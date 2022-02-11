static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
#ifdef F_2
struct V_5 * V_6 = V_3 -> V_7 ;
V_4 = V_6 -> V_8 ;
#else
V_4 = V_3 -> V_7 ;
#endif
return V_4 ;
}
static inline bool F_3 ( T_1 V_9 )
{
return ! ! ( V_9 == V_10 ) ;
}
static inline T_1 F_4 ( struct V_1 * V_4 ,
enum V_11 V_12 )
{
return V_4 -> V_13 [ V_12 ] ;
}
static inline T_2 F_5 ( struct V_1 * V_4 ,
enum V_11 V_12 )
{
T_1 V_14 = F_4 ( V_4 , V_12 ) ;
if ( F_3 ( V_14 ) )
return 0 ;
return F_6 ( V_4 -> V_15 + V_14 ) ;
}
static inline void F_7 ( struct V_1 * V_4 ,
enum V_11 V_12 , T_2 V_16 )
{
T_1 V_14 = F_4 ( V_4 , V_12 ) ;
if ( F_3 ( V_14 ) )
return;
F_8 ( V_16 , V_4 -> V_15 + V_14 ) ;
}
static inline void F_9 ( struct V_2 * V_3 ,
bool V_17 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_16 ;
if ( V_3 -> V_18 && V_4 -> V_19 ) {
V_16 = F_5 ( V_4 , V_20 ) ;
if ( V_17 )
V_16 &= ~ V_21 ;
else
V_16 |= V_21 ;
F_7 ( V_4 , V_20 , V_16 ) ;
}
}
static void T_3 * F_10 ( struct V_1 * V_4 ,
unsigned int V_22 ,
unsigned int V_23 ,
unsigned int V_24 ,
int V_25 )
{
T_1 V_14 ;
T_2 V_16 ;
V_16 = ( V_22 << V_26 ) |
( V_23 << V_27 ) |
( V_24 << V_28 ) |
( V_25 & V_29 ) |
( 1 & V_30 ) ;
F_7 ( V_4 , V_31 , V_16 ) ;
V_14 = F_4 ( V_4 , V_32 ) ;
if ( F_3 ( V_14 ) )
return NULL ;
return ( V_4 -> V_15 + V_14 ) ;
}
static unsigned int F_11 ( void T_3 * V_33 )
{
int V_34 = V_35 ;
unsigned int V_36 ;
V_36 = F_6 ( V_33 ) ;
while ( V_36 == V_37 && V_34 -- ) {
F_12 ( 1 ) ;
V_36 = F_6 ( V_33 ) ;
}
if ( V_36 == V_37 )
V_36 = 0xffffffff ;
return V_36 ;
}
static int F_13 ( struct V_2 * V_3 , unsigned int V_38 ,
int V_25 , int V_39 , T_2 * V_16 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_23 = F_14 ( V_38 ) ;
unsigned int V_24 = F_15 ( V_38 ) ;
unsigned int V_22 = V_3 -> V_18 ;
void T_3 * V_33 ;
unsigned int V_36 ;
int V_40 ;
if ( V_22 == 0 ) {
V_40 = F_16 ( V_3 , V_38 , V_25 , V_39 , V_16 ) ;
if ( V_40 != V_41 )
return V_40 ;
if ( ( V_25 & ~ 0x3 ) == V_42 + V_43 )
* V_16 &= ~ ( V_44 << 16 ) ;
return V_41 ;
}
V_33 = F_10 ( V_4 , V_22 , V_23 , V_24 , V_25 ) ;
if ( ! V_33 )
return V_45 ;
V_36 = F_11 ( V_33 ) ;
* V_16 = V_36 ;
if ( V_39 <= 2 )
* V_16 = ( V_36 >> ( 8 * ( V_25 & 3 ) ) ) & ( ( 1 << ( V_39 * 8 ) ) - 1 ) ;
return V_41 ;
}
static void T_3 * F_17 ( struct V_1 * V_4 ,
int V_22 , unsigned int V_38 ,
int V_25 )
{
unsigned V_23 = F_14 ( V_38 ) ;
unsigned V_24 = F_15 ( V_38 ) ;
T_1 V_14 ;
if ( V_22 == 0 ) {
if ( V_23 > 0 || V_24 > 0 )
return NULL ;
F_7 ( V_4 , V_46 ,
V_25 & V_47 ) ;
V_14 = F_4 ( V_4 , V_48 ) ;
if ( F_3 ( V_14 ) )
return NULL ;
else
return ( V_4 -> V_15 + V_14 ) ;
}
if ( V_4 -> V_49 )
if ( V_23 > 0 )
return NULL ;
return F_10 ( V_4 , V_22 , V_23 , V_24 , V_25 ) ;
}
static void T_3 * F_18 ( struct V_2 * V_3 ,
unsigned int V_38 ,
int V_25 )
{
return F_17 ( F_1 ( V_3 ) , V_3 -> V_18 , V_38 ,
V_25 ) ;
}
static int F_19 ( struct V_1 * V_4 ,
unsigned int V_38 , int V_25 ,
int V_39 , T_2 * V_16 )
{
void T_3 * V_50 ;
V_50 = F_17 ( V_4 , 0 , V_38 , V_25 & ~ 0x3 ) ;
if ( ! V_50 ) {
* V_16 = ~ 0 ;
return V_45 ;
}
* V_16 = F_6 ( V_50 ) ;
if ( V_39 <= 2 )
* V_16 = ( * V_16 >> ( 8 * ( V_25 & 3 ) ) ) & ( ( 1 << ( V_39 * 8 ) ) - 1 ) ;
return V_41 ;
}
static int F_20 ( struct V_1 * V_4 ,
unsigned int V_38 , int V_25 ,
int V_39 , T_2 V_16 )
{
void T_3 * V_50 ;
T_2 V_51 , V_52 ;
V_50 = F_17 ( V_4 , 0 , V_38 , V_25 & ~ 0x3 ) ;
if ( ! V_50 )
return V_45 ;
if ( V_39 == 4 ) {
F_8 ( V_16 , V_50 ) ;
return V_41 ;
}
V_51 = ~ ( ( ( 1 << ( V_39 * 8 ) ) - 1 ) << ( ( V_25 & 0x3 ) * 8 ) ) ;
V_52 = F_6 ( V_50 ) & V_51 ;
V_52 |= V_16 << ( ( V_25 & 0x3 ) * 8 ) ;
F_8 ( V_52 , V_50 ) ;
return V_41 ;
}
static int F_21 ( struct V_2 * V_3 , unsigned int V_38 ,
int V_25 , int V_39 , T_2 * V_16 )
{
int V_40 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_9 ( V_3 , true ) ;
if ( V_4 -> type == V_53 )
V_40 = F_13 ( V_3 , V_38 , V_25 , V_39 , V_16 ) ;
else
V_40 = F_16 ( V_3 , V_38 , V_25 , V_39 , V_16 ) ;
F_9 ( V_3 , false ) ;
return V_40 ;
}
static int F_22 ( struct V_2 * V_3 , unsigned int V_38 ,
int V_25 , int V_39 , T_2 V_16 )
{
int V_40 ;
F_9 ( V_3 , true ) ;
V_40 = F_23 ( V_3 , V_38 , V_25 , V_39 , V_16 ) ;
F_9 ( V_3 , false ) ;
return V_40 ;
}
static void F_24 ( struct V_1 * V_4 , bool assert )
{
T_2 V_16 ;
if ( V_4 -> V_49 )
return;
if ( assert ) {
V_16 = F_5 ( V_4 , V_54 ) ;
V_16 &= ~ V_55 & ~ V_56 &
~ V_57 ;
F_7 ( V_4 , V_54 , V_16 ) ;
F_12 ( 250 ) ;
} else {
V_16 = F_5 ( V_4 , V_54 ) ;
V_16 |= V_57 ;
F_7 ( V_4 , V_54 , V_16 ) ;
F_25 ( 100 ) ;
}
}
int F_26 ( struct V_1 * V_4 )
{
F_24 ( V_4 , true ) ;
F_25 ( 500 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_4 )
{
struct V_58 * V_59 = V_4 -> V_59 ;
T_2 V_60 , V_61 , V_62 , V_63 , V_16 ;
bool V_64 = false ;
if ( V_4 -> V_49 )
return 0 ;
V_16 = F_5 ( V_4 , V_65 ) ;
if ( ! ( V_16 & V_66 ) || ! ( V_16 & V_67 ) ) {
F_28 ( V_59 , L_1 ) ;
return - V_68 ;
}
F_19 ( V_4 , 0 , V_69 , 1 , & V_60 ) ;
if ( ( V_60 & 0x7f ) != V_70 ) {
F_28 ( V_59 , L_2 , V_60 ) ;
return - V_71 ;
}
#define F_29 0x43c
#define F_30 0xffff00
#define F_31 8
F_19 ( V_4 , 0 , F_29 ,
4 , & V_63 ) ;
V_63 &= ~ F_30 ;
V_63 |= ( V_72 << F_31 ) ;
F_20 ( V_4 , 0 , F_29 ,
4 , V_63 ) ;
F_19 ( V_4 , 0 , V_42 + V_73 ,
2 , & V_62 ) ;
if ( V_62 & V_74 )
V_64 = true ;
if ( ! V_64 ) {
#define F_32 0xf
#define F_33 0x2
#define F_34 0x1
F_19 ( V_4 , 0 ,
V_42 + V_75 ,
4 , & V_61 ) ;
if ( ( V_61 & F_32 ) ==
F_33 ) {
V_61 &= ~ F_32 ;
V_61 |= F_34 ;
F_20 ( V_4 , 0 ,
V_42 + V_75 ,
4 , V_61 ) ;
F_25 ( 100 ) ;
F_19 ( V_4 , 0 ,
V_42 + V_73 ,
2 , & V_62 ) ;
if ( V_62 & V_74 )
V_64 = true ;
}
}
F_35 ( V_59 , L_3 , V_64 ? L_4 : L_5 ) ;
return V_64 ? 0 : - V_68 ;
}
static void F_36 ( struct V_1 * V_4 )
{
F_7 ( V_4 , V_76 , V_77 ) ;
}
static inline bool F_37 ( struct V_1 * V_4 ,
int V_78 )
{
T_2 V_16 ;
V_16 = F_5 ( V_4 , F_38 ( V_79 , V_78 ) ) ;
return ! ! ( V_16 & V_80 ) ;
}
static inline int F_39 ( struct V_1 * V_4 , int V_78 ,
int V_81 , T_4 V_82 , T_4 V_83 )
{
struct V_58 * V_59 = V_4 -> V_59 ;
T_1 V_84 , V_85 ;
V_84 = F_4 ( V_4 , F_38 ( V_79 ,
V_78 ) ) ;
V_85 = F_4 ( V_4 , F_38 ( V_86 ,
V_78 ) ) ;
if ( F_3 ( V_84 ) ||
F_3 ( V_85 ) )
return - V_87 ;
F_8 ( F_40 ( V_82 ) | ( V_81 << V_88 ) |
V_80 , V_4 -> V_15 + V_84 ) ;
F_8 ( F_41 ( V_82 ) , V_4 -> V_15 + V_84 + 4 ) ;
F_8 ( F_40 ( V_83 ) , V_4 -> V_15 + V_85 ) ;
F_8 ( F_41 ( V_83 ) , V_4 -> V_15 + V_85 + 4 ) ;
F_35 ( V_59 , L_6 ,
V_78 , V_84 , & V_82 , & V_83 ) ;
F_35 ( V_59 , L_7 ,
F_6 ( V_4 -> V_15 + V_84 ) ,
F_6 ( V_4 -> V_15 + V_84 + 4 ) ) ;
F_35 ( V_59 , L_8 ,
F_6 ( V_4 -> V_15 + V_85 ) ,
F_6 ( V_4 -> V_15 + V_85 + 4 ) ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_4 , T_4 V_82 ,
T_4 V_83 , T_5 V_39 )
{
struct V_89 * V_90 = & V_4 -> V_90 ;
struct V_58 * V_59 = V_4 -> V_59 ;
int V_40 = - V_87 , V_78 , V_81 ;
if ( V_82 < V_90 -> V_91 ) {
F_28 ( V_59 , L_9 ,
& V_82 , & V_90 -> V_91 ) ;
return - V_87 ;
}
V_82 -= V_90 -> V_91 ;
for ( V_78 = V_90 -> V_92 - 1 ; V_78 >= 0 ; V_78 -- ) {
const struct V_93 * V_94 =
& V_4 -> V_94 [ V_78 ] ;
if ( F_37 ( V_4 , V_78 ) )
continue;
for ( V_81 = V_94 -> V_95 - 1 ; V_81 >= 0 ;
V_81 -- ) {
T_5 V_96 =
V_94 -> V_97 [ V_81 ] * V_98 ;
if ( V_39 < V_96 )
continue;
if ( ! F_43 ( V_82 , V_96 ) ||
! F_43 ( V_83 , V_96 ) ) {
F_28 ( V_59 ,
L_10 ,
& V_82 , & V_83 ) ;
return - V_87 ;
}
V_40 = F_39 ( V_4 , V_78 , V_81 ,
V_82 , V_83 ) ;
if ( V_40 )
goto V_99;
V_39 -= V_96 ;
if ( V_39 == 0 )
return 0 ;
V_82 += V_96 ;
V_83 += V_96 ;
break;
}
}
V_99:
F_28 ( V_59 , L_11 ) ;
F_28 ( V_59 ,
L_12 ,
& V_82 , & V_90 -> V_91 , & V_83 , & V_39 ) ;
return V_40 ;
}
static int F_44 ( struct V_1 * V_4 ,
struct V_100 * V_101 )
{
struct V_58 * V_59 = V_4 -> V_59 ;
struct V_102 * V_103 ;
int V_40 ;
F_45 (window, resources) {
struct V_104 * V_105 = V_103 -> V_105 ;
T_4 V_106 = F_46 ( V_105 ) ;
switch ( V_106 ) {
case V_107 :
case V_108 :
break;
case V_109 :
V_40 = F_42 ( V_4 , V_105 -> V_110 ,
V_105 -> V_110 - V_103 -> V_14 ,
F_47 ( V_105 ) ) ;
if ( V_40 )
return V_40 ;
break;
default:
F_28 ( V_59 , L_13 , V_105 ) ;
return - V_87 ;
}
}
return 0 ;
}
static inline bool F_48 ( struct V_1 * V_4 ,
int V_111 )
{
const struct V_112 * V_113 = & V_4 -> V_113 [ V_111 ] ;
T_2 V_16 ;
V_16 = F_5 ( V_4 , F_38 ( V_114 , V_111 ) ) ;
return ! ! ( V_16 & ( F_49 ( V_113 -> V_95 ) - 1 ) ) ;
}
static inline bool F_50 ( const struct V_112 * V_113 ,
enum V_115 type )
{
return ! ! ( V_113 -> type == type ) ;
}
static int F_51 ( struct V_1 * V_4 , int V_111 ,
int V_81 , int V_92 , T_4 V_82 ,
T_4 V_83 , T_5 V_39 )
{
struct V_58 * V_59 = V_4 -> V_59 ;
const struct V_112 * V_113 = & V_4 -> V_113 [ V_111 ] ;
T_1 V_116 , V_117 ;
T_2 V_16 ;
int V_78 ;
V_116 = F_4 ( V_4 ,
F_38 ( V_114 , V_111 ) ) ;
V_117 = F_4 ( V_4 ,
F_38 ( V_118 , V_111 ) ) ;
if ( F_3 ( V_116 ) ||
F_3 ( V_117 ) )
return - V_87 ;
F_35 ( V_59 , L_14 ,
V_111 , V_116 , & V_82 , & V_83 ) ;
F_8 ( F_40 ( V_83 ) | F_49 ( V_81 ) ,
V_4 -> V_15 + V_116 ) ;
F_8 ( F_41 ( V_83 ) , V_4 -> V_15 + V_116 + 4 ) ;
F_35 ( V_59 , L_15 ,
F_6 ( V_4 -> V_15 + V_116 ) ,
F_6 ( V_4 -> V_15 + V_116 + 4 ) ) ;
V_39 >>= F_52 ( V_92 ) ;
for ( V_78 = 0 ; V_78 < V_92 ; V_78 ++ ) {
V_16 = F_6 ( V_4 -> V_15 + V_117 ) ;
V_16 |= F_40 ( V_82 ) | V_119 ;
F_8 ( V_16 , V_4 -> V_15 + V_117 ) ;
F_8 ( F_41 ( V_82 ) ,
V_4 -> V_15 + V_117 + V_113 -> V_120 ) ;
F_35 ( V_59 , L_16 ,
V_78 , F_6 ( V_4 -> V_15 + V_117 ) ,
F_6 ( V_4 -> V_15 + V_117 +
V_113 -> V_120 ) ) ;
V_117 += V_113 -> V_121 ;
V_82 += V_39 ;
}
return 0 ;
}
static int F_53 ( struct V_1 * V_4 ,
struct V_122 * V_123 ,
enum V_115 type )
{
struct V_58 * V_59 = V_4 -> V_59 ;
struct V_124 * V_125 = & V_4 -> V_125 ;
int V_40 ;
unsigned int V_111 , V_81 ;
T_4 V_82 = V_123 -> V_126 , V_83 = V_123 -> V_83 ;
T_5 V_39 = V_123 -> V_39 ;
for ( V_111 = 0 ; V_111 < V_125 -> V_127 ; V_111 ++ ) {
const struct V_112 * V_113 =
& V_4 -> V_113 [ V_111 ] ;
if ( F_48 ( V_4 , V_111 ) ||
! F_50 ( V_113 , type ) )
continue;
for ( V_81 = 0 ; V_81 < V_113 -> V_95 ; V_81 ++ ) {
T_5 V_128 =
V_113 -> V_129 [ V_81 ] * V_113 -> V_130 ;
if ( V_39 != V_128 )
continue;
if ( ! F_43 ( V_82 , V_128 ) ||
! F_43 ( V_83 , V_128 ) ) {
F_28 ( V_59 ,
L_10 ,
& V_82 , & V_83 ) ;
return - V_87 ;
}
V_40 = F_51 ( V_4 , V_111 , V_81 ,
V_113 -> V_92 , V_82 ,
V_83 , V_39 ) ;
if ( V_40 )
goto V_131;
else
return 0 ;
}
}
V_40 = - V_87 ;
V_131:
F_28 ( V_59 , L_17 ) ;
F_28 ( V_59 , L_18 ,
& V_82 , & V_83 , & V_39 ) ;
return V_40 ;
}
static int F_54 ( struct V_132 * V_133 ,
struct V_134 * V_135 )
{
const int V_136 = 3 , V_137 = 2 ;
int V_138 ;
V_133 -> V_135 = V_135 ;
V_133 -> V_139 = F_55 ( V_135 ) ;
V_133 -> V_140 = V_133 -> V_139 + V_136 + V_137 ;
V_133 -> V_123 = F_56 ( V_135 , L_19 , & V_138 ) ;
if ( ! V_133 -> V_123 )
return - V_141 ;
V_133 -> V_142 = V_133 -> V_123 + V_138 / sizeof( V_143 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_4 )
{
struct V_122 V_123 ;
struct V_132 V_133 ;
int V_40 ;
V_40 = F_54 ( & V_133 , V_4 -> V_59 -> V_144 ) ;
if ( V_40 )
return V_40 ;
F_58 (&parser, &range) {
V_40 = F_53 ( V_4 , & V_123 , V_145 ) ;
if ( V_40 )
return V_40 ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_4 ,
struct V_134 * V_146 ,
T_4 * V_147 )
{
struct V_58 * V_59 = V_4 -> V_59 ;
int V_40 ;
struct V_104 V_105 ;
if ( ! F_60 ( V_146 , L_20 ) ) {
F_28 ( V_59 , L_21 ) ;
return - V_68 ;
}
V_40 = F_61 ( V_146 , 0 , & V_105 ) ;
if ( V_40 < 0 ) {
F_28 ( V_59 , L_22 ) ;
return V_40 ;
}
* V_147 = V_105 . V_110 + V_148 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_4 , T_4 V_147 )
{
int V_40 ;
struct V_122 V_123 ;
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
V_123 . V_39 = V_149 ;
V_123 . V_83 = V_123 . V_126 = V_147 & ~ ( V_123 . V_39 - 1 ) ;
V_40 = F_53 ( V_4 , & V_123 , V_150 ) ;
return V_40 ;
}
static void F_63 ( struct V_1 * V_4 , T_4 V_147 )
{
T_2 V_16 ;
F_7 ( V_4 , V_151 ,
( T_2 ) ( V_147 >> 13 ) ) ;
F_7 ( V_4 , V_152 , 0 ) ;
V_16 = F_5 ( V_4 , V_153 ) ;
V_16 |= V_154 ;
F_7 ( V_4 , V_153 , V_16 ) ;
V_147 >>= 2 ;
F_7 ( V_4 , V_155 ,
F_41 ( V_147 ) ) ;
F_7 ( V_4 , V_156 ,
F_40 ( V_147 ) ) ;
V_16 = F_5 ( V_4 , V_157 ) ;
V_16 |= V_158 ;
F_7 ( V_4 , V_157 , V_16 ) ;
}
static int F_64 ( struct V_1 * V_4 ,
struct V_134 * V_146 )
{
struct V_58 * V_59 = V_4 -> V_59 ;
int V_40 ;
T_4 V_147 ;
V_40 = F_59 ( V_4 , V_146 , & V_147 ) ;
if ( V_40 < 0 ) {
F_28 ( V_59 , L_23 ) ;
return V_40 ;
}
switch ( V_4 -> type ) {
case V_53 :
V_40 = F_62 ( V_4 , V_147 ) ;
if ( V_40 )
return V_40 ;
break;
case V_159 :
F_63 ( V_4 , V_147 ) ;
break;
default:
return - V_87 ;
}
return 0 ;
}
static int F_65 ( struct V_1 * V_4 )
{
struct V_134 * V_146 ;
int V_40 ;
V_146 = F_66 ( V_4 -> V_59 -> V_144 , L_24 , 0 ) ;
if ( ! V_146 ) {
const V_143 * V_160 = NULL ;
int V_161 ;
T_2 V_162 ;
V_160 = F_56 ( V_4 -> V_59 -> V_144 , L_25 , & V_161 ) ;
if ( ! V_160 )
return - V_68 ;
V_162 = F_67 ( V_160 + 1 ) ;
V_146 = F_68 ( V_162 ) ;
if ( ! V_146 )
return - V_68 ;
}
if ( V_4 -> V_163 ) {
V_40 = F_64 ( V_4 , V_146 ) ;
if ( V_40 )
return V_40 ;
}
return F_69 ( V_4 , V_146 ) ;
}
static void F_70 ( struct V_1 * V_4 )
{
F_71 ( V_4 ) ;
}
static int F_72 ( struct V_1 * V_4 )
{
struct V_58 * V_59 = V_4 -> V_59 ;
unsigned int V_164 ;
const T_1 * V_165 ;
switch ( V_4 -> type ) {
case V_166 :
V_165 = V_167 ;
break;
case V_168 :
V_165 = V_169 ;
V_4 -> V_19 = true ;
if ( V_4 -> V_170 ) {
V_4 -> V_94 = V_171 ;
V_4 -> V_90 . V_92 = F_73 ( V_171 ) ;
}
break;
case V_53 :
V_165 = V_172 ;
V_4 -> V_19 = true ;
if ( V_4 -> V_170 ) {
V_4 -> V_94 = V_173 ;
V_4 -> V_90 . V_92 = F_73 ( V_173 ) ;
}
V_4 -> V_125 . V_127 = F_73 ( V_174 ) ;
V_4 -> V_113 = V_174 ;
V_4 -> V_163 = true ;
F_74 ( V_59 , L_26 ,
V_37 ) ;
break;
case V_175 :
V_165 = V_176 ;
V_4 -> V_49 = true ;
break;
case V_159 :
V_165 = V_177 ;
V_4 -> V_49 = true ;
V_4 -> V_163 = true ;
break;
default:
F_28 ( V_59 , L_27 ) ;
return - V_87 ;
}
V_4 -> V_13 = F_75 ( V_59 , V_178 ,
sizeof( * V_4 -> V_13 ) ,
V_179 ) ;
if ( ! V_4 -> V_13 )
return - V_180 ;
V_4 -> V_13 [ 0 ] = ( V_4 -> type == V_159 ) ?
V_10 : V_165 [ 0 ] ;
for ( V_164 = 1 ; V_164 < V_178 ; V_164 ++ )
V_4 -> V_13 [ V_164 ] = V_165 [ V_164 ] ?
V_165 [ V_164 ] : V_10 ;
return 0 ;
}
int F_76 ( struct V_1 * V_4 , struct V_100 * V_105 )
{
struct V_58 * V_59 ;
int V_40 ;
void * V_7 ;
struct V_2 * V_181 ;
struct V_182 * V_183 = F_77 ( V_4 ) ;
V_59 = V_4 -> V_59 ;
V_40 = F_72 ( V_4 ) ;
if ( V_40 ) {
F_28 ( V_59 , L_28 ) ;
return V_40 ;
}
V_40 = F_78 ( V_59 , V_105 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_79 ( V_4 -> V_184 ) ;
if ( V_40 ) {
F_28 ( V_59 , L_29 ) ;
return V_40 ;
}
V_40 = F_80 ( V_4 -> V_184 ) ;
if ( V_40 ) {
F_28 ( V_59 , L_30 ) ;
goto V_185;
}
F_24 ( V_4 , true ) ;
F_24 ( V_4 , false ) ;
if ( V_4 -> V_170 ) {
V_40 = F_44 ( V_4 , V_105 ) ;
if ( V_40 ) {
F_28 ( V_59 , L_31 ) ;
goto V_186;
}
}
V_40 = F_57 ( V_4 ) ;
if ( V_40 && V_40 != - V_141 )
goto V_186;
#ifdef F_2
V_4 -> V_7 . V_8 = V_4 ;
V_7 = & V_4 -> V_7 ;
#else
V_7 = V_4 ;
#endif
V_40 = F_27 ( V_4 ) ;
if ( V_40 ) {
F_28 ( V_59 , L_32 ) ;
goto V_186;
}
F_36 ( V_4 ) ;
if ( F_81 ( V_187 ) )
if ( F_65 ( V_4 ) )
F_35 ( V_59 , L_33 ) ;
F_82 ( V_105 , & V_183 -> V_188 ) ;
V_183 -> V_189 = 0 ;
V_183 -> V_59 . V_190 = V_59 ;
V_183 -> V_191 = & V_192 ;
V_183 -> V_7 = V_7 ;
V_183 -> V_193 = V_4 -> V_193 ;
V_183 -> V_194 = V_195 ;
V_40 = F_83 ( V_183 ) ;
if ( V_40 < 0 ) {
F_28 ( V_59 , L_34 , V_40 ) ;
goto V_186;
}
F_84 ( V_183 -> V_3 ) ;
V_4 -> V_196 = V_183 -> V_3 ;
F_85 (child, &host->bus->children, node)
F_86 ( V_181 ) ;
F_87 ( V_183 -> V_3 ) ;
return 0 ;
V_186:
F_88 ( V_4 -> V_184 ) ;
V_185:
F_89 ( V_4 -> V_184 ) ;
return V_40 ;
}
int F_90 ( struct V_1 * V_4 )
{
F_91 ( V_4 -> V_196 ) ;
F_92 ( V_4 -> V_196 ) ;
F_70 ( V_4 ) ;
F_88 ( V_4 -> V_184 ) ;
F_89 ( V_4 -> V_184 ) ;
return 0 ;
}
