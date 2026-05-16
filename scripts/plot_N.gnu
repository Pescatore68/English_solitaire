set datafile separator ","

set terminal png
set output "grafico_N.png"

set xlabel "N"
set ylabel "P(N)"

set title "Probabilità durata di N mosse"

set style fill solid

plot "dist_N.csv" using 1:2 with boxes title "P(N)"
