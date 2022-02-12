inline int RTW_STATUS_CODE(int error_code)
{
if (error_code >= 0)
return _SUCCESS;
return _FAIL;
}
u32 rtw_atoi(u8 *s)
{
int num = 0, flag = 0;
int i;
for (i = 0; i <= strlen(s); i++) {
if (s[i] >= '0' && s[i] <= '9')
num = num * 10 + s[i] - '0';
else if (s[0] == '-' && i == 0)
flag = 1;
else
break;
}
if (flag == 1)
num = num * -1;
return num;
}
inline u8 *_rtw_vmalloc(u32 sz)
{
u8 *pbuf;
pbuf = vmalloc(sz);
return pbuf;
}
inline u8 *_rtw_zvmalloc(u32 sz)
{
u8 *pbuf;
pbuf = _rtw_vmalloc(sz);
if (pbuf != NULL)
memset(pbuf, 0, sz);
return pbuf;
}
inline void _rtw_vmfree(u8 *pbuf, u32 sz)
{
vfree(pbuf);
}
u8 *_rtw_malloc(u32 sz)
{
u8 *pbuf = NULL;
pbuf = kmalloc(sz, in_interrupt() ? GFP_ATOMIC : GFP_KERNEL);
return pbuf;
}
u8 *_rtw_zmalloc(u32 sz)
{
u8 *pbuf = _rtw_malloc(sz);
if (pbuf != NULL)
memset(pbuf, 0, sz);
return pbuf;
}
void *rtw_malloc2d(int h, int w, int size)
{
int j;
void **a = (void **)rtw_zmalloc(h*sizeof(void *) + h*w*size);
if (a == NULL) {
pr_info("%s: alloc memory fail!\n", __func__);
return NULL;
}
for (j = 0; j < h; j++)
a[j] = ((char *)(a+h)) + j*w*size;
return a;
}
void rtw_mfree2d(void *pbuf, int h, int w, int size)
{
kfree(pbuf);
}
int _rtw_memcmp(void *dst, void *src, u32 sz)
{
if (!(memcmp(dst, src, sz)))
return true;
else
return false;
}
void _rtw_memset(void *pbuf, int c, u32 sz)
{
memset(pbuf, c, sz);
}
void _rtw_init_listhead(struct list_head *list)
{
INIT_LIST_HEAD(list);
}
u32 rtw_is_list_empty(struct list_head *phead)
{
if (list_empty(phead))
return true;
else
return false;
}
void rtw_list_insert_head(struct list_head *plist, struct list_head *phead)
{
list_add(plist, phead);
}
void rtw_list_insert_tail(struct list_head *plist, struct list_head *phead)
{
list_add_tail(plist, phead);
}
void _rtw_init_sema(struct semaphore *sema, int init_val)
{
sema_init(sema, init_val);
}
void _rtw_free_sema(struct semaphore *sema)
{
}
void _rtw_up_sema(struct semaphore *sema)
{
up(sema);
}
u32 _rtw_down_sema(struct semaphore *sema)
{
if (down_interruptible(sema))
return _FAIL;
else
return _SUCCESS;
}
void _rtw_mutex_init(struct mutex *pmutex)
{
mutex_init(pmutex);
}
void _rtw_mutex_free(struct mutex *pmutex)
{
mutex_destroy(pmutex);
}
void _rtw_spinlock_init(spinlock_t *plock)
{
spin_lock_init(plock);
}
void _rtw_spinlock_free(spinlock_t *plock)
{
}
void _rtw_init_queue(struct __queue *pqueue)
{
_rtw_init_listhead(&(pqueue->queue));
_rtw_spinlock_init(&(pqueue->lock));
}
u32 _rtw_queue_empty(struct __queue *pqueue)
{
return rtw_is_list_empty(&(pqueue->queue));
}
u32 rtw_end_of_queue_search(struct list_head *head, struct list_head *plist)
{
if (head == plist)
return true;
else
return false;
}
u32 rtw_get_current_time(void)
{
return jiffies;
}
inline u32 rtw_systime_to_ms(u32 systime)
{
return systime * 1000 / HZ;
}
inline u32 rtw_ms_to_systime(u32 ms)
{
return ms * HZ / 1000;
}
inline s32 rtw_get_passing_time_ms(u32 start)
{
return rtw_systime_to_ms(jiffies-start);
}
inline s32 rtw_get_time_interval_ms(u32 start, u32 end)
{
return rtw_systime_to_ms(end-start);
}
void rtw_sleep_schedulable(int ms)
{
u32 delta;
delta = (ms * HZ)/1000;
if (delta == 0)
delta = 1;
set_current_state(TASK_INTERRUPTIBLE);
if (schedule_timeout(delta) != 0)
return;
}
void rtw_msleep_os(int ms)
{
msleep((unsigned int)ms);
}
void rtw_usleep_os(int us)
{
if (1 < (us/1000))
msleep(1);
else
msleep((us/1000) + 1);
}
void rtw_mdelay_os(int ms)
{
mdelay((unsigned long)ms);
}
void rtw_udelay_os(int us)
{
udelay((unsigned long)us);
}
void rtw_yield_os(void)
{
yield();
}
inline void rtw_suspend_lock_init(void)
{
}
inline void rtw_suspend_lock_uninit(void)
{
}
inline void rtw_lock_suspend(void)
{
}
inline void rtw_unlock_suspend(void)
{
}
inline void ATOMIC_SET(ATOMIC_T *v, int i)
{
atomic_set(v, i);
}
inline int ATOMIC_READ(ATOMIC_T *v)
{
return atomic_read(v);
}
inline void ATOMIC_ADD(ATOMIC_T *v, int i)
{
atomic_add(i, v);
}
inline void ATOMIC_SUB(ATOMIC_T *v, int i)
{
atomic_sub(i, v);
}
inline void ATOMIC_INC(ATOMIC_T *v)
{
atomic_inc(v);
}
inline void ATOMIC_DEC(ATOMIC_T *v)
{
atomic_dec(v);
}
inline int ATOMIC_ADD_RETURN(ATOMIC_T *v, int i)
{
return atomic_add_return(i, v);
}
inline int ATOMIC_SUB_RETURN(ATOMIC_T *v, int i)
{
return atomic_sub_return(i, v);
}
inline int ATOMIC_INC_RETURN(ATOMIC_T *v)
{
return atomic_inc_return(v);
}
inline int ATOMIC_DEC_RETURN(ATOMIC_T *v)
{
return atomic_dec_return(v);
}
static int openfile(struct file **fpp, char *path, int flag, int mode)
{
struct file *fp;
fp = filp_open(path, flag, mode);
if (IS_ERR(fp)) {
*fpp = NULL;
return PTR_ERR(fp);
} else {
*fpp = fp;
return 0;
}
}
static int closefile(struct file *fp)
{
filp_close(fp, NULL);
return 0;
}
static int readfile(struct file *fp, char __user *buf, int len)
{
int rlen = 0, sum = 0;
if (!fp->f_op || !fp->f_op->read)
return -EPERM;
while (sum < len) {
rlen = fp->f_op->read(fp, buf+sum, len-sum, &fp->f_pos);
if (rlen > 0)
sum += rlen;
else if (0 != rlen)
return rlen;
else
break;
}
return sum;
}
static int writefile(struct file *fp, char __user *buf, int len)
{
int wlen = 0, sum = 0;
if (!fp->f_op || !fp->f_op->write)
return -EPERM;
while (sum < len) {
wlen = fp->f_op->write(fp, buf+sum, len-sum, &fp->f_pos);
if (wlen > 0)
sum += wlen;
else if (0 != wlen)
return wlen;
else
break;
}
return sum;
}
static int isfilereadable(char *path)
{
struct file *fp;
int ret = 0;
mm_segment_t oldfs;
char __user buf;
fp = filp_open(path, O_RDONLY, 0);
if (IS_ERR(fp)) {
ret = PTR_ERR(fp);
} else {
oldfs = get_fs(); set_fs(get_ds());
if (1 != readfile(fp, &buf, 1))
ret = PTR_ERR(fp);
set_fs(oldfs);
filp_close(fp, NULL);
}
return ret;
}
static int retrievefromfile(char *path, u8 __user *buf, u32 sz)
{
int ret = -1;
mm_segment_t oldfs;
struct file *fp;
if (path && buf) {
ret = openfile(&fp, path, O_RDONLY, 0);
if (0 == ret) {
DBG_88E("%s openfile path:%s fp =%p\n", __func__,
path, fp);
oldfs = get_fs(); set_fs(get_ds());
ret = readfile(fp, buf, sz);
set_fs(oldfs);
closefile(fp);
DBG_88E("%s readfile, ret:%d\n", __func__, ret);
} else {
DBG_88E("%s openfile path:%s Fail, ret:%d\n", __func__,
path, ret);
}
} else {
DBG_88E("%s NULL pointer\n", __func__);
ret = -EINVAL;
}
return ret;
}
static int storetofile(char *path, u8 __user *buf, u32 sz)
{
int ret = 0;
mm_segment_t oldfs;
struct file *fp;
if (path && buf) {
ret = openfile(&fp, path, O_CREAT|O_WRONLY, 0666);
if (0 == ret) {
DBG_88E("%s openfile path:%s fp =%p\n", __func__, path, fp);
oldfs = get_fs(); set_fs(get_ds());
ret = writefile(fp, buf, sz);
set_fs(oldfs);
closefile(fp);
DBG_88E("%s writefile, ret:%d\n", __func__, ret);
} else {
DBG_88E("%s openfile path:%s Fail, ret:%d\n", __func__, path, ret);
}
} else {
DBG_88E("%s NULL pointer\n", __func__);
ret = -EINVAL;
}
return ret;
}
int rtw_is_file_readable(char *path)
{
if (isfilereadable(path) == 0)
return true;
else
return false;
}
int rtw_retrive_from_file(char *path, u8 __user *buf, u32 sz)
{
int ret = retrievefromfile(path, buf, sz);
return ret >= 0 ? ret : 0;
}
int rtw_store_to_file(char *path, u8 __user *buf, u32 sz)
{
int ret = storetofile(path, buf, sz);
return ret >= 0 ? ret : 0;
}
struct net_device *rtw_alloc_etherdev_with_old_priv(int sizeof_priv,
void *old_priv)
{
struct net_device *pnetdev;
struct rtw_netdev_priv_indicator *pnpi;
pnetdev = alloc_etherdev_mq(sizeof(struct rtw_netdev_priv_indicator), 4);
if (!pnetdev)
goto RETURN;
pnpi = netdev_priv(pnetdev);
pnpi->priv = old_priv;
pnpi->sizeof_priv = sizeof_priv;
RETURN:
return pnetdev;
}
struct net_device *rtw_alloc_etherdev(int sizeof_priv)
{
struct net_device *pnetdev;
struct rtw_netdev_priv_indicator *pnpi;
pnetdev = alloc_etherdev_mq(sizeof(struct rtw_netdev_priv_indicator), 4);
if (!pnetdev)
goto RETURN;
pnpi = netdev_priv(pnetdev);
pnpi->priv = rtw_zvmalloc(sizeof_priv);
if (!pnpi->priv) {
free_netdev(pnetdev);
pnetdev = NULL;
goto RETURN;
}
pnpi->sizeof_priv = sizeof_priv;
RETURN:
return pnetdev;
}
void rtw_free_netdev(struct net_device *netdev)
{
struct rtw_netdev_priv_indicator *pnpi;
if (!netdev)
goto RETURN;
pnpi = netdev_priv(netdev);
if (!pnpi->priv)
goto RETURN;
rtw_vmfree(pnpi->priv, pnpi->sizeof_priv);
free_netdev(netdev);
RETURN:
return;
}
int rtw_change_ifname(struct adapter *padapter, const char *ifname)
{
struct net_device *pnetdev;
struct net_device *cur_pnetdev = padapter->pnetdev;
struct rereg_nd_name_data *rereg_priv;
int ret;
if (!padapter)
goto error;
rereg_priv = &padapter->rereg_nd_name_priv;
if (rereg_priv->old_pnetdev) {
free_netdev(rereg_priv->old_pnetdev);
rereg_priv->old_pnetdev = NULL;
}
if (!rtnl_is_locked())
unregister_netdev(cur_pnetdev);
else
unregister_netdevice(cur_pnetdev);
rtw_proc_remove_one(cur_pnetdev);
rereg_priv->old_pnetdev = cur_pnetdev;
pnetdev = rtw_init_netdev(padapter);
if (!pnetdev) {
ret = -1;
goto error;
}
SET_NETDEV_DEV(pnetdev, dvobj_to_dev(adapter_to_dvobj(padapter)));
rtw_init_netdev_name(pnetdev, ifname);
memcpy(pnetdev->dev_addr, padapter->eeprompriv.mac_addr, ETH_ALEN);
if (!rtnl_is_locked())
ret = register_netdev(pnetdev);
else
ret = register_netdevice(pnetdev);
if (ret != 0) {
RT_TRACE(_module_hci_intfs_c_, _drv_err_,
("register_netdev() failed\n"));
goto error;
}
rtw_proc_init_one(pnetdev);
return 0;
error:
return -1;
}
u64 rtw_modular64(u64 x, u64 y)
{
return do_div(x, y);
}
u64 rtw_division64(u64 x, u64 y)
{
do_div(x, y);
return x;
}
void rtw_buf_free(u8 **buf, u32 *buf_len)
{
*buf_len = 0;
kfree(*buf);
*buf = NULL;
}
void rtw_buf_update(u8 **buf, u32 *buf_len, u8 *src, u32 src_len)
{
u32 ori_len = 0, dup_len = 0;
u8 *ori = NULL;
u8 *dup = NULL;
if (!buf || !buf_len)
return;
if (!src || !src_len)
goto keep_ori;
dup = rtw_malloc(src_len);
if (dup) {
dup_len = src_len;
memcpy(dup, src, dup_len);
}
keep_ori:
ori = *buf;
ori_len = *buf_len;
*buf_len = 0;
*buf = dup;
*buf_len = dup_len;
kfree(ori);
}
inline bool rtw_cbuf_full(struct rtw_cbuf *cbuf)
{
return (cbuf->write == cbuf->read-1) ? true : false;
}
inline bool rtw_cbuf_empty(struct rtw_cbuf *cbuf)
{
return (cbuf->write == cbuf->read) ? true : false;
}
bool rtw_cbuf_push(struct rtw_cbuf *cbuf, void *buf)
{
if (rtw_cbuf_full(cbuf))
return _FAIL;
if (0)
DBG_88E("%s on %u\n", __func__, cbuf->write);
cbuf->bufs[cbuf->write] = buf;
cbuf->write = (cbuf->write+1)%cbuf->size;
return _SUCCESS;
}
void *rtw_cbuf_pop(struct rtw_cbuf *cbuf)
{
void *buf;
if (rtw_cbuf_empty(cbuf))
return NULL;
if (0)
DBG_88E("%s on %u\n", __func__, cbuf->read);
buf = cbuf->bufs[cbuf->read];
cbuf->read = (cbuf->read+1)%cbuf->size;
return buf;
}
struct rtw_cbuf *rtw_cbuf_alloc(u32 size)
{
struct rtw_cbuf *cbuf;
cbuf = (struct rtw_cbuf *)rtw_malloc(sizeof(*cbuf) +
sizeof(void *)*size);
if (cbuf) {
cbuf->write = 0;
cbuf->read = 0;
cbuf->size = size;
}
return cbuf;
}
