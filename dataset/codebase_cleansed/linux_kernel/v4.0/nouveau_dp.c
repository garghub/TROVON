static void
nouveau_dp_probe_oui(struct drm_device *dev, struct nvkm_i2c_port *auxch,
u8 *dpcd)
{
struct nouveau_drm *drm = nouveau_drm(dev);
u8 buf[3];
if (!(dpcd[DP_DOWN_STREAM_PORT_COUNT] & DP_OUI_SUPPORT))
return;
if (!nv_rdaux(auxch, DP_SINK_OUI, buf, 3))
NV_DEBUG(drm, "Sink OUI: %02hx%02hx%02hx\n",
buf[0], buf[1], buf[2]);
if (!nv_rdaux(auxch, DP_BRANCH_OUI, buf, 3))
NV_DEBUG(drm, "Branch OUI: %02hx%02hx%02hx\n",
buf[0], buf[1], buf[2]);
}
int
nouveau_dp_detect(struct nouveau_encoder *nv_encoder)
{
struct drm_device *dev = nv_encoder->base.base.dev;
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_i2c_port *auxch;
u8 *dpcd = nv_encoder->dp.dpcd;
int ret;
auxch = nv_encoder->i2c;
if (!auxch)
return -ENODEV;
ret = nv_rdaux(auxch, DP_DPCD_REV, dpcd, 8);
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
nouveau_dp_probe_oui(dev, auxch, dpcd);
return 0;
}
