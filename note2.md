Thread starvation
Date: 2025-03-29



Tags:
[#university]


Jest to sytuacja, kiedy pracujemy z watkami. Polega to na tym, ze pomimo iz problem [[Thread deadlock]] zostal w jakis sposob rozwiazany, to jeden z kilku watkow NIGDY nie otrzyma dostepu do jakiegos shared resource.

Dzieje sie tak, poniewaz nie ma zaimplementowanego jakies systemu nadawania priorytetow albo zbierania informacji, jaki resource juz ile razy cos uzyl i w momencie obu watkow chcacych dostac access do shared resource, to wybierze tego co mniej razy sie tam pojawil.


Podsumowanie: System działa. Niektore procesy działają, ale inne są wiecznie pomijane