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
F_7 ( & V_14 -> V_22 , L_5 ) ;
return 0 ;
}
if ( V_14 -> V_17 -> V_21 -> V_23 == 0 &&
V_14 -> V_17 -> V_21 -> V_24 == 0 ) {
if ( V_14 -> V_25 )
F_7 ( & V_14 -> V_22 , L_6 ) ;
else
F_7 ( & V_14 -> V_22 , L_7 ) ;
return 0 ;
}
if ( ! V_14 -> V_25 || V_14 -> V_25 -> V_26 )
return 1 ;
return 0 ;
}
static void F_8 ( struct V_1 * V_14 ,
struct V_27 * V_28 ,
unsigned int V_29 ,
struct V_6 * V_7 ,
struct V_27 * V_30 ,
unsigned int V_31 )
{
unsigned int V_32 ;
unsigned int V_33 ;
unsigned int V_34 ;
V_32 = V_30 -> V_35 +
( V_7 -> V_3 -> V_36 . V_37 . V_38 * 100 ) ;
V_33 = V_29 * 1000 ;
V_34 = V_31 * 1000 ;
if ( V_33 > V_34 )
V_32 += V_33 ;
else
V_32 += V_34 ;
V_28 -> V_35 = V_32 ;
}
static void F_9 ( struct V_1 * V_14 ,
struct V_27 * V_28 ,
unsigned int V_29 ,
struct V_6 * V_7 ,
struct V_27 * V_30 ,
unsigned int V_31 ,
unsigned int V_39 )
{
unsigned int V_40 ;
unsigned int V_41 ;
if ( V_29 > V_31 )
V_40 = V_29 * 1000 ;
else
V_40 = V_31 * 1000 ;
V_41 = V_39 * 1000 + V_30 -> V_42 ;
if ( V_40 > V_41 )
V_28 -> V_42 = V_40 ;
else
V_28 -> V_42 = V_41 ;
}
static void F_10 ( struct V_1 * V_14 ,
struct V_27 * V_28 )
{
struct V_1 * V_25 ;
unsigned int V_43 ;
unsigned int V_44 ;
V_44 = V_28 -> V_42 ;
for ( V_25 = V_14 -> V_25 , V_43 = 0 ; V_25 -> V_25 ;
V_25 = V_25 -> V_25 )
V_43 ++ ;
if ( V_43 > 0 )
V_44 += 2100 + 250 * ( V_43 - 1 ) ;
V_44 += 250 * V_43 ;
V_28 -> V_45 = V_44 ;
}
static void F_11 ( struct V_1 * V_14 )
{
struct V_6 * V_7 ;
unsigned int V_46 ;
unsigned int V_47 ;
unsigned int V_48 ;
unsigned int V_49 ;
unsigned int V_50 ;
if ( ! V_14 -> V_26 || V_14 -> V_15 != V_51 )
return;
V_7 = F_3 ( V_14 -> V_25 ) ;
if ( ! V_7 )
return;
V_47 = V_14 -> V_17 -> V_21 -> V_23 ;
V_48 = F_12 ( V_14 -> V_17 -> V_21 -> V_24 ) ;
V_49 = V_14 -> V_25 -> V_17 -> V_21 -> V_23 ;
V_50 = F_12 ( V_14 -> V_25 -> V_17 -> V_21 -> V_24 ) ;
F_8 ( V_14 , & V_14 -> V_52 , V_47 ,
V_7 , & V_14 -> V_25 -> V_52 , V_49 ) ;
F_8 ( V_14 , & V_14 -> V_53 , V_48 ,
V_7 , & V_14 -> V_25 -> V_53 , V_50 ) ;
V_46 = 1 ;
F_9 ( V_14 , & V_14 -> V_52 , V_47 ,
V_7 , & V_14 -> V_25 -> V_52 , V_49 ,
V_46 ) ;
if ( V_50 > V_49 )
V_46 = 1 + V_50 - V_49 ;
else
V_46 = 1 + V_49 ;
F_9 ( V_14 , & V_14 -> V_53 , V_48 ,
V_7 , & V_14 -> V_25 -> V_53 , V_50 ,
V_46 ) ;
F_10 ( V_14 , & V_14 -> V_52 ) ;
F_10 ( V_14 , & V_14 -> V_53 ) ;
}
static int F_13 ( struct V_1 * V_2 , void * V_54 )
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
V_56 = F_14 ( V_2 , F_15 ( V_2 , 0 ) ,
V_63 , V_64 | V_65 ,
V_58 << 8 , 0 , V_54 , V_57 ,
V_66 ) ;
if ( V_56 >= ( V_67 + 2 ) )
return V_56 ;
}
return - V_68 ;
}
static int F_16 ( struct V_1 * V_2 , int V_69 )
{
return F_14 ( V_2 , F_17 ( V_2 , 0 ) ,
V_70 , V_65 , V_69 , 0 , NULL , 0 , 1000 ) ;
}
int F_18 ( struct V_1 * V_2 , int V_71 , int V_69 )
{
return F_14 ( V_2 , F_17 ( V_2 , 0 ) ,
V_70 , V_72 , V_69 , V_71 ,
NULL , 0 , 1000 ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_71 , int V_69 )
{
return F_14 ( V_2 , F_17 ( V_2 , 0 ) ,
V_73 , V_72 , V_69 , V_71 ,
NULL , 0 , 1000 ) ;
}
static void F_20 (
struct V_6 * V_7 ,
int V_71 ,
int V_74
)
{
int V_75 = F_19 ( V_7 -> V_2 , ( V_74 << 8 ) | V_71 ,
V_76 ) ;
if ( V_75 < 0 )
F_21 (hub->intfdev,
L_8 ,
port1,
({ char *s; switch (selector) {
case HUB_LED_AMBER: s = L_9; break;
case HUB_LED_GREEN: s = L_10; break;
case HUB_LED_OFF: s = L_11; break;
case HUB_LED_AUTO: s = L_12; break;
default: s = L_13; break;
} s; }),
status) ;
}
static void F_22 ( struct V_77 * V_78 )
{
struct V_6 * V_7 =
F_23 ( V_78 , struct V_6 , V_79 . V_78 ) ;
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
F_20 ( V_7 , V_55 + 1 , V_74 ) ;
V_7 -> V_86 [ V_55 ] = V_85 ;
}
if ( ! V_80 && V_99 ) {
V_81 ++ ;
V_81 %= V_2 -> V_12 ;
F_20 ( V_7 , V_81 + 1 , V_91 ) ;
V_7 -> V_86 [ V_81 ] = V_87 ;
V_80 ++ ;
}
if ( V_80 )
F_24 ( V_100 ,
& V_7 -> V_79 , V_101 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_102 * V_54 )
{
int V_55 , V_75 = - V_103 ;
for ( V_55 = 0 ; V_55 < V_104 &&
( V_75 == - V_103 || V_75 == - V_105 ) ; V_55 ++ ) {
V_75 = F_14 ( V_2 , F_15 ( V_2 , 0 ) ,
V_106 , V_64 | V_65 , 0 , 0 ,
V_54 , sizeof( * V_54 ) , V_107 ) ;
}
return V_75 ;
}
static int F_26 ( struct V_1 * V_2 , int V_71 ,
struct V_108 * V_54 )
{
int V_55 , V_75 = - V_103 ;
for ( V_55 = 0 ; V_55 < V_104 &&
( V_75 == - V_103 || V_75 == - V_105 ) ; V_55 ++ ) {
V_75 = F_14 ( V_2 , F_15 ( V_2 , 0 ) ,
V_106 , V_64 | V_72 , 0 , V_71 ,
V_54 , sizeof( * V_54 ) , V_107 ) ;
}
return V_75 ;
}
static int F_27 ( struct V_6 * V_7 , int V_71 ,
T_1 * V_75 , T_1 * V_109 )
{
int V_56 ;
F_28 ( & V_7 -> V_110 ) ;
V_56 = F_26 ( V_7 -> V_2 , V_71 , & V_7 -> V_75 -> V_111 ) ;
if ( V_56 < 4 ) {
if ( V_56 != - V_112 )
F_29 ( V_7 -> V_113 ,
L_14 , V_114 , V_56 ) ;
if ( V_56 >= 0 )
V_56 = - V_115 ;
} else {
* V_75 = F_12 ( V_7 -> V_75 -> V_111 . V_116 ) ;
* V_109 = F_12 ( V_7 -> V_75 -> V_111 . V_117 ) ;
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
F_21 ( V_7 -> V_113 , L_15 , V_75 ) ;
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
F_29 ( V_7 -> V_113 , L_16 , V_75 ) ;
}
static inline int
F_44 ( struct V_1 * V_2 , T_1 V_139 , T_1 V_140 )
{
if ( ( ( V_139 >> 11 ) & V_141 ) ==
V_142 ) {
int V_75 = F_14 ( V_2 , F_17 ( V_2 , 0 ) ,
V_143 , V_72 ,
V_139 ^ 0x8000 , V_140 , NULL , 0 , 1000 ) ;
if ( V_75 )
return V_75 ;
}
return F_14 ( V_2 , F_17 ( V_2 , 0 ) ,
V_143 , V_72 , V_139 ,
V_140 , NULL , 0 , 1000 ) ;
}
static void F_45 ( struct V_77 * V_78 )
{
struct V_6 * V_7 =
F_23 ( V_78 , struct V_6 , V_140 . V_144 ) ;
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
F_29 ( & V_2 -> V_22 ,
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
V_56 = F_19 ( V_2 , V_71 , V_161 ) ;
else
V_56 = F_18 ( V_2 , V_71 , V_161 ) ;
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
F_29 ( & V_14 -> V_22 , L_18 ) ;
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
F_12 ( V_7 -> V_3 -> V_175 ) ;
if ( ( V_175 & V_176 ) < 2 )
F_21 ( V_7 -> V_113 , L_19 ) ;
else
F_21 ( V_7 -> V_113 , L_20
L_21 ) ;
for ( V_71 = 1 ; V_71 <= V_7 -> V_2 -> V_12 ; V_71 ++ )
if ( V_7 -> V_160 [ V_71 - 1 ] -> V_162 )
F_19 ( V_7 -> V_2 , V_71 , V_161 ) ;
else
F_18 ( V_7 -> V_2 , V_71 ,
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
F_28 ( & V_7 -> V_110 ) ;
V_56 = F_25 ( V_7 -> V_2 , & V_7 -> V_75 -> V_7 ) ;
if ( V_56 < 0 ) {
if ( V_56 != - V_112 )
F_29 ( V_7 -> V_113 ,
L_14 , V_114 , V_56 ) ;
} else {
* V_75 = F_12 ( V_7 -> V_75 -> V_7 . V_177 ) ;
* V_109 = F_12 ( V_7 -> V_75 -> V_7 . V_178 ) ;
V_56 = 0 ;
}
F_30 ( & V_7 -> V_110 ) ;
return V_56 ;
}
static int F_61 ( struct V_6 * V_7 , int V_71 ,
unsigned int V_179 )
{
return F_19 ( V_7 -> V_2 ,
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
V_56 = F_27 ( V_7 , V_71 , & V_8 , & V_182 ) ;
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
F_63 ( V_7 -> V_113 , L_22 ,
V_71 , V_181 ) ;
return F_61 ( V_7 , V_71 , V_187 ) ;
}
static int F_64 ( struct V_6 * V_7 , int V_71 , int V_188 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_56 = 0 ;
if ( V_7 -> V_160 [ V_71 - 1 ] -> V_189 && V_188 )
F_65 ( V_7 -> V_160 [ V_71 - 1 ] -> V_189 ,
V_190 ) ;
if ( ! V_7 -> error ) {
if ( F_1 ( V_7 -> V_2 ) )
V_56 = F_62 ( V_7 , V_71 ) ;
else
V_56 = F_18 ( V_2 , V_71 ,
V_191 ) ;
}
if ( V_56 && V_56 != - V_112 )
F_29 ( V_7 -> V_113 , L_23 ,
V_71 , V_56 ) ;
return V_56 ;
}
static void F_66 ( struct V_6 * V_7 , int V_71 )
{
F_21 ( V_7 -> V_113 , L_24 , V_71 ) ;
F_64 ( V_7 , V_71 , 1 ) ;
F_41 ( V_71 , V_7 -> V_192 ) ;
F_31 ( V_7 ) ;
}
int F_67 ( struct V_1 * V_14 )
{
struct V_6 * V_7 ;
struct V_193 * V_194 ;
if ( ! V_14 -> V_25 )
return - V_68 ;
V_7 = F_3 ( V_14 -> V_25 ) ;
V_194 = F_36 ( V_7 -> V_113 ) ;
F_68 ( V_194 ) ;
F_41 ( V_14 -> V_124 , V_7 -> V_195 ) ;
F_66 ( V_7 , V_14 -> V_124 ) ;
F_69 ( V_194 ) ;
return 0 ;
}
static void F_70 ( struct V_6 * V_7 , enum V_196 type )
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
if ( V_2 -> V_25 && F_1 ( V_2 ) ) {
V_56 = F_14 ( V_2 , F_17 ( V_2 , 0 ) ,
V_204 , V_65 ,
V_2 -> V_205 - 1 , 0 , NULL , 0 ,
V_206 ) ;
if ( V_56 < 0 )
F_29 ( V_7 -> V_113 ,
L_25 ) ;
}
if ( type == V_207 ) {
V_174 = F_57 ( V_7 , false ) ;
F_71 ( & V_7 -> V_208 , V_209 ) ;
F_24 ( V_100 ,
& V_7 -> V_208 ,
F_72 ( V_174 ) ) ;
F_35 (
F_36 ( V_7 -> V_113 ) ) ;
return;
} else if ( type == V_210 ) {
V_153 = F_55 ( V_2 -> V_170 ) ;
if ( V_153 -> V_154 -> V_211 ) {
V_56 = V_153 -> V_154 -> V_211 ( V_153 , V_2 ,
& V_7 -> V_140 , V_212 ) ;
if ( V_56 < 0 ) {
F_29 ( V_7 -> V_113 , L_26
L_27
L_28 ) ;
F_29 ( V_7 -> V_113 , L_29
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
V_75 = F_27 ( V_7 , V_71 , & V_8 , & V_182 ) ;
if ( V_14 || ( V_8 & V_213 ) )
F_21 ( V_7 -> V_113 ,
L_32 ,
V_71 , V_8 , V_182 ) ;
if ( ( V_8 & V_214 ) && (
type != V_203 ||
! ( V_8 & V_213 ) ||
! V_14 ||
V_14 -> V_82 == V_190 ) ) {
V_8 &= ~ V_214 ;
if ( ! F_1 ( V_2 ) )
F_18 ( V_2 , V_71 ,
V_191 ) ;
}
if ( V_182 & V_215 ) {
V_198 = true ;
F_18 ( V_7 -> V_2 , V_71 ,
V_216 ) ;
}
if ( V_182 & V_217 ) {
V_198 = true ;
F_18 ( V_7 -> V_2 , V_71 ,
V_218 ) ;
}
if ( V_182 & V_219 ) {
V_198 = true ;
F_18 ( V_7 -> V_2 , V_71 ,
V_220 ) ;
}
if ( ( V_182 & V_221 ) &&
F_1 ( V_7 -> V_2 ) ) {
V_198 = true ;
F_18 ( V_7 -> V_2 , V_71 ,
V_222 ) ;
}
if ( ! ( V_8 & V_213 ) ||
( V_182 & V_215 ) )
F_73 ( V_71 , V_7 -> V_195 ) ;
if ( ! V_14 || V_14 -> V_82 == V_190 ) {
if ( V_14 || ( V_8 & V_213 ) ||
( V_8 & V_223 ) )
F_41 ( V_71 , V_7 -> V_192 ) ;
} else if ( V_8 & V_214 ) {
bool V_224 = ( V_8 &
V_185 ) ==
V_225 ;
if ( V_182 || ( F_1 ( V_7 -> V_2 ) &&
V_224 ) )
F_41 ( V_71 , V_7 -> V_192 ) ;
} else if ( V_14 -> V_226 ) {
struct V_158 * V_159 = V_7 -> V_160 [ V_71 - 1 ] ;
#ifdef F_74
V_14 -> V_227 = 1 ;
#endif
if ( V_159 -> V_162 )
F_41 ( V_71 , V_7 -> V_192 ) ;
} else {
F_65 ( V_14 , V_190 ) ;
F_41 ( V_71 , V_7 -> V_192 ) ;
}
}
if ( V_198 ) {
V_174 = V_228 ;
if ( type == V_199 ) {
F_71 ( & V_7 -> V_208 , V_229 ) ;
F_24 ( V_100 ,
& V_7 -> V_208 ,
F_72 ( V_174 ) ) ;
return;
} else {
F_59 ( V_174 ) ;
}
}
V_202:
V_7 -> V_84 = 0 ;
V_75 = F_43 ( V_7 -> V_126 , V_212 ) ;
if ( V_75 < 0 )
F_29 ( V_7 -> V_113 , L_33 , V_75 ) ;
if ( V_7 -> V_230 && V_99 )
F_24 ( V_100 ,
& V_7 -> V_79 , V_101 ) ;
F_31 ( V_7 ) ;
if ( type <= V_201 )
F_75 ( F_36 ( V_7 -> V_113 ) ) ;
}
static void V_209 ( struct V_77 * V_231 )
{
struct V_6 * V_7 = F_23 ( V_231 , struct V_6 , V_208 . V_78 ) ;
F_70 ( V_7 , V_199 ) ;
}
static void V_229 ( struct V_77 * V_231 )
{
struct V_6 * V_7 = F_23 ( V_231 , struct V_6 , V_208 . V_78 ) ;
F_70 ( V_7 , V_201 ) ;
}
static void F_76 ( struct V_6 * V_7 , enum V_232 type )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_55 ;
F_77 ( & V_7 -> V_208 ) ;
V_7 -> V_84 = 1 ;
if ( type != V_233 ) {
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; ++ V_55 ) {
if ( V_7 -> V_160 [ V_55 ] -> V_189 )
F_78 ( & V_7 -> V_160 [ V_55 ] -> V_189 ) ;
}
}
F_79 ( V_7 -> V_126 ) ;
if ( V_7 -> V_230 )
F_77 ( & V_7 -> V_79 ) ;
if ( V_7 -> V_140 . V_7 )
F_80 ( & V_7 -> V_140 . V_144 ) ;
}
static int F_81 ( struct V_193 * V_194 )
{
struct V_6 * V_7 = F_4 ( V_194 ) ;
F_76 ( V_7 , V_234 ) ;
return 0 ;
}
static int F_82 ( struct V_193 * V_194 )
{
struct V_6 * V_7 = F_4 ( V_194 ) ;
F_70 ( V_7 , V_235 ) ;
return 0 ;
}
static int F_83 ( struct V_6 * V_7 ,
struct V_236 * V_237 )
{
struct V_197 * V_153 ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_238 * V_239 = V_7 -> V_113 ;
T_1 V_240 , V_241 ;
T_1 V_175 ;
unsigned int V_163 ;
int V_242 , V_56 , V_55 ;
char * V_243 = L_34 ;
unsigned V_244 ;
unsigned V_245 ;
V_7 -> V_135 = F_51 ( sizeof( * V_7 -> V_135 ) , V_246 ) ;
if ( ! V_7 -> V_135 ) {
V_56 = - V_165 ;
goto V_247;
}
V_7 -> V_75 = F_51 ( sizeof( * V_7 -> V_75 ) , V_246 ) ;
if ( ! V_7 -> V_75 ) {
V_56 = - V_165 ;
goto V_247;
}
F_84 ( & V_7 -> V_110 ) ;
V_7 -> V_3 = F_51 ( sizeof( * V_7 -> V_3 ) , V_246 ) ;
if ( ! V_7 -> V_3 ) {
V_56 = - V_165 ;
goto V_247;
}
V_56 = F_13 ( V_2 , V_7 -> V_3 ) ;
if ( V_56 < 0 ) {
V_243 = L_35 ;
goto V_247;
} else if ( V_7 -> V_3 -> V_248 > V_249 ) {
V_243 = L_36 ;
V_56 = - V_112 ;
goto V_247;
} else if ( V_7 -> V_3 -> V_248 == 0 ) {
V_243 = L_37 ;
V_56 = - V_112 ;
goto V_247;
}
V_2 -> V_12 = V_7 -> V_3 -> V_248 ;
F_7 ( V_239 , L_38 , V_2 -> V_12 ,
( V_2 -> V_12 == 1 ) ? L_39 : L_40 ) ;
V_7 -> V_160 = F_85 ( V_2 -> V_12 * sizeof( struct V_158 * ) ,
V_246 ) ;
if ( ! V_7 -> V_160 ) {
V_56 = - V_165 ;
goto V_247;
}
V_175 = F_12 ( V_7 -> V_3 -> V_175 ) ;
if ( F_1 ( V_2 ) ) {
V_244 = 150 ;
V_245 = 900 ;
} else {
V_244 = 100 ;
V_245 = 500 ;
}
if ( ( V_175 & V_250 ) &&
! ( F_1 ( V_2 ) ) ) {
int V_55 ;
char V_251 [ V_249 + 1 ] ;
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; V_55 ++ )
V_251 [ V_55 ] = V_7 -> V_3 -> V_36 . V_252 . V_253
[ ( ( V_55 + 1 ) / 8 ) ] & ( 1 << ( ( V_55 + 1 ) % 8 ) )
? 'F' : 'R' ;
V_251 [ V_2 -> V_12 ] = 0 ;
F_21 ( V_239 , L_41 , V_251 ) ;
} else
F_21 ( V_239 , L_42 ) ;
switch ( V_175 & V_176 ) {
case V_254 :
F_21 ( V_239 , L_43 ) ;
break;
case V_255 :
F_21 ( V_239 , L_44 ) ;
break;
case V_256 :
case V_176 :
F_21 ( V_239 , L_45 ) ;
break;
}
switch ( V_175 & V_257 ) {
case V_258 :
F_21 ( V_239 , L_46 ) ;
break;
case V_259 :
F_21 ( V_239 , L_47 ) ;
break;
case V_260 :
case V_257 :
F_21 ( V_239 , L_48 ) ;
break;
}
F_86 ( & V_7 -> V_140 . V_145 ) ;
F_87 ( & V_7 -> V_140 . V_146 ) ;
F_88 ( & V_7 -> V_140 . V_144 , F_45 ) ;
switch ( V_2 -> V_3 . V_4 ) {
case V_261 :
break;
case V_262 :
F_21 ( V_239 , L_49 ) ;
V_7 -> V_140 . V_7 = V_2 ;
break;
case V_263 :
V_56 = F_89 ( V_2 , 0 , 1 ) ;
if ( V_56 == 0 ) {
F_21 ( V_239 , L_50 ) ;
V_7 -> V_140 . V_166 = 1 ;
} else
F_29 ( V_239 , L_51 ,
V_56 ) ;
V_7 -> V_140 . V_7 = V_2 ;
break;
case V_5 :
break;
default:
F_21 ( V_239 , L_52 ,
V_2 -> V_3 . V_4 ) ;
break;
}
switch ( V_175 & V_264 ) {
case V_265 :
if ( V_2 -> V_3 . V_4 != 0 ) {
V_7 -> V_140 . V_266 = 666 ;
F_21 ( V_239 , L_53
L_54 ,
8 , V_7 -> V_140 . V_266 ) ;
}
break;
case V_267 :
V_7 -> V_140 . V_266 = 666 * 2 ;
F_21 ( V_239 , L_53
L_54 ,
16 , V_7 -> V_140 . V_266 ) ;
break;
case V_268 :
V_7 -> V_140 . V_266 = 666 * 3 ;
F_21 ( V_239 , L_53
L_54 ,
24 , V_7 -> V_140 . V_266 ) ;
break;
case V_269 :
V_7 -> V_140 . V_266 = 666 * 4 ;
F_21 ( V_239 , L_53
L_54 ,
32 , V_7 -> V_140 . V_266 ) ;
break;
}
if ( V_175 & V_270 ) {
V_7 -> V_230 = 1 ;
F_21 ( V_239 , L_55 ) ;
}
F_21 ( V_239 , L_56 ,
V_7 -> V_3 -> V_173 * 2 ) ;
V_56 = F_90 ( V_2 , V_271 , 0 , & V_240 ) ;
if ( V_56 ) {
V_243 = L_57 ;
goto V_247;
}
V_153 = F_55 ( V_2 -> V_170 ) ;
if ( V_2 == V_2 -> V_170 -> V_272 ) {
if ( V_153 -> V_273 > 0 )
V_2 -> V_274 = V_153 -> V_273 ;
else
V_2 -> V_274 = V_245 * V_2 -> V_12 ;
if ( V_2 -> V_274 >= V_245 )
V_7 -> V_275 = V_245 ;
else {
V_7 -> V_275 = V_2 -> V_274 ;
V_7 -> V_276 = 1 ;
}
} else if ( ( V_240 & ( 1 << V_277 ) ) == 0 ) {
int V_278 = V_2 -> V_274 -
V_7 -> V_3 -> V_279 ;
F_21 ( V_239 , L_58 ,
V_7 -> V_3 -> V_279 ) ;
V_7 -> V_276 = 1 ;
if ( V_278 < V_2 -> V_12 * V_244 )
F_63 ( V_239 ,
L_59
L_60 ) ;
V_7 -> V_275 = V_244 ;
} else {
V_7 -> V_275 = V_245 ;
}
if ( V_7 -> V_275 < V_245 )
F_21 ( V_239 , L_61 ,
V_7 -> V_275 ) ;
if ( V_153 -> V_154 -> V_211 ) {
V_56 = V_153 -> V_154 -> V_211 ( V_153 , V_2 ,
& V_7 -> V_140 , V_246 ) ;
if ( V_56 < 0 ) {
V_243 = L_62 ;
goto V_247;
}
}
V_56 = F_60 ( V_7 , & V_240 , & V_241 ) ;
if ( V_56 < 0 ) {
V_243 = L_57 ;
goto V_247;
}
if ( V_2 -> V_11 -> V_280 . V_20 & V_281 )
F_21 ( V_239 , L_63 ,
( V_240 & V_282 )
? L_64 : L_65 ) ;
if ( ( V_175 & V_257 ) == 0 )
F_21 ( V_239 , L_66 ,
( V_240 & V_283 ) ? L_39 : L_67 ) ;
V_163 = F_91 ( V_2 , V_237 -> V_284 ) ;
V_242 = F_92 ( V_2 , V_163 , F_93 ( V_163 ) ) ;
if ( V_242 > sizeof( * V_7 -> V_135 ) )
V_242 = sizeof( * V_7 -> V_135 ) ;
V_7 -> V_126 = F_94 ( 0 , V_246 ) ;
if ( ! V_7 -> V_126 ) {
V_56 = - V_165 ;
goto V_247;
}
F_95 ( V_7 -> V_126 , V_2 , V_163 , * V_7 -> V_135 , V_242 , F_42 ,
V_7 , V_237 -> V_285 ) ;
if ( V_7 -> V_230 && V_99 )
V_7 -> V_86 [ 0 ] = V_87 ;
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; V_55 ++ ) {
V_56 = F_96 ( V_7 , V_55 + 1 ) ;
if ( V_56 < 0 ) {
F_29 ( V_7 -> V_113 ,
L_68 , V_55 + 1 ) ;
V_2 -> V_12 = V_55 ;
goto V_286;
}
}
F_97 ( V_2 , V_7 -> V_3 ) ;
F_70 ( V_7 , V_207 ) ;
return 0 ;
V_247:
V_2 -> V_12 = 0 ;
V_286:
F_29 ( V_239 , L_69 ,
V_243 , V_56 ) ;
return V_56 ;
}
static void F_98 ( struct V_287 * V_287 )
{
struct V_6 * V_7 = F_23 ( V_287 , struct V_6 , V_287 ) ;
F_99 ( F_36 ( V_7 -> V_113 ) ) ;
F_48 ( V_7 ) ;
}
static void F_100 ( struct V_193 * V_194 )
{
struct V_6 * V_7 = F_4 ( V_194 ) ;
struct V_1 * V_2 = F_101 ( V_194 ) ;
int V_71 ;
F_102 ( & V_119 ) ;
if ( ! F_33 ( & V_7 -> V_121 ) ) {
F_103 ( & V_7 -> V_121 ) ;
F_104 ( V_194 ) ;
}
V_7 -> V_120 = 1 ;
F_105 ( & V_119 ) ;
V_7 -> error = 0 ;
F_76 ( V_7 , V_288 ) ;
F_102 ( & V_289 ) ;
V_71 = V_2 -> V_12 ;
V_2 -> V_12 = 0 ;
F_106 ( V_194 , NULL ) ;
F_105 ( & V_289 ) ;
for (; V_71 > 0 ; -- V_71 )
F_107 ( V_7 , V_71 ) ;
if ( V_7 -> V_2 -> V_15 == V_16 )
V_290 -- ;
F_108 ( V_7 -> V_126 ) ;
F_48 ( V_7 -> V_160 ) ;
F_48 ( V_7 -> V_3 ) ;
F_48 ( V_7 -> V_75 ) ;
F_48 ( V_7 -> V_135 ) ;
F_109 ( & V_194 -> V_22 , false ) ;
F_110 ( & V_7 -> V_287 , F_98 ) ;
}
static int F_111 ( struct V_193 * V_194 , const struct V_291 * V_292 )
{
struct V_293 * V_280 ;
struct V_236 * V_237 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
V_280 = V_194 -> V_294 ;
V_2 = F_101 ( V_194 ) ;
F_112 ( & V_2 -> V_22 , 0 ) ;
if ( V_2 -> V_25 ) {
F_113 ( V_2 ) ;
} else {
const struct V_151 * V_152 = F_55 ( V_2 -> V_170 ) -> V_154 ;
if ( V_152 -> V_295 && V_152 -> V_296 )
F_113 ( V_2 ) ;
}
if ( V_2 -> V_205 == V_297 ) {
F_29 ( & V_194 -> V_22 ,
L_70 ) ;
return - V_298 ;
}
#ifdef F_114
if ( V_2 -> V_25 ) {
F_63 ( & V_194 -> V_22 , L_71 ) ;
return - V_112 ;
}
#endif
if ( ( V_280 -> V_280 . V_299 != 0 ) &&
( V_280 -> V_280 . V_299 != 1 ) ) {
V_300:
F_29 ( & V_194 -> V_22 , L_72 ) ;
return - V_115 ;
}
if ( V_280 -> V_280 . V_301 != 1 )
goto V_300;
V_237 = & V_280 -> V_237 [ 0 ] . V_280 ;
if ( ! F_115 ( V_237 ) )
goto V_300;
F_7 ( & V_194 -> V_22 , L_73 ) ;
V_7 = F_85 ( sizeof( * V_7 ) , V_246 ) ;
if ( ! V_7 ) {
F_21 ( & V_194 -> V_22 , L_74 ) ;
return - V_165 ;
}
F_116 ( & V_7 -> V_287 ) ;
F_87 ( & V_7 -> V_121 ) ;
V_7 -> V_113 = & V_194 -> V_22 ;
V_7 -> V_2 = V_2 ;
F_71 ( & V_7 -> V_79 , F_22 ) ;
F_71 ( & V_7 -> V_208 , NULL ) ;
F_117 ( V_194 ) ;
F_106 ( V_194 , V_7 ) ;
V_194 -> V_302 = 1 ;
F_109 ( & V_194 -> V_22 , true ) ;
if ( V_2 -> V_15 == V_16 )
V_290 ++ ;
if ( V_292 -> V_303 & V_304 )
V_7 -> V_305 = 1 ;
if ( F_83 ( V_7 , V_237 ) >= 0 )
return 0 ;
F_100 ( V_194 ) ;
return - V_112 ;
}
static int
F_118 ( struct V_193 * V_194 , unsigned int V_306 , void * V_307 )
{
struct V_1 * V_2 = F_101 ( V_194 ) ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
switch ( V_306 ) {
case V_308 : {
struct V_309 * V_310 = V_307 ;
int V_55 ;
F_102 ( & V_289 ) ;
if ( V_2 -> V_168 <= 0 )
V_310 -> V_311 = 0 ;
else {
V_310 -> V_311 = V_2 -> V_12 ;
for ( V_55 = 0 ; V_55 < V_310 -> V_311 ; V_55 ++ ) {
if ( V_7 -> V_160 [ V_55 ] -> V_189 == NULL )
V_310 -> V_111 [ V_55 ] = 0 ;
else
V_310 -> V_111 [ V_55 ] =
V_7 -> V_160 [ V_55 ] -> V_189 -> V_168 ;
}
}
F_105 ( & V_289 ) ;
return V_310 -> V_311 + 1 ;
}
default:
return - V_312 ;
}
}
static int F_119 ( struct V_1 * V_2 , unsigned V_71 ,
struct V_313 * * * V_314 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_2 -> V_82 == V_190 )
return - V_112 ;
if ( V_71 == 0 || V_71 > V_2 -> V_12 )
return - V_68 ;
* V_314 = & ( V_7 -> V_160 [ V_71 - 1 ] -> V_315 ) ;
return 0 ;
}
int F_120 ( struct V_1 * V_2 , unsigned V_71 ,
struct V_313 * V_316 )
{
int V_317 ;
struct V_313 * * V_318 ;
V_317 = F_119 ( V_2 , V_71 , & V_318 ) ;
if ( V_317 )
return V_317 ;
if ( * V_318 )
return - V_319 ;
* V_318 = V_316 ;
return V_317 ;
}
int F_121 ( struct V_1 * V_2 , unsigned V_71 ,
struct V_313 * V_316 )
{
int V_317 ;
struct V_313 * * V_318 ;
V_317 = F_119 ( V_2 , V_71 , & V_318 ) ;
if ( V_317 )
return V_317 ;
if ( * V_318 != V_316 )
return - V_129 ;
* V_318 = NULL ;
return V_317 ;
}
void F_122 ( struct V_1 * V_2 , struct V_313 * V_316 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
int V_320 ;
for ( V_320 = 0 ; V_320 < V_2 -> V_12 ; V_320 ++ ) {
if ( V_7 -> V_160 [ V_320 ] -> V_315 == V_316 )
V_7 -> V_160 [ V_320 ] -> V_315 = NULL ;
}
}
bool F_123 ( struct V_1 * V_14 )
{
struct V_6 * V_7 ;
if ( V_14 -> V_82 == V_190 || ! V_14 -> V_25 )
return false ;
V_7 = F_3 ( V_14 -> V_25 ) ;
return ! ! V_7 -> V_160 [ V_14 -> V_124 - 1 ] -> V_315 ;
}
static void F_124 ( struct V_1 * V_14 )
{
struct V_6 * V_7 = F_3 ( V_14 ) ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_14 -> V_12 ; ++ V_55 ) {
if ( V_7 -> V_160 [ V_55 ] -> V_189 )
F_124 ( V_7 -> V_160 [ V_55 ] -> V_189 ) ;
}
if ( V_14 -> V_82 == V_321 )
V_14 -> V_322 -= V_323 ;
V_14 -> V_82 = V_190 ;
}
void F_65 ( struct V_1 * V_14 ,
enum V_324 V_325 )
{
unsigned long V_118 ;
int V_326 = - 1 ;
F_32 ( & V_289 , V_118 ) ;
if ( V_14 -> V_82 == V_190 )
;
else if ( V_325 != V_190 ) {
if ( V_14 -> V_25 ) {
if ( V_14 -> V_82 == V_321
|| V_325 == V_321 )
;
else if ( V_325 == V_83 )
V_326 = V_14 -> V_11 -> V_280 . V_20
& V_327 ;
else
V_326 = 0 ;
}
if ( V_14 -> V_82 == V_321 &&
V_325 != V_321 )
V_14 -> V_322 -= V_323 ;
else if ( V_325 == V_321 &&
V_14 -> V_82 != V_321 )
V_14 -> V_322 += V_323 ;
V_14 -> V_82 = V_325 ;
} else
F_124 ( V_14 ) ;
F_38 ( & V_289 , V_118 ) ;
if ( V_326 >= 0 )
F_125 ( & V_14 -> V_22 , V_326 ) ;
}
static void F_126 ( struct V_1 * V_14 )
{
int V_168 ;
struct V_328 * V_170 = V_14 -> V_170 ;
if ( V_14 -> V_329 ) {
V_168 = V_14 -> V_124 + 1 ;
F_127 ( F_128 ( V_168 , V_170 -> V_330 . V_331 ) ) ;
} else {
V_168 = F_129 ( V_170 -> V_330 . V_331 , 128 ,
V_170 -> V_332 ) ;
if ( V_168 >= 128 )
V_168 = F_129 ( V_170 -> V_330 . V_331 ,
128 , 1 ) ;
V_170 -> V_332 = ( V_168 >= 127 ? 1 : V_168 + 1 ) ;
}
if ( V_168 < 128 ) {
F_41 ( V_168 , V_170 -> V_330 . V_331 ) ;
V_14 -> V_168 = V_168 ;
}
}
static void F_130 ( struct V_1 * V_14 )
{
if ( V_14 -> V_168 > 0 ) {
F_73 ( V_14 -> V_168 , V_14 -> V_170 -> V_330 . V_331 ) ;
V_14 -> V_168 = - 1 ;
}
}
static void F_131 ( struct V_1 * V_14 , int V_168 )
{
if ( ! V_14 -> V_329 )
V_14 -> V_168 = V_168 ;
}
static void F_132 ( struct V_1 * V_14 )
{
struct V_197 * V_153 = F_55 ( V_14 -> V_170 ) ;
if ( V_153 -> V_154 -> V_333 && V_14 -> V_25 )
V_153 -> V_154 -> V_333 ( V_153 , V_14 ) ;
}
void F_78 ( struct V_1 * * V_334 )
{
struct V_1 * V_14 = * V_334 ;
struct V_6 * V_7 = F_3 ( V_14 ) ;
int V_55 ;
F_65 ( V_14 , V_190 ) ;
F_7 ( & V_14 -> V_22 , L_75 ,
V_14 -> V_168 ) ;
F_133 ( V_14 ) ;
for ( V_55 = 0 ; V_55 < V_14 -> V_12 ; V_55 ++ ) {
if ( V_7 -> V_160 [ V_55 ] -> V_189 )
F_78 ( & V_7 -> V_160 [ V_55 ] -> V_189 ) ;
}
F_21 ( & V_14 -> V_22 , L_76 ) ;
F_134 ( V_14 , 0 ) ;
F_135 ( V_14 ) ;
if ( V_14 -> V_25 ) {
struct V_6 * V_7 = F_3 ( V_14 -> V_25 ) ;
struct V_158 * V_159 = V_7 -> V_160 [ V_14 -> V_124 - 1 ] ;
F_136 ( & V_14 -> V_22 . V_335 , L_77 ) ;
F_136 ( & V_159 -> V_22 . V_335 , L_78 ) ;
if ( ! V_159 -> V_336 )
F_137 ( & V_159 -> V_22 ) ;
else
V_159 -> V_336 = false ;
}
F_138 ( & V_14 -> V_337 ) ;
F_139 ( V_14 ) ;
F_140 ( & V_14 -> V_22 ) ;
F_130 ( V_14 ) ;
F_102 ( & V_289 ) ;
* V_334 = NULL ;
F_105 ( & V_289 ) ;
F_132 ( V_14 ) ;
F_141 ( & V_14 -> V_22 ) ;
}
static void F_142 ( struct V_1 * V_14 , char * V_292 , char * string )
{
if ( ! string )
return;
F_7 ( & V_14 -> V_22 , L_79 , V_292 , string ) ;
}
static void F_143 ( struct V_1 * V_14 )
{
F_7 ( & V_14 -> V_22 , L_80 ,
F_12 ( V_14 -> V_3 . V_338 ) ,
F_12 ( V_14 -> V_3 . V_339 ) ) ;
F_7 ( & V_14 -> V_22 ,
L_81 ,
V_14 -> V_3 . V_340 ,
V_14 -> V_3 . V_341 ,
V_14 -> V_3 . V_342 ) ;
F_142 ( V_14 , L_82 , V_14 -> V_343 ) ;
F_142 ( V_14 , L_83 , V_14 -> V_344 ) ;
F_142 ( V_14 , L_84 , V_14 -> V_345 ) ;
}
static inline void F_143 ( struct V_1 * V_14 ) { }
static int F_144 ( struct V_1 * V_14 )
{
int V_346 = 0 ;
#ifdef F_145
if ( ! V_14 -> V_170 -> V_347
&& V_14 -> V_348
&& V_14 -> V_25 == V_14 -> V_170 -> V_272 ) {
struct V_349 * V_280 = NULL ;
struct V_328 * V_170 = V_14 -> V_170 ;
if ( F_146 ( V_14 -> V_350 [ 0 ] ,
F_12 ( V_14 -> V_348 [ 0 ] . V_280 . V_351 ) ,
V_352 , ( void * * ) & V_280 ) == 0 ) {
if ( V_280 -> V_20 & V_353 ) {
unsigned V_71 = V_14 -> V_124 ;
F_7 ( & V_14 -> V_22 ,
L_85 ,
( V_71 == V_170 -> V_354 )
? L_39 : L_86 ) ;
if ( V_71 == V_170 -> V_354 )
V_170 -> V_355 = 1 ;
V_346 = F_14 ( V_14 ,
F_17 ( V_14 , 0 ) ,
V_73 , 0 ,
V_170 -> V_355
? V_356
: V_357 ,
0 , NULL , 0 , V_206 ) ;
if ( V_346 < 0 ) {
F_7 ( & V_14 -> V_22 ,
L_87 ,
V_346 ) ;
V_170 -> V_355 = 0 ;
}
}
}
}
if ( ! F_147 ( V_14 ) ) {
if ( V_14 -> V_170 -> V_355 || V_14 -> V_170 -> V_347 ) {
V_346 = F_148 ( V_14 , V_358 ) ;
if ( V_346 < 0 )
F_21 ( & V_14 -> V_22 , L_88 , V_346 ) ;
}
V_346 = - V_359 ;
goto V_247;
}
V_247:
#endif
return V_346 ;
}
static int F_149 ( struct V_1 * V_14 )
{
int V_346 ;
if ( V_14 -> V_348 == NULL ) {
V_346 = F_150 ( V_14 ) ;
if ( V_346 < 0 ) {
if ( V_346 != - V_112 )
F_29 ( & V_14 -> V_22 , L_89 ,
V_346 ) ;
return V_346 ;
}
}
V_14 -> V_343 = F_151 ( V_14 , V_14 -> V_3 . V_341 ) ;
V_14 -> V_344 = F_151 ( V_14 ,
V_14 -> V_3 . V_340 ) ;
V_14 -> V_345 = F_151 ( V_14 , V_14 -> V_3 . V_342 ) ;
V_346 = F_144 ( V_14 ) ;
if ( V_346 < 0 )
return V_346 ;
F_152 ( V_14 ) ;
return 0 ;
}
static void F_153 ( struct V_1 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_25 ;
struct V_6 * V_7 ;
T_2 V_111 = V_14 -> V_124 ;
T_1 V_175 ;
bool V_360 = true ;
if ( ! V_2 )
return;
V_7 = F_3 ( V_14 -> V_25 ) ;
V_175 = F_12 ( V_7 -> V_3 -> V_175 ) ;
if ( ! ( V_175 & V_250 ) )
return;
if ( F_1 ( V_2 ) ) {
if ( F_12 ( V_7 -> V_3 -> V_36 . V_37 . V_253 )
& ( 1 << V_111 ) )
V_360 = false ;
} else {
if ( V_7 -> V_3 -> V_36 . V_252 . V_253 [ V_111 / 8 ] & ( 1 << ( V_111 % 8 ) ) )
V_360 = false ;
}
if ( V_360 )
V_14 -> V_360 = V_361 ;
else
V_14 -> V_360 = V_362 ;
}
int F_154 ( struct V_1 * V_14 )
{
int V_346 ;
if ( V_14 -> V_25 ) {
F_155 ( & V_14 -> V_22 , 0 ) ;
}
F_156 ( & V_14 -> V_22 ) ;
F_157 ( & V_14 -> V_22 ) ;
F_158 ( & V_14 -> V_22 ) ;
F_159 ( & V_14 -> V_22 ) ;
F_160 ( V_14 ) ;
V_346 = F_149 ( V_14 ) ;
if ( V_346 < 0 )
goto V_247;
F_21 ( & V_14 -> V_22 , L_90 ,
V_14 -> V_168 , V_14 -> V_170 -> V_363 ,
( ( ( V_14 -> V_170 -> V_363 - 1 ) * 128 ) + ( V_14 -> V_168 - 1 ) ) ) ;
V_14 -> V_22 . V_364 = F_161 ( V_365 ,
( ( ( V_14 -> V_170 -> V_363 - 1 ) * 128 ) + ( V_14 -> V_168 - 1 ) ) ) ;
F_143 ( V_14 ) ;
if ( V_14 -> V_345 )
F_162 ( V_14 -> V_345 , strlen ( V_14 -> V_345 ) ) ;
if ( V_14 -> V_343 )
F_162 ( V_14 -> V_343 , strlen ( V_14 -> V_343 ) ) ;
if ( V_14 -> V_344 )
F_162 ( V_14 -> V_344 ,
strlen ( V_14 -> V_344 ) ) ;
F_163 ( & V_14 -> V_22 ) ;
if ( V_14 -> V_25 )
F_153 ( V_14 ) ;
V_346 = F_164 ( & V_14 -> V_22 ) ;
if ( V_346 ) {
F_29 ( & V_14 -> V_22 , L_91 , V_346 ) ;
goto V_247;
}
if ( V_14 -> V_25 ) {
struct V_6 * V_7 = F_3 ( V_14 -> V_25 ) ;
struct V_158 * V_159 = V_7 -> V_160 [ V_14 -> V_124 - 1 ] ;
V_346 = F_165 ( & V_14 -> V_22 . V_335 ,
& V_159 -> V_22 . V_335 , L_77 ) ;
if ( V_346 )
goto V_247;
V_346 = F_165 ( & V_159 -> V_22 . V_335 ,
& V_14 -> V_22 . V_335 , L_78 ) ;
if ( V_346 ) {
F_136 ( & V_14 -> V_22 . V_335 , L_77 ) ;
goto V_247;
}
F_166 ( & V_159 -> V_22 ) ;
}
( void ) F_167 ( & V_14 -> V_22 , & V_14 -> V_337 , V_14 ) ;
F_168 ( V_14 ) ;
F_169 ( & V_14 -> V_22 ) ;
return V_346 ;
V_247:
F_65 ( V_14 , V_190 ) ;
F_170 ( & V_14 -> V_22 ) ;
F_171 ( & V_14 -> V_22 ) ;
return V_346 ;
}
int F_172 ( struct V_1 * V_366 )
{
F_133 ( V_366 ) ;
if ( V_366 -> V_367 == 0 )
goto V_368;
V_366 -> V_367 = 0 ;
F_173 ( V_366 , - 1 ) ;
V_368:
F_139 ( V_366 ) ;
return 0 ;
}
int F_174 ( struct V_1 * V_366 )
{
int V_369 = 0 , V_370 ;
F_133 ( V_366 ) ;
if ( V_366 -> V_367 == 1 )
goto V_371;
V_369 = F_175 ( V_366 ) ;
if ( V_369 < 0 ) {
F_29 ( & V_366 -> V_22 ,
L_92 , V_369 ) ;
goto V_372;
}
V_369 = F_176 ( V_366 , sizeof( V_366 -> V_3 ) ) ;
if ( V_369 < 0 ) {
F_29 ( & V_366 -> V_22 , L_93
L_94 , V_369 ) ;
goto V_373;
}
V_366 -> V_367 = 1 ;
V_370 = F_177 ( V_366 ) ;
if ( V_370 >= 0 ) {
V_369 = F_173 ( V_366 , V_370 ) ;
if ( V_369 ) {
F_29 ( & V_366 -> V_22 ,
L_95 , V_370 , V_369 ) ;
}
}
F_7 ( & V_366 -> V_22 , L_96 ) ;
V_373:
F_178 ( V_366 ) ;
V_372:
V_371:
F_139 ( V_366 ) ;
return V_369 ;
}
static unsigned F_179 ( struct V_6 * V_7 )
{
struct V_197 * V_153 ;
if ( V_7 -> V_2 -> V_25 != NULL )
return 0 ;
V_153 = F_23 ( V_7 -> V_2 -> V_170 , struct V_197 , V_374 ) ;
return V_153 -> V_375 ;
}
static bool F_180 ( struct V_1 * V_14 , int V_376 )
{
if ( V_14 -> V_15 == V_51 )
return false ;
return F_181 ( V_376 ) ;
}
static bool F_182 ( struct V_6 * V_7 , T_1 V_8 )
{
return F_1 ( V_7 -> V_2 ) &&
( ( ( V_8 & V_185 ) ==
V_377 ) ||
( ( V_8 & V_185 ) ==
V_378 ) ) ;
}
static int F_183 ( struct V_6 * V_7 , int V_71 ,
struct V_1 * V_14 , unsigned int V_174 , bool V_379 )
{
int V_380 , V_56 ;
T_1 V_8 ;
T_1 V_182 ;
for ( V_380 = 0 ;
V_380 < V_381 ;
V_380 += V_174 ) {
F_59 ( V_174 ) ;
V_56 = F_27 ( V_7 , V_71 , & V_8 , & V_182 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( ! ( V_8 & V_382 ) )
break;
if ( V_380 >= 2 * V_383 )
V_174 = V_384 ;
F_21 ( V_7 -> V_113 ,
L_97 ,
V_71 , V_379 ? L_98 : L_39 , V_174 ) ;
}
if ( ( V_8 & V_382 ) )
return - V_319 ;
if ( F_182 ( V_7 , V_8 ) )
return - V_385 ;
if ( ! ( V_8 & V_213 ) )
return - V_385 ;
if ( ! F_1 ( V_7 -> V_2 ) &&
( V_182 & V_215 ) )
return - V_385 ;
if ( ! ( V_8 & V_214 ) )
return - V_319 ;
if ( ! V_14 )
return 0 ;
if ( F_179 ( V_7 ) )
V_14 -> V_15 = V_386 ;
else if ( F_1 ( V_7 -> V_2 ) )
V_14 -> V_15 = V_51 ;
else if ( V_8 & V_9 )
V_14 -> V_15 = V_16 ;
else if ( V_8 & V_10 )
V_14 -> V_15 = V_387 ;
else
V_14 -> V_15 = V_388 ;
return 0 ;
}
static void F_184 ( struct V_6 * V_7 , int V_71 ,
struct V_1 * V_14 , int * V_75 )
{
switch ( * V_75 ) {
case 0 :
F_59 ( 10 + 40 ) ;
if ( V_14 ) {
struct V_197 * V_153 = F_55 ( V_14 -> V_170 ) ;
F_131 ( V_14 , 0 ) ;
if ( V_153 -> V_154 -> V_389 )
V_153 -> V_154 -> V_389 ( V_153 , V_14 ) ;
}
case - V_385 :
case - V_112 :
F_18 ( V_7 -> V_2 ,
V_71 , V_220 ) ;
if ( F_1 ( V_7 -> V_2 ) ) {
F_18 ( V_7 -> V_2 , V_71 ,
V_222 ) ;
F_18 ( V_7 -> V_2 , V_71 ,
V_390 ) ;
F_18 ( V_7 -> V_2 , V_71 ,
V_216 ) ;
}
if ( V_14 )
F_65 ( V_14 , * V_75
? V_190
: V_391 ) ;
break;
}
}
static int F_185 ( struct V_6 * V_7 , int V_71 ,
struct V_1 * V_14 , unsigned int V_174 , bool V_379 )
{
int V_55 , V_75 ;
T_1 V_182 , V_8 ;
if ( ! F_1 ( V_7 -> V_2 ) ) {
if ( V_379 ) {
F_29 ( V_7 -> V_113 , L_99
L_100 ) ;
return - V_68 ;
}
F_186 ( & V_392 ) ;
} else if ( ! V_379 ) {
V_75 = F_27 ( V_7 , V_71 ,
& V_8 , & V_182 ) ;
if ( V_75 < 0 )
goto V_393;
if ( F_182 ( V_7 , V_8 ) )
V_379 = true ;
}
for ( V_55 = 0 ; V_55 < V_394 ; V_55 ++ ) {
V_75 = F_19 ( V_7 -> V_2 , V_71 , ( V_379 ?
V_395 :
V_396 ) ) ;
if ( V_75 == - V_112 ) {
;
} else if ( V_75 ) {
F_29 ( V_7 -> V_113 ,
L_101 ,
V_379 ? L_98 : L_39 , V_71 , V_75 ) ;
} else {
V_75 = F_183 ( V_7 , V_71 , V_14 , V_174 ,
V_379 ) ;
if ( V_75 && V_75 != - V_385 && V_75 != - V_112 )
F_21 ( V_7 -> V_113 ,
L_102 ,
V_75 ) ;
}
if ( V_75 == 0 || V_75 == - V_385 || V_75 == - V_112 ) {
F_184 ( V_7 , V_71 , V_14 , & V_75 ) ;
if ( ! F_1 ( V_7 -> V_2 ) )
goto V_393;
if ( F_27 ( V_7 , V_71 ,
& V_8 , & V_182 ) < 0 )
goto V_393;
if ( ! F_182 ( V_7 , V_8 ) )
goto V_393;
if ( ! V_379 ) {
F_21 ( V_7 -> V_113 , L_103 ,
V_71 ) ;
V_379 = true ;
}
}
F_21 ( V_7 -> V_113 ,
L_104 ,
V_71 , V_379 ? L_98 : L_39 ) ;
V_174 = V_384 ;
}
F_29 ( V_7 -> V_113 ,
L_105 ,
V_71 ) ;
V_393:
if ( ! F_1 ( V_7 -> V_2 ) )
F_187 ( & V_392 ) ;
return V_75 ;
}
static int F_188 ( struct V_6 * V_7 , unsigned V_8 )
{
int V_56 = 0 ;
if ( F_1 ( V_7 -> V_2 ) ) {
if ( V_8 & V_397 )
V_56 = 1 ;
} else {
if ( V_8 & V_398 )
V_56 = 1 ;
}
return V_56 ;
}
static int F_189 ( struct V_6 * V_7 , unsigned V_8 )
{
int V_56 = 0 ;
if ( F_1 ( V_7 -> V_2 ) ) {
if ( ( V_8 & V_185 )
== V_399 )
V_56 = 1 ;
} else {
if ( V_8 & V_400 )
V_56 = 1 ;
}
return V_56 ;
}
static int F_190 ( struct V_1 * V_14 ,
struct V_6 * V_7 , int V_71 ,
int V_75 , unsigned V_182 , unsigned V_8 )
{
if ( V_75 || F_189 ( V_7 , V_8 ) ||
! F_188 ( V_7 , V_8 ) ||
! ( V_8 & V_213 ) ) {
if ( V_75 >= 0 )
V_75 = - V_112 ;
}
else if ( ! ( V_8 & V_214 ) && ! V_14 -> V_227 ) {
if ( V_14 -> V_226 )
V_14 -> V_227 = 1 ;
else
V_75 = - V_112 ;
}
if ( V_75 ) {
F_21 ( V_7 -> V_113 ,
L_106 ,
V_71 , V_182 , V_8 , V_75 ) ;
} else if ( V_14 -> V_227 ) {
if ( V_182 & V_215 )
F_18 ( V_7 -> V_2 , V_71 ,
V_216 ) ;
if ( V_182 & V_217 )
F_18 ( V_7 -> V_2 , V_71 ,
V_218 ) ;
}
return V_75 ;
}
int F_191 ( struct V_1 * V_14 )
{
struct V_197 * V_153 = F_55 ( V_14 -> V_170 ) ;
if ( ! F_192 ( V_153 -> V_374 . V_272 ) ||
! F_192 ( V_14 ) )
return 0 ;
if ( ! V_14 -> V_11 )
return 0 ;
return F_14 ( V_14 , F_17 ( V_14 , 0 ) ,
V_70 , V_271 ,
V_401 , 0 , NULL , 0 ,
V_206 ) ;
}
void F_193 ( struct V_1 * V_14 )
{
struct V_197 * V_153 = F_55 ( V_14 -> V_170 ) ;
if ( ! F_192 ( V_153 -> V_374 . V_272 ) ||
! F_192 ( V_14 ) )
return;
if ( ! V_14 -> V_11 )
return;
F_14 ( V_14 , F_17 ( V_14 , 0 ) ,
V_73 , V_271 ,
V_401 , 0 , NULL , 0 ,
V_206 ) ;
}
static int F_194 ( struct V_1 * V_14 )
{
if ( V_14 -> V_15 < V_51 )
return F_14 ( V_14 , F_17 ( V_14 , 0 ) ,
V_73 , V_271 ,
V_402 , 0 , NULL , 0 ,
V_206 ) ;
else
return F_14 ( V_14 , F_17 ( V_14 , 0 ) ,
V_73 , V_403 ,
V_404 ,
V_405 |
V_406 ,
NULL , 0 , V_206 ) ;
}
static int F_195 ( struct V_1 * V_14 )
{
if ( V_14 -> V_15 < V_51 )
return F_14 ( V_14 , F_17 ( V_14 , 0 ) ,
V_70 , V_271 ,
V_402 , 0 , NULL , 0 ,
V_206 ) ;
else
return F_14 ( V_14 , F_17 ( V_14 , 0 ) ,
V_70 , V_403 ,
V_404 , 0 , NULL , 0 ,
V_206 ) ;
}
static unsigned F_196 ( struct V_1 * V_14 )
{
struct V_6 * V_7 = F_3 ( V_14 ) ;
return V_14 -> V_407 +
( V_7 ? V_7 -> F_196 : 0 ) ;
}
int F_148 ( struct V_1 * V_14 , T_3 V_408 )
{
struct V_6 * V_7 = F_3 ( V_14 -> V_25 ) ;
struct V_158 * V_159 = V_7 -> V_160 [ V_14 -> V_124 - 1 ] ;
int V_71 = V_14 -> V_124 ;
int V_75 ;
bool V_409 = true ;
if ( V_14 -> V_407 ) {
V_75 = F_194 ( V_14 ) ;
if ( V_75 ) {
F_21 ( & V_14 -> V_22 , L_107 ,
V_75 ) ;
if ( F_197 ( V_408 ) )
goto V_410;
}
}
if ( V_14 -> V_411 == 1 )
F_198 ( V_14 , 0 ) ;
if ( F_191 ( V_14 ) ) {
F_29 ( & V_14 -> V_22 , L_108 ) ;
V_75 = - V_165 ;
if ( F_197 ( V_408 ) )
goto V_412;
}
if ( F_199 ( V_14 ) ) {
F_29 ( & V_14 -> V_22 , L_109 ) ;
V_75 = - V_165 ;
if ( F_197 ( V_408 ) )
goto V_413;
}
if ( F_1 ( V_7 -> V_2 ) )
V_75 = F_61 ( V_7 , V_71 , V_399 ) ;
else if ( F_197 ( V_408 ) || F_196 ( V_14 ) > 0 )
V_75 = F_19 ( V_7 -> V_2 , V_71 ,
V_414 ) ;
else {
V_409 = false ;
V_75 = 0 ;
}
if ( V_75 ) {
F_21 ( V_7 -> V_113 , L_110 ,
V_71 , V_75 ) ;
F_200 ( V_14 ) ;
V_413:
F_193 ( V_14 ) ;
V_412:
if ( V_14 -> V_415 == 1 )
F_198 ( V_14 , 1 ) ;
if ( V_14 -> V_407 )
( void ) F_195 ( V_14 ) ;
V_410:
if ( ! F_197 ( V_408 ) )
V_75 = 0 ;
} else {
F_21 ( & V_14 -> V_22 , L_111 ,
( F_197 ( V_408 ) ? L_112 : L_39 ) ,
V_14 -> V_407 ) ;
if ( V_409 ) {
V_14 -> F_189 = 1 ;
F_59 ( 10 ) ;
}
F_65 ( V_14 , V_321 ) ;
}
if ( V_75 == 0 && ! V_14 -> V_407 && V_14 -> V_226 ) {
F_201 ( & V_159 -> V_22 ) ;
V_159 -> V_336 = true ;
}
F_168 ( V_7 -> V_2 ) ;
return V_75 ;
}
static int F_202 ( struct V_1 * V_14 )
{
int V_75 = 0 ;
T_1 V_416 = 0 ;
F_21 ( & V_14 -> V_22 , L_113 ,
V_14 -> V_227 ? L_114 : L_115 ) ;
F_65 ( V_14 , V_14 -> V_11
? V_83
: V_417 ) ;
if ( V_14 -> V_227 ) {
V_418:
if ( V_14 -> V_419 & V_420 )
V_75 = - V_112 ;
else
V_75 = F_203 ( V_14 ) ;
}
if ( V_75 == 0 ) {
V_416 = 0 ;
V_75 = F_90 ( V_14 , V_271 , 0 , & V_416 ) ;
if ( V_75 && ! V_14 -> V_227 && V_14 -> V_226 ) {
F_21 ( & V_14 -> V_22 , L_116 ) ;
V_14 -> V_227 = 1 ;
goto V_418;
}
}
if ( V_75 ) {
F_21 ( & V_14 -> V_22 , L_117 ,
V_75 ) ;
} else if ( V_14 -> V_11 && ! V_14 -> V_227 ) {
if ( V_14 -> V_15 < V_51 ) {
if ( V_416 & ( 1 << V_402 ) )
V_75 = F_195 ( V_14 ) ;
} else {
V_75 = F_90 ( V_14 , V_403 , 0 ,
& V_416 ) ;
if ( ! V_75 && V_416 & ( V_421
| V_422 ) )
V_75 = F_195 ( V_14 ) ;
}
if ( V_75 )
F_21 ( & V_14 -> V_22 ,
L_118 ,
V_75 ) ;
V_75 = 0 ;
}
return V_75 ;
}
int F_204 ( struct V_1 * V_14 , T_3 V_408 )
{
struct V_6 * V_7 = F_3 ( V_14 -> V_25 ) ;
struct V_158 * V_159 = V_7 -> V_160 [ V_14 -> V_124 - 1 ] ;
int V_71 = V_14 -> V_124 ;
int V_75 ;
T_1 V_182 , V_8 ;
if ( V_159 -> V_336 ) {
V_75 = F_166 ( & V_159 -> V_22 ) ;
V_159 -> V_336 = false ;
if ( V_75 < 0 ) {
F_21 ( & V_14 -> V_22 , L_119 ,
V_75 ) ;
return V_75 ;
}
}
V_75 = F_27 ( V_7 , V_71 , & V_8 , & V_182 ) ;
if ( V_75 == 0 && ! F_189 ( V_7 , V_8 ) )
goto V_423;
F_41 ( V_71 , V_7 -> V_424 ) ;
if ( F_1 ( V_7 -> V_2 ) )
V_75 = F_61 ( V_7 , V_71 , V_225 ) ;
else
V_75 = F_18 ( V_7 -> V_2 ,
V_71 , V_414 ) ;
if ( V_75 ) {
F_21 ( V_7 -> V_113 , L_120 ,
V_71 , V_75 ) ;
} else {
F_21 ( & V_14 -> V_22 , L_121 ,
( F_197 ( V_408 ) ? L_112 : L_39 ) ) ;
F_59 ( 25 ) ;
V_75 = F_27 ( V_7 , V_71 , & V_8 , & V_182 ) ;
F_59 ( 10 ) ;
}
V_423:
if ( V_75 == 0 ) {
V_14 -> F_189 = 0 ;
if ( F_1 ( V_7 -> V_2 ) ) {
if ( V_182 & V_425 )
F_18 ( V_7 -> V_2 , V_71 ,
V_390 ) ;
} else {
if ( V_182 & V_426 )
F_18 ( V_7 -> V_2 , V_71 ,
V_427 ) ;
}
}
F_73 ( V_71 , V_7 -> V_424 ) ;
V_75 = F_190 ( V_14 ,
V_7 , V_71 , V_75 , V_182 , V_8 ) ;
if ( V_75 == 0 )
V_75 = F_202 ( V_14 ) ;
if ( V_75 < 0 ) {
F_21 ( & V_14 -> V_22 , L_122 , V_75 ) ;
F_66 ( V_7 , V_71 ) ;
} else {
if ( V_14 -> V_415 == 1 )
F_198 ( V_14 , 1 ) ;
F_193 ( V_14 ) ;
F_200 ( V_14 ) ;
}
return V_75 ;
}
int F_205 ( struct V_1 * V_14 )
{
int V_75 = 0 ;
if ( V_14 -> V_82 == V_321 ) {
F_21 ( & V_14 -> V_22 , L_121 , L_123 ) ;
V_75 = F_175 ( V_14 ) ;
if ( V_75 == 0 ) {
F_178 ( V_14 ) ;
}
}
return V_75 ;
}
static int F_206 ( struct V_6 * V_7 )
{
int V_71 ;
for ( V_71 = 1 ; V_71 <= V_7 -> V_2 -> V_12 ; ++ V_71 ) {
T_1 V_8 , V_182 ;
int V_75 ;
V_75 = F_27 ( V_7 , V_71 , & V_8 , & V_182 ) ;
if ( ! V_75 && V_182 )
return 1 ;
}
return 0 ;
}
static int F_207 ( struct V_193 * V_194 , T_3 V_408 )
{
struct V_6 * V_7 = F_4 ( V_194 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
unsigned V_71 ;
int V_75 ;
V_7 -> F_196 = 0 ;
for ( V_71 = 1 ; V_71 <= V_2 -> V_12 ; V_71 ++ ) {
struct V_1 * V_14 ;
V_14 = V_7 -> V_160 [ V_71 - 1 ] -> V_189 ;
if ( V_14 && V_14 -> V_428 ) {
F_63 ( & V_194 -> V_22 , L_124 ,
V_71 ) ;
if ( F_197 ( V_408 ) )
return - V_319 ;
}
if ( V_14 )
V_7 -> F_196 +=
F_196 ( V_14 ) ;
}
if ( V_2 -> V_407 && V_7 -> V_305 ) {
if ( F_206 ( V_7 ) ) {
if ( F_197 ( V_408 ) )
return - V_319 ;
F_208 ( & V_2 -> V_22 , 2000 ) ;
}
}
if ( F_1 ( V_2 ) && V_2 -> V_407 ) {
for ( V_71 = 1 ; V_71 <= V_2 -> V_12 ; V_71 ++ ) {
V_75 = F_19 ( V_2 ,
V_71 |
V_429 |
V_430 |
V_431 ,
V_432 ) ;
}
}
F_21 ( & V_194 -> V_22 , L_113 , V_114 ) ;
F_76 ( V_7 , V_233 ) ;
return 0 ;
}
static int F_209 ( struct V_193 * V_194 )
{
struct V_6 * V_7 = F_4 ( V_194 ) ;
F_21 ( & V_194 -> V_22 , L_113 , V_114 ) ;
F_70 ( V_7 , V_203 ) ;
return 0 ;
}
static int F_210 ( struct V_193 * V_194 )
{
struct V_6 * V_7 = F_4 ( V_194 ) ;
F_21 ( & V_194 -> V_22 , L_113 , V_114 ) ;
F_70 ( V_7 , V_210 ) ;
return 0 ;
}
void F_211 ( struct V_1 * V_433 )
{
F_63 ( & V_433 -> V_22 , L_125 ) ;
V_433 -> V_227 = 1 ;
}
static int F_212 ( struct V_1 * V_14 , enum V_434 V_82 )
{
struct V_435 * V_436 ;
unsigned long long V_437 ;
unsigned long long V_438 ;
unsigned long long V_439 ;
unsigned long long V_440 ;
int V_56 ;
if ( V_14 -> V_82 != V_83 )
return 0 ;
V_437 = F_213 ( V_14 -> V_52 . V_45 , 1000 ) ;
V_438 = F_213 ( V_14 -> V_52 . V_42 , 1000 ) ;
V_439 = F_213 ( V_14 -> V_53 . V_45 , 1000 ) ;
V_440 = F_213 ( V_14 -> V_53 . V_42 , 1000 ) ;
if ( ( V_82 == V_441 &&
( V_437 > V_442 ||
V_438 > V_442 ) ) ||
( V_82 == V_443 &&
( V_439 > V_444 ||
V_440 > V_444 ) ) ) {
F_21 ( & V_14 -> V_22 , L_126 ,
V_445 [ V_82 ] , V_437 , V_438 ) ;
return - V_68 ;
}
if ( V_437 > V_442 )
V_437 = V_442 ;
if ( V_438 > V_442 )
V_438 = V_442 ;
if ( V_439 > V_444 )
V_439 = V_444 ;
if ( V_440 > V_444 )
V_440 = V_444 ;
V_436 = F_51 ( sizeof *( V_436 ) , V_212 ) ;
if ( ! V_436 )
return - V_165 ;
V_436 -> V_437 = V_437 ;
V_436 -> V_438 = V_438 ;
V_436 -> V_439 = F_214 ( V_439 ) ;
V_436 -> V_440 = F_214 ( V_440 ) ;
V_56 = F_14 ( V_14 , F_17 ( V_14 , 0 ) ,
V_446 ,
V_271 ,
0 , 0 ,
V_436 , sizeof *( V_436 ) ,
V_206 ) ;
F_48 ( V_436 ) ;
return V_56 ;
}
static int F_215 ( struct V_1 * V_14 ,
enum V_434 V_82 , bool V_447 )
{
int V_56 ;
int V_69 ;
switch ( V_82 ) {
case V_441 :
V_69 = V_448 ;
break;
case V_443 :
V_69 = V_449 ;
break;
default:
F_63 ( & V_14 -> V_22 , L_127 ,
V_114 , V_447 ? L_128 : L_129 ) ;
return - V_68 ;
}
if ( V_14 -> V_82 != V_83 ) {
F_21 ( & V_14 -> V_22 , L_130
L_131 ,
V_114 , V_447 ? L_128 : L_129 ,
V_445 [ V_82 ] ) ;
return 0 ;
}
if ( V_447 ) {
V_56 = F_14 ( V_14 , F_17 ( V_14 , 0 ) ,
V_73 ,
V_271 ,
V_69 ,
0 , NULL , 0 ,
V_206 ) ;
} else {
V_56 = F_14 ( V_14 , F_17 ( V_14 , 0 ) ,
V_70 ,
V_271 ,
V_69 ,
0 , NULL , 0 ,
V_206 ) ;
}
if ( V_56 < 0 ) {
F_63 ( & V_14 -> V_22 , L_132 ,
V_447 ? L_133 : L_134 ,
V_445 [ V_82 ] ) ;
return - V_319 ;
}
return 0 ;
}
static int F_216 ( struct V_1 * V_14 ,
enum V_434 V_82 , int V_450 )
{
int V_56 ;
int V_69 ;
switch ( V_82 ) {
case V_441 :
V_69 = V_451 ;
break;
case V_443 :
V_69 = V_452 ;
break;
default:
F_63 ( & V_14 -> V_22 , L_135 ,
V_114 ) ;
return - V_68 ;
}
if ( V_82 == V_441 && V_450 > V_453 &&
V_450 != V_454 ) {
F_63 ( & V_14 -> V_22 , L_136
L_137 ,
V_445 [ V_82 ] , V_450 ) ;
return - V_68 ;
}
V_56 = F_19 ( V_14 -> V_25 ,
F_217 ( V_450 ) | V_14 -> V_124 ,
V_69 ) ;
if ( V_56 < 0 ) {
F_63 ( & V_14 -> V_22 , L_138
L_139 , V_445 [ V_82 ] ,
V_450 , V_56 ) ;
return - V_319 ;
}
if ( V_82 == V_441 )
V_14 -> V_52 . V_450 = V_450 ;
else
V_14 -> V_53 . V_450 = V_450 ;
return 0 ;
}
static void F_218 ( struct V_197 * V_153 , struct V_1 * V_14 ,
enum V_434 V_82 )
{
int V_450 , V_56 ;
T_4 V_455 = V_14 -> V_17 -> V_21 -> V_23 ;
T_5 V_456 = V_14 -> V_17 -> V_21 -> V_24 ;
if ( ( V_82 == V_441 && V_455 == 0 ) ||
( V_82 == V_443 && V_456 == 0 ) )
return;
V_56 = F_212 ( V_14 , V_82 ) ;
if ( V_56 < 0 ) {
F_63 ( & V_14 -> V_22 , L_140 ,
V_445 [ V_82 ] ) ;
return;
}
V_450 = V_153 -> V_154 -> V_457 ( V_153 , V_14 , V_82 ) ;
if ( V_450 == 0 )
return;
if ( V_450 < 0 ) {
F_63 ( & V_14 -> V_22 , L_141
L_142 , V_445 [ V_82 ] ,
V_450 ) ;
return;
}
if ( F_216 ( V_14 , V_82 , V_450 ) )
V_153 -> V_154 -> V_458 ( V_153 , V_14 , V_82 ) ;
else if ( V_14 -> V_11 )
F_215 ( V_14 , V_82 , true ) ;
}
static int F_219 ( struct V_197 * V_153 , struct V_1 * V_14 ,
enum V_434 V_82 )
{
int V_69 ;
switch ( V_82 ) {
case V_441 :
V_69 = V_451 ;
break;
case V_443 :
V_69 = V_452 ;
break;
default:
F_63 ( & V_14 -> V_22 , L_143 ,
V_114 ) ;
return - V_68 ;
}
if ( F_216 ( V_14 , V_82 , 0 ) )
return - V_319 ;
F_215 ( V_14 , V_82 , false ) ;
if ( V_153 -> V_154 -> V_458 ( V_153 , V_14 , V_82 ) )
F_63 ( & V_14 -> V_22 , L_144
L_145 ,
V_445 [ V_82 ] ) ;
return 0 ;
}
int F_220 ( struct V_1 * V_14 )
{
struct V_197 * V_153 ;
if ( ! V_14 || ! V_14 -> V_25 ||
V_14 -> V_15 != V_51 ||
! V_14 -> V_26 )
return 0 ;
V_153 = F_55 ( V_14 -> V_170 ) ;
if ( ! V_153 || ! V_153 -> V_154 -> V_458 )
return 0 ;
V_14 -> V_459 ++ ;
if ( ( V_14 -> V_52 . V_450 == 0 && V_14 -> V_53 . V_450 == 0 ) )
return 0 ;
if ( F_219 ( V_153 , V_14 , V_441 ) )
goto V_460;
if ( F_219 ( V_153 , V_14 , V_443 ) )
goto V_460;
return 0 ;
V_460:
F_221 ( V_14 ) ;
return - V_319 ;
}
int F_199 ( struct V_1 * V_14 )
{
struct V_197 * V_153 = F_55 ( V_14 -> V_170 ) ;
int V_56 ;
if ( ! V_153 )
return - V_68 ;
F_28 ( V_153 -> V_461 ) ;
V_56 = F_220 ( V_14 ) ;
F_30 ( V_153 -> V_461 ) ;
return V_56 ;
}
void F_221 ( struct V_1 * V_14 )
{
struct V_197 * V_153 ;
if ( ! V_14 || ! V_14 -> V_25 ||
V_14 -> V_15 != V_51 ||
! V_14 -> V_26 )
return;
V_14 -> V_459 -- ;
V_153 = F_55 ( V_14 -> V_170 ) ;
if ( ! V_153 || ! V_153 -> V_154 -> V_457 ||
! V_153 -> V_154 -> V_458 )
return;
if ( V_14 -> V_459 > 0 )
return;
F_218 ( V_153 , V_14 , V_441 ) ;
F_218 ( V_153 , V_14 , V_443 ) ;
}
void F_200 ( struct V_1 * V_14 )
{
struct V_197 * V_153 = F_55 ( V_14 -> V_170 ) ;
if ( ! V_153 )
return;
F_28 ( V_153 -> V_461 ) ;
F_221 ( V_14 ) ;
F_30 ( V_153 -> V_461 ) ;
}
int F_220 ( struct V_1 * V_14 )
{
return 0 ;
}
void F_221 ( struct V_1 * V_14 ) { }
int F_199 ( struct V_1 * V_14 )
{
return 0 ;
}
void F_200 ( struct V_1 * V_14 ) { }
int F_191 ( struct V_1 * V_14 )
{
return 0 ;
}
void F_193 ( struct V_1 * V_14 ) { }
int F_222 ( struct V_6 * V_7 , int V_71 , bool V_462 )
{
int V_56 ;
int V_181 , V_463 = 0 ;
T_1 V_182 , V_8 ;
unsigned V_464 = 0xffff ;
for ( V_181 = 0 ; ; V_181 += V_184 ) {
V_56 = F_27 ( V_7 , V_71 , & V_8 , & V_182 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( ! ( V_182 & V_215 ) &&
( V_8 & V_213 ) == V_464 ) {
if ( ! V_462 ||
( V_464 == V_213 ) )
V_463 += V_184 ;
if ( V_463 >= V_228 )
break;
} else {
V_463 = 0 ;
V_464 = V_8 & V_213 ;
}
if ( V_182 & V_215 ) {
F_18 ( V_7 -> V_2 , V_71 ,
V_216 ) ;
}
if ( V_181 >= V_186 )
break;
F_59 ( V_184 ) ;
}
F_21 ( V_7 -> V_113 ,
L_146 ,
V_71 , V_181 , V_463 , V_8 ) ;
if ( V_463 < V_228 )
return - V_103 ;
return V_8 ;
}
void F_223 ( struct V_1 * V_14 )
{
F_224 ( V_14 , 0 + V_64 , true ) ;
F_224 ( V_14 , 0 + V_465 , true ) ;
F_225 ( V_14 , & V_14 -> V_337 , true ) ;
}
static int F_226 ( struct V_1 * V_14 , int V_168 )
{
int V_466 ;
struct V_197 * V_153 = F_55 ( V_14 -> V_170 ) ;
if ( ! V_153 -> V_154 -> V_467 && V_168 <= 1 )
return - V_68 ;
if ( V_14 -> V_82 == V_417 )
return 0 ;
if ( V_14 -> V_82 != V_391 )
return - V_68 ;
if ( V_153 -> V_154 -> V_467 )
V_466 = V_153 -> V_154 -> V_467 ( V_153 , V_14 ) ;
else
V_466 = F_14 ( V_14 , F_227 () ,
V_468 , 0 , V_168 , 0 ,
NULL , 0 , V_206 ) ;
if ( V_466 == 0 ) {
F_131 ( V_14 , V_168 ) ;
F_65 ( V_14 , V_417 ) ;
F_223 ( V_14 ) ;
}
return V_466 ;
}
static void F_228 ( struct V_1 * V_14 )
{
int V_469 ;
if ( ! V_14 -> V_415 )
return;
V_469 = F_229 ( V_14 -> V_25 ,
V_14 -> V_124 ) ;
if ( ( V_14 -> V_17 -> V_18 -> V_20 & F_230 ( V_470 ) ) ||
V_469 == V_471 ) {
V_14 -> V_472 = 1 ;
F_198 ( V_14 , 1 ) ;
}
}
static int F_231 ( struct V_1 * V_14 )
{
struct V_197 * V_153 = F_55 ( V_14 -> V_170 ) ;
if ( ! V_153 -> V_154 -> V_473 )
return 0 ;
if ( V_14 -> V_82 == V_417 )
return 0 ;
if ( V_14 -> V_82 != V_391 )
return - V_68 ;
return V_153 -> V_154 -> V_473 ( V_153 , V_14 ) ;
}
static int
F_232 ( struct V_6 * V_7 , struct V_1 * V_14 , int V_71 ,
int V_474 )
{
static F_233 ( V_475 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_197 * V_153 = F_55 ( V_2 -> V_170 ) ;
int V_55 , V_476 , V_466 ;
unsigned V_174 = V_383 ;
enum V_477 V_478 = V_14 -> V_15 ;
const char * V_15 ;
int V_168 = V_14 -> V_168 ;
if ( ! V_2 -> V_25 ) {
V_174 = V_479 ;
if ( V_71 == V_2 -> V_170 -> V_354 )
V_2 -> V_170 -> V_355 = 0 ;
}
if ( V_478 == V_387 )
V_174 = V_384 ;
F_28 ( & V_475 ) ;
V_466 = F_185 ( V_7 , V_71 , V_14 , V_174 , false ) ;
if ( V_466 < 0 )
goto V_247;
V_466 = - V_112 ;
if ( V_478 != V_480 && V_478 != V_14 -> V_15 ) {
F_21 ( & V_14 -> V_22 , L_147 ) ;
goto V_247;
}
V_478 = V_14 -> V_15 ;
switch ( V_14 -> V_15 ) {
case V_51 :
case V_386 :
V_14 -> V_337 . V_280 . V_481 = F_214 ( 512 ) ;
break;
case V_16 :
V_14 -> V_337 . V_280 . V_481 = F_214 ( 64 ) ;
break;
case V_388 :
V_14 -> V_337 . V_280 . V_481 = F_214 ( 64 ) ;
break;
case V_387 :
V_14 -> V_337 . V_280 . V_481 = F_214 ( 8 ) ;
break;
default:
goto V_247;
}
if ( V_14 -> V_15 == V_386 )
V_15 = L_148 ;
else
V_15 = F_234 ( V_14 -> V_15 ) ;
if ( V_14 -> V_15 != V_51 )
F_7 ( & V_14 -> V_22 ,
L_149 ,
( V_14 -> V_348 ) ? L_150 : L_151 , V_15 ,
V_168 , V_14 -> V_170 -> V_482 -> V_154 -> V_483 ) ;
if ( V_2 -> V_140 ) {
V_14 -> V_140 = V_2 -> V_140 ;
V_14 -> V_167 = V_2 -> V_167 ;
} else if ( V_14 -> V_15 != V_16
&& V_2 -> V_15 == V_16 ) {
if ( ! V_7 -> V_140 . V_7 ) {
F_29 ( & V_14 -> V_22 , L_152 ) ;
V_466 = - V_68 ;
goto V_247;
}
V_14 -> V_140 = & V_7 -> V_140 ;
V_14 -> V_167 = V_71 ;
}
for ( V_55 = 0 ; V_55 < V_484 ; ( ++ V_55 , F_59 ( 100 ) ) ) {
bool V_485 = false ;
if ( F_180 ( V_14 , V_474 ) ) {
struct V_486 * V_487 ;
int V_488 = 0 ;
V_485 = true ;
V_466 = F_231 ( V_14 ) ;
if ( V_466 < 0 ) {
F_29 ( & V_14 -> V_22 ,
L_153 ,
V_466 ) ;
goto V_247;
}
#define F_235 64
V_487 = F_51 ( F_235 , V_212 ) ;
if ( ! V_487 ) {
V_466 = - V_165 ;
continue;
}
for ( V_476 = 0 ; V_476 < 3 ; ++ V_476 ) {
V_487 -> V_489 = 0 ;
V_488 = F_14 ( V_14 , F_236 () ,
V_63 , V_64 ,
V_490 << 8 , 0 ,
V_487 , F_235 ,
V_491 ) ;
switch ( V_487 -> V_489 ) {
case 8 : case 16 : case 32 : case 64 : case 255 :
if ( V_487 -> V_492 ==
V_490 ) {
V_488 = 0 ;
break;
}
default:
if ( V_488 == 0 )
V_488 = - V_493 ;
break;
}
if ( V_488 == 0 )
break;
}
V_14 -> V_3 . V_489 =
V_487 -> V_489 ;
F_48 ( V_487 ) ;
V_466 = F_185 ( V_7 , V_71 , V_14 , V_174 , false ) ;
if ( V_466 < 0 )
goto V_247;
if ( V_478 != V_14 -> V_15 ) {
F_21 ( & V_14 -> V_22 ,
L_147 ) ;
V_466 = - V_112 ;
goto V_247;
}
if ( V_488 ) {
if ( V_488 != - V_112 )
F_29 ( & V_14 -> V_22 , L_154 ,
V_488 ) ;
V_466 = - V_494 ;
continue;
}
#undef F_235
}
if ( V_14 -> V_329 == 0 ) {
for ( V_476 = 0 ; V_476 < V_495 ; ++ V_476 ) {
V_466 = F_226 ( V_14 , V_168 ) ;
if ( V_466 >= 0 )
break;
F_59 ( 200 ) ;
}
if ( V_466 < 0 ) {
if ( V_466 != - V_112 )
F_29 ( & V_14 -> V_22 , L_155 ,
V_168 , V_466 ) ;
goto V_247;
}
if ( V_14 -> V_15 == V_51 ) {
V_168 = V_14 -> V_168 ;
F_7 ( & V_14 -> V_22 ,
L_156 ,
( V_14 -> V_348 ) ? L_150 : L_151 ,
V_168 , V_14 -> V_170 -> V_482 -> V_154 -> V_483 ) ;
}
F_59 ( 10 ) ;
if ( V_485 )
break;
}
V_466 = F_176 ( V_14 , 8 ) ;
if ( V_466 < 8 ) {
if ( V_466 != - V_112 )
F_29 ( & V_14 -> V_22 ,
L_157 ,
V_466 ) ;
if ( V_466 >= 0 )
V_466 = - V_494 ;
} else {
V_466 = 0 ;
break;
}
}
if ( V_466 )
goto V_247;
if ( V_153 -> V_496 && ! V_2 -> V_25 )
F_237 ( V_153 -> V_496 , V_14 -> V_15 ) ;
if ( ( V_14 -> V_15 == V_51 ) &&
( F_12 ( V_14 -> V_3 . V_497 ) < 0x0300 ) ) {
F_29 ( & V_14 -> V_22 , L_158
L_159 ) ;
F_185 ( V_7 , V_71 , V_14 ,
V_498 , true ) ;
V_466 = - V_68 ;
goto V_247;
}
if ( V_14 -> V_3 . V_489 == 0xff ||
V_14 -> V_15 == V_51 )
V_55 = 512 ;
else
V_55 = V_14 -> V_3 . V_489 ;
if ( F_238 ( & V_14 -> V_337 . V_280 ) != V_55 ) {
if ( V_14 -> V_15 == V_387 ||
! ( V_55 == 8 || V_55 == 16 || V_55 == 32 || V_55 == 64 ) ) {
F_29 ( & V_14 -> V_22 , L_160 , V_55 ) ;
V_466 = - V_494 ;
goto V_247;
}
if ( V_14 -> V_15 == V_388 )
F_21 ( & V_14 -> V_22 , L_161 , V_55 ) ;
else
F_63 ( & V_14 -> V_22 , L_162 , V_55 ) ;
V_14 -> V_337 . V_280 . V_481 = F_214 ( V_55 ) ;
F_223 ( V_14 ) ;
}
V_466 = F_176 ( V_14 , V_499 ) ;
if ( V_466 < ( signed ) sizeof( V_14 -> V_3 ) ) {
if ( V_466 != - V_112 )
F_29 ( & V_14 -> V_22 , L_163 ,
V_466 ) ;
if ( V_466 >= 0 )
V_466 = - V_500 ;
goto V_247;
}
if ( V_14 -> V_329 == 0 && F_12 ( V_14 -> V_3 . V_497 ) >= 0x0201 ) {
V_466 = F_239 ( V_14 ) ;
if ( ! V_466 ) {
V_14 -> V_26 = F_5 ( V_14 ) ;
F_11 ( V_14 ) ;
}
}
V_466 = 0 ;
if ( V_153 -> V_154 -> V_501 )
V_153 -> V_154 -> V_501 ( V_153 , V_14 ) ;
F_228 ( V_14 ) ;
V_247:
if ( V_466 ) {
F_64 ( V_7 , V_71 , 0 ) ;
F_131 ( V_14 , V_168 ) ;
}
F_30 ( & V_475 ) ;
return V_466 ;
}
static void
F_240 ( struct V_6 * V_7 , struct V_1 * V_14 , int V_71 )
{
struct V_502 * V_503 ;
int V_75 ;
V_503 = F_51 ( sizeof *V_503 , V_246 ) ;
if ( V_503 == NULL )
return;
V_75 = F_241 ( V_14 , V_504 , 0 ,
V_503 , sizeof *V_503 ) ;
if ( V_75 == sizeof *V_503 ) {
F_7 ( & V_14 -> V_22 , L_164
L_165 ) ;
if ( V_7 -> V_230 ) {
V_7 -> V_86 [ V_71 - 1 ] = V_90 ;
F_24 ( V_100 ,
& V_7 -> V_79 , 0 ) ;
}
}
F_48 ( V_503 ) ;
}
static unsigned
F_242 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_278 ;
int V_71 ;
if ( ! V_7 -> V_276 )
return 0 ;
V_278 = V_2 -> V_274 - V_7 -> V_3 -> V_279 ;
for ( V_71 = 1 ; V_71 <= V_2 -> V_12 ; ++ V_71 ) {
struct V_1 * V_14 = V_7 -> V_160 [ V_71 - 1 ] -> V_189 ;
int V_505 ;
unsigned V_244 ;
if ( ! V_14 )
continue;
if ( F_1 ( V_14 ) )
V_244 = 150 ;
else
V_244 = 100 ;
if ( V_14 -> V_11 )
V_505 = F_243 ( V_14 , V_14 -> V_11 ) ;
else if ( V_71 != V_14 -> V_170 -> V_354 || V_2 -> V_25 )
V_505 = V_244 ;
else
V_505 = 8 ;
if ( V_505 > V_7 -> V_275 )
F_63 ( & V_14 -> V_22 ,
L_166 ,
V_505 , V_7 -> V_275 , V_71 ) ;
V_278 -= V_505 ;
}
if ( V_278 < 0 ) {
F_63 ( V_7 -> V_113 , L_167 ,
- V_278 ) ;
V_278 = 0 ;
}
return V_278 ;
}
static void F_244 ( struct V_6 * V_7 , int V_71 ,
T_1 V_8 , T_1 V_182 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_238 * V_239 = V_7 -> V_113 ;
struct V_197 * V_153 = F_55 ( V_2 -> V_170 ) ;
unsigned V_175 =
F_12 ( V_7 -> V_3 -> V_175 ) ;
struct V_1 * V_14 ;
int V_75 , V_55 ;
unsigned V_244 ;
F_21 ( V_239 ,
L_168 ,
V_71 , V_8 , V_182 , F_2 ( V_7 , V_8 ) ) ;
if ( V_7 -> V_230 ) {
F_20 ( V_7 , V_71 , V_88 ) ;
V_7 -> V_86 [ V_71 - 1 ] = V_89 ;
}
#ifdef F_145
if ( V_2 -> V_170 -> V_347 )
V_182 &= ~ ( V_215 |
V_217 ) ;
#endif
V_14 = V_7 -> V_160 [ V_71 - 1 ] -> V_189 ;
if ( ( V_8 & V_213 ) && V_14 &&
V_14 -> V_82 != V_190 ) {
F_133 ( V_14 ) ;
if ( V_8 & V_214 ) {
V_75 = 0 ;
#ifdef F_245
} else if ( V_14 -> V_82 == V_321 &&
V_14 -> V_226 ) {
V_75 = F_205 ( V_14 ) ;
#endif
} else {
V_75 = - V_112 ;
}
F_139 ( V_14 ) ;
if ( V_75 == 0 ) {
F_73 ( V_71 , V_7 -> V_192 ) ;
return;
}
}
if ( V_14 ) {
if ( V_153 -> V_496 && ! V_2 -> V_25 &&
! ( V_8 & V_213 ) )
F_246 ( V_153 -> V_496 , V_14 -> V_15 ) ;
F_78 ( & V_7 -> V_160 [ V_71 - 1 ] -> V_189 ) ;
}
F_73 ( V_71 , V_7 -> V_192 ) ;
if ( ! ( V_8 & V_213 ) ||
( V_182 & V_215 ) )
F_73 ( V_71 , V_7 -> V_195 ) ;
if ( V_182 & ( V_215 |
V_217 ) ) {
V_75 = F_247 ( V_7 , V_71 ) ;
if ( V_75 < 0 ) {
if ( V_75 != - V_112 && F_248 () )
F_29 ( V_239 , L_169
L_170 , V_71 ) ;
V_8 &= ~ V_213 ;
} else {
V_8 = V_75 ;
}
}
if ( ! ( V_8 & V_213 ) ||
F_128 ( V_71 , V_7 -> V_195 ) ) {
if ( ( V_175 & V_176 ) < 2
&& ! F_188 ( V_7 , V_8 ) )
F_19 ( V_2 , V_71 , V_161 ) ;
if ( V_8 & V_214 )
goto V_393;
return;
}
if ( F_1 ( V_7 -> V_2 ) )
V_244 = 150 ;
else
V_244 = 100 ;
V_75 = 0 ;
for ( V_55 = 0 ; V_55 < V_506 ; V_55 ++ ) {
V_14 = F_249 ( V_2 , V_2 -> V_170 , V_71 ) ;
if ( ! V_14 ) {
F_29 ( V_239 ,
L_171 ,
V_71 ) ;
goto V_393;
}
F_65 ( V_14 , V_507 ) ;
V_14 -> V_274 = V_7 -> V_275 ;
V_14 -> V_205 = V_2 -> V_205 + 1 ;
V_14 -> V_329 = F_179 ( V_7 ) ;
if ( F_1 ( V_7 -> V_2 ) )
V_14 -> V_15 = V_51 ;
else
V_14 -> V_15 = V_480 ;
F_126 ( V_14 ) ;
if ( V_14 -> V_168 <= 0 ) {
V_75 = - V_385 ;
goto V_508;
}
V_75 = F_232 ( V_7 , V_14 , V_71 , V_55 ) ;
if ( V_75 < 0 )
goto V_508;
F_250 ( V_14 ) ;
if ( V_14 -> V_419 & V_509 )
F_59 ( 1000 ) ;
if ( V_14 -> V_3 . V_510 == V_511
&& V_14 -> V_274 <= V_244 ) {
T_1 V_512 ;
V_75 = F_90 ( V_14 , V_271 , 0 ,
& V_512 ) ;
if ( V_75 ) {
F_21 ( & V_14 -> V_22 , L_172 , V_75 ) ;
goto V_513;
}
if ( ( V_512 & ( 1 << V_277 ) ) == 0 ) {
F_29 ( & V_14 -> V_22 ,
L_173
L_174 ) ;
if ( V_7 -> V_230 ) {
V_7 -> V_86 [ V_71 - 1 ] =
V_94 ;
F_24 (
V_100 ,
& V_7 -> V_79 , 0 ) ;
}
V_75 = - V_385 ;
goto V_513;
}
}
if ( F_12 ( V_14 -> V_3 . V_497 ) >= 0x0200
&& V_14 -> V_15 == V_388
&& V_290 != 0 )
F_240 ( V_7 , V_14 , V_71 ) ;
V_75 = 0 ;
F_102 ( & V_289 ) ;
if ( V_2 -> V_82 == V_190 )
V_75 = - V_385 ;
else
V_7 -> V_160 [ V_71 - 1 ] -> V_189 = V_14 ;
F_105 ( & V_289 ) ;
if ( ! V_75 ) {
V_75 = F_154 ( V_14 ) ;
if ( V_75 ) {
F_102 ( & V_289 ) ;
V_7 -> V_160 [ V_71 - 1 ] -> V_189 = NULL ;
F_105 ( & V_289 ) ;
}
}
if ( V_75 )
goto V_513;
V_75 = F_242 ( V_7 ) ;
if ( V_75 )
F_21 ( V_239 , L_175 , V_75 ) ;
return;
V_513:
F_64 ( V_7 , V_71 , 1 ) ;
V_508:
F_223 ( V_14 ) ;
F_130 ( V_14 ) ;
F_132 ( V_14 ) ;
F_251 ( V_14 ) ;
if ( ( V_75 == - V_385 ) || ( V_75 == - V_359 ) )
break;
}
if ( V_7 -> V_2 -> V_25 ||
! V_153 -> V_154 -> V_514 ||
! ( V_153 -> V_154 -> V_514 ) ( V_153 , V_71 ) ) {
if ( V_75 != - V_385 && V_75 != - V_112 )
F_29 ( V_239 , L_176 ,
V_71 ) ;
}
V_393:
F_64 ( V_7 , V_71 , 1 ) ;
if ( V_153 -> V_154 -> V_515 && ! V_7 -> V_2 -> V_25 )
V_153 -> V_154 -> V_515 ( V_153 , V_71 ) ;
}
static int F_252 ( struct V_6 * V_7 , unsigned int V_111 ,
T_1 V_8 , T_1 V_182 )
{
struct V_1 * V_2 ;
struct V_1 * V_14 ;
int V_516 = 0 ;
int V_56 ;
V_2 = V_7 -> V_2 ;
V_14 = V_7 -> V_160 [ V_111 - 1 ] -> V_189 ;
if ( ! F_1 ( V_2 ) ) {
if ( ! ( V_182 & V_426 ) )
return 0 ;
F_18 ( V_2 , V_111 , V_427 ) ;
} else {
if ( ! V_14 || V_14 -> V_82 != V_321 ||
( V_8 & V_185 ) !=
V_225 )
return 0 ;
}
if ( V_14 ) {
F_59 ( 10 ) ;
F_133 ( V_14 ) ;
V_56 = F_205 ( V_14 ) ;
F_139 ( V_14 ) ;
if ( V_56 < 0 )
V_516 = 1 ;
} else {
V_56 = - V_112 ;
F_64 ( V_7 , V_111 , 1 ) ;
}
F_21 ( V_7 -> V_113 , L_177 ,
V_111 , V_56 ) ;
return V_516 ;
}
static void F_253 ( void )
{
struct V_147 * V_517 ;
struct V_1 * V_2 ;
struct V_193 * V_194 ;
struct V_6 * V_7 ;
struct V_238 * V_239 ;
T_1 V_240 ;
T_1 V_241 ;
T_1 V_8 ;
T_1 V_182 ;
int V_55 , V_56 ;
int V_516 , V_518 ;
while ( 1 ) {
F_102 ( & V_119 ) ;
if ( F_33 ( & V_122 ) ) {
F_105 ( & V_119 ) ;
break;
}
V_517 = V_122 . V_148 ;
F_103 ( V_517 ) ;
V_7 = F_46 ( V_517 , struct V_6 , V_121 ) ;
F_254 ( & V_7 -> V_287 ) ;
F_105 ( & V_119 ) ;
V_2 = V_7 -> V_2 ;
V_239 = V_7 -> V_113 ;
V_194 = F_36 ( V_239 ) ;
F_21 ( V_239 , L_178 ,
V_2 -> V_82 , V_2 -> V_12 ,
( T_1 ) V_7 -> V_192 [ 0 ] ,
( T_1 ) V_7 -> V_136 [ 0 ] ) ;
F_133 ( V_2 ) ;
if ( F_255 ( V_7 -> V_120 ) )
goto V_519;
if ( V_2 -> V_82 == V_190 ) {
V_7 -> error = - V_112 ;
F_76 ( V_7 , V_288 ) ;
goto V_508;
}
V_56 = F_68 ( V_194 ) ;
if ( V_56 ) {
F_21 ( V_239 , L_179 , V_56 ) ;
goto V_508;
}
if ( V_7 -> V_84 )
goto V_520;
if ( V_7 -> error ) {
F_21 ( V_239 , L_180 ,
V_7 -> error ) ;
V_56 = F_256 ( V_2 ) ;
if ( V_56 ) {
F_21 ( V_239 ,
L_181 , V_56 ) ;
goto V_520;
}
V_7 -> V_132 = 0 ;
V_7 -> error = 0 ;
}
for ( V_55 = 1 ; V_55 <= V_2 -> V_12 ; V_55 ++ ) {
struct V_1 * V_14 = V_7 -> V_160 [ V_55 - 1 ] -> V_189 ;
if ( F_128 ( V_55 , V_7 -> V_424 ) )
continue;
V_516 = F_128 ( V_55 , V_7 -> V_192 ) ;
V_518 = F_257 ( V_55 , V_7 -> V_125 ) ;
if ( ! F_257 ( V_55 , V_7 -> V_136 ) &&
! V_516 && ! V_518 )
continue;
V_56 = F_27 ( V_7 , V_55 ,
& V_8 , & V_182 ) ;
if ( V_56 < 0 )
continue;
if ( V_182 & V_215 ) {
F_18 ( V_2 , V_55 ,
V_216 ) ;
V_516 = 1 ;
}
if ( V_182 & V_217 ) {
if ( ! V_516 )
F_21 ( V_239 ,
L_182
L_183 ,
V_55 , V_8 ) ;
F_18 ( V_2 , V_55 ,
V_218 ) ;
if ( ! ( V_8 & V_214 )
&& ! V_516
&& V_7 -> V_160 [ V_55 - 1 ] -> V_189 ) {
F_29 ( V_239 ,
L_184
L_185
L_186 ,
V_55 ) ;
V_516 = 1 ;
}
}
if ( F_252 ( V_7 , V_55 ,
V_8 , V_182 ) )
V_516 = 1 ;
if ( V_182 & V_521 ) {
T_1 V_75 = 0 ;
T_1 V_522 ;
F_21 ( V_239 , L_187
L_188 , V_55 ) ;
F_18 ( V_2 , V_55 ,
V_523 ) ;
F_59 ( 100 ) ;
F_57 ( V_7 , true ) ;
F_27 ( V_7 , V_55 , & V_75 , & V_522 ) ;
if ( V_75 & V_223 )
F_29 ( V_239 , L_189
L_190 , V_55 ) ;
}
if ( V_182 & V_219 ) {
F_21 ( V_239 ,
L_191 ,
V_55 ) ;
F_18 ( V_2 , V_55 ,
V_220 ) ;
}
if ( ( V_182 & V_221 ) &&
F_1 ( V_7 -> V_2 ) ) {
F_21 ( V_239 ,
L_192 ,
V_55 ) ;
F_18 ( V_2 , V_55 ,
V_222 ) ;
}
if ( V_182 & V_425 ) {
F_18 ( V_7 -> V_2 , V_55 ,
V_390 ) ;
}
if ( V_182 & V_524 ) {
F_63 ( V_239 ,
L_193 ,
V_55 ) ;
F_18 ( V_7 -> V_2 , V_55 ,
V_525 ) ;
}
if ( F_182 ( V_7 , V_8 ) ) {
int V_75 ;
F_21 ( V_239 , L_194 , V_55 ) ;
if ( ! V_14 ||
! ( V_8 & V_213 ) ||
V_14 -> V_82 == V_190 ) {
V_75 = F_185 ( V_7 , V_55 ,
NULL , V_498 ,
true ) ;
if ( V_75 < 0 )
F_64 ( V_7 , V_55 , 1 ) ;
} else {
F_133 ( V_14 ) ;
V_75 = F_256 ( V_14 ) ;
F_139 ( V_14 ) ;
V_516 = 0 ;
}
} else if ( V_14 && F_1 ( V_7 -> V_2 ) &&
( V_182 & V_425 ) &&
( V_8 & V_213 ) ) {
F_133 ( V_14 ) ;
F_256 ( V_14 ) ;
F_139 ( V_14 ) ;
V_516 = 0 ;
}
if ( V_516 )
F_244 ( V_7 , V_55 ,
V_8 , V_182 ) ;
}
if ( F_257 ( 0 , V_7 -> V_136 ) == 0 )
;
else if ( F_60 ( V_7 , & V_240 , & V_241 ) < 0 )
F_29 ( V_239 , L_195 ) ;
else {
if ( V_241 & V_526 ) {
F_21 ( V_239 , L_196 ) ;
F_16 ( V_2 , V_527 ) ;
if ( V_240 & V_282 )
V_7 -> V_276 = 1 ;
else
V_7 -> V_276 = 0 ;
}
if ( V_241 & V_528 ) {
T_1 V_75 = 0 ;
T_1 V_522 ;
F_21 ( V_239 , L_197 ) ;
F_16 ( V_2 , V_529 ) ;
F_59 ( 500 ) ;
F_57 ( V_7 , true ) ;
F_60 ( V_7 , & V_75 , & V_522 ) ;
if ( V_75 & V_283 )
F_29 ( V_239 , L_189
L_198 ) ;
}
}
V_520:
F_104 ( V_194 ) ;
V_508:
F_69 ( V_194 ) ;
V_519:
F_139 ( V_2 ) ;
F_110 ( & V_7 -> V_287 , F_98 ) ;
}
}
static int F_258 ( void * V_530 )
{
F_259 () ;
do {
F_253 () ;
F_260 ( V_123 ,
! F_33 ( & V_122 ) ||
F_261 () ) ;
} while ( ! F_261 () || ! F_33 ( & V_122 ) );
F_262 ( L_199 , V_531 ) ;
return 0 ;
}
int F_263 ( void )
{
if ( F_264 ( & V_532 ) < 0 ) {
F_265 ( V_533 L_200 ,
V_531 ) ;
return - 1 ;
}
V_534 = F_266 ( F_258 , NULL , L_201 ) ;
if ( ! F_267 ( V_534 ) )
return 0 ;
F_268 ( & V_532 ) ;
F_265 ( V_533 L_202 , V_531 ) ;
return - 1 ;
}
void F_269 ( void )
{
F_270 ( V_534 ) ;
F_268 ( & V_532 ) ;
}
static int F_271 ( struct V_1 * V_14 ,
struct V_486 * V_535 ,
struct V_536 * V_537 )
{
int V_80 = 0 ;
unsigned V_538 ;
unsigned V_539 = 0 ;
unsigned V_540 ;
unsigned V_541 ;
int V_542 ;
char * V_487 ;
if ( memcmp ( & V_14 -> V_3 , V_535 ,
sizeof( * V_535 ) ) != 0 )
return 1 ;
if ( ( V_537 && ! V_14 -> V_17 ) || ( ! V_537 && V_14 -> V_17 ) )
return 1 ;
if ( V_14 -> V_17 ) {
V_540 = F_12 ( V_14 -> V_17 -> V_280 -> V_351 ) ;
if ( V_540 != F_12 ( V_537 -> V_280 -> V_351 ) )
return 1 ;
if ( memcmp ( V_14 -> V_17 -> V_280 , V_537 -> V_280 , V_540 ) )
return 1 ;
}
if ( V_14 -> V_345 )
V_539 = strlen ( V_14 -> V_345 ) + 1 ;
V_540 = V_539 ;
for ( V_538 = 0 ; V_538 < V_14 -> V_3 . V_543 ; V_538 ++ ) {
V_541 = F_12 ( V_14 -> V_348 [ V_538 ] . V_280 . V_351 ) ;
V_540 = F_58 ( V_540 , V_541 ) ;
}
V_487 = F_51 ( V_540 , V_212 ) ;
if ( V_487 == NULL ) {
F_29 ( & V_14 -> V_22 , L_203 ) ;
return 1 ;
}
for ( V_538 = 0 ; V_538 < V_14 -> V_3 . V_543 ; V_538 ++ ) {
V_541 = F_12 ( V_14 -> V_348 [ V_538 ] . V_280 . V_351 ) ;
V_542 = F_241 ( V_14 , V_544 , V_538 , V_487 ,
V_541 ) ;
if ( V_542 != V_541 ) {
F_21 ( & V_14 -> V_22 , L_204 ,
V_538 , V_542 ) ;
V_80 = 1 ;
break;
}
if ( memcmp ( V_487 , V_14 -> V_350 [ V_538 ] , V_541 )
!= 0 ) {
F_21 ( & V_14 -> V_22 , L_205 ,
V_538 ,
( (struct V_545 * ) V_487 ) ->
V_546 ) ;
V_80 = 1 ;
break;
}
}
if ( ! V_80 && V_539 ) {
V_542 = F_272 ( V_14 , V_14 -> V_3 . V_342 ,
V_487 , V_539 ) ;
if ( V_542 + 1 != V_539 ) {
F_21 ( & V_14 -> V_22 , L_206 ,
V_542 ) ;
V_80 = 1 ;
} else if ( memcmp ( V_487 , V_14 -> V_345 , V_542 ) != 0 ) {
F_21 ( & V_14 -> V_22 , L_207 ) ;
V_80 = 1 ;
}
}
F_48 ( V_487 ) ;
return V_80 ;
}
static int F_203 ( struct V_1 * V_14 )
{
struct V_1 * V_547 = V_14 -> V_25 ;
struct V_6 * V_548 ;
struct V_197 * V_153 = F_55 ( V_14 -> V_170 ) ;
struct V_486 V_3 = V_14 -> V_3 ;
struct V_536 * V_17 ;
int V_55 , V_476 , V_56 = 0 ;
int V_71 = V_14 -> V_124 ;
if ( V_14 -> V_82 == V_190 ||
V_14 -> V_82 == V_321 ) {
F_21 ( & V_14 -> V_22 , L_208 ,
V_14 -> V_82 ) ;
return - V_68 ;
}
if ( ! V_547 ) {
F_21 ( & V_14 -> V_22 , L_209 , V_114 ) ;
return - V_549 ;
}
V_548 = F_3 ( V_547 ) ;
if ( V_14 -> V_411 == 1 )
F_198 ( V_14 , 0 ) ;
V_17 = V_14 -> V_17 ;
V_14 -> V_17 = NULL ;
V_56 = F_199 ( V_14 ) ;
if ( V_56 ) {
F_29 ( & V_14 -> V_22 , L_210 , V_114 ) ;
goto V_550;
}
V_56 = F_191 ( V_14 ) ;
if ( V_56 ) {
F_29 ( & V_14 -> V_22 , L_211 ,
V_114 ) ;
goto V_550;
}
F_41 ( V_71 , V_548 -> V_424 ) ;
for ( V_55 = 0 ; V_55 < V_506 ; ++ V_55 ) {
F_223 ( V_14 ) ;
V_56 = F_232 ( V_548 , V_14 , V_71 , V_55 ) ;
if ( V_56 >= 0 || V_56 == - V_385 || V_56 == - V_112 )
break;
}
F_73 ( V_71 , V_548 -> V_424 ) ;
if ( V_56 < 0 )
goto V_550;
if ( F_271 ( V_14 , & V_3 , V_17 ) ) {
F_7 ( & V_14 -> V_22 , L_212 ) ;
V_14 -> V_3 = V_3 ;
goto V_550;
}
if ( ! V_14 -> V_11 )
goto V_393;
F_28 ( V_153 -> V_461 ) ;
V_56 = F_273 ( V_14 , V_14 -> V_11 , NULL , NULL ) ;
if ( V_56 < 0 ) {
F_63 ( & V_14 -> V_22 ,
L_213
L_214 ) ;
F_30 ( V_153 -> V_461 ) ;
goto V_550;
}
V_56 = F_14 ( V_14 , F_17 ( V_14 , 0 ) ,
V_551 , 0 ,
V_14 -> V_11 -> V_280 . V_546 , 0 ,
NULL , 0 , V_206 ) ;
if ( V_56 < 0 ) {
F_29 ( & V_14 -> V_22 ,
L_215 ,
V_14 -> V_11 -> V_280 . V_546 , V_56 ) ;
F_30 ( V_153 -> V_461 ) ;
goto V_550;
}
F_30 ( V_153 -> V_461 ) ;
F_65 ( V_14 , V_83 ) ;
for ( V_55 = 0 ; V_55 < V_14 -> V_11 -> V_280 . V_552 ; V_55 ++ ) {
struct V_553 * V_348 = V_14 -> V_11 ;
struct V_193 * V_194 = V_348 -> V_13 [ V_55 ] ;
struct V_554 * V_280 ;
V_280 = & V_194 -> V_294 -> V_280 ;
if ( V_280 -> V_555 == 0 ) {
F_274 ( V_14 , V_194 , true ) ;
F_275 ( V_14 , V_194 , true ) ;
V_56 = 0 ;
} else {
V_194 -> V_556 = 1 ;
V_56 = F_89 ( V_14 , V_280 -> V_557 ,
V_280 -> V_555 ) ;
V_194 -> V_556 = 0 ;
}
if ( V_56 < 0 ) {
F_29 ( & V_14 -> V_22 , L_216
L_217 ,
V_280 -> V_557 ,
V_280 -> V_555 ,
V_56 ) ;
goto V_550;
}
for ( V_476 = 0 ; V_476 < V_194 -> V_294 -> V_280 . V_301 ; V_476 ++ )
V_194 -> V_294 -> V_237 [ V_476 ] . V_558 = 0 ;
}
V_393:
F_198 ( V_14 , 1 ) ;
F_200 ( V_14 ) ;
F_193 ( V_14 ) ;
F_276 ( V_14 ) ;
V_14 -> V_17 = V_17 ;
return 0 ;
V_550:
F_66 ( V_548 , V_71 ) ;
F_276 ( V_14 ) ;
V_14 -> V_17 = V_17 ;
return - V_112 ;
}
int F_256 ( struct V_1 * V_14 )
{
int V_56 ;
int V_55 ;
unsigned int V_559 ;
struct V_553 * V_348 = V_14 -> V_11 ;
if ( V_14 -> V_82 == V_190 ||
V_14 -> V_82 == V_321 ) {
F_21 ( & V_14 -> V_22 , L_208 ,
V_14 -> V_82 ) ;
return - V_68 ;
}
V_559 = F_277 () ;
F_175 ( V_14 ) ;
if ( V_348 ) {
for ( V_55 = 0 ; V_55 < V_348 -> V_280 . V_552 ; ++ V_55 ) {
struct V_193 * V_560 = V_348 -> V_13 [ V_55 ] ;
struct V_561 * V_152 ;
int V_562 = 0 ;
if ( V_560 -> V_22 . V_154 ) {
V_152 = F_278 ( V_560 -> V_22 . V_154 ) ;
if ( V_152 -> V_563 && V_152 -> V_564 )
V_562 = ( V_152 -> V_563 ) ( V_560 ) ;
else if ( V_560 -> V_565 ==
V_566 )
V_562 = 1 ;
if ( V_562 )
F_279 ( V_560 ) ;
}
}
}
V_56 = F_203 ( V_14 ) ;
if ( V_348 ) {
for ( V_55 = V_348 -> V_280 . V_552 - 1 ; V_55 >= 0 ; -- V_55 ) {
struct V_193 * V_560 = V_348 -> V_13 [ V_55 ] ;
struct V_561 * V_152 ;
int V_567 = V_560 -> V_568 ;
if ( ! V_567 && V_560 -> V_22 . V_154 ) {
V_152 = F_278 ( V_560 -> V_22 . V_154 ) ;
if ( V_152 -> V_564 )
V_567 = ( V_152 -> V_564 ) ( V_560 ) ;
else if ( V_560 -> V_565 ==
V_566 )
V_567 = 1 ;
if ( V_567 )
V_560 -> V_568 = 1 ;
}
}
F_280 ( V_14 ) ;
}
F_178 ( V_14 ) ;
F_281 ( V_559 ) ;
return V_56 ;
}
void F_282 ( struct V_193 * V_569 )
{
F_56 ( & V_569 -> V_570 ) ;
}
struct V_1 * F_283 ( struct V_1 * V_2 ,
int V_71 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_71 < 1 || V_71 > V_2 -> V_12 )
return NULL ;
return V_7 -> V_160 [ V_71 - 1 ] -> V_189 ;
}
void F_284 ( struct V_1 * V_2 , int V_71 ,
enum V_571 type )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_7 )
V_7 -> V_160 [ V_71 - 1 ] -> V_469 = type ;
}
enum V_571
F_229 ( struct V_1 * V_2 , int V_71 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( ! V_7 )
return V_572 ;
return V_7 -> V_160 [ V_71 - 1 ] -> V_469 ;
}
void F_97 ( struct V_1 * V_2 ,
struct V_62 * V_280 )
{
enum V_571 V_469 ;
int V_55 ;
if ( ! F_1 ( V_2 ) ) {
for ( V_55 = 1 ; V_55 <= V_2 -> V_12 ; V_55 ++ ) {
V_469 = F_229 ( V_2 , V_55 ) ;
if ( V_469 == V_471 ) {
T_2 V_573 = 1 << ( V_55 % 8 ) ;
if ( ! ( V_280 -> V_36 . V_252 . V_253 [ V_55 / 8 ] & V_573 ) ) {
F_21 ( & V_2 -> V_22 , L_218 ,
V_55 ) ;
V_280 -> V_36 . V_252 . V_253 [ V_55 / 8 ] |= V_573 ;
}
}
}
} else {
T_1 V_574 = F_12 ( V_280 -> V_36 . V_37 . V_253 ) ;
for ( V_55 = 1 ; V_55 <= V_2 -> V_12 ; V_55 ++ ) {
V_469 = F_229 ( V_2 , V_55 ) ;
if ( V_469 == V_471 ) {
T_1 V_573 = 1 << V_55 ;
if ( ! ( V_574 & V_573 ) ) {
F_21 ( & V_2 -> V_22 , L_218 ,
V_55 ) ;
V_574 |= V_573 ;
}
}
}
V_280 -> V_36 . V_37 . V_253 = F_214 ( V_574 ) ;
}
}
T_6 F_285 ( struct V_1 * V_2 ,
int V_71 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( ! V_7 )
return NULL ;
return F_286 ( & V_7 -> V_160 [ V_71 - 1 ] -> V_22 ) ;
}
