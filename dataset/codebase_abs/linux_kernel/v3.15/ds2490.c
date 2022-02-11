static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , F_3 ( V_2 -> V_6 , V_2 -> V_7 [ V_8 ] ) ,
V_9 , V_10 , V_3 , V_4 , NULL , 0 , 1000 ) ;
if ( V_5 < 0 ) {
F_4 ( V_11 L_1 ,
V_3 , V_4 , V_5 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , F_3 ( V_2 -> V_6 , V_2 -> V_7 [ V_8 ] ) ,
V_12 , V_10 , V_3 , V_4 , NULL , 0 , 1000 ) ;
if ( V_5 < 0 ) {
F_4 ( V_11 L_2 ,
V_3 , V_4 , V_5 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , F_3 ( V_2 -> V_6 , V_2 -> V_7 [ V_8 ] ) ,
V_13 , V_10 , V_3 , V_4 , NULL , 0 , 1000 ) ;
if ( V_5 < 0 ) {
F_4 ( V_11 L_3 ,
V_3 , V_4 , V_5 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_14 * V_15 ,
unsigned char * V_16 , int V_17 )
{
int V_18 , V_5 ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_18 = 0 ;
V_5 = F_8 ( V_2 -> V_6 , F_9 ( V_2 -> V_6 ,
V_2 -> V_7 [ V_19 ] ) , V_16 , V_17 , & V_18 , 100 ) ;
if ( V_5 < 0 ) {
F_4 ( V_11 L_4 , V_2 -> V_7 [ V_19 ] , V_5 ) ;
return V_5 ;
}
if ( V_18 >= sizeof( * V_15 ) )
memcpy ( V_15 , V_16 , sizeof( * V_15 ) ) ;
return V_18 ;
}
static inline void F_10 ( unsigned char * V_16 , unsigned char * V_20 , int V_21 )
{
F_4 ( V_22 L_5 , V_20 , V_16 [ V_21 ] ) ;
}
static void F_11 ( struct V_1 * V_2 , unsigned char * V_16 , int V_18 )
{
int V_23 ;
F_4 ( V_22 L_6 , V_2 -> V_7 [ V_19 ] , V_18 ) ;
for ( V_23 = 0 ; V_23 < V_18 ; ++ V_23 )
F_4 ( L_7 , V_16 [ V_23 ] ) ;
F_4 ( V_22 L_8 ) ;
if ( V_18 >= 16 ) {
F_10 ( V_16 , L_9 , 0 ) ;
F_10 ( V_16 , L_10 , 1 ) ;
F_10 ( V_16 , L_11 , 2 ) ;
F_10 ( V_16 , L_12 , 3 ) ;
F_10 ( V_16 , L_13 , 4 ) ;
F_10 ( V_16 , L_14 , 5 ) ;
F_10 ( V_16 , L_15 ,
6 ) ;
F_10 ( V_16 , L_16 , 7 ) ;
F_10 ( V_16 , L_17 , 8 ) ;
F_10 ( V_16 , L_18 , 9 ) ;
F_10 ( V_16 , L_19 , 10 ) ;
F_10 ( V_16 , L_20 , 11 ) ;
F_10 ( V_16 , L_21 , 12 ) ;
F_10 ( V_16 , L_22 , 13 ) ;
F_10 ( V_16 , L_23 , 14 ) ;
F_10 ( V_16 , L_23 , 15 ) ;
}
for ( V_23 = 16 ; V_23 < V_18 ; ++ V_23 ) {
if ( V_16 [ V_23 ] == V_24 ) {
F_10 ( V_16 , L_24 , V_23 ) ;
continue;
}
F_10 ( V_16 , L_25 , V_23 ) ;
if ( V_16 [ V_23 ] & V_25 )
F_4 ( V_22 L_26 ) ;
if ( V_16 [ V_23 ] & V_26 )
F_4 ( V_22 L_27 ) ;
if ( V_16 [ V_23 ] & V_27 )
F_4 ( V_22 L_28 ) ;
if ( V_16 [ V_23 ] & V_28 )
F_4 ( V_22 L_29 ) ;
if ( V_16 [ V_23 ] & V_29 )
F_4 ( V_22 L_30 ) ;
if ( V_16 [ V_23 ] & V_30 )
F_4 ( V_22 L_31 ) ;
if ( V_16 [ V_23 ] & V_31 )
F_4 ( V_22 L_32 ) ;
if ( V_16 [ V_23 ] & V_32 )
F_4 ( V_22 L_33 ) ;
}
}
static void F_12 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_33 , 0 ) ;
if ( F_5 ( V_2 , V_34 , V_35 ) )
F_4 ( V_11 L_34
L_35 ) ;
if ( V_2 -> V_36 ) {
T_2 V_37 = V_2 -> V_36 >> 4 ;
if ( F_6 ( V_2 , V_38 | V_39 , V_37 ) )
F_4 ( V_11 L_34
L_36 ) ;
}
}
static int F_13 ( struct V_1 * V_2 , unsigned char * V_16 , int V_17 )
{
int V_18 , V_5 ;
struct V_14 V_15 ;
V_18 = 0 ;
V_5 = F_14 ( V_2 -> V_6 , F_15 ( V_2 -> V_6 , V_2 -> V_7 [ V_40 ] ) ,
V_16 , V_17 , & V_18 , 1000 ) ;
if ( V_5 < 0 ) {
T_2 V_16 [ V_41 ] ;
int V_18 ;
F_4 ( V_22 L_37 , V_2 -> V_7 [ V_40 ] ) ;
F_16 ( V_2 -> V_6 , F_15 ( V_2 -> V_6 , V_2 -> V_7 [ V_40 ] ) ) ;
V_18 = F_7 ( V_2 , & V_15 , V_16 , sizeof( V_16 ) ) ;
F_11 ( V_2 , V_16 , V_18 ) ;
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
return V_18 ;
}
static int F_17 ( struct V_1 * V_2 , unsigned char * V_16 , int V_42 )
{
int V_18 , V_5 ;
V_18 = 0 ;
V_5 = F_14 ( V_2 -> V_6 , F_18 ( V_2 -> V_6 , V_2 -> V_7 [ V_43 ] ) , V_16 , V_42 , & V_18 , 1000 ) ;
if ( V_5 < 0 ) {
F_4 ( V_11 L_38
L_39 , V_2 -> V_7 [ V_43 ] , V_5 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
T_2 V_16 [ V_41 ] ;
int V_5 , V_18 = 0 ;
do {
V_15 -> V_44 = 0 ;
V_5 = F_7 ( V_2 , V_15 , V_16 , sizeof( V_16 ) ) ;
#if 0
if (err >= 0) {
int i;
printk("0x%x: count=%d, status: ", dev->ep[EP_STATUS], err);
for (i=0; i<err; ++i)
printk("%02x ", buf[i]);
printk("\n");
}
#endif
} while ( ! ( V_15 -> V_44 & V_45 ) && ! ( V_5 < 0 ) && ++ V_18 < 100 );
if ( V_5 >= 16 && V_15 -> V_44 & V_46 ) {
F_4 ( V_22 L_40 ) ;
F_12 ( V_2 ) ;
V_18 = 101 ;
}
if ( V_5 > 16 || V_18 >= 100 || V_5 < 0 )
F_11 ( V_2 , V_16 , V_5 ) ;
if ( V_18 >= 100 || V_5 < 0 )
return - 1 ;
else
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_6 ( V_2 , V_47 | V_39 , V_48 ) ;
if ( V_5 )
return V_5 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , int V_49 )
{
int V_5 = 0 ;
T_2 V_37 = 1 + ( T_2 ) ( V_49 >> 4 ) ;
int V_50 = V_37 << 4 ;
V_2 -> V_51 = V_49 ? V_52 : 0 ;
if ( V_49 == 0 || V_50 == V_2 -> V_36 )
return V_5 ;
V_5 = F_6 ( V_2 , V_38 | V_39 , V_37 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_36 = V_50 ;
return V_5 ;
}
static int F_22 ( struct V_1 * V_2 , T_2 V_53 , T_2 * V_54 )
{
int V_5 ;
struct V_14 V_15 ;
V_5 = F_6 ( V_2 , V_55 | V_39 | ( V_53 ? V_56 : 0 ) ,
0 ) ;
if ( V_5 )
return V_5 ;
F_19 ( V_2 , & V_15 ) ;
V_5 = F_13 ( V_2 , V_54 , sizeof( * V_54 ) ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , T_2 V_57 )
{
int V_5 ;
struct V_14 V_15 ;
T_2 V_58 ;
V_5 = F_6 ( V_2 , V_59 | V_39 | V_2 -> V_51 , V_57 ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_51 )
F_24 ( V_2 -> V_36 ) ;
V_5 = F_19 ( V_2 , & V_15 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_13 ( V_2 , & V_58 , sizeof( V_58 ) ) ;
if ( V_5 < 0 )
return V_5 ;
return ! ( V_57 == V_58 ) ;
}
static int F_25 ( struct V_1 * V_2 , T_2 * V_57 )
{
int V_5 ;
struct V_14 V_15 ;
V_5 = F_6 ( V_2 , V_59 | V_39 , 0xff ) ;
if ( V_5 )
return V_5 ;
F_19 ( V_2 , & V_15 ) ;
V_5 = F_13 ( V_2 , V_57 , sizeof( * V_57 ) ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , T_2 * V_16 , int V_42 )
{
struct V_14 V_15 ;
int V_5 ;
if ( V_42 > 64 * 1024 )
return - V_60 ;
memset ( V_16 , 0xFF , V_42 ) ;
V_5 = F_17 ( V_2 , V_16 , V_42 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_6 ( V_2 , V_61 | V_39 , V_42 ) ;
if ( V_5 )
return V_5 ;
F_19 ( V_2 , & V_15 ) ;
memset ( V_16 , 0x00 , V_42 ) ;
V_5 = F_13 ( V_2 , V_16 , V_42 ) ;
return V_5 ;
}
static int F_27 ( struct V_1 * V_2 , T_2 * V_16 , int V_42 )
{
int V_5 ;
struct V_14 V_15 ;
V_5 = F_17 ( V_2 , V_16 , V_42 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_6 ( V_2 , V_61 | V_39 | V_2 -> V_51 , V_42 ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_51 )
F_24 ( V_2 -> V_36 ) ;
F_19 ( V_2 , & V_15 ) ;
V_5 = F_13 ( V_2 , V_16 , V_42 ) ;
if ( V_5 < 0 )
return V_5 ;
return ! ( V_5 == V_42 ) ;
}
static void F_28 ( void * V_62 , struct V_63 * V_64 ,
T_2 V_65 , T_3 V_66 )
{
struct V_1 * V_2 = V_62 ;
int V_5 ;
T_1 V_3 , V_4 ;
struct V_14 V_15 ;
T_2 V_67 [ V_41 ] ;
int V_68 ;
int V_69 = 0 ;
int V_23 ;
const unsigned long V_70 = F_29 ( 1000 * 8 / 75 ) ;
T_4 V_16 [ 2 * 64 / 8 ] ;
F_30 ( & V_64 -> V_71 ) ;
if ( F_17 ( V_2 , ( T_2 * ) & V_64 -> V_72 , 8 ) < 0 )
goto V_73;
V_64 -> V_72 = 0 ;
V_3 = V_74 | V_39 | V_75 | V_76 | V_77 |
V_78 ;
V_68 = V_64 -> V_79 ;
if ( V_68 > 255 )
V_68 = 0 ;
V_4 = V_65 | ( V_68 << 8 ) ;
if ( F_6 ( V_2 , V_3 , V_4 ) < 0 )
goto V_73;
do {
F_31 ( V_70 ) ;
if ( F_7 ( V_2 , & V_15 , V_67 , sizeof( V_67 ) ) <
sizeof( V_15 ) ) {
break;
}
if ( V_15 . V_80 ) {
V_5 = F_13 ( V_2 , ( T_2 * ) V_16 , sizeof( V_16 ) ) ;
if ( V_5 < 0 )
break;
for ( V_23 = 0 ; V_23 < V_5 / 8 ; ++ V_23 ) {
++ V_69 ;
if ( V_69 <= V_68 )
V_66 ( V_64 , V_16 [ V_23 ] ) ;
if ( V_69 == V_68 )
V_64 -> V_72 = V_16 [ V_23 ] ;
}
}
if ( F_32 ( V_81 , & V_64 -> V_82 ) )
break;
} while ( ! ( V_15 . V_44 & ( V_45 | V_83 ) ) );
if ( V_69 <= V_68 ) {
V_64 -> V_72 = 0 ;
} else if ( ! F_32 ( V_84 , & V_64 -> V_82 ) ) {
F_33 ( & V_2 -> V_6 -> V_2 , L_41
L_42 , V_85 ,
V_64 -> V_79 ) ;
F_34 ( V_84 , & V_64 -> V_82 ) ;
}
V_73:
F_35 ( & V_64 -> V_71 ) ;
}
static T_2 F_36 ( void * V_62 , T_2 V_53 )
{
T_2 V_86 ;
struct V_1 * V_2 = V_62 ;
if ( F_22 ( V_2 , V_53 , & V_86 ) )
return 0 ;
return V_86 ;
}
static void F_37 ( void * V_62 , T_2 V_57 )
{
struct V_1 * V_2 = V_62 ;
F_23 ( V_2 , V_57 ) ;
}
static T_2 F_38 ( void * V_62 )
{
struct V_1 * V_2 = V_62 ;
int V_5 ;
T_2 V_57 = 0 ;
V_5 = F_25 ( V_2 , & V_57 ) ;
if ( V_5 )
return 0 ;
return V_57 ;
}
static void F_39 ( void * V_62 , const T_2 * V_16 , int V_42 )
{
struct V_1 * V_2 = V_62 ;
F_27 ( V_2 , ( T_2 * ) V_16 , V_42 ) ;
}
static T_2 F_40 ( void * V_62 , T_2 * V_16 , int V_42 )
{
struct V_1 * V_2 = V_62 ;
int V_5 ;
V_5 = F_26 ( V_2 , V_16 , V_42 ) ;
if ( V_5 < 0 )
return 0 ;
return V_42 ;
}
static T_2 F_41 ( void * V_62 )
{
struct V_1 * V_2 = V_62 ;
int V_5 ;
V_5 = F_20 ( V_2 ) ;
if ( V_5 )
return 1 ;
return 0 ;
}
static T_2 F_42 ( void * V_62 , int V_49 )
{
struct V_1 * V_2 = V_62 ;
if ( F_21 ( V_2 , V_49 ) )
return 1 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
memset ( & V_2 -> V_64 , 0 , sizeof( struct V_87 ) ) ;
F_12 ( V_2 ) ;
V_2 -> V_64 . V_62 = V_2 ;
V_2 -> V_64 . V_88 = & F_36 ;
V_2 -> V_64 . V_89 = & F_38 ;
V_2 -> V_64 . V_90 = & F_37 ;
V_2 -> V_64 . V_91 = & F_40 ;
V_2 -> V_64 . V_92 = & F_39 ;
V_2 -> V_64 . V_93 = & F_41 ;
V_2 -> V_64 . V_94 = & F_42 ;
V_2 -> V_64 . V_95 = & F_28 ;
return F_44 ( & V_2 -> V_64 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_46 ( & V_2 -> V_64 ) ;
}
static int F_47 ( struct V_96 * V_97 ,
const struct V_98 * V_99 )
{
struct V_100 * V_6 = F_48 ( V_97 ) ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
struct V_1 * V_2 ;
int V_23 , V_5 , V_105 ;
V_2 = F_49 ( sizeof( struct V_1 ) , V_106 ) ;
if ( ! V_2 ) {
F_4 ( V_22 L_43 ) ;
return - V_107 ;
}
V_2 -> V_6 = F_50 ( V_6 ) ;
if ( ! V_2 -> V_6 ) {
V_5 = - V_107 ;
goto V_108;
}
memset ( V_2 -> V_7 , 0 , sizeof( V_2 -> V_7 ) ) ;
F_51 ( V_97 , V_2 ) ;
V_5 = F_52 ( V_2 -> V_6 ) ;
if ( V_5 ) {
F_53 ( & V_2 -> V_6 -> V_2 ,
L_44 , V_5 ) ;
goto V_109;
}
V_105 = 3 ;
V_5 = F_54 ( V_2 -> V_6 ,
V_97 -> V_110 [ V_105 ] . V_111 . V_112 , V_105 ) ;
if ( V_5 ) {
F_53 ( & V_2 -> V_6 -> V_2 , L_45
L_46 , V_105 ,
V_97 -> V_110 [ V_105 ] . V_111 . V_112 , V_5 ) ;
goto V_109;
}
V_104 = & V_97 -> V_110 [ V_105 ] ;
if ( V_104 -> V_111 . V_113 != V_114 - 1 ) {
F_4 ( V_22 L_47 , V_104 -> V_111 . V_113 ) ;
V_5 = - V_115 ;
goto V_109;
}
for ( V_23 = 0 ; V_23 < V_104 -> V_111 . V_113 ; ++ V_23 ) {
V_102 = & V_104 -> V_102 [ V_23 ] . V_111 ;
V_2 -> V_7 [ V_23 + 1 ] = V_102 -> V_116 ;
#if 0
printk("%d: addr=%x, size=%d, dir=%s, type=%x\n",
i, endpoint->bEndpointAddress, le16_to_cpu(endpoint->wMaxPacketSize),
(endpoint->bEndpointAddress & USB_DIR_IN)?"IN":"OUT",
endpoint->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK);
#endif
}
V_5 = F_43 ( V_2 ) ;
if ( V_5 )
goto V_109;
F_30 ( & V_117 ) ;
F_55 ( & V_2 -> V_118 , & V_119 ) ;
F_35 ( & V_117 ) ;
return 0 ;
V_109:
F_51 ( V_97 , NULL ) ;
F_56 ( V_2 -> V_6 ) ;
V_108:
F_57 ( V_2 ) ;
return V_5 ;
}
static void F_58 ( struct V_96 * V_97 )
{
struct V_1 * V_2 ;
V_2 = F_59 ( V_97 ) ;
if ( ! V_2 )
return;
F_30 ( & V_117 ) ;
F_60 ( & V_2 -> V_118 ) ;
F_35 ( & V_117 ) ;
F_45 ( V_2 ) ;
F_51 ( V_97 , NULL ) ;
F_56 ( V_2 -> V_6 ) ;
F_57 ( V_2 ) ;
}
