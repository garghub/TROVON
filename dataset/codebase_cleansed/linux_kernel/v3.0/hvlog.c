void HvCall_writeLogBuffer(const void *buffer, u64 len)
{
struct HvLpBufferList hv_buf;
u64 left_this_page;
u64 cur = virt_to_abs(buffer);
while (len) {
hv_buf.addr = cur;
left_this_page = ((cur & HW_PAGE_MASK) + HW_PAGE_SIZE) - cur;
if (left_this_page > len)
left_this_page = len;
hv_buf.len = left_this_page;
len -= left_this_page;
HvCall2(HvCallBaseWriteLogBuffer,
virt_to_abs(&hv_buf),
left_this_page);
cur = (cur & HW_PAGE_MASK) + HW_PAGE_SIZE;
}
}
