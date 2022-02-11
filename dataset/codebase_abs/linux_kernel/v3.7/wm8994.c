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
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_113 ) {
case V_114 :
return F_8 ( V_2 ) ;
case V_115 :
if ( V_4 -> V_22 && ! V_4 -> V_116 ) {
F_28 ( & V_4 -> V_117 ,
F_29 ( 1000 ) ) ;
V_4 -> V_116 = true ;
}
break;
case V_118 :
F_8 ( V_2 ) ;
break;
}
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_31 ( V_2 -> V_29 ) ;
V_4 -> V_119 ++ ;
F_5 ( V_2 -> V_29 , L_16 ,
V_4 -> V_119 ) ;
if ( V_4 -> V_119 == 1 ) {
F_6 ( V_2 , V_120 ,
V_121 |
V_122 , 0 ) ;
F_32 ( V_2 ) ;
switch ( V_4 -> V_123 ) {
default:
F_33 ( NULL == L_17 ) ;
case V_124 :
F_6 ( V_2 , V_106 ,
V_125 |
V_126 |
V_127 |
V_128 |
V_129 ,
V_125 |
V_127 |
V_128 |
( 0x3 << V_130 ) ) ;
F_6 ( V_2 , V_131 ,
V_132 |
V_133 ,
V_132 | 0x2 ) ;
F_34 ( 50 ) ;
F_6 ( V_2 , V_106 ,
V_129 |
V_125 ,
0 ) ;
break;
case V_134 :
F_6 ( V_2 , V_106 ,
V_125 |
V_126 |
V_127 |
V_128 |
V_129 ,
V_125 |
V_127 |
V_128 |
( 0x2 << V_130 ) ) ;
F_6 ( V_2 , V_131 ,
V_132 |
V_133 ,
V_132 | 0x2 ) ;
F_34 ( 400 ) ;
F_6 ( V_2 , V_106 ,
V_129 |
V_125 ,
0 ) ;
break;
}
}
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_119 -- ;
F_5 ( V_2 -> V_29 , L_18 ,
V_4 -> V_119 ) ;
if ( V_4 -> V_119 == 0 ) {
if ( V_4 -> V_135 . V_136 )
F_6 ( V_2 , V_137 ,
V_138 |
V_139 ,
V_138 |
V_139 ) ;
if ( V_4 -> V_135 . V_140 )
F_6 ( V_2 , V_137 ,
V_141 |
V_142 ,
V_141 |
V_142 ) ;
F_6 ( V_2 , V_106 ,
V_125 |
V_126 ,
V_125 |
V_126 ) ;
switch ( V_4 -> V_123 ) {
case V_134 :
F_34 ( 350 ) ;
break;
default:
break;
}
F_6 ( V_2 , V_143 ,
V_144 , V_144 ) ;
F_6 ( V_2 , V_120 ,
V_121 |
V_122 ,
V_121 |
V_122 ) ;
F_34 ( 150 ) ;
F_6 ( V_2 , V_137 ,
V_138 |
V_139 |
V_141 |
V_142 , 0 ) ;
F_6 ( V_2 , V_143 ,
V_144 , 0 ) ;
F_6 ( V_2 , V_106 ,
V_125 |
V_127 |
V_128 |
V_129 , 0 ) ;
F_6 ( V_2 , V_131 ,
V_132 | V_133 , 0 ) ;
F_6 ( V_2 , V_106 ,
V_129 , 0 ) ;
}
F_36 ( V_2 -> V_29 ) ;
}
static int F_37 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
switch ( V_113 ) {
case V_114 :
F_30 ( V_2 ) ;
break;
case V_118 :
F_35 ( V_2 ) ;
break;
}
return 0 ;
}
static bool F_38 ( struct V_1 * V_2 )
{
int V_51 = 0 ;
int V_53 , V_145 ;
V_53 = F_3 ( V_2 , V_146 ) ;
switch ( V_53 ) {
case V_147 :
F_39 ( V_2 -> V_29 , L_19 ) ;
V_51 = 2 << V_148 ;
break;
case V_149 :
F_39 ( V_2 -> V_29 , L_20 ) ;
V_51 = 1 << V_148 ;
break;
case V_150 :
F_39 ( V_2 -> V_29 , L_21 ) ;
V_51 = 0 << V_148 ;
break;
default:
F_39 ( V_2 -> V_29 , L_22 , V_53 ) ;
return false ;
}
V_145 = F_3 ( V_2 , V_151 ) ;
if ( V_145 != V_53 ) {
F_39 ( V_2 -> V_29 , L_23 ) ;
return false ;
}
F_6 ( V_2 , V_152 ,
V_153 , V_51 ) ;
return true ;
}
static int F_40 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_154 = V_2 -> V_155 ;
int V_63 = V_156 | V_157 ;
int V_6 ;
int V_158 ;
int V_159 ;
int V_8 ;
switch ( V_154 -> type ) {
case V_160 :
case V_161 :
V_63 |= V_162 | V_163 ;
break;
default:
break;
}
switch ( V_113 ) {
case V_114 :
if ( V_4 -> V_164 [ 0 ] <= 2 )
V_63 &= ~ ( V_162 | V_163 ) ;
V_8 = F_3 ( V_2 , V_165 ) ;
if ( ( V_8 & V_166 ) &&
( V_8 & V_167 ) )
V_159 = V_168 | V_169 ;
else if ( ! ( V_8 & V_166 ) &&
! ( V_8 & V_167 ) )
V_159 = V_170 | V_171 ;
else
V_159 = V_168 | V_169 |
V_170 | V_171 ;
V_8 = F_3 ( V_2 , V_172 ) ;
if ( ( V_8 & V_173 ) &&
( V_8 & V_174 ) )
V_158 = V_157 | V_163 ;
else if ( ! ( V_8 & V_173 ) &&
! ( V_8 & V_174 ) )
V_158 = V_156 | V_162 ;
else
V_158 = V_157 | V_163 |
V_156 | V_162 ;
F_6 ( V_2 , V_175 ,
V_63 , V_159 ) ;
F_6 ( V_2 , V_176 ,
V_63 , V_158 ) ;
F_6 ( V_2 , V_18 ,
V_177 |
V_178 ,
V_177 |
V_178 ) ;
F_6 ( V_2 , V_175 , V_63 ,
V_168 |
V_170 |
V_169 |
V_171 ) ;
F_6 ( V_2 , V_176 , V_63 ,
V_157 |
V_156 |
V_163 |
V_162 ) ;
break;
case V_115 :
for ( V_6 = 0 ; V_6 < F_4 ( V_179 ) ; V_6 ++ )
F_41 ( V_2 , V_179 [ V_6 ] . V_53 ,
F_3 ( V_2 ,
V_179 [ V_6 ] . V_53 ) ) ;
break;
case V_180 :
case V_118 :
F_6 ( V_2 , V_176 ,
V_63 , 0 ) ;
F_6 ( V_2 , V_175 ,
V_63 , 0 ) ;
V_8 = F_3 ( V_2 , V_18 ) ;
if ( V_8 & V_181 )
V_8 = V_178 ;
else
V_8 = 0 ;
F_6 ( V_2 , V_18 ,
V_178 |
V_177 , V_8 ) ;
break;
}
return 0 ;
}
static int F_42 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
int V_6 ;
int V_158 ;
int V_159 ;
int V_8 ;
switch ( V_113 ) {
case V_114 :
V_8 = F_3 ( V_2 , V_182 ) ;
if ( ( V_8 & V_183 ) &&
( V_8 & V_184 ) )
V_159 = V_185 ;
else if ( ! ( V_8 & V_183 ) &&
! ( V_8 & V_184 ) )
V_159 = V_186 ;
else
V_159 = V_186 | V_185 ;
V_8 = F_3 ( V_2 , V_187 ) ;
if ( ( V_8 & V_188 ) &&
( V_8 & V_189 ) )
V_158 = V_190 ;
else if ( ! ( V_8 & V_188 ) &&
! ( V_8 & V_189 ) )
V_158 = V_191 ;
else
V_158 = V_191 | V_190 ;
F_6 ( V_2 , V_175 ,
V_186 |
V_185 , V_159 ) ;
F_6 ( V_2 , V_176 ,
V_191 |
V_190 , V_158 ) ;
F_6 ( V_2 , V_18 ,
V_181 |
V_178 ,
V_181 |
V_178 ) ;
F_6 ( V_2 , V_175 ,
V_186 |
V_185 ,
V_186 |
V_185 ) ;
F_6 ( V_2 , V_176 ,
V_191 |
V_190 ,
V_191 |
V_190 ) ;
break;
case V_115 :
for ( V_6 = 0 ; V_6 < F_4 ( V_179 ) ; V_6 ++ )
F_41 ( V_2 , V_179 [ V_6 ] . V_53 ,
F_3 ( V_2 ,
V_179 [ V_6 ] . V_53 ) ) ;
break;
case V_180 :
case V_118 :
F_6 ( V_2 , V_176 ,
V_191 |
V_190 , 0 ) ;
F_6 ( V_2 , V_175 ,
V_186 |
V_185 , 0 ) ;
V_8 = F_3 ( V_2 , V_18 ) ;
if ( V_8 & V_177 )
V_8 = V_178 ;
else
V_8 = 0 ;
F_6 ( V_2 , V_18 ,
V_178 |
V_181 , V_8 ) ;
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
V_4 -> V_192 = 1 ;
break;
case V_118 :
V_4 -> V_193 = 1 ;
break;
}
return 0 ;
}
static int F_44 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_113 ) {
case V_114 :
V_4 -> V_194 = 1 ;
break;
case V_118 :
V_4 -> V_195 = 1 ;
break;
}
return 0 ;
}
static int F_45 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_113 ) {
case V_114 :
if ( V_4 -> V_192 ) {
F_40 ( V_112 , V_57 , V_114 ) ;
F_6 ( V_2 , V_45 ,
V_196 ,
V_197 ) ;
F_40 ( V_112 , V_57 , V_115 ) ;
V_4 -> V_192 = 0 ;
}
if ( V_4 -> V_194 ) {
F_42 ( V_112 , V_57 , V_114 ) ;
F_6 ( V_2 , V_198 ,
V_199 ,
V_200 ) ;
F_42 ( V_112 , V_57 , V_115 ) ;
V_4 -> V_194 = 0 ;
}
break;
}
F_46 ( V_112 , V_57 , V_113 ) ;
return 0 ;
}
static int F_47 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_113 ) {
case V_118 :
if ( V_4 -> V_193 ) {
F_40 ( V_112 , V_57 , V_180 ) ;
F_6 ( V_2 , V_45 ,
V_196 , 0 ) ;
F_40 ( V_112 , V_57 , V_118 ) ;
V_4 -> V_193 = 0 ;
}
if ( V_4 -> V_195 ) {
F_42 ( V_112 , V_57 , V_180 ) ;
F_6 ( V_2 , V_198 ,
V_199 , 0 ) ;
F_42 ( V_112 , V_57 , V_118 ) ;
V_4 -> V_195 = 0 ;
}
break;
}
return 0 ;
}
static int F_48 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
F_45 ( V_112 , V_57 , V_113 ) ;
return 0 ;
}
static int F_49 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
F_45 ( V_112 , V_57 , V_113 ) ;
return 0 ;
}
static int F_50 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
unsigned int V_63 = 1 << V_112 -> V_65 ;
F_6 ( V_2 , V_176 ,
V_63 , V_63 ) ;
return 0 ;
}
static int F_51 ( struct V_50 * V_112 ,
struct V_56 * V_57 , int V_113 )
{
struct V_1 * V_2 = V_112 -> V_2 ;
F_5 ( V_2 -> V_29 , L_24 ,
F_3 ( V_2 ,
V_201 ) ) ;
return 0 ;
}
static int F_52 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_202 * V_203 = F_12 ( V_57 ) ;
struct V_50 * V_112 = V_203 -> V_204 [ 0 ] ;
struct V_1 * V_2 = V_112 -> V_2 ;
int V_64 ;
V_64 = F_53 ( V_57 , V_59 ) ;
F_54 ( V_2 ) ;
return V_64 ;
}
static int F_55 ( struct V_205 * V_40 ,
int V_206 , int V_207 )
{
T_2 V_208 ;
unsigned int V_209 , V_210 , V_211 ;
F_56 ( L_25 , V_206 , V_207 ) ;
V_40 -> V_212 = 0 ;
while ( V_206 > 13500000 ) {
V_40 -> V_212 ++ ;
V_206 /= 2 ;
if ( V_40 -> V_212 > 3 )
return - V_43 ;
}
F_56 ( L_26 , V_40 -> V_212 , V_206 ) ;
V_40 -> V_213 = 3 ;
while ( V_207 * ( V_40 -> V_213 + 1 ) < 90000000 ) {
V_40 -> V_213 ++ ;
if ( V_40 -> V_213 > 63 )
return - V_43 ;
}
V_207 *= V_40 -> V_213 + 1 ;
F_56 ( L_27 , V_40 -> V_213 , V_207 ) ;
if ( V_206 > 1000000 ) {
V_40 -> V_214 = 0 ;
} else if ( V_206 > 256000 ) {
V_40 -> V_214 = 1 ;
V_206 *= 2 ;
} else if ( V_206 > 128000 ) {
V_40 -> V_214 = 2 ;
V_206 *= 4 ;
} else if ( V_206 > 64000 ) {
V_40 -> V_214 = 3 ;
V_206 *= 8 ;
} else {
V_40 -> V_214 = 4 ;
V_206 *= 16 ;
}
F_56 ( L_28 , V_40 -> V_214 , V_206 ) ;
V_210 = V_207 / V_206 ;
V_40 -> V_215 = V_210 ;
V_211 = V_207 % V_206 ;
F_56 ( L_29 , V_211 ) ;
V_208 = V_216 * ( long long ) V_211 ;
F_57 ( V_208 , V_206 ) ;
V_209 = V_208 & 0xFFFFFFFF ;
if ( ( V_209 % 10 ) >= 5 )
V_209 += 5 ;
V_40 -> V_217 = V_209 / 10 ;
F_56 ( L_30 , V_40 -> V_215 , V_40 -> V_217 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , int V_83 , int V_218 ,
unsigned int V_206 , unsigned int V_207 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_154 = V_4 -> V_4 ;
int V_219 , V_64 ;
struct V_205 V_40 ;
T_1 V_53 , V_220 , V_221 , V_222 ;
unsigned long V_223 ;
bool V_224 ;
switch ( V_83 ) {
case V_225 :
V_219 = 0 ;
V_83 = 0 ;
V_222 = 0x10 ;
break;
case V_226 :
V_219 = 0x20 ;
V_83 = 1 ;
V_222 = 0x18 ;
break;
default:
return - V_43 ;
}
V_53 = F_3 ( V_2 , V_227 + V_219 ) ;
V_224 = V_53 & V_228 ;
switch ( V_218 ) {
case 0 :
if ( V_207 )
return - V_43 ;
V_218 = V_4 -> V_40 [ V_83 ] . V_218 ;
break;
case V_229 :
case V_230 :
case V_231 :
case V_232 :
break;
case V_233 :
V_206 = 12000000 ;
V_207 = 12000000 ;
break;
default:
return - V_43 ;
}
if ( V_4 -> V_40 [ V_83 ] . V_218 == V_218 &&
V_4 -> V_40 [ V_83 ] . V_234 == V_206 && V_4 -> V_40 [ V_83 ] . V_41 == V_207 )
return 0 ;
if ( V_207 )
V_64 = F_55 ( & V_40 , V_206 , V_207 ) ;
else
V_64 = F_55 ( & V_40 , V_4 -> V_40 [ V_83 ] . V_234 ,
V_4 -> V_40 [ V_83 ] . V_41 ) ;
if ( V_64 < 0 )
return V_64 ;
V_220 = F_3 ( V_2 , V_18 ) ;
if ( V_220 & V_19 )
V_221 = V_198 ;
else
V_221 = V_45 ;
V_53 = F_3 ( V_2 , V_221 ) ;
if ( ( V_53 & V_197 ) &&
( V_53 & V_46 ) == V_222 ) {
F_59 ( V_2 -> V_29 , L_31 ,
V_83 + 1 ) ;
return - V_235 ;
}
F_6 ( V_2 , V_227 + V_219 ,
V_228 , 0 ) ;
if ( V_4 -> V_236 && V_218 == V_232 &&
V_206 == V_207 && V_207 ) {
F_5 ( V_2 -> V_29 , L_32 , V_83 + 1 ) ;
F_6 ( V_2 , V_237 + V_219 ,
V_238 , V_238 ) ;
goto V_41;
}
V_53 = ( V_40 . V_213 << V_239 ) |
( V_40 . V_214 << V_240 ) ;
F_6 ( V_2 , V_241 + V_219 ,
V_242 |
V_243 , V_53 ) ;
F_6 ( V_2 , V_244 + V_219 ,
V_245 , V_40 . V_217 ) ;
F_6 ( V_2 , V_246 + V_219 ,
V_247 ,
V_40 . V_215 << V_248 ) ;
F_6 ( V_2 , V_237 + V_219 ,
V_249 | V_238 |
V_250 |
V_251 ,
( ( V_218 == V_233 )
<< V_252 ) |
( V_40 . V_212 << V_253 ) |
( V_218 - 1 ) ) ;
F_60 ( & V_4 -> V_254 [ V_83 ] ) ;
if ( V_207 ) {
if ( ! V_224 ) {
F_23 ( V_2 ) ;
switch ( V_154 -> type ) {
case V_160 :
F_30 ( V_2 ) ;
break;
case V_161 :
if ( V_4 -> V_255 < 1 )
F_30 ( V_2 ) ;
break;
default:
break;
}
}
V_53 = V_228 ;
if ( V_40 . V_217 )
V_53 |= V_256 ;
if ( V_218 == V_233 )
V_53 |= V_257 ;
F_6 ( V_2 , V_227 + V_219 ,
V_228 | V_257 |
V_256 , V_53 ) ;
if ( V_4 -> V_258 ) {
V_223 = F_61 ( & V_4 -> V_254 [ V_83 ] ,
F_29 ( 10 ) ) ;
if ( V_223 == 0 )
F_62 ( V_2 -> V_29 ,
L_33 ) ;
} else {
F_34 ( 5 ) ;
}
} else {
if ( V_224 ) {
switch ( V_154 -> type ) {
case V_160 :
F_35 ( V_2 ) ;
break;
case V_161 :
if ( V_4 -> V_255 < 1 )
F_35 ( V_2 ) ;
break;
default:
break;
}
F_26 ( V_2 ) ;
}
}
V_41:
V_4 -> V_40 [ V_83 ] . V_234 = V_206 ;
V_4 -> V_40 [ V_83 ] . V_41 = V_207 ;
V_4 -> V_40 [ V_83 ] . V_218 = V_218 ;
F_8 ( V_2 ) ;
return 0 ;
}
static T_3 F_63 ( int V_259 , void * V_260 )
{
struct V_261 * V_261 = V_260 ;
F_64 ( V_261 ) ;
return V_262 ;
}
static int F_65 ( struct V_263 * V_264 , int V_83 , int V_218 ,
unsigned int V_206 , unsigned int V_207 )
{
return F_58 ( V_264 -> V_2 , V_83 , V_218 , V_206 , V_207 ) ;
}
static int F_66 ( struct V_263 * V_264 ,
int V_265 , unsigned int V_266 , int V_267 )
{
struct V_1 * V_2 = V_264 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
switch ( V_264 -> V_83 ) {
case 1 :
case 2 :
break;
default:
return - V_43 ;
}
switch ( V_265 ) {
case V_36 :
V_4 -> V_7 [ V_264 -> V_83 - 1 ] = V_36 ;
V_4 -> V_37 [ 0 ] = V_266 ;
F_5 ( V_264 -> V_29 , L_34 ,
V_264 -> V_83 , V_266 ) ;
break;
case V_38 :
V_4 -> V_7 [ V_264 -> V_83 - 1 ] = V_38 ;
V_4 -> V_37 [ 1 ] = V_266 ;
F_5 ( V_264 -> V_29 , L_35 ,
V_264 -> V_83 , V_266 ) ;
break;
case V_39 :
V_4 -> V_7 [ V_264 -> V_83 - 1 ] = V_39 ;
F_5 ( V_264 -> V_29 , L_36 , V_264 -> V_83 ) ;
break;
case V_42 :
V_4 -> V_7 [ V_264 -> V_83 - 1 ] = V_42 ;
F_5 ( V_264 -> V_29 , L_37 , V_264 -> V_83 ) ;
break;
case V_268 :
if ( V_266 ) {
for ( V_6 = 0 ; V_6 < F_4 ( V_269 ) ; V_6 ++ )
if ( V_269 [ V_6 ] == V_266 )
break;
if ( V_6 == F_4 ( V_269 ) )
return - V_43 ;
F_6 ( V_2 , V_270 ,
V_271 , V_6 ) ;
F_6 ( V_2 , V_272 ,
V_273 , V_273 ) ;
} else {
F_6 ( V_2 , V_272 ,
V_273 , 0 ) ;
}
default:
return - V_43 ;
}
F_8 ( V_2 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 ,
enum V_274 V_275 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_154 = V_4 -> V_4 ;
F_68 ( V_2 , V_275 ) ;
switch ( V_275 ) {
case V_276 :
break;
case V_277 :
switch ( V_154 -> type ) {
case V_161 :
case V_278 :
F_6 ( V_2 , V_279 ,
V_280 , 0 ) ;
F_6 ( V_2 , V_281 ,
V_282 , 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_49 . V_283 == V_284 )
F_23 ( V_2 ) ;
break;
case V_284 :
if ( V_2 -> V_49 . V_283 == V_285 ) {
switch ( V_154 -> type ) {
case V_161 :
if ( V_4 -> V_255 == 0 ) {
F_6 ( V_2 ,
V_286 ,
V_287 ,
V_287 ) ;
}
break;
default:
break;
}
F_6 ( V_2 , V_120 ,
V_121 |
V_122 ,
V_121 |
V_122 ) ;
}
if ( V_2 -> V_49 . V_283 == V_277 )
F_26 ( V_2 ) ;
switch ( V_154 -> type ) {
case V_161 :
case V_278 :
F_6 ( V_2 , V_279 ,
V_280 ,
V_280 ) ;
F_6 ( V_2 , V_281 ,
V_282 ,
V_282 ) ;
break;
default:
break;
}
break;
case V_285 :
if ( V_2 -> V_49 . V_283 == V_284 )
V_4 -> V_288 = NULL ;
break;
}
V_2 -> V_49 . V_283 = V_275 ;
return 0 ;
}
int F_69 ( struct V_1 * V_2 , enum F_69 V_101 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_101 ) {
case V_124 :
if ( V_4 -> V_135 . V_136 ) {
F_70 ( & V_2 -> V_49 ,
L_38 ) ;
F_70 ( & V_2 -> V_49 ,
L_39 ) ;
}
if ( V_4 -> V_135 . V_140 ) {
F_70 ( & V_2 -> V_49 ,
L_40 ) ;
F_70 ( & V_2 -> V_49 ,
L_41 ) ;
}
F_9 ( & V_2 -> V_49 ) ;
V_4 -> V_123 = V_101 ;
break;
case V_134 :
if ( V_4 -> V_135 . V_136 ) {
F_71 ( & V_2 -> V_49 ,
L_38 ) ;
F_71 ( & V_2 -> V_49 ,
L_39 ) ;
}
if ( V_4 -> V_135 . V_140 ) {
F_71 ( & V_2 -> V_49 ,
L_40 ) ;
F_71 ( & V_2 -> V_49 ,
L_41 ) ;
}
V_4 -> V_123 = V_101 ;
F_9 ( & V_2 -> V_49 ) ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static int F_72 ( struct V_263 * V_264 , unsigned int V_289 )
{
struct V_1 * V_2 = V_264 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_154 = V_4 -> V_4 ;
int V_290 ;
int V_291 ;
int V_292 = 0 ;
int V_293 = 0 ;
switch ( V_264 -> V_83 ) {
case 1 :
V_290 = V_294 ;
V_291 = V_165 ;
break;
case 2 :
V_290 = V_295 ;
V_291 = V_182 ;
break;
default:
return - V_43 ;
}
switch ( V_289 & V_296 ) {
case V_297 :
break;
case V_298 :
V_292 = V_299 ;
break;
default:
return - V_43 ;
}
switch ( V_289 & V_300 ) {
case V_301 :
V_293 |= V_302 ;
case V_303 :
V_293 |= 0x18 ;
break;
case V_304 :
V_293 |= 0x10 ;
break;
case V_305 :
break;
case V_306 :
V_293 |= 0x8 ;
break;
default:
return - V_43 ;
}
switch ( V_289 & V_300 ) {
case V_303 :
case V_301 :
switch ( V_289 & V_307 ) {
case V_308 :
break;
case V_309 :
V_293 |= V_310 ;
break;
default:
return - V_43 ;
}
break;
case V_304 :
case V_305 :
case V_306 :
switch ( V_289 & V_307 ) {
case V_308 :
break;
case V_311 :
V_293 |= V_310 | V_302 ;
break;
case V_309 :
V_293 |= V_310 ;
break;
case V_312 :
V_293 |= V_302 ;
break;
default:
return - V_43 ;
}
break;
default:
return - V_43 ;
}
switch ( V_154 -> type ) {
case V_278 :
case V_161 :
if ( V_264 -> V_83 == 2 )
F_6 ( V_2 , V_313 ,
V_302 |
V_314 , V_293 ) ;
break;
default:
break;
}
F_6 ( V_2 , V_291 ,
V_310 | V_302 |
V_315 ,
V_293 ) ;
F_6 ( V_2 , V_290 , V_299 ,
V_292 ) ;
return 0 ;
}
static int F_73 ( struct V_316 * V_317 ,
struct V_318 * V_319 ,
struct V_263 * V_264 )
{
struct V_1 * V_2 = V_264 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_291 ;
int V_320 ;
int V_321 ;
int V_322 ;
int V_323 ;
int V_293 = 0 ;
int V_324 = 0 ;
int V_325 = 0 ;
int V_326 = 0 ;
int V_327 = 0 ;
int V_83 = V_264 -> V_83 - 1 ;
int V_6 , V_328 , V_91 , V_329 , V_5 ;
switch ( V_264 -> V_83 ) {
case 1 :
V_291 = V_165 ;
V_320 = V_172 ;
V_321 = V_330 ;
V_323 = V_331 ;
if ( V_317 -> V_332 == V_333 ||
V_4 -> V_334 [ 0 ] ) {
V_322 = V_335 ;
} else {
V_322 = V_336 ;
F_5 ( V_2 -> V_29 , L_42 ) ;
}
break;
case 2 :
V_291 = V_182 ;
V_320 = V_187 ;
V_321 = V_337 ;
V_323 = V_338 ;
if ( V_317 -> V_332 == V_333 ||
V_4 -> V_334 [ 1 ] ) {
V_322 = V_339 ;
} else {
V_322 = V_340 ;
F_5 ( V_2 -> V_29 , L_43 ) ;
}
break;
default:
return - V_43 ;
}
V_329 = F_74 ( V_319 ) ;
switch ( F_75 ( V_319 ) ) {
case V_341 :
V_329 *= 16 ;
break;
case V_342 :
V_329 *= 20 ;
V_293 |= 0x20 ;
break;
case V_343 :
V_329 *= 24 ;
V_293 |= 0x40 ;
break;
case V_344 :
V_329 *= 32 ;
V_293 |= 0x60 ;
break;
default:
return - V_43 ;
}
V_4 -> V_164 [ V_83 ] = F_76 ( V_319 ) ;
switch ( F_76 ( V_319 ) ) {
case 1 :
case 2 :
V_329 *= 2 ;
break;
default:
V_329 *= 4 ;
break;
}
for ( V_6 = 0 ; V_6 < F_4 ( V_345 ) ; V_6 ++ )
if ( V_345 [ V_6 ] . V_27 == F_74 ( V_319 ) )
break;
if ( V_6 == F_4 ( V_345 ) )
return - V_43 ;
V_327 |= V_345 [ V_6 ] . V_8 << V_346 ;
F_5 ( V_264 -> V_29 , L_44 , V_345 [ V_6 ] . V_27 ) ;
F_5 ( V_264 -> V_29 , L_45 ,
V_264 -> V_83 , V_4 -> V_20 [ V_83 ] , V_329 ) ;
if ( F_76 ( V_319 ) == 1 &&
( F_3 ( V_2 , V_291 ) & 0x18 ) == 0x18 )
V_324 |= V_347 ;
if ( V_4 -> V_20 [ V_83 ] == 0 ) {
F_59 ( V_264 -> V_29 , L_46 , V_264 -> V_83 ) ;
return - V_43 ;
}
V_5 = 0 ;
V_91 = abs ( ( V_348 [ 0 ] * F_74 ( V_319 ) )
- V_4 -> V_20 [ V_83 ] ) ;
for ( V_6 = 1 ; V_6 < F_4 ( V_348 ) ; V_6 ++ ) {
V_328 = abs ( ( V_348 [ V_6 ] * F_74 ( V_319 ) )
- V_4 -> V_20 [ V_83 ] ) ;
if ( V_328 >= V_91 )
continue;
V_5 = V_6 ;
V_91 = V_328 ;
}
F_5 ( V_264 -> V_29 , L_47 ,
V_264 -> V_83 , V_348 [ V_5 ] ) ;
V_327 |= V_5 ;
V_5 = 0 ;
for ( V_6 = 0 ; V_6 < F_4 ( V_349 ) ; V_6 ++ ) {
V_328 = ( V_4 -> V_20 [ V_83 ] * 10 / V_349 [ V_6 ] ) - V_329 ;
if ( V_328 < 0 )
break;
V_5 = V_6 ;
}
V_329 = V_4 -> V_20 [ V_83 ] * 10 / V_349 [ V_5 ] ;
F_5 ( V_264 -> V_29 , L_48 ,
V_349 [ V_5 ] , V_329 ) ;
V_325 |= V_5 << V_350 ;
V_326 = V_329 / F_74 ( V_319 ) ;
if ( ! V_326 ) {
F_59 ( V_264 -> V_29 , L_49 ,
V_329 ) ;
return - V_43 ;
}
F_5 ( V_264 -> V_29 , L_50 ,
V_326 , V_329 / V_326 ) ;
F_6 ( V_2 , V_291 , V_351 , V_293 ) ;
F_6 ( V_2 , V_320 , V_347 , V_324 ) ;
F_6 ( V_2 , V_321 , V_352 , V_325 ) ;
F_6 ( V_2 , V_322 , V_353 ,
V_326 ) ;
F_6 ( V_2 , V_323 , V_354 |
V_355 , V_327 ) ;
if ( V_317 -> V_332 == V_333 ) {
switch ( V_264 -> V_83 ) {
case 1 :
V_4 -> V_98 [ 0 ] = F_74 ( V_319 ) ;
F_18 ( V_2 , 0 ) ;
F_18 ( V_2 , 1 ) ;
break;
case 2 :
V_4 -> V_98 [ 1 ] = F_74 ( V_319 ) ;
F_18 ( V_2 , 2 ) ;
break;
}
}
return 0 ;
}
static int F_77 ( struct V_316 * V_317 ,
struct V_318 * V_319 ,
struct V_263 * V_264 )
{
struct V_1 * V_2 = V_264 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_154 = V_4 -> V_4 ;
int V_291 ;
int V_293 = 0 ;
switch ( V_264 -> V_83 ) {
case 3 :
switch ( V_154 -> type ) {
case V_278 :
case V_161 :
V_291 = V_313 ;
break;
default:
return 0 ;
}
default:
return 0 ;
}
switch ( F_75 ( V_319 ) ) {
case V_341 :
break;
case V_342 :
V_293 |= 0x20 ;
break;
case V_343 :
V_293 |= 0x40 ;
break;
case V_344 :
V_293 |= 0x60 ;
break;
default:
return - V_43 ;
}
return F_6 ( V_2 , V_291 , V_351 , V_293 ) ;
}
static int F_78 ( struct V_263 * V_356 , int V_357 )
{
struct V_1 * V_2 = V_356 -> V_2 ;
int V_358 ;
int V_53 ;
switch ( V_356 -> V_83 ) {
case 1 :
V_358 = V_359 ;
break;
case 2 :
V_358 = V_360 ;
break;
default:
return - V_43 ;
}
if ( V_357 )
V_53 = V_361 ;
else
V_53 = 0 ;
F_6 ( V_2 , V_358 , V_361 , V_53 ) ;
return 0 ;
}
static int F_79 ( struct V_263 * V_356 , int V_362 )
{
struct V_1 * V_2 = V_356 -> V_2 ;
int V_53 , V_8 , V_63 ;
switch ( V_356 -> V_83 ) {
case 1 :
V_53 = V_294 ;
V_63 = V_363 ;
break;
case 2 :
V_53 = V_295 ;
V_63 = V_364 ;
break;
default:
return - V_43 ;
}
if ( V_362 )
V_8 = V_63 ;
else
V_8 = 0 ;
return F_6 ( V_2 , V_53 , V_63 , V_8 ) ;
}
static int F_80 ( struct V_263 * V_264 )
{
struct V_1 * V_2 = V_264 -> V_2 ;
F_6 ( V_2 , V_365 ,
V_366 | V_367 , 0 ) ;
F_6 ( V_2 , V_368 ,
V_366 | V_367 , 0 ) ;
F_6 ( V_2 , V_369 ,
V_366 | V_367 , 0 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 , V_64 ;
for ( V_6 = 0 ; V_6 < F_4 ( V_4 -> V_40 ) ; V_6 ++ ) {
memcpy ( & V_4 -> V_370 [ V_6 ] , & V_4 -> V_40 [ V_6 ] ,
sizeof( struct V_371 ) ) ;
V_64 = F_58 ( V_2 , V_6 + 1 , 0 , 0 , 0 ) ;
if ( V_64 < 0 )
F_62 ( V_2 -> V_29 , L_51 ,
V_6 + 1 , V_64 ) ;
}
F_67 ( V_2 , V_285 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_154 = V_4 -> V_4 ;
int V_6 , V_64 ;
unsigned int V_8 , V_63 ;
if ( V_4 -> V_255 < 4 ) {
V_64 = F_83 ( V_154 -> V_372 ,
V_176 , & V_8 ) ;
V_2 -> V_373 = 1 ;
V_63 = V_374 | V_375 |
V_376 | V_377 ;
V_8 &= V_63 ;
F_6 ( V_2 , V_176 ,
V_63 , V_8 ) ;
V_2 -> V_373 = 0 ;
}
for ( V_6 = 0 ; V_6 < F_4 ( V_4 -> V_40 ) ; V_6 ++ ) {
if ( ! V_4 -> V_370 [ V_6 ] . V_41 )
continue;
V_64 = F_58 ( V_2 , V_6 + 1 ,
V_4 -> V_370 [ V_6 ] . V_218 ,
V_4 -> V_370 [ V_6 ] . V_234 ,
V_4 -> V_370 [ V_6 ] . V_41 ) ;
if ( V_64 < 0 )
F_62 ( V_2 -> V_29 , L_52 ,
V_6 + 1 , V_64 ) ;
}
return 0 ;
}
static void F_84 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_135 . V_2 ;
struct V_71 * V_13 = V_4 -> V_13 ;
struct V_378 V_379 [] = {
F_85 ( L_11 ,
V_4 -> V_380 ,
F_21 ,
F_20 ) ,
F_85 ( L_12 ,
V_4 -> V_380 ,
F_21 ,
F_20 ) ,
F_85 ( L_13 ,
V_4 -> V_380 ,
F_21 ,
F_20 ) ,
} ;
int V_64 , V_6 , V_381 ;
const char * * V_382 ;
V_4 -> V_92 = 0 ;
V_4 -> V_97 = NULL ;
for ( V_6 = 0 ; V_6 < V_13 -> V_95 ; V_6 ++ ) {
for ( V_381 = 0 ; V_381 < V_4 -> V_92 ; V_381 ++ ) {
if ( strcmp ( V_13 -> V_96 [ V_6 ] . V_55 ,
V_4 -> V_97 [ V_381 ] ) == 0 )
break;
}
if ( V_381 != V_4 -> V_92 )
continue;
V_382 = F_86 ( V_4 -> V_97 ,
sizeof( char * ) *
( V_4 -> V_92 + 1 ) ,
V_383 ) ;
if ( V_382 == NULL )
continue;
V_382 [ V_4 -> V_92 ] =
V_13 -> V_96 [ V_6 ] . V_55 ;
V_4 -> V_92 ++ ;
V_4 -> V_97 = V_382 ;
}
F_5 ( V_2 -> V_29 , L_53 ,
V_4 -> V_92 ) ;
V_4 -> V_380 . V_384 = V_4 -> V_92 ;
V_4 -> V_380 . V_385 = V_4 -> V_97 ;
V_64 = F_87 ( V_4 -> V_135 . V_2 , V_379 ,
F_4 ( V_379 ) ) ;
if ( V_64 != 0 )
F_59 ( V_4 -> V_135 . V_2 -> V_29 ,
L_54 , V_64 ) ;
}
static void F_88 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_135 . V_2 ;
struct V_71 * V_13 = V_4 -> V_13 ;
int V_64 , V_6 ;
if ( ! V_13 )
return;
F_89 ( V_2 , V_13 -> V_386 ,
V_13 -> V_387 ,
V_13 -> V_388 ,
V_13 -> V_389 ,
V_13 -> V_390 ,
V_13 -> V_391 ,
V_13 -> V_392 ,
V_13 -> V_393 ,
V_13 -> V_394 ,
V_13 -> V_395 ) ;
F_5 ( V_2 -> V_29 , L_55 , V_13 -> V_85 ) ;
if ( V_13 -> V_85 ) {
struct V_378 V_379 [] = {
F_85 ( L_7 , V_4 -> V_396 ,
F_17 , F_16 ) ,
F_85 ( L_8 , V_4 -> V_396 ,
F_17 , F_16 ) ,
F_85 ( L_9 , V_4 -> V_396 ,
F_17 , F_16 ) ,
} ;
V_4 -> V_397 = F_90 ( V_4 -> V_135 . V_2 -> V_29 ,
sizeof( char * ) * V_13 -> V_85 , V_383 ) ;
if ( ! V_4 -> V_397 ) {
F_59 ( V_4 -> V_135 . V_2 -> V_29 ,
L_56 ,
V_13 -> V_85 ) ;
return;
}
for ( V_6 = 0 ; V_6 < V_13 -> V_85 ; V_6 ++ )
V_4 -> V_397 [ V_6 ] = V_13 -> V_81 [ V_6 ] . V_55 ;
V_4 -> V_396 . V_384 = V_13 -> V_85 ;
V_4 -> V_396 . V_385 = V_4 -> V_397 ;
V_64 = F_87 ( V_4 -> V_135 . V_2 , V_379 ,
F_4 ( V_379 ) ) ;
for ( V_6 = 0 ; V_6 < V_398 ; V_6 ++ )
F_14 ( V_2 , V_6 ) ;
} else {
V_64 = F_87 ( V_4 -> V_135 . V_2 ,
V_399 ,
F_4 ( V_399 ) ) ;
}
if ( V_64 != 0 )
F_59 ( V_4 -> V_135 . V_2 -> V_29 ,
L_57 , V_64 ) ;
F_5 ( V_2 -> V_29 , L_58 ,
V_13 -> V_95 ) ;
if ( V_13 -> V_95 )
F_84 ( V_4 ) ;
else
F_87 ( V_4 -> V_135 . V_2 , V_400 ,
F_4 ( V_400 ) ) ;
for ( V_6 = 0 ; V_6 < F_4 ( V_13 -> V_401 ) ; V_6 ++ ) {
if ( V_13 -> V_401 [ V_6 ] ) {
F_41 ( V_2 , V_279 + V_6 ,
V_13 -> V_401 [ V_6 ] & 0xffff ) ;
}
}
}
int F_91 ( struct V_1 * V_2 , struct V_402 * V_403 ,
int V_401 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_404 * V_405 ;
struct V_4 * V_154 = V_4 -> V_4 ;
int V_53 , V_64 ;
if ( V_154 -> type != V_160 ) {
F_62 ( V_2 -> V_29 , L_59 ) ;
return - V_43 ;
}
switch ( V_401 ) {
case 1 :
V_405 = & V_4 -> V_405 [ 0 ] ;
if ( V_403 )
V_64 = F_71 ( & V_2 -> V_49 ,
L_60 ) ;
else
V_64 = F_70 ( & V_2 -> V_49 ,
L_60 ) ;
break;
case 2 :
V_405 = & V_4 -> V_405 [ 1 ] ;
if ( V_403 )
V_64 = F_71 ( & V_2 -> V_49 ,
L_60 ) ;
else
V_64 = F_70 ( & V_2 -> V_49 ,
L_60 ) ;
break;
default:
F_62 ( V_2 -> V_29 , L_61 , V_401 ) ;
return - V_43 ;
}
if ( V_64 != 0 )
F_62 ( V_2 -> V_29 , L_62 ,
V_401 , V_64 ) ;
F_5 ( V_2 -> V_29 , L_63 ,
V_401 , V_403 ) ;
V_405 -> V_403 = V_403 ;
V_405 -> V_406 = true ;
if ( V_4 -> V_405 [ 0 ] . V_403 || V_4 -> V_405 [ 1 ] . V_403 )
V_53 = V_407 ;
else
V_53 = 0 ;
F_6 ( V_2 , V_408 , V_407 , V_53 ) ;
F_6 ( V_2 , V_409 ,
V_410 | V_411 |
V_412 | V_413 ,
V_414 | V_415 ) ;
F_9 ( & V_2 -> V_49 ) ;
return 0 ;
}
static void F_92 ( struct V_416 * V_417 )
{
struct V_3 * V_418 = F_93 ( V_417 ,
struct V_3 ,
V_419 . V_417 ) ;
struct V_372 * V_372 = V_418 -> V_4 -> V_372 ;
struct V_420 * V_29 = V_418 -> V_4 -> V_29 ;
unsigned int V_53 ;
int V_64 ;
int V_421 ;
F_31 ( V_29 ) ;
V_64 = F_83 ( V_372 , V_422 , & V_53 ) ;
if ( V_64 < 0 ) {
F_59 ( V_29 , L_64 ,
V_64 ) ;
F_36 ( V_29 ) ;
return;
}
F_5 ( V_29 , L_65 , V_53 ) ;
V_421 = 0 ;
if ( V_53 & V_423 ) {
if ( V_418 -> V_405 [ 0 ] . V_406 )
V_421 = V_424 ;
}
if ( V_53 & V_425 ) {
if ( V_418 -> V_405 [ 0 ] . V_406 )
V_421 = V_426 ;
else
V_421 |= V_427 ;
}
if ( V_421 )
V_418 -> V_405 [ 0 ] . V_406 = false ;
else
V_418 -> V_405 [ 0 ] . V_406 = true ;
F_94 ( V_418 -> V_405 [ 0 ] . V_403 , V_421 ,
V_424 | V_427 ) ;
V_421 = 0 ;
if ( V_53 & V_428 ) {
if ( V_418 -> V_405 [ 1 ] . V_406 )
V_421 = V_424 ;
}
if ( V_53 & V_429 ) {
if ( V_418 -> V_405 [ 1 ] . V_406 )
V_421 = V_426 ;
else
V_421 |= V_427 ;
}
if ( V_421 )
V_418 -> V_405 [ 1 ] . V_406 = false ;
else
V_418 -> V_405 [ 1 ] . V_406 = true ;
F_94 ( V_418 -> V_405 [ 1 ] . V_403 , V_421 ,
V_424 | V_427 ) ;
F_36 ( V_29 ) ;
}
static T_3 F_95 ( int V_259 , void * V_260 )
{
struct V_3 * V_418 = V_260 ;
struct V_1 * V_2 = V_418 -> V_135 . V_2 ;
#ifndef F_96
F_97 ( F_98 ( V_2 -> V_29 ) ) ;
#endif
F_99 ( V_2 -> V_29 , 300 ) ;
F_28 ( & V_418 -> V_419 , F_29 ( 250 ) ) ;
return V_262 ;
}
static void V_16 ( T_1 V_430 , void * V_260 )
{
struct V_1 * V_2 = V_260 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_421 ;
F_5 ( V_2 -> V_29 , L_66 , V_430 ) ;
if ( ! ( V_430 & V_431 ) ) {
if ( ! V_4 -> V_22 ) {
F_5 ( V_2 -> V_29 , L_67 ) ;
V_4 -> V_17 = false ;
V_4 -> V_109 = true ;
F_1 ( V_2 ) ;
F_94 ( V_4 -> V_405 [ 0 ] . V_403 , 0 ,
V_4 -> V_432 |
V_424 ) ;
}
return;
}
if ( V_4 -> V_109 && ( V_430 & 0x600 ) ) {
F_5 ( V_2 -> V_29 , L_68 ) ;
V_4 -> V_109 = false ;
V_4 -> V_17 = true ;
F_1 ( V_2 ) ;
F_94 ( V_4 -> V_405 [ 0 ] . V_403 , V_424 ,
V_424 ) ;
}
if ( V_4 -> V_109 && V_430 & 0xfc ) {
F_5 ( V_2 -> V_29 , L_69 ) ;
V_4 -> V_109 = false ;
F_1 ( V_2 ) ;
if ( V_4 -> V_22 ) {
F_24 ( & V_4 -> V_108 ) ;
F_6 ( V_2 , V_30 ,
V_433 , 0 ) ;
F_22 ( V_2 ,
V_111 ) ;
F_25 ( & V_4 -> V_108 ) ;
if ( V_4 -> V_13 -> V_434 )
F_70 ( & V_2 -> V_49 ,
L_70 ) ;
}
F_94 ( V_4 -> V_405 [ 0 ] . V_403 , V_426 ,
V_424 ) ;
}
if ( V_4 -> V_17 ) {
V_421 = 0 ;
if ( V_430 & 0x4 )
V_421 |= V_427 ;
if ( V_430 & 0x8 )
V_421 |= V_435 ;
if ( V_430 & 0x10 )
V_421 |= V_436 ;
if ( V_430 & 0x20 )
V_421 |= V_437 ;
if ( V_430 & 0x40 )
V_421 |= V_438 ;
if ( V_430 & 0x80 )
V_421 |= V_439 ;
F_94 ( V_4 -> V_405 [ 0 ] . V_403 , V_421 ,
V_4 -> V_432 ) ;
}
}
static T_3 F_100 ( int V_259 , void * V_260 )
{
struct V_3 * V_4 = V_260 ;
struct V_1 * V_2 = V_4 -> V_135 . V_2 ;
int V_53 ;
bool V_440 ;
F_31 ( V_2 -> V_29 ) ;
F_24 ( & V_4 -> V_108 ) ;
V_53 = F_3 ( V_2 , V_441 ) ;
if ( V_53 < 0 ) {
F_59 ( V_2 -> V_29 , L_71 , V_53 ) ;
F_25 ( & V_4 -> V_108 ) ;
F_36 ( V_2 -> V_29 ) ;
return V_442 ;
}
F_5 ( V_2 -> V_29 , L_72 , V_53 ) ;
V_440 = V_53 & V_443 ;
if ( V_440 ) {
F_5 ( V_2 -> V_29 , L_73 ) ;
F_1 ( V_2 ) ;
F_6 ( V_2 , V_281 ,
V_444 , 0 ) ;
F_6 ( V_2 , V_441 ,
V_445 , 0 ) ;
V_4 -> V_109 = true ;
F_22 ( V_2 , V_110 ) ;
F_6 ( V_2 , V_30 ,
V_433 , V_433 ) ;
} else {
F_5 ( V_2 -> V_29 , L_74 ) ;
F_6 ( V_2 , V_281 ,
V_444 , V_444 ) ;
F_6 ( V_2 , V_441 ,
V_445 , V_445 ) ;
V_4 -> V_109 = false ;
V_4 -> V_17 = false ;
F_6 ( V_2 , V_30 ,
V_433 , 0 ) ;
F_22 ( V_2 , V_111 ) ;
}
F_25 ( & V_4 -> V_108 ) ;
if ( V_4 -> V_13 -> V_434 ) {
if ( V_440 )
F_71 ( & V_2 -> V_49 ,
L_70 ) ;
else
F_70 ( & V_2 -> V_49 , L_70 ) ;
}
if ( V_440 )
F_94 ( V_4 -> V_405 [ 0 ] . V_403 ,
V_446 , V_446 ) ;
else
F_94 ( V_4 -> V_405 [ 0 ] . V_403 , 0 ,
V_446 | V_424 |
V_4 -> V_432 ) ;
F_94 ( V_4 -> V_405 [ 0 ] . V_403 , 0 , 0 ) ;
F_36 ( V_2 -> V_29 ) ;
return V_262 ;
}
static void F_101 ( struct V_416 * V_417 )
{
struct V_3 * V_4 = F_93 ( V_417 ,
struct V_3 ,
V_117 . V_417 ) ;
F_100 ( 0 , V_4 ) ;
}
int F_102 ( struct V_1 * V_2 , struct V_402 * V_403 ,
T_4 V_447 , void * V_448 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_154 = V_4 -> V_4 ;
T_1 V_449 ;
switch ( V_154 -> type ) {
case V_278 :
case V_161 :
break;
default:
return - V_43 ;
}
if ( V_403 ) {
if ( ! V_447 ) {
F_5 ( V_2 -> V_29 , L_75 ) ;
V_447 = V_16 ;
V_448 = V_2 ;
}
F_71 ( & V_2 -> V_49 , L_76 ) ;
F_9 ( & V_2 -> V_49 ) ;
V_4 -> V_405 [ 0 ] . V_403 = V_403 ;
V_4 -> V_15 = V_447 ;
V_4 -> V_450 = V_448 ;
V_4 -> V_109 = true ;
V_4 -> V_17 = false ;
F_1 ( V_2 ) ;
if ( V_4 -> V_13 -> V_449 )
V_449 = V_4 -> V_13 -> V_449 ;
else
V_449 = 0x41 ;
V_4 -> V_432 = V_427 | V_435 |
V_436 | V_437 |
V_438 | V_439 ;
F_6 ( V_2 , V_451 ,
V_452 , V_449 ) ;
F_33 ( V_2 -> V_49 . V_283 > V_284 ) ;
if ( V_4 -> V_22 ) {
F_6 ( V_2 , V_441 ,
V_445 , 0 ) ;
F_6 ( V_2 , V_281 ,
V_444 ,
V_444 ) ;
F_6 ( V_2 , V_453 ,
V_454 , 0 ) ;
F_22 ( V_2 ,
V_111 ) ;
} else {
F_6 ( V_2 , V_30 ,
V_433 , V_433 ) ;
}
} else {
F_6 ( V_2 , V_30 ,
V_433 , 0 ) ;
F_22 ( V_2 , V_105 ) ;
F_70 ( & V_2 -> V_49 , L_76 ) ;
F_9 ( & V_2 -> V_49 ) ;
}
return 0 ;
}
static T_3 F_103 ( int V_259 , void * V_260 )
{
struct V_3 * V_4 = V_260 ;
struct V_1 * V_2 = V_4 -> V_135 . V_2 ;
int V_53 , V_455 ;
if ( ! ( F_3 ( V_2 , V_30 ) & V_433 ) )
return V_262 ;
F_31 ( V_2 -> V_29 ) ;
V_455 = 10 ;
do {
V_53 = F_3 ( V_2 , V_456 ) ;
if ( V_53 < 0 ) {
F_59 ( V_2 -> V_29 ,
L_77 ,
V_53 ) ;
F_36 ( V_2 -> V_29 ) ;
return V_442 ;
}
if ( ! ( V_53 & V_457 ) ) {
F_5 ( V_2 -> V_29 , L_78 ) ;
goto V_41;
}
if ( ! ( V_53 & V_431 ) || ( V_53 & V_458 ) )
break;
F_34 ( 1 ) ;
} while ( V_455 -- );
if ( V_455 == 0 )
F_62 ( V_2 -> V_29 , L_79 ) ;
#ifndef F_96
F_97 ( F_98 ( V_2 -> V_29 ) ) ;
#endif
if ( V_4 -> V_15 )
V_4 -> V_15 ( V_53 , V_4 -> V_450 ) ;
else
F_62 ( V_2 -> V_29 , L_80 ) ;
V_41:
F_36 ( V_2 -> V_29 ) ;
return V_262 ;
}
static T_3 F_104 ( int V_259 , void * V_260 )
{
struct V_1 * V_2 = V_260 ;
F_59 ( V_2 -> V_29 , L_81 ) ;
return V_262 ;
}
static T_3 F_105 ( int V_259 , void * V_260 )
{
struct V_1 * V_2 = V_260 ;
F_59 ( V_2 -> V_29 , L_82 ) ;
return V_262 ;
}
static T_3 F_106 ( int V_259 , void * V_260 )
{
struct V_1 * V_2 = V_260 ;
F_107 ( V_2 -> V_29 , L_83 ) ;
return V_262 ;
}
static int F_108 ( struct V_1 * V_2 )
{
struct V_4 * V_154 = F_109 ( V_2 -> V_29 -> V_459 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_460 * V_49 = & V_2 -> V_49 ;
unsigned int V_53 ;
int V_64 , V_6 ;
V_4 -> V_135 . V_2 = V_2 ;
V_2 -> V_155 = V_154 -> V_372 ;
F_110 ( V_2 , 16 , 16 , V_461 ) ;
F_111 ( & V_4 -> V_108 ) ;
F_112 ( & V_4 -> V_419 , F_92 ) ;
F_112 ( & V_4 -> V_117 ,
F_101 ) ;
for ( V_6 = 0 ; V_6 < F_4 ( V_4 -> V_254 ) ; V_6 ++ )
F_113 ( & V_4 -> V_254 [ V_6 ] ) ;
if ( V_4 -> V_13 && V_4 -> V_13 -> V_462 )
V_4 -> V_462 = V_4 -> V_13 -> V_462 ;
F_114 ( V_2 -> V_29 ) ;
F_115 ( V_2 -> V_29 ) ;
V_2 -> V_49 . V_463 = 1 ;
V_4 -> V_255 = F_3 ( V_2 , V_464 ) ;
switch ( V_154 -> type ) {
case V_160 :
if ( ! V_4 -> V_13 -> V_386 ||
! V_4 -> V_13 -> V_387 )
V_2 -> V_49 . V_463 = 0 ;
switch ( V_4 -> V_255 ) {
case 2 :
case 3 :
V_4 -> V_135 . V_465 = - 5 ;
V_4 -> V_135 . V_466 = - 5 ;
V_4 -> V_135 . V_467 = 1 ;
V_4 -> V_135 . V_468 = 1 ;
V_4 -> V_135 . V_469 = 1 ;
break;
default:
V_4 -> V_135 . V_468 = 2 ;
break;
}
break;
case V_161 :
V_4 -> V_135 . V_468 = 1 ;
V_4 -> V_135 . V_467 = 1 ;
switch ( V_4 -> V_255 ) {
case 0 :
break;
default:
V_4 -> V_236 = true ;
break;
}
break;
case V_278 :
V_4 -> V_135 . V_468 = 2 ;
V_4 -> V_135 . V_470 = 1 ;
V_4 -> V_135 . V_467 = 1 ;
V_4 -> V_135 . V_471 = true ;
V_4 -> V_236 = true ;
switch ( V_154 -> V_472 ) {
case 0 :
case 2 :
V_4 -> V_135 . V_465 = - 9 ;
V_4 -> V_135 . V_466 = - 7 ;
break;
case 1 :
case 3 :
V_4 -> V_135 . V_465 = - 8 ;
V_4 -> V_135 . V_466 = - 7 ;
break;
default:
break;
}
F_6 ( V_2 , V_473 ,
V_474 , V_474 ) ;
break;
default:
break;
}
F_116 ( V_4 -> V_4 , V_475 ,
F_104 , L_84 , V_2 ) ;
F_116 ( V_4 -> V_4 , V_476 ,
F_105 , L_85 , V_2 ) ;
F_116 ( V_4 -> V_4 , V_477 ,
F_106 , L_86 , V_2 ) ;
V_64 = F_116 ( V_4 -> V_4 , V_478 ,
V_479 , L_87 ,
& V_4 -> V_135 ) ;
if ( V_64 == 0 )
V_4 -> V_135 . V_480 = true ;
switch ( V_154 -> type ) {
case V_160 :
if ( V_4 -> V_462 ) {
V_64 = F_117 ( V_4 -> V_462 , NULL ,
F_95 ,
V_481 ,
L_88 ,
V_4 ) ;
if ( V_64 != 0 )
F_62 ( V_2 -> V_29 ,
L_89 ,
V_64 ) ;
}
V_64 = F_116 ( V_4 -> V_4 ,
V_482 ,
F_95 , L_90 ,
V_4 ) ;
if ( V_64 != 0 )
F_62 ( V_2 -> V_29 ,
L_91 ,
V_64 ) ;
V_64 = F_116 ( V_4 -> V_4 ,
V_483 ,
F_95 , L_92 ,
V_4 ) ;
if ( V_64 != 0 )
F_62 ( V_2 -> V_29 ,
L_93 ,
V_64 ) ;
V_64 = F_116 ( V_4 -> V_4 ,
V_484 ,
F_95 , L_94 ,
V_4 ) ;
if ( V_64 != 0 )
F_62 ( V_2 -> V_29 ,
L_95 ,
V_64 ) ;
break;
case V_161 :
case V_278 :
if ( V_4 -> V_462 ) {
V_64 = F_117 ( V_4 -> V_462 , NULL ,
F_103 ,
V_481 ,
L_96 ,
V_4 ) ;
if ( V_64 != 0 )
F_62 ( V_2 -> V_29 ,
L_97 ,
V_64 ) ;
} else {
F_116 ( V_4 -> V_4 , V_485 ,
F_103 , L_96 ,
V_4 ) ;
}
}
switch ( V_154 -> type ) {
case V_278 :
if ( V_154 -> V_472 > 1 || V_4 -> V_255 > 1 ) {
V_64 = F_116 ( V_4 -> V_4 ,
F_118 ( 6 ) ,
F_100 , L_98 ,
V_4 ) ;
if ( V_64 == 0 )
V_4 -> V_22 = true ;
}
break;
default:
break;
}
V_4 -> V_258 = true ;
for ( V_6 = 0 ; V_6 < F_4 ( V_4 -> V_254 ) ; V_6 ++ ) {
V_64 = F_116 ( V_4 -> V_4 ,
V_486 + V_6 ,
F_63 , L_99 ,
& V_4 -> V_254 [ V_6 ] ) ;
if ( V_64 != 0 )
V_4 -> V_258 = false ;
}
F_31 ( V_2 -> V_29 ) ;
V_64 = F_83 ( V_154 -> V_372 , V_487 , & V_53 ) ;
if ( V_64 < 0 ) {
F_59 ( V_2 -> V_29 , L_100 , V_64 ) ;
goto V_488;
}
if ( ( V_53 & V_489 ) != V_490 ) {
V_4 -> V_334 [ 0 ] = 1 ;
V_491 [ 0 ] . V_492 = 1 ;
} else {
V_4 -> V_334 [ 0 ] = 0 ;
}
V_64 = F_83 ( V_154 -> V_372 , V_493 , & V_53 ) ;
if ( V_64 < 0 ) {
F_59 ( V_2 -> V_29 , L_101 , V_64 ) ;
goto V_488;
}
if ( ( V_53 & V_489 ) != V_490 ) {
V_4 -> V_334 [ 1 ] = 1 ;
V_491 [ 1 ] . V_492 = 1 ;
} else {
V_4 -> V_334 [ 1 ] = 0 ;
}
F_36 ( V_2 -> V_29 ) ;
for ( V_6 = 0 ; V_6 < F_4 ( V_179 ) ; V_6 ++ )
F_6 ( V_2 , V_179 [ V_6 ] . V_53 ,
V_179 [ V_6 ] . V_63 ,
V_179 [ V_6 ] . V_63 ) ;
F_6 ( V_2 , V_494 ,
1 << V_495 ,
1 << V_495 ) ;
F_6 ( V_2 , V_496 ,
1 << V_497 ,
1 << V_497 ) ;
F_6 ( V_2 , V_498 ,
1 << V_499 ,
1 << V_499 ) ;
switch ( V_154 -> type ) {
case V_160 :
case V_161 :
F_6 ( V_2 , V_165 ,
V_500 , V_500 ) ;
break;
default:
break;
}
switch ( V_154 -> type ) {
case V_161 :
case V_278 :
F_6 ( V_2 , V_279 ,
V_280 , V_280 ) ;
F_6 ( V_2 , V_281 ,
V_282 , V_282 ) ;
break;
default:
break;
}
V_4 -> V_135 . V_501 = F_38 ;
F_54 ( V_2 ) ;
F_88 ( V_4 ) ;
F_119 ( V_2 ) ;
F_87 ( V_2 , V_502 ,
F_4 ( V_502 ) ) ;
F_120 ( V_49 , V_503 ,
F_4 ( V_503 ) ) ;
switch ( V_154 -> type ) {
case V_160 :
F_120 ( V_49 , V_504 ,
F_4 ( V_504 ) ) ;
if ( V_4 -> V_255 < 4 ) {
F_120 ( V_49 , V_505 ,
F_4 ( V_505 ) ) ;
F_120 ( V_49 , V_506 ,
F_4 ( V_506 ) ) ;
F_120 ( V_49 , V_507 ,
F_4 ( V_507 ) ) ;
} else {
F_120 ( V_49 , V_508 ,
F_4 ( V_508 ) ) ;
F_120 ( V_49 , V_509 ,
F_4 ( V_509 ) ) ;
F_120 ( V_49 , V_510 ,
F_4 ( V_510 ) ) ;
}
break;
case V_161 :
F_87 ( V_2 , V_511 ,
F_4 ( V_511 ) ) ;
F_120 ( V_49 , V_512 ,
F_4 ( V_512 ) ) ;
if ( V_4 -> V_255 < 1 ) {
F_120 ( V_49 , V_505 ,
F_4 ( V_505 ) ) ;
F_120 ( V_49 , V_506 ,
F_4 ( V_506 ) ) ;
F_120 ( V_49 , V_507 ,
F_4 ( V_507 ) ) ;
} else {
F_120 ( V_49 , V_508 ,
F_4 ( V_508 ) ) ;
F_120 ( V_49 , V_509 ,
F_4 ( V_509 ) ) ;
F_120 ( V_49 , V_510 ,
F_4 ( V_510 ) ) ;
}
break;
case V_278 :
F_87 ( V_2 , V_511 ,
F_4 ( V_511 ) ) ;
F_120 ( V_49 , V_512 ,
F_4 ( V_512 ) ) ;
F_120 ( V_49 , V_508 ,
F_4 ( V_508 ) ) ;
F_120 ( V_49 , V_509 ,
F_4 ( V_509 ) ) ;
F_120 ( V_49 , V_510 ,
F_4 ( V_510 ) ) ;
break;
}
F_121 ( V_2 , 0 , 0 ) ;
F_122 ( V_49 , V_513 , F_4 ( V_513 ) ) ;
switch ( V_154 -> type ) {
case V_160 :
F_122 ( V_49 , V_514 ,
F_4 ( V_514 ) ) ;
if ( V_4 -> V_255 < 4 ) {
F_122 ( V_49 , V_515 ,
F_4 ( V_515 ) ) ;
F_122 ( V_49 , V_516 ,
F_4 ( V_516 ) ) ;
} else {
F_122 ( V_49 , V_517 ,
F_4 ( V_517 ) ) ;
}
break;
case V_161 :
if ( V_4 -> V_255 < 1 ) {
F_122 ( V_49 , V_514 ,
F_4 ( V_514 ) ) ;
F_122 ( V_49 , V_515 ,
F_4 ( V_515 ) ) ;
F_122 ( V_49 , V_516 ,
F_4 ( V_516 ) ) ;
} else {
F_122 ( V_49 , V_517 ,
F_4 ( V_517 ) ) ;
F_122 ( V_49 , V_518 ,
F_4 ( V_518 ) ) ;
}
F_123 ( V_2 ) ;
break;
case V_278 :
F_122 ( V_49 , V_517 ,
F_4 ( V_517 ) ) ;
F_122 ( V_49 , V_518 ,
F_4 ( V_518 ) ) ;
break;
}
return 0 ;
V_488:
if ( V_4 -> V_22 )
F_124 ( V_4 -> V_4 , F_118 ( 6 ) , V_4 ) ;
F_124 ( V_4 -> V_4 , V_484 , V_4 ) ;
F_124 ( V_4 -> V_4 , V_483 , V_4 ) ;
F_124 ( V_4 -> V_4 , V_482 , V_4 ) ;
if ( V_4 -> V_462 )
F_125 ( V_4 -> V_462 , V_4 ) ;
for ( V_6 = 0 ; V_6 < F_4 ( V_4 -> V_254 ) ; V_6 ++ )
F_124 ( V_4 -> V_4 , V_486 + V_6 ,
& V_4 -> V_254 [ V_6 ] ) ;
F_124 ( V_4 -> V_4 , V_478 ,
& V_4 -> V_135 ) ;
F_124 ( V_4 -> V_4 , V_475 , V_2 ) ;
F_124 ( V_4 -> V_4 , V_477 , V_2 ) ;
F_124 ( V_4 -> V_4 , V_476 , V_2 ) ;
return V_64 ;
}
static int F_126 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_154 = V_4 -> V_4 ;
int V_6 ;
F_67 ( V_2 , V_285 ) ;
F_127 ( V_2 -> V_29 ) ;
for ( V_6 = 0 ; V_6 < F_4 ( V_4 -> V_254 ) ; V_6 ++ )
F_124 ( V_4 -> V_4 , V_486 + V_6 ,
& V_4 -> V_254 [ V_6 ] ) ;
F_124 ( V_4 -> V_4 , V_478 ,
& V_4 -> V_135 ) ;
F_124 ( V_4 -> V_4 , V_475 , V_2 ) ;
F_124 ( V_4 -> V_4 , V_477 , V_2 ) ;
F_124 ( V_4 -> V_4 , V_476 , V_2 ) ;
if ( V_4 -> V_22 )
F_124 ( V_4 -> V_4 , F_118 ( 6 ) , V_4 ) ;
switch ( V_154 -> type ) {
case V_160 :
if ( V_4 -> V_462 )
F_125 ( V_4 -> V_462 , V_4 ) ;
F_124 ( V_4 -> V_4 , V_483 ,
V_4 ) ;
F_124 ( V_4 -> V_4 , V_482 ,
V_4 ) ;
F_124 ( V_4 -> V_4 , V_485 ,
V_4 ) ;
break;
case V_278 :
case V_161 :
if ( V_4 -> V_462 )
F_125 ( V_4 -> V_462 , V_4 ) ;
break;
}
F_128 ( V_4 -> V_519 ) ;
F_128 ( V_4 -> V_520 ) ;
F_128 ( V_4 -> V_521 ) ;
F_129 ( V_4 -> V_97 ) ;
return 0 ;
}
static int T_5 F_130 ( struct V_522 * V_523 )
{
struct V_3 * V_4 ;
V_4 = F_90 ( & V_523 -> V_29 , sizeof( struct V_3 ) ,
V_383 ) ;
if ( V_4 == NULL )
return - V_524 ;
F_131 ( V_523 , V_4 ) ;
V_4 -> V_4 = F_109 ( V_523 -> V_29 . V_459 ) ;
V_4 -> V_13 = F_132 ( V_523 -> V_29 . V_459 ) ;
return F_133 ( & V_523 -> V_29 , & V_525 ,
V_491 , F_4 ( V_491 ) ) ;
}
static int T_6 F_134 ( struct V_522 * V_523 )
{
F_135 ( & V_523 -> V_29 ) ;
return 0 ;
}
static int F_136 ( struct V_420 * V_29 )
{
struct V_3 * V_4 = F_109 ( V_29 ) ;
if ( V_4 -> V_22 && ! V_4 -> V_102 )
F_137 ( V_4 -> V_4 -> V_372 , V_106 ,
V_107 ,
V_4 -> V_104 ) ;
return 0 ;
}
static int F_138 ( struct V_420 * V_29 )
{
struct V_3 * V_4 = F_109 ( V_29 ) ;
if ( V_4 -> V_22 && V_4 -> V_15 )
F_137 ( V_4 -> V_4 -> V_372 , V_106 ,
V_107 ,
V_103 ) ;
return 0 ;
}
