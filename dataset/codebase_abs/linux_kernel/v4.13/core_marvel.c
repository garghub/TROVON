static char * T_1
F_1 ( int V_1 , int V_2 , char * V_3 )
{
char V_4 [ 80 ] ;
char * V_5 ;
sprintf ( V_4 , L_1 , V_3 , V_1 , V_2 ) ;
V_5 = F_2 ( strlen ( V_4 ) + 1 ) ;
strcpy ( V_5 , V_4 ) ;
return V_5 ;
}
inline struct V_6 *
F_3 ( struct V_6 * V_7 )
{
return ( V_7 ? V_7 -> V_8 : V_9 ) ;
}
struct V_6 *
F_4 ( int V_1 )
{
struct V_6 * V_6 ;
for ( V_6 = V_9 ; V_6 && V_6 -> V_1 != V_1 ; V_6 = V_6 -> V_8 )
continue;
return V_6 ;
}
static struct V_6 * T_1
F_5 ( unsigned int V_1 )
{
struct V_6 * V_6 ;
struct V_6 * V_10 ;
int V_11 ;
if ( F_4 ( V_1 ) ) {
F_6 ( V_12 L_2 , V_1 ) ;
return NULL ;
}
V_6 = F_2 ( sizeof( * V_6 ) ) ;
V_6 -> V_1 = V_1 ;
F_7 ( & V_6 -> V_13 ) ;
for ( V_11 = 0 ; V_11 < 4 ; V_11 ++ ) {
V_6 -> V_14 [ V_11 ] . V_6 = V_6 ;
V_6 -> V_14 [ V_11 ] . V_2 = V_11 ;
V_6 -> V_14 [ V_11 ] . V_15 = 0 ;
}
if ( NULL == V_9 )
V_9 = V_6 ;
else if ( V_9 -> V_1 > V_6 -> V_1 ) {
V_6 -> V_8 = V_9 ;
V_9 = V_6 ;
} else {
for ( V_10 = V_9 ; V_10 ; V_10 = V_10 -> V_8 ) {
if ( V_10 -> V_1 == V_6 -> V_1 ) {
F_6 ( V_16 L_3 ,
V_6 -> V_1 ) ;
return NULL ;
}
if ( NULL == V_10 -> V_8 ||
V_10 -> V_8 -> V_1 > V_6 -> V_1 ) {
V_6 -> V_8 = V_10 -> V_8 ;
V_10 -> V_8 = V_6 ;
break;
}
}
if ( NULL == V_10 ) {
F_6 ( V_12 L_4
L_5 , V_6 -> V_1 ) ;
V_6 -> V_8 = V_9 ;
V_9 = V_6 ;
}
}
return V_6 ;
}
void
F_8 ( struct V_6 * V_6 )
{
T_2 * V_17 ;
T_3 * V_18 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
V_18 = F_9 ( V_6 -> V_1 , V_2 ) ;
V_18 -> V_19 . V_20 = - 1UL ;
V_18 -> V_21 . V_20 = - 1UL ;
V_18 -> V_22 . V_20 = - 1UL ;
V_18 -> V_23 . V_20 = - 1UL ;
}
V_17 = F_10 ( V_6 -> V_1 ) ;
V_17 -> V_24 . V_20 = - 1UL ;
V_17 -> V_25 . V_20 = - 1UL ;
V_17 -> V_26 . V_20 = - 1UL ;
}
static void T_1
F_11 ( struct V_6 * V_6 , int V_2 )
{
static int V_27 = 0 ;
struct V_28 * V_29 = F_12 () ;
struct V_30 * V_30 = & V_6 -> V_14 [ V_2 ] ;
T_3 * V_18 = F_9 ( V_6 -> V_1 , V_2 ) ;
int V_31 ;
V_29 -> V_32 = V_27 ++ ;
if ( V_29 -> V_32 == 0 )
V_33 = V_29 ;
V_30 -> V_18 = V_18 ;
V_30 -> V_29 = V_29 ;
V_29 -> V_34 = V_30 ;
V_29 -> V_35 = F_13 () ;
V_29 -> V_36 = F_13 () ;
V_29 -> V_37 = V_29 -> V_38 = 0 ;
V_29 -> V_39 = F_14 ( V_6 -> V_1 , V_2 ) ;
V_29 -> V_40 = F_15 ( V_6 -> V_1 , V_2 ) ;
V_29 -> V_41 = ( unsigned long ) F_16 ( V_6 -> V_1 , V_2 ) ;
V_29 -> V_35 -> V_42 = ( unsigned long ) F_17 ( V_6 -> V_1 , V_2 ) ;
V_29 -> V_35 -> V_43 = V_29 -> V_35 -> V_42 + V_44 - 1 ;
V_29 -> V_35 -> V_5 = F_1 ( V_6 -> V_1 , V_2 , L_6 ) ;
V_29 -> V_35 -> V_45 = V_46 ;
V_29 -> V_36 -> V_42 = ( unsigned long ) F_18 ( V_6 -> V_1 , V_2 ) ;
V_29 -> V_36 -> V_43 = V_29 -> V_36 -> V_42 + V_47 - 1 ;
V_29 -> V_36 -> V_5 = F_1 ( V_6 -> V_1 , V_2 , L_7 ) ;
V_29 -> V_36 -> V_45 = V_48 ;
if ( F_19 ( & V_49 , V_29 -> V_35 ) < 0 )
F_6 ( V_16 L_8 ,
V_29 -> V_32 ) ;
if ( F_19 ( & V_50 , V_29 -> V_36 ) < 0 )
F_6 ( V_16 L_9 ,
V_29 -> V_32 ) ;
for ( V_31 = 0 ; V_31 < 4 ; V_31 ++ ) {
V_30 -> V_51 [ V_31 ] = V_18 -> V_52 [ V_31 ] . V_20 ;
V_30 -> V_53 [ V_31 ] = V_18 -> V_54 [ V_31 ] . V_20 ;
V_30 -> V_55 [ V_31 ] = V_18 -> V_56 [ V_31 ] . V_20 ;
}
F_20 ( V_29 , 0 , - 1 ) ;
V_29 -> V_57 = F_21 ( F_22 ( V_6 -> V_1 ) ,
V_29 , 0x00800000 , 0x00800000 , 0 ) ;
V_29 -> V_57 -> V_58 = 8 ;
V_18 -> V_52 [ 0 ] . V_20 =
V_29 -> V_57 -> V_59 | V_60 | V_61 ;
V_18 -> V_54 [ 0 ] . V_20 = ( V_29 -> V_57 -> V_62 - 1 ) & V_63 ;
V_18 -> V_56 [ 0 ] . V_20 = F_23 ( V_29 -> V_57 -> V_64 ) ;
V_18 -> V_52 [ 1 ] . V_20 = V_65 | V_60 ;
V_18 -> V_54 [ 1 ] . V_20 = ( V_66 - 1 ) & V_63 ;
V_18 -> V_56 [ 1 ] . V_20 = 0 ;
V_29 -> V_67 = F_21 ( F_22 ( V_6 -> V_1 ) ,
V_29 , 0xc0000000 , 0x40000000 , 0 ) ;
V_29 -> V_67 -> V_58 = 8 ;
V_18 -> V_52 [ 2 ] . V_20 =
V_29 -> V_67 -> V_59 | V_60 | V_61 ;
V_18 -> V_54 [ 2 ] . V_20 = ( V_29 -> V_67 -> V_62 - 1 ) & V_63 ;
V_18 -> V_56 [ 2 ] . V_20 = F_23 ( V_29 -> V_67 -> V_64 ) ;
V_18 -> V_52 [ 3 ] . V_20 = 0 ;
V_18 -> V_68 . V_20 &= ~ ( 1UL << 61 ) ;
#if 1
F_6 ( L_10 ) ;
V_18 -> V_69 . V_20 &= ~ ( 3UL << 14 ) ;
#endif
F_20 ( V_29 , 0 , - 1 ) ;
}
static void T_1
F_24 ( struct V_6 * V_6 )
{
int V_31 ;
F_6 ( L_11 , V_6 -> V_1 ) ;
V_6 -> V_18 = F_10 ( V_6 -> V_1 ) ;
for ( V_31 = 0 ; V_31 < V_70 ; V_31 ++ ) {
T_3 * V_18 = F_9 ( V_6 -> V_1 , V_31 ) ;
if ( V_18 -> V_71 . V_20 == 8 ) {
V_6 -> V_14 [ V_31 ] . V_15 = 1 ;
F_11 ( V_6 , V_31 ) ;
}
}
}
void T_1
F_25 ( T_4 * V_72 )
{
int V_1 ;
if ( V_72 -> type != V_73 ||
V_72 -> V_74 != V_75 )
return;
V_1 = ( V_72 -> V_76 >> 8 ) & 0xff ;
F_6 ( L_12 , V_1 ) ;
F_5 ( V_1 ) ;
}
static void T_1
F_26 ( void )
{
#ifdef F_27
T_5 * V_77 = ( T_5 * ) ( ( T_5 ) V_78 + V_78 -> V_79 ) ;
if ( V_77 [ 7 ] == 3 ) {
struct V_28 * V_29 = NULL ;
int V_11 = ( V_77 [ 30 ] >> 24 ) & 0xff ;
struct V_6 * V_6 ;
int V_80 , V_2 ;
F_6 ( L_13 , V_11 ) ;
V_80 = V_11 >> 2 ;
V_2 = V_11 & 3 ;
if ( ( V_6 = F_4 ( V_80 ) ) )
V_29 = V_6 -> V_14 [ V_2 ] . V_29 ;
if ( V_29 ) {
F_6 ( L_14 , V_29 -> V_32 ) ;
V_81 = V_29 ;
}
}
#endif
}
static int T_1
F_28 ( char * V_3 )
{
unsigned long V_80 ;
struct V_6 * V_6 ;
char * V_82 ;
do {
V_80 = F_29 ( V_3 , & V_82 , 0 ) ;
if ( V_82 != V_3 ) {
F_6 ( L_15 , V_80 ) ;
V_6 = F_5 ( V_80 ) ;
if ( V_6 ) F_24 ( V_6 ) ;
}
if ( V_82 == V_3 ) V_82 ++ ;
V_3 = V_82 ;
} while( * V_3 );
return 1 ;
}
void T_1
F_30 ( void )
{
struct V_6 * V_6 ;
V_49 . V_43 = ~ 0UL ;
V_65 = 0x80000000 ;
V_66 = 0x40000000 ;
F_31 ( F_32 ( 0 ) , V_83 ) ;
for ( V_6 = NULL ; NULL != ( V_6 = F_3 ( V_6 ) ) ; )
F_24 ( V_6 ) ;
F_26 () ;
}
void
F_33 ( int V_84 )
{
}
static inline unsigned long
F_34 ( struct V_28 * V_29 , T_6 V_85 ,
unsigned int V_86 , int V_87 )
{
return ( V_29 -> V_41 | ( V_85 << 16 ) | ( V_86 << 8 ) | V_87 ) ;
}
static unsigned long
F_35 ( struct V_88 * V_89 , unsigned int V_86 , int V_87 )
{
struct V_28 * V_29 = V_89 -> V_34 ;
struct V_30 * V_30 ;
unsigned long V_90 = 0 ;
T_6 V_85 = V_89 -> V_91 ;
if ( ! V_29 )
return V_90 ;
V_30 = V_29 -> V_34 ;
if ( ! V_30 -> V_15 )
return V_90 ;
if ( ! V_89 -> V_92 ) {
if ( V_86 >= F_36 ( 21 , 0 ) )
return V_90 ;
V_85 = 0 ;
}
V_90 = F_34 ( V_29 , V_85 , V_86 , V_87 ) ;
F_37 ( ( L_16 , V_90 ) ) ;
return V_90 ;
}
static int
F_38 ( struct V_88 * V_85 , unsigned int V_86 , int V_87 ,
int V_62 , T_7 * V_93 )
{
unsigned long V_90 ;
if ( 0 == ( V_90 = F_35 ( V_85 , V_86 , V_87 ) ) )
return V_94 ;
switch( V_62 ) {
case 1 :
* V_93 = F_39 ( * ( V_95 ) V_90 ) ;
break;
case 2 :
* V_93 = F_40 ( * ( V_96 ) V_90 ) ;
break;
case 4 :
* V_93 = * ( V_97 ) V_90 ;
break;
default:
return V_98 ;
}
return V_99 ;
}
static int
F_41 ( struct V_88 * V_85 , unsigned int V_86 , int V_87 ,
int V_62 , T_7 V_93 )
{
unsigned long V_90 ;
if ( 0 == ( V_90 = F_35 ( V_85 , V_86 , V_87 ) ) )
return V_94 ;
switch ( V_62 ) {
case 1 :
F_42 ( V_93 , * ( V_95 ) V_90 ) ;
F_43 () ;
F_39 ( * ( V_95 ) V_90 ) ;
break;
case 2 :
F_44 ( V_93 , * ( V_96 ) V_90 ) ;
F_43 () ;
F_40 ( * ( V_96 ) V_90 ) ;
break;
case 4 :
* ( V_97 ) V_90 = V_93 ;
F_43 () ;
* ( V_97 ) V_90 ;
break;
default:
return V_98 ;
}
return V_99 ;
}
void
F_20 ( struct V_28 * V_29 , T_8 V_42 , T_8 V_43 )
{
T_3 * V_18 = ( (struct V_30 * ) V_29 -> V_34 ) -> V_18 ;
F_45 () ;
V_18 -> V_100 . V_20 = 0 ;
F_43 () ;
V_18 -> V_100 . V_20 ;
}
static void
F_46 ( void * V_101 )
{
struct V_102 * V_103 = V_101 ;
register unsigned long T_9 V_104 ( L_17 ) ;
register unsigned long T_10 V_104 ( L_18 ) = V_103 -> V_105 ;
register unsigned long T_11 V_104 ( L_19 ) = V_103 -> V_32 ;
register unsigned long T_12 V_104 ( L_20 ) = V_103 -> V_106 ;
__asm__ __volatile__(
"call_pal %4 # cserve rtc"
: "=r"(__r16), "=r"(__r17), "=r"(__r18), "=r"(__r0)
: "i"(PAL_cserve), "0"(__r16), "1"(__r17), "2"(__r18)
: "$1", "$22", "$23", "$24", "$25");
V_103 -> V_106 = T_9 ;
}
static T_6
F_47 ( T_6 V_107 , unsigned long V_90 , int V_108 )
{
static T_6 V_32 = 0 ;
struct V_102 V_103 ;
T_6 V_109 = 0 ;
switch( V_90 ) {
case 0x70 :
if ( V_108 ) V_32 = V_107 ;
V_109 = V_32 ;
break;
case 0x71 :
V_103 . V_32 = V_32 ;
V_103 . V_106 = F_48 ( V_107 ) ;
V_103 . V_105 = 0x48 + ! V_108 ;
F_46 ( & V_103 ) ;
V_109 = F_49 ( V_103 . V_106 ) ;
break;
default:
F_6 ( V_12 L_21 , V_90 ) ;
break;
}
return V_109 ;
}
void T_13 *
F_50 ( unsigned long V_90 , unsigned long V_62 )
{
struct V_28 * V_29 ;
unsigned long V_110 , V_111 ;
struct V_112 * V_113 ;
unsigned long V_114 ;
unsigned long * V_64 ;
unsigned long V_115 ;
F_51 ( V_90 ) ;
for ( V_29 = V_116 ; V_29 ; V_29 = V_29 -> V_8 ) {
if ( ( V_90 >> 32 ) == ( V_29 -> V_36 -> V_42 >> 32 ) )
break;
}
if ( ! V_29 )
return NULL ;
V_110 = V_90 - V_29 -> V_36 -> V_42 ;
V_111 = V_110 + V_62 - 1 ;
if ( ( V_110 >= V_65 ) &&
( ( V_110 + V_62 - 1 ) < V_65 + V_66 ) ) {
V_90 = V_117 | ( V_110 - V_65 ) ;
return ( void T_13 * ) V_90 ;
}
if ( V_29 -> V_67 &&
V_110 >= ( unsigned long ) V_29 -> V_67 -> V_59 &&
V_111 < ( unsigned long ) V_29 -> V_67 -> V_59 + V_29 -> V_67 -> V_62 ) {
V_110 -= V_29 -> V_67 -> V_59 ;
V_111 -= V_29 -> V_67 -> V_59 ;
V_110 &= V_118 ;
V_62 = F_52 ( V_111 ) - V_110 ;
V_113 = F_53 ( V_62 , V_119 ) ;
if ( ! V_113 )
return NULL ;
V_64 = V_29 -> V_67 -> V_64 ;
for ( V_114 = ( unsigned long ) V_113 -> V_90 ;
V_110 <= V_111 ;
V_110 += V_120 , V_114 += V_120 ) {
V_115 = V_64 [ V_110 >> V_121 ] ;
if ( ! ( V_115 & 1 ) ) {
F_6 ( L_22 ) ;
F_54 ( V_113 -> V_90 ) ;
return NULL ;
}
V_115 >>= 1 ;
if ( F_55 ( V_114 ,
V_115 << V_121 ,
V_120 , 0 ) ) {
F_6 ( L_23 ) ;
F_54 ( V_113 -> V_90 ) ;
return NULL ;
}
}
F_56 () ;
V_114 = ( unsigned long ) V_113 -> V_90 + ( V_90 & ~ V_118 ) ;
return ( void T_13 * ) V_114 ;
}
V_114 = V_110 + V_29 -> V_36 -> V_42 ;
return ( void T_13 * ) V_114 ;
}
void
F_57 ( volatile void T_13 * V_122 )
{
unsigned long V_90 = ( unsigned long ) V_122 ;
if ( V_90 >= V_123 )
F_54 ( ( void * ) ( V_118 & V_90 ) ) ;
}
int
F_58 ( const volatile void T_13 * V_122 )
{
unsigned long V_90 = ( unsigned long ) V_122 ;
if ( V_90 >= V_123 )
return 1 ;
else
return ( V_90 & 0xFF000000UL ) == 0 ;
}
void T_13 * F_59 ( unsigned long V_90 )
{
F_60 ( V_90 ) ;
return ( void T_13 * ) V_90 ;
}
unsigned int
F_61 ( void T_13 * V_122 )
{
unsigned long V_90 = ( unsigned long ) V_122 ;
if ( F_62 ( V_90 ) )
return 0 ;
else if ( F_63 ( V_90 ) )
return F_47 ( 0 , V_90 , 0 ) ;
else if ( F_64 ( V_90 ) )
return F_39 ( * ( V_95 ) V_90 ) ;
else
return ~ 0 ;
}
void
F_65 ( T_6 V_107 , void T_13 * V_122 )
{
unsigned long V_90 = ( unsigned long ) V_122 ;
if ( F_62 ( V_90 ) )
return;
else if ( F_63 ( V_90 ) )
F_47 ( V_107 , V_90 , 1 ) ;
else if ( F_64 ( V_90 ) )
F_42 ( V_107 , * ( V_95 ) V_90 ) ;
}
int
F_66 ( unsigned long V_124 )
{
int V_125 ;
if ( ( V_124 >> 43 ) & 1 )
V_125 = ( ~ ( V_124 >> 35 ) & 0xff ) ;
else
V_125 = ( ( V_124 >> 34 ) & 0x3 ) | ( ( V_124 >> ( 37 - 2 ) ) & ( 0x1f << 2 ) ) ;
return F_22 ( V_125 ) ;
}
int
F_22 ( int V_125 )
{
return V_125 ;
}
unsigned long
F_67 ( int V_126 )
{
unsigned long V_124 ;
V_124 = ( V_126 & 0x3 ) | ( ( V_126 & ( 0x1f << 2 ) ) << 1 ) ;
V_124 <<= 34 ;
return V_124 ;
}
unsigned long
F_68 ( int V_126 )
{
return 16UL * 1024 * 1024 * 1024 ;
}
static int
F_69 ( T_14 * V_127 )
{
struct V_128 * V_129 ;
if ( ! V_130 )
return - V_131 ;
V_129 = F_70 ( sizeof( * V_129 ) , V_132 ) ;
if ( V_129 == NULL ) return - V_131 ;
V_129 -> V_133 = V_127 -> V_29 -> V_67 ;
V_129 -> V_134 = V_130 / V_120 ;
V_129 -> V_135 = F_71 ( V_129 -> V_133 , V_129 -> V_134 ,
V_129 -> V_134 - 1 ) ;
if ( V_129 -> V_135 < 0 ) {
F_6 ( V_16 L_24 ) ;
F_72 ( V_129 ) ;
return - V_131 ;
}
V_127 -> V_136 . V_137 =
V_129 -> V_133 -> V_59 + V_129 -> V_135 * V_120 ;
V_127 -> V_136 . V_62 = V_129 -> V_134 * V_120 ;
V_127 -> V_136 . V_34 = V_129 ;
return 0 ;
}
static void
F_73 ( T_14 * V_127 )
{
struct V_128 * V_129 = V_127 -> V_136 . V_34 ;
int V_138 ;
V_138 = F_74 ( V_129 -> V_133 , V_129 -> V_135 , V_129 -> V_134 ) ;
if ( V_138 == - V_139 ) {
F_6 ( V_12
L_25 ) ;
F_75 ( V_129 -> V_133 , V_129 -> V_135 , V_129 -> V_134 ) ;
V_138 = F_74 ( V_129 -> V_133 , V_129 -> V_135 ,
V_129 -> V_134 ) ;
}
if ( V_138 < 0 )
F_6 ( V_16 L_26 ) ;
F_72 ( V_129 ) ;
F_72 ( V_127 ) ;
}
static int
F_76 ( T_14 * V_127 )
{
T_3 * V_18 = ( (struct V_30 * ) V_127 -> V_29 -> V_34 ) -> V_18 ;
struct V_6 * V_6 = ( (struct V_30 * ) V_127 -> V_29 -> V_34 ) -> V_6 ;
unsigned int V_140 = 0 ;
unsigned long V_141 ;
V_141 = V_6 -> V_18 -> V_142 [ V_143 ] . V_20 ;
switch( F_77 ( V_141 ) ) {
case 0x4 :
if ( V_127 -> V_84 . V_144 . V_145 != 2 )
V_140 = 2 ;
break;
case 0x6 :
if ( V_127 -> V_84 . V_144 . V_145 == 2 )
V_140 = 1 ;
break;
default:
F_6 ( L_27 ,
V_146 , F_77 ( V_141 ) , V_141 ) ;
break;
}
if ( V_140 ) {
F_6 ( L_28
L_29 ,
V_127 -> V_84 . V_144 . V_145 ,
V_140 ) ;
V_127 -> V_84 . V_144 . V_145 = V_140 ;
}
F_6 ( L_30 ,
V_127 -> V_29 -> V_32 , V_127 -> V_84 . V_144 . V_145 ,
V_127 -> V_84 . V_144 . V_147 ? L_31 : L_32 , V_127 -> V_84 . V_144 . V_148 ) ;
V_18 -> V_149 . V_20 = V_127 -> V_84 . V_150 ;
return 0 ;
}
static int
F_78 ( T_14 * V_127 , T_15 V_135 , struct V_151 * V_152 )
{
struct V_128 * V_129 = V_127 -> V_136 . V_34 ;
return F_79 ( V_129 -> V_133 , V_129 -> V_135 + V_135 ,
V_152 -> V_153 , V_152 -> V_154 ) ;
}
static int
F_80 ( T_14 * V_127 , T_15 V_135 , struct V_151 * V_152 )
{
struct V_128 * V_129 = V_127 -> V_136 . V_34 ;
return F_75 ( V_129 -> V_133 , V_129 -> V_135 + V_135 ,
V_152 -> V_153 ) ;
}
static unsigned long
F_81 ( T_14 * V_127 , T_8 V_90 )
{
struct V_128 * V_129 = V_127 -> V_136 . V_34 ;
unsigned long V_110 = V_90 - V_129 -> V_133 -> V_59 ;
unsigned long V_155 ;
if ( V_90 < V_127 -> V_136 . V_137 ||
V_90 >= V_127 -> V_136 . V_137 + V_127 -> V_136 . V_62 ) {
F_6 ( L_33 , V_146 ) ;
return - V_156 ;
}
V_155 = V_129 -> V_133 -> V_64 [ V_110 >> V_121 ] ;
if ( ! ( V_155 & 1 ) ) {
F_6 ( L_34 , V_146 ) ;
return - V_156 ;
}
return ( V_155 >> 1 ) << V_121 ;
}
T_14 *
F_82 ( void )
{
struct V_28 * V_29 ;
T_3 * V_18 ;
T_14 * V_127 ;
struct V_6 * V_6 ;
V_29 = NULL ;
for ( V_6 = NULL ; ( V_6 = F_3 ( V_6 ) ) != NULL ; ) {
struct V_28 * V_11 ;
V_97 V_90 ;
if ( ! V_6 -> V_14 [ V_143 ] . V_15 )
continue;
V_11 = V_6 -> V_14 [ V_143 ] . V_29 ;
V_90 = ( V_97 ) F_34 ( V_11 , 0 , F_36 ( 5 , 0 ) , 0 ) ;
if ( * V_90 != 0xffffffffu ) {
V_29 = V_11 ;
break;
}
}
if ( ! V_29 || ! V_29 -> V_67 )
return NULL ;
F_6 ( L_35 , V_29 -> V_32 ) ;
V_18 = ( (struct V_30 * ) V_29 -> V_34 ) -> V_18 ;
V_127 = F_70 ( sizeof( * V_127 ) , V_132 ) ;
if ( ! V_127 )
return NULL ;
V_127 -> V_29 = V_29 ;
V_127 -> V_157 = NULL ;
V_127 -> V_158 = & V_159 ;
V_127 -> V_136 . V_137 = 0 ;
V_127 -> V_136 . V_62 = 0 ;
V_127 -> V_136 . V_34 = NULL ;
V_127 -> V_160 . V_150 = V_18 -> V_161 . V_20 ;
V_127 -> V_160 . V_144 . V_148 = 0xf ;
V_127 -> V_84 . V_150 = V_18 -> V_149 . V_20 ;
return V_127 ;
}
