static int ishtp_hid_parse(struct hid_device *hid)
{
struct ishtp_hid_data *hid_data = hid->driver_data;
struct ishtp_cl_data *client_data = hid_data->client_data;
int rv;
rv = hid_parse_report(hid, client_data->report_descr[hid_data->index],
client_data->report_descr_size[hid_data->index]);
if (rv)
return rv;
return 0;
}
static int ishtp_hid_start(struct hid_device *hid)
{
return 0;
}
static void ishtp_hid_stop(struct hid_device *hid)
{
}
static int ishtp_hid_open(struct hid_device *hid)
{
return 0;
}
static void ishtp_hid_close(struct hid_device *hid)
{
}
static int ishtp_raw_request(struct hid_device *hdev, unsigned char reportnum,
__u8 *buf, size_t len, unsigned char rtype, int reqtype)
{
return 0;
}
static void ishtp_hid_request(struct hid_device *hid, struct hid_report *rep,
int reqtype)
{
struct ishtp_hid_data *hid_data = hid->driver_data;
unsigned int len = ((rep->size - 1) >> 3) + 1 + (rep->id > 0);
char *buf;
unsigned int header_size = sizeof(struct hostif_msg);
len += header_size;
hid_data->request_done = false;
switch (reqtype) {
case HID_REQ_GET_REPORT:
hid_ishtp_get_report(hid, rep->id, rep->type);
break;
case HID_REQ_SET_REPORT:
buf = kzalloc(len + 7, GFP_KERNEL);
if (!buf)
return;
hid_output_report(rep, buf + header_size);
hid_ishtp_set_feature(hid, buf, len, rep->id);
kfree(buf);
break;
}
}
static int ishtp_wait_for_response(struct hid_device *hid)
{
struct ishtp_hid_data *hid_data = hid->driver_data;
struct ishtp_cl_data *client_data = hid_data->client_data;
int rv;
hid_ishtp_trace(client_data, "%s hid %p\n", __func__, hid);
rv = ishtp_hid_link_ready_wait(hid_data->client_data);
if (rv)
return rv;
if (!hid_data->request_done)
wait_event_interruptible_timeout(hid_data->hid_wait,
hid_data->request_done, 3 * HZ);
if (!hid_data->request_done) {
hid_err(hid,
"timeout waiting for response from ISHTP device\n");
return -ETIMEDOUT;
}
hid_ishtp_trace(client_data, "%s hid %p done\n", __func__, hid);
hid_data->request_done = false;
return 0;
}
void ishtp_hid_wakeup(struct hid_device *hid)
{
struct ishtp_hid_data *hid_data = hid->driver_data;
hid_data->request_done = true;
wake_up_interruptible(&hid_data->hid_wait);
}
int ishtp_hid_probe(unsigned int cur_hid_dev,
struct ishtp_cl_data *client_data)
{
int rv;
struct hid_device *hid;
struct ishtp_hid_data *hid_data;
hid = hid_allocate_device();
if (IS_ERR(hid)) {
rv = PTR_ERR(hid);
return -ENOMEM;
}
hid_data = kzalloc(sizeof(*hid_data), GFP_KERNEL);
if (!hid_data) {
rv = -ENOMEM;
goto err_hid_data;
}
hid_data->index = cur_hid_dev;
hid_data->client_data = client_data;
init_waitqueue_head(&hid_data->hid_wait);
hid->driver_data = hid_data;
client_data->hid_sensor_hubs[cur_hid_dev] = hid;
hid->ll_driver = &ishtp_hid_ll_driver;
hid->bus = BUS_INTEL_ISHTP;
hid->dev.parent = &client_data->cl_device->dev;
hid->version = le16_to_cpu(ISH_HID_VERSION);
hid->vendor = le16_to_cpu(ISH_HID_VENDOR);
hid->product = le16_to_cpu(ISH_HID_PRODUCT);
snprintf(hid->name, sizeof(hid->name), "%s %04hX:%04hX", "hid-ishtp",
hid->vendor, hid->product);
rv = hid_add_device(hid);
if (rv)
goto err_hid_device;
hid_ishtp_trace(client_data, "%s allocated hid %p\n", __func__, hid);
return 0;
err_hid_device:
kfree(hid_data);
err_hid_data:
kfree(hid);
return rv;
}
void ishtp_hid_remove(struct ishtp_cl_data *client_data)
{
int i;
for (i = 0; i < client_data->num_hid_devices; ++i) {
if (client_data->hid_sensor_hubs[i]) {
kfree(client_data->hid_sensor_hubs[i]->driver_data);
hid_destroy_device(client_data->hid_sensor_hubs[i]);
client_data->hid_sensor_hubs[i] = NULL;
}
}
}
