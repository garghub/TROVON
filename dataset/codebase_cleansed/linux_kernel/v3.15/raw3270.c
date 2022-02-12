static inline int raw3270_state_ready(struct raw3270 *rp)
{
return rp->state == RAW3270_STATE_READY;
}
static inline int raw3270_state_final(struct raw3270 *rp)
{
return rp->state == RAW3270_STATE_INIT ||
rp->state == RAW3270_STATE_READY;
}
void
raw3270_buffer_address(struct raw3270 *rp, char *cp, unsigned short addr)
{
if (test_bit(RAW3270_FLAGS_14BITADDR, &rp->flags)) {
cp[0] = (addr >> 8) & 0x3f;
cp[1] = addr & 0xff;
} else {
cp[0] = raw3270_ebcgraf[(addr >> 6) & 0x3f];
cp[1] = raw3270_ebcgraf[addr & 0x3f];
}
}
struct raw3270_request *
raw3270_request_alloc(size_t size)
{
struct raw3270_request *rq;
rq = kzalloc(sizeof(struct raw3270_request), GFP_KERNEL | GFP_DMA);
if (!rq)
return ERR_PTR(-ENOMEM);
if (size > 0) {
rq->buffer = kmalloc(size, GFP_KERNEL | GFP_DMA);
if (!rq->buffer) {
kfree(rq);
return ERR_PTR(-ENOMEM);
}
}
rq->size = size;
INIT_LIST_HEAD(&rq->list);
rq->ccw.cda = __pa(rq->buffer);
rq->ccw.flags = CCW_FLAG_SLI;
return rq;
}
void
raw3270_request_free (struct raw3270_request *rq)
{
kfree(rq->buffer);
kfree(rq);
}
void
raw3270_request_reset(struct raw3270_request *rq)
{
BUG_ON(!list_empty(&rq->list));
rq->ccw.cmd_code = 0;
rq->ccw.count = 0;
rq->ccw.cda = __pa(rq->buffer);
rq->ccw.flags = CCW_FLAG_SLI;
rq->rescnt = 0;
rq->rc = 0;
}
void
raw3270_request_set_cmd(struct raw3270_request *rq, u8 cmd)
{
rq->ccw.cmd_code = cmd;
}
int
raw3270_request_add_data(struct raw3270_request *rq, void *data, size_t size)
{
if (size + rq->ccw.count > rq->size)
return -E2BIG;
memcpy(rq->buffer + rq->ccw.count, data, size);
rq->ccw.count += size;
return 0;
}
void
raw3270_request_set_data(struct raw3270_request *rq, void *data, size_t size)
{
rq->ccw.cda = __pa(data);
rq->ccw.count = size;
}
void
raw3270_request_set_idal(struct raw3270_request *rq, struct idal_buffer *ib)
{
rq->ccw.cda = __pa(ib->data);
rq->ccw.count = ib->size;
rq->ccw.flags |= CCW_FLAG_IDA;
}
static int
__raw3270_halt_io(struct raw3270 *rp, struct raw3270_request *rq)
{
int retries;
int rc;
if (raw3270_request_final(rq))
return 0;
for (retries = 0; retries < 5; retries++) {
if (retries < 2)
rc = ccw_device_halt(rp->cdev, (long) rq);
else
rc = ccw_device_clear(rp->cdev, (long) rq);
if (rc == 0)
break;
}
return rc;
}
static int
__raw3270_start(struct raw3270 *rp, struct raw3270_view *view,
struct raw3270_request *rq)
{
rq->view = view;
raw3270_get_view(view);
if (list_empty(&rp->req_queue) &&
!test_bit(RAW3270_FLAGS_BUSY, &rp->flags)) {
rq->rc = ccw_device_start(rp->cdev, &rq->ccw,
(unsigned long) rq, 0, 0);
if (rq->rc) {
raw3270_put_view(view);
return rq->rc;
}
}
list_add_tail(&rq->list, &rp->req_queue);
return 0;
}
int
raw3270_view_active(struct raw3270_view *view)
{
struct raw3270 *rp = view->dev;
return rp && rp->view == view &&
!test_bit(RAW3270_FLAGS_FROZEN, &rp->flags);
}
int
raw3270_start(struct raw3270_view *view, struct raw3270_request *rq)
{
unsigned long flags;
struct raw3270 *rp;
int rc;
spin_lock_irqsave(get_ccwdev_lock(view->dev->cdev), flags);
rp = view->dev;
if (!rp || rp->view != view ||
test_bit(RAW3270_FLAGS_FROZEN, &rp->flags))
rc = -EACCES;
else if (!raw3270_state_ready(rp))
rc = -EBUSY;
else
rc = __raw3270_start(rp, view, rq);
spin_unlock_irqrestore(get_ccwdev_lock(view->dev->cdev), flags);
return rc;
}
int
raw3270_start_locked(struct raw3270_view *view, struct raw3270_request *rq)
{
struct raw3270 *rp;
int rc;
rp = view->dev;
if (!rp || rp->view != view ||
test_bit(RAW3270_FLAGS_FROZEN, &rp->flags))
rc = -EACCES;
else if (!raw3270_state_ready(rp))
rc = -EBUSY;
else
rc = __raw3270_start(rp, view, rq);
return rc;
}
int
raw3270_start_irq(struct raw3270_view *view, struct raw3270_request *rq)
{
struct raw3270 *rp;
rp = view->dev;
rq->view = view;
raw3270_get_view(view);
list_add_tail(&rq->list, &rp->req_queue);
return 0;
}
static void
raw3270_irq (struct ccw_device *cdev, unsigned long intparm, struct irb *irb)
{
struct raw3270 *rp;
struct raw3270_view *view;
struct raw3270_request *rq;
int rc;
rp = dev_get_drvdata(&cdev->dev);
if (!rp)
return;
rq = (struct raw3270_request *) intparm;
view = rq ? rq->view : rp->view;
if (IS_ERR(irb))
rc = RAW3270_IO_RETRY;
else if (irb->scsw.cmd.fctl & SCSW_FCTL_HALT_FUNC) {
rq->rc = -EIO;
rc = RAW3270_IO_DONE;
} else if (irb->scsw.cmd.dstat == (DEV_STAT_CHN_END | DEV_STAT_DEV_END |
DEV_STAT_UNIT_EXCEP)) {
set_bit(RAW3270_FLAGS_BUSY, &rp->flags);
rc = RAW3270_IO_BUSY;
} else if (test_bit(RAW3270_FLAGS_BUSY, &rp->flags)) {
if (irb->scsw.cmd.dstat & DEV_STAT_DEV_END) {
clear_bit(RAW3270_FLAGS_BUSY, &rp->flags);
rc = RAW3270_IO_RETRY;
} else
rc = RAW3270_IO_BUSY;
} else if (view)
rc = view->fn->intv(view, rq, irb);
else
rc = RAW3270_IO_DONE;
switch (rc) {
case RAW3270_IO_DONE:
break;
case RAW3270_IO_BUSY:
return;
case RAW3270_IO_RETRY:
if (!rq)
break;
rq->rc = ccw_device_start(rp->cdev, &rq->ccw,
(unsigned long) rq, 0, 0);
if (rq->rc == 0)
return;
break;
case RAW3270_IO_STOP:
if (!rq)
break;
__raw3270_halt_io(rp, rq);
rq->rc = -EIO;
break;
default:
BUG();
}
if (rq) {
BUG_ON(list_empty(&rq->list));
list_del_init(&rq->list);
if (rq->callback)
rq->callback(rq, rq->callback_data);
raw3270_put_view(view);
}
while (!list_empty(&rp->req_queue)) {
rq = list_entry(rp->req_queue.next,struct raw3270_request,list);
rq->rc = ccw_device_start(rp->cdev, &rq->ccw,
(unsigned long) rq, 0, 0);
if (rq->rc == 0)
break;
list_del_init(&rq->list);
if (rq->callback)
rq->callback(rq, rq->callback_data);
raw3270_put_view(view);
}
}
static void
raw3270_size_device_vm(struct raw3270 *rp)
{
int rc, model;
struct ccw_dev_id dev_id;
struct diag210 diag_data;
ccw_device_get_id(rp->cdev, &dev_id);
diag_data.vrdcdvno = dev_id.devno;
diag_data.vrdclen = sizeof(struct diag210);
rc = diag210(&diag_data);
model = diag_data.vrdccrmd;
if (rc || model < 2 || model > 5)
model = 2;
switch (model) {
case 2:
rp->model = model;
rp->rows = 24;
rp->cols = 80;
break;
case 3:
rp->model = model;
rp->rows = 32;
rp->cols = 80;
break;
case 4:
rp->model = model;
rp->rows = 43;
rp->cols = 80;
break;
case 5:
rp->model = model;
rp->rows = 27;
rp->cols = 132;
break;
}
}
static void
raw3270_size_device(struct raw3270 *rp)
{
struct raw3270_ua *uap;
uap = (struct raw3270_ua *) (rp->init_data + 1);
if (rp->init_readmod.rc || rp->init_data[0] != 0x88 ||
uap->uab.qcode != 0x81) {
rp->model = 2;
rp->rows = 24;
rp->cols = 80;
return;
}
rp->rows = uap->uab.h;
rp->cols = uap->uab.w;
if ((uap->uab.flags0 & 0x0d) == 0x01)
set_bit(RAW3270_FLAGS_14BITADDR, &rp->flags);
if (uap->uab.l == sizeof(struct raw3270_ua) &&
uap->aua.sdpid == 0x02) {
rp->rows = uap->aua.hauai;
rp->cols = uap->aua.wauai;
}
rp->model = 0;
if (rp->rows == 24 && rp->cols == 80)
rp->model = 2;
if (rp->rows == 32 && rp->cols == 80)
rp->model = 3;
if (rp->rows == 43 && rp->cols == 80)
rp->model = 4;
if (rp->rows == 27 && rp->cols == 132)
rp->model = 5;
}
static void
raw3270_size_device_done(struct raw3270 *rp)
{
struct raw3270_view *view;
rp->view = NULL;
rp->state = RAW3270_STATE_READY;
list_for_each_entry(view, &rp->view_list, list)
if (view->fn->resize)
view->fn->resize(view, rp->model, rp->rows, rp->cols);
list_for_each_entry(view, &rp->view_list, list) {
rp->view = view;
if (view->fn->activate(view) == 0)
break;
rp->view = NULL;
}
}
static void
raw3270_read_modified_cb(struct raw3270_request *rq, void *data)
{
struct raw3270 *rp = rq->view->dev;
raw3270_size_device(rp);
raw3270_size_device_done(rp);
}
static void
raw3270_read_modified(struct raw3270 *rp)
{
if (rp->state != RAW3270_STATE_W4ATTN)
return;
memset(&rp->init_readmod, 0, sizeof(rp->init_readmod));
memset(&rp->init_data, 0, sizeof(rp->init_data));
rp->init_readmod.ccw.cmd_code = TC_READMOD;
rp->init_readmod.ccw.flags = CCW_FLAG_SLI;
rp->init_readmod.ccw.count = sizeof(rp->init_data);
rp->init_readmod.ccw.cda = (__u32) __pa(rp->init_data);
rp->init_readmod.callback = raw3270_read_modified_cb;
rp->state = RAW3270_STATE_READMOD;
raw3270_start_irq(&rp->init_view, &rp->init_readmod);
}
static void
raw3270_writesf_readpart(struct raw3270 *rp)
{
static const unsigned char wbuf[] =
{ 0x00, 0x07, 0x01, 0xff, 0x03, 0x00, 0x81 };
memset(&rp->init_readpart, 0, sizeof(rp->init_readpart));
memset(&rp->init_data, 0, sizeof(rp->init_data));
memcpy(&rp->init_data, wbuf, sizeof(wbuf));
rp->init_readpart.ccw.cmd_code = TC_WRITESF;
rp->init_readpart.ccw.flags = CCW_FLAG_SLI;
rp->init_readpart.ccw.count = sizeof(wbuf);
rp->init_readpart.ccw.cda = (__u32) __pa(&rp->init_data);
rp->state = RAW3270_STATE_W4ATTN;
raw3270_start_irq(&rp->init_view, &rp->init_readpart);
}
static void
raw3270_reset_device_cb(struct raw3270_request *rq, void *data)
{
struct raw3270 *rp = rq->view->dev;
if (rp->state != RAW3270_STATE_RESET)
return;
if (rq->rc) {
rp->state = RAW3270_STATE_INIT;
} else if (MACHINE_IS_VM) {
raw3270_size_device_vm(rp);
raw3270_size_device_done(rp);
} else
raw3270_writesf_readpart(rp);
memset(&rp->init_reset, 0, sizeof(rp->init_reset));
memset(&rp->init_data, 0, sizeof(rp->init_data));
}
static int
__raw3270_reset_device(struct raw3270 *rp)
{
int rc;
if (rp->init_reset.view)
return -EBUSY;
rp->init_data[0] = TW_KR;
rp->init_reset.ccw.cmd_code = TC_EWRITEA;
rp->init_reset.ccw.flags = CCW_FLAG_SLI;
rp->init_reset.ccw.count = 1;
rp->init_reset.ccw.cda = (__u32) __pa(rp->init_data);
rp->init_reset.callback = raw3270_reset_device_cb;
rc = __raw3270_start(rp, &rp->init_view, &rp->init_reset);
if (rc == 0 && rp->state == RAW3270_STATE_INIT)
rp->state = RAW3270_STATE_RESET;
return rc;
}
static int
raw3270_reset_device(struct raw3270 *rp)
{
unsigned long flags;
int rc;
spin_lock_irqsave(get_ccwdev_lock(rp->cdev), flags);
rc = __raw3270_reset_device(rp);
spin_unlock_irqrestore(get_ccwdev_lock(rp->cdev), flags);
return rc;
}
int
raw3270_reset(struct raw3270_view *view)
{
struct raw3270 *rp;
int rc;
rp = view->dev;
if (!rp || rp->view != view ||
test_bit(RAW3270_FLAGS_FROZEN, &rp->flags))
rc = -EACCES;
else if (!raw3270_state_ready(rp))
rc = -EBUSY;
else
rc = raw3270_reset_device(view->dev);
return rc;
}
static int
raw3270_init_irq(struct raw3270_view *view, struct raw3270_request *rq,
struct irb *irb)
{
struct raw3270 *rp;
if (irb->scsw.cmd.dstat & DEV_STAT_UNIT_CHECK) {
if (irb->ecw[0] & SNS0_INTERVENTION_REQ) {
set_bit(RAW3270_FLAGS_BUSY, &view->dev->flags);
return RAW3270_IO_BUSY;
}
}
if (rq) {
if (irb->scsw.cmd.dstat & DEV_STAT_UNIT_CHECK) {
if (irb->ecw[0] & SNS0_CMD_REJECT)
rq->rc = -EOPNOTSUPP;
else
rq->rc = -EIO;
}
}
if (irb->scsw.cmd.dstat & DEV_STAT_ATTENTION) {
rp = view->dev;
raw3270_read_modified(rp);
}
return RAW3270_IO_DONE;
}
static int
raw3270_setup_device(struct ccw_device *cdev, struct raw3270 *rp, char *ascebc)
{
struct list_head *l;
struct raw3270 *tmp;
int minor;
memset(rp, 0, sizeof(struct raw3270));
memcpy(ascebc, _ascebc, 256);
if (tubxcorrect) {
ascebc['['] = 0xad;
ascebc[']'] = 0xbd;
ascebc['^'] = 0xb0;
}
rp->ascebc = ascebc;
rp->rows = 24;
rp->cols = 80;
INIT_LIST_HEAD(&rp->req_queue);
INIT_LIST_HEAD(&rp->view_list);
rp->init_view.dev = rp;
rp->init_view.fn = &raw3270_init_fn;
rp->view = &rp->init_view;
mutex_lock(&raw3270_mutex);
minor = RAW3270_FIRSTMINOR;
rp->minor = -1;
list_for_each(l, &raw3270_devices) {
tmp = list_entry(l, struct raw3270, list);
if (tmp->minor > minor) {
rp->minor = minor;
__list_add(&rp->list, l->prev, l);
break;
}
minor++;
}
if (rp->minor == -1 && minor < RAW3270_MAXDEVS + RAW3270_FIRSTMINOR) {
rp->minor = minor;
list_add_tail(&rp->list, &raw3270_devices);
}
mutex_unlock(&raw3270_mutex);
if (rp->minor == -1)
return -EUSERS;
rp->cdev = cdev;
dev_set_drvdata(&cdev->dev, rp);
cdev->handler = raw3270_irq;
return 0;
}
struct raw3270 __init *raw3270_setup_console(void)
{
struct ccw_device *cdev;
unsigned long flags;
struct raw3270 *rp;
char *ascebc;
int rc;
cdev = ccw_device_create_console(&raw3270_ccw_driver);
if (IS_ERR(cdev))
return ERR_CAST(cdev);
rp = kzalloc(sizeof(struct raw3270), GFP_KERNEL | GFP_DMA);
ascebc = kzalloc(256, GFP_KERNEL);
rc = raw3270_setup_device(cdev, rp, ascebc);
if (rc)
return ERR_PTR(rc);
set_bit(RAW3270_FLAGS_CONSOLE, &rp->flags);
rc = ccw_device_enable_console(cdev);
if (rc) {
ccw_device_destroy_console(cdev);
return ERR_PTR(rc);
}
spin_lock_irqsave(get_ccwdev_lock(rp->cdev), flags);
do {
__raw3270_reset_device(rp);
while (!raw3270_state_final(rp)) {
ccw_device_wait_idle(rp->cdev);
barrier();
}
} while (rp->state != RAW3270_STATE_READY);
spin_unlock_irqrestore(get_ccwdev_lock(rp->cdev), flags);
return rp;
}
void
raw3270_wait_cons_dev(struct raw3270 *rp)
{
unsigned long flags;
spin_lock_irqsave(get_ccwdev_lock(rp->cdev), flags);
ccw_device_wait_idle(rp->cdev);
spin_unlock_irqrestore(get_ccwdev_lock(rp->cdev), flags);
}
static struct raw3270 *
raw3270_create_device(struct ccw_device *cdev)
{
struct raw3270 *rp;
char *ascebc;
int rc;
rp = kzalloc(sizeof(struct raw3270), GFP_KERNEL | GFP_DMA);
if (!rp)
return ERR_PTR(-ENOMEM);
ascebc = kmalloc(256, GFP_KERNEL);
if (!ascebc) {
kfree(rp);
return ERR_PTR(-ENOMEM);
}
rc = raw3270_setup_device(cdev, rp, ascebc);
if (rc) {
kfree(rp->ascebc);
kfree(rp);
rp = ERR_PTR(rc);
}
get_device(&cdev->dev);
return rp;
}
int
raw3270_activate_view(struct raw3270_view *view)
{
struct raw3270 *rp;
struct raw3270_view *oldview, *nv;
unsigned long flags;
int rc;
rp = view->dev;
if (!rp)
return -ENODEV;
spin_lock_irqsave(get_ccwdev_lock(rp->cdev), flags);
if (rp->view == view)
rc = 0;
else if (!raw3270_state_ready(rp))
rc = -EBUSY;
else if (test_bit(RAW3270_FLAGS_FROZEN, &rp->flags))
rc = -EACCES;
else {
oldview = NULL;
if (rp->view && rp->view->fn->deactivate) {
oldview = rp->view;
oldview->fn->deactivate(oldview);
}
rp->view = view;
rc = view->fn->activate(view);
if (rc) {
rp->view = oldview;
if (!oldview || oldview->fn->activate(oldview) != 0) {
list_for_each_entry(nv, &rp->view_list, list)
if (nv != view && nv != oldview) {
rp->view = nv;
if (nv->fn->activate(nv) == 0)
break;
rp->view = NULL;
}
}
}
}
spin_unlock_irqrestore(get_ccwdev_lock(rp->cdev), flags);
return rc;
}
void
raw3270_deactivate_view(struct raw3270_view *view)
{
unsigned long flags;
struct raw3270 *rp;
rp = view->dev;
if (!rp)
return;
spin_lock_irqsave(get_ccwdev_lock(rp->cdev), flags);
if (rp->view == view) {
view->fn->deactivate(view);
rp->view = NULL;
list_del_init(&view->list);
list_add_tail(&view->list, &rp->view_list);
if (raw3270_state_ready(rp) &&
!test_bit(RAW3270_FLAGS_FROZEN, &rp->flags)) {
list_for_each_entry(view, &rp->view_list, list) {
rp->view = view;
if (view->fn->activate(view) == 0)
break;
rp->view = NULL;
}
}
}
spin_unlock_irqrestore(get_ccwdev_lock(rp->cdev), flags);
}
int
raw3270_add_view(struct raw3270_view *view, struct raw3270_fn *fn, int minor)
{
unsigned long flags;
struct raw3270 *rp;
int rc;
if (minor <= 0)
return -ENODEV;
mutex_lock(&raw3270_mutex);
rc = -ENODEV;
list_for_each_entry(rp, &raw3270_devices, list) {
if (rp->minor != minor)
continue;
spin_lock_irqsave(get_ccwdev_lock(rp->cdev), flags);
atomic_set(&view->ref_count, 2);
view->dev = rp;
view->fn = fn;
view->model = rp->model;
view->rows = rp->rows;
view->cols = rp->cols;
view->ascebc = rp->ascebc;
spin_lock_init(&view->lock);
list_add(&view->list, &rp->view_list);
rc = 0;
spin_unlock_irqrestore(get_ccwdev_lock(rp->cdev), flags);
break;
}
mutex_unlock(&raw3270_mutex);
return rc;
}
struct raw3270_view *
raw3270_find_view(struct raw3270_fn *fn, int minor)
{
struct raw3270 *rp;
struct raw3270_view *view, *tmp;
unsigned long flags;
mutex_lock(&raw3270_mutex);
view = ERR_PTR(-ENODEV);
list_for_each_entry(rp, &raw3270_devices, list) {
if (rp->minor != minor)
continue;
spin_lock_irqsave(get_ccwdev_lock(rp->cdev), flags);
list_for_each_entry(tmp, &rp->view_list, list) {
if (tmp->fn == fn) {
raw3270_get_view(tmp);
view = tmp;
break;
}
}
spin_unlock_irqrestore(get_ccwdev_lock(rp->cdev), flags);
break;
}
mutex_unlock(&raw3270_mutex);
return view;
}
void
raw3270_del_view(struct raw3270_view *view)
{
unsigned long flags;
struct raw3270 *rp;
struct raw3270_view *nv;
rp = view->dev;
spin_lock_irqsave(get_ccwdev_lock(rp->cdev), flags);
if (rp->view == view) {
view->fn->deactivate(view);
rp->view = NULL;
}
list_del_init(&view->list);
if (!rp->view && raw3270_state_ready(rp) &&
!test_bit(RAW3270_FLAGS_FROZEN, &rp->flags)) {
list_for_each_entry(nv, &rp->view_list, list) {
if (nv->fn->activate(nv) == 0) {
rp->view = nv;
break;
}
}
}
spin_unlock_irqrestore(get_ccwdev_lock(rp->cdev), flags);
atomic_dec(&view->ref_count);
wait_event(raw3270_wait_queue, atomic_read(&view->ref_count) == 0);
if (view->fn->free)
view->fn->free(view);
}
static void
raw3270_delete_device(struct raw3270 *rp)
{
struct ccw_device *cdev;
mutex_lock(&raw3270_mutex);
list_del_init(&rp->list);
mutex_unlock(&raw3270_mutex);
cdev = rp->cdev;
rp->cdev = NULL;
dev_set_drvdata(&cdev->dev, NULL);
cdev->handler = NULL;
put_device(&cdev->dev);
kfree(rp->ascebc);
kfree(rp);
}
static int
raw3270_probe (struct ccw_device *cdev)
{
return 0;
}
static ssize_t
raw3270_model_show(struct device *dev, struct device_attribute *attr, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%i\n",
((struct raw3270 *) dev_get_drvdata(dev))->model);
}
static ssize_t
raw3270_rows_show(struct device *dev, struct device_attribute *attr, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%i\n",
((struct raw3270 *) dev_get_drvdata(dev))->rows);
}
static ssize_t
raw3270_columns_show(struct device *dev, struct device_attribute *attr, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%i\n",
((struct raw3270 *) dev_get_drvdata(dev))->cols);
}
static int raw3270_create_attributes(struct raw3270 *rp)
{
return sysfs_create_group(&rp->cdev->dev.kobj, &raw3270_attr_group);
}
int raw3270_register_notifier(struct raw3270_notifier *notifier)
{
struct raw3270 *rp;
mutex_lock(&raw3270_mutex);
list_add_tail(&notifier->list, &raw3270_notifier);
list_for_each_entry(rp, &raw3270_devices, list)
notifier->create(rp->minor);
mutex_unlock(&raw3270_mutex);
return 0;
}
void raw3270_unregister_notifier(struct raw3270_notifier *notifier)
{
struct raw3270 *rp;
mutex_lock(&raw3270_mutex);
list_for_each_entry(rp, &raw3270_devices, list)
notifier->destroy(rp->minor);
list_del(&notifier->list);
mutex_unlock(&raw3270_mutex);
}
static int
raw3270_set_online (struct ccw_device *cdev)
{
struct raw3270_notifier *np;
struct raw3270 *rp;
int rc;
rp = raw3270_create_device(cdev);
if (IS_ERR(rp))
return PTR_ERR(rp);
rc = raw3270_create_attributes(rp);
if (rc)
goto failure;
raw3270_reset_device(rp);
mutex_lock(&raw3270_mutex);
list_for_each_entry(np, &raw3270_notifier, list)
np->create(rp->minor);
mutex_unlock(&raw3270_mutex);
return 0;
failure:
raw3270_delete_device(rp);
return rc;
}
static void
raw3270_remove (struct ccw_device *cdev)
{
unsigned long flags;
struct raw3270 *rp;
struct raw3270_view *v;
struct raw3270_notifier *np;
rp = dev_get_drvdata(&cdev->dev);
if (rp == NULL)
return;
sysfs_remove_group(&cdev->dev.kobj, &raw3270_attr_group);
spin_lock_irqsave(get_ccwdev_lock(cdev), flags);
if (rp->view) {
if (rp->view->fn->deactivate)
rp->view->fn->deactivate(rp->view);
rp->view = NULL;
}
while (!list_empty(&rp->view_list)) {
v = list_entry(rp->view_list.next, struct raw3270_view, list);
if (v->fn->release)
v->fn->release(v);
spin_unlock_irqrestore(get_ccwdev_lock(cdev), flags);
raw3270_del_view(v);
spin_lock_irqsave(get_ccwdev_lock(cdev), flags);
}
spin_unlock_irqrestore(get_ccwdev_lock(cdev), flags);
mutex_lock(&raw3270_mutex);
list_for_each_entry(np, &raw3270_notifier, list)
np->destroy(rp->minor);
mutex_unlock(&raw3270_mutex);
raw3270_reset_device(rp);
raw3270_delete_device(rp);
}
static int
raw3270_set_offline (struct ccw_device *cdev)
{
struct raw3270 *rp;
rp = dev_get_drvdata(&cdev->dev);
if (test_bit(RAW3270_FLAGS_CONSOLE, &rp->flags))
return -EBUSY;
raw3270_remove(cdev);
return 0;
}
static int raw3270_pm_stop(struct ccw_device *cdev)
{
struct raw3270 *rp;
struct raw3270_view *view;
unsigned long flags;
rp = dev_get_drvdata(&cdev->dev);
if (!rp)
return 0;
spin_lock_irqsave(get_ccwdev_lock(rp->cdev), flags);
if (rp->view && rp->view->fn->deactivate)
rp->view->fn->deactivate(rp->view);
if (!test_bit(RAW3270_FLAGS_CONSOLE, &rp->flags)) {
list_for_each_entry(view, &rp->view_list, list) {
if (view->fn->release)
view->fn->release(view);
}
}
set_bit(RAW3270_FLAGS_FROZEN, &rp->flags);
spin_unlock_irqrestore(get_ccwdev_lock(rp->cdev), flags);
return 0;
}
static int raw3270_pm_start(struct ccw_device *cdev)
{
struct raw3270 *rp;
unsigned long flags;
rp = dev_get_drvdata(&cdev->dev);
if (!rp)
return 0;
spin_lock_irqsave(get_ccwdev_lock(rp->cdev), flags);
clear_bit(RAW3270_FLAGS_FROZEN, &rp->flags);
if (rp->view && rp->view->fn->activate)
rp->view->fn->activate(rp->view);
spin_unlock_irqrestore(get_ccwdev_lock(rp->cdev), flags);
return 0;
}
void raw3270_pm_unfreeze(struct raw3270_view *view)
{
#ifdef CONFIG_TN3270_CONSOLE
struct raw3270 *rp;
rp = view->dev;
if (rp && test_bit(RAW3270_FLAGS_FROZEN, &rp->flags))
ccw_device_force_console(rp->cdev);
#endif
}
static int
raw3270_init(void)
{
struct raw3270 *rp;
int rc;
if (raw3270_registered)
return 0;
raw3270_registered = 1;
rc = ccw_driver_register(&raw3270_ccw_driver);
if (rc == 0) {
mutex_lock(&raw3270_mutex);
class3270 = class_create(THIS_MODULE, "3270");
list_for_each_entry(rp, &raw3270_devices, list) {
get_device(&rp->cdev->dev);
raw3270_create_attributes(rp);
}
mutex_unlock(&raw3270_mutex);
}
return rc;
}
static void
raw3270_exit(void)
{
ccw_driver_unregister(&raw3270_ccw_driver);
class_destroy(class3270);
}
