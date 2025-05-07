1. Sistemos Reikalavimai

Įsitikinkite, kad turite šias priemones:

Operacinė sistema: Windows, Linux arba macOS

C++ kompiliatorius: GCC (MinGW Windows sistemai), Clang arba MSVC

CMake: 3.10 ar naujesnė versija

Git: 2.0 ar naujesnė versija

Patikrinkite, ar įrankiai įdiegti:

          cmake --version
          gcc --version
          git --version


2. Projekto Atsisiuntimas


     Atidarykite terminalą (arba "Command Prompt" Windows sistemoje).

     Nukeliaukite į katalogą, kuriame norite atsisiųsti projektą.

          cd /kelias/iki/katalogo

     Nukopijuokite projektą iš GitHub naudodami komandą:

          git clone https://github.com/CoderGuga/2-oji_Uzduotis.git

   Pereikite į projekto katalogą:
   
          cd 2-oji_Uzduotis/v2.0


3. Programos Kompiliavimas


     Sukurkite "build" katalogą ir pereikite į jį:

          mkdir build && cd build

     Paleiskite "CMake" komandą:

          cmake ..

     Kompiliuokite programą:

  Windows (naudojant MinGW):

    mingw32-make

  Linux / macOS:
  
    make



4. Programos Paleidimas

     Po sėkmingo kompiliavimo, galite paleisti programą:

  Windows:

    ./MyExecutable.exe

  Linux / macOS:
  
    ./MyExecutable





**Releasai**

v2.0

Pridėtas Unit Testavimas

![image](https://github.com/user-attachments/assets/7dca259c-92f3-496a-90c6-4d90c52a0fd3)


v1.5

*Studentas* klasė paversta išvestine iš bazinės, abstrakčiosios *Žmogus* klasės


v1.2

Klasei *Studentas* pridėti "Rule of five" metodai, bei įvesties iš išvesties operatoriai darbui su konsole ir failais.


v1.1

*Studentas* perdarytas iš struktūros į klasę, pridėti getteriai ir setteriai.


v1.0

Programa palaiko vector, list ir deque konteinerių tipus, sukurtos 3 skirtingos strategijos darbui su konteineriais:

1. Rūšiuojami studentai kopijuojami per 2 konteinerius, pagreitinant darbą su list, bet neoptimizuojant atminties.

2. Rūšiuojami studentai naudoja tik 1 konteinerį, tokiu būdu optimizuojant atminties naudojimą.

3. Studentų rūšiavimas naudoja find ir partition metodus, darbo optimizavimui.

Pridėta CMakeLists.txt įdiegimo instrukcija.
