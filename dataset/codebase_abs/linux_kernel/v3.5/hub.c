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
if ( ! V_2 || ! V_2 -> V_11 )
return NULL ;
return F_4 ( V_2 -> V_11 -> V_12 [ 0 ] ) ;
}
static int F_5 ( struct V_1 * V_13 )
{
if ( V_13 -> V_14 == V_15 ) {
if ( V_13 -> V_16 -> V_17 &&
( V_18 &
F_6 ( V_13 -> V_16 -> V_17 -> V_19 ) ) )
return 1 ;
return 0 ;
}
if ( ! V_13 -> V_16 -> V_20 ) {
F_7 ( & V_13 -> V_21 , L_5
L_6 ) ;
return 0 ;
}
if ( V_13 -> V_22 -> V_23 )
return 1 ;
F_7 ( & V_13 -> V_21 , L_7
L_6 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_13 ,
struct V_24 * V_25 ,
unsigned int V_26 ,
struct V_6 * V_7 ,
struct V_24 * V_27 ,
unsigned int V_28 )
{
unsigned int V_29 ;
unsigned int V_30 ;
unsigned int V_31 ;
V_29 = V_27 -> V_32 +
( V_7 -> V_3 -> V_33 . V_34 . V_35 * 100 ) ;
V_30 = V_26 * 1000 ;
V_31 = V_28 * 1000 ;
if ( V_30 > V_31 )
V_29 += V_30 ;
else
V_29 += V_31 ;
V_25 -> V_32 = V_29 ;
}
static void F_9 ( struct V_1 * V_13 ,
struct V_24 * V_25 ,
unsigned int V_26 ,
struct V_6 * V_7 ,
struct V_24 * V_27 ,
unsigned int V_28 ,
unsigned int V_36 )
{
unsigned int V_37 ;
unsigned int V_38 ;
if ( V_26 > V_28 )
V_37 = V_26 * 1000 ;
else
V_37 = V_28 * 1000 ;
V_38 = V_36 * 1000 + V_27 -> V_39 ;
if ( V_37 > V_38 )
V_25 -> V_39 = V_37 ;
else
V_25 -> V_39 = V_38 ;
}
static void F_10 ( struct V_1 * V_13 ,
struct V_24 * V_25 )
{
struct V_1 * V_22 ;
unsigned int V_40 ;
unsigned int V_41 ;
V_41 = V_25 -> V_39 ;
for ( V_22 = V_13 -> V_22 , V_40 = 0 ; V_22 -> V_22 ;
V_22 = V_22 -> V_22 )
V_40 ++ ;
if ( V_40 > 0 )
V_41 += 2100 + 250 * ( V_40 - 1 ) ;
V_41 += 250 * V_40 ;
V_25 -> V_42 = V_41 ;
}
static void F_11 ( struct V_1 * V_13 )
{
struct V_6 * V_7 ;
unsigned int V_43 ;
unsigned int V_44 ;
unsigned int V_45 ;
unsigned int V_46 ;
unsigned int V_47 ;
if ( ! V_13 -> V_23 || V_13 -> V_14 != V_48 )
return;
V_7 = F_3 ( V_13 -> V_22 ) ;
if ( ! V_7 )
return;
V_44 = V_13 -> V_16 -> V_20 -> V_49 ;
V_45 = V_13 -> V_16 -> V_20 -> V_50 ;
V_46 = V_13 -> V_22 -> V_16 -> V_20 -> V_49 ;
V_47 = V_13 -> V_22 -> V_16 -> V_20 -> V_50 ;
F_8 ( V_13 , & V_13 -> V_51 , V_44 ,
V_7 , & V_13 -> V_22 -> V_51 , V_46 ) ;
F_8 ( V_13 , & V_13 -> V_52 , V_45 ,
V_7 , & V_13 -> V_22 -> V_52 , V_47 ) ;
V_43 = 1 ;
F_9 ( V_13 , & V_13 -> V_51 , V_44 ,
V_7 , & V_13 -> V_22 -> V_51 , V_46 ,
V_43 ) ;
if ( V_47 > V_46 )
V_43 = 1 + V_47 - V_46 ;
else
V_43 = 1 + V_46 ;
F_9 ( V_13 , & V_13 -> V_52 , V_45 ,
V_7 , & V_13 -> V_22 -> V_52 , V_47 ,
V_43 ) ;
F_10 ( V_13 , & V_13 -> V_51 ) ;
F_10 ( V_13 , & V_13 -> V_52 ) ;
}
static int F_12 ( struct V_1 * V_2 , void * V_53 )
{
int V_54 , V_55 , V_56 ;
unsigned V_57 ;
if ( F_1 ( V_2 ) ) {
V_57 = V_58 ;
V_56 = V_59 ;
} else {
V_57 = V_60 ;
V_56 = sizeof( struct V_61 ) ;
}
for ( V_54 = 0 ; V_54 < 3 ; V_54 ++ ) {
V_55 = F_13 ( V_2 , F_14 ( V_2 , 0 ) ,
V_62 , V_63 | V_64 ,
V_57 << 8 , 0 , V_53 , V_56 ,
V_65 ) ;
if ( V_55 >= ( V_66 + 2 ) )
return V_55 ;
}
return - V_67 ;
}
static int F_15 ( struct V_1 * V_2 , int V_68 )
{
return F_13 ( V_2 , F_16 ( V_2 , 0 ) ,
V_69 , V_64 , V_68 , 0 , NULL , 0 , 1000 ) ;
}
static int F_17 ( struct V_1 * V_2 , int V_70 , int V_68 )
{
return F_13 ( V_2 , F_16 ( V_2 , 0 ) ,
V_69 , V_71 , V_68 , V_70 ,
NULL , 0 , 1000 ) ;
}
static int F_18 ( struct V_1 * V_2 , int V_70 , int V_68 )
{
return F_13 ( V_2 , F_16 ( V_2 , 0 ) ,
V_72 , V_71 , V_68 , V_70 ,
NULL , 0 , 1000 ) ;
}
static void F_19 (
struct V_6 * V_7 ,
int V_70 ,
int V_73
)
{
int V_74 = F_18 ( V_7 -> V_2 , ( V_73 << 8 ) | V_70 ,
V_75 ) ;
if ( V_74 < 0 )
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
static void F_21 ( struct V_76 * V_77 )
{
struct V_6 * V_7 =
F_22 ( V_77 , struct V_6 , V_78 . V_77 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
unsigned V_54 ;
unsigned V_79 = 0 ;
int V_80 = - 1 ;
if ( V_2 -> V_81 != V_82 || V_7 -> V_83 )
return;
for ( V_54 = 0 ; V_54 < V_7 -> V_3 -> V_84 ; V_54 ++ ) {
unsigned V_73 , V_85 ;
switch ( V_7 -> V_86 [ V_54 ] ) {
case V_87 :
V_80 = V_54 ;
V_73 = V_88 ;
V_85 = V_89 ;
break;
case V_90 :
V_73 = V_91 ;
V_85 = V_92 ;
break;
case V_92 :
V_73 = V_93 ;
V_85 = V_90 ;
break;
case V_94 :
V_73 = V_95 ;
V_85 = V_96 ;
break;
case V_96 :
V_73 = V_93 ;
V_85 = V_94 ;
break;
case V_97 :
V_73 = V_91 ;
V_85 = V_98 ;
break;
case V_98 :
V_73 = V_95 ;
V_85 = V_97 ;
break;
default:
continue;
}
if ( V_73 != V_88 )
V_79 = 1 ;
F_19 ( V_7 , V_54 + 1 , V_73 ) ;
V_7 -> V_86 [ V_54 ] = V_85 ;
}
if ( ! V_79 && V_99 ) {
V_80 ++ ;
V_80 %= V_7 -> V_3 -> V_84 ;
F_19 ( V_7 , V_80 + 1 , V_91 ) ;
V_7 -> V_86 [ V_80 ] = V_87 ;
V_79 ++ ;
}
if ( V_79 )
F_23 ( & V_7 -> V_78 , V_100 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_101 * V_53 )
{
int V_54 , V_74 = - V_102 ;
for ( V_54 = 0 ; V_54 < V_103 &&
( V_74 == - V_102 || V_74 == - V_104 ) ; V_54 ++ ) {
V_74 = F_13 ( V_2 , F_14 ( V_2 , 0 ) ,
V_105 , V_63 | V_64 , 0 , 0 ,
V_53 , sizeof( * V_53 ) , V_106 ) ;
}
return V_74 ;
}
static int F_25 ( struct V_1 * V_2 , int V_70 ,
struct V_107 * V_53 )
{
int V_54 , V_74 = - V_102 ;
for ( V_54 = 0 ; V_54 < V_103 &&
( V_74 == - V_102 || V_74 == - V_104 ) ; V_54 ++ ) {
V_74 = F_13 ( V_2 , F_14 ( V_2 , 0 ) ,
V_105 , V_63 | V_71 , 0 , V_70 ,
V_53 , sizeof( * V_53 ) , V_106 ) ;
}
return V_74 ;
}
static int F_26 ( struct V_6 * V_7 , int V_70 ,
T_1 * V_74 , T_1 * V_108 )
{
int V_55 ;
F_27 ( & V_7 -> V_109 ) ;
V_55 = F_25 ( V_7 -> V_2 , V_70 , & V_7 -> V_74 -> V_110 ) ;
if ( V_55 < 4 ) {
F_28 ( V_7 -> V_111 ,
L_14 , V_112 , V_55 ) ;
if ( V_55 >= 0 )
V_55 = - V_113 ;
} else {
* V_74 = F_29 ( V_7 -> V_74 -> V_110 . V_114 ) ;
* V_108 = F_29 ( V_7 -> V_74 -> V_110 . V_115 ) ;
V_55 = 0 ;
}
F_30 ( & V_7 -> V_109 ) ;
return V_55 ;
}
static void F_31 ( struct V_6 * V_7 )
{
unsigned long V_116 ;
F_32 ( & V_117 , V_116 ) ;
if ( ! V_7 -> V_118 && F_33 ( & V_7 -> V_119 ) ) {
F_34 ( & V_7 -> V_119 , & V_120 ) ;
F_35 (
F_36 ( V_7 -> V_111 ) ) ;
F_37 ( & V_121 ) ;
}
F_38 ( & V_117 , V_116 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_7 )
F_31 ( V_7 ) ;
}
void F_40 ( struct V_1 * V_2 ,
unsigned int V_122 )
{
struct V_6 * V_7 ;
if ( ! V_2 )
return;
V_7 = F_3 ( V_2 ) ;
if ( V_7 ) {
F_41 ( V_122 , V_7 -> V_123 ) ;
F_31 ( V_7 ) ;
}
}
static void F_42 ( struct V_124 * V_124 )
{
struct V_6 * V_7 = V_124 -> V_125 ;
int V_74 = V_124 -> V_74 ;
unsigned V_54 ;
unsigned long V_126 ;
switch ( V_74 ) {
case - V_127 :
case - V_128 :
case - V_129 :
return;
default:
F_20 ( V_7 -> V_111 , L_15 , V_74 ) ;
if ( ( ++ V_7 -> V_130 < 10 ) || V_7 -> error )
goto V_131;
V_7 -> error = V_74 ;
case 0 :
V_126 = 0 ;
for ( V_54 = 0 ; V_54 < V_124 -> V_132 ; ++ V_54 )
V_126 |= ( ( unsigned long ) ( ( * V_7 -> V_133 ) [ V_54 ] ) )
<< ( V_54 * 8 ) ;
V_7 -> V_134 [ 0 ] = V_126 ;
break;
}
V_7 -> V_130 = 0 ;
F_31 ( V_7 ) ;
V_131:
if ( V_7 -> V_83 )
return;
if ( ( V_74 = F_43 ( V_7 -> V_124 , V_135 ) ) != 0
&& V_74 != - V_136 && V_74 != - V_137 )
F_28 ( V_7 -> V_111 , L_16 , V_74 ) ;
}
static inline int
F_44 ( struct V_1 * V_2 , T_1 V_138 , T_1 V_139 )
{
return F_13 ( V_2 , F_16 ( V_2 , 0 ) ,
V_140 , V_71 , V_138 ,
V_139 , NULL , 0 , 1000 ) ;
}
static void F_45 ( struct V_76 * V_77 )
{
struct V_6 * V_7 =
F_22 ( V_77 , struct V_6 , V_139 . V_141 ) ;
unsigned long V_116 ;
int V_142 = 100 ;
F_32 ( & V_7 -> V_139 . V_143 , V_116 ) ;
while ( -- V_142 && ! F_33 ( & V_7 -> V_139 . V_144 ) ) {
struct V_145 * V_146 ;
struct V_147 * V_148 ;
struct V_1 * V_2 = V_7 -> V_2 ;
const struct V_149 * V_150 ;
int V_74 ;
V_146 = V_7 -> V_139 . V_144 . V_146 ;
V_148 = F_46 ( V_146 , struct V_147 , V_144 ) ;
F_47 ( & V_148 -> V_144 ) ;
F_38 ( & V_7 -> V_139 . V_143 , V_116 ) ;
V_74 = F_44 ( V_2 , V_148 -> V_138 , V_148 -> V_139 ) ;
if ( V_74 )
F_28 ( & V_2 -> V_21 ,
L_17 ,
V_148 -> V_139 , V_148 -> V_138 , V_74 ) ;
V_150 = V_148 -> V_151 -> V_152 ;
if ( V_150 -> V_153 )
( V_150 -> V_153 ) ( V_148 -> V_151 , V_148 -> V_154 ) ;
F_48 ( V_148 ) ;
F_32 ( & V_7 -> V_139 . V_143 , V_116 ) ;
}
F_38 ( & V_7 -> V_139 . V_143 , V_116 ) ;
}
int F_49 ( struct V_124 * V_124 )
{
struct V_1 * V_13 = V_124 -> V_21 ;
int V_155 = V_124 -> V_155 ;
struct V_156 * V_139 = V_13 -> V_139 ;
unsigned long V_116 ;
struct V_147 * V_148 ;
if ( ( V_148 = F_50 ( sizeof *V_148 , V_135 ) ) == NULL ) {
F_28 ( & V_13 -> V_21 , L_18 ) ;
return - V_157 ;
}
V_148 -> V_139 = V_139 -> V_158 ? V_13 -> V_159 : 1 ;
V_148 -> V_138 = F_51 ( V_155 ) ;
V_148 -> V_138 |= V_13 -> V_160 << 4 ;
V_148 -> V_138 |= F_52 ( V_155 )
? ( V_161 << 11 )
: ( V_162 << 11 ) ;
if ( F_53 ( V_155 ) )
V_148 -> V_138 |= 1 << 15 ;
V_148 -> V_151 = F_54 ( V_13 -> V_163 ) ;
V_148 -> V_154 = V_124 -> V_154 ;
F_32 ( & V_139 -> V_143 , V_116 ) ;
F_34 ( & V_148 -> V_144 , & V_139 -> V_144 ) ;
F_55 ( & V_139 -> V_141 ) ;
F_38 ( & V_139 -> V_143 , V_116 ) ;
return 0 ;
}
static unsigned F_56 ( struct V_6 * V_7 , bool V_164 )
{
int V_70 ;
unsigned V_165 = V_7 -> V_3 -> V_166 * 2 ;
unsigned V_167 ;
T_1 V_168 =
F_29 ( V_7 -> V_3 -> V_168 ) ;
if ( ( V_168 & V_169 ) < 2 )
F_20 ( V_7 -> V_111 , L_19 ) ;
else
F_20 ( V_7 -> V_111 , L_20
L_21 ) ;
for ( V_70 = 1 ; V_70 <= V_7 -> V_3 -> V_84 ; V_70 ++ )
F_18 ( V_7 -> V_2 , V_70 , V_170 ) ;
V_167 = F_57 ( V_165 , ( unsigned ) 100 ) ;
if ( V_164 )
F_58 ( V_167 ) ;
return V_167 ;
}
static int F_59 ( struct V_6 * V_7 ,
T_1 * V_74 , T_1 * V_108 )
{
int V_55 ;
F_27 ( & V_7 -> V_109 ) ;
V_55 = F_24 ( V_7 -> V_2 , & V_7 -> V_74 -> V_7 ) ;
if ( V_55 < 0 )
F_28 ( V_7 -> V_111 ,
L_14 , V_112 , V_55 ) ;
else {
* V_74 = F_29 ( V_7 -> V_74 -> V_7 . V_171 ) ;
* V_108 = F_29 ( V_7 -> V_74 -> V_7 . V_172 ) ;
V_55 = 0 ;
}
F_30 ( & V_7 -> V_109 ) ;
return V_55 ;
}
static int F_60 ( struct V_6 * V_7 , int V_70 , int V_173 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_55 = 0 ;
if ( V_2 -> V_174 [ V_70 - 1 ] && V_173 )
F_61 ( V_2 -> V_174 [ V_70 - 1 ] ,
V_175 ) ;
if ( ! V_7 -> error && ! F_1 ( V_7 -> V_2 ) )
V_55 = F_17 ( V_2 , V_70 , V_176 ) ;
if ( V_55 )
F_28 ( V_7 -> V_111 , L_22 ,
V_70 , V_55 ) ;
return V_55 ;
}
static void F_62 ( struct V_6 * V_7 , int V_70 )
{
F_20 ( V_7 -> V_111 , L_23 , V_70 ) ;
F_60 ( V_7 , V_70 , 1 ) ;
F_41 ( V_70 , V_7 -> V_177 ) ;
F_31 ( V_7 ) ;
}
int F_63 ( struct V_1 * V_13 )
{
struct V_6 * V_7 ;
struct V_178 * V_179 ;
if ( ! V_13 -> V_22 )
return - V_67 ;
V_7 = F_3 ( V_13 -> V_22 ) ;
V_179 = F_36 ( V_7 -> V_111 ) ;
F_64 ( V_179 ) ;
F_41 ( V_13 -> V_122 , V_7 -> V_180 ) ;
F_62 ( V_7 , V_13 -> V_122 ) ;
F_65 ( V_179 ) ;
return 0 ;
}
static void F_66 ( struct V_6 * V_7 , enum V_181 type )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_182 * V_151 ;
int V_55 ;
int V_70 ;
int V_74 ;
bool V_183 = false ;
unsigned V_167 ;
if ( type == V_184 )
goto V_185;
if ( type == V_186 )
goto V_187;
if ( type != V_188 ) {
if ( V_2 -> V_22 && F_1 ( V_2 ) ) {
V_55 = F_13 ( V_2 , F_16 ( V_2 , 0 ) ,
V_189 , V_64 ,
V_2 -> V_190 - 1 , 0 , NULL , 0 ,
V_191 ) ;
if ( V_55 < 0 )
F_28 ( V_7 -> V_111 ,
L_24 ) ;
}
if ( type == V_192 ) {
V_167 = F_56 ( V_7 , false ) ;
F_67 ( & V_7 -> V_193 , V_194 ) ;
F_23 ( & V_7 -> V_193 ,
F_68 ( V_167 ) ) ;
F_35 (
F_36 ( V_7 -> V_111 ) ) ;
return;
} else if ( type == V_195 ) {
V_151 = F_54 ( V_2 -> V_163 ) ;
if ( V_151 -> V_152 -> V_196 ) {
V_55 = V_151 -> V_152 -> V_196 ( V_151 , V_2 ,
& V_7 -> V_139 , V_197 ) ;
if ( V_55 < 0 ) {
F_28 ( V_7 -> V_111 , L_25
L_26
L_27 ) ;
F_28 ( V_7 -> V_111 , L_28
L_29
L_30 ) ;
}
}
F_56 ( V_7 , true ) ;
} else {
F_56 ( V_7 , true ) ;
}
}
V_185:
for ( V_70 = 1 ; V_70 <= V_2 -> V_198 ; ++ V_70 ) {
struct V_1 * V_13 = V_2 -> V_174 [ V_70 - 1 ] ;
T_1 V_8 , V_199 ;
V_8 = V_199 = 0 ;
V_74 = F_26 ( V_7 , V_70 , & V_8 , & V_199 ) ;
if ( V_13 || ( V_8 & V_200 ) )
F_20 ( V_7 -> V_111 ,
L_31 ,
V_70 , V_8 , V_199 ) ;
if ( ( V_8 & V_201 ) && (
type != V_188 ||
! ( V_8 & V_200 ) ||
! V_13 ||
V_13 -> V_81 == V_175 ) ) {
if ( ! F_1 ( V_2 ) ) {
F_17 ( V_2 , V_70 ,
V_176 ) ;
V_8 &= ~ V_201 ;
} else {
V_8 &= ~ V_201 ;
}
}
if ( V_199 & V_202 ) {
V_183 = true ;
F_17 ( V_7 -> V_2 , V_70 ,
V_203 ) ;
}
if ( V_199 & V_204 ) {
V_183 = true ;
F_17 ( V_7 -> V_2 , V_70 ,
V_205 ) ;
}
if ( ( V_199 & V_206 ) &&
F_1 ( V_7 -> V_2 ) ) {
V_183 = true ;
F_17 ( V_7 -> V_2 , V_70 ,
V_207 ) ;
}
if ( ! ( V_8 & V_200 ) ||
( V_199 & V_202 ) )
F_69 ( V_70 , V_7 -> V_180 ) ;
if ( ! V_13 || V_13 -> V_81 == V_175 ) {
if ( V_13 || ( V_8 & V_200 ) )
F_41 ( V_70 , V_7 -> V_177 ) ;
} else if ( V_8 & V_201 ) {
bool V_208 = ( V_8 &
V_209 ) ==
V_210 ;
if ( V_199 || ( F_1 ( V_7 -> V_2 ) &&
V_208 ) )
F_41 ( V_70 , V_7 -> V_177 ) ;
} else if ( V_13 -> V_211 ) {
#ifdef F_70
V_13 -> V_212 = 1 ;
#endif
F_41 ( V_70 , V_7 -> V_177 ) ;
} else {
F_61 ( V_13 , V_175 ) ;
F_41 ( V_70 , V_7 -> V_177 ) ;
}
}
if ( V_183 ) {
V_167 = V_213 ;
if ( type == V_184 ) {
F_67 ( & V_7 -> V_193 , V_214 ) ;
F_23 ( & V_7 -> V_193 ,
F_68 ( V_167 ) ) ;
return;
} else {
F_58 ( V_167 ) ;
}
}
V_187:
V_7 -> V_83 = 0 ;
V_74 = F_43 ( V_7 -> V_124 , V_197 ) ;
if ( V_74 < 0 )
F_28 ( V_7 -> V_111 , L_32 , V_74 ) ;
if ( V_7 -> V_215 && V_99 )
F_23 ( & V_7 -> V_78 , V_100 ) ;
F_31 ( V_7 ) ;
if ( type <= V_186 )
F_71 ( F_36 ( V_7 -> V_111 ) ) ;
}
static void V_194 ( struct V_76 * V_216 )
{
struct V_6 * V_7 = F_22 ( V_216 , struct V_6 , V_193 . V_77 ) ;
F_66 ( V_7 , V_184 ) ;
}
static void V_214 ( struct V_76 * V_216 )
{
struct V_6 * V_7 = F_22 ( V_216 , struct V_6 , V_193 . V_77 ) ;
F_66 ( V_7 , V_186 ) ;
}
static void F_72 ( struct V_6 * V_7 , enum V_217 type )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_54 ;
F_73 ( & V_7 -> V_193 ) ;
V_7 -> V_83 = 1 ;
if ( type != V_218 ) {
for ( V_54 = 0 ; V_54 < V_2 -> V_198 ; ++ V_54 ) {
if ( V_2 -> V_174 [ V_54 ] )
F_74 ( & V_2 -> V_174 [ V_54 ] ) ;
}
}
F_75 ( V_7 -> V_124 ) ;
if ( V_7 -> V_215 )
F_73 ( & V_7 -> V_78 ) ;
if ( V_7 -> V_139 . V_7 )
F_76 ( & V_7 -> V_139 . V_141 ) ;
}
static int F_77 ( struct V_178 * V_179 )
{
struct V_6 * V_7 = F_4 ( V_179 ) ;
F_72 ( V_7 , V_219 ) ;
return 0 ;
}
static int F_78 ( struct V_178 * V_179 )
{
struct V_6 * V_7 = F_4 ( V_179 ) ;
F_66 ( V_7 , V_220 ) ;
return 0 ;
}
static int F_79 ( struct V_6 * V_7 ,
struct V_221 * V_222 )
{
struct V_182 * V_151 ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_223 * V_224 = V_7 -> V_111 ;
T_1 V_225 , V_226 ;
T_1 V_168 ;
unsigned int V_155 ;
int V_227 , V_55 ;
char * V_228 = L_33 ;
V_7 -> V_133 = F_50 ( sizeof( * V_7 -> V_133 ) , V_229 ) ;
if ( ! V_7 -> V_133 ) {
V_55 = - V_157 ;
goto V_230;
}
V_7 -> V_74 = F_50 ( sizeof( * V_7 -> V_74 ) , V_229 ) ;
if ( ! V_7 -> V_74 ) {
V_55 = - V_157 ;
goto V_230;
}
F_80 ( & V_7 -> V_109 ) ;
V_7 -> V_3 = F_50 ( sizeof( * V_7 -> V_3 ) , V_229 ) ;
if ( ! V_7 -> V_3 ) {
V_55 = - V_157 ;
goto V_230;
}
V_55 = F_12 ( V_2 , V_7 -> V_3 ) ;
if ( V_55 < 0 ) {
V_228 = L_34 ;
goto V_230;
} else if ( V_7 -> V_3 -> V_84 > V_231 ) {
V_228 = L_35 ;
V_55 = - V_136 ;
goto V_230;
}
V_2 -> V_198 = V_7 -> V_3 -> V_84 ;
F_81 ( V_224 , L_36 , V_2 -> V_198 ,
( V_2 -> V_198 == 1 ) ? L_37 : L_38 ) ;
V_2 -> V_174 = F_82 ( V_2 -> V_198 *
sizeof( struct V_1 * ) , V_229 ) ;
V_7 -> V_232 = F_82 ( V_2 -> V_198 * sizeof( void * ) , V_229 ) ;
if ( ! V_2 -> V_174 || ! V_7 -> V_232 ) {
V_55 = - V_157 ;
goto V_230;
}
V_168 = F_29 ( V_7 -> V_3 -> V_168 ) ;
if ( ( V_168 & V_233 ) &&
! ( F_1 ( V_2 ) ) ) {
int V_54 ;
char V_234 [ V_231 + 1 ] ;
for ( V_54 = 0 ; V_54 < V_2 -> V_198 ; V_54 ++ )
V_234 [ V_54 ] = V_7 -> V_3 -> V_33 . V_235 . V_236
[ ( ( V_54 + 1 ) / 8 ) ] & ( 1 << ( ( V_54 + 1 ) % 8 ) )
? 'F' : 'R' ;
V_234 [ V_2 -> V_198 ] = 0 ;
F_20 ( V_224 , L_39 , V_234 ) ;
} else
F_20 ( V_224 , L_40 ) ;
switch ( V_168 & V_169 ) {
case V_237 :
F_20 ( V_224 , L_41 ) ;
break;
case V_238 :
F_20 ( V_224 , L_42 ) ;
break;
case V_239 :
case V_169 :
F_20 ( V_224 , L_43 ) ;
break;
}
switch ( V_168 & V_240 ) {
case V_241 :
F_20 ( V_224 , L_44 ) ;
break;
case V_242 :
F_20 ( V_224 , L_45 ) ;
break;
case V_243 :
case V_240 :
F_20 ( V_224 , L_46 ) ;
break;
}
F_83 ( & V_7 -> V_139 . V_143 ) ;
F_84 ( & V_7 -> V_139 . V_144 ) ;
F_85 ( & V_7 -> V_139 . V_141 , F_45 ) ;
switch ( V_2 -> V_3 . V_4 ) {
case V_244 :
break;
case V_245 :
F_20 ( V_224 , L_47 ) ;
V_7 -> V_139 . V_7 = V_2 ;
break;
case V_246 :
V_55 = F_86 ( V_2 , 0 , 1 ) ;
if ( V_55 == 0 ) {
F_20 ( V_224 , L_48 ) ;
V_7 -> V_139 . V_158 = 1 ;
} else
F_28 ( V_224 , L_49 ,
V_55 ) ;
V_7 -> V_139 . V_7 = V_2 ;
break;
case V_5 :
break;
default:
F_20 ( V_224 , L_50 ,
V_2 -> V_3 . V_4 ) ;
break;
}
switch ( V_168 & V_247 ) {
case V_248 :
if ( V_2 -> V_3 . V_4 != 0 ) {
V_7 -> V_139 . V_249 = 666 ;
F_20 ( V_224 , L_51
L_52 ,
8 , V_7 -> V_139 . V_249 ) ;
}
break;
case V_250 :
V_7 -> V_139 . V_249 = 666 * 2 ;
F_20 ( V_224 , L_51
L_52 ,
16 , V_7 -> V_139 . V_249 ) ;
break;
case V_251 :
V_7 -> V_139 . V_249 = 666 * 3 ;
F_20 ( V_224 , L_51
L_52 ,
24 , V_7 -> V_139 . V_249 ) ;
break;
case V_252 :
V_7 -> V_139 . V_249 = 666 * 4 ;
F_20 ( V_224 , L_51
L_52 ,
32 , V_7 -> V_139 . V_249 ) ;
break;
}
if ( V_168 & V_253 ) {
V_7 -> V_215 = 1 ;
F_20 ( V_224 , L_53 ) ;
}
F_20 ( V_224 , L_54 ,
V_7 -> V_3 -> V_166 * 2 ) ;
V_55 = F_87 ( V_2 , V_254 , 0 , & V_225 ) ;
if ( V_55 < 2 ) {
V_228 = L_55 ;
goto V_230;
}
F_88 ( & V_225 ) ;
if ( V_2 == V_2 -> V_163 -> V_255 ) {
if ( V_2 -> V_256 == 0 || V_2 -> V_256 >= 500 )
V_7 -> V_257 = 500 ;
else {
V_7 -> V_257 = V_2 -> V_256 ;
V_7 -> V_258 = 1 ;
}
} else if ( ( V_225 & ( 1 << V_259 ) ) == 0 ) {
F_20 ( V_224 , L_56 ,
V_7 -> V_3 -> V_260 ) ;
V_7 -> V_258 = 1 ;
if ( V_2 -> V_198 > 0 ) {
int V_261 = V_2 -> V_256 -
V_7 -> V_3 -> V_260 ;
if ( V_261 < V_2 -> V_198 * 100 )
F_7 ( V_224 ,
L_57
L_58 ) ;
V_7 -> V_257 = 100 ;
}
} else {
V_7 -> V_257 = 500 ;
}
if ( V_7 -> V_257 < 500 )
F_20 ( V_224 , L_59 ,
V_7 -> V_257 ) ;
V_151 = F_54 ( V_2 -> V_163 ) ;
if ( V_151 -> V_152 -> V_196 ) {
V_55 = V_151 -> V_152 -> V_196 ( V_151 , V_2 ,
& V_7 -> V_139 , V_229 ) ;
if ( V_55 < 0 ) {
V_228 = L_60 ;
goto V_230;
}
}
V_55 = F_59 ( V_7 , & V_225 , & V_226 ) ;
if ( V_55 < 0 ) {
V_228 = L_55 ;
goto V_230;
}
if ( V_2 -> V_11 -> V_262 . V_19 & V_263 )
F_20 ( V_224 , L_61 ,
( V_225 & V_264 )
? L_62 : L_63 ) ;
if ( ( V_168 & V_240 ) == 0 )
F_20 ( V_224 , L_64 ,
( V_225 & V_265 ) ? L_37 : L_65 ) ;
V_155 = F_89 ( V_2 , V_222 -> V_266 ) ;
V_227 = F_90 ( V_2 , V_155 , F_91 ( V_155 ) ) ;
if ( V_227 > sizeof( * V_7 -> V_133 ) )
V_227 = sizeof( * V_7 -> V_133 ) ;
V_7 -> V_124 = F_92 ( 0 , V_229 ) ;
if ( ! V_7 -> V_124 ) {
V_55 = - V_157 ;
goto V_230;
}
F_93 ( V_7 -> V_124 , V_2 , V_155 , * V_7 -> V_133 , V_227 , F_42 ,
V_7 , V_222 -> V_267 ) ;
if ( V_7 -> V_215 && V_99 )
V_7 -> V_86 [ 0 ] = V_87 ;
F_66 ( V_7 , V_192 ) ;
return 0 ;
V_230:
F_28 ( V_224 , L_66 ,
V_228 , V_55 ) ;
return V_55 ;
}
static void F_94 ( struct V_268 * V_268 )
{
struct V_6 * V_7 = F_22 ( V_268 , struct V_6 , V_268 ) ;
F_95 ( F_36 ( V_7 -> V_111 ) ) ;
F_48 ( V_7 ) ;
}
static void F_96 ( struct V_178 * V_179 )
{
struct V_6 * V_7 = F_4 ( V_179 ) ;
struct V_1 * V_2 = F_97 ( V_179 ) ;
F_98 ( & V_117 ) ;
if ( ! F_33 ( & V_7 -> V_119 ) ) {
F_99 ( & V_7 -> V_119 ) ;
F_100 ( V_179 ) ;
}
V_7 -> V_118 = 1 ;
F_101 ( & V_117 ) ;
V_7 -> error = 0 ;
F_72 ( V_7 , V_269 ) ;
F_102 ( V_179 , NULL ) ;
V_7 -> V_2 -> V_198 = 0 ;
if ( V_7 -> V_2 -> V_14 == V_15 )
V_270 -- ;
F_103 ( V_7 -> V_124 ) ;
F_48 ( V_2 -> V_174 ) ;
F_48 ( V_7 -> V_232 ) ;
F_48 ( V_7 -> V_3 ) ;
F_48 ( V_7 -> V_74 ) ;
F_48 ( V_7 -> V_133 ) ;
F_104 ( & V_7 -> V_268 , F_94 ) ;
}
static int F_105 ( struct V_178 * V_179 , const struct V_271 * V_272 )
{
struct V_273 * V_262 ;
struct V_221 * V_222 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
V_262 = V_179 -> V_274 ;
V_2 = F_97 ( V_179 ) ;
F_106 ( V_2 ) ;
if ( V_2 -> V_190 == V_275 ) {
F_28 ( & V_179 -> V_21 ,
L_67 ) ;
return - V_276 ;
}
#ifdef F_107
if ( V_2 -> V_22 ) {
F_7 ( & V_179 -> V_21 , L_68 ) ;
return - V_136 ;
}
#endif
if ( ( V_262 -> V_262 . V_277 != 0 ) &&
( V_262 -> V_262 . V_277 != 1 ) ) {
V_278:
F_28 ( & V_179 -> V_21 , L_69 ) ;
return - V_113 ;
}
if ( V_262 -> V_262 . V_279 != 1 )
goto V_278;
V_222 = & V_262 -> V_222 [ 0 ] . V_262 ;
if ( ! F_108 ( V_222 ) )
goto V_278;
F_81 ( & V_179 -> V_21 , L_70 ) ;
V_7 = F_82 ( sizeof( * V_7 ) , V_229 ) ;
if ( ! V_7 ) {
F_20 ( & V_179 -> V_21 , L_71 ) ;
return - V_157 ;
}
F_109 ( & V_7 -> V_268 ) ;
F_84 ( & V_7 -> V_119 ) ;
V_7 -> V_111 = & V_179 -> V_21 ;
V_7 -> V_2 = V_2 ;
F_110 ( & V_7 -> V_78 , F_21 ) ;
F_110 ( & V_7 -> V_193 , NULL ) ;
F_111 ( V_179 ) ;
F_102 ( V_179 , V_7 ) ;
V_179 -> V_280 = 1 ;
if ( V_2 -> V_14 == V_15 )
V_270 ++ ;
if ( F_79 ( V_7 , V_222 ) >= 0 )
return 0 ;
F_96 ( V_179 ) ;
return - V_136 ;
}
static int
F_112 ( struct V_178 * V_179 , unsigned int V_281 , void * V_282 )
{
struct V_1 * V_2 = F_97 ( V_179 ) ;
switch ( V_281 ) {
case V_283 : {
struct V_284 * V_285 = V_282 ;
int V_54 ;
F_98 ( & V_286 ) ;
if ( V_2 -> V_160 <= 0 )
V_285 -> V_287 = 0 ;
else {
V_285 -> V_287 = V_2 -> V_198 ;
for ( V_54 = 0 ; V_54 < V_285 -> V_287 ; V_54 ++ ) {
if ( V_2 -> V_174 [ V_54 ] == NULL )
V_285 -> V_110 [ V_54 ] = 0 ;
else
V_285 -> V_110 [ V_54 ] =
V_2 -> V_174 [ V_54 ] -> V_160 ;
}
}
F_101 ( & V_286 ) ;
return V_285 -> V_287 + 1 ;
}
default:
return - V_288 ;
}
}
static int F_113 ( struct V_1 * V_2 , unsigned V_70 ,
void * * * V_289 )
{
if ( V_2 -> V_81 == V_175 )
return - V_136 ;
if ( V_70 == 0 || V_70 > V_2 -> V_198 )
return - V_67 ;
* V_289 = & ( F_3 ( V_2 ) -> V_232 [ V_70 - 1 ] ) ;
return 0 ;
}
int F_114 ( struct V_1 * V_2 , unsigned V_70 , void * V_290 )
{
int V_291 ;
void * * V_292 ;
V_291 = F_113 ( V_2 , V_70 , & V_292 ) ;
if ( V_291 )
return V_291 ;
if ( * V_292 )
return - V_293 ;
* V_292 = V_290 ;
return V_291 ;
}
int F_115 ( struct V_1 * V_2 , unsigned V_70 , void * V_290 )
{
int V_291 ;
void * * V_292 ;
V_291 = F_113 ( V_2 , V_70 , & V_292 ) ;
if ( V_291 )
return V_291 ;
if ( * V_292 != V_290 )
return - V_127 ;
* V_292 = NULL ;
return V_291 ;
}
void F_116 ( struct V_1 * V_2 , void * V_290 )
{
int V_294 ;
void * * V_292 ;
V_294 = F_113 ( V_2 , 1 , & V_292 ) ;
if ( V_294 == 0 ) {
for (; V_294 < V_2 -> V_198 ; ( ++ V_294 , ++ V_292 ) ) {
if ( * V_292 == V_290 )
* V_292 = NULL ;
}
}
}
bool F_117 ( struct V_1 * V_13 )
{
struct V_6 * V_7 ;
if ( V_13 -> V_81 == V_175 || ! V_13 -> V_22 )
return false ;
V_7 = F_3 ( V_13 -> V_22 ) ;
return ! ! V_7 -> V_232 [ V_13 -> V_122 - 1 ] ;
}
static void F_118 ( struct V_1 * V_13 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < V_13 -> V_198 ; ++ V_54 ) {
if ( V_13 -> V_174 [ V_54 ] )
F_118 ( V_13 -> V_174 [ V_54 ] ) ;
}
if ( V_13 -> V_81 == V_295 )
V_13 -> V_296 -= V_297 ;
V_13 -> V_81 = V_175 ;
}
void F_61 ( struct V_1 * V_13 ,
enum V_298 V_299 )
{
unsigned long V_116 ;
int V_300 = - 1 ;
F_32 ( & V_286 , V_116 ) ;
if ( V_13 -> V_81 == V_175 )
;
else if ( V_299 != V_175 ) {
if ( V_13 -> V_22 ) {
if ( V_13 -> V_81 == V_295
|| V_299 == V_295 )
;
else if ( V_299 == V_82 )
V_300 = V_13 -> V_11 -> V_262 . V_19
& V_301 ;
else
V_300 = 0 ;
}
if ( V_13 -> V_81 == V_295 &&
V_299 != V_295 )
V_13 -> V_296 -= V_297 ;
else if ( V_299 == V_295 &&
V_13 -> V_81 != V_295 )
V_13 -> V_296 += V_297 ;
V_13 -> V_81 = V_299 ;
} else
F_118 ( V_13 ) ;
F_38 ( & V_286 , V_116 ) ;
if ( V_300 >= 0 )
F_119 ( & V_13 -> V_21 , V_300 ) ;
}
static void F_120 ( struct V_1 * V_13 )
{
int V_160 ;
struct V_302 * V_163 = V_13 -> V_163 ;
if ( V_13 -> V_303 ) {
V_160 = V_13 -> V_122 + 1 ;
F_121 ( F_122 ( V_160 , V_163 -> V_304 . V_305 ) ) ;
} else {
V_160 = F_123 ( V_163 -> V_304 . V_305 , 128 ,
V_163 -> V_306 ) ;
if ( V_160 >= 128 )
V_160 = F_123 ( V_163 -> V_304 . V_305 ,
128 , 1 ) ;
V_163 -> V_306 = ( V_160 >= 127 ? 1 : V_160 + 1 ) ;
}
if ( V_160 < 128 ) {
F_41 ( V_160 , V_163 -> V_304 . V_305 ) ;
V_13 -> V_160 = V_160 ;
}
}
static void F_124 ( struct V_1 * V_13 )
{
if ( V_13 -> V_160 > 0 ) {
F_69 ( V_13 -> V_160 , V_13 -> V_163 -> V_304 . V_305 ) ;
V_13 -> V_160 = - 1 ;
}
}
static void F_125 ( struct V_1 * V_13 , int V_160 )
{
if ( ! V_13 -> V_303 )
V_13 -> V_160 = V_160 ;
}
static void F_126 ( struct V_1 * V_13 )
{
struct V_182 * V_151 = F_54 ( V_13 -> V_163 ) ;
if ( V_151 -> V_152 -> V_307 && V_13 -> V_22 )
V_151 -> V_152 -> V_307 ( V_151 , V_13 ) ;
}
void F_74 ( struct V_1 * * V_308 )
{
struct V_1 * V_13 = * V_308 ;
int V_54 ;
F_61 ( V_13 , V_175 ) ;
F_81 ( & V_13 -> V_21 , L_72 ,
V_13 -> V_160 ) ;
F_127 ( V_13 ) ;
for ( V_54 = 0 ; V_54 < V_13 -> V_198 ; V_54 ++ ) {
if ( V_13 -> V_174 [ V_54 ] )
F_74 ( & V_13 -> V_174 [ V_54 ] ) ;
}
F_20 ( & V_13 -> V_21 , L_73 ) ;
F_128 ( V_13 , 0 ) ;
F_129 ( V_13 ) ;
F_130 ( & V_13 -> V_309 ) ;
F_131 ( V_13 ) ;
F_132 ( & V_13 -> V_21 ) ;
F_124 ( V_13 ) ;
F_98 ( & V_286 ) ;
* V_308 = NULL ;
F_101 ( & V_286 ) ;
F_126 ( V_13 ) ;
F_133 ( & V_13 -> V_21 ) ;
}
static void F_134 ( struct V_1 * V_13 , char * V_272 , char * string )
{
if ( ! string )
return;
F_135 ( V_310 , & V_13 -> V_21 , L_74 , V_272 , string ) ;
}
static void F_136 ( struct V_1 * V_13 )
{
F_81 ( & V_13 -> V_21 , L_75 ,
F_29 ( V_13 -> V_3 . V_311 ) ,
F_29 ( V_13 -> V_3 . V_312 ) ) ;
F_81 ( & V_13 -> V_21 ,
L_76 ,
V_13 -> V_3 . V_313 ,
V_13 -> V_3 . V_314 ,
V_13 -> V_3 . V_315 ) ;
F_134 ( V_13 , L_77 , V_13 -> V_316 ) ;
F_134 ( V_13 , L_78 , V_13 -> V_317 ) ;
F_134 ( V_13 , L_79 , V_13 -> V_318 ) ;
}
static inline void F_136 ( struct V_1 * V_13 ) { }
static int F_137 ( struct V_1 * V_13 )
{
int V_319 = 0 ;
#ifdef F_138
if ( ! V_13 -> V_163 -> V_320
&& V_13 -> V_321
&& V_13 -> V_22 == V_13 -> V_163 -> V_255 ) {
struct V_322 * V_262 = NULL ;
struct V_302 * V_163 = V_13 -> V_163 ;
if ( F_139 ( V_13 -> V_323 [ 0 ] ,
F_29 ( V_13 -> V_321 [ 0 ] . V_262 . V_324 ) ,
V_325 , ( void * * ) & V_262 ) == 0 ) {
if ( V_262 -> V_19 & V_326 ) {
unsigned V_70 = V_13 -> V_122 ;
F_81 ( & V_13 -> V_21 ,
L_80 ,
( V_70 == V_163 -> V_327 )
? L_37 : L_81 ) ;
if ( V_70 == V_163 -> V_327 )
V_163 -> V_328 = 1 ;
V_319 = F_13 ( V_13 ,
F_16 ( V_13 , 0 ) ,
V_72 , 0 ,
V_163 -> V_328
? V_329
: V_330 ,
0 , NULL , 0 , V_191 ) ;
if ( V_319 < 0 ) {
F_81 ( & V_13 -> V_21 ,
L_82 ,
V_319 ) ;
V_163 -> V_328 = 0 ;
}
}
}
}
if ( ! F_140 ( V_13 ) ) {
if ( V_13 -> V_163 -> V_328 || V_13 -> V_163 -> V_320 ) {
V_319 = F_141 ( V_13 , V_331 ) ;
if ( V_319 < 0 )
F_20 ( & V_13 -> V_21 , L_83 , V_319 ) ;
}
V_319 = - V_332 ;
goto V_230;
}
V_230:
#endif
return V_319 ;
}
static int F_142 ( struct V_1 * V_13 )
{
int V_319 ;
if ( V_13 -> V_321 == NULL ) {
V_319 = F_143 ( V_13 ) ;
if ( V_319 < 0 ) {
F_28 ( & V_13 -> V_21 , L_84 ,
V_319 ) ;
goto V_230;
}
}
if ( V_13 -> V_303 == 1 && V_13 -> V_333 == 0 ) {
V_13 -> V_316 = F_144 ( L_85 , V_229 ) ;
V_13 -> V_317 = F_144 ( L_85 , V_229 ) ;
V_13 -> V_318 = F_144 ( L_85 , V_229 ) ;
}
else {
V_13 -> V_316 = F_145 ( V_13 , V_13 -> V_3 . V_314 ) ;
V_13 -> V_317 = F_145 ( V_13 ,
V_13 -> V_3 . V_313 ) ;
V_13 -> V_318 = F_145 ( V_13 , V_13 -> V_3 . V_315 ) ;
}
V_319 = F_137 ( V_13 ) ;
V_230:
return V_319 ;
}
static void F_146 ( struct V_1 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_22 ;
struct V_6 * V_7 ;
T_2 V_110 = V_13 -> V_122 ;
T_1 V_168 ;
bool V_334 = true ;
if ( ! V_2 )
return;
V_7 = F_3 ( V_13 -> V_22 ) ;
V_168 = F_29 ( V_7 -> V_3 -> V_168 ) ;
if ( ! ( V_168 & V_233 ) )
return;
if ( F_1 ( V_2 ) ) {
if ( V_7 -> V_3 -> V_33 . V_34 . V_236 & ( 1 << V_110 ) )
V_334 = false ;
} else {
if ( V_7 -> V_3 -> V_33 . V_235 . V_236 [ V_110 / 8 ] & ( 1 << ( V_110 % 8 ) ) )
V_334 = false ;
}
if ( V_334 )
V_13 -> V_334 = V_335 ;
else
V_13 -> V_334 = V_336 ;
}
int F_147 ( struct V_1 * V_13 )
{
int V_319 ;
if ( V_13 -> V_22 ) {
F_148 ( & V_13 -> V_21 , 0 ) ;
}
F_149 ( & V_13 -> V_21 ) ;
F_150 ( & V_13 -> V_21 ) ;
F_151 ( & V_13 -> V_21 ) ;
F_152 ( & V_13 -> V_21 ) ;
F_153 ( V_13 ) ;
V_319 = F_142 ( V_13 ) ;
if ( V_319 < 0 )
goto V_230;
F_20 ( & V_13 -> V_21 , L_86 ,
V_13 -> V_160 , V_13 -> V_163 -> V_337 ,
( ( ( V_13 -> V_163 -> V_337 - 1 ) * 128 ) + ( V_13 -> V_160 - 1 ) ) ) ;
V_13 -> V_21 . V_338 = F_154 ( V_339 ,
( ( ( V_13 -> V_163 -> V_337 - 1 ) * 128 ) + ( V_13 -> V_160 - 1 ) ) ) ;
F_136 ( V_13 ) ;
F_155 ( & V_13 -> V_21 ) ;
if ( V_13 -> V_22 )
F_146 ( V_13 ) ;
V_319 = F_156 ( & V_13 -> V_21 ) ;
if ( V_319 ) {
F_28 ( & V_13 -> V_21 , L_87 , V_319 ) ;
goto V_230;
}
( void ) F_157 ( & V_13 -> V_21 , & V_13 -> V_309 , V_13 ) ;
F_158 ( V_13 ) ;
F_159 ( & V_13 -> V_21 ) ;
return V_319 ;
V_230:
F_61 ( V_13 , V_175 ) ;
F_160 ( & V_13 -> V_21 ) ;
F_161 ( & V_13 -> V_21 ) ;
return V_319 ;
}
int F_162 ( struct V_1 * V_340 )
{
F_127 ( V_340 ) ;
if ( V_340 -> V_333 == 0 )
goto V_341;
V_340 -> V_333 = 0 ;
F_163 ( V_340 , - 1 ) ;
F_48 ( V_340 -> V_316 ) ;
V_340 -> V_316 = F_144 ( L_85 , V_229 ) ;
F_48 ( V_340 -> V_317 ) ;
V_340 -> V_317 = F_144 ( L_85 , V_229 ) ;
F_48 ( V_340 -> V_318 ) ;
V_340 -> V_318 = F_144 ( L_85 , V_229 ) ;
F_164 ( V_340 ) ;
V_340 -> V_3 . V_342 = 0 ;
V_341:
F_131 ( V_340 ) ;
return 0 ;
}
int F_165 ( struct V_1 * V_340 )
{
int V_343 = 0 , V_344 ;
F_127 ( V_340 ) ;
if ( V_340 -> V_333 == 1 )
goto V_345;
V_343 = F_166 ( V_340 ) ;
if ( V_343 < 0 ) {
F_28 ( & V_340 -> V_21 ,
L_88 , V_343 ) ;
goto V_346;
}
V_343 = F_167 ( V_340 , sizeof( V_340 -> V_3 ) ) ;
if ( V_343 < 0 ) {
F_28 ( & V_340 -> V_21 , L_89
L_90 , V_343 ) ;
goto V_347;
}
F_48 ( V_340 -> V_316 ) ;
V_340 -> V_316 = NULL ;
F_48 ( V_340 -> V_317 ) ;
V_340 -> V_317 = NULL ;
F_48 ( V_340 -> V_318 ) ;
V_340 -> V_318 = NULL ;
V_340 -> V_333 = 1 ;
V_343 = F_142 ( V_340 ) ;
if ( V_343 < 0 )
goto V_348;
V_344 = F_168 ( V_340 ) ;
if ( V_344 >= 0 ) {
V_343 = F_163 ( V_340 , V_344 ) ;
if ( V_343 ) {
F_28 ( & V_340 -> V_21 ,
L_91 , V_344 , V_343 ) ;
}
}
F_81 ( & V_340 -> V_21 , L_92 ) ;
V_348:
V_347:
F_169 ( V_340 ) ;
V_346:
V_345:
F_131 ( V_340 ) ;
return V_343 ;
}
static unsigned F_170 ( struct V_6 * V_7 )
{
struct V_182 * V_151 ;
if ( V_7 -> V_2 -> V_22 != NULL )
return 0 ;
V_151 = F_22 ( V_7 -> V_2 -> V_163 , struct V_182 , V_349 ) ;
return V_151 -> V_350 ;
}
static bool F_171 ( struct V_6 * V_7 , T_1 V_8 )
{
return F_1 ( V_7 -> V_2 ) &&
( ( ( V_8 & V_209 ) ==
V_351 ) ||
( ( V_8 & V_209 ) ==
V_352 ) ) ;
}
static int F_172 ( struct V_6 * V_7 , int V_70 ,
struct V_1 * V_13 , unsigned int V_167 , bool V_353 )
{
int V_354 , V_55 ;
T_1 V_8 ;
T_1 V_199 ;
for ( V_354 = 0 ;
V_354 < V_355 ;
V_354 += V_167 ) {
F_58 ( V_167 ) ;
V_55 = F_26 ( V_7 , V_70 , & V_8 , & V_199 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( ! V_353 ) {
if ( F_171 ( V_7 , V_8 ) ) {
int V_55 ;
if ( ( V_199 & V_202 ) )
F_17 ( V_7 -> V_2 , V_70 ,
V_203 ) ;
if ( V_199 & V_356 )
F_17 ( V_7 -> V_2 , V_70 ,
V_357 ) ;
if ( V_199 & V_358 )
F_17 ( V_7 -> V_2 , V_70 ,
V_359 ) ;
F_20 ( V_7 -> V_111 , L_93 ,
V_70 ) ;
V_55 = F_173 ( V_7 , V_70 ,
V_13 , V_360 ,
true ) ;
if ( ( V_199 & V_202 ) )
F_17 ( V_7 -> V_2 , V_70 ,
V_203 ) ;
return V_55 ;
}
if ( ! ( V_8 & V_200 ) )
return - V_361 ;
if ( ( V_199 & V_202 ) )
return - V_361 ;
if ( ! ( V_8 & V_362 ) &&
( V_8 & V_201 ) ) {
if ( F_170 ( V_7 ) )
V_13 -> V_14 = V_363 ;
else if ( F_1 ( V_7 -> V_2 ) )
V_13 -> V_14 = V_48 ;
else if ( V_8 & V_9 )
V_13 -> V_14 = V_15 ;
else if ( V_8 & V_10 )
V_13 -> V_14 = V_364 ;
else
V_13 -> V_14 = V_365 ;
return 0 ;
}
} else {
if ( V_199 & V_206 )
return 0 ;
}
if ( V_354 >= 2 * V_366 )
V_167 = V_367 ;
F_20 ( V_7 -> V_111 ,
L_94 ,
V_70 , V_353 ? L_95 : L_37 , V_167 ) ;
}
return - V_293 ;
}
static void F_174 ( struct V_6 * V_7 , int V_70 ,
struct V_1 * V_13 , int * V_74 , bool V_353 )
{
switch ( * V_74 ) {
case 0 :
if ( ! V_353 ) {
struct V_182 * V_151 ;
F_58 ( 10 + 40 ) ;
F_125 ( V_13 , 0 ) ;
V_151 = F_54 ( V_13 -> V_163 ) ;
if ( V_151 -> V_152 -> V_368 ) {
* V_74 = V_151 -> V_152 -> V_368 ( V_151 , V_13 ) ;
if ( * V_74 < 0 ) {
F_28 ( & V_13 -> V_21 , L_96
L_97 ) ;
break;
}
}
}
case - V_361 :
case - V_136 :
F_17 ( V_7 -> V_2 ,
V_70 , V_359 ) ;
if ( V_353 ) {
F_17 ( V_7 -> V_2 , V_70 ,
V_207 ) ;
F_17 ( V_7 -> V_2 , V_70 ,
V_357 ) ;
} else {
F_61 ( V_13 , * V_74
? V_175
: V_369 ) ;
}
break;
}
}
static int F_173 ( struct V_6 * V_7 , int V_70 ,
struct V_1 * V_13 , unsigned int V_167 , bool V_353 )
{
int V_54 , V_74 ;
if ( ! V_353 ) {
F_175 ( & V_370 ) ;
} else {
if ( ! F_1 ( V_7 -> V_2 ) ) {
F_28 ( V_7 -> V_111 , L_98
L_99 ) ;
return - V_67 ;
}
}
for ( V_54 = 0 ; V_54 < V_371 ; V_54 ++ ) {
V_74 = F_18 ( V_7 -> V_2 , V_70 , ( V_353 ?
V_372 :
V_373 ) ) ;
if ( V_74 ) {
F_28 ( V_7 -> V_111 ,
L_100 ,
V_353 ? L_95 : L_37 , V_70 , V_74 ) ;
} else {
V_74 = F_172 ( V_7 , V_70 , V_13 , V_167 ,
V_353 ) ;
if ( V_74 && V_74 != - V_361 )
F_20 ( V_7 -> V_111 ,
L_101 ,
V_74 ) ;
}
if ( V_74 == 0 || V_74 == - V_361 || V_74 == - V_136 ) {
F_174 ( V_7 , V_70 , V_13 , & V_74 , V_353 ) ;
goto V_374;
}
F_20 ( V_7 -> V_111 ,
L_102 ,
V_70 , V_353 ? L_95 : L_37 ) ;
V_167 = V_367 ;
}
F_28 ( V_7 -> V_111 ,
L_103 ,
V_70 ) ;
V_374:
if ( ! V_353 )
F_176 ( & V_370 ) ;
return V_74 ;
}
static int F_177 ( struct V_6 * V_7 , unsigned V_8 )
{
int V_55 = 0 ;
if ( F_1 ( V_7 -> V_2 ) ) {
if ( V_8 & V_375 )
V_55 = 1 ;
} else {
if ( V_8 & V_376 )
V_55 = 1 ;
}
return V_55 ;
}
static int F_178 ( struct V_6 * V_7 , unsigned V_8 )
{
int V_55 = 0 ;
if ( F_1 ( V_7 -> V_2 ) ) {
if ( ( V_8 & V_209 )
== V_377 )
V_55 = 1 ;
} else {
if ( V_8 & V_378 )
V_55 = 1 ;
}
return V_55 ;
}
static int F_179 ( struct V_1 * V_13 ,
struct V_6 * V_7 , int V_70 ,
int V_74 , unsigned V_199 , unsigned V_8 )
{
if ( V_74 || F_178 ( V_7 , V_8 ) ||
! F_177 ( V_7 , V_8 ) ||
! ( V_8 & V_200 ) ) {
if ( V_74 >= 0 )
V_74 = - V_136 ;
}
else if ( ! ( V_8 & V_201 ) && ! V_13 -> V_212 ) {
if ( V_13 -> V_211 )
V_13 -> V_212 = 1 ;
else
V_74 = - V_136 ;
}
if ( V_74 ) {
F_20 ( V_7 -> V_111 ,
L_104 ,
V_70 , V_199 , V_8 , V_74 ) ;
} else if ( V_13 -> V_212 ) {
if ( V_199 & V_202 )
F_17 ( V_7 -> V_2 , V_70 ,
V_203 ) ;
if ( V_199 & V_204 )
F_17 ( V_7 -> V_2 , V_70 ,
V_205 ) ;
}
return V_74 ;
}
int F_141 ( struct V_1 * V_13 , T_3 V_379 )
{
struct V_6 * V_7 = F_3 ( V_13 -> V_22 ) ;
int V_70 = V_13 -> V_122 ;
int V_74 ;
if ( V_13 -> V_380 ) {
if ( ! F_1 ( V_7 -> V_2 ) ) {
V_74 = F_13 ( V_13 , F_16 ( V_13 , 0 ) ,
V_72 , V_254 ,
V_381 , 0 ,
NULL , 0 ,
V_191 ) ;
} else {
V_74 = F_13 ( V_13 , F_16 ( V_13 , 0 ) ,
V_72 ,
V_382 ,
V_383 ,
V_384 |
V_385 ,
NULL , 0 ,
V_191 ) ;
}
if ( V_74 ) {
F_20 ( & V_13 -> V_21 , L_105 ,
V_74 ) ;
if ( F_180 ( V_379 ) )
return V_74 ;
}
}
if ( V_13 -> V_386 == 1 )
F_181 ( V_13 , 0 ) ;
if ( F_182 ( V_13 ) ) {
F_28 ( & V_13 -> V_21 , L_106 ,
V_112 ) ;
return - V_157 ;
}
if ( F_1 ( V_7 -> V_2 ) )
V_74 = F_18 ( V_7 -> V_2 ,
V_70 | ( V_377 << 3 ) ,
V_387 ) ;
else
V_74 = F_18 ( V_7 -> V_2 , V_70 ,
V_388 ) ;
if ( V_74 ) {
F_20 ( V_7 -> V_111 , L_107 ,
V_70 , V_74 ) ;
if ( V_13 -> V_380 )
( void ) F_13 ( V_13 , F_16 ( V_13 , 0 ) ,
V_69 , V_254 ,
V_381 , 0 ,
NULL , 0 ,
V_191 ) ;
if ( V_13 -> V_389 == 1 )
F_181 ( V_13 , 1 ) ;
F_183 ( V_13 ) ;
if ( ! F_180 ( V_379 ) )
V_74 = 0 ;
} else {
F_20 ( & V_13 -> V_21 , L_108 ,
( F_180 ( V_379 ) ? L_109 : L_37 ) ,
V_13 -> V_380 ) ;
F_61 ( V_13 , V_295 ) ;
F_58 ( 10 ) ;
}
F_158 ( V_7 -> V_2 ) ;
return V_74 ;
}
static int F_184 ( struct V_1 * V_13 )
{
int V_74 = 0 ;
T_1 V_390 ;
F_20 ( & V_13 -> V_21 , L_110 ,
V_13 -> V_212 ? L_111 : L_112 ) ;
F_61 ( V_13 , V_13 -> V_11
? V_82
: V_391 ) ;
if ( V_13 -> V_212 )
V_392:
V_74 = F_185 ( V_13 ) ;
if ( V_74 == 0 ) {
V_390 = 0 ;
V_74 = F_87 ( V_13 , V_254 , 0 , & V_390 ) ;
if ( V_74 >= 0 )
V_74 = ( V_74 > 0 ? 0 : - V_136 ) ;
if ( V_74 && ! V_13 -> V_212 && V_13 -> V_211 ) {
F_20 ( & V_13 -> V_21 , L_113 ) ;
V_13 -> V_212 = 1 ;
goto V_392;
}
}
if ( V_74 ) {
F_20 ( & V_13 -> V_21 , L_114 ,
V_74 ) ;
} else if ( V_13 -> V_11 ) {
F_88 ( & V_390 ) ;
if ( V_390 & ( 1 << V_381 ) ) {
V_74 = F_13 ( V_13 ,
F_16 ( V_13 , 0 ) ,
V_69 ,
V_254 ,
V_381 , 0 ,
NULL , 0 ,
V_191 ) ;
if ( V_74 )
F_20 ( & V_13 -> V_21 ,
L_115 ,
V_74 ) ;
}
V_74 = 0 ;
}
return V_74 ;
}
int F_186 ( struct V_1 * V_13 , T_3 V_379 )
{
struct V_6 * V_7 = F_3 ( V_13 -> V_22 ) ;
int V_70 = V_13 -> V_122 ;
int V_74 ;
T_1 V_199 , V_8 ;
V_74 = F_26 ( V_7 , V_70 , & V_8 , & V_199 ) ;
if ( V_74 == 0 && ! F_178 ( V_7 , V_8 ) )
goto V_393;
F_41 ( V_70 , V_7 -> V_394 ) ;
if ( F_1 ( V_7 -> V_2 ) )
V_74 = F_18 ( V_7 -> V_2 ,
V_70 | ( V_210 << 3 ) ,
V_387 ) ;
else
V_74 = F_17 ( V_7 -> V_2 ,
V_70 , V_388 ) ;
if ( V_74 ) {
F_20 ( V_7 -> V_111 , L_116 ,
V_70 , V_74 ) ;
} else {
F_20 ( & V_13 -> V_21 , L_117 ,
( F_180 ( V_379 ) ? L_109 : L_37 ) ) ;
F_58 ( 25 ) ;
V_74 = F_26 ( V_7 , V_70 , & V_8 , & V_199 ) ;
F_58 ( 10 ) ;
}
V_393:
if ( V_74 == 0 ) {
if ( F_1 ( V_7 -> V_2 ) ) {
if ( V_199 & V_356 )
F_17 ( V_7 -> V_2 , V_70 ,
V_357 ) ;
} else {
if ( V_199 & V_395 )
F_17 ( V_7 -> V_2 , V_70 ,
V_396 ) ;
}
}
F_69 ( V_70 , V_7 -> V_394 ) ;
V_74 = F_179 ( V_13 ,
V_7 , V_70 , V_74 , V_199 , V_8 ) ;
if ( V_74 == 0 )
V_74 = F_184 ( V_13 ) ;
if ( V_74 < 0 ) {
F_20 ( & V_13 -> V_21 , L_118 , V_74 ) ;
F_62 ( V_7 , V_70 ) ;
} else {
if ( V_13 -> V_389 == 1 )
F_181 ( V_13 , 1 ) ;
F_183 ( V_13 ) ;
}
return V_74 ;
}
int F_187 ( struct V_1 * V_13 )
{
int V_74 = 0 ;
if ( V_13 -> V_81 == V_295 ) {
F_20 ( & V_13 -> V_21 , L_117 , L_119 ) ;
V_74 = F_166 ( V_13 ) ;
if ( V_74 == 0 ) {
F_169 ( V_13 ) ;
}
}
return V_74 ;
}
int F_141 ( struct V_1 * V_13 , T_3 V_379 )
{
return 0 ;
}
int F_186 ( struct V_1 * V_13 , T_3 V_379 )
{
struct V_6 * V_7 = F_3 ( V_13 -> V_22 ) ;
int V_70 = V_13 -> V_122 ;
int V_74 ;
T_1 V_199 , V_8 ;
V_74 = F_26 ( V_7 , V_70 , & V_8 , & V_199 ) ;
V_74 = F_179 ( V_13 ,
V_7 , V_70 , V_74 , V_199 , V_8 ) ;
if ( V_74 ) {
F_20 ( & V_13 -> V_21 , L_118 , V_74 ) ;
F_62 ( V_7 , V_70 ) ;
} else if ( V_13 -> V_212 ) {
F_20 ( & V_13 -> V_21 , L_120 ) ;
V_74 = F_185 ( V_13 ) ;
}
return V_74 ;
}
static int F_188 ( struct V_178 * V_179 , T_3 V_379 )
{
struct V_6 * V_7 = F_4 ( V_179 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
unsigned V_70 ;
int V_74 ;
for ( V_70 = 1 ; V_70 <= V_2 -> V_198 ; V_70 ++ ) {
struct V_1 * V_13 ;
V_13 = V_2 -> V_174 [ V_70 - 1 ] ;
if ( V_13 && V_13 -> V_397 ) {
F_7 ( & V_179 -> V_21 , L_121 , V_70 ) ;
if ( F_180 ( V_379 ) )
return - V_293 ;
}
}
if ( F_1 ( V_2 ) && V_2 -> V_380 ) {
for ( V_70 = 1 ; V_70 <= V_2 -> V_198 ; V_70 ++ ) {
V_74 = F_18 ( V_2 ,
V_70 |
V_398 |
V_399 |
V_400 ,
V_401 ) ;
}
}
F_20 ( & V_179 -> V_21 , L_110 , V_112 ) ;
F_72 ( V_7 , V_218 ) ;
return 0 ;
}
static int F_189 ( struct V_178 * V_179 )
{
struct V_6 * V_7 = F_4 ( V_179 ) ;
F_20 ( & V_179 -> V_21 , L_110 , V_112 ) ;
F_66 ( V_7 , V_188 ) ;
return 0 ;
}
static int F_190 ( struct V_178 * V_179 )
{
struct V_6 * V_7 = F_4 ( V_179 ) ;
F_20 ( & V_179 -> V_21 , L_110 , V_112 ) ;
F_66 ( V_7 , V_195 ) ;
return 0 ;
}
void F_191 ( struct V_1 * V_402 )
{
F_7 ( & V_402 -> V_21 , L_122 ) ;
V_402 -> V_212 = 1 ;
}
static int F_192 ( struct V_1 * V_13 , enum V_403 V_81 )
{
struct V_404 * V_405 ;
unsigned long long V_406 ;
unsigned long long V_407 ;
unsigned long long V_408 ;
unsigned long long V_409 ;
int V_55 ;
V_406 = F_193 ( V_13 -> V_51 . V_42 , 1000 ) ;
V_407 = F_193 ( V_13 -> V_51 . V_39 , 1000 ) ;
V_408 = F_193 ( V_13 -> V_52 . V_42 , 1000 ) ;
V_409 = F_193 ( V_13 -> V_52 . V_39 , 1000 ) ;
if ( ( V_81 == V_410 &&
( V_406 > V_411 ||
V_407 > V_411 ) ) ||
( V_81 == V_412 &&
( V_408 > V_413 ||
V_409 > V_413 ) ) ) {
F_20 ( & V_13 -> V_21 , L_123
L_124 ,
V_414 [ V_81 ] , V_406 , V_407 ) ;
return - V_67 ;
}
if ( V_406 > V_411 )
V_406 = V_411 ;
if ( V_407 > V_411 )
V_407 = V_411 ;
if ( V_408 > V_413 )
V_408 = V_413 ;
if ( V_409 > V_413 )
V_409 = V_413 ;
V_405 = F_50 ( sizeof *( V_405 ) , V_197 ) ;
if ( ! V_405 )
return - V_157 ;
V_405 -> V_406 = V_406 ;
V_405 -> V_407 = V_407 ;
V_405 -> V_408 = F_194 ( V_408 ) ;
V_405 -> V_409 = F_194 ( V_409 ) ;
V_55 = F_13 ( V_13 , F_16 ( V_13 , 0 ) ,
V_415 ,
V_254 ,
0 , 0 ,
V_405 , sizeof *( V_405 ) ,
V_191 ) ;
F_48 ( V_405 ) ;
return V_55 ;
}
static int F_195 ( struct V_1 * V_13 ,
enum V_403 V_81 , bool V_416 )
{
int V_55 ;
int V_68 ;
switch ( V_81 ) {
case V_410 :
V_68 = V_417 ;
break;
case V_412 :
V_68 = V_418 ;
break;
default:
F_7 ( & V_13 -> V_21 , L_125 ,
V_112 , V_416 ? L_126 : L_127 ) ;
return - V_67 ;
}
if ( V_13 -> V_81 != V_82 ) {
F_20 ( & V_13 -> V_21 , L_128
L_129 ,
V_112 , V_416 ? L_126 : L_127 ,
V_414 [ V_81 ] ) ;
return 0 ;
}
if ( V_416 ) {
V_55 = F_192 ( V_13 , V_81 ) ;
if ( V_55 < 0 ) {
F_7 ( & V_13 -> V_21 , L_130
L_131 , V_414 [ V_81 ] ) ;
return - V_293 ;
}
V_55 = F_13 ( V_13 , F_16 ( V_13 , 0 ) ,
V_72 ,
V_254 ,
V_68 ,
0 , NULL , 0 ,
V_191 ) ;
} else {
V_55 = F_13 ( V_13 , F_16 ( V_13 , 0 ) ,
V_69 ,
V_254 ,
V_68 ,
0 , NULL , 0 ,
V_191 ) ;
}
if ( V_55 < 0 ) {
F_7 ( & V_13 -> V_21 , L_132 ,
V_416 ? L_133 : L_134 ,
V_414 [ V_81 ] ) ;
return - V_293 ;
}
return 0 ;
}
static int F_196 ( struct V_1 * V_13 ,
enum V_403 V_81 , int V_419 )
{
int V_55 ;
int V_68 ;
switch ( V_81 ) {
case V_410 :
V_68 = V_420 ;
break;
case V_412 :
V_68 = V_421 ;
break;
default:
F_7 ( & V_13 -> V_21 , L_135 ,
V_112 ) ;
return - V_67 ;
}
if ( V_81 == V_410 && V_419 > V_422 &&
V_419 != V_423 ) {
F_7 ( & V_13 -> V_21 , L_136
L_137 ,
V_414 [ V_81 ] , V_419 ) ;
return - V_67 ;
}
V_55 = F_18 ( V_13 -> V_22 ,
F_197 ( V_419 ) | V_13 -> V_122 ,
V_68 ) ;
if ( V_55 < 0 ) {
F_7 ( & V_13 -> V_21 , L_138
L_139 , V_414 [ V_81 ] ,
V_419 , V_55 ) ;
return - V_293 ;
}
if ( V_81 == V_410 )
V_13 -> V_51 . V_419 = V_419 ;
else
V_13 -> V_52 . V_419 = V_419 ;
return 0 ;
}
static void F_198 ( struct V_182 * V_151 , struct V_1 * V_13 ,
enum V_403 V_81 )
{
int V_419 ;
V_419 = V_151 -> V_152 -> V_424 ( V_151 , V_13 , V_81 ) ;
if ( V_419 == 0 )
return;
if ( V_419 < 0 ) {
F_7 ( & V_13 -> V_21 , L_140
L_141 , V_414 [ V_81 ] ,
V_419 ) ;
return;
}
if ( F_196 ( V_13 , V_81 , V_419 ) )
V_151 -> V_152 -> V_425 ( V_151 , V_13 , V_81 ) ;
else if ( V_13 -> V_11 )
F_195 ( V_13 , V_81 , true ) ;
}
static int F_199 ( struct V_182 * V_151 , struct V_1 * V_13 ,
enum V_403 V_81 )
{
int V_68 ;
switch ( V_81 ) {
case V_410 :
V_68 = V_420 ;
break;
case V_412 :
V_68 = V_421 ;
break;
default:
F_7 ( & V_13 -> V_21 , L_142 ,
V_112 ) ;
return - V_67 ;
}
if ( F_196 ( V_13 , V_81 , 0 ) )
return - V_293 ;
F_195 ( V_13 , V_81 , false ) ;
if ( V_151 -> V_152 -> V_425 ( V_151 , V_13 , V_81 ) )
F_7 ( & V_13 -> V_21 , L_143
L_144 ,
V_414 [ V_81 ] ) ;
return 0 ;
}
int F_200 ( struct V_1 * V_13 )
{
struct V_182 * V_151 ;
if ( ! V_13 || ! V_13 -> V_22 ||
V_13 -> V_14 != V_48 ||
! V_13 -> V_23 )
return 0 ;
V_151 = F_54 ( V_13 -> V_163 ) ;
if ( ! V_151 || ! V_151 -> V_152 -> V_425 )
return 0 ;
V_13 -> V_426 ++ ;
if ( ( V_13 -> V_51 . V_419 == 0 && V_13 -> V_52 . V_419 == 0 ) )
return 0 ;
if ( F_199 ( V_151 , V_13 , V_410 ) )
goto V_427;
if ( F_199 ( V_151 , V_13 , V_412 ) )
goto V_427;
return 0 ;
V_427:
F_201 ( V_13 ) ;
return - V_293 ;
}
int F_182 ( struct V_1 * V_13 )
{
struct V_182 * V_151 = F_54 ( V_13 -> V_163 ) ;
int V_55 ;
if ( ! V_151 )
return - V_67 ;
F_27 ( V_151 -> V_428 ) ;
V_55 = F_200 ( V_13 ) ;
F_30 ( V_151 -> V_428 ) ;
return V_55 ;
}
void F_201 ( struct V_1 * V_13 )
{
struct V_182 * V_151 ;
if ( ! V_13 || ! V_13 -> V_22 ||
V_13 -> V_14 != V_48 ||
! V_13 -> V_23 )
return;
V_13 -> V_426 -- ;
V_151 = F_54 ( V_13 -> V_163 ) ;
if ( ! V_151 || ! V_151 -> V_152 -> V_424 ||
! V_151 -> V_152 -> V_425 )
return;
if ( V_13 -> V_426 > 0 )
return;
F_198 ( V_151 , V_13 , V_410 ) ;
F_198 ( V_151 , V_13 , V_412 ) ;
}
void F_183 ( struct V_1 * V_13 )
{
struct V_182 * V_151 = F_54 ( V_13 -> V_163 ) ;
if ( ! V_151 )
return;
F_27 ( V_151 -> V_428 ) ;
F_201 ( V_13 ) ;
F_30 ( V_151 -> V_428 ) ;
}
int F_200 ( struct V_1 * V_13 )
{
return 0 ;
}
void F_201 ( struct V_1 * V_13 ) { }
int F_182 ( struct V_1 * V_13 )
{
return 0 ;
}
void F_183 ( struct V_1 * V_13 ) { }
static int F_202 ( struct V_6 * V_7 , int V_70 )
{
int V_55 ;
int V_429 , V_430 = 0 ;
T_1 V_199 , V_8 ;
unsigned V_431 = 0xffff ;
for ( V_429 = 0 ; ; V_429 += V_432 ) {
V_55 = F_26 ( V_7 , V_70 , & V_8 , & V_199 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( ! ( V_199 & V_202 ) &&
( V_8 & V_200 ) == V_431 ) {
V_430 += V_432 ;
if ( V_430 >= V_213 )
break;
} else {
V_430 = 0 ;
V_431 = V_8 & V_200 ;
}
if ( V_199 & V_202 ) {
F_17 ( V_7 -> V_2 , V_70 ,
V_203 ) ;
}
if ( V_429 >= V_433 )
break;
F_58 ( V_432 ) ;
}
F_20 ( V_7 -> V_111 ,
L_145 ,
V_70 , V_429 , V_430 , V_8 ) ;
if ( V_430 < V_213 )
return - V_102 ;
return V_8 ;
}
void F_203 ( struct V_1 * V_13 )
{
F_204 ( V_13 , 0 + V_63 , true ) ;
F_204 ( V_13 , 0 + V_434 , true ) ;
F_205 ( V_13 , & V_13 -> V_309 , true ) ;
}
static int F_206 ( struct V_1 * V_13 , int V_160 )
{
int V_435 ;
struct V_182 * V_151 = F_54 ( V_13 -> V_163 ) ;
if ( ! V_151 -> V_152 -> V_436 && V_160 <= 1 )
return - V_67 ;
if ( V_13 -> V_81 == V_391 )
return 0 ;
if ( V_13 -> V_81 != V_369 )
return - V_67 ;
if ( V_151 -> V_152 -> V_436 )
V_435 = V_151 -> V_152 -> V_436 ( V_151 , V_13 ) ;
else
V_435 = F_13 ( V_13 , F_207 () ,
V_437 , 0 , V_160 , 0 ,
NULL , 0 , V_191 ) ;
if ( V_435 == 0 ) {
F_125 ( V_13 , V_160 ) ;
F_61 ( V_13 , V_391 ) ;
F_203 ( V_13 ) ;
}
return V_435 ;
}
static int
F_208 ( struct V_6 * V_7 , struct V_1 * V_13 , int V_70 ,
int V_438 )
{
static F_209 ( V_439 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_182 * V_151 = F_54 ( V_2 -> V_163 ) ;
int V_54 , V_440 , V_435 ;
unsigned V_167 = V_366 ;
enum V_441 V_442 = V_13 -> V_14 ;
const char * V_14 ;
int V_160 = V_13 -> V_160 ;
if ( ! V_2 -> V_22 ) {
V_167 = V_443 ;
if ( V_70 == V_2 -> V_163 -> V_327 )
V_2 -> V_163 -> V_328 = 0 ;
}
if ( V_442 == V_364 )
V_167 = V_367 ;
F_27 ( & V_439 ) ;
V_435 = F_173 ( V_7 , V_70 , V_13 , V_167 , false ) ;
if ( V_435 < 0 )
goto V_230;
V_435 = - V_136 ;
if ( V_442 != V_444 && V_442 != V_13 -> V_14 ) {
F_20 ( & V_13 -> V_21 , L_146 ) ;
goto V_230;
}
V_442 = V_13 -> V_14 ;
switch ( V_13 -> V_14 ) {
case V_48 :
case V_363 :
V_13 -> V_309 . V_262 . V_445 = F_194 ( 512 ) ;
break;
case V_15 :
V_13 -> V_309 . V_262 . V_445 = F_194 ( 64 ) ;
break;
case V_365 :
V_13 -> V_309 . V_262 . V_445 = F_194 ( 64 ) ;
break;
case V_364 :
V_13 -> V_309 . V_262 . V_445 = F_194 ( 8 ) ;
break;
default:
goto V_230;
}
if ( V_13 -> V_14 == V_363 )
V_14 = L_147 ;
else
V_14 = F_210 ( V_13 -> V_14 ) ;
if ( V_13 -> V_14 != V_48 )
F_81 ( & V_13 -> V_21 ,
L_148 ,
( V_13 -> V_321 ) ? L_149 : L_150 , V_14 ,
V_160 , V_13 -> V_163 -> V_446 -> V_152 -> V_447 ) ;
if ( V_2 -> V_139 ) {
V_13 -> V_139 = V_2 -> V_139 ;
V_13 -> V_159 = V_2 -> V_159 ;
} else if ( V_13 -> V_14 != V_15
&& V_2 -> V_14 == V_15 ) {
if ( ! V_7 -> V_139 . V_7 ) {
F_28 ( & V_13 -> V_21 , L_151 ) ;
V_435 = - V_67 ;
goto V_230;
}
V_13 -> V_139 = & V_7 -> V_139 ;
V_13 -> V_159 = V_70 ;
}
for ( V_54 = 0 ; V_54 < V_448 ; ( ++ V_54 , F_58 ( 100 ) ) ) {
if ( F_211 ( V_438 ) && ! ( V_151 -> V_152 -> V_116 & V_449 ) ) {
struct V_450 * V_451 ;
int V_452 = 0 ;
#define F_212 64
V_451 = F_50 ( F_212 , V_197 ) ;
if ( ! V_451 ) {
V_435 = - V_157 ;
continue;
}
for ( V_440 = 0 ; V_440 < 3 ; ++ V_440 ) {
V_451 -> V_453 = 0 ;
V_452 = F_13 ( V_13 , F_213 () ,
V_62 , V_63 ,
V_454 << 8 , 0 ,
V_451 , F_212 ,
V_455 ) ;
switch ( V_451 -> V_453 ) {
case 8 : case 16 : case 32 : case 64 : case 255 :
if ( V_451 -> V_456 ==
V_454 ) {
V_452 = 0 ;
break;
}
default:
if ( V_452 == 0 )
V_452 = - V_457 ;
break;
}
if ( V_452 == 0 )
break;
}
V_13 -> V_3 . V_453 =
V_451 -> V_453 ;
F_48 ( V_451 ) ;
V_435 = F_173 ( V_7 , V_70 , V_13 , V_167 , false ) ;
if ( V_435 < 0 )
goto V_230;
if ( V_442 != V_13 -> V_14 ) {
F_20 ( & V_13 -> V_21 ,
L_146 ) ;
V_435 = - V_136 ;
goto V_230;
}
if ( V_452 ) {
F_28 ( & V_13 -> V_21 ,
L_152 ,
V_452 ) ;
V_435 = - V_458 ;
continue;
}
#undef F_212
}
if ( V_13 -> V_303 == 0 ) {
for ( V_440 = 0 ; V_440 < V_459 ; ++ V_440 ) {
V_435 = F_206 ( V_13 , V_160 ) ;
if ( V_435 >= 0 )
break;
F_58 ( 200 ) ;
}
if ( V_435 < 0 ) {
F_28 ( & V_13 -> V_21 ,
L_153 ,
V_160 , V_435 ) ;
goto V_230;
}
if ( V_13 -> V_14 == V_48 ) {
V_160 = V_13 -> V_160 ;
F_81 ( & V_13 -> V_21 ,
L_154 ,
( V_13 -> V_321 ) ? L_149 : L_150 ,
V_160 , V_13 -> V_163 -> V_446 -> V_152 -> V_447 ) ;
}
F_58 ( 10 ) ;
if ( F_211 ( V_438 ) && ! ( V_151 -> V_152 -> V_116 & V_449 ) )
break;
}
V_435 = F_167 ( V_13 , 8 ) ;
if ( V_435 < 8 ) {
F_28 ( & V_13 -> V_21 ,
L_155 ,
V_435 ) ;
if ( V_435 >= 0 )
V_435 = - V_458 ;
} else {
V_435 = 0 ;
break;
}
}
if ( V_435 )
goto V_230;
if ( ( V_13 -> V_14 == V_48 ) &&
( F_29 ( V_13 -> V_3 . V_460 ) < 0x0300 ) ) {
F_28 ( & V_13 -> V_21 , L_156
L_157 ) ;
F_173 ( V_7 , V_70 , V_13 ,
V_360 , true ) ;
V_435 = - V_67 ;
goto V_230;
}
if ( V_13 -> V_3 . V_453 == 0xff ||
V_13 -> V_14 == V_48 )
V_54 = 512 ;
else
V_54 = V_13 -> V_3 . V_453 ;
if ( F_214 ( & V_13 -> V_309 . V_262 ) != V_54 ) {
if ( V_13 -> V_14 == V_364 ||
! ( V_54 == 8 || V_54 == 16 || V_54 == 32 || V_54 == 64 ) ) {
F_28 ( & V_13 -> V_21 , L_158 , V_54 ) ;
V_435 = - V_458 ;
goto V_230;
}
if ( V_13 -> V_14 == V_365 )
F_20 ( & V_13 -> V_21 , L_159 , V_54 ) ;
else
F_7 ( & V_13 -> V_21 , L_160 , V_54 ) ;
V_13 -> V_309 . V_262 . V_445 = F_194 ( V_54 ) ;
F_203 ( V_13 ) ;
}
V_435 = F_167 ( V_13 , V_461 ) ;
if ( V_435 < ( signed ) sizeof( V_13 -> V_3 ) ) {
F_28 ( & V_13 -> V_21 , L_161 ,
V_435 ) ;
if ( V_435 >= 0 )
V_435 = - V_462 ;
goto V_230;
}
if ( V_13 -> V_303 == 0 && F_29 ( V_13 -> V_3 . V_460 ) >= 0x0201 ) {
V_435 = F_215 ( V_13 ) ;
if ( ! V_435 ) {
V_13 -> V_23 = F_5 ( V_13 ) ;
F_11 ( V_13 ) ;
}
}
V_435 = 0 ;
if ( V_151 -> V_152 -> V_463 )
V_151 -> V_152 -> V_463 ( V_151 , V_13 ) ;
V_230:
if ( V_435 ) {
F_60 ( V_7 , V_70 , 0 ) ;
F_125 ( V_13 , V_160 ) ;
}
F_30 ( & V_439 ) ;
return V_435 ;
}
static void
F_216 ( struct V_6 * V_7 , struct V_1 * V_13 , int V_70 )
{
struct V_464 * V_465 ;
int V_74 ;
V_465 = F_50 ( sizeof *V_465 , V_229 ) ;
if ( V_465 == NULL )
return;
V_74 = F_217 ( V_13 , V_466 , 0 ,
V_465 , sizeof *V_465 ) ;
if ( V_74 == sizeof *V_465 ) {
F_81 ( & V_13 -> V_21 , L_162
L_163 ) ;
if ( V_7 -> V_215 ) {
V_7 -> V_86 [ V_70 - 1 ] = V_90 ;
F_23 ( & V_7 -> V_78 , 0 ) ;
}
}
F_48 ( V_465 ) ;
}
static unsigned
F_218 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_261 ;
int V_70 ;
if ( ! V_7 -> V_258 )
return 0 ;
V_261 = V_2 -> V_256 - V_7 -> V_3 -> V_260 ;
for ( V_70 = 1 ; V_70 <= V_2 -> V_198 ; ++ V_70 ) {
struct V_1 * V_13 = V_2 -> V_174 [ V_70 - 1 ] ;
int V_467 ;
if ( ! V_13 )
continue;
if ( V_13 -> V_11 )
V_467 = V_13 -> V_11 -> V_262 . V_468 * 2 ;
else if ( V_70 != V_13 -> V_163 -> V_327 || V_2 -> V_22 )
V_467 = 100 ;
else
V_467 = 8 ;
if ( V_467 > V_7 -> V_257 )
F_7 ( & V_13 -> V_21 ,
L_164 ,
V_467 , V_7 -> V_257 , V_70 ) ;
V_261 -= V_467 ;
}
if ( V_261 < 0 ) {
F_7 ( V_7 -> V_111 , L_165 ,
- V_261 ) ;
V_261 = 0 ;
}
return V_261 ;
}
static void F_219 ( struct V_6 * V_7 , int V_70 ,
T_1 V_8 , T_1 V_199 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_223 * V_224 = V_7 -> V_111 ;
struct V_182 * V_151 = F_54 ( V_2 -> V_163 ) ;
unsigned V_168 =
F_29 ( V_7 -> V_3 -> V_168 ) ;
struct V_1 * V_13 ;
int V_74 , V_54 ;
F_20 ( V_224 ,
L_166 ,
V_70 , V_8 , V_199 , F_2 ( V_7 , V_8 ) ) ;
if ( V_7 -> V_215 ) {
F_19 ( V_7 , V_70 , V_88 ) ;
V_7 -> V_86 [ V_70 - 1 ] = V_89 ;
}
#ifdef F_138
if ( V_2 -> V_163 -> V_320 )
V_199 &= ~ ( V_202 |
V_204 ) ;
#endif
V_13 = V_2 -> V_174 [ V_70 - 1 ] ;
if ( ( V_8 & V_200 ) && V_13 &&
V_13 -> V_81 != V_175 ) {
F_127 ( V_13 ) ;
if ( V_8 & V_201 ) {
V_74 = 0 ;
#ifdef F_220
} else if ( V_13 -> V_81 == V_295 &&
V_13 -> V_211 ) {
V_74 = F_187 ( V_13 ) ;
#endif
} else {
V_74 = - V_136 ;
}
F_131 ( V_13 ) ;
if ( V_74 == 0 ) {
F_69 ( V_70 , V_7 -> V_177 ) ;
return;
}
}
if ( V_13 )
F_74 ( & V_2 -> V_174 [ V_70 - 1 ] ) ;
F_69 ( V_70 , V_7 -> V_177 ) ;
if ( ! ( V_8 & V_200 ) ||
( V_199 & V_202 ) )
F_69 ( V_70 , V_7 -> V_180 ) ;
if ( V_199 & ( V_202 |
V_204 ) ) {
V_74 = F_202 ( V_7 , V_70 ) ;
if ( V_74 < 0 ) {
if ( F_221 () )
F_28 ( V_224 , L_167
L_168 , V_70 ) ;
V_8 &= ~ V_200 ;
} else {
V_8 = V_74 ;
}
}
if ( ! ( V_8 & V_200 ) ||
F_122 ( V_70 , V_7 -> V_180 ) ) {
if ( ( V_168 & V_169 ) < 2
&& ! F_177 ( V_7 , V_8 ) )
F_18 ( V_2 , V_70 , V_170 ) ;
if ( V_8 & V_201 )
goto V_374;
return;
}
for ( V_54 = 0 ; V_54 < V_469 ; V_54 ++ ) {
V_13 = F_222 ( V_2 , V_2 -> V_163 , V_70 ) ;
if ( ! V_13 ) {
F_28 ( V_224 ,
L_169 ,
V_70 ) ;
goto V_374;
}
F_61 ( V_13 , V_470 ) ;
V_13 -> V_256 = V_7 -> V_257 ;
V_13 -> V_190 = V_2 -> V_190 + 1 ;
V_13 -> V_303 = F_170 ( V_7 ) ;
if ( F_1 ( V_7 -> V_2 ) )
V_13 -> V_14 = V_48 ;
else
V_13 -> V_14 = V_444 ;
F_120 ( V_13 ) ;
if ( V_13 -> V_160 <= 0 ) {
V_74 = - V_361 ;
goto V_471;
}
V_74 = F_208 ( V_7 , V_13 , V_70 , V_54 ) ;
if ( V_74 < 0 )
goto V_471;
F_223 ( V_13 ) ;
if ( V_13 -> V_472 & V_473 )
F_58 ( 1000 ) ;
if ( V_13 -> V_3 . V_474 == V_475
&& V_13 -> V_256 <= 100 ) {
T_1 V_476 ;
V_74 = F_87 ( V_13 , V_254 , 0 ,
& V_476 ) ;
if ( V_74 < 2 ) {
F_20 ( & V_13 -> V_21 , L_170 , V_74 ) ;
goto V_477;
}
F_88 ( & V_476 ) ;
if ( ( V_476 & ( 1 << V_259 ) ) == 0 ) {
F_28 ( & V_13 -> V_21 ,
L_171
L_172 ) ;
if ( V_7 -> V_215 ) {
V_7 -> V_86 [ V_70 - 1 ] =
V_94 ;
F_23 ( & V_7 -> V_78 , 0 ) ;
}
V_74 = - V_361 ;
goto V_477;
}
}
if ( F_29 ( V_13 -> V_3 . V_460 ) >= 0x0200
&& V_13 -> V_14 == V_365
&& V_270 != 0 )
F_216 ( V_7 , V_13 , V_70 ) ;
V_74 = 0 ;
F_98 ( & V_286 ) ;
if ( V_2 -> V_81 == V_175 )
V_74 = - V_361 ;
else
V_2 -> V_174 [ V_70 - 1 ] = V_13 ;
F_101 ( & V_286 ) ;
if ( ! V_74 ) {
V_74 = F_147 ( V_13 ) ;
if ( V_74 ) {
F_98 ( & V_286 ) ;
V_2 -> V_174 [ V_70 - 1 ] = NULL ;
F_101 ( & V_286 ) ;
}
}
if ( V_74 )
goto V_477;
V_74 = F_218 ( V_7 ) ;
if ( V_74 )
F_20 ( V_224 , L_173 , V_74 ) ;
return;
V_477:
F_60 ( V_7 , V_70 , 1 ) ;
V_471:
F_203 ( V_13 ) ;
F_124 ( V_13 ) ;
F_126 ( V_13 ) ;
F_224 ( V_13 ) ;
if ( ( V_74 == - V_361 ) || ( V_74 == - V_332 ) )
break;
}
if ( V_7 -> V_2 -> V_22 ||
! V_151 -> V_152 -> V_478 ||
! ( V_151 -> V_152 -> V_478 ) ( V_151 , V_70 ) )
F_28 ( V_224 , L_174 ,
V_70 ) ;
V_374:
F_60 ( V_7 , V_70 , 1 ) ;
if ( V_151 -> V_152 -> V_479 && ! V_7 -> V_2 -> V_22 )
V_151 -> V_152 -> V_479 ( V_151 , V_70 ) ;
}
static int F_225 ( struct V_6 * V_7 , unsigned int V_110 ,
T_1 V_8 , T_1 V_199 )
{
struct V_1 * V_2 ;
struct V_1 * V_13 ;
int V_480 = 0 ;
int V_55 ;
V_2 = V_7 -> V_2 ;
V_13 = V_2 -> V_174 [ V_110 - 1 ] ;
if ( ! F_1 ( V_2 ) ) {
if ( ! ( V_199 & V_395 ) )
return 0 ;
F_17 ( V_2 , V_110 , V_396 ) ;
} else {
if ( ! V_13 || V_13 -> V_81 != V_295 ||
( V_8 & V_209 ) !=
V_210 )
return 0 ;
}
if ( V_13 ) {
F_58 ( 10 ) ;
F_127 ( V_13 ) ;
V_55 = F_187 ( V_13 ) ;
F_131 ( V_13 ) ;
if ( V_55 < 0 )
V_480 = 1 ;
} else {
V_55 = - V_136 ;
F_60 ( V_7 , V_110 , 1 ) ;
}
F_20 ( V_7 -> V_111 , L_175 ,
V_110 , V_55 ) ;
return V_480 ;
}
static void F_226 ( void )
{
struct V_145 * V_481 ;
struct V_1 * V_2 ;
struct V_178 * V_179 ;
struct V_6 * V_7 ;
struct V_223 * V_224 ;
T_1 V_225 ;
T_1 V_226 ;
T_1 V_8 ;
T_1 V_199 ;
int V_54 , V_55 ;
int V_480 , V_482 ;
while ( 1 ) {
F_98 ( & V_117 ) ;
if ( F_33 ( & V_120 ) ) {
F_101 ( & V_117 ) ;
break;
}
V_481 = V_120 . V_146 ;
F_99 ( V_481 ) ;
V_7 = F_46 ( V_481 , struct V_6 , V_119 ) ;
F_227 ( & V_7 -> V_268 ) ;
F_101 ( & V_117 ) ;
V_2 = V_7 -> V_2 ;
V_224 = V_7 -> V_111 ;
V_179 = F_36 ( V_224 ) ;
F_20 ( V_224 , L_176 ,
V_2 -> V_81 , V_7 -> V_3
? V_7 -> V_3 -> V_84
: 0 ,
( T_1 ) V_7 -> V_177 [ 0 ] ,
( T_1 ) V_7 -> V_134 [ 0 ] ) ;
F_127 ( V_2 ) ;
if ( F_228 ( V_7 -> V_118 ) )
goto V_483;
if ( V_2 -> V_81 == V_175 ) {
V_7 -> error = - V_136 ;
F_72 ( V_7 , V_269 ) ;
goto V_471;
}
V_55 = F_64 ( V_179 ) ;
if ( V_55 ) {
F_20 ( V_224 , L_177 , V_55 ) ;
goto V_471;
}
if ( V_7 -> V_83 )
goto V_484;
if ( V_7 -> error ) {
F_20 ( V_224 , L_178 ,
V_7 -> error ) ;
V_55 = F_229 ( V_2 ) ;
if ( V_55 ) {
F_20 ( V_224 ,
L_179 , V_55 ) ;
goto V_484;
}
V_7 -> V_130 = 0 ;
V_7 -> error = 0 ;
}
for ( V_54 = 1 ; V_54 <= V_7 -> V_3 -> V_84 ; V_54 ++ ) {
if ( F_122 ( V_54 , V_7 -> V_394 ) )
continue;
V_480 = F_122 ( V_54 , V_7 -> V_177 ) ;
V_482 = F_230 ( V_54 , V_7 -> V_123 ) ;
if ( ! F_230 ( V_54 , V_7 -> V_134 ) &&
! V_480 && ! V_482 )
continue;
V_55 = F_26 ( V_7 , V_54 ,
& V_8 , & V_199 ) ;
if ( V_55 < 0 )
continue;
if ( V_199 & V_202 ) {
F_17 ( V_2 , V_54 ,
V_203 ) ;
V_480 = 1 ;
}
if ( V_199 & V_204 ) {
if ( ! V_480 )
F_20 ( V_224 ,
L_180
L_181 ,
V_54 , V_8 ) ;
F_17 ( V_2 , V_54 ,
V_205 ) ;
if ( ! ( V_8 & V_201 )
&& ! V_480
&& V_2 -> V_174 [ V_54 - 1 ] ) {
F_28 ( V_224 ,
L_182
L_183
L_184 ,
V_54 ) ;
V_480 = 1 ;
}
}
if ( F_225 ( V_7 , V_54 ,
V_8 , V_199 ) )
V_480 = 1 ;
if ( V_199 & V_485 ) {
T_1 V_74 = 0 ;
T_1 V_486 ;
F_20 ( V_224 , L_185
L_186 , V_54 ) ;
F_17 ( V_2 , V_54 ,
V_487 ) ;
F_58 ( 100 ) ;
F_56 ( V_7 , true ) ;
F_26 ( V_7 , V_54 , & V_74 , & V_486 ) ;
if ( V_74 & V_488 )
F_28 ( V_224 , L_187
L_188 , V_54 ) ;
}
if ( V_199 & V_358 ) {
F_20 ( V_224 ,
L_189 ,
V_54 ) ;
F_17 ( V_2 , V_54 ,
V_359 ) ;
}
if ( ( V_199 & V_206 ) &&
F_1 ( V_7 -> V_2 ) ) {
F_20 ( V_224 ,
L_190 ,
V_54 ) ;
F_17 ( V_2 , V_54 ,
V_207 ) ;
}
if ( V_199 & V_356 ) {
F_17 ( V_7 -> V_2 , V_54 ,
V_357 ) ;
}
if ( V_199 & V_489 ) {
F_7 ( V_224 ,
L_191 ,
V_54 ) ;
F_17 ( V_7 -> V_2 , V_54 ,
V_490 ) ;
}
if ( F_171 ( V_7 , V_8 ) ) {
F_20 ( V_224 , L_192 , V_54 ) ;
F_173 ( V_7 , V_54 , NULL ,
V_360 , true ) ;
}
if ( V_480 )
F_219 ( V_7 , V_54 ,
V_8 , V_199 ) ;
}
if ( F_230 ( 0 , V_7 -> V_134 ) == 0 )
;
else if ( F_59 ( V_7 , & V_225 , & V_226 ) < 0 )
F_28 ( V_224 , L_193 ) ;
else {
if ( V_226 & V_491 ) {
F_20 ( V_224 , L_194 ) ;
F_15 ( V_2 , V_492 ) ;
if ( V_225 & V_264 )
V_7 -> V_258 = 1 ;
else
V_7 -> V_258 = 0 ;
}
if ( V_226 & V_493 ) {
T_1 V_74 = 0 ;
T_1 V_486 ;
F_20 ( V_224 , L_195 ) ;
F_15 ( V_2 , V_494 ) ;
F_58 ( 500 ) ;
F_56 ( V_7 , true ) ;
F_59 ( V_7 , & V_74 , & V_486 ) ;
if ( V_74 & V_265 )
F_28 ( V_224 , L_187
L_196 ) ;
}
}
V_484:
F_100 ( V_179 ) ;
V_471:
F_65 ( V_179 ) ;
V_483:
F_131 ( V_2 ) ;
F_104 ( & V_7 -> V_268 , F_94 ) ;
}
}
static int F_231 ( void * V_495 )
{
F_232 () ;
do {
F_226 () ;
F_233 ( V_121 ,
! F_33 ( & V_120 ) ||
F_234 () ) ;
} while ( ! F_234 () || ! F_33 ( & V_120 ) );
F_235 ( L_197 , V_496 ) ;
return 0 ;
}
int F_236 ( void )
{
if ( F_237 ( & V_497 ) < 0 ) {
F_238 ( V_498 L_198 ,
V_496 ) ;
return - 1 ;
}
V_499 = F_239 ( F_231 , NULL , L_199 ) ;
if ( ! F_240 ( V_499 ) )
return 0 ;
F_241 ( & V_497 ) ;
F_238 ( V_498 L_200 , V_496 ) ;
return - 1 ;
}
void F_242 ( void )
{
F_243 ( V_499 ) ;
F_241 ( & V_497 ) ;
}
static int F_244 ( struct V_1 * V_13 ,
struct V_450 * V_500 )
{
int V_79 = 0 ;
unsigned V_501 ;
unsigned V_502 = 0 ;
unsigned V_503 ;
unsigned V_504 ;
int V_505 ;
char * V_451 ;
if ( memcmp ( & V_13 -> V_3 , V_500 ,
sizeof( * V_500 ) ) != 0 )
return 1 ;
if ( V_13 -> V_318 )
V_502 = strlen ( V_13 -> V_318 ) + 1 ;
V_503 = V_502 ;
for ( V_501 = 0 ; V_501 < V_13 -> V_3 . V_342 ; V_501 ++ ) {
V_504 = F_29 ( V_13 -> V_321 [ V_501 ] . V_262 . V_324 ) ;
V_503 = F_57 ( V_503 , V_504 ) ;
}
V_451 = F_50 ( V_503 , V_197 ) ;
if ( V_451 == NULL ) {
F_28 ( & V_13 -> V_21 , L_201 ) ;
return 1 ;
}
for ( V_501 = 0 ; V_501 < V_13 -> V_3 . V_342 ; V_501 ++ ) {
V_504 = F_29 ( V_13 -> V_321 [ V_501 ] . V_262 . V_324 ) ;
V_505 = F_217 ( V_13 , V_506 , V_501 , V_451 ,
V_504 ) ;
if ( V_505 != V_504 ) {
F_20 ( & V_13 -> V_21 , L_202 ,
V_501 , V_505 ) ;
V_79 = 1 ;
break;
}
if ( memcmp ( V_451 , V_13 -> V_323 [ V_501 ] , V_504 )
!= 0 ) {
F_20 ( & V_13 -> V_21 , L_203 ,
V_501 ,
( (struct V_507 * ) V_451 ) ->
V_508 ) ;
V_79 = 1 ;
break;
}
}
if ( ! V_79 && V_502 ) {
V_505 = F_245 ( V_13 , V_13 -> V_3 . V_315 ,
V_451 , V_502 ) ;
if ( V_505 + 1 != V_502 ) {
F_20 ( & V_13 -> V_21 , L_204 ,
V_505 ) ;
V_79 = 1 ;
} else if ( memcmp ( V_451 , V_13 -> V_318 , V_505 ) != 0 ) {
F_20 ( & V_13 -> V_21 , L_205 ) ;
V_79 = 1 ;
}
}
F_48 ( V_451 ) ;
return V_79 ;
}
static int F_185 ( struct V_1 * V_13 )
{
struct V_1 * V_509 = V_13 -> V_22 ;
struct V_6 * V_510 ;
struct V_182 * V_151 = F_54 ( V_13 -> V_163 ) ;
struct V_450 V_3 = V_13 -> V_3 ;
int V_54 , V_55 = 0 ;
int V_70 = V_13 -> V_122 ;
if ( V_13 -> V_81 == V_175 ||
V_13 -> V_81 == V_295 ) {
F_20 ( & V_13 -> V_21 , L_206 ,
V_13 -> V_81 ) ;
return - V_67 ;
}
if ( ! V_509 ) {
F_20 ( & V_13 -> V_21 , L_207 , V_112 ) ;
return - V_511 ;
}
V_510 = F_3 ( V_509 ) ;
F_41 ( V_70 , V_510 -> V_394 ) ;
for ( V_54 = 0 ; V_54 < V_469 ; ++ V_54 ) {
F_203 ( V_13 ) ;
V_55 = F_208 ( V_510 , V_13 , V_70 , V_54 ) ;
if ( V_55 >= 0 || V_55 == - V_361 || V_55 == - V_136 )
break;
}
F_69 ( V_70 , V_510 -> V_394 ) ;
if ( V_55 < 0 )
goto V_512;
if ( F_244 ( V_13 , & V_3 ) ) {
F_81 ( & V_13 -> V_21 , L_208 ) ;
V_13 -> V_3 = V_3 ;
goto V_512;
}
if ( ! V_13 -> V_11 )
goto V_374;
F_27 ( V_151 -> V_428 ) ;
V_55 = F_200 ( V_13 ) ;
if ( V_55 ) {
F_28 ( & V_13 -> V_21 , L_209 , V_112 ) ;
F_30 ( V_151 -> V_428 ) ;
goto V_374;
}
V_55 = F_246 ( V_13 , V_13 -> V_11 , NULL , NULL ) ;
if ( V_55 < 0 ) {
F_7 ( & V_13 -> V_21 ,
L_210
L_211 ) ;
F_201 ( V_13 ) ;
F_30 ( V_151 -> V_428 ) ;
goto V_512;
}
V_55 = F_13 ( V_13 , F_16 ( V_13 , 0 ) ,
V_513 , 0 ,
V_13 -> V_11 -> V_262 . V_508 , 0 ,
NULL , 0 , V_191 ) ;
if ( V_55 < 0 ) {
F_28 ( & V_13 -> V_21 ,
L_212 ,
V_13 -> V_11 -> V_262 . V_508 , V_55 ) ;
F_201 ( V_13 ) ;
F_30 ( V_151 -> V_428 ) ;
goto V_512;
}
F_30 ( V_151 -> V_428 ) ;
F_61 ( V_13 , V_82 ) ;
for ( V_54 = 0 ; V_54 < V_13 -> V_11 -> V_262 . V_514 ; V_54 ++ ) {
struct V_515 * V_321 = V_13 -> V_11 ;
struct V_178 * V_179 = V_321 -> V_12 [ V_54 ] ;
struct V_516 * V_262 ;
V_262 = & V_179 -> V_274 -> V_262 ;
if ( V_262 -> V_517 == 0 ) {
F_247 ( V_13 , V_179 , true ) ;
F_248 ( V_13 , V_179 , true ) ;
V_55 = 0 ;
} else {
V_179 -> V_518 = 1 ;
V_55 = F_86 ( V_13 , V_262 -> V_519 ,
V_262 -> V_517 ) ;
V_179 -> V_518 = 0 ;
}
if ( V_55 < 0 ) {
F_28 ( & V_13 -> V_21 , L_213
L_214 ,
V_262 -> V_519 ,
V_262 -> V_517 ,
V_55 ) ;
F_183 ( V_13 ) ;
goto V_512;
}
}
F_183 ( V_13 ) ;
V_374:
return 0 ;
V_512:
F_62 ( V_510 , V_70 ) ;
return - V_136 ;
}
int F_229 ( struct V_1 * V_13 )
{
int V_55 ;
int V_54 ;
struct V_515 * V_321 = V_13 -> V_11 ;
if ( V_13 -> V_81 == V_175 ||
V_13 -> V_81 == V_295 ) {
F_20 ( & V_13 -> V_21 , L_206 ,
V_13 -> V_81 ) ;
return - V_67 ;
}
F_166 ( V_13 ) ;
if ( V_321 ) {
for ( V_54 = 0 ; V_54 < V_321 -> V_262 . V_514 ; ++ V_54 ) {
struct V_178 * V_520 = V_321 -> V_12 [ V_54 ] ;
struct V_521 * V_150 ;
int V_522 = 0 ;
if ( V_520 -> V_21 . V_152 ) {
V_150 = F_249 ( V_520 -> V_21 . V_152 ) ;
if ( V_150 -> V_523 && V_150 -> V_524 )
V_522 = ( V_150 -> V_523 ) ( V_520 ) ;
else if ( V_520 -> V_525 ==
V_526 )
V_522 = 1 ;
if ( V_522 )
F_250 ( V_520 ) ;
}
}
}
V_55 = F_185 ( V_13 ) ;
if ( V_321 ) {
for ( V_54 = V_321 -> V_262 . V_514 - 1 ; V_54 >= 0 ; -- V_54 ) {
struct V_178 * V_520 = V_321 -> V_12 [ V_54 ] ;
struct V_521 * V_150 ;
int V_527 = V_520 -> V_528 ;
if ( ! V_527 && V_520 -> V_21 . V_152 ) {
V_150 = F_249 ( V_520 -> V_21 . V_152 ) ;
if ( V_150 -> V_524 )
V_527 = ( V_150 -> V_524 ) ( V_520 ) ;
else if ( V_520 -> V_525 ==
V_526 )
V_527 = 1 ;
}
if ( V_55 == 0 && V_527 )
F_251 ( V_520 ) ;
}
}
F_169 ( V_13 ) ;
return V_55 ;
}
void F_252 ( struct V_178 * V_529 )
{
F_55 ( & V_529 -> V_530 ) ;
}
