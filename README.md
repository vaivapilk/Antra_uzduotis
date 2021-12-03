# Antra_uzduotis
# v1.2
Pasinaudojus "Rule of Three" apibrėžimu realizuoti klasei Studentas: realizuotas destruktorius, kopijavimo konstruktorius, kopijavimo-priskirimo operatorius.
Papildomai realizuota: Studento klasės sumavimo += operatorius bei išvedimo operatorius <<.

# v1.1

Pratęsta ir patobulinta 1-osios užduoties realizacija (versija v1.0) taip, kad vietoje sukurtos Studentas struct`ūros, jos pagrindu sukurta class'ė, vadovaujantis per teorijos paskaitas nurodomomis "geromis praktikomis". Pataisytas visas kodas.

Palyginimui pirma pasižiūrime į **v1.0** gaunamus rezultatus tik su 2 strategija bei VECTOR realizacija:

![1_100k](https://user-images.githubusercontent.com/56174822/144641818-f4ac3ea8-53a5-42f7-9680-fd3e9a878669.PNG)
![1_1M](https://user-images.githubusercontent.com/56174822/144641829-795333f3-4b24-41f8-ae40-66137550dfa2.PNG)

Su **v1.1** gauname tokius rezultatus (testuojant kitos dalys užkomentuotos, šis kodas veikia su 1 ir 2 strategija bei LIST ir VECTOR):

![100k](https://user-images.githubusercontent.com/56174822/144641887-7a9d5c14-1ac8-45a8-bd74-1958462f035d.PNG)
![1M](https://user-images.githubusercontent.com/56174822/144641896-088185fd-8af7-426c-b362-5be902b43967.PNG)

Matome, kad v1.1 benrai paėmus užtrunka ilgiau.

Spartos analizė naudojant Flag'us O1, O2, O3:

**O1**:

![f100k](https://user-images.githubusercontent.com/56174822/144644349-54e58d8d-a98f-4073-ae72-064f89c0205a.PNG)
![f1M](https://user-images.githubusercontent.com/56174822/144644361-a6a275b8-f2ba-438e-a66d-b091a7c5f000.PNG)

**O2**:

![f2_100k](https://user-images.githubusercontent.com/56174822/144644505-ea592725-2e3d-4119-90d1-64824524c297.PNG)
![f2_1M](https://user-images.githubusercontent.com/56174822/144644509-56414eae-bc32-43f1-9ea1-b925ff8042a3.PNG)

**O3**:

![f3_100k](https://user-images.githubusercontent.com/56174822/144644530-67547a03-3199-41f0-a568-f258a18db8ad.PNG)
![f3_1M](https://user-images.githubusercontent.com/56174822/144644539-4fe42027-0131-498b-a0b9-26df87959145.PNG)


