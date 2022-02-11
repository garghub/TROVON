static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 = V_5 ;
V_3 = ( V_6 ) ;
F_2 ( V_3 , V_7 ) ;
while ( V_4 -- ) {
V_3 = F_3 ( V_7 ) ;
if ( ! V_3 )
break;
F_4 ( 1000 , 2000 ) ;
}
if ( V_3 ) {
F_5 ( L_1 ) ;
return - V_8 ;
}
V_3 = F_3 ( V_9 ) ;
V_3 |= ( V_10 |
F_6 ( 0 ) ) ;
F_2 ( V_3 , V_9 ) ;
F_2 ( V_3 , V_11 ) ;
F_2 ( V_3 , V_12 ) ;
V_3 = F_3 ( V_13 ) ;
V_3 |= ( V_14 |
F_7 ( 0 ) ) ;
F_2 ( V_3 , V_13 ) ;
F_2 ( V_3 , V_15 ) ;
F_2 ( V_3 , V_16 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , bool V_17 )
{
T_1 V_18 ;
V_18 = F_9 ( V_19 ) ;
if ( V_17 )
V_18 |= F_10 ( V_2 -> V_20 ) |
F_11 ( V_2 -> V_20 ) |
F_12 ( V_2 -> V_20 ) ;
else
V_18 |= F_13 ( V_2 -> V_20 ) ;
F_14 ( V_18 , V_19 ) ;
}
static void F_15 ( struct V_1 * V_2 , bool V_17 ,
bool V_21 , bool V_22 )
{
T_1 V_3 ;
F_16 ( L_2 ,
V_17 , V_21 , V_22 ) ;
V_3 = F_3 ( V_23 ) ;
V_3 |= ( V_24 | V_25 ) ;
if ( V_17 )
V_3 |= V_26 ;
else
V_3 &= ~ V_26 ;
if ( V_21 )
V_3 &= ~ V_24 ;
else
V_3 |= V_24 ;
if ( V_22 )
V_3 &= ~ V_25 ;
else
V_3 |= V_25 ;
F_2 ( V_3 , V_23 ) ;
}
static int F_17 ( struct V_27 * V_28 , T_1 V_29 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_30 * V_31 = & V_2 -> V_31 ;
T_1 V_3 ;
F_16 ( L_3 , V_29 ) ;
V_3 = F_3 ( V_32 ) ;
V_3 &= ~ ( V_33 | V_34 |
V_35 | V_36 |
V_37 | V_38 |
V_39 | V_40 ) ;
switch ( V_29 ) {
case V_41 :
V_3 |= V_42 ;
break;
case V_43 :
V_3 |= V_44 ;
break;
case V_45 :
V_3 |= ( V_44 | V_46 ) ;
break;
case V_47 :
V_3 |= ( V_48 |
V_49 |
V_50 ) ;
break;
case V_51 :
V_3 |= ( V_48 |
V_49 |
V_52 ) ;
break;
case V_53 :
V_3 |= ( V_48 |
V_54 |
V_50 ) ;
break;
case V_55 :
V_3 |= ( V_48 |
V_54 |
V_52 ) ;
break;
case V_56 :
case V_57 :
V_3 |= ( V_52 |
V_58 ) ;
break;
case V_59 :
V_3 |= V_60 ;
break;
case V_61 :
case V_62 :
V_3 |= V_63 ;
break;
case V_64 :
case V_65 :
V_3 |= ( V_50 |
V_58 ) ;
break;
default:
F_19 ( V_31 -> V_28 , L_4 , V_29 ) ;
return - V_66 ;
}
F_2 ( V_3 , V_32 ) ;
return 0 ;
}
static int F_20 ( struct V_27 * V_28 ,
enum V_67 V_68 ,
enum V_69 V_70 , bool * V_71 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_30 * V_31 = & V_2 -> V_31 ;
T_1 V_3 ;
F_16 ( L_5 , V_68 , V_70 ) ;
V_3 = F_3 ( V_32 ) ;
V_3 &= ~ V_72 ;
switch ( V_68 ) {
case V_73 :
if ( V_70 & V_74 )
V_3 |= V_75 ;
if ( V_70 & V_76 )
V_3 |= V_77 ;
break;
case V_78 :
if ( V_70 & V_74 )
V_3 |= V_79 ;
else if ( V_70 & V_76 )
V_3 |= V_80 ;
else
V_3 |= V_81 ;
break;
case V_82 :
V_3 |= V_83 ;
if ( V_70 & V_74 )
V_3 &= ~ V_75 ;
if ( V_70 & V_76 )
V_3 &= ~ V_77 ;
break;
case V_84 :
V_3 |= V_85 ;
if ( V_70 & V_74 )
V_3 &= ~ V_75 ;
if ( V_70 & V_76 )
V_3 &= ~ V_77 ;
break;
default:
F_19 ( V_31 -> V_28 , L_6 , V_68 ) ;
return - V_66 ;
}
F_2 ( V_3 , V_32 ) ;
V_2 -> V_86 = ( V_3 & V_81 ) ? 1 : 0 ;
* V_71 = V_2 -> V_86 ;
return 0 ;
}
static int F_21 ( struct V_27 * V_28 , int V_71 ,
struct V_87 * V_88 , struct V_89 * V_90 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_87 V_91 = * V_88 ;
struct V_92 * V_93 = & V_2 -> V_93 ;
T_1 V_3 ;
F_16 ( L_7 ,
V_71 , V_88 -> V_94 , V_88 -> V_95 , V_88 -> V_96 , V_88 -> V_97 ) ;
if ( V_71 ) {
V_91 . V_96 = V_88 -> V_97 ;
V_91 . V_97 = V_88 -> V_96 ;
}
V_3 = ( F_22 ( V_91 . V_94 ) |
F_23 ( V_91 . V_95 ) ) ;
F_2 ( V_3 , V_98 ) ;
V_3 = ( F_24 ( V_91 . V_96 ) |
F_25 ( V_91 . V_97 ) ) ;
F_2 ( V_3 , V_99 ) ;
F_16 ( L_8 , V_90 -> V_100 , V_90 -> V_101 ) ;
V_3 = F_3 ( V_102 ) ;
V_3 &= ~ ( V_103 |
V_104 ) ;
V_3 |= ( F_26 ( V_90 -> V_100 ) |
F_27 ( V_90 -> V_101 ) ) ;
F_2 ( V_3 , V_102 ) ;
V_3 = F_3 ( V_32 ) ;
V_3 &= ~ V_33 ;
F_16 ( L_9 , V_88 -> V_96 , V_93 -> V_105 ) ;
if ( V_88 -> V_96 >= V_106 )
if ( V_93 -> V_105 )
V_3 |= V_107 ;
else
V_3 |= V_108 ;
else
if ( V_93 -> V_105 )
V_3 |= V_109 ;
else
V_3 |= V_110 ;
F_2 ( V_3 , V_32 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , T_1 V_111 ,
enum V_112 V_113 )
{
struct V_30 * V_31 = & V_2 -> V_31 ;
bool V_114 ;
T_1 V_3 ;
T_1 V_115 = 0x00000001 << V_111 ;
F_16 ( L_10 , V_111 , V_113 ) ;
V_3 = F_3 ( V_9 ) ;
switch ( V_113 ) {
case V_116 :
V_114 = false ;
break;
case V_117 :
V_114 = true ;
break;
default:
F_19 ( V_31 -> V_28 , L_11 ) ;
return - V_66 ;
}
V_3 &= ~ V_115 ;
V_3 |= V_114 << V_111 ;
F_2 ( V_3 , V_9 ) ;
F_2 ( V_3 , V_11 ) ;
F_2 ( V_3 , V_12 ) ;
return 0 ;
}
static int F_29 ( struct V_27 * V_28 ,
struct V_118 * V_119 , T_1 V_111 ,
enum V_112 V_113 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_30 * V_31 = & V_2 -> V_31 ;
struct V_120 * V_121 = V_31 -> V_121 ;
struct V_122 * V_123 ;
if ( ! V_121 ) {
F_5 ( L_12 ) ;
return - V_124 ;
}
V_123 = & V_121 -> V_123 ;
F_16 ( L_13 ,
V_123 -> V_125 , V_111 , V_113 ) ;
if ( V_111 > V_126 ) {
F_30 ( V_31 -> V_28 , L_14 , V_111 ) ;
return - V_66 ;
}
switch ( V_113 ) {
case V_116 :
F_2 ( V_119 -> V_127 [ V_128 ] ,
F_31 ( V_111 ) ) ;
F_2 ( V_119 -> V_127 [ V_129 ] ,
F_32 ( V_111 ) ) ;
F_2 ( V_119 -> V_127 [ V_130 ] ,
F_33 ( V_111 ) ) ;
break;
case V_117 :
F_2 ( 0x0 , F_31 ( V_111 ) ) ;
F_2 ( 0x0 , F_32 ( V_111 ) ) ;
F_2 ( 0x0 , F_33 ( V_111 ) ) ;
break;
default:
break;
}
return F_28 ( V_2 , V_111 , V_113 ) ;
}
static int F_34 ( struct V_27 * V_28 , T_1 V_29 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_30 * V_31 = & V_2 -> V_31 ;
T_1 V_3 ;
F_16 ( L_3 , V_29 ) ;
V_3 = F_3 ( V_131 ) ;
V_3 &= ~ ( V_132 | V_133 |
V_134 | V_135 |
V_136 | V_137 |
V_138 ) ;
switch ( V_29 ) {
case V_41 :
V_3 |= V_139 ;
break;
case V_43 :
V_3 |= V_140 ;
break;
case V_45 :
V_3 |= ( V_140 | V_141 ) ;
break;
case V_47 :
V_3 |= ( V_142 |
V_143 |
V_144 ) ;
break;
case V_51 :
V_3 |= ( V_142 |
V_143 |
V_145 ) ;
break;
case V_53 :
V_3 |= ( V_142 |
V_146 |
V_144 ) ;
break;
case V_55 :
V_3 |= ( V_142 |
V_146 |
V_145 ) ;
break;
case V_56 :
case V_57 :
V_3 |= ( V_145 | V_147 ) ;
break;
case V_59 :
case V_61 :
case V_62 :
V_3 |= V_148 ;
break;
case V_64 :
case V_65 :
V_3 |= ( V_144 |
V_147 ) ;
break;
default:
F_19 ( V_31 -> V_28 , L_4 , V_29 ) ;
return - V_66 ;
}
F_2 ( V_3 , V_131 ) ;
return 0 ;
}
static int F_35 ( struct V_27 * V_28 ,
enum V_67 V_68 ,
enum V_69 V_70 , bool * V_71 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_30 * V_31 = & V_2 -> V_31 ;
T_1 V_3 ;
F_16 ( L_5 , V_68 , V_70 ) ;
V_3 = F_3 ( V_32 ) ;
V_3 &= ~ V_72 ;
switch ( V_68 ) {
case V_73 :
if ( V_70 & V_74 )
V_3 |= V_75 ;
if ( V_70 & V_76 )
V_3 |= V_77 ;
break;
case V_78 :
if ( V_70 & V_74 )
V_3 |= V_79 ;
else if ( V_70 & V_76 )
V_3 |= V_80 ;
else
V_3 |= V_81 ;
break;
case V_82 :
V_3 |= V_83 ;
if ( V_70 & V_74 )
V_3 &= ~ V_75 ;
if ( V_70 & V_76 )
V_3 &= ~ V_77 ;
break;
case V_84 :
V_3 |= V_85 ;
if ( V_70 & V_74 )
V_3 &= ~ V_75 ;
if ( V_70 & V_76 )
V_3 &= ~ V_77 ;
break;
default:
F_19 ( V_31 -> V_28 , L_6 , V_68 ) ;
return - V_66 ;
}
F_2 ( V_3 , V_32 ) ;
V_2 -> V_86 = ( V_3 & V_81 ) ? 1 : 0 ;
* V_71 = V_2 -> V_86 ;
return 0 ;
}
static int F_36 ( T_1 V_149 , T_1 V_150 , T_1 * V_151 )
{
F_16 ( L_15 , V_149 , V_150 ) ;
if ( V_149 >= V_150 * 8 ) {
F_5 ( L_16 ) ;
return - V_66 ;
} else if ( V_149 >= V_150 * 4 )
* V_151 = 4 ;
else if ( V_149 >= V_150 * 2 )
* V_151 = 2 ;
else
* V_151 = 1 ;
return 0 ;
}
static void F_37 ( T_1 V_152 , T_1 V_153 , T_1 * V_154 )
{
if ( V_152 == 4 && V_153 == 4 )
* V_154 = 4 ;
else if ( ( V_152 == 4 && V_153 == 2 ) ||
( V_152 == 2 && V_153 == 4 ) )
* V_154 = 3 ;
else if ( ( V_152 == 4 && V_153 == 1 ) ||
( V_152 == 1 && V_153 == 4 ) ||
( V_152 == 2 && V_153 == 2 ) )
* V_154 = 2 ;
else if ( V_152 == 1 && V_153 == 1 )
* V_154 = 0 ;
else
* V_154 = 1 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_92 * V_93 ,
struct V_87 * V_149 , struct V_87 * V_150 )
{
struct V_30 * V_31 = & V_2 -> V_31 ;
T_1 V_3 ;
T_1 V_155 , V_156 , V_157 , V_158 ;
int V_159 = 0 ;
V_155 = V_149 -> V_96 ;
V_156 = V_149 -> V_97 ;
if ( V_2 -> V_86 ) {
V_157 = V_150 -> V_97 ;
V_158 = V_150 -> V_96 ;
} else {
V_157 = V_150 -> V_96 ;
V_158 = V_150 -> V_97 ;
}
V_159 = F_36 ( V_155 , V_157 , & V_93 -> V_160 ) ;
if ( V_159 ) {
F_19 ( V_31 -> V_28 , L_17 ) ;
return V_159 ;
}
V_159 = F_36 ( V_156 , V_158 , & V_93 -> V_161 ) ;
if ( V_159 ) {
F_19 ( V_31 -> V_28 , L_18 ) ;
return V_159 ;
}
F_16 ( L_19 ,
V_93 -> V_160 , V_93 -> V_161 ) ;
V_93 -> V_162 = ( V_155 << 16 ) / V_157 ;
V_93 -> V_163 = ( V_156 << 16 ) / V_158 ;
F_16 ( L_20 ,
V_93 -> V_162 , V_93 -> V_163 ) ;
F_37 ( V_93 -> V_160 , V_93 -> V_161 ,
& V_93 -> V_164 ) ;
F_16 ( L_21 , V_93 -> V_164 ) ;
V_3 = ( F_39 ( V_93 -> V_164 ) |
F_40 ( V_93 -> V_160 ) |
F_41 ( V_93 -> V_161 ) ) ;
F_2 ( V_3 , V_165 ) ;
return V_159 ;
}
static void F_42 ( struct V_1 * V_2 , unsigned long V_162 )
{
int V_166 , V_167 , V_168 , V_169 ;
if ( V_162 <= V_170 )
V_169 = 0 ;
else if ( V_162 <= V_171 )
V_169 = 1 ;
else if ( V_162 <= V_172 )
V_169 = 2 ;
else if ( V_162 <= V_173 )
V_169 = 3 ;
else if ( V_162 <= V_174 )
V_169 = 4 ;
else if ( V_162 <= V_175 )
V_169 = 5 ;
else
V_169 = 6 ;
for ( V_166 = 0 ; V_166 < V_176 ; V_166 ++ )
for ( V_167 = 0 ; V_167 < V_177 ; V_167 ++ )
for ( V_168 = 0 ; V_168 < V_178 ; V_168 ++ )
F_2 ( V_179 [ V_169 ] [ V_166 ] [ V_167 ] ,
F_43 ( V_166 , V_167 , V_168 ) ) ;
}
static void F_44 ( struct V_1 * V_2 , unsigned long V_163 )
{
int V_166 , V_167 , V_168 , V_169 ;
if ( V_163 <= V_170 )
V_169 = 0 ;
else if ( V_163 <= V_171 )
V_169 = 1 ;
else if ( V_163 <= V_172 )
V_169 = 2 ;
else if ( V_163 <= V_173 )
V_169 = 3 ;
else if ( V_163 <= V_174 )
V_169 = 4 ;
else if ( V_163 <= V_175 )
V_169 = 5 ;
else
V_169 = 6 ;
for ( V_166 = 0 ; V_166 < V_176 ; V_166 ++ )
for ( V_167 = 0 ; V_167 < V_180 ; V_167 ++ )
for ( V_168 = 0 ; V_168 < V_178 ; V_168 ++ )
F_2 ( V_181 [ V_169 ] [ V_166 ] [ V_167 ] ,
F_45 ( V_166 , V_167 , V_168 ) ) ;
}
static void F_46 ( struct V_1 * V_2 , struct V_92 * V_93 )
{
T_1 V_3 ;
F_16 ( L_20 ,
V_93 -> V_162 , V_93 -> V_163 ) ;
F_42 ( V_2 , V_93 -> V_162 ) ;
V_3 = F_47 ( V_93 -> V_162 ) ;
F_2 ( V_3 , V_182 ) ;
F_44 ( V_2 , V_93 -> V_163 ) ;
V_3 = F_48 ( V_93 -> V_163 ) ;
F_2 ( V_3 , V_183 ) ;
}
static int F_49 ( struct V_27 * V_28 , int V_71 ,
struct V_87 * V_88 , struct V_89 * V_90 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_87 V_91 = * V_88 ;
struct V_92 * V_93 = & V_2 -> V_93 ;
T_1 V_3 ;
F_16 ( L_7 ,
V_71 , V_88 -> V_94 , V_88 -> V_95 , V_88 -> V_96 , V_88 -> V_97 ) ;
if ( V_71 ) {
V_91 . V_96 = V_88 -> V_97 ;
V_91 . V_97 = V_88 -> V_96 ;
}
V_3 = ( F_50 ( V_88 -> V_94 ) |
F_51 ( V_88 -> V_95 ) ) ;
F_2 ( V_3 , V_184 ) ;
V_3 = ( F_52 ( V_91 . V_96 ) | F_53 ( V_91 . V_97 ) ) ;
F_2 ( V_3 , V_185 ) ;
F_16 ( L_8 , V_90 -> V_100 , V_90 -> V_101 ) ;
V_3 = F_3 ( V_186 ) ;
V_3 &= ~ ( V_187 |
V_188 ) ;
V_3 |= ( F_54 ( V_90 -> V_100 ) |
F_55 ( V_90 -> V_101 ) ) ;
F_2 ( V_3 , V_186 ) ;
V_3 = F_3 ( V_131 ) ;
V_3 &= ~ V_132 ;
F_16 ( L_9 , V_88 -> V_96 , V_93 -> V_105 ) ;
if ( V_88 -> V_96 >= V_106 )
if ( V_93 -> V_105 )
V_3 |= V_189 ;
else
V_3 |= V_190 ;
else
if ( V_93 -> V_105 )
V_3 |= V_191 ;
else
V_3 |= V_192 ;
F_2 ( V_3 , V_131 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
T_1 V_3 , V_166 , V_193 = V_194 ;
T_1 V_115 = 0x00000001 ;
V_3 = F_3 ( V_13 ) ;
for ( V_166 = 0 ; V_166 < V_194 ; V_166 ++ )
if ( V_3 & ( V_115 << V_166 ) )
V_193 -- ;
F_16 ( L_22 , V_193 ) ;
return V_193 ;
}
static int F_57 ( struct V_1 * V_2 , T_1 V_111 ,
enum V_112 V_113 )
{
struct V_30 * V_31 = & V_2 -> V_31 ;
bool V_114 ;
T_1 V_3 ;
T_1 V_115 = 0x00000001 << V_111 ;
int V_159 = 0 ;
F_16 ( L_10 , V_111 , V_113 ) ;
F_58 ( & V_2 -> V_195 ) ;
V_3 = F_3 ( V_13 ) ;
switch ( V_113 ) {
case V_116 :
V_114 = false ;
break;
case V_117 :
V_114 = true ;
break;
default:
F_19 ( V_31 -> V_28 , L_11 ) ;
V_159 = - V_66 ;
goto V_196;
}
V_3 &= ~ V_115 ;
V_3 |= V_114 << V_111 ;
F_2 ( V_3 , V_13 ) ;
F_2 ( V_3 , V_15 ) ;
F_2 ( V_3 , V_16 ) ;
if ( V_113 == V_116 &&
F_56 ( V_2 ) >= V_197 )
F_15 ( V_2 , true , false , true ) ;
if ( V_113 == V_117 &&
F_56 ( V_2 ) <= V_198 )
F_15 ( V_2 , false , false , true ) ;
V_196:
F_59 ( & V_2 -> V_195 ) ;
return V_159 ;
}
static int F_60 ( struct V_27 * V_28 ,
struct V_118 * V_119 , T_1 V_111 ,
enum V_112 V_113 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_30 * V_31 = & V_2 -> V_31 ;
struct V_120 * V_121 = V_31 -> V_121 ;
struct V_122 * V_123 ;
if ( ! V_121 ) {
F_5 ( L_12 ) ;
return - V_124 ;
}
V_123 = & V_121 -> V_123 ;
F_16 ( L_13 ,
V_123 -> V_125 , V_111 , V_113 ) ;
if ( V_111 > V_199 ) {
F_30 ( V_31 -> V_28 , L_14 , V_111 ) ;
return - V_66 ;
}
switch ( V_113 ) {
case V_116 :
F_2 ( V_119 -> V_127 [ V_128 ] ,
F_61 ( V_111 ) ) ;
F_2 ( V_119 -> V_127 [ V_129 ] ,
F_62 ( V_111 ) ) ;
F_2 ( V_119 -> V_127 [ V_130 ] ,
F_63 ( V_111 ) ) ;
break;
case V_117 :
F_2 ( 0x0 , F_61 ( V_111 ) ) ;
F_2 ( 0x0 , F_62 ( V_111 ) ) ;
F_2 ( 0x0 , F_63 ( V_111 ) ) ;
break;
default:
break;
}
return F_57 ( V_2 , V_111 , V_113 ) ;
}
static int F_64 ( struct V_1 * V_2 , bool V_17 )
{
F_16 ( L_23 , V_17 ) ;
if ( V_17 ) {
F_65 ( V_2 -> V_200 ) ;
V_2 -> V_201 = false ;
} else {
F_66 ( V_2 -> V_200 ) ;
V_2 -> V_201 = true ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
T_1 V_3 , V_202 , V_166 ;
T_1 V_111 = V_126 ;
int V_159 ;
F_16 ( L_24 , V_2 -> V_20 ) ;
V_3 = F_3 ( V_9 ) ;
V_202 = F_68 ( V_3 ) ;
for ( V_166 = V_202 ; V_166 < V_126 ; V_166 ++ ) {
if ( ! ( ( V_3 >> V_166 ) & 0x1 ) ) {
V_111 = V_166 ;
break;
}
}
if ( V_111 == V_126 ) {
F_5 ( L_25 ) ;
return - V_66 ;
}
V_159 = F_28 ( V_2 , V_111 , V_117 ) ;
if ( V_159 < 0 ) {
F_5 ( L_26 ) ;
return V_159 ;
}
F_16 ( L_27 , V_3 ,
V_202 , V_111 ) ;
return V_111 ;
}
static int F_69 ( struct V_1 * V_2 )
{
T_1 V_3 , V_202 , V_166 ;
T_1 V_111 = V_199 ;
int V_159 ;
F_16 ( L_24 , V_2 -> V_20 ) ;
V_3 = F_3 ( V_13 ) ;
V_202 = F_70 ( V_3 ) ;
for ( V_166 = V_202 ; V_166 < V_199 ; V_166 ++ ) {
if ( ! ( ( V_3 >> V_166 ) & 0x1 ) ) {
V_111 = V_166 ;
break;
}
}
if ( V_111 == V_199 ) {
F_5 ( L_28 ) ;
return - V_66 ;
}
V_159 = F_57 ( V_2 , V_111 , V_117 ) ;
if ( V_159 < 0 ) {
F_5 ( L_26 ) ;
return V_159 ;
}
F_16 ( L_27 , V_3 ,
V_202 , V_111 ) ;
return V_111 ;
}
static T_2 F_71 ( int V_203 , void * V_204 )
{
struct V_1 * V_2 = V_204 ;
struct V_30 * V_31 = & V_2 -> V_31 ;
struct V_120 * V_121 = V_31 -> V_121 ;
struct V_205 * V_206 =
V_121 -> V_206 ;
T_1 V_207 ;
int V_111 [ V_208 ] ;
F_16 ( L_24 , V_2 -> V_20 ) ;
V_207 = F_3 ( V_23 ) ;
if ( V_207 & V_209 ) {
F_19 ( V_31 -> V_28 , L_29 ,
V_2 -> V_20 , V_207 ) ;
return V_210 ;
}
if ( V_207 & V_211 ) {
F_72 ( V_31 -> V_28 , L_30 ,
V_2 -> V_20 , V_207 ) ;
V_111 [ V_212 ] = F_67 ( V_2 ) ;
if ( V_111 [ V_212 ] < 0 )
return V_213 ;
V_111 [ V_214 ] = F_69 ( V_2 ) ;
if ( V_111 [ V_214 ] < 0 )
return V_213 ;
F_16 ( L_31 ,
V_111 [ V_212 ] , V_111 [ V_214 ] ) ;
V_206 -> V_31 = V_31 ;
V_206 -> V_111 [ V_212 ] =
V_111 [ V_212 ] ;
V_206 -> V_111 [ V_214 ] =
V_111 [ V_214 ] ;
F_73 ( V_31 -> V_215 , & V_206 -> V_216 ) ;
}
return V_213 ;
}
static int F_74 ( struct V_30 * V_31 )
{
struct V_217 * V_218 = & V_31 -> V_218 ;
V_218 -> V_219 = 1 ;
V_218 -> V_220 = 1 ;
V_218 -> V_221 = V_222 ;
V_218 -> V_223 = V_224 ;
V_218 -> V_70 = ( 1 << V_74 ) |
( 1 << V_76 ) ;
V_218 -> V_68 = ( 1 << V_73 ) |
( 1 << V_78 ) |
( 1 << V_82 ) |
( 1 << V_84 ) ;
V_218 -> V_225 = 1 ;
V_218 -> V_226 = 1 ;
V_218 -> V_227 . V_100 = V_228 ;
V_218 -> V_227 . V_101 = V_228 ;
V_218 -> V_229 . V_100 = V_230 ;
V_218 -> V_229 . V_101 = V_230 ;
V_218 -> V_231 = 1 ;
V_218 -> V_232 . V_100 = V_233 ;
V_218 -> V_232 . V_101 = V_233 ;
V_218 -> V_234 . V_100 = V_235 ;
V_218 -> V_234 . V_101 = V_235 ;
return 0 ;
}
static inline bool F_75 ( enum V_69 V_70 )
{
switch ( V_70 ) {
case V_236 :
case V_74 :
case V_76 :
case V_237 :
return true ;
default:
F_16 ( L_32 ) ;
return false ;
}
}
static int F_76 ( struct V_27 * V_28 ,
struct V_122 * V_123 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_30 * V_31 = & V_2 -> V_31 ;
struct V_217 * V_238 = & V_31 -> V_218 ;
struct V_239 * V_240 ;
struct V_87 * V_88 ;
struct V_89 * V_90 ;
bool V_71 ;
int V_166 ;
F_77 (i) {
if ( ( V_166 == V_212 ) &&
( V_123 -> V_241 == V_242 ) )
continue;
V_240 = & V_123 -> V_240 [ V_166 ] ;
V_88 = & V_240 -> V_88 ;
V_90 = & V_240 -> V_90 ;
if ( ! F_75 ( V_240 -> V_70 ) ) {
F_5 ( L_33 ) ;
goto V_243;
}
switch ( V_240 -> V_68 ) {
case V_78 :
case V_84 :
V_71 = true ;
break;
case V_73 :
case V_82 :
V_71 = false ;
break;
default:
F_5 ( L_34 ) ;
goto V_243;
}
if ( ( V_88 -> V_94 + V_88 -> V_96 > V_90 -> V_100 ) ||
( V_88 -> V_95 + V_88 -> V_97 > V_90 -> V_101 ) ) {
F_5 ( L_35 ) ;
goto V_243;
}
if ( ( V_166 == V_212 ) && ( V_238 -> V_226 ) ) {
if ( V_71 ) {
if ( ( V_88 -> V_97 < V_238 -> V_229 . V_100 ) ||
( V_90 -> V_101 > V_238 -> V_227 . V_100 ) ||
( V_88 -> V_96 < V_238 -> V_229 . V_101 ) ||
( V_90 -> V_100 > V_238 -> V_227 . V_101 ) ) {
F_5 ( L_36 ) ;
goto V_243;
}
} else {
if ( ( V_88 -> V_96 < V_238 -> V_229 . V_100 ) ||
( V_90 -> V_100 > V_238 -> V_227 . V_100 ) ||
( V_88 -> V_97 < V_238 -> V_229 . V_101 ) ||
( V_90 -> V_101 > V_238 -> V_227 . V_101 ) ) {
F_5 ( L_36 ) ;
goto V_243;
}
}
}
if ( ( V_166 == V_214 ) && ( V_238 -> V_231 ) ) {
if ( V_71 ) {
if ( ( V_88 -> V_97 < V_238 -> V_234 . V_100 ) ||
( V_90 -> V_101 > V_238 -> V_232 . V_100 ) ||
( V_88 -> V_96 < V_238 -> V_234 . V_101 ) ||
( V_90 -> V_100 > V_238 -> V_232 . V_101 ) ) {
F_5 ( L_37 ) ;
goto V_243;
}
} else {
if ( ( V_88 -> V_96 < V_238 -> V_234 . V_100 ) ||
( V_90 -> V_100 > V_238 -> V_232 . V_100 ) ||
( V_88 -> V_97 < V_238 -> V_234 . V_101 ) ||
( V_90 -> V_101 > V_238 -> V_232 . V_101 ) ) {
F_5 ( L_37 ) ;
goto V_243;
}
}
}
}
return 0 ;
V_243:
F_77 (i) {
if ( ( V_166 == V_212 ) &&
( V_123 -> V_241 == V_242 ) )
continue;
V_240 = & V_123 -> V_240 [ V_166 ] ;
V_88 = & V_240 -> V_88 ;
V_90 = & V_240 -> V_90 ;
F_5 ( L_38 ,
V_166 ? L_39 : L_40 , V_240 -> V_70 , V_240 -> V_68 ,
V_88 -> V_94 , V_88 -> V_95 , V_88 -> V_96 , V_88 -> V_97 ,
V_90 -> V_100 , V_90 -> V_101 ) ;
}
return - V_66 ;
}
static int F_78 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_92 * V_93 = & V_2 -> V_93 ;
int V_159 ;
V_159 = F_1 ( V_2 ) ;
if ( V_159 < 0 ) {
F_19 ( V_28 , L_41 ) ;
return V_159 ;
}
memset ( & V_2 -> V_93 , 0x0 , sizeof( V_2 -> V_93 ) ) ;
V_93 -> V_105 = true ;
return 0 ;
}
static int F_79 ( struct V_27 * V_28 , enum V_244 V_241 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_30 * V_31 = & V_2 -> V_31 ;
struct V_120 * V_121 = V_31 -> V_121 ;
struct V_122 * V_123 ;
struct V_239 * V_240 ;
struct V_87 V_91 [ V_208 ] ;
struct V_245 V_246 ;
T_1 V_3 ;
int V_159 , V_166 ;
F_16 ( L_42 , V_241 ) ;
if ( ! V_121 ) {
F_5 ( L_12 ) ;
return - V_66 ;
}
V_123 = & V_121 -> V_123 ;
F_15 ( V_2 , true , false , true ) ;
F_77 (i) {
V_240 = & V_123 -> V_240 [ V_166 ] ;
V_91 [ V_166 ] = V_240 -> V_88 ;
}
switch ( V_241 ) {
case V_247 :
V_3 = F_3 ( V_248 ) ;
V_3 &= ~ ( V_249 |
V_250 ) ;
V_3 |= V_251 ;
F_2 ( V_3 , V_248 ) ;
V_3 = F_3 ( V_32 ) ;
V_3 &= ~ ( V_252 | V_253 ) ;
V_3 |= V_254 ;
F_2 ( V_3 , V_32 ) ;
V_3 = F_3 ( V_131 ) ;
V_3 |= V_255 ;
F_2 ( V_3 , V_131 ) ;
break;
case V_242 :
V_246 . V_17 = 1 ;
V_246 . V_256 = V_123 -> V_257 ;
F_8 ( V_2 , V_246 . V_17 ) ;
F_80 ( V_258 , ( void * ) & V_246 ) ;
V_3 = F_3 ( V_32 ) ;
V_3 &= ~ ( V_252 | V_253 ) ;
V_3 |= ( V_259 | V_260 ) ;
F_2 ( V_3 , V_32 ) ;
V_3 = F_3 ( V_131 ) ;
V_3 |= V_255 ;
F_2 ( V_3 , V_131 ) ;
break;
case V_261 :
V_3 = F_3 ( V_32 ) ;
V_3 &= ~ ( V_252 | V_253 ) ;
V_3 |= V_254 ;
F_2 ( V_3 , V_32 ) ;
V_3 = F_3 ( V_131 ) ;
V_3 |= V_255 ;
F_2 ( V_3 , V_131 ) ;
break;
default:
V_159 = - V_66 ;
F_19 ( V_28 , L_43 ) ;
return V_159 ;
}
V_159 = F_38 ( V_2 , & V_2 -> V_93 ,
& V_91 [ V_212 ] ,
& V_91 [ V_214 ] ) ;
if ( V_159 ) {
F_19 ( V_28 , L_44 ) ;
return V_159 ;
}
F_46 ( V_2 , & V_2 -> V_93 ) ;
V_3 = F_3 ( V_248 ) ;
V_3 |= V_262 ;
F_2 ( V_3 , V_248 ) ;
return 0 ;
}
static void F_81 ( struct V_27 * V_28 , enum V_244 V_241 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_245 V_246 = { 0 , 0 } ;
T_1 V_3 ;
F_16 ( L_42 , V_241 ) ;
switch ( V_241 ) {
case V_247 :
break;
case V_242 :
F_8 ( V_2 , V_246 . V_17 ) ;
F_80 ( V_258 , ( void * ) & V_246 ) ;
break;
case V_261 :
default:
F_19 ( V_28 , L_43 ) ;
break;
}
F_15 ( V_2 , false , false , true ) ;
F_2 ( 0xff , V_13 ) ;
F_2 ( 0xff , V_15 ) ;
F_2 ( 0xff , V_16 ) ;
V_3 = F_3 ( V_248 ) ;
V_3 &= ~ V_262 ;
F_2 ( V_3 , V_248 ) ;
}
static int F_82 ( struct V_263 * V_264 )
{
struct V_27 * V_28 = & V_264 -> V_28 ;
struct V_1 * V_2 ;
struct V_265 * V_266 ;
struct V_30 * V_31 ;
int V_159 ;
V_2 = F_83 ( V_28 , sizeof( * V_2 ) , V_267 ) ;
if ( ! V_2 )
return - V_268 ;
V_2 -> V_200 = F_84 ( V_28 , L_45 ) ;
if ( F_85 ( V_2 -> V_200 ) ) {
F_19 ( V_28 , L_46 ) ;
return F_86 ( V_2 -> V_200 ) ;
}
V_2 -> V_269 = F_87 ( V_264 , V_270 , 0 ) ;
V_2 -> V_271 = F_88 ( V_28 , V_2 -> V_269 ) ;
if ( F_85 ( V_2 -> V_271 ) )
return F_86 ( V_2 -> V_271 ) ;
V_266 = F_87 ( V_264 , V_272 , 0 ) ;
if ( ! V_266 ) {
F_19 ( V_28 , L_47 ) ;
return - V_273 ;
}
V_2 -> V_203 = V_266 -> V_274 ;
V_159 = F_89 ( V_28 , V_2 -> V_203 , NULL , F_71 ,
V_275 , L_48 , V_2 ) ;
if ( V_159 < 0 ) {
F_19 ( V_28 , L_49 ) ;
return V_159 ;
}
V_2 -> V_20 = V_264 -> V_20 ;
V_31 = & V_2 -> V_31 ;
V_31 -> V_28 = V_28 ;
V_31 -> V_276 [ V_212 ] = & V_277 ;
V_31 -> V_276 [ V_214 ] = & V_278 ;
V_31 -> V_279 = F_76 ;
V_31 -> V_280 = F_78 ;
V_31 -> V_274 = F_79 ;
V_31 -> V_281 = F_81 ;
V_159 = F_74 ( V_31 ) ;
if ( V_159 < 0 ) {
F_19 ( V_28 , L_50 ) ;
return V_159 ;
}
F_16 ( L_51 , V_2 -> V_20 , ( int ) V_31 ) ;
F_90 ( & V_2 -> V_195 ) ;
F_91 ( V_264 , V_2 ) ;
F_92 ( V_28 ) ;
F_93 ( V_28 ) ;
V_159 = F_94 ( V_31 ) ;
if ( V_159 < 0 ) {
F_19 ( V_28 , L_52 ) ;
goto V_282;
}
F_30 ( V_28 , L_53 ) ;
return 0 ;
V_282:
F_95 ( V_28 ) ;
return V_159 ;
}
static int F_96 ( struct V_263 * V_264 )
{
struct V_27 * V_28 = & V_264 -> V_28 ;
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_30 * V_31 = & V_2 -> V_31 ;
F_97 ( V_31 ) ;
F_98 ( & V_2 -> V_195 ) ;
F_99 ( V_28 ) ;
F_95 ( V_28 ) ;
return 0 ;
}
static int F_100 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
F_16 ( L_54 , V_2 -> V_20 ) ;
if ( F_101 ( V_28 ) )
return 0 ;
return F_64 ( V_2 , false ) ;
}
static int F_102 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
F_16 ( L_54 , V_2 -> V_20 ) ;
if ( ! F_101 ( V_28 ) )
return F_64 ( V_2 , true ) ;
return 0 ;
}
static int F_103 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
F_16 ( L_54 , V_2 -> V_20 ) ;
return F_64 ( V_2 , false ) ;
}
static int F_104 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
F_16 ( L_54 , V_2 -> V_20 ) ;
return F_64 ( V_2 , true ) ;
}
