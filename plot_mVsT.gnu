#Terminal
set terminal pdf font ",25" size 10,6 #size is in inches - default would be 5,3

#Output
set output "m_vs_t_Nickel.pdf"


#load pre-sets
set loadpath "/home/slimnfr/Desktop/GNUplot_Load-Path/"
load 'rdbu.pal'

#variables
Tc=631

#range
set xrange [0:Tc+1]
set yrange [0:1]

#labels
set xlabel "T(K)"
set ylabel "m=M(T)/M(0)"

#key
#unset key

#plot
p "output_NR.txt" u 1:2 w p pt 6 ps 1.5 lc rgb dark_blue title "Solution of Weiss equation", "output_interpol.txt" u 1:2 w l ls 1 lw 3 title "Cubic spline interpolation"




