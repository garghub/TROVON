static int brcmf_cfg80211_vndr_cmds_dcmd_handler(struct wiphy *wiphy,
struct wireless_dev *wdev,
const void *data, int len)
{
struct brcmf_cfg80211_vif *vif;
struct brcmf_if *ifp;
const struct brcmf_vndr_dcmd_hdr *cmdhdr = data;
struct sk_buff *reply;
int ret, payload, ret_len;
void *dcmd_buf = NULL, *wr_pointer;
u16 msglen, maxmsglen = PAGE_SIZE - 0x100;
brcmf_dbg(TRACE, "cmd %x set %d len %d\n", cmdhdr->cmd, cmdhdr->set,
cmdhdr->len);
vif = container_of(wdev, struct brcmf_cfg80211_vif, wdev);
ifp = vif->ifp;
len -= sizeof(struct brcmf_vndr_dcmd_hdr);
ret_len = cmdhdr->len;
if (ret_len > 0 || len > 0) {
if (len > BRCMF_DCMD_MAXLEN) {
brcmf_err("oversize input buffer %d\n", len);
len = BRCMF_DCMD_MAXLEN;
}
if (ret_len > BRCMF_DCMD_MAXLEN) {
brcmf_err("oversize return buffer %d\n", ret_len);
ret_len = BRCMF_DCMD_MAXLEN;
}
payload = max(ret_len, len) + 1;
dcmd_buf = vzalloc(payload);
if (NULL == dcmd_buf)
return -ENOMEM;
memcpy(dcmd_buf, (void *)cmdhdr + cmdhdr->offset, len);
*(char *)(dcmd_buf + len) = '\0';
}
if (cmdhdr->set)
ret = brcmf_fil_cmd_data_set(ifp, cmdhdr->cmd, dcmd_buf,
ret_len);
else
ret = brcmf_fil_cmd_data_get(ifp, cmdhdr->cmd, dcmd_buf,
ret_len);
if (ret != 0)
goto exit;
wr_pointer = dcmd_buf;
while (ret_len > 0) {
msglen = ret_len > maxmsglen ? maxmsglen : ret_len;
ret_len -= msglen;
payload = msglen + sizeof(msglen);
reply = cfg80211_vendor_cmd_alloc_reply_skb(wiphy, payload);
if (NULL == reply) {
ret = -ENOMEM;
break;
}
if (nla_put(reply, BRCMF_NLATTR_DATA, msglen, wr_pointer) ||
nla_put_u16(reply, BRCMF_NLATTR_LEN, msglen)) {
kfree_skb(reply);
ret = -ENOBUFS;
break;
}
ret = cfg80211_vendor_cmd_reply(reply);
if (ret)
break;
wr_pointer += msglen;
}
exit:
vfree(dcmd_buf);
return ret;
}
