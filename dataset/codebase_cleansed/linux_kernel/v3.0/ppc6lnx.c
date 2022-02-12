static int ppc6_select(Interface *ppc)
{
u8 i, j, k;
i = inb(ppc->lpt_addr + 1);
if (i & 1)
outb(i, ppc->lpt_addr + 1);
ppc->org_data = inb(ppc->lpt_addr);
ppc->org_ctrl = inb(ppc->lpt_addr + 2) & 0x5F;
ppc->cur_ctrl = ppc->org_ctrl;
ppc->cur_ctrl |= port_sel;
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
if (ppc->org_data == 'b')
outb('x', ppc->lpt_addr);
outb('b', ppc->lpt_addr);
outb('p', ppc->lpt_addr);
outb(ppc->ppc_id, ppc->lpt_addr);
outb(~ppc->ppc_id,ppc->lpt_addr);
ppc->cur_ctrl &= ~port_sel;
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
ppc->cur_ctrl = (ppc->cur_ctrl & port_int) | port_init;
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
i = ppc->mode & 0x0C;
if (i == 0)
i = (ppc->mode & 2) | 1;
outb(i, ppc->lpt_addr);
ppc->cur_ctrl |= port_sel;
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
ppc->cur_ctrl |= port_afd;
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
j = ((i & 0x08) << 4) | ((i & 0x07) << 3);
k = inb(ppc->lpt_addr + 1) & 0xB8;
if (j == k)
{
ppc->cur_ctrl &= ~port_afd;
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
k = (inb(ppc->lpt_addr + 1) & 0xB8) ^ 0xB8;
if (j == k)
{
if (i & 4)
ppc->cur_ctrl &= ~(port_sel | port_init);
else
ppc->cur_ctrl &= ~port_sel;
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
return(1);
}
}
outb(ppc->org_ctrl, ppc->lpt_addr + 2);
outb(ppc->org_data, ppc->lpt_addr);
return(0);
}
static void ppc6_deselect(Interface *ppc)
{
if (ppc->mode & 4)
ppc->cur_ctrl |= port_init;
else
ppc->cur_ctrl |= port_sel;
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
outb(ppc->org_data, ppc->lpt_addr);
outb((ppc->org_ctrl | port_sel), ppc->lpt_addr + 2);
outb(ppc->org_ctrl, ppc->lpt_addr + 2);
}
static void ppc6_send_cmd(Interface *ppc, u8 cmd)
{
switch(ppc->mode)
{
case PPCMODE_UNI_SW :
case PPCMODE_UNI_FW :
case PPCMODE_BI_SW :
case PPCMODE_BI_FW :
{
outb(cmd, ppc->lpt_addr);
ppc->cur_ctrl ^= cmd_stb;
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
break;
}
case PPCMODE_EPP_BYTE :
case PPCMODE_EPP_WORD :
case PPCMODE_EPP_DWORD :
{
outb(cmd, ppc->lpt_addr + 3);
break;
}
}
}
static void ppc6_wr_data_byte(Interface *ppc, u8 data)
{
switch(ppc->mode)
{
case PPCMODE_UNI_SW :
case PPCMODE_UNI_FW :
case PPCMODE_BI_SW :
case PPCMODE_BI_FW :
{
outb(data, ppc->lpt_addr);
ppc->cur_ctrl ^= data_stb;
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
break;
}
case PPCMODE_EPP_BYTE :
case PPCMODE_EPP_WORD :
case PPCMODE_EPP_DWORD :
{
outb(data, ppc->lpt_addr + 4);
break;
}
}
}
static u8 ppc6_rd_data_byte(Interface *ppc)
{
u8 data = 0;
switch(ppc->mode)
{
case PPCMODE_UNI_SW :
case PPCMODE_UNI_FW :
{
ppc->cur_ctrl = (ppc->cur_ctrl & ~port_stb) ^ data_stb;
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
data = inb(ppc->lpt_addr + 1);
data = ((data & 0x80) >> 1) | ((data & 0x38) >> 3);
ppc->cur_ctrl |= port_stb;
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
data |= inb(ppc->lpt_addr + 1) & 0xB8;
break;
}
case PPCMODE_BI_SW :
case PPCMODE_BI_FW :
{
ppc->cur_ctrl |= port_dir;
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
ppc->cur_ctrl = (ppc->cur_ctrl | port_stb) ^ data_stb;
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
data = inb(ppc->lpt_addr);
ppc->cur_ctrl &= ~port_stb;
outb(ppc->cur_ctrl,ppc->lpt_addr + 2);
ppc->cur_ctrl &= ~port_dir;
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
break;
}
case PPCMODE_EPP_BYTE :
case PPCMODE_EPP_WORD :
case PPCMODE_EPP_DWORD :
{
outb((ppc->cur_ctrl | port_dir),ppc->lpt_addr + 2);
data = inb(ppc->lpt_addr + 4);
outb(ppc->cur_ctrl,ppc->lpt_addr + 2);
break;
}
}
return(data);
}
static u8 ppc6_rd_port(Interface *ppc, u8 port)
{
ppc6_send_cmd(ppc,(u8)(port | ACCESS_PORT | ACCESS_READ));
return(ppc6_rd_data_byte(ppc));
}
static void ppc6_wr_port(Interface *ppc, u8 port, u8 data)
{
ppc6_send_cmd(ppc,(u8)(port | ACCESS_PORT | ACCESS_WRITE));
ppc6_wr_data_byte(ppc, data);
}
static void ppc6_rd_data_blk(Interface *ppc, u8 *data, long count)
{
switch(ppc->mode)
{
case PPCMODE_UNI_SW :
case PPCMODE_UNI_FW :
{
while(count)
{
u8 d;
ppc->cur_ctrl = (ppc->cur_ctrl & ~port_stb) ^ data_stb;
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
d = inb(ppc->lpt_addr + 1);
d = ((d & 0x80) >> 1) | ((d & 0x38) >> 3);
ppc->cur_ctrl |= port_stb;
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
d |= inb(ppc->lpt_addr + 1) & 0xB8;
*data++ = d;
count--;
}
break;
}
case PPCMODE_BI_SW :
case PPCMODE_BI_FW :
{
ppc->cur_ctrl |= port_dir;
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
ppc->cur_ctrl |= port_stb;
while(count)
{
ppc->cur_ctrl ^= data_stb;
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
*data++ = inb(ppc->lpt_addr);
count--;
}
ppc->cur_ctrl &= ~port_stb;
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
ppc->cur_ctrl &= ~port_dir;
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
break;
}
case PPCMODE_EPP_BYTE :
{
outb((ppc->cur_ctrl | port_dir), ppc->lpt_addr + 2);
while(count)
{
*data++ = inb(ppc->lpt_addr + 4);
count--;
}
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
break;
}
case PPCMODE_EPP_WORD :
{
outb((ppc->cur_ctrl | port_dir), ppc->lpt_addr + 2);
while(count > 1)
{
*((u16 *)data) = inw(ppc->lpt_addr + 4);
data += 2;
count -= 2;
}
while(count)
{
*data++ = inb(ppc->lpt_addr + 4);
count--;
}
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
break;
}
case PPCMODE_EPP_DWORD :
{
outb((ppc->cur_ctrl | port_dir),ppc->lpt_addr + 2);
while(count > 3)
{
*((u32 *)data) = inl(ppc->lpt_addr + 4);
data += 4;
count -= 4;
}
while(count)
{
*data++ = inb(ppc->lpt_addr + 4);
count--;
}
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
break;
}
}
}
static void ppc6_wait_for_fifo(Interface *ppc)
{
int i;
if (ppc->ppc_flags & fifo_wait)
{
for(i=0; i<20; i++)
inb(ppc->lpt_addr + 1);
}
}
static void ppc6_wr_data_blk(Interface *ppc, u8 *data, long count)
{
switch(ppc->mode)
{
case PPCMODE_UNI_SW :
case PPCMODE_BI_SW :
{
while(count--)
{
outb(*data++, ppc->lpt_addr);
ppc->cur_ctrl ^= data_stb;
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
}
break;
}
case PPCMODE_UNI_FW :
case PPCMODE_BI_FW :
{
u8 this, last;
ppc6_send_cmd(ppc,(CMD_PREFIX_SET | PREFIX_FASTWR));
ppc->cur_ctrl |= port_stb;
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
last = *data;
outb(last, ppc->lpt_addr);
while(count)
{
this = *data++;
count--;
if (this == last)
{
ppc->cur_ctrl ^= data_stb;
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
}
else
{
outb(this, ppc->lpt_addr);
last = this;
}
}
ppc->cur_ctrl &= ~port_stb;
outb(ppc->cur_ctrl, ppc->lpt_addr + 2);
ppc6_send_cmd(ppc,(CMD_PREFIX_RESET | PREFIX_FASTWR));
break;
}
case PPCMODE_EPP_BYTE :
{
while(count)
{
outb(*data++,ppc->lpt_addr + 4);
count--;
}
ppc6_wait_for_fifo(ppc);
break;
}
case PPCMODE_EPP_WORD :
{
while(count > 1)
{
outw(*((u16 *)data),ppc->lpt_addr + 4);
data += 2;
count -= 2;
}
while(count)
{
outb(*data++,ppc->lpt_addr + 4);
count--;
}
ppc6_wait_for_fifo(ppc);
break;
}
case PPCMODE_EPP_DWORD :
{
while(count > 3)
{
outl(*((u32 *)data),ppc->lpt_addr + 4);
data += 4;
count -= 4;
}
while(count)
{
outb(*data++,ppc->lpt_addr + 4);
count--;
}
ppc6_wait_for_fifo(ppc);
break;
}
}
}
static void ppc6_rd_port16_blk(Interface *ppc, u8 port, u8 *data, long length)
{
length = length << 1;
ppc6_send_cmd(ppc, (REG_BLKSIZE | ACCESS_REG | ACCESS_WRITE));
ppc6_wr_data_byte(ppc,(u8)length);
ppc6_wr_data_byte(ppc,(u8)(length >> 8));
ppc6_wr_data_byte(ppc,0);
ppc6_send_cmd(ppc, (CMD_PREFIX_SET | PREFIX_IO16 | PREFIX_BLK));
ppc6_send_cmd(ppc, (u8)(port | ACCESS_PORT | ACCESS_READ));
ppc6_rd_data_blk(ppc, data, length);
ppc6_send_cmd(ppc, (CMD_PREFIX_RESET | PREFIX_IO16 | PREFIX_BLK));
}
static void ppc6_wr_port16_blk(Interface *ppc, u8 port, u8 *data, long length)
{
length = length << 1;
ppc6_send_cmd(ppc, (REG_BLKSIZE | ACCESS_REG | ACCESS_WRITE));
ppc6_wr_data_byte(ppc,(u8)length);
ppc6_wr_data_byte(ppc,(u8)(length >> 8));
ppc6_wr_data_byte(ppc,0);
ppc6_send_cmd(ppc, (CMD_PREFIX_SET | PREFIX_IO16 | PREFIX_BLK));
ppc6_send_cmd(ppc, (u8)(port | ACCESS_PORT | ACCESS_WRITE));
ppc6_wr_data_blk(ppc, data, length);
ppc6_send_cmd(ppc, (CMD_PREFIX_RESET | PREFIX_IO16 | PREFIX_BLK));
}
static void ppc6_wr_extout(Interface *ppc, u8 regdata)
{
ppc6_send_cmd(ppc,(REG_VERSION | ACCESS_REG | ACCESS_WRITE));
ppc6_wr_data_byte(ppc, (u8)((regdata & 0x03) << 6));
}
static int ppc6_open(Interface *ppc)
{
int ret;
ret = ppc6_select(ppc);
if (ret == 0)
return(ret);
ppc->ppc_flags &= ~fifo_wait;
ppc6_send_cmd(ppc, (ACCESS_REG | ACCESS_WRITE | REG_RAMSIZE));
ppc6_wr_data_byte(ppc, RAMSIZE_128K);
ppc6_send_cmd(ppc, (ACCESS_REG | ACCESS_READ | REG_VERSION));
if ((ppc6_rd_data_byte(ppc) & 0x3F) == 0x0C)
ppc->ppc_flags |= fifo_wait;
return(ret);
}
static void ppc6_close(Interface *ppc)
{
ppc6_deselect(ppc);
}
