int nfc_hci_hcp_message_tx(struct nfc_hci_dev *hdev, u8 pipe,
u8 type, u8 instruction,
const u8 *payload, size_t payload_len,
hci_cmd_cb_t cb, void *cb_data,
unsigned long completion_delay)
{
struct nfc_dev *ndev = hdev->ndev;
struct hci_msg *cmd;
const u8 *ptr = payload;
int hci_len, err;
bool firstfrag = true;
cmd = kzalloc(sizeof(struct hci_msg), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
INIT_LIST_HEAD(&cmd->msg_l);
skb_queue_head_init(&cmd->msg_frags);
cmd->wait_response = (type == NFC_HCI_HCP_COMMAND) ? true : false;
cmd->cb = cb;
cmd->cb_context = cb_data;
cmd->completion_delay = completion_delay;
hci_len = payload_len + 1;
while (hci_len > 0) {
struct sk_buff *skb;
int skb_len, data_link_len;
struct hcp_packet *packet;
if (NFC_HCI_HCP_PACKET_HEADER_LEN + hci_len <=
hdev->max_data_link_payload)
data_link_len = hci_len;
else
data_link_len = hdev->max_data_link_payload -
NFC_HCI_HCP_PACKET_HEADER_LEN;
skb_len = ndev->tx_headroom + NFC_HCI_HCP_PACKET_HEADER_LEN +
data_link_len + ndev->tx_tailroom;
hci_len -= data_link_len;
skb = alloc_skb(skb_len, GFP_KERNEL);
if (skb == NULL) {
err = -ENOMEM;
goto out_skb_err;
}
skb_reserve(skb, ndev->tx_headroom);
skb_put(skb, NFC_HCI_HCP_PACKET_HEADER_LEN + data_link_len);
packet = (struct hcp_packet *)skb->data;
packet->header = pipe;
if (firstfrag) {
firstfrag = false;
packet->message.header = HCP_HEADER(type, instruction);
if (ptr) {
memcpy(packet->message.data, ptr,
data_link_len - 1);
ptr += data_link_len - 1;
}
} else {
memcpy(&packet->message, ptr, data_link_len);
ptr += data_link_len;
}
if (hci_len == 0)
packet->header |= ~NFC_HCI_FRAGMENT;
skb_queue_tail(&cmd->msg_frags, skb);
}
mutex_lock(&hdev->msg_tx_mutex);
list_add_tail(&hdev->msg_tx_queue, &cmd->msg_l);
mutex_unlock(&hdev->msg_tx_mutex);
queue_work(hdev->msg_tx_wq, &hdev->msg_tx_work);
return 0;
out_skb_err:
skb_queue_purge(&cmd->msg_frags);
kfree(cmd);
return err;
}
u8 nfc_hci_pipe2gate(struct nfc_hci_dev *hdev, u8 pipe)
{
int gate;
for (gate = 0; gate < NFC_HCI_MAX_GATES; gate++)
if (hdev->gate2pipe[gate] == pipe)
return gate;
return 0xff;
}
void nfc_hci_hcp_message_rx(struct nfc_hci_dev *hdev, u8 pipe, u8 type,
u8 instruction, struct sk_buff *skb)
{
switch (type) {
case NFC_HCI_HCP_RESPONSE:
nfc_hci_resp_received(hdev, instruction, skb);
break;
case NFC_HCI_HCP_COMMAND:
nfc_hci_cmd_received(hdev, pipe, instruction, skb);
break;
case NFC_HCI_HCP_EVENT:
nfc_hci_event_received(hdev, pipe, instruction, skb);
break;
default:
pr_err("UNKNOWN MSG Type %d, instruction=%d\n",
type, instruction);
kfree_skb(skb);
break;
}
}
