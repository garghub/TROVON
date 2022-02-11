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
int V_143 = 100 ;
F_32 ( & V_7 -> V_140 . V_144 , V_117 ) ;
while ( ! F_33 ( & V_7 -> V_140 . V_145 ) ) {
struct V_146 * V_147 ;
struct V_148 * V_149 ;
struct V_1 * V_2 = V_7 -> V_2 ;
const struct V_150 * V_151 ;
int V_75 ;
if ( ! V_7 -> V_84 && -- V_143 < 0 )
break;
V_147 = V_7 -> V_140 . V_145 . V_147 ;
V_149 = F_46 ( V_147 , struct V_148 , V_145 ) ;
F_47 ( & V_149 -> V_145 ) ;
F_38 ( & V_7 -> V_140 . V_144 , V_117 ) ;
V_75 = F_44 ( V_2 , V_149 -> V_139 , V_149 -> V_140 ) ;
if ( V_75 )
F_28 ( & V_2 -> V_22 ,
L_17 ,
V_149 -> V_140 , V_149 -> V_139 , V_75 ) ;
V_151 = V_149 -> V_152 -> V_153 ;
if ( V_151 -> V_154 )
( V_151 -> V_154 ) ( V_149 -> V_152 , V_149 -> V_155 ) ;
F_48 ( V_149 ) ;
F_32 ( & V_7 -> V_140 . V_144 , V_117 ) ;
}
F_38 ( & V_7 -> V_140 . V_144 , V_117 ) ;
}
int F_49 ( struct V_125 * V_125 )
{
struct V_1 * V_14 = V_125 -> V_22 ;
int V_156 = V_125 -> V_156 ;
struct V_157 * V_140 = V_14 -> V_140 ;
unsigned long V_117 ;
struct V_148 * V_149 ;
if ( ( V_149 = F_50 ( sizeof *V_149 , V_136 ) ) == NULL ) {
F_28 ( & V_14 -> V_22 , L_18 ) ;
return - V_158 ;
}
V_149 -> V_140 = V_140 -> V_159 ? V_14 -> V_160 : 1 ;
V_149 -> V_139 = F_51 ( V_156 ) ;
V_149 -> V_139 |= V_14 -> V_161 << 4 ;
V_149 -> V_139 |= F_52 ( V_156 )
? ( V_162 << 11 )
: ( V_163 << 11 ) ;
if ( F_53 ( V_156 ) )
V_149 -> V_139 |= 1 << 15 ;
V_149 -> V_152 = F_54 ( V_14 -> V_164 ) ;
V_149 -> V_155 = V_125 -> V_155 ;
F_32 ( & V_140 -> V_144 , V_117 ) ;
F_34 ( & V_149 -> V_145 , & V_140 -> V_145 ) ;
F_55 ( & V_140 -> V_142 ) ;
F_38 ( & V_140 -> V_144 , V_117 ) ;
return 0 ;
}
static unsigned F_56 ( struct V_6 * V_7 , bool V_165 )
{
int V_71 ;
unsigned V_166 = V_7 -> V_3 -> V_167 * 2 ;
unsigned V_168 ;
T_1 V_169 =
F_29 ( V_7 -> V_3 -> V_169 ) ;
if ( ( V_169 & V_170 ) < 2 )
F_20 ( V_7 -> V_112 , L_19 ) ;
else
F_20 ( V_7 -> V_112 , L_20
L_21 ) ;
for ( V_71 = 1 ; V_71 <= V_7 -> V_3 -> V_85 ; V_71 ++ )
F_18 ( V_7 -> V_2 , V_71 , V_171 ) ;
V_168 = F_57 ( V_166 , ( unsigned ) 100 ) ;
if ( V_165 )
F_58 ( V_168 ) ;
return V_168 ;
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
* V_75 = F_29 ( V_7 -> V_75 -> V_7 . V_172 ) ;
* V_109 = F_29 ( V_7 -> V_75 -> V_7 . V_173 ) ;
V_56 = 0 ;
}
F_30 ( & V_7 -> V_110 ) ;
return V_56 ;
}
static int F_60 ( struct V_6 * V_7 , int V_71 , int V_174 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_56 = 0 ;
if ( V_7 -> V_175 [ V_71 - 1 ] -> V_176 && V_174 )
F_61 ( V_7 -> V_175 [ V_71 - 1 ] -> V_176 ,
V_177 ) ;
if ( ! V_7 -> error && ! F_1 ( V_7 -> V_2 ) )
V_56 = F_17 ( V_2 , V_71 , V_178 ) ;
if ( V_56 )
F_28 ( V_7 -> V_112 , L_22 ,
V_71 , V_56 ) ;
return V_56 ;
}
static void F_62 ( struct V_6 * V_7 , int V_71 )
{
F_20 ( V_7 -> V_112 , L_23 , V_71 ) ;
F_60 ( V_7 , V_71 , 1 ) ;
F_41 ( V_71 , V_7 -> V_179 ) ;
F_31 ( V_7 ) ;
}
int F_63 ( struct V_1 * V_14 )
{
struct V_6 * V_7 ;
struct V_180 * V_181 ;
if ( ! V_14 -> V_23 )
return - V_68 ;
V_7 = F_3 ( V_14 -> V_23 ) ;
V_181 = F_36 ( V_7 -> V_112 ) ;
F_64 ( V_181 ) ;
F_41 ( V_14 -> V_123 , V_7 -> V_182 ) ;
F_62 ( V_7 , V_14 -> V_123 ) ;
F_65 ( V_181 ) ;
return 0 ;
}
static void F_66 ( struct V_6 * V_7 , enum V_183 type )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_184 * V_152 ;
int V_56 ;
int V_71 ;
int V_75 ;
bool V_185 = false ;
unsigned V_168 ;
if ( type == V_186 )
goto V_187;
if ( type == V_188 )
goto V_189;
if ( type != V_190 ) {
if ( V_2 -> V_23 && F_1 ( V_2 ) ) {
V_56 = F_13 ( V_2 , F_16 ( V_2 , 0 ) ,
V_191 , V_65 ,
V_2 -> V_192 - 1 , 0 , NULL , 0 ,
V_193 ) ;
if ( V_56 < 0 )
F_28 ( V_7 -> V_112 ,
L_24 ) ;
}
if ( type == V_194 ) {
V_168 = F_56 ( V_7 , false ) ;
F_67 ( & V_7 -> V_195 , V_196 ) ;
F_23 ( & V_7 -> V_195 ,
F_68 ( V_168 ) ) ;
F_35 (
F_36 ( V_7 -> V_112 ) ) ;
return;
} else if ( type == V_197 ) {
V_152 = F_54 ( V_2 -> V_164 ) ;
if ( V_152 -> V_153 -> V_198 ) {
V_56 = V_152 -> V_153 -> V_198 ( V_152 , V_2 ,
& V_7 -> V_140 , V_199 ) ;
if ( V_56 < 0 ) {
F_28 ( V_7 -> V_112 , L_25
L_26
L_27 ) ;
F_28 ( V_7 -> V_112 , L_28
L_29
L_30 ) ;
}
}
F_56 ( V_7 , true ) ;
} else {
F_56 ( V_7 , true ) ;
}
}
V_187:
for ( V_71 = 1 ; V_71 <= V_2 -> V_12 ; ++ V_71 ) {
struct V_1 * V_14 = V_7 -> V_175 [ V_71 - 1 ] -> V_176 ;
T_1 V_8 , V_200 ;
V_8 = V_200 = 0 ;
V_75 = F_26 ( V_7 , V_71 , & V_8 , & V_200 ) ;
if ( V_14 || ( V_8 & V_201 ) )
F_20 ( V_7 -> V_112 ,
L_31 ,
V_71 , V_8 , V_200 ) ;
if ( ( V_8 & V_202 ) && (
type != V_190 ||
! ( V_8 & V_201 ) ||
! V_14 ||
V_14 -> V_82 == V_177 ) ) {
if ( ! F_1 ( V_2 ) ) {
F_17 ( V_2 , V_71 ,
V_178 ) ;
V_8 &= ~ V_202 ;
} else {
V_8 &= ~ V_202 ;
}
}
if ( V_200 & V_203 ) {
V_185 = true ;
F_17 ( V_7 -> V_2 , V_71 ,
V_204 ) ;
}
if ( V_200 & V_205 ) {
V_185 = true ;
F_17 ( V_7 -> V_2 , V_71 ,
V_206 ) ;
}
if ( ( V_200 & V_207 ) &&
F_1 ( V_7 -> V_2 ) ) {
V_185 = true ;
F_17 ( V_7 -> V_2 , V_71 ,
V_208 ) ;
}
if ( ! ( V_8 & V_201 ) ||
( V_200 & V_203 ) )
F_69 ( V_71 , V_7 -> V_182 ) ;
if ( ! V_14 || V_14 -> V_82 == V_177 ) {
if ( V_14 || ( V_8 & V_201 ) )
F_41 ( V_71 , V_7 -> V_179 ) ;
} else if ( V_8 & V_202 ) {
bool V_209 = ( V_8 &
V_210 ) ==
V_211 ;
if ( V_200 || ( F_1 ( V_7 -> V_2 ) &&
V_209 ) )
F_41 ( V_71 , V_7 -> V_179 ) ;
} else if ( V_14 -> V_212 ) {
#ifdef F_70
V_14 -> V_213 = 1 ;
#endif
F_41 ( V_71 , V_7 -> V_179 ) ;
} else {
F_61 ( V_14 , V_177 ) ;
F_41 ( V_71 , V_7 -> V_179 ) ;
}
}
if ( V_185 ) {
V_168 = V_214 ;
if ( type == V_186 ) {
F_67 ( & V_7 -> V_195 , V_215 ) ;
F_23 ( & V_7 -> V_195 ,
F_68 ( V_168 ) ) ;
return;
} else {
F_58 ( V_168 ) ;
}
}
V_189:
V_7 -> V_84 = 0 ;
V_75 = F_43 ( V_7 -> V_125 , V_199 ) ;
if ( V_75 < 0 )
F_28 ( V_7 -> V_112 , L_32 , V_75 ) ;
if ( V_7 -> V_216 && V_100 )
F_23 ( & V_7 -> V_79 , V_101 ) ;
F_31 ( V_7 ) ;
if ( type <= V_188 )
F_71 ( F_36 ( V_7 -> V_112 ) ) ;
}
static void V_196 ( struct V_77 * V_217 )
{
struct V_6 * V_7 = F_22 ( V_217 , struct V_6 , V_195 . V_78 ) ;
F_66 ( V_7 , V_186 ) ;
}
static void V_215 ( struct V_77 * V_217 )
{
struct V_6 * V_7 = F_22 ( V_217 , struct V_6 , V_195 . V_78 ) ;
F_66 ( V_7 , V_188 ) ;
}
static void F_72 ( struct V_6 * V_7 , enum V_218 type )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_55 ;
F_73 ( & V_7 -> V_195 ) ;
V_7 -> V_84 = 1 ;
if ( type != V_219 ) {
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; ++ V_55 ) {
if ( V_7 -> V_175 [ V_55 ] -> V_176 )
F_74 ( & V_7 -> V_175 [ V_55 ] -> V_176 ) ;
}
}
F_75 ( V_7 -> V_125 ) ;
if ( V_7 -> V_216 )
F_73 ( & V_7 -> V_79 ) ;
if ( V_7 -> V_140 . V_7 )
F_76 ( & V_7 -> V_140 . V_142 ) ;
}
static int F_77 ( struct V_180 * V_181 )
{
struct V_6 * V_7 = F_4 ( V_181 ) ;
F_72 ( V_7 , V_220 ) ;
return 0 ;
}
static int F_78 ( struct V_180 * V_181 )
{
struct V_6 * V_7 = F_4 ( V_181 ) ;
F_66 ( V_7 , V_221 ) ;
return 0 ;
}
static void F_79 ( struct V_222 * V_22 )
{
struct V_223 * V_224 = F_80 ( V_22 ) ;
F_48 ( V_224 ) ;
}
static void F_81 ( struct V_6 * V_7 ,
int V_71 )
{
F_82 ( & V_7 -> V_175 [ V_71 - 1 ] -> V_22 ) ;
}
static int F_83 ( struct V_6 * V_7 ,
int V_71 )
{
struct V_223 * V_224 = NULL ;
int V_225 ;
V_224 = F_84 ( sizeof( * V_224 ) , V_226 ) ;
if ( ! V_224 ) {
V_225 = - V_158 ;
goto exit;
}
V_7 -> V_175 [ V_71 - 1 ] = V_224 ;
V_224 -> V_22 . V_23 = V_7 -> V_112 ;
V_224 -> V_22 . type = & V_227 ;
F_85 ( & V_224 -> V_22 , L_33 , V_71 ) ;
V_225 = F_86 ( & V_224 -> V_22 ) ;
if ( V_225 )
goto V_228;
return 0 ;
V_228:
F_87 ( & V_224 -> V_22 ) ;
exit:
return V_225 ;
}
static int F_88 ( struct V_6 * V_7 ,
struct V_229 * V_230 )
{
struct V_184 * V_152 ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_222 * V_231 = V_7 -> V_112 ;
T_1 V_232 , V_233 ;
T_1 V_169 ;
unsigned int V_156 ;
int V_234 , V_56 , V_55 ;
char * V_235 = L_34 ;
V_7 -> V_134 = F_50 ( sizeof( * V_7 -> V_134 ) , V_226 ) ;
if ( ! V_7 -> V_134 ) {
V_56 = - V_158 ;
goto V_236;
}
V_7 -> V_75 = F_50 ( sizeof( * V_7 -> V_75 ) , V_226 ) ;
if ( ! V_7 -> V_75 ) {
V_56 = - V_158 ;
goto V_236;
}
F_89 ( & V_7 -> V_110 ) ;
V_7 -> V_3 = F_50 ( sizeof( * V_7 -> V_3 ) , V_226 ) ;
if ( ! V_7 -> V_3 ) {
V_56 = - V_158 ;
goto V_236;
}
V_56 = F_12 ( V_2 , V_7 -> V_3 ) ;
if ( V_56 < 0 ) {
V_235 = L_35 ;
goto V_236;
} else if ( V_7 -> V_3 -> V_85 > V_237 ) {
V_235 = L_36 ;
V_56 = - V_137 ;
goto V_236;
}
V_2 -> V_12 = V_7 -> V_3 -> V_85 ;
F_90 ( V_231 , L_37 , V_2 -> V_12 ,
( V_2 -> V_12 == 1 ) ? L_38 : L_39 ) ;
V_7 -> V_175 = F_84 ( V_2 -> V_12 * sizeof( struct V_223 * ) ,
V_226 ) ;
if ( ! V_7 -> V_175 ) {
V_56 = - V_158 ;
goto V_236;
}
V_169 = F_29 ( V_7 -> V_3 -> V_169 ) ;
if ( ( V_169 & V_238 ) &&
! ( F_1 ( V_2 ) ) ) {
int V_55 ;
char V_239 [ V_237 + 1 ] ;
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; V_55 ++ )
V_239 [ V_55 ] = V_7 -> V_3 -> V_34 . V_240 . V_241
[ ( ( V_55 + 1 ) / 8 ) ] & ( 1 << ( ( V_55 + 1 ) % 8 ) )
? 'F' : 'R' ;
V_239 [ V_2 -> V_12 ] = 0 ;
F_20 ( V_231 , L_40 , V_239 ) ;
} else
F_20 ( V_231 , L_41 ) ;
switch ( V_169 & V_170 ) {
case V_242 :
F_20 ( V_231 , L_42 ) ;
break;
case V_243 :
F_20 ( V_231 , L_43 ) ;
break;
case V_244 :
case V_170 :
F_20 ( V_231 , L_44 ) ;
break;
}
switch ( V_169 & V_245 ) {
case V_246 :
F_20 ( V_231 , L_45 ) ;
break;
case V_247 :
F_20 ( V_231 , L_46 ) ;
break;
case V_248 :
case V_245 :
F_20 ( V_231 , L_47 ) ;
break;
}
F_91 ( & V_7 -> V_140 . V_144 ) ;
F_92 ( & V_7 -> V_140 . V_145 ) ;
F_93 ( & V_7 -> V_140 . V_142 , F_45 ) ;
switch ( V_2 -> V_3 . V_4 ) {
case V_249 :
break;
case V_250 :
F_20 ( V_231 , L_48 ) ;
V_7 -> V_140 . V_7 = V_2 ;
break;
case V_251 :
V_56 = F_94 ( V_2 , 0 , 1 ) ;
if ( V_56 == 0 ) {
F_20 ( V_231 , L_49 ) ;
V_7 -> V_140 . V_159 = 1 ;
} else
F_28 ( V_231 , L_50 ,
V_56 ) ;
V_7 -> V_140 . V_7 = V_2 ;
break;
case V_5 :
break;
default:
F_20 ( V_231 , L_51 ,
V_2 -> V_3 . V_4 ) ;
break;
}
switch ( V_169 & V_252 ) {
case V_253 :
if ( V_2 -> V_3 . V_4 != 0 ) {
V_7 -> V_140 . V_254 = 666 ;
F_20 ( V_231 , L_52
L_53 ,
8 , V_7 -> V_140 . V_254 ) ;
}
break;
case V_255 :
V_7 -> V_140 . V_254 = 666 * 2 ;
F_20 ( V_231 , L_52
L_53 ,
16 , V_7 -> V_140 . V_254 ) ;
break;
case V_256 :
V_7 -> V_140 . V_254 = 666 * 3 ;
F_20 ( V_231 , L_52
L_53 ,
24 , V_7 -> V_140 . V_254 ) ;
break;
case V_257 :
V_7 -> V_140 . V_254 = 666 * 4 ;
F_20 ( V_231 , L_52
L_53 ,
32 , V_7 -> V_140 . V_254 ) ;
break;
}
if ( V_169 & V_258 ) {
V_7 -> V_216 = 1 ;
F_20 ( V_231 , L_54 ) ;
}
F_20 ( V_231 , L_55 ,
V_7 -> V_3 -> V_167 * 2 ) ;
V_56 = F_95 ( V_2 , V_259 , 0 , & V_232 ) ;
if ( V_56 < 2 ) {
V_235 = L_56 ;
goto V_236;
}
F_96 ( & V_232 ) ;
if ( V_2 == V_2 -> V_164 -> V_260 ) {
if ( V_2 -> V_261 == 0 || V_2 -> V_261 >= 500 )
V_7 -> V_262 = 500 ;
else {
V_7 -> V_262 = V_2 -> V_261 ;
V_7 -> V_263 = 1 ;
}
} else if ( ( V_232 & ( 1 << V_264 ) ) == 0 ) {
F_20 ( V_231 , L_57 ,
V_7 -> V_3 -> V_265 ) ;
V_7 -> V_263 = 1 ;
if ( V_2 -> V_12 > 0 ) {
int V_266 = V_2 -> V_261 -
V_7 -> V_3 -> V_265 ;
if ( V_266 < V_2 -> V_12 * 100 )
F_7 ( V_231 ,
L_58
L_59 ) ;
V_7 -> V_262 = 100 ;
}
} else {
V_7 -> V_262 = 500 ;
}
if ( V_7 -> V_262 < 500 )
F_20 ( V_231 , L_60 ,
V_7 -> V_262 ) ;
V_152 = F_54 ( V_2 -> V_164 ) ;
if ( V_152 -> V_153 -> V_198 ) {
V_56 = V_152 -> V_153 -> V_198 ( V_152 , V_2 ,
& V_7 -> V_140 , V_226 ) ;
if ( V_56 < 0 ) {
V_235 = L_61 ;
goto V_236;
}
}
V_56 = F_59 ( V_7 , & V_232 , & V_233 ) ;
if ( V_56 < 0 ) {
V_235 = L_56 ;
goto V_236;
}
if ( V_2 -> V_11 -> V_267 . V_20 & V_268 )
F_20 ( V_231 , L_62 ,
( V_232 & V_269 )
? L_63 : L_64 ) ;
if ( ( V_169 & V_245 ) == 0 )
F_20 ( V_231 , L_65 ,
( V_232 & V_270 ) ? L_38 : L_66 ) ;
V_156 = F_97 ( V_2 , V_230 -> V_271 ) ;
V_234 = F_98 ( V_2 , V_156 , F_99 ( V_156 ) ) ;
if ( V_234 > sizeof( * V_7 -> V_134 ) )
V_234 = sizeof( * V_7 -> V_134 ) ;
V_7 -> V_125 = F_100 ( 0 , V_226 ) ;
if ( ! V_7 -> V_125 ) {
V_56 = - V_158 ;
goto V_236;
}
F_101 ( V_7 -> V_125 , V_2 , V_156 , * V_7 -> V_134 , V_234 , F_42 ,
V_7 , V_230 -> V_272 ) ;
if ( V_7 -> V_216 && V_100 )
V_7 -> V_87 [ 0 ] = V_88 ;
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; V_55 ++ )
if ( F_83 ( V_7 , V_55 + 1 ) < 0 )
F_28 ( V_7 -> V_112 ,
L_67 , V_55 + 1 ) ;
F_66 ( V_7 , V_194 ) ;
return 0 ;
V_236:
F_28 ( V_231 , L_68 ,
V_235 , V_56 ) ;
return V_56 ;
}
static void F_102 ( struct V_273 * V_273 )
{
struct V_6 * V_7 = F_22 ( V_273 , struct V_6 , V_273 ) ;
F_103 ( F_36 ( V_7 -> V_112 ) ) ;
F_48 ( V_7 ) ;
}
static void F_104 ( struct V_180 * V_181 )
{
struct V_6 * V_7 = F_4 ( V_181 ) ;
struct V_1 * V_2 = F_105 ( V_181 ) ;
int V_55 ;
F_106 ( & V_118 ) ;
if ( ! F_33 ( & V_7 -> V_120 ) ) {
F_107 ( & V_7 -> V_120 ) ;
F_108 ( V_181 ) ;
}
V_7 -> V_119 = 1 ;
F_109 ( & V_118 ) ;
V_7 -> error = 0 ;
F_72 ( V_7 , V_274 ) ;
F_110 ( V_181 , NULL ) ;
for ( V_55 = 0 ; V_55 < V_2 -> V_12 ; V_55 ++ )
F_81 ( V_7 , V_55 + 1 ) ;
V_7 -> V_2 -> V_12 = 0 ;
if ( V_7 -> V_2 -> V_15 == V_16 )
V_275 -- ;
F_111 ( V_7 -> V_125 ) ;
F_48 ( V_7 -> V_175 ) ;
F_48 ( V_7 -> V_3 ) ;
F_48 ( V_7 -> V_75 ) ;
F_48 ( V_7 -> V_134 ) ;
F_112 ( & V_7 -> V_273 , F_102 ) ;
}
static int F_113 ( struct V_180 * V_181 , const struct V_276 * V_277 )
{
struct V_278 * V_267 ;
struct V_229 * V_230 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
V_267 = V_181 -> V_279 ;
V_2 = F_105 ( V_181 ) ;
F_114 ( V_2 ) ;
if ( V_2 -> V_192 == V_280 ) {
F_28 ( & V_181 -> V_22 ,
L_69 ) ;
return - V_281 ;
}
#ifdef F_115
if ( V_2 -> V_23 ) {
F_7 ( & V_181 -> V_22 , L_70 ) ;
return - V_137 ;
}
#endif
if ( ( V_267 -> V_267 . V_282 != 0 ) &&
( V_267 -> V_267 . V_282 != 1 ) ) {
V_283:
F_28 ( & V_181 -> V_22 , L_71 ) ;
return - V_114 ;
}
if ( V_267 -> V_267 . V_284 != 1 )
goto V_283;
V_230 = & V_267 -> V_230 [ 0 ] . V_267 ;
if ( ! F_116 ( V_230 ) )
goto V_283;
F_90 ( & V_181 -> V_22 , L_72 ) ;
V_7 = F_84 ( sizeof( * V_7 ) , V_226 ) ;
if ( ! V_7 ) {
F_20 ( & V_181 -> V_22 , L_73 ) ;
return - V_158 ;
}
F_117 ( & V_7 -> V_273 ) ;
F_92 ( & V_7 -> V_120 ) ;
V_7 -> V_112 = & V_181 -> V_22 ;
V_7 -> V_2 = V_2 ;
F_118 ( & V_7 -> V_79 , F_21 ) ;
F_118 ( & V_7 -> V_195 , NULL ) ;
F_119 ( V_181 ) ;
F_110 ( V_181 , V_7 ) ;
V_181 -> V_285 = 1 ;
if ( V_2 -> V_15 == V_16 )
V_275 ++ ;
if ( F_88 ( V_7 , V_230 ) >= 0 )
return 0 ;
F_104 ( V_181 ) ;
return - V_137 ;
}
static int
F_120 ( struct V_180 * V_181 , unsigned int V_286 , void * V_287 )
{
struct V_1 * V_2 = F_105 ( V_181 ) ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
switch ( V_286 ) {
case V_288 : {
struct V_289 * V_290 = V_287 ;
int V_55 ;
F_106 ( & V_291 ) ;
if ( V_2 -> V_161 <= 0 )
V_290 -> V_292 = 0 ;
else {
V_290 -> V_292 = V_2 -> V_12 ;
for ( V_55 = 0 ; V_55 < V_290 -> V_292 ; V_55 ++ ) {
if ( V_7 -> V_175 [ V_55 ] -> V_176 == NULL )
V_290 -> V_111 [ V_55 ] = 0 ;
else
V_290 -> V_111 [ V_55 ] =
V_7 -> V_175 [ V_55 ] -> V_176 -> V_161 ;
}
}
F_109 ( & V_291 ) ;
return V_290 -> V_292 + 1 ;
}
default:
return - V_293 ;
}
}
static int F_121 ( struct V_1 * V_2 , unsigned V_71 ,
struct V_294 * * * V_295 )
{
if ( V_2 -> V_82 == V_177 )
return - V_137 ;
if ( V_71 == 0 || V_71 > V_2 -> V_12 )
return - V_68 ;
* V_295 = & ( F_3 ( V_2 ) -> V_175 [ V_71 - 1 ] -> V_296 ) ;
return 0 ;
}
int F_122 ( struct V_1 * V_2 , unsigned V_71 ,
struct V_294 * V_297 )
{
int V_298 ;
struct V_294 * * V_299 ;
V_298 = F_121 ( V_2 , V_71 , & V_299 ) ;
if ( V_298 )
return V_298 ;
if ( * V_299 )
return - V_300 ;
* V_299 = V_297 ;
return V_298 ;
}
int F_123 ( struct V_1 * V_2 , unsigned V_71 ,
struct V_294 * V_297 )
{
int V_298 ;
struct V_294 * * V_299 ;
V_298 = F_121 ( V_2 , V_71 , & V_299 ) ;
if ( V_298 )
return V_298 ;
if ( * V_299 != V_297 )
return - V_128 ;
* V_299 = NULL ;
return V_298 ;
}
void F_124 ( struct V_1 * V_2 , struct V_294 * V_297 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
int V_301 ;
for ( V_301 = 0 ; V_301 < V_2 -> V_12 ; V_301 ++ ) {
if ( V_7 -> V_175 [ V_301 ] -> V_296 == V_297 )
V_7 -> V_175 [ V_301 ] -> V_296 = NULL ;
}
}
bool F_125 ( struct V_1 * V_14 )
{
struct V_6 * V_7 ;
if ( V_14 -> V_82 == V_177 || ! V_14 -> V_23 )
return false ;
V_7 = F_3 ( V_14 -> V_23 ) ;
return ! ! V_7 -> V_175 [ V_14 -> V_123 - 1 ] -> V_296 ;
}
static void F_126 ( struct V_1 * V_14 )
{
struct V_6 * V_7 = F_3 ( V_14 ) ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_14 -> V_12 ; ++ V_55 ) {
if ( V_7 -> V_175 [ V_55 ] -> V_176 )
F_126 ( V_7 -> V_175 [ V_55 ] -> V_176 ) ;
}
if ( V_14 -> V_82 == V_302 )
V_14 -> V_303 -= V_304 ;
V_14 -> V_82 = V_177 ;
}
void F_61 ( struct V_1 * V_14 ,
enum V_305 V_306 )
{
unsigned long V_117 ;
int V_307 = - 1 ;
F_32 ( & V_291 , V_117 ) ;
if ( V_14 -> V_82 == V_177 )
;
else if ( V_306 != V_177 ) {
if ( V_14 -> V_23 ) {
if ( V_14 -> V_82 == V_302
|| V_306 == V_302 )
;
else if ( V_306 == V_83 )
V_307 = V_14 -> V_11 -> V_267 . V_20
& V_308 ;
else
V_307 = 0 ;
}
if ( V_14 -> V_82 == V_302 &&
V_306 != V_302 )
V_14 -> V_303 -= V_304 ;
else if ( V_306 == V_302 &&
V_14 -> V_82 != V_302 )
V_14 -> V_303 += V_304 ;
V_14 -> V_82 = V_306 ;
} else
F_126 ( V_14 ) ;
F_38 ( & V_291 , V_117 ) ;
if ( V_307 >= 0 )
F_127 ( & V_14 -> V_22 , V_307 ) ;
}
static void F_128 ( struct V_1 * V_14 )
{
int V_161 ;
struct V_309 * V_164 = V_14 -> V_164 ;
if ( V_14 -> V_310 ) {
V_161 = V_14 -> V_123 + 1 ;
F_129 ( F_130 ( V_161 , V_164 -> V_311 . V_312 ) ) ;
} else {
V_161 = F_131 ( V_164 -> V_311 . V_312 , 128 ,
V_164 -> V_313 ) ;
if ( V_161 >= 128 )
V_161 = F_131 ( V_164 -> V_311 . V_312 ,
128 , 1 ) ;
V_164 -> V_313 = ( V_161 >= 127 ? 1 : V_161 + 1 ) ;
}
if ( V_161 < 128 ) {
F_41 ( V_161 , V_164 -> V_311 . V_312 ) ;
V_14 -> V_161 = V_161 ;
}
}
static void F_132 ( struct V_1 * V_14 )
{
if ( V_14 -> V_161 > 0 ) {
F_69 ( V_14 -> V_161 , V_14 -> V_164 -> V_311 . V_312 ) ;
V_14 -> V_161 = - 1 ;
}
}
static void F_133 ( struct V_1 * V_14 , int V_161 )
{
if ( ! V_14 -> V_310 )
V_14 -> V_161 = V_161 ;
}
static void F_134 ( struct V_1 * V_14 )
{
struct V_184 * V_152 = F_54 ( V_14 -> V_164 ) ;
if ( V_152 -> V_153 -> V_314 && V_14 -> V_23 )
V_152 -> V_153 -> V_314 ( V_152 , V_14 ) ;
}
void F_74 ( struct V_1 * * V_315 )
{
struct V_1 * V_14 = * V_315 ;
struct V_6 * V_7 = F_3 ( V_14 ) ;
int V_55 ;
F_61 ( V_14 , V_177 ) ;
F_90 ( & V_14 -> V_22 , L_74 ,
V_14 -> V_161 ) ;
F_135 ( V_14 ) ;
for ( V_55 = 0 ; V_55 < V_14 -> V_12 ; V_55 ++ ) {
if ( V_7 -> V_175 [ V_55 ] -> V_176 )
F_74 ( & V_7 -> V_175 [ V_55 ] -> V_176 ) ;
}
F_20 ( & V_14 -> V_22 , L_75 ) ;
F_136 ( V_14 , 0 ) ;
F_137 ( V_14 ) ;
F_138 ( & V_14 -> V_316 ) ;
F_139 ( V_14 ) ;
F_140 ( & V_14 -> V_22 ) ;
F_132 ( V_14 ) ;
F_106 ( & V_291 ) ;
* V_315 = NULL ;
F_109 ( & V_291 ) ;
F_134 ( V_14 ) ;
F_87 ( & V_14 -> V_22 ) ;
}
static void F_141 ( struct V_1 * V_14 , char * V_277 , char * string )
{
if ( ! string )
return;
F_142 ( V_317 , & V_14 -> V_22 , L_76 , V_277 , string ) ;
}
static void F_143 ( struct V_1 * V_14 )
{
F_90 ( & V_14 -> V_22 , L_77 ,
F_29 ( V_14 -> V_3 . V_318 ) ,
F_29 ( V_14 -> V_3 . V_319 ) ) ;
F_90 ( & V_14 -> V_22 ,
L_78 ,
V_14 -> V_3 . V_320 ,
V_14 -> V_3 . V_321 ,
V_14 -> V_3 . V_322 ) ;
F_141 ( V_14 , L_79 , V_14 -> V_323 ) ;
F_141 ( V_14 , L_80 , V_14 -> V_324 ) ;
F_141 ( V_14 , L_81 , V_14 -> V_325 ) ;
}
static inline void F_143 ( struct V_1 * V_14 ) { }
static int F_144 ( struct V_1 * V_14 )
{
int V_326 = 0 ;
#ifdef F_145
if ( ! V_14 -> V_164 -> V_327
&& V_14 -> V_328
&& V_14 -> V_23 == V_14 -> V_164 -> V_260 ) {
struct V_329 * V_267 = NULL ;
struct V_309 * V_164 = V_14 -> V_164 ;
if ( F_146 ( V_14 -> V_330 [ 0 ] ,
F_29 ( V_14 -> V_328 [ 0 ] . V_267 . V_331 ) ,
V_332 , ( void * * ) & V_267 ) == 0 ) {
if ( V_267 -> V_20 & V_333 ) {
unsigned V_71 = V_14 -> V_123 ;
F_90 ( & V_14 -> V_22 ,
L_82 ,
( V_71 == V_164 -> V_334 )
? L_38 : L_83 ) ;
if ( V_71 == V_164 -> V_334 )
V_164 -> V_335 = 1 ;
V_326 = F_13 ( V_14 ,
F_16 ( V_14 , 0 ) ,
V_73 , 0 ,
V_164 -> V_335
? V_336
: V_337 ,
0 , NULL , 0 , V_193 ) ;
if ( V_326 < 0 ) {
F_90 ( & V_14 -> V_22 ,
L_84 ,
V_326 ) ;
V_164 -> V_335 = 0 ;
}
}
}
}
if ( ! F_147 ( V_14 ) ) {
if ( V_14 -> V_164 -> V_335 || V_14 -> V_164 -> V_327 ) {
V_326 = F_148 ( V_14 , V_338 ) ;
if ( V_326 < 0 )
F_20 ( & V_14 -> V_22 , L_85 , V_326 ) ;
}
V_326 = - V_339 ;
goto V_236;
}
V_236:
#endif
return V_326 ;
}
static int F_149 ( struct V_1 * V_14 )
{
int V_326 ;
if ( V_14 -> V_328 == NULL ) {
V_326 = F_150 ( V_14 ) ;
if ( V_326 < 0 ) {
F_28 ( & V_14 -> V_22 , L_86 ,
V_326 ) ;
return V_326 ;
}
}
if ( V_14 -> V_310 == 1 && V_14 -> V_340 == 0 ) {
V_14 -> V_323 = F_151 ( L_87 , V_226 ) ;
V_14 -> V_324 = F_151 ( L_87 , V_226 ) ;
V_14 -> V_325 = F_151 ( L_87 , V_226 ) ;
}
else {
V_14 -> V_323 = F_152 ( V_14 , V_14 -> V_3 . V_321 ) ;
V_14 -> V_324 = F_152 ( V_14 ,
V_14 -> V_3 . V_320 ) ;
V_14 -> V_325 = F_152 ( V_14 , V_14 -> V_3 . V_322 ) ;
}
V_326 = F_144 ( V_14 ) ;
if ( V_326 < 0 )
return V_326 ;
F_153 ( V_14 ) ;
return 0 ;
}
static void F_154 ( struct V_1 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_23 ;
struct V_6 * V_7 ;
T_2 V_111 = V_14 -> V_123 ;
T_1 V_169 ;
bool V_341 = true ;
if ( ! V_2 )
return;
V_7 = F_3 ( V_14 -> V_23 ) ;
V_169 = F_29 ( V_7 -> V_3 -> V_169 ) ;
if ( ! ( V_169 & V_238 ) )
return;
if ( F_1 ( V_2 ) ) {
if ( F_29 ( V_7 -> V_3 -> V_34 . V_35 . V_241 )
& ( 1 << V_111 ) )
V_341 = false ;
} else {
if ( V_7 -> V_3 -> V_34 . V_240 . V_241 [ V_111 / 8 ] & ( 1 << ( V_111 % 8 ) ) )
V_341 = false ;
}
if ( V_341 )
V_14 -> V_341 = V_342 ;
else
V_14 -> V_341 = V_343 ;
}
int F_155 ( struct V_1 * V_14 )
{
int V_326 ;
if ( V_14 -> V_23 ) {
F_156 ( & V_14 -> V_22 , 0 ) ;
}
F_157 ( & V_14 -> V_22 ) ;
F_158 ( & V_14 -> V_22 ) ;
F_159 ( & V_14 -> V_22 ) ;
F_160 ( & V_14 -> V_22 ) ;
F_161 ( V_14 ) ;
V_326 = F_149 ( V_14 ) ;
if ( V_326 < 0 )
goto V_236;
F_20 ( & V_14 -> V_22 , L_88 ,
V_14 -> V_161 , V_14 -> V_164 -> V_344 ,
( ( ( V_14 -> V_164 -> V_344 - 1 ) * 128 ) + ( V_14 -> V_161 - 1 ) ) ) ;
V_14 -> V_22 . V_345 = F_162 ( V_346 ,
( ( ( V_14 -> V_164 -> V_344 - 1 ) * 128 ) + ( V_14 -> V_161 - 1 ) ) ) ;
F_143 ( V_14 ) ;
if ( V_14 -> V_325 )
F_163 ( V_14 -> V_325 , strlen ( V_14 -> V_325 ) ) ;
if ( V_14 -> V_323 )
F_163 ( V_14 -> V_323 , strlen ( V_14 -> V_323 ) ) ;
if ( V_14 -> V_324 )
F_163 ( V_14 -> V_324 ,
strlen ( V_14 -> V_324 ) ) ;
F_164 ( & V_14 -> V_22 ) ;
if ( V_14 -> V_23 )
F_154 ( V_14 ) ;
V_326 = F_165 ( & V_14 -> V_22 ) ;
if ( V_326 ) {
F_28 ( & V_14 -> V_22 , L_89 , V_326 ) ;
goto V_236;
}
( void ) F_166 ( & V_14 -> V_22 , & V_14 -> V_316 , V_14 ) ;
F_167 ( V_14 ) ;
F_168 ( & V_14 -> V_22 ) ;
return V_326 ;
V_236:
F_61 ( V_14 , V_177 ) ;
F_169 ( & V_14 -> V_22 ) ;
F_170 ( & V_14 -> V_22 ) ;
return V_326 ;
}
int F_171 ( struct V_1 * V_347 )
{
F_135 ( V_347 ) ;
if ( V_347 -> V_340 == 0 )
goto V_348;
V_347 -> V_340 = 0 ;
F_172 ( V_347 , - 1 ) ;
F_48 ( V_347 -> V_323 ) ;
V_347 -> V_323 = F_151 ( L_87 , V_226 ) ;
F_48 ( V_347 -> V_324 ) ;
V_347 -> V_324 = F_151 ( L_87 , V_226 ) ;
F_48 ( V_347 -> V_325 ) ;
V_347 -> V_325 = F_151 ( L_87 , V_226 ) ;
F_173 ( V_347 ) ;
V_347 -> V_3 . V_349 = 0 ;
V_348:
F_139 ( V_347 ) ;
return 0 ;
}
int F_174 ( struct V_1 * V_347 )
{
int V_350 = 0 , V_351 ;
F_135 ( V_347 ) ;
if ( V_347 -> V_340 == 1 )
goto V_352;
V_350 = F_175 ( V_347 ) ;
if ( V_350 < 0 ) {
F_28 ( & V_347 -> V_22 ,
L_90 , V_350 ) ;
goto V_353;
}
V_350 = F_176 ( V_347 , sizeof( V_347 -> V_3 ) ) ;
if ( V_350 < 0 ) {
F_28 ( & V_347 -> V_22 , L_91
L_92 , V_350 ) ;
goto V_354;
}
F_48 ( V_347 -> V_323 ) ;
V_347 -> V_323 = NULL ;
F_48 ( V_347 -> V_324 ) ;
V_347 -> V_324 = NULL ;
F_48 ( V_347 -> V_325 ) ;
V_347 -> V_325 = NULL ;
V_347 -> V_340 = 1 ;
V_350 = F_149 ( V_347 ) ;
if ( V_350 < 0 )
goto V_355;
V_351 = F_177 ( V_347 ) ;
if ( V_351 >= 0 ) {
V_350 = F_172 ( V_347 , V_351 ) ;
if ( V_350 ) {
F_28 ( & V_347 -> V_22 ,
L_93 , V_351 , V_350 ) ;
}
}
F_90 ( & V_347 -> V_22 , L_94 ) ;
V_355:
V_354:
F_178 ( V_347 ) ;
V_353:
V_352:
F_139 ( V_347 ) ;
return V_350 ;
}
static unsigned F_179 ( struct V_6 * V_7 )
{
struct V_184 * V_152 ;
if ( V_7 -> V_2 -> V_23 != NULL )
return 0 ;
V_152 = F_22 ( V_7 -> V_2 -> V_164 , struct V_184 , V_356 ) ;
return V_152 -> V_357 ;
}
static bool F_180 ( struct V_6 * V_7 , T_1 V_8 )
{
return F_1 ( V_7 -> V_2 ) &&
( ( ( V_8 & V_210 ) ==
V_358 ) ||
( ( V_8 & V_210 ) ==
V_359 ) ) ;
}
static int F_181 ( struct V_6 * V_7 , int V_71 ,
struct V_1 * V_14 , unsigned int V_168 , bool V_360 )
{
int V_361 , V_56 ;
T_1 V_8 ;
T_1 V_200 ;
for ( V_361 = 0 ;
V_361 < V_362 ;
V_361 += V_168 ) {
F_58 ( V_168 ) ;
V_56 = F_26 ( V_7 , V_71 , & V_8 , & V_200 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( ! V_360 ) {
if ( F_180 ( V_7 , V_8 ) ) {
int V_56 ;
if ( ( V_200 & V_203 ) )
F_17 ( V_7 -> V_2 , V_71 ,
V_204 ) ;
if ( V_200 & V_363 )
F_17 ( V_7 -> V_2 , V_71 ,
V_364 ) ;
if ( V_200 & V_365 )
F_17 ( V_7 -> V_2 , V_71 ,
V_366 ) ;
F_20 ( V_7 -> V_112 , L_95 ,
V_71 ) ;
V_56 = F_182 ( V_7 , V_71 ,
V_14 , V_367 ,
true ) ;
if ( ( V_200 & V_203 ) )
F_17 ( V_7 -> V_2 , V_71 ,
V_204 ) ;
return V_56 ;
}
if ( ! ( V_8 & V_201 ) )
return - V_368 ;
if ( ( V_200 & V_203 ) )
return - V_368 ;
if ( ! ( V_8 & V_369 ) &&
( V_8 & V_202 ) ) {
if ( F_179 ( V_7 ) )
V_14 -> V_15 = V_370 ;
else if ( F_1 ( V_7 -> V_2 ) )
V_14 -> V_15 = V_49 ;
else if ( V_8 & V_9 )
V_14 -> V_15 = V_16 ;
else if ( V_8 & V_10 )
V_14 -> V_15 = V_371 ;
else
V_14 -> V_15 = V_372 ;
return 0 ;
}
} else {
if ( V_200 & V_207 )
return 0 ;
}
if ( V_361 >= 2 * V_373 )
V_168 = V_374 ;
F_20 ( V_7 -> V_112 ,
L_96 ,
V_71 , V_360 ? L_97 : L_38 , V_168 ) ;
}
return - V_300 ;
}
static void F_183 ( struct V_6 * V_7 , int V_71 ,
struct V_1 * V_14 , int * V_75 , bool V_360 )
{
switch ( * V_75 ) {
case 0 :
if ( ! V_360 ) {
struct V_184 * V_152 ;
F_58 ( 10 + 40 ) ;
F_133 ( V_14 , 0 ) ;
V_152 = F_54 ( V_14 -> V_164 ) ;
if ( V_152 -> V_153 -> V_375 ) {
* V_75 = V_152 -> V_153 -> V_375 ( V_152 , V_14 ) ;
if ( * V_75 < 0 ) {
F_28 ( & V_14 -> V_22 , L_98
L_99 ) ;
break;
}
}
}
case - V_368 :
case - V_137 :
F_17 ( V_7 -> V_2 ,
V_71 , V_366 ) ;
if ( V_360 ) {
F_17 ( V_7 -> V_2 , V_71 ,
V_208 ) ;
F_17 ( V_7 -> V_2 , V_71 ,
V_364 ) ;
} else {
F_61 ( V_14 , * V_75
? V_177
: V_376 ) ;
}
break;
}
}
static int F_182 ( struct V_6 * V_7 , int V_71 ,
struct V_1 * V_14 , unsigned int V_168 , bool V_360 )
{
int V_55 , V_75 ;
if ( ! V_360 ) {
F_184 ( & V_377 ) ;
} else {
if ( ! F_1 ( V_7 -> V_2 ) ) {
F_28 ( V_7 -> V_112 , L_100
L_101 ) ;
return - V_68 ;
}
}
for ( V_55 = 0 ; V_55 < V_378 ; V_55 ++ ) {
V_75 = F_18 ( V_7 -> V_2 , V_71 , ( V_360 ?
V_379 :
V_380 ) ) ;
if ( V_75 ) {
F_28 ( V_7 -> V_112 ,
L_102 ,
V_360 ? L_97 : L_38 , V_71 , V_75 ) ;
} else {
V_75 = F_181 ( V_7 , V_71 , V_14 , V_168 ,
V_360 ) ;
if ( V_75 && V_75 != - V_368 )
F_20 ( V_7 -> V_112 ,
L_103 ,
V_75 ) ;
}
if ( V_75 == 0 || V_75 == - V_368 || V_75 == - V_137 ) {
F_183 ( V_7 , V_71 , V_14 , & V_75 , V_360 ) ;
goto V_381;
}
F_20 ( V_7 -> V_112 ,
L_104 ,
V_71 , V_360 ? L_97 : L_38 ) ;
V_168 = V_374 ;
}
F_28 ( V_7 -> V_112 ,
L_105 ,
V_71 ) ;
V_381:
if ( ! V_360 )
F_185 ( & V_377 ) ;
return V_75 ;
}
static int F_186 ( struct V_6 * V_7 , unsigned V_8 )
{
int V_56 = 0 ;
if ( F_1 ( V_7 -> V_2 ) ) {
if ( V_8 & V_382 )
V_56 = 1 ;
} else {
if ( V_8 & V_383 )
V_56 = 1 ;
}
return V_56 ;
}
static int F_187 ( struct V_6 * V_7 , unsigned V_8 )
{
int V_56 = 0 ;
if ( F_1 ( V_7 -> V_2 ) ) {
if ( ( V_8 & V_210 )
== V_384 )
V_56 = 1 ;
} else {
if ( V_8 & V_385 )
V_56 = 1 ;
}
return V_56 ;
}
static int F_188 ( struct V_1 * V_14 ,
struct V_6 * V_7 , int V_71 ,
int V_75 , unsigned V_200 , unsigned V_8 )
{
if ( V_75 || F_187 ( V_7 , V_8 ) ||
! F_186 ( V_7 , V_8 ) ||
! ( V_8 & V_201 ) ) {
if ( V_75 >= 0 )
V_75 = - V_137 ;
}
else if ( ! ( V_8 & V_202 ) && ! V_14 -> V_213 ) {
if ( V_14 -> V_212 )
V_14 -> V_213 = 1 ;
else
V_75 = - V_137 ;
}
if ( V_75 ) {
F_20 ( V_7 -> V_112 ,
L_106 ,
V_71 , V_200 , V_8 , V_75 ) ;
} else if ( V_14 -> V_213 ) {
if ( V_200 & V_203 )
F_17 ( V_7 -> V_2 , V_71 ,
V_204 ) ;
if ( V_200 & V_205 )
F_17 ( V_7 -> V_2 , V_71 ,
V_206 ) ;
}
return V_75 ;
}
int F_189 ( struct V_1 * V_14 )
{
struct V_184 * V_152 = F_54 ( V_14 -> V_164 ) ;
if ( ! F_190 ( V_152 -> V_356 . V_260 ) ||
! F_190 ( V_14 ) )
return 0 ;
if ( ! V_14 -> V_11 )
return 0 ;
return F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_70 , V_259 ,
V_386 , 0 , NULL , 0 ,
V_193 ) ;
}
void F_191 ( struct V_1 * V_14 )
{
struct V_184 * V_152 = F_54 ( V_14 -> V_164 ) ;
if ( ! F_190 ( V_152 -> V_356 . V_260 ) ||
! F_190 ( V_14 ) )
return;
if ( ! V_14 -> V_11 )
return;
F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_73 , V_259 ,
V_386 , 0 , NULL , 0 ,
V_193 ) ;
}
int F_148 ( struct V_1 * V_14 , T_3 V_387 )
{
struct V_6 * V_7 = F_3 ( V_14 -> V_23 ) ;
int V_71 = V_14 -> V_123 ;
int V_75 ;
if ( V_14 -> V_388 ) {
if ( ! F_1 ( V_7 -> V_2 ) ) {
V_75 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_73 , V_259 ,
V_389 , 0 ,
NULL , 0 ,
V_193 ) ;
} else {
V_75 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_73 ,
V_390 ,
V_391 ,
V_392 |
V_393 ,
NULL , 0 ,
V_193 ) ;
}
if ( V_75 ) {
F_20 ( & V_14 -> V_22 , L_107 ,
V_75 ) ;
if ( F_192 ( V_387 ) )
return V_75 ;
}
}
if ( V_14 -> V_394 == 1 )
F_193 ( V_14 , 0 ) ;
if ( F_189 ( V_14 ) ) {
F_28 ( & V_14 -> V_22 , L_108 ,
V_113 ) ;
return - V_158 ;
}
if ( F_194 ( V_14 ) ) {
F_28 ( & V_14 -> V_22 , L_109 ,
V_113 ) ;
return - V_158 ;
}
if ( F_1 ( V_7 -> V_2 ) )
V_75 = F_18 ( V_7 -> V_2 ,
V_71 | ( V_384 << 3 ) ,
V_395 ) ;
else
V_75 = F_18 ( V_7 -> V_2 , V_71 ,
V_396 ) ;
if ( V_75 ) {
F_20 ( V_7 -> V_112 , L_110 ,
V_71 , V_75 ) ;
if ( V_14 -> V_388 )
( void ) F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_70 , V_259 ,
V_389 , 0 ,
NULL , 0 ,
V_193 ) ;
if ( V_14 -> V_397 == 1 )
F_193 ( V_14 , 1 ) ;
F_191 ( V_14 ) ;
F_195 ( V_14 ) ;
if ( ! F_192 ( V_387 ) )
V_75 = 0 ;
} else {
F_20 ( & V_14 -> V_22 , L_111 ,
( F_192 ( V_387 ) ? L_112 : L_38 ) ,
V_14 -> V_388 ) ;
F_61 ( V_14 , V_302 ) ;
F_58 ( 10 ) ;
}
F_167 ( V_7 -> V_2 ) ;
return V_75 ;
}
static int F_196 ( struct V_1 * V_14 )
{
int V_75 = 0 ;
T_1 V_398 ;
F_20 ( & V_14 -> V_22 , L_113 ,
V_14 -> V_213 ? L_114 : L_115 ) ;
F_61 ( V_14 , V_14 -> V_11
? V_83
: V_399 ) ;
if ( V_14 -> V_213 )
V_400:
V_75 = F_197 ( V_14 ) ;
if ( V_75 == 0 ) {
V_398 = 0 ;
V_75 = F_95 ( V_14 , V_259 , 0 , & V_398 ) ;
if ( V_75 >= 0 )
V_75 = ( V_75 > 0 ? 0 : - V_137 ) ;
if ( V_75 && ! V_14 -> V_213 && V_14 -> V_212 ) {
F_20 ( & V_14 -> V_22 , L_116 ) ;
V_14 -> V_213 = 1 ;
goto V_400;
}
}
if ( V_75 ) {
F_20 ( & V_14 -> V_22 , L_117 ,
V_75 ) ;
} else if ( V_14 -> V_11 ) {
F_96 ( & V_398 ) ;
if ( V_398 & ( 1 << V_389 ) ) {
V_75 = F_13 ( V_14 ,
F_16 ( V_14 , 0 ) ,
V_70 ,
V_259 ,
V_389 , 0 ,
NULL , 0 ,
V_193 ) ;
if ( V_75 )
F_20 ( & V_14 -> V_22 ,
L_118 ,
V_75 ) ;
}
V_75 = 0 ;
}
return V_75 ;
}
int F_198 ( struct V_1 * V_14 , T_3 V_387 )
{
struct V_6 * V_7 = F_3 ( V_14 -> V_23 ) ;
int V_71 = V_14 -> V_123 ;
int V_75 ;
T_1 V_200 , V_8 ;
V_75 = F_26 ( V_7 , V_71 , & V_8 , & V_200 ) ;
if ( V_75 == 0 && ! F_187 ( V_7 , V_8 ) )
goto V_401;
F_41 ( V_71 , V_7 -> V_402 ) ;
if ( F_1 ( V_7 -> V_2 ) )
V_75 = F_18 ( V_7 -> V_2 ,
V_71 | ( V_211 << 3 ) ,
V_395 ) ;
else
V_75 = F_17 ( V_7 -> V_2 ,
V_71 , V_396 ) ;
if ( V_75 ) {
F_20 ( V_7 -> V_112 , L_119 ,
V_71 , V_75 ) ;
} else {
F_20 ( & V_14 -> V_22 , L_120 ,
( F_192 ( V_387 ) ? L_112 : L_38 ) ) ;
F_58 ( 25 ) ;
V_75 = F_26 ( V_7 , V_71 , & V_8 , & V_200 ) ;
F_58 ( 10 ) ;
}
V_401:
if ( V_75 == 0 ) {
if ( F_1 ( V_7 -> V_2 ) ) {
if ( V_200 & V_363 )
F_17 ( V_7 -> V_2 , V_71 ,
V_364 ) ;
} else {
if ( V_200 & V_403 )
F_17 ( V_7 -> V_2 , V_71 ,
V_404 ) ;
}
}
F_69 ( V_71 , V_7 -> V_402 ) ;
V_75 = F_188 ( V_14 ,
V_7 , V_71 , V_75 , V_200 , V_8 ) ;
if ( V_75 == 0 )
V_75 = F_196 ( V_14 ) ;
if ( V_75 < 0 ) {
F_20 ( & V_14 -> V_22 , L_121 , V_75 ) ;
F_62 ( V_7 , V_71 ) ;
} else {
if ( V_14 -> V_397 == 1 )
F_193 ( V_14 , 1 ) ;
F_191 ( V_14 ) ;
F_195 ( V_14 ) ;
}
return V_75 ;
}
int F_199 ( struct V_1 * V_14 )
{
int V_75 = 0 ;
if ( V_14 -> V_82 == V_302 ) {
F_20 ( & V_14 -> V_22 , L_120 , L_122 ) ;
V_75 = F_175 ( V_14 ) ;
if ( V_75 == 0 ) {
F_178 ( V_14 ) ;
}
}
return V_75 ;
}
int F_148 ( struct V_1 * V_14 , T_3 V_387 )
{
return 0 ;
}
int F_198 ( struct V_1 * V_14 , T_3 V_387 )
{
struct V_6 * V_7 = F_3 ( V_14 -> V_23 ) ;
int V_71 = V_14 -> V_123 ;
int V_75 ;
T_1 V_200 , V_8 ;
V_75 = F_26 ( V_7 , V_71 , & V_8 , & V_200 ) ;
V_75 = F_188 ( V_14 ,
V_7 , V_71 , V_75 , V_200 , V_8 ) ;
if ( V_75 ) {
F_20 ( & V_14 -> V_22 , L_121 , V_75 ) ;
F_62 ( V_7 , V_71 ) ;
} else if ( V_14 -> V_213 ) {
F_20 ( & V_14 -> V_22 , L_123 ) ;
V_75 = F_197 ( V_14 ) ;
}
return V_75 ;
}
static int F_200 ( struct V_180 * V_181 , T_3 V_387 )
{
struct V_6 * V_7 = F_4 ( V_181 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
unsigned V_71 ;
int V_75 ;
for ( V_71 = 1 ; V_71 <= V_2 -> V_12 ; V_71 ++ ) {
struct V_1 * V_14 ;
V_14 = V_7 -> V_175 [ V_71 - 1 ] -> V_176 ;
if ( V_14 && V_14 -> V_405 ) {
F_7 ( & V_181 -> V_22 , L_124 , V_71 ) ;
if ( F_192 ( V_387 ) )
return - V_300 ;
}
}
if ( F_1 ( V_2 ) && V_2 -> V_388 ) {
for ( V_71 = 1 ; V_71 <= V_2 -> V_12 ; V_71 ++ ) {
V_75 = F_18 ( V_2 ,
V_71 |
V_406 |
V_407 |
V_408 ,
V_409 ) ;
}
}
F_20 ( & V_181 -> V_22 , L_113 , V_113 ) ;
F_72 ( V_7 , V_219 ) ;
return 0 ;
}
static int F_201 ( struct V_180 * V_181 )
{
struct V_6 * V_7 = F_4 ( V_181 ) ;
F_20 ( & V_181 -> V_22 , L_113 , V_113 ) ;
F_66 ( V_7 , V_190 ) ;
return 0 ;
}
static int F_202 ( struct V_180 * V_181 )
{
struct V_6 * V_7 = F_4 ( V_181 ) ;
F_20 ( & V_181 -> V_22 , L_113 , V_113 ) ;
F_66 ( V_7 , V_197 ) ;
return 0 ;
}
void F_203 ( struct V_1 * V_410 )
{
F_7 ( & V_410 -> V_22 , L_125 ) ;
V_410 -> V_213 = 1 ;
}
static int F_204 ( struct V_1 * V_14 , enum V_411 V_82 )
{
struct V_412 * V_413 ;
unsigned long long V_414 ;
unsigned long long V_415 ;
unsigned long long V_416 ;
unsigned long long V_417 ;
int V_56 ;
V_414 = F_205 ( V_14 -> V_52 . V_43 , 1000 ) ;
V_415 = F_205 ( V_14 -> V_52 . V_40 , 1000 ) ;
V_416 = F_205 ( V_14 -> V_53 . V_43 , 1000 ) ;
V_417 = F_205 ( V_14 -> V_53 . V_40 , 1000 ) ;
if ( ( V_82 == V_418 &&
( V_414 > V_419 ||
V_415 > V_419 ) ) ||
( V_82 == V_420 &&
( V_416 > V_421 ||
V_417 > V_421 ) ) ) {
F_20 ( & V_14 -> V_22 , L_126 ,
V_422 [ V_82 ] , V_414 , V_415 ) ;
return - V_68 ;
}
if ( V_414 > V_419 )
V_414 = V_419 ;
if ( V_415 > V_419 )
V_415 = V_419 ;
if ( V_416 > V_421 )
V_416 = V_421 ;
if ( V_417 > V_421 )
V_417 = V_421 ;
V_413 = F_50 ( sizeof *( V_413 ) , V_199 ) ;
if ( ! V_413 )
return - V_158 ;
V_413 -> V_414 = V_414 ;
V_413 -> V_415 = V_415 ;
V_413 -> V_416 = F_206 ( V_416 ) ;
V_413 -> V_417 = F_206 ( V_417 ) ;
V_56 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_423 ,
V_259 ,
0 , 0 ,
V_413 , sizeof *( V_413 ) ,
V_193 ) ;
F_48 ( V_413 ) ;
return V_56 ;
}
static int F_207 ( struct V_1 * V_14 ,
enum V_411 V_82 , bool V_424 )
{
int V_56 ;
int V_69 ;
switch ( V_82 ) {
case V_418 :
V_69 = V_425 ;
break;
case V_420 :
V_69 = V_426 ;
break;
default:
F_7 ( & V_14 -> V_22 , L_127 ,
V_113 , V_424 ? L_128 : L_129 ) ;
return - V_68 ;
}
if ( V_14 -> V_82 != V_83 ) {
F_20 ( & V_14 -> V_22 , L_130
L_131 ,
V_113 , V_424 ? L_128 : L_129 ,
V_422 [ V_82 ] ) ;
return 0 ;
}
if ( V_424 ) {
V_56 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_73 ,
V_259 ,
V_69 ,
0 , NULL , 0 ,
V_193 ) ;
} else {
V_56 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_70 ,
V_259 ,
V_69 ,
0 , NULL , 0 ,
V_193 ) ;
}
if ( V_56 < 0 ) {
F_7 ( & V_14 -> V_22 , L_132 ,
V_424 ? L_133 : L_134 ,
V_422 [ V_82 ] ) ;
return - V_300 ;
}
return 0 ;
}
static int F_208 ( struct V_1 * V_14 ,
enum V_411 V_82 , int V_427 )
{
int V_56 ;
int V_69 ;
switch ( V_82 ) {
case V_418 :
V_69 = V_428 ;
break;
case V_420 :
V_69 = V_429 ;
break;
default:
F_7 ( & V_14 -> V_22 , L_135 ,
V_113 ) ;
return - V_68 ;
}
if ( V_82 == V_418 && V_427 > V_430 &&
V_427 != V_431 ) {
F_7 ( & V_14 -> V_22 , L_136
L_137 ,
V_422 [ V_82 ] , V_427 ) ;
return - V_68 ;
}
V_56 = F_18 ( V_14 -> V_23 ,
F_209 ( V_427 ) | V_14 -> V_123 ,
V_69 ) ;
if ( V_56 < 0 ) {
F_7 ( & V_14 -> V_22 , L_138
L_139 , V_422 [ V_82 ] ,
V_427 , V_56 ) ;
return - V_300 ;
}
if ( V_82 == V_418 )
V_14 -> V_52 . V_427 = V_427 ;
else
V_14 -> V_53 . V_427 = V_427 ;
return 0 ;
}
static void F_210 ( struct V_184 * V_152 , struct V_1 * V_14 ,
enum V_411 V_82 )
{
int V_427 , V_56 ;
T_4 V_432 = V_14 -> V_17 -> V_21 -> V_50 ;
T_5 V_433 = V_14 -> V_17 -> V_21 -> V_51 ;
if ( ( V_82 == V_418 && V_432 == 0 ) ||
( V_82 == V_420 && V_433 == 0 ) )
return;
V_56 = F_204 ( V_14 , V_82 ) ;
if ( V_56 < 0 ) {
F_7 ( & V_14 -> V_22 , L_140 ,
V_422 [ V_82 ] ) ;
return;
}
V_427 = V_152 -> V_153 -> V_434 ( V_152 , V_14 , V_82 ) ;
if ( V_427 == 0 )
return;
if ( V_427 < 0 ) {
F_7 ( & V_14 -> V_22 , L_141
L_142 , V_422 [ V_82 ] ,
V_427 ) ;
return;
}
if ( F_208 ( V_14 , V_82 , V_427 ) )
V_152 -> V_153 -> V_435 ( V_152 , V_14 , V_82 ) ;
else if ( V_14 -> V_11 )
F_207 ( V_14 , V_82 , true ) ;
}
static int F_211 ( struct V_184 * V_152 , struct V_1 * V_14 ,
enum V_411 V_82 )
{
int V_69 ;
switch ( V_82 ) {
case V_418 :
V_69 = V_428 ;
break;
case V_420 :
V_69 = V_429 ;
break;
default:
F_7 ( & V_14 -> V_22 , L_143 ,
V_113 ) ;
return - V_68 ;
}
if ( F_208 ( V_14 , V_82 , 0 ) )
return - V_300 ;
F_207 ( V_14 , V_82 , false ) ;
if ( V_152 -> V_153 -> V_435 ( V_152 , V_14 , V_82 ) )
F_7 ( & V_14 -> V_22 , L_144
L_145 ,
V_422 [ V_82 ] ) ;
return 0 ;
}
int F_212 ( struct V_1 * V_14 )
{
struct V_184 * V_152 ;
if ( ! V_14 || ! V_14 -> V_23 ||
V_14 -> V_15 != V_49 ||
! V_14 -> V_24 )
return 0 ;
V_152 = F_54 ( V_14 -> V_164 ) ;
if ( ! V_152 || ! V_152 -> V_153 -> V_435 )
return 0 ;
V_14 -> V_436 ++ ;
if ( ( V_14 -> V_52 . V_427 == 0 && V_14 -> V_53 . V_427 == 0 ) )
return 0 ;
if ( F_211 ( V_152 , V_14 , V_418 ) )
goto V_437;
if ( F_211 ( V_152 , V_14 , V_420 ) )
goto V_437;
return 0 ;
V_437:
F_213 ( V_14 ) ;
return - V_300 ;
}
int F_194 ( struct V_1 * V_14 )
{
struct V_184 * V_152 = F_54 ( V_14 -> V_164 ) ;
int V_56 ;
if ( ! V_152 )
return - V_68 ;
F_27 ( V_152 -> V_438 ) ;
V_56 = F_212 ( V_14 ) ;
F_30 ( V_152 -> V_438 ) ;
return V_56 ;
}
void F_213 ( struct V_1 * V_14 )
{
struct V_184 * V_152 ;
if ( ! V_14 || ! V_14 -> V_23 ||
V_14 -> V_15 != V_49 ||
! V_14 -> V_24 )
return;
V_14 -> V_436 -- ;
V_152 = F_54 ( V_14 -> V_164 ) ;
if ( ! V_152 || ! V_152 -> V_153 -> V_434 ||
! V_152 -> V_153 -> V_435 )
return;
if ( V_14 -> V_436 > 0 )
return;
F_210 ( V_152 , V_14 , V_418 ) ;
F_210 ( V_152 , V_14 , V_420 ) ;
}
void F_195 ( struct V_1 * V_14 )
{
struct V_184 * V_152 = F_54 ( V_14 -> V_164 ) ;
if ( ! V_152 )
return;
F_27 ( V_152 -> V_438 ) ;
F_213 ( V_14 ) ;
F_30 ( V_152 -> V_438 ) ;
}
int F_212 ( struct V_1 * V_14 )
{
return 0 ;
}
void F_213 ( struct V_1 * V_14 ) { }
int F_194 ( struct V_1 * V_14 )
{
return 0 ;
}
void F_195 ( struct V_1 * V_14 ) { }
int F_189 ( struct V_1 * V_14 )
{
return 0 ;
}
void F_191 ( struct V_1 * V_14 ) { }
static int F_214 ( struct V_6 * V_7 , int V_71 )
{
int V_56 ;
int V_439 , V_440 = 0 ;
T_1 V_200 , V_8 ;
unsigned V_441 = 0xffff ;
for ( V_439 = 0 ; ; V_439 += V_442 ) {
V_56 = F_26 ( V_7 , V_71 , & V_8 , & V_200 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( ! ( V_200 & V_203 ) &&
( V_8 & V_201 ) == V_441 ) {
V_440 += V_442 ;
if ( V_440 >= V_214 )
break;
} else {
V_440 = 0 ;
V_441 = V_8 & V_201 ;
}
if ( V_200 & V_203 ) {
F_17 ( V_7 -> V_2 , V_71 ,
V_204 ) ;
}
if ( V_439 >= V_443 )
break;
F_58 ( V_442 ) ;
}
F_20 ( V_7 -> V_112 ,
L_146 ,
V_71 , V_439 , V_440 , V_8 ) ;
if ( V_440 < V_214 )
return - V_103 ;
return V_8 ;
}
void F_215 ( struct V_1 * V_14 )
{
F_216 ( V_14 , 0 + V_64 , true ) ;
F_216 ( V_14 , 0 + V_444 , true ) ;
F_217 ( V_14 , & V_14 -> V_316 , true ) ;
}
static int F_218 ( struct V_1 * V_14 , int V_161 )
{
int V_225 ;
struct V_184 * V_152 = F_54 ( V_14 -> V_164 ) ;
if ( ! V_152 -> V_153 -> V_445 && V_161 <= 1 )
return - V_68 ;
if ( V_14 -> V_82 == V_399 )
return 0 ;
if ( V_14 -> V_82 != V_376 )
return - V_68 ;
if ( V_152 -> V_153 -> V_445 )
V_225 = V_152 -> V_153 -> V_445 ( V_152 , V_14 ) ;
else
V_225 = F_13 ( V_14 , F_219 () ,
V_446 , 0 , V_161 , 0 ,
NULL , 0 , V_193 ) ;
if ( V_225 == 0 ) {
F_133 ( V_14 , V_161 ) ;
F_61 ( V_14 , V_399 ) ;
F_215 ( V_14 ) ;
}
return V_225 ;
}
static int
F_220 ( struct V_6 * V_7 , struct V_1 * V_14 , int V_71 ,
int V_447 )
{
static F_221 ( V_448 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_184 * V_152 = F_54 ( V_2 -> V_164 ) ;
int V_55 , V_449 , V_225 ;
unsigned V_168 = V_373 ;
enum V_450 V_451 = V_14 -> V_15 ;
const char * V_15 ;
int V_161 = V_14 -> V_161 ;
if ( ! V_2 -> V_23 ) {
V_168 = V_452 ;
if ( V_71 == V_2 -> V_164 -> V_334 )
V_2 -> V_164 -> V_335 = 0 ;
}
if ( V_451 == V_371 )
V_168 = V_374 ;
F_27 ( & V_448 ) ;
V_225 = F_182 ( V_7 , V_71 , V_14 , V_168 , false ) ;
if ( V_225 < 0 )
goto V_236;
V_225 = - V_137 ;
if ( V_451 != V_453 && V_451 != V_14 -> V_15 ) {
F_20 ( & V_14 -> V_22 , L_147 ) ;
goto V_236;
}
V_451 = V_14 -> V_15 ;
switch ( V_14 -> V_15 ) {
case V_49 :
case V_370 :
V_14 -> V_316 . V_267 . V_454 = F_206 ( 512 ) ;
break;
case V_16 :
V_14 -> V_316 . V_267 . V_454 = F_206 ( 64 ) ;
break;
case V_372 :
V_14 -> V_316 . V_267 . V_454 = F_206 ( 64 ) ;
break;
case V_371 :
V_14 -> V_316 . V_267 . V_454 = F_206 ( 8 ) ;
break;
default:
goto V_236;
}
if ( V_14 -> V_15 == V_370 )
V_15 = L_148 ;
else
V_15 = F_222 ( V_14 -> V_15 ) ;
if ( V_14 -> V_15 != V_49 )
F_90 ( & V_14 -> V_22 ,
L_149 ,
( V_14 -> V_328 ) ? L_150 : L_151 , V_15 ,
V_161 , V_14 -> V_164 -> V_455 -> V_153 -> V_456 ) ;
if ( V_2 -> V_140 ) {
V_14 -> V_140 = V_2 -> V_140 ;
V_14 -> V_160 = V_2 -> V_160 ;
} else if ( V_14 -> V_15 != V_16
&& V_2 -> V_15 == V_16 ) {
if ( ! V_7 -> V_140 . V_7 ) {
F_28 ( & V_14 -> V_22 , L_152 ) ;
V_225 = - V_68 ;
goto V_236;
}
V_14 -> V_140 = & V_7 -> V_140 ;
V_14 -> V_160 = V_71 ;
}
for ( V_55 = 0 ; V_55 < V_457 ; ( ++ V_55 , F_58 ( 100 ) ) ) {
if ( F_223 ( V_447 ) && ! ( V_152 -> V_153 -> V_117 & V_458 ) ) {
struct V_459 * V_460 ;
int V_461 = 0 ;
#define F_224 64
V_460 = F_50 ( F_224 , V_199 ) ;
if ( ! V_460 ) {
V_225 = - V_158 ;
continue;
}
for ( V_449 = 0 ; V_449 < 3 ; ++ V_449 ) {
V_460 -> V_462 = 0 ;
V_461 = F_13 ( V_14 , F_225 () ,
V_63 , V_64 ,
V_463 << 8 , 0 ,
V_460 , F_224 ,
V_464 ) ;
switch ( V_460 -> V_462 ) {
case 8 : case 16 : case 32 : case 64 : case 255 :
if ( V_460 -> V_465 ==
V_463 ) {
V_461 = 0 ;
break;
}
default:
if ( V_461 == 0 )
V_461 = - V_466 ;
break;
}
if ( V_461 == 0 )
break;
}
V_14 -> V_3 . V_462 =
V_460 -> V_462 ;
F_48 ( V_460 ) ;
V_225 = F_182 ( V_7 , V_71 , V_14 , V_168 , false ) ;
if ( V_225 < 0 )
goto V_236;
if ( V_451 != V_14 -> V_15 ) {
F_20 ( & V_14 -> V_22 ,
L_147 ) ;
V_225 = - V_137 ;
goto V_236;
}
if ( V_461 ) {
F_28 ( & V_14 -> V_22 ,
L_153 ,
V_461 ) ;
V_225 = - V_467 ;
continue;
}
#undef F_224
}
if ( V_14 -> V_310 == 0 ) {
for ( V_449 = 0 ; V_449 < V_468 ; ++ V_449 ) {
V_225 = F_218 ( V_14 , V_161 ) ;
if ( V_225 >= 0 )
break;
F_58 ( 200 ) ;
}
if ( V_225 < 0 ) {
F_28 ( & V_14 -> V_22 ,
L_154 ,
V_161 , V_225 ) ;
goto V_236;
}
if ( V_14 -> V_15 == V_49 ) {
V_161 = V_14 -> V_161 ;
F_90 ( & V_14 -> V_22 ,
L_155 ,
( V_14 -> V_328 ) ? L_150 : L_151 ,
V_161 , V_14 -> V_164 -> V_455 -> V_153 -> V_456 ) ;
}
F_58 ( 10 ) ;
if ( F_223 ( V_447 ) && ! ( V_152 -> V_153 -> V_117 & V_458 ) )
break;
}
V_225 = F_176 ( V_14 , 8 ) ;
if ( V_225 < 8 ) {
F_28 ( & V_14 -> V_22 ,
L_156 ,
V_225 ) ;
if ( V_225 >= 0 )
V_225 = - V_467 ;
} else {
V_225 = 0 ;
break;
}
}
if ( V_225 )
goto V_236;
if ( ( V_14 -> V_15 == V_49 ) &&
( F_29 ( V_14 -> V_3 . V_469 ) < 0x0300 ) ) {
F_28 ( & V_14 -> V_22 , L_157
L_158 ) ;
F_182 ( V_7 , V_71 , V_14 ,
V_367 , true ) ;
V_225 = - V_68 ;
goto V_236;
}
if ( V_14 -> V_3 . V_462 == 0xff ||
V_14 -> V_15 == V_49 )
V_55 = 512 ;
else
V_55 = V_14 -> V_3 . V_462 ;
if ( F_226 ( & V_14 -> V_316 . V_267 ) != V_55 ) {
if ( V_14 -> V_15 == V_371 ||
! ( V_55 == 8 || V_55 == 16 || V_55 == 32 || V_55 == 64 ) ) {
F_28 ( & V_14 -> V_22 , L_159 , V_55 ) ;
V_225 = - V_467 ;
goto V_236;
}
if ( V_14 -> V_15 == V_372 )
F_20 ( & V_14 -> V_22 , L_160 , V_55 ) ;
else
F_7 ( & V_14 -> V_22 , L_161 , V_55 ) ;
V_14 -> V_316 . V_267 . V_454 = F_206 ( V_55 ) ;
F_215 ( V_14 ) ;
}
V_225 = F_176 ( V_14 , V_470 ) ;
if ( V_225 < ( signed ) sizeof( V_14 -> V_3 ) ) {
F_28 ( & V_14 -> V_22 , L_162 ,
V_225 ) ;
if ( V_225 >= 0 )
V_225 = - V_471 ;
goto V_236;
}
if ( V_14 -> V_310 == 0 && F_29 ( V_14 -> V_3 . V_469 ) >= 0x0201 ) {
V_225 = F_227 ( V_14 ) ;
if ( ! V_225 ) {
V_14 -> V_24 = F_5 ( V_14 ) ;
F_11 ( V_14 ) ;
}
}
V_225 = 0 ;
if ( V_152 -> V_153 -> V_472 )
V_152 -> V_153 -> V_472 ( V_152 , V_14 ) ;
V_236:
if ( V_225 ) {
F_60 ( V_7 , V_71 , 0 ) ;
F_133 ( V_14 , V_161 ) ;
}
F_30 ( & V_448 ) ;
return V_225 ;
}
static void
F_228 ( struct V_6 * V_7 , struct V_1 * V_14 , int V_71 )
{
struct V_473 * V_474 ;
int V_75 ;
V_474 = F_50 ( sizeof *V_474 , V_226 ) ;
if ( V_474 == NULL )
return;
V_75 = F_229 ( V_14 , V_475 , 0 ,
V_474 , sizeof *V_474 ) ;
if ( V_75 == sizeof *V_474 ) {
F_90 ( & V_14 -> V_22 , L_163
L_164 ) ;
if ( V_7 -> V_216 ) {
V_7 -> V_87 [ V_71 - 1 ] = V_91 ;
F_23 ( & V_7 -> V_79 , 0 ) ;
}
}
F_48 ( V_474 ) ;
}
static unsigned
F_230 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_266 ;
int V_71 ;
if ( ! V_7 -> V_263 )
return 0 ;
V_266 = V_2 -> V_261 - V_7 -> V_3 -> V_265 ;
for ( V_71 = 1 ; V_71 <= V_2 -> V_12 ; ++ V_71 ) {
struct V_1 * V_14 = V_7 -> V_175 [ V_71 - 1 ] -> V_176 ;
int V_476 ;
if ( ! V_14 )
continue;
if ( V_14 -> V_11 )
V_476 = V_14 -> V_11 -> V_267 . V_477 * 2 ;
else if ( V_71 != V_14 -> V_164 -> V_334 || V_2 -> V_23 )
V_476 = 100 ;
else
V_476 = 8 ;
if ( V_476 > V_7 -> V_262 )
F_7 ( & V_14 -> V_22 ,
L_165 ,
V_476 , V_7 -> V_262 , V_71 ) ;
V_266 -= V_476 ;
}
if ( V_266 < 0 ) {
F_7 ( V_7 -> V_112 , L_166 ,
- V_266 ) ;
V_266 = 0 ;
}
return V_266 ;
}
static void F_231 ( struct V_6 * V_7 , int V_71 ,
T_1 V_8 , T_1 V_200 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_222 * V_231 = V_7 -> V_112 ;
struct V_184 * V_152 = F_54 ( V_2 -> V_164 ) ;
unsigned V_169 =
F_29 ( V_7 -> V_3 -> V_169 ) ;
struct V_1 * V_14 ;
int V_75 , V_55 ;
F_20 ( V_231 ,
L_167 ,
V_71 , V_8 , V_200 , F_2 ( V_7 , V_8 ) ) ;
if ( V_7 -> V_216 ) {
F_19 ( V_7 , V_71 , V_89 ) ;
V_7 -> V_87 [ V_71 - 1 ] = V_90 ;
}
#ifdef F_145
if ( V_2 -> V_164 -> V_327 )
V_200 &= ~ ( V_203 |
V_205 ) ;
#endif
V_14 = V_7 -> V_175 [ V_71 - 1 ] -> V_176 ;
if ( ( V_8 & V_201 ) && V_14 &&
V_14 -> V_82 != V_177 ) {
F_135 ( V_14 ) ;
if ( V_8 & V_202 ) {
V_75 = 0 ;
#ifdef F_232
} else if ( V_14 -> V_82 == V_302 &&
V_14 -> V_212 ) {
V_75 = F_199 ( V_14 ) ;
#endif
} else {
V_75 = - V_137 ;
}
F_139 ( V_14 ) ;
if ( V_75 == 0 ) {
F_69 ( V_71 , V_7 -> V_179 ) ;
return;
}
}
if ( V_14 )
F_74 ( & V_7 -> V_175 [ V_71 - 1 ] -> V_176 ) ;
F_69 ( V_71 , V_7 -> V_179 ) ;
if ( ! ( V_8 & V_201 ) ||
( V_200 & V_203 ) )
F_69 ( V_71 , V_7 -> V_182 ) ;
if ( V_200 & ( V_203 |
V_205 ) ) {
V_75 = F_214 ( V_7 , V_71 ) ;
if ( V_75 < 0 ) {
if ( F_233 () )
F_28 ( V_231 , L_168
L_169 , V_71 ) ;
V_8 &= ~ V_201 ;
} else {
V_8 = V_75 ;
}
}
if ( V_152 -> V_478 && ! V_2 -> V_23 ) {
if ( V_8 & V_201 )
F_234 ( V_152 -> V_478 , V_71 ) ;
else
F_235 ( V_152 -> V_478 , V_71 ) ;
}
if ( ! ( V_8 & V_201 ) ||
F_130 ( V_71 , V_7 -> V_182 ) ) {
if ( ( V_169 & V_170 ) < 2
&& ! F_186 ( V_7 , V_8 ) )
F_18 ( V_2 , V_71 , V_171 ) ;
if ( V_8 & V_202 )
goto V_381;
return;
}
for ( V_55 = 0 ; V_55 < V_479 ; V_55 ++ ) {
V_14 = F_236 ( V_2 , V_2 -> V_164 , V_71 ) ;
if ( ! V_14 ) {
F_28 ( V_231 ,
L_170 ,
V_71 ) ;
goto V_381;
}
F_61 ( V_14 , V_480 ) ;
V_14 -> V_261 = V_7 -> V_262 ;
V_14 -> V_192 = V_2 -> V_192 + 1 ;
V_14 -> V_310 = F_179 ( V_7 ) ;
if ( F_1 ( V_7 -> V_2 ) )
V_14 -> V_15 = V_49 ;
else
V_14 -> V_15 = V_453 ;
F_128 ( V_14 ) ;
if ( V_14 -> V_161 <= 0 ) {
V_75 = - V_368 ;
goto V_481;
}
V_75 = F_220 ( V_7 , V_14 , V_71 , V_55 ) ;
if ( V_75 < 0 )
goto V_481;
F_237 ( V_14 ) ;
if ( V_14 -> V_482 & V_483 )
F_58 ( 1000 ) ;
if ( V_14 -> V_3 . V_484 == V_485
&& V_14 -> V_261 <= 100 ) {
T_1 V_486 ;
V_75 = F_95 ( V_14 , V_259 , 0 ,
& V_486 ) ;
if ( V_75 < 2 ) {
F_20 ( & V_14 -> V_22 , L_171 , V_75 ) ;
goto V_487;
}
F_96 ( & V_486 ) ;
if ( ( V_486 & ( 1 << V_264 ) ) == 0 ) {
F_28 ( & V_14 -> V_22 ,
L_172
L_173 ) ;
if ( V_7 -> V_216 ) {
V_7 -> V_87 [ V_71 - 1 ] =
V_95 ;
F_23 ( & V_7 -> V_79 , 0 ) ;
}
V_75 = - V_368 ;
goto V_487;
}
}
if ( F_29 ( V_14 -> V_3 . V_469 ) >= 0x0200
&& V_14 -> V_15 == V_372
&& V_275 != 0 )
F_228 ( V_7 , V_14 , V_71 ) ;
V_75 = 0 ;
F_106 ( & V_291 ) ;
if ( V_2 -> V_82 == V_177 )
V_75 = - V_368 ;
else
V_7 -> V_175 [ V_71 - 1 ] -> V_176 = V_14 ;
F_109 ( & V_291 ) ;
if ( ! V_75 ) {
V_75 = F_155 ( V_14 ) ;
if ( V_75 ) {
F_106 ( & V_291 ) ;
V_7 -> V_175 [ V_71 - 1 ] -> V_176 = NULL ;
F_109 ( & V_291 ) ;
}
}
if ( V_75 )
goto V_487;
V_75 = F_230 ( V_7 ) ;
if ( V_75 )
F_20 ( V_231 , L_174 , V_75 ) ;
return;
V_487:
F_60 ( V_7 , V_71 , 1 ) ;
V_481:
F_215 ( V_14 ) ;
F_132 ( V_14 ) ;
F_134 ( V_14 ) ;
F_238 ( V_14 ) ;
if ( ( V_75 == - V_368 ) || ( V_75 == - V_339 ) )
break;
}
if ( V_7 -> V_2 -> V_23 ||
! V_152 -> V_153 -> V_488 ||
! ( V_152 -> V_153 -> V_488 ) ( V_152 , V_71 ) )
F_28 ( V_231 , L_175 ,
V_71 ) ;
V_381:
F_60 ( V_7 , V_71 , 1 ) ;
if ( V_152 -> V_153 -> V_489 && ! V_7 -> V_2 -> V_23 )
V_152 -> V_153 -> V_489 ( V_152 , V_71 ) ;
}
static int F_239 ( struct V_6 * V_7 , unsigned int V_111 ,
T_1 V_8 , T_1 V_200 )
{
struct V_1 * V_2 ;
struct V_1 * V_14 ;
int V_490 = 0 ;
int V_56 ;
V_2 = V_7 -> V_2 ;
V_14 = V_7 -> V_175 [ V_111 - 1 ] -> V_176 ;
if ( ! F_1 ( V_2 ) ) {
if ( ! ( V_200 & V_403 ) )
return 0 ;
F_17 ( V_2 , V_111 , V_404 ) ;
} else {
if ( ! V_14 || V_14 -> V_82 != V_302 ||
( V_8 & V_210 ) !=
V_211 )
return 0 ;
}
if ( V_14 ) {
F_58 ( 10 ) ;
F_135 ( V_14 ) ;
V_56 = F_199 ( V_14 ) ;
F_139 ( V_14 ) ;
if ( V_56 < 0 )
V_490 = 1 ;
} else {
V_56 = - V_137 ;
F_60 ( V_7 , V_111 , 1 ) ;
}
F_20 ( V_7 -> V_112 , L_176 ,
V_111 , V_56 ) ;
return V_490 ;
}
static void F_240 ( void )
{
struct V_146 * V_491 ;
struct V_1 * V_2 ;
struct V_180 * V_181 ;
struct V_6 * V_7 ;
struct V_222 * V_231 ;
T_1 V_232 ;
T_1 V_233 ;
T_1 V_8 ;
T_1 V_200 ;
int V_55 , V_56 ;
int V_490 , V_492 ;
while ( 1 ) {
F_106 ( & V_118 ) ;
if ( F_33 ( & V_121 ) ) {
F_109 ( & V_118 ) ;
break;
}
V_491 = V_121 . V_147 ;
F_107 ( V_491 ) ;
V_7 = F_46 ( V_491 , struct V_6 , V_120 ) ;
F_241 ( & V_7 -> V_273 ) ;
F_109 ( & V_118 ) ;
V_2 = V_7 -> V_2 ;
V_231 = V_7 -> V_112 ;
V_181 = F_36 ( V_231 ) ;
F_20 ( V_231 , L_177 ,
V_2 -> V_82 , V_7 -> V_3
? V_7 -> V_3 -> V_85
: 0 ,
( T_1 ) V_7 -> V_179 [ 0 ] ,
( T_1 ) V_7 -> V_135 [ 0 ] ) ;
F_135 ( V_2 ) ;
if ( F_242 ( V_7 -> V_119 ) )
goto V_493;
if ( V_2 -> V_82 == V_177 ) {
V_7 -> error = - V_137 ;
F_72 ( V_7 , V_274 ) ;
goto V_481;
}
V_56 = F_64 ( V_181 ) ;
if ( V_56 ) {
F_20 ( V_231 , L_178 , V_56 ) ;
goto V_481;
}
if ( V_7 -> V_84 )
goto V_494;
if ( V_7 -> error ) {
F_20 ( V_231 , L_179 ,
V_7 -> error ) ;
V_56 = F_243 ( V_2 ) ;
if ( V_56 ) {
F_20 ( V_231 ,
L_180 , V_56 ) ;
goto V_494;
}
V_7 -> V_131 = 0 ;
V_7 -> error = 0 ;
}
for ( V_55 = 1 ; V_55 <= V_7 -> V_3 -> V_85 ; V_55 ++ ) {
if ( F_130 ( V_55 , V_7 -> V_402 ) )
continue;
V_490 = F_130 ( V_55 , V_7 -> V_179 ) ;
V_492 = F_244 ( V_55 , V_7 -> V_124 ) ;
if ( ! F_244 ( V_55 , V_7 -> V_135 ) &&
! V_490 && ! V_492 )
continue;
V_56 = F_26 ( V_7 , V_55 ,
& V_8 , & V_200 ) ;
if ( V_56 < 0 )
continue;
if ( V_200 & V_203 ) {
F_17 ( V_2 , V_55 ,
V_204 ) ;
V_490 = 1 ;
}
if ( V_200 & V_205 ) {
if ( ! V_490 )
F_20 ( V_231 ,
L_181
L_182 ,
V_55 , V_8 ) ;
F_17 ( V_2 , V_55 ,
V_206 ) ;
if ( ! ( V_8 & V_202 )
&& ! V_490
&& V_7 -> V_175 [ V_55 - 1 ] -> V_176 ) {
F_28 ( V_231 ,
L_183
L_184
L_185 ,
V_55 ) ;
V_490 = 1 ;
}
}
if ( F_239 ( V_7 , V_55 ,
V_8 , V_200 ) )
V_490 = 1 ;
if ( V_200 & V_495 ) {
T_1 V_75 = 0 ;
T_1 V_496 ;
F_20 ( V_231 , L_186
L_187 , V_55 ) ;
F_17 ( V_2 , V_55 ,
V_497 ) ;
F_58 ( 100 ) ;
F_56 ( V_7 , true ) ;
F_26 ( V_7 , V_55 , & V_75 , & V_496 ) ;
if ( V_75 & V_498 )
F_28 ( V_231 , L_188
L_189 , V_55 ) ;
}
if ( V_200 & V_365 ) {
F_20 ( V_231 ,
L_190 ,
V_55 ) ;
F_17 ( V_2 , V_55 ,
V_366 ) ;
}
if ( ( V_200 & V_207 ) &&
F_1 ( V_7 -> V_2 ) ) {
F_20 ( V_231 ,
L_191 ,
V_55 ) ;
F_17 ( V_2 , V_55 ,
V_208 ) ;
}
if ( V_200 & V_363 ) {
F_17 ( V_7 -> V_2 , V_55 ,
V_364 ) ;
}
if ( V_200 & V_499 ) {
F_7 ( V_231 ,
L_192 ,
V_55 ) ;
F_17 ( V_7 -> V_2 , V_55 ,
V_500 ) ;
}
if ( F_180 ( V_7 , V_8 ) ) {
F_20 ( V_231 , L_193 , V_55 ) ;
F_182 ( V_7 , V_55 , NULL ,
V_367 , true ) ;
}
if ( V_490 )
F_231 ( V_7 , V_55 ,
V_8 , V_200 ) ;
}
if ( F_244 ( 0 , V_7 -> V_135 ) == 0 )
;
else if ( F_59 ( V_7 , & V_232 , & V_233 ) < 0 )
F_28 ( V_231 , L_194 ) ;
else {
if ( V_233 & V_501 ) {
F_20 ( V_231 , L_195 ) ;
F_15 ( V_2 , V_502 ) ;
if ( V_232 & V_269 )
V_7 -> V_263 = 1 ;
else
V_7 -> V_263 = 0 ;
}
if ( V_233 & V_503 ) {
T_1 V_75 = 0 ;
T_1 V_496 ;
F_20 ( V_231 , L_196 ) ;
F_15 ( V_2 , V_504 ) ;
F_58 ( 500 ) ;
F_56 ( V_7 , true ) ;
F_59 ( V_7 , & V_75 , & V_496 ) ;
if ( V_75 & V_270 )
F_28 ( V_231 , L_188
L_197 ) ;
}
}
V_494:
F_108 ( V_181 ) ;
V_481:
F_65 ( V_181 ) ;
V_493:
F_139 ( V_2 ) ;
F_112 ( & V_7 -> V_273 , F_102 ) ;
}
}
static int F_245 ( void * V_505 )
{
F_246 () ;
do {
F_240 () ;
F_247 ( V_122 ,
! F_33 ( & V_121 ) ||
F_248 () ) ;
} while ( ! F_248 () || ! F_33 ( & V_121 ) );
F_249 ( L_198 , V_506 ) ;
return 0 ;
}
int F_250 ( void )
{
if ( F_251 ( & V_507 ) < 0 ) {
F_252 ( V_508 L_199 ,
V_506 ) ;
return - 1 ;
}
V_509 = F_253 ( F_245 , NULL , L_200 ) ;
if ( ! F_254 ( V_509 ) )
return 0 ;
F_255 ( & V_507 ) ;
F_252 ( V_508 L_201 , V_506 ) ;
return - 1 ;
}
void F_256 ( void )
{
F_257 ( V_509 ) ;
F_255 ( & V_507 ) ;
}
static int F_258 ( struct V_1 * V_14 ,
struct V_459 * V_510 )
{
int V_80 = 0 ;
unsigned V_511 ;
unsigned V_512 = 0 ;
unsigned V_513 ;
unsigned V_514 ;
int V_515 ;
char * V_460 ;
if ( memcmp ( & V_14 -> V_3 , V_510 ,
sizeof( * V_510 ) ) != 0 )
return 1 ;
if ( V_14 -> V_325 )
V_512 = strlen ( V_14 -> V_325 ) + 1 ;
V_513 = V_512 ;
for ( V_511 = 0 ; V_511 < V_14 -> V_3 . V_349 ; V_511 ++ ) {
V_514 = F_29 ( V_14 -> V_328 [ V_511 ] . V_267 . V_331 ) ;
V_513 = F_57 ( V_513 , V_514 ) ;
}
V_460 = F_50 ( V_513 , V_199 ) ;
if ( V_460 == NULL ) {
F_28 ( & V_14 -> V_22 , L_202 ) ;
return 1 ;
}
for ( V_511 = 0 ; V_511 < V_14 -> V_3 . V_349 ; V_511 ++ ) {
V_514 = F_29 ( V_14 -> V_328 [ V_511 ] . V_267 . V_331 ) ;
V_515 = F_229 ( V_14 , V_516 , V_511 , V_460 ,
V_514 ) ;
if ( V_515 != V_514 ) {
F_20 ( & V_14 -> V_22 , L_203 ,
V_511 , V_515 ) ;
V_80 = 1 ;
break;
}
if ( memcmp ( V_460 , V_14 -> V_330 [ V_511 ] , V_514 )
!= 0 ) {
F_20 ( & V_14 -> V_22 , L_204 ,
V_511 ,
( (struct V_517 * ) V_460 ) ->
V_518 ) ;
V_80 = 1 ;
break;
}
}
if ( ! V_80 && V_512 ) {
V_515 = F_259 ( V_14 , V_14 -> V_3 . V_322 ,
V_460 , V_512 ) ;
if ( V_515 + 1 != V_512 ) {
F_20 ( & V_14 -> V_22 , L_205 ,
V_515 ) ;
V_80 = 1 ;
} else if ( memcmp ( V_460 , V_14 -> V_325 , V_515 ) != 0 ) {
F_20 ( & V_14 -> V_22 , L_206 ) ;
V_80 = 1 ;
}
}
F_48 ( V_460 ) ;
return V_80 ;
}
static int F_197 ( struct V_1 * V_14 )
{
struct V_1 * V_519 = V_14 -> V_23 ;
struct V_6 * V_520 ;
struct V_184 * V_152 = F_54 ( V_14 -> V_164 ) ;
struct V_459 V_3 = V_14 -> V_3 ;
int V_55 , V_56 = 0 ;
int V_71 = V_14 -> V_123 ;
if ( V_14 -> V_82 == V_177 ||
V_14 -> V_82 == V_302 ) {
F_20 ( & V_14 -> V_22 , L_207 ,
V_14 -> V_82 ) ;
return - V_68 ;
}
if ( ! V_519 ) {
F_20 ( & V_14 -> V_22 , L_208 , V_113 ) ;
return - V_521 ;
}
V_520 = F_3 ( V_519 ) ;
V_56 = F_194 ( V_14 ) ;
if ( V_56 ) {
F_28 ( & V_14 -> V_22 , L_209 , V_113 ) ;
goto V_522;
}
V_56 = F_189 ( V_14 ) ;
if ( V_56 ) {
F_28 ( & V_14 -> V_22 , L_210 ,
V_113 ) ;
goto V_522;
}
F_41 ( V_71 , V_520 -> V_402 ) ;
for ( V_55 = 0 ; V_55 < V_479 ; ++ V_55 ) {
F_215 ( V_14 ) ;
V_56 = F_220 ( V_520 , V_14 , V_71 , V_55 ) ;
if ( V_56 >= 0 || V_56 == - V_368 || V_56 == - V_137 )
break;
}
F_69 ( V_71 , V_520 -> V_402 ) ;
if ( V_56 < 0 )
goto V_522;
if ( F_258 ( V_14 , & V_3 ) ) {
F_90 ( & V_14 -> V_22 , L_211 ) ;
V_14 -> V_3 = V_3 ;
goto V_522;
}
if ( ! V_14 -> V_11 )
goto V_381;
F_27 ( V_152 -> V_438 ) ;
V_56 = F_260 ( V_14 , V_14 -> V_11 , NULL , NULL ) ;
if ( V_56 < 0 ) {
F_7 ( & V_14 -> V_22 ,
L_212
L_213 ) ;
F_30 ( V_152 -> V_438 ) ;
goto V_522;
}
V_56 = F_13 ( V_14 , F_16 ( V_14 , 0 ) ,
V_523 , 0 ,
V_14 -> V_11 -> V_267 . V_518 , 0 ,
NULL , 0 , V_193 ) ;
if ( V_56 < 0 ) {
F_28 ( & V_14 -> V_22 ,
L_214 ,
V_14 -> V_11 -> V_267 . V_518 , V_56 ) ;
F_30 ( V_152 -> V_438 ) ;
goto V_522;
}
F_30 ( V_152 -> V_438 ) ;
F_61 ( V_14 , V_83 ) ;
for ( V_55 = 0 ; V_55 < V_14 -> V_11 -> V_267 . V_524 ; V_55 ++ ) {
struct V_525 * V_328 = V_14 -> V_11 ;
struct V_180 * V_181 = V_328 -> V_13 [ V_55 ] ;
struct V_526 * V_267 ;
V_267 = & V_181 -> V_279 -> V_267 ;
if ( V_267 -> V_527 == 0 ) {
F_261 ( V_14 , V_181 , true ) ;
F_262 ( V_14 , V_181 , true ) ;
V_56 = 0 ;
} else {
V_181 -> V_528 = 1 ;
V_56 = F_94 ( V_14 , V_267 -> V_529 ,
V_267 -> V_527 ) ;
V_181 -> V_528 = 0 ;
}
if ( V_56 < 0 ) {
F_28 ( & V_14 -> V_22 , L_215
L_216 ,
V_267 -> V_529 ,
V_267 -> V_527 ,
V_56 ) ;
goto V_522;
}
}
V_381:
F_195 ( V_14 ) ;
F_191 ( V_14 ) ;
return 0 ;
V_522:
F_62 ( V_520 , V_71 ) ;
return - V_137 ;
}
int F_243 ( struct V_1 * V_14 )
{
int V_56 ;
int V_55 ;
struct V_525 * V_328 = V_14 -> V_11 ;
if ( V_14 -> V_82 == V_177 ||
V_14 -> V_82 == V_302 ) {
F_20 ( & V_14 -> V_22 , L_207 ,
V_14 -> V_82 ) ;
return - V_68 ;
}
F_175 ( V_14 ) ;
if ( V_328 ) {
for ( V_55 = 0 ; V_55 < V_328 -> V_267 . V_524 ; ++ V_55 ) {
struct V_180 * V_530 = V_328 -> V_13 [ V_55 ] ;
struct V_531 * V_151 ;
int V_532 = 0 ;
if ( V_530 -> V_22 . V_153 ) {
V_151 = F_263 ( V_530 -> V_22 . V_153 ) ;
if ( V_151 -> V_533 && V_151 -> V_534 )
V_532 = ( V_151 -> V_533 ) ( V_530 ) ;
else if ( V_530 -> V_535 ==
V_536 )
V_532 = 1 ;
if ( V_532 )
F_264 ( V_530 ) ;
}
}
}
V_56 = F_197 ( V_14 ) ;
if ( V_328 ) {
for ( V_55 = V_328 -> V_267 . V_524 - 1 ; V_55 >= 0 ; -- V_55 ) {
struct V_180 * V_530 = V_328 -> V_13 [ V_55 ] ;
struct V_531 * V_151 ;
int V_537 = V_530 -> V_538 ;
if ( ! V_537 && V_530 -> V_22 . V_153 ) {
V_151 = F_263 ( V_530 -> V_22 . V_153 ) ;
if ( V_151 -> V_534 )
V_537 = ( V_151 -> V_534 ) ( V_530 ) ;
else if ( V_530 -> V_535 ==
V_536 )
V_537 = 1 ;
}
if ( V_56 == 0 && V_537 )
F_265 ( V_530 ) ;
}
}
F_178 ( V_14 ) ;
return V_56 ;
}
void F_266 ( struct V_180 * V_539 )
{
F_55 ( & V_539 -> V_540 ) ;
}
struct V_1 * F_267 ( struct V_1 * V_2 ,
int V_71 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_71 < 1 || V_71 > V_2 -> V_12 )
return NULL ;
return V_7 -> V_175 [ V_71 - 1 ] -> V_176 ;
}
void F_268 ( struct V_1 * V_2 , int V_71 ,
enum V_541 type )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
V_7 -> V_175 [ V_71 - 1 ] -> V_542 = type ;
}
enum V_541
F_269 ( struct V_1 * V_2 , int V_71 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
return V_7 -> V_175 [ V_71 - 1 ] -> V_542 ;
}
T_6 F_270 ( struct V_1 * V_2 ,
int V_71 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
return F_271 ( & V_7 -> V_175 [ V_71 - 1 ] -> V_22 ) ;
}
