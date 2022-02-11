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
F_13 ( V_20 , L_1 ,
V_21 -> V_22 , V_8 & 0xff ) ;
if ( V_8 & 0x80 ) {
if ( ! F_9 ( V_8 ) ) {
F_14 ( V_23 L_2 ,
F_10 ( V_11 ) ) ;
F_14 ( V_24 L_3 ) ;
}
}
if ( ( V_8 & 0x02 ) && ! ( V_8 & 0x40 ) ) {
V_25 = V_26 - ( F_10 ( V_11 ) - V_27 ) ;
F_13 ( V_28 , L_4 ,
V_25 ) ;
if ( ( signed int ) V_25 < 0 )
V_25 = 0 ;
if ( ( V_8 & 1 ) == 0 ) {
F_15 () ;
} else {
if ( V_25 & 0x1ff ) {
F_13 ( V_28 , L_5
L_6 ,
512 - ( V_25 & 0x1ff ) ) ;
V_25 = ( V_25 + 511 ) & ~ 0x1ff ;
}
}
V_18 . V_19 = 0 ;
}
if ( V_8 & 0x40 ) {
V_25 = 0 ;
if ( ( V_8 & 1 ) == 0 )
F_15 () ;
V_18 . V_19 = 0 ;
}
#endif
F_16 ( V_16 , V_17 ) ;
#if 0
atari_enable_irq(IRQ_TT_MFP_SCSI);
#endif
return V_29 ;
}
static T_1 F_17 ( int V_16 , void * V_17 )
{
#ifdef F_12
int V_8 ;
V_2 . V_30 = 0x90 ;
V_8 = V_2 . V_30 ;
if ( ! ( V_8 & 0x01 ) ) {
F_14 ( V_24 L_7 , F_3 () ) ;
}
if ( V_31 && ( V_8 & 0x02 ) ) {
unsigned long V_32 ;
V_32 = F_3 () - V_27 ;
if ( V_32 & 15 )
F_14 ( V_23 L_8
L_9 , V_32 & 15 ) ;
V_25 = V_26 - V_32 ;
F_13 ( V_28 , L_4 ,
V_25 ) ;
} else
V_25 = 0 ;
V_31 = 0 ;
if ( V_33 ) {
memcpy ( V_33 , F_18 ( V_27 ) ,
V_26 - V_25 ) ;
V_33 = NULL ;
}
#endif
F_16 ( V_16 , V_17 ) ;
return V_29 ;
}
static void F_15 ( void )
{
int V_34 ;
char * V_35 , * V_36 ;
unsigned long V_37 ;
V_37 = F_10 ( V_11 ) ;
V_34 = V_37 & 3 ;
if ( V_34 ) {
V_37 ^= V_34 ;
F_13 ( V_28 , L_10 ,
V_34 , V_37 ) ;
V_36 = F_18 ( V_37 ) ;
F_13 ( V_28 , L_11 , V_36 ) ;
for ( V_35 = ( char * ) & V_18 . V_38 ; V_34 != 0 ; -- V_34 )
* V_36 ++ = * V_35 ++ ;
}
}
static void F_19 ( struct V_39 * V_40 )
{
unsigned long V_41 ;
if ( F_5 () )
return;
F_20 ( V_41 ) ;
if ( V_42 && ! V_40 -> V_43 &&
! V_40 -> V_44 && ! V_40 -> V_45 ) {
if ( V_46 ) {
#if 0
printk("WARNING: Lock release not allowed. Ignored\n");
#endif
F_21 ( V_41 ) ;
return;
}
V_42 = 0 ;
F_22 () ;
F_23 ( & V_47 ) ;
}
F_21 ( V_41 ) ;
}
static void F_24 ( void )
{
unsigned long V_41 ;
if ( F_5 () )
return;
F_20 ( V_41 ) ;
F_25 ( V_47 ,
F_26 () || ! V_42 || ! F_27 () ,
F_21 ( V_41 ) ,
F_20 ( V_41 ) ) ;
while ( ! V_42 ) {
if ( F_28 () )
F_29 ( L_12 ) ;
if ( ! V_48 ) {
V_48 = 1 ;
F_30 ( F_17 , NULL ) ;
V_42 = 1 ;
V_48 = 0 ;
F_23 ( & V_49 ) ;
} else {
F_25 ( V_49 ,
V_42 && ! V_48 ,
F_21 ( V_41 ) ,
F_20 ( V_41 ) ) ;
}
}
F_21 ( V_41 ) ;
if ( ! V_42 )
F_29 ( L_13 ) ;
}
static int T_2 F_31 ( struct V_50 * V_51 )
{
static int V_52 = 0 ;
struct V_53 * V_54 ;
if ( ! V_55 ||
( ! F_32 ( V_56 ) && ! F_32 ( V_57 ) ) ||
V_52 )
return 0 ;
V_51 -> V_58 = L_14 ;
V_59 = F_5 () ? V_60 :
V_61 ;
V_62 = F_5 () ? V_63 :
V_64 ;
V_51 -> V_65 =
( V_66 > 0 ) ? V_66 :
F_5 () ? V_67 : V_68 ;
V_51 -> V_69 =
( V_70 > 0 ) ? V_70 :
F_5 () ? V_71 : V_72 ;
V_51 -> V_73 =
! F_5 () ? V_74 :
( V_75 >= 0 ) ? V_75 : V_76 ;
if ( V_77 >= 0 )
V_51 -> V_78 = V_77 ;
else {
V_51 -> V_78 = 7 ;
if ( F_32 ( V_79 ) && F_33 () ) {
unsigned char V_80 = F_34 ( 14 ) ;
if ( V_80 & 0x80 )
V_51 -> V_78 = V_80 & 7 ;
}
}
#ifdef F_35
if ( V_81 < 0 )
V_81 = V_82 ;
#endif
#ifdef F_12
if ( V_55 && F_32 ( V_56 ) &&
! F_32 ( V_83 ) && V_13 > 1 ) {
V_84 = F_36 ( V_85 , L_15 ) ;
if ( ! V_84 ) {
F_14 ( V_23 L_16
L_17 ) ;
return 0 ;
}
V_86 = F_37 ( V_84 ) ;
V_33 = 0 ;
}
#endif
V_54 = F_38 ( V_51 , sizeof( struct V_39 ) ) ;
if ( V_54 == NULL ) {
F_39 ( V_84 ) ;
V_84 = 0 ;
return 0 ;
}
V_21 = V_54 ;
V_54 -> V_16 = 0 ;
#ifdef F_40
F_41 () ;
#endif
F_42 ( V_54 , 0 ) ;
if ( F_5 () ) {
if ( F_43 ( V_6 , F_11 , V_87 ,
L_18 , V_54 ) ) {
F_14 ( V_23 L_19 , V_6 ) ;
F_44 ( V_21 ) ;
F_39 ( V_84 ) ;
V_84 = 0 ;
return 0 ;
}
V_88 . V_89 |= 0x80 ;
#ifdef F_12
V_18 . V_19 = 0 ;
V_25 = 0 ;
if ( V_90 ) {
V_91 = 4 ;
}
#endif
} else {
#ifdef F_12
V_25 = 0 ;
V_31 = 0 ;
V_92 = ( F_32 ( V_83 ) ? 0x00000000
: 0xff000000 ) ;
#endif
}
F_14 ( V_93 L_20
#ifdef F_35
L_21
#endif
L_22 ,
V_54 -> V_22 , V_54 -> V_94 -> V_65 ,
V_54 -> V_94 -> V_69 ,
V_54 -> V_94 -> V_73 ,
#ifdef F_35
V_81 ? L_23 : L_24 ,
#endif
V_54 -> V_94 -> V_78 ) ;
F_45 ( V_54 ) ;
F_14 ( L_25 ) ;
V_52 = 1 ;
return 1 ;
}
static int F_46 ( struct V_53 * V_95 )
{
if ( F_5 () )
F_47 ( V_6 , V_95 ) ;
if ( V_84 )
F_39 ( V_84 ) ;
F_48 ( V_95 ) ;
return 1 ;
}
static int T_2 F_49 ( char * V_96 )
{
int V_97 [ 6 ] ;
F_50 ( V_96 , F_51 ( V_97 ) , V_97 ) ;
if ( V_97 [ 0 ] < 1 ) {
F_14 ( L_26 ) ;
return 0 ;
}
if ( V_97 [ 0 ] >= 1 ) {
if ( V_97 [ 1 ] > 0 )
V_66 = V_97 [ 1 ] ;
}
if ( V_97 [ 0 ] >= 2 ) {
if ( V_97 [ 2 ] > 0 )
V_70 = V_97 [ 2 ] ;
}
if ( V_97 [ 0 ] >= 3 ) {
if ( V_97 [ 3 ] >= 0 ) {
V_75 = V_97 [ 3 ] ;
if ( V_75 > V_98 )
V_75 = V_98 ;
}
}
if ( V_97 [ 0 ] >= 4 ) {
if ( V_97 [ 4 ] >= 0 && V_97 [ 4 ] <= 7 )
V_77 = V_97 [ 4 ] ;
else if ( V_97 [ 4 ] > 7 )
F_14 ( L_27 , V_97 [ 4 ] ) ;
}
#ifdef F_35
if ( V_97 [ 0 ] >= 5 ) {
if ( V_97 [ 5 ] >= 0 )
V_81 = ! ! V_97 [ 5 ] ;
}
#endif
return 1 ;
}
static int F_52 ( T_3 * V_99 )
{
int V_100 ;
struct V_39 * V_40 =
(struct V_39 * ) V_99 -> V_101 -> V_51 -> V_40 ;
if ( F_5 () ) {
F_53 ( V_6 ) ;
#ifdef F_12
V_18 . V_19 = 0 ;
#endif
} else {
F_53 ( V_7 ) ;
#ifdef F_12
V_2 . V_30 = 0x90 ;
V_31 = 0 ;
V_33 = NULL ;
#endif
}
V_100 = F_54 ( V_99 ) ;
if ( F_5 () ) {
F_55 ( V_6 ) ;
} else {
F_55 ( V_7 ) ;
}
if ( V_100 == V_102 )
F_19 ( V_40 ) ;
return V_100 ;
}
static void T_2 F_41 ( void )
{
unsigned long V_103 ;
F_14 ( L_28 ) ;
F_56 ( V_104 ,
F_57 ( F_58 ( V_105 ) ) ) ;
F_56 ( V_106 , V_107 | V_108 ) ;
F_59 ( 50 ) ;
F_56 ( V_106 , V_107 ) ;
F_58 ( V_109 ) ;
V_103 = V_110 + V_111 ;
while ( F_60 ( V_110 , V_103 ) )
F_61 () ;
F_14 ( L_29 ) ;
}
static const char * F_62 ( struct V_53 * V_51 )
{
static const char string [] = L_30 ;
return string ;
}
static unsigned long F_63 ( struct V_53 * V_54 ,
void * V_112 , unsigned long V_113 ,
int V_114 )
{
unsigned long V_10 = F_64 ( V_112 ) ;
F_13 ( V_28 , L_31
L_32 , V_54 -> V_22 , V_112 , V_10 , V_113 , V_114 ) ;
if ( ! F_5 () && ! F_65 ( V_10 ) ) {
if ( V_114 )
memcpy ( V_84 , V_112 , V_113 ) ;
else
V_33 = V_112 ;
V_10 = V_86 ;
}
V_27 = V_10 ;
F_66 ( V_10 , V_113 , V_114 ) ;
if ( V_113 == 0 )
F_14 ( V_115 L_33 ) ;
if ( F_5 () ) {
V_18 . V_19 = V_114 ;
F_67 ( V_11 , V_10 ) ;
F_67 ( V_116 , V_113 ) ;
V_18 . V_19 = V_114 | 2 ;
} else {
F_1 ( V_10 ) ;
V_114 <<= 8 ;
V_2 . V_30 = 0x90 | V_114 ;
V_2 . V_30 = 0x90 | ( V_114 ^ 0x100 ) ;
V_2 . V_30 = 0x90 | V_114 ;
F_59 ( 40 ) ;
V_2 . V_117 = ( V_113 + ( V_114 ? 511 : 0 ) ) >> 9 ;
F_59 ( 40 ) ;
V_2 . V_30 = 0x10 | V_114 ;
F_59 ( 40 ) ;
V_31 = 1 ;
}
return V_113 ;
}
static long F_68 ( struct V_53 * V_54 )
{
return V_25 ;
}
static int F_69 ( T_3 * V_99 )
{
unsigned char V_118 = V_99 -> V_119 [ 0 ] ;
if ( V_118 == V_120 || V_118 == V_121 ||
V_118 == V_122 )
return V_123 ;
else if ( V_118 == V_124 || V_118 == V_125 ||
V_118 == 0xa8 || V_118 == V_126 ||
V_118 == V_127 ) {
if ( V_99 -> V_101 -> type == V_128 && ! ( V_99 -> V_119 [ 1 ] & 1 ) )
return V_123 ;
else
return V_129 ;
} else
return V_130 ;
}
static unsigned long F_70 ( unsigned long V_131 ,
T_3 * V_99 , int V_132 )
{
unsigned long V_133 , V_134 ;
if ( F_5 () )
return V_131 ;
if ( V_132 ) {
V_133 = V_131 ;
} else {
if ( V_131 & 0x1ff )
V_133 = 0 ;
else {
switch ( F_69 ( V_99 ) ) {
case V_129 :
V_133 = V_131 ;
break;
case V_123 :
V_133 = 0 ;
break;
case V_130 :
default:
V_133 = ( V_131 < 1024 ) ? 0 : V_131 ;
break;
}
}
}
V_134 = ( V_84 && ! F_65 ( F_64 ( V_99 -> V_135 . V_136 ) ) ) ?
V_85 : 255 * 512 ;
if ( V_133 > V_134 )
V_133 = V_134 ;
if ( V_133 != V_131 )
F_13 ( V_28 , L_34
L_35 , V_133 , V_131 ) ;
return V_133 ;
}
static unsigned char V_60 ( unsigned char V_137 )
{
return V_138 [ V_137 * 2 ] ;
}
static void V_63 ( unsigned char V_137 , unsigned char V_139 )
{
V_138 [ V_137 * 2 ] = V_139 ;
}
static unsigned char V_61 ( unsigned char V_137 )
{
V_140 . V_30 = ( V_141 ) ( 0x88 + V_137 ) ;
return ( V_142 ) V_140 . V_117 ;
}
static void V_64 ( unsigned char V_137 , unsigned char V_139 )
{
V_140 . V_30 = ( V_141 ) ( 0x88 + V_137 ) ;
V_140 . V_117 = ( V_141 ) V_139 ;
}
