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
static struct V_10 * F_9 ( void )
{
struct V_10 * V_14 =
F_10 ( sizeof( struct V_10 ) , V_15 ) ;
if ( V_14 == NULL )
return NULL ;
return V_14 ;
}
static int F_11 ( struct V_16 * V_17 ,
struct V_11 * V_18 ,
struct V_19 * V_20 , unsigned int * V_21 )
{
struct V_22 * V_23 = V_17 -> V_13 ;
const unsigned V_24 = F_12 ( V_20 -> V_25 ) ;
const unsigned V_1 =
F_8 ( V_18 ) -> V_26 + F_6 ( V_24 ) ;
if ( V_21 [ 0 ] != V_27 )
return - V_28 ;
if ( V_21 [ 1 ] ) {
static const unsigned V_29 = 200 ;
static const unsigned V_30 = 0xfffff ;
unsigned V_31 =
( V_21 [ 1 ] +
( V_29 / 2 ) ) / V_29 ;
if ( V_31 > V_30 )
V_31 = V_30 ;
V_21 [ 1 ] = V_31 * V_29 ;
if ( V_31 != V_23 -> V_32 ) {
F_13 ( V_31 ,
V_23 -> V_33 -> V_34 +
V_35 ) ;
V_23 -> V_32 = V_31 ;
}
V_23 -> V_36 [ V_1 ] |=
1 << ( V_24 % V_4 ) ;
} else {
V_23 -> V_36 [ V_1 ] &=
~ ( 1 << ( V_24 % V_4 ) ) ;
}
F_13 ( V_23 -> V_36 [ V_1 ] ,
V_23 -> V_33 -> V_34 + F_5 ( V_1 ) ) ;
return 2 ;
}
static int F_14 ( struct V_16 * V_17 ,
struct V_11 * V_18 ,
struct V_19 * V_20 , unsigned int * V_21 )
{
struct V_22 * V_23 = V_17 -> V_13 ;
unsigned V_1 ;
if ( V_20 -> V_37 < 1 )
return - V_28 ;
V_1 = F_8 ( V_18 ) -> V_26 +
F_6 ( F_12 ( V_20 -> V_25 ) ) ;
switch ( V_21 [ 0 ] ) {
case V_27 :
return F_11 ( V_17 , V_18 , V_20 , V_21 ) ;
break;
case V_38 :
if ( V_18 -> type != V_39 )
return - V_28 ;
V_23 -> V_40 [ V_1 ] = V_41 ;
F_13 ( 0 , V_23 -> V_33 -> V_34 + F_2 ( V_1 ) ) ;
return 1 ;
break;
case V_42 :
if ( V_18 -> type != V_39 )
return - V_28 ;
V_23 -> V_40 [ V_1 ] = V_43 ;
F_13 ( 1 , V_23 -> V_33 -> V_34 + F_2 ( V_1 ) ) ;
return 1 ;
break;
case V_44 :
if ( V_18 -> type != V_39 )
return - V_28 ;
V_21 [ 1 ] = V_23 -> V_40 [ V_1 ] ;
return V_20 -> V_37 ;
break;
default:
break;
}
return - V_28 ;
}
static int F_15 ( struct V_16 * V_17 ,
struct V_11 * V_18 ,
struct V_19 * V_20 , unsigned int * V_21 )
{
const struct V_5 * V_6 = F_16 ( V_17 ) ;
struct V_22 * V_23 = V_17 -> V_13 ;
unsigned V_45 ;
const unsigned V_46 = 5 ;
unsigned V_47 = 0 ;
unsigned V_48 ;
V_45 = F_12 ( V_20 -> V_25 ) ;
for ( V_48 = 0 ; V_48 < V_46 ; ++ V_48 ) {
const unsigned V_49 =
F_6 ( V_45 ) + V_48 ;
const unsigned V_1 =
F_8 ( V_18 ) -> V_26 + V_49 ;
unsigned V_50 ;
unsigned V_51 , V_52 , V_53 ;
int V_54 ;
if ( V_1 >= F_7 ( V_6 ) )
break;
V_50 = V_49 * V_4 ;
V_51 = V_21 [ 0 ] ;
V_52 = V_21 [ 1 ] ;
V_54 = V_50 - V_45 ;
if ( V_54 >= 32 || V_54 <= - 32 )
break;
if ( V_54 > 0 ) {
V_51 >>= V_54 ;
V_52 >>= V_54 ;
} else {
V_51 <<= - V_54 ;
V_52 <<= - V_54 ;
}
V_51 &= 0xff ;
V_52 &= 0xff ;
if ( V_51 ) {
unsigned V_55 ;
V_23 -> V_56 [ V_1 ] &= ~ V_51 ;
V_23 -> V_56 [ V_1 ] |=
V_52 & V_51 ;
V_55 = V_23 -> V_56 [ V_1 ] ;
if ( V_6 -> V_57 )
V_55 = ~ V_55 ;
F_13 ( V_55 ,
V_23 -> V_33 -> V_34 +
F_1 ( V_1 ) ) ;
}
V_53 =
F_17 ( V_23 -> V_33 -> V_34 + F_1 ( V_1 ) ) ;
if ( V_18 -> type == V_58 && V_6 -> V_57 ) {
V_53 ^= 0xFF ;
}
if ( V_54 > 0 )
V_53 <<= V_54 ;
else
V_53 >>= - V_54 ;
V_47 |= V_53 ;
}
V_21 [ 1 ] = V_47 ;
return V_20 -> V_37 ;
}
static T_1 F_18 ( int V_59 , void * V_60 )
{
struct V_16 * V_17 = V_60 ;
struct V_22 * V_23 = V_17 -> V_13 ;
struct V_11 * V_18 = & V_17 -> V_61 [ 2 ] ;
unsigned int V_62 ;
V_62 = F_17 ( V_23 -> V_33 -> V_34 + V_63 ) ;
if ( ( V_62 & V_64 ) == 0 )
return V_65 ;
if ( ( V_62 & V_66 ) == 0 )
return V_65 ;
F_13 ( V_67 | V_68 ,
V_23 -> V_33 -> V_34 + V_69 ) ;
F_19 ( V_18 -> V_70 , 0 ) ;
V_18 -> V_70 -> V_71 |= V_72 ;
F_20 ( V_17 , V_18 ) ;
return V_73 ;
}
static int F_21 ( struct V_16 * V_17 ,
struct V_11 * V_18 ,
struct V_74 * V_75 )
{
int V_76 = 0 ;
V_76 |= F_22 ( & V_75 -> V_77 , V_78 ) ;
V_76 |= F_22 ( & V_75 -> V_79 , V_80 ) ;
V_76 |= F_22 ( & V_75 -> V_81 , V_82 ) ;
V_76 |= F_22 ( & V_75 -> V_83 , V_84 ) ;
V_76 |= F_22 ( & V_75 -> V_85 , V_84 ) ;
if ( V_76 )
return 1 ;
if ( V_76 )
return 2 ;
V_76 |= F_23 ( & V_75 -> V_86 , 0 ) ;
V_76 |= F_23 ( & V_75 -> V_87 , 0 ) ;
V_76 |= F_23 ( & V_75 -> V_88 , 0 ) ;
V_76 |= F_23 ( & V_75 -> V_89 , 1 ) ;
V_76 |= F_23 ( & V_75 -> V_90 , 0 ) ;
if ( V_76 )
return 3 ;
if ( V_76 )
return 4 ;
return 0 ;
}
static int F_24 ( struct V_16 * V_17 ,
struct V_11 * V_18 )
{
struct V_22 * V_23 = V_17 -> V_13 ;
F_13 ( V_67 | V_68 ,
V_23 -> V_33 -> V_34 + V_69 ) ;
F_13 ( V_91 | V_92 |
V_93 | V_94 ,
V_23 -> V_33 -> V_34 + V_95 ) ;
return 0 ;
}
static int F_25 ( struct V_16 * V_17 ,
struct V_11 * V_18 )
{
struct V_22 * V_23 = V_17 -> V_13 ;
F_13 ( 0x00 , V_23 -> V_33 -> V_34 + V_95 ) ;
return 0 ;
}
static int F_26 ( struct V_16 * V_17 ,
struct V_11 * V_18 ,
struct V_19 * V_20 , unsigned int * V_21 )
{
V_21 [ 1 ] = 0 ;
return V_20 -> V_37 ;
}
static int F_27 ( struct V_16 * V_17 ,
struct V_11 * V_18 ,
struct V_19 * V_20 ,
unsigned int * V_21 )
{
struct V_22 * V_23 = V_17 -> V_13 ;
if ( V_20 -> V_37 < 1 )
return - V_28 ;
if ( V_21 [ 0 ] != V_96 )
return - V_28 ;
F_13 ( V_21 [ 1 ] ,
V_23 -> V_33 -> V_34 +
F_3 ( 0 ) ) ;
F_13 ( V_21 [ 1 ] >> 8 ,
V_23 -> V_33 -> V_34 +
F_3 ( 0x10 ) ) ;
F_13 ( V_21 [ 1 ] >> 16 ,
V_23 -> V_33 -> V_34 +
F_3 ( 0x20 ) ) ;
F_13 ( V_21 [ 1 ] >> 24 ,
V_23 -> V_33 -> V_34 +
F_3 ( 0x30 ) ) ;
F_13 ( V_21 [ 2 ] ,
V_23 -> V_33 -> V_34 +
F_4 ( 0 ) ) ;
F_13 ( V_21 [ 2 ] >> 8 ,
V_23 -> V_33 -> V_34 +
F_4 ( 0x10 ) ) ;
F_13 ( V_21 [ 2 ] >> 16 ,
V_23 -> V_33 -> V_34 +
F_4 ( 0x20 ) ) ;
F_13 ( V_21 [ 2 ] >> 24 ,
V_23 -> V_33 -> V_34 +
F_4 ( 0x30 ) ) ;
return 2 ;
}
static int F_28 ( struct V_16 * V_17 ,
unsigned long V_97 )
{
struct V_98 * V_99 = F_29 ( V_17 ) ;
const struct V_5 * V_6 = NULL ;
struct V_22 * V_23 ;
struct V_11 * V_18 ;
unsigned V_100 ;
int V_101 ;
if ( V_97 < F_30 ( V_102 ) )
V_6 = & V_102 [ V_97 ] ;
if ( ! V_6 )
return - V_103 ;
V_17 -> V_104 = V_6 ;
V_17 -> V_105 = V_6 -> V_106 ;
V_101 = F_31 ( V_17 ) ;
if ( V_101 )
return V_101 ;
V_23 = F_10 ( sizeof( * V_23 ) , V_15 ) ;
if ( ! V_23 )
return - V_107 ;
V_17 -> V_13 = V_23 ;
V_23 -> V_33 = F_32 ( V_99 ) ;
if ( ! V_23 -> V_33 )
return - V_107 ;
V_101 = F_33 ( V_23 -> V_33 ) ;
if ( V_101 < 0 ) {
F_34 ( V_17 -> V_108 , L_1 ) ;
return V_101 ;
}
V_17 -> V_59 = F_35 ( V_23 -> V_33 ) ;
F_36 ( V_17 -> V_108 , L_2 , V_17 -> V_105 ,
F_17 ( V_23 -> V_33 -> V_34 + V_109 ) ) ;
V_101 = F_37 ( V_17 , 4 ) ;
if ( V_101 )
return V_101 ;
V_18 = & V_17 -> V_61 [ 0 ] ;
if ( V_6 -> V_8 ) {
V_18 -> type = V_110 ;
V_18 -> V_111 = V_112 ;
V_18 -> V_113 =
V_6 -> V_8 * V_4 ;
V_18 -> V_114 = & V_115 ;
V_18 -> V_116 = 1 ;
V_18 -> V_117 = F_14 ;
V_18 -> V_118 = F_15 ;
V_18 -> V_13 = F_9 () ;
if ( V_18 -> V_13 == NULL )
return - V_107 ;
F_8 ( V_18 ) -> V_26 = 0 ;
} else {
V_18 -> type = V_119 ;
}
V_18 = & V_17 -> V_61 [ 1 ] ;
if ( V_6 -> V_9 ) {
V_18 -> type = V_58 ;
V_18 -> V_111 = V_112 | V_120 ;
V_18 -> V_113 =
V_6 -> V_9 * V_4 ;
V_18 -> V_114 = & V_115 ;
V_18 -> V_116 = 1 ;
V_18 -> V_118 = F_15 ;
V_18 -> V_13 = F_9 () ;
if ( V_18 -> V_13 == NULL )
return - V_107 ;
F_8 ( V_18 ) -> V_26 = V_6 -> V_8 ;
} else {
V_18 -> type = V_119 ;
}
V_18 = & V_17 -> V_61 [ 2 ] ;
if ( V_6 -> V_7 ) {
V_18 -> type = V_39 ;
V_18 -> V_111 = V_112 | V_120 ;
V_18 -> V_113 =
V_6 -> V_7 * V_4 ;
V_18 -> V_114 = & V_115 ;
V_18 -> V_116 = 1 ;
V_18 -> V_117 = F_14 ;
V_18 -> V_118 = F_15 ;
V_18 -> V_13 = F_9 () ;
if ( V_18 -> V_13 == NULL )
return - V_107 ;
F_8 ( V_18 ) -> V_26 = 0 ;
for ( V_100 = 0 ; V_100 < V_6 -> V_7 ; ++ V_100 ) {
F_13 ( 0x1 ,
V_23 -> V_33 -> V_34 +
F_2 ( V_100 ) ) ;
}
} else {
V_18 -> type = V_119 ;
}
V_18 = & V_17 -> V_61 [ 3 ] ;
V_17 -> V_121 = V_18 ;
V_18 -> type = V_110 ;
V_18 -> V_111 = V_112 | V_122 ;
V_18 -> V_113 = 1 ;
V_18 -> V_114 = & V_123 ;
V_18 -> V_116 = 1 ;
V_18 -> V_124 = F_21 ;
V_18 -> V_125 = F_24 ;
V_18 -> V_126 = F_25 ;
V_18 -> V_118 = F_26 ;
V_18 -> V_117 = F_27 ;
for ( V_100 = 0 ; V_100 < F_7 ( V_6 ) ; ++ V_100 ) {
F_13 ( 0x00 ,
V_23 -> V_33 -> V_34 + F_5 ( V_100 ) ) ;
if ( V_6 -> V_57 )
F_13 ( 0x01 ,
V_23 -> V_33 -> V_34 + F_1 ( V_100 ) ) ;
else
F_13 ( 0x00 ,
V_23 -> V_33 -> V_34 + F_1 ( V_100 ) ) ;
}
F_13 ( V_67 | V_68 ,
V_23 -> V_33 -> V_34 + V_69 ) ;
F_13 ( 0x00 ,
V_23 -> V_33 -> V_34 + V_95 ) ;
F_13 ( 0x00000000 , V_23 -> V_33 -> V_34 + V_35 ) ;
V_101 = F_38 ( V_17 -> V_59 , F_18 , V_127 ,
L_3 , V_17 ) ;
if ( V_101 < 0 ) {
V_17 -> V_59 = 0 ;
F_34 ( V_17 -> V_108 , L_4 ) ;
}
return 0 ;
}
static void F_39 ( struct V_16 * V_17 )
{
struct V_22 * V_23 = V_17 -> V_13 ;
int V_100 ;
if ( V_23 && V_23 -> V_33 && V_23 -> V_33 -> V_34 ) {
F_13 ( 0x00 ,
V_23 -> V_33 -> V_34 +
V_95 ) ;
}
if ( V_17 -> V_59 )
F_40 ( V_17 -> V_59 , V_17 ) ;
for ( V_100 = 0 ; V_100 < V_17 -> V_128 ; ++ V_100 )
F_41 ( V_17 , V_100 ) ;
if ( V_23 ) {
if ( V_23 -> V_33 ) {
F_42 ( V_23 -> V_33 ) ;
F_43 ( V_23 -> V_33 ) ;
}
}
F_44 ( V_17 ) ;
}
static int F_45 ( struct V_98 * V_17 ,
const struct V_129 * V_130 )
{
return F_46 ( V_17 , & V_131 , V_130 -> V_132 ) ;
}
