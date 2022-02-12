int
_nvkm_output_fini(struct nvkm_object *object, bool suspend)
{
struct nvkm_output *outp = (void *)object;
nv_ofuncs(outp->conn)->fini(nv_object(outp->conn), suspend);
return nvkm_object_fini(&outp->base, suspend);
}
int
_nvkm_output_init(struct nvkm_object *object)
{
struct nvkm_output *outp = (void *)object;
int ret = nvkm_object_init(&outp->base);
if (ret == 0)
nv_ofuncs(outp->conn)->init(nv_object(outp->conn));
return 0;
}
void
_nvkm_output_dtor(struct nvkm_object *object)
{
struct nvkm_output *outp = (void *)object;
list_del(&outp->head);
nvkm_object_ref(NULL, (void *)&outp->conn);
nvkm_object_destroy(&outp->base);
}
int
nvkm_output_create_(struct nvkm_object *parent,
struct nvkm_object *engine,
struct nvkm_oclass *oclass,
struct dcb_output *dcbE, int index,
int length, void **pobject)
{
struct nvkm_disp *disp = nvkm_disp(parent);
struct nvkm_bios *bios = nvkm_bios(parent);
struct nvkm_i2c *i2c = nvkm_i2c(parent);
struct nvbios_connE connE;
struct nvkm_output *outp;
u8 ver, hdr;
u32 data;
int ret;
ret = nvkm_object_create_(parent, engine, oclass, 0, length, pobject);
outp = *pobject;
if (ret)
return ret;
outp->info = *dcbE;
outp->index = index;
outp->or = ffs(outp->info.or) - 1;
DBG("type %02x loc %d or %d link %d con %x edid %x bus %d head %x\n",
dcbE->type, dcbE->location, dcbE->or, dcbE->type >= 2 ?
dcbE->sorconf.link : 0, dcbE->connector, dcbE->i2c_index,
dcbE->bus, dcbE->heads);
if (outp->info.type != DCB_OUTPUT_DP)
outp->port = i2c->find(i2c, NV_I2C_PORT(outp->info.i2c_index));
else
outp->port = i2c->find(i2c, NV_I2C_AUX(outp->info.i2c_index));
outp->edid = outp->port;
data = nvbios_connEp(bios, outp->info.connector, &ver, &hdr, &connE);
if (!data) {
DBG("vbios connector data not found\n");
memset(&connE, 0x00, sizeof(connE));
connE.type = DCB_CONNECTOR_NONE;
}
ret = nvkm_object_ctor(parent, NULL, nvkm_connector_oclass,
&connE, outp->info.connector,
(struct nvkm_object **)&outp->conn);
if (ret < 0) {
ERR("error %d creating connector, disabling\n", ret);
return ret;
}
list_add_tail(&outp->head, &disp->outp);
return 0;
}
int
_nvkm_output_ctor(struct nvkm_object *parent,
struct nvkm_object *engine,
struct nvkm_oclass *oclass, void *dcbE, u32 index,
struct nvkm_object **pobject)
{
struct nvkm_output *outp;
int ret;
ret = nvkm_output_create(parent, engine, oclass, dcbE, index, &outp);
*pobject = nv_object(outp);
if (ret)
return ret;
return 0;
}
