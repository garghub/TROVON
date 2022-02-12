void hci_req_init(struct hci_request *req, struct hci_dev *hdev)
{
skb_queue_head_init(&req->cmd_q);
req->hdev = hdev;
req->err = 0;
}
int hci_req_run(struct hci_request *req, hci_req_complete_t complete)
{
struct hci_dev *hdev = req->hdev;
struct sk_buff *skb;
unsigned long flags;
BT_DBG("length %u", skb_queue_len(&req->cmd_q));
if (req->err) {
skb_queue_purge(&req->cmd_q);
return req->err;
}
if (skb_queue_empty(&req->cmd_q))
return -ENODATA;
skb = skb_peek_tail(&req->cmd_q);
bt_cb(skb)->req.complete = complete;
spin_lock_irqsave(&hdev->cmd_q.lock, flags);
skb_queue_splice_tail(&req->cmd_q, &hdev->cmd_q);
spin_unlock_irqrestore(&hdev->cmd_q.lock, flags);
queue_work(hdev->workqueue, &hdev->cmd_work);
return 0;
}
struct sk_buff *hci_prepare_cmd(struct hci_dev *hdev, u16 opcode, u32 plen,
const void *param)
{
int len = HCI_COMMAND_HDR_SIZE + plen;
struct hci_command_hdr *hdr;
struct sk_buff *skb;
skb = bt_skb_alloc(len, GFP_ATOMIC);
if (!skb)
return NULL;
hdr = (struct hci_command_hdr *) skb_put(skb, HCI_COMMAND_HDR_SIZE);
hdr->opcode = cpu_to_le16(opcode);
hdr->plen = plen;
if (plen)
memcpy(skb_put(skb, plen), param, plen);
BT_DBG("skb len %d", skb->len);
bt_cb(skb)->pkt_type = HCI_COMMAND_PKT;
bt_cb(skb)->opcode = opcode;
return skb;
}
void hci_req_add_ev(struct hci_request *req, u16 opcode, u32 plen,
const void *param, u8 event)
{
struct hci_dev *hdev = req->hdev;
struct sk_buff *skb;
BT_DBG("%s opcode 0x%4.4x plen %d", hdev->name, opcode, plen);
if (req->err)
return;
skb = hci_prepare_cmd(hdev, opcode, plen, param);
if (!skb) {
BT_ERR("%s no memory for command (opcode 0x%4.4x)",
hdev->name, opcode);
req->err = -ENOMEM;
return;
}
if (skb_queue_empty(&req->cmd_q))
bt_cb(skb)->req.start = true;
bt_cb(skb)->req.event = event;
skb_queue_tail(&req->cmd_q, skb);
}
void hci_req_add(struct hci_request *req, u16 opcode, u32 plen,
const void *param)
{
hci_req_add_ev(req, opcode, plen, param, 0);
}
void hci_req_add_le_scan_disable(struct hci_request *req)
{
struct hci_cp_le_set_scan_enable cp;
memset(&cp, 0, sizeof(cp));
cp.enable = LE_SCAN_DISABLE;
hci_req_add(req, HCI_OP_LE_SET_SCAN_ENABLE, sizeof(cp), &cp);
}
static void add_to_white_list(struct hci_request *req,
struct hci_conn_params *params)
{
struct hci_cp_le_add_to_white_list cp;
cp.bdaddr_type = params->addr_type;
bacpy(&cp.bdaddr, &params->addr);
hci_req_add(req, HCI_OP_LE_ADD_TO_WHITE_LIST, sizeof(cp), &cp);
}
static u8 update_white_list(struct hci_request *req)
{
struct hci_dev *hdev = req->hdev;
struct hci_conn_params *params;
struct bdaddr_list *b;
uint8_t white_list_entries = 0;
list_for_each_entry(b, &hdev->le_white_list, list) {
struct hci_cp_le_del_from_white_list cp;
if (hci_pend_le_action_lookup(&hdev->pend_le_conns,
&b->bdaddr, b->bdaddr_type) ||
hci_pend_le_action_lookup(&hdev->pend_le_reports,
&b->bdaddr, b->bdaddr_type)) {
white_list_entries++;
continue;
}
cp.bdaddr_type = b->bdaddr_type;
bacpy(&cp.bdaddr, &b->bdaddr);
hci_req_add(req, HCI_OP_LE_DEL_FROM_WHITE_LIST,
sizeof(cp), &cp);
}
list_for_each_entry(params, &hdev->pend_le_conns, action) {
if (hci_bdaddr_list_lookup(&hdev->le_white_list,
&params->addr, params->addr_type))
continue;
if (white_list_entries >= hdev->le_white_list_size) {
return 0x00;
}
if (hci_find_irk_by_addr(hdev, &params->addr,
params->addr_type)) {
return 0x00;
}
white_list_entries++;
add_to_white_list(req, params);
}
list_for_each_entry(params, &hdev->pend_le_reports, action) {
if (hci_bdaddr_list_lookup(&hdev->le_white_list,
&params->addr, params->addr_type))
continue;
if (white_list_entries >= hdev->le_white_list_size) {
return 0x00;
}
if (hci_find_irk_by_addr(hdev, &params->addr,
params->addr_type)) {
return 0x00;
}
white_list_entries++;
add_to_white_list(req, params);
}
return 0x01;
}
void hci_req_add_le_passive_scan(struct hci_request *req)
{
struct hci_cp_le_set_scan_param param_cp;
struct hci_cp_le_set_scan_enable enable_cp;
struct hci_dev *hdev = req->hdev;
u8 own_addr_type;
u8 filter_policy;
if (hci_update_random_address(req, false, &own_addr_type))
return;
filter_policy = update_white_list(req);
if (test_bit(HCI_PRIVACY, &hdev->dev_flags) &&
(hdev->le_features[0] & HCI_LE_EXT_SCAN_POLICY))
filter_policy |= 0x02;
memset(&param_cp, 0, sizeof(param_cp));
param_cp.type = LE_SCAN_PASSIVE;
param_cp.interval = cpu_to_le16(hdev->le_scan_interval);
param_cp.window = cpu_to_le16(hdev->le_scan_window);
param_cp.own_address_type = own_addr_type;
param_cp.filter_policy = filter_policy;
hci_req_add(req, HCI_OP_LE_SET_SCAN_PARAM, sizeof(param_cp),
&param_cp);
memset(&enable_cp, 0, sizeof(enable_cp));
enable_cp.enable = LE_SCAN_ENABLE;
enable_cp.filter_dup = LE_SCAN_FILTER_DUP_ENABLE;
hci_req_add(req, HCI_OP_LE_SET_SCAN_ENABLE, sizeof(enable_cp),
&enable_cp);
}
static void set_random_addr(struct hci_request *req, bdaddr_t *rpa)
{
struct hci_dev *hdev = req->hdev;
if (test_bit(HCI_LE_ADV, &hdev->dev_flags) ||
hci_conn_hash_lookup_state(hdev, LE_LINK, BT_CONNECT)) {
BT_DBG("Deferring random address update");
set_bit(HCI_RPA_EXPIRED, &hdev->dev_flags);
return;
}
hci_req_add(req, HCI_OP_LE_SET_RANDOM_ADDR, 6, rpa);
}
int hci_update_random_address(struct hci_request *req, bool require_privacy,
u8 *own_addr_type)
{
struct hci_dev *hdev = req->hdev;
int err;
if (test_bit(HCI_PRIVACY, &hdev->dev_flags)) {
int to;
*own_addr_type = ADDR_LE_DEV_RANDOM;
if (!test_and_clear_bit(HCI_RPA_EXPIRED, &hdev->dev_flags) &&
!bacmp(&hdev->random_addr, &hdev->rpa))
return 0;
err = smp_generate_rpa(hdev, hdev->irk, &hdev->rpa);
if (err < 0) {
BT_ERR("%s failed to generate new RPA", hdev->name);
return err;
}
set_random_addr(req, &hdev->rpa);
to = msecs_to_jiffies(hdev->rpa_timeout * 1000);
queue_delayed_work(hdev->workqueue, &hdev->rpa_expired, to);
return 0;
}
if (require_privacy) {
bdaddr_t nrpa;
while (true) {
get_random_bytes(&nrpa, 6);
nrpa.b[5] &= 0x3f;
if (bacmp(&hdev->bdaddr, &nrpa))
break;
}
*own_addr_type = ADDR_LE_DEV_RANDOM;
set_random_addr(req, &nrpa);
return 0;
}
if (test_bit(HCI_FORCE_STATIC_ADDR, &hdev->dbg_flags) ||
!bacmp(&hdev->bdaddr, BDADDR_ANY) ||
(!test_bit(HCI_BREDR_ENABLED, &hdev->dev_flags) &&
bacmp(&hdev->static_addr, BDADDR_ANY))) {
*own_addr_type = ADDR_LE_DEV_RANDOM;
if (bacmp(&hdev->static_addr, &hdev->random_addr))
hci_req_add(req, HCI_OP_LE_SET_RANDOM_ADDR, 6,
&hdev->static_addr);
return 0;
}
*own_addr_type = ADDR_LE_DEV_PUBLIC;
return 0;
}
static bool disconnected_whitelist_entries(struct hci_dev *hdev)
{
struct bdaddr_list *b;
list_for_each_entry(b, &hdev->whitelist, list) {
struct hci_conn *conn;
conn = hci_conn_hash_lookup_ba(hdev, ACL_LINK, &b->bdaddr);
if (!conn)
return true;
if (conn->state != BT_CONNECTED && conn->state != BT_CONFIG)
return true;
}
return false;
}
void __hci_update_page_scan(struct hci_request *req)
{
struct hci_dev *hdev = req->hdev;
u8 scan;
if (!test_bit(HCI_BREDR_ENABLED, &hdev->dev_flags))
return;
if (!hdev_is_powered(hdev))
return;
if (mgmt_powering_down(hdev))
return;
if (test_bit(HCI_CONNECTABLE, &hdev->dev_flags) ||
disconnected_whitelist_entries(hdev))
scan = SCAN_PAGE;
else
scan = SCAN_DISABLED;
if (test_bit(HCI_PSCAN, &hdev->flags) == !!(scan & SCAN_PAGE))
return;
if (test_bit(HCI_DISCOVERABLE, &hdev->dev_flags))
scan |= SCAN_INQUIRY;
hci_req_add(req, HCI_OP_WRITE_SCAN_ENABLE, 1, &scan);
}
void hci_update_page_scan(struct hci_dev *hdev)
{
struct hci_request req;
hci_req_init(&req, hdev);
__hci_update_page_scan(&req);
hci_req_run(&req, NULL);
}
void __hci_update_background_scan(struct hci_request *req)
{
struct hci_dev *hdev = req->hdev;
struct hci_conn *conn;
if (!test_bit(HCI_UP, &hdev->flags) ||
test_bit(HCI_INIT, &hdev->flags) ||
test_bit(HCI_SETUP, &hdev->dev_flags) ||
test_bit(HCI_CONFIG, &hdev->dev_flags) ||
test_bit(HCI_AUTO_OFF, &hdev->dev_flags) ||
test_bit(HCI_UNREGISTER, &hdev->dev_flags))
return;
if (!test_bit(HCI_LE_ENABLED, &hdev->dev_flags))
return;
if (hdev->discovery.state != DISCOVERY_STOPPED)
return;
hci_discovery_filter_clear(hdev);
if (list_empty(&hdev->pend_le_conns) &&
list_empty(&hdev->pend_le_reports)) {
if (!test_bit(HCI_LE_SCAN, &hdev->dev_flags))
return;
hci_req_add_le_scan_disable(req);
BT_DBG("%s stopping background scanning", hdev->name);
} else {
conn = hci_conn_hash_lookup_state(hdev, LE_LINK, BT_CONNECT);
if (conn)
return;
if (test_bit(HCI_LE_SCAN, &hdev->dev_flags))
hci_req_add_le_scan_disable(req);
hci_req_add_le_passive_scan(req);
BT_DBG("%s starting background scanning", hdev->name);
}
}
static void update_background_scan_complete(struct hci_dev *hdev, u8 status,
u16 opcode)
{
if (status)
BT_DBG("HCI request failed to update background scanning: "
"status 0x%2.2x", status);
}
void hci_update_background_scan(struct hci_dev *hdev)
{
int err;
struct hci_request req;
hci_req_init(&req, hdev);
__hci_update_background_scan(&req);
err = hci_req_run(&req, update_background_scan_complete);
if (err && err != -ENODATA)
BT_ERR("Failed to run HCI request: err %d", err);
}
