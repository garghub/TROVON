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
case V_66 :
V_3 |= ( V_67 | V_38 ) ;
break;
default:
F_19 ( V_31 -> V_28 , L_4 , V_29 ) ;
return - V_68 ;
}
F_2 ( V_3 , V_32 ) ;
return 0 ;
}
static int F_20 ( struct V_27 * V_28 ,
enum V_69 V_70 ,
enum V_71 V_72 , bool * V_73 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_30 * V_31 = & V_2 -> V_31 ;
T_1 V_3 ;
F_16 ( L_5 , V_70 , V_72 ) ;
V_3 = F_3 ( V_32 ) ;
V_3 &= ~ V_74 ;
switch ( V_70 ) {
case V_75 :
if ( V_72 & V_76 )
V_3 |= V_77 ;
if ( V_72 & V_78 )
V_3 |= V_79 ;
break;
case V_80 :
if ( V_72 & V_76 )
V_3 |= V_81 ;
else if ( V_72 & V_78 )
V_3 |= V_82 ;
else
V_3 |= V_83 ;
break;
case V_84 :
V_3 |= V_85 ;
break;
case V_86 :
V_3 |= V_87 ;
break;
default:
F_19 ( V_31 -> V_28 , L_6 , V_70 ) ;
return - V_68 ;
}
F_2 ( V_3 , V_32 ) ;
V_2 -> V_88 = V_3 &
( V_83 | V_87 ) ? 1 : 0 ;
* V_73 = V_2 -> V_88 ;
return 0 ;
}
static int F_21 ( struct V_27 * V_28 , int V_73 ,
struct V_89 * V_90 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_89 V_93 = * V_90 ;
struct V_94 * V_95 = & V_2 -> V_95 ;
T_1 V_3 ;
F_16 ( L_7 ,
V_73 , V_90 -> V_96 , V_90 -> V_97 , V_90 -> V_98 , V_90 -> V_99 ) ;
if ( V_73 ) {
V_93 . V_98 = V_90 -> V_99 ;
V_93 . V_99 = V_90 -> V_98 ;
}
V_3 = ( F_22 ( V_93 . V_96 ) |
F_23 ( V_93 . V_97 ) ) ;
F_2 ( V_3 , V_100 ) ;
V_3 = ( F_24 ( V_93 . V_98 ) |
F_25 ( V_93 . V_99 ) ) ;
F_2 ( V_3 , V_101 ) ;
F_16 ( L_8 , V_92 -> V_102 , V_92 -> V_103 ) ;
V_3 = F_3 ( V_104 ) ;
V_3 &= ~ ( V_105 |
V_106 ) ;
V_3 |= ( F_26 ( V_92 -> V_102 ) |
F_27 ( V_92 -> V_103 ) ) ;
F_2 ( V_3 , V_104 ) ;
V_3 = F_3 ( V_32 ) ;
V_3 &= ~ V_33 ;
F_16 ( L_9 , V_90 -> V_98 , V_95 -> V_107 ) ;
if ( V_90 -> V_98 >= V_108 )
if ( V_95 -> V_107 )
V_3 |= V_109 ;
else
V_3 |= V_110 ;
else
if ( V_95 -> V_107 )
V_3 |= V_111 ;
else
V_3 |= V_112 ;
F_2 ( V_3 , V_32 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , T_1 V_113 ,
enum V_114 V_115 )
{
struct V_30 * V_31 = & V_2 -> V_31 ;
bool V_116 ;
T_1 V_3 ;
T_1 V_117 = 0x00000001 << V_113 ;
F_16 ( L_10 , V_113 , V_115 ) ;
V_3 = F_3 ( V_9 ) ;
switch ( V_115 ) {
case V_118 :
V_116 = false ;
break;
case V_119 :
V_116 = true ;
break;
default:
F_19 ( V_31 -> V_28 , L_11 ) ;
return - V_68 ;
}
V_3 &= ~ V_117 ;
V_3 |= V_116 << V_113 ;
F_2 ( V_3 , V_9 ) ;
F_2 ( V_3 , V_11 ) ;
F_2 ( V_3 , V_12 ) ;
return 0 ;
}
static int F_29 ( struct V_27 * V_28 ,
struct V_120 * V_121 , T_1 V_113 ,
enum V_114 V_115 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_30 * V_31 = & V_2 -> V_31 ;
struct V_122 * V_123 = V_31 -> V_123 ;
struct V_124 * V_125 ;
if ( ! V_123 ) {
F_5 ( L_12 ) ;
return - V_126 ;
}
V_125 = & V_123 -> V_125 ;
F_16 ( L_13 ,
V_125 -> V_127 , V_113 , V_115 ) ;
if ( V_113 > V_128 ) {
F_30 ( V_31 -> V_28 , L_14 , V_113 ) ;
return - V_68 ;
}
switch ( V_115 ) {
case V_118 :
F_2 ( V_121 -> V_129 [ V_130 ] ,
F_31 ( V_113 ) ) ;
F_2 ( V_121 -> V_129 [ V_131 ] ,
F_32 ( V_113 ) ) ;
F_2 ( V_121 -> V_129 [ V_132 ] ,
F_33 ( V_113 ) ) ;
break;
case V_119 :
F_2 ( 0x0 , F_31 ( V_113 ) ) ;
F_2 ( 0x0 , F_32 ( V_113 ) ) ;
F_2 ( 0x0 , F_33 ( V_113 ) ) ;
break;
default:
break;
}
return F_28 ( V_2 , V_113 , V_115 ) ;
}
static int F_34 ( struct V_27 * V_28 , T_1 V_29 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_30 * V_31 = & V_2 -> V_31 ;
T_1 V_3 ;
F_16 ( L_3 , V_29 ) ;
V_3 = F_3 ( V_133 ) ;
V_3 &= ~ ( V_134 | V_135 |
V_136 | V_137 |
V_138 | V_139 |
V_140 ) ;
switch ( V_29 ) {
case V_41 :
V_3 |= V_141 ;
break;
case V_43 :
V_3 |= V_142 ;
break;
case V_45 :
V_3 |= ( V_142 | V_143 ) ;
break;
case V_47 :
V_3 |= ( V_144 |
V_145 |
V_146 ) ;
break;
case V_51 :
V_3 |= ( V_144 |
V_145 |
V_147 ) ;
break;
case V_53 :
V_3 |= ( V_144 |
V_148 |
V_146 ) ;
break;
case V_55 :
V_3 |= ( V_144 |
V_148 |
V_147 ) ;
break;
case V_56 :
case V_57 :
V_3 |= ( V_147 | V_149 ) ;
break;
case V_59 :
case V_61 :
case V_62 :
V_3 |= V_150 ;
break;
case V_64 :
case V_65 :
V_3 |= ( V_146 |
V_149 ) ;
break;
case V_66 :
V_3 |= ( V_151 | V_152 ) ;
break;
default:
F_19 ( V_31 -> V_28 , L_4 , V_29 ) ;
return - V_68 ;
}
F_2 ( V_3 , V_133 ) ;
return 0 ;
}
static int F_35 ( struct V_27 * V_28 ,
enum V_69 V_70 ,
enum V_71 V_72 , bool * V_73 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_30 * V_31 = & V_2 -> V_31 ;
T_1 V_3 ;
F_16 ( L_5 , V_70 , V_72 ) ;
V_3 = F_3 ( V_32 ) ;
V_3 &= ~ V_74 ;
switch ( V_70 ) {
case V_75 :
if ( V_72 & V_76 )
V_3 |= V_77 ;
if ( V_72 & V_78 )
V_3 |= V_79 ;
break;
case V_80 :
if ( V_72 & V_76 )
V_3 |= V_81 ;
else if ( V_72 & V_78 )
V_3 |= V_82 ;
else
V_3 |= V_83 ;
break;
case V_84 :
V_3 |= V_85 ;
break;
case V_86 :
V_3 |= V_87 ;
break;
default:
F_19 ( V_31 -> V_28 , L_6 , V_70 ) ;
return - V_68 ;
}
F_2 ( V_3 , V_32 ) ;
V_2 -> V_88 = V_3 &
( V_83 | V_87 ) ? 1 : 0 ;
* V_73 = V_2 -> V_88 ;
return 0 ;
}
static int F_36 ( T_1 V_153 , T_1 V_154 , T_1 * V_155 )
{
F_16 ( L_15 , V_153 , V_154 ) ;
if ( V_153 >= V_154 * 8 ) {
F_5 ( L_16 ) ;
return - V_68 ;
} else if ( V_153 >= V_154 * 4 )
* V_155 = 4 ;
else if ( V_153 >= V_154 * 2 )
* V_155 = 2 ;
else
* V_155 = 1 ;
return 0 ;
}
static void F_37 ( T_1 V_156 , T_1 V_157 , T_1 * V_158 )
{
if ( V_156 == 4 && V_157 == 4 )
* V_158 = 4 ;
else if ( ( V_156 == 4 && V_157 == 2 ) ||
( V_156 == 2 && V_157 == 4 ) )
* V_158 = 3 ;
else if ( ( V_156 == 4 && V_157 == 1 ) ||
( V_156 == 1 && V_157 == 4 ) ||
( V_156 == 2 && V_157 == 2 ) )
* V_158 = 2 ;
else if ( V_156 == 1 && V_157 == 1 )
* V_158 = 0 ;
else
* V_158 = 1 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_94 * V_95 ,
struct V_89 * V_153 , struct V_89 * V_154 )
{
struct V_30 * V_31 = & V_2 -> V_31 ;
T_1 V_3 ;
T_1 V_159 , V_160 , V_161 , V_162 ;
int V_163 = 0 ;
V_159 = V_153 -> V_98 ;
V_160 = V_153 -> V_99 ;
if ( V_2 -> V_88 ) {
V_161 = V_154 -> V_99 ;
V_162 = V_154 -> V_98 ;
} else {
V_161 = V_154 -> V_98 ;
V_162 = V_154 -> V_99 ;
}
V_163 = F_36 ( V_159 , V_161 , & V_95 -> V_164 ) ;
if ( V_163 ) {
F_19 ( V_31 -> V_28 , L_17 ) ;
return V_163 ;
}
V_163 = F_36 ( V_160 , V_162 , & V_95 -> V_165 ) ;
if ( V_163 ) {
F_19 ( V_31 -> V_28 , L_18 ) ;
return V_163 ;
}
F_16 ( L_19 ,
V_95 -> V_164 , V_95 -> V_165 ) ;
V_95 -> V_166 = ( V_159 << 16 ) / V_161 ;
V_95 -> V_167 = ( V_160 << 16 ) / V_162 ;
F_16 ( L_20 ,
V_95 -> V_166 , V_95 -> V_167 ) ;
F_37 ( V_95 -> V_164 , V_95 -> V_165 ,
& V_95 -> V_168 ) ;
F_16 ( L_21 , V_95 -> V_168 ) ;
V_3 = ( F_39 ( V_95 -> V_168 ) |
F_40 ( V_95 -> V_164 ) |
F_41 ( V_95 -> V_165 ) ) ;
F_2 ( V_3 , V_169 ) ;
return V_163 ;
}
static void F_42 ( struct V_1 * V_2 , unsigned long V_166 )
{
int V_170 , V_171 , V_172 , V_173 ;
if ( V_166 <= V_174 )
V_173 = 0 ;
else if ( V_166 <= V_175 )
V_173 = 1 ;
else if ( V_166 <= V_176 )
V_173 = 2 ;
else if ( V_166 <= V_177 )
V_173 = 3 ;
else if ( V_166 <= V_178 )
V_173 = 4 ;
else if ( V_166 <= V_179 )
V_173 = 5 ;
else
V_173 = 6 ;
for ( V_170 = 0 ; V_170 < V_180 ; V_170 ++ )
for ( V_171 = 0 ; V_171 < V_181 ; V_171 ++ )
for ( V_172 = 0 ; V_172 < V_182 ; V_172 ++ )
F_2 ( V_183 [ V_173 ] [ V_170 ] [ V_171 ] ,
F_43 ( V_170 , V_171 , V_172 ) ) ;
}
static void F_44 ( struct V_1 * V_2 , unsigned long V_167 )
{
int V_170 , V_171 , V_172 , V_173 ;
if ( V_167 <= V_174 )
V_173 = 0 ;
else if ( V_167 <= V_175 )
V_173 = 1 ;
else if ( V_167 <= V_176 )
V_173 = 2 ;
else if ( V_167 <= V_177 )
V_173 = 3 ;
else if ( V_167 <= V_178 )
V_173 = 4 ;
else if ( V_167 <= V_179 )
V_173 = 5 ;
else
V_173 = 6 ;
for ( V_170 = 0 ; V_170 < V_180 ; V_170 ++ )
for ( V_171 = 0 ; V_171 < V_184 ; V_171 ++ )
for ( V_172 = 0 ; V_172 < V_182 ; V_172 ++ )
F_2 ( V_185 [ V_173 ] [ V_170 ] [ V_171 ] ,
F_45 ( V_170 , V_171 , V_172 ) ) ;
}
static void F_46 ( struct V_1 * V_2 , struct V_94 * V_95 )
{
T_1 V_3 ;
F_16 ( L_20 ,
V_95 -> V_166 , V_95 -> V_167 ) ;
F_42 ( V_2 , V_95 -> V_166 ) ;
V_3 = F_47 ( V_95 -> V_166 ) ;
F_2 ( V_3 , V_186 ) ;
F_44 ( V_2 , V_95 -> V_167 ) ;
V_3 = F_48 ( V_95 -> V_167 ) ;
F_2 ( V_3 , V_187 ) ;
}
static int F_49 ( struct V_27 * V_28 , int V_73 ,
struct V_89 * V_90 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_89 V_93 = * V_90 ;
struct V_94 * V_95 = & V_2 -> V_95 ;
T_1 V_3 ;
F_16 ( L_7 ,
V_73 , V_90 -> V_96 , V_90 -> V_97 , V_90 -> V_98 , V_90 -> V_99 ) ;
if ( V_73 ) {
V_93 . V_98 = V_90 -> V_99 ;
V_93 . V_99 = V_90 -> V_98 ;
}
V_3 = ( F_50 ( V_90 -> V_96 ) |
F_51 ( V_90 -> V_97 ) ) ;
F_2 ( V_3 , V_188 ) ;
V_3 = ( F_52 ( V_93 . V_98 ) | F_53 ( V_93 . V_99 ) ) ;
F_2 ( V_3 , V_189 ) ;
F_16 ( L_8 , V_92 -> V_102 , V_92 -> V_103 ) ;
V_3 = F_3 ( V_190 ) ;
V_3 &= ~ ( V_191 |
V_192 ) ;
V_3 |= ( F_54 ( V_92 -> V_102 ) |
F_55 ( V_92 -> V_103 ) ) ;
F_2 ( V_3 , V_190 ) ;
V_3 = F_3 ( V_133 ) ;
V_3 &= ~ V_134 ;
F_16 ( L_9 , V_90 -> V_98 , V_95 -> V_107 ) ;
if ( V_90 -> V_98 >= V_108 )
if ( V_95 -> V_107 )
V_3 |= V_193 ;
else
V_3 |= V_194 ;
else
if ( V_95 -> V_107 )
V_3 |= V_195 ;
else
V_3 |= V_196 ;
F_2 ( V_3 , V_133 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
T_1 V_3 , V_170 , V_197 = V_198 ;
T_1 V_117 = 0x00000001 ;
V_3 = F_3 ( V_13 ) ;
for ( V_170 = 0 ; V_170 < V_198 ; V_170 ++ )
if ( V_3 & ( V_117 << V_170 ) )
V_197 -- ;
F_16 ( L_22 , V_197 ) ;
return V_197 ;
}
static int F_57 ( struct V_1 * V_2 , T_1 V_113 ,
enum V_114 V_115 )
{
struct V_30 * V_31 = & V_2 -> V_31 ;
bool V_116 ;
T_1 V_3 ;
T_1 V_117 = 0x00000001 << V_113 ;
int V_163 = 0 ;
F_16 ( L_10 , V_113 , V_115 ) ;
F_58 ( & V_2 -> V_199 ) ;
V_3 = F_3 ( V_13 ) ;
switch ( V_115 ) {
case V_118 :
V_116 = false ;
break;
case V_119 :
V_116 = true ;
break;
default:
F_19 ( V_31 -> V_28 , L_11 ) ;
V_163 = - V_68 ;
goto V_200;
}
V_3 &= ~ V_117 ;
V_3 |= V_116 << V_113 ;
F_2 ( V_3 , V_13 ) ;
F_2 ( V_3 , V_15 ) ;
F_2 ( V_3 , V_16 ) ;
if ( V_115 == V_118 &&
F_56 ( V_2 ) >= V_201 )
F_15 ( V_2 , true , false , true ) ;
if ( V_115 == V_119 &&
F_56 ( V_2 ) <= V_202 )
F_15 ( V_2 , false , false , true ) ;
V_200:
F_59 ( & V_2 -> V_199 ) ;
return V_163 ;
}
static int F_60 ( struct V_27 * V_28 ,
struct V_120 * V_121 , T_1 V_113 ,
enum V_114 V_115 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_30 * V_31 = & V_2 -> V_31 ;
struct V_122 * V_123 = V_31 -> V_123 ;
struct V_124 * V_125 ;
if ( ! V_123 ) {
F_5 ( L_12 ) ;
return - V_126 ;
}
V_125 = & V_123 -> V_125 ;
F_16 ( L_13 ,
V_125 -> V_127 , V_113 , V_115 ) ;
if ( V_113 > V_203 ) {
F_30 ( V_31 -> V_28 , L_14 , V_113 ) ;
return - V_68 ;
}
switch ( V_115 ) {
case V_118 :
F_2 ( V_121 -> V_129 [ V_130 ] ,
F_61 ( V_113 ) ) ;
F_2 ( V_121 -> V_129 [ V_131 ] ,
F_62 ( V_113 ) ) ;
F_2 ( V_121 -> V_129 [ V_132 ] ,
F_63 ( V_113 ) ) ;
break;
case V_119 :
F_2 ( 0x0 , F_61 ( V_113 ) ) ;
F_2 ( 0x0 , F_62 ( V_113 ) ) ;
F_2 ( 0x0 , F_63 ( V_113 ) ) ;
break;
default:
break;
}
return F_57 ( V_2 , V_113 , V_115 ) ;
}
static int F_64 ( struct V_1 * V_2 , bool V_17 )
{
F_16 ( L_23 , V_17 ) ;
if ( V_17 ) {
F_65 ( V_2 -> V_204 ) ;
V_2 -> V_205 = false ;
} else {
F_66 ( V_2 -> V_204 ) ;
V_2 -> V_205 = true ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
T_1 V_3 , V_206 , V_170 ;
T_1 V_113 = V_128 ;
int V_163 ;
F_16 ( L_24 , V_2 -> V_20 ) ;
V_3 = F_3 ( V_9 ) ;
V_206 = F_68 ( V_3 ) ;
for ( V_170 = V_206 ; V_170 < V_128 ; V_170 ++ ) {
if ( ! ( ( V_3 >> V_170 ) & 0x1 ) ) {
V_113 = V_170 ;
break;
}
}
if ( V_113 == V_128 ) {
F_5 ( L_25 ) ;
return - V_68 ;
}
V_163 = F_28 ( V_2 , V_113 , V_119 ) ;
if ( V_163 < 0 ) {
F_5 ( L_26 ) ;
return V_163 ;
}
F_16 ( L_27 , V_3 ,
V_206 , V_113 ) ;
return V_113 ;
}
static int F_69 ( struct V_1 * V_2 )
{
T_1 V_3 , V_206 , V_170 ;
T_1 V_113 = V_203 ;
int V_163 ;
F_16 ( L_24 , V_2 -> V_20 ) ;
V_3 = F_3 ( V_13 ) ;
V_206 = F_70 ( V_3 ) ;
for ( V_170 = V_206 ; V_170 < V_203 ; V_170 ++ ) {
if ( ! ( ( V_3 >> V_170 ) & 0x1 ) ) {
V_113 = V_170 ;
break;
}
}
if ( V_113 == V_203 ) {
F_5 ( L_28 ) ;
return - V_68 ;
}
V_163 = F_57 ( V_2 , V_113 , V_119 ) ;
if ( V_163 < 0 ) {
F_5 ( L_26 ) ;
return V_163 ;
}
F_16 ( L_27 , V_3 ,
V_206 , V_113 ) ;
return V_113 ;
}
static T_2 F_71 ( int V_207 , void * V_208 )
{
struct V_1 * V_2 = V_208 ;
struct V_30 * V_31 = & V_2 -> V_31 ;
struct V_122 * V_123 = V_31 -> V_123 ;
struct V_209 * V_210 =
V_123 -> V_210 ;
T_1 V_211 ;
int V_113 [ V_212 ] ;
F_16 ( L_24 , V_2 -> V_20 ) ;
V_211 = F_3 ( V_23 ) ;
if ( V_211 & V_213 ) {
F_19 ( V_31 -> V_28 , L_29 ,
V_2 -> V_20 , V_211 ) ;
return V_214 ;
}
if ( V_211 & V_215 ) {
F_72 ( V_31 -> V_28 , L_30 ,
V_2 -> V_20 , V_211 ) ;
V_113 [ V_216 ] = F_67 ( V_2 ) ;
if ( V_113 [ V_216 ] < 0 )
return V_217 ;
V_113 [ V_218 ] = F_69 ( V_2 ) ;
if ( V_113 [ V_218 ] < 0 )
return V_217 ;
F_16 ( L_31 ,
V_113 [ V_216 ] , V_113 [ V_218 ] ) ;
V_210 -> V_31 = V_31 ;
V_210 -> V_113 [ V_216 ] =
V_113 [ V_216 ] ;
V_210 -> V_113 [ V_218 ] =
V_113 [ V_218 ] ;
F_73 ( V_31 -> V_219 ,
(struct V_220 * ) V_210 ) ;
}
return V_217 ;
}
static int F_74 ( struct V_30 * V_31 )
{
struct V_221 * V_222 = & V_31 -> V_222 ;
V_222 -> V_223 = 1 ;
V_222 -> V_224 = 1 ;
V_222 -> V_225 = V_226 ;
V_222 -> V_227 = V_228 ;
V_222 -> V_72 = ( 1 << V_76 ) |
( 1 << V_78 ) ;
V_222 -> V_70 = ( 1 << V_75 ) |
( 1 << V_80 ) |
( 1 << V_84 ) |
( 1 << V_86 ) ;
V_222 -> V_229 = 1 ;
V_222 -> V_230 = 1 ;
V_222 -> V_231 . V_102 = V_232 ;
V_222 -> V_231 . V_103 = V_232 ;
V_222 -> V_233 . V_102 = V_234 ;
V_222 -> V_233 . V_103 = V_234 ;
V_222 -> V_235 = 1 ;
V_222 -> V_236 . V_102 = V_237 ;
V_222 -> V_236 . V_103 = V_237 ;
V_222 -> V_238 . V_102 = V_239 ;
V_222 -> V_238 . V_103 = V_239 ;
return 0 ;
}
static inline bool F_75 ( enum V_71 V_72 )
{
switch ( V_72 ) {
case V_240 :
case V_76 :
case V_78 :
case V_241 :
return true ;
default:
F_16 ( L_32 ) ;
return false ;
}
}
static int F_76 ( struct V_27 * V_28 ,
struct V_124 * V_125 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_30 * V_31 = & V_2 -> V_31 ;
struct V_221 * V_242 = & V_31 -> V_222 ;
struct V_243 * V_244 ;
struct V_89 * V_90 ;
struct V_91 * V_92 ;
bool V_73 ;
int V_170 ;
F_77 (i) {
if ( ( V_170 == V_216 ) &&
( V_125 -> V_245 == V_246 ) )
continue;
V_244 = & V_125 -> V_244 [ V_170 ] ;
V_90 = & V_244 -> V_90 ;
V_92 = & V_244 -> V_92 ;
if ( ! F_75 ( V_244 -> V_72 ) ) {
F_5 ( L_33 ) ;
goto V_247;
}
switch ( V_244 -> V_70 ) {
case V_80 :
case V_86 :
V_73 = true ;
break;
case V_75 :
case V_84 :
V_73 = false ;
break;
default:
F_5 ( L_34 ) ;
goto V_247;
}
if ( ( V_90 -> V_96 + V_90 -> V_98 > V_92 -> V_102 ) ||
( V_90 -> V_97 + V_90 -> V_99 > V_92 -> V_103 ) ) {
F_5 ( L_35 ) ;
goto V_247;
}
if ( ( V_170 == V_216 ) && ( V_242 -> V_230 ) ) {
if ( V_73 ) {
if ( ( V_90 -> V_99 < V_242 -> V_233 . V_102 ) ||
( V_92 -> V_103 > V_242 -> V_231 . V_102 ) ||
( V_90 -> V_98 < V_242 -> V_233 . V_103 ) ||
( V_92 -> V_102 > V_242 -> V_231 . V_103 ) ) {
F_5 ( L_36 ) ;
goto V_247;
}
} else {
if ( ( V_90 -> V_98 < V_242 -> V_233 . V_102 ) ||
( V_92 -> V_102 > V_242 -> V_231 . V_102 ) ||
( V_90 -> V_99 < V_242 -> V_233 . V_103 ) ||
( V_92 -> V_103 > V_242 -> V_231 . V_103 ) ) {
F_5 ( L_36 ) ;
goto V_247;
}
}
}
if ( ( V_170 == V_218 ) && ( V_242 -> V_235 ) ) {
if ( V_73 ) {
if ( ( V_90 -> V_99 < V_242 -> V_238 . V_102 ) ||
( V_92 -> V_103 > V_242 -> V_236 . V_102 ) ||
( V_90 -> V_98 < V_242 -> V_238 . V_103 ) ||
( V_92 -> V_102 > V_242 -> V_236 . V_103 ) ) {
F_5 ( L_37 ) ;
goto V_247;
}
} else {
if ( ( V_90 -> V_98 < V_242 -> V_238 . V_102 ) ||
( V_92 -> V_102 > V_242 -> V_236 . V_102 ) ||
( V_90 -> V_99 < V_242 -> V_238 . V_103 ) ||
( V_92 -> V_103 > V_242 -> V_236 . V_103 ) ) {
F_5 ( L_37 ) ;
goto V_247;
}
}
}
}
return 0 ;
V_247:
F_77 (i) {
if ( ( V_170 == V_216 ) &&
( V_125 -> V_245 == V_246 ) )
continue;
V_244 = & V_125 -> V_244 [ V_170 ] ;
V_90 = & V_244 -> V_90 ;
V_92 = & V_244 -> V_92 ;
F_5 ( L_38 ,
V_170 ? L_39 : L_40 , V_244 -> V_72 , V_244 -> V_70 ,
V_90 -> V_96 , V_90 -> V_97 , V_90 -> V_98 , V_90 -> V_99 ,
V_92 -> V_102 , V_92 -> V_103 ) ;
}
return - V_68 ;
}
static int F_78 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_94 * V_95 = & V_2 -> V_95 ;
int V_163 ;
V_163 = F_1 ( V_2 ) ;
if ( V_163 < 0 ) {
F_19 ( V_28 , L_41 ) ;
return V_163 ;
}
memset ( & V_2 -> V_95 , 0x0 , sizeof( V_2 -> V_95 ) ) ;
V_95 -> V_107 = true ;
return 0 ;
}
static int F_79 ( struct V_27 * V_28 , enum V_248 V_245 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_30 * V_31 = & V_2 -> V_31 ;
struct V_122 * V_123 = V_31 -> V_123 ;
struct V_124 * V_125 ;
struct V_243 * V_244 ;
struct V_89 V_93 [ V_212 ] ;
struct V_249 V_250 ;
T_1 V_3 ;
int V_163 , V_170 ;
F_16 ( L_42 , V_245 ) ;
if ( ! V_123 ) {
F_5 ( L_12 ) ;
return - V_68 ;
}
V_125 = & V_123 -> V_125 ;
F_15 ( V_2 , true , false , true ) ;
F_77 (i) {
V_244 = & V_125 -> V_244 [ V_170 ] ;
V_93 [ V_170 ] = V_244 -> V_90 ;
}
switch ( V_245 ) {
case V_251 :
V_3 = F_3 ( V_252 ) ;
V_3 &= ~ ( V_253 |
V_254 ) ;
V_3 |= V_255 ;
F_2 ( V_3 , V_252 ) ;
V_3 = F_3 ( V_32 ) ;
V_3 &= ~ ( V_256 | V_257 ) ;
V_3 |= V_258 ;
F_2 ( V_3 , V_32 ) ;
V_3 = F_3 ( V_133 ) ;
V_3 |= V_259 ;
F_2 ( V_3 , V_133 ) ;
break;
case V_246 :
V_250 . V_17 = 1 ;
V_250 . V_260 = V_125 -> V_261 ;
F_8 ( V_2 , V_250 . V_17 ) ;
F_80 ( V_262 , ( void * ) & V_250 ) ;
V_3 = F_3 ( V_32 ) ;
V_3 &= ~ ( V_256 | V_257 ) ;
V_3 |= ( V_263 | V_264 ) ;
F_2 ( V_3 , V_32 ) ;
V_3 = F_3 ( V_133 ) ;
V_3 |= V_259 ;
F_2 ( V_3 , V_133 ) ;
break;
case V_265 :
V_3 = F_3 ( V_32 ) ;
V_3 &= ~ ( V_256 | V_257 ) ;
V_3 |= V_258 ;
F_2 ( V_3 , V_32 ) ;
V_3 = F_3 ( V_133 ) ;
V_3 |= V_259 ;
F_2 ( V_3 , V_133 ) ;
break;
default:
V_163 = - V_68 ;
F_19 ( V_28 , L_43 ) ;
return V_163 ;
}
V_163 = F_38 ( V_2 , & V_2 -> V_95 ,
& V_93 [ V_216 ] ,
& V_93 [ V_218 ] ) ;
if ( V_163 ) {
F_19 ( V_28 , L_44 ) ;
return V_163 ;
}
F_46 ( V_2 , & V_2 -> V_95 ) ;
V_3 = F_3 ( V_252 ) ;
V_3 |= V_266 ;
F_2 ( V_3 , V_252 ) ;
return 0 ;
}
static void F_81 ( struct V_27 * V_28 , enum V_248 V_245 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_249 V_250 = { 0 , 0 } ;
T_1 V_3 ;
F_16 ( L_42 , V_245 ) ;
switch ( V_245 ) {
case V_251 :
break;
case V_246 :
F_8 ( V_2 , V_250 . V_17 ) ;
F_80 ( V_262 , ( void * ) & V_250 ) ;
break;
case V_265 :
default:
F_19 ( V_28 , L_43 ) ;
break;
}
F_15 ( V_2 , false , false , true ) ;
F_2 ( 0xff , V_13 ) ;
F_2 ( 0xff , V_15 ) ;
F_2 ( 0xff , V_16 ) ;
V_3 = F_3 ( V_252 ) ;
V_3 &= ~ V_266 ;
F_2 ( V_3 , V_252 ) ;
}
static int F_82 ( struct V_267 * V_268 )
{
struct V_27 * V_28 = & V_268 -> V_28 ;
struct V_1 * V_2 ;
struct V_269 * V_270 ;
struct V_30 * V_31 ;
int V_163 ;
V_2 = F_83 ( V_28 , sizeof( * V_2 ) , V_271 ) ;
if ( ! V_2 )
return - V_272 ;
V_2 -> V_204 = F_84 ( V_28 , L_45 ) ;
if ( F_85 ( V_2 -> V_204 ) ) {
F_19 ( V_28 , L_46 ) ;
return F_86 ( V_2 -> V_204 ) ;
}
V_2 -> V_273 = F_87 ( V_268 , V_274 , 0 ) ;
V_2 -> V_275 = F_88 ( V_28 , V_2 -> V_273 ) ;
if ( F_85 ( V_2 -> V_275 ) )
return F_86 ( V_2 -> V_275 ) ;
V_270 = F_87 ( V_268 , V_276 , 0 ) ;
if ( ! V_270 ) {
F_19 ( V_28 , L_47 ) ;
return - V_277 ;
}
V_2 -> V_207 = V_270 -> V_278 ;
V_163 = F_89 ( V_28 , V_2 -> V_207 , NULL , F_71 ,
V_279 , L_48 , V_2 ) ;
if ( V_163 < 0 ) {
F_19 ( V_28 , L_49 ) ;
return V_163 ;
}
V_2 -> V_20 = V_268 -> V_20 ;
V_31 = & V_2 -> V_31 ;
V_31 -> V_28 = V_28 ;
V_31 -> V_280 [ V_216 ] = & V_281 ;
V_31 -> V_280 [ V_218 ] = & V_282 ;
V_31 -> V_283 = F_76 ;
V_31 -> V_284 = F_78 ;
V_31 -> V_278 = F_79 ;
V_31 -> V_285 = F_81 ;
V_163 = F_74 ( V_31 ) ;
if ( V_163 < 0 ) {
F_19 ( V_28 , L_50 ) ;
return V_163 ;
}
F_16 ( L_51 , V_2 -> V_20 , ( int ) V_31 ) ;
F_90 ( & V_2 -> V_199 ) ;
F_91 ( V_268 , V_2 ) ;
F_92 ( V_28 ) ;
F_93 ( V_28 ) ;
V_163 = F_94 ( V_31 ) ;
if ( V_163 < 0 ) {
F_19 ( V_28 , L_52 ) ;
goto V_286;
}
F_30 ( V_28 , L_53 ) ;
return 0 ;
V_286:
F_95 ( V_28 ) ;
return V_163 ;
}
static int F_96 ( struct V_267 * V_268 )
{
struct V_27 * V_28 = & V_268 -> V_28 ;
struct V_1 * V_2 = F_18 ( V_28 ) ;
struct V_30 * V_31 = & V_2 -> V_31 ;
F_97 ( V_31 ) ;
F_98 ( & V_2 -> V_199 ) ;
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
