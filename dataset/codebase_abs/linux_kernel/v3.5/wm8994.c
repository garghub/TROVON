static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_6 , V_7 , V_8 ;
bool V_9 ;
const struct V_10 * V_11 ;
int V_12 ;
if ( ! ( V_4 -> V_13 && V_4 -> V_13 -> V_14 ) &&
V_4 -> V_15 != V_16 )
return;
V_9 = ! V_4 -> V_17 ;
V_7 = F_3 ( V_2 , V_18 ) ;
if ( V_7 & V_19 )
V_7 = V_4 -> V_20 [ 1 ] ;
else
V_7 = V_4 -> V_20 [ 0 ] ;
if ( V_4 -> V_13 && V_4 -> V_13 -> V_14 ) {
V_11 = V_4 -> V_13 -> V_14 ;
V_12 = V_4 -> V_13 -> V_21 ;
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
F_5 ( V_2 -> V_29 , L_1 ,
V_11 [ V_5 ] . V_25 , V_11 [ V_5 ] . V_27 , V_7 ,
V_9 ? L_2 : L_3 ) ;
F_6 ( V_2 , V_30 ,
V_31 |
V_32 , V_8 ) ;
}
static int F_7 ( struct V_1 * V_2 , int V_33 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_27 ;
int V_34 = 0 ;
int V_35 ;
if ( V_33 )
V_35 = 4 ;
else
V_35 = 0 ;
switch ( V_4 -> V_7 [ V_33 ] ) {
case V_36 :
V_27 = V_4 -> V_37 [ 0 ] ;
break;
case V_38 :
V_34 |= 0x8 ;
V_27 = V_4 -> V_37 [ 1 ] ;
break;
case V_39 :
V_34 |= 0x10 ;
V_27 = V_4 -> V_40 [ 0 ] . V_41 ;
break;
case V_42 :
V_34 |= 0x18 ;
V_27 = V_4 -> V_40 [ 1 ] . V_41 ;
break;
default:
return - V_43 ;
}
if ( V_27 >= 13500000 ) {
V_27 /= 2 ;
V_34 |= V_44 ;
F_5 ( V_2 -> V_29 , L_4 ,
V_33 + 1 , V_27 ) ;
}
V_4 -> V_20 [ V_33 ] = V_27 ;
F_6 ( V_2 , V_45 + V_35 ,
V_46 | V_44 ,
V_34 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_47 , V_48 ;
F_7 ( V_2 , 0 ) ;
F_7 ( V_2 , 1 ) ;
if ( V_4 -> V_20 [ 0 ] == V_4 -> V_20 [ 1 ] ) {
F_1 ( V_2 ) ;
return 0 ;
}
if ( V_4 -> V_20 [ 0 ] < V_4 -> V_20 [ 1 ] )
V_48 = V_19 ;
else
V_48 = 0 ;
V_47 = F_6 ( V_2 , V_18 ,
V_19 , V_48 ) ;
if ( V_47 )
F_9 ( & V_2 -> V_49 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_10 ( struct V_50 * V_51 ,
struct V_50 * V_52 )
{
int V_53 = F_3 ( V_51 -> V_2 , V_18 ) ;
const char * V_54 ;
if ( V_53 & V_19 )
V_54 = L_5 ;
else
V_54 = L_6 ;
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
return - V_43 ;
return F_13 ( V_57 , V_59 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_70 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_71 * V_13 = V_4 -> V_13 ;
int V_72 = V_73 [ V_70 ] ;
int V_74 = V_4 -> V_75 [ V_70 ] ;
int V_76 , V_6 ;
V_76 = F_3 ( V_2 , V_72 ) ;
V_76 &= V_77 | V_78 |
V_79 ;
for ( V_6 = 0 ; V_6 < V_80 ; V_6 ++ )
F_6 ( V_2 , V_72 + V_6 , 0xffff ,
V_13 -> V_81 [ V_74 ] . V_82 [ V_6 ] ) ;
F_6 ( V_2 , V_72 , V_77 |
V_78 |
V_79 , V_76 ) ;
}
static int F_15 ( const char * V_55 )
{
if ( strcmp ( V_55 , L_7 ) == 0 )
return 0 ;
if ( strcmp ( V_55 , L_8 ) == 0 )
return 1 ;
if ( strcmp ( V_55 , L_9 ) == 0 )
return 2 ;
return - V_43 ;
}
static int F_16 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_12 ( V_57 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_71 * V_13 = V_4 -> V_13 ;
int V_70 = F_15 ( V_57 -> V_83 . V_55 ) ;
int V_84 = V_59 -> V_84 . integer . V_84 [ 0 ] ;
if ( V_70 < 0 )
return V_70 ;
if ( V_84 >= V_13 -> V_85 )
return - V_43 ;
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
struct V_71 * V_13 = V_4 -> V_13 ;
int V_72 = V_89 [ V_88 ] ;
int V_90 , V_5 , V_91 , V_76 , V_6 , V_74 ;
if ( ! V_13 || ! V_4 -> V_92 )
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
for ( V_6 = 0 ; V_6 < V_13 -> V_95 ; V_6 ++ ) {
if ( strcmp ( V_13 -> V_96 [ V_6 ] . V_55 ,
V_4 -> V_97 [ V_74 ] ) == 0 &&
abs ( V_13 -> V_96 [ V_6 ] . V_27
- V_4 -> V_98 [ V_90 ] ) < V_91 ) {
V_5 = V_6 ;
V_91 = abs ( V_13 -> V_96 [ V_6 ] . V_27
- V_4 -> V_98 [ V_90 ] ) ;
}
}
F_5 ( V_2 -> V_29 , L_10 ,
V_88 ,
V_13 -> V_96 [ V_5 ] . V_55 ,
V_13 -> V_96 [ V_5 ] . V_27 ,
V_4 -> V_98 [ V_90 ] ) ;
V_76 = F_3 ( V_2 , V_72 ) ;
V_76 &= V_99 ;
for ( V_6 = 0 ; V_6 < V_100 ; V_6 ++ )
F_6 ( V_2 , V_72 + V_6 , 0xffff ,
V_13 -> V_96 [ V_5 ] . V_82 [ V_6 ] ) ;
F_6 ( V_2 , V_72 , V_99 , V_76 ) ;
}
static int F_19 ( const char * V_55 )
{
if ( strcmp ( V_55 , L_11 ) == 0 )
return 0 ;
if ( strcmp ( V_55 , L_12 ) == 0 )
return 1 ;
if ( strcmp ( V_55 , L_13 ) == 0 )
return 2 ;
return - V_43 ;
}
static int F_20 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_12 ( V_57 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_71 * V_13 = V_4 -> V_13 ;
int V_88 = F_19 ( V_57 -> V_83 . V_55 ) ;
int V_84 = V_59 -> V_84 . integer . V_84 [ 0 ] ;
if ( V_88 < 0 )
return V_88 ;
if ( V_84 >= V_13 -> V_95 )
return - V_43 ;
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
if ( ! V_4 -> V_22 || ! V_4 -> V_15 )
return;
if ( V_4 -> V_102 )
V_101 = V_103 ;
if ( V_101 == V_4 -> V_104 )
return;
V_4 -> V_104 = V_101 ;
if ( V_101 != V_105 )
V_101 = V_103 ;
F_6 ( V_2 , V_106 ,
V_107 , V_101 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_24 ( & V_4 -> V_108 ) ;
V_4 -> V_102 ++ ;
F_5 ( V_2 -> V_29 , L_14 ,
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
F_5 ( V_2 -> V_29 , L_15 ,
V_4 -> V_102 ) ;
if ( V_4 -> V_102 == 0 ) {
if ( V_4 -> V_17 || V_4 -> V_109 )
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
F_29 ( V_2 -> V_29 ) ;
V_4 -> V_116 ++ ;
F_5 ( V_2 -> V_29 , L_16 ,
V_4 -> V_116 ) ;
if ( V_4 -> V_116 == 1 ) {
F_6 ( V_2 , V_117 ,
V_118 |
V_119 , 0 ) ;
F_30 ( V_2 ) ;
switch ( V_4 -> V_120 ) {
default:
F_31 ( NULL == L_17 ) ;
case V_121 :
F_6 ( V_2 , V_106 ,
V_122 |
V_123 |
V_124 |
V_125 |
V_126 ,
V_122 |
V_124 |
V_125 |
( 0x3 << V_127 ) ) ;
F_6 ( V_2 , V_128 ,
V_129 |
V_130 ,
V_129 | 0x2 ) ;
F_32 ( 50 ) ;
F_6 ( V_2 , V_106 ,
V_126 |
V_122 ,
0 ) ;
break;
case V_131 :
F_6 ( V_2 , V_106 ,
V_122 |
V_123 |
V_124 |
V_125 |
V_126 ,
V_122 |
V_124 |
V_125 |
( 0x2 << V_127 ) ) ;
F_6 ( V_2 , V_128 ,
V_129 |
V_130 ,
V_129 | 0x2 ) ;
F_32 ( 400 ) ;
F_6 ( V_2 , V_106 ,
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
F_5 ( V_2 -> V_29 , L_18 ,
V_4 -> V_116 ) ;
if ( V_4 -> V_116 == 0 ) {
if ( V_4 -> V_132 . V_133 )
F_6 ( V_2 , V_134 ,
V_135 |
V_136 ,
V_135 |
V_136 ) ;
if ( V_4 -> V_132 . V_137 )
F_6 ( V_2 , V_134 ,
V_138 |
V_139 ,
V_138 |
V_139 ) ;
F_6 ( V_2 , V_106 ,
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
F_6 ( V_2 , V_140 ,
V_141 , V_141 ) ;
F_6 ( V_2 , V_117 ,
V_118 |
V_119 ,
V_118 |
V_119 ) ;
F_32 ( 150 ) ;
F_6 ( V_2 , V_134 ,
V_135 |
V_136 |
V_138 |
V_139 , 0 ) ;
F_6 ( V_2 , V_140 ,
V_141 , 0 ) ;
F_6 ( V_2 , V_106 ,
V_122 |
V_124 |
V_125 |
V_126 , 0 ) ;
F_6 ( V_2 , V_128 ,
V_129 | V_130 , 0 ) ;
F_6 ( V_2 , V_106 ,
V_126 , 0 ) ;
}
F_34 ( V_2 -> V_29 ) ;
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
static bool F_36 ( struct V_1 * V_2 )
{
int V_51 = 0 ;
int V_53 , V_142 ;
V_53 = F_3 ( V_2 , V_143 ) ;
switch ( V_53 ) {
case V_144 :
F_37 ( V_2 -> V_29 , L_19 ) ;
V_51 = 2 << V_145 ;
break;
case V_146 :
F_37 ( V_2 -> V_29 , L_20 ) ;
V_51 = 1 << V_145 ;
break;
case V_147 :
F_37 ( V_2 -> V_29 , L_21 ) ;
V_51 = 0 << V_145 ;
break;
default:
F_37 ( V_2 -> V_29 , L_22 , V_53 ) ;
return false ;
}
V_142 = F_3 ( V_2 , V_148 ) ;
if ( V_142 != V_53 ) {
F_37 ( V_2 -> V_29 , L_23 ) ;
return false ;
}
F_6 ( V_2 , V_149 ,
V_150 , V_51 ) ;
return true ;
}
static int F_38 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
struct V_4 * V_151 = V_2 -> V_152 ;
int V_63 = V_153 | V_154 ;
int V_6 ;
int V_155 ;
int V_156 ;
int V_8 ;
switch ( V_151 -> type ) {
case V_157 :
case V_158 :
V_63 |= V_159 | V_160 ;
break;
default:
break;
}
switch ( V_113 ) {
case V_114 :
V_8 = F_3 ( V_2 , V_161 ) ;
if ( ( V_8 & V_162 ) &&
( V_8 & V_163 ) )
V_156 = V_164 | V_165 ;
else if ( ! ( V_8 & V_162 ) &&
! ( V_8 & V_163 ) )
V_156 = V_166 | V_167 ;
else
V_156 = V_164 | V_165 |
V_166 | V_167 ;
V_8 = F_3 ( V_2 , V_168 ) ;
if ( ( V_8 & V_169 ) &&
( V_8 & V_170 ) )
V_155 = V_154 | V_160 ;
else if ( ! ( V_8 & V_169 ) &&
! ( V_8 & V_170 ) )
V_155 = V_153 | V_159 ;
else
V_155 = V_154 | V_160 |
V_153 | V_159 ;
F_6 ( V_2 , V_171 ,
V_63 , V_156 ) ;
F_6 ( V_2 , V_172 ,
V_63 , V_155 ) ;
F_6 ( V_2 , V_18 ,
V_173 |
V_174 ,
V_173 |
V_174 ) ;
F_6 ( V_2 , V_171 , V_63 ,
V_164 |
V_166 |
V_165 |
V_167 ) ;
F_6 ( V_2 , V_172 , V_63 ,
V_154 |
V_153 |
V_160 |
V_159 ) ;
break;
case V_175 :
for ( V_6 = 0 ; V_6 < F_4 ( V_176 ) ; V_6 ++ )
F_39 ( V_2 , V_176 [ V_6 ] . V_53 ,
F_3 ( V_2 ,
V_176 [ V_6 ] . V_53 ) ) ;
break;
case V_177 :
case V_115 :
F_6 ( V_2 , V_172 ,
V_63 , 0 ) ;
F_6 ( V_2 , V_171 ,
V_63 , 0 ) ;
V_8 = F_3 ( V_2 , V_18 ) ;
if ( V_8 & V_178 )
V_8 = V_174 ;
else
V_8 = 0 ;
F_6 ( V_2 , V_18 ,
V_174 |
V_173 , V_8 ) ;
break;
}
return 0 ;
}
static int F_40 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
int V_6 ;
int V_155 ;
int V_156 ;
int V_8 ;
switch ( V_113 ) {
case V_114 :
V_8 = F_3 ( V_2 , V_179 ) ;
if ( ( V_8 & V_180 ) &&
( V_8 & V_181 ) )
V_156 = V_182 ;
else if ( ! ( V_8 & V_180 ) &&
! ( V_8 & V_181 ) )
V_156 = V_183 ;
else
V_156 = V_183 | V_182 ;
V_8 = F_3 ( V_2 , V_184 ) ;
if ( ( V_8 & V_185 ) &&
( V_8 & V_186 ) )
V_155 = V_187 ;
else if ( ! ( V_8 & V_185 ) &&
! ( V_8 & V_186 ) )
V_155 = V_188 ;
else
V_155 = V_188 | V_187 ;
F_6 ( V_2 , V_171 ,
V_183 |
V_182 , V_156 ) ;
F_6 ( V_2 , V_172 ,
V_188 |
V_187 , V_155 ) ;
F_6 ( V_2 , V_18 ,
V_178 |
V_174 ,
V_178 |
V_174 ) ;
F_6 ( V_2 , V_171 ,
V_183 |
V_182 ,
V_183 |
V_182 ) ;
F_6 ( V_2 , V_172 ,
V_188 |
V_187 ,
V_188 |
V_187 ) ;
break;
case V_175 :
for ( V_6 = 0 ; V_6 < F_4 ( V_176 ) ; V_6 ++ )
F_39 ( V_2 , V_176 [ V_6 ] . V_53 ,
F_3 ( V_2 ,
V_176 [ V_6 ] . V_53 ) ) ;
break;
case V_177 :
case V_115 :
F_6 ( V_2 , V_172 ,
V_188 |
V_187 , 0 ) ;
F_6 ( V_2 , V_171 ,
V_183 |
V_182 , 0 ) ;
V_8 = F_3 ( V_2 , V_18 ) ;
if ( V_8 & V_173 )
V_8 = V_174 ;
else
V_8 = 0 ;
F_6 ( V_2 , V_18 ,
V_174 |
V_178 , V_8 ) ;
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
V_4 -> V_189 = 1 ;
break;
case V_115 :
V_4 -> V_190 = 1 ;
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
V_4 -> V_191 = 1 ;
break;
case V_115 :
V_4 -> V_192 = 1 ;
break;
}
return 0 ;
}
static int F_43 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_113 ) {
case V_114 :
if ( V_4 -> V_189 ) {
F_38 ( V_112 , V_57 , V_114 ) ;
F_6 ( V_2 , V_45 ,
V_193 ,
V_194 ) ;
F_38 ( V_112 , V_57 , V_175 ) ;
V_4 -> V_189 = 0 ;
}
if ( V_4 -> V_191 ) {
F_40 ( V_112 , V_57 , V_114 ) ;
F_6 ( V_2 , V_195 ,
V_196 ,
V_197 ) ;
F_40 ( V_112 , V_57 , V_175 ) ;
V_4 -> V_191 = 0 ;
}
break;
}
F_44 ( V_112 , V_57 , V_113 ) ;
return 0 ;
}
static int F_45 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_113 ) {
case V_115 :
if ( V_4 -> V_190 ) {
F_38 ( V_112 , V_57 , V_177 ) ;
F_6 ( V_2 , V_45 ,
V_193 , 0 ) ;
F_38 ( V_112 , V_57 , V_115 ) ;
V_4 -> V_190 = 0 ;
}
if ( V_4 -> V_192 ) {
F_40 ( V_112 , V_57 , V_177 ) ;
F_6 ( V_2 , V_195 ,
V_196 , 0 ) ;
F_40 ( V_112 , V_57 , V_115 ) ;
V_4 -> V_192 = 0 ;
}
break;
}
return 0 ;
}
static int F_46 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
F_43 ( V_112 , V_57 , V_113 ) ;
return 0 ;
}
static int F_47 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
F_43 ( V_112 , V_57 , V_113 ) ;
return 0 ;
}
static int F_48 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
unsigned int V_63 = 1 << V_112 -> V_65 ;
F_6 ( V_2 , V_172 ,
V_63 , V_63 ) ;
return 0 ;
}
static int F_49 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
F_5 ( V_2 -> V_29 , L_24 ,
F_3 ( V_2 ,
V_198 ) ) ;
return 0 ;
}
static int F_50 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_199 * V_200 = F_12 ( V_57 ) ;
struct V_50 * V_112 = V_200 -> V_201 [ 0 ] ;
struct V_1 * V_2 = V_112 -> V_2 ;
int V_64 ;
V_64 = F_51 ( V_57 , V_59 ) ;
F_52 ( V_2 ) ;
return V_64 ;
}
static int F_53 ( struct V_202 * V_40 ,
int V_203 , int V_204 )
{
T_2 V_205 ;
unsigned int V_206 , V_207 , V_208 ;
F_54 ( L_25 , V_203 , V_204 ) ;
V_40 -> V_209 = 0 ;
while ( V_203 > 13500000 ) {
V_40 -> V_209 ++ ;
V_203 /= 2 ;
if ( V_40 -> V_209 > 3 )
return - V_43 ;
}
F_54 ( L_26 , V_40 -> V_209 , V_203 ) ;
V_40 -> V_210 = 3 ;
while ( V_204 * ( V_40 -> V_210 + 1 ) < 90000000 ) {
V_40 -> V_210 ++ ;
if ( V_40 -> V_210 > 63 )
return - V_43 ;
}
V_204 *= V_40 -> V_210 + 1 ;
F_54 ( L_27 , V_40 -> V_210 , V_204 ) ;
if ( V_203 > 1000000 ) {
V_40 -> V_211 = 0 ;
} else if ( V_203 > 256000 ) {
V_40 -> V_211 = 1 ;
V_203 *= 2 ;
} else if ( V_203 > 128000 ) {
V_40 -> V_211 = 2 ;
V_203 *= 4 ;
} else if ( V_203 > 64000 ) {
V_40 -> V_211 = 3 ;
V_203 *= 8 ;
} else {
V_40 -> V_211 = 4 ;
V_203 *= 16 ;
}
F_54 ( L_28 , V_40 -> V_211 , V_203 ) ;
V_207 = V_204 / V_203 ;
V_40 -> V_212 = V_207 ;
V_208 = V_204 % V_203 ;
F_54 ( L_29 , V_208 ) ;
V_205 = V_213 * ( long long ) V_208 ;
F_55 ( V_205 , V_203 ) ;
V_206 = V_205 & 0xFFFFFFFF ;
if ( ( V_206 % 10 ) >= 5 )
V_206 += 5 ;
V_40 -> V_214 = V_206 / 10 ;
F_54 ( L_30 , V_40 -> V_212 , V_40 -> V_214 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , int V_83 , int V_215 ,
unsigned int V_203 , unsigned int V_204 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_151 = V_4 -> V_4 ;
int V_216 , V_64 ;
struct V_202 V_40 ;
T_1 V_53 , V_217 , V_218 , V_219 ;
unsigned long V_220 ;
bool V_221 ;
switch ( V_83 ) {
case V_222 :
V_216 = 0 ;
V_83 = 0 ;
V_219 = 0x10 ;
break;
case V_223 :
V_216 = 0x20 ;
V_83 = 1 ;
V_219 = 0x18 ;
break;
default:
return - V_43 ;
}
V_53 = F_3 ( V_2 , V_224 + V_216 ) ;
V_221 = V_53 & V_225 ;
switch ( V_215 ) {
case 0 :
if ( V_204 )
return - V_43 ;
V_215 = V_4 -> V_40 [ V_83 ] . V_215 ;
break;
case V_226 :
case V_227 :
case V_228 :
case V_229 :
break;
default:
return - V_43 ;
}
if ( V_4 -> V_40 [ V_83 ] . V_215 == V_215 &&
V_4 -> V_40 [ V_83 ] . V_230 == V_203 && V_4 -> V_40 [ V_83 ] . V_41 == V_204 )
return 0 ;
if ( V_204 )
V_64 = F_53 ( & V_40 , V_203 , V_204 ) ;
else
V_64 = F_53 ( & V_40 , V_4 -> V_40 [ V_83 ] . V_230 ,
V_4 -> V_40 [ V_83 ] . V_41 ) ;
if ( V_64 < 0 )
return V_64 ;
V_217 = F_3 ( V_2 , V_18 ) ;
if ( V_217 & V_19 )
V_218 = V_195 ;
else
V_218 = V_45 ;
V_53 = F_3 ( V_2 , V_218 ) ;
if ( ( V_53 & V_194 ) &&
( V_53 & V_46 ) == V_219 ) {
F_57 ( V_2 -> V_29 , L_31 ,
V_83 + 1 ) ;
return - V_231 ;
}
F_6 ( V_2 , V_224 + V_216 ,
V_225 , 0 ) ;
if ( V_4 -> V_232 && V_215 == V_229 &&
V_203 == V_204 && V_204 ) {
F_5 ( V_2 -> V_29 , L_32 , V_83 + 1 ) ;
F_6 ( V_2 , V_233 + V_216 ,
V_234 , V_234 ) ;
goto V_41;
}
V_53 = ( V_40 . V_210 << V_235 ) |
( V_40 . V_211 << V_236 ) ;
F_6 ( V_2 , V_237 + V_216 ,
V_238 |
V_239 , V_53 ) ;
F_6 ( V_2 , V_240 + V_216 ,
V_241 , V_40 . V_214 ) ;
F_6 ( V_2 , V_242 + V_216 ,
V_243 ,
V_40 . V_212 << V_244 ) ;
F_6 ( V_2 , V_233 + V_216 ,
V_234 |
V_245 |
V_246 ,
( V_40 . V_209 << V_247 ) |
( V_215 - 1 ) ) ;
F_58 ( & V_4 -> V_248 [ V_83 ] ) ;
if ( V_204 ) {
if ( ! V_221 ) {
F_23 ( V_2 ) ;
switch ( V_151 -> type ) {
case V_157 :
F_28 ( V_2 ) ;
break;
case V_158 :
if ( V_4 -> V_249 < 1 )
F_28 ( V_2 ) ;
break;
default:
break;
}
}
if ( V_40 . V_214 )
V_53 = V_225 | V_250 ;
else
V_53 = V_225 ;
F_6 ( V_2 , V_224 + V_216 ,
V_225 | V_250 ,
V_53 ) ;
if ( V_4 -> V_251 ) {
V_220 = F_59 ( & V_4 -> V_248 [ V_83 ] ,
F_60 ( 10 ) ) ;
if ( V_220 == 0 )
F_61 ( V_2 -> V_29 ,
L_33 ) ;
} else {
F_32 ( 5 ) ;
}
} else {
if ( V_221 ) {
switch ( V_151 -> type ) {
case V_157 :
F_33 ( V_2 ) ;
break;
case V_158 :
if ( V_4 -> V_249 < 1 )
F_33 ( V_2 ) ;
break;
default:
break;
}
F_26 ( V_2 ) ;
}
}
V_41:
V_4 -> V_40 [ V_83 ] . V_230 = V_203 ;
V_4 -> V_40 [ V_83 ] . V_41 = V_204 ;
V_4 -> V_40 [ V_83 ] . V_215 = V_215 ;
F_8 ( V_2 ) ;
return 0 ;
}
static T_3 F_62 ( int V_252 , void * V_253 )
{
struct V_254 * V_254 = V_253 ;
F_63 ( V_254 ) ;
return V_255 ;
}
static int F_64 ( struct V_256 * V_257 , int V_83 , int V_215 ,
unsigned int V_203 , unsigned int V_204 )
{
return F_56 ( V_257 -> V_2 , V_83 , V_215 , V_203 , V_204 ) ;
}
static int F_65 ( struct V_256 * V_257 ,
int V_258 , unsigned int V_259 , int V_260 )
{
struct V_1 * V_2 = V_257 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
switch ( V_257 -> V_83 ) {
case 1 :
case 2 :
break;
default:
return - V_43 ;
}
switch ( V_258 ) {
case V_36 :
V_4 -> V_7 [ V_257 -> V_83 - 1 ] = V_36 ;
V_4 -> V_37 [ 0 ] = V_259 ;
F_5 ( V_257 -> V_29 , L_34 ,
V_257 -> V_83 , V_259 ) ;
break;
case V_38 :
V_4 -> V_7 [ V_257 -> V_83 - 1 ] = V_38 ;
V_4 -> V_37 [ 1 ] = V_259 ;
F_5 ( V_257 -> V_29 , L_35 ,
V_257 -> V_83 , V_259 ) ;
break;
case V_39 :
V_4 -> V_7 [ V_257 -> V_83 - 1 ] = V_39 ;
F_5 ( V_257 -> V_29 , L_36 , V_257 -> V_83 ) ;
break;
case V_42 :
V_4 -> V_7 [ V_257 -> V_83 - 1 ] = V_42 ;
F_5 ( V_257 -> V_29 , L_37 , V_257 -> V_83 ) ;
break;
case V_261 :
if ( V_259 ) {
for ( V_6 = 0 ; V_6 < F_4 ( V_262 ) ; V_6 ++ )
if ( V_262 [ V_6 ] == V_259 )
break;
if ( V_6 == F_4 ( V_262 ) )
return - V_43 ;
F_6 ( V_2 , V_263 ,
V_264 , V_6 ) ;
F_6 ( V_2 , V_265 ,
V_266 , V_266 ) ;
} else {
F_6 ( V_2 , V_265 ,
V_266 , 0 ) ;
}
default:
return - V_43 ;
}
F_8 ( V_2 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 ,
enum V_267 V_268 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_151 = V_4 -> V_4 ;
F_67 ( V_2 , V_268 ) ;
switch ( V_268 ) {
case V_269 :
break;
case V_270 :
switch ( V_151 -> type ) {
case V_158 :
case V_271 :
F_6 ( V_2 , V_272 ,
V_273 , 0 ) ;
F_6 ( V_2 , V_274 ,
V_275 , 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_49 . V_276 == V_277 )
F_23 ( V_2 ) ;
break;
case V_277 :
if ( V_2 -> V_49 . V_276 == V_278 ) {
switch ( V_151 -> type ) {
case V_158 :
if ( V_4 -> V_249 == 0 ) {
F_6 ( V_2 ,
V_279 ,
V_280 ,
V_280 ) ;
}
break;
default:
break;
}
F_6 ( V_2 , V_117 ,
V_118 |
V_119 ,
V_118 |
V_119 ) ;
}
if ( V_2 -> V_49 . V_276 == V_270 )
F_26 ( V_2 ) ;
switch ( V_151 -> type ) {
case V_158 :
case V_271 :
F_6 ( V_2 , V_272 ,
V_273 ,
V_273 ) ;
F_6 ( V_2 , V_274 ,
V_275 ,
V_275 ) ;
break;
default:
break;
}
break;
case V_278 :
if ( V_2 -> V_49 . V_276 == V_277 )
V_4 -> V_281 = NULL ;
break;
}
V_2 -> V_49 . V_276 = V_268 ;
return 0 ;
}
int F_68 ( struct V_1 * V_2 , enum F_68 V_101 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_101 ) {
case V_121 :
if ( V_4 -> V_132 . V_133 ) {
F_69 ( & V_2 -> V_49 ,
L_38 ) ;
F_69 ( & V_2 -> V_49 ,
L_39 ) ;
}
if ( V_4 -> V_132 . V_137 ) {
F_69 ( & V_2 -> V_49 ,
L_40 ) ;
F_69 ( & V_2 -> V_49 ,
L_41 ) ;
}
F_9 ( & V_2 -> V_49 ) ;
V_4 -> V_120 = V_101 ;
break;
case V_131 :
if ( V_4 -> V_132 . V_133 ) {
F_70 ( & V_2 -> V_49 ,
L_38 ) ;
F_70 ( & V_2 -> V_49 ,
L_39 ) ;
}
if ( V_4 -> V_132 . V_137 ) {
F_70 ( & V_2 -> V_49 ,
L_40 ) ;
F_70 ( & V_2 -> V_49 ,
L_41 ) ;
}
V_4 -> V_120 = V_101 ;
F_9 ( & V_2 -> V_49 ) ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static int F_71 ( struct V_256 * V_257 , unsigned int V_282 )
{
struct V_1 * V_2 = V_257 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_151 = V_4 -> V_4 ;
int V_283 ;
int V_284 ;
int V_285 = 0 ;
int V_286 = 0 ;
switch ( V_257 -> V_83 ) {
case 1 :
V_283 = V_287 ;
V_284 = V_161 ;
break;
case 2 :
V_283 = V_288 ;
V_284 = V_179 ;
break;
default:
return - V_43 ;
}
switch ( V_282 & V_289 ) {
case V_290 :
break;
case V_291 :
V_285 = V_292 ;
break;
default:
return - V_43 ;
}
switch ( V_282 & V_293 ) {
case V_294 :
V_286 |= V_295 ;
case V_296 :
V_286 |= 0x18 ;
break;
case V_297 :
V_286 |= 0x10 ;
break;
case V_298 :
break;
case V_299 :
V_286 |= 0x8 ;
break;
default:
return - V_43 ;
}
switch ( V_282 & V_293 ) {
case V_296 :
case V_294 :
switch ( V_282 & V_300 ) {
case V_301 :
break;
case V_302 :
V_286 |= V_303 ;
break;
default:
return - V_43 ;
}
break;
case V_297 :
case V_298 :
case V_299 :
switch ( V_282 & V_300 ) {
case V_301 :
break;
case V_304 :
V_286 |= V_303 | V_295 ;
break;
case V_302 :
V_286 |= V_303 ;
break;
case V_305 :
V_286 |= V_295 ;
break;
default:
return - V_43 ;
}
break;
default:
return - V_43 ;
}
switch ( V_151 -> type ) {
case V_271 :
case V_158 :
if ( V_257 -> V_83 == 2 )
F_6 ( V_2 , V_306 ,
V_295 |
V_307 , V_286 ) ;
break;
default:
break;
}
F_6 ( V_2 , V_284 ,
V_303 | V_295 |
V_308 ,
V_286 ) ;
F_6 ( V_2 , V_283 , V_292 ,
V_285 ) ;
return 0 ;
}
static int F_72 ( struct V_309 * V_310 ,
struct V_311 * V_312 ,
struct V_256 * V_257 )
{
struct V_1 * V_2 = V_257 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_284 ;
int V_313 ;
int V_314 ;
int V_315 ;
int V_316 ;
int V_286 = 0 ;
int V_317 = 0 ;
int V_318 = 0 ;
int V_319 = 0 ;
int V_320 = 0 ;
int V_83 = V_257 -> V_83 - 1 ;
int V_6 , V_321 , V_91 , V_322 , V_5 ;
switch ( V_257 -> V_83 ) {
case 1 :
V_284 = V_161 ;
V_313 = V_168 ;
V_314 = V_323 ;
V_316 = V_324 ;
if ( V_310 -> V_325 == V_326 ||
V_4 -> V_327 [ 0 ] ) {
V_315 = V_328 ;
} else {
V_315 = V_329 ;
F_5 ( V_2 -> V_29 , L_42 ) ;
}
break;
case 2 :
V_284 = V_179 ;
V_313 = V_184 ;
V_314 = V_330 ;
V_316 = V_331 ;
if ( V_310 -> V_325 == V_326 ||
V_4 -> V_327 [ 1 ] ) {
V_315 = V_332 ;
} else {
V_315 = V_333 ;
F_5 ( V_2 -> V_29 , L_43 ) ;
}
break;
default:
return - V_43 ;
}
V_322 = F_73 ( V_312 ) * 2 ;
switch ( F_74 ( V_312 ) ) {
case V_334 :
V_322 *= 16 ;
break;
case V_335 :
V_322 *= 20 ;
V_286 |= 0x20 ;
break;
case V_336 :
V_322 *= 24 ;
V_286 |= 0x40 ;
break;
case V_337 :
V_322 *= 32 ;
V_286 |= 0x60 ;
break;
default:
return - V_43 ;
}
for ( V_6 = 0 ; V_6 < F_4 ( V_338 ) ; V_6 ++ )
if ( V_338 [ V_6 ] . V_27 == F_73 ( V_312 ) )
break;
if ( V_6 == F_4 ( V_338 ) )
return - V_43 ;
V_320 |= V_338 [ V_6 ] . V_8 << V_339 ;
F_5 ( V_257 -> V_29 , L_44 , V_338 [ V_6 ] . V_27 ) ;
F_5 ( V_257 -> V_29 , L_45 ,
V_257 -> V_83 , V_4 -> V_20 [ V_83 ] , V_322 ) ;
if ( F_75 ( V_312 ) == 1 &&
( F_3 ( V_2 , V_284 ) & 0x18 ) == 0x18 )
V_317 |= V_340 ;
if ( V_4 -> V_20 [ V_83 ] == 0 ) {
F_57 ( V_257 -> V_29 , L_46 , V_257 -> V_83 ) ;
return - V_43 ;
}
V_5 = 0 ;
V_91 = abs ( ( V_341 [ 0 ] * F_73 ( V_312 ) )
- V_4 -> V_20 [ V_83 ] ) ;
for ( V_6 = 1 ; V_6 < F_4 ( V_341 ) ; V_6 ++ ) {
V_321 = abs ( ( V_341 [ V_6 ] * F_73 ( V_312 ) )
- V_4 -> V_20 [ V_83 ] ) ;
if ( V_321 >= V_91 )
continue;
V_5 = V_6 ;
V_91 = V_321 ;
}
F_5 ( V_257 -> V_29 , L_47 ,
V_257 -> V_83 , V_341 [ V_5 ] ) ;
V_320 |= V_5 ;
V_5 = 0 ;
for ( V_6 = 0 ; V_6 < F_4 ( V_342 ) ; V_6 ++ ) {
V_321 = ( V_4 -> V_20 [ V_83 ] * 10 / V_342 [ V_6 ] ) - V_322 ;
if ( V_321 < 0 )
break;
V_5 = V_6 ;
}
V_322 = V_4 -> V_20 [ V_83 ] * 10 / V_342 [ V_5 ] ;
F_5 ( V_257 -> V_29 , L_48 ,
V_342 [ V_5 ] , V_322 ) ;
V_318 |= V_5 << V_343 ;
V_319 = V_322 / F_73 ( V_312 ) ;
if ( ! V_319 ) {
F_57 ( V_257 -> V_29 , L_49 ,
V_322 ) ;
return - V_43 ;
}
F_5 ( V_257 -> V_29 , L_50 ,
V_319 , V_322 / V_319 ) ;
F_6 ( V_2 , V_284 , V_344 , V_286 ) ;
F_6 ( V_2 , V_313 , V_340 , V_317 ) ;
F_6 ( V_2 , V_314 , V_345 , V_318 ) ;
F_6 ( V_2 , V_315 , V_346 ,
V_319 ) ;
F_6 ( V_2 , V_316 , V_347 |
V_348 , V_320 ) ;
if ( V_310 -> V_325 == V_326 ) {
switch ( V_257 -> V_83 ) {
case 1 :
V_4 -> V_98 [ 0 ] = F_73 ( V_312 ) ;
F_18 ( V_2 , 0 ) ;
F_18 ( V_2 , 1 ) ;
break;
case 2 :
V_4 -> V_98 [ 1 ] = F_73 ( V_312 ) ;
F_18 ( V_2 , 2 ) ;
break;
}
}
return 0 ;
}
static int F_76 ( struct V_309 * V_310 ,
struct V_311 * V_312 ,
struct V_256 * V_257 )
{
struct V_1 * V_2 = V_257 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_151 = V_4 -> V_4 ;
int V_284 ;
int V_286 = 0 ;
switch ( V_257 -> V_83 ) {
case 3 :
switch ( V_151 -> type ) {
case V_271 :
case V_158 :
V_284 = V_306 ;
break;
default:
return 0 ;
}
default:
return 0 ;
}
switch ( F_74 ( V_312 ) ) {
case V_334 :
break;
case V_335 :
V_286 |= 0x20 ;
break;
case V_336 :
V_286 |= 0x40 ;
break;
case V_337 :
V_286 |= 0x60 ;
break;
default:
return - V_43 ;
}
return F_6 ( V_2 , V_284 , V_344 , V_286 ) ;
}
static int F_77 ( struct V_256 * V_349 , int V_350 )
{
struct V_1 * V_2 = V_349 -> V_2 ;
int V_351 ;
int V_53 ;
switch ( V_349 -> V_83 ) {
case 1 :
V_351 = V_352 ;
break;
case 2 :
V_351 = V_353 ;
break;
default:
return - V_43 ;
}
if ( V_350 )
V_53 = V_354 ;
else
V_53 = 0 ;
F_6 ( V_2 , V_351 , V_354 , V_53 ) ;
return 0 ;
}
static int F_78 ( struct V_256 * V_349 , int V_355 )
{
struct V_1 * V_2 = V_349 -> V_2 ;
int V_53 , V_8 , V_63 ;
switch ( V_349 -> V_83 ) {
case 1 :
V_53 = V_287 ;
V_63 = V_356 ;
break;
case 2 :
V_53 = V_288 ;
V_63 = V_357 ;
break;
default:
return - V_43 ;
}
if ( V_355 )
V_8 = V_63 ;
else
V_8 = 0 ;
return F_6 ( V_2 , V_53 , V_63 , V_8 ) ;
}
static int F_79 ( struct V_256 * V_257 )
{
struct V_1 * V_2 = V_257 -> V_2 ;
F_6 ( V_2 , V_358 ,
V_359 | V_360 , 0 ) ;
F_6 ( V_2 , V_361 ,
V_359 | V_360 , 0 ) ;
F_6 ( V_2 , V_362 ,
V_359 | V_360 , 0 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_151 = V_4 -> V_4 ;
int V_6 , V_64 ;
switch ( V_151 -> type ) {
case V_157 :
F_6 ( V_2 , V_363 , V_364 , 0 ) ;
break;
case V_271 :
F_6 ( V_2 , V_106 ,
V_107 , 0 ) ;
case V_158 :
F_6 ( V_2 , V_30 ,
V_365 , 0 ) ;
break;
}
for ( V_6 = 0 ; V_6 < F_4 ( V_4 -> V_40 ) ; V_6 ++ ) {
memcpy ( & V_4 -> V_366 [ V_6 ] , & V_4 -> V_40 [ V_6 ] ,
sizeof( struct V_367 ) ) ;
V_64 = F_56 ( V_2 , V_6 + 1 , 0 , 0 , 0 ) ;
if ( V_64 < 0 )
F_61 ( V_2 -> V_29 , L_51 ,
V_6 + 1 , V_64 ) ;
}
F_66 ( V_2 , V_278 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_151 = V_4 -> V_4 ;
int V_6 , V_64 ;
unsigned int V_8 , V_63 ;
if ( V_4 -> V_249 < 4 ) {
V_64 = F_82 ( V_151 -> V_368 ,
V_172 , & V_8 ) ;
V_2 -> V_369 = 1 ;
V_63 = V_370 | V_371 |
V_372 | V_373 ;
V_8 &= V_63 ;
F_6 ( V_2 , V_172 ,
V_63 , V_8 ) ;
V_2 -> V_369 = 0 ;
}
for ( V_6 = 0 ; V_6 < F_4 ( V_4 -> V_40 ) ; V_6 ++ ) {
if ( ! V_4 -> V_366 [ V_6 ] . V_41 )
continue;
V_64 = F_56 ( V_2 , V_6 + 1 ,
V_4 -> V_366 [ V_6 ] . V_215 ,
V_4 -> V_366 [ V_6 ] . V_230 ,
V_4 -> V_366 [ V_6 ] . V_41 ) ;
if ( V_64 < 0 )
F_61 ( V_2 -> V_29 , L_52 ,
V_6 + 1 , V_64 ) ;
}
switch ( V_151 -> type ) {
case V_157 :
if ( V_4 -> V_374 [ 0 ] . V_375 || V_4 -> V_374 [ 1 ] . V_375 )
F_6 ( V_2 , V_363 ,
V_364 , V_364 ) ;
break;
case V_271 :
if ( V_4 -> V_22 && V_4 -> V_15 ) {
F_6 ( V_2 , V_106 ,
V_107 ,
V_111 ) ;
break;
}
break;
case V_158 :
if ( V_4 -> V_15 )
F_6 ( V_2 , V_30 ,
V_365 , V_365 ) ;
break;
}
return 0 ;
}
static void F_83 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_71 * V_13 = V_4 -> V_13 ;
struct V_376 V_377 [] = {
F_84 ( L_11 ,
V_4 -> V_378 ,
F_21 ,
F_20 ) ,
F_84 ( L_12 ,
V_4 -> V_378 ,
F_21 ,
F_20 ) ,
F_84 ( L_13 ,
V_4 -> V_378 ,
F_21 ,
F_20 ) ,
} ;
int V_64 , V_6 , V_379 ;
const char * * V_380 ;
V_4 -> V_92 = 0 ;
V_4 -> V_97 = NULL ;
for ( V_6 = 0 ; V_6 < V_13 -> V_95 ; V_6 ++ ) {
for ( V_379 = 0 ; V_379 < V_4 -> V_92 ; V_379 ++ ) {
if ( strcmp ( V_13 -> V_96 [ V_6 ] . V_55 ,
V_4 -> V_97 [ V_379 ] ) == 0 )
break;
}
if ( V_379 != V_4 -> V_92 )
continue;
V_380 = F_85 ( V_4 -> V_97 ,
sizeof( char * ) *
( V_4 -> V_92 + 1 ) ,
V_381 ) ;
if ( V_380 == NULL )
continue;
V_380 [ V_4 -> V_92 ] =
V_13 -> V_96 [ V_6 ] . V_55 ;
V_4 -> V_92 ++ ;
V_4 -> V_97 = V_380 ;
}
F_5 ( V_2 -> V_29 , L_53 ,
V_4 -> V_92 ) ;
V_4 -> V_378 . V_382 = V_4 -> V_92 ;
V_4 -> V_378 . V_383 = V_4 -> V_97 ;
V_64 = F_86 ( V_4 -> V_2 , V_377 ,
F_4 ( V_377 ) ) ;
if ( V_64 != 0 )
F_57 ( V_4 -> V_2 -> V_29 ,
L_54 , V_64 ) ;
}
static void F_87 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_71 * V_13 = V_4 -> V_13 ;
int V_64 , V_6 ;
if ( ! V_13 )
return;
F_88 ( V_2 , V_13 -> V_384 ,
V_13 -> V_385 ,
V_13 -> V_386 ,
V_13 -> V_387 ,
V_13 -> V_388 ,
V_13 -> V_389 ,
V_13 -> V_390 ,
V_13 -> V_391 ) ;
F_5 ( V_2 -> V_29 , L_55 , V_13 -> V_85 ) ;
if ( V_13 -> V_85 ) {
struct V_376 V_377 [] = {
F_84 ( L_7 , V_4 -> V_392 ,
F_17 , F_16 ) ,
F_84 ( L_8 , V_4 -> V_392 ,
F_17 , F_16 ) ,
F_84 ( L_9 , V_4 -> V_392 ,
F_17 , F_16 ) ,
} ;
V_4 -> V_393 = F_89 ( V_4 -> V_2 -> V_29 ,
sizeof( char * ) * V_13 -> V_85 , V_381 ) ;
if ( ! V_4 -> V_393 ) {
F_57 ( V_4 -> V_2 -> V_29 ,
L_56 ,
V_13 -> V_85 ) ;
return;
}
for ( V_6 = 0 ; V_6 < V_13 -> V_85 ; V_6 ++ )
V_4 -> V_393 [ V_6 ] = V_13 -> V_81 [ V_6 ] . V_55 ;
V_4 -> V_392 . V_382 = V_13 -> V_85 ;
V_4 -> V_392 . V_383 = V_4 -> V_393 ;
V_64 = F_86 ( V_4 -> V_2 , V_377 ,
F_4 ( V_377 ) ) ;
if ( V_64 != 0 )
F_57 ( V_4 -> V_2 -> V_29 ,
L_57 , V_64 ) ;
for ( V_6 = 0 ; V_6 < V_394 ; V_6 ++ )
F_14 ( V_2 , V_6 ) ;
}
F_5 ( V_2 -> V_29 , L_58 ,
V_13 -> V_95 ) ;
if ( V_13 -> V_95 )
F_83 ( V_4 ) ;
else
F_86 ( V_4 -> V_2 , V_395 ,
F_4 ( V_395 ) ) ;
for ( V_6 = 0 ; V_6 < F_4 ( V_13 -> V_396 ) ; V_6 ++ ) {
if ( V_13 -> V_396 [ V_6 ] ) {
F_39 ( V_2 , V_272 + V_6 ,
V_13 -> V_396 [ V_6 ] & 0xffff ) ;
}
}
}
int F_90 ( struct V_1 * V_2 , struct V_397 * V_375 ,
int V_396 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_398 * V_374 ;
struct V_4 * V_151 = V_4 -> V_4 ;
int V_53 , V_64 ;
if ( V_151 -> type != V_157 ) {
F_61 ( V_2 -> V_29 , L_59 ) ;
return - V_43 ;
}
switch ( V_396 ) {
case 1 :
V_374 = & V_4 -> V_374 [ 0 ] ;
if ( V_375 )
V_64 = F_70 ( & V_2 -> V_49 ,
L_60 ) ;
else
V_64 = F_69 ( & V_2 -> V_49 ,
L_60 ) ;
break;
case 2 :
V_374 = & V_4 -> V_374 [ 1 ] ;
if ( V_375 )
V_64 = F_70 ( & V_2 -> V_49 ,
L_60 ) ;
else
V_64 = F_69 ( & V_2 -> V_49 ,
L_60 ) ;
break;
default:
F_61 ( V_2 -> V_29 , L_61 , V_396 ) ;
return - V_43 ;
}
if ( V_64 != 0 )
F_61 ( V_2 -> V_29 , L_62 ,
V_396 , V_64 ) ;
F_5 ( V_2 -> V_29 , L_63 ,
V_396 , V_375 ) ;
V_374 -> V_375 = V_375 ;
V_374 -> V_399 = true ;
if ( V_4 -> V_374 [ 0 ] . V_375 || V_4 -> V_374 [ 1 ] . V_375 )
V_53 = V_364 ;
else
V_53 = 0 ;
F_6 ( V_2 , V_363 , V_364 , V_53 ) ;
F_9 ( & V_2 -> V_49 ) ;
return 0 ;
}
static void F_91 ( struct V_400 * V_401 )
{
struct V_3 * V_402 = F_92 ( V_401 ,
struct V_3 ,
V_403 . V_401 ) ;
struct V_368 * V_368 = V_402 -> V_4 -> V_368 ;
struct V_404 * V_29 = V_402 -> V_4 -> V_29 ;
unsigned int V_53 ;
int V_64 ;
int V_405 ;
V_64 = F_82 ( V_368 , V_406 , & V_53 ) ;
if ( V_64 < 0 ) {
F_57 ( V_29 , L_64 ,
V_64 ) ;
return;
}
F_5 ( V_29 , L_65 , V_53 ) ;
V_405 = 0 ;
if ( V_53 & V_407 ) {
if ( V_402 -> V_374 [ 0 ] . V_399 )
V_405 = V_408 ;
}
if ( V_53 & V_409 ) {
if ( V_402 -> V_374 [ 0 ] . V_399 )
V_405 = V_410 ;
else
V_405 |= V_411 ;
}
if ( V_405 )
V_402 -> V_374 [ 0 ] . V_399 = false ;
else
V_402 -> V_374 [ 0 ] . V_399 = true ;
F_93 ( V_402 -> V_374 [ 0 ] . V_375 , V_405 ,
V_408 | V_411 ) ;
V_405 = 0 ;
if ( V_53 & V_412 ) {
if ( V_402 -> V_374 [ 1 ] . V_399 )
V_405 = V_408 ;
}
if ( V_53 & V_413 ) {
if ( V_402 -> V_374 [ 1 ] . V_399 )
V_405 = V_410 ;
else
V_405 |= V_411 ;
}
if ( V_405 )
V_402 -> V_374 [ 1 ] . V_399 = false ;
else
V_402 -> V_374 [ 1 ] . V_399 = true ;
F_93 ( V_402 -> V_374 [ 1 ] . V_375 , V_405 ,
V_408 | V_411 ) ;
}
static T_3 F_94 ( int V_252 , void * V_253 )
{
struct V_3 * V_402 = V_253 ;
struct V_1 * V_2 = V_402 -> V_2 ;
#ifndef F_95
F_96 ( F_97 ( V_2 -> V_29 ) ) ;
#endif
F_98 ( V_2 -> V_29 , 300 ) ;
F_99 ( & V_402 -> V_403 , F_60 ( 250 ) ) ;
return V_255 ;
}
static void V_16 ( T_1 V_414 , void * V_253 )
{
struct V_1 * V_2 = V_253 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_405 ;
F_5 ( V_2 -> V_29 , L_66 , V_414 ) ;
if ( ! ( V_414 & V_415 ) ) {
if ( ! V_4 -> V_22 ) {
F_5 ( V_2 -> V_29 , L_67 ) ;
V_4 -> V_17 = false ;
V_4 -> V_109 = true ;
F_1 ( V_2 ) ;
F_93 ( V_4 -> V_374 [ 0 ] . V_375 , 0 ,
V_4 -> V_416 |
V_408 ) ;
}
return;
}
if ( V_4 -> V_109 && ( V_414 & 0x600 ) ) {
F_5 ( V_2 -> V_29 , L_68 ) ;
V_4 -> V_109 = false ;
V_4 -> V_17 = true ;
F_1 ( V_2 ) ;
F_93 ( V_4 -> V_374 [ 0 ] . V_375 , V_408 ,
V_408 ) ;
}
if ( V_4 -> V_109 && V_414 & 0xfc ) {
F_5 ( V_2 -> V_29 , L_69 ) ;
V_4 -> V_109 = false ;
F_1 ( V_2 ) ;
if ( V_4 -> V_22 ) {
F_24 ( & V_4 -> V_108 ) ;
F_6 ( V_2 , V_30 ,
V_365 , 0 ) ;
F_22 ( V_2 ,
V_111 ) ;
F_25 ( & V_4 -> V_108 ) ;
if ( V_4 -> V_13 -> V_417 )
F_69 ( & V_2 -> V_49 ,
L_70 ) ;
}
F_93 ( V_4 -> V_374 [ 0 ] . V_375 , V_410 ,
V_408 ) ;
}
if ( V_4 -> V_17 ) {
V_405 = 0 ;
if ( V_414 & 0x4 )
V_405 |= V_411 ;
if ( V_414 & 0x8 )
V_405 |= V_418 ;
if ( V_414 & 0x10 )
V_405 |= V_419 ;
if ( V_414 & 0x20 )
V_405 |= V_420 ;
if ( V_414 & 0x40 )
V_405 |= V_421 ;
if ( V_414 & 0x80 )
V_405 |= V_422 ;
F_93 ( V_4 -> V_374 [ 0 ] . V_375 , V_405 ,
V_4 -> V_416 ) ;
}
}
static T_3 F_100 ( int V_252 , void * V_253 )
{
struct V_3 * V_4 = V_253 ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_53 ;
bool V_423 ;
F_24 ( & V_4 -> V_108 ) ;
V_53 = F_3 ( V_2 , V_424 ) ;
if ( V_53 < 0 ) {
F_57 ( V_2 -> V_29 , L_71 , V_53 ) ;
F_25 ( & V_4 -> V_108 ) ;
return V_425 ;
}
F_5 ( V_2 -> V_29 , L_72 , V_53 ) ;
V_423 = V_53 & V_426 ;
if ( V_423 ) {
F_5 ( V_2 -> V_29 , L_73 ) ;
F_1 ( V_2 ) ;
F_6 ( V_2 , V_274 ,
V_427 , 0 ) ;
F_6 ( V_2 , V_424 ,
V_428 , 0 ) ;
V_4 -> V_109 = true ;
F_22 ( V_2 , V_110 ) ;
F_6 ( V_2 , V_30 ,
V_365 , V_365 ) ;
} else {
F_5 ( V_2 -> V_29 , L_74 ) ;
F_6 ( V_2 , V_274 ,
V_427 , V_427 ) ;
F_6 ( V_2 , V_424 ,
V_428 , V_428 ) ;
V_4 -> V_109 = false ;
V_4 -> V_17 = false ;
F_6 ( V_2 , V_30 ,
V_365 , 0 ) ;
F_22 ( V_2 , V_111 ) ;
}
F_25 ( & V_4 -> V_108 ) ;
if ( V_4 -> V_13 -> V_417 ) {
if ( V_423 )
F_70 ( & V_2 -> V_49 ,
L_70 ) ;
else
F_69 ( & V_2 -> V_49 , L_70 ) ;
}
if ( V_423 )
F_93 ( V_4 -> V_374 [ 0 ] . V_375 ,
V_429 , V_429 ) ;
else
F_93 ( V_4 -> V_374 [ 0 ] . V_375 , 0 ,
V_429 | V_408 |
V_4 -> V_416 ) ;
return V_255 ;
}
int F_101 ( struct V_1 * V_2 , struct V_397 * V_375 ,
T_4 V_430 , void * V_431 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_151 = V_4 -> V_4 ;
T_1 V_432 ;
switch ( V_151 -> type ) {
case V_271 :
case V_158 :
break;
default:
return - V_43 ;
}
if ( V_375 ) {
if ( ! V_430 ) {
F_5 ( V_2 -> V_29 , L_75 ) ;
V_430 = V_16 ;
V_431 = V_2 ;
}
F_70 ( & V_2 -> V_49 , L_76 ) ;
F_9 ( & V_2 -> V_49 ) ;
V_4 -> V_374 [ 0 ] . V_375 = V_375 ;
V_4 -> V_15 = V_430 ;
V_4 -> V_433 = V_431 ;
V_4 -> V_109 = true ;
V_4 -> V_17 = false ;
F_1 ( V_2 ) ;
if ( V_4 -> V_13 -> V_432 )
V_432 = V_4 -> V_13 -> V_432 ;
else
V_432 = 0x41 ;
V_4 -> V_416 = V_411 | V_418 |
V_419 | V_420 |
V_421 | V_422 ;
F_6 ( V_2 , V_434 ,
V_435 , V_432 ) ;
F_31 ( V_2 -> V_49 . V_276 > V_277 ) ;
if ( V_4 -> V_22 ) {
F_6 ( V_2 , V_274 ,
V_427 ,
V_427 ) ;
F_6 ( V_2 , V_436 ,
V_437 , 0 ) ;
F_22 ( V_2 ,
V_111 ) ;
} else {
F_6 ( V_2 , V_30 ,
V_365 , V_365 ) ;
}
} else {
F_6 ( V_2 , V_30 ,
V_365 , 0 ) ;
F_22 ( V_2 , V_105 ) ;
F_69 ( & V_2 -> V_49 , L_76 ) ;
F_9 ( & V_2 -> V_49 ) ;
}
return 0 ;
}
static T_3 F_102 ( int V_252 , void * V_253 )
{
struct V_3 * V_4 = V_253 ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_53 , V_438 ;
if ( ! ( F_3 ( V_2 , V_30 ) & V_365 ) )
return V_255 ;
V_438 = 10 ;
do {
V_53 = F_3 ( V_2 , V_439 ) ;
if ( V_53 < 0 ) {
F_57 ( V_2 -> V_29 ,
L_77 ,
V_53 ) ;
return V_425 ;
}
if ( ! ( V_53 & V_440 ) ) {
F_5 ( V_2 -> V_29 , L_78 ) ;
goto V_41;
}
if ( ! ( V_53 & V_415 ) || ( V_53 & V_441 ) )
break;
F_32 ( 1 ) ;
} while ( V_438 -- );
if ( V_438 == 0 )
F_61 ( V_2 -> V_29 , L_79 ) ;
#ifndef F_95
F_96 ( F_97 ( V_2 -> V_29 ) ) ;
#endif
if ( V_4 -> V_15 )
V_4 -> V_15 ( V_53 , V_4 -> V_433 ) ;
else
F_61 ( V_2 -> V_29 , L_80 ) ;
V_41:
return V_255 ;
}
static T_3 F_103 ( int V_252 , void * V_253 )
{
struct V_1 * V_2 = V_253 ;
F_57 ( V_2 -> V_29 , L_81 ) ;
return V_255 ;
}
static T_3 F_104 ( int V_252 , void * V_253 )
{
struct V_1 * V_2 = V_253 ;
F_57 ( V_2 -> V_29 , L_82 ) ;
return V_255 ;
}
static T_3 F_105 ( int V_252 , void * V_253 )
{
struct V_1 * V_2 = V_253 ;
F_106 ( V_2 -> V_29 , L_83 ) ;
return V_255 ;
}
static int F_107 ( struct V_1 * V_2 )
{
struct V_4 * V_151 = F_108 ( V_2 -> V_29 -> V_442 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_443 * V_49 = & V_2 -> V_49 ;
unsigned int V_53 ;
int V_64 , V_6 ;
V_4 -> V_2 = V_2 ;
V_2 -> V_152 = V_151 -> V_368 ;
F_109 ( V_2 , 16 , 16 , V_444 ) ;
V_4 -> V_2 = V_2 ;
F_110 ( & V_4 -> V_108 ) ;
F_111 ( & V_4 -> V_403 , F_91 ) ;
for ( V_6 = 0 ; V_6 < F_4 ( V_4 -> V_248 ) ; V_6 ++ )
F_112 ( & V_4 -> V_248 [ V_6 ] ) ;
if ( V_4 -> V_13 && V_4 -> V_13 -> V_445 )
V_4 -> V_445 = V_4 -> V_13 -> V_445 ;
else if ( V_4 -> V_13 && V_4 -> V_13 -> V_446 )
V_4 -> V_445 = V_4 -> V_13 -> V_446 +
V_447 ;
F_113 ( V_2 -> V_29 ) ;
F_114 ( V_2 -> V_29 ) ;
V_2 -> V_49 . V_448 = 1 ;
V_4 -> V_249 = F_3 ( V_2 , V_449 ) ;
switch ( V_151 -> type ) {
case V_157 :
if ( ! V_4 -> V_13 -> V_384 ||
! V_4 -> V_13 -> V_385 )
V_2 -> V_49 . V_448 = 0 ;
switch ( V_4 -> V_249 ) {
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
case V_158 :
V_4 -> V_132 . V_453 = 1 ;
V_4 -> V_132 . V_452 = 1 ;
switch ( V_4 -> V_249 ) {
case 0 :
break;
default:
V_4 -> V_232 = true ;
break;
}
break;
case V_271 :
V_4 -> V_132 . V_453 = 2 ;
V_4 -> V_132 . V_455 = 1 ;
V_4 -> V_132 . V_452 = 1 ;
V_4 -> V_132 . V_456 = true ;
V_4 -> V_232 = true ;
switch ( V_4 -> V_249 ) {
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
F_6 ( V_2 , V_457 ,
V_458 , V_458 ) ;
break;
default:
break;
}
F_115 ( V_4 -> V_4 , V_459 ,
F_103 , L_84 , V_2 ) ;
F_115 ( V_4 -> V_4 , V_460 ,
F_104 , L_85 , V_2 ) ;
F_115 ( V_4 -> V_4 , V_461 ,
F_105 , L_86 , V_2 ) ;
V_64 = F_115 ( V_4 -> V_4 , V_462 ,
V_463 , L_87 ,
& V_4 -> V_132 ) ;
if ( V_64 == 0 )
V_4 -> V_132 . V_464 = true ;
switch ( V_151 -> type ) {
case V_157 :
if ( V_4 -> V_445 ) {
V_64 = F_116 ( V_4 -> V_445 , NULL ,
F_94 ,
V_465 ,
L_88 ,
V_4 ) ;
if ( V_64 != 0 )
F_61 ( V_2 -> V_29 ,
L_89 ,
V_64 ) ;
}
V_64 = F_115 ( V_4 -> V_4 ,
V_466 ,
F_94 , L_90 ,
V_4 ) ;
if ( V_64 != 0 )
F_61 ( V_2 -> V_29 ,
L_91 ,
V_64 ) ;
V_64 = F_115 ( V_4 -> V_4 ,
V_467 ,
F_94 , L_92 ,
V_4 ) ;
if ( V_64 != 0 )
F_61 ( V_2 -> V_29 ,
L_93 ,
V_64 ) ;
V_64 = F_115 ( V_4 -> V_4 ,
V_468 ,
F_94 , L_94 ,
V_4 ) ;
if ( V_64 != 0 )
F_61 ( V_2 -> V_29 ,
L_95 ,
V_64 ) ;
break;
case V_158 :
case V_271 :
if ( V_4 -> V_445 ) {
V_64 = F_116 ( V_4 -> V_445 , NULL ,
F_102 ,
V_465 ,
L_96 ,
V_4 ) ;
if ( V_64 != 0 )
F_61 ( V_2 -> V_29 ,
L_97 ,
V_64 ) ;
}
}
switch ( V_151 -> type ) {
case V_271 :
if ( V_4 -> V_249 > 1 ) {
V_64 = F_115 ( V_4 -> V_4 ,
F_117 ( 6 ) ,
F_100 , L_98 ,
V_4 ) ;
if ( V_64 == 0 )
V_4 -> V_22 = true ;
}
break;
default:
break;
}
V_4 -> V_251 = true ;
for ( V_6 = 0 ; V_6 < F_4 ( V_4 -> V_248 ) ; V_6 ++ ) {
V_64 = F_115 ( V_4 -> V_4 ,
V_469 + V_6 ,
F_62 , L_99 ,
& V_4 -> V_248 [ V_6 ] ) ;
if ( V_64 != 0 )
V_4 -> V_251 = false ;
}
F_29 ( V_2 -> V_29 ) ;
V_64 = F_82 ( V_151 -> V_368 , V_470 , & V_53 ) ;
if ( V_64 < 0 ) {
F_57 ( V_2 -> V_29 , L_100 , V_64 ) ;
goto V_471;
}
if ( ( V_53 & V_472 ) != V_473 ) {
V_4 -> V_327 [ 0 ] = 1 ;
V_474 [ 0 ] . V_475 = 1 ;
} else {
V_4 -> V_327 [ 0 ] = 0 ;
}
V_64 = F_82 ( V_151 -> V_368 , V_476 , & V_53 ) ;
if ( V_64 < 0 ) {
F_57 ( V_2 -> V_29 , L_101 , V_64 ) ;
goto V_471;
}
if ( ( V_53 & V_472 ) != V_473 ) {
V_4 -> V_327 [ 1 ] = 1 ;
V_474 [ 1 ] . V_475 = 1 ;
} else {
V_4 -> V_327 [ 1 ] = 0 ;
}
F_34 ( V_2 -> V_29 ) ;
for ( V_6 = 0 ; V_6 < F_4 ( V_176 ) ; V_6 ++ )
F_6 ( V_2 , V_176 [ V_6 ] . V_53 ,
V_176 [ V_6 ] . V_63 ,
V_176 [ V_6 ] . V_63 ) ;
F_6 ( V_2 , V_477 ,
1 << V_478 ,
1 << V_478 ) ;
F_6 ( V_2 , V_479 ,
1 << V_480 ,
1 << V_480 ) ;
F_6 ( V_2 , V_481 ,
1 << V_482 ,
1 << V_482 ) ;
switch ( V_151 -> type ) {
case V_157 :
case V_158 :
F_6 ( V_2 , V_161 ,
V_483 , V_483 ) ;
break;
default:
break;
}
switch ( V_151 -> type ) {
case V_158 :
case V_271 :
F_6 ( V_2 , V_272 ,
V_273 , V_273 ) ;
F_6 ( V_2 , V_274 ,
V_275 , V_275 ) ;
break;
default:
break;
}
V_4 -> V_132 . V_484 = F_36 ;
F_52 ( V_2 ) ;
F_87 ( V_4 ) ;
F_118 ( V_2 ) ;
F_86 ( V_2 , V_485 ,
F_4 ( V_485 ) ) ;
F_119 ( V_49 , V_486 ,
F_4 ( V_486 ) ) ;
switch ( V_151 -> type ) {
case V_157 :
F_119 ( V_49 , V_487 ,
F_4 ( V_487 ) ) ;
if ( V_4 -> V_249 < 4 ) {
F_119 ( V_49 , V_488 ,
F_4 ( V_488 ) ) ;
F_119 ( V_49 , V_489 ,
F_4 ( V_489 ) ) ;
F_119 ( V_49 , V_490 ,
F_4 ( V_490 ) ) ;
} else {
F_119 ( V_49 , V_491 ,
F_4 ( V_491 ) ) ;
F_119 ( V_49 , V_492 ,
F_4 ( V_492 ) ) ;
F_119 ( V_49 , V_493 ,
F_4 ( V_493 ) ) ;
}
break;
case V_158 :
F_86 ( V_2 , V_494 ,
F_4 ( V_494 ) ) ;
F_119 ( V_49 , V_495 ,
F_4 ( V_495 ) ) ;
if ( V_4 -> V_249 < 1 ) {
F_119 ( V_49 , V_488 ,
F_4 ( V_488 ) ) ;
F_119 ( V_49 , V_489 ,
F_4 ( V_489 ) ) ;
F_119 ( V_49 , V_490 ,
F_4 ( V_490 ) ) ;
} else {
F_119 ( V_49 , V_491 ,
F_4 ( V_491 ) ) ;
F_119 ( V_49 , V_492 ,
F_4 ( V_492 ) ) ;
F_119 ( V_49 , V_493 ,
F_4 ( V_493 ) ) ;
}
break;
case V_271 :
F_86 ( V_2 , V_494 ,
F_4 ( V_494 ) ) ;
F_119 ( V_49 , V_495 ,
F_4 ( V_495 ) ) ;
F_119 ( V_49 , V_491 ,
F_4 ( V_491 ) ) ;
F_119 ( V_49 , V_492 ,
F_4 ( V_492 ) ) ;
F_119 ( V_49 , V_493 ,
F_4 ( V_493 ) ) ;
break;
}
F_120 ( V_2 , 0 , 0 ) ;
F_121 ( V_49 , V_496 , F_4 ( V_496 ) ) ;
switch ( V_151 -> type ) {
case V_157 :
F_121 ( V_49 , V_497 ,
F_4 ( V_497 ) ) ;
if ( V_4 -> V_249 < 4 ) {
F_121 ( V_49 , V_498 ,
F_4 ( V_498 ) ) ;
F_121 ( V_49 , V_499 ,
F_4 ( V_499 ) ) ;
} else {
F_121 ( V_49 , V_500 ,
F_4 ( V_500 ) ) ;
}
break;
case V_158 :
if ( V_4 -> V_249 < 1 ) {
F_121 ( V_49 , V_498 ,
F_4 ( V_498 ) ) ;
F_121 ( V_49 , V_499 ,
F_4 ( V_499 ) ) ;
} else {
F_121 ( V_49 , V_500 ,
F_4 ( V_500 ) ) ;
F_121 ( V_49 , V_501 ,
F_4 ( V_501 ) ) ;
}
F_122 ( V_2 ) ;
break;
case V_271 :
F_121 ( V_49 , V_500 ,
F_4 ( V_500 ) ) ;
F_121 ( V_49 , V_501 ,
F_4 ( V_501 ) ) ;
break;
}
return 0 ;
V_471:
if ( V_4 -> V_22 )
F_123 ( V_4 -> V_4 , F_117 ( 6 ) , V_4 ) ;
F_123 ( V_4 -> V_4 , V_468 , V_4 ) ;
F_123 ( V_4 -> V_4 , V_467 , V_4 ) ;
F_123 ( V_4 -> V_4 , V_466 , V_4 ) ;
if ( V_4 -> V_445 )
F_124 ( V_4 -> V_445 , V_4 ) ;
for ( V_6 = 0 ; V_6 < F_4 ( V_4 -> V_248 ) ; V_6 ++ )
F_123 ( V_4 -> V_4 , V_469 + V_6 ,
& V_4 -> V_248 [ V_6 ] ) ;
F_123 ( V_4 -> V_4 , V_462 ,
& V_4 -> V_132 ) ;
F_123 ( V_4 -> V_4 , V_459 , V_2 ) ;
F_123 ( V_4 -> V_4 , V_461 , V_2 ) ;
F_123 ( V_4 -> V_4 , V_460 , V_2 ) ;
return V_64 ;
}
static int F_125 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_151 = V_4 -> V_4 ;
int V_6 ;
F_66 ( V_2 , V_278 ) ;
F_126 ( V_2 -> V_29 ) ;
for ( V_6 = 0 ; V_6 < F_4 ( V_4 -> V_248 ) ; V_6 ++ )
F_123 ( V_4 -> V_4 , V_469 + V_6 ,
& V_4 -> V_248 [ V_6 ] ) ;
F_123 ( V_4 -> V_4 , V_462 ,
& V_4 -> V_132 ) ;
F_123 ( V_4 -> V_4 , V_459 , V_2 ) ;
F_123 ( V_4 -> V_4 , V_461 , V_2 ) ;
F_123 ( V_4 -> V_4 , V_460 , V_2 ) ;
if ( V_4 -> V_22 )
F_123 ( V_4 -> V_4 , F_117 ( 6 ) , V_4 ) ;
switch ( V_151 -> type ) {
case V_157 :
if ( V_4 -> V_445 )
F_124 ( V_4 -> V_445 , V_4 ) ;
F_123 ( V_4 -> V_4 , V_467 ,
V_4 ) ;
F_123 ( V_4 -> V_4 , V_466 ,
V_4 ) ;
F_123 ( V_4 -> V_4 , V_447 ,
V_4 ) ;
break;
case V_271 :
case V_158 :
if ( V_4 -> V_445 )
F_124 ( V_4 -> V_445 , V_4 ) ;
break;
}
F_127 ( V_4 -> V_502 ) ;
F_127 ( V_4 -> V_503 ) ;
F_127 ( V_4 -> V_504 ) ;
F_128 ( V_4 -> V_97 ) ;
return 0 ;
}
static int T_5 F_129 ( struct V_505 * V_506 )
{
struct V_3 * V_4 ;
V_4 = F_89 ( & V_506 -> V_29 , sizeof( struct V_3 ) ,
V_381 ) ;
if ( V_4 == NULL )
return - V_507 ;
F_130 ( V_506 , V_4 ) ;
V_4 -> V_4 = F_108 ( V_506 -> V_29 . V_442 ) ;
V_4 -> V_13 = F_131 ( V_506 -> V_29 . V_442 ) ;
return F_132 ( & V_506 -> V_29 , & V_508 ,
V_474 , F_4 ( V_474 ) ) ;
}
static int T_6 F_133 ( struct V_505 * V_506 )
{
F_134 ( & V_506 -> V_29 ) ;
return 0 ;
}
static int F_135 ( struct V_404 * V_29 )
{
struct V_3 * V_4 = F_108 ( V_29 ) ;
if ( V_4 -> V_22 && ! V_4 -> V_102 )
F_136 ( V_4 -> V_4 -> V_368 , V_106 ,
V_107 ,
V_4 -> V_104 ) ;
return 0 ;
}
static int F_137 ( struct V_404 * V_29 )
{
struct V_3 * V_4 = F_108 ( V_29 ) ;
if ( V_4 -> V_22 && V_4 -> V_15 )
F_136 ( V_4 -> V_4 -> V_368 , V_106 ,
V_107 ,
V_103 ) ;
return 0 ;
}
