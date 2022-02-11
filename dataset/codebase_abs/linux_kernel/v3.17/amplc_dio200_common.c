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
static inline const struct V_4 *
F_4 ( const struct V_5 * V_6 )
{
return & V_6 -> V_7 ;
}
static inline const struct V_4 *
F_5 ( struct V_8 * V_9 )
{
return F_4 ( F_6 ( V_9 ) ) ;
}
static unsigned char F_7 ( struct V_8 * V_9 ,
unsigned int V_10 )
{
const struct V_5 * V_11 = F_6 ( V_9 ) ;
V_10 <<= V_11 -> V_12 ;
if ( V_9 -> V_13 )
return F_8 ( V_9 -> V_13 + V_10 ) ;
return F_9 ( V_9 -> V_14 + V_10 ) ;
}
static void F_10 ( struct V_8 * V_9 , unsigned int V_10 ,
unsigned char V_15 )
{
const struct V_5 * V_11 = F_6 ( V_9 ) ;
V_10 <<= V_11 -> V_12 ;
if ( V_9 -> V_13 )
F_11 ( V_15 , V_9 -> V_13 + V_10 ) ;
else
F_12 ( V_15 , V_9 -> V_14 + V_10 ) ;
}
static unsigned int F_13 ( struct V_8 * V_9 ,
unsigned int V_10 )
{
const struct V_5 * V_11 = F_6 ( V_9 ) ;
V_10 <<= V_11 -> V_12 ;
if ( V_9 -> V_13 )
return F_14 ( V_9 -> V_13 + V_10 ) ;
return F_15 ( V_9 -> V_14 + V_10 ) ;
}
static void F_16 ( struct V_8 * V_9 , unsigned int V_10 ,
unsigned int V_15 )
{
const struct V_5 * V_11 = F_6 ( V_9 ) ;
V_10 <<= V_11 -> V_12 ;
if ( V_9 -> V_13 )
F_17 ( V_15 , V_9 -> V_13 + V_10 ) ;
else
F_18 ( V_15 , V_9 -> V_14 + V_10 ) ;
}
static int
F_19 ( struct V_8 * V_9 ,
struct V_16 * V_17 ,
struct V_18 * V_19 , unsigned int * V_20 )
{
const struct V_4 * V_7 = F_5 ( V_9 ) ;
struct V_21 * V_22 = V_17 -> V_23 ;
if ( V_7 -> V_24 ) {
V_20 [ 1 ] = F_7 ( V_9 , V_22 -> V_25 ) & V_22 -> V_26 ;
} else {
V_20 [ 0 ] = 0 ;
}
return V_19 -> V_27 ;
}
static void F_20 ( struct V_8 * V_9 ,
struct V_16 * V_17 )
{
const struct V_4 * V_7 = F_5 ( V_9 ) ;
struct V_21 * V_22 = V_17 -> V_23 ;
V_22 -> V_28 = false ;
V_22 -> V_29 = 0 ;
if ( V_7 -> V_24 )
F_10 ( V_9 , V_22 -> V_25 , 0 ) ;
}
static int F_21 ( struct V_8 * V_9 ,
struct V_16 * V_17 )
{
unsigned int V_27 ;
unsigned V_30 ;
const struct V_4 * V_7 = F_5 ( V_9 ) ;
struct V_21 * V_22 = V_17 -> V_23 ;
struct V_31 * V_32 = & V_17 -> V_33 -> V_32 ;
int V_34 = 0 ;
if ( V_32 -> V_35 == V_36 && V_22 -> V_37 == 0 ) {
V_17 -> V_33 -> V_38 |= V_39 ;
V_22 -> V_28 = false ;
V_34 = 1 ;
} else {
V_30 = 0 ;
if ( V_32 -> V_40 ) {
for ( V_27 = 0 ; V_27 < V_32 -> V_41 ; V_27 ++ )
V_30 |= ( 1U << F_22 ( V_32 -> V_40 [ V_27 ] ) ) ;
}
V_30 &= V_22 -> V_26 ;
V_22 -> V_29 = V_30 ;
if ( V_7 -> V_24 )
F_10 ( V_9 , V_22 -> V_25 , V_30 ) ;
}
return V_34 ;
}
static int F_23 ( struct V_8 * V_9 ,
struct V_16 * V_17 ,
unsigned int V_42 )
{
struct V_21 * V_22 = V_17 -> V_23 ;
struct V_31 * V_32 = & V_17 -> V_33 -> V_32 ;
unsigned long V_43 ;
int V_44 = 0 ;
if ( V_42 != V_32 -> V_45 )
return - V_46 ;
F_24 ( & V_22 -> V_47 , V_43 ) ;
V_17 -> V_33 -> V_48 = NULL ;
if ( V_22 -> V_28 )
V_44 = F_21 ( V_9 , V_17 ) ;
F_25 ( & V_22 -> V_47 , V_43 ) ;
if ( V_44 )
F_26 ( V_9 , V_17 ) ;
return 1 ;
}
static void F_27 ( struct V_8 * V_9 ,
struct V_16 * V_17 ,
unsigned int V_49 )
{
struct V_21 * V_22 = V_17 -> V_23 ;
struct V_31 * V_32 = & V_17 -> V_33 -> V_32 ;
unsigned short V_15 ;
unsigned int V_27 , V_50 ;
V_15 = 0 ;
for ( V_27 = 0 ; V_27 < V_32 -> V_41 ; V_27 ++ ) {
V_50 = F_22 ( V_32 -> V_40 [ V_27 ] ) ;
if ( V_49 & ( 1U << V_50 ) )
V_15 |= ( 1U << V_27 ) ;
}
if ( F_28 ( V_17 , V_15 ) ) {
V_17 -> V_33 -> V_38 |= ( V_51 | V_52 ) ;
} else {
F_20 ( V_9 , V_17 ) ;
V_17 -> V_33 -> V_38 |= V_53 | V_54 ;
F_29 ( V_9 -> V_55 , L_1 ) ;
}
if ( V_32 -> V_35 == V_36 ) {
if ( V_22 -> V_37 > 0 ) {
V_22 -> V_37 -- ;
if ( V_22 -> V_37 == 0 ) {
V_17 -> V_33 -> V_38 |= V_39 ;
F_20 ( V_9 , V_17 ) ;
}
}
}
}
static int F_30 ( struct V_8 * V_9 ,
struct V_16 * V_17 )
{
const struct V_4 * V_7 = F_5 ( V_9 ) ;
struct V_21 * V_22 = V_17 -> V_23 ;
unsigned V_49 ;
unsigned V_56 ;
unsigned V_57 ;
unsigned int V_58 ;
unsigned long V_43 ;
V_49 = 0 ;
F_24 ( & V_22 -> V_47 , V_43 ) ;
V_58 = V_17 -> V_33 -> V_38 ;
if ( V_7 -> V_24 ) {
V_57 = V_22 -> V_29 ;
while ( ( V_56 = ( F_7 ( V_9 , V_22 -> V_25 ) &
V_22 -> V_26 & ~ V_49 ) ) != 0 ) {
V_49 |= V_56 ;
V_57 &= ~ V_49 ;
F_10 ( V_9 , V_22 -> V_25 , V_57 ) ;
}
} else {
V_49 = V_22 -> V_29 ;
}
if ( V_49 ) {
V_57 = V_22 -> V_29 ;
if ( V_7 -> V_24 )
F_10 ( V_9 , V_22 -> V_25 , V_57 ) ;
if ( V_22 -> V_28 ) {
if ( V_49 & V_22 -> V_29 )
F_27 ( V_9 , V_17 , V_49 ) ;
}
}
F_25 ( & V_22 -> V_47 , V_43 ) ;
if ( V_58 != V_17 -> V_33 -> V_38 )
F_26 ( V_9 , V_17 ) ;
return ( V_49 != 0 ) ;
}
static int F_31 ( struct V_8 * V_9 ,
struct V_16 * V_17 )
{
struct V_21 * V_22 = V_17 -> V_23 ;
unsigned long V_43 ;
F_24 ( & V_22 -> V_47 , V_43 ) ;
if ( V_22 -> V_28 )
F_20 ( V_9 , V_17 ) ;
F_25 ( & V_22 -> V_47 , V_43 ) ;
return 0 ;
}
static int
F_32 ( struct V_8 * V_9 ,
struct V_16 * V_17 , struct V_31 * V_32 )
{
int V_59 = 0 ;
V_59 |= F_33 ( & V_32 -> V_60 , V_61 | V_62 ) ;
V_59 |= F_33 ( & V_32 -> V_63 , V_64 ) ;
V_59 |= F_33 ( & V_32 -> V_65 , V_61 ) ;
V_59 |= F_33 ( & V_32 -> V_66 , V_36 ) ;
V_59 |= F_33 ( & V_32 -> V_35 , V_36 | V_67 ) ;
if ( V_59 )
return 1 ;
V_59 |= F_34 ( V_32 -> V_60 ) ;
V_59 |= F_34 ( V_32 -> V_35 ) ;
if ( V_59 )
return 2 ;
V_59 |= F_35 ( & V_32 -> V_45 , 0 ) ;
V_59 |= F_35 ( & V_32 -> V_68 , 0 ) ;
V_59 |= F_35 ( & V_32 -> V_69 , 0 ) ;
V_59 |= F_35 ( & V_32 -> V_70 , V_32 -> V_41 ) ;
switch ( V_32 -> V_35 ) {
case V_36 :
break;
case V_67 :
V_59 |= F_35 ( & V_32 -> V_71 , 0 ) ;
break;
default:
break;
}
if ( V_59 )
return 3 ;
return 0 ;
}
static int F_36 ( struct V_8 * V_9 ,
struct V_16 * V_17 )
{
struct V_31 * V_32 = & V_17 -> V_33 -> V_32 ;
struct V_21 * V_22 = V_17 -> V_23 ;
unsigned long V_43 ;
int V_44 = 0 ;
F_24 ( & V_22 -> V_47 , V_43 ) ;
V_22 -> V_28 = true ;
if ( V_32 -> V_35 == V_36 )
V_22 -> V_37 = V_32 -> V_71 ;
else
V_22 -> V_37 = 0 ;
if ( V_32 -> V_60 == V_62 )
V_17 -> V_33 -> V_48 = F_23 ;
else
V_44 = F_21 ( V_9 , V_17 ) ;
F_25 ( & V_22 -> V_47 , V_43 ) ;
if ( V_44 )
F_26 ( V_9 , V_17 ) ;
return 0 ;
}
static int
F_37 ( struct V_8 * V_9 , struct V_16 * V_17 ,
unsigned int V_10 , unsigned V_26 )
{
const struct V_4 * V_7 = F_5 ( V_9 ) ;
struct V_21 * V_22 ;
V_22 = F_38 ( V_17 , sizeof( * V_22 ) ) ;
if ( ! V_22 )
return - V_72 ;
V_22 -> V_25 = V_10 ;
V_22 -> V_26 = V_26 ;
F_39 ( & V_22 -> V_47 ) ;
if ( V_7 -> V_24 )
F_10 ( V_9 , V_22 -> V_25 , 0 ) ;
V_17 -> type = V_73 ;
V_17 -> V_74 = V_75 | V_76 ;
if ( V_7 -> V_24 ) {
V_17 -> V_77 = V_78 ;
V_17 -> V_79 = V_78 ;
} else {
V_17 -> V_77 = 1 ;
V_17 -> V_79 = 1 ;
}
V_17 -> V_80 = & V_81 ;
V_17 -> V_82 = 1 ;
V_17 -> V_83 = F_19 ;
V_17 -> V_84 = F_32 ;
V_17 -> V_85 = F_36 ;
V_17 -> V_86 = F_31 ;
return 0 ;
}
static T_1 F_40 ( int V_87 , void * V_88 )
{
struct V_8 * V_9 = V_88 ;
struct V_89 * V_90 = V_9 -> V_23 ;
struct V_16 * V_17 ;
int V_91 ;
if ( ! V_9 -> V_92 )
return V_93 ;
if ( V_90 -> V_94 >= 0 ) {
V_17 = & V_9 -> V_95 [ V_90 -> V_94 ] ;
V_91 = F_30 ( V_9 , V_17 ) ;
} else {
V_91 = 0 ;
}
return F_41 ( V_91 ) ;
}
static unsigned int
F_42 ( struct V_8 * V_9 ,
struct V_16 * V_17 , unsigned int V_2 )
{
struct V_96 * V_22 = V_17 -> V_23 ;
unsigned int V_15 ;
V_15 = V_2 << 6 ;
F_10 ( V_9 , V_22 -> V_25 + V_97 , V_15 ) ;
V_15 = F_7 ( V_9 , V_22 -> V_25 + V_2 ) ;
V_15 += F_7 ( V_9 , V_22 -> V_25 + V_2 ) << 8 ;
return V_15 ;
}
static void
F_43 ( struct V_8 * V_9 ,
struct V_16 * V_17 , unsigned int V_2 ,
unsigned int V_98 )
{
struct V_96 * V_22 = V_17 -> V_23 ;
F_10 ( V_9 , V_22 -> V_25 + V_2 , V_98 & 0xff ) ;
F_10 ( V_9 , V_22 -> V_25 + V_2 , ( V_98 >> 8 ) & 0xff ) ;
}
static void
F_44 ( struct V_8 * V_9 ,
struct V_16 * V_17 , unsigned int V_2 ,
unsigned int V_99 )
{
struct V_96 * V_22 = V_17 -> V_23 ;
unsigned int V_100 ;
V_100 = V_2 << 6 ;
V_100 |= 0x30 ;
V_100 |= ( V_99 & 0xf ) ;
F_10 ( V_9 , V_22 -> V_25 + V_97 , V_100 ) ;
}
static unsigned int
F_45 ( struct V_8 * V_9 ,
struct V_16 * V_17 , unsigned int V_2 )
{
struct V_96 * V_22 = V_17 -> V_23 ;
F_10 ( V_9 , V_22 -> V_25 + V_97 ,
0xe0 | ( 2 << V_2 ) ) ;
return F_7 ( V_9 , V_22 -> V_25 + V_2 ) ;
}
static int
F_46 ( struct V_8 * V_9 , struct V_16 * V_17 ,
struct V_18 * V_19 , unsigned int * V_20 )
{
struct V_96 * V_22 = V_17 -> V_23 ;
int V_2 = F_22 ( V_19 -> V_101 ) ;
unsigned int V_27 ;
unsigned long V_43 ;
for ( V_27 = 0 ; V_27 < V_19 -> V_27 ; V_27 ++ ) {
F_24 ( & V_22 -> V_47 , V_43 ) ;
V_20 [ V_27 ] = F_42 ( V_9 , V_17 , V_2 ) ;
F_25 ( & V_22 -> V_47 , V_43 ) ;
}
return V_19 -> V_27 ;
}
static int
F_47 ( struct V_8 * V_9 , struct V_16 * V_17 ,
struct V_18 * V_19 , unsigned int * V_20 )
{
struct V_96 * V_22 = V_17 -> V_23 ;
int V_2 = F_22 ( V_19 -> V_101 ) ;
unsigned int V_27 ;
unsigned long V_43 ;
for ( V_27 = 0 ; V_27 < V_19 -> V_27 ; V_27 ++ ) {
F_24 ( & V_22 -> V_47 , V_43 ) ;
F_43 ( V_9 , V_17 , V_2 , V_20 [ V_27 ] ) ;
F_25 ( & V_22 -> V_47 , V_43 ) ;
}
return V_19 -> V_27 ;
}
static int
F_48 ( struct V_8 * V_9 ,
struct V_16 * V_17 ,
unsigned int V_102 ,
unsigned int V_103 )
{
const struct V_4 * V_7 = F_5 ( V_9 ) ;
struct V_96 * V_22 = V_17 -> V_23 ;
unsigned char V_100 ;
if ( ! V_7 -> V_104 )
return - 1 ;
if ( V_102 > 2 )
return - 1 ;
if ( V_103 > ( V_7 -> V_105 ? 31 : 7 ) )
return - 1 ;
V_22 -> V_103 [ V_102 ] = V_103 ;
V_100 = F_3 ( V_22 -> V_1 , V_102 , V_103 ) ;
F_10 ( V_9 , V_22 -> V_106 , V_100 ) ;
return 0 ;
}
static int
F_49 ( struct V_8 * V_9 ,
struct V_16 * V_17 ,
unsigned int V_102 )
{
const struct V_4 * V_7 = F_5 ( V_9 ) ;
struct V_96 * V_22 = V_17 -> V_23 ;
if ( ! V_7 -> V_104 )
return - 1 ;
if ( V_102 > 2 )
return - 1 ;
return V_22 -> V_103 [ V_102 ] ;
}
static int
F_50 ( struct V_8 * V_9 ,
struct V_16 * V_17 ,
unsigned int V_102 ,
unsigned int V_107 )
{
const struct V_4 * V_7 = F_5 ( V_9 ) ;
struct V_96 * V_22 = V_17 -> V_23 ;
unsigned char V_100 ;
if ( ! V_7 -> V_104 )
return - 1 ;
if ( V_102 > 2 )
return - 1 ;
if ( V_107 > ( V_7 -> V_105 ? 31 : 7 ) )
return - 1 ;
V_22 -> V_107 [ V_102 ] = V_107 ;
V_100 = F_2 ( V_22 -> V_1 , V_102 , V_107 ) ;
F_10 ( V_9 , V_22 -> V_108 , V_100 ) ;
return 0 ;
}
static int
F_51 ( struct V_8 * V_9 ,
struct V_16 * V_17 ,
unsigned int V_102 ,
unsigned int * V_109 )
{
const struct V_4 * V_7 = F_5 ( V_9 ) ;
struct V_96 * V_22 = V_17 -> V_23 ;
unsigned V_107 ;
if ( ! V_7 -> V_104 )
return - 1 ;
if ( V_102 > 2 )
return - 1 ;
V_107 = V_22 -> V_107 [ V_102 ] ;
* V_109 = V_110 [ V_107 ] ;
return V_107 ;
}
static int
F_52 ( struct V_8 * V_9 , struct V_16 * V_17 ,
struct V_18 * V_19 , unsigned int * V_20 )
{
struct V_96 * V_22 = V_17 -> V_23 ;
int V_111 = 0 ;
int V_2 = F_22 ( V_19 -> V_101 ) ;
unsigned long V_43 ;
F_24 ( & V_22 -> V_47 , V_43 ) ;
switch ( V_20 [ 0 ] ) {
case V_112 :
if ( V_20 [ 1 ] > ( V_113 | V_114 ) )
V_111 = - V_46 ;
else
F_44 ( V_9 , V_17 , V_2 , V_20 [ 1 ] ) ;
break;
case V_115 :
V_20 [ 1 ] = F_45 ( V_9 , V_17 , V_2 ) ;
break;
case V_116 :
V_111 = F_48 ( V_9 , V_17 , V_2 , V_20 [ 2 ] ) ;
if ( V_111 < 0 )
V_111 = - V_46 ;
break;
case V_117 :
V_111 = F_49 ( V_9 , V_17 , V_2 ) ;
if ( V_111 < 0 ) {
V_111 = - V_46 ;
break;
}
V_20 [ 2 ] = V_111 ;
break;
case V_118 :
V_111 = F_50 ( V_9 , V_17 , V_2 , V_20 [ 1 ] ) ;
if ( V_111 < 0 )
V_111 = - V_46 ;
break;
case V_119 :
V_111 = F_51 ( V_9 , V_17 , V_2 , & V_20 [ 2 ] ) ;
if ( V_111 < 0 ) {
V_111 = - V_46 ;
break;
}
V_20 [ 1 ] = V_111 ;
break;
default:
V_111 = - V_46 ;
break;
}
F_25 ( & V_22 -> V_47 , V_43 ) ;
return V_111 < 0 ? V_111 : V_19 -> V_27 ;
}
static int
F_53 ( struct V_8 * V_9 , struct V_16 * V_17 ,
unsigned int V_10 )
{
const struct V_4 * V_7 = F_5 ( V_9 ) ;
struct V_96 * V_22 ;
unsigned int V_2 ;
V_22 = F_38 ( V_17 , sizeof( * V_22 ) ) ;
if ( ! V_22 )
return - V_72 ;
V_17 -> type = V_120 ;
V_17 -> V_74 = V_121 | V_75 ;
V_17 -> V_77 = 3 ;
V_17 -> V_82 = 0xFFFF ;
V_17 -> V_122 = F_46 ;
V_17 -> V_123 = F_47 ;
V_17 -> V_124 = F_52 ;
F_39 ( & V_22 -> V_47 ) ;
V_22 -> V_25 = V_10 ;
if ( V_7 -> V_104 ) {
V_22 -> V_108 = V_125 + ( V_10 >> 3 ) ;
V_22 -> V_106 = V_126 + ( V_10 >> 3 ) ;
V_22 -> V_1 = ( V_10 >> 2 ) & 1 ;
}
for ( V_2 = 0 ; V_2 < 3 ; V_2 ++ ) {
F_44 ( V_9 , V_17 , V_2 ,
V_127 | V_128 ) ;
if ( V_7 -> V_104 ) {
F_48 ( V_9 , V_17 , V_2 , 0 ) ;
F_50 ( V_9 , V_17 , V_2 , 0 ) ;
}
}
return 0 ;
}
static void F_54 ( struct V_8 * V_9 ,
struct V_16 * V_17 )
{
struct V_129 * V_22 = V_17 -> V_23 ;
int V_130 ;
V_130 = V_131 ;
if ( ! ( V_17 -> V_132 & 0x0000ff ) )
V_130 |= V_133 ;
if ( ! ( V_17 -> V_132 & 0x00ff00 ) )
V_130 |= V_134 ;
if ( ! ( V_17 -> V_132 & 0x0f0000 ) )
V_130 |= V_135 ;
if ( ! ( V_17 -> V_132 & 0xf00000 ) )
V_130 |= V_136 ;
F_10 ( V_9 , V_22 -> V_25 + 3 , V_130 ) ;
}
static int F_55 ( struct V_8 * V_9 ,
struct V_16 * V_17 ,
struct V_18 * V_19 ,
unsigned int * V_20 )
{
struct V_129 * V_22 = V_17 -> V_23 ;
unsigned int V_137 ;
unsigned int V_15 ;
V_137 = F_56 ( V_17 , V_20 ) ;
if ( V_137 ) {
if ( V_137 & 0xff )
F_10 ( V_9 , V_22 -> V_25 , V_17 -> V_138 & 0xff ) ;
if ( V_137 & 0xff00 )
F_10 ( V_9 , V_22 -> V_25 + 1 ,
( V_17 -> V_138 >> 8 ) & 0xff ) ;
if ( V_137 & 0xff0000 )
F_10 ( V_9 , V_22 -> V_25 + 2 ,
( V_17 -> V_138 >> 16 ) & 0xff ) ;
}
V_15 = F_7 ( V_9 , V_22 -> V_25 ) ;
V_15 |= F_7 ( V_9 , V_22 -> V_25 + 1 ) << 8 ;
V_15 |= F_7 ( V_9 , V_22 -> V_25 + 2 ) << 16 ;
V_20 [ 1 ] = V_15 ;
return V_19 -> V_27 ;
}
static int F_57 ( struct V_8 * V_9 ,
struct V_16 * V_17 ,
struct V_18 * V_19 ,
unsigned int * V_20 )
{
unsigned int V_2 = F_22 ( V_19 -> V_101 ) ;
unsigned int V_137 ;
int V_111 ;
if ( V_2 < 8 )
V_137 = 0x0000ff ;
else if ( V_2 < 16 )
V_137 = 0x00ff00 ;
else if ( V_2 < 20 )
V_137 = 0x0f0000 ;
else
V_137 = 0xf00000 ;
V_111 = F_58 ( V_9 , V_17 , V_19 , V_20 , V_137 ) ;
if ( V_111 )
return V_111 ;
F_54 ( V_9 , V_17 ) ;
return V_19 -> V_27 ;
}
static int F_59 ( struct V_8 * V_9 ,
struct V_16 * V_17 ,
unsigned int V_10 )
{
struct V_129 * V_22 ;
V_22 = F_38 ( V_17 , sizeof( * V_22 ) ) ;
if ( ! V_22 )
return - V_72 ;
V_22 -> V_25 = V_10 ;
V_17 -> type = V_139 ;
V_17 -> V_74 = V_75 | V_121 ;
V_17 -> V_77 = 24 ;
V_17 -> V_80 = & V_81 ;
V_17 -> V_82 = 1 ;
V_17 -> V_83 = F_55 ;
V_17 -> V_124 = F_57 ;
F_54 ( V_9 , V_17 ) ;
return 0 ;
}
static int F_60 ( struct V_8 * V_9 ,
struct V_16 * V_17 ,
struct V_18 * V_19 ,
unsigned int * V_20 )
{
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_19 -> V_27 ; V_27 ++ )
V_20 [ V_27 ] = F_13 ( V_9 , V_140 ) ;
return V_27 ;
}
static void F_61 ( struct V_8 * V_9 ,
struct V_16 * V_17 )
{
unsigned int clock ;
clock = F_13 ( V_9 , V_141 ) & V_142 ;
F_16 ( V_9 , V_141 , clock | V_143 ) ;
F_16 ( V_9 , V_141 , clock ) ;
}
static void F_62 ( struct V_8 * V_9 ,
struct V_16 * V_17 ,
unsigned int * V_144 ,
unsigned int * V_145 )
{
unsigned int V_146 ;
V_146 = F_13 ( V_9 , V_141 ) & V_142 ;
* V_144 = V_146 ;
* V_145 = ( V_146 < F_63 ( V_147 ) ) ?
V_147 [ V_146 ] : 0 ;
}
static int F_64 ( struct V_8 * V_9 ,
struct V_16 * V_17 ,
unsigned int V_144 )
{
if ( V_144 > V_148 )
return - V_46 ;
F_16 ( V_9 , V_141 , V_144 ) ;
return 0 ;
}
static int F_65 ( struct V_8 * V_9 ,
struct V_16 * V_17 ,
struct V_18 * V_19 ,
unsigned int * V_20 )
{
int V_111 = 0 ;
switch ( V_20 [ 0 ] ) {
case V_149 :
F_61 ( V_9 , V_17 ) ;
break;
case V_118 :
V_111 = F_64 ( V_9 , V_17 , V_20 [ 1 ] ) ;
if ( V_111 < 0 )
V_111 = - V_46 ;
break;
case V_119 :
F_62 ( V_9 , V_17 , & V_20 [ 1 ] , & V_20 [ 2 ] ) ;
break;
default:
V_111 = - V_46 ;
break;
}
return V_111 < 0 ? V_111 : V_19 -> V_27 ;
}
static int F_66 ( struct V_8 * V_9 ,
struct V_16 * V_17 )
{
V_17 -> type = V_150 ;
V_17 -> V_74 = V_75 | V_151 ;
V_17 -> V_77 = 1 ;
V_17 -> V_82 = 0xFFFFFFFF ;
V_17 -> V_122 = F_60 ;
V_17 -> V_124 = F_65 ;
return 0 ;
}
void F_67 ( struct V_8 * V_9 , unsigned char V_15 )
{
F_10 ( V_9 , V_152 , V_15 ) ;
}
int F_68 ( struct V_8 * V_9 , unsigned int V_87 ,
unsigned long V_153 )
{
const struct V_5 * V_11 = F_6 ( V_9 ) ;
struct V_89 * V_90 = V_9 -> V_23 ;
const struct V_4 * V_7 = F_4 ( V_11 ) ;
struct V_16 * V_17 ;
int V_154 ;
unsigned int V_27 ;
int V_111 ;
V_90 -> V_94 = - 1 ;
V_111 = F_69 ( V_9 , V_7 -> V_155 ) ;
if ( V_111 )
return V_111 ;
for ( V_27 = 0 ; V_27 < V_9 -> V_156 ; V_27 ++ ) {
V_17 = & V_9 -> V_95 [ V_27 ] ;
switch ( V_7 -> V_157 [ V_27 ] ) {
case V_158 :
V_111 = F_53 ( V_9 , V_17 ,
V_7 -> V_159 [ V_27 ] ) ;
if ( V_111 < 0 )
return V_111 ;
break;
case V_160 :
V_111 = F_59 ( V_9 , V_17 ,
V_7 -> V_159 [ V_27 ] ) ;
if ( V_111 < 0 )
return V_111 ;
break;
case V_161 :
if ( V_87 ) {
V_111 = F_37 ( V_9 , V_17 ,
V_162 ,
V_7 -> V_159 [ V_27 ]
) ;
if ( V_111 < 0 )
return V_111 ;
V_90 -> V_94 = V_27 ;
} else {
V_17 -> type = V_163 ;
}
break;
case V_164 :
V_111 = F_66 ( V_9 , V_17 ) ;
if ( V_111 < 0 )
return V_111 ;
break;
default:
V_17 -> type = V_163 ;
break;
}
}
V_154 = V_90 -> V_94 ;
if ( V_154 >= 0 && V_154 < V_9 -> V_156 )
V_9 -> V_165 = & V_9 -> V_95 [ V_154 ] ;
if ( V_87 ) {
if ( F_70 ( V_87 , F_40 , V_153 ,
V_9 -> V_166 , V_9 ) >= 0 ) {
V_9 -> V_87 = V_87 ;
} else {
F_71 ( V_9 -> V_55 ,
L_2 , V_87 ) ;
}
}
return 0 ;
}
void F_72 ( struct V_8 * V_9 )
{
if ( V_9 -> V_87 ) {
F_73 ( V_9 -> V_87 , V_9 ) ;
V_9 -> V_87 = 0 ;
}
}
static int T_2 F_74 ( void )
{
return 0 ;
}
static void T_3 F_75 ( void )
{
}
