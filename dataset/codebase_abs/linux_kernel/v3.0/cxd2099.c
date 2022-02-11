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
V_20 = F_1 ( V_19 -> V_21 , V_19 -> V_3 , 0 , V_3 ) ;
if ( ! V_20 ) {
V_19 -> V_22 = V_3 ;
V_20 = F_6 ( V_19 -> V_21 , V_19 -> V_3 , 1 , V_5 , V_17 ) ;
}
return V_20 ;
}
static int F_8 ( struct V_18 * V_19 , T_1 V_4 , T_1 * V_14 )
{
return F_7 ( V_19 , V_4 , V_14 , 1 ) ;
}
static int F_9 ( struct V_18 * V_19 , T_2 V_23 , T_1 * V_5 , T_1 V_17 )
{
int V_20 ;
T_1 V_9 [ 3 ] = { 2 , V_23 & 0xff , V_23 >> 8 } ;
V_20 = F_4 ( V_19 -> V_21 , V_19 -> V_3 , V_9 , 3 ) ;
if ( ! V_20 )
V_20 = F_6 ( V_19 -> V_21 , V_19 -> V_3 , 3 , V_5 , V_17 ) ;
return V_20 ;
}
static int F_10 ( struct V_18 * V_19 , T_2 V_23 , T_1 * V_5 , T_1 V_17 )
{
int V_20 ;
T_1 V_9 [ 3 ] = { 2 , V_23 & 0xff , V_23 >> 8 } ;
V_20 = F_4 ( V_19 -> V_21 , V_19 -> V_3 , V_9 , 3 ) ;
if ( ! V_20 ) {
T_1 V_11 [ 256 ] = { 3 } ;
memcpy ( V_11 + 1 , V_5 , V_17 ) ;
V_20 = F_4 ( V_19 -> V_21 , V_19 -> V_3 , V_11 , V_17 + 1 ) ;
}
return V_20 ;
}
static int F_11 ( struct V_18 * V_19 , T_2 V_23 , T_1 * V_14 )
{
int V_20 ;
T_1 V_9 [ 3 ] = { 2 , V_23 & 0xff , V_23 >> 8 } ;
V_20 = F_4 ( V_19 -> V_21 , V_19 -> V_3 , V_9 , 3 ) ;
if ( ! V_20 )
V_20 = F_6 ( V_19 -> V_21 , V_19 -> V_3 , 3 , V_14 , 1 ) ;
return V_20 ;
}
static int F_12 ( struct V_18 * V_19 , T_2 V_23 , T_1 V_14 )
{
int V_20 ;
T_1 V_9 [ 3 ] = { 2 , V_23 & 0xff , V_23 >> 8 } ;
T_1 V_11 [ 2 ] = { 3 , V_14 } ;
V_20 = F_4 ( V_19 -> V_21 , V_19 -> V_3 , V_9 , 3 ) ;
if ( ! V_20 )
V_20 = F_4 ( V_19 -> V_21 , V_19 -> V_3 , V_11 , 2 ) ;
return V_20 ;
}
static int F_13 ( struct V_18 * V_19 , T_1 V_4 , T_1 V_14 , T_1 V_24 )
{
int V_20 ;
V_20 = F_1 ( V_19 -> V_21 , V_19 -> V_3 , 0 , V_4 ) ;
if ( ! V_20 && V_4 >= 6 && V_4 <= 8 && V_24 != 0xff )
V_20 = F_5 ( V_19 -> V_21 , V_19 -> V_3 , 1 , & V_19 -> V_25 [ V_4 ] ) ;
V_19 -> V_25 [ V_4 ] = ( V_19 -> V_25 [ V_4 ] & ( ~ V_24 ) ) | V_14 ;
if ( ! V_20 ) {
V_19 -> V_22 = V_4 ;
V_20 = F_1 ( V_19 -> V_21 , V_19 -> V_3 , 1 , V_19 -> V_25 [ V_4 ] ) ;
}
if ( V_4 == 0x20 )
V_19 -> V_25 [ V_4 ] &= 0x7f ;
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
V_20 = F_1 ( V_19 -> V_21 , V_19 -> V_3 , 0 , V_3 ) ;
if ( ! V_20 ) {
V_19 -> V_22 = V_3 ;
memcpy ( V_11 + 1 , V_5 , V_17 ) ;
V_20 = F_4 ( V_19 -> V_21 , V_19 -> V_3 , V_11 , V_17 + 1 ) ;
}
return V_20 ;
}
static void F_16 ( struct V_18 * V_19 , int V_26 )
{
if ( V_26 == V_19 -> V_26 )
return;
switch ( V_26 ) {
case 0x00 :
F_13 ( V_19 , 0x06 , 0x00 , 0x07 ) ;
break;
case 0x01 :
F_13 ( V_19 , 0x06 , 0x02 , 0x07 ) ;
break;
default:
break;
}
V_19 -> V_26 = V_26 ;
}
static void F_17 ( struct V_18 * V_19 , int V_26 )
{
if ( V_26 == V_19 -> V_27 )
return;
switch ( V_26 ) {
case 0x00 :
F_13 ( V_19 , 0x20 , 0x80 , 0x80 ) ;
break;
case 0x01 :
F_3 ( V_28 L_5 ) ;
F_13 ( V_19 , 0x08 , 0x40 , 0x40 ) ;
F_13 ( V_19 , 0x08 , 0x80 , 0x80 ) ;
break;
default:
break;
}
V_19 -> V_27 = V_26 ;
}
static int F_18 ( struct V_18 * V_19 )
{
int V_20 ;
F_19 ( & V_19 -> V_29 ) ;
V_19 -> V_26 = - 1 ;
do {
F_20 ( F_14 ( V_19 , 0x00 , 0x00 ) ) ;
F_20 ( F_14 ( V_19 , 0x01 , 0x00 ) ) ;
F_20 ( F_14 ( V_19 , 0x02 , 0x10 ) ) ;
F_20 ( F_14 ( V_19 , 0x03 , 0x00 ) ) ;
F_20 ( F_14 ( V_19 , 0x05 , 0xFF ) ) ;
F_20 ( F_14 ( V_19 , 0x06 , 0x1F ) ) ;
F_20 ( F_14 ( V_19 , 0x07 , 0x1F ) ) ;
F_20 ( F_14 ( V_19 , 0x08 , 0x28 ) ) ;
F_20 ( F_14 ( V_19 , 0x14 , 0x20 ) ) ;
F_20 ( F_14 ( V_19 , 0x09 , 0x4D ) ) ;
F_20 ( F_14 ( V_19 , 0x0A , 0xA7 ) ) ;
F_20 ( F_14 ( V_19 , 0x0B , 0x33 ) ) ;
F_20 ( F_14 ( V_19 , 0x0C , 0x33 ) ) ;
F_20 ( F_13 ( V_19 , 0x14 , 0x00 , 0x0F ) ) ;
F_20 ( F_14 ( V_19 , 0x15 , V_19 -> V_30 ) ) ;
F_20 ( F_13 ( V_19 , 0x16 , 0x00 , 0x0F ) ) ;
F_20 ( F_14 ( V_19 , 0x17 , V_19 -> V_31 ) ) ;
F_20 ( F_14 ( V_19 , 0x20 , 0x28 ) ) ;
F_20 ( F_14 ( V_19 , 0x21 , 0x00 ) ) ;
F_20 ( F_14 ( V_19 , 0x22 , 0x07 ) ) ;
F_20 ( F_13 ( V_19 , 0x20 , 0x80 , 0x80 ) ) ;
F_20 ( F_13 ( V_19 , 0x03 , 0x02 , 02 ) ) ;
F_20 ( F_14 ( V_19 , 0x01 , 0x04 ) ) ;
F_20 ( F_14 ( V_19 , 0x00 , 0x31 ) ) ;
F_20 ( F_13 ( V_19 , 0x09 , 0x08 , 0x08 ) ) ;
V_19 -> V_27 = - 1 ;
#ifdef F_21
F_17 ( V_19 , 0 ) ;
#endif
} while ( 0 );
F_22 ( & V_19 -> V_29 ) ;
return 0 ;
}
static int F_23 ( struct V_32 * V_33 ,
int V_34 , int V_23 )
{
struct V_18 * V_19 = V_33 -> V_5 ;
T_1 V_14 ;
F_19 ( & V_19 -> V_29 ) ;
F_16 ( V_19 , 1 ) ;
F_9 ( V_19 , V_23 , & V_14 , 1 ) ;
F_22 ( & V_19 -> V_29 ) ;
return V_14 ;
}
static int F_24 ( struct V_32 * V_33 , int V_34 ,
int V_23 , T_1 V_35 )
{
struct V_18 * V_19 = V_33 -> V_5 ;
F_19 ( & V_19 -> V_29 ) ;
F_16 ( V_19 , 1 ) ;
F_10 ( V_19 , V_23 , & V_35 , 1 ) ;
F_22 ( & V_19 -> V_29 ) ;
return 0 ;
}
static int F_25 ( struct V_32 * V_33 ,
int V_34 , T_1 V_23 )
{
struct V_18 * V_19 = V_33 -> V_5 ;
T_1 V_14 ;
F_19 ( & V_19 -> V_29 ) ;
F_16 ( V_19 , 0 ) ;
F_11 ( V_19 , V_23 , & V_14 ) ;
F_22 ( & V_19 -> V_29 ) ;
return V_14 ;
}
static int F_26 ( struct V_32 * V_33 , int V_34 ,
T_1 V_23 , T_1 V_35 )
{
struct V_18 * V_19 = V_33 -> V_5 ;
F_19 ( & V_19 -> V_29 ) ;
F_16 ( V_19 , 0 ) ;
F_12 ( V_19 , V_23 , V_35 ) ;
F_22 ( & V_19 -> V_29 ) ;
return 0 ;
}
static int F_27 ( struct V_32 * V_33 , int V_34 )
{
struct V_18 * V_19 = V_33 -> V_5 ;
F_19 ( & V_19 -> V_29 ) ;
F_17 ( V_19 , 0 ) ;
F_14 ( V_19 , 0x00 , 0x21 ) ;
F_14 ( V_19 , 0x06 , 0x1F ) ;
F_14 ( V_19 , 0x00 , 0x31 ) ;
F_13 ( V_19 , 0x20 , 0x80 , 0x80 ) ;
F_14 ( V_19 , 0x03 , 0x02 ) ;
V_19 -> V_36 = 0 ;
V_19 -> V_26 = - 1 ;
{
int V_37 ;
for ( V_37 = 0 ; V_37 < 100 ; V_37 ++ ) {
F_28 ( 10 ) ;
if ( V_19 -> V_36 )
break;
}
}
F_22 ( & V_19 -> V_29 ) ;
return 0 ;
}
static int F_29 ( struct V_32 * V_33 , int V_34 )
{
struct V_18 * V_19 = V_33 -> V_5 ;
F_3 ( V_28 L_6 ) ;
F_19 ( & V_19 -> V_29 ) ;
F_13 ( V_19 , 0x20 , 0x80 , 0x80 ) ;
F_13 ( V_19 , 0x06 , 0x07 , 0x07 ) ;
V_19 -> V_26 = - 1 ;
F_22 ( & V_19 -> V_29 ) ;
return 0 ;
}
static int F_30 ( struct V_32 * V_33 , int V_34 )
{
struct V_18 * V_19 = V_33 -> V_5 ;
F_19 ( & V_19 -> V_29 ) ;
F_13 ( V_19 , 0x09 , 0x00 , 0x08 ) ;
F_16 ( V_19 , 0 ) ;
#ifdef F_21
F_17 ( V_19 , 1 ) ;
#endif
F_22 ( & V_19 -> V_29 ) ;
return 0 ;
}
static int F_31 ( struct V_18 * V_19 )
{
T_1 V_38 ;
F_8 ( V_19 , 0x04 , & V_38 ) ;
if ( ! V_38 )
return 0 ;
F_14 ( V_19 , 0x05 , V_38 ) ;
if ( V_38 & 0x40 ) {
V_19 -> V_39 = 1 ;
F_3 ( V_28 L_7 ) ;
}
if ( V_38 & 0x20 )
F_3 ( V_28 L_8 ) ;
if ( V_38 & 2 ) {
T_1 V_40 ;
F_8 ( V_19 , 0x01 , & V_40 ) ;
if ( ! ( 2 & V_40 ) ) {
if ( ! V_19 -> V_41 ) {
V_19 -> V_41 |= V_42 ;
F_13 ( V_19 , 0x03 , 0x08 , 0x08 ) ;
}
} else {
if ( V_19 -> V_41 ) {
V_19 -> V_41 = 0 ;
F_13 ( V_19 , 0x03 , 0x00 , 0x08 ) ;
F_3 ( V_28 L_9 ) ;
V_19 -> V_36 = 0 ;
}
}
if ( V_38 & 8 && V_19 -> V_41 == V_42 ) {
V_19 -> V_36 = 1 ;
V_19 -> V_41 |= V_43 ;
F_3 ( V_28 L_10 ) ;
}
}
return 0 ;
}
static int F_32 ( struct V_32 * V_33 , int V_34 , int V_44 )
{
struct V_18 * V_19 = V_33 -> V_5 ;
T_1 V_40 ;
F_19 ( & V_19 -> V_29 ) ;
F_31 ( V_19 ) ;
F_8 ( V_19 , 0x01 , & V_40 ) ;
F_22 ( & V_19 -> V_29 ) ;
return V_19 -> V_41 ;
}
static int F_33 ( struct V_32 * V_33 , int V_34 , T_1 * V_45 , int V_46 )
{
struct V_18 * V_19 = V_33 -> V_5 ;
T_1 V_47 , V_48 ;
T_2 V_12 ;
F_19 ( & V_19 -> V_29 ) ;
F_31 ( V_19 ) ;
F_22 ( & V_19 -> V_29 ) ;
F_3 ( V_28 L_11 ) ;
if ( ! V_19 -> V_39 )
return 0 ;
F_19 ( & V_19 -> V_29 ) ;
F_8 ( V_19 , 0x0f , & V_47 ) ;
F_8 ( V_19 , 0x10 , & V_48 ) ;
V_12 = ( V_47 << 8 ) | V_48 ;
F_7 ( V_19 , 0x12 , V_45 , V_12 ) ;
V_19 -> V_39 = 0 ;
F_22 ( & V_19 -> V_29 ) ;
return V_12 ;
}
static int F_34 ( struct V_32 * V_33 , int V_34 , T_1 * V_45 , int V_46 )
{
struct V_18 * V_19 = V_33 -> V_5 ;
F_19 ( & V_19 -> V_29 ) ;
F_3 ( V_28 L_12 , V_46 ) ;
F_14 ( V_19 , 0x0d , V_46 >> 8 ) ;
F_14 ( V_19 , 0x0e , V_46 & 0xff ) ;
F_15 ( V_19 , 0x11 , V_45 , V_46 ) ;
F_22 ( & V_19 -> V_29 ) ;
return V_46 ;
}
struct V_32 * F_35 ( T_1 V_3 , void * V_49 ,
struct V_1 * V_21 )
{
struct V_18 * V_19 = 0 ;
T_3 V_50 = 62000000 ;
T_1 V_14 ;
if ( F_5 ( V_21 , V_3 , 0 , & V_14 ) < 0 ) {
F_3 ( V_13 L_13 , V_3 ) ;
return 0 ;
}
V_19 = F_36 ( sizeof( struct V_18 ) , V_51 ) ;
if ( ! V_19 )
return 0 ;
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
F_37 ( & V_19 -> V_29 ) ;
V_19 -> V_21 = V_21 ;
V_19 -> V_3 = V_3 ;
V_19 -> V_22 = 0xff ;
V_19 -> V_30 = 0x4a ;
V_19 -> V_31 = 0x1b ;
V_19 -> V_50 = V_50 ;
memcpy ( & V_19 -> V_52 , & V_53 , sizeof( V_53 ) ) ;
V_19 -> V_52 . V_5 = V_19 ;
F_18 ( V_19 ) ;
F_3 ( V_28 L_14 , V_19 -> V_3 ) ;
return & V_19 -> V_52 ;
}
