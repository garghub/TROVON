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
struct V_4 * V_5 = V_2 -> V_153 ;
int V_62 = V_154 | V_155 ;
int V_7 ;
int V_156 ;
int V_157 ;
int V_9 ;
switch ( V_5 -> type ) {
case V_158 :
case V_159 :
V_62 |= V_160 | V_161 ;
break;
default:
break;
}
switch ( V_114 ) {
case V_115 :
if ( V_4 -> V_162 [ 0 ] <= 2 )
V_62 &= ~ ( V_160 | V_161 ) ;
V_9 = F_3 ( V_2 , V_163 ) ;
if ( ( V_9 & V_164 ) &&
( V_9 & V_165 ) )
V_157 = V_166 | V_167 ;
else if ( ! ( V_9 & V_164 ) &&
! ( V_9 & V_165 ) )
V_157 = V_168 | V_169 ;
else
V_157 = V_166 | V_167 |
V_168 | V_169 ;
V_9 = F_3 ( V_2 , V_170 ) ;
if ( ( V_9 & V_171 ) &&
( V_9 & V_172 ) )
V_156 = V_155 | V_161 ;
else if ( ! ( V_9 & V_171 ) &&
! ( V_9 & V_172 ) )
V_156 = V_154 | V_160 ;
else
V_156 = V_155 | V_161 |
V_154 | V_160 ;
F_6 ( V_2 , V_173 ,
V_62 , V_157 ) ;
F_6 ( V_2 , V_174 ,
V_62 , V_156 ) ;
F_6 ( V_2 , V_15 ,
V_175 |
V_176 ,
V_175 |
V_176 ) ;
F_6 ( V_2 , V_173 , V_62 ,
V_166 |
V_168 |
V_167 |
V_169 ) ;
F_6 ( V_2 , V_174 , V_62 ,
V_155 |
V_154 |
V_161 |
V_160 ) ;
break;
case V_116 :
for ( V_7 = 0 ; V_7 < F_4 ( V_177 ) ; V_7 ++ )
F_41 ( V_2 , V_177 [ V_7 ] . V_52 ,
F_3 ( V_2 ,
V_177 [ V_7 ] . V_52 ) ) ;
break;
case V_178 :
case V_119 :
F_6 ( V_2 , V_174 ,
V_62 , 0 ) ;
F_6 ( V_2 , V_173 ,
V_62 , 0 ) ;
V_9 = F_3 ( V_2 , V_15 ) ;
if ( V_9 & V_179 )
V_9 = V_176 ;
else
V_9 = 0 ;
F_6 ( V_2 , V_15 ,
V_176 |
V_175 , V_9 ) ;
break;
}
return 0 ;
}
static int F_42 ( struct V_49 * V_113 ,
struct V_55 * V_56 , int V_114 )
{
struct V_1 * V_2 = V_113 -> V_2 ;
int V_7 ;
int V_156 ;
int V_157 ;
int V_9 ;
switch ( V_114 ) {
case V_115 :
V_9 = F_3 ( V_2 , V_180 ) ;
if ( ( V_9 & V_181 ) &&
( V_9 & V_182 ) )
V_157 = V_183 ;
else if ( ! ( V_9 & V_181 ) &&
! ( V_9 & V_182 ) )
V_157 = V_184 ;
else
V_157 = V_184 | V_183 ;
V_9 = F_3 ( V_2 , V_185 ) ;
if ( ( V_9 & V_186 ) &&
( V_9 & V_187 ) )
V_156 = V_188 ;
else if ( ! ( V_9 & V_186 ) &&
! ( V_9 & V_187 ) )
V_156 = V_189 ;
else
V_156 = V_189 | V_188 ;
F_6 ( V_2 , V_173 ,
V_184 |
V_183 , V_157 ) ;
F_6 ( V_2 , V_174 ,
V_189 |
V_188 , V_156 ) ;
F_6 ( V_2 , V_15 ,
V_179 |
V_176 ,
V_179 |
V_176 ) ;
F_6 ( V_2 , V_173 ,
V_184 |
V_183 ,
V_184 |
V_183 ) ;
F_6 ( V_2 , V_174 ,
V_189 |
V_188 ,
V_189 |
V_188 ) ;
break;
case V_116 :
for ( V_7 = 0 ; V_7 < F_4 ( V_177 ) ; V_7 ++ )
F_41 ( V_2 , V_177 [ V_7 ] . V_52 ,
F_3 ( V_2 ,
V_177 [ V_7 ] . V_52 ) ) ;
break;
case V_178 :
case V_119 :
F_6 ( V_2 , V_174 ,
V_189 |
V_188 , 0 ) ;
F_6 ( V_2 , V_173 ,
V_184 |
V_183 , 0 ) ;
V_9 = F_3 ( V_2 , V_15 ) ;
if ( V_9 & V_175 )
V_9 = V_176 ;
else
V_9 = 0 ;
F_6 ( V_2 , V_15 ,
V_176 |
V_179 , V_9 ) ;
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
V_4 -> V_190 = 1 ;
break;
case V_119 :
V_4 -> V_191 = 1 ;
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
V_4 -> V_192 = 1 ;
break;
case V_119 :
V_4 -> V_193 = 1 ;
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
if ( V_4 -> V_190 ) {
F_40 ( V_113 , V_56 , V_115 ) ;
F_6 ( V_2 , V_44 ,
V_194 ,
V_195 ) ;
F_40 ( V_113 , V_56 , V_116 ) ;
V_4 -> V_190 = 0 ;
}
if ( V_4 -> V_192 ) {
F_42 ( V_113 , V_56 , V_115 ) ;
F_6 ( V_2 , V_196 ,
V_197 ,
V_198 ) ;
F_42 ( V_113 , V_56 , V_116 ) ;
V_4 -> V_192 = 0 ;
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
if ( V_4 -> V_191 ) {
F_40 ( V_113 , V_56 , V_178 ) ;
F_6 ( V_2 , V_44 ,
V_194 , 0 ) ;
F_40 ( V_113 , V_56 , V_119 ) ;
V_4 -> V_191 = 0 ;
}
if ( V_4 -> V_193 ) {
F_42 ( V_113 , V_56 , V_178 ) ;
F_6 ( V_2 , V_196 ,
V_197 , 0 ) ;
F_42 ( V_113 , V_56 , V_119 ) ;
V_4 -> V_193 = 0 ;
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
F_6 ( V_2 , V_174 ,
V_62 , V_62 ) ;
return 0 ;
}
static int F_51 ( struct V_49 * V_113 ,
struct V_55 * V_56 , int V_114 )
{
struct V_1 * V_2 = V_113 -> V_2 ;
F_5 ( V_2 -> V_28 , L_24 ,
F_3 ( V_2 ,
V_199 ) ) ;
return 0 ;
}
static int F_52 ( struct V_55 * V_56 ,
struct V_57 * V_58 )
{
struct V_200 * V_201 = F_12 ( V_56 ) ;
struct V_49 * V_113 = V_201 -> V_202 [ 0 ] ;
struct V_1 * V_2 = V_113 -> V_2 ;
int V_63 ;
V_63 = F_53 ( V_56 , V_58 ) ;
F_54 ( V_2 ) ;
return V_63 ;
}
static int F_55 ( struct V_203 * V_39 ,
int V_204 , int V_205 )
{
T_2 V_206 ;
unsigned int V_207 , V_208 , V_209 ;
F_56 ( L_25 , V_204 , V_205 ) ;
V_39 -> V_210 = 0 ;
while ( V_204 > 13500000 ) {
V_39 -> V_210 ++ ;
V_204 /= 2 ;
if ( V_39 -> V_210 > 3 )
return - V_42 ;
}
F_56 ( L_26 , V_39 -> V_210 , V_204 ) ;
V_39 -> V_211 = 3 ;
while ( V_205 * ( V_39 -> V_211 + 1 ) < 90000000 ) {
V_39 -> V_211 ++ ;
if ( V_39 -> V_211 > 63 )
return - V_42 ;
}
V_205 *= V_39 -> V_211 + 1 ;
F_56 ( L_27 , V_39 -> V_211 , V_205 ) ;
if ( V_204 > 1000000 ) {
V_39 -> V_212 = 0 ;
} else if ( V_204 > 256000 ) {
V_39 -> V_212 = 1 ;
V_204 *= 2 ;
} else if ( V_204 > 128000 ) {
V_39 -> V_212 = 2 ;
V_204 *= 4 ;
} else if ( V_204 > 64000 ) {
V_39 -> V_212 = 3 ;
V_204 *= 8 ;
} else {
V_39 -> V_212 = 4 ;
V_204 *= 16 ;
}
F_56 ( L_28 , V_39 -> V_212 , V_204 ) ;
V_208 = V_205 / V_204 ;
V_39 -> V_213 = V_208 ;
V_209 = V_205 % V_204 ;
F_56 ( L_29 , V_209 ) ;
V_206 = V_214 * ( long long ) V_209 ;
F_57 ( V_206 , V_204 ) ;
V_207 = V_206 & 0xFFFFFFFF ;
if ( ( V_207 % 10 ) >= 5 )
V_207 += 5 ;
V_39 -> V_215 = V_207 / 10 ;
F_56 ( L_30 , V_39 -> V_213 , V_39 -> V_215 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , int V_82 , int V_216 ,
unsigned int V_204 , unsigned int V_205 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_217 , V_63 ;
struct V_203 V_39 ;
T_1 V_52 , V_218 , V_219 , V_220 ;
unsigned long V_221 ;
bool V_222 ;
switch ( V_82 ) {
case V_223 :
V_217 = 0 ;
V_82 = 0 ;
V_220 = 0x10 ;
break;
case V_224 :
V_217 = 0x20 ;
V_82 = 1 ;
V_220 = 0x18 ;
break;
default:
return - V_42 ;
}
V_52 = F_3 ( V_2 , V_225 + V_217 ) ;
V_222 = V_52 & V_226 ;
switch ( V_216 ) {
case 0 :
if ( V_205 )
return - V_42 ;
V_216 = V_4 -> V_39 [ V_82 ] . V_216 ;
break;
case V_227 :
case V_228 :
case V_229 :
case V_230 :
break;
case V_231 :
V_204 = 12000000 ;
V_205 = 12000000 ;
break;
default:
return - V_42 ;
}
if ( V_4 -> V_39 [ V_82 ] . V_216 == V_216 &&
V_4 -> V_39 [ V_82 ] . V_232 == V_204 && V_4 -> V_39 [ V_82 ] . V_40 == V_205 )
return 0 ;
if ( V_205 )
V_63 = F_55 ( & V_39 , V_204 , V_205 ) ;
else
V_63 = F_55 ( & V_39 , V_4 -> V_39 [ V_82 ] . V_232 ,
V_4 -> V_39 [ V_82 ] . V_40 ) ;
if ( V_63 < 0 )
return V_63 ;
V_218 = F_3 ( V_2 , V_15 ) ;
if ( V_218 & V_16 )
V_219 = V_196 ;
else
V_219 = V_44 ;
V_52 = F_3 ( V_2 , V_219 ) ;
if ( ( V_52 & V_195 ) &&
( V_52 & V_45 ) == V_220 ) {
F_59 ( V_2 -> V_28 , L_31 ,
V_82 + 1 ) ;
return - V_233 ;
}
F_6 ( V_2 , V_225 + V_217 ,
V_226 , 0 ) ;
if ( V_4 -> V_234 && V_216 == V_230 &&
V_204 == V_205 && V_205 ) {
F_5 ( V_2 -> V_28 , L_32 , V_82 + 1 ) ;
F_6 ( V_2 , V_235 + V_217 ,
V_236 , V_236 ) ;
goto V_40;
}
V_52 = ( V_39 . V_211 << V_237 ) |
( V_39 . V_212 << V_238 ) ;
F_6 ( V_2 , V_239 + V_217 ,
V_240 |
V_241 , V_52 ) ;
F_6 ( V_2 , V_242 + V_217 ,
V_243 , V_39 . V_215 ) ;
F_6 ( V_2 , V_244 + V_217 ,
V_245 ,
V_39 . V_213 << V_246 ) ;
F_6 ( V_2 , V_235 + V_217 ,
V_247 | V_236 |
V_248 |
V_249 ,
( ( V_216 == V_231 )
<< V_250 ) |
( V_39 . V_210 << V_251 ) |
( V_216 - 1 ) ) ;
F_60 ( & V_4 -> V_252 [ V_82 ] ) ;
if ( V_205 ) {
if ( ! V_222 ) {
F_23 ( V_2 ) ;
switch ( V_5 -> type ) {
case V_158 :
F_30 ( V_2 ) ;
break;
case V_159 :
if ( V_4 -> V_253 < 1 )
F_30 ( V_2 ) ;
break;
default:
break;
}
}
V_52 = V_226 ;
if ( V_39 . V_215 )
V_52 |= V_254 ;
if ( V_216 == V_231 )
V_52 |= V_255 ;
F_6 ( V_2 , V_225 + V_217 ,
V_226 | V_255 |
V_254 , V_52 ) ;
if ( V_4 -> V_256 ) {
V_221 = F_61 ( & V_4 -> V_252 [ V_82 ] ,
F_29 ( 10 ) ) ;
if ( V_221 == 0 )
F_62 ( V_2 -> V_28 ,
L_33 ) ;
} else {
F_34 ( 5 ) ;
}
} else {
if ( V_222 ) {
switch ( V_5 -> type ) {
case V_158 :
F_35 ( V_2 ) ;
break;
case V_159 :
if ( V_4 -> V_253 < 1 )
F_35 ( V_2 ) ;
break;
default:
break;
}
F_26 ( V_2 ) ;
}
}
V_40:
V_4 -> V_39 [ V_82 ] . V_232 = V_204 ;
V_4 -> V_39 [ V_82 ] . V_40 = V_205 ;
V_4 -> V_39 [ V_82 ] . V_216 = V_216 ;
F_8 ( V_2 ) ;
if ( F_63 ( V_4 -> V_17 [ 0 ] , V_4 -> V_17 [ 1 ] ) < 50000 ) {
F_5 ( V_2 -> V_28 , L_34 ) ;
F_6 ( V_2 , V_257 ,
V_258 , 0x1 ) ;
F_6 ( V_2 , V_259 ,
V_260 , 0x1 ) ;
}
return 0 ;
}
static T_3 F_64 ( int V_261 , void * V_262 )
{
struct V_263 * V_263 = V_262 ;
F_65 ( V_263 ) ;
return V_264 ;
}
static int F_66 ( struct V_265 * V_266 , int V_82 , int V_216 ,
unsigned int V_204 , unsigned int V_205 )
{
return F_58 ( V_266 -> V_2 , V_82 , V_216 , V_204 , V_205 ) ;
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
F_6 ( V_2 , V_257 ,
V_258 , 0x1 ) ;
F_6 ( V_2 , V_259 ,
V_260 , 0x1 ) ;
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
case V_159 :
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
case V_159 :
if ( V_4 -> V_253 == 0 ) {
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
case V_159 :
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
V_293 = V_163 ;
break;
case 2 :
V_292 = V_297 ;
V_293 = V_180 ;
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
case V_159 :
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
V_293 = V_163 ;
V_322 = V_170 ;
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
V_293 = V_180 ;
V_322 = V_185 ;
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
V_4 -> V_162 [ V_82 ] = F_77 ( V_321 ) ;
switch ( F_77 ( V_321 ) ) {
case 1 :
case 2 :
V_331 *= 2 ;
break;
default:
V_331 *= 4 ;
break;
}
for ( V_7 = 0 ; V_7 < F_4 ( V_345 ) ; V_7 ++ )
if ( V_345 [ V_7 ] . V_26 == F_75 ( V_321 ) )
break;
if ( V_7 == F_4 ( V_345 ) )
return - V_42 ;
V_329 |= V_345 [ V_7 ] . V_9 << V_346 ;
F_5 ( V_266 -> V_28 , L_45 , V_345 [ V_7 ] . V_26 ) ;
F_5 ( V_266 -> V_28 , L_46 ,
V_266 -> V_82 , V_4 -> V_17 [ V_82 ] , V_331 ) ;
if ( F_77 ( V_321 ) == 1 &&
( F_3 ( V_2 , V_293 ) & 0x18 ) == 0x18 )
V_326 |= V_347 ;
if ( V_4 -> V_17 [ V_82 ] == 0 ) {
F_59 ( V_266 -> V_28 , L_47 , V_266 -> V_82 ) ;
return - V_42 ;
}
V_6 = 0 ;
V_90 = abs ( ( V_348 [ 0 ] * F_75 ( V_321 ) )
- V_4 -> V_17 [ V_82 ] ) ;
for ( V_7 = 1 ; V_7 < F_4 ( V_348 ) ; V_7 ++ ) {
V_330 = abs ( ( V_348 [ V_7 ] * F_75 ( V_321 ) )
- V_4 -> V_17 [ V_82 ] ) ;
if ( V_330 >= V_90 )
continue;
V_6 = V_7 ;
V_90 = V_330 ;
}
F_5 ( V_266 -> V_28 , L_48 ,
V_266 -> V_82 , V_348 [ V_6 ] ) ;
V_329 |= V_6 ;
V_6 = 0 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_349 ) ; V_7 ++ ) {
V_330 = ( V_4 -> V_17 [ V_82 ] * 10 / V_349 [ V_7 ] ) - V_331 ;
if ( V_330 < 0 )
break;
V_6 = V_7 ;
}
V_331 = V_4 -> V_17 [ V_82 ] * 10 / V_349 [ V_6 ] ;
F_5 ( V_266 -> V_28 , L_49 ,
V_349 [ V_6 ] , V_331 ) ;
V_327 |= V_6 << V_350 ;
V_328 = V_331 / F_75 ( V_321 ) ;
if ( ! V_328 ) {
F_59 ( V_266 -> V_28 , L_50 ,
V_331 ) ;
return - V_42 ;
}
F_5 ( V_266 -> V_28 , L_51 ,
V_328 , V_331 / V_328 ) ;
F_6 ( V_2 , V_293 , V_351 , V_295 ) ;
F_6 ( V_2 , V_322 , V_347 , V_326 ) ;
F_6 ( V_2 , V_323 , V_352 , V_327 ) ;
F_6 ( V_2 , V_324 , V_353 ,
V_328 ) ;
F_6 ( V_2 , V_325 , V_354 |
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
case V_159 :
V_293 = V_315 ;
break;
default:
return 0 ;
}
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
return F_6 ( V_2 , V_293 , V_351 , V_295 ) ;
}
static int F_79 ( struct V_265 * V_355 , int V_356 )
{
struct V_1 * V_2 = V_355 -> V_2 ;
int V_357 ;
int V_52 ;
switch ( V_355 -> V_82 ) {
case 1 :
V_357 = V_358 ;
break;
case 2 :
V_357 = V_359 ;
break;
default:
return - V_42 ;
}
if ( V_356 )
V_52 = V_360 ;
else
V_52 = 0 ;
F_6 ( V_2 , V_357 , V_360 , V_52 ) ;
return 0 ;
}
static int F_80 ( struct V_265 * V_355 , int V_361 )
{
struct V_1 * V_2 = V_355 -> V_2 ;
int V_52 , V_9 , V_62 ;
switch ( V_355 -> V_82 ) {
case 1 :
V_52 = V_296 ;
V_62 = V_362 ;
break;
case 2 :
V_52 = V_297 ;
V_62 = V_363 ;
break;
default:
return - V_42 ;
}
if ( V_361 )
V_9 = V_62 ;
else
V_9 = 0 ;
return F_6 ( V_2 , V_52 , V_62 , V_9 ) ;
}
static int F_81 ( struct V_265 * V_266 )
{
struct V_1 * V_2 = V_266 -> V_2 ;
F_6 ( V_2 , V_364 ,
V_365 | V_366 , 0 ) ;
F_6 ( V_2 , V_367 ,
V_365 | V_366 , 0 ) ;
F_6 ( V_2 , V_368 ,
V_365 | V_366 , 0 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 , V_63 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_39 ) ; V_7 ++ ) {
memcpy ( & V_4 -> V_369 [ V_7 ] , & V_4 -> V_39 [ V_7 ] ,
sizeof( struct V_370 ) ) ;
V_63 = F_58 ( V_2 , V_7 + 1 , 0 , 0 , 0 ) ;
if ( V_63 < 0 )
F_62 ( V_2 -> V_28 , L_52 ,
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
if ( V_4 -> V_253 < 4 ) {
V_63 = F_84 ( V_5 -> V_371 ,
V_174 , & V_9 ) ;
V_2 -> V_372 = 1 ;
V_62 = V_373 | V_374 |
V_375 | V_376 ;
V_9 &= V_62 ;
F_6 ( V_2 , V_174 ,
V_62 , V_9 ) ;
V_2 -> V_372 = 0 ;
}
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_39 ) ; V_7 ++ ) {
if ( ! V_4 -> V_369 [ V_7 ] . V_40 )
continue;
V_63 = F_58 ( V_2 , V_7 + 1 ,
V_4 -> V_369 [ V_7 ] . V_216 ,
V_4 -> V_369 [ V_7 ] . V_232 ,
V_4 -> V_369 [ V_7 ] . V_40 ) ;
if ( V_63 < 0 )
F_62 ( V_2 -> V_28 , L_53 ,
V_7 + 1 , V_63 ) ;
}
return 0 ;
}
static void F_85 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_136 . V_2 ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_70 * V_18 = & V_5 -> V_18 ;
struct V_377 V_378 [] = {
F_86 ( L_11 ,
V_4 -> V_379 ,
F_21 ,
F_20 ) ,
F_86 ( L_12 ,
V_4 -> V_379 ,
F_21 ,
F_20 ) ,
F_86 ( L_13 ,
V_4 -> V_379 ,
F_21 ,
F_20 ) ,
} ;
int V_63 , V_7 , V_380 ;
const char * * V_381 ;
V_4 -> V_91 = 0 ;
V_4 -> V_96 = NULL ;
for ( V_7 = 0 ; V_7 < V_18 -> V_94 ; V_7 ++ ) {
for ( V_380 = 0 ; V_380 < V_4 -> V_91 ; V_380 ++ ) {
if ( strcmp ( V_18 -> V_95 [ V_7 ] . V_54 ,
V_4 -> V_96 [ V_380 ] ) == 0 )
break;
}
if ( V_380 != V_4 -> V_91 )
continue;
V_381 = F_87 ( V_4 -> V_96 ,
sizeof( char * ) *
( V_4 -> V_91 + 1 ) ,
V_382 ) ;
if ( V_381 == NULL )
continue;
V_381 [ V_4 -> V_91 ] =
V_18 -> V_95 [ V_7 ] . V_54 ;
V_4 -> V_91 ++ ;
V_4 -> V_96 = V_381 ;
}
F_5 ( V_2 -> V_28 , L_54 ,
V_4 -> V_91 ) ;
V_4 -> V_379 . F_63 = V_4 -> V_91 ;
V_4 -> V_379 . V_383 = V_4 -> V_96 ;
V_63 = F_88 ( V_4 -> V_136 . V_2 , V_378 ,
F_4 ( V_378 ) ) ;
if ( V_63 != 0 )
F_59 ( V_4 -> V_136 . V_2 -> V_28 ,
L_55 , V_63 ) ;
}
static void F_89 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_136 . V_2 ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_70 * V_18 = & V_5 -> V_18 ;
int V_63 , V_7 ;
if ( ! V_18 )
return;
F_90 ( V_2 , V_18 -> V_384 ,
V_18 -> V_385 ,
V_18 -> V_386 ,
V_18 -> V_387 ,
V_18 -> V_388 ,
V_18 -> V_389 ,
V_18 -> V_390 ,
V_18 -> V_391 ,
V_18 -> V_392 ,
V_18 -> V_393 ) ;
F_5 ( V_2 -> V_28 , L_56 , V_18 -> V_84 ) ;
if ( V_18 -> V_84 ) {
struct V_377 V_378 [] = {
F_86 ( L_7 , V_4 -> V_394 ,
F_17 , F_16 ) ,
F_86 ( L_8 , V_4 -> V_394 ,
F_17 , F_16 ) ,
F_86 ( L_9 , V_4 -> V_394 ,
F_17 , F_16 ) ,
} ;
V_4 -> V_395 = F_91 ( V_4 -> V_136 . V_2 -> V_28 ,
sizeof( char * ) * V_18 -> V_84 , V_382 ) ;
if ( ! V_4 -> V_395 ) {
F_59 ( V_4 -> V_136 . V_2 -> V_28 ,
L_57 ,
V_18 -> V_84 ) ;
return;
}
for ( V_7 = 0 ; V_7 < V_18 -> V_84 ; V_7 ++ )
V_4 -> V_395 [ V_7 ] = V_18 -> V_80 [ V_7 ] . V_54 ;
V_4 -> V_394 . F_63 = V_18 -> V_84 ;
V_4 -> V_394 . V_383 = V_4 -> V_395 ;
V_63 = F_88 ( V_4 -> V_136 . V_2 , V_378 ,
F_4 ( V_378 ) ) ;
for ( V_7 = 0 ; V_7 < V_396 ; V_7 ++ )
F_14 ( V_2 , V_7 ) ;
} else {
V_63 = F_88 ( V_4 -> V_136 . V_2 ,
V_397 ,
F_4 ( V_397 ) ) ;
}
if ( V_63 != 0 )
F_59 ( V_4 -> V_136 . V_2 -> V_28 ,
L_58 , V_63 ) ;
F_5 ( V_2 -> V_28 , L_59 ,
V_18 -> V_94 ) ;
if ( V_18 -> V_94 )
F_85 ( V_4 ) ;
else
F_88 ( V_4 -> V_136 . V_2 , V_398 ,
F_4 ( V_398 ) ) ;
for ( V_7 = 0 ; V_7 < F_4 ( V_18 -> V_399 ) ; V_7 ++ ) {
if ( V_18 -> V_399 [ V_7 ] ) {
F_41 ( V_2 , V_281 + V_7 ,
V_18 -> V_399 [ V_7 ] & 0xffff ) ;
}
}
}
int F_92 ( struct V_1 * V_2 , struct V_400 * V_102 ,
int V_399 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_401 * V_101 ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_52 , V_63 ;
if ( V_5 -> type != V_158 ) {
F_62 ( V_2 -> V_28 , L_60 ) ;
return - V_42 ;
}
switch ( V_399 ) {
case 1 :
V_101 = & V_4 -> V_101 [ 0 ] ;
if ( V_102 )
V_63 = F_72 ( & V_2 -> V_48 ,
L_61 ) ;
else
V_63 = F_71 ( & V_2 -> V_48 ,
L_61 ) ;
break;
case 2 :
V_101 = & V_4 -> V_101 [ 1 ] ;
if ( V_102 )
V_63 = F_72 ( & V_2 -> V_48 ,
L_61 ) ;
else
V_63 = F_71 ( & V_2 -> V_48 ,
L_61 ) ;
break;
default:
F_62 ( V_2 -> V_28 , L_62 , V_399 ) ;
return - V_42 ;
}
if ( V_63 != 0 )
F_62 ( V_2 -> V_28 , L_63 ,
V_399 , V_63 ) ;
F_5 ( V_2 -> V_28 , L_64 ,
V_399 , V_102 ) ;
V_101 -> V_102 = V_102 ;
V_101 -> V_402 = true ;
if ( V_4 -> V_101 [ 0 ] . V_102 || V_4 -> V_101 [ 1 ] . V_102 )
V_52 = V_403 ;
else
V_52 = 0 ;
F_6 ( V_2 , V_404 , V_403 , V_52 ) ;
F_6 ( V_2 , V_405 ,
V_406 | V_407 |
V_408 | V_409 ,
V_410 | V_411 ) ;
F_9 ( & V_2 -> V_48 ) ;
return 0 ;
}
static void F_93 ( struct V_412 * V_413 )
{
struct V_3 * V_414 = F_94 ( V_413 ,
struct V_3 ,
V_415 . V_413 ) ;
struct V_371 * V_371 = V_414 -> V_4 -> V_371 ;
struct V_416 * V_28 = V_414 -> V_4 -> V_28 ;
unsigned int V_52 ;
int V_63 ;
int V_417 ;
F_31 ( V_28 ) ;
V_63 = F_84 ( V_371 , V_418 , & V_52 ) ;
if ( V_63 < 0 ) {
F_59 ( V_28 , L_65 ,
V_63 ) ;
F_36 ( V_28 ) ;
return;
}
F_5 ( V_28 , L_66 , V_52 ) ;
V_417 = 0 ;
if ( V_52 & V_419 ) {
if ( V_414 -> V_101 [ 0 ] . V_402 )
V_417 = V_420 ;
}
if ( V_52 & V_421 ) {
if ( V_414 -> V_101 [ 0 ] . V_402 )
V_417 = V_422 ;
else
V_417 |= V_423 ;
}
if ( V_417 )
V_414 -> V_101 [ 0 ] . V_402 = false ;
else
V_414 -> V_101 [ 0 ] . V_402 = true ;
F_95 ( V_414 -> V_101 [ 0 ] . V_102 , V_417 ,
V_420 | V_423 ) ;
V_417 = 0 ;
if ( V_52 & V_424 ) {
if ( V_414 -> V_101 [ 1 ] . V_402 )
V_417 = V_420 ;
}
if ( V_52 & V_425 ) {
if ( V_414 -> V_101 [ 1 ] . V_402 )
V_417 = V_422 ;
else
V_417 |= V_423 ;
}
if ( V_417 )
V_414 -> V_101 [ 1 ] . V_402 = false ;
else
V_414 -> V_101 [ 1 ] . V_402 = true ;
F_95 ( V_414 -> V_101 [ 1 ] . V_102 , V_417 ,
V_420 | V_423 ) ;
F_36 ( V_28 ) ;
}
static T_3 F_96 ( int V_261 , void * V_262 )
{
struct V_3 * V_414 = V_262 ;
struct V_1 * V_2 = V_414 -> V_136 . V_2 ;
#ifndef F_97
F_98 ( F_99 ( V_2 -> V_28 ) ) ;
#endif
F_100 ( V_2 -> V_28 , 300 ) ;
F_28 ( & V_414 -> V_415 , F_29 ( 250 ) ) ;
return V_264 ;
}
static void F_101 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_21 )
return;
F_24 ( & V_4 -> V_109 ) ;
F_6 ( V_2 , V_29 , V_426 , 0 ) ;
F_22 ( V_2 , V_112 ) ;
F_25 ( & V_4 -> V_109 ) ;
if ( V_4 -> V_4 -> V_18 . V_427 )
F_71 ( & V_2 -> V_48 ,
L_67 ) ;
}
static void F_102 ( struct V_1 * V_2 , T_1 V_428 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_417 ;
V_417 = 0 ;
if ( V_428 & 0x4 )
V_417 |= V_423 ;
if ( V_428 & 0x8 )
V_417 |= V_429 ;
if ( V_428 & 0x10 )
V_417 |= V_430 ;
if ( V_428 & 0x20 )
V_417 |= V_431 ;
if ( V_428 & 0x40 )
V_417 |= V_432 ;
if ( V_428 & 0x80 )
V_417 |= V_433 ;
F_95 ( V_4 -> V_101 [ 0 ] . V_102 , V_417 ,
V_4 -> V_434 ) ;
}
static void F_103 ( void * V_262 , T_1 V_428 )
{
struct V_1 * V_2 = V_262 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! ( V_428 & V_435 ) ) {
F_5 ( V_2 -> V_28 , L_68 ) ;
V_4 -> V_14 = false ;
V_4 -> V_110 = true ;
F_101 ( V_2 ) ;
F_1 ( V_2 ) ;
F_95 ( V_4 -> V_101 [ 0 ] . V_102 , 0 ,
V_4 -> V_434 |
V_420 ) ;
return;
}
if ( V_428 & 0x600 ) {
F_5 ( V_2 -> V_28 , L_69 ) ;
V_4 -> V_110 = false ;
V_4 -> V_14 = true ;
F_1 ( V_2 ) ;
F_95 ( V_4 -> V_101 [ 0 ] . V_102 , V_420 ,
V_420 ) ;
}
if ( V_428 & 0xfc ) {
F_5 ( V_2 -> V_28 , L_70 ) ;
V_4 -> V_110 = false ;
F_1 ( V_2 ) ;
F_101 ( V_2 ) ;
F_95 ( V_4 -> V_101 [ 0 ] . V_102 , V_422 ,
V_420 ) ;
}
}
static void F_104 ( struct V_412 * V_413 )
{
struct V_3 * V_4 = F_94 ( V_413 , struct V_3 ,
V_415 . V_413 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_1 * V_2 = V_4 -> V_136 . V_2 ;
F_31 ( V_2 -> V_28 ) ;
if ( V_5 -> V_18 . V_427 ) {
F_72 ( & V_2 -> V_48 ,
L_67 ) ;
F_9 ( & V_2 -> V_48 ) ;
}
F_24 ( & V_4 -> V_109 ) ;
F_5 ( V_2 -> V_28 , L_71 ) ;
if ( V_4 -> V_436 ) {
V_4 -> V_436 ( V_4 -> V_437 ) ;
} else {
V_4 -> V_110 = true ;
F_22 ( V_2 , V_111 ) ;
F_6 ( V_2 , V_29 ,
V_426 , V_426 ) ;
}
F_25 ( & V_4 -> V_109 ) ;
F_36 ( V_2 -> V_28 ) ;
}
static T_3 F_105 ( int V_261 , void * V_262 )
{
struct V_3 * V_4 = V_262 ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_1 * V_2 = V_4 -> V_136 . V_2 ;
int V_52 , V_438 ;
bool V_439 ;
F_31 ( V_2 -> V_28 ) ;
F_24 ( & V_4 -> V_109 ) ;
V_52 = F_3 ( V_2 , V_440 ) ;
if ( V_52 < 0 ) {
F_59 ( V_2 -> V_28 , L_72 , V_52 ) ;
F_25 ( & V_4 -> V_109 ) ;
F_36 ( V_2 -> V_28 ) ;
return V_441 ;
}
F_5 ( V_2 -> V_28 , L_73 , V_52 ) ;
V_439 = V_52 & V_442 ;
if ( V_439 ) {
F_5 ( V_2 -> V_28 , L_74 ) ;
F_1 ( V_2 ) ;
F_6 ( V_2 , V_283 ,
V_443 , 0 ) ;
F_6 ( V_2 , V_440 ,
V_444 , 0 ) ;
V_438 = V_5 -> V_18 . V_445 ;
F_28 ( & V_4 -> V_415 ,
F_29 ( V_438 ) ) ;
} else {
F_5 ( V_2 -> V_28 , L_75 ) ;
F_106 ( & V_4 -> V_415 ) ;
F_6 ( V_2 , V_283 ,
V_443 , V_443 ) ;
F_6 ( V_2 , V_440 ,
V_444 , V_444 ) ;
V_4 -> V_110 = false ;
V_4 -> V_14 = false ;
F_6 ( V_2 , V_29 ,
V_426 , 0 ) ;
F_22 ( V_2 , V_112 ) ;
}
F_25 ( & V_4 -> V_109 ) ;
if ( V_5 -> V_18 . V_427 && ! V_439 )
F_71 ( & V_2 -> V_48 , L_67 ) ;
if ( V_439 )
F_95 ( V_4 -> V_101 [ 0 ] . V_102 ,
V_446 , V_446 ) ;
else
F_95 ( V_4 -> V_101 [ 0 ] . V_102 , 0 ,
V_446 | V_420 |
V_4 -> V_434 ) ;
F_95 ( V_4 -> V_101 [ 0 ] . V_102 , 0 , 0 ) ;
F_36 ( V_2 -> V_28 ) ;
return V_264 ;
}
static void F_107 ( struct V_412 * V_413 )
{
struct V_3 * V_4 = F_94 ( V_413 ,
struct V_3 ,
V_118 . V_413 ) ;
F_105 ( 0 , V_4 ) ;
}
int F_108 ( struct V_1 * V_2 , struct V_400 * V_102 ,
T_4 V_447 , void * V_448 ,
T_5 V_449 , void * V_450 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
T_1 V_451 ;
switch ( V_5 -> type ) {
case V_280 :
case V_159 :
break;
default:
return - V_42 ;
}
if ( V_102 ) {
F_72 ( & V_2 -> V_48 , L_76 ) ;
F_9 ( & V_2 -> V_48 ) ;
V_4 -> V_101 [ 0 ] . V_102 = V_102 ;
if ( V_447 ) {
V_4 -> V_436 = V_447 ;
V_4 -> V_437 = V_448 ;
} else {
V_4 -> V_110 = true ;
V_4 -> V_14 = false ;
}
if ( V_449 ) {
V_4 -> V_452 = V_449 ;
V_4 -> V_453 = V_450 ;
} else {
V_4 -> V_452 = F_103 ;
V_4 -> V_453 = V_2 ;
}
F_1 ( V_2 ) ;
if ( V_5 -> V_18 . V_451 )
V_451 = V_5 -> V_18 . V_451 ;
else
V_451 = 0x41 ;
V_4 -> V_434 = V_423 | V_429 |
V_430 | V_431 |
V_432 | V_433 ;
F_6 ( V_2 , V_454 ,
V_455 , V_451 ) ;
F_33 ( V_2 -> V_48 . V_285 > V_286 ) ;
if ( V_4 -> V_21 ) {
F_6 ( V_2 , V_440 ,
V_444 , 0 ) ;
F_6 ( V_2 , V_283 ,
V_443 ,
V_443 ) ;
F_6 ( V_2 , V_456 ,
V_457 , 0 ) ;
F_22 ( V_2 ,
V_112 ) ;
} else {
F_6 ( V_2 , V_29 ,
V_426 , V_426 ) ;
}
} else {
F_6 ( V_2 , V_29 ,
V_426 , 0 ) ;
F_22 ( V_2 , V_106 ) ;
F_71 ( & V_2 -> V_48 , L_76 ) ;
F_9 ( & V_2 -> V_48 ) ;
}
return 0 ;
}
static T_3 F_109 ( int V_261 , void * V_262 )
{
struct V_3 * V_4 = V_262 ;
struct V_1 * V_2 = V_4 -> V_136 . V_2 ;
int V_52 , V_458 ;
if ( ! ( F_3 ( V_2 , V_29 ) & V_426 ) )
return V_264 ;
F_31 ( V_2 -> V_28 ) ;
V_458 = 10 ;
do {
V_52 = F_3 ( V_2 , V_459 ) ;
if ( V_52 < 0 ) {
F_59 ( V_2 -> V_28 ,
L_77 ,
V_52 ) ;
F_36 ( V_2 -> V_28 ) ;
return V_441 ;
}
if ( ! ( V_52 & V_460 ) ) {
F_5 ( V_2 -> V_28 , L_78 ) ;
goto V_40;
}
if ( ! ( V_52 & V_435 ) || ( V_52 & V_461 ) )
break;
F_34 ( 1 ) ;
} while ( V_458 -- );
if ( V_458 == 0 )
F_62 ( V_2 -> V_28 , L_79 ) ;
#ifndef F_97
F_98 ( F_99 ( V_2 -> V_28 ) ) ;
#endif
if ( V_4 -> V_21 ) {
V_52 = F_3 ( V_2 , V_440 ) ;
if ( V_52 < 0 ) {
F_59 ( V_2 -> V_28 , L_72 ,
V_52 ) ;
} else if ( ! ( V_52 & V_442 ) ) {
F_5 ( V_2 -> V_28 , L_80 ) ;
return V_264 ;
}
}
if ( V_4 -> V_110 )
V_4 -> V_452 ( V_4 -> V_453 , V_52 ) ;
else
F_102 ( V_2 , V_52 ) ;
V_40:
F_36 ( V_2 -> V_28 ) ;
return V_264 ;
}
static T_3 F_110 ( int V_261 , void * V_262 )
{
struct V_1 * V_2 = V_262 ;
F_59 ( V_2 -> V_28 , L_81 ) ;
return V_264 ;
}
static T_3 F_111 ( int V_261 , void * V_262 )
{
struct V_1 * V_2 = V_262 ;
F_59 ( V_2 -> V_28 , L_82 ) ;
return V_264 ;
}
static T_3 F_112 ( int V_261 , void * V_262 )
{
struct V_1 * V_2 = V_262 ;
F_113 ( V_2 -> V_28 , L_83 ) ;
return V_264 ;
}
static int F_114 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_115 ( V_2 -> V_28 -> V_462 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_463 * V_48 = & V_2 -> V_48 ;
unsigned int V_52 ;
int V_63 , V_7 ;
V_4 -> V_136 . V_2 = V_2 ;
V_2 -> V_153 = V_5 -> V_371 ;
F_116 ( V_2 , 16 , 16 , V_464 ) ;
F_117 ( & V_4 -> V_109 ) ;
F_118 ( & V_4 -> V_118 ,
F_107 ) ;
switch ( V_5 -> type ) {
case V_158 :
F_118 ( & V_4 -> V_415 , F_93 ) ;
break;
case V_280 :
F_118 ( & V_4 -> V_415 , F_104 ) ;
break;
default:
break;
}
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_252 ) ; V_7 ++ )
F_119 ( & V_4 -> V_252 [ V_7 ] ) ;
V_4 -> V_465 = V_5 -> V_18 . V_465 ;
F_120 ( V_2 -> V_28 ) ;
F_121 ( V_2 -> V_28 ) ;
V_2 -> V_48 . V_466 = 1 ;
V_4 -> V_253 = F_3 ( V_2 , V_467 ) ;
switch ( V_5 -> type ) {
case V_158 :
if ( ! V_5 -> V_18 . V_384 ||
! V_5 -> V_18 . V_385 )
V_2 -> V_48 . V_466 = 0 ;
switch ( V_4 -> V_253 ) {
case 2 :
case 3 :
V_4 -> V_136 . V_468 = - 5 ;
V_4 -> V_136 . V_469 = - 5 ;
V_4 -> V_136 . V_470 = 1 ;
V_4 -> V_136 . V_471 = 1 ;
V_4 -> V_136 . V_472 = 1 ;
break;
default:
V_4 -> V_136 . V_471 = 2 ;
break;
}
break;
case V_159 :
V_4 -> V_136 . V_471 = 1 ;
V_4 -> V_136 . V_470 = 1 ;
switch ( V_4 -> V_253 ) {
case 0 :
break;
default:
V_4 -> V_234 = true ;
break;
}
break;
case V_280 :
V_4 -> V_136 . V_471 = 2 ;
V_4 -> V_136 . V_473 = 1 ;
V_4 -> V_136 . V_470 = 1 ;
V_4 -> V_136 . V_474 = true ;
V_4 -> V_234 = true ;
V_4 -> V_136 . V_468 = - 9 ;
V_4 -> V_136 . V_469 = - 7 ;
F_6 ( V_2 , V_475 ,
V_476 , V_476 ) ;
break;
default:
break;
}
F_122 ( V_4 -> V_4 , V_477 ,
F_110 , L_84 , V_2 ) ;
F_122 ( V_4 -> V_4 , V_478 ,
F_111 , L_85 , V_2 ) ;
F_122 ( V_4 -> V_4 , V_479 ,
F_112 , L_86 , V_2 ) ;
V_63 = F_122 ( V_4 -> V_4 , V_480 ,
V_481 , L_87 ,
& V_4 -> V_136 ) ;
if ( V_63 == 0 )
V_4 -> V_136 . V_482 = true ;
switch ( V_5 -> type ) {
case V_158 :
if ( V_4 -> V_465 ) {
V_63 = F_123 ( V_4 -> V_465 , NULL ,
F_96 ,
V_483 ,
L_88 ,
V_4 ) ;
if ( V_63 != 0 )
F_62 ( V_2 -> V_28 ,
L_89 ,
V_63 ) ;
}
V_63 = F_122 ( V_4 -> V_4 ,
V_484 ,
F_96 , L_90 ,
V_4 ) ;
if ( V_63 != 0 )
F_62 ( V_2 -> V_28 ,
L_91 ,
V_63 ) ;
V_63 = F_122 ( V_4 -> V_4 ,
V_485 ,
F_96 , L_92 ,
V_4 ) ;
if ( V_63 != 0 )
F_62 ( V_2 -> V_28 ,
L_93 ,
V_63 ) ;
V_63 = F_122 ( V_4 -> V_4 ,
V_486 ,
F_96 , L_94 ,
V_4 ) ;
if ( V_63 != 0 )
F_62 ( V_2 -> V_28 ,
L_95 ,
V_63 ) ;
break;
case V_159 :
case V_280 :
if ( V_4 -> V_465 ) {
V_63 = F_123 ( V_4 -> V_465 , NULL ,
F_109 ,
V_483 ,
L_96 ,
V_4 ) ;
if ( V_63 != 0 )
F_62 ( V_2 -> V_28 ,
L_97 ,
V_63 ) ;
} else {
F_122 ( V_4 -> V_4 , V_487 ,
F_109 , L_96 ,
V_4 ) ;
}
}
switch ( V_5 -> type ) {
case V_280 :
if ( V_5 -> V_488 > 1 || V_4 -> V_253 > 1 ) {
V_63 = F_122 ( V_4 -> V_4 ,
F_124 ( 6 ) ,
F_105 , L_98 ,
V_4 ) ;
if ( V_63 == 0 )
V_4 -> V_21 = true ;
}
break;
default:
break;
}
V_4 -> V_256 = true ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_252 ) ; V_7 ++ ) {
V_63 = F_122 ( V_4 -> V_4 ,
V_489 + V_7 ,
F_64 , L_99 ,
& V_4 -> V_252 [ V_7 ] ) ;
if ( V_63 != 0 )
V_4 -> V_256 = false ;
}
F_31 ( V_2 -> V_28 ) ;
V_63 = F_84 ( V_5 -> V_371 , V_490 , & V_52 ) ;
if ( V_63 < 0 ) {
F_59 ( V_2 -> V_28 , L_100 , V_63 ) ;
goto V_491;
}
if ( ( V_52 & V_492 ) != V_493 ) {
V_4 -> V_335 [ 0 ] = 1 ;
V_494 [ 0 ] . V_495 = 1 ;
} else {
V_4 -> V_335 [ 0 ] = 0 ;
}
V_63 = F_84 ( V_5 -> V_371 , V_496 , & V_52 ) ;
if ( V_63 < 0 ) {
F_59 ( V_2 -> V_28 , L_101 , V_63 ) ;
goto V_491;
}
if ( ( V_52 & V_492 ) != V_493 ) {
V_4 -> V_335 [ 1 ] = 1 ;
V_494 [ 1 ] . V_495 = 1 ;
} else {
V_4 -> V_335 [ 1 ] = 0 ;
}
F_36 ( V_2 -> V_28 ) ;
for ( V_7 = 0 ; V_7 < F_4 ( V_177 ) ; V_7 ++ )
F_6 ( V_2 , V_177 [ V_7 ] . V_52 ,
V_177 [ V_7 ] . V_62 ,
V_177 [ V_7 ] . V_62 ) ;
F_6 ( V_2 , V_497 ,
1 << V_498 ,
1 << V_498 ) ;
F_6 ( V_2 , V_499 ,
1 << V_500 ,
1 << V_500 ) ;
F_6 ( V_2 , V_501 ,
1 << V_502 ,
1 << V_502 ) ;
switch ( V_5 -> type ) {
case V_158 :
case V_159 :
F_6 ( V_2 , V_163 ,
V_503 , V_503 ) ;
break;
default:
break;
}
switch ( V_5 -> type ) {
case V_159 :
case V_280 :
F_6 ( V_2 , V_281 ,
V_282 , V_282 ) ;
F_6 ( V_2 , V_283 ,
V_284 , V_284 ) ;
break;
default:
break;
}
V_4 -> V_136 . V_504 = F_38 ;
F_54 ( V_2 ) ;
F_89 ( V_4 ) ;
F_125 ( V_2 ) ;
F_88 ( V_2 , V_505 ,
F_4 ( V_505 ) ) ;
F_126 ( V_48 , V_506 ,
F_4 ( V_506 ) ) ;
switch ( V_5 -> type ) {
case V_158 :
F_126 ( V_48 , V_507 ,
F_4 ( V_507 ) ) ;
if ( V_4 -> V_253 < 4 ) {
F_126 ( V_48 , V_508 ,
F_4 ( V_508 ) ) ;
F_126 ( V_48 , V_509 ,
F_4 ( V_509 ) ) ;
F_126 ( V_48 , V_510 ,
F_4 ( V_510 ) ) ;
} else {
F_126 ( V_48 , V_511 ,
F_4 ( V_511 ) ) ;
F_126 ( V_48 , V_512 ,
F_4 ( V_512 ) ) ;
F_126 ( V_48 , V_513 ,
F_4 ( V_513 ) ) ;
}
break;
case V_159 :
F_88 ( V_2 , V_514 ,
F_4 ( V_514 ) ) ;
F_126 ( V_48 , V_515 ,
F_4 ( V_515 ) ) ;
if ( V_4 -> V_253 < 1 ) {
F_126 ( V_48 , V_508 ,
F_4 ( V_508 ) ) ;
F_126 ( V_48 , V_509 ,
F_4 ( V_509 ) ) ;
F_126 ( V_48 , V_510 ,
F_4 ( V_510 ) ) ;
} else {
F_126 ( V_48 , V_511 ,
F_4 ( V_511 ) ) ;
F_126 ( V_48 , V_512 ,
F_4 ( V_512 ) ) ;
F_126 ( V_48 , V_513 ,
F_4 ( V_513 ) ) ;
}
break;
case V_280 :
F_88 ( V_2 , V_514 ,
F_4 ( V_514 ) ) ;
F_126 ( V_48 , V_515 ,
F_4 ( V_515 ) ) ;
F_126 ( V_48 , V_511 ,
F_4 ( V_511 ) ) ;
F_126 ( V_48 , V_512 ,
F_4 ( V_512 ) ) ;
F_126 ( V_48 , V_513 ,
F_4 ( V_513 ) ) ;
break;
}
F_127 ( V_2 , 0 , 0 ) ;
F_128 ( V_48 , V_516 , F_4 ( V_516 ) ) ;
switch ( V_5 -> type ) {
case V_158 :
F_128 ( V_48 , V_517 ,
F_4 ( V_517 ) ) ;
if ( V_4 -> V_253 < 4 ) {
F_128 ( V_48 , V_518 ,
F_4 ( V_518 ) ) ;
F_128 ( V_48 , V_519 ,
F_4 ( V_519 ) ) ;
} else {
F_128 ( V_48 , V_520 ,
F_4 ( V_520 ) ) ;
}
break;
case V_159 :
if ( V_4 -> V_253 < 1 ) {
F_128 ( V_48 , V_517 ,
F_4 ( V_517 ) ) ;
F_128 ( V_48 , V_518 ,
F_4 ( V_518 ) ) ;
F_128 ( V_48 , V_519 ,
F_4 ( V_519 ) ) ;
} else {
F_128 ( V_48 , V_520 ,
F_4 ( V_520 ) ) ;
F_128 ( V_48 , V_521 ,
F_4 ( V_521 ) ) ;
}
F_129 ( V_2 ) ;
break;
case V_280 :
F_128 ( V_48 , V_520 ,
F_4 ( V_520 ) ) ;
F_128 ( V_48 , V_521 ,
F_4 ( V_521 ) ) ;
break;
}
return 0 ;
V_491:
if ( V_4 -> V_21 )
F_130 ( V_4 -> V_4 , F_124 ( 6 ) , V_4 ) ;
F_130 ( V_4 -> V_4 , V_486 , V_4 ) ;
F_130 ( V_4 -> V_4 , V_485 , V_4 ) ;
F_130 ( V_4 -> V_4 , V_484 , V_4 ) ;
if ( V_4 -> V_465 )
F_131 ( V_4 -> V_465 , V_4 ) ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_252 ) ; V_7 ++ )
F_130 ( V_4 -> V_4 , V_489 + V_7 ,
& V_4 -> V_252 [ V_7 ] ) ;
F_130 ( V_4 -> V_4 , V_480 ,
& V_4 -> V_136 ) ;
F_130 ( V_4 -> V_4 , V_477 , V_2 ) ;
F_130 ( V_4 -> V_4 , V_479 , V_2 ) ;
F_130 ( V_4 -> V_4 , V_478 , V_2 ) ;
return V_63 ;
}
static int F_132 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_7 ;
F_68 ( V_2 , V_287 ) ;
F_133 ( V_2 -> V_28 ) ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_252 ) ; V_7 ++ )
F_130 ( V_4 -> V_4 , V_489 + V_7 ,
& V_4 -> V_252 [ V_7 ] ) ;
F_130 ( V_4 -> V_4 , V_480 ,
& V_4 -> V_136 ) ;
F_130 ( V_4 -> V_4 , V_477 , V_2 ) ;
F_130 ( V_4 -> V_4 , V_479 , V_2 ) ;
F_130 ( V_4 -> V_4 , V_478 , V_2 ) ;
if ( V_4 -> V_21 )
F_130 ( V_4 -> V_4 , F_124 ( 6 ) , V_4 ) ;
switch ( V_5 -> type ) {
case V_158 :
if ( V_4 -> V_465 )
F_131 ( V_4 -> V_465 , V_4 ) ;
F_130 ( V_4 -> V_4 , V_485 ,
V_4 ) ;
F_130 ( V_4 -> V_4 , V_484 ,
V_4 ) ;
F_130 ( V_4 -> V_4 , V_487 ,
V_4 ) ;
break;
case V_280 :
case V_159 :
if ( V_4 -> V_465 )
F_131 ( V_4 -> V_465 , V_4 ) ;
break;
}
F_134 ( V_4 -> V_522 ) ;
F_134 ( V_4 -> V_523 ) ;
F_134 ( V_4 -> V_524 ) ;
F_135 ( V_4 -> V_96 ) ;
return 0 ;
}
static int F_136 ( struct V_525 * V_526 )
{
struct V_3 * V_4 ;
V_4 = F_91 ( & V_526 -> V_28 , sizeof( struct V_3 ) ,
V_382 ) ;
if ( V_4 == NULL )
return - V_527 ;
F_137 ( V_526 , V_4 ) ;
V_4 -> V_4 = F_115 ( V_526 -> V_28 . V_462 ) ;
return F_138 ( & V_526 -> V_28 , & V_528 ,
V_494 , F_4 ( V_494 ) ) ;
}
static int F_139 ( struct V_525 * V_526 )
{
F_140 ( & V_526 -> V_28 ) ;
return 0 ;
}
static int F_141 ( struct V_416 * V_28 )
{
struct V_3 * V_4 = F_115 ( V_28 ) ;
if ( V_4 -> V_21 && ! V_4 -> V_103 )
F_142 ( V_4 -> V_4 -> V_371 , V_107 ,
V_108 ,
V_4 -> V_105 ) ;
return 0 ;
}
static int F_143 ( struct V_416 * V_28 )
{
struct V_3 * V_4 = F_115 ( V_28 ) ;
if ( V_4 -> V_21 && V_4 -> V_105 )
F_142 ( V_4 -> V_4 -> V_371 , V_107 ,
V_108 ,
V_104 ) ;
return 0 ;
}
