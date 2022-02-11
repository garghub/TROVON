static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned char V_4 , unsigned char V_5 , int time ,
unsigned char * V_6 )
{
int V_7 = 0 ;
unsigned long V_8 = V_9 + ( time * V_10 + 999 ) / 1000 ;
do {
* V_6 = F_2 ( V_2 , V_3 ) ;
if ( ( * V_6 & V_4 ) == V_5 ) {
if ( V_7 > 100 )
F_3 ( L_1
L_2 ,
V_3 , V_7 ) ;
return 0 ;
}
V_7 ++ ;
} while ( F_4 ( V_8 , V_9 ) );
F_5 ( V_11
L_3 ,
V_3 , V_4 , * V_6 ) ;
return - V_12 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_13 , int V_14 )
{
int V_15 ;
unsigned char V_3 ;
if ( V_13 & V_16 ) {
F_7 ( V_2 , V_17 ,
F_8 ( V_2 , V_17 ) &
~ V_18 ) ;
}
if ( ( V_13 & V_19 ) == 0 ) {
V_3 = ( V_20 |
V_21 |
V_22 ) ;
if ( V_13 & V_23 )
V_3 |= V_24 ;
if ( V_13 & V_25 )
V_3 |= V_26 ;
F_9 ( V_2 , V_27 , V_3 ) ;
}
V_3 = ( unsigned char ) ( ( ( V_13 & V_28 ) >> 1 ) |
V_29 ) ;
F_9 ( V_2 , V_30 , V_3 ) ;
if ( V_13 & V_31 ) {
if ( V_14 )
F_10 ( V_32 ) ;
else
F_11 ( V_32 ) ;
}
if ( V_13 & V_33 ) {
if ( V_14 )
F_10 ( V_34 ) ;
else
F_11 ( V_32 ) ;
}
V_15 = F_1 ( V_2 , V_30 , V_29 , 0 ,
V_35 , & V_3 ) ;
if ( V_15 ) {
F_5 ( V_11 L_4 ) ;
return V_15 ;
}
if ( V_13 & V_16 ) {
V_15 = F_1 ( V_2 , V_17 ,
V_18 ,
V_18 ,
V_35 ,
& V_3 ) ;
if ( V_15 ) {
F_5 ( V_11
L_5 ) ;
return V_15 ;
}
}
return 0 ;
}
void F_12 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_36 ,
V_37 & ~ V_38 ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_39 )
{
unsigned int V_3 = F_8 ( V_2 , V_40 ) ;
if ( V_39 )
V_3 |= ( V_41 | V_42 ) ;
else
V_3 &= ~ ( V_41 | V_42 ) ;
F_7 ( V_2 , V_40 , V_3 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
F_13 ( V_2 , 0 ) ;
F_9 ( V_2 , V_43 , 0 ) ;
F_11 ( V_44 ) ;
F_9 ( V_2 , V_43 , 3 ) ;
F_11 ( V_44 ) ;
F_7 ( V_2 , V_17 , 0 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
F_13 ( V_2 , 1 ) ;
}
int F_16 ( struct V_1 * V_2 ,
const struct V_45 * V_46 , int V_47 )
{
unsigned int V_7 ;
unsigned int V_48 ;
unsigned char V_49 ;
unsigned char V_4 ;
const unsigned char * V_50 ;
V_48 = F_8 ( V_2 , V_36 ) ;
if( V_47 ) {
if ( ( V_48 & V_51 ) == 0 ) {
F_5 ( V_11 L_6 ) ;
return - V_52 ;
}
V_48 |= V_38 ;
F_7 ( V_2 , V_36 , V_48 ) ;
F_11 ( V_44 ) ;
}
V_50 = V_46 -> V_49 ;
for ( V_7 = 0 ; V_7 < V_46 -> V_53 ; V_7 ++ , V_50 ++ ) {
V_49 = * V_50 ;
V_4 = 0x80 ;
while ( V_4 ) {
V_48 &= ~ ( V_54 |
V_55 ) ;
if ( V_49 & V_4 )
V_48 |= V_55 ;
F_7 ( V_2 , V_36 , V_48 ) ;
V_48 |= V_54 ;
F_7 ( V_2 , V_36 , V_48 ) ;
V_4 >>= 1 ;
}
F_17 () ;
}
V_48 &= ~ ( V_54 | V_55 ) ;
F_7 ( V_2 , V_36 , V_48 ) ;
F_11 ( V_44 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , const struct V_45 * V_56 )
{
int V_15 ;
unsigned int V_7 ;
unsigned int V_57 ;
const unsigned char * V_49 ;
unsigned char V_58 ;
if ( V_56 -> V_53 <= 0 )
return - V_52 ;
if ( V_56 -> V_53 % 3 )
return - V_52 ;
if ( F_19 ( ! V_56 -> V_49 ) )
return - V_52 ;
for ( V_7 = 0 ; V_7 < V_56 -> V_53 ; V_7 += 3 ) {
V_49 = V_56 -> V_49 + V_7 ;
if ( V_7 == 0 ) {
V_57 = ( unsigned int ) ( ( V_49 [ 0 ] << 16 ) +
( V_49 [ 1 ] << 8 ) +
V_49 [ 2 ] ) ;
if ( V_57 && ( V_56 -> V_53 != ( V_57 + 2 ) * 3 ) )
return - V_52 ;
}
V_15 = F_1 ( V_2 , V_59 ,
V_60 ,
V_60 ,
V_35 , & V_58 ) ;
if ( V_15 ) {
F_5 ( V_11
L_7 , V_7 ) ;
return V_15 ;
}
F_9 ( V_2 , V_61 , V_49 [ 0 ] ) ;
F_9 ( V_2 , V_62 , V_49 [ 1 ] ) ;
F_9 ( V_2 , V_63 , V_49 [ 2 ] ) ;
F_17 () ;
}
F_11 ( V_44 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 ,
const struct V_45 * V_64 )
{
int V_15 ;
unsigned char V_3 ;
V_3 = V_20 | V_21 | V_22 ;
if ( F_8 ( V_2 , V_17 ) & V_65 ) {
F_9 ( V_2 , V_27 , V_3 | V_66 ) ;
F_11 ( V_44 ) ;
F_9 ( V_2 , V_27 , V_3 ) ;
F_11 ( V_44 ) ;
F_3 ( L_8 ) ;
return 0 ;
}
F_9 ( V_2 , V_27 , V_3 ) ;
V_15 = F_18 ( V_2 , V_64 ) ;
if ( V_15 )
return V_15 ;
return F_1 ( V_2 , V_59 , V_67 ,
V_67 , V_35 , & V_3 ) ;
}
int F_21 ( struct V_1 * V_2 , const struct V_45 * V_68 )
{
int V_15 ;
unsigned int V_69 = V_2 -> V_70 . V_71 ;
unsigned char V_58 ;
if ( F_19 ( V_69 & 0xff ) )
return - V_52 ;
F_7 ( V_2 , V_72 , ( V_69 >> 8 ) ) ;
V_15 = F_6 ( V_2 , V_73 , 0 ) ;
if ( V_15 )
return V_15 ;
F_7 ( V_2 , V_17 ,
F_8 ( V_2 , V_17 ) & ~ V_18 ) ;
V_15 = F_18 ( V_2 , V_68 ) ;
if ( V_15 )
return V_15 ;
return F_1 ( V_2 , V_17 , V_18 ,
V_18 , V_35 , & V_58 ) ;
}
int F_22 ( struct V_1 * V_2 , const struct V_45 * V_56 )
{
int V_15 ;
unsigned char V_58 ;
V_15 = F_6 ( V_2 , V_74 , 0 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_6 ( V_2 , V_75 , 0 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_18 ( V_2 , V_56 ) ;
if ( V_15 )
return V_15 ;
return F_1 ( V_2 , V_59 ,
V_67 ,
V_67 ,
V_35 , & V_58 ) ;
}
static int F_23 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
int V_15 ;
int V_7 ;
T_1 V_49 ;
T_1 V_78 ;
unsigned char V_3 ;
int V_79 ;
if ( V_77 -> V_80 < V_81 )
V_79 = V_81 ;
else V_79 = V_77 -> V_80 ;
for ( V_7 = 0 ; V_7 < V_77 -> V_80 ; V_7 ++ ) {
V_15 = F_1 ( V_2 , V_59 ,
V_82 ,
V_82 ,
V_35 , & V_3 ) ;
if ( V_15 ) {
F_5 ( V_11 L_9
L_10 ,
V_3 , V_7 ) ;
return V_15 ;
}
V_49 = F_2 ( V_2 , V_61 ) << 16 ;
V_49 |= F_2 ( V_2 , V_62 ) << 8 ;
V_49 |= F_2 ( V_2 , V_63 ) ;
if ( ! V_7 ) {
if ( V_77 -> V_83 != V_84 ) {
if ( V_77 -> V_83 == V_85 ) {
V_77 -> V_80 = ( V_49 & 0x0000ff ) + 1 ;
V_49 &= 0xffff00 ;
} else {
V_77 -> V_80 = 1 ;
V_78 = V_49 ;
while ( V_78 ) {
if ( V_78 & 1 )
V_77 -> V_80 ++ ;
V_78 >>= 1 ;
}
}
}
}
#ifdef F_24
if ( V_77 -> V_86 < V_87 )
F_3 ( L_11 , V_7 , V_49 ) ;
#endif
if ( V_7 < V_79 )
V_77 -> V_88 [ V_7 ] = V_49 ;
}
if ( V_77 -> V_80 > V_79 ) {
F_3 ( L_12 ,
V_77 -> V_80 ) ;
V_77 -> V_80 = V_79 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
int V_15 ;
int V_7 ;
T_1 V_49 ;
unsigned char V_3 ;
if ( F_19 ( V_77 -> V_89 >= V_90 ) )
return - V_52 ;
V_15 = F_6 ( V_2 , V_91 , 1 ) ;
if ( V_15 ) {
F_5 ( V_11 L_13 ) ;
return V_15 ;
}
V_15 = F_1 ( V_2 , V_59 , V_67 ,
V_67 , V_35 , & V_3 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_6 ( V_2 , V_92 , 1 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_1 ( V_2 , V_59 , V_67 , 0 ,
V_35 , & V_3 ) ;
if ( V_15 )
return V_15 ;
V_49 = V_77 -> V_93 [ 0 ] ;
if ( V_77 -> V_89 > 1 )
V_49 |= 0x008000 ;
else
V_49 &= 0xff7fff ;
#ifdef F_24
if ( V_77 -> V_86 < V_87 )
F_3 ( L_14 ,
V_49 , V_94 [ V_77 -> V_86 ] ) ;
#endif
V_15 = F_1 ( V_2 , V_59 , V_60 ,
V_60 , V_35 , & V_3 ) ;
if ( V_15 )
return V_15 ;
F_9 ( V_2 , V_61 , ( V_49 >> 16 ) & 0xFF ) ;
F_9 ( V_2 , V_62 , ( V_49 >> 8 ) & 0xFF ) ;
F_9 ( V_2 , V_63 , ( V_49 & 0xFF ) ) ;
if ( V_77 -> V_89 > 1 ) {
V_49 = V_77 -> V_89 - 1 ;
V_15 = F_1 ( V_2 , V_59 ,
V_60 ,
V_60 ,
V_35 , & V_3 ) ;
if ( V_15 )
return V_15 ;
F_9 ( V_2 , V_61 , ( V_49 >> 16 ) & 0xFF ) ;
F_9 ( V_2 , V_62 , ( V_49 >> 8 ) & 0xFF ) ;
F_9 ( V_2 , V_63 , ( V_49 & 0xFF ) ) ;
for ( V_7 = 1 ; V_7 < V_77 -> V_89 ; V_7 ++ ) {
V_49 = V_77 -> V_93 [ V_7 ] ;
#ifdef F_24
if ( V_77 -> V_86 < V_87 )
F_3 ( L_15 , V_7 , V_49 ) ;
#endif
V_15 = F_1 ( V_2 , V_59 ,
V_60 ,
V_60 ,
V_35 , & V_3 ) ;
if ( V_15 )
return V_15 ;
F_9 ( V_2 , V_61 , ( V_49 >> 16 ) & 0xFF ) ;
F_9 ( V_2 , V_62 , ( V_49 >> 8 ) & 0xFF ) ;
F_9 ( V_2 , V_63 , ( V_49 & 0xFF ) ) ;
}
}
V_15 = F_1 ( V_2 , V_59 , V_67 ,
V_67 , V_35 , & V_3 ) ;
if ( V_15 )
return V_15 ;
if ( V_3 & V_95 ) {
V_15 = F_1 ( V_2 , V_59 ,
V_82 ,
V_82 ,
V_35 , & V_3 ) ;
if ( V_15 ) {
F_5 ( V_11 L_16 , V_3 ) ;
return V_15 ;
}
V_49 = F_2 ( V_2 , V_61 ) << 16 ;
V_49 |= F_2 ( V_2 , V_62 ) << 8 ;
V_49 |= F_2 ( V_2 , V_63 ) ;
F_5 ( V_11 L_17 ,
V_77 -> V_86 , V_49 ) ;
V_15 = - V_52 ;
} else {
V_15 = F_23 ( V_2 , V_77 ) ;
}
if ( F_6 ( V_2 , V_96 , 1 ) < 0 )
return - V_12 ;
return V_15 ;
}
void F_26 ( struct V_76 * V_77 , int V_93 )
{
if ( F_19 ( V_93 >= V_87 ) )
return;
V_77 -> V_93 [ 0 ] = V_97 [ V_93 ] . V_98 ;
V_77 -> V_89 = 1 ;
V_77 -> V_80 = V_97 [ V_93 ] . V_99 ;
V_77 -> V_83 = V_97 [ V_93 ] . V_100 ;
V_77 -> V_86 = V_93 ;
}
void F_27 ( struct V_76 * V_77 , int V_101 ,
unsigned int V_102 , unsigned int V_103 ,
unsigned int V_104 )
{
F_19 ( V_102 > V_105 ) ;
if ( V_101 )
V_77 -> V_93 [ 0 ] |= 0x800 ;
if ( V_102 )
V_77 -> V_93 [ 0 ] |= ( V_102 << V_106 ) ;
if ( V_103 ) {
F_19 ( V_103 > V_105 ) ;
V_77 -> V_93 [ 0 ] |= V_103 ;
}
if( V_104 ) {
F_19 ( V_104 > V_107 ) ;
V_77 -> V_93 [ 1 ] = V_104 ;
V_77 -> V_89 = 2 ;
}
}
int F_28 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
unsigned long V_108 ;
int V_15 ;
F_29 ( & V_2 -> V_109 , V_108 ) ;
V_15 = F_25 ( V_2 , V_77 ) ;
F_30 ( & V_2 -> V_109 , V_108 ) ;
return V_15 ;
}
static inline int F_31 ( struct V_1 * V_2 )
{
int V_110 = F_8 ( V_2 , V_111 ) ;
V_110 &= 0xffffff ;
F_3 ( L_18 , V_110 ) ;
return V_110 ;
}
static int F_32 ( struct V_1 * V_2 ,
int V_112 , int * V_113 )
{
struct V_76 V_77 ;
int V_15 ;
int V_114 = 0 ;
* V_113 = 0 ;
while ( V_112 ) {
if ( V_112 & 1 ) {
F_26 ( & V_77 , V_115 ) ;
if ( V_114 < V_116 ) {
F_27 ( & V_77 , 0 , V_114 , 0 , 0 ) ;
} else {
F_27 ( & V_77 , 1 , V_114 -
V_116 ,
0 , 0 ) ;
}
V_15 = F_28 ( V_2 , & V_77 ) ;
if ( V_15 ) {
F_5 ( V_11
L_19
L_20 ,
V_15 ) ;
return V_15 ;
}
if ( V_77 . V_88 [ 0 ] == 0 )
* V_113 |= ( 1 << V_114 ) ;
}
V_112 >>= 1 ;
V_114 ++ ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , int V_112 )
{
struct V_76 V_77 ;
int V_15 ;
int V_114 = 0 ;
while ( V_112 ) {
if ( V_112 & 1 ) {
F_26 ( & V_77 , V_117 ) ;
if ( V_114 < V_116 ) {
F_27 ( & V_77 , 0 , V_114 , 0 , 0 ) ;
} else {
F_27 ( & V_77 , 1 , V_114 -
V_116 ,
0 , 0 ) ;
}
V_15 = F_28 ( V_2 , & V_77 ) ;
if ( V_15 ) {
F_5 ( V_11
L_21
L_22 , V_15 ) ;
return V_15 ;
}
}
V_112 >>= 1 ;
V_114 ++ ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , int V_112 )
{
struct V_76 V_77 ;
int V_15 ;
int V_114 = 0 ;
while ( V_112 ) {
if ( V_112 & 1 ) {
F_26 ( & V_77 , V_118 ) ;
if ( V_114 < V_116 )
F_27 ( & V_77 , 0 , 0 , 0 ,
1 << V_114 ) ;
else
F_27 ( & V_77 , 1 , 0 , 0 ,
1 << ( V_114 - V_116 ) ) ;
V_15 = F_28 ( V_2 , & V_77 ) ;
if ( V_15 ) {
F_5 ( V_11
L_19
L_23 , V_15 ) ;
return V_15 ;
}
}
V_112 >>= 1 ;
V_114 ++ ;
}
F_26 ( & V_77 , V_119 ) ;
V_15 = F_28 ( V_2 , & V_77 ) ;
if ( V_15 ) {
F_5 ( V_11
L_24 ,
V_15 ) ;
return V_15 ;
}
return 0 ;
}
int F_35 ( struct V_1 * V_2 , int V_120 ,
int V_121 , int V_122 )
{
int V_123 , V_7 , V_15 ;
int V_112 ;
#ifdef F_24
struct V_124 V_125 , V_126 ;
F_36 ( & V_125 ) ;
#endif
V_112 = ( V_120 |
( V_121 << V_116 ) ) ;
V_123 = F_31 ( V_2 ) ;
F_3 ( L_25 ,
V_122 ? L_26 : L_27 , V_112 , V_123 ) ;
if ( V_122 ) {
V_112 &= ~ V_123 ;
V_123 = V_112 ;
for ( V_7 = 0 ; V_7 < V_127 ; V_7 ++ ) {
V_15 = F_32 ( V_2 , V_123 , & V_123 ) ;
if ( V_15 )
return V_15 ;
if ( V_123 == 0 )
break;
F_10 ( 1 ) ;
}
} else {
V_112 &= V_123 ;
}
if ( V_112 == 0 )
return 0 ;
V_15 = F_34 ( V_2 , V_112 ) ;
if ( V_15 )
return V_15 ;
V_7 = 0 ;
while ( 1 ) {
V_123 = F_31 ( V_2 ) ;
if ( ( V_123 & V_112 ) == ( V_122 ? V_112 : 0 ) )
break;
if ( ++ V_7 >= V_127 * 100 ) {
F_5 ( V_11 L_28 ) ;
return - V_128 ;
}
F_37 ( 10 ) ;
}
if ( ! V_122 ) {
V_15 = F_33 ( V_2 , V_112 ) ;
if ( V_15 )
return V_15 ;
}
#ifdef F_24
F_36 ( & V_126 ) ;
F_3 ( L_29 ,
( long ) ( V_126 . V_129 - V_125 . V_129 ) , V_15 ) ;
#endif
return 0 ;
}
int F_38 ( struct V_1 * V_2 , unsigned int V_4 ,
unsigned int V_130 , int * V_131 )
{
struct V_76 V_77 ;
unsigned long V_108 ;
int V_15 ;
F_29 ( & V_2 -> V_109 , V_108 ) ;
if ( ( V_2 -> V_132 & V_4 ) == V_130 ) {
F_3 ( L_30 ,
V_4 , V_130 ) ;
if ( V_131 )
* V_131 = 0 ;
F_30 ( & V_2 -> V_109 , V_108 ) ;
return 0 ;
}
F_26 ( & V_77 , V_133 ) ;
V_77 . V_93 [ 0 ] |= V_134 ;
V_77 . V_93 [ 1 ] = V_4 ;
V_77 . V_93 [ 2 ] = V_130 ;
V_77 . V_89 = 3 ;
V_15 = F_25 ( V_2 , & V_77 ) ;
if ( V_15 == 0 ) {
V_2 -> V_132 &= ~ V_4 ;
V_2 -> V_132 |= V_130 ;
if ( V_131 )
* V_131 = 1 ;
}
F_30 ( & V_2 -> V_109 , V_108 ) ;
return V_15 ;
}
static int F_39 ( struct V_1 * V_2 , T_1 V_15 ,
enum V_135 V_136 , int V_137 ,
int V_138 )
{
#ifdef F_24
static char * V_139 [] = {
[ V_140 ] = L_31 ,
[ V_141 ] = L_32 ,
[ V_142 ] = L_33
} ;
#endif
if ( V_15 & 0xfff )
V_15 &= 0xfff ;
else
V_15 = ( ( V_15 >> 12 ) & 0xfff ) ;
if ( ! V_15 )
return 0 ;
F_3 ( L_34 ,
V_139 [ V_136 ] ,
V_138 ? L_35 : L_36 , V_137 , V_15 ) ;
if ( V_15 == 0xe01 )
V_2 -> V_143 ++ ;
else if ( V_15 == 0xe10 )
V_2 -> V_144 ++ ;
else
V_2 -> V_145 = ( int ) V_15 ;
return 1 ;
}
void F_40 ( unsigned long V_146 )
{
struct V_1 * V_2 = (struct V_1 * ) ( V_146 ) ;
struct V_76 * V_147 = V_2 -> V_147 ;
int V_15 ;
int V_7 , V_148 ;
if ( V_2 -> V_149 & V_150 )
F_3 ( L_37 ) ;
if ( V_2 -> V_149 & V_151 )
F_3 ( L_38 ) ;
if ( V_2 -> V_149 & V_152 )
F_3 ( L_39 ) ;
if ( V_2 -> V_149 & ( V_150 | V_151 ) ) {
F_26 ( V_147 , V_153 ) ;
V_15 = F_28 ( V_2 , V_147 ) ;
F_3 ( L_40 ,
V_15 , V_147 -> V_88 [ 0 ] ) ;
}
if ( V_2 -> V_149 & V_154 ) {
F_3 ( L_41 ) ;
F_26 ( V_147 , V_155 ) ;
V_147 -> V_93 [ 0 ] |= 1 ;
V_147 -> V_80 = V_156 ;
V_15 = F_28 ( V_2 , V_147 ) ;
if ( V_15 )
F_5 ( V_11 L_42 ,
V_15 ) ;
V_7 = 1 ;
while ( V_7 < V_147 -> V_80 ) {
int V_157 = ( ( V_147 -> V_88 [ V_7 ] >> V_106 ) &
V_105 ) ;
int V_158 = ( ( V_147 -> V_88 [ V_7 ] >> ( 2 * V_106 ) ) &
V_105 ) ;
int V_137 = V_147 -> V_88 [ V_7 ] & V_105 ;
int V_138 = V_147 -> V_88 [ V_7 ] & 0x400000 ;
T_1 V_159 ;
if ( V_147 -> V_88 [ V_7 ] & 0x800000 ) {
F_3 ( L_43 ,
V_138 ? L_35 : L_36 ,
V_137 ) ;
}
V_7 ++ ;
V_159 = V_147 -> V_88 [ V_7 ] ? V_147 -> V_88 [ V_7 ] : V_147 -> V_88 [ V_7 + 1 ] ;
if ( V_159 )
F_39 ( V_2 , V_159 ,
V_140 ,
V_137 , V_138 ) ;
V_7 += 2 ;
for ( V_148 = 0 ; V_148 < V_158 ; V_148 ++ ) {
V_159 = V_147 -> V_88 [ V_7 ] ?
V_147 -> V_88 [ V_7 ] : V_147 -> V_88 [ V_7 + 1 ] ;
if ( V_159 )
F_39 ( V_2 , V_159 ,
V_141 ,
V_137 ,
V_138 ) ;
V_7 += 2 ;
}
for ( V_148 = 0 ; V_148 < V_157 ; V_148 ++ ) {
V_159 = V_147 -> V_88 [ V_7 ] ?
V_147 -> V_88 [ V_7 ] : V_147 -> V_88 [ V_7 + 1 ] ;
if ( V_159 )
F_39 ( V_2 , V_159 ,
V_142 ,
V_137 ,
V_138 ) ;
V_7 += 2 ;
}
}
}
}
static T_2 F_41 ( struct V_1 * V_2 ,
struct V_160 * V_161 )
{
T_2 V_162 ;
struct V_76 V_77 ;
int V_15 , V_163 ;
V_163 = V_161 -> V_137 -> V_138 ? 1 : 1 << V_161 -> V_164 -> V_165 ;
F_26 ( & V_77 , V_166 ) ;
F_27 ( & V_77 , V_161 -> V_137 -> V_138 ,
V_161 -> V_137 -> V_167 , 0 , V_163 ) ;
V_15 = F_28 ( V_2 , & V_77 ) ;
if ( V_15 )
return 0 ;
V_162 = ( ( T_2 ) V_77 . V_88 [ 0 ] ) << 24 ;
V_162 += ( T_2 ) V_77 . V_88 [ 1 ] ;
F_3 ( L_44 ,
V_161 -> V_137 -> V_138 ? 'C' : 'P' ,
V_161 -> V_164 -> V_165 ,
( long unsigned int ) V_162 ,
( long unsigned int ) ( V_161 -> V_168 +
V_161 -> V_169 +
V_2 -> V_170 ) ) ;
return V_162 ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_160 * V_161 ,
int V_171 )
{
if ( V_161 -> V_164 &&
( V_161 -> V_172 == V_173 ) ) {
T_2 V_174 ;
int V_175 = 0 ;
int V_176 = 0 ;
struct V_177 * V_178 = V_161 -> V_164 -> V_178 ;
if ( V_171 < 0 ) {
V_161 -> V_179 = 0 ;
V_171 = V_2 -> V_170 ;
}
if ( ! V_161 -> V_179 ) {
if ( ( V_161 -> V_168 != 0 ) ||
( ( V_161 -> V_169 + V_171 ) >=
V_178 -> V_180 ) ) {
V_174 =
F_41 ( V_2 , V_161 ) ;
V_176 = 1 ;
if ( V_174 >= V_2 -> V_170 ) {
V_174 -= V_2 -> V_170 ;
V_161 -> V_179 = 1 ;
}
}
}
if ( ! V_176 ) {
V_174 = V_161 -> V_168 +
V_161 -> V_169 + V_171 ;
}
while ( 1 ) {
T_2 V_181 = V_161 -> V_168 +
V_178 -> V_180 ;
if ( V_181 > V_174 )
break;
V_175 = 1 ;
V_161 -> V_182 ++ ;
if ( V_161 -> V_182 >= V_178 -> V_183 )
V_161 -> V_182 = 0 ;
V_161 -> V_168 = V_181 ;
}
if ( V_174 >= V_161 -> V_168 ) {
V_161 -> V_169 =
( V_184 ) ( V_174 -
V_161 -> V_168 ) ;
} else {
F_5 ( V_11
L_45 ,
( long unsigned int ) V_174 ) ;
}
if ( V_175 ) {
F_43 ( & V_2 -> V_185 ) ;
F_44 ( V_161 -> V_164 ) ;
F_45 ( & V_2 -> V_185 ) ;
}
}
}
T_3 F_46 ( int V_186 , void * V_187 )
{
struct V_1 * V_2 = V_187 ;
unsigned int V_3 ;
int V_7 , V_148 ;
struct V_188 * V_189 ;
F_45 ( & V_2 -> V_185 ) ;
V_3 = F_8 ( V_2 , V_40 ) ;
if ( ! ( V_3 & V_190 ) ) {
F_43 ( & V_2 -> V_185 ) ;
return V_191 ;
}
V_3 = F_8 ( V_2 , V_192 ) ;
F_7 ( V_2 , V_192 , V_3 ) ;
if ( V_3 & V_193 ) {
int V_194 = V_3 & V_193 ;
int V_195 =
F_8 ( V_2 , V_196 ) & V_197 ;
int V_198 = V_195 - V_2 -> V_199 ;
if ( ( V_198 < 0 ) &&
( V_2 -> V_199 != V_200 ) ) {
F_3 ( L_46
L_47 ,
V_2 -> V_199 , V_195 ) ;
V_2 -> V_201 ++ ;
}
#ifdef F_24
if ( V_198 == 0 )
F_3 ( L_48 ,
V_195 ) ;
else if ( V_198 >= ( 2 * V_2 -> V_170 ) )
F_3 ( L_49 ,
V_2 -> V_199 ,
V_195 - V_2 -> V_199 ) ;
else if ( V_198 % V_2 -> V_170 )
F_3 ( L_50 ,
V_198 ) ;
#endif
V_2 -> V_199 = V_195 ;
if ( V_194 == V_2 -> V_194 ) {
F_3 ( L_51 ) ;
V_2 -> V_201 ++ ;
}
V_2 -> V_194 = V_194 ;
V_3 &= ~ V_193 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_202 ; V_7 ++ ) {
V_189 = V_2 -> V_189 [ V_7 ] ;
for ( V_148 = 0 ; V_148 < V_189 -> V_203 ; V_148 ++ )
F_42 ( V_2 ,
& V_189 -> V_204 [ V_148 ] ,
V_198 ) ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_202 ; V_7 ++ ) {
V_189 = V_2 -> V_189 [ V_7 ] ;
for ( V_148 = 0 ; V_148 < V_189 -> V_205 ; V_148 ++ )
F_42 ( V_2 ,
& V_189 -> V_206 [ V_148 ] ,
V_198 ) ;
}
}
if ( V_3 & V_207 ) {
if ( V_3 & V_154 ) {
V_2 -> V_199 = V_200 ;
}
V_2 -> V_149 = V_3 ;
F_47 ( & V_2 -> V_208 ) ;
}
#ifdef F_24
if ( V_3 & V_209 )
F_3 ( L_52 , V_3 ) ;
#endif
F_43 ( & V_2 -> V_185 ) ;
return V_210 ;
}
