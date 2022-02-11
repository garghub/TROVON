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
int F_5 ( struct V_1 * V_14 )
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
if ( ! V_14 -> V_23 )
return 1 ;
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
V_46 = F_12 ( V_14 -> V_17 -> V_21 -> V_51 ) ;
V_47 = V_14 -> V_23 -> V_17 -> V_21 -> V_50 ;
V_48 = F_12 ( V_14 -> V_23 -> V_17 -> V_21 -> V_51 ) ;
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
F_24 ( & V_7 -> V_79 , V_100 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_101 * V_54 )
{
int V_55 , V_75 = - V_102 ;
for ( V_55 = 0 ; V_55 < V_103 &&
( V_75 == - V_102 || V_75 == - V_104 ) ; V_55 ++ ) {
V_75 = F_14 ( V_2 , F_15 ( V_2 , 0 ) ,
V_105 , V_64 | V_65 , 0 , 0 ,
V_54 , sizeof( * V_54 ) , V_106 ) ;
}
return V_75 ;
}
static int F_26 ( struct V_1 * V_2 , int V_71 ,
struct V_107 * V_54 )
{
int V_55 , V_75 = - V_102 ;
for ( V_55 = 0 ; V_55 < V_103 &&
( V_75 == - V_102 || V_75 == - V_104 ) ; V_55 ++ ) {
V_75 = F_14 ( V_2 , F_15 ( V_2 , 0 ) ,
V_105 , V_64 | V_72 , 0 , V_71 ,
V_54 , sizeof( * V_54 ) , V_106 ) ;
}
return V_75 ;
}
static int F_27 ( struct V_6 * V_7 , int V_71 ,
T_1 * V_75 , T_1 * V_108 )
{
int V_56 ;
F_28 ( & V_7 -> V_109 ) ;
V_56 = F_26 ( V_7 -> V_2 , V_71 , & V_7 -> V_75 -> V_110 ) ;
if ( V_56 < 4 ) {
if ( V_56 != - V_111 )
F_29 ( V_7 -> V_112 ,
L_14 , V_113 , V_56 ) ;
if ( V_56 >= 0 )
V_56 = - V_114 ;
} else {
* V_75 = F_12 ( V_7 -> V_75 -> V_110 . V_115 ) ;
* V_108 = F_12 ( V_7 -> V_75 -> V_110 . V_116 ) ;
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
F_21 ( V_7 -> V_112 , L_15 , V_75 ) ;
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
F_29 ( V_7 -> V_112 , L_16 , V_75 ) ;
}
static inline int
F_44 ( struct V_1 * V_2 , T_1 V_138 , T_1 V_139 )
{
if ( ( ( V_138 >> 11 ) & V_140 ) ==
V_141 ) {
int V_75 = F_14 ( V_2 , F_17 ( V_2 , 0 ) ,
V_142 , V_72 ,
V_138 ^ 0x8000 , V_139 , NULL , 0 , 1000 ) ;
if ( V_75 )
return V_75 ;
}
return F_14 ( V_2 , F_17 ( V_2 , 0 ) ,
V_142 , V_72 , V_138 ,
V_139 , NULL , 0 , 1000 ) ;
}
static void F_45 ( struct V_77 * V_78 )
{
struct V_6 * V_7 =
F_23 ( V_78 , struct V_6 , V_139 . V_143 ) ;
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
F_29 ( & V_2 -> V_22 ,
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
V_56 = F_19 ( V_2 , V_71 , V_160 ) ;
else
V_56 = F_18 ( V_2 , V_71 , V_160 ) ;
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
F_29 ( & V_14 -> V_22 , L_18 ) ;
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
F_12 ( V_7 -> V_3 -> V_174 ) ;
if ( ( V_174 & V_175 ) < 2 )
F_21 ( V_7 -> V_112 , L_19 ) ;
else
F_21 ( V_7 -> V_112 , L_20
L_21 ) ;
for ( V_71 = 1 ; V_71 <= V_7 -> V_2 -> V_12 ; V_71 ++ )
if ( V_7 -> V_159 [ V_71 - 1 ] -> V_161 )
F_19 ( V_7 -> V_2 , V_71 , V_160 ) ;
else
F_18 ( V_7 -> V_2 , V_71 ,
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
F_28 ( & V_7 -> V_109 ) ;
V_56 = F_25 ( V_7 -> V_2 , & V_7 -> V_75 -> V_7 ) ;
if ( V_56 < 0 ) {
if ( V_56 != - V_111 )
F_29 ( V_7 -> V_112 ,
L_14 , V_113 , V_56 ) ;
} else {
* V_75 = F_12 ( V_7 -> V_75 -> V_7 . V_176 ) ;
* V_108 = F_12 ( V_7 -> V_75 -> V_7 . V_177 ) ;
V_56 = 0 ;
}
F_30 ( & V_7 -> V_109 ) ;
return V_56 ;
}
static int F_61 ( struct V_6 * V_7 , int V_71 ,
unsigned int V_178 )
{
return F_19 ( V_7 -> V_2 ,
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
V_56 = F_27 ( V_7 , V_71 , & V_8 , & V_181 ) ;
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
V_56 = F_18 ( V_2 , V_71 ,
V_190 ) ;
}
if ( V_56 && V_56 != - V_111 )
F_29 ( V_7 -> V_112 , L_23 ,
V_71 , V_56 ) ;
return V_56 ;
}
static void F_65 ( struct V_6 * V_7 , int V_71 )
{
F_21 ( V_7 -> V_112 , L_24 , V_71 ) ;
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
V_56 = F_14 ( V_2 , F_17 ( V_2 , 0 ) ,
V_203 , V_65 ,
V_2 -> V_204 - 1 , 0 , NULL , 0 ,
V_205 ) ;
if ( V_56 < 0 )
F_29 ( V_7 -> V_112 ,
L_25 ) ;
}
if ( type == V_206 ) {
V_173 = F_57 ( V_7 , false ) ;
F_70 ( & V_7 -> V_207 , V_208 ) ;
F_24 ( & V_7 -> V_207 ,
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
F_29 ( V_7 -> V_112 , L_26
L_27
L_28 ) ;
F_29 ( V_7 -> V_112 , L_29
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
V_75 = F_27 ( V_7 , V_71 , & V_8 , & V_181 ) ;
if ( V_14 || ( V_8 & V_212 ) )
F_21 ( V_7 -> V_112 ,
L_32 ,
V_71 , V_8 , V_181 ) ;
if ( ( V_8 & V_213 ) && (
type != V_202 ||
! ( V_8 & V_212 ) ||
! V_14 ||
V_14 -> V_82 == V_189 ) ) {
V_8 &= ~ V_213 ;
if ( ! F_1 ( V_2 ) )
F_18 ( V_2 , V_71 ,
V_190 ) ;
}
if ( V_181 & V_214 ) {
V_197 = true ;
F_18 ( V_7 -> V_2 , V_71 ,
V_215 ) ;
}
if ( V_181 & V_216 ) {
V_197 = true ;
F_18 ( V_7 -> V_2 , V_71 ,
V_217 ) ;
}
if ( V_181 & V_218 ) {
V_197 = true ;
F_18 ( V_7 -> V_2 , V_71 ,
V_219 ) ;
}
if ( ( V_181 & V_220 ) &&
F_1 ( V_7 -> V_2 ) ) {
V_197 = true ;
F_18 ( V_7 -> V_2 , V_71 ,
V_221 ) ;
}
if ( ! ( V_8 & V_212 ) ||
( V_181 & V_214 ) )
F_72 ( V_71 , V_7 -> V_194 ) ;
if ( ! V_14 || V_14 -> V_82 == V_189 ) {
if ( V_14 || ( V_8 & V_212 ) )
F_41 ( V_71 , V_7 -> V_191 ) ;
} else if ( V_8 & V_213 ) {
bool V_222 = ( V_8 &
V_184 ) ==
V_223 ;
if ( V_181 || ( F_1 ( V_7 -> V_2 ) &&
V_222 ) )
F_41 ( V_71 , V_7 -> V_191 ) ;
} else if ( V_14 -> V_224 ) {
struct V_157 * V_158 = V_7 -> V_159 [ V_71 - 1 ] ;
#ifdef F_73
V_14 -> V_225 = 1 ;
#endif
if ( V_158 -> V_161 )
F_41 ( V_71 , V_7 -> V_191 ) ;
} else {
F_64 ( V_14 , V_189 ) ;
F_41 ( V_71 , V_7 -> V_191 ) ;
}
}
if ( V_197 ) {
V_173 = V_226 ;
if ( type == V_198 ) {
F_70 ( & V_7 -> V_207 , V_227 ) ;
F_24 ( & V_7 -> V_207 ,
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
F_29 ( V_7 -> V_112 , L_33 , V_75 ) ;
if ( V_7 -> V_228 && V_99 )
F_24 ( & V_7 -> V_79 , V_100 ) ;
F_31 ( V_7 ) ;
if ( type <= V_200 )
F_74 ( F_36 ( V_7 -> V_112 ) ) ;
}
static void V_208 ( struct V_77 * V_229 )
{
struct V_6 * V_7 = F_23 ( V_229 , struct V_6 , V_207 . V_78 ) ;
F_69 ( V_7 , V_198 ) ;
}
static void V_227 ( struct V_77 * V_229 )
{
struct V_6 * V_7 = F_23 ( V_229 , struct V_6 , V_207 . V_78 ) ;
F_69 ( V_7 , V_200 ) ;
}
static void F_75 ( struct V_6 * V_7 , enum V_230 type )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_55 ;
F_76 ( & V_7 -> V_207 ) ;
V_7 -> V_84 = 1 ;
if ( type != V_231 ) {
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; ++ V_55 ) {
if ( V_7 -> V_159 [ V_55 ] -> V_188 )
F_77 ( & V_7 -> V_159 [ V_55 ] -> V_188 ) ;
}
}
F_78 ( V_7 -> V_125 ) ;
if ( V_7 -> V_228 )
F_76 ( & V_7 -> V_79 ) ;
if ( V_7 -> V_139 . V_7 )
F_79 ( & V_7 -> V_139 . V_143 ) ;
}
static int F_80 ( struct V_192 * V_193 )
{
struct V_6 * V_7 = F_4 ( V_193 ) ;
F_75 ( V_7 , V_232 ) ;
return 0 ;
}
static int F_81 ( struct V_192 * V_193 )
{
struct V_6 * V_7 = F_4 ( V_193 ) ;
F_69 ( V_7 , V_233 ) ;
return 0 ;
}
static int F_82 ( struct V_6 * V_7 ,
struct V_234 * V_235 )
{
struct V_196 * V_152 ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_236 * V_237 = V_7 -> V_112 ;
T_1 V_238 , V_239 ;
T_1 V_174 ;
unsigned int V_162 ;
int V_240 , V_56 , V_55 ;
char * V_241 = L_34 ;
unsigned V_242 ;
unsigned V_243 ;
V_7 -> V_134 = F_51 ( sizeof( * V_7 -> V_134 ) , V_244 ) ;
if ( ! V_7 -> V_134 ) {
V_56 = - V_164 ;
goto V_245;
}
V_7 -> V_75 = F_51 ( sizeof( * V_7 -> V_75 ) , V_244 ) ;
if ( ! V_7 -> V_75 ) {
V_56 = - V_164 ;
goto V_245;
}
F_83 ( & V_7 -> V_109 ) ;
V_7 -> V_3 = F_51 ( sizeof( * V_7 -> V_3 ) , V_244 ) ;
if ( ! V_7 -> V_3 ) {
V_56 = - V_164 ;
goto V_245;
}
V_56 = F_13 ( V_2 , V_7 -> V_3 ) ;
if ( V_56 < 0 ) {
V_241 = L_35 ;
goto V_245;
} else if ( V_7 -> V_3 -> V_246 > V_247 ) {
V_241 = L_36 ;
V_56 = - V_111 ;
goto V_245;
} else if ( V_7 -> V_3 -> V_246 == 0 ) {
V_241 = L_37 ;
V_56 = - V_111 ;
goto V_245;
}
V_2 -> V_12 = V_7 -> V_3 -> V_246 ;
F_84 ( V_237 , L_38 , V_2 -> V_12 ,
( V_2 -> V_12 == 1 ) ? L_39 : L_40 ) ;
V_7 -> V_159 = F_85 ( V_2 -> V_12 * sizeof( struct V_157 * ) ,
V_244 ) ;
if ( ! V_7 -> V_159 ) {
V_56 = - V_164 ;
goto V_245;
}
V_174 = F_12 ( V_7 -> V_3 -> V_174 ) ;
if ( F_1 ( V_2 ) ) {
V_242 = 150 ;
V_243 = 900 ;
} else {
V_242 = 100 ;
V_243 = 500 ;
}
if ( ( V_174 & V_248 ) &&
! ( F_1 ( V_2 ) ) ) {
int V_55 ;
char V_249 [ V_247 + 1 ] ;
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; V_55 ++ )
V_249 [ V_55 ] = V_7 -> V_3 -> V_34 . V_250 . V_251
[ ( ( V_55 + 1 ) / 8 ) ] & ( 1 << ( ( V_55 + 1 ) % 8 ) )
? 'F' : 'R' ;
V_249 [ V_2 -> V_12 ] = 0 ;
F_21 ( V_237 , L_41 , V_249 ) ;
} else
F_21 ( V_237 , L_42 ) ;
switch ( V_174 & V_175 ) {
case V_252 :
F_21 ( V_237 , L_43 ) ;
break;
case V_253 :
F_21 ( V_237 , L_44 ) ;
break;
case V_254 :
case V_175 :
F_21 ( V_237 , L_45 ) ;
break;
}
switch ( V_174 & V_255 ) {
case V_256 :
F_21 ( V_237 , L_46 ) ;
break;
case V_257 :
F_21 ( V_237 , L_47 ) ;
break;
case V_258 :
case V_255 :
F_21 ( V_237 , L_48 ) ;
break;
}
F_86 ( & V_7 -> V_139 . V_144 ) ;
F_87 ( & V_7 -> V_139 . V_145 ) ;
F_88 ( & V_7 -> V_139 . V_143 , F_45 ) ;
switch ( V_2 -> V_3 . V_4 ) {
case V_259 :
break;
case V_260 :
F_21 ( V_237 , L_49 ) ;
V_7 -> V_139 . V_7 = V_2 ;
break;
case V_261 :
V_56 = F_89 ( V_2 , 0 , 1 ) ;
if ( V_56 == 0 ) {
F_21 ( V_237 , L_50 ) ;
V_7 -> V_139 . V_165 = 1 ;
} else
F_29 ( V_237 , L_51 ,
V_56 ) ;
V_7 -> V_139 . V_7 = V_2 ;
break;
case V_5 :
break;
default:
F_21 ( V_237 , L_52 ,
V_2 -> V_3 . V_4 ) ;
break;
}
switch ( V_174 & V_262 ) {
case V_263 :
if ( V_2 -> V_3 . V_4 != 0 ) {
V_7 -> V_139 . V_264 = 666 ;
F_21 ( V_237 , L_53
L_54 ,
8 , V_7 -> V_139 . V_264 ) ;
}
break;
case V_265 :
V_7 -> V_139 . V_264 = 666 * 2 ;
F_21 ( V_237 , L_53
L_54 ,
16 , V_7 -> V_139 . V_264 ) ;
break;
case V_266 :
V_7 -> V_139 . V_264 = 666 * 3 ;
F_21 ( V_237 , L_53
L_54 ,
24 , V_7 -> V_139 . V_264 ) ;
break;
case V_267 :
V_7 -> V_139 . V_264 = 666 * 4 ;
F_21 ( V_237 , L_53
L_54 ,
32 , V_7 -> V_139 . V_264 ) ;
break;
}
if ( V_174 & V_268 ) {
V_7 -> V_228 = 1 ;
F_21 ( V_237 , L_55 ) ;
}
F_21 ( V_237 , L_56 ,
V_7 -> V_3 -> V_172 * 2 ) ;
V_56 = F_90 ( V_2 , V_269 , 0 , & V_238 ) ;
if ( V_56 ) {
V_241 = L_57 ;
goto V_245;
}
V_152 = F_55 ( V_2 -> V_169 ) ;
if ( V_2 == V_2 -> V_169 -> V_270 ) {
if ( V_152 -> V_271 > 0 )
V_2 -> V_272 = V_152 -> V_271 ;
else
V_2 -> V_272 = V_243 * V_2 -> V_12 ;
if ( V_2 -> V_272 >= V_243 )
V_7 -> V_273 = V_243 ;
else {
V_7 -> V_273 = V_2 -> V_272 ;
V_7 -> V_274 = 1 ;
}
} else if ( ( V_238 & ( 1 << V_275 ) ) == 0 ) {
int V_276 = V_2 -> V_272 -
V_7 -> V_3 -> V_277 ;
F_21 ( V_237 , L_58 ,
V_7 -> V_3 -> V_277 ) ;
V_7 -> V_274 = 1 ;
if ( V_276 < V_2 -> V_12 * V_242 )
F_7 ( V_237 ,
L_59
L_60 ) ;
V_7 -> V_273 = V_242 ;
} else {
V_7 -> V_273 = V_243 ;
}
if ( V_7 -> V_273 < V_243 )
F_21 ( V_237 , L_61 ,
V_7 -> V_273 ) ;
if ( V_152 -> V_153 -> V_210 ) {
V_56 = V_152 -> V_153 -> V_210 ( V_152 , V_2 ,
& V_7 -> V_139 , V_244 ) ;
if ( V_56 < 0 ) {
V_241 = L_62 ;
goto V_245;
}
}
V_56 = F_60 ( V_7 , & V_238 , & V_239 ) ;
if ( V_56 < 0 ) {
V_241 = L_57 ;
goto V_245;
}
if ( V_2 -> V_11 -> V_278 . V_20 & V_279 )
F_21 ( V_237 , L_63 ,
( V_238 & V_280 )
? L_64 : L_65 ) ;
if ( ( V_174 & V_255 ) == 0 )
F_21 ( V_237 , L_66 ,
( V_238 & V_281 ) ? L_39 : L_67 ) ;
V_162 = F_91 ( V_2 , V_235 -> V_282 ) ;
V_240 = F_92 ( V_2 , V_162 , F_93 ( V_162 ) ) ;
if ( V_240 > sizeof( * V_7 -> V_134 ) )
V_240 = sizeof( * V_7 -> V_134 ) ;
V_7 -> V_125 = F_94 ( 0 , V_244 ) ;
if ( ! V_7 -> V_125 ) {
V_56 = - V_164 ;
goto V_245;
}
F_95 ( V_7 -> V_125 , V_2 , V_162 , * V_7 -> V_134 , V_240 , F_42 ,
V_7 , V_235 -> V_283 ) ;
if ( V_7 -> V_228 && V_99 )
V_7 -> V_86 [ 0 ] = V_87 ;
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; V_55 ++ ) {
V_56 = F_96 ( V_7 , V_55 + 1 ) ;
if ( V_56 < 0 ) {
F_29 ( V_7 -> V_112 ,
L_68 , V_55 + 1 ) ;
V_2 -> V_12 = V_55 ;
goto V_284;
}
}
F_97 ( V_2 , V_7 -> V_3 ) ;
F_69 ( V_7 , V_206 ) ;
return 0 ;
V_245:
V_2 -> V_12 = 0 ;
V_284:
F_29 ( V_237 , L_69 ,
V_241 , V_56 ) ;
return V_56 ;
}
static void F_98 ( struct V_285 * V_285 )
{
struct V_6 * V_7 = F_23 ( V_285 , struct V_6 , V_285 ) ;
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
F_75 ( V_7 , V_286 ) ;
F_106 ( V_193 , NULL ) ;
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; V_55 ++ )
F_107 ( V_7 , V_55 + 1 ) ;
V_7 -> V_2 -> V_12 = 0 ;
if ( V_7 -> V_2 -> V_15 == V_16 )
V_287 -- ;
F_108 ( V_7 -> V_125 ) ;
F_48 ( V_7 -> V_159 ) ;
F_48 ( V_7 -> V_3 ) ;
F_48 ( V_7 -> V_75 ) ;
F_48 ( V_7 -> V_134 ) ;
F_109 ( & V_193 -> V_22 , false ) ;
F_110 ( & V_7 -> V_285 , F_98 ) ;
}
static int F_111 ( struct V_192 * V_193 , const struct V_288 * V_289 )
{
struct V_290 * V_278 ;
struct V_234 * V_235 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
V_278 = V_193 -> V_291 ;
V_2 = F_101 ( V_193 ) ;
F_112 ( & V_2 -> V_22 , 0 ) ;
F_113 ( V_2 ) ;
if ( V_2 -> V_204 == V_292 ) {
F_29 ( & V_193 -> V_22 ,
L_70 ) ;
return - V_293 ;
}
#ifdef F_114
if ( V_2 -> V_23 ) {
F_7 ( & V_193 -> V_22 , L_71 ) ;
return - V_111 ;
}
#endif
if ( ( V_278 -> V_278 . V_294 != 0 ) &&
( V_278 -> V_278 . V_294 != 1 ) ) {
V_295:
F_29 ( & V_193 -> V_22 , L_72 ) ;
return - V_114 ;
}
if ( V_278 -> V_278 . V_296 != 1 )
goto V_295;
V_235 = & V_278 -> V_235 [ 0 ] . V_278 ;
if ( ! F_115 ( V_235 ) )
goto V_295;
F_84 ( & V_193 -> V_22 , L_73 ) ;
V_7 = F_85 ( sizeof( * V_7 ) , V_244 ) ;
if ( ! V_7 ) {
F_21 ( & V_193 -> V_22 , L_74 ) ;
return - V_164 ;
}
F_116 ( & V_7 -> V_285 ) ;
F_87 ( & V_7 -> V_120 ) ;
V_7 -> V_112 = & V_193 -> V_22 ;
V_7 -> V_2 = V_2 ;
F_117 ( & V_7 -> V_79 , F_22 ) ;
F_117 ( & V_7 -> V_207 , NULL ) ;
F_118 ( V_193 ) ;
F_106 ( V_193 , V_7 ) ;
V_193 -> V_297 = 1 ;
F_109 ( & V_193 -> V_22 , true ) ;
if ( V_2 -> V_15 == V_16 )
V_287 ++ ;
if ( V_289 -> V_298 & V_299 )
V_7 -> V_300 = 1 ;
if ( F_82 ( V_7 , V_235 ) >= 0 )
return 0 ;
F_100 ( V_193 ) ;
return - V_111 ;
}
static int
F_119 ( struct V_192 * V_193 , unsigned int V_301 , void * V_302 )
{
struct V_1 * V_2 = F_101 ( V_193 ) ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
switch ( V_301 ) {
case V_303 : {
struct V_304 * V_305 = V_302 ;
int V_55 ;
F_102 ( & V_306 ) ;
if ( V_2 -> V_167 <= 0 )
V_305 -> V_307 = 0 ;
else {
V_305 -> V_307 = V_2 -> V_12 ;
for ( V_55 = 0 ; V_55 < V_305 -> V_307 ; V_55 ++ ) {
if ( V_7 -> V_159 [ V_55 ] -> V_188 == NULL )
V_305 -> V_110 [ V_55 ] = 0 ;
else
V_305 -> V_110 [ V_55 ] =
V_7 -> V_159 [ V_55 ] -> V_188 -> V_167 ;
}
}
F_105 ( & V_306 ) ;
return V_305 -> V_307 + 1 ;
}
default:
return - V_308 ;
}
}
static int F_120 ( struct V_1 * V_2 , unsigned V_71 ,
struct V_309 * * * V_310 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_2 -> V_82 == V_189 )
return - V_111 ;
if ( V_71 == 0 || V_71 > V_2 -> V_12 )
return - V_68 ;
* V_310 = & ( V_7 -> V_159 [ V_71 - 1 ] -> V_311 ) ;
return 0 ;
}
int F_121 ( struct V_1 * V_2 , unsigned V_71 ,
struct V_309 * V_312 )
{
int V_313 ;
struct V_309 * * V_314 ;
V_313 = F_120 ( V_2 , V_71 , & V_314 ) ;
if ( V_313 )
return V_313 ;
if ( * V_314 )
return - V_315 ;
* V_314 = V_312 ;
return V_313 ;
}
int F_122 ( struct V_1 * V_2 , unsigned V_71 ,
struct V_309 * V_312 )
{
int V_313 ;
struct V_309 * * V_314 ;
V_313 = F_120 ( V_2 , V_71 , & V_314 ) ;
if ( V_313 )
return V_313 ;
if ( * V_314 != V_312 )
return - V_128 ;
* V_314 = NULL ;
return V_313 ;
}
void F_123 ( struct V_1 * V_2 , struct V_309 * V_312 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
int V_316 ;
for ( V_316 = 0 ; V_316 < V_2 -> V_12 ; V_316 ++ ) {
if ( V_7 -> V_159 [ V_316 ] -> V_311 == V_312 )
V_7 -> V_159 [ V_316 ] -> V_311 = NULL ;
}
}
bool F_124 ( struct V_1 * V_14 )
{
struct V_6 * V_7 ;
if ( V_14 -> V_82 == V_189 || ! V_14 -> V_23 )
return false ;
V_7 = F_3 ( V_14 -> V_23 ) ;
return ! ! V_7 -> V_159 [ V_14 -> V_123 - 1 ] -> V_311 ;
}
static void F_125 ( struct V_1 * V_14 )
{
struct V_6 * V_7 = F_3 ( V_14 ) ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_14 -> V_12 ; ++ V_55 ) {
if ( V_7 -> V_159 [ V_55 ] -> V_188 )
F_125 ( V_7 -> V_159 [ V_55 ] -> V_188 ) ;
}
if ( V_14 -> V_82 == V_317 )
V_14 -> V_318 -= V_319 ;
V_14 -> V_82 = V_189 ;
}
void F_64 ( struct V_1 * V_14 ,
enum V_320 V_321 )
{
unsigned long V_117 ;
int V_322 = - 1 ;
F_32 ( & V_306 , V_117 ) ;
if ( V_14 -> V_82 == V_189 )
;
else if ( V_321 != V_189 ) {
if ( V_14 -> V_23 ) {
if ( V_14 -> V_82 == V_317
|| V_321 == V_317 )
;
else if ( V_321 == V_83 )
V_322 = V_14 -> V_11 -> V_278 . V_20
& V_323 ;
else
V_322 = 0 ;
}
if ( V_14 -> V_82 == V_317 &&
V_321 != V_317 )
V_14 -> V_318 -= V_319 ;
else if ( V_321 == V_317 &&
V_14 -> V_82 != V_317 )
V_14 -> V_318 += V_319 ;
V_14 -> V_82 = V_321 ;
} else
F_125 ( V_14 ) ;
F_38 ( & V_306 , V_117 ) ;
if ( V_322 >= 0 )
F_126 ( & V_14 -> V_22 , V_322 ) ;
}
static void F_127 ( struct V_1 * V_14 )
{
int V_167 ;
struct V_324 * V_169 = V_14 -> V_169 ;
if ( V_14 -> V_325 ) {
V_167 = V_14 -> V_123 + 1 ;
F_128 ( F_129 ( V_167 , V_169 -> V_326 . V_327 ) ) ;
} else {
V_167 = F_130 ( V_169 -> V_326 . V_327 , 128 ,
V_169 -> V_328 ) ;
if ( V_167 >= 128 )
V_167 = F_130 ( V_169 -> V_326 . V_327 ,
128 , 1 ) ;
V_169 -> V_328 = ( V_167 >= 127 ? 1 : V_167 + 1 ) ;
}
if ( V_167 < 128 ) {
F_41 ( V_167 , V_169 -> V_326 . V_327 ) ;
V_14 -> V_167 = V_167 ;
}
}
static void F_131 ( struct V_1 * V_14 )
{
if ( V_14 -> V_167 > 0 ) {
F_72 ( V_14 -> V_167 , V_14 -> V_169 -> V_326 . V_327 ) ;
V_14 -> V_167 = - 1 ;
}
}
static void F_132 ( struct V_1 * V_14 , int V_167 )
{
if ( ! V_14 -> V_325 )
V_14 -> V_167 = V_167 ;
}
static void F_133 ( struct V_1 * V_14 )
{
struct V_196 * V_152 = F_55 ( V_14 -> V_169 ) ;
if ( V_152 -> V_153 -> V_329 && V_14 -> V_23 )
V_152 -> V_153 -> V_329 ( V_152 , V_14 ) ;
}
void F_77 ( struct V_1 * * V_330 )
{
struct V_1 * V_14 = * V_330 ;
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
F_21 ( & V_14 -> V_22 , L_76 ) ;
F_135 ( V_14 , 0 ) ;
F_136 ( V_14 ) ;
if ( V_14 -> V_23 ) {
struct V_6 * V_7 = F_3 ( V_14 -> V_23 ) ;
struct V_157 * V_158 = V_7 -> V_159 [ V_14 -> V_123 - 1 ] ;
F_137 ( & V_14 -> V_22 . V_331 , L_77 ) ;
F_137 ( & V_158 -> V_22 . V_331 , L_78 ) ;
if ( ! V_158 -> V_332 )
F_138 ( & V_158 -> V_22 ) ;
else
V_158 -> V_332 = false ;
}
F_139 ( & V_14 -> V_333 ) ;
F_140 ( V_14 ) ;
F_141 ( & V_14 -> V_22 ) ;
F_131 ( V_14 ) ;
F_102 ( & V_306 ) ;
* V_330 = NULL ;
F_105 ( & V_306 ) ;
F_133 ( V_14 ) ;
F_142 ( & V_14 -> V_22 ) ;
}
static void F_143 ( struct V_1 * V_14 , char * V_289 , char * string )
{
if ( ! string )
return;
F_84 ( & V_14 -> V_22 , L_79 , V_289 , string ) ;
}
static void F_144 ( struct V_1 * V_14 )
{
F_84 ( & V_14 -> V_22 , L_80 ,
F_12 ( V_14 -> V_3 . V_334 ) ,
F_12 ( V_14 -> V_3 . V_335 ) ) ;
F_84 ( & V_14 -> V_22 ,
L_81 ,
V_14 -> V_3 . V_336 ,
V_14 -> V_3 . V_337 ,
V_14 -> V_3 . V_338 ) ;
F_143 ( V_14 , L_82 , V_14 -> V_339 ) ;
F_143 ( V_14 , L_83 , V_14 -> V_340 ) ;
F_143 ( V_14 , L_84 , V_14 -> V_341 ) ;
}
static inline void F_144 ( struct V_1 * V_14 ) { }
static int F_145 ( struct V_1 * V_14 )
{
int V_342 = 0 ;
#ifdef F_146
if ( ! V_14 -> V_169 -> V_343
&& V_14 -> V_344
&& V_14 -> V_23 == V_14 -> V_169 -> V_270 ) {
struct V_345 * V_278 = NULL ;
struct V_324 * V_169 = V_14 -> V_169 ;
if ( F_147 ( V_14 -> V_346 [ 0 ] ,
F_12 ( V_14 -> V_344 [ 0 ] . V_278 . V_347 ) ,
V_348 , ( void * * ) & V_278 ) == 0 ) {
if ( V_278 -> V_20 & V_349 ) {
unsigned V_71 = V_14 -> V_123 ;
F_84 ( & V_14 -> V_22 ,
L_85 ,
( V_71 == V_169 -> V_350 )
? L_39 : L_86 ) ;
if ( V_71 == V_169 -> V_350 )
V_169 -> V_351 = 1 ;
V_342 = F_14 ( V_14 ,
F_17 ( V_14 , 0 ) ,
V_73 , 0 ,
V_169 -> V_351
? V_352
: V_353 ,
0 , NULL , 0 , V_205 ) ;
if ( V_342 < 0 ) {
F_84 ( & V_14 -> V_22 ,
L_87 ,
V_342 ) ;
V_169 -> V_351 = 0 ;
}
}
}
}
if ( ! F_148 ( V_14 ) ) {
if ( V_14 -> V_169 -> V_351 || V_14 -> V_169 -> V_343 ) {
V_342 = F_149 ( V_14 , V_354 ) ;
if ( V_342 < 0 )
F_21 ( & V_14 -> V_22 , L_88 , V_342 ) ;
}
V_342 = - V_355 ;
goto V_245;
}
V_245:
#endif
return V_342 ;
}
static int F_150 ( struct V_1 * V_14 )
{
int V_342 ;
if ( V_14 -> V_344 == NULL ) {
V_342 = F_151 ( V_14 ) ;
if ( V_342 < 0 ) {
if ( V_342 != - V_111 )
F_29 ( & V_14 -> V_22 , L_89 ,
V_342 ) ;
return V_342 ;
}
}
if ( V_14 -> V_325 == 1 && V_14 -> V_356 == 0 ) {
V_14 -> V_339 = F_152 ( L_90 , V_244 ) ;
V_14 -> V_340 = F_152 ( L_90 , V_244 ) ;
V_14 -> V_341 = F_152 ( L_90 , V_244 ) ;
} else {
V_14 -> V_339 = F_153 ( V_14 , V_14 -> V_3 . V_337 ) ;
V_14 -> V_340 = F_153 ( V_14 ,
V_14 -> V_3 . V_336 ) ;
V_14 -> V_341 = F_153 ( V_14 , V_14 -> V_3 . V_338 ) ;
}
V_342 = F_145 ( V_14 ) ;
if ( V_342 < 0 )
return V_342 ;
F_154 ( V_14 ) ;
return 0 ;
}
static void F_155 ( struct V_1 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_23 ;
struct V_6 * V_7 ;
T_2 V_110 = V_14 -> V_123 ;
T_1 V_174 ;
bool V_357 = true ;
if ( ! V_2 )
return;
V_7 = F_3 ( V_14 -> V_23 ) ;
V_174 = F_12 ( V_7 -> V_3 -> V_174 ) ;
if ( ! ( V_174 & V_248 ) )
return;
if ( F_1 ( V_2 ) ) {
if ( F_12 ( V_7 -> V_3 -> V_34 . V_35 . V_251 )
& ( 1 << V_110 ) )
V_357 = false ;
} else {
if ( V_7 -> V_3 -> V_34 . V_250 . V_251 [ V_110 / 8 ] & ( 1 << ( V_110 % 8 ) ) )
V_357 = false ;
}
if ( V_357 )
V_14 -> V_357 = V_358 ;
else
V_14 -> V_357 = V_359 ;
}
int F_156 ( struct V_1 * V_14 )
{
int V_342 ;
if ( V_14 -> V_23 ) {
F_157 ( & V_14 -> V_22 , 0 ) ;
}
F_158 ( & V_14 -> V_22 ) ;
F_159 ( & V_14 -> V_22 ) ;
F_160 ( & V_14 -> V_22 ) ;
F_161 ( & V_14 -> V_22 ) ;
F_162 ( V_14 ) ;
V_342 = F_150 ( V_14 ) ;
if ( V_342 < 0 )
goto V_245;
F_21 ( & V_14 -> V_22 , L_91 ,
V_14 -> V_167 , V_14 -> V_169 -> V_360 ,
( ( ( V_14 -> V_169 -> V_360 - 1 ) * 128 ) + ( V_14 -> V_167 - 1 ) ) ) ;
V_14 -> V_22 . V_361 = F_163 ( V_362 ,
( ( ( V_14 -> V_169 -> V_360 - 1 ) * 128 ) + ( V_14 -> V_167 - 1 ) ) ) ;
F_144 ( V_14 ) ;
if ( V_14 -> V_341 )
F_164 ( V_14 -> V_341 , strlen ( V_14 -> V_341 ) ) ;
if ( V_14 -> V_339 )
F_164 ( V_14 -> V_339 , strlen ( V_14 -> V_339 ) ) ;
if ( V_14 -> V_340 )
F_164 ( V_14 -> V_340 ,
strlen ( V_14 -> V_340 ) ) ;
F_165 ( & V_14 -> V_22 ) ;
if ( V_14 -> V_23 )
F_155 ( V_14 ) ;
V_342 = F_166 ( & V_14 -> V_22 ) ;
if ( V_342 ) {
F_29 ( & V_14 -> V_22 , L_92 , V_342 ) ;
goto V_245;
}
if ( V_14 -> V_23 ) {
struct V_6 * V_7 = F_3 ( V_14 -> V_23 ) ;
struct V_157 * V_158 = V_7 -> V_159 [ V_14 -> V_123 - 1 ] ;
V_342 = F_167 ( & V_14 -> V_22 . V_331 ,
& V_158 -> V_22 . V_331 , L_77 ) ;
if ( V_342 )
goto V_245;
V_342 = F_167 ( & V_158 -> V_22 . V_331 ,
& V_14 -> V_22 . V_331 , L_78 ) ;
if ( V_342 ) {
F_137 ( & V_14 -> V_22 . V_331 , L_77 ) ;
goto V_245;
}
F_168 ( & V_158 -> V_22 ) ;
}
( void ) F_169 ( & V_14 -> V_22 , & V_14 -> V_333 , V_14 ) ;
F_170 ( V_14 ) ;
F_171 ( & V_14 -> V_22 ) ;
return V_342 ;
V_245:
F_64 ( V_14 , V_189 ) ;
F_172 ( & V_14 -> V_22 ) ;
F_173 ( & V_14 -> V_22 ) ;
return V_342 ;
}
int F_174 ( struct V_1 * V_363 )
{
F_134 ( V_363 ) ;
if ( V_363 -> V_356 == 0 )
goto V_364;
V_363 -> V_356 = 0 ;
F_175 ( V_363 , - 1 ) ;
F_48 ( V_363 -> V_339 ) ;
V_363 -> V_339 = F_152 ( L_90 , V_244 ) ;
F_48 ( V_363 -> V_340 ) ;
V_363 -> V_340 = F_152 ( L_90 , V_244 ) ;
F_48 ( V_363 -> V_341 ) ;
V_363 -> V_341 = F_152 ( L_90 , V_244 ) ;
F_176 ( V_363 ) ;
V_363 -> V_3 . V_365 = 0 ;
V_364:
F_140 ( V_363 ) ;
return 0 ;
}
int F_177 ( struct V_1 * V_363 )
{
int V_366 = 0 , V_367 ;
F_134 ( V_363 ) ;
if ( V_363 -> V_356 == 1 )
goto V_368;
V_366 = F_178 ( V_363 ) ;
if ( V_366 < 0 ) {
F_29 ( & V_363 -> V_22 ,
L_93 , V_366 ) ;
goto V_369;
}
V_366 = F_179 ( V_363 , sizeof( V_363 -> V_3 ) ) ;
if ( V_366 < 0 ) {
F_29 ( & V_363 -> V_22 , L_94
L_95 , V_366 ) ;
goto V_370;
}
F_48 ( V_363 -> V_339 ) ;
V_363 -> V_339 = NULL ;
F_48 ( V_363 -> V_340 ) ;
V_363 -> V_340 = NULL ;
F_48 ( V_363 -> V_341 ) ;
V_363 -> V_341 = NULL ;
V_363 -> V_356 = 1 ;
V_366 = F_150 ( V_363 ) ;
if ( V_366 < 0 )
goto V_371;
V_367 = F_180 ( V_363 ) ;
if ( V_367 >= 0 ) {
V_366 = F_175 ( V_363 , V_367 ) ;
if ( V_366 ) {
F_29 ( & V_363 -> V_22 ,
L_96 , V_367 , V_366 ) ;
}
}
F_84 ( & V_363 -> V_22 , L_97 ) ;
V_371:
V_370:
F_181 ( V_363 ) ;
V_369:
V_368:
F_140 ( V_363 ) ;
return V_366 ;
}
static unsigned F_182 ( struct V_6 * V_7 )
{
struct V_196 * V_152 ;
if ( V_7 -> V_2 -> V_23 != NULL )
return 0 ;
V_152 = F_23 ( V_7 -> V_2 -> V_169 , struct V_196 , V_372 ) ;
return V_152 -> V_373 ;
}
static bool F_183 ( struct V_6 * V_7 , T_1 V_8 )
{
return F_1 ( V_7 -> V_2 ) &&
( ( ( V_8 & V_184 ) ==
V_374 ) ||
( ( V_8 & V_184 ) ==
V_375 ) ) ;
}
static int F_184 ( struct V_6 * V_7 , int V_71 ,
struct V_1 * V_14 , unsigned int V_173 , bool V_376 )
{
int V_377 , V_56 ;
T_1 V_8 ;
T_1 V_181 ;
for ( V_377 = 0 ;
V_377 < V_378 ;
V_377 += V_173 ) {
F_59 ( V_173 ) ;
V_56 = F_27 ( V_7 , V_71 , & V_8 , & V_181 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( ! ( V_8 & V_379 ) )
break;
if ( V_377 >= 2 * V_380 )
V_173 = V_381 ;
F_21 ( V_7 -> V_112 ,
L_98 ,
V_71 , V_376 ? L_99 : L_39 , V_173 ) ;
}
if ( ( V_8 & V_379 ) )
return - V_315 ;
if ( F_183 ( V_7 , V_8 ) )
return - V_382 ;
if ( ! ( V_8 & V_212 ) )
return - V_382 ;
if ( ! F_1 ( V_7 -> V_2 ) &&
( V_181 & V_214 ) )
return - V_382 ;
if ( ! ( V_8 & V_213 ) )
return - V_315 ;
if ( ! V_14 )
return 0 ;
if ( F_182 ( V_7 ) )
V_14 -> V_15 = V_383 ;
else if ( F_1 ( V_7 -> V_2 ) )
V_14 -> V_15 = V_49 ;
else if ( V_8 & V_9 )
V_14 -> V_15 = V_16 ;
else if ( V_8 & V_10 )
V_14 -> V_15 = V_384 ;
else
V_14 -> V_15 = V_385 ;
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
if ( V_152 -> V_153 -> V_386 )
V_152 -> V_153 -> V_386 ( V_152 , V_14 ) ;
}
case - V_382 :
case - V_111 :
F_18 ( V_7 -> V_2 ,
V_71 , V_219 ) ;
if ( F_1 ( V_7 -> V_2 ) ) {
F_18 ( V_7 -> V_2 , V_71 ,
V_221 ) ;
F_18 ( V_7 -> V_2 , V_71 ,
V_387 ) ;
F_18 ( V_7 -> V_2 , V_71 ,
V_215 ) ;
}
if ( V_14 )
F_64 ( V_14 , * V_75
? V_189
: V_388 ) ;
break;
}
}
static int F_186 ( struct V_6 * V_7 , int V_71 ,
struct V_1 * V_14 , unsigned int V_173 , bool V_376 )
{
int V_55 , V_75 ;
T_1 V_181 , V_8 ;
if ( ! F_1 ( V_7 -> V_2 ) ) {
if ( V_376 ) {
F_29 ( V_7 -> V_112 , L_100
L_101 ) ;
return - V_68 ;
}
F_187 ( & V_389 ) ;
} else if ( ! V_376 ) {
V_75 = F_27 ( V_7 , V_71 ,
& V_8 , & V_181 ) ;
if ( V_75 < 0 )
goto V_390;
if ( F_183 ( V_7 , V_8 ) )
V_376 = true ;
}
for ( V_55 = 0 ; V_55 < V_391 ; V_55 ++ ) {
V_75 = F_19 ( V_7 -> V_2 , V_71 , ( V_376 ?
V_392 :
V_393 ) ) ;
if ( V_75 == - V_111 ) {
;
} else if ( V_75 ) {
F_29 ( V_7 -> V_112 ,
L_102 ,
V_376 ? L_99 : L_39 , V_71 , V_75 ) ;
} else {
V_75 = F_184 ( V_7 , V_71 , V_14 , V_173 ,
V_376 ) ;
if ( V_75 && V_75 != - V_382 && V_75 != - V_111 )
F_21 ( V_7 -> V_112 ,
L_103 ,
V_75 ) ;
}
if ( V_75 == 0 || V_75 == - V_382 || V_75 == - V_111 ) {
F_185 ( V_7 , V_71 , V_14 , & V_75 ) ;
if ( ! F_1 ( V_7 -> V_2 ) )
goto V_390;
if ( F_27 ( V_7 , V_71 ,
& V_8 , & V_181 ) < 0 )
goto V_390;
if ( ! F_183 ( V_7 , V_8 ) )
goto V_390;
if ( ! V_376 ) {
F_21 ( V_7 -> V_112 , L_104 ,
V_71 ) ;
V_376 = true ;
}
}
F_21 ( V_7 -> V_112 ,
L_105 ,
V_71 , V_376 ? L_99 : L_39 ) ;
V_173 = V_381 ;
}
F_29 ( V_7 -> V_112 ,
L_106 ,
V_71 ) ;
V_390:
if ( ! F_1 ( V_7 -> V_2 ) )
F_188 ( & V_389 ) ;
return V_75 ;
}
static int F_189 ( struct V_6 * V_7 , unsigned V_8 )
{
int V_56 = 0 ;
if ( F_1 ( V_7 -> V_2 ) ) {
if ( V_8 & V_394 )
V_56 = 1 ;
} else {
if ( V_8 & V_395 )
V_56 = 1 ;
}
return V_56 ;
}
static int F_190 ( struct V_6 * V_7 , unsigned V_8 )
{
int V_56 = 0 ;
if ( F_1 ( V_7 -> V_2 ) ) {
if ( ( V_8 & V_184 )
== V_396 )
V_56 = 1 ;
} else {
if ( V_8 & V_397 )
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
else if ( ! ( V_8 & V_213 ) && ! V_14 -> V_225 ) {
if ( V_14 -> V_224 )
V_14 -> V_225 = 1 ;
else
V_75 = - V_111 ;
}
if ( V_75 ) {
F_21 ( V_7 -> V_112 ,
L_107 ,
V_71 , V_181 , V_8 , V_75 ) ;
} else if ( V_14 -> V_225 ) {
if ( V_181 & V_214 )
F_18 ( V_7 -> V_2 , V_71 ,
V_215 ) ;
if ( V_181 & V_216 )
F_18 ( V_7 -> V_2 , V_71 ,
V_217 ) ;
}
return V_75 ;
}
int F_192 ( struct V_1 * V_14 )
{
struct V_196 * V_152 = F_55 ( V_14 -> V_169 ) ;
if ( ! F_193 ( V_152 -> V_372 . V_270 ) ||
! F_193 ( V_14 ) )
return 0 ;
if ( ! V_14 -> V_11 )
return 0 ;
return F_14 ( V_14 , F_17 ( V_14 , 0 ) ,
V_70 , V_269 ,
V_398 , 0 , NULL , 0 ,
V_205 ) ;
}
void F_194 ( struct V_1 * V_14 )
{
struct V_196 * V_152 = F_55 ( V_14 -> V_169 ) ;
if ( ! F_193 ( V_152 -> V_372 . V_270 ) ||
! F_193 ( V_14 ) )
return;
if ( ! V_14 -> V_11 )
return;
F_14 ( V_14 , F_17 ( V_14 , 0 ) ,
V_73 , V_269 ,
V_398 , 0 , NULL , 0 ,
V_205 ) ;
}
static int F_195 ( struct V_1 * V_14 )
{
if ( V_14 -> V_15 < V_49 )
return F_14 ( V_14 , F_17 ( V_14 , 0 ) ,
V_73 , V_269 ,
V_399 , 0 , NULL , 0 ,
V_205 ) ;
else
return F_14 ( V_14 , F_17 ( V_14 , 0 ) ,
V_73 , V_400 ,
V_401 ,
V_402 |
V_403 ,
NULL , 0 , V_205 ) ;
}
static int F_196 ( struct V_1 * V_14 )
{
if ( V_14 -> V_15 < V_49 )
return F_14 ( V_14 , F_17 ( V_14 , 0 ) ,
V_70 , V_269 ,
V_399 , 0 , NULL , 0 ,
V_205 ) ;
else
return F_14 ( V_14 , F_17 ( V_14 , 0 ) ,
V_70 , V_400 ,
V_401 , 0 , NULL , 0 ,
V_205 ) ;
}
static unsigned F_197 ( struct V_1 * V_14 )
{
struct V_6 * V_7 = F_3 ( V_14 ) ;
return V_14 -> V_404 +
( V_7 ? V_7 -> F_197 : 0 ) ;
}
int F_149 ( struct V_1 * V_14 , T_3 V_405 )
{
struct V_6 * V_7 = F_3 ( V_14 -> V_23 ) ;
struct V_157 * V_158 = V_7 -> V_159 [ V_14 -> V_123 - 1 ] ;
int V_71 = V_14 -> V_123 ;
int V_75 ;
bool V_406 = true ;
if ( V_14 -> V_404 ) {
V_75 = F_195 ( V_14 ) ;
if ( V_75 ) {
F_21 ( & V_14 -> V_22 , L_108 ,
V_75 ) ;
if ( F_198 ( V_405 ) )
goto V_407;
}
}
if ( V_14 -> V_408 == 1 )
F_199 ( V_14 , 0 ) ;
if ( F_192 ( V_14 ) ) {
F_29 ( & V_14 -> V_22 , L_109 ) ;
V_75 = - V_164 ;
if ( F_198 ( V_405 ) )
goto V_409;
}
if ( F_200 ( V_14 ) ) {
F_29 ( & V_14 -> V_22 , L_110 ) ;
V_75 = - V_164 ;
if ( F_198 ( V_405 ) )
goto V_410;
}
if ( F_1 ( V_7 -> V_2 ) )
V_75 = F_61 ( V_7 , V_71 , V_396 ) ;
else if ( F_198 ( V_405 ) || F_197 ( V_14 ) > 0 )
V_75 = F_19 ( V_7 -> V_2 , V_71 ,
V_411 ) ;
else {
V_406 = false ;
V_75 = 0 ;
}
if ( V_75 ) {
F_21 ( V_7 -> V_112 , L_111 ,
V_71 , V_75 ) ;
F_201 ( V_14 ) ;
V_410:
F_194 ( V_14 ) ;
V_409:
if ( V_14 -> V_412 == 1 )
F_199 ( V_14 , 1 ) ;
if ( V_14 -> V_404 )
( void ) F_196 ( V_14 ) ;
V_407:
if ( ! F_198 ( V_405 ) )
V_75 = 0 ;
} else {
F_21 ( & V_14 -> V_22 , L_112 ,
( F_198 ( V_405 ) ? L_113 : L_39 ) ,
V_14 -> V_404 ) ;
if ( V_406 ) {
V_14 -> F_190 = 1 ;
F_59 ( 10 ) ;
}
F_64 ( V_14 , V_317 ) ;
}
if ( V_75 == 0 && ! V_14 -> V_404 && V_14 -> V_224 ) {
F_202 ( & V_158 -> V_22 ) ;
V_158 -> V_332 = true ;
}
F_170 ( V_7 -> V_2 ) ;
return V_75 ;
}
static int F_203 ( struct V_1 * V_14 )
{
int V_75 = 0 ;
T_1 V_413 = 0 ;
F_21 ( & V_14 -> V_22 , L_114 ,
V_14 -> V_225 ? L_115 : L_116 ) ;
F_64 ( V_14 , V_14 -> V_11
? V_83
: V_414 ) ;
if ( V_14 -> V_225 )
V_415:
V_75 = F_204 ( V_14 ) ;
if ( V_75 == 0 ) {
V_413 = 0 ;
V_75 = F_90 ( V_14 , V_269 , 0 , & V_413 ) ;
if ( V_75 && ! V_14 -> V_225 && V_14 -> V_224 ) {
F_21 ( & V_14 -> V_22 , L_117 ) ;
V_14 -> V_225 = 1 ;
goto V_415;
}
}
if ( V_75 ) {
F_21 ( & V_14 -> V_22 , L_118 ,
V_75 ) ;
} else if ( V_14 -> V_11 && ! V_14 -> V_225 ) {
if ( V_14 -> V_15 < V_49 ) {
if ( V_413 & ( 1 << V_399 ) )
V_75 = F_196 ( V_14 ) ;
} else {
V_75 = F_90 ( V_14 , V_400 , 0 ,
& V_413 ) ;
if ( ! V_75 && V_413 & ( V_416
| V_417 ) )
V_75 = F_196 ( V_14 ) ;
}
if ( V_75 )
F_21 ( & V_14 -> V_22 ,
L_119 ,
V_75 ) ;
V_75 = 0 ;
}
return V_75 ;
}
int F_205 ( struct V_1 * V_14 , T_3 V_405 )
{
struct V_6 * V_7 = F_3 ( V_14 -> V_23 ) ;
struct V_157 * V_158 = V_7 -> V_159 [ V_14 -> V_123 - 1 ] ;
int V_71 = V_14 -> V_123 ;
int V_75 ;
T_1 V_181 , V_8 ;
if ( V_158 -> V_332 ) {
V_75 = F_168 ( & V_158 -> V_22 ) ;
V_158 -> V_332 = false ;
if ( V_75 < 0 ) {
F_21 ( & V_14 -> V_22 , L_120 ,
V_75 ) ;
return V_75 ;
}
}
V_75 = F_27 ( V_7 , V_71 , & V_8 , & V_181 ) ;
if ( V_75 == 0 && ! F_190 ( V_7 , V_8 ) )
goto V_418;
F_41 ( V_71 , V_7 -> V_419 ) ;
if ( F_1 ( V_7 -> V_2 ) )
V_75 = F_61 ( V_7 , V_71 , V_223 ) ;
else
V_75 = F_18 ( V_7 -> V_2 ,
V_71 , V_411 ) ;
if ( V_75 ) {
F_21 ( V_7 -> V_112 , L_121 ,
V_71 , V_75 ) ;
} else {
F_21 ( & V_14 -> V_22 , L_122 ,
( F_198 ( V_405 ) ? L_113 : L_39 ) ) ;
F_59 ( 25 ) ;
V_75 = F_27 ( V_7 , V_71 , & V_8 , & V_181 ) ;
F_59 ( 10 ) ;
}
V_418:
if ( V_75 == 0 ) {
V_14 -> F_190 = 0 ;
if ( F_1 ( V_7 -> V_2 ) ) {
if ( V_181 & V_420 )
F_18 ( V_7 -> V_2 , V_71 ,
V_387 ) ;
} else {
if ( V_181 & V_421 )
F_18 ( V_7 -> V_2 , V_71 ,
V_422 ) ;
}
}
F_72 ( V_71 , V_7 -> V_419 ) ;
V_75 = F_191 ( V_14 ,
V_7 , V_71 , V_75 , V_181 , V_8 ) ;
if ( V_75 == 0 )
V_75 = F_203 ( V_14 ) ;
if ( V_75 < 0 ) {
F_21 ( & V_14 -> V_22 , L_123 , V_75 ) ;
F_65 ( V_7 , V_71 ) ;
} else {
if ( V_14 -> V_412 == 1 )
F_199 ( V_14 , 1 ) ;
F_194 ( V_14 ) ;
F_201 ( V_14 ) ;
}
return V_75 ;
}
int F_206 ( struct V_1 * V_14 )
{
int V_75 = 0 ;
if ( V_14 -> V_82 == V_317 ) {
F_21 ( & V_14 -> V_22 , L_122 , L_124 ) ;
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
V_75 = F_27 ( V_7 , V_71 , & V_8 , & V_181 ) ;
if ( ! V_75 && V_181 )
return 1 ;
}
return 0 ;
}
static int F_208 ( struct V_192 * V_193 , T_3 V_405 )
{
struct V_6 * V_7 = F_4 ( V_193 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
unsigned V_71 ;
int V_75 ;
V_7 -> F_197 = 0 ;
for ( V_71 = 1 ; V_71 <= V_2 -> V_12 ; V_71 ++ ) {
struct V_1 * V_14 ;
V_14 = V_7 -> V_159 [ V_71 - 1 ] -> V_188 ;
if ( V_14 && V_14 -> V_423 ) {
F_7 ( & V_193 -> V_22 , L_125 , V_71 ) ;
if ( F_198 ( V_405 ) )
return - V_315 ;
}
if ( V_14 )
V_7 -> F_197 +=
F_197 ( V_14 ) ;
}
if ( V_2 -> V_404 && V_7 -> V_300 ) {
if ( F_207 ( V_7 ) ) {
if ( F_198 ( V_405 ) )
return - V_315 ;
F_209 ( & V_2 -> V_22 , 2000 ) ;
}
}
if ( F_1 ( V_2 ) && V_2 -> V_404 ) {
for ( V_71 = 1 ; V_71 <= V_2 -> V_12 ; V_71 ++ ) {
V_75 = F_19 ( V_2 ,
V_71 |
V_424 |
V_425 |
V_426 ,
V_427 ) ;
}
}
F_21 ( & V_193 -> V_22 , L_114 , V_113 ) ;
F_75 ( V_7 , V_231 ) ;
return 0 ;
}
static int F_210 ( struct V_192 * V_193 )
{
struct V_6 * V_7 = F_4 ( V_193 ) ;
F_21 ( & V_193 -> V_22 , L_114 , V_113 ) ;
F_69 ( V_7 , V_202 ) ;
return 0 ;
}
static int F_211 ( struct V_192 * V_193 )
{
struct V_6 * V_7 = F_4 ( V_193 ) ;
F_21 ( & V_193 -> V_22 , L_114 , V_113 ) ;
F_69 ( V_7 , V_209 ) ;
return 0 ;
}
void F_212 ( struct V_1 * V_428 )
{
F_7 ( & V_428 -> V_22 , L_126 ) ;
V_428 -> V_225 = 1 ;
}
static int F_213 ( struct V_1 * V_14 , enum V_429 V_82 )
{
struct V_430 * V_431 ;
unsigned long long V_432 ;
unsigned long long V_433 ;
unsigned long long V_434 ;
unsigned long long V_435 ;
int V_56 ;
if ( V_14 -> V_82 != V_83 )
return 0 ;
V_432 = F_214 ( V_14 -> V_52 . V_43 , 1000 ) ;
V_433 = F_214 ( V_14 -> V_52 . V_40 , 1000 ) ;
V_434 = F_214 ( V_14 -> V_53 . V_43 , 1000 ) ;
V_435 = F_214 ( V_14 -> V_53 . V_40 , 1000 ) ;
if ( ( V_82 == V_436 &&
( V_432 > V_437 ||
V_433 > V_437 ) ) ||
( V_82 == V_438 &&
( V_434 > V_439 ||
V_435 > V_439 ) ) ) {
F_21 ( & V_14 -> V_22 , L_127 ,
V_440 [ V_82 ] , V_432 , V_433 ) ;
return - V_68 ;
}
if ( V_432 > V_437 )
V_432 = V_437 ;
if ( V_433 > V_437 )
V_433 = V_437 ;
if ( V_434 > V_439 )
V_434 = V_439 ;
if ( V_435 > V_439 )
V_435 = V_439 ;
V_431 = F_51 ( sizeof *( V_431 ) , V_211 ) ;
if ( ! V_431 )
return - V_164 ;
V_431 -> V_432 = V_432 ;
V_431 -> V_433 = V_433 ;
V_431 -> V_434 = F_215 ( V_434 ) ;
V_431 -> V_435 = F_215 ( V_435 ) ;
V_56 = F_14 ( V_14 , F_17 ( V_14 , 0 ) ,
V_441 ,
V_269 ,
0 , 0 ,
V_431 , sizeof *( V_431 ) ,
V_205 ) ;
F_48 ( V_431 ) ;
return V_56 ;
}
static int F_216 ( struct V_1 * V_14 ,
enum V_429 V_82 , bool V_442 )
{
int V_56 ;
int V_69 ;
switch ( V_82 ) {
case V_436 :
V_69 = V_443 ;
break;
case V_438 :
V_69 = V_444 ;
break;
default:
F_7 ( & V_14 -> V_22 , L_128 ,
V_113 , V_442 ? L_129 : L_130 ) ;
return - V_68 ;
}
if ( V_14 -> V_82 != V_83 ) {
F_21 ( & V_14 -> V_22 , L_131
L_132 ,
V_113 , V_442 ? L_129 : L_130 ,
V_440 [ V_82 ] ) ;
return 0 ;
}
if ( V_442 ) {
V_56 = F_14 ( V_14 , F_17 ( V_14 , 0 ) ,
V_73 ,
V_269 ,
V_69 ,
0 , NULL , 0 ,
V_205 ) ;
} else {
V_56 = F_14 ( V_14 , F_17 ( V_14 , 0 ) ,
V_70 ,
V_269 ,
V_69 ,
0 , NULL , 0 ,
V_205 ) ;
}
if ( V_56 < 0 ) {
F_7 ( & V_14 -> V_22 , L_133 ,
V_442 ? L_134 : L_135 ,
V_440 [ V_82 ] ) ;
return - V_315 ;
}
return 0 ;
}
static int F_217 ( struct V_1 * V_14 ,
enum V_429 V_82 , int V_445 )
{
int V_56 ;
int V_69 ;
switch ( V_82 ) {
case V_436 :
V_69 = V_446 ;
break;
case V_438 :
V_69 = V_447 ;
break;
default:
F_7 ( & V_14 -> V_22 , L_136 ,
V_113 ) ;
return - V_68 ;
}
if ( V_82 == V_436 && V_445 > V_448 &&
V_445 != V_449 ) {
F_7 ( & V_14 -> V_22 , L_137
L_138 ,
V_440 [ V_82 ] , V_445 ) ;
return - V_68 ;
}
V_56 = F_19 ( V_14 -> V_23 ,
F_218 ( V_445 ) | V_14 -> V_123 ,
V_69 ) ;
if ( V_56 < 0 ) {
F_7 ( & V_14 -> V_22 , L_139
L_140 , V_440 [ V_82 ] ,
V_445 , V_56 ) ;
return - V_315 ;
}
if ( V_82 == V_436 )
V_14 -> V_52 . V_445 = V_445 ;
else
V_14 -> V_53 . V_445 = V_445 ;
return 0 ;
}
static void F_219 ( struct V_196 * V_152 , struct V_1 * V_14 ,
enum V_429 V_82 )
{
int V_445 , V_56 ;
T_4 V_450 = V_14 -> V_17 -> V_21 -> V_50 ;
T_5 V_451 = V_14 -> V_17 -> V_21 -> V_51 ;
if ( ( V_82 == V_436 && V_450 == 0 ) ||
( V_82 == V_438 && V_451 == 0 ) )
return;
V_56 = F_213 ( V_14 , V_82 ) ;
if ( V_56 < 0 ) {
F_7 ( & V_14 -> V_22 , L_141 ,
V_440 [ V_82 ] ) ;
return;
}
V_445 = V_152 -> V_153 -> V_452 ( V_152 , V_14 , V_82 ) ;
if ( V_445 == 0 )
return;
if ( V_445 < 0 ) {
F_7 ( & V_14 -> V_22 , L_142
L_143 , V_440 [ V_82 ] ,
V_445 ) ;
return;
}
if ( F_217 ( V_14 , V_82 , V_445 ) )
V_152 -> V_153 -> V_453 ( V_152 , V_14 , V_82 ) ;
else if ( V_14 -> V_11 )
F_216 ( V_14 , V_82 , true ) ;
}
static int F_220 ( struct V_196 * V_152 , struct V_1 * V_14 ,
enum V_429 V_82 )
{
int V_69 ;
switch ( V_82 ) {
case V_436 :
V_69 = V_446 ;
break;
case V_438 :
V_69 = V_447 ;
break;
default:
F_7 ( & V_14 -> V_22 , L_144 ,
V_113 ) ;
return - V_68 ;
}
if ( F_217 ( V_14 , V_82 , 0 ) )
return - V_315 ;
F_216 ( V_14 , V_82 , false ) ;
if ( V_152 -> V_153 -> V_453 ( V_152 , V_14 , V_82 ) )
F_7 ( & V_14 -> V_22 , L_145
L_146 ,
V_440 [ V_82 ] ) ;
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
if ( ! V_152 || ! V_152 -> V_153 -> V_453 )
return 0 ;
V_14 -> V_454 ++ ;
if ( ( V_14 -> V_52 . V_445 == 0 && V_14 -> V_53 . V_445 == 0 ) )
return 0 ;
if ( F_220 ( V_152 , V_14 , V_436 ) )
goto V_455;
if ( F_220 ( V_152 , V_14 , V_438 ) )
goto V_455;
return 0 ;
V_455:
F_222 ( V_14 ) ;
return - V_315 ;
}
int F_200 ( struct V_1 * V_14 )
{
struct V_196 * V_152 = F_55 ( V_14 -> V_169 ) ;
int V_56 ;
if ( ! V_152 )
return - V_68 ;
F_28 ( V_152 -> V_456 ) ;
V_56 = F_221 ( V_14 ) ;
F_30 ( V_152 -> V_456 ) ;
return V_56 ;
}
void F_222 ( struct V_1 * V_14 )
{
struct V_196 * V_152 ;
if ( ! V_14 || ! V_14 -> V_23 ||
V_14 -> V_15 != V_49 ||
! V_14 -> V_24 )
return;
V_14 -> V_454 -- ;
V_152 = F_55 ( V_14 -> V_169 ) ;
if ( ! V_152 || ! V_152 -> V_153 -> V_452 ||
! V_152 -> V_153 -> V_453 )
return;
if ( V_14 -> V_454 > 0 )
return;
F_219 ( V_152 , V_14 , V_436 ) ;
F_219 ( V_152 , V_14 , V_438 ) ;
}
void F_201 ( struct V_1 * V_14 )
{
struct V_196 * V_152 = F_55 ( V_14 -> V_169 ) ;
if ( ! V_152 )
return;
F_28 ( V_152 -> V_456 ) ;
F_222 ( V_14 ) ;
F_30 ( V_152 -> V_456 ) ;
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
int F_223 ( struct V_6 * V_7 , int V_71 , bool V_457 )
{
int V_56 ;
int V_180 , V_458 = 0 ;
T_1 V_181 , V_8 ;
unsigned V_459 = 0xffff ;
for ( V_180 = 0 ; ; V_180 += V_183 ) {
V_56 = F_27 ( V_7 , V_71 , & V_8 , & V_181 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( ! ( V_181 & V_214 ) &&
( V_8 & V_212 ) == V_459 ) {
if ( ! V_457 ||
( V_459 == V_212 ) )
V_458 += V_183 ;
if ( V_458 >= V_226 )
break;
} else {
V_458 = 0 ;
V_459 = V_8 & V_212 ;
}
if ( V_181 & V_214 ) {
F_18 ( V_7 -> V_2 , V_71 ,
V_215 ) ;
}
if ( V_180 >= V_185 )
break;
F_59 ( V_183 ) ;
}
F_21 ( V_7 -> V_112 ,
L_147 ,
V_71 , V_180 , V_458 , V_8 ) ;
if ( V_458 < V_226 )
return - V_102 ;
return V_8 ;
}
void F_224 ( struct V_1 * V_14 )
{
F_225 ( V_14 , 0 + V_64 , true ) ;
F_225 ( V_14 , 0 + V_460 , true ) ;
F_226 ( V_14 , & V_14 -> V_333 , true ) ;
}
static int F_227 ( struct V_1 * V_14 , int V_167 )
{
int V_461 ;
struct V_196 * V_152 = F_55 ( V_14 -> V_169 ) ;
if ( ! V_152 -> V_153 -> V_462 && V_167 <= 1 )
return - V_68 ;
if ( V_14 -> V_82 == V_414 )
return 0 ;
if ( V_14 -> V_82 != V_388 )
return - V_68 ;
if ( V_152 -> V_153 -> V_462 )
V_461 = V_152 -> V_153 -> V_462 ( V_152 , V_14 ) ;
else
V_461 = F_14 ( V_14 , F_228 () ,
V_463 , 0 , V_167 , 0 ,
NULL , 0 , V_205 ) ;
if ( V_461 == 0 ) {
F_132 ( V_14 , V_167 ) ;
F_64 ( V_14 , V_414 ) ;
F_224 ( V_14 ) ;
}
return V_461 ;
}
static void F_229 ( struct V_1 * V_14 )
{
int V_464 ;
if ( ! V_14 -> V_412 )
return;
V_464 = F_230 ( V_14 -> V_23 ,
V_14 -> V_123 ) ;
if ( ( V_14 -> V_17 -> V_18 -> V_20 & V_465 ) ||
V_464 == V_466 ) {
V_14 -> V_467 = 1 ;
F_199 ( V_14 , 1 ) ;
}
}
static int
F_231 ( struct V_6 * V_7 , struct V_1 * V_14 , int V_71 ,
int V_468 )
{
static F_232 ( V_469 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_196 * V_152 = F_55 ( V_2 -> V_169 ) ;
int V_55 , V_470 , V_461 ;
unsigned V_173 = V_380 ;
enum V_471 V_472 = V_14 -> V_15 ;
const char * V_15 ;
int V_167 = V_14 -> V_167 ;
if ( ! V_2 -> V_23 ) {
V_173 = V_473 ;
if ( V_71 == V_2 -> V_169 -> V_350 )
V_2 -> V_169 -> V_351 = 0 ;
}
if ( V_472 == V_384 )
V_173 = V_381 ;
F_28 ( & V_469 ) ;
V_461 = F_186 ( V_7 , V_71 , V_14 , V_173 , false ) ;
if ( V_461 < 0 )
goto V_245;
V_461 = - V_111 ;
if ( V_472 != V_474 && V_472 != V_14 -> V_15 ) {
F_21 ( & V_14 -> V_22 , L_148 ) ;
goto V_245;
}
V_472 = V_14 -> V_15 ;
switch ( V_14 -> V_15 ) {
case V_49 :
case V_383 :
V_14 -> V_333 . V_278 . V_475 = F_215 ( 512 ) ;
break;
case V_16 :
V_14 -> V_333 . V_278 . V_475 = F_215 ( 64 ) ;
break;
case V_385 :
V_14 -> V_333 . V_278 . V_475 = F_215 ( 64 ) ;
break;
case V_384 :
V_14 -> V_333 . V_278 . V_475 = F_215 ( 8 ) ;
break;
default:
goto V_245;
}
if ( V_14 -> V_15 == V_383 )
V_15 = L_149 ;
else
V_15 = F_233 ( V_14 -> V_15 ) ;
if ( V_14 -> V_15 != V_49 )
F_84 ( & V_14 -> V_22 ,
L_150 ,
( V_14 -> V_344 ) ? L_151 : L_152 , V_15 ,
V_167 , V_14 -> V_169 -> V_476 -> V_153 -> V_477 ) ;
if ( V_2 -> V_139 ) {
V_14 -> V_139 = V_2 -> V_139 ;
V_14 -> V_166 = V_2 -> V_166 ;
} else if ( V_14 -> V_15 != V_16
&& V_2 -> V_15 == V_16 ) {
if ( ! V_7 -> V_139 . V_7 ) {
F_29 ( & V_14 -> V_22 , L_153 ) ;
V_461 = - V_68 ;
goto V_245;
}
V_14 -> V_139 = & V_7 -> V_139 ;
V_14 -> V_166 = V_71 ;
}
for ( V_55 = 0 ; V_55 < V_478 ; ( ++ V_55 , F_59 ( 100 ) ) ) {
if ( F_234 ( V_468 ) && ! ( V_152 -> V_153 -> V_117 & V_479 ) ) {
struct V_480 * V_481 ;
int V_482 = 0 ;
#define F_235 64
V_481 = F_51 ( F_235 , V_211 ) ;
if ( ! V_481 ) {
V_461 = - V_164 ;
continue;
}
for ( V_470 = 0 ; V_470 < 3 ; ++ V_470 ) {
V_481 -> V_483 = 0 ;
V_482 = F_14 ( V_14 , F_236 () ,
V_63 , V_64 ,
V_484 << 8 , 0 ,
V_481 , F_235 ,
V_485 ) ;
switch ( V_481 -> V_483 ) {
case 8 : case 16 : case 32 : case 64 : case 255 :
if ( V_481 -> V_486 ==
V_484 ) {
V_482 = 0 ;
break;
}
default:
if ( V_482 == 0 )
V_482 = - V_487 ;
break;
}
if ( V_482 == 0 )
break;
}
V_14 -> V_3 . V_483 =
V_481 -> V_483 ;
F_48 ( V_481 ) ;
V_461 = F_186 ( V_7 , V_71 , V_14 , V_173 , false ) ;
if ( V_461 < 0 )
goto V_245;
if ( V_472 != V_14 -> V_15 ) {
F_21 ( & V_14 -> V_22 ,
L_148 ) ;
V_461 = - V_111 ;
goto V_245;
}
if ( V_482 ) {
if ( V_482 != - V_111 )
F_29 ( & V_14 -> V_22 , L_154 ,
V_482 ) ;
V_461 = - V_488 ;
continue;
}
#undef F_235
}
if ( V_14 -> V_325 == 0 ) {
for ( V_470 = 0 ; V_470 < V_489 ; ++ V_470 ) {
V_461 = F_227 ( V_14 , V_167 ) ;
if ( V_461 >= 0 )
break;
F_59 ( 200 ) ;
}
if ( V_461 < 0 ) {
if ( V_461 != - V_111 )
F_29 ( & V_14 -> V_22 , L_155 ,
V_167 , V_461 ) ;
goto V_245;
}
if ( V_14 -> V_15 == V_49 ) {
V_167 = V_14 -> V_167 ;
F_84 ( & V_14 -> V_22 ,
L_156 ,
( V_14 -> V_344 ) ? L_151 : L_152 ,
V_167 , V_14 -> V_169 -> V_476 -> V_153 -> V_477 ) ;
}
F_59 ( 10 ) ;
if ( F_234 ( V_468 ) && ! ( V_152 -> V_153 -> V_117 & V_479 ) )
break;
}
V_461 = F_179 ( V_14 , 8 ) ;
if ( V_461 < 8 ) {
if ( V_461 != - V_111 )
F_29 ( & V_14 -> V_22 ,
L_157 ,
V_461 ) ;
if ( V_461 >= 0 )
V_461 = - V_488 ;
} else {
V_461 = 0 ;
break;
}
}
if ( V_461 )
goto V_245;
if ( V_152 -> V_490 && ! V_2 -> V_23 )
F_237 ( V_152 -> V_490 , V_14 -> V_15 ) ;
if ( ( V_14 -> V_15 == V_49 ) &&
( F_12 ( V_14 -> V_3 . V_491 ) < 0x0300 ) ) {
F_29 ( & V_14 -> V_22 , L_158
L_159 ) ;
F_186 ( V_7 , V_71 , V_14 ,
V_492 , true ) ;
V_461 = - V_68 ;
goto V_245;
}
if ( V_14 -> V_3 . V_483 == 0xff ||
V_14 -> V_15 == V_49 )
V_55 = 512 ;
else
V_55 = V_14 -> V_3 . V_483 ;
if ( F_238 ( & V_14 -> V_333 . V_278 ) != V_55 ) {
if ( V_14 -> V_15 == V_384 ||
! ( V_55 == 8 || V_55 == 16 || V_55 == 32 || V_55 == 64 ) ) {
F_29 ( & V_14 -> V_22 , L_160 , V_55 ) ;
V_461 = - V_488 ;
goto V_245;
}
if ( V_14 -> V_15 == V_385 )
F_21 ( & V_14 -> V_22 , L_161 , V_55 ) ;
else
F_7 ( & V_14 -> V_22 , L_162 , V_55 ) ;
V_14 -> V_333 . V_278 . V_475 = F_215 ( V_55 ) ;
F_224 ( V_14 ) ;
}
V_461 = F_179 ( V_14 , V_493 ) ;
if ( V_461 < ( signed ) sizeof( V_14 -> V_3 ) ) {
if ( V_461 != - V_111 )
F_29 ( & V_14 -> V_22 , L_163 ,
V_461 ) ;
if ( V_461 >= 0 )
V_461 = - V_494 ;
goto V_245;
}
if ( V_14 -> V_325 == 0 && F_12 ( V_14 -> V_3 . V_491 ) >= 0x0201 ) {
V_461 = F_239 ( V_14 ) ;
if ( ! V_461 ) {
V_14 -> V_24 = F_5 ( V_14 ) ;
F_11 ( V_14 ) ;
}
}
V_461 = 0 ;
if ( V_152 -> V_153 -> V_495 )
V_152 -> V_153 -> V_495 ( V_152 , V_14 ) ;
F_229 ( V_14 ) ;
V_245:
if ( V_461 ) {
F_63 ( V_7 , V_71 , 0 ) ;
F_132 ( V_14 , V_167 ) ;
}
F_30 ( & V_469 ) ;
return V_461 ;
}
static void
F_240 ( struct V_6 * V_7 , struct V_1 * V_14 , int V_71 )
{
struct V_496 * V_497 ;
int V_75 ;
V_497 = F_51 ( sizeof *V_497 , V_244 ) ;
if ( V_497 == NULL )
return;
V_75 = F_241 ( V_14 , V_498 , 0 ,
V_497 , sizeof *V_497 ) ;
if ( V_75 == sizeof *V_497 ) {
F_84 ( & V_14 -> V_22 , L_164
L_165 ) ;
if ( V_7 -> V_228 ) {
V_7 -> V_86 [ V_71 - 1 ] = V_90 ;
F_24 ( & V_7 -> V_79 , 0 ) ;
}
}
F_48 ( V_497 ) ;
}
static unsigned
F_242 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_276 ;
int V_71 ;
if ( ! V_7 -> V_274 )
return 0 ;
V_276 = V_2 -> V_272 - V_7 -> V_3 -> V_277 ;
for ( V_71 = 1 ; V_71 <= V_2 -> V_12 ; ++ V_71 ) {
struct V_1 * V_14 = V_7 -> V_159 [ V_71 - 1 ] -> V_188 ;
int V_499 ;
unsigned V_242 ;
if ( ! V_14 )
continue;
if ( F_1 ( V_14 ) )
V_242 = 150 ;
else
V_242 = 100 ;
if ( V_14 -> V_11 )
V_499 = F_243 ( V_14 , V_14 -> V_11 ) ;
else if ( V_71 != V_14 -> V_169 -> V_350 || V_2 -> V_23 )
V_499 = V_242 ;
else
V_499 = 8 ;
if ( V_499 > V_7 -> V_273 )
F_7 ( & V_14 -> V_22 ,
L_166 ,
V_499 , V_7 -> V_273 , V_71 ) ;
V_276 -= V_499 ;
}
if ( V_276 < 0 ) {
F_7 ( V_7 -> V_112 , L_167 ,
- V_276 ) ;
V_276 = 0 ;
}
return V_276 ;
}
static void F_244 ( struct V_6 * V_7 , int V_71 ,
T_1 V_8 , T_1 V_181 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_236 * V_237 = V_7 -> V_112 ;
struct V_196 * V_152 = F_55 ( V_2 -> V_169 ) ;
unsigned V_174 =
F_12 ( V_7 -> V_3 -> V_174 ) ;
struct V_1 * V_14 ;
int V_75 , V_55 ;
unsigned V_242 ;
F_21 ( V_237 ,
L_168 ,
V_71 , V_8 , V_181 , F_2 ( V_7 , V_8 ) ) ;
if ( V_7 -> V_228 ) {
F_20 ( V_7 , V_71 , V_88 ) ;
V_7 -> V_86 [ V_71 - 1 ] = V_89 ;
}
#ifdef F_146
if ( V_2 -> V_169 -> V_343 )
V_181 &= ~ ( V_214 |
V_216 ) ;
#endif
V_14 = V_7 -> V_159 [ V_71 - 1 ] -> V_188 ;
if ( ( V_8 & V_212 ) && V_14 &&
V_14 -> V_82 != V_189 ) {
F_134 ( V_14 ) ;
if ( V_8 & V_213 ) {
V_75 = 0 ;
#ifdef F_245
} else if ( V_14 -> V_82 == V_317 &&
V_14 -> V_224 ) {
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
if ( V_152 -> V_490 && ! V_2 -> V_23 &&
! ( V_8 & V_212 ) )
F_246 ( V_152 -> V_490 , V_14 -> V_15 ) ;
F_77 ( & V_7 -> V_159 [ V_71 - 1 ] -> V_188 ) ;
}
F_72 ( V_71 , V_7 -> V_191 ) ;
if ( ! ( V_8 & V_212 ) ||
( V_181 & V_214 ) )
F_72 ( V_71 , V_7 -> V_194 ) ;
if ( V_181 & ( V_214 |
V_216 ) ) {
V_75 = F_247 ( V_7 , V_71 ) ;
if ( V_75 < 0 ) {
if ( V_75 != - V_111 && F_248 () )
F_29 ( V_237 , L_169
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
F_19 ( V_2 , V_71 , V_160 ) ;
if ( V_8 & V_213 )
goto V_390;
return;
}
if ( F_1 ( V_7 -> V_2 ) )
V_242 = 150 ;
else
V_242 = 100 ;
V_75 = 0 ;
for ( V_55 = 0 ; V_55 < V_500 ; V_55 ++ ) {
V_14 = F_249 ( V_2 , V_2 -> V_169 , V_71 ) ;
if ( ! V_14 ) {
F_29 ( V_237 ,
L_171 ,
V_71 ) ;
goto V_390;
}
F_64 ( V_14 , V_501 ) ;
V_14 -> V_272 = V_7 -> V_273 ;
V_14 -> V_204 = V_2 -> V_204 + 1 ;
V_14 -> V_325 = F_182 ( V_7 ) ;
if ( F_1 ( V_7 -> V_2 ) )
V_14 -> V_15 = V_49 ;
else
V_14 -> V_15 = V_474 ;
F_127 ( V_14 ) ;
if ( V_14 -> V_167 <= 0 ) {
V_75 = - V_382 ;
goto V_502;
}
V_75 = F_231 ( V_7 , V_14 , V_71 , V_55 ) ;
if ( V_75 < 0 )
goto V_502;
F_250 ( V_14 ) ;
if ( V_14 -> V_503 & V_504 )
F_59 ( 1000 ) ;
if ( V_14 -> V_3 . V_505 == V_506
&& V_14 -> V_272 <= V_242 ) {
T_1 V_507 ;
V_75 = F_90 ( V_14 , V_269 , 0 ,
& V_507 ) ;
if ( V_75 ) {
F_21 ( & V_14 -> V_22 , L_172 , V_75 ) ;
goto V_508;
}
if ( ( V_507 & ( 1 << V_275 ) ) == 0 ) {
F_29 ( & V_14 -> V_22 ,
L_173
L_174 ) ;
if ( V_7 -> V_228 ) {
V_7 -> V_86 [ V_71 - 1 ] =
V_94 ;
F_24 ( & V_7 -> V_79 , 0 ) ;
}
V_75 = - V_382 ;
goto V_508;
}
}
if ( F_12 ( V_14 -> V_3 . V_491 ) >= 0x0200
&& V_14 -> V_15 == V_385
&& V_287 != 0 )
F_240 ( V_7 , V_14 , V_71 ) ;
V_75 = 0 ;
F_102 ( & V_306 ) ;
if ( V_2 -> V_82 == V_189 )
V_75 = - V_382 ;
else
V_7 -> V_159 [ V_71 - 1 ] -> V_188 = V_14 ;
F_105 ( & V_306 ) ;
if ( ! V_75 ) {
V_75 = F_156 ( V_14 ) ;
if ( V_75 ) {
F_102 ( & V_306 ) ;
V_7 -> V_159 [ V_71 - 1 ] -> V_188 = NULL ;
F_105 ( & V_306 ) ;
}
}
if ( V_75 )
goto V_508;
V_75 = F_242 ( V_7 ) ;
if ( V_75 )
F_21 ( V_237 , L_175 , V_75 ) ;
return;
V_508:
F_63 ( V_7 , V_71 , 1 ) ;
V_502:
F_224 ( V_14 ) ;
F_131 ( V_14 ) ;
F_133 ( V_14 ) ;
F_251 ( V_14 ) ;
if ( ( V_75 == - V_382 ) || ( V_75 == - V_355 ) )
break;
}
if ( V_7 -> V_2 -> V_23 ||
! V_152 -> V_153 -> V_509 ||
! ( V_152 -> V_153 -> V_509 ) ( V_152 , V_71 ) ) {
if ( V_75 != - V_382 && V_75 != - V_111 )
F_29 ( V_237 , L_176 ,
V_71 ) ;
}
V_390:
F_63 ( V_7 , V_71 , 1 ) ;
if ( V_152 -> V_153 -> V_510 && ! V_7 -> V_2 -> V_23 )
V_152 -> V_153 -> V_510 ( V_152 , V_71 ) ;
}
static int F_252 ( struct V_6 * V_7 , unsigned int V_110 ,
T_1 V_8 , T_1 V_181 )
{
struct V_1 * V_2 ;
struct V_1 * V_14 ;
int V_511 = 0 ;
int V_56 ;
V_2 = V_7 -> V_2 ;
V_14 = V_7 -> V_159 [ V_110 - 1 ] -> V_188 ;
if ( ! F_1 ( V_2 ) ) {
if ( ! ( V_181 & V_421 ) )
return 0 ;
F_18 ( V_2 , V_110 , V_422 ) ;
} else {
if ( ! V_14 || V_14 -> V_82 != V_317 ||
( V_8 & V_184 ) !=
V_223 )
return 0 ;
}
if ( V_14 ) {
F_59 ( 10 ) ;
F_134 ( V_14 ) ;
V_56 = F_206 ( V_14 ) ;
F_140 ( V_14 ) ;
if ( V_56 < 0 )
V_511 = 1 ;
} else {
V_56 = - V_111 ;
F_63 ( V_7 , V_110 , 1 ) ;
}
F_21 ( V_7 -> V_112 , L_177 ,
V_110 , V_56 ) ;
return V_511 ;
}
static void F_253 ( void )
{
struct V_146 * V_512 ;
struct V_1 * V_2 ;
struct V_192 * V_193 ;
struct V_6 * V_7 ;
struct V_236 * V_237 ;
T_1 V_238 ;
T_1 V_239 ;
T_1 V_8 ;
T_1 V_181 ;
int V_55 , V_56 ;
int V_511 , V_513 ;
while ( 1 ) {
F_102 ( & V_118 ) ;
if ( F_33 ( & V_121 ) ) {
F_105 ( & V_118 ) ;
break;
}
V_512 = V_121 . V_147 ;
F_103 ( V_512 ) ;
V_7 = F_46 ( V_512 , struct V_6 , V_120 ) ;
F_254 ( & V_7 -> V_285 ) ;
F_105 ( & V_118 ) ;
V_2 = V_7 -> V_2 ;
V_237 = V_7 -> V_112 ;
V_193 = F_36 ( V_237 ) ;
F_21 ( V_237 , L_178 ,
V_2 -> V_82 , V_2 -> V_12 ,
( T_1 ) V_7 -> V_191 [ 0 ] ,
( T_1 ) V_7 -> V_135 [ 0 ] ) ;
F_134 ( V_2 ) ;
if ( F_255 ( V_7 -> V_119 ) )
goto V_514;
if ( V_2 -> V_82 == V_189 ) {
V_7 -> error = - V_111 ;
F_75 ( V_7 , V_286 ) ;
goto V_502;
}
V_56 = F_67 ( V_193 ) ;
if ( V_56 ) {
F_21 ( V_237 , L_179 , V_56 ) ;
goto V_502;
}
if ( V_7 -> V_84 )
goto V_515;
if ( V_7 -> error ) {
F_21 ( V_237 , L_180 ,
V_7 -> error ) ;
V_56 = F_256 ( V_2 ) ;
if ( V_56 ) {
F_21 ( V_237 ,
L_181 , V_56 ) ;
goto V_515;
}
V_7 -> V_131 = 0 ;
V_7 -> error = 0 ;
}
for ( V_55 = 1 ; V_55 <= V_2 -> V_12 ; V_55 ++ ) {
if ( F_129 ( V_55 , V_7 -> V_419 ) )
continue;
V_511 = F_129 ( V_55 , V_7 -> V_191 ) ;
V_513 = F_257 ( V_55 , V_7 -> V_124 ) ;
if ( ! F_257 ( V_55 , V_7 -> V_135 ) &&
! V_511 && ! V_513 )
continue;
V_56 = F_27 ( V_7 , V_55 ,
& V_8 , & V_181 ) ;
if ( V_56 < 0 )
continue;
if ( V_181 & V_214 ) {
F_18 ( V_2 , V_55 ,
V_215 ) ;
V_511 = 1 ;
}
if ( V_181 & V_216 ) {
if ( ! V_511 )
F_21 ( V_237 ,
L_182
L_183 ,
V_55 , V_8 ) ;
F_18 ( V_2 , V_55 ,
V_217 ) ;
if ( ! ( V_8 & V_213 )
&& ! V_511
&& V_7 -> V_159 [ V_55 - 1 ] -> V_188 ) {
F_29 ( V_237 ,
L_184
L_185
L_186 ,
V_55 ) ;
V_511 = 1 ;
}
}
if ( F_252 ( V_7 , V_55 ,
V_8 , V_181 ) )
V_511 = 1 ;
if ( V_181 & V_516 ) {
T_1 V_75 = 0 ;
T_1 V_517 ;
F_21 ( V_237 , L_187
L_188 , V_55 ) ;
F_18 ( V_2 , V_55 ,
V_518 ) ;
F_59 ( 100 ) ;
F_57 ( V_7 , true ) ;
F_27 ( V_7 , V_55 , & V_75 , & V_517 ) ;
if ( V_75 & V_519 )
F_29 ( V_237 , L_189
L_190 , V_55 ) ;
}
if ( V_181 & V_218 ) {
F_21 ( V_237 ,
L_191 ,
V_55 ) ;
F_18 ( V_2 , V_55 ,
V_219 ) ;
}
if ( ( V_181 & V_220 ) &&
F_1 ( V_7 -> V_2 ) ) {
F_21 ( V_237 ,
L_192 ,
V_55 ) ;
F_18 ( V_2 , V_55 ,
V_221 ) ;
}
if ( V_181 & V_420 ) {
F_18 ( V_7 -> V_2 , V_55 ,
V_387 ) ;
}
if ( V_181 & V_520 ) {
F_7 ( V_237 ,
L_193 ,
V_55 ) ;
F_18 ( V_7 -> V_2 , V_55 ,
V_521 ) ;
}
if ( F_183 ( V_7 , V_8 ) ) {
int V_75 ;
struct V_1 * V_14 =
V_7 -> V_159 [ V_55 - 1 ] -> V_188 ;
F_21 ( V_237 , L_194 , V_55 ) ;
if ( ! V_14 ||
! ( V_8 & V_212 ) ||
V_14 -> V_82 == V_189 ) {
V_75 = F_186 ( V_7 , V_55 ,
NULL , V_492 ,
true ) ;
if ( V_75 < 0 )
F_63 ( V_7 , V_55 , 1 ) ;
} else {
F_134 ( V_14 ) ;
V_75 = F_256 ( V_14 ) ;
F_140 ( V_14 ) ;
V_511 = 0 ;
}
}
if ( V_511 )
F_244 ( V_7 , V_55 ,
V_8 , V_181 ) ;
}
if ( F_257 ( 0 , V_7 -> V_135 ) == 0 )
;
else if ( F_60 ( V_7 , & V_238 , & V_239 ) < 0 )
F_29 ( V_237 , L_195 ) ;
else {
if ( V_239 & V_522 ) {
F_21 ( V_237 , L_196 ) ;
F_16 ( V_2 , V_523 ) ;
if ( V_238 & V_280 )
V_7 -> V_274 = 1 ;
else
V_7 -> V_274 = 0 ;
}
if ( V_239 & V_524 ) {
T_1 V_75 = 0 ;
T_1 V_517 ;
F_21 ( V_237 , L_197 ) ;
F_16 ( V_2 , V_525 ) ;
F_59 ( 500 ) ;
F_57 ( V_7 , true ) ;
F_60 ( V_7 , & V_75 , & V_517 ) ;
if ( V_75 & V_281 )
F_29 ( V_237 , L_189
L_198 ) ;
}
}
V_515:
F_104 ( V_193 ) ;
V_502:
F_68 ( V_193 ) ;
V_514:
F_140 ( V_2 ) ;
F_110 ( & V_7 -> V_285 , F_98 ) ;
}
}
static int F_258 ( void * V_526 )
{
F_259 () ;
do {
F_253 () ;
F_260 ( V_122 ,
! F_33 ( & V_121 ) ||
F_261 () ) ;
} while ( ! F_261 () || ! F_33 ( & V_121 ) );
F_262 ( L_199 , V_527 ) ;
return 0 ;
}
int F_263 ( void )
{
if ( F_264 ( & V_528 ) < 0 ) {
F_265 ( V_529 L_200 ,
V_527 ) ;
return - 1 ;
}
V_530 = F_266 ( F_258 , NULL , L_201 ) ;
if ( ! F_267 ( V_530 ) )
return 0 ;
F_268 ( & V_528 ) ;
F_265 ( V_529 L_202 , V_527 ) ;
return - 1 ;
}
void F_269 ( void )
{
F_270 ( V_530 ) ;
F_268 ( & V_528 ) ;
}
static int F_271 ( struct V_1 * V_14 ,
struct V_480 * V_531 ,
struct V_532 * V_533 )
{
int V_80 = 0 ;
unsigned V_534 ;
unsigned V_535 = 0 ;
unsigned V_536 ;
unsigned V_537 ;
int V_538 ;
char * V_481 ;
if ( memcmp ( & V_14 -> V_3 , V_531 ,
sizeof( * V_531 ) ) != 0 )
return 1 ;
if ( ( V_533 && ! V_14 -> V_17 ) || ( ! V_533 && V_14 -> V_17 ) )
return 1 ;
if ( V_14 -> V_17 ) {
V_536 = F_12 ( V_14 -> V_17 -> V_278 -> V_347 ) ;
if ( V_536 != F_12 ( V_533 -> V_278 -> V_347 ) )
return 1 ;
if ( memcmp ( V_14 -> V_17 -> V_278 , V_533 -> V_278 , V_536 ) )
return 1 ;
}
if ( V_14 -> V_341 )
V_535 = strlen ( V_14 -> V_341 ) + 1 ;
V_536 = V_535 ;
for ( V_534 = 0 ; V_534 < V_14 -> V_3 . V_365 ; V_534 ++ ) {
V_537 = F_12 ( V_14 -> V_344 [ V_534 ] . V_278 . V_347 ) ;
V_536 = F_58 ( V_536 , V_537 ) ;
}
V_481 = F_51 ( V_536 , V_211 ) ;
if ( V_481 == NULL ) {
F_29 ( & V_14 -> V_22 , L_203 ) ;
return 1 ;
}
for ( V_534 = 0 ; V_534 < V_14 -> V_3 . V_365 ; V_534 ++ ) {
V_537 = F_12 ( V_14 -> V_344 [ V_534 ] . V_278 . V_347 ) ;
V_538 = F_241 ( V_14 , V_539 , V_534 , V_481 ,
V_537 ) ;
if ( V_538 != V_537 ) {
F_21 ( & V_14 -> V_22 , L_204 ,
V_534 , V_538 ) ;
V_80 = 1 ;
break;
}
if ( memcmp ( V_481 , V_14 -> V_346 [ V_534 ] , V_537 )
!= 0 ) {
F_21 ( & V_14 -> V_22 , L_205 ,
V_534 ,
( (struct V_540 * ) V_481 ) ->
V_541 ) ;
V_80 = 1 ;
break;
}
}
if ( ! V_80 && V_535 ) {
V_538 = F_272 ( V_14 , V_14 -> V_3 . V_338 ,
V_481 , V_535 ) ;
if ( V_538 + 1 != V_535 ) {
F_21 ( & V_14 -> V_22 , L_206 ,
V_538 ) ;
V_80 = 1 ;
} else if ( memcmp ( V_481 , V_14 -> V_341 , V_538 ) != 0 ) {
F_21 ( & V_14 -> V_22 , L_207 ) ;
V_80 = 1 ;
}
}
F_48 ( V_481 ) ;
return V_80 ;
}
static int F_204 ( struct V_1 * V_14 )
{
struct V_1 * V_542 = V_14 -> V_23 ;
struct V_6 * V_543 ;
struct V_196 * V_152 = F_55 ( V_14 -> V_169 ) ;
struct V_480 V_3 = V_14 -> V_3 ;
struct V_532 * V_17 ;
int V_55 , V_56 = 0 ;
int V_71 = V_14 -> V_123 ;
if ( V_14 -> V_82 == V_189 ||
V_14 -> V_82 == V_317 ) {
F_21 ( & V_14 -> V_22 , L_208 ,
V_14 -> V_82 ) ;
return - V_68 ;
}
if ( ! V_542 ) {
F_21 ( & V_14 -> V_22 , L_209 , V_113 ) ;
return - V_544 ;
}
V_543 = F_3 ( V_542 ) ;
if ( V_14 -> V_408 == 1 )
F_199 ( V_14 , 0 ) ;
V_17 = V_14 -> V_17 ;
V_14 -> V_17 = NULL ;
V_56 = F_200 ( V_14 ) ;
if ( V_56 ) {
F_29 ( & V_14 -> V_22 , L_210 , V_113 ) ;
goto V_545;
}
V_56 = F_192 ( V_14 ) ;
if ( V_56 ) {
F_29 ( & V_14 -> V_22 , L_211 ,
V_113 ) ;
goto V_545;
}
F_41 ( V_71 , V_543 -> V_419 ) ;
for ( V_55 = 0 ; V_55 < V_500 ; ++ V_55 ) {
F_224 ( V_14 ) ;
V_56 = F_231 ( V_543 , V_14 , V_71 , V_55 ) ;
if ( V_56 >= 0 || V_56 == - V_382 || V_56 == - V_111 )
break;
}
F_72 ( V_71 , V_543 -> V_419 ) ;
if ( V_56 < 0 )
goto V_545;
if ( F_271 ( V_14 , & V_3 , V_17 ) ) {
F_84 ( & V_14 -> V_22 , L_212 ) ;
V_14 -> V_3 = V_3 ;
goto V_545;
}
if ( ! V_14 -> V_11 )
goto V_390;
F_28 ( V_152 -> V_456 ) ;
V_56 = F_273 ( V_14 , V_14 -> V_11 , NULL , NULL ) ;
if ( V_56 < 0 ) {
F_7 ( & V_14 -> V_22 ,
L_213
L_214 ) ;
F_30 ( V_152 -> V_456 ) ;
goto V_545;
}
V_56 = F_14 ( V_14 , F_17 ( V_14 , 0 ) ,
V_546 , 0 ,
V_14 -> V_11 -> V_278 . V_541 , 0 ,
NULL , 0 , V_205 ) ;
if ( V_56 < 0 ) {
F_29 ( & V_14 -> V_22 ,
L_215 ,
V_14 -> V_11 -> V_278 . V_541 , V_56 ) ;
F_30 ( V_152 -> V_456 ) ;
goto V_545;
}
F_30 ( V_152 -> V_456 ) ;
F_64 ( V_14 , V_83 ) ;
for ( V_55 = 0 ; V_55 < V_14 -> V_11 -> V_278 . V_547 ; V_55 ++ ) {
struct V_548 * V_344 = V_14 -> V_11 ;
struct V_192 * V_193 = V_344 -> V_13 [ V_55 ] ;
struct V_549 * V_278 ;
V_278 = & V_193 -> V_291 -> V_278 ;
if ( V_278 -> V_550 == 0 ) {
F_274 ( V_14 , V_193 , true ) ;
F_275 ( V_14 , V_193 , true ) ;
V_56 = 0 ;
} else {
V_193 -> V_551 = 1 ;
V_56 = F_89 ( V_14 , V_278 -> V_552 ,
V_278 -> V_550 ) ;
V_193 -> V_551 = 0 ;
}
if ( V_56 < 0 ) {
F_29 ( & V_14 -> V_22 , L_216
L_217 ,
V_278 -> V_552 ,
V_278 -> V_550 ,
V_56 ) ;
goto V_545;
}
}
V_390:
F_199 ( V_14 , 1 ) ;
F_201 ( V_14 ) ;
F_194 ( V_14 ) ;
F_276 ( V_14 ) ;
V_14 -> V_17 = V_17 ;
return 0 ;
V_545:
F_65 ( V_543 , V_71 ) ;
F_276 ( V_14 ) ;
V_14 -> V_17 = V_17 ;
return - V_111 ;
}
int F_256 ( struct V_1 * V_14 )
{
int V_56 ;
int V_55 ;
unsigned int V_553 ;
struct V_548 * V_344 = V_14 -> V_11 ;
if ( V_14 -> V_82 == V_189 ||
V_14 -> V_82 == V_317 ) {
F_21 ( & V_14 -> V_22 , L_208 ,
V_14 -> V_82 ) ;
return - V_68 ;
}
V_553 = F_277 () ;
F_178 ( V_14 ) ;
if ( V_344 ) {
for ( V_55 = 0 ; V_55 < V_344 -> V_278 . V_547 ; ++ V_55 ) {
struct V_192 * V_554 = V_344 -> V_13 [ V_55 ] ;
struct V_555 * V_151 ;
int V_556 = 0 ;
if ( V_554 -> V_22 . V_153 ) {
V_151 = F_278 ( V_554 -> V_22 . V_153 ) ;
if ( V_151 -> V_557 && V_151 -> V_558 )
V_556 = ( V_151 -> V_557 ) ( V_554 ) ;
else if ( V_554 -> V_559 ==
V_560 )
V_556 = 1 ;
if ( V_556 )
F_279 ( V_554 ) ;
}
}
}
V_56 = F_204 ( V_14 ) ;
if ( V_344 ) {
for ( V_55 = V_344 -> V_278 . V_547 - 1 ; V_55 >= 0 ; -- V_55 ) {
struct V_192 * V_554 = V_344 -> V_13 [ V_55 ] ;
struct V_555 * V_151 ;
int V_561 = V_554 -> V_562 ;
if ( ! V_561 && V_554 -> V_22 . V_153 ) {
V_151 = F_278 ( V_554 -> V_22 . V_153 ) ;
if ( V_151 -> V_558 )
V_561 = ( V_151 -> V_558 ) ( V_554 ) ;
else if ( V_554 -> V_559 ==
V_560 )
V_561 = 1 ;
}
if ( V_56 == 0 && V_561 )
F_280 ( V_554 ) ;
}
}
F_181 ( V_14 ) ;
F_281 ( V_553 ) ;
return V_56 ;
}
void F_282 ( struct V_192 * V_563 )
{
F_56 ( & V_563 -> V_564 ) ;
}
struct V_1 * F_283 ( struct V_1 * V_2 ,
int V_71 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_71 < 1 || V_71 > V_2 -> V_12 )
return NULL ;
return V_7 -> V_159 [ V_71 - 1 ] -> V_188 ;
}
void F_284 ( struct V_1 * V_2 , int V_71 ,
enum V_565 type )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_7 )
V_7 -> V_159 [ V_71 - 1 ] -> V_464 = type ;
}
enum V_565
F_230 ( struct V_1 * V_2 , int V_71 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( ! V_7 )
return V_566 ;
return V_7 -> V_159 [ V_71 - 1 ] -> V_464 ;
}
void F_97 ( struct V_1 * V_2 ,
struct V_62 * V_278 )
{
enum V_565 V_464 ;
int V_55 ;
if ( ! F_1 ( V_2 ) ) {
for ( V_55 = 1 ; V_55 <= V_2 -> V_12 ; V_55 ++ ) {
V_464 = F_230 ( V_2 , V_55 ) ;
if ( V_464 == V_466 ) {
T_2 V_567 = 1 << ( V_55 % 8 ) ;
if ( ! ( V_278 -> V_34 . V_250 . V_251 [ V_55 / 8 ] & V_567 ) ) {
F_21 ( & V_2 -> V_22 , L_218 ,
V_55 ) ;
V_278 -> V_34 . V_250 . V_251 [ V_55 / 8 ] |= V_567 ;
}
}
}
} else {
T_1 V_568 = F_12 ( V_278 -> V_34 . V_35 . V_251 ) ;
for ( V_55 = 1 ; V_55 <= V_2 -> V_12 ; V_55 ++ ) {
V_464 = F_230 ( V_2 , V_55 ) ;
if ( V_464 == V_466 ) {
T_1 V_567 = 1 << V_55 ;
if ( ! ( V_568 & V_567 ) ) {
F_21 ( & V_2 -> V_22 , L_218 ,
V_55 ) ;
V_568 |= V_567 ;
}
}
}
V_278 -> V_34 . V_35 . V_251 = F_215 ( V_568 ) ;
}
}
T_6 F_285 ( struct V_1 * V_2 ,
int V_71 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( ! V_7 )
return NULL ;
return F_286 ( & V_7 -> V_159 [ V_71 - 1 ] -> V_22 ) ;
}
