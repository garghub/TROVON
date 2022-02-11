static char * F_1 ( char * V_1 , int V_2 )
{
int V_3 , V_4 , V_5 ;
V_5 = 0 ;
for ( V_3 = 0 ; V_3 < 4 ; ++ V_3 ) {
for ( V_4 = 0 ; V_4 < 8 ; ++ V_4 ) {
if ( V_2 & ( 1 << ( 31 - ( V_3 * 8 + V_4 ) ) ) )
V_1 [ V_5 ] = '1' ;
else
V_1 [ V_5 ] = '0' ;
V_5 ++ ;
}
if ( V_3 < 3 ) {
V_1 [ V_5 ] = ' ' ;
V_5 ++ ;
}
}
V_1 [ V_5 ] = '\0' ;
return V_1 ;
}
static void F_2 ( void * V_6 , unsigned char V_7 ,
unsigned char V_8 )
{
F_3 ( (struct V_9 * ) V_6 , V_10 ,
V_7 , V_8 ) ;
}
static unsigned char F_4 ( void * V_6 , unsigned char V_7 )
{
return F_5 ( (struct V_9 * ) V_6 ,
V_10 , V_7 ) ;
}
static void F_6 ( struct V_11 * V_12 , int V_13 ,
unsigned char V_14 , unsigned char V_15 )
{
unsigned int V_16 , V_17 ;
int V_18 ;
unsigned int V_19 ;
struct V_9 * V_20 = V_12 -> V_6 [ 0 ] ;
if ( F_7 ( V_13 < 0 || V_13 >= 4 ) )
return;
V_17 = V_20 -> V_21 . V_22 ( V_20 ) ;
V_20 -> V_21 . V_23 ( V_20 , V_17 | V_24 ) ;
V_20 -> V_21 . V_25 ( V_20 , ~ V_24 ) ;
V_16 = V_20 -> V_21 . V_26 ( V_20 ) ;
V_16 |= V_24 ;
V_20 -> V_21 . V_27 ( V_20 , V_16 ) ;
F_8 ( 100 ) ;
if ( V_13 )
V_16 &= ~ V_28 ;
else
V_16 &= ~ V_29 ;
V_20 -> V_21 . V_27 ( V_20 , V_16 ) ;
F_8 ( 100 ) ;
V_19 = ( V_30 << 6 ) | 0x20 | ( V_14 & 0x1f ) ;
V_19 = ( V_19 << 8 ) | V_15 ;
for ( V_18 = 15 ; V_18 >= 0 ; V_18 -- ) {
V_16 &= ~ V_31 ;
V_20 -> V_21 . V_27 ( V_20 , V_16 ) ;
F_8 ( 100 ) ;
if ( V_19 & ( 1 << V_18 ) )
V_16 |= V_32 ;
else
V_16 &= ~ V_32 ;
V_20 -> V_21 . V_27 ( V_20 , V_16 ) ;
F_8 ( 100 ) ;
V_16 |= V_31 ;
V_20 -> V_21 . V_27 ( V_20 , V_16 ) ;
F_8 ( 100 ) ;
}
V_16 |= V_24 ;
V_20 -> V_21 . V_27 ( V_20 , V_16 ) ;
F_8 ( 100 ) ;
V_20 -> V_21 . V_25 ( V_20 , 0xffffff ) ;
V_20 -> V_21 . V_23 ( V_20 , V_17 ) ;
}
static void F_9 ( struct V_11 * V_12 , unsigned char V_14 ,
unsigned char V_33 , unsigned char V_2 )
{
unsigned char V_16 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_12 -> V_34 ; V_13 ++ ) {
V_16 = F_10 ( V_12 , V_13 , V_14 ) ;
V_16 &= ~ V_33 ;
V_16 |= V_2 ;
F_11 ( V_12 , V_13 , V_14 , V_16 ) ;
}
}
static void F_12 ( struct V_11 * V_12 , unsigned int V_35 )
{
unsigned char V_36 ;
if ( V_35 == 0 )
return;
if ( V_35 > 108000 )
V_36 = V_37 | V_38 ;
else if ( V_35 > 54000 )
V_36 = V_39 | V_40 ;
else
V_36 = 0 ;
F_9 ( V_12 , V_41 , V_39 | V_37 |
V_40 | V_38 , V_36 ) ;
}
static void F_13 ( struct V_9 * V_20 , unsigned int V_7 ,
unsigned int V_15 )
{
unsigned int V_16 ;
F_14 ( & V_20 -> V_42 ) ;
V_16 = 0x00ffff ;
V_20 -> V_21 . V_23 ( V_20 , V_16 ) ;
V_20 -> V_21 . V_25 ( V_20 , ~ ( V_16 ) ) ;
V_16 = V_20 -> V_21 . V_26 ( V_20 ) ;
V_16 &= ~ V_43 ;
V_16 |= V_15 ;
V_20 -> V_21 . V_27 ( V_20 , V_16 ) ;
F_8 ( 100 ) ;
V_16 &= ~ V_44 ;
V_20 -> V_21 . V_27 ( V_20 , V_16 ) ;
F_8 ( 100 ) ;
V_16 &= ~ V_7 ;
V_20 -> V_21 . V_27 ( V_20 , V_16 ) ;
F_8 ( 100 ) ;
V_16 |= V_7 ;
V_20 -> V_21 . V_27 ( V_20 , V_16 ) ;
F_8 ( 100 ) ;
V_16 |= V_43 ;
V_20 -> V_21 . V_27 ( V_20 , V_16 ) ;
V_20 -> V_21 . V_25 ( V_20 , 0xffffff ) ;
V_20 -> V_21 . V_23 ( V_20 , 0x00ff00 ) ;
F_15 ( & V_20 -> V_42 ) ;
}
static unsigned int F_16 ( struct V_9 * V_20 )
{
struct V_45 * V_46 = V_20 -> V_46 ;
return V_46 -> V_47 ;
}
static unsigned int F_17 ( struct V_9 * V_20 )
{
struct V_45 * V_46 = V_20 -> V_46 ;
return V_46 -> V_48 ;
}
static unsigned int F_18 ( struct V_9 * V_20 )
{
struct V_45 * V_46 = V_20 -> V_46 ;
return V_46 -> V_49 ;
}
static void F_19 ( struct V_9 * V_20 , unsigned int V_8 )
{
struct V_45 * V_46 = V_20 -> V_46 ;
F_13 ( V_20 , V_50 , V_8 ) ;
V_46 -> V_47 = V_8 ;
}
static void F_20 ( struct V_9 * V_20 , unsigned int V_8 )
{
struct V_45 * V_46 = V_20 -> V_46 ;
F_13 ( V_20 , V_51 , V_8 ) ;
V_46 -> V_48 = V_8 ;
}
static void F_21 ( struct V_9 * V_20 , unsigned int V_8 )
{
struct V_45 * V_46 = V_20 -> V_46 ;
F_13 ( V_20 , V_52 , V_8 ) ;
V_46 -> V_49 = V_8 ;
}
static void F_22 ( struct V_53 * V_54 ,
struct V_55 * V_1 )
{
struct V_9 * V_20 = V_54 -> V_6 ;
char V_56 [ 36 ] ;
F_23 ( V_1 , L_1 , F_1 ( V_56 ,
F_16 ( V_20 ) ) ) ;
F_23 ( V_1 , L_2 , F_1 ( V_56 ,
F_17 ( V_20 ) ) ) ;
F_23 ( V_1 , L_3 , F_1 ( V_56 ,
F_18 ( V_20 ) ) ) ;
}
static void F_24 ( struct V_9 * V_20 )
{
struct V_53 * V_54 ;
if ( ! F_25 ( V_20 -> V_57 , L_4 , & V_54 ) )
F_26 ( V_54 , V_20 , F_22 ) ;
}
static void F_24 ( struct V_9 * V_20 ) {}
static int F_27 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_9 * V_20 = F_28 ( V_59 ) ;
unsigned int V_8 ;
V_8 = F_16 ( V_20 ) & V_62 ;
V_61 -> V_2 . integer . V_2 [ 0 ] = ( V_8 ) ? 0 : 1 ;
return 0 ;
}
static int F_29 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_9 * V_20 = F_28 ( V_59 ) ;
unsigned int V_63 , V_64 , V_65 ;
V_63 = F_16 ( V_20 ) & V_62 ;
if ( V_61 -> V_2 . integer . V_2 [ 0 ] ) {
V_64 = 0 ;
V_65 = 0 ;
} else {
V_64 = V_62 ;
V_65 = V_66 ;
}
if ( V_63 != V_64 ) {
struct V_11 * V_12 = V_20 -> V_67 ;
F_19 ( V_20 , ( F_16 ( V_20 ) & ~ V_62 ) | V_64 ) ;
F_9 ( V_12 , V_68 , V_66 , V_65 ) ;
return 1 ;
}
return 0 ;
}
static int F_30 ( struct V_58 * V_59 ,
struct V_69 * V_70 )
{
static const char * const V_71 [ 3 ] =
{ L_5 , L_6 , L_7 } ;
return F_31 ( V_70 , 1 , F_32 ( V_71 ) , V_71 ) ;
}
static int F_33 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_9 * V_20 = F_28 ( V_59 ) ;
unsigned int V_8 , V_72 ;
V_8 = F_16 ( V_20 ) & ( V_73 | V_74 ) ;
switch ( V_8 ) {
case V_75 :
V_72 = 0 ;
break;
case V_76 :
V_72 = 1 ;
break;
case V_77 :
V_72 = 2 ;
break;
default:
F_34 () ;
V_72 = 0 ;
}
V_61 -> V_2 . integer . V_2 [ 0 ] = V_72 ;
return 0 ;
}
static int F_35 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_9 * V_20 = F_28 ( V_59 ) ;
unsigned int V_63 , V_64 , V_16 , V_78 ;
V_63 = V_64 = F_16 ( V_20 ) ;
V_78 = V_63 & ( V_73 | V_74 ) ;
V_16 = V_61 -> V_2 . integer . V_2 [ 0 ] ;
if ( V_16 == 2 )
V_16 = 3 ;
V_16 <<= 4 ;
if ( V_16 != V_78 ) {
switch ( V_16 ) {
case V_75 :
V_64 = V_63 & ~ ( V_73 | V_74 ) ;
F_19 ( V_20 , V_64 ) ;
V_64 &= ~ V_79 ;
F_19 ( V_20 , V_64 ) ;
break;
case V_76 :
V_64 = V_63 | V_79 ;
F_19 ( V_20 , V_64 ) ;
V_64 = ( V_64 & ~ V_73 ) | V_74 ;
F_19 ( V_20 , V_64 ) ;
break;
case V_77 :
V_64 = V_63 | V_79 ;
F_19 ( V_20 , V_64 ) ;
V_64 |= V_73 | V_74 ;
F_19 ( V_20 , V_64 ) ;
break;
default:
F_34 () ;
}
return 1 ;
}
return 0 ;
}
static int F_36 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_9 * V_20 = F_28 ( V_59 ) ;
unsigned int V_8 ;
V_8 = F_16 ( V_20 ) & V_80 ;
V_61 -> V_2 . integer . V_2 [ 0 ] = V_8 ? 1 : 0 ;
return 0 ;
}
static int F_37 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_9 * V_20 = F_28 ( V_59 ) ;
unsigned int V_63 , V_64 ;
V_63 = V_64 = F_16 ( V_20 ) ;
if ( V_61 -> V_2 . integer . V_2 [ 0 ]
&& ( ~ V_63 & V_80 ) ) {
V_64 = V_63 | V_80 ;
F_19 ( V_20 , V_64 ) ;
V_64 &= ~ V_81 ;
F_19 ( V_20 , V_64 ) ;
} else if ( ! V_61 -> V_2 . integer . V_2 [ 0 ] && ( V_63 & V_80 ) ) {
V_64 = V_63 & ~ V_80 ;
F_19 ( V_20 , V_64 ) ;
V_64 |= V_81 ;
F_19 ( V_20 , V_64 ) ;
}
if ( V_63 != V_64 )
return 1 ;
return 0 ;
}
static int F_38 ( struct V_58 * V_59 ,
struct V_69 * V_70 )
{
struct V_82 V_83 =
V_84 [ V_59 -> V_85 ] ;
return F_31 ( V_70 , 1 , F_32 ( V_83 . V_71 ) ,
V_83 . V_71 ) ;
}
static int F_39 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_82 V_83 =
V_84 [ V_59 -> V_85 ] ;
struct V_9 * V_20 = F_28 ( V_59 ) ;
V_61 -> V_2 . integer . V_2 [ 0 ] =
( V_83 . V_86 ( V_20 ) & V_83 . V_87 ) ? 1 : 0 ;
return 0 ;
}
static int F_40 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_82 V_83 =
V_84 [ V_59 -> V_85 ] ;
struct V_9 * V_20 = F_28 ( V_59 ) ;
unsigned int V_63 , V_64 ;
V_63 = V_83 . V_86 ( V_20 ) ;
if ( V_61 -> V_2 . integer . V_2 [ 0 ] )
V_64 = V_63 | V_83 . V_87 ;
else
V_64 = V_63 & ~ V_83 . V_87 ;
if ( V_63 != V_64 ) {
V_83 . V_88 ( V_20 , V_64 ) ;
return 1 ;
}
return 0 ;
}
static struct V_58 * F_41 ( struct V_89 * V_57 ,
const char * V_90 )
{
struct V_91 V_92 ;
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
strcpy ( V_92 . V_90 , V_90 ) ;
V_92 . V_93 = V_94 ;
return F_42 ( V_57 , & V_92 ) ;
}
static void F_43 ( struct V_89 * V_57 ,
struct V_58 * V_95 , char * const * V_96 )
{
for (; * V_96 ; V_96 ++ ) {
struct V_58 * V_97 = F_41 ( V_57 , * V_96 ) ;
if ( V_97 )
F_44 ( V_95 , V_97 ) ;
}
}
static int F_45 ( struct V_9 * V_20 )
{
struct V_45 * V_46 = V_20 -> V_46 ;
int V_98 , V_3 ;
struct V_58 * V_99 ;
V_98 = F_46 ( V_20 ) ;
if ( V_98 < 0 )
return V_98 ;
for ( V_3 = 0 ; V_3 < F_32 ( V_100 ) ; V_3 ++ ) {
V_98 = F_47 ( V_20 -> V_57 ,
F_48 ( & V_100 [ V_3 ] , V_20 ) ) ;
if ( V_98 < 0 )
return V_98 ;
}
V_99 = F_49 ( L_8 ,
V_101 ) ;
if ( ! V_99 )
return - V_102 ;
F_43 ( V_20 -> V_57 , V_99 , V_103 ) ;
V_98 = F_47 ( V_20 -> V_57 , V_99 ) ;
if ( V_98 < 0 )
return V_98 ;
return F_50 ( V_46 -> V_104 ,
V_20 -> V_105 -> V_106 [ V_107 ] . V_108 ) ;
}
static inline int F_51 ( struct V_9 * V_20 )
{
return ( F_18 ( V_20 ) & V_109 ) ? 1 : 0 ;
}
static unsigned int F_52 ( struct V_9 * V_20 )
{
int V_3 ;
unsigned char V_72 ;
V_72 = F_18 ( V_20 ) & V_110 ;
for ( V_3 = 0 ; V_3 < F_32 ( V_111 ) ; V_3 ++ )
if ( V_111 [ V_3 ] == V_72 )
return V_112 [ V_3 ] ;
return 0 ;
}
static int F_53 ( int V_35 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_32 ( V_112 ) ; V_3 ++ )
if ( V_112 [ V_3 ] == V_35 )
return V_111 [ V_3 ] ;
return 0 ;
}
static void F_54 ( struct V_9 * V_20 , unsigned int V_35 )
{
unsigned int V_64 ;
unsigned char V_8 ;
V_8 = F_55 ( F_56 ( V_20 , V_113 ) ) ;
F_57 ( V_8 | V_114 , F_56 ( V_20 , V_113 ) ) ;
V_64 = ( F_18 ( V_20 ) & ~ V_110 ) | F_53 ( V_35 ) ;
V_64 &= ~ V_109 ;
F_21 ( V_20 , V_64 ) ;
}
static inline unsigned char F_58 ( struct V_9 * V_20 ,
unsigned int V_35 )
{
return 0 ;
}
static int F_59 ( struct V_9 * V_20 , int type )
{
unsigned int V_63 , V_64 ;
V_63 = V_64 = F_18 ( V_20 ) ;
V_64 &= ~ ( V_110 | V_115 ) ;
switch ( type ) {
case V_116 :
V_64 |= V_117 ;
break;
case V_118 :
V_64 |= V_119 ;
break;
case V_120 :
V_64 |= V_121 ;
break;
default:
F_34 () ;
}
if ( V_63 != V_64 ) {
F_21 ( V_20 , V_64 ) ;
return 1 ;
}
return 0 ;
}
static int F_60 ( struct V_9 * V_20 )
{
unsigned int V_8 ;
int V_72 ;
V_8 = F_18 ( V_20 ) ;
V_8 &= ( V_110 | V_115 | V_109 ) ;
if ( ! ( V_8 & V_109 ) ) {
V_72 = - 1 ;
} else {
switch ( V_8 ) {
case ( V_117 ) :
V_72 = V_116 ;
break;
case ( V_119 ) :
V_72 = V_118 ;
break;
case ( V_121 ) :
V_72 = V_120 ;
break;
default:
F_34 () ;
V_72 = 0 ;
}
}
return V_72 ;
}
static void F_61 ( struct V_104 * V_104 , unsigned char V_122 ,
unsigned char V_123 )
{
struct V_9 * V_20 = V_104 -> V_124 ;
int V_35 ;
if ( ( F_60 ( V_20 ) == V_116 ) &&
V_123 ) {
V_35 = F_62 ( V_104 ) ;
F_12 ( V_20 -> V_67 , V_35 ) ;
}
}
static void F_63 ( struct V_9 * V_20 ,
struct V_125 * V_108 )
{
struct V_45 * V_46 = V_20 -> V_46 ;
struct V_126 * V_127 = V_108 -> V_127 ;
int V_35 ;
if ( F_60 ( V_20 ) != V_116 )
return;
V_35 = F_62 ( V_46 -> V_104 ) ;
if ( V_35 >= V_127 -> V_128 . V_129 && V_35 <= V_127 -> V_128 . V_130 ) {
V_127 -> V_128 . V_129 = V_35 ;
V_127 -> V_128 . V_130 = V_35 ;
}
}
static int F_64 ( struct V_9 * V_20 )
{
static const unsigned char V_131 [] = {
V_132 | V_133 |
V_134 | V_135 ,
V_136 | V_137 |
V_138 | V_139 ,
V_140 | V_141 |
V_142 ,
V_143 | F_65 ( 0 ) ,
0 ,
0 ,
0 ,
} ;
int V_98 ;
struct V_45 * V_46 ;
struct V_11 * V_12 ;
unsigned char V_8 ;
V_8 = F_55 ( F_56 ( V_20 , V_113 ) ) ;
F_57 ( V_8 | V_114 , F_56 ( V_20 , V_113 ) ) ;
V_46 = F_66 ( sizeof( * V_46 ) , V_144 ) ;
if ( ! V_46 )
return - V_102 ;
V_20 -> V_145 = & V_146 ;
V_20 -> V_147 = F_51 ;
V_20 -> V_148 = F_52 ;
V_20 -> V_149 = F_54 ;
V_20 -> V_150 = F_58 ;
V_20 -> V_151 = F_59 ;
V_20 -> V_152 = F_60 ;
V_20 -> V_153 = V_153 ;
V_20 -> V_154 = F_32 ( V_153 ) ;
V_20 -> V_155 . V_156 . V_157 = V_20 -> V_158 = F_63 ;
V_20 -> V_46 = V_46 ;
F_19 ( V_20 , V_81 ) ;
F_8 ( 1 ) ;
F_19 ( V_20 , V_81 | V_159 ) ;
F_20 ( V_20 , 0 ) ;
F_21 ( V_20 , 0 ) ;
V_20 -> V_160 = 2 ;
V_20 -> V_161 = 2 ;
V_20 -> V_67 = F_67 ( 2 , sizeof( struct V_11 ) , V_144 ) ;
V_12 = V_20 -> V_67 ;
if ( ! V_12 )
return - V_102 ;
V_20 -> V_162 = 1 ;
V_98 = F_68 ( V_12 , & V_163 , NULL , V_20 ) ;
if ( V_98 < 0 )
return V_98 ;
V_98 = F_69 ( V_20 -> V_57 ,
F_4 ,
F_2 ,
V_131 ,
V_20 , & V_46 -> V_104 ) ;
if ( V_98 < 0 )
return V_98 ;
V_46 -> V_104 -> V_164 = F_61 ;
V_46 -> V_104 -> V_124 = V_20 ;
V_46 -> V_104 -> V_165 = 0 ;
F_24 ( V_20 ) ;
F_54 ( V_20 , 44100 ) ;
return 0 ;
}
