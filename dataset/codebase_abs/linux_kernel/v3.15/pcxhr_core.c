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
F_3 ( & V_2 -> V_11 -> V_12 ,
L_1 ,
V_3 , V_7 ) ;
return 0 ;
}
V_7 ++ ;
} while ( F_4 ( V_8 , V_9 ) );
F_5 ( & V_2 -> V_11 -> V_12 ,
L_2 ,
V_3 , V_4 , * V_6 ) ;
return - V_13 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_14 , int V_15 )
{
int V_16 ;
unsigned char V_3 ;
if ( V_14 & V_17 ) {
F_7 ( V_2 , V_18 ,
F_8 ( V_2 , V_18 ) &
~ V_19 ) ;
}
if ( ( V_14 & V_20 ) == 0 ) {
V_3 = ( V_21 |
V_22 |
V_23 ) ;
if ( V_14 & V_24 )
V_3 |= V_25 ;
if ( V_14 & V_26 )
V_3 |= V_27 ;
F_9 ( V_2 , V_28 , V_3 ) ;
}
V_3 = ( unsigned char ) ( ( ( V_14 & V_29 ) >> 1 ) |
V_30 ) ;
F_9 ( V_2 , V_31 , V_3 ) ;
if ( V_14 & V_32 ) {
if ( V_15 )
F_10 ( V_33 ) ;
else
F_11 ( V_33 ) ;
}
if ( V_14 & V_34 ) {
if ( V_15 )
F_10 ( V_35 ) ;
else
F_11 ( V_33 ) ;
}
V_16 = F_1 ( V_2 , V_31 , V_30 , 0 ,
V_36 , & V_3 ) ;
if ( V_16 ) {
F_5 ( & V_2 -> V_11 -> V_12 , L_3 ) ;
return V_16 ;
}
if ( V_14 & V_17 ) {
V_16 = F_1 ( V_2 , V_18 ,
V_19 ,
V_19 ,
V_36 ,
& V_3 ) ;
if ( V_16 ) {
F_5 ( & V_2 -> V_11 -> V_12 ,
L_4 ) ;
return V_16 ;
}
}
return 0 ;
}
void F_12 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_37 ,
V_38 & ~ V_39 ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_40 )
{
unsigned int V_3 = F_8 ( V_2 , V_41 ) ;
if ( V_40 )
V_3 |= ( V_42 | V_43 ) ;
else
V_3 &= ~ ( V_42 | V_43 ) ;
F_7 ( V_2 , V_41 , V_3 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
F_13 ( V_2 , 0 ) ;
F_9 ( V_2 , V_44 , 0 ) ;
F_11 ( V_45 ) ;
F_9 ( V_2 , V_44 , 3 ) ;
F_11 ( V_45 ) ;
F_7 ( V_2 , V_18 , 0 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
F_13 ( V_2 , 1 ) ;
}
int F_16 ( struct V_1 * V_2 ,
const struct V_46 * V_47 , int V_48 )
{
unsigned int V_7 ;
unsigned int V_49 ;
unsigned char V_50 ;
unsigned char V_4 ;
const unsigned char * V_51 ;
V_49 = F_8 ( V_2 , V_37 ) ;
if( V_48 ) {
if ( ( V_49 & V_52 ) == 0 ) {
F_5 ( & V_2 -> V_11 -> V_12 , L_5 ) ;
return - V_53 ;
}
V_49 |= V_39 ;
F_7 ( V_2 , V_37 , V_49 ) ;
F_11 ( V_45 ) ;
}
V_51 = V_47 -> V_50 ;
for ( V_7 = 0 ; V_7 < V_47 -> V_54 ; V_7 ++ , V_51 ++ ) {
V_50 = * V_51 ;
V_4 = 0x80 ;
while ( V_4 ) {
V_49 &= ~ ( V_55 |
V_56 ) ;
if ( V_50 & V_4 )
V_49 |= V_56 ;
F_7 ( V_2 , V_37 , V_49 ) ;
V_49 |= V_55 ;
F_7 ( V_2 , V_37 , V_49 ) ;
V_4 >>= 1 ;
}
F_17 () ;
}
V_49 &= ~ ( V_55 | V_56 ) ;
F_7 ( V_2 , V_37 , V_49 ) ;
F_11 ( V_45 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , const struct V_46 * V_57 )
{
int V_16 ;
unsigned int V_7 ;
unsigned int V_58 ;
const unsigned char * V_50 ;
unsigned char V_59 ;
if ( V_57 -> V_54 <= 0 )
return - V_53 ;
if ( V_57 -> V_54 % 3 )
return - V_53 ;
if ( F_19 ( ! V_57 -> V_50 ) )
return - V_53 ;
for ( V_7 = 0 ; V_7 < V_57 -> V_54 ; V_7 += 3 ) {
V_50 = V_57 -> V_50 + V_7 ;
if ( V_7 == 0 ) {
V_58 = ( unsigned int ) ( ( V_50 [ 0 ] << 16 ) +
( V_50 [ 1 ] << 8 ) +
V_50 [ 2 ] ) ;
if ( V_58 && ( V_57 -> V_54 != ( V_58 + 2 ) * 3 ) )
return - V_53 ;
}
V_16 = F_1 ( V_2 , V_60 ,
V_61 ,
V_61 ,
V_36 , & V_59 ) ;
if ( V_16 ) {
F_5 ( & V_2 -> V_11 -> V_12 ,
L_6 , V_7 ) ;
return V_16 ;
}
F_9 ( V_2 , V_62 , V_50 [ 0 ] ) ;
F_9 ( V_2 , V_63 , V_50 [ 1 ] ) ;
F_9 ( V_2 , V_64 , V_50 [ 2 ] ) ;
F_17 () ;
}
F_11 ( V_45 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 ,
const struct V_46 * V_65 )
{
int V_16 ;
unsigned char V_3 ;
V_3 = V_21 | V_22 | V_23 ;
if ( F_8 ( V_2 , V_18 ) & V_66 ) {
F_9 ( V_2 , V_28 , V_3 | V_67 ) ;
F_11 ( V_45 ) ;
F_9 ( V_2 , V_28 , V_3 ) ;
F_11 ( V_45 ) ;
F_3 ( & V_2 -> V_11 -> V_12 , L_7 ) ;
return 0 ;
}
F_9 ( V_2 , V_28 , V_3 ) ;
V_16 = F_18 ( V_2 , V_65 ) ;
if ( V_16 )
return V_16 ;
return F_1 ( V_2 , V_60 , V_68 ,
V_68 , V_36 , & V_3 ) ;
}
int F_21 ( struct V_1 * V_2 , const struct V_46 * V_69 )
{
int V_16 ;
unsigned int V_70 = V_2 -> V_71 . V_72 ;
unsigned char V_59 ;
if ( F_19 ( V_70 & 0xff ) )
return - V_53 ;
F_7 ( V_2 , V_73 , ( V_70 >> 8 ) ) ;
V_16 = F_6 ( V_2 , V_74 , 0 ) ;
if ( V_16 )
return V_16 ;
F_7 ( V_2 , V_18 ,
F_8 ( V_2 , V_18 ) & ~ V_19 ) ;
V_16 = F_18 ( V_2 , V_69 ) ;
if ( V_16 )
return V_16 ;
return F_1 ( V_2 , V_18 , V_19 ,
V_19 , V_36 , & V_59 ) ;
}
int F_22 ( struct V_1 * V_2 , const struct V_46 * V_57 )
{
int V_16 ;
unsigned char V_59 ;
V_16 = F_6 ( V_2 , V_75 , 0 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_6 ( V_2 , V_76 , 0 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_18 ( V_2 , V_57 ) ;
if ( V_16 )
return V_16 ;
return F_1 ( V_2 , V_60 ,
V_68 ,
V_68 ,
V_36 , & V_59 ) ;
}
static int F_23 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
int V_16 ;
int V_7 ;
T_1 V_50 ;
T_1 V_79 ;
unsigned char V_3 ;
int V_80 ;
if ( V_78 -> V_81 < V_82 )
V_80 = V_82 ;
else V_80 = V_78 -> V_81 ;
for ( V_7 = 0 ; V_7 < V_78 -> V_81 ; V_7 ++ ) {
V_16 = F_1 ( V_2 , V_60 ,
V_83 ,
V_83 ,
V_36 , & V_3 ) ;
if ( V_16 ) {
F_5 ( & V_2 -> V_11 -> V_12 ,
L_8 ,
V_3 , V_7 ) ;
return V_16 ;
}
V_50 = F_2 ( V_2 , V_62 ) << 16 ;
V_50 |= F_2 ( V_2 , V_63 ) << 8 ;
V_50 |= F_2 ( V_2 , V_64 ) ;
if ( ! V_7 ) {
if ( V_78 -> V_84 != V_85 ) {
if ( V_78 -> V_84 == V_86 ) {
V_78 -> V_81 = ( V_50 & 0x0000ff ) + 1 ;
V_50 &= 0xffff00 ;
} else {
V_78 -> V_81 = 1 ;
V_79 = V_50 ;
while ( V_79 ) {
if ( V_79 & 1 )
V_78 -> V_81 ++ ;
V_79 >>= 1 ;
}
}
}
}
#ifdef F_24
if ( V_78 -> V_87 < V_88 )
F_3 ( & V_2 -> V_11 -> V_12 , L_9 , V_7 , V_50 ) ;
#endif
if ( V_7 < V_80 )
V_78 -> V_89 [ V_7 ] = V_50 ;
}
if ( V_78 -> V_81 > V_80 ) {
F_3 ( & V_2 -> V_11 -> V_12 , L_10 ,
V_78 -> V_81 ) ;
V_78 -> V_81 = V_80 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
int V_16 ;
int V_7 ;
T_1 V_50 ;
unsigned char V_3 ;
if ( F_19 ( V_78 -> V_90 >= V_91 ) )
return - V_53 ;
V_16 = F_6 ( V_2 , V_92 , 1 ) ;
if ( V_16 ) {
F_5 ( & V_2 -> V_11 -> V_12 ,
L_11 ) ;
return V_16 ;
}
V_16 = F_1 ( V_2 , V_60 , V_68 ,
V_68 , V_36 , & V_3 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_6 ( V_2 , V_93 , 1 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_1 ( V_2 , V_60 , V_68 , 0 ,
V_36 , & V_3 ) ;
if ( V_16 )
return V_16 ;
V_50 = V_78 -> V_94 [ 0 ] ;
if ( V_78 -> V_90 > 1 )
V_50 |= 0x008000 ;
else
V_50 &= 0xff7fff ;
#ifdef F_24
if ( V_78 -> V_87 < V_88 )
F_3 ( & V_2 -> V_11 -> V_12 , L_12 ,
V_50 , V_95 [ V_78 -> V_87 ] ) ;
#endif
V_16 = F_1 ( V_2 , V_60 , V_61 ,
V_61 , V_36 , & V_3 ) ;
if ( V_16 )
return V_16 ;
F_9 ( V_2 , V_62 , ( V_50 >> 16 ) & 0xFF ) ;
F_9 ( V_2 , V_63 , ( V_50 >> 8 ) & 0xFF ) ;
F_9 ( V_2 , V_64 , ( V_50 & 0xFF ) ) ;
if ( V_78 -> V_90 > 1 ) {
V_50 = V_78 -> V_90 - 1 ;
V_16 = F_1 ( V_2 , V_60 ,
V_61 ,
V_61 ,
V_36 , & V_3 ) ;
if ( V_16 )
return V_16 ;
F_9 ( V_2 , V_62 , ( V_50 >> 16 ) & 0xFF ) ;
F_9 ( V_2 , V_63 , ( V_50 >> 8 ) & 0xFF ) ;
F_9 ( V_2 , V_64 , ( V_50 & 0xFF ) ) ;
for ( V_7 = 1 ; V_7 < V_78 -> V_90 ; V_7 ++ ) {
V_50 = V_78 -> V_94 [ V_7 ] ;
#ifdef F_24
if ( V_78 -> V_87 < V_88 )
F_3 ( & V_2 -> V_11 -> V_12 ,
L_13 , V_7 , V_50 ) ;
#endif
V_16 = F_1 ( V_2 , V_60 ,
V_61 ,
V_61 ,
V_36 , & V_3 ) ;
if ( V_16 )
return V_16 ;
F_9 ( V_2 , V_62 , ( V_50 >> 16 ) & 0xFF ) ;
F_9 ( V_2 , V_63 , ( V_50 >> 8 ) & 0xFF ) ;
F_9 ( V_2 , V_64 , ( V_50 & 0xFF ) ) ;
}
}
V_16 = F_1 ( V_2 , V_60 , V_68 ,
V_68 , V_36 , & V_3 ) ;
if ( V_16 )
return V_16 ;
if ( V_3 & V_96 ) {
V_16 = F_1 ( V_2 , V_60 ,
V_83 ,
V_83 ,
V_36 , & V_3 ) ;
if ( V_16 ) {
F_5 ( & V_2 -> V_11 -> V_12 ,
L_14 , V_3 ) ;
return V_16 ;
}
V_50 = F_2 ( V_2 , V_62 ) << 16 ;
V_50 |= F_2 ( V_2 , V_63 ) << 8 ;
V_50 |= F_2 ( V_2 , V_64 ) ;
F_5 ( & V_2 -> V_11 -> V_12 , L_15 ,
V_78 -> V_87 , V_50 ) ;
V_16 = - V_53 ;
} else {
V_16 = F_23 ( V_2 , V_78 ) ;
}
if ( F_6 ( V_2 , V_97 , 1 ) < 0 )
return - V_13 ;
return V_16 ;
}
void F_26 ( struct V_77 * V_78 , int V_94 )
{
if ( F_19 ( V_94 >= V_88 ) )
return;
V_78 -> V_94 [ 0 ] = V_98 [ V_94 ] . V_99 ;
V_78 -> V_90 = 1 ;
V_78 -> V_81 = V_98 [ V_94 ] . V_100 ;
V_78 -> V_84 = V_98 [ V_94 ] . V_101 ;
V_78 -> V_87 = V_94 ;
}
void F_27 ( struct V_77 * V_78 , int V_102 ,
unsigned int V_103 , unsigned int V_104 ,
unsigned int V_105 )
{
F_19 ( V_103 > V_106 ) ;
if ( V_102 )
V_78 -> V_94 [ 0 ] |= 0x800 ;
if ( V_103 )
V_78 -> V_94 [ 0 ] |= ( V_103 << V_107 ) ;
if ( V_104 ) {
F_19 ( V_104 > V_106 ) ;
V_78 -> V_94 [ 0 ] |= V_104 ;
}
if( V_105 ) {
F_19 ( V_105 > V_108 ) ;
V_78 -> V_94 [ 1 ] = V_105 ;
V_78 -> V_90 = 2 ;
}
}
int F_28 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
unsigned long V_109 ;
int V_16 ;
F_29 ( & V_2 -> V_110 , V_109 ) ;
V_16 = F_25 ( V_2 , V_78 ) ;
F_30 ( & V_2 -> V_110 , V_109 ) ;
return V_16 ;
}
static inline int F_31 ( struct V_1 * V_2 )
{
int V_111 = F_8 ( V_2 , V_112 ) ;
V_111 &= 0xffffff ;
F_3 ( & V_2 -> V_11 -> V_12 , L_16 , V_111 ) ;
return V_111 ;
}
static int F_32 ( struct V_1 * V_2 ,
int V_113 , int * V_114 )
{
struct V_77 V_78 ;
int V_16 ;
int V_115 = 0 ;
* V_114 = 0 ;
while ( V_113 ) {
if ( V_113 & 1 ) {
F_26 ( & V_78 , V_116 ) ;
if ( V_115 < V_117 ) {
F_27 ( & V_78 , 0 , V_115 , 0 , 0 ) ;
} else {
F_27 ( & V_78 , 1 , V_115 -
V_117 ,
0 , 0 ) ;
}
V_16 = F_28 ( V_2 , & V_78 ) ;
if ( V_16 ) {
F_5 ( & V_2 -> V_11 -> V_12 ,
L_17
L_18 ,
V_16 ) ;
return V_16 ;
}
if ( V_78 . V_89 [ 0 ] == 0 )
* V_114 |= ( 1 << V_115 ) ;
}
V_113 >>= 1 ;
V_115 ++ ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , int V_113 )
{
struct V_77 V_78 ;
int V_16 ;
int V_115 = 0 ;
while ( V_113 ) {
if ( V_113 & 1 ) {
F_26 ( & V_78 , V_118 ) ;
if ( V_115 < V_117 ) {
F_27 ( & V_78 , 0 , V_115 , 0 , 0 ) ;
} else {
F_27 ( & V_78 , 1 , V_115 -
V_117 ,
0 , 0 ) ;
}
V_16 = F_28 ( V_2 , & V_78 ) ;
if ( V_16 ) {
F_5 ( & V_2 -> V_11 -> V_12 ,
L_19
L_20 , V_16 ) ;
return V_16 ;
}
}
V_113 >>= 1 ;
V_115 ++ ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , int V_113 )
{
struct V_77 V_78 ;
int V_16 ;
int V_115 = 0 ;
while ( V_113 ) {
if ( V_113 & 1 ) {
F_26 ( & V_78 , V_119 ) ;
if ( V_115 < V_117 )
F_27 ( & V_78 , 0 , 0 , 0 ,
1 << V_115 ) ;
else
F_27 ( & V_78 , 1 , 0 , 0 ,
1 << ( V_115 - V_117 ) ) ;
V_16 = F_28 ( V_2 , & V_78 ) ;
if ( V_16 ) {
F_5 ( & V_2 -> V_11 -> V_12 ,
L_17
L_21 , V_16 ) ;
return V_16 ;
}
}
V_113 >>= 1 ;
V_115 ++ ;
}
F_26 ( & V_78 , V_120 ) ;
V_16 = F_28 ( V_2 , & V_78 ) ;
if ( V_16 ) {
F_5 ( & V_2 -> V_11 -> V_12 ,
L_22 ,
V_16 ) ;
return V_16 ;
}
return 0 ;
}
int F_35 ( struct V_1 * V_2 , int V_121 ,
int V_122 , int V_123 )
{
int V_124 , V_7 , V_16 ;
int V_113 ;
#ifdef F_24
struct V_125 V_126 , V_127 ;
F_36 ( & V_126 ) ;
#endif
V_113 = ( V_121 |
( V_122 << V_117 ) ) ;
V_124 = F_31 ( V_2 ) ;
F_3 ( & V_2 -> V_11 -> V_12 ,
L_23 ,
V_123 ? L_24 : L_25 , V_113 , V_124 ) ;
if ( V_123 ) {
V_113 &= ~ V_124 ;
V_124 = V_113 ;
for ( V_7 = 0 ; V_7 < V_128 ; V_7 ++ ) {
V_16 = F_32 ( V_2 , V_124 , & V_124 ) ;
if ( V_16 )
return V_16 ;
if ( V_124 == 0 )
break;
F_10 ( 1 ) ;
}
} else {
V_113 &= V_124 ;
}
if ( V_113 == 0 )
return 0 ;
V_16 = F_34 ( V_2 , V_113 ) ;
if ( V_16 )
return V_16 ;
V_7 = 0 ;
while ( 1 ) {
V_124 = F_31 ( V_2 ) ;
if ( ( V_124 & V_113 ) == ( V_123 ? V_113 : 0 ) )
break;
if ( ++ V_7 >= V_128 * 100 ) {
F_5 ( & V_2 -> V_11 -> V_12 , L_26 ) ;
return - V_129 ;
}
F_37 ( 10 ) ;
}
if ( ! V_123 ) {
V_16 = F_33 ( V_2 , V_113 ) ;
if ( V_16 )
return V_16 ;
}
#ifdef F_24
F_36 ( & V_127 ) ;
F_3 ( & V_2 -> V_11 -> V_12 , L_27 ,
( long ) ( V_127 . V_130 - V_126 . V_130 ) , V_16 ) ;
#endif
return 0 ;
}
int F_38 ( struct V_1 * V_2 , unsigned int V_4 ,
unsigned int V_131 , int * V_132 )
{
struct V_77 V_78 ;
unsigned long V_109 ;
int V_16 ;
F_29 ( & V_2 -> V_110 , V_109 ) ;
if ( ( V_2 -> V_133 & V_4 ) == V_131 ) {
F_3 ( & V_2 -> V_11 -> V_12 ,
L_28 ,
V_4 , V_131 ) ;
if ( V_132 )
* V_132 = 0 ;
F_30 ( & V_2 -> V_110 , V_109 ) ;
return 0 ;
}
F_26 ( & V_78 , V_134 ) ;
V_78 . V_94 [ 0 ] |= V_135 ;
V_78 . V_94 [ 1 ] = V_4 ;
V_78 . V_94 [ 2 ] = V_131 ;
V_78 . V_90 = 3 ;
V_16 = F_25 ( V_2 , & V_78 ) ;
if ( V_16 == 0 ) {
V_2 -> V_133 &= ~ V_4 ;
V_2 -> V_133 |= V_131 ;
if ( V_132 )
* V_132 = 1 ;
}
F_30 ( & V_2 -> V_110 , V_109 ) ;
return V_16 ;
}
static int F_39 ( struct V_1 * V_2 , T_1 V_16 ,
enum V_136 V_137 , int V_138 ,
int V_139 )
{
static char * V_140 [] = {
[ V_141 ] = L_29 ,
[ V_142 ] = L_30 ,
[ V_143 ] = L_31
} ;
if ( V_16 & 0xfff )
V_16 &= 0xfff ;
else
V_16 = ( ( V_16 >> 12 ) & 0xfff ) ;
if ( ! V_16 )
return 0 ;
F_3 ( & V_2 -> V_11 -> V_12 , L_32 ,
V_140 [ V_137 ] ,
V_139 ? L_33 : L_34 , V_138 , V_16 ) ;
if ( V_16 == 0xe01 )
V_2 -> V_144 ++ ;
else if ( V_16 == 0xe10 )
V_2 -> V_145 ++ ;
else
V_2 -> V_146 = ( int ) V_16 ;
return 1 ;
}
void F_40 ( unsigned long V_147 )
{
struct V_1 * V_2 = (struct V_1 * ) ( V_147 ) ;
struct V_77 * V_148 = V_2 -> V_148 ;
int V_16 ;
int V_7 , V_149 ;
if ( V_2 -> V_150 & V_151 )
F_3 ( & V_2 -> V_11 -> V_12 ,
L_35 ) ;
if ( V_2 -> V_150 & V_152 )
F_3 ( & V_2 -> V_11 -> V_12 ,
L_36 ) ;
if ( V_2 -> V_150 & V_153 )
F_3 ( & V_2 -> V_11 -> V_12 ,
L_37 ) ;
if ( V_2 -> V_150 & ( V_151 | V_152 ) ) {
F_26 ( V_148 , V_154 ) ;
V_16 = F_28 ( V_2 , V_148 ) ;
F_3 ( & V_2 -> V_11 -> V_12 , L_38 ,
V_16 , V_148 -> V_89 [ 0 ] ) ;
}
if ( V_2 -> V_150 & V_155 ) {
F_3 ( & V_2 -> V_11 -> V_12 ,
L_39 ) ;
F_26 ( V_148 , V_156 ) ;
V_148 -> V_94 [ 0 ] |= 1 ;
V_148 -> V_81 = V_157 ;
V_16 = F_28 ( V_2 , V_148 ) ;
if ( V_16 )
F_5 ( & V_2 -> V_11 -> V_12 , L_40 ,
V_16 ) ;
V_7 = 1 ;
while ( V_7 < V_148 -> V_81 ) {
int V_158 = ( ( V_148 -> V_89 [ V_7 ] >> V_107 ) &
V_106 ) ;
int V_159 = ( ( V_148 -> V_89 [ V_7 ] >> ( 2 * V_107 ) ) &
V_106 ) ;
int V_138 = V_148 -> V_89 [ V_7 ] & V_106 ;
int V_139 = V_148 -> V_89 [ V_7 ] & 0x400000 ;
T_1 V_160 ;
if ( V_148 -> V_89 [ V_7 ] & 0x800000 ) {
F_3 ( & V_2 -> V_11 -> V_12 ,
L_41 ,
V_139 ? L_33 : L_34 ,
V_138 ) ;
}
V_7 ++ ;
V_160 = V_148 -> V_89 [ V_7 ] ? V_148 -> V_89 [ V_7 ] : V_148 -> V_89 [ V_7 + 1 ] ;
if ( V_160 )
F_39 ( V_2 , V_160 ,
V_141 ,
V_138 , V_139 ) ;
V_7 += 2 ;
for ( V_149 = 0 ; V_149 < V_159 ; V_149 ++ ) {
V_160 = V_148 -> V_89 [ V_7 ] ?
V_148 -> V_89 [ V_7 ] : V_148 -> V_89 [ V_7 + 1 ] ;
if ( V_160 )
F_39 ( V_2 , V_160 ,
V_142 ,
V_138 ,
V_139 ) ;
V_7 += 2 ;
}
for ( V_149 = 0 ; V_149 < V_158 ; V_149 ++ ) {
V_160 = V_148 -> V_89 [ V_7 ] ?
V_148 -> V_89 [ V_7 ] : V_148 -> V_89 [ V_7 + 1 ] ;
if ( V_160 )
F_39 ( V_2 , V_160 ,
V_143 ,
V_138 ,
V_139 ) ;
V_7 += 2 ;
}
}
}
}
static T_2 F_41 ( struct V_1 * V_2 ,
struct V_161 * V_162 )
{
T_2 V_163 ;
struct V_77 V_78 ;
int V_16 , V_164 ;
V_164 = V_162 -> V_138 -> V_139 ? 1 : 1 << V_162 -> V_165 -> V_166 ;
F_26 ( & V_78 , V_167 ) ;
F_27 ( & V_78 , V_162 -> V_138 -> V_139 ,
V_162 -> V_138 -> V_168 , 0 , V_164 ) ;
V_16 = F_28 ( V_2 , & V_78 ) ;
if ( V_16 )
return 0 ;
V_163 = ( ( T_2 ) V_78 . V_89 [ 0 ] ) << 24 ;
V_163 += ( T_2 ) V_78 . V_89 [ 1 ] ;
F_3 ( & V_2 -> V_11 -> V_12 ,
L_42 ,
V_162 -> V_138 -> V_139 ? 'C' : 'P' ,
V_162 -> V_165 -> V_166 ,
V_163 ,
V_162 -> V_169 + V_162 -> V_170 +
V_2 -> V_171 ) ;
return V_163 ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_161 * V_162 ,
int V_172 )
{
if ( V_162 -> V_165 &&
( V_162 -> V_173 == V_174 ) ) {
T_2 V_175 ;
int V_176 = 0 ;
int V_177 = 0 ;
struct V_178 * V_179 = V_162 -> V_165 -> V_179 ;
if ( V_172 < 0 ) {
V_162 -> V_180 = 0 ;
V_172 = V_2 -> V_171 ;
}
if ( ! V_162 -> V_180 ) {
if ( ( V_162 -> V_169 != 0 ) ||
( ( V_162 -> V_170 + V_172 ) >=
V_179 -> V_181 ) ) {
V_175 =
F_41 ( V_2 , V_162 ) ;
V_177 = 1 ;
if ( V_175 >= V_2 -> V_171 ) {
V_175 -= V_2 -> V_171 ;
V_162 -> V_180 = 1 ;
}
}
}
if ( ! V_177 ) {
V_175 = V_162 -> V_169 +
V_162 -> V_170 + V_172 ;
}
while ( 1 ) {
T_2 V_182 = V_162 -> V_169 +
V_179 -> V_181 ;
if ( V_182 > V_175 )
break;
V_176 = 1 ;
V_162 -> V_183 ++ ;
if ( V_162 -> V_183 >= V_179 -> V_184 )
V_162 -> V_183 = 0 ;
V_162 -> V_169 = V_182 ;
}
if ( V_175 >= V_162 -> V_169 ) {
V_162 -> V_170 =
( V_185 ) ( V_175 -
V_162 -> V_169 ) ;
} else {
F_5 ( & V_2 -> V_11 -> V_12 ,
L_43 ,
( long unsigned int ) V_175 ) ;
}
if ( V_176 ) {
F_43 ( & V_2 -> V_186 ) ;
F_44 ( V_162 -> V_165 ) ;
F_45 ( & V_2 -> V_186 ) ;
}
}
}
T_3 F_46 ( int V_187 , void * V_188 )
{
struct V_1 * V_2 = V_188 ;
unsigned int V_3 ;
int V_7 , V_149 ;
struct V_189 * V_190 ;
F_45 ( & V_2 -> V_186 ) ;
V_3 = F_8 ( V_2 , V_41 ) ;
if ( ! ( V_3 & V_191 ) ) {
F_43 ( & V_2 -> V_186 ) ;
return V_192 ;
}
V_3 = F_8 ( V_2 , V_193 ) ;
F_7 ( V_2 , V_193 , V_3 ) ;
if ( V_3 & V_194 ) {
int V_195 = V_3 & V_194 ;
int V_196 =
F_8 ( V_2 , V_197 ) & V_198 ;
int V_199 = V_196 - V_2 -> V_200 ;
if ( ( V_199 < 0 ) &&
( V_2 -> V_200 != V_201 ) ) {
int V_202 = V_199 + V_198 + 1 ;
F_3 ( & V_2 -> V_11 -> V_12 ,
L_44 ,
V_2 -> V_200 , V_196 ) ;
if ( V_202 > 0 && V_202 <= ( 2 * V_2 -> V_171 ) ) {
F_3 ( & V_2 -> V_11 -> V_12 ,
L_45
L_46 , V_202 ) ;
V_199 = V_202 ;
} else {
F_3 ( & V_2 -> V_11 -> V_12 ,
L_47 ) ;
V_2 -> V_203 ++ ;
}
}
#ifdef F_24
if ( V_199 == 0 )
F_3 ( & V_2 -> V_11 -> V_12 ,
L_48 ,
V_196 ) ;
else if ( V_199 >= ( 2 * V_2 -> V_171 ) )
F_3 ( & V_2 -> V_11 -> V_12 ,
L_49 ,
V_2 -> V_200 ,
V_196 - V_2 -> V_200 ) ;
else if ( V_199 % V_2 -> V_171 )
F_3 ( & V_2 -> V_11 -> V_12 ,
L_50 ,
V_199 ) ;
#endif
V_2 -> V_200 = V_196 ;
if ( V_195 == V_2 -> V_195 ) {
F_3 ( & V_2 -> V_11 -> V_12 , L_51 ) ;
V_2 -> V_203 ++ ;
}
V_2 -> V_195 = V_195 ;
V_3 &= ~ V_194 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_204 ; V_7 ++ ) {
V_190 = V_2 -> V_190 [ V_7 ] ;
for ( V_149 = 0 ; V_149 < V_190 -> V_205 ; V_149 ++ )
F_42 ( V_2 ,
& V_190 -> V_206 [ V_149 ] ,
V_199 ) ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_204 ; V_7 ++ ) {
V_190 = V_2 -> V_190 [ V_7 ] ;
for ( V_149 = 0 ; V_149 < V_190 -> V_207 ; V_149 ++ )
F_42 ( V_2 ,
& V_190 -> V_208 [ V_149 ] ,
V_199 ) ;
}
}
if ( V_3 & V_209 ) {
if ( V_3 & V_155 ) {
V_2 -> V_200 = V_201 ;
}
V_2 -> V_150 = V_3 ;
F_47 ( & V_2 -> V_210 ) ;
}
#ifdef F_24
if ( V_3 & V_211 )
F_3 ( & V_2 -> V_11 -> V_12 , L_52 , V_3 ) ;
#endif
F_43 ( & V_2 -> V_186 ) ;
return V_212 ;
}
