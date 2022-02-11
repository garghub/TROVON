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
struct V_46 * V_47 = F_9 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_48 , V_49 ;
F_7 ( V_2 , 0 ) ;
F_7 ( V_2 , 1 ) ;
if ( V_4 -> V_17 [ 0 ] == V_4 -> V_17 [ 1 ] ) {
F_1 ( V_2 ) ;
return 0 ;
}
if ( V_4 -> V_17 [ 0 ] < V_4 -> V_17 [ 1 ] )
V_49 = V_16 ;
else
V_49 = 0 ;
V_48 = F_6 ( V_2 , V_15 ,
V_16 , V_49 ) ;
if ( V_48 )
F_10 ( V_47 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_11 ( struct V_50 * V_51 ,
struct V_50 * V_52 )
{
struct V_1 * V_2 = F_12 ( V_51 -> V_47 ) ;
int V_53 = F_3 ( V_2 , V_15 ) ;
const char * V_54 ;
if ( V_53 & V_16 )
V_54 = L_5 ;
else
V_54 = L_6 ;
return strcmp ( V_51 -> V_55 , V_54 ) == 0 ;
}
static int F_13 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_60 * V_61 =
(struct V_60 * ) V_57 -> V_62 ;
struct V_1 * V_2 = F_14 ( V_57 ) ;
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
return F_15 ( V_57 , V_59 ) ;
}
static void F_16 ( struct V_1 * V_2 , int V_70 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_71 * V_18 = & V_5 -> V_18 ;
int V_72 = V_73 [ V_70 ] ;
int V_74 = V_4 -> V_75 [ V_70 ] ;
int V_76 , V_7 ;
V_76 = F_3 ( V_2 , V_72 ) ;
V_76 &= V_77 | V_78 |
V_79 ;
for ( V_7 = 0 ; V_7 < V_80 ; V_7 ++ )
F_6 ( V_2 , V_72 + V_7 , 0xffff ,
V_18 -> V_81 [ V_74 ] . V_82 [ V_7 ] ) ;
F_6 ( V_2 , V_72 , V_77 |
V_78 |
V_79 , V_76 ) ;
}
static int F_17 ( const char * V_55 )
{
if ( strcmp ( V_55 , L_7 ) == 0 )
return 0 ;
if ( strcmp ( V_55 , L_8 ) == 0 )
return 1 ;
if ( strcmp ( V_55 , L_9 ) == 0 )
return 2 ;
return - V_42 ;
}
static int F_18 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_14 ( V_57 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_71 * V_18 = & V_5 -> V_18 ;
int V_70 = F_17 ( V_57 -> V_83 . V_55 ) ;
int V_84 = V_59 -> V_84 . integer . V_84 [ 0 ] ;
if ( V_70 < 0 )
return V_70 ;
if ( V_84 >= V_18 -> V_85 )
return - V_42 ;
V_4 -> V_75 [ V_70 ] = V_84 ;
F_16 ( V_2 , V_70 ) ;
return 0 ;
}
static int F_19 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_14 ( V_57 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_70 = F_17 ( V_57 -> V_83 . V_55 ) ;
if ( V_70 < 0 )
return V_70 ;
V_59 -> V_84 . V_86 . V_87 [ 0 ] = V_4 -> V_75 [ V_70 ] ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 , int V_88 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_71 * V_18 = & V_5 -> V_18 ;
int V_72 = V_89 [ V_88 ] ;
int V_90 , V_6 , V_91 , V_76 , V_7 , V_74 ;
if ( ! V_18 || ! V_4 -> V_92 )
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
V_6 = 0 ;
V_91 = V_94 ;
for ( V_7 = 0 ; V_7 < V_18 -> V_95 ; V_7 ++ ) {
if ( strcmp ( V_18 -> V_96 [ V_7 ] . V_55 ,
V_4 -> V_97 [ V_74 ] ) == 0 &&
abs ( V_18 -> V_96 [ V_7 ] . V_26
- V_4 -> V_98 [ V_90 ] ) < V_91 ) {
V_6 = V_7 ;
V_91 = abs ( V_18 -> V_96 [ V_7 ] . V_26
- V_4 -> V_98 [ V_90 ] ) ;
}
}
F_5 ( V_2 -> V_28 , L_10 ,
V_88 ,
V_18 -> V_96 [ V_6 ] . V_55 ,
V_18 -> V_96 [ V_6 ] . V_26 ,
V_4 -> V_98 [ V_90 ] ) ;
V_76 = F_3 ( V_2 , V_72 ) ;
V_76 &= V_99 ;
for ( V_7 = 0 ; V_7 < V_100 ; V_7 ++ )
F_6 ( V_2 , V_72 + V_7 , 0xffff ,
V_18 -> V_96 [ V_6 ] . V_82 [ V_7 ] ) ;
F_6 ( V_2 , V_72 , V_99 , V_76 ) ;
}
static int F_21 ( const char * V_55 )
{
if ( strcmp ( V_55 , L_11 ) == 0 )
return 0 ;
if ( strcmp ( V_55 , L_12 ) == 0 )
return 1 ;
if ( strcmp ( V_55 , L_13 ) == 0 )
return 2 ;
return - V_42 ;
}
static int F_22 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_14 ( V_57 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_71 * V_18 = & V_5 -> V_18 ;
int V_88 = F_21 ( V_57 -> V_83 . V_55 ) ;
int V_84 = V_59 -> V_84 . integer . V_84 [ 0 ] ;
if ( V_88 < 0 )
return V_88 ;
if ( V_84 >= V_18 -> V_95 )
return - V_42 ;
V_4 -> V_93 [ V_88 ] = V_84 ;
F_20 ( V_2 , V_88 ) ;
return 0 ;
}
static int F_23 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_14 ( V_57 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_88 = F_21 ( V_57 -> V_83 . V_55 ) ;
if ( V_88 < 0 )
return V_88 ;
V_59 -> V_84 . V_86 . V_87 [ 0 ] = V_4 -> V_93 [ V_88 ] ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 , T_1 V_101 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_21 || ! V_4 -> V_102 [ 0 ] . V_103 )
return;
if ( V_4 -> V_104 )
V_101 = V_105 ;
if ( V_101 == V_4 -> V_106 )
return;
V_4 -> V_106 = V_101 ;
if ( V_101 != V_107 )
V_101 = V_105 ;
F_6 ( V_2 , V_108 ,
V_109 , V_101 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_26 ( & V_4 -> V_110 ) ;
V_4 -> V_104 ++ ;
F_5 ( V_2 -> V_28 , L_14 ,
V_4 -> V_104 ) ;
F_24 ( V_2 , V_105 ) ;
F_27 ( & V_4 -> V_110 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_101 ;
F_26 ( & V_4 -> V_110 ) ;
V_4 -> V_104 -- ;
F_5 ( V_2 -> V_28 , L_15 ,
V_4 -> V_104 ) ;
if ( V_4 -> V_104 == 0 ) {
if ( V_4 -> V_14 || V_4 -> V_111 )
V_101 = V_112 ;
else
V_101 = V_113 ;
F_24 ( V_2 , V_101 ) ;
}
F_27 ( & V_4 -> V_110 ) ;
}
static int F_29 ( struct V_50 * V_114 ,
struct V_56 * V_57 , int V_115 )
{
struct V_1 * V_2 = F_12 ( V_114 -> V_47 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_115 ) {
case V_116 :
return F_8 ( V_2 ) ;
case V_117 :
if ( V_4 -> V_21 && ! V_4 -> V_118 ) {
F_30 ( V_119 ,
& V_4 -> V_120 ,
F_31 ( 1000 ) ) ;
V_4 -> V_118 = true ;
}
break;
case V_121 :
F_8 ( V_2 ) ;
break;
}
return 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_33 ( V_2 -> V_28 ) ;
V_4 -> V_122 ++ ;
F_5 ( V_2 -> V_28 , L_16 ,
V_4 -> V_122 ) ;
if ( V_4 -> V_122 == 1 ) {
F_6 ( V_2 , V_123 ,
V_124 |
V_125 , 0 ) ;
F_34 ( V_2 ) ;
switch ( V_4 -> V_126 ) {
default:
F_35 ( NULL == L_17 ) ;
case V_127 :
F_6 ( V_2 , V_108 ,
V_128 |
V_129 |
V_130 |
V_131 |
V_132 ,
V_128 |
V_130 |
V_131 |
( 0x2 << V_133 ) ) ;
F_6 ( V_2 , V_134 ,
V_135 |
V_136 ,
V_135 | 0x2 ) ;
F_36 ( 300 ) ;
F_6 ( V_2 , V_108 ,
V_132 |
V_128 ,
0 ) ;
break;
case V_137 :
F_6 ( V_2 , V_108 ,
V_128 |
V_129 |
V_130 |
V_131 |
V_132 ,
V_128 |
V_130 |
V_131 |
( 0x2 << V_133 ) ) ;
F_6 ( V_2 , V_134 ,
V_135 |
V_136 ,
V_135 | 0x2 ) ;
F_36 ( 400 ) ;
F_6 ( V_2 , V_108 ,
V_132 |
V_128 ,
0 ) ;
break;
}
}
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_122 -- ;
F_5 ( V_2 -> V_28 , L_18 ,
V_4 -> V_122 ) ;
if ( V_4 -> V_122 == 0 ) {
if ( V_4 -> V_138 . V_139 )
F_6 ( V_2 , V_140 ,
V_141 |
V_142 ,
V_141 |
V_142 ) ;
if ( V_4 -> V_138 . V_143 )
F_6 ( V_2 , V_140 ,
V_144 |
V_145 ,
V_144 |
V_145 ) ;
F_6 ( V_2 , V_108 ,
V_128 |
V_129 ,
V_128 |
V_129 ) ;
F_6 ( V_2 , V_134 ,
V_136 , 0 ) ;
F_36 ( 400 ) ;
F_6 ( V_2 , V_123 ,
V_124 |
V_125 ,
V_124 |
V_125 ) ;
F_6 ( V_2 , V_140 ,
V_141 |
V_142 |
V_144 |
V_145 , 0 ) ;
F_6 ( V_2 , V_108 ,
V_128 |
V_130 |
V_131 |
V_132 , 0 ) ;
F_6 ( V_2 , V_134 ,
V_136 , 0 ) ;
}
F_38 ( V_2 -> V_28 ) ;
}
static int F_39 ( struct V_50 * V_114 ,
struct V_56 * V_57 , int V_115 )
{
struct V_1 * V_2 = F_12 ( V_114 -> V_47 ) ;
switch ( V_115 ) {
case V_116 :
F_32 ( V_2 ) ;
break;
case V_121 :
F_37 ( V_2 ) ;
break;
}
return 0 ;
}
static bool F_40 ( struct V_1 * V_2 )
{
int V_51 = 0 ;
int V_53 , V_146 ;
V_53 = F_3 ( V_2 , V_147 ) ;
switch ( V_53 ) {
case V_148 :
F_41 ( V_2 -> V_28 , L_19 ) ;
V_51 = 2 << V_149 ;
break;
case V_150 :
F_41 ( V_2 -> V_28 , L_20 ) ;
V_51 = 1 << V_149 ;
break;
case V_151 :
F_41 ( V_2 -> V_28 , L_21 ) ;
V_51 = 0 << V_149 ;
break;
default:
F_41 ( V_2 -> V_28 , L_22 , V_53 ) ;
return false ;
}
V_146 = F_3 ( V_2 , V_152 ) ;
if ( V_146 != V_53 ) {
F_41 ( V_2 -> V_28 , L_23 ) ;
return false ;
}
F_6 ( V_2 , V_153 ,
V_154 , V_51 ) ;
return true ;
}
static int F_42 ( struct V_50 * V_114 ,
struct V_56 * V_57 , int V_115 )
{
struct V_1 * V_2 = F_12 ( V_114 -> V_47 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_63 = V_155 | V_156 ;
int V_7 ;
int V_157 ;
int V_158 ;
int V_9 ;
switch ( V_5 -> type ) {
case V_159 :
case V_160 :
V_63 |= V_161 | V_162 ;
break;
default:
break;
}
switch ( V_115 ) {
case V_116 :
if ( V_4 -> V_163 [ 0 ] <= 2 )
V_63 &= ~ ( V_161 | V_162 ) ;
V_9 = F_3 ( V_2 , V_164 ) ;
if ( ( V_9 & V_165 ) &&
( V_9 & V_166 ) )
V_158 = V_167 | V_168 ;
else if ( ! ( V_9 & V_165 ) &&
! ( V_9 & V_166 ) )
V_158 = V_169 | V_170 ;
else
V_158 = V_167 | V_168 |
V_169 | V_170 ;
V_9 = F_3 ( V_2 , V_171 ) ;
if ( ( V_9 & V_172 ) &&
( V_9 & V_173 ) )
V_157 = V_156 | V_162 ;
else if ( ! ( V_9 & V_172 ) &&
! ( V_9 & V_173 ) )
V_157 = V_155 | V_161 ;
else
V_157 = V_156 | V_162 |
V_155 | V_161 ;
F_6 ( V_2 , V_174 ,
V_63 , V_158 ) ;
F_6 ( V_2 , V_175 ,
V_63 , V_157 ) ;
F_6 ( V_2 , V_15 ,
V_176 |
V_177 ,
V_176 |
V_177 ) ;
F_6 ( V_2 , V_174 , V_63 ,
V_167 |
V_169 |
V_168 |
V_170 ) ;
F_6 ( V_2 , V_175 , V_63 ,
V_156 |
V_155 |
V_162 |
V_161 ) ;
break;
case V_117 :
for ( V_7 = 0 ; V_7 < F_4 ( V_178 ) ; V_7 ++ )
F_43 ( V_2 , V_178 [ V_7 ] . V_53 ,
F_3 ( V_2 ,
V_178 [ V_7 ] . V_53 ) ) ;
break;
case V_179 :
case V_121 :
F_6 ( V_2 , V_175 ,
V_63 , 0 ) ;
F_6 ( V_2 , V_174 ,
V_63 , 0 ) ;
V_9 = F_3 ( V_2 , V_15 ) ;
if ( V_9 & V_180 )
V_9 = V_177 ;
else
V_9 = 0 ;
F_6 ( V_2 , V_15 ,
V_177 |
V_176 , V_9 ) ;
break;
}
return 0 ;
}
static int F_44 ( struct V_50 * V_114 ,
struct V_56 * V_57 , int V_115 )
{
struct V_1 * V_2 = F_12 ( V_114 -> V_47 ) ;
int V_7 ;
int V_157 ;
int V_158 ;
int V_9 ;
switch ( V_115 ) {
case V_116 :
V_9 = F_3 ( V_2 , V_181 ) ;
if ( ( V_9 & V_182 ) &&
( V_9 & V_183 ) )
V_158 = V_184 ;
else if ( ! ( V_9 & V_182 ) &&
! ( V_9 & V_183 ) )
V_158 = V_185 ;
else
V_158 = V_185 | V_184 ;
V_9 = F_3 ( V_2 , V_186 ) ;
if ( ( V_9 & V_187 ) &&
( V_9 & V_188 ) )
V_157 = V_189 ;
else if ( ! ( V_9 & V_187 ) &&
! ( V_9 & V_188 ) )
V_157 = V_190 ;
else
V_157 = V_190 | V_189 ;
F_6 ( V_2 , V_174 ,
V_185 |
V_184 , V_158 ) ;
F_6 ( V_2 , V_175 ,
V_190 |
V_189 , V_157 ) ;
F_6 ( V_2 , V_15 ,
V_180 |
V_177 ,
V_180 |
V_177 ) ;
F_6 ( V_2 , V_174 ,
V_185 |
V_184 ,
V_185 |
V_184 ) ;
F_6 ( V_2 , V_175 ,
V_190 |
V_189 ,
V_190 |
V_189 ) ;
break;
case V_117 :
for ( V_7 = 0 ; V_7 < F_4 ( V_178 ) ; V_7 ++ )
F_43 ( V_2 , V_178 [ V_7 ] . V_53 ,
F_3 ( V_2 ,
V_178 [ V_7 ] . V_53 ) ) ;
break;
case V_179 :
case V_121 :
F_6 ( V_2 , V_175 ,
V_190 |
V_189 , 0 ) ;
F_6 ( V_2 , V_174 ,
V_185 |
V_184 , 0 ) ;
V_9 = F_3 ( V_2 , V_15 ) ;
if ( V_9 & V_176 )
V_9 = V_177 ;
else
V_9 = 0 ;
F_6 ( V_2 , V_15 ,
V_177 |
V_180 , V_9 ) ;
break;
}
return 0 ;
}
static int F_45 ( struct V_50 * V_114 ,
struct V_56 * V_57 , int V_115 )
{
struct V_1 * V_2 = F_12 ( V_114 -> V_47 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_115 ) {
case V_116 :
V_4 -> V_191 = 1 ;
break;
case V_121 :
V_4 -> V_192 = 1 ;
break;
}
return 0 ;
}
static int F_46 ( struct V_50 * V_114 ,
struct V_56 * V_57 , int V_115 )
{
struct V_1 * V_2 = F_12 ( V_114 -> V_47 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_115 ) {
case V_116 :
V_4 -> V_193 = 1 ;
break;
case V_121 :
V_4 -> V_194 = 1 ;
break;
}
return 0 ;
}
static int F_47 ( struct V_50 * V_114 ,
struct V_56 * V_57 , int V_115 )
{
struct V_1 * V_2 = F_12 ( V_114 -> V_47 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_115 ) {
case V_116 :
if ( V_4 -> V_191 ) {
F_42 ( V_114 , V_57 , V_116 ) ;
F_6 ( V_2 , V_44 ,
V_195 ,
V_196 ) ;
F_42 ( V_114 , V_57 , V_117 ) ;
V_4 -> V_191 = 0 ;
}
if ( V_4 -> V_193 ) {
F_44 ( V_114 , V_57 , V_116 ) ;
F_6 ( V_2 , V_197 ,
V_198 ,
V_199 ) ;
F_44 ( V_114 , V_57 , V_117 ) ;
V_4 -> V_193 = 0 ;
}
break;
}
F_48 ( V_114 , V_57 , V_115 ) ;
return 0 ;
}
static int F_49 ( struct V_50 * V_114 ,
struct V_56 * V_57 , int V_115 )
{
struct V_1 * V_2 = F_12 ( V_114 -> V_47 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_115 ) {
case V_121 :
if ( V_4 -> V_192 ) {
F_42 ( V_114 , V_57 , V_179 ) ;
F_6 ( V_2 , V_44 ,
V_195 , 0 ) ;
F_42 ( V_114 , V_57 , V_121 ) ;
V_4 -> V_192 = 0 ;
}
if ( V_4 -> V_194 ) {
F_44 ( V_114 , V_57 , V_179 ) ;
F_6 ( V_2 , V_197 ,
V_198 , 0 ) ;
F_44 ( V_114 , V_57 , V_121 ) ;
V_4 -> V_194 = 0 ;
}
break;
}
return 0 ;
}
static int F_50 ( struct V_50 * V_114 ,
struct V_56 * V_57 , int V_115 )
{
F_47 ( V_114 , V_57 , V_115 ) ;
return 0 ;
}
static int F_51 ( struct V_50 * V_114 ,
struct V_56 * V_57 , int V_115 )
{
F_47 ( V_114 , V_57 , V_115 ) ;
return 0 ;
}
static int F_52 ( struct V_50 * V_114 ,
struct V_56 * V_57 , int V_115 )
{
struct V_1 * V_2 = F_12 ( V_114 -> V_47 ) ;
unsigned int V_63 = 1 << V_114 -> V_65 ;
F_6 ( V_2 , V_175 ,
V_63 , V_63 ) ;
return 0 ;
}
static int F_53 ( struct V_50 * V_114 ,
struct V_56 * V_57 , int V_115 )
{
struct V_1 * V_2 = F_12 ( V_114 -> V_47 ) ;
F_5 ( V_2 -> V_28 , L_24 ,
F_3 ( V_2 ,
V_200 ) ) ;
return 0 ;
}
static int F_54 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_55 ( V_57 ) ;
int V_64 ;
V_64 = F_56 ( V_57 , V_59 ) ;
F_57 ( V_2 ) ;
return V_64 ;
}
static int F_58 ( struct V_4 * V_5 , struct V_201 * V_39 ,
int V_202 , int V_203 )
{
T_2 V_204 ;
unsigned int V_205 , V_206 , V_207 , V_208 ;
F_59 ( L_25 , V_202 , V_203 ) ;
V_39 -> V_209 = 0 ;
while ( V_202 > 13500000 ) {
V_39 -> V_209 ++ ;
V_202 /= 2 ;
if ( V_39 -> V_209 > 3 )
return - V_42 ;
}
F_59 ( L_26 , V_39 -> V_209 , V_202 ) ;
V_39 -> V_210 = 3 ;
while ( V_203 * ( V_39 -> V_210 + 1 ) < 90000000 ) {
V_39 -> V_210 ++ ;
if ( V_39 -> V_210 > 63 )
return - V_42 ;
}
V_203 *= V_39 -> V_210 + 1 ;
F_59 ( L_27 , V_39 -> V_210 , V_203 ) ;
if ( V_202 > 1000000 ) {
V_39 -> V_211 = 0 ;
} else if ( V_202 > 256000 ) {
V_39 -> V_211 = 1 ;
V_202 *= 2 ;
} else if ( V_202 > 128000 ) {
V_39 -> V_211 = 2 ;
V_202 *= 4 ;
} else if ( V_202 > 64000 ) {
V_39 -> V_211 = 3 ;
V_202 *= 8 ;
} else {
V_39 -> V_211 = 4 ;
V_202 *= 16 ;
}
F_59 ( L_28 , V_39 -> V_211 , V_202 ) ;
V_206 = V_203 / V_202 ;
V_39 -> V_212 = V_206 ;
V_207 = V_203 % V_202 ;
F_59 ( L_29 , V_207 ) ;
switch ( V_5 -> type ) {
case V_159 :
V_204 = V_213 * ( long long ) V_207 ;
F_60 ( V_204 , V_202 ) ;
V_205 = V_204 & 0xFFFFFFFF ;
if ( ( V_205 % 10 ) >= 5 )
V_205 += 5 ;
V_39 -> V_214 = V_205 / 10 ;
V_39 -> V_215 = 0 ;
F_59 ( L_30 , V_39 -> V_212 , V_39 -> V_214 ) ;
break;
default:
V_208 = F_61 ( V_203 , V_202 ) ;
V_39 -> V_214 = ( V_203 - ( V_202 * V_39 -> V_212 ) ) / V_208 ;
V_39 -> V_215 = V_202 / V_208 ;
}
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , int V_83 , int V_216 ,
unsigned int V_202 , unsigned int V_203 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_217 , V_64 ;
struct V_201 V_39 ;
T_1 V_53 , V_218 , V_219 , V_220 ;
unsigned long V_221 ;
bool V_222 ;
switch ( V_83 ) {
case V_223 :
V_217 = 0 ;
V_83 = 0 ;
V_220 = 0x10 ;
break;
case V_224 :
V_217 = 0x20 ;
V_83 = 1 ;
V_220 = 0x18 ;
break;
default:
return - V_42 ;
}
V_53 = F_3 ( V_2 , V_225 + V_217 ) ;
V_222 = V_53 & V_226 ;
switch ( V_216 ) {
case 0 :
if ( V_203 )
return - V_42 ;
V_216 = V_4 -> V_39 [ V_83 ] . V_216 ;
break;
case V_227 :
case V_228 :
case V_229 :
case V_230 :
break;
case V_231 :
V_202 = 12000000 ;
V_203 = 12000000 ;
break;
default:
return - V_42 ;
}
if ( V_4 -> V_39 [ V_83 ] . V_216 == V_216 &&
V_4 -> V_39 [ V_83 ] . V_232 == V_202 && V_4 -> V_39 [ V_83 ] . V_40 == V_203 )
return 0 ;
if ( V_203 )
V_64 = F_58 ( V_5 , & V_39 , V_202 , V_203 ) ;
else
V_64 = F_58 ( V_5 , & V_39 , V_4 -> V_39 [ V_83 ] . V_232 ,
V_4 -> V_39 [ V_83 ] . V_40 ) ;
if ( V_64 < 0 )
return V_64 ;
V_218 = F_3 ( V_2 , V_15 ) ;
if ( V_218 & V_16 )
V_219 = V_197 ;
else
V_219 = V_44 ;
V_53 = F_3 ( V_2 , V_219 ) ;
if ( ( V_53 & V_196 ) &&
( V_53 & V_45 ) == V_220 ) {
F_63 ( V_2 -> V_28 , L_31 ,
V_83 + 1 ) ;
return - V_233 ;
}
F_6 ( V_2 , V_225 + V_217 ,
V_226 , 0 ) ;
if ( V_4 -> V_234 && V_216 == V_230 &&
V_202 == V_203 && V_203 ) {
F_5 ( V_2 -> V_28 , L_32 , V_83 + 1 ) ;
F_6 ( V_2 , V_235 + V_217 ,
V_236 , V_236 ) ;
goto V_40;
}
V_53 = ( V_39 . V_210 << V_237 ) |
( V_39 . V_211 << V_238 ) ;
F_6 ( V_2 , V_239 + V_217 ,
V_240 |
V_241 , V_53 ) ;
F_6 ( V_2 , V_242 + V_217 ,
V_243 , V_39 . V_214 ) ;
F_6 ( V_2 , V_244 + V_217 ,
V_245 ,
V_39 . V_212 << V_246 ) ;
if ( V_39 . V_215 ) {
F_6 ( V_2 , V_247 + V_217 ,
V_248 ,
V_39 . V_215 ) ;
F_6 ( V_2 , V_249 + V_217 ,
V_250 , V_250 ) ;
} else {
F_6 ( V_2 , V_249 + V_217 ,
V_250 , 0 ) ;
}
F_6 ( V_2 , V_235 + V_217 ,
V_251 | V_236 |
V_252 |
V_253 ,
( ( V_216 == V_231 )
<< V_254 ) |
( V_39 . V_209 << V_255 ) |
( V_216 - 1 ) ) ;
F_64 ( & V_4 -> V_256 [ V_83 ] ) ;
if ( V_203 ) {
if ( ! V_222 ) {
F_25 ( V_2 ) ;
switch ( V_5 -> type ) {
case V_159 :
F_32 ( V_2 ) ;
break;
case V_160 :
if ( V_5 -> V_257 < 1 )
F_32 ( V_2 ) ;
break;
default:
break;
}
}
V_53 = V_226 ;
if ( V_39 . V_214 )
V_53 |= V_258 ;
if ( V_216 == V_231 )
V_53 |= V_259 ;
F_6 ( V_2 , V_225 + V_217 ,
V_226 | V_259 |
V_258 , V_53 ) ;
if ( V_4 -> V_260 ) {
V_221 = F_65 ( & V_4 -> V_256 [ V_83 ] ,
F_31 ( 10 ) ) ;
if ( V_221 == 0 )
F_66 ( V_2 -> V_28 ,
L_33 ) ;
} else {
F_36 ( 5 ) ;
}
} else {
if ( V_222 ) {
switch ( V_5 -> type ) {
case V_159 :
F_37 ( V_2 ) ;
break;
case V_160 :
if ( V_5 -> V_257 < 1 )
F_37 ( V_2 ) ;
break;
default:
break;
}
F_28 ( V_2 ) ;
}
}
V_40:
V_4 -> V_39 [ V_83 ] . V_232 = V_202 ;
V_4 -> V_39 [ V_83 ] . V_40 = V_203 ;
V_4 -> V_39 [ V_83 ] . V_216 = V_216 ;
F_8 ( V_2 ) ;
if ( F_67 ( V_4 -> V_17 [ 0 ] , V_4 -> V_17 [ 1 ] ) < 50000 ) {
F_5 ( V_2 -> V_28 , L_34 ) ;
V_4 -> V_261 [ 0 ] = F_3 ( V_2 , V_262 )
& V_263 ;
V_4 -> V_261 [ 1 ] = F_3 ( V_2 , V_264 )
& V_263 ;
F_6 ( V_2 , V_262 ,
V_263 , 0x1 ) ;
F_6 ( V_2 , V_264 ,
V_265 , 0x1 ) ;
} else if ( V_4 -> V_261 [ 0 ] ) {
F_6 ( V_2 , V_262 ,
V_263 ,
V_4 -> V_261 [ 0 ] ) ;
F_6 ( V_2 , V_264 ,
V_265 ,
V_4 -> V_261 [ 1 ] ) ;
V_4 -> V_261 [ 0 ] = 0 ;
V_4 -> V_261 [ 1 ] = 0 ;
}
return 0 ;
}
static T_3 F_68 ( int V_266 , void * V_267 )
{
struct V_268 * V_268 = V_267 ;
F_69 ( V_268 ) ;
return V_269 ;
}
static int F_70 ( struct V_270 * V_271 , int V_83 , int V_216 ,
unsigned int V_202 , unsigned int V_203 )
{
return F_62 ( V_271 -> V_2 , V_83 , V_216 , V_202 , V_203 ) ;
}
static int F_71 ( struct V_270 * V_271 ,
int V_272 , unsigned int V_273 , int V_274 )
{
struct V_1 * V_2 = V_271 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
switch ( V_271 -> V_83 ) {
case 1 :
case 2 :
break;
default:
return - V_42 ;
}
switch ( V_272 ) {
case V_35 :
V_4 -> V_8 [ V_271 -> V_83 - 1 ] = V_35 ;
V_4 -> V_36 [ 0 ] = V_273 ;
F_5 ( V_271 -> V_28 , L_35 ,
V_271 -> V_83 , V_273 ) ;
break;
case V_37 :
V_4 -> V_8 [ V_271 -> V_83 - 1 ] = V_37 ;
V_4 -> V_36 [ 1 ] = V_273 ;
F_5 ( V_271 -> V_28 , L_36 ,
V_271 -> V_83 , V_273 ) ;
break;
case V_38 :
V_4 -> V_8 [ V_271 -> V_83 - 1 ] = V_38 ;
F_5 ( V_271 -> V_28 , L_37 , V_271 -> V_83 ) ;
break;
case V_41 :
V_4 -> V_8 [ V_271 -> V_83 - 1 ] = V_41 ;
F_5 ( V_271 -> V_28 , L_38 , V_271 -> V_83 ) ;
break;
case V_275 :
if ( V_273 ) {
for ( V_7 = 0 ; V_7 < F_4 ( V_276 ) ; V_7 ++ )
if ( V_276 [ V_7 ] == V_273 )
break;
if ( V_7 == F_4 ( V_276 ) )
return - V_42 ;
F_6 ( V_2 , V_277 ,
V_278 , V_7 ) ;
F_6 ( V_2 , V_279 ,
V_280 , V_280 ) ;
} else {
F_6 ( V_2 , V_279 ,
V_280 , 0 ) ;
}
default:
return - V_42 ;
}
F_8 ( V_2 ) ;
if ( F_67 ( V_4 -> V_17 [ 0 ] , V_4 -> V_17 [ 1 ] ) < 50000 ) {
F_5 ( V_2 -> V_28 , L_34 ) ;
V_4 -> V_261 [ 0 ] = F_3 ( V_2 , V_262 )
& V_263 ;
V_4 -> V_261 [ 1 ] = F_3 ( V_2 , V_264 )
& V_263 ;
F_6 ( V_2 , V_262 ,
V_263 , 0x1 ) ;
F_6 ( V_2 , V_264 ,
V_265 , 0x1 ) ;
} else if ( V_4 -> V_261 [ 0 ] ) {
F_6 ( V_2 , V_262 ,
V_263 ,
V_4 -> V_261 [ 0 ] ) ;
F_6 ( V_2 , V_264 ,
V_265 ,
V_4 -> V_261 [ 1 ] ) ;
V_4 -> V_261 [ 0 ] = 0 ;
V_4 -> V_261 [ 1 ] = 0 ;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 ,
enum V_281 V_282 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
F_73 ( V_2 , V_282 ) ;
switch ( V_282 ) {
case V_283 :
break;
case V_284 :
switch ( V_5 -> type ) {
case V_160 :
case V_285 :
F_6 ( V_2 , V_286 ,
V_287 , 0 ) ;
F_6 ( V_2 , V_288 ,
V_289 , 0 ) ;
break;
default:
break;
}
if ( F_74 ( V_2 ) == V_290 )
F_25 ( V_2 ) ;
break;
case V_290 :
if ( F_74 ( V_2 ) == V_291 ) {
switch ( V_5 -> type ) {
case V_160 :
if ( V_5 -> V_257 == 0 ) {
F_6 ( V_2 ,
V_292 ,
V_293 ,
V_293 ) ;
}
break;
default:
break;
}
F_6 ( V_2 , V_123 ,
V_124 |
V_125 ,
V_124 |
V_125 ) ;
}
if ( F_74 ( V_2 ) == V_284 )
F_28 ( V_2 ) ;
switch ( V_5 -> type ) {
case V_160 :
case V_285 :
F_6 ( V_2 , V_286 ,
V_287 ,
V_287 ) ;
F_6 ( V_2 , V_288 ,
V_289 ,
V_289 ) ;
break;
default:
break;
}
break;
case V_291 :
if ( F_74 ( V_2 ) == V_290 )
V_4 -> V_294 = NULL ;
break;
}
return 0 ;
}
int F_75 ( struct V_1 * V_2 , enum F_75 V_101 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_46 * V_47 = F_9 ( V_2 ) ;
switch ( V_101 ) {
case V_127 :
F_76 ( V_47 ) ;
if ( V_4 -> V_138 . V_139 ) {
F_77 ( V_47 ,
L_39 ) ;
F_77 ( V_47 ,
L_40 ) ;
}
if ( V_4 -> V_138 . V_143 ) {
F_77 ( V_47 ,
L_41 ) ;
F_77 ( V_47 ,
L_42 ) ;
}
F_78 ( V_47 ) ;
V_4 -> V_126 = V_101 ;
F_79 ( V_47 ) ;
break;
case V_137 :
F_76 ( V_47 ) ;
if ( V_4 -> V_138 . V_139 ) {
F_80 ( V_47 ,
L_39 ) ;
F_80 ( V_47 ,
L_40 ) ;
}
if ( V_4 -> V_138 . V_143 ) {
F_80 ( V_47 ,
L_41 ) ;
F_80 ( V_47 ,
L_42 ) ;
}
V_4 -> V_126 = V_101 ;
F_78 ( V_47 ) ;
F_79 ( V_47 ) ;
break;
default:
return - V_42 ;
}
return 0 ;
}
static int F_81 ( struct V_270 * V_271 , unsigned int V_295 )
{
struct V_1 * V_2 = V_271 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_296 ;
int V_297 ;
int V_298 ;
int V_299 ;
int V_300 = 0 ;
int V_301 = 0 ;
int V_302 = 0 ;
switch ( V_271 -> V_83 ) {
case 1 :
V_296 = V_303 ;
V_297 = V_164 ;
V_298 = V_304 ;
V_299 = V_305 ;
break;
case 2 :
V_296 = V_306 ;
V_297 = V_181 ;
V_298 = V_304 ;
V_299 = V_305 ;
break;
default:
return - V_42 ;
}
switch ( V_295 & V_307 ) {
case V_308 :
break;
case V_309 :
V_300 = V_310 ;
break;
default:
return - V_42 ;
}
switch ( V_295 & V_311 ) {
case V_312 :
V_301 |= V_313 ;
V_302 |= V_314 ;
case V_315 :
V_301 |= 0x18 ;
break;
case V_316 :
V_301 |= 0x10 ;
break;
case V_317 :
break;
case V_318 :
V_301 |= 0x8 ;
break;
default:
return - V_42 ;
}
switch ( V_295 & V_311 ) {
case V_315 :
case V_312 :
switch ( V_295 & V_319 ) {
case V_320 :
break;
case V_321 :
V_301 |= V_322 ;
break;
default:
return - V_42 ;
}
break;
case V_316 :
case V_317 :
case V_318 :
switch ( V_295 & V_319 ) {
case V_320 :
break;
case V_323 :
V_301 |= V_322 | V_313 ;
V_302 |= V_314 ;
break;
case V_321 :
V_301 |= V_322 ;
break;
case V_324 :
V_301 |= V_313 ;
V_302 |= V_314 ;
break;
default:
return - V_42 ;
}
break;
default:
return - V_42 ;
}
switch ( V_5 -> type ) {
case V_285 :
case V_160 :
if ( V_271 -> V_83 == 2 )
F_6 ( V_2 , V_325 ,
V_313 |
V_326 , V_301 ) ;
break;
default:
break;
}
F_6 ( V_2 , V_297 ,
V_322 | V_313 |
V_327 ,
V_301 ) ;
F_6 ( V_2 , V_296 , V_310 ,
V_300 ) ;
F_6 ( V_2 , V_298 ,
V_314 , V_302 ) ;
F_6 ( V_2 , V_299 ,
V_314 , V_302 ) ;
return 0 ;
}
static int F_82 ( struct V_328 * V_329 ,
struct V_330 * V_331 ,
struct V_270 * V_271 )
{
struct V_1 * V_2 = V_271 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_71 * V_18 = & V_5 -> V_18 ;
int V_297 ;
int V_332 ;
int V_333 ;
int V_334 ;
int V_335 ;
int V_301 = 0 ;
int V_336 = 0 ;
int V_337 = 0 ;
int V_302 = 0 ;
int V_338 = 0 ;
int V_83 = V_271 -> V_83 - 1 ;
int V_7 , V_339 , V_91 , V_340 , V_6 ;
switch ( V_271 -> V_83 ) {
case 1 :
V_297 = V_164 ;
V_332 = V_171 ;
V_333 = V_341 ;
V_335 = V_262 ;
if ( V_329 -> V_342 == V_343 ||
V_4 -> V_344 [ 0 ] ) {
V_334 = V_304 ;
} else {
V_334 = V_305 ;
F_5 ( V_2 -> V_28 , L_43 ) ;
}
break;
case 2 :
V_297 = V_181 ;
V_332 = V_186 ;
V_333 = V_345 ;
V_335 = V_264 ;
if ( V_329 -> V_342 == V_343 ||
V_4 -> V_344 [ 1 ] ) {
V_334 = V_346 ;
} else {
V_334 = V_347 ;
F_5 ( V_2 -> V_28 , L_44 ) ;
}
break;
default:
return - V_42 ;
}
V_340 = F_83 ( V_331 ) ;
switch ( F_84 ( V_331 ) ) {
case 16 :
V_340 *= 16 ;
break;
case 20 :
V_340 *= 20 ;
V_301 |= 0x20 ;
break;
case 24 :
V_340 *= 24 ;
V_301 |= 0x40 ;
break;
case 32 :
V_340 *= 32 ;
V_301 |= 0x60 ;
break;
default:
return - V_42 ;
}
V_4 -> V_163 [ V_83 ] = F_85 ( V_331 ) ;
if ( V_18 -> V_348 [ V_83 ] &&
V_4 -> V_163 [ V_83 ] > V_18 -> V_348 [ V_83 ] ) {
F_5 ( V_271 -> V_28 , L_45 ,
V_18 -> V_348 [ V_83 ] , V_4 -> V_163 [ V_83 ] ) ;
V_4 -> V_163 [ V_83 ] = V_18 -> V_348 [ V_83 ] ;
}
switch ( V_4 -> V_163 [ V_83 ] ) {
case 1 :
case 2 :
V_340 *= 2 ;
break;
default:
V_340 *= 4 ;
break;
}
for ( V_7 = 0 ; V_7 < F_4 ( V_349 ) ; V_7 ++ )
if ( V_349 [ V_7 ] . V_26 == F_83 ( V_331 ) )
break;
if ( V_7 == F_4 ( V_349 ) )
return - V_42 ;
V_338 |= V_349 [ V_7 ] . V_9 << V_350 ;
F_5 ( V_271 -> V_28 , L_46 , V_349 [ V_7 ] . V_26 ) ;
F_5 ( V_271 -> V_28 , L_47 ,
V_271 -> V_83 , V_4 -> V_17 [ V_83 ] , V_340 ) ;
if ( V_4 -> V_163 [ V_83 ] == 1 &&
( F_3 ( V_2 , V_297 ) & 0x18 ) == 0x18 )
V_336 |= V_351 ;
if ( V_4 -> V_17 [ V_83 ] == 0 ) {
F_63 ( V_271 -> V_28 , L_48 , V_271 -> V_83 ) ;
return - V_42 ;
}
V_6 = 0 ;
V_91 = abs ( ( V_352 [ 0 ] * F_83 ( V_331 ) )
- V_4 -> V_17 [ V_83 ] ) ;
for ( V_7 = 1 ; V_7 < F_4 ( V_352 ) ; V_7 ++ ) {
V_339 = abs ( ( V_352 [ V_7 ] * F_83 ( V_331 ) )
- V_4 -> V_17 [ V_83 ] ) ;
if ( V_339 >= V_91 )
continue;
V_6 = V_7 ;
V_91 = V_339 ;
}
F_5 ( V_271 -> V_28 , L_49 ,
V_271 -> V_83 , V_352 [ V_6 ] ) ;
V_338 |= V_6 ;
V_6 = 0 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_353 ) ; V_7 ++ ) {
V_339 = ( V_4 -> V_17 [ V_83 ] * 10 / V_353 [ V_7 ] ) - V_340 ;
if ( V_339 < 0 )
break;
V_6 = V_7 ;
}
V_340 = V_4 -> V_17 [ V_83 ] * 10 / V_353 [ V_6 ] ;
F_5 ( V_271 -> V_28 , L_50 ,
V_353 [ V_6 ] , V_340 ) ;
V_337 |= V_6 << V_354 ;
V_302 = V_340 / F_83 ( V_331 ) ;
if ( ! V_302 ) {
F_63 ( V_271 -> V_28 , L_51 ,
V_340 ) ;
return - V_42 ;
}
F_5 ( V_271 -> V_28 , L_52 ,
V_302 , V_340 / V_302 ) ;
F_6 ( V_2 , V_297 , V_355 , V_301 ) ;
F_6 ( V_2 , V_332 , V_351 , V_336 ) ;
F_6 ( V_2 , V_333 , V_356 , V_337 ) ;
F_6 ( V_2 , V_334 , V_357 ,
V_302 ) ;
F_6 ( V_2 , V_335 , V_358 |
V_263 , V_338 ) ;
if ( V_329 -> V_342 == V_343 ) {
switch ( V_271 -> V_83 ) {
case 1 :
V_4 -> V_98 [ 0 ] = F_83 ( V_331 ) ;
F_20 ( V_2 , 0 ) ;
F_20 ( V_2 , 1 ) ;
break;
case 2 :
V_4 -> V_98 [ 1 ] = F_83 ( V_331 ) ;
F_20 ( V_2 , 2 ) ;
break;
}
}
return 0 ;
}
static int F_86 ( struct V_328 * V_329 ,
struct V_330 * V_331 ,
struct V_270 * V_271 )
{
struct V_1 * V_2 = V_271 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_297 ;
int V_301 = 0 ;
switch ( V_271 -> V_83 ) {
case 3 :
switch ( V_5 -> type ) {
case V_285 :
case V_160 :
V_297 = V_325 ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
switch ( F_84 ( V_331 ) ) {
case 16 :
break;
case 20 :
V_301 |= 0x20 ;
break;
case 24 :
V_301 |= 0x40 ;
break;
case 32 :
V_301 |= 0x60 ;
break;
default:
return - V_42 ;
}
return F_6 ( V_2 , V_297 , V_355 , V_301 ) ;
}
static int F_87 ( struct V_270 * V_359 , int V_360 )
{
struct V_1 * V_2 = V_359 -> V_2 ;
int V_361 ;
int V_53 ;
switch ( V_359 -> V_83 ) {
case 1 :
V_361 = V_362 ;
break;
case 2 :
V_361 = V_363 ;
break;
default:
return - V_42 ;
}
if ( V_360 )
V_53 = V_364 ;
else
V_53 = 0 ;
F_6 ( V_2 , V_361 , V_364 , V_53 ) ;
return 0 ;
}
static int F_88 ( struct V_270 * V_359 , int V_365 )
{
struct V_1 * V_2 = V_359 -> V_2 ;
int V_53 , V_9 , V_63 ;
switch ( V_359 -> V_83 ) {
case 1 :
V_53 = V_303 ;
V_63 = V_366 ;
break;
case 2 :
V_53 = V_306 ;
V_63 = V_367 ;
break;
default:
return - V_42 ;
}
if ( V_365 )
V_9 = V_63 ;
else
V_9 = 0 ;
return F_6 ( V_2 , V_53 , V_63 , V_9 ) ;
}
static int F_89 ( struct V_270 * V_271 )
{
struct V_1 * V_2 = V_271 -> V_2 ;
F_6 ( V_2 , V_368 ,
V_369 | V_370 , 0 ) ;
F_6 ( V_2 , V_371 ,
V_369 | V_370 , 0 ) ;
F_6 ( V_2 , V_372 ,
V_369 | V_370 , 0 ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 , V_64 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_39 ) ; V_7 ++ ) {
memcpy ( & V_4 -> V_373 [ V_7 ] , & V_4 -> V_39 [ V_7 ] ,
sizeof( struct V_374 ) ) ;
V_64 = F_62 ( V_2 , V_7 + 1 , 0 , 0 , 0 ) ;
if ( V_64 < 0 )
F_66 ( V_2 -> V_28 , L_53 ,
V_7 + 1 , V_64 ) ;
}
F_91 ( V_2 , V_291 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 , V_64 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_39 ) ; V_7 ++ ) {
if ( ! V_4 -> V_373 [ V_7 ] . V_40 )
continue;
V_64 = F_62 ( V_2 , V_7 + 1 ,
V_4 -> V_373 [ V_7 ] . V_216 ,
V_4 -> V_373 [ V_7 ] . V_232 ,
V_4 -> V_373 [ V_7 ] . V_40 ) ;
if ( V_64 < 0 )
F_66 ( V_2 -> V_28 , L_54 ,
V_7 + 1 , V_64 ) ;
}
return 0 ;
}
static void F_93 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_138 . V_2 ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_71 * V_18 = & V_5 -> V_18 ;
struct V_375 V_376 [] = {
F_94 ( L_11 ,
V_4 -> V_377 ,
F_23 ,
F_22 ) ,
F_94 ( L_12 ,
V_4 -> V_377 ,
F_23 ,
F_22 ) ,
F_94 ( L_13 ,
V_4 -> V_377 ,
F_23 ,
F_22 ) ,
} ;
int V_64 , V_7 , V_378 ;
const char * * V_379 ;
V_4 -> V_92 = 0 ;
V_4 -> V_97 = NULL ;
for ( V_7 = 0 ; V_7 < V_18 -> V_95 ; V_7 ++ ) {
for ( V_378 = 0 ; V_378 < V_4 -> V_92 ; V_378 ++ ) {
if ( strcmp ( V_18 -> V_96 [ V_7 ] . V_55 ,
V_4 -> V_97 [ V_378 ] ) == 0 )
break;
}
if ( V_378 != V_4 -> V_92 )
continue;
V_379 = F_95 ( V_4 -> V_97 ,
sizeof( char * ) *
( V_4 -> V_92 + 1 ) ,
V_380 ) ;
if ( V_379 == NULL )
continue;
V_379 [ V_4 -> V_92 ] =
V_18 -> V_96 [ V_7 ] . V_55 ;
V_4 -> V_92 ++ ;
V_4 -> V_97 = V_379 ;
}
F_5 ( V_2 -> V_28 , L_55 ,
V_4 -> V_92 ) ;
V_4 -> V_377 . V_381 = V_4 -> V_92 ;
V_4 -> V_377 . V_382 = V_4 -> V_97 ;
V_64 = F_96 ( V_4 -> V_138 . V_2 , V_376 ,
F_4 ( V_376 ) ) ;
if ( V_64 != 0 )
F_63 ( V_4 -> V_138 . V_2 -> V_28 ,
L_56 , V_64 ) ;
}
static void F_97 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_138 . V_2 ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_71 * V_18 = & V_5 -> V_18 ;
int V_64 , V_7 ;
if ( ! V_18 )
return;
F_98 ( V_2 , V_18 -> V_383 ,
V_18 -> V_384 ,
V_18 -> V_385 ,
V_18 -> V_386 ,
V_18 -> V_387 ,
V_18 -> V_388 ,
V_18 -> V_389 ,
V_18 -> V_390 ,
V_18 -> V_391 ,
V_18 -> V_392 ) ;
F_5 ( V_2 -> V_28 , L_57 , V_18 -> V_85 ) ;
if ( V_18 -> V_85 ) {
struct V_375 V_376 [] = {
F_94 ( L_7 , V_4 -> V_393 ,
F_19 , F_18 ) ,
F_94 ( L_8 , V_4 -> V_393 ,
F_19 , F_18 ) ,
F_94 ( L_9 , V_4 -> V_393 ,
F_19 , F_18 ) ,
} ;
V_4 -> V_394 = F_99 ( V_4 -> V_138 . V_2 -> V_28 ,
sizeof( char * ) * V_18 -> V_85 , V_380 ) ;
if ( ! V_4 -> V_394 )
return;
for ( V_7 = 0 ; V_7 < V_18 -> V_85 ; V_7 ++ )
V_4 -> V_394 [ V_7 ] = V_18 -> V_81 [ V_7 ] . V_55 ;
V_4 -> V_393 . V_381 = V_18 -> V_85 ;
V_4 -> V_393 . V_382 = V_4 -> V_394 ;
V_64 = F_96 ( V_4 -> V_138 . V_2 , V_376 ,
F_4 ( V_376 ) ) ;
for ( V_7 = 0 ; V_7 < V_395 ; V_7 ++ )
F_16 ( V_2 , V_7 ) ;
} else {
V_64 = F_96 ( V_4 -> V_138 . V_2 ,
V_396 ,
F_4 ( V_396 ) ) ;
}
if ( V_64 != 0 )
F_63 ( V_4 -> V_138 . V_2 -> V_28 ,
L_58 , V_64 ) ;
F_5 ( V_2 -> V_28 , L_59 ,
V_18 -> V_95 ) ;
if ( V_18 -> V_95 )
F_93 ( V_4 ) ;
else
F_96 ( V_4 -> V_138 . V_2 , V_397 ,
F_4 ( V_397 ) ) ;
for ( V_7 = 0 ; V_7 < F_4 ( V_18 -> V_398 ) ; V_7 ++ ) {
if ( V_18 -> V_398 [ V_7 ] ) {
F_43 ( V_2 , V_286 + V_7 ,
V_18 -> V_398 [ V_7 ] & 0xffff ) ;
}
}
}
int F_100 ( struct V_1 * V_2 , struct V_399 * V_103 ,
int V_398 )
{
struct V_46 * V_47 = F_9 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_400 * V_102 ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_53 , V_64 ;
if ( V_5 -> type != V_159 ) {
F_66 ( V_2 -> V_28 , L_60 ) ;
return - V_42 ;
}
switch ( V_398 ) {
case 1 :
V_102 = & V_4 -> V_102 [ 0 ] ;
if ( V_103 )
V_64 = F_101 ( V_47 , L_61 ) ;
else
V_64 = F_102 ( V_47 , L_61 ) ;
break;
case 2 :
V_102 = & V_4 -> V_102 [ 1 ] ;
if ( V_103 )
V_64 = F_101 ( V_47 , L_61 ) ;
else
V_64 = F_102 ( V_47 , L_61 ) ;
break;
default:
F_66 ( V_2 -> V_28 , L_62 , V_398 ) ;
return - V_42 ;
}
if ( V_64 != 0 )
F_66 ( V_2 -> V_28 , L_63 ,
V_398 , V_64 ) ;
F_5 ( V_2 -> V_28 , L_64 ,
V_398 , V_103 ) ;
V_102 -> V_103 = V_103 ;
V_102 -> V_401 = true ;
if ( V_4 -> V_102 [ 0 ] . V_103 || V_4 -> V_102 [ 1 ] . V_103 )
V_53 = V_402 ;
else
V_53 = 0 ;
F_6 ( V_2 , V_403 , V_402 , V_53 ) ;
F_6 ( V_2 , V_404 ,
V_405 | V_406 |
V_407 | V_408 ,
V_409 | V_410 ) ;
F_10 ( V_47 ) ;
return 0 ;
}
static void F_103 ( struct V_411 * V_412 )
{
struct V_3 * V_413 = F_104 ( V_412 ,
struct V_3 ,
V_414 . V_412 ) ;
struct V_415 * V_415 = V_413 -> V_4 -> V_415 ;
struct V_416 * V_28 = V_413 -> V_4 -> V_28 ;
unsigned int V_53 ;
int V_64 ;
int V_417 ;
F_33 ( V_28 ) ;
V_64 = F_105 ( V_415 , V_418 , & V_53 ) ;
if ( V_64 < 0 ) {
F_63 ( V_28 , L_65 ,
V_64 ) ;
F_38 ( V_28 ) ;
return;
}
F_5 ( V_28 , L_66 , V_53 ) ;
V_417 = 0 ;
if ( V_53 & V_419 ) {
if ( V_413 -> V_102 [ 0 ] . V_401 )
V_417 = V_420 ;
}
if ( V_53 & V_421 ) {
if ( V_413 -> V_102 [ 0 ] . V_401 )
V_417 = V_422 ;
else
V_417 |= V_423 ;
}
if ( V_417 )
V_413 -> V_102 [ 0 ] . V_401 = false ;
else
V_413 -> V_102 [ 0 ] . V_401 = true ;
F_106 ( V_413 -> V_102 [ 0 ] . V_103 , V_417 ,
V_420 | V_423 ) ;
V_417 = 0 ;
if ( V_53 & V_424 ) {
if ( V_413 -> V_102 [ 1 ] . V_401 )
V_417 = V_420 ;
}
if ( V_53 & V_425 ) {
if ( V_413 -> V_102 [ 1 ] . V_401 )
V_417 = V_422 ;
else
V_417 |= V_423 ;
}
if ( V_417 )
V_413 -> V_102 [ 1 ] . V_401 = false ;
else
V_413 -> V_102 [ 1 ] . V_401 = true ;
F_106 ( V_413 -> V_102 [ 1 ] . V_103 , V_417 ,
V_420 | V_423 ) ;
F_38 ( V_28 ) ;
}
static T_3 F_107 ( int V_266 , void * V_267 )
{
struct V_3 * V_413 = V_267 ;
struct V_1 * V_2 = V_413 -> V_138 . V_2 ;
#ifndef F_108
F_109 ( F_110 ( V_2 -> V_28 ) ) ;
#endif
F_111 ( V_2 -> V_28 , 300 ) ;
F_30 ( V_119 ,
& V_413 -> V_414 , F_31 ( 250 ) ) ;
return V_269 ;
}
static void F_112 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = F_9 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_21 )
return;
F_6 ( V_2 , V_29 , V_426 , 0 ) ;
F_24 ( V_2 , V_113 ) ;
if ( V_4 -> V_4 -> V_18 . V_427 )
F_102 ( V_47 , L_67 ) ;
}
static void F_113 ( struct V_1 * V_2 , T_1 V_428 )
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
F_106 ( V_4 -> V_102 [ 0 ] . V_103 , V_417 ,
V_4 -> V_434 ) ;
}
static void F_114 ( struct V_411 * V_412 )
{
struct V_3 * V_4 = F_104 ( V_412 ,
struct V_3 ,
V_435 . V_412 ) ;
struct V_416 * V_28 = V_4 -> V_4 -> V_28 ;
F_26 ( & V_4 -> V_110 ) ;
F_112 ( V_4 -> V_138 . V_2 ) ;
F_5 ( V_28 , L_68 ) ;
V_4 -> V_14 = false ;
V_4 -> V_111 = true ;
F_1 ( V_4 -> V_138 . V_2 ) ;
F_106 ( V_4 -> V_102 [ 0 ] . V_103 , 0 ,
V_4 -> V_434 |
V_420 ) ;
F_27 ( & V_4 -> V_110 ) ;
}
static void F_115 ( void * V_267 , T_1 V_428 )
{
struct V_1 * V_2 = V_267 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! ( V_428 & V_436 ) ) {
F_5 ( V_2 -> V_28 , L_69 ) ;
F_30 ( V_119 ,
& V_4 -> V_435 ,
F_31 ( 2500 ) ) ;
return;
}
if ( V_428 & 0x600 ) {
F_5 ( V_2 -> V_28 , L_70 ) ;
V_4 -> V_111 = false ;
V_4 -> V_14 = true ;
F_1 ( V_2 ) ;
F_106 ( V_4 -> V_102 [ 0 ] . V_103 , V_420 ,
V_420 ) ;
}
if ( V_428 & 0xfc ) {
F_5 ( V_2 -> V_28 , L_71 ) ;
V_4 -> V_111 = false ;
F_1 ( V_2 ) ;
F_112 ( V_2 ) ;
F_106 ( V_4 -> V_102 [ 0 ] . V_103 , V_422 ,
V_420 ) ;
}
}
static void F_116 ( struct V_411 * V_412 )
{
struct V_3 * V_4 = F_104 ( V_412 , struct V_3 ,
V_414 . V_412 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_1 * V_2 = V_4 -> V_138 . V_2 ;
struct V_46 * V_47 = F_9 ( V_2 ) ;
F_33 ( V_2 -> V_28 ) ;
if ( V_5 -> V_18 . V_427 ) {
F_101 ( V_47 , L_67 ) ;
F_10 ( V_47 ) ;
}
F_26 ( & V_4 -> V_110 ) ;
F_5 ( V_2 -> V_28 , L_72 ) ;
if ( V_4 -> V_437 ) {
V_4 -> V_437 ( V_4 -> V_438 ) ;
} else {
V_4 -> V_111 = true ;
F_24 ( V_2 , V_112 ) ;
F_6 ( V_2 , V_29 ,
V_426 , V_426 ) ;
}
F_27 ( & V_4 -> V_110 ) ;
F_38 ( V_2 -> V_28 ) ;
}
static T_3 F_117 ( int V_266 , void * V_267 )
{
struct V_3 * V_4 = V_267 ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_1 * V_2 = V_4 -> V_138 . V_2 ;
struct V_46 * V_47 = F_9 ( V_2 ) ;
int V_53 , V_439 ;
bool V_440 ;
F_33 ( V_2 -> V_28 ) ;
F_118 ( & V_4 -> V_441 ) ;
F_26 ( & V_4 -> V_110 ) ;
V_53 = F_3 ( V_2 , V_442 ) ;
if ( V_53 < 0 ) {
F_63 ( V_2 -> V_28 , L_73 , V_53 ) ;
F_27 ( & V_4 -> V_110 ) ;
F_38 ( V_2 -> V_28 ) ;
return V_443 ;
}
F_5 ( V_2 -> V_28 , L_74 , V_53 ) ;
V_440 = V_53 & V_444 ;
if ( V_440 ) {
F_5 ( V_2 -> V_28 , L_75 ) ;
F_1 ( V_2 ) ;
F_6 ( V_2 , V_288 ,
V_445 , 0 ) ;
F_6 ( V_2 , V_442 ,
V_446 , 0 ) ;
V_439 = V_5 -> V_18 . V_447 ;
F_30 ( V_119 ,
& V_4 -> V_414 ,
F_31 ( V_439 ) ) ;
} else {
F_5 ( V_2 -> V_28 , L_76 ) ;
F_118 ( & V_4 -> V_414 ) ;
F_6 ( V_2 , V_288 ,
V_445 , V_445 ) ;
F_6 ( V_2 , V_442 ,
V_446 , V_446 ) ;
V_4 -> V_111 = false ;
V_4 -> V_14 = false ;
F_6 ( V_2 , V_29 ,
V_426 , 0 ) ;
F_24 ( V_2 , V_113 ) ;
}
F_27 ( & V_4 -> V_110 ) ;
if ( V_5 -> V_18 . V_427 && ! V_440 )
F_102 ( V_47 , L_67 ) ;
if ( V_440 )
F_106 ( V_4 -> V_102 [ 0 ] . V_103 ,
V_448 , V_448 ) ;
else
F_106 ( V_4 -> V_102 [ 0 ] . V_103 , 0 ,
V_448 | V_420 |
V_4 -> V_434 ) ;
F_106 ( V_4 -> V_102 [ 0 ] . V_103 , 0 , 0 ) ;
F_38 ( V_2 -> V_28 ) ;
return V_269 ;
}
static void F_119 ( struct V_411 * V_412 )
{
struct V_3 * V_4 = F_104 ( V_412 ,
struct V_3 ,
V_120 . V_412 ) ;
F_117 ( 0 , V_4 ) ;
}
int F_120 ( struct V_1 * V_2 , struct V_399 * V_103 ,
T_4 V_449 , void * V_450 ,
T_5 V_451 , void * V_452 )
{
struct V_46 * V_47 = F_9 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
T_1 V_453 ;
switch ( V_5 -> type ) {
case V_285 :
case V_160 :
break;
default:
return - V_42 ;
}
if ( V_103 ) {
F_101 ( V_47 , L_77 ) ;
F_10 ( V_47 ) ;
V_4 -> V_102 [ 0 ] . V_103 = V_103 ;
if ( V_449 ) {
V_4 -> V_437 = V_449 ;
V_4 -> V_438 = V_450 ;
} else {
V_4 -> V_111 = true ;
V_4 -> V_14 = false ;
}
if ( V_451 ) {
V_4 -> V_454 = V_451 ;
V_4 -> V_455 = V_452 ;
} else {
V_4 -> V_454 = F_115 ;
V_4 -> V_455 = V_2 ;
}
F_1 ( V_2 ) ;
if ( V_5 -> V_18 . V_453 )
V_453 = V_5 -> V_18 . V_453 ;
else
V_453 = 0x41 ;
V_4 -> V_434 = V_423 | V_429 |
V_430 | V_431 |
V_432 | V_433 ;
F_6 ( V_2 , V_456 ,
V_457 , V_453 ) ;
F_35 ( F_74 ( V_2 ) > V_290 ) ;
if ( V_4 -> V_21 ) {
F_6 ( V_2 , V_442 ,
V_446 , 0 ) ;
F_6 ( V_2 , V_288 ,
V_445 ,
V_445 ) ;
F_6 ( V_2 , V_458 ,
V_459 , 0 ) ;
F_24 ( V_2 ,
V_113 ) ;
} else {
F_6 ( V_2 , V_29 ,
V_426 , V_426 ) ;
}
} else {
F_6 ( V_2 , V_29 ,
V_426 , 0 ) ;
F_24 ( V_2 , V_107 ) ;
F_102 ( V_47 , L_77 ) ;
F_10 ( V_47 ) ;
}
return 0 ;
}
static void F_121 ( struct V_411 * V_412 )
{
struct V_3 * V_4 = F_104 ( V_412 ,
struct V_3 ,
V_441 . V_412 ) ;
struct V_1 * V_2 = V_4 -> V_138 . V_2 ;
F_33 ( V_2 -> V_28 ) ;
F_26 ( & V_4 -> V_110 ) ;
V_4 -> V_454 ( V_4 -> V_455 , V_4 -> V_460 ) ;
F_27 ( & V_4 -> V_110 ) ;
F_38 ( V_2 -> V_28 ) ;
}
static T_3 F_122 ( int V_266 , void * V_267 )
{
struct V_3 * V_4 = V_267 ;
struct V_1 * V_2 = V_4 -> V_138 . V_2 ;
int V_53 , V_461 , V_64 , V_462 ;
if ( ! ( F_3 ( V_2 , V_29 ) & V_426 ) )
return V_269 ;
F_118 ( & V_4 -> V_441 ) ;
F_118 ( & V_4 -> V_435 ) ;
F_33 ( V_2 -> V_28 ) ;
V_461 = 10 ;
do {
V_53 = F_3 ( V_2 , V_463 ) ;
if ( V_53 < 0 ) {
F_63 ( V_2 -> V_28 ,
L_78 ,
V_53 ) ;
F_38 ( V_2 -> V_28 ) ;
return V_443 ;
}
if ( ! ( V_53 & V_464 ) ) {
F_5 ( V_2 -> V_28 , L_79 ) ;
goto V_40;
}
if ( ! ( V_53 & V_436 ) || ( V_53 & V_465 ) )
break;
F_36 ( 1 ) ;
} while ( V_461 -- );
if ( V_461 == 0 )
F_66 ( V_2 -> V_28 , L_80 ) ;
#ifndef F_108
F_109 ( F_110 ( V_2 -> V_28 ) ) ;
#endif
if ( V_4 -> V_21 ) {
V_64 = F_3 ( V_2 , V_442 ) ;
if ( V_64 < 0 ) {
F_63 ( V_2 -> V_28 , L_73 ,
V_64 ) ;
} else if ( ! ( V_64 & V_444 ) ) {
F_5 ( V_2 -> V_28 , L_81 ) ;
goto V_40;
}
} else if ( ! ( V_53 & V_436 ) ) {
F_106 ( V_4 -> V_102 [ 0 ] . V_103 , 0 ,
V_448 | V_420 |
V_4 -> V_434 ) ;
V_4 -> V_111 = true ;
goto V_40;
}
V_4 -> V_460 = V_53 ;
V_462 = V_4 -> V_4 -> V_18 . V_466 ;
if ( V_4 -> V_111 )
F_30 ( V_119 ,
& V_4 -> V_441 ,
F_31 ( V_462 ) ) ;
else
F_113 ( V_2 , V_53 ) ;
V_40:
F_38 ( V_2 -> V_28 ) ;
return V_269 ;
}
static T_3 F_123 ( int V_266 , void * V_267 )
{
struct V_1 * V_2 = V_267 ;
F_63 ( V_2 -> V_28 , L_82 ) ;
return V_269 ;
}
static T_3 F_124 ( int V_266 , void * V_267 )
{
struct V_1 * V_2 = V_267 ;
F_63 ( V_2 -> V_28 , L_83 ) ;
return V_269 ;
}
static T_3 F_125 ( int V_266 , void * V_267 )
{
struct V_1 * V_2 = V_267 ;
F_126 ( V_2 -> V_28 , L_84 ) ;
return V_269 ;
}
static int F_127 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = F_9 ( V_2 ) ;
struct V_4 * V_5 = F_128 ( V_2 -> V_28 -> V_467 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_53 ;
int V_64 , V_7 ;
V_4 -> V_138 . V_2 = V_2 ;
F_129 ( & V_4 -> V_110 ) ;
F_130 ( & V_4 -> V_120 ,
F_119 ) ;
F_130 ( & V_4 -> V_435 ,
F_114 ) ;
switch ( V_5 -> type ) {
case V_159 :
F_130 ( & V_4 -> V_414 , F_103 ) ;
break;
case V_285 :
F_130 ( & V_4 -> V_414 , F_116 ) ;
break;
default:
break;
}
F_130 ( & V_4 -> V_441 , F_121 ) ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_256 ) ; V_7 ++ )
F_131 ( & V_4 -> V_256 [ V_7 ] ) ;
V_4 -> V_468 = V_5 -> V_18 . V_468 ;
V_47 -> V_469 = 1 ;
switch ( V_5 -> type ) {
case V_159 :
if ( ! V_5 -> V_18 . V_383 ||
! V_5 -> V_18 . V_384 )
V_47 -> V_469 = 0 ;
switch ( V_5 -> V_257 ) {
case 2 :
case 3 :
V_4 -> V_138 . V_470 = - 5 ;
V_4 -> V_138 . V_471 = - 5 ;
V_4 -> V_138 . V_472 = 1 ;
V_4 -> V_138 . V_473 = 1 ;
V_4 -> V_138 . V_474 = 1 ;
break;
default:
V_4 -> V_138 . V_473 = 2 ;
break;
}
break;
case V_160 :
V_4 -> V_138 . V_473 = 1 ;
V_4 -> V_138 . V_472 = 1 ;
switch ( V_5 -> V_257 ) {
case 0 :
break;
default:
V_4 -> V_234 = true ;
break;
}
break;
case V_285 :
V_4 -> V_138 . V_473 = 2 ;
V_4 -> V_138 . V_475 = 1 ;
V_4 -> V_138 . V_472 = 1 ;
V_4 -> V_138 . V_476 = true ;
V_4 -> V_234 = true ;
V_4 -> V_138 . V_470 = - 9 ;
V_4 -> V_138 . V_471 = - 7 ;
F_6 ( V_2 , V_477 ,
V_478 , V_478 ) ;
break;
default:
break;
}
F_132 ( V_4 -> V_4 , V_479 ,
F_123 , L_85 , V_2 ) ;
F_132 ( V_4 -> V_4 , V_480 ,
F_124 , L_86 , V_2 ) ;
F_132 ( V_4 -> V_4 , V_481 ,
F_125 , L_87 , V_2 ) ;
switch ( V_5 -> type ) {
case V_159 :
if ( V_4 -> V_468 )
V_64 = F_133 ( V_4 -> V_468 , NULL ,
F_107 ,
V_482 |
V_483 ,
L_88 ,
V_4 ) ;
else
V_64 = F_132 ( V_4 -> V_4 ,
V_484 ,
F_107 , L_89 ,
V_4 ) ;
if ( V_64 != 0 )
F_66 ( V_2 -> V_28 ,
L_90 ,
V_64 ) ;
V_64 = F_132 ( V_4 -> V_4 ,
V_485 ,
F_107 , L_91 ,
V_4 ) ;
if ( V_64 != 0 )
F_66 ( V_2 -> V_28 ,
L_92 ,
V_64 ) ;
V_64 = F_132 ( V_4 -> V_4 ,
V_486 ,
F_107 , L_93 ,
V_4 ) ;
if ( V_64 != 0 )
F_66 ( V_2 -> V_28 ,
L_94 ,
V_64 ) ;
V_64 = F_132 ( V_4 -> V_4 ,
V_487 ,
F_107 , L_95 ,
V_4 ) ;
if ( V_64 != 0 )
F_66 ( V_2 -> V_28 ,
L_96 ,
V_64 ) ;
break;
case V_160 :
case V_285 :
if ( V_4 -> V_468 ) {
V_64 = F_133 ( V_4 -> V_468 , NULL ,
F_122 ,
V_482 |
V_483 ,
L_97 ,
V_4 ) ;
if ( V_64 != 0 )
F_66 ( V_2 -> V_28 ,
L_98 ,
V_64 ) ;
} else {
F_132 ( V_4 -> V_4 , V_484 ,
F_122 , L_97 ,
V_4 ) ;
}
}
switch ( V_5 -> type ) {
case V_285 :
if ( V_5 -> V_488 > 1 || V_5 -> V_257 > 1 ) {
V_64 = F_132 ( V_4 -> V_4 ,
F_134 ( 6 ) ,
F_117 , L_99 ,
V_4 ) ;
if ( V_64 == 0 )
V_4 -> V_21 = true ;
}
break;
default:
break;
}
V_4 -> V_260 = true ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_256 ) ; V_7 ++ ) {
V_64 = F_132 ( V_4 -> V_4 ,
V_489 + V_7 ,
F_68 , L_100 ,
& V_4 -> V_256 [ V_7 ] ) ;
if ( V_64 != 0 )
V_4 -> V_260 = false ;
}
F_33 ( V_2 -> V_28 ) ;
V_64 = F_105 ( V_5 -> V_415 , V_490 , & V_53 ) ;
if ( V_64 < 0 ) {
F_63 ( V_2 -> V_28 , L_101 , V_64 ) ;
goto V_491;
}
if ( ( V_53 & V_492 ) != V_493 ) {
V_4 -> V_344 [ 0 ] = 1 ;
V_494 [ 0 ] . V_495 = 1 ;
} else {
V_4 -> V_344 [ 0 ] = 0 ;
}
V_64 = F_105 ( V_5 -> V_415 , V_496 , & V_53 ) ;
if ( V_64 < 0 ) {
F_63 ( V_2 -> V_28 , L_102 , V_64 ) ;
goto V_491;
}
if ( ( V_53 & V_492 ) != V_493 ) {
V_4 -> V_344 [ 1 ] = 1 ;
V_494 [ 1 ] . V_495 = 1 ;
} else {
V_4 -> V_344 [ 1 ] = 0 ;
}
F_38 ( V_2 -> V_28 ) ;
for ( V_7 = 0 ; V_7 < F_4 ( V_178 ) ; V_7 ++ )
F_6 ( V_2 , V_178 [ V_7 ] . V_53 ,
V_178 [ V_7 ] . V_63 ,
V_178 [ V_7 ] . V_63 ) ;
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
case V_159 :
case V_160 :
F_6 ( V_2 , V_164 ,
V_503 , V_503 ) ;
break;
default:
break;
}
switch ( V_5 -> type ) {
case V_160 :
case V_285 :
F_6 ( V_2 , V_286 ,
V_287 , V_287 ) ;
F_6 ( V_2 , V_288 ,
V_289 , V_289 ) ;
break;
default:
break;
}
V_4 -> V_138 . V_504 = F_40 ;
F_57 ( V_2 ) ;
F_97 ( V_4 ) ;
F_135 ( V_2 ) ;
F_96 ( V_2 , V_505 ,
F_4 ( V_505 ) ) ;
F_136 ( V_47 , V_506 ,
F_4 ( V_506 ) ) ;
switch ( V_5 -> type ) {
case V_159 :
F_136 ( V_47 , V_507 ,
F_4 ( V_507 ) ) ;
if ( V_5 -> V_257 < 4 ) {
F_136 ( V_47 , V_508 ,
F_4 ( V_508 ) ) ;
F_136 ( V_47 , V_509 ,
F_4 ( V_509 ) ) ;
F_136 ( V_47 , V_510 ,
F_4 ( V_510 ) ) ;
} else {
F_136 ( V_47 , V_511 ,
F_4 ( V_511 ) ) ;
F_136 ( V_47 , V_512 ,
F_4 ( V_512 ) ) ;
F_136 ( V_47 , V_513 ,
F_4 ( V_513 ) ) ;
}
break;
case V_160 :
F_96 ( V_2 , V_514 ,
F_4 ( V_514 ) ) ;
F_136 ( V_47 , V_515 ,
F_4 ( V_515 ) ) ;
if ( V_5 -> V_257 < 1 ) {
F_136 ( V_47 , V_508 ,
F_4 ( V_508 ) ) ;
F_136 ( V_47 , V_509 ,
F_4 ( V_509 ) ) ;
F_136 ( V_47 , V_510 ,
F_4 ( V_510 ) ) ;
} else {
F_136 ( V_47 , V_511 ,
F_4 ( V_511 ) ) ;
F_136 ( V_47 , V_512 ,
F_4 ( V_512 ) ) ;
F_136 ( V_47 , V_513 ,
F_4 ( V_513 ) ) ;
}
break;
case V_285 :
F_96 ( V_2 , V_514 ,
F_4 ( V_514 ) ) ;
F_136 ( V_47 , V_515 ,
F_4 ( V_515 ) ) ;
F_136 ( V_47 , V_511 ,
F_4 ( V_511 ) ) ;
F_136 ( V_47 , V_512 ,
F_4 ( V_512 ) ) ;
F_136 ( V_47 , V_513 ,
F_4 ( V_513 ) ) ;
break;
}
F_137 ( V_2 , 0 , 0 ) ;
V_64 = F_132 ( V_4 -> V_4 , V_516 ,
V_517 , L_103 ,
& V_4 -> V_138 ) ;
if ( V_64 == 0 )
V_4 -> V_138 . V_518 = true ;
F_138 ( V_47 , V_519 , F_4 ( V_519 ) ) ;
switch ( V_5 -> type ) {
case V_159 :
F_138 ( V_47 , V_520 ,
F_4 ( V_520 ) ) ;
if ( V_5 -> V_257 < 4 ) {
F_138 ( V_47 , V_521 ,
F_4 ( V_521 ) ) ;
F_138 ( V_47 , V_522 ,
F_4 ( V_522 ) ) ;
} else {
F_138 ( V_47 , V_523 ,
F_4 ( V_523 ) ) ;
}
break;
case V_160 :
if ( V_5 -> V_257 < 1 ) {
F_138 ( V_47 , V_520 ,
F_4 ( V_520 ) ) ;
F_138 ( V_47 , V_521 ,
F_4 ( V_521 ) ) ;
F_138 ( V_47 , V_522 ,
F_4 ( V_522 ) ) ;
} else {
F_138 ( V_47 , V_523 ,
F_4 ( V_523 ) ) ;
F_138 ( V_47 , V_524 ,
F_4 ( V_524 ) ) ;
}
F_139 ( V_2 ) ;
break;
case V_285 :
F_138 ( V_47 , V_523 ,
F_4 ( V_523 ) ) ;
F_138 ( V_47 , V_524 ,
F_4 ( V_524 ) ) ;
break;
}
return 0 ;
V_491:
if ( V_4 -> V_21 )
F_140 ( V_4 -> V_4 , F_134 ( 6 ) , V_4 ) ;
F_140 ( V_4 -> V_4 , V_487 , V_4 ) ;
F_140 ( V_4 -> V_4 , V_486 , V_4 ) ;
F_140 ( V_4 -> V_4 , V_485 , V_4 ) ;
if ( V_4 -> V_468 )
F_141 ( V_4 -> V_468 , V_4 ) ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_256 ) ; V_7 ++ )
F_140 ( V_4 -> V_4 , V_489 + V_7 ,
& V_4 -> V_256 [ V_7 ] ) ;
F_140 ( V_4 -> V_4 , V_516 ,
& V_4 -> V_138 ) ;
F_140 ( V_4 -> V_4 , V_479 , V_2 ) ;
F_140 ( V_4 -> V_4 , V_481 , V_2 ) ;
F_140 ( V_4 -> V_4 , V_480 , V_2 ) ;
return V_64 ;
}
static int F_142 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_256 ) ; V_7 ++ )
F_140 ( V_4 -> V_4 , V_489 + V_7 ,
& V_4 -> V_256 [ V_7 ] ) ;
F_140 ( V_4 -> V_4 , V_516 ,
& V_4 -> V_138 ) ;
F_140 ( V_4 -> V_4 , V_479 , V_2 ) ;
F_140 ( V_4 -> V_4 , V_481 , V_2 ) ;
F_140 ( V_4 -> V_4 , V_480 , V_2 ) ;
if ( V_4 -> V_21 )
F_140 ( V_4 -> V_4 , F_134 ( 6 ) , V_4 ) ;
switch ( V_5 -> type ) {
case V_159 :
if ( V_4 -> V_468 )
F_141 ( V_4 -> V_468 , V_4 ) ;
F_140 ( V_4 -> V_4 , V_486 ,
V_4 ) ;
F_140 ( V_4 -> V_4 , V_485 ,
V_4 ) ;
F_140 ( V_4 -> V_4 , V_484 ,
V_4 ) ;
break;
case V_285 :
case V_160 :
if ( V_4 -> V_468 )
F_141 ( V_4 -> V_468 , V_4 ) ;
break;
}
F_143 ( V_4 -> V_525 ) ;
F_143 ( V_4 -> V_526 ) ;
F_143 ( V_4 -> V_527 ) ;
F_144 ( V_4 -> V_97 ) ;
return 0 ;
}
static struct V_415 * F_145 ( struct V_416 * V_28 )
{
struct V_4 * V_5 = F_128 ( V_28 -> V_467 ) ;
return V_5 -> V_415 ;
}
static int F_146 ( struct V_528 * V_529 )
{
struct V_3 * V_4 ;
V_4 = F_99 ( & V_529 -> V_28 , sizeof( struct V_3 ) ,
V_380 ) ;
if ( V_4 == NULL )
return - V_530 ;
F_147 ( V_529 , V_4 ) ;
F_129 ( & V_4 -> V_531 ) ;
V_4 -> V_4 = F_128 ( V_529 -> V_28 . V_467 ) ;
F_148 ( & V_529 -> V_28 ) ;
F_149 ( & V_529 -> V_28 ) ;
return F_150 ( & V_529 -> V_28 , & V_532 ,
V_494 , F_4 ( V_494 ) ) ;
}
static int F_151 ( struct V_528 * V_529 )
{
F_152 ( & V_529 -> V_28 ) ;
F_153 ( & V_529 -> V_28 ) ;
return 0 ;
}
static int F_154 ( struct V_416 * V_28 )
{
struct V_3 * V_4 = F_128 ( V_28 ) ;
if ( V_4 -> V_21 && ! V_4 -> V_104 )
F_155 ( V_4 -> V_4 -> V_415 , V_108 ,
V_109 ,
V_4 -> V_106 ) ;
return 0 ;
}
static int F_156 ( struct V_416 * V_28 )
{
struct V_3 * V_4 = F_128 ( V_28 ) ;
if ( V_4 -> V_21 && V_4 -> V_106 )
F_155 ( V_4 -> V_4 -> V_415 , V_108 ,
V_109 ,
V_105 ) ;
return 0 ;
}
