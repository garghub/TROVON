static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 = V_5 ;
F_2 ( L_1 , V_6 ) ;
V_3 = ( V_7 ) ;
F_3 ( V_3 , V_8 ) ;
while ( V_4 -- ) {
V_3 = F_4 ( V_8 ) ;
if ( ! V_3 )
break;
F_5 ( 1000 , 2000 ) ;
}
if ( V_3 ) {
F_6 ( L_2 ) ;
return - V_9 ;
}
V_3 = F_4 ( V_10 ) ;
V_3 |= ( V_11 |
F_7 ( 0 ) ) ;
F_3 ( V_3 , V_10 ) ;
F_3 ( V_3 , V_12 ) ;
F_3 ( V_3 , V_13 ) ;
V_3 = F_4 ( V_14 ) ;
V_3 |= ( V_15 |
F_8 ( 0 ) ) ;
F_3 ( V_3 , V_14 ) ;
F_3 ( V_3 , V_16 ) ;
F_3 ( V_3 , V_17 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 , bool V_18 )
{
T_1 V_19 ;
F_2 ( L_1 , V_6 ) ;
V_19 = F_10 ( V_20 ) ;
if ( V_18 )
V_19 |= F_11 ( V_2 -> V_21 ) |
F_12 ( V_2 -> V_21 ) |
F_13 ( V_2 -> V_21 ) ;
else
V_19 |= F_14 ( V_2 -> V_21 ) ;
F_15 ( V_19 , V_20 ) ;
}
static void F_16 ( struct V_1 * V_2 , bool V_18 ,
bool V_22 , bool V_23 )
{
T_1 V_3 ;
F_2 ( L_3 , V_6 ,
V_18 , V_22 , V_23 ) ;
V_3 = F_4 ( V_24 ) ;
V_3 |= ( V_25 | V_26 ) ;
if ( V_18 )
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
F_3 ( V_3 , V_24 ) ;
}
static int F_17 ( struct V_28 * V_29 , T_1 V_30 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_31 * V_32 = & V_2 -> V_32 ;
T_1 V_3 ;
F_2 ( L_4 , V_6 , V_30 ) ;
V_3 = F_4 ( V_33 ) ;
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
case V_67 :
V_3 |= ( V_68 | V_39 ) ;
break;
default:
F_19 ( V_32 -> V_29 , L_5 , V_30 ) ;
return - V_69 ;
}
F_3 ( V_3 , V_33 ) ;
return 0 ;
}
static int F_20 ( struct V_28 * V_29 ,
enum V_70 V_71 ,
enum V_72 V_73 , bool * V_74 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_31 * V_32 = & V_2 -> V_32 ;
T_1 V_3 ;
F_2 ( L_6 , V_6 ,
V_71 , V_73 ) ;
V_3 = F_4 ( V_33 ) ;
V_3 &= ~ V_75 ;
switch ( V_71 ) {
case V_76 :
if ( V_73 & V_77 )
V_3 |= V_78 ;
if ( V_73 & V_79 )
V_3 |= V_80 ;
break;
case V_81 :
if ( V_73 & V_77 )
V_3 |= V_82 ;
else if ( V_73 & V_79 )
V_3 |= V_83 ;
else
V_3 |= V_84 ;
break;
case V_85 :
V_3 |= V_86 ;
break;
case V_87 :
V_3 |= V_88 ;
break;
default:
F_19 ( V_32 -> V_29 , L_7 , V_71 ) ;
return - V_69 ;
}
F_3 ( V_3 , V_33 ) ;
V_2 -> V_89 = V_3 &
( V_84 | V_88 ) ? 1 : 0 ;
* V_74 = V_2 -> V_89 ;
return 0 ;
}
static int F_21 ( struct V_28 * V_29 , int V_74 ,
struct V_90 * V_91 , struct V_92 * V_93 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_90 V_94 = * V_91 ;
struct V_95 * V_96 = & V_2 -> V_96 ;
T_1 V_3 ;
F_2 ( L_8 ,
V_6 , V_74 , V_91 -> V_97 , V_91 -> V_98 , V_91 -> V_99 , V_91 -> V_100 ) ;
if ( V_74 ) {
V_94 . V_99 = V_91 -> V_100 ;
V_94 . V_100 = V_91 -> V_99 ;
}
V_3 = ( F_22 ( V_94 . V_97 ) |
F_23 ( V_94 . V_98 ) ) ;
F_3 ( V_3 , V_101 ) ;
V_3 = ( F_24 ( V_94 . V_99 ) |
F_25 ( V_94 . V_100 ) ) ;
F_3 ( V_3 , V_102 ) ;
F_2 ( L_9 ,
V_6 , V_93 -> V_103 , V_93 -> V_104 ) ;
V_3 = F_4 ( V_105 ) ;
V_3 &= ~ ( V_106 |
V_107 ) ;
V_3 |= ( F_26 ( V_93 -> V_103 ) |
F_27 ( V_93 -> V_104 ) ) ;
F_3 ( V_3 , V_105 ) ;
V_3 = F_4 ( V_33 ) ;
V_3 &= ~ V_34 ;
F_2 ( L_10 ,
V_6 , V_91 -> V_99 , V_96 -> V_108 ) ;
if ( V_91 -> V_99 >= V_109 )
if ( V_96 -> V_108 )
V_3 |= V_110 ;
else
V_3 |= V_111 ;
else
if ( V_96 -> V_108 )
V_3 |= V_112 ;
else
V_3 |= V_113 ;
F_3 ( V_3 , V_33 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , T_1 V_114 ,
enum V_115 V_116 )
{
struct V_31 * V_32 = & V_2 -> V_32 ;
bool V_117 ;
T_1 V_3 ;
T_1 V_118 = 0x00000001 << V_114 ;
F_2 ( L_11 , V_6 ,
V_114 , V_116 ) ;
V_3 = F_4 ( V_10 ) ;
switch ( V_116 ) {
case V_119 :
V_117 = false ;
break;
case V_120 :
V_117 = true ;
break;
default:
F_19 ( V_32 -> V_29 , L_12 ) ;
return - V_69 ;
}
V_3 &= ~ V_118 ;
V_3 |= V_117 << V_114 ;
F_3 ( V_3 , V_10 ) ;
F_3 ( V_3 , V_12 ) ;
F_3 ( V_3 , V_13 ) ;
return 0 ;
}
static int F_29 ( struct V_28 * V_29 ,
struct V_121 * V_122 , T_1 V_114 ,
enum V_115 V_116 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_31 * V_32 = & V_2 -> V_32 ;
struct V_123 * V_124 = V_32 -> V_124 ;
struct V_125 * V_126 ;
if ( ! V_124 ) {
F_6 ( L_13 ) ;
return - V_127 ;
}
V_126 = & V_124 -> V_126 ;
F_2 ( L_14 , V_6 ,
V_126 -> V_128 , V_114 , V_116 ) ;
if ( V_114 > V_129 ) {
F_30 ( V_32 -> V_29 , L_15 , V_114 ) ;
return - V_69 ;
}
switch ( V_116 ) {
case V_119 :
F_3 ( V_122 -> V_130 [ V_131 ] ,
F_31 ( V_114 ) ) ;
F_3 ( V_122 -> V_130 [ V_132 ] ,
F_32 ( V_114 ) ) ;
F_3 ( V_122 -> V_130 [ V_133 ] ,
F_33 ( V_114 ) ) ;
break;
case V_120 :
F_3 ( 0x0 , F_31 ( V_114 ) ) ;
F_3 ( 0x0 , F_32 ( V_114 ) ) ;
F_3 ( 0x0 , F_33 ( V_114 ) ) ;
break;
default:
break;
}
return F_28 ( V_2 , V_114 , V_116 ) ;
}
static int F_34 ( struct V_28 * V_29 , T_1 V_30 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_31 * V_32 = & V_2 -> V_32 ;
T_1 V_3 ;
F_2 ( L_4 , V_6 , V_30 ) ;
V_3 = F_4 ( V_134 ) ;
V_3 &= ~ ( V_135 | V_136 |
V_137 | V_138 |
V_139 | V_140 |
V_141 ) ;
switch ( V_30 ) {
case V_42 :
V_3 |= V_142 ;
break;
case V_44 :
V_3 |= V_143 ;
break;
case V_46 :
V_3 |= ( V_143 | V_144 ) ;
break;
case V_48 :
V_3 |= ( V_145 |
V_146 |
V_147 ) ;
break;
case V_52 :
V_3 |= ( V_145 |
V_146 |
V_148 ) ;
break;
case V_54 :
V_3 |= ( V_145 |
V_149 |
V_147 ) ;
break;
case V_56 :
V_3 |= ( V_145 |
V_149 |
V_148 ) ;
break;
case V_57 :
case V_58 :
V_3 |= ( V_148 | V_150 ) ;
break;
case V_60 :
case V_62 :
case V_63 :
V_3 |= V_151 ;
break;
case V_65 :
case V_66 :
V_3 |= ( V_147 |
V_150 ) ;
break;
case V_67 :
V_3 |= ( V_152 | V_153 ) ;
break;
default:
F_19 ( V_32 -> V_29 , L_5 , V_30 ) ;
return - V_69 ;
}
F_3 ( V_3 , V_134 ) ;
return 0 ;
}
static int F_35 ( struct V_28 * V_29 ,
enum V_70 V_71 ,
enum V_72 V_73 , bool * V_74 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_31 * V_32 = & V_2 -> V_32 ;
T_1 V_3 ;
F_2 ( L_6 , V_6 ,
V_71 , V_73 ) ;
V_3 = F_4 ( V_33 ) ;
V_3 &= ~ V_75 ;
switch ( V_71 ) {
case V_76 :
if ( V_73 & V_77 )
V_3 |= V_78 ;
if ( V_73 & V_79 )
V_3 |= V_80 ;
break;
case V_81 :
if ( V_73 & V_77 )
V_3 |= V_82 ;
else if ( V_73 & V_79 )
V_3 |= V_83 ;
else
V_3 |= V_84 ;
break;
case V_85 :
V_3 |= V_86 ;
break;
case V_87 :
V_3 |= V_88 ;
break;
default:
F_19 ( V_32 -> V_29 , L_7 , V_71 ) ;
return - V_69 ;
}
F_3 ( V_3 , V_33 ) ;
V_2 -> V_89 = V_3 &
( V_84 | V_88 ) ? 1 : 0 ;
* V_74 = V_2 -> V_89 ;
return 0 ;
}
static int F_36 ( T_1 V_154 , T_1 V_155 , T_1 * V_156 )
{
F_2 ( L_16 , V_6 , V_154 , V_155 ) ;
if ( V_154 >= V_155 * 8 ) {
F_6 ( L_17 ) ;
return - V_69 ;
} else if ( V_154 >= V_155 * 4 )
* V_156 = 4 ;
else if ( V_154 >= V_155 * 2 )
* V_156 = 2 ;
else
* V_156 = 1 ;
return 0 ;
}
static void F_37 ( T_1 V_157 , T_1 V_158 , T_1 * V_159 )
{
if ( V_157 == 4 && V_158 == 4 )
* V_159 = 4 ;
else if ( ( V_157 == 4 && V_158 == 2 ) ||
( V_157 == 2 && V_158 == 4 ) )
* V_159 = 3 ;
else if ( ( V_157 == 4 && V_158 == 1 ) ||
( V_157 == 1 && V_158 == 4 ) ||
( V_157 == 2 && V_158 == 2 ) )
* V_159 = 2 ;
else if ( V_157 == 1 && V_158 == 1 )
* V_159 = 0 ;
else
* V_159 = 1 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_95 * V_96 ,
struct V_90 * V_154 , struct V_90 * V_155 )
{
struct V_31 * V_32 = & V_2 -> V_32 ;
T_1 V_3 ;
T_1 V_160 , V_161 , V_162 , V_163 ;
int V_164 = 0 ;
V_160 = V_154 -> V_99 ;
V_161 = V_154 -> V_100 ;
if ( V_2 -> V_89 ) {
V_162 = V_155 -> V_100 ;
V_163 = V_155 -> V_99 ;
} else {
V_162 = V_155 -> V_99 ;
V_163 = V_155 -> V_100 ;
}
V_164 = F_36 ( V_160 , V_162 , & V_96 -> V_165 ) ;
if ( V_164 ) {
F_19 ( V_32 -> V_29 , L_18 ) ;
return V_164 ;
}
V_164 = F_36 ( V_161 , V_163 , & V_96 -> V_166 ) ;
if ( V_164 ) {
F_19 ( V_32 -> V_29 , L_19 ) ;
return V_164 ;
}
F_2 ( L_20 ,
V_6 , V_96 -> V_165 , V_96 -> V_166 ) ;
V_96 -> V_167 = ( V_160 << 16 ) / V_162 ;
V_96 -> V_168 = ( V_161 << 16 ) / V_163 ;
F_2 ( L_21 ,
V_6 , V_96 -> V_167 , V_96 -> V_168 ) ;
F_37 ( V_96 -> V_165 , V_96 -> V_166 ,
& V_96 -> V_169 ) ;
F_2 ( L_22 , V_6 ,
V_96 -> V_169 ) ;
V_3 = ( F_39 ( V_96 -> V_169 ) |
F_40 ( V_96 -> V_165 ) |
F_41 ( V_96 -> V_166 ) ) ;
F_3 ( V_3 , V_170 ) ;
return V_164 ;
}
static void F_42 ( struct V_1 * V_2 , unsigned long V_167 )
{
int V_171 , V_172 , V_173 , V_174 ;
if ( V_167 <= V_175 )
V_174 = 0 ;
else if ( V_167 <= V_176 )
V_174 = 1 ;
else if ( V_167 <= V_177 )
V_174 = 2 ;
else if ( V_167 <= V_178 )
V_174 = 3 ;
else if ( V_167 <= V_179 )
V_174 = 4 ;
else if ( V_167 <= V_180 )
V_174 = 5 ;
else
V_174 = 6 ;
for ( V_171 = 0 ; V_171 < V_181 ; V_171 ++ )
for ( V_172 = 0 ; V_172 < V_182 ; V_172 ++ )
for ( V_173 = 0 ; V_173 < V_183 ; V_173 ++ )
F_3 ( V_184 [ V_174 ] [ V_171 ] [ V_172 ] ,
F_43 ( V_171 , V_172 , V_173 ) ) ;
}
static void F_44 ( struct V_1 * V_2 , unsigned long V_168 )
{
int V_171 , V_172 , V_173 , V_174 ;
if ( V_168 <= V_175 )
V_174 = 0 ;
else if ( V_168 <= V_176 )
V_174 = 1 ;
else if ( V_168 <= V_177 )
V_174 = 2 ;
else if ( V_168 <= V_178 )
V_174 = 3 ;
else if ( V_168 <= V_179 )
V_174 = 4 ;
else if ( V_168 <= V_180 )
V_174 = 5 ;
else
V_174 = 6 ;
for ( V_171 = 0 ; V_171 < V_181 ; V_171 ++ )
for ( V_172 = 0 ; V_172 < V_185 ; V_172 ++ )
for ( V_173 = 0 ; V_173 < V_183 ; V_173 ++ )
F_3 ( V_186 [ V_174 ] [ V_171 ] [ V_172 ] ,
F_45 ( V_171 , V_172 , V_173 ) ) ;
}
static void F_46 ( struct V_1 * V_2 , struct V_95 * V_96 )
{
T_1 V_3 ;
F_2 ( L_21 ,
V_6 , V_96 -> V_167 , V_96 -> V_168 ) ;
F_42 ( V_2 , V_96 -> V_167 ) ;
V_3 = F_47 ( V_96 -> V_167 ) ;
F_3 ( V_3 , V_187 ) ;
F_44 ( V_2 , V_96 -> V_168 ) ;
V_3 = F_48 ( V_96 -> V_168 ) ;
F_3 ( V_3 , V_188 ) ;
}
static int F_49 ( struct V_28 * V_29 , int V_74 ,
struct V_90 * V_91 , struct V_92 * V_93 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_90 V_94 = * V_91 ;
struct V_95 * V_96 = & V_2 -> V_96 ;
T_1 V_3 ;
F_2 ( L_8 ,
V_6 , V_74 , V_91 -> V_97 , V_91 -> V_98 , V_91 -> V_99 , V_91 -> V_100 ) ;
if ( V_74 ) {
V_94 . V_99 = V_91 -> V_100 ;
V_94 . V_100 = V_91 -> V_99 ;
}
V_3 = ( F_50 ( V_91 -> V_97 ) |
F_51 ( V_91 -> V_98 ) ) ;
F_3 ( V_3 , V_189 ) ;
V_3 = ( F_52 ( V_94 . V_99 ) | F_53 ( V_94 . V_100 ) ) ;
F_3 ( V_3 , V_190 ) ;
F_2 ( L_9 ,
V_6 , V_93 -> V_103 , V_93 -> V_104 ) ;
V_3 = F_4 ( V_191 ) ;
V_3 &= ~ ( V_192 |
V_193 ) ;
V_3 |= ( F_54 ( V_93 -> V_103 ) |
F_55 ( V_93 -> V_104 ) ) ;
F_3 ( V_3 , V_191 ) ;
V_3 = F_4 ( V_134 ) ;
V_3 &= ~ V_135 ;
F_2 ( L_10 ,
V_6 , V_91 -> V_99 , V_96 -> V_108 ) ;
if ( V_91 -> V_99 >= V_109 )
if ( V_96 -> V_108 )
V_3 |= V_194 ;
else
V_3 |= V_195 ;
else
if ( V_96 -> V_108 )
V_3 |= V_196 ;
else
V_3 |= V_197 ;
F_3 ( V_3 , V_134 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
T_1 V_3 , V_171 , V_198 = V_199 ;
T_1 V_118 = 0x00000001 ;
V_3 = F_4 ( V_14 ) ;
for ( V_171 = 0 ; V_171 < V_199 ; V_171 ++ )
if ( V_3 & ( V_118 << V_171 ) )
V_198 -- ;
F_2 ( L_23 , V_6 , V_198 ) ;
return V_198 ;
}
static int F_57 ( struct V_1 * V_2 , T_1 V_114 ,
enum V_115 V_116 )
{
struct V_31 * V_32 = & V_2 -> V_32 ;
bool V_117 ;
T_1 V_3 ;
T_1 V_118 = 0x00000001 << V_114 ;
int V_164 = 0 ;
F_2 ( L_11 , V_6 ,
V_114 , V_116 ) ;
F_58 ( & V_2 -> V_200 ) ;
V_3 = F_4 ( V_14 ) ;
switch ( V_116 ) {
case V_119 :
V_117 = false ;
break;
case V_120 :
V_117 = true ;
break;
default:
F_19 ( V_32 -> V_29 , L_12 ) ;
V_164 = - V_69 ;
goto V_201;
}
V_3 &= ~ V_118 ;
V_3 |= V_117 << V_114 ;
F_3 ( V_3 , V_14 ) ;
F_3 ( V_3 , V_16 ) ;
F_3 ( V_3 , V_17 ) ;
if ( V_116 == V_119 &&
F_56 ( V_2 ) >= V_202 )
F_16 ( V_2 , true , false , true ) ;
if ( V_116 == V_120 &&
F_56 ( V_2 ) <= V_203 )
F_16 ( V_2 , false , false , true ) ;
V_201:
F_59 ( & V_2 -> V_200 ) ;
return V_164 ;
}
static int F_60 ( struct V_28 * V_29 ,
struct V_121 * V_122 , T_1 V_114 ,
enum V_115 V_116 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_31 * V_32 = & V_2 -> V_32 ;
struct V_123 * V_124 = V_32 -> V_124 ;
struct V_125 * V_126 ;
if ( ! V_124 ) {
F_6 ( L_13 ) ;
return - V_127 ;
}
V_126 = & V_124 -> V_126 ;
F_2 ( L_14 , V_6 ,
V_126 -> V_128 , V_114 , V_116 ) ;
if ( V_114 > V_204 ) {
F_30 ( V_32 -> V_29 , L_15 , V_114 ) ;
return - V_69 ;
}
switch ( V_116 ) {
case V_119 :
F_3 ( V_122 -> V_130 [ V_131 ] ,
F_61 ( V_114 ) ) ;
F_3 ( V_122 -> V_130 [ V_132 ] ,
F_62 ( V_114 ) ) ;
F_3 ( V_122 -> V_130 [ V_133 ] ,
F_63 ( V_114 ) ) ;
break;
case V_120 :
F_3 ( 0x0 , F_61 ( V_114 ) ) ;
F_3 ( 0x0 , F_62 ( V_114 ) ) ;
F_3 ( 0x0 , F_63 ( V_114 ) ) ;
break;
default:
break;
}
return F_57 ( V_2 , V_114 , V_116 ) ;
}
static int F_64 ( struct V_1 * V_2 , bool V_18 )
{
F_2 ( L_24 , V_6 , V_18 ) ;
if ( V_18 ) {
F_65 ( V_2 -> V_205 ) ;
V_2 -> V_206 = false ;
} else {
F_66 ( V_2 -> V_205 ) ;
V_2 -> V_206 = true ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
T_1 V_3 , V_207 , V_171 ;
T_1 V_114 = V_129 ;
int V_164 ;
F_2 ( L_25 , V_6 , V_2 -> V_21 ) ;
V_3 = F_4 ( V_10 ) ;
V_207 = F_68 ( V_3 ) ;
for ( V_171 = V_207 ; V_171 < V_129 ; V_171 ++ ) {
if ( ! ( ( V_3 >> V_171 ) & 0x1 ) ) {
V_114 = V_171 ;
break;
}
}
if ( V_114 == V_129 ) {
F_6 ( L_26 ) ;
return - V_69 ;
}
V_164 = F_28 ( V_2 , V_114 , V_120 ) ;
if ( V_164 < 0 ) {
F_6 ( L_27 ) ;
return V_164 ;
}
F_2 ( L_28 , V_6 , V_3 ,
V_207 , V_114 ) ;
return V_114 ;
}
static int F_69 ( struct V_1 * V_2 )
{
T_1 V_3 , V_207 , V_171 ;
T_1 V_114 = V_204 ;
int V_164 ;
F_2 ( L_25 , V_6 , V_2 -> V_21 ) ;
V_3 = F_4 ( V_14 ) ;
V_207 = F_70 ( V_3 ) ;
for ( V_171 = V_207 ; V_171 < V_204 ; V_171 ++ ) {
if ( ! ( ( V_3 >> V_171 ) & 0x1 ) ) {
V_114 = V_171 ;
break;
}
}
if ( V_114 == V_204 ) {
F_6 ( L_29 ) ;
return - V_69 ;
}
V_164 = F_57 ( V_2 , V_114 , V_120 ) ;
if ( V_164 < 0 ) {
F_6 ( L_27 ) ;
return V_164 ;
}
F_2 ( L_28 , V_6 , V_3 ,
V_207 , V_114 ) ;
return V_114 ;
}
static T_2 F_71 ( int V_208 , void * V_209 )
{
struct V_1 * V_2 = V_209 ;
struct V_31 * V_32 = & V_2 -> V_32 ;
struct V_123 * V_124 = V_32 -> V_124 ;
struct V_210 * V_211 =
V_124 -> V_211 ;
T_1 V_212 ;
int V_114 [ V_213 ] ;
F_2 ( L_25 , V_6 , V_2 -> V_21 ) ;
V_212 = F_4 ( V_24 ) ;
if ( V_212 & V_214 ) {
F_19 ( V_32 -> V_29 , L_30 ,
V_2 -> V_21 , V_212 ) ;
return V_215 ;
}
if ( V_212 & V_216 ) {
F_72 ( V_32 -> V_29 , L_31 ,
V_2 -> V_21 , V_212 ) ;
V_114 [ V_217 ] = F_67 ( V_2 ) ;
if ( V_114 [ V_217 ] < 0 )
return V_218 ;
V_114 [ V_219 ] = F_69 ( V_2 ) ;
if ( V_114 [ V_219 ] < 0 )
return V_218 ;
F_2 ( L_32 , V_6 ,
V_114 [ V_217 ] , V_114 [ V_219 ] ) ;
V_211 -> V_32 = V_32 ;
V_211 -> V_114 [ V_217 ] =
V_114 [ V_217 ] ;
V_211 -> V_114 [ V_219 ] =
V_114 [ V_219 ] ;
F_73 ( V_32 -> V_220 ,
(struct V_221 * ) V_211 ) ;
}
return V_218 ;
}
static int F_74 ( struct V_31 * V_32 )
{
struct V_222 * V_223 ;
F_2 ( L_1 , V_6 ) ;
V_223 = F_75 ( V_32 -> V_29 , sizeof( * V_223 ) , V_224 ) ;
if ( ! V_223 ) {
F_6 ( L_33 ) ;
return - V_225 ;
}
V_223 -> V_226 = 1 ;
V_223 -> V_227 = 1 ;
V_223 -> V_228 = V_229 ;
V_223 -> V_230 = V_231 ;
V_223 -> V_73 = ( 1 << V_77 ) |
( 1 << V_79 ) ;
V_223 -> V_71 = ( 1 << V_76 ) |
( 1 << V_81 ) |
( 1 << V_85 ) |
( 1 << V_87 ) ;
V_223 -> V_232 = 1 ;
V_223 -> V_233 = 1 ;
V_223 -> V_234 . V_103 = V_235 ;
V_223 -> V_234 . V_104 = V_235 ;
V_223 -> V_236 . V_103 = V_237 ;
V_223 -> V_236 . V_104 = V_237 ;
V_223 -> V_238 = 1 ;
V_223 -> V_239 . V_103 = V_240 ;
V_223 -> V_239 . V_104 = V_240 ;
V_223 -> V_241 . V_103 = V_242 ;
V_223 -> V_241 . V_104 = V_242 ;
V_32 -> V_223 = V_223 ;
return 0 ;
}
static inline bool F_76 ( enum V_72 V_73 )
{
switch ( V_73 ) {
case V_243 :
case V_77 :
case V_79 :
case V_244 :
return true ;
default:
F_2 ( L_34 , V_6 ) ;
return false ;
}
}
static int F_77 ( struct V_28 * V_29 ,
struct V_125 * V_126 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_31 * V_32 = & V_2 -> V_32 ;
struct V_222 * V_245 = V_32 -> V_223 ;
struct V_246 * V_247 ;
struct V_90 * V_91 ;
struct V_92 * V_93 ;
bool V_74 ;
int V_171 ;
F_2 ( L_1 , V_6 ) ;
F_78 (i) {
if ( ( V_171 == V_217 ) &&
( V_126 -> V_248 == V_249 ) )
continue;
V_247 = & V_126 -> V_247 [ V_171 ] ;
V_91 = & V_247 -> V_91 ;
V_93 = & V_247 -> V_93 ;
if ( ! F_76 ( V_247 -> V_73 ) ) {
F_6 ( L_35 ) ;
goto V_250;
}
switch ( V_247 -> V_71 ) {
case V_81 :
case V_87 :
V_74 = true ;
break;
case V_76 :
case V_85 :
V_74 = false ;
break;
default:
F_6 ( L_36 ) ;
goto V_250;
}
if ( ( V_91 -> V_97 + V_91 -> V_99 > V_93 -> V_103 ) ||
( V_91 -> V_98 + V_91 -> V_100 > V_93 -> V_104 ) ) {
F_6 ( L_37 ) ;
goto V_250;
}
if ( ( V_171 == V_217 ) && ( V_245 -> V_233 ) ) {
if ( V_74 ) {
if ( ( V_91 -> V_100 < V_245 -> V_236 . V_103 ) ||
( V_93 -> V_104 > V_245 -> V_234 . V_103 ) ||
( V_91 -> V_99 < V_245 -> V_236 . V_104 ) ||
( V_93 -> V_103 > V_245 -> V_234 . V_104 ) ) {
F_6 ( L_38 ) ;
goto V_250;
}
} else {
if ( ( V_91 -> V_99 < V_245 -> V_236 . V_103 ) ||
( V_93 -> V_103 > V_245 -> V_234 . V_103 ) ||
( V_91 -> V_100 < V_245 -> V_236 . V_104 ) ||
( V_93 -> V_104 > V_245 -> V_234 . V_104 ) ) {
F_6 ( L_38 ) ;
goto V_250;
}
}
}
if ( ( V_171 == V_219 ) && ( V_245 -> V_238 ) ) {
if ( V_74 ) {
if ( ( V_91 -> V_100 < V_245 -> V_241 . V_103 ) ||
( V_93 -> V_104 > V_245 -> V_239 . V_103 ) ||
( V_91 -> V_99 < V_245 -> V_241 . V_104 ) ||
( V_93 -> V_103 > V_245 -> V_239 . V_104 ) ) {
F_6 ( L_39 ) ;
goto V_250;
}
} else {
if ( ( V_91 -> V_99 < V_245 -> V_241 . V_103 ) ||
( V_93 -> V_103 > V_245 -> V_239 . V_103 ) ||
( V_91 -> V_100 < V_245 -> V_241 . V_104 ) ||
( V_93 -> V_104 > V_245 -> V_239 . V_104 ) ) {
F_6 ( L_39 ) ;
goto V_250;
}
}
}
}
return 0 ;
V_250:
F_78 (i) {
if ( ( V_171 == V_217 ) &&
( V_126 -> V_248 == V_249 ) )
continue;
V_247 = & V_126 -> V_247 [ V_171 ] ;
V_91 = & V_247 -> V_91 ;
V_93 = & V_247 -> V_93 ;
F_6 ( L_40 ,
V_171 ? L_41 : L_42 , V_247 -> V_73 , V_247 -> V_71 ,
V_91 -> V_97 , V_91 -> V_98 , V_91 -> V_99 , V_91 -> V_100 ,
V_93 -> V_103 , V_93 -> V_104 ) ;
}
return - V_69 ;
}
static int F_79 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_95 * V_96 = & V_2 -> V_96 ;
int V_164 ;
F_2 ( L_1 , V_6 ) ;
V_164 = F_1 ( V_2 ) ;
if ( V_164 < 0 ) {
F_19 ( V_29 , L_43 ) ;
return V_164 ;
}
memset ( & V_2 -> V_96 , 0x0 , sizeof( V_2 -> V_96 ) ) ;
V_96 -> V_108 = true ;
return 0 ;
}
static int F_80 ( struct V_28 * V_29 , enum V_251 V_248 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_31 * V_32 = & V_2 -> V_32 ;
struct V_123 * V_124 = V_32 -> V_124 ;
struct V_125 * V_126 ;
struct V_246 * V_247 ;
struct V_90 V_94 [ V_213 ] ;
struct V_252 V_253 ;
T_1 V_3 ;
int V_164 , V_171 ;
F_2 ( L_44 , V_6 , V_248 ) ;
if ( ! V_124 ) {
F_6 ( L_13 ) ;
return - V_69 ;
}
V_126 = & V_124 -> V_126 ;
F_16 ( V_2 , true , false , true ) ;
F_78 (i) {
V_247 = & V_126 -> V_247 [ V_171 ] ;
V_94 [ V_171 ] = V_247 -> V_91 ;
}
switch ( V_248 ) {
case V_254 :
V_3 = F_4 ( V_255 ) ;
V_3 &= ~ ( V_256 |
V_257 ) ;
V_3 |= V_258 ;
F_3 ( V_3 , V_255 ) ;
V_3 = F_4 ( V_33 ) ;
V_3 &= ~ ( V_259 | V_260 ) ;
V_3 |= V_261 ;
F_3 ( V_3 , V_33 ) ;
V_3 = F_4 ( V_134 ) ;
V_3 |= V_262 ;
F_3 ( V_3 , V_134 ) ;
break;
case V_249 :
V_253 . V_18 = 1 ;
V_253 . V_263 = V_126 -> V_264 ;
F_9 ( V_2 , V_253 . V_18 ) ;
F_81 ( V_265 , ( void * ) & V_253 ) ;
V_3 = F_4 ( V_33 ) ;
V_3 &= ~ ( V_259 | V_260 ) ;
V_3 |= ( V_266 | V_267 ) ;
F_3 ( V_3 , V_33 ) ;
V_3 = F_4 ( V_134 ) ;
V_3 |= V_262 ;
F_3 ( V_3 , V_134 ) ;
break;
case V_268 :
V_3 = F_4 ( V_33 ) ;
V_3 &= ~ ( V_259 | V_260 ) ;
V_3 |= V_261 ;
F_3 ( V_3 , V_33 ) ;
V_3 = F_4 ( V_134 ) ;
V_3 |= V_262 ;
F_3 ( V_3 , V_134 ) ;
break;
default:
V_164 = - V_69 ;
F_19 ( V_29 , L_45 ) ;
return V_164 ;
}
V_164 = F_38 ( V_2 , & V_2 -> V_96 ,
& V_94 [ V_217 ] ,
& V_94 [ V_219 ] ) ;
if ( V_164 ) {
F_19 ( V_29 , L_46 ) ;
return V_164 ;
}
F_46 ( V_2 , & V_2 -> V_96 ) ;
V_3 = F_4 ( V_255 ) ;
V_3 |= V_269 ;
F_3 ( V_3 , V_255 ) ;
return 0 ;
}
static void F_82 ( struct V_28 * V_29 , enum V_251 V_248 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_252 V_253 = { 0 , 0 } ;
T_1 V_3 ;
F_2 ( L_44 , V_6 , V_248 ) ;
switch ( V_248 ) {
case V_254 :
break;
case V_249 :
F_9 ( V_2 , V_253 . V_18 ) ;
F_81 ( V_265 , ( void * ) & V_253 ) ;
break;
case V_268 :
default:
F_19 ( V_29 , L_45 ) ;
break;
}
F_16 ( V_2 , false , false , true ) ;
F_3 ( 0xff , V_14 ) ;
F_3 ( 0xff , V_16 ) ;
F_3 ( 0xff , V_17 ) ;
V_3 = F_4 ( V_255 ) ;
V_3 &= ~ V_269 ;
F_3 ( V_3 , V_255 ) ;
}
static int F_83 ( struct V_270 * V_271 )
{
struct V_28 * V_29 = & V_271 -> V_29 ;
struct V_1 * V_2 ;
struct V_272 * V_273 ;
struct V_31 * V_32 ;
int V_164 ;
V_2 = F_75 ( V_29 , sizeof( * V_2 ) , V_224 ) ;
if ( ! V_2 )
return - V_225 ;
V_2 -> V_205 = F_84 ( V_29 , L_47 ) ;
if ( F_85 ( V_2 -> V_205 ) ) {
F_19 ( V_29 , L_48 ) ;
return F_86 ( V_2 -> V_205 ) ;
}
V_2 -> V_274 = F_87 ( V_271 , V_275 , 0 ) ;
V_2 -> V_276 = F_88 ( V_29 , V_2 -> V_274 ) ;
if ( F_85 ( V_2 -> V_276 ) )
return F_86 ( V_2 -> V_276 ) ;
V_273 = F_87 ( V_271 , V_277 , 0 ) ;
if ( ! V_273 ) {
F_19 ( V_29 , L_49 ) ;
return - V_278 ;
}
V_2 -> V_208 = V_273 -> V_279 ;
V_164 = F_89 ( V_29 , V_2 -> V_208 , NULL , F_71 ,
V_280 , L_50 , V_2 ) ;
if ( V_164 < 0 ) {
F_19 ( V_29 , L_51 ) ;
return V_164 ;
}
V_2 -> V_21 = V_271 -> V_21 ;
V_32 = & V_2 -> V_32 ;
V_32 -> V_29 = V_29 ;
V_32 -> V_281 [ V_217 ] = & V_282 ;
V_32 -> V_281 [ V_219 ] = & V_283 ;
V_32 -> V_284 = F_77 ;
V_32 -> V_285 = F_79 ;
V_32 -> V_279 = F_80 ;
V_32 -> V_286 = F_82 ;
V_164 = F_74 ( V_32 ) ;
if ( V_164 < 0 ) {
F_19 ( V_29 , L_52 ) ;
return V_164 ;
}
F_2 ( L_53 , V_6 , V_2 -> V_21 ,
( int ) V_32 ) ;
F_90 ( & V_2 -> V_200 ) ;
F_91 ( V_271 , V_2 ) ;
F_92 ( V_29 ) ;
F_93 ( V_29 ) ;
V_164 = F_94 ( V_32 ) ;
if ( V_164 < 0 ) {
F_19 ( V_29 , L_54 ) ;
goto V_287;
}
F_30 ( V_29 , L_55 ) ;
return 0 ;
V_287:
F_95 ( V_29 ) ;
return V_164 ;
}
static int F_96 ( struct V_270 * V_271 )
{
struct V_28 * V_29 = & V_271 -> V_29 ;
struct V_1 * V_2 = F_18 ( V_29 ) ;
struct V_31 * V_32 = & V_2 -> V_32 ;
F_97 ( V_32 ) ;
F_98 ( & V_2 -> V_200 ) ;
F_99 ( V_29 ) ;
F_95 ( V_29 ) ;
return 0 ;
}
static int F_100 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
F_2 ( L_56 , V_6 , V_2 -> V_21 ) ;
if ( F_101 ( V_29 ) )
return 0 ;
return F_64 ( V_2 , false ) ;
}
static int F_102 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
F_2 ( L_56 , V_6 , V_2 -> V_21 ) ;
if ( ! F_101 ( V_29 ) )
return F_64 ( V_2 , true ) ;
return 0 ;
}
static int F_103 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
F_2 ( L_56 , V_6 , V_2 -> V_21 ) ;
return F_64 ( V_2 , false ) ;
}
static int F_104 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_18 ( V_29 ) ;
F_2 ( L_56 , __FILE__ , V_2 -> V_21 ) ;
return F_64 ( V_2 , true ) ;
}
