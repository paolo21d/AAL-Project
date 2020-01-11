#AAL-Projekt: Zalewanie wykresu słupkowego
Paweł Ś.

#Tresc:
Mając do dyspozycji ciąg nieujemnych liczb a1, a2 ... an reprezentujących kolejne słupki wykresu słupkowego Twoim zadaniem jest znalezienie największego obszaru ograniczonego dwoma słupkami, oraz osią x, który można zalać z góry. Odległości pomiędzy słupkami w osi x wynosi 1.
Uwaga, wody nie można wlewać "na" słupek (tak żeby rozlewała się na prawo i na lewo od niego).
Przykładowe rozwiązanie:
Wejście: N = [1,8,6,2,5,4,8,3,7]
Wyjście: 40
Wyjaśnienie:
Najwięcej wody znajdzie się pomiędzy drugim, a 7 słupkiem o wysokości 8

#Tryby uruchomienia
1) Tryb interaktywny - po uruchomieniu programu zostaje wyświetlone menu główne
    - Pojedyncze rozwiazanie<br/> 
        Oblicznie maksymalnej ilości wody jaka się zmieści w podanym przypadku<br/>
        Argumenty: [dlugosc pola], [wysokości słupków (ich ilosc ma się równać podanej długości pola)]
    - Generowanie przypadkow testowych i porownanie wynikow dla algorytmu Optimal oraz Brutforce<br/>
        Generowane są przypadki testowe o zadanych parametrach, a następnie są one rozwiązywane za pomocą algorytmu Optimal oraz Brutforce. Porównywane są jakie zwracają te algorytmy. Jeżeli zostanie wygenerowana próba w której te dwa algorytmy zwrócą różne wartości wyświetlony zostanie błąd.<br/>
        Argumenty: [dlugosc pola], [max wysokosc slupka], [ilosc prob]
    - Pomiar czasu wykonania dla coraz wiekszych probek dla algorytmu Optimal<br/>
        Wykonanie pomiarów wydajnościowych algorytmu Optimal. Czas wykonania zależny jest od długości pola, z tego powodu to właśnie ta wartość jest zwiększana w kolejnych krokach testowych. Dla danej długości pola generowanych jest wiele przypadków testowych i wykonywane są dla nich pomiary czasu rozwiązania, następnie czas wykoanania zostaje uśredniony.<br/>
        Argumenty: [offset - od jakiej długości mają zaczynać się kroki pomiaru], [max wysokosc slupka], [wielkosc kroku], [ilosc krokow], [ilosc probek pomiarowych na dany krok]
    - Pomiar czasu wykonania dla coraz wiekszych probek dla obu algorytmow<br/>
        Analogicznie do poprzedniego punktu, tylko w tym przypadku wygenerowane próbeki rozwiązywane są za pomocą algorytmu Optimal oraz Brutforce. Wyniki pomiarów są zapisywane a następnie wyświetlane.<br/>
        Argumenty: [offset - od jakiej długości mają zaczynać się kroki pomiaru], [max wysokosc slupka], [wielkosc kroku], [ilosc krokow], [ilosc probek pomiarowych na dany krok]
2) Tryb wsadowy<br/>
    Pierwszym argumentem jest operacja jaka ma zostać wykonana (dostępne operacje są takie same jak w trybie interaktywnym):<br/>
        1 - Pojedyncze rozwiazanie<br/>
        2 - Generowanie przypadkow testowych i porownanie wynikow dla algorytmu Optimal oraz Brutforce<br/>
        3 - Pomiar czasu wykonania dla coraz wiekszych probek dla algorytmu Optimal<br/>
        4 - Pomiar czasu wykonania dla coraz wiekszych probek dla obu algorytmow<br/>
    
Każda z operacji przyjmuje arguemnty analogiczne do tych opisnych w trybie interaktywnym

#Kompilacja
Możliwa jest kompilacja z wykorzystaniem g++<br/>
Specjalnie do tego celu został stworzony Makefile.
Aby zbudować projekt wystarczy w folderze głównym projektu wywołać polecenie make. Zostanie wtedy wygenerowany plik wykonywalny aalProject<br/>
W trakcie tworzenie projektu wykorzystywany był kompilator MinGW wraz ze środwiskiem CLion.

#Dane wejściowe
Aby uzyskać rozwiązanie problemu należy podać dane:
- długość pola/basenu (minimum 1)
- kolejne wysokości słupków (0, 1, 2, 3 ...)

#Rozwiązanie
1) Algorytm optymalny<br/>
    Korzystamy z algorytmu gąsiennicowego. Moja gąsiennica ma głowę i ogon, oba są iteratorami w
    liście reprezentującej wysokości kolejnych słupków. Poruszamy się raz od lewej strony ciągu oraz
    drugi raz od prawej strony.<br/>
    W zadanym przejściu zaczynamy od początku. Przesuwamy głowę gąsiennicy do czasu, gdy głowa
    będzie wyższa lub równa od wysokości ogonu gąsiennicy. Wtedy obliczamy jaka ilość wody zmieści
    się w tej „dolinie” miedzy głową a ogonem gąsiennicy (bierzemy pod uwagę odległość miedzy tymi
    iteratorami oraz wysokość mniejszej wysokości spośród wysokości ogona i głowy). Jeżeli znaleziona
    teraz pojemność jest większa niż dotychczasowa największa, bierzemy aktualną jako MaxCapacity.<br/>
    Po przejściu ciągu od lewej oraz od prawej jako wynik algorytmu zwracamy największą znalezioną
    pojemność z obu porzejść.
    
    Złożoność tego rozwiązania jest liniowa.
2) Algorytm brutforce (pierwsze znalezione rozwiązanie, wykorzystawne w późniejszych etapach projektu w celu weryfkacji wyników zwracanych przez algorytm optymalny) <br/>
    Przechodzimy od słupka i-tego do ostatniego słupka. W danej iteracji i przechodzę po kolejnych
    słupkach do czasu gdy napotkam słupek równy bądź wyższy od słupka i-tego. Obliczana jest wtedy
    odległość między tymi słupkami i mnożona jest przez minimum wysokości i-tego słupka oraz tego
    słupka do którego dotarliśmy. Wykonując ten algorytm dla każdego i=1…n znajduję maksymalną
    pojemność.
    
    Złożoność teoretyczna tego rozwiązania jest kwadratowa. Jednak podczas testów pomiary czasu wykonania wskazują na złożoność liniową.<br/>
    Powodem tego jest to, że złożoność kwadratowa jest złożonością pesymistyczną, występującą tylko dla przypadku gdy dolina zajmuje znaczą część pola
    tzn. jest niewielka ilość dolin, a każda o dużej szerokości. W przypadkach testowych zwykle wychodziło wiele dolin o niewielkiej szerokości każda.
    Dlatego też średnio złożoność tego rozwiązania wychodzi liniowa, jednak z o wiele większym współczynnikiem(nachylenie prostej jest znacznie bardziej pionowe) niż w przypadku algorytmu optymalnego/ 