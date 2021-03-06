static void
hwsq_cmd(struct nouveau_hwsq *hwsq, int size, u8 data[])
{
memcpy(&hwsq->c.data[hwsq->c.size], data, size * sizeof(data[0]));
hwsq->c.size += size;
}
int
nouveau_hwsq_init(struct nouveau_bus *pbus, struct nouveau_hwsq **phwsq)
{
struct nouveau_hwsq *hwsq;
hwsq = *phwsq = kmalloc(sizeof(*hwsq), GFP_KERNEL);
if (hwsq) {
hwsq->pbus = pbus;
hwsq->addr = ~0;
hwsq->data = ~0;
memset(hwsq->c.data, 0x7f, sizeof(hwsq->c.data));
hwsq->c.size = 0;
}
return hwsq ? 0 : -ENOMEM;
}
int
nouveau_hwsq_fini(struct nouveau_hwsq **phwsq, bool exec)
{
struct nouveau_hwsq *hwsq = *phwsq;
int ret = 0, i;
if (hwsq) {
struct nouveau_bus *pbus = hwsq->pbus;
hwsq->c.size = (hwsq->c.size + 4) / 4;
if (hwsq->c.size <= pbus->hwsq_size) {
if (exec)
ret = pbus->hwsq_exec(pbus, (u32 *)hwsq->c.data,
hwsq->c.size);
if (ret)
nv_error(pbus, "hwsq exec failed: %d\n", ret);
} else {
nv_error(pbus, "hwsq ucode too large\n");
ret = -ENOSPC;
}
for (i = 0; ret && i < hwsq->c.size; i++)
nv_error(pbus, "\t0x%08x\n", ((u32 *)hwsq->c.data)[i]);
*phwsq = NULL;
kfree(hwsq);
}
return ret;
}
void
nouveau_hwsq_wr32(struct nouveau_hwsq *hwsq, u32 addr, u32 data)
{
nv_debug(hwsq->pbus, "R[%06x] = 0x%08x\n", addr, data);
if (hwsq->data != data) {
if ((data & 0xffff0000) != (hwsq->data & 0xffff0000)) {
hwsq_cmd(hwsq, 5, (u8[]){ 0xe2, data, data >> 8,
data >> 16, data >> 24 });
} else {
hwsq_cmd(hwsq, 3, (u8[]){ 0x42, data, data >> 8 });
}
}
if ((addr & 0xffff0000) != (hwsq->addr & 0xffff0000)) {
hwsq_cmd(hwsq, 5, (u8[]){ 0xe0, addr, addr >> 8,
addr >> 16, addr >> 24 });
} else {
hwsq_cmd(hwsq, 3, (u8[]){ 0x40, addr, addr >> 8 });
}
hwsq->addr = addr;
hwsq->data = data;
}
void
nouveau_hwsq_setf(struct nouveau_hwsq *hwsq, u8 flag, int data)
{
nv_debug(hwsq->pbus, " FLAG[%02x] = %d\n", flag, data);
flag += 0x80;
if (data >= 0)
flag += 0x20;
if (data >= 1)
flag += 0x20;
hwsq_cmd(hwsq, 1, (u8[]){ flag });
}
void
nouveau_hwsq_wait(struct nouveau_hwsq *hwsq, u8 flag, u8 data)
{
nv_debug(hwsq->pbus, " WAIT[%02x] = %d\n", flag, data);
hwsq_cmd(hwsq, 3, (u8[]){ 0x5f, flag, data });
}
void
nouveau_hwsq_nsec(struct nouveau_hwsq *hwsq, u32 nsec)
{
u8 shift = 0, usec = nsec / 1000;
while (usec & ~3) {
usec >>= 2;
shift++;
}
nv_debug(hwsq->pbus, " DELAY = %d ns\n", nsec);
hwsq_cmd(hwsq, 1, (u8[]){ 0x00 | (shift << 2) | usec });
}
