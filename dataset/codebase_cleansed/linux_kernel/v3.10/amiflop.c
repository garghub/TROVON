static irqreturn_t ms_isr(int irq, void *dummy)
{
complete(&ms_wait_completion);
return IRQ_HANDLED;
}
static void ms_delay(int ms)
{
int ticks;
static DEFINE_MUTEX(mutex);
if (ms > 0) {
mutex_lock(&mutex);
ticks = MS_TICKS*ms-1;
ciaa.tblo=ticks%256;
ciaa.tbhi=ticks/256;
ciaa.crb=0x19;
wait_for_completion(&ms_wait_completion);
mutex_unlock(&mutex);
}
}
static inline int try_fdc(int drive)
{
drive &= 3;
return ((fdc_busy < 0) || (fdc_busy == drive));
}
static void get_fdc(int drive)
{
unsigned long flags;
drive &= 3;
#ifdef DEBUG
printk("get_fdc: drive %d fdc_busy %d fdc_nested %d\n",drive,fdc_busy,fdc_nested);
#endif
local_irq_save(flags);
wait_event(fdc_wait, try_fdc(drive));
fdc_busy = drive;
fdc_nested++;
local_irq_restore(flags);
}
static inline void rel_fdc(void)
{
#ifdef DEBUG
if (fdc_nested == 0)
printk("fd: unmatched rel_fdc\n");
printk("rel_fdc: fdc_busy %d fdc_nested %d\n",fdc_busy,fdc_nested);
#endif
fdc_nested--;
if (fdc_nested == 0) {
fdc_busy = -1;
wake_up(&fdc_wait);
}
}
static void fd_select (int drive)
{
unsigned char prb = ~0;
drive&=3;
#ifdef DEBUG
printk("selecting %d\n",drive);
#endif
if (drive == selected)
return;
get_fdc(drive);
selected = drive;
if (unit[drive].track % 2 != 0)
prb &= ~DSKSIDE;
if (unit[drive].motor == 1)
prb &= ~DSKMOTOR;
ciab.prb |= (SELMASK(0)|SELMASK(1)|SELMASK(2)|SELMASK(3));
ciab.prb = prb;
prb &= ~SELMASK(drive);
ciab.prb = prb;
rel_fdc();
}
static void fd_deselect (int drive)
{
unsigned char prb;
unsigned long flags;
drive&=3;
#ifdef DEBUG
printk("deselecting %d\n",drive);
#endif
if (drive != selected) {
printk(KERN_WARNING "Deselecting drive %d while %d was selected!\n",drive,selected);
return;
}
get_fdc(drive);
local_irq_save(flags);
selected = -1;
prb = ciab.prb;
prb |= (SELMASK(0)|SELMASK(1)|SELMASK(2)|SELMASK(3));
ciab.prb = prb;
local_irq_restore (flags);
rel_fdc();
}
static void motor_on_callback(unsigned long nr)
{
if (!(ciaa.pra & DSKRDY) || --on_attempts == 0) {
complete_all(&motor_on_completion);
} else {
motor_on_timer.expires = jiffies + HZ/10;
add_timer(&motor_on_timer);
}
}
static int fd_motor_on(int nr)
{
nr &= 3;
del_timer(motor_off_timer + nr);
if (!unit[nr].motor) {
unit[nr].motor = 1;
fd_select(nr);
INIT_COMPLETION(motor_on_completion);
motor_on_timer.data = nr;
mod_timer(&motor_on_timer, jiffies + HZ/2);
on_attempts = 10;
wait_for_completion(&motor_on_completion);
fd_deselect(nr);
}
if (on_attempts == 0) {
on_attempts = -1;
#if 0
printk (KERN_ERR "motor_on failed, turning motor off\n");
fd_motor_off (nr);
return 0;
#else
printk (KERN_WARNING "DSKRDY not set after 1.5 seconds - assuming drive is spinning notwithstanding\n");
#endif
}
return 1;
}
static void fd_motor_off(unsigned long drive)
{
long calledfromint;
#ifdef MODULE
long decusecount;
decusecount = drive & 0x40000000;
#endif
calledfromint = drive & 0x80000000;
drive&=3;
if (calledfromint && !try_fdc(drive)) {
motor_off_timer[drive].expires = jiffies + 1;
add_timer(motor_off_timer + drive);
return;
}
unit[drive].motor = 0;
fd_select(drive);
udelay (1);
fd_deselect(drive);
}
static void floppy_off (unsigned int nr)
{
int drive;
drive = nr & 3;
motor_off_timer[drive].data = nr | 0x80000000;
mod_timer(motor_off_timer + drive, jiffies + 3*HZ);
}
static int fd_calibrate(int drive)
{
unsigned char prb;
int n;
drive &= 3;
get_fdc(drive);
if (!fd_motor_on (drive))
return 0;
fd_select (drive);
prb = ciab.prb;
prb |= DSKSIDE;
prb &= ~DSKDIREC;
ciab.prb = prb;
for (n = unit[drive].type->tracks/2; n != 0; --n) {
if (ciaa.pra & DSKTRACK0)
break;
prb &= ~DSKSTEP;
ciab.prb = prb;
prb |= DSKSTEP;
udelay (2);
ciab.prb = prb;
ms_delay(unit[drive].type->step_delay);
}
ms_delay (unit[drive].type->settle_time);
prb |= DSKDIREC;
n = unit[drive].type->tracks + 20;
for (;;) {
prb &= ~DSKSTEP;
ciab.prb = prb;
prb |= DSKSTEP;
udelay (2);
ciab.prb = prb;
ms_delay(unit[drive].type->step_delay + 1);
if ((ciaa.pra & DSKTRACK0) == 0)
break;
if (--n == 0) {
printk (KERN_ERR "fd%d: calibrate failed, turning motor off\n", drive);
fd_motor_off (drive);
unit[drive].track = -1;
rel_fdc();
return 0;
}
}
unit[drive].track = 0;
ms_delay(unit[drive].type->settle_time);
rel_fdc();
fd_deselect(drive);
return 1;
}
static int fd_seek(int drive, int track)
{
unsigned char prb;
int cnt;
#ifdef DEBUG
printk("seeking drive %d to track %d\n",drive,track);
#endif
drive &= 3;
get_fdc(drive);
if (unit[drive].track == track) {
rel_fdc();
return 1;
}
if (!fd_motor_on(drive)) {
rel_fdc();
return 0;
}
if (unit[drive].track < 0 && !fd_calibrate(drive)) {
rel_fdc();
return 0;
}
fd_select (drive);
cnt = unit[drive].track/2 - track/2;
prb = ciab.prb;
prb |= DSKSIDE | DSKDIREC;
if (track % 2 != 0)
prb &= ~DSKSIDE;
if (cnt < 0) {
cnt = - cnt;
prb &= ~DSKDIREC;
}
ciab.prb = prb;
if (track % 2 != unit[drive].track % 2)
ms_delay (unit[drive].type->side_time);
unit[drive].track = track;
if (cnt == 0) {
rel_fdc();
fd_deselect(drive);
return 1;
}
do {
prb &= ~DSKSTEP;
ciab.prb = prb;
prb |= DSKSTEP;
udelay (1);
ciab.prb = prb;
ms_delay (unit[drive].type->step_delay);
} while (--cnt != 0);
ms_delay (unit[drive].type->settle_time);
rel_fdc();
fd_deselect(drive);
return 1;
}
static unsigned long fd_get_drive_id(int drive)
{
int i;
ulong id = 0;
drive&=3;
get_fdc(drive);
MOTOR_ON;
udelay(2);
SELECT(SELMASK(drive));
udelay(2);
DESELECT(SELMASK(drive));
udelay(2);
MOTOR_OFF;
udelay(2);
SELECT(SELMASK(drive));
udelay(2);
DESELECT(SELMASK(drive));
udelay(2);
for (i=0; i<32; i++) {
SELECT(SELMASK(drive));
udelay(2);
id <<= 1;
id |= (ciaa.pra & DSKRDY) ? 0 : 1;
DESELECT(SELMASK(drive));
}
rel_fdc();
if(drive == 0 && id == FD_NODRIVE)
{
id = fd_def_df0;
printk(KERN_NOTICE "fd: drive 0 didn't identify, setting default %08lx\n", (ulong)fd_def_df0);
}
return (id);
}
static irqreturn_t fd_block_done(int irq, void *dummy)
{
if (block_flag)
custom.dsklen = 0x4000;
if (block_flag == 2) {
writepending = 2;
post_write_timer.expires = jiffies + 1;
post_write_timer.data = selected;
add_timer(&post_write_timer);
}
else {
block_flag = 0;
wake_up (&wait_fd_block);
}
return IRQ_HANDLED;
}
static void raw_read(int drive)
{
drive&=3;
get_fdc(drive);
wait_event(wait_fd_block, !block_flag);
fd_select(drive);
custom.adkcon = ADK_MSBSYNC;
custom.adkcon = ADK_SETCLR|ADK_WORDSYNC|ADK_FAST;
custom.dsksync = MFM_SYNC;
custom.dsklen = 0;
custom.dskptr = (u_char *)ZTWO_PADDR((u_char *)raw_buf);
custom.dsklen = unit[drive].type->read_size/sizeof(short) | DSKLEN_DMAEN;
custom.dsklen = unit[drive].type->read_size/sizeof(short) | DSKLEN_DMAEN;
block_flag = 1;
wait_event(wait_fd_block, !block_flag);
custom.dsklen = 0;
fd_deselect(drive);
rel_fdc();
}
static int raw_write(int drive)
{
ushort adk;
drive&=3;
get_fdc(drive);
if ((ciaa.pra & DSKPROT) == 0) {
rel_fdc();
return 0;
}
wait_event(wait_fd_block, !block_flag);
fd_select(drive);
custom.adkcon = ADK_PRECOMP1|ADK_PRECOMP0|ADK_WORDSYNC|ADK_MSBSYNC;
adk = ADK_SETCLR|ADK_FAST;
if ((ulong)unit[drive].track >= unit[drive].type->precomp2)
adk |= ADK_PRECOMP1;
else if ((ulong)unit[drive].track >= unit[drive].type->precomp1)
adk |= ADK_PRECOMP0;
custom.adkcon = adk;
custom.dsklen = DSKLEN_WRITE;
custom.dskptr = (u_char *)ZTWO_PADDR((u_char *)raw_buf);
custom.dsklen = unit[drive].type->write_size/sizeof(short) | DSKLEN_DMAEN|DSKLEN_WRITE;
custom.dsklen = unit[drive].type->write_size/sizeof(short) | DSKLEN_DMAEN|DSKLEN_WRITE;
block_flag = 2;
return 1;
}
static void post_write (unsigned long drive)
{
#ifdef DEBUG
printk("post_write for drive %ld\n",drive);
#endif
drive &= 3;
custom.dsklen = 0;
block_flag = 0;
writepending = 0;
writefromint = 0;
unit[drive].dirty = 0;
wake_up(&wait_fd_block);
fd_deselect(drive);
rel_fdc();
}
static unsigned long scan_sync(unsigned long raw, unsigned long end)
{
ushort *ptr = (ushort *)raw, *endp = (ushort *)end;
while (ptr < endp && *ptr++ != 0x4489)
;
if (ptr < endp) {
while (*ptr == 0x4489 && ptr < endp)
ptr++;
return (ulong)ptr;
}
return 0;
}
static inline unsigned long checksum(unsigned long *addr, int len)
{
unsigned long csum = 0;
len /= sizeof(*addr);
while (len-- > 0)
csum ^= *addr++;
csum = ((csum>>1) & 0x55555555) ^ (csum & 0x55555555);
return csum;
}
static unsigned long decode (unsigned long *data, unsigned long *raw,
int len)
{
ulong *odd, *even;
len >>= 2;
odd = raw;
even = odd + len;
raw += len * 2;
do {
*data++ = ((*odd++ & 0x55555555) << 1) | (*even++ & 0x55555555);
} while (--len != 0);
return (ulong)raw;
}
static int amiga_read(int drive)
{
unsigned long raw;
unsigned long end;
int scnt;
unsigned long csum;
struct header hdr;
drive&=3;
raw = (long) raw_buf;
end = raw + unit[drive].type->read_size;
for (scnt = 0;scnt < unit[drive].dtype->sects * unit[drive].type->sect_mult; scnt++) {
if (!(raw = scan_sync(raw, end))) {
printk (KERN_INFO "can't find sync for sector %d\n", scnt);
return MFM_NOSYNC;
}
raw = decode ((ulong *)&hdr.magic, (ulong *)raw, 4);
raw = decode ((ulong *)&hdr.labels, (ulong *)raw, 16);
raw = decode ((ulong *)&hdr.hdrchk, (ulong *)raw, 4);
raw = decode ((ulong *)&hdr.datachk, (ulong *)raw, 4);
csum = checksum((ulong *)&hdr,
(char *)&hdr.hdrchk-(char *)&hdr);
#ifdef DEBUG
printk ("(%x,%d,%d,%d) (%lx,%lx,%lx,%lx) %lx %lx\n",
hdr.magic, hdr.track, hdr.sect, hdr.ord,
*(ulong *)&hdr.labels[0], *(ulong *)&hdr.labels[4],
*(ulong *)&hdr.labels[8], *(ulong *)&hdr.labels[12],
hdr.hdrchk, hdr.datachk);
#endif
if (hdr.hdrchk != csum) {
printk(KERN_INFO "MFM_HEADER: %08lx,%08lx\n", hdr.hdrchk, csum);
return MFM_HEADER;
}
if (hdr.track != unit[drive].track) {
printk(KERN_INFO "MFM_TRACK: %d, %d\n", hdr.track, unit[drive].track);
return MFM_TRACK;
}
raw = decode ((ulong *)(unit[drive].trackbuf + hdr.sect*512),
(ulong *)raw, 512);
csum = checksum((ulong *)(unit[drive].trackbuf + hdr.sect*512), 512);
if (hdr.datachk != csum) {
printk(KERN_INFO "MFM_DATA: (%x:%d:%d:%d) sc=%d %lx, %lx\n",
hdr.magic, hdr.track, hdr.sect, hdr.ord, scnt,
hdr.datachk, csum);
printk (KERN_INFO "data=(%lx,%lx,%lx,%lx)\n",
((ulong *)(unit[drive].trackbuf+hdr.sect*512))[0],
((ulong *)(unit[drive].trackbuf+hdr.sect*512))[1],
((ulong *)(unit[drive].trackbuf+hdr.sect*512))[2],
((ulong *)(unit[drive].trackbuf+hdr.sect*512))[3]);
return MFM_DATA;
}
}
return 0;
}
static void encode(unsigned long data, unsigned long *dest)
{
unsigned long data2;
data &= 0x55555555;
data2 = data ^ 0x55555555;
data |= ((data2 >> 1) | 0x80000000) & (data2 << 1);
if (*(dest - 1) & 0x00000001)
data &= 0x7FFFFFFF;
*dest = data;
}
static void encode_block(unsigned long *dest, unsigned long *src, int len)
{
int cnt, to_cnt = 0;
unsigned long data;
for (cnt = 0; cnt < len / 4; cnt++) {
data = src[cnt] >> 1;
encode(data, dest + to_cnt++);
}
for (cnt = 0; cnt < len / 4; cnt++) {
data = src[cnt];
encode(data, dest + to_cnt++);
}
}
static unsigned long *putsec(int disk, unsigned long *raw, int cnt)
{
struct header hdr;
int i;
disk&=3;
*raw = (raw[-1]&1) ? 0x2AAAAAAA : 0xAAAAAAAA;
raw++;
*raw++ = 0x44894489;
hdr.magic = 0xFF;
hdr.track = unit[disk].track;
hdr.sect = cnt;
hdr.ord = unit[disk].dtype->sects * unit[disk].type->sect_mult - cnt;
for (i = 0; i < 16; i++)
hdr.labels[i] = 0;
hdr.hdrchk = checksum((ulong *)&hdr,
(char *)&hdr.hdrchk-(char *)&hdr);
hdr.datachk = checksum((ulong *)(unit[disk].trackbuf+cnt*512), 512);
encode_block(raw, (ulong *)&hdr.magic, 4);
raw += 2;
encode_block(raw, (ulong *)&hdr.labels, 16);
raw += 8;
encode_block(raw, (ulong *)&hdr.hdrchk, 4);
raw += 2;
encode_block(raw, (ulong *)&hdr.datachk, 4);
raw += 2;
encode_block(raw, (ulong *)(unit[disk].trackbuf+cnt*512), 512);
raw += 256;
return raw;
}
static void amiga_write(int disk)
{
unsigned int cnt;
unsigned long *ptr = (unsigned long *)raw_buf;
disk&=3;
for (cnt = 0; cnt < 415 * unit[disk].type->sect_mult; cnt++)
*ptr++ = 0xaaaaaaaa;
for (cnt = 0; cnt < unit[disk].dtype->sects * unit[disk].type->sect_mult; cnt++)
ptr = putsec (disk, ptr, cnt);
*(ushort *)ptr = (ptr[-1]&1) ? 0x2AA8 : 0xAAA8;
}
static ushort dos_crc(void * data_a3, int data_d0, int data_d1, int data_d3)
{
static unsigned char CRCTable1[] = {
0x00,0x10,0x20,0x30,0x40,0x50,0x60,0x70,0x81,0x91,0xa1,0xb1,0xc1,0xd1,0xe1,0xf1,
0x12,0x02,0x32,0x22,0x52,0x42,0x72,0x62,0x93,0x83,0xb3,0xa3,0xd3,0xc3,0xf3,0xe3,
0x24,0x34,0x04,0x14,0x64,0x74,0x44,0x54,0xa5,0xb5,0x85,0x95,0xe5,0xf5,0xc5,0xd5,
0x36,0x26,0x16,0x06,0x76,0x66,0x56,0x46,0xb7,0xa7,0x97,0x87,0xf7,0xe7,0xd7,0xc7,
0x48,0x58,0x68,0x78,0x08,0x18,0x28,0x38,0xc9,0xd9,0xe9,0xf9,0x89,0x99,0xa9,0xb9,
0x5a,0x4a,0x7a,0x6a,0x1a,0x0a,0x3a,0x2a,0xdb,0xcb,0xfb,0xeb,0x9b,0x8b,0xbb,0xab,
0x6c,0x7c,0x4c,0x5c,0x2c,0x3c,0x0c,0x1c,0xed,0xfd,0xcd,0xdd,0xad,0xbd,0x8d,0x9d,
0x7e,0x6e,0x5e,0x4e,0x3e,0x2e,0x1e,0x0e,0xff,0xef,0xdf,0xcf,0xbf,0xaf,0x9f,0x8f,
0x91,0x81,0xb1,0xa1,0xd1,0xc1,0xf1,0xe1,0x10,0x00,0x30,0x20,0x50,0x40,0x70,0x60,
0x83,0x93,0xa3,0xb3,0xc3,0xd3,0xe3,0xf3,0x02,0x12,0x22,0x32,0x42,0x52,0x62,0x72,
0xb5,0xa5,0x95,0x85,0xf5,0xe5,0xd5,0xc5,0x34,0x24,0x14,0x04,0x74,0x64,0x54,0x44,
0xa7,0xb7,0x87,0x97,0xe7,0xf7,0xc7,0xd7,0x26,0x36,0x06,0x16,0x66,0x76,0x46,0x56,
0xd9,0xc9,0xf9,0xe9,0x99,0x89,0xb9,0xa9,0x58,0x48,0x78,0x68,0x18,0x08,0x38,0x28,
0xcb,0xdb,0xeb,0xfb,0x8b,0x9b,0xab,0xbb,0x4a,0x5a,0x6a,0x7a,0x0a,0x1a,0x2a,0x3a,
0xfd,0xed,0xdd,0xcd,0xbd,0xad,0x9d,0x8d,0x7c,0x6c,0x5c,0x4c,0x3c,0x2c,0x1c,0x0c,
0xef,0xff,0xcf,0xdf,0xaf,0xbf,0x8f,0x9f,0x6e,0x7e,0x4e,0x5e,0x2e,0x3e,0x0e,0x1e
};
static unsigned char CRCTable2[] = {
0x00,0x21,0x42,0x63,0x84,0xa5,0xc6,0xe7,0x08,0x29,0x4a,0x6b,0x8c,0xad,0xce,0xef,
0x31,0x10,0x73,0x52,0xb5,0x94,0xf7,0xd6,0x39,0x18,0x7b,0x5a,0xbd,0x9c,0xff,0xde,
0x62,0x43,0x20,0x01,0xe6,0xc7,0xa4,0x85,0x6a,0x4b,0x28,0x09,0xee,0xcf,0xac,0x8d,
0x53,0x72,0x11,0x30,0xd7,0xf6,0x95,0xb4,0x5b,0x7a,0x19,0x38,0xdf,0xfe,0x9d,0xbc,
0xc4,0xe5,0x86,0xa7,0x40,0x61,0x02,0x23,0xcc,0xed,0x8e,0xaf,0x48,0x69,0x0a,0x2b,
0xf5,0xd4,0xb7,0x96,0x71,0x50,0x33,0x12,0xfd,0xdc,0xbf,0x9e,0x79,0x58,0x3b,0x1a,
0xa6,0x87,0xe4,0xc5,0x22,0x03,0x60,0x41,0xae,0x8f,0xec,0xcd,0x2a,0x0b,0x68,0x49,
0x97,0xb6,0xd5,0xf4,0x13,0x32,0x51,0x70,0x9f,0xbe,0xdd,0xfc,0x1b,0x3a,0x59,0x78,
0x88,0xa9,0xca,0xeb,0x0c,0x2d,0x4e,0x6f,0x80,0xa1,0xc2,0xe3,0x04,0x25,0x46,0x67,
0xb9,0x98,0xfb,0xda,0x3d,0x1c,0x7f,0x5e,0xb1,0x90,0xf3,0xd2,0x35,0x14,0x77,0x56,
0xea,0xcb,0xa8,0x89,0x6e,0x4f,0x2c,0x0d,0xe2,0xc3,0xa0,0x81,0x66,0x47,0x24,0x05,
0xdb,0xfa,0x99,0xb8,0x5f,0x7e,0x1d,0x3c,0xd3,0xf2,0x91,0xb0,0x57,0x76,0x15,0x34,
0x4c,0x6d,0x0e,0x2f,0xc8,0xe9,0x8a,0xab,0x44,0x65,0x06,0x27,0xc0,0xe1,0x82,0xa3,
0x7d,0x5c,0x3f,0x1e,0xf9,0xd8,0xbb,0x9a,0x75,0x54,0x37,0x16,0xf1,0xd0,0xb3,0x92,
0x2e,0x0f,0x6c,0x4d,0xaa,0x8b,0xe8,0xc9,0x26,0x07,0x64,0x45,0xa2,0x83,0xe0,0xc1,
0x1f,0x3e,0x5d,0x7c,0x9b,0xba,0xd9,0xf8,0x17,0x36,0x55,0x74,0x93,0xb2,0xd1,0xf0
};
register int i;
register unsigned char *CRCT1, *CRCT2, *data, c, crch, crcl;
CRCT1=CRCTable1;
CRCT2=CRCTable2;
data=data_a3;
crcl=data_d1;
crch=data_d0;
for (i=data_d3; i>=0; i--) {
c = (*data++) ^ crch;
crch = CRCT1[c] ^ crcl;
crcl = CRCT2[c];
}
return (crch<<8)|crcl;
}
static inline ushort dos_hdr_crc (struct dos_header *hdr)
{
return dos_crc(&(hdr->track), 0xb2, 0x30, 3);
}
static inline ushort dos_data_crc(unsigned char *data)
{
return dos_crc(data, 0xe2, 0x95 ,511);
}
static inline unsigned char dos_decode_byte(ushort word)
{
register ushort w2;
register unsigned char byte;
register unsigned char *dec = mfmdecode;
w2=word;
w2>>=8;
w2&=127;
byte = dec[w2];
byte <<= 4;
w2 = word & 127;
byte |= dec[w2];
return byte;
}
static unsigned long dos_decode(unsigned char *data, unsigned short *raw, int len)
{
int i;
for (i = 0; i < len; i++)
*data++=dos_decode_byte(*raw++);
return ((ulong)raw);
}
static void dbg(unsigned long ptr)
{
printk("raw data @%08lx: %08lx, %08lx ,%08lx, %08lx\n", ptr,
((ulong *)ptr)[0], ((ulong *)ptr)[1],
((ulong *)ptr)[2], ((ulong *)ptr)[3]);
}
static int dos_read(int drive)
{
unsigned long end;
unsigned long raw;
int scnt;
unsigned short crc,data_crc[2];
struct dos_header hdr;
drive&=3;
raw = (long) raw_buf;
end = raw + unit[drive].type->read_size;
for (scnt=0; scnt < unit[drive].dtype->sects * unit[drive].type->sect_mult; scnt++) {
do {
if (!(raw = scan_sync (raw, end))) {
printk(KERN_INFO "dos_read: no hdr sync on "
"track %d, unit %d for sector %d\n",
unit[drive].track,drive,scnt);
return MFM_NOSYNC;
}
#ifdef DEBUG
dbg(raw);
#endif
} while (*((ushort *)raw)!=0x5554);
raw+=2;
raw = dos_decode((unsigned char *)&hdr,(ushort *) raw,8);
crc = dos_hdr_crc(&hdr);
#ifdef DEBUG
printk("(%3d,%d,%2d,%d) %x\n", hdr.track, hdr.side,
hdr.sec, hdr.len_desc, hdr.crc);
#endif
if (crc != hdr.crc) {
printk(KERN_INFO "dos_read: MFM_HEADER %04x,%04x\n",
hdr.crc, crc);
return MFM_HEADER;
}
if (hdr.track != unit[drive].track/unit[drive].type->heads) {
printk(KERN_INFO "dos_read: MFM_TRACK %d, %d\n",
hdr.track,
unit[drive].track/unit[drive].type->heads);
return MFM_TRACK;
}
if (hdr.side != unit[drive].track%unit[drive].type->heads) {
printk(KERN_INFO "dos_read: MFM_SIDE %d, %d\n",
hdr.side,
unit[drive].track%unit[drive].type->heads);
return MFM_TRACK;
}
if (hdr.len_desc != 2) {
printk(KERN_INFO "dos_read: unknown sector len "
"descriptor %d\n", hdr.len_desc);
return MFM_DATA;
}
#ifdef DEBUG
printk("hdr accepted\n");
#endif
if (!(raw = scan_sync (raw, end))) {
printk(KERN_INFO "dos_read: no data sync on track "
"%d, unit %d for sector%d, disk sector %d\n",
unit[drive].track, drive, scnt, hdr.sec);
return MFM_NOSYNC;
}
#ifdef DEBUG
dbg(raw);
#endif
if (*((ushort *)raw)!=0x5545) {
printk(KERN_INFO "dos_read: no data mark after "
"sync (%d,%d,%d,%d) sc=%d\n",
hdr.track,hdr.side,hdr.sec,hdr.len_desc,scnt);
return MFM_NOSYNC;
}
raw+=2;
raw = dos_decode((unsigned char *)(unit[drive].trackbuf + (hdr.sec - 1) * 512), (ushort *) raw, 512);
raw = dos_decode((unsigned char *)data_crc,(ushort *) raw,4);
crc = dos_data_crc(unit[drive].trackbuf + (hdr.sec - 1) * 512);
if (crc != data_crc[0]) {
printk(KERN_INFO "dos_read: MFM_DATA (%d,%d,%d,%d) "
"sc=%d, %x %x\n", hdr.track, hdr.side,
hdr.sec, hdr.len_desc, scnt,data_crc[0], crc);
printk(KERN_INFO "data=(%lx,%lx,%lx,%lx,...)\n",
((ulong *)(unit[drive].trackbuf+(hdr.sec-1)*512))[0],
((ulong *)(unit[drive].trackbuf+(hdr.sec-1)*512))[1],
((ulong *)(unit[drive].trackbuf+(hdr.sec-1)*512))[2],
((ulong *)(unit[drive].trackbuf+(hdr.sec-1)*512))[3]);
return MFM_DATA;
}
}
return 0;
}
static inline ushort dos_encode_byte(unsigned char byte)
{
register unsigned char *enc, b2, b1;
register ushort word;
enc=mfmencode;
b1=byte;
b2=b1>>4;
b1&=15;
word=enc[b2] <<8 | enc [b1];
return (word|((word&(256|64)) ? 0: 128));
}
static void dos_encode_block(ushort *dest, unsigned char *src, int len)
{
int i;
for (i = 0; i < len; i++) {
*dest=dos_encode_byte(*src++);
*dest|=((dest[-1]&1)||(*dest&0x4000))? 0: 0x8000;
dest++;
}
}
static unsigned long *ms_putsec(int drive, unsigned long *raw, int cnt)
{
static struct dos_header hdr={0,0,0,2,0,
{78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78}};
int i;
static ushort crc[2]={0,0x4e4e};
drive&=3;
for(i=0;i<6;i++)
*raw++=0xaaaaaaaa;
*raw++=0x44894489;
*raw++=0x44895554;
hdr.track=unit[drive].track/unit[drive].type->heads;
hdr.side=unit[drive].track%unit[drive].type->heads;
hdr.sec=cnt+1;
hdr.crc=dos_hdr_crc(&hdr);
dos_encode_block((ushort *)raw,(unsigned char *) &hdr.track,28);
raw+=14;
for(i=0;i<6;i++)
*raw++=0xaaaaaaaa;
*raw++=0x44894489;
*raw++=0x44895545;
dos_encode_block((ushort *)raw,
(unsigned char *)unit[drive].trackbuf+cnt*512,512);
raw+=256;
crc[0]=dos_data_crc(unit[drive].trackbuf+cnt*512);
dos_encode_block((ushort *) raw,(unsigned char *)crc,4);
raw+=2;
for(i=0;i<38;i++)
*raw++=0x92549254;
return raw;
}
static void dos_write(int disk)
{
int cnt;
unsigned long raw = (unsigned long) raw_buf;
unsigned long *ptr=(unsigned long *)raw;
disk&=3;
for (cnt=0;cnt<425;cnt++)
*ptr++=0x92549254;
if (unit[disk].type->sect_mult==2)
for(cnt=0;cnt<473;cnt++)
*ptr++=0x92549254;
for (cnt=0;cnt<20;cnt++)
*ptr++=0x92549254;
for (cnt=0;cnt<6;cnt++)
*ptr++=0xaaaaaaaa;
*ptr++=0x52245224;
*ptr++=0x52245552;
for (cnt=0;cnt<20;cnt++)
*ptr++=0x92549254;
for(cnt = 0; cnt < unit[disk].dtype->sects * unit[disk].type->sect_mult; cnt++)
ptr=ms_putsec(disk,ptr,cnt);
*(ushort *)ptr = 0xaaa8;
}
static void flush_track_callback(unsigned long nr)
{
nr&=3;
writefromint = 1;
if (!try_fdc(nr)) {
flush_track_timer[nr].expires = jiffies + 1;
add_timer(flush_track_timer + nr);
return;
}
get_fdc(nr);
(*unit[nr].dtype->write_fkt)(nr);
if (!raw_write(nr)) {
printk (KERN_NOTICE "floppy disk write protected\n");
writefromint = 0;
writepending = 0;
}
rel_fdc();
}
static int non_int_flush_track (unsigned long nr)
{
unsigned long flags;
nr&=3;
writefromint = 0;
del_timer(&post_write_timer);
get_fdc(nr);
if (!fd_motor_on(nr)) {
writepending = 0;
rel_fdc();
return 0;
}
local_irq_save(flags);
if (writepending != 2) {
local_irq_restore(flags);
(*unit[nr].dtype->write_fkt)(nr);
if (!raw_write(nr)) {
printk (KERN_NOTICE "floppy disk write protected "
"in write!\n");
writepending = 0;
return 0;
}
wait_event(wait_fd_block, block_flag != 2);
}
else {
local_irq_restore(flags);
ms_delay(2);
post_write(nr);
}
rel_fdc();
return 1;
}
static int get_track(int drive, int track)
{
int error, errcnt;
drive&=3;
if (unit[drive].track == track)
return 0;
get_fdc(drive);
if (!fd_motor_on(drive)) {
rel_fdc();
return -1;
}
if (unit[drive].dirty == 1) {
del_timer (flush_track_timer + drive);
non_int_flush_track (drive);
}
errcnt = 0;
while (errcnt < MAX_ERRORS) {
if (!fd_seek(drive, track))
return -1;
raw_read(drive);
error = (*unit[drive].dtype->read_fkt)(drive);
if (error == 0) {
rel_fdc();
return 0;
}
unit[drive].track = -1;
errcnt++;
}
rel_fdc();
return -1;
}
static struct request *set_next_request(void)
{
struct request_queue *q;
int cnt = FD_MAX_UNITS;
struct request *rq = NULL;
fdc_queue = fdc_queue + 1;
if (fdc_queue == FD_MAX_UNITS)
fdc_queue = 0;
for(cnt = FD_MAX_UNITS; cnt > 0; cnt--) {
if (unit[fdc_queue].type->code == FD_NODRIVE) {
if (++fdc_queue == FD_MAX_UNITS)
fdc_queue = 0;
continue;
}
q = unit[fdc_queue].gendisk->queue;
if (q) {
rq = blk_fetch_request(q);
if (rq)
break;
}
if (++fdc_queue == FD_MAX_UNITS)
fdc_queue = 0;
}
return rq;
}
static void redo_fd_request(void)
{
struct request *rq;
unsigned int cnt, block, track, sector;
int drive;
struct amiga_floppy_struct *floppy;
char *data;
unsigned long flags;
int err;
next_req:
rq = set_next_request();
if (!rq) {
return;
}
floppy = rq->rq_disk->private_data;
drive = floppy - unit;
next_segment:
for (cnt = 0, err = 0; cnt < blk_rq_cur_sectors(rq); cnt++) {
#ifdef DEBUG
printk("fd: sector %ld + %d requested for %s\n",
blk_rq_pos(rq), cnt,
(rq_data_dir(rq) == READ) ? "read" : "write");
#endif
block = blk_rq_pos(rq) + cnt;
if ((int)block > floppy->blocks) {
err = -EIO;
break;
}
track = block / (floppy->dtype->sects * floppy->type->sect_mult);
sector = block % (floppy->dtype->sects * floppy->type->sect_mult);
data = rq->buffer + 512 * cnt;
#ifdef DEBUG
printk("access to track %d, sector %d, with buffer at "
"0x%08lx\n", track, sector, data);
#endif
if (get_track(drive, track) == -1) {
err = -EIO;
break;
}
if (rq_data_dir(rq) == READ) {
memcpy(data, floppy->trackbuf + sector * 512, 512);
} else {
memcpy(floppy->trackbuf + sector * 512, data, 512);
if (!fd_motor_on(drive)) {
err = -EIO;
break;
}
local_irq_save(flags);
floppy->dirty = 1;
mod_timer (flush_track_timer + drive, jiffies + 1);
local_irq_restore(flags);
}
}
if (__blk_end_request_cur(rq, err))
goto next_segment;
goto next_req;
}
static void do_fd_request(struct request_queue * q)
{
redo_fd_request();
}
static int fd_getgeo(struct block_device *bdev, struct hd_geometry *geo)
{
int drive = MINOR(bdev->bd_dev) & 3;
geo->heads = unit[drive].type->heads;
geo->sectors = unit[drive].dtype->sects * unit[drive].type->sect_mult;
geo->cylinders = unit[drive].type->tracks;
return 0;
}
static int fd_locked_ioctl(struct block_device *bdev, fmode_t mode,
unsigned int cmd, unsigned long param)
{
struct amiga_floppy_struct *p = bdev->bd_disk->private_data;
int drive = p - unit;
static struct floppy_struct getprm;
void __user *argp = (void __user *)param;
switch(cmd){
case FDFMTBEG:
get_fdc(drive);
if (fd_ref[drive] > 1) {
rel_fdc();
return -EBUSY;
}
fsync_bdev(bdev);
if (fd_motor_on(drive) == 0) {
rel_fdc();
return -ENODEV;
}
if (fd_calibrate(drive) == 0) {
rel_fdc();
return -ENXIO;
}
floppy_off(drive);
rel_fdc();
break;
case FDFMTTRK:
if (param < p->type->tracks * p->type->heads)
{
get_fdc(drive);
if (fd_seek(drive,param) != 0){
memset(p->trackbuf, FD_FILL_BYTE,
p->dtype->sects * p->type->sect_mult * 512);
non_int_flush_track(drive);
}
floppy_off(drive);
rel_fdc();
}
else
return -EINVAL;
break;
case FDFMTEND:
floppy_off(drive);
invalidate_bdev(bdev);
break;
case FDGETPRM:
memset((void *)&getprm, 0, sizeof (getprm));
getprm.track=p->type->tracks;
getprm.head=p->type->heads;
getprm.sect=p->dtype->sects * p->type->sect_mult;
getprm.size=p->blocks;
if (copy_to_user(argp, &getprm, sizeof(struct floppy_struct)))
return -EFAULT;
break;
case FDSETPRM:
case FDDEFPRM:
return -EINVAL;
case FDFLUSH:
del_timer (flush_track_timer + drive);
non_int_flush_track(drive);
break;
#ifdef RAW_IOCTL
case IOCTL_RAW_TRACK:
if (copy_to_user(argp, raw_buf, p->type->read_size))
return -EFAULT;
else
return p->type->read_size;
#endif
default:
printk(KERN_DEBUG "fd_ioctl: unknown cmd %d for drive %d.",
cmd, drive);
return -ENOSYS;
}
return 0;
}
static int fd_ioctl(struct block_device *bdev, fmode_t mode,
unsigned int cmd, unsigned long param)
{
int ret;
mutex_lock(&amiflop_mutex);
ret = fd_locked_ioctl(bdev, mode, cmd, param);
mutex_unlock(&amiflop_mutex);
return ret;
}
static void fd_probe(int dev)
{
unsigned long code;
int type;
int drive;
drive = dev & 3;
code = fd_get_drive_id(drive);
for (type = 0; type < num_dr_types; type++)
if (drive_types[type].code == code)
break;
if (type >= num_dr_types) {
printk(KERN_WARNING "fd_probe: unsupported drive type "
"%08lx found\n", code);
unit[drive].type = &drive_types[num_dr_types-1];
return;
}
unit[drive].type = drive_types + type;
unit[drive].track = -1;
unit[drive].disk = -1;
unit[drive].motor = 0;
unit[drive].busy = 0;
unit[drive].status = -1;
}
static int floppy_open(struct block_device *bdev, fmode_t mode)
{
int drive = MINOR(bdev->bd_dev) & 3;
int system = (MINOR(bdev->bd_dev) & 4) >> 2;
int old_dev;
unsigned long flags;
mutex_lock(&amiflop_mutex);
old_dev = fd_device[drive];
if (fd_ref[drive] && old_dev != system) {
mutex_unlock(&amiflop_mutex);
return -EBUSY;
}
if (mode & (FMODE_READ|FMODE_WRITE)) {
check_disk_change(bdev);
if (mode & FMODE_WRITE) {
int wrprot;
get_fdc(drive);
fd_select (drive);
wrprot = !(ciaa.pra & DSKPROT);
fd_deselect (drive);
rel_fdc();
if (wrprot) {
mutex_unlock(&amiflop_mutex);
return -EROFS;
}
}
}
local_irq_save(flags);
fd_ref[drive]++;
fd_device[drive] = system;
local_irq_restore(flags);
unit[drive].dtype=&data_types[system];
unit[drive].blocks=unit[drive].type->heads*unit[drive].type->tracks*
data_types[system].sects*unit[drive].type->sect_mult;
set_capacity(unit[drive].gendisk, unit[drive].blocks);
printk(KERN_INFO "fd%d: accessing %s-disk with %s-layout\n",drive,
unit[drive].type->name, data_types[system].name);
mutex_unlock(&amiflop_mutex);
return 0;
}
static void floppy_release(struct gendisk *disk, fmode_t mode)
{
struct amiga_floppy_struct *p = disk->private_data;
int drive = p - unit;
mutex_lock(&amiflop_mutex);
if (unit[drive].dirty == 1) {
del_timer (flush_track_timer + drive);
non_int_flush_track (drive);
}
if (!fd_ref[drive]--) {
printk(KERN_CRIT "floppy_release with fd_ref == 0");
fd_ref[drive] = 0;
}
#ifdef MODULE
floppy_off (drive | 0x40000000);
#endif
mutex_unlock(&amiflop_mutex);
}
static unsigned amiga_check_events(struct gendisk *disk, unsigned int clearing)
{
struct amiga_floppy_struct *p = disk->private_data;
int drive = p - unit;
int changed;
static int first_time = 1;
if (first_time)
changed = first_time--;
else {
get_fdc(drive);
fd_select (drive);
changed = !(ciaa.pra & DSKCHANGE);
fd_deselect (drive);
rel_fdc();
}
if (changed) {
fd_probe(drive);
p->track = -1;
p->dirty = 0;
writepending = 0;
writefromint = 0;
return DISK_EVENT_MEDIA_CHANGE;
}
return 0;
}
static int __init fd_probe_drives(void)
{
int drive,drives,nomem;
printk(KERN_INFO "FD: probing units\nfound ");
drives=0;
nomem=0;
for(drive=0;drive<FD_MAX_UNITS;drive++) {
struct gendisk *disk;
fd_probe(drive);
if (unit[drive].type->code == FD_NODRIVE)
continue;
disk = alloc_disk(1);
if (!disk) {
unit[drive].type->code = FD_NODRIVE;
continue;
}
unit[drive].gendisk = disk;
disk->queue = blk_init_queue(do_fd_request, &amiflop_lock);
if (!disk->queue) {
unit[drive].type->code = FD_NODRIVE;
continue;
}
drives++;
if ((unit[drive].trackbuf = kmalloc(FLOPPY_MAX_SECTORS * 512, GFP_KERNEL)) == NULL) {
printk("no mem for ");
unit[drive].type = &drive_types[num_dr_types - 1];
drives--;
nomem = 1;
}
printk("fd%d ",drive);
disk->major = FLOPPY_MAJOR;
disk->first_minor = drive;
disk->fops = &floppy_fops;
sprintf(disk->disk_name, "fd%d", drive);
disk->private_data = &unit[drive];
set_capacity(disk, 880*2);
add_disk(disk);
}
if ((drives > 0) || (nomem == 0)) {
if (drives == 0)
printk("no drives");
printk("\n");
return drives;
}
printk("\n");
return -ENOMEM;
}
static struct kobject *floppy_find(dev_t dev, int *part, void *data)
{
int drive = *part & 3;
if (unit[drive].type->code == FD_NODRIVE)
return NULL;
*part = 0;
return get_disk(unit[drive].gendisk);
}
static int __init amiga_floppy_probe(struct platform_device *pdev)
{
int i, ret;
if (register_blkdev(FLOPPY_MAJOR,"fd"))
return -EBUSY;
ret = -ENOMEM;
raw_buf = amiga_chip_alloc(RAW_BUF_SIZE, "Floppy");
if (!raw_buf) {
printk("fd: cannot get chip mem buffer\n");
goto out_blkdev;
}
ret = -EBUSY;
if (request_irq(IRQ_AMIGA_DSKBLK, fd_block_done, 0, "floppy_dma", NULL)) {
printk("fd: cannot get irq for dma\n");
goto out_irq;
}
if (request_irq(IRQ_AMIGA_CIAA_TB, ms_isr, 0, "floppy_timer", NULL)) {
printk("fd: cannot get irq for timer\n");
goto out_irq2;
}
ret = -ENODEV;
if (fd_probe_drives() < 1)
goto out_probe;
blk_register_region(MKDEV(FLOPPY_MAJOR, 0), 256, THIS_MODULE,
floppy_find, NULL, NULL);
init_timer(&motor_on_timer);
motor_on_timer.expires = 0;
motor_on_timer.data = 0;
motor_on_timer.function = motor_on_callback;
for (i = 0; i < FD_MAX_UNITS; i++) {
init_timer(&motor_off_timer[i]);
motor_off_timer[i].expires = 0;
motor_off_timer[i].data = i|0x80000000;
motor_off_timer[i].function = fd_motor_off;
init_timer(&flush_track_timer[i]);
flush_track_timer[i].expires = 0;
flush_track_timer[i].data = i;
flush_track_timer[i].function = flush_track_callback;
unit[i].track = -1;
}
init_timer(&post_write_timer);
post_write_timer.expires = 0;
post_write_timer.data = 0;
post_write_timer.function = post_write;
for (i = 0; i < 128; i++)
mfmdecode[i]=255;
for (i = 0; i < 16; i++)
mfmdecode[mfmencode[i]]=i;
custom.dmacon = DMAF_SETCLR | DMAF_DISK;
ciaa.crb = 8;
return 0;
out_probe:
free_irq(IRQ_AMIGA_CIAA_TB, NULL);
out_irq2:
free_irq(IRQ_AMIGA_DSKBLK, NULL);
out_irq:
amiga_chip_free(raw_buf);
out_blkdev:
unregister_blkdev(FLOPPY_MAJOR,"fd");
return ret;
}
static int __init amiga_floppy_init(void)
{
return platform_driver_probe(&amiga_floppy_driver, amiga_floppy_probe);
}
static int __init amiga_floppy_setup (char *str)
{
int n;
if (!MACH_IS_AMIGA)
return 0;
if (!get_option(&str, &n))
return 0;
printk (KERN_INFO "amiflop: Setting default df0 to %x\n", n);
fd_def_df0 = n;
return 1;
}
