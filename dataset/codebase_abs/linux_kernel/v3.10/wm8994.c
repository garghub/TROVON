static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_6 , V_7 , V_8 , V_9 ;
bool V_10 ;
const struct V_11 * V_12 ;
int V_13 ;
V_10 = ! V_4 -> V_14 ;
V_8 = F_3 ( V_2 , V_15 ) ;
if ( V_8 & V_16 )
V_8 = V_4 -> V_17 [ 1 ] ;
else
V_8 = V_4 -> V_17 [ 0 ] ;
if ( V_5 -> V_18 . V_19 ) {
V_12 = V_5 -> V_18 . V_19 ;
V_13 = V_5 -> V_18 . V_20 ;
} else if ( V_4 -> V_21 ) {
V_12 = V_22 ;
V_13 = F_4 ( V_22 ) ;
} else {
V_12 = V_23 ;
V_13 = F_4 ( V_23 ) ;
}
V_6 = 0 ;
for ( V_7 = 0 ; V_7 < V_13 ; V_7 ++ ) {
if ( V_12 [ V_7 ] . V_10 != V_10 )
continue;
if ( abs ( V_12 [ V_7 ] . V_8 - V_8 ) <
abs ( V_12 [ V_6 ] . V_8 - V_8 ) )
V_6 = V_7 ;
else if ( V_12 [ V_6 ] . V_10 != V_10 )
V_6 = V_7 ;
}
V_9 = V_12 [ V_6 ] . V_24 << V_25
| V_12 [ V_6 ] . V_26 << V_27 ;
F_5 ( V_2 -> V_28 , L_1 ,
V_12 [ V_6 ] . V_24 , V_12 [ V_6 ] . V_26 , V_8 ,
V_10 ? L_2 : L_3 ) ;
F_6 ( V_2 , V_29 ,
V_30 |
V_31 , V_9 ) ;
}
static int F_7 ( struct V_1 * V_2 , int V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_26 ;
int V_33 = 0 ;
int V_34 ;
if ( V_32 )
V_34 = 4 ;
else
V_34 = 0 ;
switch ( V_4 -> V_8 [ V_32 ] ) {
case V_35 :
V_26 = V_4 -> V_36 [ 0 ] ;
break;
case V_37 :
V_33 |= 0x8 ;
V_26 = V_4 -> V_36 [ 1 ] ;
break;
case V_38 :
V_33 |= 0x10 ;
V_26 = V_4 -> V_39 [ 0 ] . V_40 ;
break;
case V_41 :
V_33 |= 0x18 ;
V_26 = V_4 -> V_39 [ 1 ] . V_40 ;
break;
default:
return - V_42 ;
}
if ( V_26 >= 13500000 ) {
V_26 /= 2 ;
V_33 |= V_43 ;
F_5 ( V_2 -> V_28 , L_4 ,
V_32 + 1 , V_26 ) ;
}
V_4 -> V_17 [ V_32 ] = V_26 ;
F_6 ( V_2 , V_44 + V_34 ,
V_45 | V_43 ,
V_33 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_46 , V_47 ;
F_7 ( V_2 , 0 ) ;
F_7 ( V_2 , 1 ) ;
if ( V_4 -> V_17 [ 0 ] == V_4 -> V_17 [ 1 ] ) {
F_1 ( V_2 ) ;
return 0 ;
}
if ( V_4 -> V_17 [ 0 ] < V_4 -> V_17 [ 1 ] )
V_47 = V_16 ;
else
V_47 = 0 ;
V_46 = F_6 ( V_2 , V_15 ,
V_16 , V_47 ) ;
if ( V_46 )
F_9 ( & V_2 -> V_48 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_10 ( struct V_49 * V_50 ,
struct V_49 * V_51 )
{
int V_52 = F_3 ( V_50 -> V_2 , V_15 ) ;
const char * V_53 ;
if ( V_52 & V_16 )
V_53 = L_5 ;
else
V_53 = L_6 ;
return strcmp ( V_50 -> V_54 , V_53 ) == 0 ;
}
static int F_11 ( struct V_55 * V_56 ,
struct V_57 * V_58 )
{
struct V_59 * V_60 =
(struct V_59 * ) V_56 -> V_61 ;
struct V_1 * V_2 = F_12 ( V_56 ) ;
int V_62 , V_63 ;
if ( V_60 -> V_64 == V_65 )
V_62 = V_66 |
V_67 ;
else
V_62 = V_68 ;
V_63 = F_3 ( V_2 , V_60 -> V_52 ) ;
if ( V_63 < 0 )
return V_63 ;
if ( V_63 & V_62 )
return - V_42 ;
return F_13 ( V_56 , V_58 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_69 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_70 * V_18 = & V_5 -> V_18 ;
int V_71 = V_72 [ V_69 ] ;
int V_73 = V_4 -> V_74 [ V_69 ] ;
int V_75 , V_7 ;
V_75 = F_3 ( V_2 , V_71 ) ;
V_75 &= V_76 | V_77 |
V_78 ;
for ( V_7 = 0 ; V_7 < V_79 ; V_7 ++ )
F_6 ( V_2 , V_71 + V_7 , 0xffff ,
V_18 -> V_80 [ V_73 ] . V_81 [ V_7 ] ) ;
F_6 ( V_2 , V_71 , V_76 |
V_77 |
V_78 , V_75 ) ;
}
static int F_15 ( const char * V_54 )
{
if ( strcmp ( V_54 , L_7 ) == 0 )
return 0 ;
if ( strcmp ( V_54 , L_8 ) == 0 )
return 1 ;
if ( strcmp ( V_54 , L_9 ) == 0 )
return 2 ;
return - V_42 ;
}
static int F_16 ( struct V_55 * V_56 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = F_12 ( V_56 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_70 * V_18 = & V_5 -> V_18 ;
int V_69 = F_15 ( V_56 -> V_82 . V_54 ) ;
int V_83 = V_58 -> V_83 . integer . V_83 [ 0 ] ;
if ( V_69 < 0 )
return V_69 ;
if ( V_83 >= V_18 -> V_84 )
return - V_42 ;
V_4 -> V_74 [ V_69 ] = V_83 ;
F_14 ( V_2 , V_69 ) ;
return 0 ;
}
static int F_17 ( struct V_55 * V_56 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = F_12 ( V_56 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_69 = F_15 ( V_56 -> V_82 . V_54 ) ;
if ( V_69 < 0 )
return V_69 ;
V_58 -> V_83 . V_85 . V_86 [ 0 ] = V_4 -> V_74 [ V_69 ] ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , int V_87 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_70 * V_18 = & V_5 -> V_18 ;
int V_71 = V_88 [ V_87 ] ;
int V_89 , V_6 , V_90 , V_75 , V_7 , V_73 ;
if ( ! V_18 || ! V_4 -> V_91 )
return;
switch ( V_87 ) {
case 0 :
case 1 :
V_89 = 0 ;
break;
case 2 :
V_89 = 1 ;
break;
default:
return;
}
V_73 = V_4 -> V_92 [ V_87 ] ;
V_6 = 0 ;
V_90 = V_93 ;
for ( V_7 = 0 ; V_7 < V_18 -> V_94 ; V_7 ++ ) {
if ( strcmp ( V_18 -> V_95 [ V_7 ] . V_54 ,
V_4 -> V_96 [ V_73 ] ) == 0 &&
abs ( V_18 -> V_95 [ V_7 ] . V_26
- V_4 -> V_97 [ V_89 ] ) < V_90 ) {
V_6 = V_7 ;
V_90 = abs ( V_18 -> V_95 [ V_7 ] . V_26
- V_4 -> V_97 [ V_89 ] ) ;
}
}
F_5 ( V_2 -> V_28 , L_10 ,
V_87 ,
V_18 -> V_95 [ V_6 ] . V_54 ,
V_18 -> V_95 [ V_6 ] . V_26 ,
V_4 -> V_97 [ V_89 ] ) ;
V_75 = F_3 ( V_2 , V_71 ) ;
V_75 &= V_98 ;
for ( V_7 = 0 ; V_7 < V_99 ; V_7 ++ )
F_6 ( V_2 , V_71 + V_7 , 0xffff ,
V_18 -> V_95 [ V_6 ] . V_81 [ V_7 ] ) ;
F_6 ( V_2 , V_71 , V_98 , V_75 ) ;
}
static int F_19 ( const char * V_54 )
{
if ( strcmp ( V_54 , L_11 ) == 0 )
return 0 ;
if ( strcmp ( V_54 , L_12 ) == 0 )
return 1 ;
if ( strcmp ( V_54 , L_13 ) == 0 )
return 2 ;
return - V_42 ;
}
static int F_20 ( struct V_55 * V_56 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = F_12 ( V_56 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_70 * V_18 = & V_5 -> V_18 ;
int V_87 = F_19 ( V_56 -> V_82 . V_54 ) ;
int V_83 = V_58 -> V_83 . integer . V_83 [ 0 ] ;
if ( V_87 < 0 )
return V_87 ;
if ( V_83 >= V_18 -> V_94 )
return - V_42 ;
V_4 -> V_92 [ V_87 ] = V_83 ;
F_18 ( V_2 , V_87 ) ;
return 0 ;
}
static int F_21 ( struct V_55 * V_56 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = F_12 ( V_56 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_87 = F_19 ( V_56 -> V_82 . V_54 ) ;
if ( V_87 < 0 )
return V_87 ;
V_58 -> V_83 . V_85 . V_86 [ 0 ] = V_4 -> V_92 [ V_87 ] ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 , T_1 V_100 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_21 || ! V_4 -> V_101 [ 0 ] . V_102 )
return;
if ( V_4 -> V_103 )
V_100 = V_104 ;
if ( V_100 == V_4 -> V_105 )
return;
V_4 -> V_105 = V_100 ;
if ( V_100 != V_106 )
V_100 = V_104 ;
F_6 ( V_2 , V_107 ,
V_108 , V_100 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_24 ( & V_4 -> V_109 ) ;
V_4 -> V_103 ++ ;
F_5 ( V_2 -> V_28 , L_14 ,
V_4 -> V_103 ) ;
F_22 ( V_2 , V_104 ) ;
F_25 ( & V_4 -> V_109 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_100 ;
F_24 ( & V_4 -> V_109 ) ;
V_4 -> V_103 -- ;
F_5 ( V_2 -> V_28 , L_15 ,
V_4 -> V_103 ) ;
if ( V_4 -> V_103 == 0 ) {
if ( V_4 -> V_14 || V_4 -> V_110 )
V_100 = V_111 ;
else
V_100 = V_112 ;
F_22 ( V_2 , V_100 ) ;
}
F_25 ( & V_4 -> V_109 ) ;
}
static int F_27 ( struct V_49 * V_113 ,
struct V_55 * V_56 , int V_114 )
{
struct V_1 * V_2 = V_113 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_114 ) {
case V_115 :
return F_8 ( V_2 ) ;
case V_116 :
if ( V_4 -> V_21 && ! V_4 -> V_117 ) {
F_28 ( & V_4 -> V_118 ,
F_29 ( 1000 ) ) ;
V_4 -> V_117 = true ;
}
break;
case V_119 :
F_8 ( V_2 ) ;
break;
}
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_31 ( V_2 -> V_28 ) ;
V_4 -> V_120 ++ ;
F_5 ( V_2 -> V_28 , L_16 ,
V_4 -> V_120 ) ;
if ( V_4 -> V_120 == 1 ) {
F_6 ( V_2 , V_121 ,
V_122 |
V_123 , 0 ) ;
F_32 ( V_2 ) ;
switch ( V_4 -> V_124 ) {
default:
F_33 ( NULL == L_17 ) ;
case V_125 :
F_6 ( V_2 , V_107 ,
V_126 |
V_127 |
V_128 |
V_129 |
V_130 ,
V_126 |
V_128 |
V_129 |
( 0x2 << V_131 ) ) ;
F_6 ( V_2 , V_132 ,
V_133 |
V_134 ,
V_133 | 0x2 ) ;
F_34 ( 300 ) ;
F_6 ( V_2 , V_107 ,
V_130 |
V_126 ,
0 ) ;
break;
case V_135 :
F_6 ( V_2 , V_107 ,
V_126 |
V_127 |
V_128 |
V_129 |
V_130 ,
V_126 |
V_128 |
V_129 |
( 0x2 << V_131 ) ) ;
F_6 ( V_2 , V_132 ,
V_133 |
V_134 ,
V_133 | 0x2 ) ;
F_34 ( 400 ) ;
F_6 ( V_2 , V_107 ,
V_130 |
V_126 ,
0 ) ;
break;
}
}
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_120 -- ;
F_5 ( V_2 -> V_28 , L_18 ,
V_4 -> V_120 ) ;
if ( V_4 -> V_120 == 0 ) {
if ( V_4 -> V_136 . V_137 )
F_6 ( V_2 , V_138 ,
V_139 |
V_140 ,
V_139 |
V_140 ) ;
if ( V_4 -> V_136 . V_141 )
F_6 ( V_2 , V_138 ,
V_142 |
V_143 ,
V_142 |
V_143 ) ;
F_6 ( V_2 , V_107 ,
V_126 |
V_127 ,
V_126 |
V_127 ) ;
F_6 ( V_2 , V_132 ,
V_134 , 0 ) ;
F_34 ( 400 ) ;
F_6 ( V_2 , V_121 ,
V_122 |
V_123 ,
V_122 |
V_123 ) ;
F_6 ( V_2 , V_138 ,
V_139 |
V_140 |
V_142 |
V_143 , 0 ) ;
F_6 ( V_2 , V_107 ,
V_126 |
V_128 |
V_129 |
V_130 , 0 ) ;
F_6 ( V_2 , V_132 ,
V_134 , 0 ) ;
}
F_36 ( V_2 -> V_28 ) ;
}
static int F_37 ( struct V_49 * V_113 ,
struct V_55 * V_56 , int V_114 )
{
struct V_1 * V_2 = V_113 -> V_2 ;
switch ( V_114 ) {
case V_115 :
F_30 ( V_2 ) ;
break;
case V_119 :
F_35 ( V_2 ) ;
break;
}
return 0 ;
}
static bool F_38 ( struct V_1 * V_2 )
{
int V_50 = 0 ;
int V_52 , V_144 ;
V_52 = F_3 ( V_2 , V_145 ) ;
switch ( V_52 ) {
case V_146 :
F_39 ( V_2 -> V_28 , L_19 ) ;
V_50 = 2 << V_147 ;
break;
case V_148 :
F_39 ( V_2 -> V_28 , L_20 ) ;
V_50 = 1 << V_147 ;
break;
case V_149 :
F_39 ( V_2 -> V_28 , L_21 ) ;
V_50 = 0 << V_147 ;
break;
default:
F_39 ( V_2 -> V_28 , L_22 , V_52 ) ;
return false ;
}
V_144 = F_3 ( V_2 , V_150 ) ;
if ( V_144 != V_52 ) {
F_39 ( V_2 -> V_28 , L_23 ) ;
return false ;
}
F_6 ( V_2 , V_151 ,
V_152 , V_50 ) ;
return true ;
}
static int F_40 ( struct V_49 * V_113 ,
struct V_55 * V_56 , int V_114 )
{
struct V_1 * V_2 = V_113 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_62 = V_153 | V_154 ;
int V_7 ;
int V_155 ;
int V_156 ;
int V_9 ;
switch ( V_5 -> type ) {
case V_157 :
case V_158 :
V_62 |= V_159 | V_160 ;
break;
default:
break;
}
switch ( V_114 ) {
case V_115 :
if ( V_4 -> V_161 [ 0 ] <= 2 )
V_62 &= ~ ( V_159 | V_160 ) ;
V_9 = F_3 ( V_2 , V_162 ) ;
if ( ( V_9 & V_163 ) &&
( V_9 & V_164 ) )
V_156 = V_165 | V_166 ;
else if ( ! ( V_9 & V_163 ) &&
! ( V_9 & V_164 ) )
V_156 = V_167 | V_168 ;
else
V_156 = V_165 | V_166 |
V_167 | V_168 ;
V_9 = F_3 ( V_2 , V_169 ) ;
if ( ( V_9 & V_170 ) &&
( V_9 & V_171 ) )
V_155 = V_154 | V_160 ;
else if ( ! ( V_9 & V_170 ) &&
! ( V_9 & V_171 ) )
V_155 = V_153 | V_159 ;
else
V_155 = V_154 | V_160 |
V_153 | V_159 ;
F_6 ( V_2 , V_172 ,
V_62 , V_156 ) ;
F_6 ( V_2 , V_173 ,
V_62 , V_155 ) ;
F_6 ( V_2 , V_15 ,
V_174 |
V_175 ,
V_174 |
V_175 ) ;
F_6 ( V_2 , V_172 , V_62 ,
V_165 |
V_167 |
V_166 |
V_168 ) ;
F_6 ( V_2 , V_173 , V_62 ,
V_154 |
V_153 |
V_160 |
V_159 ) ;
break;
case V_116 :
for ( V_7 = 0 ; V_7 < F_4 ( V_176 ) ; V_7 ++ )
F_41 ( V_2 , V_176 [ V_7 ] . V_52 ,
F_3 ( V_2 ,
V_176 [ V_7 ] . V_52 ) ) ;
break;
case V_177 :
case V_119 :
F_6 ( V_2 , V_173 ,
V_62 , 0 ) ;
F_6 ( V_2 , V_172 ,
V_62 , 0 ) ;
V_9 = F_3 ( V_2 , V_15 ) ;
if ( V_9 & V_178 )
V_9 = V_175 ;
else
V_9 = 0 ;
F_6 ( V_2 , V_15 ,
V_175 |
V_174 , V_9 ) ;
break;
}
return 0 ;
}
static int F_42 ( struct V_49 * V_113 ,
struct V_55 * V_56 , int V_114 )
{
struct V_1 * V_2 = V_113 -> V_2 ;
int V_7 ;
int V_155 ;
int V_156 ;
int V_9 ;
switch ( V_114 ) {
case V_115 :
V_9 = F_3 ( V_2 , V_179 ) ;
if ( ( V_9 & V_180 ) &&
( V_9 & V_181 ) )
V_156 = V_182 ;
else if ( ! ( V_9 & V_180 ) &&
! ( V_9 & V_181 ) )
V_156 = V_183 ;
else
V_156 = V_183 | V_182 ;
V_9 = F_3 ( V_2 , V_184 ) ;
if ( ( V_9 & V_185 ) &&
( V_9 & V_186 ) )
V_155 = V_187 ;
else if ( ! ( V_9 & V_185 ) &&
! ( V_9 & V_186 ) )
V_155 = V_188 ;
else
V_155 = V_188 | V_187 ;
F_6 ( V_2 , V_172 ,
V_183 |
V_182 , V_156 ) ;
F_6 ( V_2 , V_173 ,
V_188 |
V_187 , V_155 ) ;
F_6 ( V_2 , V_15 ,
V_178 |
V_175 ,
V_178 |
V_175 ) ;
F_6 ( V_2 , V_172 ,
V_183 |
V_182 ,
V_183 |
V_182 ) ;
F_6 ( V_2 , V_173 ,
V_188 |
V_187 ,
V_188 |
V_187 ) ;
break;
case V_116 :
for ( V_7 = 0 ; V_7 < F_4 ( V_176 ) ; V_7 ++ )
F_41 ( V_2 , V_176 [ V_7 ] . V_52 ,
F_3 ( V_2 ,
V_176 [ V_7 ] . V_52 ) ) ;
break;
case V_177 :
case V_119 :
F_6 ( V_2 , V_173 ,
V_188 |
V_187 , 0 ) ;
F_6 ( V_2 , V_172 ,
V_183 |
V_182 , 0 ) ;
V_9 = F_3 ( V_2 , V_15 ) ;
if ( V_9 & V_174 )
V_9 = V_175 ;
else
V_9 = 0 ;
F_6 ( V_2 , V_15 ,
V_175 |
V_178 , V_9 ) ;
break;
}
return 0 ;
}
static int F_43 ( struct V_49 * V_113 ,
struct V_55 * V_56 , int V_114 )
{
struct V_1 * V_2 = V_113 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_114 ) {
case V_115 :
V_4 -> V_189 = 1 ;
break;
case V_119 :
V_4 -> V_190 = 1 ;
break;
}
return 0 ;
}
static int F_44 ( struct V_49 * V_113 ,
struct V_55 * V_56 , int V_114 )
{
struct V_1 * V_2 = V_113 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_114 ) {
case V_115 :
V_4 -> V_191 = 1 ;
break;
case V_119 :
V_4 -> V_192 = 1 ;
break;
}
return 0 ;
}
static int F_45 ( struct V_49 * V_113 ,
struct V_55 * V_56 , int V_114 )
{
struct V_1 * V_2 = V_113 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_114 ) {
case V_115 :
if ( V_4 -> V_189 ) {
F_40 ( V_113 , V_56 , V_115 ) ;
F_6 ( V_2 , V_44 ,
V_193 ,
V_194 ) ;
F_40 ( V_113 , V_56 , V_116 ) ;
V_4 -> V_189 = 0 ;
}
if ( V_4 -> V_191 ) {
F_42 ( V_113 , V_56 , V_115 ) ;
F_6 ( V_2 , V_195 ,
V_196 ,
V_197 ) ;
F_42 ( V_113 , V_56 , V_116 ) ;
V_4 -> V_191 = 0 ;
}
break;
}
F_46 ( V_113 , V_56 , V_114 ) ;
return 0 ;
}
static int F_47 ( struct V_49 * V_113 ,
struct V_55 * V_56 , int V_114 )
{
struct V_1 * V_2 = V_113 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_114 ) {
case V_119 :
if ( V_4 -> V_190 ) {
F_40 ( V_113 , V_56 , V_177 ) ;
F_6 ( V_2 , V_44 ,
V_193 , 0 ) ;
F_40 ( V_113 , V_56 , V_119 ) ;
V_4 -> V_190 = 0 ;
}
if ( V_4 -> V_192 ) {
F_42 ( V_113 , V_56 , V_177 ) ;
F_6 ( V_2 , V_195 ,
V_196 , 0 ) ;
F_42 ( V_113 , V_56 , V_119 ) ;
V_4 -> V_192 = 0 ;
}
break;
}
return 0 ;
}
static int F_48 ( struct V_49 * V_113 ,
struct V_55 * V_56 , int V_114 )
{
F_45 ( V_113 , V_56 , V_114 ) ;
return 0 ;
}
static int F_49 ( struct V_49 * V_113 ,
struct V_55 * V_56 , int V_114 )
{
F_45 ( V_113 , V_56 , V_114 ) ;
return 0 ;
}
static int F_50 ( struct V_49 * V_113 ,
struct V_55 * V_56 , int V_114 )
{
struct V_1 * V_2 = V_113 -> V_2 ;
unsigned int V_62 = 1 << V_113 -> V_64 ;
F_6 ( V_2 , V_173 ,
V_62 , V_62 ) ;
return 0 ;
}
static int F_51 ( struct V_49 * V_113 ,
struct V_55 * V_56 , int V_114 )
{
struct V_1 * V_2 = V_113 -> V_2 ;
F_5 ( V_2 -> V_28 , L_24 ,
F_3 ( V_2 ,
V_198 ) ) ;
return 0 ;
}
static int F_52 ( struct V_55 * V_56 ,
struct V_57 * V_58 )
{
struct V_199 * V_200 = F_12 ( V_56 ) ;
struct V_49 * V_113 = V_200 -> V_201 [ 0 ] ;
struct V_1 * V_2 = V_113 -> V_2 ;
int V_63 ;
V_63 = F_53 ( V_56 , V_58 ) ;
F_54 ( V_2 ) ;
return V_63 ;
}
static int F_55 ( struct V_202 * V_39 ,
int V_203 , int V_204 )
{
T_2 V_205 ;
unsigned int V_206 , V_207 , V_208 ;
F_56 ( L_25 , V_203 , V_204 ) ;
V_39 -> V_209 = 0 ;
while ( V_203 > 13500000 ) {
V_39 -> V_209 ++ ;
V_203 /= 2 ;
if ( V_39 -> V_209 > 3 )
return - V_42 ;
}
F_56 ( L_26 , V_39 -> V_209 , V_203 ) ;
V_39 -> V_210 = 3 ;
while ( V_204 * ( V_39 -> V_210 + 1 ) < 90000000 ) {
V_39 -> V_210 ++ ;
if ( V_39 -> V_210 > 63 )
return - V_42 ;
}
V_204 *= V_39 -> V_210 + 1 ;
F_56 ( L_27 , V_39 -> V_210 , V_204 ) ;
if ( V_203 > 1000000 ) {
V_39 -> V_211 = 0 ;
} else if ( V_203 > 256000 ) {
V_39 -> V_211 = 1 ;
V_203 *= 2 ;
} else if ( V_203 > 128000 ) {
V_39 -> V_211 = 2 ;
V_203 *= 4 ;
} else if ( V_203 > 64000 ) {
V_39 -> V_211 = 3 ;
V_203 *= 8 ;
} else {
V_39 -> V_211 = 4 ;
V_203 *= 16 ;
}
F_56 ( L_28 , V_39 -> V_211 , V_203 ) ;
V_207 = V_204 / V_203 ;
V_39 -> V_212 = V_207 ;
V_208 = V_204 % V_203 ;
F_56 ( L_29 , V_208 ) ;
V_205 = V_213 * ( long long ) V_208 ;
F_57 ( V_205 , V_203 ) ;
V_206 = V_205 & 0xFFFFFFFF ;
if ( ( V_206 % 10 ) >= 5 )
V_206 += 5 ;
V_39 -> V_214 = V_206 / 10 ;
F_56 ( L_30 , V_39 -> V_212 , V_39 -> V_214 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , int V_82 , int V_215 ,
unsigned int V_203 , unsigned int V_204 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_216 , V_63 ;
struct V_202 V_39 ;
T_1 V_52 , V_217 , V_218 , V_219 ;
unsigned long V_220 ;
bool V_221 ;
switch ( V_82 ) {
case V_222 :
V_216 = 0 ;
V_82 = 0 ;
V_219 = 0x10 ;
break;
case V_223 :
V_216 = 0x20 ;
V_82 = 1 ;
V_219 = 0x18 ;
break;
default:
return - V_42 ;
}
V_52 = F_3 ( V_2 , V_224 + V_216 ) ;
V_221 = V_52 & V_225 ;
switch ( V_215 ) {
case 0 :
if ( V_204 )
return - V_42 ;
V_215 = V_4 -> V_39 [ V_82 ] . V_215 ;
break;
case V_226 :
case V_227 :
case V_228 :
case V_229 :
break;
case V_230 :
V_203 = 12000000 ;
V_204 = 12000000 ;
break;
default:
return - V_42 ;
}
if ( V_4 -> V_39 [ V_82 ] . V_215 == V_215 &&
V_4 -> V_39 [ V_82 ] . V_231 == V_203 && V_4 -> V_39 [ V_82 ] . V_40 == V_204 )
return 0 ;
if ( V_204 )
V_63 = F_55 ( & V_39 , V_203 , V_204 ) ;
else
V_63 = F_55 ( & V_39 , V_4 -> V_39 [ V_82 ] . V_231 ,
V_4 -> V_39 [ V_82 ] . V_40 ) ;
if ( V_63 < 0 )
return V_63 ;
V_217 = F_3 ( V_2 , V_15 ) ;
if ( V_217 & V_16 )
V_218 = V_195 ;
else
V_218 = V_44 ;
V_52 = F_3 ( V_2 , V_218 ) ;
if ( ( V_52 & V_194 ) &&
( V_52 & V_45 ) == V_219 ) {
F_59 ( V_2 -> V_28 , L_31 ,
V_82 + 1 ) ;
return - V_232 ;
}
F_6 ( V_2 , V_224 + V_216 ,
V_225 , 0 ) ;
if ( V_4 -> V_233 && V_215 == V_229 &&
V_203 == V_204 && V_204 ) {
F_5 ( V_2 -> V_28 , L_32 , V_82 + 1 ) ;
F_6 ( V_2 , V_234 + V_216 ,
V_235 , V_235 ) ;
goto V_40;
}
V_52 = ( V_39 . V_210 << V_236 ) |
( V_39 . V_211 << V_237 ) ;
F_6 ( V_2 , V_238 + V_216 ,
V_239 |
V_240 , V_52 ) ;
F_6 ( V_2 , V_241 + V_216 ,
V_242 , V_39 . V_214 ) ;
F_6 ( V_2 , V_243 + V_216 ,
V_244 ,
V_39 . V_212 << V_245 ) ;
F_6 ( V_2 , V_234 + V_216 ,
V_246 | V_235 |
V_247 |
V_248 ,
( ( V_215 == V_230 )
<< V_249 ) |
( V_39 . V_209 << V_250 ) |
( V_215 - 1 ) ) ;
F_60 ( & V_4 -> V_251 [ V_82 ] ) ;
if ( V_204 ) {
if ( ! V_221 ) {
F_23 ( V_2 ) ;
switch ( V_5 -> type ) {
case V_157 :
F_30 ( V_2 ) ;
break;
case V_158 :
if ( V_5 -> V_252 < 1 )
F_30 ( V_2 ) ;
break;
default:
break;
}
}
V_52 = V_225 ;
if ( V_39 . V_214 )
V_52 |= V_253 ;
if ( V_215 == V_230 )
V_52 |= V_254 ;
F_6 ( V_2 , V_224 + V_216 ,
V_225 | V_254 |
V_253 , V_52 ) ;
if ( V_4 -> V_255 ) {
V_220 = F_61 ( & V_4 -> V_251 [ V_82 ] ,
F_29 ( 10 ) ) ;
if ( V_220 == 0 )
F_62 ( V_2 -> V_28 ,
L_33 ) ;
} else {
F_34 ( 5 ) ;
}
} else {
if ( V_221 ) {
switch ( V_5 -> type ) {
case V_157 :
F_35 ( V_2 ) ;
break;
case V_158 :
if ( V_5 -> V_252 < 1 )
F_35 ( V_2 ) ;
break;
default:
break;
}
F_26 ( V_2 ) ;
}
}
V_40:
V_4 -> V_39 [ V_82 ] . V_231 = V_203 ;
V_4 -> V_39 [ V_82 ] . V_40 = V_204 ;
V_4 -> V_39 [ V_82 ] . V_215 = V_215 ;
F_8 ( V_2 ) ;
if ( F_63 ( V_4 -> V_17 [ 0 ] , V_4 -> V_17 [ 1 ] ) < 50000 ) {
F_5 ( V_2 -> V_28 , L_34 ) ;
V_4 -> V_256 [ 0 ] = F_3 ( V_2 , V_257 )
& V_258 ;
V_4 -> V_256 [ 1 ] = F_3 ( V_2 , V_259 )
& V_258 ;
F_6 ( V_2 , V_257 ,
V_258 , 0x1 ) ;
F_6 ( V_2 , V_259 ,
V_260 , 0x1 ) ;
} else if ( V_4 -> V_256 [ 0 ] ) {
F_6 ( V_2 , V_257 ,
V_258 ,
V_4 -> V_256 [ 0 ] ) ;
F_6 ( V_2 , V_259 ,
V_260 ,
V_4 -> V_256 [ 1 ] ) ;
V_4 -> V_256 [ 0 ] = 0 ;
V_4 -> V_256 [ 1 ] = 0 ;
}
return 0 ;
}
static T_3 F_64 ( int V_261 , void * V_262 )
{
struct V_263 * V_263 = V_262 ;
F_65 ( V_263 ) ;
return V_264 ;
}
static int F_66 ( struct V_265 * V_266 , int V_82 , int V_215 ,
unsigned int V_203 , unsigned int V_204 )
{
return F_58 ( V_266 -> V_2 , V_82 , V_215 , V_203 , V_204 ) ;
}
static int F_67 ( struct V_265 * V_266 ,
int V_267 , unsigned int V_268 , int V_269 )
{
struct V_1 * V_2 = V_266 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
switch ( V_266 -> V_82 ) {
case 1 :
case 2 :
break;
default:
return - V_42 ;
}
switch ( V_267 ) {
case V_35 :
V_4 -> V_8 [ V_266 -> V_82 - 1 ] = V_35 ;
V_4 -> V_36 [ 0 ] = V_268 ;
F_5 ( V_266 -> V_28 , L_35 ,
V_266 -> V_82 , V_268 ) ;
break;
case V_37 :
V_4 -> V_8 [ V_266 -> V_82 - 1 ] = V_37 ;
V_4 -> V_36 [ 1 ] = V_268 ;
F_5 ( V_266 -> V_28 , L_36 ,
V_266 -> V_82 , V_268 ) ;
break;
case V_38 :
V_4 -> V_8 [ V_266 -> V_82 - 1 ] = V_38 ;
F_5 ( V_266 -> V_28 , L_37 , V_266 -> V_82 ) ;
break;
case V_41 :
V_4 -> V_8 [ V_266 -> V_82 - 1 ] = V_41 ;
F_5 ( V_266 -> V_28 , L_38 , V_266 -> V_82 ) ;
break;
case V_270 :
if ( V_268 ) {
for ( V_7 = 0 ; V_7 < F_4 ( V_271 ) ; V_7 ++ )
if ( V_271 [ V_7 ] == V_268 )
break;
if ( V_7 == F_4 ( V_271 ) )
return - V_42 ;
F_6 ( V_2 , V_272 ,
V_273 , V_7 ) ;
F_6 ( V_2 , V_274 ,
V_275 , V_275 ) ;
} else {
F_6 ( V_2 , V_274 ,
V_275 , 0 ) ;
}
default:
return - V_42 ;
}
F_8 ( V_2 ) ;
if ( F_63 ( V_4 -> V_17 [ 0 ] , V_4 -> V_17 [ 1 ] ) < 50000 ) {
F_5 ( V_2 -> V_28 , L_34 ) ;
V_4 -> V_256 [ 0 ] = F_3 ( V_2 , V_257 )
& V_258 ;
V_4 -> V_256 [ 1 ] = F_3 ( V_2 , V_259 )
& V_258 ;
F_6 ( V_2 , V_257 ,
V_258 , 0x1 ) ;
F_6 ( V_2 , V_259 ,
V_260 , 0x1 ) ;
} else if ( V_4 -> V_256 [ 0 ] ) {
F_6 ( V_2 , V_257 ,
V_258 ,
V_4 -> V_256 [ 0 ] ) ;
F_6 ( V_2 , V_259 ,
V_260 ,
V_4 -> V_256 [ 1 ] ) ;
V_4 -> V_256 [ 0 ] = 0 ;
V_4 -> V_256 [ 1 ] = 0 ;
}
return 0 ;
}
static int F_68 ( struct V_1 * V_2 ,
enum V_276 V_277 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
F_69 ( V_2 , V_277 ) ;
switch ( V_277 ) {
case V_278 :
break;
case V_279 :
switch ( V_5 -> type ) {
case V_158 :
case V_280 :
F_6 ( V_2 , V_281 ,
V_282 , 0 ) ;
F_6 ( V_2 , V_283 ,
V_284 , 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_48 . V_285 == V_286 )
F_23 ( V_2 ) ;
break;
case V_286 :
if ( V_2 -> V_48 . V_285 == V_287 ) {
switch ( V_5 -> type ) {
case V_158 :
if ( V_5 -> V_252 == 0 ) {
F_6 ( V_2 ,
V_288 ,
V_289 ,
V_289 ) ;
}
break;
default:
break;
}
F_6 ( V_2 , V_121 ,
V_122 |
V_123 ,
V_122 |
V_123 ) ;
}
if ( V_2 -> V_48 . V_285 == V_279 )
F_26 ( V_2 ) ;
switch ( V_5 -> type ) {
case V_158 :
case V_280 :
F_6 ( V_2 , V_281 ,
V_282 ,
V_282 ) ;
F_6 ( V_2 , V_283 ,
V_284 ,
V_284 ) ;
break;
default:
break;
}
break;
case V_287 :
if ( V_2 -> V_48 . V_285 == V_286 )
V_4 -> V_290 = NULL ;
break;
}
V_2 -> V_48 . V_285 = V_277 ;
return 0 ;
}
int F_70 ( struct V_1 * V_2 , enum F_70 V_100 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_100 ) {
case V_125 :
if ( V_4 -> V_136 . V_137 ) {
F_71 ( & V_2 -> V_48 ,
L_39 ) ;
F_71 ( & V_2 -> V_48 ,
L_40 ) ;
}
if ( V_4 -> V_136 . V_141 ) {
F_71 ( & V_2 -> V_48 ,
L_41 ) ;
F_71 ( & V_2 -> V_48 ,
L_42 ) ;
}
F_9 ( & V_2 -> V_48 ) ;
V_4 -> V_124 = V_100 ;
break;
case V_135 :
if ( V_4 -> V_136 . V_137 ) {
F_72 ( & V_2 -> V_48 ,
L_39 ) ;
F_72 ( & V_2 -> V_48 ,
L_40 ) ;
}
if ( V_4 -> V_136 . V_141 ) {
F_72 ( & V_2 -> V_48 ,
L_41 ) ;
F_72 ( & V_2 -> V_48 ,
L_42 ) ;
}
V_4 -> V_124 = V_100 ;
F_9 ( & V_2 -> V_48 ) ;
break;
default:
return - V_42 ;
}
return 0 ;
}
static int F_73 ( struct V_265 * V_266 , unsigned int V_291 )
{
struct V_1 * V_2 = V_266 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_292 ;
int V_293 ;
int V_294 = 0 ;
int V_295 = 0 ;
switch ( V_266 -> V_82 ) {
case 1 :
V_292 = V_296 ;
V_293 = V_162 ;
break;
case 2 :
V_292 = V_297 ;
V_293 = V_179 ;
break;
default:
return - V_42 ;
}
switch ( V_291 & V_298 ) {
case V_299 :
break;
case V_300 :
V_294 = V_301 ;
break;
default:
return - V_42 ;
}
switch ( V_291 & V_302 ) {
case V_303 :
V_295 |= V_304 ;
case V_305 :
V_295 |= 0x18 ;
break;
case V_306 :
V_295 |= 0x10 ;
break;
case V_307 :
break;
case V_308 :
V_295 |= 0x8 ;
break;
default:
return - V_42 ;
}
switch ( V_291 & V_302 ) {
case V_305 :
case V_303 :
switch ( V_291 & V_309 ) {
case V_310 :
break;
case V_311 :
V_295 |= V_312 ;
break;
default:
return - V_42 ;
}
break;
case V_306 :
case V_307 :
case V_308 :
switch ( V_291 & V_309 ) {
case V_310 :
break;
case V_313 :
V_295 |= V_312 | V_304 ;
break;
case V_311 :
V_295 |= V_312 ;
break;
case V_314 :
V_295 |= V_304 ;
break;
default:
return - V_42 ;
}
break;
default:
return - V_42 ;
}
switch ( V_5 -> type ) {
case V_280 :
case V_158 :
if ( V_266 -> V_82 == 2 )
F_6 ( V_2 , V_315 ,
V_304 |
V_316 , V_295 ) ;
break;
default:
break;
}
F_6 ( V_2 , V_293 ,
V_312 | V_304 |
V_317 ,
V_295 ) ;
F_6 ( V_2 , V_292 , V_301 ,
V_294 ) ;
return 0 ;
}
static int F_74 ( struct V_318 * V_319 ,
struct V_320 * V_321 ,
struct V_265 * V_266 )
{
struct V_1 * V_2 = V_266 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_70 * V_18 = & V_5 -> V_18 ;
int V_293 ;
int V_322 ;
int V_323 ;
int V_324 ;
int V_325 ;
int V_295 = 0 ;
int V_326 = 0 ;
int V_327 = 0 ;
int V_328 = 0 ;
int V_329 = 0 ;
int V_82 = V_266 -> V_82 - 1 ;
int V_7 , V_330 , V_90 , V_331 , V_6 ;
switch ( V_266 -> V_82 ) {
case 1 :
V_293 = V_162 ;
V_322 = V_169 ;
V_323 = V_332 ;
V_325 = V_257 ;
if ( V_319 -> V_333 == V_334 ||
V_4 -> V_335 [ 0 ] ) {
V_324 = V_336 ;
} else {
V_324 = V_337 ;
F_5 ( V_2 -> V_28 , L_43 ) ;
}
break;
case 2 :
V_293 = V_179 ;
V_322 = V_184 ;
V_323 = V_338 ;
V_325 = V_259 ;
if ( V_319 -> V_333 == V_334 ||
V_4 -> V_335 [ 1 ] ) {
V_324 = V_339 ;
} else {
V_324 = V_340 ;
F_5 ( V_2 -> V_28 , L_44 ) ;
}
break;
default:
return - V_42 ;
}
V_331 = F_75 ( V_321 ) ;
switch ( F_76 ( V_321 ) ) {
case V_341 :
V_331 *= 16 ;
break;
case V_342 :
V_331 *= 20 ;
V_295 |= 0x20 ;
break;
case V_343 :
V_331 *= 24 ;
V_295 |= 0x40 ;
break;
case V_344 :
V_331 *= 32 ;
V_295 |= 0x60 ;
break;
default:
return - V_42 ;
}
V_4 -> V_161 [ V_82 ] = F_77 ( V_321 ) ;
if ( V_18 -> V_345 [ V_82 ] &&
V_4 -> V_161 [ V_82 ] > V_18 -> V_345 [ V_82 ] ) {
F_5 ( V_266 -> V_28 , L_45 ,
V_18 -> V_345 [ V_82 ] , V_4 -> V_161 [ V_82 ] ) ;
V_4 -> V_161 [ V_82 ] = V_18 -> V_345 [ V_82 ] ;
}
switch ( V_4 -> V_161 [ V_82 ] ) {
case 1 :
case 2 :
V_331 *= 2 ;
break;
default:
V_331 *= 4 ;
break;
}
for ( V_7 = 0 ; V_7 < F_4 ( V_346 ) ; V_7 ++ )
if ( V_346 [ V_7 ] . V_26 == F_75 ( V_321 ) )
break;
if ( V_7 == F_4 ( V_346 ) )
return - V_42 ;
V_329 |= V_346 [ V_7 ] . V_9 << V_347 ;
F_5 ( V_266 -> V_28 , L_46 , V_346 [ V_7 ] . V_26 ) ;
F_5 ( V_266 -> V_28 , L_47 ,
V_266 -> V_82 , V_4 -> V_17 [ V_82 ] , V_331 ) ;
if ( V_4 -> V_161 [ V_82 ] == 1 &&
( F_3 ( V_2 , V_293 ) & 0x18 ) == 0x18 )
V_326 |= V_348 ;
if ( V_4 -> V_17 [ V_82 ] == 0 ) {
F_59 ( V_266 -> V_28 , L_48 , V_266 -> V_82 ) ;
return - V_42 ;
}
V_6 = 0 ;
V_90 = abs ( ( V_349 [ 0 ] * F_75 ( V_321 ) )
- V_4 -> V_17 [ V_82 ] ) ;
for ( V_7 = 1 ; V_7 < F_4 ( V_349 ) ; V_7 ++ ) {
V_330 = abs ( ( V_349 [ V_7 ] * F_75 ( V_321 ) )
- V_4 -> V_17 [ V_82 ] ) ;
if ( V_330 >= V_90 )
continue;
V_6 = V_7 ;
V_90 = V_330 ;
}
F_5 ( V_266 -> V_28 , L_49 ,
V_266 -> V_82 , V_349 [ V_6 ] ) ;
V_329 |= V_6 ;
V_6 = 0 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_350 ) ; V_7 ++ ) {
V_330 = ( V_4 -> V_17 [ V_82 ] * 10 / V_350 [ V_7 ] ) - V_331 ;
if ( V_330 < 0 )
break;
V_6 = V_7 ;
}
V_331 = V_4 -> V_17 [ V_82 ] * 10 / V_350 [ V_6 ] ;
F_5 ( V_266 -> V_28 , L_50 ,
V_350 [ V_6 ] , V_331 ) ;
V_327 |= V_6 << V_351 ;
V_328 = V_331 / F_75 ( V_321 ) ;
if ( ! V_328 ) {
F_59 ( V_266 -> V_28 , L_51 ,
V_331 ) ;
return - V_42 ;
}
F_5 ( V_266 -> V_28 , L_52 ,
V_328 , V_331 / V_328 ) ;
F_6 ( V_2 , V_293 , V_352 , V_295 ) ;
F_6 ( V_2 , V_322 , V_348 , V_326 ) ;
F_6 ( V_2 , V_323 , V_353 , V_327 ) ;
F_6 ( V_2 , V_324 , V_354 ,
V_328 ) ;
F_6 ( V_2 , V_325 , V_355 |
V_258 , V_329 ) ;
if ( V_319 -> V_333 == V_334 ) {
switch ( V_266 -> V_82 ) {
case 1 :
V_4 -> V_97 [ 0 ] = F_75 ( V_321 ) ;
F_18 ( V_2 , 0 ) ;
F_18 ( V_2 , 1 ) ;
break;
case 2 :
V_4 -> V_97 [ 1 ] = F_75 ( V_321 ) ;
F_18 ( V_2 , 2 ) ;
break;
}
}
return 0 ;
}
static int F_78 ( struct V_318 * V_319 ,
struct V_320 * V_321 ,
struct V_265 * V_266 )
{
struct V_1 * V_2 = V_266 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_293 ;
int V_295 = 0 ;
switch ( V_266 -> V_82 ) {
case 3 :
switch ( V_5 -> type ) {
case V_280 :
case V_158 :
V_293 = V_315 ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
switch ( F_76 ( V_321 ) ) {
case V_341 :
break;
case V_342 :
V_295 |= 0x20 ;
break;
case V_343 :
V_295 |= 0x40 ;
break;
case V_344 :
V_295 |= 0x60 ;
break;
default:
return - V_42 ;
}
return F_6 ( V_2 , V_293 , V_352 , V_295 ) ;
}
static int F_79 ( struct V_265 * V_356 , int V_357 )
{
struct V_1 * V_2 = V_356 -> V_2 ;
int V_358 ;
int V_52 ;
switch ( V_356 -> V_82 ) {
case 1 :
V_358 = V_359 ;
break;
case 2 :
V_358 = V_360 ;
break;
default:
return - V_42 ;
}
if ( V_357 )
V_52 = V_361 ;
else
V_52 = 0 ;
F_6 ( V_2 , V_358 , V_361 , V_52 ) ;
return 0 ;
}
static int F_80 ( struct V_265 * V_356 , int V_362 )
{
struct V_1 * V_2 = V_356 -> V_2 ;
int V_52 , V_9 , V_62 ;
switch ( V_356 -> V_82 ) {
case 1 :
V_52 = V_296 ;
V_62 = V_363 ;
break;
case 2 :
V_52 = V_297 ;
V_62 = V_364 ;
break;
default:
return - V_42 ;
}
if ( V_362 )
V_9 = V_62 ;
else
V_9 = 0 ;
return F_6 ( V_2 , V_52 , V_62 , V_9 ) ;
}
static int F_81 ( struct V_265 * V_266 )
{
struct V_1 * V_2 = V_266 -> V_2 ;
F_6 ( V_2 , V_365 ,
V_366 | V_367 , 0 ) ;
F_6 ( V_2 , V_368 ,
V_366 | V_367 , 0 ) ;
F_6 ( V_2 , V_369 ,
V_366 | V_367 , 0 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 , V_63 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_39 ) ; V_7 ++ ) {
memcpy ( & V_4 -> V_370 [ V_7 ] , & V_4 -> V_39 [ V_7 ] ,
sizeof( struct V_371 ) ) ;
V_63 = F_58 ( V_2 , V_7 + 1 , 0 , 0 , 0 ) ;
if ( V_63 < 0 )
F_62 ( V_2 -> V_28 , L_53 ,
V_7 + 1 , V_63 ) ;
}
F_68 ( V_2 , V_287 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_7 , V_63 ;
unsigned int V_9 , V_62 ;
if ( V_5 -> V_252 < 4 ) {
V_63 = F_84 ( V_5 -> V_372 ,
V_173 , & V_9 ) ;
V_2 -> V_373 = 1 ;
V_62 = V_374 | V_375 |
V_376 | V_377 ;
V_9 &= V_62 ;
F_6 ( V_2 , V_173 ,
V_62 , V_9 ) ;
V_2 -> V_373 = 0 ;
}
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_39 ) ; V_7 ++ ) {
if ( ! V_4 -> V_370 [ V_7 ] . V_40 )
continue;
V_63 = F_58 ( V_2 , V_7 + 1 ,
V_4 -> V_370 [ V_7 ] . V_215 ,
V_4 -> V_370 [ V_7 ] . V_231 ,
V_4 -> V_370 [ V_7 ] . V_40 ) ;
if ( V_63 < 0 )
F_62 ( V_2 -> V_28 , L_54 ,
V_7 + 1 , V_63 ) ;
}
return 0 ;
}
static void F_85 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_136 . V_2 ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_70 * V_18 = & V_5 -> V_18 ;
struct V_378 V_379 [] = {
F_86 ( L_11 ,
V_4 -> V_380 ,
F_21 ,
F_20 ) ,
F_86 ( L_12 ,
V_4 -> V_380 ,
F_21 ,
F_20 ) ,
F_86 ( L_13 ,
V_4 -> V_380 ,
F_21 ,
F_20 ) ,
} ;
int V_63 , V_7 , V_381 ;
const char * * V_382 ;
V_4 -> V_91 = 0 ;
V_4 -> V_96 = NULL ;
for ( V_7 = 0 ; V_7 < V_18 -> V_94 ; V_7 ++ ) {
for ( V_381 = 0 ; V_381 < V_4 -> V_91 ; V_381 ++ ) {
if ( strcmp ( V_18 -> V_95 [ V_7 ] . V_54 ,
V_4 -> V_96 [ V_381 ] ) == 0 )
break;
}
if ( V_381 != V_4 -> V_91 )
continue;
V_382 = F_87 ( V_4 -> V_96 ,
sizeof( char * ) *
( V_4 -> V_91 + 1 ) ,
V_383 ) ;
if ( V_382 == NULL )
continue;
V_382 [ V_4 -> V_91 ] =
V_18 -> V_95 [ V_7 ] . V_54 ;
V_4 -> V_91 ++ ;
V_4 -> V_96 = V_382 ;
}
F_5 ( V_2 -> V_28 , L_55 ,
V_4 -> V_91 ) ;
V_4 -> V_380 . F_63 = V_4 -> V_91 ;
V_4 -> V_380 . V_384 = V_4 -> V_96 ;
V_63 = F_88 ( V_4 -> V_136 . V_2 , V_379 ,
F_4 ( V_379 ) ) ;
if ( V_63 != 0 )
F_59 ( V_4 -> V_136 . V_2 -> V_28 ,
L_56 , V_63 ) ;
}
static void F_89 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_136 . V_2 ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_70 * V_18 = & V_5 -> V_18 ;
int V_63 , V_7 ;
if ( ! V_18 )
return;
F_90 ( V_2 , V_18 -> V_385 ,
V_18 -> V_386 ,
V_18 -> V_387 ,
V_18 -> V_388 ,
V_18 -> V_389 ,
V_18 -> V_390 ,
V_18 -> V_391 ,
V_18 -> V_392 ,
V_18 -> V_393 ,
V_18 -> V_394 ) ;
F_5 ( V_2 -> V_28 , L_57 , V_18 -> V_84 ) ;
if ( V_18 -> V_84 ) {
struct V_378 V_379 [] = {
F_86 ( L_7 , V_4 -> V_395 ,
F_17 , F_16 ) ,
F_86 ( L_8 , V_4 -> V_395 ,
F_17 , F_16 ) ,
F_86 ( L_9 , V_4 -> V_395 ,
F_17 , F_16 ) ,
} ;
V_4 -> V_396 = F_91 ( V_4 -> V_136 . V_2 -> V_28 ,
sizeof( char * ) * V_18 -> V_84 , V_383 ) ;
if ( ! V_4 -> V_396 ) {
F_59 ( V_4 -> V_136 . V_2 -> V_28 ,
L_58 ,
V_18 -> V_84 ) ;
return;
}
for ( V_7 = 0 ; V_7 < V_18 -> V_84 ; V_7 ++ )
V_4 -> V_396 [ V_7 ] = V_18 -> V_80 [ V_7 ] . V_54 ;
V_4 -> V_395 . F_63 = V_18 -> V_84 ;
V_4 -> V_395 . V_384 = V_4 -> V_396 ;
V_63 = F_88 ( V_4 -> V_136 . V_2 , V_379 ,
F_4 ( V_379 ) ) ;
for ( V_7 = 0 ; V_7 < V_397 ; V_7 ++ )
F_14 ( V_2 , V_7 ) ;
} else {
V_63 = F_88 ( V_4 -> V_136 . V_2 ,
V_398 ,
F_4 ( V_398 ) ) ;
}
if ( V_63 != 0 )
F_59 ( V_4 -> V_136 . V_2 -> V_28 ,
L_59 , V_63 ) ;
F_5 ( V_2 -> V_28 , L_60 ,
V_18 -> V_94 ) ;
if ( V_18 -> V_94 )
F_85 ( V_4 ) ;
else
F_88 ( V_4 -> V_136 . V_2 , V_399 ,
F_4 ( V_399 ) ) ;
for ( V_7 = 0 ; V_7 < F_4 ( V_18 -> V_400 ) ; V_7 ++ ) {
if ( V_18 -> V_400 [ V_7 ] ) {
F_41 ( V_2 , V_281 + V_7 ,
V_18 -> V_400 [ V_7 ] & 0xffff ) ;
}
}
}
int F_92 ( struct V_1 * V_2 , struct V_401 * V_102 ,
int V_400 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_402 * V_101 ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_52 , V_63 ;
if ( V_5 -> type != V_157 ) {
F_62 ( V_2 -> V_28 , L_61 ) ;
return - V_42 ;
}
switch ( V_400 ) {
case 1 :
V_101 = & V_4 -> V_101 [ 0 ] ;
if ( V_102 )
V_63 = F_72 ( & V_2 -> V_48 ,
L_62 ) ;
else
V_63 = F_71 ( & V_2 -> V_48 ,
L_62 ) ;
break;
case 2 :
V_101 = & V_4 -> V_101 [ 1 ] ;
if ( V_102 )
V_63 = F_72 ( & V_2 -> V_48 ,
L_62 ) ;
else
V_63 = F_71 ( & V_2 -> V_48 ,
L_62 ) ;
break;
default:
F_62 ( V_2 -> V_28 , L_63 , V_400 ) ;
return - V_42 ;
}
if ( V_63 != 0 )
F_62 ( V_2 -> V_28 , L_64 ,
V_400 , V_63 ) ;
F_5 ( V_2 -> V_28 , L_65 ,
V_400 , V_102 ) ;
V_101 -> V_102 = V_102 ;
V_101 -> V_403 = true ;
if ( V_4 -> V_101 [ 0 ] . V_102 || V_4 -> V_101 [ 1 ] . V_102 )
V_52 = V_404 ;
else
V_52 = 0 ;
F_6 ( V_2 , V_405 , V_404 , V_52 ) ;
F_6 ( V_2 , V_406 ,
V_407 | V_408 |
V_409 | V_410 ,
V_411 | V_412 ) ;
F_9 ( & V_2 -> V_48 ) ;
return 0 ;
}
static void F_93 ( struct V_413 * V_414 )
{
struct V_3 * V_415 = F_94 ( V_414 ,
struct V_3 ,
V_416 . V_414 ) ;
struct V_372 * V_372 = V_415 -> V_4 -> V_372 ;
struct V_417 * V_28 = V_415 -> V_4 -> V_28 ;
unsigned int V_52 ;
int V_63 ;
int V_418 ;
F_31 ( V_28 ) ;
V_63 = F_84 ( V_372 , V_419 , & V_52 ) ;
if ( V_63 < 0 ) {
F_59 ( V_28 , L_66 ,
V_63 ) ;
F_36 ( V_28 ) ;
return;
}
F_5 ( V_28 , L_67 , V_52 ) ;
V_418 = 0 ;
if ( V_52 & V_420 ) {
if ( V_415 -> V_101 [ 0 ] . V_403 )
V_418 = V_421 ;
}
if ( V_52 & V_422 ) {
if ( V_415 -> V_101 [ 0 ] . V_403 )
V_418 = V_423 ;
else
V_418 |= V_424 ;
}
if ( V_418 )
V_415 -> V_101 [ 0 ] . V_403 = false ;
else
V_415 -> V_101 [ 0 ] . V_403 = true ;
F_95 ( V_415 -> V_101 [ 0 ] . V_102 , V_418 ,
V_421 | V_424 ) ;
V_418 = 0 ;
if ( V_52 & V_425 ) {
if ( V_415 -> V_101 [ 1 ] . V_403 )
V_418 = V_421 ;
}
if ( V_52 & V_426 ) {
if ( V_415 -> V_101 [ 1 ] . V_403 )
V_418 = V_423 ;
else
V_418 |= V_424 ;
}
if ( V_418 )
V_415 -> V_101 [ 1 ] . V_403 = false ;
else
V_415 -> V_101 [ 1 ] . V_403 = true ;
F_95 ( V_415 -> V_101 [ 1 ] . V_102 , V_418 ,
V_421 | V_424 ) ;
F_36 ( V_28 ) ;
}
static T_3 F_96 ( int V_261 , void * V_262 )
{
struct V_3 * V_415 = V_262 ;
struct V_1 * V_2 = V_415 -> V_136 . V_2 ;
#ifndef F_97
F_98 ( F_99 ( V_2 -> V_28 ) ) ;
#endif
F_100 ( V_2 -> V_28 , 300 ) ;
F_28 ( & V_415 -> V_416 , F_29 ( 250 ) ) ;
return V_264 ;
}
static void F_101 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_21 )
return;
F_24 ( & V_4 -> V_109 ) ;
F_6 ( V_2 , V_29 , V_427 , 0 ) ;
F_22 ( V_2 , V_112 ) ;
F_25 ( & V_4 -> V_109 ) ;
if ( V_4 -> V_4 -> V_18 . V_428 )
F_71 ( & V_2 -> V_48 ,
L_68 ) ;
}
static void F_102 ( struct V_1 * V_2 , T_1 V_429 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_418 ;
V_418 = 0 ;
if ( V_429 & 0x4 )
V_418 |= V_424 ;
if ( V_429 & 0x8 )
V_418 |= V_430 ;
if ( V_429 & 0x10 )
V_418 |= V_431 ;
if ( V_429 & 0x20 )
V_418 |= V_432 ;
if ( V_429 & 0x40 )
V_418 |= V_433 ;
if ( V_429 & 0x80 )
V_418 |= V_434 ;
F_95 ( V_4 -> V_101 [ 0 ] . V_102 , V_418 ,
V_4 -> V_435 ) ;
}
static void F_103 ( void * V_262 , T_1 V_429 )
{
struct V_1 * V_2 = V_262 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! ( V_429 & V_436 ) ) {
F_5 ( V_2 -> V_28 , L_69 ) ;
V_4 -> V_14 = false ;
V_4 -> V_110 = true ;
F_101 ( V_2 ) ;
F_1 ( V_2 ) ;
F_95 ( V_4 -> V_101 [ 0 ] . V_102 , 0 ,
V_4 -> V_435 |
V_421 ) ;
return;
}
if ( V_429 & 0x600 ) {
F_5 ( V_2 -> V_28 , L_70 ) ;
V_4 -> V_110 = false ;
V_4 -> V_14 = true ;
F_1 ( V_2 ) ;
F_95 ( V_4 -> V_101 [ 0 ] . V_102 , V_421 ,
V_421 ) ;
}
if ( V_429 & 0xfc ) {
F_5 ( V_2 -> V_28 , L_71 ) ;
V_4 -> V_110 = false ;
F_1 ( V_2 ) ;
F_101 ( V_2 ) ;
F_95 ( V_4 -> V_101 [ 0 ] . V_102 , V_423 ,
V_421 ) ;
}
}
static void F_104 ( struct V_413 * V_414 )
{
struct V_3 * V_4 = F_94 ( V_414 , struct V_3 ,
V_416 . V_414 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_1 * V_2 = V_4 -> V_136 . V_2 ;
F_31 ( V_2 -> V_28 ) ;
if ( V_5 -> V_18 . V_428 ) {
F_72 ( & V_2 -> V_48 ,
L_68 ) ;
F_9 ( & V_2 -> V_48 ) ;
}
F_24 ( & V_4 -> V_109 ) ;
F_5 ( V_2 -> V_28 , L_72 ) ;
if ( V_4 -> V_437 ) {
V_4 -> V_437 ( V_4 -> V_438 ) ;
} else {
V_4 -> V_110 = true ;
F_22 ( V_2 , V_111 ) ;
F_6 ( V_2 , V_29 ,
V_427 , V_427 ) ;
}
F_25 ( & V_4 -> V_109 ) ;
F_36 ( V_2 -> V_28 ) ;
}
static T_3 F_105 ( int V_261 , void * V_262 )
{
struct V_3 * V_4 = V_262 ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_1 * V_2 = V_4 -> V_136 . V_2 ;
int V_52 , V_439 ;
bool V_440 ;
F_31 ( V_2 -> V_28 ) ;
F_24 ( & V_4 -> V_109 ) ;
V_52 = F_3 ( V_2 , V_441 ) ;
if ( V_52 < 0 ) {
F_59 ( V_2 -> V_28 , L_73 , V_52 ) ;
F_25 ( & V_4 -> V_109 ) ;
F_36 ( V_2 -> V_28 ) ;
return V_442 ;
}
F_5 ( V_2 -> V_28 , L_74 , V_52 ) ;
V_440 = V_52 & V_443 ;
if ( V_440 ) {
F_5 ( V_2 -> V_28 , L_75 ) ;
F_1 ( V_2 ) ;
F_6 ( V_2 , V_283 ,
V_444 , 0 ) ;
F_6 ( V_2 , V_441 ,
V_445 , 0 ) ;
V_439 = V_5 -> V_18 . V_446 ;
F_28 ( & V_4 -> V_416 ,
F_29 ( V_439 ) ) ;
} else {
F_5 ( V_2 -> V_28 , L_76 ) ;
F_106 ( & V_4 -> V_416 ) ;
F_6 ( V_2 , V_283 ,
V_444 , V_444 ) ;
F_6 ( V_2 , V_441 ,
V_445 , V_445 ) ;
V_4 -> V_110 = false ;
V_4 -> V_14 = false ;
F_6 ( V_2 , V_29 ,
V_427 , 0 ) ;
F_22 ( V_2 , V_112 ) ;
}
F_25 ( & V_4 -> V_109 ) ;
if ( V_5 -> V_18 . V_428 && ! V_440 )
F_71 ( & V_2 -> V_48 , L_68 ) ;
if ( V_440 )
F_95 ( V_4 -> V_101 [ 0 ] . V_102 ,
V_447 , V_447 ) ;
else
F_95 ( V_4 -> V_101 [ 0 ] . V_102 , 0 ,
V_447 | V_421 |
V_4 -> V_435 ) ;
F_95 ( V_4 -> V_101 [ 0 ] . V_102 , 0 , 0 ) ;
F_36 ( V_2 -> V_28 ) ;
return V_264 ;
}
static void F_107 ( struct V_413 * V_414 )
{
struct V_3 * V_4 = F_94 ( V_414 ,
struct V_3 ,
V_118 . V_414 ) ;
F_105 ( 0 , V_4 ) ;
}
int F_108 ( struct V_1 * V_2 , struct V_401 * V_102 ,
T_4 V_448 , void * V_449 ,
T_5 V_450 , void * V_451 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
T_1 V_452 ;
switch ( V_5 -> type ) {
case V_280 :
case V_158 :
break;
default:
return - V_42 ;
}
if ( V_102 ) {
F_72 ( & V_2 -> V_48 , L_77 ) ;
F_9 ( & V_2 -> V_48 ) ;
V_4 -> V_101 [ 0 ] . V_102 = V_102 ;
if ( V_448 ) {
V_4 -> V_437 = V_448 ;
V_4 -> V_438 = V_449 ;
} else {
V_4 -> V_110 = true ;
V_4 -> V_14 = false ;
}
if ( V_450 ) {
V_4 -> V_453 = V_450 ;
V_4 -> V_454 = V_451 ;
} else {
V_4 -> V_453 = F_103 ;
V_4 -> V_454 = V_2 ;
}
F_1 ( V_2 ) ;
if ( V_5 -> V_18 . V_452 )
V_452 = V_5 -> V_18 . V_452 ;
else
V_452 = 0x41 ;
V_4 -> V_435 = V_424 | V_430 |
V_431 | V_432 |
V_433 | V_434 ;
F_6 ( V_2 , V_455 ,
V_456 , V_452 ) ;
F_33 ( V_2 -> V_48 . V_285 > V_286 ) ;
if ( V_4 -> V_21 ) {
F_6 ( V_2 , V_441 ,
V_445 , 0 ) ;
F_6 ( V_2 , V_283 ,
V_444 ,
V_444 ) ;
F_6 ( V_2 , V_457 ,
V_458 , 0 ) ;
F_22 ( V_2 ,
V_112 ) ;
} else {
F_6 ( V_2 , V_29 ,
V_427 , V_427 ) ;
}
} else {
F_6 ( V_2 , V_29 ,
V_427 , 0 ) ;
F_22 ( V_2 , V_106 ) ;
F_71 ( & V_2 -> V_48 , L_77 ) ;
F_9 ( & V_2 -> V_48 ) ;
}
return 0 ;
}
static T_3 F_109 ( int V_261 , void * V_262 )
{
struct V_3 * V_4 = V_262 ;
struct V_1 * V_2 = V_4 -> V_136 . V_2 ;
int V_52 , V_459 , V_63 ;
if ( ! ( F_3 ( V_2 , V_29 ) & V_427 ) )
return V_264 ;
F_31 ( V_2 -> V_28 ) ;
V_459 = 10 ;
do {
V_52 = F_3 ( V_2 , V_460 ) ;
if ( V_52 < 0 ) {
F_59 ( V_2 -> V_28 ,
L_78 ,
V_52 ) ;
F_36 ( V_2 -> V_28 ) ;
return V_442 ;
}
if ( ! ( V_52 & V_461 ) ) {
F_5 ( V_2 -> V_28 , L_79 ) ;
goto V_40;
}
if ( ! ( V_52 & V_436 ) || ( V_52 & V_462 ) )
break;
F_34 ( 1 ) ;
} while ( V_459 -- );
if ( V_459 == 0 )
F_62 ( V_2 -> V_28 , L_80 ) ;
#ifndef F_97
F_98 ( F_99 ( V_2 -> V_28 ) ) ;
#endif
if ( V_4 -> V_21 ) {
V_63 = F_3 ( V_2 , V_441 ) ;
if ( V_63 < 0 ) {
F_59 ( V_2 -> V_28 , L_73 ,
V_63 ) ;
} else if ( ! ( V_63 & V_443 ) ) {
F_5 ( V_2 -> V_28 , L_81 ) ;
goto V_40;
}
} else if ( ! ( V_52 & V_436 ) ) {
F_95 ( V_4 -> V_101 [ 0 ] . V_102 , 0 ,
V_447 | V_421 |
V_4 -> V_435 ) ;
V_4 -> V_110 = true ;
goto V_40;
}
if ( V_4 -> V_110 )
V_4 -> V_453 ( V_4 -> V_454 , V_52 ) ;
else
F_102 ( V_2 , V_52 ) ;
V_40:
F_36 ( V_2 -> V_28 ) ;
return V_264 ;
}
static T_3 F_110 ( int V_261 , void * V_262 )
{
struct V_1 * V_2 = V_262 ;
F_59 ( V_2 -> V_28 , L_82 ) ;
return V_264 ;
}
static T_3 F_111 ( int V_261 , void * V_262 )
{
struct V_1 * V_2 = V_262 ;
F_59 ( V_2 -> V_28 , L_83 ) ;
return V_264 ;
}
static T_3 F_112 ( int V_261 , void * V_262 )
{
struct V_1 * V_2 = V_262 ;
F_113 ( V_2 -> V_28 , L_84 ) ;
return V_264 ;
}
static int F_114 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_115 ( V_2 -> V_28 -> V_463 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_464 * V_48 = & V_2 -> V_48 ;
unsigned int V_52 ;
int V_63 , V_7 ;
V_4 -> V_136 . V_2 = V_2 ;
V_2 -> V_465 = V_5 -> V_372 ;
F_116 ( V_2 , 16 , 16 , V_466 ) ;
F_117 ( & V_4 -> V_109 ) ;
F_118 ( & V_4 -> V_118 ,
F_107 ) ;
switch ( V_5 -> type ) {
case V_157 :
F_118 ( & V_4 -> V_416 , F_93 ) ;
break;
case V_280 :
F_118 ( & V_4 -> V_416 , F_104 ) ;
break;
default:
break;
}
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_251 ) ; V_7 ++ )
F_119 ( & V_4 -> V_251 [ V_7 ] ) ;
V_4 -> V_467 = V_5 -> V_18 . V_467 ;
F_120 ( V_2 -> V_28 ) ;
F_121 ( V_2 -> V_28 ) ;
V_2 -> V_48 . V_468 = 1 ;
switch ( V_5 -> type ) {
case V_157 :
if ( ! V_5 -> V_18 . V_385 ||
! V_5 -> V_18 . V_386 )
V_2 -> V_48 . V_468 = 0 ;
switch ( V_5 -> V_252 ) {
case 2 :
case 3 :
V_4 -> V_136 . V_469 = - 5 ;
V_4 -> V_136 . V_470 = - 5 ;
V_4 -> V_136 . V_471 = 1 ;
V_4 -> V_136 . V_472 = 1 ;
V_4 -> V_136 . V_473 = 1 ;
break;
default:
V_4 -> V_136 . V_472 = 2 ;
break;
}
break;
case V_158 :
V_4 -> V_136 . V_472 = 1 ;
V_4 -> V_136 . V_471 = 1 ;
switch ( V_5 -> V_252 ) {
case 0 :
break;
default:
V_4 -> V_233 = true ;
break;
}
break;
case V_280 :
V_4 -> V_136 . V_472 = 2 ;
V_4 -> V_136 . V_474 = 1 ;
V_4 -> V_136 . V_471 = 1 ;
V_4 -> V_136 . V_475 = true ;
V_4 -> V_233 = true ;
V_4 -> V_136 . V_469 = - 9 ;
V_4 -> V_136 . V_470 = - 7 ;
F_6 ( V_2 , V_476 ,
V_477 , V_477 ) ;
break;
default:
break;
}
F_122 ( V_4 -> V_4 , V_478 ,
F_110 , L_85 , V_2 ) ;
F_122 ( V_4 -> V_4 , V_479 ,
F_111 , L_86 , V_2 ) ;
F_122 ( V_4 -> V_4 , V_480 ,
F_112 , L_87 , V_2 ) ;
V_63 = F_122 ( V_4 -> V_4 , V_481 ,
V_482 , L_88 ,
& V_4 -> V_136 ) ;
if ( V_63 == 0 )
V_4 -> V_136 . V_483 = true ;
switch ( V_5 -> type ) {
case V_157 :
if ( V_4 -> V_467 ) {
V_63 = F_123 ( V_4 -> V_467 , NULL ,
F_96 ,
V_484 ,
L_89 ,
V_4 ) ;
if ( V_63 != 0 )
F_62 ( V_2 -> V_28 ,
L_90 ,
V_63 ) ;
}
V_63 = F_122 ( V_4 -> V_4 ,
V_485 ,
F_96 , L_91 ,
V_4 ) ;
if ( V_63 != 0 )
F_62 ( V_2 -> V_28 ,
L_92 ,
V_63 ) ;
V_63 = F_122 ( V_4 -> V_4 ,
V_486 ,
F_96 , L_93 ,
V_4 ) ;
if ( V_63 != 0 )
F_62 ( V_2 -> V_28 ,
L_94 ,
V_63 ) ;
V_63 = F_122 ( V_4 -> V_4 ,
V_487 ,
F_96 , L_95 ,
V_4 ) ;
if ( V_63 != 0 )
F_62 ( V_2 -> V_28 ,
L_96 ,
V_63 ) ;
break;
case V_158 :
case V_280 :
if ( V_4 -> V_467 ) {
V_63 = F_123 ( V_4 -> V_467 , NULL ,
F_109 ,
V_484 ,
L_97 ,
V_4 ) ;
if ( V_63 != 0 )
F_62 ( V_2 -> V_28 ,
L_98 ,
V_63 ) ;
} else {
F_122 ( V_4 -> V_4 , V_488 ,
F_109 , L_97 ,
V_4 ) ;
}
}
switch ( V_5 -> type ) {
case V_280 :
if ( V_5 -> V_489 > 1 || V_5 -> V_252 > 1 ) {
V_63 = F_122 ( V_4 -> V_4 ,
F_124 ( 6 ) ,
F_105 , L_99 ,
V_4 ) ;
if ( V_63 == 0 )
V_4 -> V_21 = true ;
}
break;
default:
break;
}
V_4 -> V_255 = true ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_251 ) ; V_7 ++ ) {
V_63 = F_122 ( V_4 -> V_4 ,
V_490 + V_7 ,
F_64 , L_100 ,
& V_4 -> V_251 [ V_7 ] ) ;
if ( V_63 != 0 )
V_4 -> V_255 = false ;
}
F_31 ( V_2 -> V_28 ) ;
V_63 = F_84 ( V_5 -> V_372 , V_491 , & V_52 ) ;
if ( V_63 < 0 ) {
F_59 ( V_2 -> V_28 , L_101 , V_63 ) ;
goto V_492;
}
if ( ( V_52 & V_493 ) != V_494 ) {
V_4 -> V_335 [ 0 ] = 1 ;
V_495 [ 0 ] . V_496 = 1 ;
} else {
V_4 -> V_335 [ 0 ] = 0 ;
}
V_63 = F_84 ( V_5 -> V_372 , V_497 , & V_52 ) ;
if ( V_63 < 0 ) {
F_59 ( V_2 -> V_28 , L_102 , V_63 ) ;
goto V_492;
}
if ( ( V_52 & V_493 ) != V_494 ) {
V_4 -> V_335 [ 1 ] = 1 ;
V_495 [ 1 ] . V_496 = 1 ;
} else {
V_4 -> V_335 [ 1 ] = 0 ;
}
F_36 ( V_2 -> V_28 ) ;
for ( V_7 = 0 ; V_7 < F_4 ( V_176 ) ; V_7 ++ )
F_6 ( V_2 , V_176 [ V_7 ] . V_52 ,
V_176 [ V_7 ] . V_62 ,
V_176 [ V_7 ] . V_62 ) ;
F_6 ( V_2 , V_498 ,
1 << V_499 ,
1 << V_499 ) ;
F_6 ( V_2 , V_500 ,
1 << V_501 ,
1 << V_501 ) ;
F_6 ( V_2 , V_502 ,
1 << V_503 ,
1 << V_503 ) ;
switch ( V_5 -> type ) {
case V_157 :
case V_158 :
F_6 ( V_2 , V_162 ,
V_504 , V_504 ) ;
break;
default:
break;
}
switch ( V_5 -> type ) {
case V_158 :
case V_280 :
F_6 ( V_2 , V_281 ,
V_282 , V_282 ) ;
F_6 ( V_2 , V_283 ,
V_284 , V_284 ) ;
break;
default:
break;
}
V_4 -> V_136 . V_505 = F_38 ;
F_54 ( V_2 ) ;
F_89 ( V_4 ) ;
F_125 ( V_2 ) ;
F_88 ( V_2 , V_506 ,
F_4 ( V_506 ) ) ;
F_126 ( V_48 , V_507 ,
F_4 ( V_507 ) ) ;
switch ( V_5 -> type ) {
case V_157 :
F_126 ( V_48 , V_508 ,
F_4 ( V_508 ) ) ;
if ( V_5 -> V_252 < 4 ) {
F_126 ( V_48 , V_509 ,
F_4 ( V_509 ) ) ;
F_126 ( V_48 , V_510 ,
F_4 ( V_510 ) ) ;
F_126 ( V_48 , V_511 ,
F_4 ( V_511 ) ) ;
} else {
F_126 ( V_48 , V_512 ,
F_4 ( V_512 ) ) ;
F_126 ( V_48 , V_513 ,
F_4 ( V_513 ) ) ;
F_126 ( V_48 , V_514 ,
F_4 ( V_514 ) ) ;
}
break;
case V_158 :
F_88 ( V_2 , V_515 ,
F_4 ( V_515 ) ) ;
F_126 ( V_48 , V_516 ,
F_4 ( V_516 ) ) ;
if ( V_5 -> V_252 < 1 ) {
F_126 ( V_48 , V_509 ,
F_4 ( V_509 ) ) ;
F_126 ( V_48 , V_510 ,
F_4 ( V_510 ) ) ;
F_126 ( V_48 , V_511 ,
F_4 ( V_511 ) ) ;
} else {
F_126 ( V_48 , V_512 ,
F_4 ( V_512 ) ) ;
F_126 ( V_48 , V_513 ,
F_4 ( V_513 ) ) ;
F_126 ( V_48 , V_514 ,
F_4 ( V_514 ) ) ;
}
break;
case V_280 :
F_88 ( V_2 , V_515 ,
F_4 ( V_515 ) ) ;
F_126 ( V_48 , V_516 ,
F_4 ( V_516 ) ) ;
F_126 ( V_48 , V_512 ,
F_4 ( V_512 ) ) ;
F_126 ( V_48 , V_513 ,
F_4 ( V_513 ) ) ;
F_126 ( V_48 , V_514 ,
F_4 ( V_514 ) ) ;
break;
}
F_127 ( V_2 , 0 , 0 ) ;
F_128 ( V_48 , V_517 , F_4 ( V_517 ) ) ;
switch ( V_5 -> type ) {
case V_157 :
F_128 ( V_48 , V_518 ,
F_4 ( V_518 ) ) ;
if ( V_5 -> V_252 < 4 ) {
F_128 ( V_48 , V_519 ,
F_4 ( V_519 ) ) ;
F_128 ( V_48 , V_520 ,
F_4 ( V_520 ) ) ;
} else {
F_128 ( V_48 , V_521 ,
F_4 ( V_521 ) ) ;
}
break;
case V_158 :
if ( V_5 -> V_252 < 1 ) {
F_128 ( V_48 , V_518 ,
F_4 ( V_518 ) ) ;
F_128 ( V_48 , V_519 ,
F_4 ( V_519 ) ) ;
F_128 ( V_48 , V_520 ,
F_4 ( V_520 ) ) ;
} else {
F_128 ( V_48 , V_521 ,
F_4 ( V_521 ) ) ;
F_128 ( V_48 , V_522 ,
F_4 ( V_522 ) ) ;
}
F_129 ( V_2 ) ;
break;
case V_280 :
F_128 ( V_48 , V_521 ,
F_4 ( V_521 ) ) ;
F_128 ( V_48 , V_522 ,
F_4 ( V_522 ) ) ;
break;
}
return 0 ;
V_492:
if ( V_4 -> V_21 )
F_130 ( V_4 -> V_4 , F_124 ( 6 ) , V_4 ) ;
F_130 ( V_4 -> V_4 , V_487 , V_4 ) ;
F_130 ( V_4 -> V_4 , V_486 , V_4 ) ;
F_130 ( V_4 -> V_4 , V_485 , V_4 ) ;
if ( V_4 -> V_467 )
F_131 ( V_4 -> V_467 , V_4 ) ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_251 ) ; V_7 ++ )
F_130 ( V_4 -> V_4 , V_490 + V_7 ,
& V_4 -> V_251 [ V_7 ] ) ;
F_130 ( V_4 -> V_4 , V_481 ,
& V_4 -> V_136 ) ;
F_130 ( V_4 -> V_4 , V_478 , V_2 ) ;
F_130 ( V_4 -> V_4 , V_480 , V_2 ) ;
F_130 ( V_4 -> V_4 , V_479 , V_2 ) ;
return V_63 ;
}
static int F_132 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_7 ;
F_68 ( V_2 , V_287 ) ;
F_133 ( V_2 -> V_28 ) ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_251 ) ; V_7 ++ )
F_130 ( V_4 -> V_4 , V_490 + V_7 ,
& V_4 -> V_251 [ V_7 ] ) ;
F_130 ( V_4 -> V_4 , V_481 ,
& V_4 -> V_136 ) ;
F_130 ( V_4 -> V_4 , V_478 , V_2 ) ;
F_130 ( V_4 -> V_4 , V_480 , V_2 ) ;
F_130 ( V_4 -> V_4 , V_479 , V_2 ) ;
if ( V_4 -> V_21 )
F_130 ( V_4 -> V_4 , F_124 ( 6 ) , V_4 ) ;
switch ( V_5 -> type ) {
case V_157 :
if ( V_4 -> V_467 )
F_131 ( V_4 -> V_467 , V_4 ) ;
F_130 ( V_4 -> V_4 , V_486 ,
V_4 ) ;
F_130 ( V_4 -> V_4 , V_485 ,
V_4 ) ;
F_130 ( V_4 -> V_4 , V_488 ,
V_4 ) ;
break;
case V_280 :
case V_158 :
if ( V_4 -> V_467 )
F_131 ( V_4 -> V_467 , V_4 ) ;
break;
}
F_134 ( V_4 -> V_523 ) ;
F_134 ( V_4 -> V_524 ) ;
F_134 ( V_4 -> V_525 ) ;
F_135 ( V_4 -> V_96 ) ;
return 0 ;
}
static int F_136 ( struct V_526 * V_527 )
{
struct V_3 * V_4 ;
V_4 = F_91 ( & V_527 -> V_28 , sizeof( struct V_3 ) ,
V_383 ) ;
if ( V_4 == NULL )
return - V_528 ;
F_137 ( V_527 , V_4 ) ;
V_4 -> V_4 = F_115 ( V_527 -> V_28 . V_463 ) ;
return F_138 ( & V_527 -> V_28 , & V_529 ,
V_495 , F_4 ( V_495 ) ) ;
}
static int F_139 ( struct V_526 * V_527 )
{
F_140 ( & V_527 -> V_28 ) ;
return 0 ;
}
static int F_141 ( struct V_417 * V_28 )
{
struct V_3 * V_4 = F_115 ( V_28 ) ;
if ( V_4 -> V_21 && ! V_4 -> V_103 )
F_142 ( V_4 -> V_4 -> V_372 , V_107 ,
V_108 ,
V_4 -> V_105 ) ;
return 0 ;
}
static int F_143 ( struct V_417 * V_28 )
{
struct V_3 * V_4 = F_115 ( V_28 ) ;
if ( V_4 -> V_21 && V_4 -> V_105 )
F_142 ( V_4 -> V_4 -> V_372 , V_107 ,
V_108 ,
V_104 ) ;
return 0 ;
}
