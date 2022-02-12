void fpu_emulator_init_fpu(void)
{
static int first = 1;
int i;
if (first) {
first = 0;
printk("Algorithmics/MIPS FPU Emulator v1.5\n");
}
current->thread.fpu.fcr31 = 0;
for (i = 0; i < 32; i++)
set_fpr64(&current->thread.fpu.fpr[i], 0, SIGNALLING_NAN);
}
