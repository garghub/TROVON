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
static void F_71 ( struct V_1 * V_2 ,
T_3 V_68 ,
struct V_203 * V_76 ,
struct V_204 * V_109 ,
struct V_205 * V_206 )
{
struct V_3 * V_4 = F_11 ( V_2 ,
V_68 ,
false ) ;
struct V_71 * V_72 ;
if ( ! V_4 )
return;
V_72 = V_4 -> V_78 . V_79 ;
V_72 -> V_207 = V_76 -> V_208 . V_209 ;
V_72 -> V_210 = V_76 -> V_208 . V_211 ;
V_72 -> V_212 = V_76 -> V_208 . V_213 ;
V_72 -> V_214 = V_76 -> V_215 . V_209 ;
V_72 -> V_216 = V_76 -> V_215 . V_217 ;
V_72 -> V_218 = V_76 -> V_215 . V_219 ;
V_72 -> V_220 = V_76 -> V_221 ;
V_72 -> V_222 = V_109 -> V_222 ;
V_72 -> V_208 = V_109 -> V_208 ;
V_72 -> V_223 = V_109 -> V_223 ;
V_72 -> V_209 = V_109 -> V_224 ;
V_72 -> V_225 = V_109 -> V_226 ;
V_72 -> V_227 = V_109 -> V_227 ;
V_72 -> V_228 = V_109 -> V_228 ;
V_72 -> V_229 = V_109 -> V_229 ;
V_72 -> V_230 = V_109 -> V_230 ;
V_72 -> V_231 = V_109 -> V_231 ;
V_72 -> V_232 = V_109 -> V_232 ;
V_72 -> V_233 = V_109 -> V_233 ;
V_72 -> V_234 = V_206 -> V_235 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_236 * V_237 )
{
struct V_205 V_238 ;
struct V_203 V_239 ;
struct V_204 V_240 ;
T_1 V_241 = 0 ;
struct V_3 * V_59 = NULL ;
T_3 V_186 , V_242 ;
int V_11 = 0 ;
T_2 V_243 ;
T_1 V_65 ;
V_59 = F_11 ( V_2 , V_237 -> V_48 , false ) ;
if ( ! V_59 ) {
F_12 ( V_2 , L_23 ) ;
return - V_12 ;
}
if ( V_59 -> V_56 ) {
F_6 ( V_2 , L_24 ,
V_237 -> V_48 ) ;
return - V_12 ;
}
for ( V_65 = 0 ; V_65 < V_237 -> V_244 ; V_65 ++ ) {
T_3 V_245 = F_73 ( V_2 , V_246 ) ;
T_3 V_247 = V_245 +
F_73 ( V_2 , V_248 ) - 1 ;
V_186 = V_237 -> V_249 [ V_65 ] ;
if ( V_186 < V_245 || V_186 > V_247 ) {
F_6 ( V_2 ,
L_25 ,
V_186 ,
V_237 -> V_48 ,
V_245 , V_247 ) ;
return - V_12 ;
}
V_186 = V_237 -> V_250 [ V_65 ] ;
if ( V_186 > V_247 ) {
F_6 ( V_2 ,
L_26 ,
V_186 , V_237 -> V_48 , V_247 ) ;
return - V_12 ;
}
if ( V_186 < V_245 )
F_7 ( V_2 ,
V_36 ,
L_27 ,
V_237 -> V_48 , V_186 , V_65 ) ;
}
F_74 ( V_2 , V_251 , & V_243 ) ;
F_7 ( V_2 ,
V_36 ,
L_28 ,
V_59 -> V_58 , V_237 -> V_244 , ( T_3 ) V_243 ) ;
V_242 = F_75 ( T_3 , V_237 -> V_244 , ( ( T_3 ) V_243 ) ) ;
V_241 = F_67 ( V_2 ,
V_70 ,
V_59 , V_242 ) ;
if ( ! V_241 ) {
F_12 ( V_2 , L_29 ) ;
return - V_159 ;
}
V_59 -> V_61 = V_241 ;
V_59 -> V_63 = V_241 ;
for ( V_65 = 0 ; V_65 < V_59 -> V_61 ; V_65 ++ ) {
struct V_252 * V_253 = & V_59 -> V_187 [ V_65 ] ;
V_253 -> V_188 = V_237 -> V_249 [ V_65 ] ;
V_253 -> V_254 = V_237 -> V_250 [ V_65 ] ;
V_253 -> V_255 = V_65 ;
F_7 ( V_2 , V_36 ,
L_30 ,
V_59 -> V_58 ,
V_65 , V_59 -> V_67 [ V_65 ] ,
V_253 -> V_188 ,
V_253 -> V_254 , V_253 -> V_255 ) ;
}
memcpy ( & V_239 , F_76 ( V_2 ) ,
sizeof( V_239 ) ) ;
memcpy ( & V_240 , F_77 ( V_2 ) , sizeof( V_240 ) ) ;
memcpy ( & V_238 , F_78 ( V_2 ) ,
sizeof( V_238 ) ) ;
F_71 ( V_2 , V_237 -> V_48 ,
& V_239 , & V_240 , & V_238 ) ;
V_11 = F_58 ( V_2 , V_70 , V_59 ) ;
if ( ! V_11 ) {
V_59 -> V_56 = true ;
if ( F_79 ( V_2 ) )
V_2 -> V_52 -> V_53 -> V_97 ++ ;
}
return V_11 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_69 * V_70 , T_3 V_48 )
{
struct V_205 V_256 ;
struct V_203 V_76 ;
struct V_204 V_109 ;
struct V_3 * V_59 = NULL ;
V_59 = F_11 ( V_2 , V_48 , true ) ;
if ( ! V_59 ) {
F_12 ( V_2 , L_31 ) ;
return - V_12 ;
}
if ( V_59 -> V_78 . V_79 )
memset ( V_59 -> V_78 . V_79 , 0 , sizeof( * V_59 -> V_78 . V_79 ) ) ;
memset ( & V_59 -> V_257 , 0 , sizeof( V_59 -> V_257 ) ) ;
memcpy ( & V_76 , F_76 ( V_2 ) , sizeof( V_76 ) ) ;
memcpy ( & V_109 , F_77 ( V_2 ) , sizeof( V_109 ) ) ;
memcpy ( & V_256 , F_78 ( V_2 ) , sizeof( V_256 ) ) ;
F_71 ( V_2 , V_48 , & V_76 , & V_109 , & V_256 ) ;
memset ( & V_59 -> V_31 , 0 , sizeof( V_59 -> V_31 ) ) ;
F_57 ( V_2 , V_70 , V_59 , 0 ) ;
F_63 ( V_2 , V_70 , V_59 , 0 ) ;
V_59 -> V_61 = 0 ;
V_59 -> V_63 = 0 ;
F_70 ( V_2 , V_70 , V_59 ) ;
if ( V_59 -> V_56 ) {
V_59 -> V_56 = false ;
if ( F_79 ( V_2 ) )
V_2 -> V_52 -> V_53 -> V_97 -- ;
}
return 0 ;
}
static bool F_81 ( T_3 V_258 )
{
return V_259 < V_258 && V_258 < V_260 ;
}
void * F_82 ( struct V_1 * V_2 , T_1 * * V_99 , T_3 type , T_3 V_261 )
{
struct V_262 * V_263 = (struct V_262 * ) * V_99 ;
V_263 -> type = type ;
V_263 -> V_261 = V_261 ;
* V_99 += V_261 ;
return * V_99 - V_261 ;
}
void F_83 ( struct V_1 * V_2 , void * V_264 )
{
T_3 V_65 = 1 , V_265 = 0 ;
struct V_262 * V_266 ;
do {
V_266 = (struct V_262 * ) ( ( T_1 * ) V_264 + V_265 ) ;
F_7 ( V_2 , V_36 ,
L_32 ,
V_65 , V_266 -> type , V_266 -> V_261 ) ;
if ( V_266 -> type == V_267 )
return;
if ( ! V_266 -> V_261 ) {
F_6 ( V_2 , L_33 ) ;
return;
}
V_265 += V_266 -> V_261 ;
if ( V_265 >= sizeof( struct V_268 ) ) {
F_6 ( V_2 , L_34 ) ;
return;
}
V_65 ++ ;
} while ( 1 );
}
static void F_84 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_4 ,
T_3 V_261 , T_1 V_119 )
{
struct V_269 * V_270 = & V_4 -> V_142 ;
struct V_75 V_76 ;
T_1 V_271 ;
V_270 -> V_145 -> V_272 . V_273 . V_119 = V_119 ;
F_83 ( V_2 , V_270 -> V_145 ) ;
V_271 = V_4 -> V_37 ;
memset ( & V_76 , 0 , sizeof( struct V_75 ) ) ;
V_76 . V_82 = V_83 ;
V_76 . V_84 = V_271 ;
F_18 ( V_2 , V_70 , V_270 -> V_146 + sizeof( V_162 ) ,
V_270 -> V_143 -> V_274 . V_275 +
sizeof( V_162 ) ,
( sizeof( union V_130 ) - sizeof( V_162 ) ) / 4 ,
& V_76 ) ;
F_18 ( V_2 , V_70 , V_270 -> V_146 ,
V_270 -> V_143 -> V_274 . V_275 ,
sizeof( V_162 ) / 4 , & V_76 ) ;
F_85 ( V_2 ,
V_276 +
F_86 ( V_271 ) , 1 ) ;
}
static T_3 F_87 ( struct V_1 * V_2 ,
enum V_277 V_278 )
{
switch ( V_278 ) {
case V_279 :
return V_280 ;
case V_281 :
return V_282 ;
case V_283 :
return V_284 ;
case V_285 :
return V_286 ;
case V_287 :
return V_288 ;
case V_289 :
return V_290 ;
case V_291 :
return V_292 ;
case V_293 :
return V_294 ;
default:
return 0 ;
}
}
static T_3 F_88 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_269 * V_295 ,
T_1 V_119 ,
T_3 V_296 , T_3 V_297 )
{
struct V_298 * V_299 ;
T_3 V_81 , V_300 , V_65 ;
memset ( V_295 -> V_145 , 0 , sizeof( union V_130 ) ) ;
V_295 -> V_99 = ( T_1 * ) V_295 -> V_145 ;
V_81 = sizeof( struct V_298 ) ;
V_300 = V_81 ;
F_82 ( V_2 , & V_295 -> V_99 , V_301 , V_81 ) ;
for ( V_65 = 0 ; V_65 < V_302 ; V_65 ++ ) {
if ( ! ( V_296 & F_65 ( V_65 ) ) )
continue;
V_299 = F_82 ( V_2 , & V_295 -> V_99 ,
F_87 ( V_2 , V_65 ) , V_81 ) ;
if ( V_297 & F_65 ( V_65 ) )
V_299 -> V_273 . V_119 = V_119 ;
else
V_299 -> V_273 . V_119 = V_303 ;
F_7 ( V_2 ,
V_36 ,
L_35 ,
V_4 -> V_58 ,
F_87 ( V_2 , V_65 ) , V_299 -> V_273 . V_119 ) ;
V_300 += V_81 ;
}
F_82 ( V_2 , & V_295 -> V_99 , V_267 ,
sizeof( struct V_304 ) ) ;
return V_300 ;
}
static void F_89 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_305 ,
T_3 type , T_3 V_261 , T_1 V_119 )
{
struct V_269 * V_270 = & V_305 -> V_142 ;
V_270 -> V_99 = ( T_1 * ) V_270 -> V_145 ;
F_82 ( V_2 , & V_270 -> V_99 , type , V_261 ) ;
F_82 ( V_2 , & V_270 -> V_99 , V_267 ,
sizeof( struct V_304 ) ) ;
F_84 ( V_2 , V_70 , V_305 , V_261 , V_119 ) ;
}
static struct
V_306 * F_90 ( struct V_1 * V_2 ,
T_3 V_58 ,
bool V_49 )
{
struct V_3 * V_59 = NULL ;
V_59 = F_11 ( V_2 , V_58 , V_49 ) ;
if ( ! V_59 )
return NULL ;
return & V_59 -> V_257 ;
}
static void F_91 ( struct V_1 * V_2 , T_1 V_68 )
{
struct V_306 * V_305 ;
V_305 = F_90 ( V_2 , V_68 , false ) ;
if ( ! V_305 )
return;
F_92 ( V_305 -> V_307 ) ;
V_305 -> V_308 = 0 ;
V_305 -> V_309 = 0 ;
}
static void F_93 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_65 ;
V_4 -> V_77 = 0 ;
V_4 -> V_310 = 0 ;
V_4 -> V_311 = 0 ;
V_4 -> V_61 = V_4 -> V_66 ;
V_4 -> V_63 = V_4 -> V_66 ;
V_4 -> V_312 = 0 ;
for ( V_65 = 0 ; V_65 < V_313 ; V_65 ++ ) {
struct V_252 * V_253 = & V_4 -> V_187 [ V_65 ] ;
if ( V_253 -> V_314 ) {
F_94 ( V_2 , V_253 -> V_314 ) ;
V_253 -> V_314 = NULL ;
}
if ( V_253 -> V_315 ) {
F_94 ( V_2 , V_253 -> V_315 ) ;
V_253 -> V_315 = NULL ;
}
}
memset ( & V_4 -> V_316 , 0 , sizeof( V_4 -> V_316 ) ) ;
memset ( & V_4 -> V_31 , 0 , sizeof( V_4 -> V_31 ) ) ;
F_91 ( V_2 , V_4 -> V_58 ) ;
}
static T_1 F_95 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_4 ,
struct V_317 * V_318 ,
struct V_319 * V_320 )
{
int V_65 ;
V_320 -> V_61 = V_4 -> V_61 ;
V_320 -> V_63 = V_4 -> V_63 ;
V_320 -> V_66 = V_4 -> V_66 ;
for ( V_65 = 0 ; V_65 < V_320 -> V_66 ; V_65 ++ ) {
V_320 -> V_321 [ V_65 ] . V_322 = V_4 -> V_67 [ V_65 ] ;
V_320 -> V_321 [ V_65 ] . V_323 = 0 ;
}
for ( V_65 = 0 ; V_65 < V_320 -> V_61 ; V_65 ++ ) {
F_64 ( V_2 , V_4 -> V_187 [ V_65 ] . V_188 ,
( T_3 * ) & V_320 -> V_324 [ V_65 ] ) ;
V_320 -> V_14 [ V_65 ] = V_4 -> V_187 [ V_65 ] . V_255 ;
}
V_320 -> V_151 = F_75 ( T_1 , V_4 -> V_151 ,
V_318 -> V_151 ) ;
V_320 -> V_153 = F_75 ( T_1 , V_4 -> V_153 ,
V_318 -> V_153 ) ;
V_320 -> V_325 = V_326 ;
if ( V_320 -> V_61 < V_318 -> V_61 ||
V_320 -> V_63 < V_318 -> V_63 ||
V_320 -> V_66 < V_318 -> V_66 ||
V_320 -> V_151 < V_318 -> V_151 ||
V_320 -> V_153 < V_318 -> V_153 ||
V_320 -> V_325 < V_318 -> V_325 ) {
F_7 ( V_2 ,
V_36 ,
L_36 ,
V_4 -> V_37 ,
V_318 -> V_61 ,
V_320 -> V_61 ,
V_318 -> V_61 ,
V_320 -> V_63 ,
V_318 -> V_66 ,
V_320 -> V_66 ,
V_318 -> V_151 ,
V_320 -> V_151 ,
V_318 -> V_153 ,
V_320 -> V_153 ,
V_318 -> V_325 , V_320 -> V_325 ) ;
if ( ( V_4 -> V_31 . V_32 . V_33 ==
V_35 ) &&
( V_4 -> V_31 . V_32 . V_327 ==
V_328 ) )
return V_329 ;
return V_330 ;
}
return V_329 ;
}
static void F_96 ( struct V_1 * V_2 ,
struct V_331 * V_332 )
{
V_332 -> V_333 . V_334 = V_335 +
F_97 ( struct V_336 ,
V_337 . V_338 ) ;
V_332 -> V_333 . V_339 = sizeof( struct V_340 ) ;
V_332 -> V_341 . V_334 = V_342 +
F_97 ( struct V_343 ,
V_337 . V_338 ) ;
V_332 -> V_341 . V_339 = sizeof( struct V_344 ) ;
V_332 -> V_345 . V_334 = V_346 +
F_97 ( struct V_347 ,
V_337 . V_338 ) ;
V_332 -> V_345 . V_339 = sizeof( struct V_348 ) ;
V_332 -> V_349 . V_334 = 0 ;
V_332 -> V_349 . V_339 = 0 ;
}
static void F_98 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 )
{
struct V_269 * V_270 = & V_59 -> V_142 ;
struct V_350 * V_299 = & V_270 -> V_145 -> V_351 ;
struct V_352 * V_353 = & V_299 -> V_353 ;
struct V_354 * V_355 = & V_270 -> V_143 -> V_31 ;
T_1 V_356 = V_303 ;
struct V_319 * V_357 = & V_299 -> V_357 ;
int V_11 ;
memset ( V_299 , 0 , sizeof( * V_299 ) ) ;
V_353 -> V_358 = V_38 ;
V_353 -> V_359 = V_34 ;
if ( V_59 -> V_147 != V_183 && V_59 -> V_147 != V_148 ) {
F_7 ( V_2 ,
V_36 ,
L_37 ,
V_59 -> V_37 , V_59 -> V_147 ) ;
goto V_360;
}
if ( V_355 -> V_32 . V_361 != V_38 ) {
if ( V_355 -> V_32 . V_362 &
V_363 ) {
struct V_364 * V_365 = & V_355 -> V_32 ;
F_7 ( V_2 , V_36 ,
L_38 ,
V_59 -> V_37 ) ;
V_365 -> V_361 = V_38 ;
V_365 -> V_33 = V_35 ;
} else {
F_99 ( V_2 ,
L_39 ,
V_59 -> V_37 ,
V_355 -> V_32 . V_361 ,
V_355 -> V_32 . V_33 ,
V_38 , V_34 ) ;
goto V_360;
}
}
if ( ( V_2 -> V_52 -> V_366 > 1 ) &&
! ( V_355 -> V_32 . V_362 & V_367 ) ) {
F_99 ( V_2 ,
L_40 ,
V_59 -> V_37 ) ;
goto V_360;
}
memcpy ( & V_59 -> V_31 , V_355 , sizeof( V_59 -> V_31 ) ) ;
V_59 -> V_15 = V_355 -> V_32 . V_15 ;
V_59 -> V_77 = V_355 -> V_368 ;
V_59 -> V_78 . V_81 = ( V_59 -> V_78 . V_81 < V_355 -> V_369 ) ?
V_59 -> V_78 . V_81 : V_355 -> V_369 ;
V_353 -> V_370 = V_2 -> V_52 -> V_370 ;
V_353 -> V_371 = 0 ;
V_353 -> V_372 = V_373 ;
V_353 -> V_362 = V_374 |
V_375 ;
if ( V_2 -> V_52 -> V_366 > 1 )
V_353 -> V_362 |= V_376 ;
F_96 ( V_2 , & V_353 -> V_377 ) ;
memcpy ( V_353 -> V_378 , V_2 -> V_25 . V_379 , V_380 ) ;
V_353 -> V_381 = V_382 ;
V_353 -> V_383 = V_384 ;
V_353 -> V_385 = V_386 ;
V_353 -> V_387 = V_388 ;
V_353 -> V_359 = F_75 ( T_1 , V_34 ,
V_355 -> V_32 . V_33 ) ;
V_353 -> V_327 = V_389 ;
F_100 ( V_2 , V_70 , & V_353 -> V_390 , NULL ) ;
V_353 -> V_391 = V_2 -> V_52 -> type ;
V_353 -> V_392 = V_2 -> V_52 -> V_392 ;
V_356 = F_95 ( V_2 , V_70 , V_59 ,
& V_355 -> V_393 , V_357 ) ;
if ( V_356 != V_329 )
goto V_360;
V_11 = F_1 ( V_2 , V_59 ) ;
if ( V_11 ) {
F_6 ( V_2 , L_41 , V_59 -> V_37 ) ;
V_356 = V_394 ;
goto V_360;
}
V_299 -> V_369 = V_59 -> V_78 . V_81 ;
F_16 ( V_2 , V_59 -> V_58 , V_70 ) ;
F_7 ( V_2 ,
V_36 ,
L_42
L_43 ,
V_59 -> V_37 ,
V_299 -> V_353 . V_370 ,
V_299 -> V_353 . V_371 ,
V_299 -> V_353 . V_372 ,
V_299 -> V_353 . V_362 ,
V_357 -> V_61 ,
V_357 -> V_63 ,
V_357 -> V_66 ,
V_357 -> V_151 ,
V_357 -> V_153 ) ;
V_59 -> V_147 = V_395 ;
V_360:
F_89 ( V_2 , V_70 , V_59 , V_396 ,
sizeof( struct V_350 ) , V_356 ) ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_115 )
{
struct V_397 V_76 ;
int V_11 ;
if ( V_115 == V_4 -> V_398 ) {
F_7 ( V_2 , V_36 ,
L_44 , V_115 ) ;
return 0 ;
}
memset ( & V_76 , 0 , sizeof( struct V_397 ) ) ;
V_76 . V_15 = V_4 -> V_15 ;
V_76 . V_150 = V_4 -> V_150 ;
V_76 . V_399 = 1 ;
V_76 . V_400 = V_115 ;
V_11 = F_102 ( V_2 , & V_76 , V_17 , NULL ) ;
if ( ! V_11 ) {
V_4 -> V_398 = V_115 ;
V_4 -> V_401 = V_4 -> V_398 ;
F_7 ( V_2 , V_36 ,
L_45 , V_115 ) ;
} else {
F_7 ( V_2 , V_36 ,
L_46 ,
V_115 , V_4 -> V_58 ) ;
}
return V_11 ;
}
static int F_103 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_402 V_403 ;
int V_11 = 0 ;
int V_65 ;
memset ( & V_403 , 0 , sizeof( V_403 ) ) ;
V_403 . V_404 = 1 ;
V_403 . V_405 = 1 ;
V_403 . V_406 = V_4 -> V_150 ;
V_403 . V_407 = V_408 ;
for ( V_65 = 0 ; V_65 < V_154 + 1 ; V_65 ++ ) {
if ( ! V_4 -> V_316 . V_409 [ V_65 ] . V_410 )
continue;
V_403 . type = V_411 ;
V_403 . V_412 = V_4 -> V_316 . V_409 [ V_65 ] . V_413 ;
F_7 ( V_2 , V_36 ,
L_47 ,
V_403 . V_412 , V_4 -> V_58 ) ;
V_11 = F_104 ( V_2 , V_4 -> V_15 ,
& V_403 , V_414 , NULL ) ;
if ( V_11 ) {
F_6 ( V_2 ,
L_48 ,
V_403 . V_412 , V_4 -> V_58 ) ;
break;
}
}
return V_11 ;
}
static int
F_105 ( struct V_1 * V_2 ,
struct V_3 * V_4 , V_162 V_415 )
{
int V_11 = 0 ;
if ( ( V_415 & F_65 ( V_416 ) ) &&
! ( V_4 -> V_311 & ( 1 << V_416 ) ) )
V_11 = F_103 ( V_2 , V_4 ) ;
return V_11 ;
}
static int F_106 ( struct V_1 * V_2 ,
struct V_3 * V_4 , V_162 V_415 )
{
int V_11 = 0 ;
struct V_402 V_403 ;
if ( ! V_4 -> V_310 )
return - V_12 ;
if ( V_415 & F_65 ( V_417 ) ) {
memset ( & V_403 , 0 , sizeof( V_403 ) ) ;
V_403 . type = V_418 ;
V_403 . V_407 = V_419 ;
V_403 . V_404 = 1 ;
V_403 . V_405 = 1 ;
V_403 . V_406 = V_4 -> V_150 ;
F_107 ( V_403 . V_307 , V_4 -> V_78 . V_79 -> V_307 ) ;
V_11 = F_104 ( V_2 , V_4 -> V_15 ,
& V_403 , V_414 , NULL ) ;
if ( V_11 ) {
F_6 ( V_2 ,
L_49 ) ;
return V_11 ;
}
V_4 -> V_311 |= 1 << V_417 ;
}
if ( V_415 & F_65 ( V_416 ) ) {
struct V_397 V_420 ;
T_1 V_421 ;
int V_65 ;
memset ( & V_403 , 0 , sizeof( V_403 ) ) ;
V_403 . type = V_411 ;
V_403 . V_404 = 1 ;
V_403 . V_405 = 1 ;
V_403 . V_406 = V_4 -> V_150 ;
V_403 . V_412 = V_4 -> V_78 . V_79 -> V_422 ;
V_403 . V_407 = V_403 . V_412 ? V_419 :
V_423 ;
V_11 = F_104 ( V_2 , V_4 -> V_15 ,
& V_403 , V_414 , NULL ) ;
if ( V_11 ) {
F_6 ( V_2 ,
L_50 ) ;
return V_11 ;
}
memset ( & V_420 , 0 , sizeof( V_420 ) ) ;
V_420 . V_15 = V_4 -> V_15 ;
V_420 . V_150 = V_4 -> V_150 ;
V_420 . V_424 = 1 ;
V_420 . V_425 = V_403 . V_412 ? 1 : 0 ;
V_420 . V_426 = 1 ;
V_420 . V_427 = V_403 . V_412 ;
V_420 . V_428 = 1 ;
V_421 = V_403 . V_412 ? 1
: V_4 -> V_316 . V_429 ;
V_420 . V_430 = V_421 ;
V_420 . V_431 = V_403 . V_412 ? 1 : 0 ;
V_11 = F_102 ( V_2 ,
& V_420 ,
V_17 , NULL ) ;
if ( V_11 ) {
F_6 ( V_2 ,
L_51 ) ;
return V_11 ;
}
for ( V_65 = 0 ; V_65 < V_313 ; V_65 ++ ) {
struct V_432 * V_433 ;
V_433 = V_4 -> V_187 [ V_65 ] . V_314 ;
if ( ! V_433 )
continue;
V_11 = F_108 ( V_2 ,
( void * * ) & V_433 ,
1 , 0 , 1 ,
V_17 ,
NULL ) ;
if ( V_11 ) {
F_6 ( V_2 ,
L_52 ,
V_433 -> V_434 . V_435 ) ;
return V_11 ;
}
}
if ( V_403 . V_412 )
V_4 -> V_311 |= 1 << V_416 ;
else
V_4 -> V_311 &= ~ F_65 ( V_416 ) ;
}
if ( V_415 )
F_105 ( V_2 , V_4 , V_415 ) ;
return V_11 ;
}
static void F_109 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 )
{
struct V_436 V_76 = { 0 } ;
struct V_269 * V_270 = & V_59 -> V_142 ;
struct V_437 * V_438 ;
T_1 V_119 = V_329 ;
struct V_3 * V_305 ;
V_162 * V_439 ;
int V_114 ;
int V_11 ;
V_305 = F_11 ( V_2 , ( T_3 ) V_59 -> V_58 , true ) ;
if ( ! V_305 ) {
F_6 ( V_2 -> V_52 ,
L_53 ,
V_59 -> V_58 ) ;
return;
}
V_59 -> V_147 = V_440 ;
V_438 = & V_270 -> V_143 -> V_441 ;
for ( V_114 = 0 ; V_114 < V_59 -> V_66 ; V_114 ++ ) {
if ( ! V_438 -> V_442 [ V_114 ] ) {
F_7 ( V_2 , V_36 ,
L_54 ,
V_59 -> V_58 , V_114 ) ;
break;
}
F_110 ( V_2 , V_70 ,
V_438 -> V_442 [ V_114 ] ,
V_59 -> V_67 [ V_114 ] , V_59 -> V_37 , 1 ) ;
}
F_66 ( V_2 , V_70 , V_59 ) ;
V_59 -> V_443 = V_438 -> V_443 ;
V_59 -> V_316 . V_429 = V_438 -> V_429 ;
V_439 = & V_305 -> V_78 . V_79 -> V_444 ;
if ( ! ( * V_439 & F_65 ( V_445 ) ) ) {
T_1 V_446 = V_438 -> V_447 ;
V_305 -> V_78 . V_79 -> V_448 = V_446 ;
* V_439 |= 1 << V_449 ;
}
V_76 . V_450 = V_438 -> V_450 ;
V_76 . V_451 = V_438 -> V_429 ;
V_76 . V_452 = true ;
V_76 . V_447 = V_305 -> V_78 . V_79 -> V_448 ;
V_76 . V_453 = false ;
V_76 . V_23 = V_59 -> V_23 ;
V_76 . V_15 = V_59 -> V_15 ;
V_76 . V_150 = V_59 -> V_150 ;
V_76 . V_454 = V_438 -> V_454 ;
V_76 . V_443 = V_59 -> V_443 ;
V_76 . V_455 = true ;
V_11 = F_111 ( V_2 , & V_76 ) ;
if ( V_11 ) {
F_12 ( V_2 ,
L_55 , V_11 ) ;
V_119 = V_394 ;
} else {
V_59 -> V_310 ++ ;
F_106 ( V_2 , V_59 , * V_439 ) ;
F_101 ( V_2 , V_59 , V_59 -> V_401 ) ;
}
F_89 ( V_2 , V_70 , V_59 , V_456 ,
sizeof( struct V_298 ) , V_119 ) ;
}
static void F_112 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 )
{
T_1 V_119 = V_329 ;
int V_11 ;
V_59 -> V_310 -- ;
V_59 -> V_398 = false ;
V_11 = F_113 ( V_2 , V_59 -> V_15 , V_59 -> V_150 ) ;
if ( V_11 ) {
F_12 ( V_2 , L_56 ,
V_11 ) ;
V_119 = V_394 ;
}
V_59 -> V_311 = 0 ;
memset ( & V_59 -> V_316 , 0 , sizeof( V_59 -> V_316 ) ) ;
F_89 ( V_2 , V_70 , V_59 , V_457 ,
sizeof( struct V_298 ) , V_119 ) ;
}
static void F_114 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 ,
T_1 V_119 , bool V_458 )
{
struct V_269 * V_270 = & V_59 -> V_142 ;
struct V_459 * V_460 ;
struct V_461 * V_355 ;
T_3 V_261 ;
V_270 -> V_99 = ( T_1 * ) V_270 -> V_145 ;
if ( ! V_458 )
V_261 = sizeof( * V_460 ) ;
else
V_261 = sizeof( struct V_298 ) ;
V_460 = F_82 ( V_2 , & V_270 -> V_99 , V_462 ,
V_261 ) ;
F_82 ( V_2 , & V_270 -> V_99 , V_267 ,
sizeof( struct V_304 ) ) ;
if ( ( V_119 == V_329 ) && ! V_458 ) {
V_355 = & V_270 -> V_143 -> V_463 ;
V_460 -> V_99 = V_335 +
F_97 ( struct V_336 ,
V_337 . V_464 ) +
sizeof( struct V_465 ) * V_355 -> V_60 ;
}
F_84 ( V_2 , V_70 , V_59 , V_261 , V_119 ) ;
}
static void F_115 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 )
{
struct V_466 V_76 ;
struct V_269 * V_270 = & V_59 -> V_142 ;
T_1 V_119 = V_330 ;
struct V_252 * V_253 ;
struct V_461 * V_355 ;
bool V_467 = false ;
int V_11 ;
V_355 = & V_270 -> V_143 -> V_463 ;
if ( ! F_13 ( V_2 , V_59 , V_355 -> V_60 ) ||
! F_15 ( V_2 , V_59 , V_355 -> V_468 ) )
goto V_360;
V_253 = & V_59 -> V_187 [ V_355 -> V_60 ] ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_76 . V_435 = V_253 -> V_188 ;
V_76 . V_150 = V_59 -> V_150 ;
V_76 . V_469 = V_59 -> V_37 + 0x10 ;
V_76 . V_470 = V_355 -> V_468 ;
V_76 . V_64 = V_355 -> V_471 ;
V_253 -> V_314 = F_116 ( V_2 ,
V_59 -> V_15 ,
V_253 -> V_255 ,
V_355 -> V_60 , & V_76 ) ;
if ( ! V_253 -> V_314 )
goto V_360;
if ( V_59 -> V_31 . V_32 . V_33 ==
V_35 ) {
V_467 = true ;
} else {
F_85 ( V_2 ,
V_472 +
F_117 ( V_59 -> V_37 , V_355 -> V_60 ) ,
0 ) ;
}
V_253 -> V_314 -> V_467 = V_467 ;
V_11 = F_118 ( V_2 ,
V_253 -> V_314 ,
V_355 -> V_473 ,
V_355 -> V_474 ,
V_355 -> V_475 , V_355 -> V_476 ) ;
if ( V_11 ) {
V_119 = V_394 ;
F_94 ( V_2 , V_253 -> V_314 ) ;
V_253 -> V_314 = NULL ;
} else {
V_119 = V_329 ;
V_59 -> V_312 ++ ;
}
V_360:
F_114 ( V_2 , V_70 , V_59 , V_119 , V_467 ) ;
}
static void F_119 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_4 , T_1 V_119 )
{
struct V_269 * V_270 = & V_4 -> V_142 ;
struct V_459 * V_460 ;
bool V_458 = false ;
T_3 V_261 ;
V_270 -> V_99 = ( T_1 * ) V_270 -> V_145 ;
if ( V_4 -> V_31 . V_32 . V_33 ==
V_35 )
V_458 = true ;
if ( ! V_458 )
V_261 = sizeof( * V_460 ) ;
else
V_261 = sizeof( struct V_298 ) ;
V_460 = F_82 ( V_2 , & V_270 -> V_99 , V_477 ,
V_261 ) ;
F_82 ( V_2 , & V_270 -> V_99 , V_267 ,
sizeof( struct V_304 ) ) ;
if ( ( V_119 == V_329 ) && ! V_458 ) {
T_3 V_186 = V_270 -> V_143 -> V_478 . V_62 ;
V_460 -> V_99 = F_120 ( V_4 -> V_187 [ V_186 ] . V_255 ,
V_479 ) ;
}
F_84 ( V_2 , V_70 , V_4 , V_261 , V_119 ) ;
}
static void F_121 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 )
{
struct V_466 V_76 ;
struct V_269 * V_270 = & V_59 -> V_142 ;
T_1 V_119 = V_330 ;
union V_480 V_481 ;
struct V_482 * V_355 ;
struct V_252 * V_253 ;
int V_11 ;
T_3 V_483 ;
memset ( & V_481 , 0 , sizeof( V_481 ) ) ;
V_481 . V_484 . V_485 = 1 ;
V_481 . V_484 . V_22 = V_59 -> V_58 ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_355 = & V_270 -> V_143 -> V_478 ;
if ( ! F_14 ( V_2 , V_59 , V_355 -> V_62 ) ||
! F_15 ( V_2 , V_59 , V_355 -> V_468 ) )
goto V_360;
V_253 = & V_59 -> V_187 [ V_355 -> V_62 ] ;
V_76 . V_435 = V_253 -> V_254 ;
V_76 . V_150 = V_59 -> V_150 ;
V_76 . V_469 = V_59 -> V_37 + 0x10 ;
V_76 . V_470 = V_355 -> V_468 ;
V_76 . V_64 = V_355 -> V_471 ;
V_253 -> V_315 = F_116 ( V_2 ,
V_59 -> V_15 ,
V_253 -> V_255 ,
V_355 -> V_62 , & V_76 ) ;
if ( ! V_253 -> V_315 )
goto V_360;
V_483 = F_122 ( V_2 , V_251 , & V_481 ) ;
V_11 = F_123 ( V_2 , V_253 -> V_315 ,
V_355 -> V_486 , V_355 -> V_487 , V_483 ) ;
if ( V_11 ) {
V_119 = V_394 ;
F_94 ( V_2 , V_253 -> V_315 ) ;
V_253 -> V_315 = NULL ;
} else {
V_119 = V_329 ;
}
V_360:
F_119 ( V_2 , V_70 , V_59 , V_119 ) ;
}
static int F_124 ( struct V_1 * V_2 ,
struct V_3 * V_59 ,
T_3 V_488 , T_1 V_61 , bool V_489 )
{
struct V_252 * V_253 ;
int V_11 = 0 ;
int V_186 ;
if ( V_488 + V_61 > F_125 ( V_59 -> V_187 ) )
return - V_12 ;
for ( V_186 = V_488 ; V_186 < V_488 + V_61 ; V_186 ++ ) {
V_253 = & V_59 -> V_187 [ V_186 ] ;
if ( ! V_253 -> V_314 )
continue;
V_11 = F_126 ( V_2 ,
V_253 -> V_314 ,
false , V_489 ) ;
if ( V_11 )
return V_11 ;
V_59 -> V_187 [ V_186 ] . V_314 = NULL ;
V_59 -> V_312 -- ;
}
return V_11 ;
}
static int F_127 ( struct V_1 * V_2 ,
struct V_3 * V_59 , T_3 V_490 , T_1 V_63 )
{
int V_11 = 0 ;
struct V_252 * V_253 ;
int V_186 ;
if ( V_490 + V_63 > F_125 ( V_59 -> V_187 ) )
return - V_12 ;
for ( V_186 = V_490 ; V_186 < V_490 + V_63 ; V_186 ++ ) {
V_253 = & V_59 -> V_187 [ V_186 ] ;
if ( ! V_253 -> V_315 )
continue;
V_11 = F_128 ( V_2 , V_253 -> V_315 ) ;
if ( V_11 )
return V_11 ;
V_253 -> V_315 = NULL ;
}
return V_11 ;
}
static void F_129 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 )
{
T_3 V_261 = sizeof( struct V_298 ) ;
struct V_269 * V_270 = & V_59 -> V_142 ;
T_1 V_119 = V_329 ;
struct V_491 * V_355 ;
int V_11 ;
V_355 = & V_270 -> V_143 -> V_492 ;
V_11 = F_124 ( V_2 , V_59 , V_355 -> V_60 ,
V_355 -> V_61 , V_355 -> V_489 ) ;
if ( V_11 )
V_119 = V_394 ;
F_89 ( V_2 , V_70 , V_59 , V_493 ,
V_261 , V_119 ) ;
}
static void F_130 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 )
{
T_3 V_261 = sizeof( struct V_298 ) ;
struct V_269 * V_270 = & V_59 -> V_142 ;
T_1 V_119 = V_329 ;
struct V_494 * V_355 ;
int V_11 ;
V_355 = & V_270 -> V_143 -> V_495 ;
V_11 = F_127 ( V_2 , V_59 , V_355 -> V_62 , V_355 -> V_63 ) ;
if ( V_11 )
V_119 = V_394 ;
F_89 ( V_2 , V_70 , V_59 , V_496 ,
V_261 , V_119 ) ;
}
static void F_131 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 )
{
struct V_432 * V_497 [ V_313 ] ;
T_3 V_261 = sizeof( struct V_298 ) ;
struct V_269 * V_270 = & V_59 -> V_142 ;
struct V_498 * V_355 ;
T_1 V_119 = V_394 ;
T_1 V_499 ;
T_1 V_500 ;
T_3 V_186 ;
int V_11 ;
T_1 V_65 ;
V_355 = & V_270 -> V_143 -> V_501 ;
V_500 = ! ! ( V_355 -> V_82 & V_502 ) ;
V_499 = ! ! ( V_355 -> V_82 & V_503 ) ;
if ( V_355 -> V_61 + V_355 -> V_60 > V_313 ||
! F_13 ( V_2 , V_59 , V_355 -> V_60 ) ) {
F_99 ( V_2 , L_57 ,
V_59 -> V_58 , V_355 -> V_60 , V_355 -> V_61 ) ;
goto V_360;
}
for ( V_65 = 0 ; V_65 < V_355 -> V_61 ; V_65 ++ ) {
V_186 = V_355 -> V_60 + V_65 ;
if ( ! V_59 -> V_187 [ V_186 ] . V_314 ) {
F_99 ( V_2 ,
L_58 ,
V_59 -> V_58 , V_186 ) ;
goto V_360;
}
V_497 [ V_65 ] = V_59 -> V_187 [ V_186 ] . V_314 ;
}
V_11 = F_108 ( V_2 , ( void * * ) & V_497 ,
V_355 -> V_61 ,
V_500 ,
V_499 ,
V_17 , NULL ) ;
if ( V_11 )
goto V_360;
V_119 = V_329 ;
V_360:
F_89 ( V_2 , V_70 , V_59 , V_504 ,
V_261 , V_119 ) ;
}
void * F_132 ( struct V_1 * V_2 ,
void * V_505 , T_3 V_506 )
{
struct V_262 * V_460 = (struct V_262 * ) V_505 ;
int V_339 = 0 ;
do {
if ( ! V_460 -> V_261 ) {
F_6 ( V_2 , L_59 ) ;
return NULL ;
}
if ( V_460 -> type == V_506 ) {
F_7 ( V_2 , V_36 ,
L_60 ,
V_460 -> type , V_460 -> V_261 ) ;
return V_460 ;
}
V_339 += V_460 -> V_261 ;
V_460 = (struct V_262 * ) ( ( T_1 * ) V_460 + V_460 -> V_261 ) ;
if ( ( V_339 + V_460 -> V_261 ) > V_507 ) {
F_6 ( V_2 , L_61 ) ;
return NULL ;
}
} while ( V_460 -> type != V_267 );
return NULL ;
}
static void
F_133 ( struct V_1 * V_2 ,
struct V_397 * V_508 ,
struct V_269 * V_295 , T_3 * V_296 )
{
struct V_509 * V_510 ;
T_3 V_266 = V_280 ;
V_510 = (struct V_509 * )
F_132 ( V_2 , V_295 -> V_143 , V_266 ) ;
if ( ! V_510 )
return;
V_508 -> V_511 = V_510 -> V_512 ;
V_508 -> V_513 = V_510 -> V_514 ;
V_508 -> V_515 = V_510 -> V_516 ;
V_508 -> V_517 = V_510 -> V_518 ;
* V_296 |= 1 << V_279 ;
}
static void
F_134 ( struct V_1 * V_2 ,
struct V_397 * V_508 ,
struct V_3 * V_4 ,
struct V_269 * V_295 , T_3 * V_296 )
{
struct V_519 * V_520 ;
T_3 V_266 = V_282 ;
V_520 = (struct V_519 * )
F_132 ( V_2 , V_295 -> V_143 , V_266 ) ;
if ( ! V_520 )
return;
V_4 -> V_316 . V_429 = V_520 -> V_521 ;
if ( ! ( V_4 -> V_311 & F_65 ( V_416 ) ) ) {
V_508 -> V_428 = 1 ;
V_508 -> V_430 = V_520 -> V_521 ;
}
* V_296 |= 1 << V_281 ;
}
static void
F_135 ( struct V_1 * V_2 ,
struct V_397 * V_508 ,
struct V_269 * V_295 , T_3 * V_296 )
{
struct V_522 * V_523 ;
T_3 V_266 = V_284 ;
V_523 = (struct V_522 * )
F_132 ( V_2 , V_295 -> V_143 ,
V_266 ) ;
if ( ! V_523 )
return;
V_508 -> V_524 = 1 ;
V_508 -> V_525 = V_523 -> V_452 ;
* V_296 |= 1 << V_283 ;
}
static void
F_136 ( struct V_1 * V_2 ,
struct V_397 * V_508 ,
struct V_269 * V_295 , T_3 * V_296 )
{
struct V_526 * V_527 ;
T_3 V_266 = V_286 ;
V_527 = (struct V_526 * )
F_132 ( V_2 , V_295 -> V_143 , V_266 ) ;
if ( ! V_527 )
return;
V_508 -> V_528 = 1 ;
memcpy ( V_508 -> V_529 , V_527 -> V_529 ,
sizeof( unsigned long ) * V_530 ) ;
* V_296 |= 1 << V_285 ;
}
static void
F_137 ( struct V_1 * V_2 ,
struct V_397 * V_508 ,
struct V_269 * V_295 , T_3 * V_296 )
{
struct V_531 * V_532 = & V_508 -> V_533 ;
struct V_534 * V_535 ;
T_3 V_266 = V_288 ;
V_535 = (struct V_534 * )
F_132 ( V_2 , V_295 -> V_143 , V_266 ) ;
if ( ! V_535 )
return;
V_532 -> V_536 = V_535 -> V_537 ;
V_532 -> V_538 = V_535 -> V_538 ;
V_532 -> V_539 = V_535 -> V_540 ;
V_532 -> V_541 = V_535 -> V_541 ;
* V_296 |= 1 << V_287 ;
}
static void
F_138 ( struct V_1 * V_2 ,
struct V_397 * V_508 ,
struct V_269 * V_295 , T_3 * V_296 )
{
struct V_542 * V_543 ;
T_3 V_266 = V_292 ;
V_543 = (struct V_542 * )
F_132 ( V_2 , V_295 -> V_143 ,
V_266 ) ;
if ( ! V_543 )
return;
V_508 -> V_544 = V_543 -> V_544 ;
V_508 -> V_545 =
V_543 -> V_545 ;
* V_296 |= 1 << V_291 ;
}
static void
F_139 ( struct V_1 * V_2 ,
struct V_3 * V_59 ,
struct V_397 * V_508 ,
struct V_546 * V_547 ,
struct V_269 * V_295 ,
T_3 * V_296 , T_3 * V_297 )
{
struct V_548 * V_549 ;
T_3 V_266 = V_290 ;
bool V_550 = false ;
T_3 V_551 ;
T_3 V_65 , V_552 ;
V_549 = (struct V_548 * )
F_132 ( V_2 , V_295 -> V_143 , V_266 ) ;
if ( ! V_549 ) {
V_508 -> V_553 = NULL ;
return;
}
memset ( V_547 , 0 , sizeof( struct V_546 ) ) ;
V_547 -> V_554 = ! ! ( V_549 -> V_555 &
V_556 ) ;
V_547 -> V_557 = ! ! ( V_549 -> V_555 &
V_558 ) ;
V_547 -> V_559 = ! ! ( V_549 -> V_555 &
V_560 ) ;
V_547 -> V_561 = ! ! ( V_549 -> V_555 &
V_562 ) ;
V_547 -> V_563 = V_549 -> V_563 ;
V_547 -> V_564 = V_59 -> V_58 + 1 ;
V_547 -> V_565 = V_549 -> V_565 ;
V_547 -> V_566 = V_549 -> V_566 ;
memcpy ( V_547 -> V_567 , V_549 -> V_567 , sizeof( V_547 -> V_567 ) ) ;
V_551 = F_75 ( T_3 , F_125 ( V_547 -> V_568 ) ,
( 1 << V_549 -> V_566 ) ) ;
for ( V_65 = 0 ; V_65 < V_551 ; V_65 ++ ) {
V_552 = V_549 -> V_568 [ V_65 ] ;
if ( ! F_13 ( V_2 , V_59 , V_552 ) ) {
F_7 ( V_2 ,
V_36 ,
L_62 ,
V_59 -> V_58 , V_552 ) ;
V_550 = true ;
goto V_360;
}
if ( ! V_59 -> V_187 [ V_552 ] . V_314 ) {
F_7 ( V_2 ,
V_36 ,
L_63 ,
V_59 -> V_58 , V_552 ) ;
V_550 = true ;
goto V_360;
}
V_547 -> V_568 [ V_65 ] = V_59 -> V_187 [ V_552 ] . V_314 ;
}
V_508 -> V_553 = V_547 ;
V_360:
* V_296 |= 1 << V_289 ;
if ( ! V_550 )
* V_297 |= 1 << V_289 ;
}
static void
F_140 ( struct V_1 * V_2 ,
struct V_3 * V_59 ,
struct V_397 * V_508 ,
struct V_569 * V_570 ,
struct V_269 * V_295 , T_3 * V_296 )
{
struct V_571 * V_572 ;
T_3 V_266 = V_294 ;
V_572 = (struct V_571 * )
F_132 ( V_2 , V_295 -> V_143 , V_266 ) ;
if ( ! V_572 ) {
V_508 -> V_573 = NULL ;
return;
}
memset ( V_570 , 0 , sizeof( struct V_569 ) ) ;
V_570 -> V_574 =
! ! ( V_572 -> V_575 & V_576 ) ;
V_570 -> V_577 =
! ! ( V_572 -> V_575 &
V_578 ) ;
V_570 -> V_579 =
! ! ( V_572 -> V_580 & V_581 ) ;
V_570 -> V_582 =
! ! ( V_572 -> V_580 & V_583 ) ;
V_570 -> V_584 =
! ! ( V_572 -> V_580 & V_585 ) ;
V_570 -> V_586 =
! ! ( V_572 -> V_580 & V_587 ) ;
V_570 -> V_588 =
! ! ( V_572 -> V_580 & V_589 ) ;
V_570 -> V_590 = V_572 -> V_590 ;
V_570 -> V_591 = V_572 -> V_591 ;
V_570 -> V_592 = V_572 -> V_592 ;
V_570 -> V_593 = V_572 -> V_593 ;
V_570 -> V_454 = V_572 -> V_454 ;
V_508 -> V_573 = V_570 ;
* V_296 |= 1 << V_293 ;
}
static int F_141 ( struct V_1 * V_594 ,
T_1 V_68 ,
struct V_397 * V_76 ,
T_3 * V_595 )
{
T_1 V_596 = V_597 | V_598 ;
struct V_531 * V_82 = & V_76 -> V_533 ;
struct V_306 * V_305 ;
if ( ! ( * V_595 & F_65 ( V_287 ) ) )
return 0 ;
V_305 = F_90 ( V_594 , V_68 , true ) ;
if ( V_82 -> V_536 ) {
V_305 -> V_308 = V_82 -> V_538 ;
if ( ! V_305 -> V_599 )
V_82 -> V_538 &= ~ V_596 ;
}
if ( V_82 -> V_539 ) {
V_305 -> V_309 = V_82 -> V_541 ;
if ( ! V_305 -> V_599 )
V_82 -> V_541 &= ~ V_596 ;
}
return 0 ;
}
static void F_142 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 )
{
struct V_546 * V_600 = NULL ;
struct V_397 V_76 ;
struct V_269 * V_270 = & V_59 -> V_142 ;
struct V_569 V_573 ;
T_3 V_296 = 0 , V_297 = 0 ;
T_1 V_119 = V_329 ;
T_3 V_261 ;
int V_11 ;
if ( ! V_59 -> V_310 ) {
F_7 ( V_2 ,
V_36 ,
L_64 ,
V_59 -> V_37 ) ;
V_119 = V_394 ;
goto V_360;
}
V_600 = F_143 ( sizeof( * V_600 ) ) ;
if ( V_600 == NULL ) {
V_119 = V_394 ;
goto V_360;
}
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_76 . V_15 = V_59 -> V_15 ;
V_76 . V_150 = V_59 -> V_150 ;
V_76 . V_553 = NULL ;
F_133 ( V_2 , & V_76 , V_270 , & V_296 ) ;
F_134 ( V_2 , & V_76 , V_59 , V_270 , & V_296 ) ;
F_135 ( V_2 , & V_76 , V_270 , & V_296 ) ;
F_136 ( V_2 , & V_76 , V_270 , & V_296 ) ;
F_137 ( V_2 , & V_76 , V_270 , & V_296 ) ;
F_138 ( V_2 , & V_76 , V_270 , & V_296 ) ;
F_140 ( V_2 , V_59 , & V_76 ,
& V_573 , V_270 , & V_296 ) ;
V_297 = V_296 ;
F_139 ( V_2 , V_59 , & V_76 , V_600 ,
V_270 , & V_296 , & V_297 ) ;
if ( F_141 ( V_2 , V_59 -> V_58 ,
& V_76 , & V_297 ) ) {
V_297 = 0 ;
V_119 = V_303 ;
goto V_360;
}
if ( ! V_297 ) {
if ( V_296 )
F_7 ( V_2 , V_36 ,
L_65 ) ;
else
F_7 ( V_2 , V_36 ,
L_66 ) ;
V_119 = V_303 ;
goto V_360;
}
V_11 = F_102 ( V_2 , & V_76 , V_17 , NULL ) ;
if ( V_11 )
V_119 = V_394 ;
V_360:
F_144 ( V_600 ) ;
V_261 = F_88 ( V_2 , V_59 , V_270 , V_119 ,
V_296 , V_297 ) ;
F_84 ( V_2 , V_70 , V_59 , V_261 , V_119 ) ;
}
static int F_145 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_402 * V_237 )
{
int V_65 ;
if ( V_237 -> V_407 == V_601 ) {
for ( V_65 = 0 ; V_65 < V_154 + 1 ; V_65 ++ )
if ( V_4 -> V_316 . V_409 [ V_65 ] . V_410 &&
V_4 -> V_316 . V_409 [ V_65 ] . V_413 ==
V_237 -> V_412 ) {
V_4 -> V_316 . V_409 [ V_65 ] . V_410 = false ;
break;
}
if ( V_65 == V_154 + 1 ) {
F_7 ( V_2 ,
V_36 ,
L_67 ,
V_4 -> V_58 ) ;
return - V_12 ;
}
} else if ( V_237 -> V_407 == V_419 ||
V_237 -> V_407 == V_423 ) {
for ( V_65 = 0 ; V_65 < V_154 + 1 ; V_65 ++ )
V_4 -> V_316 . V_409 [ V_65 ] . V_410 = false ;
}
if ( V_4 -> V_78 . V_79 -> V_444 & F_65 ( V_416 ) )
return 0 ;
if ( V_237 -> V_407 == V_408 ||
V_237 -> V_407 == V_419 ) {
for ( V_65 = 0 ; V_65 < V_154 + 1 ; V_65 ++ ) {
if ( V_4 -> V_316 . V_409 [ V_65 ] . V_410 )
continue;
V_4 -> V_316 . V_409 [ V_65 ] . V_410 = true ;
V_4 -> V_316 . V_409 [ V_65 ] . V_413 = V_237 -> V_412 ;
break;
}
if ( V_65 == V_154 + 1 ) {
F_7 ( V_2 ,
V_36 ,
L_68 ,
V_4 -> V_58 ,
V_154 + 1 ) ;
return - V_12 ;
}
}
return 0 ;
}
static int F_146 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_402 * V_237 )
{
int V_65 ;
if ( V_4 -> V_78 . V_79 -> V_444 & F_65 ( V_417 ) )
return 0 ;
if ( V_237 -> V_407 == V_601 ) {
for ( V_65 = 0 ; V_65 < V_152 ; V_65 ++ ) {
if ( F_147 ( V_4 -> V_316 . V_602 [ V_65 ] ,
V_237 -> V_307 ) ) {
F_92 ( V_4 -> V_316 . V_602 [ V_65 ] ) ;
break;
}
}
if ( V_65 == V_152 ) {
F_7 ( V_2 , V_36 ,
L_69 ) ;
return - V_12 ;
}
} else if ( V_237 -> V_407 == V_419 ||
V_237 -> V_407 == V_423 ) {
for ( V_65 = 0 ; V_65 < V_152 ; V_65 ++ )
F_92 ( V_4 -> V_316 . V_602 [ V_65 ] ) ;
}
if ( V_237 -> V_407 != V_408 &&
V_237 -> V_407 != V_419 )
return 0 ;
for ( V_65 = 0 ; V_65 < V_152 ; V_65 ++ ) {
if ( F_148 ( V_4 -> V_316 . V_602 [ V_65 ] ) ) {
F_107 ( V_4 -> V_316 . V_602 [ V_65 ] ,
V_237 -> V_307 ) ;
F_7 ( V_2 , V_36 ,
L_70 , V_65 ) ;
break;
}
}
if ( V_65 == V_152 ) {
F_7 ( V_2 , V_36 , L_71 ) ;
return - V_12 ;
}
return 0 ;
}
static int
F_149 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_402 * V_237 )
{
int V_11 = 0 ;
if ( V_237 -> type == V_418 ) {
V_11 = F_146 ( V_2 , V_4 , V_237 ) ;
if ( V_11 )
return V_11 ;
}
if ( V_237 -> type == V_411 )
V_11 = F_145 ( V_2 , V_4 , V_237 ) ;
return V_11 ;
}
static int F_150 ( struct V_1 * V_594 ,
int V_68 , struct V_402 * V_76 )
{
struct V_306 * V_59 ;
V_59 = F_90 ( V_594 , V_68 , true ) ;
if ( ! V_59 )
return - V_12 ;
if ( V_76 -> type == V_418 ||
V_76 -> type == V_603 )
F_107 ( V_59 -> V_307 , V_76 -> V_307 ) ;
return 0 ;
}
static void F_151 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 )
{
struct V_71 * V_72 = V_59 -> V_78 . V_79 ;
struct V_269 * V_270 = & V_59 -> V_142 ;
struct V_604 * V_355 ;
T_1 V_119 = V_329 ;
struct V_402 V_76 ;
int V_11 ;
memset ( & V_76 , 0 , sizeof( struct V_402 ) ) ;
V_355 = & V_270 -> V_143 -> V_605 ;
V_76 . V_407 = (enum V_606 ) V_355 -> V_407 ;
V_76 . type = (enum V_607 ) V_355 -> type ;
V_76 . V_404 = 1 ;
V_76 . V_405 = 1 ;
V_76 . V_608 = V_59 -> V_150 ;
V_76 . V_406 = V_59 -> V_150 ;
memcpy ( V_76 . V_307 , V_355 -> V_307 , V_380 ) ;
V_76 . V_412 = V_355 -> V_412 ;
F_7 ( V_2 ,
V_36 ,
L_72 ,
V_59 -> V_37 , V_76 . V_407 , V_76 . type ,
V_76 . V_404 ? L_73 : L_74 ,
V_76 . V_405 ? L_75 : L_74 ,
V_76 . V_406 ,
V_76 . V_307 [ 0 ] , V_76 . V_307 [ 1 ] ,
V_76 . V_307 [ 2 ] , V_76 . V_307 [ 3 ] ,
V_76 . V_307 [ 4 ] , V_76 . V_307 [ 5 ] , V_76 . V_412 ) ;
if ( ! V_59 -> V_310 ) {
F_7 ( V_2 ,
V_36 ,
L_76 ,
V_59 -> V_37 ) ;
V_119 = V_394 ;
goto V_360;
}
if ( F_149 ( V_2 , V_59 , & V_76 ) ) {
V_119 = V_394 ;
goto V_360;
}
if ( ( V_72 -> V_444 & F_65 ( V_416 ) ) &&
( V_76 . type == V_411 ||
V_76 . type == V_603 ) ) {
if ( V_76 . V_407 == V_408 ||
V_76 . V_407 == V_419 )
V_119 = V_609 ;
goto V_360;
}
if ( ( V_72 -> V_444 & F_65 ( V_417 ) ) &&
( V_76 . type == V_418 ||
V_76 . type == V_603 ) ) {
if ( ! F_147 ( V_72 -> V_307 , V_76 . V_307 ) ||
( V_76 . V_407 != V_408 &&
V_76 . V_407 != V_419 ) )
V_119 = V_609 ;
goto V_360;
}
V_11 = F_150 ( V_2 , V_59 -> V_58 , & V_76 ) ;
if ( V_11 ) {
V_119 = V_394 ;
goto V_360;
}
V_11 = F_104 ( V_2 , V_59 -> V_15 , & V_76 ,
V_414 , NULL ) ;
if ( V_11 )
V_119 = V_394 ;
V_360:
F_89 ( V_2 , V_70 , V_59 , V_610 ,
sizeof( struct V_298 ) , V_119 ) ;
}
static void F_152 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_59 )
{
int V_65 ;
for ( V_65 = 0 ; V_65 < V_59 -> V_66 ; V_65 ++ )
F_56 ( V_2 , V_70 ,
V_59 -> V_67 [ V_65 ] ,
V_59 -> V_15 , false ) ;
F_89 ( V_2 , V_70 , V_59 , V_611 ,
sizeof( struct V_298 ) ,
V_329 ) ;
}
static void F_153 ( struct V_1 * V_2 ,
struct V_69 * V_70 , struct V_3 * V_59 )
{
T_3 V_261 = sizeof( struct V_298 ) ;
T_1 V_119 = V_329 ;
F_57 ( V_2 , V_70 , V_59 , 0 ) ;
F_63 ( V_2 , V_70 , V_59 , 0 ) ;
F_89 ( V_2 , V_70 , V_59 , V_612 ,
V_261 , V_119 ) ;
}
static void F_154 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_3 * V_4 )
{
T_3 V_261 = sizeof( struct V_298 ) ;
T_1 V_119 = V_329 ;
int V_11 = 0 ;
F_93 ( V_2 , V_4 ) ;
if ( V_4 -> V_147 != V_148 && V_4 -> V_147 != V_183 ) {
V_11 = F_9 ( V_2 , V_4 -> V_23 ,
V_4 -> V_15 ) ;
if ( V_11 ) {
F_12 ( V_2 , L_77 ,
V_11 ) ;
V_119 = V_394 ;
}
V_4 -> V_147 = V_148 ;
}
F_89 ( V_2 , V_70 , V_4 , V_613 ,
V_261 , V_119 ) ;
}
static int
F_155 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_69 * V_70 )
{
int V_614 ;
T_2 V_115 ;
F_55 ( V_2 , V_70 , ( T_3 ) V_4 -> V_23 ) ;
for ( V_614 = 0 ; V_614 < 50 ; V_614 ++ ) {
V_115 = F_26 ( V_2 , V_70 , V_615 ) ;
if ( ! V_115 )
break;
F_156 ( 20 ) ;
}
F_55 ( V_2 , V_70 , ( T_3 ) V_2 -> V_25 . V_23 ) ;
if ( V_614 == 50 ) {
F_12 ( V_2 ,
L_78 ,
V_4 -> V_37 , V_115 ) ;
return - V_616 ;
}
return 0 ;
}
static int
F_157 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_69 * V_70 )
{
T_2 V_617 [ V_618 ] , V_619 [ V_618 ] ;
int V_65 , V_614 ;
for ( V_65 = 0 ; V_65 < V_618 ; V_65 ++ ) {
T_2 V_620 ;
V_617 [ V_65 ] = F_26 ( V_2 , V_70 ,
V_621 +
V_65 * 0x40 ) ;
V_620 = F_26 ( V_2 , V_70 ,
V_622 +
V_65 * 0x40 ) ;
V_619 [ V_65 ] = V_620 - V_617 [ V_65 ] ;
}
V_65 = 0 ;
for ( V_614 = 0 ; V_614 < 50 ; V_614 ++ ) {
for (; V_65 < V_618 ; V_65 ++ ) {
T_2 V_623 ;
V_623 = F_26 ( V_2 , V_70 ,
V_621 +
V_65 * 0x40 ) ;
if ( V_619 [ V_65 ] > V_623 - V_617 [ V_65 ] )
break;
}
if ( V_65 == V_618 )
break;
F_156 ( 20 ) ;
}
if ( V_614 == 50 ) {
F_12 ( V_2 , L_79 ,
V_4 -> V_37 , V_65 ) ;
return - V_616 ;
}
return 0 ;
}
static int F_158 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_69 * V_70 )
{
int V_11 ;
V_11 = F_155 ( V_2 , V_4 , V_70 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_157 ( V_2 , V_4 , V_70 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int
F_159 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
T_3 V_48 , T_2 * V_624 )
{
struct V_3 * V_4 ;
int V_11 = 0 ;
V_4 = F_11 ( V_2 , V_48 , false ) ;
if ( ! V_4 )
return 0 ;
if ( V_2 -> V_51 -> V_625 [ V_48 / 64 ] &
( 1ULL << ( V_48 % 64 ) ) ) {
T_3 V_68 = V_4 -> V_37 ;
F_7 ( V_2 , V_36 ,
L_80 , V_68 ) ;
F_93 ( V_2 , V_4 ) ;
if ( ! V_4 -> V_56 )
goto V_626;
V_11 = F_158 ( V_2 , V_4 , V_70 ) ;
if ( V_11 )
goto V_626;
V_11 = F_160 ( V_2 , V_70 , V_68 , true ) ;
if ( V_11 ) {
F_12 ( V_2 , L_81 , V_68 ) ;
return V_11 ;
}
F_85 ( V_2 ,
V_276 +
F_86 ( V_68 ) , 1 ) ;
V_4 -> V_147 = V_148 ;
V_11 = F_58 ( V_2 , V_70 , V_4 ) ;
if ( V_11 ) {
F_12 ( V_2 , L_82 ,
V_68 ) ;
return V_11 ;
}
V_626:
if ( V_4 -> V_147 == V_627 )
V_4 -> V_147 = V_148 ;
V_624 [ V_68 / 32 ] |= F_65 ( ( V_68 % 32 ) ) ;
V_2 -> V_51 -> V_625 [ V_48 / 64 ] &=
~ ( 1ULL << ( V_48 % 64 ) ) ;
V_4 -> V_142 . V_628 = false ;
}
return V_11 ;
}
static int
F_161 ( struct V_1 * V_2 , struct V_69 * V_70 )
{
T_2 V_624 [ V_629 / 32 ] ;
int V_11 = 0 ;
T_3 V_65 ;
memset ( V_624 , 0 , sizeof( T_2 ) * ( V_629 / 32 ) ) ;
F_156 ( 100 ) ;
for ( V_65 = 0 ; V_65 < V_2 -> V_52 -> V_53 -> V_54 ; V_65 ++ )
F_159 ( V_2 , V_70 , V_65 , V_624 ) ;
V_11 = F_162 ( V_2 , V_70 , V_624 ) ;
return V_11 ;
}
int F_163 ( struct V_1 * V_2 , T_2 * V_630 )
{
T_3 V_65 , V_631 = 0 ;
F_7 ( V_2 , V_36 , L_83 ) ;
for ( V_65 = 0 ; V_65 < ( V_629 / 32 ) ; V_65 ++ )
F_7 ( V_2 , V_36 ,
L_84 ,
V_65 * 32 , ( V_65 + 1 ) * 32 - 1 , V_630 [ V_65 ] ) ;
if ( ! V_2 -> V_52 -> V_53 ) {
F_6 ( V_2 , L_85 ) ;
return 0 ;
}
for ( V_65 = 0 ; V_65 < V_2 -> V_52 -> V_53 -> V_54 ; V_65 ++ ) {
struct V_3 * V_4 ;
T_1 V_68 ;
V_4 = F_11 ( V_2 , V_65 , false ) ;
if ( ! V_4 )
continue;
V_68 = V_4 -> V_37 ;
if ( F_65 ( ( V_68 % 32 ) ) & V_630 [ V_68 / 32 ] ) {
V_162 * V_632 = V_2 -> V_51 -> V_625 ;
T_3 V_48 = V_4 -> V_58 ;
F_7 ( V_2 , V_36 ,
L_86 ,
V_68 , V_48 ) ;
V_4 -> V_147 = V_627 ;
V_632 [ V_48 / 64 ] |= 1ULL << ( V_48 % 64 ) ;
V_631 = 1 ;
}
}
return V_631 ;
}
static void F_164 ( struct V_1 * V_2 ,
T_3 V_68 ,
struct V_203 * V_237 ,
struct V_204 * V_633 ,
struct V_205 * V_206 )
{
struct V_3 * V_4 = F_11 ( V_2 ,
V_68 ,
false ) ;
struct V_71 * V_72 ;
if ( ! V_4 )
return;
V_72 = V_4 -> V_78 . V_79 ;
if ( V_237 )
F_165 ( V_2 , V_237 , V_72 ) ;
if ( V_633 )
F_166 ( V_2 , V_633 , V_72 ) ;
if ( V_206 )
F_167 ( V_2 , V_206 , V_72 ) ;
}
static void F_168 ( struct V_1 * V_2 ,
struct V_69 * V_70 , int V_68 )
{
struct V_269 * V_270 ;
struct V_3 * V_4 ;
V_4 = F_11 ( V_2 , ( T_3 ) V_68 , true ) ;
if ( ! V_4 )
return;
V_270 = & V_4 -> V_142 ;
if ( ! V_270 -> V_628 ) {
F_6 ( V_2 ,
L_87 ,
V_4 -> V_37 ) ;
return;
}
V_270 -> V_628 = false ;
V_270 -> V_274 = V_270 -> V_143 -> V_274 ;
F_7 ( V_2 , V_36 ,
L_88 ,
V_4 -> V_37 , V_270 -> V_274 . V_263 . type ) ;
if ( F_81 ( V_270 -> V_274 . V_263 . type ) &&
! V_4 -> V_57 ) {
switch ( V_270 -> V_274 . V_263 . type ) {
case V_396 :
F_98 ( V_2 , V_70 , V_4 ) ;
break;
case V_456 :
F_109 ( V_2 , V_70 , V_4 ) ;
break;
case V_457 :
F_112 ( V_2 , V_70 , V_4 ) ;
break;
case V_462 :
F_115 ( V_2 , V_70 , V_4 ) ;
break;
case V_477 :
F_121 ( V_2 , V_70 , V_4 ) ;
break;
case V_493 :
F_129 ( V_2 , V_70 , V_4 ) ;
break;
case V_496 :
F_130 ( V_2 , V_70 , V_4 ) ;
break;
case V_504 :
F_131 ( V_2 , V_70 , V_4 ) ;
break;
case V_301 :
F_142 ( V_2 , V_70 , V_4 ) ;
break;
case V_610 :
F_151 ( V_2 , V_70 , V_4 ) ;
break;
case V_612 :
F_153 ( V_2 , V_70 , V_4 ) ;
break;
case V_611 :
F_152 ( V_2 , V_70 , V_4 ) ;
break;
case V_613 :
F_154 ( V_2 , V_70 , V_4 ) ;
break;
}
} else if ( F_81 ( V_270 -> V_274 . V_263 . type ) ) {
F_7 ( V_2 , V_36 ,
L_89 ,
V_4 -> V_37 , V_270 -> V_274 . V_263 . type ) ;
F_89 ( V_2 , V_70 , V_4 ,
V_270 -> V_274 . V_263 . type ,
sizeof( struct V_298 ) ,
V_634 ) ;
} else {
F_6 ( V_2 ,
L_90 ,
V_4 -> V_37 ,
V_270 -> V_274 . V_263 . type ,
V_270 -> V_274 . V_263 . V_261 ,
V_270 -> V_274 . V_635 , V_270 -> V_274 . V_275 ) ;
if ( V_4 -> V_31 . V_274 . V_275 &&
( V_270 -> V_274 . V_275 ==
V_4 -> V_31 . V_274 . V_275 ) ) {
F_89 ( V_2 , V_70 , V_4 ,
V_270 -> V_274 . V_263 . type ,
sizeof( struct V_298 ) ,
V_303 ) ;
} else {
F_7 ( V_2 ,
V_36 ,
L_91 ,
V_4 -> V_37 ) ;
}
}
}
void F_169 ( struct V_1 * V_2 , V_162 * V_415 )
{
int V_65 ;
memset ( V_415 , 0 , sizeof( V_162 ) * V_636 ) ;
F_170 (p_hwfn, i) {
struct V_3 * V_4 ;
V_4 = & V_2 -> V_51 -> V_55 [ V_65 ] ;
if ( V_4 -> V_142 . V_628 )
V_415 [ V_65 / 64 ] |= 1ULL << ( V_65 % 64 ) ;
}
}
static struct V_3 * F_171 ( struct V_1 * V_2 ,
T_3 V_170 )
{
T_1 V_637 = ( T_1 ) V_2 -> V_52 -> V_53 -> V_149 ;
if ( ! F_47 ( V_2 , ( int ) V_170 - V_637 , false ) ) {
F_7 ( V_2 ,
V_36 ,
L_92 ,
V_170 ) ;
return NULL ;
}
return & V_2 -> V_51 -> V_55 [ ( T_1 ) V_170 - V_637 ] ;
}
static int F_172 ( struct V_1 * V_2 ,
T_3 V_170 , struct V_638 * V_639 )
{
struct V_3 * V_4 = F_171 ( V_2 ,
V_170 ) ;
if ( ! V_4 )
return 0 ;
V_4 -> V_142 . V_640 = ( ( ( V_162 ) V_639 -> V_641 ) << 32 ) | V_639 -> V_642 ;
V_4 -> V_142 . V_628 = true ;
F_173 ( V_2 , V_643 ) ;
return 0 ;
}
static void F_174 ( struct V_1 * V_2 ,
struct V_644 * V_508 )
{
struct V_3 * V_4 ;
V_4 = F_171 ( V_2 , V_508 -> V_22 ) ;
if ( ! V_4 )
return;
F_99 ( V_2 ,
L_93 ,
V_4 -> V_37 , V_508 -> V_645 ) ;
V_4 -> V_57 = true ;
}
int F_175 ( struct V_1 * V_2 ,
T_1 V_407 , T_5 V_646 , union V_647 * V_648 )
{
switch ( V_407 ) {
case V_649 :
return F_172 ( V_2 , F_176 ( V_646 ) ,
& V_648 -> V_650 . V_651 ) ;
case V_652 :
F_174 ( V_2 , & V_648 -> V_653 ) ;
return 0 ;
default:
F_99 ( V_2 -> V_52 , L_94 ,
V_407 ) ;
return - V_12 ;
}
}
T_3 F_177 ( struct V_1 * V_2 , T_3 V_48 )
{
struct V_87 * V_124 = V_2 -> V_52 -> V_53 ;
T_3 V_65 ;
if ( ! V_124 )
goto V_360;
for ( V_65 = V_48 ; V_65 < V_124 -> V_54 ; V_65 ++ )
if ( F_10 ( V_2 , V_48 , true , false ) )
return V_65 ;
V_360:
return V_654 ;
}
static int F_178 ( struct V_1 * V_2 , struct V_69 * V_655 ,
int V_68 )
{
struct V_75 V_76 ;
struct V_3 * V_305 ;
V_305 = F_11 ( V_2 , ( T_3 ) V_68 , true ) ;
if ( ! V_305 )
return - V_12 ;
memset ( & V_76 , 0 , sizeof( struct V_75 ) ) ;
V_76 . V_82 = V_656 | V_657 ;
V_76 . V_658 = V_305 -> V_37 ;
if ( F_18 ( V_2 , V_655 ,
V_305 -> V_142 . V_640 ,
V_305 -> V_142 . V_144 ,
sizeof( union V_132 ) / 4 , & V_76 ) ) {
F_7 ( V_2 , V_36 ,
L_95 , V_68 ) ;
return - V_659 ;
}
return 0 ;
}
static void F_179 ( struct V_1 * V_2 ,
T_1 * V_307 , int V_68 )
{
struct V_3 * V_305 ;
V_162 V_660 ;
V_305 = F_11 ( V_2 , ( T_3 ) V_68 , true ) ;
if ( ! V_305 ) {
F_6 ( V_2 -> V_52 ,
L_96 , V_68 ) ;
return;
}
if ( V_305 -> V_57 ) {
F_6 ( V_2 -> V_52 ,
L_97 , V_68 ) ;
return;
}
V_660 = 1 << V_417 ;
memcpy ( V_305 -> V_78 . V_79 -> V_307 , V_307 , V_380 ) ;
V_305 -> V_78 . V_79 -> V_444 |= V_660 ;
V_305 -> V_78 . V_79 -> V_444 &= ~ F_65 ( V_661 ) ;
F_106 ( V_2 , V_305 , V_660 ) ;
}
static void F_180 ( struct V_1 * V_2 ,
T_3 V_422 , int V_68 )
{
struct V_3 * V_305 ;
V_162 V_660 ;
V_305 = F_11 ( V_2 , ( T_3 ) V_68 , true ) ;
if ( ! V_305 ) {
F_6 ( V_2 -> V_52 ,
L_96 , V_68 ) ;
return;
}
if ( V_305 -> V_57 ) {
F_6 ( V_2 -> V_52 ,
L_98 , V_68 ) ;
return;
}
V_660 = 1 << V_416 ;
V_305 -> V_78 . V_79 -> V_422 = V_422 ;
if ( V_422 )
V_305 -> V_78 . V_79 -> V_444 |= V_660 ;
else
V_305 -> V_78 . V_79 -> V_444 &= ~ V_660 ;
F_106 ( V_2 , V_305 , V_660 ) ;
}
static bool F_181 ( struct V_1 * V_2 , int V_68 )
{
struct V_3 * V_257 ;
V_257 = F_11 ( V_2 , ( T_3 ) V_68 , true ) ;
if ( ! V_257 )
return false ;
return ! ! V_257 -> V_310 ;
}
static bool F_182 ( struct V_1 * V_2 , int V_68 )
{
struct V_3 * V_257 ;
V_257 = F_11 ( V_2 , ( T_3 ) V_68 , true ) ;
if ( ! V_257 )
return true ;
return V_257 -> V_147 == V_148 ;
}
static bool F_183 ( struct V_1 * V_2 , int V_68 )
{
struct V_3 * V_305 ;
V_305 = F_11 ( V_2 , ( T_3 ) V_68 , true ) ;
if ( ! V_305 )
return false ;
return V_305 -> V_398 ;
}
static int F_184 ( struct V_1 * V_2 , int V_68 , bool V_115 )
{
struct V_3 * V_59 ;
int V_11 = - V_12 ;
if ( ! F_49 ( V_2 , V_68 ) ) {
F_6 ( V_2 ,
L_99 ) ;
goto V_360;
}
V_59 = F_11 ( V_2 , ( T_3 ) V_68 , true ) ;
if ( ! V_59 )
goto V_360;
if ( ! F_181 ( V_2 , V_68 ) ) {
V_59 -> V_401 = V_115 ;
V_11 = 0 ;
goto V_360;
}
V_11 = F_101 ( V_2 , V_59 , V_115 ) ;
V_360:
return V_11 ;
}
static T_1 * F_185 ( struct V_1 * V_2 ,
T_3 V_48 )
{
struct V_3 * V_4 ;
V_4 = F_11 ( V_2 , V_48 , true ) ;
if ( ! V_4 || ! V_4 -> V_78 . V_79 )
return NULL ;
if ( ! ( V_4 -> V_78 . V_79 -> V_444 & F_65 ( V_417 ) ) )
return NULL ;
return V_4 -> V_78 . V_79 -> V_307 ;
}
static T_3
F_186 ( struct V_1 * V_2 , T_3 V_48 )
{
struct V_3 * V_4 ;
V_4 = F_11 ( V_2 , V_48 , true ) ;
if ( ! V_4 || ! V_4 -> V_78 . V_79 )
return 0 ;
if ( ! ( V_4 -> V_78 . V_79 -> V_444 & F_65 ( V_416 ) ) )
return 0 ;
return V_4 -> V_78 . V_79 -> V_422 ;
}
static int F_187 ( struct V_1 * V_2 ,
struct V_69 * V_70 , int V_68 , int V_115 )
{
struct V_3 * V_59 ;
T_1 V_662 = 0 ;
int V_11 ;
V_59 = F_11 ( V_2 , ( T_3 ) V_68 , true ) ;
if ( ! V_59 )
return - V_12 ;
V_11 = F_188 ( V_2 , V_59 -> V_150 , & V_662 ) ;
if ( V_11 )
return V_11 ;
return F_189 ( V_2 , V_70 , V_662 , ( T_2 ) V_115 ) ;
}
static int
F_190 ( struct V_86 * V_52 , int V_68 , T_2 V_663 )
{
struct V_3 * V_59 ;
T_1 V_150 ;
int V_65 ;
F_51 (cdev, i) {
struct V_1 * V_2 = & V_52 -> V_169 [ V_65 ] ;
if ( ! F_49 ( V_2 , V_68 ) ) {
F_6 ( V_2 ,
L_100 ) ;
return - V_12 ;
}
}
V_59 = F_11 ( F_191 ( V_52 ) , ( T_3 ) V_68 , true ) ;
V_150 = V_59 -> V_150 ;
return F_192 ( V_52 , V_150 , V_663 ) ;
}
static int F_193 ( struct V_1 * V_2 , int V_68 )
{
struct V_664 * V_665 ;
struct V_3 * V_305 ;
V_305 = F_11 ( V_2 , ( T_3 ) V_68 , true ) ;
if ( ! V_305 )
return 0 ;
V_665 = & V_2 -> V_666 . V_667 [ V_305 -> V_150 ] ;
if ( V_665 -> V_668 )
return V_665 -> V_669 ;
else
return 0 ;
}
void F_173 ( struct V_1 * V_594 , enum V_670 V_278 )
{
F_194 () ;
F_195 ( V_278 , & V_594 -> V_671 ) ;
F_196 () ;
F_7 ( V_594 , V_36 , L_101 , V_278 ) ;
F_197 ( V_594 -> V_672 , & V_594 -> V_673 , 0 ) ;
}
void F_198 ( struct V_86 * V_52 )
{
int V_65 ;
F_51 (cdev, i)
F_197 ( V_52 -> V_169 [ V_65 ] . V_672 ,
& V_52 -> V_169 [ V_65 ] . V_673 , 0 ) ;
}
int F_199 ( struct V_86 * V_52 , bool V_674 )
{
int V_65 , V_675 ;
F_51 (cdev, i)
if ( V_52 -> V_169 [ V_65 ] . V_672 )
F_200 ( V_52 -> V_169 [ V_65 ] . V_672 ) ;
F_52 ( V_52 , true ) ;
if ( V_52 -> V_53 && V_52 -> V_53 -> V_97 && V_674 )
F_201 ( V_52 -> V_90 ) ;
F_51 (cdev, i) {
struct V_1 * V_594 = & V_52 -> V_169 [ V_65 ] ;
struct V_69 * V_655 = F_202 ( V_594 ) ;
if ( ! V_655 ) {
F_12 ( V_594 , L_102 ) ;
return - V_616 ;
}
F_203 ( V_594 , V_655 ) ;
F_170 (hwfn, j) {
int V_676 ;
if ( ! F_10 ( V_594 , V_675 , true , false ) )
continue;
for ( V_676 = 0 ; V_676 < 100 ; V_676 ++ ) {
if ( ! F_182 ( V_594 , V_675 ) )
F_156 ( 20 ) ;
else
break;
}
if ( V_676 < 100 )
F_80 ( & V_52 -> V_169 [ V_65 ] ,
V_655 , V_675 ) ;
else
F_12 ( V_594 ,
L_103 ) ;
}
F_204 ( V_594 , V_655 ) ;
}
F_52 ( V_52 , false ) ;
return 0 ;
}
static void F_205 ( struct V_1 * V_594 ,
T_3 V_68 ,
struct V_236 * V_76 )
{
T_3 V_677 , V_65 ;
V_677 = F_73 ( V_594 , V_246 ) + V_68 * V_76 -> V_244 ;
V_76 -> V_48 = V_68 ;
for ( V_65 = 0 ; V_65 < V_76 -> V_244 ; V_65 ++ ) {
V_76 -> V_249 [ V_65 ] = V_677 + V_65 ;
V_76 -> V_250 [ V_65 ] = V_677 + V_65 ;
}
}
static int F_206 ( struct V_86 * V_52 , int V_678 )
{
struct V_236 V_76 ;
int V_65 , V_675 , V_11 ;
if ( V_678 >= F_207 ( & V_52 -> V_169 [ 0 ] , V_679 ) ) {
F_6 ( V_52 , L_104 ,
F_207 ( & V_52 -> V_169 [ 0 ] , V_679 ) - 1 ) ;
return - V_12 ;
}
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
F_51 (cdev, j) {
struct V_1 * V_594 = & V_52 -> V_169 [ V_675 ] ;
struct V_69 * V_655 = F_202 ( V_594 ) ;
V_76 . V_244 = F_75 ( int ,
F_73 ( V_594 , V_248 ) / V_678 ,
16 ) ;
if ( ! V_655 ) {
F_12 ( V_594 , L_102 ) ;
V_11 = - V_616 ;
goto V_680;
}
for ( V_65 = 0 ; V_65 < V_678 ; V_65 ++ ) {
if ( ! F_10 ( V_594 , V_65 , false , true ) )
continue;
F_205 ( V_594 , V_65 , & V_76 ) ;
V_11 = F_72 ( V_594 , V_655 , & V_76 ) ;
if ( V_11 ) {
F_12 ( V_52 , L_105 , V_65 ) ;
F_204 ( V_594 , V_655 ) ;
goto V_680;
}
}
F_204 ( V_594 , V_655 ) ;
}
V_11 = F_208 ( V_52 -> V_90 , V_678 ) ;
if ( V_11 ) {
F_12 ( V_52 , L_106 , V_11 ) ;
goto V_680;
}
return V_678 ;
V_680:
F_199 ( V_52 , false ) ;
return V_11 ;
}
static int F_209 ( struct V_86 * V_52 , int V_681 )
{
if ( ! F_48 ( V_52 ) ) {
F_7 ( V_52 , V_36 , L_107 ) ;
return - V_682 ;
}
if ( V_681 )
return F_206 ( V_52 , V_681 ) ;
else
return F_199 ( V_52 , true ) ;
}
static int F_210 ( struct V_86 * V_52 , T_1 * V_307 , int V_68 )
{
int V_65 ;
if ( ! F_48 ( V_52 ) || ! F_39 ( & V_52 -> V_169 [ 0 ] ) ) {
F_7 ( V_52 , V_36 ,
L_108 ) ;
return - V_12 ;
}
if ( ! F_10 ( & V_52 -> V_169 [ 0 ] , V_68 , true , true ) ) {
F_7 ( V_52 , V_36 ,
L_109 , V_68 ) ;
return - V_12 ;
}
F_51 (cdev, i) {
struct V_1 * V_594 = & V_52 -> V_169 [ V_65 ] ;
struct V_306 * V_305 ;
V_305 = F_90 ( V_594 , V_68 , true ) ;
if ( ! V_305 )
continue;
F_107 ( V_305 -> V_683 , V_307 ) ;
F_173 ( V_594 , V_684 ) ;
}
return 0 ;
}
static int F_211 ( struct V_86 * V_52 , T_3 V_413 , int V_68 )
{
int V_65 ;
if ( ! F_48 ( V_52 ) || ! F_39 ( & V_52 -> V_169 [ 0 ] ) ) {
F_7 ( V_52 , V_36 ,
L_108 ) ;
return - V_12 ;
}
if ( ! F_10 ( & V_52 -> V_169 [ 0 ] , V_68 , true , true ) ) {
F_7 ( V_52 , V_36 ,
L_109 , V_68 ) ;
return - V_12 ;
}
F_51 (cdev, i) {
struct V_1 * V_594 = & V_52 -> V_169 [ V_65 ] ;
struct V_306 * V_305 ;
V_305 = F_90 ( V_594 , V_68 , true ) ;
if ( ! V_305 )
continue;
V_305 -> V_685 = V_413 ;
F_173 ( V_594 , V_684 ) ;
}
return 0 ;
}
static int F_212 ( struct V_86 * V_52 ,
int V_22 , struct V_686 * V_687 )
{
struct V_1 * V_594 = F_191 ( V_52 ) ;
struct V_306 * V_305 ;
struct V_204 V_109 ;
T_2 V_688 ;
if ( F_44 ( V_52 ) )
return - V_12 ;
if ( ! F_10 ( & V_52 -> V_169 [ 0 ] , V_22 , true , false ) ) {
F_7 ( V_52 , V_36 ,
L_110 , V_22 ) ;
return - V_12 ;
}
V_305 = F_90 ( V_594 , V_22 , true ) ;
F_164 ( V_594 , V_22 , NULL , & V_109 , NULL ) ;
V_687 -> V_59 = V_22 ;
if ( F_213 ( V_305 -> V_683 ) )
F_107 ( V_687 -> V_307 , V_305 -> V_683 ) ;
else
F_107 ( V_687 -> V_307 , V_305 -> V_307 ) ;
V_687 -> V_412 = V_305 -> V_685 ;
V_687 -> V_689 = F_183 ( V_594 , V_22 ) ;
V_687 -> V_690 = V_305 -> V_240 ;
V_688 = V_305 -> V_688 ;
V_687 -> V_691 = V_688 ? V_688 : V_109 . V_208 ;
V_687 -> V_692 = F_193 ( V_594 , V_22 ) ;
return 0 ;
}
void F_214 ( struct V_1 * V_594 )
{
struct V_205 V_256 ;
struct V_203 V_76 ;
struct V_204 V_109 ;
int V_65 ;
if ( ! V_594 -> V_51 )
return;
for ( V_65 = 0 ; V_65 < V_594 -> V_52 -> V_53 -> V_54 ; V_65 ++ ) {
struct V_306 * V_305 ;
V_305 = F_90 ( V_594 , V_65 , false ) ;
if ( ! V_305 )
continue;
memcpy ( & V_76 , F_76 ( V_594 ) , sizeof( V_76 ) ) ;
memcpy ( & V_109 , F_77 ( V_594 ) , sizeof( V_109 ) ) ;
memcpy ( & V_256 , F_78 ( V_594 ) ,
sizeof( V_256 ) ) ;
switch ( V_305 -> V_240 ) {
case V_693 :
V_109 . V_222 = false ;
break;
case V_694 :
V_109 . V_222 = true ;
V_109 . V_208 = ( V_594 -> V_52 -> V_366 > 1 ) ?
100000 : 40000 ;
default:
break;
}
if ( V_109 . V_222 && V_305 -> V_688 ) {
struct V_69 * V_655 ;
int V_663 ;
V_663 = F_75 ( int , V_305 -> V_688 , V_109 . V_208 ) ;
V_655 = F_202 ( V_594 ) ;
if ( ! V_655 ) {
F_6 ( V_594 , L_111 ) ;
return;
}
if ( ! F_187 ( V_594 , V_655 , V_65 , V_663 ) ) {
V_305 -> V_688 = V_663 ;
V_109 . V_208 = V_663 ;
}
F_204 ( V_594 , V_655 ) ;
}
F_71 ( V_594 , V_65 , & V_76 , & V_109 , & V_256 ) ;
}
F_173 ( V_594 , V_695 ) ;
}
static int F_215 ( struct V_86 * V_52 ,
int V_22 , int V_240 )
{
int V_65 ;
if ( F_44 ( V_52 ) )
return - V_12 ;
if ( ! F_10 ( & V_52 -> V_169 [ 0 ] , V_22 , true , true ) ) {
F_7 ( V_52 , V_36 ,
L_110 , V_22 ) ;
return - V_12 ;
}
F_51 (cdev, i) {
struct V_1 * V_594 = & V_52 -> V_169 [ V_65 ] ;
struct V_306 * V_59 ;
V_59 = F_90 ( V_594 , V_22 , true ) ;
if ( ! V_59 )
continue;
if ( V_59 -> V_240 == V_240 )
continue;
V_59 -> V_240 = V_240 ;
F_214 ( & V_52 -> V_169 [ V_65 ] ) ;
}
return 0 ;
}
static int F_216 ( struct V_86 * V_52 , int V_68 , bool V_115 )
{
int V_65 , V_11 = - V_12 ;
F_51 (cdev, i) {
struct V_1 * V_2 = & V_52 -> V_169 [ V_65 ] ;
V_11 = F_184 ( V_2 , V_68 , V_115 ) ;
if ( V_11 )
break;
}
return V_11 ;
}
static int F_217 ( struct V_86 * V_52 , int V_68 , int V_663 )
{
int V_65 ;
F_51 (cdev, i) {
struct V_1 * V_2 = & V_52 -> V_169 [ V_65 ] ;
struct V_306 * V_59 ;
if ( ! F_49 ( V_2 , V_68 ) ) {
F_6 ( V_2 ,
L_112 ) ;
return - V_12 ;
}
V_59 = F_90 ( V_2 , V_68 , true ) ;
V_59 -> V_688 = V_663 ;
F_214 ( V_2 ) ;
}
return 0 ;
}
static int F_218 ( struct V_86 * V_52 ,
int V_68 , T_2 V_696 , T_2 V_697 )
{
int V_698 = 0 , V_699 = 0 ;
if ( V_697 )
V_699 = F_217 ( V_52 , V_68 , V_697 ) ;
if ( V_696 )
V_698 = F_190 ( V_52 , V_68 , V_696 ) ;
if ( V_699 | V_698 )
return - V_12 ;
return 0 ;
}
static int F_219 ( struct V_86 * V_52 , int V_68 , bool V_700 )
{
int V_65 ;
F_51 (cdev, i) {
struct V_1 * V_594 = & V_52 -> V_169 [ V_65 ] ;
struct V_306 * V_59 ;
if ( ! F_49 ( V_594 , V_68 ) ) {
F_6 ( V_594 ,
L_113 ) ;
return - V_12 ;
}
V_59 = F_90 ( V_594 , V_68 , true ) ;
if ( V_59 -> V_701 == V_700 )
return 0 ;
V_59 -> V_701 = V_700 ;
F_173 ( V_594 , V_702 ) ;
}
return 0 ;
}
static void F_220 ( struct V_1 * V_594 )
{
V_162 V_415 [ V_636 ] ;
struct V_69 * V_655 ;
int V_65 ;
V_655 = F_202 ( V_594 ) ;
if ( ! V_655 ) {
F_7 ( V_594 , V_36 ,
L_114 ) ;
F_173 ( V_594 , V_643 ) ;
return;
}
F_169 ( V_594 , V_415 ) ;
F_7 ( V_594 , V_36 ,
L_115 ,
V_415 [ 0 ] , V_415 [ 1 ] , V_415 [ 2 ] ) ;
F_170 (hwfn, i) {
if ( ! ( V_415 [ V_65 / 64 ] & ( 1ULL << ( V_65 % 64 ) ) ) )
continue;
F_7 ( V_594 , V_36 ,
L_116 ,
V_65 , V_594 -> V_52 -> V_53 -> V_149 + V_65 ) ;
if ( F_178 ( V_594 , V_655 , V_65 ) )
continue;
F_168 ( V_594 , V_655 , V_65 ) ;
}
F_204 ( V_594 , V_655 ) ;
}
static void F_221 ( struct V_1 * V_594 )
{
int V_65 ;
F_170 (hwfn, i) {
struct V_306 * V_703 ;
bool V_704 = false ;
T_1 * V_307 ;
V_703 = F_90 ( V_594 , V_65 , true ) ;
if ( ! V_703 )
continue;
V_307 = F_185 ( V_594 , V_65 ) ;
if ( F_213 ( V_703 -> V_683 ) &&
( ! V_307 || ! F_147 ( V_307 , V_703 -> V_683 ) ) ) {
F_7 ( V_594 ,
V_36 ,
L_117 ,
V_65 ,
V_594 -> V_52 -> V_53 -> V_149 + V_65 ) ;
F_179 ( V_594 ,
V_703 -> V_683 , V_65 ) ;
V_704 = true ;
}
if ( F_186 ( V_594 , V_65 ) ^
V_703 -> V_685 ) {
F_7 ( V_594 ,
V_36 ,
L_118 ,
V_703 -> V_685 ,
V_65 ,
V_594 -> V_52 -> V_53 -> V_149 + V_65 ) ;
F_180 ( V_594 ,
V_703 -> V_685 , V_65 ) ;
V_704 = true ;
}
if ( V_704 )
F_173 ( V_594 , V_695 ) ;
}
}
static void F_222 ( struct V_1 * V_594 )
{
struct V_69 * V_655 ;
int V_65 ;
V_655 = F_202 ( V_594 ) ;
if ( ! V_655 ) {
F_6 ( V_594 , L_119 ) ;
F_173 ( V_594 , V_695 ) ;
return;
}
F_170 (hwfn, i)
F_16 ( V_594 , V_65 , V_655 ) ;
F_204 ( V_594 , V_655 ) ;
}
static void F_223 ( struct V_1 * V_594 )
{
struct V_397 V_76 ;
struct V_531 * V_82 ;
struct V_306 * V_305 ;
struct V_3 * V_59 ;
T_1 V_596 ;
int V_65 ;
V_596 = V_597 | V_598 ;
V_82 = & V_76 . V_533 ;
F_170 (hwfn, i) {
V_305 = F_90 ( V_594 , V_65 , true ) ;
if ( V_305 -> V_599 ==
V_305 -> V_701 )
continue;
V_305 -> V_599 = V_305 -> V_701 ;
V_59 = F_11 ( V_594 , V_65 , true ) ;
if ( ! V_59 -> V_310 )
continue;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_76 . V_15 = V_59 -> V_15 ;
V_76 . V_150 = V_59 -> V_150 ;
if ( V_305 -> V_308 & V_596 ) {
V_82 -> V_536 = 1 ;
V_82 -> V_538 = V_305 -> V_308 ;
}
if ( V_305 -> V_309 & V_596 ) {
V_82 -> V_539 = 1 ;
V_82 -> V_541 = V_305 -> V_309 ;
}
if ( ! V_305 -> V_599 ) {
V_82 -> V_538 &= ~ V_596 ;
V_82 -> V_541 &= ~ V_596 ;
}
if ( V_82 -> V_536 ||
V_82 -> V_539 )
F_102 ( V_594 , & V_76 ,
V_17 , NULL ) ;
}
}
static void F_224 ( struct V_705 * V_706 )
{
struct V_1 * V_594 = F_225 ( V_706 , struct V_1 ,
V_673 . V_706 ) ;
int V_11 ;
if ( F_226 ( V_707 , & V_594 -> V_671 ) )
return;
if ( F_226 ( V_708 , & V_594 -> V_671 ) ) {
struct V_69 * V_655 = F_202 ( V_594 ) ;
if ( ! V_655 ) {
F_173 ( V_594 , V_708 ) ;
return;
}
V_11 = F_161 ( V_594 , V_655 ) ;
if ( V_11 )
F_173 ( V_594 , V_708 ) ;
F_204 ( V_594 , V_655 ) ;
}
if ( F_226 ( V_643 , & V_594 -> V_671 ) )
F_220 ( V_594 ) ;
if ( F_226 ( V_684 ,
& V_594 -> V_671 ) )
F_221 ( V_594 ) ;
if ( F_226 ( V_695 ,
& V_594 -> V_671 ) )
F_222 ( V_594 ) ;
if ( F_226 ( V_702 , & V_594 -> V_671 ) )
F_223 ( V_594 ) ;
}
void F_227 ( struct V_86 * V_52 , bool V_709 )
{
int V_65 ;
F_51 (cdev, i) {
if ( ! V_52 -> V_169 [ V_65 ] . V_672 )
continue;
if ( V_709 ) {
F_173 ( & V_52 -> V_169 [ V_65 ] ,
V_707 ) ;
F_228 ( & V_52 -> V_169 [ V_65 ] . V_673 ) ;
}
F_200 ( V_52 -> V_169 [ V_65 ] . V_672 ) ;
F_229 ( V_52 -> V_169 [ V_65 ] . V_672 ) ;
}
}
int F_230 ( struct V_86 * V_52 )
{
char V_710 [ V_711 ] ;
int V_65 ;
F_51 (cdev, i) {
struct V_1 * V_2 = & V_52 -> V_169 [ V_65 ] ;
if ( F_231 ( V_2 -> V_52 ) && ! F_36 ( V_2 ) )
continue;
snprintf ( V_710 , V_711 , L_120 ,
V_52 -> V_90 -> V_712 -> V_713 ,
F_232 ( V_52 -> V_90 -> V_714 ) , V_2 -> V_165 ) ;
V_2 -> V_672 = F_233 ( V_710 ) ;
if ( ! V_2 -> V_672 ) {
F_6 ( V_2 , L_121 ) ;
return - V_159 ;
}
if ( F_231 ( V_52 ) )
F_234 ( & V_2 -> V_673 , F_224 ) ;
else
F_234 ( & V_2 -> V_673 , V_715 ) ;
}
return 0 ;
}
