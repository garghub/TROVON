void display_timings_release(struct display_timings *disp)
{
if (disp->timings) {
unsigned int i;
for (i = 0; i < disp->num_timings; i++)
kfree(disp->timings[i]);
kfree(disp->timings);
}
kfree(disp);
}
