int zip_cmd_qbuf_alloc(struct zip_device *zip, int q)
{
zip->iq[q].sw_head = (u64 *)__get_free_pages((GFP_KERNEL | GFP_DMA),
get_order(ZIP_CMD_QBUF_SIZE));
if (!zip->iq[q].sw_head)
return -ENOMEM;
memset(zip->iq[q].sw_head, 0, ZIP_CMD_QBUF_SIZE);
zip_dbg("cmd_qbuf_alloc[%d] Success : %p\n", q, zip->iq[q].sw_head);
return 0;
}
void zip_cmd_qbuf_free(struct zip_device *zip, int q)
{
zip_dbg("Freeing cmd_qbuf 0x%lx\n", zip->iq[q].sw_tail);
free_pages((u64)zip->iq[q].sw_tail, get_order(ZIP_CMD_QBUF_SIZE));
}
u8 *zip_data_buf_alloc(u64 size)
{
u8 *ptr;
ptr = (u8 *)__get_free_pages((GFP_KERNEL | GFP_DMA),
get_order(size));
if (!ptr)
return NULL;
memset(ptr, 0, size);
zip_dbg("Data buffer allocation success\n");
return ptr;
}
void zip_data_buf_free(u8 *ptr, u64 size)
{
zip_dbg("Freeing data buffer 0x%lx\n", ptr);
free_pages((u64)ptr, get_order(size));
}
