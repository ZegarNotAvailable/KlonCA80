# KlonCA80
## Płyta główna.
![CA80-mini](https://raw.githubusercontent.com/ZegarNotAvailable/KlonCA80/main/CA80-mini.png)
- Okrojona o kilka elementów, zminiaturyzowana wersja MIK90.
- ZK z MIK290,
- Całkowicie programowo zgodna z oryginałem (MIK290).
- Przystosowana do pracy bez ROM (w połączeniu z bootloaderem).
- Wybór adresu U9 za pomocą zworek,
- Złącze ZS zgodne ze starą wersją CA80 (nieznacznie zmodyfikowane).
## Bootloader.
![bootloader](https://raw.githubusercontent.com/ZegarNotAvailable/KlonCA80/main/CA80-bezROM-touch.png)
- Bootloader w oparciu o rozwiązania z Z80-MBC2.
- Jest to zmodyfikowany w/w projekt, do którego dodałem:
    - złącze systemowe CA80,
    - złącze modułu MPR121 wraz z zasilaczem 3,3V,
    - emulator klawiatury CA80 oraz ZK (umożliwia "wciskanie" klawiszy przez serial lub touch),
## MIK89
- Rozszerzona wersja płytki z portem użytkownika (8255) oraz Z80CTC,
    - dodany generator kwarcowy,
    - dodany dzielnik NMI,
    - dodane złącze "daisy chain",
    - dodane złącze "ZX serial" (zlecenie 8E opis w MIK06 str. 227),

## Oprogramowanie w Arduino IDE    
- Oprogramowanie również pochodzi od J4F. Poprawiłem kilka fragmentów w celu przyspieszenia ładowania programu do RAM, oraz dodałem:
    - obraz monitora CA80 (8kB) w postaci tablicy,
    - ładowanie pliku CA80.HEX z karty SD, 
    - ustawianie zegara CA80,
    - generator NMI (CLK już był),
    - obsługę klawiatury dotykowej z modułem MPR121,
    - więcej grzechów nie pamiętam...

- Opis na blogu: [klonCA80](https://klonca80.blogspot.com)

- Zapraszam.
