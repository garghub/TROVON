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
static struct V_6 * F_3 ( struct V_1 * V_2 )
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
static int F_17 ( struct V_1 * V_2 , int V_71 , int V_69 )
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
int F_49 ( struct V_125 * V_125 )
{
struct V_1 * V_14 = V_125 -> V_22 ;
int V_155 = V_125 -> V_155 ;
struct V_156 * V_140 = V_14 -> V_140 ;
unsigned long V_117 ;
struct V_147 * V_148 ;
if ( ( V_148 = F_50 ( sizeof *V_148 , V_136 ) ) == NULL ) {
F_28 ( & V_14 -> V_22 , L_18 ) ;
return - V_157 ;
}
V_148 -> V_140 = V_140 -> V_158 ? V_14 -> V_159 : 1 ;
V_148 -> V_139 = F_51 ( V_155 ) ;
V_148 -> V_139 |= V_14 -> V_160 << 4 ;
V_148 -> V_139 |= F_52 ( V_155 )
? ( V_161 << 11 )
: ( V_162 << 11 ) ;
if ( F_53 ( V_155 ) )
V_148 -> V_139 |= 1 << 15 ;
V_148 -> V_151 = F_54 ( V_14 -> V_163 ) ;
V_148 -> V_154 = V_125 -> V_154 ;
F_32 ( & V_140 -> V_143 , V_117 ) ;
F_34 ( & V_148 -> V_144 , & V_140 -> V_144 ) ;
F_55 ( & V_140 -> V_142 ) ;
F_38 ( & V_140 -> V_143 , V_117 ) ;
return 0 ;
}
static unsigned F_56 ( struct V_6 * V_7 , bool V_164 )
{
int V_71 ;
unsigned V_165 = V_7 -> V_3 -> V_166 * 2 ;
unsigned V_167 ;
T_1 V_168 =
F_29 ( V_7 -> V_3 -> V_168 ) ;
if ( ( V_168 & V_169 ) < 2 )
F_20 ( V_7 -> V_112 , L_19 ) ;
else
F_20 ( V_7 -> V_112 , L_20
L_21 ) ;
for ( V_71 = 1 ; V_71 <= V_7 -> V_3 -> V_85 ; V_71 ++ )
F_18 ( V_7 -> V_2 , V_71 , V_170 ) ;
V_167 = F_57 ( V_165 , ( unsigned ) 100 ) ;
if ( V_164 )
F_58 ( V_167 ) ;
return V_167 ;
}
static int F_59 ( struct V_6 * V_7 ,
T_1 * V_75 , T_1 * V_109 )
{
int V_56 ;
F_27 ( & V_7 -> V_110 ) ;
V_56 = F_24 ( V_7 -> V_2 , & V_7 -> V_75 -> V_7 ) ;
if ( V_56 < 0 )
F_28 ( V_7 -> V_112 ,
L_14 , V_113 , V_56 ) ;
else {
* V_75 = F_29 ( V_7 -> V_75 -> V_7 . V_171 ) ;
* V_109 = F_29 ( V_7 -> V_75 -> V_7 . V_172 ) ;
V_56 = 0 ;
}
F_30 ( & V_7 -> V_110 ) ;
return V_56 ;
}
static int F_60 ( struct V_6 * V_7 , int V_71 ,
unsigned int V_173 )
{
return F_18 ( V_7 -> V_2 ,
V_71 | ( V_173 << 3 ) ,
V_174 ) ;
}
static int F_61 ( struct V_6 * V_7 , int V_71 )
{
int V_56 ;
int V_175 ;
T_1 V_176 , V_8 ;
if ( ! F_1 ( V_7 -> V_2 ) )
return - V_68 ;
V_56 = F_60 ( V_7 , V_71 , V_177 ) ;
if ( V_56 ) {
F_28 ( V_7 -> V_112 , L_22 ,
V_71 , V_56 ) ;
return V_56 ;
}
for ( V_175 = 0 ; ; V_175 += V_178 ) {
V_56 = F_26 ( V_7 , V_71 , & V_8 , & V_176 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( ( V_8 & V_179 ) ==
V_177 )
break;
if ( V_175 >= V_180 )
break;
F_58 ( V_178 ) ;
}
if ( V_175 >= V_180 )
F_7 ( V_7 -> V_112 , L_23 ,
V_71 , V_175 ) ;
return F_60 ( V_7 , V_71 , V_181 ) ;
}
static int F_62 ( struct V_6 * V_7 , int V_71 , int V_182 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_56 = 0 ;
if ( V_7 -> V_183 [ V_71 - 1 ] -> V_184 && V_182 )
F_63 ( V_7 -> V_183 [ V_71 - 1 ] -> V_184 ,
V_185 ) ;
if ( ! V_7 -> error ) {
if ( F_1 ( V_7 -> V_2 ) )
V_56 = F_61 ( V_7 , V_71 ) ;
else
V_56 = F_17 ( V_2 , V_71 ,
V_186 ) ;
}
if ( V_56 )
F_28 ( V_7 -> V_112 , L_22 ,
V_71 , V_56 ) ;
return V_56 ;
}
static void F_64 ( struct V_6 * V_7 , int V_71 )
{
F_20 ( V_7 -> V_112 , L_24 , V_71 ) ;
F_62 ( V_7 , V_71 , 1 ) ;
F_41 ( V_71 , V_7 -> V_187 ) ;
F_31 ( V_7 ) ;
}
int F_65 ( struct V_1 * V_14 )
{
struct V_6 * V_7 ;
struct V_188 * V_189 ;
if ( ! V_14 -> V_23 )
return - V_68 ;
V_7 = F_3 ( V_14 -> V_23 ) ;
V_189 = F_36 ( V_7 -> V_112 ) ;
F_66 ( V_189 ) ;
F_41 ( V_14 -> V_123 , V_7 -> V_190 ) ;
F_64 ( V_7 , V_14 -> V_123 ) ;
F_67 ( V_189 ) ;
return 0 ;
}
static void F_68 ( struct V_6 * V_7 , enum V_191 type )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_192 * V_151 ;
int V_56 ;
int V_71 ;
int V_75 ;
bool V_193 = false ;
unsigned V_167 ;
if ( type == V_194 )
goto V_195;
if ( type == V_196 )
goto V_197;
if ( type != V_198 ) {
if ( V_2 -> V_23 && F_1 ( V_2 ) ) {
V_56 = F_13 ( V_2 , F_16 ( V_2 , 0 ) ,
V_199 , V_65 ,
V_2 -> V_200 - 1 , 0 , NULL , 0 ,
V_201 ) ;
if ( V_56 < 0 )
F_28 ( V_7 -> V_112 ,
L_25 ) ;
}
if ( type == V_202 ) {
V_167 = F_56 ( V_7 , false ) ;
F_69 ( & V_7 -> V_203 , V_204 ) ;
F_23 ( & V_7 -> V_203 ,
F_70 ( V_167 ) ) ;
F_35 (
F_36 ( V_7 -> V_112 ) ) ;
return;
} else if ( type == V_205 ) {
V_151 = F_54 ( V_2 -> V_163 ) ;
if ( V_151 -> V_152 -> V_206 ) {
V_56 = V_151 -> V_152 -> V_206 ( V_151 , V_2 ,
& V_7 -> V_140 , V_207 ) ;
if ( V_56 < 0 ) {
F_28 ( V_7 -> V_112 , L_26
L_27
L_28 ) ;
F_28 ( V_7 -> V_112 , L_29
L_30
L_31 ) ;
}
}
F_56 ( V_7 , true ) ;
} else {
F_56 ( V_7 , true ) ;
}
}
V_195:
for ( V_71 = 1 ; V_71 <= V_2 -> V_12 ; ++ V_71 ) {
struct V_1 * V_14 = V_7 -> V_183 [ V_71 - 1 ] -> V_184 ;
T_1 V_8 , V_176 ;
V_8 = V_176 = 0 ;
V_75 = F_26 ( V_7 , V_71 , & V_8 , & V_176 ) ;
if ( V_14 || ( V_8 & V_208 ) )
F_20 ( V_7 -> V_112 ,
L_32 ,
V_71 , V_8 , V_176 ) ;
if ( ( V_8 & V_209 ) && (
type != V_198 ||
! ( V_8 & V_208 ) ||
! V_14 ||
V_14 -> V_82 == V_185 ) ) {
if ( ! F_1 ( V_2 ) ) {
F_17 ( V_2 , V_71 ,
V_186 ) ;
V_8 &= ~ V_209 ;
} else {
V_8 &= ~ V_209 ;
}
}
if ( V_176 & V_210 ) {
V_193 = true ;
F_17 ( V_7 -> V_2 , V_71 ,
V_211 ) ;
}
if ( V_176 & V_212 ) {
V_193 = true ;
F_17 ( V_7 -> V_2 , V_71 ,
V_213 ) ;
}
if ( ( V_176 & V_214 ) &&
F_1 ( V_7 -> V_2 ) ) {
V_193 = true ;
F_17 ( V_7 -> V_2 , V_71 ,
V_215 ) ;
}
if ( ! ( V_8 & V_208 ) ||
( V_176 & V_210 ) )
F_71 ( V_71 , V_7 -> V_190 ) ;
if ( ! V_14 || V_14 -> V_82 == V_185 ) {
if ( V_14 || ( V_8 & V_208 ) )
F_41 ( V_71 , V_7 -> V_187 ) ;
} else if ( V_8 & V_209 ) {
bool V_216 = ( V_8 &
V_179 ) ==
V_217 ;
if ( V_176 || ( F_1 ( V_7 -> V_2 ) &&
V_216 ) )
F_41 ( V_71 , V_7 -> V_187 ) ;
} else if ( V_14 -> V_218 ) {
#ifdef F_72
V_14 -> V_219 = 1 ;
#endif
F_41 ( V_71 , V_7 -> V_187 ) ;
} else {
F_63 ( V_14 , V_185 ) ;
F_41 ( V_71 , V_7 -> V_187 ) ;
}
}
if ( V_193 ) {
V_167 = V_220 ;
if ( type == V_194 ) {
F_69 ( & V_7 -> V_203 , V_221 ) ;
F_23 ( & V_7 -> V_203 ,
F_70 ( V_167 ) ) ;
return;
} else {
F_58 ( V_167 ) ;
}
}
V_197:
V_7 -> V_84 = 0 ;
V_75 = F_43 ( V_7 -> V_125 , V_207 ) ;
if ( V_75 < 0 )
F_28 ( V_7 -> V_112 , L_33 , V_75 ) ;
if ( V_7 -> V_222 && V_100 )
F_23 ( & V_7 -> V_79 , V_101 ) ;
F_31 ( V_7 ) ;
if ( type <= V_196 )
F_73 ( F_36 ( V_7 -> V_112 ) ) ;
}
static void V_204 ( struct V_77 * V_223 )
{
struct V_6 * V_7 = F_22 ( V_223 , struct V_6 , V_203 . V_78 ) ;
F_68 ( V_7 , V_194 ) ;
}
static void V_221 ( struct V_77 * V_223 )
{
struct V_6 * V_7 = F_22 ( V_223 , struct V_6 , V_203 . V_78 ) ;
F_68 ( V_7 , V_196 ) ;
}
static void F_74 ( struct V_6 * V_7 , enum V_224 type )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_55 ;
F_75 ( & V_7 -> V_203 ) ;
V_7 -> V_84 = 1 ;
if ( type != V_225 ) {
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; ++ V_55 ) {
if ( V_7 -> V_183 [ V_55 ] -> V_184 )
F_76 ( & V_7 -> V_183 [ V_55 ] -> V_184 ) ;
}
}
F_77 ( V_7 -> V_125 ) ;
if ( V_7 -> V_222 )
F_75 ( & V_7 -> V_79 ) ;
if ( V_7 -> V_140 . V_7 )
F_78 ( & V_7 -> V_140 . V_142 ) ;
}
static int F_79 ( struct V_188 * V_189 )
{
struct V_6 * V_7 = F_4 ( V_189 ) ;
F_74 ( V_7 , V_226 ) ;
return 0 ;
}
static int F_80 ( struct V_188 * V_189 )
{
struct V_6 * V_7 = F_4 ( V_189 ) ;
F_68 ( V_7 , V_227 ) ;
return 0 ;
}
static void F_81 ( struct V_228 * V_22 )
{
struct V_229 * V_230 = F_82 ( V_22 ) ;
F_48 ( V_230 ) ;
}
static void F_83 ( struct V_6 * V_7 ,
int V_71 )
{
F_84 ( & V_7 -> V_183 [ V_71 - 1 ] -> V_22 ) ;
}
static int F_85 ( struct V_6 * V_7 ,
int V_71 )
{
struct V_229 * V_230 = NULL ;
int V_231 ;
V_230 = F_86 ( sizeof( * V_230 ) , V_232 ) ;
if ( ! V_230 ) {
V_231 = - V_157 ;
goto exit;
}
V_7 -> V_183 [ V_71 - 1 ] = V_230 ;
V_230 -> V_22 . V_23 = V_7 -> V_112 ;
V_230 -> V_22 . type = & V_233 ;
F_87 ( & V_230 -> V_22 , L_34 , V_71 ) ;
V_231 = F_88 ( & V_230 -> V_22 ) ;
if ( V_231 )
goto V_234;
return 0 ;
V_234:
F_89 ( & V_230 -> V_22 ) ;
exit:
return V_231 ;
}
static int F_90 ( struct V_6 * V_7 ,
struct V_235 * V_236 )
{
struct V_192 * V_151 ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_228 * V_237 = V_7 -> V_112 ;
T_1 V_238 , V_239 ;
T_1 V_168 ;
unsigned int V_155 ;
int V_240 , V_56 , V_55 ;
char * V_241 = L_35 ;
V_7 -> V_134 = F_50 ( sizeof( * V_7 -> V_134 ) , V_232 ) ;
if ( ! V_7 -> V_134 ) {
V_56 = - V_157 ;
goto V_242;
}
V_7 -> V_75 = F_50 ( sizeof( * V_7 -> V_75 ) , V_232 ) ;
if ( ! V_7 -> V_75 ) {
V_56 = - V_157 ;
goto V_242;
}
F_91 ( & V_7 -> V_110 ) ;
V_7 -> V_3 = F_50 ( sizeof( * V_7 -> V_3 ) , V_232 ) ;
if ( ! V_7 -> V_3 ) {
V_56 = - V_157 ;
goto V_242;
}
V_56 = F_12 ( V_2 , V_7 -> V_3 ) ;
if ( V_56 < 0 ) {
V_241 = L_36 ;
goto V_242;
} else if ( V_7 -> V_3 -> V_85 > V_243 ) {
V_241 = L_37 ;
V_56 = - V_137 ;
goto V_242;
}
V_2 -> V_12 = V_7 -> V_3 -> V_85 ;
F_92 ( V_237 , L_38 , V_2 -> V_12 ,
( V_2 -> V_12 == 1 ) ? L_39 : L_40 ) ;
V_7 -> V_183 = F_86 ( V_2 -> V_12 * sizeof( struct V_229 * ) ,
V_232 ) ;
if ( ! V_7 -> V_183 ) {
V_56 = - V_157 ;
goto V_242;
}
V_168 = F_29 ( V_7 -> V_3 -> V_168 ) ;
if ( ( V_168 & V_244 ) &&
! ( F_1 ( V_2 ) ) ) {
int V_55 ;
char V_245 [ V_243 + 1 ] ;
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; V_55 ++ )
V_245 [ V_55 ] = V_7 -> V_3 -> V_34 . V_246 . V_247
[ ( ( V_55 + 1 ) / 8 ) ] & ( 1 << ( ( V_55 + 1 ) % 8 ) )
? 'F' : 'R' ;
V_245 [ V_2 -> V_12 ] = 0 ;
F_20 ( V_237 , L_41 , V_245 ) ;
} else
F_20 ( V_237 , L_42 ) ;
switch ( V_168 & V_169 ) {
case V_248 :
F_20 ( V_237 , L_43 ) ;
break;
case V_249 :
F_20 ( V_237 , L_44 ) ;
break;
case V_250 :
case V_169 :
F_20 ( V_237 , L_45 ) ;
break;
}
switch ( V_168 & V_251 ) {
case V_252 :
F_20 ( V_237 , L_46 ) ;
break;
case V_253 :
F_20 ( V_237 , L_47 ) ;
break;
case V_254 :
case V_251 :
F_20 ( V_237 , L_48 ) ;
break;
}
F_93 ( & V_7 -> V_140 . V_143 ) ;
F_94 ( & V_7 -> V_140 . V_144 ) ;
F_95 ( & V_7 -> V_140 . V_142 , F_45 ) ;
switch ( V_2 -> V_3 . V_4 ) {
case V_255 :
break;
case V_256 :
F_20 ( V_237 , L_49 ) ;
V_7 -> V_140 . V_7 = V_2 ;
break;
case V_257 :
V_56 = F_96 ( V_2 , 0 , 1 ) ;
if ( V_56 == 0 ) {
F_20 ( V_237 , L_50 ) ;
V_7 -> V_140 . V_158 = 1 ;
} else
F_28 ( V_237 , L_51 ,
V_56 ) ;
V_7 -> V_140 . V_7 = V_2 ;
break;
case V_5 :
break;
default:
F_20 ( V_237 , L_52 ,
V_2 -> V_3 . V_4 ) ;
break;
}
switch ( V_168 & V_258 ) {
case V_259 :
if ( V_2 -> V_3 . V_4 != 0 ) {
V_7 -> V_140 . V_260 = 666 ;
F_20 ( V_237 , L_53
L_54 ,
8 , V_7 -> V_140 . V_260 ) ;
}
break;
case V_261 :
V_7 -> V_140 . V_260 = 666 * 2 ;
F_20 ( V_237 , L_53
L_54 ,
16 , V_7 -> V_140 . V_260 ) ;
break;
case V_262 :
V_7 -> V_140 . V_260 = 666 * 3 ;
F_20 ( V_237 , L_53
L_54 ,
24 , V_7 -> V_140 . V_260 ) ;
break;
case V_263 :
V_7 -> V_140 . V_260 = 666 * 4 ;
F_20 ( V_237 , L_53
L_54 ,
32 , V_7 -> V_140 . V_260 ) ;
break;
}
if ( V_168 & V_264 ) {
V_7 -> V_222 = 1 ;
F_20 ( V_237 , L_55 ) ;
}
F_20 ( V_237 , L_56 ,
V_7 -> V_3 -> V_166 * 2 ) ;
V_56 = F_97 ( V_2 , V_265 , 0 , & V_238 ) ;
if ( V_56 < 2 ) {
V_241 = L_57 ;
goto V_242;
}
F_98 ( & V_238 ) ;
if ( V_2 == V_2 -> V_163 -> V_266 ) {
if ( V_2 -> V_267 == 0 || V_2 -> V_267 >= 500 )
V_7 -> V_268 = 500 ;
else {
V_7 -> V_268 = V_2 -> V_267 ;
V_7 -> V_269 = 1 ;
}
} else if ( ( V_238 & ( 1 << V_270 ) ) == 0 ) {
F_20 ( V_237 , L_58 ,
V_7 -> V_3 -> V_271 ) ;
V_7 -> V_269 = 1 ;
if ( V_2 -> V_12 > 0 ) {
int V_272 = V_2 -> V_267 -
V_7 -> V_3 -> V_271 ;
if ( V_272 < V_2 -> V_12 * 100 )
F_7 ( V_237 ,
L_59
L_60 ) ;
V_7 -> V_268 = 100 ;
}
} else {
V_7 -> V_268 = 500 ;
}
if ( V_7 -> V_268 < 500 )
F_20 ( V_237 , L_61 ,
V_7 -> V_268 ) ;
V_151 = F_54 ( V_2 -> V_163 ) ;
if ( V_151 -> V_152 -> V_206 ) {
V_56 = V_151 -> V_152 -> V_206 ( V_151 , V_2 ,
& V_7 -> V_140 , V_232 ) ;
if ( V_56 < 0 ) {
V_241 = L_62 ;
goto V_242;
}
}
V_56 = F_59 ( V_7 , & V_238 , & V_239 ) ;
if ( V_56 < 0 ) {
V_241 = L_57 ;
goto V_242;
}
if ( V_2 -> V_11 -> V_273 . V_20 & V_274 )
F_20 ( V_237 , L_63 ,
( V_238 & V_275 )
? L_64 : L_65 ) ;
if ( ( V_168 & V_251 ) == 0 )
F_20 ( V_237 , L_66 ,
( V_238 & V_276 ) ? L_39 : L_67 ) ;
V_155 = F_99 ( V_2 , V_236 -> V_277 ) ;
V_240 = F_100 ( V_2 , V_155 , F_101 ( V_155 ) ) ;
if ( V_240 > sizeof( * V_7 -> V_134 ) )
V_240 = sizeof( * V_7 -> V_134 ) ;
V_7 -> V_125 = F_102 ( 0 , V_232 ) ;
if ( ! V_7 -> V_125 ) {
V_56 = - V_157 ;
goto V_242;
}
F_103 ( V_7 -> V_125 , V_2 , V_155 , * V_7 -> V_134 , V_240 , F_42 ,
V_7 , V_236 -> V_278 ) ;
if ( V_7 -> V_222 && V_100 )
V_7 -> V_87 [ 0 ] = V_88 ;
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; V_55 ++ )
if ( F_85 ( V_7 , V_55 + 1 ) < 0 )
F_28 ( V_7 -> V_112 ,
L_68 , V_55 + 1 ) ;
F_68 ( V_7 , V_202 ) ;
return 0 ;
V_242:
F_28 ( V_237 , L_69 ,
V_241 , V_56 ) ;
return V_56 ;
}
static void F_104 ( struct V_279 * V_279 )
{
struct V_6 * V_7 = F_22 ( V_279 , struct V_6 , V_279 ) ;
F_105 ( F_36 ( V_7 -> V_112 ) ) ;
F_48 ( V_7 ) ;
}
static void F_106 ( struct V_188 * V_189 )
{
struct V_6 * V_7 = F_4 ( V_189 ) ;
struct V_1 * V_2 = F_107 ( V_189 ) ;
int V_55 ;
F_108 ( & V_118 ) ;
if ( ! F_33 ( & V_7 -> V_120 ) ) {
F_109 ( & V_7 -> V_120 ) ;
F_110 ( V_189 ) ;
}
V_7 -> V_119 = 1 ;
F_111 ( & V_118 ) ;
V_7 -> error = 0 ;
F_74 ( V_7 , V_280 ) ;
F_112 ( V_189 , NULL ) ;
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; V_55 ++ )
F_83 ( V_7 , V_55 + 1 ) ;
V_7 -> V_2 -> V_12 = 0 ;
if ( V_7 -> V_2 -> V_15 == V_16 )
V_281 -- ;
F_113 ( V_7 -> V_125 ) ;
F_48 ( V_7 -> V_183 ) ;
F_48 ( V_7 -> V_3 ) ;
F_48 ( V_7 -> V_75 ) ;
F_48 ( V_7 -> V_134 ) ;
F_114 ( & V_7 -> V_279 , F_104 ) ;
}
static int F_115 ( struct V_188 * V_189 , const struct V_282 * V_283 )
{
struct V_284 * V_273 ;
struct V_235 * V_236 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
V_273 = V_189 -> V_285 ;
V_2 = F_107 ( V_189 ) ;
F_116 ( & V_2 -> V_22 , 0 ) ;
F_117 ( V_2 ) ;
if ( V_2 -> V_200 == V_286 ) {
F_28 ( & V_189 -> V_22 ,
L_70 ) ;
return - V_287 ;
}
#ifdef F_118
if ( V_2 -> V_23 ) {
F_7 ( & V_189 -> V_22 , L_71 ) ;
return - V_137 ;
}
#endif
if ( ( V_273 -> V_273 . V_288 != 0 ) &&
( V_273 -> V_273 . V_288 != 1 ) ) {
V_289:
F_28 ( & V_189 -> V_22 , L_72 ) ;
return - V_114 ;
}
if ( V_273 -> V_273 . V_290 != 1 )
goto V_289;
V_236 = & V_273 -> V_236 [ 0 ] . V_273 ;
if ( ! F_119 ( V_236 ) )
goto V_289;
F_92 ( & V_189 -> V_22 , L_73 ) ;
V_7 = F_86 ( sizeof( * V_7 ) , V_232 ) ;
if ( ! V_7 ) {
F_20 ( & V_189 -> V_22 , L_74 ) ;
return - V_157 ;
}
F_120 ( & V_7 -> V_279 ) ;
F_94 ( & V_7 -> V_120 ) ;
V_7 -> V_112 = & V_189 -> V_22 ;
V_7 -> V_2 = V_2 ;
F_121 ( & V_7 -> V_79 , F_21 ) ;
F_121 ( & V_7 -> V_203 , NULL ) ;
F_122 ( V_189 ) ;
F_112 ( V_189 , V_7 ) ;
V_189 -> V_291 = 1 ;
if ( V_2 -> V_15 == V_16 )
V_281 ++ ;
if ( V_283 -> V_292 & V_293 )
V_7 -> V_294 = 1 ;
if ( F_90 ( V_7 , V_236 ) >= 0 )
return 0 ;
F_106 ( V_189 ) ;
return - V_137 ;
}
static int
F_123 ( struct V_188 * V_189 , unsigned int V_295 , void * V_296 )
{
struct V_1 * V_2 = F_107 ( V_189 ) ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
switch ( V_295 ) {
case V_297 : {
struct V_298 * V_299 = V_296 ;
int V_55 ;
F_108 ( & V_300 ) ;
if ( V_2 -> V_160 <= 0 )
V_299 -> V_301 = 0 ;
else {
V_299 -> V_301 = V_2 -> V_12 ;
for ( V_55 = 0 ; V_55 < V_299 -> V_301 ; V_55 ++ ) {
if ( V_7 -> V_183 [ V_55 ] -> V_184 == NULL )
V_299 -> V_111 [ V_55 ] = 0 ;
else
V_299 -> V_111 [ V_55 ] =
V_7 -> V_183 [ V_55 ] -> V_184 -> V_160 ;
}
}
F_111 ( & V_300 ) ;
return V_299 -> V_301 + 1 ;
}
default:
return - V_302 ;
}
}
static int F_124 ( struct V_1 * V_2 , unsigned V_71 ,
struct V_303 * * * V_304 )
{
if ( V_2 -> V_82 == V_185 )
return - V_137 ;
if ( V_71 == 0 || V_71 > V_2 -> V_12 )
return - V_68 ;
* V_304 = & ( F_3 ( V_2 ) -> V_183 [ V_71 - 1 ] -> V_305 ) ;
return 0 ;
}
int F_125 ( struct V_1 * V_2 , unsigned V_71 ,
struct V_303 * V_306 )
{
int V_307 ;
struct V_303 * * V_308 ;
V_307 = F_124 ( V_2 , V_71 , & V_308 ) ;
if ( V_307 )
return V_307 ;
if ( * V_308 )
return - V_309 ;
* V_308 = V_306 ;
return V_307 ;
}
int F_126 ( struct V_1 * V_2 , unsigned V_71 ,
struct V_303 * V_306 )
{
int V_307 ;
struct V_303 * * V_308 ;
V_307 = F_124 ( V_2 , V_71 , & V_308 ) ;
if ( V_307 )
return V_307 ;
if ( * V_308 != V_306 )
return - V_128 ;
* V_308 = NULL ;
return V_307 ;
}
void F_127 ( struct V_1 * V_2 , struct V_303 * V_306 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
int V_310 ;
for ( V_310 = 0 ; V_310 < V_2 -> V_12 ; V_310 ++ ) {
if ( V_7 -> V_183 [ V_310 ] -> V_305 == V_306 )
V_7 -> V_183 [ V_310 ] -> V_305 = NULL ;
}
}
bool F_128 ( struct V_1 * V_14 )
{
struct V_6 * V_7 ;
if ( V_14 -> V_82 == V_185 || ! V_14 -> V_23 )
return false ;
V_7 = F_3 ( V_14 -> V_23 ) ;
return ! ! V_7 -> V_183 [ V_14 -> V_123 - 1 ] -> V_305 ;
}
static void F_129 ( struct V_1 * V_14 )
{
struct V_6 * V_7 = F_3 ( V_14 ) ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_14 -> V_12 ; ++ V_55 ) {
if ( V_7 -> V_183 [ V_55 ] -> V_184 )
F_129 ( V_7 -> V_183 [ V_55 ] -> V_184 ) ;
}
if ( V_14 -> V_82 == V_311 )
V_14 -> V_312 -= V_313 ;
V_14 -> V_82 = V_185 ;
}
void F_63 ( struct V_1 * V_14 ,
enum V_314 V_315 )
{
unsigned long V_117 ;
int V_316 = - 1 ;
F_32 ( & V_300 , V_117 ) ;
if ( V_14 -> V_82 == V_185 )
;
else if ( V_315 != V_185 ) {
if ( V_14 -> V_23 ) {
if ( V_14 -> V_82 == V_311
|| V_315 == V_311 )
;
else if ( V_315 == V_83 )
V_316 = V_14 -> V_11 -> V_273 . V_20
& V_317 ;
else
V_316 = 0 ;
}
if ( V_14 -> V_82 == V_311 &&
V_315 != V_311 )
V_14 -> V_312 -= V_313 ;
else if ( V_315 == V_311 &&
V_14 -> V_82 != V_311 )
V_14 -> V_312 += V_313 ;
V_14 -> V_82 = V_315 ;
} else
F_129 ( V_14 ) ;
F_38 ( & V_300 , V_117 ) ;
if ( V_316 >= 0 )
F_130 ( & V_14 -> V_22 , V_316 ) ;
}
static void F_131 ( struct V_1 * V_14 )
{
int V_160 ;
struct V_318 * V_163 = V_14 -> V_163 ;
if ( V_14 -> V_319 ) {
V_160 = V_14 -> V_123 + 1 ;
F_132 ( F_133 ( V_160 , V_163 -> V_320 . V_321 ) ) ;
} else {
V_160 = F_134 ( V_163 -> V_320 . V_321 , 128 ,
V_163 -> V_322 ) ;
if ( V_160 >= 128 )
V_160 = F_134 ( V_163 -> V_320 . V_321 ,
128 , 1 ) ;
V_163 -> V_322 = ( V_160 >= 127 ? 1 : V_160 + 1 ) ;
}
if ( V_160 < 128 ) {
F_41 ( V_160 , V_163 -> V_320 . V_321 ) ;
V_14 -> V_160 = V_160 ;
}
}
static void F_135 ( struct V_1 * V_14 )
{
if ( V_14 -> V_160 > 0 ) {
F_71 ( V_14 -> V_160 , V_14 -> V_163 -> V_320 . V_321 ) ;
V_14 -> V_160 = - 1 ;
}
}
static void F_136 ( struct V_1 * V_14 , int V_160 )
{
if ( ! V_14 -> V_319 )
V_14 -> V_160 = V_160 ;
}
static void F_137 ( struct V_1 * V_14 )
{
struct V_192 * V_151 = F_54 ( V_14 -> V_163 ) ;
if ( V_151 -> V_152 -> V_323 && V_14 -> V_23 )
V_151 -> V_152 -> V_323 ( V_151 , V_14 ) ;
}
void F_76 ( struct V_1 * * V_324 )
{
struct V_1 * V_14 = * V_324 ;
struct V_6 * V_7 = F_3 ( V_14 ) ;
int V_55 ;
F_63 ( V_14 , V_185 ) ;
F_92 ( & V_14 -> V_22 , L_75 ,
V_14 -> V_160 ) ;
F_138 ( V_14 ) ;
for ( V_55 = 0 ; V_55 < V_14 -> V_12 ; V_55 ++ ) {
if ( V_7 -> V_183 [ V_55 ] -> V_184 )
F_76 ( & V_7 -> V_183 [ V_55 ] -> V_184 ) ;
}
F_20 ( & V_14 -> V_22 , L_76 ) ;
F_139 ( V_14 , 0 ) ;
F_140 ( V_14 ) ;
F_141 ( & V_14 -> V_325 ) ;
F_142 ( V_14 ) ;
F_143 ( & V_14 -> V_22 ) ;
F_135 ( V_14 ) ;
F_108 ( & V_300 ) ;
* V_324 = NULL ;
F_111 ( & V_300 ) ;
F_137 ( V_14 ) ;
F_89 ( & V_14 -> V_22 ) ;
}
static void F_144 ( struct V_1 * V_14 , char * V_283 , char * string )
{
if ( ! string )
return;
F_92 ( & V_14 -> V_22 , L_77 , V_283 , string ) ;
}
static void F_145 ( struct V_1 * V_14 )
{
F_92 ( & V_14 -> V_22 , L_78 ,
F_29 ( V_14 -> V_3 . V_326 ) ,
F_29 ( V_14 -> V_3 . V_327 ) ) ;
F_92 ( & V_14 -> V_22 ,
L_79 ,
V_14 -> V_3 . V_328 ,
V_14 -> V_3 . V_329 ,
V_14 -> V_3 . V_330 ) ;
F_144 ( V_14 , L_80 , V_14 -> V_331 ) ;
F_144 ( V_14 , L_81 , V_14 -> V_332 ) ;
F_144 ( V_14 , L_82 , V_14 -> V_333 ) ;
}
static inline void F_145 ( struct V_1 * V_14 ) { }
static int F_146 ( struct V_1 * V_14 )
{
int V_334 = 0 ;
#ifdef F_147
if ( ! V_14 -> V_163 -> V_335
&& V_14 -> V_336
&& V_14 -> V_23 == V_14 -> V_163 -> V_266 ) {
struct V_337 * V_273 = NULL ;
struct V_318 * V_163 = V_14 -> V_163 ;
if ( F_148 ( V_14 -> V_338 [ 0 ] ,
F_29 ( V_14 -> V_336 [ 0 ] . V_273 . V_339 ) ,
V_340 , ( void * * ) & V_273 ) == 0 ) {
if ( V_273 -> V_20 & V_341 ) {
unsigned V_71 = V_14 -> V_123 ;
F_92 ( & V_14 -> V_22 ,
L_83 ,
( V_71 == V_163 -> V_342 )
? L_39 : L_84 ) ;
if ( V_71 == V_163 -> V_342 )
V_163 -> V_343 = 1 ;
V_334 = F_13 ( V_14 ,
F_16 ( V_14 , 0 ) ,
V_73 , 0 ,
V_163 -> V_343
? V_344
: V_345 ,
0 , NULL , 0 , V_201 ) ;
if ( V_334 < 0 ) {
F_92 ( & V_14 -> V_22 ,
L_85 ,
V_334 ) ;
V_163 -> V_343 = 0 ;
}
}
}
}
if ( ! F_149 ( V_14 ) ) {
if ( V_14 -> V_163 -> V_343 || V_14 -> V_163 -> V_335 ) {
V_334 = F_150 ( V_14 , V_346 ) ;
if ( V_334 < 0 )
F_20 ( & V_14 -> V_22 , L_86 , V_334 ) ;
}
V_334 = - V_347 ;
goto V_242;
}
V_242:
#endif
return V_334 ;
}
static int F_151 ( struct V_1 * V_14 )
{
int V_334 ;
if ( V_14 -> V_336 == NULL ) {
V_334 = F_152 ( V_14 ) ;
if ( V_334 < 0 ) {
F_28 ( & V_14 -> V_22 , L_87 ,
V_334 ) ;
return V_334 ;
}
}
if ( V_14 -> V_319 == 1 && V_14 -> V_348 == 0 ) {
V_14 -> V_331 = F_153 ( L_88 , V_232 ) ;
V_14 -> V_332 = F_153 ( L_88 , V_232 ) ;
V_14 -> V_333 = F_153 ( L_88 , V_232 ) ;
}
else {
V_14 -> V_331 = F_154 ( V_14 , V_14 -> V_3 . V_329 ) ;
V_14 -> V_332 = F_154 ( V_14 ,
V_14 -> V_3 . V_328 ) ;
V_14 -> V_333 = F_154 ( V_14 , V_14 -> V_3 . V_330 ) ;
}
V_334 = F_146 ( V_14 ) ;
if ( V_334 < 0 )
return V_334 ;
F_155 ( V_14 ) ;
return 0 ;
}
static void F_156 ( struct V_1 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_23 ;
struct V_6 * V_7 ;
T_2 V_111 = V_14 -> V_123 ;
T_1 V_168 ;
bool V_349 = true ;
if ( ! V_2 )
return;
V_7 = F_3 ( V_14 -> V_23 ) ;
V_168 = F_29 ( V_7 -> V_3 -> V_168 ) ;
if ( ! ( V_168 & V_244 ) )
return;
if ( F_1 ( V_2 ) ) {
if ( F_29 ( V_7 -> V_3 -> V_34 . V_35 . V_247 )
& ( 1 << V_111 ) )
V_349 = false ;
} else {
if ( V_7 -> V_3 -> V_34 . V_246 . V_247 [ V_111 / 8 ] & ( 1 << ( V_111 % 8 ) ) )
V_349 = false ;
}
if ( V_349 )
V_14 -> V_349 = V_350 ;
else
V_14 -> V_349 = V_351 ;
}
int F_157 ( struct V_1 * V_14 )
{
int V_334 ;
if ( V_14 -> V_23 ) {
F_158 ( & V_14 -> V_22 , 0 ) ;
}
F_159 ( & V_14 -> V_22 ) ;
F_160 ( & V_14 -> V_22 ) ;
F_161 ( & V_14 -> V_22 ) ;
F_162 ( & V_14 -> V_22 ) ;
F_163 ( V_14 ) ;
V_334 = F_151 ( V_14 ) ;
if ( V_334 < 0 )
goto V_242;
F_20 ( & V_14 -> V_22 , L_89 ,
V_14 -> V_160 , V_14 -> V_163 -> V_352 ,
( ( ( V_14 -> V_163 -> V_352 - 1 ) * 128 ) + ( V_14 -> V_160 - 1 ) ) ) ;
V_14 -> V_22 . V_353 = F_164 ( V_354 ,
( ( ( V_14 -> V_163 -> V_352 - 1 ) * 128 ) + ( V_14 -> V_160 - 1 ) ) ) ;
F_145 ( V_14 ) ;
if ( V_14 -> V_333 )
F_165 ( V_14 -> V_333 , strlen ( V_14 -> V_333 ) ) ;
if ( V_14 -> V_331 )
F_165 ( V_14 -> V_331 , strlen ( V_14 -> V_331 ) ) ;
if ( V_14 -> V_332 )
F_165 ( V_14 -> V_332 ,
strlen ( V_14 -> V_332 ) ) ;
F_166 ( & V_14 -> V_22 ) ;
if ( V_14 -> V_23 )
F_156 ( V_14 ) ;
V_334 = F_167 ( & V_14 -> V_22 ) ;
if ( V_334 ) {
F_28 ( & V_14 -> V_22 , L_90 , V_334 ) ;
goto V_242;
}
( void ) F_168 ( & V_14 -> V_22 , & V_14 -> V_325 , V_14 ) ;
F_169 ( V_14 ) ;
F_170 ( & V_14 -> V_22 ) ;
return V_334 ;
V_242:
F_63 ( V_14 , V_185 ) ;
F_171 ( & V_14 -> V_22 ) ;
F_172 ( & V_14 -> V_22 ) ;
return V_334 ;
}
int F_173 ( struct V_1 * V_355 )
{
F_138 ( V_355 ) ;
if ( V_355 -> V_348 == 0 )
goto V_356;
V_355 -> V_348 = 0 ;
F_174 ( V_355 , - 1 ) ;
F_48 ( V_355 -> V_331 ) ;
V_355 -> V_331 = F_153 ( L_88 , V_232 ) ;
F_48 ( V_355 -> V_332 ) ;
V_355 -> V_332 = F_153 ( L_88 , V_232 ) ;
F_48 ( V_355 -> V_333 ) ;
V_355 -> V_333 = F_153 ( L_88 , V_232 ) ;
F_175 ( V_355 ) ;
V_355 -> V_3 . V_357 = 0 ;
V_356:
F_142 ( V_355 ) ;
return 0 ;
}
int F_176 ( struct V_1 * V_355 )
{
int V_358 = 0 , V_359 ;
F_138 ( V_355 ) ;
if ( V_355 -> V_348 == 1 )
goto V_360;
V_358 = F_177 ( V_355 ) ;
if ( V_358 < 0 ) {
F_28 ( & V_355 -> V_22 ,
L_91 , V_358 ) ;
goto V_361;
}
V_358 = F_178 ( V_355 , sizeof( V_355 -> V_3 ) ) ;
if ( V_358 < 0 ) {
F_28 ( & V_355 -> V_22 , L_92
L_93 , V_358 ) ;
goto V_362;
}
F_48 ( V_355 -> V_331 ) ;
V_355 -> V_331 = NULL ;
F_48 ( V_355 -> V_332 ) ;
V_355 -> V_332 = NULL ;
F_48 ( V_355 -> V_333 ) ;
V_355 -> V_333 = NULL ;
V_355 -> V_348 = 1 ;
V_358 = F_151 ( V_355 ) ;
if ( V_358 < 0 )
goto V_363;
V_359 = F_179 ( V_355 ) ;
if ( V_359 >= 0 ) {
V_358 = F_174 ( V_355 , V_359 ) ;
if ( V_358 ) {
F_28 ( & V_355 -> V_22 ,
L_94 , V_359 , V_358 ) ;
}
}
F_92 ( & V_355 -> V_22 , L_95 ) ;
V_363:
V_362:
F_180 ( V_355 ) ;
V_361:
V_360:
F_142 ( V_355 ) ;
return V_358 ;
}
static unsigned F_181 ( struct V_6 * V_7 )
{
struct V_192 * V_151 ;
if ( V_7 -> V_2 -> V_23 != NULL )
return 0 ;
V_151 = F_22 ( V_7 -> V_2 -> V_163 , struct V_192 , V_364 ) ;
return V_151 -> V_365 ;
}
static bool F_182 ( struct V_6 * V_7 , T_1 V_8 )
{
return F_1 ( V_7 -> V_2 ) &&
( ( ( V_8 & V_179 ) ==
V_366 ) ||
( ( V_8 & V_179 ) ==
V_367 ) ) ;
}
static int F_183 ( struct V_6 * V_7 , int V_71 ,
struct V_1 * V_14 , unsigned int V_167 , bool V_368 )
{
int V_369 , V_56 ;
T_1 V_8 ;
T_1 V_176 ;
for ( V_369 = 0 ;
V_369 < V_370 ;
V_369 += V_167 ) {
F_58 ( V_167 ) ;
V_56 = F_26 ( V_7 , V_71 , & V_8 , & V_176 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( ( V_8 & V_371 ) )
goto V_167;
if ( ! V_368 ) {
if ( F_182 ( V_7 , V_8 ) ) {
int V_56 ;
if ( ( V_176 & V_210 ) )
F_17 ( V_7 -> V_2 , V_71 ,
V_211 ) ;
if ( V_176 & V_372 )
F_17 ( V_7 -> V_2 , V_71 ,
V_373 ) ;
if ( V_176 & V_374 )
F_17 ( V_7 -> V_2 , V_71 ,
V_375 ) ;
F_20 ( V_7 -> V_112 , L_96 ,
V_71 ) ;
V_56 = F_184 ( V_7 , V_71 ,
V_14 , V_376 ,
true ) ;
if ( ( V_176 & V_210 ) )
F_17 ( V_7 -> V_2 , V_71 ,
V_211 ) ;
return V_56 ;
}
if ( ! ( V_8 & V_208 ) )
return - V_377 ;
if ( ( V_176 & V_210 ) )
return - V_377 ;
if ( ( V_8 & V_209 ) ) {
if ( F_181 ( V_7 ) )
V_14 -> V_15 = V_378 ;
else if ( F_1 ( V_7 -> V_2 ) )
V_14 -> V_15 = V_49 ;
else if ( V_8 & V_9 )
V_14 -> V_15 = V_16 ;
else if ( V_8 & V_10 )
V_14 -> V_15 = V_379 ;
else
V_14 -> V_15 = V_380 ;
return 0 ;
}
} else {
if ( ! ( V_8 & V_208 ) ||
F_182 ( V_7 ,
V_8 ) )
return - V_377 ;
return 0 ;
}
V_167:
if ( V_369 >= 2 * V_381 )
V_167 = V_382 ;
F_20 ( V_7 -> V_112 ,
L_97 ,
V_71 , V_368 ? L_98 : L_39 , V_167 ) ;
}
return - V_309 ;
}
static void F_185 ( struct V_6 * V_7 , int V_71 ,
struct V_1 * V_14 , int * V_75 , bool V_368 )
{
switch ( * V_75 ) {
case 0 :
if ( ! V_368 ) {
struct V_192 * V_151 ;
F_58 ( 10 + 40 ) ;
F_136 ( V_14 , 0 ) ;
V_151 = F_54 ( V_14 -> V_163 ) ;
if ( V_151 -> V_152 -> V_383 )
V_151 -> V_152 -> V_383 ( V_151 , V_14 ) ;
}
case - V_377 :
case - V_137 :
F_17 ( V_7 -> V_2 ,
V_71 , V_375 ) ;
if ( F_1 ( V_7 -> V_2 ) ) {
F_17 ( V_7 -> V_2 , V_71 ,
V_215 ) ;
F_17 ( V_7 -> V_2 , V_71 ,
V_373 ) ;
}
if ( ! V_368 )
F_63 ( V_14 , * V_75
? V_185
: V_384 ) ;
break;
}
}
static int F_184 ( struct V_6 * V_7 , int V_71 ,
struct V_1 * V_14 , unsigned int V_167 , bool V_368 )
{
int V_55 , V_75 ;
if ( ! V_368 ) {
F_186 ( & V_385 ) ;
} else {
if ( ! F_1 ( V_7 -> V_2 ) ) {
F_28 ( V_7 -> V_112 , L_99
L_100 ) ;
return - V_68 ;
}
}
for ( V_55 = 0 ; V_55 < V_386 ; V_55 ++ ) {
V_75 = F_18 ( V_7 -> V_2 , V_71 , ( V_368 ?
V_387 :
V_388 ) ) ;
if ( V_75 ) {
F_28 ( V_7 -> V_112 ,
L_101 ,
V_368 ? L_98 : L_39 , V_71 , V_75 ) ;
} else {
V_75 = F_183 ( V_7 , V_71 , V_14 , V_167 ,
V_368 ) ;
if ( V_75 && V_75 != - V_377 )
F_20 ( V_7 -> V_112 ,
L_102 ,
V_75 ) ;
}
if ( V_75 == 0 || V_75 == - V_377 || V_75 == - V_137 ) {
F_185 ( V_7 , V_71 , V_14 , & V_75 , V_368 ) ;
goto V_389;
}
F_20 ( V_7 -> V_112 ,
L_103 ,
V_71 , V_368 ? L_98 : L_39 ) ;
V_167 = V_382 ;
}
F_28 ( V_7 -> V_112 ,
L_104 ,
V_71 ) ;
V_389:
if ( ! V_368 )
F_187 ( & V_385 ) ;
return V_75 ;
}
static int F_188 ( struct V_6 * V_7 , unsigned V_8 )
{
int V_56 = 0 ;
if ( F_1 ( V_7 -> V_2 ) ) {
if ( V_8 & V_390 )
V_56 = 1 ;
} else {
if ( V_8 & V_391 )
V_56 = 1 ;
}
return V_56 ;
}
static int F_189 ( struct V_6 * V_7 , unsigned V_8 )
{
int V_56 = 0 ;
if ( F_1 ( V_7 -> V_2 ) ) {
if ( ( V_8 & V_179 )
== V_392 )
V_56 = 1 ;
} else {
if ( V_8 & V_393 )
V_56 = 1 ;
}
return V_56 ;
}
static int F_190 ( struct V_1 * V_14 ,
struct V_6 * V_7 , int V_71 ,
int V_75 , unsigned V_176 , unsigned V_8 )
{
if ( V_75 || F_189 ( V_7 , V_8 ) ||
! F_188 ( V_7 , V_8 ) ||
! ( V_8 & V_208 ) ) {
if ( V_75 >= 0 )
V_75 = - V_137 ;
}
else if ( ! ( V_8 & V_209 ) && ! V_14 -> V_219 ) {
if ( V_14 -> V_218 )
V_14 -> V_219 = 1 ;
else
V_75 = - V_137 ;
}
if ( V_75 ) {
F_20 ( V_7 -> V_112 ,
L_105 ,
V_71 , V_176 , V_8 , V_75 ) ;
} else if ( V_14 -> V_219 ) {
if ( V_176 & V_210 )
F_17 ( V_7 -> V_2 , V_71 ,
V_211 ) ;
if ( V_176 & V_212 )
F_17 ( V_7 -> V_2 , V_71 ,
V_213 ) ;
}
return V_75 ;
}
int F_191 ( struct V_1 * V_14 )
{
struct V_192 * V_151 = F_54 ( V_14 -> V_163 ) ;
if ( ! F_192 ( V_151 -> V_364 . V_266 ) ||
! F_192 ( V_14 ) )
return 0 ;
if ( ! V_14 -> V_11 )
return 0 ;
return F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_70 , V_265 ,
V_394 , 0 , NULL , 0 ,
V_201 ) ;
}
void F_193 ( struct V_1 * V_14 )
{
struct V_192 * V_151 = F_54 ( V_14 -> V_163 ) ;
if ( ! F_192 ( V_151 -> V_364 . V_266 ) ||
! F_192 ( V_14 ) )
return;
if ( ! V_14 -> V_11 )
return;
F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_73 , V_265 ,
V_394 , 0 , NULL , 0 ,
V_201 ) ;
}
static int F_194 ( struct V_1 * V_14 )
{
return F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_70 , V_395 ,
V_396 , 0 , NULL , 0 ,
V_201 ) ;
}
int F_150 ( struct V_1 * V_14 , T_3 V_397 )
{
struct V_6 * V_7 = F_3 ( V_14 -> V_23 ) ;
int V_71 = V_14 -> V_123 ;
int V_75 ;
if ( V_14 -> V_398 ) {
if ( ! F_1 ( V_7 -> V_2 ) ) {
V_75 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_73 , V_265 ,
V_399 , 0 ,
NULL , 0 ,
V_201 ) ;
} else {
V_75 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_73 ,
V_395 ,
V_396 ,
V_400 |
V_401 ,
NULL , 0 ,
V_201 ) ;
}
if ( V_75 ) {
F_20 ( & V_14 -> V_22 , L_106 ,
V_75 ) ;
if ( F_195 ( V_397 ) )
return V_75 ;
}
}
if ( V_14 -> V_402 == 1 )
F_196 ( V_14 , 0 ) ;
if ( F_191 ( V_14 ) ) {
F_28 ( & V_14 -> V_22 , L_107 ,
V_113 ) ;
return - V_157 ;
}
if ( F_197 ( V_14 ) ) {
F_28 ( & V_14 -> V_22 , L_108 ,
V_113 ) ;
return - V_157 ;
}
if ( F_1 ( V_7 -> V_2 ) )
V_75 = F_18 ( V_7 -> V_2 ,
V_71 | ( V_392 << 3 ) ,
V_174 ) ;
else
V_75 = F_18 ( V_7 -> V_2 , V_71 ,
V_403 ) ;
if ( V_75 ) {
F_20 ( V_7 -> V_112 , L_109 ,
V_71 , V_75 ) ;
if ( V_14 -> V_398 ) {
if ( ! F_1 ( V_7 -> V_2 ) ) {
( void ) F_13 ( V_14 ,
F_16 ( V_14 , 0 ) ,
V_70 ,
V_265 ,
V_399 , 0 ,
NULL , 0 ,
V_201 ) ;
} else
( void ) F_194 ( V_14 ) ;
}
if ( V_14 -> V_404 == 1 )
F_196 ( V_14 , 1 ) ;
F_193 ( V_14 ) ;
F_198 ( V_14 ) ;
if ( ! F_195 ( V_397 ) )
V_75 = 0 ;
} else {
F_20 ( & V_14 -> V_22 , L_110 ,
( F_195 ( V_397 ) ? L_111 : L_39 ) ,
V_14 -> V_398 ) ;
F_63 ( V_14 , V_311 ) ;
V_14 -> F_189 = 1 ;
F_58 ( 10 ) ;
}
F_169 ( V_7 -> V_2 ) ;
return V_75 ;
}
static int F_199 ( struct V_1 * V_14 )
{
int V_75 = 0 ;
T_1 V_405 = 0 ;
F_20 ( & V_14 -> V_22 , L_112 ,
V_14 -> V_219 ? L_113 : L_114 ) ;
F_63 ( V_14 , V_14 -> V_11
? V_83
: V_406 ) ;
if ( V_14 -> V_219 )
V_407:
V_75 = F_200 ( V_14 ) ;
if ( V_75 == 0 ) {
V_405 = 0 ;
V_75 = F_97 ( V_14 , V_265 , 0 , & V_405 ) ;
if ( V_75 >= 0 )
V_75 = ( V_75 > 0 ? 0 : - V_137 ) ;
if ( V_75 && ! V_14 -> V_219 && V_14 -> V_218 ) {
F_20 ( & V_14 -> V_22 , L_115 ) ;
V_14 -> V_219 = 1 ;
goto V_407;
}
}
if ( V_75 ) {
F_20 ( & V_14 -> V_22 , L_116 ,
V_75 ) ;
} else if ( V_14 -> V_11 && ! V_14 -> V_219 ) {
if ( ! F_1 ( V_14 -> V_23 ) ) {
F_98 ( & V_405 ) ;
if ( V_405 & ( 1 << V_399 ) )
V_75 = F_13 ( V_14 ,
F_16 ( V_14 , 0 ) ,
V_70 ,
V_265 ,
V_399 , 0 ,
NULL , 0 ,
V_201 ) ;
} else {
V_75 = F_97 ( V_14 , V_395 , 0 ,
& V_405 ) ;
F_98 ( & V_405 ) ;
if ( ! V_75 && V_405 & ( V_408
| V_409 ) )
V_75 =
F_194 ( V_14 ) ;
}
if ( V_75 )
F_20 ( & V_14 -> V_22 ,
L_117 ,
V_75 ) ;
V_75 = 0 ;
}
return V_75 ;
}
int F_201 ( struct V_1 * V_14 , T_3 V_397 )
{
struct V_6 * V_7 = F_3 ( V_14 -> V_23 ) ;
int V_71 = V_14 -> V_123 ;
int V_75 ;
T_1 V_176 , V_8 ;
V_75 = F_26 ( V_7 , V_71 , & V_8 , & V_176 ) ;
if ( V_75 == 0 && ! F_189 ( V_7 , V_8 ) )
goto V_410;
F_41 ( V_71 , V_7 -> V_411 ) ;
if ( F_1 ( V_7 -> V_2 ) )
V_75 = F_18 ( V_7 -> V_2 ,
V_71 | ( V_217 << 3 ) ,
V_174 ) ;
else
V_75 = F_17 ( V_7 -> V_2 ,
V_71 , V_403 ) ;
if ( V_75 ) {
F_20 ( V_7 -> V_112 , L_118 ,
V_71 , V_75 ) ;
} else {
F_20 ( & V_14 -> V_22 , L_119 ,
( F_195 ( V_397 ) ? L_111 : L_39 ) ) ;
F_58 ( 25 ) ;
V_75 = F_26 ( V_7 , V_71 , & V_8 , & V_176 ) ;
F_58 ( 10 ) ;
}
V_410:
if ( V_75 == 0 ) {
V_14 -> F_189 = 0 ;
if ( F_1 ( V_7 -> V_2 ) ) {
if ( V_176 & V_372 )
F_17 ( V_7 -> V_2 , V_71 ,
V_373 ) ;
} else {
if ( V_176 & V_412 )
F_17 ( V_7 -> V_2 , V_71 ,
V_413 ) ;
}
}
F_71 ( V_71 , V_7 -> V_411 ) ;
V_75 = F_190 ( V_14 ,
V_7 , V_71 , V_75 , V_176 , V_8 ) ;
if ( V_75 == 0 )
V_75 = F_199 ( V_14 ) ;
if ( V_75 < 0 ) {
F_20 ( & V_14 -> V_22 , L_120 , V_75 ) ;
F_64 ( V_7 , V_71 ) ;
} else {
if ( V_14 -> V_404 == 1 )
F_196 ( V_14 , 1 ) ;
F_193 ( V_14 ) ;
F_198 ( V_14 ) ;
}
return V_75 ;
}
int F_202 ( struct V_1 * V_14 )
{
int V_75 = 0 ;
if ( V_14 -> V_82 == V_311 ) {
F_20 ( & V_14 -> V_22 , L_119 , L_121 ) ;
V_75 = F_177 ( V_14 ) ;
if ( V_75 == 0 ) {
F_180 ( V_14 ) ;
}
}
return V_75 ;
}
int F_150 ( struct V_1 * V_14 , T_3 V_397 )
{
return 0 ;
}
int F_201 ( struct V_1 * V_14 , T_3 V_397 )
{
struct V_6 * V_7 = F_3 ( V_14 -> V_23 ) ;
int V_71 = V_14 -> V_123 ;
int V_75 ;
T_1 V_176 , V_8 ;
V_75 = F_26 ( V_7 , V_71 , & V_8 , & V_176 ) ;
V_75 = F_190 ( V_14 ,
V_7 , V_71 , V_75 , V_176 , V_8 ) ;
if ( V_75 ) {
F_20 ( & V_14 -> V_22 , L_120 , V_75 ) ;
F_64 ( V_7 , V_71 ) ;
} else if ( V_14 -> V_219 ) {
F_20 ( & V_14 -> V_22 , L_122 ) ;
V_75 = F_200 ( V_14 ) ;
}
return V_75 ;
}
static int F_203 ( struct V_6 * V_7 )
{
int V_71 ;
for ( V_71 = 1 ; V_71 <= V_7 -> V_2 -> V_12 ; ++ V_71 ) {
T_1 V_8 , V_176 ;
int V_75 ;
V_75 = F_26 ( V_7 , V_71 , & V_8 , & V_176 ) ;
if ( ! V_75 && V_176 )
return 1 ;
}
return 0 ;
}
static int F_204 ( struct V_188 * V_189 , T_3 V_397 )
{
struct V_6 * V_7 = F_4 ( V_189 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
unsigned V_71 ;
int V_75 ;
for ( V_71 = 1 ; V_71 <= V_2 -> V_12 ; V_71 ++ ) {
struct V_1 * V_14 ;
V_14 = V_7 -> V_183 [ V_71 - 1 ] -> V_184 ;
if ( V_14 && V_14 -> V_414 ) {
F_7 ( & V_189 -> V_22 , L_123 , V_71 ) ;
if ( F_195 ( V_397 ) )
return - V_309 ;
}
}
if ( V_2 -> V_398 && V_7 -> V_294 ) {
if ( F_203 ( V_7 ) ) {
if ( F_195 ( V_397 ) )
return - V_309 ;
F_205 ( & V_2 -> V_22 , 2000 ) ;
}
}
if ( F_1 ( V_2 ) && V_2 -> V_398 ) {
for ( V_71 = 1 ; V_71 <= V_2 -> V_12 ; V_71 ++ ) {
V_75 = F_18 ( V_2 ,
V_71 |
V_415 |
V_416 |
V_417 ,
V_418 ) ;
}
}
F_20 ( & V_189 -> V_22 , L_112 , V_113 ) ;
F_74 ( V_7 , V_225 ) ;
return 0 ;
}
static int F_206 ( struct V_188 * V_189 )
{
struct V_6 * V_7 = F_4 ( V_189 ) ;
F_20 ( & V_189 -> V_22 , L_112 , V_113 ) ;
F_68 ( V_7 , V_198 ) ;
return 0 ;
}
static int F_207 ( struct V_188 * V_189 )
{
struct V_6 * V_7 = F_4 ( V_189 ) ;
F_20 ( & V_189 -> V_22 , L_112 , V_113 ) ;
F_68 ( V_7 , V_205 ) ;
return 0 ;
}
void F_208 ( struct V_1 * V_419 )
{
F_7 ( & V_419 -> V_22 , L_124 ) ;
V_419 -> V_219 = 1 ;
}
static int F_209 ( struct V_1 * V_14 , enum V_420 V_82 )
{
struct V_421 * V_422 ;
unsigned long long V_423 ;
unsigned long long V_424 ;
unsigned long long V_425 ;
unsigned long long V_426 ;
int V_56 ;
V_423 = F_210 ( V_14 -> V_52 . V_43 , 1000 ) ;
V_424 = F_210 ( V_14 -> V_52 . V_40 , 1000 ) ;
V_425 = F_210 ( V_14 -> V_53 . V_43 , 1000 ) ;
V_426 = F_210 ( V_14 -> V_53 . V_40 , 1000 ) ;
if ( ( V_82 == V_427 &&
( V_423 > V_428 ||
V_424 > V_428 ) ) ||
( V_82 == V_429 &&
( V_425 > V_430 ||
V_426 > V_430 ) ) ) {
F_20 ( & V_14 -> V_22 , L_125 ,
V_431 [ V_82 ] , V_423 , V_424 ) ;
return - V_68 ;
}
if ( V_423 > V_428 )
V_423 = V_428 ;
if ( V_424 > V_428 )
V_424 = V_428 ;
if ( V_425 > V_430 )
V_425 = V_430 ;
if ( V_426 > V_430 )
V_426 = V_430 ;
V_422 = F_50 ( sizeof *( V_422 ) , V_207 ) ;
if ( ! V_422 )
return - V_157 ;
V_422 -> V_423 = V_423 ;
V_422 -> V_424 = V_424 ;
V_422 -> V_425 = F_211 ( V_425 ) ;
V_422 -> V_426 = F_211 ( V_426 ) ;
V_56 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_432 ,
V_265 ,
0 , 0 ,
V_422 , sizeof *( V_422 ) ,
V_201 ) ;
F_48 ( V_422 ) ;
return V_56 ;
}
static int F_212 ( struct V_1 * V_14 ,
enum V_420 V_82 , bool V_433 )
{
int V_56 ;
int V_69 ;
switch ( V_82 ) {
case V_427 :
V_69 = V_434 ;
break;
case V_429 :
V_69 = V_435 ;
break;
default:
F_7 ( & V_14 -> V_22 , L_126 ,
V_113 , V_433 ? L_127 : L_128 ) ;
return - V_68 ;
}
if ( V_14 -> V_82 != V_83 ) {
F_20 ( & V_14 -> V_22 , L_129
L_130 ,
V_113 , V_433 ? L_127 : L_128 ,
V_431 [ V_82 ] ) ;
return 0 ;
}
if ( V_433 ) {
V_56 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_73 ,
V_265 ,
V_69 ,
0 , NULL , 0 ,
V_201 ) ;
} else {
V_56 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_70 ,
V_265 ,
V_69 ,
0 , NULL , 0 ,
V_201 ) ;
}
if ( V_56 < 0 ) {
F_7 ( & V_14 -> V_22 , L_131 ,
V_433 ? L_132 : L_133 ,
V_431 [ V_82 ] ) ;
return - V_309 ;
}
return 0 ;
}
static int F_213 ( struct V_1 * V_14 ,
enum V_420 V_82 , int V_436 )
{
int V_56 ;
int V_69 ;
switch ( V_82 ) {
case V_427 :
V_69 = V_437 ;
break;
case V_429 :
V_69 = V_438 ;
break;
default:
F_7 ( & V_14 -> V_22 , L_134 ,
V_113 ) ;
return - V_68 ;
}
if ( V_82 == V_427 && V_436 > V_439 &&
V_436 != V_440 ) {
F_7 ( & V_14 -> V_22 , L_135
L_136 ,
V_431 [ V_82 ] , V_436 ) ;
return - V_68 ;
}
V_56 = F_18 ( V_14 -> V_23 ,
F_214 ( V_436 ) | V_14 -> V_123 ,
V_69 ) ;
if ( V_56 < 0 ) {
F_7 ( & V_14 -> V_22 , L_137
L_138 , V_431 [ V_82 ] ,
V_436 , V_56 ) ;
return - V_309 ;
}
if ( V_82 == V_427 )
V_14 -> V_52 . V_436 = V_436 ;
else
V_14 -> V_53 . V_436 = V_436 ;
return 0 ;
}
static void F_215 ( struct V_192 * V_151 , struct V_1 * V_14 ,
enum V_420 V_82 )
{
int V_436 , V_56 ;
T_4 V_441 = V_14 -> V_17 -> V_21 -> V_50 ;
T_5 V_442 = V_14 -> V_17 -> V_21 -> V_51 ;
if ( ( V_82 == V_427 && V_441 == 0 ) ||
( V_82 == V_429 && V_442 == 0 ) )
return;
V_56 = F_209 ( V_14 , V_82 ) ;
if ( V_56 < 0 ) {
F_7 ( & V_14 -> V_22 , L_139 ,
V_431 [ V_82 ] ) ;
return;
}
V_436 = V_151 -> V_152 -> V_443 ( V_151 , V_14 , V_82 ) ;
if ( V_436 == 0 )
return;
if ( V_436 < 0 ) {
F_7 ( & V_14 -> V_22 , L_140
L_141 , V_431 [ V_82 ] ,
V_436 ) ;
return;
}
if ( F_213 ( V_14 , V_82 , V_436 ) )
V_151 -> V_152 -> V_444 ( V_151 , V_14 , V_82 ) ;
else if ( V_14 -> V_11 )
F_212 ( V_14 , V_82 , true ) ;
}
static int F_216 ( struct V_192 * V_151 , struct V_1 * V_14 ,
enum V_420 V_82 )
{
int V_69 ;
switch ( V_82 ) {
case V_427 :
V_69 = V_437 ;
break;
case V_429 :
V_69 = V_438 ;
break;
default:
F_7 ( & V_14 -> V_22 , L_142 ,
V_113 ) ;
return - V_68 ;
}
if ( F_213 ( V_14 , V_82 , 0 ) )
return - V_309 ;
F_212 ( V_14 , V_82 , false ) ;
if ( V_151 -> V_152 -> V_444 ( V_151 , V_14 , V_82 ) )
F_7 ( & V_14 -> V_22 , L_143
L_144 ,
V_431 [ V_82 ] ) ;
return 0 ;
}
int F_217 ( struct V_1 * V_14 )
{
struct V_192 * V_151 ;
if ( ! V_14 || ! V_14 -> V_23 ||
V_14 -> V_15 != V_49 ||
! V_14 -> V_24 )
return 0 ;
V_151 = F_54 ( V_14 -> V_163 ) ;
if ( ! V_151 || ! V_151 -> V_152 -> V_444 )
return 0 ;
V_14 -> V_445 ++ ;
if ( ( V_14 -> V_52 . V_436 == 0 && V_14 -> V_53 . V_436 == 0 ) )
return 0 ;
if ( F_216 ( V_151 , V_14 , V_427 ) )
goto V_446;
if ( F_216 ( V_151 , V_14 , V_429 ) )
goto V_446;
return 0 ;
V_446:
F_218 ( V_14 ) ;
return - V_309 ;
}
int F_197 ( struct V_1 * V_14 )
{
struct V_192 * V_151 = F_54 ( V_14 -> V_163 ) ;
int V_56 ;
if ( ! V_151 )
return - V_68 ;
F_27 ( V_151 -> V_447 ) ;
V_56 = F_217 ( V_14 ) ;
F_30 ( V_151 -> V_447 ) ;
return V_56 ;
}
void F_218 ( struct V_1 * V_14 )
{
struct V_192 * V_151 ;
if ( ! V_14 || ! V_14 -> V_23 ||
V_14 -> V_15 != V_49 ||
! V_14 -> V_24 )
return;
V_14 -> V_445 -- ;
V_151 = F_54 ( V_14 -> V_163 ) ;
if ( ! V_151 || ! V_151 -> V_152 -> V_443 ||
! V_151 -> V_152 -> V_444 )
return;
if ( V_14 -> V_445 > 0 )
return;
F_215 ( V_151 , V_14 , V_427 ) ;
F_215 ( V_151 , V_14 , V_429 ) ;
}
void F_198 ( struct V_1 * V_14 )
{
struct V_192 * V_151 = F_54 ( V_14 -> V_163 ) ;
if ( ! V_151 )
return;
F_27 ( V_151 -> V_447 ) ;
F_218 ( V_14 ) ;
F_30 ( V_151 -> V_447 ) ;
}
int F_217 ( struct V_1 * V_14 )
{
return 0 ;
}
void F_218 ( struct V_1 * V_14 ) { }
int F_197 ( struct V_1 * V_14 )
{
return 0 ;
}
void F_198 ( struct V_1 * V_14 ) { }
int F_191 ( struct V_1 * V_14 )
{
return 0 ;
}
void F_193 ( struct V_1 * V_14 ) { }
static int F_219 ( struct V_6 * V_7 , int V_71 )
{
int V_56 ;
int V_175 , V_448 = 0 ;
T_1 V_176 , V_8 ;
unsigned V_449 = 0xffff ;
for ( V_175 = 0 ; ; V_175 += V_178 ) {
V_56 = F_26 ( V_7 , V_71 , & V_8 , & V_176 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( ! ( V_176 & V_210 ) &&
( V_8 & V_208 ) == V_449 ) {
V_448 += V_178 ;
if ( V_448 >= V_220 )
break;
} else {
V_448 = 0 ;
V_449 = V_8 & V_208 ;
}
if ( V_176 & V_210 ) {
F_17 ( V_7 -> V_2 , V_71 ,
V_211 ) ;
}
if ( V_175 >= V_180 )
break;
F_58 ( V_178 ) ;
}
F_20 ( V_7 -> V_112 ,
L_145 ,
V_71 , V_175 , V_448 , V_8 ) ;
if ( V_448 < V_220 )
return - V_103 ;
return V_8 ;
}
void F_220 ( struct V_1 * V_14 )
{
F_221 ( V_14 , 0 + V_64 , true ) ;
F_221 ( V_14 , 0 + V_450 , true ) ;
F_222 ( V_14 , & V_14 -> V_325 , true ) ;
}
static int F_223 ( struct V_1 * V_14 , int V_160 )
{
int V_231 ;
struct V_192 * V_151 = F_54 ( V_14 -> V_163 ) ;
if ( ! V_151 -> V_152 -> V_451 && V_160 <= 1 )
return - V_68 ;
if ( V_14 -> V_82 == V_406 )
return 0 ;
if ( V_14 -> V_82 != V_384 )
return - V_68 ;
if ( V_151 -> V_152 -> V_451 )
V_231 = V_151 -> V_152 -> V_451 ( V_151 , V_14 ) ;
else
V_231 = F_13 ( V_14 , F_224 () ,
V_452 , 0 , V_160 , 0 ,
NULL , 0 , V_201 ) ;
if ( V_231 == 0 ) {
F_136 ( V_14 , V_160 ) ;
F_63 ( V_14 , V_406 ) ;
F_220 ( V_14 ) ;
}
return V_231 ;
}
static int
F_225 ( struct V_6 * V_7 , struct V_1 * V_14 , int V_71 ,
int V_453 )
{
static F_226 ( V_454 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_192 * V_151 = F_54 ( V_2 -> V_163 ) ;
int V_55 , V_455 , V_231 ;
unsigned V_167 = V_381 ;
enum V_456 V_457 = V_14 -> V_15 ;
const char * V_15 ;
int V_160 = V_14 -> V_160 ;
if ( ! V_2 -> V_23 ) {
V_167 = V_458 ;
if ( V_71 == V_2 -> V_163 -> V_342 )
V_2 -> V_163 -> V_343 = 0 ;
}
if ( V_457 == V_379 )
V_167 = V_382 ;
F_27 ( & V_454 ) ;
V_231 = F_184 ( V_7 , V_71 , V_14 , V_167 , false ) ;
if ( V_231 < 0 )
goto V_242;
V_231 = - V_137 ;
if ( V_457 != V_459 && V_457 != V_14 -> V_15 ) {
F_20 ( & V_14 -> V_22 , L_146 ) ;
goto V_242;
}
V_457 = V_14 -> V_15 ;
switch ( V_14 -> V_15 ) {
case V_49 :
case V_378 :
V_14 -> V_325 . V_273 . V_460 = F_211 ( 512 ) ;
break;
case V_16 :
V_14 -> V_325 . V_273 . V_460 = F_211 ( 64 ) ;
break;
case V_380 :
V_14 -> V_325 . V_273 . V_460 = F_211 ( 64 ) ;
break;
case V_379 :
V_14 -> V_325 . V_273 . V_460 = F_211 ( 8 ) ;
break;
default:
goto V_242;
}
if ( V_14 -> V_15 == V_378 )
V_15 = L_147 ;
else
V_15 = F_227 ( V_14 -> V_15 ) ;
if ( V_14 -> V_15 != V_49 )
F_92 ( & V_14 -> V_22 ,
L_148 ,
( V_14 -> V_336 ) ? L_149 : L_150 , V_15 ,
V_160 , V_14 -> V_163 -> V_461 -> V_152 -> V_462 ) ;
if ( V_2 -> V_140 ) {
V_14 -> V_140 = V_2 -> V_140 ;
V_14 -> V_159 = V_2 -> V_159 ;
} else if ( V_14 -> V_15 != V_16
&& V_2 -> V_15 == V_16 ) {
if ( ! V_7 -> V_140 . V_7 ) {
F_28 ( & V_14 -> V_22 , L_151 ) ;
V_231 = - V_68 ;
goto V_242;
}
V_14 -> V_140 = & V_7 -> V_140 ;
V_14 -> V_159 = V_71 ;
}
for ( V_55 = 0 ; V_55 < V_463 ; ( ++ V_55 , F_58 ( 100 ) ) ) {
if ( F_228 ( V_453 ) && ! ( V_151 -> V_152 -> V_117 & V_464 ) ) {
struct V_465 * V_466 ;
int V_467 = 0 ;
#define F_229 64
V_466 = F_50 ( F_229 , V_207 ) ;
if ( ! V_466 ) {
V_231 = - V_157 ;
continue;
}
for ( V_455 = 0 ; V_455 < 3 ; ++ V_455 ) {
V_466 -> V_468 = 0 ;
V_467 = F_13 ( V_14 , F_230 () ,
V_63 , V_64 ,
V_469 << 8 , 0 ,
V_466 , F_229 ,
V_470 ) ;
switch ( V_466 -> V_468 ) {
case 8 : case 16 : case 32 : case 64 : case 255 :
if ( V_466 -> V_471 ==
V_469 ) {
V_467 = 0 ;
break;
}
default:
if ( V_467 == 0 )
V_467 = - V_472 ;
break;
}
if ( V_467 == 0 )
break;
}
V_14 -> V_3 . V_468 =
V_466 -> V_468 ;
F_48 ( V_466 ) ;
V_231 = F_184 ( V_7 , V_71 , V_14 , V_167 , false ) ;
if ( V_231 < 0 )
goto V_242;
if ( V_457 != V_14 -> V_15 ) {
F_20 ( & V_14 -> V_22 ,
L_146 ) ;
V_231 = - V_137 ;
goto V_242;
}
if ( V_467 ) {
F_28 ( & V_14 -> V_22 ,
L_152 ,
V_467 ) ;
V_231 = - V_473 ;
continue;
}
#undef F_229
}
if ( V_14 -> V_319 == 0 ) {
for ( V_455 = 0 ; V_455 < V_474 ; ++ V_455 ) {
V_231 = F_223 ( V_14 , V_160 ) ;
if ( V_231 >= 0 )
break;
F_58 ( 200 ) ;
}
if ( V_231 < 0 ) {
F_28 ( & V_14 -> V_22 ,
L_153 ,
V_160 , V_231 ) ;
goto V_242;
}
if ( V_14 -> V_15 == V_49 ) {
V_160 = V_14 -> V_160 ;
F_92 ( & V_14 -> V_22 ,
L_154 ,
( V_14 -> V_336 ) ? L_149 : L_150 ,
V_160 , V_14 -> V_163 -> V_461 -> V_152 -> V_462 ) ;
}
F_58 ( 10 ) ;
if ( F_228 ( V_453 ) && ! ( V_151 -> V_152 -> V_117 & V_464 ) )
break;
}
V_231 = F_178 ( V_14 , 8 ) ;
if ( V_231 < 8 ) {
F_28 ( & V_14 -> V_22 ,
L_155 ,
V_231 ) ;
if ( V_231 >= 0 )
V_231 = - V_473 ;
} else {
V_231 = 0 ;
break;
}
}
if ( V_231 )
goto V_242;
if ( V_151 -> V_475 && ! V_2 -> V_23 )
F_231 ( V_151 -> V_475 , V_14 -> V_15 ) ;
if ( ( V_14 -> V_15 == V_49 ) &&
( F_29 ( V_14 -> V_3 . V_476 ) < 0x0300 ) ) {
F_28 ( & V_14 -> V_22 , L_156
L_157 ) ;
F_184 ( V_7 , V_71 , V_14 ,
V_376 , true ) ;
V_231 = - V_68 ;
goto V_242;
}
if ( V_14 -> V_3 . V_468 == 0xff ||
V_14 -> V_15 == V_49 )
V_55 = 512 ;
else
V_55 = V_14 -> V_3 . V_468 ;
if ( F_232 ( & V_14 -> V_325 . V_273 ) != V_55 ) {
if ( V_14 -> V_15 == V_379 ||
! ( V_55 == 8 || V_55 == 16 || V_55 == 32 || V_55 == 64 ) ) {
F_28 ( & V_14 -> V_22 , L_158 , V_55 ) ;
V_231 = - V_473 ;
goto V_242;
}
if ( V_14 -> V_15 == V_380 )
F_20 ( & V_14 -> V_22 , L_159 , V_55 ) ;
else
F_7 ( & V_14 -> V_22 , L_160 , V_55 ) ;
V_14 -> V_325 . V_273 . V_460 = F_211 ( V_55 ) ;
F_220 ( V_14 ) ;
}
V_231 = F_178 ( V_14 , V_477 ) ;
if ( V_231 < ( signed ) sizeof( V_14 -> V_3 ) ) {
F_28 ( & V_14 -> V_22 , L_161 ,
V_231 ) ;
if ( V_231 >= 0 )
V_231 = - V_478 ;
goto V_242;
}
if ( V_14 -> V_319 == 0 && F_29 ( V_14 -> V_3 . V_476 ) >= 0x0201 ) {
V_231 = F_233 ( V_14 ) ;
if ( ! V_231 ) {
V_14 -> V_24 = F_5 ( V_14 ) ;
F_11 ( V_14 ) ;
}
}
V_231 = 0 ;
if ( V_151 -> V_152 -> V_479 )
V_151 -> V_152 -> V_479 ( V_151 , V_14 ) ;
V_242:
if ( V_231 ) {
F_62 ( V_7 , V_71 , 0 ) ;
F_136 ( V_14 , V_160 ) ;
}
F_30 ( & V_454 ) ;
return V_231 ;
}
static void
F_234 ( struct V_6 * V_7 , struct V_1 * V_14 , int V_71 )
{
struct V_480 * V_481 ;
int V_75 ;
V_481 = F_50 ( sizeof *V_481 , V_232 ) ;
if ( V_481 == NULL )
return;
V_75 = F_235 ( V_14 , V_482 , 0 ,
V_481 , sizeof *V_481 ) ;
if ( V_75 == sizeof *V_481 ) {
F_92 ( & V_14 -> V_22 , L_162
L_163 ) ;
if ( V_7 -> V_222 ) {
V_7 -> V_87 [ V_71 - 1 ] = V_91 ;
F_23 ( & V_7 -> V_79 , 0 ) ;
}
}
F_48 ( V_481 ) ;
}
static unsigned
F_236 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_272 ;
int V_71 ;
if ( ! V_7 -> V_269 )
return 0 ;
V_272 = V_2 -> V_267 - V_7 -> V_3 -> V_271 ;
for ( V_71 = 1 ; V_71 <= V_2 -> V_12 ; ++ V_71 ) {
struct V_1 * V_14 = V_7 -> V_183 [ V_71 - 1 ] -> V_184 ;
int V_483 ;
if ( ! V_14 )
continue;
if ( V_14 -> V_11 )
V_483 = V_14 -> V_11 -> V_273 . V_484 * 2 ;
else if ( V_71 != V_14 -> V_163 -> V_342 || V_2 -> V_23 )
V_483 = 100 ;
else
V_483 = 8 ;
if ( V_483 > V_7 -> V_268 )
F_7 ( & V_14 -> V_22 ,
L_164 ,
V_483 , V_7 -> V_268 , V_71 ) ;
V_272 -= V_483 ;
}
if ( V_272 < 0 ) {
F_7 ( V_7 -> V_112 , L_165 ,
- V_272 ) ;
V_272 = 0 ;
}
return V_272 ;
}
static void F_237 ( struct V_6 * V_7 , int V_71 ,
T_1 V_8 , T_1 V_176 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_228 * V_237 = V_7 -> V_112 ;
struct V_192 * V_151 = F_54 ( V_2 -> V_163 ) ;
unsigned V_168 =
F_29 ( V_7 -> V_3 -> V_168 ) ;
struct V_1 * V_14 ;
int V_75 , V_55 ;
F_20 ( V_237 ,
L_166 ,
V_71 , V_8 , V_176 , F_2 ( V_7 , V_8 ) ) ;
if ( V_7 -> V_222 ) {
F_19 ( V_7 , V_71 , V_89 ) ;
V_7 -> V_87 [ V_71 - 1 ] = V_90 ;
}
#ifdef F_147
if ( V_2 -> V_163 -> V_335 )
V_176 &= ~ ( V_210 |
V_212 ) ;
#endif
V_14 = V_7 -> V_183 [ V_71 - 1 ] -> V_184 ;
if ( ( V_8 & V_208 ) && V_14 &&
V_14 -> V_82 != V_185 ) {
F_138 ( V_14 ) ;
if ( V_8 & V_209 ) {
V_75 = 0 ;
#ifdef F_238
} else if ( V_14 -> V_82 == V_311 &&
V_14 -> V_218 ) {
V_75 = F_202 ( V_14 ) ;
#endif
} else {
V_75 = - V_137 ;
}
F_142 ( V_14 ) ;
if ( V_75 == 0 ) {
F_71 ( V_71 , V_7 -> V_187 ) ;
return;
}
}
if ( V_14 ) {
if ( V_151 -> V_475 && ! V_2 -> V_23 &&
! ( V_8 & V_208 ) )
F_239 ( V_151 -> V_475 , V_14 -> V_15 ) ;
F_76 ( & V_7 -> V_183 [ V_71 - 1 ] -> V_184 ) ;
}
F_71 ( V_71 , V_7 -> V_187 ) ;
if ( ! ( V_8 & V_208 ) ||
( V_176 & V_210 ) )
F_71 ( V_71 , V_7 -> V_190 ) ;
if ( V_176 & ( V_210 |
V_212 ) ) {
V_75 = F_219 ( V_7 , V_71 ) ;
if ( V_75 < 0 ) {
if ( F_240 () )
F_28 ( V_237 , L_167
L_168 , V_71 ) ;
V_8 &= ~ V_208 ;
} else {
V_8 = V_75 ;
}
}
if ( ! ( V_8 & V_208 ) ||
F_133 ( V_71 , V_7 -> V_190 ) ) {
if ( ( V_168 & V_169 ) < 2
&& ! F_188 ( V_7 , V_8 ) )
F_18 ( V_2 , V_71 , V_170 ) ;
if ( V_8 & V_209 )
goto V_389;
return;
}
for ( V_55 = 0 ; V_55 < V_485 ; V_55 ++ ) {
V_14 = F_241 ( V_2 , V_2 -> V_163 , V_71 ) ;
if ( ! V_14 ) {
F_28 ( V_237 ,
L_169 ,
V_71 ) ;
goto V_389;
}
F_63 ( V_14 , V_486 ) ;
V_14 -> V_267 = V_7 -> V_268 ;
V_14 -> V_200 = V_2 -> V_200 + 1 ;
V_14 -> V_319 = F_181 ( V_7 ) ;
if ( F_1 ( V_7 -> V_2 ) )
V_14 -> V_15 = V_49 ;
else
V_14 -> V_15 = V_459 ;
F_131 ( V_14 ) ;
if ( V_14 -> V_160 <= 0 ) {
V_75 = - V_377 ;
goto V_487;
}
V_75 = F_225 ( V_7 , V_14 , V_71 , V_55 ) ;
if ( V_75 < 0 )
goto V_487;
F_242 ( V_14 ) ;
if ( V_14 -> V_488 & V_489 )
F_58 ( 1000 ) ;
if ( V_14 -> V_3 . V_490 == V_491
&& V_14 -> V_267 <= 100 ) {
T_1 V_492 ;
V_75 = F_97 ( V_14 , V_265 , 0 ,
& V_492 ) ;
if ( V_75 < 2 ) {
F_20 ( & V_14 -> V_22 , L_170 , V_75 ) ;
goto V_493;
}
F_98 ( & V_492 ) ;
if ( ( V_492 & ( 1 << V_270 ) ) == 0 ) {
F_28 ( & V_14 -> V_22 ,
L_171
L_172 ) ;
if ( V_7 -> V_222 ) {
V_7 -> V_87 [ V_71 - 1 ] =
V_95 ;
F_23 ( & V_7 -> V_79 , 0 ) ;
}
V_75 = - V_377 ;
goto V_493;
}
}
if ( F_29 ( V_14 -> V_3 . V_476 ) >= 0x0200
&& V_14 -> V_15 == V_380
&& V_281 != 0 )
F_234 ( V_7 , V_14 , V_71 ) ;
V_75 = 0 ;
F_108 ( & V_300 ) ;
if ( V_2 -> V_82 == V_185 )
V_75 = - V_377 ;
else
V_7 -> V_183 [ V_71 - 1 ] -> V_184 = V_14 ;
F_111 ( & V_300 ) ;
if ( ! V_75 ) {
V_75 = F_157 ( V_14 ) ;
if ( V_75 ) {
F_108 ( & V_300 ) ;
V_7 -> V_183 [ V_71 - 1 ] -> V_184 = NULL ;
F_111 ( & V_300 ) ;
}
}
if ( V_75 )
goto V_493;
V_75 = F_236 ( V_7 ) ;
if ( V_75 )
F_20 ( V_237 , L_173 , V_75 ) ;
return;
V_493:
F_62 ( V_7 , V_71 , 1 ) ;
V_487:
F_220 ( V_14 ) ;
F_135 ( V_14 ) ;
F_137 ( V_14 ) ;
F_243 ( V_14 ) ;
if ( ( V_75 == - V_377 ) || ( V_75 == - V_347 ) )
break;
}
if ( V_7 -> V_2 -> V_23 ||
! V_151 -> V_152 -> V_494 ||
! ( V_151 -> V_152 -> V_494 ) ( V_151 , V_71 ) )
F_28 ( V_237 , L_174 ,
V_71 ) ;
V_389:
F_62 ( V_7 , V_71 , 1 ) ;
if ( V_151 -> V_152 -> V_495 && ! V_7 -> V_2 -> V_23 )
V_151 -> V_152 -> V_495 ( V_151 , V_71 ) ;
}
static int F_244 ( struct V_6 * V_7 , unsigned int V_111 ,
T_1 V_8 , T_1 V_176 )
{
struct V_1 * V_2 ;
struct V_1 * V_14 ;
int V_496 = 0 ;
int V_56 ;
V_2 = V_7 -> V_2 ;
V_14 = V_7 -> V_183 [ V_111 - 1 ] -> V_184 ;
if ( ! F_1 ( V_2 ) ) {
if ( ! ( V_176 & V_412 ) )
return 0 ;
F_17 ( V_2 , V_111 , V_413 ) ;
} else {
if ( ! V_14 || V_14 -> V_82 != V_311 ||
( V_8 & V_179 ) !=
V_217 )
return 0 ;
}
if ( V_14 ) {
F_58 ( 10 ) ;
F_138 ( V_14 ) ;
V_56 = F_202 ( V_14 ) ;
F_142 ( V_14 ) ;
if ( V_56 < 0 )
V_496 = 1 ;
} else {
V_56 = - V_137 ;
F_62 ( V_7 , V_111 , 1 ) ;
}
F_20 ( V_7 -> V_112 , L_175 ,
V_111 , V_56 ) ;
return V_496 ;
}
static void F_245 ( void )
{
struct V_145 * V_497 ;
struct V_1 * V_2 ;
struct V_188 * V_189 ;
struct V_6 * V_7 ;
struct V_228 * V_237 ;
T_1 V_238 ;
T_1 V_239 ;
T_1 V_8 ;
T_1 V_176 ;
int V_55 , V_56 ;
int V_496 , V_498 ;
while ( 1 ) {
F_108 ( & V_118 ) ;
if ( F_33 ( & V_121 ) ) {
F_111 ( & V_118 ) ;
break;
}
V_497 = V_121 . V_146 ;
F_109 ( V_497 ) ;
V_7 = F_46 ( V_497 , struct V_6 , V_120 ) ;
F_246 ( & V_7 -> V_279 ) ;
F_111 ( & V_118 ) ;
V_2 = V_7 -> V_2 ;
V_237 = V_7 -> V_112 ;
V_189 = F_36 ( V_237 ) ;
F_20 ( V_237 , L_176 ,
V_2 -> V_82 , V_7 -> V_3
? V_7 -> V_3 -> V_85
: 0 ,
( T_1 ) V_7 -> V_187 [ 0 ] ,
( T_1 ) V_7 -> V_135 [ 0 ] ) ;
F_138 ( V_2 ) ;
if ( F_247 ( V_7 -> V_119 ) )
goto V_499;
if ( V_2 -> V_82 == V_185 ) {
V_7 -> error = - V_137 ;
F_74 ( V_7 , V_280 ) ;
goto V_487;
}
V_56 = F_66 ( V_189 ) ;
if ( V_56 ) {
F_20 ( V_237 , L_177 , V_56 ) ;
goto V_487;
}
if ( V_7 -> V_84 )
goto V_500;
if ( V_7 -> error ) {
F_20 ( V_237 , L_178 ,
V_7 -> error ) ;
V_56 = F_248 ( V_2 ) ;
if ( V_56 ) {
F_20 ( V_237 ,
L_179 , V_56 ) ;
goto V_500;
}
V_7 -> V_131 = 0 ;
V_7 -> error = 0 ;
}
for ( V_55 = 1 ; V_55 <= V_7 -> V_3 -> V_85 ; V_55 ++ ) {
if ( F_133 ( V_55 , V_7 -> V_411 ) )
continue;
V_496 = F_133 ( V_55 , V_7 -> V_187 ) ;
V_498 = F_249 ( V_55 , V_7 -> V_124 ) ;
if ( ! F_249 ( V_55 , V_7 -> V_135 ) &&
! V_496 && ! V_498 )
continue;
V_56 = F_26 ( V_7 , V_55 ,
& V_8 , & V_176 ) ;
if ( V_56 < 0 )
continue;
if ( V_176 & V_210 ) {
F_17 ( V_2 , V_55 ,
V_211 ) ;
V_496 = 1 ;
}
if ( V_176 & V_212 ) {
if ( ! V_496 )
F_20 ( V_237 ,
L_180
L_181 ,
V_55 , V_8 ) ;
F_17 ( V_2 , V_55 ,
V_213 ) ;
if ( ! ( V_8 & V_209 )
&& ! V_496
&& V_7 -> V_183 [ V_55 - 1 ] -> V_184 ) {
F_28 ( V_237 ,
L_182
L_183
L_184 ,
V_55 ) ;
V_496 = 1 ;
}
}
if ( F_244 ( V_7 , V_55 ,
V_8 , V_176 ) )
V_496 = 1 ;
if ( V_176 & V_501 ) {
T_1 V_75 = 0 ;
T_1 V_502 ;
F_20 ( V_237 , L_185
L_186 , V_55 ) ;
F_17 ( V_2 , V_55 ,
V_503 ) ;
F_58 ( 100 ) ;
F_56 ( V_7 , true ) ;
F_26 ( V_7 , V_55 , & V_75 , & V_502 ) ;
if ( V_75 & V_504 )
F_28 ( V_237 , L_187
L_188 , V_55 ) ;
}
if ( V_176 & V_374 ) {
F_20 ( V_237 ,
L_189 ,
V_55 ) ;
F_17 ( V_2 , V_55 ,
V_375 ) ;
}
if ( ( V_176 & V_214 ) &&
F_1 ( V_7 -> V_2 ) ) {
F_20 ( V_237 ,
L_190 ,
V_55 ) ;
F_17 ( V_2 , V_55 ,
V_215 ) ;
}
if ( V_176 & V_372 ) {
F_17 ( V_7 -> V_2 , V_55 ,
V_373 ) ;
}
if ( V_176 & V_505 ) {
F_7 ( V_237 ,
L_191 ,
V_55 ) ;
F_17 ( V_7 -> V_2 , V_55 ,
V_506 ) ;
}
if ( F_182 ( V_7 , V_8 ) ) {
int V_75 ;
F_20 ( V_237 , L_192 , V_55 ) ;
V_75 = F_184 ( V_7 , V_55 , NULL ,
V_376 , true ) ;
if ( V_75 < 0 )
F_62 ( V_7 , V_55 , 1 ) ;
V_496 = 0 ;
}
if ( V_496 )
F_237 ( V_7 , V_55 ,
V_8 , V_176 ) ;
}
if ( F_249 ( 0 , V_7 -> V_135 ) == 0 )
;
else if ( F_59 ( V_7 , & V_238 , & V_239 ) < 0 )
F_28 ( V_237 , L_193 ) ;
else {
if ( V_239 & V_507 ) {
F_20 ( V_237 , L_194 ) ;
F_15 ( V_2 , V_508 ) ;
if ( V_238 & V_275 )
V_7 -> V_269 = 1 ;
else
V_7 -> V_269 = 0 ;
}
if ( V_239 & V_509 ) {
T_1 V_75 = 0 ;
T_1 V_502 ;
F_20 ( V_237 , L_195 ) ;
F_15 ( V_2 , V_510 ) ;
F_58 ( 500 ) ;
F_56 ( V_7 , true ) ;
F_59 ( V_7 , & V_75 , & V_502 ) ;
if ( V_75 & V_276 )
F_28 ( V_237 , L_187
L_196 ) ;
}
}
V_500:
F_110 ( V_189 ) ;
V_487:
F_67 ( V_189 ) ;
V_499:
F_142 ( V_2 ) ;
F_114 ( & V_7 -> V_279 , F_104 ) ;
}
}
static int F_250 ( void * V_511 )
{
F_251 () ;
do {
F_245 () ;
F_252 ( V_122 ,
! F_33 ( & V_121 ) ||
F_253 () ) ;
} while ( ! F_253 () || ! F_33 ( & V_121 ) );
F_254 ( L_197 , V_512 ) ;
return 0 ;
}
int F_255 ( void )
{
if ( F_256 ( & V_513 ) < 0 ) {
F_257 ( V_514 L_198 ,
V_512 ) ;
return - 1 ;
}
V_515 = F_258 ( F_250 , NULL , L_199 ) ;
if ( ! F_259 ( V_515 ) )
return 0 ;
F_260 ( & V_513 ) ;
F_257 ( V_514 L_200 , V_512 ) ;
return - 1 ;
}
void F_261 ( void )
{
F_262 ( V_515 ) ;
F_260 ( & V_513 ) ;
}
static int F_263 ( struct V_1 * V_14 ,
struct V_465 * V_516 )
{
int V_80 = 0 ;
unsigned V_517 ;
unsigned V_518 = 0 ;
unsigned V_519 ;
unsigned V_520 ;
int V_521 ;
char * V_466 ;
if ( memcmp ( & V_14 -> V_3 , V_516 ,
sizeof( * V_516 ) ) != 0 )
return 1 ;
if ( V_14 -> V_333 )
V_518 = strlen ( V_14 -> V_333 ) + 1 ;
V_519 = V_518 ;
for ( V_517 = 0 ; V_517 < V_14 -> V_3 . V_357 ; V_517 ++ ) {
V_520 = F_29 ( V_14 -> V_336 [ V_517 ] . V_273 . V_339 ) ;
V_519 = F_57 ( V_519 , V_520 ) ;
}
V_466 = F_50 ( V_519 , V_207 ) ;
if ( V_466 == NULL ) {
F_28 ( & V_14 -> V_22 , L_201 ) ;
return 1 ;
}
for ( V_517 = 0 ; V_517 < V_14 -> V_3 . V_357 ; V_517 ++ ) {
V_520 = F_29 ( V_14 -> V_336 [ V_517 ] . V_273 . V_339 ) ;
V_521 = F_235 ( V_14 , V_522 , V_517 , V_466 ,
V_520 ) ;
if ( V_521 != V_520 ) {
F_20 ( & V_14 -> V_22 , L_202 ,
V_517 , V_521 ) ;
V_80 = 1 ;
break;
}
if ( memcmp ( V_466 , V_14 -> V_338 [ V_517 ] , V_520 )
!= 0 ) {
F_20 ( & V_14 -> V_22 , L_203 ,
V_517 ,
( (struct V_523 * ) V_466 ) ->
V_524 ) ;
V_80 = 1 ;
break;
}
}
if ( ! V_80 && V_518 ) {
V_521 = F_264 ( V_14 , V_14 -> V_3 . V_330 ,
V_466 , V_518 ) ;
if ( V_521 + 1 != V_518 ) {
F_20 ( & V_14 -> V_22 , L_204 ,
V_521 ) ;
V_80 = 1 ;
} else if ( memcmp ( V_466 , V_14 -> V_333 , V_521 ) != 0 ) {
F_20 ( & V_14 -> V_22 , L_205 ) ;
V_80 = 1 ;
}
}
F_48 ( V_466 ) ;
return V_80 ;
}
static int F_200 ( struct V_1 * V_14 )
{
struct V_1 * V_525 = V_14 -> V_23 ;
struct V_6 * V_526 ;
struct V_192 * V_151 = F_54 ( V_14 -> V_163 ) ;
struct V_465 V_3 = V_14 -> V_3 ;
int V_55 , V_56 = 0 ;
int V_71 = V_14 -> V_123 ;
if ( V_14 -> V_82 == V_185 ||
V_14 -> V_82 == V_311 ) {
F_20 ( & V_14 -> V_22 , L_206 ,
V_14 -> V_82 ) ;
return - V_68 ;
}
if ( ! V_525 ) {
F_20 ( & V_14 -> V_22 , L_207 , V_113 ) ;
return - V_527 ;
}
V_526 = F_3 ( V_525 ) ;
V_56 = F_197 ( V_14 ) ;
if ( V_56 ) {
F_28 ( & V_14 -> V_22 , L_208 , V_113 ) ;
goto V_528;
}
V_56 = F_191 ( V_14 ) ;
if ( V_56 ) {
F_28 ( & V_14 -> V_22 , L_209 ,
V_113 ) ;
goto V_528;
}
F_41 ( V_71 , V_526 -> V_411 ) ;
for ( V_55 = 0 ; V_55 < V_485 ; ++ V_55 ) {
F_220 ( V_14 ) ;
V_56 = F_225 ( V_526 , V_14 , V_71 , V_55 ) ;
if ( V_56 >= 0 || V_56 == - V_377 || V_56 == - V_137 )
break;
}
F_71 ( V_71 , V_526 -> V_411 ) ;
if ( V_56 < 0 )
goto V_528;
if ( F_263 ( V_14 , & V_3 ) ) {
F_92 ( & V_14 -> V_22 , L_210 ) ;
V_14 -> V_3 = V_3 ;
goto V_528;
}
if ( ! V_14 -> V_11 )
goto V_389;
F_27 ( V_151 -> V_447 ) ;
V_56 = F_265 ( V_14 , V_14 -> V_11 , NULL , NULL ) ;
if ( V_56 < 0 ) {
F_7 ( & V_14 -> V_22 ,
L_211
L_212 ) ;
F_30 ( V_151 -> V_447 ) ;
goto V_528;
}
V_56 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_529 , 0 ,
V_14 -> V_11 -> V_273 . V_524 , 0 ,
NULL , 0 , V_201 ) ;
if ( V_56 < 0 ) {
F_28 ( & V_14 -> V_22 ,
L_213 ,
V_14 -> V_11 -> V_273 . V_524 , V_56 ) ;
F_30 ( V_151 -> V_447 ) ;
goto V_528;
}
F_30 ( V_151 -> V_447 ) ;
F_63 ( V_14 , V_83 ) ;
for ( V_55 = 0 ; V_55 < V_14 -> V_11 -> V_273 . V_530 ; V_55 ++ ) {
struct V_531 * V_336 = V_14 -> V_11 ;
struct V_188 * V_189 = V_336 -> V_13 [ V_55 ] ;
struct V_532 * V_273 ;
V_273 = & V_189 -> V_285 -> V_273 ;
if ( V_273 -> V_533 == 0 ) {
F_266 ( V_14 , V_189 , true ) ;
F_267 ( V_14 , V_189 , true ) ;
V_56 = 0 ;
} else {
V_189 -> V_534 = 1 ;
V_56 = F_96 ( V_14 , V_273 -> V_535 ,
V_273 -> V_533 ) ;
V_189 -> V_534 = 0 ;
}
if ( V_56 < 0 ) {
F_28 ( & V_14 -> V_22 , L_214
L_215 ,
V_273 -> V_535 ,
V_273 -> V_533 ,
V_56 ) ;
goto V_528;
}
}
V_389:
F_198 ( V_14 ) ;
F_193 ( V_14 ) ;
return 0 ;
V_528:
F_64 ( V_526 , V_71 ) ;
return - V_137 ;
}
int F_248 ( struct V_1 * V_14 )
{
int V_56 ;
int V_55 ;
struct V_531 * V_336 = V_14 -> V_11 ;
if ( V_14 -> V_82 == V_185 ||
V_14 -> V_82 == V_311 ) {
F_20 ( & V_14 -> V_22 , L_206 ,
V_14 -> V_82 ) ;
return - V_68 ;
}
F_177 ( V_14 ) ;
if ( V_336 ) {
for ( V_55 = 0 ; V_55 < V_336 -> V_273 . V_530 ; ++ V_55 ) {
struct V_188 * V_536 = V_336 -> V_13 [ V_55 ] ;
struct V_537 * V_150 ;
int V_538 = 0 ;
if ( V_536 -> V_22 . V_152 ) {
V_150 = F_268 ( V_536 -> V_22 . V_152 ) ;
if ( V_150 -> V_539 && V_150 -> V_540 )
V_538 = ( V_150 -> V_539 ) ( V_536 ) ;
else if ( V_536 -> V_541 ==
V_542 )
V_538 = 1 ;
if ( V_538 )
F_269 ( V_536 ) ;
}
}
}
V_56 = F_200 ( V_14 ) ;
if ( V_336 ) {
for ( V_55 = V_336 -> V_273 . V_530 - 1 ; V_55 >= 0 ; -- V_55 ) {
struct V_188 * V_536 = V_336 -> V_13 [ V_55 ] ;
struct V_537 * V_150 ;
int V_543 = V_536 -> V_544 ;
if ( ! V_543 && V_536 -> V_22 . V_152 ) {
V_150 = F_268 ( V_536 -> V_22 . V_152 ) ;
if ( V_150 -> V_540 )
V_543 = ( V_150 -> V_540 ) ( V_536 ) ;
else if ( V_536 -> V_541 ==
V_542 )
V_543 = 1 ;
}
if ( V_56 == 0 && V_543 )
F_270 ( V_536 ) ;
}
}
F_180 ( V_14 ) ;
return V_56 ;
}
void F_271 ( struct V_188 * V_545 )
{
F_55 ( & V_545 -> V_546 ) ;
}
struct V_1 * F_272 ( struct V_1 * V_2 ,
int V_71 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_71 < 1 || V_71 > V_2 -> V_12 )
return NULL ;
return V_7 -> V_183 [ V_71 - 1 ] -> V_184 ;
}
void F_273 ( struct V_1 * V_2 , int V_71 ,
enum V_547 type )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
V_7 -> V_183 [ V_71 - 1 ] -> V_548 = type ;
}
enum V_547
F_274 ( struct V_1 * V_2 , int V_71 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
return V_7 -> V_183 [ V_71 - 1 ] -> V_548 ;
}
T_6 F_275 ( struct V_1 * V_2 ,
int V_71 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
return F_276 ( & V_7 -> V_183 [ V_71 - 1 ] -> V_22 ) ;
}
