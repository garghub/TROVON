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
static void T_3 * F_10 ( struct V_2 * V_3 ,
unsigned int V_22 ,
int V_23 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned V_24 = F_11 ( V_22 ) ;
unsigned V_25 = F_12 ( V_22 ) ;
unsigned V_26 = V_3 -> V_18 ;
T_2 V_16 ;
T_1 V_14 ;
if ( V_26 == 0 ) {
if ( V_24 > 0 || V_25 > 0 )
return NULL ;
F_7 ( V_4 , V_27 ,
V_23 & V_28 ) ;
V_14 = F_4 ( V_4 , V_29 ) ;
if ( F_3 ( V_14 ) )
return NULL ;
else
return ( V_4 -> V_15 + V_14 ) ;
}
if ( V_4 -> V_30 )
if ( V_24 > 0 )
return NULL ;
V_16 = ( V_26 << V_31 ) |
( V_24 << V_32 ) |
( V_25 << V_33 ) |
( V_23 & V_34 ) |
( 1 & V_35 ) ;
F_7 ( V_4 , V_36 , V_16 ) ;
V_14 = F_4 ( V_4 , V_37 ) ;
if ( F_3 ( V_14 ) )
return NULL ;
else
return ( V_4 -> V_15 + V_14 ) ;
}
static int F_13 ( struct V_2 * V_3 , unsigned int V_22 ,
int V_23 , int V_38 , T_2 * V_16 )
{
int V_39 ;
F_9 ( V_3 , true ) ;
V_39 = F_14 ( V_3 , V_22 , V_23 , V_38 , V_16 ) ;
F_9 ( V_3 , false ) ;
return V_39 ;
}
static int F_15 ( struct V_2 * V_3 , unsigned int V_22 ,
int V_23 , int V_38 , T_2 V_16 )
{
int V_39 ;
F_9 ( V_3 , true ) ;
V_39 = F_16 ( V_3 , V_22 , V_23 , V_38 , V_16 ) ;
F_9 ( V_3 , false ) ;
return V_39 ;
}
static void F_17 ( struct V_1 * V_4 )
{
T_2 V_16 ;
if ( V_4 -> V_30 )
return;
V_16 = F_5 ( V_4 , V_40 ) ;
V_16 &= ~ V_41 & ~ V_42 &
~ V_43 ;
F_7 ( V_4 , V_40 , V_16 ) ;
F_18 ( 250 ) ;
V_16 |= V_43 ;
F_7 ( V_4 , V_40 , V_16 ) ;
F_19 ( 100 ) ;
}
static int F_20 ( struct V_1 * V_4 , struct V_2 * V_3 )
{
struct V_44 * V_45 = V_4 -> V_45 ;
T_4 V_46 ;
T_2 V_47 , V_48 , V_16 ;
T_1 V_49 = V_50 , V_51 ;
bool V_52 = false ;
if ( V_4 -> V_30 )
return 0 ;
V_16 = F_5 ( V_4 , V_53 ) ;
if ( ! ( V_16 & V_54 ) || ! ( V_16 & V_55 ) ) {
F_21 ( V_45 , L_1 ) ;
return - V_56 ;
}
F_22 ( V_3 , 0 , V_57 , & V_46 ) ;
if ( ( V_46 & 0x7f ) != V_58 ) {
F_21 ( V_45 , L_2 , V_46 ) ;
return - V_59 ;
}
#define F_23 0x43c
#define F_24 0xffff00
#define F_25 8
F_26 ( V_3 , 0 , F_23 , & V_48 ) ;
V_48 &= ~ F_24 ;
V_48 |= ( V_60 << F_25 ) ;
F_27 ( V_3 , 0 , F_23 , V_48 ) ;
F_28 ( V_3 , 0 , V_49 + V_61 , & V_51 ) ;
if ( V_51 & V_62 )
V_52 = true ;
if ( ! V_52 ) {
#define F_29 0xf
#define F_30 0x2
#define F_31 0x1
F_26 ( V_3 , 0 ,
V_49 + V_63 ,
& V_47 ) ;
if ( ( V_47 & F_29 ) ==
F_30 ) {
V_47 &= ~ F_29 ;
V_47 |= F_31 ;
F_27 ( V_3 , 0 ,
V_49 + V_63 ,
V_47 ) ;
F_19 ( 100 ) ;
F_28 ( V_3 , 0 , V_49 + V_61 ,
& V_51 ) ;
if ( V_51 & V_62 )
V_52 = true ;
}
}
F_32 ( V_45 , L_3 , V_52 ? L_4 : L_5 ) ;
return V_52 ? 0 : - V_56 ;
}
static void F_33 ( struct V_1 * V_4 )
{
F_7 ( V_4 , V_64 , V_65 ) ;
}
static inline bool F_34 ( struct V_1 * V_4 ,
int V_66 )
{
T_2 V_16 ;
V_16 = F_5 ( V_4 , F_35 ( V_67 , V_66 ) ) ;
return ! ! ( V_16 & V_68 ) ;
}
static inline int F_36 ( struct V_1 * V_4 , int V_66 ,
int V_69 , T_5 V_70 , T_5 V_71 )
{
struct V_44 * V_45 = V_4 -> V_45 ;
T_1 V_72 , V_73 ;
V_72 = F_4 ( V_4 , F_35 ( V_67 ,
V_66 ) ) ;
V_73 = F_4 ( V_4 , F_35 ( V_74 ,
V_66 ) ) ;
if ( F_3 ( V_72 ) ||
F_3 ( V_73 ) )
return - V_75 ;
F_8 ( F_37 ( V_70 ) | ( V_69 << V_76 ) |
V_68 , V_4 -> V_15 + V_72 ) ;
F_8 ( F_38 ( V_70 ) , V_4 -> V_15 + V_72 + 4 ) ;
F_8 ( F_37 ( V_71 ) , V_4 -> V_15 + V_73 ) ;
F_8 ( F_38 ( V_71 ) , V_4 -> V_15 + V_73 + 4 ) ;
F_32 ( V_45 , L_6 ,
V_66 , V_72 , & V_70 , & V_71 ) ;
F_32 ( V_45 , L_7 ,
F_6 ( V_4 -> V_15 + V_72 ) ,
F_6 ( V_4 -> V_15 + V_72 + 4 ) ) ;
F_32 ( V_45 , L_8 ,
F_6 ( V_4 -> V_15 + V_73 ) ,
F_6 ( V_4 -> V_15 + V_73 + 4 ) ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_4 , T_5 V_70 ,
T_5 V_71 , T_6 V_38 )
{
struct V_77 * V_78 = & V_4 -> V_78 ;
struct V_44 * V_45 = V_4 -> V_45 ;
int V_39 = - V_75 , V_66 , V_69 ;
if ( V_70 < V_78 -> V_79 ) {
F_21 ( V_45 , L_9 ,
& V_70 , & V_78 -> V_79 ) ;
return - V_75 ;
}
V_70 -= V_78 -> V_79 ;
for ( V_66 = V_78 -> V_80 - 1 ; V_66 >= 0 ; V_66 -- ) {
const struct V_81 * V_82 =
& V_4 -> V_82 [ V_66 ] ;
if ( F_34 ( V_4 , V_66 ) )
continue;
for ( V_69 = V_82 -> V_83 - 1 ; V_69 >= 0 ;
V_69 -- ) {
T_6 V_84 =
V_82 -> V_85 [ V_69 ] * V_86 ;
if ( V_38 < V_84 )
continue;
if ( ! F_40 ( V_70 , V_84 ) ||
! F_40 ( V_71 , V_84 ) ) {
F_21 ( V_45 ,
L_10 ,
& V_70 , & V_71 ) ;
return - V_75 ;
}
V_39 = F_36 ( V_4 , V_66 , V_69 ,
V_70 , V_71 ) ;
if ( V_39 )
goto V_87;
V_38 -= V_84 ;
if ( V_38 == 0 )
return 0 ;
V_70 += V_84 ;
V_71 += V_84 ;
break;
}
}
V_87:
F_21 ( V_45 , L_11 ) ;
F_21 ( V_45 ,
L_12 ,
& V_70 , & V_78 -> V_79 , & V_71 , & V_38 ) ;
return V_39 ;
}
static int F_41 ( struct V_1 * V_4 ,
struct V_88 * V_89 )
{
struct V_44 * V_45 = V_4 -> V_45 ;
struct V_90 * V_91 ;
int V_39 ;
F_42 (window, resources) {
struct V_92 * V_93 = V_91 -> V_93 ;
T_5 V_94 = F_43 ( V_93 ) ;
switch ( V_94 ) {
case V_95 :
case V_96 :
break;
case V_97 :
V_39 = F_39 ( V_4 , V_93 -> V_98 ,
V_93 -> V_98 - V_91 -> V_14 ,
F_44 ( V_93 ) ) ;
if ( V_39 )
return V_39 ;
break;
default:
F_21 ( V_45 , L_13 , V_93 ) ;
return - V_75 ;
}
}
return 0 ;
}
static inline bool F_45 ( struct V_1 * V_4 ,
int V_99 )
{
const struct V_100 * V_101 = & V_4 -> V_101 [ V_99 ] ;
T_2 V_16 ;
V_16 = F_5 ( V_4 , F_35 ( V_102 , V_99 ) ) ;
return ! ! ( V_16 & ( F_46 ( V_101 -> V_83 ) - 1 ) ) ;
}
static inline bool F_47 ( const struct V_100 * V_101 ,
enum V_103 type )
{
return ! ! ( V_101 -> type == type ) ;
}
static int F_48 ( struct V_1 * V_4 , int V_99 ,
int V_69 , int V_80 , T_5 V_70 ,
T_5 V_71 , T_6 V_38 )
{
struct V_44 * V_45 = V_4 -> V_45 ;
const struct V_100 * V_101 = & V_4 -> V_101 [ V_99 ] ;
T_1 V_104 , V_105 ;
T_2 V_16 ;
int V_66 ;
V_104 = F_4 ( V_4 ,
F_35 ( V_102 , V_99 ) ) ;
V_105 = F_4 ( V_4 ,
F_35 ( V_106 , V_99 ) ) ;
if ( F_3 ( V_104 ) ||
F_3 ( V_105 ) )
return - V_75 ;
F_32 ( V_45 , L_14 ,
V_99 , V_104 , & V_70 , & V_71 ) ;
F_8 ( F_37 ( V_71 ) | F_46 ( V_69 ) ,
V_4 -> V_15 + V_104 ) ;
F_8 ( F_38 ( V_71 ) , V_4 -> V_15 + V_104 + 4 ) ;
F_32 ( V_45 , L_15 ,
F_6 ( V_4 -> V_15 + V_104 ) ,
F_6 ( V_4 -> V_15 + V_104 + 4 ) ) ;
V_38 >>= F_49 ( V_80 ) ;
for ( V_66 = 0 ; V_66 < V_80 ; V_66 ++ ) {
V_16 = F_6 ( V_4 -> V_15 + V_105 ) ;
V_16 |= F_37 ( V_70 ) | V_107 ;
F_8 ( V_16 , V_4 -> V_15 + V_105 ) ;
F_8 ( F_38 ( V_70 ) ,
V_4 -> V_15 + V_105 + V_101 -> V_108 ) ;
F_32 ( V_45 , L_16 ,
V_66 , F_6 ( V_4 -> V_15 + V_105 ) ,
F_6 ( V_4 -> V_15 + V_105 +
V_101 -> V_108 ) ) ;
V_105 += V_101 -> V_109 ;
V_70 += V_38 ;
}
return 0 ;
}
static int F_50 ( struct V_1 * V_4 ,
struct V_110 * V_111 ,
enum V_103 type )
{
struct V_44 * V_45 = V_4 -> V_45 ;
struct V_112 * V_113 = & V_4 -> V_113 ;
int V_39 ;
unsigned int V_99 , V_69 ;
T_5 V_70 = V_111 -> V_114 , V_71 = V_111 -> V_71 ;
T_6 V_38 = V_111 -> V_38 ;
for ( V_99 = 0 ; V_99 < V_113 -> V_115 ; V_99 ++ ) {
const struct V_100 * V_101 =
& V_4 -> V_101 [ V_99 ] ;
if ( F_45 ( V_4 , V_99 ) ||
! F_47 ( V_101 , type ) )
continue;
for ( V_69 = 0 ; V_69 < V_101 -> V_83 ; V_69 ++ ) {
T_6 V_116 =
V_101 -> V_117 [ V_69 ] * V_101 -> V_118 ;
if ( V_38 != V_116 )
continue;
if ( ! F_40 ( V_70 , V_116 ) ||
! F_40 ( V_71 , V_116 ) ) {
F_21 ( V_45 ,
L_10 ,
& V_70 , & V_71 ) ;
return - V_75 ;
}
V_39 = F_48 ( V_4 , V_99 , V_69 ,
V_101 -> V_80 , V_70 ,
V_71 , V_38 ) ;
if ( V_39 )
goto V_119;
else
return 0 ;
}
}
V_39 = - V_75 ;
V_119:
F_21 ( V_45 , L_17 ) ;
F_21 ( V_45 , L_18 ,
& V_70 , & V_71 , & V_38 ) ;
return V_39 ;
}
static int F_51 ( struct V_120 * V_121 ,
struct V_122 * V_123 )
{
const int V_124 = 3 , V_125 = 2 ;
int V_126 ;
V_121 -> V_123 = V_123 ;
V_121 -> V_127 = F_52 ( V_123 ) ;
V_121 -> V_128 = V_121 -> V_127 + V_124 + V_125 ;
V_121 -> V_111 = F_53 ( V_123 , L_19 , & V_126 ) ;
if ( ! V_121 -> V_111 )
return - V_129 ;
V_121 -> V_130 = V_121 -> V_111 + V_126 / sizeof( V_131 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_4 )
{
struct V_110 V_111 ;
struct V_120 V_121 ;
int V_39 ;
V_39 = F_51 ( & V_121 , V_4 -> V_45 -> V_132 ) ;
if ( V_39 )
return V_39 ;
F_55 (&parser, &range) {
V_39 = F_50 ( V_4 , & V_111 , V_133 ) ;
if ( V_39 )
return V_39 ;
}
return 0 ;
}
static int F_56 ( struct V_1 * V_4 ,
struct V_122 * V_134 ,
T_5 * V_135 )
{
struct V_44 * V_45 = V_4 -> V_45 ;
int V_39 ;
struct V_92 V_93 ;
if ( ! F_57 ( V_134 , L_20 ) ) {
F_21 ( V_45 , L_21 ) ;
return - V_56 ;
}
V_39 = F_58 ( V_134 , 0 , & V_93 ) ;
if ( V_39 < 0 ) {
F_21 ( V_45 , L_22 ) ;
return V_39 ;
}
* V_135 = V_93 . V_98 + V_136 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_4 , T_5 V_135 )
{
int V_39 ;
struct V_110 V_111 ;
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
V_111 . V_38 = V_137 ;
V_111 . V_71 = V_111 . V_114 = V_135 & ~ ( V_111 . V_38 - 1 ) ;
V_39 = F_50 ( V_4 , & V_111 , V_138 ) ;
return V_39 ;
}
static void F_60 ( struct V_1 * V_4 , T_5 V_135 )
{
T_2 V_16 ;
F_7 ( V_4 , V_139 ,
( T_2 ) ( V_135 >> 13 ) ) ;
F_7 ( V_4 , V_140 , 0 ) ;
V_16 = F_5 ( V_4 , V_141 ) ;
V_16 |= V_142 ;
F_7 ( V_4 , V_141 , V_16 ) ;
V_135 >>= 2 ;
F_7 ( V_4 , V_143 ,
F_38 ( V_135 ) ) ;
F_7 ( V_4 , V_144 ,
F_37 ( V_135 ) ) ;
V_16 = F_5 ( V_4 , V_145 ) ;
V_16 |= V_146 ;
F_7 ( V_4 , V_145 , V_16 ) ;
}
static int F_61 ( struct V_1 * V_4 ,
struct V_122 * V_134 )
{
struct V_44 * V_45 = V_4 -> V_45 ;
int V_39 ;
T_5 V_135 ;
V_39 = F_56 ( V_4 , V_134 , & V_135 ) ;
if ( V_39 < 0 ) {
F_21 ( V_45 , L_23 ) ;
return V_39 ;
}
switch ( V_4 -> type ) {
case V_147 :
V_39 = F_59 ( V_4 , V_135 ) ;
if ( V_39 )
return V_39 ;
break;
case V_148 :
F_60 ( V_4 , V_135 ) ;
break;
default:
return - V_75 ;
}
return 0 ;
}
static int F_62 ( struct V_1 * V_4 )
{
struct V_122 * V_134 ;
int V_39 ;
V_134 = F_63 ( V_4 -> V_45 -> V_132 , L_24 , 0 ) ;
if ( ! V_134 ) {
const V_131 * V_149 = NULL ;
int V_150 ;
T_2 V_151 ;
V_149 = F_53 ( V_4 -> V_45 -> V_132 , L_25 , & V_150 ) ;
if ( ! V_149 )
return - V_56 ;
V_151 = F_64 ( V_149 + 1 ) ;
V_134 = F_65 ( V_151 ) ;
if ( ! V_134 )
return - V_56 ;
}
if ( V_4 -> V_152 ) {
V_39 = F_61 ( V_4 , V_134 ) ;
if ( V_39 )
return V_39 ;
}
return F_66 ( V_4 , V_134 ) ;
}
static void F_67 ( struct V_1 * V_4 )
{
F_68 ( V_4 ) ;
}
static int F_69 ( struct V_1 * V_4 )
{
struct V_44 * V_45 = V_4 -> V_45 ;
unsigned int V_153 ;
const T_1 * V_154 ;
switch ( V_4 -> type ) {
case V_155 :
V_154 = V_156 ;
break;
case V_157 :
V_154 = V_158 ;
V_4 -> V_19 = true ;
if ( V_4 -> V_159 ) {
V_4 -> V_82 = V_160 ;
V_4 -> V_78 . V_80 = F_70 ( V_160 ) ;
}
break;
case V_147 :
V_154 = V_161 ;
V_4 -> V_19 = true ;
if ( V_4 -> V_159 ) {
V_4 -> V_82 = V_162 ;
V_4 -> V_78 . V_80 = F_70 ( V_162 ) ;
}
V_4 -> V_113 . V_115 = F_70 ( V_163 ) ;
V_4 -> V_101 = V_163 ;
V_4 -> V_152 = true ;
break;
case V_164 :
V_154 = V_165 ;
V_4 -> V_30 = true ;
break;
case V_148 :
V_154 = V_166 ;
V_4 -> V_30 = true ;
V_4 -> V_152 = true ;
break;
default:
F_21 ( V_45 , L_26 ) ;
return - V_75 ;
}
V_4 -> V_13 = F_71 ( V_45 , V_167 ,
sizeof( * V_4 -> V_13 ) ,
V_168 ) ;
if ( ! V_4 -> V_13 )
return - V_169 ;
V_4 -> V_13 [ 0 ] = ( V_4 -> type == V_148 ) ?
V_10 : V_154 [ 0 ] ;
for ( V_153 = 1 ; V_153 < V_167 ; V_153 ++ )
V_4 -> V_13 [ V_153 ] = V_154 [ V_153 ] ?
V_154 [ V_153 ] : V_10 ;
return 0 ;
}
int F_72 ( struct V_1 * V_4 , struct V_88 * V_93 )
{
struct V_44 * V_45 ;
int V_39 ;
void * V_7 ;
struct V_2 * V_3 , * V_170 ;
V_45 = V_4 -> V_45 ;
V_39 = F_69 ( V_4 ) ;
if ( V_39 ) {
F_21 ( V_45 , L_27 ) ;
return V_39 ;
}
V_39 = F_73 ( V_45 , V_93 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_74 ( V_4 -> V_171 ) ;
if ( V_39 ) {
F_21 ( V_45 , L_28 ) ;
return V_39 ;
}
V_39 = F_75 ( V_4 -> V_171 ) ;
if ( V_39 ) {
F_21 ( V_45 , L_29 ) ;
goto V_172;
}
F_17 ( V_4 ) ;
if ( V_4 -> V_159 ) {
V_39 = F_41 ( V_4 , V_93 ) ;
if ( V_39 ) {
F_21 ( V_45 , L_30 ) ;
goto V_173;
}
}
V_39 = F_54 ( V_4 ) ;
if ( V_39 && V_39 != - V_129 )
goto V_173;
#ifdef F_2
V_4 -> V_7 . V_8 = V_4 ;
V_7 = & V_4 -> V_7 ;
#else
V_7 = V_4 ;
#endif
V_3 = F_76 ( V_45 , 0 , & V_174 , V_7 , V_93 ) ;
if ( ! V_3 ) {
F_21 ( V_45 , L_31 ) ;
V_39 = - V_169 ;
goto V_173;
}
V_4 -> V_175 = V_3 ;
V_39 = F_20 ( V_4 , V_3 ) ;
if ( V_39 ) {
F_21 ( V_45 , L_32 ) ;
goto V_176;
}
F_33 ( V_4 ) ;
if ( F_77 ( V_177 ) )
if ( F_62 ( V_4 ) )
F_32 ( V_45 , L_33 ) ;
F_78 ( V_3 ) ;
F_79 ( V_3 ) ;
if ( V_4 -> V_178 )
F_80 ( V_179 , V_4 -> V_178 ) ;
F_81 (child, &bus->children, node)
F_82 ( V_170 ) ;
F_83 ( V_3 ) ;
return 0 ;
V_176:
F_84 ( V_3 ) ;
F_85 ( V_3 ) ;
V_173:
F_86 ( V_4 -> V_171 ) ;
V_172:
F_87 ( V_4 -> V_171 ) ;
return V_39 ;
}
int F_88 ( struct V_1 * V_4 )
{
F_84 ( V_4 -> V_175 ) ;
F_85 ( V_4 -> V_175 ) ;
F_67 ( V_4 ) ;
F_86 ( V_4 -> V_171 ) ;
F_87 ( V_4 -> V_171 ) ;
return 0 ;
}
