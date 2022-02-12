static inline struct rdac_dh_data *get_rdac_data(struct scsi_device *sdev)
{
return container_of(sdev->scsi_dh_data, struct rdac_dh_data, dh_data);
}
static struct request *get_rdac_req(struct scsi_device *sdev,
void *buffer, unsigned buflen, int rw)
{
struct request *rq;
struct request_queue *q = sdev->request_queue;
rq = blk_get_request(q, rw, GFP_NOIO);
if (IS_ERR(rq)) {
sdev_printk(KERN_INFO, sdev,
"get_rdac_req: blk_get_request failed.\n");
return NULL;
}
blk_rq_set_block_pc(rq);
if (buflen && blk_rq_map_kern(q, rq, buffer, buflen, GFP_NOIO)) {
blk_put_request(rq);
sdev_printk(KERN_INFO, sdev,
"get_rdac_req: blk_rq_map_kern failed.\n");
return NULL;
}
rq->cmd_flags |= REQ_FAILFAST_DEV | REQ_FAILFAST_TRANSPORT |
REQ_FAILFAST_DRIVER;
rq->retries = RDAC_RETRIES;
rq->timeout = RDAC_TIMEOUT;
return rq;
}
static struct request *rdac_failover_get(struct scsi_device *sdev,
struct rdac_dh_data *h, struct list_head *list)
{
struct request *rq;
struct rdac_mode_common *common;
unsigned data_size;
struct rdac_queue_data *qdata;
u8 *lun_table;
if (h->ctlr->use_ms10) {
struct rdac_pg_expanded *rdac_pg;
data_size = sizeof(struct rdac_pg_expanded);
rdac_pg = &h->ctlr->mode_select.expanded;
memset(rdac_pg, 0, data_size);
common = &rdac_pg->common;
rdac_pg->page_code = RDAC_PAGE_CODE_REDUNDANT_CONTROLLER + 0x40;
rdac_pg->subpage_code = 0x1;
rdac_pg->page_len[0] = 0x01;
rdac_pg->page_len[1] = 0x28;
lun_table = rdac_pg->lun_table;
} else {
struct rdac_pg_legacy *rdac_pg;
data_size = sizeof(struct rdac_pg_legacy);
rdac_pg = &h->ctlr->mode_select.legacy;
memset(rdac_pg, 0, data_size);
common = &rdac_pg->common;
rdac_pg->page_code = RDAC_PAGE_CODE_REDUNDANT_CONTROLLER;
rdac_pg->page_len = 0x68;
lun_table = rdac_pg->lun_table;
}
common->rdac_mode[1] = RDAC_MODE_TRANSFER_SPECIFIED_LUNS;
common->quiescence_timeout = RDAC_QUIESCENCE_TIME;
common->rdac_options = RDAC_FORCED_QUIESENCE;
list_for_each_entry(qdata, list, entry) {
lun_table[qdata->h->lun] = 0x81;
}
rq = get_rdac_req(sdev, &h->ctlr->mode_select, data_size, WRITE);
if (!rq)
return NULL;
if (h->ctlr->use_ms10) {
rq->cmd[0] = MODE_SELECT_10;
rq->cmd[7] = data_size >> 8;
rq->cmd[8] = data_size & 0xff;
} else {
rq->cmd[0] = MODE_SELECT;
rq->cmd[4] = data_size;
}
rq->cmd_len = COMMAND_SIZE(rq->cmd[0]);
rq->sense = h->sense;
memset(rq->sense, 0, SCSI_SENSE_BUFFERSIZE);
rq->sense_len = 0;
return rq;
}
static void release_controller(struct kref *kref)
{
struct rdac_controller *ctlr;
ctlr = container_of(kref, struct rdac_controller, kref);
list_del(&ctlr->node);
kfree(ctlr);
}
static struct rdac_controller *get_controller(int index, char *array_name,
u8 *array_id, struct scsi_device *sdev)
{
struct rdac_controller *ctlr, *tmp;
list_for_each_entry(tmp, &ctlr_list, node) {
if ((memcmp(tmp->array_id, array_id, UNIQUE_ID_LEN) == 0) &&
(tmp->index == index) &&
(tmp->host == sdev->host)) {
kref_get(&tmp->kref);
return tmp;
}
}
ctlr = kmalloc(sizeof(*ctlr), GFP_ATOMIC);
if (!ctlr)
return NULL;
memcpy(ctlr->array_id, array_id, UNIQUE_ID_LEN);
ctlr->index = index;
ctlr->host = sdev->host;
memcpy(ctlr->array_name, array_name, ARRAY_LABEL_LEN);
kref_init(&ctlr->kref);
ctlr->use_ms10 = -1;
ctlr->ms_queued = 0;
ctlr->ms_sdev = NULL;
spin_lock_init(&ctlr->ms_lock);
INIT_WORK(&ctlr->ms_work, send_mode_select);
INIT_LIST_HEAD(&ctlr->ms_head);
list_add(&ctlr->node, &ctlr_list);
return ctlr;
}
static int submit_inquiry(struct scsi_device *sdev, int page_code,
unsigned int len, struct rdac_dh_data *h)
{
struct request *rq;
struct request_queue *q = sdev->request_queue;
int err = SCSI_DH_RES_TEMP_UNAVAIL;
rq = get_rdac_req(sdev, &h->inq, len, READ);
if (!rq)
goto done;
rq->cmd[0] = INQUIRY;
rq->cmd[1] = 1;
rq->cmd[2] = page_code;
rq->cmd[4] = len;
rq->cmd_len = COMMAND_SIZE(INQUIRY);
rq->sense = h->sense;
memset(rq->sense, 0, SCSI_SENSE_BUFFERSIZE);
rq->sense_len = 0;
err = blk_execute_rq(q, NULL, rq, 1);
if (err == -EIO)
err = SCSI_DH_IO;
blk_put_request(rq);
done:
return err;
}
static int get_lun_info(struct scsi_device *sdev, struct rdac_dh_data *h,
char *array_name, u8 *array_id)
{
int err, i;
struct c8_inquiry *inqp;
err = submit_inquiry(sdev, 0xC8, sizeof(struct c8_inquiry), h);
if (err == SCSI_DH_OK) {
inqp = &h->inq.c8;
if (inqp->page_code != 0xc8)
return SCSI_DH_NOSYS;
if (inqp->page_id[0] != 'e' || inqp->page_id[1] != 'd' ||
inqp->page_id[2] != 'i' || inqp->page_id[3] != 'd')
return SCSI_DH_NOSYS;
h->lun = inqp->lun[7];
for(i=0; i<ARRAY_LABEL_LEN-1; ++i)
*(array_name+i) = inqp->array_user_label[(2*i)+1];
*(array_name+ARRAY_LABEL_LEN-1) = '\0';
memset(array_id, 0, UNIQUE_ID_LEN);
memcpy(array_id, inqp->array_unique_id, inqp->array_uniq_id_len);
}
return err;
}
static int check_ownership(struct scsi_device *sdev, struct rdac_dh_data *h)
{
int err;
struct c9_inquiry *inqp;
h->state = RDAC_STATE_ACTIVE;
err = submit_inquiry(sdev, 0xC9, sizeof(struct c9_inquiry), h);
if (err == SCSI_DH_OK) {
inqp = &h->inq.c9;
if ((inqp->avte_cvp >> 5) & 0x1)
h->mode = RDAC_MODE_IOSHIP;
else if (inqp->avte_cvp >> 7)
h->mode = RDAC_MODE_AVT;
else
h->mode = RDAC_MODE;
if (inqp->avte_cvp & 0x1)
h->lun_state = RDAC_LUN_OWNED;
else {
h->lun_state = RDAC_LUN_UNOWNED;
if (h->mode == RDAC_MODE)
h->state = RDAC_STATE_PASSIVE;
}
if (inqp->path_prio & 0x1)
h->preferred = RDAC_PREFERRED;
else
h->preferred = RDAC_NON_PREFERRED;
}
return err;
}
static int initialize_controller(struct scsi_device *sdev,
struct rdac_dh_data *h, char *array_name, u8 *array_id)
{
int err, index;
struct c4_inquiry *inqp;
err = submit_inquiry(sdev, 0xC4, sizeof(struct c4_inquiry), h);
if (err == SCSI_DH_OK) {
inqp = &h->inq.c4;
if (inqp->slot_id[1] == 0x31)
index = 0;
else
index = 1;
spin_lock(&list_lock);
h->ctlr = get_controller(index, array_name, array_id, sdev);
if (!h->ctlr)
err = SCSI_DH_RES_TEMP_UNAVAIL;
spin_unlock(&list_lock);
}
return err;
}
static int set_mode_select(struct scsi_device *sdev, struct rdac_dh_data *h)
{
int err;
struct c2_inquiry *inqp;
err = submit_inquiry(sdev, 0xC2, sizeof(struct c2_inquiry), h);
if (err == SCSI_DH_OK) {
inqp = &h->inq.c2;
if (inqp->max_lun_supported >= MODE6_MAX_LUN)
h->ctlr->use_ms10 = 1;
else
h->ctlr->use_ms10 = 0;
}
return err;
}
static int mode_select_handle_sense(struct scsi_device *sdev,
unsigned char *sensebuf)
{
struct scsi_sense_hdr sense_hdr;
int err = SCSI_DH_IO, ret;
struct rdac_dh_data *h = get_rdac_data(sdev);
ret = scsi_normalize_sense(sensebuf, SCSI_SENSE_BUFFERSIZE, &sense_hdr);
if (!ret)
goto done;
switch (sense_hdr.sense_key) {
case NO_SENSE:
case ABORTED_COMMAND:
case UNIT_ATTENTION:
err = SCSI_DH_RETRY;
break;
case NOT_READY:
if (sense_hdr.asc == 0x04 && sense_hdr.ascq == 0x01)
err = SCSI_DH_RETRY;
break;
case ILLEGAL_REQUEST:
if (sense_hdr.asc == 0x91 && sense_hdr.ascq == 0x36)
err = SCSI_DH_RETRY;
break;
default:
break;
}
RDAC_LOG(RDAC_LOG_FAILOVER, sdev, "array %s, ctlr %d, "
"MODE_SELECT returned with sense %02x/%02x/%02x",
(char *) h->ctlr->array_name, h->ctlr->index,
sense_hdr.sense_key, sense_hdr.asc, sense_hdr.ascq);
done:
return err;
}
static void send_mode_select(struct work_struct *work)
{
struct rdac_controller *ctlr =
container_of(work, struct rdac_controller, ms_work);
struct request *rq;
struct scsi_device *sdev = ctlr->ms_sdev;
struct rdac_dh_data *h = get_rdac_data(sdev);
struct request_queue *q = sdev->request_queue;
int err, retry_cnt = RDAC_RETRY_COUNT;
struct rdac_queue_data *tmp, *qdata;
LIST_HEAD(list);
spin_lock(&ctlr->ms_lock);
list_splice_init(&ctlr->ms_head, &list);
ctlr->ms_queued = 0;
ctlr->ms_sdev = NULL;
spin_unlock(&ctlr->ms_lock);
retry:
err = SCSI_DH_RES_TEMP_UNAVAIL;
rq = rdac_failover_get(sdev, h, &list);
if (!rq)
goto done;
RDAC_LOG(RDAC_LOG_FAILOVER, sdev, "array %s, ctlr %d, "
"%s MODE_SELECT command",
(char *) h->ctlr->array_name, h->ctlr->index,
(retry_cnt == RDAC_RETRY_COUNT) ? "queueing" : "retrying");
err = blk_execute_rq(q, NULL, rq, 1);
blk_put_request(rq);
if (err != SCSI_DH_OK) {
err = mode_select_handle_sense(sdev, h->sense);
if (err == SCSI_DH_RETRY && retry_cnt--)
goto retry;
}
if (err == SCSI_DH_OK) {
h->state = RDAC_STATE_ACTIVE;
RDAC_LOG(RDAC_LOG_FAILOVER, sdev, "array %s, ctlr %d, "
"MODE_SELECT completed",
(char *) h->ctlr->array_name, h->ctlr->index);
}
done:
list_for_each_entry_safe(qdata, tmp, &list, entry) {
list_del(&qdata->entry);
if (err == SCSI_DH_OK)
qdata->h->state = RDAC_STATE_ACTIVE;
if (qdata->callback_fn)
qdata->callback_fn(qdata->callback_data, err);
kfree(qdata);
}
return;
}
static int queue_mode_select(struct scsi_device *sdev,
activate_complete fn, void *data)
{
struct rdac_queue_data *qdata;
struct rdac_controller *ctlr;
qdata = kzalloc(sizeof(*qdata), GFP_KERNEL);
if (!qdata)
return SCSI_DH_RETRY;
qdata->h = get_rdac_data(sdev);
qdata->callback_fn = fn;
qdata->callback_data = data;
ctlr = qdata->h->ctlr;
spin_lock(&ctlr->ms_lock);
list_add_tail(&qdata->entry, &ctlr->ms_head);
if (!ctlr->ms_queued) {
ctlr->ms_queued = 1;
ctlr->ms_sdev = sdev;
queue_work(kmpath_rdacd, &ctlr->ms_work);
}
spin_unlock(&ctlr->ms_lock);
return SCSI_DH_OK;
}
static int rdac_activate(struct scsi_device *sdev,
activate_complete fn, void *data)
{
struct rdac_dh_data *h = get_rdac_data(sdev);
int err = SCSI_DH_OK;
int act = 0;
err = check_ownership(sdev, h);
if (err != SCSI_DH_OK)
goto done;
switch (h->mode) {
case RDAC_MODE:
if (h->lun_state == RDAC_LUN_UNOWNED)
act = 1;
break;
case RDAC_MODE_IOSHIP:
if ((h->lun_state == RDAC_LUN_UNOWNED) &&
(h->preferred == RDAC_PREFERRED))
act = 1;
break;
default:
break;
}
if (act) {
err = queue_mode_select(sdev, fn, data);
if (err == SCSI_DH_OK)
return 0;
}
done:
if (fn)
fn(data, err);
return 0;
}
static int rdac_prep_fn(struct scsi_device *sdev, struct request *req)
{
struct rdac_dh_data *h = get_rdac_data(sdev);
int ret = BLKPREP_OK;
if (h->state != RDAC_STATE_ACTIVE) {
ret = BLKPREP_KILL;
req->cmd_flags |= REQ_QUIET;
}
return ret;
}
static int rdac_check_sense(struct scsi_device *sdev,
struct scsi_sense_hdr *sense_hdr)
{
struct rdac_dh_data *h = get_rdac_data(sdev);
RDAC_LOG(RDAC_LOG_SENSE, sdev, "array %s, ctlr %d, "
"I/O returned with sense %02x/%02x/%02x",
(char *) h->ctlr->array_name, h->ctlr->index,
sense_hdr->sense_key, sense_hdr->asc, sense_hdr->ascq);
switch (sense_hdr->sense_key) {
case NOT_READY:
if (sense_hdr->asc == 0x04 && sense_hdr->ascq == 0x01)
return ADD_TO_MLQUEUE;
if (sense_hdr->asc == 0x04 && sense_hdr->ascq == 0x81)
return SUCCESS;
if (sense_hdr->asc == 0x04 && sense_hdr->ascq == 0xA1)
return ADD_TO_MLQUEUE;
if (sense_hdr->asc == 0xA1 && sense_hdr->ascq == 0x02)
return ADD_TO_MLQUEUE;
break;
case ILLEGAL_REQUEST:
if (sense_hdr->asc == 0x94 && sense_hdr->ascq == 0x01) {
h->state = RDAC_STATE_PASSIVE;
return SUCCESS;
}
break;
case UNIT_ATTENTION:
if (sense_hdr->asc == 0x29 && sense_hdr->ascq == 0x00)
return ADD_TO_MLQUEUE;
if (sense_hdr->asc == 0x8b && sense_hdr->ascq == 0x02)
return ADD_TO_MLQUEUE;
break;
}
return SCSI_RETURN_NOT_HANDLED;
}
static bool rdac_match(struct scsi_device *sdev)
{
int i;
if (scsi_device_tpgs(sdev))
return false;
for (i = 0; rdac_dev_list[i].vendor; i++) {
if (!strncmp(sdev->vendor, rdac_dev_list[i].vendor,
strlen(rdac_dev_list[i].vendor)) &&
!strncmp(sdev->model, rdac_dev_list[i].model,
strlen(rdac_dev_list[i].model))) {
return true;
}
}
return false;
}
static struct scsi_dh_data *rdac_bus_attach(struct scsi_device *sdev)
{
struct rdac_dh_data *h;
int err;
char array_name[ARRAY_LABEL_LEN];
char array_id[UNIQUE_ID_LEN];
h = kzalloc(sizeof(*h) , GFP_KERNEL);
if (!h)
return ERR_PTR(-ENOMEM);
h->lun = UNINITIALIZED_LUN;
h->state = RDAC_STATE_ACTIVE;
err = get_lun_info(sdev, h, array_name, array_id);
if (err != SCSI_DH_OK)
goto failed;
err = initialize_controller(sdev, h, array_name, array_id);
if (err != SCSI_DH_OK)
goto failed;
err = check_ownership(sdev, h);
if (err != SCSI_DH_OK)
goto clean_ctlr;
err = set_mode_select(sdev, h);
if (err != SCSI_DH_OK)
goto clean_ctlr;
sdev_printk(KERN_NOTICE, sdev,
"%s: LUN %d (%s) (%s)\n",
RDAC_NAME, h->lun, mode[(int)h->mode],
lun_state[(int)h->lun_state]);
return &h->dh_data;
clean_ctlr:
spin_lock(&list_lock);
kref_put(&h->ctlr->kref, release_controller);
spin_unlock(&list_lock);
failed:
kfree(h);
return ERR_PTR(-EINVAL);
}
static void rdac_bus_detach( struct scsi_device *sdev )
{
struct rdac_dh_data *h = get_rdac_data(sdev);
if (h->ctlr && h->ctlr->ms_queued)
flush_workqueue(kmpath_rdacd);
spin_lock(&list_lock);
if (h->ctlr)
kref_put(&h->ctlr->kref, release_controller);
spin_unlock(&list_lock);
kfree(h);
}
static int __init rdac_init(void)
{
int r;
r = scsi_register_device_handler(&rdac_dh);
if (r != 0) {
printk(KERN_ERR "Failed to register scsi device handler.");
goto done;
}
kmpath_rdacd = create_singlethread_workqueue("kmpath_rdacd");
if (!kmpath_rdacd) {
scsi_unregister_device_handler(&rdac_dh);
printk(KERN_ERR "kmpath_rdacd creation failed.\n");
r = -EINVAL;
}
done:
return r;
}
static void __exit rdac_exit(void)
{
destroy_workqueue(kmpath_rdacd);
scsi_unregister_device_handler(&rdac_dh);
}
