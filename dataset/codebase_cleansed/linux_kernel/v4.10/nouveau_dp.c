static void
nouveau_dp_probe_oui(struct drm_device *dev, struct nvkm_i2c_aux *aux, u8 *dpcd)
{
struct nouveau_drm *drm = nouveau_drm(dev);
u8 buf[3];
if (!(dpcd[DP_DOWN_STREAM_PORT_COUNT] & DP_OUI_SUPPORT))
return;
if (!nvkm_rdaux(aux, DP_SINK_OUI, buf, 3))
NV_DEBUG(drm, "Sink OUI: %02hx%02hx%02hx\n",
buf[0], buf[1], buf[2]);
if (!nvkm_rdaux(aux, DP_BRANCH_OUI, buf, 3))
NV_DEBUG(drm, "Branch OUI: %02hx%02hx%02hx\n",
buf[0], buf[1], buf[2]);
}
int
nouveau_dp_detect(struct nouveau_encoder *nv_encoder)
{
struct drm_device *dev = nv_encoder->base.base.dev;
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_i2c_aux *aux;
u8 dpcd[8];
int ret;
aux = nv_encoder->aux;
if (!aux)
return -ENODEV;
ret = nvkm_rdaux(aux, DP_DPCD_REV, dpcd, sizeof(dpcd));
if (ret)
return ret;
nv_encoder->dp.link_bw = 27000 * dpcd[1];
nv_encoder->dp.link_nr = dpcd[2] & DP_MAX_LANE_COUNT_MASK;
NV_DEBUG(drm, "display: %dx%d dpcd 0x%02x\n",
nv_encoder->dp.link_nr, nv_encoder->dp.link_bw, dpcd[0]);
NV_DEBUG(drm, "encoder: %dx%d\n",
nv_encoder->dcb->dpconf.link_nr,
nv_encoder->dcb->dpconf.link_bw);
if (nv_encoder->dcb->dpconf.link_nr < nv_encoder->dp.link_nr)
nv_encoder->dp.link_nr = nv_encoder->dcb->dpconf.link_nr;
if (nv_encoder->dcb->dpconf.link_bw < nv_encoder->dp.link_bw)
nv_encoder->dp.link_bw = nv_encoder->dcb->dpconf.link_bw;
NV_DEBUG(drm, "maximum: %dx%d\n",
nv_encoder->dp.link_nr, nv_encoder->dp.link_bw);
nouveau_dp_probe_oui(dev, aux, dpcd);
ret = nv50_mstm_detect(nv_encoder->dp.mstm, dpcd, nouveau_mst);
if (ret == 1)
return NOUVEAU_DP_MST;
if (ret == 0)
return NOUVEAU_DP_SST;
return ret;
}
