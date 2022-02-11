static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_4 -> type = V_8 ;
V_4 -> V_9 = V_6 -> V_10 . V_11 ;
V_4 -> V_12 . integer . V_13 = V_6 -> V_10 . V_14 ;
V_4 -> V_12 . integer . V_15 = V_6 -> V_10 . V_16 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_17 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_18 ;
F_3 ( & V_6 -> V_19 ) ;
for ( V_18 = 0 ; V_18 < V_6 -> V_10 . V_11 ; ++ V_18 )
V_12 -> V_12 . integer . V_12 [ V_18 ] = V_6 -> V_20 [ V_18 ] ;
F_4 ( & V_6 -> V_19 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_17 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_18 ;
int V_21 ;
V_21 = 0 ;
F_3 ( & V_6 -> V_19 ) ;
for ( V_18 = 0 ; V_18 < V_6 -> V_10 . V_11 ; ++ V_18 )
if ( V_12 -> V_12 . integer . V_12 [ V_18 ] != V_6 -> V_20 [ V_18 ] ) {
V_6 -> V_20 [ V_18 ] = V_12 -> V_12 . integer . V_12 [ V_18 ] ;
V_21 = 1 ;
}
if ( V_21 )
V_6 -> V_10 . V_22 ( V_6 ) ;
F_4 ( & V_6 -> V_19 ) ;
return V_21 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_17 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_3 ( & V_6 -> V_19 ) ;
V_12 -> V_12 . integer . V_12 [ 0 ] = ! V_6 -> V_23 ;
F_4 ( & V_6 -> V_19 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_17 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_21 ;
F_3 ( & V_6 -> V_19 ) ;
V_21 = ! V_12 -> V_12 . integer . V_12 [ 0 ] != V_6 -> V_23 ;
if ( V_21 ) {
V_6 -> V_23 = ! V_12 -> V_12 . integer . V_12 [ 0 ] ;
V_6 -> V_10 . V_24 ( V_6 ) ;
}
F_4 ( & V_6 -> V_19 ) ;
return V_21 ;
}
static unsigned int F_8 ( struct V_5 * V_6 )
{
if ( V_6 -> V_10 . V_25 < 8 )
return 2 ;
else if ( V_6 -> V_10 . V_26 )
return 5 ;
else
return 3 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
static const char * const V_27 [ 5 ] = {
L_1 ,
L_2 ,
L_3 ,
L_4 ,
L_5 ,
} ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_9 = F_8 ( V_6 ) ;
return F_10 ( V_4 , 1 , V_9 , V_27 ) ;
}
static int F_11 ( struct V_1 * V_2 , struct V_17 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_3 ( & V_6 -> V_19 ) ;
V_12 -> V_12 . V_28 . V_29 [ 0 ] = V_6 -> V_30 ;
F_4 ( & V_6 -> V_19 ) ;
return 0 ;
}
void F_12 ( struct V_5 * V_6 )
{
static const unsigned int V_31 [ 5 ] = {
( 0 << V_32 ) |
( 1 << V_33 ) |
( 2 << V_34 ) |
( 3 << V_35 ) ,
( 0 << V_32 ) |
( 0 << V_33 ) |
( 2 << V_34 ) |
( 3 << V_35 ) ,
( 0 << V_32 ) |
( 0 << V_33 ) |
( 2 << V_34 ) |
( 0 << V_35 ) ,
( 0 << V_32 ) |
( 0 << V_33 ) |
( 0 << V_34 ) |
( 3 << V_35 ) ,
( 0 << V_32 ) |
( 0 << V_33 ) |
( 0 << V_34 ) |
( 0 << V_35 ) ,
} ;
T_1 V_36 ;
unsigned int V_37 ;
V_36 = F_13 ( V_6 , V_38 ) &
V_39 ;
if ( V_36 == V_40 )
V_37 = V_31 [ V_6 -> V_30 ] ;
else if ( V_36 == V_41 )
V_37 = ( 0 << V_32 ) |
( 3 << V_33 ) |
( 2 << V_34 ) |
( 1 << V_35 ) ;
else
V_37 = ( 0 << V_32 ) |
( 1 << V_33 ) |
( 2 << V_34 ) |
( 3 << V_35 ) ;
if ( V_6 -> V_10 . V_42 )
V_37 = V_6 -> V_10 . V_42 ( V_6 , V_37 ) ;
F_14 ( V_6 , V_43 , V_37 ,
V_44 |
V_45 |
V_46 |
V_47 ) ;
if ( V_6 -> V_10 . V_26 )
V_6 -> V_10 . V_26 ( V_6 , V_6 -> V_30 > 2 ) ;
}
static int F_15 ( struct V_1 * V_2 , struct V_17 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_9 = F_8 ( V_6 ) ;
int V_21 ;
if ( V_12 -> V_12 . V_28 . V_29 [ 0 ] >= V_9 )
return - V_48 ;
F_3 ( & V_6 -> V_19 ) ;
V_21 = V_12 -> V_12 . V_28 . V_29 [ 0 ] != V_6 -> V_30 ;
if ( V_21 ) {
V_6 -> V_30 = V_12 -> V_12 . V_28 . V_29 [ 0 ] ;
F_12 ( V_6 ) ;
}
F_4 ( & V_6 -> V_19 ) ;
return V_21 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_17 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_3 ( & V_6 -> V_19 ) ;
V_12 -> V_12 . integer . V_12 [ 0 ] = V_6 -> V_49 ;
F_4 ( & V_6 -> V_19 ) ;
return 0 ;
}
static unsigned int F_17 ( unsigned int V_50 )
{
switch ( V_50 ) {
case V_51 :
return V_52 << V_53 ;
case V_54 :
return V_55 << V_53 ;
default:
return V_56 << V_53 ;
case V_57 :
return 0xb << V_53 ;
case V_58 :
return V_59 << V_53 ;
case V_60 :
return V_61 << V_53 ;
case V_62 :
return V_63 << V_53 ;
case V_64 :
return V_65 << V_53 ;
}
}
void F_18 ( struct V_5 * V_6 )
{
T_2 V_66 , V_67 ;
T_3 V_68 , V_69 ;
unsigned int V_50 ;
V_66 = F_19 ( V_6 , V_70 ) ;
V_68 = F_20 ( V_6 , V_43 ) ;
if ( V_6 -> V_71 & ( 1 << V_72 ) ) {
V_67 = V_66 | V_73 ;
V_69 = ( V_68 & ~ V_74 )
| V_75 ;
V_50 = ( V_66 >> V_76 )
& V_77 ;
} else if ( ( V_6 -> V_71 & ( 1 << V_78 ) ) &&
V_6 -> V_49 ) {
V_69 = ( V_68 & ~ V_74 )
| V_79 ;
V_50 = F_20 ( V_6 , V_80 )
& V_77 ;
V_67 = ( V_66 & ~ V_81 ) |
( V_50 << V_76 ) |
V_73 ;
} else {
V_67 = V_66 & ~ V_73 ;
V_69 = V_68 ;
V_50 = V_54 ;
}
if ( V_68 != V_69 ) {
F_21 ( V_6 , V_70 ,
V_67 & ~ V_73 ) ;
F_22 ( V_6 , V_43 , V_69 ) ;
}
if ( V_67 & V_73 )
F_21 ( V_6 , V_82 ,
F_17 ( V_50 ) |
( ( V_6 -> V_71 & ( 1 << V_72 ) ) ?
V_6 -> V_83 : V_6 -> V_84 ) ) ;
F_21 ( V_6 , V_70 , V_67 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_17 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_21 ;
F_3 ( & V_6 -> V_19 ) ;
V_21 = V_12 -> V_12 . integer . V_12 [ 0 ] != V_6 -> V_49 ;
if ( V_21 ) {
V_6 -> V_49 = ! ! V_12 -> V_12 . integer . V_12 [ 0 ] ;
F_24 ( & V_6 -> V_85 ) ;
F_18 ( V_6 ) ;
F_25 ( & V_6 -> V_85 ) ;
}
F_4 ( & V_6 -> V_19 ) ;
return V_21 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> type = V_86 ;
V_4 -> V_9 = 1 ;
return 0 ;
}
static void F_27 ( T_2 V_87 , struct V_17 * V_12 )
{
V_12 -> V_12 . V_88 . V_89 [ 0 ] =
V_87 & ( V_90 | V_91 |
V_92 ) ;
V_12 -> V_12 . V_88 . V_89 [ 1 ] =
V_87 >> V_93 ;
}
static T_2 F_28 ( struct V_17 * V_12 )
{
T_2 V_87 ;
V_87 = V_12 -> V_12 . V_88 . V_89 [ 0 ] &
( V_90 | V_91 |
V_92 ) ;
V_87 |= V_12 -> V_12 . V_88 . V_89 [ 1 ] << V_93 ;
if ( V_87 & V_90 )
V_87 |= V_94 ;
return V_87 ;
}
static inline void F_29 ( struct V_5 * V_6 , T_2 V_87 )
{
F_30 ( V_6 , V_82 , V_87 ,
V_90 |
V_91 |
V_92 |
V_95 |
V_96 |
V_94 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_17 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_3 ( & V_6 -> V_19 ) ;
F_27 ( V_6 -> V_84 , V_12 ) ;
F_4 ( & V_6 -> V_19 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_17 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_97 ;
int V_21 ;
V_97 = F_28 ( V_12 ) ;
F_3 ( & V_6 -> V_19 ) ;
V_21 = V_97 != V_6 -> V_84 ;
if ( V_21 ) {
V_6 -> V_84 = V_97 ;
if ( ! ( V_6 -> V_71 & ( 1 << V_72 ) ) )
F_29 ( V_6 , V_97 ) ;
}
F_4 ( & V_6 -> V_19 ) ;
return V_21 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_17 * V_12 )
{
V_12 -> V_12 . V_88 . V_89 [ 0 ] = V_98 |
V_99 | V_100 ;
V_12 -> V_12 . V_88 . V_89 [ 1 ] =
V_101 | V_102 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_17 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_3 ( & V_6 -> V_19 ) ;
F_27 ( V_6 -> V_83 , V_12 ) ;
F_4 ( & V_6 -> V_19 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_17 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_97 ;
int V_21 ;
V_97 = F_28 ( V_12 ) ;
F_3 ( & V_6 -> V_19 ) ;
V_21 = V_97 != V_6 -> V_83 ;
if ( V_21 ) {
V_6 -> V_83 = V_97 ;
if ( V_6 -> V_71 & ( 1 << V_72 ) )
F_29 ( V_6 , V_97 ) ;
}
F_4 ( & V_6 -> V_19 ) ;
return V_21 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_17 * V_12 )
{
V_12 -> V_12 . V_88 . V_89 [ 0 ] = 0xff ;
V_12 -> V_12 . V_88 . V_89 [ 1 ] = 0xff ;
V_12 -> V_12 . V_88 . V_89 [ 2 ] = 0xff ;
V_12 -> V_12 . V_88 . V_89 [ 3 ] = 0xff ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_17 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_87 ;
V_87 = F_19 ( V_6 , V_103 ) ;
V_12 -> V_12 . V_88 . V_89 [ 0 ] = V_87 ;
V_12 -> V_12 . V_88 . V_89 [ 1 ] = V_87 >> 8 ;
V_12 -> V_12 . V_88 . V_89 [ 2 ] = V_87 >> 16 ;
V_12 -> V_12 . V_88 . V_89 [ 3 ] = V_87 >> 24 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_17 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_104 = V_2 -> V_105 ;
V_12 -> V_12 . integer . V_12 [ 0 ] =
! ! ( F_19 ( V_6 , V_70 ) & V_104 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_17 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_104 = V_2 -> V_105 ;
T_2 V_106 , V_107 ;
int V_21 ;
F_24 ( & V_6 -> V_85 ) ;
V_106 = F_19 ( V_6 , V_70 ) ;
if ( V_12 -> V_12 . integer . V_12 [ 0 ] )
V_107 = V_106 | V_104 ;
else
V_107 = V_106 & ~ V_104 ;
V_21 = V_107 != V_106 ;
if ( V_21 )
F_21 ( V_6 , V_70 , V_107 ) ;
F_25 ( & V_6 -> V_85 ) ;
return V_21 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> type = V_8 ;
V_4 -> V_9 = 1 ;
V_4 -> V_12 . integer . V_13 = 0 ;
V_4 -> V_12 . integer . V_15 = 1 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_17 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_104 = V_2 -> V_105 ;
int V_108 = V_2 -> V_105 & ( 1 << 8 ) ;
V_12 -> V_12 . integer . V_12 [ 0 ] =
! ! V_108 ^ ! ! ( F_13 ( V_6 , V_109 ) & V_104 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_17 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_104 = V_2 -> V_105 ;
int V_108 = V_2 -> V_105 & ( 1 << 8 ) ;
T_1 V_106 , V_107 ;
int V_21 ;
F_24 ( & V_6 -> V_85 ) ;
V_106 = F_13 ( V_6 , V_109 ) ;
if ( ( ! ! V_12 -> V_12 . integer . V_12 [ 0 ] ^ ! ! V_108 ) != 0 )
V_107 = V_106 | V_104 ;
else
V_107 = V_106 & ~ V_104 ;
V_21 = V_107 != V_106 ;
if ( V_21 )
F_43 ( V_6 , V_109 , V_107 ) ;
F_25 ( & V_6 -> V_85 ) ;
return V_21 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_17 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_110 = ( V_2 -> V_105 >> 24 ) & 1 ;
unsigned int V_111 = V_2 -> V_105 & 0xff ;
unsigned int V_112 = ( V_2 -> V_105 >> 8 ) & 0xff ;
int V_108 = V_2 -> V_105 & ( 1 << 16 ) ;
T_3 V_113 ;
F_3 ( & V_6 -> V_19 ) ;
V_113 = F_45 ( V_6 , V_110 , V_111 ) ;
F_4 ( & V_6 -> V_19 ) ;
if ( ! ( V_113 & ( 1 << V_112 ) ) ^ ! V_108 )
V_12 -> V_12 . integer . V_12 [ 0 ] = 1 ;
else
V_12 -> V_12 . integer . V_12 [ 0 ] = 0 ;
return 0 ;
}
static void F_46 ( struct V_5 * V_6 , unsigned int V_114 )
{
unsigned int V_115 ;
T_3 V_12 ;
if ( ! V_6 -> V_116 [ V_114 ] )
return;
V_115 = V_6 -> V_116 [ V_114 ] -> V_105 & 0xff ;
V_12 = F_45 ( V_6 , 0 , V_115 ) ;
if ( ! ( V_12 & 0x8000 ) ) {
F_47 ( V_6 , 0 , V_115 , V_12 | 0x8000 ) ;
if ( V_6 -> V_10 . V_117 )
V_6 -> V_10 . V_117 ( V_6 , V_115 , 0x8000 ) ;
F_48 ( V_6 -> V_118 , V_119 ,
& V_6 -> V_116 [ V_114 ] -> V_120 ) ;
}
}
static int F_49 ( struct V_1 * V_2 ,
struct V_17 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_110 = ( V_2 -> V_105 >> 24 ) & 1 ;
unsigned int V_111 = V_2 -> V_105 & 0xff ;
unsigned int V_112 = ( V_2 -> V_105 >> 8 ) & 0xff ;
int V_108 = V_2 -> V_105 & ( 1 << 16 ) ;
T_3 V_106 , V_107 ;
int V_121 ;
F_3 ( & V_6 -> V_19 ) ;
V_106 = F_45 ( V_6 , V_110 , V_111 ) ;
V_107 = V_106 ;
if ( ! V_12 -> V_12 . integer . V_12 [ 0 ] ^ ! V_108 )
V_107 |= 1 << V_112 ;
else
V_107 &= ~ ( 1 << V_112 ) ;
V_121 = V_107 != V_106 ;
if ( V_121 ) {
F_47 ( V_6 , V_110 , V_111 , V_107 ) ;
if ( V_110 == 0 && V_6 -> V_10 . V_117 )
V_6 -> V_10 . V_117 ( V_6 , V_111 , V_107 & 0x8000 ) ;
if ( V_111 == V_122 ) {
F_50 ( V_6 , 0 , V_123 ,
V_107 & 0x8000 ?
V_124 : 0 , V_124 ) ;
if ( ! ( V_107 & 0x8000 ) ) {
F_46 ( V_6 , V_125 ) ;
F_46 ( V_6 , V_126 ) ;
F_46 ( V_6 , V_127 ) ;
}
} else if ( ( V_111 == V_128 || V_111 == V_129 ||
V_111 == V_130 || V_111 == V_131 ) &&
V_112 == 15 && ! ( V_107 & 0x8000 ) ) {
F_46 ( V_6 , V_132 ) ;
F_50 ( V_6 , 0 , V_123 ,
V_124 , V_124 ) ;
}
}
F_4 ( & V_6 -> V_19 ) ;
return V_121 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_133 = ( V_2 -> V_105 >> 16 ) & 1 ;
V_4 -> type = V_8 ;
V_4 -> V_9 = V_133 ? 2 : 1 ;
V_4 -> V_12 . integer . V_13 = 0 ;
V_4 -> V_12 . integer . V_15 = 0x1f ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_17 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_110 = ( V_2 -> V_105 >> 24 ) & 1 ;
int V_133 = ( V_2 -> V_105 >> 16 ) & 1 ;
unsigned int V_111 = V_2 -> V_105 & 0xff ;
T_3 V_113 ;
F_3 ( & V_6 -> V_19 ) ;
V_113 = F_45 ( V_6 , V_110 , V_111 ) ;
F_4 ( & V_6 -> V_19 ) ;
if ( ! V_133 ) {
V_12 -> V_12 . integer . V_12 [ 0 ] = 31 - ( V_113 & 0x1f ) ;
} else {
V_12 -> V_12 . integer . V_12 [ 0 ] = 31 - ( ( V_113 >> 8 ) & 0x1f ) ;
V_12 -> V_12 . integer . V_12 [ 1 ] = 31 - ( V_113 & 0x1f ) ;
}
return 0 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_17 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_110 = ( V_2 -> V_105 >> 24 ) & 1 ;
int V_133 = ( V_2 -> V_105 >> 16 ) & 1 ;
unsigned int V_111 = V_2 -> V_105 & 0xff ;
T_3 V_106 , V_107 ;
int V_121 ;
F_3 ( & V_6 -> V_19 ) ;
V_106 = F_45 ( V_6 , V_110 , V_111 ) ;
if ( ! V_133 ) {
V_107 = V_106 & ~ 0x1f ;
V_107 |= 31 - ( V_12 -> V_12 . integer . V_12 [ 0 ] & 0x1f ) ;
} else {
V_107 = V_106 & ~ 0x1f1f ;
V_107 |= ( 31 - ( V_12 -> V_12 . integer . V_12 [ 0 ] & 0x1f ) ) << 8 ;
V_107 |= 31 - ( V_12 -> V_12 . integer . V_12 [ 1 ] & 0x1f ) ;
}
V_121 = V_107 != V_106 ;
if ( V_121 )
F_47 ( V_6 , V_110 , V_111 , V_107 ) ;
F_4 ( & V_6 -> V_19 ) ;
return V_121 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
static const char * const V_27 [] = { L_6 , L_7 } ;
return F_10 ( V_4 , 1 , 2 , V_27 ) ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_17 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_3 ( & V_6 -> V_19 ) ;
V_12 -> V_12 . V_28 . V_29 [ 0 ] =
! ! ( F_45 ( V_6 , 0 , V_134 ) & V_135 ) ;
F_4 ( & V_6 -> V_19 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_17 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 V_106 , V_107 ;
int V_121 ;
F_3 ( & V_6 -> V_19 ) ;
V_106 = F_45 ( V_6 , 0 , V_134 ) ;
if ( V_12 -> V_12 . V_28 . V_29 [ 0 ] )
V_107 = V_106 | V_135 ;
else
V_107 = V_106 & ~ V_135 ;
V_121 = V_107 != V_106 ;
if ( V_121 )
F_47 ( V_6 , 0 , V_134 , V_107 ) ;
F_4 ( & V_6 -> V_19 ) ;
return V_121 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> type = V_8 ;
V_4 -> V_9 = 2 ;
V_4 -> V_12 . integer . V_13 = 0 ;
V_4 -> V_12 . integer . V_15 = 7 ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_17 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 V_113 ;
F_3 ( & V_6 -> V_19 ) ;
V_113 = F_45 ( V_6 , 1 , V_136 ) ;
F_4 ( & V_6 -> V_19 ) ;
V_12 -> V_12 . integer . V_12 [ 0 ] = V_113 & 7 ;
V_12 -> V_12 . integer . V_12 [ 1 ] = ( V_113 >> 8 ) & 7 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_17 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 V_106 , V_107 ;
int V_121 ;
F_3 ( & V_6 -> V_19 ) ;
V_106 = F_45 ( V_6 , 1 , V_136 ) ;
V_107 = V_106 & ~ 0x0707 ;
V_107 = V_107 | ( V_12 -> V_12 . integer . V_12 [ 0 ] & 7 ) ;
V_107 = V_107 | ( ( V_12 -> V_12 . integer . V_12 [ 0 ] & 7 ) << 8 ) ;
V_121 = V_107 != V_106 ;
if ( V_121 )
F_47 ( V_6 , 1 , V_136 , V_107 ) ;
F_4 ( & V_6 -> V_19 ) ;
return V_121 ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_18 ;
for ( V_18 = 0 ; V_18 < F_61 ( V_6 -> V_116 ) ; ++ V_18 )
V_6 -> V_116 [ V_18 ] = NULL ;
}
static int F_62 ( struct V_5 * V_6 ,
const struct V_137 V_116 [] ,
unsigned int V_9 )
{
static const char * const V_138 [ V_139 ] = {
[ V_140 ] =
F_63 ( L_8 , V_141 , V_142 ) ,
[ V_143 ] =
F_63 ( L_8 , V_144 , DEFAULT ) ,
[ V_125 ] = L_9 ,
[ V_132 ] = L_10 ,
[ V_126 ] = L_11 ,
[ V_127 ] = L_12 ,
} ;
unsigned int V_18 , V_145 ;
struct V_137 V_146 ;
struct V_1 * V_2 ;
int V_147 ;
for ( V_18 = 0 ; V_18 < V_9 ; ++ V_18 ) {
V_146 = V_116 [ V_18 ] ;
if ( V_6 -> V_10 . V_148 ) {
V_147 = V_6 -> V_10 . V_148 ( & V_146 ) ;
if ( V_147 < 0 )
return V_147 ;
if ( V_147 == 1 )
continue;
}
if ( ! strcmp ( V_146 . V_149 , L_13 ) &&
V_6 -> V_10 . V_25 == 2 )
continue;
if ( ! strcmp ( V_146 . V_149 , L_14 ) &&
! ( V_6 -> V_10 . V_150 & V_151 ) )
continue;
if ( ! strncmp ( V_146 . V_149 , L_15 , 11 ) &&
! ( V_6 -> V_10 . V_150 & V_152 ) )
continue;
if ( ! strcmp ( V_146 . V_149 , L_16 ) &&
V_6 -> V_10 . V_153 ) {
V_146 . V_154 . V_155 = V_6 -> V_10 . V_153 ;
V_146 . V_156 |= V_157 ;
}
V_2 = F_64 ( & V_146 , V_6 ) ;
if ( ! V_2 )
return - V_158 ;
V_147 = F_65 ( V_6 -> V_118 , V_2 ) ;
if ( V_147 < 0 )
return V_147 ;
for ( V_145 = 0 ; V_145 < V_139 ; ++ V_145 )
if ( ! strcmp ( V_2 -> V_120 . V_149 , V_138 [ V_145 ] ) ) {
V_6 -> V_116 [ V_145 ] = V_2 ;
V_2 -> V_159 = F_60 ;
}
}
return 0 ;
}
int F_66 ( struct V_5 * V_6 )
{
unsigned int V_18 ;
int V_147 ;
V_147 = F_62 ( V_6 , V_116 , F_61 ( V_116 ) ) ;
if ( V_147 < 0 )
return V_147 ;
if ( V_6 -> V_10 . V_150 & V_160 ) {
V_147 = F_62 ( V_6 , V_161 ,
F_61 ( V_161 ) ) ;
if ( V_147 < 0 )
return V_147 ;
}
for ( V_18 = 0 ; V_18 < F_61 ( V_162 ) ; ++ V_18 ) {
if ( ! ( V_6 -> V_10 . V_150 & V_162 [ V_18 ] . V_163 ) )
continue;
V_147 = F_62 ( V_6 , V_162 [ V_18 ] . V_116 ,
F_61 ( V_162 [ V_18 ] . V_116 ) ) ;
if ( V_147 < 0 )
return V_147 ;
}
if ( V_6 -> V_164 ) {
V_147 = F_62 ( V_6 , V_165 ,
F_61 ( V_165 ) ) ;
if ( V_147 < 0 )
return V_147 ;
}
if ( V_6 -> V_166 ) {
V_147 = F_62 ( V_6 , V_167 ,
F_61 ( V_167 ) ) ;
if ( V_147 < 0 )
return V_147 ;
}
return V_6 -> V_10 . V_168 ? V_6 -> V_10 . V_168 ( V_6 ) : 0 ;
}
