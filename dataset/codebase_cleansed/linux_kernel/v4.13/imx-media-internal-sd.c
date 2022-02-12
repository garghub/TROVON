static inline void isd_id_to_devname(char *devname, int sz,
const struct internal_subdev_id *id,
int ipu_id)
{
int pdev_id = ipu_id * num_isd + id->index;
snprintf(devname, sz, "%s.%d", id->name, pdev_id);
}
static int add_internal_links(struct imx_media_dev *imxmd,
const struct internal_subdev *isd,
struct imx_media_subdev *imxsd,
int ipu_id)
{
int i, num_pads, ret;
num_pads = isd->num_sink_pads + isd->num_src_pads;
for (i = 0; i < num_pads; i++) {
const struct internal_pad *intpad = &isd->pad[i];
struct imx_media_pad *pad = &imxsd->pad[i];
int j;
pad->pad.flags = (i < isd->num_sink_pads) ?
MEDIA_PAD_FL_SINK : MEDIA_PAD_FL_SOURCE;
pad->devnode = intpad->devnode;
for (j = 0; ; j++) {
const struct internal_link *link;
char remote_devname[32];
link = &intpad->link[j];
if (!link->remote_id)
break;
isd_id_to_devname(remote_devname,
sizeof(remote_devname),
link->remote_id, ipu_id);
ret = imx_media_add_pad_link(imxmd, pad,
NULL, remote_devname,
i, link->remote_pad);
if (ret)
return ret;
}
}
return 0;
}
static struct imx_media_subdev *
add_internal_subdev(struct imx_media_dev *imxmd,
const struct internal_subdev *isd,
int ipu_id)
{
struct imx_media_internal_sd_platformdata pdata;
struct platform_device_info pdevinfo = {0};
struct imx_media_subdev *imxsd;
struct platform_device *pdev;
pdata.grp_id = isd->id->grp_id;
pdata.ipu_id = ipu_id;
imx_media_grp_id_to_sd_name(pdata.sd_name, sizeof(pdata.sd_name),
pdata.grp_id, ipu_id);
pdevinfo.name = isd->id->name;
pdevinfo.id = ipu_id * num_isd + isd->id->index;
pdevinfo.parent = imxmd->md.dev;
pdevinfo.data = &pdata;
pdevinfo.size_data = sizeof(pdata);
pdevinfo.dma_mask = DMA_BIT_MASK(32);
pdev = platform_device_register_full(&pdevinfo);
if (IS_ERR(pdev))
return ERR_CAST(pdev);
imxsd = imx_media_add_async_subdev(imxmd, NULL, pdev);
if (IS_ERR(imxsd))
return imxsd;
imxsd->num_sink_pads = isd->num_sink_pads;
imxsd->num_src_pads = isd->num_src_pads;
return imxsd;
}
static int add_ipu_internal_subdevs(struct imx_media_dev *imxmd,
struct imx_media_subdev *csi0,
struct imx_media_subdev *csi1,
int ipu_id)
{
enum isd_enum i;
int ret;
for (i = 0; i < num_isd; i++) {
const struct internal_subdev *isd = &internal_subdev[i];
struct imx_media_subdev *imxsd;
switch (isd->id->grp_id) {
case IMX_MEDIA_GRP_ID_CSI0:
imxsd = csi0;
break;
case IMX_MEDIA_GRP_ID_CSI1:
imxsd = csi1;
break;
default:
imxsd = add_internal_subdev(imxmd, isd, ipu_id);
break;
}
if (IS_ERR(imxsd))
return PTR_ERR(imxsd);
if (imxsd) {
ret = add_internal_links(imxmd, isd, imxsd, ipu_id);
if (ret)
return ret;
}
}
return 0;
}
int imx_media_add_internal_subdevs(struct imx_media_dev *imxmd,
struct imx_media_subdev *csi[4])
{
int ret;
ret = add_ipu_internal_subdevs(imxmd, csi[0], csi[1], 0);
if (ret)
goto remove;
ret = add_ipu_internal_subdevs(imxmd, csi[2], csi[3], 1);
if (ret)
goto remove;
return 0;
remove:
imx_media_remove_internal_subdevs(imxmd);
return ret;
}
void imx_media_remove_internal_subdevs(struct imx_media_dev *imxmd)
{
struct imx_media_subdev *imxsd;
int i;
for (i = 0; i < imxmd->subdev_notifier.num_subdevs; i++) {
imxsd = &imxmd->subdev[i];
if (!imxsd->pdev)
continue;
platform_device_unregister(imxsd->pdev);
}
}
