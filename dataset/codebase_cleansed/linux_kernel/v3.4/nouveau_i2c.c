static void
i2c_drive_scl(void *data, int state)
{
struct nouveau_i2c_chan *port = data;
if (port->type == 0) {
u8 val = NVReadVgaCrtc(port->dev, 0, port->drive);
if (state) val |= 0x20;
else val &= 0xdf;
NVWriteVgaCrtc(port->dev, 0, port->drive, val | 0x01);
} else
if (port->type == 4) {
nv_mask(port->dev, port->drive, 0x2f, state ? 0x21 : 0x01);
} else
if (port->type == 5) {
if (state) port->state |= 0x01;
else port->state &= 0xfe;
nv_wr32(port->dev, port->drive, 4 | port->state);
}
}
static void
i2c_drive_sda(void *data, int state)
{
struct nouveau_i2c_chan *port = data;
if (port->type == 0) {
u8 val = NVReadVgaCrtc(port->dev, 0, port->drive);
if (state) val |= 0x10;
else val &= 0xef;
NVWriteVgaCrtc(port->dev, 0, port->drive, val | 0x01);
} else
if (port->type == 4) {
nv_mask(port->dev, port->drive, 0x1f, state ? 0x11 : 0x01);
} else
if (port->type == 5) {
if (state) port->state |= 0x02;
else port->state &= 0xfd;
nv_wr32(port->dev, port->drive, 4 | port->state);
}
}
static int
i2c_sense_scl(void *data)
{
struct nouveau_i2c_chan *port = data;
struct drm_nouveau_private *dev_priv = port->dev->dev_private;
if (port->type == 0) {
return !!(NVReadVgaCrtc(port->dev, 0, port->sense) & 0x04);
} else
if (port->type == 4) {
return !!(nv_rd32(port->dev, port->sense) & 0x00040000);
} else
if (port->type == 5) {
if (dev_priv->card_type < NV_D0)
return !!(nv_rd32(port->dev, port->sense) & 0x01);
else
return !!(nv_rd32(port->dev, port->sense) & 0x10);
}
return 0;
}
static int
i2c_sense_sda(void *data)
{
struct nouveau_i2c_chan *port = data;
struct drm_nouveau_private *dev_priv = port->dev->dev_private;
if (port->type == 0) {
return !!(NVReadVgaCrtc(port->dev, 0, port->sense) & 0x08);
} else
if (port->type == 4) {
return !!(nv_rd32(port->dev, port->sense) & 0x00080000);
} else
if (port->type == 5) {
if (dev_priv->card_type < NV_D0)
return !!(nv_rd32(port->dev, port->sense) & 0x02);
else
return !!(nv_rd32(port->dev, port->sense) & 0x20);
}
return 0;
}
static u8 *
i2c_table(struct drm_device *dev, u8 *version)
{
u8 *dcb = dcb_table(dev), *i2c = NULL;
if (dcb) {
if (dcb[0] >= 0x15)
i2c = ROMPTR(dev, dcb[2]);
if (dcb[0] >= 0x30)
i2c = ROMPTR(dev, dcb[4]);
}
if (i2c) {
*version = dcb[0];
if (*version >= 0x30)
*version = i2c[0];
}
return i2c;
}
int
nouveau_i2c_init(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
struct nouveau_i2c_chan *port;
u8 version = 0x00, entries, recordlen;
u8 *i2c, *entry, legacy[2][4] = {};
int ret, i;
INIT_LIST_HEAD(&dev_priv->i2c_ports);
i2c = i2c_table(dev, &version);
if (!i2c) {
u8 *bmp = &bios->data[bios->offset];
if (bios->type != NVBIOS_BMP)
return -ENODEV;
legacy[0][0] = NV_CIO_CRE_DDC_WR__INDEX;
legacy[0][1] = NV_CIO_CRE_DDC_STATUS__INDEX;
legacy[1][0] = NV_CIO_CRE_DDC0_WR__INDEX;
legacy[1][1] = NV_CIO_CRE_DDC0_STATUS__INDEX;
if (bmp[5] < 4)
i2c = &bios->data[0x48];
else
i2c = &bmp[0x36];
if (i2c[4]) legacy[0][0] = i2c[4];
if (i2c[5]) legacy[0][1] = i2c[5];
if (i2c[6]) legacy[1][0] = i2c[6];
if (i2c[7]) legacy[1][1] = i2c[7];
}
if (version >= 0x30) {
entry = i2c[1] + i2c;
entries = i2c[2];
recordlen = i2c[3];
} else
if (version) {
entry = i2c;
entries = 16;
recordlen = 4;
} else {
entry = legacy[0];
entries = 2;
recordlen = 4;
}
for (i = 0; i < entries; i++, entry += recordlen) {
port = kzalloc(sizeof(*port), GFP_KERNEL);
if (port == NULL) {
nouveau_i2c_fini(dev);
return -ENOMEM;
}
port->type = entry[3];
if (version < 0x30) {
port->type &= 0x07;
if (port->type == 0x07)
port->type = 0xff;
}
if (port->type == 0xff) {
kfree(port);
continue;
}
switch (port->type) {
case 0:
port->drive = entry[0];
port->sense = entry[1];
break;
case 4:
port->drive = 0x600800 + entry[1];
port->sense = port->drive;
break;
case 5:
port->drive = entry[0] & 0x0f;
if (dev_priv->card_type < NV_D0) {
if (port->drive >= ARRAY_SIZE(nv50_i2c_port))
break;
port->drive = nv50_i2c_port[port->drive];
port->sense = port->drive;
} else {
port->drive = 0x00d014 + (port->drive * 0x20);
port->sense = port->drive;
}
break;
case 6:
port->drive = entry[0];
port->sense = port->drive;
port->adapter.algo = &nouveau_dp_i2c_algo;
break;
default:
break;
}
if (!port->adapter.algo && !port->drive) {
NV_ERROR(dev, "I2C%d: type %d index %x/%x unknown\n",
i, port->type, port->drive, port->sense);
kfree(port);
continue;
}
snprintf(port->adapter.name, sizeof(port->adapter.name),
"nouveau-%s-%d", pci_name(dev->pdev), i);
port->adapter.owner = THIS_MODULE;
port->adapter.dev.parent = &dev->pdev->dev;
port->dev = dev;
port->index = i;
port->dcb = ROM32(entry[0]);
i2c_set_adapdata(&port->adapter, i2c);
if (port->adapter.algo != &nouveau_dp_i2c_algo) {
port->adapter.algo_data = &port->bit;
port->bit.udelay = 10;
port->bit.timeout = usecs_to_jiffies(2200);
port->bit.data = port;
port->bit.setsda = i2c_drive_sda;
port->bit.setscl = i2c_drive_scl;
port->bit.getsda = i2c_sense_sda;
port->bit.getscl = i2c_sense_scl;
i2c_drive_scl(port, 0);
i2c_drive_sda(port, 1);
i2c_drive_scl(port, 1);
ret = i2c_bit_add_bus(&port->adapter);
} else {
port->adapter.algo = &nouveau_dp_i2c_algo;
ret = i2c_add_adapter(&port->adapter);
}
if (ret) {
NV_ERROR(dev, "I2C%d: failed register: %d\n", i, ret);
kfree(port);
continue;
}
list_add_tail(&port->head, &dev_priv->i2c_ports);
}
return 0;
}
void
nouveau_i2c_fini(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_i2c_chan *port, *tmp;
list_for_each_entry_safe(port, tmp, &dev_priv->i2c_ports, head) {
i2c_del_adapter(&port->adapter);
kfree(port);
}
}
struct nouveau_i2c_chan *
nouveau_i2c_find(struct drm_device *dev, u8 index)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_i2c_chan *port;
if (index == NV_I2C_DEFAULT(0) ||
index == NV_I2C_DEFAULT(1)) {
u8 version, *i2c = i2c_table(dev, &version);
if (i2c && version >= 0x30) {
if (index == NV_I2C_DEFAULT(0))
index = (i2c[4] & 0x0f);
else
index = (i2c[4] & 0xf0) >> 4;
} else {
index = 2;
}
}
list_for_each_entry(port, &dev_priv->i2c_ports, head) {
if (port->index == index)
break;
}
if (&port->head == &dev_priv->i2c_ports)
return NULL;
if (dev_priv->card_type >= NV_50 && (port->dcb & 0x00000100)) {
u32 reg = 0x00e500, val;
if (port->type == 6) {
reg += port->drive * 0x50;
val = 0x2002;
} else {
reg += ((port->dcb & 0x1e00) >> 9) * 0x50;
val = 0xe001;
}
nv_mask(dev, reg + 0x0c, 0x00000001, 0x00000000);
nv_mask(dev, reg + 0x00, 0x0000f003, val);
}
return port;
}
bool
nouveau_probe_i2c_addr(struct nouveau_i2c_chan *i2c, int addr)
{
uint8_t buf[] = { 0 };
struct i2c_msg msgs[] = {
{
.addr = addr,
.flags = 0,
.len = 1,
.buf = buf,
},
{
.addr = addr,
.flags = I2C_M_RD,
.len = 1,
.buf = buf,
}
};
return i2c_transfer(&i2c->adapter, msgs, 2) == 2;
}
int
nouveau_i2c_identify(struct drm_device *dev, const char *what,
struct i2c_board_info *info,
bool (*match)(struct nouveau_i2c_chan *,
struct i2c_board_info *),
int index)
{
struct nouveau_i2c_chan *i2c = nouveau_i2c_find(dev, index);
int i;
if (!i2c) {
NV_DEBUG(dev, "No bus when probing %s on %d\n", what, index);
return -ENODEV;
}
NV_DEBUG(dev, "Probing %ss on I2C bus: %d\n", what, i2c->index);
for (i = 0; info[i].addr; i++) {
if (nouveau_probe_i2c_addr(i2c, info[i].addr) &&
(!match || match(i2c, &info[i]))) {
NV_INFO(dev, "Detected %s: %s\n", what, info[i].type);
return i;
}
}
NV_DEBUG(dev, "No devices found.\n");
return -ENODEV;
}
