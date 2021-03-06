int\r\nnv50_disp_oimm_new(const struct nv50_disp_chan_func *func,\r\nconst struct nv50_disp_chan_mthd *mthd,\r\nstruct nv50_disp_root *root, int chid,\r\nconst struct nvkm_oclass *oclass, void *data, u32 size,\r\nstruct nvkm_object **pobject)\r\n{\r\nunion {\r\nstruct nv50_disp_overlay_v0 v0;\r\n} *args = data;\r\nstruct nvkm_object *parent = oclass->parent;\r\nstruct nv50_disp *disp = root->disp;\r\nint head, ret = -ENOSYS;\r\nnvif_ioctl(parent, "create disp overlay size %d\n", size);\r\nif (!(ret = nvif_unpack(ret, &data, &size, args->v0, 0, 0, false))) {\r\nnvif_ioctl(parent, "create disp overlay vers %d head %d\n",\r\nargs->v0.version, args->v0.head);\r\nif (args->v0.head > disp->base.head.nr)\r\nreturn -EINVAL;\r\nhead = args->v0.head;\r\n} else\r\nreturn ret;\r\nreturn nv50_disp_chan_new_(func, mthd, root, chid + head,\r\nhead, oclass, pobject);\r\n}
