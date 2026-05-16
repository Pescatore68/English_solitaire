set datafile separator ","

set terminal pdf
set output "grafico_N.pdf"

set xlabel "N"
set ylabel "P(N)"

set title "Probabilità durata di N mosse"

set style fill solid

plot "dist_N.csv" using 1:2 with boxes title "P(N)"
