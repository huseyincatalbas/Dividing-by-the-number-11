/*
#Ad-Soyad = Huseyin ÇATALBAŞ
#E-posta = hcatalbas@ceng.ktu.edu.tr
#Proje = Dividing by the number 11
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int sum=0,remaining=0,d1,numberSet[10];
static int numberDigitValue=10,numberDigitRemainder,inputNumber;

void d1Add(int d1, int numberSet[]);
int d1DigitValueCalc(int inputNumber);

int main(int argc, char *argv[])
{
  inputNumber=atoi(argv[1]);
  /*Burada girilen string sayıyı atoi fonksiyonu ile integer 
  girilensayi değişkenine aktardım.*/

  d1=d1DigitValueCalc(inputNumber);
  /*d1 sayısını hesaplamak ve girilen sayıyı basamaklarına
   ayırıp integer girilen sayılar dizisine aktarmak için
   d1 hesaplama fonksiyonunu kullandım.Geriye de bulunan
   d1 sayısını döndürdüm.*/

  d1Add(d1,numberSet);
  /*Elde edilen d1 sayısını  alınan sayılarla birlikte
  ekrana yazdırmak için d1 ekleme fonksiyonunu çalıştırdım.*/

  return 0;
}

void d1Add(int d1, int numberSet[])
/*d1 sayısını programın başında  alınan sayıya ekleme işlemi yaptım*/
{
  for(int i=8;i>=0;i--)
  {
      printf("%d",numberSet[i]);
      /*Diziye aktarmış olduğum sayıları yazdırdım.*/
  }

  if(d1==10){printf("X\n");}
  /*Programın başında girilmiş olan sayılara ek olarak d1 sayısı
  10 ise X simgesini ekledim.*/

  else{printf("%d\n",d1);}
  /*Programın başında girilmiş olan sayılara ek olarak d1 sayısı
  değerini ekledim.*/

}


int d1DigitValueCalc(int inputNumber)
/*Girilen sayıyı bu fonksiyonda basamaklarına ayırıp dizinin 
indislerine aktardım ve 11'e bölünebilmesi için gereken d1 
sayının hesaplama işlemini yaptım.*/
{

  for(int k=0;k<9;k++)
  {
      numberDigitRemainder=inputNumber%numberDigitValue;
      /*Programın başında girilmiş olan integer sayının 10 ve katları
      şeklinde modunu alarak sayının o basamaktaki değerine ulaştım.*/

      numberDigitRemainder/=numberDigitValue/10;
      /*Burada sayının basamak değerini birler onlar yüzler diye artırarak
      böldürüp bölüm sayısını elde ettim.Bu değer aynı zamanda dizide
      tutacak olduğum değerdir.*/

      numberSet[k]=numberDigitRemainder;
      /*Burada buldurduğum bölüm değerini dizinin indisleri şeklinde aktarma yaptırdım.*/

      inputNumber-=numberDigitRemainder;
      /*Burada bir sonraki adımda bulduracağım basamak değerinde şu anki
      bulduğum değeri çıkararak işlemin uzamamasını sağladım.*/

      numberDigitValue*=10;
      /*Burada bir sonraki adımda basamak değeri yani birlerse onlar onlarsa
      binler yapabilmek için çarpma işlemi yaptım.*/
  }

  for(int i=0;i<=8;i++)
  {
      printf("\n%d. Basamak Degeri:%d",i+1,numberSet[8-i]);
      /*Dizideki indis değerlerini yazdırdım.*/

      sum+=(i+2)*(numberSet[i]);
      /*Burada dizideki basamak değerlerini katsayılarına uygun şekilde toplattım.*/
  }


  printf("\nToplam Degeri:%d",sum);//sum değeri yazdırttım.

  remaining=(sum%11);
  /*sum değerin modunu alarak kalan değeri hesapladım.*/
  
  if(remaining==0)
  {
      d1=0;
      printf("\nD1'in Degeri:%d\n",d1);
      /*Normalde kalan değeri 11'den çıkarıyordum.Ancak burada 0 olursa
      11'den çıkarldığında 11 değeri olacaktı d1 değeri bunu engellemek için
      if şartı kullandım.*/
  }
  else if(remaining!=0)
  {
        d1=(11-remaining);
        /*Burada remaining değerini 11'den çıkarıyorum, çünkü eklenecek olan sayı
        olan d1 sayısı ile 11'e tam bölünebilmesi gerekiyor.*/
        printf("\nD1'in Degeri:%d\n",d1);
  }

  return d1;
}
