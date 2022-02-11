static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = NULL ;
struct V_7 * V_8 = NULL ;
struct V_9 V_10 ;
int V_11 = - V_12 ;
T_1 V_13 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . V_14 = F_2 ( V_2 ) ;
V_10 . V_15 = V_4 -> V_15 ;
V_10 . V_16 = V_17 ;
V_11 = F_3 ( V_2 , & V_8 ,
V_18 ,
V_19 , & V_10 ) ;
if ( V_11 )
return V_11 ;
V_6 = & V_8 -> V_20 . V_21 ;
V_6 -> V_22 = F_4 ( V_4 -> V_23 , V_24 ) ;
V_6 -> V_15 = F_5 ( V_4 -> V_15 ) ;
switch ( V_2 -> V_25 . V_26 ) {
case V_27 :
V_6 -> V_26 = V_28 ;
break;
case V_29 :
V_6 -> V_26 = V_30 ;
break;
default:
F_6 ( V_2 , L_1 ,
V_2 -> V_25 . V_26 ) ;
return - V_12 ;
}
V_13 = V_4 -> V_31 . V_32 . V_33 ;
if ( V_13 > V_34 &&
V_13 != V_35 ) {
F_7 ( V_2 ,
V_36 ,
L_2 ,
V_4 -> V_37 ,
V_38 ,
V_13 , V_38 , V_34 ) ;
V_13 = V_34 ;
}
V_6 -> V_39 . V_40 [ V_41 ] = V_38 ;
V_6 -> V_39 . V_42 [ V_41 ] = V_13 ;
F_7 ( V_2 , V_36 ,
L_3 ,
V_4 -> V_37 , V_38 , V_13 ) ;
return F_8 ( V_2 , V_8 , NULL ) ;
}
static int F_9 ( struct V_1 * V_2 ,
T_2 V_43 , T_3 V_44 )
{
struct V_45 * V_6 = NULL ;
struct V_7 * V_8 = NULL ;
struct V_9 V_10 ;
int V_11 = - V_12 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . V_14 = F_2 ( V_2 ) ;
V_10 . V_15 = V_44 ;
V_10 . V_16 = V_17 ;
V_11 = F_3 ( V_2 , & V_8 ,
V_46 ,
V_19 , & V_10 ) ;
if ( V_11 )
return V_11 ;
V_6 = & V_8 -> V_20 . V_47 ;
V_6 -> V_22 = F_4 ( V_43 , V_24 ) ;
return F_8 ( V_2 , V_8 , NULL ) ;
}
static bool F_10 ( struct V_1 * V_2 ,
int V_48 ,
bool V_49 , bool V_50 )
{
if ( ! V_2 -> V_51 ) {
F_6 ( V_2 -> V_52 , L_4 ) ;
return false ;
}
if ( ( V_48 >= V_2 -> V_52 -> V_53 -> V_54 ) ||
( V_48 < 0 ) )
return false ;
if ( ( ! V_2 -> V_51 -> V_55 [ V_48 ] . V_56 ) &&
V_49 )
return false ;
if ( ( V_2 -> V_51 -> V_55 [ V_48 ] . V_57 ) &&
V_50 )
return false ;
return true ;
}
static struct V_3 * F_11 ( struct V_1 * V_2 ,
T_3 V_58 ,
bool V_49 )
{
struct V_3 * V_59 = NULL ;
if ( ! V_2 -> V_51 ) {
F_6 ( V_2 -> V_52 , L_4 ) ;
return NULL ;
}
if ( F_10 ( V_2 , V_58 ,
V_49 , false ) )
V_59 = & V_2 -> V_51 -> V_55 [ V_58 ] ;
else
F_12 ( V_2 , L_5 ,
V_58 ) ;
return V_59 ;
}
static bool F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_3 V_60 )
{
if ( V_60 >= V_4 -> V_61 )
F_7 ( V_2 ,
V_36 ,
L_6 ,
V_4 -> V_37 , V_60 , V_4 -> V_61 ) ;
return V_60 < V_4 -> V_61 ;
}
static bool F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_3 V_62 )
{
if ( V_62 >= V_4 -> V_63 )
F_7 ( V_2 ,
V_36 ,
L_7 ,
V_4 -> V_37 , V_62 , V_4 -> V_63 ) ;
return V_62 < V_4 -> V_63 ;
}
static bool F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_3 V_64 )
{
int V_65 ;
for ( V_65 = 0 ; V_65 < V_4 -> V_66 ; V_65 ++ )
if ( V_4 -> V_67 [ V_65 ] == V_64 )
return true ;
F_7 ( V_2 ,
V_36 ,
L_8 ,
V_4 -> V_37 , V_64 , V_4 -> V_66 ) ;
return false ;
}
static int F_16 ( struct V_1 * V_2 ,
int V_68 , struct V_69 * V_70 )
{
struct V_71 * V_72 ;
int V_73 = sizeof( V_72 -> V_74 ) ;
struct V_75 V_76 ;
struct V_3 * V_4 ;
V_4 = F_11 ( V_2 , ( T_3 ) V_68 , true ) ;
if ( ! V_4 )
return - V_12 ;
if ( ! V_4 -> V_77 )
return - V_12 ;
V_72 = V_4 -> V_78 . V_79 ;
V_72 -> V_80 ++ ;
V_72 -> V_74 = F_17 ( 0 , ( T_1 * ) V_72 + V_73 ,
V_4 -> V_78 . V_81 - V_73 ) ;
F_7 ( V_2 , V_36 ,
L_9 ,
V_72 -> V_80 , V_4 -> V_58 , V_72 -> V_74 ) ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_76 . V_82 = V_83 ;
V_76 . V_84 = V_4 -> V_37 ;
return F_18 ( V_2 , V_70 , V_4 -> V_78 . V_85 ,
V_4 -> V_77 , V_4 -> V_78 . V_81 / 4 ,
& V_76 ) ;
}
static int F_19 ( struct V_86 * V_52 )
{
struct V_87 * V_88 = V_52 -> V_53 ;
int V_89 = V_88 -> V_89 ;
F_7 ( V_52 , V_36 , L_10 , V_89 ) ;
F_20 ( V_52 -> V_90 , V_89 + V_91 , & V_88 -> V_92 ) ;
F_20 ( V_52 -> V_90 ,
V_89 + V_93 , & V_88 -> V_54 ) ;
F_20 ( V_52 -> V_90 ,
V_89 + V_94 , & V_88 -> V_95 ) ;
F_20 ( V_52 -> V_90 , V_89 + V_96 , & V_88 -> V_97 ) ;
if ( V_88 -> V_97 ) {
F_7 ( V_52 ,
V_36 ,
L_11 ) ;
V_88 -> V_97 = 0 ;
}
F_20 ( V_52 -> V_90 ,
V_89 + V_98 , & V_88 -> V_99 ) ;
F_20 ( V_52 -> V_90 ,
V_89 + V_100 , & V_88 -> V_101 ) ;
F_20 ( V_52 -> V_90 ,
V_89 + V_102 , & V_88 -> V_103 ) ;
F_21 ( V_52 -> V_90 ,
V_89 + V_104 , & V_88 -> V_105 ) ;
F_21 ( V_52 -> V_90 , V_89 + V_106 , & V_88 -> V_107 ) ;
F_22 ( V_52 -> V_90 , V_89 + V_108 , & V_88 -> V_109 ) ;
F_7 ( V_52 ,
V_36 ,
L_12 ,
V_88 -> V_110 ,
V_88 -> V_107 ,
V_88 -> V_92 ,
V_88 -> V_54 ,
V_88 -> V_95 ,
V_88 -> V_111 , V_88 -> V_99 , V_88 -> V_101 , V_88 -> V_105 ) ;
if ( V_88 -> V_97 > F_23 ( V_52 ) ||
V_88 -> V_54 > F_23 ( V_52 ) ) {
F_6 ( V_52 ,
L_13 ,
V_88 -> V_97 ) ;
V_88 -> V_97 = 0 ;
V_88 -> V_54 = 0 ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_69 * V_70 )
{
struct V_112 * V_113 ;
T_3 V_114 ;
T_2 V_115 ;
if ( ! V_2 -> V_25 . V_116 ) {
F_12 ( V_2 ,
L_14 ) ;
return;
}
for ( V_114 = 0 ; V_114 < F_25 ( V_2 -> V_52 ) ;
V_114 ++ ) {
V_113 = & V_2 -> V_25 . V_116 -> V_117 . V_118 [ V_114 ] ;
if ( ( V_113 -> V_119 & V_120 ) &&
! ( V_113 -> V_119 & V_121 ) ) {
V_115 = F_26 ( V_2 , V_70 ,
V_122 + V_114 * 4 ) ;
F_27 ( V_115 , V_123 , 0 ) ;
F_28 ( V_2 , V_70 ,
V_122 + 4 * V_114 , V_115 ) ;
}
}
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_87 * V_124 = V_2 -> V_52 -> V_53 ;
struct V_125 * V_53 = V_2 -> V_51 ;
struct V_71 * V_126 ;
T_4 V_127 , V_128 , V_129 ;
union V_130 * V_131 ;
union V_132 * V_133 ;
T_1 V_134 = 0 ;
memset ( V_53 -> V_55 , 0 , sizeof( V_53 -> V_55 ) ) ;
V_133 = V_53 -> V_135 ;
V_127 = V_53 -> V_136 ;
V_131 = V_53 -> V_137 ;
V_128 = V_53 -> V_138 ;
V_126 = V_53 -> V_139 ;
V_129 = V_53 -> V_140 ;
if ( ! V_133 || ! V_131 || ! V_126 ) {
F_12 ( V_2 ,
L_15 ) ;
return;
}
for ( V_134 = 0 ; V_134 < V_124 -> V_54 ; V_134 ++ ) {
struct V_3 * V_59 = & V_53 -> V_55 [ V_134 ] ;
T_2 V_141 ;
V_59 -> V_142 . V_143 = V_133 + V_134 ;
V_59 -> V_142 . V_144 = V_127 + V_134 * sizeof( union V_132 ) ;
V_59 -> V_142 . V_145 = V_131 + V_134 ;
V_59 -> V_142 . V_146 = V_128 + V_134 * sizeof( union V_130 ) ;
V_59 -> V_147 = V_148 ;
V_59 -> V_56 = false ;
V_59 -> V_78 . V_85 = V_134 *
sizeof( struct V_71 ) +
V_129 ;
V_59 -> V_78 . V_79 = V_126 + V_134 ;
V_59 -> V_78 . V_81 = sizeof( struct V_71 ) ;
V_59 -> V_58 = V_134 ;
V_59 -> V_37 = V_134 + V_124 -> V_149 ;
V_141 = F_30 ( V_2 , V_59 -> V_37 ) ;
V_59 -> V_23 = V_141 ;
V_59 -> V_15 = ( V_2 -> V_25 . V_15 & 0xff ) |
( V_59 -> V_37 << 8 ) ;
V_59 -> V_150 = V_134 + 1 ;
V_59 -> V_151 = V_152 ;
V_59 -> V_153 = V_154 ;
}
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_125 * V_53 = V_2 -> V_51 ;
void * * V_155 ;
T_3 V_97 = 0 ;
V_97 = V_2 -> V_52 -> V_53 -> V_54 ;
F_7 ( V_2 , V_36 ,
L_16 , V_97 ) ;
V_53 -> V_156 = sizeof( union V_132 ) * V_97 ;
V_155 = & V_53 -> V_135 ;
* V_155 = F_32 ( & V_2 -> V_52 -> V_90 -> V_157 ,
V_53 -> V_156 ,
& V_53 -> V_136 ,
V_158 ) ;
if ( ! * V_155 )
return - V_159 ;
V_53 -> V_160 = sizeof( union V_130 ) * V_97 ;
V_155 = & V_53 -> V_137 ;
* V_155 = F_32 ( & V_2 -> V_52 -> V_90 -> V_157 ,
V_53 -> V_160 ,
& V_53 -> V_138 ,
V_158 ) ;
if ( ! * V_155 )
return - V_159 ;
V_53 -> V_161 = sizeof( struct V_71 ) *
V_97 ;
V_155 = & V_53 -> V_139 ;
* V_155 = F_32 ( & V_2 -> V_52 -> V_90 -> V_157 ,
V_53 -> V_161 ,
& V_53 -> V_140 ,
V_158 ) ;
if ( ! * V_155 )
return - V_159 ;
F_7 ( V_2 ,
V_36 ,
L_17 ,
V_53 -> V_135 ,
( V_162 ) V_53 -> V_136 ,
V_53 -> V_137 ,
( V_162 ) V_53 -> V_138 ,
V_53 -> V_139 , ( V_162 ) V_53 -> V_140 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_125 * V_53 = V_2 -> V_51 ;
if ( V_2 -> V_51 -> V_135 )
F_34 ( & V_2 -> V_52 -> V_90 -> V_157 ,
V_53 -> V_156 ,
V_53 -> V_135 ,
V_53 -> V_136 ) ;
if ( V_2 -> V_51 -> V_137 )
F_34 ( & V_2 -> V_52 -> V_90 -> V_157 ,
V_53 -> V_160 ,
V_53 -> V_137 ,
V_53 -> V_138 ) ;
if ( V_53 -> V_139 )
F_34 ( & V_2 -> V_52 -> V_90 -> V_157 ,
V_53 -> V_161 ,
V_53 -> V_139 ,
V_53 -> V_140 ) ;
}
int F_35 ( struct V_1 * V_2 )
{
struct V_125 * V_163 ;
if ( ! F_36 ( V_2 ) ) {
F_7 ( V_2 , V_36 ,
L_18 ) ;
return 0 ;
}
V_163 = F_37 ( sizeof( * V_163 ) , V_158 ) ;
if ( ! V_163 )
return - V_159 ;
V_2 -> V_51 = V_163 ;
return F_31 ( V_2 ) ;
}
void F_38 ( struct V_1 * V_2 , struct V_69 * V_70 )
{
if ( ! F_36 ( V_2 ) || ! F_39 ( V_2 ) )
return;
F_29 ( V_2 ) ;
F_24 ( V_2 , V_70 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
if ( F_39 ( V_2 ) ) {
F_33 ( V_2 ) ;
F_41 ( V_2 -> V_51 ) ;
}
}
void F_42 ( struct V_86 * V_52 )
{
F_41 ( V_52 -> V_53 ) ;
V_52 -> V_53 = NULL ;
}
int F_43 ( struct V_1 * V_2 )
{
struct V_86 * V_52 = V_2 -> V_52 ;
int V_89 ;
int V_11 ;
if ( F_44 ( V_2 -> V_52 ) )
return 0 ;
V_89 = F_45 ( V_2 -> V_52 -> V_90 ,
V_164 ) ;
if ( ! V_89 ) {
F_7 ( V_2 , V_36 , L_19 ) ;
return 0 ;
}
V_52 -> V_53 = F_37 ( sizeof( * V_52 -> V_53 ) , V_158 ) ;
if ( ! V_52 -> V_53 )
return - V_159 ;
V_52 -> V_53 -> V_89 = V_89 ;
V_11 = F_19 ( V_52 ) ;
if ( V_11 )
return V_11 ;
if ( ! V_52 -> V_53 -> V_54 ) {
F_7 ( V_2 , V_36 ,
L_20 ) ;
F_41 ( V_52 -> V_53 ) ;
V_52 -> V_53 = NULL ;
return 0 ;
}
V_52 -> V_53 -> V_149 = V_2 -> V_52 -> V_53 -> V_99 +
V_2 -> V_165 - 16 ;
if ( F_46 ( V_2 ) )
V_52 -> V_53 -> V_149 -= V_166 ;
F_7 ( V_2 , V_36 ,
L_21 ,
V_52 -> V_53 -> V_149 ) ;
return 0 ;
}
bool F_47 ( struct V_1 * V_2 ,
int V_68 , bool V_167 )
{
if ( F_44 ( V_2 -> V_52 ) || ! F_48 ( V_2 -> V_52 ) ||
! F_39 ( V_2 ) )
return false ;
if ( ! F_10 ( V_2 , V_68 , true , V_167 ) )
return false ;
return true ;
}
bool F_49 ( struct V_1 * V_2 , int V_68 )
{
return F_47 ( V_2 , V_68 , true ) ;
}
static void F_50 ( struct V_86 * V_52 ,
T_3 V_48 , T_1 V_168 )
{
struct V_3 * V_59 ;
int V_65 ;
F_51 (cdev, i) {
struct V_1 * V_2 = & V_52 -> V_169 [ V_65 ] ;
V_59 = F_11 ( V_2 , V_48 , false ) ;
if ( ! V_59 )
continue;
V_59 -> V_168 = V_168 ;
}
}
static void F_52 ( struct V_86 * V_52 , T_1 V_168 )
{
T_3 V_65 ;
if ( ! F_48 ( V_52 ) )
return;
for ( V_65 = 0 ; V_65 < V_52 -> V_53 -> V_54 ; V_65 ++ )
F_50 ( V_52 , V_65 , V_168 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_69 * V_70 , T_1 V_170 )
{
F_28 ( V_2 , V_70 ,
V_171 + ( V_170 >> 5 ) * 4 ,
1 << ( V_170 & 0x1f ) ) ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_69 * V_70 , struct V_3 * V_59 )
{
int V_65 ;
F_55 ( V_2 , V_70 , ( T_3 ) V_59 -> V_23 ) ;
F_28 ( V_2 , V_70 , V_172 , 0 ) ;
F_55 ( V_2 , V_70 , ( T_3 ) V_2 -> V_25 . V_23 ) ;
for ( V_65 = 0 ; V_65 < V_59 -> V_66 ; V_65 ++ )
F_56 ( V_2 , V_70 ,
V_59 -> V_67 [ V_65 ] ,
V_59 -> V_15 , true ) ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 , bool V_173 )
{
T_2 V_174 ;
F_55 ( V_2 , V_70 , ( T_3 ) V_59 -> V_23 ) ;
V_174 = F_26 ( V_2 , V_70 , V_175 ) ;
if ( V_173 )
V_174 |= V_176 ;
else
V_174 &= ~ V_176 ;
F_28 ( V_2 , V_70 , V_175 , V_174 ) ;
F_55 ( V_2 , V_70 , ( T_3 ) V_2 -> V_25 . V_23 ) ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 )
{
T_2 V_174 = V_177 ;
int V_11 ;
if ( V_59 -> V_168 )
return 0 ;
F_7 ( V_2 ,
V_36 ,
L_22 ,
V_59 -> V_37 , F_59 ( V_2 , V_59 ) ) ;
F_53 ( V_2 , V_70 , F_59 ( V_2 , V_59 ) ) ;
F_54 ( V_2 , V_70 , V_59 ) ;
V_59 -> V_57 = false ;
V_11 = F_60 ( V_2 , V_70 , V_59 -> V_37 , V_59 -> V_66 ) ;
if ( V_11 )
return V_11 ;
F_55 ( V_2 , V_70 , ( T_3 ) V_59 -> V_23 ) ;
F_27 ( V_174 , V_178 , V_2 -> V_179 ) ;
F_61 ( V_2 , V_180 , V_174 ) ;
F_62 ( V_2 , V_70 , V_181 , V_59 -> V_37 ,
V_2 -> V_25 . V_182 ) ;
F_55 ( V_2 , V_70 , ( T_3 ) V_2 -> V_25 . V_23 ) ;
V_59 -> V_147 = V_183 ;
return V_11 ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 , T_1 V_173 )
{
T_2 V_184 , V_115 ;
T_3 V_185 = 0 ;
int V_186 ;
for ( V_186 = 0 ; V_186 < V_59 -> V_61 ; V_186 ++ ) {
F_64 ( V_2 , V_59 -> V_187 [ V_186 ] . V_188 ,
& V_185 ) ;
V_184 = V_189 + V_185 * 4 ;
V_115 = V_173 ? ( V_59 -> V_37 | F_65 ( 8 ) ) : 0 ;
F_28 ( V_2 , V_70 , V_184 , V_115 ) ;
}
}
static void F_66 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 )
{
F_54 ( V_2 , V_70 , V_59 ) ;
F_57 ( V_2 , V_70 , V_59 , 1 ) ;
F_63 ( V_2 , V_70 , V_59 , true ) ;
}
static T_1 F_67 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 , T_3 V_190 )
{
struct V_112 * V_118 ;
int V_186 = 0 , V_191 = 0 ;
T_2 V_115 = 0 ;
V_118 = V_2 -> V_25 . V_116 -> V_117 . V_118 ;
if ( V_190 > V_2 -> V_25 . V_116 -> V_192 )
V_190 = V_2 -> V_25 . V_116 -> V_192 ;
V_2 -> V_25 . V_116 -> V_192 -= V_190 ;
F_27 ( V_115 , V_193 , V_59 -> V_37 ) ;
F_27 ( V_115 , V_123 , 1 ) ;
F_27 ( V_115 , V_194 , 0 ) ;
while ( ( V_186 < V_190 ) &&
( V_191 < F_25 ( V_2 -> V_52 ) ) ) {
if ( V_118 [ V_191 ] . V_119 & V_120 ) {
struct V_195 V_196 ;
V_59 -> V_67 [ V_186 ] = ( T_3 ) V_191 ;
V_118 [ V_191 ] . V_119 &= ~ V_120 ;
F_27 ( V_115 , V_197 , V_186 ) ;
F_28 ( V_2 , V_70 ,
V_122 + sizeof( T_2 ) * V_191 ,
V_115 ) ;
F_68 ( V_2 , & V_196 ,
V_2 -> V_179 ,
V_59 -> V_37 , 1 ) ;
F_69 ( V_2 , V_70 ,
( V_162 ) ( V_198 ) & V_196 ,
V_199 +
V_191 * sizeof( V_162 ) , 2 , 0 ) ;
V_186 ++ ;
}
V_191 ++ ;
}
V_59 -> V_66 = ( T_1 ) V_190 ;
return V_59 -> V_66 ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 )
{
struct V_200 * V_201 = V_2 -> V_25 . V_116 ;
int V_134 , V_191 ;
T_2 V_202 , V_115 ;
for ( V_134 = 0 ; V_134 < V_59 -> V_66 ; V_134 ++ ) {
V_191 = V_59 -> V_67 [ V_134 ] ;
V_202 = V_122 + sizeof( T_2 ) * V_191 ;
V_115 = F_26 ( V_2 , V_70 , V_202 ) ;
F_27 ( V_115 , V_123 , 0 ) ;
F_28 ( V_2 , V_70 , V_202 , V_115 ) ;
V_201 -> V_117 . V_118 [ V_191 ] . V_119 |=
V_120 ;
V_2 -> V_25 . V_116 -> V_192 ++ ;
}
V_59 -> V_66 = 0 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_203 * V_204 )
{
T_1 V_205 = 0 ;
struct V_3 * V_59 = NULL ;
T_3 V_186 , V_206 ;
int V_11 = 0 ;
T_2 V_207 ;
T_1 V_65 ;
V_59 = F_11 ( V_2 , V_204 -> V_48 , false ) ;
if ( ! V_59 ) {
F_12 ( V_2 , L_23 ) ;
return - V_12 ;
}
if ( V_59 -> V_56 ) {
F_6 ( V_2 , L_24 ,
V_204 -> V_48 ) ;
return - V_12 ;
}
for ( V_65 = 0 ; V_65 < V_204 -> V_208 ; V_65 ++ ) {
T_3 V_209 = F_72 ( V_2 , V_210 ) ;
T_3 V_211 = V_209 +
F_72 ( V_2 , V_212 ) - 1 ;
V_186 = V_204 -> V_213 [ V_65 ] ;
if ( V_186 < V_209 || V_186 > V_211 ) {
F_6 ( V_2 ,
L_25 ,
V_186 ,
V_204 -> V_48 ,
V_209 , V_211 ) ;
return - V_12 ;
}
V_186 = V_204 -> V_214 [ V_65 ] ;
if ( V_186 > V_211 ) {
F_6 ( V_2 ,
L_26 ,
V_186 , V_204 -> V_48 , V_211 ) ;
return - V_12 ;
}
if ( V_186 < V_209 )
F_7 ( V_2 ,
V_36 ,
L_27 ,
V_204 -> V_48 , V_186 , V_65 ) ;
}
F_73 ( V_2 , V_215 , & V_207 ) ;
F_7 ( V_2 ,
V_36 ,
L_28 ,
V_59 -> V_58 , V_204 -> V_208 , ( T_3 ) V_207 ) ;
V_206 = F_74 ( T_3 , V_204 -> V_208 , ( ( T_3 ) V_207 ) ) ;
V_205 = F_67 ( V_2 ,
V_70 ,
V_59 , V_206 ) ;
if ( ! V_205 ) {
F_12 ( V_2 , L_29 ) ;
return - V_159 ;
}
V_59 -> V_61 = V_205 ;
V_59 -> V_63 = V_205 ;
for ( V_65 = 0 ; V_65 < V_59 -> V_61 ; V_65 ++ ) {
struct V_216 * V_217 = & V_59 -> V_187 [ V_65 ] ;
V_217 -> V_188 = V_204 -> V_213 [ V_65 ] ;
V_217 -> V_218 = V_204 -> V_214 [ V_65 ] ;
V_217 -> V_219 = V_65 ;
F_7 ( V_2 , V_36 ,
L_30 ,
V_59 -> V_58 ,
V_65 , V_59 -> V_67 [ V_65 ] ,
V_217 -> V_188 ,
V_217 -> V_218 , V_217 -> V_219 ) ;
}
V_11 = F_58 ( V_2 , V_70 , V_59 ) ;
if ( ! V_11 ) {
V_59 -> V_56 = true ;
if ( F_75 ( V_2 ) )
V_2 -> V_52 -> V_53 -> V_97 ++ ;
}
return V_11 ;
}
static void F_76 ( struct V_1 * V_2 ,
T_3 V_68 ,
struct V_220 * V_76 ,
struct V_221 * V_109 ,
struct V_222 * V_223 )
{
struct V_3 * V_4 = F_11 ( V_2 ,
V_68 ,
false ) ;
struct V_71 * V_72 ;
if ( ! V_4 )
return;
V_72 = V_4 -> V_78 . V_79 ;
V_72 -> V_224 = V_76 -> V_225 . V_226 ;
V_72 -> V_227 = V_76 -> V_225 . V_228 ;
V_72 -> V_229 = V_76 -> V_225 . V_230 ;
V_72 -> V_231 = V_76 -> V_232 . V_226 ;
V_72 -> V_233 = V_76 -> V_232 . V_234 ;
V_72 -> V_235 = V_76 -> V_232 . V_236 ;
V_72 -> V_237 = V_76 -> V_238 ;
V_72 -> V_239 = V_109 -> V_239 ;
V_72 -> V_225 = V_109 -> V_225 ;
V_72 -> V_240 = V_109 -> V_240 ;
V_72 -> V_226 = V_109 -> V_241 ;
V_72 -> V_242 = V_109 -> V_243 ;
V_72 -> V_244 = V_109 -> V_244 ;
V_72 -> V_245 = V_109 -> V_245 ;
V_72 -> V_246 = V_109 -> V_246 ;
V_72 -> V_247 = V_109 -> V_247 ;
V_72 -> V_248 = V_109 -> V_248 ;
V_72 -> V_249 = V_109 -> V_249 ;
V_72 -> V_250 = V_109 -> V_250 ;
V_72 -> V_251 = V_223 -> V_252 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_69 * V_70 , T_3 V_48 )
{
struct V_222 V_253 ;
struct V_220 V_76 ;
struct V_221 V_109 ;
struct V_3 * V_59 = NULL ;
V_59 = F_11 ( V_2 , V_48 , true ) ;
if ( ! V_59 ) {
F_12 ( V_2 , L_31 ) ;
return - V_12 ;
}
if ( V_59 -> V_78 . V_79 )
memset ( V_59 -> V_78 . V_79 , 0 , sizeof( * V_59 -> V_78 . V_79 ) ) ;
memset ( & V_59 -> V_254 , 0 , sizeof( V_59 -> V_254 ) ) ;
memcpy ( & V_76 , F_78 ( V_2 ) , sizeof( V_76 ) ) ;
memcpy ( & V_109 , F_79 ( V_2 ) , sizeof( V_109 ) ) ;
memcpy ( & V_253 , F_80 ( V_2 ) , sizeof( V_253 ) ) ;
F_76 ( V_2 , V_48 , & V_76 , & V_109 , & V_253 ) ;
memset ( & V_59 -> V_31 , 0 , sizeof( V_59 -> V_31 ) ) ;
F_57 ( V_2 , V_70 , V_59 , 0 ) ;
F_63 ( V_2 , V_70 , V_59 , 0 ) ;
V_59 -> V_61 = 0 ;
V_59 -> V_63 = 0 ;
F_70 ( V_2 , V_70 , V_59 ) ;
if ( V_59 -> V_56 ) {
V_59 -> V_56 = false ;
if ( F_75 ( V_2 ) )
V_2 -> V_52 -> V_53 -> V_97 -- ;
}
return 0 ;
}
static bool F_81 ( T_3 V_255 )
{
return V_256 < V_255 && V_255 < V_257 ;
}
void * F_82 ( struct V_1 * V_2 , T_1 * * V_99 , T_3 type , T_3 V_258 )
{
struct V_259 * V_260 = (struct V_259 * ) * V_99 ;
V_260 -> type = type ;
V_260 -> V_258 = V_258 ;
* V_99 += V_258 ;
return * V_99 - V_258 ;
}
void F_83 ( struct V_1 * V_2 , void * V_261 )
{
T_3 V_65 = 1 , V_262 = 0 ;
struct V_259 * V_263 ;
do {
V_263 = (struct V_259 * ) ( ( T_1 * ) V_261 + V_262 ) ;
F_7 ( V_2 , V_36 ,
L_32 ,
V_65 , V_263 -> type , V_263 -> V_258 ) ;
if ( V_263 -> type == V_264 )
return;
if ( ! V_263 -> V_258 ) {
F_6 ( V_2 , L_33 ) ;
return;
}
V_262 += V_263 -> V_258 ;
if ( V_262 >= sizeof( struct V_265 ) ) {
F_6 ( V_2 , L_34 ) ;
return;
}
V_65 ++ ;
} while ( 1 );
}
static void F_84 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_4 ,
T_3 V_258 , T_1 V_119 )
{
struct V_266 * V_267 = & V_4 -> V_142 ;
struct V_75 V_76 ;
T_1 V_268 ;
V_267 -> V_145 -> V_269 . V_270 . V_119 = V_119 ;
F_83 ( V_2 , V_267 -> V_145 ) ;
V_268 = V_4 -> V_37 ;
memset ( & V_76 , 0 , sizeof( struct V_75 ) ) ;
V_76 . V_82 = V_83 ;
V_76 . V_84 = V_268 ;
F_18 ( V_2 , V_70 , V_267 -> V_146 + sizeof( V_162 ) ,
V_267 -> V_143 -> V_271 . V_272 +
sizeof( V_162 ) ,
( sizeof( union V_130 ) - sizeof( V_162 ) ) / 4 ,
& V_76 ) ;
F_18 ( V_2 , V_70 , V_267 -> V_146 ,
V_267 -> V_143 -> V_271 . V_272 ,
sizeof( V_162 ) / 4 , & V_76 ) ;
F_85 ( V_2 ,
V_273 +
F_86 ( V_268 ) , 1 ) ;
}
static T_3 F_87 ( struct V_1 * V_2 ,
enum V_274 V_275 )
{
switch ( V_275 ) {
case V_276 :
return V_277 ;
case V_278 :
return V_279 ;
case V_280 :
return V_281 ;
case V_282 :
return V_283 ;
case V_284 :
return V_285 ;
case V_286 :
return V_287 ;
case V_288 :
return V_289 ;
case V_290 :
return V_291 ;
default:
return 0 ;
}
}
static T_3 F_88 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_266 * V_292 ,
T_1 V_119 ,
T_3 V_293 , T_3 V_294 )
{
struct V_295 * V_296 ;
T_3 V_81 , V_297 , V_65 ;
memset ( V_292 -> V_145 , 0 , sizeof( union V_130 ) ) ;
V_292 -> V_99 = ( T_1 * ) V_292 -> V_145 ;
V_81 = sizeof( struct V_295 ) ;
V_297 = V_81 ;
F_82 ( V_2 , & V_292 -> V_99 , V_298 , V_81 ) ;
for ( V_65 = 0 ; V_65 < V_299 ; V_65 ++ ) {
if ( ! ( V_293 & F_65 ( V_65 ) ) )
continue;
V_296 = F_82 ( V_2 , & V_292 -> V_99 ,
F_87 ( V_2 , V_65 ) , V_81 ) ;
if ( V_294 & F_65 ( V_65 ) )
V_296 -> V_270 . V_119 = V_119 ;
else
V_296 -> V_270 . V_119 = V_300 ;
F_7 ( V_2 ,
V_36 ,
L_35 ,
V_4 -> V_58 ,
F_87 ( V_2 , V_65 ) , V_296 -> V_270 . V_119 ) ;
V_297 += V_81 ;
}
F_82 ( V_2 , & V_292 -> V_99 , V_264 ,
sizeof( struct V_301 ) ) ;
return V_297 ;
}
static void F_89 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_302 ,
T_3 type , T_3 V_258 , T_1 V_119 )
{
struct V_266 * V_267 = & V_302 -> V_142 ;
V_267 -> V_99 = ( T_1 * ) V_267 -> V_145 ;
F_82 ( V_2 , & V_267 -> V_99 , type , V_258 ) ;
F_82 ( V_2 , & V_267 -> V_99 , V_264 ,
sizeof( struct V_301 ) ) ;
F_84 ( V_2 , V_70 , V_302 , V_258 , V_119 ) ;
}
static struct
V_303 * F_90 ( struct V_1 * V_2 ,
T_3 V_58 ,
bool V_49 )
{
struct V_3 * V_59 = NULL ;
V_59 = F_11 ( V_2 , V_58 , V_49 ) ;
if ( ! V_59 )
return NULL ;
return & V_59 -> V_254 ;
}
static void F_91 ( struct V_1 * V_2 , T_1 V_68 )
{
struct V_303 * V_302 ;
V_302 = F_90 ( V_2 , V_68 , false ) ;
if ( ! V_302 )
return;
memset ( V_302 -> V_304 , 0 , V_305 ) ;
}
static void F_92 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_65 ;
V_4 -> V_77 = 0 ;
V_4 -> V_306 = 0 ;
V_4 -> V_307 = 0 ;
V_4 -> V_61 = V_4 -> V_66 ;
V_4 -> V_63 = V_4 -> V_66 ;
V_4 -> V_308 = 0 ;
for ( V_65 = 0 ; V_65 < V_309 ; V_65 ++ ) {
struct V_216 * V_217 = & V_4 -> V_187 [ V_65 ] ;
if ( V_217 -> V_310 ) {
F_93 ( V_2 , V_217 -> V_310 ) ;
V_217 -> V_310 = NULL ;
}
if ( V_217 -> V_311 ) {
F_93 ( V_2 , V_217 -> V_311 ) ;
V_217 -> V_311 = NULL ;
}
}
memset ( & V_4 -> V_312 , 0 , sizeof( V_4 -> V_312 ) ) ;
memset ( & V_4 -> V_31 , 0 , sizeof( V_4 -> V_31 ) ) ;
F_91 ( V_2 , V_4 -> V_58 ) ;
}
static T_1 F_94 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_4 ,
struct V_313 * V_314 ,
struct V_315 * V_316 )
{
int V_65 ;
V_316 -> V_61 = V_4 -> V_61 ;
V_316 -> V_63 = V_4 -> V_63 ;
V_316 -> V_66 = V_4 -> V_66 ;
for ( V_65 = 0 ; V_65 < V_316 -> V_66 ; V_65 ++ ) {
V_316 -> V_317 [ V_65 ] . V_318 = V_4 -> V_67 [ V_65 ] ;
V_316 -> V_317 [ V_65 ] . V_319 = 0 ;
}
for ( V_65 = 0 ; V_65 < V_316 -> V_61 ; V_65 ++ ) {
F_64 ( V_2 , V_4 -> V_187 [ V_65 ] . V_188 ,
( T_3 * ) & V_316 -> V_320 [ V_65 ] ) ;
V_316 -> V_14 [ V_65 ] = V_4 -> V_187 [ V_65 ] . V_219 ;
}
V_316 -> V_151 = F_74 ( T_1 , V_4 -> V_151 ,
V_314 -> V_151 ) ;
V_316 -> V_153 = F_74 ( T_1 , V_4 -> V_153 ,
V_314 -> V_153 ) ;
V_316 -> V_321 = V_322 ;
if ( V_316 -> V_61 < V_314 -> V_61 ||
V_316 -> V_63 < V_314 -> V_63 ||
V_316 -> V_66 < V_314 -> V_66 ||
V_316 -> V_151 < V_314 -> V_151 ||
V_316 -> V_153 < V_314 -> V_153 ||
V_316 -> V_321 < V_314 -> V_321 ) {
F_7 ( V_2 ,
V_36 ,
L_36 ,
V_4 -> V_37 ,
V_314 -> V_61 ,
V_316 -> V_61 ,
V_314 -> V_61 ,
V_316 -> V_63 ,
V_314 -> V_66 ,
V_316 -> V_66 ,
V_314 -> V_151 ,
V_316 -> V_151 ,
V_314 -> V_153 ,
V_316 -> V_153 ,
V_314 -> V_321 , V_316 -> V_321 ) ;
if ( ( V_4 -> V_31 . V_32 . V_33 ==
V_35 ) &&
( V_4 -> V_31 . V_32 . V_323 ==
V_324 ) )
return V_325 ;
return V_326 ;
}
return V_325 ;
}
static void F_95 ( struct V_1 * V_2 ,
struct V_327 * V_328 )
{
V_328 -> V_329 . V_330 = V_331 +
F_96 ( struct V_332 ,
V_333 . V_334 ) ;
V_328 -> V_329 . V_335 = sizeof( struct V_336 ) ;
V_328 -> V_337 . V_330 = V_338 +
F_96 ( struct V_339 ,
V_333 . V_334 ) ;
V_328 -> V_337 . V_335 = sizeof( struct V_340 ) ;
V_328 -> V_341 . V_330 = V_342 +
F_96 ( struct V_343 ,
V_333 . V_334 ) ;
V_328 -> V_341 . V_335 = sizeof( struct V_344 ) ;
V_328 -> V_345 . V_330 = 0 ;
V_328 -> V_345 . V_335 = 0 ;
}
static void F_97 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 )
{
struct V_266 * V_267 = & V_59 -> V_142 ;
struct V_346 * V_296 = & V_267 -> V_145 -> V_347 ;
struct V_348 * V_349 = & V_296 -> V_349 ;
struct V_350 * V_351 = & V_267 -> V_143 -> V_31 ;
T_1 V_352 = V_300 ;
struct V_315 * V_353 = & V_296 -> V_353 ;
int V_11 ;
memset ( V_296 , 0 , sizeof( * V_296 ) ) ;
V_349 -> V_354 = V_38 ;
V_349 -> V_355 = V_34 ;
if ( V_59 -> V_147 != V_183 && V_59 -> V_147 != V_148 ) {
F_7 ( V_2 ,
V_36 ,
L_37 ,
V_59 -> V_37 , V_59 -> V_147 ) ;
goto V_356;
}
if ( V_351 -> V_32 . V_357 != V_38 ) {
if ( V_351 -> V_32 . V_358 &
V_359 ) {
struct V_360 * V_361 = & V_351 -> V_32 ;
F_7 ( V_2 , V_36 ,
L_38 ,
V_59 -> V_37 ) ;
V_361 -> V_357 = V_38 ;
V_361 -> V_33 = V_35 ;
} else {
F_98 ( V_2 ,
L_39 ,
V_59 -> V_37 ,
V_351 -> V_32 . V_357 ,
V_351 -> V_32 . V_33 ,
V_38 , V_34 ) ;
goto V_356;
}
}
if ( ( V_2 -> V_52 -> V_362 > 1 ) &&
! ( V_351 -> V_32 . V_358 & V_363 ) ) {
F_98 ( V_2 ,
L_40 ,
V_59 -> V_37 ) ;
goto V_356;
}
memcpy ( & V_59 -> V_31 , V_351 , sizeof( V_59 -> V_31 ) ) ;
V_59 -> V_15 = V_351 -> V_32 . V_15 ;
V_59 -> V_77 = V_351 -> V_364 ;
V_59 -> V_78 . V_81 = ( V_59 -> V_78 . V_81 < V_351 -> V_365 ) ?
V_59 -> V_78 . V_81 : V_351 -> V_365 ;
V_349 -> V_366 = V_2 -> V_52 -> V_366 ;
V_349 -> V_367 = 0 ;
V_349 -> V_368 = V_369 ;
V_349 -> V_358 = V_370 |
V_371 ;
if ( V_2 -> V_52 -> V_362 > 1 )
V_349 -> V_358 |= V_372 ;
F_95 ( V_2 , & V_349 -> V_373 ) ;
memcpy ( V_349 -> V_374 , V_2 -> V_25 . V_375 , V_305 ) ;
V_349 -> V_376 = V_377 ;
V_349 -> V_378 = V_379 ;
V_349 -> V_380 = V_381 ;
V_349 -> V_382 = V_383 ;
V_349 -> V_355 = F_74 ( T_1 , V_34 ,
V_351 -> V_32 . V_33 ) ;
V_349 -> V_323 = V_384 ;
F_99 ( V_2 , V_70 , & V_349 -> V_385 , NULL ) ;
V_349 -> V_386 = V_2 -> V_52 -> type ;
V_349 -> V_387 = V_2 -> V_52 -> V_387 ;
V_352 = F_94 ( V_2 , V_70 , V_59 ,
& V_351 -> V_388 , V_353 ) ;
if ( V_352 != V_325 )
goto V_356;
V_11 = F_1 ( V_2 , V_59 ) ;
if ( V_11 ) {
F_6 ( V_2 , L_41 , V_59 -> V_37 ) ;
V_352 = V_389 ;
goto V_356;
}
V_296 -> V_365 = V_59 -> V_78 . V_81 ;
F_16 ( V_2 , V_59 -> V_58 , V_70 ) ;
F_7 ( V_2 ,
V_36 ,
L_42
L_43 ,
V_59 -> V_37 ,
V_296 -> V_349 . V_366 ,
V_296 -> V_349 . V_367 ,
V_296 -> V_349 . V_368 ,
V_296 -> V_349 . V_358 ,
V_353 -> V_61 ,
V_353 -> V_63 ,
V_353 -> V_66 ,
V_353 -> V_151 ,
V_353 -> V_153 ) ;
V_59 -> V_147 = V_390 ;
V_356:
F_89 ( V_2 , V_70 , V_59 , V_391 ,
sizeof( struct V_346 ) , V_352 ) ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_115 )
{
struct V_392 V_76 ;
int V_11 ;
if ( V_115 == V_4 -> V_393 ) {
F_7 ( V_2 , V_36 ,
L_44 , V_115 ) ;
return 0 ;
}
memset ( & V_76 , 0 , sizeof( struct V_392 ) ) ;
V_76 . V_15 = V_4 -> V_15 ;
V_76 . V_150 = V_4 -> V_150 ;
V_76 . V_394 = 1 ;
V_76 . V_395 = V_115 ;
V_11 = F_101 ( V_2 , & V_76 , V_17 , NULL ) ;
if ( ! V_11 ) {
V_4 -> V_393 = V_115 ;
V_4 -> V_396 = V_4 -> V_393 ;
F_7 ( V_2 , V_36 ,
L_45 , V_115 ) ;
} else {
F_7 ( V_2 , V_36 ,
L_46 ,
V_115 , V_4 -> V_58 ) ;
}
return V_11 ;
}
static int F_102 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_397 V_398 ;
int V_11 = 0 ;
int V_65 ;
memset ( & V_398 , 0 , sizeof( V_398 ) ) ;
V_398 . V_399 = 1 ;
V_398 . V_400 = 1 ;
V_398 . V_401 = V_4 -> V_150 ;
V_398 . V_402 = V_403 ;
for ( V_65 = 0 ; V_65 < V_154 + 1 ; V_65 ++ ) {
if ( ! V_4 -> V_312 . V_404 [ V_65 ] . V_405 )
continue;
V_398 . type = V_406 ;
V_398 . V_407 = V_4 -> V_312 . V_404 [ V_65 ] . V_408 ;
F_7 ( V_2 , V_36 ,
L_47 ,
V_398 . V_407 , V_4 -> V_58 ) ;
V_11 = F_103 ( V_2 , V_4 -> V_15 ,
& V_398 , V_409 , NULL ) ;
if ( V_11 ) {
F_6 ( V_2 ,
L_48 ,
V_398 . V_407 , V_4 -> V_58 ) ;
break;
}
}
return V_11 ;
}
static int
F_104 ( struct V_1 * V_2 ,
struct V_3 * V_4 , V_162 V_410 )
{
int V_11 = 0 ;
if ( ( V_410 & F_65 ( V_411 ) ) &&
! ( V_4 -> V_307 & ( 1 << V_411 ) ) )
V_11 = F_102 ( V_2 , V_4 ) ;
return V_11 ;
}
static int F_105 ( struct V_1 * V_2 ,
struct V_3 * V_4 , V_162 V_410 )
{
int V_11 = 0 ;
struct V_397 V_398 ;
if ( ! V_4 -> V_306 )
return - V_12 ;
if ( V_410 & F_65 ( V_412 ) ) {
memset ( & V_398 , 0 , sizeof( V_398 ) ) ;
V_398 . type = V_413 ;
V_398 . V_402 = V_414 ;
V_398 . V_399 = 1 ;
V_398 . V_400 = 1 ;
V_398 . V_401 = V_4 -> V_150 ;
F_106 ( V_398 . V_304 , V_4 -> V_78 . V_79 -> V_304 ) ;
V_11 = F_103 ( V_2 , V_4 -> V_15 ,
& V_398 , V_409 , NULL ) ;
if ( V_11 ) {
F_6 ( V_2 ,
L_49 ) ;
return V_11 ;
}
V_4 -> V_307 |= 1 << V_412 ;
}
if ( V_410 & F_65 ( V_411 ) ) {
struct V_392 V_415 ;
T_1 V_416 ;
int V_65 ;
memset ( & V_398 , 0 , sizeof( V_398 ) ) ;
V_398 . type = V_406 ;
V_398 . V_399 = 1 ;
V_398 . V_400 = 1 ;
V_398 . V_401 = V_4 -> V_150 ;
V_398 . V_407 = V_4 -> V_78 . V_79 -> V_417 ;
V_398 . V_402 = V_398 . V_407 ? V_414 :
V_418 ;
V_11 = F_103 ( V_2 , V_4 -> V_15 ,
& V_398 , V_409 , NULL ) ;
if ( V_11 ) {
F_6 ( V_2 ,
L_50 ) ;
return V_11 ;
}
memset ( & V_415 , 0 , sizeof( V_415 ) ) ;
V_415 . V_15 = V_4 -> V_15 ;
V_415 . V_150 = V_4 -> V_150 ;
V_415 . V_419 = 1 ;
V_415 . V_420 = V_398 . V_407 ? 1 : 0 ;
V_415 . V_421 = 1 ;
V_415 . V_422 = V_398 . V_407 ;
V_415 . V_423 = 1 ;
V_416 = V_398 . V_407 ? 1
: V_4 -> V_312 . V_424 ;
V_415 . V_425 = V_416 ;
V_415 . V_426 = V_398 . V_407 ? 1 : 0 ;
V_11 = F_101 ( V_2 ,
& V_415 ,
V_17 , NULL ) ;
if ( V_11 ) {
F_6 ( V_2 ,
L_51 ) ;
return V_11 ;
}
for ( V_65 = 0 ; V_65 < V_309 ; V_65 ++ ) {
struct V_427 * V_428 ;
V_428 = V_4 -> V_187 [ V_65 ] . V_310 ;
if ( ! V_428 )
continue;
V_11 = F_107 ( V_2 ,
( void * * ) & V_428 ,
1 , 0 , 1 ,
V_17 ,
NULL ) ;
if ( V_11 ) {
F_6 ( V_2 ,
L_52 ,
V_428 -> V_429 . V_430 ) ;
return V_11 ;
}
}
if ( V_398 . V_407 )
V_4 -> V_307 |= 1 << V_411 ;
else
V_4 -> V_307 &= ~ F_65 ( V_411 ) ;
}
if ( V_410 )
F_104 ( V_2 , V_4 , V_410 ) ;
return V_11 ;
}
static void F_108 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 )
{
struct V_431 V_76 = { 0 } ;
struct V_266 * V_267 = & V_59 -> V_142 ;
struct V_432 * V_433 ;
T_1 V_119 = V_325 ;
struct V_3 * V_302 ;
V_162 * V_434 ;
int V_114 ;
int V_11 ;
V_302 = F_11 ( V_2 , ( T_3 ) V_59 -> V_58 , true ) ;
if ( ! V_302 ) {
F_6 ( V_2 -> V_52 ,
L_53 ,
V_59 -> V_58 ) ;
return;
}
V_59 -> V_147 = V_435 ;
V_433 = & V_267 -> V_143 -> V_436 ;
for ( V_114 = 0 ; V_114 < V_59 -> V_66 ; V_114 ++ ) {
if ( ! V_433 -> V_437 [ V_114 ] ) {
F_7 ( V_2 , V_36 ,
L_54 ,
V_59 -> V_58 , V_114 ) ;
break;
}
F_109 ( V_2 , V_70 ,
V_433 -> V_437 [ V_114 ] ,
V_59 -> V_67 [ V_114 ] , V_59 -> V_37 , 1 ) ;
}
F_66 ( V_2 , V_70 , V_59 ) ;
V_59 -> V_438 = V_433 -> V_438 ;
V_59 -> V_312 . V_424 = V_433 -> V_424 ;
V_434 = & V_302 -> V_78 . V_79 -> V_439 ;
if ( ! ( * V_434 & F_65 ( V_440 ) ) ) {
T_1 V_441 = V_433 -> V_442 ;
V_302 -> V_78 . V_79 -> V_443 = V_441 ;
* V_434 |= 1 << V_444 ;
}
V_76 . V_445 = V_433 -> V_445 ;
V_76 . V_446 = V_433 -> V_424 ;
V_76 . V_447 = true ;
V_76 . V_442 = V_302 -> V_78 . V_79 -> V_443 ;
V_76 . V_448 = false ;
V_76 . V_23 = V_59 -> V_23 ;
V_76 . V_15 = V_59 -> V_15 ;
V_76 . V_150 = V_59 -> V_150 ;
V_76 . V_449 = V_433 -> V_449 ;
V_76 . V_438 = V_59 -> V_438 ;
V_76 . V_450 = true ;
V_11 = F_110 ( V_2 , & V_76 ) ;
if ( V_11 ) {
F_12 ( V_2 ,
L_55 , V_11 ) ;
V_119 = V_389 ;
} else {
V_59 -> V_306 ++ ;
F_105 ( V_2 , V_59 , * V_434 ) ;
F_100 ( V_2 , V_59 , V_59 -> V_396 ) ;
}
F_89 ( V_2 , V_70 , V_59 , V_451 ,
sizeof( struct V_295 ) , V_119 ) ;
}
static void F_111 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 )
{
T_1 V_119 = V_325 ;
int V_11 ;
V_59 -> V_306 -- ;
V_59 -> V_393 = false ;
V_11 = F_112 ( V_2 , V_59 -> V_15 , V_59 -> V_150 ) ;
if ( V_11 ) {
F_12 ( V_2 , L_56 ,
V_11 ) ;
V_119 = V_389 ;
}
V_59 -> V_307 = 0 ;
memset ( & V_59 -> V_312 , 0 , sizeof( V_59 -> V_312 ) ) ;
F_89 ( V_2 , V_70 , V_59 , V_452 ,
sizeof( struct V_295 ) , V_119 ) ;
}
static void F_113 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 ,
T_1 V_119 , bool V_453 )
{
struct V_266 * V_267 = & V_59 -> V_142 ;
struct V_454 * V_455 ;
struct V_456 * V_351 ;
T_3 V_258 ;
V_267 -> V_99 = ( T_1 * ) V_267 -> V_145 ;
if ( ! V_453 )
V_258 = sizeof( * V_455 ) ;
else
V_258 = sizeof( struct V_295 ) ;
V_455 = F_82 ( V_2 , & V_267 -> V_99 , V_457 ,
V_258 ) ;
F_82 ( V_2 , & V_267 -> V_99 , V_264 ,
sizeof( struct V_301 ) ) ;
if ( ( V_119 == V_325 ) && ! V_453 ) {
V_351 = & V_267 -> V_143 -> V_458 ;
V_455 -> V_99 = V_331 +
F_96 ( struct V_332 ,
V_333 . V_459 ) +
sizeof( struct V_460 ) * V_351 -> V_60 ;
}
F_84 ( V_2 , V_70 , V_59 , V_258 , V_119 ) ;
}
static void F_114 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 )
{
struct V_461 V_76 ;
struct V_266 * V_267 = & V_59 -> V_142 ;
T_1 V_119 = V_326 ;
struct V_216 * V_217 ;
struct V_456 * V_351 ;
bool V_462 = false ;
int V_11 ;
V_351 = & V_267 -> V_143 -> V_458 ;
if ( ! F_13 ( V_2 , V_59 , V_351 -> V_60 ) ||
! F_15 ( V_2 , V_59 , V_351 -> V_463 ) )
goto V_356;
V_217 = & V_59 -> V_187 [ V_351 -> V_60 ] ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_76 . V_430 = V_217 -> V_188 ;
V_76 . V_150 = V_59 -> V_150 ;
V_76 . V_464 = V_59 -> V_37 + 0x10 ;
V_76 . V_465 = V_351 -> V_463 ;
V_76 . V_64 = V_351 -> V_466 ;
V_217 -> V_310 = F_115 ( V_2 ,
V_59 -> V_15 ,
V_217 -> V_219 ,
V_351 -> V_60 , & V_76 ) ;
if ( ! V_217 -> V_310 )
goto V_356;
if ( V_59 -> V_31 . V_32 . V_33 ==
V_35 ) {
V_462 = true ;
} else {
F_85 ( V_2 ,
V_467 +
F_116 ( V_59 -> V_37 , V_351 -> V_60 ) ,
0 ) ;
}
V_217 -> V_310 -> V_462 = V_462 ;
V_11 = F_117 ( V_2 ,
V_217 -> V_310 ,
V_351 -> V_468 ,
V_351 -> V_469 ,
V_351 -> V_470 , V_351 -> V_471 ) ;
if ( V_11 ) {
V_119 = V_389 ;
F_93 ( V_2 , V_217 -> V_310 ) ;
V_217 -> V_310 = NULL ;
} else {
V_119 = V_325 ;
V_59 -> V_308 ++ ;
}
V_356:
F_113 ( V_2 , V_70 , V_59 , V_119 , V_462 ) ;
}
static void F_118 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_4 , T_1 V_119 )
{
struct V_266 * V_267 = & V_4 -> V_142 ;
struct V_454 * V_455 ;
bool V_453 = false ;
T_3 V_258 ;
V_267 -> V_99 = ( T_1 * ) V_267 -> V_145 ;
if ( V_4 -> V_31 . V_32 . V_33 ==
V_35 )
V_453 = true ;
if ( ! V_453 )
V_258 = sizeof( * V_455 ) ;
else
V_258 = sizeof( struct V_295 ) ;
V_455 = F_82 ( V_2 , & V_267 -> V_99 , V_472 ,
V_258 ) ;
F_82 ( V_2 , & V_267 -> V_99 , V_264 ,
sizeof( struct V_301 ) ) ;
if ( ( V_119 == V_325 ) && ! V_453 ) {
T_3 V_186 = V_267 -> V_143 -> V_473 . V_62 ;
V_455 -> V_99 = F_119 ( V_4 -> V_187 [ V_186 ] . V_219 ,
V_474 ) ;
}
F_84 ( V_2 , V_70 , V_4 , V_258 , V_119 ) ;
}
static void F_120 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 )
{
struct V_461 V_76 ;
struct V_266 * V_267 = & V_59 -> V_142 ;
T_1 V_119 = V_326 ;
union V_475 V_476 ;
struct V_477 * V_351 ;
struct V_216 * V_217 ;
int V_11 ;
T_3 V_478 ;
memset ( & V_476 , 0 , sizeof( V_476 ) ) ;
V_476 . V_479 . V_480 = 1 ;
V_476 . V_479 . V_22 = V_59 -> V_58 ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_351 = & V_267 -> V_143 -> V_473 ;
if ( ! F_14 ( V_2 , V_59 , V_351 -> V_62 ) ||
! F_15 ( V_2 , V_59 , V_351 -> V_463 ) )
goto V_356;
V_217 = & V_59 -> V_187 [ V_351 -> V_62 ] ;
V_76 . V_430 = V_217 -> V_218 ;
V_76 . V_150 = V_59 -> V_150 ;
V_76 . V_464 = V_59 -> V_37 + 0x10 ;
V_76 . V_465 = V_351 -> V_463 ;
V_76 . V_64 = V_351 -> V_466 ;
V_217 -> V_311 = F_115 ( V_2 ,
V_59 -> V_15 ,
V_217 -> V_219 ,
V_351 -> V_62 , & V_76 ) ;
if ( ! V_217 -> V_311 )
goto V_356;
V_478 = F_121 ( V_2 , V_215 , & V_476 ) ;
V_11 = F_122 ( V_2 , V_217 -> V_311 ,
V_351 -> V_481 , V_351 -> V_482 , V_478 ) ;
if ( V_11 ) {
V_119 = V_389 ;
F_93 ( V_2 , V_217 -> V_311 ) ;
V_217 -> V_311 = NULL ;
} else {
V_119 = V_325 ;
}
V_356:
F_118 ( V_2 , V_70 , V_59 , V_119 ) ;
}
static int F_123 ( struct V_1 * V_2 ,
struct V_3 * V_59 ,
T_3 V_483 , T_1 V_61 , bool V_484 )
{
struct V_216 * V_217 ;
int V_11 = 0 ;
int V_186 ;
if ( V_483 + V_61 > F_124 ( V_59 -> V_187 ) )
return - V_12 ;
for ( V_186 = V_483 ; V_186 < V_483 + V_61 ; V_186 ++ ) {
V_217 = & V_59 -> V_187 [ V_186 ] ;
if ( ! V_217 -> V_310 )
continue;
V_11 = F_125 ( V_2 ,
V_217 -> V_310 ,
false , V_484 ) ;
if ( V_11 )
return V_11 ;
V_59 -> V_187 [ V_186 ] . V_310 = NULL ;
V_59 -> V_308 -- ;
}
return V_11 ;
}
static int F_126 ( struct V_1 * V_2 ,
struct V_3 * V_59 , T_3 V_485 , T_1 V_63 )
{
int V_11 = 0 ;
struct V_216 * V_217 ;
int V_186 ;
if ( V_485 + V_63 > F_124 ( V_59 -> V_187 ) )
return - V_12 ;
for ( V_186 = V_485 ; V_186 < V_485 + V_63 ; V_186 ++ ) {
V_217 = & V_59 -> V_187 [ V_186 ] ;
if ( ! V_217 -> V_311 )
continue;
V_11 = F_127 ( V_2 , V_217 -> V_311 ) ;
if ( V_11 )
return V_11 ;
V_217 -> V_311 = NULL ;
}
return V_11 ;
}
static void F_128 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 )
{
T_3 V_258 = sizeof( struct V_295 ) ;
struct V_266 * V_267 = & V_59 -> V_142 ;
T_1 V_119 = V_325 ;
struct V_486 * V_351 ;
int V_11 ;
V_351 = & V_267 -> V_143 -> V_487 ;
V_11 = F_123 ( V_2 , V_59 , V_351 -> V_60 ,
V_351 -> V_61 , V_351 -> V_484 ) ;
if ( V_11 )
V_119 = V_389 ;
F_89 ( V_2 , V_70 , V_59 , V_488 ,
V_258 , V_119 ) ;
}
static void F_129 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 )
{
T_3 V_258 = sizeof( struct V_295 ) ;
struct V_266 * V_267 = & V_59 -> V_142 ;
T_1 V_119 = V_325 ;
struct V_489 * V_351 ;
int V_11 ;
V_351 = & V_267 -> V_143 -> V_490 ;
V_11 = F_126 ( V_2 , V_59 , V_351 -> V_62 , V_351 -> V_63 ) ;
if ( V_11 )
V_119 = V_389 ;
F_89 ( V_2 , V_70 , V_59 , V_491 ,
V_258 , V_119 ) ;
}
static void F_130 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 )
{
struct V_427 * V_492 [ V_309 ] ;
T_3 V_258 = sizeof( struct V_295 ) ;
struct V_266 * V_267 = & V_59 -> V_142 ;
struct V_493 * V_351 ;
T_1 V_119 = V_389 ;
T_1 V_494 ;
T_1 V_495 ;
T_3 V_186 ;
int V_11 ;
T_1 V_65 ;
V_351 = & V_267 -> V_143 -> V_496 ;
V_495 = ! ! ( V_351 -> V_82 & V_497 ) ;
V_494 = ! ! ( V_351 -> V_82 & V_498 ) ;
if ( V_351 -> V_61 + V_351 -> V_60 > V_309 ||
! F_13 ( V_2 , V_59 , V_351 -> V_60 ) ) {
F_98 ( V_2 , L_57 ,
V_59 -> V_58 , V_351 -> V_60 , V_351 -> V_61 ) ;
goto V_356;
}
for ( V_65 = 0 ; V_65 < V_351 -> V_61 ; V_65 ++ ) {
V_186 = V_351 -> V_60 + V_65 ;
if ( ! V_59 -> V_187 [ V_186 ] . V_310 ) {
F_98 ( V_2 ,
L_58 ,
V_59 -> V_58 , V_186 ) ;
goto V_356;
}
V_492 [ V_65 ] = V_59 -> V_187 [ V_186 ] . V_310 ;
}
V_11 = F_107 ( V_2 , ( void * * ) & V_492 ,
V_351 -> V_61 ,
V_495 ,
V_494 ,
V_17 , NULL ) ;
if ( V_11 )
goto V_356;
V_119 = V_325 ;
V_356:
F_89 ( V_2 , V_70 , V_59 , V_499 ,
V_258 , V_119 ) ;
}
void * F_131 ( struct V_1 * V_2 ,
void * V_500 , T_3 V_501 )
{
struct V_259 * V_455 = (struct V_259 * ) V_500 ;
int V_335 = 0 ;
do {
if ( ! V_455 -> V_258 ) {
F_6 ( V_2 , L_59 ) ;
return NULL ;
}
if ( V_455 -> type == V_501 ) {
F_7 ( V_2 , V_36 ,
L_60 ,
V_455 -> type , V_455 -> V_258 ) ;
return V_455 ;
}
V_335 += V_455 -> V_258 ;
V_455 = (struct V_259 * ) ( ( T_1 * ) V_455 + V_455 -> V_258 ) ;
if ( ( V_335 + V_455 -> V_258 ) > V_502 ) {
F_6 ( V_2 , L_61 ) ;
return NULL ;
}
} while ( V_455 -> type != V_264 );
return NULL ;
}
static void
F_132 ( struct V_1 * V_2 ,
struct V_392 * V_503 ,
struct V_266 * V_292 , T_3 * V_293 )
{
struct V_504 * V_505 ;
T_3 V_263 = V_277 ;
V_505 = (struct V_504 * )
F_131 ( V_2 , V_292 -> V_143 , V_263 ) ;
if ( ! V_505 )
return;
V_503 -> V_506 = V_505 -> V_507 ;
V_503 -> V_508 = V_505 -> V_509 ;
V_503 -> V_510 = V_505 -> V_511 ;
V_503 -> V_512 = V_505 -> V_513 ;
* V_293 |= 1 << V_276 ;
}
static void
F_133 ( struct V_1 * V_2 ,
struct V_392 * V_503 ,
struct V_3 * V_4 ,
struct V_266 * V_292 , T_3 * V_293 )
{
struct V_514 * V_515 ;
T_3 V_263 = V_279 ;
V_515 = (struct V_514 * )
F_131 ( V_2 , V_292 -> V_143 , V_263 ) ;
if ( ! V_515 )
return;
V_4 -> V_312 . V_424 = V_515 -> V_516 ;
if ( ! ( V_4 -> V_307 & F_65 ( V_411 ) ) ) {
V_503 -> V_423 = 1 ;
V_503 -> V_425 = V_515 -> V_516 ;
}
* V_293 |= 1 << V_278 ;
}
static void
F_134 ( struct V_1 * V_2 ,
struct V_392 * V_503 ,
struct V_266 * V_292 , T_3 * V_293 )
{
struct V_517 * V_518 ;
T_3 V_263 = V_281 ;
V_518 = (struct V_517 * )
F_131 ( V_2 , V_292 -> V_143 ,
V_263 ) ;
if ( ! V_518 )
return;
V_503 -> V_519 = 1 ;
V_503 -> V_520 = V_518 -> V_447 ;
* V_293 |= 1 << V_280 ;
}
static void
F_135 ( struct V_1 * V_2 ,
struct V_392 * V_503 ,
struct V_266 * V_292 , T_3 * V_293 )
{
struct V_521 * V_522 ;
T_3 V_263 = V_283 ;
V_522 = (struct V_521 * )
F_131 ( V_2 , V_292 -> V_143 , V_263 ) ;
if ( ! V_522 )
return;
V_503 -> V_523 = 1 ;
memcpy ( V_503 -> V_524 , V_522 -> V_524 ,
sizeof( unsigned long ) * V_525 ) ;
* V_293 |= 1 << V_282 ;
}
static void
F_136 ( struct V_1 * V_2 ,
struct V_392 * V_503 ,
struct V_266 * V_292 , T_3 * V_293 )
{
struct V_526 * V_527 = & V_503 -> V_528 ;
struct V_529 * V_530 ;
T_3 V_263 = V_285 ;
V_530 = (struct V_529 * )
F_131 ( V_2 , V_292 -> V_143 , V_263 ) ;
if ( ! V_530 )
return;
V_527 -> V_531 = V_530 -> V_532 ;
V_527 -> V_533 = V_530 -> V_533 ;
V_527 -> V_534 = V_530 -> V_535 ;
V_527 -> V_536 = V_530 -> V_536 ;
* V_293 |= 1 << V_284 ;
}
static void
F_137 ( struct V_1 * V_2 ,
struct V_392 * V_503 ,
struct V_266 * V_292 , T_3 * V_293 )
{
struct V_537 * V_538 ;
T_3 V_263 = V_289 ;
V_538 = (struct V_537 * )
F_131 ( V_2 , V_292 -> V_143 ,
V_263 ) ;
if ( ! V_538 )
return;
V_503 -> V_539 = V_538 -> V_539 ;
V_503 -> V_540 =
V_538 -> V_540 ;
* V_293 |= 1 << V_288 ;
}
static void
F_138 ( struct V_1 * V_2 ,
struct V_3 * V_59 ,
struct V_392 * V_503 ,
struct V_541 * V_542 ,
struct V_266 * V_292 , T_3 * V_293 )
{
struct V_543 * V_544 ;
T_3 V_263 = V_287 ;
T_3 V_65 , V_545 , V_546 ;
T_3 V_547 ;
V_544 = (struct V_543 * )
F_131 ( V_2 , V_292 -> V_143 , V_263 ) ;
if ( ! V_544 ) {
V_503 -> V_548 = NULL ;
return;
}
memset ( V_542 , 0 , sizeof( struct V_541 ) ) ;
V_542 -> V_549 = ! ! ( V_544 -> V_550 &
V_551 ) ;
V_542 -> V_552 = ! ! ( V_544 -> V_550 &
V_553 ) ;
V_542 -> V_554 = ! ! ( V_544 -> V_550 &
V_555 ) ;
V_542 -> V_556 = ! ! ( V_544 -> V_550 &
V_557 ) ;
V_542 -> V_558 = V_544 -> V_558 ;
V_542 -> V_559 = V_59 -> V_58 + 1 ;
V_542 -> V_560 = V_544 -> V_560 ;
V_542 -> V_561 = V_544 -> V_561 ;
memcpy ( V_542 -> V_562 , V_544 -> V_562 ,
sizeof( V_542 -> V_562 ) ) ;
memcpy ( V_542 -> V_563 , V_544 -> V_563 , sizeof( V_542 -> V_563 ) ) ;
V_547 = F_74 ( T_3 , F_124 ( V_542 -> V_562 ) ,
( 1 << V_544 -> V_561 ) ) ;
V_546 = F_124 ( V_59 -> V_187 ) ;
for ( V_65 = 0 ; V_65 < V_547 ; V_65 ++ ) {
T_3 V_564 = V_59 -> V_187 [ 0 ] . V_188 ;
V_545 = V_542 -> V_562 [ V_65 ] ;
if ( V_545 >= V_546 )
F_6 ( V_2 ,
L_62 ,
V_65 , V_545 ) ;
else if ( ! V_59 -> V_187 [ V_545 ] . V_310 )
F_6 ( V_2 ,
L_63 ,
V_65 , V_545 ) ;
else
V_564 = V_59 -> V_187 [ V_545 ] . V_188 ;
V_542 -> V_562 [ V_65 ] = V_564 ;
}
V_503 -> V_548 = V_542 ;
* V_293 |= 1 << V_286 ;
}
static void
F_139 ( struct V_1 * V_2 ,
struct V_3 * V_59 ,
struct V_392 * V_503 ,
struct V_565 * V_566 ,
struct V_266 * V_292 , T_3 * V_293 )
{
struct V_567 * V_568 ;
T_3 V_263 = V_291 ;
V_568 = (struct V_567 * )
F_131 ( V_2 , V_292 -> V_143 , V_263 ) ;
if ( ! V_568 ) {
V_503 -> V_569 = NULL ;
return;
}
memset ( V_566 , 0 , sizeof( struct V_565 ) ) ;
V_566 -> V_570 =
! ! ( V_568 -> V_571 & V_572 ) ;
V_566 -> V_573 =
! ! ( V_568 -> V_571 &
V_574 ) ;
V_566 -> V_575 =
! ! ( V_568 -> V_576 & V_577 ) ;
V_566 -> V_578 =
! ! ( V_568 -> V_576 & V_579 ) ;
V_566 -> V_580 =
! ! ( V_568 -> V_576 & V_581 ) ;
V_566 -> V_582 =
! ! ( V_568 -> V_576 & V_583 ) ;
V_566 -> V_584 =
! ! ( V_568 -> V_576 & V_585 ) ;
V_566 -> V_586 = V_568 -> V_586 ;
V_566 -> V_587 = V_568 -> V_587 ;
V_566 -> V_588 = V_568 -> V_588 ;
V_566 -> V_589 = V_568 -> V_589 ;
V_566 -> V_449 = V_568 -> V_449 ;
V_503 -> V_569 = V_566 ;
* V_293 |= 1 << V_290 ;
}
static void F_140 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 )
{
struct V_392 V_76 ;
struct V_266 * V_267 = & V_59 -> V_142 ;
struct V_565 V_569 ;
struct V_541 V_548 ;
T_1 V_119 = V_325 ;
T_3 V_293 = 0 ;
T_3 V_258 ;
int V_11 ;
if ( ! V_59 -> V_306 ) {
F_7 ( V_2 ,
V_36 ,
L_64 ,
V_59 -> V_37 ) ;
V_119 = V_389 ;
goto V_356;
}
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_76 . V_15 = V_59 -> V_15 ;
V_76 . V_150 = V_59 -> V_150 ;
V_76 . V_548 = NULL ;
F_132 ( V_2 , & V_76 , V_267 , & V_293 ) ;
F_133 ( V_2 , & V_76 , V_59 , V_267 , & V_293 ) ;
F_134 ( V_2 , & V_76 , V_267 , & V_293 ) ;
F_135 ( V_2 , & V_76 , V_267 , & V_293 ) ;
F_136 ( V_2 , & V_76 , V_267 , & V_293 ) ;
F_138 ( V_2 , V_59 , & V_76 , & V_548 ,
V_267 , & V_293 ) ;
F_137 ( V_2 , & V_76 , V_267 , & V_293 ) ;
F_139 ( V_2 , V_59 , & V_76 ,
& V_569 , V_267 , & V_293 ) ;
if ( ! V_293 ) {
F_6 ( V_2 ,
L_65 ) ;
V_119 = V_300 ;
goto V_356;
}
V_11 = F_101 ( V_2 , & V_76 , V_17 , NULL ) ;
if ( V_11 )
V_119 = V_389 ;
V_356:
V_258 = F_88 ( V_2 , V_59 , V_267 , V_119 ,
V_293 , V_293 ) ;
F_84 ( V_2 , V_70 , V_59 , V_258 , V_119 ) ;
}
static int F_141 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_397 * V_204 )
{
int V_65 ;
if ( V_204 -> V_402 == V_590 ) {
for ( V_65 = 0 ; V_65 < V_154 + 1 ; V_65 ++ )
if ( V_4 -> V_312 . V_404 [ V_65 ] . V_405 &&
V_4 -> V_312 . V_404 [ V_65 ] . V_408 ==
V_204 -> V_407 ) {
V_4 -> V_312 . V_404 [ V_65 ] . V_405 = false ;
break;
}
if ( V_65 == V_154 + 1 ) {
F_7 ( V_2 ,
V_36 ,
L_66 ,
V_4 -> V_58 ) ;
return - V_12 ;
}
} else if ( V_204 -> V_402 == V_414 ||
V_204 -> V_402 == V_418 ) {
for ( V_65 = 0 ; V_65 < V_154 + 1 ; V_65 ++ )
V_4 -> V_312 . V_404 [ V_65 ] . V_405 = false ;
}
if ( V_4 -> V_78 . V_79 -> V_439 & F_65 ( V_411 ) )
return 0 ;
if ( V_204 -> V_402 == V_403 ||
V_204 -> V_402 == V_414 ) {
for ( V_65 = 0 ; V_65 < V_154 + 1 ; V_65 ++ ) {
if ( V_4 -> V_312 . V_404 [ V_65 ] . V_405 )
continue;
V_4 -> V_312 . V_404 [ V_65 ] . V_405 = true ;
V_4 -> V_312 . V_404 [ V_65 ] . V_408 = V_204 -> V_407 ;
break;
}
if ( V_65 == V_154 + 1 ) {
F_7 ( V_2 ,
V_36 ,
L_67 ,
V_4 -> V_58 ,
V_154 + 1 ) ;
return - V_12 ;
}
}
return 0 ;
}
static int F_142 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_397 * V_204 )
{
int V_65 ;
if ( V_4 -> V_78 . V_79 -> V_439 & F_65 ( V_412 ) )
return 0 ;
if ( V_204 -> V_402 == V_590 ) {
for ( V_65 = 0 ; V_65 < V_152 ; V_65 ++ ) {
if ( F_143 ( V_4 -> V_312 . V_591 [ V_65 ] ,
V_204 -> V_304 ) ) {
memset ( V_4 -> V_312 . V_591 [ V_65 ] , 0 ,
V_305 ) ;
break;
}
}
if ( V_65 == V_152 ) {
F_7 ( V_2 , V_36 ,
L_68 ) ;
return - V_12 ;
}
} else if ( V_204 -> V_402 == V_414 ||
V_204 -> V_402 == V_418 ) {
for ( V_65 = 0 ; V_65 < V_152 ; V_65 ++ )
memset ( V_4 -> V_312 . V_591 [ V_65 ] , 0 , V_305 ) ;
}
if ( V_204 -> V_402 != V_403 &&
V_204 -> V_402 != V_414 )
return 0 ;
for ( V_65 = 0 ; V_65 < V_152 ; V_65 ++ ) {
if ( F_144 ( V_4 -> V_312 . V_591 [ V_65 ] ) ) {
F_106 ( V_4 -> V_312 . V_591 [ V_65 ] ,
V_204 -> V_304 ) ;
F_7 ( V_2 , V_36 ,
L_69 , V_65 ) ;
break;
}
}
if ( V_65 == V_152 ) {
F_7 ( V_2 , V_36 , L_70 ) ;
return - V_12 ;
}
return 0 ;
}
static int
F_145 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_397 * V_204 )
{
int V_11 = 0 ;
if ( V_204 -> type == V_413 ) {
V_11 = F_142 ( V_2 , V_4 , V_204 ) ;
if ( V_11 )
return V_11 ;
}
if ( V_204 -> type == V_406 )
V_11 = F_141 ( V_2 , V_4 , V_204 ) ;
return V_11 ;
}
static int F_146 ( struct V_1 * V_592 ,
int V_68 , struct V_397 * V_76 )
{
struct V_303 * V_59 ;
V_59 = F_90 ( V_592 , V_68 , true ) ;
if ( ! V_59 )
return - V_12 ;
if ( V_76 -> type == V_413 ||
V_76 -> type == V_593 )
F_106 ( V_59 -> V_304 , V_76 -> V_304 ) ;
return 0 ;
}
static void F_147 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 )
{
struct V_71 * V_72 = V_59 -> V_78 . V_79 ;
struct V_266 * V_267 = & V_59 -> V_142 ;
struct V_594 * V_351 ;
T_1 V_119 = V_325 ;
struct V_397 V_76 ;
int V_11 ;
memset ( & V_76 , 0 , sizeof( struct V_397 ) ) ;
V_351 = & V_267 -> V_143 -> V_595 ;
V_76 . V_402 = (enum V_596 ) V_351 -> V_402 ;
V_76 . type = (enum V_597 ) V_351 -> type ;
V_76 . V_399 = 1 ;
V_76 . V_400 = 1 ;
V_76 . V_598 = V_59 -> V_150 ;
V_76 . V_401 = V_59 -> V_150 ;
memcpy ( V_76 . V_304 , V_351 -> V_304 , V_305 ) ;
V_76 . V_407 = V_351 -> V_407 ;
F_7 ( V_2 ,
V_36 ,
L_71 ,
V_59 -> V_37 , V_76 . V_402 , V_76 . type ,
V_76 . V_399 ? L_72 : L_73 ,
V_76 . V_400 ? L_74 : L_73 ,
V_76 . V_401 ,
V_76 . V_304 [ 0 ] , V_76 . V_304 [ 1 ] ,
V_76 . V_304 [ 2 ] , V_76 . V_304 [ 3 ] ,
V_76 . V_304 [ 4 ] , V_76 . V_304 [ 5 ] , V_76 . V_407 ) ;
if ( ! V_59 -> V_306 ) {
F_7 ( V_2 ,
V_36 ,
L_75 ,
V_59 -> V_37 ) ;
V_119 = V_389 ;
goto V_356;
}
if ( F_145 ( V_2 , V_59 , & V_76 ) ) {
V_119 = V_389 ;
goto V_356;
}
if ( ( V_72 -> V_439 & F_65 ( V_411 ) ) &&
( V_76 . type == V_406 ||
V_76 . type == V_593 ) ) {
if ( V_76 . V_402 == V_403 ||
V_76 . V_402 == V_414 )
V_119 = V_599 ;
goto V_356;
}
if ( ( V_72 -> V_439 & F_65 ( V_412 ) ) &&
( V_76 . type == V_413 ||
V_76 . type == V_593 ) ) {
if ( ! F_143 ( V_72 -> V_304 , V_76 . V_304 ) ||
( V_76 . V_402 != V_403 &&
V_76 . V_402 != V_414 ) )
V_119 = V_599 ;
goto V_356;
}
V_11 = F_146 ( V_2 , V_59 -> V_58 , & V_76 ) ;
if ( V_11 ) {
V_119 = V_389 ;
goto V_356;
}
V_11 = F_103 ( V_2 , V_59 -> V_15 , & V_76 ,
V_409 , NULL ) ;
if ( V_11 )
V_119 = V_389 ;
V_356:
F_89 ( V_2 , V_70 , V_59 , V_600 ,
sizeof( struct V_295 ) , V_119 ) ;
}
static void F_148 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 )
{
int V_65 ;
for ( V_65 = 0 ; V_65 < V_59 -> V_66 ; V_65 ++ )
F_56 ( V_2 , V_70 ,
V_59 -> V_67 [ V_65 ] ,
V_59 -> V_15 , false ) ;
F_89 ( V_2 , V_70 , V_59 , V_601 ,
sizeof( struct V_295 ) ,
V_325 ) ;
}
static void F_149 ( struct V_1 * V_2 ,
struct V_69 * V_70 , struct V_3 * V_59 )
{
T_3 V_258 = sizeof( struct V_295 ) ;
T_1 V_119 = V_325 ;
F_57 ( V_2 , V_70 , V_59 , 0 ) ;
F_63 ( V_2 , V_70 , V_59 , 0 ) ;
F_89 ( V_2 , V_70 , V_59 , V_602 ,
V_258 , V_119 ) ;
}
static void F_150 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_4 )
{
T_3 V_258 = sizeof( struct V_295 ) ;
T_1 V_119 = V_325 ;
int V_11 = 0 ;
F_92 ( V_2 , V_4 ) ;
if ( V_4 -> V_147 != V_148 && V_4 -> V_147 != V_183 ) {
V_11 = F_9 ( V_2 , V_4 -> V_23 ,
V_4 -> V_15 ) ;
if ( V_11 ) {
F_12 ( V_2 , L_76 ,
V_11 ) ;
V_119 = V_389 ;
}
V_4 -> V_147 = V_148 ;
}
F_89 ( V_2 , V_70 , V_4 , V_603 ,
V_258 , V_119 ) ;
}
static int
F_151 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_69 * V_70 )
{
int V_604 ;
T_2 V_115 ;
F_55 ( V_2 , V_70 , ( T_3 ) V_4 -> V_23 ) ;
for ( V_604 = 0 ; V_604 < 50 ; V_604 ++ ) {
V_115 = F_26 ( V_2 , V_70 , V_605 ) ;
if ( ! V_115 )
break;
F_152 ( 20 ) ;
}
F_55 ( V_2 , V_70 , ( T_3 ) V_2 -> V_25 . V_23 ) ;
if ( V_604 == 50 ) {
F_12 ( V_2 ,
L_77 ,
V_4 -> V_37 , V_115 ) ;
return - V_606 ;
}
return 0 ;
}
static int
F_153 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_69 * V_70 )
{
T_2 V_607 [ V_608 ] , V_609 [ V_608 ] ;
int V_65 , V_604 ;
for ( V_65 = 0 ; V_65 < V_608 ; V_65 ++ ) {
T_2 V_610 ;
V_607 [ V_65 ] = F_26 ( V_2 , V_70 ,
V_611 +
V_65 * 0x40 ) ;
V_610 = F_26 ( V_2 , V_70 ,
V_612 +
V_65 * 0x40 ) ;
V_609 [ V_65 ] = V_610 - V_607 [ V_65 ] ;
}
V_65 = 0 ;
for ( V_604 = 0 ; V_604 < 50 ; V_604 ++ ) {
for (; V_65 < V_608 ; V_65 ++ ) {
T_2 V_613 ;
V_613 = F_26 ( V_2 , V_70 ,
V_611 +
V_65 * 0x40 ) ;
if ( V_609 [ V_65 ] > V_613 - V_607 [ V_65 ] )
break;
}
if ( V_65 == V_608 )
break;
F_152 ( 20 ) ;
}
if ( V_604 == 50 ) {
F_12 ( V_2 , L_78 ,
V_4 -> V_37 , V_65 ) ;
return - V_606 ;
}
return 0 ;
}
static int F_154 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_69 * V_70 )
{
int V_11 ;
V_11 = F_151 ( V_2 , V_4 , V_70 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_153 ( V_2 , V_4 , V_70 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int
F_155 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
T_3 V_48 , T_2 * V_614 )
{
struct V_3 * V_4 ;
int V_11 = 0 ;
V_4 = F_11 ( V_2 , V_48 , false ) ;
if ( ! V_4 )
return 0 ;
if ( V_2 -> V_51 -> V_615 [ V_48 / 64 ] &
( 1ULL << ( V_48 % 64 ) ) ) {
T_3 V_68 = V_4 -> V_37 ;
F_7 ( V_2 , V_36 ,
L_79 , V_68 ) ;
F_92 ( V_2 , V_4 ) ;
if ( ! V_4 -> V_56 )
goto V_616;
V_11 = F_154 ( V_2 , V_4 , V_70 ) ;
if ( V_11 )
goto V_616;
V_11 = F_156 ( V_2 , V_70 , V_68 , true ) ;
if ( V_11 ) {
F_12 ( V_2 , L_80 , V_68 ) ;
return V_11 ;
}
F_85 ( V_2 ,
V_273 +
F_86 ( V_68 ) , 1 ) ;
V_4 -> V_147 = V_148 ;
V_11 = F_58 ( V_2 , V_70 , V_4 ) ;
if ( V_11 ) {
F_12 ( V_2 , L_81 ,
V_68 ) ;
return V_11 ;
}
V_616:
if ( V_4 -> V_147 == V_617 )
V_4 -> V_147 = V_148 ;
V_614 [ V_68 / 32 ] |= F_65 ( ( V_68 % 32 ) ) ;
V_2 -> V_51 -> V_615 [ V_48 / 64 ] &=
~ ( 1ULL << ( V_48 % 64 ) ) ;
V_2 -> V_51 -> V_618 [ V_48 / 64 ] &=
~ ( 1ULL << ( V_48 % 64 ) ) ;
}
return V_11 ;
}
static int
F_157 ( struct V_1 * V_2 , struct V_69 * V_70 )
{
T_2 V_614 [ V_619 / 32 ] ;
int V_11 = 0 ;
T_3 V_65 ;
memset ( V_614 , 0 , sizeof( T_2 ) * ( V_619 / 32 ) ) ;
F_152 ( 100 ) ;
for ( V_65 = 0 ; V_65 < V_2 -> V_52 -> V_53 -> V_54 ; V_65 ++ )
F_155 ( V_2 , V_70 , V_65 , V_614 ) ;
V_11 = F_158 ( V_2 , V_70 , V_614 ) ;
return V_11 ;
}
int F_159 ( struct V_1 * V_2 , T_2 * V_620 )
{
T_3 V_65 , V_621 = 0 ;
F_7 ( V_2 , V_36 , L_82 ) ;
for ( V_65 = 0 ; V_65 < ( V_619 / 32 ) ; V_65 ++ )
F_7 ( V_2 , V_36 ,
L_83 ,
V_65 * 32 , ( V_65 + 1 ) * 32 - 1 , V_620 [ V_65 ] ) ;
if ( ! V_2 -> V_52 -> V_53 ) {
F_6 ( V_2 , L_84 ) ;
return 0 ;
}
for ( V_65 = 0 ; V_65 < V_2 -> V_52 -> V_53 -> V_54 ; V_65 ++ ) {
struct V_3 * V_4 ;
T_1 V_68 ;
V_4 = F_11 ( V_2 , V_65 , false ) ;
if ( ! V_4 )
continue;
V_68 = V_4 -> V_37 ;
if ( F_65 ( ( V_68 % 32 ) ) & V_620 [ V_68 / 32 ] ) {
V_162 * V_622 = V_2 -> V_51 -> V_615 ;
T_3 V_48 = V_4 -> V_58 ;
F_7 ( V_2 , V_36 ,
L_85 ,
V_68 , V_48 ) ;
V_4 -> V_147 = V_617 ;
V_622 [ V_48 / 64 ] |= 1ULL << ( V_48 % 64 ) ;
V_621 = 1 ;
}
}
return V_621 ;
}
static void F_160 ( struct V_1 * V_2 ,
T_3 V_68 ,
struct V_220 * V_204 ,
struct V_221 * V_623 ,
struct V_222 * V_223 )
{
struct V_3 * V_4 = F_11 ( V_2 ,
V_68 ,
false ) ;
struct V_71 * V_72 ;
if ( ! V_4 )
return;
V_72 = V_4 -> V_78 . V_79 ;
if ( V_204 )
F_161 ( V_2 , V_204 , V_72 ) ;
if ( V_623 )
F_162 ( V_2 , V_623 , V_72 ) ;
if ( V_223 )
F_163 ( V_2 , V_223 , V_72 ) ;
}
static void F_164 ( struct V_1 * V_2 ,
struct V_69 * V_70 , int V_68 )
{
struct V_266 * V_267 ;
struct V_3 * V_4 ;
V_4 = F_11 ( V_2 , ( T_3 ) V_68 , true ) ;
if ( ! V_4 )
return;
V_267 = & V_4 -> V_142 ;
F_7 ( V_2 , V_36 ,
L_86 , V_4 -> V_37 ) ;
V_267 -> V_271 = V_267 -> V_143 -> V_271 ;
if ( F_81 ( V_267 -> V_271 . V_260 . type ) &&
! V_4 -> V_57 ) {
switch ( V_267 -> V_271 . V_260 . type ) {
case V_391 :
F_97 ( V_2 , V_70 , V_4 ) ;
break;
case V_451 :
F_108 ( V_2 , V_70 , V_4 ) ;
break;
case V_452 :
F_111 ( V_2 , V_70 , V_4 ) ;
break;
case V_457 :
F_114 ( V_2 , V_70 , V_4 ) ;
break;
case V_472 :
F_120 ( V_2 , V_70 , V_4 ) ;
break;
case V_488 :
F_128 ( V_2 , V_70 , V_4 ) ;
break;
case V_491 :
F_129 ( V_2 , V_70 , V_4 ) ;
break;
case V_499 :
F_130 ( V_2 , V_70 , V_4 ) ;
break;
case V_298 :
F_140 ( V_2 , V_70 , V_4 ) ;
break;
case V_600 :
F_147 ( V_2 , V_70 , V_4 ) ;
break;
case V_602 :
F_149 ( V_2 , V_70 , V_4 ) ;
break;
case V_601 :
F_148 ( V_2 , V_70 , V_4 ) ;
break;
case V_603 :
F_150 ( V_2 , V_70 , V_4 ) ;
break;
}
} else if ( F_81 ( V_267 -> V_271 . V_260 . type ) ) {
F_7 ( V_2 , V_36 ,
L_87 ,
V_4 -> V_37 , V_267 -> V_271 . V_260 . type ) ;
F_89 ( V_2 , V_70 , V_4 ,
V_267 -> V_271 . V_260 . type ,
sizeof( struct V_295 ) ,
V_624 ) ;
} else {
F_6 ( V_2 ,
L_88 ,
V_4 -> V_37 ,
V_267 -> V_271 . V_260 . type ,
V_267 -> V_271 . V_260 . V_258 ,
V_267 -> V_271 . V_625 , V_267 -> V_271 . V_272 ) ;
if ( V_4 -> V_31 . V_271 . V_272 &&
( V_267 -> V_271 . V_272 ==
V_4 -> V_31 . V_271 . V_272 ) ) {
F_89 ( V_2 , V_70 , V_4 ,
V_267 -> V_271 . V_260 . type ,
sizeof( struct V_295 ) ,
V_300 ) ;
} else {
F_7 ( V_2 ,
V_36 ,
L_89 ,
V_4 -> V_37 ) ;
}
}
}
static void F_165 ( struct V_1 * V_2 , T_1 V_68 )
{
V_162 V_626 = 1ULL << ( V_68 % 64 ) ;
V_2 -> V_51 -> V_618 [ V_68 / 64 ] |= V_626 ;
}
static void F_166 ( struct V_1 * V_2 ,
V_162 * V_410 )
{
V_162 * V_627 = V_2 -> V_51 -> V_618 ;
memcpy ( V_410 , V_627 , sizeof( V_162 ) * V_628 ) ;
memset ( V_627 , 0 , sizeof( V_162 ) * V_628 ) ;
}
static struct V_3 * F_167 ( struct V_1 * V_2 ,
T_3 V_170 )
{
T_1 V_629 = ( T_1 ) V_2 -> V_52 -> V_53 -> V_149 ;
if ( ! F_47 ( V_2 , ( int ) V_170 - V_629 , false ) ) {
F_7 ( V_2 ,
V_36 ,
L_90 ,
V_170 ) ;
return NULL ;
}
return & V_2 -> V_51 -> V_55 [ ( T_1 ) V_170 - V_629 ] ;
}
static int F_168 ( struct V_1 * V_2 ,
T_3 V_170 , struct V_630 * V_631 )
{
struct V_3 * V_4 = F_167 ( V_2 ,
V_170 ) ;
if ( ! V_4 )
return 0 ;
V_4 -> V_142 . V_632 = ( ( ( V_162 ) V_631 -> V_633 ) << 32 ) | V_631 -> V_634 ;
F_165 ( V_2 , V_4 -> V_58 ) ;
F_169 ( V_2 , V_635 ) ;
return 0 ;
}
static void F_170 ( struct V_1 * V_2 ,
struct V_636 * V_503 )
{
struct V_3 * V_4 ;
V_4 = F_167 ( V_2 , V_503 -> V_22 ) ;
if ( ! V_4 )
return;
F_98 ( V_2 ,
L_91 ,
V_4 -> V_37 , V_503 -> V_637 ) ;
V_4 -> V_57 = true ;
}
int F_171 ( struct V_1 * V_2 ,
T_1 V_402 , T_5 V_638 , union V_639 * V_640 )
{
switch ( V_402 ) {
case V_641 :
return F_168 ( V_2 , F_172 ( V_638 ) ,
& V_640 -> V_642 . V_643 ) ;
case V_644 :
F_170 ( V_2 , & V_640 -> V_645 ) ;
return 0 ;
default:
F_98 ( V_2 -> V_52 , L_92 ,
V_402 ) ;
return - V_12 ;
}
}
T_3 F_173 ( struct V_1 * V_2 , T_3 V_48 )
{
struct V_87 * V_124 = V_2 -> V_52 -> V_53 ;
T_3 V_65 ;
if ( ! V_124 )
goto V_356;
for ( V_65 = V_48 ; V_65 < V_124 -> V_54 ; V_65 ++ )
if ( F_10 ( V_2 , V_48 , true , false ) )
return V_65 ;
V_356:
return V_646 ;
}
static int F_174 ( struct V_1 * V_2 , struct V_69 * V_647 ,
int V_68 )
{
struct V_75 V_76 ;
struct V_3 * V_302 ;
V_302 = F_11 ( V_2 , ( T_3 ) V_68 , true ) ;
if ( ! V_302 )
return - V_12 ;
memset ( & V_76 , 0 , sizeof( struct V_75 ) ) ;
V_76 . V_82 = V_648 | V_649 ;
V_76 . V_650 = V_302 -> V_37 ;
if ( F_18 ( V_2 , V_647 ,
V_302 -> V_142 . V_632 ,
V_302 -> V_142 . V_144 ,
sizeof( union V_132 ) / 4 , & V_76 ) ) {
F_7 ( V_2 , V_36 ,
L_93 , V_68 ) ;
return - V_651 ;
}
return 0 ;
}
static void F_175 ( struct V_1 * V_2 ,
T_1 * V_304 , int V_68 )
{
struct V_3 * V_302 ;
V_162 V_652 ;
V_302 = F_11 ( V_2 , ( T_3 ) V_68 , true ) ;
if ( ! V_302 ) {
F_6 ( V_2 -> V_52 ,
L_94 , V_68 ) ;
return;
}
if ( V_302 -> V_57 ) {
F_6 ( V_2 -> V_52 ,
L_95 , V_68 ) ;
return;
}
V_652 = 1 << V_412 ;
memcpy ( V_302 -> V_78 . V_79 -> V_304 , V_304 , V_305 ) ;
V_302 -> V_78 . V_79 -> V_439 |= V_652 ;
V_302 -> V_78 . V_79 -> V_439 &= ~ F_65 ( V_653 ) ;
F_105 ( V_2 , V_302 , V_652 ) ;
}
static void F_176 ( struct V_1 * V_2 ,
T_3 V_417 , int V_68 )
{
struct V_3 * V_302 ;
V_162 V_652 ;
V_302 = F_11 ( V_2 , ( T_3 ) V_68 , true ) ;
if ( ! V_302 ) {
F_6 ( V_2 -> V_52 ,
L_94 , V_68 ) ;
return;
}
if ( V_302 -> V_57 ) {
F_6 ( V_2 -> V_52 ,
L_96 , V_68 ) ;
return;
}
V_652 = 1 << V_411 ;
V_302 -> V_78 . V_79 -> V_417 = V_417 ;
if ( V_417 )
V_302 -> V_78 . V_79 -> V_439 |= V_652 ;
else
V_302 -> V_78 . V_79 -> V_439 &= ~ V_652 ;
F_105 ( V_2 , V_302 , V_652 ) ;
}
static bool F_177 ( struct V_1 * V_2 , int V_68 )
{
struct V_3 * V_254 ;
V_254 = F_11 ( V_2 , ( T_3 ) V_68 , true ) ;
if ( ! V_254 )
return false ;
return ! ! V_254 -> V_306 ;
}
static bool F_178 ( struct V_1 * V_2 , int V_68 )
{
struct V_3 * V_254 ;
V_254 = F_11 ( V_2 , ( T_3 ) V_68 , true ) ;
if ( ! V_254 )
return true ;
return V_254 -> V_147 == V_148 ;
}
static bool F_179 ( struct V_1 * V_2 , int V_68 )
{
struct V_3 * V_302 ;
V_302 = F_11 ( V_2 , ( T_3 ) V_68 , true ) ;
if ( ! V_302 )
return false ;
return V_302 -> V_393 ;
}
static int F_180 ( struct V_1 * V_2 , int V_68 , bool V_115 )
{
struct V_3 * V_59 ;
int V_11 = - V_12 ;
if ( ! F_49 ( V_2 , V_68 ) ) {
F_6 ( V_2 ,
L_97 ) ;
goto V_356;
}
V_59 = F_11 ( V_2 , ( T_3 ) V_68 , true ) ;
if ( ! V_59 )
goto V_356;
if ( ! F_177 ( V_2 , V_68 ) ) {
V_59 -> V_396 = V_115 ;
V_11 = 0 ;
goto V_356;
}
V_11 = F_100 ( V_2 , V_59 , V_115 ) ;
V_356:
return V_11 ;
}
static T_1 * F_181 ( struct V_1 * V_2 ,
T_3 V_48 )
{
struct V_3 * V_4 ;
V_4 = F_11 ( V_2 , V_48 , true ) ;
if ( ! V_4 || ! V_4 -> V_78 . V_79 )
return NULL ;
if ( ! ( V_4 -> V_78 . V_79 -> V_439 & F_65 ( V_412 ) ) )
return NULL ;
return V_4 -> V_78 . V_79 -> V_304 ;
}
static T_3
F_182 ( struct V_1 * V_2 , T_3 V_48 )
{
struct V_3 * V_4 ;
V_4 = F_11 ( V_2 , V_48 , true ) ;
if ( ! V_4 || ! V_4 -> V_78 . V_79 )
return 0 ;
if ( ! ( V_4 -> V_78 . V_79 -> V_439 & F_65 ( V_411 ) ) )
return 0 ;
return V_4 -> V_78 . V_79 -> V_417 ;
}
static int F_183 ( struct V_1 * V_2 ,
struct V_69 * V_70 , int V_68 , int V_115 )
{
struct V_3 * V_59 ;
T_1 V_654 = 0 ;
int V_11 ;
V_59 = F_11 ( V_2 , ( T_3 ) V_68 , true ) ;
if ( ! V_59 )
return - V_12 ;
V_11 = F_184 ( V_2 , V_59 -> V_150 , & V_654 ) ;
if ( V_11 )
return V_11 ;
return F_185 ( V_2 , V_70 , V_654 , ( T_2 ) V_115 ) ;
}
static int
F_186 ( struct V_86 * V_52 , int V_68 , T_2 V_655 )
{
struct V_3 * V_59 ;
T_1 V_150 ;
int V_65 ;
F_51 (cdev, i) {
struct V_1 * V_2 = & V_52 -> V_169 [ V_65 ] ;
if ( ! F_49 ( V_2 , V_68 ) ) {
F_6 ( V_2 ,
L_98 ) ;
return - V_12 ;
}
}
V_59 = F_11 ( F_187 ( V_52 ) , ( T_3 ) V_68 , true ) ;
V_150 = V_59 -> V_150 ;
return F_188 ( V_52 , V_150 , V_655 ) ;
}
static int F_189 ( struct V_1 * V_2 , int V_68 )
{
struct V_656 * V_657 ;
struct V_3 * V_302 ;
V_302 = F_11 ( V_2 , ( T_3 ) V_68 , true ) ;
if ( ! V_302 )
return 0 ;
V_657 = & V_2 -> V_658 . V_659 [ V_302 -> V_150 ] ;
if ( V_657 -> V_660 )
return V_657 -> V_661 ;
else
return 0 ;
}
void F_169 ( struct V_1 * V_592 , enum V_662 V_275 )
{
F_190 () ;
F_191 ( V_275 , & V_592 -> V_663 ) ;
F_192 () ;
F_7 ( V_592 , V_36 , L_99 , V_275 ) ;
F_193 ( V_592 -> V_664 , & V_592 -> V_665 , 0 ) ;
}
void F_194 ( struct V_86 * V_52 )
{
int V_65 ;
F_51 (cdev, i)
F_193 ( V_52 -> V_169 [ V_65 ] . V_664 ,
& V_52 -> V_169 [ V_65 ] . V_665 , 0 ) ;
}
int F_195 ( struct V_86 * V_52 , bool V_666 )
{
int V_65 , V_667 ;
F_51 (cdev, i)
if ( V_52 -> V_169 [ V_65 ] . V_664 )
F_196 ( V_52 -> V_169 [ V_65 ] . V_664 ) ;
F_52 ( V_52 , true ) ;
if ( V_52 -> V_53 && V_52 -> V_53 -> V_97 && V_666 )
F_197 ( V_52 -> V_90 ) ;
F_51 (cdev, i) {
struct V_1 * V_592 = & V_52 -> V_169 [ V_65 ] ;
struct V_69 * V_647 = F_198 ( V_592 ) ;
if ( ! V_647 ) {
F_12 ( V_592 , L_100 ) ;
return - V_606 ;
}
F_199 ( V_592 , V_647 ) ;
F_200 (hwfn, j) {
int V_668 ;
if ( ! F_10 ( V_592 , V_667 , true , false ) )
continue;
for ( V_668 = 0 ; V_668 < 100 ; V_668 ++ ) {
if ( ! F_178 ( V_592 , V_667 ) )
F_152 ( 20 ) ;
else
break;
}
if ( V_668 < 100 )
F_77 ( & V_52 -> V_169 [ V_65 ] ,
V_647 , V_667 ) ;
else
F_12 ( V_592 ,
L_101 ) ;
}
F_201 ( V_592 , V_647 ) ;
}
F_52 ( V_52 , false ) ;
return 0 ;
}
static void F_202 ( struct V_1 * V_592 ,
T_3 V_68 ,
struct V_203 * V_76 )
{
T_3 V_669 , V_65 ;
V_669 = F_72 ( V_592 , V_210 ) + V_68 * V_76 -> V_208 ;
V_76 -> V_48 = V_68 ;
for ( V_65 = 0 ; V_65 < V_76 -> V_208 ; V_65 ++ ) {
V_76 -> V_213 [ V_65 ] = V_669 + V_65 ;
V_76 -> V_214 [ V_65 ] = V_669 + V_65 ;
}
}
static int F_203 ( struct V_86 * V_52 , int V_670 )
{
struct V_203 V_76 ;
int V_65 , V_667 , V_11 ;
if ( V_670 >= F_204 ( & V_52 -> V_169 [ 0 ] , V_671 ) ) {
F_6 ( V_52 , L_102 ,
F_204 ( & V_52 -> V_169 [ 0 ] , V_671 ) - 1 ) ;
return - V_12 ;
}
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
F_51 (cdev, j) {
struct V_1 * V_592 = & V_52 -> V_169 [ V_667 ] ;
struct V_69 * V_647 = F_198 ( V_592 ) ;
V_76 . V_208 = F_74 ( int ,
F_72 ( V_592 , V_212 ) / V_670 ,
16 ) ;
if ( ! V_647 ) {
F_12 ( V_592 , L_100 ) ;
V_11 = - V_606 ;
goto V_672;
}
for ( V_65 = 0 ; V_65 < V_670 ; V_65 ++ ) {
if ( ! F_10 ( V_592 , V_65 , false , true ) )
continue;
F_202 ( V_592 , V_65 , & V_76 ) ;
V_11 = F_71 ( V_592 , V_647 , & V_76 ) ;
if ( V_11 ) {
F_12 ( V_52 , L_103 , V_65 ) ;
F_201 ( V_592 , V_647 ) ;
goto V_672;
}
}
F_201 ( V_592 , V_647 ) ;
}
V_11 = F_205 ( V_52 -> V_90 , V_670 ) ;
if ( V_11 ) {
F_12 ( V_52 , L_104 , V_11 ) ;
goto V_672;
}
return V_670 ;
V_672:
F_195 ( V_52 , false ) ;
return V_11 ;
}
static int F_206 ( struct V_86 * V_52 , int V_673 )
{
if ( ! F_48 ( V_52 ) ) {
F_7 ( V_52 , V_36 , L_105 ) ;
return - V_674 ;
}
if ( V_673 )
return F_203 ( V_52 , V_673 ) ;
else
return F_195 ( V_52 , true ) ;
}
static int F_207 ( struct V_86 * V_52 , T_1 * V_304 , int V_68 )
{
int V_65 ;
if ( ! F_48 ( V_52 ) || ! F_39 ( & V_52 -> V_169 [ 0 ] ) ) {
F_7 ( V_52 , V_36 ,
L_106 ) ;
return - V_12 ;
}
if ( ! F_10 ( & V_52 -> V_169 [ 0 ] , V_68 , true , true ) ) {
F_7 ( V_52 , V_36 ,
L_107 , V_68 ) ;
return - V_12 ;
}
F_51 (cdev, i) {
struct V_1 * V_592 = & V_52 -> V_169 [ V_65 ] ;
struct V_303 * V_302 ;
V_302 = F_90 ( V_592 , V_68 , true ) ;
if ( ! V_302 )
continue;
F_106 ( V_302 -> V_675 , V_304 ) ;
F_169 ( V_592 , V_676 ) ;
}
return 0 ;
}
static int F_208 ( struct V_86 * V_52 , T_3 V_408 , int V_68 )
{
int V_65 ;
if ( ! F_48 ( V_52 ) || ! F_39 ( & V_52 -> V_169 [ 0 ] ) ) {
F_7 ( V_52 , V_36 ,
L_106 ) ;
return - V_12 ;
}
if ( ! F_10 ( & V_52 -> V_169 [ 0 ] , V_68 , true , true ) ) {
F_7 ( V_52 , V_36 ,
L_107 , V_68 ) ;
return - V_12 ;
}
F_51 (cdev, i) {
struct V_1 * V_592 = & V_52 -> V_169 [ V_65 ] ;
struct V_303 * V_302 ;
V_302 = F_90 ( V_592 , V_68 , true ) ;
if ( ! V_302 )
continue;
V_302 -> V_677 = V_408 ;
F_169 ( V_592 , V_676 ) ;
}
return 0 ;
}
static int F_209 ( struct V_86 * V_52 ,
int V_22 , struct V_678 * V_679 )
{
struct V_1 * V_592 = F_187 ( V_52 ) ;
struct V_303 * V_302 ;
struct V_221 V_109 ;
T_2 V_680 ;
if ( F_44 ( V_52 ) )
return - V_12 ;
if ( ! F_10 ( & V_52 -> V_169 [ 0 ] , V_22 , true , false ) ) {
F_7 ( V_52 , V_36 ,
L_108 , V_22 ) ;
return - V_12 ;
}
V_302 = F_90 ( V_592 , V_22 , true ) ;
F_160 ( V_592 , V_22 , NULL , & V_109 , NULL ) ;
V_679 -> V_59 = V_22 ;
if ( F_210 ( V_302 -> V_675 ) )
F_106 ( V_679 -> V_304 , V_302 -> V_675 ) ;
else
F_106 ( V_679 -> V_304 , V_302 -> V_304 ) ;
V_679 -> V_407 = V_302 -> V_677 ;
V_679 -> V_681 = F_179 ( V_592 , V_22 ) ;
V_679 -> V_682 = V_302 -> V_683 ;
V_680 = V_302 -> V_680 ;
V_679 -> V_684 = V_680 ? V_680 : V_109 . V_225 ;
V_679 -> V_685 = F_189 ( V_592 , V_22 ) ;
return 0 ;
}
void F_211 ( struct V_1 * V_592 )
{
struct V_222 V_253 ;
struct V_220 V_76 ;
struct V_221 V_109 ;
int V_65 ;
if ( ! V_592 -> V_51 )
return;
for ( V_65 = 0 ; V_65 < V_592 -> V_52 -> V_53 -> V_54 ; V_65 ++ ) {
struct V_303 * V_302 ;
V_302 = F_90 ( V_592 , V_65 , false ) ;
if ( ! V_302 )
continue;
memcpy ( & V_76 , F_78 ( V_592 ) , sizeof( V_76 ) ) ;
memcpy ( & V_109 , F_79 ( V_592 ) , sizeof( V_109 ) ) ;
memcpy ( & V_253 , F_80 ( V_592 ) ,
sizeof( V_253 ) ) ;
switch ( V_302 -> V_683 ) {
case V_686 :
V_109 . V_239 = false ;
break;
case V_687 :
V_109 . V_239 = true ;
V_109 . V_225 = ( V_592 -> V_52 -> V_362 > 1 ) ?
100000 : 40000 ;
default:
break;
}
if ( V_109 . V_239 && V_302 -> V_680 ) {
struct V_69 * V_647 ;
int V_655 ;
V_655 = F_74 ( int , V_302 -> V_680 , V_109 . V_225 ) ;
V_647 = F_198 ( V_592 ) ;
if ( ! V_647 ) {
F_6 ( V_592 , L_109 ) ;
return;
}
if ( ! F_183 ( V_592 , V_647 , V_65 , V_655 ) ) {
V_302 -> V_680 = V_655 ;
V_109 . V_225 = V_655 ;
}
F_201 ( V_592 , V_647 ) ;
}
F_76 ( V_592 , V_65 , & V_76 , & V_109 , & V_253 ) ;
}
F_169 ( V_592 , V_688 ) ;
}
static int F_212 ( struct V_86 * V_52 ,
int V_22 , int V_683 )
{
int V_65 ;
if ( F_44 ( V_52 ) )
return - V_12 ;
if ( ! F_10 ( & V_52 -> V_169 [ 0 ] , V_22 , true , true ) ) {
F_7 ( V_52 , V_36 ,
L_108 , V_22 ) ;
return - V_12 ;
}
F_51 (cdev, i) {
struct V_1 * V_592 = & V_52 -> V_169 [ V_65 ] ;
struct V_303 * V_59 ;
V_59 = F_90 ( V_592 , V_22 , true ) ;
if ( ! V_59 )
continue;
if ( V_59 -> V_683 == V_683 )
continue;
V_59 -> V_683 = V_683 ;
F_211 ( & V_52 -> V_169 [ V_65 ] ) ;
}
return 0 ;
}
static int F_213 ( struct V_86 * V_52 , int V_68 , bool V_115 )
{
int V_65 , V_11 = - V_12 ;
F_51 (cdev, i) {
struct V_1 * V_2 = & V_52 -> V_169 [ V_65 ] ;
V_11 = F_180 ( V_2 , V_68 , V_115 ) ;
if ( V_11 )
break;
}
return V_11 ;
}
static int F_214 ( struct V_86 * V_52 , int V_68 , int V_655 )
{
int V_65 ;
F_51 (cdev, i) {
struct V_1 * V_2 = & V_52 -> V_169 [ V_65 ] ;
struct V_303 * V_59 ;
if ( ! F_49 ( V_2 , V_68 ) ) {
F_6 ( V_2 ,
L_110 ) ;
return - V_12 ;
}
V_59 = F_90 ( V_2 , V_68 , true ) ;
V_59 -> V_680 = V_655 ;
F_211 ( V_2 ) ;
}
return 0 ;
}
static int F_215 ( struct V_86 * V_52 ,
int V_68 , T_2 V_689 , T_2 V_690 )
{
int V_691 = 0 , V_692 = 0 ;
if ( V_690 )
V_692 = F_214 ( V_52 , V_68 , V_690 ) ;
if ( V_689 )
V_691 = F_186 ( V_52 , V_68 , V_689 ) ;
if ( V_692 | V_691 )
return - V_12 ;
return 0 ;
}
static void F_216 ( struct V_1 * V_592 )
{
V_162 V_410 [ V_628 ] ;
struct V_69 * V_647 ;
int V_65 ;
V_647 = F_198 ( V_592 ) ;
if ( ! V_647 ) {
F_7 ( V_592 , V_36 ,
L_111 ) ;
F_169 ( V_592 , V_635 ) ;
return;
}
F_166 ( V_592 , V_410 ) ;
F_7 ( V_592 , V_36 ,
L_112 ,
V_410 [ 0 ] , V_410 [ 1 ] , V_410 [ 2 ] ) ;
F_200 (hwfn, i) {
if ( ! ( V_410 [ V_65 / 64 ] & ( 1ULL << ( V_65 % 64 ) ) ) )
continue;
F_7 ( V_592 , V_36 ,
L_113 ,
V_65 , V_592 -> V_52 -> V_53 -> V_149 + V_65 ) ;
if ( F_174 ( V_592 , V_647 , V_65 ) )
continue;
F_164 ( V_592 , V_647 , V_65 ) ;
}
F_201 ( V_592 , V_647 ) ;
}
static void F_217 ( struct V_1 * V_592 )
{
int V_65 ;
F_200 (hwfn, i) {
struct V_303 * V_693 ;
bool V_694 = false ;
T_1 * V_304 ;
V_693 = F_90 ( V_592 , V_65 , true ) ;
if ( ! V_693 )
continue;
V_304 = F_181 ( V_592 , V_65 ) ;
if ( F_210 ( V_693 -> V_675 ) &&
( ! V_304 || ! F_143 ( V_304 , V_693 -> V_675 ) ) ) {
F_7 ( V_592 ,
V_36 ,
L_114 ,
V_65 ,
V_592 -> V_52 -> V_53 -> V_149 + V_65 ) ;
F_175 ( V_592 ,
V_693 -> V_675 , V_65 ) ;
V_694 = true ;
}
if ( F_182 ( V_592 , V_65 ) ^
V_693 -> V_677 ) {
F_7 ( V_592 ,
V_36 ,
L_115 ,
V_693 -> V_677 ,
V_65 ,
V_592 -> V_52 -> V_53 -> V_149 + V_65 ) ;
F_176 ( V_592 ,
V_693 -> V_677 , V_65 ) ;
V_694 = true ;
}
if ( V_694 )
F_169 ( V_592 , V_688 ) ;
}
}
static void F_218 ( struct V_1 * V_592 )
{
struct V_69 * V_647 ;
int V_65 ;
V_647 = F_198 ( V_592 ) ;
if ( ! V_647 ) {
F_6 ( V_592 , L_116 ) ;
F_169 ( V_592 , V_688 ) ;
return;
}
F_200 (hwfn, i)
F_16 ( V_592 , V_65 , V_647 ) ;
F_201 ( V_592 , V_647 ) ;
}
static void F_219 ( struct V_695 * V_696 )
{
struct V_1 * V_592 = F_220 ( V_696 , struct V_1 ,
V_665 . V_696 ) ;
int V_11 ;
if ( F_221 ( V_697 , & V_592 -> V_663 ) )
return;
if ( F_221 ( V_698 , & V_592 -> V_663 ) ) {
struct V_69 * V_647 = F_198 ( V_592 ) ;
if ( ! V_647 ) {
F_169 ( V_592 , V_698 ) ;
return;
}
V_11 = F_157 ( V_592 , V_647 ) ;
if ( V_11 )
F_169 ( V_592 , V_698 ) ;
F_201 ( V_592 , V_647 ) ;
}
if ( F_221 ( V_635 , & V_592 -> V_663 ) )
F_216 ( V_592 ) ;
if ( F_221 ( V_676 ,
& V_592 -> V_663 ) )
F_217 ( V_592 ) ;
if ( F_221 ( V_688 ,
& V_592 -> V_663 ) )
F_218 ( V_592 ) ;
}
void F_222 ( struct V_86 * V_52 , bool V_699 )
{
int V_65 ;
F_51 (cdev, i) {
if ( ! V_52 -> V_169 [ V_65 ] . V_664 )
continue;
if ( V_699 ) {
F_169 ( & V_52 -> V_169 [ V_65 ] ,
V_697 ) ;
F_223 ( & V_52 -> V_169 [ V_65 ] . V_665 ) ;
}
F_196 ( V_52 -> V_169 [ V_65 ] . V_664 ) ;
F_224 ( V_52 -> V_169 [ V_65 ] . V_664 ) ;
}
}
int F_225 ( struct V_86 * V_52 )
{
char V_700 [ V_701 ] ;
int V_65 ;
F_51 (cdev, i) {
struct V_1 * V_2 = & V_52 -> V_169 [ V_65 ] ;
if ( F_226 ( V_2 -> V_52 ) && ! F_36 ( V_2 ) )
continue;
snprintf ( V_700 , V_701 , L_117 ,
V_52 -> V_90 -> V_702 -> V_703 ,
F_227 ( V_52 -> V_90 -> V_704 ) , V_2 -> V_165 ) ;
V_2 -> V_664 = F_228 ( V_700 ) ;
if ( ! V_2 -> V_664 ) {
F_6 ( V_2 , L_118 ) ;
return - V_159 ;
}
if ( F_226 ( V_52 ) )
F_229 ( & V_2 -> V_665 , F_219 ) ;
else
F_229 ( & V_2 -> V_665 , V_705 ) ;
}
return 0 ;
}
