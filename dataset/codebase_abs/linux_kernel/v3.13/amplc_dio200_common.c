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
struct V_12 * V_13 = V_9 -> V_14 ;
V_10 <<= V_11 -> V_15 ;
if ( V_13 -> V_16 . V_17 == V_18 )
return F_8 ( V_13 -> V_16 . V_19 . V_20 + V_10 ) ;
else
return F_9 ( V_13 -> V_16 . V_19 . V_21 + V_10 ) ;
}
static void F_10 ( struct V_8 * V_9 , unsigned int V_10 ,
unsigned char V_22 )
{
const struct V_5 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_9 -> V_14 ;
V_10 <<= V_11 -> V_15 ;
if ( V_13 -> V_16 . V_17 == V_18 )
F_11 ( V_22 , V_13 -> V_16 . V_19 . V_20 + V_10 ) ;
else
F_12 ( V_22 , V_13 -> V_16 . V_19 . V_21 + V_10 ) ;
}
static unsigned int F_13 ( struct V_8 * V_9 ,
unsigned int V_10 )
{
const struct V_5 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_9 -> V_14 ;
V_10 <<= V_11 -> V_15 ;
if ( V_13 -> V_16 . V_17 == V_18 )
return F_14 ( V_13 -> V_16 . V_19 . V_20 + V_10 ) ;
else
return F_15 ( V_13 -> V_16 . V_19 . V_21 + V_10 ) ;
}
static void F_16 ( struct V_8 * V_9 , unsigned int V_10 ,
unsigned int V_22 )
{
const struct V_5 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_9 -> V_14 ;
V_10 <<= V_11 -> V_15 ;
if ( V_13 -> V_16 . V_17 == V_18 )
F_17 ( V_22 , V_13 -> V_16 . V_19 . V_20 + V_10 ) ;
else
F_18 ( V_22 , V_13 -> V_16 . V_19 . V_21 + V_10 ) ;
}
static int
F_19 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
struct V_25 * V_26 , unsigned int * V_27 )
{
const struct V_4 * V_7 = F_5 ( V_9 ) ;
struct V_28 * V_29 = V_24 -> V_14 ;
if ( V_7 -> V_30 ) {
V_27 [ 1 ] = F_7 ( V_9 , V_29 -> V_31 ) & V_29 -> V_32 ;
} else {
V_27 [ 0 ] = 0 ;
}
return V_26 -> V_33 ;
}
static void F_20 ( struct V_8 * V_9 ,
struct V_23 * V_24 )
{
const struct V_4 * V_7 = F_5 ( V_9 ) ;
struct V_28 * V_29 = V_24 -> V_14 ;
V_29 -> V_34 = false ;
V_29 -> V_35 = 0 ;
if ( V_7 -> V_30 )
F_10 ( V_9 , V_29 -> V_31 , 0 ) ;
}
static int F_21 ( struct V_8 * V_9 ,
struct V_23 * V_24 )
{
unsigned int V_33 ;
unsigned V_36 ;
const struct V_4 * V_7 = F_5 ( V_9 ) ;
struct V_28 * V_29 = V_24 -> V_14 ;
struct V_37 * V_38 = & V_24 -> V_39 -> V_38 ;
int V_40 = 0 ;
if ( ! V_29 -> V_41 && V_29 -> V_42 == 0 ) {
V_24 -> V_39 -> V_43 |= V_44 ;
V_29 -> V_34 = false ;
V_40 = 1 ;
} else {
V_36 = 0 ;
if ( V_38 -> V_45 ) {
for ( V_33 = 0 ; V_33 < V_38 -> V_46 ; V_33 ++ )
V_36 |= ( 1U << F_22 ( V_38 -> V_45 [ V_33 ] ) ) ;
}
V_36 &= V_29 -> V_32 ;
V_29 -> V_35 = V_36 ;
if ( V_7 -> V_30 )
F_10 ( V_9 , V_29 -> V_31 , V_36 ) ;
}
return V_40 ;
}
static int
F_23 ( struct V_8 * V_9 , struct V_23 * V_24 ,
unsigned int V_47 )
{
struct V_28 * V_29 ;
unsigned long V_48 ;
int V_49 = 0 ;
if ( V_47 != 0 )
return - V_50 ;
V_29 = V_24 -> V_14 ;
F_24 ( & V_29 -> V_51 , V_48 ) ;
V_24 -> V_39 -> V_52 = NULL ;
if ( V_29 -> V_34 )
V_49 = F_21 ( V_9 , V_24 ) ;
F_25 ( & V_29 -> V_51 , V_48 ) ;
if ( V_49 )
F_26 ( V_9 , V_24 ) ;
return 1 ;
}
static void F_27 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
unsigned int V_53 )
{
struct V_28 * V_29 = V_24 -> V_14 ;
unsigned short V_22 ;
unsigned int V_33 , V_54 , V_55 ;
V_22 = 0 ;
V_55 = V_24 -> V_39 -> V_38 . V_46 ;
for ( V_33 = 0 ; V_33 < V_55 ; V_33 ++ ) {
V_54 = F_22 ( V_24 -> V_39 -> V_38 . V_45 [ V_33 ] ) ;
if ( V_53 & ( 1U << V_54 ) )
V_22 |= ( 1U << V_33 ) ;
}
if ( F_28 ( V_24 -> V_39 , V_22 ) ) {
V_24 -> V_39 -> V_43 |= ( V_56 | V_57 ) ;
} else {
F_20 ( V_9 , V_24 ) ;
V_24 -> V_39 -> V_43 |= V_58 | V_59 ;
F_29 ( V_9 , L_1 ) ;
}
if ( ! V_29 -> V_41 ) {
if ( V_29 -> V_42 > 0 ) {
V_29 -> V_42 -- ;
if ( V_29 -> V_42 == 0 ) {
V_24 -> V_39 -> V_43 |= V_44 ;
F_20 ( V_9 , V_24 ) ;
}
}
}
}
static int F_30 ( struct V_8 * V_9 ,
struct V_23 * V_24 )
{
const struct V_4 * V_7 = F_5 ( V_9 ) ;
struct V_28 * V_29 = V_24 -> V_14 ;
unsigned V_53 ;
unsigned V_60 ;
unsigned V_61 ;
unsigned int V_62 ;
unsigned long V_48 ;
V_53 = 0 ;
F_24 ( & V_29 -> V_51 , V_48 ) ;
V_62 = V_24 -> V_39 -> V_43 ;
if ( V_7 -> V_30 ) {
V_61 = V_29 -> V_35 ;
while ( ( V_60 = ( F_7 ( V_9 , V_29 -> V_31 ) &
V_29 -> V_32 & ~ V_53 ) ) != 0 ) {
V_53 |= V_60 ;
V_61 &= ~ V_53 ;
F_10 ( V_9 , V_29 -> V_31 , V_61 ) ;
}
} else {
V_53 = V_29 -> V_35 ;
}
if ( V_53 ) {
V_61 = V_29 -> V_35 ;
if ( V_7 -> V_30 )
F_10 ( V_9 , V_29 -> V_31 , V_61 ) ;
if ( V_29 -> V_34 ) {
if ( V_53 & V_29 -> V_35 )
F_27 ( V_9 , V_24 , V_53 ) ;
}
}
F_25 ( & V_29 -> V_51 , V_48 ) ;
if ( V_62 != V_24 -> V_39 -> V_43 )
F_26 ( V_9 , V_24 ) ;
return ( V_53 != 0 ) ;
}
static int F_31 ( struct V_8 * V_9 ,
struct V_23 * V_24 )
{
struct V_28 * V_29 = V_24 -> V_14 ;
unsigned long V_48 ;
F_24 ( & V_29 -> V_51 , V_48 ) ;
if ( V_29 -> V_34 )
F_20 ( V_9 , V_24 ) ;
F_25 ( & V_29 -> V_51 , V_48 ) ;
return 0 ;
}
static int
F_32 ( struct V_8 * V_9 ,
struct V_23 * V_24 , struct V_37 * V_38 )
{
int V_63 = 0 ;
V_63 |= F_33 ( & V_38 -> V_64 , V_65 | V_66 ) ;
V_63 |= F_33 ( & V_38 -> V_67 , V_68 ) ;
V_63 |= F_33 ( & V_38 -> V_69 , V_65 ) ;
V_63 |= F_33 ( & V_38 -> V_70 , V_71 ) ;
V_63 |= F_33 ( & V_38 -> V_72 , V_71 | V_73 ) ;
if ( V_63 )
return 1 ;
V_63 |= F_34 ( V_38 -> V_64 ) ;
V_63 |= F_34 ( V_38 -> V_72 ) ;
if ( V_63 )
return 2 ;
V_63 |= F_35 ( & V_38 -> V_74 , 0 ) ;
V_63 |= F_35 ( & V_38 -> V_75 , 0 ) ;
V_63 |= F_35 ( & V_38 -> V_76 , 0 ) ;
V_63 |= F_35 ( & V_38 -> V_77 , V_38 -> V_46 ) ;
switch ( V_38 -> V_72 ) {
case V_71 :
break;
case V_73 :
V_63 |= F_35 ( & V_38 -> V_78 , 0 ) ;
break;
default:
break;
}
if ( V_63 )
return 3 ;
return 0 ;
}
static int F_36 ( struct V_8 * V_9 ,
struct V_23 * V_24 )
{
struct V_37 * V_38 = & V_24 -> V_39 -> V_38 ;
struct V_28 * V_29 = V_24 -> V_14 ;
unsigned long V_48 ;
int V_49 = 0 ;
F_24 ( & V_29 -> V_51 , V_48 ) ;
V_29 -> V_34 = 1 ;
switch ( V_38 -> V_72 ) {
case V_71 :
V_29 -> V_41 = false ;
V_29 -> V_42 = V_38 -> V_78 ;
break;
default:
V_29 -> V_41 = true ;
V_29 -> V_42 = 0 ;
break;
}
switch ( V_38 -> V_64 ) {
case V_66 :
V_24 -> V_39 -> V_52 = F_23 ;
break;
default:
V_49 = F_21 ( V_9 , V_24 ) ;
break;
}
F_25 ( & V_29 -> V_51 , V_48 ) ;
if ( V_49 )
F_26 ( V_9 , V_24 ) ;
return 0 ;
}
static int
F_37 ( struct V_8 * V_9 , struct V_23 * V_24 ,
unsigned int V_10 , unsigned V_32 )
{
const struct V_4 * V_7 = F_5 ( V_9 ) ;
struct V_28 * V_29 ;
V_29 = F_38 ( V_24 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
return - V_79 ;
V_29 -> V_31 = V_10 ;
V_29 -> V_32 = V_32 ;
F_39 ( & V_29 -> V_51 ) ;
if ( V_7 -> V_30 )
F_10 ( V_9 , V_29 -> V_31 , 0 ) ;
V_24 -> type = V_80 ;
V_24 -> V_81 = V_82 | V_83 ;
if ( V_7 -> V_30 ) {
V_24 -> V_84 = V_85 ;
V_24 -> V_86 = V_85 ;
} else {
V_24 -> V_84 = 1 ;
V_24 -> V_86 = 1 ;
}
V_24 -> V_87 = & V_88 ;
V_24 -> V_89 = 1 ;
V_24 -> V_90 = F_19 ;
V_24 -> V_91 = F_32 ;
V_24 -> V_92 = F_36 ;
V_24 -> V_93 = F_31 ;
return 0 ;
}
static T_1 F_40 ( int V_94 , void * V_95 )
{
struct V_8 * V_9 = V_95 ;
struct V_12 * V_13 = V_9 -> V_14 ;
struct V_23 * V_24 ;
int V_96 ;
if ( ! V_9 -> V_97 )
return V_98 ;
if ( V_13 -> V_99 >= 0 ) {
V_24 = & V_9 -> V_100 [ V_13 -> V_99 ] ;
V_96 = F_30 ( V_9 , V_24 ) ;
} else {
V_96 = 0 ;
}
return F_41 ( V_96 ) ;
}
static unsigned int
F_42 ( struct V_8 * V_9 ,
struct V_23 * V_24 , unsigned int V_2 )
{
struct V_101 * V_29 = V_24 -> V_14 ;
unsigned int V_22 ;
V_22 = V_2 << 6 ;
F_10 ( V_9 , V_29 -> V_31 + V_102 , V_22 ) ;
V_22 = F_7 ( V_9 , V_29 -> V_31 + V_2 ) ;
V_22 += F_7 ( V_9 , V_29 -> V_31 + V_2 ) << 8 ;
return V_22 ;
}
static void
F_43 ( struct V_8 * V_9 ,
struct V_23 * V_24 , unsigned int V_2 ,
unsigned int V_103 )
{
struct V_101 * V_29 = V_24 -> V_14 ;
F_10 ( V_9 , V_29 -> V_31 + V_2 , V_103 & 0xff ) ;
F_10 ( V_9 , V_29 -> V_31 + V_2 , ( V_103 >> 8 ) & 0xff ) ;
}
static void
F_44 ( struct V_8 * V_9 ,
struct V_23 * V_24 , unsigned int V_2 ,
unsigned int V_104 )
{
struct V_101 * V_29 = V_24 -> V_14 ;
unsigned int V_105 ;
V_105 = V_2 << 6 ;
V_105 |= 0x30 ;
V_105 |= ( V_104 & 0xf ) ;
F_10 ( V_9 , V_29 -> V_31 + V_102 , V_105 ) ;
}
static unsigned int
F_45 ( struct V_8 * V_9 ,
struct V_23 * V_24 , unsigned int V_2 )
{
struct V_101 * V_29 = V_24 -> V_14 ;
F_10 ( V_9 , V_29 -> V_31 + V_102 ,
0xe0 | ( 2 << V_2 ) ) ;
return F_7 ( V_9 , V_29 -> V_31 + V_2 ) ;
}
static int
F_46 ( struct V_8 * V_9 , struct V_23 * V_24 ,
struct V_25 * V_26 , unsigned int * V_27 )
{
struct V_101 * V_29 = V_24 -> V_14 ;
int V_2 = F_22 ( V_26 -> V_106 ) ;
unsigned int V_33 ;
unsigned long V_48 ;
for ( V_33 = 0 ; V_33 < V_26 -> V_33 ; V_33 ++ ) {
F_24 ( & V_29 -> V_51 , V_48 ) ;
V_27 [ V_33 ] = F_42 ( V_9 , V_24 , V_2 ) ;
F_25 ( & V_29 -> V_51 , V_48 ) ;
}
return V_26 -> V_33 ;
}
static int
F_47 ( struct V_8 * V_9 , struct V_23 * V_24 ,
struct V_25 * V_26 , unsigned int * V_27 )
{
struct V_101 * V_29 = V_24 -> V_14 ;
int V_2 = F_22 ( V_26 -> V_106 ) ;
unsigned int V_33 ;
unsigned long V_48 ;
for ( V_33 = 0 ; V_33 < V_26 -> V_33 ; V_33 ++ ) {
F_24 ( & V_29 -> V_51 , V_48 ) ;
F_43 ( V_9 , V_24 , V_2 , V_27 [ V_33 ] ) ;
F_25 ( & V_29 -> V_51 , V_48 ) ;
}
return V_26 -> V_33 ;
}
static int
F_48 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
unsigned int V_107 ,
unsigned int V_108 )
{
const struct V_4 * V_7 = F_5 ( V_9 ) ;
struct V_101 * V_29 = V_24 -> V_14 ;
unsigned char V_105 ;
if ( ! V_7 -> V_109 )
return - 1 ;
if ( V_107 > 2 )
return - 1 ;
if ( V_108 > ( V_7 -> V_110 ? 31 : 7 ) )
return - 1 ;
V_29 -> V_108 [ V_107 ] = V_108 ;
V_105 = F_3 ( V_29 -> V_1 , V_107 , V_108 ) ;
F_10 ( V_9 , V_29 -> V_111 , V_105 ) ;
return 0 ;
}
static int
F_49 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
unsigned int V_107 )
{
const struct V_4 * V_7 = F_5 ( V_9 ) ;
struct V_101 * V_29 = V_24 -> V_14 ;
if ( ! V_7 -> V_109 )
return - 1 ;
if ( V_107 > 2 )
return - 1 ;
return V_29 -> V_108 [ V_107 ] ;
}
static int
F_50 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
unsigned int V_107 ,
unsigned int V_112 )
{
const struct V_4 * V_7 = F_5 ( V_9 ) ;
struct V_101 * V_29 = V_24 -> V_14 ;
unsigned char V_105 ;
if ( ! V_7 -> V_109 )
return - 1 ;
if ( V_107 > 2 )
return - 1 ;
if ( V_112 > ( V_7 -> V_110 ? 31 : 7 ) )
return - 1 ;
V_29 -> V_112 [ V_107 ] = V_112 ;
V_105 = F_2 ( V_29 -> V_1 , V_107 , V_112 ) ;
F_10 ( V_9 , V_29 -> V_113 , V_105 ) ;
return 0 ;
}
static int
F_51 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
unsigned int V_107 ,
unsigned int * V_114 )
{
const struct V_4 * V_7 = F_5 ( V_9 ) ;
struct V_101 * V_29 = V_24 -> V_14 ;
unsigned V_112 ;
if ( ! V_7 -> V_109 )
return - 1 ;
if ( V_107 > 2 )
return - 1 ;
V_112 = V_29 -> V_112 [ V_107 ] ;
* V_114 = V_115 [ V_112 ] ;
return V_112 ;
}
static int
F_52 ( struct V_8 * V_9 , struct V_23 * V_24 ,
struct V_25 * V_26 , unsigned int * V_27 )
{
struct V_101 * V_29 = V_24 -> V_14 ;
int V_116 = 0 ;
int V_2 = F_22 ( V_26 -> V_106 ) ;
unsigned long V_48 ;
F_24 ( & V_29 -> V_51 , V_48 ) ;
switch ( V_27 [ 0 ] ) {
case V_117 :
if ( V_27 [ 1 ] > ( V_118 | V_119 ) )
V_116 = - V_50 ;
else
F_44 ( V_9 , V_24 , V_2 , V_27 [ 1 ] ) ;
break;
case V_120 :
V_27 [ 1 ] = F_45 ( V_9 , V_24 , V_2 ) ;
break;
case V_121 :
V_116 = F_48 ( V_9 , V_24 , V_2 , V_27 [ 2 ] ) ;
if ( V_116 < 0 )
V_116 = - V_50 ;
break;
case V_122 :
V_116 = F_49 ( V_9 , V_24 , V_2 ) ;
if ( V_116 < 0 ) {
V_116 = - V_50 ;
break;
}
V_27 [ 2 ] = V_116 ;
break;
case V_123 :
V_116 = F_50 ( V_9 , V_24 , V_2 , V_27 [ 1 ] ) ;
if ( V_116 < 0 )
V_116 = - V_50 ;
break;
case V_124 :
V_116 = F_51 ( V_9 , V_24 , V_2 , & V_27 [ 2 ] ) ;
if ( V_116 < 0 ) {
V_116 = - V_50 ;
break;
}
V_27 [ 1 ] = V_116 ;
break;
default:
V_116 = - V_50 ;
break;
}
F_25 ( & V_29 -> V_51 , V_48 ) ;
return V_116 < 0 ? V_116 : V_26 -> V_33 ;
}
static int
F_53 ( struct V_8 * V_9 , struct V_23 * V_24 ,
unsigned int V_10 )
{
const struct V_4 * V_7 = F_5 ( V_9 ) ;
struct V_101 * V_29 ;
unsigned int V_2 ;
V_29 = F_38 ( V_24 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
return - V_79 ;
V_24 -> type = V_125 ;
V_24 -> V_81 = V_126 | V_82 ;
V_24 -> V_84 = 3 ;
V_24 -> V_89 = 0xFFFF ;
V_24 -> V_127 = F_46 ;
V_24 -> V_128 = F_47 ;
V_24 -> V_129 = F_52 ;
F_39 ( & V_29 -> V_51 ) ;
V_29 -> V_31 = V_10 ;
if ( V_7 -> V_109 ) {
V_29 -> V_113 = V_130 + ( V_10 >> 3 ) ;
V_29 -> V_111 = V_131 + ( V_10 >> 3 ) ;
V_29 -> V_1 = ( V_10 >> 2 ) & 1 ;
}
for ( V_2 = 0 ; V_2 < 3 ; V_2 ++ ) {
F_44 ( V_9 , V_24 , V_2 ,
V_132 | V_119 ) ;
if ( V_7 -> V_109 ) {
F_48 ( V_9 , V_24 , V_2 , 0 ) ;
F_50 ( V_9 , V_24 , V_2 , 0 ) ;
}
}
return 0 ;
}
static void F_54 ( struct V_8 * V_9 ,
struct V_23 * V_24 )
{
struct V_133 * V_29 = V_24 -> V_14 ;
int V_134 ;
V_134 = V_135 ;
if ( ! ( V_24 -> V_136 & 0x0000ff ) )
V_134 |= V_137 ;
if ( ! ( V_24 -> V_136 & 0x00ff00 ) )
V_134 |= V_138 ;
if ( ! ( V_24 -> V_136 & 0x0f0000 ) )
V_134 |= V_139 ;
if ( ! ( V_24 -> V_136 & 0xf00000 ) )
V_134 |= V_140 ;
F_10 ( V_9 , V_29 -> V_31 + 3 , V_134 ) ;
}
static int F_55 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
struct V_25 * V_26 ,
unsigned int * V_27 )
{
struct V_133 * V_29 = V_24 -> V_14 ;
unsigned int V_141 ;
unsigned int V_22 ;
V_141 = F_56 ( V_24 , V_27 ) ;
if ( V_141 ) {
if ( V_141 & 0xff )
F_10 ( V_9 , V_29 -> V_31 , V_24 -> V_142 & 0xff ) ;
if ( V_141 & 0xff00 )
F_10 ( V_9 , V_29 -> V_31 + 1 ,
( V_24 -> V_142 >> 8 ) & 0xff ) ;
if ( V_141 & 0xff0000 )
F_10 ( V_9 , V_29 -> V_31 + 2 ,
( V_24 -> V_142 >> 16 ) & 0xff ) ;
}
V_22 = F_7 ( V_9 , V_29 -> V_31 ) ;
V_22 |= F_7 ( V_9 , V_29 -> V_31 + 1 ) << 8 ;
V_22 |= F_7 ( V_9 , V_29 -> V_31 + 2 ) << 16 ;
V_27 [ 1 ] = V_22 ;
return V_26 -> V_33 ;
}
static int F_57 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
struct V_25 * V_26 ,
unsigned int * V_27 )
{
unsigned int V_2 = F_22 ( V_26 -> V_106 ) ;
unsigned int V_141 ;
int V_116 ;
if ( V_2 < 8 )
V_141 = 0x0000ff ;
else if ( V_2 < 16 )
V_141 = 0x00ff00 ;
else if ( V_2 < 20 )
V_141 = 0x0f0000 ;
else
V_141 = 0xf00000 ;
V_116 = F_58 ( V_9 , V_24 , V_26 , V_27 , V_141 ) ;
if ( V_116 )
return V_116 ;
F_54 ( V_9 , V_24 ) ;
return V_26 -> V_33 ;
}
static int F_59 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
unsigned int V_10 )
{
struct V_133 * V_29 ;
V_29 = F_38 ( V_24 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
return - V_79 ;
V_29 -> V_31 = V_10 ;
V_24 -> type = V_143 ;
V_24 -> V_81 = V_82 | V_126 ;
V_24 -> V_84 = 24 ;
V_24 -> V_87 = & V_88 ;
V_24 -> V_89 = 1 ;
V_24 -> V_90 = F_55 ;
V_24 -> V_129 = F_57 ;
F_54 ( V_9 , V_24 ) ;
return 0 ;
}
static int F_60 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
struct V_25 * V_26 ,
unsigned int * V_27 )
{
unsigned int V_33 ;
for ( V_33 = 0 ; V_33 < V_26 -> V_33 ; V_33 ++ )
V_27 [ V_33 ] = F_13 ( V_9 , V_144 ) ;
return V_33 ;
}
static void F_61 ( struct V_8 * V_9 ,
struct V_23 * V_24 )
{
unsigned int clock ;
clock = F_13 ( V_9 , V_145 ) & V_146 ;
F_16 ( V_9 , V_145 , clock | V_147 ) ;
F_16 ( V_9 , V_145 , clock ) ;
}
static void F_62 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
unsigned int * V_148 ,
unsigned int * V_149 )
{
unsigned int V_150 ;
V_150 = F_13 ( V_9 , V_145 ) & V_146 ;
* V_148 = V_150 ;
* V_149 = ( V_150 < F_63 ( V_151 ) ) ?
V_151 [ V_150 ] : 0 ;
}
static int F_64 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
unsigned int V_148 )
{
if ( V_148 > V_152 )
return - V_50 ;
F_16 ( V_9 , V_145 , V_148 ) ;
return 0 ;
}
static int F_65 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
struct V_25 * V_26 ,
unsigned int * V_27 )
{
int V_116 = 0 ;
switch ( V_27 [ 0 ] ) {
case V_153 :
F_61 ( V_9 , V_24 ) ;
break;
case V_123 :
V_116 = F_64 ( V_9 , V_24 , V_27 [ 1 ] ) ;
if ( V_116 < 0 )
V_116 = - V_50 ;
break;
case V_124 :
F_62 ( V_9 , V_24 , & V_27 [ 1 ] , & V_27 [ 2 ] ) ;
break;
default:
V_116 = - V_50 ;
break;
}
return V_116 < 0 ? V_116 : V_26 -> V_33 ;
}
static int F_66 ( struct V_8 * V_9 ,
struct V_23 * V_24 )
{
V_24 -> type = V_154 ;
V_24 -> V_81 = V_82 | V_155 ;
V_24 -> V_84 = 1 ;
V_24 -> V_89 = 0xFFFFFFFF ;
V_24 -> V_127 = F_60 ;
V_24 -> V_129 = F_65 ;
return 0 ;
}
void F_67 ( struct V_8 * V_9 , unsigned char V_22 )
{
F_10 ( V_9 , V_156 , V_22 ) ;
}
int F_68 ( struct V_8 * V_9 , unsigned int V_94 ,
unsigned long V_157 )
{
const struct V_5 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_9 -> V_14 ;
const struct V_4 * V_7 = F_4 ( V_11 ) ;
struct V_23 * V_24 ;
int V_158 ;
unsigned int V_33 ;
int V_116 ;
V_13 -> V_99 = - 1 ;
V_116 = F_69 ( V_9 , V_7 -> V_159 ) ;
if ( V_116 )
return V_116 ;
for ( V_33 = 0 ; V_33 < V_9 -> V_160 ; V_33 ++ ) {
V_24 = & V_9 -> V_100 [ V_33 ] ;
switch ( V_7 -> V_161 [ V_33 ] ) {
case V_162 :
V_116 = F_53 ( V_9 , V_24 ,
V_7 -> V_163 [ V_33 ] ) ;
if ( V_116 < 0 )
return V_116 ;
break;
case V_164 :
V_116 = F_59 ( V_9 , V_24 ,
V_7 -> V_163 [ V_33 ] ) ;
if ( V_116 < 0 )
return V_116 ;
break;
case V_165 :
if ( V_94 ) {
V_116 = F_37 ( V_9 , V_24 ,
V_166 ,
V_7 -> V_163 [ V_33 ]
) ;
if ( V_116 < 0 )
return V_116 ;
V_13 -> V_99 = V_33 ;
} else {
V_24 -> type = V_167 ;
}
break;
case V_168 :
V_116 = F_66 ( V_9 , V_24 ) ;
if ( V_116 < 0 )
return V_116 ;
break;
default:
V_24 -> type = V_167 ;
break;
}
}
V_158 = V_13 -> V_99 ;
if ( V_158 >= 0 && V_158 < V_9 -> V_160 )
V_9 -> V_169 = & V_9 -> V_100 [ V_158 ] ;
if ( V_94 ) {
if ( F_70 ( V_94 , F_40 , V_157 ,
V_9 -> V_170 , V_9 ) >= 0 ) {
V_9 -> V_94 = V_94 ;
} else {
F_71 ( V_9 -> V_171 ,
L_2 , V_94 ) ;
}
}
F_72 ( V_9 -> V_171 , L_3 ) ;
return 0 ;
}
void F_73 ( struct V_8 * V_9 )
{
const struct V_5 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_9 -> V_14 ;
if ( ! V_11 || ! V_13 )
return;
if ( V_9 -> V_94 )
F_74 ( V_9 -> V_94 , V_9 ) ;
}
static int T_2 F_75 ( void )
{
return 0 ;
}
static void T_3 F_76 ( void )
{
}
