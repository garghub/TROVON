static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 )
{
T_1 V_6 [ 2 ] = { V_4 , V_5 } ;
struct V_7 V_8 = { . V_9 = V_3 , . V_10 = 0 , . V_11 = V_6 , . V_12 = 2 } ;
if ( F_2 ( V_2 , & V_8 , 1 ) != 1 ) {
F_3 ( V_13 L_1 ,
V_4 , V_3 ) ;
return - 1 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_5 , T_1 V_12 )
{
struct V_7 V_8 = { . V_9 = V_3 , . V_10 = 0 , . V_11 = V_5 , . V_12 = V_12 } ;
if ( F_2 ( V_2 , & V_8 , 1 ) != 1 ) {
F_3 ( V_13 L_2 ) ;
return - 1 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 * V_14 )
{
struct V_7 V_15 [ 2 ] = { { . V_9 = V_3 , . V_10 = 0 ,
. V_11 = & V_4 , . V_12 = 1 } ,
{ . V_9 = V_3 , . V_10 = V_16 ,
. V_11 = V_14 , . V_12 = 1 } } ;
if ( F_2 ( V_2 , V_15 , 2 ) != 2 ) {
F_3 ( V_13 L_3 ) ;
return - 1 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 * V_5 , T_1 V_17 )
{
struct V_7 V_15 [ 2 ] = { { . V_9 = V_3 , . V_10 = 0 ,
. V_11 = & V_4 , . V_12 = 1 } ,
{ . V_9 = V_3 , . V_10 = V_16 ,
. V_11 = V_5 , . V_12 = V_17 } } ;
if ( F_2 ( V_2 , V_15 , 2 ) != 2 ) {
F_3 ( V_13 L_4 ) ;
return - 1 ;
}
return 0 ;
}
static int F_7 ( struct V_18 * V_19 , T_1 V_3 , T_1 * V_5 , T_1 V_17 )
{
int V_20 ;
V_20 = F_1 ( V_19 -> V_21 , V_19 -> V_22 . V_3 , 0 , V_3 ) ;
if ( ! V_20 ) {
V_19 -> V_23 = V_3 ;
V_20 = F_6 ( V_19 -> V_21 , V_19 -> V_22 . V_3 , 1 , V_5 , V_17 ) ;
}
return V_20 ;
}
static int F_8 ( struct V_18 * V_19 , T_1 V_4 , T_1 * V_14 )
{
return F_7 ( V_19 , V_4 , V_14 , 1 ) ;
}
static int F_9 ( struct V_18 * V_19 , T_2 V_24 , T_1 * V_5 , T_1 V_17 )
{
int V_20 ;
T_1 V_9 [ 3 ] = { 2 , V_24 & 0xff , V_24 >> 8 } ;
V_20 = F_4 ( V_19 -> V_21 , V_19 -> V_22 . V_3 , V_9 , 3 ) ;
if ( ! V_20 )
V_20 = F_6 ( V_19 -> V_21 , V_19 -> V_22 . V_3 , 3 , V_5 , V_17 ) ;
return V_20 ;
}
static int F_10 ( struct V_18 * V_19 , T_2 V_24 , T_1 * V_5 , T_1 V_17 )
{
int V_20 ;
T_1 V_9 [ 3 ] = { 2 , V_24 & 0xff , V_24 >> 8 } ;
V_20 = F_4 ( V_19 -> V_21 , V_19 -> V_22 . V_3 , V_9 , 3 ) ;
if ( ! V_20 ) {
T_1 V_11 [ 256 ] = { 3 } ;
memcpy ( V_11 + 1 , V_5 , V_17 ) ;
V_20 = F_4 ( V_19 -> V_21 , V_19 -> V_22 . V_3 , V_11 , V_17 + 1 ) ;
}
return V_20 ;
}
static int F_11 ( struct V_18 * V_19 , T_2 V_24 , T_1 * V_14 )
{
int V_20 ;
T_1 V_9 [ 3 ] = { 2 , V_24 & 0xff , V_24 >> 8 } ;
V_20 = F_4 ( V_19 -> V_21 , V_19 -> V_22 . V_3 , V_9 , 3 ) ;
if ( ! V_20 )
V_20 = F_6 ( V_19 -> V_21 , V_19 -> V_22 . V_3 , 3 , V_14 , 1 ) ;
return V_20 ;
}
static int F_12 ( struct V_18 * V_19 , T_2 V_24 , T_1 V_14 )
{
int V_20 ;
T_1 V_9 [ 3 ] = { 2 , V_24 & 0xff , V_24 >> 8 } ;
T_1 V_11 [ 2 ] = { 3 , V_14 } ;
V_20 = F_4 ( V_19 -> V_21 , V_19 -> V_22 . V_3 , V_9 , 3 ) ;
if ( ! V_20 )
V_20 = F_4 ( V_19 -> V_21 , V_19 -> V_22 . V_3 , V_11 , 2 ) ;
return V_20 ;
}
static int F_13 ( struct V_18 * V_19 , T_1 V_4 , T_1 V_14 , T_1 V_25 )
{
int V_20 ;
V_20 = F_1 ( V_19 -> V_21 , V_19 -> V_22 . V_3 , 0 , V_4 ) ;
if ( ! V_20 && V_4 >= 6 && V_4 <= 8 && V_25 != 0xff )
V_20 = F_5 ( V_19 -> V_21 , V_19 -> V_22 . V_3 , 1 , & V_19 -> V_26 [ V_4 ] ) ;
V_19 -> V_26 [ V_4 ] = ( V_19 -> V_26 [ V_4 ] & ( ~ V_25 ) ) | V_14 ;
if ( ! V_20 ) {
V_19 -> V_23 = V_4 ;
V_20 = F_1 ( V_19 -> V_21 , V_19 -> V_22 . V_3 , 1 , V_19 -> V_26 [ V_4 ] ) ;
}
if ( V_4 == 0x20 )
V_19 -> V_26 [ V_4 ] &= 0x7f ;
return V_20 ;
}
static int F_14 ( struct V_18 * V_19 , T_1 V_4 , T_1 V_14 )
{
return F_13 ( V_19 , V_4 , V_14 , 0xff ) ;
}
static int F_15 ( struct V_18 * V_19 , T_1 V_3 , T_1 * V_5 , int V_17 )
{
int V_20 ;
T_1 V_11 [ 256 ] = { 1 } ;
V_20 = F_1 ( V_19 -> V_21 , V_19 -> V_22 . V_3 , 0 , V_3 ) ;
if ( ! V_20 ) {
V_19 -> V_23 = V_3 ;
memcpy ( V_11 + 1 , V_5 , V_17 ) ;
V_20 = F_4 ( V_19 -> V_21 , V_19 -> V_22 . V_3 , V_11 , V_17 + 1 ) ;
}
return V_20 ;
}
static void F_16 ( struct V_18 * V_19 , int V_27 )
{
if ( V_27 == V_19 -> V_27 )
return;
switch ( V_27 ) {
case 0x00 :
F_13 ( V_19 , 0x06 , 0x00 , 0x07 ) ;
break;
case 0x01 :
F_13 ( V_19 , 0x06 , 0x02 , 0x07 ) ;
break;
default:
break;
}
V_19 -> V_27 = V_27 ;
}
static void F_17 ( struct V_18 * V_19 , int V_27 )
{
if ( V_27 == V_19 -> V_28 )
return;
switch ( V_27 ) {
case 0x00 :
F_13 ( V_19 , 0x20 , 0x80 , 0x80 ) ;
break;
case 0x01 :
#ifdef F_18
if ( ! V_19 -> V_29 . V_30 )
return;
F_3 ( V_31 L_5 ) ;
F_13 ( V_19 , 0x08 , 0x40 , 0x40 ) ;
F_13 ( V_19 , 0x08 , 0x80 , 0x80 ) ;
#endif
break;
default:
break;
}
V_19 -> V_28 = V_27 ;
}
static int F_19 ( struct V_18 * V_19 )
{
int V_20 ;
F_20 ( & V_19 -> V_32 ) ;
V_19 -> V_27 = - 1 ;
do {
V_20 = F_14 ( V_19 , 0x00 , 0x00 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x01 , 0x00 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x02 , 0x10 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x03 , 0x00 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x05 , 0xFF ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x06 , 0x1F ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x07 , 0x1F ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x08 , 0x28 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x14 , 0x20 ) ;
if ( V_20 < 0 )
break;
#if 0
status = write_reg(ci, 0x09, 0x4D);
if (status < 0)
break;
#endif
V_20 = F_14 ( V_19 , 0x0A , 0xA7 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x0B , 0x33 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x0C , 0x33 ) ;
if ( V_20 < 0 )
break;
V_20 = F_13 ( V_19 , 0x14 , 0x00 , 0x0F ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x15 , V_19 -> V_33 ) ;
if ( V_20 < 0 )
break;
V_20 = F_13 ( V_19 , 0x16 , 0x00 , 0x0F ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x17 , V_19 -> V_34 ) ;
if ( V_20 < 0 )
break;
if ( V_19 -> V_22 . V_35 ) {
if ( V_19 -> V_22 . V_36 ) {
V_20 = F_14 ( V_19 , 0x09 , 0x6f ) ;
if ( V_20 < 0 )
break;
} else {
V_20 = F_14 ( V_19 , 0x09 , 0x6d ) ;
if ( V_20 < 0 )
break;
}
V_20 = F_14 ( V_19 , 0x20 , 0x68 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x21 , 0x00 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x22 , 0x02 ) ;
if ( V_20 < 0 )
break;
} else {
if ( V_19 -> V_22 . V_36 ) {
V_20 = F_14 ( V_19 , 0x09 , 0x4f ) ;
if ( V_20 < 0 )
break;
} else {
V_20 = F_14 ( V_19 , 0x09 , 0x4d ) ;
if ( V_20 < 0 )
break;
}
V_20 = F_14 ( V_19 , 0x20 , 0x28 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x21 , 0x00 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x22 , 0x07 ) ;
if ( V_20 < 0 )
break;
}
V_20 = F_13 ( V_19 , 0x20 , 0x80 , 0x80 ) ;
if ( V_20 < 0 )
break;
V_20 = F_13 ( V_19 , 0x03 , 0x02 , 0x02 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x01 , 0x04 ) ;
if ( V_20 < 0 )
break;
V_20 = F_14 ( V_19 , 0x00 , 0x31 ) ;
if ( V_20 < 0 )
break;
V_20 = F_13 ( V_19 , 0x09 , 0x08 , 0x08 ) ;
if ( V_20 < 0 )
break;
V_19 -> V_28 = - 1 ;
F_17 ( V_19 , 0 ) ;
} while ( 0 );
F_21 ( & V_19 -> V_32 ) ;
return 0 ;
}
static int F_22 ( struct V_37 * V_38 ,
int V_39 , int V_24 )
{
struct V_18 * V_19 = V_38 -> V_5 ;
#if 0
if (ci->amem_read) {
if (address <= 0 || address > 1024)
return -EIO;
return ci->amem[address];
}
mutex_lock(&ci->lock);
write_regm(ci, 0x06, 0x00, 0x05);
read_pccard(ci, 0, &ci->amem[0], 128);
read_pccard(ci, 128, &ci->amem[0], 128);
read_pccard(ci, 256, &ci->amem[0], 128);
read_pccard(ci, 384, &ci->amem[0], 128);
write_regm(ci, 0x06, 0x05, 0x05);
mutex_unlock(&ci->lock);
return ci->amem[address];
#else
T_1 V_14 ;
F_20 ( & V_19 -> V_32 ) ;
F_16 ( V_19 , 1 ) ;
F_9 ( V_19 , V_24 , & V_14 , 1 ) ;
F_21 ( & V_19 -> V_32 ) ;
return V_14 ;
#endif
}
static int F_23 ( struct V_37 * V_38 , int V_39 ,
int V_24 , T_1 V_40 )
{
struct V_18 * V_19 = V_38 -> V_5 ;
F_20 ( & V_19 -> V_32 ) ;
F_16 ( V_19 , 1 ) ;
F_10 ( V_19 , V_24 , & V_40 , 1 ) ;
F_21 ( & V_19 -> V_32 ) ;
return 0 ;
}
static int F_24 ( struct V_37 * V_38 ,
int V_39 , T_1 V_24 )
{
struct V_18 * V_19 = V_38 -> V_5 ;
T_1 V_14 ;
F_20 ( & V_19 -> V_32 ) ;
F_16 ( V_19 , 0 ) ;
F_11 ( V_19 , V_24 , & V_14 ) ;
F_21 ( & V_19 -> V_32 ) ;
return V_14 ;
}
static int F_25 ( struct V_37 * V_38 , int V_39 ,
T_1 V_24 , T_1 V_40 )
{
struct V_18 * V_19 = V_38 -> V_5 ;
F_20 ( & V_19 -> V_32 ) ;
F_16 ( V_19 , 0 ) ;
F_12 ( V_19 , V_24 , V_40 ) ;
F_21 ( & V_19 -> V_32 ) ;
return 0 ;
}
static int F_26 ( struct V_37 * V_38 , int V_39 )
{
struct V_18 * V_19 = V_38 -> V_5 ;
F_20 ( & V_19 -> V_32 ) ;
#if 0
write_reg(ci, 0x00, 0x21);
write_reg(ci, 0x06, 0x1F);
write_reg(ci, 0x00, 0x31);
#else
#if 0
write_reg(ci, 0x06, 0x1F);
write_reg(ci, 0x06, 0x2F);
#else
F_17 ( V_19 , 0 ) ;
F_14 ( V_19 , 0x00 , 0x21 ) ;
F_14 ( V_19 , 0x06 , 0x1F ) ;
F_14 ( V_19 , 0x00 , 0x31 ) ;
F_13 ( V_19 , 0x20 , 0x80 , 0x80 ) ;
F_14 ( V_19 , 0x03 , 0x02 ) ;
V_19 -> V_41 = 0 ;
#endif
#endif
V_19 -> V_27 = - 1 ;
{
int V_42 ;
#if 0
u8 val;
#endif
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
F_27 ( 10 ) ;
#if 0
read_reg(ci, 0x06, &val);
printk(KERN_INFO "%d:%02x\n", i, val);
if (!(val&0x10))
break;
#else
if ( V_19 -> V_41 )
break;
#endif
}
}
F_21 ( & V_19 -> V_32 ) ;
return 0 ;
}
static int F_28 ( struct V_37 * V_38 , int V_39 )
{
struct V_18 * V_19 = V_38 -> V_5 ;
F_3 ( V_31 L_6 ) ;
F_20 ( & V_19 -> V_32 ) ;
F_13 ( V_19 , 0x09 , 0x08 , 0x08 ) ;
F_13 ( V_19 , 0x20 , 0x80 , 0x80 ) ;
F_13 ( V_19 , 0x06 , 0x07 , 0x07 ) ;
V_19 -> V_27 = - 1 ;
F_21 ( & V_19 -> V_32 ) ;
return 0 ;
}
static int F_29 ( struct V_37 * V_38 , int V_39 )
{
struct V_18 * V_19 = V_38 -> V_5 ;
F_20 ( & V_19 -> V_32 ) ;
F_13 ( V_19 , 0x09 , 0x00 , 0x08 ) ;
F_16 ( V_19 , 0 ) ;
#ifdef F_18
F_17 ( V_19 , 1 ) ;
#endif
F_21 ( & V_19 -> V_32 ) ;
return 0 ;
}
static int F_30 ( struct V_18 * V_19 )
{
T_1 V_43 ;
F_8 ( V_19 , 0x04 , & V_43 ) ;
if ( ! V_43 )
return 0 ;
F_14 ( V_19 , 0x05 , V_43 ) ;
if ( V_43 & 0x40 ) {
V_19 -> V_44 = 1 ;
F_3 ( V_31 L_7 ) ;
}
if ( V_43 & 0x20 )
F_3 ( V_31 L_8 ) ;
if ( V_43 & 2 ) {
T_1 V_45 ;
F_8 ( V_19 , 0x01 , & V_45 ) ;
if ( ! ( 2 & V_45 ) ) {
if ( ! V_19 -> V_46 ) {
V_19 -> V_46 |= V_47 ;
F_13 ( V_19 , 0x03 , 0x08 , 0x08 ) ;
}
} else {
if ( V_19 -> V_46 ) {
V_19 -> V_46 = 0 ;
F_13 ( V_19 , 0x03 , 0x00 , 0x08 ) ;
F_3 ( V_31 L_9 ) ;
V_19 -> V_41 = 0 ;
}
}
if ( V_43 & 8 && V_19 -> V_46 == V_47 ) {
V_19 -> V_41 = 1 ;
V_19 -> V_46 |= V_48 ;
}
}
return 0 ;
}
static int F_31 ( struct V_37 * V_38 , int V_39 , int V_49 )
{
struct V_18 * V_19 = V_38 -> V_5 ;
T_1 V_45 ;
F_20 ( & V_19 -> V_32 ) ;
F_30 ( V_19 ) ;
F_8 ( V_19 , 0x01 , & V_45 ) ;
F_21 ( & V_19 -> V_32 ) ;
return V_19 -> V_46 ;
}
static int V_30 ( struct V_37 * V_38 , int V_39 , T_1 * V_50 , int V_51 )
{
struct V_18 * V_19 = V_38 -> V_5 ;
T_1 V_52 , V_53 ;
T_2 V_12 ;
F_20 ( & V_19 -> V_32 ) ;
F_30 ( V_19 ) ;
F_21 ( & V_19 -> V_32 ) ;
F_3 ( V_31 L_10 ) ;
if ( ! V_19 -> V_44 )
return 0 ;
F_20 ( & V_19 -> V_32 ) ;
F_8 ( V_19 , 0x0f , & V_52 ) ;
F_8 ( V_19 , 0x10 , & V_53 ) ;
V_12 = ( V_52 << 8 ) | V_53 ;
F_7 ( V_19 , 0x12 , V_50 , V_12 ) ;
V_19 -> V_44 = 0 ;
F_21 ( & V_19 -> V_32 ) ;
return V_12 ;
}
static int F_32 ( struct V_37 * V_38 , int V_39 , T_1 * V_50 , int V_51 )
{
struct V_18 * V_19 = V_38 -> V_5 ;
F_20 ( & V_19 -> V_32 ) ;
F_3 ( V_54 L_11 , V_51 ) ;
F_14 ( V_19 , 0x0d , V_51 >> 8 ) ;
F_14 ( V_19 , 0x0e , V_51 & 0xff ) ;
F_15 ( V_19 , 0x11 , V_50 , V_51 ) ;
F_21 ( & V_19 -> V_32 ) ;
return V_51 ;
}
struct V_37 * F_33 ( struct V_55 * V_22 ,
void * V_56 ,
struct V_1 * V_21 )
{
struct V_18 * V_19 ;
T_1 V_14 ;
if ( F_5 ( V_21 , V_22 -> V_3 , 0 , & V_14 ) < 0 ) {
F_3 ( V_31 L_12 , V_22 -> V_3 ) ;
return NULL ;
}
V_19 = F_34 ( sizeof( struct V_18 ) , V_57 ) ;
if ( ! V_19 )
return NULL ;
F_35 ( & V_19 -> V_32 ) ;
V_19 -> V_22 = * V_22 ;
V_19 -> V_21 = V_21 ;
V_19 -> V_23 = 0xff ;
V_19 -> V_33 = 0x4a ;
V_19 -> V_34 = 0x1b ;
V_19 -> V_29 = V_58 ;
V_19 -> V_29 . V_5 = V_19 ;
F_19 ( V_19 ) ;
F_3 ( V_31 L_13 , V_19 -> V_22 . V_3 ) ;
return & V_19 -> V_29 ;
}
