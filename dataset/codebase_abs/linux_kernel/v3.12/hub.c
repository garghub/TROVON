static inline int F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 . V_4 == V_5 ) ;
}
static inline char * F_2 ( struct V_6 * V_7 , int V_8 )
{
if ( F_1 ( V_7 -> V_2 ) )
return L_1 ;
if ( V_8 & V_9 )
return L_2 ;
else if ( V_8 & V_10 )
return L_3 ;
else
return L_4 ;
}
struct V_6 * F_3 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_11 || ! V_2 -> V_12 )
return NULL ;
return F_4 ( V_2 -> V_11 -> V_13 [ 0 ] ) ;
}
static int F_5 ( struct V_1 * V_14 )
{
if ( V_14 -> V_15 == V_16 ) {
if ( V_14 -> V_17 -> V_18 &&
( V_19 &
F_6 ( V_14 -> V_17 -> V_18 -> V_20 ) ) )
return 1 ;
return 0 ;
}
if ( ! V_14 -> V_17 -> V_21 ) {
F_7 ( & V_14 -> V_22 , L_5
L_6 ) ;
return 0 ;
}
if ( V_14 -> V_23 -> V_24 )
return 1 ;
F_7 ( & V_14 -> V_22 , L_7
L_6 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_14 ,
struct V_25 * V_26 ,
unsigned int V_27 ,
struct V_6 * V_7 ,
struct V_25 * V_28 ,
unsigned int V_29 )
{
unsigned int V_30 ;
unsigned int V_31 ;
unsigned int V_32 ;
V_30 = V_28 -> V_33 +
( V_7 -> V_3 -> V_34 . V_35 . V_36 * 100 ) ;
V_31 = V_27 * 1000 ;
V_32 = V_29 * 1000 ;
if ( V_31 > V_32 )
V_30 += V_31 ;
else
V_30 += V_32 ;
V_26 -> V_33 = V_30 ;
}
static void F_9 ( struct V_1 * V_14 ,
struct V_25 * V_26 ,
unsigned int V_27 ,
struct V_6 * V_7 ,
struct V_25 * V_28 ,
unsigned int V_29 ,
unsigned int V_37 )
{
unsigned int V_38 ;
unsigned int V_39 ;
if ( V_27 > V_29 )
V_38 = V_27 * 1000 ;
else
V_38 = V_29 * 1000 ;
V_39 = V_37 * 1000 + V_28 -> V_40 ;
if ( V_38 > V_39 )
V_26 -> V_40 = V_38 ;
else
V_26 -> V_40 = V_39 ;
}
static void F_10 ( struct V_1 * V_14 ,
struct V_25 * V_26 )
{
struct V_1 * V_23 ;
unsigned int V_41 ;
unsigned int V_42 ;
V_42 = V_26 -> V_40 ;
for ( V_23 = V_14 -> V_23 , V_41 = 0 ; V_23 -> V_23 ;
V_23 = V_23 -> V_23 )
V_41 ++ ;
if ( V_41 > 0 )
V_42 += 2100 + 250 * ( V_41 - 1 ) ;
V_42 += 250 * V_41 ;
V_26 -> V_43 = V_42 ;
}
static void F_11 ( struct V_1 * V_14 )
{
struct V_6 * V_7 ;
unsigned int V_44 ;
unsigned int V_45 ;
unsigned int V_46 ;
unsigned int V_47 ;
unsigned int V_48 ;
if ( ! V_14 -> V_24 || V_14 -> V_15 != V_49 )
return;
V_7 = F_3 ( V_14 -> V_23 ) ;
if ( ! V_7 )
return;
V_45 = V_14 -> V_17 -> V_21 -> V_50 ;
V_46 = V_14 -> V_17 -> V_21 -> V_51 ;
V_47 = V_14 -> V_23 -> V_17 -> V_21 -> V_50 ;
V_48 = V_14 -> V_23 -> V_17 -> V_21 -> V_51 ;
F_8 ( V_14 , & V_14 -> V_52 , V_45 ,
V_7 , & V_14 -> V_23 -> V_52 , V_47 ) ;
F_8 ( V_14 , & V_14 -> V_53 , V_46 ,
V_7 , & V_14 -> V_23 -> V_53 , V_48 ) ;
V_44 = 1 ;
F_9 ( V_14 , & V_14 -> V_52 , V_45 ,
V_7 , & V_14 -> V_23 -> V_52 , V_47 ,
V_44 ) ;
if ( V_48 > V_47 )
V_44 = 1 + V_48 - V_47 ;
else
V_44 = 1 + V_47 ;
F_9 ( V_14 , & V_14 -> V_53 , V_46 ,
V_7 , & V_14 -> V_23 -> V_53 , V_48 ,
V_44 ) ;
F_10 ( V_14 , & V_14 -> V_52 ) ;
F_10 ( V_14 , & V_14 -> V_53 ) ;
}
static int F_12 ( struct V_1 * V_2 , void * V_54 )
{
int V_55 , V_56 , V_57 ;
unsigned V_58 ;
if ( F_1 ( V_2 ) ) {
V_58 = V_59 ;
V_57 = V_60 ;
} else {
V_58 = V_61 ;
V_57 = sizeof( struct V_62 ) ;
}
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
V_56 = F_13 ( V_2 , F_14 ( V_2 , 0 ) ,
V_63 , V_64 | V_65 ,
V_58 << 8 , 0 , V_54 , V_57 ,
V_66 ) ;
if ( V_56 >= ( V_67 + 2 ) )
return V_56 ;
}
return - V_68 ;
}
static int F_15 ( struct V_1 * V_2 , int V_69 )
{
return F_13 ( V_2 , F_16 ( V_2 , 0 ) ,
V_70 , V_65 , V_69 , 0 , NULL , 0 , 1000 ) ;
}
int F_17 ( struct V_1 * V_2 , int V_71 , int V_69 )
{
return F_13 ( V_2 , F_16 ( V_2 , 0 ) ,
V_70 , V_72 , V_69 , V_71 ,
NULL , 0 , 1000 ) ;
}
static int F_18 ( struct V_1 * V_2 , int V_71 , int V_69 )
{
return F_13 ( V_2 , F_16 ( V_2 , 0 ) ,
V_73 , V_72 , V_69 , V_71 ,
NULL , 0 , 1000 ) ;
}
static void F_19 (
struct V_6 * V_7 ,
int V_71 ,
int V_74
)
{
int V_75 = F_18 ( V_7 -> V_2 , ( V_74 << 8 ) | V_71 ,
V_76 ) ;
if ( V_75 < 0 )
F_20 (hub->intfdev,
L_8 ,
port1,
({ char *s; switch (selector) {
case HUB_LED_AMBER: s = L_9; break;
case HUB_LED_GREEN: s = L_10; break;
case HUB_LED_OFF: s = L_11; break;
case HUB_LED_AUTO: s = L_12; break;
default: s = L_13; break;
}; s; }),
status) ;
}
static void F_21 ( struct V_77 * V_78 )
{
struct V_6 * V_7 =
F_22 ( V_78 , struct V_6 , V_79 . V_78 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
unsigned V_55 ;
unsigned V_80 = 0 ;
int V_81 = - 1 ;
if ( V_2 -> V_82 != V_83 || V_7 -> V_84 )
return;
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; V_55 ++ ) {
unsigned V_74 , V_85 ;
switch ( V_7 -> V_86 [ V_55 ] ) {
case V_87 :
V_81 = V_55 ;
V_74 = V_88 ;
V_85 = V_89 ;
break;
case V_90 :
V_74 = V_91 ;
V_85 = V_92 ;
break;
case V_92 :
V_74 = V_93 ;
V_85 = V_90 ;
break;
case V_94 :
V_74 = V_95 ;
V_85 = V_96 ;
break;
case V_96 :
V_74 = V_93 ;
V_85 = V_94 ;
break;
case V_97 :
V_74 = V_91 ;
V_85 = V_98 ;
break;
case V_98 :
V_74 = V_95 ;
V_85 = V_97 ;
break;
default:
continue;
}
if ( V_74 != V_88 )
V_80 = 1 ;
F_19 ( V_7 , V_55 + 1 , V_74 ) ;
V_7 -> V_86 [ V_55 ] = V_85 ;
}
if ( ! V_80 && V_99 ) {
V_81 ++ ;
V_81 %= V_2 -> V_12 ;
F_19 ( V_7 , V_81 + 1 , V_91 ) ;
V_7 -> V_86 [ V_81 ] = V_87 ;
V_80 ++ ;
}
if ( V_80 )
F_23 ( & V_7 -> V_79 , V_100 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_101 * V_54 )
{
int V_55 , V_75 = - V_102 ;
for ( V_55 = 0 ; V_55 < V_103 &&
( V_75 == - V_102 || V_75 == - V_104 ) ; V_55 ++ ) {
V_75 = F_13 ( V_2 , F_14 ( V_2 , 0 ) ,
V_105 , V_64 | V_65 , 0 , 0 ,
V_54 , sizeof( * V_54 ) , V_106 ) ;
}
return V_75 ;
}
static int F_25 ( struct V_1 * V_2 , int V_71 ,
struct V_107 * V_54 )
{
int V_55 , V_75 = - V_102 ;
for ( V_55 = 0 ; V_55 < V_103 &&
( V_75 == - V_102 || V_75 == - V_104 ) ; V_55 ++ ) {
V_75 = F_13 ( V_2 , F_14 ( V_2 , 0 ) ,
V_105 , V_64 | V_72 , 0 , V_71 ,
V_54 , sizeof( * V_54 ) , V_106 ) ;
}
return V_75 ;
}
static int F_26 ( struct V_6 * V_7 , int V_71 ,
T_1 * V_75 , T_1 * V_108 )
{
int V_56 ;
F_27 ( & V_7 -> V_109 ) ;
V_56 = F_25 ( V_7 -> V_2 , V_71 , & V_7 -> V_75 -> V_110 ) ;
if ( V_56 < 4 ) {
if ( V_56 != - V_111 )
F_28 ( V_7 -> V_112 ,
L_14 , V_113 , V_56 ) ;
if ( V_56 >= 0 )
V_56 = - V_114 ;
} else {
* V_75 = F_29 ( V_7 -> V_75 -> V_110 . V_115 ) ;
* V_108 = F_29 ( V_7 -> V_75 -> V_110 . V_116 ) ;
V_56 = 0 ;
}
F_30 ( & V_7 -> V_109 ) ;
return V_56 ;
}
static void F_31 ( struct V_6 * V_7 )
{
unsigned long V_117 ;
F_32 ( & V_118 , V_117 ) ;
if ( ! V_7 -> V_119 && F_33 ( & V_7 -> V_120 ) ) {
F_34 ( & V_7 -> V_120 , & V_121 ) ;
F_35 (
F_36 ( V_7 -> V_112 ) ) ;
F_37 ( & V_122 ) ;
}
F_38 ( & V_118 , V_117 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_7 )
F_31 ( V_7 ) ;
}
void F_40 ( struct V_1 * V_2 ,
unsigned int V_123 )
{
struct V_6 * V_7 ;
if ( ! V_2 )
return;
V_7 = F_3 ( V_2 ) ;
if ( V_7 ) {
F_41 ( V_123 , V_7 -> V_124 ) ;
F_31 ( V_7 ) ;
}
}
static void F_42 ( struct V_125 * V_125 )
{
struct V_6 * V_7 = V_125 -> V_126 ;
int V_75 = V_125 -> V_75 ;
unsigned V_55 ;
unsigned long V_127 ;
switch ( V_75 ) {
case - V_128 :
case - V_129 :
case - V_130 :
return;
default:
F_20 ( V_7 -> V_112 , L_15 , V_75 ) ;
if ( ( ++ V_7 -> V_131 < 10 ) || V_7 -> error )
goto V_132;
V_7 -> error = V_75 ;
case 0 :
V_127 = 0 ;
for ( V_55 = 0 ; V_55 < V_125 -> V_133 ; ++ V_55 )
V_127 |= ( ( unsigned long ) ( ( * V_7 -> V_134 ) [ V_55 ] ) )
<< ( V_55 * 8 ) ;
V_7 -> V_135 [ 0 ] = V_127 ;
break;
}
V_7 -> V_131 = 0 ;
F_31 ( V_7 ) ;
V_132:
if ( V_7 -> V_84 )
return;
if ( ( V_75 = F_43 ( V_7 -> V_125 , V_136 ) ) != 0
&& V_75 != - V_111 && V_75 != - V_137 )
F_28 ( V_7 -> V_112 , L_16 , V_75 ) ;
}
static inline int
F_44 ( struct V_1 * V_2 , T_1 V_138 , T_1 V_139 )
{
if ( ( ( V_138 >> 11 ) & V_140 ) ==
V_141 ) {
int V_75 = F_13 ( V_2 , F_16 ( V_2 , 0 ) ,
V_142 , V_72 ,
V_138 ^ 0x8000 , V_139 , NULL , 0 , 1000 ) ;
if ( V_75 )
return V_75 ;
}
return F_13 ( V_2 , F_16 ( V_2 , 0 ) ,
V_142 , V_72 , V_138 ,
V_139 , NULL , 0 , 1000 ) ;
}
static void F_45 ( struct V_77 * V_78 )
{
struct V_6 * V_7 =
F_22 ( V_78 , struct V_6 , V_139 . V_143 ) ;
unsigned long V_117 ;
F_32 ( & V_7 -> V_139 . V_144 , V_117 ) ;
while ( ! F_33 ( & V_7 -> V_139 . V_145 ) ) {
struct V_146 * V_147 ;
struct V_148 * V_149 ;
struct V_1 * V_2 = V_7 -> V_2 ;
const struct V_150 * V_151 ;
int V_75 ;
V_147 = V_7 -> V_139 . V_145 . V_147 ;
V_149 = F_46 ( V_147 , struct V_148 , V_145 ) ;
F_47 ( & V_149 -> V_145 ) ;
F_38 ( & V_7 -> V_139 . V_144 , V_117 ) ;
V_75 = F_44 ( V_2 , V_149 -> V_138 , V_149 -> V_139 ) ;
if ( V_75 && V_75 != - V_111 )
F_28 ( & V_2 -> V_22 ,
L_17 ,
V_149 -> V_139 , V_149 -> V_138 , V_75 ) ;
V_151 = V_149 -> V_152 -> V_153 ;
if ( V_151 -> V_154 )
( V_151 -> V_154 ) ( V_149 -> V_152 , V_149 -> V_155 ) ;
F_48 ( V_149 ) ;
F_32 ( & V_7 -> V_139 . V_144 , V_117 ) ;
}
F_38 ( & V_7 -> V_139 . V_144 , V_117 ) ;
}
int F_49 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_71 , bool V_156 )
{
int V_56 ;
struct V_157 * V_158 = V_7 -> V_159 [ V_71 - 1 ] ;
if ( V_156 )
V_56 = F_18 ( V_2 , V_71 , V_160 ) ;
else
V_56 = F_17 ( V_2 , V_71 , V_160 ) ;
if ( ! V_56 )
V_158 -> V_161 = V_156 ;
return V_56 ;
}
int F_50 ( struct V_125 * V_125 )
{
struct V_1 * V_14 = V_125 -> V_22 ;
int V_162 = V_125 -> V_162 ;
struct V_163 * V_139 = V_14 -> V_139 ;
unsigned long V_117 ;
struct V_148 * V_149 ;
if ( ( V_149 = F_51 ( sizeof *V_149 , V_136 ) ) == NULL ) {
F_28 ( & V_14 -> V_22 , L_18 ) ;
return - V_164 ;
}
V_149 -> V_139 = V_139 -> V_165 ? V_14 -> V_166 : 1 ;
V_149 -> V_138 = F_52 ( V_162 ) ;
V_149 -> V_138 |= V_14 -> V_167 << 4 ;
V_149 -> V_138 |= F_53 ( V_162 )
? ( V_141 << 11 )
: ( V_168 << 11 ) ;
if ( F_54 ( V_162 ) )
V_149 -> V_138 |= 1 << 15 ;
V_149 -> V_152 = F_55 ( V_14 -> V_169 ) ;
V_149 -> V_155 = V_125 -> V_155 ;
F_32 ( & V_139 -> V_144 , V_117 ) ;
F_34 ( & V_149 -> V_145 , & V_139 -> V_145 ) ;
F_56 ( & V_139 -> V_143 ) ;
F_38 ( & V_139 -> V_144 , V_117 ) ;
return 0 ;
}
static unsigned F_57 ( struct V_6 * V_7 , bool V_170 )
{
int V_71 ;
unsigned V_171 = V_7 -> V_3 -> V_172 * 2 ;
unsigned V_173 ;
T_1 V_174 =
F_29 ( V_7 -> V_3 -> V_174 ) ;
if ( ( V_174 & V_175 ) < 2 )
F_20 ( V_7 -> V_112 , L_19 ) ;
else
F_20 ( V_7 -> V_112 , L_20
L_21 ) ;
for ( V_71 = 1 ; V_71 <= V_7 -> V_2 -> V_12 ; V_71 ++ )
if ( V_7 -> V_159 [ V_71 - 1 ] -> V_161 )
F_18 ( V_7 -> V_2 , V_71 , V_160 ) ;
else
F_17 ( V_7 -> V_2 , V_71 ,
V_160 ) ;
V_173 = F_58 ( V_171 , ( unsigned ) 100 ) ;
if ( V_170 )
F_59 ( V_173 ) ;
return V_173 ;
}
static int F_60 ( struct V_6 * V_7 ,
T_1 * V_75 , T_1 * V_108 )
{
int V_56 ;
F_27 ( & V_7 -> V_109 ) ;
V_56 = F_24 ( V_7 -> V_2 , & V_7 -> V_75 -> V_7 ) ;
if ( V_56 < 0 ) {
if ( V_56 != - V_111 )
F_28 ( V_7 -> V_112 ,
L_14 , V_113 , V_56 ) ;
} else {
* V_75 = F_29 ( V_7 -> V_75 -> V_7 . V_176 ) ;
* V_108 = F_29 ( V_7 -> V_75 -> V_7 . V_177 ) ;
V_56 = 0 ;
}
F_30 ( & V_7 -> V_109 ) ;
return V_56 ;
}
static int F_61 ( struct V_6 * V_7 , int V_71 ,
unsigned int V_178 )
{
return F_18 ( V_7 -> V_2 ,
V_71 | ( V_178 << 3 ) ,
V_179 ) ;
}
static int F_62 ( struct V_6 * V_7 , int V_71 )
{
int V_56 ;
int V_180 ;
T_1 V_181 , V_8 ;
if ( ! F_1 ( V_7 -> V_2 ) )
return - V_68 ;
V_56 = F_61 ( V_7 , V_71 , V_182 ) ;
if ( V_56 )
return V_56 ;
for ( V_180 = 0 ; ; V_180 += V_183 ) {
V_56 = F_26 ( V_7 , V_71 , & V_8 , & V_181 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( ( V_8 & V_184 ) ==
V_182 )
break;
if ( V_180 >= V_185 )
break;
F_59 ( V_183 ) ;
}
if ( V_180 >= V_185 )
F_7 ( V_7 -> V_112 , L_22 ,
V_71 , V_180 ) ;
return F_61 ( V_7 , V_71 , V_186 ) ;
}
static int F_63 ( struct V_6 * V_7 , int V_71 , int V_187 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_56 = 0 ;
if ( V_7 -> V_159 [ V_71 - 1 ] -> V_188 && V_187 )
F_64 ( V_7 -> V_159 [ V_71 - 1 ] -> V_188 ,
V_189 ) ;
if ( ! V_7 -> error ) {
if ( F_1 ( V_7 -> V_2 ) )
V_56 = F_62 ( V_7 , V_71 ) ;
else
V_56 = F_17 ( V_2 , V_71 ,
V_190 ) ;
}
if ( V_56 && V_56 != - V_111 )
F_28 ( V_7 -> V_112 , L_23 ,
V_71 , V_56 ) ;
return V_56 ;
}
static void F_65 ( struct V_6 * V_7 , int V_71 )
{
F_20 ( V_7 -> V_112 , L_24 , V_71 ) ;
F_63 ( V_7 , V_71 , 1 ) ;
F_41 ( V_71 , V_7 -> V_191 ) ;
F_31 ( V_7 ) ;
}
int F_66 ( struct V_1 * V_14 )
{
struct V_6 * V_7 ;
struct V_192 * V_193 ;
if ( ! V_14 -> V_23 )
return - V_68 ;
V_7 = F_3 ( V_14 -> V_23 ) ;
V_193 = F_36 ( V_7 -> V_112 ) ;
F_67 ( V_193 ) ;
F_41 ( V_14 -> V_123 , V_7 -> V_194 ) ;
F_65 ( V_7 , V_14 -> V_123 ) ;
F_68 ( V_193 ) ;
return 0 ;
}
static void F_69 ( struct V_6 * V_7 , enum V_195 type )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_196 * V_152 ;
int V_56 ;
int V_71 ;
int V_75 ;
bool V_197 = false ;
unsigned V_173 ;
if ( type == V_198 )
goto V_199;
if ( type == V_200 )
goto V_201;
if ( type != V_202 ) {
if ( V_2 -> V_23 && F_1 ( V_2 ) ) {
V_56 = F_13 ( V_2 , F_16 ( V_2 , 0 ) ,
V_203 , V_65 ,
V_2 -> V_204 - 1 , 0 , NULL , 0 ,
V_205 ) ;
if ( V_56 < 0 )
F_28 ( V_7 -> V_112 ,
L_25 ) ;
}
if ( type == V_206 ) {
V_173 = F_57 ( V_7 , false ) ;
F_70 ( & V_7 -> V_207 , V_208 ) ;
F_23 ( & V_7 -> V_207 ,
F_71 ( V_173 ) ) ;
F_35 (
F_36 ( V_7 -> V_112 ) ) ;
return;
} else if ( type == V_209 ) {
V_152 = F_55 ( V_2 -> V_169 ) ;
if ( V_152 -> V_153 -> V_210 ) {
V_56 = V_152 -> V_153 -> V_210 ( V_152 , V_2 ,
& V_7 -> V_139 , V_211 ) ;
if ( V_56 < 0 ) {
F_28 ( V_7 -> V_112 , L_26
L_27
L_28 ) ;
F_28 ( V_7 -> V_112 , L_29
L_30
L_31 ) ;
}
}
F_57 ( V_7 , true ) ;
} else {
F_57 ( V_7 , true ) ;
}
}
V_199:
for ( V_71 = 1 ; V_71 <= V_2 -> V_12 ; ++ V_71 ) {
struct V_1 * V_14 = V_7 -> V_159 [ V_71 - 1 ] -> V_188 ;
T_1 V_8 , V_181 ;
V_8 = V_181 = 0 ;
V_75 = F_26 ( V_7 , V_71 , & V_8 , & V_181 ) ;
if ( V_14 || ( V_8 & V_212 ) )
F_20 ( V_7 -> V_112 ,
L_32 ,
V_71 , V_8 , V_181 ) ;
if ( ( V_8 & V_213 ) && (
type != V_202 ||
! ( V_8 & V_212 ) ||
! V_14 ||
V_14 -> V_82 == V_189 ) ) {
if ( ! F_1 ( V_2 ) ) {
F_17 ( V_2 , V_71 ,
V_190 ) ;
V_8 &= ~ V_213 ;
} else {
V_8 &= ~ V_213 ;
}
}
if ( V_181 & V_214 ) {
V_197 = true ;
F_17 ( V_7 -> V_2 , V_71 ,
V_215 ) ;
}
if ( V_181 & V_216 ) {
V_197 = true ;
F_17 ( V_7 -> V_2 , V_71 ,
V_217 ) ;
}
if ( ( V_181 & V_218 ) &&
F_1 ( V_7 -> V_2 ) ) {
V_197 = true ;
F_17 ( V_7 -> V_2 , V_71 ,
V_219 ) ;
}
if ( ! ( V_8 & V_212 ) ||
( V_181 & V_214 ) )
F_72 ( V_71 , V_7 -> V_194 ) ;
if ( ! V_14 || V_14 -> V_82 == V_189 ) {
if ( V_14 || ( V_8 & V_212 ) )
F_41 ( V_71 , V_7 -> V_191 ) ;
} else if ( V_8 & V_213 ) {
bool V_220 = ( V_8 &
V_184 ) ==
V_221 ;
if ( V_181 || ( F_1 ( V_7 -> V_2 ) &&
V_220 ) )
F_41 ( V_71 , V_7 -> V_191 ) ;
} else if ( V_14 -> V_222 ) {
struct V_157 * V_158 = V_7 -> V_159 [ V_71 - 1 ] ;
#ifdef F_73
V_14 -> V_223 = 1 ;
#endif
if ( V_158 -> V_161 )
F_41 ( V_71 , V_7 -> V_191 ) ;
} else {
F_64 ( V_14 , V_189 ) ;
F_41 ( V_71 , V_7 -> V_191 ) ;
}
}
if ( V_197 ) {
V_173 = V_224 ;
if ( type == V_198 ) {
F_70 ( & V_7 -> V_207 , V_225 ) ;
F_23 ( & V_7 -> V_207 ,
F_71 ( V_173 ) ) ;
return;
} else {
F_59 ( V_173 ) ;
}
}
V_201:
V_7 -> V_84 = 0 ;
V_75 = F_43 ( V_7 -> V_125 , V_211 ) ;
if ( V_75 < 0 )
F_28 ( V_7 -> V_112 , L_33 , V_75 ) ;
if ( V_7 -> V_226 && V_99 )
F_23 ( & V_7 -> V_79 , V_100 ) ;
F_31 ( V_7 ) ;
if ( type <= V_200 )
F_74 ( F_36 ( V_7 -> V_112 ) ) ;
}
static void V_208 ( struct V_77 * V_227 )
{
struct V_6 * V_7 = F_22 ( V_227 , struct V_6 , V_207 . V_78 ) ;
F_69 ( V_7 , V_198 ) ;
}
static void V_225 ( struct V_77 * V_227 )
{
struct V_6 * V_7 = F_22 ( V_227 , struct V_6 , V_207 . V_78 ) ;
F_69 ( V_7 , V_200 ) ;
}
static void F_75 ( struct V_6 * V_7 , enum V_228 type )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_55 ;
F_76 ( & V_7 -> V_207 ) ;
V_7 -> V_84 = 1 ;
if ( type != V_229 ) {
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; ++ V_55 ) {
if ( V_7 -> V_159 [ V_55 ] -> V_188 )
F_77 ( & V_7 -> V_159 [ V_55 ] -> V_188 ) ;
}
}
F_78 ( V_7 -> V_125 ) ;
if ( V_7 -> V_226 )
F_76 ( & V_7 -> V_79 ) ;
if ( V_7 -> V_139 . V_7 )
F_79 ( & V_7 -> V_139 . V_143 ) ;
}
static int F_80 ( struct V_192 * V_193 )
{
struct V_6 * V_7 = F_4 ( V_193 ) ;
F_75 ( V_7 , V_230 ) ;
return 0 ;
}
static int F_81 ( struct V_192 * V_193 )
{
struct V_6 * V_7 = F_4 ( V_193 ) ;
F_69 ( V_7 , V_231 ) ;
return 0 ;
}
static int F_82 ( struct V_6 * V_7 ,
struct V_232 * V_233 )
{
struct V_196 * V_152 ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_234 * V_235 = V_7 -> V_112 ;
T_1 V_236 , V_237 ;
T_1 V_174 ;
unsigned int V_162 ;
int V_238 , V_56 , V_55 ;
char * V_239 = L_34 ;
unsigned V_240 ;
unsigned V_241 ;
V_7 -> V_134 = F_51 ( sizeof( * V_7 -> V_134 ) , V_242 ) ;
if ( ! V_7 -> V_134 ) {
V_56 = - V_164 ;
goto V_243;
}
V_7 -> V_75 = F_51 ( sizeof( * V_7 -> V_75 ) , V_242 ) ;
if ( ! V_7 -> V_75 ) {
V_56 = - V_164 ;
goto V_243;
}
F_83 ( & V_7 -> V_109 ) ;
V_7 -> V_3 = F_51 ( sizeof( * V_7 -> V_3 ) , V_242 ) ;
if ( ! V_7 -> V_3 ) {
V_56 = - V_164 ;
goto V_243;
}
V_56 = F_12 ( V_2 , V_7 -> V_3 ) ;
if ( V_56 < 0 ) {
V_239 = L_35 ;
goto V_243;
} else if ( V_7 -> V_3 -> V_244 > V_245 ) {
V_239 = L_36 ;
V_56 = - V_111 ;
goto V_243;
} else if ( V_7 -> V_3 -> V_244 == 0 ) {
V_239 = L_37 ;
V_56 = - V_111 ;
goto V_243;
}
V_2 -> V_12 = V_7 -> V_3 -> V_244 ;
F_84 ( V_235 , L_38 , V_2 -> V_12 ,
( V_2 -> V_12 == 1 ) ? L_39 : L_40 ) ;
V_7 -> V_159 = F_85 ( V_2 -> V_12 * sizeof( struct V_157 * ) ,
V_242 ) ;
if ( ! V_7 -> V_159 ) {
V_56 = - V_164 ;
goto V_243;
}
V_174 = F_29 ( V_7 -> V_3 -> V_174 ) ;
if ( F_1 ( V_2 ) ) {
V_240 = 150 ;
V_241 = 900 ;
} else {
V_240 = 100 ;
V_241 = 500 ;
}
if ( ( V_174 & V_246 ) &&
! ( F_1 ( V_2 ) ) ) {
int V_55 ;
char V_247 [ V_245 + 1 ] ;
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; V_55 ++ )
V_247 [ V_55 ] = V_7 -> V_3 -> V_34 . V_248 . V_249
[ ( ( V_55 + 1 ) / 8 ) ] & ( 1 << ( ( V_55 + 1 ) % 8 ) )
? 'F' : 'R' ;
V_247 [ V_2 -> V_12 ] = 0 ;
F_20 ( V_235 , L_41 , V_247 ) ;
} else
F_20 ( V_235 , L_42 ) ;
switch ( V_174 & V_175 ) {
case V_250 :
F_20 ( V_235 , L_43 ) ;
break;
case V_251 :
F_20 ( V_235 , L_44 ) ;
break;
case V_252 :
case V_175 :
F_20 ( V_235 , L_45 ) ;
break;
}
switch ( V_174 & V_253 ) {
case V_254 :
F_20 ( V_235 , L_46 ) ;
break;
case V_255 :
F_20 ( V_235 , L_47 ) ;
break;
case V_256 :
case V_253 :
F_20 ( V_235 , L_48 ) ;
break;
}
F_86 ( & V_7 -> V_139 . V_144 ) ;
F_87 ( & V_7 -> V_139 . V_145 ) ;
F_88 ( & V_7 -> V_139 . V_143 , F_45 ) ;
switch ( V_2 -> V_3 . V_4 ) {
case V_257 :
break;
case V_258 :
F_20 ( V_235 , L_49 ) ;
V_7 -> V_139 . V_7 = V_2 ;
break;
case V_259 :
V_56 = F_89 ( V_2 , 0 , 1 ) ;
if ( V_56 == 0 ) {
F_20 ( V_235 , L_50 ) ;
V_7 -> V_139 . V_165 = 1 ;
} else
F_28 ( V_235 , L_51 ,
V_56 ) ;
V_7 -> V_139 . V_7 = V_2 ;
break;
case V_5 :
break;
default:
F_20 ( V_235 , L_52 ,
V_2 -> V_3 . V_4 ) ;
break;
}
switch ( V_174 & V_260 ) {
case V_261 :
if ( V_2 -> V_3 . V_4 != 0 ) {
V_7 -> V_139 . V_262 = 666 ;
F_20 ( V_235 , L_53
L_54 ,
8 , V_7 -> V_139 . V_262 ) ;
}
break;
case V_263 :
V_7 -> V_139 . V_262 = 666 * 2 ;
F_20 ( V_235 , L_53
L_54 ,
16 , V_7 -> V_139 . V_262 ) ;
break;
case V_264 :
V_7 -> V_139 . V_262 = 666 * 3 ;
F_20 ( V_235 , L_53
L_54 ,
24 , V_7 -> V_139 . V_262 ) ;
break;
case V_265 :
V_7 -> V_139 . V_262 = 666 * 4 ;
F_20 ( V_235 , L_53
L_54 ,
32 , V_7 -> V_139 . V_262 ) ;
break;
}
if ( V_174 & V_266 ) {
V_7 -> V_226 = 1 ;
F_20 ( V_235 , L_55 ) ;
}
F_20 ( V_235 , L_56 ,
V_7 -> V_3 -> V_172 * 2 ) ;
V_56 = F_90 ( V_2 , V_267 , 0 , & V_236 ) ;
if ( V_56 ) {
V_239 = L_57 ;
goto V_243;
}
V_152 = F_55 ( V_2 -> V_169 ) ;
if ( V_2 == V_2 -> V_169 -> V_268 ) {
if ( V_152 -> V_269 > 0 )
V_2 -> V_270 = V_152 -> V_269 ;
else
V_2 -> V_270 = V_241 * V_2 -> V_12 ;
if ( V_2 -> V_270 >= V_241 )
V_7 -> V_271 = V_241 ;
else {
V_7 -> V_271 = V_2 -> V_270 ;
V_7 -> V_272 = 1 ;
}
} else if ( ( V_236 & ( 1 << V_273 ) ) == 0 ) {
int V_274 = V_2 -> V_270 -
V_7 -> V_3 -> V_275 ;
F_20 ( V_235 , L_58 ,
V_7 -> V_3 -> V_275 ) ;
V_7 -> V_272 = 1 ;
if ( V_274 < V_2 -> V_12 * V_240 )
F_7 ( V_235 ,
L_59
L_60 ) ;
V_7 -> V_271 = V_240 ;
} else {
V_7 -> V_271 = V_241 ;
}
if ( V_7 -> V_271 < V_241 )
F_20 ( V_235 , L_61 ,
V_7 -> V_271 ) ;
if ( V_152 -> V_153 -> V_210 ) {
V_56 = V_152 -> V_153 -> V_210 ( V_152 , V_2 ,
& V_7 -> V_139 , V_242 ) ;
if ( V_56 < 0 ) {
V_239 = L_62 ;
goto V_243;
}
}
V_56 = F_60 ( V_7 , & V_236 , & V_237 ) ;
if ( V_56 < 0 ) {
V_239 = L_57 ;
goto V_243;
}
if ( V_2 -> V_11 -> V_276 . V_20 & V_277 )
F_20 ( V_235 , L_63 ,
( V_236 & V_278 )
? L_64 : L_65 ) ;
if ( ( V_174 & V_253 ) == 0 )
F_20 ( V_235 , L_66 ,
( V_236 & V_279 ) ? L_39 : L_67 ) ;
V_162 = F_91 ( V_2 , V_233 -> V_280 ) ;
V_238 = F_92 ( V_2 , V_162 , F_93 ( V_162 ) ) ;
if ( V_238 > sizeof( * V_7 -> V_134 ) )
V_238 = sizeof( * V_7 -> V_134 ) ;
V_7 -> V_125 = F_94 ( 0 , V_242 ) ;
if ( ! V_7 -> V_125 ) {
V_56 = - V_164 ;
goto V_243;
}
F_95 ( V_7 -> V_125 , V_2 , V_162 , * V_7 -> V_134 , V_238 , F_42 ,
V_7 , V_233 -> V_281 ) ;
if ( V_7 -> V_226 && V_99 )
V_7 -> V_86 [ 0 ] = V_87 ;
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; V_55 ++ ) {
V_56 = F_96 ( V_7 , V_55 + 1 ) ;
if ( V_56 < 0 ) {
F_28 ( V_7 -> V_112 ,
L_68 , V_55 + 1 ) ;
V_2 -> V_12 = V_55 ;
goto V_282;
}
}
F_97 ( V_2 , V_7 -> V_3 ) ;
F_69 ( V_7 , V_206 ) ;
return 0 ;
V_243:
V_2 -> V_12 = 0 ;
V_282:
F_28 ( V_235 , L_69 ,
V_239 , V_56 ) ;
return V_56 ;
}
static void F_98 ( struct V_283 * V_283 )
{
struct V_6 * V_7 = F_22 ( V_283 , struct V_6 , V_283 ) ;
F_99 ( F_36 ( V_7 -> V_112 ) ) ;
F_48 ( V_7 ) ;
}
static void F_100 ( struct V_192 * V_193 )
{
struct V_6 * V_7 = F_4 ( V_193 ) ;
struct V_1 * V_2 = F_101 ( V_193 ) ;
int V_55 ;
F_102 ( & V_118 ) ;
if ( ! F_33 ( & V_7 -> V_120 ) ) {
F_103 ( & V_7 -> V_120 ) ;
F_104 ( V_193 ) ;
}
V_7 -> V_119 = 1 ;
F_105 ( & V_118 ) ;
V_7 -> error = 0 ;
F_75 ( V_7 , V_284 ) ;
F_106 ( V_193 , NULL ) ;
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; V_55 ++ )
F_107 ( V_7 , V_55 + 1 ) ;
V_7 -> V_2 -> V_12 = 0 ;
if ( V_7 -> V_2 -> V_15 == V_16 )
V_285 -- ;
F_108 ( V_7 -> V_125 ) ;
F_48 ( V_7 -> V_159 ) ;
F_48 ( V_7 -> V_3 ) ;
F_48 ( V_7 -> V_75 ) ;
F_48 ( V_7 -> V_134 ) ;
F_109 ( & V_193 -> V_22 , false ) ;
F_110 ( & V_7 -> V_283 , F_98 ) ;
}
static int F_111 ( struct V_192 * V_193 , const struct V_286 * V_287 )
{
struct V_288 * V_276 ;
struct V_232 * V_233 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
V_276 = V_193 -> V_289 ;
V_2 = F_101 ( V_193 ) ;
F_112 ( & V_2 -> V_22 , 0 ) ;
F_113 ( V_2 ) ;
if ( V_2 -> V_204 == V_290 ) {
F_28 ( & V_193 -> V_22 ,
L_70 ) ;
return - V_291 ;
}
#ifdef F_114
if ( V_2 -> V_23 ) {
F_7 ( & V_193 -> V_22 , L_71 ) ;
return - V_111 ;
}
#endif
if ( ( V_276 -> V_276 . V_292 != 0 ) &&
( V_276 -> V_276 . V_292 != 1 ) ) {
V_293:
F_28 ( & V_193 -> V_22 , L_72 ) ;
return - V_114 ;
}
if ( V_276 -> V_276 . V_294 != 1 )
goto V_293;
V_233 = & V_276 -> V_233 [ 0 ] . V_276 ;
if ( ! F_115 ( V_233 ) )
goto V_293;
F_84 ( & V_193 -> V_22 , L_73 ) ;
V_7 = F_85 ( sizeof( * V_7 ) , V_242 ) ;
if ( ! V_7 ) {
F_20 ( & V_193 -> V_22 , L_74 ) ;
return - V_164 ;
}
F_116 ( & V_7 -> V_283 ) ;
F_87 ( & V_7 -> V_120 ) ;
V_7 -> V_112 = & V_193 -> V_22 ;
V_7 -> V_2 = V_2 ;
F_117 ( & V_7 -> V_79 , F_21 ) ;
F_117 ( & V_7 -> V_207 , NULL ) ;
F_118 ( V_193 ) ;
F_106 ( V_193 , V_7 ) ;
V_193 -> V_295 = 1 ;
F_109 ( & V_193 -> V_22 , true ) ;
if ( V_2 -> V_15 == V_16 )
V_285 ++ ;
if ( V_287 -> V_296 & V_297 )
V_7 -> V_298 = 1 ;
if ( F_82 ( V_7 , V_233 ) >= 0 )
return 0 ;
F_100 ( V_193 ) ;
return - V_111 ;
}
static int
F_119 ( struct V_192 * V_193 , unsigned int V_299 , void * V_300 )
{
struct V_1 * V_2 = F_101 ( V_193 ) ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
switch ( V_299 ) {
case V_301 : {
struct V_302 * V_303 = V_300 ;
int V_55 ;
F_102 ( & V_304 ) ;
if ( V_2 -> V_167 <= 0 )
V_303 -> V_305 = 0 ;
else {
V_303 -> V_305 = V_2 -> V_12 ;
for ( V_55 = 0 ; V_55 < V_303 -> V_305 ; V_55 ++ ) {
if ( V_7 -> V_159 [ V_55 ] -> V_188 == NULL )
V_303 -> V_110 [ V_55 ] = 0 ;
else
V_303 -> V_110 [ V_55 ] =
V_7 -> V_159 [ V_55 ] -> V_188 -> V_167 ;
}
}
F_105 ( & V_304 ) ;
return V_303 -> V_305 + 1 ;
}
default:
return - V_306 ;
}
}
static int F_120 ( struct V_1 * V_2 , unsigned V_71 ,
struct V_307 * * * V_308 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_2 -> V_82 == V_189 )
return - V_111 ;
if ( V_71 == 0 || V_71 > V_2 -> V_12 )
return - V_68 ;
* V_308 = & ( V_7 -> V_159 [ V_71 - 1 ] -> V_309 ) ;
return 0 ;
}
int F_121 ( struct V_1 * V_2 , unsigned V_71 ,
struct V_307 * V_310 )
{
int V_311 ;
struct V_307 * * V_312 ;
V_311 = F_120 ( V_2 , V_71 , & V_312 ) ;
if ( V_311 )
return V_311 ;
if ( * V_312 )
return - V_313 ;
* V_312 = V_310 ;
return V_311 ;
}
int F_122 ( struct V_1 * V_2 , unsigned V_71 ,
struct V_307 * V_310 )
{
int V_311 ;
struct V_307 * * V_312 ;
V_311 = F_120 ( V_2 , V_71 , & V_312 ) ;
if ( V_311 )
return V_311 ;
if ( * V_312 != V_310 )
return - V_128 ;
* V_312 = NULL ;
return V_311 ;
}
void F_123 ( struct V_1 * V_2 , struct V_307 * V_310 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
int V_314 ;
for ( V_314 = 0 ; V_314 < V_2 -> V_12 ; V_314 ++ ) {
if ( V_7 -> V_159 [ V_314 ] -> V_309 == V_310 )
V_7 -> V_159 [ V_314 ] -> V_309 = NULL ;
}
}
bool F_124 ( struct V_1 * V_14 )
{
struct V_6 * V_7 ;
if ( V_14 -> V_82 == V_189 || ! V_14 -> V_23 )
return false ;
V_7 = F_3 ( V_14 -> V_23 ) ;
return ! ! V_7 -> V_159 [ V_14 -> V_123 - 1 ] -> V_309 ;
}
static void F_125 ( struct V_1 * V_14 )
{
struct V_6 * V_7 = F_3 ( V_14 ) ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_14 -> V_12 ; ++ V_55 ) {
if ( V_7 -> V_159 [ V_55 ] -> V_188 )
F_125 ( V_7 -> V_159 [ V_55 ] -> V_188 ) ;
}
if ( V_14 -> V_82 == V_315 )
V_14 -> V_316 -= V_317 ;
V_14 -> V_82 = V_189 ;
}
void F_64 ( struct V_1 * V_14 ,
enum V_318 V_319 )
{
unsigned long V_117 ;
int V_320 = - 1 ;
F_32 ( & V_304 , V_117 ) ;
if ( V_14 -> V_82 == V_189 )
;
else if ( V_319 != V_189 ) {
if ( V_14 -> V_23 ) {
if ( V_14 -> V_82 == V_315
|| V_319 == V_315 )
;
else if ( V_319 == V_83 )
V_320 = V_14 -> V_11 -> V_276 . V_20
& V_321 ;
else
V_320 = 0 ;
}
if ( V_14 -> V_82 == V_315 &&
V_319 != V_315 )
V_14 -> V_316 -= V_317 ;
else if ( V_319 == V_315 &&
V_14 -> V_82 != V_315 )
V_14 -> V_316 += V_317 ;
V_14 -> V_82 = V_319 ;
} else
F_125 ( V_14 ) ;
F_38 ( & V_304 , V_117 ) ;
if ( V_320 >= 0 )
F_126 ( & V_14 -> V_22 , V_320 ) ;
}
static void F_127 ( struct V_1 * V_14 )
{
int V_167 ;
struct V_322 * V_169 = V_14 -> V_169 ;
if ( V_14 -> V_323 ) {
V_167 = V_14 -> V_123 + 1 ;
F_128 ( F_129 ( V_167 , V_169 -> V_324 . V_325 ) ) ;
} else {
V_167 = F_130 ( V_169 -> V_324 . V_325 , 128 ,
V_169 -> V_326 ) ;
if ( V_167 >= 128 )
V_167 = F_130 ( V_169 -> V_324 . V_325 ,
128 , 1 ) ;
V_169 -> V_326 = ( V_167 >= 127 ? 1 : V_167 + 1 ) ;
}
if ( V_167 < 128 ) {
F_41 ( V_167 , V_169 -> V_324 . V_325 ) ;
V_14 -> V_167 = V_167 ;
}
}
static void F_131 ( struct V_1 * V_14 )
{
if ( V_14 -> V_167 > 0 ) {
F_72 ( V_14 -> V_167 , V_14 -> V_169 -> V_324 . V_325 ) ;
V_14 -> V_167 = - 1 ;
}
}
static void F_132 ( struct V_1 * V_14 , int V_167 )
{
if ( ! V_14 -> V_323 )
V_14 -> V_167 = V_167 ;
}
static void F_133 ( struct V_1 * V_14 )
{
struct V_196 * V_152 = F_55 ( V_14 -> V_169 ) ;
if ( V_152 -> V_153 -> V_327 && V_14 -> V_23 )
V_152 -> V_153 -> V_327 ( V_152 , V_14 ) ;
}
void F_77 ( struct V_1 * * V_328 )
{
struct V_1 * V_14 = * V_328 ;
struct V_6 * V_7 = F_3 ( V_14 ) ;
int V_55 ;
F_64 ( V_14 , V_189 ) ;
F_84 ( & V_14 -> V_22 , L_75 ,
V_14 -> V_167 ) ;
F_134 ( V_14 ) ;
for ( V_55 = 0 ; V_55 < V_14 -> V_12 ; V_55 ++ ) {
if ( V_7 -> V_159 [ V_55 ] -> V_188 )
F_77 ( & V_7 -> V_159 [ V_55 ] -> V_188 ) ;
}
F_20 ( & V_14 -> V_22 , L_76 ) ;
F_135 ( V_14 , 0 ) ;
F_136 ( V_14 ) ;
if ( V_14 -> V_23 ) {
struct V_6 * V_7 = F_3 ( V_14 -> V_23 ) ;
struct V_157 * V_158 = V_7 -> V_159 [ V_14 -> V_123 - 1 ] ;
F_137 ( & V_14 -> V_22 . V_329 , L_77 ) ;
F_137 ( & V_158 -> V_22 . V_329 , L_78 ) ;
if ( ! V_158 -> V_330 )
F_138 ( & V_158 -> V_22 ) ;
else
V_158 -> V_330 = false ;
}
F_139 ( & V_14 -> V_331 ) ;
F_140 ( V_14 ) ;
F_141 ( & V_14 -> V_22 ) ;
F_131 ( V_14 ) ;
F_102 ( & V_304 ) ;
* V_328 = NULL ;
F_105 ( & V_304 ) ;
F_133 ( V_14 ) ;
F_142 ( & V_14 -> V_22 ) ;
}
static void F_143 ( struct V_1 * V_14 , char * V_287 , char * string )
{
if ( ! string )
return;
F_84 ( & V_14 -> V_22 , L_79 , V_287 , string ) ;
}
static void F_144 ( struct V_1 * V_14 )
{
F_84 ( & V_14 -> V_22 , L_80 ,
F_29 ( V_14 -> V_3 . V_332 ) ,
F_29 ( V_14 -> V_3 . V_333 ) ) ;
F_84 ( & V_14 -> V_22 ,
L_81 ,
V_14 -> V_3 . V_334 ,
V_14 -> V_3 . V_335 ,
V_14 -> V_3 . V_336 ) ;
F_143 ( V_14 , L_82 , V_14 -> V_337 ) ;
F_143 ( V_14 , L_83 , V_14 -> V_338 ) ;
F_143 ( V_14 , L_84 , V_14 -> V_339 ) ;
}
static inline void F_144 ( struct V_1 * V_14 ) { }
static int F_145 ( struct V_1 * V_14 )
{
int V_340 = 0 ;
#ifdef F_146
if ( ! V_14 -> V_169 -> V_341
&& V_14 -> V_342
&& V_14 -> V_23 == V_14 -> V_169 -> V_268 ) {
struct V_343 * V_276 = NULL ;
struct V_322 * V_169 = V_14 -> V_169 ;
if ( F_147 ( V_14 -> V_344 [ 0 ] ,
F_29 ( V_14 -> V_342 [ 0 ] . V_276 . V_345 ) ,
V_346 , ( void * * ) & V_276 ) == 0 ) {
if ( V_276 -> V_20 & V_347 ) {
unsigned V_71 = V_14 -> V_123 ;
F_84 ( & V_14 -> V_22 ,
L_85 ,
( V_71 == V_169 -> V_348 )
? L_39 : L_86 ) ;
if ( V_71 == V_169 -> V_348 )
V_169 -> V_349 = 1 ;
V_340 = F_13 ( V_14 ,
F_16 ( V_14 , 0 ) ,
V_73 , 0 ,
V_169 -> V_349
? V_350
: V_351 ,
0 , NULL , 0 , V_205 ) ;
if ( V_340 < 0 ) {
F_84 ( & V_14 -> V_22 ,
L_87 ,
V_340 ) ;
V_169 -> V_349 = 0 ;
}
}
}
}
if ( ! F_148 ( V_14 ) ) {
if ( V_14 -> V_169 -> V_349 || V_14 -> V_169 -> V_341 ) {
V_340 = F_149 ( V_14 , V_352 ) ;
if ( V_340 < 0 )
F_20 ( & V_14 -> V_22 , L_88 , V_340 ) ;
}
V_340 = - V_353 ;
goto V_243;
}
V_243:
#endif
return V_340 ;
}
static int F_150 ( struct V_1 * V_14 )
{
int V_340 ;
if ( V_14 -> V_342 == NULL ) {
V_340 = F_151 ( V_14 ) ;
if ( V_340 < 0 ) {
if ( V_340 != - V_111 )
F_28 ( & V_14 -> V_22 , L_89 ,
V_340 ) ;
return V_340 ;
}
}
if ( V_14 -> V_323 == 1 && V_14 -> V_354 == 0 ) {
V_14 -> V_337 = F_152 ( L_90 , V_242 ) ;
V_14 -> V_338 = F_152 ( L_90 , V_242 ) ;
V_14 -> V_339 = F_152 ( L_90 , V_242 ) ;
}
else {
V_14 -> V_337 = F_153 ( V_14 , V_14 -> V_3 . V_335 ) ;
V_14 -> V_338 = F_153 ( V_14 ,
V_14 -> V_3 . V_334 ) ;
V_14 -> V_339 = F_153 ( V_14 , V_14 -> V_3 . V_336 ) ;
}
V_340 = F_145 ( V_14 ) ;
if ( V_340 < 0 )
return V_340 ;
F_154 ( V_14 ) ;
return 0 ;
}
static void F_155 ( struct V_1 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_23 ;
struct V_6 * V_7 ;
T_2 V_110 = V_14 -> V_123 ;
T_1 V_174 ;
bool V_355 = true ;
if ( ! V_2 )
return;
V_7 = F_3 ( V_14 -> V_23 ) ;
V_174 = F_29 ( V_7 -> V_3 -> V_174 ) ;
if ( ! ( V_174 & V_246 ) )
return;
if ( F_1 ( V_2 ) ) {
if ( F_29 ( V_7 -> V_3 -> V_34 . V_35 . V_249 )
& ( 1 << V_110 ) )
V_355 = false ;
} else {
if ( V_7 -> V_3 -> V_34 . V_248 . V_249 [ V_110 / 8 ] & ( 1 << ( V_110 % 8 ) ) )
V_355 = false ;
}
if ( V_355 )
V_14 -> V_355 = V_356 ;
else
V_14 -> V_355 = V_357 ;
}
int F_156 ( struct V_1 * V_14 )
{
int V_340 ;
if ( V_14 -> V_23 ) {
F_157 ( & V_14 -> V_22 , 0 ) ;
}
F_158 ( & V_14 -> V_22 ) ;
F_159 ( & V_14 -> V_22 ) ;
F_160 ( & V_14 -> V_22 ) ;
F_161 ( & V_14 -> V_22 ) ;
F_162 ( V_14 ) ;
V_340 = F_150 ( V_14 ) ;
if ( V_340 < 0 )
goto V_243;
F_20 ( & V_14 -> V_22 , L_91 ,
V_14 -> V_167 , V_14 -> V_169 -> V_358 ,
( ( ( V_14 -> V_169 -> V_358 - 1 ) * 128 ) + ( V_14 -> V_167 - 1 ) ) ) ;
V_14 -> V_22 . V_359 = F_163 ( V_360 ,
( ( ( V_14 -> V_169 -> V_358 - 1 ) * 128 ) + ( V_14 -> V_167 - 1 ) ) ) ;
F_144 ( V_14 ) ;
if ( V_14 -> V_339 )
F_164 ( V_14 -> V_339 , strlen ( V_14 -> V_339 ) ) ;
if ( V_14 -> V_337 )
F_164 ( V_14 -> V_337 , strlen ( V_14 -> V_337 ) ) ;
if ( V_14 -> V_338 )
F_164 ( V_14 -> V_338 ,
strlen ( V_14 -> V_338 ) ) ;
F_165 ( & V_14 -> V_22 ) ;
if ( V_14 -> V_23 )
F_155 ( V_14 ) ;
V_340 = F_166 ( & V_14 -> V_22 ) ;
if ( V_340 ) {
F_28 ( & V_14 -> V_22 , L_92 , V_340 ) ;
goto V_243;
}
if ( V_14 -> V_23 ) {
struct V_6 * V_7 = F_3 ( V_14 -> V_23 ) ;
struct V_157 * V_158 = V_7 -> V_159 [ V_14 -> V_123 - 1 ] ;
V_340 = F_167 ( & V_14 -> V_22 . V_329 ,
& V_158 -> V_22 . V_329 , L_77 ) ;
if ( V_340 )
goto V_243;
V_340 = F_167 ( & V_158 -> V_22 . V_329 ,
& V_14 -> V_22 . V_329 , L_78 ) ;
if ( V_340 ) {
F_137 ( & V_14 -> V_22 . V_329 , L_77 ) ;
goto V_243;
}
F_168 ( & V_158 -> V_22 ) ;
}
( void ) F_169 ( & V_14 -> V_22 , & V_14 -> V_331 , V_14 ) ;
F_170 ( V_14 ) ;
F_171 ( & V_14 -> V_22 ) ;
return V_340 ;
V_243:
F_64 ( V_14 , V_189 ) ;
F_172 ( & V_14 -> V_22 ) ;
F_173 ( & V_14 -> V_22 ) ;
return V_340 ;
}
int F_174 ( struct V_1 * V_361 )
{
F_134 ( V_361 ) ;
if ( V_361 -> V_354 == 0 )
goto V_362;
V_361 -> V_354 = 0 ;
F_175 ( V_361 , - 1 ) ;
F_48 ( V_361 -> V_337 ) ;
V_361 -> V_337 = F_152 ( L_90 , V_242 ) ;
F_48 ( V_361 -> V_338 ) ;
V_361 -> V_338 = F_152 ( L_90 , V_242 ) ;
F_48 ( V_361 -> V_339 ) ;
V_361 -> V_339 = F_152 ( L_90 , V_242 ) ;
F_176 ( V_361 ) ;
V_361 -> V_3 . V_363 = 0 ;
V_362:
F_140 ( V_361 ) ;
return 0 ;
}
int F_177 ( struct V_1 * V_361 )
{
int V_364 = 0 , V_365 ;
F_134 ( V_361 ) ;
if ( V_361 -> V_354 == 1 )
goto V_366;
V_364 = F_178 ( V_361 ) ;
if ( V_364 < 0 ) {
F_28 ( & V_361 -> V_22 ,
L_93 , V_364 ) ;
goto V_367;
}
V_364 = F_179 ( V_361 , sizeof( V_361 -> V_3 ) ) ;
if ( V_364 < 0 ) {
F_28 ( & V_361 -> V_22 , L_94
L_95 , V_364 ) ;
goto V_368;
}
F_48 ( V_361 -> V_337 ) ;
V_361 -> V_337 = NULL ;
F_48 ( V_361 -> V_338 ) ;
V_361 -> V_338 = NULL ;
F_48 ( V_361 -> V_339 ) ;
V_361 -> V_339 = NULL ;
V_361 -> V_354 = 1 ;
V_364 = F_150 ( V_361 ) ;
if ( V_364 < 0 )
goto V_369;
V_365 = F_180 ( V_361 ) ;
if ( V_365 >= 0 ) {
V_364 = F_175 ( V_361 , V_365 ) ;
if ( V_364 ) {
F_28 ( & V_361 -> V_22 ,
L_96 , V_365 , V_364 ) ;
}
}
F_84 ( & V_361 -> V_22 , L_97 ) ;
V_369:
V_368:
F_181 ( V_361 ) ;
V_367:
V_366:
F_140 ( V_361 ) ;
return V_364 ;
}
static unsigned F_182 ( struct V_6 * V_7 )
{
struct V_196 * V_152 ;
if ( V_7 -> V_2 -> V_23 != NULL )
return 0 ;
V_152 = F_22 ( V_7 -> V_2 -> V_169 , struct V_196 , V_370 ) ;
return V_152 -> V_371 ;
}
static bool F_183 ( struct V_6 * V_7 , T_1 V_8 )
{
return F_1 ( V_7 -> V_2 ) &&
( ( ( V_8 & V_184 ) ==
V_372 ) ||
( ( V_8 & V_184 ) ==
V_373 ) ) ;
}
static int F_184 ( struct V_6 * V_7 , int V_71 ,
struct V_1 * V_14 , unsigned int V_173 , bool V_374 )
{
int V_375 , V_56 ;
T_1 V_8 ;
T_1 V_181 ;
for ( V_375 = 0 ;
V_375 < V_376 ;
V_375 += V_173 ) {
F_59 ( V_173 ) ;
V_56 = F_26 ( V_7 , V_71 , & V_8 , & V_181 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( ! ( V_8 & V_377 ) )
break;
if ( V_375 >= 2 * V_378 )
V_173 = V_379 ;
F_20 ( V_7 -> V_112 ,
L_98 ,
V_71 , V_374 ? L_99 : L_39 , V_173 ) ;
}
if ( ( V_8 & V_377 ) )
return - V_313 ;
if ( F_183 ( V_7 , V_8 ) )
return - V_380 ;
if ( ! ( V_8 & V_212 ) )
return - V_380 ;
if ( ! F_1 ( V_7 -> V_2 ) &&
( V_181 & V_214 ) )
return - V_380 ;
if ( ! ( V_8 & V_213 ) )
return - V_313 ;
if ( ! V_14 )
return 0 ;
if ( F_182 ( V_7 ) )
V_14 -> V_15 = V_381 ;
else if ( F_1 ( V_7 -> V_2 ) )
V_14 -> V_15 = V_49 ;
else if ( V_8 & V_9 )
V_14 -> V_15 = V_16 ;
else if ( V_8 & V_10 )
V_14 -> V_15 = V_382 ;
else
V_14 -> V_15 = V_383 ;
return 0 ;
}
static void F_185 ( struct V_6 * V_7 , int V_71 ,
struct V_1 * V_14 , int * V_75 )
{
switch ( * V_75 ) {
case 0 :
F_59 ( 10 + 40 ) ;
if ( V_14 ) {
struct V_196 * V_152 = F_55 ( V_14 -> V_169 ) ;
F_132 ( V_14 , 0 ) ;
if ( V_152 -> V_153 -> V_384 )
V_152 -> V_153 -> V_384 ( V_152 , V_14 ) ;
}
case - V_380 :
case - V_111 :
F_17 ( V_7 -> V_2 ,
V_71 , V_385 ) ;
if ( F_1 ( V_7 -> V_2 ) ) {
F_17 ( V_7 -> V_2 , V_71 ,
V_219 ) ;
F_17 ( V_7 -> V_2 , V_71 ,
V_386 ) ;
F_17 ( V_7 -> V_2 , V_71 ,
V_215 ) ;
}
if ( V_14 )
F_64 ( V_14 , * V_75
? V_189
: V_387 ) ;
break;
}
}
static int F_186 ( struct V_6 * V_7 , int V_71 ,
struct V_1 * V_14 , unsigned int V_173 , bool V_374 )
{
int V_55 , V_75 ;
T_1 V_181 , V_8 ;
if ( ! F_1 ( V_7 -> V_2 ) ) {
if ( V_374 ) {
F_28 ( V_7 -> V_112 , L_100
L_101 ) ;
return - V_68 ;
}
F_187 ( & V_388 ) ;
} else if ( ! V_374 ) {
V_75 = F_26 ( V_7 , V_71 ,
& V_8 , & V_181 ) ;
if ( V_75 < 0 )
goto V_389;
if ( F_183 ( V_7 , V_8 ) )
V_374 = true ;
}
for ( V_55 = 0 ; V_55 < V_390 ; V_55 ++ ) {
V_75 = F_18 ( V_7 -> V_2 , V_71 , ( V_374 ?
V_391 :
V_392 ) ) ;
if ( V_75 == - V_111 ) {
;
} else if ( V_75 ) {
F_28 ( V_7 -> V_112 ,
L_102 ,
V_374 ? L_99 : L_39 , V_71 , V_75 ) ;
} else {
V_75 = F_184 ( V_7 , V_71 , V_14 , V_173 ,
V_374 ) ;
if ( V_75 && V_75 != - V_380 && V_75 != - V_111 )
F_20 ( V_7 -> V_112 ,
L_103 ,
V_75 ) ;
}
if ( V_75 == 0 || V_75 == - V_380 || V_75 == - V_111 ) {
F_185 ( V_7 , V_71 , V_14 , & V_75 ) ;
if ( ! F_1 ( V_7 -> V_2 ) )
goto V_389;
if ( F_26 ( V_7 , V_71 ,
& V_8 , & V_181 ) < 0 )
goto V_389;
if ( ! F_183 ( V_7 , V_8 ) )
goto V_389;
if ( ! V_374 ) {
F_20 ( V_7 -> V_112 , L_104 ,
V_71 ) ;
V_374 = true ;
}
}
F_20 ( V_7 -> V_112 ,
L_105 ,
V_71 , V_374 ? L_99 : L_39 ) ;
V_173 = V_379 ;
}
F_28 ( V_7 -> V_112 ,
L_106 ,
V_71 ) ;
V_389:
if ( ! F_1 ( V_7 -> V_2 ) )
F_188 ( & V_388 ) ;
return V_75 ;
}
static int F_189 ( struct V_6 * V_7 , unsigned V_8 )
{
int V_56 = 0 ;
if ( F_1 ( V_7 -> V_2 ) ) {
if ( V_8 & V_393 )
V_56 = 1 ;
} else {
if ( V_8 & V_394 )
V_56 = 1 ;
}
return V_56 ;
}
static int F_190 ( struct V_6 * V_7 , unsigned V_8 )
{
int V_56 = 0 ;
if ( F_1 ( V_7 -> V_2 ) ) {
if ( ( V_8 & V_184 )
== V_395 )
V_56 = 1 ;
} else {
if ( V_8 & V_396 )
V_56 = 1 ;
}
return V_56 ;
}
static int F_191 ( struct V_1 * V_14 ,
struct V_6 * V_7 , int V_71 ,
int V_75 , unsigned V_181 , unsigned V_8 )
{
if ( V_75 || F_190 ( V_7 , V_8 ) ||
! F_189 ( V_7 , V_8 ) ||
! ( V_8 & V_212 ) ) {
if ( V_75 >= 0 )
V_75 = - V_111 ;
}
else if ( ! ( V_8 & V_213 ) && ! V_14 -> V_223 ) {
if ( V_14 -> V_222 )
V_14 -> V_223 = 1 ;
else
V_75 = - V_111 ;
}
if ( V_75 ) {
F_20 ( V_7 -> V_112 ,
L_107 ,
V_71 , V_181 , V_8 , V_75 ) ;
} else if ( V_14 -> V_223 ) {
if ( V_181 & V_214 )
F_17 ( V_7 -> V_2 , V_71 ,
V_215 ) ;
if ( V_181 & V_216 )
F_17 ( V_7 -> V_2 , V_71 ,
V_217 ) ;
}
return V_75 ;
}
int F_192 ( struct V_1 * V_14 )
{
struct V_196 * V_152 = F_55 ( V_14 -> V_169 ) ;
if ( ! F_193 ( V_152 -> V_370 . V_268 ) ||
! F_193 ( V_14 ) )
return 0 ;
if ( ! V_14 -> V_11 )
return 0 ;
return F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_70 , V_267 ,
V_397 , 0 , NULL , 0 ,
V_205 ) ;
}
void F_194 ( struct V_1 * V_14 )
{
struct V_196 * V_152 = F_55 ( V_14 -> V_169 ) ;
if ( ! F_193 ( V_152 -> V_370 . V_268 ) ||
! F_193 ( V_14 ) )
return;
if ( ! V_14 -> V_11 )
return;
F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_73 , V_267 ,
V_397 , 0 , NULL , 0 ,
V_205 ) ;
}
static int F_195 ( struct V_1 * V_14 )
{
if ( V_14 -> V_15 < V_49 )
return F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_73 , V_267 ,
V_398 , 0 , NULL , 0 ,
V_205 ) ;
else
return F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_73 , V_399 ,
V_400 ,
V_401 |
V_402 ,
NULL , 0 , V_205 ) ;
}
static int F_196 ( struct V_1 * V_14 )
{
if ( V_14 -> V_15 < V_49 )
return F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_70 , V_267 ,
V_398 , 0 , NULL , 0 ,
V_205 ) ;
else
return F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_70 , V_399 ,
V_400 , 0 , NULL , 0 ,
V_205 ) ;
}
static unsigned F_197 ( struct V_1 * V_14 )
{
struct V_6 * V_7 = F_3 ( V_14 ) ;
return V_14 -> V_403 +
( V_7 ? V_7 -> F_197 : 0 ) ;
}
int F_149 ( struct V_1 * V_14 , T_3 V_404 )
{
struct V_6 * V_7 = F_3 ( V_14 -> V_23 ) ;
struct V_157 * V_158 = V_7 -> V_159 [ V_14 -> V_123 - 1 ] ;
int V_71 = V_14 -> V_123 ;
int V_75 ;
bool V_405 = true ;
if ( V_14 -> V_403 ) {
V_75 = F_195 ( V_14 ) ;
if ( V_75 ) {
F_20 ( & V_14 -> V_22 , L_108 ,
V_75 ) ;
if ( F_198 ( V_404 ) )
goto V_406;
}
}
if ( V_14 -> V_407 == 1 )
F_199 ( V_14 , 0 ) ;
if ( F_192 ( V_14 ) ) {
F_28 ( & V_14 -> V_22 , L_109 ) ;
V_75 = - V_164 ;
if ( F_198 ( V_404 ) )
goto V_408;
}
if ( F_200 ( V_14 ) ) {
F_28 ( & V_14 -> V_22 , L_110 ) ;
V_75 = - V_164 ;
if ( F_198 ( V_404 ) )
goto V_409;
}
if ( F_1 ( V_7 -> V_2 ) )
V_75 = F_61 ( V_7 , V_71 , V_395 ) ;
else if ( F_198 ( V_404 ) || F_197 ( V_14 ) > 0 )
V_75 = F_18 ( V_7 -> V_2 , V_71 ,
V_410 ) ;
else {
V_405 = false ;
V_75 = 0 ;
}
if ( V_75 ) {
F_20 ( V_7 -> V_112 , L_111 ,
V_71 , V_75 ) ;
F_201 ( V_14 ) ;
V_409:
F_194 ( V_14 ) ;
V_408:
if ( V_14 -> V_411 == 1 )
F_199 ( V_14 , 1 ) ;
if ( V_14 -> V_403 )
( void ) F_196 ( V_14 ) ;
V_406:
if ( ! F_198 ( V_404 ) )
V_75 = 0 ;
} else {
F_20 ( & V_14 -> V_22 , L_112 ,
( F_198 ( V_404 ) ? L_113 : L_39 ) ,
V_14 -> V_403 ) ;
if ( V_405 ) {
V_14 -> F_190 = 1 ;
F_59 ( 10 ) ;
}
F_64 ( V_14 , V_315 ) ;
}
if ( V_75 == 0 && ! V_14 -> V_403 && V_14 -> V_222 ) {
F_202 ( & V_158 -> V_22 ) ;
V_158 -> V_330 = true ;
}
F_170 ( V_7 -> V_2 ) ;
return V_75 ;
}
static int F_203 ( struct V_1 * V_14 )
{
int V_75 = 0 ;
T_1 V_412 = 0 ;
F_20 ( & V_14 -> V_22 , L_114 ,
V_14 -> V_223 ? L_115 : L_116 ) ;
F_64 ( V_14 , V_14 -> V_11
? V_83
: V_413 ) ;
if ( V_14 -> V_223 )
V_414:
V_75 = F_204 ( V_14 ) ;
if ( V_75 == 0 ) {
V_412 = 0 ;
V_75 = F_90 ( V_14 , V_267 , 0 , & V_412 ) ;
if ( V_75 && ! V_14 -> V_223 && V_14 -> V_222 ) {
F_20 ( & V_14 -> V_22 , L_117 ) ;
V_14 -> V_223 = 1 ;
goto V_414;
}
}
if ( V_75 ) {
F_20 ( & V_14 -> V_22 , L_118 ,
V_75 ) ;
} else if ( V_14 -> V_11 && ! V_14 -> V_223 ) {
if ( V_14 -> V_15 < V_49 ) {
if ( V_412 & ( 1 << V_398 ) )
V_75 = F_196 ( V_14 ) ;
} else {
V_75 = F_90 ( V_14 , V_399 , 0 ,
& V_412 ) ;
if ( ! V_75 && V_412 & ( V_415
| V_416 ) )
V_75 = F_196 ( V_14 ) ;
}
if ( V_75 )
F_20 ( & V_14 -> V_22 ,
L_119 ,
V_75 ) ;
V_75 = 0 ;
}
return V_75 ;
}
int F_205 ( struct V_1 * V_14 , T_3 V_404 )
{
struct V_6 * V_7 = F_3 ( V_14 -> V_23 ) ;
struct V_157 * V_158 = V_7 -> V_159 [ V_14 -> V_123 - 1 ] ;
int V_71 = V_14 -> V_123 ;
int V_75 ;
T_1 V_181 , V_8 ;
if ( V_158 -> V_330 ) {
V_75 = F_168 ( & V_158 -> V_22 ) ;
V_158 -> V_330 = false ;
if ( V_75 < 0 ) {
F_20 ( & V_14 -> V_22 , L_120 ,
V_75 ) ;
return V_75 ;
}
}
V_75 = F_26 ( V_7 , V_71 , & V_8 , & V_181 ) ;
if ( V_75 == 0 && ! F_190 ( V_7 , V_8 ) )
goto V_417;
F_41 ( V_71 , V_7 -> V_418 ) ;
if ( F_1 ( V_7 -> V_2 ) )
V_75 = F_61 ( V_7 , V_71 , V_221 ) ;
else
V_75 = F_17 ( V_7 -> V_2 ,
V_71 , V_410 ) ;
if ( V_75 ) {
F_20 ( V_7 -> V_112 , L_121 ,
V_71 , V_75 ) ;
} else {
F_20 ( & V_14 -> V_22 , L_122 ,
( F_198 ( V_404 ) ? L_113 : L_39 ) ) ;
F_59 ( 25 ) ;
V_75 = F_26 ( V_7 , V_71 , & V_8 , & V_181 ) ;
F_59 ( 10 ) ;
}
V_417:
if ( V_75 == 0 ) {
V_14 -> F_190 = 0 ;
if ( F_1 ( V_7 -> V_2 ) ) {
if ( V_181 & V_419 )
F_17 ( V_7 -> V_2 , V_71 ,
V_386 ) ;
} else {
if ( V_181 & V_420 )
F_17 ( V_7 -> V_2 , V_71 ,
V_421 ) ;
}
}
F_72 ( V_71 , V_7 -> V_418 ) ;
V_75 = F_191 ( V_14 ,
V_7 , V_71 , V_75 , V_181 , V_8 ) ;
if ( V_75 == 0 )
V_75 = F_203 ( V_14 ) ;
if ( V_75 < 0 ) {
F_20 ( & V_14 -> V_22 , L_123 , V_75 ) ;
F_65 ( V_7 , V_71 ) ;
} else {
if ( V_14 -> V_411 == 1 )
F_199 ( V_14 , 1 ) ;
F_194 ( V_14 ) ;
F_201 ( V_14 ) ;
}
return V_75 ;
}
int F_206 ( struct V_1 * V_14 )
{
int V_75 = 0 ;
if ( V_14 -> V_82 == V_315 ) {
F_20 ( & V_14 -> V_22 , L_122 , L_124 ) ;
V_75 = F_178 ( V_14 ) ;
if ( V_75 == 0 ) {
F_181 ( V_14 ) ;
}
}
return V_75 ;
}
static int F_207 ( struct V_6 * V_7 )
{
int V_71 ;
for ( V_71 = 1 ; V_71 <= V_7 -> V_2 -> V_12 ; ++ V_71 ) {
T_1 V_8 , V_181 ;
int V_75 ;
V_75 = F_26 ( V_7 , V_71 , & V_8 , & V_181 ) ;
if ( ! V_75 && V_181 )
return 1 ;
}
return 0 ;
}
static int F_208 ( struct V_192 * V_193 , T_3 V_404 )
{
struct V_6 * V_7 = F_4 ( V_193 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
unsigned V_71 ;
int V_75 ;
V_7 -> F_197 = 0 ;
for ( V_71 = 1 ; V_71 <= V_2 -> V_12 ; V_71 ++ ) {
struct V_1 * V_14 ;
V_14 = V_7 -> V_159 [ V_71 - 1 ] -> V_188 ;
if ( V_14 && V_14 -> V_422 ) {
F_7 ( & V_193 -> V_22 , L_125 , V_71 ) ;
if ( F_198 ( V_404 ) )
return - V_313 ;
}
if ( V_14 )
V_7 -> F_197 +=
F_197 ( V_14 ) ;
}
if ( V_2 -> V_403 && V_7 -> V_298 ) {
if ( F_207 ( V_7 ) ) {
if ( F_198 ( V_404 ) )
return - V_313 ;
F_209 ( & V_2 -> V_22 , 2000 ) ;
}
}
if ( F_1 ( V_2 ) && V_2 -> V_403 ) {
for ( V_71 = 1 ; V_71 <= V_2 -> V_12 ; V_71 ++ ) {
V_75 = F_18 ( V_2 ,
V_71 |
V_423 |
V_424 |
V_425 ,
V_426 ) ;
}
}
F_20 ( & V_193 -> V_22 , L_114 , V_113 ) ;
F_75 ( V_7 , V_229 ) ;
return 0 ;
}
static int F_210 ( struct V_192 * V_193 )
{
struct V_6 * V_7 = F_4 ( V_193 ) ;
F_20 ( & V_193 -> V_22 , L_114 , V_113 ) ;
F_69 ( V_7 , V_202 ) ;
return 0 ;
}
static int F_211 ( struct V_192 * V_193 )
{
struct V_6 * V_7 = F_4 ( V_193 ) ;
F_20 ( & V_193 -> V_22 , L_114 , V_113 ) ;
F_69 ( V_7 , V_209 ) ;
return 0 ;
}
void F_212 ( struct V_1 * V_427 )
{
F_7 ( & V_427 -> V_22 , L_126 ) ;
V_427 -> V_223 = 1 ;
}
static int F_213 ( struct V_1 * V_14 , enum V_428 V_82 )
{
struct V_429 * V_430 ;
unsigned long long V_431 ;
unsigned long long V_432 ;
unsigned long long V_433 ;
unsigned long long V_434 ;
int V_56 ;
if ( V_14 -> V_82 != V_83 )
return 0 ;
V_431 = F_214 ( V_14 -> V_52 . V_43 , 1000 ) ;
V_432 = F_214 ( V_14 -> V_52 . V_40 , 1000 ) ;
V_433 = F_214 ( V_14 -> V_53 . V_43 , 1000 ) ;
V_434 = F_214 ( V_14 -> V_53 . V_40 , 1000 ) ;
if ( ( V_82 == V_435 &&
( V_431 > V_436 ||
V_432 > V_436 ) ) ||
( V_82 == V_437 &&
( V_433 > V_438 ||
V_434 > V_438 ) ) ) {
F_20 ( & V_14 -> V_22 , L_127 ,
V_439 [ V_82 ] , V_431 , V_432 ) ;
return - V_68 ;
}
if ( V_431 > V_436 )
V_431 = V_436 ;
if ( V_432 > V_436 )
V_432 = V_436 ;
if ( V_433 > V_438 )
V_433 = V_438 ;
if ( V_434 > V_438 )
V_434 = V_438 ;
V_430 = F_51 ( sizeof *( V_430 ) , V_211 ) ;
if ( ! V_430 )
return - V_164 ;
V_430 -> V_431 = V_431 ;
V_430 -> V_432 = V_432 ;
V_430 -> V_433 = F_215 ( V_433 ) ;
V_430 -> V_434 = F_215 ( V_434 ) ;
V_56 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_440 ,
V_267 ,
0 , 0 ,
V_430 , sizeof *( V_430 ) ,
V_205 ) ;
F_48 ( V_430 ) ;
return V_56 ;
}
static int F_216 ( struct V_1 * V_14 ,
enum V_428 V_82 , bool V_441 )
{
int V_56 ;
int V_69 ;
switch ( V_82 ) {
case V_435 :
V_69 = V_442 ;
break;
case V_437 :
V_69 = V_443 ;
break;
default:
F_7 ( & V_14 -> V_22 , L_128 ,
V_113 , V_441 ? L_129 : L_130 ) ;
return - V_68 ;
}
if ( V_14 -> V_82 != V_83 ) {
F_20 ( & V_14 -> V_22 , L_131
L_132 ,
V_113 , V_441 ? L_129 : L_130 ,
V_439 [ V_82 ] ) ;
return 0 ;
}
if ( V_441 ) {
V_56 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_73 ,
V_267 ,
V_69 ,
0 , NULL , 0 ,
V_205 ) ;
} else {
V_56 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_70 ,
V_267 ,
V_69 ,
0 , NULL , 0 ,
V_205 ) ;
}
if ( V_56 < 0 ) {
F_7 ( & V_14 -> V_22 , L_133 ,
V_441 ? L_134 : L_135 ,
V_439 [ V_82 ] ) ;
return - V_313 ;
}
return 0 ;
}
static int F_217 ( struct V_1 * V_14 ,
enum V_428 V_82 , int V_444 )
{
int V_56 ;
int V_69 ;
switch ( V_82 ) {
case V_435 :
V_69 = V_445 ;
break;
case V_437 :
V_69 = V_446 ;
break;
default:
F_7 ( & V_14 -> V_22 , L_136 ,
V_113 ) ;
return - V_68 ;
}
if ( V_82 == V_435 && V_444 > V_447 &&
V_444 != V_448 ) {
F_7 ( & V_14 -> V_22 , L_137
L_138 ,
V_439 [ V_82 ] , V_444 ) ;
return - V_68 ;
}
V_56 = F_18 ( V_14 -> V_23 ,
F_218 ( V_444 ) | V_14 -> V_123 ,
V_69 ) ;
if ( V_56 < 0 ) {
F_7 ( & V_14 -> V_22 , L_139
L_140 , V_439 [ V_82 ] ,
V_444 , V_56 ) ;
return - V_313 ;
}
if ( V_82 == V_435 )
V_14 -> V_52 . V_444 = V_444 ;
else
V_14 -> V_53 . V_444 = V_444 ;
return 0 ;
}
static void F_219 ( struct V_196 * V_152 , struct V_1 * V_14 ,
enum V_428 V_82 )
{
int V_444 , V_56 ;
T_4 V_449 = V_14 -> V_17 -> V_21 -> V_50 ;
T_5 V_450 = V_14 -> V_17 -> V_21 -> V_51 ;
if ( ( V_82 == V_435 && V_449 == 0 ) ||
( V_82 == V_437 && V_450 == 0 ) )
return;
V_56 = F_213 ( V_14 , V_82 ) ;
if ( V_56 < 0 ) {
F_7 ( & V_14 -> V_22 , L_141 ,
V_439 [ V_82 ] ) ;
return;
}
V_444 = V_152 -> V_153 -> V_451 ( V_152 , V_14 , V_82 ) ;
if ( V_444 == 0 )
return;
if ( V_444 < 0 ) {
F_7 ( & V_14 -> V_22 , L_142
L_143 , V_439 [ V_82 ] ,
V_444 ) ;
return;
}
if ( F_217 ( V_14 , V_82 , V_444 ) )
V_152 -> V_153 -> V_452 ( V_152 , V_14 , V_82 ) ;
else if ( V_14 -> V_11 )
F_216 ( V_14 , V_82 , true ) ;
}
static int F_220 ( struct V_196 * V_152 , struct V_1 * V_14 ,
enum V_428 V_82 )
{
int V_69 ;
switch ( V_82 ) {
case V_435 :
V_69 = V_445 ;
break;
case V_437 :
V_69 = V_446 ;
break;
default:
F_7 ( & V_14 -> V_22 , L_144 ,
V_113 ) ;
return - V_68 ;
}
if ( F_217 ( V_14 , V_82 , 0 ) )
return - V_313 ;
F_216 ( V_14 , V_82 , false ) ;
if ( V_152 -> V_153 -> V_452 ( V_152 , V_14 , V_82 ) )
F_7 ( & V_14 -> V_22 , L_145
L_146 ,
V_439 [ V_82 ] ) ;
return 0 ;
}
int F_221 ( struct V_1 * V_14 )
{
struct V_196 * V_152 ;
if ( ! V_14 || ! V_14 -> V_23 ||
V_14 -> V_15 != V_49 ||
! V_14 -> V_24 )
return 0 ;
V_152 = F_55 ( V_14 -> V_169 ) ;
if ( ! V_152 || ! V_152 -> V_153 -> V_452 )
return 0 ;
V_14 -> V_453 ++ ;
if ( ( V_14 -> V_52 . V_444 == 0 && V_14 -> V_53 . V_444 == 0 ) )
return 0 ;
if ( F_220 ( V_152 , V_14 , V_435 ) )
goto V_454;
if ( F_220 ( V_152 , V_14 , V_437 ) )
goto V_454;
return 0 ;
V_454:
F_222 ( V_14 ) ;
return - V_313 ;
}
int F_200 ( struct V_1 * V_14 )
{
struct V_196 * V_152 = F_55 ( V_14 -> V_169 ) ;
int V_56 ;
if ( ! V_152 )
return - V_68 ;
F_27 ( V_152 -> V_455 ) ;
V_56 = F_221 ( V_14 ) ;
F_30 ( V_152 -> V_455 ) ;
return V_56 ;
}
void F_222 ( struct V_1 * V_14 )
{
struct V_196 * V_152 ;
if ( ! V_14 || ! V_14 -> V_23 ||
V_14 -> V_15 != V_49 ||
! V_14 -> V_24 )
return;
V_14 -> V_453 -- ;
V_152 = F_55 ( V_14 -> V_169 ) ;
if ( ! V_152 || ! V_152 -> V_153 -> V_451 ||
! V_152 -> V_153 -> V_452 )
return;
if ( V_14 -> V_453 > 0 )
return;
F_219 ( V_152 , V_14 , V_435 ) ;
F_219 ( V_152 , V_14 , V_437 ) ;
}
void F_201 ( struct V_1 * V_14 )
{
struct V_196 * V_152 = F_55 ( V_14 -> V_169 ) ;
if ( ! V_152 )
return;
F_27 ( V_152 -> V_455 ) ;
F_222 ( V_14 ) ;
F_30 ( V_152 -> V_455 ) ;
}
int F_221 ( struct V_1 * V_14 )
{
return 0 ;
}
void F_222 ( struct V_1 * V_14 ) { }
int F_200 ( struct V_1 * V_14 )
{
return 0 ;
}
void F_201 ( struct V_1 * V_14 ) { }
int F_192 ( struct V_1 * V_14 )
{
return 0 ;
}
void F_194 ( struct V_1 * V_14 ) { }
int F_223 ( struct V_6 * V_7 , int V_71 , bool V_456 )
{
int V_56 ;
int V_180 , V_457 = 0 ;
T_1 V_181 , V_8 ;
unsigned V_458 = 0xffff ;
for ( V_180 = 0 ; ; V_180 += V_183 ) {
V_56 = F_26 ( V_7 , V_71 , & V_8 , & V_181 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( ! ( V_181 & V_214 ) &&
( V_8 & V_212 ) == V_458 ) {
if ( ! V_456 ||
( V_458 == V_212 ) )
V_457 += V_183 ;
if ( V_457 >= V_224 )
break;
} else {
V_457 = 0 ;
V_458 = V_8 & V_212 ;
}
if ( V_181 & V_214 ) {
F_17 ( V_7 -> V_2 , V_71 ,
V_215 ) ;
}
if ( V_180 >= V_185 )
break;
F_59 ( V_183 ) ;
}
F_20 ( V_7 -> V_112 ,
L_147 ,
V_71 , V_180 , V_457 , V_8 ) ;
if ( V_457 < V_224 )
return - V_102 ;
return V_8 ;
}
void F_224 ( struct V_1 * V_14 )
{
F_225 ( V_14 , 0 + V_64 , true ) ;
F_225 ( V_14 , 0 + V_459 , true ) ;
F_226 ( V_14 , & V_14 -> V_331 , true ) ;
}
static int F_227 ( struct V_1 * V_14 , int V_167 )
{
int V_460 ;
struct V_196 * V_152 = F_55 ( V_14 -> V_169 ) ;
if ( ! V_152 -> V_153 -> V_461 && V_167 <= 1 )
return - V_68 ;
if ( V_14 -> V_82 == V_413 )
return 0 ;
if ( V_14 -> V_82 != V_387 )
return - V_68 ;
if ( V_152 -> V_153 -> V_461 )
V_460 = V_152 -> V_153 -> V_461 ( V_152 , V_14 ) ;
else
V_460 = F_13 ( V_14 , F_228 () ,
V_462 , 0 , V_167 , 0 ,
NULL , 0 , V_205 ) ;
if ( V_460 == 0 ) {
F_132 ( V_14 , V_167 ) ;
F_64 ( V_14 , V_413 ) ;
F_224 ( V_14 ) ;
}
return V_460 ;
}
static int
F_229 ( struct V_6 * V_7 , struct V_1 * V_14 , int V_71 ,
int V_463 )
{
static F_230 ( V_464 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_196 * V_152 = F_55 ( V_2 -> V_169 ) ;
int V_55 , V_465 , V_460 ;
unsigned V_173 = V_378 ;
enum V_466 V_467 = V_14 -> V_15 ;
const char * V_15 ;
int V_167 = V_14 -> V_167 ;
if ( ! V_2 -> V_23 ) {
V_173 = V_468 ;
if ( V_71 == V_2 -> V_169 -> V_348 )
V_2 -> V_169 -> V_349 = 0 ;
}
if ( V_467 == V_382 )
V_173 = V_379 ;
F_27 ( & V_464 ) ;
V_460 = F_186 ( V_7 , V_71 , V_14 , V_173 , false ) ;
if ( V_460 < 0 )
goto V_243;
V_460 = - V_111 ;
if ( V_467 != V_469 && V_467 != V_14 -> V_15 ) {
F_20 ( & V_14 -> V_22 , L_148 ) ;
goto V_243;
}
V_467 = V_14 -> V_15 ;
switch ( V_14 -> V_15 ) {
case V_49 :
case V_381 :
V_14 -> V_331 . V_276 . V_470 = F_215 ( 512 ) ;
break;
case V_16 :
V_14 -> V_331 . V_276 . V_470 = F_215 ( 64 ) ;
break;
case V_383 :
V_14 -> V_331 . V_276 . V_470 = F_215 ( 64 ) ;
break;
case V_382 :
V_14 -> V_331 . V_276 . V_470 = F_215 ( 8 ) ;
break;
default:
goto V_243;
}
if ( V_14 -> V_15 == V_381 )
V_15 = L_149 ;
else
V_15 = F_231 ( V_14 -> V_15 ) ;
if ( V_14 -> V_15 != V_49 )
F_84 ( & V_14 -> V_22 ,
L_150 ,
( V_14 -> V_342 ) ? L_151 : L_152 , V_15 ,
V_167 , V_14 -> V_169 -> V_471 -> V_153 -> V_472 ) ;
if ( V_2 -> V_139 ) {
V_14 -> V_139 = V_2 -> V_139 ;
V_14 -> V_166 = V_2 -> V_166 ;
} else if ( V_14 -> V_15 != V_16
&& V_2 -> V_15 == V_16 ) {
if ( ! V_7 -> V_139 . V_7 ) {
F_28 ( & V_14 -> V_22 , L_153 ) ;
V_460 = - V_68 ;
goto V_243;
}
V_14 -> V_139 = & V_7 -> V_139 ;
V_14 -> V_166 = V_71 ;
}
for ( V_55 = 0 ; V_55 < V_473 ; ( ++ V_55 , F_59 ( 100 ) ) ) {
if ( F_232 ( V_463 ) && ! ( V_152 -> V_153 -> V_117 & V_474 ) ) {
struct V_475 * V_476 ;
int V_477 = 0 ;
#define F_233 64
V_476 = F_51 ( F_233 , V_211 ) ;
if ( ! V_476 ) {
V_460 = - V_164 ;
continue;
}
for ( V_465 = 0 ; V_465 < 3 ; ++ V_465 ) {
V_476 -> V_478 = 0 ;
V_477 = F_13 ( V_14 , F_234 () ,
V_63 , V_64 ,
V_479 << 8 , 0 ,
V_476 , F_233 ,
V_480 ) ;
switch ( V_476 -> V_478 ) {
case 8 : case 16 : case 32 : case 64 : case 255 :
if ( V_476 -> V_481 ==
V_479 ) {
V_477 = 0 ;
break;
}
default:
if ( V_477 == 0 )
V_477 = - V_482 ;
break;
}
if ( V_477 == 0 )
break;
}
V_14 -> V_3 . V_478 =
V_476 -> V_478 ;
F_48 ( V_476 ) ;
V_460 = F_186 ( V_7 , V_71 , V_14 , V_173 , false ) ;
if ( V_460 < 0 )
goto V_243;
if ( V_467 != V_14 -> V_15 ) {
F_20 ( & V_14 -> V_22 ,
L_148 ) ;
V_460 = - V_111 ;
goto V_243;
}
if ( V_477 ) {
if ( V_477 != - V_111 )
F_28 ( & V_14 -> V_22 , L_154 ,
V_477 ) ;
V_460 = - V_483 ;
continue;
}
#undef F_233
}
if ( V_14 -> V_323 == 0 ) {
for ( V_465 = 0 ; V_465 < V_484 ; ++ V_465 ) {
V_460 = F_227 ( V_14 , V_167 ) ;
if ( V_460 >= 0 )
break;
F_59 ( 200 ) ;
}
if ( V_460 < 0 ) {
if ( V_460 != - V_111 )
F_28 ( & V_14 -> V_22 , L_155 ,
V_167 , V_460 ) ;
goto V_243;
}
if ( V_14 -> V_15 == V_49 ) {
V_167 = V_14 -> V_167 ;
F_84 ( & V_14 -> V_22 ,
L_156 ,
( V_14 -> V_342 ) ? L_151 : L_152 ,
V_167 , V_14 -> V_169 -> V_471 -> V_153 -> V_472 ) ;
}
F_59 ( 10 ) ;
if ( F_232 ( V_463 ) && ! ( V_152 -> V_153 -> V_117 & V_474 ) )
break;
}
V_460 = F_179 ( V_14 , 8 ) ;
if ( V_460 < 8 ) {
if ( V_460 != - V_111 )
F_28 ( & V_14 -> V_22 ,
L_157 ,
V_460 ) ;
if ( V_460 >= 0 )
V_460 = - V_483 ;
} else {
V_460 = 0 ;
break;
}
}
if ( V_460 )
goto V_243;
if ( V_152 -> V_485 && ! V_2 -> V_23 )
F_235 ( V_152 -> V_485 , V_14 -> V_15 ) ;
if ( ( V_14 -> V_15 == V_49 ) &&
( F_29 ( V_14 -> V_3 . V_486 ) < 0x0300 ) ) {
F_28 ( & V_14 -> V_22 , L_158
L_159 ) ;
F_186 ( V_7 , V_71 , V_14 ,
V_487 , true ) ;
V_460 = - V_68 ;
goto V_243;
}
if ( V_14 -> V_3 . V_478 == 0xff ||
V_14 -> V_15 == V_49 )
V_55 = 512 ;
else
V_55 = V_14 -> V_3 . V_478 ;
if ( F_236 ( & V_14 -> V_331 . V_276 ) != V_55 ) {
if ( V_14 -> V_15 == V_382 ||
! ( V_55 == 8 || V_55 == 16 || V_55 == 32 || V_55 == 64 ) ) {
F_28 ( & V_14 -> V_22 , L_160 , V_55 ) ;
V_460 = - V_483 ;
goto V_243;
}
if ( V_14 -> V_15 == V_383 )
F_20 ( & V_14 -> V_22 , L_161 , V_55 ) ;
else
F_7 ( & V_14 -> V_22 , L_162 , V_55 ) ;
V_14 -> V_331 . V_276 . V_470 = F_215 ( V_55 ) ;
F_224 ( V_14 ) ;
}
V_460 = F_179 ( V_14 , V_488 ) ;
if ( V_460 < ( signed ) sizeof( V_14 -> V_3 ) ) {
if ( V_460 != - V_111 )
F_28 ( & V_14 -> V_22 , L_163 ,
V_460 ) ;
if ( V_460 >= 0 )
V_460 = - V_489 ;
goto V_243;
}
if ( V_14 -> V_323 == 0 && F_29 ( V_14 -> V_3 . V_486 ) >= 0x0201 ) {
V_460 = F_237 ( V_14 ) ;
if ( ! V_460 ) {
V_14 -> V_24 = F_5 ( V_14 ) ;
F_11 ( V_14 ) ;
}
}
V_460 = 0 ;
if ( V_152 -> V_153 -> V_490 )
V_152 -> V_153 -> V_490 ( V_152 , V_14 ) ;
V_243:
if ( V_460 ) {
F_63 ( V_7 , V_71 , 0 ) ;
F_132 ( V_14 , V_167 ) ;
}
F_30 ( & V_464 ) ;
return V_460 ;
}
static void
F_238 ( struct V_6 * V_7 , struct V_1 * V_14 , int V_71 )
{
struct V_491 * V_492 ;
int V_75 ;
V_492 = F_51 ( sizeof *V_492 , V_242 ) ;
if ( V_492 == NULL )
return;
V_75 = F_239 ( V_14 , V_493 , 0 ,
V_492 , sizeof *V_492 ) ;
if ( V_75 == sizeof *V_492 ) {
F_84 ( & V_14 -> V_22 , L_164
L_165 ) ;
if ( V_7 -> V_226 ) {
V_7 -> V_86 [ V_71 - 1 ] = V_90 ;
F_23 ( & V_7 -> V_79 , 0 ) ;
}
}
F_48 ( V_492 ) ;
}
static unsigned
F_240 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_274 ;
int V_71 ;
if ( ! V_7 -> V_272 )
return 0 ;
V_274 = V_2 -> V_270 - V_7 -> V_3 -> V_275 ;
for ( V_71 = 1 ; V_71 <= V_2 -> V_12 ; ++ V_71 ) {
struct V_1 * V_14 = V_7 -> V_159 [ V_71 - 1 ] -> V_188 ;
int V_494 ;
unsigned V_240 ;
if ( ! V_14 )
continue;
if ( F_1 ( V_14 ) )
V_240 = 150 ;
else
V_240 = 100 ;
if ( V_14 -> V_11 )
V_494 = F_241 ( V_14 , V_14 -> V_11 ) ;
else if ( V_71 != V_14 -> V_169 -> V_348 || V_2 -> V_23 )
V_494 = V_240 ;
else
V_494 = 8 ;
if ( V_494 > V_7 -> V_271 )
F_7 ( & V_14 -> V_22 ,
L_166 ,
V_494 , V_7 -> V_271 , V_71 ) ;
V_274 -= V_494 ;
}
if ( V_274 < 0 ) {
F_7 ( V_7 -> V_112 , L_167 ,
- V_274 ) ;
V_274 = 0 ;
}
return V_274 ;
}
static void F_242 ( struct V_6 * V_7 , int V_71 ,
T_1 V_8 , T_1 V_181 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_234 * V_235 = V_7 -> V_112 ;
struct V_196 * V_152 = F_55 ( V_2 -> V_169 ) ;
unsigned V_174 =
F_29 ( V_7 -> V_3 -> V_174 ) ;
struct V_1 * V_14 ;
int V_75 , V_55 ;
unsigned V_240 ;
F_20 ( V_235 ,
L_168 ,
V_71 , V_8 , V_181 , F_2 ( V_7 , V_8 ) ) ;
if ( V_7 -> V_226 ) {
F_19 ( V_7 , V_71 , V_88 ) ;
V_7 -> V_86 [ V_71 - 1 ] = V_89 ;
}
#ifdef F_146
if ( V_2 -> V_169 -> V_341 )
V_181 &= ~ ( V_214 |
V_216 ) ;
#endif
V_14 = V_7 -> V_159 [ V_71 - 1 ] -> V_188 ;
if ( ( V_8 & V_212 ) && V_14 &&
V_14 -> V_82 != V_189 ) {
F_134 ( V_14 ) ;
if ( V_8 & V_213 ) {
V_75 = 0 ;
#ifdef F_243
} else if ( V_14 -> V_82 == V_315 &&
V_14 -> V_222 ) {
V_75 = F_206 ( V_14 ) ;
#endif
} else {
V_75 = - V_111 ;
}
F_140 ( V_14 ) ;
if ( V_75 == 0 ) {
F_72 ( V_71 , V_7 -> V_191 ) ;
return;
}
}
if ( V_14 ) {
if ( V_152 -> V_485 && ! V_2 -> V_23 &&
! ( V_8 & V_212 ) )
F_244 ( V_152 -> V_485 , V_14 -> V_15 ) ;
F_77 ( & V_7 -> V_159 [ V_71 - 1 ] -> V_188 ) ;
}
F_72 ( V_71 , V_7 -> V_191 ) ;
if ( ! ( V_8 & V_212 ) ||
( V_181 & V_214 ) )
F_72 ( V_71 , V_7 -> V_194 ) ;
if ( V_181 & ( V_214 |
V_216 ) ) {
V_75 = F_245 ( V_7 , V_71 ) ;
if ( V_75 < 0 ) {
if ( V_75 != - V_111 && F_246 () )
F_28 ( V_235 , L_169
L_170 , V_71 ) ;
V_8 &= ~ V_212 ;
} else {
V_8 = V_75 ;
}
}
if ( ! ( V_8 & V_212 ) ||
F_129 ( V_71 , V_7 -> V_194 ) ) {
if ( ( V_174 & V_175 ) < 2
&& ! F_189 ( V_7 , V_8 ) )
F_18 ( V_2 , V_71 , V_160 ) ;
if ( V_8 & V_213 )
goto V_389;
return;
}
if ( F_1 ( V_7 -> V_2 ) )
V_240 = 150 ;
else
V_240 = 100 ;
V_75 = 0 ;
for ( V_55 = 0 ; V_55 < V_495 ; V_55 ++ ) {
V_14 = F_247 ( V_2 , V_2 -> V_169 , V_71 ) ;
if ( ! V_14 ) {
F_28 ( V_235 ,
L_171 ,
V_71 ) ;
goto V_389;
}
F_64 ( V_14 , V_496 ) ;
V_14 -> V_270 = V_7 -> V_271 ;
V_14 -> V_204 = V_2 -> V_204 + 1 ;
V_14 -> V_323 = F_182 ( V_7 ) ;
if ( F_1 ( V_7 -> V_2 ) )
V_14 -> V_15 = V_49 ;
else
V_14 -> V_15 = V_469 ;
F_127 ( V_14 ) ;
if ( V_14 -> V_167 <= 0 ) {
V_75 = - V_380 ;
goto V_497;
}
V_75 = F_229 ( V_7 , V_14 , V_71 , V_55 ) ;
if ( V_75 < 0 )
goto V_497;
F_248 ( V_14 ) ;
if ( V_14 -> V_498 & V_499 )
F_59 ( 1000 ) ;
if ( V_14 -> V_3 . V_500 == V_501
&& V_14 -> V_270 <= V_240 ) {
T_1 V_502 ;
V_75 = F_90 ( V_14 , V_267 , 0 ,
& V_502 ) ;
if ( V_75 ) {
F_20 ( & V_14 -> V_22 , L_172 , V_75 ) ;
goto V_503;
}
if ( ( V_502 & ( 1 << V_273 ) ) == 0 ) {
F_28 ( & V_14 -> V_22 ,
L_173
L_174 ) ;
if ( V_7 -> V_226 ) {
V_7 -> V_86 [ V_71 - 1 ] =
V_94 ;
F_23 ( & V_7 -> V_79 , 0 ) ;
}
V_75 = - V_380 ;
goto V_503;
}
}
if ( F_29 ( V_14 -> V_3 . V_486 ) >= 0x0200
&& V_14 -> V_15 == V_383
&& V_285 != 0 )
F_238 ( V_7 , V_14 , V_71 ) ;
V_75 = 0 ;
F_102 ( & V_304 ) ;
if ( V_2 -> V_82 == V_189 )
V_75 = - V_380 ;
else
V_7 -> V_159 [ V_71 - 1 ] -> V_188 = V_14 ;
F_105 ( & V_304 ) ;
if ( ! V_75 ) {
V_75 = F_156 ( V_14 ) ;
if ( V_75 ) {
F_102 ( & V_304 ) ;
V_7 -> V_159 [ V_71 - 1 ] -> V_188 = NULL ;
F_105 ( & V_304 ) ;
}
}
if ( V_75 )
goto V_503;
V_75 = F_240 ( V_7 ) ;
if ( V_75 )
F_20 ( V_235 , L_175 , V_75 ) ;
return;
V_503:
F_63 ( V_7 , V_71 , 1 ) ;
V_497:
F_224 ( V_14 ) ;
F_131 ( V_14 ) ;
F_133 ( V_14 ) ;
F_249 ( V_14 ) ;
if ( ( V_75 == - V_380 ) || ( V_75 == - V_353 ) )
break;
}
if ( V_7 -> V_2 -> V_23 ||
! V_152 -> V_153 -> V_504 ||
! ( V_152 -> V_153 -> V_504 ) ( V_152 , V_71 ) ) {
if ( V_75 != - V_380 && V_75 != - V_111 )
F_28 ( V_235 , L_176 ,
V_71 ) ;
}
V_389:
F_63 ( V_7 , V_71 , 1 ) ;
if ( V_152 -> V_153 -> V_505 && ! V_7 -> V_2 -> V_23 )
V_152 -> V_153 -> V_505 ( V_152 , V_71 ) ;
}
static int F_250 ( struct V_6 * V_7 , unsigned int V_110 ,
T_1 V_8 , T_1 V_181 )
{
struct V_1 * V_2 ;
struct V_1 * V_14 ;
int V_506 = 0 ;
int V_56 ;
V_2 = V_7 -> V_2 ;
V_14 = V_7 -> V_159 [ V_110 - 1 ] -> V_188 ;
if ( ! F_1 ( V_2 ) ) {
if ( ! ( V_181 & V_420 ) )
return 0 ;
F_17 ( V_2 , V_110 , V_421 ) ;
} else {
if ( ! V_14 || V_14 -> V_82 != V_315 ||
( V_8 & V_184 ) !=
V_221 )
return 0 ;
}
if ( V_14 ) {
F_59 ( 10 ) ;
F_134 ( V_14 ) ;
V_56 = F_206 ( V_14 ) ;
F_140 ( V_14 ) ;
if ( V_56 < 0 )
V_506 = 1 ;
} else {
V_56 = - V_111 ;
F_63 ( V_7 , V_110 , 1 ) ;
}
F_20 ( V_7 -> V_112 , L_177 ,
V_110 , V_56 ) ;
return V_506 ;
}
static void F_251 ( void )
{
struct V_146 * V_507 ;
struct V_1 * V_2 ;
struct V_192 * V_193 ;
struct V_6 * V_7 ;
struct V_234 * V_235 ;
T_1 V_236 ;
T_1 V_237 ;
T_1 V_8 ;
T_1 V_181 ;
int V_55 , V_56 ;
int V_506 , V_508 ;
while ( 1 ) {
F_102 ( & V_118 ) ;
if ( F_33 ( & V_121 ) ) {
F_105 ( & V_118 ) ;
break;
}
V_507 = V_121 . V_147 ;
F_103 ( V_507 ) ;
V_7 = F_46 ( V_507 , struct V_6 , V_120 ) ;
F_252 ( & V_7 -> V_283 ) ;
F_105 ( & V_118 ) ;
V_2 = V_7 -> V_2 ;
V_235 = V_7 -> V_112 ;
V_193 = F_36 ( V_235 ) ;
F_20 ( V_235 , L_178 ,
V_2 -> V_82 , V_2 -> V_12 ,
( T_1 ) V_7 -> V_191 [ 0 ] ,
( T_1 ) V_7 -> V_135 [ 0 ] ) ;
F_134 ( V_2 ) ;
if ( F_253 ( V_7 -> V_119 ) )
goto V_509;
if ( V_2 -> V_82 == V_189 ) {
V_7 -> error = - V_111 ;
F_75 ( V_7 , V_284 ) ;
goto V_497;
}
V_56 = F_67 ( V_193 ) ;
if ( V_56 ) {
F_20 ( V_235 , L_179 , V_56 ) ;
goto V_497;
}
if ( V_7 -> V_84 )
goto V_510;
if ( V_7 -> error ) {
F_20 ( V_235 , L_180 ,
V_7 -> error ) ;
V_56 = F_254 ( V_2 ) ;
if ( V_56 ) {
F_20 ( V_235 ,
L_181 , V_56 ) ;
goto V_510;
}
V_7 -> V_131 = 0 ;
V_7 -> error = 0 ;
}
for ( V_55 = 1 ; V_55 <= V_2 -> V_12 ; V_55 ++ ) {
if ( F_129 ( V_55 , V_7 -> V_418 ) )
continue;
V_506 = F_129 ( V_55 , V_7 -> V_191 ) ;
V_508 = F_255 ( V_55 , V_7 -> V_124 ) ;
if ( ! F_255 ( V_55 , V_7 -> V_135 ) &&
! V_506 && ! V_508 )
continue;
V_56 = F_26 ( V_7 , V_55 ,
& V_8 , & V_181 ) ;
if ( V_56 < 0 )
continue;
if ( V_181 & V_214 ) {
F_17 ( V_2 , V_55 ,
V_215 ) ;
V_506 = 1 ;
}
if ( V_181 & V_216 ) {
if ( ! V_506 )
F_20 ( V_235 ,
L_182
L_183 ,
V_55 , V_8 ) ;
F_17 ( V_2 , V_55 ,
V_217 ) ;
if ( ! ( V_8 & V_213 )
&& ! V_506
&& V_7 -> V_159 [ V_55 - 1 ] -> V_188 ) {
F_28 ( V_235 ,
L_184
L_185
L_186 ,
V_55 ) ;
V_506 = 1 ;
}
}
if ( F_250 ( V_7 , V_55 ,
V_8 , V_181 ) )
V_506 = 1 ;
if ( V_181 & V_511 ) {
T_1 V_75 = 0 ;
T_1 V_512 ;
F_20 ( V_235 , L_187
L_188 , V_55 ) ;
F_17 ( V_2 , V_55 ,
V_513 ) ;
F_59 ( 100 ) ;
F_57 ( V_7 , true ) ;
F_26 ( V_7 , V_55 , & V_75 , & V_512 ) ;
if ( V_75 & V_514 )
F_28 ( V_235 , L_189
L_190 , V_55 ) ;
}
if ( V_181 & V_515 ) {
F_20 ( V_235 ,
L_191 ,
V_55 ) ;
F_17 ( V_2 , V_55 ,
V_385 ) ;
}
if ( ( V_181 & V_218 ) &&
F_1 ( V_7 -> V_2 ) ) {
F_20 ( V_235 ,
L_192 ,
V_55 ) ;
F_17 ( V_2 , V_55 ,
V_219 ) ;
}
if ( V_181 & V_419 ) {
F_17 ( V_7 -> V_2 , V_55 ,
V_386 ) ;
}
if ( V_181 & V_516 ) {
F_7 ( V_235 ,
L_193 ,
V_55 ) ;
F_17 ( V_7 -> V_2 , V_55 ,
V_517 ) ;
}
if ( F_183 ( V_7 , V_8 ) ) {
int V_75 ;
struct V_1 * V_14 =
V_7 -> V_159 [ V_55 - 1 ] -> V_188 ;
F_20 ( V_235 , L_194 , V_55 ) ;
if ( ! V_14 || ! ( V_8 &
V_212 ) ) {
V_75 = F_186 ( V_7 , V_55 ,
NULL , V_487 ,
true ) ;
if ( V_75 < 0 )
F_63 ( V_7 , V_55 , 1 ) ;
} else {
F_134 ( V_14 ) ;
V_75 = F_254 ( V_14 ) ;
F_140 ( V_14 ) ;
V_506 = 0 ;
}
}
if ( V_506 )
F_242 ( V_7 , V_55 ,
V_8 , V_181 ) ;
}
if ( F_255 ( 0 , V_7 -> V_135 ) == 0 )
;
else if ( F_60 ( V_7 , & V_236 , & V_237 ) < 0 )
F_28 ( V_235 , L_195 ) ;
else {
if ( V_237 & V_518 ) {
F_20 ( V_235 , L_196 ) ;
F_15 ( V_2 , V_519 ) ;
if ( V_236 & V_278 )
V_7 -> V_272 = 1 ;
else
V_7 -> V_272 = 0 ;
}
if ( V_237 & V_520 ) {
T_1 V_75 = 0 ;
T_1 V_512 ;
F_20 ( V_235 , L_197 ) ;
F_15 ( V_2 , V_521 ) ;
F_59 ( 500 ) ;
F_57 ( V_7 , true ) ;
F_60 ( V_7 , & V_75 , & V_512 ) ;
if ( V_75 & V_279 )
F_28 ( V_235 , L_189
L_198 ) ;
}
}
V_510:
F_104 ( V_193 ) ;
V_497:
F_68 ( V_193 ) ;
V_509:
F_140 ( V_2 ) ;
F_110 ( & V_7 -> V_283 , F_98 ) ;
}
}
static int F_256 ( void * V_522 )
{
F_257 () ;
do {
F_251 () ;
F_258 ( V_122 ,
! F_33 ( & V_121 ) ||
F_259 () ) ;
} while ( ! F_259 () || ! F_33 ( & V_121 ) );
F_260 ( L_199 , V_523 ) ;
return 0 ;
}
int F_261 ( void )
{
if ( F_262 ( & V_524 ) < 0 ) {
F_263 ( V_525 L_200 ,
V_523 ) ;
return - 1 ;
}
V_526 = F_264 ( F_256 , NULL , L_201 ) ;
if ( ! F_265 ( V_526 ) )
return 0 ;
F_266 ( & V_524 ) ;
F_263 ( V_525 L_202 , V_523 ) ;
return - 1 ;
}
void F_267 ( void )
{
F_268 ( V_526 ) ;
F_266 ( & V_524 ) ;
}
static int F_269 ( struct V_1 * V_14 ,
struct V_475 * V_527 ,
struct V_528 * V_529 )
{
int V_80 = 0 ;
unsigned V_530 ;
unsigned V_531 = 0 ;
unsigned V_532 ;
unsigned V_533 ;
int V_534 ;
char * V_476 ;
if ( memcmp ( & V_14 -> V_3 , V_527 ,
sizeof( * V_527 ) ) != 0 )
return 1 ;
if ( ( V_529 && ! V_14 -> V_17 ) || ( ! V_529 && V_14 -> V_17 ) )
return 1 ;
if ( V_14 -> V_17 ) {
V_532 = F_29 ( V_14 -> V_17 -> V_276 -> V_345 ) ;
if ( V_532 != F_29 ( V_529 -> V_276 -> V_345 ) )
return 1 ;
if ( memcmp ( V_14 -> V_17 -> V_276 , V_529 -> V_276 , V_532 ) )
return 1 ;
}
if ( V_14 -> V_339 )
V_531 = strlen ( V_14 -> V_339 ) + 1 ;
V_532 = V_531 ;
for ( V_530 = 0 ; V_530 < V_14 -> V_3 . V_363 ; V_530 ++ ) {
V_533 = F_29 ( V_14 -> V_342 [ V_530 ] . V_276 . V_345 ) ;
V_532 = F_58 ( V_532 , V_533 ) ;
}
V_476 = F_51 ( V_532 , V_211 ) ;
if ( V_476 == NULL ) {
F_28 ( & V_14 -> V_22 , L_203 ) ;
return 1 ;
}
for ( V_530 = 0 ; V_530 < V_14 -> V_3 . V_363 ; V_530 ++ ) {
V_533 = F_29 ( V_14 -> V_342 [ V_530 ] . V_276 . V_345 ) ;
V_534 = F_239 ( V_14 , V_535 , V_530 , V_476 ,
V_533 ) ;
if ( V_534 != V_533 ) {
F_20 ( & V_14 -> V_22 , L_204 ,
V_530 , V_534 ) ;
V_80 = 1 ;
break;
}
if ( memcmp ( V_476 , V_14 -> V_344 [ V_530 ] , V_533 )
!= 0 ) {
F_20 ( & V_14 -> V_22 , L_205 ,
V_530 ,
( (struct V_536 * ) V_476 ) ->
V_537 ) ;
V_80 = 1 ;
break;
}
}
if ( ! V_80 && V_531 ) {
V_534 = F_270 ( V_14 , V_14 -> V_3 . V_336 ,
V_476 , V_531 ) ;
if ( V_534 + 1 != V_531 ) {
F_20 ( & V_14 -> V_22 , L_206 ,
V_534 ) ;
V_80 = 1 ;
} else if ( memcmp ( V_476 , V_14 -> V_339 , V_534 ) != 0 ) {
F_20 ( & V_14 -> V_22 , L_207 ) ;
V_80 = 1 ;
}
}
F_48 ( V_476 ) ;
return V_80 ;
}
static int F_204 ( struct V_1 * V_14 )
{
struct V_1 * V_538 = V_14 -> V_23 ;
struct V_6 * V_539 ;
struct V_196 * V_152 = F_55 ( V_14 -> V_169 ) ;
struct V_475 V_3 = V_14 -> V_3 ;
struct V_528 * V_17 ;
int V_55 , V_56 = 0 ;
int V_71 = V_14 -> V_123 ;
if ( V_14 -> V_82 == V_189 ||
V_14 -> V_82 == V_315 ) {
F_20 ( & V_14 -> V_22 , L_208 ,
V_14 -> V_82 ) ;
return - V_68 ;
}
if ( ! V_538 ) {
F_20 ( & V_14 -> V_22 , L_209 , V_113 ) ;
return - V_540 ;
}
V_539 = F_3 ( V_538 ) ;
V_17 = V_14 -> V_17 ;
V_14 -> V_17 = NULL ;
V_56 = F_200 ( V_14 ) ;
if ( V_56 ) {
F_28 ( & V_14 -> V_22 , L_210 , V_113 ) ;
goto V_541;
}
V_56 = F_192 ( V_14 ) ;
if ( V_56 ) {
F_28 ( & V_14 -> V_22 , L_211 ,
V_113 ) ;
goto V_541;
}
F_41 ( V_71 , V_539 -> V_418 ) ;
for ( V_55 = 0 ; V_55 < V_495 ; ++ V_55 ) {
F_224 ( V_14 ) ;
V_56 = F_229 ( V_539 , V_14 , V_71 , V_55 ) ;
if ( V_56 >= 0 || V_56 == - V_380 || V_56 == - V_111 )
break;
}
F_72 ( V_71 , V_539 -> V_418 ) ;
if ( V_56 < 0 )
goto V_541;
if ( F_269 ( V_14 , & V_3 , V_17 ) ) {
F_84 ( & V_14 -> V_22 , L_212 ) ;
V_14 -> V_3 = V_3 ;
goto V_541;
}
if ( ! V_14 -> V_11 )
goto V_389;
F_27 ( V_152 -> V_455 ) ;
V_56 = F_271 ( V_14 , V_14 -> V_11 , NULL , NULL ) ;
if ( V_56 < 0 ) {
F_7 ( & V_14 -> V_22 ,
L_213
L_214 ) ;
F_30 ( V_152 -> V_455 ) ;
goto V_541;
}
V_56 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_542 , 0 ,
V_14 -> V_11 -> V_276 . V_537 , 0 ,
NULL , 0 , V_205 ) ;
if ( V_56 < 0 ) {
F_28 ( & V_14 -> V_22 ,
L_215 ,
V_14 -> V_11 -> V_276 . V_537 , V_56 ) ;
F_30 ( V_152 -> V_455 ) ;
goto V_541;
}
F_30 ( V_152 -> V_455 ) ;
F_64 ( V_14 , V_83 ) ;
for ( V_55 = 0 ; V_55 < V_14 -> V_11 -> V_276 . V_543 ; V_55 ++ ) {
struct V_544 * V_342 = V_14 -> V_11 ;
struct V_192 * V_193 = V_342 -> V_13 [ V_55 ] ;
struct V_545 * V_276 ;
V_276 = & V_193 -> V_289 -> V_276 ;
if ( V_276 -> V_546 == 0 ) {
F_272 ( V_14 , V_193 , true ) ;
F_273 ( V_14 , V_193 , true ) ;
V_56 = 0 ;
} else {
V_193 -> V_547 = 1 ;
V_56 = F_89 ( V_14 , V_276 -> V_548 ,
V_276 -> V_546 ) ;
V_193 -> V_547 = 0 ;
}
if ( V_56 < 0 ) {
F_28 ( & V_14 -> V_22 , L_216
L_217 ,
V_276 -> V_548 ,
V_276 -> V_546 ,
V_56 ) ;
goto V_541;
}
}
V_389:
F_201 ( V_14 ) ;
F_194 ( V_14 ) ;
F_274 ( V_14 ) ;
V_14 -> V_17 = V_17 ;
return 0 ;
V_541:
F_65 ( V_539 , V_71 ) ;
F_274 ( V_14 ) ;
V_14 -> V_17 = V_17 ;
return - V_111 ;
}
int F_254 ( struct V_1 * V_14 )
{
int V_56 ;
int V_55 ;
unsigned int V_549 ;
struct V_544 * V_342 = V_14 -> V_11 ;
if ( V_14 -> V_82 == V_189 ||
V_14 -> V_82 == V_315 ) {
F_20 ( & V_14 -> V_22 , L_208 ,
V_14 -> V_82 ) ;
return - V_68 ;
}
V_549 = F_275 () ;
F_178 ( V_14 ) ;
if ( V_342 ) {
for ( V_55 = 0 ; V_55 < V_342 -> V_276 . V_543 ; ++ V_55 ) {
struct V_192 * V_550 = V_342 -> V_13 [ V_55 ] ;
struct V_551 * V_151 ;
int V_552 = 0 ;
if ( V_550 -> V_22 . V_153 ) {
V_151 = F_276 ( V_550 -> V_22 . V_153 ) ;
if ( V_151 -> V_553 && V_151 -> V_554 )
V_552 = ( V_151 -> V_553 ) ( V_550 ) ;
else if ( V_550 -> V_555 ==
V_556 )
V_552 = 1 ;
if ( V_552 )
F_277 ( V_550 ) ;
}
}
}
V_56 = F_204 ( V_14 ) ;
if ( V_342 ) {
for ( V_55 = V_342 -> V_276 . V_543 - 1 ; V_55 >= 0 ; -- V_55 ) {
struct V_192 * V_550 = V_342 -> V_13 [ V_55 ] ;
struct V_551 * V_151 ;
int V_557 = V_550 -> V_558 ;
if ( ! V_557 && V_550 -> V_22 . V_153 ) {
V_151 = F_276 ( V_550 -> V_22 . V_153 ) ;
if ( V_151 -> V_554 )
V_557 = ( V_151 -> V_554 ) ( V_550 ) ;
else if ( V_550 -> V_555 ==
V_556 )
V_557 = 1 ;
}
if ( V_56 == 0 && V_557 )
F_278 ( V_550 ) ;
}
}
F_181 ( V_14 ) ;
F_279 ( V_549 ) ;
return V_56 ;
}
void F_280 ( struct V_192 * V_559 )
{
F_56 ( & V_559 -> V_560 ) ;
}
struct V_1 * F_281 ( struct V_1 * V_2 ,
int V_71 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_71 < 1 || V_71 > V_2 -> V_12 )
return NULL ;
return V_7 -> V_159 [ V_71 - 1 ] -> V_188 ;
}
void F_282 ( struct V_1 * V_2 , int V_71 ,
enum V_561 type )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_7 )
V_7 -> V_159 [ V_71 - 1 ] -> V_562 = type ;
}
enum V_561
F_283 ( struct V_1 * V_2 , int V_71 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( ! V_7 )
return V_563 ;
return V_7 -> V_159 [ V_71 - 1 ] -> V_562 ;
}
void F_97 ( struct V_1 * V_2 ,
struct V_62 * V_276 )
{
enum V_561 V_562 ;
int V_55 ;
if ( ! F_1 ( V_2 ) ) {
for ( V_55 = 1 ; V_55 <= V_2 -> V_12 ; V_55 ++ ) {
V_562 = F_283 ( V_2 , V_55 ) ;
if ( V_562 == V_564 ) {
T_2 V_565 = 1 << ( V_55 % 8 ) ;
if ( ! ( V_276 -> V_34 . V_248 . V_249 [ V_55 / 8 ] & V_565 ) ) {
F_20 ( & V_2 -> V_22 , L_218 ,
V_55 ) ;
V_276 -> V_34 . V_248 . V_249 [ V_55 / 8 ] |= V_565 ;
}
}
}
} else {
T_1 V_566 = F_29 ( V_276 -> V_34 . V_35 . V_249 ) ;
for ( V_55 = 1 ; V_55 <= V_2 -> V_12 ; V_55 ++ ) {
V_562 = F_283 ( V_2 , V_55 ) ;
if ( V_562 == V_564 ) {
T_1 V_565 = 1 << V_55 ;
if ( ! ( V_566 & V_565 ) ) {
F_20 ( & V_2 -> V_22 , L_218 ,
V_55 ) ;
V_566 |= V_565 ;
}
}
}
V_276 -> V_34 . V_35 . V_249 = F_215 ( V_566 ) ;
}
}
T_6 F_284 ( struct V_1 * V_2 ,
int V_71 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( ! V_7 )
return NULL ;
return F_285 ( & V_7 -> V_159 [ V_71 - 1 ] -> V_22 ) ;
}
