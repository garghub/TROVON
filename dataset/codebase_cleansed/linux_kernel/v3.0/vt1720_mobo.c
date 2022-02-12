static int __devinit k8x800_init(struct snd_ice1712 *ice)
{
ice->vt1720 = 1;
ice->num_total_dacs = 6;
ice->num_total_adcs = 2;
return 0;
}
static int __devinit k8x800_add_controls(struct snd_ice1712 *ice)
{
return 0;
}
