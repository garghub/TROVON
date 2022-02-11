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
for ( V_55 = 0 ; V_55 < V_7 -> V_3 -> V_85 ; V_55 ++ ) {
unsigned V_74 , V_86 ;
switch ( V_7 -> V_87 [ V_55 ] ) {
case V_88 :
V_81 = V_55 ;
V_74 = V_89 ;
V_86 = V_90 ;
break;
case V_91 :
V_74 = V_92 ;
V_86 = V_93 ;
break;
case V_93 :
V_74 = V_94 ;
V_86 = V_91 ;
break;
case V_95 :
V_74 = V_96 ;
V_86 = V_97 ;
break;
case V_97 :
V_74 = V_94 ;
V_86 = V_95 ;
break;
case V_98 :
V_74 = V_92 ;
V_86 = V_99 ;
break;
case V_99 :
V_74 = V_96 ;
V_86 = V_98 ;
break;
default:
continue;
}
if ( V_74 != V_89 )
V_80 = 1 ;
F_19 ( V_7 , V_55 + 1 , V_74 ) ;
V_7 -> V_87 [ V_55 ] = V_86 ;
}
if ( ! V_80 && V_100 ) {
V_81 ++ ;
V_81 %= V_7 -> V_3 -> V_85 ;
F_19 ( V_7 , V_81 + 1 , V_92 ) ;
V_7 -> V_87 [ V_81 ] = V_88 ;
V_80 ++ ;
}
if ( V_80 )
F_23 ( & V_7 -> V_79 , V_101 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_102 * V_54 )
{
int V_55 , V_75 = - V_103 ;
for ( V_55 = 0 ; V_55 < V_104 &&
( V_75 == - V_103 || V_75 == - V_105 ) ; V_55 ++ ) {
V_75 = F_13 ( V_2 , F_14 ( V_2 , 0 ) ,
V_106 , V_64 | V_65 , 0 , 0 ,
V_54 , sizeof( * V_54 ) , V_107 ) ;
}
return V_75 ;
}
static int F_25 ( struct V_1 * V_2 , int V_71 ,
struct V_108 * V_54 )
{
int V_55 , V_75 = - V_103 ;
for ( V_55 = 0 ; V_55 < V_104 &&
( V_75 == - V_103 || V_75 == - V_105 ) ; V_55 ++ ) {
V_75 = F_13 ( V_2 , F_14 ( V_2 , 0 ) ,
V_106 , V_64 | V_72 , 0 , V_71 ,
V_54 , sizeof( * V_54 ) , V_107 ) ;
}
return V_75 ;
}
static int F_26 ( struct V_6 * V_7 , int V_71 ,
T_1 * V_75 , T_1 * V_109 )
{
int V_56 ;
F_27 ( & V_7 -> V_110 ) ;
V_56 = F_25 ( V_7 -> V_2 , V_71 , & V_7 -> V_75 -> V_111 ) ;
if ( V_56 < 4 ) {
if ( V_56 != - V_112 )
F_28 ( V_7 -> V_113 ,
L_14 , V_114 , V_56 ) ;
if ( V_56 >= 0 )
V_56 = - V_115 ;
} else {
* V_75 = F_29 ( V_7 -> V_75 -> V_111 . V_116 ) ;
* V_109 = F_29 ( V_7 -> V_75 -> V_111 . V_117 ) ;
V_56 = 0 ;
}
F_30 ( & V_7 -> V_110 ) ;
return V_56 ;
}
static void F_31 ( struct V_6 * V_7 )
{
unsigned long V_118 ;
F_32 ( & V_119 , V_118 ) ;
if ( ! V_7 -> V_120 && F_33 ( & V_7 -> V_121 ) ) {
F_34 ( & V_7 -> V_121 , & V_122 ) ;
F_35 (
F_36 ( V_7 -> V_113 ) ) ;
F_37 ( & V_123 ) ;
}
F_38 ( & V_119 , V_118 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_7 )
F_31 ( V_7 ) ;
}
void F_40 ( struct V_1 * V_2 ,
unsigned int V_124 )
{
struct V_6 * V_7 ;
if ( ! V_2 )
return;
V_7 = F_3 ( V_2 ) ;
if ( V_7 ) {
F_41 ( V_124 , V_7 -> V_125 ) ;
F_31 ( V_7 ) ;
}
}
static void F_42 ( struct V_126 * V_126 )
{
struct V_6 * V_7 = V_126 -> V_127 ;
int V_75 = V_126 -> V_75 ;
unsigned V_55 ;
unsigned long V_128 ;
switch ( V_75 ) {
case - V_129 :
case - V_130 :
case - V_131 :
return;
default:
F_20 ( V_7 -> V_113 , L_15 , V_75 ) ;
if ( ( ++ V_7 -> V_132 < 10 ) || V_7 -> error )
goto V_133;
V_7 -> error = V_75 ;
case 0 :
V_128 = 0 ;
for ( V_55 = 0 ; V_55 < V_126 -> V_134 ; ++ V_55 )
V_128 |= ( ( unsigned long ) ( ( * V_7 -> V_135 ) [ V_55 ] ) )
<< ( V_55 * 8 ) ;
V_7 -> V_136 [ 0 ] = V_128 ;
break;
}
V_7 -> V_132 = 0 ;
F_31 ( V_7 ) ;
V_133:
if ( V_7 -> V_84 )
return;
if ( ( V_75 = F_43 ( V_7 -> V_126 , V_137 ) ) != 0
&& V_75 != - V_112 && V_75 != - V_138 )
F_28 ( V_7 -> V_113 , L_16 , V_75 ) ;
}
static inline int
F_44 ( struct V_1 * V_2 , T_1 V_139 , T_1 V_140 )
{
if ( ( ( V_139 >> 11 ) & V_141 ) ==
V_142 ) {
int V_75 = F_13 ( V_2 , F_16 ( V_2 , 0 ) ,
V_143 , V_72 ,
V_139 ^ 0x8000 , V_140 , NULL , 0 , 1000 ) ;
if ( V_75 )
return V_75 ;
}
return F_13 ( V_2 , F_16 ( V_2 , 0 ) ,
V_143 , V_72 , V_139 ,
V_140 , NULL , 0 , 1000 ) ;
}
static void F_45 ( struct V_77 * V_78 )
{
struct V_6 * V_7 =
F_22 ( V_78 , struct V_6 , V_140 . V_144 ) ;
unsigned long V_118 ;
F_32 ( & V_7 -> V_140 . V_145 , V_118 ) ;
while ( ! F_33 ( & V_7 -> V_140 . V_146 ) ) {
struct V_147 * V_148 ;
struct V_149 * V_150 ;
struct V_1 * V_2 = V_7 -> V_2 ;
const struct V_151 * V_152 ;
int V_75 ;
V_148 = V_7 -> V_140 . V_146 . V_148 ;
V_150 = F_46 ( V_148 , struct V_149 , V_146 ) ;
F_47 ( & V_150 -> V_146 ) ;
F_38 ( & V_7 -> V_140 . V_145 , V_118 ) ;
V_75 = F_44 ( V_2 , V_150 -> V_139 , V_150 -> V_140 ) ;
if ( V_75 && V_75 != - V_112 )
F_28 ( & V_2 -> V_22 ,
L_17 ,
V_150 -> V_140 , V_150 -> V_139 , V_75 ) ;
V_152 = V_150 -> V_153 -> V_154 ;
if ( V_152 -> V_155 )
( V_152 -> V_155 ) ( V_150 -> V_153 , V_150 -> V_156 ) ;
F_48 ( V_150 ) ;
F_32 ( & V_7 -> V_140 . V_145 , V_118 ) ;
}
F_38 ( & V_7 -> V_140 . V_145 , V_118 ) ;
}
int F_49 ( struct V_1 * V_2 , struct V_6 * V_7 ,
int V_71 , bool V_157 )
{
int V_56 ;
struct V_158 * V_159 = V_7 -> V_160 [ V_71 - 1 ] ;
if ( V_157 )
V_56 = F_18 ( V_2 , V_71 , V_161 ) ;
else
V_56 = F_17 ( V_2 , V_71 , V_161 ) ;
if ( ! V_56 )
V_159 -> V_162 = V_157 ;
return V_56 ;
}
int F_50 ( struct V_126 * V_126 )
{
struct V_1 * V_14 = V_126 -> V_22 ;
int V_163 = V_126 -> V_163 ;
struct V_164 * V_140 = V_14 -> V_140 ;
unsigned long V_118 ;
struct V_149 * V_150 ;
if ( ( V_150 = F_51 ( sizeof *V_150 , V_137 ) ) == NULL ) {
F_28 ( & V_14 -> V_22 , L_18 ) ;
return - V_165 ;
}
V_150 -> V_140 = V_140 -> V_166 ? V_14 -> V_167 : 1 ;
V_150 -> V_139 = F_52 ( V_163 ) ;
V_150 -> V_139 |= V_14 -> V_168 << 4 ;
V_150 -> V_139 |= F_53 ( V_163 )
? ( V_142 << 11 )
: ( V_169 << 11 ) ;
if ( F_54 ( V_163 ) )
V_150 -> V_139 |= 1 << 15 ;
V_150 -> V_153 = F_55 ( V_14 -> V_170 ) ;
V_150 -> V_156 = V_126 -> V_156 ;
F_32 ( & V_140 -> V_145 , V_118 ) ;
F_34 ( & V_150 -> V_146 , & V_140 -> V_146 ) ;
F_56 ( & V_140 -> V_144 ) ;
F_38 ( & V_140 -> V_145 , V_118 ) ;
return 0 ;
}
static unsigned F_57 ( struct V_6 * V_7 , bool V_171 )
{
int V_71 ;
unsigned V_172 = V_7 -> V_3 -> V_173 * 2 ;
unsigned V_174 ;
T_1 V_175 =
F_29 ( V_7 -> V_3 -> V_175 ) ;
if ( ( V_175 & V_176 ) < 2 )
F_20 ( V_7 -> V_113 , L_19 ) ;
else
F_20 ( V_7 -> V_113 , L_20
L_21 ) ;
for ( V_71 = 1 ; V_71 <= V_7 -> V_3 -> V_85 ; V_71 ++ )
if ( V_7 -> V_160 [ V_71 - 1 ] -> V_162 )
F_18 ( V_7 -> V_2 , V_71 , V_161 ) ;
else
F_17 ( V_7 -> V_2 , V_71 ,
V_161 ) ;
V_174 = F_58 ( V_172 , ( unsigned ) 100 ) ;
if ( V_171 )
F_59 ( V_174 ) ;
return V_174 ;
}
static int F_60 ( struct V_6 * V_7 ,
T_1 * V_75 , T_1 * V_109 )
{
int V_56 ;
F_27 ( & V_7 -> V_110 ) ;
V_56 = F_24 ( V_7 -> V_2 , & V_7 -> V_75 -> V_7 ) ;
if ( V_56 < 0 ) {
if ( V_56 != - V_112 )
F_28 ( V_7 -> V_113 ,
L_14 , V_114 , V_56 ) ;
} else {
* V_75 = F_29 ( V_7 -> V_75 -> V_7 . V_177 ) ;
* V_109 = F_29 ( V_7 -> V_75 -> V_7 . V_178 ) ;
V_56 = 0 ;
}
F_30 ( & V_7 -> V_110 ) ;
return V_56 ;
}
static int F_61 ( struct V_6 * V_7 , int V_71 ,
unsigned int V_179 )
{
return F_18 ( V_7 -> V_2 ,
V_71 | ( V_179 << 3 ) ,
V_180 ) ;
}
static int F_62 ( struct V_6 * V_7 , int V_71 )
{
int V_56 ;
int V_181 ;
T_1 V_182 , V_8 ;
if ( ! F_1 ( V_7 -> V_2 ) )
return - V_68 ;
V_56 = F_61 ( V_7 , V_71 , V_183 ) ;
if ( V_56 )
return V_56 ;
for ( V_181 = 0 ; ; V_181 += V_184 ) {
V_56 = F_26 ( V_7 , V_71 , & V_8 , & V_182 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( ( V_8 & V_185 ) ==
V_183 )
break;
if ( V_181 >= V_186 )
break;
F_59 ( V_184 ) ;
}
if ( V_181 >= V_186 )
F_7 ( V_7 -> V_113 , L_22 ,
V_71 , V_181 ) ;
return F_61 ( V_7 , V_71 , V_187 ) ;
}
static int F_63 ( struct V_6 * V_7 , int V_71 , int V_188 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_56 = 0 ;
if ( V_7 -> V_160 [ V_71 - 1 ] -> V_189 && V_188 )
F_64 ( V_7 -> V_160 [ V_71 - 1 ] -> V_189 ,
V_190 ) ;
if ( ! V_7 -> error ) {
if ( F_1 ( V_7 -> V_2 ) )
V_56 = F_62 ( V_7 , V_71 ) ;
else
V_56 = F_17 ( V_2 , V_71 ,
V_191 ) ;
}
if ( V_56 && V_56 != - V_112 )
F_28 ( V_7 -> V_113 , L_23 ,
V_71 , V_56 ) ;
return V_56 ;
}
static void F_65 ( struct V_6 * V_7 , int V_71 )
{
F_20 ( V_7 -> V_113 , L_24 , V_71 ) ;
F_63 ( V_7 , V_71 , 1 ) ;
F_41 ( V_71 , V_7 -> V_192 ) ;
F_31 ( V_7 ) ;
}
int F_66 ( struct V_1 * V_14 )
{
struct V_6 * V_7 ;
struct V_193 * V_194 ;
if ( ! V_14 -> V_23 )
return - V_68 ;
V_7 = F_3 ( V_14 -> V_23 ) ;
V_194 = F_36 ( V_7 -> V_113 ) ;
F_67 ( V_194 ) ;
F_41 ( V_14 -> V_124 , V_7 -> V_195 ) ;
F_65 ( V_7 , V_14 -> V_124 ) ;
F_68 ( V_194 ) ;
return 0 ;
}
static void F_69 ( struct V_6 * V_7 , enum V_196 type )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_197 * V_153 ;
int V_56 ;
int V_71 ;
int V_75 ;
bool V_198 = false ;
unsigned V_174 ;
if ( type == V_199 )
goto V_200;
if ( type == V_201 )
goto V_202;
if ( type != V_203 ) {
if ( V_2 -> V_23 && F_1 ( V_2 ) ) {
V_56 = F_13 ( V_2 , F_16 ( V_2 , 0 ) ,
V_204 , V_65 ,
V_2 -> V_205 - 1 , 0 , NULL , 0 ,
V_206 ) ;
if ( V_56 < 0 )
F_28 ( V_7 -> V_113 ,
L_25 ) ;
}
if ( type == V_207 ) {
V_174 = F_57 ( V_7 , false ) ;
F_70 ( & V_7 -> V_208 , V_209 ) ;
F_23 ( & V_7 -> V_208 ,
F_71 ( V_174 ) ) ;
F_35 (
F_36 ( V_7 -> V_113 ) ) ;
return;
} else if ( type == V_210 ) {
V_153 = F_55 ( V_2 -> V_170 ) ;
if ( V_153 -> V_154 -> V_211 ) {
V_56 = V_153 -> V_154 -> V_211 ( V_153 , V_2 ,
& V_7 -> V_140 , V_212 ) ;
if ( V_56 < 0 ) {
F_28 ( V_7 -> V_113 , L_26
L_27
L_28 ) ;
F_28 ( V_7 -> V_113 , L_29
L_30
L_31 ) ;
}
}
F_57 ( V_7 , true ) ;
} else {
F_57 ( V_7 , true ) ;
}
}
V_200:
for ( V_71 = 1 ; V_71 <= V_2 -> V_12 ; ++ V_71 ) {
struct V_1 * V_14 = V_7 -> V_160 [ V_71 - 1 ] -> V_189 ;
T_1 V_8 , V_182 ;
V_8 = V_182 = 0 ;
V_75 = F_26 ( V_7 , V_71 , & V_8 , & V_182 ) ;
if ( V_14 || ( V_8 & V_213 ) )
F_20 ( V_7 -> V_113 ,
L_32 ,
V_71 , V_8 , V_182 ) ;
if ( ( V_8 & V_214 ) && (
type != V_203 ||
! ( V_8 & V_213 ) ||
! V_14 ||
V_14 -> V_82 == V_190 ) ) {
if ( ! F_1 ( V_2 ) ) {
F_17 ( V_2 , V_71 ,
V_191 ) ;
V_8 &= ~ V_214 ;
} else {
V_8 &= ~ V_214 ;
}
}
if ( V_182 & V_215 ) {
V_198 = true ;
F_17 ( V_7 -> V_2 , V_71 ,
V_216 ) ;
}
if ( V_182 & V_217 ) {
V_198 = true ;
F_17 ( V_7 -> V_2 , V_71 ,
V_218 ) ;
}
if ( ( V_182 & V_219 ) &&
F_1 ( V_7 -> V_2 ) ) {
V_198 = true ;
F_17 ( V_7 -> V_2 , V_71 ,
V_220 ) ;
}
if ( ! ( V_8 & V_213 ) ||
( V_182 & V_215 ) )
F_72 ( V_71 , V_7 -> V_195 ) ;
if ( ! V_14 || V_14 -> V_82 == V_190 ) {
if ( V_14 || ( V_8 & V_213 ) )
F_41 ( V_71 , V_7 -> V_192 ) ;
} else if ( V_8 & V_214 ) {
bool V_221 = ( V_8 &
V_185 ) ==
V_222 ;
if ( V_182 || ( F_1 ( V_7 -> V_2 ) &&
V_221 ) )
F_41 ( V_71 , V_7 -> V_192 ) ;
} else if ( V_14 -> V_223 ) {
struct V_158 * V_159 = V_7 -> V_160 [ V_71 - 1 ] ;
#ifdef F_73
V_14 -> V_224 = 1 ;
#endif
if ( V_159 -> V_162 )
F_41 ( V_71 , V_7 -> V_192 ) ;
} else {
F_64 ( V_14 , V_190 ) ;
F_41 ( V_71 , V_7 -> V_192 ) ;
}
}
if ( V_198 ) {
V_174 = V_225 ;
if ( type == V_199 ) {
F_70 ( & V_7 -> V_208 , V_226 ) ;
F_23 ( & V_7 -> V_208 ,
F_71 ( V_174 ) ) ;
return;
} else {
F_59 ( V_174 ) ;
}
}
V_202:
V_7 -> V_84 = 0 ;
V_75 = F_43 ( V_7 -> V_126 , V_212 ) ;
if ( V_75 < 0 )
F_28 ( V_7 -> V_113 , L_33 , V_75 ) ;
if ( V_7 -> V_227 && V_100 )
F_23 ( & V_7 -> V_79 , V_101 ) ;
F_31 ( V_7 ) ;
if ( type <= V_201 )
F_74 ( F_36 ( V_7 -> V_113 ) ) ;
}
static void V_209 ( struct V_77 * V_228 )
{
struct V_6 * V_7 = F_22 ( V_228 , struct V_6 , V_208 . V_78 ) ;
F_69 ( V_7 , V_199 ) ;
}
static void V_226 ( struct V_77 * V_228 )
{
struct V_6 * V_7 = F_22 ( V_228 , struct V_6 , V_208 . V_78 ) ;
F_69 ( V_7 , V_201 ) ;
}
static void F_75 ( struct V_6 * V_7 , enum V_229 type )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_55 ;
F_76 ( & V_7 -> V_208 ) ;
V_7 -> V_84 = 1 ;
if ( type != V_230 ) {
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; ++ V_55 ) {
if ( V_7 -> V_160 [ V_55 ] -> V_189 )
F_77 ( & V_7 -> V_160 [ V_55 ] -> V_189 ) ;
}
}
F_78 ( V_7 -> V_126 ) ;
if ( V_7 -> V_227 )
F_76 ( & V_7 -> V_79 ) ;
if ( V_7 -> V_140 . V_7 )
F_79 ( & V_7 -> V_140 . V_144 ) ;
}
static int F_80 ( struct V_193 * V_194 )
{
struct V_6 * V_7 = F_4 ( V_194 ) ;
F_75 ( V_7 , V_231 ) ;
return 0 ;
}
static int F_81 ( struct V_193 * V_194 )
{
struct V_6 * V_7 = F_4 ( V_194 ) ;
F_69 ( V_7 , V_232 ) ;
return 0 ;
}
static int F_82 ( struct V_6 * V_7 ,
struct V_233 * V_234 )
{
struct V_197 * V_153 ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_235 * V_236 = V_7 -> V_113 ;
T_1 V_237 , V_238 ;
T_1 V_175 ;
unsigned int V_163 ;
int V_239 , V_56 , V_55 ;
char * V_240 = L_34 ;
unsigned V_241 ;
unsigned V_242 ;
V_7 -> V_135 = F_51 ( sizeof( * V_7 -> V_135 ) , V_243 ) ;
if ( ! V_7 -> V_135 ) {
V_56 = - V_165 ;
goto V_244;
}
V_7 -> V_75 = F_51 ( sizeof( * V_7 -> V_75 ) , V_243 ) ;
if ( ! V_7 -> V_75 ) {
V_56 = - V_165 ;
goto V_244;
}
F_83 ( & V_7 -> V_110 ) ;
V_7 -> V_3 = F_51 ( sizeof( * V_7 -> V_3 ) , V_243 ) ;
if ( ! V_7 -> V_3 ) {
V_56 = - V_165 ;
goto V_244;
}
V_56 = F_12 ( V_2 , V_7 -> V_3 ) ;
if ( V_56 < 0 ) {
V_240 = L_35 ;
goto V_244;
} else if ( V_7 -> V_3 -> V_85 > V_245 ) {
V_240 = L_36 ;
V_56 = - V_112 ;
goto V_244;
} else if ( V_7 -> V_3 -> V_85 == 0 ) {
V_240 = L_37 ;
V_56 = - V_112 ;
goto V_244;
}
V_2 -> V_12 = V_7 -> V_3 -> V_85 ;
F_84 ( V_236 , L_38 , V_2 -> V_12 ,
( V_2 -> V_12 == 1 ) ? L_39 : L_40 ) ;
V_7 -> V_160 = F_85 ( V_2 -> V_12 * sizeof( struct V_158 * ) ,
V_243 ) ;
if ( ! V_7 -> V_160 ) {
V_56 = - V_165 ;
goto V_244;
}
V_175 = F_29 ( V_7 -> V_3 -> V_175 ) ;
if ( F_1 ( V_2 ) ) {
V_241 = 150 ;
V_242 = 900 ;
} else {
V_241 = 100 ;
V_242 = 500 ;
}
if ( ( V_175 & V_246 ) &&
! ( F_1 ( V_2 ) ) ) {
int V_55 ;
char V_247 [ V_245 + 1 ] ;
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; V_55 ++ )
V_247 [ V_55 ] = V_7 -> V_3 -> V_34 . V_248 . V_249
[ ( ( V_55 + 1 ) / 8 ) ] & ( 1 << ( ( V_55 + 1 ) % 8 ) )
? 'F' : 'R' ;
V_247 [ V_2 -> V_12 ] = 0 ;
F_20 ( V_236 , L_41 , V_247 ) ;
} else
F_20 ( V_236 , L_42 ) ;
switch ( V_175 & V_176 ) {
case V_250 :
F_20 ( V_236 , L_43 ) ;
break;
case V_251 :
F_20 ( V_236 , L_44 ) ;
break;
case V_252 :
case V_176 :
F_20 ( V_236 , L_45 ) ;
break;
}
switch ( V_175 & V_253 ) {
case V_254 :
F_20 ( V_236 , L_46 ) ;
break;
case V_255 :
F_20 ( V_236 , L_47 ) ;
break;
case V_256 :
case V_253 :
F_20 ( V_236 , L_48 ) ;
break;
}
F_86 ( & V_7 -> V_140 . V_145 ) ;
F_87 ( & V_7 -> V_140 . V_146 ) ;
F_88 ( & V_7 -> V_140 . V_144 , F_45 ) ;
switch ( V_2 -> V_3 . V_4 ) {
case V_257 :
break;
case V_258 :
F_20 ( V_236 , L_49 ) ;
V_7 -> V_140 . V_7 = V_2 ;
break;
case V_259 :
V_56 = F_89 ( V_2 , 0 , 1 ) ;
if ( V_56 == 0 ) {
F_20 ( V_236 , L_50 ) ;
V_7 -> V_140 . V_166 = 1 ;
} else
F_28 ( V_236 , L_51 ,
V_56 ) ;
V_7 -> V_140 . V_7 = V_2 ;
break;
case V_5 :
break;
default:
F_20 ( V_236 , L_52 ,
V_2 -> V_3 . V_4 ) ;
break;
}
switch ( V_175 & V_260 ) {
case V_261 :
if ( V_2 -> V_3 . V_4 != 0 ) {
V_7 -> V_140 . V_262 = 666 ;
F_20 ( V_236 , L_53
L_54 ,
8 , V_7 -> V_140 . V_262 ) ;
}
break;
case V_263 :
V_7 -> V_140 . V_262 = 666 * 2 ;
F_20 ( V_236 , L_53
L_54 ,
16 , V_7 -> V_140 . V_262 ) ;
break;
case V_264 :
V_7 -> V_140 . V_262 = 666 * 3 ;
F_20 ( V_236 , L_53
L_54 ,
24 , V_7 -> V_140 . V_262 ) ;
break;
case V_265 :
V_7 -> V_140 . V_262 = 666 * 4 ;
F_20 ( V_236 , L_53
L_54 ,
32 , V_7 -> V_140 . V_262 ) ;
break;
}
if ( V_175 & V_266 ) {
V_7 -> V_227 = 1 ;
F_20 ( V_236 , L_55 ) ;
}
F_20 ( V_236 , L_56 ,
V_7 -> V_3 -> V_173 * 2 ) ;
V_56 = F_90 ( V_2 , V_267 , 0 , & V_237 ) ;
if ( V_56 < 2 ) {
V_240 = L_57 ;
goto V_244;
}
F_91 ( & V_237 ) ;
V_153 = F_55 ( V_2 -> V_170 ) ;
if ( V_2 == V_2 -> V_170 -> V_268 ) {
if ( V_153 -> V_269 > 0 )
V_2 -> V_270 = V_153 -> V_269 ;
else
V_2 -> V_270 = V_242 * V_2 -> V_12 ;
if ( V_2 -> V_270 >= V_242 )
V_7 -> V_271 = V_242 ;
else {
V_7 -> V_271 = V_2 -> V_270 ;
V_7 -> V_272 = 1 ;
}
} else if ( ( V_237 & ( 1 << V_273 ) ) == 0 ) {
int V_274 = V_2 -> V_270 -
V_7 -> V_3 -> V_275 ;
F_20 ( V_236 , L_58 ,
V_7 -> V_3 -> V_275 ) ;
V_7 -> V_272 = 1 ;
if ( V_274 < V_2 -> V_12 * V_241 )
F_7 ( V_236 ,
L_59
L_60 ) ;
V_7 -> V_271 = V_241 ;
} else {
V_7 -> V_271 = V_242 ;
}
if ( V_7 -> V_271 < V_242 )
F_20 ( V_236 , L_61 ,
V_7 -> V_271 ) ;
if ( V_153 -> V_154 -> V_211 ) {
V_56 = V_153 -> V_154 -> V_211 ( V_153 , V_2 ,
& V_7 -> V_140 , V_243 ) ;
if ( V_56 < 0 ) {
V_240 = L_62 ;
goto V_244;
}
}
V_56 = F_60 ( V_7 , & V_237 , & V_238 ) ;
if ( V_56 < 0 ) {
V_240 = L_57 ;
goto V_244;
}
if ( V_2 -> V_11 -> V_276 . V_20 & V_277 )
F_20 ( V_236 , L_63 ,
( V_237 & V_278 )
? L_64 : L_65 ) ;
if ( ( V_175 & V_253 ) == 0 )
F_20 ( V_236 , L_66 ,
( V_237 & V_279 ) ? L_39 : L_67 ) ;
V_163 = F_92 ( V_2 , V_234 -> V_280 ) ;
V_239 = F_93 ( V_2 , V_163 , F_94 ( V_163 ) ) ;
if ( V_239 > sizeof( * V_7 -> V_135 ) )
V_239 = sizeof( * V_7 -> V_135 ) ;
V_7 -> V_126 = F_95 ( 0 , V_243 ) ;
if ( ! V_7 -> V_126 ) {
V_56 = - V_165 ;
goto V_244;
}
F_96 ( V_7 -> V_126 , V_2 , V_163 , * V_7 -> V_135 , V_239 , F_42 ,
V_7 , V_234 -> V_281 ) ;
if ( V_7 -> V_227 && V_100 )
V_7 -> V_87 [ 0 ] = V_88 ;
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; V_55 ++ )
if ( F_97 ( V_7 , V_55 + 1 ) < 0 )
F_28 ( V_7 -> V_113 ,
L_68 , V_55 + 1 ) ;
F_98 ( V_2 , V_7 -> V_3 ) ;
F_69 ( V_7 , V_207 ) ;
return 0 ;
V_244:
F_28 ( V_236 , L_69 ,
V_240 , V_56 ) ;
return V_56 ;
}
static void F_99 ( struct V_282 * V_282 )
{
struct V_6 * V_7 = F_22 ( V_282 , struct V_6 , V_282 ) ;
F_100 ( F_36 ( V_7 -> V_113 ) ) ;
F_48 ( V_7 ) ;
}
static void F_101 ( struct V_193 * V_194 )
{
struct V_6 * V_7 = F_4 ( V_194 ) ;
struct V_1 * V_2 = F_102 ( V_194 ) ;
int V_55 ;
F_103 ( & V_119 ) ;
if ( ! F_33 ( & V_7 -> V_121 ) ) {
F_104 ( & V_7 -> V_121 ) ;
F_105 ( V_194 ) ;
}
V_7 -> V_120 = 1 ;
F_106 ( & V_119 ) ;
V_7 -> error = 0 ;
F_75 ( V_7 , V_283 ) ;
F_107 ( V_194 , NULL ) ;
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; V_55 ++ )
F_108 ( V_7 , V_55 + 1 ) ;
V_7 -> V_2 -> V_12 = 0 ;
if ( V_7 -> V_2 -> V_15 == V_16 )
V_284 -- ;
F_109 ( V_7 -> V_126 ) ;
F_48 ( V_7 -> V_160 ) ;
F_48 ( V_7 -> V_3 ) ;
F_48 ( V_7 -> V_75 ) ;
F_48 ( V_7 -> V_135 ) ;
F_110 ( & V_194 -> V_22 , false ) ;
F_111 ( & V_7 -> V_282 , F_99 ) ;
}
static int F_112 ( struct V_193 * V_194 , const struct V_285 * V_286 )
{
struct V_287 * V_276 ;
struct V_233 * V_234 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
V_276 = V_194 -> V_288 ;
V_2 = F_102 ( V_194 ) ;
F_113 ( & V_2 -> V_22 , 0 ) ;
F_114 ( V_2 ) ;
if ( V_2 -> V_205 == V_289 ) {
F_28 ( & V_194 -> V_22 ,
L_70 ) ;
return - V_290 ;
}
#ifdef F_115
if ( V_2 -> V_23 ) {
F_7 ( & V_194 -> V_22 , L_71 ) ;
return - V_112 ;
}
#endif
if ( ( V_276 -> V_276 . V_291 != 0 ) &&
( V_276 -> V_276 . V_291 != 1 ) ) {
V_292:
F_28 ( & V_194 -> V_22 , L_72 ) ;
return - V_115 ;
}
if ( V_276 -> V_276 . V_293 != 1 )
goto V_292;
V_234 = & V_276 -> V_234 [ 0 ] . V_276 ;
if ( ! F_116 ( V_234 ) )
goto V_292;
F_84 ( & V_194 -> V_22 , L_73 ) ;
V_7 = F_85 ( sizeof( * V_7 ) , V_243 ) ;
if ( ! V_7 ) {
F_20 ( & V_194 -> V_22 , L_74 ) ;
return - V_165 ;
}
F_117 ( & V_7 -> V_282 ) ;
F_87 ( & V_7 -> V_121 ) ;
V_7 -> V_113 = & V_194 -> V_22 ;
V_7 -> V_2 = V_2 ;
F_118 ( & V_7 -> V_79 , F_21 ) ;
F_118 ( & V_7 -> V_208 , NULL ) ;
F_119 ( V_194 ) ;
F_107 ( V_194 , V_7 ) ;
V_194 -> V_294 = 1 ;
F_110 ( & V_194 -> V_22 , true ) ;
if ( V_2 -> V_15 == V_16 )
V_284 ++ ;
if ( V_286 -> V_295 & V_296 )
V_7 -> V_297 = 1 ;
if ( F_82 ( V_7 , V_234 ) >= 0 )
return 0 ;
F_101 ( V_194 ) ;
return - V_112 ;
}
static int
F_120 ( struct V_193 * V_194 , unsigned int V_298 , void * V_299 )
{
struct V_1 * V_2 = F_102 ( V_194 ) ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
switch ( V_298 ) {
case V_300 : {
struct V_301 * V_302 = V_299 ;
int V_55 ;
F_103 ( & V_303 ) ;
if ( V_2 -> V_168 <= 0 )
V_302 -> V_304 = 0 ;
else {
V_302 -> V_304 = V_2 -> V_12 ;
for ( V_55 = 0 ; V_55 < V_302 -> V_304 ; V_55 ++ ) {
if ( V_7 -> V_160 [ V_55 ] -> V_189 == NULL )
V_302 -> V_111 [ V_55 ] = 0 ;
else
V_302 -> V_111 [ V_55 ] =
V_7 -> V_160 [ V_55 ] -> V_189 -> V_168 ;
}
}
F_106 ( & V_303 ) ;
return V_302 -> V_304 + 1 ;
}
default:
return - V_305 ;
}
}
static int F_121 ( struct V_1 * V_2 , unsigned V_71 ,
struct V_306 * * * V_307 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_2 -> V_82 == V_190 )
return - V_112 ;
if ( V_71 == 0 || V_71 > V_2 -> V_12 )
return - V_68 ;
* V_307 = & ( V_7 -> V_160 [ V_71 - 1 ] -> V_308 ) ;
return 0 ;
}
int F_122 ( struct V_1 * V_2 , unsigned V_71 ,
struct V_306 * V_309 )
{
int V_310 ;
struct V_306 * * V_311 ;
V_310 = F_121 ( V_2 , V_71 , & V_311 ) ;
if ( V_310 )
return V_310 ;
if ( * V_311 )
return - V_312 ;
* V_311 = V_309 ;
return V_310 ;
}
int F_123 ( struct V_1 * V_2 , unsigned V_71 ,
struct V_306 * V_309 )
{
int V_310 ;
struct V_306 * * V_311 ;
V_310 = F_121 ( V_2 , V_71 , & V_311 ) ;
if ( V_310 )
return V_310 ;
if ( * V_311 != V_309 )
return - V_129 ;
* V_311 = NULL ;
return V_310 ;
}
void F_124 ( struct V_1 * V_2 , struct V_306 * V_309 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
int V_313 ;
for ( V_313 = 0 ; V_313 < V_2 -> V_12 ; V_313 ++ ) {
if ( V_7 -> V_160 [ V_313 ] -> V_308 == V_309 )
V_7 -> V_160 [ V_313 ] -> V_308 = NULL ;
}
}
bool F_125 ( struct V_1 * V_14 )
{
struct V_6 * V_7 ;
if ( V_14 -> V_82 == V_190 || ! V_14 -> V_23 )
return false ;
V_7 = F_3 ( V_14 -> V_23 ) ;
return ! ! V_7 -> V_160 [ V_14 -> V_124 - 1 ] -> V_308 ;
}
static void F_126 ( struct V_1 * V_14 )
{
struct V_6 * V_7 = F_3 ( V_14 ) ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_14 -> V_12 ; ++ V_55 ) {
if ( V_7 -> V_160 [ V_55 ] -> V_189 )
F_126 ( V_7 -> V_160 [ V_55 ] -> V_189 ) ;
}
if ( V_14 -> V_82 == V_314 )
V_14 -> V_315 -= V_316 ;
V_14 -> V_82 = V_190 ;
}
void F_64 ( struct V_1 * V_14 ,
enum V_317 V_318 )
{
unsigned long V_118 ;
int V_319 = - 1 ;
F_32 ( & V_303 , V_118 ) ;
if ( V_14 -> V_82 == V_190 )
;
else if ( V_318 != V_190 ) {
if ( V_14 -> V_23 ) {
if ( V_14 -> V_82 == V_314
|| V_318 == V_314 )
;
else if ( V_318 == V_83 )
V_319 = V_14 -> V_11 -> V_276 . V_20
& V_320 ;
else
V_319 = 0 ;
}
if ( V_14 -> V_82 == V_314 &&
V_318 != V_314 )
V_14 -> V_315 -= V_316 ;
else if ( V_318 == V_314 &&
V_14 -> V_82 != V_314 )
V_14 -> V_315 += V_316 ;
V_14 -> V_82 = V_318 ;
} else
F_126 ( V_14 ) ;
F_38 ( & V_303 , V_118 ) ;
if ( V_319 >= 0 )
F_127 ( & V_14 -> V_22 , V_319 ) ;
}
static void F_128 ( struct V_1 * V_14 )
{
int V_168 ;
struct V_321 * V_170 = V_14 -> V_170 ;
if ( V_14 -> V_322 ) {
V_168 = V_14 -> V_124 + 1 ;
F_129 ( F_130 ( V_168 , V_170 -> V_323 . V_324 ) ) ;
} else {
V_168 = F_131 ( V_170 -> V_323 . V_324 , 128 ,
V_170 -> V_325 ) ;
if ( V_168 >= 128 )
V_168 = F_131 ( V_170 -> V_323 . V_324 ,
128 , 1 ) ;
V_170 -> V_325 = ( V_168 >= 127 ? 1 : V_168 + 1 ) ;
}
if ( V_168 < 128 ) {
F_41 ( V_168 , V_170 -> V_323 . V_324 ) ;
V_14 -> V_168 = V_168 ;
}
}
static void F_132 ( struct V_1 * V_14 )
{
if ( V_14 -> V_168 > 0 ) {
F_72 ( V_14 -> V_168 , V_14 -> V_170 -> V_323 . V_324 ) ;
V_14 -> V_168 = - 1 ;
}
}
static void F_133 ( struct V_1 * V_14 , int V_168 )
{
if ( ! V_14 -> V_322 )
V_14 -> V_168 = V_168 ;
}
static void F_134 ( struct V_1 * V_14 )
{
struct V_197 * V_153 = F_55 ( V_14 -> V_170 ) ;
if ( V_153 -> V_154 -> V_326 && V_14 -> V_23 )
V_153 -> V_154 -> V_326 ( V_153 , V_14 ) ;
}
void F_77 ( struct V_1 * * V_327 )
{
struct V_1 * V_14 = * V_327 ;
struct V_6 * V_7 = F_3 ( V_14 ) ;
int V_55 ;
F_64 ( V_14 , V_190 ) ;
F_84 ( & V_14 -> V_22 , L_75 ,
V_14 -> V_168 ) ;
F_135 ( V_14 ) ;
for ( V_55 = 0 ; V_55 < V_14 -> V_12 ; V_55 ++ ) {
if ( V_7 -> V_160 [ V_55 ] -> V_189 )
F_77 ( & V_7 -> V_160 [ V_55 ] -> V_189 ) ;
}
F_20 ( & V_14 -> V_22 , L_76 ) ;
F_136 ( V_14 , 0 ) ;
F_137 ( V_14 ) ;
if ( V_14 -> V_23 ) {
struct V_6 * V_7 = F_3 ( V_14 -> V_23 ) ;
struct V_158 * V_159 = V_7 -> V_160 [ V_14 -> V_124 - 1 ] ;
F_138 ( & V_14 -> V_22 . V_328 , L_77 ) ;
F_138 ( & V_159 -> V_22 . V_328 , L_78 ) ;
if ( ! V_159 -> V_329 )
F_139 ( & V_159 -> V_22 ) ;
else
V_159 -> V_329 = false ;
}
F_140 ( & V_14 -> V_330 ) ;
F_141 ( V_14 ) ;
F_142 ( & V_14 -> V_22 ) ;
F_132 ( V_14 ) ;
F_103 ( & V_303 ) ;
* V_327 = NULL ;
F_106 ( & V_303 ) ;
F_134 ( V_14 ) ;
F_143 ( & V_14 -> V_22 ) ;
}
static void F_144 ( struct V_1 * V_14 , char * V_286 , char * string )
{
if ( ! string )
return;
F_84 ( & V_14 -> V_22 , L_79 , V_286 , string ) ;
}
static void F_145 ( struct V_1 * V_14 )
{
F_84 ( & V_14 -> V_22 , L_80 ,
F_29 ( V_14 -> V_3 . V_331 ) ,
F_29 ( V_14 -> V_3 . V_332 ) ) ;
F_84 ( & V_14 -> V_22 ,
L_81 ,
V_14 -> V_3 . V_333 ,
V_14 -> V_3 . V_334 ,
V_14 -> V_3 . V_335 ) ;
F_144 ( V_14 , L_82 , V_14 -> V_336 ) ;
F_144 ( V_14 , L_83 , V_14 -> V_337 ) ;
F_144 ( V_14 , L_84 , V_14 -> V_338 ) ;
}
static inline void F_145 ( struct V_1 * V_14 ) { }
static int F_146 ( struct V_1 * V_14 )
{
int V_339 = 0 ;
#ifdef F_147
if ( ! V_14 -> V_170 -> V_340
&& V_14 -> V_341
&& V_14 -> V_23 == V_14 -> V_170 -> V_268 ) {
struct V_342 * V_276 = NULL ;
struct V_321 * V_170 = V_14 -> V_170 ;
if ( F_148 ( V_14 -> V_343 [ 0 ] ,
F_29 ( V_14 -> V_341 [ 0 ] . V_276 . V_344 ) ,
V_345 , ( void * * ) & V_276 ) == 0 ) {
if ( V_276 -> V_20 & V_346 ) {
unsigned V_71 = V_14 -> V_124 ;
F_84 ( & V_14 -> V_22 ,
L_85 ,
( V_71 == V_170 -> V_347 )
? L_39 : L_86 ) ;
if ( V_71 == V_170 -> V_347 )
V_170 -> V_348 = 1 ;
V_339 = F_13 ( V_14 ,
F_16 ( V_14 , 0 ) ,
V_73 , 0 ,
V_170 -> V_348
? V_349
: V_350 ,
0 , NULL , 0 , V_206 ) ;
if ( V_339 < 0 ) {
F_84 ( & V_14 -> V_22 ,
L_87 ,
V_339 ) ;
V_170 -> V_348 = 0 ;
}
}
}
}
if ( ! F_149 ( V_14 ) ) {
if ( V_14 -> V_170 -> V_348 || V_14 -> V_170 -> V_340 ) {
V_339 = F_150 ( V_14 , V_351 ) ;
if ( V_339 < 0 )
F_20 ( & V_14 -> V_22 , L_88 , V_339 ) ;
}
V_339 = - V_352 ;
goto V_244;
}
V_244:
#endif
return V_339 ;
}
static int F_151 ( struct V_1 * V_14 )
{
int V_339 ;
if ( V_14 -> V_341 == NULL ) {
V_339 = F_152 ( V_14 ) ;
if ( V_339 < 0 ) {
if ( V_339 != - V_112 )
F_28 ( & V_14 -> V_22 , L_89 ,
V_339 ) ;
return V_339 ;
}
}
if ( V_14 -> V_322 == 1 && V_14 -> V_353 == 0 ) {
V_14 -> V_336 = F_153 ( L_90 , V_243 ) ;
V_14 -> V_337 = F_153 ( L_90 , V_243 ) ;
V_14 -> V_338 = F_153 ( L_90 , V_243 ) ;
}
else {
V_14 -> V_336 = F_154 ( V_14 , V_14 -> V_3 . V_334 ) ;
V_14 -> V_337 = F_154 ( V_14 ,
V_14 -> V_3 . V_333 ) ;
V_14 -> V_338 = F_154 ( V_14 , V_14 -> V_3 . V_335 ) ;
}
V_339 = F_146 ( V_14 ) ;
if ( V_339 < 0 )
return V_339 ;
F_155 ( V_14 ) ;
return 0 ;
}
static void F_156 ( struct V_1 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_23 ;
struct V_6 * V_7 ;
T_2 V_111 = V_14 -> V_124 ;
T_1 V_175 ;
bool V_354 = true ;
if ( ! V_2 )
return;
V_7 = F_3 ( V_14 -> V_23 ) ;
V_175 = F_29 ( V_7 -> V_3 -> V_175 ) ;
if ( ! ( V_175 & V_246 ) )
return;
if ( F_1 ( V_2 ) ) {
if ( F_29 ( V_7 -> V_3 -> V_34 . V_35 . V_249 )
& ( 1 << V_111 ) )
V_354 = false ;
} else {
if ( V_7 -> V_3 -> V_34 . V_248 . V_249 [ V_111 / 8 ] & ( 1 << ( V_111 % 8 ) ) )
V_354 = false ;
}
if ( V_354 )
V_14 -> V_354 = V_355 ;
else
V_14 -> V_354 = V_356 ;
}
int F_157 ( struct V_1 * V_14 )
{
int V_339 ;
if ( V_14 -> V_23 ) {
F_158 ( & V_14 -> V_22 , 0 ) ;
}
F_159 ( & V_14 -> V_22 ) ;
F_160 ( & V_14 -> V_22 ) ;
F_161 ( & V_14 -> V_22 ) ;
F_162 ( & V_14 -> V_22 ) ;
F_163 ( V_14 ) ;
V_339 = F_151 ( V_14 ) ;
if ( V_339 < 0 )
goto V_244;
F_20 ( & V_14 -> V_22 , L_91 ,
V_14 -> V_168 , V_14 -> V_170 -> V_357 ,
( ( ( V_14 -> V_170 -> V_357 - 1 ) * 128 ) + ( V_14 -> V_168 - 1 ) ) ) ;
V_14 -> V_22 . V_358 = F_164 ( V_359 ,
( ( ( V_14 -> V_170 -> V_357 - 1 ) * 128 ) + ( V_14 -> V_168 - 1 ) ) ) ;
F_145 ( V_14 ) ;
if ( V_14 -> V_338 )
F_165 ( V_14 -> V_338 , strlen ( V_14 -> V_338 ) ) ;
if ( V_14 -> V_336 )
F_165 ( V_14 -> V_336 , strlen ( V_14 -> V_336 ) ) ;
if ( V_14 -> V_337 )
F_165 ( V_14 -> V_337 ,
strlen ( V_14 -> V_337 ) ) ;
F_166 ( & V_14 -> V_22 ) ;
if ( V_14 -> V_23 )
F_156 ( V_14 ) ;
V_339 = F_167 ( & V_14 -> V_22 ) ;
if ( V_339 ) {
F_28 ( & V_14 -> V_22 , L_92 , V_339 ) ;
goto V_244;
}
if ( V_14 -> V_23 ) {
struct V_6 * V_7 = F_3 ( V_14 -> V_23 ) ;
struct V_158 * V_159 = V_7 -> V_160 [ V_14 -> V_124 - 1 ] ;
V_339 = F_168 ( & V_14 -> V_22 . V_328 ,
& V_159 -> V_22 . V_328 , L_77 ) ;
if ( V_339 )
goto V_244;
V_339 = F_168 ( & V_159 -> V_22 . V_328 ,
& V_14 -> V_22 . V_328 , L_78 ) ;
if ( V_339 ) {
F_138 ( & V_14 -> V_22 . V_328 , L_77 ) ;
goto V_244;
}
F_169 ( & V_159 -> V_22 ) ;
}
( void ) F_170 ( & V_14 -> V_22 , & V_14 -> V_330 , V_14 ) ;
F_171 ( V_14 ) ;
F_172 ( & V_14 -> V_22 ) ;
return V_339 ;
V_244:
F_64 ( V_14 , V_190 ) ;
F_173 ( & V_14 -> V_22 ) ;
F_174 ( & V_14 -> V_22 ) ;
return V_339 ;
}
int F_175 ( struct V_1 * V_360 )
{
F_135 ( V_360 ) ;
if ( V_360 -> V_353 == 0 )
goto V_361;
V_360 -> V_353 = 0 ;
F_176 ( V_360 , - 1 ) ;
F_48 ( V_360 -> V_336 ) ;
V_360 -> V_336 = F_153 ( L_90 , V_243 ) ;
F_48 ( V_360 -> V_337 ) ;
V_360 -> V_337 = F_153 ( L_90 , V_243 ) ;
F_48 ( V_360 -> V_338 ) ;
V_360 -> V_338 = F_153 ( L_90 , V_243 ) ;
F_177 ( V_360 ) ;
V_360 -> V_3 . V_362 = 0 ;
V_361:
F_141 ( V_360 ) ;
return 0 ;
}
int F_178 ( struct V_1 * V_360 )
{
int V_363 = 0 , V_364 ;
F_135 ( V_360 ) ;
if ( V_360 -> V_353 == 1 )
goto V_365;
V_363 = F_179 ( V_360 ) ;
if ( V_363 < 0 ) {
F_28 ( & V_360 -> V_22 ,
L_93 , V_363 ) ;
goto V_366;
}
V_363 = F_180 ( V_360 , sizeof( V_360 -> V_3 ) ) ;
if ( V_363 < 0 ) {
F_28 ( & V_360 -> V_22 , L_94
L_95 , V_363 ) ;
goto V_367;
}
F_48 ( V_360 -> V_336 ) ;
V_360 -> V_336 = NULL ;
F_48 ( V_360 -> V_337 ) ;
V_360 -> V_337 = NULL ;
F_48 ( V_360 -> V_338 ) ;
V_360 -> V_338 = NULL ;
V_360 -> V_353 = 1 ;
V_363 = F_151 ( V_360 ) ;
if ( V_363 < 0 )
goto V_368;
V_364 = F_181 ( V_360 ) ;
if ( V_364 >= 0 ) {
V_363 = F_176 ( V_360 , V_364 ) ;
if ( V_363 ) {
F_28 ( & V_360 -> V_22 ,
L_96 , V_364 , V_363 ) ;
}
}
F_84 ( & V_360 -> V_22 , L_97 ) ;
V_368:
V_367:
F_182 ( V_360 ) ;
V_366:
V_365:
F_141 ( V_360 ) ;
return V_363 ;
}
static unsigned F_183 ( struct V_6 * V_7 )
{
struct V_197 * V_153 ;
if ( V_7 -> V_2 -> V_23 != NULL )
return 0 ;
V_153 = F_22 ( V_7 -> V_2 -> V_170 , struct V_197 , V_369 ) ;
return V_153 -> V_370 ;
}
static bool F_184 ( struct V_6 * V_7 , T_1 V_8 )
{
return F_1 ( V_7 -> V_2 ) &&
( ( ( V_8 & V_185 ) ==
V_371 ) ||
( ( V_8 & V_185 ) ==
V_372 ) ) ;
}
static int F_185 ( struct V_6 * V_7 , int V_71 ,
struct V_1 * V_14 , unsigned int V_174 , bool V_373 )
{
int V_374 , V_56 ;
T_1 V_8 ;
T_1 V_182 ;
for ( V_374 = 0 ;
V_374 < V_375 ;
V_374 += V_174 ) {
F_59 ( V_174 ) ;
V_56 = F_26 ( V_7 , V_71 , & V_8 , & V_182 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( ! ( V_8 & V_376 ) )
break;
if ( V_374 >= 2 * V_377 )
V_174 = V_378 ;
F_20 ( V_7 -> V_113 ,
L_98 ,
V_71 , V_373 ? L_99 : L_39 , V_174 ) ;
}
if ( ( V_8 & V_376 ) )
return - V_312 ;
if ( F_184 ( V_7 , V_8 ) )
return - V_379 ;
if ( ! ( V_8 & V_213 ) )
return - V_379 ;
if ( ! F_1 ( V_7 -> V_2 ) &&
( V_182 & V_215 ) )
return - V_379 ;
if ( ! ( V_8 & V_214 ) )
return - V_312 ;
if ( ! V_14 )
return 0 ;
if ( F_183 ( V_7 ) )
V_14 -> V_15 = V_380 ;
else if ( F_1 ( V_7 -> V_2 ) )
V_14 -> V_15 = V_49 ;
else if ( V_8 & V_9 )
V_14 -> V_15 = V_16 ;
else if ( V_8 & V_10 )
V_14 -> V_15 = V_381 ;
else
V_14 -> V_15 = V_382 ;
return 0 ;
}
static void F_186 ( struct V_6 * V_7 , int V_71 ,
struct V_1 * V_14 , int * V_75 )
{
switch ( * V_75 ) {
case 0 :
F_59 ( 10 + 40 ) ;
if ( V_14 ) {
struct V_197 * V_153 = F_55 ( V_14 -> V_170 ) ;
F_133 ( V_14 , 0 ) ;
if ( V_153 -> V_154 -> V_383 )
V_153 -> V_154 -> V_383 ( V_153 , V_14 ) ;
}
case - V_379 :
case - V_112 :
F_17 ( V_7 -> V_2 ,
V_71 , V_384 ) ;
if ( F_1 ( V_7 -> V_2 ) ) {
F_17 ( V_7 -> V_2 , V_71 ,
V_220 ) ;
F_17 ( V_7 -> V_2 , V_71 ,
V_385 ) ;
F_17 ( V_7 -> V_2 , V_71 ,
V_216 ) ;
}
if ( V_14 )
F_64 ( V_14 , * V_75
? V_190
: V_386 ) ;
break;
}
}
static int F_187 ( struct V_6 * V_7 , int V_71 ,
struct V_1 * V_14 , unsigned int V_174 , bool V_373 )
{
int V_55 , V_75 ;
T_1 V_182 , V_8 ;
if ( ! F_1 ( V_7 -> V_2 ) ) {
if ( V_373 ) {
F_28 ( V_7 -> V_113 , L_100
L_101 ) ;
return - V_68 ;
}
F_188 ( & V_387 ) ;
} else if ( ! V_373 ) {
V_75 = F_26 ( V_7 , V_71 ,
& V_8 , & V_182 ) ;
if ( V_75 < 0 )
goto V_388;
if ( F_184 ( V_7 , V_8 ) )
V_373 = true ;
}
for ( V_55 = 0 ; V_55 < V_389 ; V_55 ++ ) {
V_75 = F_18 ( V_7 -> V_2 , V_71 , ( V_373 ?
V_390 :
V_391 ) ) ;
if ( V_75 == - V_112 ) {
;
} else if ( V_75 ) {
F_28 ( V_7 -> V_113 ,
L_102 ,
V_373 ? L_99 : L_39 , V_71 , V_75 ) ;
} else {
V_75 = F_185 ( V_7 , V_71 , V_14 , V_174 ,
V_373 ) ;
if ( V_75 && V_75 != - V_379 && V_75 != - V_112 )
F_20 ( V_7 -> V_113 ,
L_103 ,
V_75 ) ;
}
if ( V_75 == 0 || V_75 == - V_379 || V_75 == - V_112 ) {
F_186 ( V_7 , V_71 , V_14 , & V_75 ) ;
if ( ! F_1 ( V_7 -> V_2 ) )
goto V_388;
if ( F_26 ( V_7 , V_71 ,
& V_8 , & V_182 ) < 0 )
goto V_388;
if ( ! F_184 ( V_7 , V_8 ) )
goto V_388;
if ( ! V_373 ) {
F_20 ( V_7 -> V_113 , L_104 ,
V_71 ) ;
V_373 = true ;
}
}
F_20 ( V_7 -> V_113 ,
L_105 ,
V_71 , V_373 ? L_99 : L_39 ) ;
V_174 = V_378 ;
}
F_28 ( V_7 -> V_113 ,
L_106 ,
V_71 ) ;
V_388:
if ( ! F_1 ( V_7 -> V_2 ) )
F_189 ( & V_387 ) ;
return V_75 ;
}
static int F_190 ( struct V_6 * V_7 , unsigned V_8 )
{
int V_56 = 0 ;
if ( F_1 ( V_7 -> V_2 ) ) {
if ( V_8 & V_392 )
V_56 = 1 ;
} else {
if ( V_8 & V_393 )
V_56 = 1 ;
}
return V_56 ;
}
static int F_191 ( struct V_6 * V_7 , unsigned V_8 )
{
int V_56 = 0 ;
if ( F_1 ( V_7 -> V_2 ) ) {
if ( ( V_8 & V_185 )
== V_394 )
V_56 = 1 ;
} else {
if ( V_8 & V_395 )
V_56 = 1 ;
}
return V_56 ;
}
static int F_192 ( struct V_1 * V_14 ,
struct V_6 * V_7 , int V_71 ,
int V_75 , unsigned V_182 , unsigned V_8 )
{
if ( V_75 || F_191 ( V_7 , V_8 ) ||
! F_190 ( V_7 , V_8 ) ||
! ( V_8 & V_213 ) ) {
if ( V_75 >= 0 )
V_75 = - V_112 ;
}
else if ( ! ( V_8 & V_214 ) && ! V_14 -> V_224 ) {
if ( V_14 -> V_223 )
V_14 -> V_224 = 1 ;
else
V_75 = - V_112 ;
}
if ( V_75 ) {
F_20 ( V_7 -> V_113 ,
L_107 ,
V_71 , V_182 , V_8 , V_75 ) ;
} else if ( V_14 -> V_224 ) {
if ( V_182 & V_215 )
F_17 ( V_7 -> V_2 , V_71 ,
V_216 ) ;
if ( V_182 & V_217 )
F_17 ( V_7 -> V_2 , V_71 ,
V_218 ) ;
}
return V_75 ;
}
int F_193 ( struct V_1 * V_14 )
{
struct V_197 * V_153 = F_55 ( V_14 -> V_170 ) ;
if ( ! F_194 ( V_153 -> V_369 . V_268 ) ||
! F_194 ( V_14 ) )
return 0 ;
if ( ! V_14 -> V_11 )
return 0 ;
return F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_70 , V_267 ,
V_396 , 0 , NULL , 0 ,
V_206 ) ;
}
void F_195 ( struct V_1 * V_14 )
{
struct V_197 * V_153 = F_55 ( V_14 -> V_170 ) ;
if ( ! F_194 ( V_153 -> V_369 . V_268 ) ||
! F_194 ( V_14 ) )
return;
if ( ! V_14 -> V_11 )
return;
F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_73 , V_267 ,
V_396 , 0 , NULL , 0 ,
V_206 ) ;
}
static int F_196 ( struct V_1 * V_14 )
{
return F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_70 , V_397 ,
V_398 , 0 , NULL , 0 ,
V_206 ) ;
}
static unsigned F_197 ( struct V_1 * V_14 )
{
struct V_6 * V_7 = F_3 ( V_14 ) ;
return V_14 -> V_399 +
( V_7 ? V_7 -> F_197 : 0 ) ;
}
int F_150 ( struct V_1 * V_14 , T_3 V_400 )
{
struct V_6 * V_7 = F_3 ( V_14 -> V_23 ) ;
struct V_158 * V_159 = V_7 -> V_160 [ V_14 -> V_124 - 1 ] ;
enum V_401 V_402 ;
int V_71 = V_14 -> V_124 ;
int V_75 ;
bool V_403 = true ;
if ( V_14 -> V_399 ) {
if ( ! F_1 ( V_7 -> V_2 ) ) {
V_75 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_73 , V_267 ,
V_404 , 0 ,
NULL , 0 ,
V_206 ) ;
} else {
V_75 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_73 ,
V_397 ,
V_398 ,
V_405 |
V_406 ,
NULL , 0 ,
V_206 ) ;
}
if ( V_75 ) {
F_20 ( & V_14 -> V_22 , L_108 ,
V_75 ) ;
if ( F_198 ( V_400 ) )
return V_75 ;
}
}
if ( V_14 -> V_407 == 1 )
F_199 ( V_14 , 0 ) ;
if ( F_193 ( V_14 ) ) {
F_28 ( & V_14 -> V_22 , L_109 ,
V_114 ) ;
return - V_165 ;
}
if ( F_200 ( V_14 ) ) {
F_28 ( & V_14 -> V_22 , L_110 ,
V_114 ) ;
return - V_165 ;
}
if ( F_1 ( V_7 -> V_2 ) )
V_75 = F_61 ( V_7 , V_71 , V_394 ) ;
else if ( F_198 ( V_400 ) || F_197 ( V_14 ) > 0 )
V_75 = F_18 ( V_7 -> V_2 , V_71 ,
V_408 ) ;
else {
V_403 = false ;
V_75 = 0 ;
}
if ( V_75 ) {
F_20 ( V_7 -> V_113 , L_111 ,
V_71 , V_75 ) ;
if ( V_14 -> V_399 ) {
if ( ! F_1 ( V_7 -> V_2 ) ) {
( void ) F_13 ( V_14 ,
F_16 ( V_14 , 0 ) ,
V_70 ,
V_267 ,
V_404 , 0 ,
NULL , 0 ,
V_206 ) ;
} else
( void ) F_196 ( V_14 ) ;
}
if ( V_14 -> V_409 == 1 )
F_199 ( V_14 , 1 ) ;
F_195 ( V_14 ) ;
F_201 ( V_14 ) ;
if ( ! F_198 ( V_400 ) )
V_75 = 0 ;
} else {
F_20 ( & V_14 -> V_22 , L_112 ,
( F_198 ( V_400 ) ? L_113 : L_39 ) ,
V_14 -> V_399 ) ;
if ( V_403 ) {
V_14 -> F_191 = 1 ;
F_59 ( 10 ) ;
}
F_64 ( V_14 , V_314 ) ;
}
V_402 = F_202 ( & V_159 -> V_22 ,
V_410 ) ;
if ( ! V_14 -> V_399
&& V_402 != V_411
&& V_14 -> V_223
&& ! V_75 ) {
F_203 ( & V_159 -> V_22 ) ;
V_159 -> V_329 = true ;
}
F_171 ( V_7 -> V_2 ) ;
return V_75 ;
}
static int F_204 ( struct V_1 * V_14 )
{
int V_75 = 0 ;
T_1 V_412 = 0 ;
F_20 ( & V_14 -> V_22 , L_114 ,
V_14 -> V_224 ? L_115 : L_116 ) ;
F_64 ( V_14 , V_14 -> V_11
? V_83
: V_413 ) ;
if ( V_14 -> V_224 )
V_414:
V_75 = F_205 ( V_14 ) ;
if ( V_75 == 0 ) {
V_412 = 0 ;
V_75 = F_90 ( V_14 , V_267 , 0 , & V_412 ) ;
if ( V_75 >= 0 )
V_75 = ( V_75 > 0 ? 0 : - V_112 ) ;
if ( V_75 && ! V_14 -> V_224 && V_14 -> V_223 ) {
F_20 ( & V_14 -> V_22 , L_117 ) ;
V_14 -> V_224 = 1 ;
goto V_414;
}
}
if ( V_75 ) {
F_20 ( & V_14 -> V_22 , L_118 ,
V_75 ) ;
} else if ( V_14 -> V_11 && ! V_14 -> V_224 ) {
if ( ! F_1 ( V_14 -> V_23 ) ) {
F_91 ( & V_412 ) ;
if ( V_412 & ( 1 << V_404 ) )
V_75 = F_13 ( V_14 ,
F_16 ( V_14 , 0 ) ,
V_70 ,
V_267 ,
V_404 , 0 ,
NULL , 0 ,
V_206 ) ;
} else {
V_75 = F_90 ( V_14 , V_397 , 0 ,
& V_412 ) ;
F_91 ( & V_412 ) ;
if ( ! V_75 && V_412 & ( V_415
| V_416 ) )
V_75 =
F_196 ( V_14 ) ;
}
if ( V_75 )
F_20 ( & V_14 -> V_22 ,
L_119 ,
V_75 ) ;
V_75 = 0 ;
}
return V_75 ;
}
int F_206 ( struct V_1 * V_14 , T_3 V_400 )
{
struct V_6 * V_7 = F_3 ( V_14 -> V_23 ) ;
struct V_158 * V_159 = V_7 -> V_160 [ V_14 -> V_124 - 1 ] ;
int V_71 = V_14 -> V_124 ;
int V_75 ;
T_1 V_182 , V_8 ;
if ( V_159 -> V_329 ) {
V_75 = F_169 ( & V_159 -> V_22 ) ;
V_159 -> V_329 = false ;
if ( V_75 < 0 ) {
F_20 ( & V_14 -> V_22 , L_120 ,
V_75 ) ;
return V_75 ;
}
}
V_75 = F_26 ( V_7 , V_71 , & V_8 , & V_182 ) ;
if ( V_75 == 0 && ! F_191 ( V_7 , V_8 ) )
goto V_417;
F_41 ( V_71 , V_7 -> V_418 ) ;
if ( F_1 ( V_7 -> V_2 ) )
V_75 = F_61 ( V_7 , V_71 , V_222 ) ;
else
V_75 = F_17 ( V_7 -> V_2 ,
V_71 , V_408 ) ;
if ( V_75 ) {
F_20 ( V_7 -> V_113 , L_121 ,
V_71 , V_75 ) ;
} else {
F_20 ( & V_14 -> V_22 , L_122 ,
( F_198 ( V_400 ) ? L_113 : L_39 ) ) ;
F_59 ( 25 ) ;
V_75 = F_26 ( V_7 , V_71 , & V_8 , & V_182 ) ;
F_59 ( 10 ) ;
}
V_417:
if ( V_75 == 0 ) {
V_14 -> F_191 = 0 ;
if ( F_1 ( V_7 -> V_2 ) ) {
if ( V_182 & V_419 )
F_17 ( V_7 -> V_2 , V_71 ,
V_385 ) ;
} else {
if ( V_182 & V_420 )
F_17 ( V_7 -> V_2 , V_71 ,
V_421 ) ;
}
}
F_72 ( V_71 , V_7 -> V_418 ) ;
V_75 = F_192 ( V_14 ,
V_7 , V_71 , V_75 , V_182 , V_8 ) ;
if ( V_75 == 0 )
V_75 = F_204 ( V_14 ) ;
if ( V_75 < 0 ) {
F_20 ( & V_14 -> V_22 , L_123 , V_75 ) ;
F_65 ( V_7 , V_71 ) ;
} else {
if ( V_14 -> V_409 == 1 )
F_199 ( V_14 , 1 ) ;
F_195 ( V_14 ) ;
F_201 ( V_14 ) ;
}
return V_75 ;
}
int F_207 ( struct V_1 * V_14 )
{
int V_75 = 0 ;
if ( V_14 -> V_82 == V_314 ) {
F_20 ( & V_14 -> V_22 , L_122 , L_124 ) ;
V_75 = F_179 ( V_14 ) ;
if ( V_75 == 0 ) {
F_182 ( V_14 ) ;
}
}
return V_75 ;
}
static int F_208 ( struct V_6 * V_7 )
{
int V_71 ;
for ( V_71 = 1 ; V_71 <= V_7 -> V_2 -> V_12 ; ++ V_71 ) {
T_1 V_8 , V_182 ;
int V_75 ;
V_75 = F_26 ( V_7 , V_71 , & V_8 , & V_182 ) ;
if ( ! V_75 && V_182 )
return 1 ;
}
return 0 ;
}
static int F_209 ( struct V_193 * V_194 , T_3 V_400 )
{
struct V_6 * V_7 = F_4 ( V_194 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
unsigned V_71 ;
int V_75 ;
V_7 -> F_197 = 0 ;
for ( V_71 = 1 ; V_71 <= V_2 -> V_12 ; V_71 ++ ) {
struct V_1 * V_14 ;
V_14 = V_7 -> V_160 [ V_71 - 1 ] -> V_189 ;
if ( V_14 && V_14 -> V_422 ) {
F_7 ( & V_194 -> V_22 , L_125 , V_71 ) ;
if ( F_198 ( V_400 ) )
return - V_312 ;
}
if ( V_14 )
V_7 -> F_197 +=
F_197 ( V_14 ) ;
}
if ( V_2 -> V_399 && V_7 -> V_297 ) {
if ( F_208 ( V_7 ) ) {
if ( F_198 ( V_400 ) )
return - V_312 ;
F_210 ( & V_2 -> V_22 , 2000 ) ;
}
}
if ( F_1 ( V_2 ) && V_2 -> V_399 ) {
for ( V_71 = 1 ; V_71 <= V_2 -> V_12 ; V_71 ++ ) {
V_75 = F_18 ( V_2 ,
V_71 |
V_423 |
V_424 |
V_425 ,
V_426 ) ;
}
}
F_20 ( & V_194 -> V_22 , L_114 , V_114 ) ;
F_75 ( V_7 , V_230 ) ;
return 0 ;
}
static int F_211 ( struct V_193 * V_194 )
{
struct V_6 * V_7 = F_4 ( V_194 ) ;
F_20 ( & V_194 -> V_22 , L_114 , V_114 ) ;
F_69 ( V_7 , V_203 ) ;
return 0 ;
}
static int F_212 ( struct V_193 * V_194 )
{
struct V_6 * V_7 = F_4 ( V_194 ) ;
F_20 ( & V_194 -> V_22 , L_114 , V_114 ) ;
F_69 ( V_7 , V_210 ) ;
return 0 ;
}
void F_213 ( struct V_1 * V_427 )
{
F_7 ( & V_427 -> V_22 , L_126 ) ;
V_427 -> V_224 = 1 ;
}
static int F_214 ( struct V_1 * V_14 , enum V_428 V_82 )
{
struct V_429 * V_430 ;
unsigned long long V_431 ;
unsigned long long V_432 ;
unsigned long long V_433 ;
unsigned long long V_434 ;
int V_56 ;
V_431 = F_215 ( V_14 -> V_52 . V_43 , 1000 ) ;
V_432 = F_215 ( V_14 -> V_52 . V_40 , 1000 ) ;
V_433 = F_215 ( V_14 -> V_53 . V_43 , 1000 ) ;
V_434 = F_215 ( V_14 -> V_53 . V_40 , 1000 ) ;
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
V_430 = F_51 ( sizeof *( V_430 ) , V_212 ) ;
if ( ! V_430 )
return - V_165 ;
V_430 -> V_431 = V_431 ;
V_430 -> V_432 = V_432 ;
V_430 -> V_433 = F_216 ( V_433 ) ;
V_430 -> V_434 = F_216 ( V_434 ) ;
V_56 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_440 ,
V_267 ,
0 , 0 ,
V_430 , sizeof *( V_430 ) ,
V_206 ) ;
F_48 ( V_430 ) ;
return V_56 ;
}
static int F_217 ( struct V_1 * V_14 ,
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
V_114 , V_441 ? L_129 : L_130 ) ;
return - V_68 ;
}
if ( V_14 -> V_82 != V_83 ) {
F_20 ( & V_14 -> V_22 , L_131
L_132 ,
V_114 , V_441 ? L_129 : L_130 ,
V_439 [ V_82 ] ) ;
return 0 ;
}
if ( V_441 ) {
V_56 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_73 ,
V_267 ,
V_69 ,
0 , NULL , 0 ,
V_206 ) ;
} else {
V_56 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_70 ,
V_267 ,
V_69 ,
0 , NULL , 0 ,
V_206 ) ;
}
if ( V_56 < 0 ) {
F_7 ( & V_14 -> V_22 , L_133 ,
V_441 ? L_134 : L_135 ,
V_439 [ V_82 ] ) ;
return - V_312 ;
}
return 0 ;
}
static int F_218 ( struct V_1 * V_14 ,
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
V_114 ) ;
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
F_219 ( V_444 ) | V_14 -> V_124 ,
V_69 ) ;
if ( V_56 < 0 ) {
F_7 ( & V_14 -> V_22 , L_139
L_140 , V_439 [ V_82 ] ,
V_444 , V_56 ) ;
return - V_312 ;
}
if ( V_82 == V_435 )
V_14 -> V_52 . V_444 = V_444 ;
else
V_14 -> V_53 . V_444 = V_444 ;
return 0 ;
}
static void F_220 ( struct V_197 * V_153 , struct V_1 * V_14 ,
enum V_428 V_82 )
{
int V_444 , V_56 ;
T_4 V_449 = V_14 -> V_17 -> V_21 -> V_50 ;
T_5 V_450 = V_14 -> V_17 -> V_21 -> V_51 ;
if ( ( V_82 == V_435 && V_449 == 0 ) ||
( V_82 == V_437 && V_450 == 0 ) )
return;
V_56 = F_214 ( V_14 , V_82 ) ;
if ( V_56 < 0 ) {
F_7 ( & V_14 -> V_22 , L_141 ,
V_439 [ V_82 ] ) ;
return;
}
V_444 = V_153 -> V_154 -> V_451 ( V_153 , V_14 , V_82 ) ;
if ( V_444 == 0 )
return;
if ( V_444 < 0 ) {
F_7 ( & V_14 -> V_22 , L_142
L_143 , V_439 [ V_82 ] ,
V_444 ) ;
return;
}
if ( F_218 ( V_14 , V_82 , V_444 ) )
V_153 -> V_154 -> V_452 ( V_153 , V_14 , V_82 ) ;
else if ( V_14 -> V_11 )
F_217 ( V_14 , V_82 , true ) ;
}
static int F_221 ( struct V_197 * V_153 , struct V_1 * V_14 ,
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
V_114 ) ;
return - V_68 ;
}
if ( F_218 ( V_14 , V_82 , 0 ) )
return - V_312 ;
F_217 ( V_14 , V_82 , false ) ;
if ( V_153 -> V_154 -> V_452 ( V_153 , V_14 , V_82 ) )
F_7 ( & V_14 -> V_22 , L_145
L_146 ,
V_439 [ V_82 ] ) ;
return 0 ;
}
int F_222 ( struct V_1 * V_14 )
{
struct V_197 * V_153 ;
if ( ! V_14 || ! V_14 -> V_23 ||
V_14 -> V_15 != V_49 ||
! V_14 -> V_24 )
return 0 ;
V_153 = F_55 ( V_14 -> V_170 ) ;
if ( ! V_153 || ! V_153 -> V_154 -> V_452 )
return 0 ;
V_14 -> V_453 ++ ;
if ( ( V_14 -> V_52 . V_444 == 0 && V_14 -> V_53 . V_444 == 0 ) )
return 0 ;
if ( F_221 ( V_153 , V_14 , V_435 ) )
goto V_454;
if ( F_221 ( V_153 , V_14 , V_437 ) )
goto V_454;
return 0 ;
V_454:
F_223 ( V_14 ) ;
return - V_312 ;
}
int F_200 ( struct V_1 * V_14 )
{
struct V_197 * V_153 = F_55 ( V_14 -> V_170 ) ;
int V_56 ;
if ( ! V_153 )
return - V_68 ;
F_27 ( V_153 -> V_455 ) ;
V_56 = F_222 ( V_14 ) ;
F_30 ( V_153 -> V_455 ) ;
return V_56 ;
}
void F_223 ( struct V_1 * V_14 )
{
struct V_197 * V_153 ;
if ( ! V_14 || ! V_14 -> V_23 ||
V_14 -> V_15 != V_49 ||
! V_14 -> V_24 )
return;
V_14 -> V_453 -- ;
V_153 = F_55 ( V_14 -> V_170 ) ;
if ( ! V_153 || ! V_153 -> V_154 -> V_451 ||
! V_153 -> V_154 -> V_452 )
return;
if ( V_14 -> V_453 > 0 )
return;
F_220 ( V_153 , V_14 , V_435 ) ;
F_220 ( V_153 , V_14 , V_437 ) ;
}
void F_201 ( struct V_1 * V_14 )
{
struct V_197 * V_153 = F_55 ( V_14 -> V_170 ) ;
if ( ! V_153 )
return;
F_27 ( V_153 -> V_455 ) ;
F_223 ( V_14 ) ;
F_30 ( V_153 -> V_455 ) ;
}
int F_222 ( struct V_1 * V_14 )
{
return 0 ;
}
void F_223 ( struct V_1 * V_14 ) { }
int F_200 ( struct V_1 * V_14 )
{
return 0 ;
}
void F_201 ( struct V_1 * V_14 ) { }
int F_193 ( struct V_1 * V_14 )
{
return 0 ;
}
void F_195 ( struct V_1 * V_14 ) { }
int F_224 ( struct V_6 * V_7 , int V_71 , bool V_456 )
{
int V_56 ;
int V_181 , V_457 = 0 ;
T_1 V_182 , V_8 ;
unsigned V_458 = 0xffff ;
for ( V_181 = 0 ; ; V_181 += V_184 ) {
V_56 = F_26 ( V_7 , V_71 , & V_8 , & V_182 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( ! ( V_182 & V_215 ) &&
( V_8 & V_213 ) == V_458 ) {
if ( ! V_456 ||
( V_458 == V_213 ) )
V_457 += V_184 ;
if ( V_457 >= V_225 )
break;
} else {
V_457 = 0 ;
V_458 = V_8 & V_213 ;
}
if ( V_182 & V_215 ) {
F_17 ( V_7 -> V_2 , V_71 ,
V_216 ) ;
}
if ( V_181 >= V_186 )
break;
F_59 ( V_184 ) ;
}
F_20 ( V_7 -> V_113 ,
L_147 ,
V_71 , V_181 , V_457 , V_8 ) ;
if ( V_457 < V_225 )
return - V_103 ;
return V_8 ;
}
void F_225 ( struct V_1 * V_14 )
{
F_226 ( V_14 , 0 + V_64 , true ) ;
F_226 ( V_14 , 0 + V_459 , true ) ;
F_227 ( V_14 , & V_14 -> V_330 , true ) ;
}
static int F_228 ( struct V_1 * V_14 , int V_168 )
{
int V_460 ;
struct V_197 * V_153 = F_55 ( V_14 -> V_170 ) ;
if ( ! V_153 -> V_154 -> V_461 && V_168 <= 1 )
return - V_68 ;
if ( V_14 -> V_82 == V_413 )
return 0 ;
if ( V_14 -> V_82 != V_386 )
return - V_68 ;
if ( V_153 -> V_154 -> V_461 )
V_460 = V_153 -> V_154 -> V_461 ( V_153 , V_14 ) ;
else
V_460 = F_13 ( V_14 , F_229 () ,
V_462 , 0 , V_168 , 0 ,
NULL , 0 , V_206 ) ;
if ( V_460 == 0 ) {
F_133 ( V_14 , V_168 ) ;
F_64 ( V_14 , V_413 ) ;
F_225 ( V_14 ) ;
}
return V_460 ;
}
static int
F_230 ( struct V_6 * V_7 , struct V_1 * V_14 , int V_71 ,
int V_463 )
{
static F_231 ( V_464 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_197 * V_153 = F_55 ( V_2 -> V_170 ) ;
int V_55 , V_465 , V_460 ;
unsigned V_174 = V_377 ;
enum V_466 V_467 = V_14 -> V_15 ;
const char * V_15 ;
int V_168 = V_14 -> V_168 ;
if ( ! V_2 -> V_23 ) {
V_174 = V_468 ;
if ( V_71 == V_2 -> V_170 -> V_347 )
V_2 -> V_170 -> V_348 = 0 ;
}
if ( V_467 == V_381 )
V_174 = V_378 ;
F_27 ( & V_464 ) ;
V_460 = F_187 ( V_7 , V_71 , V_14 , V_174 , false ) ;
if ( V_460 < 0 )
goto V_244;
V_460 = - V_112 ;
if ( V_467 != V_469 && V_467 != V_14 -> V_15 ) {
F_20 ( & V_14 -> V_22 , L_148 ) ;
goto V_244;
}
V_467 = V_14 -> V_15 ;
switch ( V_14 -> V_15 ) {
case V_49 :
case V_380 :
V_14 -> V_330 . V_276 . V_470 = F_216 ( 512 ) ;
break;
case V_16 :
V_14 -> V_330 . V_276 . V_470 = F_216 ( 64 ) ;
break;
case V_382 :
V_14 -> V_330 . V_276 . V_470 = F_216 ( 64 ) ;
break;
case V_381 :
V_14 -> V_330 . V_276 . V_470 = F_216 ( 8 ) ;
break;
default:
goto V_244;
}
if ( V_14 -> V_15 == V_380 )
V_15 = L_149 ;
else
V_15 = F_232 ( V_14 -> V_15 ) ;
if ( V_14 -> V_15 != V_49 )
F_84 ( & V_14 -> V_22 ,
L_150 ,
( V_14 -> V_341 ) ? L_151 : L_152 , V_15 ,
V_168 , V_14 -> V_170 -> V_471 -> V_154 -> V_472 ) ;
if ( V_2 -> V_140 ) {
V_14 -> V_140 = V_2 -> V_140 ;
V_14 -> V_167 = V_2 -> V_167 ;
} else if ( V_14 -> V_15 != V_16
&& V_2 -> V_15 == V_16 ) {
if ( ! V_7 -> V_140 . V_7 ) {
F_28 ( & V_14 -> V_22 , L_153 ) ;
V_460 = - V_68 ;
goto V_244;
}
V_14 -> V_140 = & V_7 -> V_140 ;
V_14 -> V_167 = V_71 ;
}
for ( V_55 = 0 ; V_55 < V_473 ; ( ++ V_55 , F_59 ( 100 ) ) ) {
if ( F_233 ( V_463 ) && ! ( V_153 -> V_154 -> V_118 & V_474 ) ) {
struct V_475 * V_476 ;
int V_477 = 0 ;
#define F_234 64
V_476 = F_51 ( F_234 , V_212 ) ;
if ( ! V_476 ) {
V_460 = - V_165 ;
continue;
}
for ( V_465 = 0 ; V_465 < 3 ; ++ V_465 ) {
V_476 -> V_478 = 0 ;
V_477 = F_13 ( V_14 , F_235 () ,
V_63 , V_64 ,
V_479 << 8 , 0 ,
V_476 , F_234 ,
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
V_460 = F_187 ( V_7 , V_71 , V_14 , V_174 , false ) ;
if ( V_460 < 0 )
goto V_244;
if ( V_467 != V_14 -> V_15 ) {
F_20 ( & V_14 -> V_22 ,
L_148 ) ;
V_460 = - V_112 ;
goto V_244;
}
if ( V_477 ) {
if ( V_477 != - V_112 )
F_28 ( & V_14 -> V_22 , L_154 ,
V_477 ) ;
V_460 = - V_483 ;
continue;
}
#undef F_234
}
if ( V_14 -> V_322 == 0 ) {
for ( V_465 = 0 ; V_465 < V_484 ; ++ V_465 ) {
V_460 = F_228 ( V_14 , V_168 ) ;
if ( V_460 >= 0 )
break;
F_59 ( 200 ) ;
}
if ( V_460 < 0 ) {
if ( V_460 != - V_112 )
F_28 ( & V_14 -> V_22 , L_155 ,
V_168 , V_460 ) ;
goto V_244;
}
if ( V_14 -> V_15 == V_49 ) {
V_168 = V_14 -> V_168 ;
F_84 ( & V_14 -> V_22 ,
L_156 ,
( V_14 -> V_341 ) ? L_151 : L_152 ,
V_168 , V_14 -> V_170 -> V_471 -> V_154 -> V_472 ) ;
}
F_59 ( 10 ) ;
if ( F_233 ( V_463 ) && ! ( V_153 -> V_154 -> V_118 & V_474 ) )
break;
}
V_460 = F_180 ( V_14 , 8 ) ;
if ( V_460 < 8 ) {
if ( V_460 != - V_112 )
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
goto V_244;
if ( V_153 -> V_485 && ! V_2 -> V_23 )
F_236 ( V_153 -> V_485 , V_14 -> V_15 ) ;
if ( ( V_14 -> V_15 == V_49 ) &&
( F_29 ( V_14 -> V_3 . V_486 ) < 0x0300 ) ) {
F_28 ( & V_14 -> V_22 , L_158
L_159 ) ;
F_187 ( V_7 , V_71 , V_14 ,
V_487 , true ) ;
V_460 = - V_68 ;
goto V_244;
}
if ( V_14 -> V_3 . V_478 == 0xff ||
V_14 -> V_15 == V_49 )
V_55 = 512 ;
else
V_55 = V_14 -> V_3 . V_478 ;
if ( F_237 ( & V_14 -> V_330 . V_276 ) != V_55 ) {
if ( V_14 -> V_15 == V_381 ||
! ( V_55 == 8 || V_55 == 16 || V_55 == 32 || V_55 == 64 ) ) {
F_28 ( & V_14 -> V_22 , L_160 , V_55 ) ;
V_460 = - V_483 ;
goto V_244;
}
if ( V_14 -> V_15 == V_382 )
F_20 ( & V_14 -> V_22 , L_161 , V_55 ) ;
else
F_7 ( & V_14 -> V_22 , L_162 , V_55 ) ;
V_14 -> V_330 . V_276 . V_470 = F_216 ( V_55 ) ;
F_225 ( V_14 ) ;
}
V_460 = F_180 ( V_14 , V_488 ) ;
if ( V_460 < ( signed ) sizeof( V_14 -> V_3 ) ) {
if ( V_460 != - V_112 )
F_28 ( & V_14 -> V_22 , L_163 ,
V_460 ) ;
if ( V_460 >= 0 )
V_460 = - V_489 ;
goto V_244;
}
if ( V_14 -> V_322 == 0 && F_29 ( V_14 -> V_3 . V_486 ) >= 0x0201 ) {
V_460 = F_238 ( V_14 ) ;
if ( ! V_460 ) {
V_14 -> V_24 = F_5 ( V_14 ) ;
F_11 ( V_14 ) ;
}
}
V_460 = 0 ;
if ( V_153 -> V_154 -> V_490 )
V_153 -> V_154 -> V_490 ( V_153 , V_14 ) ;
V_244:
if ( V_460 ) {
F_63 ( V_7 , V_71 , 0 ) ;
F_133 ( V_14 , V_168 ) ;
}
F_30 ( & V_464 ) ;
return V_460 ;
}
static void
F_239 ( struct V_6 * V_7 , struct V_1 * V_14 , int V_71 )
{
struct V_491 * V_492 ;
int V_75 ;
V_492 = F_51 ( sizeof *V_492 , V_243 ) ;
if ( V_492 == NULL )
return;
V_75 = F_240 ( V_14 , V_493 , 0 ,
V_492 , sizeof *V_492 ) ;
if ( V_75 == sizeof *V_492 ) {
F_84 ( & V_14 -> V_22 , L_164
L_165 ) ;
if ( V_7 -> V_227 ) {
V_7 -> V_87 [ V_71 - 1 ] = V_91 ;
F_23 ( & V_7 -> V_79 , 0 ) ;
}
}
F_48 ( V_492 ) ;
}
static unsigned
F_241 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_274 ;
int V_71 ;
if ( ! V_7 -> V_272 )
return 0 ;
V_274 = V_2 -> V_270 - V_7 -> V_3 -> V_275 ;
for ( V_71 = 1 ; V_71 <= V_2 -> V_12 ; ++ V_71 ) {
struct V_1 * V_14 = V_7 -> V_160 [ V_71 - 1 ] -> V_189 ;
int V_494 ;
unsigned V_241 ;
if ( ! V_14 )
continue;
if ( F_1 ( V_14 ) )
V_241 = 150 ;
else
V_241 = 100 ;
if ( V_14 -> V_11 )
V_494 = F_242 ( V_14 , V_14 -> V_11 ) ;
else if ( V_71 != V_14 -> V_170 -> V_347 || V_2 -> V_23 )
V_494 = V_241 ;
else
V_494 = 8 ;
if ( V_494 > V_7 -> V_271 )
F_7 ( & V_14 -> V_22 ,
L_166 ,
V_494 , V_7 -> V_271 , V_71 ) ;
V_274 -= V_494 ;
}
if ( V_274 < 0 ) {
F_7 ( V_7 -> V_113 , L_167 ,
- V_274 ) ;
V_274 = 0 ;
}
return V_274 ;
}
static void F_243 ( struct V_6 * V_7 , int V_71 ,
T_1 V_8 , T_1 V_182 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_235 * V_236 = V_7 -> V_113 ;
struct V_197 * V_153 = F_55 ( V_2 -> V_170 ) ;
unsigned V_175 =
F_29 ( V_7 -> V_3 -> V_175 ) ;
struct V_1 * V_14 ;
int V_75 , V_55 ;
unsigned V_241 ;
F_20 ( V_236 ,
L_168 ,
V_71 , V_8 , V_182 , F_2 ( V_7 , V_8 ) ) ;
if ( V_7 -> V_227 ) {
F_19 ( V_7 , V_71 , V_89 ) ;
V_7 -> V_87 [ V_71 - 1 ] = V_90 ;
}
#ifdef F_147
if ( V_2 -> V_170 -> V_340 )
V_182 &= ~ ( V_215 |
V_217 ) ;
#endif
V_14 = V_7 -> V_160 [ V_71 - 1 ] -> V_189 ;
if ( ( V_8 & V_213 ) && V_14 &&
V_14 -> V_82 != V_190 ) {
F_135 ( V_14 ) ;
if ( V_8 & V_214 ) {
V_75 = 0 ;
#ifdef F_244
} else if ( V_14 -> V_82 == V_314 &&
V_14 -> V_223 ) {
V_75 = F_207 ( V_14 ) ;
#endif
} else {
V_75 = - V_112 ;
}
F_141 ( V_14 ) ;
if ( V_75 == 0 ) {
F_72 ( V_71 , V_7 -> V_192 ) ;
return;
}
}
if ( V_14 ) {
if ( V_153 -> V_485 && ! V_2 -> V_23 &&
! ( V_8 & V_213 ) )
F_245 ( V_153 -> V_485 , V_14 -> V_15 ) ;
F_77 ( & V_7 -> V_160 [ V_71 - 1 ] -> V_189 ) ;
}
F_72 ( V_71 , V_7 -> V_192 ) ;
if ( ! ( V_8 & V_213 ) ||
( V_182 & V_215 ) )
F_72 ( V_71 , V_7 -> V_195 ) ;
if ( V_182 & ( V_215 |
V_217 ) ) {
V_75 = F_246 ( V_7 , V_71 ) ;
if ( V_75 < 0 ) {
if ( V_75 != - V_112 && F_247 () )
F_28 ( V_236 , L_169
L_170 , V_71 ) ;
V_8 &= ~ V_213 ;
} else {
V_8 = V_75 ;
}
}
if ( ! ( V_8 & V_213 ) ||
F_130 ( V_71 , V_7 -> V_195 ) ) {
if ( ( V_175 & V_176 ) < 2
&& ! F_190 ( V_7 , V_8 ) )
F_18 ( V_2 , V_71 , V_161 ) ;
if ( V_8 & V_214 )
goto V_388;
return;
}
if ( F_1 ( V_7 -> V_2 ) )
V_241 = 150 ;
else
V_241 = 100 ;
V_75 = 0 ;
for ( V_55 = 0 ; V_55 < V_495 ; V_55 ++ ) {
V_14 = F_248 ( V_2 , V_2 -> V_170 , V_71 ) ;
if ( ! V_14 ) {
F_28 ( V_236 ,
L_171 ,
V_71 ) ;
goto V_388;
}
F_64 ( V_14 , V_496 ) ;
V_14 -> V_270 = V_7 -> V_271 ;
V_14 -> V_205 = V_2 -> V_205 + 1 ;
V_14 -> V_322 = F_183 ( V_7 ) ;
if ( F_1 ( V_7 -> V_2 ) )
V_14 -> V_15 = V_49 ;
else
V_14 -> V_15 = V_469 ;
F_128 ( V_14 ) ;
if ( V_14 -> V_168 <= 0 ) {
V_75 = - V_379 ;
goto V_497;
}
V_75 = F_230 ( V_7 , V_14 , V_71 , V_55 ) ;
if ( V_75 < 0 )
goto V_497;
F_249 ( V_14 ) ;
if ( V_14 -> V_498 & V_499 )
F_59 ( 1000 ) ;
if ( V_14 -> V_3 . V_500 == V_501
&& V_14 -> V_270 <= V_241 ) {
T_1 V_502 ;
V_75 = F_90 ( V_14 , V_267 , 0 ,
& V_502 ) ;
if ( V_75 < 2 ) {
F_20 ( & V_14 -> V_22 , L_172 , V_75 ) ;
goto V_503;
}
F_91 ( & V_502 ) ;
if ( ( V_502 & ( 1 << V_273 ) ) == 0 ) {
F_28 ( & V_14 -> V_22 ,
L_173
L_174 ) ;
if ( V_7 -> V_227 ) {
V_7 -> V_87 [ V_71 - 1 ] =
V_95 ;
F_23 ( & V_7 -> V_79 , 0 ) ;
}
V_75 = - V_379 ;
goto V_503;
}
}
if ( F_29 ( V_14 -> V_3 . V_486 ) >= 0x0200
&& V_14 -> V_15 == V_382
&& V_284 != 0 )
F_239 ( V_7 , V_14 , V_71 ) ;
V_75 = 0 ;
F_103 ( & V_303 ) ;
if ( V_2 -> V_82 == V_190 )
V_75 = - V_379 ;
else
V_7 -> V_160 [ V_71 - 1 ] -> V_189 = V_14 ;
F_106 ( & V_303 ) ;
if ( ! V_75 ) {
V_75 = F_157 ( V_14 ) ;
if ( V_75 ) {
F_103 ( & V_303 ) ;
V_7 -> V_160 [ V_71 - 1 ] -> V_189 = NULL ;
F_106 ( & V_303 ) ;
}
}
if ( V_75 )
goto V_503;
V_75 = F_241 ( V_7 ) ;
if ( V_75 )
F_20 ( V_236 , L_175 , V_75 ) ;
return;
V_503:
F_63 ( V_7 , V_71 , 1 ) ;
V_497:
F_225 ( V_14 ) ;
F_132 ( V_14 ) ;
F_134 ( V_14 ) ;
F_250 ( V_14 ) ;
if ( ( V_75 == - V_379 ) || ( V_75 == - V_352 ) )
break;
}
if ( V_7 -> V_2 -> V_23 ||
! V_153 -> V_154 -> V_504 ||
! ( V_153 -> V_154 -> V_504 ) ( V_153 , V_71 ) ) {
if ( V_75 != - V_379 && V_75 != - V_112 )
F_28 ( V_236 , L_176 ,
V_71 ) ;
}
V_388:
F_63 ( V_7 , V_71 , 1 ) ;
if ( V_153 -> V_154 -> V_505 && ! V_7 -> V_2 -> V_23 )
V_153 -> V_154 -> V_505 ( V_153 , V_71 ) ;
}
static int F_251 ( struct V_6 * V_7 , unsigned int V_111 ,
T_1 V_8 , T_1 V_182 )
{
struct V_1 * V_2 ;
struct V_1 * V_14 ;
int V_506 = 0 ;
int V_56 ;
V_2 = V_7 -> V_2 ;
V_14 = V_7 -> V_160 [ V_111 - 1 ] -> V_189 ;
if ( ! F_1 ( V_2 ) ) {
if ( ! ( V_182 & V_420 ) )
return 0 ;
F_17 ( V_2 , V_111 , V_421 ) ;
} else {
if ( ! V_14 || V_14 -> V_82 != V_314 ||
( V_8 & V_185 ) !=
V_222 )
return 0 ;
}
if ( V_14 ) {
F_59 ( 10 ) ;
F_135 ( V_14 ) ;
V_56 = F_207 ( V_14 ) ;
F_141 ( V_14 ) ;
if ( V_56 < 0 )
V_506 = 1 ;
} else {
V_56 = - V_112 ;
F_63 ( V_7 , V_111 , 1 ) ;
}
F_20 ( V_7 -> V_113 , L_177 ,
V_111 , V_56 ) ;
return V_506 ;
}
static void F_252 ( void )
{
struct V_147 * V_507 ;
struct V_1 * V_2 ;
struct V_193 * V_194 ;
struct V_6 * V_7 ;
struct V_235 * V_236 ;
T_1 V_237 ;
T_1 V_238 ;
T_1 V_8 ;
T_1 V_182 ;
int V_55 , V_56 ;
int V_506 , V_508 ;
while ( 1 ) {
F_103 ( & V_119 ) ;
if ( F_33 ( & V_122 ) ) {
F_106 ( & V_119 ) ;
break;
}
V_507 = V_122 . V_148 ;
F_104 ( V_507 ) ;
V_7 = F_46 ( V_507 , struct V_6 , V_121 ) ;
F_253 ( & V_7 -> V_282 ) ;
F_106 ( & V_119 ) ;
V_2 = V_7 -> V_2 ;
V_236 = V_7 -> V_113 ;
V_194 = F_36 ( V_236 ) ;
F_20 ( V_236 , L_178 ,
V_2 -> V_82 , V_7 -> V_3
? V_7 -> V_3 -> V_85
: 0 ,
( T_1 ) V_7 -> V_192 [ 0 ] ,
( T_1 ) V_7 -> V_136 [ 0 ] ) ;
F_135 ( V_2 ) ;
if ( F_254 ( V_7 -> V_120 ) )
goto V_509;
if ( V_2 -> V_82 == V_190 ) {
V_7 -> error = - V_112 ;
F_75 ( V_7 , V_283 ) ;
goto V_497;
}
V_56 = F_67 ( V_194 ) ;
if ( V_56 ) {
F_20 ( V_236 , L_179 , V_56 ) ;
goto V_497;
}
if ( V_7 -> V_84 )
goto V_510;
if ( V_7 -> error ) {
F_20 ( V_236 , L_180 ,
V_7 -> error ) ;
V_56 = F_255 ( V_2 ) ;
if ( V_56 ) {
F_20 ( V_236 ,
L_181 , V_56 ) ;
goto V_510;
}
V_7 -> V_132 = 0 ;
V_7 -> error = 0 ;
}
for ( V_55 = 1 ; V_55 <= V_7 -> V_3 -> V_85 ; V_55 ++ ) {
if ( F_130 ( V_55 , V_7 -> V_418 ) )
continue;
V_506 = F_130 ( V_55 , V_7 -> V_192 ) ;
V_508 = F_256 ( V_55 , V_7 -> V_125 ) ;
if ( ! F_256 ( V_55 , V_7 -> V_136 ) &&
! V_506 && ! V_508 )
continue;
V_56 = F_26 ( V_7 , V_55 ,
& V_8 , & V_182 ) ;
if ( V_56 < 0 )
continue;
if ( V_182 & V_215 ) {
F_17 ( V_2 , V_55 ,
V_216 ) ;
V_506 = 1 ;
}
if ( V_182 & V_217 ) {
if ( ! V_506 )
F_20 ( V_236 ,
L_182
L_183 ,
V_55 , V_8 ) ;
F_17 ( V_2 , V_55 ,
V_218 ) ;
if ( ! ( V_8 & V_214 )
&& ! V_506
&& V_7 -> V_160 [ V_55 - 1 ] -> V_189 ) {
F_28 ( V_236 ,
L_184
L_185
L_186 ,
V_55 ) ;
V_506 = 1 ;
}
}
if ( F_251 ( V_7 , V_55 ,
V_8 , V_182 ) )
V_506 = 1 ;
if ( V_182 & V_511 ) {
T_1 V_75 = 0 ;
T_1 V_512 ;
F_20 ( V_236 , L_187
L_188 , V_55 ) ;
F_17 ( V_2 , V_55 ,
V_513 ) ;
F_59 ( 100 ) ;
F_57 ( V_7 , true ) ;
F_26 ( V_7 , V_55 , & V_75 , & V_512 ) ;
if ( V_75 & V_514 )
F_28 ( V_236 , L_189
L_190 , V_55 ) ;
}
if ( V_182 & V_515 ) {
F_20 ( V_236 ,
L_191 ,
V_55 ) ;
F_17 ( V_2 , V_55 ,
V_384 ) ;
}
if ( ( V_182 & V_219 ) &&
F_1 ( V_7 -> V_2 ) ) {
F_20 ( V_236 ,
L_192 ,
V_55 ) ;
F_17 ( V_2 , V_55 ,
V_220 ) ;
}
if ( V_182 & V_419 ) {
F_17 ( V_7 -> V_2 , V_55 ,
V_385 ) ;
}
if ( V_182 & V_516 ) {
F_7 ( V_236 ,
L_193 ,
V_55 ) ;
F_17 ( V_7 -> V_2 , V_55 ,
V_517 ) ;
}
if ( F_184 ( V_7 , V_8 ) ) {
int V_75 ;
struct V_1 * V_14 =
V_7 -> V_160 [ V_55 - 1 ] -> V_189 ;
F_20 ( V_236 , L_194 , V_55 ) ;
if ( ! V_14 || ! ( V_8 &
V_213 ) ) {
V_75 = F_187 ( V_7 , V_55 ,
NULL , V_487 ,
true ) ;
if ( V_75 < 0 )
F_63 ( V_7 , V_55 , 1 ) ;
} else {
F_135 ( V_14 ) ;
V_75 = F_255 ( V_14 ) ;
F_141 ( V_14 ) ;
V_506 = 0 ;
}
}
if ( V_506 )
F_243 ( V_7 , V_55 ,
V_8 , V_182 ) ;
}
if ( F_256 ( 0 , V_7 -> V_136 ) == 0 )
;
else if ( F_60 ( V_7 , & V_237 , & V_238 ) < 0 )
F_28 ( V_236 , L_195 ) ;
else {
if ( V_238 & V_518 ) {
F_20 ( V_236 , L_196 ) ;
F_15 ( V_2 , V_519 ) ;
if ( V_237 & V_278 )
V_7 -> V_272 = 1 ;
else
V_7 -> V_272 = 0 ;
}
if ( V_238 & V_520 ) {
T_1 V_75 = 0 ;
T_1 V_512 ;
F_20 ( V_236 , L_197 ) ;
F_15 ( V_2 , V_521 ) ;
F_59 ( 500 ) ;
F_57 ( V_7 , true ) ;
F_60 ( V_7 , & V_75 , & V_512 ) ;
if ( V_75 & V_279 )
F_28 ( V_236 , L_189
L_198 ) ;
}
}
V_510:
F_105 ( V_194 ) ;
V_497:
F_68 ( V_194 ) ;
V_509:
F_141 ( V_2 ) ;
F_111 ( & V_7 -> V_282 , F_99 ) ;
}
}
static int F_257 ( void * V_522 )
{
F_258 () ;
do {
F_252 () ;
F_259 ( V_123 ,
! F_33 ( & V_122 ) ||
F_260 () ) ;
} while ( ! F_260 () || ! F_33 ( & V_122 ) );
F_261 ( L_199 , V_523 ) ;
return 0 ;
}
int F_262 ( void )
{
if ( F_263 ( & V_524 ) < 0 ) {
F_264 ( V_525 L_200 ,
V_523 ) ;
return - 1 ;
}
V_526 = F_265 ( F_257 , NULL , L_201 ) ;
if ( ! F_266 ( V_526 ) )
return 0 ;
F_267 ( & V_524 ) ;
F_264 ( V_525 L_202 , V_523 ) ;
return - 1 ;
}
void F_268 ( void )
{
F_269 ( V_526 ) ;
F_267 ( & V_524 ) ;
}
static int F_270 ( struct V_1 * V_14 ,
struct V_475 * V_527 )
{
int V_80 = 0 ;
unsigned V_528 ;
unsigned V_529 = 0 ;
unsigned V_530 ;
unsigned V_531 ;
int V_532 ;
char * V_476 ;
if ( memcmp ( & V_14 -> V_3 , V_527 ,
sizeof( * V_527 ) ) != 0 )
return 1 ;
if ( V_14 -> V_338 )
V_529 = strlen ( V_14 -> V_338 ) + 1 ;
V_530 = V_529 ;
for ( V_528 = 0 ; V_528 < V_14 -> V_3 . V_362 ; V_528 ++ ) {
V_531 = F_29 ( V_14 -> V_341 [ V_528 ] . V_276 . V_344 ) ;
V_530 = F_58 ( V_530 , V_531 ) ;
}
V_476 = F_51 ( V_530 , V_212 ) ;
if ( V_476 == NULL ) {
F_28 ( & V_14 -> V_22 , L_203 ) ;
return 1 ;
}
for ( V_528 = 0 ; V_528 < V_14 -> V_3 . V_362 ; V_528 ++ ) {
V_531 = F_29 ( V_14 -> V_341 [ V_528 ] . V_276 . V_344 ) ;
V_532 = F_240 ( V_14 , V_533 , V_528 , V_476 ,
V_531 ) ;
if ( V_532 != V_531 ) {
F_20 ( & V_14 -> V_22 , L_204 ,
V_528 , V_532 ) ;
V_80 = 1 ;
break;
}
if ( memcmp ( V_476 , V_14 -> V_343 [ V_528 ] , V_531 )
!= 0 ) {
F_20 ( & V_14 -> V_22 , L_205 ,
V_528 ,
( (struct V_534 * ) V_476 ) ->
V_535 ) ;
V_80 = 1 ;
break;
}
}
if ( ! V_80 && V_529 ) {
V_532 = F_271 ( V_14 , V_14 -> V_3 . V_335 ,
V_476 , V_529 ) ;
if ( V_532 + 1 != V_529 ) {
F_20 ( & V_14 -> V_22 , L_206 ,
V_532 ) ;
V_80 = 1 ;
} else if ( memcmp ( V_476 , V_14 -> V_338 , V_532 ) != 0 ) {
F_20 ( & V_14 -> V_22 , L_207 ) ;
V_80 = 1 ;
}
}
F_48 ( V_476 ) ;
return V_80 ;
}
static int F_205 ( struct V_1 * V_14 )
{
struct V_1 * V_536 = V_14 -> V_23 ;
struct V_6 * V_537 ;
struct V_197 * V_153 = F_55 ( V_14 -> V_170 ) ;
struct V_475 V_3 = V_14 -> V_3 ;
int V_55 , V_56 = 0 ;
int V_71 = V_14 -> V_124 ;
if ( V_14 -> V_82 == V_190 ||
V_14 -> V_82 == V_314 ) {
F_20 ( & V_14 -> V_22 , L_208 ,
V_14 -> V_82 ) ;
return - V_68 ;
}
if ( ! V_536 ) {
F_20 ( & V_14 -> V_22 , L_209 , V_114 ) ;
return - V_538 ;
}
V_537 = F_3 ( V_536 ) ;
V_56 = F_200 ( V_14 ) ;
if ( V_56 ) {
F_28 ( & V_14 -> V_22 , L_210 , V_114 ) ;
goto V_539;
}
V_56 = F_193 ( V_14 ) ;
if ( V_56 ) {
F_28 ( & V_14 -> V_22 , L_211 ,
V_114 ) ;
goto V_539;
}
F_41 ( V_71 , V_537 -> V_418 ) ;
for ( V_55 = 0 ; V_55 < V_495 ; ++ V_55 ) {
F_225 ( V_14 ) ;
V_56 = F_230 ( V_537 , V_14 , V_71 , V_55 ) ;
if ( V_56 >= 0 || V_56 == - V_379 || V_56 == - V_112 )
break;
}
F_72 ( V_71 , V_537 -> V_418 ) ;
if ( V_56 < 0 )
goto V_539;
if ( F_270 ( V_14 , & V_3 ) ) {
F_84 ( & V_14 -> V_22 , L_212 ) ;
V_14 -> V_3 = V_3 ;
goto V_539;
}
if ( ! V_14 -> V_11 )
goto V_388;
F_27 ( V_153 -> V_455 ) ;
V_56 = F_272 ( V_14 , V_14 -> V_11 , NULL , NULL ) ;
if ( V_56 < 0 ) {
F_7 ( & V_14 -> V_22 ,
L_213
L_214 ) ;
F_30 ( V_153 -> V_455 ) ;
goto V_539;
}
V_56 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_540 , 0 ,
V_14 -> V_11 -> V_276 . V_535 , 0 ,
NULL , 0 , V_206 ) ;
if ( V_56 < 0 ) {
F_28 ( & V_14 -> V_22 ,
L_215 ,
V_14 -> V_11 -> V_276 . V_535 , V_56 ) ;
F_30 ( V_153 -> V_455 ) ;
goto V_539;
}
F_30 ( V_153 -> V_455 ) ;
F_64 ( V_14 , V_83 ) ;
for ( V_55 = 0 ; V_55 < V_14 -> V_11 -> V_276 . V_541 ; V_55 ++ ) {
struct V_542 * V_341 = V_14 -> V_11 ;
struct V_193 * V_194 = V_341 -> V_13 [ V_55 ] ;
struct V_543 * V_276 ;
V_276 = & V_194 -> V_288 -> V_276 ;
if ( V_276 -> V_544 == 0 ) {
F_273 ( V_14 , V_194 , true ) ;
F_274 ( V_14 , V_194 , true ) ;
V_56 = 0 ;
} else {
V_194 -> V_545 = 1 ;
V_56 = F_89 ( V_14 , V_276 -> V_546 ,
V_276 -> V_544 ) ;
V_194 -> V_545 = 0 ;
}
if ( V_56 < 0 ) {
F_28 ( & V_14 -> V_22 , L_216
L_217 ,
V_276 -> V_546 ,
V_276 -> V_544 ,
V_56 ) ;
goto V_539;
}
}
V_388:
F_201 ( V_14 ) ;
F_195 ( V_14 ) ;
return 0 ;
V_539:
F_65 ( V_537 , V_71 ) ;
return - V_112 ;
}
int F_255 ( struct V_1 * V_14 )
{
int V_56 ;
int V_55 ;
unsigned int V_547 ;
struct V_542 * V_341 = V_14 -> V_11 ;
if ( V_14 -> V_82 == V_190 ||
V_14 -> V_82 == V_314 ) {
F_20 ( & V_14 -> V_22 , L_208 ,
V_14 -> V_82 ) ;
return - V_68 ;
}
V_547 = F_275 () ;
F_179 ( V_14 ) ;
if ( V_341 ) {
for ( V_55 = 0 ; V_55 < V_341 -> V_276 . V_541 ; ++ V_55 ) {
struct V_193 * V_548 = V_341 -> V_13 [ V_55 ] ;
struct V_549 * V_152 ;
int V_550 = 0 ;
if ( V_548 -> V_22 . V_154 ) {
V_152 = F_276 ( V_548 -> V_22 . V_154 ) ;
if ( V_152 -> V_551 && V_152 -> V_552 )
V_550 = ( V_152 -> V_551 ) ( V_548 ) ;
else if ( V_548 -> V_553 ==
V_554 )
V_550 = 1 ;
if ( V_550 )
F_277 ( V_548 ) ;
}
}
}
V_56 = F_205 ( V_14 ) ;
if ( V_341 ) {
for ( V_55 = V_341 -> V_276 . V_541 - 1 ; V_55 >= 0 ; -- V_55 ) {
struct V_193 * V_548 = V_341 -> V_13 [ V_55 ] ;
struct V_549 * V_152 ;
int V_555 = V_548 -> V_556 ;
if ( ! V_555 && V_548 -> V_22 . V_154 ) {
V_152 = F_276 ( V_548 -> V_22 . V_154 ) ;
if ( V_152 -> V_552 )
V_555 = ( V_152 -> V_552 ) ( V_548 ) ;
else if ( V_548 -> V_553 ==
V_554 )
V_555 = 1 ;
}
if ( V_56 == 0 && V_555 )
F_278 ( V_548 ) ;
}
}
F_182 ( V_14 ) ;
F_279 ( V_547 ) ;
return V_56 ;
}
void F_280 ( struct V_193 * V_557 )
{
F_56 ( & V_557 -> V_558 ) ;
}
struct V_1 * F_281 ( struct V_1 * V_2 ,
int V_71 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_71 < 1 || V_71 > V_2 -> V_12 )
return NULL ;
return V_7 -> V_160 [ V_71 - 1 ] -> V_189 ;
}
void F_282 ( struct V_1 * V_2 , int V_71 ,
enum V_559 type )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_7 )
V_7 -> V_160 [ V_71 - 1 ] -> V_560 = type ;
}
enum V_559
F_283 ( struct V_1 * V_2 , int V_71 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( ! V_7 )
return V_561 ;
return V_7 -> V_160 [ V_71 - 1 ] -> V_560 ;
}
void F_98 ( struct V_1 * V_2 ,
struct V_62 * V_276 )
{
enum V_559 V_560 ;
int V_55 ;
if ( ! F_1 ( V_2 ) ) {
for ( V_55 = 1 ; V_55 <= V_2 -> V_12 ; V_55 ++ ) {
V_560 = F_283 ( V_2 , V_55 ) ;
if ( V_560 == V_562 ) {
T_2 V_563 = 1 << ( V_55 % 8 ) ;
if ( ! ( V_276 -> V_34 . V_248 . V_249 [ V_55 / 8 ] & V_563 ) ) {
F_20 ( & V_2 -> V_22 , L_218 ,
V_55 ) ;
V_276 -> V_34 . V_248 . V_249 [ V_55 / 8 ] |= V_563 ;
}
}
}
} else {
T_1 V_564 = F_29 ( V_276 -> V_34 . V_35 . V_249 ) ;
for ( V_55 = 1 ; V_55 <= V_2 -> V_12 ; V_55 ++ ) {
V_560 = F_283 ( V_2 , V_55 ) ;
if ( V_560 == V_562 ) {
T_1 V_563 = 1 << V_55 ;
if ( ! ( V_564 & V_563 ) ) {
F_20 ( & V_2 -> V_22 , L_218 ,
V_55 ) ;
V_564 |= V_563 ;
}
}
}
V_276 -> V_34 . V_35 . V_249 = F_216 ( V_564 ) ;
}
}
T_6 F_284 ( struct V_1 * V_2 ,
int V_71 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( ! V_7 )
return NULL ;
return F_285 ( & V_7 -> V_160 [ V_71 - 1 ] -> V_22 ) ;
}
