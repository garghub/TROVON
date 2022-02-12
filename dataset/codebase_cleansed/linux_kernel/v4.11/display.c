static int get_edp_pipe(struct intel_vgpu *vgpu)
{
u32 data = vgpu_vreg(vgpu, _TRANS_DDI_FUNC_CTL_EDP);
int pipe = -1;
switch (data & TRANS_DDI_EDP_INPUT_MASK) {
case TRANS_DDI_EDP_INPUT_A_ON:
case TRANS_DDI_EDP_INPUT_A_ONOFF:
pipe = PIPE_A;
break;
case TRANS_DDI_EDP_INPUT_B_ONOFF:
pipe = PIPE_B;
break;
case TRANS_DDI_EDP_INPUT_C_ONOFF:
pipe = PIPE_C;
break;
}
return pipe;
}
static int edp_pipe_is_enabled(struct intel_vgpu *vgpu)
{
struct drm_i915_private *dev_priv = vgpu->gvt->dev_priv;
if (!(vgpu_vreg(vgpu, PIPECONF(_PIPE_EDP)) & PIPECONF_ENABLE))
return 0;
if (!(vgpu_vreg(vgpu, _TRANS_DDI_FUNC_CTL_EDP) & TRANS_DDI_FUNC_ENABLE))
return 0;
return 1;
}
static int pipe_is_enabled(struct intel_vgpu *vgpu, int pipe)
{
struct drm_i915_private *dev_priv = vgpu->gvt->dev_priv;
if (WARN_ON(pipe < PIPE_A || pipe >= I915_MAX_PIPES))
return -EINVAL;
if (vgpu_vreg(vgpu, PIPECONF(pipe)) & PIPECONF_ENABLE)
return 1;
if (edp_pipe_is_enabled(vgpu) &&
get_edp_pipe(vgpu) == pipe)
return 1;
return 0;
}
static void emulate_monitor_status_change(struct intel_vgpu *vgpu)
{
struct drm_i915_private *dev_priv = vgpu->gvt->dev_priv;
vgpu_vreg(vgpu, SDEISR) &= ~(SDE_PORTB_HOTPLUG_CPT |
SDE_PORTC_HOTPLUG_CPT |
SDE_PORTD_HOTPLUG_CPT);
if (IS_SKYLAKE(dev_priv))
vgpu_vreg(vgpu, SDEISR) &= ~(SDE_PORTA_HOTPLUG_SPT |
SDE_PORTE_HOTPLUG_SPT);
if (intel_vgpu_has_monitor_on_port(vgpu, PORT_B)) {
vgpu_vreg(vgpu, SDEISR) |= SDE_PORTB_HOTPLUG_CPT;
vgpu_vreg(vgpu, SFUSE_STRAP) |= SFUSE_STRAP_DDIB_DETECTED;
}
if (intel_vgpu_has_monitor_on_port(vgpu, PORT_C)) {
vgpu_vreg(vgpu, SDEISR) |= SDE_PORTC_HOTPLUG_CPT;
vgpu_vreg(vgpu, SFUSE_STRAP) |= SFUSE_STRAP_DDIC_DETECTED;
}
if (intel_vgpu_has_monitor_on_port(vgpu, PORT_D)) {
vgpu_vreg(vgpu, SDEISR) |= SDE_PORTD_HOTPLUG_CPT;
vgpu_vreg(vgpu, SFUSE_STRAP) |= SFUSE_STRAP_DDID_DETECTED;
}
if (IS_SKYLAKE(dev_priv) &&
intel_vgpu_has_monitor_on_port(vgpu, PORT_E)) {
vgpu_vreg(vgpu, SDEISR) |= SDE_PORTE_HOTPLUG_SPT;
}
if (intel_vgpu_has_monitor_on_port(vgpu, PORT_A)) {
if (IS_BROADWELL(dev_priv))
vgpu_vreg(vgpu, GEN8_DE_PORT_ISR) |=
GEN8_PORT_DP_A_HOTPLUG;
else
vgpu_vreg(vgpu, SDEISR) |= SDE_PORTA_HOTPLUG_SPT;
vgpu_vreg(vgpu, DDI_BUF_CTL(PORT_A)) |= DDI_INIT_DISPLAY_DETECTED;
}
}
static void clean_virtual_dp_monitor(struct intel_vgpu *vgpu, int port_num)
{
struct intel_vgpu_port *port = intel_vgpu_port(vgpu, port_num);
kfree(port->edid);
port->edid = NULL;
kfree(port->dpcd);
port->dpcd = NULL;
}
static int setup_virtual_dp_monitor(struct intel_vgpu *vgpu, int port_num,
int type, unsigned int resolution)
{
struct intel_vgpu_port *port = intel_vgpu_port(vgpu, port_num);
if (WARN_ON(resolution >= GVT_EDID_NUM))
return -EINVAL;
port->edid = kzalloc(sizeof(*(port->edid)), GFP_KERNEL);
if (!port->edid)
return -ENOMEM;
port->dpcd = kzalloc(sizeof(*(port->dpcd)), GFP_KERNEL);
if (!port->dpcd) {
kfree(port->edid);
return -ENOMEM;
}
memcpy(port->edid->edid_block, virtual_dp_monitor_edid[resolution],
EDID_SIZE);
port->edid->data_valid = true;
memcpy(port->dpcd->data, dpcd_fix_data, DPCD_HEADER_SIZE);
port->dpcd->data_valid = true;
port->dpcd->data[DPCD_SINK_COUNT] = 0x1;
port->type = type;
emulate_monitor_status_change(vgpu);
return 0;
}
void intel_gvt_check_vblank_emulation(struct intel_gvt *gvt)
{
struct intel_gvt_irq *irq = &gvt->irq;
struct intel_vgpu *vgpu;
bool have_enabled_pipe = false;
int pipe, id;
if (WARN_ON(!mutex_is_locked(&gvt->lock)))
return;
hrtimer_cancel(&irq->vblank_timer.timer);
for_each_active_vgpu(gvt, vgpu, id) {
for (pipe = 0; pipe < I915_MAX_PIPES; pipe++) {
have_enabled_pipe =
pipe_is_enabled(vgpu, pipe);
if (have_enabled_pipe)
break;
}
}
if (have_enabled_pipe)
hrtimer_start(&irq->vblank_timer.timer,
ktime_add_ns(ktime_get(), irq->vblank_timer.period),
HRTIMER_MODE_ABS);
}
static void emulate_vblank_on_pipe(struct intel_vgpu *vgpu, int pipe)
{
struct drm_i915_private *dev_priv = vgpu->gvt->dev_priv;
struct intel_vgpu_irq *irq = &vgpu->irq;
int vblank_event[] = {
[PIPE_A] = PIPE_A_VBLANK,
[PIPE_B] = PIPE_B_VBLANK,
[PIPE_C] = PIPE_C_VBLANK,
};
int event;
if (pipe < PIPE_A || pipe > PIPE_C)
return;
for_each_set_bit(event, irq->flip_done_event[pipe],
INTEL_GVT_EVENT_MAX) {
clear_bit(event, irq->flip_done_event[pipe]);
if (!pipe_is_enabled(vgpu, pipe))
continue;
vgpu_vreg(vgpu, PIPE_FLIPCOUNT_G4X(pipe))++;
intel_vgpu_trigger_virtual_event(vgpu, event);
}
if (pipe_is_enabled(vgpu, pipe)) {
vgpu_vreg(vgpu, PIPE_FRMCOUNT_G4X(pipe))++;
intel_vgpu_trigger_virtual_event(vgpu, vblank_event[pipe]);
}
}
static void emulate_vblank(struct intel_vgpu *vgpu)
{
int pipe;
for_each_pipe(vgpu->gvt->dev_priv, pipe)
emulate_vblank_on_pipe(vgpu, pipe);
}
void intel_gvt_emulate_vblank(struct intel_gvt *gvt)
{
struct intel_vgpu *vgpu;
int id;
if (WARN_ON(!mutex_is_locked(&gvt->lock)))
return;
for_each_active_vgpu(gvt, vgpu, id)
emulate_vblank(vgpu);
}
void intel_vgpu_clean_display(struct intel_vgpu *vgpu)
{
struct drm_i915_private *dev_priv = vgpu->gvt->dev_priv;
if (IS_SKYLAKE(dev_priv))
clean_virtual_dp_monitor(vgpu, PORT_D);
else
clean_virtual_dp_monitor(vgpu, PORT_B);
}
int intel_vgpu_init_display(struct intel_vgpu *vgpu, u64 resolution)
{
struct drm_i915_private *dev_priv = vgpu->gvt->dev_priv;
intel_vgpu_init_i2c_edid(vgpu);
if (IS_SKYLAKE(dev_priv))
return setup_virtual_dp_monitor(vgpu, PORT_D, GVT_DP_D,
resolution);
else
return setup_virtual_dp_monitor(vgpu, PORT_B, GVT_DP_B,
resolution);
}
void intel_vgpu_reset_display(struct intel_vgpu *vgpu)
{
emulate_monitor_status_change(vgpu);
}
