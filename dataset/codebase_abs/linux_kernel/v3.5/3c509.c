static int F_1 ( T_1 * V_1 )
{
short V_2 = 0xff ;
int V_3 ;
F_2 ( 0x00 , V_4 ) ;
F_2 ( 0x00 , V_4 ) ;
for ( V_3 = 0 ; V_3 < 255 ; V_3 ++ ) {
F_2 ( V_2 , V_4 ) ;
V_2 <<= 1 ;
V_2 = V_2 & 0x100 ? V_2 ^ 0xcf : V_2 ;
}
if ( V_5 == 0 )
F_2 ( 0xd0 , V_4 ) ;
else
F_2 ( 0xd8 , V_4 ) ;
if ( F_3 ( 7 ) != 0x6d50 )
return 1 ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
V_1 [ V_3 ] = F_4 ( F_3 ( V_3 ) ) ;
#ifdef F_5
if ( ! V_6 ) {
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
struct V_8 * V_9 = F_6 ( V_10 [ V_3 ] ) ;
if ( V_9 -> type == V_11 &&
! memcmp ( V_1 , V_10 [ V_3 ] -> V_12 ,
V_13 ) ) {
if ( V_14 > 3 )
F_7 ( L_1 ,
V_1 [ 0 ] & 0xff , V_1 [ 0 ] >> 8 ,
V_1 [ 1 ] & 0xff , V_1 [ 1 ] >> 8 ,
V_1 [ 2 ] & 0xff , V_1 [ 2 ] >> 8 ) ;
F_2 ( 0xd0 + ++ V_5 , V_4 ) ;
return 2 ;
}
}
}
#endif
return 0 ;
}
static void T_2 F_8 ( struct V_15 * V_16 , T_1 * V_1 ,
int V_17 , int V_18 , int V_19 ,
enum V_20 type )
{
struct V_8 * V_9 = F_6 ( V_16 ) ;
memcpy ( V_16 -> V_12 , V_1 , V_13 ) ;
V_16 -> V_21 = V_17 ;
V_16 -> V_18 = V_18 ;
V_16 -> V_19 = V_19 ;
V_9 -> type = type ;
}
static int T_2 F_9 ( struct V_22 * V_23 ,
unsigned int V_24 )
{
struct V_15 * V_16 ;
int V_17 , V_25 , V_19 , V_26 ;
unsigned int V_27 ;
T_1 V_1 [ 3 ] ;
while ( ( V_26 = F_1 ( V_1 ) ) == 2 )
;
if ( V_26 == 1 )
return 0 ;
V_27 = F_3 ( 8 ) ;
V_19 = V_27 >> 14 ;
V_17 = 0x200 + ( ( V_27 & 0x1f ) << 4 ) ;
if ( V_18 [ V_7 ] > 1 && V_18 [ V_7 ] < 16 )
V_25 = V_18 [ V_7 ] ;
else
V_25 = F_3 ( 9 ) >> 12 ;
V_16 = F_10 ( sizeof( struct V_8 ) ) ;
if ( ! V_16 )
return - V_28 ;
F_11 ( V_16 ) ;
if ( ! F_12 ( V_17 , V_29 , L_2 ) ) {
F_13 ( V_16 ) ;
return 0 ;
}
F_2 ( 0xd0 + ++ V_5 , V_4 ) ;
F_2 ( ( V_17 >> 4 ) | 0xe0 , V_4 ) ;
F_14 ( 0 ) ;
if ( F_15 ( V_17 ) != 0x6d50 ) {
F_13 ( V_16 ) ;
return 0 ;
}
F_16 ( 0x0f00 , V_17 + V_30 ) ;
F_8 ( V_16 , V_1 , V_17 , V_25 , V_19 , V_31 ) ;
F_17 ( V_23 , V_16 ) ;
if ( F_18 ( V_16 ) ) {
F_13 ( V_16 ) ;
return 0 ;
}
V_10 [ V_7 ++ ] = V_16 ;
return 1 ;
}
static int T_3 F_19 ( struct V_22 * V_23 ,
unsigned int V_24 )
{
F_20 ( V_23 ) ;
F_17 ( V_23 , NULL ) ;
return 0 ;
}
static int F_21 ( struct V_22 * V_16 , unsigned int V_32 ,
T_4 V_33 )
{
V_5 = 0 ;
return F_22 ( V_16 , V_33 ) ;
}
static int F_23 ( struct V_22 * V_16 , unsigned int V_32 )
{
struct V_15 * V_24 = F_24 ( V_16 ) ;
int V_17 = V_24 -> V_21 , V_26 ;
T_1 V_1 [ 3 ] ;
while ( ( V_26 = F_1 ( V_1 ) ) == 2 )
;
if ( V_26 == 1 )
return 0 ;
F_2 ( 0xd0 + ++ V_5 , V_4 ) ;
F_2 ( ( V_17 >> 4 ) | 0xe0 , V_4 ) ;
F_14 ( 0 ) ;
if ( F_15 ( V_17 ) != 0x6d50 )
return 1 ;
F_16 ( 0x0f00 , V_17 + V_30 ) ;
return F_25 ( V_16 ) ;
}
static int T_2 F_26 ( struct V_34 * V_23 ,
const struct V_35 * V_36 )
{
short V_3 ;
int V_17 , V_18 , V_19 ;
T_1 V_1 [ 3 ] ;
struct V_15 * V_16 = NULL ;
int V_26 ;
V_17 = F_27 ( V_23 , 0 ) ;
if ( ! F_12 ( V_17 , V_29 , L_3 ) )
return - V_37 ;
V_18 = F_28 ( V_23 , 0 ) ;
F_14 ( 0 ) ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
V_1 [ V_3 ] = F_4 ( F_29 ( V_17 , V_3 ) ) ;
V_19 = F_29 ( V_17 , 8 ) >> 14 ;
V_16 = F_10 ( sizeof( struct V_8 ) ) ;
if ( ! V_16 ) {
F_30 ( V_17 , V_29 ) ;
return - V_28 ;
}
F_31 ( V_16 , & V_23 -> V_16 ) ;
F_11 ( V_16 ) ;
F_8 ( V_16 , V_1 , V_17 , V_18 , V_19 , V_11 ) ;
F_32 ( V_23 , V_16 ) ;
V_26 = F_18 ( V_16 ) ;
if ( V_26 ) {
F_32 ( V_23 , NULL ) ;
F_13 ( V_16 ) ;
return V_26 ;
}
V_10 [ V_7 ++ ] = V_16 ;
return 0 ;
}
static void T_3 F_33 ( struct V_34 * V_23 )
{
F_34 ( F_35 ( V_23 ) ) ;
F_32 ( V_23 , NULL ) ;
}
static int F_36 ( struct V_34 * V_23 , T_4 V_33 )
{
return F_22 ( & V_23 -> V_16 , V_33 ) ;
}
static int F_37 ( struct V_34 * V_23 )
{
return F_25 ( & V_23 -> V_16 ) ;
}
static int T_2 F_18 ( struct V_15 * V_16 )
{
struct V_8 * V_9 = F_6 ( V_16 ) ;
int V_26 ;
const char * V_38 [] = { L_4 , L_5 , L_6 , L_7 } ;
F_38 ( & V_9 -> V_39 ) ;
if ( V_16 -> V_40 & 0x05 ) {
V_16 -> V_19 = ( V_16 -> V_40 & 0x0f ) ;
} else {
V_16 -> V_19 |= ( V_16 -> V_40 & 0x08 ) ;
}
V_16 -> V_41 = & V_41 ;
V_16 -> V_42 = V_43 ;
F_39 ( V_16 , & V_44 ) ;
V_26 = F_40 ( V_16 ) ;
if ( V_26 ) {
F_41 ( L_8 ,
V_16 -> V_21 , V_16 -> V_18 ) ;
F_30 ( V_16 -> V_21 , V_29 ) ;
return V_26 ;
}
F_42 ( L_9 ,
V_16 -> V_45 , V_16 -> V_21 , V_38 [ ( V_16 -> V_19 & 0x03 ) ] ,
V_16 -> V_12 , V_16 -> V_18 ) ;
if ( V_14 > 0 )
F_42 ( L_10 , V_46 ) ;
return 0 ;
}
static void F_34 ( struct V_15 * V_16 )
{
F_43 ( V_16 ) ;
F_30 ( V_16 -> V_21 , V_29 ) ;
F_13 ( V_16 ) ;
}
static int T_5 F_44 ( struct V_22 * V_22 )
{
short V_3 ;
int V_17 , V_18 , V_19 ;
T_1 V_1 [ 3 ] ;
struct V_15 * V_16 = NULL ;
struct V_47 * V_48 ;
int V_26 ;
V_48 = F_45 ( V_22 ) ;
V_17 = V_48 -> V_21 ;
if ( ! F_12 ( V_17 , V_29 , L_11 ) )
return - V_37 ;
F_16 ( V_49 | 0 , V_17 + 0xC80 + V_50 ) ;
V_18 = F_15 ( V_17 + V_30 ) >> 12 ;
V_19 = F_15 ( V_17 + 6 ) >> 14 ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
V_1 [ V_3 ] = F_4 ( F_29 ( V_17 , V_3 ) ) ;
F_29 ( V_17 , 3 ) ;
V_16 = F_10 ( sizeof ( struct V_8 ) ) ;
if ( V_16 == NULL ) {
F_30 ( V_17 , V_29 ) ;
return - V_28 ;
}
F_11 ( V_16 ) ;
F_8 ( V_16 , V_1 , V_17 , V_18 , V_19 , V_51 ) ;
F_46 ( V_48 , V_16 ) ;
V_26 = F_18 ( V_16 ) ;
if ( V_26 ) {
F_46 ( V_48 , NULL ) ;
F_13 ( V_16 ) ;
return V_26 ;
}
V_10 [ V_7 ++ ] = V_16 ;
return 0 ;
}
static int T_3 F_20 ( struct V_22 * V_22 )
{
struct V_15 * V_16 ;
V_16 = F_24 ( V_22 ) ;
F_34 ( V_16 ) ;
return 0 ;
}
static T_6 F_29 ( int V_17 , int V_52 )
{
F_16 ( V_53 + V_52 , V_17 + 10 ) ;
F_47 ( 2 ) ;
return F_15 ( V_17 + 12 ) ;
}
static T_6 F_3 ( int V_52 )
{
int V_54 , V_55 = 0 ;
F_2 ( V_53 + V_52 , V_4 ) ;
F_47 ( 4 ) ;
for ( V_54 = 15 ; V_54 >= 0 ; V_54 -- )
V_55 = ( V_55 << 1 ) + ( F_48 ( V_4 ) & 0x01 ) ;
if ( V_14 > 3 )
F_7 ( L_12 , V_52 , V_55 ) ;
return V_55 ;
}
static int
F_49 ( struct V_15 * V_16 )
{
int V_17 = V_16 -> V_21 ;
int V_3 ;
F_16 ( V_56 , V_17 + V_50 ) ;
F_16 ( V_57 , V_17 + V_50 ) ;
F_16 ( V_58 | 0x00 , V_17 + V_50 ) ;
V_3 = F_50 ( V_16 -> V_18 , V_59 , 0 , V_16 -> V_45 , V_16 ) ;
if ( V_3 )
return V_3 ;
F_14 ( 0 ) ;
if ( V_14 > 3 )
F_7 ( L_13 , V_16 -> V_45 ,
V_16 -> V_18 , V_17 + V_60 , F_15 ( V_17 + V_60 ) ) ;
F_51 ( V_16 ) ;
if ( V_14 > 3 )
F_7 ( L_14 ,
V_16 -> V_45 , V_16 -> V_18 , F_15 ( V_17 + V_60 ) ) ;
return 0 ;
}
static void
F_52 ( struct V_15 * V_16 )
{
int V_17 = V_16 -> V_21 ;
F_53 ( L_15 ,
V_16 -> V_45 , F_48 ( V_17 + V_61 ) , F_15 ( V_17 + V_60 ) ,
F_15 ( V_17 + V_62 ) ) ;
V_16 -> V_63 . V_64 ++ ;
V_16 -> V_65 = V_66 ;
F_16 ( V_56 , V_17 + V_50 ) ;
F_16 ( V_67 , V_17 + V_50 ) ;
F_54 ( V_16 ) ;
}
static T_7
F_55 ( struct V_68 * V_69 , struct V_15 * V_16 )
{
struct V_8 * V_9 = F_6 ( V_16 ) ;
int V_17 = V_16 -> V_21 ;
unsigned long V_70 ;
F_56 ( V_16 ) ;
V_16 -> V_63 . V_71 += V_69 -> V_72 ;
if ( V_14 > 4 ) {
F_7 ( L_16 ,
V_16 -> V_45 , V_69 -> V_72 , F_15 ( V_17 + V_60 ) ) ;
}
#if 0
#ifndef F_57
{
ushort status = inw(ioaddr + EL3_STATUS);
if (status & 0x0001 &&
inw(ioaddr + EL3_STATUS) & 1) {
pr_debug("%s: Missed interrupt, status then %04x now %04x"
" Tx %2.2x Rx %4.4x.\n", dev->name, status,
inw(ioaddr + EL3_STATUS), inb(ioaddr + TX_STATUS),
inw(ioaddr + RX_STATUS));
outw(SetStatusEnb | 0x00, ioaddr + EL3_CMD);
outw(AckIntr | IntLatch | TxAvailable | RxEarly | IntReq,
ioaddr + EL3_CMD);
outw(SetStatusEnb | 0xff, ioaddr + EL3_CMD);
}
}
#endif
#endif
F_58 ( & V_9 -> V_39 , V_70 ) ;
F_16 ( V_69 -> V_72 , V_17 + V_73 ) ;
F_16 ( 0x00 , V_17 + V_73 ) ;
F_59 ( V_17 + V_73 , V_69 -> V_74 , ( V_69 -> V_72 + 3 ) >> 2 ) ;
if ( F_15 ( V_17 + V_62 ) > 1536 )
F_60 ( V_16 ) ;
else
F_16 ( V_75 + 1536 , V_17 + V_50 ) ;
F_61 ( & V_9 -> V_39 , V_70 ) ;
F_62 ( V_69 ) ;
{
short V_76 ;
int V_3 = 4 ;
while ( -- V_3 > 0 && ( V_76 = F_48 ( V_17 + V_61 ) ) > 0 ) {
if ( V_76 & 0x38 ) V_16 -> V_63 . V_77 ++ ;
if ( V_76 & 0x30 ) F_16 ( V_56 , V_17 + V_50 ) ;
if ( V_76 & 0x3C ) F_16 ( V_67 , V_17 + V_50 ) ;
F_2 ( 0x00 , V_17 + V_61 ) ;
}
}
return V_78 ;
}
static T_8
V_59 ( int V_18 , void * V_79 )
{
struct V_15 * V_16 = V_79 ;
struct V_8 * V_9 ;
int V_17 , V_80 ;
int V_3 = V_81 ;
V_9 = F_6 ( V_16 ) ;
F_63 ( & V_9 -> V_39 ) ;
V_17 = V_16 -> V_21 ;
if ( V_14 > 4 ) {
V_80 = F_15 ( V_17 + V_60 ) ;
F_7 ( L_17 , V_16 -> V_45 , V_80 ) ;
}
while ( ( V_80 = F_15 ( V_17 + V_60 ) ) &
( V_82 | V_83 | V_84 ) ) {
if ( V_80 & V_83 )
F_64 ( V_16 ) ;
if ( V_80 & V_85 ) {
if ( V_14 > 5 )
F_7 ( L_18 ) ;
F_16 ( V_86 | V_85 , V_17 + V_50 ) ;
F_54 ( V_16 ) ;
}
if ( V_80 & ( V_87 | V_88 | V_84 | V_89 ) ) {
if ( V_80 & V_84 )
F_65 ( V_16 ) ;
if ( V_80 & V_88 ) {
F_64 ( V_16 ) ;
F_16 ( V_86 | V_88 , V_17 + V_50 ) ;
}
if ( V_80 & V_89 ) {
short V_76 ;
int V_3 = 4 ;
while ( -- V_3 > 0 && ( V_76 = F_48 ( V_17 + V_61 ) ) > 0 ) {
if ( V_76 & 0x38 ) V_16 -> V_63 . V_77 ++ ;
if ( V_76 & 0x30 ) F_16 ( V_56 , V_17 + V_50 ) ;
if ( V_76 & 0x3C ) F_16 ( V_67 , V_17 + V_50 ) ;
F_2 ( 0x00 , V_17 + V_61 ) ;
}
}
if ( V_80 & V_87 ) {
F_16 ( V_57 , V_17 + V_50 ) ;
F_16 ( V_90 | V_91 | V_92
| ( V_16 -> V_70 & V_93 ? V_94 : 0 )
| ( V_16 -> V_70 & V_95 ? V_96 : 0 ) ,
V_17 + V_50 ) ;
F_16 ( V_97 , V_17 + V_50 ) ;
F_16 ( V_86 | V_87 , V_17 + V_50 ) ;
}
}
if ( -- V_3 < 0 ) {
F_41 ( L_19 ,
V_16 -> V_45 , V_80 ) ;
F_16 ( V_86 | 0xFF , V_17 + V_50 ) ;
break;
}
F_16 ( V_86 | V_98 | V_82 , V_17 + V_50 ) ;
}
if ( V_14 > 4 ) {
F_7 ( L_20 , V_16 -> V_45 ,
F_15 ( V_17 + V_60 ) ) ;
}
F_66 ( & V_9 -> V_39 ) ;
return V_99 ;
}
static void F_67 ( struct V_15 * V_16 )
{
F_68 ( V_16 -> V_18 ) ;
V_59 ( V_16 -> V_18 , V_16 ) ;
F_69 ( V_16 -> V_18 ) ;
}
static struct V_100 *
F_70 ( struct V_15 * V_16 )
{
struct V_8 * V_9 = F_6 ( V_16 ) ;
unsigned long V_70 ;
F_58 ( & V_9 -> V_39 , V_70 ) ;
F_65 ( V_16 ) ;
F_61 ( & V_9 -> V_39 , V_70 ) ;
return & V_16 -> V_63 ;
}
static void F_65 ( struct V_15 * V_16 )
{
int V_17 = V_16 -> V_21 ;
if ( V_14 > 5 )
F_7 ( L_21 ) ;
F_16 ( V_101 , V_17 + V_50 ) ;
F_14 ( 6 ) ;
V_16 -> V_63 . V_102 += F_48 ( V_17 + 0 ) ;
V_16 -> V_63 . V_103 += F_48 ( V_17 + 1 ) ;
F_48 ( V_17 + 2 ) ;
V_16 -> V_63 . V_104 += F_48 ( V_17 + 3 ) ;
V_16 -> V_63 . V_105 += F_48 ( V_17 + 4 ) ;
V_16 -> V_63 . V_106 += F_48 ( V_17 + 5 ) ;
V_16 -> V_63 . V_107 += F_48 ( V_17 + 6 ) ;
F_48 ( V_17 + 7 ) ;
F_48 ( V_17 + 8 ) ;
F_15 ( V_17 + 10 ) ;
F_15 ( V_17 + 12 ) ;
F_14 ( 1 ) ;
F_16 ( V_108 , V_17 + V_50 ) ;
}
static int
F_64 ( struct V_15 * V_16 )
{
int V_17 = V_16 -> V_21 ;
short V_109 ;
if ( V_14 > 5 )
F_7 ( L_22 ,
F_15 ( V_17 + V_60 ) , F_15 ( V_17 + V_110 ) ) ;
while ( ( V_109 = F_15 ( V_17 + V_110 ) ) > 0 ) {
if ( V_109 & 0x4000 ) {
short error = V_109 & 0x3800 ;
F_16 ( V_111 , V_17 + V_50 ) ;
V_16 -> V_63 . V_112 ++ ;
switch ( error ) {
case 0x0000 : V_16 -> V_63 . V_113 ++ ; break;
case 0x0800 : V_16 -> V_63 . V_114 ++ ; break;
case 0x1000 : V_16 -> V_63 . V_115 ++ ; break;
case 0x1800 : V_16 -> V_63 . V_114 ++ ; break;
case 0x2000 : V_16 -> V_63 . V_115 ++ ; break;
case 0x2800 : V_16 -> V_63 . V_116 ++ ; break;
}
} else {
short V_117 = V_109 & 0x7ff ;
struct V_68 * V_69 ;
V_69 = F_71 ( V_16 , V_117 + 5 ) ;
if ( V_14 > 4 )
F_7 ( L_23 ,
V_117 , V_109 ) ;
if ( V_69 != NULL ) {
F_72 ( V_69 , 2 ) ;
F_73 ( V_17 + V_118 , F_74 ( V_69 , V_117 ) ,
( V_117 + 3 ) >> 2 ) ;
F_16 ( V_111 , V_17 + V_50 ) ;
V_69 -> V_119 = F_75 ( V_69 , V_16 ) ;
F_76 ( V_69 ) ;
V_16 -> V_63 . V_120 += V_117 ;
V_16 -> V_63 . V_121 ++ ;
continue;
}
F_16 ( V_111 , V_17 + V_50 ) ;
V_16 -> V_63 . V_122 ++ ;
if ( V_14 )
F_7 ( L_24 ,
V_16 -> V_45 , V_117 ) ;
}
F_15 ( V_17 + V_60 ) ;
while ( F_15 ( V_17 + V_60 ) & 0x1000 )
F_7 ( L_25 ,
F_15 ( V_17 + V_60 ) ) ;
}
return 0 ;
}
static void
F_77 ( struct V_15 * V_16 )
{
unsigned long V_70 ;
struct V_8 * V_9 = F_6 ( V_16 ) ;
int V_17 = V_16 -> V_21 ;
int V_123 = F_78 ( V_16 ) ;
if ( V_14 > 1 ) {
static int V_124 ;
if ( V_124 != V_123 ) {
V_124 = V_123 ;
F_7 ( L_26 ,
V_16 -> V_45 , V_123 ) ;
}
}
F_58 ( & V_9 -> V_39 , V_70 ) ;
if ( V_16 -> V_70 & V_95 ) {
F_16 ( V_90 | V_91 | V_94 | V_92 | V_96 ,
V_17 + V_50 ) ;
}
else if ( V_123 || ( V_16 -> V_70 & V_93 ) ) {
F_16 ( V_90 | V_91 | V_94 | V_92 , V_17 + V_50 ) ;
}
else
F_16 ( V_90 | V_91 | V_92 , V_17 + V_50 ) ;
F_61 ( & V_9 -> V_39 , V_70 ) ;
}
static int
F_79 ( struct V_15 * V_16 )
{
int V_17 = V_16 -> V_21 ;
struct V_8 * V_9 = F_6 ( V_16 ) ;
if ( V_14 > 2 )
F_7 ( L_27 , V_16 -> V_45 ) ;
F_80 ( V_16 ) ;
F_81 ( V_16 -> V_18 , V_16 ) ;
F_14 ( 0 ) ;
if ( V_9 -> type != V_51 ) {
F_16 ( 0x0f00 , V_17 + V_30 ) ;
}
return 0 ;
}
static int
F_82 ( struct V_15 * V_16 )
{
int V_17 = V_16 -> V_21 ;
T_9 V_125 ;
F_14 ( 4 ) ;
V_125 = F_15 ( V_17 + V_126 ) ;
F_14 ( 1 ) ;
return V_125 & ( 1 << 11 ) ;
}
static int
F_83 ( struct V_15 * V_16 , struct V_127 * V_128 )
{
T_9 V_125 ;
int V_17 = V_16 -> V_21 ;
F_14 ( 0 ) ;
V_125 = F_15 ( V_17 + V_129 ) ;
V_128 -> V_130 = V_131 ;
switch ( V_125 >> 14 ) {
case 0 :
V_128 -> V_132 = V_133 ;
break;
case 1 :
V_128 -> V_132 = V_134 ;
V_128 -> V_130 = V_135 ;
break;
case 3 :
V_128 -> V_132 = V_136 ;
default:
break;
}
V_128 -> V_137 = V_138 ;
V_128 -> V_139 = 0 ;
V_125 = F_15 ( V_17 + V_140 ) ;
if ( V_125 & ( 1 << 13 ) )
V_128 -> V_139 |= V_141 ;
if ( V_125 & ( 1 << 12 ) )
V_128 -> V_139 |= V_142 ;
if ( V_125 & ( 1 << 9 ) ) {
V_128 -> V_139 |= V_143 | V_144 |
V_145 ;
F_14 ( 4 ) ;
V_125 = F_15 ( V_17 + V_146 ) ;
if ( V_125 & V_147 )
V_128 -> V_137 = V_148 ;
}
F_84 ( V_128 , V_149 ) ;
F_14 ( 1 ) ;
return 0 ;
}
static int
F_85 ( struct V_15 * V_16 , struct V_127 * V_128 )
{
T_9 V_125 ;
int V_17 = V_16 -> V_21 ;
if ( V_128 -> V_150 != V_149 )
return - V_151 ;
if ( ( V_128 -> V_137 != V_138 ) && ( V_128 -> V_137 != V_148 ) )
return - V_151 ;
if ( ( V_128 -> V_130 != V_131 ) && ( V_128 -> V_130 != V_135 ) )
return - V_151 ;
F_14 ( 0 ) ;
V_125 = F_15 ( V_17 + V_129 ) ;
switch ( V_128 -> V_132 ) {
case V_133 :
V_125 &= ~ ( 3 << 14 ) ;
V_16 -> V_19 = 0 ;
break;
case V_134 :
V_125 |= ( 1 << 14 ) ;
V_16 -> V_19 = 1 ;
break;
case V_136 :
V_125 |= ( 3 << 14 ) ;
V_16 -> V_19 = 3 ;
break;
default:
return - V_151 ;
}
F_16 ( V_125 , V_17 + V_129 ) ;
if ( V_16 -> V_19 == 3 ) {
V_125 = F_15 ( V_17 + V_129 ) ;
if ( V_125 & ( 3 << 14 ) ) {
F_16 ( V_152 , V_17 + V_50 ) ;
F_86 ( 800 ) ;
} else
return - V_153 ;
}
F_14 ( 4 ) ;
V_125 = F_15 ( V_17 + V_146 ) ;
if ( V_128 -> V_137 == V_148 )
V_125 |= V_147 ;
else
V_125 &= ~ V_147 ;
F_16 ( V_125 , V_17 + V_146 ) ;
F_14 ( 1 ) ;
return 0 ;
}
static void F_87 ( struct V_15 * V_16 , struct V_154 * V_155 )
{
strcpy ( V_155 -> V_156 , V_157 ) ;
strcpy ( V_155 -> V_46 , V_158 ) ;
}
static int F_88 ( struct V_15 * V_16 , struct V_127 * V_128 )
{
struct V_8 * V_9 = F_6 ( V_16 ) ;
int V_159 ;
F_89 ( & V_9 -> V_39 ) ;
V_159 = F_83 ( V_16 , V_128 ) ;
F_90 ( & V_9 -> V_39 ) ;
return V_159 ;
}
static int F_91 ( struct V_15 * V_16 , struct V_127 * V_128 )
{
struct V_8 * V_9 = F_6 ( V_16 ) ;
int V_159 ;
F_89 ( & V_9 -> V_39 ) ;
V_159 = F_85 ( V_16 , V_128 ) ;
F_90 ( & V_9 -> V_39 ) ;
return V_159 ;
}
static T_10 F_92 ( struct V_15 * V_16 )
{
struct V_8 * V_9 = F_6 ( V_16 ) ;
T_10 V_159 ;
F_89 ( & V_9 -> V_39 ) ;
V_159 = F_82 ( V_16 ) ;
F_90 ( & V_9 -> V_39 ) ;
return V_159 ;
}
static T_10 F_93 ( struct V_15 * V_16 )
{
return V_14 ;
}
static void F_94 ( struct V_15 * V_16 , T_10 V_160 )
{
V_14 = V_160 ;
}
static void
F_80 ( struct V_15 * V_16 )
{
int V_17 = V_16 -> V_21 ;
F_56 ( V_16 ) ;
F_16 ( V_101 , V_17 + V_50 ) ;
F_16 ( V_161 , V_17 + V_50 ) ;
F_16 ( V_162 , V_17 + V_50 ) ;
if ( V_16 -> V_19 == 3 )
F_16 ( V_163 , V_17 + V_50 ) ;
else if ( V_16 -> V_19 == 0 ) {
F_14 ( 4 ) ;
F_16 ( F_15 ( V_17 + V_126 ) & ~ V_164 , V_17 + V_126 ) ;
}
F_16 ( V_165 | 0x0000 , V_17 + V_50 ) ;
F_65 ( V_16 ) ;
}
static void
F_51 ( struct V_15 * V_16 )
{
int V_3 , V_166 , V_167 ;
int V_17 = V_16 -> V_21 ;
F_16 ( 0x0001 , V_17 + 4 ) ;
F_16 ( ( V_16 -> V_18 << 12 ) | 0x0f00 , V_17 + V_30 ) ;
F_14 ( 2 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_2 ( V_16 -> V_12 [ V_3 ] , V_17 + V_3 ) ;
if ( ( V_16 -> V_19 & 0x03 ) == 3 )
F_16 ( V_152 , V_17 + V_50 ) ;
else if ( ( V_16 -> V_19 & 0x03 ) == 0 ) {
F_14 ( 0 ) ;
V_166 = ( F_29 ( V_17 , 0x14 ) & 0x400f ) |
( F_29 ( V_17 , 0x0d ) & 0xBff0 ) ;
F_14 ( 4 ) ;
V_167 = F_15 ( V_17 + V_146 ) ;
V_167 = ( V_167 | V_147 ) ;
F_42 ( L_28 , V_16 -> V_45 ) ;
switch ( V_16 -> V_19 & 0x0c ) {
case 12 :
if ( V_166 & 0x000f ) {
F_95 ( L_29 ) ;
break;
}
case 8 :
if ( ( V_166 & 0x000f ) && ( V_166 & 0x8000 ) ) {
F_95 ( L_30 ) ;
break;
}
default:
F_95 ( L_31 ) ;
V_167 = ( V_167 & ~ V_147 ) ;
}
F_16 ( V_167 , V_17 + V_146 ) ;
F_95 ( L_32 , V_16 -> V_19 , V_166 ) ;
if ( V_14 > 3 )
F_7 ( L_33 , V_16 -> V_45 , V_167 ) ;
F_16 ( F_15 ( V_17 + V_126 ) | V_164 , V_17 + V_126 ) ;
}
F_16 ( V_101 , V_17 + V_50 ) ;
F_14 ( 6 ) ;
for ( V_3 = 0 ; V_3 < 9 ; V_3 ++ )
F_48 ( V_17 + V_3 ) ;
F_15 ( V_17 + 10 ) ;
F_15 ( V_17 + 12 ) ;
F_14 ( 1 ) ;
F_16 ( V_90 | V_91 | V_92 , V_17 + V_50 ) ;
F_16 ( V_108 , V_17 + V_50 ) ;
F_16 ( V_97 , V_17 + V_50 ) ;
F_16 ( V_67 , V_17 + V_50 ) ;
F_16 ( V_58 | 0xff , V_17 + V_50 ) ;
F_16 ( V_86 | V_82 | V_85 | V_88 | V_98 ,
V_17 + V_50 ) ;
F_16 ( V_165 | V_82 | V_85 | V_89 | V_83 | V_84 ,
V_17 + V_50 ) ;
F_60 ( V_16 ) ;
}
static int
F_22 ( struct V_22 * V_23 , T_4 V_33 )
{
unsigned long V_70 ;
struct V_15 * V_16 ;
struct V_8 * V_9 ;
int V_17 ;
V_16 = F_24 ( V_23 ) ;
V_9 = F_6 ( V_16 ) ;
V_17 = V_16 -> V_21 ;
F_58 ( & V_9 -> V_39 , V_70 ) ;
if ( F_96 ( V_16 ) )
F_97 ( V_16 ) ;
F_80 ( V_16 ) ;
F_16 ( V_168 , V_17 + V_50 ) ;
F_61 ( & V_9 -> V_39 , V_70 ) ;
return 0 ;
}
static int
F_25 ( struct V_22 * V_23 )
{
unsigned long V_70 ;
struct V_15 * V_16 ;
struct V_8 * V_9 ;
int V_17 ;
V_16 = F_24 ( V_23 ) ;
V_9 = F_6 ( V_16 ) ;
V_17 = V_16 -> V_21 ;
F_58 ( & V_9 -> V_39 , V_70 ) ;
F_16 ( V_169 , V_17 + V_50 ) ;
F_14 ( 0 ) ;
F_51 ( V_16 ) ;
if ( F_96 ( V_16 ) )
F_98 ( V_16 ) ;
F_61 ( & V_9 -> V_39 , V_70 ) ;
return 0 ;
}
static int T_5 F_99 ( void )
{
int V_159 = 0 ;
if ( V_170 >= 0 )
V_14 = V_170 ;
#ifdef F_5
if ( ! V_6 ) {
V_159 = F_100 ( & V_171 ) ;
if ( ! V_159 )
V_172 = 1 ;
}
#endif
for ( V_4 = 0x110 ; V_4 < 0x200 ; V_4 += 0x10 ) {
if ( ! F_12 ( V_4 , 1 , L_34 ) )
continue;
F_2 ( 0x00 , V_4 ) ;
F_2 ( 0xff , V_4 ) ;
if ( F_48 ( V_4 ) & 0x01 )
break;
else
F_30 ( V_4 , 1 ) ;
}
if ( V_4 >= 0x200 ) {
V_4 = 0 ;
F_41 ( L_35 ) ;
} else {
V_159 = F_101 ( & V_173 , V_174 ) ;
if ( ! V_159 )
V_175 = 1 ;
}
#ifdef F_102
V_159 = F_103 ( & V_176 ) ;
if ( ! V_159 )
V_177 = 1 ;
#endif
#ifdef F_5
if ( V_172 )
V_159 = 0 ;
#endif
if ( V_175 )
V_159 = 0 ;
#ifdef F_102
if ( V_177 )
V_159 = 0 ;
#endif
return V_159 ;
}
static void T_11 F_104 ( void )
{
#ifdef F_5
if ( V_172 )
F_105 ( & V_171 ) ;
#endif
if ( V_175 )
F_106 ( & V_173 ) ;
if ( V_4 )
F_30 ( V_4 , 1 ) ;
#ifdef F_102
if ( V_177 )
F_107 ( & V_176 ) ;
#endif
}
