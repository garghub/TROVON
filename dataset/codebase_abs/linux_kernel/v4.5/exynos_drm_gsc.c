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
unsigned int V_18 ;
if ( ! V_2 -> V_19 )
return;
F_9 ( V_2 -> V_19 , V_20 , & V_18 ) ;
if ( V_17 )
V_18 |= F_10 ( V_2 -> V_21 ) |
F_11 ( V_2 -> V_21 ) |
F_12 ( V_2 -> V_21 ) ;
else
V_18 |= F_13 ( V_2 -> V_21 ) ;
F_14 ( V_2 -> V_19 , V_20 , V_18 ) ;
}
static void F_15 ( struct V_1 * V_2 , bool V_17 ,
bool V_22 , bool V_23 )
{
T_1 V_3 ;
F_16 ( L_2 ,
V_17 , V_22 , V_23 ) ;
V_3 = F_3 ( V_24 ) ;
V_3 |= ( V_25 | V_26 ) ;
if ( V_17 )
V_3 |= V_27 ;
else
V_3 &= ~ V_27 ;
if ( V_22 )
V_3 &= ~ V_25 ;
else
V_3 |= V_25 ;
if ( V_23 )
V_3 &= ~ V_26 ;
else
V_3 |= V_26 ;
F_2 ( V_3 , V_24 ) ;
}
static int F_17 ( struct V_28 * V_29 , T_1 V_30 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_31 * V_32 = & V_2 -> V_32 ;
T_1 V_3 ;
F_16 ( L_3 , V_30 ) ;
V_3 = F_3 ( V_33 ) ;
V_3 &= ~ ( V_34 | V_35 |
V_36 | V_37 |
V_38 | V_39 |
V_40 | V_41 ) ;
switch ( V_30 ) {
case V_42 :
V_3 |= V_43 ;
break;
case V_44 :
V_3 |= V_45 ;
break;
case V_46 :
V_3 |= ( V_45 | V_47 ) ;
break;
case V_48 :
V_3 |= ( V_49 |
V_50 |
V_51 ) ;
break;
case V_52 :
V_3 |= ( V_49 |
V_50 |
V_53 ) ;
break;
case V_54 :
V_3 |= ( V_49 |
V_55 |
V_51 ) ;
break;
case V_56 :
V_3 |= ( V_49 |
V_55 |
V_53 ) ;
break;
case V_57 :
case V_58 :
V_3 |= ( V_53 |
V_59 ) ;
break;
case V_60 :
V_3 |= V_61 ;
break;
case V_62 :
case V_63 :
V_3 |= V_64 ;
break;
case V_65 :
case V_66 :
V_3 |= ( V_51 |
V_59 ) ;
break;
default:
F_19 ( V_32 -> V_29 , L_4 , V_30 ) ;
return - V_67 ;
}
F_2 ( V_3 , V_33 ) ;
return 0 ;
}
static int F_20 ( struct V_28 * V_29 ,
enum V_68 V_69 ,
enum V_70 V_71 , bool * V_72 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_31 * V_32 = & V_2 -> V_32 ;
T_1 V_3 ;
F_16 ( L_5 , V_69 , V_71 ) ;
V_3 = F_3 ( V_33 ) ;
V_3 &= ~ V_73 ;
switch ( V_69 ) {
case V_74 :
if ( V_71 & V_75 )
V_3 |= V_76 ;
if ( V_71 & V_77 )
V_3 |= V_78 ;
break;
case V_79 :
if ( V_71 & V_75 )
V_3 |= V_80 ;
else if ( V_71 & V_77 )
V_3 |= V_81 ;
else
V_3 |= V_82 ;
break;
case V_83 :
V_3 |= V_84 ;
if ( V_71 & V_75 )
V_3 &= ~ V_76 ;
if ( V_71 & V_77 )
V_3 &= ~ V_78 ;
break;
case V_85 :
V_3 |= V_86 ;
if ( V_71 & V_75 )
V_3 &= ~ V_76 ;
if ( V_71 & V_77 )
V_3 &= ~ V_78 ;
break;
default:
F_19 ( V_32 -> V_29 , L_6 , V_69 ) ;
return - V_67 ;
}
F_2 ( V_3 , V_33 ) ;
V_2 -> V_87 = ( V_3 & V_82 ) ? 1 : 0 ;
* V_72 = V_2 -> V_87 ;
return 0 ;
}
static int F_21 ( struct V_28 * V_29 , int V_72 ,
struct V_88 * V_89 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_88 V_92 = * V_89 ;
struct V_93 * V_94 = & V_2 -> V_94 ;
T_1 V_3 ;
F_16 ( L_7 ,
V_72 , V_89 -> V_95 , V_89 -> V_96 , V_89 -> V_97 , V_89 -> V_98 ) ;
if ( V_72 ) {
V_92 . V_97 = V_89 -> V_98 ;
V_92 . V_98 = V_89 -> V_97 ;
}
V_3 = ( F_22 ( V_92 . V_95 ) |
F_23 ( V_92 . V_96 ) ) ;
F_2 ( V_3 , V_99 ) ;
V_3 = ( F_24 ( V_92 . V_97 ) |
F_25 ( V_92 . V_98 ) ) ;
F_2 ( V_3 , V_100 ) ;
F_16 ( L_8 , V_91 -> V_101 , V_91 -> V_102 ) ;
V_3 = F_3 ( V_103 ) ;
V_3 &= ~ ( V_104 |
V_105 ) ;
V_3 |= ( F_26 ( V_91 -> V_101 ) |
F_27 ( V_91 -> V_102 ) ) ;
F_2 ( V_3 , V_103 ) ;
V_3 = F_3 ( V_33 ) ;
V_3 &= ~ V_34 ;
F_16 ( L_9 , V_89 -> V_97 , V_94 -> V_106 ) ;
if ( V_89 -> V_97 >= V_107 )
if ( V_94 -> V_106 )
V_3 |= V_108 ;
else
V_3 |= V_109 ;
else
if ( V_94 -> V_106 )
V_3 |= V_110 ;
else
V_3 |= V_111 ;
F_2 ( V_3 , V_33 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , T_1 V_112 ,
enum V_113 V_114 )
{
struct V_31 * V_32 = & V_2 -> V_32 ;
bool V_115 ;
T_1 V_3 ;
T_1 V_116 = 0x00000001 << V_112 ;
F_16 ( L_10 , V_112 , V_114 ) ;
V_3 = F_3 ( V_9 ) ;
switch ( V_114 ) {
case V_117 :
V_115 = false ;
break;
case V_118 :
V_115 = true ;
break;
default:
F_19 ( V_32 -> V_29 , L_11 ) ;
return - V_67 ;
}
V_3 &= ~ V_116 ;
V_3 |= V_115 << V_112 ;
F_2 ( V_3 , V_9 ) ;
F_2 ( V_3 , V_11 ) ;
F_2 ( V_3 , V_12 ) ;
return 0 ;
}
static int F_29 ( struct V_28 * V_29 ,
struct V_119 * V_120 , T_1 V_112 ,
enum V_113 V_114 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_31 * V_32 = & V_2 -> V_32 ;
struct V_121 * V_122 = V_32 -> V_122 ;
struct V_123 * V_124 ;
if ( ! V_122 ) {
F_5 ( L_12 ) ;
return - V_125 ;
}
V_124 = & V_122 -> V_124 ;
F_16 ( L_13 ,
V_124 -> V_126 , V_112 , V_114 ) ;
if ( V_112 > V_127 ) {
F_30 ( V_32 -> V_29 , L_14 , V_112 ) ;
return - V_67 ;
}
switch ( V_114 ) {
case V_117 :
F_2 ( V_120 -> V_128 [ V_129 ] ,
F_31 ( V_112 ) ) ;
F_2 ( V_120 -> V_128 [ V_130 ] ,
F_32 ( V_112 ) ) ;
F_2 ( V_120 -> V_128 [ V_131 ] ,
F_33 ( V_112 ) ) ;
break;
case V_118 :
F_2 ( 0x0 , F_31 ( V_112 ) ) ;
F_2 ( 0x0 , F_32 ( V_112 ) ) ;
F_2 ( 0x0 , F_33 ( V_112 ) ) ;
break;
default:
break;
}
return F_28 ( V_2 , V_112 , V_114 ) ;
}
static int F_34 ( struct V_28 * V_29 , T_1 V_30 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_31 * V_32 = & V_2 -> V_32 ;
T_1 V_3 ;
F_16 ( L_3 , V_30 ) ;
V_3 = F_3 ( V_132 ) ;
V_3 &= ~ ( V_133 | V_134 |
V_135 | V_136 |
V_137 | V_138 |
V_139 ) ;
switch ( V_30 ) {
case V_42 :
V_3 |= V_140 ;
break;
case V_44 :
V_3 |= V_141 ;
break;
case V_46 :
V_3 |= ( V_141 | V_142 ) ;
break;
case V_48 :
V_3 |= ( V_143 |
V_144 |
V_145 ) ;
break;
case V_52 :
V_3 |= ( V_143 |
V_144 |
V_146 ) ;
break;
case V_54 :
V_3 |= ( V_143 |
V_147 |
V_145 ) ;
break;
case V_56 :
V_3 |= ( V_143 |
V_147 |
V_146 ) ;
break;
case V_57 :
case V_58 :
V_3 |= ( V_146 | V_148 ) ;
break;
case V_60 :
case V_62 :
case V_63 :
V_3 |= V_149 ;
break;
case V_65 :
case V_66 :
V_3 |= ( V_145 |
V_148 ) ;
break;
default:
F_19 ( V_32 -> V_29 , L_4 , V_30 ) ;
return - V_67 ;
}
F_2 ( V_3 , V_132 ) ;
return 0 ;
}
static int F_35 ( struct V_28 * V_29 ,
enum V_68 V_69 ,
enum V_70 V_71 , bool * V_72 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_31 * V_32 = & V_2 -> V_32 ;
T_1 V_3 ;
F_16 ( L_5 , V_69 , V_71 ) ;
V_3 = F_3 ( V_33 ) ;
V_3 &= ~ V_73 ;
switch ( V_69 ) {
case V_74 :
if ( V_71 & V_75 )
V_3 |= V_76 ;
if ( V_71 & V_77 )
V_3 |= V_78 ;
break;
case V_79 :
if ( V_71 & V_75 )
V_3 |= V_80 ;
else if ( V_71 & V_77 )
V_3 |= V_81 ;
else
V_3 |= V_82 ;
break;
case V_83 :
V_3 |= V_84 ;
if ( V_71 & V_75 )
V_3 &= ~ V_76 ;
if ( V_71 & V_77 )
V_3 &= ~ V_78 ;
break;
case V_85 :
V_3 |= V_86 ;
if ( V_71 & V_75 )
V_3 &= ~ V_76 ;
if ( V_71 & V_77 )
V_3 &= ~ V_78 ;
break;
default:
F_19 ( V_32 -> V_29 , L_6 , V_69 ) ;
return - V_67 ;
}
F_2 ( V_3 , V_33 ) ;
V_2 -> V_87 = ( V_3 & V_82 ) ? 1 : 0 ;
* V_72 = V_2 -> V_87 ;
return 0 ;
}
static int F_36 ( T_1 V_150 , T_1 V_151 , T_1 * V_152 )
{
F_16 ( L_15 , V_150 , V_151 ) ;
if ( V_150 >= V_151 * 8 ) {
F_5 ( L_16 ) ;
return - V_67 ;
} else if ( V_150 >= V_151 * 4 )
* V_152 = 4 ;
else if ( V_150 >= V_151 * 2 )
* V_152 = 2 ;
else
* V_152 = 1 ;
return 0 ;
}
static void F_37 ( T_1 V_153 , T_1 V_154 , T_1 * V_155 )
{
if ( V_153 == 4 && V_154 == 4 )
* V_155 = 4 ;
else if ( ( V_153 == 4 && V_154 == 2 ) ||
( V_153 == 2 && V_154 == 4 ) )
* V_155 = 3 ;
else if ( ( V_153 == 4 && V_154 == 1 ) ||
( V_153 == 1 && V_154 == 4 ) ||
( V_153 == 2 && V_154 == 2 ) )
* V_155 = 2 ;
else if ( V_153 == 1 && V_154 == 1 )
* V_155 = 0 ;
else
* V_155 = 1 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_93 * V_94 ,
struct V_88 * V_150 , struct V_88 * V_151 )
{
struct V_31 * V_32 = & V_2 -> V_32 ;
T_1 V_3 ;
T_1 V_156 , V_157 , V_158 , V_159 ;
int V_160 = 0 ;
V_156 = V_150 -> V_97 ;
V_157 = V_150 -> V_98 ;
if ( V_2 -> V_87 ) {
V_158 = V_151 -> V_98 ;
V_159 = V_151 -> V_97 ;
} else {
V_158 = V_151 -> V_97 ;
V_159 = V_151 -> V_98 ;
}
V_160 = F_36 ( V_156 , V_158 , & V_94 -> V_161 ) ;
if ( V_160 ) {
F_19 ( V_32 -> V_29 , L_17 ) ;
return V_160 ;
}
V_160 = F_36 ( V_157 , V_159 , & V_94 -> V_162 ) ;
if ( V_160 ) {
F_19 ( V_32 -> V_29 , L_18 ) ;
return V_160 ;
}
F_16 ( L_19 ,
V_94 -> V_161 , V_94 -> V_162 ) ;
V_94 -> V_163 = ( V_156 << 16 ) / V_158 ;
V_94 -> V_164 = ( V_157 << 16 ) / V_159 ;
F_16 ( L_20 ,
V_94 -> V_163 , V_94 -> V_164 ) ;
F_37 ( V_94 -> V_161 , V_94 -> V_162 ,
& V_94 -> V_165 ) ;
F_16 ( L_21 , V_94 -> V_165 ) ;
V_3 = ( F_39 ( V_94 -> V_165 ) |
F_40 ( V_94 -> V_161 ) |
F_41 ( V_94 -> V_162 ) ) ;
F_2 ( V_3 , V_166 ) ;
return V_160 ;
}
static void F_42 ( struct V_1 * V_2 , unsigned long V_163 )
{
int V_167 , V_168 , V_169 , V_170 ;
if ( V_163 <= V_171 )
V_170 = 0 ;
else if ( V_163 <= V_172 )
V_170 = 1 ;
else if ( V_163 <= V_173 )
V_170 = 2 ;
else if ( V_163 <= V_174 )
V_170 = 3 ;
else if ( V_163 <= V_175 )
V_170 = 4 ;
else if ( V_163 <= V_176 )
V_170 = 5 ;
else
V_170 = 6 ;
for ( V_167 = 0 ; V_167 < V_177 ; V_167 ++ )
for ( V_168 = 0 ; V_168 < V_178 ; V_168 ++ )
for ( V_169 = 0 ; V_169 < V_179 ; V_169 ++ )
F_2 ( V_180 [ V_170 ] [ V_167 ] [ V_168 ] ,
F_43 ( V_167 , V_168 , V_169 ) ) ;
}
static void F_44 ( struct V_1 * V_2 , unsigned long V_164 )
{
int V_167 , V_168 , V_169 , V_170 ;
if ( V_164 <= V_171 )
V_170 = 0 ;
else if ( V_164 <= V_172 )
V_170 = 1 ;
else if ( V_164 <= V_173 )
V_170 = 2 ;
else if ( V_164 <= V_174 )
V_170 = 3 ;
else if ( V_164 <= V_175 )
V_170 = 4 ;
else if ( V_164 <= V_176 )
V_170 = 5 ;
else
V_170 = 6 ;
for ( V_167 = 0 ; V_167 < V_177 ; V_167 ++ )
for ( V_168 = 0 ; V_168 < V_181 ; V_168 ++ )
for ( V_169 = 0 ; V_169 < V_179 ; V_169 ++ )
F_2 ( V_182 [ V_170 ] [ V_167 ] [ V_168 ] ,
F_45 ( V_167 , V_168 , V_169 ) ) ;
}
static void F_46 ( struct V_1 * V_2 , struct V_93 * V_94 )
{
T_1 V_3 ;
F_16 ( L_20 ,
V_94 -> V_163 , V_94 -> V_164 ) ;
F_42 ( V_2 , V_94 -> V_163 ) ;
V_3 = F_47 ( V_94 -> V_163 ) ;
F_2 ( V_3 , V_183 ) ;
F_44 ( V_2 , V_94 -> V_164 ) ;
V_3 = F_48 ( V_94 -> V_164 ) ;
F_2 ( V_3 , V_184 ) ;
}
static int F_49 ( struct V_28 * V_29 , int V_72 ,
struct V_88 * V_89 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_88 V_92 = * V_89 ;
struct V_93 * V_94 = & V_2 -> V_94 ;
T_1 V_3 ;
F_16 ( L_7 ,
V_72 , V_89 -> V_95 , V_89 -> V_96 , V_89 -> V_97 , V_89 -> V_98 ) ;
if ( V_72 ) {
V_92 . V_97 = V_89 -> V_98 ;
V_92 . V_98 = V_89 -> V_97 ;
}
V_3 = ( F_50 ( V_89 -> V_95 ) |
F_51 ( V_89 -> V_96 ) ) ;
F_2 ( V_3 , V_185 ) ;
V_3 = ( F_52 ( V_92 . V_97 ) | F_53 ( V_92 . V_98 ) ) ;
F_2 ( V_3 , V_186 ) ;
F_16 ( L_8 , V_91 -> V_101 , V_91 -> V_102 ) ;
V_3 = F_3 ( V_187 ) ;
V_3 &= ~ ( V_188 |
V_189 ) ;
V_3 |= ( F_54 ( V_91 -> V_101 ) |
F_55 ( V_91 -> V_102 ) ) ;
F_2 ( V_3 , V_187 ) ;
V_3 = F_3 ( V_132 ) ;
V_3 &= ~ V_133 ;
F_16 ( L_9 , V_89 -> V_97 , V_94 -> V_106 ) ;
if ( V_89 -> V_97 >= V_107 )
if ( V_94 -> V_106 )
V_3 |= V_190 ;
else
V_3 |= V_191 ;
else
if ( V_94 -> V_106 )
V_3 |= V_192 ;
else
V_3 |= V_193 ;
F_2 ( V_3 , V_132 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
T_1 V_3 , V_167 , V_194 = V_195 ;
T_1 V_116 = 0x00000001 ;
V_3 = F_3 ( V_13 ) ;
for ( V_167 = 0 ; V_167 < V_195 ; V_167 ++ )
if ( V_3 & ( V_116 << V_167 ) )
V_194 -- ;
F_16 ( L_22 , V_194 ) ;
return V_194 ;
}
static int F_57 ( struct V_1 * V_2 , T_1 V_112 ,
enum V_113 V_114 )
{
struct V_31 * V_32 = & V_2 -> V_32 ;
bool V_115 ;
T_1 V_3 ;
T_1 V_116 = 0x00000001 << V_112 ;
int V_160 = 0 ;
F_16 ( L_10 , V_112 , V_114 ) ;
F_58 ( & V_2 -> V_196 ) ;
V_3 = F_3 ( V_13 ) ;
switch ( V_114 ) {
case V_117 :
V_115 = false ;
break;
case V_118 :
V_115 = true ;
break;
default:
F_19 ( V_32 -> V_29 , L_11 ) ;
V_160 = - V_67 ;
goto V_197;
}
V_3 &= ~ V_116 ;
V_3 |= V_115 << V_112 ;
F_2 ( V_3 , V_13 ) ;
F_2 ( V_3 , V_15 ) ;
F_2 ( V_3 , V_16 ) ;
if ( V_114 == V_117 &&
F_56 ( V_2 ) >= V_198 )
F_15 ( V_2 , true , false , true ) ;
if ( V_114 == V_118 &&
F_56 ( V_2 ) <= V_199 )
F_15 ( V_2 , false , false , true ) ;
V_197:
F_59 ( & V_2 -> V_196 ) ;
return V_160 ;
}
static int F_60 ( struct V_28 * V_29 ,
struct V_119 * V_120 , T_1 V_112 ,
enum V_113 V_114 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_31 * V_32 = & V_2 -> V_32 ;
struct V_121 * V_122 = V_32 -> V_122 ;
struct V_123 * V_124 ;
if ( ! V_122 ) {
F_5 ( L_12 ) ;
return - V_125 ;
}
V_124 = & V_122 -> V_124 ;
F_16 ( L_13 ,
V_124 -> V_126 , V_112 , V_114 ) ;
if ( V_112 > V_200 ) {
F_30 ( V_32 -> V_29 , L_14 , V_112 ) ;
return - V_67 ;
}
switch ( V_114 ) {
case V_117 :
F_2 ( V_120 -> V_128 [ V_129 ] ,
F_61 ( V_112 ) ) ;
F_2 ( V_120 -> V_128 [ V_130 ] ,
F_62 ( V_112 ) ) ;
F_2 ( V_120 -> V_128 [ V_131 ] ,
F_63 ( V_112 ) ) ;
break;
case V_118 :
F_2 ( 0x0 , F_61 ( V_112 ) ) ;
F_2 ( 0x0 , F_62 ( V_112 ) ) ;
F_2 ( 0x0 , F_63 ( V_112 ) ) ;
break;
default:
break;
}
return F_57 ( V_2 , V_112 , V_114 ) ;
}
static int F_64 ( struct V_1 * V_2 , bool V_17 )
{
F_16 ( L_23 , V_17 ) ;
if ( V_17 ) {
F_65 ( V_2 -> V_201 ) ;
V_2 -> V_202 = false ;
} else {
F_66 ( V_2 -> V_201 ) ;
V_2 -> V_202 = true ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
T_1 V_3 , V_203 , V_167 ;
T_1 V_112 = V_127 ;
int V_160 ;
F_16 ( L_24 , V_2 -> V_21 ) ;
V_3 = F_3 ( V_9 ) ;
V_203 = F_68 ( V_3 ) ;
for ( V_167 = V_203 ; V_167 < V_127 ; V_167 ++ ) {
if ( ! ( ( V_3 >> V_167 ) & 0x1 ) ) {
V_112 = V_167 ;
break;
}
}
if ( V_112 == V_127 ) {
F_5 ( L_25 ) ;
return - V_67 ;
}
V_160 = F_28 ( V_2 , V_112 , V_118 ) ;
if ( V_160 < 0 ) {
F_5 ( L_26 ) ;
return V_160 ;
}
F_16 ( L_27 , V_3 ,
V_203 , V_112 ) ;
return V_112 ;
}
static int F_69 ( struct V_1 * V_2 )
{
T_1 V_3 , V_203 , V_167 ;
T_1 V_112 = V_200 ;
int V_160 ;
F_16 ( L_24 , V_2 -> V_21 ) ;
V_3 = F_3 ( V_13 ) ;
V_203 = F_70 ( V_3 ) ;
for ( V_167 = V_203 ; V_167 < V_200 ; V_167 ++ ) {
if ( ! ( ( V_3 >> V_167 ) & 0x1 ) ) {
V_112 = V_167 ;
break;
}
}
if ( V_112 == V_200 ) {
F_5 ( L_28 ) ;
return - V_67 ;
}
V_160 = F_57 ( V_2 , V_112 , V_118 ) ;
if ( V_160 < 0 ) {
F_5 ( L_26 ) ;
return V_160 ;
}
F_16 ( L_27 , V_3 ,
V_203 , V_112 ) ;
return V_112 ;
}
static T_2 F_71 ( int V_204 , void * V_205 )
{
struct V_1 * V_2 = V_205 ;
struct V_31 * V_32 = & V_2 -> V_32 ;
struct V_121 * V_122 = V_32 -> V_122 ;
struct V_206 * V_207 =
V_122 -> V_207 ;
T_1 V_208 ;
int V_112 [ V_209 ] ;
F_16 ( L_24 , V_2 -> V_21 ) ;
V_208 = F_3 ( V_24 ) ;
if ( V_208 & V_210 ) {
F_19 ( V_32 -> V_29 , L_29 ,
V_2 -> V_21 , V_208 ) ;
return V_211 ;
}
if ( V_208 & V_212 ) {
F_72 ( V_32 -> V_29 , L_30 ,
V_2 -> V_21 , V_208 ) ;
V_112 [ V_213 ] = F_67 ( V_2 ) ;
if ( V_112 [ V_213 ] < 0 )
return V_214 ;
V_112 [ V_215 ] = F_69 ( V_2 ) ;
if ( V_112 [ V_215 ] < 0 )
return V_214 ;
F_16 ( L_31 ,
V_112 [ V_213 ] , V_112 [ V_215 ] ) ;
V_207 -> V_32 = V_32 ;
V_207 -> V_112 [ V_213 ] =
V_112 [ V_213 ] ;
V_207 -> V_112 [ V_215 ] =
V_112 [ V_215 ] ;
F_73 ( V_32 -> V_216 , & V_207 -> V_217 ) ;
}
return V_214 ;
}
static int F_74 ( struct V_31 * V_32 )
{
struct V_218 * V_219 = & V_32 -> V_219 ;
V_219 -> V_220 = 1 ;
V_219 -> V_221 = 1 ;
V_219 -> V_222 = V_223 ;
V_219 -> V_224 = V_225 ;
V_219 -> V_71 = ( 1 << V_75 ) |
( 1 << V_77 ) ;
V_219 -> V_69 = ( 1 << V_74 ) |
( 1 << V_79 ) |
( 1 << V_83 ) |
( 1 << V_85 ) ;
V_219 -> V_226 = 1 ;
V_219 -> V_227 = 1 ;
V_219 -> V_228 . V_101 = V_229 ;
V_219 -> V_228 . V_102 = V_229 ;
V_219 -> V_230 . V_101 = V_231 ;
V_219 -> V_230 . V_102 = V_231 ;
V_219 -> V_232 = 1 ;
V_219 -> V_233 . V_101 = V_234 ;
V_219 -> V_233 . V_102 = V_234 ;
V_219 -> V_235 . V_101 = V_236 ;
V_219 -> V_235 . V_102 = V_236 ;
return 0 ;
}
static inline bool F_75 ( enum V_70 V_71 )
{
switch ( V_71 ) {
case V_237 :
case V_75 :
case V_77 :
case V_238 :
return true ;
default:
F_16 ( L_32 ) ;
return false ;
}
}
static int F_76 ( struct V_28 * V_29 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_31 * V_32 = & V_2 -> V_32 ;
struct V_218 * V_239 = & V_32 -> V_219 ;
struct V_240 * V_241 ;
struct V_88 * V_89 ;
struct V_90 * V_91 ;
bool V_72 ;
int V_167 ;
F_77 (i) {
if ( ( V_167 == V_213 ) &&
( V_124 -> V_242 == V_243 ) )
continue;
V_241 = & V_124 -> V_241 [ V_167 ] ;
V_89 = & V_241 -> V_89 ;
V_91 = & V_241 -> V_91 ;
if ( ! F_75 ( V_241 -> V_71 ) ) {
F_5 ( L_33 ) ;
goto V_244;
}
switch ( V_241 -> V_69 ) {
case V_79 :
case V_85 :
V_72 = true ;
break;
case V_74 :
case V_83 :
V_72 = false ;
break;
default:
F_5 ( L_34 ) ;
goto V_244;
}
if ( ( V_89 -> V_95 + V_89 -> V_97 > V_91 -> V_101 ) ||
( V_89 -> V_96 + V_89 -> V_98 > V_91 -> V_102 ) ) {
F_5 ( L_35 ) ;
goto V_244;
}
if ( ( V_167 == V_213 ) && ( V_239 -> V_227 ) ) {
if ( V_72 ) {
if ( ( V_89 -> V_98 < V_239 -> V_230 . V_101 ) ||
( V_91 -> V_102 > V_239 -> V_228 . V_101 ) ||
( V_89 -> V_97 < V_239 -> V_230 . V_102 ) ||
( V_91 -> V_101 > V_239 -> V_228 . V_102 ) ) {
F_5 ( L_36 ) ;
goto V_244;
}
} else {
if ( ( V_89 -> V_97 < V_239 -> V_230 . V_101 ) ||
( V_91 -> V_101 > V_239 -> V_228 . V_101 ) ||
( V_89 -> V_98 < V_239 -> V_230 . V_102 ) ||
( V_91 -> V_102 > V_239 -> V_228 . V_102 ) ) {
F_5 ( L_36 ) ;
goto V_244;
}
}
}
if ( ( V_167 == V_215 ) && ( V_239 -> V_232 ) ) {
if ( V_72 ) {
if ( ( V_89 -> V_98 < V_239 -> V_235 . V_101 ) ||
( V_91 -> V_102 > V_239 -> V_233 . V_101 ) ||
( V_89 -> V_97 < V_239 -> V_235 . V_102 ) ||
( V_91 -> V_101 > V_239 -> V_233 . V_102 ) ) {
F_5 ( L_37 ) ;
goto V_244;
}
} else {
if ( ( V_89 -> V_97 < V_239 -> V_235 . V_101 ) ||
( V_91 -> V_101 > V_239 -> V_233 . V_101 ) ||
( V_89 -> V_98 < V_239 -> V_235 . V_102 ) ||
( V_91 -> V_102 > V_239 -> V_233 . V_102 ) ) {
F_5 ( L_37 ) ;
goto V_244;
}
}
}
}
return 0 ;
V_244:
F_77 (i) {
if ( ( V_167 == V_213 ) &&
( V_124 -> V_242 == V_243 ) )
continue;
V_241 = & V_124 -> V_241 [ V_167 ] ;
V_89 = & V_241 -> V_89 ;
V_91 = & V_241 -> V_91 ;
F_5 ( L_38 ,
V_167 ? L_39 : L_40 , V_241 -> V_71 , V_241 -> V_69 ,
V_89 -> V_95 , V_89 -> V_96 , V_89 -> V_97 , V_89 -> V_98 ,
V_91 -> V_101 , V_91 -> V_102 ) ;
}
return - V_67 ;
}
static int F_78 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_93 * V_94 = & V_2 -> V_94 ;
int V_160 ;
V_160 = F_1 ( V_2 ) ;
if ( V_160 < 0 ) {
F_19 ( V_29 , L_41 ) ;
return V_160 ;
}
memset ( & V_2 -> V_94 , 0x0 , sizeof( V_2 -> V_94 ) ) ;
V_94 -> V_106 = true ;
return 0 ;
}
static int F_79 ( struct V_28 * V_29 , enum V_245 V_242 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_31 * V_32 = & V_2 -> V_32 ;
struct V_121 * V_122 = V_32 -> V_122 ;
struct V_123 * V_124 ;
struct V_240 * V_241 ;
struct V_88 V_92 [ V_209 ] ;
struct V_246 V_247 ;
T_1 V_3 ;
int V_160 , V_167 ;
F_16 ( L_42 , V_242 ) ;
if ( ! V_122 ) {
F_5 ( L_12 ) ;
return - V_67 ;
}
V_124 = & V_122 -> V_124 ;
F_15 ( V_2 , true , false , true ) ;
F_77 (i) {
V_241 = & V_124 -> V_241 [ V_167 ] ;
V_92 [ V_167 ] = V_241 -> V_89 ;
}
switch ( V_242 ) {
case V_248 :
V_3 = F_3 ( V_249 ) ;
V_3 &= ~ ( V_250 |
V_251 ) ;
V_3 |= V_252 ;
F_2 ( V_3 , V_249 ) ;
V_3 = F_3 ( V_33 ) ;
V_3 &= ~ ( V_253 | V_254 ) ;
V_3 |= V_255 ;
F_2 ( V_3 , V_33 ) ;
V_3 = F_3 ( V_132 ) ;
V_3 |= V_256 ;
F_2 ( V_3 , V_132 ) ;
break;
case V_243 :
V_247 . V_17 = 1 ;
V_247 . V_257 = V_124 -> V_258 ;
F_8 ( V_2 , V_247 . V_17 ) ;
F_80 ( V_259 , ( void * ) & V_247 ) ;
V_3 = F_3 ( V_33 ) ;
V_3 &= ~ ( V_253 | V_254 ) ;
V_3 |= ( V_260 | V_261 ) ;
F_2 ( V_3 , V_33 ) ;
V_3 = F_3 ( V_132 ) ;
V_3 |= V_256 ;
F_2 ( V_3 , V_132 ) ;
break;
case V_262 :
V_3 = F_3 ( V_33 ) ;
V_3 &= ~ ( V_253 | V_254 ) ;
V_3 |= V_255 ;
F_2 ( V_3 , V_33 ) ;
V_3 = F_3 ( V_132 ) ;
V_3 |= V_256 ;
F_2 ( V_3 , V_132 ) ;
break;
default:
V_160 = - V_67 ;
F_19 ( V_29 , L_43 ) ;
return V_160 ;
}
V_160 = F_38 ( V_2 , & V_2 -> V_94 ,
& V_92 [ V_213 ] ,
& V_92 [ V_215 ] ) ;
if ( V_160 ) {
F_19 ( V_29 , L_44 ) ;
return V_160 ;
}
F_46 ( V_2 , & V_2 -> V_94 ) ;
V_3 = F_3 ( V_249 ) ;
V_3 |= V_263 ;
F_2 ( V_3 , V_249 ) ;
return 0 ;
}
static void F_81 ( struct V_28 * V_29 , enum V_245 V_242 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_246 V_247 = { 0 , 0 } ;
T_1 V_3 ;
F_16 ( L_42 , V_242 ) ;
switch ( V_242 ) {
case V_248 :
break;
case V_243 :
F_8 ( V_2 , V_247 . V_17 ) ;
F_80 ( V_259 , ( void * ) & V_247 ) ;
break;
case V_262 :
default:
F_19 ( V_29 , L_43 ) ;
break;
}
F_15 ( V_2 , false , false , true ) ;
F_2 ( 0xff , V_13 ) ;
F_2 ( 0xff , V_15 ) ;
F_2 ( 0xff , V_16 ) ;
V_3 = F_3 ( V_249 ) ;
V_3 &= ~ V_263 ;
F_2 ( V_3 , V_249 ) ;
}
static int F_82 ( struct V_264 * V_265 )
{
struct V_28 * V_29 = & V_265 -> V_29 ;
struct V_1 * V_2 ;
struct V_266 * V_267 ;
struct V_31 * V_32 ;
int V_160 ;
V_2 = F_83 ( V_29 , sizeof( * V_2 ) , V_268 ) ;
if ( ! V_2 )
return - V_269 ;
if ( V_29 -> V_270 ) {
V_2 -> V_19 = F_84 ( V_29 -> V_270 ,
L_45 ) ;
if ( F_85 ( V_2 -> V_19 ) ) {
F_86 ( V_29 , L_46 ) ;
V_2 -> V_19 = NULL ;
}
}
V_2 -> V_201 = F_87 ( V_29 , L_47 ) ;
if ( F_85 ( V_2 -> V_201 ) ) {
F_19 ( V_29 , L_48 ) ;
return F_88 ( V_2 -> V_201 ) ;
}
V_2 -> V_271 = F_89 ( V_265 , V_272 , 0 ) ;
V_2 -> V_273 = F_90 ( V_29 , V_2 -> V_271 ) ;
if ( F_85 ( V_2 -> V_273 ) )
return F_88 ( V_2 -> V_273 ) ;
V_267 = F_89 ( V_265 , V_274 , 0 ) ;
if ( ! V_267 ) {
F_19 ( V_29 , L_49 ) ;
return - V_275 ;
}
V_2 -> V_204 = V_267 -> V_276 ;
V_160 = F_91 ( V_29 , V_2 -> V_204 , NULL , F_71 ,
V_277 , L_50 , V_2 ) ;
if ( V_160 < 0 ) {
F_19 ( V_29 , L_51 ) ;
return V_160 ;
}
V_2 -> V_21 = V_265 -> V_21 ;
V_32 = & V_2 -> V_32 ;
V_32 -> V_29 = V_29 ;
V_32 -> V_278 [ V_213 ] = & V_279 ;
V_32 -> V_278 [ V_215 ] = & V_280 ;
V_32 -> V_281 = F_76 ;
V_32 -> V_282 = F_78 ;
V_32 -> V_276 = F_79 ;
V_32 -> V_283 = F_81 ;
V_160 = F_74 ( V_32 ) ;
if ( V_160 < 0 ) {
F_19 ( V_29 , L_52 ) ;
return V_160 ;
}
F_16 ( L_53 , V_2 -> V_21 , V_32 ) ;
F_92 ( & V_2 -> V_196 ) ;
F_93 ( V_265 , V_2 ) ;
F_94 ( V_29 ) ;
V_160 = F_95 ( V_32 ) ;
if ( V_160 < 0 ) {
F_19 ( V_29 , L_54 ) ;
goto V_284;
}
F_30 ( V_29 , L_55 ) ;
return 0 ;
V_284:
F_96 ( V_29 ) ;
return V_160 ;
}
static int F_97 ( struct V_264 * V_265 )
{
struct V_28 * V_29 = & V_265 -> V_29 ;
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_31 * V_32 = & V_2 -> V_32 ;
F_98 ( V_32 ) ;
F_99 ( & V_2 -> V_196 ) ;
F_100 ( V_29 ) ;
F_96 ( V_29 ) ;
return 0 ;
}
static int F_101 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
F_16 ( L_56 , V_2 -> V_21 ) ;
if ( F_102 ( V_29 ) )
return 0 ;
return F_64 ( V_2 , false ) ;
}
static int F_103 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
F_16 ( L_56 , V_2 -> V_21 ) ;
if ( ! F_102 ( V_29 ) )
return F_64 ( V_2 , true ) ;
return 0 ;
}
static int F_104 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
F_16 ( L_56 , V_2 -> V_21 ) ;
return F_64 ( V_2 , false ) ;
}
static int F_105 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
F_16 ( L_56 , V_2 -> V_21 ) ;
return F_64 ( V_2 , true ) ;
}
