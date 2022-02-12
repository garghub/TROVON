static int
au1x00_pcmcia_skt_state(struct au1000_pcmcia_socket *skt)
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
static int
au1x00_pcmcia_config_skt(struct au1000_pcmcia_socket *skt, socket_state_t *state)
{
int ret;
ret = skt->ops->configure_socket(skt, state);
if (ret == 0) {
skt->cs_state = *state;
}
if (ret < 0)
debug("unable to configure socket %d\n", skt->nr);
return ret;
}
static int au1x00_pcmcia_sock_init(struct pcmcia_socket *sock)
{
struct au1000_pcmcia_socket *skt = to_au1000_socket(sock);
debug("initializing socket %u\n", skt->nr);
skt->ops->socket_init(skt);
return 0;
}
static int au1x00_pcmcia_suspend(struct pcmcia_socket *sock)
{
struct au1000_pcmcia_socket *skt = to_au1000_socket(sock);
debug("suspending socket %u\n", skt->nr);
skt->ops->socket_suspend(skt);
return 0;
}
static void au1x00_check_status(struct au1000_pcmcia_socket *skt)
{
unsigned int events;
debug("entering PCMCIA monitoring thread\n");
do {
unsigned int status;
unsigned long flags;
status = au1x00_pcmcia_skt_state(skt);
spin_lock_irqsave(&status_lock, flags);
events = (status ^ skt->status) & skt->cs_state.csc_mask;
skt->status = status;
spin_unlock_irqrestore(&status_lock, flags);
debug("events: %s%s%s%s%s%s\n",
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
static void au1x00_pcmcia_poll_event(unsigned long dummy)
{
struct au1000_pcmcia_socket *skt = (struct au1000_pcmcia_socket *)dummy;
debug("polling for events\n");
mod_timer(&skt->poll_timer, jiffies + AU1000_PCMCIA_POLL_PERIOD);
au1x00_check_status(skt);
}
static int
au1x00_pcmcia_get_status(struct pcmcia_socket *sock, unsigned int *status)
{
struct au1000_pcmcia_socket *skt = to_au1000_socket(sock);
skt->status = au1x00_pcmcia_skt_state(skt);
*status = skt->status;
return 0;
}
static int
au1x00_pcmcia_set_socket(struct pcmcia_socket *sock, socket_state_t *state)
{
struct au1000_pcmcia_socket *skt = to_au1000_socket(sock);
debug("for sock %u\n", skt->nr);
debug("\tmask: %s%s%s%s%s%s\n\tflags: %s%s%s%s%s%s\n",
(state->csc_mask==0)?"<NONE>":"",
(state->csc_mask&SS_DETECT)?"DETECT ":"",
(state->csc_mask&SS_READY)?"READY ":"",
(state->csc_mask&SS_BATDEAD)?"BATDEAD ":"",
(state->csc_mask&SS_BATWARN)?"BATWARN ":"",
(state->csc_mask&SS_STSCHG)?"STSCHG ":"",
(state->flags==0)?"<NONE>":"",
(state->flags&SS_PWR_AUTO)?"PWR_AUTO ":"",
(state->flags&SS_IOCARD)?"IOCARD ":"",
(state->flags&SS_RESET)?"RESET ":"",
(state->flags&SS_SPKR_ENA)?"SPKR_ENA ":"",
(state->flags&SS_OUTPUT_ENA)?"OUTPUT_ENA ":"");
debug("\tVcc %d Vpp %d irq %d\n",
state->Vcc, state->Vpp, state->io_irq);
return au1x00_pcmcia_config_skt(skt, state);
}
int
au1x00_pcmcia_set_io_map(struct pcmcia_socket *sock, struct pccard_io_map *map)
{
struct au1000_pcmcia_socket *skt = to_au1000_socket(sock);
unsigned int speed;
if(map->map>=MAX_IO_WIN){
debug("map (%d) out of range\n", map->map);
return -1;
}
if(map->flags&MAP_ACTIVE){
speed=(map->speed>0)?map->speed:AU1000_PCMCIA_IO_SPEED;
skt->spd_io[map->map] = speed;
}
map->start=(unsigned int)(u32)skt->virt_io;
map->stop=map->start+MAP_SIZE;
return 0;
}
static int
au1x00_pcmcia_set_mem_map(struct pcmcia_socket *sock, struct pccard_mem_map *map)
{
struct au1000_pcmcia_socket *skt = to_au1000_socket(sock);
unsigned short speed = map->speed;
if(map->map>=MAX_WIN){
debug("map (%d) out of range\n", map->map);
return -1;
}
if (map->flags & MAP_ATTRIB) {
skt->spd_attr[map->map] = speed;
skt->spd_mem[map->map] = 0;
} else {
skt->spd_attr[map->map] = 0;
skt->spd_mem[map->map] = speed;
}
if (map->flags & MAP_ATTRIB) {
map->static_start = skt->phys_attr + map->card_start;
}
else {
map->static_start = skt->phys_mem + map->card_start;
}
debug("set_mem_map %d start %08lx card_start %08x\n",
map->map, map->static_start, map->card_start);
return 0;
}
int au1x00_pcmcia_socket_probe(struct device *dev, struct pcmcia_low_level *ops, int first, int nr)
{
struct skt_dev_info *sinfo;
struct au1000_pcmcia_socket *skt;
int ret, i;
sinfo = kzalloc(sizeof(struct skt_dev_info), GFP_KERNEL);
if (!sinfo) {
ret = -ENOMEM;
goto out;
}
sinfo->nskt = nr;
for (i = 0; i < nr; i++) {
skt = PCMCIA_SOCKET(i);
memset(skt, 0, sizeof(*skt));
skt->socket.resource_ops = &pccard_static_ops;
skt->socket.ops = &au1x00_pcmcia_operations;
skt->socket.owner = ops->owner;
skt->socket.dev.parent = dev;
init_timer(&skt->poll_timer);
skt->poll_timer.function = au1x00_pcmcia_poll_event;
skt->poll_timer.data = (unsigned long)skt;
skt->poll_timer.expires = jiffies + AU1000_PCMCIA_POLL_PERIOD;
skt->nr = first + i;
skt->irq = 255;
skt->dev = dev;
skt->ops = ops;
skt->res_skt.name = skt_names[skt->nr];
skt->res_io.name = "io";
skt->res_io.flags = IORESOURCE_MEM | IORESOURCE_BUSY;
skt->res_mem.name = "memory";
skt->res_mem.flags = IORESOURCE_MEM;
skt->res_attr.name = "attribute";
skt->res_attr.flags = IORESOURCE_MEM;
if (i == 0) {
skt->virt_io = (void *)
(ioremap((phys_t)AU1X_SOCK0_IO, 0x1000) -
(u32)mips_io_port_base);
skt->phys_attr = AU1X_SOCK0_PHYS_ATTR;
skt->phys_mem = AU1X_SOCK0_PHYS_MEM;
}
else {
skt->virt_io = (void *)
(ioremap((phys_t)AU1X_SOCK1_IO, 0x1000) -
(u32)mips_io_port_base);
skt->phys_attr = AU1X_SOCK1_PHYS_ATTR;
skt->phys_mem = AU1X_SOCK1_PHYS_MEM;
}
pcmcia_base_vaddrs[i] = (u32 *)skt->virt_io;
ret = ops->hw_init(skt);
skt->socket.features = SS_CAP_STATIC_MAP|SS_CAP_PCCARD;
skt->socket.irq_mask = 0;
skt->socket.map_size = MAP_SIZE;
skt->socket.pci_irq = skt->irq;
skt->socket.io_offset = (unsigned long)skt->virt_io;
skt->status = au1x00_pcmcia_skt_state(skt);
ret = pcmcia_register_socket(&skt->socket);
if (ret)
goto out_err;
WARN_ON(skt->socket.sock != i);
add_timer(&skt->poll_timer);
}
dev_set_drvdata(dev, sinfo);
return 0;
out_err:
ops->hw_shutdown(skt);
while (i-- > 0) {
skt = PCMCIA_SOCKET(i);
del_timer_sync(&skt->poll_timer);
pcmcia_unregister_socket(&skt->socket);
if (i == 0) {
iounmap(skt->virt_io + (u32)mips_io_port_base);
skt->virt_io = NULL;
}
#ifndef CONFIG_MIPS_XXS1500
else {
iounmap(skt->virt_io + (u32)mips_io_port_base);
skt->virt_io = NULL;
}
#endif
ops->hw_shutdown(skt);
}
kfree(sinfo);
out:
return ret;
}
int au1x00_drv_pcmcia_remove(struct platform_device *dev)
{
struct skt_dev_info *sinfo = platform_get_drvdata(dev);
int i;
mutex_lock(&pcmcia_sockets_lock);
platform_set_drvdata(dev, NULL);
for (i = 0; i < sinfo->nskt; i++) {
struct au1000_pcmcia_socket *skt = PCMCIA_SOCKET(i);
del_timer_sync(&skt->poll_timer);
pcmcia_unregister_socket(&skt->socket);
skt->ops->hw_shutdown(skt);
au1x00_pcmcia_config_skt(skt, &dead_socket);
iounmap(skt->virt_io + (u32)mips_io_port_base);
skt->virt_io = NULL;
}
kfree(sinfo);
mutex_unlock(&pcmcia_sockets_lock);
return 0;
}
static int au1x00_drv_pcmcia_probe(struct platform_device *dev)
{
int i, ret = -ENODEV;
mutex_lock(&pcmcia_sockets_lock);
for (i=0; i < ARRAY_SIZE(au1x00_pcmcia_hw_init); i++) {
ret = au1x00_pcmcia_hw_init[i](&dev->dev);
if (ret == 0)
break;
}
mutex_unlock(&pcmcia_sockets_lock);
return ret;
}
static int __init au1x00_pcmcia_init(void)
{
int error = 0;
error = platform_driver_register(&au1x00_pcmcia_driver);
return error;
}
static void __exit au1x00_pcmcia_exit(void)
{
platform_driver_unregister(&au1x00_pcmcia_driver);
}
