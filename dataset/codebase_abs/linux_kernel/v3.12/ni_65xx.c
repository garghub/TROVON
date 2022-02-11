static inline unsigned F_1 ( unsigned V_1 )
{
return 0x40 + V_1 * V_2 ;
}
static inline unsigned F_2 ( unsigned V_1 )
{
return 0x41 + V_1 * V_2 ;
}
static inline unsigned F_3 ( unsigned V_1 )
{
return 0x42 + V_1 * V_2 ;
}
static inline unsigned F_4 ( unsigned V_1 )
{
return 0x43 + V_1 * V_2 ;
}
static inline unsigned F_5 ( unsigned V_1 )
{
return 0x44 + V_1 * V_2 ;
}
static inline unsigned F_6 ( unsigned V_3 )
{
return V_3 / V_4 ;
}
static inline unsigned F_7 ( const struct V_5
* V_6 )
{
return V_6 -> V_7 + V_6 -> V_8 + V_6 -> V_9 ;
}
static inline struct V_10 * F_8 ( struct V_11
* V_12 )
{
return V_12 -> V_13 ;
}
static int F_9 ( struct V_14 * V_15 ,
struct V_11 * V_16 ,
struct V_17 * V_18 , unsigned int * V_19 )
{
struct V_20 * V_21 = V_15 -> V_13 ;
const unsigned V_22 = F_10 ( V_18 -> V_23 ) ;
const unsigned V_1 =
F_8 ( V_16 ) -> V_24 + F_6 ( V_22 ) ;
if ( V_19 [ 0 ] != V_25 )
return - V_26 ;
if ( V_19 [ 1 ] ) {
static const unsigned V_27 = 200 ;
static const unsigned V_28 = 0xfffff ;
unsigned V_29 =
( V_19 [ 1 ] +
( V_27 / 2 ) ) / V_27 ;
if ( V_29 > V_28 )
V_29 = V_28 ;
V_19 [ 1 ] = V_29 * V_27 ;
if ( V_29 != V_21 -> V_30 ) {
F_11 ( V_29 ,
V_21 -> V_31 -> V_32 +
V_33 ) ;
V_21 -> V_30 = V_29 ;
}
V_21 -> V_34 [ V_1 ] |=
1 << ( V_22 % V_4 ) ;
} else {
V_21 -> V_34 [ V_1 ] &=
~ ( 1 << ( V_22 % V_4 ) ) ;
}
F_11 ( V_21 -> V_34 [ V_1 ] ,
V_21 -> V_31 -> V_32 + F_5 ( V_1 ) ) ;
return 2 ;
}
static int F_12 ( struct V_14 * V_15 ,
struct V_11 * V_16 ,
struct V_17 * V_18 , unsigned int * V_19 )
{
struct V_20 * V_21 = V_15 -> V_13 ;
unsigned V_1 ;
if ( V_18 -> V_35 < 1 )
return - V_26 ;
V_1 = F_8 ( V_16 ) -> V_24 +
F_6 ( F_10 ( V_18 -> V_23 ) ) ;
switch ( V_19 [ 0 ] ) {
case V_25 :
return F_9 ( V_15 , V_16 , V_18 , V_19 ) ;
break;
case V_36 :
if ( V_16 -> type != V_37 )
return - V_26 ;
V_21 -> V_38 [ V_1 ] = V_39 ;
F_11 ( 0 , V_21 -> V_31 -> V_32 + F_2 ( V_1 ) ) ;
return 1 ;
break;
case V_40 :
if ( V_16 -> type != V_37 )
return - V_26 ;
V_21 -> V_38 [ V_1 ] = V_41 ;
F_11 ( 1 , V_21 -> V_31 -> V_32 + F_2 ( V_1 ) ) ;
return 1 ;
break;
case V_42 :
if ( V_16 -> type != V_37 )
return - V_26 ;
V_19 [ 1 ] = V_21 -> V_38 [ V_1 ] ;
return V_18 -> V_35 ;
break;
default:
break;
}
return - V_26 ;
}
static int F_13 ( struct V_14 * V_15 ,
struct V_11 * V_16 ,
struct V_17 * V_18 , unsigned int * V_19 )
{
const struct V_5 * V_6 = F_14 ( V_15 ) ;
struct V_20 * V_21 = V_15 -> V_13 ;
int V_43 ;
unsigned V_44 = 0 ;
int V_45 = F_6 ( V_16 -> V_46 - 1 ) ;
int V_47 ;
V_43 = F_10 ( V_18 -> V_23 ) ;
for ( V_47 = F_6 ( V_43 ) ;
V_47 <= V_45 ; V_47 ++ ) {
unsigned V_1 = F_8 ( V_16 ) -> V_24 + V_47 ;
int V_48 = V_47 * V_4 ;
unsigned V_49 , V_50 , V_51 ;
int V_52 = V_48 - V_43 ;
if ( V_52 >= 32 )
break;
V_49 = V_19 [ 0 ] ;
V_50 = V_19 [ 1 ] ;
if ( V_52 > 0 ) {
V_49 >>= V_52 ;
V_50 >>= V_52 ;
} else {
V_49 <<= - V_52 ;
V_50 <<= - V_52 ;
}
V_49 &= 0xff ;
V_50 &= 0xff ;
if ( V_49 ) {
unsigned V_53 ;
V_21 -> V_54 [ V_1 ] &= ~ V_49 ;
V_21 -> V_54 [ V_1 ] |=
V_50 & V_49 ;
V_53 = V_21 -> V_54 [ V_1 ] ;
if ( V_6 -> V_55 )
V_53 = ~ V_53 ;
F_11 ( V_53 ,
V_21 -> V_31 -> V_32 +
F_1 ( V_1 ) ) ;
}
V_51 =
F_15 ( V_21 -> V_31 -> V_32 + F_1 ( V_1 ) ) ;
if ( V_16 -> type == V_56 && V_6 -> V_55 ) {
V_51 ^= 0xFF ;
}
if ( V_52 > 0 )
V_51 <<= V_52 ;
else
V_51 >>= - V_52 ;
V_44 |= V_51 ;
}
V_19 [ 1 ] = V_44 ;
return V_18 -> V_35 ;
}
static T_1 F_16 ( int V_57 , void * V_58 )
{
struct V_14 * V_15 = V_58 ;
struct V_20 * V_21 = V_15 -> V_13 ;
struct V_11 * V_16 = & V_15 -> V_59 [ 2 ] ;
unsigned int V_60 ;
V_60 = F_15 ( V_21 -> V_31 -> V_32 + V_61 ) ;
if ( ( V_60 & V_62 ) == 0 )
return V_63 ;
if ( ( V_60 & V_64 ) == 0 )
return V_63 ;
F_11 ( V_65 | V_66 ,
V_21 -> V_31 -> V_32 + V_67 ) ;
F_17 ( V_16 -> V_68 , 0 ) ;
V_16 -> V_68 -> V_69 |= V_70 ;
F_18 ( V_15 , V_16 ) ;
return V_71 ;
}
static int F_19 ( struct V_14 * V_15 ,
struct V_11 * V_16 ,
struct V_72 * V_73 )
{
int V_74 = 0 ;
V_74 |= F_20 ( & V_73 -> V_75 , V_76 ) ;
V_74 |= F_20 ( & V_73 -> V_77 , V_78 ) ;
V_74 |= F_20 ( & V_73 -> V_79 , V_80 ) ;
V_74 |= F_20 ( & V_73 -> V_81 , V_82 ) ;
V_74 |= F_20 ( & V_73 -> V_83 , V_82 ) ;
if ( V_74 )
return 1 ;
if ( V_74 )
return 2 ;
V_74 |= F_21 ( & V_73 -> V_84 , 0 ) ;
V_74 |= F_21 ( & V_73 -> V_85 , 0 ) ;
V_74 |= F_21 ( & V_73 -> V_86 , 0 ) ;
V_74 |= F_21 ( & V_73 -> V_87 , 1 ) ;
V_74 |= F_21 ( & V_73 -> V_88 , 0 ) ;
if ( V_74 )
return 3 ;
if ( V_74 )
return 4 ;
return 0 ;
}
static int F_22 ( struct V_14 * V_15 ,
struct V_11 * V_16 )
{
struct V_20 * V_21 = V_15 -> V_13 ;
F_11 ( V_65 | V_66 ,
V_21 -> V_31 -> V_32 + V_67 ) ;
F_11 ( V_89 | V_90 |
V_91 | V_92 ,
V_21 -> V_31 -> V_32 + V_93 ) ;
return 0 ;
}
static int F_23 ( struct V_14 * V_15 ,
struct V_11 * V_16 )
{
struct V_20 * V_21 = V_15 -> V_13 ;
F_11 ( 0x00 , V_21 -> V_31 -> V_32 + V_93 ) ;
return 0 ;
}
static int F_24 ( struct V_14 * V_15 ,
struct V_11 * V_16 ,
struct V_17 * V_18 , unsigned int * V_19 )
{
V_19 [ 1 ] = 0 ;
return V_18 -> V_35 ;
}
static int F_25 ( struct V_14 * V_15 ,
struct V_11 * V_16 ,
struct V_17 * V_18 ,
unsigned int * V_19 )
{
struct V_20 * V_21 = V_15 -> V_13 ;
if ( V_18 -> V_35 < 1 )
return - V_26 ;
if ( V_19 [ 0 ] != V_94 )
return - V_26 ;
F_11 ( V_19 [ 1 ] ,
V_21 -> V_31 -> V_32 +
F_3 ( 0 ) ) ;
F_11 ( V_19 [ 1 ] >> 8 ,
V_21 -> V_31 -> V_32 +
F_3 ( 0x10 ) ) ;
F_11 ( V_19 [ 1 ] >> 16 ,
V_21 -> V_31 -> V_32 +
F_3 ( 0x20 ) ) ;
F_11 ( V_19 [ 1 ] >> 24 ,
V_21 -> V_31 -> V_32 +
F_3 ( 0x30 ) ) ;
F_11 ( V_19 [ 2 ] ,
V_21 -> V_31 -> V_32 +
F_4 ( 0 ) ) ;
F_11 ( V_19 [ 2 ] >> 8 ,
V_21 -> V_31 -> V_32 +
F_4 ( 0x10 ) ) ;
F_11 ( V_19 [ 2 ] >> 16 ,
V_21 -> V_31 -> V_32 +
F_4 ( 0x20 ) ) ;
F_11 ( V_19 [ 2 ] >> 24 ,
V_21 -> V_31 -> V_32 +
F_4 ( 0x30 ) ) ;
return 2 ;
}
static int F_26 ( struct V_14 * V_15 ,
unsigned long V_95 )
{
struct V_96 * V_97 = F_27 ( V_15 ) ;
const struct V_5 * V_6 = NULL ;
struct V_20 * V_21 ;
struct V_10 * V_98 ;
struct V_11 * V_16 ;
unsigned V_99 ;
int V_100 ;
if ( V_95 < F_28 ( V_101 ) )
V_6 = & V_101 [ V_95 ] ;
if ( ! V_6 )
return - V_102 ;
V_15 -> V_103 = V_6 ;
V_15 -> V_104 = V_6 -> V_105 ;
V_100 = F_29 ( V_15 ) ;
if ( V_100 )
return V_100 ;
V_21 = F_30 ( V_15 , sizeof( * V_21 ) ) ;
if ( ! V_21 )
return - V_106 ;
V_21 -> V_31 = F_31 ( V_97 ) ;
if ( ! V_21 -> V_31 )
return - V_106 ;
V_100 = F_32 ( V_21 -> V_31 ) ;
if ( V_100 < 0 ) {
F_33 ( V_15 -> V_107 , L_1 ) ;
return V_100 ;
}
V_15 -> V_57 = F_34 ( V_21 -> V_31 ) ;
F_35 ( V_15 -> V_107 , L_2 , V_15 -> V_104 ,
F_15 ( V_21 -> V_31 -> V_32 + V_108 ) ) ;
V_100 = F_36 ( V_15 , 4 ) ;
if ( V_100 )
return V_100 ;
V_16 = & V_15 -> V_59 [ 0 ] ;
if ( V_6 -> V_8 ) {
V_16 -> type = V_109 ;
V_16 -> V_110 = V_111 ;
V_16 -> V_46 =
V_6 -> V_8 * V_4 ;
V_16 -> V_112 = & V_113 ;
V_16 -> V_114 = 1 ;
V_16 -> V_115 = F_12 ;
V_16 -> V_116 = F_13 ;
V_98 = F_37 ( V_16 , sizeof( * V_98 ) ) ;
if ( ! V_98 )
return - V_106 ;
V_98 -> V_24 = 0 ;
} else {
V_16 -> type = V_117 ;
}
V_16 = & V_15 -> V_59 [ 1 ] ;
if ( V_6 -> V_9 ) {
V_16 -> type = V_56 ;
V_16 -> V_110 = V_111 | V_118 ;
V_16 -> V_46 =
V_6 -> V_9 * V_4 ;
V_16 -> V_112 = & V_113 ;
V_16 -> V_114 = 1 ;
V_16 -> V_116 = F_13 ;
V_98 = F_37 ( V_16 , sizeof( * V_98 ) ) ;
if ( ! V_98 )
return - V_106 ;
V_98 -> V_24 = V_6 -> V_8 ;
} else {
V_16 -> type = V_117 ;
}
V_16 = & V_15 -> V_59 [ 2 ] ;
if ( V_6 -> V_7 ) {
V_16 -> type = V_37 ;
V_16 -> V_110 = V_111 | V_118 ;
V_16 -> V_46 =
V_6 -> V_7 * V_4 ;
V_16 -> V_112 = & V_113 ;
V_16 -> V_114 = 1 ;
V_16 -> V_115 = F_12 ;
V_16 -> V_116 = F_13 ;
V_98 = F_37 ( V_16 , sizeof( * V_98 ) ) ;
if ( ! V_98 )
return - V_106 ;
V_98 -> V_24 = 0 ;
for ( V_99 = 0 ; V_99 < V_6 -> V_7 ; ++ V_99 ) {
F_11 ( 0x1 ,
V_21 -> V_31 -> V_32 +
F_2 ( V_99 ) ) ;
}
} else {
V_16 -> type = V_117 ;
}
V_16 = & V_15 -> V_59 [ 3 ] ;
V_15 -> V_119 = V_16 ;
V_16 -> type = V_109 ;
V_16 -> V_110 = V_111 | V_120 ;
V_16 -> V_46 = 1 ;
V_16 -> V_112 = & V_121 ;
V_16 -> V_114 = 1 ;
V_16 -> V_122 = F_19 ;
V_16 -> V_123 = F_22 ;
V_16 -> V_124 = F_23 ;
V_16 -> V_116 = F_24 ;
V_16 -> V_115 = F_25 ;
for ( V_99 = 0 ; V_99 < F_7 ( V_6 ) ; ++ V_99 ) {
F_11 ( 0x00 ,
V_21 -> V_31 -> V_32 + F_5 ( V_99 ) ) ;
if ( V_6 -> V_55 )
F_11 ( 0x01 ,
V_21 -> V_31 -> V_32 + F_1 ( V_99 ) ) ;
else
F_11 ( 0x00 ,
V_21 -> V_31 -> V_32 + F_1 ( V_99 ) ) ;
}
F_11 ( V_65 | V_66 ,
V_21 -> V_31 -> V_32 + V_67 ) ;
F_11 ( 0x00 ,
V_21 -> V_31 -> V_32 + V_93 ) ;
F_11 ( 0x00000000 , V_21 -> V_31 -> V_32 + V_33 ) ;
V_100 = F_38 ( V_15 -> V_57 , F_16 , V_125 ,
L_3 , V_15 ) ;
if ( V_100 < 0 ) {
V_15 -> V_57 = 0 ;
F_33 ( V_15 -> V_107 , L_4 ) ;
}
return 0 ;
}
static void F_39 ( struct V_14 * V_15 )
{
struct V_20 * V_21 = V_15 -> V_13 ;
if ( V_21 && V_21 -> V_31 && V_21 -> V_31 -> V_32 ) {
F_11 ( 0x00 ,
V_21 -> V_31 -> V_32 +
V_93 ) ;
}
if ( V_15 -> V_57 )
F_40 ( V_15 -> V_57 , V_15 ) ;
if ( V_21 ) {
if ( V_21 -> V_31 ) {
F_41 ( V_21 -> V_31 ) ;
F_42 ( V_21 -> V_31 ) ;
}
}
F_43 ( V_15 ) ;
}
static int F_44 ( struct V_96 * V_15 ,
const struct V_126 * V_127 )
{
return F_45 ( V_15 , & V_128 , V_127 -> V_129 ) ;
}
