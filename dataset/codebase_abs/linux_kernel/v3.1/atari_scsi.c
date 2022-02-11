static inline void F_1 ( unsigned long V_1 )
{
V_2 . V_3 = ( unsigned char ) V_1 ;
F_2 () ;
V_1 >>= 8 ;
V_2 . V_4 = ( unsigned char ) V_1 ;
F_2 () ;
V_1 >>= 8 ;
V_2 . V_5 = ( unsigned char ) V_1 ;
F_2 () ;
}
static inline unsigned long F_3 ( void )
{
unsigned long V_1 ;
V_1 = V_2 . V_3 ;
F_2 () ;
V_1 |= ( V_2 . V_4 & 0xff ) << 8 ;
F_2 () ;
V_1 |= ( V_2 . V_5 & 0xff ) << 16 ;
F_2 () ;
return V_1 ;
}
static inline void F_4 ( void )
{
if ( F_5 () )
F_6 ( V_6 ) ;
else
F_6 ( V_7 ) ;
}
static inline void F_7 ( void )
{
if ( F_5 () )
F_8 ( V_6 ) ;
else
F_8 ( V_7 ) ;
}
static int F_9 ( unsigned char V_8 )
{
int V_9 ;
unsigned long V_10 = F_10 ( V_11 ) , V_12 ;
if ( V_8 & 0x01 ) {
for ( V_9 = 0 ; V_9 < V_13 ; ++ V_9 ) {
V_12 = V_14 [ V_9 ] . V_10 + V_14 [ V_9 ] . V_15 ;
if ( V_12 <= V_10 && V_10 <= V_12 + 4 )
return 1 ;
}
}
return 0 ;
}
static T_1 F_11 ( int V_16 , void * V_17 )
{
#ifdef F_12
int V_8 ;
V_8 = V_18 . V_19 ;
F_13 ( L_1 ,
V_20 -> V_21 , V_8 & 0xff ) ;
if ( V_8 & 0x80 ) {
if ( ! F_9 ( V_8 ) ) {
F_14 ( V_22 L_2 ,
F_10 ( V_11 ) ) ;
F_14 ( V_23 L_3 ) ;
}
}
if ( ( V_8 & 0x02 ) && ! ( V_8 & 0x40 ) ) {
V_24 = V_25 - ( F_10 ( V_11 ) - V_26 ) ;
F_15 ( L_4 ,
V_24 ) ;
if ( ( signed int ) V_24 < 0 )
V_24 = 0 ;
if ( ( V_8 & 1 ) == 0 ) {
F_16 () ;
} else {
if ( V_24 & 0x1ff ) {
F_15 ( L_5
L_6 ,
512 - ( V_24 & 0x1ff ) ) ;
V_24 = ( V_24 + 511 ) & ~ 0x1ff ;
}
}
V_18 . V_19 = 0 ;
}
if ( V_8 & 0x40 ) {
V_24 = 0 ;
if ( ( V_8 & 1 ) == 0 )
F_16 () ;
V_18 . V_19 = 0 ;
}
#endif
F_17 ( V_16 , V_17 ) ;
#if 0
atari_enable_irq(IRQ_TT_MFP_SCSI);
#endif
return V_27 ;
}
static T_1 F_18 ( int V_16 , void * V_17 )
{
#ifdef F_12
int V_8 ;
V_2 . V_28 = 0x90 ;
V_8 = V_2 . V_28 ;
if ( ! ( V_8 & 0x01 ) ) {
F_14 ( V_23 L_7 , F_3 () ) ;
}
if ( V_29 && ( V_8 & 0x02 ) ) {
unsigned long V_30 ;
V_30 = F_3 () - V_26 ;
if ( V_30 & 15 )
F_14 ( V_22 L_8
L_9 , V_30 & 15 ) ;
V_24 = V_25 - V_30 ;
F_15 ( L_4 ,
V_24 ) ;
} else
V_24 = 0 ;
V_29 = 0 ;
if ( V_31 ) {
memcpy ( V_31 , F_19 ( V_26 ) ,
V_25 - V_24 ) ;
V_31 = NULL ;
}
#endif
F_17 ( V_16 , V_17 ) ;
return V_27 ;
}
static void F_16 ( void )
{
int V_32 ;
char * V_33 , * V_34 ;
unsigned long V_35 ;
V_35 = F_10 ( V_11 ) ;
V_32 = V_35 & 3 ;
if ( V_32 ) {
V_35 ^= V_32 ;
F_15 ( L_10 ,
V_32 , V_35 ) ;
V_34 = F_19 ( V_35 ) ;
F_15 ( L_11 , V_34 ) ;
for ( V_33 = ( char * ) & V_18 . V_36 ; V_32 != 0 ; -- V_32 )
* V_34 ++ = * V_33 ++ ;
}
}
static void F_20 ( struct V_37 * V_38 )
{
unsigned long V_39 ;
if ( F_5 () )
return;
F_21 ( V_39 ) ;
if ( V_40 && ! V_38 -> V_41 &&
! V_38 -> V_42 && ! V_38 -> V_43 ) {
if ( V_44 ) {
#if 0
printk("WARNING: Lock release not allowed. Ignored\n");
#endif
F_22 ( V_39 ) ;
return;
}
V_40 = 0 ;
F_23 () ;
F_24 ( & V_45 ) ;
}
F_22 ( V_39 ) ;
}
static void F_25 ( void )
{
unsigned long V_39 ;
if ( F_5 () )
return;
F_21 ( V_39 ) ;
while ( ! F_26 () && V_40 && F_27 () )
F_28 ( & V_45 ) ;
while ( ! V_40 ) {
if ( F_26 () )
F_29 ( L_12 ) ;
if ( ! V_46 ) {
V_46 = 1 ;
F_30 ( F_18 , NULL ) ;
V_40 = 1 ;
V_46 = 0 ;
F_24 ( & V_47 ) ;
} else {
F_28 ( & V_47 ) ;
}
}
F_22 ( V_39 ) ;
if ( ! V_40 )
F_29 ( L_13 ) ;
}
int T_2 F_31 ( struct V_48 * V_49 )
{
static int V_50 = 0 ;
struct V_51 * V_52 ;
if ( ! V_53 ||
( ! F_32 ( V_54 ) && ! F_32 ( V_55 ) ) ||
V_50 )
return 0 ;
V_49 -> V_56 = L_14 ;
V_57 = F_5 () ? V_58 :
V_59 ;
V_60 = F_5 () ? V_61 :
V_62 ;
V_49 -> V_63 =
( V_64 > 0 ) ? V_64 :
F_5 () ? V_65 : V_66 ;
V_49 -> V_67 =
( V_68 > 0 ) ? V_68 :
F_5 () ? V_69 : V_70 ;
V_49 -> V_71 =
! F_5 () ? V_72 :
( V_73 >= 0 ) ? V_73 : V_74 ;
if ( V_75 >= 0 )
V_49 -> V_76 = V_75 ;
else {
V_49 -> V_76 = 7 ;
if ( F_32 ( V_77 ) && F_33 () ) {
unsigned char V_78 = F_34 ( 14 ) ;
if ( V_78 & 0x80 )
V_49 -> V_76 = V_78 & 7 ;
}
}
#ifdef F_35
if ( V_79 < 0 )
V_79 = V_80 ;
#endif
#ifdef F_12
if ( V_53 && F_32 ( V_54 ) &&
! F_32 ( V_81 ) && V_13 > 1 ) {
V_82 = F_36 ( V_83 , L_15 ) ;
if ( ! V_82 ) {
F_14 ( V_22 L_16
L_17 ) ;
return 0 ;
}
V_84 = F_37 ( V_82 ) ;
V_31 = 0 ;
}
#endif
V_52 = F_38 ( V_49 , sizeof( struct V_37 ) ) ;
if ( V_52 == NULL ) {
F_39 ( V_82 ) ;
V_82 = 0 ;
return 0 ;
}
V_20 = V_52 ;
V_52 -> V_16 = 0 ;
#ifdef F_40
F_41 () ;
#endif
F_42 ( V_52 , 0 ) ;
if ( F_5 () ) {
if ( F_43 ( V_6 , F_11 , V_85 ,
L_18 , V_52 ) ) {
F_14 ( V_22 L_19 , V_6 ) ;
F_44 ( V_20 ) ;
F_39 ( V_82 ) ;
V_82 = 0 ;
return 0 ;
}
V_86 . V_87 |= 0x80 ;
#ifdef F_12
V_18 . V_19 = 0 ;
V_24 = 0 ;
if ( V_88 ) {
V_89 = 4 ;
}
#endif
} else {
#ifdef F_12
V_24 = 0 ;
V_29 = 0 ;
V_90 = ( F_32 ( V_81 ) ? 0x00000000
: 0xff000000 ) ;
#endif
}
F_14 ( V_91 L_20
#ifdef F_35
L_21
#endif
L_22 ,
V_52 -> V_21 , V_52 -> V_92 -> V_63 ,
V_52 -> V_92 -> V_67 ,
V_52 -> V_92 -> V_71 ,
#ifdef F_35
V_79 ? L_23 : L_24 ,
#endif
V_52 -> V_92 -> V_76 ) ;
F_45 ( V_52 ) ;
F_14 ( L_25 ) ;
V_50 = 1 ;
return 1 ;
}
int F_46 ( struct V_51 * V_93 )
{
if ( F_5 () )
F_47 ( V_6 , V_93 ) ;
if ( V_82 )
F_39 ( V_82 ) ;
F_48 ( V_93 ) ;
return 1 ;
}
void T_2 F_49 ( char * V_94 , int * V_95 )
{
if ( V_95 [ 0 ] < 1 ) {
F_14 ( L_26 ) ;
return;
}
if ( V_95 [ 0 ] >= 1 ) {
if ( V_95 [ 1 ] > 0 )
V_64 = V_95 [ 1 ] ;
}
if ( V_95 [ 0 ] >= 2 ) {
if ( V_95 [ 2 ] > 0 )
V_68 = V_95 [ 2 ] ;
}
if ( V_95 [ 0 ] >= 3 ) {
if ( V_95 [ 3 ] >= 0 ) {
V_73 = V_95 [ 3 ] ;
if ( V_73 > V_96 )
V_73 = V_96 ;
}
}
if ( V_95 [ 0 ] >= 4 ) {
if ( V_95 [ 4 ] >= 0 && V_95 [ 4 ] <= 7 )
V_75 = V_95 [ 4 ] ;
else if ( V_95 [ 4 ] > 7 )
F_14 ( L_27 , V_95 [ 4 ] ) ;
}
#ifdef F_35
if ( V_95 [ 0 ] >= 5 ) {
if ( V_95 [ 5 ] >= 0 )
V_79 = ! ! V_95 [ 5 ] ;
}
#endif
}
int F_50 ( T_3 * V_97 )
{
int V_98 ;
struct V_37 * V_38 =
(struct V_37 * ) V_97 -> V_99 -> V_49 -> V_38 ;
if ( F_5 () ) {
F_51 ( V_6 ) ;
#ifdef F_12
V_18 . V_19 = 0 ;
#endif
} else {
F_51 ( V_7 ) ;
#ifdef F_12
V_2 . V_28 = 0x90 ;
V_29 = 0 ;
V_31 = NULL ;
#endif
}
V_98 = F_52 ( V_97 ) ;
if ( F_5 () ) {
F_53 ( V_6 ) ;
} else {
F_53 ( V_7 ) ;
}
if ( ( V_98 & V_100 ) == V_101 )
F_20 ( V_38 ) ;
return V_98 ;
}
static void T_2 F_41 ( void )
{
unsigned long V_102 ;
F_14 ( L_28 ) ;
F_54 ( V_103 ,
F_55 ( F_56 ( V_104 ) ) ) ;
F_54 ( V_105 , V_106 | V_107 ) ;
F_57 ( 50 ) ;
F_54 ( V_105 , V_106 ) ;
F_56 ( V_108 ) ;
V_102 = V_109 + V_110 ;
while ( F_58 ( V_109 , V_102 ) )
F_59 () ;
F_14 ( L_29 ) ;
}
const char * F_60 ( struct V_51 * V_49 )
{
static const char string [] = L_30 ;
return string ;
}
unsigned long F_61 ( struct V_51 * V_52 , void * V_111 ,
unsigned long V_112 , int V_113 )
{
unsigned long V_10 = F_37 ( V_111 ) ;
F_15 ( L_31
L_32 , V_52 -> V_21 , V_111 , V_10 , V_112 , V_113 ) ;
if ( ! F_5 () && ! F_62 ( V_10 ) ) {
if ( V_113 )
memcpy ( V_82 , V_111 , V_112 ) ;
else
V_31 = V_111 ;
V_10 = V_84 ;
}
V_26 = V_10 ;
F_63 ( V_10 , V_112 , V_113 ) ;
if ( V_112 == 0 )
F_14 ( V_114 L_33 ) ;
if ( F_5 () ) {
V_18 . V_19 = V_113 ;
F_64 ( V_11 , V_10 ) ;
F_64 ( V_115 , V_112 ) ;
V_18 . V_19 = V_113 | 2 ;
} else {
F_1 ( V_10 ) ;
V_113 <<= 8 ;
V_2 . V_28 = 0x90 | V_113 ;
V_2 . V_28 = 0x90 | ( V_113 ^ 0x100 ) ;
V_2 . V_28 = 0x90 | V_113 ;
F_57 ( 40 ) ;
V_2 . V_116 = ( V_112 + ( V_113 ? 511 : 0 ) ) >> 9 ;
F_57 ( 40 ) ;
V_2 . V_28 = 0x10 | V_113 ;
F_57 ( 40 ) ;
V_29 = 1 ;
}
return V_112 ;
}
static long F_65 ( struct V_51 * V_52 )
{
return V_24 ;
}
static int F_66 ( T_3 * V_97 )
{
unsigned char V_117 = V_97 -> V_118 [ 0 ] ;
if ( V_117 == V_119 || V_117 == V_120 ||
V_117 == V_121 )
return V_122 ;
else if ( V_117 == V_123 || V_117 == V_124 ||
V_117 == 0xa8 || V_117 == V_125 ||
V_117 == V_126 ) {
if ( V_97 -> V_99 -> type == V_127 && ! ( V_97 -> V_118 [ 1 ] & 1 ) )
return V_122 ;
else
return V_128 ;
} else
return V_129 ;
}
static unsigned long F_67 ( unsigned long V_130 ,
T_3 * V_97 , int V_131 )
{
unsigned long V_132 , V_133 ;
if ( F_5 () )
return V_130 ;
if ( V_131 ) {
V_132 = V_130 ;
} else {
if ( V_130 & 0x1ff )
V_132 = 0 ;
else {
switch ( F_66 ( V_97 ) ) {
case V_128 :
V_132 = V_130 ;
break;
case V_122 :
V_132 = 0 ;
break;
case V_129 :
default:
V_132 = ( V_130 < 1024 ) ? 0 : V_130 ;
break;
}
}
}
V_133 = ( V_82 && ! F_62 ( F_37 ( V_97 -> V_134 . V_135 ) ) ) ?
V_83 : 255 * 512 ;
if ( V_132 > V_133 )
V_132 = V_133 ;
if ( V_132 != V_130 )
F_15 ( L_34
L_35 , V_132 , V_130 ) ;
return V_132 ;
}
static unsigned char V_58 ( unsigned char V_136 )
{
return V_137 [ V_136 * 2 ] ;
}
static void V_61 ( unsigned char V_136 , unsigned char V_138 )
{
V_137 [ V_136 * 2 ] = V_138 ;
}
static unsigned char V_59 ( unsigned char V_136 )
{
V_139 . V_28 = ( V_140 ) ( 0x88 + V_136 ) ;
return ( V_141 ) V_139 . V_116 ;
}
static void V_62 ( unsigned char V_136 , unsigned char V_138 )
{
V_139 . V_28 = ( V_140 ) ( 0x88 + V_136 ) ;
V_139 . V_116 = ( V_140 ) V_138 ;
}
