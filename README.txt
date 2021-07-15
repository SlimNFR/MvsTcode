This code can calculate the m_e(T) curve: it initially uses Newton-Raphson to solve the self-consistent Weiss equation and obtain several (m_e,T) points, and later employs cubic interpolation to obtain the rest of the curve.

The NR method outpus data in output_NR.txt
The cubic interpolation outputs data in output_interpol.txt

The cpp and h files are found in the Code dir.

use gnuplot plot_mVsT.gnu to plot the result 


Cubic interpolation github:  https://gist.github.com/svdamani/1015c5c4b673c3297309
Newton Raphson: https://deepanshubhatti.blogspot.com/2013/10/to-find-roots-of-transcendental.html

