static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , F_3 ( V_2 -> V_6 , V_2 -> V_7 [ V_8 ] ) ,
V_9 , 0x40 , V_3 , V_4 , NULL , 0 , 1000 ) ;
if ( V_5 < 0 ) {
F_4 ( V_10 L_1 ,
V_3 , V_4 , V_5 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , F_3 ( V_2 -> V_6 , V_2 -> V_7 [ V_8 ] ) ,
V_11 , 0x40 , V_3 , V_4 , NULL , 0 , 1000 ) ;
if ( V_5 < 0 ) {
F_4 ( V_10 L_2 ,
V_3 , V_4 , V_5 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , F_3 ( V_2 -> V_6 , V_2 -> V_7 [ V_8 ] ) ,
V_12 , 0x40 , V_3 , V_4 , NULL , 0 , 1000 ) ;
if ( V_5 < 0 ) {
F_4 ( V_10 L_3 ,
V_3 , V_4 , V_5 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_13 * V_14 ,
unsigned char * V_15 , int V_16 )
{
int V_17 , V_5 ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
V_17 = 0 ;
V_5 = F_8 ( V_2 -> V_6 , F_9 ( V_2 -> V_6 , V_2 -> V_7 [ V_18 ] ) , V_15 , V_16 , & V_17 , 100 ) ;
if ( V_5 < 0 ) {
F_4 ( V_10 L_4 , V_2 -> V_7 [ V_18 ] , V_5 ) ;
return V_5 ;
}
if ( V_17 >= sizeof( * V_14 ) )
memcpy ( V_14 , V_15 , sizeof( * V_14 ) ) ;
return V_17 ;
}
static inline void F_10 ( unsigned char * V_15 , unsigned char * V_19 , int V_20 )
{
F_4 ( V_21 L_5 , V_19 , V_15 [ V_20 ] ) ;
}
static void F_11 ( struct V_1 * V_2 , unsigned char * V_15 , int V_17 )
{
int V_22 ;
F_4 ( V_21 L_6 , V_2 -> V_7 [ V_18 ] , V_17 ) ;
for ( V_22 = 0 ; V_22 < V_17 ; ++ V_22 )
F_4 ( L_7 , V_15 [ V_22 ] ) ;
F_4 ( V_21 L_8 ) ;
if ( V_17 >= 16 ) {
F_10 ( V_15 , L_9 , 0 ) ;
F_10 ( V_15 , L_10 , 1 ) ;
F_10 ( V_15 , L_11 , 2 ) ;
F_10 ( V_15 , L_12 , 3 ) ;
F_10 ( V_15 , L_13 , 4 ) ;
F_10 ( V_15 , L_14 , 5 ) ;
F_10 ( V_15 , L_15 ,
6 ) ;
F_10 ( V_15 , L_16 , 7 ) ;
F_10 ( V_15 , L_17 , 8 ) ;
F_10 ( V_15 , L_18 , 9 ) ;
F_10 ( V_15 , L_19 , 10 ) ;
F_10 ( V_15 , L_20 , 11 ) ;
F_10 ( V_15 , L_21 , 12 ) ;
F_10 ( V_15 , L_22 , 13 ) ;
F_10 ( V_15 , L_23 , 14 ) ;
F_10 ( V_15 , L_23 , 15 ) ;
}
for ( V_22 = 16 ; V_22 < V_17 ; ++ V_22 ) {
if ( V_15 [ V_22 ] == V_23 ) {
F_10 ( V_15 , L_24 , V_22 ) ;
continue;
}
F_10 ( V_15 , L_25 , V_22 ) ;
if ( V_15 [ V_22 ] & V_24 )
F_4 ( V_21 L_26 ) ;
if ( V_15 [ V_22 ] & V_25 )
F_4 ( V_21 L_27 ) ;
if ( V_15 [ V_22 ] & V_26 )
F_4 ( V_21 L_28 ) ;
if ( V_15 [ V_22 ] & V_27 )
F_4 ( V_21 L_29 ) ;
if ( V_15 [ V_22 ] & V_28 )
F_4 ( V_21 L_30 ) ;
if ( V_15 [ V_22 ] & V_29 )
F_4 ( V_21 L_31 ) ;
if ( V_15 [ V_22 ] & V_30 )
F_4 ( V_21 L_32 ) ;
if ( V_15 [ V_22 ] & V_31 )
F_4 ( V_21 L_33 ) ;
}
}
static void F_12 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_32 , 0 ) ;
if ( F_5 ( V_2 , V_33 , V_34 ) )
F_4 ( V_10 L_34
L_35 ) ;
if ( V_2 -> V_35 ) {
T_2 V_36 = V_2 -> V_35 >> 4 ;
if ( F_6 ( V_2 , V_37 | V_38 , V_36 ) )
F_4 ( V_10 L_34
L_36 ) ;
}
}
static int F_13 ( struct V_1 * V_2 , unsigned char * V_15 , int V_16 )
{
int V_17 , V_5 ;
struct V_13 V_14 ;
V_17 = 0 ;
V_5 = F_8 ( V_2 -> V_6 , F_9 ( V_2 -> V_6 , V_2 -> V_7 [ V_39 ] ) ,
V_15 , V_16 , & V_17 , 1000 ) ;
if ( V_5 < 0 ) {
T_2 V_15 [ 0x20 ] ;
int V_17 ;
F_4 ( V_21 L_37 , V_2 -> V_7 [ V_39 ] ) ;
F_14 ( V_2 -> V_6 , F_9 ( V_2 -> V_6 , V_2 -> V_7 [ V_39 ] ) ) ;
V_17 = F_7 ( V_2 , & V_14 , V_15 , sizeof( V_15 ) ) ;
F_11 ( V_2 , V_15 , V_17 ) ;
return V_5 ;
}
#if 0
{
int i;
printk("%s: count=%d: ", __func__, count);
for (i=0; i<count; ++i)
printk("%02x ", buf[i]);
printk("\n");
}
#endif
return V_17 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned char * V_15 , int V_40 )
{
int V_17 , V_5 ;
V_17 = 0 ;
V_5 = F_8 ( V_2 -> V_6 , F_16 ( V_2 -> V_6 , V_2 -> V_7 [ V_41 ] ) , V_15 , V_40 , & V_17 , 1000 ) ;
if ( V_5 < 0 ) {
F_4 ( V_10 L_38
L_39 , V_2 -> V_7 [ V_41 ] , V_5 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
T_2 V_15 [ 0x20 ] ;
int V_5 , V_17 = 0 ;
do {
V_5 = F_7 ( V_2 , V_14 , V_15 , sizeof( V_15 ) ) ;
#if 0
if (err >= 0) {
int i;
printk("0x%x: count=%d, status: ", dev->ep[EP_STATUS], err);
for (i=0; i<err; ++i)
printk("%02x ", buf[i]);
printk("\n");
}
#endif
} while ( ! ( V_15 [ 0x08 ] & V_42 ) && ! ( V_5 < 0 ) && ++ V_17 < 100 );
if ( V_5 >= 16 && V_14 -> V_43 & V_44 ) {
F_4 ( V_21 L_40 ) ;
F_12 ( V_2 ) ;
V_17 = 101 ;
}
if ( V_5 > 16 || V_17 >= 100 || V_5 < 0 )
F_11 ( V_2 , V_15 , V_5 ) ;
if ( V_17 >= 100 || V_5 < 0 )
return - 1 ;
else
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_6 ( V_2 , V_45 | V_38 , V_46 ) ;
if ( V_5 )
return V_5 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_47 )
{
int V_5 = 0 ;
T_2 V_36 = 1 + ( T_2 ) ( V_47 >> 4 ) ;
int V_48 = V_36 << 4 ;
V_2 -> V_49 = V_47 ? V_50 : 0 ;
if ( V_47 == 0 || V_48 == V_2 -> V_35 )
return V_5 ;
V_5 = F_6 ( V_2 , V_37 | V_38 , V_36 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_35 = V_48 ;
return V_5 ;
}
static int F_20 ( struct V_1 * V_2 , T_2 V_51 , T_2 * V_52 )
{
int V_5 ;
struct V_13 V_14 ;
V_5 = F_6 ( V_2 , V_53 | V_38 | ( V_51 ? V_54 : 0 ) ,
0 ) ;
if ( V_5 )
return V_5 ;
F_17 ( V_2 , & V_14 ) ;
V_5 = F_13 ( V_2 , V_52 , sizeof( * V_52 ) ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , T_2 V_55 )
{
int V_5 ;
struct V_13 V_14 ;
T_2 V_56 ;
V_5 = F_6 ( V_2 , V_57 | V_38 | V_2 -> V_49 , V_55 ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_49 )
F_22 ( V_2 -> V_35 ) ;
V_5 = F_17 ( V_2 , & V_14 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_13 ( V_2 , & V_56 , sizeof( V_56 ) ) ;
if ( V_5 < 0 )
return V_5 ;
return ! ( V_55 == V_56 ) ;
}
static int F_23 ( struct V_1 * V_2 , T_2 * V_55 )
{
int V_5 ;
struct V_13 V_14 ;
V_5 = F_6 ( V_2 , V_57 | V_38 , 0xff ) ;
if ( V_5 )
return V_5 ;
F_17 ( V_2 , & V_14 ) ;
V_5 = F_13 ( V_2 , V_55 , sizeof( * V_55 ) ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , T_2 * V_15 , int V_40 )
{
struct V_13 V_14 ;
int V_5 ;
if ( V_40 > 64 * 1024 )
return - V_58 ;
memset ( V_15 , 0xFF , V_40 ) ;
V_5 = F_15 ( V_2 , V_15 , V_40 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_6 ( V_2 , V_59 | V_38 , V_40 ) ;
if ( V_5 )
return V_5 ;
F_17 ( V_2 , & V_14 ) ;
memset ( V_15 , 0x00 , V_40 ) ;
V_5 = F_13 ( V_2 , V_15 , V_40 ) ;
return V_5 ;
}
static int F_25 ( struct V_1 * V_2 , T_2 * V_15 , int V_40 )
{
int V_5 ;
struct V_13 V_14 ;
V_5 = F_15 ( V_2 , V_15 , V_40 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_6 ( V_2 , V_59 | V_38 | V_2 -> V_49 , V_40 ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_49 )
F_22 ( V_2 -> V_35 ) ;
F_17 ( V_2 , & V_14 ) ;
V_5 = F_13 ( V_2 , V_15 , V_40 ) ;
if ( V_5 < 0 )
return V_5 ;
return ! ( V_5 == V_40 ) ;
}
static T_2 F_26 ( void * V_60 , T_2 V_51 )
{
T_2 V_61 ;
struct V_1 * V_2 = V_60 ;
if ( F_20 ( V_2 , V_51 , & V_61 ) )
return 0 ;
return V_61 ;
}
static void F_27 ( void * V_60 , T_2 V_55 )
{
struct V_1 * V_2 = V_60 ;
F_21 ( V_2 , V_55 ) ;
}
static T_2 F_28 ( void * V_60 )
{
struct V_1 * V_2 = V_60 ;
int V_5 ;
T_2 V_55 = 0 ;
V_5 = F_23 ( V_2 , & V_55 ) ;
if ( V_5 )
return 0 ;
return V_55 ;
}
static void F_29 ( void * V_60 , const T_2 * V_15 , int V_40 )
{
struct V_1 * V_2 = V_60 ;
F_25 ( V_2 , ( T_2 * ) V_15 , V_40 ) ;
}
static T_2 F_30 ( void * V_60 , T_2 * V_15 , int V_40 )
{
struct V_1 * V_2 = V_60 ;
int V_5 ;
V_5 = F_24 ( V_2 , V_15 , V_40 ) ;
if ( V_5 < 0 )
return 0 ;
return V_40 ;
}
static T_2 F_31 ( void * V_60 )
{
struct V_1 * V_2 = V_60 ;
int V_5 ;
V_5 = F_18 ( V_2 ) ;
if ( V_5 )
return 1 ;
return 0 ;
}
static T_2 F_32 ( void * V_60 , int V_47 )
{
struct V_1 * V_2 = V_60 ;
if ( F_19 ( V_2 , V_47 ) )
return 1 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
memset ( & V_2 -> V_62 , 0 , sizeof( struct V_63 ) ) ;
F_12 ( V_2 ) ;
V_2 -> V_62 . V_60 = V_2 ;
V_2 -> V_62 . V_64 = & F_26 ;
V_2 -> V_62 . V_65 = & F_28 ;
V_2 -> V_62 . V_66 = & F_27 ;
V_2 -> V_62 . V_67 = & F_30 ;
V_2 -> V_62 . V_68 = & F_29 ;
V_2 -> V_62 . V_69 = & F_31 ;
V_2 -> V_62 . V_70 = & F_32 ;
return F_34 ( & V_2 -> V_62 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_36 ( & V_2 -> V_62 ) ;
}
static int F_37 ( struct V_71 * V_72 ,
const struct V_73 * V_74 )
{
struct V_75 * V_6 = F_38 ( V_72 ) ;
struct V_76 * V_77 ;
struct V_78 * V_79 ;
struct V_1 * V_2 ;
int V_22 , V_5 ;
V_2 = F_39 ( sizeof( struct V_1 ) , V_80 ) ;
if ( ! V_2 ) {
F_4 ( V_21 L_41 ) ;
return - V_81 ;
}
V_2 -> V_35 = 0 ;
V_2 -> V_49 = 0 ;
V_2 -> V_6 = F_40 ( V_6 ) ;
if ( ! V_2 -> V_6 ) {
V_5 = - V_81 ;
goto V_82;
}
memset ( V_2 -> V_7 , 0 , sizeof( V_2 -> V_7 ) ) ;
F_41 ( V_72 , V_2 ) ;
V_5 = F_42 ( V_2 -> V_6 , V_72 -> V_83 [ 0 ] . V_84 . V_85 , 3 ) ;
if ( V_5 ) {
F_4 ( V_10 L_42 ,
V_72 -> V_83 [ 0 ] . V_84 . V_85 , V_5 ) ;
goto V_86;
}
V_5 = F_43 ( V_2 -> V_6 ) ;
if ( V_5 ) {
F_4 ( V_10 L_43 , V_5 ) ;
goto V_86;
}
V_79 = & V_72 -> V_83 [ 0 ] ;
if ( V_79 -> V_84 . V_87 != V_88 - 1 ) {
F_4 ( V_21 L_44 , V_79 -> V_84 . V_87 ) ;
V_5 = - V_89 ;
goto V_86;
}
for ( V_22 = 0 ; V_22 < V_79 -> V_84 . V_87 ; ++ V_22 ) {
V_77 = & V_79 -> V_77 [ V_22 ] . V_84 ;
V_2 -> V_7 [ V_22 + 1 ] = V_77 -> V_90 ;
#if 0
printk("%d: addr=%x, size=%d, dir=%s, type=%x\n",
i, endpoint->bEndpointAddress, le16_to_cpu(endpoint->wMaxPacketSize),
(endpoint->bEndpointAddress & USB_DIR_IN)?"IN":"OUT",
endpoint->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK);
#endif
}
V_5 = F_33 ( V_2 ) ;
if ( V_5 )
goto V_86;
F_44 ( & V_91 ) ;
F_45 ( & V_2 -> V_92 , & V_93 ) ;
F_46 ( & V_91 ) ;
return 0 ;
V_86:
F_41 ( V_72 , NULL ) ;
F_47 ( V_2 -> V_6 ) ;
V_82:
F_48 ( V_2 ) ;
return V_5 ;
}
static void F_49 ( struct V_71 * V_72 )
{
struct V_1 * V_2 ;
V_2 = F_50 ( V_72 ) ;
if ( ! V_2 )
return;
F_44 ( & V_91 ) ;
F_51 ( & V_2 -> V_92 ) ;
F_46 ( & V_91 ) ;
F_35 ( V_2 ) ;
F_41 ( V_72 , NULL ) ;
F_47 ( V_2 -> V_6 ) ;
F_48 ( V_2 ) ;
}
