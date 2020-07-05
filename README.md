# Veri Yapiları LAB1
Ders Yürütücüsü: Prof. Yahya KARSLIGİL 
# Konu : Linkli Liste Kullanımı
Bu ödevde dinamik bellek yönetimi ile, belleği linkli liste yapısında kullanan diziler ile ilgili bir uygulama yapmanız istenmektedir.   

# Problem:  Aşağıdaki işlemleri gerçekleştiriniz : 
1. A ve B dizilerini okuyacağınız küçükten büyüğe sıralı elemanlar ile(dizi elemanlarını sıralı sayılar olacak şekilde okumanız yeterli, sıralama yapmanız istenmiyor) oluşturunuz. İki dizinin her elemanını dinamik bellek kullanımı ile belleğe yerleştirip linkli liste yapısında saklayınız.  

2. A ve B dizilerini yazdırınız.  

3. Bu iki dizinin kesişimini ve birleşimini oluşturan elemanları bularak  C(kesişim) ve D(birleşim) dizilerini  yine linkli liste yapısında ve sıralı olarak elde ediniz. Kesişim ve birleşim işlemini yaparken dizilerin sıralı olmasından faydalanınız.  

4. Elde ettiğiniz ve C ve D dizilerini yazdırınız. 
 
 Örnek :  Okuduğunuz A dizisi ve B dizisi aşağıdaki gibi iken C ve D dizileri aşağıdaki gibi bulunmalıdır.  
 
A :  2 -> 5 -> 9 -> 11  
B :  1 -> 2 -> 7 -> 9  
Kesişim dizisi C : 2 -> 9 
Birleşim dizisi D : 1 -> 2 -> 5 -> 7 -> 9 -> 11 


# Not 1 : Belleğin dinamik kullanımı için dizilerin her elemanını malloc() fonksiyonu  ile yer tutarak linkli liste yapısı ile saklayınız.   
# Not 2 : İşlemleri anlamlı modüllere bölerek fonksiyonlar halinde  yazmaya özen gösteriniz.  
