rm -rf eff_plot_C.so
rm -rf eff_plot_C.d
rm -rf result.log

root -l -b  < x_eff_plot.C  &> result.log &

rm -rf eff_plot_C.so
rm -rf eff_plot_C.d
