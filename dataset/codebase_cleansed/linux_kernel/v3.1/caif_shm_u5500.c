static int shmdev_send_msg(u32 dev_id, u32 mbx_msg)
{
mbox_send(shmdev_lyr[dev_id].hmbx, mbx_msg, true);
return 0;
}
static int shmdev_mbx_setup(void *pshmdrv_cb, struct shmdev_layer *pshm_dev,
void *pshm_drv)
{
pshm_dev->hmbx = mbox_setup(MBX_ACC0, pshmdrv_cb, pshm_drv);
if (!pshm_dev->hmbx)
return -ENODEV;
else
return 0;
}
static int __init caif_shmdev_init(void)
{
int i, result;
for (i = 0; i < MAX_SHM_INSTANCES; i++) {
shmdev_lyr[i].shm_base_addr = shm_start;
shmdev_lyr[i].shm_total_sz = shm_size;
if (((char *)shmdev_lyr[i].shm_base_addr == NULL)
|| (shmdev_lyr[i].shm_total_sz <= 0)) {
pr_warn("ERROR,"
"Shared memory Address and/or Size incorrect"
", Bailing out ...\n");
result = -EINVAL;
goto clean;
}
pr_info("SHM AREA (instance %d) STARTS"
" AT %p\n", i, (char *)shmdev_lyr[i].shm_base_addr);
shmdev_lyr[i].shm_id = i;
shmdev_lyr[i].pshmdev_mbxsend = shmdev_send_msg;
shmdev_lyr[i].pshmdev_mbxsetup = shmdev_mbx_setup;
result = caif_shmcore_probe(&shmdev_lyr[i]);
if (result) {
pr_warn("ERROR[%d],"
"Could not probe SHM core (instance %d)"
" Bailing out ...\n", result, i);
goto clean;
}
}
return 0;
clean:
for (i = 0; i < MAX_SHM_INSTANCES; i++) {
if (shmdev_lyr[i].pshm_netdev)
unregister_netdev(shmdev_lyr[i].pshm_netdev);
}
return result;
}
static void __exit caif_shmdev_exit(void)
{
int i;
for (i = 0; i < MAX_SHM_INSTANCES; i++) {
caif_shmcore_remove(shmdev_lyr[i].pshm_netdev);
kfree((void *)shmdev_lyr[i].shm_base_addr);
}
}
