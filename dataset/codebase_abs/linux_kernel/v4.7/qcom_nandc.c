static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_4 *
F_3 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_5 , struct V_4 ,
V_5 ) ;
}
static inline T_1 F_4 ( struct V_4 * V_6 , int V_7 )
{
return F_5 ( V_6 -> V_8 + V_7 ) ;
}
static inline void F_6 ( struct V_4 * V_6 , int V_7 ,
T_1 V_9 )
{
F_7 ( V_9 , V_6 -> V_8 + V_7 ) ;
}
static T_2 * F_8 ( struct V_10 * V_11 , int V_7 )
{
switch ( V_7 ) {
case V_12 :
return & V_11 -> V_13 ;
case V_14 :
return & V_11 -> V_15 ;
case V_16 :
return & V_11 -> V_17 ;
case V_18 :
return & V_11 -> V_19 ;
case V_20 :
return & V_11 -> V_21 ;
case V_22 :
return & V_11 -> V_23 ;
case V_24 :
return & V_11 -> V_25 ;
case V_26 :
return & V_11 -> V_27 ;
case V_28 :
return & V_11 -> V_29 ;
case V_30 :
return & V_11 -> V_31 ;
case V_32 :
return & V_11 -> V_33 ;
case V_34 :
return & V_11 -> V_35 ;
case V_36 :
return & V_11 -> V_37 ;
case V_38 :
return & V_11 -> V_39 ;
case V_40 :
return & V_11 -> V_41 ;
default:
return NULL ;
}
}
static void F_9 ( struct V_4 * V_6 , int V_7 ,
T_1 V_9 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
T_2 * V_42 ;
V_42 = F_8 ( V_11 , V_7 ) ;
if ( V_42 )
* V_42 = F_10 ( V_9 ) ;
}
static void F_11 ( struct V_1 * V_43 , T_3 V_44 , int V_45 )
{
struct V_2 * V_3 = & V_43 -> V_3 ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
if ( V_3 -> V_46 & V_47 )
V_44 >>= 1 ;
F_9 ( V_6 , V_14 , V_45 << 16 | V_44 ) ;
F_9 ( V_6 , V_16 , V_45 >> 16 & 0xff ) ;
}
static void F_12 ( struct V_1 * V_43 , int V_48 , bool V_49 )
{
struct V_2 * V_3 = & V_43 -> V_3 ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
T_1 V_13 , V_25 , V_27 , V_29 ;
if ( V_49 ) {
if ( V_43 -> V_50 )
V_13 = V_51 | V_52 | V_53 ;
else
V_13 = V_54 | V_52 | V_53 ;
} else {
V_13 = V_55 | V_52 | V_53 ;
}
if ( V_43 -> V_50 ) {
V_25 = ( V_43 -> V_25 & ~ ( 7U << V_56 ) ) |
( V_48 - 1 ) << V_56 ;
V_27 = V_43 -> V_27 ;
V_29 = V_43 -> V_29 ;
} else {
V_25 = ( V_43 -> V_57 & ~ ( 7U << V_56 ) ) |
( V_48 - 1 ) << V_56 ;
V_27 = V_43 -> V_58 ;
V_29 = 1 << V_59 ;
}
F_9 ( V_6 , V_12 , V_13 ) ;
F_9 ( V_6 , V_24 , V_25 ) ;
F_9 ( V_6 , V_26 , V_27 ) ;
F_9 ( V_6 , V_28 , V_29 ) ;
F_9 ( V_6 , V_40 , V_43 -> V_41 ) ;
F_9 ( V_6 , V_22 , V_43 -> V_23 ) ;
F_9 ( V_6 , V_30 , V_43 -> V_31 ) ;
F_9 ( V_6 , V_20 , 1 ) ;
}
static int F_13 ( struct V_4 * V_6 , bool V_49 ,
int V_60 , const void * V_61 , int V_62 ,
bool V_63 )
{
struct V_64 * V_65 ;
struct V_66 * V_67 ;
struct V_68 * V_69 ;
struct V_70 V_71 ;
enum V_72 V_73 ;
int V_74 ;
V_65 = F_14 ( sizeof( * V_65 ) , V_75 ) ;
if ( ! V_65 )
return - V_76 ;
V_69 = & V_65 -> V_69 ;
F_15 ( V_69 , V_61 , V_62 ) ;
if ( V_49 ) {
V_73 = V_77 ;
V_65 -> V_78 = V_79 ;
} else {
V_73 = V_80 ;
V_65 -> V_78 = V_81 ;
}
V_74 = F_16 ( V_6 -> V_82 , V_69 , 1 , V_65 -> V_78 ) ;
if ( V_74 == 0 ) {
V_74 = - V_76 ;
goto V_83;
}
memset ( & V_71 , 0x00 , sizeof( V_71 ) ) ;
V_71 . V_84 = V_63 ;
if ( V_49 ) {
V_71 . V_85 = 16 ;
V_71 . V_86 = V_6 -> V_87 + V_60 ;
V_71 . V_88 = V_6 -> V_89 ;
} else {
V_71 . V_90 = 16 ;
V_71 . V_91 = V_6 -> V_87 + V_60 ;
V_71 . V_88 = V_6 -> V_92 ;
}
V_74 = F_17 ( V_6 -> V_93 , & V_71 ) ;
if ( V_74 ) {
F_18 ( V_6 -> V_82 , L_1 ) ;
goto V_83;
}
V_67 = F_19 ( V_6 -> V_93 , V_69 , 1 , V_73 , 0 ) ;
if ( ! V_67 ) {
F_18 ( V_6 -> V_82 , L_2 ) ;
V_74 = - V_94 ;
goto V_83;
}
V_65 -> V_67 = V_67 ;
F_20 ( & V_65 -> V_95 , & V_6 -> V_96 ) ;
return 0 ;
V_83:
F_21 ( V_65 ) ;
return V_74 ;
}
static int F_22 ( struct V_4 * V_6 , int V_97 ,
int V_98 )
{
bool V_63 = false ;
void * V_61 ;
int V_62 ;
if ( V_97 == V_99 || V_97 == V_22 )
V_63 = true ;
V_62 = V_98 * sizeof( T_1 ) ;
V_61 = V_6 -> V_100 + V_6 -> V_101 ;
V_6 -> V_101 += V_98 ;
return F_13 ( V_6 , true , V_97 , V_61 , V_62 , V_63 ) ;
}
static int F_23 ( struct V_4 * V_6 , int V_97 ,
int V_98 )
{
bool V_63 = false ;
struct V_10 * V_11 = V_6 -> V_11 ;
void * V_61 ;
int V_62 ;
V_61 = F_8 ( V_11 , V_97 ) ;
if ( V_97 == V_12 )
V_63 = true ;
if ( V_97 == V_34 )
V_97 = V_32 ;
if ( V_97 == V_38 )
V_97 = V_36 ;
V_62 = V_98 * sizeof( T_1 ) ;
return F_13 ( V_6 , false , V_97 , V_61 , V_62 , V_63 ) ;
}
static int F_24 ( struct V_4 * V_6 , int V_60 ,
const T_4 * V_61 , int V_62 )
{
return F_13 ( V_6 , true , V_60 , V_61 , V_62 , false ) ;
}
static int F_25 ( struct V_4 * V_6 , int V_60 ,
const T_4 * V_61 , int V_62 )
{
return F_13 ( V_6 , false , V_60 , V_61 , V_62 , false ) ;
}
static void F_26 ( struct V_4 * V_6 )
{
F_23 ( V_6 , V_12 , 3 ) ;
F_23 ( V_6 , V_24 , 3 ) ;
F_23 ( V_6 , V_40 , 1 ) ;
F_23 ( V_6 , V_20 , 1 ) ;
F_22 ( V_6 , V_22 , 2 ) ;
F_22 ( V_6 , V_102 , 1 ) ;
}
static void F_27 ( struct V_4 * V_6 )
{
F_23 ( V_6 , V_12 , 3 ) ;
F_23 ( V_6 , V_24 , 3 ) ;
F_23 ( V_6 , V_40 , 1 ) ;
}
static void F_28 ( struct V_4 * V_6 )
{
F_23 ( V_6 , V_20 , 1 ) ;
F_22 ( V_6 , V_22 , 1 ) ;
F_23 ( V_6 , V_22 , 1 ) ;
F_23 ( V_6 , V_30 , 1 ) ;
}
static int F_29 ( struct V_1 * V_43 )
{
struct V_2 * V_3 = & V_43 -> V_3 ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
F_9 ( V_6 , V_12 , V_54 | V_52 | V_53 ) ;
F_9 ( V_6 , V_14 , 0 ) ;
F_9 ( V_6 , V_16 , 0 ) ;
F_9 ( V_6 , V_24 , 0 << V_56
| 512 << V_103
| 5 << V_104
| 0 << V_105 ) ;
F_9 ( V_6 , V_26 , 7 << V_106
| 0 << V_107
| 17 << V_108
| 1 << V_109
| 2 << V_110
| 0 << V_111
| 1 << V_112 ) ;
F_9 ( V_6 , V_40 , 1 << V_59 ) ;
F_9 ( V_6 , V_36 ,
( V_6 -> V_37 & ~ ( 1 << V_113 ) )
| 0 << V_113 ) ;
F_9 ( V_6 , V_32 ,
( V_6 -> V_33 & ~ ( 0xFF << V_114 ) )
| V_115 << V_114 ) ;
F_9 ( V_6 , V_20 , 1 ) ;
F_9 ( V_6 , V_34 , V_6 -> V_33 ) ;
F_9 ( V_6 , V_38 , V_6 -> V_37 ) ;
F_23 ( V_6 , V_36 , 1 ) ;
F_23 ( V_6 , V_32 , 1 ) ;
V_6 -> V_116 = 512 ;
memset ( V_6 -> V_117 , 0xff , V_6 -> V_116 ) ;
F_26 ( V_6 ) ;
F_24 ( V_6 , V_118 , V_6 -> V_117 ,
V_6 -> V_116 ) ;
F_23 ( V_6 , V_34 , 1 ) ;
F_23 ( V_6 , V_38 , 1 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_43 , int V_119 )
{
struct V_2 * V_3 = & V_43 -> V_3 ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
F_9 ( V_6 , V_12 ,
V_120 | V_52 | V_53 ) ;
F_9 ( V_6 , V_14 , V_119 ) ;
F_9 ( V_6 , V_16 , 0 ) ;
F_9 ( V_6 , V_24 ,
V_43 -> V_57 & ~ ( 7 << V_56 ) ) ;
F_9 ( V_6 , V_26 , V_43 -> V_58 ) ;
F_9 ( V_6 , V_20 , 1 ) ;
F_9 ( V_6 , V_22 , V_43 -> V_23 ) ;
F_9 ( V_6 , V_30 , V_43 -> V_31 ) ;
F_23 ( V_6 , V_12 , 3 ) ;
F_23 ( V_6 , V_24 , 2 ) ;
F_23 ( V_6 , V_20 , 1 ) ;
F_22 ( V_6 , V_22 , 1 ) ;
F_23 ( V_6 , V_22 , 1 ) ;
F_23 ( V_6 , V_30 , 1 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_43 , int V_44 )
{
struct V_2 * V_3 = & V_43 -> V_3 ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
if ( V_44 == - 1 )
return 0 ;
F_9 ( V_6 , V_12 , V_121 ) ;
F_9 ( V_6 , V_14 , V_44 ) ;
F_9 ( V_6 , V_16 , 0 ) ;
F_9 ( V_6 , V_18 , V_122 ) ;
F_9 ( V_6 , V_20 , 1 ) ;
F_23 ( V_6 , V_12 , 4 ) ;
F_23 ( V_6 , V_20 , 1 ) ;
F_22 ( V_6 , V_99 , 1 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_43 )
{
struct V_2 * V_3 = & V_43 -> V_3 ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
F_9 ( V_6 , V_12 , V_123 ) ;
F_9 ( V_6 , V_20 , 1 ) ;
F_23 ( V_6 , V_12 , 1 ) ;
F_23 ( V_6 , V_20 , 1 ) ;
F_22 ( V_6 , V_22 , 1 ) ;
return 0 ;
}
static int F_33 ( struct V_4 * V_6 )
{
struct V_64 * V_65 ;
T_5 V_124 = 0 ;
F_34 (desc, &nandc->desc_list, node)
V_124 = F_35 ( V_65 -> V_67 ) ;
if ( F_36 ( V_6 -> V_93 , V_124 ) != V_125 )
return - V_126 ;
return 0 ;
}
static void F_37 ( struct V_4 * V_6 )
{
struct V_64 * V_65 , * V_127 ;
F_38 (desc, n, &nandc->desc_list, node) {
F_39 ( & V_65 -> V_95 ) ;
F_40 ( V_6 -> V_82 , & V_65 -> V_69 , 1 , V_65 -> V_78 ) ;
F_21 ( V_65 ) ;
}
}
static void F_41 ( struct V_4 * V_6 )
{
V_6 -> V_101 = 0 ;
memset ( V_6 -> V_100 , 0 ,
V_128 * sizeof( * V_6 -> V_100 ) ) ;
}
static void F_42 ( struct V_1 * V_43 , int V_129 )
{
struct V_2 * V_3 = & V_43 -> V_3 ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
V_6 -> V_116 = 0 ;
V_6 -> V_130 = 0 ;
V_43 -> V_50 = false ;
V_43 -> V_131 = V_129 ;
F_41 ( V_6 ) ;
}
static void F_43 ( struct V_1 * V_43 , int V_129 )
{
struct V_2 * V_3 = & V_43 -> V_3 ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
struct V_132 * V_133 = & V_3 -> V_133 ;
int V_48 ;
int V_134 ;
V_48 = V_129 == V_135 ? V_133 -> V_136 : 1 ;
for ( V_134 = 0 ; V_134 < V_48 ; V_134 ++ ) {
T_1 V_137 = F_44 ( V_6 -> V_100 [ V_134 ] ) ;
if ( V_137 & V_138 )
V_43 -> V_139 &= ~ V_140 ;
if ( V_137 & V_141 || ( V_134 == ( V_48 - 1 ) &&
( V_137 &
V_142 ) ) )
V_43 -> V_139 |= V_143 ;
}
}
static void F_45 ( struct V_1 * V_43 , int V_129 )
{
struct V_2 * V_3 = & V_43 -> V_3 ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
switch ( V_129 ) {
case V_144 :
memcpy ( V_6 -> V_117 , V_6 -> V_100 ,
V_6 -> V_116 ) ;
break;
case V_135 :
case V_145 :
F_43 ( V_43 , V_129 ) ;
break;
default:
break;
}
}
static void F_46 ( struct V_146 * V_147 , unsigned int V_129 ,
int V_44 , int V_119 )
{
struct V_2 * V_3 = F_47 ( V_147 ) ;
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_132 * V_133 = & V_3 -> V_133 ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
bool V_148 = false ;
int V_74 = 0 ;
F_42 ( V_43 , V_129 ) ;
switch ( V_129 ) {
case V_149 :
V_74 = F_32 ( V_43 ) ;
V_148 = true ;
break;
case V_144 :
V_6 -> V_116 = 4 ;
V_74 = F_31 ( V_43 , V_44 ) ;
V_148 = true ;
break;
case V_115 :
V_74 = F_29 ( V_43 ) ;
V_148 = true ;
break;
case V_145 :
V_74 = F_30 ( V_43 , V_119 ) ;
V_148 = true ;
break;
case V_150 :
F_48 ( V_44 != 0 ) ;
V_43 -> V_50 = true ;
F_11 ( V_43 , 0 , V_119 ) ;
F_12 ( V_43 , V_133 -> V_136 , true ) ;
break;
case V_151 :
F_48 ( V_44 != 0 ) ;
F_11 ( V_43 , 0 , V_119 ) ;
break;
case V_135 :
case V_152 :
case V_153 :
default:
break;
}
if ( V_74 ) {
F_18 ( V_6 -> V_82 , L_3 ,
V_129 ) ;
F_37 ( V_6 ) ;
return;
}
if ( V_148 ) {
V_74 = F_33 ( V_6 ) ;
if ( V_74 )
F_18 ( V_6 -> V_82 ,
L_4 ,
V_129 ) ;
}
F_37 ( V_6 ) ;
F_45 ( V_43 , V_129 ) ;
}
static bool F_49 ( T_4 * V_154 , int V_155 )
{
T_4 V_156 , V_157 ;
V_156 = V_154 [ 3 ] ;
V_157 = V_154 [ 175 ] ;
if ( ( V_156 == 0x54 && V_157 == 0xff ) ||
( V_156 == 0xff && V_157 == 0x54 ) ) {
V_154 [ 3 ] = 0xff ;
V_154 [ 175 ] = 0xff ;
}
if ( F_50 ( V_154 , 0xff , V_155 ) ) {
V_154 [ 3 ] = V_156 ;
V_154 [ 175 ] = V_157 ;
return false ;
}
return true ;
}
static int F_51 ( struct V_1 * V_43 , T_4 * V_154 ,
T_4 * V_158 )
{
struct V_2 * V_3 = & V_43 -> V_3 ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
struct V_146 * V_147 = F_52 ( V_3 ) ;
struct V_132 * V_133 = & V_3 -> V_133 ;
unsigned int V_159 = 0 ;
struct V_160 * V_161 ;
int V_134 ;
V_161 = (struct V_160 * ) V_6 -> V_100 ;
for ( V_134 = 0 ; V_134 < V_133 -> V_136 ; V_134 ++ , V_161 ++ ) {
T_1 V_162 , V_163 , V_164 ;
int V_155 , V_165 ;
if ( V_134 == ( V_133 -> V_136 - 1 ) ) {
V_155 = V_133 -> V_62 - ( ( V_133 -> V_136 - 1 ) << 2 ) ;
V_165 = V_133 -> V_136 << 2 ;
} else {
V_155 = V_43 -> V_166 ;
V_165 = 0 ;
}
V_162 = F_44 ( V_161 -> V_162 ) ;
V_163 = F_44 ( V_161 -> V_163 ) ;
V_164 = F_44 ( V_161 -> V_164 ) ;
if ( V_162 & ( V_141 | V_138 ) ) {
bool V_167 ;
if ( V_43 -> V_168 ) {
V_167 = ( V_164 & V_169 ) == V_169 ?
true : false ;
} else {
V_167 = F_49 ( V_154 ,
V_155 ) ;
}
if ( V_167 ) {
V_154 += V_155 ;
if ( V_158 )
V_158 += V_165 + V_133 -> V_170 ;
continue;
}
if ( V_163 & V_171 ) {
int V_74 , V_172 , V_173 ;
void * V_174 ;
V_174 = V_158 ? V_158 + V_165 : NULL ;
V_172 = V_158 ? V_43 -> V_175 : 0 ;
V_173 = V_158 ? V_165 : 0 ;
V_74 = F_53 ( V_154 ,
V_155 , V_174 , V_172 , V_158 ,
V_173 , V_133 -> V_176 ) ;
if ( V_74 < 0 ) {
V_147 -> V_177 . V_178 ++ ;
} else {
V_147 -> V_177 . V_179 += V_74 ;
V_159 =
F_54 (unsigned int, max_bitflips, ret) ;
}
}
} else {
unsigned int V_180 ;
V_180 = V_163 & V_181 ;
V_147 -> V_177 . V_179 += V_180 ;
V_159 = F_55 ( V_159 , V_180 ) ;
}
V_154 += V_155 ;
if ( V_158 )
V_158 += V_165 + V_133 -> V_170 ;
}
return V_159 ;
}
static int F_56 ( struct V_1 * V_43 , T_4 * V_154 ,
T_4 * V_158 )
{
struct V_2 * V_3 = & V_43 -> V_3 ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
struct V_132 * V_133 = & V_3 -> V_133 ;
int V_134 , V_74 ;
for ( V_134 = 0 ; V_134 < V_133 -> V_136 ; V_134 ++ ) {
int V_182 , V_183 ;
if ( V_134 == ( V_133 -> V_136 - 1 ) ) {
V_182 = V_133 -> V_62 - ( ( V_133 -> V_136 - 1 ) << 2 ) ;
V_183 = ( V_133 -> V_136 << 2 ) + V_43 -> V_175 +
V_43 -> V_184 ;
} else {
V_182 = V_43 -> V_166 ;
V_183 = V_43 -> V_175 + V_43 -> V_184 ;
}
F_26 ( V_6 ) ;
if ( V_154 )
F_24 ( V_6 , V_118 , V_154 ,
V_182 ) ;
if ( V_158 ) {
int V_185 ;
for ( V_185 = 0 ; V_185 < V_43 -> V_186 ; V_185 ++ )
* V_158 ++ = 0xff ;
F_24 ( V_6 , V_118 + V_182 ,
V_158 , V_183 ) ;
}
if ( V_154 )
V_154 += V_182 ;
if ( V_158 )
V_158 += V_183 ;
}
V_74 = F_33 ( V_6 ) ;
if ( V_74 )
F_18 ( V_6 -> V_82 , L_5 ) ;
F_37 ( V_6 ) ;
return V_74 ;
}
static int F_57 ( struct V_1 * V_43 , int V_45 )
{
struct V_2 * V_3 = & V_43 -> V_3 ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
struct V_132 * V_133 = & V_3 -> V_133 ;
int V_62 ;
int V_74 ;
F_41 ( V_6 ) ;
V_62 = V_43 -> V_50 ? V_43 -> V_166 : V_43 -> V_187 ;
memset ( V_6 -> V_117 , 0xff , V_62 ) ;
F_11 ( V_43 , V_43 -> V_187 * ( V_133 -> V_136 - 1 ) , V_45 ) ;
F_12 ( V_43 , 1 , true ) ;
F_26 ( V_6 ) ;
F_24 ( V_6 , V_118 , V_6 -> V_117 , V_62 ) ;
V_74 = F_33 ( V_6 ) ;
if ( V_74 )
F_18 ( V_6 -> V_82 , L_6 ) ;
F_37 ( V_6 ) ;
return V_74 ;
}
static int F_58 ( struct V_146 * V_147 , struct V_2 * V_3 ,
T_6 * V_161 , int V_188 , int V_45 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
T_4 * V_154 , * V_158 = NULL ;
int V_74 ;
V_154 = V_161 ;
V_158 = V_188 ? V_3 -> V_189 : NULL ;
V_74 = F_56 ( V_43 , V_154 , V_158 ) ;
if ( V_74 ) {
F_18 ( V_6 -> V_82 , L_7 ) ;
return V_74 ;
}
return F_51 ( V_43 , V_154 , V_158 ) ;
}
static int F_59 ( struct V_146 * V_147 ,
struct V_2 * V_3 , T_6 * V_161 ,
int V_188 , int V_45 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
T_4 * V_154 , * V_158 ;
struct V_132 * V_133 = & V_3 -> V_133 ;
int V_134 , V_74 ;
V_154 = V_161 ;
V_158 = V_3 -> V_189 ;
V_43 -> V_50 = false ;
F_12 ( V_43 , V_133 -> V_136 , true ) ;
for ( V_134 = 0 ; V_134 < V_133 -> V_136 ; V_134 ++ ) {
int V_190 , V_191 , V_192 , V_193 ;
int V_60 = V_118 ;
V_190 = V_147 -> V_194 - V_43 -> V_187 * ( V_133 -> V_136 - 1 ) ;
V_192 = V_43 -> V_186 ;
if ( V_134 == ( V_133 -> V_136 - 1 ) ) {
V_191 = V_133 -> V_62 - V_190 -
( ( V_133 -> V_136 - 1 ) << 2 ) ;
V_193 = ( V_133 -> V_136 << 2 ) + V_43 -> V_175 +
V_43 -> V_184 ;
} else {
V_191 = V_43 -> V_166 - V_190 ;
V_193 = V_43 -> V_175 + V_43 -> V_184 ;
}
F_26 ( V_6 ) ;
F_24 ( V_6 , V_60 , V_154 , V_190 ) ;
V_60 += V_190 ;
V_154 += V_190 ;
F_24 ( V_6 , V_60 , V_158 , V_192 ) ;
V_60 += V_192 ;
V_158 += V_192 ;
F_24 ( V_6 , V_60 , V_154 , V_191 ) ;
V_60 += V_191 ;
V_154 += V_191 ;
F_24 ( V_6 , V_60 , V_158 , V_193 ) ;
V_158 += V_193 ;
}
V_74 = F_33 ( V_6 ) ;
if ( V_74 )
F_18 ( V_6 -> V_82 , L_8 ) ;
F_37 ( V_6 ) ;
return 0 ;
}
static int F_60 ( struct V_146 * V_147 , struct V_2 * V_3 ,
int V_45 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
struct V_132 * V_133 = & V_3 -> V_133 ;
int V_74 ;
F_41 ( V_6 ) ;
V_43 -> V_50 = true ;
F_11 ( V_43 , 0 , V_45 ) ;
F_12 ( V_43 , V_133 -> V_136 , true ) ;
V_74 = F_56 ( V_43 , NULL , V_3 -> V_189 ) ;
if ( V_74 )
F_18 ( V_6 -> V_82 , L_9 ) ;
return V_74 ;
}
static int F_61 ( struct V_146 * V_147 , struct V_2 * V_3 ,
const T_6 * V_161 , int V_188 , int V_45 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
struct V_132 * V_133 = & V_3 -> V_133 ;
T_4 * V_154 , * V_158 ;
int V_134 , V_74 ;
F_41 ( V_6 ) ;
V_154 = ( T_4 * ) V_161 ;
V_158 = V_3 -> V_189 ;
V_43 -> V_50 = true ;
F_12 ( V_43 , V_133 -> V_136 , false ) ;
for ( V_134 = 0 ; V_134 < V_133 -> V_136 ; V_134 ++ ) {
int V_182 , V_183 ;
if ( V_134 == ( V_133 -> V_136 - 1 ) ) {
V_182 = V_133 -> V_62 - ( ( V_133 -> V_136 - 1 ) << 2 ) ;
V_183 = ( V_133 -> V_136 << 2 ) + V_43 -> V_175 +
V_43 -> V_184 ;
} else {
V_182 = V_43 -> V_166 ;
V_183 = V_133 -> V_170 ;
}
F_27 ( V_6 ) ;
F_25 ( V_6 , V_118 , V_154 , V_182 ) ;
if ( V_134 == ( V_133 -> V_136 - 1 ) ) {
V_158 += V_43 -> V_186 ;
F_25 ( V_6 , V_118 + V_182 ,
V_158 , V_183 ) ;
}
F_28 ( V_6 ) ;
V_154 += V_182 ;
V_158 += V_183 ;
}
V_74 = F_33 ( V_6 ) ;
if ( V_74 )
F_18 ( V_6 -> V_82 , L_10 ) ;
F_37 ( V_6 ) ;
return V_74 ;
}
static int F_62 ( struct V_146 * V_147 ,
struct V_2 * V_3 , const T_6 * V_161 ,
int V_188 , int V_45 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
struct V_132 * V_133 = & V_3 -> V_133 ;
T_4 * V_154 , * V_158 ;
int V_134 , V_74 ;
F_41 ( V_6 ) ;
V_154 = ( T_4 * ) V_161 ;
V_158 = V_3 -> V_189 ;
V_43 -> V_50 = false ;
F_12 ( V_43 , V_133 -> V_136 , false ) ;
for ( V_134 = 0 ; V_134 < V_133 -> V_136 ; V_134 ++ ) {
int V_190 , V_191 , V_192 , V_193 ;
int V_60 = V_118 ;
V_190 = V_147 -> V_194 - V_43 -> V_187 * ( V_133 -> V_136 - 1 ) ;
V_192 = V_43 -> V_186 ;
if ( V_134 == ( V_133 -> V_136 - 1 ) ) {
V_191 = V_133 -> V_62 - V_190 -
( ( V_133 -> V_136 - 1 ) << 2 ) ;
V_193 = ( V_133 -> V_136 << 2 ) + V_43 -> V_175 +
V_43 -> V_184 ;
} else {
V_191 = V_43 -> V_166 - V_190 ;
V_193 = V_43 -> V_175 + V_43 -> V_184 ;
}
F_27 ( V_6 ) ;
F_25 ( V_6 , V_60 , V_154 , V_190 ) ;
V_60 += V_190 ;
V_154 += V_190 ;
F_25 ( V_6 , V_60 , V_158 , V_192 ) ;
V_60 += V_192 ;
V_158 += V_192 ;
F_25 ( V_6 , V_60 , V_154 , V_191 ) ;
V_60 += V_191 ;
V_154 += V_191 ;
F_25 ( V_6 , V_60 , V_158 , V_193 ) ;
V_158 += V_193 ;
F_28 ( V_6 ) ;
}
V_74 = F_33 ( V_6 ) ;
if ( V_74 )
F_18 ( V_6 -> V_82 , L_11 ) ;
F_37 ( V_6 ) ;
return V_74 ;
}
static int F_63 ( struct V_146 * V_147 , struct V_2 * V_3 ,
int V_45 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
struct V_132 * V_133 = & V_3 -> V_133 ;
T_4 * V_195 = V_3 -> V_189 ;
int V_182 , V_183 ;
int V_74 , V_139 = 0 ;
V_43 -> V_50 = true ;
V_74 = F_57 ( V_43 , V_45 ) ;
if ( V_74 )
return V_74 ;
F_41 ( V_6 ) ;
V_182 = V_133 -> V_62 - ( ( V_133 -> V_136 - 1 ) << 2 ) ;
V_183 = V_147 -> V_196 ;
F_64 ( V_147 , V_6 -> V_117 + V_182 , V_195 ,
0 , V_147 -> V_196 ) ;
F_11 ( V_43 , V_43 -> V_187 * ( V_133 -> V_136 - 1 ) , V_45 ) ;
F_12 ( V_43 , 1 , false ) ;
F_27 ( V_6 ) ;
F_25 ( V_6 , V_118 , V_6 -> V_117 ,
V_182 + V_183 ) ;
F_28 ( V_6 ) ;
V_74 = F_33 ( V_6 ) ;
F_37 ( V_6 ) ;
if ( V_74 ) {
F_18 ( V_6 -> V_82 , L_12 ) ;
return - V_197 ;
}
V_3 -> V_198 ( V_147 , V_135 , - 1 , - 1 ) ;
V_139 = V_3 -> V_199 ( V_147 , V_3 ) ;
return V_139 & V_143 ? - V_197 : 0 ;
}
static int F_65 ( struct V_146 * V_147 , T_7 V_200 )
{
struct V_2 * V_3 = F_47 ( V_147 ) ;
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
struct V_132 * V_133 = & V_3 -> V_133 ;
int V_45 , V_74 , V_201 , V_202 = 0 ;
T_1 V_137 ;
V_45 = ( int ) ( V_200 >> V_3 -> V_203 ) & V_3 -> V_204 ;
V_43 -> V_50 = false ;
V_74 = F_57 ( V_43 , V_45 ) ;
if ( V_74 )
goto V_83;
V_137 = F_44 ( V_6 -> V_100 [ 0 ] ) ;
if ( V_137 & ( V_141 | V_138 ) ) {
F_66 ( V_6 -> V_82 , L_13 ) ;
goto V_83;
}
V_201 = V_147 -> V_194 - V_43 -> V_187 * ( V_133 -> V_136 - 1 ) ;
V_202 = V_6 -> V_117 [ V_201 ] != 0xff ;
if ( V_3 -> V_46 & V_47 )
V_202 = V_202 || ( V_6 -> V_117 [ V_201 + 1 ] != 0xff ) ;
V_83:
return V_202 ;
}
static int F_67 ( struct V_146 * V_147 , T_7 V_200 )
{
struct V_2 * V_3 = F_47 ( V_147 ) ;
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
struct V_132 * V_133 = & V_3 -> V_133 ;
int V_45 , V_74 , V_139 = 0 ;
F_41 ( V_6 ) ;
memset ( V_6 -> V_117 , 0x00 , V_43 -> V_187 ) ;
V_45 = ( int ) ( V_200 >> V_3 -> V_203 ) & V_3 -> V_204 ;
V_43 -> V_50 = false ;
F_11 ( V_43 , V_43 -> V_187 * ( V_133 -> V_136 - 1 ) , V_45 ) ;
F_12 ( V_43 , 1 , false ) ;
F_27 ( V_6 ) ;
F_25 ( V_6 , V_118 , V_6 -> V_117 , V_43 -> V_187 ) ;
F_28 ( V_6 ) ;
V_74 = F_33 ( V_6 ) ;
F_37 ( V_6 ) ;
if ( V_74 ) {
F_18 ( V_6 -> V_82 , L_14 ) ;
return - V_197 ;
}
V_3 -> V_198 ( V_147 , V_135 , - 1 , - 1 ) ;
V_139 = V_3 -> V_199 ( V_147 , V_3 ) ;
return V_139 & V_143 ? - V_197 : 0 ;
}
static T_6 F_68 ( struct V_146 * V_147 )
{
struct V_2 * V_3 = F_47 ( V_147 ) ;
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
T_4 * V_161 = V_6 -> V_117 ;
T_4 V_74 = 0x0 ;
if ( V_43 -> V_131 == V_152 ) {
V_74 = V_43 -> V_139 ;
V_43 -> V_139 = V_205 | V_140 ;
return V_74 ;
}
if ( V_6 -> V_130 < V_6 -> V_116 )
V_74 = V_161 [ V_6 -> V_130 ++ ] ;
return V_74 ;
}
static void F_69 ( struct V_146 * V_147 , T_6 * V_161 , int V_206 )
{
struct V_2 * V_3 = F_47 ( V_147 ) ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
int V_207 = F_70 ( V_208 , V_206 , V_6 -> V_116 - V_6 -> V_130 ) ;
memcpy ( V_161 , V_6 -> V_117 + V_6 -> V_130 , V_207 ) ;
V_6 -> V_130 += V_207 ;
}
static void F_71 ( struct V_146 * V_147 , const T_6 * V_161 ,
int V_206 )
{
struct V_2 * V_3 = F_47 ( V_147 ) ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
int V_207 = F_70 ( V_208 , V_206 , V_6 -> V_116 - V_6 -> V_130 ) ;
memcpy ( V_6 -> V_117 + V_6 -> V_130 , V_161 , V_207 ) ;
V_6 -> V_130 += V_207 ;
}
static void F_72 ( struct V_146 * V_147 , int V_209 )
{
struct V_2 * V_3 = F_47 ( V_147 ) ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
if ( V_209 <= 0 )
return;
F_66 ( V_6 -> V_82 , L_15 ) ;
}
static int F_73 ( struct V_146 * V_147 , int V_210 ,
struct V_211 * V_212 )
{
struct V_2 * V_3 = F_47 ( V_147 ) ;
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_132 * V_133 = & V_3 -> V_133 ;
if ( V_210 > 1 )
return - V_213 ;
if ( ! V_210 ) {
V_212 -> V_214 = ( V_133 -> V_170 * ( V_133 -> V_136 - 1 ) ) +
V_43 -> V_186 ;
V_212 -> V_7 = 0 ;
} else {
V_212 -> V_214 = V_43 -> V_175 + V_43 -> V_184 ;
V_212 -> V_7 = V_147 -> V_215 - V_212 -> V_214 ;
}
return 0 ;
}
static int F_74 ( struct V_146 * V_147 , int V_210 ,
struct V_211 * V_212 )
{
struct V_2 * V_3 = F_47 ( V_147 ) ;
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_132 * V_133 = & V_3 -> V_133 ;
if ( V_210 )
return - V_213 ;
V_212 -> V_214 = V_133 -> V_136 * 4 ;
V_212 -> V_7 = ( ( V_133 -> V_136 - 1 ) * V_133 -> V_170 ) + V_43 -> V_186 ;
return 0 ;
}
static int F_75 ( struct V_1 * V_43 )
{
struct V_2 * V_3 = & V_43 -> V_3 ;
struct V_146 * V_147 = F_52 ( V_3 ) ;
struct V_132 * V_133 = & V_3 -> V_133 ;
struct V_4 * V_6 = F_3 ( V_3 ) ;
int V_216 , V_217 ;
bool V_218 ;
int V_219 = 1 ;
if ( V_133 -> V_62 != V_220 ) {
F_18 ( V_6 -> V_82 , L_16 ) ;
return - V_94 ;
}
V_218 = V_3 -> V_46 & V_47 ? true : false ;
if ( V_133 -> V_176 >= 8 ) {
V_43 -> V_168 = true ;
V_219 = 1 ;
if ( V_218 ) {
V_43 -> V_175 = 14 ;
V_43 -> V_184 = 0 ;
V_43 -> V_186 = 2 ;
} else {
V_43 -> V_175 = 13 ;
V_43 -> V_184 = 2 ;
V_43 -> V_186 = 1 ;
}
} else {
if ( V_6 -> V_221 & V_222 ) {
V_43 -> V_168 = true ;
V_219 = 0 ;
if ( V_218 ) {
V_43 -> V_175 = 8 ;
V_43 -> V_184 = 2 ;
V_43 -> V_186 = 2 ;
} else {
V_43 -> V_175 = 7 ;
V_43 -> V_184 = 4 ;
V_43 -> V_186 = 1 ;
}
} else {
V_43 -> V_175 = 10 ;
if ( V_218 ) {
V_43 -> V_184 = 0 ;
V_43 -> V_186 = 2 ;
} else {
V_43 -> V_184 = 1 ;
V_43 -> V_186 = 1 ;
}
}
}
V_133 -> V_170 = V_43 -> V_175 + V_43 -> V_184 + V_43 -> V_186 ;
V_133 -> V_223 = F_58 ;
V_133 -> V_224 = F_59 ;
V_133 -> V_225 = F_60 ;
V_133 -> V_226 = F_61 ;
V_133 -> V_227 = F_62 ;
V_133 -> V_228 = F_63 ;
V_133 -> V_229 = V_230 ;
F_76 ( V_147 , & V_231 ) ;
V_216 = V_147 -> V_194 / V_133 -> V_62 ;
V_43 -> V_166 = 516 ;
V_43 -> V_187 = V_43 -> V_166 + V_133 -> V_170 ;
if ( V_133 -> V_170 * ( V_147 -> V_194 / V_133 -> V_62 ) > V_147 -> V_215 ) {
F_18 ( V_6 -> V_82 , L_17 ) ;
return - V_94 ;
}
V_217 = V_147 -> V_194 - V_43 -> V_187 * ( V_216 - 1 ) + 1 ;
V_43 -> V_25 = ( V_216 - 1 ) << V_56
| V_43 -> V_166 << V_103
| 0 << V_232
| 5 << V_104
| V_43 -> V_175 << V_233
| 0 << V_234
| 1 << V_235
| V_43 -> V_184 << V_105 ;
V_43 -> V_27 = 7 << V_106
| 0 << V_107
| V_217 << V_108
| 0 << V_109
| 2 << V_110
| V_218 << V_111
| V_43 -> V_168 << V_236 ;
V_43 -> V_57 = ( V_216 - 1 ) << V_56
| V_43 -> V_187 << V_103
| 5 << V_104
| 0 << V_105 ;
V_43 -> V_58 = 7 << V_106
| 0 << V_107
| 17 << V_108
| 1 << V_109
| 2 << V_110
| V_218 << V_111
| 1 << V_112 ;
V_43 -> V_29 = V_43 -> V_168 << V_59
| 0 << V_237
| V_43 -> V_166 << V_238
| 1 << V_239
| V_219 << V_240
| V_43 -> V_175 << V_241 ;
V_43 -> V_41 = 0x203 << V_242 ;
V_43 -> V_23 = V_243 ;
V_43 -> V_31 = 0xc0 ;
F_77 ( V_6 -> V_82 ,
L_18 ,
V_43 -> V_25 , V_43 -> V_27 , V_43 -> V_41 , V_43 -> V_29 ,
V_43 -> V_187 , V_43 -> V_166 , V_133 -> V_176 , V_133 -> V_170 ,
V_216 ) ;
return 0 ;
}
static int F_78 ( struct V_4 * V_6 )
{
int V_74 ;
V_74 = F_79 ( V_6 -> V_82 , F_80 ( 32 ) ) ;
if ( V_74 ) {
F_18 ( V_6 -> V_82 , L_19 ) ;
return V_74 ;
}
V_6 -> V_244 = 532 ;
V_6 -> V_117 = F_81 ( V_6 -> V_82 , V_6 -> V_244 ,
V_75 ) ;
if ( ! V_6 -> V_117 )
return - V_76 ;
V_6 -> V_11 = F_81 ( V_6 -> V_82 , sizeof( * V_6 -> V_11 ) ,
V_75 ) ;
if ( ! V_6 -> V_11 )
return - V_76 ;
V_6 -> V_100 = F_81 ( V_6 -> V_82 ,
V_128 * sizeof( * V_6 -> V_100 ) ,
V_75 ) ;
if ( ! V_6 -> V_100 )
return - V_76 ;
V_6 -> V_93 = F_82 ( V_6 -> V_82 , L_20 ) ;
if ( ! V_6 -> V_93 ) {
F_18 ( V_6 -> V_82 , L_21 ) ;
return - V_245 ;
}
F_83 ( & V_6 -> V_96 ) ;
F_83 ( & V_6 -> V_246 ) ;
F_84 ( & V_6 -> V_5 . V_247 ) ;
F_85 ( & V_6 -> V_5 . V_248 ) ;
return 0 ;
}
static void F_86 ( struct V_4 * V_6 )
{
F_87 ( V_6 -> V_93 ) ;
}
static int F_88 ( struct V_4 * V_6 )
{
F_6 ( V_6 , V_249 , 0 ) ;
F_6 ( V_6 , V_18 , V_122 ) ;
V_6 -> V_33 = F_4 ( V_6 , V_32 ) ;
V_6 -> V_37 = F_4 ( V_6 , V_36 ) ;
return 0 ;
}
static int F_89 ( struct V_4 * V_6 ,
struct V_1 * V_43 ,
struct V_250 * V_251 )
{
struct V_2 * V_3 = & V_43 -> V_3 ;
struct V_146 * V_147 = F_52 ( V_3 ) ;
struct V_252 * V_82 = V_6 -> V_82 ;
int V_74 ;
V_74 = F_90 ( V_251 , L_22 , & V_43 -> V_253 ) ;
if ( V_74 ) {
F_18 ( V_82 , L_23 ) ;
return - V_254 ;
}
F_91 ( V_3 , V_251 ) ;
V_147 -> V_255 = F_92 ( V_82 , V_75 , L_24 , V_43 -> V_253 ) ;
V_147 -> V_256 = V_257 ;
V_147 -> V_82 . V_258 = V_82 ;
V_3 -> V_198 = F_46 ;
V_3 -> V_259 = F_72 ;
V_3 -> V_260 = F_68 ;
V_3 -> V_261 = F_69 ;
V_3 -> V_262 = F_71 ;
V_3 -> V_263 = F_65 ;
V_3 -> V_264 = F_67 ;
V_3 -> V_5 = & V_6 -> V_5 ;
V_3 -> V_46 |= V_265 | V_266 |
V_267 ;
V_43 -> V_139 = V_205 | V_140 ;
V_74 = F_93 ( V_147 , 1 , NULL ) ;
if ( V_74 )
return V_74 ;
V_74 = F_75 ( V_43 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_94 ( V_147 ) ;
if ( V_74 )
return V_74 ;
return F_95 ( V_147 , NULL , 0 ) ;
}
static int F_96 ( struct V_268 * V_269 )
{
struct V_4 * V_6 = F_97 ( V_269 ) ;
struct V_250 * V_270 = V_6 -> V_82 -> V_271 ;
int V_74 ;
V_74 = F_90 ( V_270 , L_25 , & V_6 -> V_92 ) ;
if ( V_74 ) {
F_18 ( V_6 -> V_82 , L_26 ) ;
return V_74 ;
}
V_74 = F_90 ( V_270 , L_27 , & V_6 -> V_89 ) ;
if ( V_74 ) {
F_18 ( V_6 -> V_82 , L_28 ) ;
return V_74 ;
}
return 0 ;
}
static int F_98 ( struct V_268 * V_269 )
{
struct V_4 * V_6 ;
struct V_1 * V_43 ;
const void * V_272 ;
struct V_252 * V_82 = & V_269 -> V_82 ;
struct V_250 * V_251 = V_82 -> V_271 , * V_273 ;
struct V_274 * V_275 ;
int V_74 ;
V_6 = F_81 ( & V_269 -> V_82 , sizeof( * V_6 ) , V_75 ) ;
if ( ! V_6 )
return - V_76 ;
F_99 ( V_269 , V_6 ) ;
V_6 -> V_82 = V_82 ;
V_272 = F_100 ( V_82 ) ;
if ( ! V_272 ) {
F_18 ( & V_269 -> V_82 , L_29 ) ;
return - V_245 ;
}
V_6 -> V_221 = ( unsigned long ) V_272 ;
V_275 = F_101 ( V_269 , V_276 , 0 ) ;
V_6 -> V_8 = F_102 ( V_82 , V_275 ) ;
if ( F_103 ( V_6 -> V_8 ) )
return F_104 ( V_6 -> V_8 ) ;
V_6 -> V_87 = F_105 ( V_82 , ( V_277 ) V_275 -> V_278 ) ;
V_6 -> V_279 = F_106 ( V_82 , L_30 ) ;
if ( F_103 ( V_6 -> V_279 ) )
return F_104 ( V_6 -> V_279 ) ;
V_6 -> V_280 = F_106 ( V_82 , L_31 ) ;
if ( F_103 ( V_6 -> V_280 ) )
return F_104 ( V_6 -> V_280 ) ;
V_74 = F_96 ( V_269 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_78 ( V_6 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_107 ( V_6 -> V_279 ) ;
if ( V_74 )
goto V_281;
V_74 = F_107 ( V_6 -> V_280 ) ;
if ( V_74 )
goto V_282;
V_74 = F_88 ( V_6 ) ;
if ( V_74 )
goto V_283;
F_108 (dn, child) {
if ( F_109 ( V_273 , L_32 ) ) {
V_43 = F_81 ( V_82 , sizeof( * V_43 ) , V_75 ) ;
if ( ! V_43 ) {
F_110 ( V_273 ) ;
V_74 = - V_76 ;
goto V_284;
}
V_74 = F_89 ( V_6 , V_43 , V_273 ) ;
if ( V_74 ) {
F_111 ( V_82 , V_43 ) ;
continue;
}
F_20 ( & V_43 -> V_95 , & V_6 -> V_246 ) ;
}
}
if ( F_112 ( & V_6 -> V_246 ) ) {
V_74 = - V_245 ;
goto V_284;
}
return 0 ;
V_284:
F_34 (host, &nandc->host_list, node)
F_113 ( F_52 ( & V_43 -> V_3 ) ) ;
V_283:
F_114 ( V_6 -> V_280 ) ;
V_282:
F_114 ( V_6 -> V_279 ) ;
V_281:
F_86 ( V_6 ) ;
return V_74 ;
}
static int F_115 ( struct V_268 * V_269 )
{
struct V_4 * V_6 = F_97 ( V_269 ) ;
struct V_1 * V_43 ;
F_34 (host, &nandc->host_list, node)
F_113 ( F_52 ( & V_43 -> V_3 ) ) ;
F_86 ( V_6 ) ;
F_114 ( V_6 -> V_280 ) ;
F_114 ( V_6 -> V_279 ) ;
return 0 ;
}
