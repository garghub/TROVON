static void hil_mlc_clear_di_map(hil_mlc *mlc, int val)
{
int j;
for (j = val; j < 7 ; j++)
mlc->di_map[j] = -1;
}
static void hil_mlc_clear_di_scratch(hil_mlc *mlc)
{
memset(&mlc->di_scratch, 0, sizeof(mlc->di_scratch));
}
static void hil_mlc_copy_di_scratch(hil_mlc *mlc, int idx)
{
memcpy(&mlc->di[idx], &mlc->di_scratch, sizeof(mlc->di_scratch));
}
static int hil_mlc_match_di_scratch(hil_mlc *mlc)
{
int idx;
for (idx = 0; idx < HIL_MLC_DEVMEM; idx++) {
int j, found = 0;
for (j = 0; j < 7 ; j++)
if (mlc->di_map[j] == idx)
found++;
if (found)
continue;
if (!memcmp(mlc->di + idx, &mlc->di_scratch,
sizeof(mlc->di_scratch)))
break;
}
return idx >= HIL_MLC_DEVMEM ? -1 : idx;
}
static int hil_mlc_find_free_di(hil_mlc *mlc)
{
int idx;
for (idx = 0; idx < HIL_MLC_DEVMEM; idx++) {
int j, found = 0;
for (j = 0; j < 7 ; j++)
if (mlc->di_map[j] == idx)
found++;
if (!found)
break;
}
return idx;
}
static inline void hil_mlc_clean_serio_map(hil_mlc *mlc)
{
int idx;
for (idx = 0; idx < HIL_MLC_DEVMEM; idx++) {
int j, found = 0;
for (j = 0; j < 7 ; j++)
if (mlc->di_map[j] == idx)
found++;
if (!found)
mlc->serio_map[idx].di_revmap = -1;
}
}
static void hil_mlc_send_polls(hil_mlc *mlc)
{
int did, i, cnt;
struct serio *serio;
struct serio_driver *drv;
i = cnt = 0;
did = (mlc->ipacket[0] & HIL_PKT_ADDR_MASK) >> 8;
serio = did ? mlc->serio[mlc->di_map[did - 1]] : NULL;
drv = (serio != NULL) ? serio->drv : NULL;
while (mlc->icount < 15 - i) {
hil_packet p;
p = mlc->ipacket[i];
if (did != (p & HIL_PKT_ADDR_MASK) >> 8) {
if (drv && drv->interrupt) {
drv->interrupt(serio, 0, 0);
drv->interrupt(serio, HIL_ERR_INT >> 16, 0);
drv->interrupt(serio, HIL_PKT_CMD >> 8, 0);
drv->interrupt(serio, HIL_CMD_POL + cnt, 0);
}
did = (p & HIL_PKT_ADDR_MASK) >> 8;
serio = did ? mlc->serio[mlc->di_map[did-1]] : NULL;
drv = (serio != NULL) ? serio->drv : NULL;
cnt = 0;
}
cnt++;
i++;
if (drv && drv->interrupt) {
drv->interrupt(serio, (p >> 24), 0);
drv->interrupt(serio, (p >> 16) & 0xff, 0);
drv->interrupt(serio, (p >> 8) & ~HIL_PKT_ADDR_MASK, 0);
drv->interrupt(serio, p & 0xff, 0);
}
}
}
static int hilse_match(hil_mlc *mlc, int unused)
{
int rc;
rc = hil_mlc_match_di_scratch(mlc);
if (rc == -1) {
rc = hil_mlc_find_free_di(mlc);
if (rc == -1)
goto err;
#ifdef HIL_MLC_DEBUG
printk(KERN_DEBUG PREFIX "new in slot %i\n", rc);
#endif
hil_mlc_copy_di_scratch(mlc, rc);
mlc->di_map[mlc->ddi] = rc;
mlc->serio_map[rc].di_revmap = mlc->ddi;
hil_mlc_clean_serio_map(mlc);
serio_rescan(mlc->serio[rc]);
return -1;
}
mlc->di_map[mlc->ddi] = rc;
#ifdef HIL_MLC_DEBUG
printk(KERN_DEBUG PREFIX "same in slot %i\n", rc);
#endif
mlc->serio_map[rc].di_revmap = mlc->ddi;
hil_mlc_clean_serio_map(mlc);
return 0;
err:
printk(KERN_ERR PREFIX "Residual device slots exhausted, close some serios!\n");
return 1;
}
static int hilse_init_lcv(hil_mlc *mlc, int unused)
{
struct timeval tv;
do_gettimeofday(&tv);
if (mlc->lcv && (tv.tv_sec - mlc->lcv_tv.tv_sec) < 5)
return -1;
mlc->lcv_tv = tv;
mlc->lcv = 0;
return 0;
}
static int hilse_inc_lcv(hil_mlc *mlc, int lim)
{
return mlc->lcv++ >= lim ? -1 : 0;
}
static int hilse_set_ddi(hil_mlc *mlc, int val)
{
mlc->ddi = val;
hil_mlc_clear_di_map(mlc, val + 1);
return 0;
}
static int hilse_dec_ddi(hil_mlc *mlc, int unused)
{
mlc->ddi--;
if (mlc->ddi <= -1) {
mlc->ddi = -1;
hil_mlc_clear_di_map(mlc, 0);
return -1;
}
hil_mlc_clear_di_map(mlc, mlc->ddi + 1);
return 0;
}
static int hilse_inc_ddi(hil_mlc *mlc, int unused)
{
BUG_ON(mlc->ddi >= 6);
mlc->ddi++;
return 0;
}
static int hilse_take_idd(hil_mlc *mlc, int unused)
{
int i;
if (mlc->ipacket[0] & HIL_PKT_CMD)
goto bail;
for (i = 1; i < 16; i++) {
if (((mlc->ipacket[i] & HIL_PKT_ADDR_MASK) ==
(mlc->ipacket[0] & HIL_PKT_ADDR_MASK)) &&
(mlc->ipacket[i] & HIL_PKT_CMD) &&
((mlc->ipacket[i] & HIL_PKT_DATA_MASK) == HIL_CMD_IDD))
break;
}
if (i > 15)
goto bail;
while (++i < 16)
if (mlc->ipacket[i])
break;
if (i < 16)
goto bail;
for (i = 0; i < 16; i++)
mlc->di_scratch.idd[i] =
mlc->ipacket[i] & HIL_PKT_DATA_MASK;
if (mlc->di_scratch.idd[1] & HIL_IDD_HEADER_RSC)
return HILSEN_NEXT;
if (mlc->di_scratch.idd[1] & HIL_IDD_HEADER_EXD)
return HILSEN_DOWN | 4;
return 0;
bail:
mlc->ddi--;
return -1;
}
static int hilse_take_rsc(hil_mlc *mlc, int unused)
{
int i;
for (i = 0; i < 16; i++)
mlc->di_scratch.rsc[i] =
mlc->ipacket[i] & HIL_PKT_DATA_MASK;
if (mlc->di_scratch.idd[1] & HIL_IDD_HEADER_EXD)
return HILSEN_NEXT;
return 0;
}
static int hilse_take_exd(hil_mlc *mlc, int unused)
{
int i;
for (i = 0; i < 16; i++)
mlc->di_scratch.exd[i] =
mlc->ipacket[i] & HIL_PKT_DATA_MASK;
if (mlc->di_scratch.exd[0] & HIL_EXD_HEADER_RNM)
return HILSEN_NEXT;
return 0;
}
static int hilse_take_rnm(hil_mlc *mlc, int unused)
{
int i;
for (i = 0; i < 16; i++)
mlc->di_scratch.rnm[i] =
mlc->ipacket[i] & HIL_PKT_DATA_MASK;
printk(KERN_INFO PREFIX "Device name gotten: %16s\n",
mlc->di_scratch.rnm);
return 0;
}
static int hilse_operate(hil_mlc *mlc, int repoll)
{
if (mlc->opercnt == 0)
hil_mlcs_probe = 0;
mlc->opercnt = 1;
hil_mlc_send_polls(mlc);
if (!hil_mlcs_probe)
return 0;
hil_mlcs_probe = 0;
mlc->opercnt = 0;
return 1;
}
static inline void hilse_setup_input(hil_mlc *mlc, const struct hilse_node *node)
{
switch (node->act) {
case HILSE_EXPECT_DISC:
mlc->imatch = node->object.packet;
mlc->imatch |= ((mlc->ddi + 2) << HIL_PKT_ADDR_SHIFT);
break;
case HILSE_EXPECT_LAST:
mlc->imatch = node->object.packet;
mlc->imatch |= ((mlc->ddi + 1) << HIL_PKT_ADDR_SHIFT);
break;
case HILSE_EXPECT:
mlc->imatch = node->object.packet;
break;
case HILSE_IN:
mlc->imatch = 0;
break;
default:
BUG();
}
mlc->istarted = 1;
mlc->intimeout = node->arg;
do_gettimeofday(&(mlc->instart));
mlc->icount = 15;
memset(mlc->ipacket, 0, 16 * sizeof(hil_packet));
BUG_ON(down_trylock(&mlc->isem));
}
static int hilse_donode(hil_mlc *mlc)
{
const struct hilse_node *node;
int nextidx = 0;
int sched_long = 0;
unsigned long flags;
#ifdef HIL_MLC_DEBUG
if (mlc->seidx && mlc->seidx != seidx &&
mlc->seidx != 41 && mlc->seidx != 42 && mlc->seidx != 43) {
printk(KERN_DEBUG PREFIX "z%i \n {%i}", doze, mlc->seidx);
doze = 0;
}
seidx = mlc->seidx;
#endif
node = hil_mlc_se + mlc->seidx;
switch (node->act) {
int rc;
hil_packet pack;
case HILSE_FUNC:
BUG_ON(node->object.func == NULL);
rc = node->object.func(mlc, node->arg);
nextidx = (rc > 0) ? node->ugly :
((rc < 0) ? node->bad : node->good);
if (nextidx == HILSEN_FOLLOW)
nextidx = rc;
break;
case HILSE_EXPECT_LAST:
case HILSE_EXPECT_DISC:
case HILSE_EXPECT:
case HILSE_IN:
write_lock_irqsave(&mlc->lock, flags);
rc = mlc->in(mlc, node->arg);
if (rc == 2) {
nextidx = HILSEN_DOZE;
sched_long = 1;
write_unlock_irqrestore(&mlc->lock, flags);
break;
}
if (rc == 1)
nextidx = node->ugly;
else if (rc == 0)
nextidx = node->good;
else
nextidx = node->bad;
mlc->istarted = 0;
write_unlock_irqrestore(&mlc->lock, flags);
break;
case HILSE_OUT_LAST:
write_lock_irqsave(&mlc->lock, flags);
pack = node->object.packet;
pack |= ((mlc->ddi + 1) << HIL_PKT_ADDR_SHIFT);
goto out;
case HILSE_OUT_DISC:
write_lock_irqsave(&mlc->lock, flags);
pack = node->object.packet;
pack |= ((mlc->ddi + 2) << HIL_PKT_ADDR_SHIFT);
goto out;
case HILSE_OUT:
write_lock_irqsave(&mlc->lock, flags);
pack = node->object.packet;
out:
if (mlc->istarted)
goto out2;
if ((node + 1)->act & HILSE_IN)
hilse_setup_input(mlc, node + 1);
out2:
write_unlock_irqrestore(&mlc->lock, flags);
if (down_trylock(&mlc->osem)) {
nextidx = HILSEN_DOZE;
break;
}
up(&mlc->osem);
write_lock_irqsave(&mlc->lock, flags);
if (!mlc->ostarted) {
mlc->ostarted = 1;
mlc->opacket = pack;
mlc->out(mlc);
nextidx = HILSEN_DOZE;
write_unlock_irqrestore(&mlc->lock, flags);
break;
}
mlc->ostarted = 0;
do_gettimeofday(&(mlc->instart));
write_unlock_irqrestore(&mlc->lock, flags);
nextidx = HILSEN_NEXT;
break;
case HILSE_CTS:
write_lock_irqsave(&mlc->lock, flags);
nextidx = mlc->cts(mlc) ? node->bad : node->good;
write_unlock_irqrestore(&mlc->lock, flags);
break;
default:
BUG();
}
#ifdef HIL_MLC_DEBUG
if (nextidx == HILSEN_DOZE)
doze++;
#endif
while (nextidx & HILSEN_SCHED) {
struct timeval tv;
if (!sched_long)
goto sched;
do_gettimeofday(&tv);
tv.tv_usec += USEC_PER_SEC * (tv.tv_sec - mlc->instart.tv_sec);
tv.tv_usec -= mlc->instart.tv_usec;
if (tv.tv_usec >= mlc->intimeout) goto sched;
tv.tv_usec = (mlc->intimeout - tv.tv_usec) * HZ / USEC_PER_SEC;
if (!tv.tv_usec) goto sched;
mod_timer(&hil_mlcs_kicker, jiffies + tv.tv_usec);
break;
sched:
tasklet_schedule(&hil_mlcs_tasklet);
break;
}
if (nextidx & HILSEN_DOWN)
mlc->seidx += nextidx & HILSEN_MASK;
else if (nextidx & HILSEN_UP)
mlc->seidx -= nextidx & HILSEN_MASK;
else
mlc->seidx = nextidx & HILSEN_MASK;
if (nextidx & HILSEN_BREAK)
return 1;
return 0;
}
static void hil_mlcs_process(unsigned long unused)
{
struct list_head *tmp;
read_lock(&hil_mlcs_lock);
list_for_each(tmp, &hil_mlcs) {
struct hil_mlc *mlc = list_entry(tmp, hil_mlc, list);
while (hilse_donode(mlc) == 0) {
#ifdef HIL_MLC_DEBUG
if (mlc->seidx != 41 &&
mlc->seidx != 42 &&
mlc->seidx != 43)
printk(KERN_DEBUG PREFIX " + ");
#endif
}
}
read_unlock(&hil_mlcs_lock);
}
static void hil_mlcs_timer(unsigned long data)
{
hil_mlcs_probe = 1;
tasklet_schedule(&hil_mlcs_tasklet);
if (!timer_pending(&hil_mlcs_kicker))
mod_timer(&hil_mlcs_kicker, jiffies + HZ);
}
static int hil_mlc_serio_write(struct serio *serio, unsigned char c)
{
struct hil_mlc_serio_map *map;
struct hil_mlc *mlc;
struct serio_driver *drv;
uint8_t *idx, *last;
map = serio->port_data;
BUG_ON(map == NULL);
mlc = map->mlc;
BUG_ON(mlc == NULL);
mlc->serio_opacket[map->didx] |=
((hil_packet)c) << (8 * (3 - mlc->serio_oidx[map->didx]));
if (mlc->serio_oidx[map->didx] >= 3) {
if (!(mlc->serio_opacket[map->didx] & HIL_PKT_CMD))
return -EIO;
switch (mlc->serio_opacket[map->didx] & HIL_PKT_DATA_MASK) {
case HIL_CMD_IDD:
idx = mlc->di[map->didx].idd;
goto emu;
case HIL_CMD_RSC:
idx = mlc->di[map->didx].rsc;
goto emu;
case HIL_CMD_EXD:
idx = mlc->di[map->didx].exd;
goto emu;
case HIL_CMD_RNM:
idx = mlc->di[map->didx].rnm;
goto emu;
default:
break;
}
mlc->serio_oidx[map->didx] = 0;
mlc->serio_opacket[map->didx] = 0;
}
mlc->serio_oidx[map->didx]++;
return -EIO;
emu:
drv = serio->drv;
BUG_ON(drv == NULL);
last = idx + 15;
while ((last != idx) && (*last == 0))
last--;
while (idx != last) {
drv->interrupt(serio, 0, 0);
drv->interrupt(serio, HIL_ERR_INT >> 16, 0);
drv->interrupt(serio, 0, 0);
drv->interrupt(serio, *idx, 0);
idx++;
}
drv->interrupt(serio, 0, 0);
drv->interrupt(serio, HIL_ERR_INT >> 16, 0);
drv->interrupt(serio, HIL_PKT_CMD >> 8, 0);
drv->interrupt(serio, *idx, 0);
mlc->serio_oidx[map->didx] = 0;
mlc->serio_opacket[map->didx] = 0;
return 0;
}
static int hil_mlc_serio_open(struct serio *serio)
{
struct hil_mlc_serio_map *map;
struct hil_mlc *mlc;
if (serio_get_drvdata(serio) != NULL)
return -EBUSY;
map = serio->port_data;
BUG_ON(map == NULL);
mlc = map->mlc;
BUG_ON(mlc == NULL);
return 0;
}
static void hil_mlc_serio_close(struct serio *serio)
{
struct hil_mlc_serio_map *map;
struct hil_mlc *mlc;
map = serio->port_data;
BUG_ON(map == NULL);
mlc = map->mlc;
BUG_ON(mlc == NULL);
serio_set_drvdata(serio, NULL);
serio->drv = NULL;
}
int hil_mlc_register(hil_mlc *mlc)
{
int i;
unsigned long flags;
BUG_ON(mlc == NULL);
mlc->istarted = 0;
mlc->ostarted = 0;
rwlock_init(&mlc->lock);
sema_init(&mlc->osem, 1);
sema_init(&mlc->isem, 1);
mlc->icount = -1;
mlc->imatch = 0;
mlc->opercnt = 0;
sema_init(&(mlc->csem), 0);
hil_mlc_clear_di_scratch(mlc);
hil_mlc_clear_di_map(mlc, 0);
for (i = 0; i < HIL_MLC_DEVMEM; i++) {
struct serio *mlc_serio;
hil_mlc_copy_di_scratch(mlc, i);
mlc_serio = kzalloc(sizeof(*mlc_serio), GFP_KERNEL);
mlc->serio[i] = mlc_serio;
if (!mlc->serio[i]) {
for (; i >= 0; i--)
kfree(mlc->serio[i]);
return -ENOMEM;
}
snprintf(mlc_serio->name, sizeof(mlc_serio->name)-1, "HIL_SERIO%d", i);
snprintf(mlc_serio->phys, sizeof(mlc_serio->phys)-1, "HIL%d", i);
mlc_serio->id = hil_mlc_serio_id;
mlc_serio->id.id = i;
mlc_serio->write = hil_mlc_serio_write;
mlc_serio->open = hil_mlc_serio_open;
mlc_serio->close = hil_mlc_serio_close;
mlc_serio->port_data = &(mlc->serio_map[i]);
mlc->serio_map[i].mlc = mlc;
mlc->serio_map[i].didx = i;
mlc->serio_map[i].di_revmap = -1;
mlc->serio_opacket[i] = 0;
mlc->serio_oidx[i] = 0;
serio_register_port(mlc_serio);
}
mlc->tasklet = &hil_mlcs_tasklet;
write_lock_irqsave(&hil_mlcs_lock, flags);
list_add_tail(&mlc->list, &hil_mlcs);
mlc->seidx = HILSEN_START;
write_unlock_irqrestore(&hil_mlcs_lock, flags);
tasklet_schedule(&hil_mlcs_tasklet);
return 0;
}
int hil_mlc_unregister(hil_mlc *mlc)
{
struct list_head *tmp;
unsigned long flags;
int i;
BUG_ON(mlc == NULL);
write_lock_irqsave(&hil_mlcs_lock, flags);
list_for_each(tmp, &hil_mlcs)
if (list_entry(tmp, hil_mlc, list) == mlc)
goto found;
write_unlock_irqrestore(&hil_mlcs_lock, flags);
tasklet_schedule(&hil_mlcs_tasklet);
return -ENODEV;
found:
list_del(tmp);
write_unlock_irqrestore(&hil_mlcs_lock, flags);
for (i = 0; i < HIL_MLC_DEVMEM; i++) {
serio_unregister_port(mlc->serio[i]);
mlc->serio[i] = NULL;
}
tasklet_schedule(&hil_mlcs_tasklet);
return 0;
}
static int __init hil_mlc_init(void)
{
setup_timer(&hil_mlcs_kicker, &hil_mlcs_timer, 0);
mod_timer(&hil_mlcs_kicker, jiffies + HZ);
tasklet_enable(&hil_mlcs_tasklet);
return 0;
}
static void __exit hil_mlc_exit(void)
{
del_timer_sync(&hil_mlcs_kicker);
tasklet_disable(&hil_mlcs_tasklet);
tasklet_kill(&hil_mlcs_tasklet);
}
