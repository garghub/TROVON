static int __init aedsp16_wait_data(int port)
{
int loop = STATUSRETRY;
unsigned char ret = 0;
DBG1(("aedsp16_wait_data (0x%x): ", port));
do {
ret = inb(port + DSP_DATAVAIL);
} while (!(ret & 0x80) && loop--);
if (ret & 0x80) {
DBG1(("success.\n"));
return TRUE;
}
DBG1(("failure.\n"));
return FALSE;
}
static int __init aedsp16_read(int port)
{
int inbyte;
DBG((" Read DSP Byte (0x%x): ", port));
if (aedsp16_wait_data(port) == FALSE) {
DBG(("failure.\n"));
return -1;
}
inbyte = inb(port + DSP_READ);
DBG(("read [0x%x]/{%c}.\n", inbyte, inbyte));
return inbyte;
}
static int __init aedsp16_test_dsp(int port)
{
return ((aedsp16_read(port) == 0xaa) ? TRUE : FALSE);
}
static int __init aedsp16_dsp_reset(int port)
{
DBG(("Reset DSP:\n"));
outb(1, (port + DSP_RESET));
udelay(10);
outb(0, (port + DSP_RESET));
udelay(10);
udelay(10);
if (aedsp16_test_dsp(port) == TRUE) {
DBG(("success.\n"));
return TRUE;
} else
DBG(("failure.\n"));
return FALSE;
}
static int __init aedsp16_write(int port, int cmd)
{
unsigned char ret;
int loop = HARDRETRY;
DBG((" Write DSP Byte (0x%x) [0x%x]: ", port, cmd));
do {
ret = inb(port + DSP_STATUS);
if (!(ret & 0x80)) {
outb(cmd, port + DSP_COMMAND);
DBG(("success.\n"));
return 0;
}
} while (loop--);
DBG(("timeout.\n"));
printk("[AEDSP16] DSP Command (0x%x) timeout.\n", cmd);
return -1;
}
void __init aedsp16_pinfo(void) {
DBG(("\n Base address: %x\n", decoded_hcfg.iobase));
DBG((" Joystick : %s present\n", decoded_hcfg.joystick?"":" not"));
DBG((" WSS addr : %x\n", decoded_hcfg.wssbase));
DBG((" MPU-401 addr: %x\n", decoded_hcfg.mpubase));
DBG((" CDROM : %s present\n", (decoded_hcfg.cdrom!=4)?"":" not"));
DBG((" CDROMADDR : %x\n\n", decoded_hcfg.cdrombase));
}
static void __init aedsp16_hard_decode(void) {
DBG((" aedsp16_hard_decode: 0x%x, 0x%x\n", hard_cfg[0], hard_cfg[1]));
decoded_hcfg.iobase = IOBASE(hard_cfg[0]);
decoded_hcfg.joystick = JOY(hard_cfg[0]);
decoded_hcfg.wssbase = WSSADDR(hard_cfg[0]);
decoded_hcfg.mpubase = MPUADDR(hard_cfg[0]);
decoded_hcfg.cdrom = CDROM(hard_cfg[1]);
decoded_hcfg.cdrombase = CDROMADDR(hard_cfg[1]);
#if defined(AEDSP16_INFO) || defined(AEDSP16_DEBUG)
printk(" Original sound card configuration:\n");
aedsp16_pinfo();
#endif
decoded_hcfg.iobase = ae_config.base_io;
decoded_hcfg.wssbase = ae_config.mss_base;
decoded_hcfg.mpubase = ae_config.mpu_base;
#if defined(CONFIG_SC6600_JOY)
decoded_hcfg.joystick = CONFIG_SC6600_JOY;
#endif
#if defined(CONFIG_SC6600_CDROM)
decoded_hcfg.cdrom = CONFIG_SC6600_CDROM;
#endif
#if defined(CONFIG_SC6600_CDROMBASE)
decoded_hcfg.cdrombase = CONFIG_SC6600_CDROMBASE;
#endif
#if defined(AEDSP16_DEBUG)
DBG((" New Values:\n"));
aedsp16_pinfo();
#endif
DBG(("success.\n"));
}
static void __init aedsp16_hard_encode(void) {
DBG((" aedsp16_hard_encode: 0x%x, 0x%x\n", hard_cfg[0], hard_cfg[1]));
hard_cfg[0] = 0;
hard_cfg[1] = 0;
hard_cfg[0] |= 0x20;
BLDIOBASE (hard_cfg[0], decoded_hcfg.iobase);
BLDWSSADDR(hard_cfg[0], decoded_hcfg.wssbase);
BLDMPUADDR(hard_cfg[0], decoded_hcfg.mpubase);
BLDJOY(hard_cfg[0], decoded_hcfg.joystick);
BLDCDROM(hard_cfg[1], decoded_hcfg.cdrom);
BLDCDROMADDR(hard_cfg[1], decoded_hcfg.cdrombase);
#if defined(AEDSP16_DEBUG)
aedsp16_pinfo();
#endif
DBG((" aedsp16_hard_encode: 0x%x, 0x%x\n", hard_cfg[0], hard_cfg[1]));
DBG(("success.\n"));
}
static int __init aedsp16_hard_write(int port) {
DBG(("aedsp16_hard_write:\n"));
if (aedsp16_write(port, COMMAND_6C)) {
printk("[AEDSP16] CMD 0x%x: failed!\n", COMMAND_6C);
DBG(("failure.\n"));
return FALSE;
}
if (aedsp16_write(port, COMMAND_5C)) {
printk("[AEDSP16] CMD 0x%x: failed!\n", COMMAND_5C);
DBG(("failure.\n"));
return FALSE;
}
if (aedsp16_write(port, hard_cfg[0])) {
printk("[AEDSP16] DATA 0x%x: failed!\n", hard_cfg[0]);
DBG(("failure.\n"));
return FALSE;
}
if (aedsp16_write(port, hard_cfg[1])) {
printk("[AEDSP16] DATA 0x%x: failed!\n", hard_cfg[1]);
DBG(("failure.\n"));
return FALSE;
}
if (aedsp16_write(port, COMMAND_C5)) {
printk("[AEDSP16] CMD 0x%x: failed!\n", COMMAND_C5);
DBG(("failure.\n"));
return FALSE;
}
DBG(("success.\n"));
return TRUE;
}
static int __init aedsp16_hard_read(int port) {
DBG(("aedsp16_hard_read:\n"));
if (aedsp16_write(port, READ_HARD_CFG)) {
printk("[AEDSP16] CMD 0x%x: failed!\n", READ_HARD_CFG);
DBG(("failure.\n"));
return FALSE;
}
if ((hard_cfg[0] = aedsp16_read(port)) == -1) {
printk("[AEDSP16] aedsp16_read after CMD 0x%x: failed\n",
READ_HARD_CFG);
DBG(("failure.\n"));
return FALSE;
}
if ((hard_cfg[1] = aedsp16_read(port)) == -1) {
printk("[AEDSP16] aedsp16_read after CMD 0x%x: failed\n",
READ_HARD_CFG);
DBG(("failure.\n"));
return FALSE;
}
if (aedsp16_read(port) == -1) {
printk("[AEDSP16] aedsp16_read after CMD 0x%x: failed\n",
READ_HARD_CFG);
DBG(("failure.\n"));
return FALSE;
}
DBG(("success.\n"));
return TRUE;
}
static int __init aedsp16_ext_cfg_write(int port) {
int extcfg, val;
if (aedsp16_write(port, COMMAND_66)) {
printk("[AEDSP16] CMD 0x%x: failed!\n", COMMAND_66);
return FALSE;
}
extcfg = 7;
if (decoded_hcfg.cdrom != 2)
extcfg = 0x0F;
if ((decoded_hcfg.cdrom == 4) ||
(decoded_hcfg.cdrom == 3))
extcfg &= ~2;
if (decoded_hcfg.cdrombase == 0)
extcfg &= ~2;
if (decoded_hcfg.mpubase == 0)
extcfg &= ~1;
if (aedsp16_write(port, extcfg)) {
printk("[AEDSP16] Write extcfg: failed!\n");
return FALSE;
}
if (aedsp16_write(port, 0)) {
printk("[AEDSP16] Write extcfg: failed!\n");
return FALSE;
}
if (decoded_hcfg.cdrom == 3) {
if (aedsp16_write(port, COMMAND_52)) {
printk("[AEDSP16] CMD 0x%x: failed!\n", COMMAND_52);
return FALSE;
}
if ((val = aedsp16_read(port)) == -1) {
printk("[AEDSP16] aedsp16_read after CMD 0x%x: failed\n"
, COMMAND_52);
return FALSE;
}
val &= 0x7F;
if (aedsp16_write(port, COMMAND_60)) {
printk("[AEDSP16] CMD 0x%x: failed!\n", COMMAND_60);
return FALSE;
}
if (aedsp16_write(port, val)) {
printk("[AEDSP16] Write val: failed!\n");
return FALSE;
}
}
return TRUE;
}
static int __init aedsp16_cfg_write(int port) {
if (aedsp16_write(port, WRITE_MDIRQ_CFG)) {
printk("[AEDSP16] CMD 0x%x: failed!\n", WRITE_MDIRQ_CFG);
return FALSE;
}
if (aedsp16_write(port, soft_cfg)) {
printk("[AEDSP16] Initialization of (M)IRQ and DMA: failed!\n");
return FALSE;
}
return TRUE;
}
static int __init aedsp16_init_mss(int port)
{
DBG(("aedsp16_init_mss:\n"));
mdelay(10);
if (aedsp16_write(port, DSP_INIT_MSS)) {
printk("[AEDSP16] aedsp16_init_mss [0x%x]: failed!\n",
DSP_INIT_MSS);
DBG(("failure.\n"));
return FALSE;
}
mdelay(10);
if (aedsp16_cfg_write(port) == FALSE)
return FALSE;
outb(soft_cfg_mss, ae_config.mss_base);
DBG(("success.\n"));
return TRUE;
}
static int __init aedsp16_setup_board(int port) {
int loop = RETRY;
#if defined(CONFIG_SC6600)
int val = 0;
if (aedsp16_hard_read(port) == FALSE) {
printk("[AEDSP16] aedsp16_hard_read: failed!\n");
return FALSE;
}
if (aedsp16_write(port, COMMAND_52)) {
printk("[AEDSP16] CMD 0x%x: failed!\n", COMMAND_52);
return FALSE;
}
if ((val = aedsp16_read(port)) == -1) {
printk("[AEDSP16] aedsp16_read after CMD 0x%x: failed\n",
COMMAND_52);
return FALSE;
}
#endif
do {
if (aedsp16_write(port, COMMAND_88)) {
printk("[AEDSP16] CMD 0x%x: failed!\n", COMMAND_88);
return FALSE;
}
mdelay(10);
} while ((aedsp16_wait_data(port) == FALSE) && loop--);
if (aedsp16_read(port) == -1) {
printk("[AEDSP16] aedsp16_read after CMD 0x%x: failed\n",
COMMAND_88);
return FALSE;
}
#if !defined(CONFIG_SC6600)
if (aedsp16_write(port, COMMAND_5C)) {
printk("[AEDSP16] CMD 0x%x: failed!\n", COMMAND_5C);
return FALSE;
}
#endif
if (aedsp16_cfg_write(port) == FALSE)
return FALSE;
#if defined(CONFIG_SC6600)
if (aedsp16_write(port, COMMAND_60)) {
printk("[AEDSP16] CMD 0x%x: failed!\n", COMMAND_60);
return FALSE;
}
if (aedsp16_write(port, val)) {
printk("[AEDSP16] DATA 0x%x: failed!\n", val);
return FALSE;
}
if (aedsp16_write(port, COMMAND_6E)) {
printk("[AEDSP16] CMD 0x%x: failed!\n", COMMAND_6E);
return FALSE;
}
if (aedsp16_write(port, ver[0])) {
printk("[AEDSP16] DATA 0x%x: failed!\n", ver[0]);
return FALSE;
}
if (aedsp16_write(port, ver[1])) {
printk("[AEDSP16] DATA 0x%x: failed!\n", ver[1]);
return FALSE;
}
if (aedsp16_hard_write(port) == FALSE) {
printk("[AEDSP16] aedsp16_hard_write: failed!\n");
return FALSE;
}
if (aedsp16_write(port, COMMAND_5C)) {
printk("[AEDSP16] CMD 0x%x: failed!\n", COMMAND_5C);
return FALSE;
}
#if defined(THIS_IS_A_THING_I_HAVE_NOT_TESTED_YET)
if (aedsp16_cfg_write(port) == FALSE)
return FALSE;
#endif
#endif
return TRUE;
}
static int __init aedsp16_stdcfg(int port) {
if (aedsp16_write(port, WRITE_MDIRQ_CFG)) {
printk("[AEDSP16] CMD 0x%x: failed!\n", WRITE_MDIRQ_CFG);
return FALSE;
}
if (aedsp16_write(port, 0x0A)) {
printk("[AEDSP16] aedsp16_stdcfg: failed!\n");
return FALSE;
}
return TRUE;
}
static int __init aedsp16_dsp_version(int port)
{
int len = 0;
int ret;
DBG(("Get DSP Version:\n"));
if (aedsp16_write(ae_config.base_io, GET_DSP_VERSION)) {
printk("[AEDSP16] CMD 0x%x: failed!\n", GET_DSP_VERSION);
DBG(("failed.\n"));
return FALSE;
}
do {
if ((ret = aedsp16_read(port)) == -1) {
DBG(("failed.\n"));
return FALSE;
}
ver[len++] = ret;
} while (len < CARDVERDIGITS);
sprintf(DSPVersion, "%d.%d", ver[0], ver[1]);
DBG(("success.\n"));
return TRUE;
}
static int __init aedsp16_dsp_copyright(int port)
{
int len = 0;
int ret;
DBG(("Get DSP Copyright:\n"));
if (aedsp16_write(ae_config.base_io, GET_DSP_COPYRIGHT)) {
printk("[AEDSP16] CMD 0x%x: failed!\n", GET_DSP_COPYRIGHT);
DBG(("failed.\n"));
return FALSE;
}
do {
if ((ret = aedsp16_read(port)) == -1) {
if (len)
break;
else {
DBG(("failed.\n"));
return FALSE;
}
}
DSPCopyright[len++] = ret;
} while (len < CARDNAMELEN);
DBG(("success.\n"));
return TRUE;
}
static void __init aedsp16_init_tables(void)
{
int i = 0;
memset(DSPCopyright, 0, CARDNAMELEN + 1);
memset(DSPVersion, 0, CARDVERLEN + 1);
for (i = 0; orIRQ[i].or; i++)
if (orIRQ[i].val == ae_config.irq) {
soft_cfg |= orIRQ[i].or;
soft_cfg_mss |= orIRQ[i].or;
}
for (i = 0; orMIRQ[i].or; i++)
if (orMIRQ[i].or == ae_config.mpu_irq)
soft_cfg |= orMIRQ[i].or;
for (i = 0; orDMA[i].or; i++)
if (orDMA[i].val == ae_config.dma) {
soft_cfg |= orDMA[i].or;
soft_cfg_mss |= orDMA[i].or;
}
}
static int __init aedsp16_init_board(void)
{
aedsp16_init_tables();
if (aedsp16_dsp_reset(ae_config.base_io) == FALSE) {
printk("[AEDSP16] aedsp16_dsp_reset: failed!\n");
return FALSE;
}
if (aedsp16_dsp_copyright(ae_config.base_io) == FALSE) {
printk("[AEDSP16] aedsp16_dsp_copyright: failed!\n");
return FALSE;
}
if (strcmp("SC-6000", DSPCopyright))
printk("[AEDSP16] Warning: non SC-6000 audio card!\n");
if (aedsp16_dsp_version(ae_config.base_io) == FALSE) {
printk("[AEDSP16] aedsp16_dsp_version: failed!\n");
return FALSE;
}
if (aedsp16_stdcfg(ae_config.base_io) == FALSE) {
printk("[AEDSP16] aedsp16_stdcfg: failed!\n");
return FALSE;
}
#if defined(CONFIG_SC6600)
if (aedsp16_hard_read(ae_config.base_io) == FALSE) {
printk("[AEDSP16] aedsp16_hard_read: failed!\n");
return FALSE;
}
aedsp16_hard_decode();
aedsp16_hard_encode();
if (aedsp16_hard_write(ae_config.base_io) == FALSE) {
printk("[AEDSP16] aedsp16_hard_write: failed!\n");
return FALSE;
}
if (aedsp16_ext_cfg_write(ae_config.base_io) == FALSE) {
printk("[AEDSP16] aedsp16_ext_cfg_write: failed!\n");
return FALSE;
}
#endif
if (aedsp16_setup_board(ae_config.base_io) == FALSE) {
printk("[AEDSP16] aedsp16_setup_board: failed!\n");
return FALSE;
}
if (ae_config.mss_base != -1) {
if (ae_config.init & INIT_MSS) {
if (aedsp16_init_mss(ae_config.base_io) == FALSE) {
printk("[AEDSP16] Can not initialize"
"Microsoft Sound System mode.\n");
return FALSE;
}
}
}
#if !defined(MODULE) || defined(AEDSP16_INFO) || defined(AEDSP16_DEBUG)
printk("Audio Excel DSP 16 init v%s (%s %s) [",
VERSION, DSPCopyright,
DSPVersion);
if (ae_config.mpu_base != -1) {
if (ae_config.init & INIT_MPU401) {
printk("MPU401");
if ((ae_config.init & INIT_MSS) ||
(ae_config.init & INIT_SBPRO))
printk(" ");
}
}
if (ae_config.mss_base == -1) {
if (ae_config.init & INIT_SBPRO) {
printk("SBPro");
if (ae_config.init & INIT_MSS)
printk(" ");
}
}
if (ae_config.mss_base != -1)
if (ae_config.init & INIT_MSS)
printk("MSS");
printk("]\n");
#endif
mdelay(10);
return TRUE;
}
static int __init init_aedsp16_sb(void)
{
DBG(("init_aedsp16_sb: "));
if (ae_config.init & INIT_MSS)
return FALSE;
if (ae_config.init & INIT_SBPRO)
return FALSE;
ae_config.init |= INIT_SBPRO;
DBG(("done.\n"));
return TRUE;
}
static void uninit_aedsp16_sb(void)
{
DBG(("uninit_aedsp16_sb: "));
ae_config.init &= ~INIT_SBPRO;
DBG(("done.\n"));
}
static int __init init_aedsp16_mss(void)
{
DBG(("init_aedsp16_mss: "));
if (ae_config.init & INIT_SBPRO)
return FALSE;
if (ae_config.init & INIT_MSS)
return FALSE;
if (!(ae_config.init & INIT_MPU401)) {
if (!request_region(ae_config.base_io, IOBASE_REGION_SIZE,
"aedsp16 (base)")) {
printk(
"AEDSP16 BASE I/O port region is already in use.\n");
return FALSE;
}
}
ae_config.init |= INIT_MSS;
DBG(("done.\n"));
return TRUE;
}
static void uninit_aedsp16_mss(void)
{
DBG(("uninit_aedsp16_mss: "));
if ((!(ae_config.init & INIT_MPU401)) &&
(ae_config.init & INIT_MSS)) {
release_region(ae_config.base_io, IOBASE_REGION_SIZE);
DBG(("AEDSP16 base region released.\n"));
}
ae_config.init &= ~INIT_MSS;
DBG(("done.\n"));
}
static int __init init_aedsp16_mpu(void)
{
DBG(("init_aedsp16_mpu: "));
if (ae_config.init & INIT_MPU401)
return FALSE;
if (!(ae_config.init & (INIT_MSS | INIT_SBPRO))) {
if (!request_region(ae_config.base_io, IOBASE_REGION_SIZE,
"aedsp16 (base)")) {
printk(
"AEDSP16 BASE I/O port region is already in use.\n");
return FALSE;
}
}
ae_config.init |= INIT_MPU401;
DBG(("done.\n"));
return TRUE;
}
static void uninit_aedsp16_mpu(void)
{
DBG(("uninit_aedsp16_mpu: "));
if ((!(ae_config.init & (INIT_MSS | INIT_SBPRO))) &&
(ae_config.init & INIT_MPU401)) {
release_region(ae_config.base_io, IOBASE_REGION_SIZE);
DBG(("AEDSP16 base region released.\n"));
}
ae_config.init &= ~INIT_MPU401;
DBG(("done.\n"));
}
static int __init init_aedsp16(void)
{
int initialized = FALSE;
DBG(("Initializing BASE[0x%x] IRQ[%d] DMA[%d] MIRQ[%d]\n",
ae_config.base_io,ae_config.irq,ae_config.dma,ae_config.mpu_irq));
if (ae_config.mss_base == -1) {
if (init_aedsp16_sb() == FALSE) {
uninit_aedsp16_sb();
} else {
initialized = TRUE;
}
}
if (ae_config.mpu_base != -1) {
if (init_aedsp16_mpu() == FALSE) {
uninit_aedsp16_mpu();
} else {
initialized = TRUE;
}
}
if (ae_config.mss_base != -1) {
if (init_aedsp16_mss() == FALSE) {
uninit_aedsp16_mss();
} else {
initialized = TRUE;
}
}
if (initialized)
initialized = aedsp16_init_board();
return initialized;
}
static void __exit uninit_aedsp16(void)
{
if (ae_config.mss_base != -1)
uninit_aedsp16_mss();
else
uninit_aedsp16_sb();
if (ae_config.mpu_base != -1)
uninit_aedsp16_mpu();
}
static int __init do_init_aedsp16(void) {
printk("Audio Excel DSP 16 init driver Copyright (C) Riccardo Facchetti 1995-98\n");
if (io == -1 || dma == -1 || irq == -1) {
printk(KERN_INFO "aedsp16: I/O, IRQ and DMA are mandatory\n");
return -EINVAL;
}
ae_config.base_io = io;
ae_config.irq = irq;
ae_config.dma = dma;
ae_config.mss_base = mss_base;
ae_config.mpu_base = mpu_base;
ae_config.mpu_irq = mpu_irq;
if (init_aedsp16() == FALSE) {
printk(KERN_ERR "aedsp16: initialization failed\n");
return -EINVAL;
}
return 0;
}
static void __exit cleanup_aedsp16(void) {
uninit_aedsp16();
}
static int __init setup_aedsp16(char *str)
{
int ints[7];
str = get_options(str, ARRAY_SIZE(ints), ints);
io = ints[1];
irq = ints[2];
dma = ints[3];
mss_base = ints[4];
mpu_base = ints[5];
mpu_irq = ints[6];
return 1;
}
