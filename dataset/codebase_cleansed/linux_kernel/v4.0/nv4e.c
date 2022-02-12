static void
nv4e_i2c_drive_scl(struct nvkm_i2c_port *base, int state)
{
struct nv4e_i2c_priv *priv = (void *)nvkm_i2c(base);
struct nv4e_i2c_port *port = (void *)base;
nv_mask(priv, port->addr, 0x2f, state ? 0x21 : 0x01);
}
static void
nv4e_i2c_drive_sda(struct nvkm_i2c_port *base, int state)
{
struct nv4e_i2c_priv *priv = (void *)nvkm_i2c(base);
struct nv4e_i2c_port *port = (void *)base;
nv_mask(priv, port->addr, 0x1f, state ? 0x11 : 0x01);
}
static int
nv4e_i2c_sense_scl(struct nvkm_i2c_port *base)
{
struct nv4e_i2c_priv *priv = (void *)nvkm_i2c(base);
struct nv4e_i2c_port *port = (void *)base;
return !!(nv_rd32(priv, port->addr) & 0x00040000);
}
static int
nv4e_i2c_sense_sda(struct nvkm_i2c_port *base)
{
struct nv4e_i2c_priv *priv = (void *)nvkm_i2c(base);
struct nv4e_i2c_port *port = (void *)base;
return !!(nv_rd32(priv, port->addr) & 0x00080000);
}
static int
nv4e_i2c_port_ctor(struct nvkm_object *parent, struct nvkm_object *engine,
struct nvkm_oclass *oclass, void *data, u32 index,
struct nvkm_object **pobject)
{
struct dcb_i2c_entry *info = data;
struct nv4e_i2c_port *port;
int ret;
ret = nvkm_i2c_port_create(parent, engine, oclass, index,
&nvkm_i2c_bit_algo, &nv4e_i2c_func, &port);
*pobject = nv_object(port);
if (ret)
return ret;
port->addr = 0x600800 + info->drive;
return 0;
}
