static u32 to_codec_type(u32 pixfmt)\r\n{\r\nswitch (pixfmt) {\r\ncase V4L2_PIX_FMT_H264:\r\ncase V4L2_PIX_FMT_H264_NO_SC:\r\nreturn HFI_VIDEO_CODEC_H264;\r\ncase V4L2_PIX_FMT_H263:\r\nreturn HFI_VIDEO_CODEC_H263;\r\ncase V4L2_PIX_FMT_MPEG1:\r\nreturn HFI_VIDEO_CODEC_MPEG1;\r\ncase V4L2_PIX_FMT_MPEG2:\r\nreturn HFI_VIDEO_CODEC_MPEG2;\r\ncase V4L2_PIX_FMT_MPEG4:\r\nreturn HFI_VIDEO_CODEC_MPEG4;\r\ncase V4L2_PIX_FMT_VC1_ANNEX_G:\r\ncase V4L2_PIX_FMT_VC1_ANNEX_L:\r\nreturn HFI_VIDEO_CODEC_VC1;\r\ncase V4L2_PIX_FMT_VP8:\r\nreturn HFI_VIDEO_CODEC_VP8;\r\ncase V4L2_PIX_FMT_VP9:\r\nreturn HFI_VIDEO_CODEC_VP9;\r\ncase V4L2_PIX_FMT_XVID:\r\nreturn HFI_VIDEO_CODEC_DIVX;\r\ndefault:\r\nreturn 0;\r\n}\r\n}\r\nint hfi_core_init(struct venus_core *core)\r\n{\r\nint ret = 0;\r\nmutex_lock(&core->lock);\r\nif (core->state >= CORE_INIT)\r\ngoto unlock;\r\nreinit_completion(&core->done);\r\nret = core->ops->core_init(core);\r\nif (ret)\r\ngoto unlock;\r\nret = wait_for_completion_timeout(&core->done, TIMEOUT);\r\nif (!ret) {\r\nret = -ETIMEDOUT;\r\ngoto unlock;\r\n}\r\nret = 0;\r\nif (core->error != HFI_ERR_NONE) {\r\nret = -EIO;\r\ngoto unlock;\r\n}\r\ncore->state = CORE_INIT;\r\nunlock:\r\nmutex_unlock(&core->lock);\r\nreturn ret;\r\n}\r\nstatic int core_deinit_wait_atomic_t(atomic_t *p)\r\n{\r\nschedule();\r\nreturn 0;\r\n}\r\nint hfi_core_deinit(struct venus_core *core, bool blocking)\r\n{\r\nint ret = 0, empty;\r\nmutex_lock(&core->lock);\r\nif (core->state == CORE_UNINIT)\r\ngoto unlock;\r\nempty = list_empty(&core->instances);\r\nif (!empty && !blocking) {\r\nret = -EBUSY;\r\ngoto unlock;\r\n}\r\nif (!empty) {\r\nmutex_unlock(&core->lock);\r\nwait_on_atomic_t(&core->insts_count, core_deinit_wait_atomic_t,\r\nTASK_UNINTERRUPTIBLE);\r\nmutex_lock(&core->lock);\r\n}\r\nret = core->ops->core_deinit(core);\r\nif (!ret)\r\ncore->state = CORE_UNINIT;\r\nunlock:\r\nmutex_unlock(&core->lock);\r\nreturn ret;\r\n}\r\nint hfi_core_suspend(struct venus_core *core)\r\n{\r\nif (core->state != CORE_INIT)\r\nreturn 0;\r\nreturn core->ops->suspend(core);\r\n}\r\nint hfi_core_resume(struct venus_core *core, bool force)\r\n{\r\nif (!force && core->state != CORE_INIT)\r\nreturn 0;\r\nreturn core->ops->resume(core);\r\n}\r\nint hfi_core_trigger_ssr(struct venus_core *core, u32 type)\r\n{\r\nreturn core->ops->core_trigger_ssr(core, type);\r\n}\r\nint hfi_core_ping(struct venus_core *core)\r\n{\r\nint ret;\r\nmutex_lock(&core->lock);\r\nret = core->ops->core_ping(core, 0xbeef);\r\nif (ret)\r\ngoto unlock;\r\nret = wait_for_completion_timeout(&core->done, TIMEOUT);\r\nif (!ret) {\r\nret = -ETIMEDOUT;\r\ngoto unlock;\r\n}\r\nret = 0;\r\nif (core->error != HFI_ERR_NONE)\r\nret = -ENODEV;\r\nunlock:\r\nmutex_unlock(&core->lock);\r\nreturn ret;\r\n}\r\nstatic int wait_session_msg(struct venus_inst *inst)\r\n{\r\nint ret;\r\nret = wait_for_completion_timeout(&inst->done, TIMEOUT);\r\nif (!ret)\r\nreturn -ETIMEDOUT;\r\nif (inst->error != HFI_ERR_NONE)\r\nreturn -EIO;\r\nreturn 0;\r\n}\r\nint hfi_session_create(struct venus_inst *inst, const struct hfi_inst_ops *ops)\r\n{\r\nstruct venus_core *core = inst->core;\r\nif (!ops)\r\nreturn -EINVAL;\r\ninst->state = INST_UNINIT;\r\ninit_completion(&inst->done);\r\ninst->ops = ops;\r\nmutex_lock(&core->lock);\r\nlist_add_tail(&inst->list, &core->instances);\r\natomic_inc(&core->insts_count);\r\nmutex_unlock(&core->lock);\r\nreturn 0;\r\n}\r\nint hfi_session_init(struct venus_inst *inst, u32 pixfmt)\r\n{\r\nstruct venus_core *core = inst->core;\r\nconst struct hfi_ops *ops = core->ops;\r\nu32 codec;\r\nint ret;\r\ncodec = to_codec_type(pixfmt);\r\nreinit_completion(&inst->done);\r\nret = ops->session_init(inst, inst->session_type, codec);\r\nif (ret)\r\nreturn ret;\r\nret = wait_session_msg(inst);\r\nif (ret)\r\nreturn ret;\r\ninst->state = INST_INIT;\r\nreturn 0;\r\n}\r\nvoid hfi_session_destroy(struct venus_inst *inst)\r\n{\r\nstruct venus_core *core = inst->core;\r\nmutex_lock(&core->lock);\r\nlist_del_init(&inst->list);\r\natomic_dec(&core->insts_count);\r\nwake_up_atomic_t(&core->insts_count);\r\nmutex_unlock(&core->lock);\r\n}\r\nint hfi_session_deinit(struct venus_inst *inst)\r\n{\r\nconst struct hfi_ops *ops = inst->core->ops;\r\nint ret;\r\nif (inst->state == INST_UNINIT)\r\nreturn 0;\r\nif (inst->state < INST_INIT)\r\nreturn -EINVAL;\r\nreinit_completion(&inst->done);\r\nret = ops->session_end(inst);\r\nif (ret)\r\nreturn ret;\r\nret = wait_session_msg(inst);\r\nif (ret)\r\nreturn ret;\r\ninst->state = INST_UNINIT;\r\nreturn 0;\r\n}\r\nint hfi_session_start(struct venus_inst *inst)\r\n{\r\nconst struct hfi_ops *ops = inst->core->ops;\r\nint ret;\r\nif (inst->state != INST_LOAD_RESOURCES)\r\nreturn -EINVAL;\r\nreinit_completion(&inst->done);\r\nret = ops->session_start(inst);\r\nif (ret)\r\nreturn ret;\r\nret = wait_session_msg(inst);\r\nif (ret)\r\nreturn ret;\r\ninst->state = INST_START;\r\nreturn 0;\r\n}\r\nint hfi_session_stop(struct venus_inst *inst)\r\n{\r\nconst struct hfi_ops *ops = inst->core->ops;\r\nint ret;\r\nif (inst->state != INST_START)\r\nreturn -EINVAL;\r\nreinit_completion(&inst->done);\r\nret = ops->session_stop(inst);\r\nif (ret)\r\nreturn ret;\r\nret = wait_session_msg(inst);\r\nif (ret)\r\nreturn ret;\r\ninst->state = INST_STOP;\r\nreturn 0;\r\n}\r\nint hfi_session_continue(struct venus_inst *inst)\r\n{\r\nstruct venus_core *core = inst->core;\r\nif (core->res->hfi_version != HFI_VERSION_3XX)\r\nreturn 0;\r\nreturn core->ops->session_continue(inst);\r\n}\r\nint hfi_session_abort(struct venus_inst *inst)\r\n{\r\nconst struct hfi_ops *ops = inst->core->ops;\r\nint ret;\r\nreinit_completion(&inst->done);\r\nret = ops->session_abort(inst);\r\nif (ret)\r\nreturn ret;\r\nret = wait_session_msg(inst);\r\nif (ret)\r\nreturn ret;\r\nreturn 0;\r\n}\r\nint hfi_session_load_res(struct venus_inst *inst)\r\n{\r\nconst struct hfi_ops *ops = inst->core->ops;\r\nint ret;\r\nif (inst->state != INST_INIT)\r\nreturn -EINVAL;\r\nreinit_completion(&inst->done);\r\nret = ops->session_load_res(inst);\r\nif (ret)\r\nreturn ret;\r\nret = wait_session_msg(inst);\r\nif (ret)\r\nreturn ret;\r\ninst->state = INST_LOAD_RESOURCES;\r\nreturn 0;\r\n}\r\nint hfi_session_unload_res(struct venus_inst *inst)\r\n{\r\nconst struct hfi_ops *ops = inst->core->ops;\r\nint ret;\r\nif (inst->state != INST_STOP)\r\nreturn -EINVAL;\r\nreinit_completion(&inst->done);\r\nret = ops->session_release_res(inst);\r\nif (ret)\r\nreturn ret;\r\nret = wait_session_msg(inst);\r\nif (ret)\r\nreturn ret;\r\ninst->state = INST_RELEASE_RESOURCES;\r\nreturn 0;\r\n}\r\nint hfi_session_flush(struct venus_inst *inst)\r\n{\r\nconst struct hfi_ops *ops = inst->core->ops;\r\nint ret;\r\nreinit_completion(&inst->done);\r\nret = ops->session_flush(inst, HFI_FLUSH_ALL);\r\nif (ret)\r\nreturn ret;\r\nret = wait_session_msg(inst);\r\nif (ret)\r\nreturn ret;\r\nreturn 0;\r\n}\r\nint hfi_session_set_buffers(struct venus_inst *inst, struct hfi_buffer_desc *bd)\r\n{\r\nconst struct hfi_ops *ops = inst->core->ops;\r\nreturn ops->session_set_buffers(inst, bd);\r\n}\r\nint hfi_session_unset_buffers(struct venus_inst *inst,\r\nstruct hfi_buffer_desc *bd)\r\n{\r\nconst struct hfi_ops *ops = inst->core->ops;\r\nint ret;\r\nreinit_completion(&inst->done);\r\nret = ops->session_unset_buffers(inst, bd);\r\nif (ret)\r\nreturn ret;\r\nif (!bd->response_required)\r\nreturn 0;\r\nret = wait_session_msg(inst);\r\nif (ret)\r\nreturn ret;\r\nreturn 0;\r\n}\r\nint hfi_session_get_property(struct venus_inst *inst, u32 ptype,\r\nunion hfi_get_property *hprop)\r\n{\r\nconst struct hfi_ops *ops = inst->core->ops;\r\nint ret;\r\nif (inst->state < INST_INIT || inst->state >= INST_STOP)\r\nreturn -EINVAL;\r\nreinit_completion(&inst->done);\r\nret = ops->session_get_property(inst, ptype);\r\nif (ret)\r\nreturn ret;\r\nret = wait_session_msg(inst);\r\nif (ret)\r\nreturn ret;\r\n*hprop = inst->hprop;\r\nreturn 0;\r\n}\r\nint hfi_session_set_property(struct venus_inst *inst, u32 ptype, void *pdata)\r\n{\r\nconst struct hfi_ops *ops = inst->core->ops;\r\nif (inst->state < INST_INIT || inst->state >= INST_STOP)\r\nreturn -EINVAL;\r\nreturn ops->session_set_property(inst, ptype, pdata);\r\n}\r\nint hfi_session_process_buf(struct venus_inst *inst, struct hfi_frame_data *fd)\r\n{\r\nconst struct hfi_ops *ops = inst->core->ops;\r\nif (fd->buffer_type == HFI_BUFFER_INPUT)\r\nreturn ops->session_etb(inst, fd);\r\nelse if (fd->buffer_type == HFI_BUFFER_OUTPUT)\r\nreturn ops->session_ftb(inst, fd);\r\nreturn -EINVAL;\r\n}\r\nirqreturn_t hfi_isr_thread(int irq, void *dev_id)\r\n{\r\nstruct venus_core *core = dev_id;\r\nreturn core->ops->isr_thread(core);\r\n}\r\nirqreturn_t hfi_isr(int irq, void *dev)\r\n{\r\nstruct venus_core *core = dev;\r\nreturn core->ops->isr(core);\r\n}\r\nint hfi_create(struct venus_core *core, const struct hfi_core_ops *ops)\r\n{\r\nint ret;\r\nif (!ops)\r\nreturn -EINVAL;\r\natomic_set(&core->insts_count, 0);\r\ncore->core_ops = ops;\r\ncore->state = CORE_UNINIT;\r\ninit_completion(&core->done);\r\npkt_set_version(core->res->hfi_version);\r\nret = venus_hfi_create(core);\r\nreturn ret;\r\n}\r\nvoid hfi_destroy(struct venus_core *core)\r\n{\r\nvenus_hfi_destroy(core);\r\n}
