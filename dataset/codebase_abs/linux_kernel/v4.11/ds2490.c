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
static inline void F_7 ( unsigned char * V_13 , unsigned char * V_14 , int V_15 )
{
F_8 ( L_4 , V_14 , V_13 [ V_15 ] ) ;
}
static void F_9 ( struct V_1 * V_2 , unsigned char * V_13 , int V_16 )
{
int V_17 ;
F_8 ( L_5 , V_2 -> V_7 [ V_18 ] , V_16 ) ;
for ( V_17 = 0 ; V_17 < V_16 ; ++ V_17 )
F_8 ( L_6 , V_13 [ V_17 ] ) ;
F_8 ( L_7 ) ;
if ( V_16 >= 16 ) {
F_7 ( V_13 , L_8 , 0 ) ;
F_7 ( V_13 , L_9 , 1 ) ;
F_7 ( V_13 , L_10 , 2 ) ;
F_7 ( V_13 , L_11 , 3 ) ;
F_7 ( V_13 , L_12 , 4 ) ;
F_7 ( V_13 , L_13 , 5 ) ;
F_7 ( V_13 , L_14 ,
6 ) ;
F_7 ( V_13 , L_15 , 7 ) ;
F_7 ( V_13 , L_16 , 8 ) ;
F_7 ( V_13 , L_17 , 9 ) ;
F_7 ( V_13 , L_18 , 10 ) ;
F_7 ( V_13 , L_19 , 11 ) ;
F_7 ( V_13 , L_20 , 12 ) ;
F_7 ( V_13 , L_21 , 13 ) ;
F_7 ( V_13 , L_22 , 14 ) ;
F_7 ( V_13 , L_22 , 15 ) ;
}
for ( V_17 = 16 ; V_17 < V_16 ; ++ V_17 ) {
if ( V_13 [ V_17 ] == V_19 ) {
F_7 ( V_13 , L_23 , V_17 ) ;
continue;
}
F_7 ( V_13 , L_24 , V_17 ) ;
if ( V_13 [ V_17 ] & V_20 )
F_8 ( L_25 ) ;
if ( V_13 [ V_17 ] & V_21 )
F_8 ( L_26 ) ;
if ( V_13 [ V_17 ] & V_22 )
F_8 ( L_27 ) ;
if ( V_13 [ V_17 ] & V_23 )
F_8 ( L_28 ) ;
if ( V_13 [ V_17 ] & V_24 )
F_8 ( L_29 ) ;
if ( V_13 [ V_17 ] & V_25 )
F_8 ( L_30 ) ;
if ( V_13 [ V_17 ] & V_26 )
F_8 ( L_31 ) ;
if ( V_13 [ V_17 ] & V_27 )
F_8 ( L_32 ) ;
}
}
static int F_10 ( struct V_1 * V_2 , struct V_28 * V_29 ,
bool V_30 )
{
int V_16 , V_5 ;
if ( V_29 )
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_16 = 0 ;
V_5 = F_11 ( V_2 -> V_6 ,
F_12 ( V_2 -> V_6 ,
V_2 -> V_7 [ V_18 ] ) ,
V_2 -> V_31 , sizeof( V_2 -> V_31 ) ,
& V_16 , 1000 ) ;
if ( V_5 < 0 ) {
F_4 ( L_33 ,
V_2 -> V_7 [ V_18 ] , V_5 ) ;
return V_5 ;
}
if ( V_30 )
F_9 ( V_2 , V_2 -> V_31 , V_16 ) ;
if ( V_29 && V_16 >= sizeof( * V_29 ) )
memcpy ( V_29 , V_2 -> V_31 , sizeof( * V_29 ) ) ;
return V_16 ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_32 , 0 ) ;
if ( F_5 ( V_2 , V_33 , V_34 ) )
F_4 ( L_34 ) ;
if ( V_2 -> V_35 ) {
T_2 V_36 = V_2 -> V_35 >> 4 ;
if ( F_6 ( V_2 , V_37 | V_38 , V_36 ) )
F_4 ( L_35 ) ;
}
}
static int F_14 ( struct V_1 * V_2 , unsigned char * V_13 , int V_39 )
{
int V_16 , V_5 ;
V_16 = 0 ;
V_5 = F_15 ( V_2 -> V_6 , F_16 ( V_2 -> V_6 , V_2 -> V_7 [ V_40 ] ) ,
V_13 , V_39 , & V_16 , 1000 ) ;
if ( V_5 < 0 ) {
F_8 ( L_36 , V_2 -> V_7 [ V_40 ] ) ;
F_17 ( V_2 -> V_6 , F_16 ( V_2 -> V_6 , V_2 -> V_7 [ V_40 ] ) ) ;
F_10 ( V_2 , NULL , true ) ;
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
return V_16 ;
}
static int F_18 ( struct V_1 * V_2 , unsigned char * V_13 , int V_41 )
{
int V_16 , V_5 ;
V_16 = 0 ;
V_5 = F_15 ( V_2 -> V_6 , F_19 ( V_2 -> V_6 , V_2 -> V_7 [ V_42 ] ) , V_13 , V_41 , & V_16 , 1000 ) ;
if ( V_5 < 0 ) {
F_4 ( L_37
L_38 , V_2 -> V_7 [ V_42 ] , V_5 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
int V_5 , V_16 = 0 ;
do {
V_29 -> V_43 = 0 ;
V_5 = F_10 ( V_2 , V_29 , false ) ;
#if 0
if (err >= 0) {
int i;
printk("0x%x: count=%d, status: ", dev->ep[EP_STATUS], err);
for (i=0; i<err; ++i)
printk("%02x ", dev->st_buf[i]);
printk("\n");
}
#endif
} while ( ! ( V_29 -> V_43 & V_44 ) && ! ( V_5 < 0 ) && ++ V_16 < 100 );
if ( V_5 >= 16 && V_29 -> V_43 & V_45 ) {
F_8 ( L_39 ) ;
F_13 ( V_2 ) ;
V_16 = 101 ;
}
if ( V_5 > 16 || V_16 >= 100 || V_5 < 0 )
F_9 ( V_2 , V_2 -> V_31 , V_5 ) ;
if ( V_16 >= 100 || V_5 < 0 )
return - 1 ;
else
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_6 ( V_2 , V_46 | V_38 , V_47 ) ;
if ( V_5 )
return V_5 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , int V_48 )
{
int V_5 = 0 ;
T_2 V_36 = 1 + ( T_2 ) ( V_48 >> 4 ) ;
int V_49 = V_36 << 4 ;
V_2 -> V_50 = V_48 ? V_51 : 0 ;
if ( V_48 == 0 || V_49 == V_2 -> V_35 )
return V_5 ;
V_5 = F_6 ( V_2 , V_37 | V_38 , V_36 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_35 = V_49 ;
return V_5 ;
}
static int F_23 ( struct V_1 * V_2 , T_2 V_52 , T_2 * V_53 )
{
int V_5 ;
struct V_28 V_29 ;
V_5 = F_6 ( V_2 , V_54 | V_38 | ( V_52 ? V_55 : 0 ) ,
0 ) ;
if ( V_5 )
return V_5 ;
F_20 ( V_2 , & V_29 ) ;
V_5 = F_14 ( V_2 , V_53 , sizeof( * V_53 ) ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , T_2 V_56 )
{
int V_5 ;
struct V_28 V_29 ;
V_5 = F_6 ( V_2 , V_57 | V_38 | V_2 -> V_50 , V_56 ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_50 )
F_25 ( V_2 -> V_35 ) ;
V_5 = F_20 ( V_2 , & V_29 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_14 ( V_2 , & V_2 -> V_58 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
return ! ( V_56 == V_2 -> V_58 ) ;
}
static int F_26 ( struct V_1 * V_2 , T_2 * V_56 )
{
int V_5 ;
struct V_28 V_29 ;
V_5 = F_6 ( V_2 , V_57 | V_38 , 0xff ) ;
if ( V_5 )
return V_5 ;
F_20 ( V_2 , & V_29 ) ;
V_5 = F_14 ( V_2 , V_56 , sizeof( * V_56 ) ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , T_2 * V_13 , int V_41 )
{
struct V_28 V_29 ;
int V_5 ;
if ( V_41 > 64 * 1024 )
return - V_59 ;
memset ( V_13 , 0xFF , V_41 ) ;
V_5 = F_18 ( V_2 , V_13 , V_41 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_6 ( V_2 , V_60 | V_38 , V_41 ) ;
if ( V_5 )
return V_5 ;
F_20 ( V_2 , & V_29 ) ;
memset ( V_13 , 0x00 , V_41 ) ;
V_5 = F_14 ( V_2 , V_13 , V_41 ) ;
return V_5 ;
}
static int F_28 ( struct V_1 * V_2 , T_2 * V_13 , int V_41 )
{
int V_5 ;
struct V_28 V_29 ;
V_5 = F_18 ( V_2 , V_13 , V_41 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_6 ( V_2 , V_60 | V_38 | V_2 -> V_50 , V_41 ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_50 )
F_25 ( V_2 -> V_35 ) ;
F_20 ( V_2 , & V_29 ) ;
V_5 = F_14 ( V_2 , V_13 , V_41 ) ;
if ( V_5 < 0 )
return V_5 ;
return ! ( V_5 == V_41 ) ;
}
static void F_29 ( void * V_61 , struct V_62 * V_63 ,
T_2 V_64 , T_3 V_65 )
{
struct V_1 * V_2 = V_61 ;
int V_5 ;
T_1 V_3 , V_4 ;
struct V_28 V_29 ;
int V_66 ;
int V_67 = 0 ;
int V_17 ;
const unsigned long V_68 = F_30 ( 1000 * 8 / 75 ) ;
const T_4 V_69 = 2 * 64 ;
T_5 * V_13 ;
V_13 = F_31 ( V_69 , V_70 ) ;
if ( ! V_13 )
return;
F_32 ( & V_63 -> V_71 ) ;
if ( F_18 ( V_2 , ( T_2 * ) & V_63 -> V_72 , 8 ) < 0 )
goto V_73;
V_63 -> V_72 = 0 ;
V_3 = V_74 | V_38 | V_75 | V_76 | V_77 |
V_78 ;
V_66 = V_63 -> V_79 ;
if ( V_66 > 255 )
V_66 = 0 ;
V_4 = V_64 | ( V_66 << 8 ) ;
if ( F_6 ( V_2 , V_3 , V_4 ) < 0 )
goto V_73;
do {
F_33 ( V_68 ) ;
V_5 = F_10 ( V_2 , & V_29 , false ) ;
if ( V_5 < 0 || V_5 < sizeof( V_29 ) )
break;
if ( V_29 . V_80 ) {
V_5 = F_14 ( V_2 , ( T_2 * ) V_13 , V_69 ) ;
if ( V_5 < 0 )
break;
for ( V_17 = 0 ; V_17 < V_5 / 8 ; ++ V_17 ) {
++ V_67 ;
if ( V_67 <= V_66 )
V_65 ( V_63 , V_13 [ V_17 ] ) ;
if ( V_67 == V_66 )
V_63 -> V_72 = V_13 [ V_17 ] ;
}
}
if ( F_34 ( V_81 , & V_63 -> V_82 ) )
break;
} while ( ! ( V_29 . V_43 & ( V_44 | V_83 ) ) );
if ( V_67 <= V_66 ) {
V_63 -> V_72 = 0 ;
} else if ( ! F_34 ( V_84 , & V_63 -> V_82 ) ) {
F_35 ( & V_2 -> V_6 -> V_2 , L_40
L_41 , V_85 ,
V_63 -> V_79 ) ;
F_36 ( V_84 , & V_63 -> V_82 ) ;
}
V_73:
F_37 ( & V_63 -> V_71 ) ;
F_38 ( V_13 ) ;
}
static T_2 F_39 ( void * V_61 , T_2 V_52 )
{
struct V_1 * V_2 = V_61 ;
if ( F_23 ( V_2 , V_52 , & V_2 -> V_58 ) )
return 0 ;
return V_2 -> V_58 ;
}
static void F_40 ( void * V_61 , T_2 V_56 )
{
struct V_1 * V_2 = V_61 ;
F_24 ( V_2 , V_56 ) ;
}
static T_2 F_41 ( void * V_61 )
{
struct V_1 * V_2 = V_61 ;
int V_5 ;
V_5 = F_26 ( V_2 , & V_2 -> V_58 ) ;
if ( V_5 )
return 0 ;
return V_2 -> V_58 ;
}
static void F_42 ( void * V_61 , const T_2 * V_13 , int V_41 )
{
struct V_1 * V_2 = V_61 ;
T_2 * V_86 ;
if ( V_41 <= 0 )
return;
V_86 = F_43 ( V_13 , V_41 , V_70 ) ;
if ( ! V_86 )
return;
F_28 ( V_2 , V_86 , V_41 ) ;
F_38 ( V_86 ) ;
}
static T_2 F_44 ( void * V_61 , T_2 * V_13 , int V_41 )
{
struct V_1 * V_2 = V_61 ;
int V_5 ;
T_2 * V_86 ;
if ( V_41 <= 0 )
return 0 ;
V_86 = F_31 ( V_41 , V_70 ) ;
if ( ! V_86 )
return 0 ;
V_5 = F_27 ( V_2 , V_86 , V_41 ) ;
if ( V_5 >= 0 )
memcpy ( V_13 , V_86 , V_41 ) ;
F_38 ( V_86 ) ;
return V_5 >= 0 ? V_41 : 0 ;
}
static T_2 F_45 ( void * V_61 )
{
struct V_1 * V_2 = V_61 ;
int V_5 ;
V_5 = F_21 ( V_2 ) ;
if ( V_5 )
return 1 ;
return 0 ;
}
static T_2 F_46 ( void * V_61 , int V_48 )
{
struct V_1 * V_2 = V_61 ;
if ( F_22 ( V_2 , V_48 ) )
return 1 ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
memset ( & V_2 -> V_63 , 0 , sizeof( struct V_87 ) ) ;
F_13 ( V_2 ) ;
V_2 -> V_63 . V_61 = V_2 ;
V_2 -> V_63 . V_88 = & F_39 ;
V_2 -> V_63 . V_89 = & F_41 ;
V_2 -> V_63 . V_90 = & F_40 ;
V_2 -> V_63 . V_91 = & F_44 ;
V_2 -> V_63 . V_92 = & F_42 ;
V_2 -> V_63 . V_93 = & F_45 ;
V_2 -> V_63 . V_94 = & F_46 ;
V_2 -> V_63 . V_95 = & F_29 ;
return F_48 ( & V_2 -> V_63 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_50 ( & V_2 -> V_63 ) ;
}
static int F_51 ( struct V_96 * V_97 ,
const struct V_98 * V_99 )
{
struct V_100 * V_6 = F_52 ( V_97 ) ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
struct V_1 * V_2 ;
int V_17 , V_5 , V_105 ;
V_2 = F_53 ( sizeof( struct V_1 ) , V_70 ) ;
if ( ! V_2 ) {
F_8 ( L_42 ) ;
return - V_106 ;
}
V_2 -> V_6 = F_54 ( V_6 ) ;
if ( ! V_2 -> V_6 ) {
V_5 = - V_106 ;
goto V_107;
}
memset ( V_2 -> V_7 , 0 , sizeof( V_2 -> V_7 ) ) ;
F_55 ( V_97 , V_2 ) ;
V_5 = F_56 ( V_2 -> V_6 ) ;
if ( V_5 ) {
F_57 ( & V_2 -> V_6 -> V_2 ,
L_43 , V_5 ) ;
goto V_108;
}
V_105 = 3 ;
V_5 = F_58 ( V_2 -> V_6 ,
V_97 -> V_109 [ V_105 ] . V_110 . V_111 , V_105 ) ;
if ( V_5 ) {
F_57 ( & V_2 -> V_6 -> V_2 , L_44
L_45 , V_105 ,
V_97 -> V_109 [ V_105 ] . V_110 . V_111 , V_5 ) ;
goto V_108;
}
V_104 = & V_97 -> V_109 [ V_105 ] ;
if ( V_104 -> V_110 . V_112 != V_113 - 1 ) {
F_8 ( L_46 ,
V_104 -> V_110 . V_112 ) ;
V_5 = - V_114 ;
goto V_108;
}
for ( V_17 = 0 ; V_17 < V_104 -> V_110 . V_112 ; ++ V_17 ) {
V_102 = & V_104 -> V_102 [ V_17 ] . V_110 ;
V_2 -> V_7 [ V_17 + 1 ] = V_102 -> V_115 ;
#if 0
printk("%d: addr=%x, size=%d, dir=%s, type=%x\n",
i, endpoint->bEndpointAddress, le16_to_cpu(endpoint->wMaxPacketSize),
(endpoint->bEndpointAddress & USB_DIR_IN)?"IN":"OUT",
endpoint->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK);
#endif
}
V_5 = F_47 ( V_2 ) ;
if ( V_5 )
goto V_108;
F_32 ( & V_116 ) ;
F_59 ( & V_2 -> V_117 , & V_118 ) ;
F_37 ( & V_116 ) ;
return 0 ;
V_108:
F_55 ( V_97 , NULL ) ;
F_60 ( V_2 -> V_6 ) ;
V_107:
F_38 ( V_2 ) ;
return V_5 ;
}
static void F_61 ( struct V_96 * V_97 )
{
struct V_1 * V_2 ;
V_2 = F_62 ( V_97 ) ;
if ( ! V_2 )
return;
F_32 ( & V_116 ) ;
F_63 ( & V_2 -> V_117 ) ;
F_37 ( & V_116 ) ;
F_49 ( V_2 ) ;
F_55 ( V_97 , NULL ) ;
F_60 ( V_2 -> V_6 ) ;
F_38 ( V_2 ) ;
}
