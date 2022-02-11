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
static inline const struct V_3 * F_6 ( struct V_4 * V_5 )
{
return V_5 -> V_6 ;
}
static inline unsigned F_7 ( unsigned V_7 )
{
return V_7 / V_8 ;
}
static inline unsigned F_8 ( const struct V_3
* F_6 )
{
return F_6 -> V_9 + F_6 -> V_10 + F_6 -> V_11 ;
}
static inline struct V_12 * F_9 ( struct V_13
* V_14 )
{
return V_14 -> V_15 ;
}
static struct V_12 * F_10 ( void )
{
struct V_12 * V_16 =
F_11 ( sizeof( struct V_12 ) , V_17 ) ;
if ( V_16 == NULL )
return NULL ;
return V_16 ;
}
static int F_12 ( struct V_4 * V_5 ,
struct V_13 * V_18 ,
struct V_19 * V_20 , unsigned int * V_21 )
{
struct V_22 * V_23 = V_5 -> V_15 ;
const unsigned V_24 = F_13 ( V_20 -> V_25 ) ;
const unsigned V_1 =
F_9 ( V_18 ) -> V_26 + F_7 ( V_24 ) ;
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
F_14 ( V_31 ,
V_23 -> V_33 -> V_34 +
V_35 ) ;
V_23 -> V_32 = V_31 ;
}
V_23 -> V_36 [ V_1 ] |=
1 << ( V_24 % V_8 ) ;
} else {
V_23 -> V_36 [ V_1 ] &=
~ ( 1 << ( V_24 % V_8 ) ) ;
}
F_14 ( V_23 -> V_36 [ V_1 ] ,
V_23 -> V_33 -> V_34 + F_5 ( V_1 ) ) ;
return 2 ;
}
static int F_15 ( struct V_4 * V_5 ,
struct V_13 * V_18 ,
struct V_19 * V_20 , unsigned int * V_21 )
{
struct V_22 * V_23 = V_5 -> V_15 ;
unsigned V_1 ;
if ( V_20 -> V_37 < 1 )
return - V_28 ;
V_1 = F_9 ( V_18 ) -> V_26 +
F_7 ( F_13 ( V_20 -> V_25 ) ) ;
switch ( V_21 [ 0 ] ) {
case V_27 :
return F_12 ( V_5 , V_18 , V_20 , V_21 ) ;
break;
case V_38 :
if ( V_18 -> type != V_39 )
return - V_28 ;
V_23 -> V_40 [ V_1 ] = V_41 ;
F_14 ( 0 , V_23 -> V_33 -> V_34 + F_2 ( V_1 ) ) ;
return 1 ;
break;
case V_42 :
if ( V_18 -> type != V_39 )
return - V_28 ;
V_23 -> V_40 [ V_1 ] = V_43 ;
F_14 ( 1 , V_23 -> V_33 -> V_34 + F_2 ( V_1 ) ) ;
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
static int F_16 ( struct V_4 * V_5 ,
struct V_13 * V_18 ,
struct V_19 * V_20 , unsigned int * V_21 )
{
struct V_22 * V_23 = V_5 -> V_15 ;
unsigned V_45 ;
const unsigned V_46 = 5 ;
unsigned V_47 = 0 ;
unsigned V_48 ;
V_45 = F_13 ( V_20 -> V_25 ) ;
for ( V_48 = 0 ; V_48 < V_46 ; ++ V_48 ) {
const unsigned V_49 =
F_7 ( V_45 ) + V_48 ;
const unsigned V_1 =
F_9 ( V_18 ) -> V_26 + V_49 ;
unsigned V_50 ;
unsigned V_51 , V_52 , V_53 ;
int V_54 ;
if ( V_1 >= F_8 ( F_6 ( V_5 ) ) )
break;
V_50 = V_49 * V_8 ;
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
if ( F_6 ( V_5 ) -> V_57 )
V_55 = ~ V_55 ;
F_14 ( V_55 ,
V_23 -> V_33 -> V_34 +
F_1 ( V_1 ) ) ;
}
V_53 =
F_17 ( V_23 -> V_33 -> V_34 + F_1 ( V_1 ) ) ;
if ( V_18 -> type == V_58 && F_6 ( V_5 ) -> V_57 ) {
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
struct V_4 * V_5 = V_60 ;
struct V_22 * V_23 = V_5 -> V_15 ;
struct V_13 * V_18 = & V_5 -> V_61 [ 2 ] ;
unsigned int V_62 ;
V_62 = F_17 ( V_23 -> V_33 -> V_34 + V_63 ) ;
if ( ( V_62 & V_64 ) == 0 )
return V_65 ;
if ( ( V_62 & V_66 ) == 0 )
return V_65 ;
F_14 ( V_67 | V_68 ,
V_23 -> V_33 -> V_34 + V_69 ) ;
F_19 ( V_18 -> V_70 , 0 ) ;
V_18 -> V_70 -> V_71 |= V_72 ;
F_20 ( V_5 , V_18 ) ;
return V_73 ;
}
static int F_21 ( struct V_4 * V_5 ,
struct V_13 * V_18 ,
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
static int F_24 ( struct V_4 * V_5 ,
struct V_13 * V_18 )
{
struct V_22 * V_23 = V_5 -> V_15 ;
F_14 ( V_67 | V_68 ,
V_23 -> V_33 -> V_34 + V_69 ) ;
F_14 ( V_91 | V_92 |
V_93 | V_94 ,
V_23 -> V_33 -> V_34 + V_95 ) ;
return 0 ;
}
static int F_25 ( struct V_4 * V_5 ,
struct V_13 * V_18 )
{
struct V_22 * V_23 = V_5 -> V_15 ;
F_14 ( 0x00 , V_23 -> V_33 -> V_34 + V_95 ) ;
return 0 ;
}
static int F_26 ( struct V_4 * V_5 ,
struct V_13 * V_18 ,
struct V_19 * V_20 , unsigned int * V_21 )
{
V_21 [ 1 ] = 0 ;
return V_20 -> V_37 ;
}
static int F_27 ( struct V_4 * V_5 ,
struct V_13 * V_18 ,
struct V_19 * V_20 ,
unsigned int * V_21 )
{
struct V_22 * V_23 = V_5 -> V_15 ;
if ( V_20 -> V_37 < 1 )
return - V_28 ;
if ( V_21 [ 0 ] != V_96 )
return - V_28 ;
F_14 ( V_21 [ 1 ] ,
V_23 -> V_33 -> V_34 +
F_3 ( 0 ) ) ;
F_14 ( V_21 [ 1 ] >> 8 ,
V_23 -> V_33 -> V_34 +
F_3 ( 0x10 ) ) ;
F_14 ( V_21 [ 1 ] >> 16 ,
V_23 -> V_33 -> V_34 +
F_3 ( 0x20 ) ) ;
F_14 ( V_21 [ 1 ] >> 24 ,
V_23 -> V_33 -> V_34 +
F_3 ( 0x30 ) ) ;
F_14 ( V_21 [ 2 ] ,
V_23 -> V_33 -> V_34 +
F_4 ( 0 ) ) ;
F_14 ( V_21 [ 2 ] >> 8 ,
V_23 -> V_33 -> V_34 +
F_4 ( 0x10 ) ) ;
F_14 ( V_21 [ 2 ] >> 16 ,
V_23 -> V_33 -> V_34 +
F_4 ( 0x20 ) ) ;
F_14 ( V_21 [ 2 ] >> 24 ,
V_23 -> V_33 -> V_34 +
F_4 ( 0x30 ) ) ;
return 2 ;
}
static const struct V_3 *
F_28 ( struct V_97 * V_98 )
{
unsigned int V_99 = V_98 -> V_100 ;
unsigned int V_37 ;
for ( V_37 = 0 ; V_37 < F_29 ( V_101 ) ; V_37 ++ ) {
const struct V_3 * F_6 = & V_101 [ V_37 ] ;
if ( F_6 -> V_99 == V_99 )
return F_6 ;
}
return NULL ;
}
static int F_30 ( struct V_4 * V_5 ,
unsigned long V_102 )
{
struct V_97 * V_98 = F_31 ( V_5 ) ;
struct V_22 * V_23 ;
struct V_13 * V_18 ;
unsigned V_103 ;
int V_104 ;
V_23 = F_11 ( sizeof( * V_23 ) , V_17 ) ;
if ( ! V_23 )
return - V_105 ;
V_5 -> V_15 = V_23 ;
V_5 -> V_6 = F_28 ( V_98 ) ;
if ( ! V_5 -> V_6 )
return - V_106 ;
V_23 -> V_33 = F_32 ( V_98 ) ;
if ( ! V_23 -> V_33 )
return - V_105 ;
V_104 = F_33 ( V_23 -> V_33 ) ;
if ( V_104 < 0 ) {
F_34 ( V_5 -> V_107 , L_1 ) ;
return V_104 ;
}
V_5 -> V_108 = F_6 ( V_5 ) -> V_109 ;
V_5 -> V_59 = F_35 ( V_23 -> V_33 ) ;
F_36 ( V_5 -> V_107 , L_2 , V_5 -> V_108 ,
F_17 ( V_23 -> V_33 -> V_34 + V_110 ) ) ;
V_104 = F_37 ( V_5 , 4 ) ;
if ( V_104 )
return V_104 ;
V_18 = & V_5 -> V_61 [ 0 ] ;
if ( F_6 ( V_5 ) -> V_10 ) {
V_18 -> type = V_111 ;
V_18 -> V_112 = V_113 ;
V_18 -> V_114 =
F_6 ( V_5 ) -> V_10 * V_8 ;
V_18 -> V_115 = & V_116 ;
V_18 -> V_117 = 1 ;
V_18 -> V_118 = F_15 ;
V_18 -> V_119 = F_16 ;
V_18 -> V_15 = F_10 () ;
if ( V_18 -> V_15 == NULL )
return - V_105 ;
F_9 ( V_18 ) -> V_26 = 0 ;
} else {
V_18 -> type = V_120 ;
}
V_18 = & V_5 -> V_61 [ 1 ] ;
if ( F_6 ( V_5 ) -> V_11 ) {
V_18 -> type = V_58 ;
V_18 -> V_112 = V_113 | V_121 ;
V_18 -> V_114 =
F_6 ( V_5 ) -> V_11 * V_8 ;
V_18 -> V_115 = & V_116 ;
V_18 -> V_117 = 1 ;
V_18 -> V_119 = F_16 ;
V_18 -> V_15 = F_10 () ;
if ( V_18 -> V_15 == NULL )
return - V_105 ;
F_9 ( V_18 ) -> V_26 = F_6 ( V_5 ) -> V_10 ;
} else {
V_18 -> type = V_120 ;
}
V_18 = & V_5 -> V_61 [ 2 ] ;
if ( F_6 ( V_5 ) -> V_9 ) {
V_18 -> type = V_39 ;
V_18 -> V_112 = V_113 | V_121 ;
V_18 -> V_114 =
F_6 ( V_5 ) -> V_9 * V_8 ;
V_18 -> V_115 = & V_116 ;
V_18 -> V_117 = 1 ;
V_18 -> V_118 = F_15 ;
V_18 -> V_119 = F_16 ;
V_18 -> V_15 = F_10 () ;
if ( V_18 -> V_15 == NULL )
return - V_105 ;
F_9 ( V_18 ) -> V_26 = 0 ;
for ( V_103 = 0 ; V_103 < F_6 ( V_5 ) -> V_9 ; ++ V_103 ) {
F_14 ( 0x1 ,
V_23 -> V_33 -> V_34 +
F_2 ( V_103 ) ) ;
}
} else {
V_18 -> type = V_120 ;
}
V_18 = & V_5 -> V_61 [ 3 ] ;
V_5 -> V_122 = V_18 ;
V_18 -> type = V_111 ;
V_18 -> V_112 = V_113 | V_123 ;
V_18 -> V_114 = 1 ;
V_18 -> V_115 = & V_124 ;
V_18 -> V_117 = 1 ;
V_18 -> V_125 = F_21 ;
V_18 -> V_126 = F_24 ;
V_18 -> V_127 = F_25 ;
V_18 -> V_119 = F_26 ;
V_18 -> V_118 = F_27 ;
for ( V_103 = 0 ; V_103 < F_8 ( F_6 ( V_5 ) ) ; ++ V_103 ) {
F_14 ( 0x00 ,
V_23 -> V_33 -> V_34 + F_5 ( V_103 ) ) ;
if ( F_6 ( V_5 ) -> V_57 )
F_14 ( 0x01 ,
V_23 -> V_33 -> V_34 + F_1 ( V_103 ) ) ;
else
F_14 ( 0x00 ,
V_23 -> V_33 -> V_34 + F_1 ( V_103 ) ) ;
}
F_14 ( V_67 | V_68 ,
V_23 -> V_33 -> V_34 + V_69 ) ;
F_14 ( 0x00 ,
V_23 -> V_33 -> V_34 + V_95 ) ;
F_14 ( 0x00000000 , V_23 -> V_33 -> V_34 + V_35 ) ;
V_104 = F_38 ( V_5 -> V_59 , F_18 , V_128 ,
L_3 , V_5 ) ;
if ( V_104 < 0 ) {
V_5 -> V_59 = 0 ;
F_34 ( V_5 -> V_107 , L_4 ) ;
}
return 0 ;
}
static void F_39 ( struct V_4 * V_5 )
{
struct V_22 * V_23 = V_5 -> V_15 ;
if ( V_23 && V_23 -> V_33 && V_23 -> V_33 -> V_34 ) {
F_14 ( 0x00 ,
V_23 -> V_33 -> V_34 +
V_95 ) ;
}
if ( V_5 -> V_59 )
F_40 ( V_5 -> V_59 , V_5 ) ;
if ( V_23 ) {
struct V_13 * V_18 ;
unsigned V_103 ;
for ( V_103 = 0 ; V_103 < V_5 -> V_129 ; ++ V_103 ) {
V_18 = & V_5 -> V_61 [ V_103 ] ;
F_41 ( V_18 -> V_15 ) ;
V_18 -> V_15 = NULL ;
}
if ( V_23 -> V_33 ) {
F_42 ( V_23 -> V_33 ) ;
F_43 ( V_23 -> V_33 ) ;
}
}
}
static int F_44 ( struct V_97 * V_5 ,
const struct V_130 * V_131 )
{
return F_45 ( V_5 , & V_132 ) ;
}
static void F_46 ( struct V_97 * V_5 )
{
F_47 ( V_5 ) ;
}
