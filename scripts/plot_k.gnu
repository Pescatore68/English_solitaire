set datafile separator ","

set terminal png
set output "grafico_k.png"

set xlabel "k"
set ylabel "P(k)"
set title "Distribuzione P(k)"

set style fill solid
plot "dist_k.csv" using 1:2 with boxes title "P(k)"
