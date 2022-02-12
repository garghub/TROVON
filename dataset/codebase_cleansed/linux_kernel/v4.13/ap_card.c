static ssize_t ap_hwtype_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ap_card *ac = to_ap_card(dev);
return snprintf(buf, PAGE_SIZE, "%d\n", ac->ap_dev.device_type);
}
static ssize_t ap_raw_hwtype_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ap_card *ac = to_ap_card(dev);
return snprintf(buf, PAGE_SIZE, "%d\n", ac->raw_hwtype);
}
static ssize_t ap_depth_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct ap_card *ac = to_ap_card(dev);
return snprintf(buf, PAGE_SIZE, "%d\n", ac->queue_depth);
}
static ssize_t ap_functions_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ap_card *ac = to_ap_card(dev);
return snprintf(buf, PAGE_SIZE, "0x%08X\n", ac->functions);
}
static ssize_t ap_req_count_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ap_card *ac = to_ap_card(dev);
unsigned int req_cnt;
req_cnt = 0;
spin_lock_bh(&ap_list_lock);
req_cnt = atomic_read(&ac->total_request_count);
spin_unlock_bh(&ap_list_lock);
return snprintf(buf, PAGE_SIZE, "%d\n", req_cnt);
}
static ssize_t ap_req_count_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct ap_card *ac = to_ap_card(dev);
struct ap_queue *aq;
spin_lock_bh(&ap_list_lock);
for_each_ap_queue(aq, ac)
aq->total_request_count = 0;
spin_unlock_bh(&ap_list_lock);
atomic_set(&ac->total_request_count, 0);
return count;
}
static ssize_t ap_requestq_count_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ap_card *ac = to_ap_card(dev);
struct ap_queue *aq;
unsigned int reqq_cnt;
reqq_cnt = 0;
spin_lock_bh(&ap_list_lock);
for_each_ap_queue(aq, ac)
reqq_cnt += aq->requestq_count;
spin_unlock_bh(&ap_list_lock);
return snprintf(buf, PAGE_SIZE, "%d\n", reqq_cnt);
}
static ssize_t ap_pendingq_count_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ap_card *ac = to_ap_card(dev);
struct ap_queue *aq;
unsigned int penq_cnt;
penq_cnt = 0;
spin_lock_bh(&ap_list_lock);
for_each_ap_queue(aq, ac)
penq_cnt += aq->pendingq_count;
spin_unlock_bh(&ap_list_lock);
return snprintf(buf, PAGE_SIZE, "%d\n", penq_cnt);
}
static ssize_t ap_modalias_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "ap:t%02X\n", to_ap_dev(dev)->device_type);
}
static void ap_card_device_release(struct device *dev)
{
struct ap_card *ac = to_ap_card(dev);
if (!list_empty(&ac->list)) {
spin_lock_bh(&ap_list_lock);
list_del_init(&ac->list);
spin_unlock_bh(&ap_list_lock);
}
kfree(ac);
}
struct ap_card *ap_card_create(int id, int queue_depth, int device_type,
unsigned int functions)
{
struct ap_card *ac;
ac = kzalloc(sizeof(*ac), GFP_KERNEL);
if (!ac)
return NULL;
INIT_LIST_HEAD(&ac->queues);
ac->ap_dev.device.release = ap_card_device_release;
ac->ap_dev.device.type = &ap_card_type;
ac->ap_dev.device_type = device_type;
if (device_type == AP_DEVICE_TYPE_CEX6)
ac->ap_dev.device_type = AP_DEVICE_TYPE_CEX5;
ac->raw_hwtype = device_type;
ac->queue_depth = queue_depth;
ac->functions = functions;
ac->id = id;
return ac;
}
