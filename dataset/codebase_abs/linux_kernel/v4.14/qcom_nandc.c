static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_2 -> V_5 , V_4 ) ;
}
static struct V_3 *
F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_6 ;
unsigned int V_7 = V_2 -> V_8 ;
void * V_9 ;
V_6 =
sizeof( * V_4 ) + V_7 *
( ( sizeof( * V_4 -> V_10 ) * V_11 ) +
( sizeof( * V_4 -> V_12 ) * V_13 ) ) ;
V_9 = F_4 ( V_2 -> V_5 , V_6 , V_14 ) ;
if ( ! V_9 )
return NULL ;
V_4 = V_9 ;
V_9 += sizeof( * V_4 ) ;
V_4 -> V_10 = V_9 ;
V_9 +=
sizeof( * V_4 -> V_10 ) * V_11 * V_7 ;
V_4 -> V_12 = V_9 ;
return V_4 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! V_2 -> V_15 -> V_16 )
return;
V_4 -> V_17 = 0 ;
V_4 -> V_18 = 0 ;
V_4 -> V_19 = 0 ;
V_4 -> V_20 = 0 ;
V_4 -> V_21 = 0 ;
V_4 -> V_22 = 0 ;
F_6 ( V_4 -> V_10 , V_2 -> V_8 *
V_11 ) ;
F_6 ( V_4 -> V_12 , V_2 -> V_8 *
V_13 ) ;
}
static inline struct V_23 * F_7 ( struct V_24 * V_25 )
{
return F_8 ( V_25 , struct V_23 , V_25 ) ;
}
static inline struct V_1 *
F_9 ( struct V_24 * V_25 )
{
return F_8 ( V_25 -> V_26 , struct V_1 ,
V_26 ) ;
}
static inline T_2 F_10 ( struct V_1 * V_2 , int V_27 )
{
return F_11 ( V_2 -> V_28 + V_27 ) ;
}
static inline void F_12 ( struct V_1 * V_2 , int V_27 ,
T_2 V_29 )
{
F_13 ( V_29 , V_2 -> V_28 + V_27 ) ;
}
static inline void F_14 ( struct V_1 * V_2 ,
bool V_30 )
{
if ( ! V_2 -> V_15 -> V_16 )
return;
if ( V_30 )
F_15 ( V_2 -> V_5 , V_2 -> V_31 ,
V_32 *
sizeof( * V_2 -> V_33 ) ,
V_34 ) ;
else
F_16 ( V_2 -> V_5 , V_2 -> V_31 ,
V_32 *
sizeof( * V_2 -> V_33 ) ,
V_34 ) ;
}
static T_3 * F_17 ( struct V_35 * V_36 , int V_27 )
{
switch ( V_27 ) {
case V_37 :
return & V_36 -> V_38 ;
case V_39 :
return & V_36 -> V_40 ;
case V_41 :
return & V_36 -> V_42 ;
case V_43 :
return & V_36 -> V_44 ;
case V_45 :
return & V_36 -> V_46 ;
case V_47 :
return & V_36 -> V_48 ;
case V_49 :
return & V_36 -> V_50 ;
case V_51 :
return & V_36 -> V_52 ;
case V_53 :
return & V_36 -> V_54 ;
case V_55 :
return & V_36 -> V_56 ;
case V_57 :
return & V_36 -> V_58 ;
case V_59 :
return & V_36 -> V_60 ;
case V_61 :
return & V_36 -> V_62 ;
case V_63 :
return & V_36 -> V_64 ;
case V_65 :
return & V_36 -> V_66 ;
case V_67 :
return & V_36 -> V_68 ;
case V_69 :
return & V_36 -> V_70 ;
case V_71 :
return & V_36 -> V_72 ;
case V_73 :
return & V_36 -> V_74 ;
default:
return NULL ;
}
}
static void F_18 ( struct V_1 * V_2 , int V_27 ,
T_2 V_29 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
T_3 * V_75 ;
V_75 = F_17 ( V_36 , V_27 ) ;
if ( V_75 )
* V_75 = F_19 ( V_29 ) ;
}
static void F_20 ( struct V_23 * V_76 , T_4 V_77 , int V_78 )
{
struct V_24 * V_25 = & V_76 -> V_25 ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
if ( V_25 -> V_79 & V_80 )
V_77 >>= 1 ;
F_18 ( V_2 , V_39 , V_78 << 16 | V_77 ) ;
F_18 ( V_2 , V_41 , V_78 >> 16 & 0xff ) ;
}
static void F_21 ( struct V_23 * V_76 , int V_7 , bool V_81 )
{
struct V_24 * V_25 = & V_76 -> V_25 ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
T_2 V_38 , V_50 , V_52 , V_54 ;
if ( V_81 ) {
if ( V_76 -> V_82 )
V_38 = V_83 | V_84 | V_85 ;
else
V_38 = V_86 | V_84 | V_85 ;
} else {
V_38 = V_87 | V_84 | V_85 ;
}
if ( V_76 -> V_82 ) {
V_50 = ( V_76 -> V_50 & ~ ( 7U << V_88 ) ) |
( V_7 - 1 ) << V_88 ;
V_52 = V_76 -> V_52 ;
V_54 = V_76 -> V_54 ;
} else {
V_50 = ( V_76 -> V_89 & ~ ( 7U << V_88 ) ) |
( V_7 - 1 ) << V_88 ;
V_52 = V_76 -> V_90 ;
V_54 = 1 << V_91 ;
}
F_18 ( V_2 , V_37 , V_38 ) ;
F_18 ( V_2 , V_49 , V_50 ) ;
F_18 ( V_2 , V_51 , V_52 ) ;
F_18 ( V_2 , V_53 , V_54 ) ;
F_18 ( V_2 , V_65 , V_76 -> V_66 ) ;
F_18 ( V_2 , V_47 , V_76 -> V_48 ) ;
F_18 ( V_2 , V_55 , V_76 -> V_56 ) ;
F_18 ( V_2 , V_45 , 1 ) ;
if ( V_81 )
F_22 ( V_2 , 0 , 0 , V_76 -> V_82 ?
V_76 -> V_92 : V_76 -> V_93 , 1 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_94 * V_95 ,
unsigned long V_96 )
{
struct V_97 * V_98 ;
struct V_99 * V_100 ;
unsigned int V_101 ;
int V_102 ;
struct V_3 * V_4 = V_2 -> V_4 ;
enum V_103 V_104 ;
struct V_105 * V_106 ;
V_98 = F_24 ( sizeof( * V_98 ) , V_14 ) ;
if ( ! V_98 )
return - V_107 ;
if ( V_95 == V_2 -> V_108 ) {
V_100 = & V_4 -> V_10 [ V_4 -> V_18 ] ;
V_101 = V_4 -> V_17 - V_4 -> V_18 ;
V_4 -> V_18 = V_4 -> V_17 ;
V_104 = V_109 ;
V_98 -> V_110 = V_111 ;
} else if ( V_95 == V_2 -> V_112 ) {
V_100 = & V_4 -> V_12 [ V_4 -> V_20 ] ;
V_101 = V_4 -> V_19 - V_4 -> V_20 ;
V_4 -> V_20 = V_4 -> V_19 ;
V_104 = V_109 ;
V_98 -> V_110 = V_111 ;
} else {
V_100 = & V_4 -> V_12 [ V_4 -> V_22 ] ;
V_101 = V_4 -> V_21 - V_4 -> V_22 ;
V_4 -> V_22 = V_4 -> V_21 ;
V_104 = V_113 ;
V_98 -> V_110 = V_34 ;
}
F_25 ( V_100 + V_101 - 1 ) ;
V_102 = F_26 ( V_2 -> V_5 , V_100 , V_101 , V_98 -> V_110 ) ;
if ( V_102 == 0 ) {
F_27 ( V_2 -> V_5 , L_1 ) ;
F_28 ( V_98 ) ;
return - V_107 ;
}
V_98 -> V_101 = V_101 ;
V_98 -> V_114 = V_100 ;
V_106 = F_29 ( V_95 , V_100 , V_101 , V_104 ,
V_96 ) ;
if ( ! V_106 ) {
F_27 ( V_2 -> V_5 , L_2 ) ;
F_30 ( V_2 -> V_5 , V_100 , V_101 , V_98 -> V_110 ) ;
F_28 ( V_98 ) ;
return - V_115 ;
}
V_98 -> V_106 = V_106 ;
F_31 ( & V_98 -> V_116 , & V_2 -> V_117 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , bool V_81 ,
const void * V_118 ,
int V_119 , unsigned int V_96 )
{
int V_102 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_81 ) {
F_33 ( & V_4 -> V_12 [ V_4 -> V_21 ] ,
V_118 , V_119 ) ;
V_4 -> V_21 ++ ;
} else {
F_33 ( & V_4 -> V_12 [ V_4 -> V_19 ] ,
V_118 , V_119 ) ;
V_4 -> V_19 ++ ;
if ( ! ( V_96 & V_120 ) ) {
V_102 = F_23 ( V_2 , V_2 -> V_112 ,
V_121 ) ;
if ( V_102 )
return V_102 ;
}
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , bool V_81 ,
int V_122 , const void * V_118 , int V_119 ,
bool V_123 )
{
struct V_97 * V_98 ;
struct V_105 * V_106 ;
struct V_99 * V_100 ;
struct V_124 V_125 ;
enum V_103 V_104 ;
int V_102 ;
V_98 = F_24 ( sizeof( * V_98 ) , V_14 ) ;
if ( ! V_98 )
return - V_107 ;
V_100 = & V_98 -> V_126 ;
F_35 ( V_100 , V_118 , V_119 ) ;
if ( V_81 ) {
V_104 = V_113 ;
V_98 -> V_110 = V_34 ;
} else {
V_104 = V_109 ;
V_98 -> V_110 = V_111 ;
}
V_102 = F_26 ( V_2 -> V_5 , V_100 , 1 , V_98 -> V_110 ) ;
if ( V_102 == 0 ) {
V_102 = - V_107 ;
goto V_127;
}
memset ( & V_125 , 0x00 , sizeof( V_125 ) ) ;
V_125 . V_128 = V_123 ;
if ( V_81 ) {
V_125 . V_129 = 16 ;
V_125 . V_130 = V_2 -> V_131 + V_122 ;
V_125 . V_132 = V_2 -> V_133 ;
} else {
V_125 . V_134 = 16 ;
V_125 . V_135 = V_2 -> V_131 + V_122 ;
V_125 . V_132 = V_2 -> V_136 ;
}
V_102 = F_36 ( V_2 -> V_95 , & V_125 ) ;
if ( V_102 ) {
F_27 ( V_2 -> V_5 , L_3 ) ;
goto V_127;
}
V_106 = F_29 ( V_2 -> V_95 , V_100 , 1 , V_104 , 0 ) ;
if ( ! V_106 ) {
F_27 ( V_2 -> V_5 , L_4 ) ;
V_102 = - V_115 ;
goto V_127;
}
V_98 -> V_106 = V_106 ;
F_31 ( & V_98 -> V_116 , & V_2 -> V_117 ) ;
return 0 ;
V_127:
F_28 ( V_98 ) ;
return V_102 ;
}
static int F_37 ( struct V_1 * V_2 , int V_137 ,
int V_138 , unsigned int V_96 )
{
bool V_123 = false ;
void * V_118 ;
int V_119 ;
if ( V_137 == V_139 || V_137 == V_47 )
V_123 = true ;
if ( V_137 == V_61 || V_137 == V_57 )
V_137 = F_38 ( V_2 , V_137 ) ;
V_119 = V_138 * sizeof( T_2 ) ;
V_118 = V_2 -> V_33 + V_2 -> V_140 ;
V_2 -> V_140 += V_138 ;
return F_34 ( V_2 , true , V_137 , V_118 , V_119 , V_123 ) ;
}
static int F_39 ( struct V_1 * V_2 , int V_137 ,
int V_138 , unsigned int V_96 )
{
bool V_123 = false ;
struct V_35 * V_36 = V_2 -> V_36 ;
void * V_118 ;
int V_119 ;
V_118 = F_17 ( V_36 , V_137 ) ;
if ( V_137 == V_37 )
V_123 = true ;
if ( V_137 == V_141 ) {
if ( V_96 & V_142 )
V_118 = & V_36 -> V_143 ;
else
V_118 = & V_36 -> V_144 ;
}
if ( V_137 == V_45 )
V_96 |= V_145 ;
if ( V_137 == V_59 || V_137 == V_57 )
V_137 = F_38 ( V_2 , V_57 ) ;
if ( V_137 == V_63 || V_137 == V_61 )
V_137 = F_38 ( V_2 , V_61 ) ;
V_119 = V_138 * sizeof( T_2 ) ;
return F_34 ( V_2 , false , V_137 , V_118 , V_119 ,
V_123 ) ;
}
static int F_40 ( struct V_1 * V_2 , int V_122 ,
const T_5 * V_118 , int V_119 , unsigned int V_96 )
{
if ( V_2 -> V_15 -> V_16 )
return F_32 ( V_2 , true , V_118 , V_119 , V_96 ) ;
return F_34 ( V_2 , true , V_122 , V_118 , V_119 , false ) ;
}
static int F_41 ( struct V_1 * V_2 , int V_122 ,
const T_5 * V_118 , int V_119 , unsigned int V_96 )
{
if ( V_2 -> V_15 -> V_16 )
return F_32 ( V_2 , false , V_118 , V_119 , V_96 ) ;
return F_34 ( V_2 , false , V_122 , V_118 , V_119 , false ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_39 ( V_2 , V_39 , 2 , 0 ) ;
F_39 ( V_2 , V_49 , 3 , 0 ) ;
F_39 ( V_2 , V_65 , 1 , 0 ) ;
F_39 ( V_2 , V_141 , 1 , 0 ) ;
F_39 ( V_2 , V_141 , 1 ,
V_142 | V_146 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
if ( V_2 -> V_15 -> V_16 )
F_39 ( V_2 , V_67 , 4 ,
V_146 ) ;
F_39 ( V_2 , V_37 , 1 , V_146 ) ;
F_39 ( V_2 , V_45 , 1 , V_146 ) ;
F_37 ( V_2 , V_47 , 2 , 0 ) ;
F_37 ( V_2 , V_147 , 1 ,
V_146 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_39 ( V_2 , V_39 , 2 , 0 ) ;
F_39 ( V_2 , V_49 , 3 , 0 ) ;
F_39 ( V_2 , V_65 , 1 ,
V_146 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_39 ( V_2 , V_37 , 1 , V_146 ) ;
F_39 ( V_2 , V_45 , 1 , V_146 ) ;
F_37 ( V_2 , V_47 , 1 , V_146 ) ;
F_39 ( V_2 , V_47 , 1 , 0 ) ;
F_39 ( V_2 , V_55 , 1 , V_146 ) ;
}
static int F_47 ( struct V_23 * V_76 )
{
struct V_24 * V_25 = & V_76 -> V_25 ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
F_18 ( V_2 , V_37 , V_86 | V_84 | V_85 ) ;
F_18 ( V_2 , V_39 , 0 ) ;
F_18 ( V_2 , V_41 , 0 ) ;
F_18 ( V_2 , V_49 , 0 << V_88
| 512 << V_148
| 5 << V_149
| 0 << V_150 ) ;
F_18 ( V_2 , V_51 , 7 << V_151
| 0 << V_152
| 17 << V_153
| 1 << V_154
| 2 << V_155
| 0 << V_156
| 1 << V_157 ) ;
F_18 ( V_2 , V_65 , 1 << V_91 ) ;
F_18 ( V_2 , V_61 ,
( V_2 -> V_62 & ~ V_158 ) ) ;
F_18 ( V_2 , V_57 ,
( V_2 -> V_58 & ~ ( 0xFF << V_159 ) )
| V_160 << V_159 ) ;
F_18 ( V_2 , V_45 , 1 ) ;
F_18 ( V_2 , V_59 , V_2 -> V_58 ) ;
F_18 ( V_2 , V_63 , V_2 -> V_62 ) ;
F_22 ( V_2 , 0 , 0 , 512 , 1 ) ;
F_39 ( V_2 , V_61 , 1 , 0 ) ;
F_39 ( V_2 , V_57 , 1 , V_146 ) ;
V_2 -> V_161 = 512 ;
memset ( V_2 -> V_162 , 0xff , V_2 -> V_161 ) ;
F_44 ( V_2 ) ;
F_40 ( V_2 , V_163 , V_2 -> V_162 ,
V_2 -> V_161 , 0 ) ;
F_39 ( V_2 , V_59 , 1 , 0 ) ;
F_39 ( V_2 , V_63 , 1 , V_146 ) ;
return 0 ;
}
static int F_48 ( struct V_23 * V_76 , int V_164 )
{
struct V_24 * V_25 = & V_76 -> V_25 ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
F_18 ( V_2 , V_37 ,
V_165 | V_84 | V_85 ) ;
F_18 ( V_2 , V_39 , V_164 ) ;
F_18 ( V_2 , V_41 , 0 ) ;
F_18 ( V_2 , V_49 ,
V_76 -> V_89 & ~ ( 7 << V_88 ) ) ;
F_18 ( V_2 , V_51 , V_76 -> V_90 ) ;
F_18 ( V_2 , V_45 , 1 ) ;
F_18 ( V_2 , V_47 , V_76 -> V_48 ) ;
F_18 ( V_2 , V_55 , V_76 -> V_56 ) ;
F_39 ( V_2 , V_37 , 3 , V_146 ) ;
F_39 ( V_2 , V_49 , 2 , V_146 ) ;
F_39 ( V_2 , V_45 , 1 , V_146 ) ;
F_37 ( V_2 , V_47 , 1 , V_146 ) ;
F_39 ( V_2 , V_47 , 1 , 0 ) ;
F_39 ( V_2 , V_55 , 1 , V_146 ) ;
return 0 ;
}
static int F_49 ( struct V_23 * V_76 , int V_77 )
{
struct V_24 * V_25 = & V_76 -> V_25 ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
if ( V_77 == - 1 )
return 0 ;
F_18 ( V_2 , V_37 , V_166 ) ;
F_18 ( V_2 , V_39 , V_77 ) ;
F_18 ( V_2 , V_41 , 0 ) ;
F_18 ( V_2 , V_43 ,
V_2 -> V_15 -> V_16 ? 0 : V_167 ) ;
F_18 ( V_2 , V_45 , 1 ) ;
F_39 ( V_2 , V_37 , 4 , V_146 ) ;
F_39 ( V_2 , V_45 , 1 , V_146 ) ;
F_37 ( V_2 , V_139 , 1 , V_146 ) ;
return 0 ;
}
static int F_50 ( struct V_23 * V_76 )
{
struct V_24 * V_25 = & V_76 -> V_25 ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
F_18 ( V_2 , V_37 , V_168 ) ;
F_18 ( V_2 , V_45 , 1 ) ;
F_39 ( V_2 , V_37 , 1 , V_146 ) ;
F_39 ( V_2 , V_45 , 1 , V_146 ) ;
F_37 ( V_2 , V_47 , 1 , V_146 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_97 * V_98 ;
T_6 V_169 = 0 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_170 ;
if ( V_2 -> V_15 -> V_16 ) {
if ( V_4 -> V_21 > V_4 -> V_22 ) {
V_170 = F_23 ( V_2 , V_2 -> V_171 , 0 ) ;
if ( V_170 )
return V_170 ;
}
if ( V_4 -> V_19 > V_4 -> V_20 ) {
V_170 = F_23 ( V_2 , V_2 -> V_112 ,
V_121 ) ;
if ( V_170 )
return V_170 ;
}
if ( V_4 -> V_17 > V_4 -> V_18 ) {
V_170 = F_23 ( V_2 , V_2 -> V_108 , 0 ) ;
if ( V_170 )
return V_170 ;
}
}
F_52 (desc, &nandc->desc_list, node)
V_169 = F_53 ( V_98 -> V_106 ) ;
if ( V_2 -> V_15 -> V_16 ) {
F_54 ( V_2 -> V_112 ) ;
F_54 ( V_2 -> V_171 ) ;
if ( F_55 ( V_2 -> V_108 , V_169 ) != V_172 )
return - V_173 ;
} else {
if ( F_55 ( V_2 -> V_95 , V_169 ) != V_172 )
return - V_173 ;
}
return 0 ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_97 * V_98 , * V_174 ;
F_57 (desc, n, &nandc->desc_list, node) {
F_58 ( & V_98 -> V_116 ) ;
if ( V_2 -> V_15 -> V_16 )
F_30 ( V_2 -> V_5 , V_98 -> V_114 ,
V_98 -> V_101 , V_98 -> V_110 ) ;
else
F_30 ( V_2 -> V_5 , & V_98 -> V_126 , 1 ,
V_98 -> V_110 ) ;
F_28 ( V_98 ) ;
}
}
static void F_59 ( struct V_1 * V_2 )
{
V_2 -> V_140 = 0 ;
F_14 ( V_2 , false ) ;
}
static void F_60 ( struct V_23 * V_76 , int V_175 )
{
struct V_24 * V_25 = & V_76 -> V_25 ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
V_2 -> V_161 = 0 ;
V_2 -> V_176 = 0 ;
V_76 -> V_82 = false ;
V_76 -> V_177 = V_175 ;
F_59 ( V_2 ) ;
if ( V_175 == V_178 || V_175 == V_179 ||
V_175 == V_160 || V_175 == V_180 )
F_5 ( V_2 ) ;
}
static void F_61 ( struct V_23 * V_76 , int V_175 )
{
struct V_24 * V_25 = & V_76 -> V_25 ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
struct V_181 * V_182 = & V_25 -> V_182 ;
int V_7 ;
int V_183 ;
V_7 = V_175 == V_184 ? V_182 -> V_185 : 1 ;
F_14 ( V_2 , true ) ;
for ( V_183 = 0 ; V_183 < V_7 ; V_183 ++ ) {
T_2 V_186 = F_62 ( V_2 -> V_33 [ V_183 ] ) ;
if ( V_186 & V_187 )
V_76 -> V_188 &= ~ V_189 ;
if ( V_186 & V_190 || ( V_183 == ( V_7 - 1 ) &&
( V_186 &
V_191 ) ) )
V_76 -> V_188 |= V_192 ;
}
}
static void F_63 ( struct V_23 * V_76 , int V_175 )
{
struct V_24 * V_25 = & V_76 -> V_25 ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
switch ( V_175 ) {
case V_179 :
F_14 ( V_2 , true ) ;
memcpy ( V_2 -> V_162 , V_2 -> V_33 ,
V_2 -> V_161 ) ;
break;
case V_184 :
case V_180 :
F_61 ( V_76 , V_175 ) ;
break;
default:
break;
}
}
static void F_64 ( struct V_193 * V_194 , unsigned int V_175 ,
int V_77 , int V_164 )
{
struct V_24 * V_25 = F_65 ( V_194 ) ;
struct V_23 * V_76 = F_7 ( V_25 ) ;
struct V_181 * V_182 = & V_25 -> V_182 ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
bool V_195 = false ;
int V_102 = 0 ;
F_60 ( V_76 , V_175 ) ;
switch ( V_175 ) {
case V_178 :
V_102 = F_50 ( V_76 ) ;
V_195 = true ;
break;
case V_179 :
V_2 -> V_161 = 4 ;
V_102 = F_49 ( V_76 , V_77 ) ;
V_195 = true ;
break;
case V_160 :
V_102 = F_47 ( V_76 ) ;
V_195 = true ;
break;
case V_180 :
V_102 = F_48 ( V_76 , V_164 ) ;
V_195 = true ;
break;
case V_196 :
F_66 ( V_77 != 0 ) ;
V_76 -> V_82 = true ;
F_20 ( V_76 , 0 , V_164 ) ;
F_21 ( V_76 , V_182 -> V_185 , true ) ;
break;
case V_197 :
F_66 ( V_77 != 0 ) ;
F_20 ( V_76 , 0 , V_164 ) ;
break;
case V_184 :
case V_198 :
case V_199 :
default:
break;
}
if ( V_102 ) {
F_27 ( V_2 -> V_5 , L_5 ,
V_175 ) ;
F_56 ( V_2 ) ;
return;
}
if ( V_195 ) {
V_102 = F_51 ( V_2 ) ;
if ( V_102 )
F_27 ( V_2 -> V_5 ,
L_6 ,
V_175 ) ;
}
F_56 ( V_2 ) ;
F_63 ( V_76 , V_175 ) ;
}
static bool F_67 ( T_5 * V_200 , int V_201 )
{
T_5 V_202 , V_203 ;
V_202 = V_200 [ 3 ] ;
V_203 = V_200 [ 175 ] ;
if ( ( V_202 == 0x54 && V_203 == 0xff ) ||
( V_202 == 0xff && V_203 == 0x54 ) ) {
V_200 [ 3 ] = 0xff ;
V_200 [ 175 ] = 0xff ;
}
if ( F_68 ( V_200 , 0xff , V_201 ) ) {
V_200 [ 3 ] = V_202 ;
V_200 [ 175 ] = V_203 ;
return false ;
}
return true ;
}
static int F_69 ( struct V_23 * V_76 , T_5 * V_200 ,
T_5 * V_204 )
{
struct V_24 * V_25 = & V_76 -> V_25 ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
struct V_193 * V_194 = F_70 ( V_25 ) ;
struct V_181 * V_182 = & V_25 -> V_182 ;
unsigned int V_205 = 0 ;
struct V_206 * V_207 ;
int V_183 ;
V_207 = (struct V_206 * ) V_2 -> V_33 ;
F_14 ( V_2 , true ) ;
for ( V_183 = 0 ; V_183 < V_182 -> V_185 ; V_183 ++ , V_207 ++ ) {
T_2 V_208 , V_209 , V_210 ;
int V_201 , V_211 ;
if ( V_183 == ( V_182 -> V_185 - 1 ) ) {
V_201 = V_182 -> V_119 - ( ( V_182 -> V_185 - 1 ) << 2 ) ;
V_211 = V_182 -> V_185 << 2 ;
} else {
V_201 = V_76 -> V_92 ;
V_211 = 0 ;
}
V_208 = F_62 ( V_207 -> V_208 ) ;
V_209 = F_62 ( V_207 -> V_209 ) ;
V_210 = F_62 ( V_207 -> V_210 ) ;
if ( V_208 & ( V_190 | V_187 ) ) {
bool V_212 ;
if ( V_76 -> V_213 ) {
V_212 = ( V_210 & V_214 ) == V_214 ?
true : false ;
} else {
V_212 = F_67 ( V_200 ,
V_201 ) ;
}
if ( V_212 ) {
V_200 += V_201 ;
if ( V_204 )
V_204 += V_211 + V_182 -> V_215 ;
continue;
}
if ( V_209 & V_216 ) {
int V_102 , V_217 , V_218 ;
void * V_219 ;
V_219 = V_204 ? V_204 + V_211 : NULL ;
V_217 = V_204 ? V_76 -> V_220 : 0 ;
V_218 = V_204 ? V_211 : 0 ;
V_102 = F_71 ( V_200 ,
V_201 , V_219 , V_217 , V_204 ,
V_218 , V_182 -> V_221 ) ;
if ( V_102 < 0 ) {
V_194 -> V_222 . V_223 ++ ;
} else {
V_194 -> V_222 . V_224 += V_102 ;
V_205 =
F_72 (unsigned int, max_bitflips, ret) ;
}
}
} else {
unsigned int V_225 ;
V_225 = V_209 & V_226 ;
V_194 -> V_222 . V_224 += V_225 ;
V_205 = F_73 ( V_205 , V_225 ) ;
}
V_200 += V_201 ;
if ( V_204 )
V_204 += V_211 + V_182 -> V_215 ;
}
return V_205 ;
}
static int F_74 ( struct V_23 * V_76 , T_5 * V_200 ,
T_5 * V_204 )
{
struct V_24 * V_25 = & V_76 -> V_25 ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
struct V_181 * V_182 = & V_25 -> V_182 ;
int V_183 , V_102 ;
F_42 ( V_2 ) ;
for ( V_183 = 0 ; V_183 < V_182 -> V_185 ; V_183 ++ ) {
int V_227 , V_228 ;
if ( V_183 == ( V_182 -> V_185 - 1 ) ) {
V_227 = V_182 -> V_119 - ( ( V_182 -> V_185 - 1 ) << 2 ) ;
V_228 = ( V_182 -> V_185 << 2 ) + V_76 -> V_220 +
V_76 -> V_229 ;
} else {
V_227 = V_76 -> V_92 ;
V_228 = V_76 -> V_220 + V_76 -> V_229 ;
}
if ( V_2 -> V_15 -> V_16 ) {
if ( V_200 && V_204 ) {
F_22 ( V_2 , 0 , 0 , V_227 , 0 ) ;
F_22 ( V_2 , 1 , V_227 ,
V_228 , 1 ) ;
} else if ( V_200 ) {
F_22 ( V_2 , 0 , 0 , V_227 , 1 ) ;
} else {
F_22 ( V_2 , 0 , V_227 ,
V_228 , 1 ) ;
}
}
F_43 ( V_2 ) ;
if ( V_200 )
F_40 ( V_2 , V_163 , V_200 ,
V_227 , 0 ) ;
if ( V_204 ) {
int V_230 ;
for ( V_230 = 0 ; V_230 < V_76 -> V_231 ; V_230 ++ )
* V_204 ++ = 0xff ;
F_40 ( V_2 , V_163 + V_227 ,
V_204 , V_228 , 0 ) ;
}
if ( V_200 )
V_200 += V_227 ;
if ( V_204 )
V_204 += V_228 ;
}
V_102 = F_51 ( V_2 ) ;
if ( V_102 )
F_27 ( V_2 -> V_5 , L_7 ) ;
F_56 ( V_2 ) ;
return V_102 ;
}
static int F_75 ( struct V_23 * V_76 , int V_78 )
{
struct V_24 * V_25 = & V_76 -> V_25 ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
struct V_181 * V_182 = & V_25 -> V_182 ;
int V_119 ;
int V_102 ;
F_59 ( V_2 ) ;
V_119 = V_76 -> V_82 ? V_76 -> V_92 : V_76 -> V_93 ;
memset ( V_2 -> V_162 , 0xff , V_119 ) ;
F_20 ( V_76 , V_76 -> V_93 * ( V_182 -> V_185 - 1 ) , V_78 ) ;
F_21 ( V_76 , 1 , true ) ;
F_44 ( V_2 ) ;
F_40 ( V_2 , V_163 , V_2 -> V_162 , V_119 , 0 ) ;
V_102 = F_51 ( V_2 ) ;
if ( V_102 )
F_27 ( V_2 -> V_5 , L_8 ) ;
F_56 ( V_2 ) ;
return V_102 ;
}
static int F_76 ( struct V_193 * V_194 , struct V_24 * V_25 ,
T_7 * V_207 , int V_232 , int V_78 )
{
struct V_23 * V_76 = F_7 ( V_25 ) ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
T_5 * V_200 , * V_204 = NULL ;
int V_102 ;
V_200 = V_207 ;
V_204 = V_232 ? V_25 -> V_233 : NULL ;
F_5 ( V_2 ) ;
V_102 = F_74 ( V_76 , V_200 , V_204 ) ;
if ( V_102 ) {
F_27 ( V_2 -> V_5 , L_9 ) ;
return V_102 ;
}
return F_69 ( V_76 , V_200 , V_204 ) ;
}
static int F_77 ( struct V_193 * V_194 ,
struct V_24 * V_25 , T_7 * V_207 ,
int V_232 , int V_78 )
{
struct V_23 * V_76 = F_7 ( V_25 ) ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
T_5 * V_200 , * V_204 ;
struct V_181 * V_182 = & V_25 -> V_182 ;
int V_183 , V_102 ;
int V_234 ;
V_200 = V_207 ;
V_204 = V_25 -> V_233 ;
V_76 -> V_82 = false ;
F_5 ( V_2 ) ;
F_21 ( V_76 , V_182 -> V_185 , true ) ;
F_42 ( V_2 ) ;
for ( V_183 = 0 ; V_183 < V_182 -> V_185 ; V_183 ++ ) {
int V_235 , V_236 , V_237 , V_238 ;
int V_122 = V_163 ;
V_235 = V_194 -> V_239 - V_76 -> V_93 * ( V_182 -> V_185 - 1 ) ;
V_237 = V_76 -> V_231 ;
if ( V_183 == ( V_182 -> V_185 - 1 ) ) {
V_236 = V_182 -> V_119 - V_235 -
( ( V_182 -> V_185 - 1 ) << 2 ) ;
V_238 = ( V_182 -> V_185 << 2 ) + V_76 -> V_220 +
V_76 -> V_229 ;
} else {
V_236 = V_76 -> V_92 - V_235 ;
V_238 = V_76 -> V_220 + V_76 -> V_229 ;
}
if ( V_2 -> V_15 -> V_16 ) {
V_234 = 0 ;
F_22 ( V_2 , 0 , V_234 , V_235 , 0 ) ;
V_234 += V_235 ;
F_22 ( V_2 , 1 , V_234 , V_237 , 0 ) ;
V_234 += V_237 ;
F_22 ( V_2 , 2 , V_234 , V_236 , 0 ) ;
V_234 += V_236 ;
F_22 ( V_2 , 3 , V_234 , V_238 , 1 ) ;
}
F_43 ( V_2 ) ;
F_40 ( V_2 , V_122 , V_200 , V_235 , 0 ) ;
V_122 += V_235 ;
V_200 += V_235 ;
F_40 ( V_2 , V_122 , V_204 , V_237 , 0 ) ;
V_122 += V_237 ;
V_204 += V_237 ;
F_40 ( V_2 , V_122 , V_200 , V_236 , 0 ) ;
V_122 += V_236 ;
V_200 += V_236 ;
F_40 ( V_2 , V_122 , V_204 , V_238 , 0 ) ;
V_204 += V_238 ;
}
V_102 = F_51 ( V_2 ) ;
if ( V_102 )
F_27 ( V_2 -> V_5 , L_10 ) ;
F_56 ( V_2 ) ;
return 0 ;
}
static int F_78 ( struct V_193 * V_194 , struct V_24 * V_25 ,
int V_78 )
{
struct V_23 * V_76 = F_7 ( V_25 ) ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
struct V_181 * V_182 = & V_25 -> V_182 ;
int V_102 ;
F_59 ( V_2 ) ;
F_5 ( V_2 ) ;
V_76 -> V_82 = true ;
F_20 ( V_76 , 0 , V_78 ) ;
F_21 ( V_76 , V_182 -> V_185 , true ) ;
V_102 = F_74 ( V_76 , NULL , V_25 -> V_233 ) ;
if ( V_102 )
F_27 ( V_2 -> V_5 , L_11 ) ;
return V_102 ;
}
static int F_79 ( struct V_193 * V_194 , struct V_24 * V_25 ,
const T_7 * V_207 , int V_232 , int V_78 )
{
struct V_23 * V_76 = F_7 ( V_25 ) ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
struct V_181 * V_182 = & V_25 -> V_182 ;
T_5 * V_200 , * V_204 ;
int V_183 , V_102 ;
F_59 ( V_2 ) ;
F_5 ( V_2 ) ;
V_200 = ( T_5 * ) V_207 ;
V_204 = V_25 -> V_233 ;
V_76 -> V_82 = true ;
F_21 ( V_76 , V_182 -> V_185 , false ) ;
F_45 ( V_2 ) ;
for ( V_183 = 0 ; V_183 < V_182 -> V_185 ; V_183 ++ ) {
int V_227 , V_228 ;
if ( V_183 == ( V_182 -> V_185 - 1 ) ) {
V_227 = V_182 -> V_119 - ( ( V_182 -> V_185 - 1 ) << 2 ) ;
V_228 = ( V_182 -> V_185 << 2 ) + V_76 -> V_220 +
V_76 -> V_229 ;
} else {
V_227 = V_76 -> V_92 ;
V_228 = V_182 -> V_215 ;
}
F_41 ( V_2 , V_163 , V_200 , V_227 ,
V_183 == ( V_182 -> V_185 - 1 ) ? V_120 : 0 ) ;
if ( V_183 == ( V_182 -> V_185 - 1 ) ) {
V_204 += V_76 -> V_231 ;
F_41 ( V_2 , V_163 + V_227 ,
V_204 , V_228 , 0 ) ;
}
F_46 ( V_2 ) ;
V_200 += V_227 ;
V_204 += V_228 ;
}
V_102 = F_51 ( V_2 ) ;
if ( V_102 )
F_27 ( V_2 -> V_5 , L_12 ) ;
F_56 ( V_2 ) ;
return V_102 ;
}
static int F_80 ( struct V_193 * V_194 ,
struct V_24 * V_25 , const T_7 * V_207 ,
int V_232 , int V_78 )
{
struct V_23 * V_76 = F_7 ( V_25 ) ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
struct V_181 * V_182 = & V_25 -> V_182 ;
T_5 * V_200 , * V_204 ;
int V_183 , V_102 ;
F_59 ( V_2 ) ;
F_5 ( V_2 ) ;
V_200 = ( T_5 * ) V_207 ;
V_204 = V_25 -> V_233 ;
V_76 -> V_82 = false ;
F_21 ( V_76 , V_182 -> V_185 , false ) ;
F_45 ( V_2 ) ;
for ( V_183 = 0 ; V_183 < V_182 -> V_185 ; V_183 ++ ) {
int V_235 , V_236 , V_237 , V_238 ;
int V_122 = V_163 ;
V_235 = V_194 -> V_239 - V_76 -> V_93 * ( V_182 -> V_185 - 1 ) ;
V_237 = V_76 -> V_231 ;
if ( V_183 == ( V_182 -> V_185 - 1 ) ) {
V_236 = V_182 -> V_119 - V_235 -
( ( V_182 -> V_185 - 1 ) << 2 ) ;
V_238 = ( V_182 -> V_185 << 2 ) + V_76 -> V_220 +
V_76 -> V_229 ;
} else {
V_236 = V_76 -> V_92 - V_235 ;
V_238 = V_76 -> V_220 + V_76 -> V_229 ;
}
F_41 ( V_2 , V_122 , V_200 , V_235 ,
V_120 ) ;
V_122 += V_235 ;
V_200 += V_235 ;
F_41 ( V_2 , V_122 , V_204 , V_237 ,
V_120 ) ;
V_122 += V_237 ;
V_204 += V_237 ;
F_41 ( V_2 , V_122 , V_200 , V_236 ,
V_120 ) ;
V_122 += V_236 ;
V_200 += V_236 ;
F_41 ( V_2 , V_122 , V_204 , V_238 , 0 ) ;
V_204 += V_238 ;
F_46 ( V_2 ) ;
}
V_102 = F_51 ( V_2 ) ;
if ( V_102 )
F_27 ( V_2 -> V_5 , L_13 ) ;
F_56 ( V_2 ) ;
return V_102 ;
}
static int F_81 ( struct V_193 * V_194 , struct V_24 * V_25 ,
int V_78 )
{
struct V_23 * V_76 = F_7 ( V_25 ) ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
struct V_181 * V_182 = & V_25 -> V_182 ;
T_5 * V_240 = V_25 -> V_233 ;
int V_227 , V_228 ;
int V_102 , V_188 = 0 ;
V_76 -> V_82 = true ;
F_5 ( V_2 ) ;
V_102 = F_75 ( V_76 , V_78 ) ;
if ( V_102 )
return V_102 ;
F_59 ( V_2 ) ;
F_5 ( V_2 ) ;
V_227 = V_182 -> V_119 - ( ( V_182 -> V_185 - 1 ) << 2 ) ;
V_228 = V_194 -> V_241 ;
F_82 ( V_194 , V_2 -> V_162 + V_227 , V_240 ,
0 , V_194 -> V_241 ) ;
F_20 ( V_76 , V_76 -> V_93 * ( V_182 -> V_185 - 1 ) , V_78 ) ;
F_21 ( V_76 , 1 , false ) ;
F_45 ( V_2 ) ;
F_41 ( V_2 , V_163 ,
V_2 -> V_162 , V_227 + V_228 , 0 ) ;
F_46 ( V_2 ) ;
V_102 = F_51 ( V_2 ) ;
F_56 ( V_2 ) ;
if ( V_102 ) {
F_27 ( V_2 -> V_5 , L_14 ) ;
return - V_242 ;
}
V_25 -> V_243 ( V_194 , V_184 , - 1 , - 1 ) ;
V_188 = V_25 -> V_244 ( V_194 , V_25 ) ;
return V_188 & V_192 ? - V_242 : 0 ;
}
static int F_83 ( struct V_193 * V_194 , T_8 V_245 )
{
struct V_24 * V_25 = F_65 ( V_194 ) ;
struct V_23 * V_76 = F_7 ( V_25 ) ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
struct V_181 * V_182 = & V_25 -> V_182 ;
int V_78 , V_102 , V_246 , V_247 = 0 ;
T_2 V_186 ;
V_78 = ( int ) ( V_245 >> V_25 -> V_248 ) & V_25 -> V_249 ;
V_76 -> V_82 = false ;
F_5 ( V_2 ) ;
V_102 = F_75 ( V_76 , V_78 ) ;
if ( V_102 )
goto V_127;
V_186 = F_62 ( V_2 -> V_33 [ 0 ] ) ;
if ( V_186 & ( V_190 | V_187 ) ) {
F_84 ( V_2 -> V_5 , L_15 ) ;
goto V_127;
}
V_246 = V_194 -> V_239 - V_76 -> V_93 * ( V_182 -> V_185 - 1 ) ;
V_247 = V_2 -> V_162 [ V_246 ] != 0xff ;
if ( V_25 -> V_79 & V_80 )
V_247 = V_247 || ( V_2 -> V_162 [ V_246 + 1 ] != 0xff ) ;
V_127:
return V_247 ;
}
static int F_85 ( struct V_193 * V_194 , T_8 V_245 )
{
struct V_24 * V_25 = F_65 ( V_194 ) ;
struct V_23 * V_76 = F_7 ( V_25 ) ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
struct V_181 * V_182 = & V_25 -> V_182 ;
int V_78 , V_102 , V_188 = 0 ;
F_59 ( V_2 ) ;
F_5 ( V_2 ) ;
memset ( V_2 -> V_162 , 0x00 , V_76 -> V_93 ) ;
V_78 = ( int ) ( V_245 >> V_25 -> V_248 ) & V_25 -> V_249 ;
V_76 -> V_82 = false ;
F_20 ( V_76 , V_76 -> V_93 * ( V_182 -> V_185 - 1 ) , V_78 ) ;
F_21 ( V_76 , 1 , false ) ;
F_45 ( V_2 ) ;
F_41 ( V_2 , V_163 ,
V_2 -> V_162 , V_76 -> V_93 , 0 ) ;
F_46 ( V_2 ) ;
V_102 = F_51 ( V_2 ) ;
F_56 ( V_2 ) ;
if ( V_102 ) {
F_27 ( V_2 -> V_5 , L_16 ) ;
return - V_242 ;
}
V_25 -> V_243 ( V_194 , V_184 , - 1 , - 1 ) ;
V_188 = V_25 -> V_244 ( V_194 , V_25 ) ;
return V_188 & V_192 ? - V_242 : 0 ;
}
static T_7 F_86 ( struct V_193 * V_194 )
{
struct V_24 * V_25 = F_65 ( V_194 ) ;
struct V_23 * V_76 = F_7 ( V_25 ) ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
T_5 * V_207 = V_2 -> V_162 ;
T_5 V_102 = 0x0 ;
if ( V_76 -> V_177 == V_198 ) {
V_102 = V_76 -> V_188 ;
V_76 -> V_188 = V_250 | V_189 ;
return V_102 ;
}
if ( V_2 -> V_176 < V_2 -> V_161 )
V_102 = V_207 [ V_2 -> V_176 ++ ] ;
return V_102 ;
}
static void F_87 ( struct V_193 * V_194 , T_7 * V_207 , int V_251 )
{
struct V_24 * V_25 = F_65 ( V_194 ) ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
int V_252 = F_88 ( T_1 , V_251 , V_2 -> V_161 - V_2 -> V_176 ) ;
memcpy ( V_207 , V_2 -> V_162 + V_2 -> V_176 , V_252 ) ;
V_2 -> V_176 += V_252 ;
}
static void F_89 ( struct V_193 * V_194 , const T_7 * V_207 ,
int V_251 )
{
struct V_24 * V_25 = F_65 ( V_194 ) ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
int V_252 = F_88 ( T_1 , V_251 , V_2 -> V_161 - V_2 -> V_176 ) ;
memcpy ( V_2 -> V_162 + V_2 -> V_176 , V_207 , V_252 ) ;
V_2 -> V_176 += V_252 ;
}
static void F_90 ( struct V_193 * V_194 , int V_253 )
{
struct V_24 * V_25 = F_65 ( V_194 ) ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
if ( V_253 <= 0 )
return;
F_84 ( V_2 -> V_5 , L_17 ) ;
}
static int F_91 ( struct V_193 * V_194 , int V_254 ,
struct V_255 * V_256 )
{
struct V_24 * V_25 = F_65 ( V_194 ) ;
struct V_23 * V_76 = F_7 ( V_25 ) ;
struct V_181 * V_182 = & V_25 -> V_182 ;
if ( V_254 > 1 )
return - V_257 ;
if ( ! V_254 ) {
V_256 -> V_258 = ( V_182 -> V_215 * ( V_182 -> V_185 - 1 ) ) +
V_76 -> V_231 ;
V_256 -> V_27 = 0 ;
} else {
V_256 -> V_258 = V_76 -> V_220 + V_76 -> V_229 ;
V_256 -> V_27 = V_194 -> V_259 - V_256 -> V_258 ;
}
return 0 ;
}
static int F_92 ( struct V_193 * V_194 , int V_254 ,
struct V_255 * V_256 )
{
struct V_24 * V_25 = F_65 ( V_194 ) ;
struct V_23 * V_76 = F_7 ( V_25 ) ;
struct V_181 * V_182 = & V_25 -> V_182 ;
if ( V_254 )
return - V_257 ;
V_256 -> V_258 = V_182 -> V_185 * 4 ;
V_256 -> V_27 = ( ( V_182 -> V_185 - 1 ) * V_182 -> V_215 ) + V_76 -> V_231 ;
return 0 ;
}
static int F_93 ( struct V_23 * V_76 )
{
struct V_24 * V_25 = & V_76 -> V_25 ;
struct V_193 * V_194 = F_70 ( V_25 ) ;
struct V_181 * V_182 = & V_25 -> V_182 ;
struct V_1 * V_2 = F_9 ( V_25 ) ;
int V_260 , V_261 ;
bool V_262 ;
int V_263 = 1 ;
if ( V_182 -> V_119 != V_264 ) {
F_27 ( V_2 -> V_5 , L_18 ) ;
return - V_115 ;
}
V_262 = V_25 -> V_79 & V_80 ? true : false ;
if ( V_182 -> V_221 >= 8 ) {
V_76 -> V_213 = true ;
V_263 = 1 ;
if ( V_262 ) {
V_76 -> V_220 = 14 ;
V_76 -> V_229 = 0 ;
V_76 -> V_231 = 2 ;
} else {
V_76 -> V_220 = 13 ;
V_76 -> V_229 = 2 ;
V_76 -> V_231 = 1 ;
}
} else {
if ( V_2 -> V_15 -> V_265 & V_266 ) {
V_76 -> V_213 = true ;
V_263 = 0 ;
if ( V_262 ) {
V_76 -> V_220 = 8 ;
V_76 -> V_229 = 2 ;
V_76 -> V_231 = 2 ;
} else {
V_76 -> V_220 = 7 ;
V_76 -> V_229 = 4 ;
V_76 -> V_231 = 1 ;
}
} else {
V_76 -> V_220 = 10 ;
if ( V_262 ) {
V_76 -> V_229 = 0 ;
V_76 -> V_231 = 2 ;
} else {
V_76 -> V_229 = 1 ;
V_76 -> V_231 = 1 ;
}
}
}
V_182 -> V_215 = V_76 -> V_220 + V_76 -> V_229 + V_76 -> V_231 ;
V_182 -> V_267 = F_76 ;
V_182 -> V_268 = F_77 ;
V_182 -> V_269 = F_78 ;
V_182 -> V_270 = F_79 ;
V_182 -> V_271 = F_80 ;
V_182 -> V_272 = F_81 ;
V_182 -> V_273 = V_274 ;
F_94 ( V_194 , & V_275 ) ;
V_260 = V_194 -> V_239 / V_182 -> V_119 ;
V_2 -> V_8 = F_72 (unsigned int, nandc->max_cwperpage,
cwperpage) ;
V_76 -> V_92 = 516 ;
V_76 -> V_93 = V_76 -> V_92 + V_182 -> V_215 ;
if ( V_182 -> V_215 * ( V_194 -> V_239 / V_182 -> V_119 ) > V_194 -> V_259 ) {
F_27 ( V_2 -> V_5 , L_19 ) ;
return - V_115 ;
}
V_261 = V_194 -> V_239 - V_76 -> V_93 * ( V_260 - 1 ) + 1 ;
V_76 -> V_50 = ( V_260 - 1 ) << V_88
| V_76 -> V_92 << V_148
| 0 << V_276
| 5 << V_149
| V_76 -> V_220 << V_277
| 0 << V_278
| 1 << V_279
| V_76 -> V_229 << V_150 ;
V_76 -> V_52 = 7 << V_151
| 0 << V_152
| V_261 << V_153
| 0 << V_154
| 2 << V_155
| V_262 << V_156
| V_76 -> V_213 << V_280 ;
V_76 -> V_89 = ( V_260 - 1 ) << V_88
| V_76 -> V_93 << V_148
| 5 << V_149
| 0 << V_150 ;
V_76 -> V_90 = 7 << V_151
| 0 << V_152
| 17 << V_153
| 1 << V_154
| 2 << V_155
| V_262 << V_156
| 1 << V_157 ;
V_76 -> V_54 = ! V_76 -> V_213 << V_91
| 0 << V_281
| V_76 -> V_92 << V_282
| 1 << V_283
| V_263 << V_284
| V_76 -> V_220 << V_285 ;
V_76 -> V_66 = 0x203 << V_286 ;
V_76 -> V_48 = V_287 ;
V_76 -> V_56 = 0xc0 ;
V_2 -> V_36 -> V_144 =
F_19 ( V_288 ) ;
V_2 -> V_36 -> V_143 =
F_19 ( V_289 ) ;
F_95 ( V_2 -> V_5 ,
L_20 ,
V_76 -> V_50 , V_76 -> V_52 , V_76 -> V_66 , V_76 -> V_54 ,
V_76 -> V_93 , V_76 -> V_92 , V_182 -> V_221 , V_182 -> V_215 ,
V_260 ) ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 )
{
int V_102 ;
V_102 = F_97 ( V_2 -> V_5 , F_98 ( 32 ) ) ;
if ( V_102 ) {
F_27 ( V_2 -> V_5 , L_21 ) ;
return V_102 ;
}
V_2 -> V_290 = 532 ;
V_2 -> V_162 = F_4 ( V_2 -> V_5 , V_2 -> V_290 ,
V_14 ) ;
if ( ! V_2 -> V_162 )
return - V_107 ;
V_2 -> V_36 = F_4 ( V_2 -> V_5 , sizeof( * V_2 -> V_36 ) ,
V_14 ) ;
if ( ! V_2 -> V_36 )
return - V_107 ;
V_2 -> V_33 = F_4 ( V_2 -> V_5 ,
V_32 * sizeof( * V_2 -> V_33 ) ,
V_14 ) ;
if ( ! V_2 -> V_33 )
return - V_107 ;
if ( V_2 -> V_15 -> V_16 ) {
V_2 -> V_31 =
F_99 ( V_2 -> V_5 , V_2 -> V_33 ,
V_32 *
sizeof( * V_2 -> V_33 ) ,
V_34 ) ;
if ( F_100 ( V_2 -> V_5 , V_2 -> V_31 ) ) {
F_27 ( V_2 -> V_5 , L_22 ) ;
return - V_242 ;
}
V_2 -> V_112 = F_101 ( V_2 -> V_5 , L_23 ) ;
if ( ! V_2 -> V_112 ) {
F_27 ( V_2 -> V_5 , L_24 ) ;
return - V_291 ;
}
V_2 -> V_171 = F_101 ( V_2 -> V_5 , L_25 ) ;
if ( ! V_2 -> V_171 ) {
F_27 ( V_2 -> V_5 , L_26 ) ;
return - V_291 ;
}
V_2 -> V_108 = F_101 ( V_2 -> V_5 , L_27 ) ;
if ( ! V_2 -> V_108 ) {
F_27 ( V_2 -> V_5 , L_28 ) ;
return - V_291 ;
}
V_2 -> V_8 = 1 ;
V_2 -> V_4 = F_3 ( V_2 ) ;
if ( ! V_2 -> V_4 ) {
F_27 ( V_2 -> V_5 ,
L_29 ) ;
return - V_107 ;
}
} else {
V_2 -> V_95 = F_101 ( V_2 -> V_5 , L_30 ) ;
if ( ! V_2 -> V_95 ) {
F_27 ( V_2 -> V_5 ,
L_31 ) ;
return - V_291 ;
}
}
F_102 ( & V_2 -> V_117 ) ;
F_102 ( & V_2 -> V_292 ) ;
F_103 ( & V_2 -> V_26 ) ;
return 0 ;
}
static void F_104 ( struct V_1 * V_2 )
{
if ( V_2 -> V_15 -> V_16 ) {
if ( ! F_100 ( V_2 -> V_5 , V_2 -> V_31 ) )
F_105 ( V_2 -> V_5 , V_2 -> V_31 ,
V_32 *
sizeof( * V_2 -> V_33 ) ,
V_34 ) ;
if ( V_2 -> V_112 )
F_106 ( V_2 -> V_112 ) ;
if ( V_2 -> V_171 )
F_106 ( V_2 -> V_171 ) ;
if ( V_2 -> V_108 )
F_106 ( V_2 -> V_108 ) ;
} else {
if ( V_2 -> V_95 )
F_106 ( V_2 -> V_95 ) ;
}
}
static int F_107 ( struct V_1 * V_2 )
{
T_2 V_293 ;
F_12 ( V_2 , V_294 , 0 ) ;
F_12 ( V_2 , F_38 ( V_2 , V_61 ) ,
V_295 ) ;
if ( V_2 -> V_15 -> V_16 ) {
V_293 = F_10 ( V_2 , V_296 ) ;
F_12 ( V_2 , V_296 , V_293 | V_297 ) ;
} else {
F_12 ( V_2 , V_43 , V_167 ) ;
}
V_2 -> V_58 = F_10 ( V_2 , F_38 ( V_2 , V_57 ) ) ;
V_2 -> V_62 = V_295 ;
return 0 ;
}
static int F_108 ( struct V_1 * V_2 ,
struct V_23 * V_76 ,
struct V_298 * V_299 )
{
struct V_24 * V_25 = & V_76 -> V_25 ;
struct V_193 * V_194 = F_70 ( V_25 ) ;
struct V_300 * V_5 = V_2 -> V_5 ;
int V_102 ;
V_102 = F_109 ( V_299 , L_32 , & V_76 -> V_301 ) ;
if ( V_102 ) {
F_27 ( V_5 , L_33 ) ;
return - V_302 ;
}
F_110 ( V_25 , V_299 ) ;
V_194 -> V_303 = F_111 ( V_5 , V_14 , L_34 , V_76 -> V_301 ) ;
V_194 -> V_304 = V_305 ;
V_194 -> V_5 . V_306 = V_5 ;
V_25 -> V_243 = F_64 ;
V_25 -> V_307 = F_90 ;
V_25 -> V_308 = F_86 ;
V_25 -> V_309 = F_87 ;
V_25 -> V_310 = F_89 ;
V_25 -> V_311 = V_312 ;
V_25 -> V_313 = V_312 ;
V_25 -> V_314 = F_83 ;
V_25 -> V_315 = F_85 ;
V_25 -> V_26 = & V_2 -> V_26 ;
V_25 -> V_79 |= V_316 | V_317 |
V_318 ;
V_76 -> V_188 = V_250 | V_189 ;
V_102 = F_112 ( V_194 , 1 , NULL ) ;
if ( V_102 )
return V_102 ;
V_102 = F_93 ( V_76 ) ;
return V_102 ;
}
static int F_113 ( struct V_1 * V_2 ,
struct V_23 * V_76 ,
struct V_298 * V_299 )
{
struct V_24 * V_25 = & V_76 -> V_25 ;
struct V_193 * V_194 = F_70 ( V_25 ) ;
int V_102 ;
V_102 = F_114 ( V_194 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_115 ( V_194 , NULL , 0 ) ;
if ( V_102 )
F_116 ( F_65 ( V_194 ) ) ;
return V_102 ;
}
static int F_117 ( struct V_1 * V_2 )
{
struct V_300 * V_5 = V_2 -> V_5 ;
struct V_298 * V_299 = V_5 -> V_319 , * V_320 ;
struct V_23 * V_76 , * V_321 ;
int V_102 ;
F_118 (dn, child) {
V_76 = F_4 ( V_5 , sizeof( * V_76 ) , V_14 ) ;
if ( ! V_76 ) {
F_119 ( V_320 ) ;
return - V_107 ;
}
V_102 = F_108 ( V_2 , V_76 , V_320 ) ;
if ( V_102 ) {
F_2 ( V_5 , V_76 ) ;
continue;
}
F_31 ( & V_76 -> V_116 , & V_2 -> V_292 ) ;
}
if ( F_120 ( & V_2 -> V_292 ) )
return - V_291 ;
if ( V_2 -> V_15 -> V_16 ) {
F_1 ( V_2 ) ;
V_2 -> V_4 = F_3 ( V_2 ) ;
if ( ! V_2 -> V_4 ) {
F_27 ( V_2 -> V_5 ,
L_29 ) ;
return - V_107 ;
}
}
F_57 (host, tmp, &nandc->host_list, node) {
V_102 = F_113 ( V_2 , V_76 , V_320 ) ;
if ( V_102 ) {
F_58 ( & V_76 -> V_116 ) ;
F_2 ( V_5 , V_76 ) ;
}
}
if ( F_120 ( & V_2 -> V_292 ) )
return - V_291 ;
return 0 ;
}
static int F_121 ( struct V_322 * V_323 )
{
struct V_1 * V_2 = F_122 ( V_323 ) ;
struct V_298 * V_324 = V_2 -> V_5 -> V_319 ;
int V_102 ;
if ( ! V_2 -> V_15 -> V_16 ) {
V_102 = F_109 ( V_324 , L_35 ,
& V_2 -> V_136 ) ;
if ( V_102 ) {
F_27 ( V_2 -> V_5 , L_36 ) ;
return V_102 ;
}
V_102 = F_109 ( V_324 , L_37 ,
& V_2 -> V_133 ) ;
if ( V_102 ) {
F_27 ( V_2 -> V_5 , L_38 ) ;
return V_102 ;
}
}
return 0 ;
}
static int F_123 ( struct V_322 * V_323 )
{
struct V_1 * V_2 ;
const void * V_325 ;
struct V_300 * V_5 = & V_323 -> V_5 ;
struct V_326 * V_327 ;
int V_102 ;
V_2 = F_4 ( & V_323 -> V_5 , sizeof( * V_2 ) , V_14 ) ;
if ( ! V_2 )
return - V_107 ;
F_124 ( V_323 , V_2 ) ;
V_2 -> V_5 = V_5 ;
V_325 = F_125 ( V_5 ) ;
if ( ! V_325 ) {
F_27 ( & V_323 -> V_5 , L_39 ) ;
return - V_291 ;
}
V_2 -> V_15 = V_325 ;
V_327 = F_126 ( V_323 , V_328 , 0 ) ;
V_2 -> V_28 = F_127 ( V_5 , V_327 ) ;
if ( F_128 ( V_2 -> V_28 ) )
return F_129 ( V_2 -> V_28 ) ;
V_2 -> V_131 = F_130 ( V_5 , ( V_329 ) V_327 -> V_330 ) ;
V_2 -> V_331 = F_131 ( V_5 , L_40 ) ;
if ( F_128 ( V_2 -> V_331 ) )
return F_129 ( V_2 -> V_331 ) ;
V_2 -> V_332 = F_131 ( V_5 , L_41 ) ;
if ( F_128 ( V_2 -> V_332 ) )
return F_129 ( V_2 -> V_332 ) ;
V_102 = F_121 ( V_323 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_96 ( V_2 ) ;
if ( V_102 )
goto V_333;
V_102 = F_132 ( V_2 -> V_331 ) ;
if ( V_102 )
goto V_333;
V_102 = F_132 ( V_2 -> V_332 ) ;
if ( V_102 )
goto V_334;
V_102 = F_107 ( V_2 ) ;
if ( V_102 )
goto V_335;
V_102 = F_117 ( V_2 ) ;
if ( V_102 )
goto V_335;
return 0 ;
V_335:
F_133 ( V_2 -> V_332 ) ;
V_334:
F_133 ( V_2 -> V_331 ) ;
V_333:
F_104 ( V_2 ) ;
return V_102 ;
}
static int F_134 ( struct V_322 * V_323 )
{
struct V_1 * V_2 = F_122 ( V_323 ) ;
struct V_23 * V_76 ;
F_52 (host, &nandc->host_list, node)
F_135 ( F_70 ( & V_76 -> V_25 ) ) ;
F_104 ( V_2 ) ;
F_133 ( V_2 -> V_332 ) ;
F_133 ( V_2 -> V_331 ) ;
return 0 ;
}
