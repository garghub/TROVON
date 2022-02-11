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
static int F_55 ( struct V_4 * V_5 , struct V_202 * V_39 ,
int V_203 , int V_204 )
{
T_2 V_205 ;
unsigned int V_206 , V_207 , V_208 , V_209 ;
F_56 ( L_25 , V_203 , V_204 ) ;
V_39 -> V_210 = 0 ;
while ( V_203 > 13500000 ) {
V_39 -> V_210 ++ ;
V_203 /= 2 ;
if ( V_39 -> V_210 > 3 )
return - V_42 ;
}
F_56 ( L_26 , V_39 -> V_210 , V_203 ) ;
V_39 -> V_211 = 3 ;
while ( V_204 * ( V_39 -> V_211 + 1 ) < 90000000 ) {
V_39 -> V_211 ++ ;
if ( V_39 -> V_211 > 63 )
return - V_42 ;
}
V_204 *= V_39 -> V_211 + 1 ;
F_56 ( L_27 , V_39 -> V_211 , V_204 ) ;
if ( V_203 > 1000000 ) {
V_39 -> V_212 = 0 ;
} else if ( V_203 > 256000 ) {
V_39 -> V_212 = 1 ;
V_203 *= 2 ;
} else if ( V_203 > 128000 ) {
V_39 -> V_212 = 2 ;
V_203 *= 4 ;
} else if ( V_203 > 64000 ) {
V_39 -> V_212 = 3 ;
V_203 *= 8 ;
} else {
V_39 -> V_212 = 4 ;
V_203 *= 16 ;
}
F_56 ( L_28 , V_39 -> V_212 , V_203 ) ;
V_207 = V_204 / V_203 ;
V_39 -> V_213 = V_207 ;
V_208 = V_204 % V_203 ;
F_56 ( L_29 , V_208 ) ;
switch ( V_5 -> type ) {
case V_157 :
V_205 = V_214 * ( long long ) V_208 ;
F_57 ( V_205 , V_203 ) ;
V_206 = V_205 & 0xFFFFFFFF ;
if ( ( V_206 % 10 ) >= 5 )
V_206 += 5 ;
V_39 -> V_215 = V_206 / 10 ;
V_39 -> V_216 = 0 ;
F_56 ( L_30 , V_39 -> V_213 , V_39 -> V_215 ) ;
break;
default:
V_209 = F_58 ( V_204 , V_203 ) ;
V_39 -> V_215 = ( V_204 - ( V_203 * V_39 -> V_213 ) ) / V_209 ;
V_39 -> V_216 = V_203 / V_209 ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , int V_82 , int V_217 ,
unsigned int V_203 , unsigned int V_204 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_218 , V_63 ;
struct V_202 V_39 ;
T_1 V_52 , V_219 , V_220 , V_221 ;
unsigned long V_222 ;
bool V_223 ;
switch ( V_82 ) {
case V_224 :
V_218 = 0 ;
V_82 = 0 ;
V_221 = 0x10 ;
break;
case V_225 :
V_218 = 0x20 ;
V_82 = 1 ;
V_221 = 0x18 ;
break;
default:
return - V_42 ;
}
V_52 = F_3 ( V_2 , V_226 + V_218 ) ;
V_223 = V_52 & V_227 ;
switch ( V_217 ) {
case 0 :
if ( V_204 )
return - V_42 ;
V_217 = V_4 -> V_39 [ V_82 ] . V_217 ;
break;
case V_228 :
case V_229 :
case V_230 :
case V_231 :
break;
case V_232 :
V_203 = 12000000 ;
V_204 = 12000000 ;
break;
default:
return - V_42 ;
}
if ( V_4 -> V_39 [ V_82 ] . V_217 == V_217 &&
V_4 -> V_39 [ V_82 ] . V_233 == V_203 && V_4 -> V_39 [ V_82 ] . V_40 == V_204 )
return 0 ;
if ( V_204 )
V_63 = F_55 ( V_5 , & V_39 , V_203 , V_204 ) ;
else
V_63 = F_55 ( V_5 , & V_39 , V_4 -> V_39 [ V_82 ] . V_233 ,
V_4 -> V_39 [ V_82 ] . V_40 ) ;
if ( V_63 < 0 )
return V_63 ;
V_219 = F_3 ( V_2 , V_15 ) ;
if ( V_219 & V_16 )
V_220 = V_195 ;
else
V_220 = V_44 ;
V_52 = F_3 ( V_2 , V_220 ) ;
if ( ( V_52 & V_194 ) &&
( V_52 & V_45 ) == V_221 ) {
F_60 ( V_2 -> V_28 , L_31 ,
V_82 + 1 ) ;
return - V_234 ;
}
F_6 ( V_2 , V_226 + V_218 ,
V_227 , 0 ) ;
if ( V_4 -> V_235 && V_217 == V_231 &&
V_203 == V_204 && V_204 ) {
F_5 ( V_2 -> V_28 , L_32 , V_82 + 1 ) ;
F_6 ( V_2 , V_236 + V_218 ,
V_237 , V_237 ) ;
goto V_40;
}
V_52 = ( V_39 . V_211 << V_238 ) |
( V_39 . V_212 << V_239 ) ;
F_6 ( V_2 , V_240 + V_218 ,
V_241 |
V_242 , V_52 ) ;
F_6 ( V_2 , V_243 + V_218 ,
V_244 , V_39 . V_215 ) ;
F_6 ( V_2 , V_245 + V_218 ,
V_246 ,
V_39 . V_213 << V_247 ) ;
if ( V_39 . V_216 ) {
F_6 ( V_2 , V_248 + V_218 ,
V_249 ,
V_39 . V_216 ) ;
F_6 ( V_2 , V_250 + V_218 ,
V_251 , V_251 ) ;
} else {
F_6 ( V_2 , V_250 + V_218 ,
V_251 , 0 ) ;
}
F_6 ( V_2 , V_236 + V_218 ,
V_252 | V_237 |
V_253 |
V_254 ,
( ( V_217 == V_232 )
<< V_255 ) |
( V_39 . V_210 << V_256 ) |
( V_217 - 1 ) ) ;
F_61 ( & V_4 -> V_257 [ V_82 ] ) ;
if ( V_204 ) {
if ( ! V_223 ) {
F_23 ( V_2 ) ;
switch ( V_5 -> type ) {
case V_157 :
F_30 ( V_2 ) ;
break;
case V_158 :
if ( V_5 -> V_258 < 1 )
F_30 ( V_2 ) ;
break;
default:
break;
}
}
V_52 = V_227 ;
if ( V_39 . V_215 )
V_52 |= V_259 ;
if ( V_217 == V_232 )
V_52 |= V_260 ;
F_6 ( V_2 , V_226 + V_218 ,
V_227 | V_260 |
V_259 , V_52 ) ;
if ( V_4 -> V_261 ) {
V_222 = F_62 ( & V_4 -> V_257 [ V_82 ] ,
F_29 ( 10 ) ) ;
if ( V_222 == 0 )
F_63 ( V_2 -> V_28 ,
L_33 ) ;
} else {
F_34 ( 5 ) ;
}
} else {
if ( V_223 ) {
switch ( V_5 -> type ) {
case V_157 :
F_35 ( V_2 ) ;
break;
case V_158 :
if ( V_5 -> V_258 < 1 )
F_35 ( V_2 ) ;
break;
default:
break;
}
F_26 ( V_2 ) ;
}
}
V_40:
V_4 -> V_39 [ V_82 ] . V_233 = V_203 ;
V_4 -> V_39 [ V_82 ] . V_40 = V_204 ;
V_4 -> V_39 [ V_82 ] . V_217 = V_217 ;
F_8 ( V_2 ) ;
if ( F_64 ( V_4 -> V_17 [ 0 ] , V_4 -> V_17 [ 1 ] ) < 50000 ) {
F_5 ( V_2 -> V_28 , L_34 ) ;
V_4 -> V_262 [ 0 ] = F_3 ( V_2 , V_263 )
& V_264 ;
V_4 -> V_262 [ 1 ] = F_3 ( V_2 , V_265 )
& V_264 ;
F_6 ( V_2 , V_263 ,
V_264 , 0x1 ) ;
F_6 ( V_2 , V_265 ,
V_266 , 0x1 ) ;
} else if ( V_4 -> V_262 [ 0 ] ) {
F_6 ( V_2 , V_263 ,
V_264 ,
V_4 -> V_262 [ 0 ] ) ;
F_6 ( V_2 , V_265 ,
V_266 ,
V_4 -> V_262 [ 1 ] ) ;
V_4 -> V_262 [ 0 ] = 0 ;
V_4 -> V_262 [ 1 ] = 0 ;
}
return 0 ;
}
static T_3 F_65 ( int V_267 , void * V_268 )
{
struct V_269 * V_269 = V_268 ;
F_66 ( V_269 ) ;
return V_270 ;
}
static int F_67 ( struct V_271 * V_272 , int V_82 , int V_217 ,
unsigned int V_203 , unsigned int V_204 )
{
return F_59 ( V_272 -> V_2 , V_82 , V_217 , V_203 , V_204 ) ;
}
static int F_68 ( struct V_271 * V_272 ,
int V_273 , unsigned int V_274 , int V_275 )
{
struct V_1 * V_2 = V_272 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
switch ( V_272 -> V_82 ) {
case 1 :
case 2 :
break;
default:
return - V_42 ;
}
switch ( V_273 ) {
case V_35 :
V_4 -> V_8 [ V_272 -> V_82 - 1 ] = V_35 ;
V_4 -> V_36 [ 0 ] = V_274 ;
F_5 ( V_272 -> V_28 , L_35 ,
V_272 -> V_82 , V_274 ) ;
break;
case V_37 :
V_4 -> V_8 [ V_272 -> V_82 - 1 ] = V_37 ;
V_4 -> V_36 [ 1 ] = V_274 ;
F_5 ( V_272 -> V_28 , L_36 ,
V_272 -> V_82 , V_274 ) ;
break;
case V_38 :
V_4 -> V_8 [ V_272 -> V_82 - 1 ] = V_38 ;
F_5 ( V_272 -> V_28 , L_37 , V_272 -> V_82 ) ;
break;
case V_41 :
V_4 -> V_8 [ V_272 -> V_82 - 1 ] = V_41 ;
F_5 ( V_272 -> V_28 , L_38 , V_272 -> V_82 ) ;
break;
case V_276 :
if ( V_274 ) {
for ( V_7 = 0 ; V_7 < F_4 ( V_277 ) ; V_7 ++ )
if ( V_277 [ V_7 ] == V_274 )
break;
if ( V_7 == F_4 ( V_277 ) )
return - V_42 ;
F_6 ( V_2 , V_278 ,
V_279 , V_7 ) ;
F_6 ( V_2 , V_280 ,
V_281 , V_281 ) ;
} else {
F_6 ( V_2 , V_280 ,
V_281 , 0 ) ;
}
default:
return - V_42 ;
}
F_8 ( V_2 ) ;
if ( F_64 ( V_4 -> V_17 [ 0 ] , V_4 -> V_17 [ 1 ] ) < 50000 ) {
F_5 ( V_2 -> V_28 , L_34 ) ;
V_4 -> V_262 [ 0 ] = F_3 ( V_2 , V_263 )
& V_264 ;
V_4 -> V_262 [ 1 ] = F_3 ( V_2 , V_265 )
& V_264 ;
F_6 ( V_2 , V_263 ,
V_264 , 0x1 ) ;
F_6 ( V_2 , V_265 ,
V_266 , 0x1 ) ;
} else if ( V_4 -> V_262 [ 0 ] ) {
F_6 ( V_2 , V_263 ,
V_264 ,
V_4 -> V_262 [ 0 ] ) ;
F_6 ( V_2 , V_265 ,
V_266 ,
V_4 -> V_262 [ 1 ] ) ;
V_4 -> V_262 [ 0 ] = 0 ;
V_4 -> V_262 [ 1 ] = 0 ;
}
return 0 ;
}
static int F_69 ( struct V_1 * V_2 ,
enum V_282 V_283 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
F_70 ( V_2 , V_283 ) ;
switch ( V_283 ) {
case V_284 :
break;
case V_285 :
switch ( V_5 -> type ) {
case V_158 :
case V_286 :
F_6 ( V_2 , V_287 ,
V_288 , 0 ) ;
F_6 ( V_2 , V_289 ,
V_290 , 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_48 . V_291 == V_292 )
F_23 ( V_2 ) ;
break;
case V_292 :
if ( V_2 -> V_48 . V_291 == V_293 ) {
switch ( V_5 -> type ) {
case V_158 :
if ( V_5 -> V_258 == 0 ) {
F_6 ( V_2 ,
V_294 ,
V_295 ,
V_295 ) ;
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
if ( V_2 -> V_48 . V_291 == V_285 )
F_26 ( V_2 ) ;
switch ( V_5 -> type ) {
case V_158 :
case V_286 :
F_6 ( V_2 , V_287 ,
V_288 ,
V_288 ) ;
F_6 ( V_2 , V_289 ,
V_290 ,
V_290 ) ;
break;
default:
break;
}
break;
case V_293 :
if ( V_2 -> V_48 . V_291 == V_292 )
V_4 -> V_296 = NULL ;
break;
}
V_2 -> V_48 . V_291 = V_283 ;
return 0 ;
}
int F_71 ( struct V_1 * V_2 , enum F_71 V_100 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_100 ) {
case V_125 :
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
F_9 ( & V_2 -> V_48 ) ;
V_4 -> V_124 = V_100 ;
break;
case V_135 :
if ( V_4 -> V_136 . V_137 ) {
F_73 ( & V_2 -> V_48 ,
L_39 ) ;
F_73 ( & V_2 -> V_48 ,
L_40 ) ;
}
if ( V_4 -> V_136 . V_141 ) {
F_73 ( & V_2 -> V_48 ,
L_41 ) ;
F_73 ( & V_2 -> V_48 ,
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
static int F_74 ( struct V_271 * V_272 , unsigned int V_297 )
{
struct V_1 * V_2 = V_272 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_298 ;
int V_299 ;
int V_300 ;
int V_301 ;
int V_302 = 0 ;
int V_303 = 0 ;
int V_304 = 0 ;
switch ( V_272 -> V_82 ) {
case 1 :
V_298 = V_305 ;
V_299 = V_162 ;
V_300 = V_306 ;
V_301 = V_307 ;
break;
case 2 :
V_298 = V_308 ;
V_299 = V_179 ;
V_300 = V_306 ;
V_301 = V_307 ;
break;
default:
return - V_42 ;
}
switch ( V_297 & V_309 ) {
case V_310 :
break;
case V_311 :
V_302 = V_312 ;
break;
default:
return - V_42 ;
}
switch ( V_297 & V_313 ) {
case V_314 :
V_303 |= V_315 ;
V_304 |= V_316 ;
case V_317 :
V_303 |= 0x18 ;
break;
case V_318 :
V_303 |= 0x10 ;
break;
case V_319 :
break;
case V_320 :
V_303 |= 0x8 ;
break;
default:
return - V_42 ;
}
switch ( V_297 & V_313 ) {
case V_317 :
case V_314 :
switch ( V_297 & V_321 ) {
case V_322 :
break;
case V_323 :
V_303 |= V_324 ;
break;
default:
return - V_42 ;
}
break;
case V_318 :
case V_319 :
case V_320 :
switch ( V_297 & V_321 ) {
case V_322 :
break;
case V_325 :
V_303 |= V_324 | V_315 ;
V_304 |= V_316 ;
break;
case V_323 :
V_303 |= V_324 ;
break;
case V_326 :
V_303 |= V_315 ;
V_304 |= V_316 ;
break;
default:
return - V_42 ;
}
break;
default:
return - V_42 ;
}
switch ( V_5 -> type ) {
case V_286 :
case V_158 :
if ( V_272 -> V_82 == 2 )
F_6 ( V_2 , V_327 ,
V_315 |
V_328 , V_303 ) ;
break;
default:
break;
}
F_6 ( V_2 , V_299 ,
V_324 | V_315 |
V_329 ,
V_303 ) ;
F_6 ( V_2 , V_298 , V_312 ,
V_302 ) ;
F_6 ( V_2 , V_300 ,
V_316 , V_304 ) ;
F_6 ( V_2 , V_301 ,
V_316 , V_304 ) ;
return 0 ;
}
static int F_75 ( struct V_330 * V_331 ,
struct V_332 * V_333 ,
struct V_271 * V_272 )
{
struct V_1 * V_2 = V_272 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_70 * V_18 = & V_5 -> V_18 ;
int V_299 ;
int V_334 ;
int V_335 ;
int V_336 ;
int V_337 ;
int V_303 = 0 ;
int V_338 = 0 ;
int V_339 = 0 ;
int V_304 = 0 ;
int V_340 = 0 ;
int V_82 = V_272 -> V_82 - 1 ;
int V_7 , V_341 , V_90 , V_342 , V_6 ;
switch ( V_272 -> V_82 ) {
case 1 :
V_299 = V_162 ;
V_334 = V_169 ;
V_335 = V_343 ;
V_337 = V_263 ;
if ( V_331 -> V_344 == V_345 ||
V_4 -> V_346 [ 0 ] ) {
V_336 = V_306 ;
} else {
V_336 = V_307 ;
F_5 ( V_2 -> V_28 , L_43 ) ;
}
break;
case 2 :
V_299 = V_179 ;
V_334 = V_184 ;
V_335 = V_347 ;
V_337 = V_265 ;
if ( V_331 -> V_344 == V_345 ||
V_4 -> V_346 [ 1 ] ) {
V_336 = V_348 ;
} else {
V_336 = V_349 ;
F_5 ( V_2 -> V_28 , L_44 ) ;
}
break;
default:
return - V_42 ;
}
V_342 = F_76 ( V_333 ) ;
switch ( F_77 ( V_333 ) ) {
case V_350 :
V_342 *= 16 ;
break;
case V_351 :
V_342 *= 20 ;
V_303 |= 0x20 ;
break;
case V_352 :
V_342 *= 24 ;
V_303 |= 0x40 ;
break;
case V_353 :
V_342 *= 32 ;
V_303 |= 0x60 ;
break;
default:
return - V_42 ;
}
V_4 -> V_161 [ V_82 ] = F_78 ( V_333 ) ;
if ( V_18 -> V_354 [ V_82 ] &&
V_4 -> V_161 [ V_82 ] > V_18 -> V_354 [ V_82 ] ) {
F_5 ( V_272 -> V_28 , L_45 ,
V_18 -> V_354 [ V_82 ] , V_4 -> V_161 [ V_82 ] ) ;
V_4 -> V_161 [ V_82 ] = V_18 -> V_354 [ V_82 ] ;
}
switch ( V_4 -> V_161 [ V_82 ] ) {
case 1 :
case 2 :
V_342 *= 2 ;
break;
default:
V_342 *= 4 ;
break;
}
for ( V_7 = 0 ; V_7 < F_4 ( V_355 ) ; V_7 ++ )
if ( V_355 [ V_7 ] . V_26 == F_76 ( V_333 ) )
break;
if ( V_7 == F_4 ( V_355 ) )
return - V_42 ;
V_340 |= V_355 [ V_7 ] . V_9 << V_356 ;
F_5 ( V_272 -> V_28 , L_46 , V_355 [ V_7 ] . V_26 ) ;
F_5 ( V_272 -> V_28 , L_47 ,
V_272 -> V_82 , V_4 -> V_17 [ V_82 ] , V_342 ) ;
if ( V_4 -> V_161 [ V_82 ] == 1 &&
( F_3 ( V_2 , V_299 ) & 0x18 ) == 0x18 )
V_338 |= V_357 ;
if ( V_4 -> V_17 [ V_82 ] == 0 ) {
F_60 ( V_272 -> V_28 , L_48 , V_272 -> V_82 ) ;
return - V_42 ;
}
V_6 = 0 ;
V_90 = abs ( ( V_358 [ 0 ] * F_76 ( V_333 ) )
- V_4 -> V_17 [ V_82 ] ) ;
for ( V_7 = 1 ; V_7 < F_4 ( V_358 ) ; V_7 ++ ) {
V_341 = abs ( ( V_358 [ V_7 ] * F_76 ( V_333 ) )
- V_4 -> V_17 [ V_82 ] ) ;
if ( V_341 >= V_90 )
continue;
V_6 = V_7 ;
V_90 = V_341 ;
}
F_5 ( V_272 -> V_28 , L_49 ,
V_272 -> V_82 , V_358 [ V_6 ] ) ;
V_340 |= V_6 ;
V_6 = 0 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_359 ) ; V_7 ++ ) {
V_341 = ( V_4 -> V_17 [ V_82 ] * 10 / V_359 [ V_7 ] ) - V_342 ;
if ( V_341 < 0 )
break;
V_6 = V_7 ;
}
V_342 = V_4 -> V_17 [ V_82 ] * 10 / V_359 [ V_6 ] ;
F_5 ( V_272 -> V_28 , L_50 ,
V_359 [ V_6 ] , V_342 ) ;
V_339 |= V_6 << V_360 ;
V_304 = V_342 / F_76 ( V_333 ) ;
if ( ! V_304 ) {
F_60 ( V_272 -> V_28 , L_51 ,
V_342 ) ;
return - V_42 ;
}
F_5 ( V_272 -> V_28 , L_52 ,
V_304 , V_342 / V_304 ) ;
F_6 ( V_2 , V_299 , V_361 , V_303 ) ;
F_6 ( V_2 , V_334 , V_357 , V_338 ) ;
F_6 ( V_2 , V_335 , V_362 , V_339 ) ;
F_6 ( V_2 , V_336 , V_363 ,
V_304 ) ;
F_6 ( V_2 , V_337 , V_364 |
V_264 , V_340 ) ;
if ( V_331 -> V_344 == V_345 ) {
switch ( V_272 -> V_82 ) {
case 1 :
V_4 -> V_97 [ 0 ] = F_76 ( V_333 ) ;
F_18 ( V_2 , 0 ) ;
F_18 ( V_2 , 1 ) ;
break;
case 2 :
V_4 -> V_97 [ 1 ] = F_76 ( V_333 ) ;
F_18 ( V_2 , 2 ) ;
break;
}
}
return 0 ;
}
static int F_79 ( struct V_330 * V_331 ,
struct V_332 * V_333 ,
struct V_271 * V_272 )
{
struct V_1 * V_2 = V_272 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_299 ;
int V_303 = 0 ;
switch ( V_272 -> V_82 ) {
case 3 :
switch ( V_5 -> type ) {
case V_286 :
case V_158 :
V_299 = V_327 ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
switch ( F_77 ( V_333 ) ) {
case V_350 :
break;
case V_351 :
V_303 |= 0x20 ;
break;
case V_352 :
V_303 |= 0x40 ;
break;
case V_353 :
V_303 |= 0x60 ;
break;
default:
return - V_42 ;
}
return F_6 ( V_2 , V_299 , V_361 , V_303 ) ;
}
static int F_80 ( struct V_271 * V_365 , int V_366 )
{
struct V_1 * V_2 = V_365 -> V_2 ;
int V_367 ;
int V_52 ;
switch ( V_365 -> V_82 ) {
case 1 :
V_367 = V_368 ;
break;
case 2 :
V_367 = V_369 ;
break;
default:
return - V_42 ;
}
if ( V_366 )
V_52 = V_370 ;
else
V_52 = 0 ;
F_6 ( V_2 , V_367 , V_370 , V_52 ) ;
return 0 ;
}
static int F_81 ( struct V_271 * V_365 , int V_371 )
{
struct V_1 * V_2 = V_365 -> V_2 ;
int V_52 , V_9 , V_62 ;
switch ( V_365 -> V_82 ) {
case 1 :
V_52 = V_305 ;
V_62 = V_372 ;
break;
case 2 :
V_52 = V_308 ;
V_62 = V_373 ;
break;
default:
return - V_42 ;
}
if ( V_371 )
V_9 = V_62 ;
else
V_9 = 0 ;
return F_6 ( V_2 , V_52 , V_62 , V_9 ) ;
}
static int F_82 ( struct V_271 * V_272 )
{
struct V_1 * V_2 = V_272 -> V_2 ;
F_6 ( V_2 , V_374 ,
V_375 | V_376 , 0 ) ;
F_6 ( V_2 , V_377 ,
V_375 | V_376 , 0 ) ;
F_6 ( V_2 , V_378 ,
V_375 | V_376 , 0 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 , V_63 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_39 ) ; V_7 ++ ) {
memcpy ( & V_4 -> V_379 [ V_7 ] , & V_4 -> V_39 [ V_7 ] ,
sizeof( struct V_380 ) ) ;
V_63 = F_59 ( V_2 , V_7 + 1 , 0 , 0 , 0 ) ;
if ( V_63 < 0 )
F_63 ( V_2 -> V_28 , L_53 ,
V_7 + 1 , V_63 ) ;
}
F_69 ( V_2 , V_293 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 , V_63 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_39 ) ; V_7 ++ ) {
if ( ! V_4 -> V_379 [ V_7 ] . V_40 )
continue;
V_63 = F_59 ( V_2 , V_7 + 1 ,
V_4 -> V_379 [ V_7 ] . V_217 ,
V_4 -> V_379 [ V_7 ] . V_233 ,
V_4 -> V_379 [ V_7 ] . V_40 ) ;
if ( V_63 < 0 )
F_63 ( V_2 -> V_28 , L_54 ,
V_7 + 1 , V_63 ) ;
}
return 0 ;
}
static void F_85 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_136 . V_2 ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_70 * V_18 = & V_5 -> V_18 ;
struct V_381 V_382 [] = {
F_86 ( L_11 ,
V_4 -> V_383 ,
F_21 ,
F_20 ) ,
F_86 ( L_12 ,
V_4 -> V_383 ,
F_21 ,
F_20 ) ,
F_86 ( L_13 ,
V_4 -> V_383 ,
F_21 ,
F_20 ) ,
} ;
int V_63 , V_7 , V_384 ;
const char * * V_385 ;
V_4 -> V_91 = 0 ;
V_4 -> V_96 = NULL ;
for ( V_7 = 0 ; V_7 < V_18 -> V_94 ; V_7 ++ ) {
for ( V_384 = 0 ; V_384 < V_4 -> V_91 ; V_384 ++ ) {
if ( strcmp ( V_18 -> V_95 [ V_7 ] . V_54 ,
V_4 -> V_96 [ V_384 ] ) == 0 )
break;
}
if ( V_384 != V_4 -> V_91 )
continue;
V_385 = F_87 ( V_4 -> V_96 ,
sizeof( char * ) *
( V_4 -> V_91 + 1 ) ,
V_386 ) ;
if ( V_385 == NULL )
continue;
V_385 [ V_4 -> V_91 ] =
V_18 -> V_95 [ V_7 ] . V_54 ;
V_4 -> V_91 ++ ;
V_4 -> V_96 = V_385 ;
}
F_5 ( V_2 -> V_28 , L_55 ,
V_4 -> V_91 ) ;
V_4 -> V_383 . F_64 = V_4 -> V_91 ;
V_4 -> V_383 . V_387 = V_4 -> V_96 ;
V_63 = F_88 ( V_4 -> V_136 . V_2 , V_382 ,
F_4 ( V_382 ) ) ;
if ( V_63 != 0 )
F_60 ( V_4 -> V_136 . V_2 -> V_28 ,
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
F_90 ( V_2 , V_18 -> V_388 ,
V_18 -> V_389 ,
V_18 -> V_390 ,
V_18 -> V_391 ,
V_18 -> V_392 ,
V_18 -> V_393 ,
V_18 -> V_394 ,
V_18 -> V_395 ,
V_18 -> V_396 ,
V_18 -> V_397 ) ;
F_5 ( V_2 -> V_28 , L_57 , V_18 -> V_84 ) ;
if ( V_18 -> V_84 ) {
struct V_381 V_382 [] = {
F_86 ( L_7 , V_4 -> V_398 ,
F_17 , F_16 ) ,
F_86 ( L_8 , V_4 -> V_398 ,
F_17 , F_16 ) ,
F_86 ( L_9 , V_4 -> V_398 ,
F_17 , F_16 ) ,
} ;
V_4 -> V_399 = F_91 ( V_4 -> V_136 . V_2 -> V_28 ,
sizeof( char * ) * V_18 -> V_84 , V_386 ) ;
if ( ! V_4 -> V_399 ) {
F_60 ( V_4 -> V_136 . V_2 -> V_28 ,
L_58 ,
V_18 -> V_84 ) ;
return;
}
for ( V_7 = 0 ; V_7 < V_18 -> V_84 ; V_7 ++ )
V_4 -> V_399 [ V_7 ] = V_18 -> V_80 [ V_7 ] . V_54 ;
V_4 -> V_398 . F_64 = V_18 -> V_84 ;
V_4 -> V_398 . V_387 = V_4 -> V_399 ;
V_63 = F_88 ( V_4 -> V_136 . V_2 , V_382 ,
F_4 ( V_382 ) ) ;
for ( V_7 = 0 ; V_7 < V_400 ; V_7 ++ )
F_14 ( V_2 , V_7 ) ;
} else {
V_63 = F_88 ( V_4 -> V_136 . V_2 ,
V_401 ,
F_4 ( V_401 ) ) ;
}
if ( V_63 != 0 )
F_60 ( V_4 -> V_136 . V_2 -> V_28 ,
L_59 , V_63 ) ;
F_5 ( V_2 -> V_28 , L_60 ,
V_18 -> V_94 ) ;
if ( V_18 -> V_94 )
F_85 ( V_4 ) ;
else
F_88 ( V_4 -> V_136 . V_2 , V_402 ,
F_4 ( V_402 ) ) ;
for ( V_7 = 0 ; V_7 < F_4 ( V_18 -> V_403 ) ; V_7 ++ ) {
if ( V_18 -> V_403 [ V_7 ] ) {
F_41 ( V_2 , V_287 + V_7 ,
V_18 -> V_403 [ V_7 ] & 0xffff ) ;
}
}
}
int F_92 ( struct V_1 * V_2 , struct V_404 * V_102 ,
int V_403 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_405 * V_101 ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_52 , V_63 ;
if ( V_5 -> type != V_157 ) {
F_63 ( V_2 -> V_28 , L_61 ) ;
return - V_42 ;
}
switch ( V_403 ) {
case 1 :
V_101 = & V_4 -> V_101 [ 0 ] ;
if ( V_102 )
V_63 = F_73 ( & V_2 -> V_48 ,
L_62 ) ;
else
V_63 = F_72 ( & V_2 -> V_48 ,
L_62 ) ;
break;
case 2 :
V_101 = & V_4 -> V_101 [ 1 ] ;
if ( V_102 )
V_63 = F_73 ( & V_2 -> V_48 ,
L_62 ) ;
else
V_63 = F_72 ( & V_2 -> V_48 ,
L_62 ) ;
break;
default:
F_63 ( V_2 -> V_28 , L_63 , V_403 ) ;
return - V_42 ;
}
if ( V_63 != 0 )
F_63 ( V_2 -> V_28 , L_64 ,
V_403 , V_63 ) ;
F_5 ( V_2 -> V_28 , L_65 ,
V_403 , V_102 ) ;
V_101 -> V_102 = V_102 ;
V_101 -> V_406 = true ;
if ( V_4 -> V_101 [ 0 ] . V_102 || V_4 -> V_101 [ 1 ] . V_102 )
V_52 = V_407 ;
else
V_52 = 0 ;
F_6 ( V_2 , V_408 , V_407 , V_52 ) ;
F_6 ( V_2 , V_409 ,
V_410 | V_411 |
V_412 | V_413 ,
V_414 | V_415 ) ;
F_9 ( & V_2 -> V_48 ) ;
return 0 ;
}
static void F_93 ( struct V_416 * V_417 )
{
struct V_3 * V_418 = F_94 ( V_417 ,
struct V_3 ,
V_419 . V_417 ) ;
struct V_420 * V_420 = V_418 -> V_4 -> V_420 ;
struct V_421 * V_28 = V_418 -> V_4 -> V_28 ;
unsigned int V_52 ;
int V_63 ;
int V_422 ;
F_31 ( V_28 ) ;
V_63 = F_95 ( V_420 , V_423 , & V_52 ) ;
if ( V_63 < 0 ) {
F_60 ( V_28 , L_66 ,
V_63 ) ;
F_36 ( V_28 ) ;
return;
}
F_5 ( V_28 , L_67 , V_52 ) ;
V_422 = 0 ;
if ( V_52 & V_424 ) {
if ( V_418 -> V_101 [ 0 ] . V_406 )
V_422 = V_425 ;
}
if ( V_52 & V_426 ) {
if ( V_418 -> V_101 [ 0 ] . V_406 )
V_422 = V_427 ;
else
V_422 |= V_428 ;
}
if ( V_422 )
V_418 -> V_101 [ 0 ] . V_406 = false ;
else
V_418 -> V_101 [ 0 ] . V_406 = true ;
F_96 ( V_418 -> V_101 [ 0 ] . V_102 , V_422 ,
V_425 | V_428 ) ;
V_422 = 0 ;
if ( V_52 & V_429 ) {
if ( V_418 -> V_101 [ 1 ] . V_406 )
V_422 = V_425 ;
}
if ( V_52 & V_430 ) {
if ( V_418 -> V_101 [ 1 ] . V_406 )
V_422 = V_427 ;
else
V_422 |= V_428 ;
}
if ( V_422 )
V_418 -> V_101 [ 1 ] . V_406 = false ;
else
V_418 -> V_101 [ 1 ] . V_406 = true ;
F_96 ( V_418 -> V_101 [ 1 ] . V_102 , V_422 ,
V_425 | V_428 ) ;
F_36 ( V_28 ) ;
}
static T_3 F_97 ( int V_267 , void * V_268 )
{
struct V_3 * V_418 = V_268 ;
struct V_1 * V_2 = V_418 -> V_136 . V_2 ;
#ifndef F_98
F_99 ( F_100 ( V_2 -> V_28 ) ) ;
#endif
F_101 ( V_2 -> V_28 , 300 ) ;
F_28 ( & V_418 -> V_419 , F_29 ( 250 ) ) ;
return V_270 ;
}
static void F_102 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_21 )
return;
F_24 ( & V_4 -> V_109 ) ;
F_6 ( V_2 , V_29 , V_431 , 0 ) ;
F_22 ( V_2 , V_112 ) ;
F_25 ( & V_4 -> V_109 ) ;
if ( V_4 -> V_4 -> V_18 . V_432 )
F_72 ( & V_2 -> V_48 ,
L_68 ) ;
}
static void F_103 ( struct V_1 * V_2 , T_1 V_433 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_422 ;
V_422 = 0 ;
if ( V_433 & 0x4 )
V_422 |= V_428 ;
if ( V_433 & 0x8 )
V_422 |= V_434 ;
if ( V_433 & 0x10 )
V_422 |= V_435 ;
if ( V_433 & 0x20 )
V_422 |= V_436 ;
if ( V_433 & 0x40 )
V_422 |= V_437 ;
if ( V_433 & 0x80 )
V_422 |= V_438 ;
F_96 ( V_4 -> V_101 [ 0 ] . V_102 , V_422 ,
V_4 -> V_439 ) ;
}
static void F_104 ( struct V_416 * V_417 )
{
struct V_3 * V_4 = F_94 ( V_417 ,
struct V_3 ,
V_440 . V_417 ) ;
struct V_421 * V_28 = V_4 -> V_4 -> V_28 ;
F_102 ( V_4 -> V_136 . V_2 ) ;
F_24 ( & V_4 -> V_109 ) ;
F_5 ( V_28 , L_69 ) ;
V_4 -> V_14 = false ;
V_4 -> V_110 = true ;
F_1 ( V_4 -> V_136 . V_2 ) ;
F_96 ( V_4 -> V_101 [ 0 ] . V_102 , 0 ,
V_4 -> V_439 |
V_425 ) ;
F_25 ( & V_4 -> V_109 ) ;
}
static void F_105 ( void * V_268 , T_1 V_433 )
{
struct V_1 * V_2 = V_268 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! ( V_433 & V_441 ) ) {
F_5 ( V_2 -> V_28 , L_70 ) ;
F_28 ( & V_4 -> V_440 ,
F_29 ( 2500 ) ) ;
return;
}
if ( V_433 & 0x600 ) {
F_5 ( V_2 -> V_28 , L_71 ) ;
V_4 -> V_110 = false ;
V_4 -> V_14 = true ;
F_1 ( V_2 ) ;
F_96 ( V_4 -> V_101 [ 0 ] . V_102 , V_425 ,
V_425 ) ;
}
if ( V_433 & 0xfc ) {
F_5 ( V_2 -> V_28 , L_72 ) ;
V_4 -> V_110 = false ;
F_1 ( V_2 ) ;
F_102 ( V_2 ) ;
F_96 ( V_4 -> V_101 [ 0 ] . V_102 , V_427 ,
V_425 ) ;
}
}
static void F_106 ( struct V_416 * V_417 )
{
struct V_3 * V_4 = F_94 ( V_417 , struct V_3 ,
V_419 . V_417 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_1 * V_2 = V_4 -> V_136 . V_2 ;
F_31 ( V_2 -> V_28 ) ;
if ( V_5 -> V_18 . V_432 ) {
F_73 ( & V_2 -> V_48 ,
L_68 ) ;
F_9 ( & V_2 -> V_48 ) ;
}
F_24 ( & V_4 -> V_109 ) ;
F_5 ( V_2 -> V_28 , L_73 ) ;
if ( V_4 -> V_442 ) {
V_4 -> V_442 ( V_4 -> V_443 ) ;
} else {
V_4 -> V_110 = true ;
F_22 ( V_2 , V_111 ) ;
F_6 ( V_2 , V_29 ,
V_431 , V_431 ) ;
}
F_25 ( & V_4 -> V_109 ) ;
F_36 ( V_2 -> V_28 ) ;
}
static T_3 F_107 ( int V_267 , void * V_268 )
{
struct V_3 * V_4 = V_268 ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_1 * V_2 = V_4 -> V_136 . V_2 ;
int V_52 , V_444 ;
bool V_445 ;
F_31 ( V_2 -> V_28 ) ;
F_108 ( & V_4 -> V_446 ) ;
F_24 ( & V_4 -> V_109 ) ;
V_52 = F_3 ( V_2 , V_447 ) ;
if ( V_52 < 0 ) {
F_60 ( V_2 -> V_28 , L_74 , V_52 ) ;
F_25 ( & V_4 -> V_109 ) ;
F_36 ( V_2 -> V_28 ) ;
return V_448 ;
}
F_5 ( V_2 -> V_28 , L_75 , V_52 ) ;
V_445 = V_52 & V_449 ;
if ( V_445 ) {
F_5 ( V_2 -> V_28 , L_76 ) ;
F_1 ( V_2 ) ;
F_6 ( V_2 , V_289 ,
V_450 , 0 ) ;
F_6 ( V_2 , V_447 ,
V_451 , 0 ) ;
V_444 = V_5 -> V_18 . V_452 ;
F_28 ( & V_4 -> V_419 ,
F_29 ( V_444 ) ) ;
} else {
F_5 ( V_2 -> V_28 , L_77 ) ;
F_108 ( & V_4 -> V_419 ) ;
F_6 ( V_2 , V_289 ,
V_450 , V_450 ) ;
F_6 ( V_2 , V_447 ,
V_451 , V_451 ) ;
V_4 -> V_110 = false ;
V_4 -> V_14 = false ;
F_6 ( V_2 , V_29 ,
V_431 , 0 ) ;
F_22 ( V_2 , V_112 ) ;
}
F_25 ( & V_4 -> V_109 ) ;
if ( V_5 -> V_18 . V_432 && ! V_445 )
F_72 ( & V_2 -> V_48 , L_68 ) ;
if ( V_445 )
F_96 ( V_4 -> V_101 [ 0 ] . V_102 ,
V_453 , V_453 ) ;
else
F_96 ( V_4 -> V_101 [ 0 ] . V_102 , 0 ,
V_453 | V_425 |
V_4 -> V_439 ) ;
F_96 ( V_4 -> V_101 [ 0 ] . V_102 , 0 , 0 ) ;
F_36 ( V_2 -> V_28 ) ;
return V_270 ;
}
static void F_109 ( struct V_416 * V_417 )
{
struct V_3 * V_4 = F_94 ( V_417 ,
struct V_3 ,
V_118 . V_417 ) ;
F_107 ( 0 , V_4 ) ;
}
int F_110 ( struct V_1 * V_2 , struct V_404 * V_102 ,
T_4 V_454 , void * V_455 ,
T_5 V_456 , void * V_457 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
T_1 V_458 ;
switch ( V_5 -> type ) {
case V_286 :
case V_158 :
break;
default:
return - V_42 ;
}
if ( V_102 ) {
F_73 ( & V_2 -> V_48 , L_78 ) ;
F_9 ( & V_2 -> V_48 ) ;
V_4 -> V_101 [ 0 ] . V_102 = V_102 ;
if ( V_454 ) {
V_4 -> V_442 = V_454 ;
V_4 -> V_443 = V_455 ;
} else {
V_4 -> V_110 = true ;
V_4 -> V_14 = false ;
}
if ( V_456 ) {
V_4 -> V_459 = V_456 ;
V_4 -> V_460 = V_457 ;
} else {
V_4 -> V_459 = F_105 ;
V_4 -> V_460 = V_2 ;
}
F_1 ( V_2 ) ;
if ( V_5 -> V_18 . V_458 )
V_458 = V_5 -> V_18 . V_458 ;
else
V_458 = 0x41 ;
V_4 -> V_439 = V_428 | V_434 |
V_435 | V_436 |
V_437 | V_438 ;
F_6 ( V_2 , V_461 ,
V_462 , V_458 ) ;
F_33 ( V_2 -> V_48 . V_291 > V_292 ) ;
if ( V_4 -> V_21 ) {
F_6 ( V_2 , V_447 ,
V_451 , 0 ) ;
F_6 ( V_2 , V_289 ,
V_450 ,
V_450 ) ;
F_6 ( V_2 , V_463 ,
V_464 , 0 ) ;
F_22 ( V_2 ,
V_112 ) ;
} else {
F_6 ( V_2 , V_29 ,
V_431 , V_431 ) ;
}
} else {
F_6 ( V_2 , V_29 ,
V_431 , 0 ) ;
F_22 ( V_2 , V_106 ) ;
F_72 ( & V_2 -> V_48 , L_78 ) ;
F_9 ( & V_2 -> V_48 ) ;
}
return 0 ;
}
static void F_111 ( struct V_416 * V_417 )
{
struct V_3 * V_4 = F_94 ( V_417 ,
struct V_3 ,
V_446 . V_417 ) ;
struct V_1 * V_2 = V_4 -> V_136 . V_2 ;
F_31 ( V_2 -> V_28 ) ;
F_24 ( & V_4 -> V_109 ) ;
V_4 -> V_459 ( V_4 -> V_460 , V_4 -> V_465 ) ;
F_25 ( & V_4 -> V_109 ) ;
F_36 ( V_2 -> V_28 ) ;
}
static T_3 F_112 ( int V_267 , void * V_268 )
{
struct V_3 * V_4 = V_268 ;
struct V_1 * V_2 = V_4 -> V_136 . V_2 ;
int V_52 , V_466 , V_63 , V_467 ;
if ( ! ( F_3 ( V_2 , V_29 ) & V_431 ) )
return V_270 ;
F_108 ( & V_4 -> V_446 ) ;
F_108 ( & V_4 -> V_440 ) ;
F_31 ( V_2 -> V_28 ) ;
V_466 = 10 ;
do {
V_52 = F_3 ( V_2 , V_468 ) ;
if ( V_52 < 0 ) {
F_60 ( V_2 -> V_28 ,
L_79 ,
V_52 ) ;
F_36 ( V_2 -> V_28 ) ;
return V_448 ;
}
if ( ! ( V_52 & V_469 ) ) {
F_5 ( V_2 -> V_28 , L_80 ) ;
goto V_40;
}
if ( ! ( V_52 & V_441 ) || ( V_52 & V_470 ) )
break;
F_34 ( 1 ) ;
} while ( V_466 -- );
if ( V_466 == 0 )
F_63 ( V_2 -> V_28 , L_81 ) ;
#ifndef F_98
F_99 ( F_100 ( V_2 -> V_28 ) ) ;
#endif
if ( V_4 -> V_21 ) {
V_63 = F_3 ( V_2 , V_447 ) ;
if ( V_63 < 0 ) {
F_60 ( V_2 -> V_28 , L_74 ,
V_63 ) ;
} else if ( ! ( V_63 & V_449 ) ) {
F_5 ( V_2 -> V_28 , L_82 ) ;
goto V_40;
}
} else if ( ! ( V_52 & V_441 ) ) {
F_96 ( V_4 -> V_101 [ 0 ] . V_102 , 0 ,
V_453 | V_425 |
V_4 -> V_439 ) ;
V_4 -> V_110 = true ;
goto V_40;
}
V_4 -> V_465 = V_52 ;
V_467 = V_4 -> V_4 -> V_18 . V_471 ;
if ( V_4 -> V_110 )
F_28 ( & V_4 -> V_446 ,
F_29 ( V_467 ) ) ;
else
F_103 ( V_2 , V_52 ) ;
V_40:
F_36 ( V_2 -> V_28 ) ;
return V_270 ;
}
static T_3 F_113 ( int V_267 , void * V_268 )
{
struct V_1 * V_2 = V_268 ;
F_60 ( V_2 -> V_28 , L_83 ) ;
return V_270 ;
}
static T_3 F_114 ( int V_267 , void * V_268 )
{
struct V_1 * V_2 = V_268 ;
F_60 ( V_2 -> V_28 , L_84 ) ;
return V_270 ;
}
static T_3 F_115 ( int V_267 , void * V_268 )
{
struct V_1 * V_2 = V_268 ;
F_116 ( V_2 -> V_28 , L_85 ) ;
return V_270 ;
}
static int F_117 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_118 ( V_2 -> V_28 -> V_472 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_473 * V_48 = & V_2 -> V_48 ;
unsigned int V_52 ;
int V_63 , V_7 ;
V_4 -> V_136 . V_2 = V_2 ;
V_2 -> V_474 = V_5 -> V_420 ;
F_119 ( V_2 , 16 , 16 , V_475 ) ;
F_120 ( & V_4 -> V_109 ) ;
F_121 ( & V_4 -> V_118 ,
F_109 ) ;
F_121 ( & V_4 -> V_440 ,
F_104 ) ;
switch ( V_5 -> type ) {
case V_157 :
F_121 ( & V_4 -> V_419 , F_93 ) ;
break;
case V_286 :
F_121 ( & V_4 -> V_419 , F_106 ) ;
break;
default:
break;
}
F_121 ( & V_4 -> V_446 , F_111 ) ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_257 ) ; V_7 ++ )
F_122 ( & V_4 -> V_257 [ V_7 ] ) ;
V_4 -> V_476 = V_5 -> V_18 . V_476 ;
F_123 ( V_2 -> V_28 ) ;
F_124 ( V_2 -> V_28 ) ;
V_2 -> V_48 . V_477 = 1 ;
switch ( V_5 -> type ) {
case V_157 :
if ( ! V_5 -> V_18 . V_388 ||
! V_5 -> V_18 . V_389 )
V_2 -> V_48 . V_477 = 0 ;
switch ( V_5 -> V_258 ) {
case 2 :
case 3 :
V_4 -> V_136 . V_478 = - 5 ;
V_4 -> V_136 . V_479 = - 5 ;
V_4 -> V_136 . V_480 = 1 ;
V_4 -> V_136 . V_481 = 1 ;
V_4 -> V_136 . V_482 = 1 ;
break;
default:
V_4 -> V_136 . V_481 = 2 ;
break;
}
break;
case V_158 :
V_4 -> V_136 . V_481 = 1 ;
V_4 -> V_136 . V_480 = 1 ;
switch ( V_5 -> V_258 ) {
case 0 :
break;
default:
V_4 -> V_235 = true ;
break;
}
break;
case V_286 :
V_4 -> V_136 . V_481 = 2 ;
V_4 -> V_136 . V_483 = 1 ;
V_4 -> V_136 . V_480 = 1 ;
V_4 -> V_136 . V_484 = true ;
V_4 -> V_235 = true ;
V_4 -> V_136 . V_478 = - 9 ;
V_4 -> V_136 . V_479 = - 7 ;
F_6 ( V_2 , V_485 ,
V_486 , V_486 ) ;
break;
default:
break;
}
F_125 ( V_4 -> V_4 , V_487 ,
F_113 , L_86 , V_2 ) ;
F_125 ( V_4 -> V_4 , V_488 ,
F_114 , L_87 , V_2 ) ;
F_125 ( V_4 -> V_4 , V_489 ,
F_115 , L_88 , V_2 ) ;
V_63 = F_125 ( V_4 -> V_4 , V_490 ,
V_491 , L_89 ,
& V_4 -> V_136 ) ;
if ( V_63 == 0 )
V_4 -> V_136 . V_492 = true ;
switch ( V_5 -> type ) {
case V_157 :
if ( V_4 -> V_476 ) {
V_63 = F_126 ( V_4 -> V_476 , NULL ,
F_97 ,
V_493 ,
L_90 ,
V_4 ) ;
if ( V_63 != 0 )
F_63 ( V_2 -> V_28 ,
L_91 ,
V_63 ) ;
}
V_63 = F_125 ( V_4 -> V_4 ,
V_494 ,
F_97 , L_92 ,
V_4 ) ;
if ( V_63 != 0 )
F_63 ( V_2 -> V_28 ,
L_93 ,
V_63 ) ;
V_63 = F_125 ( V_4 -> V_4 ,
V_495 ,
F_97 , L_94 ,
V_4 ) ;
if ( V_63 != 0 )
F_63 ( V_2 -> V_28 ,
L_95 ,
V_63 ) ;
V_63 = F_125 ( V_4 -> V_4 ,
V_496 ,
F_97 , L_96 ,
V_4 ) ;
if ( V_63 != 0 )
F_63 ( V_2 -> V_28 ,
L_97 ,
V_63 ) ;
break;
case V_158 :
case V_286 :
if ( V_4 -> V_476 ) {
V_63 = F_126 ( V_4 -> V_476 , NULL ,
F_112 ,
V_493 ,
L_98 ,
V_4 ) ;
if ( V_63 != 0 )
F_63 ( V_2 -> V_28 ,
L_99 ,
V_63 ) ;
} else {
F_125 ( V_4 -> V_4 , V_497 ,
F_112 , L_98 ,
V_4 ) ;
}
}
switch ( V_5 -> type ) {
case V_286 :
if ( V_5 -> V_498 > 1 || V_5 -> V_258 > 1 ) {
V_63 = F_125 ( V_4 -> V_4 ,
F_127 ( 6 ) ,
F_107 , L_100 ,
V_4 ) ;
if ( V_63 == 0 )
V_4 -> V_21 = true ;
}
break;
default:
break;
}
V_4 -> V_261 = true ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_257 ) ; V_7 ++ ) {
V_63 = F_125 ( V_4 -> V_4 ,
V_499 + V_7 ,
F_65 , L_101 ,
& V_4 -> V_257 [ V_7 ] ) ;
if ( V_63 != 0 )
V_4 -> V_261 = false ;
}
F_31 ( V_2 -> V_28 ) ;
V_63 = F_95 ( V_5 -> V_420 , V_500 , & V_52 ) ;
if ( V_63 < 0 ) {
F_60 ( V_2 -> V_28 , L_102 , V_63 ) ;
goto V_501;
}
if ( ( V_52 & V_502 ) != V_503 ) {
V_4 -> V_346 [ 0 ] = 1 ;
V_504 [ 0 ] . V_505 = 1 ;
} else {
V_4 -> V_346 [ 0 ] = 0 ;
}
V_63 = F_95 ( V_5 -> V_420 , V_506 , & V_52 ) ;
if ( V_63 < 0 ) {
F_60 ( V_2 -> V_28 , L_103 , V_63 ) ;
goto V_501;
}
if ( ( V_52 & V_502 ) != V_503 ) {
V_4 -> V_346 [ 1 ] = 1 ;
V_504 [ 1 ] . V_505 = 1 ;
} else {
V_4 -> V_346 [ 1 ] = 0 ;
}
F_36 ( V_2 -> V_28 ) ;
for ( V_7 = 0 ; V_7 < F_4 ( V_176 ) ; V_7 ++ )
F_6 ( V_2 , V_176 [ V_7 ] . V_52 ,
V_176 [ V_7 ] . V_62 ,
V_176 [ V_7 ] . V_62 ) ;
F_6 ( V_2 , V_507 ,
1 << V_508 ,
1 << V_508 ) ;
F_6 ( V_2 , V_509 ,
1 << V_510 ,
1 << V_510 ) ;
F_6 ( V_2 , V_511 ,
1 << V_512 ,
1 << V_512 ) ;
switch ( V_5 -> type ) {
case V_157 :
case V_158 :
F_6 ( V_2 , V_162 ,
V_513 , V_513 ) ;
break;
default:
break;
}
switch ( V_5 -> type ) {
case V_158 :
case V_286 :
F_6 ( V_2 , V_287 ,
V_288 , V_288 ) ;
F_6 ( V_2 , V_289 ,
V_290 , V_290 ) ;
break;
default:
break;
}
V_4 -> V_136 . V_514 = F_38 ;
F_54 ( V_2 ) ;
F_89 ( V_4 ) ;
F_128 ( V_2 ) ;
F_88 ( V_2 , V_515 ,
F_4 ( V_515 ) ) ;
F_129 ( V_48 , V_516 ,
F_4 ( V_516 ) ) ;
switch ( V_5 -> type ) {
case V_157 :
F_129 ( V_48 , V_517 ,
F_4 ( V_517 ) ) ;
if ( V_5 -> V_258 < 4 ) {
F_129 ( V_48 , V_518 ,
F_4 ( V_518 ) ) ;
F_129 ( V_48 , V_519 ,
F_4 ( V_519 ) ) ;
F_129 ( V_48 , V_520 ,
F_4 ( V_520 ) ) ;
} else {
F_129 ( V_48 , V_521 ,
F_4 ( V_521 ) ) ;
F_129 ( V_48 , V_522 ,
F_4 ( V_522 ) ) ;
F_129 ( V_48 , V_523 ,
F_4 ( V_523 ) ) ;
}
break;
case V_158 :
F_88 ( V_2 , V_524 ,
F_4 ( V_524 ) ) ;
F_129 ( V_48 , V_525 ,
F_4 ( V_525 ) ) ;
if ( V_5 -> V_258 < 1 ) {
F_129 ( V_48 , V_518 ,
F_4 ( V_518 ) ) ;
F_129 ( V_48 , V_519 ,
F_4 ( V_519 ) ) ;
F_129 ( V_48 , V_520 ,
F_4 ( V_520 ) ) ;
} else {
F_129 ( V_48 , V_521 ,
F_4 ( V_521 ) ) ;
F_129 ( V_48 , V_522 ,
F_4 ( V_522 ) ) ;
F_129 ( V_48 , V_523 ,
F_4 ( V_523 ) ) ;
}
break;
case V_286 :
F_88 ( V_2 , V_524 ,
F_4 ( V_524 ) ) ;
F_129 ( V_48 , V_525 ,
F_4 ( V_525 ) ) ;
F_129 ( V_48 , V_521 ,
F_4 ( V_521 ) ) ;
F_129 ( V_48 , V_522 ,
F_4 ( V_522 ) ) ;
F_129 ( V_48 , V_523 ,
F_4 ( V_523 ) ) ;
break;
}
F_130 ( V_2 , 0 , 0 ) ;
F_131 ( V_48 , V_526 , F_4 ( V_526 ) ) ;
switch ( V_5 -> type ) {
case V_157 :
F_131 ( V_48 , V_527 ,
F_4 ( V_527 ) ) ;
if ( V_5 -> V_258 < 4 ) {
F_131 ( V_48 , V_528 ,
F_4 ( V_528 ) ) ;
F_131 ( V_48 , V_529 ,
F_4 ( V_529 ) ) ;
} else {
F_131 ( V_48 , V_530 ,
F_4 ( V_530 ) ) ;
}
break;
case V_158 :
if ( V_5 -> V_258 < 1 ) {
F_131 ( V_48 , V_527 ,
F_4 ( V_527 ) ) ;
F_131 ( V_48 , V_528 ,
F_4 ( V_528 ) ) ;
F_131 ( V_48 , V_529 ,
F_4 ( V_529 ) ) ;
} else {
F_131 ( V_48 , V_530 ,
F_4 ( V_530 ) ) ;
F_131 ( V_48 , V_531 ,
F_4 ( V_531 ) ) ;
}
F_132 ( V_2 ) ;
break;
case V_286 :
F_131 ( V_48 , V_530 ,
F_4 ( V_530 ) ) ;
F_131 ( V_48 , V_531 ,
F_4 ( V_531 ) ) ;
break;
}
return 0 ;
V_501:
if ( V_4 -> V_21 )
F_133 ( V_4 -> V_4 , F_127 ( 6 ) , V_4 ) ;
F_133 ( V_4 -> V_4 , V_496 , V_4 ) ;
F_133 ( V_4 -> V_4 , V_495 , V_4 ) ;
F_133 ( V_4 -> V_4 , V_494 , V_4 ) ;
if ( V_4 -> V_476 )
F_134 ( V_4 -> V_476 , V_4 ) ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_257 ) ; V_7 ++ )
F_133 ( V_4 -> V_4 , V_499 + V_7 ,
& V_4 -> V_257 [ V_7 ] ) ;
F_133 ( V_4 -> V_4 , V_490 ,
& V_4 -> V_136 ) ;
F_133 ( V_4 -> V_4 , V_487 , V_2 ) ;
F_133 ( V_4 -> V_4 , V_489 , V_2 ) ;
F_133 ( V_4 -> V_4 , V_488 , V_2 ) ;
return V_63 ;
}
static int F_135 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_7 ;
F_69 ( V_2 , V_293 ) ;
F_136 ( V_2 -> V_28 ) ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_257 ) ; V_7 ++ )
F_133 ( V_4 -> V_4 , V_499 + V_7 ,
& V_4 -> V_257 [ V_7 ] ) ;
F_133 ( V_4 -> V_4 , V_490 ,
& V_4 -> V_136 ) ;
F_133 ( V_4 -> V_4 , V_487 , V_2 ) ;
F_133 ( V_4 -> V_4 , V_489 , V_2 ) ;
F_133 ( V_4 -> V_4 , V_488 , V_2 ) ;
if ( V_4 -> V_21 )
F_133 ( V_4 -> V_4 , F_127 ( 6 ) , V_4 ) ;
switch ( V_5 -> type ) {
case V_157 :
if ( V_4 -> V_476 )
F_134 ( V_4 -> V_476 , V_4 ) ;
F_133 ( V_4 -> V_4 , V_495 ,
V_4 ) ;
F_133 ( V_4 -> V_4 , V_494 ,
V_4 ) ;
F_133 ( V_4 -> V_4 , V_497 ,
V_4 ) ;
break;
case V_286 :
case V_158 :
if ( V_4 -> V_476 )
F_134 ( V_4 -> V_476 , V_4 ) ;
break;
}
F_137 ( V_4 -> V_532 ) ;
F_137 ( V_4 -> V_533 ) ;
F_137 ( V_4 -> V_534 ) ;
F_138 ( V_4 -> V_96 ) ;
return 0 ;
}
static int F_139 ( struct V_535 * V_536 )
{
struct V_3 * V_4 ;
V_4 = F_91 ( & V_536 -> V_28 , sizeof( struct V_3 ) ,
V_386 ) ;
if ( V_4 == NULL )
return - V_537 ;
F_140 ( V_536 , V_4 ) ;
V_4 -> V_4 = F_118 ( V_536 -> V_28 . V_472 ) ;
return F_141 ( & V_536 -> V_28 , & V_538 ,
V_504 , F_4 ( V_504 ) ) ;
}
static int F_142 ( struct V_535 * V_536 )
{
F_143 ( & V_536 -> V_28 ) ;
return 0 ;
}
static int F_144 ( struct V_421 * V_28 )
{
struct V_3 * V_4 = F_118 ( V_28 ) ;
if ( V_4 -> V_21 && ! V_4 -> V_103 )
F_145 ( V_4 -> V_4 -> V_420 , V_107 ,
V_108 ,
V_4 -> V_105 ) ;
return 0 ;
}
static int F_146 ( struct V_421 * V_28 )
{
struct V_3 * V_4 = F_118 ( V_28 ) ;
if ( V_4 -> V_21 && V_4 -> V_105 )
F_145 ( V_4 -> V_4 -> V_420 , V_107 ,
V_108 ,
V_104 ) ;
return 0 ;
}
