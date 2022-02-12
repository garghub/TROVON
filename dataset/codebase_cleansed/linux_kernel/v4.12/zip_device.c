static inline u32 zip_cmd_queue_consumed(struct zip_device *zip_dev, int queue)
{
return ((zip_dev->iq[queue].sw_head - zip_dev->iq[queue].sw_tail) *
sizeof(u64 *));
}
u32 zip_load_instr(union zip_inst_s *instr,
struct zip_device *zip_dev)
{
union zip_quex_doorbell dbell;
u32 queue = 0;
u32 consumed = 0;
u64 *ncb_ptr = NULL;
union zip_nptr_s ncp;
if (smp_processor_id() % 2 == 0)
queue = 0;
else
queue = 1;
zip_dbg("CPU Core: %d Queue number:%d", smp_processor_id(), queue);
spin_lock(&zip_dev->iq[queue].lock);
zip_dbg("sw_head : %lx", zip_dev->iq[queue].sw_head);
zip_dbg("sw_tail : %lx", zip_dev->iq[queue].sw_tail);
consumed = zip_cmd_queue_consumed(zip_dev, queue);
if ((consumed + 128) == (ZIP_CMD_QBUF_SIZE - 8)) {
zip_dbg("Cmd queue space available for single command");
memcpy((u8 *)zip_dev->iq[queue].sw_head, (u8 *)instr,
sizeof(union zip_inst_s));
zip_dev->iq[queue].sw_head += 16;
ncb_ptr = zip_dev->iq[queue].sw_head;
zip_dbg("ncb addr :0x%lx sw_head addr :0x%lx",
ncb_ptr, zip_dev->iq[queue].sw_head - 16);
zip_dev->iq[queue].sw_head = zip_dev->iq[queue].sw_tail;
zip_dev->iq[queue].free_flag = 1;
ncp.u_reg64 = 0ull;
ncp.s.addr = __pa(zip_dev->iq[queue].sw_head);
*ncb_ptr = ncp.u_reg64;
zip_dbg("*ncb_ptr :0x%lx sw_head[phys] :0x%lx",
*ncb_ptr, __pa(zip_dev->iq[queue].sw_head));
zip_dev->iq[queue].pend_cnt++;
} else {
zip_dbg("Enough space is available for commands");
memcpy((u8 *)zip_dev->iq[queue].sw_head, (u8 *)instr,
sizeof(union zip_inst_s));
zip_dev->iq[queue].sw_head += 16;
zip_dev->iq[queue].pend_cnt++;
}
zip_dbg("sw_head :0x%lx sw_tail :0x%lx hw_tail :0x%lx",
zip_dev->iq[queue].sw_head, zip_dev->iq[queue].sw_tail,
zip_dev->iq[queue].hw_tail);
zip_dbg(" Pushed the new cmd : pend_cnt : %d",
zip_dev->iq[queue].pend_cnt);
dbell.u_reg64 = 0ull;
dbell.s.dbell_cnt = 1;
zip_reg_write(dbell.u_reg64,
(zip_dev->reg_base + ZIP_QUEX_DOORBELL(queue)));
spin_unlock(&zip_dev->iq[queue].lock);
return queue;
}
void zip_update_cmd_bufs(struct zip_device *zip_dev, u32 queue)
{
spin_lock(&zip_dev->iq[queue].lock);
if (zip_dev->iq[queue].free_flag == 1) {
zip_dbg("Free flag. Free cmd buffer, adjust sw head and tail");
zip_dev->iq[queue].free_flag = 0;
zip_dev->iq[queue].hw_tail = zip_dev->iq[queue].sw_head;
} else {
zip_dbg("Free flag not set. increment hw tail");
zip_dev->iq[queue].hw_tail += 16;
}
zip_dev->iq[queue].done_cnt++;
zip_dev->iq[queue].pend_cnt--;
zip_dbg("sw_head :0x%lx sw_tail :0x%lx hw_tail :0x%lx",
zip_dev->iq[queue].sw_head, zip_dev->iq[queue].sw_tail,
zip_dev->iq[queue].hw_tail);
zip_dbg(" Got CC : pend_cnt : %d\n", zip_dev->iq[queue].pend_cnt);
spin_unlock(&zip_dev->iq[queue].lock);
}
