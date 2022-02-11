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
static int F_16 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_16 * V_17 ,
unsigned int * V_18 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_19 * V_20 = V_15 -> V_21 ;
if ( V_8 -> V_22 ) {
V_18 [ 1 ] = F_4 ( V_5 , V_20 -> V_23 ) & V_20 -> V_24 ;
} else {
V_18 [ 0 ] = 0 ;
}
return V_17 -> V_25 ;
}
static void F_17 ( struct V_4 * V_5 ,
struct V_14 * V_15 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_19 * V_20 = V_15 -> V_21 ;
V_20 -> V_26 = false ;
V_20 -> V_27 = 0 ;
if ( V_8 -> V_22 )
F_7 ( V_5 , V_20 -> V_23 , 0 ) ;
}
static void F_18 ( struct V_4 * V_5 ,
struct V_14 * V_15 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_19 * V_20 = V_15 -> V_21 ;
struct V_28 * V_29 = & V_15 -> V_30 -> V_29 ;
unsigned int V_25 ;
unsigned V_31 ;
V_31 = 0 ;
if ( V_29 -> V_32 ) {
for ( V_25 = 0 ; V_25 < V_29 -> V_33 ; V_25 ++ )
V_31 |= ( 1U << F_19 ( V_29 -> V_32 [ V_25 ] ) ) ;
}
V_31 &= V_20 -> V_24 ;
V_20 -> V_27 = V_31 ;
if ( V_8 -> V_22 )
F_7 ( V_5 , V_20 -> V_23 , V_31 ) ;
}
static int F_20 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_34 )
{
struct V_19 * V_20 = V_15 -> V_21 ;
struct V_28 * V_29 = & V_15 -> V_30 -> V_29 ;
unsigned long V_35 ;
if ( V_34 != V_29 -> V_36 )
return - V_37 ;
F_21 ( & V_20 -> V_38 , V_35 ) ;
V_15 -> V_30 -> V_39 = NULL ;
if ( V_20 -> V_26 )
F_18 ( V_5 , V_15 ) ;
F_22 ( & V_20 -> V_38 , V_35 ) ;
return 1 ;
}
static void F_23 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_40 )
{
struct V_19 * V_20 = V_15 -> V_21 ;
struct V_28 * V_29 = & V_15 -> V_30 -> V_29 ;
unsigned short V_13 ;
unsigned int V_25 , V_41 ;
V_13 = 0 ;
for ( V_25 = 0 ; V_25 < V_29 -> V_33 ; V_25 ++ ) {
V_41 = F_19 ( V_29 -> V_32 [ V_25 ] ) ;
if ( V_40 & ( 1U << V_41 ) )
V_13 |= ( 1U << V_25 ) ;
}
if ( F_24 ( V_15 , V_13 ) ) {
V_15 -> V_30 -> V_42 |= ( V_43 | V_44 ) ;
} else {
F_17 ( V_5 , V_15 ) ;
V_15 -> V_30 -> V_42 |= V_45 | V_46 ;
F_25 ( V_5 -> V_47 , L_1 ) ;
}
if ( V_29 -> V_48 == V_49 ) {
if ( V_20 -> V_50 > 0 ) {
V_20 -> V_50 -- ;
if ( V_20 -> V_50 == 0 ) {
V_15 -> V_30 -> V_42 |= V_51 ;
F_17 ( V_5 , V_15 ) ;
}
}
}
}
static int F_26 ( struct V_4 * V_5 ,
struct V_14 * V_15 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_19 * V_20 = V_15 -> V_21 ;
unsigned V_40 ;
unsigned V_52 ;
unsigned V_53 ;
unsigned int V_54 ;
unsigned long V_35 ;
V_40 = 0 ;
F_21 ( & V_20 -> V_38 , V_35 ) ;
V_54 = V_15 -> V_30 -> V_42 ;
if ( V_8 -> V_22 ) {
V_53 = V_20 -> V_27 ;
while ( ( V_52 = ( F_4 ( V_5 , V_20 -> V_23 ) &
V_20 -> V_24 & ~ V_40 ) ) != 0 ) {
V_40 |= V_52 ;
V_53 &= ~ V_40 ;
F_7 ( V_5 , V_20 -> V_23 , V_53 ) ;
}
} else {
V_40 = V_20 -> V_27 ;
}
if ( V_40 ) {
V_53 = V_20 -> V_27 ;
if ( V_8 -> V_22 )
F_7 ( V_5 , V_20 -> V_23 , V_53 ) ;
if ( V_20 -> V_26 ) {
if ( V_40 & V_20 -> V_27 )
F_23 ( V_5 , V_15 , V_40 ) ;
}
}
F_22 ( & V_20 -> V_38 , V_35 ) ;
if ( V_54 != V_15 -> V_30 -> V_42 )
F_27 ( V_5 , V_15 ) ;
return ( V_40 != 0 ) ;
}
static int F_28 ( struct V_4 * V_5 ,
struct V_14 * V_15 )
{
struct V_19 * V_20 = V_15 -> V_21 ;
unsigned long V_35 ;
F_21 ( & V_20 -> V_38 , V_35 ) ;
if ( V_20 -> V_26 )
F_17 ( V_5 , V_15 ) ;
F_22 ( & V_20 -> V_38 , V_35 ) ;
return 0 ;
}
static int F_29 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_28 * V_29 )
{
int V_55 = 0 ;
V_55 |= F_30 ( & V_29 -> V_56 , V_57 | V_58 ) ;
V_55 |= F_30 ( & V_29 -> V_59 , V_60 ) ;
V_55 |= F_30 ( & V_29 -> V_61 , V_57 ) ;
V_55 |= F_30 ( & V_29 -> V_62 , V_49 ) ;
V_55 |= F_30 ( & V_29 -> V_48 , V_49 | V_63 ) ;
if ( V_55 )
return 1 ;
V_55 |= F_31 ( V_29 -> V_56 ) ;
V_55 |= F_31 ( V_29 -> V_48 ) ;
if ( V_55 )
return 2 ;
V_55 |= F_32 ( & V_29 -> V_36 , 0 ) ;
V_55 |= F_32 ( & V_29 -> V_64 , 0 ) ;
V_55 |= F_32 ( & V_29 -> V_65 , 0 ) ;
V_55 |= F_32 ( & V_29 -> V_66 , V_29 -> V_33 ) ;
if ( V_29 -> V_48 == V_49 )
V_55 |= F_33 ( & V_29 -> V_67 , 1 ) ;
else
V_55 |= F_32 ( & V_29 -> V_67 , 0 ) ;
if ( V_55 )
return 3 ;
return 0 ;
}
static int F_34 ( struct V_4 * V_5 ,
struct V_14 * V_15 )
{
struct V_28 * V_29 = & V_15 -> V_30 -> V_29 ;
struct V_19 * V_20 = V_15 -> V_21 ;
unsigned long V_35 ;
F_21 ( & V_20 -> V_38 , V_35 ) ;
V_20 -> V_26 = true ;
V_20 -> V_50 = V_29 -> V_67 ;
if ( V_29 -> V_56 == V_58 )
V_15 -> V_30 -> V_39 = F_20 ;
else
F_18 ( V_5 , V_15 ) ;
F_22 ( & V_20 -> V_38 , V_35 ) ;
return 0 ;
}
static int F_35 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_6 ,
unsigned V_24 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_19 * V_20 ;
V_20 = F_36 ( V_15 , sizeof( * V_20 ) ) ;
if ( ! V_20 )
return - V_68 ;
V_20 -> V_23 = V_6 ;
V_20 -> V_24 = V_24 ;
F_37 ( & V_20 -> V_38 ) ;
if ( V_8 -> V_22 )
F_7 ( V_5 , V_20 -> V_23 , 0 ) ;
V_15 -> type = V_69 ;
V_15 -> V_70 = V_71 | V_72 ;
if ( V_8 -> V_22 ) {
V_15 -> V_73 = V_74 ;
V_15 -> V_75 = V_74 ;
} else {
V_15 -> V_73 = 1 ;
V_15 -> V_75 = 1 ;
}
V_15 -> V_76 = & V_77 ;
V_15 -> V_78 = 1 ;
V_15 -> V_79 = F_16 ;
V_15 -> V_80 = F_29 ;
V_15 -> V_81 = F_34 ;
V_15 -> V_82 = F_28 ;
return 0 ;
}
static T_1 F_38 ( int V_83 , void * V_84 )
{
struct V_4 * V_5 = V_84 ;
struct V_14 * V_15 = V_5 -> V_85 ;
int V_86 ;
if ( ! V_5 -> V_87 )
return V_88 ;
V_86 = F_26 ( V_5 , V_15 ) ;
return F_39 ( V_86 ) ;
}
static unsigned int F_40 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_2 )
{
struct V_89 * V_20 = V_15 -> V_21 ;
unsigned int V_13 ;
V_13 = V_2 << 6 ;
F_7 ( V_5 , V_20 -> V_23 + V_90 , V_13 ) ;
V_13 = F_4 ( V_5 , V_20 -> V_23 + V_2 ) ;
V_13 += F_4 ( V_5 , V_20 -> V_23 + V_2 ) << 8 ;
return V_13 ;
}
static void F_41 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_2 ,
unsigned int V_91 )
{
struct V_89 * V_20 = V_15 -> V_21 ;
F_7 ( V_5 , V_20 -> V_23 + V_2 , V_91 & 0xff ) ;
F_7 ( V_5 , V_20 -> V_23 + V_2 , ( V_91 >> 8 ) & 0xff ) ;
}
static void F_42 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_2 ,
unsigned int V_92 )
{
struct V_89 * V_20 = V_15 -> V_21 ;
unsigned int V_93 ;
V_93 = V_2 << 6 ;
V_93 |= 0x30 ;
V_93 |= ( V_92 & 0xf ) ;
F_7 ( V_5 , V_20 -> V_23 + V_90 , V_93 ) ;
}
static unsigned int F_43 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_2 )
{
struct V_89 * V_20 = V_15 -> V_21 ;
F_7 ( V_5 , V_20 -> V_23 + V_90 ,
0xe0 | ( 2 << V_2 ) ) ;
return F_4 ( V_5 , V_20 -> V_23 + V_2 ) ;
}
static int F_44 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_16 * V_17 ,
unsigned int * V_18 )
{
struct V_89 * V_20 = V_15 -> V_21 ;
int V_2 = F_19 ( V_17 -> V_94 ) ;
unsigned int V_25 ;
unsigned long V_35 ;
for ( V_25 = 0 ; V_25 < V_17 -> V_25 ; V_25 ++ ) {
F_21 ( & V_20 -> V_38 , V_35 ) ;
V_18 [ V_25 ] = F_40 ( V_5 , V_15 , V_2 ) ;
F_22 ( & V_20 -> V_38 , V_35 ) ;
}
return V_17 -> V_25 ;
}
static int F_45 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_16 * V_17 ,
unsigned int * V_18 )
{
struct V_89 * V_20 = V_15 -> V_21 ;
int V_2 = F_19 ( V_17 -> V_94 ) ;
unsigned int V_25 ;
unsigned long V_35 ;
for ( V_25 = 0 ; V_25 < V_17 -> V_25 ; V_25 ++ ) {
F_21 ( & V_20 -> V_38 , V_35 ) ;
F_41 ( V_5 , V_15 , V_2 , V_18 [ V_25 ] ) ;
F_22 ( & V_20 -> V_38 , V_35 ) ;
}
return V_17 -> V_25 ;
}
static int F_46 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_95 ,
unsigned int V_96 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_89 * V_20 = V_15 -> V_21 ;
unsigned char V_93 ;
if ( ! V_8 -> V_97 )
return - 1 ;
if ( V_95 > 2 )
return - 1 ;
if ( V_96 > ( V_8 -> V_10 ? 31 : 7 ) )
return - 1 ;
V_20 -> V_96 [ V_95 ] = V_96 ;
V_93 = F_3 ( V_20 -> V_1 , V_95 , V_96 ) ;
F_7 ( V_5 , V_20 -> V_98 , V_93 ) ;
return 0 ;
}
static int F_47 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_95 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_89 * V_20 = V_15 -> V_21 ;
if ( ! V_8 -> V_97 )
return - 1 ;
if ( V_95 > 2 )
return - 1 ;
return V_20 -> V_96 [ V_95 ] ;
}
static int F_48 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_95 ,
unsigned int V_99 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_89 * V_20 = V_15 -> V_21 ;
unsigned char V_93 ;
if ( ! V_8 -> V_97 )
return - 1 ;
if ( V_95 > 2 )
return - 1 ;
if ( V_99 > ( V_8 -> V_10 ? 31 : 7 ) )
return - 1 ;
V_20 -> V_99 [ V_95 ] = V_99 ;
V_93 = F_2 ( V_20 -> V_1 , V_95 , V_99 ) ;
F_7 ( V_5 , V_20 -> V_100 , V_93 ) ;
return 0 ;
}
static int F_49 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_95 ,
unsigned int * V_101 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_89 * V_20 = V_15 -> V_21 ;
unsigned V_99 ;
if ( ! V_8 -> V_97 )
return - 1 ;
if ( V_95 > 2 )
return - 1 ;
V_99 = V_20 -> V_99 [ V_95 ] ;
* V_101 = V_102 [ V_99 ] ;
return V_99 ;
}
static int F_50 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_16 * V_17 ,
unsigned int * V_18 )
{
struct V_89 * V_20 = V_15 -> V_21 ;
int V_103 = 0 ;
int V_2 = F_19 ( V_17 -> V_94 ) ;
unsigned long V_35 ;
F_21 ( & V_20 -> V_38 , V_35 ) ;
switch ( V_18 [ 0 ] ) {
case V_104 :
if ( V_18 [ 1 ] > ( V_105 | V_106 ) )
V_103 = - V_37 ;
else
F_42 ( V_5 , V_15 , V_2 , V_18 [ 1 ] ) ;
break;
case V_107 :
V_18 [ 1 ] = F_43 ( V_5 , V_15 , V_2 ) ;
break;
case V_108 :
V_103 = F_46 ( V_5 , V_15 , V_2 , V_18 [ 2 ] ) ;
if ( V_103 < 0 )
V_103 = - V_37 ;
break;
case V_109 :
V_103 = F_47 ( V_5 , V_15 , V_2 ) ;
if ( V_103 < 0 ) {
V_103 = - V_37 ;
break;
}
V_18 [ 2 ] = V_103 ;
break;
case V_110 :
V_103 = F_48 ( V_5 , V_15 , V_2 , V_18 [ 1 ] ) ;
if ( V_103 < 0 )
V_103 = - V_37 ;
break;
case V_111 :
V_103 = F_49 ( V_5 , V_15 , V_2 , & V_18 [ 2 ] ) ;
if ( V_103 < 0 ) {
V_103 = - V_37 ;
break;
}
V_18 [ 1 ] = V_103 ;
break;
default:
V_103 = - V_37 ;
break;
}
F_22 ( & V_20 -> V_38 , V_35 ) ;
return V_103 < 0 ? V_103 : V_17 -> V_25 ;
}
static int F_51 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_6 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_89 * V_20 ;
unsigned int V_2 ;
V_20 = F_36 ( V_15 , sizeof( * V_20 ) ) ;
if ( ! V_20 )
return - V_68 ;
V_15 -> type = V_112 ;
V_15 -> V_70 = V_113 | V_71 ;
V_15 -> V_73 = 3 ;
V_15 -> V_78 = 0xFFFF ;
V_15 -> V_114 = F_44 ;
V_15 -> V_115 = F_45 ;
V_15 -> V_116 = F_50 ;
F_37 ( & V_20 -> V_38 ) ;
V_20 -> V_23 = V_6 ;
if ( V_8 -> V_97 ) {
V_20 -> V_100 = V_117 + ( V_6 >> 3 ) ;
V_20 -> V_98 = V_118 + ( V_6 >> 3 ) ;
V_20 -> V_1 = ( V_6 >> 2 ) & 1 ;
}
for ( V_2 = 0 ; V_2 < 3 ; V_2 ++ ) {
F_42 ( V_5 , V_15 , V_2 ,
V_119 | V_120 ) ;
if ( V_8 -> V_97 ) {
F_46 ( V_5 , V_15 , V_2 , 0 ) ;
F_48 ( V_5 , V_15 , V_2 , 0 ) ;
}
}
return 0 ;
}
static void F_52 ( struct V_4 * V_5 ,
struct V_14 * V_15 )
{
struct V_121 * V_20 = V_15 -> V_21 ;
int V_122 ;
V_122 = V_123 ;
if ( ! ( V_15 -> V_124 & 0x0000ff ) )
V_122 |= V_125 ;
if ( ! ( V_15 -> V_124 & 0x00ff00 ) )
V_122 |= V_126 ;
if ( ! ( V_15 -> V_124 & 0x0f0000 ) )
V_122 |= V_127 ;
if ( ! ( V_15 -> V_124 & 0xf00000 ) )
V_122 |= V_128 ;
F_7 ( V_5 , V_20 -> V_23 + V_129 , V_122 ) ;
}
static int F_53 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_16 * V_17 ,
unsigned int * V_18 )
{
struct V_121 * V_20 = V_15 -> V_21 ;
unsigned int V_130 ;
unsigned int V_13 ;
V_130 = F_54 ( V_15 , V_18 ) ;
if ( V_130 ) {
if ( V_130 & 0xff )
F_7 ( V_5 , V_20 -> V_23 + V_131 ,
V_15 -> V_132 & 0xff ) ;
if ( V_130 & 0xff00 )
F_7 ( V_5 , V_20 -> V_23 + V_133 ,
( V_15 -> V_132 >> 8 ) & 0xff ) ;
if ( V_130 & 0xff0000 )
F_7 ( V_5 , V_20 -> V_23 + V_134 ,
( V_15 -> V_132 >> 16 ) & 0xff ) ;
}
V_13 = F_4 ( V_5 , V_20 -> V_23 + V_131 ) ;
V_13 |= F_4 ( V_5 , V_20 -> V_23 + V_133 ) << 8 ;
V_13 |= F_4 ( V_5 , V_20 -> V_23 + V_134 ) << 16 ;
V_18 [ 1 ] = V_13 ;
return V_17 -> V_25 ;
}
static int F_55 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_16 * V_17 ,
unsigned int * V_18 )
{
unsigned int V_2 = F_19 ( V_17 -> V_94 ) ;
unsigned int V_130 ;
int V_103 ;
if ( V_2 < 8 )
V_130 = 0x0000ff ;
else if ( V_2 < 16 )
V_130 = 0x00ff00 ;
else if ( V_2 < 20 )
V_130 = 0x0f0000 ;
else
V_130 = 0xf00000 ;
V_103 = F_56 ( V_5 , V_15 , V_17 , V_18 , V_130 ) ;
if ( V_103 )
return V_103 ;
F_52 ( V_5 , V_15 ) ;
return V_17 -> V_25 ;
}
static int F_57 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_6 )
{
struct V_121 * V_20 ;
V_20 = F_36 ( V_15 , sizeof( * V_20 ) ) ;
if ( ! V_20 )
return - V_68 ;
V_20 -> V_23 = V_6 ;
V_15 -> type = V_135 ;
V_15 -> V_70 = V_71 | V_113 ;
V_15 -> V_73 = 24 ;
V_15 -> V_76 = & V_77 ;
V_15 -> V_78 = 1 ;
V_15 -> V_79 = F_53 ;
V_15 -> V_116 = F_55 ;
F_52 ( V_5 , V_15 ) ;
return 0 ;
}
static int F_58 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_16 * V_17 ,
unsigned int * V_18 )
{
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < V_17 -> V_25 ; V_25 ++ )
V_18 [ V_25 ] = F_10 ( V_5 , V_136 ) ;
return V_25 ;
}
static void F_59 ( struct V_4 * V_5 ,
struct V_14 * V_15 )
{
unsigned int clock ;
clock = F_10 ( V_5 , V_137 ) & V_138 ;
F_13 ( V_5 , V_137 , clock | V_139 ) ;
F_13 ( V_5 , V_137 , clock ) ;
}
static void F_60 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int * V_140 ,
unsigned int * V_141 )
{
unsigned int V_142 ;
V_142 = F_10 ( V_5 , V_137 ) & V_138 ;
* V_140 = V_142 ;
* V_141 = ( V_142 < F_61 ( V_143 ) ) ?
V_143 [ V_142 ] : 0 ;
}
static int F_62 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_140 )
{
if ( V_140 > V_144 )
return - V_37 ;
F_13 ( V_5 , V_137 , V_140 ) ;
return 0 ;
}
static int F_63 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_16 * V_17 ,
unsigned int * V_18 )
{
int V_103 = 0 ;
switch ( V_18 [ 0 ] ) {
case V_145 :
F_59 ( V_5 , V_15 ) ;
break;
case V_110 :
V_103 = F_62 ( V_5 , V_15 , V_18 [ 1 ] ) ;
if ( V_103 < 0 )
V_103 = - V_37 ;
break;
case V_111 :
F_60 ( V_5 , V_15 , & V_18 [ 1 ] , & V_18 [ 2 ] ) ;
break;
default:
V_103 = - V_37 ;
break;
}
return V_103 < 0 ? V_103 : V_17 -> V_25 ;
}
void F_64 ( struct V_4 * V_5 , unsigned char V_13 )
{
F_7 ( V_5 , V_146 , V_13 ) ;
}
int F_65 ( struct V_4 * V_5 , unsigned int V_83 ,
unsigned long V_147 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_14 * V_15 ;
unsigned int V_25 ;
int V_103 ;
V_103 = F_66 ( V_5 , V_8 -> V_148 ) ;
if ( V_103 )
return V_103 ;
for ( V_25 = 0 ; V_25 < V_5 -> V_149 ; V_25 ++ ) {
V_15 = & V_5 -> V_150 [ V_25 ] ;
switch ( V_8 -> V_151 [ V_25 ] ) {
case V_152 :
V_103 = F_51 ( V_5 , V_15 ,
V_8 -> V_153 [ V_25 ] ) ;
if ( V_103 < 0 )
return V_103 ;
break;
case V_154 :
V_103 = F_57 ( V_5 , V_15 ,
V_8 -> V_153 [ V_25 ] ) ;
if ( V_103 < 0 )
return V_103 ;
break;
case V_155 :
if ( V_83 && ! V_5 -> V_85 ) {
V_103 = F_35 ( V_5 , V_15 ,
V_156 ,
V_8 -> V_153 [ V_25 ] ) ;
if ( V_103 < 0 )
return V_103 ;
V_5 -> V_85 = V_15 ;
} else {
V_15 -> type = V_157 ;
}
break;
case V_158 :
V_15 -> type = V_159 ;
V_15 -> V_70 = V_71 | V_160 ;
V_15 -> V_73 = 1 ;
V_15 -> V_78 = 0xffffffff ;
V_15 -> V_114 = F_58 ;
V_15 -> V_116 = F_63 ;
break;
default:
V_15 -> type = V_157 ;
break;
}
}
if ( V_83 && V_5 -> V_85 ) {
if ( F_67 ( V_83 , F_38 , V_147 ,
V_5 -> V_161 , V_5 ) >= 0 ) {
V_5 -> V_83 = V_83 ;
} else {
F_68 ( V_5 -> V_47 ,
L_2 , V_83 ) ;
}
}
return 0 ;
}
static int T_2 F_69 ( void )
{
return 0 ;
}
static void T_3 F_70 ( void )
{
}
