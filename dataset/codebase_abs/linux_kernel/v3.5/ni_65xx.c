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
static inline struct V_12 * F_9 ( struct V_4 * V_5 )
{
return V_5 -> F_9 ;
}
static inline struct V_13 * F_10 ( struct V_14
* V_15 )
{
return V_15 -> F_9 ;
}
static struct V_13 * F_11 ( void )
{
struct V_13 * V_16 =
F_12 ( sizeof( struct V_13 ) , V_17 ) ;
if ( V_16 == NULL )
return NULL ;
return V_16 ;
}
static int F_13 ( struct V_4 * V_5 ,
struct V_14 * V_18 ,
struct V_19 * V_20 , unsigned int * V_21 )
{
const unsigned V_22 = F_14 ( V_20 -> V_23 ) ;
const unsigned V_1 =
F_10 ( V_18 ) -> V_24 + F_7 ( V_22 ) ;
if ( V_21 [ 0 ] != V_25 )
return - V_26 ;
if ( V_21 [ 1 ] ) {
static const unsigned V_27 = 200 ;
static const unsigned V_28 = 0xfffff ;
unsigned V_29 =
( V_21 [ 1 ] +
( V_27 / 2 ) ) / V_27 ;
if ( V_29 > V_28 )
V_29 = V_28 ;
V_21 [ 1 ] = V_29 * V_27 ;
if ( V_29 != F_9 ( V_5 ) -> V_30 ) {
F_15 ( V_29 ,
F_9 ( V_5 ) -> V_31 -> V_32 +
V_33 ) ;
F_9 ( V_5 ) -> V_30 = V_29 ;
}
F_9 ( V_5 ) -> V_34 [ V_1 ] |=
1 << ( V_22 % V_8 ) ;
} else {
F_9 ( V_5 ) -> V_34 [ V_1 ] &=
~ ( 1 << ( V_22 % V_8 ) ) ;
}
F_15 ( F_9 ( V_5 ) -> V_34 [ V_1 ] ,
F_9 ( V_5 ) -> V_31 -> V_32 + F_5 ( V_1 ) ) ;
return 2 ;
}
static int F_16 ( struct V_4 * V_5 ,
struct V_14 * V_18 ,
struct V_19 * V_20 , unsigned int * V_21 )
{
unsigned V_1 ;
if ( V_20 -> V_35 < 1 )
return - V_26 ;
V_1 = F_10 ( V_18 ) -> V_24 +
F_7 ( F_14 ( V_20 -> V_23 ) ) ;
switch ( V_21 [ 0 ] ) {
case V_25 :
return F_13 ( V_5 , V_18 , V_20 , V_21 ) ;
break;
case V_36 :
if ( V_18 -> type != V_37 )
return - V_26 ;
F_9 ( V_5 ) -> V_38 [ V_1 ] = V_39 ;
F_15 ( 0 , F_9 ( V_5 ) -> V_31 -> V_32 + F_2 ( V_1 ) ) ;
return 1 ;
break;
case V_40 :
if ( V_18 -> type != V_37 )
return - V_26 ;
F_9 ( V_5 ) -> V_38 [ V_1 ] = V_41 ;
F_15 ( 1 , F_9 ( V_5 ) -> V_31 -> V_32 + F_2 ( V_1 ) ) ;
return 1 ;
break;
case V_42 :
if ( V_18 -> type != V_37 )
return - V_26 ;
V_21 [ 1 ] = F_9 ( V_5 ) -> V_38 [ V_1 ] ;
return V_20 -> V_35 ;
break;
default:
break;
}
return - V_26 ;
}
static int F_17 ( struct V_4 * V_5 ,
struct V_14 * V_18 ,
struct V_19 * V_20 , unsigned int * V_21 )
{
unsigned V_43 ;
const unsigned V_44 = 5 ;
unsigned V_45 = 0 ;
unsigned V_46 ;
if ( V_20 -> V_35 != 2 )
return - V_26 ;
V_43 = F_14 ( V_20 -> V_23 ) ;
for ( V_46 = 0 ; V_46 < V_44 ; ++ V_46 ) {
const unsigned V_47 =
F_7 ( V_43 ) + V_46 ;
const unsigned V_1 =
F_10 ( V_18 ) -> V_24 + V_47 ;
unsigned V_48 ;
unsigned V_49 , V_50 , V_51 ;
int V_52 ;
if ( V_1 >= F_8 ( F_6 ( V_5 ) ) )
break;
V_48 = V_47 * V_8 ;
V_49 = V_21 [ 0 ] ;
V_50 = V_21 [ 1 ] ;
V_52 = V_48 - V_43 ;
if ( V_52 >= 32 || V_52 <= - 32 )
break;
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
F_9 ( V_5 ) -> V_54 [ V_1 ] &= ~ V_49 ;
F_9 ( V_5 ) -> V_54 [ V_1 ] |=
V_50 & V_49 ;
V_53 = F_9 ( V_5 ) -> V_54 [ V_1 ] ;
if ( F_6 ( V_5 ) -> V_55 )
V_53 = ~ V_53 ;
F_15 ( V_53 ,
F_9 ( V_5 ) -> V_31 -> V_32 +
F_1 ( V_1 ) ) ;
}
V_51 =
F_18 ( F_9 ( V_5 ) -> V_31 -> V_32 + F_1 ( V_1 ) ) ;
if ( V_18 -> type == V_56 && F_6 ( V_5 ) -> V_55 ) {
V_51 ^= 0xFF ;
}
if ( V_52 > 0 )
V_51 <<= V_52 ;
else
V_51 >>= - V_52 ;
V_45 |= V_51 ;
}
V_21 [ 1 ] = V_45 ;
return V_20 -> V_35 ;
}
static T_1 F_19 ( int V_57 , void * V_58 )
{
struct V_4 * V_5 = V_58 ;
struct V_14 * V_18 = V_5 -> V_59 + 2 ;
unsigned int V_60 ;
V_60 = F_18 ( F_9 ( V_5 ) -> V_31 -> V_32 + V_61 ) ;
if ( ( V_60 & V_62 ) == 0 )
return V_63 ;
if ( ( V_60 & V_64 ) == 0 )
return V_63 ;
F_15 ( V_65 | V_66 ,
F_9 ( V_5 ) -> V_31 -> V_32 + V_67 ) ;
F_20 ( V_18 -> V_68 , 0 ) ;
V_18 -> V_68 -> V_69 |= V_70 ;
F_21 ( V_5 , V_18 ) ;
return V_71 ;
}
static int F_22 ( struct V_4 * V_5 ,
struct V_14 * V_18 ,
struct V_72 * V_73 )
{
int V_74 = 0 ;
int V_75 ;
V_75 = V_73 -> V_76 ;
V_73 -> V_76 &= V_77 ;
if ( ! V_73 -> V_76 || V_75 != V_73 -> V_76 )
V_74 ++ ;
V_75 = V_73 -> V_78 ;
V_73 -> V_78 &= V_79 ;
if ( ! V_73 -> V_78 || V_75 != V_73 -> V_78 )
V_74 ++ ;
V_75 = V_73 -> V_80 ;
V_73 -> V_80 &= V_81 ;
if ( ! V_73 -> V_80 || V_75 != V_73 -> V_80 )
V_74 ++ ;
V_75 = V_73 -> V_82 ;
V_73 -> V_82 &= V_83 ;
if ( ! V_73 -> V_82 || V_75 != V_73 -> V_82 )
V_74 ++ ;
V_75 = V_73 -> V_84 ;
V_73 -> V_84 &= V_83 ;
if ( ! V_73 -> V_84 || V_75 != V_73 -> V_84 )
V_74 ++ ;
if ( V_74 )
return 1 ;
if ( V_74 )
return 2 ;
if ( V_73 -> V_85 != 0 ) {
V_73 -> V_85 = 0 ;
V_74 ++ ;
}
if ( V_73 -> V_86 != 0 ) {
V_73 -> V_86 = 0 ;
V_74 ++ ;
}
if ( V_73 -> V_87 != 0 ) {
V_73 -> V_87 = 0 ;
V_74 ++ ;
}
if ( V_73 -> V_88 != 1 ) {
V_73 -> V_88 = 1 ;
V_74 ++ ;
}
if ( V_73 -> V_89 != 0 ) {
V_73 -> V_89 = 0 ;
V_74 ++ ;
}
if ( V_74 )
return 3 ;
if ( V_74 )
return 4 ;
return 0 ;
}
static int F_23 ( struct V_4 * V_5 ,
struct V_14 * V_18 )
{
F_15 ( V_65 | V_66 ,
F_9 ( V_5 ) -> V_31 -> V_32 + V_67 ) ;
F_15 ( V_90 | V_91 |
V_92 | V_93 ,
F_9 ( V_5 ) -> V_31 -> V_32 + V_94 ) ;
return 0 ;
}
static int F_24 ( struct V_4 * V_5 ,
struct V_14 * V_18 )
{
F_15 ( 0x00 ,
F_9 ( V_5 ) -> V_31 -> V_32 + V_94 ) ;
return 0 ;
}
static int F_25 ( struct V_4 * V_5 ,
struct V_14 * V_18 ,
struct V_19 * V_20 , unsigned int * V_21 )
{
if ( V_20 -> V_35 < 1 )
return - V_26 ;
V_21 [ 1 ] = 0 ;
return 2 ;
}
static int F_26 ( struct V_4 * V_5 ,
struct V_14 * V_18 ,
struct V_19 * V_20 ,
unsigned int * V_21 )
{
if ( V_20 -> V_35 < 1 )
return - V_26 ;
if ( V_21 [ 0 ] != V_95 )
return - V_26 ;
F_15 ( V_21 [ 1 ] ,
F_9 ( V_5 ) -> V_31 -> V_32 +
F_3 ( 0 ) ) ;
F_15 ( V_21 [ 1 ] >> 8 ,
F_9 ( V_5 ) -> V_31 -> V_32 +
F_3 ( 0x10 ) ) ;
F_15 ( V_21 [ 1 ] >> 16 ,
F_9 ( V_5 ) -> V_31 -> V_32 +
F_3 ( 0x20 ) ) ;
F_15 ( V_21 [ 1 ] >> 24 ,
F_9 ( V_5 ) -> V_31 -> V_32 +
F_3 ( 0x30 ) ) ;
F_15 ( V_21 [ 2 ] ,
F_9 ( V_5 ) -> V_31 -> V_32 +
F_4 ( 0 ) ) ;
F_15 ( V_21 [ 2 ] >> 8 ,
F_9 ( V_5 ) -> V_31 -> V_32 +
F_4 ( 0x10 ) ) ;
F_15 ( V_21 [ 2 ] >> 16 ,
F_9 ( V_5 ) -> V_31 -> V_32 +
F_4 ( 0x20 ) ) ;
F_15 ( V_21 [ 2 ] >> 24 ,
F_9 ( V_5 ) -> V_31 -> V_32 +
F_4 ( 0x30 ) ) ;
return 2 ;
}
static int F_27 ( struct V_4 * V_5 ,
struct V_96 * V_97 )
{
struct V_14 * V_18 ;
unsigned V_98 ;
int V_99 ;
F_28 ( V_100 L_1 , V_5 -> V_101 ) ;
V_99 = F_29 ( V_5 , sizeof( struct V_12 ) ) ;
if ( V_99 < 0 )
return V_99 ;
V_99 = F_30 ( V_5 , V_97 -> V_102 [ 0 ] , V_97 -> V_102 [ 1 ] ) ;
if ( V_99 < 0 )
return V_99 ;
V_99 = F_31 ( F_9 ( V_5 ) -> V_31 ) ;
if ( V_99 < 0 ) {
F_28 ( V_103 L_2 ) ;
return V_99 ;
}
V_5 -> V_104 = F_6 ( V_5 ) -> V_105 ;
V_5 -> V_57 = F_32 ( F_9 ( V_5 ) -> V_31 ) ;
F_28 ( V_100 L_3 , V_5 -> V_104 ) ;
F_28 ( V_100 L_4 ,
F_18 ( F_9 ( V_5 ) -> V_31 -> V_32 + V_106 ) ) ;
V_99 = F_33 ( V_5 , 4 ) ;
if ( V_99 < 0 )
return V_99 ;
V_18 = V_5 -> V_59 + 0 ;
if ( F_6 ( V_5 ) -> V_10 ) {
V_18 -> type = V_107 ;
V_18 -> V_108 = V_109 ;
V_18 -> V_110 =
F_6 ( V_5 ) -> V_10 * V_8 ;
V_18 -> V_111 = & V_112 ;
V_18 -> V_113 = 1 ;
V_18 -> V_114 = F_16 ;
V_18 -> V_115 = F_17 ;
V_18 -> F_9 = F_11 () ;
if ( V_18 -> F_9 == NULL )
return - V_116 ;
F_10 ( V_18 ) -> V_24 = 0 ;
} else {
V_18 -> type = V_117 ;
}
V_18 = V_5 -> V_59 + 1 ;
if ( F_6 ( V_5 ) -> V_11 ) {
V_18 -> type = V_56 ;
V_18 -> V_108 = V_109 | V_118 ;
V_18 -> V_110 =
F_6 ( V_5 ) -> V_11 * V_8 ;
V_18 -> V_111 = & V_112 ;
V_18 -> V_113 = 1 ;
V_18 -> V_115 = F_17 ;
V_18 -> F_9 = F_11 () ;
if ( V_18 -> F_9 == NULL )
return - V_116 ;
F_10 ( V_18 ) -> V_24 = F_6 ( V_5 ) -> V_10 ;
} else {
V_18 -> type = V_117 ;
}
V_18 = V_5 -> V_59 + 2 ;
if ( F_6 ( V_5 ) -> V_9 ) {
V_18 -> type = V_37 ;
V_18 -> V_108 = V_109 | V_118 ;
V_18 -> V_110 =
F_6 ( V_5 ) -> V_9 * V_8 ;
V_18 -> V_111 = & V_112 ;
V_18 -> V_113 = 1 ;
V_18 -> V_114 = F_16 ;
V_18 -> V_115 = F_17 ;
V_18 -> F_9 = F_11 () ;
if ( V_18 -> F_9 == NULL )
return - V_116 ;
F_10 ( V_18 ) -> V_24 = 0 ;
for ( V_98 = 0 ; V_98 < F_6 ( V_5 ) -> V_9 ; ++ V_98 ) {
F_15 ( 0x1 ,
F_9 ( V_5 ) -> V_31 -> V_32 +
F_2 ( V_98 ) ) ;
}
} else {
V_18 -> type = V_117 ;
}
V_18 = V_5 -> V_59 + 3 ;
V_5 -> V_119 = V_18 ;
V_18 -> type = V_107 ;
V_18 -> V_108 = V_109 | V_120 ;
V_18 -> V_110 = 1 ;
V_18 -> V_111 = & V_121 ;
V_18 -> V_113 = 1 ;
V_18 -> V_122 = F_22 ;
V_18 -> V_123 = F_23 ;
V_18 -> V_124 = F_24 ;
V_18 -> V_115 = F_25 ;
V_18 -> V_114 = F_26 ;
for ( V_98 = 0 ; V_98 < F_8 ( F_6 ( V_5 ) ) ; ++ V_98 ) {
F_15 ( 0x00 ,
F_9 ( V_5 ) -> V_31 -> V_32 + F_5 ( V_98 ) ) ;
if ( F_6 ( V_5 ) -> V_55 )
F_15 ( 0x01 ,
F_9 ( V_5 ) -> V_31 -> V_32 + F_1 ( V_98 ) ) ;
else
F_15 ( 0x00 ,
F_9 ( V_5 ) -> V_31 -> V_32 + F_1 ( V_98 ) ) ;
}
F_15 ( V_65 | V_66 ,
F_9 ( V_5 ) -> V_31 -> V_32 + V_67 ) ;
F_15 ( 0x00 ,
F_9 ( V_5 ) -> V_31 -> V_32 + V_94 ) ;
F_15 ( 0x00000000 , F_9 ( V_5 ) -> V_31 -> V_32 + V_33 ) ;
V_99 = F_34 ( V_5 -> V_57 , F_19 , V_125 ,
L_5 , V_5 ) ;
if ( V_99 < 0 ) {
V_5 -> V_57 = 0 ;
F_28 ( V_103 L_6 ) ;
}
F_28 ( L_7 ) ;
return 0 ;
}
static void F_35 ( struct V_4 * V_5 )
{
if ( F_9 ( V_5 ) && F_9 ( V_5 ) -> V_31
&& F_9 ( V_5 ) -> V_31 -> V_32 ) {
F_15 ( 0x00 ,
F_9 ( V_5 ) -> V_31 -> V_32 +
V_94 ) ;
}
if ( V_5 -> V_57 )
F_36 ( V_5 -> V_57 , V_5 ) ;
if ( F_9 ( V_5 ) ) {
unsigned V_98 ;
for ( V_98 = 0 ; V_98 < V_5 -> V_126 ; ++ V_98 ) {
F_37 ( V_5 -> V_59 [ V_98 ] . F_9 ) ;
V_5 -> V_59 [ V_98 ] . F_9 = NULL ;
}
if ( F_9 ( V_5 ) -> V_31 )
F_38 ( F_9 ( V_5 ) -> V_31 ) ;
}
}
static int F_30 ( struct V_4 * V_5 , int V_127 , int V_128 )
{
struct V_129 * V_31 ;
int V_98 ;
for ( V_31 = V_130 ; V_31 ; V_31 = V_31 -> V_131 ) {
if ( V_31 -> V_132 )
continue;
if ( V_127 || V_128 ) {
if ( V_127 != V_31 -> V_133 -> V_127 -> V_134 ||
V_128 != F_39 ( V_31 -> V_133 -> V_135 ) )
continue;
}
for ( V_98 = 0 ; V_98 < V_136 ; V_98 ++ ) {
if ( F_40 ( V_31 ) == V_137 [ V_98 ] . V_138 ) {
V_5 -> V_6 = V_137 + V_98 ;
F_9 ( V_5 ) -> V_31 = V_31 ;
return 0 ;
}
}
}
F_28 ( V_103 L_8 ) ;
F_41 () ;
return - V_139 ;
}
static int T_2 F_42 ( struct V_140 * V_5 ,
const struct V_141 * V_142 )
{
return F_43 ( V_5 , & V_143 ) ;
}
static void T_3 F_44 ( struct V_140 * V_5 )
{
F_45 ( V_5 ) ;
}
static int T_4 F_46 ( void )
{
int V_144 ;
V_144 = F_47 ( & V_143 ) ;
if ( V_144 < 0 )
return V_144 ;
V_145 . V_105 = ( char * ) V_143 . V_146 ;
return F_48 ( & V_145 ) ;
}
static void T_5 F_49 ( void )
{
F_50 ( & V_145 ) ;
F_51 ( & V_143 ) ;
}
