int dma_skb_copy_datagram_iovec(struct dma_chan *chan,
struct sk_buff *skb, int offset, struct iovec *to,
size_t len, struct dma_pinned_list *pinned_list)
{
int start = skb_headlen(skb);
int i, copy = start - offset;
struct sk_buff *frag_iter;
dma_cookie_t cookie = 0;
if (copy > 0) {
if (copy > len)
copy = len;
cookie = dma_memcpy_to_iovec(chan, to, pinned_list,
skb->data + offset, copy);
if (cookie < 0)
goto fault;
len -= copy;
if (len == 0)
goto end;
offset += copy;
}
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
int end;
WARN_ON(start > offset + len);
end = start + skb_shinfo(skb)->frags[i].size;
copy = end - offset;
if (copy > 0) {
skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
struct page *page = frag->page;
if (copy > len)
copy = len;
cookie = dma_memcpy_pg_to_iovec(chan, to, pinned_list, page,
frag->page_offset + offset - start, copy);
if (cookie < 0)
goto fault;
len -= copy;
if (len == 0)
goto end;
offset += copy;
}
start = end;
}
skb_walk_frags(skb, frag_iter) {
int end;
WARN_ON(start > offset + len);
end = start + frag_iter->len;
copy = end - offset;
if (copy > 0) {
if (copy > len)
copy = len;
cookie = dma_skb_copy_datagram_iovec(chan, frag_iter,
offset - start,
to, copy,
pinned_list);
if (cookie < 0)
goto fault;
len -= copy;
if (len == 0)
goto end;
offset += copy;
}
start = end;
}
end:
if (!len) {
skb->dma_cookie = cookie;
return cookie;
}
fault:
return -EFAULT;
}
