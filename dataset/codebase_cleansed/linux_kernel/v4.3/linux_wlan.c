static int linux_wlan_device_power(int on_off)
{
PRINT_D(INIT_DBG, "linux_wlan_device_power.. (%d)\n", on_off);
if (on_off) {
_linux_wlan_device_power_on();
} else {
_linux_wlan_device_power_off();
}
return 0;
}
static int linux_wlan_device_detection(int on_off)
{
PRINT_D(INIT_DBG, "linux_wlan_device_detection.. (%d)\n", on_off);
#ifdef WILC_SDIO
if (on_off) {
_linux_wlan_device_detection();
} else {
_linux_wlan_device_removal();
}
#endif
return 0;
}
void printk_later(const char *format, ...)
{
va_list args;
va_start(args, format);
ps8current += vsprintf(ps8current, format, args);
va_end(args);
if ((ps8current - DebugBuffer) > DEGUG_BUFFER_LENGTH)
ps8current = DebugBuffer;
}
void dump_logs(void)
{
if (DebugBuffer[0]) {
DebugBuffer[DEGUG_BUFFER_LENGTH] = 0;
PRINT_INFO(GENERIC_DBG, "early printed\n");
PRINT_D(GENERIC_DBG, ps8current + 1);
ps8current[1] = 0;
PRINT_INFO(GENERIC_DBG, "latest printed\n");
PRINT_D(GENERIC_DBG, DebugBuffer);
DebugBuffer[0] = 0;
ps8current = DebugBuffer;
}
}
void Reset_WatchDogdebugger(void)
{
WatchDogdebuggerCounter = 0;
}
static int DebuggingThreadTask(void *vp)
{
while (1) {
while (!WatchDogdebuggerCounter) {
PRINT_D(GENERIC_DBG, "Debug Thread Running %d\n", timeNo);
WatchDogdebuggerCounter = 1;
msleep(10000);
}
dump_logs();
WatchDogdebuggerCounter = 0;
}
}
static int dev_state_ev_handler(struct notifier_block *this, unsigned long event, void *ptr)
{
struct in_ifaddr *dev_iface = (struct in_ifaddr *)ptr;
struct WILC_WFI_priv *priv;
tstrWILC_WFIDrv *pstrWFIDrv;
struct net_device *dev;
u8 *pIP_Add_buff;
perInterface_wlan_t *nic;
u8 null_ip[4] = {0};
char wlan_dev_name[5] = "wlan0";
if (dev_iface == NULL || dev_iface->ifa_dev == NULL || dev_iface->ifa_dev->dev == NULL) {
PRINT_D(GENERIC_DBG, "dev_iface = NULL\n");
return NOTIFY_DONE;
}
if ((memcmp(dev_iface->ifa_label, "wlan0", 5)) && (memcmp(dev_iface->ifa_label, "p2p0", 4))) {
PRINT_D(GENERIC_DBG, "Interface is neither WLAN0 nor P2P0\n");
return NOTIFY_DONE;
}
dev = (struct net_device *)dev_iface->ifa_dev->dev;
if (dev->ieee80211_ptr == NULL || dev->ieee80211_ptr->wiphy == NULL) {
PRINT_D(GENERIC_DBG, "No Wireless registerd\n");
return NOTIFY_DONE;
}
priv = wiphy_priv(dev->ieee80211_ptr->wiphy);
if (priv == NULL) {
PRINT_D(GENERIC_DBG, "No Wireless Priv\n");
return NOTIFY_DONE;
}
pstrWFIDrv = (tstrWILC_WFIDrv *)priv->hWILCWFIDrv;
nic = netdev_priv(dev);
if (nic == NULL || pstrWFIDrv == NULL) {
PRINT_D(GENERIC_DBG, "No Wireless Priv\n");
return NOTIFY_DONE;
}
PRINT_INFO(GENERIC_DBG, "dev_state_ev_handler +++\n");
switch (event) {
case NETDEV_UP:
PRINT_D(GENERIC_DBG, "dev_state_ev_handler event=NETDEV_UP %p\n", dev);
PRINT_INFO(GENERIC_DBG, "\n ============== IP Address Obtained ===============\n\n");
if (nic->iftype == STATION_MODE || nic->iftype == CLIENT_MODE) {
pstrWFIDrv->IFC_UP = 1;
g_obtainingIP = false;
del_timer(&hDuringIpTimer);
PRINT_D(GENERIC_DBG, "IP obtained , enable scan\n");
}
if (bEnablePS)
host_int_set_power_mgmt(pstrWFIDrv, 1, 0);
PRINT_D(GENERIC_DBG, "[%s] Up IP\n", dev_iface->ifa_label);
pIP_Add_buff = (char *) (&(dev_iface->ifa_address));
PRINT_D(GENERIC_DBG, "IP add=%d:%d:%d:%d\n", pIP_Add_buff[0], pIP_Add_buff[1], pIP_Add_buff[2], pIP_Add_buff[3]);
host_int_setup_ipaddress(pstrWFIDrv, pIP_Add_buff, nic->u8IfIdx);
break;
case NETDEV_DOWN:
PRINT_D(GENERIC_DBG, "dev_state_ev_handler event=NETDEV_DOWN %p\n", dev);
PRINT_INFO(GENERIC_DBG, "\n ============== IP Address Released ===============\n\n");
if (nic->iftype == STATION_MODE || nic->iftype == CLIENT_MODE) {
pstrWFIDrv->IFC_UP = 0;
g_obtainingIP = false;
}
if (memcmp(dev_iface->ifa_label, wlan_dev_name, 5) == 0)
host_int_set_power_mgmt(pstrWFIDrv, 0, 0);
resolve_disconnect_aberration(pstrWFIDrv);
PRINT_D(GENERIC_DBG, "[%s] Down IP\n", dev_iface->ifa_label);
pIP_Add_buff = null_ip;
PRINT_D(GENERIC_DBG, "IP add=%d:%d:%d:%d\n", pIP_Add_buff[0], pIP_Add_buff[1], pIP_Add_buff[2], pIP_Add_buff[3]);
host_int_setup_ipaddress(pstrWFIDrv, pIP_Add_buff, nic->u8IfIdx);
break;
default:
PRINT_INFO(GENERIC_DBG, "dev_state_ev_handler event=default\n");
PRINT_INFO(GENERIC_DBG, "[%s] unknown dev event: %lu\n", dev_iface->ifa_label, event);
break;
}
return NOTIFY_DONE;
}
void linux_wlan_enable_irq(void)
{
#if (RX_BH_TYPE != RX_BH_THREADED_IRQ)
#if (defined WILC_SPI) || (defined WILC_SDIO_IRQ_GPIO)
PRINT_D(INT_DBG, "Enabling IRQ ...\n");
enable_irq(g_linux_wlan->dev_irq_num);
#endif
#endif
}
void linux_wlan_disable_irq(int wait)
{
#if (defined WILC_SPI) || (defined WILC_SDIO_IRQ_GPIO)
if (wait) {
PRINT_D(INT_DBG, "Disabling IRQ ...\n");
disable_irq(g_linux_wlan->dev_irq_num);
} else {
PRINT_D(INT_DBG, "Disabling IRQ ...\n");
disable_irq_nosync(g_linux_wlan->dev_irq_num);
}
#endif
}
static irqreturn_t isr_uh_routine(int irq, void *user_data)
{
int_rcvdU++;
#if (RX_BH_TYPE != RX_BH_THREADED_IRQ)
linux_wlan_disable_irq(IRQ_NO_WAIT);
#endif
PRINT_D(INT_DBG, "Interrupt received UH\n");
if (g_linux_wlan->close) {
PRINT_ER("Driver is CLOSING: Can't handle UH interrupt\n");
#if (RX_BH_TYPE == RX_BH_THREADED_IRQ)
return IRQ_HANDLED;
#else
return IRQ_NONE;
#endif
}
#if (RX_BH_TYPE == RX_BH_WORK_QUEUE)
schedule_work(&g_linux_wlan->rx_work_queue);
return IRQ_HANDLED;
#elif (RX_BH_TYPE == RX_BH_KTHREAD)
linux_wlan_unlock(&g_linux_wlan->rx_sem);
return IRQ_HANDLED;
#elif (RX_BH_TYPE == RX_BH_THREADED_IRQ)
return IRQ_WAKE_THREAD;
#endif
}
static void isr_bh_routine(struct work_struct *work)
{
perInterface_wlan_t *nic;
nic = (perInterface_wlan_t *)container_of(work, linux_wlan_t, rx_work_queue);
#endif
if (g_linux_wlan->close) {
PRINT_ER("Driver is CLOSING: Can't handle BH interrupt\n");
#if (RX_BH_TYPE == RX_BH_THREADED_IRQ)
return IRQ_HANDLED;
#else
return;
#endif
}
int_rcvdB++;
PRINT_D(INT_DBG, "Interrupt received BH\n");
if (g_linux_wlan->oup.wlan_handle_rx_isr != 0)
g_linux_wlan->oup.wlan_handle_rx_isr();
else
PRINT_ER("wlan_handle_rx_isr() hasn't been initialized\n");
#if (RX_BH_TYPE == RX_BH_THREADED_IRQ)
return IRQ_HANDLED;
#endif
}
static int isr_bh_routine(void *vp)
{
linux_wlan_t *nic;
nic = (linux_wlan_t *)vp;
while (1) {
linux_wlan_lock(&nic->rx_sem);
if (g_linux_wlan->close) {
while (!kthread_should_stop())
schedule();
break;
}
int_rcvdB++;
PRINT_D(INT_DBG, "Interrupt received BH\n");
if (g_linux_wlan->oup.wlan_handle_rx_isr != 0)
g_linux_wlan->oup.wlan_handle_rx_isr();
else
PRINT_ER("wlan_handle_rx_isr() hasn't been initialized\n");
}
return 0;
}
static void deinit_irq(linux_wlan_t *nic)
{
#if (defined WILC_SPI) || (defined WILC_SDIO_IRQ_GPIO)
if (&nic->dev_irq_num != 0) {
free_irq(nic->dev_irq_num, g_linux_wlan);
gpio_free(GPIO_NUM);
}
#endif
}
static void linux_wlan_msleep(uint32_t msc)
{
if (msc <= 4000000) {
u32 u32Temp = msc * 1000;
usleep_range(u32Temp, u32Temp);
} else {
msleep(msc);
}
}
static void linux_wlan_atomic_msleep(uint32_t msc)
{
mdelay(msc);
}
static void linux_wlan_dbg(uint8_t *buff)
{
PRINT_D(INIT_DBG, "%d\n", *buff);
}
static void *linux_wlan_malloc_atomic(uint32_t sz)
{
char *pntr = NULL;
pntr = kmalloc(sz, GFP_ATOMIC);
PRINT_D(MEM_DBG, "Allocating %d bytes at address %p\n", sz, pntr);
return (void *)pntr;
}
static void *linux_wlan_malloc(uint32_t sz)
{
char *pntr = NULL;
pntr = kmalloc(sz, GFP_KERNEL);
PRINT_D(MEM_DBG, "Allocating %d bytes at address %p\n", sz, pntr);
return (void *)pntr;
}
void linux_wlan_free(void *vp)
{
if (vp != NULL) {
PRINT_D(MEM_DBG, "Freeing %p\n", vp);
kfree(vp);
}
}
static void *internal_alloc(uint32_t size, uint32_t flag)
{
char *pntr = NULL;
pntr = kmalloc(size, flag);
PRINT_D(MEM_DBG, "Allocating %d bytes at address %p\n", size, pntr);
return (void *)pntr;
}
static void linux_wlan_init_lock(char *lockName, void *plock, int count)
{
sema_init((struct semaphore *)plock, count);
PRINT_D(LOCK_DBG, "Initializing [%s][%p]\n", lockName, plock);
}
static void linux_wlan_deinit_lock(void *plock)
{
}
static void linux_wlan_lock(void *vp)
{
PRINT_D(LOCK_DBG, "Locking %p\n", vp);
if (vp != NULL) {
while (down_interruptible((struct semaphore *) vp))
;
} else {
PRINT_ER("Failed, mutex is NULL\n");
}
}
static int linux_wlan_lock_timeout(void *vp, u32 timeout)
{
int error = -1;
PRINT_D(LOCK_DBG, "Locking %p\n", vp);
if (vp != NULL)
error = down_timeout((struct semaphore *)vp, msecs_to_jiffies(timeout));
else
PRINT_ER("Failed, mutex is NULL\n");
return error;
}
void linux_wlan_unlock(void *vp)
{
PRINT_D(LOCK_DBG, "Unlocking %p\n", vp);
if (vp != NULL)
up((struct semaphore *)vp);
else
PRINT_ER("Failed, mutex is NULL\n");
}
static void linux_wlan_init_mutex(char *lockName, void *plock, int count)
{
mutex_init((struct mutex *)plock);
PRINT_D(LOCK_DBG, "Initializing mutex [%s][%p]\n", lockName, plock);
}
static void linux_wlan_deinit_mutex(void *plock)
{
mutex_destroy((struct mutex *)plock);
}
static void linux_wlan_lock_mutex(void *vp)
{
PRINT_D(LOCK_DBG, "Locking mutex %p\n", vp);
if (vp != NULL) {
mutex_lock((struct mutex *)vp);
} else {
PRINT_ER("Failed, mutex is NULL\n");
}
}
static void linux_wlan_unlock_mutex(void *vp)
{
PRINT_D(LOCK_DBG, "Unlocking mutex %p\n", vp);
if (vp != NULL) {
if (mutex_is_locked((struct mutex *)vp)) {
mutex_unlock((struct mutex *)vp);
} else {
}
} else {
PRINT_ER("Failed, mutex is NULL\n");
}
}
static void linux_wlan_init_spin_lock(char *lockName, void *plock, int count)
{
spin_lock_init((spinlock_t *)plock);
PRINT_D(SPIN_DEBUG, "Initializing mutex [%s][%p]\n", lockName, plock);
}
static void linux_wlan_deinit_spin_lock(void *plock)
{
}
static void linux_wlan_spin_lock(void *vp, unsigned long *flags)
{
unsigned long lflags;
PRINT_D(SPIN_DEBUG, "Lock spin %p\n", vp);
if (vp != NULL) {
spin_lock_irqsave((spinlock_t *)vp, lflags);
*flags = lflags;
} else {
PRINT_ER("Failed, spin lock is NULL\n");
}
}
static void linux_wlan_spin_unlock(void *vp, unsigned long *flags)
{
unsigned long lflags = *flags;
PRINT_D(SPIN_DEBUG, "Unlock spin %p\n", vp);
if (vp != NULL) {
spin_unlock_irqrestore((spinlock_t *)vp, lflags);
*flags = lflags;
} else {
PRINT_ER("Failed, spin lock is NULL\n");
}
}
static void linux_wlan_mac_indicate(int flag)
{
linux_wlan_t *pd = g_linux_wlan;
int status;
if (flag == WILC_MAC_INDICATE_STATUS) {
pd->oup.wlan_cfg_get_value(WID_STATUS, (unsigned char *)&status, 4);
if (pd->mac_status == WILC_MAC_STATUS_INIT) {
pd->mac_status = status;
linux_wlan_unlock(&pd->sync_event);
} else {
pd->mac_status = status;
}
if (pd->mac_status == WILC_MAC_STATUS_CONNECT) {
}
} else if (flag == WILC_MAC_INDICATE_SCAN) {
PRINT_D(GENERIC_DBG, "Scanning ...\n");
}
}
struct net_device *GetIfHandler(uint8_t *pMacHeader)
{
uint8_t *Bssid, *Bssid1;
int i = 0;
Bssid = pMacHeader + 10;
Bssid1 = pMacHeader + 4;
for (i = 0; i < g_linux_wlan->u8NoIfcs; i++) {
if (!memcmp(Bssid1, g_linux_wlan->strInterfaceInfo[i].aBSSID, ETH_ALEN) ||
!memcmp(Bssid, g_linux_wlan->strInterfaceInfo[i].aBSSID, ETH_ALEN)) {
return g_linux_wlan->strInterfaceInfo[i].wilc_netdev;
}
}
PRINT_INFO(INIT_DBG, "Invalide handle\n");
for (i = 0; i < 25; i++)
PRINT_D(INIT_DBG, "%02x ", pMacHeader[i]);
Bssid = pMacHeader + 18;
Bssid1 = pMacHeader + 12;
for (i = 0; i < g_linux_wlan->u8NoIfcs; i++) {
if (!memcmp(Bssid1, g_linux_wlan->strInterfaceInfo[i].aBSSID, ETH_ALEN) ||
!memcmp(Bssid, g_linux_wlan->strInterfaceInfo[i].aBSSID, ETH_ALEN)) {
PRINT_D(INIT_DBG, "Ctx [%p]\n", g_linux_wlan->strInterfaceInfo[i].wilc_netdev);
return g_linux_wlan->strInterfaceInfo[i].wilc_netdev;
}
}
PRINT_INFO(INIT_DBG, "\n");
return NULL;
}
int linux_wlan_set_bssid(struct net_device *wilc_netdev, uint8_t *pBSSID)
{
int i = 0;
int ret = -1;
PRINT_D(INIT_DBG, "set bssid on[%p]\n", wilc_netdev);
for (i = 0; i < g_linux_wlan->u8NoIfcs; i++) {
if (g_linux_wlan->strInterfaceInfo[i].wilc_netdev == wilc_netdev) {
PRINT_D(INIT_DBG, "set bssid [%x][%x][%x]\n", pBSSID[0], pBSSID[1], pBSSID[2]);
memcpy(g_linux_wlan->strInterfaceInfo[i].aBSSID, pBSSID, 6);
ret = 0;
break;
}
}
return ret;
}
int linux_wlan_get_num_conn_ifcs(void)
{
uint8_t i = 0;
uint8_t null_bssid[6] = {0};
uint8_t ret_val = 0;
for (i = 0; i < g_linux_wlan->u8NoIfcs; i++) {
if (memcmp(g_linux_wlan->strInterfaceInfo[i].aBSSID, null_bssid, 6))
ret_val++;
}
return ret_val;
}
static int linux_wlan_rxq_task(void *vp)
{
linux_wlan_unlock(&g_linux_wlan->rxq_thread_started);
while (1) {
linux_wlan_lock(&g_linux_wlan->rxq_event);
if (g_linux_wlan->close) {
linux_wlan_unlock(&g_linux_wlan->rxq_thread_started);
while (!kthread_should_stop())
schedule();
PRINT_D(RX_DBG, " RX thread stopped\n");
break;
}
PRINT_D(RX_DBG, "Calling wlan_handle_rx_que()\n");
g_linux_wlan->oup.wlan_handle_rx_que();
}
return 0;
}
static int linux_wlan_txq_task(void *vp)
{
int ret, txq_count;
#if defined USE_TX_BACKOFF_DELAY_IF_NO_BUFFERS
#define TX_BACKOFF_WEIGHT_INCR_STEP (1)
#define TX_BACKOFF_WEIGHT_DECR_STEP (1)
#define TX_BACKOFF_WEIGHT_MAX (7)
#define TX_BACKOFF_WEIGHT_MIN (0)
#define TX_BACKOFF_WEIGHT_UNIT_MS (10)
int backoff_weight = TX_BACKOFF_WEIGHT_MIN;
#endif
linux_wlan_unlock(&g_linux_wlan->txq_thread_started);
while (1) {
PRINT_D(TX_DBG, "txq_task Taking a nap :)\n");
linux_wlan_lock(&g_linux_wlan->txq_event);
PRINT_D(TX_DBG, "txq_task Who waked me up :$\n");
if (g_linux_wlan->close) {
linux_wlan_unlock(&g_linux_wlan->txq_thread_started);
while (!kthread_should_stop())
schedule();
PRINT_D(TX_DBG, "TX thread stopped\n");
break;
}
PRINT_D(TX_DBG, "txq_task handle the sending packet and let me go to sleep.\n");
#if !defined USE_TX_BACKOFF_DELAY_IF_NO_BUFFERS
g_linux_wlan->oup.wlan_handle_tx_que();
#else
do {
ret = g_linux_wlan->oup.wlan_handle_tx_que(&txq_count);
if (txq_count < FLOW_CONTROL_LOWER_THRESHOLD ) {
PRINT_D(TX_DBG, "Waking up queue\n");
if (netif_queue_stopped(g_linux_wlan->strInterfaceInfo[0].wilc_netdev))
netif_wake_queue(g_linux_wlan->strInterfaceInfo[0].wilc_netdev);
if (netif_queue_stopped(g_linux_wlan->strInterfaceInfo[1].wilc_netdev))
netif_wake_queue(g_linux_wlan->strInterfaceInfo[1].wilc_netdev);
}
if (ret == WILC_TX_ERR_NO_BUF) {
do {
msleep(TX_BACKOFF_WEIGHT_UNIT_MS << backoff_weight);
} while ( 0);
backoff_weight += TX_BACKOFF_WEIGHT_INCR_STEP;
if (backoff_weight > TX_BACKOFF_WEIGHT_MAX)
backoff_weight = TX_BACKOFF_WEIGHT_MAX;
} else {
if (backoff_weight > TX_BACKOFF_WEIGHT_MIN) {
backoff_weight -= TX_BACKOFF_WEIGHT_DECR_STEP;
if (backoff_weight < TX_BACKOFF_WEIGHT_MIN)
backoff_weight = TX_BACKOFF_WEIGHT_MIN;
}
}
} while (ret == WILC_TX_ERR_NO_BUF && !g_linux_wlan->close);
#endif
}
return 0;
}
static void linux_wlan_rx_complete(void)
{
PRINT_D(RX_DBG, "RX completed\n");
}
int linux_wlan_get_firmware(perInterface_wlan_t *p_nic)
{
perInterface_wlan_t *nic = p_nic;
int ret = 0;
const struct firmware *wilc_firmware;
char *firmware;
if (nic->iftype == AP_MODE)
firmware = AP_FIRMWARE;
else if (nic->iftype == STATION_MODE)
firmware = STA_FIRMWARE;
else {
PRINT_D(INIT_DBG, "Get P2P_CONCURRENCY_FIRMWARE\n");
firmware = P2P_CONCURRENCY_FIRMWARE;
}
if (nic == NULL) {
PRINT_ER("NIC is NULL\n");
goto _fail_;
}
if (&nic->wilc_netdev->dev == NULL) {
PRINT_ER("&nic->wilc_netdev->dev is NULL\n");
goto _fail_;
}
#ifdef WILC_SDIO
if (request_firmware(&wilc_firmware, firmware, &g_linux_wlan->wilc_sdio_func->dev) != 0) {
PRINT_ER("%s - firmare not available\n", firmware);
ret = -1;
goto _fail_;
}
#else
if (request_firmware(&wilc_firmware, firmware, &g_linux_wlan->wilc_spidev->dev) != 0) {
PRINT_ER("%s - firmare not available\n", firmware);
ret = -1;
goto _fail_;
}
#endif
g_linux_wlan->wilc_firmware = wilc_firmware;
_fail_:
return ret;
}
static int linux_wlan_start_firmware(perInterface_wlan_t *nic)
{
int ret = 0;
PRINT_D(INIT_DBG, "Starting Firmware ...\n");
ret = g_linux_wlan->oup.wlan_start();
if (ret < 0) {
PRINT_ER("Failed to start Firmware\n");
goto _fail_;
}
PRINT_D(INIT_DBG, "Waiting for Firmware to get ready ...\n");
ret = linux_wlan_lock_timeout(&g_linux_wlan->sync_event, 5000);
if (ret) {
#ifdef COMPLEMENT_BOOT
static int timeout = 5;
if (timeout--) {
PRINT_D(INIT_DBG, "repeat power cycle[%d]", timeout);
ret = repeat_power_cycle(nic);
} else {
timeout = 5;
ret = -1;
goto _fail_;
}
#endif
PRINT_D(INIT_DBG, "Firmware start timed out");
goto _fail_;
}
PRINT_D(INIT_DBG, "Firmware successfully started\n");
_fail_:
return ret;
}
static int linux_wlan_firmware_download(linux_wlan_t *p_nic)
{
int ret = 0;
if (g_linux_wlan->wilc_firmware == NULL) {
PRINT_ER("Firmware buffer is NULL\n");
ret = -ENOBUFS;
goto _FAIL_;
}
PRINT_D(INIT_DBG, "Downloading Firmware ...\n");
ret = g_linux_wlan->oup.wlan_firmware_download(g_linux_wlan->wilc_firmware->data, g_linux_wlan->wilc_firmware->size);
if (ret < 0)
goto _FAIL_;
PRINT_D(INIT_DBG, "Freeing FW buffer ...\n");
PRINT_D(INIT_DBG, "Releasing firmware\n");
release_firmware(g_linux_wlan->wilc_firmware);
g_linux_wlan->wilc_firmware = NULL;
PRINT_D(INIT_DBG, "Download Succeeded\n");
_FAIL_:
return ret;
}
static int linux_wlan_init_test_config(struct net_device *dev, linux_wlan_t *p_nic)
{
unsigned char c_val[64];
#ifndef STATIC_MACADDRESS
unsigned char mac_add[] = {0x00, 0x80, 0xC2, 0x5E, 0xa2, 0xff};
#endif
struct WILC_WFI_priv *priv;
tstrWILC_WFIDrv *pstrWFIDrv;
PRINT_D(TX_DBG, "Start configuring Firmware\n");
#ifndef STATIC_MACADDRESS
get_random_bytes(&mac_add[5], 1);
get_random_bytes(&mac_add[4], 1);
#endif
priv = wiphy_priv(dev->ieee80211_ptr->wiphy);
pstrWFIDrv = (tstrWILC_WFIDrv *)priv->hWILCWFIDrv;
PRINT_D(INIT_DBG, "Host = %p\n", pstrWFIDrv);
PRINT_D(INIT_DBG, "MAC address is : %02x-%02x-%02x-%02x-%02x-%02x\n", mac_add[0], mac_add[1], mac_add[2], mac_add[3], mac_add[4], mac_add[5]);
wilc_get_chipid(0);
if (g_linux_wlan->oup.wlan_cfg_set == NULL) {
PRINT_D(INIT_DBG, "Null p[ointer\n");
goto _fail_;
}
*(int *)c_val = (u32)pstrWFIDrv;
if (!g_linux_wlan->oup.wlan_cfg_set(1, WID_SET_DRV_HANDLER, c_val, 4, 0, 0))
goto _fail_;
c_val[0] = 0;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_PC_TEST_MODE, c_val, 1, 0, 0))
goto _fail_;
c_val[0] = INFRASTRUCTURE;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_BSS_TYPE, c_val, 1, 0, 0))
goto _fail_;
c_val[0] = RATE_AUTO;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_CURRENT_TX_RATE, c_val, 1, 0, 0))
goto _fail_;
c_val[0] = G_MIXED_11B_2_MODE;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_11G_OPERATING_MODE, c_val, 1, 0, 0))
goto _fail_;
c_val[0] = 1;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_CURRENT_CHANNEL, c_val, 1, 0, 0))
goto _fail_;
c_val[0] = G_SHORT_PREAMBLE;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_PREAMBLE, c_val, 1, 0, 0))
goto _fail_;
c_val[0] = AUTO_PROT;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_11N_PROT_MECH, c_val, 1, 0, 0))
goto _fail_;
#ifdef SWITCH_LOG_TERMINAL
c_val[0] = AUTO_PROT;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_LOGTerminal_Switch, c_val, 1, 0, 0))
goto _fail_;
#endif
c_val[0] = ACTIVE_SCAN;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_SCAN_TYPE, c_val, 1, 0, 0))
goto _fail_;
c_val[0] = SITE_SURVEY_OFF;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_SITE_SURVEY, c_val, 1, 0, 0))
goto _fail_;
*((int *)c_val) = 0xffff;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_RTS_THRESHOLD, c_val, 2, 0, 0))
goto _fail_;
*((int *)c_val) = 2346;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_FRAG_THRESHOLD, c_val, 2, 0, 0))
goto _fail_;
#ifndef USE_WIRELESS
strcpy(c_val, "nwifi");
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_SSID, c_val, (strlen(c_val) + 1), 0, 0))
goto _fail_;
#endif
c_val[0] = 0;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_BCAST_SSID, c_val, 1, 0, 0))
goto _fail_;
c_val[0] = 1;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_QOS_ENABLE, c_val, 1, 0, 0))
goto _fail_;
c_val[0] = NO_POWERSAVE;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_POWER_MANAGEMENT, c_val, 1, 0, 0))
goto _fail_;
c_val[0] = NO_ENCRYPT;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_11I_MODE, c_val, 1, 0, 0))
goto _fail_;
c_val[0] = OPEN_SYSTEM;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_AUTH_TYPE, c_val, 1, 0, 0))
goto _fail_;
strcpy(c_val, "123456790abcdef1234567890");
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_WEP_KEY_VALUE, c_val, (strlen(c_val) + 1), 0, 0))
goto _fail_;
strcpy(c_val, "12345678");
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_11I_PSK, c_val, (strlen(c_val)), 0, 0))
goto _fail_;
strcpy(c_val, "password");
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_1X_KEY, c_val, (strlen(c_val) + 1), 0, 0))
goto _fail_;
c_val[0] = 192;
c_val[1] = 168;
c_val[2] = 1;
c_val[3] = 112;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_1X_SERV_ADDR, c_val, 4, 0, 0))
goto _fail_;
c_val[0] = 3;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_LISTEN_INTERVAL, c_val, 1, 0, 0))
goto _fail_;
c_val[0] = 3;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_DTIM_PERIOD, c_val, 1, 0, 0))
goto _fail_;
c_val[0] = NORMAL_ACK;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_ACK_POLICY, c_val, 1, 0, 0))
goto _fail_;
c_val[0] = 0;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_USER_CONTROL_ON_TX_POWER, c_val, 1, 0, 0))
goto _fail_;
c_val[0] = 48;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_TX_POWER_LEVEL_11A, c_val, 1, 0, 0))
goto _fail_;
c_val[0] = 28;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_TX_POWER_LEVEL_11B, c_val, 1, 0, 0))
goto _fail_;
*((int *)c_val) = 100;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_BEACON_INTERVAL, c_val, 2, 0, 0))
goto _fail_;
c_val[0] = REKEY_DISABLE;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_REKEY_POLICY, c_val, 1, 0, 0))
goto _fail_;
*((int *)c_val) = 84600;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_REKEY_PERIOD, c_val, 4, 0, 0))
goto _fail_;
*((int *)c_val) = 500;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_REKEY_PACKET_COUNT, c_val, 4, 0, 0))
goto _fail_;
c_val[0] = 1;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_SHORT_SLOT_ALLOWED, c_val, 1, 0, 0))
goto _fail_;
c_val[0] = G_SELF_CTS_PROT;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_11N_ERP_PROT_TYPE, c_val, 1, 0, 0))
goto _fail_;
c_val[0] = 1;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_11N_ENABLE, c_val, 1, 0, 0))
goto _fail_;
c_val[0] = HT_MIXED_MODE;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_11N_OPERATING_MODE, c_val, 1, 0, 0))
goto _fail_;
c_val[0] = 1;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_11N_TXOP_PROT_DISABLE, c_val, 1, 0, 0))
goto _fail_;
memcpy(c_val, mac_add, 6);
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_MAC_ADDR, c_val, 6, 0, 0))
goto _fail_;
c_val[0] = DETECT_PROTECT_REPORT;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_11N_OBSS_NONHT_DETECTION, c_val, 1, 0, 0))
goto _fail_;
c_val[0] = RTS_CTS_NONHT_PROT;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_11N_HT_PROT_TYPE, c_val, 1, 0, 0))
goto _fail_;
c_val[0] = 0;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_11N_RIFS_PROT_ENABLE, c_val, 1, 0, 0))
goto _fail_;
c_val[0] = MIMO_MODE;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_11N_SMPS_MODE, c_val, 1, 0, 0))
goto _fail_;
c_val[0] = 7;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_11N_CURRENT_TX_MCS, c_val, 1, 0, 0))
goto _fail_;
c_val[0] = 1;
if (!g_linux_wlan->oup.wlan_cfg_set(0, WID_11N_IMMEDIATE_BA_ENABLED, c_val, 1, 1, (u32)pstrWFIDrv))
goto _fail_;
return 0;
_fail_:
return -1;
}
void wilc1000_wlan_deinit(linux_wlan_t *nic)
{
if (g_linux_wlan->wilc1000_initialized) {
printk("Deinitializing wilc1000 ...\n");
if (nic == NULL) {
PRINT_ER("nic is NULL\n");
return;
}
#if defined(PLAT_ALLWINNER_A20) || defined(PLAT_ALLWINNER_A23) || defined(PLAT_ALLWINNER_A31)
PRINT_D(INIT_DBG, "skip wilc_bus_set_default_speed\n");
#else
wilc_bus_set_default_speed();
#endif
PRINT_D(INIT_DBG, "Disabling IRQ\n");
#if (!defined WILC_SDIO) || (defined WILC_SDIO_IRQ_GPIO)
linux_wlan_disable_irq(IRQ_WAIT);
#else
#if defined(PLAT_ALLWINNER_A20) || defined(PLAT_ALLWINNER_A23) || defined(PLAT_ALLWINNER_A31)
#else
linux_wlan_lock_mutex((void *)&g_linux_wlan->hif_cs);
disable_sdio_interrupt();
linux_wlan_unlock_mutex((void *)&g_linux_wlan->hif_cs);
#endif
#endif
if (&g_linux_wlan->rxq_event != NULL)
linux_wlan_unlock(&g_linux_wlan->rxq_event);
if (&g_linux_wlan->txq_event != NULL)
linux_wlan_unlock(&g_linux_wlan->txq_event);
#if (RX_BH_TYPE == RX_BH_WORK_QUEUE)
if (&g_linux_wlan->rx_work_queue != NULL)
flush_work(&g_linux_wlan->rx_work_queue);
#elif (RX_BH_TYPE == RX_BH_KTHREAD)
#endif
PRINT_D(INIT_DBG, "Deinitializing Threads\n");
wlan_deinitialize_threads(nic);
PRINT_D(INIT_DBG, "Deinitializing IRQ\n");
deinit_irq(g_linux_wlan);
if (&g_linux_wlan->oup != NULL) {
if (g_linux_wlan->oup.wlan_stop != NULL)
g_linux_wlan->oup.wlan_stop();
}
PRINT_D(INIT_DBG, "Deinitializing WILC Wlan\n");
wilc_wlan_deinit(nic);
#if (defined WILC_SDIO) && (!defined WILC_SDIO_IRQ_GPIO)
#if defined(PLAT_ALLWINNER_A20) || defined(PLAT_ALLWINNER_A23) || defined(PLAT_ALLWINNER_A31)
PRINT_D(INIT_DBG, "Disabling IRQ 2\n");
linux_wlan_lock_mutex((void *)&g_linux_wlan->hif_cs);
disable_sdio_interrupt();
linux_wlan_unlock_mutex((void *)&g_linux_wlan->hif_cs);
#endif
#endif
PRINT_D(INIT_DBG, "Deinitializing Locks\n");
wlan_deinit_locks(g_linux_wlan);
g_linux_wlan->wilc1000_initialized = 0;
PRINT_D(INIT_DBG, "wilc1000 deinitialization Done\n");
} else {
PRINT_D(INIT_DBG, "wilc1000 is not initialized\n");
}
}
int wlan_init_locks(linux_wlan_t *p_nic)
{
PRINT_D(INIT_DBG, "Initializing Locks ...\n");
linux_wlan_init_mutex("hif_lock/hif_cs", &g_linux_wlan->hif_cs, 1);
linux_wlan_init_mutex("rxq_lock/rxq_cs", &g_linux_wlan->rxq_cs, 1);
linux_wlan_init_mutex("txq_lock/txq_cs", &g_linux_wlan->txq_cs, 1);
linux_wlan_init_spin_lock("txq_spin_lock/txq_cs", &g_linux_wlan->txq_spinlock, 1);
linux_wlan_init_lock("txq_add_to_head_lock/txq_cs", &g_linux_wlan->txq_add_to_head_cs, 1);
linux_wlan_init_lock("txq_wait/txq_event", &g_linux_wlan->txq_event, 0);
linux_wlan_init_lock("rxq_wait/rxq_event", &g_linux_wlan->rxq_event, 0);
linux_wlan_init_lock("cfg_wait/cfg_event", &g_linux_wlan->cfg_event, 0);
linux_wlan_init_lock("sync_event", &g_linux_wlan->sync_event, 0);
linux_wlan_init_lock("rxq_lock/rxq_started", &g_linux_wlan->rxq_thread_started, 0);
linux_wlan_init_lock("rxq_lock/txq_started", &g_linux_wlan->txq_thread_started, 0);
#if (RX_BH_TYPE == RX_BH_KTHREAD)
linux_wlan_init_lock("BH_SEM", &g_linux_wlan->rx_sem, 0);
#endif
return 0;
}
static int wlan_deinit_locks(linux_wlan_t *nic)
{
PRINT_D(INIT_DBG, "De-Initializing Locks\n");
if (&g_linux_wlan->hif_cs != NULL)
linux_wlan_deinit_mutex(&g_linux_wlan->hif_cs);
if (&g_linux_wlan->rxq_cs != NULL)
linux_wlan_deinit_mutex(&g_linux_wlan->rxq_cs);
if (&g_linux_wlan->txq_cs != NULL)
linux_wlan_deinit_mutex(&g_linux_wlan->txq_cs);
if (&g_linux_wlan->txq_spinlock != NULL)
linux_wlan_deinit_spin_lock(&g_linux_wlan->txq_spinlock);
if (&g_linux_wlan->rxq_event != NULL)
linux_wlan_deinit_lock(&g_linux_wlan->rxq_event);
if (&g_linux_wlan->txq_event != NULL)
linux_wlan_deinit_lock(&g_linux_wlan->txq_event);
if (&g_linux_wlan->txq_add_to_head_cs != NULL)
linux_wlan_deinit_lock(&g_linux_wlan->txq_add_to_head_cs);
if (&g_linux_wlan->rxq_thread_started != NULL)
linux_wlan_deinit_lock(&g_linux_wlan->rxq_thread_started);
if (&g_linux_wlan->txq_thread_started != NULL)
linux_wlan_deinit_lock(&g_linux_wlan->txq_thread_started);
if (&g_linux_wlan->cfg_event != NULL)
linux_wlan_deinit_lock(&g_linux_wlan->cfg_event);
if (&g_linux_wlan->sync_event != NULL)
linux_wlan_deinit_lock(&g_linux_wlan->sync_event);
return 0;
}
void linux_to_wlan(wilc_wlan_inp_t *nwi, linux_wlan_t *nic)
{
PRINT_D(INIT_DBG, "Linux to Wlan services ...\n");
nwi->os_context.hif_critical_section = (void *)&g_linux_wlan->hif_cs;
nwi->os_context.os_private = (void *)nic;
nwi->os_context.tx_buffer_size = LINUX_TX_SIZE;
nwi->os_context.txq_critical_section = (void *)&g_linux_wlan->txq_cs;
nwi->os_context.txq_add_to_head_critical_section = (void *)&g_linux_wlan->txq_add_to_head_cs;
nwi->os_context.txq_spin_lock = (void *)&g_linux_wlan->txq_spinlock;
nwi->os_context.txq_wait_event = (void *)&g_linux_wlan->txq_event;
#if defined(MEMORY_STATIC)
nwi->os_context.rx_buffer_size = LINUX_RX_SIZE;
#endif
nwi->os_context.rxq_critical_section = (void *)&g_linux_wlan->rxq_cs;
nwi->os_context.rxq_wait_event = (void *)&g_linux_wlan->rxq_event;
nwi->os_context.cfg_wait_event = (void *)&g_linux_wlan->cfg_event;
nwi->os_func.os_sleep = linux_wlan_msleep;
nwi->os_func.os_atomic_sleep = linux_wlan_atomic_msleep;
nwi->os_func.os_debug = linux_wlan_dbg;
nwi->os_func.os_malloc = linux_wlan_malloc;
nwi->os_func.os_malloc_atomic = linux_wlan_malloc_atomic;
nwi->os_func.os_free = linux_wlan_free;
nwi->os_func.os_lock = linux_wlan_lock;
nwi->os_func.os_unlock = linux_wlan_unlock;
nwi->os_func.os_wait = linux_wlan_lock_timeout;
nwi->os_func.os_signal = linux_wlan_unlock;
nwi->os_func.os_enter_cs = linux_wlan_lock_mutex;
nwi->os_func.os_leave_cs = linux_wlan_unlock_mutex;
nwi->os_func.os_spin_lock = linux_wlan_spin_lock;
nwi->os_func.os_spin_unlock = linux_wlan_spin_unlock;
#ifdef WILC_SDIO
nwi->io_func.io_type = HIF_SDIO;
nwi->io_func.io_init = linux_sdio_init;
nwi->io_func.io_deinit = linux_sdio_deinit;
nwi->io_func.u.sdio.sdio_cmd52 = linux_sdio_cmd52;
nwi->io_func.u.sdio.sdio_cmd53 = linux_sdio_cmd53;
nwi->io_func.u.sdio.sdio_set_max_speed = linux_sdio_set_max_speed;
nwi->io_func.u.sdio.sdio_set_default_speed = linux_sdio_set_default_speed;
#else
nwi->io_func.io_type = HIF_SPI;
nwi->io_func.io_init = linux_spi_init;
nwi->io_func.io_deinit = linux_spi_deinit;
nwi->io_func.u.spi.spi_tx = linux_spi_write;
nwi->io_func.u.spi.spi_rx = linux_spi_read;
nwi->io_func.u.spi.spi_trx = linux_spi_write_read;
nwi->io_func.u.spi.spi_max_speed = linux_spi_set_max_speed;
#endif
#ifdef WILC_FULLY_HOSTING_AP
nwi->net_func.rx_indicate = WILC_Process_rx_frame;
#else
nwi->net_func.rx_indicate = frmw_to_linux;
#endif
nwi->net_func.rx_complete = linux_wlan_rx_complete;
nwi->indicate_func.mac_indicate = linux_wlan_mac_indicate;
}
int wlan_initialize_threads(perInterface_wlan_t *nic)
{
int ret = 0;
PRINT_D(INIT_DBG, "Initializing Threads ...\n");
#if (RX_BH_TYPE == RX_BH_WORK_QUEUE)
INIT_WORK(&g_linux_wlan->rx_work_queue, isr_bh_routine);
#elif (RX_BH_TYPE == RX_BH_KTHREAD)
PRINT_D(INIT_DBG, "Creating kthread for Rxq BH\n");
g_linux_wlan->rx_bh_thread = kthread_run(isr_bh_routine, (void *)g_linux_wlan, "K_RXQ_BH");
if (g_linux_wlan->rx_bh_thread == 0) {
PRINT_ER("couldn't create RX BH thread\n");
ret = -ENOBUFS;
goto _fail_;
}
#endif
#ifndef TCP_ENHANCEMENTS
PRINT_D(INIT_DBG, "Creating kthread for reception\n");
g_linux_wlan->rxq_thread = kthread_run(linux_wlan_rxq_task, (void *)g_linux_wlan, "K_RXQ_TASK");
if (g_linux_wlan->rxq_thread == 0) {
PRINT_ER("couldn't create RXQ thread\n");
ret = -ENOBUFS;
goto _fail_1;
}
linux_wlan_lock(&g_linux_wlan->rxq_thread_started);
#endif
PRINT_D(INIT_DBG, "Creating kthread for transmission\n");
g_linux_wlan->txq_thread = kthread_run(linux_wlan_txq_task, (void *)g_linux_wlan, "K_TXQ_TASK");
if (g_linux_wlan->txq_thread == 0) {
PRINT_ER("couldn't create TXQ thread\n");
ret = -ENOBUFS;
goto _fail_2;
}
#ifdef DEBUG_MODE
PRINT_D(INIT_DBG, "Creating kthread for Debugging\n");
g_linux_wlan->txq_thread = kthread_run(DebuggingThreadTask, (void *)g_linux_wlan, "DebugThread");
if (g_linux_wlan->txq_thread == 0) {
PRINT_ER("couldn't create TXQ thread\n");
ret = -ENOBUFS;
goto _fail_2;
}
#endif
linux_wlan_lock(&g_linux_wlan->txq_thread_started);
return 0;
_fail_2:
g_linux_wlan->close = 1;
linux_wlan_unlock(&g_linux_wlan->rxq_event);
kthread_stop(g_linux_wlan->rxq_thread);
#ifndef TCP_ENHANCEMENTS
_fail_1:
#endif
#if (RX_BH_TYPE == RX_BH_KTHREAD)
g_linux_wlan->close = 1;
linux_wlan_unlock(&g_linux_wlan->rx_sem);
kthread_stop(g_linux_wlan->rx_bh_thread);
_fail_:
#endif
g_linux_wlan->close = 0;
return ret;
}
static void wlan_deinitialize_threads(linux_wlan_t *nic)
{
g_linux_wlan->close = 1;
PRINT_D(INIT_DBG, "Deinitializing Threads\n");
if (&g_linux_wlan->rxq_event != NULL)
linux_wlan_unlock(&g_linux_wlan->rxq_event);
if (g_linux_wlan->rxq_thread != NULL) {
kthread_stop(g_linux_wlan->rxq_thread);
g_linux_wlan->rxq_thread = NULL;
}
if (&g_linux_wlan->txq_event != NULL)
linux_wlan_unlock(&g_linux_wlan->txq_event);
if (g_linux_wlan->txq_thread != NULL) {
kthread_stop(g_linux_wlan->txq_thread);
g_linux_wlan->txq_thread = NULL;
}
#if (RX_BH_TYPE == RX_BH_KTHREAD)
if (&g_linux_wlan->rx_sem != NULL)
linux_wlan_unlock(&g_linux_wlan->rx_sem);
if (g_linux_wlan->rx_bh_thread != NULL) {
kthread_stop(g_linux_wlan->rx_bh_thread);
g_linux_wlan->rx_bh_thread = NULL;
}
#endif
}
static int linux_wlan_read_mac_addr(void *vp)
{
int ret = 0;
struct file *fp = (struct file *)-ENOENT;
mm_segment_t old_fs;
loff_t pos = 0;
int index;
int array_size = ARRAY_SIZE(path_string);
old_fs = get_fs();
set_fs(KERNEL_DS);
for (index = 0; index < array_size; index++) {
fp = filp_open(path_string[index], O_WRONLY, 0640);
if (!fp) {
ret = -1;
goto exit;
}
if (IS_ERR(fp) || !fp->f_op) {
get_random_bytes(&mac_add[3], 3);
fp = filp_open(path_string[index], O_WRONLY | O_CREAT, 0640);
if (!fp || IS_ERR(fp)) {
ret = -1;
continue;
} else {
fp->f_op->write(fp, mac_add, 6, &pos);
break;
}
} else {
fp->f_op->read(fp, mac_add, 6, &pos);
break;
}
}
if (index == array_size)
PRINT_ER("random MAC\n");
exit:
if (fp && !IS_ERR(fp))
filp_close(fp, NULL);
set_fs(old_fs);
return ret;
}
uint8_t wilc1000_prepare_11b_core(wilc_wlan_inp_t *nwi, wilc_wlan_oup_t *nwo, linux_wlan_t *nic)
{
uint8_t trials = 0;
while ((core_11b_ready() && (READY_CHECK_THRESHOLD > (trials++)))) {
PRINT_D(INIT_DBG, "11b core not ready yet: %u\n", trials);
wilc_wlan_deinit(nic);
wilc_wlan_global_reset();
sdio_unregister_driver(&wilc_bus);
linux_wlan_device_detection(0);
mdelay(100);
linux_wlan_device_detection(1);
sdio_register_driver(&wilc_bus);
while (!probe)
msleep(100);
probe = 0;
g_linux_wlan->wilc_sdio_func = local_sdio_func;
linux_to_wlan(nwi, nic);
wilc_wlan_init(nwi, nwo);
}
if (READY_CHECK_THRESHOLD <= trials)
return 1;
else
return 0;
}
int repeat_power_cycle(perInterface_wlan_t *nic)
{
int ret = 0;
wilc_wlan_inp_t nwi;
wilc_wlan_oup_t nwo;
sdio_unregister_driver(&wilc_bus);
linux_wlan_device_detection(0);
linux_wlan_device_power(0);
msleep(100);
linux_wlan_device_power(1);
msleep(80);
linux_wlan_device_detection(1);
msleep(20);
sdio_register_driver(&wilc_bus);
while (!probe)
msleep(100);
probe = 0;
g_linux_wlan->wilc_sdio_func = local_sdio_func;
linux_to_wlan(&nwi, g_linux_wlan);
ret = wilc_wlan_init(&nwi, &nwo);
g_linux_wlan->mac_status = WILC_MAC_STATUS_INIT;
#if (defined WILC_SDIO) && (!defined WILC_SDIO_IRQ_GPIO)
enable_sdio_interrupt();
#endif
if (linux_wlan_get_firmware(nic)) {
PRINT_ER("Can't get firmware\n");
ret = -1;
goto __fail__;
}
ret = linux_wlan_firmware_download(g_linux_wlan);
if (ret < 0) {
PRINT_ER("Failed to download firmware\n");
goto __fail__;
}
ret = linux_wlan_start_firmware(nic);
if (ret < 0)
PRINT_ER("Failed to start firmware\n");
__fail__:
return ret;
}
int wilc1000_wlan_init(struct net_device *dev, perInterface_wlan_t *p_nic)
{
wilc_wlan_inp_t nwi;
wilc_wlan_oup_t nwo;
perInterface_wlan_t *nic = p_nic;
int ret = 0;
if (!g_linux_wlan->wilc1000_initialized) {
g_linux_wlan->mac_status = WILC_MAC_STATUS_INIT;
g_linux_wlan->close = 0;
g_linux_wlan->wilc1000_initialized = 0;
wlan_init_locks(g_linux_wlan);
#ifdef STATIC_MACADDRESS
wilc_mac_thread = kthread_run(linux_wlan_read_mac_addr, NULL, "wilc_mac_thread");
if (wilc_mac_thread < 0)
PRINT_ER("couldn't create Mac addr thread\n");
#endif
linux_to_wlan(&nwi, g_linux_wlan);
ret = wilc_wlan_init(&nwi, &nwo);
if (ret < 0) {
PRINT_ER("Initializing WILC_Wlan FAILED\n");
ret = -EIO;
goto _fail_locks_;
}
memcpy(&g_linux_wlan->oup, &nwo, sizeof(wilc_wlan_oup_t));
gpstrWlanOps = &g_linux_wlan->oup;
ret = wlan_initialize_threads(nic);
if (ret < 0) {
PRINT_ER("Initializing Threads FAILED\n");
ret = -EIO;
goto _fail_wilc_wlan_;
}
#if (defined WILC_SDIO) && (defined COMPLEMENT_BOOT)
if (wilc1000_prepare_11b_core(&nwi, &nwo, g_linux_wlan)) {
PRINT_ER("11b Core is not ready\n");
ret = -EIO;
goto _fail_threads_;
}
#endif
#if (!defined WILC_SDIO) || (defined WILC_SDIO_IRQ_GPIO)
if (init_irq(g_linux_wlan)) {
PRINT_ER("couldn't initialize IRQ\n");
ret = -EIO;
goto _fail_threads_;
}
#endif
#if (defined WILC_SDIO) && (!defined WILC_SDIO_IRQ_GPIO)
if (enable_sdio_interrupt()) {
PRINT_ER("couldn't initialize IRQ\n");
ret = -EIO;
goto _fail_irq_init_;
}
#endif
if (linux_wlan_get_firmware(nic)) {
PRINT_ER("Can't get firmware\n");
ret = -EIO;
goto _fail_irq_enable_;
}
ret = linux_wlan_firmware_download(g_linux_wlan);
if (ret < 0) {
PRINT_ER("Failed to download firmware\n");
ret = -EIO;
goto _fail_irq_enable_;
}
ret = linux_wlan_start_firmware(nic);
if (ret < 0) {
PRINT_ER("Failed to start firmware\n");
ret = -EIO;
goto _fail_irq_enable_;
}
wilc_bus_set_max_speed();
if (g_linux_wlan->oup.wlan_cfg_get(1, WID_FIRMWARE_VERSION, 1, 0)) {
int size;
char Firmware_ver[20];
size = g_linux_wlan->oup.wlan_cfg_get_value(
WID_FIRMWARE_VERSION,
Firmware_ver, sizeof(Firmware_ver));
Firmware_ver[size] = '\0';
PRINT_D(INIT_DBG, "***** Firmware Ver = %s *******\n", Firmware_ver);
}
ret = linux_wlan_init_test_config(dev, g_linux_wlan);
if (ret < 0) {
PRINT_ER("Failed to configure firmware\n");
ret = -EIO;
goto _fail_fw_start_;
}
g_linux_wlan->wilc1000_initialized = 1;
return 0;
_fail_fw_start_:
if (&g_linux_wlan->oup != NULL) {
if (g_linux_wlan->oup.wlan_stop != NULL)
g_linux_wlan->oup.wlan_stop();
}
_fail_irq_enable_:
#if (defined WILC_SDIO) && (!defined WILC_SDIO_IRQ_GPIO)
disable_sdio_interrupt();
_fail_irq_init_:
#endif
#if (!defined WILC_SDIO) || (defined WILC_SDIO_IRQ_GPIO)
deinit_irq(g_linux_wlan);
#endif
_fail_threads_:
wlan_deinitialize_threads(g_linux_wlan);
_fail_wilc_wlan_:
wilc_wlan_deinit(g_linux_wlan);
_fail_locks_:
wlan_deinit_locks(g_linux_wlan);
PRINT_ER("WLAN Iinitialization FAILED\n");
} else {
PRINT_D(INIT_DBG, "wilc1000 already initialized\n");
}
return ret;
}
int mac_init_fn(struct net_device *ndev)
{
netif_start_queue(ndev);
netif_stop_queue(ndev);
return 0;
}
int mac_init_fn(struct net_device *ndev)
{
unsigned char mac_add[] = {0x00, 0x50, 0xc2, 0x5e, 0x10, 0x00};
memcpy(ndev->dev_addr, mac_add, 6);
if (!is_valid_ether_addr(ndev->dev_addr)) {
PRINT_ER("Error: Wrong MAC address\n");
return -EINVAL;
}
return 0;
}
int mac_open(struct net_device *ndev)
{
perInterface_wlan_t *nic;
unsigned char mac_add[ETH_ALEN] = {0};
int ret = 0;
int i = 0;
struct WILC_WFI_priv *priv;
nic = netdev_priv(ndev);
priv = wiphy_priv(nic->wilc_netdev->ieee80211_ptr->wiphy);
PRINT_D(INIT_DBG, "MAC OPEN[%p]\n", ndev);
#ifdef USE_WIRELESS
ret = WILC_WFI_InitHostInt(ndev);
if (ret < 0) {
PRINT_ER("Failed to initialize host interface\n");
return ret;
}
#endif
PRINT_D(INIT_DBG, "*** re-init ***\n");
ret = wilc1000_wlan_init(ndev, nic);
if (ret < 0) {
PRINT_ER("Failed to initialize wilc1000\n");
WILC_WFI_DeInitHostInt(ndev);
return ret;
}
Set_machw_change_vir_if(false);
host_int_get_MacAddress(priv->hWILCWFIDrv, mac_add);
PRINT_D(INIT_DBG, "Mac address: %x:%x:%x:%x:%x:%x\n", mac_add[0], mac_add[1], mac_add[2],
mac_add[3], mac_add[4], mac_add[5]);
for (i = 0; i < g_linux_wlan->u8NoIfcs; i++) {
if (ndev == g_linux_wlan->strInterfaceInfo[i].wilc_netdev) {
memcpy(g_linux_wlan->strInterfaceInfo[i].aSrcAddress, mac_add, ETH_ALEN);
g_linux_wlan->strInterfaceInfo[i].drvHandler = priv->hWILCWFIDrv;
break;
}
}
memcpy(ndev->dev_addr, g_linux_wlan->strInterfaceInfo[i].aSrcAddress, ETH_ALEN);
if (!is_valid_ether_addr(ndev->dev_addr)) {
PRINT_ER("Error: Wrong MAC address\n");
ret = -EINVAL;
goto _err_;
}
WILC_WFI_frame_register(nic->wilc_netdev->ieee80211_ptr->wiphy, nic->wilc_netdev,
nic->g_struct_frame_reg[0].frame_type, nic->g_struct_frame_reg[0].reg);
WILC_WFI_frame_register(nic->wilc_netdev->ieee80211_ptr->wiphy, nic->wilc_netdev,
nic->g_struct_frame_reg[1].frame_type, nic->g_struct_frame_reg[1].reg);
netif_wake_queue(ndev);
g_linux_wlan->open_ifcs++;
nic->mac_opened = 1;
return 0;
_err_:
WILC_WFI_DeInitHostInt(ndev);
wilc1000_wlan_deinit(g_linux_wlan);
return ret;
}
int mac_open(struct net_device *ndev)
{
linux_wlan_t *nic;
nic = netdev_priv(ndev);
if (wilc1000_wlan_init(nic)) {
PRINT_ER("Failed to initialize platform\n");
return 1;
}
PRINT_D(INIT_DBG, "Starting netifQ\n");
netif_start_queue(ndev);
return 0;
}
struct net_device_stats *mac_stats(struct net_device *dev)
{
perInterface_wlan_t *nic = netdev_priv(dev);
return &nic->netstats;
}
static void wilc_set_multicast_list(struct net_device *dev)
{
struct netdev_hw_addr *ha;
struct WILC_WFI_priv *priv;
tstrWILC_WFIDrv *pstrWFIDrv;
int i = 0;
priv = wiphy_priv(dev->ieee80211_ptr->wiphy);
pstrWFIDrv = (tstrWILC_WFIDrv *)priv->hWILCWFIDrv;
if (!dev)
return;
PRINT_D(INIT_DBG, "Setting Multicast List with count = %d.\n", dev->mc.count);
if (dev->flags & IFF_PROMISC) {
PRINT_D(INIT_DBG, "Set promiscuous mode ON, retrive all packets\n");
return;
}
if ((dev->flags & IFF_ALLMULTI) || (dev->mc.count) > WILC_MULTICAST_TABLE_SIZE) {
PRINT_D(INIT_DBG, "Disable multicast filter, retrive all multicast packets\n");
host_int_setup_multicast_filter(pstrWFIDrv, false, 0);
return;
}
if ((dev->mc.count) == 0) {
PRINT_D(INIT_DBG, "Enable multicast filter, retrive directed packets only.\n");
host_int_setup_multicast_filter(pstrWFIDrv, true, 0);
return;
}
netdev_for_each_mc_addr(ha, dev)
{
memcpy(gau8MulticastMacAddrList[i], ha->addr, ETH_ALEN);
PRINT_D(INIT_DBG, "Entry[%d]: %x:%x:%x:%x:%x:%x\n", i,
gau8MulticastMacAddrList[i][0], gau8MulticastMacAddrList[i][1], gau8MulticastMacAddrList[i][2], gau8MulticastMacAddrList[i][3], gau8MulticastMacAddrList[i][4], gau8MulticastMacAddrList[i][5]);
i++;
}
host_int_setup_multicast_filter(pstrWFIDrv, true, (dev->mc.count));
return;
}
static void linux_wlan_tx_complete(void *priv, int status)
{
struct tx_complete_data *pv_data = (struct tx_complete_data *)priv;
if (status == 1)
PRINT_D(TX_DBG, "Packet sent successfully - Size = %d - Address = %p - SKB = %p\n", pv_data->size, pv_data->buff, pv_data->skb);
else
PRINT_D(TX_DBG, "Couldn't send packet - Size = %d - Address = %p - SKB = %p\n", pv_data->size, pv_data->buff, pv_data->skb);
dev_kfree_skb(pv_data->skb);
linux_wlan_free(pv_data);
}
int mac_xmit(struct sk_buff *skb, struct net_device *ndev)
{
perInterface_wlan_t *nic;
struct tx_complete_data *tx_data = NULL;
int QueueCount;
char *pu8UdpBuffer;
struct iphdr *ih;
struct ethhdr *eth_h;
nic = netdev_priv(ndev);
PRINT_D(INT_DBG, "\n========\n IntUH: %d - IntBH: %d - IntCld: %d\n========\n", int_rcvdU, int_rcvdB, int_clrd);
PRINT_D(TX_DBG, "Sending packet just received from TCP/IP\n");
if (skb->dev != ndev) {
PRINT_ER("Packet not destined to this device\n");
return 0;
}
tx_data = (struct tx_complete_data *)internal_alloc(sizeof(struct tx_complete_data), GFP_ATOMIC);
if (tx_data == NULL) {
PRINT_ER("Failed to allocate memory for tx_data structure\n");
dev_kfree_skb(skb);
netif_wake_queue(ndev);
return 0;
}
tx_data->buff = skb->data;
tx_data->size = skb->len;
tx_data->skb = skb;
eth_h = (struct ethhdr *)(skb->data);
if (eth_h->h_proto == 0x8e88)
PRINT_D(INIT_DBG, "EAPOL transmitted\n");
ih = (struct iphdr *)(skb->data + sizeof(struct ethhdr));
pu8UdpBuffer = (char *)ih + sizeof(struct iphdr);
if ((pu8UdpBuffer[1] == 68 && pu8UdpBuffer[3] == 67) || (pu8UdpBuffer[1] == 67 && pu8UdpBuffer[3] == 68))
PRINT_D(GENERIC_DBG, "DHCP Message transmitted, type:%x %x %x\n", pu8UdpBuffer[248], pu8UdpBuffer[249], pu8UdpBuffer[250]);
PRINT_D(TX_DBG, "Sending packet - Size = %d - Address = %p - SKB = %p\n", tx_data->size, tx_data->buff, tx_data->skb);
PRINT_D(TX_DBG, "Adding tx packet to TX Queue\n");
nic->netstats.tx_packets++;
nic->netstats.tx_bytes += tx_data->size;
tx_data->pBssid = g_linux_wlan->strInterfaceInfo[nic->u8IfIdx].aBSSID;
#ifndef WILC_FULLY_HOSTING_AP
QueueCount = g_linux_wlan->oup.wlan_add_to_tx_que((void *)tx_data,
tx_data->buff,
tx_data->size,
linux_wlan_tx_complete);
#else
QueueCount = WILC_Xmit_data((void *)tx_data, HOST_TO_WLAN);
#endif
if (QueueCount > FLOW_CONTROL_UPPER_THRESHOLD) {
netif_stop_queue(g_linux_wlan->strInterfaceInfo[0].wilc_netdev);
netif_stop_queue(g_linux_wlan->strInterfaceInfo[1].wilc_netdev);
}
return 0;
}
int mac_close(struct net_device *ndev)
{
struct WILC_WFI_priv *priv;
perInterface_wlan_t *nic;
tstrWILC_WFIDrv *pstrWFIDrv;
nic = netdev_priv(ndev);
if ((nic == NULL) || (nic->wilc_netdev == NULL) || (nic->wilc_netdev->ieee80211_ptr == NULL) || (nic->wilc_netdev->ieee80211_ptr->wiphy == NULL)) {
PRINT_ER("nic = NULL\n");
return 0;
}
priv = wiphy_priv(nic->wilc_netdev->ieee80211_ptr->wiphy);
if (priv == NULL) {
PRINT_ER("priv = NULL\n");
return 0;
}
pstrWFIDrv = (tstrWILC_WFIDrv *)priv->hWILCWFIDrv;
PRINT_D(GENERIC_DBG, "Mac close\n");
if (g_linux_wlan == NULL) {
PRINT_ER("g_linux_wlan = NULL\n");
return 0;
}
if (pstrWFIDrv == NULL) {
PRINT_ER("pstrWFIDrv = NULL\n");
return 0;
}
if ((g_linux_wlan->open_ifcs) > 0) {
g_linux_wlan->open_ifcs--;
} else {
PRINT_ER("ERROR: MAC close called while number of opened interfaces is zero\n");
return 0;
}
if (nic->wilc_netdev != NULL) {
netif_stop_queue(nic->wilc_netdev);
#ifdef USE_WIRELESS
WILC_WFI_DeInitHostInt(nic->wilc_netdev);
#endif
}
if (g_linux_wlan->open_ifcs == 0) {
PRINT_D(GENERIC_DBG, "Deinitializing wilc1000\n");
g_linux_wlan->close = 1;
wilc1000_wlan_deinit(g_linux_wlan);
#ifdef USE_WIRELESS
#ifdef WILC_AP_EXTERNAL_MLME
WILC_WFI_deinit_mon_interface();
#endif
#endif
}
linux_wlan_unlock(&close_exit_sync);
nic->mac_opened = 0;
return 0;
}
int mac_ioctl(struct net_device *ndev, struct ifreq *req, int cmd)
{
u8 *buff = NULL;
s8 rssi;
u32 size = 0, length = 0;
perInterface_wlan_t *nic;
struct WILC_WFI_priv *priv;
s32 s32Error = WILC_SUCCESS;
#ifdef USE_WIRELESS
nic = netdev_priv(ndev);
if (!g_linux_wlan->wilc1000_initialized)
return 0;
#endif
switch (cmd) {
case SIOCSIWPRIV:
{
struct iwreq *wrq = (struct iwreq *) req;
size = wrq->u.data.length;
if (size && wrq->u.data.pointer) {
buff = memdup_user(wrq->u.data.pointer, wrq->u.data.length);
if (IS_ERR(buff)) {
s32Error = PTR_ERR(buff);
goto done;
}
if (strncasecmp(buff, "RSSI", length) == 0) {
#ifdef USE_WIRELESS
priv = wiphy_priv(nic->wilc_netdev->ieee80211_ptr->wiphy);
s32Error = host_int_get_rssi(priv->hWILCWFIDrv, &(rssi));
if (s32Error)
PRINT_ER("Failed to send get rssi param's message queue ");
#endif
PRINT_INFO(GENERIC_DBG, "RSSI :%d\n", rssi);
rssi += 5;
snprintf(buff, size, "rssi %d", rssi);
if (copy_to_user(wrq->u.data.pointer, buff, size)) {
PRINT_ER("%s: failed to copy data to user buffer\n", __func__);
s32Error = -EFAULT;
goto done;
}
}
}
}
break;
default:
{
PRINT_INFO(GENERIC_DBG, "Command - %d - has been received\n", cmd);
s32Error = -EOPNOTSUPP;
goto done;
}
}
done:
kfree(buff);
return s32Error;
}
void frmw_to_linux(uint8_t *buff, uint32_t size, uint32_t pkt_offset)
{
unsigned int frame_len = 0;
int stats;
unsigned char *buff_to_send = NULL;
struct sk_buff *skb;
#ifndef TCP_ENHANCEMENTS
char *pu8UdpBuffer;
struct iphdr *ih;
#endif
struct net_device *wilc_netdev;
perInterface_wlan_t *nic;
wilc_netdev = GetIfHandler(buff);
if (wilc_netdev == NULL)
return;
buff += pkt_offset;
nic = netdev_priv(wilc_netdev);
if (size > 0) {
frame_len = size;
buff_to_send = buff;
skb = dev_alloc_skb(frame_len);
if (skb == NULL) {
PRINT_ER("Low memory - packet droped\n");
return;
}
skb_reserve(skb, (unsigned int)skb->data & 0x3);
if (g_linux_wlan == NULL || wilc_netdev == NULL)
PRINT_ER("wilc_netdev in g_linux_wlan is NULL");
skb->dev = wilc_netdev;
if (skb->dev == NULL)
PRINT_ER("skb->dev is NULL\n");
memcpy(skb_put(skb, frame_len), buff_to_send, frame_len);
#ifdef USE_WIRELESS
#endif
skb->protocol = eth_type_trans(skb, wilc_netdev);
#ifndef TCP_ENHANCEMENTS
ih = (struct iphdr *)(skb->data + sizeof(struct ethhdr));
pu8UdpBuffer = (char *)ih + sizeof(struct iphdr);
if (buff_to_send[35] == 67 && buff_to_send[37] == 68)
PRINT_D(RX_DBG, "DHCP Message received\n");
if (buff_to_send[12] == 0x88 && buff_to_send[13] == 0x8e)
PRINT_D(GENERIC_DBG, "eapol received\n");
#endif
nic->netstats.rx_packets++;
nic->netstats.rx_bytes += frame_len;
skb->ip_summed = CHECKSUM_UNNECESSARY;
stats = netif_rx(skb);
PRINT_D(RX_DBG, "netif_rx ret value is: %d\n", stats);
}
#ifndef TCP_ENHANCEMENTS
else
PRINT_ER("Discard sending packet with len = %d\n", size);
#endif
}
void WILC_WFI_mgmt_rx(uint8_t *buff, uint32_t size)
{
int i = 0;
perInterface_wlan_t *nic;
for (i = 0; i < g_linux_wlan->u8NoIfcs; i++) {
nic = netdev_priv(g_linux_wlan->strInterfaceInfo[i].wilc_netdev);
if (nic->monitor_flag) {
WILC_WFI_monitor_rx(buff, size);
return;
}
}
#ifdef WILC_P2P
nic = netdev_priv(g_linux_wlan->strInterfaceInfo[1].wilc_netdev);
if ((buff[0] == nic->g_struct_frame_reg[0].frame_type && nic->g_struct_frame_reg[0].reg) ||
(buff[0] == nic->g_struct_frame_reg[1].frame_type && nic->g_struct_frame_reg[1].reg))
WILC_WFI_p2p_rx(g_linux_wlan->strInterfaceInfo[1].wilc_netdev, buff, size);
#endif
}
int wilc_netdev_init(void)
{
int i;
perInterface_wlan_t *nic;
struct net_device *ndev;
linux_wlan_init_lock("close_exit_sync", &close_exit_sync, 0);
g_linux_wlan = WILC_MALLOC(sizeof(linux_wlan_t));
memset(g_linux_wlan, 0, sizeof(linux_wlan_t));
int_rcvdU = 0;
int_rcvdB = 0;
int_clrd = 0;
#ifdef DISABLE_PWRSAVE_AND_SCAN_DURING_IP
register_inetaddr_notifier(&g_dev_notifier);
#endif
for (i = 0; i < NUM_CONCURRENT_IFC; i++) {
ndev = alloc_etherdev(sizeof(perInterface_wlan_t));
if (!ndev) {
PRINT_ER("Failed to allocate ethernet dev\n");
return -1;
}
nic = netdev_priv(ndev);
memset(nic, 0, sizeof(perInterface_wlan_t));
if (i == 0) {
#if defined(NM73131)
strcpy(ndev->name, "wilc_eth%d");
#elif defined(PLAT_CLM9722)
strcpy(ndev->name, "eth%d");
#else
strcpy(ndev->name, "wlan%d");
#endif
} else
strcpy(ndev->name, "p2p%d");
nic->u8IfIdx = g_linux_wlan->u8NoIfcs;
nic->wilc_netdev = ndev;
g_linux_wlan->strInterfaceInfo[g_linux_wlan->u8NoIfcs].wilc_netdev = ndev;
g_linux_wlan->u8NoIfcs++;
ndev->netdev_ops = &wilc_netdev_ops;
#ifdef USE_WIRELESS
{
struct wireless_dev *wdev;
wdev = WILC_WFI_WiphyRegister(ndev);
#ifdef WILC_SDIO
SET_NETDEV_DEV(ndev, &local_sdio_func->dev);
#endif
if (wdev == NULL) {
PRINT_ER("Can't register WILC Wiphy\n");
return -1;
}
nic->wilc_netdev->ieee80211_ptr = wdev;
nic->wilc_netdev->ml_priv = nic;
wdev->netdev = nic->wilc_netdev;
nic->netstats.rx_packets = 0;
nic->netstats.tx_packets = 0;
nic->netstats.rx_bytes = 0;
nic->netstats.tx_bytes = 0;
}
#endif
if (register_netdev(ndev)) {
PRINT_ER("Device couldn't be registered - %s\n", ndev->name);
return -1;
}
nic->iftype = STATION_MODE;
nic->mac_opened = 0;
}
#ifndef WILC_SDIO
if (!linux_spi_init(&g_linux_wlan->wilc_spidev)) {
PRINT_ER("Can't initialize SPI\n");
return -1;
}
g_linux_wlan->wilc_spidev = wilc_spi_dev;
#else
g_linux_wlan->wilc_sdio_func = local_sdio_func;
#endif
return 0;
}
static int __init init_wilc_driver(void)
{
#if defined(WILC_DEBUGFS)
if (wilc_debugfs_init() < 0) {
PRINT_D(GENERIC_DBG, "fail to create debugfs for wilc driver\n");
return -1;
}
#endif
printk("IN INIT FUNCTION\n");
printk("*** WILC1000 driver VERSION=[10.2] FW_VER=[10.2] ***\n");
linux_wlan_device_power(1);
msleep(100);
linux_wlan_device_detection(1);
#ifdef WILC_SDIO
{
int ret;
ret = sdio_register_driver(&wilc_bus);
if (ret < 0)
PRINT_D(INIT_DBG, "init_wilc_driver: Failed register sdio driver\n");
return ret;
}
#else
PRINT_D(INIT_DBG, "Initializing netdev\n");
if (wilc_netdev_init())
PRINT_ER("Couldn't initialize netdev\n");
return 0;
#endif
}
static void __exit exit_wilc_driver(void)
{
int i = 0;
perInterface_wlan_t *nic[NUM_CONCURRENT_IFC] = {NULL,};
#define CLOSE_TIMEOUT (12 * 1000)
if ((g_linux_wlan != NULL) && (((g_linux_wlan->strInterfaceInfo[0].wilc_netdev) != NULL)
|| ((g_linux_wlan->strInterfaceInfo[1].wilc_netdev) != NULL))) {
#ifdef DISABLE_PWRSAVE_AND_SCAN_DURING_IP
unregister_inetaddr_notifier(&g_dev_notifier);
#endif
for (i = 0; i < NUM_CONCURRENT_IFC; i++)
nic[i] = netdev_priv(g_linux_wlan->strInterfaceInfo[i].wilc_netdev);
}
if ((g_linux_wlan != NULL) && g_linux_wlan->wilc_firmware != NULL) {
release_firmware(g_linux_wlan->wilc_firmware);
g_linux_wlan->wilc_firmware = NULL;
}
if ((g_linux_wlan != NULL) && (((g_linux_wlan->strInterfaceInfo[0].wilc_netdev) != NULL)
|| ((g_linux_wlan->strInterfaceInfo[1].wilc_netdev) != NULL))) {
PRINT_D(INIT_DBG, "Waiting for mac_close ....\n");
if (linux_wlan_lock_timeout(&close_exit_sync, CLOSE_TIMEOUT) < 0)
PRINT_D(INIT_DBG, "Closed TimedOUT\n");
else
PRINT_D(INIT_DBG, "mac_closed\n");
for (i = 0; i < NUM_CONCURRENT_IFC; i++) {
if (g_linux_wlan->strInterfaceInfo[i].wilc_netdev != NULL) {
if (nic[i]->mac_opened)
mac_close(g_linux_wlan->strInterfaceInfo[i].wilc_netdev);
}
}
for (i = 0; i < NUM_CONCURRENT_IFC; i++) {
PRINT_D(INIT_DBG, "Unregistering netdev %p\n", g_linux_wlan->strInterfaceInfo[i].wilc_netdev);
unregister_netdev(g_linux_wlan->strInterfaceInfo[i].wilc_netdev);
#ifdef USE_WIRELESS
PRINT_D(INIT_DBG, "Freeing Wiphy...\n");
WILC_WFI_WiphyFree(g_linux_wlan->strInterfaceInfo[i].wilc_netdev);
#endif
PRINT_D(INIT_DBG, "Freeing netdev...\n");
free_netdev(g_linux_wlan->strInterfaceInfo[i].wilc_netdev);
}
}
#ifdef USE_WIRELESS
#ifdef WILC_AP_EXTERNAL_MLME
#endif
#endif
{
#ifndef WILC_SDIO
PRINT_D(INIT_DBG, "SPI unregsiter...\n");
spi_unregister_driver(&wilc_bus);
#else
PRINT_D(INIT_DBG, "SDIO unregsiter...\n");
sdio_unregister_driver(&wilc_bus);
#endif
linux_wlan_deinit_lock(&close_exit_sync);
if (g_linux_wlan != NULL) {
kfree(g_linux_wlan);
g_linux_wlan = NULL;
}
printk("Module_exit Done.\n");
#if defined(WILC_DEBUGFS)
wilc_debugfs_remove();
#endif
linux_wlan_device_detection(0);
linux_wlan_device_power(0);
}
}
