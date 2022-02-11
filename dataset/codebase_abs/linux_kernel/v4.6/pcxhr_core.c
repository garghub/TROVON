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
int V_16 ;
F_29 ( & V_2 -> V_109 ) ;
V_16 = F_25 ( V_2 , V_78 ) ;
F_30 ( & V_2 -> V_109 ) ;
return V_16 ;
}
static inline int F_31 ( struct V_1 * V_2 )
{
int V_110 = F_8 ( V_2 , V_111 ) ;
V_110 &= 0xffffff ;
F_3 ( & V_2 -> V_11 -> V_12 , L_16 , V_110 ) ;
return V_110 ;
}
static int F_32 ( struct V_1 * V_2 ,
int V_112 , int * V_113 )
{
struct V_77 V_78 ;
int V_16 ;
int V_114 = 0 ;
* V_113 = 0 ;
while ( V_112 ) {
if ( V_112 & 1 ) {
F_26 ( & V_78 , V_115 ) ;
if ( V_114 < V_116 ) {
F_27 ( & V_78 , 0 , V_114 , 0 , 0 ) ;
} else {
F_27 ( & V_78 , 1 , V_114 -
V_116 ,
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
* V_113 |= ( 1 << V_114 ) ;
}
V_112 >>= 1 ;
V_114 ++ ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , int V_112 )
{
struct V_77 V_78 ;
int V_16 ;
int V_114 = 0 ;
while ( V_112 ) {
if ( V_112 & 1 ) {
F_26 ( & V_78 , V_117 ) ;
if ( V_114 < V_116 ) {
F_27 ( & V_78 , 0 , V_114 , 0 , 0 ) ;
} else {
F_27 ( & V_78 , 1 , V_114 -
V_116 ,
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
V_112 >>= 1 ;
V_114 ++ ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , int V_112 )
{
struct V_77 V_78 ;
int V_16 ;
int V_114 = 0 ;
while ( V_112 ) {
if ( V_112 & 1 ) {
F_26 ( & V_78 , V_118 ) ;
if ( V_114 < V_116 )
F_27 ( & V_78 , 0 , 0 , 0 ,
1 << V_114 ) ;
else
F_27 ( & V_78 , 1 , 0 , 0 ,
1 << ( V_114 - V_116 ) ) ;
V_16 = F_28 ( V_2 , & V_78 ) ;
if ( V_16 ) {
F_5 ( & V_2 -> V_11 -> V_12 ,
L_17
L_21 , V_16 ) ;
return V_16 ;
}
}
V_112 >>= 1 ;
V_114 ++ ;
}
F_26 ( & V_78 , V_119 ) ;
V_16 = F_28 ( V_2 , & V_78 ) ;
if ( V_16 ) {
F_5 ( & V_2 -> V_11 -> V_12 ,
L_22 ,
V_16 ) ;
return V_16 ;
}
return 0 ;
}
int F_35 ( struct V_1 * V_2 , int V_120 ,
int V_121 , int V_122 )
{
int V_123 , V_7 , V_16 ;
int V_112 ;
#ifdef F_24
T_2 V_124 , V_125 , V_126 ;
V_124 = F_36 () ;
#endif
V_112 = ( V_120 |
( V_121 << V_116 ) ) ;
V_123 = F_31 ( V_2 ) ;
F_3 ( & V_2 -> V_11 -> V_12 ,
L_23 ,
V_122 ? L_24 : L_25 , V_112 , V_123 ) ;
if ( V_122 ) {
V_112 &= ~ V_123 ;
V_123 = V_112 ;
for ( V_7 = 0 ; V_7 < V_127 ; V_7 ++ ) {
V_16 = F_32 ( V_2 , V_123 , & V_123 ) ;
if ( V_16 )
return V_16 ;
if ( V_123 == 0 )
break;
F_10 ( 1 ) ;
}
} else {
V_112 &= V_123 ;
}
if ( V_112 == 0 )
return 0 ;
V_16 = F_34 ( V_2 , V_112 ) ;
if ( V_16 )
return V_16 ;
V_7 = 0 ;
while ( 1 ) {
V_123 = F_31 ( V_2 ) ;
if ( ( V_123 & V_112 ) == ( V_122 ? V_112 : 0 ) )
break;
if ( ++ V_7 >= V_127 * 100 ) {
F_5 ( & V_2 -> V_11 -> V_12 , L_26 ) ;
return - V_128 ;
}
F_37 ( 10 ) ;
}
if ( ! V_122 ) {
V_16 = F_33 ( V_2 , V_112 ) ;
if ( V_16 )
return V_16 ;
}
#ifdef F_24
V_125 = F_36 () ;
V_126 = F_38 ( V_125 , V_124 ) ;
F_3 ( & V_2 -> V_11 -> V_12 , L_27 ,
( long ) ( F_39 ( V_126 ) ) , V_16 ) ;
#endif
return 0 ;
}
int F_40 ( struct V_1 * V_2 , unsigned int V_4 ,
unsigned int V_129 , int * V_130 )
{
struct V_77 V_78 ;
int V_16 ;
F_29 ( & V_2 -> V_109 ) ;
if ( ( V_2 -> V_131 & V_4 ) == V_129 ) {
F_3 ( & V_2 -> V_11 -> V_12 ,
L_28 ,
V_4 , V_129 ) ;
if ( V_130 )
* V_130 = 0 ;
F_30 ( & V_2 -> V_109 ) ;
return 0 ;
}
F_26 ( & V_78 , V_132 ) ;
V_78 . V_94 [ 0 ] |= V_133 ;
V_78 . V_94 [ 1 ] = V_4 ;
V_78 . V_94 [ 2 ] = V_129 ;
V_78 . V_90 = 3 ;
V_16 = F_25 ( V_2 , & V_78 ) ;
if ( V_16 == 0 ) {
V_2 -> V_131 &= ~ V_4 ;
V_2 -> V_131 |= V_129 ;
if ( V_130 )
* V_130 = 1 ;
}
F_30 ( & V_2 -> V_109 ) ;
return V_16 ;
}
static int F_41 ( struct V_1 * V_2 , T_1 V_16 ,
enum V_134 V_135 , int V_136 ,
int V_137 )
{
static char * V_138 [] = {
[ V_139 ] = L_29 ,
[ V_140 ] = L_30 ,
[ V_141 ] = L_31
} ;
if ( V_16 & 0xfff )
V_16 &= 0xfff ;
else
V_16 = ( ( V_16 >> 12 ) & 0xfff ) ;
if ( ! V_16 )
return 0 ;
F_3 ( & V_2 -> V_11 -> V_12 , L_32 ,
V_138 [ V_135 ] ,
V_137 ? L_33 : L_34 , V_136 , V_16 ) ;
if ( V_16 == 0xe01 )
V_2 -> V_142 ++ ;
else if ( V_16 == 0xe10 )
V_2 -> V_143 ++ ;
else
V_2 -> V_144 = ( int ) V_16 ;
return 1 ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_77 * V_145 = V_2 -> V_145 ;
int V_16 ;
int V_7 , V_146 ;
if ( V_2 -> V_147 & V_148 )
F_3 ( & V_2 -> V_11 -> V_12 ,
L_35 ) ;
if ( V_2 -> V_147 & V_149 )
F_3 ( & V_2 -> V_11 -> V_12 ,
L_36 ) ;
if ( V_2 -> V_147 & V_150 )
F_3 ( & V_2 -> V_11 -> V_12 ,
L_37 ) ;
if ( V_2 -> V_147 & ( V_148 | V_149 ) ) {
F_26 ( V_145 , V_151 ) ;
V_16 = F_28 ( V_2 , V_145 ) ;
F_3 ( & V_2 -> V_11 -> V_12 , L_38 ,
V_16 , V_145 -> V_89 [ 0 ] ) ;
}
if ( V_2 -> V_147 & V_152 ) {
F_3 ( & V_2 -> V_11 -> V_12 ,
L_39 ) ;
F_26 ( V_145 , V_153 ) ;
V_145 -> V_94 [ 0 ] |= 1 ;
V_145 -> V_81 = V_154 ;
V_16 = F_28 ( V_2 , V_145 ) ;
if ( V_16 )
F_5 ( & V_2 -> V_11 -> V_12 , L_40 ,
V_16 ) ;
V_7 = 1 ;
while ( V_7 < V_145 -> V_81 ) {
int V_155 = ( ( V_145 -> V_89 [ V_7 ] >> V_107 ) &
V_106 ) ;
int V_156 = ( ( V_145 -> V_89 [ V_7 ] >> ( 2 * V_107 ) ) &
V_106 ) ;
int V_136 = V_145 -> V_89 [ V_7 ] & V_106 ;
int V_137 = V_145 -> V_89 [ V_7 ] & 0x400000 ;
T_1 V_157 ;
if ( V_145 -> V_89 [ V_7 ] & 0x800000 ) {
F_3 ( & V_2 -> V_11 -> V_12 ,
L_41 ,
V_137 ? L_33 : L_34 ,
V_136 ) ;
}
V_7 ++ ;
V_157 = V_145 -> V_89 [ V_7 ] ? V_145 -> V_89 [ V_7 ] : V_145 -> V_89 [ V_7 + 1 ] ;
if ( V_157 )
F_41 ( V_2 , V_157 ,
V_139 ,
V_136 , V_137 ) ;
V_7 += 2 ;
for ( V_146 = 0 ; V_146 < V_156 ; V_146 ++ ) {
V_157 = V_145 -> V_89 [ V_7 ] ?
V_145 -> V_89 [ V_7 ] : V_145 -> V_89 [ V_7 + 1 ] ;
if ( V_157 )
F_41 ( V_2 , V_157 ,
V_140 ,
V_136 ,
V_137 ) ;
V_7 += 2 ;
}
for ( V_146 = 0 ; V_146 < V_155 ; V_146 ++ ) {
V_157 = V_145 -> V_89 [ V_7 ] ?
V_145 -> V_89 [ V_7 ] : V_145 -> V_89 [ V_7 + 1 ] ;
if ( V_157 )
F_41 ( V_2 , V_157 ,
V_141 ,
V_136 ,
V_137 ) ;
V_7 += 2 ;
}
}
}
}
static T_3 F_43 ( struct V_1 * V_2 ,
struct V_158 * V_159 )
{
T_3 V_160 ;
struct V_77 V_78 ;
int V_16 , V_161 ;
V_161 = V_159 -> V_136 -> V_137 ? 1 : 1 << V_159 -> V_162 -> V_163 ;
F_26 ( & V_78 , V_164 ) ;
F_27 ( & V_78 , V_159 -> V_136 -> V_137 ,
V_159 -> V_136 -> V_165 , 0 , V_161 ) ;
V_16 = F_28 ( V_2 , & V_78 ) ;
if ( V_16 )
return 0 ;
V_160 = ( ( T_3 ) V_78 . V_89 [ 0 ] ) << 24 ;
V_160 += ( T_3 ) V_78 . V_89 [ 1 ] ;
F_3 ( & V_2 -> V_11 -> V_12 ,
L_42 ,
V_159 -> V_136 -> V_137 ? 'C' : 'P' ,
V_159 -> V_162 -> V_163 ,
V_160 ,
V_159 -> V_166 + V_159 -> V_167 +
V_2 -> V_168 ) ;
return V_160 ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_158 * V_159 ,
int V_169 )
{
if ( V_159 -> V_162 &&
( V_159 -> V_170 == V_171 ) ) {
T_3 V_172 ;
int V_173 = 0 ;
int V_174 = 0 ;
struct V_175 * V_176 = V_159 -> V_162 -> V_176 ;
if ( V_169 < 0 ) {
V_159 -> V_177 = 0 ;
V_169 = V_2 -> V_168 ;
}
if ( ! V_159 -> V_177 ) {
if ( ( V_159 -> V_166 != 0 ) ||
( ( V_159 -> V_167 + V_169 ) >=
V_176 -> V_178 ) ) {
V_172 =
F_43 ( V_2 , V_159 ) ;
V_174 = 1 ;
if ( V_172 >= V_2 -> V_168 ) {
V_172 -= V_2 -> V_168 ;
V_159 -> V_177 = 1 ;
}
}
}
if ( ! V_174 ) {
V_172 = V_159 -> V_166 +
V_159 -> V_167 + V_169 ;
}
while ( 1 ) {
T_3 V_179 = V_159 -> V_166 +
V_176 -> V_178 ;
if ( V_179 > V_172 )
break;
V_173 = 1 ;
V_159 -> V_180 ++ ;
if ( V_159 -> V_180 >= V_176 -> V_181 )
V_159 -> V_180 = 0 ;
V_159 -> V_166 = V_179 ;
}
if ( V_172 >= V_159 -> V_166 ) {
V_159 -> V_167 =
( V_182 ) ( V_172 -
V_159 -> V_166 ) ;
} else {
F_5 ( & V_2 -> V_11 -> V_12 ,
L_43 ,
( long unsigned int ) V_172 ) ;
}
if ( V_173 ) {
F_30 ( & V_2 -> V_183 ) ;
F_45 ( V_159 -> V_162 ) ;
F_29 ( & V_2 -> V_183 ) ;
}
}
}
T_4 F_46 ( int V_184 , void * V_185 )
{
struct V_1 * V_2 = V_185 ;
unsigned int V_3 ;
bool V_186 = false ;
V_3 = F_8 ( V_2 , V_41 ) ;
if ( ! ( V_3 & V_187 ) ) {
return V_188 ;
}
V_3 = F_8 ( V_2 , V_189 ) ;
F_7 ( V_2 , V_189 , V_3 ) ;
if ( V_3 & V_190 ) {
int V_191 = V_3 & V_190 ;
if ( V_191 == V_2 -> V_191 ) {
F_3 ( & V_2 -> V_11 -> V_12 , L_44 ) ;
V_2 -> V_192 ++ ;
}
V_2 -> V_191 = V_191 ;
V_2 -> V_147 = V_3 ;
V_186 = true ;
}
if ( V_3 & V_193 ) {
if ( V_3 & V_152 ) {
V_2 -> V_194 = V_195 ;
}
V_2 -> V_147 = V_3 ;
V_186 = true ;
}
#ifdef F_24
if ( V_3 & V_196 )
F_3 ( & V_2 -> V_11 -> V_12 , L_45 , V_3 ) ;
#endif
return V_186 ? V_197 : V_198 ;
}
T_4 F_47 ( int V_184 , void * V_185 )
{
struct V_1 * V_2 = V_185 ;
int V_7 , V_146 ;
struct V_199 * V_200 ;
F_29 ( & V_2 -> V_183 ) ;
if ( V_2 -> V_147 & V_190 ) {
int V_201 =
F_8 ( V_2 , V_202 ) & V_203 ;
int V_204 = V_201 - V_2 -> V_194 ;
if ( ( V_204 < 0 ) &&
( V_2 -> V_194 != V_195 ) ) {
int V_205 = V_204 + V_203 + 1 ;
F_3 ( & V_2 -> V_11 -> V_12 ,
L_46 ,
V_2 -> V_194 , V_201 ) ;
if ( V_205 > 0 && V_205 <= ( 2 * V_2 -> V_168 ) ) {
F_3 ( & V_2 -> V_11 -> V_12 ,
L_47
L_48 , V_205 ) ;
V_204 = V_205 ;
} else {
F_3 ( & V_2 -> V_11 -> V_12 ,
L_49 ) ;
V_2 -> V_192 ++ ;
}
}
#ifdef F_24
if ( V_204 == 0 )
F_3 ( & V_2 -> V_11 -> V_12 ,
L_50 ,
V_201 ) ;
else if ( V_204 >= ( 2 * V_2 -> V_168 ) )
F_3 ( & V_2 -> V_11 -> V_12 ,
L_51 ,
V_2 -> V_194 ,
V_201 - V_2 -> V_194 ) ;
else if ( V_204 % V_2 -> V_168 )
F_3 ( & V_2 -> V_11 -> V_12 ,
L_52 ,
V_204 ) ;
#endif
V_2 -> V_194 = V_201 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_206 ; V_7 ++ ) {
V_200 = V_2 -> V_200 [ V_7 ] ;
for ( V_146 = 0 ; V_146 < V_200 -> V_207 ; V_146 ++ )
F_44 ( V_2 ,
& V_200 -> V_208 [ V_146 ] ,
V_204 ) ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_206 ; V_7 ++ ) {
V_200 = V_2 -> V_200 [ V_7 ] ;
for ( V_146 = 0 ; V_146 < V_200 -> V_209 ; V_146 ++ )
F_44 ( V_2 ,
& V_200 -> V_210 [ V_146 ] ,
V_204 ) ;
}
}
F_42 ( V_2 ) ;
F_30 ( & V_2 -> V_183 ) ;
return V_198 ;
}
