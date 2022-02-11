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
if ( V_38 -> V_41 == V_42 && V_29 -> V_43 == 0 ) {
V_24 -> V_39 -> V_44 |= V_45 ;
V_29 -> V_34 = false ;
V_40 = 1 ;
} else {
V_36 = 0 ;
if ( V_38 -> V_46 ) {
for ( V_33 = 0 ; V_33 < V_38 -> V_47 ; V_33 ++ )
V_36 |= ( 1U << F_22 ( V_38 -> V_46 [ V_33 ] ) ) ;
}
V_36 &= V_29 -> V_32 ;
V_29 -> V_35 = V_36 ;
if ( V_7 -> V_30 )
F_10 ( V_9 , V_29 -> V_31 , V_36 ) ;
}
return V_40 ;
}
static int F_23 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
unsigned int V_48 )
{
struct V_28 * V_29 = V_24 -> V_14 ;
struct V_37 * V_38 = & V_24 -> V_39 -> V_38 ;
unsigned long V_49 ;
int V_50 = 0 ;
if ( V_48 != V_38 -> V_51 )
return - V_52 ;
F_24 ( & V_29 -> V_53 , V_49 ) ;
V_24 -> V_39 -> V_54 = NULL ;
if ( V_29 -> V_34 )
V_50 = F_21 ( V_9 , V_24 ) ;
F_25 ( & V_29 -> V_53 , V_49 ) ;
if ( V_50 )
F_26 ( V_9 , V_24 ) ;
return 1 ;
}
static void F_27 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
unsigned int V_55 )
{
struct V_28 * V_29 = V_24 -> V_14 ;
struct V_37 * V_38 = & V_24 -> V_39 -> V_38 ;
unsigned short V_22 ;
unsigned int V_33 , V_56 ;
V_22 = 0 ;
for ( V_33 = 0 ; V_33 < V_38 -> V_47 ; V_33 ++ ) {
V_56 = F_22 ( V_38 -> V_46 [ V_33 ] ) ;
if ( V_55 & ( 1U << V_56 ) )
V_22 |= ( 1U << V_33 ) ;
}
if ( F_28 ( V_24 , V_22 ) ) {
V_24 -> V_39 -> V_44 |= ( V_57 | V_58 ) ;
} else {
F_20 ( V_9 , V_24 ) ;
V_24 -> V_39 -> V_44 |= V_59 | V_60 ;
F_29 ( V_9 , L_1 ) ;
}
if ( V_38 -> V_41 == V_42 ) {
if ( V_29 -> V_43 > 0 ) {
V_29 -> V_43 -- ;
if ( V_29 -> V_43 == 0 ) {
V_24 -> V_39 -> V_44 |= V_45 ;
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
unsigned V_55 ;
unsigned V_61 ;
unsigned V_62 ;
unsigned int V_63 ;
unsigned long V_49 ;
V_55 = 0 ;
F_24 ( & V_29 -> V_53 , V_49 ) ;
V_63 = V_24 -> V_39 -> V_44 ;
if ( V_7 -> V_30 ) {
V_62 = V_29 -> V_35 ;
while ( ( V_61 = ( F_7 ( V_9 , V_29 -> V_31 ) &
V_29 -> V_32 & ~ V_55 ) ) != 0 ) {
V_55 |= V_61 ;
V_62 &= ~ V_55 ;
F_10 ( V_9 , V_29 -> V_31 , V_62 ) ;
}
} else {
V_55 = V_29 -> V_35 ;
}
if ( V_55 ) {
V_62 = V_29 -> V_35 ;
if ( V_7 -> V_30 )
F_10 ( V_9 , V_29 -> V_31 , V_62 ) ;
if ( V_29 -> V_34 ) {
if ( V_55 & V_29 -> V_35 )
F_27 ( V_9 , V_24 , V_55 ) ;
}
}
F_25 ( & V_29 -> V_53 , V_49 ) ;
if ( V_63 != V_24 -> V_39 -> V_44 )
F_26 ( V_9 , V_24 ) ;
return ( V_55 != 0 ) ;
}
static int F_31 ( struct V_8 * V_9 ,
struct V_23 * V_24 )
{
struct V_28 * V_29 = V_24 -> V_14 ;
unsigned long V_49 ;
F_24 ( & V_29 -> V_53 , V_49 ) ;
if ( V_29 -> V_34 )
F_20 ( V_9 , V_24 ) ;
F_25 ( & V_29 -> V_53 , V_49 ) ;
return 0 ;
}
static int
F_32 ( struct V_8 * V_9 ,
struct V_23 * V_24 , struct V_37 * V_38 )
{
int V_64 = 0 ;
V_64 |= F_33 ( & V_38 -> V_65 , V_66 | V_67 ) ;
V_64 |= F_33 ( & V_38 -> V_68 , V_69 ) ;
V_64 |= F_33 ( & V_38 -> V_70 , V_66 ) ;
V_64 |= F_33 ( & V_38 -> V_71 , V_42 ) ;
V_64 |= F_33 ( & V_38 -> V_41 , V_42 | V_72 ) ;
if ( V_64 )
return 1 ;
V_64 |= F_34 ( V_38 -> V_65 ) ;
V_64 |= F_34 ( V_38 -> V_41 ) ;
if ( V_64 )
return 2 ;
V_64 |= F_35 ( & V_38 -> V_51 , 0 ) ;
V_64 |= F_35 ( & V_38 -> V_73 , 0 ) ;
V_64 |= F_35 ( & V_38 -> V_74 , 0 ) ;
V_64 |= F_35 ( & V_38 -> V_75 , V_38 -> V_47 ) ;
switch ( V_38 -> V_41 ) {
case V_42 :
break;
case V_72 :
V_64 |= F_35 ( & V_38 -> V_76 , 0 ) ;
break;
default:
break;
}
if ( V_64 )
return 3 ;
return 0 ;
}
static int F_36 ( struct V_8 * V_9 ,
struct V_23 * V_24 )
{
struct V_37 * V_38 = & V_24 -> V_39 -> V_38 ;
struct V_28 * V_29 = V_24 -> V_14 ;
unsigned long V_49 ;
int V_50 = 0 ;
F_24 ( & V_29 -> V_53 , V_49 ) ;
V_29 -> V_34 = true ;
if ( V_38 -> V_41 == V_42 )
V_29 -> V_43 = V_38 -> V_76 ;
else
V_29 -> V_43 = 0 ;
if ( V_38 -> V_65 == V_67 )
V_24 -> V_39 -> V_54 = F_23 ;
else
V_50 = F_21 ( V_9 , V_24 ) ;
F_25 ( & V_29 -> V_53 , V_49 ) ;
if ( V_50 )
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
return - V_77 ;
V_29 -> V_31 = V_10 ;
V_29 -> V_32 = V_32 ;
F_39 ( & V_29 -> V_53 ) ;
if ( V_7 -> V_30 )
F_10 ( V_9 , V_29 -> V_31 , 0 ) ;
V_24 -> type = V_78 ;
V_24 -> V_79 = V_80 | V_81 ;
if ( V_7 -> V_30 ) {
V_24 -> V_82 = V_83 ;
V_24 -> V_84 = V_83 ;
} else {
V_24 -> V_82 = 1 ;
V_24 -> V_84 = 1 ;
}
V_24 -> V_85 = & V_86 ;
V_24 -> V_87 = 1 ;
V_24 -> V_88 = F_19 ;
V_24 -> V_89 = F_32 ;
V_24 -> V_90 = F_36 ;
V_24 -> V_91 = F_31 ;
return 0 ;
}
static T_1 F_40 ( int V_92 , void * V_93 )
{
struct V_8 * V_9 = V_93 ;
struct V_12 * V_13 = V_9 -> V_14 ;
struct V_23 * V_24 ;
int V_94 ;
if ( ! V_9 -> V_95 )
return V_96 ;
if ( V_13 -> V_97 >= 0 ) {
V_24 = & V_9 -> V_98 [ V_13 -> V_97 ] ;
V_94 = F_30 ( V_9 , V_24 ) ;
} else {
V_94 = 0 ;
}
return F_41 ( V_94 ) ;
}
static unsigned int
F_42 ( struct V_8 * V_9 ,
struct V_23 * V_24 , unsigned int V_2 )
{
struct V_99 * V_29 = V_24 -> V_14 ;
unsigned int V_22 ;
V_22 = V_2 << 6 ;
F_10 ( V_9 , V_29 -> V_31 + V_100 , V_22 ) ;
V_22 = F_7 ( V_9 , V_29 -> V_31 + V_2 ) ;
V_22 += F_7 ( V_9 , V_29 -> V_31 + V_2 ) << 8 ;
return V_22 ;
}
static void
F_43 ( struct V_8 * V_9 ,
struct V_23 * V_24 , unsigned int V_2 ,
unsigned int V_101 )
{
struct V_99 * V_29 = V_24 -> V_14 ;
F_10 ( V_9 , V_29 -> V_31 + V_2 , V_101 & 0xff ) ;
F_10 ( V_9 , V_29 -> V_31 + V_2 , ( V_101 >> 8 ) & 0xff ) ;
}
static void
F_44 ( struct V_8 * V_9 ,
struct V_23 * V_24 , unsigned int V_2 ,
unsigned int V_102 )
{
struct V_99 * V_29 = V_24 -> V_14 ;
unsigned int V_103 ;
V_103 = V_2 << 6 ;
V_103 |= 0x30 ;
V_103 |= ( V_102 & 0xf ) ;
F_10 ( V_9 , V_29 -> V_31 + V_100 , V_103 ) ;
}
static unsigned int
F_45 ( struct V_8 * V_9 ,
struct V_23 * V_24 , unsigned int V_2 )
{
struct V_99 * V_29 = V_24 -> V_14 ;
F_10 ( V_9 , V_29 -> V_31 + V_100 ,
0xe0 | ( 2 << V_2 ) ) ;
return F_7 ( V_9 , V_29 -> V_31 + V_2 ) ;
}
static int
F_46 ( struct V_8 * V_9 , struct V_23 * V_24 ,
struct V_25 * V_26 , unsigned int * V_27 )
{
struct V_99 * V_29 = V_24 -> V_14 ;
int V_2 = F_22 ( V_26 -> V_104 ) ;
unsigned int V_33 ;
unsigned long V_49 ;
for ( V_33 = 0 ; V_33 < V_26 -> V_33 ; V_33 ++ ) {
F_24 ( & V_29 -> V_53 , V_49 ) ;
V_27 [ V_33 ] = F_42 ( V_9 , V_24 , V_2 ) ;
F_25 ( & V_29 -> V_53 , V_49 ) ;
}
return V_26 -> V_33 ;
}
static int
F_47 ( struct V_8 * V_9 , struct V_23 * V_24 ,
struct V_25 * V_26 , unsigned int * V_27 )
{
struct V_99 * V_29 = V_24 -> V_14 ;
int V_2 = F_22 ( V_26 -> V_104 ) ;
unsigned int V_33 ;
unsigned long V_49 ;
for ( V_33 = 0 ; V_33 < V_26 -> V_33 ; V_33 ++ ) {
F_24 ( & V_29 -> V_53 , V_49 ) ;
F_43 ( V_9 , V_24 , V_2 , V_27 [ V_33 ] ) ;
F_25 ( & V_29 -> V_53 , V_49 ) ;
}
return V_26 -> V_33 ;
}
static int
F_48 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
unsigned int V_105 ,
unsigned int V_106 )
{
const struct V_4 * V_7 = F_5 ( V_9 ) ;
struct V_99 * V_29 = V_24 -> V_14 ;
unsigned char V_103 ;
if ( ! V_7 -> V_107 )
return - 1 ;
if ( V_105 > 2 )
return - 1 ;
if ( V_106 > ( V_7 -> V_108 ? 31 : 7 ) )
return - 1 ;
V_29 -> V_106 [ V_105 ] = V_106 ;
V_103 = F_3 ( V_29 -> V_1 , V_105 , V_106 ) ;
F_10 ( V_9 , V_29 -> V_109 , V_103 ) ;
return 0 ;
}
static int
F_49 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
unsigned int V_105 )
{
const struct V_4 * V_7 = F_5 ( V_9 ) ;
struct V_99 * V_29 = V_24 -> V_14 ;
if ( ! V_7 -> V_107 )
return - 1 ;
if ( V_105 > 2 )
return - 1 ;
return V_29 -> V_106 [ V_105 ] ;
}
static int
F_50 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
unsigned int V_105 ,
unsigned int V_110 )
{
const struct V_4 * V_7 = F_5 ( V_9 ) ;
struct V_99 * V_29 = V_24 -> V_14 ;
unsigned char V_103 ;
if ( ! V_7 -> V_107 )
return - 1 ;
if ( V_105 > 2 )
return - 1 ;
if ( V_110 > ( V_7 -> V_108 ? 31 : 7 ) )
return - 1 ;
V_29 -> V_110 [ V_105 ] = V_110 ;
V_103 = F_2 ( V_29 -> V_1 , V_105 , V_110 ) ;
F_10 ( V_9 , V_29 -> V_111 , V_103 ) ;
return 0 ;
}
static int
F_51 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
unsigned int V_105 ,
unsigned int * V_112 )
{
const struct V_4 * V_7 = F_5 ( V_9 ) ;
struct V_99 * V_29 = V_24 -> V_14 ;
unsigned V_110 ;
if ( ! V_7 -> V_107 )
return - 1 ;
if ( V_105 > 2 )
return - 1 ;
V_110 = V_29 -> V_110 [ V_105 ] ;
* V_112 = V_113 [ V_110 ] ;
return V_110 ;
}
static int
F_52 ( struct V_8 * V_9 , struct V_23 * V_24 ,
struct V_25 * V_26 , unsigned int * V_27 )
{
struct V_99 * V_29 = V_24 -> V_14 ;
int V_114 = 0 ;
int V_2 = F_22 ( V_26 -> V_104 ) ;
unsigned long V_49 ;
F_24 ( & V_29 -> V_53 , V_49 ) ;
switch ( V_27 [ 0 ] ) {
case V_115 :
if ( V_27 [ 1 ] > ( V_116 | V_117 ) )
V_114 = - V_52 ;
else
F_44 ( V_9 , V_24 , V_2 , V_27 [ 1 ] ) ;
break;
case V_118 :
V_27 [ 1 ] = F_45 ( V_9 , V_24 , V_2 ) ;
break;
case V_119 :
V_114 = F_48 ( V_9 , V_24 , V_2 , V_27 [ 2 ] ) ;
if ( V_114 < 0 )
V_114 = - V_52 ;
break;
case V_120 :
V_114 = F_49 ( V_9 , V_24 , V_2 ) ;
if ( V_114 < 0 ) {
V_114 = - V_52 ;
break;
}
V_27 [ 2 ] = V_114 ;
break;
case V_121 :
V_114 = F_50 ( V_9 , V_24 , V_2 , V_27 [ 1 ] ) ;
if ( V_114 < 0 )
V_114 = - V_52 ;
break;
case V_122 :
V_114 = F_51 ( V_9 , V_24 , V_2 , & V_27 [ 2 ] ) ;
if ( V_114 < 0 ) {
V_114 = - V_52 ;
break;
}
V_27 [ 1 ] = V_114 ;
break;
default:
V_114 = - V_52 ;
break;
}
F_25 ( & V_29 -> V_53 , V_49 ) ;
return V_114 < 0 ? V_114 : V_26 -> V_33 ;
}
static int
F_53 ( struct V_8 * V_9 , struct V_23 * V_24 ,
unsigned int V_10 )
{
const struct V_4 * V_7 = F_5 ( V_9 ) ;
struct V_99 * V_29 ;
unsigned int V_2 ;
V_29 = F_38 ( V_24 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
return - V_77 ;
V_24 -> type = V_123 ;
V_24 -> V_79 = V_124 | V_80 ;
V_24 -> V_82 = 3 ;
V_24 -> V_87 = 0xFFFF ;
V_24 -> V_125 = F_46 ;
V_24 -> V_126 = F_47 ;
V_24 -> V_127 = F_52 ;
F_39 ( & V_29 -> V_53 ) ;
V_29 -> V_31 = V_10 ;
if ( V_7 -> V_107 ) {
V_29 -> V_111 = V_128 + ( V_10 >> 3 ) ;
V_29 -> V_109 = V_129 + ( V_10 >> 3 ) ;
V_29 -> V_1 = ( V_10 >> 2 ) & 1 ;
}
for ( V_2 = 0 ; V_2 < 3 ; V_2 ++ ) {
F_44 ( V_9 , V_24 , V_2 ,
V_130 | V_131 ) ;
if ( V_7 -> V_107 ) {
F_48 ( V_9 , V_24 , V_2 , 0 ) ;
F_50 ( V_9 , V_24 , V_2 , 0 ) ;
}
}
return 0 ;
}
static void F_54 ( struct V_8 * V_9 ,
struct V_23 * V_24 )
{
struct V_132 * V_29 = V_24 -> V_14 ;
int V_133 ;
V_133 = V_134 ;
if ( ! ( V_24 -> V_135 & 0x0000ff ) )
V_133 |= V_136 ;
if ( ! ( V_24 -> V_135 & 0x00ff00 ) )
V_133 |= V_137 ;
if ( ! ( V_24 -> V_135 & 0x0f0000 ) )
V_133 |= V_138 ;
if ( ! ( V_24 -> V_135 & 0xf00000 ) )
V_133 |= V_139 ;
F_10 ( V_9 , V_29 -> V_31 + 3 , V_133 ) ;
}
static int F_55 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
struct V_25 * V_26 ,
unsigned int * V_27 )
{
struct V_132 * V_29 = V_24 -> V_14 ;
unsigned int V_140 ;
unsigned int V_22 ;
V_140 = F_56 ( V_24 , V_27 ) ;
if ( V_140 ) {
if ( V_140 & 0xff )
F_10 ( V_9 , V_29 -> V_31 , V_24 -> V_141 & 0xff ) ;
if ( V_140 & 0xff00 )
F_10 ( V_9 , V_29 -> V_31 + 1 ,
( V_24 -> V_141 >> 8 ) & 0xff ) ;
if ( V_140 & 0xff0000 )
F_10 ( V_9 , V_29 -> V_31 + 2 ,
( V_24 -> V_141 >> 16 ) & 0xff ) ;
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
unsigned int V_2 = F_22 ( V_26 -> V_104 ) ;
unsigned int V_140 ;
int V_114 ;
if ( V_2 < 8 )
V_140 = 0x0000ff ;
else if ( V_2 < 16 )
V_140 = 0x00ff00 ;
else if ( V_2 < 20 )
V_140 = 0x0f0000 ;
else
V_140 = 0xf00000 ;
V_114 = F_58 ( V_9 , V_24 , V_26 , V_27 , V_140 ) ;
if ( V_114 )
return V_114 ;
F_54 ( V_9 , V_24 ) ;
return V_26 -> V_33 ;
}
static int F_59 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
unsigned int V_10 )
{
struct V_132 * V_29 ;
V_29 = F_38 ( V_24 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
return - V_77 ;
V_29 -> V_31 = V_10 ;
V_24 -> type = V_142 ;
V_24 -> V_79 = V_80 | V_124 ;
V_24 -> V_82 = 24 ;
V_24 -> V_85 = & V_86 ;
V_24 -> V_87 = 1 ;
V_24 -> V_88 = F_55 ;
V_24 -> V_127 = F_57 ;
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
V_27 [ V_33 ] = F_13 ( V_9 , V_143 ) ;
return V_33 ;
}
static void F_61 ( struct V_8 * V_9 ,
struct V_23 * V_24 )
{
unsigned int clock ;
clock = F_13 ( V_9 , V_144 ) & V_145 ;
F_16 ( V_9 , V_144 , clock | V_146 ) ;
F_16 ( V_9 , V_144 , clock ) ;
}
static void F_62 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
unsigned int * V_147 ,
unsigned int * V_148 )
{
unsigned int V_149 ;
V_149 = F_13 ( V_9 , V_144 ) & V_145 ;
* V_147 = V_149 ;
* V_148 = ( V_149 < F_63 ( V_150 ) ) ?
V_150 [ V_149 ] : 0 ;
}
static int F_64 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
unsigned int V_147 )
{
if ( V_147 > V_151 )
return - V_52 ;
F_16 ( V_9 , V_144 , V_147 ) ;
return 0 ;
}
static int F_65 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
struct V_25 * V_26 ,
unsigned int * V_27 )
{
int V_114 = 0 ;
switch ( V_27 [ 0 ] ) {
case V_152 :
F_61 ( V_9 , V_24 ) ;
break;
case V_121 :
V_114 = F_64 ( V_9 , V_24 , V_27 [ 1 ] ) ;
if ( V_114 < 0 )
V_114 = - V_52 ;
break;
case V_122 :
F_62 ( V_9 , V_24 , & V_27 [ 1 ] , & V_27 [ 2 ] ) ;
break;
default:
V_114 = - V_52 ;
break;
}
return V_114 < 0 ? V_114 : V_26 -> V_33 ;
}
static int F_66 ( struct V_8 * V_9 ,
struct V_23 * V_24 )
{
V_24 -> type = V_153 ;
V_24 -> V_79 = V_80 | V_154 ;
V_24 -> V_82 = 1 ;
V_24 -> V_87 = 0xFFFFFFFF ;
V_24 -> V_125 = F_60 ;
V_24 -> V_127 = F_65 ;
return 0 ;
}
void F_67 ( struct V_8 * V_9 , unsigned char V_22 )
{
F_10 ( V_9 , V_155 , V_22 ) ;
}
int F_68 ( struct V_8 * V_9 , unsigned int V_92 ,
unsigned long V_156 )
{
const struct V_5 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_9 -> V_14 ;
const struct V_4 * V_7 = F_4 ( V_11 ) ;
struct V_23 * V_24 ;
int V_157 ;
unsigned int V_33 ;
int V_114 ;
V_13 -> V_97 = - 1 ;
V_114 = F_69 ( V_9 , V_7 -> V_158 ) ;
if ( V_114 )
return V_114 ;
for ( V_33 = 0 ; V_33 < V_9 -> V_159 ; V_33 ++ ) {
V_24 = & V_9 -> V_98 [ V_33 ] ;
switch ( V_7 -> V_160 [ V_33 ] ) {
case V_161 :
V_114 = F_53 ( V_9 , V_24 ,
V_7 -> V_162 [ V_33 ] ) ;
if ( V_114 < 0 )
return V_114 ;
break;
case V_163 :
V_114 = F_59 ( V_9 , V_24 ,
V_7 -> V_162 [ V_33 ] ) ;
if ( V_114 < 0 )
return V_114 ;
break;
case V_164 :
if ( V_92 ) {
V_114 = F_37 ( V_9 , V_24 ,
V_165 ,
V_7 -> V_162 [ V_33 ]
) ;
if ( V_114 < 0 )
return V_114 ;
V_13 -> V_97 = V_33 ;
} else {
V_24 -> type = V_166 ;
}
break;
case V_167 :
V_114 = F_66 ( V_9 , V_24 ) ;
if ( V_114 < 0 )
return V_114 ;
break;
default:
V_24 -> type = V_166 ;
break;
}
}
V_157 = V_13 -> V_97 ;
if ( V_157 >= 0 && V_157 < V_9 -> V_159 )
V_9 -> V_168 = & V_9 -> V_98 [ V_157 ] ;
if ( V_92 ) {
if ( F_70 ( V_92 , F_40 , V_156 ,
V_9 -> V_169 , V_9 ) >= 0 ) {
V_9 -> V_92 = V_92 ;
} else {
F_71 ( V_9 -> V_170 ,
L_2 , V_92 ) ;
}
}
return 0 ;
}
void F_72 ( struct V_8 * V_9 )
{
const struct V_5 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 = V_9 -> V_14 ;
if ( ! V_11 || ! V_13 )
return;
if ( V_9 -> V_92 )
F_73 ( V_9 -> V_92 , V_9 ) ;
}
static int T_2 F_74 ( void )
{
return 0 ;
}
static void T_3 F_75 ( void )
{
}
