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
int V_22 ,
unsigned int V_23 ,
int V_24 )
{
unsigned V_25 = F_11 ( V_23 ) ;
unsigned V_26 = F_12 ( V_23 ) ;
T_2 V_16 ;
T_1 V_14 ;
if ( V_22 == 0 ) {
if ( V_25 > 0 || V_26 > 0 )
return NULL ;
F_7 ( V_4 , V_27 ,
V_24 & V_28 ) ;
V_14 = F_4 ( V_4 , V_29 ) ;
if ( F_3 ( V_14 ) )
return NULL ;
else
return ( V_4 -> V_15 + V_14 ) ;
}
if ( V_4 -> V_30 )
if ( V_25 > 0 )
return NULL ;
V_16 = ( V_22 << V_31 ) |
( V_25 << V_32 ) |
( V_26 << V_33 ) |
( V_24 & V_34 ) |
( 1 & V_35 ) ;
F_7 ( V_4 , V_36 , V_16 ) ;
V_14 = F_4 ( V_4 , V_37 ) ;
if ( F_3 ( V_14 ) )
return NULL ;
else
return ( V_4 -> V_15 + V_14 ) ;
}
static void T_3 * F_13 ( struct V_2 * V_3 ,
unsigned int V_23 ,
int V_24 )
{
return F_10 ( F_1 ( V_3 ) , V_3 -> V_18 , V_23 ,
V_24 ) ;
}
static int F_14 ( struct V_1 * V_4 ,
unsigned int V_23 , int V_24 ,
int V_38 , T_2 * V_16 )
{
void T_3 * V_39 ;
V_39 = F_10 ( V_4 , 0 , V_23 , V_24 & ~ 0x3 ) ;
if ( ! V_39 ) {
* V_16 = ~ 0 ;
return V_40 ;
}
* V_16 = F_6 ( V_39 ) ;
if ( V_38 <= 2 )
* V_16 = ( * V_16 >> ( 8 * ( V_24 & 3 ) ) ) & ( ( 1 << ( V_38 * 8 ) ) - 1 ) ;
return V_41 ;
}
static int F_15 ( struct V_1 * V_4 ,
unsigned int V_23 , int V_24 ,
int V_38 , T_2 V_16 )
{
void T_3 * V_39 ;
T_2 V_42 , V_43 ;
V_39 = F_10 ( V_4 , 0 , V_23 , V_24 & ~ 0x3 ) ;
if ( ! V_39 )
return V_40 ;
if ( V_38 == 4 ) {
F_8 ( V_16 , V_39 ) ;
return V_41 ;
}
V_42 = ~ ( ( ( 1 << ( V_38 * 8 ) ) - 1 ) << ( ( V_24 & 0x3 ) * 8 ) ) ;
V_43 = F_6 ( V_39 ) & V_42 ;
V_43 |= V_16 << ( ( V_24 & 0x3 ) * 8 ) ;
F_8 ( V_43 , V_39 ) ;
return V_41 ;
}
static int F_16 ( struct V_2 * V_3 , unsigned int V_23 ,
int V_24 , int V_38 , T_2 * V_16 )
{
int V_44 ;
F_9 ( V_3 , true ) ;
V_44 = F_17 ( V_3 , V_23 , V_24 , V_38 , V_16 ) ;
F_9 ( V_3 , false ) ;
return V_44 ;
}
static int F_18 ( struct V_2 * V_3 , unsigned int V_23 ,
int V_24 , int V_38 , T_2 V_16 )
{
int V_44 ;
F_9 ( V_3 , true ) ;
V_44 = F_19 ( V_3 , V_23 , V_24 , V_38 , V_16 ) ;
F_9 ( V_3 , false ) ;
return V_44 ;
}
static void F_20 ( struct V_1 * V_4 )
{
T_2 V_16 ;
if ( V_4 -> V_30 )
return;
V_16 = F_5 ( V_4 , V_45 ) ;
V_16 &= ~ V_46 & ~ V_47 &
~ V_48 ;
F_7 ( V_4 , V_45 , V_16 ) ;
F_21 ( 250 ) ;
V_16 |= V_48 ;
F_7 ( V_4 , V_45 , V_16 ) ;
F_22 ( 100 ) ;
}
static int F_23 ( struct V_1 * V_4 )
{
struct V_49 * V_50 = V_4 -> V_50 ;
T_2 V_51 , V_52 , V_53 , V_54 , V_16 ;
T_1 V_55 = V_56 ;
bool V_57 = false ;
if ( V_4 -> V_30 )
return 0 ;
V_16 = F_5 ( V_4 , V_58 ) ;
if ( ! ( V_16 & V_59 ) || ! ( V_16 & V_60 ) ) {
F_24 ( V_50 , L_1 ) ;
return - V_61 ;
}
F_14 ( V_4 , 0 , V_62 , 1 , & V_51 ) ;
if ( ( V_51 & 0x7f ) != V_63 ) {
F_24 ( V_50 , L_2 , V_51 ) ;
return - V_64 ;
}
#define F_25 0x43c
#define F_26 0xffff00
#define F_27 8
F_14 ( V_4 , 0 , F_25 ,
4 , & V_54 ) ;
V_54 &= ~ F_26 ;
V_54 |= ( V_65 << F_27 ) ;
F_15 ( V_4 , 0 , F_25 ,
4 , V_54 ) ;
F_14 ( V_4 , 0 , V_55 + V_66 ,
2 , & V_53 ) ;
if ( V_53 & V_67 )
V_57 = true ;
if ( ! V_57 ) {
#define F_28 0xf
#define F_29 0x2
#define F_30 0x1
F_14 ( V_4 , 0 ,
V_55 + V_68 , 4 ,
& V_52 ) ;
if ( ( V_52 & F_28 ) ==
F_29 ) {
V_52 &= ~ F_28 ;
V_52 |= F_30 ;
F_15 ( V_4 , 0 ,
V_55 + V_68 ,
4 , V_52 ) ;
F_22 ( 100 ) ;
F_14 ( V_4 , 0 ,
V_55 + V_66 ,
2 , & V_53 ) ;
if ( V_53 & V_67 )
V_57 = true ;
}
}
F_31 ( V_50 , L_3 , V_57 ? L_4 : L_5 ) ;
return V_57 ? 0 : - V_61 ;
}
static void F_32 ( struct V_1 * V_4 )
{
F_7 ( V_4 , V_69 , V_70 ) ;
}
static inline bool F_33 ( struct V_1 * V_4 ,
int V_71 )
{
T_2 V_16 ;
V_16 = F_5 ( V_4 , F_34 ( V_72 , V_71 ) ) ;
return ! ! ( V_16 & V_73 ) ;
}
static inline int F_35 ( struct V_1 * V_4 , int V_71 ,
int V_74 , T_4 V_75 , T_4 V_76 )
{
struct V_49 * V_50 = V_4 -> V_50 ;
T_1 V_77 , V_78 ;
V_77 = F_4 ( V_4 , F_34 ( V_72 ,
V_71 ) ) ;
V_78 = F_4 ( V_4 , F_34 ( V_79 ,
V_71 ) ) ;
if ( F_3 ( V_77 ) ||
F_3 ( V_78 ) )
return - V_80 ;
F_8 ( F_36 ( V_75 ) | ( V_74 << V_81 ) |
V_73 , V_4 -> V_15 + V_77 ) ;
F_8 ( F_37 ( V_75 ) , V_4 -> V_15 + V_77 + 4 ) ;
F_8 ( F_36 ( V_76 ) , V_4 -> V_15 + V_78 ) ;
F_8 ( F_37 ( V_76 ) , V_4 -> V_15 + V_78 + 4 ) ;
F_31 ( V_50 , L_6 ,
V_71 , V_77 , & V_75 , & V_76 ) ;
F_31 ( V_50 , L_7 ,
F_6 ( V_4 -> V_15 + V_77 ) ,
F_6 ( V_4 -> V_15 + V_77 + 4 ) ) ;
F_31 ( V_50 , L_8 ,
F_6 ( V_4 -> V_15 + V_78 ) ,
F_6 ( V_4 -> V_15 + V_78 + 4 ) ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_4 , T_4 V_75 ,
T_4 V_76 , T_5 V_38 )
{
struct V_82 * V_83 = & V_4 -> V_83 ;
struct V_49 * V_50 = V_4 -> V_50 ;
int V_44 = - V_80 , V_71 , V_74 ;
if ( V_75 < V_83 -> V_84 ) {
F_24 ( V_50 , L_9 ,
& V_75 , & V_83 -> V_84 ) ;
return - V_80 ;
}
V_75 -= V_83 -> V_84 ;
for ( V_71 = V_83 -> V_85 - 1 ; V_71 >= 0 ; V_71 -- ) {
const struct V_86 * V_87 =
& V_4 -> V_87 [ V_71 ] ;
if ( F_33 ( V_4 , V_71 ) )
continue;
for ( V_74 = V_87 -> V_88 - 1 ; V_74 >= 0 ;
V_74 -- ) {
T_5 V_89 =
V_87 -> V_90 [ V_74 ] * V_91 ;
if ( V_38 < V_89 )
continue;
if ( ! F_39 ( V_75 , V_89 ) ||
! F_39 ( V_76 , V_89 ) ) {
F_24 ( V_50 ,
L_10 ,
& V_75 , & V_76 ) ;
return - V_80 ;
}
V_44 = F_35 ( V_4 , V_71 , V_74 ,
V_75 , V_76 ) ;
if ( V_44 )
goto V_92;
V_38 -= V_89 ;
if ( V_38 == 0 )
return 0 ;
V_75 += V_89 ;
V_76 += V_89 ;
break;
}
}
V_92:
F_24 ( V_50 , L_11 ) ;
F_24 ( V_50 ,
L_12 ,
& V_75 , & V_83 -> V_84 , & V_76 , & V_38 ) ;
return V_44 ;
}
static int F_40 ( struct V_1 * V_4 ,
struct V_93 * V_94 )
{
struct V_49 * V_50 = V_4 -> V_50 ;
struct V_95 * V_96 ;
int V_44 ;
F_41 (window, resources) {
struct V_97 * V_98 = V_96 -> V_98 ;
T_4 V_99 = F_42 ( V_98 ) ;
switch ( V_99 ) {
case V_100 :
case V_101 :
break;
case V_102 :
V_44 = F_38 ( V_4 , V_98 -> V_103 ,
V_98 -> V_103 - V_96 -> V_14 ,
F_43 ( V_98 ) ) ;
if ( V_44 )
return V_44 ;
break;
default:
F_24 ( V_50 , L_13 , V_98 ) ;
return - V_80 ;
}
}
return 0 ;
}
static inline bool F_44 ( struct V_1 * V_4 ,
int V_104 )
{
const struct V_105 * V_106 = & V_4 -> V_106 [ V_104 ] ;
T_2 V_16 ;
V_16 = F_5 ( V_4 , F_34 ( V_107 , V_104 ) ) ;
return ! ! ( V_16 & ( F_45 ( V_106 -> V_88 ) - 1 ) ) ;
}
static inline bool F_46 ( const struct V_105 * V_106 ,
enum V_108 type )
{
return ! ! ( V_106 -> type == type ) ;
}
static int F_47 ( struct V_1 * V_4 , int V_104 ,
int V_74 , int V_85 , T_4 V_75 ,
T_4 V_76 , T_5 V_38 )
{
struct V_49 * V_50 = V_4 -> V_50 ;
const struct V_105 * V_106 = & V_4 -> V_106 [ V_104 ] ;
T_1 V_109 , V_110 ;
T_2 V_16 ;
int V_71 ;
V_109 = F_4 ( V_4 ,
F_34 ( V_107 , V_104 ) ) ;
V_110 = F_4 ( V_4 ,
F_34 ( V_111 , V_104 ) ) ;
if ( F_3 ( V_109 ) ||
F_3 ( V_110 ) )
return - V_80 ;
F_31 ( V_50 , L_14 ,
V_104 , V_109 , & V_75 , & V_76 ) ;
F_8 ( F_36 ( V_76 ) | F_45 ( V_74 ) ,
V_4 -> V_15 + V_109 ) ;
F_8 ( F_37 ( V_76 ) , V_4 -> V_15 + V_109 + 4 ) ;
F_31 ( V_50 , L_15 ,
F_6 ( V_4 -> V_15 + V_109 ) ,
F_6 ( V_4 -> V_15 + V_109 + 4 ) ) ;
V_38 >>= F_48 ( V_85 ) ;
for ( V_71 = 0 ; V_71 < V_85 ; V_71 ++ ) {
V_16 = F_6 ( V_4 -> V_15 + V_110 ) ;
V_16 |= F_36 ( V_75 ) | V_112 ;
F_8 ( V_16 , V_4 -> V_15 + V_110 ) ;
F_8 ( F_37 ( V_75 ) ,
V_4 -> V_15 + V_110 + V_106 -> V_113 ) ;
F_31 ( V_50 , L_16 ,
V_71 , F_6 ( V_4 -> V_15 + V_110 ) ,
F_6 ( V_4 -> V_15 + V_110 +
V_106 -> V_113 ) ) ;
V_110 += V_106 -> V_114 ;
V_75 += V_38 ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_4 ,
struct V_115 * V_116 ,
enum V_108 type )
{
struct V_49 * V_50 = V_4 -> V_50 ;
struct V_117 * V_118 = & V_4 -> V_118 ;
int V_44 ;
unsigned int V_104 , V_74 ;
T_4 V_75 = V_116 -> V_119 , V_76 = V_116 -> V_76 ;
T_5 V_38 = V_116 -> V_38 ;
for ( V_104 = 0 ; V_104 < V_118 -> V_120 ; V_104 ++ ) {
const struct V_105 * V_106 =
& V_4 -> V_106 [ V_104 ] ;
if ( F_44 ( V_4 , V_104 ) ||
! F_46 ( V_106 , type ) )
continue;
for ( V_74 = 0 ; V_74 < V_106 -> V_88 ; V_74 ++ ) {
T_5 V_121 =
V_106 -> V_122 [ V_74 ] * V_106 -> V_123 ;
if ( V_38 != V_121 )
continue;
if ( ! F_39 ( V_75 , V_121 ) ||
! F_39 ( V_76 , V_121 ) ) {
F_24 ( V_50 ,
L_10 ,
& V_75 , & V_76 ) ;
return - V_80 ;
}
V_44 = F_47 ( V_4 , V_104 , V_74 ,
V_106 -> V_85 , V_75 ,
V_76 , V_38 ) ;
if ( V_44 )
goto V_124;
else
return 0 ;
}
}
V_44 = - V_80 ;
V_124:
F_24 ( V_50 , L_17 ) ;
F_24 ( V_50 , L_18 ,
& V_75 , & V_76 , & V_38 ) ;
return V_44 ;
}
static int F_50 ( struct V_125 * V_126 ,
struct V_127 * V_128 )
{
const int V_129 = 3 , V_130 = 2 ;
int V_131 ;
V_126 -> V_128 = V_128 ;
V_126 -> V_132 = F_51 ( V_128 ) ;
V_126 -> V_133 = V_126 -> V_132 + V_129 + V_130 ;
V_126 -> V_116 = F_52 ( V_128 , L_19 , & V_131 ) ;
if ( ! V_126 -> V_116 )
return - V_134 ;
V_126 -> V_135 = V_126 -> V_116 + V_131 / sizeof( V_136 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_4 )
{
struct V_115 V_116 ;
struct V_125 V_126 ;
int V_44 ;
V_44 = F_50 ( & V_126 , V_4 -> V_50 -> V_137 ) ;
if ( V_44 )
return V_44 ;
F_54 (&parser, &range) {
V_44 = F_49 ( V_4 , & V_116 , V_138 ) ;
if ( V_44 )
return V_44 ;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_4 ,
struct V_127 * V_139 ,
T_4 * V_140 )
{
struct V_49 * V_50 = V_4 -> V_50 ;
int V_44 ;
struct V_97 V_98 ;
if ( ! F_56 ( V_139 , L_20 ) ) {
F_24 ( V_50 , L_21 ) ;
return - V_61 ;
}
V_44 = F_57 ( V_139 , 0 , & V_98 ) ;
if ( V_44 < 0 ) {
F_24 ( V_50 , L_22 ) ;
return V_44 ;
}
* V_140 = V_98 . V_103 + V_141 ;
return 0 ;
}
static int F_58 ( struct V_1 * V_4 , T_4 V_140 )
{
int V_44 ;
struct V_115 V_116 ;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_116 . V_38 = V_142 ;
V_116 . V_76 = V_116 . V_119 = V_140 & ~ ( V_116 . V_38 - 1 ) ;
V_44 = F_49 ( V_4 , & V_116 , V_143 ) ;
return V_44 ;
}
static void F_59 ( struct V_1 * V_4 , T_4 V_140 )
{
T_2 V_16 ;
F_7 ( V_4 , V_144 ,
( T_2 ) ( V_140 >> 13 ) ) ;
F_7 ( V_4 , V_145 , 0 ) ;
V_16 = F_5 ( V_4 , V_146 ) ;
V_16 |= V_147 ;
F_7 ( V_4 , V_146 , V_16 ) ;
V_140 >>= 2 ;
F_7 ( V_4 , V_148 ,
F_37 ( V_140 ) ) ;
F_7 ( V_4 , V_149 ,
F_36 ( V_140 ) ) ;
V_16 = F_5 ( V_4 , V_150 ) ;
V_16 |= V_151 ;
F_7 ( V_4 , V_150 , V_16 ) ;
}
static int F_60 ( struct V_1 * V_4 ,
struct V_127 * V_139 )
{
struct V_49 * V_50 = V_4 -> V_50 ;
int V_44 ;
T_4 V_140 ;
V_44 = F_55 ( V_4 , V_139 , & V_140 ) ;
if ( V_44 < 0 ) {
F_24 ( V_50 , L_23 ) ;
return V_44 ;
}
switch ( V_4 -> type ) {
case V_152 :
V_44 = F_58 ( V_4 , V_140 ) ;
if ( V_44 )
return V_44 ;
break;
case V_153 :
F_59 ( V_4 , V_140 ) ;
break;
default:
return - V_80 ;
}
return 0 ;
}
static int F_61 ( struct V_1 * V_4 )
{
struct V_127 * V_139 ;
int V_44 ;
V_139 = F_62 ( V_4 -> V_50 -> V_137 , L_24 , 0 ) ;
if ( ! V_139 ) {
const V_136 * V_154 = NULL ;
int V_155 ;
T_2 V_156 ;
V_154 = F_52 ( V_4 -> V_50 -> V_137 , L_25 , & V_155 ) ;
if ( ! V_154 )
return - V_61 ;
V_156 = F_63 ( V_154 + 1 ) ;
V_139 = F_64 ( V_156 ) ;
if ( ! V_139 )
return - V_61 ;
}
if ( V_4 -> V_157 ) {
V_44 = F_60 ( V_4 , V_139 ) ;
if ( V_44 )
return V_44 ;
}
return F_65 ( V_4 , V_139 ) ;
}
static void F_66 ( struct V_1 * V_4 )
{
F_67 ( V_4 ) ;
}
static int F_68 ( struct V_1 * V_4 )
{
struct V_49 * V_50 = V_4 -> V_50 ;
unsigned int V_158 ;
const T_1 * V_159 ;
switch ( V_4 -> type ) {
case V_160 :
V_159 = V_161 ;
break;
case V_162 :
V_159 = V_163 ;
V_4 -> V_19 = true ;
if ( V_4 -> V_164 ) {
V_4 -> V_87 = V_165 ;
V_4 -> V_83 . V_85 = F_69 ( V_165 ) ;
}
break;
case V_152 :
V_159 = V_166 ;
V_4 -> V_19 = true ;
if ( V_4 -> V_164 ) {
V_4 -> V_87 = V_167 ;
V_4 -> V_83 . V_85 = F_69 ( V_167 ) ;
}
V_4 -> V_118 . V_120 = F_69 ( V_168 ) ;
V_4 -> V_106 = V_168 ;
V_4 -> V_157 = true ;
break;
case V_169 :
V_159 = V_170 ;
V_4 -> V_30 = true ;
break;
case V_153 :
V_159 = V_171 ;
V_4 -> V_30 = true ;
V_4 -> V_157 = true ;
break;
default:
F_24 ( V_50 , L_26 ) ;
return - V_80 ;
}
V_4 -> V_13 = F_70 ( V_50 , V_172 ,
sizeof( * V_4 -> V_13 ) ,
V_173 ) ;
if ( ! V_4 -> V_13 )
return - V_174 ;
V_4 -> V_13 [ 0 ] = ( V_4 -> type == V_153 ) ?
V_10 : V_159 [ 0 ] ;
for ( V_158 = 1 ; V_158 < V_172 ; V_158 ++ )
V_4 -> V_13 [ V_158 ] = V_159 [ V_158 ] ?
V_159 [ V_158 ] : V_10 ;
return 0 ;
}
int F_71 ( struct V_1 * V_4 , struct V_93 * V_98 )
{
struct V_49 * V_50 ;
int V_44 ;
void * V_7 ;
struct V_2 * V_175 ;
struct V_176 * V_177 = F_72 ( V_4 ) ;
V_50 = V_4 -> V_50 ;
V_44 = F_68 ( V_4 ) ;
if ( V_44 ) {
F_24 ( V_50 , L_27 ) ;
return V_44 ;
}
V_44 = F_73 ( V_50 , V_98 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_74 ( V_4 -> V_178 ) ;
if ( V_44 ) {
F_24 ( V_50 , L_28 ) ;
return V_44 ;
}
V_44 = F_75 ( V_4 -> V_178 ) ;
if ( V_44 ) {
F_24 ( V_50 , L_29 ) ;
goto V_179;
}
F_20 ( V_4 ) ;
if ( V_4 -> V_164 ) {
V_44 = F_40 ( V_4 , V_98 ) ;
if ( V_44 ) {
F_24 ( V_50 , L_30 ) ;
goto V_180;
}
}
V_44 = F_53 ( V_4 ) ;
if ( V_44 && V_44 != - V_134 )
goto V_180;
#ifdef F_2
V_4 -> V_7 . V_8 = V_4 ;
V_7 = & V_4 -> V_7 ;
#else
V_7 = V_4 ;
#endif
V_44 = F_23 ( V_4 ) ;
if ( V_44 ) {
F_24 ( V_50 , L_31 ) ;
goto V_180;
}
F_32 ( V_4 ) ;
if ( F_76 ( V_181 ) )
if ( F_61 ( V_4 ) )
F_31 ( V_50 , L_32 ) ;
F_77 ( V_98 , & V_177 -> V_182 ) ;
V_177 -> V_183 = 0 ;
V_177 -> V_50 . V_184 = V_50 ;
V_177 -> V_185 = & V_186 ;
V_177 -> V_7 = V_7 ;
V_177 -> V_187 = V_4 -> V_187 ;
V_177 -> V_188 = V_189 ;
V_44 = F_78 ( V_177 ) ;
if ( V_44 < 0 ) {
F_24 ( V_50 , L_33 , V_44 ) ;
goto V_180;
}
F_79 ( V_177 -> V_3 ) ;
V_4 -> V_190 = V_177 -> V_3 ;
F_80 (child, &host->bus->children, node)
F_81 ( V_175 ) ;
F_82 ( V_177 -> V_3 ) ;
return 0 ;
V_180:
F_83 ( V_4 -> V_178 ) ;
V_179:
F_84 ( V_4 -> V_178 ) ;
return V_44 ;
}
int F_85 ( struct V_1 * V_4 )
{
F_86 ( V_4 -> V_190 ) ;
F_87 ( V_4 -> V_190 ) ;
F_66 ( V_4 ) ;
F_83 ( V_4 -> V_178 ) ;
F_84 ( V_4 -> V_178 ) ;
return 0 ;
}
