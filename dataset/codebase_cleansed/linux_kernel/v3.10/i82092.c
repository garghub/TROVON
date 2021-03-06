static int i82092aa_pci_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
unsigned char configbyte;
int i, ret;
enter("i82092aa_pci_probe");
if ((ret = pci_enable_device(dev)))
return ret;
pci_read_config_byte(dev, 0x40, &configbyte);
switch(configbyte&6) {
case 0:
socket_count = 2;
break;
case 2:
socket_count = 1;
break;
case 4:
case 6:
socket_count = 4;
break;
default:
printk(KERN_ERR "i82092aa: Oops, you did something we didn't think of.\n");
ret = -EIO;
goto err_out_disable;
}
printk(KERN_INFO "i82092aa: configured as a %d socket device.\n", socket_count);
if (!request_region(pci_resource_start(dev, 0), 2, "i82092aa")) {
ret = -EBUSY;
goto err_out_disable;
}
for (i = 0;i<socket_count;i++) {
sockets[i].card_state = 1;
sockets[i].io_base = pci_resource_start(dev, 0);
sockets[i].socket.features |= SS_CAP_PCCARD;
sockets[i].socket.map_size = 0x1000;
sockets[i].socket.irq_mask = 0;
sockets[i].socket.pci_irq = dev->irq;
sockets[i].socket.cb_dev = dev;
sockets[i].socket.owner = THIS_MODULE;
sockets[i].number = i;
if (card_present(i)) {
sockets[i].card_state = 3;
dprintk(KERN_DEBUG "i82092aa: slot %i is occupied\n",i);
} else {
dprintk(KERN_DEBUG "i82092aa: slot %i is vacant\n",i);
}
}
configbyte = 0xFF;
pci_write_config_byte(dev, 0x50, configbyte);
dprintk(KERN_DEBUG "Requesting interrupt %i \n",dev->irq);
if ((ret = request_irq(dev->irq, i82092aa_interrupt, IRQF_SHARED, "i82092aa", i82092aa_interrupt))) {
printk(KERN_ERR "i82092aa: Failed to register IRQ %d, aborting\n", dev->irq);
goto err_out_free_res;
}
for (i = 0; i<socket_count; i++) {
sockets[i].socket.dev.parent = &dev->dev;
sockets[i].socket.ops = &i82092aa_operations;
sockets[i].socket.resource_ops = &pccard_nonstatic_ops;
ret = pcmcia_register_socket(&sockets[i].socket);
if (ret) {
goto err_out_free_sockets;
}
}
leave("i82092aa_pci_probe");
return 0;
err_out_free_sockets:
if (i) {
for (i--;i>=0;i--) {
pcmcia_unregister_socket(&sockets[i].socket);
}
}
free_irq(dev->irq, i82092aa_interrupt);
err_out_free_res:
release_region(pci_resource_start(dev, 0), 2);
err_out_disable:
pci_disable_device(dev);
return ret;
}
static void i82092aa_pci_remove(struct pci_dev *dev)
{
int i;
enter("i82092aa_pci_remove");
free_irq(dev->irq, i82092aa_interrupt);
for (i = 0; i < socket_count; i++)
pcmcia_unregister_socket(&sockets[i].socket);
leave("i82092aa_pci_remove");
}
static unsigned char indirect_read(int socket, unsigned short reg)
{
unsigned short int port;
unsigned char val;
unsigned long flags;
spin_lock_irqsave(&port_lock,flags);
reg += socket * 0x40;
port = sockets[socket].io_base;
outb(reg,port);
val = inb(port+1);
spin_unlock_irqrestore(&port_lock,flags);
return val;
}
static void indirect_write(int socket, unsigned short reg, unsigned char value)
{
unsigned short int port;
unsigned long flags;
spin_lock_irqsave(&port_lock,flags);
reg = reg + socket * 0x40;
port = sockets[socket].io_base;
outb(reg,port);
outb(value,port+1);
spin_unlock_irqrestore(&port_lock,flags);
}
static void indirect_setbit(int socket, unsigned short reg, unsigned char mask)
{
unsigned short int port;
unsigned char val;
unsigned long flags;
spin_lock_irqsave(&port_lock,flags);
reg = reg + socket * 0x40;
port = sockets[socket].io_base;
outb(reg,port);
val = inb(port+1);
val |= mask;
outb(reg,port);
outb(val,port+1);
spin_unlock_irqrestore(&port_lock,flags);
}
static void indirect_resetbit(int socket, unsigned short reg, unsigned char mask)
{
unsigned short int port;
unsigned char val;
unsigned long flags;
spin_lock_irqsave(&port_lock,flags);
reg = reg + socket * 0x40;
port = sockets[socket].io_base;
outb(reg,port);
val = inb(port+1);
val &= ~mask;
outb(reg,port);
outb(val,port+1);
spin_unlock_irqrestore(&port_lock,flags);
}
static void indirect_write16(int socket, unsigned short reg, unsigned short value)
{
unsigned short int port;
unsigned char val;
unsigned long flags;
spin_lock_irqsave(&port_lock,flags);
reg = reg + socket * 0x40;
port = sockets[socket].io_base;
outb(reg,port);
val = value & 255;
outb(val,port+1);
reg++;
outb(reg,port);
val = value>>8;
outb(val,port+1);
spin_unlock_irqrestore(&port_lock,flags);
}
static int to_cycles(int ns)
{
if (cycle_time!=0)
return ns/cycle_time;
else
return 0;
}
static irqreturn_t i82092aa_interrupt(int irq, void *dev)
{
int i;
int loopcount = 0;
int handled = 0;
unsigned int events, active=0;
while (1) {
loopcount++;
if (loopcount>20) {
printk(KERN_ERR "i82092aa: infinite eventloop in interrupt \n");
break;
}
active = 0;
for (i=0;i<socket_count;i++) {
int csc;
if (sockets[i].card_state==0)
continue;
csc = indirect_read(i,I365_CSC);
if (csc==0)
continue;
handled = 1;
events = 0;
if (csc & I365_CSC_DETECT) {
events |= SS_DETECT;
printk("Card detected in socket %i!\n",i);
}
if (indirect_read(i,I365_INTCTL) & I365_PC_IOCARD) {
events |= (csc & I365_CSC_STSCHG) ? SS_STSCHG : 0;
} else {
events |= (csc & I365_CSC_BVD1) ? SS_BATDEAD : 0;
events |= (csc & I365_CSC_BVD2) ? SS_BATWARN : 0;
events |= (csc & I365_CSC_READY) ? SS_READY : 0;
}
if (events) {
pcmcia_parse_events(&sockets[i].socket, events);
}
active |= events;
}
if (active==0)
break;
}
return IRQ_RETVAL(handled);
}
static int card_present(int socketno)
{
unsigned int val;
enter("card_present");
if ((socketno<0) || (socketno >= MAX_SOCKETS))
return 0;
if (sockets[socketno].io_base == 0)
return 0;
val = indirect_read(socketno, 1);
if ((val&12)==12) {
leave("card_present 1");
return 1;
}
leave("card_present 0");
return 0;
}
static void set_bridge_state(int sock)
{
enter("set_bridge_state");
indirect_write(sock, I365_GBLCTL,0x00);
indirect_write(sock, I365_GENCTL,0x00);
indirect_setbit(sock, I365_INTCTL,0x08);
leave("set_bridge_state");
}
static int i82092aa_init(struct pcmcia_socket *sock)
{
int i;
struct resource res = { .start = 0, .end = 0x0fff };
pccard_io_map io = { 0, 0, 0, 0, 1 };
pccard_mem_map mem = { .res = &res, };
enter("i82092aa_init");
for (i = 0; i < 2; i++) {
io.map = i;
i82092aa_set_io_map(sock, &io);
}
for (i = 0; i < 5; i++) {
mem.map = i;
i82092aa_set_mem_map(sock, &mem);
}
leave("i82092aa_init");
return 0;
}
static int i82092aa_get_status(struct pcmcia_socket *socket, u_int *value)
{
unsigned int sock = container_of(socket, struct socket_info, socket)->number;
unsigned int status;
enter("i82092aa_get_status");
status = indirect_read(sock,I365_STATUS);
*value = 0;
if ((status & I365_CS_DETECT) == I365_CS_DETECT) {
*value |= SS_DETECT;
}
if (indirect_read(sock, I365_INTCTL) & I365_PC_IOCARD) {
if (!(status & I365_CS_STSCHG))
*value |= SS_STSCHG;
} else {
if (!(status & I365_CS_BVD1))
*value |= SS_BATDEAD;
if (!(status & I365_CS_BVD2))
*value |= SS_BATWARN;
}
if (status & I365_CS_WRPROT)
(*value) |= SS_WRPROT;
if (status & I365_CS_READY)
(*value) |= SS_READY;
if (status & I365_CS_POWERON)
(*value) |= SS_POWERON;
leave("i82092aa_get_status");
return 0;
}
static int i82092aa_set_socket(struct pcmcia_socket *socket, socket_state_t *state)
{
unsigned int sock = container_of(socket, struct socket_info, socket)->number;
unsigned char reg;
enter("i82092aa_set_socket");
set_bridge_state(sock);
reg = 0;
if (!(state->flags & SS_RESET))
reg = reg | I365_PC_RESET;
if (state->flags & SS_IOCARD)
reg = reg | I365_PC_IOCARD;
indirect_write(sock,I365_INTCTL,reg);
reg = I365_PWR_NORESET;
if (state->flags & SS_PWR_AUTO) {
printk("Auto power\n");
reg |= I365_PWR_AUTO;
}
if (state->flags & SS_OUTPUT_ENA) {
printk("Power Enabled \n");
reg |= I365_PWR_OUT;
}
switch (state->Vcc) {
case 0:
break;
case 50:
printk("setting voltage to Vcc to 5V on socket %i\n",sock);
reg |= I365_VCC_5V;
break;
default:
printk("i82092aa: i82092aa_set_socket called with invalid VCC power value: %i ", state->Vcc);
leave("i82092aa_set_socket");
return -EINVAL;
}
switch (state->Vpp) {
case 0:
printk("not setting Vpp on socket %i\n",sock);
break;
case 50:
printk("setting Vpp to 5.0 for socket %i\n",sock);
reg |= I365_VPP1_5V | I365_VPP2_5V;
break;
case 120:
printk("setting Vpp to 12.0\n");
reg |= I365_VPP1_12V | I365_VPP2_12V;
break;
default:
printk("i82092aa: i82092aa_set_socket called with invalid VPP power value: %i ", state->Vcc);
leave("i82092aa_set_socket");
return -EINVAL;
}
if (reg != indirect_read(sock,I365_POWER))
indirect_write(sock,I365_POWER,reg);
reg = 0x00;
if (state->csc_mask & SS_DETECT) {
reg |= I365_CSC_DETECT;
}
if (state->flags & SS_IOCARD) {
if (state->csc_mask & SS_STSCHG)
reg |= I365_CSC_STSCHG;
} else {
if (state->csc_mask & SS_BATDEAD)
reg |= I365_CSC_BVD1;
if (state->csc_mask & SS_BATWARN)
reg |= I365_CSC_BVD2;
if (state->csc_mask & SS_READY)
reg |= I365_CSC_READY;
}
indirect_write(sock,I365_CSCINT,reg);
(void)indirect_read(sock,I365_CSC);
leave("i82092aa_set_socket");
return 0;
}
static int i82092aa_set_io_map(struct pcmcia_socket *socket, struct pccard_io_map *io)
{
unsigned int sock = container_of(socket, struct socket_info, socket)->number;
unsigned char map, ioctl;
enter("i82092aa_set_io_map");
map = io->map;
if (map > 1) {
leave("i82092aa_set_io_map with invalid map");
return -EINVAL;
}
if ((io->start > 0xffff) || (io->stop > 0xffff) || (io->stop < io->start)){
leave("i82092aa_set_io_map with invalid io");
return -EINVAL;
}
if (indirect_read(sock, I365_ADDRWIN) & I365_ENA_IO(map))
indirect_resetbit(sock, I365_ADDRWIN, I365_ENA_IO(map));
indirect_write16(sock,I365_IO(map)+I365_W_START,io->start);
indirect_write16(sock,I365_IO(map)+I365_W_STOP,io->stop);
ioctl = indirect_read(sock,I365_IOCTL) & ~I365_IOCTL_MASK(map);
if (io->flags & (MAP_16BIT|MAP_AUTOSZ))
ioctl |= I365_IOCTL_16BIT(map);
indirect_write(sock,I365_IOCTL,ioctl);
if (io->flags & MAP_ACTIVE)
indirect_setbit(sock,I365_ADDRWIN,I365_ENA_IO(map));
leave("i82092aa_set_io_map");
return 0;
}
static int i82092aa_set_mem_map(struct pcmcia_socket *socket, struct pccard_mem_map *mem)
{
struct socket_info *sock_info = container_of(socket, struct socket_info, socket);
unsigned int sock = sock_info->number;
struct pci_bus_region region;
unsigned short base, i;
unsigned char map;
enter("i82092aa_set_mem_map");
pcibios_resource_to_bus(sock_info->dev, &region, mem->res);
map = mem->map;
if (map > 4) {
leave("i82092aa_set_mem_map: invalid map");
return -EINVAL;
}
if ( (mem->card_start > 0x3ffffff) || (region.start > region.end) ||
(mem->speed > 1000) ) {
leave("i82092aa_set_mem_map: invalid address / speed");
printk("invalid mem map for socket %i: %llx to %llx with a "
"start of %x\n",
sock,
(unsigned long long)region.start,
(unsigned long long)region.end,
mem->card_start);
return -EINVAL;
}
if (indirect_read(sock, I365_ADDRWIN) & I365_ENA_MEM(map))
indirect_resetbit(sock, I365_ADDRWIN, I365_ENA_MEM(map));
base = I365_MEM(map);
i = (region.start >> 12) & 0x0fff;
if (mem->flags & MAP_16BIT)
i |= I365_MEM_16BIT;
if (mem->flags & MAP_0WS)
i |= I365_MEM_0WS;
indirect_write16(sock,base+I365_W_START,i);
i= (region.end >> 12) & 0x0fff;
switch (to_cycles(mem->speed)) {
case 0:
break;
case 1:
i |= I365_MEM_WS0;
break;
case 2:
i |= I365_MEM_WS1;
break;
default:
i |= I365_MEM_WS1 | I365_MEM_WS0;
break;
}
indirect_write16(sock,base+I365_W_STOP,i);
i = ((mem->card_start - region.start) >> 12) & 0x3fff;
if (mem->flags & MAP_WRPROT)
i |= I365_MEM_WRPROT;
if (mem->flags & MAP_ATTRIB) {
i |= I365_MEM_REG;
} else {
}
indirect_write16(sock,base+I365_W_OFF,i);
if (mem->flags & MAP_ACTIVE)
indirect_setbit(sock, I365_ADDRWIN, I365_ENA_MEM(map));
leave("i82092aa_set_mem_map");
return 0;
}
static int i82092aa_module_init(void)
{
return pci_register_driver(&i82092aa_pci_driver);
}
static void i82092aa_module_exit(void)
{
enter("i82092aa_module_exit");
pci_unregister_driver(&i82092aa_pci_driver);
if (sockets[0].io_base>0)
release_region(sockets[0].io_base, 2);
leave("i82092aa_module_exit");
}
