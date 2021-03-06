void eprom_cs(struct net_device *dev, short bit)
{
if(bit)
write_nic_byte_E(dev, EPROM_CMD,
(1<<EPROM_CS_SHIFT) | \
read_nic_byte_E(dev, EPROM_CMD));
else
write_nic_byte_E(dev, EPROM_CMD, read_nic_byte_E(dev, EPROM_CMD)\
&~(1<<EPROM_CS_SHIFT));
force_pci_posting(dev);
udelay(EPROM_DELAY);
}
void eprom_ck_cycle(struct net_device *dev)
{
write_nic_byte_E(dev, EPROM_CMD,
(1<<EPROM_CK_SHIFT) | read_nic_byte_E(dev,EPROM_CMD));
force_pci_posting(dev);
udelay(EPROM_DELAY);
write_nic_byte_E(dev, EPROM_CMD,
read_nic_byte_E(dev, EPROM_CMD) &~ (1<<EPROM_CK_SHIFT));
force_pci_posting(dev);
udelay(EPROM_DELAY);
}
void eprom_w(struct net_device *dev,short bit)
{
if(bit)
write_nic_byte_E(dev, EPROM_CMD, (1<<EPROM_W_SHIFT) | \
read_nic_byte_E(dev,EPROM_CMD));
else
write_nic_byte_E(dev, EPROM_CMD, read_nic_byte_E(dev,EPROM_CMD)\
&~(1<<EPROM_W_SHIFT));
force_pci_posting(dev);
udelay(EPROM_DELAY);
}
short eprom_r(struct net_device *dev)
{
short bit;
bit=(read_nic_byte_E(dev, EPROM_CMD) & (1<<EPROM_R_SHIFT) );
udelay(EPROM_DELAY);
if(bit) return 1;
return 0;
}
void eprom_send_bits_string(struct net_device *dev, short b[], int len)
{
int i;
for(i=0; i<len; i++){
eprom_w(dev, b[i]);
eprom_ck_cycle(dev);
}
}
u32 eprom_read(struct net_device *dev, u32 addr)
{
struct r8192_priv *priv = ieee80211_priv(dev);
short read_cmd[]={1,1,0};
short addr_str[8];
int i;
int addr_len;
u32 ret;
ret=0;
write_nic_byte_E(dev, EPROM_CMD,
(EPROM_CMD_PROGRAM<<EPROM_CMD_OPERATING_MODE_SHIFT));
force_pci_posting(dev);
udelay(EPROM_DELAY);
if (priv->epromtype==EPROM_93c56){
addr_str[7]=addr & 1;
addr_str[6]=addr & (1<<1);
addr_str[5]=addr & (1<<2);
addr_str[4]=addr & (1<<3);
addr_str[3]=addr & (1<<4);
addr_str[2]=addr & (1<<5);
addr_str[1]=addr & (1<<6);
addr_str[0]=addr & (1<<7);
addr_len=8;
}else{
addr_str[5]=addr & 1;
addr_str[4]=addr & (1<<1);
addr_str[3]=addr & (1<<2);
addr_str[2]=addr & (1<<3);
addr_str[1]=addr & (1<<4);
addr_str[0]=addr & (1<<5);
addr_len=6;
}
eprom_cs(dev, 1);
eprom_ck_cycle(dev);
eprom_send_bits_string(dev, read_cmd, 3);
eprom_send_bits_string(dev, addr_str, addr_len);
eprom_w(dev, 0);
for(i=0;i<16;i++){
eprom_ck_cycle(dev);
ret |= (eprom_r(dev)<<(15-i));
}
eprom_cs(dev, 0);
eprom_ck_cycle(dev);
write_nic_byte_E(dev, EPROM_CMD,
(EPROM_CMD_NORMAL<<EPROM_CMD_OPERATING_MODE_SHIFT));
return ret;
}
