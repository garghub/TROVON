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
T_6 V_47 , V_48 ;
struct V_49 * V_50 = F_45 ( V_22 ) ;
int V_51 = V_50 -> V_51 ;
int V_26 ;
V_47 = F_46 ( V_50 , 4 ) ;
V_48 = F_46 ( V_50 , 5 ) ;
V_17 = ( ( short ) ( ( V_47 & 0xfc ) | 0x02 ) ) << 8 ;
V_18 = V_48 & 0x0f ;
F_42 ( L_11 ,
V_52 [ V_50 -> V_53 ] , V_51 + 1 ) ;
strncpy ( V_50 -> V_45 , V_52 [ V_50 -> V_53 ] ,
sizeof( V_50 -> V_45 ) ) ;
F_47 ( V_50 , 1 ) ;
V_19 = V_47 & 0x03 ;
V_18 = F_48 ( V_50 , V_18 ) ;
V_17 = F_49 ( V_50 , V_17 ) ;
if ( V_14 > 2 ) {
F_7 ( L_12 , V_18 , V_17 , V_19 ) ;
}
F_14 ( 0 ) ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
V_1 [ V_3 ] = F_4 ( F_29 ( V_17 , V_3 ) ) ;
V_16 = F_10 ( sizeof ( struct V_8 ) ) ;
if ( V_16 == NULL ) {
F_30 ( V_17 , V_29 ) ;
return - V_28 ;
}
F_11 ( V_16 ) ;
F_8 ( V_16 , V_1 , V_17 , V_18 , V_19 , V_54 ) ;
F_17 ( V_22 , V_16 ) ;
V_26 = F_18 ( V_16 ) ;
if ( V_26 ) {
F_17 ( V_22 , NULL ) ;
F_13 ( V_16 ) ;
return - V_28 ;
}
V_10 [ V_7 ++ ] = V_16 ;
return 0 ;
}
static int T_5 F_50 ( struct V_22 * V_22 )
{
short V_3 ;
int V_17 , V_18 , V_19 ;
T_1 V_1 [ 3 ] ;
struct V_15 * V_16 = NULL ;
struct V_55 * V_56 ;
int V_26 ;
V_56 = F_51 ( V_22 ) ;
V_17 = V_56 -> V_21 ;
if ( ! F_12 ( V_17 , V_29 , L_13 ) )
return - V_37 ;
F_16 ( V_57 | 0 , V_17 + 0xC80 + V_58 ) ;
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
F_8 ( V_16 , V_1 , V_17 , V_18 , V_19 , V_59 ) ;
F_52 ( V_56 , V_16 ) ;
V_26 = F_18 ( V_16 ) ;
if ( V_26 ) {
F_52 ( V_56 , NULL ) ;
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
static T_7 F_29 ( int V_17 , int V_53 )
{
F_16 ( V_60 + V_53 , V_17 + 10 ) ;
F_53 ( 2 ) ;
return F_15 ( V_17 + 12 ) ;
}
static T_7 F_3 ( int V_53 )
{
int V_61 , V_62 = 0 ;
F_2 ( V_60 + V_53 , V_4 ) ;
F_53 ( 4 ) ;
for ( V_61 = 15 ; V_61 >= 0 ; V_61 -- )
V_62 = ( V_62 << 1 ) + ( F_54 ( V_4 ) & 0x01 ) ;
if ( V_14 > 3 )
F_7 ( L_14 , V_53 , V_62 ) ;
return V_62 ;
}
static int
F_55 ( struct V_15 * V_16 )
{
int V_17 = V_16 -> V_21 ;
int V_3 ;
F_16 ( V_63 , V_17 + V_58 ) ;
F_16 ( V_64 , V_17 + V_58 ) ;
F_16 ( V_65 | 0x00 , V_17 + V_58 ) ;
V_3 = F_56 ( V_16 -> V_18 , V_66 , 0 , V_16 -> V_45 , V_16 ) ;
if ( V_3 )
return V_3 ;
F_14 ( 0 ) ;
if ( V_14 > 3 )
F_7 ( L_15 , V_16 -> V_45 ,
V_16 -> V_18 , V_17 + V_67 , F_15 ( V_17 + V_67 ) ) ;
F_57 ( V_16 ) ;
if ( V_14 > 3 )
F_7 ( L_16 ,
V_16 -> V_45 , V_16 -> V_18 , F_15 ( V_17 + V_67 ) ) ;
return 0 ;
}
static void
F_58 ( struct V_15 * V_16 )
{
int V_17 = V_16 -> V_21 ;
F_59 ( L_17 ,
V_16 -> V_45 , F_54 ( V_17 + V_68 ) , F_15 ( V_17 + V_67 ) ,
F_15 ( V_17 + V_69 ) ) ;
V_16 -> V_70 . V_71 ++ ;
V_16 -> V_72 = V_73 ;
F_16 ( V_63 , V_17 + V_58 ) ;
F_16 ( V_74 , V_17 + V_58 ) ;
F_60 ( V_16 ) ;
}
static T_8
F_61 ( struct V_75 * V_76 , struct V_15 * V_16 )
{
struct V_8 * V_9 = F_6 ( V_16 ) ;
int V_17 = V_16 -> V_21 ;
unsigned long V_77 ;
F_62 ( V_16 ) ;
V_16 -> V_70 . V_78 += V_76 -> V_79 ;
if ( V_14 > 4 ) {
F_7 ( L_18 ,
V_16 -> V_45 , V_76 -> V_79 , F_15 ( V_17 + V_67 ) ) ;
}
#if 0
#ifndef F_63
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
F_64 ( & V_9 -> V_39 , V_77 ) ;
F_16 ( V_76 -> V_79 , V_17 + V_80 ) ;
F_16 ( 0x00 , V_17 + V_80 ) ;
F_65 ( V_17 + V_80 , V_76 -> V_81 , ( V_76 -> V_79 + 3 ) >> 2 ) ;
if ( F_15 ( V_17 + V_69 ) > 1536 )
F_66 ( V_16 ) ;
else
F_16 ( V_82 + 1536 , V_17 + V_58 ) ;
F_67 ( & V_9 -> V_39 , V_77 ) ;
F_68 ( V_76 ) ;
{
short V_83 ;
int V_3 = 4 ;
while ( -- V_3 > 0 && ( V_83 = F_54 ( V_17 + V_68 ) ) > 0 ) {
if ( V_83 & 0x38 ) V_16 -> V_70 . V_84 ++ ;
if ( V_83 & 0x30 ) F_16 ( V_63 , V_17 + V_58 ) ;
if ( V_83 & 0x3C ) F_16 ( V_74 , V_17 + V_58 ) ;
F_2 ( 0x00 , V_17 + V_68 ) ;
}
}
return V_85 ;
}
static T_9
V_66 ( int V_18 , void * V_86 )
{
struct V_15 * V_16 = V_86 ;
struct V_8 * V_9 ;
int V_17 , V_87 ;
int V_3 = V_88 ;
V_9 = F_6 ( V_16 ) ;
F_69 ( & V_9 -> V_39 ) ;
V_17 = V_16 -> V_21 ;
if ( V_14 > 4 ) {
V_87 = F_15 ( V_17 + V_67 ) ;
F_7 ( L_19 , V_16 -> V_45 , V_87 ) ;
}
while ( ( V_87 = F_15 ( V_17 + V_67 ) ) &
( V_89 | V_90 | V_91 ) ) {
if ( V_87 & V_90 )
F_70 ( V_16 ) ;
if ( V_87 & V_92 ) {
if ( V_14 > 5 )
F_7 ( L_20 ) ;
F_16 ( V_93 | V_92 , V_17 + V_58 ) ;
F_60 ( V_16 ) ;
}
if ( V_87 & ( V_94 | V_95 | V_91 | V_96 ) ) {
if ( V_87 & V_91 )
F_71 ( V_16 ) ;
if ( V_87 & V_95 ) {
F_70 ( V_16 ) ;
F_16 ( V_93 | V_95 , V_17 + V_58 ) ;
}
if ( V_87 & V_96 ) {
short V_83 ;
int V_3 = 4 ;
while ( -- V_3 > 0 && ( V_83 = F_54 ( V_17 + V_68 ) ) > 0 ) {
if ( V_83 & 0x38 ) V_16 -> V_70 . V_84 ++ ;
if ( V_83 & 0x30 ) F_16 ( V_63 , V_17 + V_58 ) ;
if ( V_83 & 0x3C ) F_16 ( V_74 , V_17 + V_58 ) ;
F_2 ( 0x00 , V_17 + V_68 ) ;
}
}
if ( V_87 & V_94 ) {
F_16 ( V_64 , V_17 + V_58 ) ;
F_16 ( V_97 | V_98 | V_99
| ( V_16 -> V_77 & V_100 ? V_101 : 0 )
| ( V_16 -> V_77 & V_102 ? V_103 : 0 ) ,
V_17 + V_58 ) ;
F_16 ( V_104 , V_17 + V_58 ) ;
F_16 ( V_93 | V_94 , V_17 + V_58 ) ;
}
}
if ( -- V_3 < 0 ) {
F_41 ( L_21 ,
V_16 -> V_45 , V_87 ) ;
F_16 ( V_93 | 0xFF , V_17 + V_58 ) ;
break;
}
F_16 ( V_93 | V_105 | V_89 , V_17 + V_58 ) ;
}
if ( V_14 > 4 ) {
F_7 ( L_22 , V_16 -> V_45 ,
F_15 ( V_17 + V_67 ) ) ;
}
F_72 ( & V_9 -> V_39 ) ;
return V_106 ;
}
static void F_73 ( struct V_15 * V_16 )
{
F_74 ( V_16 -> V_18 ) ;
V_66 ( V_16 -> V_18 , V_16 ) ;
F_75 ( V_16 -> V_18 ) ;
}
static struct V_107 *
F_76 ( struct V_15 * V_16 )
{
struct V_8 * V_9 = F_6 ( V_16 ) ;
unsigned long V_77 ;
F_64 ( & V_9 -> V_39 , V_77 ) ;
F_71 ( V_16 ) ;
F_67 ( & V_9 -> V_39 , V_77 ) ;
return & V_16 -> V_70 ;
}
static void F_71 ( struct V_15 * V_16 )
{
int V_17 = V_16 -> V_21 ;
if ( V_14 > 5 )
F_7 ( L_23 ) ;
F_16 ( V_108 , V_17 + V_58 ) ;
F_14 ( 6 ) ;
V_16 -> V_70 . V_109 += F_54 ( V_17 + 0 ) ;
V_16 -> V_70 . V_110 += F_54 ( V_17 + 1 ) ;
F_54 ( V_17 + 2 ) ;
V_16 -> V_70 . V_111 += F_54 ( V_17 + 3 ) ;
V_16 -> V_70 . V_112 += F_54 ( V_17 + 4 ) ;
V_16 -> V_70 . V_113 += F_54 ( V_17 + 5 ) ;
V_16 -> V_70 . V_114 += F_54 ( V_17 + 6 ) ;
F_54 ( V_17 + 7 ) ;
F_54 ( V_17 + 8 ) ;
F_15 ( V_17 + 10 ) ;
F_15 ( V_17 + 12 ) ;
F_14 ( 1 ) ;
F_16 ( V_115 , V_17 + V_58 ) ;
}
static int
F_70 ( struct V_15 * V_16 )
{
int V_17 = V_16 -> V_21 ;
short V_116 ;
if ( V_14 > 5 )
F_7 ( L_24 ,
F_15 ( V_17 + V_67 ) , F_15 ( V_17 + V_117 ) ) ;
while ( ( V_116 = F_15 ( V_17 + V_117 ) ) > 0 ) {
if ( V_116 & 0x4000 ) {
short error = V_116 & 0x3800 ;
F_16 ( V_118 , V_17 + V_58 ) ;
V_16 -> V_70 . V_119 ++ ;
switch ( error ) {
case 0x0000 : V_16 -> V_70 . V_120 ++ ; break;
case 0x0800 : V_16 -> V_70 . V_121 ++ ; break;
case 0x1000 : V_16 -> V_70 . V_122 ++ ; break;
case 0x1800 : V_16 -> V_70 . V_121 ++ ; break;
case 0x2000 : V_16 -> V_70 . V_122 ++ ; break;
case 0x2800 : V_16 -> V_70 . V_123 ++ ; break;
}
} else {
short V_124 = V_116 & 0x7ff ;
struct V_75 * V_76 ;
V_76 = F_77 ( V_124 + 5 ) ;
if ( V_14 > 4 )
F_7 ( L_25 ,
V_124 , V_116 ) ;
if ( V_76 != NULL ) {
F_78 ( V_76 , 2 ) ;
F_79 ( V_17 + V_125 , F_80 ( V_76 , V_124 ) ,
( V_124 + 3 ) >> 2 ) ;
F_16 ( V_118 , V_17 + V_58 ) ;
V_76 -> V_126 = F_81 ( V_76 , V_16 ) ;
F_82 ( V_76 ) ;
V_16 -> V_70 . V_127 += V_124 ;
V_16 -> V_70 . V_128 ++ ;
continue;
}
F_16 ( V_118 , V_17 + V_58 ) ;
V_16 -> V_70 . V_129 ++ ;
if ( V_14 )
F_7 ( L_26 ,
V_16 -> V_45 , V_124 ) ;
}
F_15 ( V_17 + V_67 ) ;
while ( F_15 ( V_17 + V_67 ) & 0x1000 )
F_7 ( L_27 ,
F_15 ( V_17 + V_67 ) ) ;
}
return 0 ;
}
static void
F_83 ( struct V_15 * V_16 )
{
unsigned long V_77 ;
struct V_8 * V_9 = F_6 ( V_16 ) ;
int V_17 = V_16 -> V_21 ;
int V_130 = F_84 ( V_16 ) ;
if ( V_14 > 1 ) {
static int V_131 ;
if ( V_131 != V_130 ) {
V_131 = V_130 ;
F_7 ( L_28 ,
V_16 -> V_45 , V_130 ) ;
}
}
F_64 ( & V_9 -> V_39 , V_77 ) ;
if ( V_16 -> V_77 & V_102 ) {
F_16 ( V_97 | V_98 | V_101 | V_99 | V_103 ,
V_17 + V_58 ) ;
}
else if ( V_130 || ( V_16 -> V_77 & V_100 ) ) {
F_16 ( V_97 | V_98 | V_101 | V_99 , V_17 + V_58 ) ;
}
else
F_16 ( V_97 | V_98 | V_99 , V_17 + V_58 ) ;
F_67 ( & V_9 -> V_39 , V_77 ) ;
}
static int
F_85 ( struct V_15 * V_16 )
{
int V_17 = V_16 -> V_21 ;
struct V_8 * V_9 = F_6 ( V_16 ) ;
if ( V_14 > 2 )
F_7 ( L_29 , V_16 -> V_45 ) ;
F_86 ( V_16 ) ;
F_87 ( V_16 -> V_18 , V_16 ) ;
F_14 ( 0 ) ;
if ( V_9 -> type != V_59 ) {
F_16 ( 0x0f00 , V_17 + V_30 ) ;
}
return 0 ;
}
static int
F_88 ( struct V_15 * V_16 )
{
int V_17 = V_16 -> V_21 ;
T_10 V_132 ;
F_14 ( 4 ) ;
V_132 = F_15 ( V_17 + V_133 ) ;
F_14 ( 1 ) ;
return V_132 & ( 1 << 11 ) ;
}
static int
F_89 ( struct V_15 * V_16 , struct V_134 * V_135 )
{
T_10 V_132 ;
int V_17 = V_16 -> V_21 ;
F_14 ( 0 ) ;
V_132 = F_15 ( V_17 + V_136 ) ;
V_135 -> V_137 = V_138 ;
switch ( V_132 >> 14 ) {
case 0 :
V_135 -> V_139 = V_140 ;
break;
case 1 :
V_135 -> V_139 = V_141 ;
V_135 -> V_137 = V_142 ;
break;
case 3 :
V_135 -> V_139 = V_143 ;
default:
break;
}
V_135 -> V_144 = V_145 ;
V_135 -> V_146 = 0 ;
V_132 = F_15 ( V_17 + V_147 ) ;
if ( V_132 & ( 1 << 13 ) )
V_135 -> V_146 |= V_148 ;
if ( V_132 & ( 1 << 12 ) )
V_135 -> V_146 |= V_149 ;
if ( V_132 & ( 1 << 9 ) ) {
V_135 -> V_146 |= V_150 | V_151 |
V_152 ;
F_14 ( 4 ) ;
V_132 = F_15 ( V_17 + V_153 ) ;
if ( V_132 & V_154 )
V_135 -> V_144 = V_155 ;
}
F_90 ( V_135 , V_156 ) ;
F_14 ( 1 ) ;
return 0 ;
}
static int
F_91 ( struct V_15 * V_16 , struct V_134 * V_135 )
{
T_10 V_132 ;
int V_17 = V_16 -> V_21 ;
if ( V_135 -> V_157 != V_156 )
return - V_158 ;
if ( ( V_135 -> V_144 != V_145 ) && ( V_135 -> V_144 != V_155 ) )
return - V_158 ;
if ( ( V_135 -> V_137 != V_138 ) && ( V_135 -> V_137 != V_142 ) )
return - V_158 ;
F_14 ( 0 ) ;
V_132 = F_15 ( V_17 + V_136 ) ;
switch ( V_135 -> V_139 ) {
case V_140 :
V_132 &= ~ ( 3 << 14 ) ;
V_16 -> V_19 = 0 ;
break;
case V_141 :
V_132 |= ( 1 << 14 ) ;
V_16 -> V_19 = 1 ;
break;
case V_143 :
V_132 |= ( 3 << 14 ) ;
V_16 -> V_19 = 3 ;
break;
default:
return - V_158 ;
}
F_16 ( V_132 , V_17 + V_136 ) ;
if ( V_16 -> V_19 == 3 ) {
V_132 = F_15 ( V_17 + V_136 ) ;
if ( V_132 & ( 3 << 14 ) ) {
F_16 ( V_159 , V_17 + V_58 ) ;
F_92 ( 800 ) ;
} else
return - V_160 ;
}
F_14 ( 4 ) ;
V_132 = F_15 ( V_17 + V_153 ) ;
if ( V_135 -> V_144 == V_155 )
V_132 |= V_154 ;
else
V_132 &= ~ V_154 ;
F_16 ( V_132 , V_17 + V_153 ) ;
F_14 ( 1 ) ;
return 0 ;
}
static void F_93 ( struct V_15 * V_16 , struct V_161 * V_162 )
{
strcpy ( V_162 -> V_163 , V_164 ) ;
strcpy ( V_162 -> V_46 , V_165 ) ;
}
static int F_94 ( struct V_15 * V_16 , struct V_134 * V_135 )
{
struct V_8 * V_9 = F_6 ( V_16 ) ;
int V_166 ;
F_95 ( & V_9 -> V_39 ) ;
V_166 = F_89 ( V_16 , V_135 ) ;
F_96 ( & V_9 -> V_39 ) ;
return V_166 ;
}
static int F_97 ( struct V_15 * V_16 , struct V_134 * V_135 )
{
struct V_8 * V_9 = F_6 ( V_16 ) ;
int V_166 ;
F_95 ( & V_9 -> V_39 ) ;
V_166 = F_91 ( V_16 , V_135 ) ;
F_96 ( & V_9 -> V_39 ) ;
return V_166 ;
}
static T_11 F_98 ( struct V_15 * V_16 )
{
struct V_8 * V_9 = F_6 ( V_16 ) ;
T_11 V_166 ;
F_95 ( & V_9 -> V_39 ) ;
V_166 = F_88 ( V_16 ) ;
F_96 ( & V_9 -> V_39 ) ;
return V_166 ;
}
static T_11 F_99 ( struct V_15 * V_16 )
{
return V_14 ;
}
static void F_100 ( struct V_15 * V_16 , T_11 V_167 )
{
V_14 = V_167 ;
}
static void
F_86 ( struct V_15 * V_16 )
{
int V_17 = V_16 -> V_21 ;
F_62 ( V_16 ) ;
F_16 ( V_108 , V_17 + V_58 ) ;
F_16 ( V_168 , V_17 + V_58 ) ;
F_16 ( V_169 , V_17 + V_58 ) ;
if ( V_16 -> V_19 == 3 )
F_16 ( V_170 , V_17 + V_58 ) ;
else if ( V_16 -> V_19 == 0 ) {
F_14 ( 4 ) ;
F_16 ( F_15 ( V_17 + V_133 ) & ~ V_171 , V_17 + V_133 ) ;
}
F_16 ( V_172 | 0x0000 , V_17 + V_58 ) ;
F_71 ( V_16 ) ;
}
static void
F_57 ( struct V_15 * V_16 )
{
int V_3 , V_173 , V_174 ;
int V_17 = V_16 -> V_21 ;
F_16 ( 0x0001 , V_17 + 4 ) ;
F_16 ( ( V_16 -> V_18 << 12 ) | 0x0f00 , V_17 + V_30 ) ;
F_14 ( 2 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_2 ( V_16 -> V_12 [ V_3 ] , V_17 + V_3 ) ;
if ( ( V_16 -> V_19 & 0x03 ) == 3 )
F_16 ( V_159 , V_17 + V_58 ) ;
else if ( ( V_16 -> V_19 & 0x03 ) == 0 ) {
F_14 ( 0 ) ;
V_173 = ( F_29 ( V_17 , 0x14 ) & 0x400f ) |
( F_29 ( V_17 , 0x0d ) & 0xBff0 ) ;
F_14 ( 4 ) ;
V_174 = F_15 ( V_17 + V_153 ) ;
V_174 = ( V_174 | V_154 ) ;
F_42 ( L_30 , V_16 -> V_45 ) ;
switch ( V_16 -> V_19 & 0x0c ) {
case 12 :
if ( V_173 & 0x000f ) {
F_101 ( L_31 ) ;
break;
}
case 8 :
if ( ( V_173 & 0x000f ) && ( V_173 & 0x8000 ) ) {
F_101 ( L_32 ) ;
break;
}
default:
F_101 ( L_33 ) ;
V_174 = ( V_174 & ~ V_154 ) ;
}
F_16 ( V_174 , V_17 + V_153 ) ;
F_101 ( L_34 , V_16 -> V_19 , V_173 ) ;
if ( V_14 > 3 )
F_7 ( L_35 , V_16 -> V_45 , V_174 ) ;
F_16 ( F_15 ( V_17 + V_133 ) | V_171 , V_17 + V_133 ) ;
}
F_16 ( V_108 , V_17 + V_58 ) ;
F_14 ( 6 ) ;
for ( V_3 = 0 ; V_3 < 9 ; V_3 ++ )
F_54 ( V_17 + V_3 ) ;
F_15 ( V_17 + 10 ) ;
F_15 ( V_17 + 12 ) ;
F_14 ( 1 ) ;
F_16 ( V_97 | V_98 | V_99 , V_17 + V_58 ) ;
F_16 ( V_115 , V_17 + V_58 ) ;
F_16 ( V_104 , V_17 + V_58 ) ;
F_16 ( V_74 , V_17 + V_58 ) ;
F_16 ( V_65 | 0xff , V_17 + V_58 ) ;
F_16 ( V_93 | V_89 | V_92 | V_95 | V_105 ,
V_17 + V_58 ) ;
F_16 ( V_172 | V_89 | V_92 | V_96 | V_90 | V_91 ,
V_17 + V_58 ) ;
F_66 ( V_16 ) ;
}
static int
F_22 ( struct V_22 * V_23 , T_4 V_33 )
{
unsigned long V_77 ;
struct V_15 * V_16 ;
struct V_8 * V_9 ;
int V_17 ;
V_16 = F_24 ( V_23 ) ;
V_9 = F_6 ( V_16 ) ;
V_17 = V_16 -> V_21 ;
F_64 ( & V_9 -> V_39 , V_77 ) ;
if ( F_102 ( V_16 ) )
F_103 ( V_16 ) ;
F_86 ( V_16 ) ;
F_16 ( V_175 , V_17 + V_58 ) ;
F_67 ( & V_9 -> V_39 , V_77 ) ;
return 0 ;
}
static int
F_25 ( struct V_22 * V_23 )
{
unsigned long V_77 ;
struct V_15 * V_16 ;
struct V_8 * V_9 ;
int V_17 ;
V_16 = F_24 ( V_23 ) ;
V_9 = F_6 ( V_16 ) ;
V_17 = V_16 -> V_21 ;
F_64 ( & V_9 -> V_39 , V_77 ) ;
F_16 ( V_176 , V_17 + V_58 ) ;
F_14 ( 0 ) ;
F_57 ( V_16 ) ;
if ( F_102 ( V_16 ) )
F_104 ( V_16 ) ;
F_67 ( & V_9 -> V_39 , V_77 ) ;
return 0 ;
}
static int T_5 F_105 ( void )
{
int V_166 = 0 ;
if ( V_177 >= 0 )
V_14 = V_177 ;
#ifdef F_5
if ( ! V_6 ) {
V_166 = F_106 ( & V_178 ) ;
if ( ! V_166 )
V_179 = 1 ;
}
#endif
for ( V_4 = 0x110 ; V_4 < 0x200 ; V_4 += 0x10 ) {
if ( ! F_12 ( V_4 , 1 , L_36 ) )
continue;
F_2 ( 0x00 , V_4 ) ;
F_2 ( 0xff , V_4 ) ;
if ( F_54 ( V_4 ) & 0x01 )
break;
else
F_30 ( V_4 , 1 ) ;
}
if ( V_4 >= 0x200 ) {
V_4 = 0 ;
F_41 ( L_37 ) ;
} else {
V_166 = F_107 ( & V_180 , V_181 ) ;
if ( ! V_166 )
V_182 = 1 ;
}
#ifdef F_108
V_166 = F_109 ( & V_183 ) ;
if ( ! V_166 )
V_184 = 1 ;
#endif
#ifdef F_110
V_166 = F_111 ( & V_185 ) ;
if ( ! V_166 )
V_186 = 1 ;
#endif
#ifdef F_5
if ( V_179 )
V_166 = 0 ;
#endif
if ( V_182 )
V_166 = 0 ;
#ifdef F_108
if ( V_184 )
V_166 = 0 ;
#endif
#ifdef F_110
if ( V_186 )
V_166 = 0 ;
#endif
return V_166 ;
}
static void T_12 F_112 ( void )
{
#ifdef F_5
if ( V_179 )
F_113 ( & V_178 ) ;
#endif
if ( V_182 )
F_114 ( & V_180 ) ;
if ( V_4 )
F_30 ( V_4 , 1 ) ;
#ifdef F_108
if ( V_184 )
F_115 ( & V_183 ) ;
#endif
#ifdef F_110
if ( V_186 )
F_116 ( & V_185 ) ;
#endif
}
