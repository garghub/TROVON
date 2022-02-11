static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_6 , V_7 , V_8 ;
bool V_9 ;
const struct V_10 * V_11 ;
int V_12 ;
if ( V_4 -> V_13 != V_14 )
return;
V_9 = ! V_4 -> V_15 ;
V_7 = F_3 ( V_2 , V_16 ) ;
if ( V_7 & V_17 )
V_7 = V_4 -> V_18 [ 1 ] ;
else
V_7 = V_4 -> V_18 [ 0 ] ;
if ( V_4 -> V_19 && V_4 -> V_19 -> V_20 ) {
V_11 = V_4 -> V_19 -> V_20 ;
V_12 = V_4 -> V_19 -> V_21 ;
} else if ( V_4 -> V_22 ) {
V_11 = V_23 ;
V_12 = F_4 ( V_23 ) ;
} else {
V_11 = V_24 ;
V_12 = F_4 ( V_24 ) ;
}
V_5 = 0 ;
for ( V_6 = 0 ; V_6 < V_12 ; V_6 ++ ) {
if ( V_11 [ V_6 ] . V_9 != V_9 )
continue;
if ( abs ( V_11 [ V_6 ] . V_7 - V_7 ) <
abs ( V_11 [ V_5 ] . V_7 - V_7 ) )
V_5 = V_6 ;
else if ( V_11 [ V_5 ] . V_9 != V_9 )
V_5 = V_6 ;
}
V_8 = V_11 [ V_5 ] . V_25 << V_26
| V_11 [ V_5 ] . V_27 << V_28 ;
F_5 ( V_2 , V_29 ,
V_30 |
V_31 , V_8 ) ;
}
static int F_6 ( struct V_1 * V_2 , int V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_27 ;
int V_33 = 0 ;
int V_34 ;
if ( V_32 )
V_34 = 4 ;
else
V_34 = 0 ;
switch ( V_4 -> V_7 [ V_32 ] ) {
case V_35 :
V_27 = V_4 -> V_36 [ 0 ] ;
break;
case V_37 :
V_33 |= 0x8 ;
V_27 = V_4 -> V_36 [ 1 ] ;
break;
case V_38 :
V_33 |= 0x10 ;
V_27 = V_4 -> V_39 [ 0 ] . V_40 ;
break;
case V_41 :
V_33 |= 0x18 ;
V_27 = V_4 -> V_39 [ 1 ] . V_40 ;
break;
default:
return - V_42 ;
}
if ( V_27 >= 13500000 ) {
V_27 /= 2 ;
V_33 |= V_43 ;
F_7 ( V_2 -> V_44 , L_1 ,
V_32 + 1 , V_27 ) ;
}
V_4 -> V_18 [ V_32 ] = V_27 ;
F_5 ( V_2 , V_45 + V_34 ,
V_46 | V_43 ,
V_33 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_47 , V_48 ;
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , 1 ) ;
if ( V_4 -> V_18 [ 0 ] == V_4 -> V_18 [ 1 ] ) {
F_1 ( V_2 ) ;
return 0 ;
}
if ( V_4 -> V_18 [ 0 ] < V_4 -> V_18 [ 1 ] )
V_48 = V_17 ;
else
V_48 = 0 ;
V_47 = F_5 ( V_2 , V_16 ,
V_17 , V_48 ) ;
if ( V_47 )
F_9 ( & V_2 -> V_49 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_10 ( struct V_50 * V_51 ,
struct V_50 * V_52 )
{
int V_53 = F_3 ( V_51 -> V_2 , V_16 ) ;
const char * V_54 ;
if ( V_53 & V_17 )
V_54 = L_2 ;
else
V_54 = L_3 ;
return strcmp ( V_51 -> V_55 , V_54 ) == 0 ;
}
static int F_11 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_60 * V_61 =
(struct V_60 * ) V_57 -> V_62 ;
struct V_1 * V_2 = F_12 ( V_57 ) ;
int V_63 , V_64 ;
if ( V_61 -> V_65 == V_66 )
V_63 = V_67 |
V_68 ;
else
V_63 = V_69 ;
V_64 = F_3 ( V_2 , V_61 -> V_53 ) ;
if ( V_64 < 0 )
return V_64 ;
if ( V_64 & V_63 )
return - V_42 ;
return F_13 ( V_57 , V_59 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_70 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_71 * V_19 = V_4 -> V_19 ;
int V_72 = V_73 [ V_70 ] ;
int V_74 = V_4 -> V_75 [ V_70 ] ;
int V_76 , V_6 ;
V_76 = F_3 ( V_2 , V_72 ) ;
V_76 &= V_77 | V_78 |
V_79 ;
for ( V_6 = 0 ; V_6 < V_80 ; V_6 ++ )
F_5 ( V_2 , V_72 + V_6 , 0xffff ,
V_19 -> V_81 [ V_74 ] . V_82 [ V_6 ] ) ;
F_5 ( V_2 , V_72 , V_77 |
V_78 |
V_79 , V_76 ) ;
}
static int F_15 ( const char * V_55 )
{
if ( strcmp ( V_55 , L_4 ) == 0 )
return 0 ;
if ( strcmp ( V_55 , L_5 ) == 0 )
return 1 ;
if ( strcmp ( V_55 , L_6 ) == 0 )
return 2 ;
return - V_42 ;
}
static int F_16 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_12 ( V_57 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_71 * V_19 = V_4 -> V_19 ;
int V_70 = F_15 ( V_57 -> V_83 . V_55 ) ;
int V_84 = V_59 -> V_84 . integer . V_84 [ 0 ] ;
if ( V_70 < 0 )
return V_70 ;
if ( V_84 >= V_19 -> V_85 )
return - V_42 ;
V_4 -> V_75 [ V_70 ] = V_84 ;
F_14 ( V_2 , V_70 ) ;
return 0 ;
}
static int F_17 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_12 ( V_57 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_70 = F_15 ( V_57 -> V_83 . V_55 ) ;
V_59 -> V_84 . V_86 . V_87 [ 0 ] = V_4 -> V_75 [ V_70 ] ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , int V_88 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_71 * V_19 = V_4 -> V_19 ;
int V_72 = V_89 [ V_88 ] ;
int V_90 , V_5 , V_91 , V_76 , V_6 , V_74 ;
if ( ! V_19 || ! V_4 -> V_92 )
return;
switch ( V_88 ) {
case 0 :
case 1 :
V_90 = 0 ;
break;
case 2 :
V_90 = 1 ;
break;
default:
return;
}
V_74 = V_4 -> V_93 [ V_88 ] ;
V_5 = 0 ;
V_91 = V_94 ;
for ( V_6 = 0 ; V_6 < V_19 -> V_95 ; V_6 ++ ) {
if ( strcmp ( V_19 -> V_96 [ V_6 ] . V_55 ,
V_4 -> V_97 [ V_74 ] ) == 0 &&
abs ( V_19 -> V_96 [ V_6 ] . V_27
- V_4 -> V_98 [ V_90 ] ) < V_91 ) {
V_5 = V_6 ;
V_91 = abs ( V_19 -> V_96 [ V_6 ] . V_27
- V_4 -> V_98 [ V_90 ] ) ;
}
}
F_7 ( V_2 -> V_44 , L_7 ,
V_88 ,
V_19 -> V_96 [ V_5 ] . V_55 ,
V_19 -> V_96 [ V_5 ] . V_27 ,
V_4 -> V_98 [ V_90 ] ) ;
V_76 = F_3 ( V_2 , V_72 ) ;
V_76 &= V_99 ;
for ( V_6 = 0 ; V_6 < V_100 ; V_6 ++ )
F_5 ( V_2 , V_72 + V_6 , 0xffff ,
V_19 -> V_96 [ V_5 ] . V_82 [ V_6 ] ) ;
F_5 ( V_2 , V_72 , V_99 , V_76 ) ;
}
static int F_19 ( const char * V_55 )
{
if ( strcmp ( V_55 , L_8 ) == 0 )
return 0 ;
if ( strcmp ( V_55 , L_9 ) == 0 )
return 1 ;
if ( strcmp ( V_55 , L_10 ) == 0 )
return 2 ;
return - V_42 ;
}
static int F_20 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_12 ( V_57 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_71 * V_19 = V_4 -> V_19 ;
int V_88 = F_19 ( V_57 -> V_83 . V_55 ) ;
int V_84 = V_59 -> V_84 . integer . V_84 [ 0 ] ;
if ( V_88 < 0 )
return V_88 ;
if ( V_84 >= V_19 -> V_95 )
return - V_42 ;
V_4 -> V_93 [ V_88 ] = V_84 ;
F_18 ( V_2 , V_88 ) ;
return 0 ;
}
static int F_21 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_12 ( V_57 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_88 = F_19 ( V_57 -> V_83 . V_55 ) ;
V_59 -> V_84 . V_86 . V_87 [ 0 ] = V_4 -> V_93 [ V_88 ] ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 , T_1 V_101 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_22 || ! V_4 -> V_13 )
return;
if ( V_4 -> V_102 )
V_101 = V_103 ;
if ( V_101 == V_4 -> V_104 )
return;
V_4 -> V_104 = V_101 ;
if ( V_101 != V_105 )
V_101 = V_103 ;
F_5 ( V_2 , V_106 ,
V_107 , V_101 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_24 ( & V_4 -> V_108 ) ;
V_4 -> V_102 ++ ;
F_7 ( V_2 -> V_44 , L_11 ,
V_4 -> V_102 ) ;
F_22 ( V_2 , V_103 ) ;
F_25 ( & V_4 -> V_108 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_101 ;
F_24 ( & V_4 -> V_108 ) ;
V_4 -> V_102 -- ;
F_7 ( V_2 -> V_44 , L_12 ,
V_4 -> V_102 ) ;
if ( V_4 -> V_102 == 0 ) {
if ( V_4 -> V_15 || V_4 -> V_109 )
V_101 = V_110 ;
else
V_101 = V_111 ;
F_22 ( V_2 , V_101 ) ;
}
F_25 ( & V_4 -> V_108 ) ;
}
static int F_27 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
switch ( V_113 ) {
case V_114 :
return F_8 ( V_2 ) ;
case V_115 :
F_8 ( V_2 ) ;
break;
}
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_29 ( V_2 -> V_44 ) ;
V_4 -> V_116 ++ ;
F_7 ( V_2 -> V_44 , L_13 ,
V_4 -> V_116 ) ;
if ( V_4 -> V_116 == 1 ) {
F_5 ( V_2 , V_117 ,
V_118 |
V_119 , 0 ) ;
F_30 ( V_2 ) ;
switch ( V_4 -> V_120 ) {
default:
F_31 ( 0 == L_14 ) ;
case V_121 :
F_5 ( V_2 , V_106 ,
V_122 |
V_123 |
V_124 |
V_125 |
V_126 ,
V_122 |
V_124 |
V_125 |
( 0x3 << V_127 ) ) ;
F_5 ( V_2 , V_128 ,
V_129 |
V_130 ,
V_129 | 0x2 ) ;
F_32 ( 50 ) ;
F_5 ( V_2 , V_106 ,
V_126 |
V_122 ,
0 ) ;
break;
case V_131 :
F_5 ( V_2 , V_106 ,
V_122 |
V_123 |
V_124 |
V_125 |
V_126 ,
V_122 |
V_124 |
V_125 |
( 0x2 << V_127 ) ) ;
F_5 ( V_2 , V_128 ,
V_129 |
V_130 ,
V_129 | 0x2 ) ;
F_32 ( 400 ) ;
F_5 ( V_2 , V_106 ,
V_126 |
V_122 ,
0 ) ;
break;
}
}
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_116 -- ;
F_7 ( V_2 -> V_44 , L_15 ,
V_4 -> V_116 ) ;
if ( V_4 -> V_116 == 0 ) {
if ( V_4 -> V_132 . V_133 )
F_5 ( V_2 , V_134 ,
V_135 |
V_136 ,
V_135 |
V_136 ) ;
if ( V_4 -> V_132 . V_137 )
F_5 ( V_2 , V_134 ,
V_138 |
V_139 ,
V_138 |
V_139 ) ;
F_5 ( V_2 , V_106 ,
V_122 |
V_123 ,
V_122 |
V_123 ) ;
switch ( V_4 -> V_120 ) {
case V_131 :
F_32 ( 350 ) ;
break;
default:
break;
}
F_5 ( V_2 , V_140 ,
V_141 , V_141 ) ;
F_5 ( V_2 , V_117 ,
V_118 |
V_119 ,
V_118 |
V_119 ) ;
F_32 ( 150 ) ;
F_5 ( V_2 , V_134 ,
V_135 |
V_136 |
V_138 |
V_139 , 0 ) ;
F_5 ( V_2 , V_140 ,
V_141 , 0 ) ;
F_5 ( V_2 , V_106 ,
V_122 |
V_124 |
V_125 |
V_126 , 0 ) ;
F_5 ( V_2 , V_128 ,
V_129 | V_130 , 0 ) ;
F_5 ( V_2 , V_106 ,
V_126 , 0 ) ;
}
F_34 ( V_2 -> V_44 ) ;
}
static int F_35 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
switch ( V_113 ) {
case V_114 :
F_28 ( V_2 ) ;
break;
case V_115 :
F_33 ( V_2 ) ;
break;
}
return 0 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_142 = 1 ;
int V_51 = 0 ;
int V_53 , V_143 ;
V_53 = F_3 ( V_2 , V_144 ) ;
if ( ! ( V_53 & V_145 ) ) {
F_37 ( V_2 -> V_44 , L_16 ) ;
V_142 = 0 ;
}
V_53 = F_3 ( V_2 , V_146 ) ;
if ( ! ( V_53 & V_147 ) ) {
F_37 ( V_2 -> V_44 , L_17 ) ;
V_142 = 0 ;
}
V_53 = F_3 ( V_2 , V_148 ) ;
switch ( V_53 ) {
case V_149 :
F_37 ( V_2 -> V_44 , L_18 ) ;
V_51 = 2 << V_150 ;
break;
case V_151 :
F_37 ( V_2 -> V_44 , L_19 ) ;
V_51 = 1 << V_150 ;
break;
case V_152 :
F_37 ( V_2 -> V_44 , L_20 ) ;
V_51 = 0 << V_150 ;
break;
default:
F_37 ( V_2 -> V_44 , L_21 , V_53 ) ;
V_142 = 0 ;
break;
}
V_143 = F_3 ( V_2 , V_153 ) ;
if ( V_143 != V_53 ) {
F_37 ( V_2 -> V_44 , L_22 ) ;
V_142 = 0 ;
}
if ( V_142 ) {
F_7 ( V_2 -> V_44 , L_23 ) ;
F_5 ( V_2 , V_154 ,
V_155 |
V_156 ,
V_51 | V_155 ) ;
V_4 -> V_132 . V_157 = true ;
} else {
F_7 ( V_2 -> V_44 , L_24 ) ;
F_5 ( V_2 , V_154 ,
V_155 , 0 ) ;
V_4 -> V_132 . V_157 = false ;
}
}
static int F_38 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
struct V_4 * V_158 = V_2 -> V_159 ;
int V_63 = V_160 | V_161 ;
int V_162 ;
int V_163 ;
int V_8 ;
switch ( V_158 -> type ) {
case V_164 :
case V_165 :
V_63 |= V_166 | V_167 ;
break;
default:
break;
}
switch ( V_113 ) {
case V_114 :
V_8 = F_3 ( V_2 , V_168 ) ;
if ( ( V_8 & V_169 ) &&
( V_8 & V_170 ) )
V_163 = V_171 | V_172 ;
else if ( ! ( V_8 & V_169 ) &&
! ( V_8 & V_170 ) )
V_163 = V_173 | V_174 ;
else
V_163 = V_171 | V_172 |
V_173 | V_174 ;
V_8 = F_3 ( V_2 , V_175 ) ;
if ( ( V_8 & V_176 ) &&
( V_8 & V_177 ) )
V_162 = V_161 | V_167 ;
else if ( ! ( V_8 & V_176 ) &&
! ( V_8 & V_177 ) )
V_162 = V_160 | V_166 ;
else
V_162 = V_161 | V_167 |
V_160 | V_166 ;
F_5 ( V_2 , V_178 ,
V_63 , V_163 ) ;
F_5 ( V_2 , V_179 ,
V_63 , V_162 ) ;
F_5 ( V_2 , V_16 ,
V_180 |
V_181 ,
V_180 |
V_181 ) ;
F_5 ( V_2 , V_178 , V_63 ,
V_171 |
V_173 |
V_172 |
V_174 ) ;
F_5 ( V_2 , V_179 , V_63 ,
V_161 |
V_160 |
V_167 |
V_166 ) ;
break;
case V_182 :
case V_115 :
F_5 ( V_2 , V_179 ,
V_63 , 0 ) ;
F_5 ( V_2 , V_178 ,
V_63 , 0 ) ;
V_8 = F_3 ( V_2 , V_16 ) ;
if ( V_8 & V_183 )
V_8 = V_181 ;
else
V_8 = 0 ;
F_5 ( V_2 , V_16 ,
V_181 |
V_180 , V_8 ) ;
break;
}
return 0 ;
}
static int F_39 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
int V_162 ;
int V_163 ;
int V_8 ;
switch ( V_113 ) {
case V_114 :
V_8 = F_3 ( V_2 , V_184 ) ;
if ( ( V_8 & V_185 ) &&
( V_8 & V_186 ) )
V_163 = V_187 ;
else if ( ! ( V_8 & V_185 ) &&
! ( V_8 & V_186 ) )
V_163 = V_188 ;
else
V_163 = V_188 | V_187 ;
V_8 = F_3 ( V_2 , V_189 ) ;
if ( ( V_8 & V_190 ) &&
( V_8 & V_191 ) )
V_162 = V_192 ;
else if ( ! ( V_8 & V_190 ) &&
! ( V_8 & V_191 ) )
V_162 = V_193 ;
else
V_162 = V_193 | V_192 ;
F_5 ( V_2 , V_178 ,
V_188 |
V_187 , V_163 ) ;
F_5 ( V_2 , V_179 ,
V_193 |
V_192 , V_162 ) ;
F_5 ( V_2 , V_16 ,
V_183 |
V_181 ,
V_183 |
V_181 ) ;
F_5 ( V_2 , V_178 ,
V_188 |
V_187 ,
V_188 |
V_187 ) ;
F_5 ( V_2 , V_179 ,
V_193 |
V_192 ,
V_193 |
V_192 ) ;
break;
case V_182 :
case V_115 :
F_5 ( V_2 , V_179 ,
V_193 |
V_192 , 0 ) ;
F_5 ( V_2 , V_178 ,
V_188 |
V_187 , 0 ) ;
V_8 = F_3 ( V_2 , V_16 ) ;
if ( V_8 & V_180 )
V_8 = V_181 ;
else
V_8 = 0 ;
F_5 ( V_2 , V_16 ,
V_181 |
V_183 , V_8 ) ;
break;
}
return 0 ;
}
static int F_40 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_113 ) {
case V_114 :
V_4 -> V_194 = 1 ;
break;
case V_115 :
V_4 -> V_195 = 1 ;
break;
}
return 0 ;
}
static int F_41 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_113 ) {
case V_114 :
V_4 -> V_196 = 1 ;
break;
case V_115 :
V_4 -> V_197 = 1 ;
break;
}
return 0 ;
}
static int F_42 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_113 ) {
case V_114 :
if ( V_4 -> V_194 ) {
F_38 ( V_112 , V_57 , V_113 ) ;
F_5 ( V_2 , V_45 ,
V_198 ,
V_199 ) ;
V_4 -> V_194 = 0 ;
}
if ( V_4 -> V_196 ) {
F_39 ( V_112 , V_57 , V_113 ) ;
F_5 ( V_2 , V_200 ,
V_201 ,
V_202 ) ;
V_4 -> V_196 = 0 ;
}
break;
}
F_43 ( V_112 , V_57 , V_113 ) ;
return 0 ;
}
static int F_44 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_113 ) {
case V_115 :
if ( V_4 -> V_195 ) {
F_5 ( V_2 , V_45 ,
V_198 , 0 ) ;
F_38 ( V_112 , V_57 , V_113 ) ;
V_4 -> V_195 = 0 ;
}
if ( V_4 -> V_197 ) {
F_5 ( V_2 , V_200 ,
V_201 , 0 ) ;
F_39 ( V_112 , V_57 , V_113 ) ;
V_4 -> V_197 = 0 ;
}
break;
}
return 0 ;
}
static int F_45 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
F_42 ( V_112 , V_57 , V_113 ) ;
return 0 ;
}
static int F_46 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
F_42 ( V_112 , V_57 , V_113 ) ;
return 0 ;
}
static int F_47 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
unsigned int V_63 = 1 << V_112 -> V_65 ;
F_5 ( V_2 , V_179 ,
V_63 , V_63 ) ;
return 0 ;
}
static int F_48 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_203 * V_204 = F_12 ( V_57 ) ;
struct V_50 * V_112 = V_204 -> V_205 [ 0 ] ;
struct V_1 * V_2 = V_112 -> V_2 ;
int V_64 ;
V_64 = F_49 ( V_57 , V_59 ) ;
F_36 ( V_2 ) ;
return V_64 ;
}
static int F_50 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
F_7 ( V_2 -> V_44 , L_25 ,
F_3 ( V_2 ,
V_206 ) ) ;
return 0 ;
}
static int F_51 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_203 * V_204 = F_12 ( V_57 ) ;
struct V_50 * V_112 = V_204 -> V_205 [ 0 ] ;
struct V_1 * V_2 = V_112 -> V_2 ;
int V_64 ;
V_64 = F_52 ( V_57 , V_59 ) ;
F_36 ( V_2 ) ;
return V_64 ;
}
static int F_53 ( struct V_207 * V_39 ,
int V_208 , int V_209 )
{
T_2 V_210 ;
unsigned int V_211 , V_212 , V_213 ;
F_54 ( L_26 , V_208 , V_209 ) ;
V_39 -> V_214 = 0 ;
while ( V_208 > 13500000 ) {
V_39 -> V_214 ++ ;
V_208 /= 2 ;
if ( V_39 -> V_214 > 3 )
return - V_42 ;
}
F_54 ( L_27 , V_39 -> V_214 , V_208 ) ;
V_39 -> V_215 = 3 ;
while ( V_209 * ( V_39 -> V_215 + 1 ) < 90000000 ) {
V_39 -> V_215 ++ ;
if ( V_39 -> V_215 > 63 )
return - V_42 ;
}
V_209 *= V_39 -> V_215 + 1 ;
F_54 ( L_28 , V_39 -> V_215 , V_209 ) ;
if ( V_208 > 1000000 ) {
V_39 -> V_216 = 0 ;
} else if ( V_208 > 256000 ) {
V_39 -> V_216 = 1 ;
V_208 *= 2 ;
} else if ( V_208 > 128000 ) {
V_39 -> V_216 = 2 ;
V_208 *= 4 ;
} else if ( V_208 > 64000 ) {
V_39 -> V_216 = 3 ;
V_208 *= 8 ;
} else {
V_39 -> V_216 = 4 ;
V_208 *= 16 ;
}
F_54 ( L_29 , V_39 -> V_216 , V_208 ) ;
V_212 = V_209 / V_208 ;
V_39 -> V_217 = V_212 ;
V_213 = V_209 % V_208 ;
F_54 ( L_30 , V_213 ) ;
V_210 = V_218 * ( long long ) V_213 ;
F_55 ( V_210 , V_208 ) ;
V_211 = V_210 & 0xFFFFFFFF ;
if ( ( V_211 % 10 ) >= 5 )
V_211 += 5 ;
V_39 -> V_219 = V_211 / 10 ;
F_54 ( L_31 , V_39 -> V_217 , V_39 -> V_219 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , int V_83 , int V_220 ,
unsigned int V_208 , unsigned int V_209 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_158 = V_4 -> V_4 ;
int V_221 , V_64 ;
struct V_207 V_39 ;
T_1 V_53 , V_222 , V_223 ;
unsigned long V_224 ;
bool V_225 ;
V_222 = F_3 ( V_2 , V_45 )
& V_199 ;
V_223 = F_3 ( V_2 , V_200 )
& V_202 ;
switch ( V_83 ) {
case V_226 :
V_221 = 0 ;
V_83 = 0 ;
break;
case V_227 :
V_221 = 0x20 ;
V_83 = 1 ;
break;
default:
return - V_42 ;
}
V_53 = F_3 ( V_2 , V_228 + V_221 ) ;
V_225 = V_53 & V_229 ;
switch ( V_220 ) {
case 0 :
if ( V_209 )
return - V_42 ;
V_220 = V_4 -> V_39 [ V_83 ] . V_220 ;
break;
case V_230 :
case V_231 :
case V_232 :
case V_233 :
break;
default:
return - V_42 ;
}
if ( V_4 -> V_39 [ V_83 ] . V_220 == V_220 &&
V_4 -> V_39 [ V_83 ] . V_234 == V_208 && V_4 -> V_39 [ V_83 ] . V_40 == V_209 )
return 0 ;
if ( V_209 )
V_64 = F_53 ( & V_39 , V_208 , V_209 ) ;
else
V_64 = F_53 ( & V_39 , V_4 -> V_39 [ V_83 ] . V_234 ,
V_4 -> V_39 [ V_83 ] . V_40 ) ;
if ( V_64 < 0 )
return V_64 ;
F_5 ( V_2 , V_45 ,
V_199 , 0 ) ;
F_5 ( V_2 , V_200 ,
V_202 , 0 ) ;
F_5 ( V_2 , V_228 + V_221 ,
V_229 , 0 ) ;
V_53 = ( V_39 . V_215 << V_235 ) |
( V_39 . V_216 << V_236 ) ;
F_5 ( V_2 , V_237 + V_221 ,
V_238 |
V_239 , V_53 ) ;
F_5 ( V_2 , V_240 + V_221 ,
V_241 , V_39 . V_219 ) ;
F_5 ( V_2 , V_242 + V_221 ,
V_243 ,
V_39 . V_217 << V_244 ) ;
F_5 ( V_2 , V_245 + V_221 ,
V_246 |
V_247 ,
( V_39 . V_214 << V_248 ) |
( V_220 - 1 ) ) ;
F_57 ( & V_4 -> V_249 [ V_83 ] ) ;
if ( V_209 ) {
if ( ! V_225 ) {
F_23 ( V_2 ) ;
switch ( V_158 -> type ) {
case V_164 :
F_28 ( V_2 ) ;
break;
case V_165 :
if ( V_4 -> V_250 < 1 )
F_28 ( V_2 ) ;
break;
default:
break;
}
}
if ( V_39 . V_219 )
V_53 = V_229 | V_251 ;
else
V_53 = V_229 ;
F_5 ( V_2 , V_228 + V_221 ,
V_229 | V_251 ,
V_53 ) ;
if ( V_4 -> V_252 ) {
V_224 = F_58 ( & V_4 -> V_249 [ V_83 ] ,
F_59 ( 10 ) ) ;
if ( V_224 == 0 )
F_60 ( V_2 -> V_44 ,
L_32 ) ;
} else {
F_32 ( 5 ) ;
}
} else {
if ( V_225 ) {
switch ( V_158 -> type ) {
case V_164 :
F_33 ( V_2 ) ;
break;
case V_165 :
if ( V_4 -> V_250 < 1 )
F_33 ( V_2 ) ;
break;
default:
break;
}
F_26 ( V_2 ) ;
}
}
V_4 -> V_39 [ V_83 ] . V_234 = V_208 ;
V_4 -> V_39 [ V_83 ] . V_40 = V_209 ;
V_4 -> V_39 [ V_83 ] . V_220 = V_220 ;
F_5 ( V_2 , V_45 ,
V_199 , V_222 ) ;
F_5 ( V_2 , V_200 ,
V_202 , V_223 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static T_3 F_61 ( int V_253 , void * V_254 )
{
struct V_255 * V_255 = V_254 ;
F_62 ( V_255 ) ;
return V_256 ;
}
static int F_63 ( struct V_257 * V_258 , int V_83 , int V_220 ,
unsigned int V_208 , unsigned int V_209 )
{
return F_56 ( V_258 -> V_2 , V_83 , V_220 , V_208 , V_209 ) ;
}
static int F_64 ( struct V_257 * V_258 ,
int V_259 , unsigned int V_260 , int V_261 )
{
struct V_1 * V_2 = V_258 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
switch ( V_258 -> V_83 ) {
case 1 :
case 2 :
break;
default:
return - V_42 ;
}
switch ( V_259 ) {
case V_35 :
V_4 -> V_7 [ V_258 -> V_83 - 1 ] = V_35 ;
V_4 -> V_36 [ 0 ] = V_260 ;
F_7 ( V_258 -> V_44 , L_33 ,
V_258 -> V_83 , V_260 ) ;
break;
case V_37 :
V_4 -> V_7 [ V_258 -> V_83 - 1 ] = V_37 ;
V_4 -> V_36 [ 1 ] = V_260 ;
F_7 ( V_258 -> V_44 , L_34 ,
V_258 -> V_83 , V_260 ) ;
break;
case V_38 :
V_4 -> V_7 [ V_258 -> V_83 - 1 ] = V_38 ;
F_7 ( V_258 -> V_44 , L_35 , V_258 -> V_83 ) ;
break;
case V_41 :
V_4 -> V_7 [ V_258 -> V_83 - 1 ] = V_41 ;
F_7 ( V_258 -> V_44 , L_36 , V_258 -> V_83 ) ;
break;
case V_262 :
if ( V_260 ) {
for ( V_6 = 0 ; V_6 < F_4 ( V_263 ) ; V_6 ++ )
if ( V_263 [ V_6 ] == V_260 )
break;
if ( V_6 == F_4 ( V_263 ) )
return - V_42 ;
F_5 ( V_2 , V_264 ,
V_265 , V_6 ) ;
F_5 ( V_2 , V_266 ,
V_267 , V_267 ) ;
} else {
F_5 ( V_2 , V_266 ,
V_267 , 0 ) ;
}
default:
return - V_42 ;
}
F_8 ( V_2 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
enum V_268 V_269 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_158 = V_4 -> V_4 ;
F_66 ( V_2 , V_269 ) ;
switch ( V_269 ) {
case V_270 :
break;
case V_271 :
switch ( V_158 -> type ) {
case V_165 :
case V_272 :
F_5 ( V_2 , V_273 ,
V_274 , 0 ) ;
F_5 ( V_2 , V_275 ,
V_276 , 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_49 . V_277 == V_278 )
F_23 ( V_2 ) ;
break;
case V_278 :
if ( V_2 -> V_49 . V_277 == V_279 ) {
switch ( V_158 -> type ) {
case V_165 :
if ( V_4 -> V_250 == 0 ) {
F_5 ( V_2 ,
V_280 ,
V_281 ,
V_281 ) ;
}
break;
default:
break;
}
F_5 ( V_2 , V_117 ,
V_118 |
V_119 ,
V_118 |
V_119 ) ;
}
if ( V_2 -> V_49 . V_277 == V_271 )
F_26 ( V_2 ) ;
switch ( V_158 -> type ) {
case V_165 :
case V_272 :
F_5 ( V_2 , V_273 ,
V_274 ,
V_274 ) ;
F_5 ( V_2 , V_275 ,
V_276 ,
V_276 ) ;
break;
default:
break;
}
break;
case V_279 :
if ( V_2 -> V_49 . V_277 == V_278 )
V_4 -> V_282 = NULL ;
break;
}
V_2 -> V_49 . V_277 = V_269 ;
return 0 ;
}
int F_67 ( struct V_1 * V_2 , enum F_67 V_101 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_101 ) {
case V_121 :
if ( V_4 -> V_132 . V_133 ) {
F_68 ( & V_2 -> V_49 ,
L_37 ) ;
F_68 ( & V_2 -> V_49 ,
L_38 ) ;
}
if ( V_4 -> V_132 . V_137 ) {
F_68 ( & V_2 -> V_49 ,
L_39 ) ;
F_68 ( & V_2 -> V_49 ,
L_40 ) ;
}
F_9 ( & V_2 -> V_49 ) ;
V_4 -> V_120 = V_101 ;
break;
case V_131 :
if ( V_4 -> V_132 . V_133 ) {
F_69 ( & V_2 -> V_49 ,
L_37 ) ;
F_69 ( & V_2 -> V_49 ,
L_38 ) ;
}
if ( V_4 -> V_132 . V_137 ) {
F_69 ( & V_2 -> V_49 ,
L_39 ) ;
F_69 ( & V_2 -> V_49 ,
L_40 ) ;
}
V_4 -> V_120 = V_101 ;
F_9 ( & V_2 -> V_49 ) ;
break;
default:
return - V_42 ;
}
return 0 ;
}
static int F_70 ( struct V_257 * V_258 , unsigned int V_283 )
{
struct V_1 * V_2 = V_258 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_158 = V_4 -> V_4 ;
int V_284 ;
int V_285 ;
int V_286 = 0 ;
int V_222 = 0 ;
switch ( V_258 -> V_83 ) {
case 1 :
V_284 = V_287 ;
V_285 = V_168 ;
break;
case 2 :
V_284 = V_288 ;
V_285 = V_184 ;
break;
default:
return - V_42 ;
}
switch ( V_283 & V_289 ) {
case V_290 :
break;
case V_291 :
V_286 = V_292 ;
break;
default:
return - V_42 ;
}
switch ( V_283 & V_293 ) {
case V_294 :
V_222 |= V_295 ;
case V_296 :
V_222 |= 0x18 ;
break;
case V_297 :
V_222 |= 0x10 ;
break;
case V_298 :
break;
case V_299 :
V_222 |= 0x8 ;
break;
default:
return - V_42 ;
}
switch ( V_283 & V_293 ) {
case V_296 :
case V_294 :
switch ( V_283 & V_300 ) {
case V_301 :
break;
case V_302 :
V_222 |= V_303 ;
break;
default:
return - V_42 ;
}
break;
case V_297 :
case V_298 :
case V_299 :
switch ( V_283 & V_300 ) {
case V_301 :
break;
case V_304 :
V_222 |= V_303 | V_295 ;
break;
case V_302 :
V_222 |= V_303 ;
break;
case V_305 :
V_222 |= V_295 ;
break;
default:
return - V_42 ;
}
break;
default:
return - V_42 ;
}
switch ( V_158 -> type ) {
case V_272 :
case V_165 :
if ( V_258 -> V_83 == 2 )
F_5 ( V_2 , V_306 ,
V_295 |
V_307 , V_222 ) ;
break;
default:
break;
}
F_5 ( V_2 , V_285 ,
V_303 | V_295 |
V_308 ,
V_222 ) ;
F_5 ( V_2 , V_284 , V_292 ,
V_286 ) ;
return 0 ;
}
static int F_71 ( struct V_309 * V_310 ,
struct V_311 * V_312 ,
struct V_257 * V_258 )
{
struct V_1 * V_2 = V_258 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_285 ;
int V_313 ;
int V_314 ;
int V_315 ;
int V_316 ;
int V_222 = 0 ;
int V_223 = 0 ;
int V_317 = 0 ;
int V_318 = 0 ;
int V_319 = 0 ;
int V_83 = V_258 -> V_83 - 1 ;
int V_6 , V_320 , V_91 , V_321 , V_5 ;
switch ( V_258 -> V_83 ) {
case 1 :
V_285 = V_168 ;
V_313 = V_175 ;
V_314 = V_322 ;
V_316 = V_323 ;
if ( V_310 -> V_324 == V_325 ||
V_4 -> V_326 [ 0 ] ) {
V_315 = V_327 ;
} else {
V_315 = V_328 ;
F_7 ( V_2 -> V_44 , L_41 ) ;
}
break;
case 2 :
V_285 = V_184 ;
V_313 = V_189 ;
V_314 = V_329 ;
V_316 = V_330 ;
if ( V_310 -> V_324 == V_325 ||
V_4 -> V_326 [ 1 ] ) {
V_315 = V_331 ;
} else {
V_315 = V_332 ;
F_7 ( V_2 -> V_44 , L_42 ) ;
}
break;
default:
return - V_42 ;
}
V_321 = F_72 ( V_312 ) * 2 ;
switch ( F_73 ( V_312 ) ) {
case V_333 :
V_321 *= 16 ;
break;
case V_334 :
V_321 *= 20 ;
V_222 |= 0x20 ;
break;
case V_335 :
V_321 *= 24 ;
V_222 |= 0x40 ;
break;
case V_336 :
V_321 *= 32 ;
V_222 |= 0x60 ;
break;
default:
return - V_42 ;
}
for ( V_6 = 0 ; V_6 < F_4 ( V_337 ) ; V_6 ++ )
if ( V_337 [ V_6 ] . V_27 == F_72 ( V_312 ) )
break;
if ( V_6 == F_4 ( V_337 ) )
return - V_42 ;
V_319 |= V_337 [ V_6 ] . V_8 << V_338 ;
F_7 ( V_258 -> V_44 , L_43 , V_337 [ V_6 ] . V_27 ) ;
F_7 ( V_258 -> V_44 , L_44 ,
V_258 -> V_83 , V_4 -> V_18 [ V_83 ] , V_321 ) ;
if ( F_74 ( V_312 ) == 1 &&
( F_3 ( V_2 , V_285 ) & 0x18 ) == 0x18 )
V_223 |= V_339 ;
if ( V_4 -> V_18 [ V_83 ] == 0 ) {
F_75 ( V_258 -> V_44 , L_45 , V_258 -> V_83 ) ;
return - V_42 ;
}
V_5 = 0 ;
V_91 = abs ( ( V_340 [ 0 ] * F_72 ( V_312 ) )
- V_4 -> V_18 [ V_83 ] ) ;
for ( V_6 = 1 ; V_6 < F_4 ( V_340 ) ; V_6 ++ ) {
V_320 = abs ( ( V_340 [ V_6 ] * F_72 ( V_312 ) )
- V_4 -> V_18 [ V_83 ] ) ;
if ( V_320 >= V_91 )
continue;
V_5 = V_6 ;
V_91 = V_320 ;
}
F_7 ( V_258 -> V_44 , L_46 ,
V_258 -> V_83 , V_340 [ V_5 ] ) ;
V_319 |= V_5 ;
V_5 = 0 ;
for ( V_6 = 0 ; V_6 < F_4 ( V_341 ) ; V_6 ++ ) {
V_320 = ( V_4 -> V_18 [ V_83 ] * 10 / V_341 [ V_6 ] ) - V_321 ;
if ( V_320 < 0 )
break;
V_5 = V_6 ;
}
V_321 = V_4 -> V_18 [ V_83 ] * 10 / V_341 [ V_5 ] ;
F_7 ( V_258 -> V_44 , L_47 ,
V_341 [ V_5 ] , V_321 ) ;
V_317 |= V_5 << V_342 ;
V_318 = V_321 / F_72 ( V_312 ) ;
if ( ! V_318 ) {
F_75 ( V_258 -> V_44 , L_48 ,
V_321 ) ;
return - V_42 ;
}
F_7 ( V_258 -> V_44 , L_49 ,
V_318 , V_321 / V_318 ) ;
F_5 ( V_2 , V_285 , V_343 , V_222 ) ;
F_5 ( V_2 , V_313 , V_339 , V_223 ) ;
F_5 ( V_2 , V_314 , V_344 , V_317 ) ;
F_5 ( V_2 , V_315 , V_345 ,
V_318 ) ;
F_5 ( V_2 , V_316 , V_346 |
V_347 , V_319 ) ;
if ( V_310 -> V_324 == V_325 ) {
switch ( V_258 -> V_83 ) {
case 1 :
V_4 -> V_98 [ 0 ] = F_72 ( V_312 ) ;
F_18 ( V_2 , 0 ) ;
F_18 ( V_2 , 1 ) ;
break;
case 2 :
V_4 -> V_98 [ 1 ] = F_72 ( V_312 ) ;
F_18 ( V_2 , 2 ) ;
break;
}
}
return 0 ;
}
static int F_76 ( struct V_309 * V_310 ,
struct V_311 * V_312 ,
struct V_257 * V_258 )
{
struct V_1 * V_2 = V_258 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_158 = V_4 -> V_4 ;
int V_285 ;
int V_222 = 0 ;
switch ( V_258 -> V_83 ) {
case 3 :
switch ( V_158 -> type ) {
case V_272 :
case V_165 :
V_285 = V_306 ;
break;
default:
return 0 ;
}
default:
return 0 ;
}
switch ( F_73 ( V_312 ) ) {
case V_333 :
break;
case V_334 :
V_222 |= 0x20 ;
break;
case V_335 :
V_222 |= 0x40 ;
break;
case V_336 :
V_222 |= 0x60 ;
break;
default:
return - V_42 ;
}
return F_5 ( V_2 , V_285 , V_343 , V_222 ) ;
}
static void F_77 ( struct V_309 * V_310 ,
struct V_257 * V_258 )
{
struct V_1 * V_2 = V_258 -> V_2 ;
int V_316 = 0 ;
switch ( V_258 -> V_83 ) {
case 1 :
V_316 = V_323 ;
break;
case 2 :
V_316 = V_330 ;
break;
default:
break;
}
if ( V_316 && ! V_258 -> V_348 && ! V_258 -> V_349 )
F_5 ( V_2 , V_316 ,
V_346 |
V_347 , 0x9 ) ;
}
static int F_78 ( struct V_257 * V_350 , int V_351 )
{
struct V_1 * V_2 = V_350 -> V_2 ;
int V_352 ;
int V_53 ;
switch ( V_350 -> V_83 ) {
case 1 :
V_352 = V_353 ;
break;
case 2 :
V_352 = V_354 ;
break;
default:
return - V_42 ;
}
if ( V_351 )
V_53 = V_355 ;
else
V_53 = 0 ;
F_5 ( V_2 , V_352 , V_355 , V_53 ) ;
return 0 ;
}
static int F_79 ( struct V_257 * V_350 , int V_356 )
{
struct V_1 * V_2 = V_350 -> V_2 ;
int V_53 , V_8 , V_63 ;
switch ( V_350 -> V_83 ) {
case 1 :
V_53 = V_287 ;
V_63 = V_357 ;
break;
case 2 :
V_53 = V_288 ;
V_63 = V_358 ;
break;
case 3 :
V_53 = V_359 ;
V_63 = V_360 ;
break;
default:
return - V_42 ;
}
if ( V_356 )
V_8 = V_63 ;
else
V_8 = 0 ;
return F_5 ( V_2 , V_53 , V_63 , V_8 ) ;
}
static int F_80 ( struct V_257 * V_258 )
{
struct V_1 * V_2 = V_258 -> V_2 ;
F_5 ( V_2 , V_361 ,
V_362 | V_363 , 0 ) ;
F_5 ( V_2 , V_364 ,
V_362 | V_363 , 0 ) ;
F_5 ( V_2 , V_365 ,
V_362 | V_363 , 0 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_158 = V_4 -> V_4 ;
int V_6 , V_64 ;
switch ( V_158 -> type ) {
case V_164 :
F_5 ( V_2 , V_366 , V_367 , 0 ) ;
break;
case V_272 :
F_5 ( V_2 , V_106 ,
V_107 , 0 ) ;
case V_165 :
F_5 ( V_2 , V_29 ,
V_368 , 0 ) ;
break;
}
for ( V_6 = 0 ; V_6 < F_4 ( V_4 -> V_39 ) ; V_6 ++ ) {
memcpy ( & V_4 -> V_369 [ V_6 ] , & V_4 -> V_39 [ V_6 ] ,
sizeof( struct V_370 ) ) ;
V_64 = F_56 ( V_2 , V_6 + 1 , 0 , 0 , 0 ) ;
if ( V_64 < 0 )
F_60 ( V_2 -> V_44 , L_50 ,
V_6 + 1 , V_64 ) ;
}
F_65 ( V_2 , V_279 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_158 = V_4 -> V_4 ;
int V_6 , V_64 ;
unsigned int V_8 , V_63 ;
if ( V_4 -> V_250 < 4 ) {
V_64 = F_83 ( V_158 -> V_371 ,
V_179 , & V_8 ) ;
V_2 -> V_372 = 1 ;
V_63 = V_373 | V_374 |
V_375 | V_376 ;
V_8 &= V_63 ;
F_5 ( V_2 , V_179 ,
V_63 , V_8 ) ;
V_2 -> V_372 = 0 ;
}
for ( V_6 = 0 ; V_6 < F_4 ( V_4 -> V_39 ) ; V_6 ++ ) {
if ( ! V_4 -> V_369 [ V_6 ] . V_40 )
continue;
V_64 = F_56 ( V_2 , V_6 + 1 ,
V_4 -> V_369 [ V_6 ] . V_220 ,
V_4 -> V_369 [ V_6 ] . V_234 ,
V_4 -> V_369 [ V_6 ] . V_40 ) ;
if ( V_64 < 0 )
F_60 ( V_2 -> V_44 , L_51 ,
V_6 + 1 , V_64 ) ;
}
switch ( V_158 -> type ) {
case V_164 :
if ( V_4 -> V_377 [ 0 ] . V_378 || V_4 -> V_377 [ 1 ] . V_378 )
F_5 ( V_2 , V_366 ,
V_367 , V_367 ) ;
break;
case V_272 :
if ( V_4 -> V_22 && V_4 -> V_13 ) {
F_5 ( V_2 , V_106 ,
V_107 ,
V_111 ) ;
break;
}
break;
case V_165 :
if ( V_4 -> V_13 )
F_5 ( V_2 , V_29 ,
V_368 , V_368 ) ;
break;
}
return 0 ;
}
static void F_84 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_71 * V_19 = V_4 -> V_19 ;
struct V_379 V_380 [] = {
F_85 ( L_8 ,
V_4 -> V_381 ,
F_21 ,
F_20 ) ,
F_85 ( L_9 ,
V_4 -> V_381 ,
F_21 ,
F_20 ) ,
F_85 ( L_10 ,
V_4 -> V_381 ,
F_21 ,
F_20 ) ,
} ;
int V_64 , V_6 , V_382 ;
const char * * V_383 ;
V_4 -> V_92 = 0 ;
V_4 -> V_97 = NULL ;
for ( V_6 = 0 ; V_6 < V_19 -> V_95 ; V_6 ++ ) {
for ( V_382 = 0 ; V_382 < V_4 -> V_92 ; V_382 ++ ) {
if ( strcmp ( V_19 -> V_96 [ V_6 ] . V_55 ,
V_4 -> V_97 [ V_382 ] ) == 0 )
break;
}
if ( V_382 != V_4 -> V_92 )
continue;
V_383 = F_86 ( V_4 -> V_97 ,
sizeof( char * ) *
( V_4 -> V_92 + 1 ) ,
V_384 ) ;
if ( V_383 == NULL )
continue;
V_383 [ V_4 -> V_92 ] =
V_19 -> V_96 [ V_6 ] . V_55 ;
V_4 -> V_92 ++ ;
V_4 -> V_97 = V_383 ;
}
F_7 ( V_2 -> V_44 , L_52 ,
V_4 -> V_92 ) ;
V_4 -> V_381 . V_385 = V_4 -> V_92 ;
V_4 -> V_381 . V_386 = V_4 -> V_97 ;
V_64 = F_87 ( V_4 -> V_2 , V_380 ,
F_4 ( V_380 ) ) ;
if ( V_64 != 0 )
F_75 ( V_4 -> V_2 -> V_44 ,
L_53 , V_64 ) ;
}
static void F_88 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_71 * V_19 = V_4 -> V_19 ;
int V_64 , V_6 ;
if ( ! V_19 )
return;
F_89 ( V_2 , V_19 -> V_387 ,
V_19 -> V_388 ,
V_19 -> V_389 ,
V_19 -> V_390 ,
V_19 -> V_391 ,
V_19 -> V_392 ,
V_19 -> V_393 ,
V_19 -> V_394 ) ;
F_7 ( V_2 -> V_44 , L_54 , V_19 -> V_85 ) ;
if ( V_19 -> V_85 ) {
struct V_379 V_380 [] = {
F_85 ( L_4 , V_4 -> V_395 ,
F_17 , F_16 ) ,
F_85 ( L_5 , V_4 -> V_395 ,
F_17 , F_16 ) ,
F_85 ( L_6 , V_4 -> V_395 ,
F_17 , F_16 ) ,
} ;
V_4 -> V_396 = F_90 ( V_4 -> V_2 -> V_44 ,
sizeof( char * ) * V_19 -> V_85 , V_384 ) ;
if ( ! V_4 -> V_396 ) {
F_75 ( V_4 -> V_2 -> V_44 ,
L_55 ,
V_19 -> V_85 ) ;
return;
}
for ( V_6 = 0 ; V_6 < V_19 -> V_85 ; V_6 ++ )
V_4 -> V_396 [ V_6 ] = V_19 -> V_81 [ V_6 ] . V_55 ;
V_4 -> V_395 . V_385 = V_19 -> V_85 ;
V_4 -> V_395 . V_386 = V_4 -> V_396 ;
V_64 = F_87 ( V_4 -> V_2 , V_380 ,
F_4 ( V_380 ) ) ;
if ( V_64 != 0 )
F_75 ( V_4 -> V_2 -> V_44 ,
L_56 , V_64 ) ;
for ( V_6 = 0 ; V_6 < V_397 ; V_6 ++ )
F_14 ( V_2 , V_6 ) ;
}
F_7 ( V_2 -> V_44 , L_57 ,
V_19 -> V_95 ) ;
if ( V_19 -> V_95 )
F_84 ( V_4 ) ;
else
F_87 ( V_4 -> V_2 , V_398 ,
F_4 ( V_398 ) ) ;
for ( V_6 = 0 ; V_6 < F_4 ( V_19 -> V_399 ) ; V_6 ++ ) {
if ( V_19 -> V_399 [ V_6 ] ) {
F_91 ( V_2 , V_273 + V_6 ,
V_19 -> V_399 [ V_6 ] & 0xffff ) ;
}
}
}
int F_92 ( struct V_1 * V_2 , struct V_400 * V_378 ,
int V_399 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_401 * V_377 ;
struct V_4 * V_158 = V_4 -> V_4 ;
int V_53 , V_64 ;
if ( V_158 -> type != V_164 ) {
F_60 ( V_2 -> V_44 , L_58 ) ;
return - V_42 ;
}
switch ( V_399 ) {
case 1 :
V_377 = & V_4 -> V_377 [ 0 ] ;
if ( V_378 )
V_64 = F_69 ( & V_2 -> V_49 ,
L_59 ) ;
else
V_64 = F_68 ( & V_2 -> V_49 ,
L_59 ) ;
break;
case 2 :
V_377 = & V_4 -> V_377 [ 1 ] ;
if ( V_378 )
V_64 = F_69 ( & V_2 -> V_49 ,
L_59 ) ;
else
V_64 = F_68 ( & V_2 -> V_49 ,
L_59 ) ;
break;
default:
F_60 ( V_2 -> V_44 , L_60 , V_399 ) ;
return - V_42 ;
}
if ( V_64 != 0 )
F_60 ( V_2 -> V_44 , L_61 ,
V_399 , V_64 ) ;
F_7 ( V_2 -> V_44 , L_62 ,
V_399 , V_378 ) ;
V_377 -> V_378 = V_378 ;
V_377 -> V_402 = true ;
if ( V_4 -> V_377 [ 0 ] . V_378 || V_4 -> V_377 [ 1 ] . V_378 )
V_53 = V_367 ;
else
V_53 = 0 ;
F_5 ( V_2 , V_366 , V_367 , V_53 ) ;
F_9 ( & V_2 -> V_49 ) ;
return 0 ;
}
static T_3 F_93 ( int V_253 , void * V_254 )
{
struct V_3 * V_403 = V_254 ;
struct V_1 * V_2 = V_403 -> V_2 ;
int V_53 ;
int V_404 ;
#ifndef F_94
F_95 ( F_96 ( V_2 -> V_44 ) ) ;
#endif
V_53 = F_3 ( V_2 , V_405 ) ;
if ( V_53 < 0 ) {
F_75 ( V_2 -> V_44 , L_63 ,
V_53 ) ;
return V_256 ;
}
F_7 ( V_2 -> V_44 , L_64 , V_53 ) ;
V_404 = 0 ;
if ( V_53 & V_406 ) {
if ( V_403 -> V_377 [ 0 ] . V_402 )
V_404 = V_407 ;
}
if ( V_53 & V_408 ) {
if ( V_403 -> V_377 [ 0 ] . V_402 )
V_404 = V_409 ;
else
V_404 |= V_410 ;
}
if ( V_404 )
V_403 -> V_377 [ 0 ] . V_402 = false ;
else
V_403 -> V_377 [ 0 ] . V_402 = true ;
F_97 ( V_403 -> V_377 [ 0 ] . V_378 , V_404 ,
V_407 | V_410 ) ;
V_404 = 0 ;
if ( V_53 & V_411 ) {
if ( V_403 -> V_377 [ 1 ] . V_402 )
V_404 = V_407 ;
}
if ( V_53 & V_412 ) {
if ( V_403 -> V_377 [ 1 ] . V_402 )
V_404 = V_409 ;
else
V_404 |= V_410 ;
}
if ( V_404 )
V_403 -> V_377 [ 1 ] . V_402 = false ;
else
V_403 -> V_377 [ 1 ] . V_402 = true ;
F_97 ( V_403 -> V_377 [ 1 ] . V_378 , V_404 ,
V_407 | V_410 ) ;
return V_256 ;
}
static void V_14 ( T_1 V_413 , void * V_254 )
{
struct V_1 * V_2 = V_254 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_404 ;
F_7 ( V_2 -> V_44 , L_65 , V_413 ) ;
if ( ! ( V_413 & V_414 ) ) {
if ( ! V_4 -> V_22 ) {
F_7 ( V_2 -> V_44 , L_66 ) ;
V_4 -> V_15 = false ;
V_4 -> V_109 = true ;
F_1 ( V_2 ) ;
F_97 ( V_4 -> V_377 [ 0 ] . V_378 , 0 ,
V_4 -> V_415 |
V_407 ) ;
}
return;
}
if ( V_4 -> V_109 && ( V_413 & 0x600 ) ) {
F_7 ( V_2 -> V_44 , L_67 ) ;
V_4 -> V_109 = false ;
V_4 -> V_15 = true ;
F_1 ( V_2 ) ;
F_97 ( V_4 -> V_377 [ 0 ] . V_378 , V_407 ,
V_407 ) ;
}
if ( V_4 -> V_109 && V_413 & 0xfc ) {
F_7 ( V_2 -> V_44 , L_68 ) ;
V_4 -> V_109 = false ;
F_1 ( V_2 ) ;
F_97 ( V_4 -> V_377 [ 0 ] . V_378 , V_409 ,
V_407 ) ;
if ( V_4 -> V_22 ) {
F_24 ( & V_4 -> V_108 ) ;
F_5 ( V_2 , V_29 ,
V_368 , 0 ) ;
F_22 ( V_2 ,
V_111 ) ;
F_25 ( & V_4 -> V_108 ) ;
if ( V_4 -> V_19 -> V_416 ) {
F_24 ( & V_2 -> V_417 ) ;
F_68 ( & V_2 -> V_49 ,
L_69 ) ;
F_9 ( & V_2 -> V_49 ) ;
F_25 ( & V_2 -> V_417 ) ;
}
}
}
if ( V_4 -> V_15 ) {
V_404 = 0 ;
if ( V_413 & 0x4 )
V_404 |= V_410 ;
if ( V_413 & 0x8 )
V_404 |= V_418 ;
if ( V_413 & 0x10 )
V_404 |= V_419 ;
if ( V_413 & 0x20 )
V_404 |= V_420 ;
if ( V_413 & 0x40 )
V_404 |= V_421 ;
if ( V_413 & 0x80 )
V_404 |= V_422 ;
F_97 ( V_4 -> V_377 [ 0 ] . V_378 , V_404 ,
V_4 -> V_415 ) ;
}
}
static T_3 F_98 ( int V_253 , void * V_254 )
{
struct V_3 * V_4 = V_254 ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_53 ;
bool V_423 ;
F_24 ( & V_4 -> V_108 ) ;
V_53 = F_3 ( V_2 , V_424 ) ;
if ( V_53 < 0 ) {
F_75 ( V_2 -> V_44 , L_70 , V_53 ) ;
F_25 ( & V_4 -> V_108 ) ;
return V_425 ;
}
F_7 ( V_2 -> V_44 , L_71 , V_53 ) ;
V_423 = V_53 & V_426 ;
if ( V_423 ) {
F_7 ( V_2 -> V_44 , L_72 ) ;
F_5 ( V_2 , V_275 ,
V_427 , 0 ) ;
F_5 ( V_2 , V_424 ,
V_428 , 0 ) ;
V_4 -> V_109 = true ;
F_22 ( V_2 , V_110 ) ;
F_5 ( V_2 , V_29 ,
V_368 , V_368 ) ;
} else {
F_7 ( V_2 -> V_44 , L_73 ) ;
F_5 ( V_2 , V_275 ,
V_427 , V_427 ) ;
F_5 ( V_2 , V_424 ,
V_428 , V_428 ) ;
V_4 -> V_109 = false ;
V_4 -> V_15 = false ;
F_5 ( V_2 , V_29 ,
V_368 , 0 ) ;
F_22 ( V_2 , V_111 ) ;
}
F_25 ( & V_4 -> V_108 ) ;
if ( V_4 -> V_19 -> V_416 ) {
F_24 ( & V_2 -> V_417 ) ;
if ( V_423 )
F_69 ( & V_2 -> V_49 ,
L_69 ) ;
else
F_68 ( & V_2 -> V_49 , L_69 ) ;
F_9 ( & V_2 -> V_49 ) ;
F_25 ( & V_2 -> V_417 ) ;
}
if ( V_423 )
F_97 ( V_4 -> V_377 [ 0 ] . V_378 ,
V_429 , V_429 ) ;
else
F_97 ( V_4 -> V_377 [ 0 ] . V_378 , 0 ,
V_429 | V_407 |
V_4 -> V_415 ) ;
return V_256 ;
}
int F_99 ( struct V_1 * V_2 , struct V_400 * V_378 ,
T_4 V_430 , void * V_431 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_158 = V_4 -> V_4 ;
T_1 V_432 ;
switch ( V_158 -> type ) {
case V_272 :
case V_165 :
break;
default:
return - V_42 ;
}
if ( V_378 ) {
if ( ! V_430 ) {
F_7 ( V_2 -> V_44 , L_74 ) ;
V_430 = V_14 ;
V_431 = V_2 ;
}
F_69 ( & V_2 -> V_49 , L_75 ) ;
F_9 ( & V_2 -> V_49 ) ;
V_4 -> V_377 [ 0 ] . V_378 = V_378 ;
V_4 -> V_13 = V_430 ;
V_4 -> V_433 = V_431 ;
V_4 -> V_109 = true ;
V_4 -> V_15 = false ;
F_1 ( V_2 ) ;
if ( V_4 -> V_19 -> V_432 )
V_432 = V_4 -> V_19 -> V_432 ;
else
V_432 = 0x41 ;
V_4 -> V_415 = V_410 | V_418 |
V_419 | V_420 |
V_421 | V_422 ;
F_5 ( V_2 , V_434 ,
V_435 , V_432 ) ;
F_31 ( V_2 -> V_49 . V_277 > V_278 ) ;
if ( V_4 -> V_22 ) {
F_5 ( V_2 , V_275 ,
V_427 ,
V_427 ) ;
F_5 ( V_2 , V_436 ,
V_437 , 0 ) ;
F_22 ( V_2 ,
V_111 ) ;
} else {
F_5 ( V_2 , V_29 ,
V_368 , V_368 ) ;
}
} else {
F_5 ( V_2 , V_29 ,
V_368 , 0 ) ;
F_22 ( V_2 , V_105 ) ;
F_68 ( & V_2 -> V_49 , L_75 ) ;
F_9 ( & V_2 -> V_49 ) ;
}
return 0 ;
}
static T_3 F_100 ( int V_253 , void * V_254 )
{
struct V_3 * V_4 = V_254 ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_53 , V_438 ;
if ( ! ( F_3 ( V_2 , V_29 ) & V_368 ) )
return V_256 ;
V_438 = 10 ;
do {
V_53 = F_3 ( V_2 , V_439 ) ;
if ( V_53 < 0 ) {
F_75 ( V_2 -> V_44 ,
L_76 ,
V_53 ) ;
return V_425 ;
}
if ( ! ( V_53 & V_440 ) ) {
F_7 ( V_2 -> V_44 , L_77 ) ;
goto V_40;
}
if ( ! ( V_53 & V_414 ) || ( V_53 & V_441 ) )
break;
F_32 ( 1 ) ;
} while ( V_438 -- );
if ( V_438 == 0 )
F_60 ( V_2 -> V_44 , L_78 ) ;
#ifndef F_94
F_95 ( F_96 ( V_2 -> V_44 ) ) ;
#endif
if ( V_4 -> V_13 )
V_4 -> V_13 ( V_53 , V_4 -> V_433 ) ;
else
F_60 ( V_2 -> V_44 , L_79 ) ;
V_40:
return V_256 ;
}
static T_3 F_101 ( int V_253 , void * V_254 )
{
struct V_1 * V_2 = V_254 ;
F_75 ( V_2 -> V_44 , L_80 ) ;
return V_256 ;
}
static T_3 F_102 ( int V_253 , void * V_254 )
{
struct V_1 * V_2 = V_254 ;
F_75 ( V_2 -> V_44 , L_81 ) ;
return V_256 ;
}
static T_3 F_103 ( int V_253 , void * V_254 )
{
struct V_1 * V_2 = V_254 ;
F_104 ( V_2 -> V_44 , L_82 ) ;
return V_256 ;
}
static int F_105 ( struct V_1 * V_2 )
{
struct V_4 * V_158 = F_106 ( V_2 -> V_44 -> V_442 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_443 * V_49 = & V_2 -> V_49 ;
unsigned int V_53 ;
int V_64 , V_6 ;
V_4 -> V_2 = V_2 ;
V_2 -> V_159 = V_158 -> V_371 ;
F_107 ( V_2 , 16 , 16 , V_444 ) ;
V_4 -> V_2 = V_2 ;
F_108 ( & V_4 -> V_108 ) ;
for ( V_6 = 0 ; V_6 < F_4 ( V_4 -> V_249 ) ; V_6 ++ )
F_109 ( & V_4 -> V_249 [ V_6 ] ) ;
if ( V_4 -> V_19 && V_4 -> V_19 -> V_445 )
V_4 -> V_445 = V_4 -> V_19 -> V_445 ;
else if ( V_4 -> V_19 && V_4 -> V_19 -> V_446 )
V_4 -> V_445 = V_4 -> V_19 -> V_446 +
V_447 ;
F_110 ( V_2 -> V_44 ) ;
F_111 ( V_2 -> V_44 ) ;
V_2 -> V_49 . V_448 = 1 ;
V_4 -> V_250 = F_3 ( V_2 , V_449 ) ;
switch ( V_158 -> type ) {
case V_164 :
if ( ! V_4 -> V_19 -> V_387 ||
! V_4 -> V_19 -> V_388 )
V_2 -> V_49 . V_448 = 0 ;
switch ( V_4 -> V_250 ) {
case 2 :
case 3 :
V_4 -> V_132 . V_450 = - 5 ;
V_4 -> V_132 . V_451 = - 5 ;
V_4 -> V_132 . V_452 = 1 ;
V_4 -> V_132 . V_453 = 1 ;
V_4 -> V_132 . V_454 = 1 ;
break;
default:
V_4 -> V_132 . V_453 = 2 ;
break;
}
break;
case V_165 :
V_4 -> V_132 . V_453 = 1 ;
V_4 -> V_132 . V_452 = 1 ;
break;
case V_272 :
V_4 -> V_132 . V_453 = 2 ;
V_4 -> V_132 . V_455 = 1 ;
V_4 -> V_132 . V_452 = 1 ;
V_4 -> V_132 . V_456 = true ;
switch ( V_4 -> V_250 ) {
case 0 :
case 1 :
case 2 :
case 3 :
V_4 -> V_132 . V_450 = - 9 ;
V_4 -> V_132 . V_451 = - 7 ;
break;
default:
break;
}
F_5 ( V_2 , V_457 ,
V_458 , V_458 ) ;
break;
default:
break;
}
F_112 ( V_4 -> V_4 , V_459 ,
F_101 , L_83 , V_2 ) ;
F_112 ( V_4 -> V_4 , V_460 ,
F_102 , L_84 , V_2 ) ;
F_112 ( V_4 -> V_4 , V_461 ,
F_103 , L_85 , V_2 ) ;
V_64 = F_112 ( V_4 -> V_4 , V_462 ,
V_463 , L_86 ,
& V_4 -> V_132 ) ;
if ( V_64 == 0 )
V_4 -> V_132 . V_464 = true ;
switch ( V_158 -> type ) {
case V_164 :
if ( V_4 -> V_445 ) {
V_64 = F_113 ( V_4 -> V_445 , NULL ,
F_93 ,
V_465 ,
L_87 ,
V_4 ) ;
if ( V_64 != 0 )
F_60 ( V_2 -> V_44 ,
L_88 ,
V_64 ) ;
}
V_64 = F_112 ( V_4 -> V_4 ,
V_466 ,
F_93 , L_89 ,
V_4 ) ;
if ( V_64 != 0 )
F_60 ( V_2 -> V_44 ,
L_90 ,
V_64 ) ;
V_64 = F_112 ( V_4 -> V_4 ,
V_467 ,
F_93 , L_91 ,
V_4 ) ;
if ( V_64 != 0 )
F_60 ( V_2 -> V_44 ,
L_92 ,
V_64 ) ;
V_64 = F_112 ( V_4 -> V_4 ,
V_468 ,
F_93 , L_93 ,
V_4 ) ;
if ( V_64 != 0 )
F_60 ( V_2 -> V_44 ,
L_94 ,
V_64 ) ;
break;
case V_165 :
case V_272 :
if ( V_4 -> V_445 ) {
V_64 = F_113 ( V_4 -> V_445 , NULL ,
F_100 ,
V_465 ,
L_95 ,
V_4 ) ;
if ( V_64 != 0 )
F_60 ( V_2 -> V_44 ,
L_96 ,
V_64 ) ;
}
}
switch ( V_158 -> type ) {
case V_272 :
if ( V_4 -> V_250 > 1 ) {
V_64 = F_112 ( V_4 -> V_4 ,
F_114 ( 6 ) ,
F_98 , L_97 ,
V_4 ) ;
if ( V_64 == 0 )
V_4 -> V_22 = true ;
}
break;
default:
break;
}
V_4 -> V_252 = true ;
for ( V_6 = 0 ; V_6 < F_4 ( V_4 -> V_249 ) ; V_6 ++ ) {
V_64 = F_112 ( V_4 -> V_4 ,
V_469 + V_6 ,
F_61 , L_98 ,
& V_4 -> V_249 [ V_6 ] ) ;
if ( V_64 != 0 )
V_4 -> V_252 = false ;
}
F_29 ( V_2 -> V_44 ) ;
V_64 = F_83 ( V_158 -> V_371 , V_470 , & V_53 ) ;
if ( V_64 < 0 ) {
F_75 ( V_2 -> V_44 , L_99 , V_64 ) ;
goto V_471;
}
if ( ( V_53 & V_472 ) != V_473 ) {
V_4 -> V_326 [ 0 ] = 1 ;
V_474 [ 0 ] . V_475 = 1 ;
} else {
V_4 -> V_326 [ 0 ] = 0 ;
}
V_64 = F_83 ( V_158 -> V_371 , V_476 , & V_53 ) ;
if ( V_64 < 0 ) {
F_75 ( V_2 -> V_44 , L_100 , V_64 ) ;
goto V_471;
}
if ( ( V_53 & V_472 ) != V_473 ) {
V_4 -> V_326 [ 1 ] = 1 ;
V_474 [ 1 ] . V_475 = 1 ;
} else {
V_4 -> V_326 [ 1 ] = 0 ;
}
F_34 ( V_2 -> V_44 ) ;
F_5 ( V_2 , V_477 ,
V_478 , V_478 ) ;
F_5 ( V_2 , V_479 ,
V_478 , V_478 ) ;
F_5 ( V_2 , V_480 ,
V_481 , V_481 ) ;
F_5 ( V_2 , V_482 ,
V_481 , V_481 ) ;
F_5 ( V_2 , V_483 ,
V_484 , V_484 ) ;
F_5 ( V_2 , V_485 ,
V_484 , V_484 ) ;
F_5 ( V_2 , V_486 ,
V_487 , V_487 ) ;
F_5 ( V_2 , V_488 ,
V_487 , V_487 ) ;
F_5 ( V_2 , V_489 ,
V_490 , V_490 ) ;
F_5 ( V_2 , V_491 ,
V_490 , V_490 ) ;
F_5 ( V_2 , V_492 ,
V_493 , V_490 ) ;
F_5 ( V_2 , V_494 ,
V_493 , V_490 ) ;
F_5 ( V_2 , V_495 ,
V_496 , V_496 ) ;
F_5 ( V_2 , V_497 ,
V_496 , V_496 ) ;
F_5 ( V_2 , V_498 ,
V_499 , V_499 ) ;
F_5 ( V_2 , V_500 ,
V_499 , V_499 ) ;
F_5 ( V_2 , V_501 ,
1 << V_502 ,
1 << V_502 ) ;
F_5 ( V_2 , V_503 ,
1 << V_504 ,
1 << V_504 ) ;
F_5 ( V_2 , V_505 ,
1 << V_506 ,
1 << V_506 ) ;
switch ( V_158 -> type ) {
case V_164 :
case V_165 :
F_5 ( V_2 , V_168 ,
V_507 , V_507 ) ;
break;
default:
break;
}
switch ( V_158 -> type ) {
case V_165 :
case V_272 :
F_5 ( V_2 , V_273 ,
V_274 , V_274 ) ;
F_5 ( V_2 , V_275 ,
V_276 , V_276 ) ;
break;
default:
break;
}
F_36 ( V_2 ) ;
F_88 ( V_4 ) ;
F_115 ( V_2 ) ;
F_87 ( V_2 , V_508 ,
F_4 ( V_508 ) ) ;
F_116 ( V_49 , V_509 ,
F_4 ( V_509 ) ) ;
switch ( V_158 -> type ) {
case V_164 :
F_116 ( V_49 , V_510 ,
F_4 ( V_510 ) ) ;
if ( V_4 -> V_250 < 4 ) {
F_116 ( V_49 , V_511 ,
F_4 ( V_511 ) ) ;
F_116 ( V_49 , V_512 ,
F_4 ( V_512 ) ) ;
F_116 ( V_49 , V_513 ,
F_4 ( V_513 ) ) ;
} else {
F_116 ( V_49 , V_514 ,
F_4 ( V_514 ) ) ;
F_116 ( V_49 , V_515 ,
F_4 ( V_515 ) ) ;
F_116 ( V_49 , V_516 ,
F_4 ( V_516 ) ) ;
}
break;
case V_165 :
F_87 ( V_2 , V_517 ,
F_4 ( V_517 ) ) ;
F_116 ( V_49 , V_518 ,
F_4 ( V_518 ) ) ;
if ( V_4 -> V_250 < 1 ) {
F_116 ( V_49 , V_511 ,
F_4 ( V_511 ) ) ;
F_116 ( V_49 , V_512 ,
F_4 ( V_512 ) ) ;
F_116 ( V_49 , V_513 ,
F_4 ( V_513 ) ) ;
} else {
F_116 ( V_49 , V_514 ,
F_4 ( V_514 ) ) ;
F_116 ( V_49 , V_515 ,
F_4 ( V_515 ) ) ;
F_116 ( V_49 , V_516 ,
F_4 ( V_516 ) ) ;
}
break;
case V_272 :
F_87 ( V_2 , V_517 ,
F_4 ( V_517 ) ) ;
F_116 ( V_49 , V_518 ,
F_4 ( V_518 ) ) ;
F_116 ( V_49 , V_514 ,
F_4 ( V_514 ) ) ;
F_116 ( V_49 , V_515 ,
F_4 ( V_515 ) ) ;
F_116 ( V_49 , V_516 ,
F_4 ( V_516 ) ) ;
break;
}
F_117 ( V_2 , 0 , 0 ) ;
F_118 ( V_49 , V_519 , F_4 ( V_519 ) ) ;
switch ( V_158 -> type ) {
case V_164 :
F_118 ( V_49 , V_520 ,
F_4 ( V_520 ) ) ;
if ( V_4 -> V_250 < 4 ) {
F_118 ( V_49 , V_521 ,
F_4 ( V_521 ) ) ;
F_118 ( V_49 , V_522 ,
F_4 ( V_522 ) ) ;
} else {
F_118 ( V_49 , V_523 ,
F_4 ( V_523 ) ) ;
}
break;
case V_165 :
if ( V_4 -> V_250 < 1 ) {
F_118 ( V_49 , V_521 ,
F_4 ( V_521 ) ) ;
F_118 ( V_49 , V_522 ,
F_4 ( V_522 ) ) ;
} else {
F_118 ( V_49 , V_523 ,
F_4 ( V_523 ) ) ;
F_118 ( V_49 , V_524 ,
F_4 ( V_524 ) ) ;
}
F_119 ( V_2 ) ;
break;
case V_272 :
F_118 ( V_49 , V_523 ,
F_4 ( V_523 ) ) ;
F_118 ( V_49 , V_524 ,
F_4 ( V_524 ) ) ;
break;
}
return 0 ;
V_471:
if ( V_4 -> V_22 )
F_120 ( V_4 -> V_4 , F_114 ( 6 ) , V_4 ) ;
F_120 ( V_4 -> V_4 , V_468 , V_4 ) ;
F_120 ( V_4 -> V_4 , V_467 , V_4 ) ;
F_120 ( V_4 -> V_4 , V_466 , V_4 ) ;
if ( V_4 -> V_445 )
F_121 ( V_4 -> V_445 , V_4 ) ;
for ( V_6 = 0 ; V_6 < F_4 ( V_4 -> V_249 ) ; V_6 ++ )
F_120 ( V_4 -> V_4 , V_469 + V_6 ,
& V_4 -> V_249 [ V_6 ] ) ;
F_120 ( V_4 -> V_4 , V_462 ,
& V_4 -> V_132 ) ;
F_120 ( V_4 -> V_4 , V_459 , V_2 ) ;
F_120 ( V_4 -> V_4 , V_461 , V_2 ) ;
F_120 ( V_4 -> V_4 , V_460 , V_2 ) ;
return V_64 ;
}
static int F_122 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_158 = V_4 -> V_4 ;
int V_6 ;
F_65 ( V_2 , V_279 ) ;
F_123 ( V_2 -> V_44 ) ;
for ( V_6 = 0 ; V_6 < F_4 ( V_4 -> V_249 ) ; V_6 ++ )
F_120 ( V_4 -> V_4 , V_469 + V_6 ,
& V_4 -> V_249 [ V_6 ] ) ;
F_120 ( V_4 -> V_4 , V_462 ,
& V_4 -> V_132 ) ;
F_120 ( V_4 -> V_4 , V_459 , V_2 ) ;
F_120 ( V_4 -> V_4 , V_461 , V_2 ) ;
F_120 ( V_4 -> V_4 , V_460 , V_2 ) ;
if ( V_4 -> V_22 )
F_120 ( V_4 -> V_4 , F_114 ( 6 ) , V_4 ) ;
switch ( V_158 -> type ) {
case V_164 :
if ( V_4 -> V_445 )
F_121 ( V_4 -> V_445 , V_4 ) ;
F_120 ( V_4 -> V_4 , V_467 ,
V_4 ) ;
F_120 ( V_4 -> V_4 , V_466 ,
V_4 ) ;
F_120 ( V_4 -> V_4 , V_447 ,
V_4 ) ;
break;
case V_272 :
case V_165 :
if ( V_4 -> V_445 )
F_121 ( V_4 -> V_445 , V_4 ) ;
break;
}
if ( V_4 -> V_525 )
F_124 ( V_4 -> V_525 ) ;
if ( V_4 -> V_526 )
F_124 ( V_4 -> V_526 ) ;
if ( V_4 -> V_527 )
F_124 ( V_4 -> V_527 ) ;
F_125 ( V_4 -> V_97 ) ;
return 0 ;
}
static int T_5 F_126 ( struct V_528 * V_529 )
{
struct V_3 * V_4 ;
V_4 = F_90 ( & V_529 -> V_44 , sizeof( struct V_3 ) ,
V_384 ) ;
if ( V_4 == NULL )
return - V_530 ;
F_127 ( V_529 , V_4 ) ;
V_4 -> V_4 = F_106 ( V_529 -> V_44 . V_442 ) ;
V_4 -> V_19 = F_128 ( V_529 -> V_44 . V_442 ) ;
return F_129 ( & V_529 -> V_44 , & V_531 ,
V_474 , F_4 ( V_474 ) ) ;
}
static int T_6 F_130 ( struct V_528 * V_529 )
{
F_131 ( & V_529 -> V_44 ) ;
return 0 ;
}
static int F_132 ( struct V_532 * V_44 )
{
struct V_3 * V_4 = F_106 ( V_44 ) ;
if ( V_4 -> V_22 && ! V_4 -> V_102 )
F_133 ( V_4 -> V_4 -> V_371 , V_106 ,
V_107 ,
V_4 -> V_104 ) ;
return 0 ;
}
static int F_134 ( struct V_532 * V_44 )
{
struct V_3 * V_4 = F_106 ( V_44 ) ;
if ( V_4 -> V_22 && V_4 -> V_13 )
F_133 ( V_4 -> V_4 -> V_371 , V_106 ,
V_107 ,
V_103 ) ;
return 0 ;
}
