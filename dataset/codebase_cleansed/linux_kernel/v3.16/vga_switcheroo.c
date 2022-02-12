static bool vga_switcheroo_ready(void)
{
return !vgasr_priv.active &&
vgasr_priv.registered_clients == 2 && vgasr_priv.handler;
}
static void vga_switcheroo_enable(void)
{
int ret;
struct vga_switcheroo_client *client;
if (vgasr_priv.handler->init)
vgasr_priv.handler->init();
list_for_each_entry(client, &vgasr_priv.clients, list) {
if (client->id != -1)
continue;
ret = vgasr_priv.handler->get_client_id(client->pdev);
if (ret < 0)
return;
client->id = ret;
}
vga_switcheroo_debugfs_init(&vgasr_priv);
vgasr_priv.active = true;
}
int vga_switcheroo_register_handler(struct vga_switcheroo_handler *handler)
{
mutex_lock(&vgasr_mutex);
if (vgasr_priv.handler) {
mutex_unlock(&vgasr_mutex);
return -EINVAL;
}
vgasr_priv.handler = handler;
if (vga_switcheroo_ready()) {
printk(KERN_INFO "vga_switcheroo: enabled\n");
vga_switcheroo_enable();
}
mutex_unlock(&vgasr_mutex);
return 0;
}
void vga_switcheroo_unregister_handler(void)
{
mutex_lock(&vgasr_mutex);
vgasr_priv.handler = NULL;
if (vgasr_priv.active) {
pr_info("vga_switcheroo: disabled\n");
vga_switcheroo_debugfs_fini(&vgasr_priv);
vgasr_priv.active = false;
}
mutex_unlock(&vgasr_mutex);
}
static int register_client(struct pci_dev *pdev,
const struct vga_switcheroo_client_ops *ops,
int id, bool active, bool driver_power_control)
{
struct vga_switcheroo_client *client;
client = kzalloc(sizeof(*client), GFP_KERNEL);
if (!client)
return -ENOMEM;
client->pwr_state = VGA_SWITCHEROO_ON;
client->pdev = pdev;
client->ops = ops;
client->id = id;
client->active = active;
client->driver_power_control = driver_power_control;
mutex_lock(&vgasr_mutex);
list_add_tail(&client->list, &vgasr_priv.clients);
if (client_is_vga(client))
vgasr_priv.registered_clients++;
if (vga_switcheroo_ready()) {
printk(KERN_INFO "vga_switcheroo: enabled\n");
vga_switcheroo_enable();
}
mutex_unlock(&vgasr_mutex);
return 0;
}
int vga_switcheroo_register_client(struct pci_dev *pdev,
const struct vga_switcheroo_client_ops *ops,
bool driver_power_control)
{
return register_client(pdev, ops, -1,
pdev == vga_default_device(), driver_power_control);
}
int vga_switcheroo_register_audio_client(struct pci_dev *pdev,
const struct vga_switcheroo_client_ops *ops,
int id, bool active)
{
return register_client(pdev, ops, id | ID_BIT_AUDIO, active, false);
}
static struct vga_switcheroo_client *
find_client_from_pci(struct list_head *head, struct pci_dev *pdev)
{
struct vga_switcheroo_client *client;
list_for_each_entry(client, head, list)
if (client->pdev == pdev)
return client;
return NULL;
}
static struct vga_switcheroo_client *
find_client_from_id(struct list_head *head, int client_id)
{
struct vga_switcheroo_client *client;
list_for_each_entry(client, head, list)
if (client->id == client_id)
return client;
return NULL;
}
static struct vga_switcheroo_client *
find_active_client(struct list_head *head)
{
struct vga_switcheroo_client *client;
list_for_each_entry(client, head, list)
if (client->active && client_is_vga(client))
return client;
return NULL;
}
int vga_switcheroo_get_client_state(struct pci_dev *pdev)
{
struct vga_switcheroo_client *client;
client = find_client_from_pci(&vgasr_priv.clients, pdev);
if (!client)
return VGA_SWITCHEROO_NOT_FOUND;
if (!vgasr_priv.active)
return VGA_SWITCHEROO_INIT;
return client->pwr_state;
}
void vga_switcheroo_unregister_client(struct pci_dev *pdev)
{
struct vga_switcheroo_client *client;
mutex_lock(&vgasr_mutex);
client = find_client_from_pci(&vgasr_priv.clients, pdev);
if (client) {
if (client_is_vga(client))
vgasr_priv.registered_clients--;
list_del(&client->list);
kfree(client);
}
if (vgasr_priv.active && vgasr_priv.registered_clients < 2) {
printk(KERN_INFO "vga_switcheroo: disabled\n");
vga_switcheroo_debugfs_fini(&vgasr_priv);
vgasr_priv.active = false;
}
mutex_unlock(&vgasr_mutex);
}
void vga_switcheroo_client_fb_set(struct pci_dev *pdev,
struct fb_info *info)
{
struct vga_switcheroo_client *client;
mutex_lock(&vgasr_mutex);
client = find_client_from_pci(&vgasr_priv.clients, pdev);
if (client)
client->fb_info = info;
mutex_unlock(&vgasr_mutex);
}
static int vga_switcheroo_show(struct seq_file *m, void *v)
{
struct vga_switcheroo_client *client;
int i = 0;
mutex_lock(&vgasr_mutex);
list_for_each_entry(client, &vgasr_priv.clients, list) {
seq_printf(m, "%d:%s%s:%c:%s%s:%s\n", i,
client_id(client) == VGA_SWITCHEROO_DIS ? "DIS" : "IGD",
client_is_vga(client) ? "" : "-Audio",
client->active ? '+' : ' ',
client->driver_power_control ? "Dyn" : "",
client->pwr_state ? "Pwr" : "Off",
pci_name(client->pdev));
i++;
}
mutex_unlock(&vgasr_mutex);
return 0;
}
static int vga_switcheroo_debugfs_open(struct inode *inode, struct file *file)
{
return single_open(file, vga_switcheroo_show, NULL);
}
static int vga_switchon(struct vga_switcheroo_client *client)
{
if (client->driver_power_control)
return 0;
if (vgasr_priv.handler->power_state)
vgasr_priv.handler->power_state(client->id, VGA_SWITCHEROO_ON);
client->ops->set_gpu_state(client->pdev, VGA_SWITCHEROO_ON);
client->pwr_state = VGA_SWITCHEROO_ON;
return 0;
}
static int vga_switchoff(struct vga_switcheroo_client *client)
{
if (client->driver_power_control)
return 0;
client->ops->set_gpu_state(client->pdev, VGA_SWITCHEROO_OFF);
if (vgasr_priv.handler->power_state)
vgasr_priv.handler->power_state(client->id, VGA_SWITCHEROO_OFF);
client->pwr_state = VGA_SWITCHEROO_OFF;
return 0;
}
static void set_audio_state(int id, int state)
{
struct vga_switcheroo_client *client;
client = find_client_from_id(&vgasr_priv.clients, id | ID_BIT_AUDIO);
if (client && client->pwr_state != state) {
client->ops->set_gpu_state(client->pdev, state);
client->pwr_state = state;
}
}
static int vga_switchto_stage1(struct vga_switcheroo_client *new_client)
{
struct vga_switcheroo_client *active;
active = find_active_client(&vgasr_priv.clients);
if (!active)
return 0;
if (new_client->pwr_state == VGA_SWITCHEROO_OFF)
vga_switchon(new_client);
vga_set_default_device(new_client->pdev);
return 0;
}
static int vga_switchto_stage2(struct vga_switcheroo_client *new_client)
{
int ret;
struct vga_switcheroo_client *active;
active = find_active_client(&vgasr_priv.clients);
if (!active)
return 0;
active->active = false;
set_audio_state(active->id, VGA_SWITCHEROO_OFF);
if (new_client->fb_info) {
struct fb_event event;
console_lock();
event.info = new_client->fb_info;
fb_notifier_call_chain(FB_EVENT_REMAP_ALL_CONSOLE, &event);
console_unlock();
}
ret = vgasr_priv.handler->switchto(new_client->id);
if (ret)
return ret;
if (new_client->ops->reprobe)
new_client->ops->reprobe(new_client->pdev);
if (active->pwr_state == VGA_SWITCHEROO_ON)
vga_switchoff(active);
set_audio_state(new_client->id, VGA_SWITCHEROO_ON);
new_client->active = true;
return 0;
}
static bool check_can_switch(void)
{
struct vga_switcheroo_client *client;
list_for_each_entry(client, &vgasr_priv.clients, list) {
if (!client->ops->can_switch(client->pdev)) {
printk(KERN_ERR "vga_switcheroo: client %x refused switch\n", client->id);
return false;
}
}
return true;
}
static ssize_t
vga_switcheroo_debugfs_write(struct file *filp, const char __user *ubuf,
size_t cnt, loff_t *ppos)
{
char usercmd[64];
int ret;
bool delay = false, can_switch;
bool just_mux = false;
int client_id = -1;
struct vga_switcheroo_client *client = NULL;
if (cnt > 63)
cnt = 63;
if (copy_from_user(usercmd, ubuf, cnt))
return -EFAULT;
mutex_lock(&vgasr_mutex);
if (!vgasr_priv.active) {
cnt = -EINVAL;
goto out;
}
if (strncmp(usercmd, "OFF", 3) == 0) {
list_for_each_entry(client, &vgasr_priv.clients, list) {
if (client->active || client_is_audio(client))
continue;
if (client->driver_power_control)
continue;
set_audio_state(client->id, VGA_SWITCHEROO_OFF);
if (client->pwr_state == VGA_SWITCHEROO_ON)
vga_switchoff(client);
}
goto out;
}
if (strncmp(usercmd, "ON", 2) == 0) {
list_for_each_entry(client, &vgasr_priv.clients, list) {
if (client->active || client_is_audio(client))
continue;
if (client->driver_power_control)
continue;
if (client->pwr_state == VGA_SWITCHEROO_OFF)
vga_switchon(client);
set_audio_state(client->id, VGA_SWITCHEROO_ON);
}
goto out;
}
if (strncmp(usercmd, "DIGD", 4) == 0) {
client_id = VGA_SWITCHEROO_IGD;
delay = true;
}
if (strncmp(usercmd, "DDIS", 4) == 0) {
client_id = VGA_SWITCHEROO_DIS;
delay = true;
}
if (strncmp(usercmd, "IGD", 3) == 0)
client_id = VGA_SWITCHEROO_IGD;
if (strncmp(usercmd, "DIS", 3) == 0)
client_id = VGA_SWITCHEROO_DIS;
if (strncmp(usercmd, "MIGD", 4) == 0) {
just_mux = true;
client_id = VGA_SWITCHEROO_IGD;
}
if (strncmp(usercmd, "MDIS", 4) == 0) {
just_mux = true;
client_id = VGA_SWITCHEROO_DIS;
}
if (client_id == -1)
goto out;
client = find_client_from_id(&vgasr_priv.clients, client_id);
if (!client)
goto out;
vgasr_priv.delayed_switch_active = false;
if (just_mux) {
ret = vgasr_priv.handler->switchto(client_id);
goto out;
}
if (client->active)
goto out;
can_switch = check_can_switch();
if (can_switch == false && delay == false)
goto out;
if (can_switch) {
ret = vga_switchto_stage1(client);
if (ret)
printk(KERN_ERR "vga_switcheroo: switching failed stage 1 %d\n", ret);
ret = vga_switchto_stage2(client);
if (ret)
printk(KERN_ERR "vga_switcheroo: switching failed stage 2 %d\n", ret);
} else {
printk(KERN_INFO "vga_switcheroo: setting delayed switch to client %d\n", client->id);
vgasr_priv.delayed_switch_active = true;
vgasr_priv.delayed_client_id = client_id;
ret = vga_switchto_stage1(client);
if (ret)
printk(KERN_ERR "vga_switcheroo: delayed switching stage 1 failed %d\n", ret);
}
out:
mutex_unlock(&vgasr_mutex);
return cnt;
}
static void vga_switcheroo_debugfs_fini(struct vgasr_priv *priv)
{
if (priv->switch_file) {
debugfs_remove(priv->switch_file);
priv->switch_file = NULL;
}
if (priv->debugfs_root) {
debugfs_remove(priv->debugfs_root);
priv->debugfs_root = NULL;
}
}
static int vga_switcheroo_debugfs_init(struct vgasr_priv *priv)
{
if (priv->debugfs_root)
return 0;
priv->debugfs_root = debugfs_create_dir("vgaswitcheroo", NULL);
if (!priv->debugfs_root) {
printk(KERN_ERR "vga_switcheroo: Cannot create /sys/kernel/debug/vgaswitcheroo\n");
goto fail;
}
priv->switch_file = debugfs_create_file("switch", 0644,
priv->debugfs_root, NULL, &vga_switcheroo_debugfs_fops);
if (!priv->switch_file) {
printk(KERN_ERR "vga_switcheroo: cannot create /sys/kernel/debug/vgaswitcheroo/switch\n");
goto fail;
}
return 0;
fail:
vga_switcheroo_debugfs_fini(priv);
return -1;
}
int vga_switcheroo_process_delayed_switch(void)
{
struct vga_switcheroo_client *client;
int ret;
int err = -EINVAL;
mutex_lock(&vgasr_mutex);
if (!vgasr_priv.delayed_switch_active)
goto err;
printk(KERN_INFO "vga_switcheroo: processing delayed switch to %d\n", vgasr_priv.delayed_client_id);
client = find_client_from_id(&vgasr_priv.clients,
vgasr_priv.delayed_client_id);
if (!client || !check_can_switch())
goto err;
ret = vga_switchto_stage2(client);
if (ret)
printk(KERN_ERR "vga_switcheroo: delayed switching failed stage 2 %d\n", ret);
vgasr_priv.delayed_switch_active = false;
err = 0;
err:
mutex_unlock(&vgasr_mutex);
return err;
}
static void vga_switcheroo_power_switch(struct pci_dev *pdev, enum vga_switcheroo_state state)
{
struct vga_switcheroo_client *client;
if (!vgasr_priv.handler->power_state)
return;
client = find_client_from_pci(&vgasr_priv.clients, pdev);
if (!client)
return;
if (!client->driver_power_control)
return;
vgasr_priv.handler->power_state(client->id, state);
}
void vga_switcheroo_set_dynamic_switch(struct pci_dev *pdev, enum vga_switcheroo_state dynamic)
{
struct vga_switcheroo_client *client;
client = find_client_from_pci(&vgasr_priv.clients, pdev);
if (!client)
return;
if (!client->driver_power_control)
return;
client->pwr_state = dynamic;
set_audio_state(client->id, dynamic);
}
static int vga_switcheroo_runtime_suspend(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
int ret;
ret = dev->bus->pm->runtime_suspend(dev);
if (ret)
return ret;
if (vgasr_priv.handler->switchto)
vgasr_priv.handler->switchto(VGA_SWITCHEROO_IGD);
vga_switcheroo_power_switch(pdev, VGA_SWITCHEROO_OFF);
return 0;
}
static int vga_switcheroo_runtime_resume(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
int ret;
vga_switcheroo_power_switch(pdev, VGA_SWITCHEROO_ON);
ret = dev->bus->pm->runtime_resume(dev);
if (ret)
return ret;
return 0;
}
int vga_switcheroo_init_domain_pm_ops(struct device *dev, struct dev_pm_domain *domain)
{
if (dev->bus && dev->bus->pm) {
domain->ops = *dev->bus->pm;
domain->ops.runtime_suspend = vga_switcheroo_runtime_suspend;
domain->ops.runtime_resume = vga_switcheroo_runtime_resume;
dev->pm_domain = domain;
return 0;
}
dev->pm_domain = NULL;
return -EINVAL;
}
static int vga_switcheroo_runtime_resume_hdmi_audio(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
int ret;
struct vga_switcheroo_client *client, *found = NULL;
list_for_each_entry(client, &vgasr_priv.clients, list) {
if (PCI_SLOT(client->pdev->devfn) == PCI_SLOT(pdev->devfn) && client_is_vga(client)) {
found = client;
ret = pm_runtime_get_sync(&client->pdev->dev);
if (ret) {
if (ret != 1)
return ret;
}
break;
}
}
ret = dev->bus->pm->runtime_resume(dev);
if (found) {
pm_runtime_mark_last_busy(&found->pdev->dev);
pm_runtime_put_autosuspend(&found->pdev->dev);
}
return ret;
}
int vga_switcheroo_init_domain_pm_optimus_hdmi_audio(struct device *dev, struct dev_pm_domain *domain)
{
if (dev->bus && dev->bus->pm) {
domain->ops = *dev->bus->pm;
domain->ops.runtime_resume = vga_switcheroo_runtime_resume_hdmi_audio;
dev->pm_domain = domain;
return 0;
}
dev->pm_domain = NULL;
return -EINVAL;
}
