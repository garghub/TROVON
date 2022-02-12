static unsigned char vortex_game_read(struct gameport *gameport)
{
vortex_t *vortex = gameport_get_port_data(gameport);
return hwread(vortex->mmio, VORTEX_GAME_LEGACY);
}
static void vortex_game_trigger(struct gameport *gameport)
{
vortex_t *vortex = gameport_get_port_data(gameport);
hwwrite(vortex->mmio, VORTEX_GAME_LEGACY, 0xff);
}
static int
vortex_game_cooked_read(struct gameport *gameport, int *axes, int *buttons)
{
vortex_t *vortex = gameport_get_port_data(gameport);
int i;
*buttons = (~hwread(vortex->mmio, VORTEX_GAME_LEGACY) >> 4) & 0xf;
for (i = 0; i < 4; i++) {
axes[i] =
hwread(vortex->mmio, VORTEX_GAME_AXIS + (i * AXIS_SIZE));
if (axes[i] == AXIS_RANGE)
axes[i] = -1;
}
return 0;
}
static int vortex_game_open(struct gameport *gameport, int mode)
{
vortex_t *vortex = gameport_get_port_data(gameport);
switch (mode) {
case GAMEPORT_MODE_COOKED:
hwwrite(vortex->mmio, VORTEX_CTRL2,
hwread(vortex->mmio,
VORTEX_CTRL2) | CTRL2_GAME_ADCMODE);
msleep(VORTEX_GAME_DWAIT);
return 0;
case GAMEPORT_MODE_RAW:
hwwrite(vortex->mmio, VORTEX_CTRL2,
hwread(vortex->mmio,
VORTEX_CTRL2) & ~CTRL2_GAME_ADCMODE);
return 0;
default:
return -1;
}
return 0;
}
static int vortex_gameport_register(vortex_t *vortex)
{
struct gameport *gp;
vortex->gameport = gp = gameport_allocate_port();
if (!gp) {
printk(KERN_ERR "vortex: cannot allocate memory for gameport\n");
return -ENOMEM;
}
gameport_set_name(gp, "AU88x0 Gameport");
gameport_set_phys(gp, "pci%s/gameport0", pci_name(vortex->pci_dev));
gameport_set_dev_parent(gp, &vortex->pci_dev->dev);
gp->read = vortex_game_read;
gp->trigger = vortex_game_trigger;
gp->cooked_read = vortex_game_cooked_read;
gp->open = vortex_game_open;
gameport_set_port_data(gp, vortex);
gp->fuzz = 64;
gameport_register_port(gp);
return 0;
}
static void vortex_gameport_unregister(vortex_t * vortex)
{
if (vortex->gameport) {
gameport_unregister_port(vortex->gameport);
vortex->gameport = NULL;
}
}
static inline int vortex_gameport_register(vortex_t * vortex) { return -ENOSYS; }
static inline void vortex_gameport_unregister(vortex_t * vortex) { }
