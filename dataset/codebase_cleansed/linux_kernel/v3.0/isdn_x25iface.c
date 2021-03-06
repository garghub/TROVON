static void illegal_state_warn( unsigned state, unsigned char firstbyte)
{
printk( KERN_WARNING "isdn_x25iface: firstbyte %x illegal in"
"current state %d\n",firstbyte, state );
}
static int pdata_is_bad( ix25_pdata_t * pda ){
if( pda && pda -> magic == ISDN_X25IFACE_MAGIC ) return 0;
printk( KERN_WARNING
"isdn_x25iface_xxx: illegal pointer to proto data\n" );
return 1;
}
struct concap_proto * isdn_x25iface_proto_new(void)
{
ix25_pdata_t * tmp = kmalloc(sizeof(ix25_pdata_t),GFP_KERNEL);
IX25DEBUG("isdn_x25iface_proto_new\n");
if( tmp ){
tmp -> magic = ISDN_X25IFACE_MAGIC;
tmp -> state = WAN_UNCONFIGURED;
spin_lock_init(&tmp->priv.lock);
tmp -> priv.dops = NULL;
tmp -> priv.net_dev = NULL;
tmp -> priv.pops = &ix25_pops;
tmp -> priv.flags = 0;
tmp -> priv.proto_data = tmp;
return( &(tmp -> priv) );
}
return NULL;
}
static int isdn_x25iface_proto_close(struct concap_proto *cprot){
ix25_pdata_t *tmp;
int ret = 0;
ulong flags;
if( ! cprot ){
printk( KERN_ERR "isdn_x25iface_proto_close: "
"invalid concap_proto pointer\n" );
return -1;
}
IX25DEBUG( "isdn_x25iface_proto_close %s \n", MY_DEVNAME(cprot -> net_dev) );
spin_lock_irqsave(&cprot->lock, flags);
cprot -> dops = NULL;
cprot -> net_dev = NULL;
tmp = cprot -> proto_data;
if( pdata_is_bad( tmp ) ){
ret = -1;
} else {
tmp -> state = WAN_UNCONFIGURED;
}
spin_unlock_irqrestore(&cprot->lock, flags);
return ret;
}
static void isdn_x25iface_proto_del(struct concap_proto *cprot){
ix25_pdata_t * tmp;
IX25DEBUG( "isdn_x25iface_proto_del \n" );
if( ! cprot ){
printk( KERN_ERR "isdn_x25iface_proto_del: "
"concap_proto pointer is NULL\n" );
return;
}
tmp = cprot -> proto_data;
if( tmp == NULL ){
printk( KERN_ERR "isdn_x25iface_proto_del: inconsistent "
"proto_data pointer (maybe already deleted?)\n");
return;
}
if( cprot -> dops ) isdn_x25iface_proto_close(cprot);
tmp -> magic = 0;
cprot -> proto_data = NULL;
kfree( tmp );
return;
}
static int isdn_x25iface_proto_restart(struct concap_proto *cprot,
struct net_device *ndev,
struct concap_device_ops *dops)
{
ix25_pdata_t * pda = cprot -> proto_data ;
ulong flags;
IX25DEBUG( "isdn_x25iface_proto_restart %s \n", MY_DEVNAME(ndev) );
if ( pdata_is_bad( pda ) ) return -1;
if( !( dops && dops -> data_req && dops -> connect_req
&& dops -> disconn_req ) ){
printk( KERN_WARNING "isdn_x25iface_restart: required dops"
" missing\n" );
isdn_x25iface_proto_close(cprot);
return -1;
}
spin_lock_irqsave(&cprot->lock, flags);
cprot -> net_dev = ndev;
cprot -> pops = &ix25_pops;
cprot -> dops = dops;
pda -> state = WAN_DISCONNECTED;
spin_unlock_irqrestore(&cprot->lock, flags);
return 0;
}
static int isdn_x25iface_receive(struct concap_proto *cprot, struct sk_buff *skb)
{
IX25DEBUG( "isdn_x25iface_receive %s \n", MY_DEVNAME(cprot->net_dev) );
if ( ( (ix25_pdata_t*) (cprot->proto_data) )
-> state == WAN_CONNECTED ){
if( skb_push(skb, 1)){
skb->data[0] = X25_IFACE_DATA;
skb->protocol = x25_type_trans(skb, cprot->net_dev);
netif_rx(skb);
return 0;
}
}
printk(KERN_WARNING "isdn_x25iface_receive %s: not connected, skb dropped\n", MY_DEVNAME(cprot->net_dev) );
dev_kfree_skb(skb);
return -1;
}
static int isdn_x25iface_connect_ind(struct concap_proto *cprot)
{
struct sk_buff * skb;
enum wan_states *state_p
= &( ( (ix25_pdata_t*) (cprot->proto_data) ) -> state);
IX25DEBUG( "isdn_x25iface_connect_ind %s \n"
, MY_DEVNAME(cprot->net_dev) );
if( *state_p == WAN_UNCONFIGURED ){
printk(KERN_WARNING
"isdn_x25iface_connect_ind while unconfigured %s\n"
, MY_DEVNAME(cprot->net_dev) );
return -1;
}
*state_p = WAN_CONNECTED;
skb = dev_alloc_skb(1);
if( skb ){
*(skb_put(skb, 1)) = X25_IFACE_CONNECT;
skb->protocol = x25_type_trans(skb, cprot->net_dev);
netif_rx(skb);
return 0;
} else {
printk(KERN_WARNING "isdn_x25iface_connect_ind: "
" out of memory -- disconnecting\n");
cprot -> dops -> disconn_req(cprot);
return -1;
}
}
static int isdn_x25iface_disconn_ind(struct concap_proto *cprot)
{
struct sk_buff *skb;
enum wan_states *state_p
= &( ( (ix25_pdata_t*) (cprot->proto_data) ) -> state);
IX25DEBUG( "isdn_x25iface_disconn_ind %s \n", MY_DEVNAME(cprot -> net_dev) );
if( *state_p == WAN_UNCONFIGURED ){
printk(KERN_WARNING
"isdn_x25iface_disconn_ind while unconfigured\n");
return -1;
}
if(! cprot -> net_dev) return -1;
*state_p = WAN_DISCONNECTED;
skb = dev_alloc_skb(1);
if( skb ){
*(skb_put(skb, 1)) = X25_IFACE_DISCONNECT;
skb->protocol = x25_type_trans(skb, cprot->net_dev);
netif_rx(skb);
return 0;
} else {
printk(KERN_WARNING "isdn_x25iface_disconn_ind:"
" out of memory\n");
return -1;
}
}
static int isdn_x25iface_xmit(struct concap_proto *cprot, struct sk_buff *skb)
{
unsigned char firstbyte = skb->data[0];
enum wan_states *state = &((ix25_pdata_t*)cprot->proto_data)->state;
int ret = 0;
IX25DEBUG("isdn_x25iface_xmit: %s first=%x state=%d\n",
MY_DEVNAME(cprot->net_dev), firstbyte, *state);
switch ( firstbyte ){
case X25_IFACE_DATA:
if( *state == WAN_CONNECTED ){
skb_pull(skb, 1);
cprot -> net_dev -> trans_start = jiffies;
ret = ( cprot -> dops -> data_req(cprot, skb) );
if( ret ) skb_push(skb,1);
return ret;
}
illegal_state_warn( *state, firstbyte );
break;
case X25_IFACE_CONNECT:
if( *state == WAN_DISCONNECTED ){
*state = WAN_CONNECTING;
ret = cprot -> dops -> connect_req(cprot);
if(ret){
isdn_x25iface_disconn_ind(cprot);
}
} else {
illegal_state_warn( *state, firstbyte );
}
break;
case X25_IFACE_DISCONNECT:
switch ( *state ){
case WAN_DISCONNECTED:
printk(KERN_WARNING "isdn_x25iface_xmit: disconnect "
" requested while disconnected\n" );
isdn_x25iface_disconn_ind(cprot);
break;
case WAN_CONNECTING:
case WAN_CONNECTED:
*state = WAN_DISCONNECTED;
cprot -> dops -> disconn_req(cprot);
break;
default:
illegal_state_warn( *state, firstbyte );
}
break;
case X25_IFACE_PARAMS:
printk(KERN_WARNING "isdn_x25iface_xmit: setting of lapb"
" options not yet supported\n");
break;
default:
printk(KERN_WARNING "isdn_x25iface_xmit: frame with illegal"
" first byte %x ignored:\n", firstbyte);
}
dev_kfree_skb(skb);
return 0;
}
