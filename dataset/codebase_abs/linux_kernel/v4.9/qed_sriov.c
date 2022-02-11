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
int V_48 , bool V_49 )
{
if ( ! V_2 -> V_50 ) {
F_6 ( V_2 -> V_51 , L_4 ) ;
return false ;
}
if ( ( V_48 >= V_2 -> V_51 -> V_52 -> V_53 ) ||
( V_48 < 0 ) )
return false ;
if ( ( ! V_2 -> V_50 -> V_54 [ V_48 ] . V_55 ) &&
V_49 )
return false ;
return true ;
}
static struct V_3 * F_11 ( struct V_1 * V_2 ,
T_3 V_56 ,
bool V_49 )
{
struct V_3 * V_57 = NULL ;
if ( ! V_2 -> V_50 ) {
F_6 ( V_2 -> V_51 , L_4 ) ;
return NULL ;
}
if ( F_10 ( V_2 , V_56 , V_49 ) )
V_57 = & V_2 -> V_50 -> V_54 [ V_56 ] ;
else
F_12 ( V_2 , L_5 ,
V_56 ) ;
return V_57 ;
}
static bool F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_3 V_58 )
{
if ( V_58 >= V_4 -> V_59 )
F_7 ( V_2 ,
V_36 ,
L_6 ,
V_4 -> V_37 , V_58 , V_4 -> V_59 ) ;
return V_58 < V_4 -> V_59 ;
}
static bool F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_3 V_60 )
{
if ( V_60 >= V_4 -> V_61 )
F_7 ( V_2 ,
V_36 ,
L_7 ,
V_4 -> V_37 , V_60 , V_4 -> V_61 ) ;
return V_60 < V_4 -> V_61 ;
}
static bool F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_3 V_62 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_4 -> V_64 ; V_63 ++ )
if ( V_4 -> V_65 [ V_63 ] == V_62 )
return true ;
F_7 ( V_2 ,
V_36 ,
L_8 ,
V_4 -> V_37 , V_62 , V_4 -> V_64 ) ;
return false ;
}
static int F_16 ( struct V_1 * V_2 ,
int V_66 , struct V_67 * V_68 )
{
struct V_69 * V_70 ;
int V_71 = sizeof( V_70 -> V_72 ) ;
struct V_73 V_74 ;
struct V_3 * V_4 ;
V_4 = F_11 ( V_2 , ( T_3 ) V_66 , true ) ;
if ( ! V_4 )
return - V_12 ;
if ( ! V_4 -> V_75 )
return - V_12 ;
V_70 = V_4 -> V_76 . V_77 ;
V_70 -> V_78 ++ ;
V_70 -> V_72 = F_17 ( 0 , ( T_1 * ) V_70 + V_71 ,
V_4 -> V_76 . V_79 - V_71 ) ;
F_7 ( V_2 , V_36 ,
L_9 ,
V_70 -> V_78 , V_4 -> V_56 , V_70 -> V_72 ) ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_80 = V_81 ;
V_74 . V_82 = V_4 -> V_37 ;
return F_18 ( V_2 , V_68 , V_4 -> V_76 . V_83 ,
V_4 -> V_75 , V_4 -> V_76 . V_79 / 4 ,
& V_74 ) ;
}
static int F_19 ( struct V_84 * V_51 )
{
struct V_85 * V_86 = V_51 -> V_52 ;
int V_87 = V_86 -> V_87 ;
F_7 ( V_51 , V_36 , L_10 , V_87 ) ;
F_20 ( V_51 -> V_88 , V_87 + V_89 , & V_86 -> V_90 ) ;
F_20 ( V_51 -> V_88 ,
V_87 + V_91 , & V_86 -> V_53 ) ;
F_20 ( V_51 -> V_88 ,
V_87 + V_92 , & V_86 -> V_93 ) ;
F_20 ( V_51 -> V_88 , V_87 + V_94 , & V_86 -> V_95 ) ;
if ( V_86 -> V_95 ) {
F_7 ( V_51 ,
V_36 ,
L_11 ) ;
V_86 -> V_95 = 0 ;
}
F_20 ( V_51 -> V_88 ,
V_87 + V_96 , & V_86 -> V_97 ) ;
F_20 ( V_51 -> V_88 ,
V_87 + V_98 , & V_86 -> V_99 ) ;
F_20 ( V_51 -> V_88 ,
V_87 + V_100 , & V_86 -> V_101 ) ;
F_21 ( V_51 -> V_88 ,
V_87 + V_102 , & V_86 -> V_103 ) ;
F_21 ( V_51 -> V_88 , V_87 + V_104 , & V_86 -> V_105 ) ;
F_22 ( V_51 -> V_88 , V_87 + V_106 , & V_86 -> V_107 ) ;
F_7 ( V_51 ,
V_36 ,
L_12 ,
V_86 -> V_108 ,
V_86 -> V_105 ,
V_86 -> V_90 ,
V_86 -> V_53 ,
V_86 -> V_93 ,
V_86 -> V_109 , V_86 -> V_97 , V_86 -> V_99 , V_86 -> V_103 ) ;
if ( V_86 -> V_95 > F_23 ( V_51 ) ||
V_86 -> V_53 > F_23 ( V_51 ) ) {
F_6 ( V_51 ,
L_13 ,
V_86 -> V_95 ) ;
V_86 -> V_95 = 0 ;
V_86 -> V_53 = 0 ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_67 * V_68 )
{
struct V_110 * V_111 ;
T_3 V_112 ;
T_2 V_113 ;
if ( ! V_2 -> V_25 . V_114 ) {
F_12 ( V_2 ,
L_14 ) ;
return;
}
for ( V_112 = 0 ; V_112 < F_25 ( V_2 -> V_51 ) ;
V_112 ++ ) {
V_111 = & V_2 -> V_25 . V_114 -> V_115 . V_116 [ V_112 ] ;
if ( ( V_111 -> V_117 & V_118 ) &&
! ( V_111 -> V_117 & V_119 ) ) {
V_113 = F_26 ( V_2 , V_68 ,
V_120 + V_112 * 4 ) ;
F_27 ( V_113 , V_121 , 0 ) ;
F_28 ( V_2 , V_68 ,
V_120 + 4 * V_112 , V_113 ) ;
}
}
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_85 * V_122 = V_2 -> V_51 -> V_52 ;
struct V_123 * V_52 = V_2 -> V_50 ;
struct V_69 * V_124 ;
T_4 V_125 , V_126 , V_127 ;
union V_128 * V_129 ;
union V_130 * V_131 ;
T_1 V_132 = 0 ;
memset ( V_52 -> V_54 , 0 , sizeof( V_52 -> V_54 ) ) ;
V_131 = V_52 -> V_133 ;
V_125 = V_52 -> V_134 ;
V_129 = V_52 -> V_135 ;
V_126 = V_52 -> V_136 ;
V_124 = V_52 -> V_137 ;
V_127 = V_52 -> V_138 ;
if ( ! V_131 || ! V_129 || ! V_124 ) {
F_12 ( V_2 ,
L_15 ) ;
return;
}
for ( V_132 = 0 ; V_132 < V_122 -> V_53 ; V_132 ++ ) {
struct V_3 * V_57 = & V_52 -> V_54 [ V_132 ] ;
T_2 V_139 ;
V_57 -> V_140 . V_141 = V_131 + V_132 ;
V_57 -> V_140 . V_142 = V_125 + V_132 * sizeof( union V_130 ) ;
V_57 -> V_140 . V_143 = V_129 + V_132 ;
V_57 -> V_140 . V_144 = V_126 + V_132 * sizeof( union V_128 ) ;
V_57 -> V_145 = V_146 ;
V_57 -> V_55 = false ;
V_57 -> V_76 . V_83 = V_132 *
sizeof( struct V_69 ) +
V_127 ;
V_57 -> V_76 . V_77 = V_124 + V_132 ;
V_57 -> V_76 . V_79 = sizeof( struct V_69 ) ;
V_57 -> V_56 = V_132 ;
V_57 -> V_37 = V_132 + V_122 -> V_147 ;
V_139 = F_30 ( V_2 , V_57 -> V_37 ) ;
V_57 -> V_23 = V_139 ;
V_57 -> V_15 = ( V_2 -> V_25 . V_15 & 0xff ) |
( V_57 -> V_37 << 8 ) ;
V_57 -> V_148 = V_132 + 1 ;
V_57 -> V_149 = V_150 ;
V_57 -> V_151 = V_152 ;
}
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_123 * V_52 = V_2 -> V_50 ;
void * * V_153 ;
T_3 V_95 = 0 ;
V_95 = V_2 -> V_51 -> V_52 -> V_53 ;
F_7 ( V_2 , V_36 ,
L_16 , V_95 ) ;
V_52 -> V_154 = sizeof( union V_130 ) * V_95 ;
V_153 = & V_52 -> V_133 ;
* V_153 = F_32 ( & V_2 -> V_51 -> V_88 -> V_155 ,
V_52 -> V_154 ,
& V_52 -> V_134 ,
V_156 ) ;
if ( ! * V_153 )
return - V_157 ;
V_52 -> V_158 = sizeof( union V_128 ) * V_95 ;
V_153 = & V_52 -> V_135 ;
* V_153 = F_32 ( & V_2 -> V_51 -> V_88 -> V_155 ,
V_52 -> V_158 ,
& V_52 -> V_136 ,
V_156 ) ;
if ( ! * V_153 )
return - V_157 ;
V_52 -> V_159 = sizeof( struct V_69 ) *
V_95 ;
V_153 = & V_52 -> V_137 ;
* V_153 = F_32 ( & V_2 -> V_51 -> V_88 -> V_155 ,
V_52 -> V_159 ,
& V_52 -> V_138 ,
V_156 ) ;
if ( ! * V_153 )
return - V_157 ;
F_7 ( V_2 ,
V_36 ,
L_17 ,
V_52 -> V_133 ,
( V_160 ) V_52 -> V_134 ,
V_52 -> V_135 ,
( V_160 ) V_52 -> V_136 ,
V_52 -> V_137 , ( V_160 ) V_52 -> V_138 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_123 * V_52 = V_2 -> V_50 ;
if ( V_2 -> V_50 -> V_133 )
F_34 ( & V_2 -> V_51 -> V_88 -> V_155 ,
V_52 -> V_154 ,
V_52 -> V_133 ,
V_52 -> V_134 ) ;
if ( V_2 -> V_50 -> V_135 )
F_34 ( & V_2 -> V_51 -> V_88 -> V_155 ,
V_52 -> V_158 ,
V_52 -> V_135 ,
V_52 -> V_136 ) ;
if ( V_52 -> V_137 )
F_34 ( & V_2 -> V_51 -> V_88 -> V_155 ,
V_52 -> V_159 ,
V_52 -> V_137 ,
V_52 -> V_138 ) ;
}
int F_35 ( struct V_1 * V_2 )
{
struct V_123 * V_161 ;
if ( ! F_36 ( V_2 ) ) {
F_7 ( V_2 , V_36 ,
L_18 ) ;
return 0 ;
}
V_161 = F_37 ( sizeof( * V_161 ) , V_156 ) ;
if ( ! V_161 )
return - V_157 ;
V_2 -> V_50 = V_161 ;
return F_31 ( V_2 ) ;
}
void F_38 ( struct V_1 * V_2 , struct V_67 * V_68 )
{
if ( ! F_36 ( V_2 ) || ! F_39 ( V_2 ) )
return;
F_29 ( V_2 ) ;
F_24 ( V_2 , V_68 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
if ( F_39 ( V_2 ) ) {
F_33 ( V_2 ) ;
F_41 ( V_2 -> V_50 ) ;
}
}
void F_42 ( struct V_84 * V_51 )
{
F_41 ( V_51 -> V_52 ) ;
V_51 -> V_52 = NULL ;
}
int F_43 ( struct V_1 * V_2 )
{
struct V_84 * V_51 = V_2 -> V_51 ;
int V_87 ;
int V_11 ;
if ( F_44 ( V_2 -> V_51 ) )
return 0 ;
V_87 = F_45 ( V_2 -> V_51 -> V_88 ,
V_162 ) ;
if ( ! V_87 ) {
F_7 ( V_2 , V_36 , L_19 ) ;
return 0 ;
}
V_51 -> V_52 = F_37 ( sizeof( * V_51 -> V_52 ) , V_156 ) ;
if ( ! V_51 -> V_52 )
return - V_157 ;
V_51 -> V_52 -> V_87 = V_87 ;
V_11 = F_19 ( V_51 ) ;
if ( V_11 )
return V_11 ;
if ( ! V_51 -> V_52 -> V_53 ) {
F_7 ( V_2 , V_36 ,
L_20 ) ;
F_41 ( V_51 -> V_52 ) ;
V_51 -> V_52 = NULL ;
return 0 ;
}
V_51 -> V_52 -> V_147 = V_2 -> V_51 -> V_52 -> V_97 +
V_2 -> V_163 - 16 ;
if ( F_46 ( V_2 ) )
V_51 -> V_52 -> V_147 -= V_164 ;
F_7 ( V_2 , V_36 ,
L_21 ,
V_51 -> V_52 -> V_147 ) ;
return 0 ;
}
static bool F_47 ( struct V_1 * V_2 , int V_66 )
{
if ( F_44 ( V_2 -> V_51 ) || ! F_48 ( V_2 -> V_51 ) ||
! F_39 ( V_2 ) )
return false ;
if ( ! F_10 ( V_2 , V_66 , true ) )
return false ;
return true ;
}
static void F_49 ( struct V_84 * V_51 ,
T_3 V_48 , T_1 V_165 )
{
struct V_3 * V_57 ;
int V_63 ;
F_50 (cdev, i) {
struct V_1 * V_2 = & V_51 -> V_166 [ V_63 ] ;
V_57 = F_11 ( V_2 , V_48 , false ) ;
if ( ! V_57 )
continue;
V_57 -> V_165 = V_165 ;
}
}
static void F_51 ( struct V_84 * V_51 , T_1 V_165 )
{
T_3 V_63 ;
if ( ! F_48 ( V_51 ) )
return;
for ( V_63 = 0 ; V_63 < V_51 -> V_52 -> V_53 ; V_63 ++ )
F_49 ( V_51 , V_63 , V_165 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_67 * V_68 , T_1 V_167 )
{
F_28 ( V_2 , V_68 ,
V_168 + ( V_167 >> 5 ) * 4 ,
1 << ( V_167 & 0x1f ) ) ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_67 * V_68 , struct V_3 * V_57 )
{
int V_63 ;
F_54 ( V_2 , V_68 , ( T_3 ) V_57 -> V_23 ) ;
F_28 ( V_2 , V_68 , V_169 , 0 ) ;
F_54 ( V_2 , V_68 , ( T_3 ) V_2 -> V_25 . V_23 ) ;
for ( V_63 = 0 ; V_63 < V_57 -> V_64 ; V_63 ++ )
F_55 ( V_2 , V_68 ,
V_57 -> V_65 [ V_63 ] ,
V_57 -> V_15 , true ) ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_3 * V_57 , bool V_170 )
{
T_2 V_171 ;
F_54 ( V_2 , V_68 , ( T_3 ) V_57 -> V_23 ) ;
V_171 = F_26 ( V_2 , V_68 , V_172 ) ;
if ( V_170 )
V_171 |= V_173 ;
else
V_171 &= ~ V_173 ;
F_28 ( V_2 , V_68 , V_172 , V_171 ) ;
F_54 ( V_2 , V_68 , ( T_3 ) V_2 -> V_25 . V_23 ) ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_3 * V_57 )
{
T_2 V_171 = V_174 ;
int V_11 ;
if ( V_57 -> V_165 )
return 0 ;
F_7 ( V_2 ,
V_36 ,
L_22 ,
V_57 -> V_37 , F_58 ( V_2 , V_57 ) ) ;
F_52 ( V_2 , V_68 , F_58 ( V_2 , V_57 ) ) ;
F_53 ( V_2 , V_68 , V_57 ) ;
V_11 = F_59 ( V_2 , V_68 , V_57 -> V_37 , V_57 -> V_64 ) ;
if ( V_11 )
return V_11 ;
F_54 ( V_2 , V_68 , ( T_3 ) V_57 -> V_23 ) ;
F_27 ( V_171 , V_175 , V_2 -> V_176 ) ;
F_60 ( V_2 , V_177 , V_171 ) ;
F_61 ( V_2 , V_68 , V_178 , V_57 -> V_37 ,
V_2 -> V_25 . V_179 ) ;
F_54 ( V_2 , V_68 , ( T_3 ) V_2 -> V_25 . V_23 ) ;
V_57 -> V_145 = V_180 ;
return V_11 ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_3 * V_57 , T_1 V_170 )
{
T_2 V_181 , V_113 ;
T_3 V_182 = 0 ;
int V_183 ;
for ( V_183 = 0 ; V_183 < V_57 -> V_59 ; V_183 ++ ) {
F_63 ( V_2 , V_57 -> V_184 [ V_183 ] . V_185 ,
& V_182 ) ;
V_181 = V_186 + V_182 * 4 ;
V_113 = V_170 ? ( V_57 -> V_37 | F_64 ( 8 ) ) : 0 ;
F_28 ( V_2 , V_68 , V_181 , V_113 ) ;
}
}
static void F_65 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_3 * V_57 )
{
F_53 ( V_2 , V_68 , V_57 ) ;
F_56 ( V_2 , V_68 , V_57 , 1 ) ;
F_62 ( V_2 , V_68 , V_57 , true ) ;
}
static T_1 F_66 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_3 * V_57 , T_3 V_187 )
{
struct V_110 * V_116 ;
int V_183 = 0 , V_188 = 0 ;
T_2 V_113 = 0 ;
V_116 = V_2 -> V_25 . V_114 -> V_115 . V_116 ;
if ( V_187 > V_2 -> V_25 . V_114 -> V_189 )
V_187 = V_2 -> V_25 . V_114 -> V_189 ;
V_2 -> V_25 . V_114 -> V_189 -= V_187 ;
F_27 ( V_113 , V_190 , V_57 -> V_37 ) ;
F_27 ( V_113 , V_121 , 1 ) ;
F_27 ( V_113 , V_191 , 0 ) ;
while ( ( V_183 < V_187 ) &&
( V_188 < F_25 ( V_2 -> V_51 ) ) ) {
if ( V_116 [ V_188 ] . V_117 & V_118 ) {
struct V_192 V_193 ;
V_57 -> V_65 [ V_183 ] = ( T_3 ) V_188 ;
V_116 [ V_188 ] . V_117 &= ~ V_118 ;
F_27 ( V_113 , V_194 , V_183 ) ;
F_28 ( V_2 , V_68 ,
V_120 + sizeof( T_2 ) * V_188 ,
V_113 ) ;
F_67 ( V_2 , & V_193 ,
V_2 -> V_176 ,
V_57 -> V_37 , 1 ) ;
F_68 ( V_2 , V_68 ,
( V_160 ) ( V_195 ) & V_193 ,
V_196 +
V_188 * sizeof( V_160 ) , 2 , 0 ) ;
V_183 ++ ;
}
V_188 ++ ;
}
V_57 -> V_64 = ( T_1 ) V_187 ;
return V_57 -> V_64 ;
}
static void F_69 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_3 * V_57 )
{
struct V_197 * V_198 = V_2 -> V_25 . V_114 ;
int V_132 , V_188 ;
T_2 V_199 , V_113 ;
for ( V_132 = 0 ; V_132 < V_57 -> V_64 ; V_132 ++ ) {
V_188 = V_57 -> V_65 [ V_132 ] ;
V_199 = V_120 + sizeof( T_2 ) * V_188 ;
V_113 = F_26 ( V_2 , V_68 , V_199 ) ;
F_27 ( V_113 , V_121 , 0 ) ;
F_28 ( V_2 , V_68 , V_199 , V_113 ) ;
V_198 -> V_115 . V_116 [ V_188 ] . V_117 |=
V_118 ;
V_2 -> V_25 . V_114 -> V_189 ++ ;
}
V_57 -> V_64 = 0 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
T_3 V_48 , T_3 V_187 )
{
T_1 V_200 = 0 ;
struct V_3 * V_57 = NULL ;
int V_11 = 0 ;
T_2 V_201 ;
T_1 V_63 ;
V_57 = F_11 ( V_2 , V_48 , false ) ;
if ( ! V_57 ) {
F_12 ( V_2 , L_23 ) ;
return - V_12 ;
}
if ( V_57 -> V_55 ) {
F_6 ( V_2 , L_24 , V_48 ) ;
return - V_12 ;
}
F_71 ( V_2 , V_202 , & V_201 ) ;
F_7 ( V_2 ,
V_36 ,
L_25 ,
V_57 -> V_56 , V_187 , ( T_3 ) V_201 ) ;
V_187 = F_72 ( T_3 , V_187 , ( ( T_3 ) V_201 ) ) ;
V_200 = F_66 ( V_2 ,
V_68 ,
V_57 ,
V_187 ) ;
if ( ! V_200 ) {
F_12 ( V_2 , L_26 ) ;
return - V_157 ;
}
V_57 -> V_59 = V_200 ;
V_57 -> V_61 = V_200 ;
for ( V_63 = 0 ; V_63 < V_57 -> V_59 ; V_63 ++ ) {
T_3 V_203 = F_73 ( V_2 ,
V_57 -> V_65 [ V_63 ] ) ;
if ( V_203 > F_74 ( V_2 , V_204 ) ) {
F_6 ( V_2 ,
L_27 ,
V_57 -> V_56 , V_203 ) ;
return - V_12 ;
}
V_57 -> V_184 [ V_63 ] . V_185 = V_203 ;
V_57 -> V_184 [ V_63 ] . V_205 = V_203 ;
V_57 -> V_184 [ V_63 ] . V_206 = V_63 ;
F_7 ( V_2 , V_36 ,
L_28 ,
V_57 -> V_56 , V_63 , V_57 -> V_65 [ V_63 ] , V_203 , V_63 ) ;
}
V_11 = F_57 ( V_2 , V_68 , V_57 ) ;
if ( ! V_11 ) {
V_57 -> V_55 = true ;
if ( F_75 ( V_2 ) )
V_2 -> V_51 -> V_52 -> V_95 ++ ;
}
return V_11 ;
}
static void F_76 ( struct V_1 * V_2 ,
T_3 V_66 ,
struct V_207 * V_74 ,
struct V_208 * V_107 ,
struct V_209 * V_210 )
{
struct V_3 * V_4 = F_11 ( V_2 ,
V_66 ,
false ) ;
struct V_69 * V_70 ;
if ( ! V_4 )
return;
V_70 = V_4 -> V_76 . V_77 ;
V_70 -> V_211 = V_74 -> V_212 . V_213 ;
V_70 -> V_214 = V_74 -> V_212 . V_215 ;
V_70 -> V_216 = V_74 -> V_212 . V_217 ;
V_70 -> V_218 = V_74 -> V_219 . V_213 ;
V_70 -> V_220 = V_74 -> V_219 . V_221 ;
V_70 -> V_222 = V_74 -> V_219 . V_223 ;
V_70 -> V_224 = V_74 -> V_225 ;
V_70 -> V_226 = V_107 -> V_226 ;
V_70 -> V_212 = V_107 -> V_212 ;
V_70 -> V_227 = V_107 -> V_227 ;
V_70 -> V_213 = V_107 -> V_228 ;
V_70 -> V_229 = V_107 -> V_230 ;
V_70 -> V_231 = V_107 -> V_231 ;
V_70 -> V_232 = V_107 -> V_232 ;
V_70 -> V_233 = V_107 -> V_233 ;
V_70 -> V_234 = V_107 -> V_234 ;
V_70 -> V_235 = V_107 -> V_235 ;
V_70 -> V_236 = V_107 -> V_236 ;
V_70 -> V_237 = V_107 -> V_237 ;
V_70 -> V_238 = V_210 -> V_239 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_67 * V_68 , T_3 V_48 )
{
struct V_209 V_240 ;
struct V_207 V_74 ;
struct V_208 V_107 ;
struct V_3 * V_57 = NULL ;
V_57 = F_11 ( V_2 , V_48 , true ) ;
if ( ! V_57 ) {
F_12 ( V_2 , L_29 ) ;
return - V_12 ;
}
if ( V_57 -> V_76 . V_77 )
memset ( V_57 -> V_76 . V_77 , 0 , sizeof( * V_57 -> V_76 . V_77 ) ) ;
memset ( & V_57 -> V_241 , 0 , sizeof( V_57 -> V_241 ) ) ;
memcpy ( & V_74 , F_78 ( V_2 ) , sizeof( V_74 ) ) ;
memcpy ( & V_107 , F_79 ( V_2 ) , sizeof( V_107 ) ) ;
memcpy ( & V_240 , F_80 ( V_2 ) , sizeof( V_240 ) ) ;
F_76 ( V_2 , V_48 , & V_74 , & V_107 , & V_240 ) ;
memset ( & V_57 -> V_31 , 0 , sizeof( V_57 -> V_31 ) ) ;
F_56 ( V_2 , V_68 , V_57 , 0 ) ;
F_62 ( V_2 , V_68 , V_57 , 0 ) ;
V_57 -> V_59 = 0 ;
V_57 -> V_61 = 0 ;
F_69 ( V_2 , V_68 , V_57 ) ;
if ( V_57 -> V_55 ) {
V_57 -> V_55 = false ;
if ( F_75 ( V_2 ) )
V_2 -> V_51 -> V_52 -> V_95 -- ;
}
return 0 ;
}
static bool F_81 ( T_3 V_242 )
{
return V_243 < V_242 && V_242 < V_244 ;
}
void * F_82 ( struct V_1 * V_2 , T_1 * * V_97 , T_3 type , T_3 V_245 )
{
struct V_246 * V_247 = (struct V_246 * ) * V_97 ;
V_247 -> type = type ;
V_247 -> V_245 = V_245 ;
* V_97 += V_245 ;
return * V_97 - V_245 ;
}
void F_83 ( struct V_1 * V_2 , void * V_248 )
{
T_3 V_63 = 1 , V_249 = 0 ;
struct V_246 * V_250 ;
do {
V_250 = (struct V_246 * ) ( ( T_1 * ) V_248 + V_249 ) ;
F_7 ( V_2 , V_36 ,
L_30 ,
V_63 , V_250 -> type , V_250 -> V_245 ) ;
if ( V_250 -> type == V_251 )
return;
if ( ! V_250 -> V_245 ) {
F_6 ( V_2 , L_31 ) ;
return;
}
V_249 += V_250 -> V_245 ;
if ( V_249 >= sizeof( struct V_252 ) ) {
F_6 ( V_2 , L_32 ) ;
return;
}
V_63 ++ ;
} while ( 1 );
}
static void F_84 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_3 * V_4 ,
T_3 V_245 , T_1 V_117 )
{
struct V_253 * V_254 = & V_4 -> V_140 ;
struct V_73 V_74 ;
T_1 V_255 ;
V_254 -> V_143 -> V_256 . V_257 . V_117 = V_117 ;
F_83 ( V_2 , V_254 -> V_143 ) ;
V_255 = V_4 -> V_37 ;
memset ( & V_74 , 0 , sizeof( struct V_73 ) ) ;
V_74 . V_80 = V_81 ;
V_74 . V_82 = V_255 ;
F_18 ( V_2 , V_68 , V_254 -> V_144 + sizeof( V_160 ) ,
V_254 -> V_141 -> V_258 . V_259 +
sizeof( V_160 ) ,
( sizeof( union V_128 ) - sizeof( V_160 ) ) / 4 ,
& V_74 ) ;
F_18 ( V_2 , V_68 , V_254 -> V_144 ,
V_254 -> V_141 -> V_258 . V_259 ,
sizeof( V_160 ) / 4 , & V_74 ) ;
F_85 ( V_2 ,
V_260 +
F_86 ( V_255 ) , 1 ) ;
}
static T_3 F_87 ( struct V_1 * V_2 ,
enum V_261 V_262 )
{
switch ( V_262 ) {
case V_263 :
return V_264 ;
case V_265 :
return V_266 ;
case V_267 :
return V_268 ;
case V_269 :
return V_270 ;
case V_271 :
return V_272 ;
case V_273 :
return V_274 ;
case V_275 :
return V_276 ;
case V_277 :
return V_278 ;
default:
return 0 ;
}
}
static T_3 F_88 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_253 * V_279 ,
T_1 V_117 ,
T_3 V_280 , T_3 V_281 )
{
struct V_282 * V_283 ;
T_3 V_79 , V_284 , V_63 ;
memset ( V_279 -> V_143 , 0 , sizeof( union V_128 ) ) ;
V_279 -> V_97 = ( T_1 * ) V_279 -> V_143 ;
V_79 = sizeof( struct V_282 ) ;
V_284 = V_79 ;
F_82 ( V_2 , & V_279 -> V_97 , V_285 , V_79 ) ;
for ( V_63 = 0 ; V_63 < V_286 ; V_63 ++ ) {
if ( ! ( V_280 & F_64 ( V_63 ) ) )
continue;
V_283 = F_82 ( V_2 , & V_279 -> V_97 ,
F_87 ( V_2 , V_63 ) , V_79 ) ;
if ( V_281 & F_64 ( V_63 ) )
V_283 -> V_257 . V_117 = V_117 ;
else
V_283 -> V_257 . V_117 = V_287 ;
F_7 ( V_2 ,
V_36 ,
L_33 ,
V_4 -> V_56 ,
F_87 ( V_2 , V_63 ) , V_283 -> V_257 . V_117 ) ;
V_284 += V_79 ;
}
F_82 ( V_2 , & V_279 -> V_97 , V_251 ,
sizeof( struct V_288 ) ) ;
return V_284 ;
}
static void F_89 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_3 * V_289 ,
T_3 type , T_3 V_245 , T_1 V_117 )
{
struct V_253 * V_254 = & V_289 -> V_140 ;
V_254 -> V_97 = ( T_1 * ) V_254 -> V_143 ;
F_82 ( V_2 , & V_254 -> V_97 , type , V_245 ) ;
F_82 ( V_2 , & V_254 -> V_97 , V_251 ,
sizeof( struct V_288 ) ) ;
F_84 ( V_2 , V_68 , V_289 , V_245 , V_117 ) ;
}
static struct
V_290 * F_90 ( struct V_1 * V_2 ,
T_3 V_56 ,
bool V_49 )
{
struct V_3 * V_57 = NULL ;
V_57 = F_11 ( V_2 , V_56 , V_49 ) ;
if ( ! V_57 )
return NULL ;
return & V_57 -> V_241 ;
}
static void F_91 ( struct V_1 * V_2 , T_1 V_66 )
{
struct V_290 * V_289 ;
V_289 = F_90 ( V_2 , V_66 , false ) ;
if ( ! V_289 )
return;
memset ( V_289 -> V_291 , 0 , V_292 ) ;
}
static void F_92 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_63 ;
V_4 -> V_75 = 0 ;
V_4 -> V_293 = 0 ;
V_4 -> V_294 = 0 ;
V_4 -> V_59 = V_4 -> V_64 ;
V_4 -> V_61 = V_4 -> V_64 ;
V_4 -> V_295 = 0 ;
for ( V_63 = 0 ; V_63 < V_296 ; V_63 ++ )
V_4 -> V_184 [ V_63 ] . V_297 = 0 ;
memset ( & V_4 -> V_298 , 0 , sizeof( V_4 -> V_298 ) ) ;
memset ( & V_4 -> V_31 , 0 , sizeof( V_4 -> V_31 ) ) ;
F_91 ( V_2 , V_4 -> V_56 ) ;
}
static T_1 F_93 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_3 * V_4 ,
struct V_299 * V_300 ,
struct V_301 * V_302 )
{
int V_63 ;
V_302 -> V_59 = V_4 -> V_59 ;
V_302 -> V_61 = V_4 -> V_61 ;
V_302 -> V_64 = V_4 -> V_64 ;
for ( V_63 = 0 ; V_63 < V_302 -> V_64 ; V_63 ++ ) {
V_302 -> V_303 [ V_63 ] . V_304 = V_4 -> V_65 [ V_63 ] ;
V_302 -> V_303 [ V_63 ] . V_305 = 0 ;
}
for ( V_63 = 0 ; V_63 < V_302 -> V_59 ; V_63 ++ ) {
F_63 ( V_2 , V_4 -> V_184 [ V_63 ] . V_185 ,
( T_3 * ) & V_302 -> V_306 [ V_63 ] ) ;
V_302 -> V_14 [ V_63 ] = V_4 -> V_184 [ V_63 ] . V_206 ;
}
V_302 -> V_149 = F_72 ( T_1 , V_4 -> V_149 ,
V_300 -> V_149 ) ;
V_302 -> V_151 = F_72 ( T_1 , V_4 -> V_151 ,
V_300 -> V_151 ) ;
V_302 -> V_307 = V_308 ;
if ( V_302 -> V_59 < V_300 -> V_59 ||
V_302 -> V_61 < V_300 -> V_61 ||
V_302 -> V_64 < V_300 -> V_64 ||
V_302 -> V_149 < V_300 -> V_149 ||
V_302 -> V_151 < V_300 -> V_151 ||
V_302 -> V_307 < V_300 -> V_307 ) {
F_7 ( V_2 ,
V_36 ,
L_34 ,
V_4 -> V_37 ,
V_300 -> V_59 ,
V_302 -> V_59 ,
V_300 -> V_59 ,
V_302 -> V_61 ,
V_300 -> V_64 ,
V_302 -> V_64 ,
V_300 -> V_149 ,
V_302 -> V_149 ,
V_300 -> V_151 ,
V_302 -> V_151 ,
V_300 -> V_307 , V_302 -> V_307 ) ;
if ( ( V_4 -> V_31 . V_32 . V_33 ==
V_35 ) &&
( V_4 -> V_31 . V_32 . V_309 ==
V_310 ) )
return V_311 ;
return V_312 ;
}
return V_311 ;
}
static void F_94 ( struct V_1 * V_2 ,
struct V_313 * V_314 )
{
V_314 -> V_315 . V_316 = V_317 +
F_95 ( struct V_318 ,
V_319 . V_320 ) ;
V_314 -> V_315 . V_321 = sizeof( struct V_322 ) ;
V_314 -> V_323 . V_316 = V_324 +
F_95 ( struct V_325 ,
V_319 . V_320 ) ;
V_314 -> V_323 . V_321 = sizeof( struct V_326 ) ;
V_314 -> V_327 . V_316 = V_328 +
F_95 ( struct V_329 ,
V_319 . V_320 ) ;
V_314 -> V_327 . V_321 = sizeof( struct V_330 ) ;
V_314 -> V_331 . V_316 = 0 ;
V_314 -> V_331 . V_321 = 0 ;
}
static void F_96 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_3 * V_57 )
{
struct V_253 * V_254 = & V_57 -> V_140 ;
struct V_332 * V_283 = & V_254 -> V_143 -> V_333 ;
struct V_334 * V_335 = & V_283 -> V_335 ;
struct V_336 * V_337 = & V_254 -> V_141 -> V_31 ;
T_1 V_338 = V_287 ;
struct V_301 * V_339 = & V_283 -> V_339 ;
int V_11 ;
memset ( V_283 , 0 , sizeof( * V_283 ) ) ;
V_335 -> V_340 = V_38 ;
V_335 -> V_341 = V_34 ;
if ( V_57 -> V_145 != V_180 && V_57 -> V_145 != V_146 ) {
F_7 ( V_2 ,
V_36 ,
L_35 ,
V_57 -> V_37 , V_57 -> V_145 ) ;
goto V_342;
}
if ( V_337 -> V_32 . V_343 != V_38 ) {
if ( V_337 -> V_32 . V_344 &
V_345 ) {
struct V_346 * V_347 = & V_337 -> V_32 ;
F_7 ( V_2 , V_36 ,
L_36 ,
V_57 -> V_37 ) ;
V_347 -> V_343 = V_38 ;
V_347 -> V_33 = V_35 ;
} else {
F_97 ( V_2 ,
L_37 ,
V_57 -> V_37 ,
V_337 -> V_32 . V_343 ,
V_337 -> V_32 . V_33 ,
V_38 , V_34 ) ;
goto V_342;
}
}
if ( ( V_2 -> V_51 -> V_348 > 1 ) &&
! ( V_337 -> V_32 . V_344 & V_349 ) ) {
F_97 ( V_2 ,
L_38 ,
V_57 -> V_37 ) ;
goto V_342;
}
memcpy ( & V_57 -> V_31 , V_337 , sizeof( V_57 -> V_31 ) ) ;
V_57 -> V_15 = V_337 -> V_32 . V_15 ;
V_57 -> V_75 = V_337 -> V_350 ;
V_57 -> V_76 . V_79 = ( V_57 -> V_76 . V_79 < V_337 -> V_351 ) ?
V_57 -> V_76 . V_79 : V_337 -> V_351 ;
V_335 -> V_352 = V_2 -> V_51 -> V_352 ;
V_335 -> V_353 = 0 ;
V_335 -> V_354 = V_355 ;
V_335 -> V_344 = V_356 |
V_357 ;
if ( V_2 -> V_51 -> V_348 > 1 )
V_335 -> V_344 |= V_358 ;
F_94 ( V_2 , & V_335 -> V_359 ) ;
memcpy ( V_335 -> V_360 , V_2 -> V_25 . V_361 , V_292 ) ;
V_335 -> V_362 = V_363 ;
V_335 -> V_364 = V_365 ;
V_335 -> V_366 = V_367 ;
V_335 -> V_368 = V_369 ;
V_335 -> V_341 = F_72 ( T_1 , V_34 ,
V_337 -> V_32 . V_33 ) ;
V_335 -> V_309 = V_370 ;
F_98 ( V_2 , V_68 , & V_335 -> V_371 , NULL ) ;
V_335 -> V_372 = V_2 -> V_51 -> type ;
V_335 -> V_373 = V_2 -> V_51 -> V_373 ;
V_338 = F_93 ( V_2 , V_68 , V_57 ,
& V_337 -> V_374 , V_339 ) ;
if ( V_338 != V_311 )
goto V_342;
V_11 = F_1 ( V_2 , V_57 ) ;
if ( V_11 ) {
F_6 ( V_2 , L_39 , V_57 -> V_37 ) ;
V_338 = V_375 ;
goto V_342;
}
V_283 -> V_351 = V_57 -> V_76 . V_79 ;
F_16 ( V_2 , V_57 -> V_56 , V_68 ) ;
F_7 ( V_2 ,
V_36 ,
L_40
L_41 ,
V_57 -> V_37 ,
V_283 -> V_335 . V_352 ,
V_283 -> V_335 . V_353 ,
V_283 -> V_335 . V_354 ,
V_283 -> V_335 . V_344 ,
V_339 -> V_59 ,
V_339 -> V_61 ,
V_339 -> V_64 ,
V_339 -> V_149 ,
V_339 -> V_151 ) ;
V_57 -> V_145 = V_376 ;
V_342:
F_89 ( V_2 , V_68 , V_57 , V_377 ,
sizeof( struct V_332 ) , V_338 ) ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_113 )
{
struct V_378 V_74 ;
int V_11 ;
if ( V_113 == V_4 -> V_379 ) {
F_7 ( V_2 , V_36 ,
L_42 , V_113 ) ;
return 0 ;
}
memset ( & V_74 , 0 , sizeof( struct V_378 ) ) ;
V_74 . V_15 = V_4 -> V_15 ;
V_74 . V_148 = V_4 -> V_148 ;
V_74 . V_380 = 1 ;
V_74 . V_381 = V_113 ;
V_11 = F_100 ( V_2 , & V_74 , V_17 , NULL ) ;
if ( ! V_11 ) {
V_4 -> V_379 = V_113 ;
V_4 -> V_382 = V_4 -> V_379 ;
F_7 ( V_2 , V_36 ,
L_43 , V_113 ) ;
} else {
F_7 ( V_2 , V_36 ,
L_44 ,
V_113 , V_4 -> V_56 ) ;
}
return V_11 ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_383 V_384 ;
int V_11 = 0 ;
int V_63 ;
memset ( & V_384 , 0 , sizeof( V_384 ) ) ;
V_384 . V_385 = 1 ;
V_384 . V_386 = 1 ;
V_384 . V_387 = V_4 -> V_148 ;
V_384 . V_388 = V_389 ;
for ( V_63 = 0 ; V_63 < V_152 + 1 ; V_63 ++ ) {
if ( ! V_4 -> V_298 . V_390 [ V_63 ] . V_391 )
continue;
V_384 . type = V_392 ;
V_384 . V_393 = V_4 -> V_298 . V_390 [ V_63 ] . V_394 ;
F_7 ( V_2 , V_36 ,
L_45 ,
V_384 . V_393 , V_4 -> V_56 ) ;
V_11 = F_102 ( V_2 , V_4 -> V_15 ,
& V_384 , V_395 , NULL ) ;
if ( V_11 ) {
F_6 ( V_2 ,
L_46 ,
V_384 . V_393 , V_4 -> V_56 ) ;
break;
}
}
return V_11 ;
}
static int
F_103 ( struct V_1 * V_2 ,
struct V_3 * V_4 , V_160 V_396 )
{
int V_11 = 0 ;
if ( ( V_396 & F_64 ( V_397 ) ) &&
! ( V_4 -> V_294 & ( 1 << V_397 ) ) )
V_11 = F_101 ( V_2 , V_4 ) ;
return V_11 ;
}
static int F_104 ( struct V_1 * V_2 ,
struct V_3 * V_4 , V_160 V_396 )
{
int V_11 = 0 ;
struct V_383 V_384 ;
if ( ! V_4 -> V_293 )
return - V_12 ;
if ( V_396 & F_64 ( V_398 ) ) {
memset ( & V_384 , 0 , sizeof( V_384 ) ) ;
V_384 . type = V_399 ;
V_384 . V_388 = V_400 ;
V_384 . V_385 = 1 ;
V_384 . V_386 = 1 ;
V_384 . V_387 = V_4 -> V_148 ;
F_105 ( V_384 . V_291 , V_4 -> V_76 . V_77 -> V_291 ) ;
V_11 = F_102 ( V_2 , V_4 -> V_15 ,
& V_384 , V_395 , NULL ) ;
if ( V_11 ) {
F_6 ( V_2 ,
L_47 ) ;
return V_11 ;
}
V_4 -> V_294 |= 1 << V_398 ;
}
if ( V_396 & F_64 ( V_397 ) ) {
struct V_378 V_401 ;
T_1 V_402 ;
int V_63 ;
memset ( & V_384 , 0 , sizeof( V_384 ) ) ;
V_384 . type = V_392 ;
V_384 . V_385 = 1 ;
V_384 . V_386 = 1 ;
V_384 . V_387 = V_4 -> V_148 ;
V_384 . V_393 = V_4 -> V_76 . V_77 -> V_403 ;
V_384 . V_388 = V_384 . V_393 ? V_400 :
V_404 ;
V_11 = F_102 ( V_2 , V_4 -> V_15 ,
& V_384 , V_395 , NULL ) ;
if ( V_11 ) {
F_6 ( V_2 ,
L_48 ) ;
return V_11 ;
}
memset ( & V_401 , 0 , sizeof( V_401 ) ) ;
V_401 . V_15 = V_4 -> V_15 ;
V_401 . V_148 = V_4 -> V_148 ;
V_401 . V_405 = 1 ;
V_401 . V_406 = V_384 . V_393 ? 1 : 0 ;
V_401 . V_407 = 1 ;
V_401 . V_408 = V_384 . V_393 ;
V_401 . V_409 = 1 ;
V_402 = V_384 . V_393 ? 1
: V_4 -> V_298 . V_410 ;
V_401 . V_411 = V_402 ;
V_401 . V_412 = V_384 . V_393 ? 1 : 0 ;
V_11 = F_100 ( V_2 ,
& V_401 ,
V_17 , NULL ) ;
if ( V_11 ) {
F_6 ( V_2 ,
L_49 ) ;
return V_11 ;
}
for ( V_63 = 0 ; V_63 < V_296 ; V_63 ++ ) {
T_3 V_183 ;
if ( ! V_4 -> V_184 [ V_63 ] . V_297 )
continue;
V_183 = V_4 -> V_184 [ V_63 ] . V_185 ;
V_11 = F_106 ( V_2 , V_183 ,
1 , 0 , 1 ,
V_17 ,
NULL ) ;
if ( V_11 ) {
F_6 ( V_2 ,
L_50 ,
V_183 ) ;
return V_11 ;
}
}
if ( V_384 . V_393 )
V_4 -> V_294 |= 1 << V_397 ;
else
V_4 -> V_294 &= ~ F_64 ( V_397 ) ;
}
if ( V_396 )
F_103 ( V_2 , V_4 , V_396 ) ;
return V_11 ;
}
static void F_107 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_3 * V_57 )
{
struct V_413 V_74 = { 0 } ;
struct V_253 * V_254 = & V_57 -> V_140 ;
struct V_414 * V_415 ;
T_1 V_117 = V_311 ;
struct V_3 * V_289 ;
V_160 * V_416 ;
int V_112 ;
int V_11 ;
V_289 = F_11 ( V_2 , ( T_3 ) V_57 -> V_56 , true ) ;
if ( ! V_289 ) {
F_6 ( V_2 -> V_51 ,
L_51 ,
V_57 -> V_56 ) ;
return;
}
V_57 -> V_145 = V_417 ;
V_415 = & V_254 -> V_141 -> V_418 ;
for ( V_112 = 0 ; V_112 < V_57 -> V_64 ; V_112 ++ ) {
if ( ! V_415 -> V_419 [ V_112 ] ) {
F_7 ( V_2 , V_36 ,
L_52 ,
V_57 -> V_56 , V_112 ) ;
break;
}
F_108 ( V_2 , V_68 ,
V_415 -> V_419 [ V_112 ] ,
V_57 -> V_65 [ V_112 ] , V_57 -> V_37 , 1 ) ;
}
F_65 ( V_2 , V_68 , V_57 ) ;
V_57 -> V_420 = V_415 -> V_420 ;
V_57 -> V_298 . V_410 = V_415 -> V_410 ;
V_416 = & V_289 -> V_76 . V_77 -> V_421 ;
if ( ! ( * V_416 & F_64 ( V_422 ) ) ) {
T_1 V_423 = V_415 -> V_424 ;
V_289 -> V_76 . V_77 -> V_425 = V_423 ;
* V_416 |= 1 << V_426 ;
}
V_74 . V_427 = V_415 -> V_427 ;
V_74 . V_428 = V_415 -> V_410 ;
V_74 . V_429 = true ;
V_74 . V_424 = V_289 -> V_76 . V_77 -> V_425 ;
V_74 . V_430 = false ;
V_74 . V_23 = V_57 -> V_23 ;
V_74 . V_15 = V_57 -> V_15 ;
V_74 . V_148 = V_57 -> V_148 ;
V_74 . V_431 = V_415 -> V_431 ;
V_74 . V_420 = V_57 -> V_420 ;
V_74 . V_432 = true ;
V_11 = F_109 ( V_2 , & V_74 ) ;
if ( V_11 ) {
F_12 ( V_2 ,
L_53 , V_11 ) ;
V_117 = V_375 ;
} else {
V_57 -> V_293 ++ ;
F_104 ( V_2 , V_57 , * V_416 ) ;
F_99 ( V_2 , V_57 , V_57 -> V_382 ) ;
}
F_89 ( V_2 , V_68 , V_57 , V_433 ,
sizeof( struct V_282 ) , V_117 ) ;
}
static void F_110 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_3 * V_57 )
{
T_1 V_117 = V_311 ;
int V_11 ;
V_57 -> V_293 -- ;
V_57 -> V_379 = false ;
V_11 = F_111 ( V_2 , V_57 -> V_15 , V_57 -> V_148 ) ;
if ( V_11 ) {
F_12 ( V_2 , L_54 ,
V_11 ) ;
V_117 = V_375 ;
}
V_57 -> V_294 = 0 ;
memset ( & V_57 -> V_298 , 0 , sizeof( V_57 -> V_298 ) ) ;
F_89 ( V_2 , V_68 , V_57 , V_434 ,
sizeof( struct V_282 ) , V_117 ) ;
}
static void F_112 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_3 * V_57 ,
T_1 V_117 , bool V_435 )
{
struct V_253 * V_254 = & V_57 -> V_140 ;
struct V_436 * V_437 ;
struct V_438 * V_337 ;
T_3 V_245 ;
V_254 -> V_97 = ( T_1 * ) V_254 -> V_143 ;
if ( ! V_435 )
V_245 = sizeof( * V_437 ) ;
else
V_245 = sizeof( struct V_282 ) ;
V_437 = F_82 ( V_2 , & V_254 -> V_97 , V_439 ,
V_245 ) ;
F_82 ( V_2 , & V_254 -> V_97 , V_251 ,
sizeof( struct V_288 ) ) ;
if ( ( V_117 == V_311 ) && ! V_435 ) {
V_337 = & V_254 -> V_141 -> V_440 ;
V_437 -> V_97 = V_317 +
F_95 ( struct V_318 ,
V_319 . V_441 ) +
sizeof( struct V_442 ) * V_337 -> V_58 ;
}
F_84 ( V_2 , V_68 , V_57 , V_245 , V_117 ) ;
}
static void F_113 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_3 * V_57 )
{
struct V_443 V_74 ;
struct V_253 * V_254 = & V_57 -> V_140 ;
T_1 V_117 = V_312 ;
struct V_438 * V_337 ;
bool V_444 = false ;
int V_11 ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_337 = & V_254 -> V_141 -> V_440 ;
if ( ! F_13 ( V_2 , V_57 , V_337 -> V_58 ) ||
! F_15 ( V_2 , V_57 , V_337 -> V_445 ) )
goto V_342;
V_74 . V_203 = V_57 -> V_184 [ V_337 -> V_58 ] . V_185 ;
V_74 . V_446 = V_337 -> V_58 ;
V_74 . V_148 = V_57 -> V_148 ;
V_74 . V_447 = V_337 -> V_445 ;
V_74 . V_62 = V_337 -> V_448 ;
if ( V_57 -> V_31 . V_32 . V_33 ==
V_35 ) {
V_444 = true ;
} else {
F_85 ( V_2 ,
V_449 +
F_114 ( V_57 -> V_37 , V_337 -> V_58 ) ,
0 ) ;
}
V_11 = F_115 ( V_2 , V_57 -> V_15 ,
V_57 -> V_184 [ V_337 -> V_58 ] . V_206 ,
& V_74 ,
V_57 -> V_37 + 0x10 ,
V_337 -> V_450 ,
V_337 -> V_451 ,
V_337 -> V_452 , V_337 -> V_453 ,
V_444 ) ;
if ( V_11 ) {
V_117 = V_375 ;
} else {
V_117 = V_311 ;
V_57 -> V_184 [ V_337 -> V_58 ] . V_297 = true ;
V_57 -> V_295 ++ ;
}
V_342:
F_112 ( V_2 , V_68 , V_57 , V_117 , V_444 ) ;
}
static void F_116 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_3 * V_4 , T_1 V_117 )
{
struct V_253 * V_254 = & V_4 -> V_140 ;
struct V_436 * V_437 ;
bool V_435 = false ;
T_3 V_245 ;
V_254 -> V_97 = ( T_1 * ) V_254 -> V_143 ;
if ( V_4 -> V_31 . V_32 . V_33 ==
V_35 )
V_435 = true ;
if ( ! V_435 )
V_245 = sizeof( * V_437 ) ;
else
V_245 = sizeof( struct V_282 ) ;
V_437 = F_82 ( V_2 , & V_254 -> V_97 , V_454 ,
V_245 ) ;
F_82 ( V_2 , & V_254 -> V_97 , V_251 ,
sizeof( struct V_288 ) ) ;
if ( ( V_117 == V_311 ) && ! V_435 ) {
T_3 V_183 = V_254 -> V_141 -> V_455 . V_60 ;
V_437 -> V_97 = F_117 ( V_4 -> V_184 [ V_183 ] . V_206 ,
V_456 ) ;
}
F_84 ( V_2 , V_68 , V_4 , V_245 , V_117 ) ;
}
static void F_118 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_3 * V_57 )
{
struct V_443 V_74 ;
struct V_253 * V_254 = & V_57 -> V_140 ;
T_1 V_117 = V_312 ;
union V_457 V_458 ;
struct V_459 * V_337 ;
int V_11 ;
memset ( & V_458 , 0 , sizeof( V_458 ) ) ;
V_458 . V_460 . V_461 = 1 ;
V_458 . V_460 . V_22 = V_57 -> V_56 ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_337 = & V_254 -> V_141 -> V_455 ;
if ( ! F_14 ( V_2 , V_57 , V_337 -> V_60 ) ||
! F_15 ( V_2 , V_57 , V_337 -> V_445 ) )
goto V_342;
V_74 . V_203 = V_57 -> V_184 [ V_337 -> V_60 ] . V_205 ;
V_74 . V_148 = V_57 -> V_148 ;
V_74 . V_447 = V_337 -> V_445 ;
V_74 . V_62 = V_337 -> V_448 ;
V_11 = F_119 ( V_2 ,
V_57 -> V_15 ,
V_57 -> V_184 [ V_337 -> V_60 ] . V_206 ,
& V_74 ,
V_57 -> V_37 + 0x10 ,
V_337 -> V_462 ,
V_337 -> V_463 , & V_458 ) ;
if ( V_11 ) {
V_117 = V_375 ;
} else {
V_117 = V_311 ;
V_57 -> V_184 [ V_337 -> V_60 ] . V_464 = true ;
}
V_342:
F_116 ( V_2 , V_68 , V_57 , V_117 ) ;
}
static int F_120 ( struct V_1 * V_2 ,
struct V_3 * V_57 ,
T_3 V_465 , T_1 V_59 , bool V_466 )
{
int V_11 = 0 ;
int V_183 ;
if ( V_465 + V_59 > F_121 ( V_57 -> V_184 ) )
return - V_12 ;
for ( V_183 = V_465 ; V_183 < V_465 + V_59 ; V_183 ++ ) {
if ( V_57 -> V_184 [ V_183 ] . V_297 ) {
V_11 = F_122 ( V_2 ,
V_57 -> V_184 [ V_183 ] .
V_185 , false ,
V_466 ) ;
if ( V_11 )
return V_11 ;
}
V_57 -> V_184 [ V_183 ] . V_297 = false ;
V_57 -> V_295 -- ;
}
return V_11 ;
}
static int F_123 ( struct V_1 * V_2 ,
struct V_3 * V_57 , T_3 V_467 , T_1 V_61 )
{
int V_11 = 0 ;
int V_183 ;
if ( V_467 + V_61 > F_121 ( V_57 -> V_184 ) )
return - V_12 ;
for ( V_183 = V_467 ; V_183 < V_467 + V_61 ; V_183 ++ ) {
if ( V_57 -> V_184 [ V_183 ] . V_464 ) {
V_11 = F_124 ( V_2 ,
V_57 -> V_184 [ V_183 ] .
V_205 ) ;
if ( V_11 )
return V_11 ;
}
V_57 -> V_184 [ V_183 ] . V_464 = false ;
}
return V_11 ;
}
static void F_125 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_3 * V_57 )
{
T_3 V_245 = sizeof( struct V_282 ) ;
struct V_253 * V_254 = & V_57 -> V_140 ;
T_1 V_117 = V_311 ;
struct V_468 * V_337 ;
int V_11 ;
V_337 = & V_254 -> V_141 -> V_469 ;
V_11 = F_120 ( V_2 , V_57 , V_337 -> V_58 ,
V_337 -> V_59 , V_337 -> V_466 ) ;
if ( V_11 )
V_117 = V_375 ;
F_89 ( V_2 , V_68 , V_57 , V_470 ,
V_245 , V_117 ) ;
}
static void F_126 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_3 * V_57 )
{
T_3 V_245 = sizeof( struct V_282 ) ;
struct V_253 * V_254 = & V_57 -> V_140 ;
T_1 V_117 = V_311 ;
struct V_471 * V_337 ;
int V_11 ;
V_337 = & V_254 -> V_141 -> V_472 ;
V_11 = F_123 ( V_2 , V_57 , V_337 -> V_60 , V_337 -> V_61 ) ;
if ( V_11 )
V_117 = V_375 ;
F_89 ( V_2 , V_68 , V_57 , V_473 ,
V_245 , V_117 ) ;
}
static void F_127 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_3 * V_57 )
{
T_3 V_245 = sizeof( struct V_282 ) ;
struct V_253 * V_254 = & V_57 -> V_140 ;
struct V_474 * V_337 ;
T_1 V_117 = V_311 ;
T_1 V_475 ;
T_1 V_476 ;
T_3 V_183 ;
int V_11 ;
T_1 V_63 ;
V_337 = & V_254 -> V_141 -> V_477 ;
V_476 = ! ! ( V_337 -> V_80 & V_478 ) ;
V_475 = ! ! ( V_337 -> V_80 & V_479 ) ;
for ( V_63 = 0 ; V_63 < V_337 -> V_59 ; V_63 ++ ) {
V_183 = V_337 -> V_58 + V_63 ;
if ( ! V_57 -> V_184 [ V_183 ] . V_297 ) {
F_6 ( V_2 , L_55 ,
V_183 ) ;
V_117 = V_375 ;
break;
}
V_11 = F_106 ( V_2 ,
V_57 -> V_184 [ V_183 ] . V_185 ,
1 ,
V_476 ,
V_475 ,
V_17 , NULL ) ;
if ( V_11 ) {
V_117 = V_375 ;
break;
}
}
F_89 ( V_2 , V_68 , V_57 , V_480 ,
V_245 , V_117 ) ;
}
void * F_128 ( struct V_1 * V_2 ,
void * V_481 , T_3 V_482 )
{
struct V_246 * V_437 = (struct V_246 * ) V_481 ;
int V_321 = 0 ;
do {
if ( ! V_437 -> V_245 ) {
F_6 ( V_2 , L_56 ) ;
return NULL ;
}
if ( V_437 -> type == V_482 ) {
F_7 ( V_2 , V_36 ,
L_57 ,
V_437 -> type , V_437 -> V_245 ) ;
return V_437 ;
}
V_321 += V_437 -> V_245 ;
V_437 = (struct V_246 * ) ( ( T_1 * ) V_437 + V_437 -> V_245 ) ;
if ( ( V_321 + V_437 -> V_245 ) > V_483 ) {
F_6 ( V_2 , L_58 ) ;
return NULL ;
}
} while ( V_437 -> type != V_251 );
return NULL ;
}
static void
F_129 ( struct V_1 * V_2 ,
struct V_378 * V_484 ,
struct V_253 * V_279 , T_3 * V_280 )
{
struct V_485 * V_486 ;
T_3 V_250 = V_264 ;
V_486 = (struct V_485 * )
F_128 ( V_2 , V_279 -> V_141 , V_250 ) ;
if ( ! V_486 )
return;
V_484 -> V_487 = V_486 -> V_488 ;
V_484 -> V_489 = V_486 -> V_490 ;
V_484 -> V_491 = V_486 -> V_492 ;
V_484 -> V_493 = V_486 -> V_494 ;
* V_280 |= 1 << V_263 ;
}
static void
F_130 ( struct V_1 * V_2 ,
struct V_378 * V_484 ,
struct V_3 * V_4 ,
struct V_253 * V_279 , T_3 * V_280 )
{
struct V_495 * V_496 ;
T_3 V_250 = V_266 ;
V_496 = (struct V_495 * )
F_128 ( V_2 , V_279 -> V_141 , V_250 ) ;
if ( ! V_496 )
return;
V_4 -> V_298 . V_410 = V_496 -> V_497 ;
if ( ! ( V_4 -> V_294 & F_64 ( V_397 ) ) ) {
V_484 -> V_409 = 1 ;
V_484 -> V_411 = V_496 -> V_497 ;
}
* V_280 |= 1 << V_265 ;
}
static void
F_131 ( struct V_1 * V_2 ,
struct V_378 * V_484 ,
struct V_253 * V_279 , T_3 * V_280 )
{
struct V_498 * V_499 ;
T_3 V_250 = V_268 ;
V_499 = (struct V_498 * )
F_128 ( V_2 , V_279 -> V_141 ,
V_250 ) ;
if ( ! V_499 )
return;
V_484 -> V_500 = 1 ;
V_484 -> V_501 = V_499 -> V_429 ;
* V_280 |= 1 << V_267 ;
}
static void
F_132 ( struct V_1 * V_2 ,
struct V_378 * V_484 ,
struct V_253 * V_279 , T_3 * V_280 )
{
struct V_502 * V_503 ;
T_3 V_250 = V_270 ;
V_503 = (struct V_502 * )
F_128 ( V_2 , V_279 -> V_141 , V_250 ) ;
if ( ! V_503 )
return;
V_484 -> V_504 = 1 ;
memcpy ( V_484 -> V_505 , V_503 -> V_505 ,
sizeof( unsigned long ) * V_506 ) ;
* V_280 |= 1 << V_269 ;
}
static void
F_133 ( struct V_1 * V_2 ,
struct V_378 * V_484 ,
struct V_253 * V_279 , T_3 * V_280 )
{
struct V_507 * V_508 = & V_484 -> V_509 ;
struct V_510 * V_511 ;
T_3 V_250 = V_272 ;
V_511 = (struct V_510 * )
F_128 ( V_2 , V_279 -> V_141 , V_250 ) ;
if ( ! V_511 )
return;
V_508 -> V_512 = V_511 -> V_513 ;
V_508 -> V_514 = V_511 -> V_514 ;
V_508 -> V_515 = V_511 -> V_516 ;
V_508 -> V_517 = V_511 -> V_517 ;
* V_280 |= 1 << V_271 ;
}
static void
F_134 ( struct V_1 * V_2 ,
struct V_378 * V_484 ,
struct V_253 * V_279 , T_3 * V_280 )
{
struct V_518 * V_519 ;
T_3 V_250 = V_276 ;
V_519 = (struct V_518 * )
F_128 ( V_2 , V_279 -> V_141 ,
V_250 ) ;
if ( ! V_519 )
return;
V_484 -> V_520 = V_519 -> V_520 ;
V_484 -> V_521 =
V_519 -> V_521 ;
* V_280 |= 1 << V_275 ;
}
static void
F_135 ( struct V_1 * V_2 ,
struct V_3 * V_57 ,
struct V_378 * V_484 ,
struct V_522 * V_523 ,
struct V_253 * V_279 , T_3 * V_280 )
{
struct V_524 * V_525 ;
T_3 V_250 = V_274 ;
T_3 V_63 , V_526 , V_527 ;
T_3 V_528 ;
V_525 = (struct V_524 * )
F_128 ( V_2 , V_279 -> V_141 , V_250 ) ;
if ( ! V_525 ) {
V_484 -> V_529 = NULL ;
return;
}
memset ( V_523 , 0 , sizeof( struct V_522 ) ) ;
V_523 -> V_530 = ! ! ( V_525 -> V_531 &
V_532 ) ;
V_523 -> V_533 = ! ! ( V_525 -> V_531 &
V_534 ) ;
V_523 -> V_535 = ! ! ( V_525 -> V_531 &
V_536 ) ;
V_523 -> V_537 = ! ! ( V_525 -> V_531 &
V_538 ) ;
V_523 -> V_539 = V_525 -> V_539 ;
V_523 -> V_540 = V_57 -> V_56 + 1 ;
V_523 -> V_541 = V_525 -> V_541 ;
V_523 -> V_542 = V_525 -> V_542 ;
memcpy ( V_523 -> V_543 , V_525 -> V_543 ,
sizeof( V_523 -> V_543 ) ) ;
memcpy ( V_523 -> V_544 , V_525 -> V_544 , sizeof( V_523 -> V_544 ) ) ;
V_528 = F_72 ( T_3 , F_121 ( V_523 -> V_543 ) ,
( 1 << V_525 -> V_542 ) ) ;
V_527 = F_121 ( V_57 -> V_184 ) ;
for ( V_63 = 0 ; V_63 < V_528 ; V_63 ++ ) {
T_3 V_545 = V_57 -> V_184 [ 0 ] . V_185 ;
V_526 = V_523 -> V_543 [ V_63 ] ;
if ( V_526 >= V_527 )
F_6 ( V_2 ,
L_59 ,
V_63 , V_526 ) ;
else if ( ! V_57 -> V_184 [ V_526 ] . V_297 )
F_6 ( V_2 ,
L_60 ,
V_63 , V_526 ) ;
else
V_545 = V_57 -> V_184 [ V_526 ] . V_185 ;
V_523 -> V_543 [ V_63 ] = V_545 ;
}
V_484 -> V_529 = V_523 ;
* V_280 |= 1 << V_273 ;
}
static void
F_136 ( struct V_1 * V_2 ,
struct V_3 * V_57 ,
struct V_378 * V_484 ,
struct V_546 * V_547 ,
struct V_253 * V_279 , T_3 * V_280 )
{
struct V_548 * V_549 ;
T_3 V_250 = V_278 ;
V_549 = (struct V_548 * )
F_128 ( V_2 , V_279 -> V_141 , V_250 ) ;
if ( ! V_549 ) {
V_484 -> V_550 = NULL ;
return;
}
memset ( V_547 , 0 , sizeof( struct V_546 ) ) ;
V_547 -> V_551 =
! ! ( V_549 -> V_552 & V_553 ) ;
V_547 -> V_554 =
! ! ( V_549 -> V_552 &
V_555 ) ;
V_547 -> V_556 =
! ! ( V_549 -> V_557 & V_558 ) ;
V_547 -> V_559 =
! ! ( V_549 -> V_557 & V_560 ) ;
V_547 -> V_561 =
! ! ( V_549 -> V_557 & V_562 ) ;
V_547 -> V_563 =
! ! ( V_549 -> V_557 & V_564 ) ;
V_547 -> V_565 =
! ! ( V_549 -> V_557 & V_566 ) ;
V_547 -> V_567 = V_549 -> V_567 ;
V_547 -> V_568 = V_549 -> V_568 ;
V_547 -> V_569 = V_549 -> V_569 ;
V_547 -> V_570 = V_549 -> V_570 ;
V_547 -> V_431 = V_549 -> V_431 ;
V_484 -> V_550 = V_547 ;
* V_280 |= 1 << V_277 ;
}
static void F_137 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_3 * V_57 )
{
struct V_378 V_74 ;
struct V_253 * V_254 = & V_57 -> V_140 ;
struct V_546 V_550 ;
struct V_522 V_529 ;
T_1 V_117 = V_311 ;
T_3 V_280 = 0 ;
T_3 V_245 ;
int V_11 ;
if ( ! V_57 -> V_293 ) {
F_7 ( V_2 ,
V_36 ,
L_61 ,
V_57 -> V_37 ) ;
V_117 = V_375 ;
goto V_342;
}
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_15 = V_57 -> V_15 ;
V_74 . V_148 = V_57 -> V_148 ;
V_74 . V_529 = NULL ;
F_129 ( V_2 , & V_74 , V_254 , & V_280 ) ;
F_130 ( V_2 , & V_74 , V_57 , V_254 , & V_280 ) ;
F_131 ( V_2 , & V_74 , V_254 , & V_280 ) ;
F_132 ( V_2 , & V_74 , V_254 , & V_280 ) ;
F_133 ( V_2 , & V_74 , V_254 , & V_280 ) ;
F_135 ( V_2 , V_57 , & V_74 , & V_529 ,
V_254 , & V_280 ) ;
F_134 ( V_2 , & V_74 , V_254 , & V_280 ) ;
F_136 ( V_2 , V_57 , & V_74 ,
& V_550 , V_254 , & V_280 ) ;
if ( ! V_280 ) {
F_6 ( V_2 ,
L_62 ) ;
V_117 = V_287 ;
goto V_342;
}
V_11 = F_100 ( V_2 , & V_74 , V_17 , NULL ) ;
if ( V_11 )
V_117 = V_375 ;
V_342:
V_245 = F_88 ( V_2 , V_57 , V_254 , V_117 ,
V_280 , V_280 ) ;
F_84 ( V_2 , V_68 , V_57 , V_245 , V_117 ) ;
}
static int F_138 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_383 * V_571 )
{
int V_63 ;
if ( V_571 -> V_388 == V_572 ) {
for ( V_63 = 0 ; V_63 < V_152 + 1 ; V_63 ++ )
if ( V_4 -> V_298 . V_390 [ V_63 ] . V_391 &&
V_4 -> V_298 . V_390 [ V_63 ] . V_394 ==
V_571 -> V_393 ) {
V_4 -> V_298 . V_390 [ V_63 ] . V_391 = false ;
break;
}
if ( V_63 == V_152 + 1 ) {
F_7 ( V_2 ,
V_36 ,
L_63 ,
V_4 -> V_56 ) ;
return - V_12 ;
}
} else if ( V_571 -> V_388 == V_400 ||
V_571 -> V_388 == V_404 ) {
for ( V_63 = 0 ; V_63 < V_152 + 1 ; V_63 ++ )
V_4 -> V_298 . V_390 [ V_63 ] . V_391 = false ;
}
if ( V_4 -> V_76 . V_77 -> V_421 & F_64 ( V_397 ) )
return 0 ;
if ( V_571 -> V_388 == V_389 ||
V_571 -> V_388 == V_400 ) {
for ( V_63 = 0 ; V_63 < V_152 + 1 ; V_63 ++ ) {
if ( V_4 -> V_298 . V_390 [ V_63 ] . V_391 )
continue;
V_4 -> V_298 . V_390 [ V_63 ] . V_391 = true ;
V_4 -> V_298 . V_390 [ V_63 ] . V_394 = V_571 -> V_393 ;
break;
}
if ( V_63 == V_152 + 1 ) {
F_7 ( V_2 ,
V_36 ,
L_64 ,
V_4 -> V_56 ,
V_152 + 1 ) ;
return - V_12 ;
}
}
return 0 ;
}
static int F_139 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_383 * V_571 )
{
int V_63 ;
if ( V_4 -> V_76 . V_77 -> V_421 & F_64 ( V_398 ) )
return 0 ;
if ( V_571 -> V_388 == V_572 ) {
for ( V_63 = 0 ; V_63 < V_150 ; V_63 ++ ) {
if ( F_140 ( V_4 -> V_298 . V_573 [ V_63 ] ,
V_571 -> V_291 ) ) {
memset ( V_4 -> V_298 . V_573 [ V_63 ] , 0 ,
V_292 ) ;
break;
}
}
if ( V_63 == V_150 ) {
F_7 ( V_2 , V_36 ,
L_65 ) ;
return - V_12 ;
}
} else if ( V_571 -> V_388 == V_400 ||
V_571 -> V_388 == V_404 ) {
for ( V_63 = 0 ; V_63 < V_150 ; V_63 ++ )
memset ( V_4 -> V_298 . V_573 [ V_63 ] , 0 , V_292 ) ;
}
if ( V_571 -> V_388 != V_389 &&
V_571 -> V_388 != V_400 )
return 0 ;
for ( V_63 = 0 ; V_63 < V_150 ; V_63 ++ ) {
if ( F_141 ( V_4 -> V_298 . V_573 [ V_63 ] ) ) {
F_105 ( V_4 -> V_298 . V_573 [ V_63 ] ,
V_571 -> V_291 ) ;
F_7 ( V_2 , V_36 ,
L_66 , V_63 ) ;
break;
}
}
if ( V_63 == V_150 ) {
F_7 ( V_2 , V_36 , L_67 ) ;
return - V_12 ;
}
return 0 ;
}
static int
F_142 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_383 * V_571 )
{
int V_11 = 0 ;
if ( V_571 -> type == V_399 ) {
V_11 = F_139 ( V_2 , V_4 , V_571 ) ;
if ( V_11 )
return V_11 ;
}
if ( V_571 -> type == V_392 )
V_11 = F_138 ( V_2 , V_4 , V_571 ) ;
return V_11 ;
}
static int F_143 ( struct V_1 * V_574 ,
int V_66 , struct V_383 * V_74 )
{
struct V_290 * V_57 ;
V_57 = F_90 ( V_574 , V_66 , true ) ;
if ( ! V_57 )
return - V_12 ;
if ( V_74 -> type == V_399 ||
V_74 -> type == V_575 )
F_105 ( V_57 -> V_291 , V_74 -> V_291 ) ;
return 0 ;
}
static void F_144 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_3 * V_57 )
{
struct V_69 * V_70 = V_57 -> V_76 . V_77 ;
struct V_253 * V_254 = & V_57 -> V_140 ;
struct V_576 * V_337 ;
T_1 V_117 = V_311 ;
struct V_383 V_74 ;
int V_11 ;
memset ( & V_74 , 0 , sizeof( struct V_383 ) ) ;
V_337 = & V_254 -> V_141 -> V_577 ;
V_74 . V_388 = (enum V_578 ) V_337 -> V_388 ;
V_74 . type = (enum V_579 ) V_337 -> type ;
V_74 . V_385 = 1 ;
V_74 . V_386 = 1 ;
V_74 . V_580 = V_57 -> V_148 ;
V_74 . V_387 = V_57 -> V_148 ;
memcpy ( V_74 . V_291 , V_337 -> V_291 , V_292 ) ;
V_74 . V_393 = V_337 -> V_393 ;
F_7 ( V_2 ,
V_36 ,
L_68 ,
V_57 -> V_37 , V_74 . V_388 , V_74 . type ,
V_74 . V_385 ? L_69 : L_70 ,
V_74 . V_386 ? L_71 : L_70 ,
V_74 . V_387 ,
V_74 . V_291 [ 0 ] , V_74 . V_291 [ 1 ] ,
V_74 . V_291 [ 2 ] , V_74 . V_291 [ 3 ] ,
V_74 . V_291 [ 4 ] , V_74 . V_291 [ 5 ] , V_74 . V_393 ) ;
if ( ! V_57 -> V_293 ) {
F_7 ( V_2 ,
V_36 ,
L_72 ,
V_57 -> V_37 ) ;
V_117 = V_375 ;
goto V_342;
}
if ( F_142 ( V_2 , V_57 , & V_74 ) ) {
V_117 = V_375 ;
goto V_342;
}
if ( ( V_70 -> V_421 & F_64 ( V_397 ) ) &&
( V_74 . type == V_392 ||
V_74 . type == V_575 ) ) {
if ( V_74 . V_388 == V_389 ||
V_74 . V_388 == V_400 )
V_117 = V_581 ;
goto V_342;
}
if ( ( V_70 -> V_421 & F_64 ( V_398 ) ) &&
( V_74 . type == V_399 ||
V_74 . type == V_575 ) ) {
if ( ! F_140 ( V_70 -> V_291 , V_74 . V_291 ) ||
( V_74 . V_388 != V_389 &&
V_74 . V_388 != V_400 ) )
V_117 = V_581 ;
goto V_342;
}
V_11 = F_143 ( V_2 , V_57 -> V_56 , & V_74 ) ;
if ( V_11 ) {
V_117 = V_375 ;
goto V_342;
}
V_11 = F_102 ( V_2 , V_57 -> V_15 , & V_74 ,
V_395 , NULL ) ;
if ( V_11 )
V_117 = V_375 ;
V_342:
F_89 ( V_2 , V_68 , V_57 , V_582 ,
sizeof( struct V_282 ) , V_117 ) ;
}
static void F_145 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_3 * V_57 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_57 -> V_64 ; V_63 ++ )
F_55 ( V_2 , V_68 ,
V_57 -> V_65 [ V_63 ] ,
V_57 -> V_15 , false ) ;
F_89 ( V_2 , V_68 , V_57 , V_583 ,
sizeof( struct V_282 ) ,
V_311 ) ;
}
static void F_146 ( struct V_1 * V_2 ,
struct V_67 * V_68 , struct V_3 * V_57 )
{
T_3 V_245 = sizeof( struct V_282 ) ;
T_1 V_117 = V_311 ;
F_56 ( V_2 , V_68 , V_57 , 0 ) ;
F_62 ( V_2 , V_68 , V_57 , 0 ) ;
F_89 ( V_2 , V_68 , V_57 , V_584 ,
V_245 , V_117 ) ;
}
static void F_147 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_3 * V_4 )
{
T_3 V_245 = sizeof( struct V_282 ) ;
T_1 V_117 = V_311 ;
int V_11 = 0 ;
F_92 ( V_2 , V_4 ) ;
if ( V_4 -> V_145 != V_146 && V_4 -> V_145 != V_180 ) {
V_11 = F_9 ( V_2 , V_4 -> V_23 ,
V_4 -> V_15 ) ;
if ( V_11 ) {
F_12 ( V_2 , L_73 ,
V_11 ) ;
V_117 = V_375 ;
}
V_4 -> V_145 = V_146 ;
}
F_89 ( V_2 , V_68 , V_4 , V_585 ,
V_245 , V_117 ) ;
}
static int
F_148 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_67 * V_68 )
{
int V_586 ;
T_2 V_113 ;
F_54 ( V_2 , V_68 , ( T_3 ) V_4 -> V_23 ) ;
for ( V_586 = 0 ; V_586 < 50 ; V_586 ++ ) {
V_113 = F_26 ( V_2 , V_68 , V_587 ) ;
if ( ! V_113 )
break;
F_149 ( 20 ) ;
}
F_54 ( V_2 , V_68 , ( T_3 ) V_2 -> V_25 . V_23 ) ;
if ( V_586 == 50 ) {
F_12 ( V_2 ,
L_74 ,
V_4 -> V_37 , V_113 ) ;
return - V_588 ;
}
return 0 ;
}
static int
F_150 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_67 * V_68 )
{
T_2 V_589 [ V_590 ] , V_591 [ V_590 ] ;
int V_63 , V_586 ;
for ( V_63 = 0 ; V_63 < V_590 ; V_63 ++ ) {
T_2 V_592 ;
V_589 [ V_63 ] = F_26 ( V_2 , V_68 ,
V_593 +
V_63 * 0x40 ) ;
V_592 = F_26 ( V_2 , V_68 ,
V_594 +
V_63 * 0x40 ) ;
V_591 [ V_63 ] = V_592 - V_589 [ V_63 ] ;
}
V_63 = 0 ;
for ( V_586 = 0 ; V_586 < 50 ; V_586 ++ ) {
for (; V_63 < V_590 ; V_63 ++ ) {
T_2 V_595 ;
V_595 = F_26 ( V_2 , V_68 ,
V_593 +
V_63 * 0x40 ) ;
if ( V_591 [ V_63 ] > V_595 - V_589 [ V_63 ] )
break;
}
if ( V_63 == V_590 )
break;
F_149 ( 20 ) ;
}
if ( V_586 == 50 ) {
F_12 ( V_2 , L_75 ,
V_4 -> V_37 , V_63 ) ;
return - V_588 ;
}
return 0 ;
}
static int F_151 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_67 * V_68 )
{
int V_11 ;
V_11 = F_148 ( V_2 , V_4 , V_68 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_150 ( V_2 , V_4 , V_68 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int
F_152 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
T_3 V_48 , T_2 * V_596 )
{
struct V_3 * V_4 ;
int V_11 = 0 ;
V_4 = F_11 ( V_2 , V_48 , false ) ;
if ( ! V_4 )
return 0 ;
if ( V_2 -> V_50 -> V_597 [ V_48 / 64 ] &
( 1ULL << ( V_48 % 64 ) ) ) {
T_3 V_66 = V_4 -> V_37 ;
F_7 ( V_2 , V_36 ,
L_76 , V_66 ) ;
F_92 ( V_2 , V_4 ) ;
if ( ! V_4 -> V_55 )
goto V_598;
V_11 = F_151 ( V_2 , V_4 , V_68 ) ;
if ( V_11 )
goto V_598;
V_11 = F_153 ( V_2 , V_68 , V_66 , true ) ;
if ( V_11 ) {
F_12 ( V_2 , L_77 , V_66 ) ;
return V_11 ;
}
V_4 -> V_145 = V_146 ;
V_11 = F_57 ( V_2 , V_68 , V_4 ) ;
if ( V_11 ) {
F_12 ( V_2 , L_78 ,
V_66 ) ;
return V_11 ;
}
V_598:
if ( V_4 -> V_145 == V_599 )
V_4 -> V_145 = V_146 ;
V_596 [ V_66 / 32 ] |= F_64 ( ( V_66 % 32 ) ) ;
V_2 -> V_50 -> V_597 [ V_48 / 64 ] &=
~ ( 1ULL << ( V_48 % 64 ) ) ;
V_2 -> V_50 -> V_600 [ V_48 / 64 ] &=
~ ( 1ULL << ( V_48 % 64 ) ) ;
}
return V_11 ;
}
static int
F_154 ( struct V_1 * V_2 , struct V_67 * V_68 )
{
T_2 V_596 [ V_601 / 32 ] ;
int V_11 = 0 ;
T_3 V_63 ;
memset ( V_596 , 0 , sizeof( T_2 ) * ( V_601 / 32 ) ) ;
F_149 ( 100 ) ;
for ( V_63 = 0 ; V_63 < V_2 -> V_51 -> V_52 -> V_53 ; V_63 ++ )
F_152 ( V_2 , V_68 , V_63 , V_596 ) ;
V_11 = F_155 ( V_2 , V_68 , V_596 ) ;
return V_11 ;
}
int F_156 ( struct V_1 * V_2 , T_2 * V_602 )
{
T_3 V_63 , V_603 = 0 ;
F_7 ( V_2 , V_36 , L_79 ) ;
for ( V_63 = 0 ; V_63 < ( V_601 / 32 ) ; V_63 ++ )
F_7 ( V_2 , V_36 ,
L_80 ,
V_63 * 32 , ( V_63 + 1 ) * 32 - 1 , V_602 [ V_63 ] ) ;
if ( ! V_2 -> V_51 -> V_52 ) {
F_6 ( V_2 , L_81 ) ;
return 0 ;
}
for ( V_63 = 0 ; V_63 < V_2 -> V_51 -> V_52 -> V_53 ; V_63 ++ ) {
struct V_3 * V_4 ;
T_1 V_66 ;
V_4 = F_11 ( V_2 , V_63 , false ) ;
if ( ! V_4 )
continue;
V_66 = V_4 -> V_37 ;
if ( F_64 ( ( V_66 % 32 ) ) & V_602 [ V_66 / 32 ] ) {
V_160 * V_604 = V_2 -> V_50 -> V_597 ;
T_3 V_48 = V_4 -> V_56 ;
F_7 ( V_2 , V_36 ,
L_82 ,
V_66 , V_48 ) ;
V_4 -> V_145 = V_599 ;
V_604 [ V_48 / 64 ] |= 1ULL << ( V_48 % 64 ) ;
V_603 = 1 ;
}
}
return V_603 ;
}
static void F_157 ( struct V_1 * V_2 ,
T_3 V_66 ,
struct V_207 * V_571 ,
struct V_208 * V_605 ,
struct V_209 * V_210 )
{
struct V_3 * V_4 = F_11 ( V_2 ,
V_66 ,
false ) ;
struct V_69 * V_70 ;
if ( ! V_4 )
return;
V_70 = V_4 -> V_76 . V_77 ;
if ( V_571 )
F_158 ( V_2 , V_571 , V_70 ) ;
if ( V_605 )
F_159 ( V_2 , V_605 , V_70 ) ;
if ( V_210 )
F_160 ( V_2 , V_210 , V_70 ) ;
}
static void F_161 ( struct V_1 * V_2 ,
struct V_67 * V_68 , int V_66 )
{
struct V_253 * V_254 ;
struct V_3 * V_4 ;
V_4 = F_11 ( V_2 , ( T_3 ) V_66 , true ) ;
if ( ! V_4 )
return;
V_254 = & V_4 -> V_140 ;
F_7 ( V_2 , V_36 ,
L_83 , V_4 -> V_37 ) ;
V_254 -> V_258 = V_254 -> V_141 -> V_258 ;
if ( F_81 ( V_254 -> V_258 . V_247 . type ) ) {
switch ( V_254 -> V_258 . V_247 . type ) {
case V_377 :
F_96 ( V_2 , V_68 , V_4 ) ;
break;
case V_433 :
F_107 ( V_2 , V_68 , V_4 ) ;
break;
case V_434 :
F_110 ( V_2 , V_68 , V_4 ) ;
break;
case V_439 :
F_113 ( V_2 , V_68 , V_4 ) ;
break;
case V_454 :
F_118 ( V_2 , V_68 , V_4 ) ;
break;
case V_470 :
F_125 ( V_2 , V_68 , V_4 ) ;
break;
case V_473 :
F_126 ( V_2 , V_68 , V_4 ) ;
break;
case V_480 :
F_127 ( V_2 , V_68 , V_4 ) ;
break;
case V_285 :
F_137 ( V_2 , V_68 , V_4 ) ;
break;
case V_582 :
F_144 ( V_2 , V_68 , V_4 ) ;
break;
case V_584 :
F_146 ( V_2 , V_68 , V_4 ) ;
break;
case V_583 :
F_145 ( V_2 , V_68 , V_4 ) ;
break;
case V_585 :
F_147 ( V_2 , V_68 , V_4 ) ;
break;
}
} else {
F_6 ( V_2 ,
L_84 ,
V_4 -> V_37 ,
V_254 -> V_258 . V_247 . type ,
V_254 -> V_258 . V_247 . V_245 ,
V_254 -> V_258 . V_606 , V_254 -> V_258 . V_259 ) ;
if ( V_4 -> V_31 . V_258 . V_259 &&
( V_254 -> V_258 . V_259 ==
V_4 -> V_31 . V_258 . V_259 ) ) {
F_89 ( V_2 , V_68 , V_4 ,
V_254 -> V_258 . V_247 . type ,
sizeof( struct V_282 ) ,
V_287 ) ;
} else {
F_7 ( V_2 ,
V_36 ,
L_85 ,
V_4 -> V_37 ) ;
}
}
}
static void F_162 ( struct V_1 * V_2 , T_1 V_66 )
{
V_160 V_607 = 1ULL << ( V_66 % 64 ) ;
V_2 -> V_50 -> V_600 [ V_66 / 64 ] |= V_607 ;
}
static void F_163 ( struct V_1 * V_2 ,
V_160 * V_396 )
{
V_160 * V_608 = V_2 -> V_50 -> V_600 ;
memcpy ( V_396 , V_608 , sizeof( V_160 ) * V_609 ) ;
memset ( V_608 , 0 , sizeof( V_160 ) * V_609 ) ;
}
static int F_164 ( struct V_1 * V_2 ,
T_3 V_167 , struct V_610 * V_611 )
{
T_1 V_612 = ( T_1 ) V_2 -> V_51 -> V_52 -> V_147 ;
struct V_3 * V_4 ;
if ( ! F_47 ( V_2 , ( int ) V_167 - V_612 ) ) {
F_7 ( V_2 ,
V_36 ,
L_86 ,
V_167 ) ;
return 0 ;
}
V_4 = & V_2 -> V_50 -> V_54 [ ( T_1 ) V_167 - V_612 ] ;
V_4 -> V_140 . V_613 = ( ( ( V_160 ) V_611 -> V_614 ) << 32 ) | V_611 -> V_615 ;
F_162 ( V_2 , V_4 -> V_56 ) ;
F_165 ( V_2 , V_616 ) ;
return 0 ;
}
int F_166 ( struct V_1 * V_2 ,
T_1 V_388 , T_5 V_617 , union V_618 * V_619 )
{
switch ( V_388 ) {
case V_620 :
return F_164 ( V_2 , F_167 ( V_617 ) ,
& V_619 -> V_621 . V_622 ) ;
default:
F_97 ( V_2 -> V_51 , L_87 ,
V_388 ) ;
return - V_12 ;
}
}
T_3 F_168 ( struct V_1 * V_2 , T_3 V_48 )
{
struct V_85 * V_122 = V_2 -> V_51 -> V_52 ;
T_3 V_63 ;
if ( ! V_122 )
goto V_342;
for ( V_63 = V_48 ; V_63 < V_122 -> V_53 ; V_63 ++ )
if ( F_10 ( V_2 , V_48 , true ) )
return V_63 ;
V_342:
return V_623 ;
}
static int F_169 ( struct V_1 * V_2 , struct V_67 * V_624 ,
int V_66 )
{
struct V_73 V_74 ;
struct V_3 * V_289 ;
V_289 = F_11 ( V_2 , ( T_3 ) V_66 , true ) ;
if ( ! V_289 )
return - V_12 ;
memset ( & V_74 , 0 , sizeof( struct V_73 ) ) ;
V_74 . V_80 = V_625 | V_626 ;
V_74 . V_627 = V_289 -> V_37 ;
if ( F_18 ( V_2 , V_624 ,
V_289 -> V_140 . V_613 ,
V_289 -> V_140 . V_142 ,
sizeof( union V_130 ) / 4 , & V_74 ) ) {
F_7 ( V_2 , V_36 ,
L_88 , V_66 ) ;
return - V_628 ;
}
return 0 ;
}
static void F_170 ( struct V_1 * V_2 ,
T_1 * V_291 , int V_66 )
{
struct V_3 * V_289 ;
V_160 V_629 ;
V_289 = F_11 ( V_2 , ( T_3 ) V_66 , true ) ;
if ( ! V_289 ) {
F_6 ( V_2 -> V_51 ,
L_89 , V_66 ) ;
return;
}
V_629 = 1 << V_398 ;
memcpy ( V_289 -> V_76 . V_77 -> V_291 , V_291 , V_292 ) ;
V_289 -> V_76 . V_77 -> V_421 |= V_629 ;
V_289 -> V_76 . V_77 -> V_421 &= ~ F_64 ( V_630 ) ;
F_104 ( V_2 , V_289 , V_629 ) ;
}
static void F_171 ( struct V_1 * V_2 ,
T_3 V_403 , int V_66 )
{
struct V_3 * V_289 ;
V_160 V_629 ;
V_289 = F_11 ( V_2 , ( T_3 ) V_66 , true ) ;
if ( ! V_289 ) {
F_6 ( V_2 -> V_51 ,
L_89 , V_66 ) ;
return;
}
V_629 = 1 << V_397 ;
V_289 -> V_76 . V_77 -> V_403 = V_403 ;
if ( V_403 )
V_289 -> V_76 . V_77 -> V_421 |= V_629 ;
else
V_289 -> V_76 . V_77 -> V_421 &= ~ V_629 ;
F_104 ( V_2 , V_289 , V_629 ) ;
}
static bool F_172 ( struct V_1 * V_2 , int V_66 )
{
struct V_3 * V_241 ;
V_241 = F_11 ( V_2 , ( T_3 ) V_66 , true ) ;
if ( ! V_241 )
return false ;
return ! ! V_241 -> V_293 ;
}
static bool F_173 ( struct V_1 * V_2 , int V_66 )
{
struct V_3 * V_241 ;
V_241 = F_11 ( V_2 , ( T_3 ) V_66 , true ) ;
if ( ! V_241 )
return true ;
return V_241 -> V_145 == V_146 ;
}
static bool F_174 ( struct V_1 * V_2 , int V_66 )
{
struct V_3 * V_289 ;
V_289 = F_11 ( V_2 , ( T_3 ) V_66 , true ) ;
if ( ! V_289 )
return false ;
return V_289 -> V_379 ;
}
static int F_175 ( struct V_1 * V_2 , int V_66 , bool V_113 )
{
struct V_3 * V_57 ;
int V_11 = - V_12 ;
if ( ! F_47 ( V_2 , V_66 ) ) {
F_6 ( V_2 ,
L_90 ) ;
goto V_342;
}
V_57 = F_11 ( V_2 , ( T_3 ) V_66 , true ) ;
if ( ! V_57 )
goto V_342;
if ( ! F_172 ( V_2 , V_66 ) ) {
V_57 -> V_382 = V_113 ;
V_11 = 0 ;
goto V_342;
}
V_11 = F_99 ( V_2 , V_57 , V_113 ) ;
V_342:
return V_11 ;
}
static T_1 * F_176 ( struct V_1 * V_2 ,
T_3 V_48 )
{
struct V_3 * V_4 ;
V_4 = F_11 ( V_2 , V_48 , true ) ;
if ( ! V_4 || ! V_4 -> V_76 . V_77 )
return NULL ;
if ( ! ( V_4 -> V_76 . V_77 -> V_421 & F_64 ( V_398 ) ) )
return NULL ;
return V_4 -> V_76 . V_77 -> V_291 ;
}
static T_3
F_177 ( struct V_1 * V_2 , T_3 V_48 )
{
struct V_3 * V_4 ;
V_4 = F_11 ( V_2 , V_48 , true ) ;
if ( ! V_4 || ! V_4 -> V_76 . V_77 )
return 0 ;
if ( ! ( V_4 -> V_76 . V_77 -> V_421 & F_64 ( V_397 ) ) )
return 0 ;
return V_4 -> V_76 . V_77 -> V_403 ;
}
static int F_178 ( struct V_1 * V_2 ,
struct V_67 * V_68 , int V_66 , int V_113 )
{
struct V_3 * V_57 ;
T_1 V_631 = 0 ;
int V_11 ;
V_57 = F_11 ( V_2 , ( T_3 ) V_66 , true ) ;
if ( ! V_57 )
return - V_12 ;
V_11 = F_179 ( V_2 , V_57 -> V_148 , & V_631 ) ;
if ( V_11 )
return V_11 ;
return F_180 ( V_2 , V_68 , V_631 , ( T_2 ) V_113 ) ;
}
static int
F_181 ( struct V_84 * V_51 , int V_66 , T_2 V_632 )
{
struct V_3 * V_57 ;
T_1 V_148 ;
int V_63 ;
F_50 (cdev, i) {
struct V_1 * V_2 = & V_51 -> V_166 [ V_63 ] ;
if ( ! F_47 ( V_2 , V_66 ) ) {
F_6 ( V_2 ,
L_91 ) ;
return - V_12 ;
}
}
V_57 = F_11 ( F_182 ( V_51 ) , ( T_3 ) V_66 , true ) ;
V_148 = V_57 -> V_148 ;
return F_183 ( V_51 , V_148 , V_632 ) ;
}
static int F_184 ( struct V_1 * V_2 , int V_66 )
{
struct V_633 * V_634 ;
struct V_3 * V_289 ;
V_289 = F_11 ( V_2 , ( T_3 ) V_66 , true ) ;
if ( ! V_289 )
return 0 ;
V_634 = & V_2 -> V_635 . V_636 [ V_289 -> V_148 ] ;
if ( V_634 -> V_637 )
return V_634 -> V_638 ;
else
return 0 ;
}
void F_165 ( struct V_1 * V_574 , enum V_639 V_262 )
{
F_185 () ;
F_186 ( V_262 , & V_574 -> V_640 ) ;
F_187 () ;
F_7 ( V_574 , V_36 , L_92 , V_262 ) ;
F_188 ( V_574 -> V_641 , & V_574 -> V_642 , 0 ) ;
}
void F_189 ( struct V_84 * V_51 )
{
int V_63 ;
F_50 (cdev, i)
F_188 ( V_51 -> V_166 [ V_63 ] . V_641 ,
& V_51 -> V_166 [ V_63 ] . V_642 , 0 ) ;
}
int F_190 ( struct V_84 * V_51 , bool V_643 )
{
int V_63 , V_644 ;
F_50 (cdev, i)
if ( V_51 -> V_166 [ V_63 ] . V_641 )
F_191 ( V_51 -> V_166 [ V_63 ] . V_641 ) ;
F_51 ( V_51 , true ) ;
if ( V_51 -> V_52 && V_51 -> V_52 -> V_95 && V_643 )
F_192 ( V_51 -> V_88 ) ;
F_50 (cdev, i) {
struct V_1 * V_574 = & V_51 -> V_166 [ V_63 ] ;
struct V_67 * V_624 = F_193 ( V_574 ) ;
if ( ! V_624 ) {
F_12 ( V_574 , L_93 ) ;
return - V_588 ;
}
F_194 ( V_574 , V_624 ) ;
F_195 (hwfn, j) {
int V_645 ;
if ( ! F_10 ( V_574 , V_644 , true ) )
continue;
for ( V_645 = 0 ; V_645 < 100 ; V_645 ++ ) {
if ( ! F_173 ( V_574 , V_644 ) )
F_149 ( 20 ) ;
else
break;
}
if ( V_645 < 100 )
F_77 ( & V_51 -> V_166 [ V_63 ] ,
V_624 , V_644 ) ;
else
F_12 ( V_574 ,
L_94 ) ;
}
F_196 ( V_574 , V_624 ) ;
}
F_51 ( V_51 , false ) ;
return 0 ;
}
static int F_197 ( struct V_84 * V_51 , int V_646 )
{
struct V_647 V_648 ;
int V_63 , V_644 , V_11 ;
if ( V_646 >= F_74 ( & V_51 -> V_166 [ 0 ] , V_649 ) ) {
F_6 ( V_51 , L_95 ,
F_74 ( & V_51 -> V_166 [ 0 ] , V_649 ) - 1 ) ;
return - V_12 ;
}
F_50 (cdev, j) {
struct V_1 * V_574 = & V_51 -> V_166 [ V_644 ] ;
struct V_67 * V_624 = F_193 ( V_574 ) ;
int V_64 = 0 , V_650 = 16 ;
if ( ! V_624 ) {
F_12 ( V_574 , L_93 ) ;
V_11 = - V_588 ;
goto V_651;
}
if ( F_198 ( V_574 ) )
V_650 = V_164 / V_574 -> V_652 ;
memset ( & V_648 , 0 , sizeof( V_648 ) ) ;
F_199 ( V_574 , & V_648 ) ;
V_64 = F_72 ( int , V_648 . V_653 , V_650 ) ;
for ( V_63 = 0 ; V_63 < V_646 ; V_63 ++ ) {
if ( ! F_10 ( V_574 , V_63 , false ) )
continue;
V_11 = F_70 ( V_574 ,
V_624 , V_63 , V_64 / V_646 ) ;
if ( V_11 ) {
F_12 ( V_51 , L_96 , V_63 ) ;
F_196 ( V_574 , V_624 ) ;
goto V_651;
}
}
F_196 ( V_574 , V_624 ) ;
}
V_11 = F_200 ( V_51 -> V_88 , V_646 ) ;
if ( V_11 ) {
F_12 ( V_51 , L_97 , V_11 ) ;
goto V_651;
}
return V_646 ;
V_651:
F_190 ( V_51 , false ) ;
return V_11 ;
}
static int F_201 ( struct V_84 * V_51 , int V_654 )
{
if ( ! F_48 ( V_51 ) ) {
F_7 ( V_51 , V_36 , L_98 ) ;
return - V_655 ;
}
if ( V_654 )
return F_197 ( V_51 , V_654 ) ;
else
return F_190 ( V_51 , true ) ;
}
static int F_202 ( struct V_84 * V_51 , T_1 * V_291 , int V_66 )
{
int V_63 ;
if ( ! F_48 ( V_51 ) || ! F_39 ( & V_51 -> V_166 [ 0 ] ) ) {
F_7 ( V_51 , V_36 ,
L_99 ) ;
return - V_12 ;
}
if ( ! F_10 ( & V_51 -> V_166 [ 0 ] , V_66 , true ) ) {
F_7 ( V_51 , V_36 ,
L_100 , V_66 ) ;
return - V_12 ;
}
F_50 (cdev, i) {
struct V_1 * V_574 = & V_51 -> V_166 [ V_63 ] ;
struct V_290 * V_289 ;
V_289 = F_90 ( V_574 , V_66 , true ) ;
if ( ! V_289 )
continue;
F_105 ( V_289 -> V_656 , V_291 ) ;
F_165 ( V_574 , V_657 ) ;
}
return 0 ;
}
static int F_203 ( struct V_84 * V_51 , T_3 V_394 , int V_66 )
{
int V_63 ;
if ( ! F_48 ( V_51 ) || ! F_39 ( & V_51 -> V_166 [ 0 ] ) ) {
F_7 ( V_51 , V_36 ,
L_99 ) ;
return - V_12 ;
}
if ( ! F_10 ( & V_51 -> V_166 [ 0 ] , V_66 , true ) ) {
F_7 ( V_51 , V_36 ,
L_100 , V_66 ) ;
return - V_12 ;
}
F_50 (cdev, i) {
struct V_1 * V_574 = & V_51 -> V_166 [ V_63 ] ;
struct V_290 * V_289 ;
V_289 = F_90 ( V_574 , V_66 , true ) ;
if ( ! V_289 )
continue;
V_289 -> V_658 = V_394 ;
F_165 ( V_574 , V_657 ) ;
}
return 0 ;
}
static int F_204 ( struct V_84 * V_51 ,
int V_22 , struct V_659 * V_660 )
{
struct V_1 * V_574 = F_182 ( V_51 ) ;
struct V_290 * V_289 ;
struct V_208 V_107 ;
T_2 V_661 ;
if ( F_44 ( V_51 ) )
return - V_12 ;
if ( ! F_10 ( & V_51 -> V_166 [ 0 ] , V_22 , true ) ) {
F_7 ( V_51 , V_36 ,
L_101 , V_22 ) ;
return - V_12 ;
}
V_289 = F_90 ( V_574 , V_22 , true ) ;
F_157 ( V_574 , V_22 , NULL , & V_107 , NULL ) ;
V_660 -> V_57 = V_22 ;
if ( F_205 ( V_289 -> V_656 ) )
F_105 ( V_660 -> V_291 , V_289 -> V_656 ) ;
else
F_105 ( V_660 -> V_291 , V_289 -> V_291 ) ;
V_660 -> V_393 = V_289 -> V_658 ;
V_660 -> V_662 = F_174 ( V_574 , V_22 ) ;
V_660 -> V_663 = V_289 -> V_664 ;
V_661 = V_289 -> V_661 ;
V_660 -> V_665 = V_661 ? V_661 : V_107 . V_212 ;
V_660 -> V_666 = F_184 ( V_574 , V_22 ) ;
return 0 ;
}
void F_206 ( struct V_1 * V_574 )
{
struct V_209 V_240 ;
struct V_207 V_74 ;
struct V_208 V_107 ;
int V_63 ;
if ( ! V_574 -> V_50 )
return;
for ( V_63 = 0 ; V_63 < V_574 -> V_51 -> V_52 -> V_53 ; V_63 ++ ) {
struct V_290 * V_289 ;
V_289 = F_90 ( V_574 , V_63 , false ) ;
if ( ! V_289 )
continue;
memcpy ( & V_74 , F_78 ( V_574 ) , sizeof( V_74 ) ) ;
memcpy ( & V_107 , F_79 ( V_574 ) , sizeof( V_107 ) ) ;
memcpy ( & V_240 , F_80 ( V_574 ) ,
sizeof( V_240 ) ) ;
switch ( V_289 -> V_664 ) {
case V_667 :
V_107 . V_226 = false ;
break;
case V_668 :
V_107 . V_226 = true ;
V_107 . V_212 = ( V_574 -> V_51 -> V_348 > 1 ) ?
100000 : 40000 ;
default:
break;
}
if ( V_107 . V_226 && V_289 -> V_661 ) {
struct V_67 * V_624 ;
int V_632 ;
V_632 = F_72 ( int , V_289 -> V_661 , V_107 . V_212 ) ;
V_624 = F_193 ( V_574 ) ;
if ( ! V_624 ) {
F_6 ( V_574 , L_102 ) ;
return;
}
if ( ! F_178 ( V_574 , V_624 , V_63 , V_632 ) ) {
V_289 -> V_661 = V_632 ;
V_107 . V_212 = V_632 ;
}
F_196 ( V_574 , V_624 ) ;
}
F_76 ( V_574 , V_63 , & V_74 , & V_107 , & V_240 ) ;
}
F_165 ( V_574 , V_669 ) ;
}
static int F_207 ( struct V_84 * V_51 ,
int V_22 , int V_664 )
{
int V_63 ;
if ( F_44 ( V_51 ) )
return - V_12 ;
if ( ! F_10 ( & V_51 -> V_166 [ 0 ] , V_22 , true ) ) {
F_7 ( V_51 , V_36 ,
L_101 , V_22 ) ;
return - V_12 ;
}
F_50 (cdev, i) {
struct V_1 * V_574 = & V_51 -> V_166 [ V_63 ] ;
struct V_290 * V_57 ;
V_57 = F_90 ( V_574 , V_22 , true ) ;
if ( ! V_57 )
continue;
if ( V_57 -> V_664 == V_664 )
continue;
V_57 -> V_664 = V_664 ;
F_206 ( & V_51 -> V_166 [ V_63 ] ) ;
}
return 0 ;
}
static int F_208 ( struct V_84 * V_51 , int V_66 , bool V_113 )
{
int V_63 , V_11 = - V_12 ;
F_50 (cdev, i) {
struct V_1 * V_2 = & V_51 -> V_166 [ V_63 ] ;
V_11 = F_175 ( V_2 , V_66 , V_113 ) ;
if ( V_11 )
break;
}
return V_11 ;
}
static int F_209 ( struct V_84 * V_51 , int V_66 , int V_632 )
{
int V_63 ;
F_50 (cdev, i) {
struct V_1 * V_2 = & V_51 -> V_166 [ V_63 ] ;
struct V_290 * V_57 ;
if ( ! F_47 ( V_2 , V_66 ) ) {
F_6 ( V_2 ,
L_103 ) ;
return - V_12 ;
}
V_57 = F_90 ( V_2 , V_66 , true ) ;
V_57 -> V_661 = V_632 ;
F_206 ( V_2 ) ;
}
return 0 ;
}
static int F_210 ( struct V_84 * V_51 ,
int V_66 , T_2 V_670 , T_2 V_671 )
{
int V_672 = 0 , V_673 = 0 ;
if ( V_671 )
V_673 = F_209 ( V_51 , V_66 , V_671 ) ;
if ( V_670 )
V_672 = F_181 ( V_51 , V_66 , V_670 ) ;
if ( V_673 | V_672 )
return - V_12 ;
return 0 ;
}
static void F_211 ( struct V_1 * V_574 )
{
V_160 V_396 [ V_609 ] ;
struct V_67 * V_624 ;
int V_63 ;
V_624 = F_193 ( V_574 ) ;
if ( ! V_624 ) {
F_7 ( V_574 , V_36 ,
L_104 ) ;
F_165 ( V_574 , V_616 ) ;
return;
}
F_163 ( V_574 , V_396 ) ;
F_7 ( V_574 , V_36 ,
L_105 ,
V_396 [ 0 ] , V_396 [ 1 ] , V_396 [ 2 ] ) ;
F_195 (hwfn, i) {
if ( ! ( V_396 [ V_63 / 64 ] & ( 1ULL << ( V_63 % 64 ) ) ) )
continue;
F_7 ( V_574 , V_36 ,
L_106 ,
V_63 , V_574 -> V_51 -> V_52 -> V_147 + V_63 ) ;
if ( F_169 ( V_574 , V_624 , V_63 ) )
continue;
F_161 ( V_574 , V_624 , V_63 ) ;
}
F_196 ( V_574 , V_624 ) ;
}
static void F_212 ( struct V_1 * V_574 )
{
int V_63 ;
F_195 (hwfn, i) {
struct V_290 * V_674 ;
bool V_675 = false ;
T_1 * V_291 ;
V_674 = F_90 ( V_574 , V_63 , true ) ;
if ( ! V_674 )
continue;
V_291 = F_176 ( V_574 , V_63 ) ;
if ( F_205 ( V_674 -> V_656 ) &&
( ! V_291 || ! F_140 ( V_291 , V_674 -> V_656 ) ) ) {
F_7 ( V_574 ,
V_36 ,
L_107 ,
V_63 ,
V_574 -> V_51 -> V_52 -> V_147 + V_63 ) ;
F_170 ( V_574 ,
V_674 -> V_656 , V_63 ) ;
V_675 = true ;
}
if ( F_177 ( V_574 , V_63 ) ^
V_674 -> V_658 ) {
F_7 ( V_574 ,
V_36 ,
L_108 ,
V_674 -> V_658 ,
V_63 ,
V_574 -> V_51 -> V_52 -> V_147 + V_63 ) ;
F_171 ( V_574 ,
V_674 -> V_658 , V_63 ) ;
V_675 = true ;
}
if ( V_675 )
F_165 ( V_574 , V_669 ) ;
}
}
static void F_213 ( struct V_1 * V_574 )
{
struct V_67 * V_624 ;
int V_63 ;
V_624 = F_193 ( V_574 ) ;
if ( ! V_624 ) {
F_6 ( V_574 , L_109 ) ;
F_165 ( V_574 , V_669 ) ;
return;
}
F_195 (hwfn, i)
F_16 ( V_574 , V_63 , V_624 ) ;
F_196 ( V_574 , V_624 ) ;
}
static void F_214 ( struct V_676 * V_677 )
{
struct V_1 * V_574 = F_215 ( V_677 , struct V_1 ,
V_642 . V_677 ) ;
int V_11 ;
if ( F_216 ( V_678 , & V_574 -> V_640 ) )
return;
if ( F_216 ( V_679 , & V_574 -> V_640 ) ) {
struct V_67 * V_624 = F_193 ( V_574 ) ;
if ( ! V_624 ) {
F_165 ( V_574 , V_679 ) ;
return;
}
V_11 = F_154 ( V_574 , V_624 ) ;
if ( V_11 )
F_165 ( V_574 , V_679 ) ;
F_196 ( V_574 , V_624 ) ;
}
if ( F_216 ( V_616 , & V_574 -> V_640 ) )
F_211 ( V_574 ) ;
if ( F_216 ( V_657 ,
& V_574 -> V_640 ) )
F_212 ( V_574 ) ;
if ( F_216 ( V_669 ,
& V_574 -> V_640 ) )
F_213 ( V_574 ) ;
}
void F_217 ( struct V_84 * V_51 , bool V_680 )
{
int V_63 ;
F_50 (cdev, i) {
if ( ! V_51 -> V_166 [ V_63 ] . V_641 )
continue;
if ( V_680 ) {
F_165 ( & V_51 -> V_166 [ V_63 ] ,
V_678 ) ;
F_218 ( & V_51 -> V_166 [ V_63 ] . V_642 ) ;
}
F_191 ( V_51 -> V_166 [ V_63 ] . V_641 ) ;
F_219 ( V_51 -> V_166 [ V_63 ] . V_641 ) ;
}
}
int F_220 ( struct V_84 * V_51 )
{
char V_681 [ V_682 ] ;
int V_63 ;
F_50 (cdev, i) {
struct V_1 * V_2 = & V_51 -> V_166 [ V_63 ] ;
if ( F_221 ( V_2 -> V_51 ) && ! F_36 ( V_2 ) )
continue;
snprintf ( V_681 , V_682 , L_110 ,
V_51 -> V_88 -> V_683 -> V_684 ,
F_222 ( V_51 -> V_88 -> V_685 ) , V_2 -> V_163 ) ;
V_2 -> V_641 = F_223 ( V_681 ) ;
if ( ! V_2 -> V_641 ) {
F_6 ( V_2 , L_111 ) ;
return - V_157 ;
}
if ( F_221 ( V_51 ) )
F_224 ( & V_2 -> V_642 , F_214 ) ;
else
F_224 ( & V_2 -> V_642 , V_686 ) ;
}
return 0 ;
}
