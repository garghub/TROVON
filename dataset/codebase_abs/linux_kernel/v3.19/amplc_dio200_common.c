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
struct V_28 * V_29 = & V_15 -> V_30 -> V_29 ;
unsigned short V_13 ;
unsigned int V_25 , V_41 ;
V_13 = 0 ;
for ( V_25 = 0 ; V_25 < V_29 -> V_33 ; V_25 ++ ) {
V_41 = F_19 ( V_29 -> V_32 [ V_25 ] ) ;
if ( V_40 & ( 1U << V_41 ) )
V_13 |= ( 1U << V_25 ) ;
}
F_24 ( V_15 , & V_13 , 1 ) ;
if ( V_29 -> V_42 == V_43 &&
V_15 -> V_30 -> V_44 >= V_29 -> V_45 )
V_15 -> V_30 -> V_46 |= V_47 ;
}
static int F_25 ( struct V_4 * V_5 ,
struct V_14 * V_15 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_19 * V_20 = V_15 -> V_21 ;
unsigned V_40 ;
unsigned V_48 ;
unsigned V_49 ;
unsigned long V_35 ;
V_40 = 0 ;
F_21 ( & V_20 -> V_38 , V_35 ) ;
if ( V_8 -> V_22 ) {
V_49 = V_20 -> V_27 ;
while ( ( V_48 = ( F_4 ( V_5 , V_20 -> V_23 ) &
V_20 -> V_24 & ~ V_40 ) ) != 0 ) {
V_40 |= V_48 ;
V_49 &= ~ V_40 ;
F_7 ( V_5 , V_20 -> V_23 , V_49 ) ;
}
} else {
V_40 = V_20 -> V_27 ;
}
if ( V_40 ) {
V_49 = V_20 -> V_27 ;
if ( V_8 -> V_22 )
F_7 ( V_5 , V_20 -> V_23 , V_49 ) ;
if ( V_20 -> V_26 ) {
if ( V_40 & V_20 -> V_27 )
F_23 ( V_5 , V_15 , V_40 ) ;
}
}
F_22 ( & V_20 -> V_38 , V_35 ) ;
F_26 ( V_5 , V_15 ) ;
return ( V_40 != 0 ) ;
}
static int F_27 ( struct V_4 * V_5 ,
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
static int F_28 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_28 * V_29 )
{
int V_50 = 0 ;
V_50 |= F_29 ( & V_29 -> V_51 , V_52 | V_53 ) ;
V_50 |= F_29 ( & V_29 -> V_54 , V_55 ) ;
V_50 |= F_29 ( & V_29 -> V_56 , V_52 ) ;
V_50 |= F_29 ( & V_29 -> V_57 , V_43 ) ;
V_50 |= F_29 ( & V_29 -> V_42 , V_43 | V_58 ) ;
if ( V_50 )
return 1 ;
V_50 |= F_30 ( V_29 -> V_51 ) ;
V_50 |= F_30 ( V_29 -> V_42 ) ;
if ( V_50 )
return 2 ;
V_50 |= F_31 ( & V_29 -> V_36 , 0 ) ;
V_50 |= F_31 ( & V_29 -> V_59 , 0 ) ;
V_50 |= F_31 ( & V_29 -> V_60 , 0 ) ;
V_50 |= F_31 ( & V_29 -> V_61 , V_29 -> V_33 ) ;
if ( V_29 -> V_42 == V_43 )
V_50 |= F_32 ( & V_29 -> V_45 , 1 ) ;
else
V_50 |= F_31 ( & V_29 -> V_45 , 0 ) ;
if ( V_50 )
return 3 ;
return 0 ;
}
static int F_33 ( struct V_4 * V_5 ,
struct V_14 * V_15 )
{
struct V_28 * V_29 = & V_15 -> V_30 -> V_29 ;
struct V_19 * V_20 = V_15 -> V_21 ;
unsigned long V_35 ;
F_21 ( & V_20 -> V_38 , V_35 ) ;
V_20 -> V_26 = true ;
if ( V_29 -> V_51 == V_53 )
V_15 -> V_30 -> V_39 = F_20 ;
else
F_18 ( V_5 , V_15 ) ;
F_22 ( & V_20 -> V_38 , V_35 ) ;
return 0 ;
}
static int F_34 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_6 ,
unsigned V_24 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_19 * V_20 ;
V_20 = F_35 ( V_15 , sizeof( * V_20 ) ) ;
if ( ! V_20 )
return - V_62 ;
V_20 -> V_23 = V_6 ;
V_20 -> V_24 = V_24 ;
F_36 ( & V_20 -> V_38 ) ;
if ( V_8 -> V_22 )
F_7 ( V_5 , V_20 -> V_23 , 0 ) ;
V_15 -> type = V_63 ;
V_15 -> V_64 = V_65 | V_66 | V_67 ;
if ( V_8 -> V_22 ) {
V_15 -> V_68 = V_69 ;
V_15 -> V_70 = V_69 ;
} else {
V_15 -> V_68 = 1 ;
V_15 -> V_70 = 1 ;
}
V_15 -> V_71 = & V_72 ;
V_15 -> V_73 = 1 ;
V_15 -> V_74 = F_16 ;
V_15 -> V_75 = F_28 ;
V_15 -> V_76 = F_33 ;
V_15 -> V_77 = F_27 ;
return 0 ;
}
static T_1 F_37 ( int V_78 , void * V_79 )
{
struct V_4 * V_5 = V_79 ;
struct V_14 * V_15 = V_5 -> V_80 ;
int V_81 ;
if ( ! V_5 -> V_82 )
return V_83 ;
V_81 = F_25 ( V_5 , V_15 ) ;
return F_38 ( V_81 ) ;
}
static unsigned int F_39 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_2 )
{
struct V_84 * V_20 = V_15 -> V_21 ;
unsigned int V_13 ;
V_13 = V_2 << 6 ;
F_7 ( V_5 , V_20 -> V_23 + V_85 , V_13 ) ;
V_13 = F_4 ( V_5 , V_20 -> V_23 + V_2 ) ;
V_13 += F_4 ( V_5 , V_20 -> V_23 + V_2 ) << 8 ;
return V_13 ;
}
static void F_40 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_2 ,
unsigned int V_86 )
{
struct V_84 * V_20 = V_15 -> V_21 ;
F_7 ( V_5 , V_20 -> V_23 + V_2 , V_86 & 0xff ) ;
F_7 ( V_5 , V_20 -> V_23 + V_2 , ( V_86 >> 8 ) & 0xff ) ;
}
static void F_41 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_2 ,
unsigned int V_87 )
{
struct V_84 * V_20 = V_15 -> V_21 ;
unsigned int V_88 ;
V_88 = V_2 << 6 ;
V_88 |= 0x30 ;
V_88 |= ( V_87 & 0xf ) ;
F_7 ( V_5 , V_20 -> V_23 + V_85 , V_88 ) ;
}
static unsigned int F_42 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_2 )
{
struct V_84 * V_20 = V_15 -> V_21 ;
F_7 ( V_5 , V_20 -> V_23 + V_85 ,
0xe0 | ( 2 << V_2 ) ) ;
return F_4 ( V_5 , V_20 -> V_23 + V_2 ) ;
}
static int F_43 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_16 * V_17 ,
unsigned int * V_18 )
{
struct V_84 * V_20 = V_15 -> V_21 ;
int V_2 = F_19 ( V_17 -> V_89 ) ;
unsigned int V_25 ;
unsigned long V_35 ;
for ( V_25 = 0 ; V_25 < V_17 -> V_25 ; V_25 ++ ) {
F_21 ( & V_20 -> V_38 , V_35 ) ;
V_18 [ V_25 ] = F_39 ( V_5 , V_15 , V_2 ) ;
F_22 ( & V_20 -> V_38 , V_35 ) ;
}
return V_17 -> V_25 ;
}
static int F_44 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_16 * V_17 ,
unsigned int * V_18 )
{
struct V_84 * V_20 = V_15 -> V_21 ;
int V_2 = F_19 ( V_17 -> V_89 ) ;
unsigned int V_25 ;
unsigned long V_35 ;
for ( V_25 = 0 ; V_25 < V_17 -> V_25 ; V_25 ++ ) {
F_21 ( & V_20 -> V_38 , V_35 ) ;
F_40 ( V_5 , V_15 , V_2 , V_18 [ V_25 ] ) ;
F_22 ( & V_20 -> V_38 , V_35 ) ;
}
return V_17 -> V_25 ;
}
static int F_45 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_90 ,
unsigned int V_91 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_84 * V_20 = V_15 -> V_21 ;
unsigned char V_88 ;
if ( ! V_8 -> V_92 )
return - 1 ;
if ( V_90 > 2 )
return - 1 ;
if ( V_91 > ( V_8 -> V_10 ? 31 : 7 ) )
return - 1 ;
V_20 -> V_91 [ V_90 ] = V_91 ;
V_88 = F_3 ( V_20 -> V_1 , V_90 , V_91 ) ;
F_7 ( V_5 , V_20 -> V_93 , V_88 ) ;
return 0 ;
}
static int F_46 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_90 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_84 * V_20 = V_15 -> V_21 ;
if ( ! V_8 -> V_92 )
return - 1 ;
if ( V_90 > 2 )
return - 1 ;
return V_20 -> V_91 [ V_90 ] ;
}
static int F_47 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_90 ,
unsigned int V_94 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_84 * V_20 = V_15 -> V_21 ;
unsigned char V_88 ;
if ( ! V_8 -> V_92 )
return - 1 ;
if ( V_90 > 2 )
return - 1 ;
if ( V_94 > ( V_8 -> V_10 ? 31 : 7 ) )
return - 1 ;
V_20 -> V_94 [ V_90 ] = V_94 ;
V_88 = F_2 ( V_20 -> V_1 , V_90 , V_94 ) ;
F_7 ( V_5 , V_20 -> V_95 , V_88 ) ;
return 0 ;
}
static int F_48 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_90 ,
unsigned int * V_96 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_84 * V_20 = V_15 -> V_21 ;
unsigned V_94 ;
if ( ! V_8 -> V_92 )
return - 1 ;
if ( V_90 > 2 )
return - 1 ;
V_94 = V_20 -> V_94 [ V_90 ] ;
* V_96 = V_97 [ V_94 ] ;
return V_94 ;
}
static int F_49 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_16 * V_17 ,
unsigned int * V_18 )
{
struct V_84 * V_20 = V_15 -> V_21 ;
int V_98 = 0 ;
int V_2 = F_19 ( V_17 -> V_89 ) ;
unsigned long V_35 ;
F_21 ( & V_20 -> V_38 , V_35 ) ;
switch ( V_18 [ 0 ] ) {
case V_99 :
if ( V_18 [ 1 ] > ( V_100 | V_101 ) )
V_98 = - V_37 ;
else
F_41 ( V_5 , V_15 , V_2 , V_18 [ 1 ] ) ;
break;
case V_102 :
V_18 [ 1 ] = F_42 ( V_5 , V_15 , V_2 ) ;
break;
case V_103 :
V_98 = F_45 ( V_5 , V_15 , V_2 , V_18 [ 2 ] ) ;
if ( V_98 < 0 )
V_98 = - V_37 ;
break;
case V_104 :
V_98 = F_46 ( V_5 , V_15 , V_2 ) ;
if ( V_98 < 0 ) {
V_98 = - V_37 ;
break;
}
V_18 [ 2 ] = V_98 ;
break;
case V_105 :
V_98 = F_47 ( V_5 , V_15 , V_2 , V_18 [ 1 ] ) ;
if ( V_98 < 0 )
V_98 = - V_37 ;
break;
case V_106 :
V_98 = F_48 ( V_5 , V_15 , V_2 , & V_18 [ 2 ] ) ;
if ( V_98 < 0 ) {
V_98 = - V_37 ;
break;
}
V_18 [ 1 ] = V_98 ;
break;
default:
V_98 = - V_37 ;
break;
}
F_22 ( & V_20 -> V_38 , V_35 ) ;
return V_98 < 0 ? V_98 : V_17 -> V_25 ;
}
static int F_50 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_6 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_84 * V_20 ;
unsigned int V_2 ;
V_20 = F_35 ( V_15 , sizeof( * V_20 ) ) ;
if ( ! V_20 )
return - V_62 ;
V_15 -> type = V_107 ;
V_15 -> V_64 = V_108 | V_65 ;
V_15 -> V_68 = 3 ;
V_15 -> V_73 = 0xFFFF ;
V_15 -> V_109 = F_43 ;
V_15 -> V_110 = F_44 ;
V_15 -> V_111 = F_49 ;
F_36 ( & V_20 -> V_38 ) ;
V_20 -> V_23 = V_6 ;
if ( V_8 -> V_92 ) {
V_20 -> V_95 = V_112 + ( V_6 >> 3 ) ;
V_20 -> V_93 = V_113 + ( V_6 >> 3 ) ;
V_20 -> V_1 = ( V_6 >> 2 ) & 1 ;
}
for ( V_2 = 0 ; V_2 < 3 ; V_2 ++ ) {
F_41 ( V_5 , V_15 , V_2 ,
V_114 | V_115 ) ;
if ( V_8 -> V_92 ) {
F_45 ( V_5 , V_15 , V_2 , 0 ) ;
F_47 ( V_5 , V_15 , V_2 , 0 ) ;
}
}
return 0 ;
}
static void F_51 ( struct V_4 * V_5 ,
struct V_14 * V_15 )
{
struct V_116 * V_20 = V_15 -> V_21 ;
int V_117 ;
V_117 = V_118 ;
if ( ! ( V_15 -> V_119 & 0x0000ff ) )
V_117 |= V_120 ;
if ( ! ( V_15 -> V_119 & 0x00ff00 ) )
V_117 |= V_121 ;
if ( ! ( V_15 -> V_119 & 0x0f0000 ) )
V_117 |= V_122 ;
if ( ! ( V_15 -> V_119 & 0xf00000 ) )
V_117 |= V_123 ;
F_7 ( V_5 , V_20 -> V_23 + V_124 , V_117 ) ;
}
static int F_52 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_16 * V_17 ,
unsigned int * V_18 )
{
struct V_116 * V_20 = V_15 -> V_21 ;
unsigned int V_125 ;
unsigned int V_13 ;
V_125 = F_53 ( V_15 , V_18 ) ;
if ( V_125 ) {
if ( V_125 & 0xff )
F_7 ( V_5 , V_20 -> V_23 + V_126 ,
V_15 -> V_127 & 0xff ) ;
if ( V_125 & 0xff00 )
F_7 ( V_5 , V_20 -> V_23 + V_128 ,
( V_15 -> V_127 >> 8 ) & 0xff ) ;
if ( V_125 & 0xff0000 )
F_7 ( V_5 , V_20 -> V_23 + V_129 ,
( V_15 -> V_127 >> 16 ) & 0xff ) ;
}
V_13 = F_4 ( V_5 , V_20 -> V_23 + V_126 ) ;
V_13 |= F_4 ( V_5 , V_20 -> V_23 + V_128 ) << 8 ;
V_13 |= F_4 ( V_5 , V_20 -> V_23 + V_129 ) << 16 ;
V_18 [ 1 ] = V_13 ;
return V_17 -> V_25 ;
}
static int F_54 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_16 * V_17 ,
unsigned int * V_18 )
{
unsigned int V_2 = F_19 ( V_17 -> V_89 ) ;
unsigned int V_125 ;
int V_98 ;
if ( V_2 < 8 )
V_125 = 0x0000ff ;
else if ( V_2 < 16 )
V_125 = 0x00ff00 ;
else if ( V_2 < 20 )
V_125 = 0x0f0000 ;
else
V_125 = 0xf00000 ;
V_98 = F_55 ( V_5 , V_15 , V_17 , V_18 , V_125 ) ;
if ( V_98 )
return V_98 ;
F_51 ( V_5 , V_15 ) ;
return V_17 -> V_25 ;
}
static int F_56 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_6 )
{
struct V_116 * V_20 ;
V_20 = F_35 ( V_15 , sizeof( * V_20 ) ) ;
if ( ! V_20 )
return - V_62 ;
V_20 -> V_23 = V_6 ;
V_15 -> type = V_130 ;
V_15 -> V_64 = V_65 | V_108 ;
V_15 -> V_68 = 24 ;
V_15 -> V_71 = & V_72 ;
V_15 -> V_73 = 1 ;
V_15 -> V_74 = F_52 ;
V_15 -> V_111 = F_54 ;
F_51 ( V_5 , V_15 ) ;
return 0 ;
}
static int F_57 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_16 * V_17 ,
unsigned int * V_18 )
{
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < V_17 -> V_25 ; V_25 ++ )
V_18 [ V_25 ] = F_10 ( V_5 , V_131 ) ;
return V_25 ;
}
static void F_58 ( struct V_4 * V_5 ,
struct V_14 * V_15 )
{
unsigned int clock ;
clock = F_10 ( V_5 , V_132 ) & V_133 ;
F_13 ( V_5 , V_132 , clock | V_134 ) ;
F_13 ( V_5 , V_132 , clock ) ;
}
static void F_59 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int * V_135 ,
unsigned int * V_136 )
{
unsigned int V_137 ;
V_137 = F_10 ( V_5 , V_132 ) & V_133 ;
* V_135 = V_137 ;
* V_136 = ( V_137 < F_60 ( V_138 ) ) ?
V_138 [ V_137 ] : 0 ;
}
static int F_61 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
unsigned int V_135 )
{
if ( V_135 > V_139 )
return - V_37 ;
F_13 ( V_5 , V_132 , V_135 ) ;
return 0 ;
}
static int F_62 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_16 * V_17 ,
unsigned int * V_18 )
{
int V_98 = 0 ;
switch ( V_18 [ 0 ] ) {
case V_140 :
F_58 ( V_5 , V_15 ) ;
break;
case V_105 :
V_98 = F_61 ( V_5 , V_15 , V_18 [ 1 ] ) ;
if ( V_98 < 0 )
V_98 = - V_37 ;
break;
case V_106 :
F_59 ( V_5 , V_15 , & V_18 [ 1 ] , & V_18 [ 2 ] ) ;
break;
default:
V_98 = - V_37 ;
break;
}
return V_98 < 0 ? V_98 : V_17 -> V_25 ;
}
void F_63 ( struct V_4 * V_5 , unsigned char V_13 )
{
F_7 ( V_5 , V_141 , V_13 ) ;
}
int F_64 ( struct V_4 * V_5 , unsigned int V_78 ,
unsigned long V_142 )
{
const struct V_7 * V_8 = V_5 -> V_9 ;
struct V_14 * V_15 ;
unsigned int V_25 ;
int V_98 ;
V_98 = F_65 ( V_5 , V_8 -> V_143 ) ;
if ( V_98 )
return V_98 ;
for ( V_25 = 0 ; V_25 < V_5 -> V_144 ; V_25 ++ ) {
V_15 = & V_5 -> V_145 [ V_25 ] ;
switch ( V_8 -> V_146 [ V_25 ] ) {
case V_147 :
V_98 = F_50 ( V_5 , V_15 ,
V_8 -> V_148 [ V_25 ] ) ;
if ( V_98 < 0 )
return V_98 ;
break;
case V_149 :
V_98 = F_56 ( V_5 , V_15 ,
V_8 -> V_148 [ V_25 ] ) ;
if ( V_98 < 0 )
return V_98 ;
break;
case V_150 :
if ( V_78 && ! V_5 -> V_80 ) {
V_98 = F_34 ( V_5 , V_15 ,
V_151 ,
V_8 -> V_148 [ V_25 ] ) ;
if ( V_98 < 0 )
return V_98 ;
V_5 -> V_80 = V_15 ;
} else {
V_15 -> type = V_152 ;
}
break;
case V_153 :
V_15 -> type = V_154 ;
V_15 -> V_64 = V_65 | V_155 ;
V_15 -> V_68 = 1 ;
V_15 -> V_73 = 0xffffffff ;
V_15 -> V_109 = F_57 ;
V_15 -> V_111 = F_62 ;
break;
default:
V_15 -> type = V_152 ;
break;
}
}
if ( V_78 && V_5 -> V_80 ) {
if ( F_66 ( V_78 , F_37 , V_142 ,
V_5 -> V_156 , V_5 ) >= 0 ) {
V_5 -> V_78 = V_78 ;
} else {
F_67 ( V_5 -> V_157 ,
L_1 , V_78 ) ;
}
}
return 0 ;
}
static int T_2 F_68 ( void )
{
return 0 ;
}
static void T_3 F_69 ( void )
{
}
