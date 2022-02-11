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
F_28 ( V_7 -> V_112 ,
L_14 , V_113 , V_56 ) ;
if ( V_56 >= 0 )
V_56 = - V_114 ;
} else {
* V_75 = F_29 ( V_7 -> V_75 -> V_111 . V_115 ) ;
* V_109 = F_29 ( V_7 -> V_75 -> V_111 . V_116 ) ;
V_56 = 0 ;
}
F_30 ( & V_7 -> V_110 ) ;
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
&& V_75 != - V_137 && V_75 != - V_138 )
F_28 ( V_7 -> V_112 , L_16 , V_75 ) ;
}
static inline int
F_44 ( struct V_1 * V_2 , T_1 V_139 , T_1 V_140 )
{
return F_13 ( V_2 , F_16 ( V_2 , 0 ) ,
V_141 , V_72 , V_139 ,
V_140 , NULL , 0 , 1000 ) ;
}
static void F_45 ( struct V_77 * V_78 )
{
struct V_6 * V_7 =
F_22 ( V_78 , struct V_6 , V_140 . V_142 ) ;
unsigned long V_117 ;
F_32 ( & V_7 -> V_140 . V_143 , V_117 ) ;
while ( ! F_33 ( & V_7 -> V_140 . V_144 ) ) {
struct V_145 * V_146 ;
struct V_147 * V_148 ;
struct V_1 * V_2 = V_7 -> V_2 ;
const struct V_149 * V_150 ;
int V_75 ;
V_146 = V_7 -> V_140 . V_144 . V_146 ;
V_148 = F_46 ( V_146 , struct V_147 , V_144 ) ;
F_47 ( & V_148 -> V_144 ) ;
F_38 ( & V_7 -> V_140 . V_143 , V_117 ) ;
V_75 = F_44 ( V_2 , V_148 -> V_139 , V_148 -> V_140 ) ;
if ( V_75 )
F_28 ( & V_2 -> V_22 ,
L_17 ,
V_148 -> V_140 , V_148 -> V_139 , V_75 ) ;
V_150 = V_148 -> V_151 -> V_152 ;
if ( V_150 -> V_153 )
( V_150 -> V_153 ) ( V_148 -> V_151 , V_148 -> V_154 ) ;
F_48 ( V_148 ) ;
F_32 ( & V_7 -> V_140 . V_143 , V_117 ) ;
}
F_38 ( & V_7 -> V_140 . V_143 , V_117 ) ;
}
int F_49 ( struct V_1 * V_2 , int V_71 ,
bool V_155 )
{
int V_56 ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
struct V_156 * V_157 = V_7 -> V_158 [ V_71 - 1 ] ;
if ( V_155 )
V_56 = F_18 ( V_2 , V_71 , V_159 ) ;
else
V_56 = F_17 ( V_2 , V_71 , V_159 ) ;
if ( ! V_56 )
V_157 -> V_160 = V_155 ;
return V_56 ;
}
int F_50 ( struct V_125 * V_125 )
{
struct V_1 * V_14 = V_125 -> V_22 ;
int V_161 = V_125 -> V_161 ;
struct V_162 * V_140 = V_14 -> V_140 ;
unsigned long V_117 ;
struct V_147 * V_148 ;
if ( ( V_148 = F_51 ( sizeof *V_148 , V_136 ) ) == NULL ) {
F_28 ( & V_14 -> V_22 , L_18 ) ;
return - V_163 ;
}
V_148 -> V_140 = V_140 -> V_164 ? V_14 -> V_165 : 1 ;
V_148 -> V_139 = F_52 ( V_161 ) ;
V_148 -> V_139 |= V_14 -> V_166 << 4 ;
V_148 -> V_139 |= F_53 ( V_161 )
? ( V_167 << 11 )
: ( V_168 << 11 ) ;
if ( F_54 ( V_161 ) )
V_148 -> V_139 |= 1 << 15 ;
V_148 -> V_151 = F_55 ( V_14 -> V_169 ) ;
V_148 -> V_154 = V_125 -> V_154 ;
F_32 ( & V_140 -> V_143 , V_117 ) ;
F_34 ( & V_148 -> V_144 , & V_140 -> V_144 ) ;
F_56 ( & V_140 -> V_142 ) ;
F_38 ( & V_140 -> V_143 , V_117 ) ;
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
for ( V_71 = 1 ; V_71 <= V_7 -> V_3 -> V_85 ; V_71 ++ )
if ( V_7 -> V_158 [ V_71 - 1 ] -> V_160 )
F_18 ( V_7 -> V_2 , V_71 , V_159 ) ;
else
F_17 ( V_7 -> V_2 , V_71 ,
V_159 ) ;
V_173 = F_58 ( V_171 , ( unsigned ) 100 ) ;
if ( V_170 )
F_59 ( V_173 ) ;
return V_173 ;
}
static int F_60 ( struct V_6 * V_7 ,
T_1 * V_75 , T_1 * V_109 )
{
int V_56 ;
F_27 ( & V_7 -> V_110 ) ;
V_56 = F_24 ( V_7 -> V_2 , & V_7 -> V_75 -> V_7 ) ;
if ( V_56 < 0 )
F_28 ( V_7 -> V_112 ,
L_14 , V_113 , V_56 ) ;
else {
* V_75 = F_29 ( V_7 -> V_75 -> V_7 . V_176 ) ;
* V_109 = F_29 ( V_7 -> V_75 -> V_7 . V_177 ) ;
V_56 = 0 ;
}
F_30 ( & V_7 -> V_110 ) ;
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
if ( V_56 ) {
F_28 ( V_7 -> V_112 , L_22 ,
V_71 , V_56 ) ;
return V_56 ;
}
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
F_7 ( V_7 -> V_112 , L_23 ,
V_71 , V_180 ) ;
return F_61 ( V_7 , V_71 , V_186 ) ;
}
static int F_63 ( struct V_6 * V_7 , int V_71 , int V_187 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_56 = 0 ;
if ( V_7 -> V_158 [ V_71 - 1 ] -> V_188 && V_187 )
F_64 ( V_7 -> V_158 [ V_71 - 1 ] -> V_188 ,
V_189 ) ;
if ( ! V_7 -> error ) {
if ( F_1 ( V_7 -> V_2 ) )
V_56 = F_62 ( V_7 , V_71 ) ;
else
V_56 = F_17 ( V_2 , V_71 ,
V_190 ) ;
}
if ( V_56 )
F_28 ( V_7 -> V_112 , L_22 ,
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
struct V_196 * V_151 ;
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
V_151 = F_55 ( V_2 -> V_169 ) ;
if ( V_151 -> V_152 -> V_210 ) {
V_56 = V_151 -> V_152 -> V_210 ( V_151 , V_2 ,
& V_7 -> V_140 , V_211 ) ;
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
struct V_1 * V_14 = V_7 -> V_158 [ V_71 - 1 ] -> V_188 ;
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
struct V_156 * V_157 = V_7 -> V_158 [ V_71 - 1 ] ;
#ifdef F_73
V_14 -> V_223 = 1 ;
#endif
if ( V_157 -> V_160 )
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
if ( V_7 -> V_226 && V_100 )
F_23 ( & V_7 -> V_79 , V_101 ) ;
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
if ( V_7 -> V_158 [ V_55 ] -> V_188 )
F_77 ( & V_7 -> V_158 [ V_55 ] -> V_188 ) ;
}
}
F_78 ( V_7 -> V_125 ) ;
if ( V_7 -> V_226 )
F_76 ( & V_7 -> V_79 ) ;
if ( V_7 -> V_140 . V_7 )
F_79 ( & V_7 -> V_140 . V_142 ) ;
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
struct V_196 * V_151 ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_234 * V_235 = V_7 -> V_112 ;
T_1 V_236 , V_237 ;
T_1 V_174 ;
unsigned int V_161 ;
int V_238 , V_56 , V_55 ;
char * V_239 = L_34 ;
unsigned V_240 ;
unsigned V_241 ;
V_7 -> V_134 = F_51 ( sizeof( * V_7 -> V_134 ) , V_242 ) ;
if ( ! V_7 -> V_134 ) {
V_56 = - V_163 ;
goto V_243;
}
V_7 -> V_75 = F_51 ( sizeof( * V_7 -> V_75 ) , V_242 ) ;
if ( ! V_7 -> V_75 ) {
V_56 = - V_163 ;
goto V_243;
}
F_83 ( & V_7 -> V_110 ) ;
V_7 -> V_3 = F_51 ( sizeof( * V_7 -> V_3 ) , V_242 ) ;
if ( ! V_7 -> V_3 ) {
V_56 = - V_163 ;
goto V_243;
}
V_56 = F_12 ( V_2 , V_7 -> V_3 ) ;
if ( V_56 < 0 ) {
V_239 = L_35 ;
goto V_243;
} else if ( V_7 -> V_3 -> V_85 > V_244 ) {
V_239 = L_36 ;
V_56 = - V_137 ;
goto V_243;
}
V_2 -> V_12 = V_7 -> V_3 -> V_85 ;
F_84 ( V_235 , L_37 , V_2 -> V_12 ,
( V_2 -> V_12 == 1 ) ? L_38 : L_39 ) ;
V_7 -> V_158 = F_85 ( V_2 -> V_12 * sizeof( struct V_156 * ) ,
V_242 ) ;
if ( ! V_7 -> V_158 ) {
V_56 = - V_163 ;
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
if ( ( V_174 & V_245 ) &&
! ( F_1 ( V_2 ) ) ) {
int V_55 ;
char V_246 [ V_244 + 1 ] ;
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; V_55 ++ )
V_246 [ V_55 ] = V_7 -> V_3 -> V_34 . V_247 . V_248
[ ( ( V_55 + 1 ) / 8 ) ] & ( 1 << ( ( V_55 + 1 ) % 8 ) )
? 'F' : 'R' ;
V_246 [ V_2 -> V_12 ] = 0 ;
F_20 ( V_235 , L_40 , V_246 ) ;
} else
F_20 ( V_235 , L_41 ) ;
switch ( V_174 & V_175 ) {
case V_249 :
F_20 ( V_235 , L_42 ) ;
break;
case V_250 :
F_20 ( V_235 , L_43 ) ;
break;
case V_251 :
case V_175 :
F_20 ( V_235 , L_44 ) ;
break;
}
switch ( V_174 & V_252 ) {
case V_253 :
F_20 ( V_235 , L_45 ) ;
break;
case V_254 :
F_20 ( V_235 , L_46 ) ;
break;
case V_255 :
case V_252 :
F_20 ( V_235 , L_47 ) ;
break;
}
F_86 ( & V_7 -> V_140 . V_143 ) ;
F_87 ( & V_7 -> V_140 . V_144 ) ;
F_88 ( & V_7 -> V_140 . V_142 , F_45 ) ;
switch ( V_2 -> V_3 . V_4 ) {
case V_256 :
break;
case V_257 :
F_20 ( V_235 , L_48 ) ;
V_7 -> V_140 . V_7 = V_2 ;
break;
case V_258 :
V_56 = F_89 ( V_2 , 0 , 1 ) ;
if ( V_56 == 0 ) {
F_20 ( V_235 , L_49 ) ;
V_7 -> V_140 . V_164 = 1 ;
} else
F_28 ( V_235 , L_50 ,
V_56 ) ;
V_7 -> V_140 . V_7 = V_2 ;
break;
case V_5 :
break;
default:
F_20 ( V_235 , L_51 ,
V_2 -> V_3 . V_4 ) ;
break;
}
switch ( V_174 & V_259 ) {
case V_260 :
if ( V_2 -> V_3 . V_4 != 0 ) {
V_7 -> V_140 . V_261 = 666 ;
F_20 ( V_235 , L_52
L_53 ,
8 , V_7 -> V_140 . V_261 ) ;
}
break;
case V_262 :
V_7 -> V_140 . V_261 = 666 * 2 ;
F_20 ( V_235 , L_52
L_53 ,
16 , V_7 -> V_140 . V_261 ) ;
break;
case V_263 :
V_7 -> V_140 . V_261 = 666 * 3 ;
F_20 ( V_235 , L_52
L_53 ,
24 , V_7 -> V_140 . V_261 ) ;
break;
case V_264 :
V_7 -> V_140 . V_261 = 666 * 4 ;
F_20 ( V_235 , L_52
L_53 ,
32 , V_7 -> V_140 . V_261 ) ;
break;
}
if ( V_174 & V_265 ) {
V_7 -> V_226 = 1 ;
F_20 ( V_235 , L_54 ) ;
}
F_20 ( V_235 , L_55 ,
V_7 -> V_3 -> V_172 * 2 ) ;
V_56 = F_90 ( V_2 , V_266 , 0 , & V_236 ) ;
if ( V_56 < 2 ) {
V_239 = L_56 ;
goto V_243;
}
F_91 ( & V_236 ) ;
V_151 = F_55 ( V_2 -> V_169 ) ;
if ( V_2 == V_2 -> V_169 -> V_267 ) {
if ( V_151 -> V_268 > 0 )
V_2 -> V_269 = V_151 -> V_268 ;
else
V_2 -> V_269 = V_241 * V_2 -> V_12 ;
if ( V_2 -> V_269 >= V_241 )
V_7 -> V_270 = V_241 ;
else {
V_7 -> V_270 = V_2 -> V_269 ;
V_7 -> V_271 = 1 ;
}
} else if ( ( V_236 & ( 1 << V_272 ) ) == 0 ) {
int V_273 = V_2 -> V_269 -
V_7 -> V_3 -> V_274 ;
F_20 ( V_235 , L_57 ,
V_7 -> V_3 -> V_274 ) ;
V_7 -> V_271 = 1 ;
if ( V_273 < V_2 -> V_12 * V_240 )
F_7 ( V_235 ,
L_58
L_59 ) ;
V_7 -> V_270 = V_240 ;
} else {
V_7 -> V_270 = V_241 ;
}
if ( V_7 -> V_270 < V_241 )
F_20 ( V_235 , L_60 ,
V_7 -> V_270 ) ;
if ( V_151 -> V_152 -> V_210 ) {
V_56 = V_151 -> V_152 -> V_210 ( V_151 , V_2 ,
& V_7 -> V_140 , V_242 ) ;
if ( V_56 < 0 ) {
V_239 = L_61 ;
goto V_243;
}
}
V_56 = F_60 ( V_7 , & V_236 , & V_237 ) ;
if ( V_56 < 0 ) {
V_239 = L_56 ;
goto V_243;
}
if ( V_2 -> V_11 -> V_275 . V_20 & V_276 )
F_20 ( V_235 , L_62 ,
( V_236 & V_277 )
? L_63 : L_64 ) ;
if ( ( V_174 & V_252 ) == 0 )
F_20 ( V_235 , L_65 ,
( V_236 & V_278 ) ? L_38 : L_66 ) ;
V_161 = F_92 ( V_2 , V_233 -> V_279 ) ;
V_238 = F_93 ( V_2 , V_161 , F_94 ( V_161 ) ) ;
if ( V_238 > sizeof( * V_7 -> V_134 ) )
V_238 = sizeof( * V_7 -> V_134 ) ;
V_7 -> V_125 = F_95 ( 0 , V_242 ) ;
if ( ! V_7 -> V_125 ) {
V_56 = - V_163 ;
goto V_243;
}
F_96 ( V_7 -> V_125 , V_2 , V_161 , * V_7 -> V_134 , V_238 , F_42 ,
V_7 , V_233 -> V_280 ) ;
if ( V_7 -> V_226 && V_100 )
V_7 -> V_87 [ 0 ] = V_88 ;
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; V_55 ++ )
if ( F_97 ( V_7 , V_55 + 1 ) < 0 )
F_28 ( V_7 -> V_112 ,
L_67 , V_55 + 1 ) ;
F_98 ( V_2 , V_7 -> V_3 ) ;
F_69 ( V_7 , V_206 ) ;
return 0 ;
V_243:
F_28 ( V_235 , L_68 ,
V_239 , V_56 ) ;
return V_56 ;
}
static void F_99 ( struct V_281 * V_281 )
{
struct V_6 * V_7 = F_22 ( V_281 , struct V_6 , V_281 ) ;
F_100 ( F_36 ( V_7 -> V_112 ) ) ;
F_48 ( V_7 ) ;
}
static void F_101 ( struct V_192 * V_193 )
{
struct V_6 * V_7 = F_4 ( V_193 ) ;
struct V_1 * V_2 = F_102 ( V_193 ) ;
int V_55 ;
F_103 ( & V_118 ) ;
if ( ! F_33 ( & V_7 -> V_120 ) ) {
F_104 ( & V_7 -> V_120 ) ;
F_105 ( V_193 ) ;
}
V_7 -> V_119 = 1 ;
F_106 ( & V_118 ) ;
V_7 -> error = 0 ;
F_75 ( V_7 , V_282 ) ;
F_107 ( V_193 , NULL ) ;
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; V_55 ++ )
F_108 ( V_7 , V_55 + 1 ) ;
V_7 -> V_2 -> V_12 = 0 ;
if ( V_7 -> V_2 -> V_15 == V_16 )
V_283 -- ;
F_109 ( V_7 -> V_125 ) ;
F_48 ( V_7 -> V_158 ) ;
F_48 ( V_7 -> V_3 ) ;
F_48 ( V_7 -> V_75 ) ;
F_48 ( V_7 -> V_134 ) ;
F_110 ( & V_193 -> V_22 , false ) ;
F_111 ( & V_7 -> V_281 , F_99 ) ;
}
static int F_112 ( struct V_192 * V_193 , const struct V_284 * V_285 )
{
struct V_286 * V_275 ;
struct V_232 * V_233 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
V_275 = V_193 -> V_287 ;
V_2 = F_102 ( V_193 ) ;
F_113 ( & V_2 -> V_22 , 0 ) ;
F_114 ( V_2 ) ;
if ( V_2 -> V_204 == V_288 ) {
F_28 ( & V_193 -> V_22 ,
L_69 ) ;
return - V_289 ;
}
#ifdef F_115
if ( V_2 -> V_23 ) {
F_7 ( & V_193 -> V_22 , L_70 ) ;
return - V_137 ;
}
#endif
if ( ( V_275 -> V_275 . V_290 != 0 ) &&
( V_275 -> V_275 . V_290 != 1 ) ) {
V_291:
F_28 ( & V_193 -> V_22 , L_71 ) ;
return - V_114 ;
}
if ( V_275 -> V_275 . V_292 != 1 )
goto V_291;
V_233 = & V_275 -> V_233 [ 0 ] . V_275 ;
if ( ! F_116 ( V_233 ) )
goto V_291;
F_84 ( & V_193 -> V_22 , L_72 ) ;
V_7 = F_85 ( sizeof( * V_7 ) , V_242 ) ;
if ( ! V_7 ) {
F_20 ( & V_193 -> V_22 , L_73 ) ;
return - V_163 ;
}
F_117 ( & V_7 -> V_281 ) ;
F_87 ( & V_7 -> V_120 ) ;
V_7 -> V_112 = & V_193 -> V_22 ;
V_7 -> V_2 = V_2 ;
F_118 ( & V_7 -> V_79 , F_21 ) ;
F_118 ( & V_7 -> V_207 , NULL ) ;
F_119 ( V_193 ) ;
F_107 ( V_193 , V_7 ) ;
V_193 -> V_293 = 1 ;
F_110 ( & V_193 -> V_22 , true ) ;
if ( V_2 -> V_15 == V_16 )
V_283 ++ ;
if ( V_285 -> V_294 & V_295 )
V_7 -> V_296 = 1 ;
if ( F_82 ( V_7 , V_233 ) >= 0 )
return 0 ;
F_101 ( V_193 ) ;
return - V_137 ;
}
static int
F_120 ( struct V_192 * V_193 , unsigned int V_297 , void * V_298 )
{
struct V_1 * V_2 = F_102 ( V_193 ) ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
switch ( V_297 ) {
case V_299 : {
struct V_300 * V_301 = V_298 ;
int V_55 ;
F_103 ( & V_302 ) ;
if ( V_2 -> V_166 <= 0 )
V_301 -> V_303 = 0 ;
else {
V_301 -> V_303 = V_2 -> V_12 ;
for ( V_55 = 0 ; V_55 < V_301 -> V_303 ; V_55 ++ ) {
if ( V_7 -> V_158 [ V_55 ] -> V_188 == NULL )
V_301 -> V_111 [ V_55 ] = 0 ;
else
V_301 -> V_111 [ V_55 ] =
V_7 -> V_158 [ V_55 ] -> V_188 -> V_166 ;
}
}
F_106 ( & V_302 ) ;
return V_301 -> V_303 + 1 ;
}
default:
return - V_304 ;
}
}
static int F_121 ( struct V_1 * V_2 , unsigned V_71 ,
struct V_305 * * * V_306 )
{
if ( V_2 -> V_82 == V_189 )
return - V_137 ;
if ( V_71 == 0 || V_71 > V_2 -> V_12 )
return - V_68 ;
* V_306 = & ( F_3 ( V_2 ) -> V_158 [ V_71 - 1 ] -> V_307 ) ;
return 0 ;
}
int F_122 ( struct V_1 * V_2 , unsigned V_71 ,
struct V_305 * V_308 )
{
int V_309 ;
struct V_305 * * V_310 ;
V_309 = F_121 ( V_2 , V_71 , & V_310 ) ;
if ( V_309 )
return V_309 ;
if ( * V_310 )
return - V_311 ;
* V_310 = V_308 ;
return V_309 ;
}
int F_123 ( struct V_1 * V_2 , unsigned V_71 ,
struct V_305 * V_308 )
{
int V_309 ;
struct V_305 * * V_310 ;
V_309 = F_121 ( V_2 , V_71 , & V_310 ) ;
if ( V_309 )
return V_309 ;
if ( * V_310 != V_308 )
return - V_128 ;
* V_310 = NULL ;
return V_309 ;
}
void F_124 ( struct V_1 * V_2 , struct V_305 * V_308 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
int V_312 ;
for ( V_312 = 0 ; V_312 < V_2 -> V_12 ; V_312 ++ ) {
if ( V_7 -> V_158 [ V_312 ] -> V_307 == V_308 )
V_7 -> V_158 [ V_312 ] -> V_307 = NULL ;
}
}
bool F_125 ( struct V_1 * V_14 )
{
struct V_6 * V_7 ;
if ( V_14 -> V_82 == V_189 || ! V_14 -> V_23 )
return false ;
V_7 = F_3 ( V_14 -> V_23 ) ;
return ! ! V_7 -> V_158 [ V_14 -> V_123 - 1 ] -> V_307 ;
}
static void F_126 ( struct V_1 * V_14 )
{
struct V_6 * V_7 = F_3 ( V_14 ) ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_14 -> V_12 ; ++ V_55 ) {
if ( V_7 -> V_158 [ V_55 ] -> V_188 )
F_126 ( V_7 -> V_158 [ V_55 ] -> V_188 ) ;
}
if ( V_14 -> V_82 == V_313 )
V_14 -> V_314 -= V_315 ;
V_14 -> V_82 = V_189 ;
}
void F_64 ( struct V_1 * V_14 ,
enum V_316 V_317 )
{
unsigned long V_117 ;
int V_318 = - 1 ;
F_32 ( & V_302 , V_117 ) ;
if ( V_14 -> V_82 == V_189 )
;
else if ( V_317 != V_189 ) {
if ( V_14 -> V_23 ) {
if ( V_14 -> V_82 == V_313
|| V_317 == V_313 )
;
else if ( V_317 == V_83 )
V_318 = V_14 -> V_11 -> V_275 . V_20
& V_319 ;
else
V_318 = 0 ;
}
if ( V_14 -> V_82 == V_313 &&
V_317 != V_313 )
V_14 -> V_314 -= V_315 ;
else if ( V_317 == V_313 &&
V_14 -> V_82 != V_313 )
V_14 -> V_314 += V_315 ;
V_14 -> V_82 = V_317 ;
} else
F_126 ( V_14 ) ;
F_38 ( & V_302 , V_117 ) ;
if ( V_318 >= 0 )
F_127 ( & V_14 -> V_22 , V_318 ) ;
}
static void F_128 ( struct V_1 * V_14 )
{
int V_166 ;
struct V_320 * V_169 = V_14 -> V_169 ;
if ( V_14 -> V_321 ) {
V_166 = V_14 -> V_123 + 1 ;
F_129 ( F_130 ( V_166 , V_169 -> V_322 . V_323 ) ) ;
} else {
V_166 = F_131 ( V_169 -> V_322 . V_323 , 128 ,
V_169 -> V_324 ) ;
if ( V_166 >= 128 )
V_166 = F_131 ( V_169 -> V_322 . V_323 ,
128 , 1 ) ;
V_169 -> V_324 = ( V_166 >= 127 ? 1 : V_166 + 1 ) ;
}
if ( V_166 < 128 ) {
F_41 ( V_166 , V_169 -> V_322 . V_323 ) ;
V_14 -> V_166 = V_166 ;
}
}
static void F_132 ( struct V_1 * V_14 )
{
if ( V_14 -> V_166 > 0 ) {
F_72 ( V_14 -> V_166 , V_14 -> V_169 -> V_322 . V_323 ) ;
V_14 -> V_166 = - 1 ;
}
}
static void F_133 ( struct V_1 * V_14 , int V_166 )
{
if ( ! V_14 -> V_321 )
V_14 -> V_166 = V_166 ;
}
static void F_134 ( struct V_1 * V_14 )
{
struct V_196 * V_151 = F_55 ( V_14 -> V_169 ) ;
if ( V_151 -> V_152 -> V_325 && V_14 -> V_23 )
V_151 -> V_152 -> V_325 ( V_151 , V_14 ) ;
}
void F_77 ( struct V_1 * * V_326 )
{
struct V_1 * V_14 = * V_326 ;
struct V_6 * V_7 = F_3 ( V_14 ) ;
int V_55 ;
F_64 ( V_14 , V_189 ) ;
F_84 ( & V_14 -> V_22 , L_74 ,
V_14 -> V_166 ) ;
F_135 ( V_14 ) ;
for ( V_55 = 0 ; V_55 < V_14 -> V_12 ; V_55 ++ ) {
if ( V_7 -> V_158 [ V_55 ] -> V_188 )
F_77 ( & V_7 -> V_158 [ V_55 ] -> V_188 ) ;
}
F_20 ( & V_14 -> V_22 , L_75 ) ;
F_136 ( V_14 , 0 ) ;
F_137 ( V_14 ) ;
if ( V_14 -> V_23 ) {
struct V_6 * V_7 = F_3 ( V_14 -> V_23 ) ;
struct V_156 * V_157 = V_7 -> V_158 [ V_14 -> V_123 - 1 ] ;
F_138 ( & V_14 -> V_22 . V_327 , L_76 ) ;
F_138 ( & V_157 -> V_22 . V_327 , L_77 ) ;
if ( ! V_157 -> V_328 )
F_139 ( & V_157 -> V_22 ) ;
else
V_157 -> V_328 = false ;
}
F_140 ( & V_14 -> V_329 ) ;
F_141 ( V_14 ) ;
F_142 ( & V_14 -> V_22 ) ;
F_132 ( V_14 ) ;
F_103 ( & V_302 ) ;
* V_326 = NULL ;
F_106 ( & V_302 ) ;
F_134 ( V_14 ) ;
F_143 ( & V_14 -> V_22 ) ;
}
static void F_144 ( struct V_1 * V_14 , char * V_285 , char * string )
{
if ( ! string )
return;
F_84 ( & V_14 -> V_22 , L_78 , V_285 , string ) ;
}
static void F_145 ( struct V_1 * V_14 )
{
F_84 ( & V_14 -> V_22 , L_79 ,
F_29 ( V_14 -> V_3 . V_330 ) ,
F_29 ( V_14 -> V_3 . V_331 ) ) ;
F_84 ( & V_14 -> V_22 ,
L_80 ,
V_14 -> V_3 . V_332 ,
V_14 -> V_3 . V_333 ,
V_14 -> V_3 . V_334 ) ;
F_144 ( V_14 , L_81 , V_14 -> V_335 ) ;
F_144 ( V_14 , L_82 , V_14 -> V_336 ) ;
F_144 ( V_14 , L_83 , V_14 -> V_337 ) ;
}
static inline void F_145 ( struct V_1 * V_14 ) { }
static int F_146 ( struct V_1 * V_14 )
{
int V_338 = 0 ;
#ifdef F_147
if ( ! V_14 -> V_169 -> V_339
&& V_14 -> V_340
&& V_14 -> V_23 == V_14 -> V_169 -> V_267 ) {
struct V_341 * V_275 = NULL ;
struct V_320 * V_169 = V_14 -> V_169 ;
if ( F_148 ( V_14 -> V_342 [ 0 ] ,
F_29 ( V_14 -> V_340 [ 0 ] . V_275 . V_343 ) ,
V_344 , ( void * * ) & V_275 ) == 0 ) {
if ( V_275 -> V_20 & V_345 ) {
unsigned V_71 = V_14 -> V_123 ;
F_84 ( & V_14 -> V_22 ,
L_84 ,
( V_71 == V_169 -> V_346 )
? L_38 : L_85 ) ;
if ( V_71 == V_169 -> V_346 )
V_169 -> V_347 = 1 ;
V_338 = F_13 ( V_14 ,
F_16 ( V_14 , 0 ) ,
V_73 , 0 ,
V_169 -> V_347
? V_348
: V_349 ,
0 , NULL , 0 , V_205 ) ;
if ( V_338 < 0 ) {
F_84 ( & V_14 -> V_22 ,
L_86 ,
V_338 ) ;
V_169 -> V_347 = 0 ;
}
}
}
}
if ( ! F_149 ( V_14 ) ) {
if ( V_14 -> V_169 -> V_347 || V_14 -> V_169 -> V_339 ) {
V_338 = F_150 ( V_14 , V_350 ) ;
if ( V_338 < 0 )
F_20 ( & V_14 -> V_22 , L_87 , V_338 ) ;
}
V_338 = - V_351 ;
goto V_243;
}
V_243:
#endif
return V_338 ;
}
static int F_151 ( struct V_1 * V_14 )
{
int V_338 ;
if ( V_14 -> V_340 == NULL ) {
V_338 = F_152 ( V_14 ) ;
if ( V_338 < 0 ) {
F_28 ( & V_14 -> V_22 , L_88 ,
V_338 ) ;
return V_338 ;
}
}
if ( V_14 -> V_321 == 1 && V_14 -> V_352 == 0 ) {
V_14 -> V_335 = F_153 ( L_89 , V_242 ) ;
V_14 -> V_336 = F_153 ( L_89 , V_242 ) ;
V_14 -> V_337 = F_153 ( L_89 , V_242 ) ;
}
else {
V_14 -> V_335 = F_154 ( V_14 , V_14 -> V_3 . V_333 ) ;
V_14 -> V_336 = F_154 ( V_14 ,
V_14 -> V_3 . V_332 ) ;
V_14 -> V_337 = F_154 ( V_14 , V_14 -> V_3 . V_334 ) ;
}
V_338 = F_146 ( V_14 ) ;
if ( V_338 < 0 )
return V_338 ;
F_155 ( V_14 ) ;
return 0 ;
}
static void F_156 ( struct V_1 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_23 ;
struct V_6 * V_7 ;
T_2 V_111 = V_14 -> V_123 ;
T_1 V_174 ;
bool V_353 = true ;
if ( ! V_2 )
return;
V_7 = F_3 ( V_14 -> V_23 ) ;
V_174 = F_29 ( V_7 -> V_3 -> V_174 ) ;
if ( ! ( V_174 & V_245 ) )
return;
if ( F_1 ( V_2 ) ) {
if ( F_29 ( V_7 -> V_3 -> V_34 . V_35 . V_248 )
& ( 1 << V_111 ) )
V_353 = false ;
} else {
if ( V_7 -> V_3 -> V_34 . V_247 . V_248 [ V_111 / 8 ] & ( 1 << ( V_111 % 8 ) ) )
V_353 = false ;
}
if ( V_353 )
V_14 -> V_353 = V_354 ;
else
V_14 -> V_353 = V_355 ;
}
int F_157 ( struct V_1 * V_14 )
{
int V_338 ;
if ( V_14 -> V_23 ) {
F_158 ( & V_14 -> V_22 , 0 ) ;
}
F_159 ( & V_14 -> V_22 ) ;
F_160 ( & V_14 -> V_22 ) ;
F_161 ( & V_14 -> V_22 ) ;
F_162 ( & V_14 -> V_22 ) ;
F_163 ( V_14 ) ;
V_338 = F_151 ( V_14 ) ;
if ( V_338 < 0 )
goto V_243;
F_20 ( & V_14 -> V_22 , L_90 ,
V_14 -> V_166 , V_14 -> V_169 -> V_356 ,
( ( ( V_14 -> V_169 -> V_356 - 1 ) * 128 ) + ( V_14 -> V_166 - 1 ) ) ) ;
V_14 -> V_22 . V_357 = F_164 ( V_358 ,
( ( ( V_14 -> V_169 -> V_356 - 1 ) * 128 ) + ( V_14 -> V_166 - 1 ) ) ) ;
F_145 ( V_14 ) ;
if ( V_14 -> V_337 )
F_165 ( V_14 -> V_337 , strlen ( V_14 -> V_337 ) ) ;
if ( V_14 -> V_335 )
F_165 ( V_14 -> V_335 , strlen ( V_14 -> V_335 ) ) ;
if ( V_14 -> V_336 )
F_165 ( V_14 -> V_336 ,
strlen ( V_14 -> V_336 ) ) ;
F_166 ( & V_14 -> V_22 ) ;
if ( V_14 -> V_23 )
F_156 ( V_14 ) ;
V_338 = F_167 ( & V_14 -> V_22 ) ;
if ( V_338 ) {
F_28 ( & V_14 -> V_22 , L_91 , V_338 ) ;
goto V_243;
}
if ( V_14 -> V_23 ) {
struct V_6 * V_7 = F_3 ( V_14 -> V_23 ) ;
struct V_156 * V_157 = V_7 -> V_158 [ V_14 -> V_123 - 1 ] ;
V_338 = F_168 ( & V_14 -> V_22 . V_327 ,
& V_157 -> V_22 . V_327 , L_76 ) ;
if ( V_338 )
goto V_243;
V_338 = F_168 ( & V_157 -> V_22 . V_327 ,
& V_14 -> V_22 . V_327 , L_77 ) ;
if ( V_338 ) {
F_138 ( & V_14 -> V_22 . V_327 , L_76 ) ;
goto V_243;
}
F_169 ( & V_157 -> V_22 ) ;
}
( void ) F_170 ( & V_14 -> V_22 , & V_14 -> V_329 , V_14 ) ;
F_171 ( V_14 ) ;
F_172 ( & V_14 -> V_22 ) ;
return V_338 ;
V_243:
F_64 ( V_14 , V_189 ) ;
F_173 ( & V_14 -> V_22 ) ;
F_174 ( & V_14 -> V_22 ) ;
return V_338 ;
}
int F_175 ( struct V_1 * V_359 )
{
F_135 ( V_359 ) ;
if ( V_359 -> V_352 == 0 )
goto V_360;
V_359 -> V_352 = 0 ;
F_176 ( V_359 , - 1 ) ;
F_48 ( V_359 -> V_335 ) ;
V_359 -> V_335 = F_153 ( L_89 , V_242 ) ;
F_48 ( V_359 -> V_336 ) ;
V_359 -> V_336 = F_153 ( L_89 , V_242 ) ;
F_48 ( V_359 -> V_337 ) ;
V_359 -> V_337 = F_153 ( L_89 , V_242 ) ;
F_177 ( V_359 ) ;
V_359 -> V_3 . V_361 = 0 ;
V_360:
F_141 ( V_359 ) ;
return 0 ;
}
int F_178 ( struct V_1 * V_359 )
{
int V_362 = 0 , V_363 ;
F_135 ( V_359 ) ;
if ( V_359 -> V_352 == 1 )
goto V_364;
V_362 = F_179 ( V_359 ) ;
if ( V_362 < 0 ) {
F_28 ( & V_359 -> V_22 ,
L_92 , V_362 ) ;
goto V_365;
}
V_362 = F_180 ( V_359 , sizeof( V_359 -> V_3 ) ) ;
if ( V_362 < 0 ) {
F_28 ( & V_359 -> V_22 , L_93
L_94 , V_362 ) ;
goto V_366;
}
F_48 ( V_359 -> V_335 ) ;
V_359 -> V_335 = NULL ;
F_48 ( V_359 -> V_336 ) ;
V_359 -> V_336 = NULL ;
F_48 ( V_359 -> V_337 ) ;
V_359 -> V_337 = NULL ;
V_359 -> V_352 = 1 ;
V_362 = F_151 ( V_359 ) ;
if ( V_362 < 0 )
goto V_367;
V_363 = F_181 ( V_359 ) ;
if ( V_363 >= 0 ) {
V_362 = F_176 ( V_359 , V_363 ) ;
if ( V_362 ) {
F_28 ( & V_359 -> V_22 ,
L_95 , V_363 , V_362 ) ;
}
}
F_84 ( & V_359 -> V_22 , L_96 ) ;
V_367:
V_366:
F_182 ( V_359 ) ;
V_365:
V_364:
F_141 ( V_359 ) ;
return V_362 ;
}
static unsigned F_183 ( struct V_6 * V_7 )
{
struct V_196 * V_151 ;
if ( V_7 -> V_2 -> V_23 != NULL )
return 0 ;
V_151 = F_22 ( V_7 -> V_2 -> V_169 , struct V_196 , V_368 ) ;
return V_151 -> V_369 ;
}
static bool F_184 ( struct V_6 * V_7 , T_1 V_8 )
{
return F_1 ( V_7 -> V_2 ) &&
( ( ( V_8 & V_184 ) ==
V_370 ) ||
( ( V_8 & V_184 ) ==
V_371 ) ) ;
}
static int F_185 ( struct V_6 * V_7 , int V_71 ,
struct V_1 * V_14 , unsigned int V_173 , bool V_372 )
{
int V_373 , V_56 ;
T_1 V_8 ;
T_1 V_181 ;
for ( V_373 = 0 ;
V_373 < V_374 ;
V_373 += V_173 ) {
F_59 ( V_173 ) ;
V_56 = F_26 ( V_7 , V_71 , & V_8 , & V_181 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( ! ( V_8 & V_375 ) )
break;
if ( V_373 >= 2 * V_376 )
V_173 = V_377 ;
F_20 ( V_7 -> V_112 ,
L_97 ,
V_71 , V_372 ? L_98 : L_38 , V_173 ) ;
}
if ( ( V_8 & V_375 ) )
return - V_311 ;
if ( F_184 ( V_7 , V_8 ) )
return - V_378 ;
if ( ! ( V_8 & V_212 ) )
return - V_378 ;
if ( ! F_1 ( V_7 -> V_2 ) &&
( V_181 & V_214 ) )
return - V_378 ;
if ( ! ( V_8 & V_213 ) )
return - V_311 ;
if ( ! V_14 )
return 0 ;
if ( F_183 ( V_7 ) )
V_14 -> V_15 = V_379 ;
else if ( F_1 ( V_7 -> V_2 ) )
V_14 -> V_15 = V_49 ;
else if ( V_8 & V_9 )
V_14 -> V_15 = V_16 ;
else if ( V_8 & V_10 )
V_14 -> V_15 = V_380 ;
else
V_14 -> V_15 = V_381 ;
return 0 ;
}
static void F_186 ( struct V_6 * V_7 , int V_71 ,
struct V_1 * V_14 , int * V_75 )
{
switch ( * V_75 ) {
case 0 :
F_59 ( 10 + 40 ) ;
if ( V_14 ) {
struct V_196 * V_151 = F_55 ( V_14 -> V_169 ) ;
F_133 ( V_14 , 0 ) ;
if ( V_151 -> V_152 -> V_382 )
V_151 -> V_152 -> V_382 ( V_151 , V_14 ) ;
}
case - V_378 :
case - V_137 :
F_17 ( V_7 -> V_2 ,
V_71 , V_383 ) ;
if ( F_1 ( V_7 -> V_2 ) ) {
F_17 ( V_7 -> V_2 , V_71 ,
V_219 ) ;
F_17 ( V_7 -> V_2 , V_71 ,
V_384 ) ;
F_17 ( V_7 -> V_2 , V_71 ,
V_215 ) ;
}
if ( V_14 )
F_64 ( V_14 , * V_75
? V_189
: V_385 ) ;
break;
}
}
static int F_187 ( struct V_6 * V_7 , int V_71 ,
struct V_1 * V_14 , unsigned int V_173 , bool V_372 )
{
int V_55 , V_75 ;
T_1 V_181 , V_8 ;
if ( ! F_1 ( V_7 -> V_2 ) ) {
if ( V_372 ) {
F_28 ( V_7 -> V_112 , L_99
L_100 ) ;
return - V_68 ;
}
F_188 ( & V_386 ) ;
} else if ( ! V_372 ) {
V_75 = F_26 ( V_7 , V_71 ,
& V_8 , & V_181 ) ;
if ( V_75 < 0 )
goto V_387;
if ( F_184 ( V_7 , V_8 ) )
V_372 = true ;
}
for ( V_55 = 0 ; V_55 < V_388 ; V_55 ++ ) {
V_75 = F_18 ( V_7 -> V_2 , V_71 , ( V_372 ?
V_389 :
V_390 ) ) ;
if ( V_75 ) {
F_28 ( V_7 -> V_112 ,
L_101 ,
V_372 ? L_98 : L_38 , V_71 , V_75 ) ;
} else {
V_75 = F_185 ( V_7 , V_71 , V_14 , V_173 ,
V_372 ) ;
if ( V_75 && V_75 != - V_378 )
F_20 ( V_7 -> V_112 ,
L_102 ,
V_75 ) ;
}
if ( V_75 == 0 || V_75 == - V_378 || V_75 == - V_137 ) {
F_186 ( V_7 , V_71 , V_14 , & V_75 ) ;
if ( ! F_1 ( V_7 -> V_2 ) )
goto V_387;
if ( F_26 ( V_7 , V_71 ,
& V_8 , & V_181 ) < 0 )
goto V_387;
if ( ! F_184 ( V_7 , V_8 ) )
goto V_387;
if ( ! V_372 ) {
F_20 ( V_7 -> V_112 , L_103 ,
V_71 ) ;
V_372 = true ;
}
}
F_20 ( V_7 -> V_112 ,
L_104 ,
V_71 , V_372 ? L_98 : L_38 ) ;
V_173 = V_377 ;
}
F_28 ( V_7 -> V_112 ,
L_105 ,
V_71 ) ;
V_387:
if ( ! F_1 ( V_7 -> V_2 ) )
F_189 ( & V_386 ) ;
return V_75 ;
}
static int F_190 ( struct V_6 * V_7 , unsigned V_8 )
{
int V_56 = 0 ;
if ( F_1 ( V_7 -> V_2 ) ) {
if ( V_8 & V_391 )
V_56 = 1 ;
} else {
if ( V_8 & V_392 )
V_56 = 1 ;
}
return V_56 ;
}
static int F_191 ( struct V_6 * V_7 , unsigned V_8 )
{
int V_56 = 0 ;
if ( F_1 ( V_7 -> V_2 ) ) {
if ( ( V_8 & V_184 )
== V_393 )
V_56 = 1 ;
} else {
if ( V_8 & V_394 )
V_56 = 1 ;
}
return V_56 ;
}
static int F_192 ( struct V_1 * V_14 ,
struct V_6 * V_7 , int V_71 ,
int V_75 , unsigned V_181 , unsigned V_8 )
{
if ( V_75 || F_191 ( V_7 , V_8 ) ||
! F_190 ( V_7 , V_8 ) ||
! ( V_8 & V_212 ) ) {
if ( V_75 >= 0 )
V_75 = - V_137 ;
}
else if ( ! ( V_8 & V_213 ) && ! V_14 -> V_223 ) {
if ( V_14 -> V_222 )
V_14 -> V_223 = 1 ;
else
V_75 = - V_137 ;
}
if ( V_75 ) {
F_20 ( V_7 -> V_112 ,
L_106 ,
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
int F_193 ( struct V_1 * V_14 )
{
struct V_196 * V_151 = F_55 ( V_14 -> V_169 ) ;
if ( ! F_194 ( V_151 -> V_368 . V_267 ) ||
! F_194 ( V_14 ) )
return 0 ;
if ( ! V_14 -> V_11 )
return 0 ;
return F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_70 , V_266 ,
V_395 , 0 , NULL , 0 ,
V_205 ) ;
}
void F_195 ( struct V_1 * V_14 )
{
struct V_196 * V_151 = F_55 ( V_14 -> V_169 ) ;
if ( ! F_194 ( V_151 -> V_368 . V_267 ) ||
! F_194 ( V_14 ) )
return;
if ( ! V_14 -> V_11 )
return;
F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_73 , V_266 ,
V_395 , 0 , NULL , 0 ,
V_205 ) ;
}
static int F_196 ( struct V_1 * V_14 )
{
return F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_70 , V_396 ,
V_397 , 0 , NULL , 0 ,
V_205 ) ;
}
int F_150 ( struct V_1 * V_14 , T_3 V_398 )
{
struct V_6 * V_7 = F_3 ( V_14 -> V_23 ) ;
struct V_156 * V_157 = V_7 -> V_158 [ V_14 -> V_123 - 1 ] ;
enum V_399 V_400 ;
int V_71 = V_14 -> V_123 ;
int V_75 ;
if ( V_14 -> V_401 ) {
if ( ! F_1 ( V_7 -> V_2 ) ) {
V_75 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_73 , V_266 ,
V_402 , 0 ,
NULL , 0 ,
V_205 ) ;
} else {
V_75 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_73 ,
V_396 ,
V_397 ,
V_403 |
V_404 ,
NULL , 0 ,
V_205 ) ;
}
if ( V_75 ) {
F_20 ( & V_14 -> V_22 , L_107 ,
V_75 ) ;
if ( F_197 ( V_398 ) )
return V_75 ;
}
}
if ( V_14 -> V_405 == 1 )
F_198 ( V_14 , 0 ) ;
if ( F_193 ( V_14 ) ) {
F_28 ( & V_14 -> V_22 , L_108 ,
V_113 ) ;
return - V_163 ;
}
if ( F_199 ( V_14 ) ) {
F_28 ( & V_14 -> V_22 , L_109 ,
V_113 ) ;
return - V_163 ;
}
if ( F_1 ( V_7 -> V_2 ) )
V_75 = F_61 ( V_7 , V_71 , V_393 ) ;
else
V_75 = F_18 ( V_7 -> V_2 , V_71 ,
V_406 ) ;
if ( V_75 ) {
F_20 ( V_7 -> V_112 , L_110 ,
V_71 , V_75 ) ;
if ( V_14 -> V_401 ) {
if ( ! F_1 ( V_7 -> V_2 ) ) {
( void ) F_13 ( V_14 ,
F_16 ( V_14 , 0 ) ,
V_70 ,
V_266 ,
V_402 , 0 ,
NULL , 0 ,
V_205 ) ;
} else
( void ) F_196 ( V_14 ) ;
}
if ( V_14 -> V_407 == 1 )
F_198 ( V_14 , 1 ) ;
F_195 ( V_14 ) ;
F_200 ( V_14 ) ;
if ( ! F_197 ( V_398 ) )
V_75 = 0 ;
} else {
F_20 ( & V_14 -> V_22 , L_111 ,
( F_197 ( V_398 ) ? L_112 : L_38 ) ,
V_14 -> V_401 ) ;
F_64 ( V_14 , V_313 ) ;
V_14 -> F_191 = 1 ;
F_59 ( 10 ) ;
}
V_400 = F_201 ( & V_157 -> V_22 ,
V_408 ) ;
if ( ! V_14 -> V_401
&& V_400 != V_409
&& V_14 -> V_222
&& ! V_75 ) {
F_202 ( & V_157 -> V_22 ) ;
V_157 -> V_328 = true ;
}
F_171 ( V_7 -> V_2 ) ;
return V_75 ;
}
static int F_203 ( struct V_1 * V_14 )
{
int V_75 = 0 ;
T_1 V_410 = 0 ;
F_20 ( & V_14 -> V_22 , L_113 ,
V_14 -> V_223 ? L_114 : L_115 ) ;
F_64 ( V_14 , V_14 -> V_11
? V_83
: V_411 ) ;
if ( V_14 -> V_223 )
V_412:
V_75 = F_204 ( V_14 ) ;
if ( V_75 == 0 ) {
V_410 = 0 ;
V_75 = F_90 ( V_14 , V_266 , 0 , & V_410 ) ;
if ( V_75 >= 0 )
V_75 = ( V_75 > 0 ? 0 : - V_137 ) ;
if ( V_75 && ! V_14 -> V_223 && V_14 -> V_222 ) {
F_20 ( & V_14 -> V_22 , L_116 ) ;
V_14 -> V_223 = 1 ;
goto V_412;
}
}
if ( V_75 ) {
F_20 ( & V_14 -> V_22 , L_117 ,
V_75 ) ;
} else if ( V_14 -> V_11 && ! V_14 -> V_223 ) {
if ( ! F_1 ( V_14 -> V_23 ) ) {
F_91 ( & V_410 ) ;
if ( V_410 & ( 1 << V_402 ) )
V_75 = F_13 ( V_14 ,
F_16 ( V_14 , 0 ) ,
V_70 ,
V_266 ,
V_402 , 0 ,
NULL , 0 ,
V_205 ) ;
} else {
V_75 = F_90 ( V_14 , V_396 , 0 ,
& V_410 ) ;
F_91 ( & V_410 ) ;
if ( ! V_75 && V_410 & ( V_413
| V_414 ) )
V_75 =
F_196 ( V_14 ) ;
}
if ( V_75 )
F_20 ( & V_14 -> V_22 ,
L_118 ,
V_75 ) ;
V_75 = 0 ;
}
return V_75 ;
}
int F_205 ( struct V_1 * V_14 , T_3 V_398 )
{
struct V_6 * V_7 = F_3 ( V_14 -> V_23 ) ;
struct V_156 * V_157 = V_7 -> V_158 [ V_14 -> V_123 - 1 ] ;
int V_71 = V_14 -> V_123 ;
int V_75 ;
T_1 V_181 , V_8 ;
if ( V_157 -> V_328 ) {
V_75 = F_169 ( & V_157 -> V_22 ) ;
V_157 -> V_328 = false ;
if ( V_75 < 0 ) {
F_20 ( & V_14 -> V_22 , L_119 ,
V_75 ) ;
return V_75 ;
}
}
V_75 = F_26 ( V_7 , V_71 , & V_8 , & V_181 ) ;
if ( V_75 == 0 && ! F_191 ( V_7 , V_8 ) )
goto V_415;
F_41 ( V_71 , V_7 -> V_416 ) ;
if ( F_1 ( V_7 -> V_2 ) )
V_75 = F_61 ( V_7 , V_71 , V_221 ) ;
else
V_75 = F_17 ( V_7 -> V_2 ,
V_71 , V_406 ) ;
if ( V_75 ) {
F_20 ( V_7 -> V_112 , L_120 ,
V_71 , V_75 ) ;
} else {
F_20 ( & V_14 -> V_22 , L_121 ,
( F_197 ( V_398 ) ? L_112 : L_38 ) ) ;
F_59 ( 25 ) ;
V_75 = F_26 ( V_7 , V_71 , & V_8 , & V_181 ) ;
F_59 ( 10 ) ;
}
V_415:
if ( V_75 == 0 ) {
V_14 -> F_191 = 0 ;
if ( F_1 ( V_7 -> V_2 ) ) {
if ( V_181 & V_417 )
F_17 ( V_7 -> V_2 , V_71 ,
V_384 ) ;
} else {
if ( V_181 & V_418 )
F_17 ( V_7 -> V_2 , V_71 ,
V_419 ) ;
}
}
F_72 ( V_71 , V_7 -> V_416 ) ;
V_75 = F_192 ( V_14 ,
V_7 , V_71 , V_75 , V_181 , V_8 ) ;
if ( V_75 == 0 )
V_75 = F_203 ( V_14 ) ;
if ( V_75 < 0 ) {
F_20 ( & V_14 -> V_22 , L_122 , V_75 ) ;
F_65 ( V_7 , V_71 ) ;
} else {
if ( V_14 -> V_407 == 1 )
F_198 ( V_14 , 1 ) ;
F_195 ( V_14 ) ;
F_200 ( V_14 ) ;
}
return V_75 ;
}
int F_206 ( struct V_1 * V_14 )
{
int V_75 = 0 ;
if ( V_14 -> V_82 == V_313 ) {
F_20 ( & V_14 -> V_22 , L_121 , L_123 ) ;
V_75 = F_179 ( V_14 ) ;
if ( V_75 == 0 ) {
F_182 ( V_14 ) ;
}
}
return V_75 ;
}
int F_150 ( struct V_1 * V_14 , T_3 V_398 )
{
return 0 ;
}
int F_205 ( struct V_1 * V_14 , T_3 V_398 )
{
struct V_6 * V_7 = F_3 ( V_14 -> V_23 ) ;
int V_71 = V_14 -> V_123 ;
int V_75 ;
T_1 V_181 , V_8 ;
V_75 = F_26 ( V_7 , V_71 , & V_8 , & V_181 ) ;
V_75 = F_192 ( V_14 ,
V_7 , V_71 , V_75 , V_181 , V_8 ) ;
if ( V_75 ) {
F_20 ( & V_14 -> V_22 , L_122 , V_75 ) ;
F_65 ( V_7 , V_71 ) ;
} else if ( V_14 -> V_223 ) {
F_20 ( & V_14 -> V_22 , L_124 ) ;
V_75 = F_204 ( V_14 ) ;
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
static int F_208 ( struct V_192 * V_193 , T_3 V_398 )
{
struct V_6 * V_7 = F_4 ( V_193 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
unsigned V_71 ;
int V_75 ;
for ( V_71 = 1 ; V_71 <= V_2 -> V_12 ; V_71 ++ ) {
struct V_1 * V_14 ;
V_14 = V_7 -> V_158 [ V_71 - 1 ] -> V_188 ;
if ( V_14 && V_14 -> V_420 ) {
F_7 ( & V_193 -> V_22 , L_125 , V_71 ) ;
if ( F_197 ( V_398 ) )
return - V_311 ;
}
}
if ( V_2 -> V_401 && V_7 -> V_296 ) {
if ( F_207 ( V_7 ) ) {
if ( F_197 ( V_398 ) )
return - V_311 ;
F_209 ( & V_2 -> V_22 , 2000 ) ;
}
}
if ( F_1 ( V_2 ) && V_2 -> V_401 ) {
for ( V_71 = 1 ; V_71 <= V_2 -> V_12 ; V_71 ++ ) {
V_75 = F_18 ( V_2 ,
V_71 |
V_421 |
V_422 |
V_423 ,
V_424 ) ;
}
}
F_20 ( & V_193 -> V_22 , L_113 , V_113 ) ;
F_75 ( V_7 , V_229 ) ;
return 0 ;
}
static int F_210 ( struct V_192 * V_193 )
{
struct V_6 * V_7 = F_4 ( V_193 ) ;
F_20 ( & V_193 -> V_22 , L_113 , V_113 ) ;
F_69 ( V_7 , V_202 ) ;
return 0 ;
}
static int F_211 ( struct V_192 * V_193 )
{
struct V_6 * V_7 = F_4 ( V_193 ) ;
F_20 ( & V_193 -> V_22 , L_113 , V_113 ) ;
F_69 ( V_7 , V_209 ) ;
return 0 ;
}
void F_212 ( struct V_1 * V_425 )
{
F_7 ( & V_425 -> V_22 , L_126 ) ;
V_425 -> V_223 = 1 ;
}
static int F_213 ( struct V_1 * V_14 , enum V_426 V_82 )
{
struct V_427 * V_428 ;
unsigned long long V_429 ;
unsigned long long V_430 ;
unsigned long long V_431 ;
unsigned long long V_432 ;
int V_56 ;
V_429 = F_214 ( V_14 -> V_52 . V_43 , 1000 ) ;
V_430 = F_214 ( V_14 -> V_52 . V_40 , 1000 ) ;
V_431 = F_214 ( V_14 -> V_53 . V_43 , 1000 ) ;
V_432 = F_214 ( V_14 -> V_53 . V_40 , 1000 ) ;
if ( ( V_82 == V_433 &&
( V_429 > V_434 ||
V_430 > V_434 ) ) ||
( V_82 == V_435 &&
( V_431 > V_436 ||
V_432 > V_436 ) ) ) {
F_20 ( & V_14 -> V_22 , L_127 ,
V_437 [ V_82 ] , V_429 , V_430 ) ;
return - V_68 ;
}
if ( V_429 > V_434 )
V_429 = V_434 ;
if ( V_430 > V_434 )
V_430 = V_434 ;
if ( V_431 > V_436 )
V_431 = V_436 ;
if ( V_432 > V_436 )
V_432 = V_436 ;
V_428 = F_51 ( sizeof *( V_428 ) , V_211 ) ;
if ( ! V_428 )
return - V_163 ;
V_428 -> V_429 = V_429 ;
V_428 -> V_430 = V_430 ;
V_428 -> V_431 = F_215 ( V_431 ) ;
V_428 -> V_432 = F_215 ( V_432 ) ;
V_56 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_438 ,
V_266 ,
0 , 0 ,
V_428 , sizeof *( V_428 ) ,
V_205 ) ;
F_48 ( V_428 ) ;
return V_56 ;
}
static int F_216 ( struct V_1 * V_14 ,
enum V_426 V_82 , bool V_439 )
{
int V_56 ;
int V_69 ;
switch ( V_82 ) {
case V_433 :
V_69 = V_440 ;
break;
case V_435 :
V_69 = V_441 ;
break;
default:
F_7 ( & V_14 -> V_22 , L_128 ,
V_113 , V_439 ? L_129 : L_130 ) ;
return - V_68 ;
}
if ( V_14 -> V_82 != V_83 ) {
F_20 ( & V_14 -> V_22 , L_131
L_132 ,
V_113 , V_439 ? L_129 : L_130 ,
V_437 [ V_82 ] ) ;
return 0 ;
}
if ( V_439 ) {
V_56 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_73 ,
V_266 ,
V_69 ,
0 , NULL , 0 ,
V_205 ) ;
} else {
V_56 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_70 ,
V_266 ,
V_69 ,
0 , NULL , 0 ,
V_205 ) ;
}
if ( V_56 < 0 ) {
F_7 ( & V_14 -> V_22 , L_133 ,
V_439 ? L_134 : L_135 ,
V_437 [ V_82 ] ) ;
return - V_311 ;
}
return 0 ;
}
static int F_217 ( struct V_1 * V_14 ,
enum V_426 V_82 , int V_442 )
{
int V_56 ;
int V_69 ;
switch ( V_82 ) {
case V_433 :
V_69 = V_443 ;
break;
case V_435 :
V_69 = V_444 ;
break;
default:
F_7 ( & V_14 -> V_22 , L_136 ,
V_113 ) ;
return - V_68 ;
}
if ( V_82 == V_433 && V_442 > V_445 &&
V_442 != V_446 ) {
F_7 ( & V_14 -> V_22 , L_137
L_138 ,
V_437 [ V_82 ] , V_442 ) ;
return - V_68 ;
}
V_56 = F_18 ( V_14 -> V_23 ,
F_218 ( V_442 ) | V_14 -> V_123 ,
V_69 ) ;
if ( V_56 < 0 ) {
F_7 ( & V_14 -> V_22 , L_139
L_140 , V_437 [ V_82 ] ,
V_442 , V_56 ) ;
return - V_311 ;
}
if ( V_82 == V_433 )
V_14 -> V_52 . V_442 = V_442 ;
else
V_14 -> V_53 . V_442 = V_442 ;
return 0 ;
}
static void F_219 ( struct V_196 * V_151 , struct V_1 * V_14 ,
enum V_426 V_82 )
{
int V_442 , V_56 ;
T_4 V_447 = V_14 -> V_17 -> V_21 -> V_50 ;
T_5 V_448 = V_14 -> V_17 -> V_21 -> V_51 ;
if ( ( V_82 == V_433 && V_447 == 0 ) ||
( V_82 == V_435 && V_448 == 0 ) )
return;
V_56 = F_213 ( V_14 , V_82 ) ;
if ( V_56 < 0 ) {
F_7 ( & V_14 -> V_22 , L_141 ,
V_437 [ V_82 ] ) ;
return;
}
V_442 = V_151 -> V_152 -> V_449 ( V_151 , V_14 , V_82 ) ;
if ( V_442 == 0 )
return;
if ( V_442 < 0 ) {
F_7 ( & V_14 -> V_22 , L_142
L_143 , V_437 [ V_82 ] ,
V_442 ) ;
return;
}
if ( F_217 ( V_14 , V_82 , V_442 ) )
V_151 -> V_152 -> V_450 ( V_151 , V_14 , V_82 ) ;
else if ( V_14 -> V_11 )
F_216 ( V_14 , V_82 , true ) ;
}
static int F_220 ( struct V_196 * V_151 , struct V_1 * V_14 ,
enum V_426 V_82 )
{
int V_69 ;
switch ( V_82 ) {
case V_433 :
V_69 = V_443 ;
break;
case V_435 :
V_69 = V_444 ;
break;
default:
F_7 ( & V_14 -> V_22 , L_144 ,
V_113 ) ;
return - V_68 ;
}
if ( F_217 ( V_14 , V_82 , 0 ) )
return - V_311 ;
F_216 ( V_14 , V_82 , false ) ;
if ( V_151 -> V_152 -> V_450 ( V_151 , V_14 , V_82 ) )
F_7 ( & V_14 -> V_22 , L_145
L_146 ,
V_437 [ V_82 ] ) ;
return 0 ;
}
int F_221 ( struct V_1 * V_14 )
{
struct V_196 * V_151 ;
if ( ! V_14 || ! V_14 -> V_23 ||
V_14 -> V_15 != V_49 ||
! V_14 -> V_24 )
return 0 ;
V_151 = F_55 ( V_14 -> V_169 ) ;
if ( ! V_151 || ! V_151 -> V_152 -> V_450 )
return 0 ;
V_14 -> V_451 ++ ;
if ( ( V_14 -> V_52 . V_442 == 0 && V_14 -> V_53 . V_442 == 0 ) )
return 0 ;
if ( F_220 ( V_151 , V_14 , V_433 ) )
goto V_452;
if ( F_220 ( V_151 , V_14 , V_435 ) )
goto V_452;
return 0 ;
V_452:
F_222 ( V_14 ) ;
return - V_311 ;
}
int F_199 ( struct V_1 * V_14 )
{
struct V_196 * V_151 = F_55 ( V_14 -> V_169 ) ;
int V_56 ;
if ( ! V_151 )
return - V_68 ;
F_27 ( V_151 -> V_453 ) ;
V_56 = F_221 ( V_14 ) ;
F_30 ( V_151 -> V_453 ) ;
return V_56 ;
}
void F_222 ( struct V_1 * V_14 )
{
struct V_196 * V_151 ;
if ( ! V_14 || ! V_14 -> V_23 ||
V_14 -> V_15 != V_49 ||
! V_14 -> V_24 )
return;
V_14 -> V_451 -- ;
V_151 = F_55 ( V_14 -> V_169 ) ;
if ( ! V_151 || ! V_151 -> V_152 -> V_449 ||
! V_151 -> V_152 -> V_450 )
return;
if ( V_14 -> V_451 > 0 )
return;
F_219 ( V_151 , V_14 , V_433 ) ;
F_219 ( V_151 , V_14 , V_435 ) ;
}
void F_200 ( struct V_1 * V_14 )
{
struct V_196 * V_151 = F_55 ( V_14 -> V_169 ) ;
if ( ! V_151 )
return;
F_27 ( V_151 -> V_453 ) ;
F_222 ( V_14 ) ;
F_30 ( V_151 -> V_453 ) ;
}
int F_221 ( struct V_1 * V_14 )
{
return 0 ;
}
void F_222 ( struct V_1 * V_14 ) { }
int F_199 ( struct V_1 * V_14 )
{
return 0 ;
}
void F_200 ( struct V_1 * V_14 ) { }
int F_193 ( struct V_1 * V_14 )
{
return 0 ;
}
void F_195 ( struct V_1 * V_14 ) { }
int F_223 ( struct V_6 * V_7 , int V_71 , bool V_454 )
{
int V_56 ;
int V_180 , V_455 = 0 ;
T_1 V_181 , V_8 ;
unsigned V_456 = 0xffff ;
for ( V_180 = 0 ; ; V_180 += V_183 ) {
V_56 = F_26 ( V_7 , V_71 , & V_8 , & V_181 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( ! ( V_181 & V_214 ) &&
( V_8 & V_212 ) == V_456 ) {
if ( ! V_454 ||
( V_456 == V_212 ) )
V_455 += V_183 ;
if ( V_455 >= V_224 )
break;
} else {
V_455 = 0 ;
V_456 = V_8 & V_212 ;
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
V_71 , V_180 , V_455 , V_8 ) ;
if ( V_455 < V_224 )
return - V_103 ;
return V_8 ;
}
void F_224 ( struct V_1 * V_14 )
{
F_225 ( V_14 , 0 + V_64 , true ) ;
F_225 ( V_14 , 0 + V_457 , true ) ;
F_226 ( V_14 , & V_14 -> V_329 , true ) ;
}
static int F_227 ( struct V_1 * V_14 , int V_166 )
{
int V_458 ;
struct V_196 * V_151 = F_55 ( V_14 -> V_169 ) ;
if ( ! V_151 -> V_152 -> V_459 && V_166 <= 1 )
return - V_68 ;
if ( V_14 -> V_82 == V_411 )
return 0 ;
if ( V_14 -> V_82 != V_385 )
return - V_68 ;
if ( V_151 -> V_152 -> V_459 )
V_458 = V_151 -> V_152 -> V_459 ( V_151 , V_14 ) ;
else
V_458 = F_13 ( V_14 , F_228 () ,
V_460 , 0 , V_166 , 0 ,
NULL , 0 , V_205 ) ;
if ( V_458 == 0 ) {
F_133 ( V_14 , V_166 ) ;
F_64 ( V_14 , V_411 ) ;
F_224 ( V_14 ) ;
}
return V_458 ;
}
static int
F_229 ( struct V_6 * V_7 , struct V_1 * V_14 , int V_71 ,
int V_461 )
{
static F_230 ( V_462 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_196 * V_151 = F_55 ( V_2 -> V_169 ) ;
int V_55 , V_463 , V_458 ;
unsigned V_173 = V_376 ;
enum V_464 V_465 = V_14 -> V_15 ;
const char * V_15 ;
int V_166 = V_14 -> V_166 ;
if ( ! V_2 -> V_23 ) {
V_173 = V_466 ;
if ( V_71 == V_2 -> V_169 -> V_346 )
V_2 -> V_169 -> V_347 = 0 ;
}
if ( V_465 == V_380 )
V_173 = V_377 ;
F_27 ( & V_462 ) ;
V_458 = F_187 ( V_7 , V_71 , V_14 , V_173 , false ) ;
if ( V_458 < 0 )
goto V_243;
V_458 = - V_137 ;
if ( V_465 != V_467 && V_465 != V_14 -> V_15 ) {
F_20 ( & V_14 -> V_22 , L_148 ) ;
goto V_243;
}
V_465 = V_14 -> V_15 ;
switch ( V_14 -> V_15 ) {
case V_49 :
case V_379 :
V_14 -> V_329 . V_275 . V_468 = F_215 ( 512 ) ;
break;
case V_16 :
V_14 -> V_329 . V_275 . V_468 = F_215 ( 64 ) ;
break;
case V_381 :
V_14 -> V_329 . V_275 . V_468 = F_215 ( 64 ) ;
break;
case V_380 :
V_14 -> V_329 . V_275 . V_468 = F_215 ( 8 ) ;
break;
default:
goto V_243;
}
if ( V_14 -> V_15 == V_379 )
V_15 = L_149 ;
else
V_15 = F_231 ( V_14 -> V_15 ) ;
if ( V_14 -> V_15 != V_49 )
F_84 ( & V_14 -> V_22 ,
L_150 ,
( V_14 -> V_340 ) ? L_151 : L_152 , V_15 ,
V_166 , V_14 -> V_169 -> V_469 -> V_152 -> V_470 ) ;
if ( V_2 -> V_140 ) {
V_14 -> V_140 = V_2 -> V_140 ;
V_14 -> V_165 = V_2 -> V_165 ;
} else if ( V_14 -> V_15 != V_16
&& V_2 -> V_15 == V_16 ) {
if ( ! V_7 -> V_140 . V_7 ) {
F_28 ( & V_14 -> V_22 , L_153 ) ;
V_458 = - V_68 ;
goto V_243;
}
V_14 -> V_140 = & V_7 -> V_140 ;
V_14 -> V_165 = V_71 ;
}
for ( V_55 = 0 ; V_55 < V_471 ; ( ++ V_55 , F_59 ( 100 ) ) ) {
if ( F_232 ( V_461 ) && ! ( V_151 -> V_152 -> V_117 & V_472 ) ) {
struct V_473 * V_474 ;
int V_475 = 0 ;
#define F_233 64
V_474 = F_51 ( F_233 , V_211 ) ;
if ( ! V_474 ) {
V_458 = - V_163 ;
continue;
}
for ( V_463 = 0 ; V_463 < 3 ; ++ V_463 ) {
V_474 -> V_476 = 0 ;
V_475 = F_13 ( V_14 , F_234 () ,
V_63 , V_64 ,
V_477 << 8 , 0 ,
V_474 , F_233 ,
V_478 ) ;
switch ( V_474 -> V_476 ) {
case 8 : case 16 : case 32 : case 64 : case 255 :
if ( V_474 -> V_479 ==
V_477 ) {
V_475 = 0 ;
break;
}
default:
if ( V_475 == 0 )
V_475 = - V_480 ;
break;
}
if ( V_475 == 0 )
break;
}
V_14 -> V_3 . V_476 =
V_474 -> V_476 ;
F_48 ( V_474 ) ;
V_458 = F_187 ( V_7 , V_71 , V_14 , V_173 , false ) ;
if ( V_458 < 0 )
goto V_243;
if ( V_465 != V_14 -> V_15 ) {
F_20 ( & V_14 -> V_22 ,
L_148 ) ;
V_458 = - V_137 ;
goto V_243;
}
if ( V_475 ) {
F_28 ( & V_14 -> V_22 ,
L_154 ,
V_475 ) ;
V_458 = - V_481 ;
continue;
}
#undef F_233
}
if ( V_14 -> V_321 == 0 ) {
for ( V_463 = 0 ; V_463 < V_482 ; ++ V_463 ) {
V_458 = F_227 ( V_14 , V_166 ) ;
if ( V_458 >= 0 )
break;
F_59 ( 200 ) ;
}
if ( V_458 < 0 ) {
F_28 ( & V_14 -> V_22 ,
L_155 ,
V_166 , V_458 ) ;
goto V_243;
}
if ( V_14 -> V_15 == V_49 ) {
V_166 = V_14 -> V_166 ;
F_84 ( & V_14 -> V_22 ,
L_156 ,
( V_14 -> V_340 ) ? L_151 : L_152 ,
V_166 , V_14 -> V_169 -> V_469 -> V_152 -> V_470 ) ;
}
F_59 ( 10 ) ;
if ( F_232 ( V_461 ) && ! ( V_151 -> V_152 -> V_117 & V_472 ) )
break;
}
V_458 = F_180 ( V_14 , 8 ) ;
if ( V_458 < 8 ) {
F_28 ( & V_14 -> V_22 ,
L_157 ,
V_458 ) ;
if ( V_458 >= 0 )
V_458 = - V_481 ;
} else {
V_458 = 0 ;
break;
}
}
if ( V_458 )
goto V_243;
if ( V_151 -> V_483 && ! V_2 -> V_23 )
F_235 ( V_151 -> V_483 , V_14 -> V_15 ) ;
if ( ( V_14 -> V_15 == V_49 ) &&
( F_29 ( V_14 -> V_3 . V_484 ) < 0x0300 ) ) {
F_28 ( & V_14 -> V_22 , L_158
L_159 ) ;
F_187 ( V_7 , V_71 , V_14 ,
V_485 , true ) ;
V_458 = - V_68 ;
goto V_243;
}
if ( V_14 -> V_3 . V_476 == 0xff ||
V_14 -> V_15 == V_49 )
V_55 = 512 ;
else
V_55 = V_14 -> V_3 . V_476 ;
if ( F_236 ( & V_14 -> V_329 . V_275 ) != V_55 ) {
if ( V_14 -> V_15 == V_380 ||
! ( V_55 == 8 || V_55 == 16 || V_55 == 32 || V_55 == 64 ) ) {
F_28 ( & V_14 -> V_22 , L_160 , V_55 ) ;
V_458 = - V_481 ;
goto V_243;
}
if ( V_14 -> V_15 == V_381 )
F_20 ( & V_14 -> V_22 , L_161 , V_55 ) ;
else
F_7 ( & V_14 -> V_22 , L_162 , V_55 ) ;
V_14 -> V_329 . V_275 . V_468 = F_215 ( V_55 ) ;
F_224 ( V_14 ) ;
}
V_458 = F_180 ( V_14 , V_486 ) ;
if ( V_458 < ( signed ) sizeof( V_14 -> V_3 ) ) {
F_28 ( & V_14 -> V_22 , L_163 ,
V_458 ) ;
if ( V_458 >= 0 )
V_458 = - V_487 ;
goto V_243;
}
if ( V_14 -> V_321 == 0 && F_29 ( V_14 -> V_3 . V_484 ) >= 0x0201 ) {
V_458 = F_237 ( V_14 ) ;
if ( ! V_458 ) {
V_14 -> V_24 = F_5 ( V_14 ) ;
F_11 ( V_14 ) ;
}
}
V_458 = 0 ;
if ( V_151 -> V_152 -> V_488 )
V_151 -> V_152 -> V_488 ( V_151 , V_14 ) ;
V_243:
if ( V_458 ) {
F_63 ( V_7 , V_71 , 0 ) ;
F_133 ( V_14 , V_166 ) ;
}
F_30 ( & V_462 ) ;
return V_458 ;
}
static void
F_238 ( struct V_6 * V_7 , struct V_1 * V_14 , int V_71 )
{
struct V_489 * V_490 ;
int V_75 ;
V_490 = F_51 ( sizeof *V_490 , V_242 ) ;
if ( V_490 == NULL )
return;
V_75 = F_239 ( V_14 , V_491 , 0 ,
V_490 , sizeof *V_490 ) ;
if ( V_75 == sizeof *V_490 ) {
F_84 ( & V_14 -> V_22 , L_164
L_165 ) ;
if ( V_7 -> V_226 ) {
V_7 -> V_87 [ V_71 - 1 ] = V_91 ;
F_23 ( & V_7 -> V_79 , 0 ) ;
}
}
F_48 ( V_490 ) ;
}
static unsigned
F_240 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_273 ;
int V_71 ;
if ( ! V_7 -> V_271 )
return 0 ;
V_273 = V_2 -> V_269 - V_7 -> V_3 -> V_274 ;
for ( V_71 = 1 ; V_71 <= V_2 -> V_12 ; ++ V_71 ) {
struct V_1 * V_14 = V_7 -> V_158 [ V_71 - 1 ] -> V_188 ;
int V_492 ;
unsigned V_240 ;
if ( ! V_14 )
continue;
if ( F_1 ( V_14 ) )
V_240 = 150 ;
else
V_240 = 100 ;
if ( V_14 -> V_11 )
V_492 = F_241 ( V_14 , V_14 -> V_11 ) ;
else if ( V_71 != V_14 -> V_169 -> V_346 || V_2 -> V_23 )
V_492 = V_240 ;
else
V_492 = 8 ;
if ( V_492 > V_7 -> V_270 )
F_7 ( & V_14 -> V_22 ,
L_166 ,
V_492 , V_7 -> V_270 , V_71 ) ;
V_273 -= V_492 ;
}
if ( V_273 < 0 ) {
F_7 ( V_7 -> V_112 , L_167 ,
- V_273 ) ;
V_273 = 0 ;
}
return V_273 ;
}
static void F_242 ( struct V_6 * V_7 , int V_71 ,
T_1 V_8 , T_1 V_181 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_234 * V_235 = V_7 -> V_112 ;
struct V_196 * V_151 = F_55 ( V_2 -> V_169 ) ;
unsigned V_174 =
F_29 ( V_7 -> V_3 -> V_174 ) ;
struct V_1 * V_14 ;
int V_75 , V_55 ;
unsigned V_240 ;
F_20 ( V_235 ,
L_168 ,
V_71 , V_8 , V_181 , F_2 ( V_7 , V_8 ) ) ;
if ( V_7 -> V_226 ) {
F_19 ( V_7 , V_71 , V_89 ) ;
V_7 -> V_87 [ V_71 - 1 ] = V_90 ;
}
#ifdef F_147
if ( V_2 -> V_169 -> V_339 )
V_181 &= ~ ( V_214 |
V_216 ) ;
#endif
V_14 = V_7 -> V_158 [ V_71 - 1 ] -> V_188 ;
if ( ( V_8 & V_212 ) && V_14 &&
V_14 -> V_82 != V_189 ) {
F_135 ( V_14 ) ;
if ( V_8 & V_213 ) {
V_75 = 0 ;
#ifdef F_243
} else if ( V_14 -> V_82 == V_313 &&
V_14 -> V_222 ) {
V_75 = F_206 ( V_14 ) ;
#endif
} else {
V_75 = - V_137 ;
}
F_141 ( V_14 ) ;
if ( V_75 == 0 ) {
F_72 ( V_71 , V_7 -> V_191 ) ;
return;
}
}
if ( V_14 ) {
if ( V_151 -> V_483 && ! V_2 -> V_23 &&
! ( V_8 & V_212 ) )
F_244 ( V_151 -> V_483 , V_14 -> V_15 ) ;
F_77 ( & V_7 -> V_158 [ V_71 - 1 ] -> V_188 ) ;
}
F_72 ( V_71 , V_7 -> V_191 ) ;
if ( ! ( V_8 & V_212 ) ||
( V_181 & V_214 ) )
F_72 ( V_71 , V_7 -> V_194 ) ;
if ( V_181 & ( V_214 |
V_216 ) ) {
V_75 = F_245 ( V_7 , V_71 ) ;
if ( V_75 < 0 ) {
if ( F_246 () )
F_28 ( V_235 , L_169
L_170 , V_71 ) ;
V_8 &= ~ V_212 ;
} else {
V_8 = V_75 ;
}
}
if ( ! ( V_8 & V_212 ) ||
F_130 ( V_71 , V_7 -> V_194 ) ) {
if ( ( V_174 & V_175 ) < 2
&& ! F_190 ( V_7 , V_8 ) )
F_18 ( V_2 , V_71 , V_159 ) ;
if ( V_8 & V_213 )
goto V_387;
return;
}
if ( F_1 ( V_7 -> V_2 ) )
V_240 = 150 ;
else
V_240 = 100 ;
for ( V_55 = 0 ; V_55 < V_493 ; V_55 ++ ) {
V_14 = F_247 ( V_2 , V_2 -> V_169 , V_71 ) ;
if ( ! V_14 ) {
F_28 ( V_235 ,
L_171 ,
V_71 ) ;
goto V_387;
}
F_64 ( V_14 , V_494 ) ;
V_14 -> V_269 = V_7 -> V_270 ;
V_14 -> V_204 = V_2 -> V_204 + 1 ;
V_14 -> V_321 = F_183 ( V_7 ) ;
if ( F_1 ( V_7 -> V_2 ) )
V_14 -> V_15 = V_49 ;
else
V_14 -> V_15 = V_467 ;
F_128 ( V_14 ) ;
if ( V_14 -> V_166 <= 0 ) {
V_75 = - V_378 ;
goto V_495;
}
V_75 = F_229 ( V_7 , V_14 , V_71 , V_55 ) ;
if ( V_75 < 0 )
goto V_495;
F_248 ( V_14 ) ;
if ( V_14 -> V_496 & V_497 )
F_59 ( 1000 ) ;
if ( V_14 -> V_3 . V_498 == V_499
&& V_14 -> V_269 <= V_240 ) {
T_1 V_500 ;
V_75 = F_90 ( V_14 , V_266 , 0 ,
& V_500 ) ;
if ( V_75 < 2 ) {
F_20 ( & V_14 -> V_22 , L_172 , V_75 ) ;
goto V_501;
}
F_91 ( & V_500 ) ;
if ( ( V_500 & ( 1 << V_272 ) ) == 0 ) {
F_28 ( & V_14 -> V_22 ,
L_173
L_174 ) ;
if ( V_7 -> V_226 ) {
V_7 -> V_87 [ V_71 - 1 ] =
V_95 ;
F_23 ( & V_7 -> V_79 , 0 ) ;
}
V_75 = - V_378 ;
goto V_501;
}
}
if ( F_29 ( V_14 -> V_3 . V_484 ) >= 0x0200
&& V_14 -> V_15 == V_381
&& V_283 != 0 )
F_238 ( V_7 , V_14 , V_71 ) ;
V_75 = 0 ;
F_103 ( & V_302 ) ;
if ( V_2 -> V_82 == V_189 )
V_75 = - V_378 ;
else
V_7 -> V_158 [ V_71 - 1 ] -> V_188 = V_14 ;
F_106 ( & V_302 ) ;
if ( ! V_75 ) {
V_75 = F_157 ( V_14 ) ;
if ( V_75 ) {
F_103 ( & V_302 ) ;
V_7 -> V_158 [ V_71 - 1 ] -> V_188 = NULL ;
F_106 ( & V_302 ) ;
}
}
if ( V_75 )
goto V_501;
V_75 = F_240 ( V_7 ) ;
if ( V_75 )
F_20 ( V_235 , L_175 , V_75 ) ;
return;
V_501:
F_63 ( V_7 , V_71 , 1 ) ;
V_495:
F_224 ( V_14 ) ;
F_132 ( V_14 ) ;
F_134 ( V_14 ) ;
F_249 ( V_14 ) ;
if ( ( V_75 == - V_378 ) || ( V_75 == - V_351 ) )
break;
}
if ( V_7 -> V_2 -> V_23 ||
! V_151 -> V_152 -> V_502 ||
! ( V_151 -> V_152 -> V_502 ) ( V_151 , V_71 ) )
F_28 ( V_235 , L_176 ,
V_71 ) ;
V_387:
F_63 ( V_7 , V_71 , 1 ) ;
if ( V_151 -> V_152 -> V_503 && ! V_7 -> V_2 -> V_23 )
V_151 -> V_152 -> V_503 ( V_151 , V_71 ) ;
}
static int F_250 ( struct V_6 * V_7 , unsigned int V_111 ,
T_1 V_8 , T_1 V_181 )
{
struct V_1 * V_2 ;
struct V_1 * V_14 ;
int V_504 = 0 ;
int V_56 ;
V_2 = V_7 -> V_2 ;
V_14 = V_7 -> V_158 [ V_111 - 1 ] -> V_188 ;
if ( ! F_1 ( V_2 ) ) {
if ( ! ( V_181 & V_418 ) )
return 0 ;
F_17 ( V_2 , V_111 , V_419 ) ;
} else {
if ( ! V_14 || V_14 -> V_82 != V_313 ||
( V_8 & V_184 ) !=
V_221 )
return 0 ;
}
if ( V_14 ) {
F_59 ( 10 ) ;
F_135 ( V_14 ) ;
V_56 = F_206 ( V_14 ) ;
F_141 ( V_14 ) ;
if ( V_56 < 0 )
V_504 = 1 ;
} else {
V_56 = - V_137 ;
F_63 ( V_7 , V_111 , 1 ) ;
}
F_20 ( V_7 -> V_112 , L_177 ,
V_111 , V_56 ) ;
return V_504 ;
}
static void F_251 ( void )
{
struct V_145 * V_505 ;
struct V_1 * V_2 ;
struct V_192 * V_193 ;
struct V_6 * V_7 ;
struct V_234 * V_235 ;
T_1 V_236 ;
T_1 V_237 ;
T_1 V_8 ;
T_1 V_181 ;
int V_55 , V_56 ;
int V_504 , V_506 ;
while ( 1 ) {
F_103 ( & V_118 ) ;
if ( F_33 ( & V_121 ) ) {
F_106 ( & V_118 ) ;
break;
}
V_505 = V_121 . V_146 ;
F_104 ( V_505 ) ;
V_7 = F_46 ( V_505 , struct V_6 , V_120 ) ;
F_252 ( & V_7 -> V_281 ) ;
F_106 ( & V_118 ) ;
V_2 = V_7 -> V_2 ;
V_235 = V_7 -> V_112 ;
V_193 = F_36 ( V_235 ) ;
F_20 ( V_235 , L_178 ,
V_2 -> V_82 , V_7 -> V_3
? V_7 -> V_3 -> V_85
: 0 ,
( T_1 ) V_7 -> V_191 [ 0 ] ,
( T_1 ) V_7 -> V_135 [ 0 ] ) ;
F_135 ( V_2 ) ;
if ( F_253 ( V_7 -> V_119 ) )
goto V_507;
if ( V_2 -> V_82 == V_189 ) {
V_7 -> error = - V_137 ;
F_75 ( V_7 , V_282 ) ;
goto V_495;
}
V_56 = F_67 ( V_193 ) ;
if ( V_56 ) {
F_20 ( V_235 , L_179 , V_56 ) ;
goto V_495;
}
if ( V_7 -> V_84 )
goto V_508;
if ( V_7 -> error ) {
F_20 ( V_235 , L_180 ,
V_7 -> error ) ;
V_56 = F_254 ( V_2 ) ;
if ( V_56 ) {
F_20 ( V_235 ,
L_181 , V_56 ) ;
goto V_508;
}
V_7 -> V_131 = 0 ;
V_7 -> error = 0 ;
}
for ( V_55 = 1 ; V_55 <= V_7 -> V_3 -> V_85 ; V_55 ++ ) {
if ( F_130 ( V_55 , V_7 -> V_416 ) )
continue;
V_504 = F_130 ( V_55 , V_7 -> V_191 ) ;
V_506 = F_255 ( V_55 , V_7 -> V_124 ) ;
if ( ! F_255 ( V_55 , V_7 -> V_135 ) &&
! V_504 && ! V_506 )
continue;
V_56 = F_26 ( V_7 , V_55 ,
& V_8 , & V_181 ) ;
if ( V_56 < 0 )
continue;
if ( V_181 & V_214 ) {
F_17 ( V_2 , V_55 ,
V_215 ) ;
V_504 = 1 ;
}
if ( V_181 & V_216 ) {
if ( ! V_504 )
F_20 ( V_235 ,
L_182
L_183 ,
V_55 , V_8 ) ;
F_17 ( V_2 , V_55 ,
V_217 ) ;
if ( ! ( V_8 & V_213 )
&& ! V_504
&& V_7 -> V_158 [ V_55 - 1 ] -> V_188 ) {
F_28 ( V_235 ,
L_184
L_185
L_186 ,
V_55 ) ;
V_504 = 1 ;
}
}
if ( F_250 ( V_7 , V_55 ,
V_8 , V_181 ) )
V_504 = 1 ;
if ( V_181 & V_509 ) {
T_1 V_75 = 0 ;
T_1 V_510 ;
F_20 ( V_235 , L_187
L_188 , V_55 ) ;
F_17 ( V_2 , V_55 ,
V_511 ) ;
F_59 ( 100 ) ;
F_57 ( V_7 , true ) ;
F_26 ( V_7 , V_55 , & V_75 , & V_510 ) ;
if ( V_75 & V_512 )
F_28 ( V_235 , L_189
L_190 , V_55 ) ;
}
if ( V_181 & V_513 ) {
F_20 ( V_235 ,
L_191 ,
V_55 ) ;
F_17 ( V_2 , V_55 ,
V_383 ) ;
}
if ( ( V_181 & V_218 ) &&
F_1 ( V_7 -> V_2 ) ) {
F_20 ( V_235 ,
L_192 ,
V_55 ) ;
F_17 ( V_2 , V_55 ,
V_219 ) ;
}
if ( V_181 & V_417 ) {
F_17 ( V_7 -> V_2 , V_55 ,
V_384 ) ;
}
if ( V_181 & V_514 ) {
F_7 ( V_235 ,
L_193 ,
V_55 ) ;
F_17 ( V_7 -> V_2 , V_55 ,
V_515 ) ;
}
if ( F_184 ( V_7 , V_8 ) ) {
int V_75 ;
struct V_1 * V_14 =
V_7 -> V_158 [ V_55 - 1 ] -> V_188 ;
F_20 ( V_235 , L_194 , V_55 ) ;
if ( ! V_14 ) {
V_75 = F_187 ( V_7 , V_55 ,
NULL , V_485 ,
true ) ;
if ( V_75 < 0 )
F_63 ( V_7 , V_55 , 1 ) ;
} else {
F_135 ( V_14 ) ;
V_75 = F_254 ( V_14 ) ;
F_141 ( V_14 ) ;
}
V_504 = 0 ;
}
if ( V_504 )
F_242 ( V_7 , V_55 ,
V_8 , V_181 ) ;
}
if ( F_255 ( 0 , V_7 -> V_135 ) == 0 )
;
else if ( F_60 ( V_7 , & V_236 , & V_237 ) < 0 )
F_28 ( V_235 , L_195 ) ;
else {
if ( V_237 & V_516 ) {
F_20 ( V_235 , L_196 ) ;
F_15 ( V_2 , V_517 ) ;
if ( V_236 & V_277 )
V_7 -> V_271 = 1 ;
else
V_7 -> V_271 = 0 ;
}
if ( V_237 & V_518 ) {
T_1 V_75 = 0 ;
T_1 V_510 ;
F_20 ( V_235 , L_197 ) ;
F_15 ( V_2 , V_519 ) ;
F_59 ( 500 ) ;
F_57 ( V_7 , true ) ;
F_60 ( V_7 , & V_75 , & V_510 ) ;
if ( V_75 & V_278 )
F_28 ( V_235 , L_189
L_198 ) ;
}
}
V_508:
F_105 ( V_193 ) ;
V_495:
F_68 ( V_193 ) ;
V_507:
F_141 ( V_2 ) ;
F_111 ( & V_7 -> V_281 , F_99 ) ;
}
}
static int F_256 ( void * V_520 )
{
F_257 () ;
do {
F_251 () ;
F_258 ( V_122 ,
! F_33 ( & V_121 ) ||
F_259 () ) ;
} while ( ! F_259 () || ! F_33 ( & V_121 ) );
F_260 ( L_199 , V_521 ) ;
return 0 ;
}
int F_261 ( void )
{
if ( F_262 ( & V_522 ) < 0 ) {
F_263 ( V_523 L_200 ,
V_521 ) ;
return - 1 ;
}
V_524 = F_264 ( F_256 , NULL , L_201 ) ;
if ( ! F_265 ( V_524 ) )
return 0 ;
F_266 ( & V_522 ) ;
F_263 ( V_523 L_202 , V_521 ) ;
return - 1 ;
}
void F_267 ( void )
{
F_268 ( V_524 ) ;
F_266 ( & V_522 ) ;
}
static int F_269 ( struct V_1 * V_14 ,
struct V_473 * V_525 )
{
int V_80 = 0 ;
unsigned V_526 ;
unsigned V_527 = 0 ;
unsigned V_528 ;
unsigned V_529 ;
int V_530 ;
char * V_474 ;
if ( memcmp ( & V_14 -> V_3 , V_525 ,
sizeof( * V_525 ) ) != 0 )
return 1 ;
if ( V_14 -> V_337 )
V_527 = strlen ( V_14 -> V_337 ) + 1 ;
V_528 = V_527 ;
for ( V_526 = 0 ; V_526 < V_14 -> V_3 . V_361 ; V_526 ++ ) {
V_529 = F_29 ( V_14 -> V_340 [ V_526 ] . V_275 . V_343 ) ;
V_528 = F_58 ( V_528 , V_529 ) ;
}
V_474 = F_51 ( V_528 , V_211 ) ;
if ( V_474 == NULL ) {
F_28 ( & V_14 -> V_22 , L_203 ) ;
return 1 ;
}
for ( V_526 = 0 ; V_526 < V_14 -> V_3 . V_361 ; V_526 ++ ) {
V_529 = F_29 ( V_14 -> V_340 [ V_526 ] . V_275 . V_343 ) ;
V_530 = F_239 ( V_14 , V_531 , V_526 , V_474 ,
V_529 ) ;
if ( V_530 != V_529 ) {
F_20 ( & V_14 -> V_22 , L_204 ,
V_526 , V_530 ) ;
V_80 = 1 ;
break;
}
if ( memcmp ( V_474 , V_14 -> V_342 [ V_526 ] , V_529 )
!= 0 ) {
F_20 ( & V_14 -> V_22 , L_205 ,
V_526 ,
( (struct V_532 * ) V_474 ) ->
V_533 ) ;
V_80 = 1 ;
break;
}
}
if ( ! V_80 && V_527 ) {
V_530 = F_270 ( V_14 , V_14 -> V_3 . V_334 ,
V_474 , V_527 ) ;
if ( V_530 + 1 != V_527 ) {
F_20 ( & V_14 -> V_22 , L_206 ,
V_530 ) ;
V_80 = 1 ;
} else if ( memcmp ( V_474 , V_14 -> V_337 , V_530 ) != 0 ) {
F_20 ( & V_14 -> V_22 , L_207 ) ;
V_80 = 1 ;
}
}
F_48 ( V_474 ) ;
return V_80 ;
}
static int F_204 ( struct V_1 * V_14 )
{
struct V_1 * V_534 = V_14 -> V_23 ;
struct V_6 * V_535 ;
struct V_196 * V_151 = F_55 ( V_14 -> V_169 ) ;
struct V_473 V_3 = V_14 -> V_3 ;
int V_55 , V_56 = 0 ;
int V_71 = V_14 -> V_123 ;
if ( V_14 -> V_82 == V_189 ||
V_14 -> V_82 == V_313 ) {
F_20 ( & V_14 -> V_22 , L_208 ,
V_14 -> V_82 ) ;
return - V_68 ;
}
if ( ! V_534 ) {
F_20 ( & V_14 -> V_22 , L_209 , V_113 ) ;
return - V_536 ;
}
V_535 = F_3 ( V_534 ) ;
V_56 = F_199 ( V_14 ) ;
if ( V_56 ) {
F_28 ( & V_14 -> V_22 , L_210 , V_113 ) ;
goto V_537;
}
V_56 = F_193 ( V_14 ) ;
if ( V_56 ) {
F_28 ( & V_14 -> V_22 , L_211 ,
V_113 ) ;
goto V_537;
}
F_41 ( V_71 , V_535 -> V_416 ) ;
for ( V_55 = 0 ; V_55 < V_493 ; ++ V_55 ) {
F_224 ( V_14 ) ;
V_56 = F_229 ( V_535 , V_14 , V_71 , V_55 ) ;
if ( V_56 >= 0 || V_56 == - V_378 || V_56 == - V_137 )
break;
}
F_72 ( V_71 , V_535 -> V_416 ) ;
if ( V_56 < 0 )
goto V_537;
if ( F_269 ( V_14 , & V_3 ) ) {
F_84 ( & V_14 -> V_22 , L_212 ) ;
V_14 -> V_3 = V_3 ;
goto V_537;
}
if ( ! V_14 -> V_11 )
goto V_387;
F_27 ( V_151 -> V_453 ) ;
V_56 = F_271 ( V_14 , V_14 -> V_11 , NULL , NULL ) ;
if ( V_56 < 0 ) {
F_7 ( & V_14 -> V_22 ,
L_213
L_214 ) ;
F_30 ( V_151 -> V_453 ) ;
goto V_537;
}
V_56 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_538 , 0 ,
V_14 -> V_11 -> V_275 . V_533 , 0 ,
NULL , 0 , V_205 ) ;
if ( V_56 < 0 ) {
F_28 ( & V_14 -> V_22 ,
L_215 ,
V_14 -> V_11 -> V_275 . V_533 , V_56 ) ;
F_30 ( V_151 -> V_453 ) ;
goto V_537;
}
F_30 ( V_151 -> V_453 ) ;
F_64 ( V_14 , V_83 ) ;
for ( V_55 = 0 ; V_55 < V_14 -> V_11 -> V_275 . V_539 ; V_55 ++ ) {
struct V_540 * V_340 = V_14 -> V_11 ;
struct V_192 * V_193 = V_340 -> V_13 [ V_55 ] ;
struct V_541 * V_275 ;
V_275 = & V_193 -> V_287 -> V_275 ;
if ( V_275 -> V_542 == 0 ) {
F_272 ( V_14 , V_193 , true ) ;
F_273 ( V_14 , V_193 , true ) ;
V_56 = 0 ;
} else {
V_193 -> V_543 = 1 ;
V_56 = F_89 ( V_14 , V_275 -> V_544 ,
V_275 -> V_542 ) ;
V_193 -> V_543 = 0 ;
}
if ( V_56 < 0 ) {
F_28 ( & V_14 -> V_22 , L_216
L_217 ,
V_275 -> V_544 ,
V_275 -> V_542 ,
V_56 ) ;
goto V_537;
}
}
V_387:
F_200 ( V_14 ) ;
F_195 ( V_14 ) ;
return 0 ;
V_537:
F_65 ( V_535 , V_71 ) ;
return - V_137 ;
}
int F_254 ( struct V_1 * V_14 )
{
int V_56 ;
int V_55 ;
unsigned int V_545 ;
struct V_540 * V_340 = V_14 -> V_11 ;
if ( V_14 -> V_82 == V_189 ||
V_14 -> V_82 == V_313 ) {
F_20 ( & V_14 -> V_22 , L_208 ,
V_14 -> V_82 ) ;
return - V_68 ;
}
V_545 = F_274 () ;
F_179 ( V_14 ) ;
if ( V_340 ) {
for ( V_55 = 0 ; V_55 < V_340 -> V_275 . V_539 ; ++ V_55 ) {
struct V_192 * V_546 = V_340 -> V_13 [ V_55 ] ;
struct V_547 * V_150 ;
int V_548 = 0 ;
if ( V_546 -> V_22 . V_152 ) {
V_150 = F_275 ( V_546 -> V_22 . V_152 ) ;
if ( V_150 -> V_549 && V_150 -> V_550 )
V_548 = ( V_150 -> V_549 ) ( V_546 ) ;
else if ( V_546 -> V_551 ==
V_552 )
V_548 = 1 ;
if ( V_548 )
F_276 ( V_546 ) ;
}
}
}
V_56 = F_204 ( V_14 ) ;
if ( V_340 ) {
for ( V_55 = V_340 -> V_275 . V_539 - 1 ; V_55 >= 0 ; -- V_55 ) {
struct V_192 * V_546 = V_340 -> V_13 [ V_55 ] ;
struct V_547 * V_150 ;
int V_553 = V_546 -> V_554 ;
if ( ! V_553 && V_546 -> V_22 . V_152 ) {
V_150 = F_275 ( V_546 -> V_22 . V_152 ) ;
if ( V_150 -> V_550 )
V_553 = ( V_150 -> V_550 ) ( V_546 ) ;
else if ( V_546 -> V_551 ==
V_552 )
V_553 = 1 ;
}
if ( V_56 == 0 && V_553 )
F_277 ( V_546 ) ;
}
}
F_182 ( V_14 ) ;
F_278 ( V_545 ) ;
return V_56 ;
}
void F_279 ( struct V_192 * V_555 )
{
F_56 ( & V_555 -> V_556 ) ;
}
struct V_1 * F_280 ( struct V_1 * V_2 ,
int V_71 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_71 < 1 || V_71 > V_2 -> V_12 )
return NULL ;
return V_7 -> V_158 [ V_71 - 1 ] -> V_188 ;
}
void F_281 ( struct V_1 * V_2 , int V_71 ,
enum V_557 type )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
V_7 -> V_158 [ V_71 - 1 ] -> V_558 = type ;
}
enum V_557
F_282 ( struct V_1 * V_2 , int V_71 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
return V_7 -> V_158 [ V_71 - 1 ] -> V_558 ;
}
void F_98 ( struct V_1 * V_2 ,
struct V_62 * V_275 )
{
enum V_557 V_558 ;
int V_55 ;
if ( ! F_1 ( V_2 ) ) {
for ( V_55 = 1 ; V_55 <= V_2 -> V_12 ; V_55 ++ ) {
V_558 = F_282 ( V_2 , V_55 ) ;
if ( V_558 == V_559 ) {
T_2 V_560 = 1 << ( V_55 % 8 ) ;
if ( ! ( V_275 -> V_34 . V_247 . V_248 [ V_55 / 8 ] & V_560 ) ) {
F_20 ( & V_2 -> V_22 , L_218 ,
V_55 ) ;
V_275 -> V_34 . V_247 . V_248 [ V_55 / 8 ] |= V_560 ;
}
}
}
} else {
T_1 V_561 = F_29 ( V_275 -> V_34 . V_35 . V_248 ) ;
for ( V_55 = 1 ; V_55 <= V_2 -> V_12 ; V_55 ++ ) {
V_558 = F_282 ( V_2 , V_55 ) ;
if ( V_558 == V_559 ) {
T_1 V_560 = 1 << V_55 ;
if ( ! ( V_561 & V_560 ) ) {
F_20 ( & V_2 -> V_22 , L_218 ,
V_55 ) ;
V_561 |= V_560 ;
}
}
}
V_275 -> V_34 . V_35 . V_248 = F_215 ( V_561 ) ;
}
}
T_6 F_283 ( struct V_1 * V_2 ,
int V_71 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
return F_284 ( & V_7 -> V_158 [ V_71 - 1 ] -> V_22 ) ;
}
