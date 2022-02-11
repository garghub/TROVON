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
V_7 -> V_232 = F_82 ( V_2 -> V_198 * sizeof( struct V_233 * ) ,
V_229 ) ;
if ( ! V_2 -> V_174 || ! V_7 -> V_232 ) {
V_55 = - V_157 ;
goto V_230;
}
V_168 = F_29 ( V_7 -> V_3 -> V_168 ) ;
if ( ( V_168 & V_234 ) &&
! ( F_1 ( V_2 ) ) ) {
int V_54 ;
char V_235 [ V_231 + 1 ] ;
for ( V_54 = 0 ; V_54 < V_2 -> V_198 ; V_54 ++ )
V_235 [ V_54 ] = V_7 -> V_3 -> V_33 . V_236 . V_237
[ ( ( V_54 + 1 ) / 8 ) ] & ( 1 << ( ( V_54 + 1 ) % 8 ) )
? 'F' : 'R' ;
V_235 [ V_2 -> V_198 ] = 0 ;
F_20 ( V_224 , L_39 , V_235 ) ;
} else
F_20 ( V_224 , L_40 ) ;
switch ( V_168 & V_169 ) {
case V_238 :
F_20 ( V_224 , L_41 ) ;
break;
case V_239 :
F_20 ( V_224 , L_42 ) ;
break;
case V_240 :
case V_169 :
F_20 ( V_224 , L_43 ) ;
break;
}
switch ( V_168 & V_241 ) {
case V_242 :
F_20 ( V_224 , L_44 ) ;
break;
case V_243 :
F_20 ( V_224 , L_45 ) ;
break;
case V_244 :
case V_241 :
F_20 ( V_224 , L_46 ) ;
break;
}
F_83 ( & V_7 -> V_139 . V_143 ) ;
F_84 ( & V_7 -> V_139 . V_144 ) ;
F_85 ( & V_7 -> V_139 . V_141 , F_45 ) ;
switch ( V_2 -> V_3 . V_4 ) {
case V_245 :
break;
case V_246 :
F_20 ( V_224 , L_47 ) ;
V_7 -> V_139 . V_7 = V_2 ;
break;
case V_247 :
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
switch ( V_168 & V_248 ) {
case V_249 :
if ( V_2 -> V_3 . V_4 != 0 ) {
V_7 -> V_139 . V_250 = 666 ;
F_20 ( V_224 , L_51
L_52 ,
8 , V_7 -> V_139 . V_250 ) ;
}
break;
case V_251 :
V_7 -> V_139 . V_250 = 666 * 2 ;
F_20 ( V_224 , L_51
L_52 ,
16 , V_7 -> V_139 . V_250 ) ;
break;
case V_252 :
V_7 -> V_139 . V_250 = 666 * 3 ;
F_20 ( V_224 , L_51
L_52 ,
24 , V_7 -> V_139 . V_250 ) ;
break;
case V_253 :
V_7 -> V_139 . V_250 = 666 * 4 ;
F_20 ( V_224 , L_51
L_52 ,
32 , V_7 -> V_139 . V_250 ) ;
break;
}
if ( V_168 & V_254 ) {
V_7 -> V_215 = 1 ;
F_20 ( V_224 , L_53 ) ;
}
F_20 ( V_224 , L_54 ,
V_7 -> V_3 -> V_166 * 2 ) ;
V_55 = F_87 ( V_2 , V_255 , 0 , & V_225 ) ;
if ( V_55 < 2 ) {
V_228 = L_55 ;
goto V_230;
}
F_88 ( & V_225 ) ;
if ( V_2 == V_2 -> V_163 -> V_256 ) {
if ( V_2 -> V_257 == 0 || V_2 -> V_257 >= 500 )
V_7 -> V_258 = 500 ;
else {
V_7 -> V_258 = V_2 -> V_257 ;
V_7 -> V_259 = 1 ;
}
} else if ( ( V_225 & ( 1 << V_260 ) ) == 0 ) {
F_20 ( V_224 , L_56 ,
V_7 -> V_3 -> V_261 ) ;
V_7 -> V_259 = 1 ;
if ( V_2 -> V_198 > 0 ) {
int V_262 = V_2 -> V_257 -
V_7 -> V_3 -> V_261 ;
if ( V_262 < V_2 -> V_198 * 100 )
F_7 ( V_224 ,
L_57
L_58 ) ;
V_7 -> V_258 = 100 ;
}
} else {
V_7 -> V_258 = 500 ;
}
if ( V_7 -> V_258 < 500 )
F_20 ( V_224 , L_59 ,
V_7 -> V_258 ) ;
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
if ( V_2 -> V_11 -> V_263 . V_19 & V_264 )
F_20 ( V_224 , L_61 ,
( V_225 & V_265 )
? L_62 : L_63 ) ;
if ( ( V_168 & V_241 ) == 0 )
F_20 ( V_224 , L_64 ,
( V_225 & V_266 ) ? L_37 : L_65 ) ;
V_155 = F_89 ( V_2 , V_222 -> V_267 ) ;
V_227 = F_90 ( V_2 , V_155 , F_91 ( V_155 ) ) ;
if ( V_227 > sizeof( * V_7 -> V_133 ) )
V_227 = sizeof( * V_7 -> V_133 ) ;
V_7 -> V_124 = F_92 ( 0 , V_229 ) ;
if ( ! V_7 -> V_124 ) {
V_55 = - V_157 ;
goto V_230;
}
F_93 ( V_7 -> V_124 , V_2 , V_155 , * V_7 -> V_133 , V_227 , F_42 ,
V_7 , V_222 -> V_268 ) ;
if ( V_7 -> V_215 && V_99 )
V_7 -> V_86 [ 0 ] = V_87 ;
F_66 ( V_7 , V_192 ) ;
return 0 ;
V_230:
F_28 ( V_224 , L_66 ,
V_228 , V_55 ) ;
return V_55 ;
}
static void F_94 ( struct V_269 * V_269 )
{
struct V_6 * V_7 = F_22 ( V_269 , struct V_6 , V_269 ) ;
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
F_72 ( V_7 , V_270 ) ;
F_102 ( V_179 , NULL ) ;
V_7 -> V_2 -> V_198 = 0 ;
if ( V_7 -> V_2 -> V_14 == V_15 )
V_271 -- ;
F_103 ( V_7 -> V_124 ) ;
F_48 ( V_2 -> V_174 ) ;
F_48 ( V_7 -> V_232 ) ;
F_48 ( V_7 -> V_3 ) ;
F_48 ( V_7 -> V_74 ) ;
F_48 ( V_7 -> V_133 ) ;
F_104 ( & V_7 -> V_269 , F_94 ) ;
}
static int F_105 ( struct V_178 * V_179 , const struct V_272 * V_273 )
{
struct V_274 * V_263 ;
struct V_221 * V_222 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
V_263 = V_179 -> V_275 ;
V_2 = F_97 ( V_179 ) ;
F_106 ( V_2 ) ;
if ( V_2 -> V_190 == V_276 ) {
F_28 ( & V_179 -> V_21 ,
L_67 ) ;
return - V_277 ;
}
#ifdef F_107
if ( V_2 -> V_22 ) {
F_7 ( & V_179 -> V_21 , L_68 ) ;
return - V_136 ;
}
#endif
if ( ( V_263 -> V_263 . V_278 != 0 ) &&
( V_263 -> V_263 . V_278 != 1 ) ) {
V_279:
F_28 ( & V_179 -> V_21 , L_69 ) ;
return - V_113 ;
}
if ( V_263 -> V_263 . V_280 != 1 )
goto V_279;
V_222 = & V_263 -> V_222 [ 0 ] . V_263 ;
if ( ! F_108 ( V_222 ) )
goto V_279;
F_81 ( & V_179 -> V_21 , L_70 ) ;
V_7 = F_82 ( sizeof( * V_7 ) , V_229 ) ;
if ( ! V_7 ) {
F_20 ( & V_179 -> V_21 , L_71 ) ;
return - V_157 ;
}
F_109 ( & V_7 -> V_269 ) ;
F_84 ( & V_7 -> V_119 ) ;
V_7 -> V_111 = & V_179 -> V_21 ;
V_7 -> V_2 = V_2 ;
F_110 ( & V_7 -> V_78 , F_21 ) ;
F_110 ( & V_7 -> V_193 , NULL ) ;
F_111 ( V_179 ) ;
F_102 ( V_179 , V_7 ) ;
V_179 -> V_281 = 1 ;
if ( V_2 -> V_14 == V_15 )
V_271 ++ ;
if ( F_79 ( V_7 , V_222 ) >= 0 )
return 0 ;
F_96 ( V_179 ) ;
return - V_136 ;
}
static int
F_112 ( struct V_178 * V_179 , unsigned int V_282 , void * V_283 )
{
struct V_1 * V_2 = F_97 ( V_179 ) ;
switch ( V_282 ) {
case V_284 : {
struct V_285 * V_286 = V_283 ;
int V_54 ;
F_98 ( & V_287 ) ;
if ( V_2 -> V_160 <= 0 )
V_286 -> V_288 = 0 ;
else {
V_286 -> V_288 = V_2 -> V_198 ;
for ( V_54 = 0 ; V_54 < V_286 -> V_288 ; V_54 ++ ) {
if ( V_2 -> V_174 [ V_54 ] == NULL )
V_286 -> V_110 [ V_54 ] = 0 ;
else
V_286 -> V_110 [ V_54 ] =
V_2 -> V_174 [ V_54 ] -> V_160 ;
}
}
F_101 ( & V_287 ) ;
return V_286 -> V_288 + 1 ;
}
default:
return - V_289 ;
}
}
static int F_113 ( struct V_1 * V_2 , unsigned V_70 ,
struct V_233 * * * V_290 )
{
if ( V_2 -> V_81 == V_175 )
return - V_136 ;
if ( V_70 == 0 || V_70 > V_2 -> V_198 )
return - V_67 ;
* V_290 = & ( F_3 ( V_2 ) -> V_232 [ V_70 - 1 ] ) ;
return 0 ;
}
int F_114 ( struct V_1 * V_2 , unsigned V_70 ,
struct V_233 * V_291 )
{
int V_292 ;
struct V_233 * * V_293 ;
V_292 = F_113 ( V_2 , V_70 , & V_293 ) ;
if ( V_292 )
return V_292 ;
if ( * V_293 )
return - V_294 ;
* V_293 = V_291 ;
return V_292 ;
}
int F_115 ( struct V_1 * V_2 , unsigned V_70 ,
struct V_233 * V_291 )
{
int V_292 ;
struct V_233 * * V_293 ;
V_292 = F_113 ( V_2 , V_70 , & V_293 ) ;
if ( V_292 )
return V_292 ;
if ( * V_293 != V_291 )
return - V_127 ;
* V_293 = NULL ;
return V_292 ;
}
void F_116 ( struct V_1 * V_2 , struct V_233 * V_291 )
{
int V_295 ;
struct V_233 * * V_293 ;
V_295 = F_113 ( V_2 , 1 , & V_293 ) ;
if ( V_295 == 0 ) {
for (; V_295 < V_2 -> V_198 ; ( ++ V_295 , ++ V_293 ) ) {
if ( * V_293 == V_291 )
* V_293 = NULL ;
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
if ( V_13 -> V_81 == V_296 )
V_13 -> V_297 -= V_298 ;
V_13 -> V_81 = V_175 ;
}
void F_61 ( struct V_1 * V_13 ,
enum V_299 V_300 )
{
unsigned long V_116 ;
int V_301 = - 1 ;
F_32 ( & V_287 , V_116 ) ;
if ( V_13 -> V_81 == V_175 )
;
else if ( V_300 != V_175 ) {
if ( V_13 -> V_22 ) {
if ( V_13 -> V_81 == V_296
|| V_300 == V_296 )
;
else if ( V_300 == V_82 )
V_301 = V_13 -> V_11 -> V_263 . V_19
& V_302 ;
else
V_301 = 0 ;
}
if ( V_13 -> V_81 == V_296 &&
V_300 != V_296 )
V_13 -> V_297 -= V_298 ;
else if ( V_300 == V_296 &&
V_13 -> V_81 != V_296 )
V_13 -> V_297 += V_298 ;
V_13 -> V_81 = V_300 ;
} else
F_118 ( V_13 ) ;
F_38 ( & V_287 , V_116 ) ;
if ( V_301 >= 0 )
F_119 ( & V_13 -> V_21 , V_301 ) ;
}
static void F_120 ( struct V_1 * V_13 )
{
int V_160 ;
struct V_303 * V_163 = V_13 -> V_163 ;
if ( V_13 -> V_304 ) {
V_160 = V_13 -> V_122 + 1 ;
F_121 ( F_122 ( V_160 , V_163 -> V_305 . V_306 ) ) ;
} else {
V_160 = F_123 ( V_163 -> V_305 . V_306 , 128 ,
V_163 -> V_307 ) ;
if ( V_160 >= 128 )
V_160 = F_123 ( V_163 -> V_305 . V_306 ,
128 , 1 ) ;
V_163 -> V_307 = ( V_160 >= 127 ? 1 : V_160 + 1 ) ;
}
if ( V_160 < 128 ) {
F_41 ( V_160 , V_163 -> V_305 . V_306 ) ;
V_13 -> V_160 = V_160 ;
}
}
static void F_124 ( struct V_1 * V_13 )
{
if ( V_13 -> V_160 > 0 ) {
F_69 ( V_13 -> V_160 , V_13 -> V_163 -> V_305 . V_306 ) ;
V_13 -> V_160 = - 1 ;
}
}
static void F_125 ( struct V_1 * V_13 , int V_160 )
{
if ( ! V_13 -> V_304 )
V_13 -> V_160 = V_160 ;
}
static void F_126 ( struct V_1 * V_13 )
{
struct V_182 * V_151 = F_54 ( V_13 -> V_163 ) ;
if ( V_151 -> V_152 -> V_308 && V_13 -> V_22 )
V_151 -> V_152 -> V_308 ( V_151 , V_13 ) ;
}
void F_74 ( struct V_1 * * V_309 )
{
struct V_1 * V_13 = * V_309 ;
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
F_130 ( & V_13 -> V_310 ) ;
F_131 ( V_13 ) ;
F_132 ( & V_13 -> V_21 ) ;
F_124 ( V_13 ) ;
F_98 ( & V_287 ) ;
* V_309 = NULL ;
F_101 ( & V_287 ) ;
F_126 ( V_13 ) ;
F_133 ( & V_13 -> V_21 ) ;
}
static void F_134 ( struct V_1 * V_13 , char * V_273 , char * string )
{
if ( ! string )
return;
F_135 ( V_311 , & V_13 -> V_21 , L_74 , V_273 , string ) ;
}
static void F_136 ( struct V_1 * V_13 )
{
F_81 ( & V_13 -> V_21 , L_75 ,
F_29 ( V_13 -> V_3 . V_312 ) ,
F_29 ( V_13 -> V_3 . V_313 ) ) ;
F_81 ( & V_13 -> V_21 ,
L_76 ,
V_13 -> V_3 . V_314 ,
V_13 -> V_3 . V_315 ,
V_13 -> V_3 . V_316 ) ;
F_134 ( V_13 , L_77 , V_13 -> V_317 ) ;
F_134 ( V_13 , L_78 , V_13 -> V_318 ) ;
F_134 ( V_13 , L_79 , V_13 -> V_319 ) ;
}
static inline void F_136 ( struct V_1 * V_13 ) { }
static int F_137 ( struct V_1 * V_13 )
{
int V_320 = 0 ;
#ifdef F_138
if ( ! V_13 -> V_163 -> V_321
&& V_13 -> V_322
&& V_13 -> V_22 == V_13 -> V_163 -> V_256 ) {
struct V_323 * V_263 = NULL ;
struct V_303 * V_163 = V_13 -> V_163 ;
if ( F_139 ( V_13 -> V_324 [ 0 ] ,
F_29 ( V_13 -> V_322 [ 0 ] . V_263 . V_325 ) ,
V_326 , ( void * * ) & V_263 ) == 0 ) {
if ( V_263 -> V_19 & V_327 ) {
unsigned V_70 = V_13 -> V_122 ;
F_81 ( & V_13 -> V_21 ,
L_80 ,
( V_70 == V_163 -> V_328 )
? L_37 : L_81 ) ;
if ( V_70 == V_163 -> V_328 )
V_163 -> V_329 = 1 ;
V_320 = F_13 ( V_13 ,
F_16 ( V_13 , 0 ) ,
V_72 , 0 ,
V_163 -> V_329
? V_330
: V_331 ,
0 , NULL , 0 , V_191 ) ;
if ( V_320 < 0 ) {
F_81 ( & V_13 -> V_21 ,
L_82 ,
V_320 ) ;
V_163 -> V_329 = 0 ;
}
}
}
}
if ( ! F_140 ( V_13 ) ) {
if ( V_13 -> V_163 -> V_329 || V_13 -> V_163 -> V_321 ) {
V_320 = F_141 ( V_13 , V_332 ) ;
if ( V_320 < 0 )
F_20 ( & V_13 -> V_21 , L_83 , V_320 ) ;
}
V_320 = - V_333 ;
goto V_230;
}
V_230:
#endif
return V_320 ;
}
static int F_142 ( struct V_1 * V_13 )
{
int V_320 ;
if ( V_13 -> V_322 == NULL ) {
V_320 = F_143 ( V_13 ) ;
if ( V_320 < 0 ) {
F_28 ( & V_13 -> V_21 , L_84 ,
V_320 ) ;
return V_320 ;
}
}
if ( V_13 -> V_304 == 1 && V_13 -> V_334 == 0 ) {
V_13 -> V_317 = F_144 ( L_85 , V_229 ) ;
V_13 -> V_318 = F_144 ( L_85 , V_229 ) ;
V_13 -> V_319 = F_144 ( L_85 , V_229 ) ;
}
else {
V_13 -> V_317 = F_145 ( V_13 , V_13 -> V_3 . V_315 ) ;
V_13 -> V_318 = F_145 ( V_13 ,
V_13 -> V_3 . V_314 ) ;
V_13 -> V_319 = F_145 ( V_13 , V_13 -> V_3 . V_316 ) ;
}
V_320 = F_137 ( V_13 ) ;
if ( V_320 < 0 )
return V_320 ;
F_146 ( V_13 ) ;
return 0 ;
}
static void F_147 ( struct V_1 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_22 ;
struct V_6 * V_7 ;
T_2 V_110 = V_13 -> V_122 ;
T_1 V_168 ;
bool V_335 = true ;
if ( ! V_2 )
return;
V_7 = F_3 ( V_13 -> V_22 ) ;
V_168 = F_29 ( V_7 -> V_3 -> V_168 ) ;
if ( ! ( V_168 & V_234 ) )
return;
if ( F_1 ( V_2 ) ) {
if ( V_7 -> V_3 -> V_33 . V_34 . V_237 & ( 1 << V_110 ) )
V_335 = false ;
} else {
if ( V_7 -> V_3 -> V_33 . V_236 . V_237 [ V_110 / 8 ] & ( 1 << ( V_110 % 8 ) ) )
V_335 = false ;
}
if ( V_335 )
V_13 -> V_335 = V_336 ;
else
V_13 -> V_335 = V_337 ;
}
int F_148 ( struct V_1 * V_13 )
{
int V_320 ;
if ( V_13 -> V_22 ) {
F_149 ( & V_13 -> V_21 , 0 ) ;
}
F_150 ( & V_13 -> V_21 ) ;
F_151 ( & V_13 -> V_21 ) ;
F_152 ( & V_13 -> V_21 ) ;
F_153 ( & V_13 -> V_21 ) ;
F_154 ( V_13 ) ;
V_320 = F_142 ( V_13 ) ;
if ( V_320 < 0 )
goto V_230;
F_20 ( & V_13 -> V_21 , L_86 ,
V_13 -> V_160 , V_13 -> V_163 -> V_338 ,
( ( ( V_13 -> V_163 -> V_338 - 1 ) * 128 ) + ( V_13 -> V_160 - 1 ) ) ) ;
V_13 -> V_21 . V_339 = F_155 ( V_340 ,
( ( ( V_13 -> V_163 -> V_338 - 1 ) * 128 ) + ( V_13 -> V_160 - 1 ) ) ) ;
F_136 ( V_13 ) ;
if ( V_13 -> V_319 )
F_156 ( V_13 -> V_319 , strlen ( V_13 -> V_319 ) ) ;
if ( V_13 -> V_317 )
F_156 ( V_13 -> V_317 , strlen ( V_13 -> V_317 ) ) ;
if ( V_13 -> V_318 )
F_156 ( V_13 -> V_318 ,
strlen ( V_13 -> V_318 ) ) ;
F_157 ( & V_13 -> V_21 ) ;
if ( V_13 -> V_22 )
F_147 ( V_13 ) ;
V_320 = F_158 ( & V_13 -> V_21 ) ;
if ( V_320 ) {
F_28 ( & V_13 -> V_21 , L_87 , V_320 ) ;
goto V_230;
}
( void ) F_159 ( & V_13 -> V_21 , & V_13 -> V_310 , V_13 ) ;
F_160 ( V_13 ) ;
F_161 ( & V_13 -> V_21 ) ;
return V_320 ;
V_230:
F_61 ( V_13 , V_175 ) ;
F_162 ( & V_13 -> V_21 ) ;
F_163 ( & V_13 -> V_21 ) ;
return V_320 ;
}
int F_164 ( struct V_1 * V_341 )
{
F_127 ( V_341 ) ;
if ( V_341 -> V_334 == 0 )
goto V_342;
V_341 -> V_334 = 0 ;
F_165 ( V_341 , - 1 ) ;
F_48 ( V_341 -> V_317 ) ;
V_341 -> V_317 = F_144 ( L_85 , V_229 ) ;
F_48 ( V_341 -> V_318 ) ;
V_341 -> V_318 = F_144 ( L_85 , V_229 ) ;
F_48 ( V_341 -> V_319 ) ;
V_341 -> V_319 = F_144 ( L_85 , V_229 ) ;
F_166 ( V_341 ) ;
V_341 -> V_3 . V_343 = 0 ;
V_342:
F_131 ( V_341 ) ;
return 0 ;
}
int F_167 ( struct V_1 * V_341 )
{
int V_344 = 0 , V_345 ;
F_127 ( V_341 ) ;
if ( V_341 -> V_334 == 1 )
goto V_346;
V_344 = F_168 ( V_341 ) ;
if ( V_344 < 0 ) {
F_28 ( & V_341 -> V_21 ,
L_88 , V_344 ) ;
goto V_347;
}
V_344 = F_169 ( V_341 , sizeof( V_341 -> V_3 ) ) ;
if ( V_344 < 0 ) {
F_28 ( & V_341 -> V_21 , L_89
L_90 , V_344 ) ;
goto V_348;
}
F_48 ( V_341 -> V_317 ) ;
V_341 -> V_317 = NULL ;
F_48 ( V_341 -> V_318 ) ;
V_341 -> V_318 = NULL ;
F_48 ( V_341 -> V_319 ) ;
V_341 -> V_319 = NULL ;
V_341 -> V_334 = 1 ;
V_344 = F_142 ( V_341 ) ;
if ( V_344 < 0 )
goto V_349;
V_345 = F_170 ( V_341 ) ;
if ( V_345 >= 0 ) {
V_344 = F_165 ( V_341 , V_345 ) ;
if ( V_344 ) {
F_28 ( & V_341 -> V_21 ,
L_91 , V_345 , V_344 ) ;
}
}
F_81 ( & V_341 -> V_21 , L_92 ) ;
V_349:
V_348:
F_171 ( V_341 ) ;
V_347:
V_346:
F_131 ( V_341 ) ;
return V_344 ;
}
static unsigned F_172 ( struct V_6 * V_7 )
{
struct V_182 * V_151 ;
if ( V_7 -> V_2 -> V_22 != NULL )
return 0 ;
V_151 = F_22 ( V_7 -> V_2 -> V_163 , struct V_182 , V_350 ) ;
return V_151 -> V_351 ;
}
static bool F_173 ( struct V_6 * V_7 , T_1 V_8 )
{
return F_1 ( V_7 -> V_2 ) &&
( ( ( V_8 & V_209 ) ==
V_352 ) ||
( ( V_8 & V_209 ) ==
V_353 ) ) ;
}
static int F_174 ( struct V_6 * V_7 , int V_70 ,
struct V_1 * V_13 , unsigned int V_167 , bool V_354 )
{
int V_355 , V_55 ;
T_1 V_8 ;
T_1 V_199 ;
for ( V_355 = 0 ;
V_355 < V_356 ;
V_355 += V_167 ) {
F_58 ( V_167 ) ;
V_55 = F_26 ( V_7 , V_70 , & V_8 , & V_199 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( ! V_354 ) {
if ( F_173 ( V_7 , V_8 ) ) {
int V_55 ;
if ( ( V_199 & V_202 ) )
F_17 ( V_7 -> V_2 , V_70 ,
V_203 ) ;
if ( V_199 & V_357 )
F_17 ( V_7 -> V_2 , V_70 ,
V_358 ) ;
if ( V_199 & V_359 )
F_17 ( V_7 -> V_2 , V_70 ,
V_360 ) ;
F_20 ( V_7 -> V_111 , L_93 ,
V_70 ) ;
V_55 = F_175 ( V_7 , V_70 ,
V_13 , V_361 ,
true ) ;
if ( ( V_199 & V_202 ) )
F_17 ( V_7 -> V_2 , V_70 ,
V_203 ) ;
return V_55 ;
}
if ( ! ( V_8 & V_200 ) )
return - V_362 ;
if ( ( V_199 & V_202 ) )
return - V_362 ;
if ( ! ( V_8 & V_363 ) &&
( V_8 & V_201 ) ) {
if ( F_172 ( V_7 ) )
V_13 -> V_14 = V_364 ;
else if ( F_1 ( V_7 -> V_2 ) )
V_13 -> V_14 = V_48 ;
else if ( V_8 & V_9 )
V_13 -> V_14 = V_15 ;
else if ( V_8 & V_10 )
V_13 -> V_14 = V_365 ;
else
V_13 -> V_14 = V_366 ;
return 0 ;
}
} else {
if ( V_199 & V_206 )
return 0 ;
}
if ( V_355 >= 2 * V_367 )
V_167 = V_368 ;
F_20 ( V_7 -> V_111 ,
L_94 ,
V_70 , V_354 ? L_95 : L_37 , V_167 ) ;
}
return - V_294 ;
}
static void F_176 ( struct V_6 * V_7 , int V_70 ,
struct V_1 * V_13 , int * V_74 , bool V_354 )
{
switch ( * V_74 ) {
case 0 :
if ( ! V_354 ) {
struct V_182 * V_151 ;
F_58 ( 10 + 40 ) ;
F_125 ( V_13 , 0 ) ;
V_151 = F_54 ( V_13 -> V_163 ) ;
if ( V_151 -> V_152 -> V_369 ) {
* V_74 = V_151 -> V_152 -> V_369 ( V_151 , V_13 ) ;
if ( * V_74 < 0 ) {
F_28 ( & V_13 -> V_21 , L_96
L_97 ) ;
break;
}
}
}
case - V_362 :
case - V_136 :
F_17 ( V_7 -> V_2 ,
V_70 , V_360 ) ;
if ( V_354 ) {
F_17 ( V_7 -> V_2 , V_70 ,
V_207 ) ;
F_17 ( V_7 -> V_2 , V_70 ,
V_358 ) ;
} else {
F_61 ( V_13 , * V_74
? V_175
: V_370 ) ;
}
break;
}
}
static int F_175 ( struct V_6 * V_7 , int V_70 ,
struct V_1 * V_13 , unsigned int V_167 , bool V_354 )
{
int V_54 , V_74 ;
if ( ! V_354 ) {
F_177 ( & V_371 ) ;
} else {
if ( ! F_1 ( V_7 -> V_2 ) ) {
F_28 ( V_7 -> V_111 , L_98
L_99 ) ;
return - V_67 ;
}
}
for ( V_54 = 0 ; V_54 < V_372 ; V_54 ++ ) {
V_74 = F_18 ( V_7 -> V_2 , V_70 , ( V_354 ?
V_373 :
V_374 ) ) ;
if ( V_74 ) {
F_28 ( V_7 -> V_111 ,
L_100 ,
V_354 ? L_95 : L_37 , V_70 , V_74 ) ;
} else {
V_74 = F_174 ( V_7 , V_70 , V_13 , V_167 ,
V_354 ) ;
if ( V_74 && V_74 != - V_362 )
F_20 ( V_7 -> V_111 ,
L_101 ,
V_74 ) ;
}
if ( V_74 == 0 || V_74 == - V_362 || V_74 == - V_136 ) {
F_176 ( V_7 , V_70 , V_13 , & V_74 , V_354 ) ;
goto V_375;
}
F_20 ( V_7 -> V_111 ,
L_102 ,
V_70 , V_354 ? L_95 : L_37 ) ;
V_167 = V_368 ;
}
F_28 ( V_7 -> V_111 ,
L_103 ,
V_70 ) ;
V_375:
if ( ! V_354 )
F_178 ( & V_371 ) ;
return V_74 ;
}
static int F_179 ( struct V_6 * V_7 , unsigned V_8 )
{
int V_55 = 0 ;
if ( F_1 ( V_7 -> V_2 ) ) {
if ( V_8 & V_376 )
V_55 = 1 ;
} else {
if ( V_8 & V_377 )
V_55 = 1 ;
}
return V_55 ;
}
static int F_180 ( struct V_6 * V_7 , unsigned V_8 )
{
int V_55 = 0 ;
if ( F_1 ( V_7 -> V_2 ) ) {
if ( ( V_8 & V_209 )
== V_378 )
V_55 = 1 ;
} else {
if ( V_8 & V_379 )
V_55 = 1 ;
}
return V_55 ;
}
static int F_181 ( struct V_1 * V_13 ,
struct V_6 * V_7 , int V_70 ,
int V_74 , unsigned V_199 , unsigned V_8 )
{
if ( V_74 || F_180 ( V_7 , V_8 ) ||
! F_179 ( V_7 , V_8 ) ||
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
int F_182 ( struct V_1 * V_13 )
{
struct V_182 * V_151 = F_54 ( V_13 -> V_163 ) ;
if ( ! F_183 ( V_151 -> V_350 . V_256 ) ||
! F_183 ( V_13 ) )
return 0 ;
if ( ! V_13 -> V_11 )
return 0 ;
return F_13 ( V_13 , F_16 ( V_13 , 0 ) ,
V_69 , V_255 ,
V_380 , 0 , NULL , 0 ,
V_191 ) ;
}
void F_184 ( struct V_1 * V_13 )
{
struct V_182 * V_151 = F_54 ( V_13 -> V_163 ) ;
if ( ! F_183 ( V_151 -> V_350 . V_256 ) ||
! F_183 ( V_13 ) )
return;
if ( ! V_13 -> V_11 )
return;
F_13 ( V_13 , F_16 ( V_13 , 0 ) ,
V_72 , V_255 ,
V_380 , 0 , NULL , 0 ,
V_191 ) ;
}
int F_141 ( struct V_1 * V_13 , T_3 V_381 )
{
struct V_6 * V_7 = F_3 ( V_13 -> V_22 ) ;
int V_70 = V_13 -> V_122 ;
int V_74 ;
if ( V_13 -> V_382 ) {
if ( ! F_1 ( V_7 -> V_2 ) ) {
V_74 = F_13 ( V_13 , F_16 ( V_13 , 0 ) ,
V_72 , V_255 ,
V_383 , 0 ,
NULL , 0 ,
V_191 ) ;
} else {
V_74 = F_13 ( V_13 , F_16 ( V_13 , 0 ) ,
V_72 ,
V_384 ,
V_385 ,
V_386 |
V_387 ,
NULL , 0 ,
V_191 ) ;
}
if ( V_74 ) {
F_20 ( & V_13 -> V_21 , L_105 ,
V_74 ) ;
if ( F_185 ( V_381 ) )
return V_74 ;
}
}
if ( V_13 -> V_388 == 1 )
F_186 ( V_13 , 0 ) ;
if ( F_182 ( V_13 ) ) {
F_28 ( & V_13 -> V_21 , L_106 ,
V_112 ) ;
return - V_157 ;
}
if ( F_187 ( V_13 ) ) {
F_28 ( & V_13 -> V_21 , L_107 ,
V_112 ) ;
return - V_157 ;
}
if ( F_1 ( V_7 -> V_2 ) )
V_74 = F_18 ( V_7 -> V_2 ,
V_70 | ( V_378 << 3 ) ,
V_389 ) ;
else
V_74 = F_18 ( V_7 -> V_2 , V_70 ,
V_390 ) ;
if ( V_74 ) {
F_20 ( V_7 -> V_111 , L_108 ,
V_70 , V_74 ) ;
if ( V_13 -> V_382 )
( void ) F_13 ( V_13 , F_16 ( V_13 , 0 ) ,
V_69 , V_255 ,
V_383 , 0 ,
NULL , 0 ,
V_191 ) ;
if ( V_13 -> V_391 == 1 )
F_186 ( V_13 , 1 ) ;
F_184 ( V_13 ) ;
F_188 ( V_13 ) ;
if ( ! F_185 ( V_381 ) )
V_74 = 0 ;
} else {
F_20 ( & V_13 -> V_21 , L_109 ,
( F_185 ( V_381 ) ? L_110 : L_37 ) ,
V_13 -> V_382 ) ;
F_61 ( V_13 , V_296 ) ;
F_58 ( 10 ) ;
}
F_160 ( V_7 -> V_2 ) ;
return V_74 ;
}
static int F_189 ( struct V_1 * V_13 )
{
int V_74 = 0 ;
T_1 V_392 ;
F_20 ( & V_13 -> V_21 , L_111 ,
V_13 -> V_212 ? L_112 : L_113 ) ;
F_61 ( V_13 , V_13 -> V_11
? V_82
: V_393 ) ;
if ( V_13 -> V_212 )
V_394:
V_74 = F_190 ( V_13 ) ;
if ( V_74 == 0 ) {
V_392 = 0 ;
V_74 = F_87 ( V_13 , V_255 , 0 , & V_392 ) ;
if ( V_74 >= 0 )
V_74 = ( V_74 > 0 ? 0 : - V_136 ) ;
if ( V_74 && ! V_13 -> V_212 && V_13 -> V_211 ) {
F_20 ( & V_13 -> V_21 , L_114 ) ;
V_13 -> V_212 = 1 ;
goto V_394;
}
}
if ( V_74 ) {
F_20 ( & V_13 -> V_21 , L_115 ,
V_74 ) ;
} else if ( V_13 -> V_11 ) {
F_88 ( & V_392 ) ;
if ( V_392 & ( 1 << V_383 ) ) {
V_74 = F_13 ( V_13 ,
F_16 ( V_13 , 0 ) ,
V_69 ,
V_255 ,
V_383 , 0 ,
NULL , 0 ,
V_191 ) ;
if ( V_74 )
F_20 ( & V_13 -> V_21 ,
L_116 ,
V_74 ) ;
}
V_74 = 0 ;
}
return V_74 ;
}
int F_191 ( struct V_1 * V_13 , T_3 V_381 )
{
struct V_6 * V_7 = F_3 ( V_13 -> V_22 ) ;
int V_70 = V_13 -> V_122 ;
int V_74 ;
T_1 V_199 , V_8 ;
V_74 = F_26 ( V_7 , V_70 , & V_8 , & V_199 ) ;
if ( V_74 == 0 && ! F_180 ( V_7 , V_8 ) )
goto V_395;
F_41 ( V_70 , V_7 -> V_396 ) ;
if ( F_1 ( V_7 -> V_2 ) )
V_74 = F_18 ( V_7 -> V_2 ,
V_70 | ( V_210 << 3 ) ,
V_389 ) ;
else
V_74 = F_17 ( V_7 -> V_2 ,
V_70 , V_390 ) ;
if ( V_74 ) {
F_20 ( V_7 -> V_111 , L_117 ,
V_70 , V_74 ) ;
} else {
F_20 ( & V_13 -> V_21 , L_118 ,
( F_185 ( V_381 ) ? L_110 : L_37 ) ) ;
F_58 ( 25 ) ;
V_74 = F_26 ( V_7 , V_70 , & V_8 , & V_199 ) ;
F_58 ( 10 ) ;
}
V_395:
if ( V_74 == 0 ) {
if ( F_1 ( V_7 -> V_2 ) ) {
if ( V_199 & V_357 )
F_17 ( V_7 -> V_2 , V_70 ,
V_358 ) ;
} else {
if ( V_199 & V_397 )
F_17 ( V_7 -> V_2 , V_70 ,
V_398 ) ;
}
}
F_69 ( V_70 , V_7 -> V_396 ) ;
V_74 = F_181 ( V_13 ,
V_7 , V_70 , V_74 , V_199 , V_8 ) ;
if ( V_74 == 0 )
V_74 = F_189 ( V_13 ) ;
if ( V_74 < 0 ) {
F_20 ( & V_13 -> V_21 , L_119 , V_74 ) ;
F_62 ( V_7 , V_70 ) ;
} else {
if ( V_13 -> V_391 == 1 )
F_186 ( V_13 , 1 ) ;
F_184 ( V_13 ) ;
F_188 ( V_13 ) ;
}
return V_74 ;
}
int F_192 ( struct V_1 * V_13 )
{
int V_74 = 0 ;
if ( V_13 -> V_81 == V_296 ) {
F_20 ( & V_13 -> V_21 , L_118 , L_120 ) ;
V_74 = F_168 ( V_13 ) ;
if ( V_74 == 0 ) {
F_171 ( V_13 ) ;
}
}
return V_74 ;
}
int F_141 ( struct V_1 * V_13 , T_3 V_381 )
{
return 0 ;
}
int F_191 ( struct V_1 * V_13 , T_3 V_381 )
{
struct V_6 * V_7 = F_3 ( V_13 -> V_22 ) ;
int V_70 = V_13 -> V_122 ;
int V_74 ;
T_1 V_199 , V_8 ;
V_74 = F_26 ( V_7 , V_70 , & V_8 , & V_199 ) ;
V_74 = F_181 ( V_13 ,
V_7 , V_70 , V_74 , V_199 , V_8 ) ;
if ( V_74 ) {
F_20 ( & V_13 -> V_21 , L_119 , V_74 ) ;
F_62 ( V_7 , V_70 ) ;
} else if ( V_13 -> V_212 ) {
F_20 ( & V_13 -> V_21 , L_121 ) ;
V_74 = F_190 ( V_13 ) ;
}
return V_74 ;
}
static int F_193 ( struct V_178 * V_179 , T_3 V_381 )
{
struct V_6 * V_7 = F_4 ( V_179 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
unsigned V_70 ;
int V_74 ;
for ( V_70 = 1 ; V_70 <= V_2 -> V_198 ; V_70 ++ ) {
struct V_1 * V_13 ;
V_13 = V_2 -> V_174 [ V_70 - 1 ] ;
if ( V_13 && V_13 -> V_399 ) {
F_7 ( & V_179 -> V_21 , L_122 , V_70 ) ;
if ( F_185 ( V_381 ) )
return - V_294 ;
}
}
if ( F_1 ( V_2 ) && V_2 -> V_382 ) {
for ( V_70 = 1 ; V_70 <= V_2 -> V_198 ; V_70 ++ ) {
V_74 = F_18 ( V_2 ,
V_70 |
V_400 |
V_401 |
V_402 ,
V_403 ) ;
}
}
F_20 ( & V_179 -> V_21 , L_111 , V_112 ) ;
F_72 ( V_7 , V_218 ) ;
return 0 ;
}
static int F_194 ( struct V_178 * V_179 )
{
struct V_6 * V_7 = F_4 ( V_179 ) ;
F_20 ( & V_179 -> V_21 , L_111 , V_112 ) ;
F_66 ( V_7 , V_188 ) ;
return 0 ;
}
static int F_195 ( struct V_178 * V_179 )
{
struct V_6 * V_7 = F_4 ( V_179 ) ;
F_20 ( & V_179 -> V_21 , L_111 , V_112 ) ;
F_66 ( V_7 , V_195 ) ;
return 0 ;
}
void F_196 ( struct V_1 * V_404 )
{
F_7 ( & V_404 -> V_21 , L_123 ) ;
V_404 -> V_212 = 1 ;
}
static int F_197 ( struct V_1 * V_13 , enum V_405 V_81 )
{
struct V_406 * V_407 ;
unsigned long long V_408 ;
unsigned long long V_409 ;
unsigned long long V_410 ;
unsigned long long V_411 ;
int V_55 ;
V_408 = F_198 ( V_13 -> V_51 . V_42 , 1000 ) ;
V_409 = F_198 ( V_13 -> V_51 . V_39 , 1000 ) ;
V_410 = F_198 ( V_13 -> V_52 . V_42 , 1000 ) ;
V_411 = F_198 ( V_13 -> V_52 . V_39 , 1000 ) ;
if ( ( V_81 == V_412 &&
( V_408 > V_413 ||
V_409 > V_413 ) ) ||
( V_81 == V_414 &&
( V_410 > V_415 ||
V_411 > V_415 ) ) ) {
F_20 ( & V_13 -> V_21 , L_124
L_125 ,
V_416 [ V_81 ] , V_408 , V_409 ) ;
return - V_67 ;
}
if ( V_408 > V_413 )
V_408 = V_413 ;
if ( V_409 > V_413 )
V_409 = V_413 ;
if ( V_410 > V_415 )
V_410 = V_415 ;
if ( V_411 > V_415 )
V_411 = V_415 ;
V_407 = F_50 ( sizeof *( V_407 ) , V_197 ) ;
if ( ! V_407 )
return - V_157 ;
V_407 -> V_408 = V_408 ;
V_407 -> V_409 = V_409 ;
V_407 -> V_410 = F_199 ( V_410 ) ;
V_407 -> V_411 = F_199 ( V_411 ) ;
V_55 = F_13 ( V_13 , F_16 ( V_13 , 0 ) ,
V_417 ,
V_255 ,
0 , 0 ,
V_407 , sizeof *( V_407 ) ,
V_191 ) ;
F_48 ( V_407 ) ;
return V_55 ;
}
static int F_200 ( struct V_1 * V_13 ,
enum V_405 V_81 , bool V_418 )
{
int V_55 ;
int V_68 ;
switch ( V_81 ) {
case V_412 :
V_68 = V_419 ;
break;
case V_414 :
V_68 = V_420 ;
break;
default:
F_7 ( & V_13 -> V_21 , L_126 ,
V_112 , V_418 ? L_127 : L_128 ) ;
return - V_67 ;
}
if ( V_13 -> V_81 != V_82 ) {
F_20 ( & V_13 -> V_21 , L_129
L_130 ,
V_112 , V_418 ? L_127 : L_128 ,
V_416 [ V_81 ] ) ;
return 0 ;
}
if ( V_418 ) {
V_55 = F_197 ( V_13 , V_81 ) ;
if ( V_55 < 0 ) {
F_7 ( & V_13 -> V_21 , L_131
L_132 , V_416 [ V_81 ] ) ;
return - V_294 ;
}
V_55 = F_13 ( V_13 , F_16 ( V_13 , 0 ) ,
V_72 ,
V_255 ,
V_68 ,
0 , NULL , 0 ,
V_191 ) ;
} else {
V_55 = F_13 ( V_13 , F_16 ( V_13 , 0 ) ,
V_69 ,
V_255 ,
V_68 ,
0 , NULL , 0 ,
V_191 ) ;
}
if ( V_55 < 0 ) {
F_7 ( & V_13 -> V_21 , L_133 ,
V_418 ? L_134 : L_135 ,
V_416 [ V_81 ] ) ;
return - V_294 ;
}
return 0 ;
}
static int F_201 ( struct V_1 * V_13 ,
enum V_405 V_81 , int V_421 )
{
int V_55 ;
int V_68 ;
switch ( V_81 ) {
case V_412 :
V_68 = V_422 ;
break;
case V_414 :
V_68 = V_423 ;
break;
default:
F_7 ( & V_13 -> V_21 , L_136 ,
V_112 ) ;
return - V_67 ;
}
if ( V_81 == V_412 && V_421 > V_424 &&
V_421 != V_425 ) {
F_7 ( & V_13 -> V_21 , L_137
L_138 ,
V_416 [ V_81 ] , V_421 ) ;
return - V_67 ;
}
V_55 = F_18 ( V_13 -> V_22 ,
F_202 ( V_421 ) | V_13 -> V_122 ,
V_68 ) ;
if ( V_55 < 0 ) {
F_7 ( & V_13 -> V_21 , L_139
L_140 , V_416 [ V_81 ] ,
V_421 , V_55 ) ;
return - V_294 ;
}
if ( V_81 == V_412 )
V_13 -> V_51 . V_421 = V_421 ;
else
V_13 -> V_52 . V_421 = V_421 ;
return 0 ;
}
static void F_203 ( struct V_182 * V_151 , struct V_1 * V_13 ,
enum V_405 V_81 )
{
int V_421 ;
V_421 = V_151 -> V_152 -> V_426 ( V_151 , V_13 , V_81 ) ;
if ( V_421 == 0 )
return;
if ( V_421 < 0 ) {
F_7 ( & V_13 -> V_21 , L_141
L_142 , V_416 [ V_81 ] ,
V_421 ) ;
return;
}
if ( F_201 ( V_13 , V_81 , V_421 ) )
V_151 -> V_152 -> V_427 ( V_151 , V_13 , V_81 ) ;
else if ( V_13 -> V_11 )
F_200 ( V_13 , V_81 , true ) ;
}
static int F_204 ( struct V_182 * V_151 , struct V_1 * V_13 ,
enum V_405 V_81 )
{
int V_68 ;
switch ( V_81 ) {
case V_412 :
V_68 = V_422 ;
break;
case V_414 :
V_68 = V_423 ;
break;
default:
F_7 ( & V_13 -> V_21 , L_143 ,
V_112 ) ;
return - V_67 ;
}
if ( F_201 ( V_13 , V_81 , 0 ) )
return - V_294 ;
F_200 ( V_13 , V_81 , false ) ;
if ( V_151 -> V_152 -> V_427 ( V_151 , V_13 , V_81 ) )
F_7 ( & V_13 -> V_21 , L_144
L_145 ,
V_416 [ V_81 ] ) ;
return 0 ;
}
int F_205 ( struct V_1 * V_13 )
{
struct V_182 * V_151 ;
if ( ! V_13 || ! V_13 -> V_22 ||
V_13 -> V_14 != V_48 ||
! V_13 -> V_23 )
return 0 ;
V_151 = F_54 ( V_13 -> V_163 ) ;
if ( ! V_151 || ! V_151 -> V_152 -> V_427 )
return 0 ;
V_13 -> V_428 ++ ;
if ( ( V_13 -> V_51 . V_421 == 0 && V_13 -> V_52 . V_421 == 0 ) )
return 0 ;
if ( F_204 ( V_151 , V_13 , V_412 ) )
goto V_429;
if ( F_204 ( V_151 , V_13 , V_414 ) )
goto V_429;
return 0 ;
V_429:
F_206 ( V_13 ) ;
return - V_294 ;
}
int F_187 ( struct V_1 * V_13 )
{
struct V_182 * V_151 = F_54 ( V_13 -> V_163 ) ;
int V_55 ;
if ( ! V_151 )
return - V_67 ;
F_27 ( V_151 -> V_430 ) ;
V_55 = F_205 ( V_13 ) ;
F_30 ( V_151 -> V_430 ) ;
return V_55 ;
}
void F_206 ( struct V_1 * V_13 )
{
struct V_182 * V_151 ;
if ( ! V_13 || ! V_13 -> V_22 ||
V_13 -> V_14 != V_48 ||
! V_13 -> V_23 )
return;
V_13 -> V_428 -- ;
V_151 = F_54 ( V_13 -> V_163 ) ;
if ( ! V_151 || ! V_151 -> V_152 -> V_426 ||
! V_151 -> V_152 -> V_427 )
return;
if ( V_13 -> V_428 > 0 )
return;
F_203 ( V_151 , V_13 , V_412 ) ;
F_203 ( V_151 , V_13 , V_414 ) ;
}
void F_188 ( struct V_1 * V_13 )
{
struct V_182 * V_151 = F_54 ( V_13 -> V_163 ) ;
if ( ! V_151 )
return;
F_27 ( V_151 -> V_430 ) ;
F_206 ( V_13 ) ;
F_30 ( V_151 -> V_430 ) ;
}
int F_205 ( struct V_1 * V_13 )
{
return 0 ;
}
void F_206 ( struct V_1 * V_13 ) { }
int F_187 ( struct V_1 * V_13 )
{
return 0 ;
}
void F_188 ( struct V_1 * V_13 ) { }
int F_182 ( struct V_1 * V_13 )
{
return 0 ;
}
void F_184 ( struct V_1 * V_13 ) { }
static int F_207 ( struct V_6 * V_7 , int V_70 )
{
int V_55 ;
int V_431 , V_432 = 0 ;
T_1 V_199 , V_8 ;
unsigned V_433 = 0xffff ;
for ( V_431 = 0 ; ; V_431 += V_434 ) {
V_55 = F_26 ( V_7 , V_70 , & V_8 , & V_199 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( ! ( V_199 & V_202 ) &&
( V_8 & V_200 ) == V_433 ) {
V_432 += V_434 ;
if ( V_432 >= V_213 )
break;
} else {
V_432 = 0 ;
V_433 = V_8 & V_200 ;
}
if ( V_199 & V_202 ) {
F_17 ( V_7 -> V_2 , V_70 ,
V_203 ) ;
}
if ( V_431 >= V_435 )
break;
F_58 ( V_434 ) ;
}
F_20 ( V_7 -> V_111 ,
L_146 ,
V_70 , V_431 , V_432 , V_8 ) ;
if ( V_432 < V_213 )
return - V_102 ;
return V_8 ;
}
void F_208 ( struct V_1 * V_13 )
{
F_209 ( V_13 , 0 + V_63 , true ) ;
F_209 ( V_13 , 0 + V_436 , true ) ;
F_210 ( V_13 , & V_13 -> V_310 , true ) ;
}
static int F_211 ( struct V_1 * V_13 , int V_160 )
{
int V_437 ;
struct V_182 * V_151 = F_54 ( V_13 -> V_163 ) ;
if ( ! V_151 -> V_152 -> V_438 && V_160 <= 1 )
return - V_67 ;
if ( V_13 -> V_81 == V_393 )
return 0 ;
if ( V_13 -> V_81 != V_370 )
return - V_67 ;
if ( V_151 -> V_152 -> V_438 )
V_437 = V_151 -> V_152 -> V_438 ( V_151 , V_13 ) ;
else
V_437 = F_13 ( V_13 , F_212 () ,
V_439 , 0 , V_160 , 0 ,
NULL , 0 , V_191 ) ;
if ( V_437 == 0 ) {
F_125 ( V_13 , V_160 ) ;
F_61 ( V_13 , V_393 ) ;
F_208 ( V_13 ) ;
}
return V_437 ;
}
static int
F_213 ( struct V_6 * V_7 , struct V_1 * V_13 , int V_70 ,
int V_440 )
{
static F_214 ( V_441 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_182 * V_151 = F_54 ( V_2 -> V_163 ) ;
int V_54 , V_442 , V_437 ;
unsigned V_167 = V_367 ;
enum V_443 V_444 = V_13 -> V_14 ;
const char * V_14 ;
int V_160 = V_13 -> V_160 ;
if ( ! V_2 -> V_22 ) {
V_167 = V_445 ;
if ( V_70 == V_2 -> V_163 -> V_328 )
V_2 -> V_163 -> V_329 = 0 ;
}
if ( V_444 == V_365 )
V_167 = V_368 ;
F_27 ( & V_441 ) ;
V_437 = F_175 ( V_7 , V_70 , V_13 , V_167 , false ) ;
if ( V_437 < 0 )
goto V_230;
V_437 = - V_136 ;
if ( V_444 != V_446 && V_444 != V_13 -> V_14 ) {
F_20 ( & V_13 -> V_21 , L_147 ) ;
goto V_230;
}
V_444 = V_13 -> V_14 ;
switch ( V_13 -> V_14 ) {
case V_48 :
case V_364 :
V_13 -> V_310 . V_263 . V_447 = F_199 ( 512 ) ;
break;
case V_15 :
V_13 -> V_310 . V_263 . V_447 = F_199 ( 64 ) ;
break;
case V_366 :
V_13 -> V_310 . V_263 . V_447 = F_199 ( 64 ) ;
break;
case V_365 :
V_13 -> V_310 . V_263 . V_447 = F_199 ( 8 ) ;
break;
default:
goto V_230;
}
if ( V_13 -> V_14 == V_364 )
V_14 = L_148 ;
else
V_14 = F_215 ( V_13 -> V_14 ) ;
if ( V_13 -> V_14 != V_48 )
F_81 ( & V_13 -> V_21 ,
L_149 ,
( V_13 -> V_322 ) ? L_150 : L_151 , V_14 ,
V_160 , V_13 -> V_163 -> V_448 -> V_152 -> V_449 ) ;
if ( V_2 -> V_139 ) {
V_13 -> V_139 = V_2 -> V_139 ;
V_13 -> V_159 = V_2 -> V_159 ;
} else if ( V_13 -> V_14 != V_15
&& V_2 -> V_14 == V_15 ) {
if ( ! V_7 -> V_139 . V_7 ) {
F_28 ( & V_13 -> V_21 , L_152 ) ;
V_437 = - V_67 ;
goto V_230;
}
V_13 -> V_139 = & V_7 -> V_139 ;
V_13 -> V_159 = V_70 ;
}
for ( V_54 = 0 ; V_54 < V_450 ; ( ++ V_54 , F_58 ( 100 ) ) ) {
if ( F_216 ( V_440 ) && ! ( V_151 -> V_152 -> V_116 & V_451 ) ) {
struct V_452 * V_453 ;
int V_454 = 0 ;
#define F_217 64
V_453 = F_50 ( F_217 , V_197 ) ;
if ( ! V_453 ) {
V_437 = - V_157 ;
continue;
}
for ( V_442 = 0 ; V_442 < 3 ; ++ V_442 ) {
V_453 -> V_455 = 0 ;
V_454 = F_13 ( V_13 , F_218 () ,
V_62 , V_63 ,
V_456 << 8 , 0 ,
V_453 , F_217 ,
V_457 ) ;
switch ( V_453 -> V_455 ) {
case 8 : case 16 : case 32 : case 64 : case 255 :
if ( V_453 -> V_458 ==
V_456 ) {
V_454 = 0 ;
break;
}
default:
if ( V_454 == 0 )
V_454 = - V_459 ;
break;
}
if ( V_454 == 0 )
break;
}
V_13 -> V_3 . V_455 =
V_453 -> V_455 ;
F_48 ( V_453 ) ;
V_437 = F_175 ( V_7 , V_70 , V_13 , V_167 , false ) ;
if ( V_437 < 0 )
goto V_230;
if ( V_444 != V_13 -> V_14 ) {
F_20 ( & V_13 -> V_21 ,
L_147 ) ;
V_437 = - V_136 ;
goto V_230;
}
if ( V_454 ) {
F_28 ( & V_13 -> V_21 ,
L_153 ,
V_454 ) ;
V_437 = - V_460 ;
continue;
}
#undef F_217
}
if ( V_13 -> V_304 == 0 ) {
for ( V_442 = 0 ; V_442 < V_461 ; ++ V_442 ) {
V_437 = F_211 ( V_13 , V_160 ) ;
if ( V_437 >= 0 )
break;
F_58 ( 200 ) ;
}
if ( V_437 < 0 ) {
F_28 ( & V_13 -> V_21 ,
L_154 ,
V_160 , V_437 ) ;
goto V_230;
}
if ( V_13 -> V_14 == V_48 ) {
V_160 = V_13 -> V_160 ;
F_81 ( & V_13 -> V_21 ,
L_155 ,
( V_13 -> V_322 ) ? L_150 : L_151 ,
V_160 , V_13 -> V_163 -> V_448 -> V_152 -> V_449 ) ;
}
F_58 ( 10 ) ;
if ( F_216 ( V_440 ) && ! ( V_151 -> V_152 -> V_116 & V_451 ) )
break;
}
V_437 = F_169 ( V_13 , 8 ) ;
if ( V_437 < 8 ) {
F_28 ( & V_13 -> V_21 ,
L_156 ,
V_437 ) ;
if ( V_437 >= 0 )
V_437 = - V_460 ;
} else {
V_437 = 0 ;
break;
}
}
if ( V_437 )
goto V_230;
if ( ( V_13 -> V_14 == V_48 ) &&
( F_29 ( V_13 -> V_3 . V_462 ) < 0x0300 ) ) {
F_28 ( & V_13 -> V_21 , L_157
L_158 ) ;
F_175 ( V_7 , V_70 , V_13 ,
V_361 , true ) ;
V_437 = - V_67 ;
goto V_230;
}
if ( V_13 -> V_3 . V_455 == 0xff ||
V_13 -> V_14 == V_48 )
V_54 = 512 ;
else
V_54 = V_13 -> V_3 . V_455 ;
if ( F_219 ( & V_13 -> V_310 . V_263 ) != V_54 ) {
if ( V_13 -> V_14 == V_365 ||
! ( V_54 == 8 || V_54 == 16 || V_54 == 32 || V_54 == 64 ) ) {
F_28 ( & V_13 -> V_21 , L_159 , V_54 ) ;
V_437 = - V_460 ;
goto V_230;
}
if ( V_13 -> V_14 == V_366 )
F_20 ( & V_13 -> V_21 , L_160 , V_54 ) ;
else
F_7 ( & V_13 -> V_21 , L_161 , V_54 ) ;
V_13 -> V_310 . V_263 . V_447 = F_199 ( V_54 ) ;
F_208 ( V_13 ) ;
}
V_437 = F_169 ( V_13 , V_463 ) ;
if ( V_437 < ( signed ) sizeof( V_13 -> V_3 ) ) {
F_28 ( & V_13 -> V_21 , L_162 ,
V_437 ) ;
if ( V_437 >= 0 )
V_437 = - V_464 ;
goto V_230;
}
if ( V_13 -> V_304 == 0 && F_29 ( V_13 -> V_3 . V_462 ) >= 0x0201 ) {
V_437 = F_220 ( V_13 ) ;
if ( ! V_437 ) {
V_13 -> V_23 = F_5 ( V_13 ) ;
F_11 ( V_13 ) ;
}
}
V_437 = 0 ;
if ( V_151 -> V_152 -> V_465 )
V_151 -> V_152 -> V_465 ( V_151 , V_13 ) ;
V_230:
if ( V_437 ) {
F_60 ( V_7 , V_70 , 0 ) ;
F_125 ( V_13 , V_160 ) ;
}
F_30 ( & V_441 ) ;
return V_437 ;
}
static void
F_221 ( struct V_6 * V_7 , struct V_1 * V_13 , int V_70 )
{
struct V_466 * V_467 ;
int V_74 ;
V_467 = F_50 ( sizeof *V_467 , V_229 ) ;
if ( V_467 == NULL )
return;
V_74 = F_222 ( V_13 , V_468 , 0 ,
V_467 , sizeof *V_467 ) ;
if ( V_74 == sizeof *V_467 ) {
F_81 ( & V_13 -> V_21 , L_163
L_164 ) ;
if ( V_7 -> V_215 ) {
V_7 -> V_86 [ V_70 - 1 ] = V_90 ;
F_23 ( & V_7 -> V_78 , 0 ) ;
}
}
F_48 ( V_467 ) ;
}
static unsigned
F_223 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
int V_262 ;
int V_70 ;
if ( ! V_7 -> V_259 )
return 0 ;
V_262 = V_2 -> V_257 - V_7 -> V_3 -> V_261 ;
for ( V_70 = 1 ; V_70 <= V_2 -> V_198 ; ++ V_70 ) {
struct V_1 * V_13 = V_2 -> V_174 [ V_70 - 1 ] ;
int V_469 ;
if ( ! V_13 )
continue;
if ( V_13 -> V_11 )
V_469 = V_13 -> V_11 -> V_263 . V_470 * 2 ;
else if ( V_70 != V_13 -> V_163 -> V_328 || V_2 -> V_22 )
V_469 = 100 ;
else
V_469 = 8 ;
if ( V_469 > V_7 -> V_258 )
F_7 ( & V_13 -> V_21 ,
L_165 ,
V_469 , V_7 -> V_258 , V_70 ) ;
V_262 -= V_469 ;
}
if ( V_262 < 0 ) {
F_7 ( V_7 -> V_111 , L_166 ,
- V_262 ) ;
V_262 = 0 ;
}
return V_262 ;
}
static void F_224 ( struct V_6 * V_7 , int V_70 ,
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
L_167 ,
V_70 , V_8 , V_199 , F_2 ( V_7 , V_8 ) ) ;
if ( V_7 -> V_215 ) {
F_19 ( V_7 , V_70 , V_88 ) ;
V_7 -> V_86 [ V_70 - 1 ] = V_89 ;
}
#ifdef F_138
if ( V_2 -> V_163 -> V_321 )
V_199 &= ~ ( V_202 |
V_204 ) ;
#endif
V_13 = V_2 -> V_174 [ V_70 - 1 ] ;
if ( ( V_8 & V_200 ) && V_13 &&
V_13 -> V_81 != V_175 ) {
F_127 ( V_13 ) ;
if ( V_8 & V_201 ) {
V_74 = 0 ;
#ifdef F_225
} else if ( V_13 -> V_81 == V_296 &&
V_13 -> V_211 ) {
V_74 = F_192 ( V_13 ) ;
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
V_74 = F_207 ( V_7 , V_70 ) ;
if ( V_74 < 0 ) {
if ( F_226 () )
F_28 ( V_224 , L_168
L_169 , V_70 ) ;
V_8 &= ~ V_200 ;
} else {
V_8 = V_74 ;
}
}
if ( V_151 -> V_471 && ! V_2 -> V_22 ) {
if ( V_8 & V_200 )
F_227 ( V_151 -> V_471 , V_70 ) ;
else
F_228 ( V_151 -> V_471 , V_70 ) ;
}
if ( ! ( V_8 & V_200 ) ||
F_122 ( V_70 , V_7 -> V_180 ) ) {
if ( ( V_168 & V_169 ) < 2
&& ! F_179 ( V_7 , V_8 ) )
F_18 ( V_2 , V_70 , V_170 ) ;
if ( V_8 & V_201 )
goto V_375;
return;
}
for ( V_54 = 0 ; V_54 < V_472 ; V_54 ++ ) {
V_13 = F_229 ( V_2 , V_2 -> V_163 , V_70 ) ;
if ( ! V_13 ) {
F_28 ( V_224 ,
L_170 ,
V_70 ) ;
goto V_375;
}
F_61 ( V_13 , V_473 ) ;
V_13 -> V_257 = V_7 -> V_258 ;
V_13 -> V_190 = V_2 -> V_190 + 1 ;
V_13 -> V_304 = F_172 ( V_7 ) ;
if ( F_1 ( V_7 -> V_2 ) )
V_13 -> V_14 = V_48 ;
else
V_13 -> V_14 = V_446 ;
F_120 ( V_13 ) ;
if ( V_13 -> V_160 <= 0 ) {
V_74 = - V_362 ;
goto V_474;
}
V_74 = F_213 ( V_7 , V_13 , V_70 , V_54 ) ;
if ( V_74 < 0 )
goto V_474;
F_230 ( V_13 ) ;
if ( V_13 -> V_475 & V_476 )
F_58 ( 1000 ) ;
if ( V_13 -> V_3 . V_477 == V_478
&& V_13 -> V_257 <= 100 ) {
T_1 V_479 ;
V_74 = F_87 ( V_13 , V_255 , 0 ,
& V_479 ) ;
if ( V_74 < 2 ) {
F_20 ( & V_13 -> V_21 , L_171 , V_74 ) ;
goto V_480;
}
F_88 ( & V_479 ) ;
if ( ( V_479 & ( 1 << V_260 ) ) == 0 ) {
F_28 ( & V_13 -> V_21 ,
L_172
L_173 ) ;
if ( V_7 -> V_215 ) {
V_7 -> V_86 [ V_70 - 1 ] =
V_94 ;
F_23 ( & V_7 -> V_78 , 0 ) ;
}
V_74 = - V_362 ;
goto V_480;
}
}
if ( F_29 ( V_13 -> V_3 . V_462 ) >= 0x0200
&& V_13 -> V_14 == V_366
&& V_271 != 0 )
F_221 ( V_7 , V_13 , V_70 ) ;
V_74 = 0 ;
F_98 ( & V_287 ) ;
if ( V_2 -> V_81 == V_175 )
V_74 = - V_362 ;
else
V_2 -> V_174 [ V_70 - 1 ] = V_13 ;
F_101 ( & V_287 ) ;
if ( ! V_74 ) {
V_74 = F_148 ( V_13 ) ;
if ( V_74 ) {
F_98 ( & V_287 ) ;
V_2 -> V_174 [ V_70 - 1 ] = NULL ;
F_101 ( & V_287 ) ;
}
}
if ( V_74 )
goto V_480;
V_74 = F_223 ( V_7 ) ;
if ( V_74 )
F_20 ( V_224 , L_174 , V_74 ) ;
return;
V_480:
F_60 ( V_7 , V_70 , 1 ) ;
V_474:
F_208 ( V_13 ) ;
F_124 ( V_13 ) ;
F_126 ( V_13 ) ;
F_231 ( V_13 ) ;
if ( ( V_74 == - V_362 ) || ( V_74 == - V_333 ) )
break;
}
if ( V_7 -> V_2 -> V_22 ||
! V_151 -> V_152 -> V_481 ||
! ( V_151 -> V_152 -> V_481 ) ( V_151 , V_70 ) )
F_28 ( V_224 , L_175 ,
V_70 ) ;
V_375:
F_60 ( V_7 , V_70 , 1 ) ;
if ( V_151 -> V_152 -> V_482 && ! V_7 -> V_2 -> V_22 )
V_151 -> V_152 -> V_482 ( V_151 , V_70 ) ;
}
static int F_232 ( struct V_6 * V_7 , unsigned int V_110 ,
T_1 V_8 , T_1 V_199 )
{
struct V_1 * V_2 ;
struct V_1 * V_13 ;
int V_483 = 0 ;
int V_55 ;
V_2 = V_7 -> V_2 ;
V_13 = V_2 -> V_174 [ V_110 - 1 ] ;
if ( ! F_1 ( V_2 ) ) {
if ( ! ( V_199 & V_397 ) )
return 0 ;
F_17 ( V_2 , V_110 , V_398 ) ;
} else {
if ( ! V_13 || V_13 -> V_81 != V_296 ||
( V_8 & V_209 ) !=
V_210 )
return 0 ;
}
if ( V_13 ) {
F_58 ( 10 ) ;
F_127 ( V_13 ) ;
V_55 = F_192 ( V_13 ) ;
F_131 ( V_13 ) ;
if ( V_55 < 0 )
V_483 = 1 ;
} else {
V_55 = - V_136 ;
F_60 ( V_7 , V_110 , 1 ) ;
}
F_20 ( V_7 -> V_111 , L_176 ,
V_110 , V_55 ) ;
return V_483 ;
}
static void F_233 ( void )
{
struct V_145 * V_484 ;
struct V_1 * V_2 ;
struct V_178 * V_179 ;
struct V_6 * V_7 ;
struct V_223 * V_224 ;
T_1 V_225 ;
T_1 V_226 ;
T_1 V_8 ;
T_1 V_199 ;
int V_54 , V_55 ;
int V_483 , V_485 ;
while ( 1 ) {
F_98 ( & V_117 ) ;
if ( F_33 ( & V_120 ) ) {
F_101 ( & V_117 ) ;
break;
}
V_484 = V_120 . V_146 ;
F_99 ( V_484 ) ;
V_7 = F_46 ( V_484 , struct V_6 , V_119 ) ;
F_234 ( & V_7 -> V_269 ) ;
F_101 ( & V_117 ) ;
V_2 = V_7 -> V_2 ;
V_224 = V_7 -> V_111 ;
V_179 = F_36 ( V_224 ) ;
F_20 ( V_224 , L_177 ,
V_2 -> V_81 , V_7 -> V_3
? V_7 -> V_3 -> V_84
: 0 ,
( T_1 ) V_7 -> V_177 [ 0 ] ,
( T_1 ) V_7 -> V_134 [ 0 ] ) ;
F_127 ( V_2 ) ;
if ( F_235 ( V_7 -> V_118 ) )
goto V_486;
if ( V_2 -> V_81 == V_175 ) {
V_7 -> error = - V_136 ;
F_72 ( V_7 , V_270 ) ;
goto V_474;
}
V_55 = F_64 ( V_179 ) ;
if ( V_55 ) {
F_20 ( V_224 , L_178 , V_55 ) ;
goto V_474;
}
if ( V_7 -> V_83 )
goto V_487;
if ( V_7 -> error ) {
F_20 ( V_224 , L_179 ,
V_7 -> error ) ;
V_55 = F_236 ( V_2 ) ;
if ( V_55 ) {
F_20 ( V_224 ,
L_180 , V_55 ) ;
goto V_487;
}
V_7 -> V_130 = 0 ;
V_7 -> error = 0 ;
}
for ( V_54 = 1 ; V_54 <= V_7 -> V_3 -> V_84 ; V_54 ++ ) {
if ( F_122 ( V_54 , V_7 -> V_396 ) )
continue;
V_483 = F_122 ( V_54 , V_7 -> V_177 ) ;
V_485 = F_237 ( V_54 , V_7 -> V_123 ) ;
if ( ! F_237 ( V_54 , V_7 -> V_134 ) &&
! V_483 && ! V_485 )
continue;
V_55 = F_26 ( V_7 , V_54 ,
& V_8 , & V_199 ) ;
if ( V_55 < 0 )
continue;
if ( V_199 & V_202 ) {
F_17 ( V_2 , V_54 ,
V_203 ) ;
V_483 = 1 ;
}
if ( V_199 & V_204 ) {
if ( ! V_483 )
F_20 ( V_224 ,
L_181
L_182 ,
V_54 , V_8 ) ;
F_17 ( V_2 , V_54 ,
V_205 ) ;
if ( ! ( V_8 & V_201 )
&& ! V_483
&& V_2 -> V_174 [ V_54 - 1 ] ) {
F_28 ( V_224 ,
L_183
L_184
L_185 ,
V_54 ) ;
V_483 = 1 ;
}
}
if ( F_232 ( V_7 , V_54 ,
V_8 , V_199 ) )
V_483 = 1 ;
if ( V_199 & V_488 ) {
T_1 V_74 = 0 ;
T_1 V_489 ;
F_20 ( V_224 , L_186
L_187 , V_54 ) ;
F_17 ( V_2 , V_54 ,
V_490 ) ;
F_58 ( 100 ) ;
F_56 ( V_7 , true ) ;
F_26 ( V_7 , V_54 , & V_74 , & V_489 ) ;
if ( V_74 & V_491 )
F_28 ( V_224 , L_188
L_189 , V_54 ) ;
}
if ( V_199 & V_359 ) {
F_20 ( V_224 ,
L_190 ,
V_54 ) ;
F_17 ( V_2 , V_54 ,
V_360 ) ;
}
if ( ( V_199 & V_206 ) &&
F_1 ( V_7 -> V_2 ) ) {
F_20 ( V_224 ,
L_191 ,
V_54 ) ;
F_17 ( V_2 , V_54 ,
V_207 ) ;
}
if ( V_199 & V_357 ) {
F_17 ( V_7 -> V_2 , V_54 ,
V_358 ) ;
}
if ( V_199 & V_492 ) {
F_7 ( V_224 ,
L_192 ,
V_54 ) ;
F_17 ( V_7 -> V_2 , V_54 ,
V_493 ) ;
}
if ( F_173 ( V_7 , V_8 ) ) {
F_20 ( V_224 , L_193 , V_54 ) ;
F_175 ( V_7 , V_54 , NULL ,
V_361 , true ) ;
}
if ( V_483 )
F_224 ( V_7 , V_54 ,
V_8 , V_199 ) ;
}
if ( F_237 ( 0 , V_7 -> V_134 ) == 0 )
;
else if ( F_59 ( V_7 , & V_225 , & V_226 ) < 0 )
F_28 ( V_224 , L_194 ) ;
else {
if ( V_226 & V_494 ) {
F_20 ( V_224 , L_195 ) ;
F_15 ( V_2 , V_495 ) ;
if ( V_225 & V_265 )
V_7 -> V_259 = 1 ;
else
V_7 -> V_259 = 0 ;
}
if ( V_226 & V_496 ) {
T_1 V_74 = 0 ;
T_1 V_489 ;
F_20 ( V_224 , L_196 ) ;
F_15 ( V_2 , V_497 ) ;
F_58 ( 500 ) ;
F_56 ( V_7 , true ) ;
F_59 ( V_7 , & V_74 , & V_489 ) ;
if ( V_74 & V_266 )
F_28 ( V_224 , L_188
L_197 ) ;
}
}
V_487:
F_100 ( V_179 ) ;
V_474:
F_65 ( V_179 ) ;
V_486:
F_131 ( V_2 ) ;
F_104 ( & V_7 -> V_269 , F_94 ) ;
}
}
static int F_238 ( void * V_498 )
{
F_239 () ;
do {
F_233 () ;
F_240 ( V_121 ,
! F_33 ( & V_120 ) ||
F_241 () ) ;
} while ( ! F_241 () || ! F_33 ( & V_120 ) );
F_242 ( L_198 , V_499 ) ;
return 0 ;
}
int F_243 ( void )
{
if ( F_244 ( & V_500 ) < 0 ) {
F_245 ( V_501 L_199 ,
V_499 ) ;
return - 1 ;
}
V_502 = F_246 ( F_238 , NULL , L_200 ) ;
if ( ! F_247 ( V_502 ) )
return 0 ;
F_248 ( & V_500 ) ;
F_245 ( V_501 L_201 , V_499 ) ;
return - 1 ;
}
void F_249 ( void )
{
F_250 ( V_502 ) ;
F_248 ( & V_500 ) ;
}
static int F_251 ( struct V_1 * V_13 ,
struct V_452 * V_503 )
{
int V_79 = 0 ;
unsigned V_504 ;
unsigned V_505 = 0 ;
unsigned V_506 ;
unsigned V_507 ;
int V_508 ;
char * V_453 ;
if ( memcmp ( & V_13 -> V_3 , V_503 ,
sizeof( * V_503 ) ) != 0 )
return 1 ;
if ( V_13 -> V_319 )
V_505 = strlen ( V_13 -> V_319 ) + 1 ;
V_506 = V_505 ;
for ( V_504 = 0 ; V_504 < V_13 -> V_3 . V_343 ; V_504 ++ ) {
V_507 = F_29 ( V_13 -> V_322 [ V_504 ] . V_263 . V_325 ) ;
V_506 = F_57 ( V_506 , V_507 ) ;
}
V_453 = F_50 ( V_506 , V_197 ) ;
if ( V_453 == NULL ) {
F_28 ( & V_13 -> V_21 , L_202 ) ;
return 1 ;
}
for ( V_504 = 0 ; V_504 < V_13 -> V_3 . V_343 ; V_504 ++ ) {
V_507 = F_29 ( V_13 -> V_322 [ V_504 ] . V_263 . V_325 ) ;
V_508 = F_222 ( V_13 , V_509 , V_504 , V_453 ,
V_507 ) ;
if ( V_508 != V_507 ) {
F_20 ( & V_13 -> V_21 , L_203 ,
V_504 , V_508 ) ;
V_79 = 1 ;
break;
}
if ( memcmp ( V_453 , V_13 -> V_324 [ V_504 ] , V_507 )
!= 0 ) {
F_20 ( & V_13 -> V_21 , L_204 ,
V_504 ,
( (struct V_510 * ) V_453 ) ->
V_511 ) ;
V_79 = 1 ;
break;
}
}
if ( ! V_79 && V_505 ) {
V_508 = F_252 ( V_13 , V_13 -> V_3 . V_316 ,
V_453 , V_505 ) ;
if ( V_508 + 1 != V_505 ) {
F_20 ( & V_13 -> V_21 , L_205 ,
V_508 ) ;
V_79 = 1 ;
} else if ( memcmp ( V_453 , V_13 -> V_319 , V_508 ) != 0 ) {
F_20 ( & V_13 -> V_21 , L_206 ) ;
V_79 = 1 ;
}
}
F_48 ( V_453 ) ;
return V_79 ;
}
static int F_190 ( struct V_1 * V_13 )
{
struct V_1 * V_512 = V_13 -> V_22 ;
struct V_6 * V_513 ;
struct V_182 * V_151 = F_54 ( V_13 -> V_163 ) ;
struct V_452 V_3 = V_13 -> V_3 ;
int V_54 , V_55 = 0 ;
int V_70 = V_13 -> V_122 ;
if ( V_13 -> V_81 == V_175 ||
V_13 -> V_81 == V_296 ) {
F_20 ( & V_13 -> V_21 , L_207 ,
V_13 -> V_81 ) ;
return - V_67 ;
}
if ( ! V_512 ) {
F_20 ( & V_13 -> V_21 , L_208 , V_112 ) ;
return - V_514 ;
}
V_513 = F_3 ( V_512 ) ;
V_55 = F_187 ( V_13 ) ;
if ( V_55 ) {
F_28 ( & V_13 -> V_21 , L_209 , V_112 ) ;
goto V_515;
}
V_55 = F_182 ( V_13 ) ;
if ( V_55 ) {
F_28 ( & V_13 -> V_21 , L_210 ,
V_112 ) ;
goto V_515;
}
F_41 ( V_70 , V_513 -> V_396 ) ;
for ( V_54 = 0 ; V_54 < V_472 ; ++ V_54 ) {
F_208 ( V_13 ) ;
V_55 = F_213 ( V_513 , V_13 , V_70 , V_54 ) ;
if ( V_55 >= 0 || V_55 == - V_362 || V_55 == - V_136 )
break;
}
F_69 ( V_70 , V_513 -> V_396 ) ;
if ( V_55 < 0 )
goto V_515;
if ( F_251 ( V_13 , & V_3 ) ) {
F_81 ( & V_13 -> V_21 , L_211 ) ;
V_13 -> V_3 = V_3 ;
goto V_515;
}
if ( ! V_13 -> V_11 )
goto V_375;
F_27 ( V_151 -> V_430 ) ;
V_55 = F_253 ( V_13 , V_13 -> V_11 , NULL , NULL ) ;
if ( V_55 < 0 ) {
F_7 ( & V_13 -> V_21 ,
L_212
L_213 ) ;
F_30 ( V_151 -> V_430 ) ;
goto V_515;
}
V_55 = F_13 ( V_13 , F_16 ( V_13 , 0 ) ,
V_516 , 0 ,
V_13 -> V_11 -> V_263 . V_511 , 0 ,
NULL , 0 , V_191 ) ;
if ( V_55 < 0 ) {
F_28 ( & V_13 -> V_21 ,
L_214 ,
V_13 -> V_11 -> V_263 . V_511 , V_55 ) ;
F_30 ( V_151 -> V_430 ) ;
goto V_515;
}
F_30 ( V_151 -> V_430 ) ;
F_61 ( V_13 , V_82 ) ;
for ( V_54 = 0 ; V_54 < V_13 -> V_11 -> V_263 . V_517 ; V_54 ++ ) {
struct V_518 * V_322 = V_13 -> V_11 ;
struct V_178 * V_179 = V_322 -> V_12 [ V_54 ] ;
struct V_519 * V_263 ;
V_263 = & V_179 -> V_275 -> V_263 ;
if ( V_263 -> V_520 == 0 ) {
F_254 ( V_13 , V_179 , true ) ;
F_255 ( V_13 , V_179 , true ) ;
V_55 = 0 ;
} else {
V_179 -> V_521 = 1 ;
V_55 = F_86 ( V_13 , V_263 -> V_522 ,
V_263 -> V_520 ) ;
V_179 -> V_521 = 0 ;
}
if ( V_55 < 0 ) {
F_28 ( & V_13 -> V_21 , L_215
L_216 ,
V_263 -> V_522 ,
V_263 -> V_520 ,
V_55 ) ;
goto V_515;
}
}
V_375:
F_188 ( V_13 ) ;
F_184 ( V_13 ) ;
return 0 ;
V_515:
F_62 ( V_513 , V_70 ) ;
return - V_136 ;
}
int F_236 ( struct V_1 * V_13 )
{
int V_55 ;
int V_54 ;
struct V_518 * V_322 = V_13 -> V_11 ;
if ( V_13 -> V_81 == V_175 ||
V_13 -> V_81 == V_296 ) {
F_20 ( & V_13 -> V_21 , L_207 ,
V_13 -> V_81 ) ;
return - V_67 ;
}
F_168 ( V_13 ) ;
if ( V_322 ) {
for ( V_54 = 0 ; V_54 < V_322 -> V_263 . V_517 ; ++ V_54 ) {
struct V_178 * V_523 = V_322 -> V_12 [ V_54 ] ;
struct V_524 * V_150 ;
int V_525 = 0 ;
if ( V_523 -> V_21 . V_152 ) {
V_150 = F_256 ( V_523 -> V_21 . V_152 ) ;
if ( V_150 -> V_526 && V_150 -> V_527 )
V_525 = ( V_150 -> V_526 ) ( V_523 ) ;
else if ( V_523 -> V_528 ==
V_529 )
V_525 = 1 ;
if ( V_525 )
F_257 ( V_523 ) ;
}
}
}
V_55 = F_190 ( V_13 ) ;
if ( V_322 ) {
for ( V_54 = V_322 -> V_263 . V_517 - 1 ; V_54 >= 0 ; -- V_54 ) {
struct V_178 * V_523 = V_322 -> V_12 [ V_54 ] ;
struct V_524 * V_150 ;
int V_530 = V_523 -> V_531 ;
if ( ! V_530 && V_523 -> V_21 . V_152 ) {
V_150 = F_256 ( V_523 -> V_21 . V_152 ) ;
if ( V_150 -> V_527 )
V_530 = ( V_150 -> V_527 ) ( V_523 ) ;
else if ( V_523 -> V_528 ==
V_529 )
V_530 = 1 ;
}
if ( V_55 == 0 && V_530 )
F_258 ( V_523 ) ;
}
}
F_171 ( V_13 ) ;
return V_55 ;
}
void F_259 ( struct V_178 * V_532 )
{
F_55 ( & V_532 -> V_533 ) ;
}
