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
F_28 ( V_118 ,
& V_4 -> V_119 ,
F_29 ( 1000 ) ) ;
V_4 -> V_117 = true ;
}
break;
case V_120 :
F_8 ( V_2 ) ;
break;
}
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_31 ( V_2 -> V_28 ) ;
V_4 -> V_121 ++ ;
F_5 ( V_2 -> V_28 , L_16 ,
V_4 -> V_121 ) ;
if ( V_4 -> V_121 == 1 ) {
F_6 ( V_2 , V_122 ,
V_123 |
V_124 , 0 ) ;
F_32 ( V_2 ) ;
switch ( V_4 -> V_125 ) {
default:
F_33 ( NULL == L_17 ) ;
case V_126 :
F_6 ( V_2 , V_107 ,
V_127 |
V_128 |
V_129 |
V_130 |
V_131 ,
V_127 |
V_129 |
V_130 |
( 0x2 << V_132 ) ) ;
F_6 ( V_2 , V_133 ,
V_134 |
V_135 ,
V_134 | 0x2 ) ;
F_34 ( 300 ) ;
F_6 ( V_2 , V_107 ,
V_131 |
V_127 ,
0 ) ;
break;
case V_136 :
F_6 ( V_2 , V_107 ,
V_127 |
V_128 |
V_129 |
V_130 |
V_131 ,
V_127 |
V_129 |
V_130 |
( 0x2 << V_132 ) ) ;
F_6 ( V_2 , V_133 ,
V_134 |
V_135 ,
V_134 | 0x2 ) ;
F_34 ( 400 ) ;
F_6 ( V_2 , V_107 ,
V_131 |
V_127 ,
0 ) ;
break;
}
}
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_121 -- ;
F_5 ( V_2 -> V_28 , L_18 ,
V_4 -> V_121 ) ;
if ( V_4 -> V_121 == 0 ) {
if ( V_4 -> V_137 . V_138 )
F_6 ( V_2 , V_139 ,
V_140 |
V_141 ,
V_140 |
V_141 ) ;
if ( V_4 -> V_137 . V_142 )
F_6 ( V_2 , V_139 ,
V_143 |
V_144 ,
V_143 |
V_144 ) ;
F_6 ( V_2 , V_107 ,
V_127 |
V_128 ,
V_127 |
V_128 ) ;
F_6 ( V_2 , V_133 ,
V_135 , 0 ) ;
F_34 ( 400 ) ;
F_6 ( V_2 , V_122 ,
V_123 |
V_124 ,
V_123 |
V_124 ) ;
F_6 ( V_2 , V_139 ,
V_140 |
V_141 |
V_143 |
V_144 , 0 ) ;
F_6 ( V_2 , V_107 ,
V_127 |
V_129 |
V_130 |
V_131 , 0 ) ;
F_6 ( V_2 , V_133 ,
V_135 , 0 ) ;
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
case V_120 :
F_35 ( V_2 ) ;
break;
}
return 0 ;
}
static bool F_38 ( struct V_1 * V_2 )
{
int V_50 = 0 ;
int V_52 , V_145 ;
V_52 = F_3 ( V_2 , V_146 ) ;
switch ( V_52 ) {
case V_147 :
F_39 ( V_2 -> V_28 , L_19 ) ;
V_50 = 2 << V_148 ;
break;
case V_149 :
F_39 ( V_2 -> V_28 , L_20 ) ;
V_50 = 1 << V_148 ;
break;
case V_150 :
F_39 ( V_2 -> V_28 , L_21 ) ;
V_50 = 0 << V_148 ;
break;
default:
F_39 ( V_2 -> V_28 , L_22 , V_52 ) ;
return false ;
}
V_145 = F_3 ( V_2 , V_151 ) ;
if ( V_145 != V_52 ) {
F_39 ( V_2 -> V_28 , L_23 ) ;
return false ;
}
F_6 ( V_2 , V_152 ,
V_153 , V_50 ) ;
return true ;
}
static int F_40 ( struct V_49 * V_113 ,
struct V_55 * V_56 , int V_114 )
{
struct V_1 * V_2 = V_113 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
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
case V_120 :
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
case V_120 :
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
case V_120 :
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
case V_120 :
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
case V_120 :
if ( V_4 -> V_191 ) {
F_40 ( V_113 , V_56 , V_178 ) ;
F_6 ( V_2 , V_44 ,
V_194 , 0 ) ;
F_40 ( V_113 , V_56 , V_120 ) ;
V_4 -> V_191 = 0 ;
}
if ( V_4 -> V_193 ) {
F_42 ( V_113 , V_56 , V_178 ) ;
F_6 ( V_2 , V_196 ,
V_197 , 0 ) ;
F_42 ( V_113 , V_56 , V_120 ) ;
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
struct V_1 * V_2 = F_53 ( V_56 ) ;
int V_63 ;
V_63 = F_54 ( V_56 , V_58 ) ;
F_55 ( V_2 ) ;
return V_63 ;
}
static int F_56 ( struct V_4 * V_5 , struct V_200 * V_39 ,
int V_201 , int V_202 )
{
T_2 V_203 ;
unsigned int V_204 , V_205 , V_206 , V_207 ;
F_57 ( L_25 , V_201 , V_202 ) ;
V_39 -> V_208 = 0 ;
while ( V_201 > 13500000 ) {
V_39 -> V_208 ++ ;
V_201 /= 2 ;
if ( V_39 -> V_208 > 3 )
return - V_42 ;
}
F_57 ( L_26 , V_39 -> V_208 , V_201 ) ;
V_39 -> V_209 = 3 ;
while ( V_202 * ( V_39 -> V_209 + 1 ) < 90000000 ) {
V_39 -> V_209 ++ ;
if ( V_39 -> V_209 > 63 )
return - V_42 ;
}
V_202 *= V_39 -> V_209 + 1 ;
F_57 ( L_27 , V_39 -> V_209 , V_202 ) ;
if ( V_201 > 1000000 ) {
V_39 -> V_210 = 0 ;
} else if ( V_201 > 256000 ) {
V_39 -> V_210 = 1 ;
V_201 *= 2 ;
} else if ( V_201 > 128000 ) {
V_39 -> V_210 = 2 ;
V_201 *= 4 ;
} else if ( V_201 > 64000 ) {
V_39 -> V_210 = 3 ;
V_201 *= 8 ;
} else {
V_39 -> V_210 = 4 ;
V_201 *= 16 ;
}
F_57 ( L_28 , V_39 -> V_210 , V_201 ) ;
V_205 = V_202 / V_201 ;
V_39 -> V_211 = V_205 ;
V_206 = V_202 % V_201 ;
F_57 ( L_29 , V_206 ) ;
switch ( V_5 -> type ) {
case V_158 :
V_203 = V_212 * ( long long ) V_206 ;
F_58 ( V_203 , V_201 ) ;
V_204 = V_203 & 0xFFFFFFFF ;
if ( ( V_204 % 10 ) >= 5 )
V_204 += 5 ;
V_39 -> V_213 = V_204 / 10 ;
V_39 -> V_214 = 0 ;
F_57 ( L_30 , V_39 -> V_211 , V_39 -> V_213 ) ;
break;
default:
V_207 = F_59 ( V_202 , V_201 ) ;
V_39 -> V_213 = ( V_202 - ( V_201 * V_39 -> V_211 ) ) / V_207 ;
V_39 -> V_214 = V_201 / V_207 ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , int V_82 , int V_215 ,
unsigned int V_201 , unsigned int V_202 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_216 , V_63 ;
struct V_200 V_39 ;
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
if ( V_202 )
return - V_42 ;
V_215 = V_4 -> V_39 [ V_82 ] . V_215 ;
break;
case V_226 :
case V_227 :
case V_228 :
case V_229 :
break;
case V_230 :
V_201 = 12000000 ;
V_202 = 12000000 ;
break;
default:
return - V_42 ;
}
if ( V_4 -> V_39 [ V_82 ] . V_215 == V_215 &&
V_4 -> V_39 [ V_82 ] . V_231 == V_201 && V_4 -> V_39 [ V_82 ] . V_40 == V_202 )
return 0 ;
if ( V_202 )
V_63 = F_56 ( V_5 , & V_39 , V_201 , V_202 ) ;
else
V_63 = F_56 ( V_5 , & V_39 , V_4 -> V_39 [ V_82 ] . V_231 ,
V_4 -> V_39 [ V_82 ] . V_40 ) ;
if ( V_63 < 0 )
return V_63 ;
V_217 = F_3 ( V_2 , V_15 ) ;
if ( V_217 & V_16 )
V_218 = V_196 ;
else
V_218 = V_44 ;
V_52 = F_3 ( V_2 , V_218 ) ;
if ( ( V_52 & V_195 ) &&
( V_52 & V_45 ) == V_219 ) {
F_61 ( V_2 -> V_28 , L_31 ,
V_82 + 1 ) ;
return - V_232 ;
}
F_6 ( V_2 , V_224 + V_216 ,
V_225 , 0 ) ;
if ( V_4 -> V_233 && V_215 == V_229 &&
V_201 == V_202 && V_202 ) {
F_5 ( V_2 -> V_28 , L_32 , V_82 + 1 ) ;
F_6 ( V_2 , V_234 + V_216 ,
V_235 , V_235 ) ;
goto V_40;
}
V_52 = ( V_39 . V_209 << V_236 ) |
( V_39 . V_210 << V_237 ) ;
F_6 ( V_2 , V_238 + V_216 ,
V_239 |
V_240 , V_52 ) ;
F_6 ( V_2 , V_241 + V_216 ,
V_242 , V_39 . V_213 ) ;
F_6 ( V_2 , V_243 + V_216 ,
V_244 ,
V_39 . V_211 << V_245 ) ;
if ( V_39 . V_214 ) {
F_6 ( V_2 , V_246 + V_216 ,
V_247 ,
V_39 . V_214 ) ;
F_6 ( V_2 , V_248 + V_216 ,
V_249 , V_249 ) ;
} else {
F_6 ( V_2 , V_248 + V_216 ,
V_249 , 0 ) ;
}
F_6 ( V_2 , V_234 + V_216 ,
V_250 | V_235 |
V_251 |
V_252 ,
( ( V_215 == V_230 )
<< V_253 ) |
( V_39 . V_208 << V_254 ) |
( V_215 - 1 ) ) ;
F_62 ( & V_4 -> V_255 [ V_82 ] ) ;
if ( V_202 ) {
if ( ! V_221 ) {
F_23 ( V_2 ) ;
switch ( V_5 -> type ) {
case V_158 :
F_30 ( V_2 ) ;
break;
case V_159 :
if ( V_5 -> V_256 < 1 )
F_30 ( V_2 ) ;
break;
default:
break;
}
}
V_52 = V_225 ;
if ( V_39 . V_213 )
V_52 |= V_257 ;
if ( V_215 == V_230 )
V_52 |= V_258 ;
F_6 ( V_2 , V_224 + V_216 ,
V_225 | V_258 |
V_257 , V_52 ) ;
if ( V_4 -> V_259 ) {
V_220 = F_63 ( & V_4 -> V_255 [ V_82 ] ,
F_29 ( 10 ) ) ;
if ( V_220 == 0 )
F_64 ( V_2 -> V_28 ,
L_33 ) ;
} else {
F_34 ( 5 ) ;
}
} else {
if ( V_221 ) {
switch ( V_5 -> type ) {
case V_158 :
F_35 ( V_2 ) ;
break;
case V_159 :
if ( V_5 -> V_256 < 1 )
F_35 ( V_2 ) ;
break;
default:
break;
}
F_26 ( V_2 ) ;
}
}
V_40:
V_4 -> V_39 [ V_82 ] . V_231 = V_201 ;
V_4 -> V_39 [ V_82 ] . V_40 = V_202 ;
V_4 -> V_39 [ V_82 ] . V_215 = V_215 ;
F_8 ( V_2 ) ;
if ( F_65 ( V_4 -> V_17 [ 0 ] , V_4 -> V_17 [ 1 ] ) < 50000 ) {
F_5 ( V_2 -> V_28 , L_34 ) ;
V_4 -> V_260 [ 0 ] = F_3 ( V_2 , V_261 )
& V_262 ;
V_4 -> V_260 [ 1 ] = F_3 ( V_2 , V_263 )
& V_262 ;
F_6 ( V_2 , V_261 ,
V_262 , 0x1 ) ;
F_6 ( V_2 , V_263 ,
V_264 , 0x1 ) ;
} else if ( V_4 -> V_260 [ 0 ] ) {
F_6 ( V_2 , V_261 ,
V_262 ,
V_4 -> V_260 [ 0 ] ) ;
F_6 ( V_2 , V_263 ,
V_264 ,
V_4 -> V_260 [ 1 ] ) ;
V_4 -> V_260 [ 0 ] = 0 ;
V_4 -> V_260 [ 1 ] = 0 ;
}
return 0 ;
}
static T_3 F_66 ( int V_265 , void * V_266 )
{
struct V_267 * V_267 = V_266 ;
F_67 ( V_267 ) ;
return V_268 ;
}
static int F_68 ( struct V_269 * V_270 , int V_82 , int V_215 ,
unsigned int V_201 , unsigned int V_202 )
{
return F_60 ( V_270 -> V_2 , V_82 , V_215 , V_201 , V_202 ) ;
}
static int F_69 ( struct V_269 * V_270 ,
int V_271 , unsigned int V_272 , int V_273 )
{
struct V_1 * V_2 = V_270 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
switch ( V_270 -> V_82 ) {
case 1 :
case 2 :
break;
default:
return - V_42 ;
}
switch ( V_271 ) {
case V_35 :
V_4 -> V_8 [ V_270 -> V_82 - 1 ] = V_35 ;
V_4 -> V_36 [ 0 ] = V_272 ;
F_5 ( V_270 -> V_28 , L_35 ,
V_270 -> V_82 , V_272 ) ;
break;
case V_37 :
V_4 -> V_8 [ V_270 -> V_82 - 1 ] = V_37 ;
V_4 -> V_36 [ 1 ] = V_272 ;
F_5 ( V_270 -> V_28 , L_36 ,
V_270 -> V_82 , V_272 ) ;
break;
case V_38 :
V_4 -> V_8 [ V_270 -> V_82 - 1 ] = V_38 ;
F_5 ( V_270 -> V_28 , L_37 , V_270 -> V_82 ) ;
break;
case V_41 :
V_4 -> V_8 [ V_270 -> V_82 - 1 ] = V_41 ;
F_5 ( V_270 -> V_28 , L_38 , V_270 -> V_82 ) ;
break;
case V_274 :
if ( V_272 ) {
for ( V_7 = 0 ; V_7 < F_4 ( V_275 ) ; V_7 ++ )
if ( V_275 [ V_7 ] == V_272 )
break;
if ( V_7 == F_4 ( V_275 ) )
return - V_42 ;
F_6 ( V_2 , V_276 ,
V_277 , V_7 ) ;
F_6 ( V_2 , V_278 ,
V_279 , V_279 ) ;
} else {
F_6 ( V_2 , V_278 ,
V_279 , 0 ) ;
}
default:
return - V_42 ;
}
F_8 ( V_2 ) ;
if ( F_65 ( V_4 -> V_17 [ 0 ] , V_4 -> V_17 [ 1 ] ) < 50000 ) {
F_5 ( V_2 -> V_28 , L_34 ) ;
V_4 -> V_260 [ 0 ] = F_3 ( V_2 , V_261 )
& V_262 ;
V_4 -> V_260 [ 1 ] = F_3 ( V_2 , V_263 )
& V_262 ;
F_6 ( V_2 , V_261 ,
V_262 , 0x1 ) ;
F_6 ( V_2 , V_263 ,
V_264 , 0x1 ) ;
} else if ( V_4 -> V_260 [ 0 ] ) {
F_6 ( V_2 , V_261 ,
V_262 ,
V_4 -> V_260 [ 0 ] ) ;
F_6 ( V_2 , V_263 ,
V_264 ,
V_4 -> V_260 [ 1 ] ) ;
V_4 -> V_260 [ 0 ] = 0 ;
V_4 -> V_260 [ 1 ] = 0 ;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_2 ,
enum V_280 V_281 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
F_71 ( V_2 , V_281 ) ;
switch ( V_281 ) {
case V_282 :
break;
case V_283 :
switch ( V_5 -> type ) {
case V_159 :
case V_284 :
F_6 ( V_2 , V_285 ,
V_286 , 0 ) ;
F_6 ( V_2 , V_287 ,
V_288 , 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_48 . V_289 == V_290 )
F_23 ( V_2 ) ;
break;
case V_290 :
if ( V_2 -> V_48 . V_289 == V_291 ) {
switch ( V_5 -> type ) {
case V_159 :
if ( V_5 -> V_256 == 0 ) {
F_6 ( V_2 ,
V_292 ,
V_293 ,
V_293 ) ;
}
break;
default:
break;
}
F_6 ( V_2 , V_122 ,
V_123 |
V_124 ,
V_123 |
V_124 ) ;
}
if ( V_2 -> V_48 . V_289 == V_283 )
F_26 ( V_2 ) ;
switch ( V_5 -> type ) {
case V_159 :
case V_284 :
F_6 ( V_2 , V_285 ,
V_286 ,
V_286 ) ;
F_6 ( V_2 , V_287 ,
V_288 ,
V_288 ) ;
break;
default:
break;
}
break;
case V_291 :
if ( V_2 -> V_48 . V_289 == V_290 )
V_4 -> V_294 = NULL ;
break;
}
V_2 -> V_48 . V_289 = V_281 ;
return 0 ;
}
int F_72 ( struct V_1 * V_2 , enum F_72 V_100 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_100 ) {
case V_126 :
if ( V_4 -> V_137 . V_138 ) {
F_73 ( & V_2 -> V_48 ,
L_39 ) ;
F_73 ( & V_2 -> V_48 ,
L_40 ) ;
}
if ( V_4 -> V_137 . V_142 ) {
F_73 ( & V_2 -> V_48 ,
L_41 ) ;
F_73 ( & V_2 -> V_48 ,
L_42 ) ;
}
F_9 ( & V_2 -> V_48 ) ;
V_4 -> V_125 = V_100 ;
break;
case V_136 :
if ( V_4 -> V_137 . V_138 ) {
F_74 ( & V_2 -> V_48 ,
L_39 ) ;
F_74 ( & V_2 -> V_48 ,
L_40 ) ;
}
if ( V_4 -> V_137 . V_142 ) {
F_74 ( & V_2 -> V_48 ,
L_41 ) ;
F_74 ( & V_2 -> V_48 ,
L_42 ) ;
}
V_4 -> V_125 = V_100 ;
F_9 ( & V_2 -> V_48 ) ;
break;
default:
return - V_42 ;
}
return 0 ;
}
static int F_75 ( struct V_269 * V_270 , unsigned int V_295 )
{
struct V_1 * V_2 = V_270 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_296 ;
int V_297 ;
int V_298 ;
int V_299 ;
int V_300 = 0 ;
int V_301 = 0 ;
int V_302 = 0 ;
switch ( V_270 -> V_82 ) {
case 1 :
V_296 = V_303 ;
V_297 = V_163 ;
V_298 = V_304 ;
V_299 = V_305 ;
break;
case 2 :
V_296 = V_306 ;
V_297 = V_180 ;
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
case V_284 :
case V_159 :
if ( V_270 -> V_82 == 2 )
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
static int F_76 ( struct V_328 * V_329 ,
struct V_330 * V_331 ,
struct V_269 * V_270 )
{
struct V_1 * V_2 = V_270 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_70 * V_18 = & V_5 -> V_18 ;
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
int V_82 = V_270 -> V_82 - 1 ;
int V_7 , V_339 , V_90 , V_340 , V_6 ;
switch ( V_270 -> V_82 ) {
case 1 :
V_297 = V_163 ;
V_332 = V_170 ;
V_333 = V_341 ;
V_335 = V_261 ;
if ( V_329 -> V_342 == V_343 ||
V_4 -> V_344 [ 0 ] ) {
V_334 = V_304 ;
} else {
V_334 = V_305 ;
F_5 ( V_2 -> V_28 , L_43 ) ;
}
break;
case 2 :
V_297 = V_180 ;
V_332 = V_185 ;
V_333 = V_345 ;
V_335 = V_263 ;
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
V_340 = F_77 ( V_331 ) ;
switch ( F_78 ( V_331 ) ) {
case V_348 :
V_340 *= 16 ;
break;
case V_349 :
V_340 *= 20 ;
V_301 |= 0x20 ;
break;
case V_350 :
V_340 *= 24 ;
V_301 |= 0x40 ;
break;
case V_351 :
V_340 *= 32 ;
V_301 |= 0x60 ;
break;
default:
return - V_42 ;
}
V_4 -> V_162 [ V_82 ] = F_79 ( V_331 ) ;
if ( V_18 -> V_352 [ V_82 ] &&
V_4 -> V_162 [ V_82 ] > V_18 -> V_352 [ V_82 ] ) {
F_5 ( V_270 -> V_28 , L_45 ,
V_18 -> V_352 [ V_82 ] , V_4 -> V_162 [ V_82 ] ) ;
V_4 -> V_162 [ V_82 ] = V_18 -> V_352 [ V_82 ] ;
}
switch ( V_4 -> V_162 [ V_82 ] ) {
case 1 :
case 2 :
V_340 *= 2 ;
break;
default:
V_340 *= 4 ;
break;
}
for ( V_7 = 0 ; V_7 < F_4 ( V_353 ) ; V_7 ++ )
if ( V_353 [ V_7 ] . V_26 == F_77 ( V_331 ) )
break;
if ( V_7 == F_4 ( V_353 ) )
return - V_42 ;
V_338 |= V_353 [ V_7 ] . V_9 << V_354 ;
F_5 ( V_270 -> V_28 , L_46 , V_353 [ V_7 ] . V_26 ) ;
F_5 ( V_270 -> V_28 , L_47 ,
V_270 -> V_82 , V_4 -> V_17 [ V_82 ] , V_340 ) ;
if ( V_4 -> V_162 [ V_82 ] == 1 &&
( F_3 ( V_2 , V_297 ) & 0x18 ) == 0x18 )
V_336 |= V_355 ;
if ( V_4 -> V_17 [ V_82 ] == 0 ) {
F_61 ( V_270 -> V_28 , L_48 , V_270 -> V_82 ) ;
return - V_42 ;
}
V_6 = 0 ;
V_90 = abs ( ( V_356 [ 0 ] * F_77 ( V_331 ) )
- V_4 -> V_17 [ V_82 ] ) ;
for ( V_7 = 1 ; V_7 < F_4 ( V_356 ) ; V_7 ++ ) {
V_339 = abs ( ( V_356 [ V_7 ] * F_77 ( V_331 ) )
- V_4 -> V_17 [ V_82 ] ) ;
if ( V_339 >= V_90 )
continue;
V_6 = V_7 ;
V_90 = V_339 ;
}
F_5 ( V_270 -> V_28 , L_49 ,
V_270 -> V_82 , V_356 [ V_6 ] ) ;
V_338 |= V_6 ;
V_6 = 0 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_357 ) ; V_7 ++ ) {
V_339 = ( V_4 -> V_17 [ V_82 ] * 10 / V_357 [ V_7 ] ) - V_340 ;
if ( V_339 < 0 )
break;
V_6 = V_7 ;
}
V_340 = V_4 -> V_17 [ V_82 ] * 10 / V_357 [ V_6 ] ;
F_5 ( V_270 -> V_28 , L_50 ,
V_357 [ V_6 ] , V_340 ) ;
V_337 |= V_6 << V_358 ;
V_302 = V_340 / F_77 ( V_331 ) ;
if ( ! V_302 ) {
F_61 ( V_270 -> V_28 , L_51 ,
V_340 ) ;
return - V_42 ;
}
F_5 ( V_270 -> V_28 , L_52 ,
V_302 , V_340 / V_302 ) ;
F_6 ( V_2 , V_297 , V_359 , V_301 ) ;
F_6 ( V_2 , V_332 , V_355 , V_336 ) ;
F_6 ( V_2 , V_333 , V_360 , V_337 ) ;
F_6 ( V_2 , V_334 , V_361 ,
V_302 ) ;
F_6 ( V_2 , V_335 , V_362 |
V_262 , V_338 ) ;
if ( V_329 -> V_342 == V_343 ) {
switch ( V_270 -> V_82 ) {
case 1 :
V_4 -> V_97 [ 0 ] = F_77 ( V_331 ) ;
F_18 ( V_2 , 0 ) ;
F_18 ( V_2 , 1 ) ;
break;
case 2 :
V_4 -> V_97 [ 1 ] = F_77 ( V_331 ) ;
F_18 ( V_2 , 2 ) ;
break;
}
}
return 0 ;
}
static int F_80 ( struct V_328 * V_329 ,
struct V_330 * V_331 ,
struct V_269 * V_270 )
{
struct V_1 * V_2 = V_270 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_297 ;
int V_301 = 0 ;
switch ( V_270 -> V_82 ) {
case 3 :
switch ( V_5 -> type ) {
case V_284 :
case V_159 :
V_297 = V_325 ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
switch ( F_78 ( V_331 ) ) {
case V_348 :
break;
case V_349 :
V_301 |= 0x20 ;
break;
case V_350 :
V_301 |= 0x40 ;
break;
case V_351 :
V_301 |= 0x60 ;
break;
default:
return - V_42 ;
}
return F_6 ( V_2 , V_297 , V_359 , V_301 ) ;
}
static int F_81 ( struct V_269 * V_363 , int V_364 )
{
struct V_1 * V_2 = V_363 -> V_2 ;
int V_365 ;
int V_52 ;
switch ( V_363 -> V_82 ) {
case 1 :
V_365 = V_366 ;
break;
case 2 :
V_365 = V_367 ;
break;
default:
return - V_42 ;
}
if ( V_364 )
V_52 = V_368 ;
else
V_52 = 0 ;
F_6 ( V_2 , V_365 , V_368 , V_52 ) ;
return 0 ;
}
static int F_82 ( struct V_269 * V_363 , int V_369 )
{
struct V_1 * V_2 = V_363 -> V_2 ;
int V_52 , V_9 , V_62 ;
switch ( V_363 -> V_82 ) {
case 1 :
V_52 = V_303 ;
V_62 = V_370 ;
break;
case 2 :
V_52 = V_306 ;
V_62 = V_371 ;
break;
default:
return - V_42 ;
}
if ( V_369 )
V_9 = V_62 ;
else
V_9 = 0 ;
return F_6 ( V_2 , V_52 , V_62 , V_9 ) ;
}
static int F_83 ( struct V_269 * V_270 )
{
struct V_1 * V_2 = V_270 -> V_2 ;
F_6 ( V_2 , V_372 ,
V_373 | V_374 , 0 ) ;
F_6 ( V_2 , V_375 ,
V_373 | V_374 , 0 ) ;
F_6 ( V_2 , V_376 ,
V_373 | V_374 , 0 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 , V_63 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_39 ) ; V_7 ++ ) {
memcpy ( & V_4 -> V_377 [ V_7 ] , & V_4 -> V_39 [ V_7 ] ,
sizeof( struct V_378 ) ) ;
V_63 = F_60 ( V_2 , V_7 + 1 , 0 , 0 , 0 ) ;
if ( V_63 < 0 )
F_64 ( V_2 -> V_28 , L_53 ,
V_7 + 1 , V_63 ) ;
}
F_70 ( V_2 , V_291 ) ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 , V_63 ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_39 ) ; V_7 ++ ) {
if ( ! V_4 -> V_377 [ V_7 ] . V_40 )
continue;
V_63 = F_60 ( V_2 , V_7 + 1 ,
V_4 -> V_377 [ V_7 ] . V_215 ,
V_4 -> V_377 [ V_7 ] . V_231 ,
V_4 -> V_377 [ V_7 ] . V_40 ) ;
if ( V_63 < 0 )
F_64 ( V_2 -> V_28 , L_54 ,
V_7 + 1 , V_63 ) ;
}
return 0 ;
}
static void F_86 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_137 . V_2 ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_70 * V_18 = & V_5 -> V_18 ;
struct V_379 V_380 [] = {
F_87 ( L_11 ,
V_4 -> V_381 ,
F_21 ,
F_20 ) ,
F_87 ( L_12 ,
V_4 -> V_381 ,
F_21 ,
F_20 ) ,
F_87 ( L_13 ,
V_4 -> V_381 ,
F_21 ,
F_20 ) ,
} ;
int V_63 , V_7 , V_382 ;
const char * * V_383 ;
V_4 -> V_91 = 0 ;
V_4 -> V_96 = NULL ;
for ( V_7 = 0 ; V_7 < V_18 -> V_94 ; V_7 ++ ) {
for ( V_382 = 0 ; V_382 < V_4 -> V_91 ; V_382 ++ ) {
if ( strcmp ( V_18 -> V_95 [ V_7 ] . V_54 ,
V_4 -> V_96 [ V_382 ] ) == 0 )
break;
}
if ( V_382 != V_4 -> V_91 )
continue;
V_383 = F_88 ( V_4 -> V_96 ,
sizeof( char * ) *
( V_4 -> V_91 + 1 ) ,
V_384 ) ;
if ( V_383 == NULL )
continue;
V_383 [ V_4 -> V_91 ] =
V_18 -> V_95 [ V_7 ] . V_54 ;
V_4 -> V_91 ++ ;
V_4 -> V_96 = V_383 ;
}
F_5 ( V_2 -> V_28 , L_55 ,
V_4 -> V_91 ) ;
V_4 -> V_381 . F_65 = V_4 -> V_91 ;
V_4 -> V_381 . V_385 = V_4 -> V_96 ;
V_63 = F_89 ( V_4 -> V_137 . V_2 , V_380 ,
F_4 ( V_380 ) ) ;
if ( V_63 != 0 )
F_61 ( V_4 -> V_137 . V_2 -> V_28 ,
L_56 , V_63 ) ;
}
static void F_90 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_137 . V_2 ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_70 * V_18 = & V_5 -> V_18 ;
int V_63 , V_7 ;
if ( ! V_18 )
return;
F_91 ( V_2 , V_18 -> V_386 ,
V_18 -> V_387 ,
V_18 -> V_388 ,
V_18 -> V_389 ,
V_18 -> V_390 ,
V_18 -> V_391 ,
V_18 -> V_392 ,
V_18 -> V_393 ,
V_18 -> V_394 ,
V_18 -> V_395 ) ;
F_5 ( V_2 -> V_28 , L_57 , V_18 -> V_84 ) ;
if ( V_18 -> V_84 ) {
struct V_379 V_380 [] = {
F_87 ( L_7 , V_4 -> V_396 ,
F_17 , F_16 ) ,
F_87 ( L_8 , V_4 -> V_396 ,
F_17 , F_16 ) ,
F_87 ( L_9 , V_4 -> V_396 ,
F_17 , F_16 ) ,
} ;
V_4 -> V_397 = F_92 ( V_4 -> V_137 . V_2 -> V_28 ,
sizeof( char * ) * V_18 -> V_84 , V_384 ) ;
if ( ! V_4 -> V_397 ) {
F_61 ( V_4 -> V_137 . V_2 -> V_28 ,
L_58 ,
V_18 -> V_84 ) ;
return;
}
for ( V_7 = 0 ; V_7 < V_18 -> V_84 ; V_7 ++ )
V_4 -> V_397 [ V_7 ] = V_18 -> V_80 [ V_7 ] . V_54 ;
V_4 -> V_396 . F_65 = V_18 -> V_84 ;
V_4 -> V_396 . V_385 = V_4 -> V_397 ;
V_63 = F_89 ( V_4 -> V_137 . V_2 , V_380 ,
F_4 ( V_380 ) ) ;
for ( V_7 = 0 ; V_7 < V_398 ; V_7 ++ )
F_14 ( V_2 , V_7 ) ;
} else {
V_63 = F_89 ( V_4 -> V_137 . V_2 ,
V_399 ,
F_4 ( V_399 ) ) ;
}
if ( V_63 != 0 )
F_61 ( V_4 -> V_137 . V_2 -> V_28 ,
L_59 , V_63 ) ;
F_5 ( V_2 -> V_28 , L_60 ,
V_18 -> V_94 ) ;
if ( V_18 -> V_94 )
F_86 ( V_4 ) ;
else
F_89 ( V_4 -> V_137 . V_2 , V_400 ,
F_4 ( V_400 ) ) ;
for ( V_7 = 0 ; V_7 < F_4 ( V_18 -> V_401 ) ; V_7 ++ ) {
if ( V_18 -> V_401 [ V_7 ] ) {
F_41 ( V_2 , V_285 + V_7 ,
V_18 -> V_401 [ V_7 ] & 0xffff ) ;
}
}
}
int F_93 ( struct V_1 * V_2 , struct V_402 * V_102 ,
int V_401 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_403 * V_101 ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_52 , V_63 ;
if ( V_5 -> type != V_158 ) {
F_64 ( V_2 -> V_28 , L_61 ) ;
return - V_42 ;
}
switch ( V_401 ) {
case 1 :
V_101 = & V_4 -> V_101 [ 0 ] ;
if ( V_102 )
V_63 = F_74 ( & V_2 -> V_48 ,
L_62 ) ;
else
V_63 = F_73 ( & V_2 -> V_48 ,
L_62 ) ;
break;
case 2 :
V_101 = & V_4 -> V_101 [ 1 ] ;
if ( V_102 )
V_63 = F_74 ( & V_2 -> V_48 ,
L_62 ) ;
else
V_63 = F_73 ( & V_2 -> V_48 ,
L_62 ) ;
break;
default:
F_64 ( V_2 -> V_28 , L_63 , V_401 ) ;
return - V_42 ;
}
if ( V_63 != 0 )
F_64 ( V_2 -> V_28 , L_64 ,
V_401 , V_63 ) ;
F_5 ( V_2 -> V_28 , L_65 ,
V_401 , V_102 ) ;
V_101 -> V_102 = V_102 ;
V_101 -> V_404 = true ;
if ( V_4 -> V_101 [ 0 ] . V_102 || V_4 -> V_101 [ 1 ] . V_102 )
V_52 = V_405 ;
else
V_52 = 0 ;
F_6 ( V_2 , V_406 , V_405 , V_52 ) ;
F_6 ( V_2 , V_407 ,
V_408 | V_409 |
V_410 | V_411 ,
V_412 | V_413 ) ;
F_9 ( & V_2 -> V_48 ) ;
return 0 ;
}
static void F_94 ( struct V_414 * V_415 )
{
struct V_3 * V_416 = F_95 ( V_415 ,
struct V_3 ,
V_417 . V_415 ) ;
struct V_418 * V_418 = V_416 -> V_4 -> V_418 ;
struct V_419 * V_28 = V_416 -> V_4 -> V_28 ;
unsigned int V_52 ;
int V_63 ;
int V_420 ;
F_31 ( V_28 ) ;
V_63 = F_96 ( V_418 , V_421 , & V_52 ) ;
if ( V_63 < 0 ) {
F_61 ( V_28 , L_66 ,
V_63 ) ;
F_36 ( V_28 ) ;
return;
}
F_5 ( V_28 , L_67 , V_52 ) ;
V_420 = 0 ;
if ( V_52 & V_422 ) {
if ( V_416 -> V_101 [ 0 ] . V_404 )
V_420 = V_423 ;
}
if ( V_52 & V_424 ) {
if ( V_416 -> V_101 [ 0 ] . V_404 )
V_420 = V_425 ;
else
V_420 |= V_426 ;
}
if ( V_420 )
V_416 -> V_101 [ 0 ] . V_404 = false ;
else
V_416 -> V_101 [ 0 ] . V_404 = true ;
F_97 ( V_416 -> V_101 [ 0 ] . V_102 , V_420 ,
V_423 | V_426 ) ;
V_420 = 0 ;
if ( V_52 & V_427 ) {
if ( V_416 -> V_101 [ 1 ] . V_404 )
V_420 = V_423 ;
}
if ( V_52 & V_428 ) {
if ( V_416 -> V_101 [ 1 ] . V_404 )
V_420 = V_425 ;
else
V_420 |= V_426 ;
}
if ( V_420 )
V_416 -> V_101 [ 1 ] . V_404 = false ;
else
V_416 -> V_101 [ 1 ] . V_404 = true ;
F_97 ( V_416 -> V_101 [ 1 ] . V_102 , V_420 ,
V_423 | V_426 ) ;
F_36 ( V_28 ) ;
}
static T_3 F_98 ( int V_265 , void * V_266 )
{
struct V_3 * V_416 = V_266 ;
struct V_1 * V_2 = V_416 -> V_137 . V_2 ;
#ifndef F_99
F_100 ( F_101 ( V_2 -> V_28 ) ) ;
#endif
F_102 ( V_2 -> V_28 , 300 ) ;
F_28 ( V_118 ,
& V_416 -> V_417 , F_29 ( 250 ) ) ;
return V_268 ;
}
static void F_103 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_21 )
return;
F_24 ( & V_4 -> V_109 ) ;
F_6 ( V_2 , V_29 , V_429 , 0 ) ;
F_22 ( V_2 , V_112 ) ;
F_25 ( & V_4 -> V_109 ) ;
if ( V_4 -> V_4 -> V_18 . V_430 )
F_73 ( & V_2 -> V_48 ,
L_68 ) ;
}
static void F_104 ( struct V_1 * V_2 , T_1 V_431 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_420 ;
V_420 = 0 ;
if ( V_431 & 0x4 )
V_420 |= V_426 ;
if ( V_431 & 0x8 )
V_420 |= V_432 ;
if ( V_431 & 0x10 )
V_420 |= V_433 ;
if ( V_431 & 0x20 )
V_420 |= V_434 ;
if ( V_431 & 0x40 )
V_420 |= V_435 ;
if ( V_431 & 0x80 )
V_420 |= V_436 ;
F_97 ( V_4 -> V_101 [ 0 ] . V_102 , V_420 ,
V_4 -> V_437 ) ;
}
static void F_105 ( struct V_414 * V_415 )
{
struct V_3 * V_4 = F_95 ( V_415 ,
struct V_3 ,
V_438 . V_415 ) ;
struct V_419 * V_28 = V_4 -> V_4 -> V_28 ;
F_103 ( V_4 -> V_137 . V_2 ) ;
F_24 ( & V_4 -> V_109 ) ;
F_5 ( V_28 , L_69 ) ;
V_4 -> V_14 = false ;
V_4 -> V_110 = true ;
F_1 ( V_4 -> V_137 . V_2 ) ;
F_97 ( V_4 -> V_101 [ 0 ] . V_102 , 0 ,
V_4 -> V_437 |
V_423 ) ;
F_25 ( & V_4 -> V_109 ) ;
}
static void F_106 ( void * V_266 , T_1 V_431 )
{
struct V_1 * V_2 = V_266 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! ( V_431 & V_439 ) ) {
F_5 ( V_2 -> V_28 , L_70 ) ;
F_28 ( V_118 ,
& V_4 -> V_438 ,
F_29 ( 2500 ) ) ;
return;
}
if ( V_431 & 0x600 ) {
F_5 ( V_2 -> V_28 , L_71 ) ;
V_4 -> V_110 = false ;
V_4 -> V_14 = true ;
F_1 ( V_2 ) ;
F_97 ( V_4 -> V_101 [ 0 ] . V_102 , V_423 ,
V_423 ) ;
}
if ( V_431 & 0xfc ) {
F_5 ( V_2 -> V_28 , L_72 ) ;
V_4 -> V_110 = false ;
F_1 ( V_2 ) ;
F_103 ( V_2 ) ;
F_97 ( V_4 -> V_101 [ 0 ] . V_102 , V_425 ,
V_423 ) ;
}
}
static void F_107 ( struct V_414 * V_415 )
{
struct V_3 * V_4 = F_95 ( V_415 , struct V_3 ,
V_417 . V_415 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_1 * V_2 = V_4 -> V_137 . V_2 ;
F_31 ( V_2 -> V_28 ) ;
if ( V_5 -> V_18 . V_430 ) {
F_74 ( & V_2 -> V_48 ,
L_68 ) ;
F_9 ( & V_2 -> V_48 ) ;
}
F_24 ( & V_4 -> V_109 ) ;
F_5 ( V_2 -> V_28 , L_73 ) ;
if ( V_4 -> V_440 ) {
V_4 -> V_440 ( V_4 -> V_441 ) ;
} else {
V_4 -> V_110 = true ;
F_22 ( V_2 , V_111 ) ;
F_6 ( V_2 , V_29 ,
V_429 , V_429 ) ;
}
F_25 ( & V_4 -> V_109 ) ;
F_36 ( V_2 -> V_28 ) ;
}
static T_3 F_108 ( int V_265 , void * V_266 )
{
struct V_3 * V_4 = V_266 ;
struct V_4 * V_5 = V_4 -> V_4 ;
struct V_1 * V_2 = V_4 -> V_137 . V_2 ;
int V_52 , V_442 ;
bool V_443 ;
F_31 ( V_2 -> V_28 ) ;
F_109 ( & V_4 -> V_444 ) ;
F_24 ( & V_4 -> V_109 ) ;
V_52 = F_3 ( V_2 , V_445 ) ;
if ( V_52 < 0 ) {
F_61 ( V_2 -> V_28 , L_74 , V_52 ) ;
F_25 ( & V_4 -> V_109 ) ;
F_36 ( V_2 -> V_28 ) ;
return V_446 ;
}
F_5 ( V_2 -> V_28 , L_75 , V_52 ) ;
V_443 = V_52 & V_447 ;
if ( V_443 ) {
F_5 ( V_2 -> V_28 , L_76 ) ;
F_1 ( V_2 ) ;
F_6 ( V_2 , V_287 ,
V_448 , 0 ) ;
F_6 ( V_2 , V_445 ,
V_449 , 0 ) ;
V_442 = V_5 -> V_18 . V_450 ;
F_28 ( V_118 ,
& V_4 -> V_417 ,
F_29 ( V_442 ) ) ;
} else {
F_5 ( V_2 -> V_28 , L_77 ) ;
F_109 ( & V_4 -> V_417 ) ;
F_6 ( V_2 , V_287 ,
V_448 , V_448 ) ;
F_6 ( V_2 , V_445 ,
V_449 , V_449 ) ;
V_4 -> V_110 = false ;
V_4 -> V_14 = false ;
F_6 ( V_2 , V_29 ,
V_429 , 0 ) ;
F_22 ( V_2 , V_112 ) ;
}
F_25 ( & V_4 -> V_109 ) ;
if ( V_5 -> V_18 . V_430 && ! V_443 )
F_73 ( & V_2 -> V_48 , L_68 ) ;
if ( V_443 )
F_97 ( V_4 -> V_101 [ 0 ] . V_102 ,
V_451 , V_451 ) ;
else
F_97 ( V_4 -> V_101 [ 0 ] . V_102 , 0 ,
V_451 | V_423 |
V_4 -> V_437 ) ;
F_97 ( V_4 -> V_101 [ 0 ] . V_102 , 0 , 0 ) ;
F_36 ( V_2 -> V_28 ) ;
return V_268 ;
}
static void F_110 ( struct V_414 * V_415 )
{
struct V_3 * V_4 = F_95 ( V_415 ,
struct V_3 ,
V_119 . V_415 ) ;
F_108 ( 0 , V_4 ) ;
}
int F_111 ( struct V_1 * V_2 , struct V_402 * V_102 ,
T_4 V_452 , void * V_453 ,
T_5 V_454 , void * V_455 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
T_1 V_456 ;
switch ( V_5 -> type ) {
case V_284 :
case V_159 :
break;
default:
return - V_42 ;
}
if ( V_102 ) {
F_74 ( & V_2 -> V_48 , L_78 ) ;
F_9 ( & V_2 -> V_48 ) ;
V_4 -> V_101 [ 0 ] . V_102 = V_102 ;
if ( V_452 ) {
V_4 -> V_440 = V_452 ;
V_4 -> V_441 = V_453 ;
} else {
V_4 -> V_110 = true ;
V_4 -> V_14 = false ;
}
if ( V_454 ) {
V_4 -> V_457 = V_454 ;
V_4 -> V_458 = V_455 ;
} else {
V_4 -> V_457 = F_106 ;
V_4 -> V_458 = V_2 ;
}
F_1 ( V_2 ) ;
if ( V_5 -> V_18 . V_456 )
V_456 = V_5 -> V_18 . V_456 ;
else
V_456 = 0x41 ;
V_4 -> V_437 = V_426 | V_432 |
V_433 | V_434 |
V_435 | V_436 ;
F_6 ( V_2 , V_459 ,
V_460 , V_456 ) ;
F_33 ( V_2 -> V_48 . V_289 > V_290 ) ;
if ( V_4 -> V_21 ) {
F_6 ( V_2 , V_445 ,
V_449 , 0 ) ;
F_6 ( V_2 , V_287 ,
V_448 ,
V_448 ) ;
F_6 ( V_2 , V_461 ,
V_462 , 0 ) ;
F_22 ( V_2 ,
V_112 ) ;
} else {
F_6 ( V_2 , V_29 ,
V_429 , V_429 ) ;
}
} else {
F_6 ( V_2 , V_29 ,
V_429 , 0 ) ;
F_22 ( V_2 , V_106 ) ;
F_73 ( & V_2 -> V_48 , L_78 ) ;
F_9 ( & V_2 -> V_48 ) ;
}
return 0 ;
}
static void F_112 ( struct V_414 * V_415 )
{
struct V_3 * V_4 = F_95 ( V_415 ,
struct V_3 ,
V_444 . V_415 ) ;
struct V_1 * V_2 = V_4 -> V_137 . V_2 ;
F_31 ( V_2 -> V_28 ) ;
F_24 ( & V_4 -> V_109 ) ;
V_4 -> V_457 ( V_4 -> V_458 , V_4 -> V_463 ) ;
F_25 ( & V_4 -> V_109 ) ;
F_36 ( V_2 -> V_28 ) ;
}
static T_3 F_113 ( int V_265 , void * V_266 )
{
struct V_3 * V_4 = V_266 ;
struct V_1 * V_2 = V_4 -> V_137 . V_2 ;
int V_52 , V_464 , V_63 , V_465 ;
if ( ! ( F_3 ( V_2 , V_29 ) & V_429 ) )
return V_268 ;
F_109 ( & V_4 -> V_444 ) ;
F_109 ( & V_4 -> V_438 ) ;
F_31 ( V_2 -> V_28 ) ;
V_464 = 10 ;
do {
V_52 = F_3 ( V_2 , V_466 ) ;
if ( V_52 < 0 ) {
F_61 ( V_2 -> V_28 ,
L_79 ,
V_52 ) ;
F_36 ( V_2 -> V_28 ) ;
return V_446 ;
}
if ( ! ( V_52 & V_467 ) ) {
F_5 ( V_2 -> V_28 , L_80 ) ;
goto V_40;
}
if ( ! ( V_52 & V_439 ) || ( V_52 & V_468 ) )
break;
F_34 ( 1 ) ;
} while ( V_464 -- );
if ( V_464 == 0 )
F_64 ( V_2 -> V_28 , L_81 ) ;
#ifndef F_99
F_100 ( F_101 ( V_2 -> V_28 ) ) ;
#endif
if ( V_4 -> V_21 ) {
V_63 = F_3 ( V_2 , V_445 ) ;
if ( V_63 < 0 ) {
F_61 ( V_2 -> V_28 , L_74 ,
V_63 ) ;
} else if ( ! ( V_63 & V_447 ) ) {
F_5 ( V_2 -> V_28 , L_82 ) ;
goto V_40;
}
} else if ( ! ( V_52 & V_439 ) ) {
F_97 ( V_4 -> V_101 [ 0 ] . V_102 , 0 ,
V_451 | V_423 |
V_4 -> V_437 ) ;
V_4 -> V_110 = true ;
goto V_40;
}
V_4 -> V_463 = V_52 ;
V_465 = V_4 -> V_4 -> V_18 . V_469 ;
if ( V_4 -> V_110 )
F_28 ( V_118 ,
& V_4 -> V_444 ,
F_29 ( V_465 ) ) ;
else
F_104 ( V_2 , V_52 ) ;
V_40:
F_36 ( V_2 -> V_28 ) ;
return V_268 ;
}
static T_3 F_114 ( int V_265 , void * V_266 )
{
struct V_1 * V_2 = V_266 ;
F_61 ( V_2 -> V_28 , L_83 ) ;
return V_268 ;
}
static T_3 F_115 ( int V_265 , void * V_266 )
{
struct V_1 * V_2 = V_266 ;
F_61 ( V_2 -> V_28 , L_84 ) ;
return V_268 ;
}
static T_3 F_116 ( int V_265 , void * V_266 )
{
struct V_1 * V_2 = V_266 ;
F_117 ( V_2 -> V_28 , L_85 ) ;
return V_268 ;
}
static int F_118 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_119 ( V_2 -> V_28 -> V_470 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_471 * V_48 = & V_2 -> V_48 ;
unsigned int V_52 ;
int V_63 , V_7 ;
V_4 -> V_137 . V_2 = V_2 ;
V_2 -> V_472 = V_5 -> V_418 ;
F_120 ( V_2 , 16 , 16 , V_473 ) ;
F_121 ( & V_4 -> V_109 ) ;
F_122 ( & V_4 -> V_119 ,
F_110 ) ;
F_122 ( & V_4 -> V_438 ,
F_105 ) ;
switch ( V_5 -> type ) {
case V_158 :
F_122 ( & V_4 -> V_417 , F_94 ) ;
break;
case V_284 :
F_122 ( & V_4 -> V_417 , F_107 ) ;
break;
default:
break;
}
F_122 ( & V_4 -> V_444 , F_112 ) ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_255 ) ; V_7 ++ )
F_123 ( & V_4 -> V_255 [ V_7 ] ) ;
V_4 -> V_474 = V_5 -> V_18 . V_474 ;
V_2 -> V_48 . V_475 = 1 ;
switch ( V_5 -> type ) {
case V_158 :
if ( ! V_5 -> V_18 . V_386 ||
! V_5 -> V_18 . V_387 )
V_2 -> V_48 . V_475 = 0 ;
switch ( V_5 -> V_256 ) {
case 2 :
case 3 :
V_4 -> V_137 . V_476 = - 5 ;
V_4 -> V_137 . V_477 = - 5 ;
V_4 -> V_137 . V_478 = 1 ;
V_4 -> V_137 . V_479 = 1 ;
V_4 -> V_137 . V_480 = 1 ;
break;
default:
V_4 -> V_137 . V_479 = 2 ;
break;
}
break;
case V_159 :
V_4 -> V_137 . V_479 = 1 ;
V_4 -> V_137 . V_478 = 1 ;
switch ( V_5 -> V_256 ) {
case 0 :
break;
default:
V_4 -> V_233 = true ;
break;
}
break;
case V_284 :
V_4 -> V_137 . V_479 = 2 ;
V_4 -> V_137 . V_481 = 1 ;
V_4 -> V_137 . V_478 = 1 ;
V_4 -> V_137 . V_482 = true ;
V_4 -> V_233 = true ;
V_4 -> V_137 . V_476 = - 9 ;
V_4 -> V_137 . V_477 = - 7 ;
F_6 ( V_2 , V_483 ,
V_484 , V_484 ) ;
break;
default:
break;
}
F_124 ( V_4 -> V_4 , V_485 ,
F_114 , L_86 , V_2 ) ;
F_124 ( V_4 -> V_4 , V_486 ,
F_115 , L_87 , V_2 ) ;
F_124 ( V_4 -> V_4 , V_487 ,
F_116 , L_88 , V_2 ) ;
V_63 = F_124 ( V_4 -> V_4 , V_488 ,
V_489 , L_89 ,
& V_4 -> V_137 ) ;
if ( V_63 == 0 )
V_4 -> V_137 . V_490 = true ;
switch ( V_5 -> type ) {
case V_158 :
if ( V_4 -> V_474 ) {
V_63 = F_125 ( V_4 -> V_474 , NULL ,
F_98 ,
V_491 ,
L_90 ,
V_4 ) ;
if ( V_63 != 0 )
F_64 ( V_2 -> V_28 ,
L_91 ,
V_63 ) ;
}
V_63 = F_124 ( V_4 -> V_4 ,
V_492 ,
F_98 , L_92 ,
V_4 ) ;
if ( V_63 != 0 )
F_64 ( V_2 -> V_28 ,
L_93 ,
V_63 ) ;
V_63 = F_124 ( V_4 -> V_4 ,
V_493 ,
F_98 , L_94 ,
V_4 ) ;
if ( V_63 != 0 )
F_64 ( V_2 -> V_28 ,
L_95 ,
V_63 ) ;
V_63 = F_124 ( V_4 -> V_4 ,
V_494 ,
F_98 , L_96 ,
V_4 ) ;
if ( V_63 != 0 )
F_64 ( V_2 -> V_28 ,
L_97 ,
V_63 ) ;
break;
case V_159 :
case V_284 :
if ( V_4 -> V_474 ) {
V_63 = F_125 ( V_4 -> V_474 , NULL ,
F_113 ,
V_491 ,
L_98 ,
V_4 ) ;
if ( V_63 != 0 )
F_64 ( V_2 -> V_28 ,
L_99 ,
V_63 ) ;
} else {
F_124 ( V_4 -> V_4 , V_495 ,
F_113 , L_98 ,
V_4 ) ;
}
}
switch ( V_5 -> type ) {
case V_284 :
if ( V_5 -> V_496 > 1 || V_5 -> V_256 > 1 ) {
V_63 = F_124 ( V_4 -> V_4 ,
F_126 ( 6 ) ,
F_108 , L_100 ,
V_4 ) ;
if ( V_63 == 0 )
V_4 -> V_21 = true ;
}
break;
default:
break;
}
V_4 -> V_259 = true ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_255 ) ; V_7 ++ ) {
V_63 = F_124 ( V_4 -> V_4 ,
V_497 + V_7 ,
F_66 , L_101 ,
& V_4 -> V_255 [ V_7 ] ) ;
if ( V_63 != 0 )
V_4 -> V_259 = false ;
}
F_31 ( V_2 -> V_28 ) ;
V_63 = F_96 ( V_5 -> V_418 , V_498 , & V_52 ) ;
if ( V_63 < 0 ) {
F_61 ( V_2 -> V_28 , L_102 , V_63 ) ;
goto V_499;
}
if ( ( V_52 & V_500 ) != V_501 ) {
V_4 -> V_344 [ 0 ] = 1 ;
V_502 [ 0 ] . V_503 = 1 ;
} else {
V_4 -> V_344 [ 0 ] = 0 ;
}
V_63 = F_96 ( V_5 -> V_418 , V_504 , & V_52 ) ;
if ( V_63 < 0 ) {
F_61 ( V_2 -> V_28 , L_103 , V_63 ) ;
goto V_499;
}
if ( ( V_52 & V_500 ) != V_501 ) {
V_4 -> V_344 [ 1 ] = 1 ;
V_502 [ 1 ] . V_503 = 1 ;
} else {
V_4 -> V_344 [ 1 ] = 0 ;
}
F_36 ( V_2 -> V_28 ) ;
for ( V_7 = 0 ; V_7 < F_4 ( V_177 ) ; V_7 ++ )
F_6 ( V_2 , V_177 [ V_7 ] . V_52 ,
V_177 [ V_7 ] . V_62 ,
V_177 [ V_7 ] . V_62 ) ;
F_6 ( V_2 , V_505 ,
1 << V_506 ,
1 << V_506 ) ;
F_6 ( V_2 , V_507 ,
1 << V_508 ,
1 << V_508 ) ;
F_6 ( V_2 , V_509 ,
1 << V_510 ,
1 << V_510 ) ;
switch ( V_5 -> type ) {
case V_158 :
case V_159 :
F_6 ( V_2 , V_163 ,
V_511 , V_511 ) ;
break;
default:
break;
}
switch ( V_5 -> type ) {
case V_159 :
case V_284 :
F_6 ( V_2 , V_285 ,
V_286 , V_286 ) ;
F_6 ( V_2 , V_287 ,
V_288 , V_288 ) ;
break;
default:
break;
}
V_4 -> V_137 . V_512 = F_38 ;
F_55 ( V_2 ) ;
F_90 ( V_4 ) ;
F_127 ( V_2 ) ;
F_89 ( V_2 , V_513 ,
F_4 ( V_513 ) ) ;
F_128 ( V_48 , V_514 ,
F_4 ( V_514 ) ) ;
switch ( V_5 -> type ) {
case V_158 :
F_128 ( V_48 , V_515 ,
F_4 ( V_515 ) ) ;
if ( V_5 -> V_256 < 4 ) {
F_128 ( V_48 , V_516 ,
F_4 ( V_516 ) ) ;
F_128 ( V_48 , V_517 ,
F_4 ( V_517 ) ) ;
F_128 ( V_48 , V_518 ,
F_4 ( V_518 ) ) ;
} else {
F_128 ( V_48 , V_519 ,
F_4 ( V_519 ) ) ;
F_128 ( V_48 , V_520 ,
F_4 ( V_520 ) ) ;
F_128 ( V_48 , V_521 ,
F_4 ( V_521 ) ) ;
}
break;
case V_159 :
F_89 ( V_2 , V_522 ,
F_4 ( V_522 ) ) ;
F_128 ( V_48 , V_523 ,
F_4 ( V_523 ) ) ;
if ( V_5 -> V_256 < 1 ) {
F_128 ( V_48 , V_516 ,
F_4 ( V_516 ) ) ;
F_128 ( V_48 , V_517 ,
F_4 ( V_517 ) ) ;
F_128 ( V_48 , V_518 ,
F_4 ( V_518 ) ) ;
} else {
F_128 ( V_48 , V_519 ,
F_4 ( V_519 ) ) ;
F_128 ( V_48 , V_520 ,
F_4 ( V_520 ) ) ;
F_128 ( V_48 , V_521 ,
F_4 ( V_521 ) ) ;
}
break;
case V_284 :
F_89 ( V_2 , V_522 ,
F_4 ( V_522 ) ) ;
F_128 ( V_48 , V_523 ,
F_4 ( V_523 ) ) ;
F_128 ( V_48 , V_519 ,
F_4 ( V_519 ) ) ;
F_128 ( V_48 , V_520 ,
F_4 ( V_520 ) ) ;
F_128 ( V_48 , V_521 ,
F_4 ( V_521 ) ) ;
break;
}
F_129 ( V_2 , 0 , 0 ) ;
F_130 ( V_48 , V_524 , F_4 ( V_524 ) ) ;
switch ( V_5 -> type ) {
case V_158 :
F_130 ( V_48 , V_525 ,
F_4 ( V_525 ) ) ;
if ( V_5 -> V_256 < 4 ) {
F_130 ( V_48 , V_526 ,
F_4 ( V_526 ) ) ;
F_130 ( V_48 , V_527 ,
F_4 ( V_527 ) ) ;
} else {
F_130 ( V_48 , V_528 ,
F_4 ( V_528 ) ) ;
}
break;
case V_159 :
if ( V_5 -> V_256 < 1 ) {
F_130 ( V_48 , V_525 ,
F_4 ( V_525 ) ) ;
F_130 ( V_48 , V_526 ,
F_4 ( V_526 ) ) ;
F_130 ( V_48 , V_527 ,
F_4 ( V_527 ) ) ;
} else {
F_130 ( V_48 , V_528 ,
F_4 ( V_528 ) ) ;
F_130 ( V_48 , V_529 ,
F_4 ( V_529 ) ) ;
}
F_131 ( V_2 ) ;
break;
case V_284 :
F_130 ( V_48 , V_528 ,
F_4 ( V_528 ) ) ;
F_130 ( V_48 , V_529 ,
F_4 ( V_529 ) ) ;
break;
}
return 0 ;
V_499:
if ( V_4 -> V_21 )
F_132 ( V_4 -> V_4 , F_126 ( 6 ) , V_4 ) ;
F_132 ( V_4 -> V_4 , V_494 , V_4 ) ;
F_132 ( V_4 -> V_4 , V_493 , V_4 ) ;
F_132 ( V_4 -> V_4 , V_492 , V_4 ) ;
if ( V_4 -> V_474 )
F_133 ( V_4 -> V_474 , V_4 ) ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_255 ) ; V_7 ++ )
F_132 ( V_4 -> V_4 , V_497 + V_7 ,
& V_4 -> V_255 [ V_7 ] ) ;
F_132 ( V_4 -> V_4 , V_488 ,
& V_4 -> V_137 ) ;
F_132 ( V_4 -> V_4 , V_485 , V_2 ) ;
F_132 ( V_4 -> V_4 , V_487 , V_2 ) ;
F_132 ( V_4 -> V_4 , V_486 , V_2 ) ;
return V_63 ;
}
static int F_134 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_4 -> V_4 ;
int V_7 ;
F_70 ( V_2 , V_291 ) ;
for ( V_7 = 0 ; V_7 < F_4 ( V_4 -> V_255 ) ; V_7 ++ )
F_132 ( V_4 -> V_4 , V_497 + V_7 ,
& V_4 -> V_255 [ V_7 ] ) ;
F_132 ( V_4 -> V_4 , V_488 ,
& V_4 -> V_137 ) ;
F_132 ( V_4 -> V_4 , V_485 , V_2 ) ;
F_132 ( V_4 -> V_4 , V_487 , V_2 ) ;
F_132 ( V_4 -> V_4 , V_486 , V_2 ) ;
if ( V_4 -> V_21 )
F_132 ( V_4 -> V_4 , F_126 ( 6 ) , V_4 ) ;
switch ( V_5 -> type ) {
case V_158 :
if ( V_4 -> V_474 )
F_133 ( V_4 -> V_474 , V_4 ) ;
F_132 ( V_4 -> V_4 , V_493 ,
V_4 ) ;
F_132 ( V_4 -> V_4 , V_492 ,
V_4 ) ;
F_132 ( V_4 -> V_4 , V_495 ,
V_4 ) ;
break;
case V_284 :
case V_159 :
if ( V_4 -> V_474 )
F_133 ( V_4 -> V_474 , V_4 ) ;
break;
}
F_135 ( V_4 -> V_530 ) ;
F_135 ( V_4 -> V_531 ) ;
F_135 ( V_4 -> V_532 ) ;
F_136 ( V_4 -> V_96 ) ;
return 0 ;
}
static int F_137 ( struct V_533 * V_534 )
{
struct V_3 * V_4 ;
V_4 = F_92 ( & V_534 -> V_28 , sizeof( struct V_3 ) ,
V_384 ) ;
if ( V_4 == NULL )
return - V_535 ;
F_138 ( V_534 , V_4 ) ;
V_4 -> V_4 = F_119 ( V_534 -> V_28 . V_470 ) ;
F_139 ( & V_534 -> V_28 ) ;
F_140 ( & V_534 -> V_28 ) ;
return F_141 ( & V_534 -> V_28 , & V_536 ,
V_502 , F_4 ( V_502 ) ) ;
}
static int F_142 ( struct V_533 * V_534 )
{
F_143 ( & V_534 -> V_28 ) ;
F_144 ( & V_534 -> V_28 ) ;
return 0 ;
}
static int F_145 ( struct V_419 * V_28 )
{
struct V_3 * V_4 = F_119 ( V_28 ) ;
if ( V_4 -> V_21 && ! V_4 -> V_103 )
F_146 ( V_4 -> V_4 -> V_418 , V_107 ,
V_108 ,
V_4 -> V_105 ) ;
return 0 ;
}
static int F_147 ( struct V_419 * V_28 )
{
struct V_3 * V_4 = F_119 ( V_28 ) ;
if ( V_4 -> V_21 && V_4 -> V_105 )
F_146 ( V_4 -> V_4 -> V_418 , V_107 ,
V_108 ,
V_104 ) ;
return 0 ;
}
