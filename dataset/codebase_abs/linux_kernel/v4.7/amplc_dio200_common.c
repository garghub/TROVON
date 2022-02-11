static unsigned char F_1 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
return ( V_1 << 5 ) | ( V_2 << 3 ) |
( ( V_3 & 030 ) << 3 ) | ( V_3 & 007 ) ;
}
static unsigned char F_2 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
return F_1 ( V_1 , V_2 , V_3 ) ;
}
static unsigned char F_3 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
return F_1 ( V_1 , V_2 , V_3 ) ;
}
static unsigned char F_4 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
if ( V_8 -> V_10 )
V_6 <<= 3 ;
if ( V_5 -> V_11 )
return F_5 ( V_5 -> V_11 + V_6 ) ;
return F_6 ( V_5 -> V_12 + V_6 ) ;
}
static void F_7 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned char V_13 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
if ( V_8 -> V_10 )
V_6 <<= 3 ;
if ( V_5 -> V_11 )
F_8 ( V_13 , V_5 -> V_11 + V_6 ) ;
else
F_9 ( V_13 , V_5 -> V_12 + V_6 ) ;
}
static unsigned int F_10 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
if ( V_8 -> V_10 )
V_6 <<= 3 ;
if ( V_5 -> V_11 )
return F_11 ( V_5 -> V_11 + V_6 ) ;
return F_12 ( V_5 -> V_12 + V_6 ) ;
}
static void F_13 ( struct V_4 * V_5 ,
unsigned int V_6 , unsigned int V_13 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
if ( V_8 -> V_10 )
V_6 <<= 3 ;
if ( V_5 -> V_11 )
F_14 ( V_13 , V_5 -> V_11 + V_6 ) ;
else
F_15 ( V_13 , V_5 -> V_12 + V_6 ) ;
}
static unsigned int F_16 ( struct V_4 * V_5 ,
struct V_14 * V_15 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_16 * V_17 = V_15 -> V_18 ;
unsigned int V_6 ;
if ( V_5 -> V_11 )
V_6 = V_17 -> V_11 - V_5 -> V_11 ;
else
V_6 = V_17 -> V_12 - V_5 -> V_12 ;
if ( V_8 -> V_10 )
V_6 >>= 3 ;
return V_6 ;
}
static int F_17 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_19 * V_20 ,
unsigned int * V_21 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_22 * V_23 = V_15 -> V_18 ;
if ( V_8 -> V_24 ) {
V_21 [ 1 ] = F_4 ( V_5 , V_23 -> V_25 ) & V_23 -> V_26 ;
} else {
V_21 [ 0 ] = 0 ;
}
return V_20 -> V_27 ;
}
static void F_18 ( struct V_4 * V_5 ,
struct V_14 * V_15 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_22 * V_23 = V_15 -> V_18 ;
V_23 -> V_28 = false ;
V_23 -> V_29 = 0 ;
if ( V_8 -> V_24 )
F_7 ( V_5 , V_23 -> V_25 , 0 ) ;
}
static void F_19 ( struct V_4 * V_5 ,
struct V_14 * V_15 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_22 * V_23 = V_15 -> V_18 ;
struct V_30 * V_31 = & V_15 -> V_32 -> V_31 ;
unsigned int V_27 ;
unsigned int V_33 ;
V_33 = 0 ;
if ( V_31 -> V_34 ) {
for ( V_27 = 0 ; V_27 < V_31 -> V_35 ; V_27 ++ )
V_33 |= ( 1U << F_20 ( V_31 -> V_34 [ V_27 ] ) ) ;
}
V_33 &= V_23 -> V_26 ;
V_23 -> V_29 = V_33 ;
if ( V_8 -> V_24 )
F_7 ( V_5 , V_23 -> V_25 , V_33 ) ;
}
static int F_21 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_36 )
{
struct V_22 * V_23 = V_15 -> V_18 ;
struct V_30 * V_31 = & V_15 -> V_32 -> V_31 ;
unsigned long V_37 ;
if ( V_36 != V_31 -> V_38 )
return - V_39 ;
F_22 ( & V_23 -> V_40 , V_37 ) ;
V_15 -> V_32 -> V_41 = NULL ;
if ( V_23 -> V_28 )
F_19 ( V_5 , V_15 ) ;
F_23 ( & V_23 -> V_40 , V_37 ) ;
return 1 ;
}
static void F_24 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_42 )
{
struct V_30 * V_31 = & V_15 -> V_32 -> V_31 ;
unsigned short V_13 ;
unsigned int V_27 , V_43 ;
V_13 = 0 ;
for ( V_27 = 0 ; V_27 < V_31 -> V_35 ; V_27 ++ ) {
V_43 = F_20 ( V_31 -> V_34 [ V_27 ] ) ;
if ( V_42 & ( 1U << V_43 ) )
V_13 |= ( 1U << V_27 ) ;
}
F_25 ( V_15 , & V_13 , 1 ) ;
if ( V_31 -> V_44 == V_45 &&
V_15 -> V_32 -> V_46 >= V_31 -> V_47 )
V_15 -> V_32 -> V_48 |= V_49 ;
}
static int F_26 ( struct V_4 * V_5 ,
struct V_14 * V_15 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_22 * V_23 = V_15 -> V_18 ;
unsigned int V_42 ;
unsigned int V_50 ;
unsigned int V_51 ;
unsigned long V_37 ;
V_42 = 0 ;
F_22 ( & V_23 -> V_40 , V_37 ) ;
if ( V_8 -> V_24 ) {
V_51 = V_23 -> V_29 ;
while ( ( V_50 = ( F_4 ( V_5 , V_23 -> V_25 ) &
V_23 -> V_26 & ~ V_42 ) ) != 0 ) {
V_42 |= V_50 ;
V_51 &= ~ V_42 ;
F_7 ( V_5 , V_23 -> V_25 , V_51 ) ;
}
} else {
V_42 = V_23 -> V_29 ;
}
if ( V_42 ) {
V_51 = V_23 -> V_29 ;
if ( V_8 -> V_24 )
F_7 ( V_5 , V_23 -> V_25 , V_51 ) ;
if ( V_23 -> V_28 ) {
if ( V_42 & V_23 -> V_29 ) {
F_24 ( V_5 , V_15 , V_42 ) ;
}
}
}
F_23 ( & V_23 -> V_40 , V_37 ) ;
F_27 ( V_5 , V_15 ) ;
return ( V_42 != 0 ) ;
}
static int F_28 ( struct V_4 * V_5 ,
struct V_14 * V_15 )
{
struct V_22 * V_23 = V_15 -> V_18 ;
unsigned long V_37 ;
F_22 ( & V_23 -> V_40 , V_37 ) ;
if ( V_23 -> V_28 )
F_18 ( V_5 , V_15 ) ;
F_23 ( & V_23 -> V_40 , V_37 ) ;
return 0 ;
}
static int F_29 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_30 * V_31 )
{
int V_52 = 0 ;
V_52 |= F_30 ( & V_31 -> V_53 , V_54 | V_55 ) ;
V_52 |= F_30 ( & V_31 -> V_56 , V_57 ) ;
V_52 |= F_30 ( & V_31 -> V_58 , V_54 ) ;
V_52 |= F_30 ( & V_31 -> V_59 , V_45 ) ;
V_52 |= F_30 ( & V_31 -> V_44 , V_45 | V_60 ) ;
if ( V_52 )
return 1 ;
V_52 |= F_31 ( V_31 -> V_53 ) ;
V_52 |= F_31 ( V_31 -> V_44 ) ;
if ( V_52 )
return 2 ;
V_52 |= F_32 ( & V_31 -> V_38 , 0 ) ;
V_52 |= F_32 ( & V_31 -> V_61 , 0 ) ;
V_52 |= F_32 ( & V_31 -> V_62 , 0 ) ;
V_52 |= F_32 ( & V_31 -> V_63 ,
V_31 -> V_35 ) ;
if ( V_31 -> V_44 == V_45 )
V_52 |= F_33 ( & V_31 -> V_47 , 1 ) ;
else
V_52 |= F_32 ( & V_31 -> V_47 , 0 ) ;
if ( V_52 )
return 3 ;
return 0 ;
}
static int F_34 ( struct V_4 * V_5 ,
struct V_14 * V_15 )
{
struct V_30 * V_31 = & V_15 -> V_32 -> V_31 ;
struct V_22 * V_23 = V_15 -> V_18 ;
unsigned long V_37 ;
F_22 ( & V_23 -> V_40 , V_37 ) ;
V_23 -> V_28 = true ;
if ( V_31 -> V_53 == V_55 )
V_15 -> V_32 -> V_41 = F_21 ;
else
F_19 ( V_5 , V_15 ) ;
F_23 ( & V_23 -> V_40 , V_37 ) ;
return 0 ;
}
static int F_35 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_6 ,
unsigned int V_26 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_22 * V_23 ;
V_23 = F_36 ( V_15 , sizeof( * V_23 ) ) ;
if ( ! V_23 )
return - V_64 ;
V_23 -> V_25 = V_6 ;
V_23 -> V_26 = V_26 ;
F_37 ( & V_23 -> V_40 ) ;
if ( V_8 -> V_24 )
F_7 ( V_5 , V_23 -> V_25 , 0 ) ;
V_15 -> type = V_65 ;
V_15 -> V_66 = V_67 | V_68 | V_69 ;
if ( V_8 -> V_24 ) {
V_15 -> V_70 = V_71 ;
V_15 -> V_72 = V_71 ;
} else {
V_15 -> V_70 = 1 ;
V_15 -> V_72 = 1 ;
}
V_15 -> V_73 = & V_74 ;
V_15 -> V_75 = 1 ;
V_15 -> V_76 = F_17 ;
V_15 -> V_77 = F_29 ;
V_15 -> V_78 = F_34 ;
V_15 -> V_79 = F_28 ;
return 0 ;
}
static T_1 F_38 ( int V_80 , void * V_81 )
{
struct V_4 * V_5 = V_81 ;
struct V_14 * V_15 = V_5 -> V_82 ;
int V_83 ;
if ( ! V_5 -> V_84 )
return V_85 ;
V_83 = F_26 ( V_5 , V_15 ) ;
return F_39 ( V_83 ) ;
}
static void F_40 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_2 ,
unsigned int V_86 )
{
unsigned int V_6 = F_16 ( V_5 , V_15 ) ;
F_7 ( V_5 , F_41 ( V_6 >> 3 ) ,
F_3 ( ( V_6 >> 2 ) & 1 , V_2 , V_86 ) ) ;
}
static void F_42 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_2 ,
unsigned int V_86 )
{
unsigned int V_6 = F_16 ( V_5 , V_15 ) ;
F_7 ( V_5 , F_43 ( V_6 >> 3 ) ,
F_2 ( ( V_6 >> 2 ) & 1 , V_2 , V_86 ) ) ;
}
static int F_44 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_19 * V_20 ,
unsigned int * V_21 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_16 * V_17 = V_15 -> V_18 ;
unsigned int V_2 = F_20 ( V_20 -> V_87 ) ;
unsigned int V_88 = V_8 -> V_10 ? 31 : 7 ;
unsigned int V_86 ;
if ( ! V_8 -> V_89 )
return - V_39 ;
switch ( V_21 [ 0 ] ) {
case V_90 :
V_86 = V_21 [ 2 ] ;
if ( V_86 > V_88 )
return - V_39 ;
F_40 ( V_5 , V_15 , V_2 , V_86 ) ;
V_17 -> V_91 [ V_2 ] = V_86 ;
break;
case V_92 :
V_21 [ 2 ] = V_17 -> V_91 [ V_2 ] ;
break;
case V_93 :
V_86 = V_21 [ 1 ] ;
if ( V_86 > V_88 )
return - V_39 ;
F_42 ( V_5 , V_15 , V_2 , V_86 ) ;
V_17 -> V_94 [ V_2 ] = V_86 ;
break;
case V_95 :
V_21 [ 1 ] = V_17 -> V_94 [ V_2 ] ;
V_21 [ 2 ] = V_96 [ V_17 -> V_94 [ V_2 ] ] ;
break;
default:
return - V_39 ;
}
return V_20 -> V_27 ;
}
static int F_45 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_6 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_16 * V_17 ;
unsigned int V_97 ;
int V_2 ;
if ( V_8 -> V_10 ) {
V_6 <<= 3 ;
V_97 = 3 ;
} else {
V_97 = 0 ;
}
if ( V_5 -> V_11 ) {
V_17 = F_46 ( V_5 -> V_11 + V_6 ,
0 , V_98 , V_97 ) ;
} else {
V_17 = F_47 ( V_5 -> V_12 + V_6 ,
0 , V_98 , V_97 ) ;
}
if ( ! V_17 )
return - V_64 ;
F_48 ( V_15 , V_17 ) ;
V_17 -> V_99 = F_44 ;
F_49 ( V_15 ) ;
if ( V_8 -> V_89 ) {
for ( V_2 = 0 ; V_2 < 3 ; V_2 ++ ) {
F_40 ( V_5 , V_15 , V_2 , 0 ) ;
F_42 ( V_5 , V_15 , V_2 , 0 ) ;
}
}
return 0 ;
}
static void F_50 ( struct V_4 * V_5 ,
struct V_14 * V_15 )
{
struct V_100 * V_23 = V_15 -> V_18 ;
int V_101 ;
V_101 = V_102 ;
if ( ! ( V_15 -> V_103 & 0x0000ff ) )
V_101 |= V_104 ;
if ( ! ( V_15 -> V_103 & 0x00ff00 ) )
V_101 |= V_105 ;
if ( ! ( V_15 -> V_103 & 0x0f0000 ) )
V_101 |= V_106 ;
if ( ! ( V_15 -> V_103 & 0xf00000 ) )
V_101 |= V_107 ;
F_7 ( V_5 , V_23 -> V_25 + V_108 , V_101 ) ;
}
static int F_51 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_19 * V_20 ,
unsigned int * V_21 )
{
struct V_100 * V_23 = V_15 -> V_18 ;
unsigned int V_109 ;
unsigned int V_13 ;
V_109 = F_52 ( V_15 , V_21 ) ;
if ( V_109 ) {
if ( V_109 & 0xff ) {
F_7 ( V_5 , V_23 -> V_25 + V_110 ,
V_15 -> V_111 & 0xff ) ;
}
if ( V_109 & 0xff00 ) {
F_7 ( V_5 , V_23 -> V_25 + V_112 ,
( V_15 -> V_111 >> 8 ) & 0xff ) ;
}
if ( V_109 & 0xff0000 ) {
F_7 ( V_5 , V_23 -> V_25 + V_113 ,
( V_15 -> V_111 >> 16 ) & 0xff ) ;
}
}
V_13 = F_4 ( V_5 , V_23 -> V_25 + V_110 ) ;
V_13 |= F_4 ( V_5 , V_23 -> V_25 + V_112 ) << 8 ;
V_13 |= F_4 ( V_5 , V_23 -> V_25 + V_113 ) << 16 ;
V_21 [ 1 ] = V_13 ;
return V_20 -> V_27 ;
}
static int F_53 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_19 * V_20 ,
unsigned int * V_21 )
{
unsigned int V_2 = F_20 ( V_20 -> V_87 ) ;
unsigned int V_109 ;
int V_114 ;
if ( V_2 < 8 )
V_109 = 0x0000ff ;
else if ( V_2 < 16 )
V_109 = 0x00ff00 ;
else if ( V_2 < 20 )
V_109 = 0x0f0000 ;
else
V_109 = 0xf00000 ;
V_114 = F_54 ( V_5 , V_15 , V_20 , V_21 , V_109 ) ;
if ( V_114 )
return V_114 ;
F_50 ( V_5 , V_15 ) ;
return V_20 -> V_27 ;
}
static int F_55 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_6 )
{
struct V_100 * V_23 ;
V_23 = F_36 ( V_15 , sizeof( * V_23 ) ) ;
if ( ! V_23 )
return - V_64 ;
V_23 -> V_25 = V_6 ;
V_15 -> type = V_115 ;
V_15 -> V_66 = V_67 | V_116 ;
V_15 -> V_70 = 24 ;
V_15 -> V_73 = & V_74 ;
V_15 -> V_75 = 1 ;
V_15 -> V_76 = F_51 ;
V_15 -> V_99 = F_53 ;
F_50 ( V_5 , V_15 ) ;
return 0 ;
}
static int F_56 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_19 * V_20 ,
unsigned int * V_21 )
{
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_20 -> V_27 ; V_27 ++ )
V_21 [ V_27 ] = F_10 ( V_5 , V_117 ) ;
return V_27 ;
}
static void F_57 ( struct V_4 * V_5 ,
struct V_14 * V_15 )
{
unsigned int clock ;
clock = F_10 ( V_5 , V_118 ) & V_119 ;
F_13 ( V_5 , V_118 , clock | V_120 ) ;
F_13 ( V_5 , V_118 , clock ) ;
}
static void F_58 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int * V_86 ,
unsigned int * V_121 )
{
unsigned int V_122 ;
V_122 = F_10 ( V_5 , V_118 ) & V_119 ;
* V_86 = V_122 ;
* V_121 = ( V_122 < F_59 ( V_123 ) ) ?
V_123 [ V_122 ] : 0 ;
}
static int F_60 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_86 )
{
if ( V_86 > V_124 )
return - V_39 ;
F_13 ( V_5 , V_118 , V_86 ) ;
return 0 ;
}
static int F_61 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_19 * V_20 ,
unsigned int * V_21 )
{
int V_114 = 0 ;
switch ( V_21 [ 0 ] ) {
case V_125 :
F_57 ( V_5 , V_15 ) ;
break;
case V_93 :
V_114 = F_60 ( V_5 , V_15 , V_21 [ 1 ] ) ;
if ( V_114 < 0 )
V_114 = - V_39 ;
break;
case V_95 :
F_58 ( V_5 , V_15 , & V_21 [ 1 ] , & V_21 [ 2 ] ) ;
break;
default:
V_114 = - V_39 ;
break;
}
return V_114 < 0 ? V_114 : V_20 -> V_27 ;
}
void F_62 ( struct V_4 * V_5 , unsigned char V_13 )
{
F_7 ( V_5 , V_126 , V_13 ) ;
}
int F_63 ( struct V_4 * V_5 , unsigned int V_80 ,
unsigned long V_127 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_14 * V_15 ;
unsigned int V_27 ;
int V_114 ;
V_114 = F_64 ( V_5 , V_8 -> V_128 ) ;
if ( V_114 )
return V_114 ;
for ( V_27 = 0 ; V_27 < V_5 -> V_129 ; V_27 ++ ) {
V_15 = & V_5 -> V_130 [ V_27 ] ;
switch ( V_8 -> V_131 [ V_27 ] ) {
case V_132 :
V_114 = F_45 ( V_5 , V_15 ,
V_8 -> V_133 [ V_27 ] ) ;
if ( V_114 < 0 )
return V_114 ;
break;
case V_134 :
V_114 = F_55 ( V_5 , V_15 ,
V_8 -> V_133 [ V_27 ] ) ;
if ( V_114 < 0 )
return V_114 ;
break;
case V_135 :
if ( V_80 && ! V_5 -> V_82 ) {
V_114 = F_35 ( V_5 , V_15 ,
V_136 ,
V_8 -> V_133 [ V_27 ] ) ;
if ( V_114 < 0 )
return V_114 ;
V_5 -> V_82 = V_15 ;
} else {
V_15 -> type = V_137 ;
}
break;
case V_138 :
V_15 -> type = V_139 ;
V_15 -> V_66 = V_67 | V_140 ;
V_15 -> V_70 = 1 ;
V_15 -> V_75 = 0xffffffff ;
V_15 -> V_141 = F_56 ;
V_15 -> V_99 = F_61 ;
break;
default:
V_15 -> type = V_137 ;
break;
}
}
if ( V_80 && V_5 -> V_82 ) {
if ( F_65 ( V_80 , F_38 , V_127 ,
V_5 -> V_142 , V_5 ) >= 0 ) {
V_5 -> V_80 = V_80 ;
} else {
F_66 ( V_5 -> V_143 ,
L_1 , V_80 ) ;
}
}
return 0 ;
}
static int T_2 F_67 ( void )
{
return 0 ;
}
static void T_3 F_68 ( void )
{
}
