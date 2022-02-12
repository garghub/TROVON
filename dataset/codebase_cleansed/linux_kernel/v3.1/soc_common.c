void soc_pcmcia_debug(struct soc_pcmcia_socket *skt, const char *func,
int lvl, const char *fmt, ...)
{
struct va_format vaf;
va_list args;
if (pc_debug > lvl) {
va_start(args, fmt);
vaf.fmt = fmt;
vaf.va = &args;
printk(KERN_DEBUG "skt%u: %s: %pV", skt->nr, func, &vaf);
va_end(args);
}
}
static unsigned short
calc_speed(unsigned short *spds, int num, unsigned short dflt)
{
unsigned short speed = 0;
int i;
for (i = 0; i < num; i++)
if (speed < spds[i])
speed = spds[i];
if (speed == 0)
speed = dflt;
return speed;
}
void soc_common_pcmcia_get_timing(struct soc_pcmcia_socket *skt,
struct soc_pcmcia_timing *timing)
{
timing->io =
calc_speed(skt->spd_io, MAX_IO_WIN, SOC_PCMCIA_IO_ACCESS);
timing->mem =
calc_speed(skt->spd_mem, MAX_WIN, SOC_PCMCIA_3V_MEM_ACCESS);
timing->attr =
calc_speed(skt->spd_attr, MAX_WIN, SOC_PCMCIA_3V_MEM_ACCESS);
}
static unsigned int soc_common_pcmcia_skt_state(struct soc_pcmcia_socket *skt)
{
struct pcmcia_state state;
unsigned int stat;
memset(&state, 0, sizeof(struct pcmcia_state));
skt->ops->socket_state(skt, &state);
stat = state.detect ? SS_DETECT : 0;
stat |= state.ready ? SS_READY : 0;
stat |= state.wrprot ? SS_WRPROT : 0;
stat |= state.vs_3v ? SS_3VCARD : 0;
stat |= state.vs_Xv ? SS_XVCARD : 0;
stat |= skt->cs_state.Vcc ? SS_POWERON : 0;
if (skt->cs_state.flags & SS_IOCARD)
stat |= state.bvd1 ? SS_STSCHG : 0;
else {
if (state.bvd1 == 0)
stat |= SS_BATDEAD;
else if (state.bvd2 == 0)
stat |= SS_BATWARN;
}
return stat;
}
static int soc_common_pcmcia_config_skt(
struct soc_pcmcia_socket *skt, socket_state_t *state)
{
int ret;
ret = skt->ops->configure_socket(skt, state);
if (ret == 0) {
if (skt->irq_state != 1 && state->io_irq) {
skt->irq_state = 1;
irq_set_irq_type(skt->socket.pci_irq,
IRQ_TYPE_EDGE_FALLING);
} else if (skt->irq_state == 1 && state->io_irq == 0) {
skt->irq_state = 0;
irq_set_irq_type(skt->socket.pci_irq, IRQ_TYPE_NONE);
}
skt->cs_state = *state;
}
if (ret < 0)
printk(KERN_ERR "soc_common_pcmcia: unable to configure "
"socket %d\n", skt->nr);
return ret;
}
static int soc_common_pcmcia_sock_init(struct pcmcia_socket *sock)
{
struct soc_pcmcia_socket *skt = to_soc_pcmcia_socket(sock);
debug(skt, 2, "initializing socket\n");
if (skt->ops->socket_init)
skt->ops->socket_init(skt);
return 0;
}
static int soc_common_pcmcia_suspend(struct pcmcia_socket *sock)
{
struct soc_pcmcia_socket *skt = to_soc_pcmcia_socket(sock);
debug(skt, 2, "suspending socket\n");
if (skt->ops->socket_suspend)
skt->ops->socket_suspend(skt);
return 0;
}
static void soc_common_check_status(struct soc_pcmcia_socket *skt)
{
unsigned int events;
debug(skt, 4, "entering PCMCIA monitoring thread\n");
do {
unsigned int status;
unsigned long flags;
status = soc_common_pcmcia_skt_state(skt);
spin_lock_irqsave(&status_lock, flags);
events = (status ^ skt->status) & skt->cs_state.csc_mask;
skt->status = status;
spin_unlock_irqrestore(&status_lock, flags);
debug(skt, 4, "events: %s%s%s%s%s%s\n",
events == 0 ? "<NONE>" : "",
events & SS_DETECT ? "DETECT " : "",
events & SS_READY ? "READY " : "",
events & SS_BATDEAD ? "BATDEAD " : "",
events & SS_BATWARN ? "BATWARN " : "",
events & SS_STSCHG ? "STSCHG " : "");
if (events)
pcmcia_parse_events(&skt->socket, events);
} while (events);
}
static void soc_common_pcmcia_poll_event(unsigned long dummy)
{
struct soc_pcmcia_socket *skt = (struct soc_pcmcia_socket *)dummy;
debug(skt, 4, "polling for events\n");
mod_timer(&skt->poll_timer, jiffies + SOC_PCMCIA_POLL_PERIOD);
soc_common_check_status(skt);
}
static irqreturn_t soc_common_pcmcia_interrupt(int irq, void *dev)
{
struct soc_pcmcia_socket *skt = dev;
debug(skt, 3, "servicing IRQ %d\n", irq);
soc_common_check_status(skt);
return IRQ_HANDLED;
}
static int
soc_common_pcmcia_get_status(struct pcmcia_socket *sock, unsigned int *status)
{
struct soc_pcmcia_socket *skt = to_soc_pcmcia_socket(sock);
skt->status = soc_common_pcmcia_skt_state(skt);
*status = skt->status;
return 0;
}
static int soc_common_pcmcia_set_socket(
struct pcmcia_socket *sock, socket_state_t *state)
{
struct soc_pcmcia_socket *skt = to_soc_pcmcia_socket(sock);
debug(skt, 2, "mask: %s%s%s%s%s%s flags: %s%s%s%s%s%s Vcc %d Vpp %d irq %d\n",
(state->csc_mask == 0) ? "<NONE> " : "",
(state->csc_mask & SS_DETECT) ? "DETECT " : "",
(state->csc_mask & SS_READY) ? "READY " : "",
(state->csc_mask & SS_BATDEAD) ? "BATDEAD " : "",
(state->csc_mask & SS_BATWARN) ? "BATWARN " : "",
(state->csc_mask & SS_STSCHG) ? "STSCHG " : "",
(state->flags == 0) ? "<NONE> " : "",
(state->flags & SS_PWR_AUTO) ? "PWR_AUTO " : "",
(state->flags & SS_IOCARD) ? "IOCARD " : "",
(state->flags & SS_RESET) ? "RESET " : "",
(state->flags & SS_SPKR_ENA) ? "SPKR_ENA " : "",
(state->flags & SS_OUTPUT_ENA) ? "OUTPUT_ENA " : "",
state->Vcc, state->Vpp, state->io_irq);
return soc_common_pcmcia_config_skt(skt, state);
}
static int soc_common_pcmcia_set_io_map(
struct pcmcia_socket *sock, struct pccard_io_map *map)
{
struct soc_pcmcia_socket *skt = to_soc_pcmcia_socket(sock);
unsigned short speed = map->speed;
debug(skt, 2, "map %u speed %u start 0x%08llx stop 0x%08llx\n",
map->map, map->speed, (unsigned long long)map->start,
(unsigned long long)map->stop);
debug(skt, 2, "flags: %s%s%s%s%s%s%s%s\n",
(map->flags == 0) ? "<NONE>" : "",
(map->flags & MAP_ACTIVE) ? "ACTIVE " : "",
(map->flags & MAP_16BIT) ? "16BIT " : "",
(map->flags & MAP_AUTOSZ) ? "AUTOSZ " : "",
(map->flags & MAP_0WS) ? "0WS " : "",
(map->flags & MAP_WRPROT) ? "WRPROT " : "",
(map->flags & MAP_USE_WAIT) ? "USE_WAIT " : "",
(map->flags & MAP_PREFETCH) ? "PREFETCH " : "");
if (map->map >= MAX_IO_WIN) {
printk(KERN_ERR "%s(): map (%d) out of range\n", __func__,
map->map);
return -1;
}
if (map->flags & MAP_ACTIVE) {
if (speed == 0)
speed = SOC_PCMCIA_IO_ACCESS;
} else {
speed = 0;
}
skt->spd_io[map->map] = speed;
skt->ops->set_timing(skt);
if (map->stop == 1)
map->stop = PAGE_SIZE-1;
map->stop -= map->start;
map->stop += skt->socket.io_offset;
map->start = skt->socket.io_offset;
return 0;
}
static int soc_common_pcmcia_set_mem_map(
struct pcmcia_socket *sock, struct pccard_mem_map *map)
{
struct soc_pcmcia_socket *skt = to_soc_pcmcia_socket(sock);
struct resource *res;
unsigned short speed = map->speed;
debug(skt, 2, "map %u speed %u card_start %08x\n",
map->map, map->speed, map->card_start);
debug(skt, 2, "flags: %s%s%s%s%s%s%s%s\n",
(map->flags == 0) ? "<NONE>" : "",
(map->flags & MAP_ACTIVE) ? "ACTIVE " : "",
(map->flags & MAP_16BIT) ? "16BIT " : "",
(map->flags & MAP_AUTOSZ) ? "AUTOSZ " : "",
(map->flags & MAP_0WS) ? "0WS " : "",
(map->flags & MAP_WRPROT) ? "WRPROT " : "",
(map->flags & MAP_ATTRIB) ? "ATTRIB " : "",
(map->flags & MAP_USE_WAIT) ? "USE_WAIT " : "");
if (map->map >= MAX_WIN)
return -EINVAL;
if (map->flags & MAP_ACTIVE) {
if (speed == 0)
speed = 300;
} else {
speed = 0;
}
if (map->flags & MAP_ATTRIB) {
res = &skt->res_attr;
skt->spd_attr[map->map] = speed;
skt->spd_mem[map->map] = 0;
} else {
res = &skt->res_mem;
skt->spd_attr[map->map] = 0;
skt->spd_mem[map->map] = speed;
}
skt->ops->set_timing(skt);
map->static_start = res->start + map->card_start;
return 0;
}
static void dump_bits(char **p, const char *prefix,
unsigned int val, struct bittbl *bits, int sz)
{
char *b = *p;
int i;
b += sprintf(b, "%-9s:", prefix);
for (i = 0; i < sz; i++)
if (val & bits[i].mask)
b += sprintf(b, " %s", bits[i].name);
*b++ = '\n';
*p = b;
}
static ssize_t show_status(
struct device *dev, struct device_attribute *attr, char *buf)
{
struct soc_pcmcia_socket *skt =
container_of(dev, struct soc_pcmcia_socket, socket.dev);
char *p = buf;
p += sprintf(p, "slot : %d\n", skt->nr);
dump_bits(&p, "status", skt->status,
status_bits, ARRAY_SIZE(status_bits));
dump_bits(&p, "csc_mask", skt->cs_state.csc_mask,
status_bits, ARRAY_SIZE(status_bits));
dump_bits(&p, "cs_flags", skt->cs_state.flags,
conf_bits, ARRAY_SIZE(conf_bits));
p += sprintf(p, "Vcc : %d\n", skt->cs_state.Vcc);
p += sprintf(p, "Vpp : %d\n", skt->cs_state.Vpp);
p += sprintf(p, "IRQ : %d (%d)\n", skt->cs_state.io_irq,
skt->socket.pci_irq);
if (skt->ops->show_timing)
p += skt->ops->show_timing(skt, p);
return p-buf;
}
int soc_pcmcia_request_irqs(struct soc_pcmcia_socket *skt,
struct pcmcia_irqs *irqs, int nr)
{
int i, res = 0;
for (i = 0; i < nr; i++) {
if (irqs[i].sock != skt->nr)
continue;
res = request_irq(irqs[i].irq, soc_common_pcmcia_interrupt,
IRQF_DISABLED, irqs[i].str, skt);
if (res)
break;
irq_set_irq_type(irqs[i].irq, IRQ_TYPE_NONE);
}
if (res) {
printk(KERN_ERR "PCMCIA: request for IRQ%d failed (%d)\n",
irqs[i].irq, res);
while (i--)
if (irqs[i].sock == skt->nr)
free_irq(irqs[i].irq, skt);
}
return res;
}
void soc_pcmcia_free_irqs(struct soc_pcmcia_socket *skt,
struct pcmcia_irqs *irqs, int nr)
{
int i;
for (i = 0; i < nr; i++)
if (irqs[i].sock == skt->nr)
free_irq(irqs[i].irq, skt);
}
void soc_pcmcia_disable_irqs(struct soc_pcmcia_socket *skt,
struct pcmcia_irqs *irqs, int nr)
{
int i;
for (i = 0; i < nr; i++)
if (irqs[i].sock == skt->nr)
irq_set_irq_type(irqs[i].irq, IRQ_TYPE_NONE);
}
void soc_pcmcia_enable_irqs(struct soc_pcmcia_socket *skt,
struct pcmcia_irqs *irqs, int nr)
{
int i;
for (i = 0; i < nr; i++)
if (irqs[i].sock == skt->nr) {
irq_set_irq_type(irqs[i].irq, IRQ_TYPE_EDGE_RISING);
irq_set_irq_type(irqs[i].irq, IRQ_TYPE_EDGE_BOTH);
}
}
static int
soc_pcmcia_notifier(struct notifier_block *nb, unsigned long val, void *data)
{
struct soc_pcmcia_socket *skt;
struct cpufreq_freqs *freqs = data;
int ret = 0;
mutex_lock(&soc_pcmcia_sockets_lock);
list_for_each_entry(skt, &soc_pcmcia_sockets, node)
if (skt->ops->frequency_change)
ret += skt->ops->frequency_change(skt, val, freqs);
mutex_unlock(&soc_pcmcia_sockets_lock);
return ret;
}
static int soc_pcmcia_cpufreq_register(void)
{
int ret;
ret = cpufreq_register_notifier(&soc_pcmcia_notifier_block,
CPUFREQ_TRANSITION_NOTIFIER);
if (ret < 0)
printk(KERN_ERR "Unable to register CPU frequency change "
"notifier for PCMCIA (%d)\n", ret);
return ret;
}
static void soc_pcmcia_cpufreq_unregister(void)
{
cpufreq_unregister_notifier(&soc_pcmcia_notifier_block,
CPUFREQ_TRANSITION_NOTIFIER);
}
void soc_pcmcia_remove_one(struct soc_pcmcia_socket *skt)
{
mutex_lock(&soc_pcmcia_sockets_lock);
del_timer_sync(&skt->poll_timer);
pcmcia_unregister_socket(&skt->socket);
skt->ops->hw_shutdown(skt);
soc_common_pcmcia_config_skt(skt, &dead_socket);
list_del(&skt->node);
mutex_unlock(&soc_pcmcia_sockets_lock);
iounmap(skt->virt_io);
skt->virt_io = NULL;
release_resource(&skt->res_attr);
release_resource(&skt->res_mem);
release_resource(&skt->res_io);
release_resource(&skt->res_skt);
}
int soc_pcmcia_add_one(struct soc_pcmcia_socket *skt)
{
int ret;
init_timer(&skt->poll_timer);
skt->poll_timer.function = soc_common_pcmcia_poll_event;
skt->poll_timer.data = (unsigned long)skt;
skt->poll_timer.expires = jiffies + SOC_PCMCIA_POLL_PERIOD;
ret = request_resource(&iomem_resource, &skt->res_skt);
if (ret)
goto out_err_1;
ret = request_resource(&skt->res_skt, &skt->res_io);
if (ret)
goto out_err_2;
ret = request_resource(&skt->res_skt, &skt->res_mem);
if (ret)
goto out_err_3;
ret = request_resource(&skt->res_skt, &skt->res_attr);
if (ret)
goto out_err_4;
skt->virt_io = ioremap(skt->res_io.start, 0x10000);
if (skt->virt_io == NULL) {
ret = -ENOMEM;
goto out_err_5;
}
mutex_lock(&soc_pcmcia_sockets_lock);
list_add(&skt->node, &soc_pcmcia_sockets);
skt->ops->set_timing(skt);
ret = skt->ops->hw_init(skt);
if (ret)
goto out_err_6;
skt->socket.ops = &soc_common_pcmcia_operations;
skt->socket.features = SS_CAP_STATIC_MAP|SS_CAP_PCCARD;
skt->socket.resource_ops = &pccard_static_ops;
skt->socket.irq_mask = 0;
skt->socket.map_size = PAGE_SIZE;
skt->socket.io_offset = (unsigned long)skt->virt_io;
skt->status = soc_common_pcmcia_skt_state(skt);
ret = pcmcia_register_socket(&skt->socket);
if (ret)
goto out_err_7;
add_timer(&skt->poll_timer);
mutex_unlock(&soc_pcmcia_sockets_lock);
ret = device_create_file(&skt->socket.dev, &dev_attr_status);
if (ret)
goto out_err_8;
return ret;
out_err_8:
mutex_lock(&soc_pcmcia_sockets_lock);
del_timer_sync(&skt->poll_timer);
pcmcia_unregister_socket(&skt->socket);
out_err_7:
skt->ops->hw_shutdown(skt);
out_err_6:
list_del(&skt->node);
mutex_unlock(&soc_pcmcia_sockets_lock);
iounmap(skt->virt_io);
out_err_5:
release_resource(&skt->res_attr);
out_err_4:
release_resource(&skt->res_mem);
out_err_3:
release_resource(&skt->res_io);
out_err_2:
release_resource(&skt->res_skt);
out_err_1:
return ret;
}
