static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , F_3 ( V_2 -> V_6 , V_2 -> V_7 [ V_8 ] ) ,
V_9 , V_10 , V_3 , V_4 , NULL , 0 , 1000 ) ;
if ( V_5 < 0 ) {
F_4 ( L_1 ,
V_3 , V_4 , V_5 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , F_3 ( V_2 -> V_6 , V_2 -> V_7 [ V_8 ] ) ,
V_11 , V_10 , V_3 , V_4 , NULL , 0 , 1000 ) ;
if ( V_5 < 0 ) {
F_4 ( L_2 ,
V_3 , V_4 , V_5 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , F_3 ( V_2 -> V_6 , V_2 -> V_7 [ V_8 ] ) ,
V_12 , V_10 , V_3 , V_4 , NULL , 0 , 1000 ) ;
if ( V_5 < 0 ) {
F_4 ( L_3 ,
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
V_5 = F_8 ( V_2 -> V_6 , F_9 ( V_2 -> V_6 ,
V_2 -> V_7 [ V_18 ] ) , V_15 , V_16 , & V_17 , 100 ) ;
if ( V_5 < 0 ) {
F_4 ( L_4 ,
V_2 -> V_7 [ V_18 ] , V_5 ) ;
return V_5 ;
}
if ( V_17 >= sizeof( * V_14 ) )
memcpy ( V_14 , V_15 , sizeof( * V_14 ) ) ;
return V_17 ;
}
static inline void F_10 ( unsigned char * V_15 , unsigned char * V_19 , int V_20 )
{
F_11 ( L_5 , V_19 , V_15 [ V_20 ] ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned char * V_15 , int V_17 )
{
int V_21 ;
F_11 ( L_6 , V_2 -> V_7 [ V_18 ] , V_17 ) ;
for ( V_21 = 0 ; V_21 < V_17 ; ++ V_21 )
F_11 ( L_7 , V_15 [ V_21 ] ) ;
F_11 ( L_8 ) ;
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
for ( V_21 = 16 ; V_21 < V_17 ; ++ V_21 ) {
if ( V_15 [ V_21 ] == V_22 ) {
F_10 ( V_15 , L_24 , V_21 ) ;
continue;
}
F_10 ( V_15 , L_25 , V_21 ) ;
if ( V_15 [ V_21 ] & V_23 )
F_11 ( L_26 ) ;
if ( V_15 [ V_21 ] & V_24 )
F_11 ( L_27 ) ;
if ( V_15 [ V_21 ] & V_25 )
F_11 ( L_28 ) ;
if ( V_15 [ V_21 ] & V_26 )
F_11 ( L_29 ) ;
if ( V_15 [ V_21 ] & V_27 )
F_11 ( L_30 ) ;
if ( V_15 [ V_21 ] & V_28 )
F_11 ( L_31 ) ;
if ( V_15 [ V_21 ] & V_29 )
F_11 ( L_32 ) ;
if ( V_15 [ V_21 ] & V_30 )
F_11 ( L_33 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_31 , 0 ) ;
if ( F_5 ( V_2 , V_32 , V_33 ) )
F_4 ( L_34 ) ;
if ( V_2 -> V_34 ) {
T_2 V_35 = V_2 -> V_34 >> 4 ;
if ( F_6 ( V_2 , V_36 | V_37 , V_35 ) )
F_4 ( L_35 ) ;
}
}
static int F_14 ( struct V_1 * V_2 , unsigned char * V_15 , int V_16 )
{
int V_17 , V_5 ;
struct V_13 V_14 ;
V_17 = 0 ;
V_5 = F_15 ( V_2 -> V_6 , F_16 ( V_2 -> V_6 , V_2 -> V_7 [ V_38 ] ) ,
V_15 , V_16 , & V_17 , 1000 ) ;
if ( V_5 < 0 ) {
T_2 V_15 [ V_39 ] ;
int V_17 ;
F_11 ( L_36 , V_2 -> V_7 [ V_38 ] ) ;
F_17 ( V_2 -> V_6 , F_16 ( V_2 -> V_6 , V_2 -> V_7 [ V_38 ] ) ) ;
V_17 = F_7 ( V_2 , & V_14 , V_15 , sizeof( V_15 ) ) ;
F_12 ( V_2 , V_15 , V_17 ) ;
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
static int F_18 ( struct V_1 * V_2 , unsigned char * V_15 , int V_40 )
{
int V_17 , V_5 ;
V_17 = 0 ;
V_5 = F_15 ( V_2 -> V_6 , F_19 ( V_2 -> V_6 , V_2 -> V_7 [ V_41 ] ) , V_15 , V_40 , & V_17 , 1000 ) ;
if ( V_5 < 0 ) {
F_4 ( L_37
L_38 , V_2 -> V_7 [ V_41 ] , V_5 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
T_2 V_15 [ V_39 ] ;
int V_5 , V_17 = 0 ;
do {
V_14 -> V_42 = 0 ;
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
} while ( ! ( V_14 -> V_42 & V_43 ) && ! ( V_5 < 0 ) && ++ V_17 < 100 );
if ( V_5 >= 16 && V_14 -> V_42 & V_44 ) {
F_11 ( L_39 ) ;
F_13 ( V_2 ) ;
V_17 = 101 ;
}
if ( V_5 > 16 || V_17 >= 100 || V_5 < 0 )
F_12 ( V_2 , V_15 , V_5 ) ;
if ( V_17 >= 100 || V_5 < 0 )
return - 1 ;
else
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_6 ( V_2 , V_45 | V_37 , V_46 ) ;
if ( V_5 )
return V_5 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , int V_47 )
{
int V_5 = 0 ;
T_2 V_35 = 1 + ( T_2 ) ( V_47 >> 4 ) ;
int V_48 = V_35 << 4 ;
V_2 -> V_49 = V_47 ? V_50 : 0 ;
if ( V_47 == 0 || V_48 == V_2 -> V_34 )
return V_5 ;
V_5 = F_6 ( V_2 , V_36 | V_37 , V_35 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_34 = V_48 ;
return V_5 ;
}
static int F_23 ( struct V_1 * V_2 , T_2 V_51 , T_2 * V_52 )
{
int V_5 ;
struct V_13 V_14 ;
V_5 = F_6 ( V_2 , V_53 | V_37 | ( V_51 ? V_54 : 0 ) ,
0 ) ;
if ( V_5 )
return V_5 ;
F_20 ( V_2 , & V_14 ) ;
V_5 = F_14 ( V_2 , V_52 , sizeof( * V_52 ) ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , T_2 V_55 )
{
int V_5 ;
struct V_13 V_14 ;
T_2 V_56 ;
V_5 = F_6 ( V_2 , V_57 | V_37 | V_2 -> V_49 , V_55 ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_49 )
F_25 ( V_2 -> V_34 ) ;
V_5 = F_20 ( V_2 , & V_14 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_14 ( V_2 , & V_56 , sizeof( V_56 ) ) ;
if ( V_5 < 0 )
return V_5 ;
return ! ( V_55 == V_56 ) ;
}
static int F_26 ( struct V_1 * V_2 , T_2 * V_55 )
{
int V_5 ;
struct V_13 V_14 ;
V_5 = F_6 ( V_2 , V_57 | V_37 , 0xff ) ;
if ( V_5 )
return V_5 ;
F_20 ( V_2 , & V_14 ) ;
V_5 = F_14 ( V_2 , V_55 , sizeof( * V_55 ) ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , T_2 * V_15 , int V_40 )
{
struct V_13 V_14 ;
int V_5 ;
if ( V_40 > 64 * 1024 )
return - V_58 ;
memset ( V_15 , 0xFF , V_40 ) ;
V_5 = F_18 ( V_2 , V_15 , V_40 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_6 ( V_2 , V_59 | V_37 , V_40 ) ;
if ( V_5 )
return V_5 ;
F_20 ( V_2 , & V_14 ) ;
memset ( V_15 , 0x00 , V_40 ) ;
V_5 = F_14 ( V_2 , V_15 , V_40 ) ;
return V_5 ;
}
static int F_28 ( struct V_1 * V_2 , T_2 * V_15 , int V_40 )
{
int V_5 ;
struct V_13 V_14 ;
V_5 = F_18 ( V_2 , V_15 , V_40 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_6 ( V_2 , V_59 | V_37 | V_2 -> V_49 , V_40 ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_49 )
F_25 ( V_2 -> V_34 ) ;
F_20 ( V_2 , & V_14 ) ;
V_5 = F_14 ( V_2 , V_15 , V_40 ) ;
if ( V_5 < 0 )
return V_5 ;
return ! ( V_5 == V_40 ) ;
}
static void F_29 ( void * V_60 , struct V_61 * V_62 ,
T_2 V_63 , T_3 V_64 )
{
struct V_1 * V_2 = V_60 ;
int V_5 ;
T_1 V_3 , V_4 ;
struct V_13 V_14 ;
T_2 V_65 [ V_39 ] ;
int V_66 ;
int V_67 = 0 ;
int V_21 ;
const unsigned long V_68 = F_30 ( 1000 * 8 / 75 ) ;
T_4 V_15 [ 2 * 64 / 8 ] ;
F_31 ( & V_62 -> V_69 ) ;
if ( F_18 ( V_2 , ( T_2 * ) & V_62 -> V_70 , 8 ) < 0 )
goto V_71;
V_62 -> V_70 = 0 ;
V_3 = V_72 | V_37 | V_73 | V_74 | V_75 |
V_76 ;
V_66 = V_62 -> V_77 ;
if ( V_66 > 255 )
V_66 = 0 ;
V_4 = V_63 | ( V_66 << 8 ) ;
if ( F_6 ( V_2 , V_3 , V_4 ) < 0 )
goto V_71;
do {
F_32 ( V_68 ) ;
if ( F_7 ( V_2 , & V_14 , V_65 , sizeof( V_65 ) ) <
sizeof( V_14 ) ) {
break;
}
if ( V_14 . V_78 ) {
V_5 = F_14 ( V_2 , ( T_2 * ) V_15 , sizeof( V_15 ) ) ;
if ( V_5 < 0 )
break;
for ( V_21 = 0 ; V_21 < V_5 / 8 ; ++ V_21 ) {
++ V_67 ;
if ( V_67 <= V_66 )
V_64 ( V_62 , V_15 [ V_21 ] ) ;
if ( V_67 == V_66 )
V_62 -> V_70 = V_15 [ V_21 ] ;
}
}
if ( F_33 ( V_79 , & V_62 -> V_80 ) )
break;
} while ( ! ( V_14 . V_42 & ( V_43 | V_81 ) ) );
if ( V_67 <= V_66 ) {
V_62 -> V_70 = 0 ;
} else if ( ! F_33 ( V_82 , & V_62 -> V_80 ) ) {
F_34 ( & V_2 -> V_6 -> V_2 , L_40
L_41 , V_83 ,
V_62 -> V_77 ) ;
F_35 ( V_82 , & V_62 -> V_80 ) ;
}
V_71:
F_36 ( & V_62 -> V_69 ) ;
}
static T_2 F_37 ( void * V_60 , T_2 V_51 )
{
T_2 V_84 ;
struct V_1 * V_2 = V_60 ;
if ( F_23 ( V_2 , V_51 , & V_84 ) )
return 0 ;
return V_84 ;
}
static void F_38 ( void * V_60 , T_2 V_55 )
{
struct V_1 * V_2 = V_60 ;
F_24 ( V_2 , V_55 ) ;
}
static T_2 F_39 ( void * V_60 )
{
struct V_1 * V_2 = V_60 ;
int V_5 ;
T_2 V_55 = 0 ;
V_5 = F_26 ( V_2 , & V_55 ) ;
if ( V_5 )
return 0 ;
return V_55 ;
}
static void F_40 ( void * V_60 , const T_2 * V_15 , int V_40 )
{
struct V_1 * V_2 = V_60 ;
F_28 ( V_2 , ( T_2 * ) V_15 , V_40 ) ;
}
static T_2 F_41 ( void * V_60 , T_2 * V_15 , int V_40 )
{
struct V_1 * V_2 = V_60 ;
int V_5 ;
V_5 = F_27 ( V_2 , V_15 , V_40 ) ;
if ( V_5 < 0 )
return 0 ;
return V_40 ;
}
static T_2 F_42 ( void * V_60 )
{
struct V_1 * V_2 = V_60 ;
int V_5 ;
V_5 = F_21 ( V_2 ) ;
if ( V_5 )
return 1 ;
return 0 ;
}
static T_2 F_43 ( void * V_60 , int V_47 )
{
struct V_1 * V_2 = V_60 ;
if ( F_22 ( V_2 , V_47 ) )
return 1 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
memset ( & V_2 -> V_62 , 0 , sizeof( struct V_85 ) ) ;
F_13 ( V_2 ) ;
V_2 -> V_62 . V_60 = V_2 ;
V_2 -> V_62 . V_86 = & F_37 ;
V_2 -> V_62 . V_87 = & F_39 ;
V_2 -> V_62 . V_88 = & F_38 ;
V_2 -> V_62 . V_89 = & F_41 ;
V_2 -> V_62 . V_90 = & F_40 ;
V_2 -> V_62 . V_91 = & F_42 ;
V_2 -> V_62 . V_92 = & F_43 ;
V_2 -> V_62 . V_93 = & F_29 ;
return F_45 ( & V_2 -> V_62 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_47 ( & V_2 -> V_62 ) ;
}
static int F_48 ( struct V_94 * V_95 ,
const struct V_96 * V_97 )
{
struct V_98 * V_6 = F_49 ( V_95 ) ;
struct V_99 * V_100 ;
struct V_101 * V_102 ;
struct V_1 * V_2 ;
int V_21 , V_5 , V_103 ;
V_2 = F_50 ( sizeof( struct V_1 ) , V_104 ) ;
if ( ! V_2 ) {
F_11 ( L_42 ) ;
return - V_105 ;
}
V_2 -> V_6 = F_51 ( V_6 ) ;
if ( ! V_2 -> V_6 ) {
V_5 = - V_105 ;
goto V_106;
}
memset ( V_2 -> V_7 , 0 , sizeof( V_2 -> V_7 ) ) ;
F_52 ( V_95 , V_2 ) ;
V_5 = F_53 ( V_2 -> V_6 ) ;
if ( V_5 ) {
F_54 ( & V_2 -> V_6 -> V_2 ,
L_43 , V_5 ) ;
goto V_107;
}
V_103 = 3 ;
V_5 = F_55 ( V_2 -> V_6 ,
V_95 -> V_108 [ V_103 ] . V_109 . V_110 , V_103 ) ;
if ( V_5 ) {
F_54 ( & V_2 -> V_6 -> V_2 , L_44
L_45 , V_103 ,
V_95 -> V_108 [ V_103 ] . V_109 . V_110 , V_5 ) ;
goto V_107;
}
V_102 = & V_95 -> V_108 [ V_103 ] ;
if ( V_102 -> V_109 . V_111 != V_112 - 1 ) {
F_11 ( L_46 ,
V_102 -> V_109 . V_111 ) ;
V_5 = - V_113 ;
goto V_107;
}
for ( V_21 = 0 ; V_21 < V_102 -> V_109 . V_111 ; ++ V_21 ) {
V_100 = & V_102 -> V_100 [ V_21 ] . V_109 ;
V_2 -> V_7 [ V_21 + 1 ] = V_100 -> V_114 ;
#if 0
printk("%d: addr=%x, size=%d, dir=%s, type=%x\n",
i, endpoint->bEndpointAddress, le16_to_cpu(endpoint->wMaxPacketSize),
(endpoint->bEndpointAddress & USB_DIR_IN)?"IN":"OUT",
endpoint->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK);
#endif
}
V_5 = F_44 ( V_2 ) ;
if ( V_5 )
goto V_107;
F_31 ( & V_115 ) ;
F_56 ( & V_2 -> V_116 , & V_117 ) ;
F_36 ( & V_115 ) ;
return 0 ;
V_107:
F_52 ( V_95 , NULL ) ;
F_57 ( V_2 -> V_6 ) ;
V_106:
F_58 ( V_2 ) ;
return V_5 ;
}
static void F_59 ( struct V_94 * V_95 )
{
struct V_1 * V_2 ;
V_2 = F_60 ( V_95 ) ;
if ( ! V_2 )
return;
F_31 ( & V_115 ) ;
F_61 ( & V_2 -> V_116 ) ;
F_36 ( & V_115 ) ;
F_46 ( V_2 ) ;
F_52 ( V_95 , NULL ) ;
F_57 ( V_2 -> V_6 ) ;
F_58 ( V_2 ) ;
}
