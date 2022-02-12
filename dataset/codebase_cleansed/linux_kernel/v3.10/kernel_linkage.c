void fpu_emulator_init_fpu(void)
{
static int first = 1;
int i;
if (first) {
first = 0;
printk("Algorithmics/MIPS FPU Emulator v1.5\n");
}
current->thread.fpu.fcr31 = 0;
for (i = 0; i < 32; i++) {
current->thread.fpu.fpr[i] = SIGNALLING_NAN;
}
}
int fpu_emulator_save_context(struct sigcontext __user *sc)
{
int i;
int err = 0;
for (i = 0; i < 32; i++) {
err |=
__put_user(current->thread.fpu.fpr[i], &sc->sc_fpregs[i]);
}
err |= __put_user(current->thread.fpu.fcr31, &sc->sc_fpc_csr);
return err;
}
int fpu_emulator_restore_context(struct sigcontext __user *sc)
{
int i;
int err = 0;
for (i = 0; i < 32; i++) {
err |=
__get_user(current->thread.fpu.fpr[i], &sc->sc_fpregs[i]);
}
err |= __get_user(current->thread.fpu.fcr31, &sc->sc_fpc_csr);
return err;
}
int fpu_emulator_save_context32(struct sigcontext32 __user *sc)
{
int i;
int err = 0;
for (i = 0; i < 32; i+=2) {
err |=
__put_user(current->thread.fpu.fpr[i], &sc->sc_fpregs[i]);
}
err |= __put_user(current->thread.fpu.fcr31, &sc->sc_fpc_csr);
return err;
}
int fpu_emulator_restore_context32(struct sigcontext32 __user *sc)
{
int i;
int err = 0;
for (i = 0; i < 32; i+=2) {
err |=
__get_user(current->thread.fpu.fpr[i], &sc->sc_fpregs[i]);
}
err |= __get_user(current->thread.fpu.fcr31, &sc->sc_fpc_csr);
return err;
}
