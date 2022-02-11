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
static char * V_71 [ 3 ] = { L_5 , L_6 , L_7 } ;
V_70 -> type = V_72 ;
V_70 -> V_73 = 1 ;
V_70 -> V_2 . V_74 . V_75 = F_31 ( V_71 ) ;
if ( V_70 -> V_2 . V_74 . V_76 >= V_70 -> V_2 . V_74 . V_75 )
V_70 -> V_2 . V_74 . V_76 =
V_70 -> V_2 . V_74 . V_75 - 1 ;
strcpy ( V_70 -> V_2 . V_74 . V_77 ,
V_71 [ V_70 -> V_2 . V_74 . V_76 ] ) ;
return 0 ;
}
static int F_32 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_9 * V_20 = F_28 ( V_59 ) ;
unsigned int V_8 , V_78 ;
V_8 = F_16 ( V_20 ) & ( V_79 | V_80 ) ;
switch ( V_8 ) {
case V_81 :
V_78 = 0 ;
break;
case V_82 :
V_78 = 1 ;
break;
case V_83 :
V_78 = 2 ;
break;
default:
F_33 () ;
V_78 = 0 ;
}
V_61 -> V_2 . integer . V_2 [ 0 ] = V_78 ;
return 0 ;
}
static int F_34 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_9 * V_20 = F_28 ( V_59 ) ;
unsigned int V_63 , V_64 , V_16 , V_84 ;
V_63 = V_64 = F_16 ( V_20 ) ;
V_84 = V_63 & ( V_79 | V_80 ) ;
V_16 = V_61 -> V_2 . integer . V_2 [ 0 ] ;
if ( V_16 == 2 )
V_16 = 3 ;
V_16 <<= 4 ;
if ( V_16 != V_84 ) {
switch ( V_16 ) {
case V_81 :
V_64 = V_63 & ~ ( V_79 | V_80 ) ;
F_19 ( V_20 , V_64 ) ;
V_64 &= ~ V_85 ;
F_19 ( V_20 , V_64 ) ;
break;
case V_82 :
V_64 = V_63 | V_85 ;
F_19 ( V_20 , V_64 ) ;
V_64 = ( V_64 & ~ V_79 ) | V_80 ;
F_19 ( V_20 , V_64 ) ;
break;
case V_83 :
V_64 = V_63 | V_85 ;
F_19 ( V_20 , V_64 ) ;
V_64 |= V_79 | V_80 ;
F_19 ( V_20 , V_64 ) ;
break;
default:
F_33 () ;
}
return 1 ;
}
return 0 ;
}
static int F_35 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_9 * V_20 = F_28 ( V_59 ) ;
unsigned int V_8 ;
V_8 = F_16 ( V_20 ) & V_86 ;
V_61 -> V_2 . integer . V_2 [ 0 ] = V_8 ? 1 : 0 ;
return 0 ;
}
static int F_36 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_9 * V_20 = F_28 ( V_59 ) ;
unsigned int V_63 , V_64 ;
V_63 = V_64 = F_16 ( V_20 ) ;
if ( V_61 -> V_2 . integer . V_2 [ 0 ]
&& ( ~ V_63 & V_86 ) ) {
V_64 = V_63 | V_86 ;
F_19 ( V_20 , V_64 ) ;
V_64 &= ~ V_87 ;
F_19 ( V_20 , V_64 ) ;
} else if ( ! V_61 -> V_2 . integer . V_2 [ 0 ] && ( V_63 & V_86 ) ) {
V_64 = V_63 & ~ V_86 ;
F_19 ( V_20 , V_64 ) ;
V_64 |= V_87 ;
F_19 ( V_20 , V_64 ) ;
}
if ( V_63 != V_64 )
return 1 ;
return 0 ;
}
static int F_37 ( struct V_58 * V_59 ,
struct V_69 * V_70 )
{
struct V_88 V_89 =
V_90 [ V_59 -> V_91 ] ;
V_70 -> type = V_72 ;
V_70 -> V_73 = 1 ;
V_70 -> V_2 . V_74 . V_75 = F_31 ( V_89 . V_71 ) ;
if ( V_70 -> V_2 . V_74 . V_76 >= V_70 -> V_2 . V_74 . V_75 )
V_70 -> V_2 . V_74 . V_76 =
V_70 -> V_2 . V_74 . V_75 - 1 ;
strcpy ( V_70 -> V_2 . V_74 . V_77 ,
V_89 . V_71 [ V_70 -> V_2 . V_74 . V_76 ] ) ;
return 0 ;
}
static int F_38 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_88 V_89 =
V_90 [ V_59 -> V_91 ] ;
struct V_9 * V_20 = F_28 ( V_59 ) ;
V_61 -> V_2 . integer . V_2 [ 0 ] =
( V_89 . V_92 ( V_20 ) & V_89 . V_93 ) ? 1 : 0 ;
return 0 ;
}
static int F_39 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_88 V_89 =
V_90 [ V_59 -> V_91 ] ;
struct V_9 * V_20 = F_28 ( V_59 ) ;
unsigned int V_63 , V_64 ;
V_63 = V_89 . V_92 ( V_20 ) ;
if ( V_61 -> V_2 . integer . V_2 [ 0 ] )
V_64 = V_63 | V_89 . V_93 ;
else
V_64 = V_63 & ~ V_89 . V_93 ;
if ( V_63 != V_64 ) {
V_89 . V_94 ( V_20 , V_64 ) ;
return 1 ;
}
return 0 ;
}
static struct V_58 T_1 * F_40 ( struct V_95 * V_57 ,
const char * V_77 )
{
struct V_96 V_97 ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
strcpy ( V_97 . V_77 , V_77 ) ;
V_97 . V_98 = V_99 ;
return F_41 ( V_57 , & V_97 ) ;
}
static void T_1 F_42 ( struct V_95 * V_57 ,
struct V_58 * V_100 , char * * V_101 )
{
for (; * V_101 ; V_101 ++ ) {
struct V_58 * V_102 = F_40 ( V_57 , * V_101 ) ;
if ( V_102 )
F_43 ( V_100 , V_102 ) ;
}
}
static int T_1 F_44 ( struct V_9 * V_20 )
{
struct V_45 * V_46 = V_20 -> V_46 ;
int V_103 , V_3 ;
struct V_58 * V_104 ;
V_103 = F_45 ( V_20 ) ;
if ( V_103 < 0 )
return V_103 ;
for ( V_3 = 0 ; V_3 < F_31 ( V_105 ) ; V_3 ++ ) {
V_103 = F_46 ( V_20 -> V_57 ,
F_47 ( & V_105 [ V_3 ] , V_20 ) ) ;
if ( V_103 < 0 )
return V_103 ;
}
V_104 = F_48 ( L_8 ,
V_106 ) ;
if ( ! V_104 )
return - V_107 ;
F_42 ( V_20 -> V_57 , V_104 , V_108 ) ;
V_103 = F_46 ( V_20 -> V_57 , V_104 ) ;
if ( V_103 < 0 )
return V_103 ;
V_103 = F_49 ( V_46 -> V_109 ,
V_20 -> V_110 -> V_111 [ V_112 ] . V_113 ) ;
if ( V_103 < 0 )
return V_103 ;
return 0 ;
}
static inline int F_50 ( struct V_9 * V_20 )
{
return ( F_18 ( V_20 ) & V_114 ) ? 1 : 0 ;
}
static unsigned int F_51 ( struct V_9 * V_20 )
{
int V_3 ;
unsigned char V_78 ;
V_78 = F_18 ( V_20 ) & V_115 ;
for ( V_3 = 0 ; V_3 < F_31 ( V_116 ) ; V_3 ++ )
if ( V_116 [ V_3 ] == V_78 )
return V_117 [ V_3 ] ;
return 0 ;
}
static int F_52 ( int V_35 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_31 ( V_117 ) ; V_3 ++ )
if ( V_117 [ V_3 ] == V_35 )
return V_116 [ V_3 ] ;
return 0 ;
}
static void F_53 ( struct V_9 * V_20 , unsigned int V_35 )
{
unsigned int V_64 ;
unsigned char V_8 ;
V_8 = F_54 ( F_55 ( V_20 , V_118 ) ) ;
F_56 ( V_8 | V_119 , F_55 ( V_20 , V_118 ) ) ;
V_64 = ( F_18 ( V_20 ) & ~ V_115 ) | F_52 ( V_35 ) ;
V_64 &= ~ V_114 ;
F_21 ( V_20 , V_64 ) ;
}
static inline unsigned char F_57 ( struct V_9 * V_20 ,
unsigned int V_35 )
{
return 0 ;
}
static int F_58 ( struct V_9 * V_20 , int type )
{
unsigned int V_63 , V_64 ;
V_63 = V_64 = F_18 ( V_20 ) ;
V_64 &= ~ ( V_115 | V_120 ) ;
switch ( type ) {
case V_121 :
V_64 |= V_122 ;
break;
case V_123 :
V_64 |= V_124 ;
break;
case V_125 :
V_64 |= V_126 ;
break;
default:
F_33 () ;
}
if ( V_63 != V_64 ) {
F_21 ( V_20 , V_64 ) ;
return 1 ;
}
return 0 ;
}
static int F_59 ( struct V_9 * V_20 )
{
unsigned int V_8 ;
int V_78 ;
V_8 = F_18 ( V_20 ) ;
V_8 &= ( V_115 | V_120 | V_114 ) ;
if ( ! ( V_8 & V_114 ) ) {
V_78 = - 1 ;
} else {
switch ( V_8 ) {
case ( V_122 ) :
V_78 = V_121 ;
break;
case ( V_124 ) :
V_78 = V_123 ;
break;
case ( V_126 ) :
V_78 = V_125 ;
break;
default:
F_33 () ;
V_78 = 0 ;
}
}
return V_78 ;
}
static void F_60 ( struct V_109 * V_109 , unsigned char V_127 ,
unsigned char V_128 )
{
struct V_9 * V_20 = V_109 -> V_129 ;
int V_35 ;
if ( ( F_59 ( V_20 ) == V_121 ) &&
V_128 ) {
V_35 = F_61 ( V_109 ) ;
F_12 ( V_20 -> V_67 , V_35 ) ;
}
}
static void F_62 ( struct V_9 * V_20 ,
struct V_130 * V_113 )
{
struct V_45 * V_46 = V_20 -> V_46 ;
struct V_131 * V_132 = V_113 -> V_132 ;
int V_35 ;
if ( F_59 ( V_20 ) != V_121 )
return;
V_35 = F_61 ( V_46 -> V_109 ) ;
if ( V_35 >= V_132 -> V_133 . V_134 && V_35 <= V_132 -> V_133 . V_135 ) {
V_132 -> V_133 . V_134 = V_35 ;
V_132 -> V_133 . V_135 = V_35 ;
}
}
static int T_1 F_63 ( struct V_9 * V_20 )
{
static const unsigned char V_136 [] = {
V_137 | V_138 |
V_139 | V_140 ,
V_141 | V_142 |
V_143 | V_144 ,
V_145 | V_146 |
V_147 ,
V_148 | F_64 ( 0 ) ,
0 ,
0 ,
0 ,
} ;
int V_103 ;
struct V_45 * V_46 ;
struct V_11 * V_12 ;
unsigned char V_8 ;
V_8 = F_54 ( F_55 ( V_20 , V_118 ) ) ;
F_56 ( V_8 | V_119 , F_55 ( V_20 , V_118 ) ) ;
V_46 = F_65 ( sizeof( * V_46 ) , V_149 ) ;
if ( ! V_46 )
return - V_107 ;
V_20 -> V_150 = & V_151 ;
V_20 -> V_152 = F_50 ;
V_20 -> V_153 = F_51 ;
V_20 -> V_154 = F_53 ;
V_20 -> V_155 = F_57 ;
V_20 -> V_156 = F_58 ;
V_20 -> V_157 = F_59 ;
V_20 -> V_158 = V_158 ;
V_20 -> V_159 = F_31 ( V_158 ) ;
V_20 -> V_160 . V_161 . V_162 = V_20 -> V_163 = F_62 ;
V_20 -> V_46 = V_46 ;
F_19 ( V_20 , V_87 ) ;
F_8 ( 1 ) ;
F_19 ( V_20 , V_87 | V_164 ) ;
F_20 ( V_20 , 0 ) ;
F_21 ( V_20 , 0 ) ;
V_20 -> V_165 = 2 ;
V_20 -> V_166 = 2 ;
V_20 -> V_67 = F_66 ( 2 , sizeof( struct V_11 ) , V_149 ) ;
V_12 = V_20 -> V_67 ;
if ( ! V_12 )
return - V_107 ;
V_20 -> V_167 = 1 ;
V_103 = F_67 ( V_12 , & V_168 , NULL , V_20 ) ;
if ( V_103 < 0 )
return V_103 ;
V_103 = F_68 ( V_20 -> V_57 ,
F_4 ,
F_2 ,
V_136 ,
V_20 , & V_46 -> V_109 ) ;
if ( V_103 < 0 )
return V_103 ;
V_46 -> V_109 -> V_169 = F_60 ;
V_46 -> V_109 -> V_129 = V_20 ;
V_46 -> V_109 -> V_170 = 0 ;
F_24 ( V_20 ) ;
F_53 ( V_20 , 44100 ) ;
return 0 ;
}
