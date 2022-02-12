u32 vmci_get_context_id(void)
{
if (vmci_guest_code_active())
return vmci_get_vm_context_id();
else if (vmci_host_code_active())
return VMCI_HOST_CONTEXT_ID;
return VMCI_INVALID_ID;
}
static int __init vmci_drv_init(void)
{
int vmci_err;
int error;
vmci_err = vmci_event_init();
if (vmci_err < VMCI_SUCCESS) {
pr_err("Failed to initialize VMCIEvent (result=%d)\n",
vmci_err);
return -EINVAL;
}
if (!vmci_disable_guest) {
error = vmci_guest_init();
if (error) {
pr_warn("Failed to initialize guest personality (err=%d)\n",
error);
} else {
vmci_guest_personality_initialized = true;
pr_info("Guest personality initialized and is %s\n",
vmci_guest_code_active() ?
"active" : "inactive");
}
}
if (!vmci_disable_host) {
error = vmci_host_init();
if (error) {
pr_warn("Unable to initialize host personality (err=%d)\n",
error);
} else {
vmci_host_personality_initialized = true;
pr_info("Initialized host personality\n");
}
}
if (!vmci_guest_personality_initialized &&
!vmci_host_personality_initialized) {
vmci_event_exit();
return -ENODEV;
}
return 0;
}
static void __exit vmci_drv_exit(void)
{
if (vmci_guest_personality_initialized)
vmci_guest_exit();
if (vmci_host_personality_initialized)
vmci_host_exit();
vmci_event_exit();
}
