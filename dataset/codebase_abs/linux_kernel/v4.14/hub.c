static inline char * F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( F_2 ( V_2 -> V_4 ) )
return L_1 ;
if ( F_3 ( V_2 -> V_4 ) )
return L_2 ;
if ( V_3 & V_5 )
return L_3 ;
else if ( V_3 & V_6 )
return L_4 ;
else
return L_5 ;
}
struct V_1 * F_4 ( struct V_7 * V_4 )
{
if ( ! V_4 || ! V_4 -> V_8 || ! V_4 -> V_9 )
return NULL ;
return F_5 ( V_4 -> V_8 -> V_10 [ 0 ] ) ;
}
int F_6 ( struct V_7 * V_11 )
{
if ( V_11 -> V_12 & V_13 )
return 0 ;
if ( V_11 -> V_14 == V_15 || V_11 -> V_14 == V_16 ) {
if ( V_11 -> V_17 -> V_18 &&
( V_19 &
F_7 ( V_11 -> V_17 -> V_18 -> V_20 ) ) )
return 1 ;
return 0 ;
}
if ( ! V_11 -> V_17 -> V_21 ) {
F_8 ( & V_11 -> V_22 , L_6 ) ;
return 0 ;
}
if ( V_11 -> V_17 -> V_21 -> V_23 == 0 &&
V_11 -> V_17 -> V_21 -> V_24 == 0 ) {
if ( V_11 -> V_25 )
F_8 ( & V_11 -> V_22 , L_7 ) ;
else
F_8 ( & V_11 -> V_22 , L_8 ) ;
return 0 ;
}
if ( ! V_11 -> V_25 || V_11 -> V_25 -> V_26 )
return 1 ;
return 0 ;
}
static void F_9 ( struct V_7 * V_11 ,
struct V_27 * V_28 ,
unsigned int V_29 ,
struct V_1 * V_2 ,
struct V_27 * V_30 ,
unsigned int V_31 )
{
unsigned int V_32 ;
unsigned int V_33 ;
unsigned int V_34 ;
V_32 = V_30 -> V_35 +
( V_2 -> V_36 -> V_37 . V_38 . V_39 * 100 ) ;
V_33 = V_29 * 1000 ;
V_34 = V_31 * 1000 ;
if ( V_33 > V_34 )
V_32 += V_33 ;
else
V_32 += V_34 ;
V_28 -> V_35 = V_32 ;
}
static void F_10 ( struct V_7 * V_11 ,
struct V_27 * V_28 ,
unsigned int V_29 ,
struct V_1 * V_2 ,
struct V_27 * V_30 ,
unsigned int V_31 ,
unsigned int V_40 )
{
unsigned int V_41 ;
unsigned int V_42 ;
if ( V_29 > V_31 )
V_41 = V_29 * 1000 ;
else
V_41 = V_31 * 1000 ;
V_42 = V_40 * 1000 + V_30 -> V_43 ;
if ( V_41 > V_42 )
V_28 -> V_43 = V_41 ;
else
V_28 -> V_43 = V_42 ;
}
static void F_11 ( struct V_7 * V_11 ,
struct V_27 * V_28 )
{
struct V_7 * V_25 ;
unsigned int V_44 ;
unsigned int V_45 ;
V_45 = V_28 -> V_43 ;
for ( V_25 = V_11 -> V_25 , V_44 = 0 ; V_25 -> V_25 ;
V_25 = V_25 -> V_25 )
V_44 ++ ;
if ( V_44 > 0 )
V_45 += 2100 + 250 * ( V_44 - 1 ) ;
V_45 += 250 * V_44 ;
V_28 -> V_46 = V_45 ;
}
static void F_12 ( struct V_7 * V_11 )
{
struct V_1 * V_2 ;
unsigned int V_47 ;
unsigned int V_48 ;
unsigned int V_49 ;
unsigned int V_50 ;
unsigned int V_51 ;
if ( ! V_11 -> V_26 || V_11 -> V_14 < V_52 )
return;
V_2 = F_4 ( V_11 -> V_25 ) ;
if ( ! V_2 )
return;
V_48 = V_11 -> V_17 -> V_21 -> V_23 ;
V_49 = F_13 ( V_11 -> V_17 -> V_21 -> V_24 ) ;
V_50 = V_11 -> V_25 -> V_17 -> V_21 -> V_23 ;
V_51 = F_13 ( V_11 -> V_25 -> V_17 -> V_21 -> V_24 ) ;
F_9 ( V_11 , & V_11 -> V_53 , V_48 ,
V_2 , & V_11 -> V_25 -> V_53 , V_50 ) ;
F_9 ( V_11 , & V_11 -> V_54 , V_49 ,
V_2 , & V_11 -> V_25 -> V_54 , V_51 ) ;
V_47 = 1 ;
F_10 ( V_11 , & V_11 -> V_53 , V_48 ,
V_2 , & V_11 -> V_25 -> V_53 , V_50 ,
V_47 ) ;
if ( V_51 > V_50 )
V_47 = 1 + V_51 - V_50 ;
else
V_47 = 1 + V_50 ;
F_10 ( V_11 , & V_11 -> V_54 , V_49 ,
V_2 , & V_11 -> V_25 -> V_54 , V_51 ,
V_47 ) ;
F_11 ( V_11 , & V_11 -> V_53 ) ;
F_11 ( V_11 , & V_11 -> V_54 ) ;
}
static int F_14 ( struct V_7 * V_4 ,
struct V_55 * V_56 )
{
int V_57 , V_58 , V_59 ;
unsigned V_60 ;
if ( F_3 ( V_4 ) ) {
V_60 = V_61 ;
V_59 = V_62 ;
} else {
V_60 = V_63 ;
V_59 = sizeof( struct V_55 ) ;
}
for ( V_57 = 0 ; V_57 < 3 ; V_57 ++ ) {
V_58 = F_15 ( V_4 , F_16 ( V_4 , 0 ) ,
V_64 , V_65 | V_66 ,
V_60 << 8 , 0 , V_56 , V_59 ,
V_67 ) ;
if ( F_3 ( V_4 ) ) {
if ( V_58 == V_59 )
return V_58 ;
} else if ( V_58 >= V_68 + 2 ) {
V_59 = V_68 + V_56 -> V_69 / 8 + 1 ;
if ( V_58 < V_59 )
return - V_70 ;
return V_58 ;
}
}
return - V_71 ;
}
static int F_17 ( struct V_7 * V_4 , int V_72 )
{
return F_15 ( V_4 , F_18 ( V_4 , 0 ) ,
V_73 , V_66 , V_72 , 0 , NULL , 0 , 1000 ) ;
}
int F_19 ( struct V_7 * V_4 , int V_74 , int V_72 )
{
return F_15 ( V_4 , F_18 ( V_4 , 0 ) ,
V_73 , V_75 , V_72 , V_74 ,
NULL , 0 , 1000 ) ;
}
static int F_20 ( struct V_7 * V_4 , int V_74 , int V_72 )
{
return F_15 ( V_4 , F_18 ( V_4 , 0 ) ,
V_76 , V_75 , V_72 , V_74 ,
NULL , 0 , 1000 ) ;
}
static char * F_21 ( int V_77 )
{
switch ( V_77 ) {
case V_78 :
return L_9 ;
case V_79 :
return L_10 ;
case V_80 :
return L_11 ;
case V_81 :
return L_12 ;
default:
return L_13 ;
}
}
static void F_22 ( struct V_1 * V_2 , int V_74 , int V_77 )
{
struct V_82 * V_83 = V_2 -> V_84 [ V_74 - 1 ] ;
int V_85 ;
V_85 = F_20 ( V_2 -> V_4 , ( V_77 << 8 ) | V_74 ,
V_86 ) ;
F_23 ( & V_83 -> V_22 , L_14 ,
F_21 ( V_77 ) , V_85 ) ;
}
static void F_24 ( struct V_87 * V_88 )
{
struct V_1 * V_2 =
F_25 ( V_88 , struct V_1 , V_89 . V_88 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
unsigned V_57 ;
unsigned V_90 = 0 ;
int V_91 = - 1 ;
if ( V_4 -> V_92 != V_93 || V_2 -> V_94 )
return;
for ( V_57 = 0 ; V_57 < V_4 -> V_9 ; V_57 ++ ) {
unsigned V_77 , V_95 ;
switch ( V_2 -> V_96 [ V_57 ] ) {
case V_97 :
V_91 = V_57 ;
V_77 = V_81 ;
V_95 = V_98 ;
break;
case V_99 :
V_77 = V_79 ;
V_95 = V_100 ;
break;
case V_100 :
V_77 = V_80 ;
V_95 = V_99 ;
break;
case V_101 :
V_77 = V_78 ;
V_95 = V_102 ;
break;
case V_102 :
V_77 = V_80 ;
V_95 = V_101 ;
break;
case V_103 :
V_77 = V_79 ;
V_95 = V_104 ;
break;
case V_104 :
V_77 = V_78 ;
V_95 = V_103 ;
break;
default:
continue;
}
if ( V_77 != V_81 )
V_90 = 1 ;
F_22 ( V_2 , V_57 + 1 , V_77 ) ;
V_2 -> V_96 [ V_57 ] = V_95 ;
}
if ( ! V_90 && V_105 ) {
V_91 ++ ;
V_91 %= V_4 -> V_9 ;
F_22 ( V_2 , V_91 + 1 , V_79 ) ;
V_2 -> V_96 [ V_91 ] = V_97 ;
V_90 ++ ;
}
if ( V_90 )
F_26 ( V_106 ,
& V_2 -> V_89 , V_107 ) ;
}
static int F_27 ( struct V_7 * V_4 ,
struct V_108 * V_109 )
{
int V_57 , V_85 = - V_110 ;
for ( V_57 = 0 ; V_57 < V_111 &&
( V_85 == - V_110 || V_85 == - V_112 ) ; V_57 ++ ) {
V_85 = F_15 ( V_4 , F_16 ( V_4 , 0 ) ,
V_113 , V_65 | V_66 , 0 , 0 ,
V_109 , sizeof( * V_109 ) , V_114 ) ;
}
return V_85 ;
}
static int F_28 ( struct V_7 * V_4 , int V_74 ,
void * V_109 , T_1 V_115 , T_1 V_116 )
{
int V_57 , V_85 = - V_110 ;
for ( V_57 = 0 ; V_57 < V_111 &&
( V_85 == - V_110 || V_85 == - V_112 ) ; V_57 ++ ) {
V_85 = F_15 ( V_4 , F_16 ( V_4 , 0 ) ,
V_113 , V_65 | V_75 , V_115 ,
V_74 , V_109 , V_116 , V_114 ) ;
}
return V_85 ;
}
static int F_29 ( struct V_1 * V_2 , int V_74 , int type ,
T_1 * V_85 , T_1 * V_117 , T_2 * V_118 )
{
int V_58 ;
int V_119 = 4 ;
if ( type != V_120 )
V_119 = 8 ;
F_30 ( & V_2 -> V_121 ) ;
V_58 = F_28 ( V_2 -> V_4 , V_74 , & V_2 -> V_85 -> V_122 , type , V_119 ) ;
if ( V_58 < V_119 ) {
if ( V_58 != - V_123 )
F_31 ( V_2 -> V_124 ,
L_15 , V_125 , V_58 ) ;
if ( V_58 >= 0 )
V_58 = - V_126 ;
} else {
* V_85 = F_13 ( V_2 -> V_85 -> V_122 . V_127 ) ;
* V_117 = F_13 ( V_2 -> V_85 -> V_122 . V_128 ) ;
if ( type != V_120 && V_118 )
* V_118 = F_7 (
V_2 -> V_85 -> V_122 . V_129 ) ;
V_58 = 0 ;
}
F_32 ( & V_2 -> V_121 ) ;
return V_58 ;
}
static int F_33 ( struct V_1 * V_2 , int V_74 ,
T_1 * V_85 , T_1 * V_117 )
{
return F_29 ( V_2 , V_74 , V_120 ,
V_85 , V_117 , NULL ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_130 * V_131 ;
if ( V_2 -> V_132 || F_35 ( & V_2 -> V_133 ) )
return;
V_131 = F_36 ( V_2 -> V_124 ) ;
F_37 ( V_131 ) ;
F_38 ( & V_2 -> V_134 ) ;
if ( F_39 ( V_135 , & V_2 -> V_133 ) )
return;
F_40 ( V_131 ) ;
F_41 ( & V_2 -> V_134 , V_136 ) ;
}
void F_42 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
if ( V_2 )
F_34 ( V_2 ) ;
}
void F_43 ( struct V_7 * V_4 ,
unsigned int V_137 )
{
struct V_1 * V_2 ;
if ( ! V_4 )
return;
V_2 = F_4 ( V_4 ) ;
if ( V_2 ) {
F_44 ( V_137 , V_2 -> V_138 ) ;
F_34 ( V_2 ) ;
}
}
static void F_45 ( struct V_139 * V_139 )
{
struct V_1 * V_2 = V_139 -> V_140 ;
int V_85 = V_139 -> V_85 ;
unsigned V_57 ;
unsigned long V_141 ;
switch ( V_85 ) {
case - V_142 :
case - V_143 :
case - V_144 :
return;
default:
F_23 ( V_2 -> V_124 , L_16 , V_85 ) ;
if ( ( ++ V_2 -> V_145 < 10 ) || V_2 -> error )
goto V_146;
V_2 -> error = V_85 ;
case 0 :
V_141 = 0 ;
for ( V_57 = 0 ; V_57 < V_139 -> V_147 ; ++ V_57 )
V_141 |= ( ( unsigned long ) ( ( * V_2 -> V_148 ) [ V_57 ] ) )
<< ( V_57 * 8 ) ;
V_2 -> V_149 [ 0 ] = V_141 ;
break;
}
V_2 -> V_145 = 0 ;
F_34 ( V_2 ) ;
V_146:
if ( V_2 -> V_94 )
return;
V_85 = F_46 ( V_2 -> V_139 , V_150 ) ;
if ( V_85 != 0 && V_85 != - V_123 && V_85 != - V_151 )
F_31 ( V_2 -> V_124 , L_17 , V_85 ) ;
}
static inline int
F_47 ( struct V_7 * V_4 , T_1 V_152 , T_1 V_153 )
{
if ( ( ( V_152 >> 11 ) & V_154 ) ==
V_155 ) {
int V_85 = F_15 ( V_4 , F_18 ( V_4 , 0 ) ,
V_156 , V_75 ,
V_152 ^ 0x8000 , V_153 , NULL , 0 , 1000 ) ;
if ( V_85 )
return V_85 ;
}
return F_15 ( V_4 , F_18 ( V_4 , 0 ) ,
V_156 , V_75 , V_152 ,
V_153 , NULL , 0 , 1000 ) ;
}
static void F_48 ( struct V_87 * V_88 )
{
struct V_1 * V_2 =
F_25 ( V_88 , struct V_1 , V_153 . V_157 ) ;
unsigned long V_158 ;
F_49 ( & V_2 -> V_153 . V_159 , V_158 ) ;
while ( ! F_50 ( & V_2 -> V_153 . V_160 ) ) {
struct V_161 * V_162 ;
struct V_163 * V_164 ;
struct V_7 * V_4 = V_2 -> V_4 ;
const struct V_165 * V_166 ;
int V_85 ;
V_162 = V_2 -> V_153 . V_160 . V_162 ;
V_164 = F_51 ( V_162 , struct V_163 , V_160 ) ;
F_52 ( & V_164 -> V_160 ) ;
F_53 ( & V_2 -> V_153 . V_159 , V_158 ) ;
V_85 = F_47 ( V_4 , V_164 -> V_152 , V_164 -> V_153 ) ;
if ( V_85 && V_85 != - V_123 )
F_31 ( & V_4 -> V_22 ,
L_18 ,
V_164 -> V_153 , V_164 -> V_152 , V_85 ) ;
V_166 = V_164 -> V_167 -> V_168 ;
if ( V_166 -> V_169 )
( V_166 -> V_169 ) ( V_164 -> V_167 , V_164 -> V_170 ) ;
F_54 ( V_164 ) ;
F_49 ( & V_2 -> V_153 . V_159 , V_158 ) ;
}
F_53 ( & V_2 -> V_153 . V_159 , V_158 ) ;
}
int F_55 ( struct V_7 * V_4 , struct V_1 * V_2 ,
int V_74 , bool V_171 )
{
int V_58 ;
if ( V_171 )
V_58 = F_20 ( V_4 , V_74 , V_172 ) ;
else
V_58 = F_19 ( V_4 , V_74 , V_172 ) ;
if ( V_58 )
return V_58 ;
if ( V_171 )
F_44 ( V_74 , V_2 -> V_173 ) ;
else
F_56 ( V_74 , V_2 -> V_173 ) ;
return 0 ;
}
int F_57 ( struct V_139 * V_139 )
{
struct V_7 * V_11 = V_139 -> V_22 ;
int V_174 = V_139 -> V_174 ;
struct V_175 * V_153 = V_11 -> V_153 ;
unsigned long V_158 ;
struct V_163 * V_164 ;
V_164 = F_58 ( sizeof *V_164 , V_150 ) ;
if ( V_164 == NULL ) {
F_31 ( & V_11 -> V_22 , L_19 ) ;
return - V_176 ;
}
V_164 -> V_153 = V_153 -> V_177 ? V_11 -> V_178 : 1 ;
V_164 -> V_152 = F_59 ( V_174 ) ;
V_164 -> V_152 |= V_11 -> V_179 << 4 ;
V_164 -> V_152 |= F_60 ( V_174 )
? ( V_155 << 11 )
: ( V_180 << 11 ) ;
if ( F_61 ( V_174 ) )
V_164 -> V_152 |= 1 << 15 ;
V_164 -> V_167 = F_62 ( V_11 -> V_181 ) ;
V_164 -> V_170 = V_139 -> V_170 ;
F_49 ( & V_153 -> V_159 , V_158 ) ;
F_63 ( & V_164 -> V_160 , & V_153 -> V_160 ) ;
F_64 ( & V_153 -> V_157 ) ;
F_53 ( & V_153 -> V_159 , V_158 ) ;
return 0 ;
}
static void F_65 ( struct V_1 * V_2 , bool V_182 )
{
int V_74 ;
if ( F_66 ( V_2 ) )
F_23 ( V_2 -> V_124 , L_20 ) ;
else
F_23 ( V_2 -> V_124 , L_21
L_22 ) ;
for ( V_74 = 1 ; V_74 <= V_2 -> V_4 -> V_9 ; V_74 ++ )
if ( F_67 ( V_74 , V_2 -> V_173 ) )
F_20 ( V_2 -> V_4 , V_74 , V_172 ) ;
else
F_19 ( V_2 -> V_4 , V_74 ,
V_172 ) ;
if ( V_182 )
F_68 ( F_69 ( V_2 ) ) ;
}
static int F_70 ( struct V_1 * V_2 ,
T_1 * V_85 , T_1 * V_117 )
{
int V_58 ;
F_30 ( & V_2 -> V_121 ) ;
V_58 = F_27 ( V_2 -> V_4 , & V_2 -> V_85 -> V_2 ) ;
if ( V_58 < 0 ) {
if ( V_58 != - V_123 )
F_31 ( V_2 -> V_124 ,
L_15 , V_125 , V_58 ) ;
} else {
* V_85 = F_13 ( V_2 -> V_85 -> V_2 . V_183 ) ;
* V_117 = F_13 ( V_2 -> V_85 -> V_2 . V_184 ) ;
V_58 = 0 ;
}
F_32 ( & V_2 -> V_121 ) ;
return V_58 ;
}
static int F_71 ( struct V_1 * V_2 , int V_74 ,
unsigned int V_185 )
{
return F_20 ( V_2 -> V_4 ,
V_74 | ( V_185 << 3 ) ,
V_186 ) ;
}
static void F_72 ( struct V_1 * V_2 , int V_74 )
{
F_23 ( & V_2 -> V_84 [ V_74 - 1 ] -> V_22 , L_23 ) ;
F_73 ( V_2 , V_74 , 1 ) ;
F_44 ( V_74 , V_2 -> V_187 ) ;
F_34 ( V_2 ) ;
}
int F_74 ( struct V_7 * V_11 )
{
struct V_1 * V_2 ;
struct V_130 * V_131 ;
if ( ! V_11 -> V_25 )
return - V_71 ;
V_2 = F_4 ( V_11 -> V_25 ) ;
V_131 = F_36 ( V_2 -> V_124 ) ;
F_75 ( V_131 ) ;
F_44 ( V_11 -> V_137 , V_2 -> V_188 ) ;
F_72 ( V_2 , V_11 -> V_137 ) ;
F_76 ( V_131 ) ;
return 0 ;
}
static void F_77 ( struct V_1 * V_2 , enum V_189 type )
{
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_190 * V_167 ;
int V_58 ;
int V_74 ;
int V_85 ;
bool V_191 = false ;
unsigned V_192 ;
if ( type == V_193 || type == V_194 ) {
F_78 ( & V_4 -> V_22 ) ;
if ( V_2 -> V_132 )
goto V_132;
if ( type == V_193 )
goto V_195;
goto V_196;
}
F_38 ( & V_2 -> V_134 ) ;
if ( type != V_197 ) {
if ( V_4 -> V_25 && F_3 ( V_4 ) ) {
V_58 = F_15 ( V_4 , F_18 ( V_4 , 0 ) ,
V_198 , V_66 ,
V_4 -> V_199 - 1 , 0 , NULL , 0 ,
V_200 ) ;
if ( V_58 < 0 )
F_31 ( V_2 -> V_124 ,
L_24 ) ;
}
if ( type == V_201 ) {
V_192 = F_69 ( V_2 ) ;
F_65 ( V_2 , false ) ;
F_79 ( & V_2 -> V_202 , V_203 ) ;
F_26 ( V_106 ,
& V_2 -> V_202 ,
F_80 ( V_192 ) ) ;
F_37 (
F_36 ( V_2 -> V_124 ) ) ;
return;
} else if ( type == V_204 ) {
V_167 = F_62 ( V_4 -> V_181 ) ;
if ( V_167 -> V_168 -> V_205 ) {
V_58 = V_167 -> V_168 -> V_205 ( V_167 , V_4 ,
& V_2 -> V_153 , V_206 ) ;
if ( V_58 < 0 ) {
F_31 ( V_2 -> V_124 , L_25
L_26
L_27 ) ;
F_31 ( V_2 -> V_124 , L_28
L_29
L_30 ) ;
}
}
F_65 ( V_2 , true ) ;
} else {
F_65 ( V_2 , true ) ;
}
}
V_195:
for ( V_74 = 1 ; V_74 <= V_4 -> V_9 ; ++ V_74 ) {
struct V_82 * V_83 = V_2 -> V_84 [ V_74 - 1 ] ;
struct V_7 * V_11 = V_83 -> V_207 ;
T_1 V_3 , V_208 ;
V_3 = V_208 = 0 ;
V_85 = F_33 ( V_2 , V_74 , & V_3 , & V_208 ) ;
if ( V_85 )
goto abort;
if ( V_11 || ( V_3 & V_209 ) )
F_23 ( & V_83 -> V_22 , L_31 ,
V_3 , V_208 ) ;
if ( ( V_3 & V_210 ) && (
type != V_197 ||
! ( V_3 & V_209 ) ||
! V_11 ||
V_11 -> V_92 == V_211 ) ) {
V_3 &= ~ V_210 ;
if ( ! F_3 ( V_4 ) )
F_19 ( V_4 , V_74 ,
V_212 ) ;
}
if ( V_208 & V_213 ) {
V_191 = true ;
F_19 ( V_2 -> V_4 , V_74 ,
V_214 ) ;
}
if ( V_208 & V_215 ) {
V_191 = true ;
F_19 ( V_2 -> V_4 , V_74 ,
V_216 ) ;
}
if ( V_208 & V_217 ) {
V_191 = true ;
F_19 ( V_2 -> V_4 , V_74 ,
V_218 ) ;
}
if ( ( V_208 & V_219 ) &&
F_3 ( V_2 -> V_4 ) ) {
V_191 = true ;
F_19 ( V_2 -> V_4 , V_74 ,
V_220 ) ;
}
if ( ! ( V_3 & V_209 ) ||
( V_208 & V_213 ) )
F_56 ( V_74 , V_2 -> V_188 ) ;
if ( ! V_11 || V_11 -> V_92 == V_211 ) {
if ( V_11 || ( V_3 & V_209 ) ||
( V_3 & V_221 ) )
F_44 ( V_74 , V_2 -> V_187 ) ;
} else if ( V_3 & V_210 ) {
bool V_222 = ( V_3 &
V_223 ) ==
V_224 ;
if ( V_208 || ( F_3 ( V_2 -> V_4 ) &&
V_222 ) )
F_44 ( V_74 , V_2 -> V_187 ) ;
} else if ( V_11 -> V_225 ) {
#ifdef F_81
V_11 -> V_226 = 1 ;
#endif
if ( F_67 ( V_74 , V_2 -> V_173 ) )
F_44 ( V_74 , V_2 -> V_187 ) ;
} else {
F_82 ( V_11 , V_211 ) ;
F_44 ( V_74 , V_2 -> V_187 ) ;
}
}
if ( V_191 ) {
V_192 = V_227 ;
if ( type == V_193 ) {
F_79 ( & V_2 -> V_202 , V_228 ) ;
F_26 ( V_106 ,
& V_2 -> V_202 ,
F_80 ( V_192 ) ) ;
F_83 ( & V_4 -> V_22 ) ;
return;
} else {
F_68 ( V_192 ) ;
}
}
V_196:
V_2 -> V_94 = 0 ;
V_85 = F_46 ( V_2 -> V_139 , V_206 ) ;
if ( V_85 < 0 )
F_31 ( V_2 -> V_124 , L_32 , V_85 ) ;
if ( V_2 -> V_229 && V_105 )
F_26 ( V_106 ,
& V_2 -> V_89 , V_107 ) ;
F_34 ( V_2 ) ;
abort:
if ( type == V_193 || type == V_194 ) {
V_132:
F_40 ( F_36 ( V_2 -> V_124 ) ) ;
F_83 ( & V_4 -> V_22 ) ;
}
F_41 ( & V_2 -> V_134 , V_136 ) ;
}
static void V_203 ( struct V_87 * V_230 )
{
struct V_1 * V_2 = F_25 ( V_230 , struct V_1 , V_202 . V_88 ) ;
F_77 ( V_2 , V_193 ) ;
}
static void V_228 ( struct V_87 * V_230 )
{
struct V_1 * V_2 = F_25 ( V_230 , struct V_1 , V_202 . V_88 ) ;
F_77 ( V_2 , V_194 ) ;
}
static void F_84 ( struct V_1 * V_2 , enum V_231 type )
{
struct V_7 * V_4 = V_2 -> V_4 ;
int V_57 ;
V_2 -> V_94 = 1 ;
if ( type != V_232 ) {
for ( V_57 = 0 ; V_57 < V_4 -> V_9 ; ++ V_57 ) {
if ( V_2 -> V_84 [ V_57 ] -> V_207 )
F_85 ( & V_2 -> V_84 [ V_57 ] -> V_207 ) ;
}
}
F_86 ( V_2 -> V_139 ) ;
if ( V_2 -> V_229 )
F_87 ( & V_2 -> V_89 ) ;
if ( V_2 -> V_153 . V_2 )
F_88 ( & V_2 -> V_153 . V_157 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_2 -> V_4 -> V_9 ; ++ V_57 )
F_90 ( & V_2 -> V_84 [ V_57 ] -> V_22 ) ;
}
static int F_91 ( struct V_130 * V_131 )
{
struct V_1 * V_2 = F_5 ( V_131 ) ;
F_84 ( V_2 , V_233 ) ;
V_2 -> V_234 = 1 ;
F_89 ( V_2 ) ;
return 0 ;
}
static int F_92 ( struct V_130 * V_131 )
{
struct V_1 * V_2 = F_5 ( V_131 ) ;
V_2 -> V_234 = 0 ;
F_89 ( V_2 ) ;
F_77 ( V_2 , V_235 ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_236 * V_237 )
{
struct V_190 * V_167 ;
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_238 * V_239 = V_2 -> V_124 ;
T_1 V_240 , V_241 ;
T_1 V_242 ;
unsigned int V_174 ;
int V_243 , V_58 , V_57 ;
char * V_244 = L_33 ;
unsigned V_245 ;
unsigned V_246 ;
unsigned V_9 ;
V_2 -> V_148 = F_58 ( sizeof( * V_2 -> V_148 ) , V_247 ) ;
if ( ! V_2 -> V_148 ) {
V_58 = - V_176 ;
goto V_248;
}
V_2 -> V_85 = F_58 ( sizeof( * V_2 -> V_85 ) , V_247 ) ;
if ( ! V_2 -> V_85 ) {
V_58 = - V_176 ;
goto V_248;
}
F_94 ( & V_2 -> V_121 ) ;
V_2 -> V_36 = F_95 ( sizeof( * V_2 -> V_36 ) , V_247 ) ;
if ( ! V_2 -> V_36 ) {
V_58 = - V_176 ;
goto V_248;
}
V_58 = F_14 ( V_4 , V_2 -> V_36 ) ;
if ( V_58 < 0 ) {
V_244 = L_34 ;
goto V_248;
}
V_9 = V_249 ;
if ( F_3 ( V_4 ) )
V_9 = F_96 ( unsigned , V_9 , V_250 ) ;
if ( V_2 -> V_36 -> V_69 > V_9 ) {
V_244 = L_35 ;
V_58 = - V_123 ;
goto V_248;
} else if ( V_2 -> V_36 -> V_69 == 0 ) {
V_244 = L_36 ;
V_58 = - V_123 ;
goto V_248;
}
V_9 = V_2 -> V_36 -> V_69 ;
F_8 ( V_239 , L_37 , V_9 ,
( V_9 == 1 ) ? L_38 : L_39 ) ;
V_2 -> V_84 = F_95 ( V_9 * sizeof( struct V_82 * ) , V_247 ) ;
if ( ! V_2 -> V_84 ) {
V_58 = - V_176 ;
goto V_248;
}
V_242 = F_13 ( V_2 -> V_36 -> V_242 ) ;
if ( F_3 ( V_4 ) ) {
V_245 = 150 ;
V_246 = 900 ;
} else {
V_245 = 100 ;
V_246 = 500 ;
}
if ( ( V_242 & V_251 ) &&
! ( F_3 ( V_4 ) ) ) {
char V_252 [ V_249 + 1 ] ;
for ( V_57 = 0 ; V_57 < V_9 ; V_57 ++ )
V_252 [ V_57 ] = V_2 -> V_36 -> V_37 . V_253 . V_254
[ ( ( V_57 + 1 ) / 8 ) ] & ( 1 << ( ( V_57 + 1 ) % 8 ) )
? 'F' : 'R' ;
V_252 [ V_9 ] = 0 ;
F_23 ( V_239 , L_40 , V_252 ) ;
} else
F_23 ( V_239 , L_41 ) ;
switch ( V_242 & V_255 ) {
case V_256 :
F_23 ( V_239 , L_42 ) ;
break;
case V_257 :
F_23 ( V_239 , L_43 ) ;
break;
case V_258 :
case V_255 :
F_23 ( V_239 , L_44 ) ;
break;
}
switch ( V_242 & V_259 ) {
case V_260 :
F_23 ( V_239 , L_45 ) ;
break;
case V_261 :
F_23 ( V_239 , L_46 ) ;
break;
case V_262 :
case V_259 :
F_23 ( V_239 , L_47 ) ;
break;
}
F_97 ( & V_2 -> V_153 . V_159 ) ;
F_98 ( & V_2 -> V_153 . V_160 ) ;
F_99 ( & V_2 -> V_153 . V_157 , F_48 ) ;
switch ( V_4 -> V_36 . V_263 ) {
case V_264 :
break;
case V_265 :
F_23 ( V_239 , L_48 ) ;
V_2 -> V_153 . V_2 = V_4 ;
break;
case V_266 :
V_58 = F_100 ( V_4 , 0 , 1 ) ;
if ( V_58 == 0 ) {
F_23 ( V_239 , L_49 ) ;
V_2 -> V_153 . V_177 = 1 ;
} else
F_31 ( V_239 , L_50 ,
V_58 ) ;
V_2 -> V_153 . V_2 = V_4 ;
break;
case V_267 :
break;
default:
F_23 ( V_239 , L_51 ,
V_4 -> V_36 . V_263 ) ;
break;
}
switch ( V_242 & V_268 ) {
case V_269 :
if ( V_4 -> V_36 . V_263 != 0 ) {
V_2 -> V_153 . V_270 = 666 ;
F_23 ( V_239 , L_52
L_53 ,
8 , V_2 -> V_153 . V_270 ) ;
}
break;
case V_271 :
V_2 -> V_153 . V_270 = 666 * 2 ;
F_23 ( V_239 , L_52
L_53 ,
16 , V_2 -> V_153 . V_270 ) ;
break;
case V_272 :
V_2 -> V_153 . V_270 = 666 * 3 ;
F_23 ( V_239 , L_52
L_53 ,
24 , V_2 -> V_153 . V_270 ) ;
break;
case V_273 :
V_2 -> V_153 . V_270 = 666 * 4 ;
F_23 ( V_239 , L_52
L_53 ,
32 , V_2 -> V_153 . V_270 ) ;
break;
}
if ( V_242 & V_274 ) {
V_2 -> V_229 = 1 ;
F_23 ( V_239 , L_54 ) ;
}
F_23 ( V_239 , L_55 ,
V_2 -> V_36 -> V_275 * 2 ) ;
V_58 = F_101 ( V_4 , V_276 , 0 , & V_240 ) ;
if ( V_58 ) {
V_244 = L_56 ;
goto V_248;
}
V_167 = F_62 ( V_4 -> V_181 ) ;
if ( V_4 == V_4 -> V_181 -> V_277 ) {
if ( V_167 -> V_278 > 0 )
V_4 -> V_279 = V_167 -> V_278 ;
else
V_4 -> V_279 = V_246 * V_9 ;
if ( V_4 -> V_279 >= V_246 )
V_2 -> V_280 = V_246 ;
else {
V_2 -> V_280 = V_4 -> V_279 ;
V_2 -> V_281 = 1 ;
}
} else if ( ( V_240 & ( 1 << V_282 ) ) == 0 ) {
int V_283 = V_4 -> V_279 -
V_2 -> V_36 -> V_284 ;
F_23 ( V_239 , L_57 ,
V_2 -> V_36 -> V_284 ) ;
V_2 -> V_281 = 1 ;
if ( V_283 < V_9 * V_245 )
F_102 ( V_239 ,
L_58
L_59 ) ;
V_2 -> V_280 = V_245 ;
} else {
V_2 -> V_280 = V_246 ;
}
if ( V_2 -> V_280 < V_246 )
F_23 ( V_239 , L_60 ,
V_2 -> V_280 ) ;
V_58 = F_70 ( V_2 , & V_240 , & V_241 ) ;
if ( V_58 < 0 ) {
V_244 = L_56 ;
goto V_248;
}
if ( V_4 -> V_8 -> V_56 . V_20 & V_285 )
F_23 ( V_239 , L_61 ,
( V_240 & V_286 )
? L_62 : L_63 ) ;
if ( ( V_242 & V_259 ) == 0 )
F_23 ( V_239 , L_64 ,
( V_240 & V_287 ) ? L_38 : L_65 ) ;
V_174 = F_103 ( V_4 , V_237 -> V_288 ) ;
V_243 = F_104 ( V_4 , V_174 , F_105 ( V_174 ) ) ;
if ( V_243 > sizeof( * V_2 -> V_148 ) )
V_243 = sizeof( * V_2 -> V_148 ) ;
V_2 -> V_139 = F_106 ( 0 , V_247 ) ;
if ( ! V_2 -> V_139 ) {
V_58 = - V_176 ;
goto V_248;
}
F_107 ( V_2 -> V_139 , V_4 , V_174 , * V_2 -> V_148 , V_243 , F_45 ,
V_2 , V_237 -> V_289 ) ;
if ( V_2 -> V_229 && V_105 )
V_2 -> V_96 [ 0 ] = V_97 ;
F_30 ( & V_290 ) ;
for ( V_57 = 0 ; V_57 < V_9 ; V_57 ++ ) {
V_58 = F_108 ( V_2 , V_57 + 1 ) ;
if ( V_58 < 0 ) {
F_31 ( V_2 -> V_124 ,
L_66 , V_57 + 1 ) ;
break;
}
}
V_4 -> V_9 = V_57 ;
for ( V_57 = 0 ; V_57 < V_4 -> V_9 ; V_57 ++ ) {
struct V_82 * V_83 = V_2 -> V_84 [ V_57 ] ;
F_109 ( & V_83 -> V_22 ) ;
}
F_32 ( & V_290 ) ;
if ( V_58 < 0 )
goto V_248;
if ( V_167 -> V_168 -> V_205 ) {
V_58 = V_167 -> V_168 -> V_205 ( V_167 , V_4 ,
& V_2 -> V_153 , V_247 ) ;
if ( V_58 < 0 ) {
V_244 = L_67 ;
goto V_248;
}
}
F_110 ( V_4 , V_2 -> V_36 ) ;
F_77 ( V_2 , V_201 ) ;
return 0 ;
V_248:
F_31 ( V_239 , L_68 ,
V_244 , V_58 ) ;
return V_58 ;
}
static void V_136 ( struct V_134 * V_134 )
{
struct V_1 * V_2 = F_25 ( V_134 , struct V_1 , V_134 ) ;
F_111 ( V_2 -> V_4 ) ;
F_112 ( F_36 ( V_2 -> V_124 ) ) ;
F_54 ( V_2 ) ;
}
static void F_113 ( struct V_130 * V_131 )
{
struct V_1 * V_2 = F_5 ( V_131 ) ;
struct V_7 * V_4 = F_114 ( V_131 ) ;
int V_74 ;
V_2 -> V_132 = 1 ;
V_2 -> error = 0 ;
F_84 ( V_2 , V_291 ) ;
F_30 ( & V_290 ) ;
F_115 ( & V_292 ) ;
V_74 = V_4 -> V_9 ;
V_4 -> V_9 = 0 ;
F_116 ( V_131 , NULL ) ;
F_117 ( & V_292 ) ;
for (; V_74 > 0 ; -- V_74 )
F_118 ( V_2 , V_74 ) ;
F_32 ( & V_290 ) ;
if ( V_2 -> V_4 -> V_14 == V_15 )
V_293 -- ;
F_119 ( V_2 -> V_139 ) ;
F_54 ( V_2 -> V_84 ) ;
F_54 ( V_2 -> V_36 ) ;
F_54 ( V_2 -> V_85 ) ;
F_54 ( V_2 -> V_148 ) ;
F_120 ( & V_131 -> V_22 , false ) ;
F_41 ( & V_2 -> V_134 , V_136 ) ;
}
static bool F_121 ( struct V_294 * V_56 )
{
if ( V_56 -> V_56 . V_295 != 0 &&
V_56 -> V_56 . V_295 != 1 )
return false ;
if ( V_56 -> V_56 . V_296 != 1 )
return false ;
if ( ! F_122 ( & V_56 -> V_237 [ 0 ] . V_56 ) )
return false ;
return true ;
}
static int F_123 ( struct V_130 * V_131 , const struct V_297 * V_298 )
{
struct V_294 * V_56 ;
struct V_7 * V_4 ;
struct V_1 * V_2 ;
V_56 = V_131 -> V_299 ;
V_4 = F_114 ( V_131 ) ;
#ifdef F_81
if ( V_4 -> V_22 . V_300 . V_301 >= 0 )
F_124 ( & V_4 -> V_22 , 0 ) ;
#endif
if ( V_4 -> V_25 ) {
F_125 ( V_4 ) ;
} else {
const struct V_165 * V_166 = F_62 ( V_4 -> V_181 ) -> V_168 ;
if ( V_166 -> V_302 && V_166 -> V_303 )
F_125 ( V_4 ) ;
}
if ( V_4 -> V_199 == V_304 ) {
F_31 ( & V_131 -> V_22 ,
L_69 ) ;
return - V_305 ;
}
#ifdef F_126
if ( V_4 -> V_25 ) {
F_102 ( & V_131 -> V_22 , L_70 ) ;
return - V_123 ;
}
#endif
if ( ! F_121 ( V_56 ) ) {
F_31 ( & V_131 -> V_22 , L_71 ) ;
return - V_126 ;
}
F_8 ( & V_131 -> V_22 , L_72 ) ;
V_2 = F_95 ( sizeof( * V_2 ) , V_247 ) ;
if ( ! V_2 )
return - V_176 ;
F_127 ( & V_2 -> V_134 ) ;
V_2 -> V_124 = & V_131 -> V_22 ;
V_2 -> V_4 = V_4 ;
F_79 ( & V_2 -> V_89 , F_24 ) ;
F_79 ( & V_2 -> V_202 , NULL ) ;
F_99 ( & V_2 -> V_133 , V_306 ) ;
F_128 ( V_131 ) ;
F_129 ( V_4 ) ;
F_116 ( V_131 , V_2 ) ;
V_131 -> V_307 = 1 ;
F_120 ( & V_131 -> V_22 , true ) ;
if ( V_4 -> V_14 == V_15 )
V_293 ++ ;
if ( V_298 -> V_308 & V_309 )
V_2 -> V_310 = 1 ;
if ( F_93 ( V_2 , & V_56 -> V_237 [ 0 ] . V_56 ) >= 0 )
return 0 ;
F_113 ( V_131 ) ;
return - V_123 ;
}
static int
F_130 ( struct V_130 * V_131 , unsigned int V_311 , void * V_312 )
{
struct V_7 * V_4 = F_114 ( V_131 ) ;
struct V_1 * V_2 = F_4 ( V_4 ) ;
switch ( V_311 ) {
case V_313 : {
struct V_314 * V_315 = V_312 ;
int V_57 ;
F_115 ( & V_292 ) ;
if ( V_4 -> V_179 <= 0 )
V_315 -> V_316 = 0 ;
else {
V_315 -> V_316 = V_4 -> V_9 ;
for ( V_57 = 0 ; V_57 < V_315 -> V_316 ; V_57 ++ ) {
if ( V_2 -> V_84 [ V_57 ] -> V_207 == NULL )
V_315 -> V_122 [ V_57 ] = 0 ;
else
V_315 -> V_122 [ V_57 ] =
V_2 -> V_84 [ V_57 ] -> V_207 -> V_179 ;
}
}
F_117 ( & V_292 ) ;
return V_315 -> V_316 + 1 ;
}
default:
return - V_317 ;
}
}
static int F_131 ( struct V_7 * V_4 , unsigned V_74 ,
struct V_318 * * * V_319 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
if ( V_4 -> V_92 == V_211 )
return - V_123 ;
if ( V_74 == 0 || V_74 > V_4 -> V_9 )
return - V_71 ;
* V_319 = & ( V_2 -> V_84 [ V_74 - 1 ] -> V_320 ) ;
return 0 ;
}
int F_132 ( struct V_7 * V_4 , unsigned V_74 ,
struct V_318 * V_321 )
{
int V_322 ;
struct V_318 * * V_323 ;
V_322 = F_131 ( V_4 , V_74 , & V_323 ) ;
if ( V_322 )
return V_322 ;
if ( * V_323 )
return - V_324 ;
* V_323 = V_321 ;
return V_322 ;
}
int F_133 ( struct V_7 * V_4 , unsigned V_74 ,
struct V_318 * V_321 )
{
int V_322 ;
struct V_318 * * V_323 ;
V_322 = F_131 ( V_4 , V_74 , & V_323 ) ;
if ( V_322 )
return V_322 ;
if ( * V_323 != V_321 )
return - V_142 ;
* V_323 = NULL ;
return V_322 ;
}
void F_134 ( struct V_7 * V_4 , struct V_318 * V_321 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
int V_325 ;
for ( V_325 = 0 ; V_325 < V_4 -> V_9 ; V_325 ++ ) {
if ( V_2 -> V_84 [ V_325 ] -> V_320 == V_321 )
V_2 -> V_84 [ V_325 ] -> V_320 = NULL ;
}
}
bool F_135 ( struct V_7 * V_11 )
{
struct V_1 * V_2 ;
if ( V_11 -> V_92 == V_211 || ! V_11 -> V_25 )
return false ;
V_2 = F_4 ( V_11 -> V_25 ) ;
return ! ! V_2 -> V_84 [ V_11 -> V_137 - 1 ] -> V_320 ;
}
static void F_136 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_4 ( V_11 ) ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_11 -> V_9 ; ++ V_57 ) {
if ( V_2 -> V_84 [ V_57 ] -> V_207 )
F_136 ( V_2 -> V_84 [ V_57 ] -> V_207 ) ;
}
if ( V_11 -> V_92 == V_326 )
V_11 -> V_327 -= V_328 ;
V_11 -> V_92 = V_211 ;
}
void F_82 ( struct V_7 * V_11 ,
enum V_329 V_330 )
{
unsigned long V_158 ;
int V_331 = - 1 ;
F_49 ( & V_292 , V_158 ) ;
if ( V_11 -> V_92 == V_211 )
;
else if ( V_330 != V_211 ) {
if ( V_11 -> V_25 ) {
if ( V_11 -> V_92 == V_326
|| V_330 == V_326 )
;
else if ( V_330 == V_93 )
V_331 = ( V_11 -> V_12 &
V_332 ) ? 0 :
V_11 -> V_8 -> V_56 . V_20 &
V_333 ;
else
V_331 = 0 ;
}
if ( V_11 -> V_92 == V_326 &&
V_330 != V_326 )
V_11 -> V_327 -= V_328 ;
else if ( V_330 == V_326 &&
V_11 -> V_92 != V_326 )
V_11 -> V_327 += V_328 ;
V_11 -> V_92 = V_330 ;
} else
F_136 ( V_11 ) ;
F_53 ( & V_292 , V_158 ) ;
if ( V_331 >= 0 )
F_137 ( & V_11 -> V_22 , V_331 ) ;
}
static void F_138 ( struct V_7 * V_11 )
{
int V_179 ;
struct V_334 * V_181 = V_11 -> V_181 ;
F_30 ( & V_181 -> V_335 ) ;
if ( V_11 -> V_336 ) {
V_179 = V_11 -> V_137 + 1 ;
F_139 ( F_67 ( V_179 , V_181 -> V_337 . V_338 ) ) ;
} else {
V_179 = F_140 ( V_181 -> V_337 . V_338 , 128 ,
V_181 -> V_339 ) ;
if ( V_179 >= 128 )
V_179 = F_140 ( V_181 -> V_337 . V_338 ,
128 , 1 ) ;
V_181 -> V_339 = ( V_179 >= 127 ? 1 : V_179 + 1 ) ;
}
if ( V_179 < 128 ) {
F_44 ( V_179 , V_181 -> V_337 . V_338 ) ;
V_11 -> V_179 = V_179 ;
}
F_32 ( & V_181 -> V_335 ) ;
}
static void F_141 ( struct V_7 * V_11 )
{
if ( V_11 -> V_179 > 0 ) {
F_56 ( V_11 -> V_179 , V_11 -> V_181 -> V_337 . V_338 ) ;
V_11 -> V_179 = - 1 ;
}
}
static void F_142 ( struct V_7 * V_11 , int V_179 )
{
if ( ! V_11 -> V_336 )
V_11 -> V_179 = V_179 ;
}
static void F_143 ( struct V_7 * V_11 )
{
struct V_190 * V_167 = F_62 ( V_11 -> V_181 ) ;
if ( V_167 -> V_168 -> V_340 && V_11 -> V_25 )
V_167 -> V_168 -> V_340 ( V_167 , V_11 ) ;
}
static void F_144 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_4 ( V_11 ) ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_11 -> V_9 ; V_57 ++ ) {
if ( V_2 -> V_84 [ V_57 ] -> V_207 )
F_85 ( & V_2 -> V_84 [ V_57 ] -> V_207 ) ;
}
}
void F_85 ( struct V_7 * * V_341 )
{
struct V_82 * V_83 = NULL ;
struct V_7 * V_11 = * V_341 ;
struct V_1 * V_2 = NULL ;
int V_74 = 1 ;
F_82 ( V_11 , V_211 ) ;
F_8 ( & V_11 -> V_22 , L_73 ,
V_11 -> V_179 ) ;
F_90 ( & V_11 -> V_22 ) ;
F_145 ( V_11 ) ;
F_144 ( V_11 ) ;
F_23 ( & V_11 -> V_22 , L_74 ) ;
F_146 ( V_11 , 0 ) ;
F_147 ( V_11 ) ;
if ( V_11 -> V_25 ) {
V_74 = V_11 -> V_137 ;
V_2 = F_4 ( V_11 -> V_25 ) ;
V_83 = V_2 -> V_84 [ V_74 - 1 ] ;
F_148 ( & V_11 -> V_22 . V_342 , L_75 ) ;
F_148 ( & V_83 -> V_22 . V_342 , L_76 ) ;
if ( ! F_149 ( V_74 , V_2 -> V_343 ) )
F_150 ( & V_83 -> V_22 ) ;
}
F_151 ( & V_11 -> V_344 ) ;
F_152 ( V_11 ) ;
F_153 ( & V_11 -> V_22 ) ;
F_141 ( V_11 ) ;
F_115 ( & V_292 ) ;
* V_341 = NULL ;
F_117 ( & V_292 ) ;
if ( V_83 && F_154 ( V_74 , V_2 -> V_343 ) )
F_109 ( & V_83 -> V_22 ) ;
F_143 ( V_11 ) ;
F_155 ( & V_11 -> V_22 ) ;
}
static void F_156 ( struct V_7 * V_11 , char * V_298 , char * string )
{
if ( ! string )
return;
F_8 ( & V_11 -> V_22 , L_77 , V_298 , string ) ;
}
static void F_157 ( struct V_7 * V_11 )
{
F_8 ( & V_11 -> V_22 , L_78 ,
F_13 ( V_11 -> V_36 . V_345 ) ,
F_13 ( V_11 -> V_36 . V_346 ) ) ;
F_8 ( & V_11 -> V_22 ,
L_79 ,
V_11 -> V_36 . V_347 ,
V_11 -> V_36 . V_348 ,
V_11 -> V_36 . V_349 ) ;
F_156 ( V_11 , L_80 , V_11 -> V_350 ) ;
F_156 ( V_11 , L_81 , V_11 -> V_351 ) ;
F_156 ( V_11 , L_82 , V_11 -> V_352 ) ;
}
static inline void F_157 ( struct V_7 * V_11 ) { }
static int F_158 ( struct V_7 * V_11 )
{
int V_353 = 0 ;
#ifdef F_159
if ( ! V_11 -> V_181 -> V_354
&& V_11 -> V_355
&& V_11 -> V_25 == V_11 -> V_181 -> V_277 ) {
struct V_356 * V_56 = NULL ;
struct V_334 * V_181 = V_11 -> V_181 ;
unsigned V_74 = V_11 -> V_137 ;
V_353 = F_160 ( V_11 -> V_357 [ 0 ] ,
F_13 ( V_11 -> V_355 [ 0 ] . V_56 . V_358 ) ,
V_359 , ( void * * ) & V_56 ) ;
if ( V_353 || ! ( V_56 -> V_20 & V_360 ) )
return 0 ;
F_8 ( & V_11 -> V_22 , L_83 ,
( V_74 == V_181 -> V_361 ) ? L_38 : L_84 ) ;
if ( V_74 == V_181 -> V_361 ) {
V_181 -> V_362 = 1 ;
V_353 = F_15 ( V_11 ,
F_18 ( V_11 , 0 ) ,
V_76 , 0 ,
V_363 ,
0 , NULL , 0 ,
V_200 ) ;
if ( V_353 < 0 ) {
F_31 ( & V_11 -> V_22 , L_85 ,
V_353 ) ;
V_181 -> V_362 = 0 ;
}
} else if ( V_56 -> V_364 == sizeof
( struct V_356 ) ) {
V_353 = F_15 ( V_11 ,
F_18 ( V_11 , 0 ) ,
V_76 , 0 ,
V_365 ,
0 , NULL , 0 ,
V_200 ) ;
if ( V_353 < 0 )
F_31 ( & V_11 -> V_22 ,
L_86 ,
V_353 ) ;
}
}
#endif
return V_353 ;
}
static int F_161 ( struct V_7 * V_11 )
{
int V_353 ;
struct V_190 * V_167 = F_62 ( V_11 -> V_181 ) ;
if ( V_11 -> V_355 == NULL ) {
V_353 = F_162 ( V_11 ) ;
if ( V_353 < 0 ) {
if ( V_353 != - V_123 )
F_31 ( & V_11 -> V_22 , L_87 ,
V_353 ) ;
return V_353 ;
}
}
V_11 -> V_350 = F_163 ( V_11 , V_11 -> V_36 . V_348 ) ;
V_11 -> V_351 = F_163 ( V_11 ,
V_11 -> V_36 . V_347 ) ;
V_11 -> V_352 = F_163 ( V_11 , V_11 -> V_36 . V_349 ) ;
V_353 = F_158 ( V_11 ) ;
if ( V_353 < 0 )
return V_353 ;
if ( F_164 ( V_366 ) && V_167 -> V_367 &&
! F_165 ( V_11 ) ) {
if ( F_164 ( F_159 ) && ( V_11 -> V_181 -> V_362
|| V_11 -> V_181 -> V_354 ) ) {
V_353 = F_166 ( V_11 , V_368 ) ;
if ( V_353 < 0 )
F_23 ( & V_11 -> V_22 , L_88 , V_353 ) ;
}
return - V_369 ;
}
F_167 ( V_11 ) ;
return 0 ;
}
static void F_168 ( struct V_7 * V_11 )
{
struct V_7 * V_4 = V_11 -> V_25 ;
struct V_1 * V_2 ;
T_3 V_122 = V_11 -> V_137 ;
T_1 V_242 ;
bool V_370 = true ;
if ( ! V_4 )
return;
V_2 = F_4 ( V_11 -> V_25 ) ;
switch ( V_2 -> V_84 [ V_11 -> V_137 - 1 ] -> V_371 ) {
case V_372 :
V_11 -> V_370 = V_373 ;
return;
case V_374 :
case V_375 :
V_11 -> V_370 = V_376 ;
return;
default:
break;
}
V_242 = F_13 ( V_2 -> V_36 -> V_242 ) ;
if ( ! ( V_242 & V_251 ) )
return;
if ( F_3 ( V_4 ) ) {
if ( F_13 ( V_2 -> V_36 -> V_37 . V_38 . V_254 )
& ( 1 << V_122 ) )
V_370 = false ;
} else {
if ( V_2 -> V_36 -> V_37 . V_253 . V_254 [ V_122 / 8 ] & ( 1 << ( V_122 % 8 ) ) )
V_370 = false ;
}
if ( V_370 )
V_11 -> V_370 = V_373 ;
else
V_11 -> V_370 = V_376 ;
}
int F_169 ( struct V_7 * V_11 )
{
int V_353 ;
if ( V_11 -> V_25 ) {
F_170 ( & V_11 -> V_22 , 0 ) ;
}
F_171 ( & V_11 -> V_22 ) ;
F_172 ( & V_11 -> V_22 ) ;
F_173 ( & V_11 -> V_22 ) ;
F_174 ( & V_11 -> V_22 ) ;
F_175 ( V_11 ) ;
V_353 = F_161 ( V_11 ) ;
if ( V_353 < 0 )
goto V_248;
F_23 ( & V_11 -> V_22 , L_89 ,
V_11 -> V_179 , V_11 -> V_181 -> V_377 ,
( ( ( V_11 -> V_181 -> V_377 - 1 ) * 128 ) + ( V_11 -> V_179 - 1 ) ) ) ;
V_11 -> V_22 . V_378 = F_176 ( V_379 ,
( ( ( V_11 -> V_181 -> V_377 - 1 ) * 128 ) + ( V_11 -> V_179 - 1 ) ) ) ;
F_157 ( V_11 ) ;
if ( V_11 -> V_352 )
F_177 ( V_11 -> V_352 , strlen ( V_11 -> V_352 ) ) ;
if ( V_11 -> V_350 )
F_177 ( V_11 -> V_350 , strlen ( V_11 -> V_350 ) ) ;
if ( V_11 -> V_351 )
F_177 ( V_11 -> V_351 ,
strlen ( V_11 -> V_351 ) ) ;
F_178 ( & V_11 -> V_22 ) ;
if ( V_11 -> V_25 )
F_168 ( V_11 ) ;
V_353 = F_179 ( & V_11 -> V_22 ) ;
if ( V_353 ) {
F_31 ( & V_11 -> V_22 , L_90 , V_353 ) ;
goto V_248;
}
if ( V_11 -> V_25 ) {
struct V_1 * V_2 = F_4 ( V_11 -> V_25 ) ;
int V_74 = V_11 -> V_137 ;
struct V_82 * V_83 = V_2 -> V_84 [ V_74 - 1 ] ;
V_353 = F_180 ( & V_11 -> V_22 . V_342 ,
& V_83 -> V_22 . V_342 , L_75 ) ;
if ( V_353 )
goto V_248;
V_353 = F_180 ( & V_83 -> V_22 . V_342 ,
& V_11 -> V_22 . V_342 , L_76 ) ;
if ( V_353 ) {
F_148 ( & V_11 -> V_22 . V_342 , L_75 ) ;
goto V_248;
}
if ( ! F_149 ( V_74 , V_2 -> V_343 ) )
F_150 ( & V_83 -> V_22 ) ;
}
( void ) F_181 ( & V_11 -> V_22 , & V_11 -> V_344 , V_11 ) ;
F_182 ( V_11 ) ;
F_183 ( & V_11 -> V_22 ) ;
return V_353 ;
V_248:
F_82 ( V_11 , V_211 ) ;
F_184 ( & V_11 -> V_22 ) ;
F_185 ( & V_11 -> V_22 ) ;
return V_353 ;
}
int F_186 ( struct V_7 * V_380 )
{
F_145 ( V_380 ) ;
if ( V_380 -> V_381 == 0 )
goto V_382;
V_380 -> V_381 = 0 ;
F_187 ( V_380 , - 1 ) ;
V_382:
F_152 ( V_380 ) ;
return 0 ;
}
int F_188 ( struct V_7 * V_380 )
{
int V_383 = 0 , V_384 ;
F_145 ( V_380 ) ;
if ( V_380 -> V_381 == 1 )
goto V_385;
V_383 = F_189 ( V_380 ) ;
if ( V_383 < 0 ) {
F_31 ( & V_380 -> V_22 ,
L_91 , V_383 ) ;
goto V_386;
}
if ( V_380 -> V_336 ) {
V_383 = F_190 ( V_380 , sizeof( V_380 -> V_36 ) ) ;
if ( V_383 < 0 ) {
F_31 ( & V_380 -> V_22 , L_92
L_93 , V_383 ) ;
goto V_387;
}
}
V_380 -> V_381 = 1 ;
V_384 = F_191 ( V_380 ) ;
if ( V_384 >= 0 ) {
V_383 = F_187 ( V_380 , V_384 ) ;
if ( V_383 ) {
F_31 ( & V_380 -> V_22 ,
L_94 , V_384 , V_383 ) ;
}
}
F_8 ( & V_380 -> V_22 , L_95 ) ;
V_387:
F_192 ( V_380 ) ;
V_386:
V_385:
F_152 ( V_380 ) ;
return V_383 ;
}
static int F_193 ( struct V_7 * V_4 , int V_388 )
{
int V_389 ;
T_2 V_390 ;
int V_57 ;
struct V_391 * V_392 = V_4 -> V_17 -> V_392 ;
if ( ! V_392 )
return 0 ;
V_389 = F_7 ( V_392 -> V_20 ) &
V_393 ;
for ( V_57 = 0 ; V_57 <= V_389 ; V_57 ++ ) {
V_390 = F_7 ( V_392 -> V_394 [ V_57 ] ) ;
if ( V_388 == ( V_390 & V_395 ) )
return ! ! ( V_390 & V_396 ) ;
}
return 0 ;
}
static unsigned F_194 ( struct V_1 * V_2 )
{
struct V_190 * V_167 ;
if ( V_2 -> V_4 -> V_25 != NULL )
return 0 ;
V_167 = F_62 ( V_2 -> V_4 -> V_181 ) ;
return V_167 -> V_397 ;
}
static bool F_195 ( struct V_7 * V_11 , int V_398 )
{
if ( V_11 -> V_14 >= V_52 )
return false ;
return F_196 ( V_398 ) ;
}
static bool F_197 ( struct V_1 * V_2 , int V_74 ,
T_1 V_3 )
{
T_1 V_399 ;
if ( ! F_3 ( V_2 -> V_4 ) )
return false ;
if ( F_67 ( V_74 , V_2 -> V_400 ) )
return true ;
V_399 = V_3 & V_223 ;
return V_399 == V_401
|| V_399 == V_402 ;
}
static int F_198 ( struct V_1 * V_2 , int V_74 ,
struct V_7 * V_11 , unsigned int V_192 , bool V_403 )
{
int V_404 , V_58 ;
T_1 V_3 ;
T_1 V_208 ;
T_2 V_405 = 0 ;
for ( V_404 = 0 ;
V_404 < V_406 ;
V_404 += V_192 ) {
F_68 ( V_192 ) ;
if ( F_2 ( V_2 -> V_4 ) )
V_58 = F_29 ( V_2 , V_74 ,
V_407 ,
& V_3 , & V_208 ,
& V_405 ) ;
else
V_58 = F_33 ( V_2 , V_74 , & V_3 ,
& V_208 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( ! ( V_3 & V_408 ) &&
( V_3 & V_209 ) )
break;
if ( V_404 >= 2 * V_409 )
V_192 = V_410 ;
F_23 ( & V_2 -> V_84 [ V_74 - 1 ] -> V_22 ,
L_96 ,
V_403 ? L_97 : L_38 , V_192 ) ;
}
if ( ( V_3 & V_408 ) )
return - V_324 ;
if ( F_197 ( V_2 , V_74 , V_3 ) )
return - V_411 ;
if ( ! ( V_3 & V_209 ) )
return - V_411 ;
if ( ! F_3 ( V_2 -> V_4 ) &&
( V_208 & V_213 ) ) {
F_19 ( V_2 -> V_4 , V_74 ,
V_214 ) ;
return - V_412 ;
}
if ( ! ( V_3 & V_210 ) )
return - V_324 ;
if ( ! V_11 )
return 0 ;
if ( F_194 ( V_2 ) )
V_11 -> V_14 = V_413 ;
else if ( F_2 ( V_2 -> V_4 ) &&
F_193 ( V_2 -> V_4 , V_405 &
V_414 ) )
V_11 -> V_14 = V_415 ;
else if ( F_3 ( V_2 -> V_4 ) )
V_11 -> V_14 = V_52 ;
else if ( V_3 & V_5 )
V_11 -> V_14 = V_15 ;
else if ( V_3 & V_6 )
V_11 -> V_14 = V_416 ;
else
V_11 -> V_14 = V_16 ;
return 0 ;
}
static int F_199 ( struct V_1 * V_2 , int V_74 ,
struct V_7 * V_11 , unsigned int V_192 , bool V_403 )
{
int V_57 , V_85 ;
T_1 V_208 , V_3 ;
struct V_82 * V_83 = V_2 -> V_84 [ V_74 - 1 ] ;
if ( ! F_3 ( V_2 -> V_4 ) ) {
if ( V_403 ) {
F_31 ( V_2 -> V_124 , L_98
L_99 ) ;
return - V_71 ;
}
F_200 ( & V_417 ) ;
} else if ( ! V_403 ) {
if ( F_33 ( V_2 , V_74 , & V_3 , & V_208 ) == 0 )
if ( F_197 ( V_2 , V_74 ,
V_3 ) )
V_403 = true ;
}
F_56 ( V_74 , V_2 -> V_400 ) ;
for ( V_57 = 0 ; V_57 < V_418 ; V_57 ++ ) {
V_85 = F_20 ( V_2 -> V_4 , V_74 , ( V_403 ?
V_419 :
V_420 ) ) ;
if ( V_85 == - V_123 ) {
;
} else if ( V_85 ) {
F_31 ( & V_83 -> V_22 ,
L_100 ,
V_403 ? L_97 : L_38 , V_85 ) ;
} else {
V_85 = F_198 ( V_2 , V_74 , V_11 , V_192 ,
V_403 ) ;
if ( V_85 && V_85 != - V_411 && V_85 != - V_123 )
F_23 ( V_2 -> V_124 ,
L_101 ,
V_85 ) ;
}
if ( V_85 == 0 || V_85 == - V_411 || V_85 == - V_123 ) {
F_19 ( V_2 -> V_4 , V_74 ,
V_218 ) ;
if ( ! F_3 ( V_2 -> V_4 ) )
goto V_421;
F_19 ( V_2 -> V_4 , V_74 ,
V_220 ) ;
F_19 ( V_2 -> V_4 , V_74 ,
V_422 ) ;
F_19 ( V_2 -> V_4 , V_74 ,
V_214 ) ;
if ( F_33 ( V_2 , V_74 ,
& V_3 , & V_208 ) < 0 )
goto V_421;
if ( ! F_197 ( V_2 , V_74 ,
V_3 ) )
goto V_421;
if ( ! V_403 ) {
F_23 ( & V_83 -> V_22 ,
L_102 ) ;
V_403 = true ;
}
}
F_23 ( & V_83 -> V_22 ,
L_103 ,
V_403 ? L_97 : L_38 ) ;
V_192 = V_410 ;
}
F_31 ( & V_83 -> V_22 , L_104 ) ;
V_421:
if ( V_85 == 0 ) {
F_68 ( 10 + 40 ) ;
if ( V_11 ) {
struct V_190 * V_167 = F_62 ( V_11 -> V_181 ) ;
F_142 ( V_11 , 0 ) ;
if ( V_167 -> V_168 -> V_423 )
V_167 -> V_168 -> V_423 ( V_167 , V_11 ) ;
F_82 ( V_11 , V_424 ) ;
}
} else {
if ( V_11 )
F_82 ( V_11 , V_211 ) ;
}
if ( ! F_3 ( V_2 -> V_4 ) )
F_201 ( & V_417 ) ;
return V_85 ;
}
static int F_202 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_58 = 0 ;
if ( F_3 ( V_2 -> V_4 ) ) {
if ( V_3 & V_425 )
V_58 = 1 ;
} else {
if ( V_3 & V_426 )
V_58 = 1 ;
}
return V_58 ;
}
static void F_203 ( struct V_82 * V_83 )
__acquires( &port_dev->status_lock
static void F_204 ( struct V_82 * V_83 )
__releases( &port_dev->status_lock
static int F_205 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_58 = 0 ;
if ( F_3 ( V_2 -> V_4 ) ) {
if ( ( V_3 & V_223 )
== V_427 )
V_58 = 1 ;
} else {
if ( V_3 & V_428 )
V_58 = 1 ;
}
return V_58 ;
}
static int F_206 ( struct V_7 * V_11 ,
struct V_1 * V_2 , int V_74 ,
int V_85 , T_1 V_208 , T_1 V_3 )
{
struct V_82 * V_83 = V_2 -> V_84 [ V_74 - 1 ] ;
int V_429 = 3 ;
V_398:
if ( V_85 == 0 && V_11 -> V_226
&& F_197 ( V_2 , V_74 , V_3 ) ) {
;
}
else if ( V_85 || F_205 ( V_2 , V_3 ) ||
! F_202 ( V_2 , V_3 ) ) {
if ( V_85 >= 0 )
V_85 = - V_123 ;
} else if ( ! ( V_3 & V_209 ) ) {
if ( V_429 -- ) {
F_207 ( 200 , 300 ) ;
V_85 = F_33 ( V_2 , V_74 , & V_3 ,
& V_208 ) ;
goto V_398;
}
V_85 = - V_123 ;
}
else if ( ! ( V_3 & V_210 ) && ! V_11 -> V_226 ) {
if ( V_11 -> V_225 )
V_11 -> V_226 = 1 ;
else
V_85 = - V_123 ;
}
if ( V_85 ) {
F_23 ( & V_83 -> V_22 , L_105 ,
V_208 , V_3 , V_85 ) ;
} else if ( V_11 -> V_226 ) {
if ( V_208 & V_213 )
F_19 ( V_2 -> V_4 , V_74 ,
V_214 ) ;
if ( V_208 & V_215 )
F_19 ( V_2 -> V_4 , V_74 ,
V_216 ) ;
}
return V_85 ;
}
int F_208 ( struct V_7 * V_11 )
{
struct V_190 * V_167 = F_62 ( V_11 -> V_181 ) ;
if ( ! F_209 ( V_167 -> V_430 . V_277 ) ||
! F_209 ( V_11 ) )
return 0 ;
if ( ! V_11 -> V_8 )
return 0 ;
return F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_73 , V_276 ,
V_431 , 0 , NULL , 0 ,
V_200 ) ;
}
void F_210 ( struct V_7 * V_11 )
{
struct V_190 * V_167 = F_62 ( V_11 -> V_181 ) ;
if ( ! F_209 ( V_167 -> V_430 . V_277 ) ||
! F_209 ( V_11 ) )
return;
if ( ! V_11 -> V_8 )
return;
F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_76 , V_276 ,
V_431 , 0 , NULL , 0 ,
V_200 ) ;
}
static int F_211 ( struct V_7 * V_11 )
{
if ( V_11 -> V_14 < V_52 )
return F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_76 , V_276 ,
V_432 , 0 , NULL , 0 ,
V_200 ) ;
else
return F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_76 , V_433 ,
V_434 ,
V_435 |
V_436 ,
NULL , 0 , V_200 ) ;
}
static int F_212 ( struct V_7 * V_11 )
{
if ( V_11 -> V_14 < V_52 )
return F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_73 , V_276 ,
V_432 , 0 , NULL , 0 ,
V_200 ) ;
else
return F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_76 , V_433 ,
V_434 , 0 , NULL , 0 ,
V_200 ) ;
}
static unsigned F_213 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_4 ( V_11 ) ;
return V_11 -> V_437 +
( V_2 ? V_2 -> F_213 : 0 ) ;
}
int F_166 ( struct V_7 * V_11 , T_4 V_438 )
{
struct V_1 * V_2 = F_4 ( V_11 -> V_25 ) ;
struct V_82 * V_83 = V_2 -> V_84 [ V_11 -> V_137 - 1 ] ;
int V_74 = V_11 -> V_137 ;
int V_85 ;
bool V_439 = true ;
F_203 ( V_83 ) ;
if ( V_11 -> V_437 ) {
V_85 = F_211 ( V_11 ) ;
if ( V_85 ) {
F_23 ( & V_11 -> V_22 , L_106 ,
V_85 ) ;
if ( F_214 ( V_438 ) )
goto V_440;
}
}
if ( V_11 -> V_441 == 1 )
F_215 ( V_11 , 0 ) ;
if ( F_208 ( V_11 ) ) {
F_31 ( & V_11 -> V_22 , L_107 ) ;
V_85 = - V_176 ;
if ( F_214 ( V_438 ) )
goto V_442;
}
if ( F_3 ( V_2 -> V_4 ) )
V_85 = F_71 ( V_2 , V_74 , V_427 ) ;
else if ( F_214 ( V_438 ) || F_213 ( V_11 ) > 0 )
V_85 = F_20 ( V_2 -> V_4 , V_74 ,
V_443 ) ;
else {
V_439 = false ;
V_85 = 0 ;
}
if ( V_85 ) {
F_23 ( & V_83 -> V_22 , L_108 , V_85 ) ;
F_210 ( V_11 ) ;
V_442:
if ( V_11 -> V_444 == 1 )
F_215 ( V_11 , 1 ) ;
if ( V_11 -> V_437 )
( void ) F_212 ( V_11 ) ;
V_440:
if ( ! F_214 ( V_438 ) )
V_85 = 0 ;
} else {
F_23 ( & V_11 -> V_22 , L_109 ,
( F_214 ( V_438 ) ? L_110 : L_38 ) ,
V_11 -> V_437 ) ;
if ( V_439 ) {
V_11 -> F_205 = 1 ;
F_68 ( 10 ) ;
}
F_82 ( V_11 , V_326 ) ;
}
if ( V_85 == 0 && ! V_11 -> V_437 && V_11 -> V_225
&& F_154 ( V_74 , V_2 -> V_343 ) )
F_216 ( & V_83 -> V_22 ) ;
F_182 ( V_2 -> V_4 ) ;
F_204 ( V_83 ) ;
return V_85 ;
}
static int F_217 ( struct V_7 * V_11 )
{
int V_85 = 0 ;
T_1 V_445 = 0 ;
F_23 ( & V_11 -> V_22 , L_111 ,
V_11 -> V_226 ? L_112 : L_113 ) ;
F_82 ( V_11 , V_11 -> V_8
? V_93
: V_446 ) ;
if ( V_11 -> V_226 ) {
V_447:
if ( V_11 -> V_12 & V_448 )
V_85 = - V_123 ;
else
V_85 = F_218 ( V_11 ) ;
}
if ( V_85 == 0 ) {
V_445 = 0 ;
V_85 = F_101 ( V_11 , V_276 , 0 , & V_445 ) ;
if ( V_85 && ! V_11 -> V_226 && V_11 -> V_225 ) {
F_23 ( & V_11 -> V_22 , L_114 ) ;
V_11 -> V_226 = 1 ;
goto V_447;
}
}
if ( V_85 ) {
F_23 ( & V_11 -> V_22 , L_115 ,
V_85 ) ;
} else if ( V_11 -> V_8 && ! V_11 -> V_226 ) {
if ( V_11 -> V_14 < V_52 ) {
if ( V_445 & ( 1 << V_432 ) )
V_85 = F_212 ( V_11 ) ;
} else {
V_85 = F_101 ( V_11 , V_433 , 0 ,
& V_445 ) ;
if ( ! V_85 && V_445 & ( V_449
| V_450 ) )
V_85 = F_212 ( V_11 ) ;
}
if ( V_85 )
F_23 ( & V_11 -> V_22 ,
L_116 ,
V_85 ) ;
V_85 = 0 ;
}
return V_85 ;
}
static int F_219 ( struct V_7 * V_11 ,
struct V_1 * V_2 , int * V_74 ,
T_1 * V_208 , T_1 * V_3 )
{
int V_85 = 0 , V_451 = 0 ;
while ( V_451 < 2000 ) {
if ( V_85 || * V_3 & V_209 )
break;
F_68 ( 20 ) ;
V_451 += 20 ;
V_85 = F_33 ( V_2 , * V_74 , V_3 , V_208 ) ;
}
F_23 ( & V_11 -> V_22 , L_117 , V_451 ) ;
return V_85 ;
}
int F_220 ( struct V_7 * V_11 , T_4 V_438 )
{
struct V_1 * V_2 = F_4 ( V_11 -> V_25 ) ;
struct V_82 * V_83 = V_2 -> V_84 [ V_11 -> V_137 - 1 ] ;
int V_74 = V_11 -> V_137 ;
int V_85 ;
T_1 V_208 , V_3 ;
if ( ! F_149 ( V_74 , V_2 -> V_343 ) ) {
V_85 = F_150 ( & V_83 -> V_22 ) ;
if ( V_85 < 0 ) {
F_23 ( & V_11 -> V_22 , L_118 ,
V_85 ) ;
return V_85 ;
}
}
F_203 ( V_83 ) ;
V_85 = F_33 ( V_2 , V_74 , & V_3 , & V_208 ) ;
if ( V_85 == 0 && ! F_205 ( V_2 , V_3 ) )
goto V_452;
if ( F_3 ( V_2 -> V_4 ) )
V_85 = F_71 ( V_2 , V_74 , V_224 ) ;
else
V_85 = F_19 ( V_2 -> V_4 ,
V_74 , V_443 ) ;
if ( V_85 ) {
F_23 ( & V_83 -> V_22 , L_119 , V_85 ) ;
} else {
F_23 ( & V_11 -> V_22 , L_120 ,
( F_214 ( V_438 ) ? L_110 : L_38 ) ) ;
F_68 ( V_453 ) ;
V_85 = F_33 ( V_2 , V_74 , & V_3 , & V_208 ) ;
F_68 ( 10 ) ;
}
V_452:
if ( V_85 == 0 ) {
V_11 -> F_205 = 0 ;
if ( F_3 ( V_2 -> V_4 ) ) {
if ( V_208 & V_454 )
F_19 ( V_2 -> V_4 , V_74 ,
V_422 ) ;
} else {
if ( V_208 & V_455 )
F_19 ( V_2 -> V_4 , V_74 ,
V_456 ) ;
}
}
if ( V_11 -> V_225 )
V_85 = F_219 ( V_11 , V_2 , & V_74 , & V_208 ,
& V_3 ) ;
V_85 = F_206 ( V_11 ,
V_2 , V_74 , V_85 , V_208 , V_3 ) ;
if ( V_85 == 0 )
V_85 = F_217 ( V_11 ) ;
if ( V_85 < 0 ) {
F_23 ( & V_11 -> V_22 , L_119 , V_85 ) ;
F_72 ( V_2 , V_74 ) ;
} else {
if ( V_11 -> V_444 == 1 )
F_215 ( V_11 , 1 ) ;
F_210 ( V_11 ) ;
}
F_204 ( V_83 ) ;
return V_85 ;
}
int F_221 ( struct V_7 * V_11 )
{
int V_85 = 0 ;
F_145 ( V_11 ) ;
if ( V_11 -> V_92 == V_326 ) {
F_23 ( & V_11 -> V_22 , L_120 , L_121 ) ;
V_85 = F_189 ( V_11 ) ;
if ( V_85 == 0 ) {
F_192 ( V_11 ) ;
}
}
F_152 ( V_11 ) ;
return V_85 ;
}
static int F_222 ( struct V_1 * V_2 , unsigned int V_122 ,
T_1 V_3 , T_1 V_208 )
__must_hold( &port_dev->status_lock
static int F_223 ( struct V_1 * V_2 )
{
int V_74 ;
for ( V_74 = 1 ; V_74 <= V_2 -> V_4 -> V_9 ; ++ V_74 ) {
T_1 V_3 , V_208 ;
int V_85 ;
V_85 = F_33 ( V_2 , V_74 , & V_3 , & V_208 ) ;
if ( ! V_85 && V_208 )
return 1 ;
}
return 0 ;
}
static int F_224 ( struct V_130 * V_131 , T_4 V_438 )
{
struct V_1 * V_2 = F_5 ( V_131 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
unsigned V_74 ;
int V_85 ;
V_2 -> F_213 = 0 ;
for ( V_74 = 1 ; V_74 <= V_4 -> V_9 ; V_74 ++ ) {
struct V_82 * V_83 = V_2 -> V_84 [ V_74 - 1 ] ;
struct V_7 * V_11 = V_83 -> V_207 ;
if ( V_11 && V_11 -> V_457 ) {
F_102 ( & V_83 -> V_22 , L_122 ,
F_225 ( & V_11 -> V_22 ) ) ;
if ( F_214 ( V_438 ) )
return - V_324 ;
}
if ( V_11 )
V_2 -> F_213 +=
F_213 ( V_11 ) ;
}
if ( V_4 -> V_437 && V_2 -> V_310 ) {
if ( F_223 ( V_2 ) ) {
if ( F_214 ( V_438 ) )
return - V_324 ;
F_226 ( & V_4 -> V_22 , 2000 ) ;
}
}
if ( F_3 ( V_4 ) && V_4 -> V_437 ) {
for ( V_74 = 1 ; V_74 <= V_4 -> V_9 ; V_74 ++ ) {
V_85 = F_20 ( V_4 ,
V_74 |
V_458 |
V_459 |
V_460 ,
V_461 ) ;
}
}
F_23 ( & V_131 -> V_22 , L_111 , V_125 ) ;
F_84 ( V_2 , V_232 ) ;
return 0 ;
}
static int F_227 ( struct V_130 * V_131 )
{
struct V_1 * V_2 = F_5 ( V_131 ) ;
F_23 ( & V_131 -> V_22 , L_111 , V_125 ) ;
F_77 ( V_2 , V_197 ) ;
return 0 ;
}
static int F_228 ( struct V_130 * V_131 )
{
struct V_1 * V_2 = F_5 ( V_131 ) ;
F_23 ( & V_131 -> V_22 , L_111 , V_125 ) ;
F_77 ( V_2 , V_204 ) ;
return 0 ;
}
void F_229 ( struct V_7 * V_462 )
{
F_102 ( & V_462 -> V_22 , L_123 ) ;
V_462 -> V_226 = 1 ;
}
static int F_230 ( struct V_7 * V_11 , enum V_463 V_92 )
{
struct V_464 * V_465 ;
unsigned long long V_466 ;
unsigned long long V_467 ;
unsigned long long V_468 ;
unsigned long long V_469 ;
int V_58 ;
if ( V_11 -> V_92 != V_93 )
return 0 ;
V_466 = F_231 ( V_11 -> V_53 . V_46 , 1000 ) ;
V_467 = F_231 ( V_11 -> V_53 . V_43 , 1000 ) ;
V_468 = F_231 ( V_11 -> V_54 . V_46 , 1000 ) ;
V_469 = F_231 ( V_11 -> V_54 . V_43 , 1000 ) ;
if ( ( V_92 == V_470 &&
( V_466 > V_471 ||
V_467 > V_471 ) ) ||
( V_92 == V_472 &&
( V_468 > V_473 ||
V_469 > V_473 ) ) ) {
F_23 ( & V_11 -> V_22 , L_124 ,
V_474 [ V_92 ] , V_466 , V_467 ) ;
return - V_71 ;
}
if ( V_466 > V_471 )
V_466 = V_471 ;
if ( V_467 > V_471 )
V_467 = V_471 ;
if ( V_468 > V_473 )
V_468 = V_473 ;
if ( V_469 > V_473 )
V_469 = V_473 ;
V_465 = F_58 ( sizeof *( V_465 ) , V_206 ) ;
if ( ! V_465 )
return - V_176 ;
V_465 -> V_466 = V_466 ;
V_465 -> V_467 = V_467 ;
V_465 -> V_468 = F_232 ( V_468 ) ;
V_465 -> V_469 = F_232 ( V_469 ) ;
V_58 = F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_475 ,
V_276 ,
0 , 0 ,
V_465 , sizeof *( V_465 ) ,
V_200 ) ;
F_54 ( V_465 ) ;
return V_58 ;
}
static int F_233 ( struct V_7 * V_11 ,
enum V_463 V_92 , bool V_476 )
{
int V_58 ;
int V_72 ;
switch ( V_92 ) {
case V_470 :
V_72 = V_477 ;
break;
case V_472 :
V_72 = V_478 ;
break;
default:
F_102 ( & V_11 -> V_22 , L_125 ,
V_125 , V_476 ? L_126 : L_127 ) ;
return - V_71 ;
}
if ( V_11 -> V_92 != V_93 ) {
F_23 ( & V_11 -> V_22 , L_128
L_129 ,
V_125 , V_476 ? L_126 : L_127 ,
V_474 [ V_92 ] ) ;
return 0 ;
}
if ( V_476 ) {
V_58 = F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_76 ,
V_276 ,
V_72 ,
0 , NULL , 0 ,
V_200 ) ;
} else {
V_58 = F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_73 ,
V_276 ,
V_72 ,
0 , NULL , 0 ,
V_200 ) ;
}
if ( V_58 < 0 ) {
F_102 ( & V_11 -> V_22 , L_130 ,
V_476 ? L_131 : L_132 ,
V_474 [ V_92 ] ) ;
return - V_324 ;
}
return 0 ;
}
static int F_234 ( struct V_7 * V_11 ,
enum V_463 V_92 , int V_479 )
{
int V_58 ;
int V_72 ;
switch ( V_92 ) {
case V_470 :
V_72 = V_480 ;
break;
case V_472 :
V_72 = V_481 ;
break;
default:
F_102 ( & V_11 -> V_22 , L_133 ,
V_125 ) ;
return - V_71 ;
}
if ( V_92 == V_470 && V_479 > V_482 &&
V_479 != V_483 ) {
F_102 ( & V_11 -> V_22 , L_134
L_135 ,
V_474 [ V_92 ] , V_479 ) ;
return - V_71 ;
}
V_58 = F_20 ( V_11 -> V_25 ,
F_235 ( V_479 ) | V_11 -> V_137 ,
V_72 ) ;
if ( V_58 < 0 ) {
F_102 ( & V_11 -> V_22 , L_136
L_137 , V_474 [ V_92 ] ,
V_479 , V_58 ) ;
return - V_324 ;
}
if ( V_92 == V_470 )
V_11 -> V_53 . V_479 = V_479 ;
else
V_11 -> V_54 . V_479 = V_479 ;
return 0 ;
}
static void F_236 ( struct V_190 * V_167 , struct V_7 * V_11 ,
enum V_463 V_92 )
{
int V_479 , V_58 ;
T_5 V_484 = V_11 -> V_17 -> V_21 -> V_23 ;
T_6 V_485 = V_11 -> V_17 -> V_21 -> V_24 ;
if ( ( V_92 == V_470 && V_484 == 0 ) ||
( V_92 == V_472 && V_485 == 0 ) )
return;
V_58 = F_230 ( V_11 , V_92 ) ;
if ( V_58 < 0 ) {
F_102 ( & V_11 -> V_22 , L_138 ,
V_474 [ V_92 ] ) ;
return;
}
V_479 = V_167 -> V_168 -> V_486 ( V_167 , V_11 , V_92 ) ;
if ( V_479 == 0 )
return;
if ( V_479 < 0 ) {
F_102 ( & V_11 -> V_22 , L_139
L_140 , V_474 [ V_92 ] ,
V_479 ) ;
return;
}
if ( F_234 ( V_11 , V_92 , V_479 ) ) {
V_167 -> V_168 -> V_487 ( V_167 , V_11 , V_92 ) ;
} else {
if ( V_11 -> V_8 )
F_233 ( V_11 , V_92 , true ) ;
if ( V_92 == V_470 )
V_11 -> V_488 = 1 ;
else if ( V_92 == V_472 )
V_11 -> V_489 = 1 ;
}
}
static int F_237 ( struct V_190 * V_167 , struct V_7 * V_11 ,
enum V_463 V_92 )
{
switch ( V_92 ) {
case V_470 :
case V_472 :
break;
default:
F_102 ( & V_11 -> V_22 , L_141 ,
V_125 ) ;
return - V_71 ;
}
if ( F_234 ( V_11 , V_92 , 0 ) )
return - V_324 ;
F_233 ( V_11 , V_92 , false ) ;
if ( V_167 -> V_168 -> V_487 ( V_167 , V_11 , V_92 ) )
F_102 ( & V_11 -> V_22 , L_142
L_143 ,
V_474 [ V_92 ] ) ;
if ( V_92 == V_470 )
V_11 -> V_488 = 0 ;
else if ( V_92 == V_472 )
V_11 -> V_489 = 0 ;
return 0 ;
}
int F_238 ( struct V_7 * V_11 )
{
struct V_190 * V_167 ;
if ( ! V_11 || ! V_11 -> V_25 ||
V_11 -> V_14 < V_52 ||
! V_11 -> V_26 ||
V_11 -> V_92 < V_424 )
return 0 ;
V_167 = F_62 ( V_11 -> V_181 ) ;
if ( ! V_167 || ! V_167 -> V_168 -> V_487 )
return 0 ;
V_11 -> V_490 ++ ;
if ( ( V_11 -> V_53 . V_479 == 0 && V_11 -> V_54 . V_479 == 0 ) )
return 0 ;
if ( F_237 ( V_167 , V_11 , V_470 ) )
goto V_491;
if ( F_237 ( V_167 , V_11 , V_472 ) )
goto V_491;
return 0 ;
V_491:
F_239 ( V_11 ) ;
return - V_324 ;
}
int F_240 ( struct V_7 * V_11 )
{
struct V_190 * V_167 = F_62 ( V_11 -> V_181 ) ;
int V_58 ;
if ( ! V_167 )
return - V_71 ;
F_30 ( V_167 -> V_492 ) ;
V_58 = F_238 ( V_11 ) ;
F_32 ( V_167 -> V_492 ) ;
return V_58 ;
}
void F_239 ( struct V_7 * V_11 )
{
struct V_190 * V_167 ;
struct V_1 * V_2 ;
struct V_82 * V_83 ;
if ( ! V_11 || ! V_11 -> V_25 ||
V_11 -> V_14 < V_52 ||
! V_11 -> V_26 ||
V_11 -> V_92 < V_424 )
return;
V_11 -> V_490 -- ;
V_167 = F_62 ( V_11 -> V_181 ) ;
if ( ! V_167 || ! V_167 -> V_168 -> V_486 ||
! V_167 -> V_168 -> V_487 )
return;
if ( V_11 -> V_490 > 0 )
return;
V_2 = F_4 ( V_11 -> V_25 ) ;
if ( ! V_2 )
return;
V_83 = V_2 -> V_84 [ V_11 -> V_137 - 1 ] ;
if ( V_83 -> V_493 )
F_236 ( V_167 , V_11 , V_470 ) ;
if ( V_83 -> V_494 )
F_236 ( V_167 , V_11 , V_472 ) ;
}
void F_241 ( struct V_7 * V_11 )
{
struct V_190 * V_167 = F_62 ( V_11 -> V_181 ) ;
if ( ! V_167 )
return;
F_30 ( V_167 -> V_492 ) ;
F_239 ( V_11 ) ;
F_32 ( V_167 -> V_492 ) ;
}
static void F_242 ( struct V_1 * V_2 ,
struct V_82 * V_83 )
{
struct V_7 * V_11 = V_83 -> V_207 ;
int V_58 ;
if ( V_11 && V_11 -> F_205 && V_11 -> V_437 ) {
V_58 = F_71 ( V_2 , V_83 -> V_137 ,
V_224 ) ;
if ( ! V_58 ) {
F_68 ( V_453 ) ;
V_58 = F_212 ( V_11 ) ;
}
if ( V_58 )
F_102 ( & V_11 -> V_22 ,
L_144 ) ;
V_11 -> V_437 = 0 ;
}
}
static inline void F_242 ( struct V_1 * V_2 ,
struct V_82 * V_83 ) { }
int F_238 ( struct V_7 * V_11 )
{
return 0 ;
}
void F_239 ( struct V_7 * V_11 ) { }
int F_240 ( struct V_7 * V_11 )
{
return 0 ;
}
void F_241 ( struct V_7 * V_11 ) { }
int F_208 ( struct V_7 * V_11 )
{
return 0 ;
}
void F_210 ( struct V_7 * V_11 ) { }
static int F_222 ( struct V_1 * V_2 , unsigned int V_122 ,
T_1 V_3 , T_1 V_208 )
{
return 0 ;
}
static int F_73 ( struct V_1 * V_2 , int V_74 , int V_495 )
{
struct V_82 * V_83 = V_2 -> V_84 [ V_74 - 1 ] ;
struct V_7 * V_4 = V_2 -> V_4 ;
int V_58 = 0 ;
if ( ! V_2 -> error ) {
if ( F_3 ( V_2 -> V_4 ) ) {
F_242 ( V_2 , V_83 ) ;
V_58 = F_71 ( V_2 , V_83 -> V_137 ,
V_427 ) ;
} else {
V_58 = F_19 ( V_4 , V_74 ,
V_212 ) ;
}
}
if ( V_83 -> V_207 && V_495 )
F_82 ( V_83 -> V_207 , V_211 ) ;
if ( V_58 && V_58 != - V_123 )
F_31 ( & V_83 -> V_22 , L_145 , V_58 ) ;
return V_58 ;
}
int F_243 ( struct V_1 * V_2 , int V_74 , bool V_496 )
{
int V_58 ;
T_1 V_208 , V_3 ;
unsigned V_497 = 0xffff ;
int V_498 , V_499 = 0 ;
struct V_82 * V_83 = V_2 -> V_84 [ V_74 - 1 ] ;
for ( V_498 = 0 ; ; V_498 += V_500 ) {
V_58 = F_33 ( V_2 , V_74 , & V_3 , & V_208 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( ! ( V_208 & V_213 ) &&
( V_3 & V_209 ) == V_497 ) {
if ( ! V_496 ||
( V_497 == V_209 ) )
V_499 += V_500 ;
if ( V_499 >= V_227 )
break;
} else {
V_499 = 0 ;
V_497 = V_3 & V_209 ;
}
if ( V_208 & V_213 ) {
F_19 ( V_2 -> V_4 , V_74 ,
V_214 ) ;
}
if ( V_498 >= V_501 )
break;
F_68 ( V_500 ) ;
}
F_23 ( & V_83 -> V_22 , L_146 ,
V_498 , V_499 , V_3 ) ;
if ( V_499 < V_227 )
return - V_110 ;
return V_3 ;
}
void F_244 ( struct V_7 * V_11 )
{
F_245 ( V_11 , 0 + V_65 , true ) ;
F_245 ( V_11 , 0 + V_502 , true ) ;
F_246 ( V_11 , & V_11 -> V_344 , true ) ;
}
static int F_247 ( struct V_7 * V_11 , int V_179 )
{
int V_503 ;
struct V_190 * V_167 = F_62 ( V_11 -> V_181 ) ;
if ( ! V_167 -> V_168 -> V_504 && V_179 <= 1 )
return - V_71 ;
if ( V_11 -> V_92 == V_446 )
return 0 ;
if ( V_11 -> V_92 != V_424 )
return - V_71 ;
if ( V_167 -> V_168 -> V_504 )
V_503 = V_167 -> V_168 -> V_504 ( V_167 , V_11 ) ;
else
V_503 = F_15 ( V_11 , F_248 () ,
V_505 , 0 , V_179 , 0 ,
NULL , 0 , V_200 ) ;
if ( V_503 == 0 ) {
F_142 ( V_11 , V_179 ) ;
F_82 ( V_11 , V_446 ) ;
F_244 ( V_11 ) ;
}
return V_503 ;
}
static void F_249 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_4 ( V_11 -> V_25 ) ;
int V_371 = V_506 ;
if ( ! V_11 -> V_444 || ! V_11 -> V_17 )
return;
if ( V_2 )
V_371 = V_2 -> V_84 [ V_11 -> V_137 - 1 ] -> V_371 ;
if ( ( V_11 -> V_17 -> V_18 -> V_20 & F_250 ( V_507 ) ) ||
V_371 == V_374 ) {
V_11 -> V_508 = 1 ;
F_215 ( V_11 , 1 ) ;
}
}
static int F_251 ( struct V_7 * V_11 )
{
struct V_190 * V_167 = F_62 ( V_11 -> V_181 ) ;
if ( ! V_167 -> V_168 -> V_509 )
return 0 ;
if ( V_11 -> V_92 == V_446 )
return 0 ;
if ( V_11 -> V_92 != V_424 )
return - V_71 ;
return V_167 -> V_168 -> V_509 ( V_167 , V_11 ) ;
}
static int
F_252 ( struct V_1 * V_2 , struct V_7 * V_11 , int V_74 ,
int V_510 )
{
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_190 * V_167 = F_62 ( V_4 -> V_181 ) ;
int V_429 , V_511 , V_503 , V_57 ;
unsigned V_192 = V_409 ;
enum V_512 V_513 = V_11 -> V_14 ;
const char * V_14 ;
int V_179 = V_11 -> V_179 ;
const char * V_514 ;
if ( ! V_4 -> V_25 ) {
V_192 = V_515 ;
if ( V_74 == V_4 -> V_181 -> V_361 )
V_4 -> V_181 -> V_362 = 0 ;
}
if ( V_513 == V_416 )
V_192 = V_410 ;
F_30 ( V_167 -> V_516 ) ;
V_503 = F_199 ( V_2 , V_74 , V_11 , V_192 , false ) ;
if ( V_503 < 0 )
goto V_248;
V_503 = - V_123 ;
if ( V_513 != V_517 && V_513 != V_11 -> V_14 &&
! ( V_513 == V_52 && V_11 -> V_14 > V_513 ) ) {
F_23 ( & V_11 -> V_22 , L_147 ) ;
goto V_248;
}
V_513 = V_11 -> V_14 ;
switch ( V_11 -> V_14 ) {
case V_415 :
case V_52 :
case V_413 :
V_11 -> V_344 . V_56 . V_518 = F_232 ( 512 ) ;
break;
case V_15 :
V_11 -> V_344 . V_56 . V_518 = F_232 ( 64 ) ;
break;
case V_16 :
V_11 -> V_344 . V_56 . V_518 = F_232 ( 64 ) ;
break;
case V_416 :
V_11 -> V_344 . V_56 . V_518 = F_232 ( 8 ) ;
break;
default:
goto V_248;
}
if ( V_11 -> V_14 == V_413 )
V_14 = L_148 ;
else
V_14 = F_253 ( V_11 -> V_14 ) ;
if ( V_11 -> V_181 -> V_519 -> V_168 )
V_514 = V_11 -> V_181 -> V_519 -> V_168 -> V_520 ;
else
V_514 = V_11 -> V_181 -> V_521 -> V_168 -> V_520 ;
if ( V_11 -> V_14 < V_52 )
F_8 ( & V_11 -> V_22 ,
L_149 ,
( V_11 -> V_355 ) ? L_150 : L_151 , V_14 ,
V_179 , V_514 ) ;
if ( V_4 -> V_153 ) {
V_11 -> V_153 = V_4 -> V_153 ;
V_11 -> V_178 = V_4 -> V_178 ;
} else if ( V_11 -> V_14 != V_15
&& V_4 -> V_14 == V_15 ) {
if ( ! V_2 -> V_153 . V_2 ) {
F_31 ( & V_11 -> V_22 , L_152 ) ;
V_503 = - V_71 ;
goto V_248;
}
V_11 -> V_153 = & V_2 -> V_153 ;
V_11 -> V_178 = V_74 ;
}
for ( V_429 = 0 ; V_429 < V_522 ; ( ++ V_429 , F_68 ( 100 ) ) ) {
bool V_523 = false ;
if ( F_195 ( V_11 , V_510 ) ) {
struct V_524 * V_525 ;
int V_526 = 0 ;
V_523 = true ;
V_503 = F_251 ( V_11 ) ;
if ( V_503 < 0 ) {
F_31 ( & V_11 -> V_22 ,
L_153 ,
V_503 ) ;
goto V_248;
}
#define F_254 64
V_525 = F_58 ( F_254 , V_206 ) ;
if ( ! V_525 ) {
V_503 = - V_176 ;
continue;
}
for ( V_511 = 0 ; V_511 < 3 ; ++ V_511 ) {
V_525 -> V_527 = 0 ;
V_526 = F_15 ( V_11 , F_255 () ,
V_64 , V_65 ,
V_528 << 8 , 0 ,
V_525 , F_254 ,
V_529 ) ;
switch ( V_525 -> V_527 ) {
case 8 : case 16 : case 32 : case 64 : case 255 :
if ( V_525 -> V_530 ==
V_528 ) {
V_526 = 0 ;
break;
}
default:
if ( V_526 == 0 )
V_526 = - V_531 ;
break;
}
if ( V_526 == 0 || ( V_526 == - V_110 && V_429 == 0 ) )
break;
}
V_11 -> V_36 . V_527 =
V_525 -> V_527 ;
F_54 ( V_525 ) ;
V_503 = F_199 ( V_2 , V_74 , V_11 , V_192 , false ) ;
if ( V_503 < 0 )
goto V_248;
if ( V_513 != V_11 -> V_14 ) {
F_23 ( & V_11 -> V_22 ,
L_147 ) ;
V_503 = - V_123 ;
goto V_248;
}
if ( V_526 ) {
if ( V_526 != - V_123 )
F_31 ( & V_11 -> V_22 , L_154 ,
V_526 ) ;
V_503 = - V_70 ;
continue;
}
#undef F_254
}
if ( V_11 -> V_336 == 0 ) {
for ( V_511 = 0 ; V_511 < V_532 ; ++ V_511 ) {
V_503 = F_247 ( V_11 , V_179 ) ;
if ( V_503 >= 0 )
break;
F_68 ( 200 ) ;
}
if ( V_503 < 0 ) {
if ( V_503 != - V_123 )
F_31 ( & V_11 -> V_22 , L_155 ,
V_179 , V_503 ) ;
goto V_248;
}
if ( V_11 -> V_14 >= V_52 ) {
V_179 = V_11 -> V_179 ;
F_8 ( & V_11 -> V_22 ,
L_156 ,
( V_11 -> V_355 ) ? L_150 : L_151 ,
( V_11 -> V_14 == V_415 ) ? L_157 : L_38 ,
V_179 , V_514 ) ;
}
F_68 ( 10 ) ;
if ( V_523 )
break;
}
V_503 = F_190 ( V_11 , 8 ) ;
if ( V_503 < 8 ) {
if ( V_503 != - V_123 )
F_31 ( & V_11 -> V_22 ,
L_158 ,
V_503 ) ;
if ( V_503 >= 0 )
V_503 = - V_70 ;
} else {
V_503 = 0 ;
break;
}
}
if ( V_503 )
goto V_248;
if ( ( V_11 -> V_14 >= V_52 ) &&
( F_13 ( V_11 -> V_36 . V_533 ) < 0x0300 ) ) {
F_31 ( & V_11 -> V_22 , L_159
L_160 ) ;
F_199 ( V_2 , V_74 , V_11 ,
V_534 , true ) ;
V_503 = - V_71 ;
goto V_248;
}
if ( V_11 -> V_36 . V_527 == 0xff ||
V_11 -> V_14 >= V_52 )
V_57 = 512 ;
else
V_57 = V_11 -> V_36 . V_527 ;
if ( F_256 ( & V_11 -> V_344 . V_56 ) != V_57 ) {
if ( V_11 -> V_14 == V_416 ||
! ( V_57 == 8 || V_57 == 16 || V_57 == 32 || V_57 == 64 ) ) {
F_31 ( & V_11 -> V_22 , L_161 , V_57 ) ;
V_503 = - V_70 ;
goto V_248;
}
if ( V_11 -> V_14 == V_16 )
F_23 ( & V_11 -> V_22 , L_162 , V_57 ) ;
else
F_102 ( & V_11 -> V_22 , L_163 , V_57 ) ;
V_11 -> V_344 . V_56 . V_518 = F_232 ( V_57 ) ;
F_244 ( V_11 ) ;
}
V_503 = F_190 ( V_11 , V_535 ) ;
if ( V_503 < ( signed ) sizeof( V_11 -> V_36 ) ) {
if ( V_503 != - V_123 )
F_31 ( & V_11 -> V_22 , L_164 ,
V_503 ) ;
if ( V_503 >= 0 )
V_503 = - V_536 ;
goto V_248;
}
F_257 ( V_11 ) ;
if ( V_11 -> V_336 == 0 && F_13 ( V_11 -> V_36 . V_533 ) >= 0x0201 ) {
V_503 = F_258 ( V_11 ) ;
if ( ! V_503 ) {
V_11 -> V_26 = F_6 ( V_11 ) ;
F_12 ( V_11 ) ;
}
}
V_503 = 0 ;
if ( V_167 -> V_168 -> V_537 )
V_167 -> V_168 -> V_537 ( V_167 , V_11 ) ;
F_249 ( V_11 ) ;
V_248:
if ( V_503 ) {
F_73 ( V_2 , V_74 , 0 ) ;
F_142 ( V_11 , V_179 ) ;
}
F_32 ( V_167 -> V_516 ) ;
return V_503 ;
}
static void
F_259 ( struct V_1 * V_2 , struct V_7 * V_11 , int V_74 )
{
struct V_538 * V_539 ;
int V_85 ;
if ( V_11 -> V_12 & V_540 )
return;
V_539 = F_58 ( sizeof *V_539 , V_247 ) ;
if ( V_539 == NULL )
return;
V_85 = F_260 ( V_11 , V_541 , 0 ,
V_539 , sizeof *V_539 ) ;
if ( V_85 == sizeof *V_539 ) {
F_8 ( & V_11 -> V_22 , L_165
L_166 ) ;
if ( V_2 -> V_229 ) {
V_2 -> V_96 [ V_74 - 1 ] = V_99 ;
F_26 ( V_106 ,
& V_2 -> V_89 , 0 ) ;
}
}
F_54 ( V_539 ) ;
}
static unsigned
F_261 ( struct V_1 * V_2 )
{
struct V_7 * V_4 = V_2 -> V_4 ;
int V_283 ;
int V_74 ;
if ( ! V_2 -> V_281 )
return 0 ;
V_283 = V_4 -> V_279 - V_2 -> V_36 -> V_284 ;
for ( V_74 = 1 ; V_74 <= V_4 -> V_9 ; ++ V_74 ) {
struct V_82 * V_83 = V_2 -> V_84 [ V_74 - 1 ] ;
struct V_7 * V_11 = V_83 -> V_207 ;
unsigned V_245 ;
int V_542 ;
if ( ! V_11 )
continue;
if ( F_3 ( V_11 ) )
V_245 = 150 ;
else
V_245 = 100 ;
if ( V_11 -> V_8 )
V_542 = F_262 ( V_11 , V_11 -> V_8 ) ;
else if ( V_74 != V_11 -> V_181 -> V_361 || V_4 -> V_25 )
V_542 = V_245 ;
else
V_542 = 8 ;
if ( V_542 > V_2 -> V_280 )
F_102 ( & V_83 -> V_22 , L_167 ,
V_542 , V_2 -> V_280 ) ;
V_283 -= V_542 ;
}
if ( V_283 < 0 ) {
F_102 ( V_2 -> V_124 , L_168 ,
- V_283 ) ;
V_283 = 0 ;
}
return V_283 ;
}
static void F_263 ( struct V_1 * V_2 , int V_74 , T_1 V_3 ,
T_1 V_208 )
{
int V_85 = - V_123 ;
int V_57 ;
unsigned V_245 ;
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_190 * V_167 = F_62 ( V_4 -> V_181 ) ;
struct V_82 * V_83 = V_2 -> V_84 [ V_74 - 1 ] ;
struct V_7 * V_11 = V_83 -> V_207 ;
static int V_543 = - 1 ;
if ( V_11 ) {
if ( V_167 -> V_544 && ! V_4 -> V_25 )
F_264 ( V_167 -> V_544 , V_11 -> V_14 ) ;
F_85 ( & V_83 -> V_207 ) ;
}
if ( ! ( V_3 & V_209 ) ||
( V_208 & V_213 ) )
F_56 ( V_74 , V_2 -> V_188 ) ;
if ( V_208 & ( V_213 |
V_215 ) ) {
V_85 = F_265 ( V_2 , V_74 ) ;
if ( V_85 < 0 ) {
if ( V_85 != - V_123 &&
V_74 != V_543 &&
F_266 () )
F_31 ( & V_83 -> V_22 , L_169 ) ;
V_3 &= ~ V_209 ;
V_543 = V_74 ;
} else {
V_3 = V_85 ;
}
}
if ( ! ( V_3 & V_209 ) ||
F_67 ( V_74 , V_2 -> V_188 ) ) {
if ( F_66 ( V_2 )
&& ! F_202 ( V_2 , V_3 )
&& ! V_83 -> V_320 )
F_20 ( V_4 , V_74 , V_172 ) ;
if ( V_3 & V_210 )
goto V_421;
return;
}
if ( F_3 ( V_2 -> V_4 ) )
V_245 = 150 ;
else
V_245 = 100 ;
V_85 = 0 ;
for ( V_57 = 0 ; V_57 < V_545 ; V_57 ++ ) {
V_11 = F_267 ( V_4 , V_4 -> V_181 , V_74 ) ;
if ( ! V_11 ) {
F_31 ( & V_83 -> V_22 ,
L_170 ) ;
goto V_421;
}
F_82 ( V_11 , V_546 ) ;
V_11 -> V_279 = V_2 -> V_280 ;
V_11 -> V_199 = V_4 -> V_199 + 1 ;
V_11 -> V_336 = F_194 ( V_2 ) ;
if ( F_3 ( V_2 -> V_4 ) )
V_11 -> V_14 = V_52 ;
else
V_11 -> V_14 = V_517 ;
F_138 ( V_11 ) ;
if ( V_11 -> V_179 <= 0 ) {
V_85 = - V_411 ;
goto V_547;
}
F_203 ( V_83 ) ;
V_85 = F_252 ( V_2 , V_11 , V_74 , V_57 ) ;
F_204 ( V_83 ) ;
if ( V_85 < 0 )
goto V_547;
if ( V_11 -> V_12 & V_548 )
F_68 ( 2000 ) ;
if ( V_11 -> V_36 . V_549 == V_550
&& V_11 -> V_279 <= V_245 ) {
T_1 V_551 ;
V_85 = F_101 ( V_11 , V_276 , 0 ,
& V_551 ) ;
if ( V_85 ) {
F_23 ( & V_11 -> V_22 , L_171 , V_85 ) ;
goto V_552;
}
if ( ( V_551 & ( 1 << V_282 ) ) == 0 ) {
F_31 ( & V_11 -> V_22 ,
L_172
L_173 ) ;
if ( V_2 -> V_229 ) {
V_2 -> V_96 [ V_74 - 1 ] =
V_101 ;
F_26 (
V_106 ,
& V_2 -> V_89 , 0 ) ;
}
V_85 = - V_411 ;
goto V_552;
}
}
if ( F_13 ( V_11 -> V_36 . V_533 ) >= 0x0200
&& V_11 -> V_14 == V_16
&& V_293 != 0 )
F_259 ( V_2 , V_11 , V_74 ) ;
V_85 = 0 ;
F_30 ( & V_290 ) ;
F_115 ( & V_292 ) ;
if ( V_4 -> V_92 == V_211 )
V_85 = - V_411 ;
else
V_83 -> V_207 = V_11 ;
F_117 ( & V_292 ) ;
F_32 ( & V_290 ) ;
if ( ! V_85 ) {
V_85 = F_169 ( V_11 ) ;
if ( V_85 ) {
F_30 ( & V_290 ) ;
F_115 ( & V_292 ) ;
V_83 -> V_207 = NULL ;
F_117 ( & V_292 ) ;
F_32 ( & V_290 ) ;
} else {
if ( V_167 -> V_544 && ! V_4 -> V_25 )
F_268 ( V_167 -> V_544 ,
V_11 -> V_14 ) ;
}
}
if ( V_85 )
goto V_552;
V_85 = F_261 ( V_2 ) ;
if ( V_85 )
F_23 ( V_2 -> V_124 , L_174 , V_85 ) ;
return;
V_552:
F_73 ( V_2 , V_74 , 1 ) ;
V_547:
F_244 ( V_11 ) ;
F_141 ( V_11 ) ;
F_143 ( V_11 ) ;
F_111 ( V_11 ) ;
if ( ( V_85 == - V_411 ) || ( V_85 == - V_369 ) )
break;
}
if ( V_2 -> V_4 -> V_25 ||
! V_167 -> V_168 -> V_553 ||
! ( V_167 -> V_168 -> V_553 ) ( V_167 , V_74 ) ) {
if ( V_85 != - V_411 && V_85 != - V_123 )
F_31 ( & V_83 -> V_22 ,
L_175 ) ;
}
V_421:
F_73 ( V_2 , V_74 , 1 ) ;
if ( V_167 -> V_168 -> V_554 && ! V_2 -> V_4 -> V_25 ) {
if ( V_85 != - V_411 && V_85 != - V_123 )
V_167 -> V_168 -> V_554 ( V_167 , V_74 ) ;
}
}
static void F_269 ( struct V_1 * V_2 , int V_74 ,
T_1 V_3 , T_1 V_208 )
__must_hold( &port_dev->status_lock
static void F_270 ( struct V_1 * V_2 , int V_74 )
__must_hold( &port_dev->status_lock
static void V_306 ( struct V_87 * V_88 )
{
struct V_7 * V_4 ;
struct V_130 * V_131 ;
struct V_1 * V_2 ;
struct V_238 * V_239 ;
T_1 V_240 ;
T_1 V_241 ;
int V_57 , V_58 ;
V_2 = F_25 ( V_88 , struct V_1 , V_133 ) ;
V_4 = V_2 -> V_4 ;
V_239 = V_2 -> V_124 ;
V_131 = F_36 ( V_239 ) ;
F_23 ( V_239 , L_176 ,
V_4 -> V_92 , V_4 -> V_9 ,
( T_1 ) V_2 -> V_187 [ 0 ] ,
( T_1 ) V_2 -> V_149 [ 0 ] ) ;
F_145 ( V_4 ) ;
if ( F_271 ( V_2 -> V_132 ) )
goto V_555;
if ( V_4 -> V_92 == V_211 ) {
V_2 -> error = - V_123 ;
F_84 ( V_2 , V_291 ) ;
goto V_555;
}
V_58 = F_75 ( V_131 ) ;
if ( V_58 ) {
F_23 ( V_239 , L_177 , V_58 ) ;
goto V_555;
}
if ( V_2 -> V_94 )
goto V_556;
if ( V_2 -> error ) {
F_23 ( V_239 , L_178 , V_2 -> error ) ;
V_58 = F_272 ( V_4 ) ;
if ( V_58 ) {
F_23 ( V_239 , L_179 , V_58 ) ;
goto V_556;
}
V_2 -> V_145 = 0 ;
V_2 -> error = 0 ;
}
for ( V_57 = 1 ; V_57 <= V_4 -> V_9 ; V_57 ++ ) {
struct V_82 * V_83 = V_2 -> V_84 [ V_57 - 1 ] ;
if ( F_67 ( V_57 , V_2 -> V_149 )
|| F_67 ( V_57 , V_2 -> V_187 )
|| F_67 ( V_57 , V_2 -> V_138 ) ) {
F_172 ( & V_83 -> V_22 ) ;
F_90 ( & V_83 -> V_22 ) ;
F_203 ( V_83 ) ;
F_270 ( V_2 , V_57 ) ;
F_204 ( V_83 ) ;
F_216 ( & V_83 -> V_22 ) ;
}
}
if ( F_154 ( 0 , V_2 -> V_149 ) == 0 )
;
else if ( F_70 ( V_2 , & V_240 , & V_241 ) < 0 )
F_31 ( V_239 , L_180 ) ;
else {
if ( V_241 & V_557 ) {
F_23 ( V_239 , L_181 ) ;
F_17 ( V_4 , V_558 ) ;
if ( V_240 & V_286 )
V_2 -> V_281 = 1 ;
else
V_2 -> V_281 = 0 ;
}
if ( V_241 & V_559 ) {
T_1 V_85 = 0 ;
T_1 V_560 ;
F_23 ( V_239 , L_182 ) ;
F_17 ( V_4 , V_561 ) ;
F_68 ( 500 ) ;
F_65 ( V_2 , true ) ;
F_70 ( V_2 , & V_85 , & V_560 ) ;
if ( V_85 & V_287 )
F_31 ( V_239 , L_183 ) ;
}
}
V_556:
F_273 ( V_131 ) ;
V_555:
F_152 ( V_4 ) ;
F_76 ( V_131 ) ;
F_41 ( & V_2 -> V_134 , V_136 ) ;
}
int F_274 ( void )
{
if ( F_275 ( & V_562 ) < 0 ) {
F_276 ( V_563 L_184 ,
V_564 ) ;
return - 1 ;
}
V_135 = F_277 ( L_185 , V_565 , 0 ) ;
if ( V_135 )
return 0 ;
F_278 ( & V_562 ) ;
F_279 ( L_186 , V_564 ) ;
return - 1 ;
}
void F_280 ( void )
{
F_281 ( V_135 ) ;
F_278 ( & V_562 ) ;
}
static int F_282 ( struct V_7 * V_11 ,
struct V_524 * V_566 ,
struct V_567 * V_568 )
{
int V_90 = 0 ;
unsigned V_569 ;
unsigned V_570 = 0 ;
unsigned V_119 ;
unsigned V_571 ;
int V_116 ;
char * V_525 ;
if ( memcmp ( & V_11 -> V_36 , V_566 ,
sizeof( * V_566 ) ) != 0 )
return 1 ;
if ( ( V_568 && ! V_11 -> V_17 ) || ( ! V_568 && V_11 -> V_17 ) )
return 1 ;
if ( V_11 -> V_17 ) {
V_119 = F_13 ( V_11 -> V_17 -> V_56 -> V_358 ) ;
if ( V_119 != F_13 ( V_568 -> V_56 -> V_358 ) )
return 1 ;
if ( memcmp ( V_11 -> V_17 -> V_56 , V_568 -> V_56 , V_119 ) )
return 1 ;
}
if ( V_11 -> V_352 )
V_570 = strlen ( V_11 -> V_352 ) + 1 ;
V_119 = V_570 ;
for ( V_569 = 0 ; V_569 < V_11 -> V_36 . V_572 ; V_569 ++ ) {
V_571 = F_13 ( V_11 -> V_355 [ V_569 ] . V_56 . V_358 ) ;
V_119 = F_283 ( V_119 , V_571 ) ;
}
V_525 = F_58 ( V_119 , V_206 ) ;
if ( ! V_525 )
return 1 ;
for ( V_569 = 0 ; V_569 < V_11 -> V_36 . V_572 ; V_569 ++ ) {
V_571 = F_13 ( V_11 -> V_355 [ V_569 ] . V_56 . V_358 ) ;
V_116 = F_260 ( V_11 , V_573 , V_569 , V_525 ,
V_571 ) ;
if ( V_116 != V_571 ) {
F_23 ( & V_11 -> V_22 , L_187 ,
V_569 , V_116 ) ;
V_90 = 1 ;
break;
}
if ( memcmp ( V_525 , V_11 -> V_357 [ V_569 ] , V_571 )
!= 0 ) {
F_23 ( & V_11 -> V_22 , L_188 ,
V_569 ,
( (struct V_574 * ) V_525 ) ->
V_575 ) ;
V_90 = 1 ;
break;
}
}
if ( ! V_90 && V_570 ) {
V_116 = F_284 ( V_11 , V_11 -> V_36 . V_349 ,
V_525 , V_570 ) ;
if ( V_116 + 1 != V_570 ) {
F_23 ( & V_11 -> V_22 , L_189 ,
V_116 ) ;
V_90 = 1 ;
} else if ( memcmp ( V_525 , V_11 -> V_352 , V_116 ) != 0 ) {
F_23 ( & V_11 -> V_22 , L_190 ) ;
V_90 = 1 ;
}
}
F_54 ( V_525 ) ;
return V_90 ;
}
static int F_218 ( struct V_7 * V_11 )
{
struct V_7 * V_576 = V_11 -> V_25 ;
struct V_1 * V_577 ;
struct V_190 * V_167 = F_62 ( V_11 -> V_181 ) ;
struct V_524 V_36 = V_11 -> V_36 ;
struct V_567 * V_17 ;
int V_57 , V_578 , V_58 = 0 ;
int V_74 = V_11 -> V_137 ;
if ( V_11 -> V_92 == V_211 ||
V_11 -> V_92 == V_326 ) {
F_23 ( & V_11 -> V_22 , L_191 ,
V_11 -> V_92 ) ;
return - V_71 ;
}
if ( ! V_576 )
return - V_579 ;
V_577 = F_4 ( V_576 ) ;
if ( V_11 -> V_441 == 1 )
F_215 ( V_11 , 0 ) ;
V_58 = F_240 ( V_11 ) ;
if ( V_58 ) {
F_31 ( & V_11 -> V_22 , L_192 , V_125 ) ;
goto V_580;
}
V_58 = F_208 ( V_11 ) ;
if ( V_58 ) {
F_31 ( & V_11 -> V_22 , L_193 ,
V_125 ) ;
goto V_580;
}
V_17 = V_11 -> V_17 ;
V_11 -> V_17 = NULL ;
for ( V_57 = 0 ; V_57 < V_545 ; ++ V_57 ) {
F_244 ( V_11 ) ;
V_58 = F_252 ( V_577 , V_11 , V_74 , V_57 ) ;
if ( V_58 >= 0 || V_58 == - V_411 || V_58 == - V_123 )
break;
}
if ( V_58 < 0 )
goto V_581;
if ( F_282 ( V_11 , & V_36 , V_17 ) ) {
F_8 ( & V_11 -> V_22 , L_194 ) ;
V_11 -> V_36 = V_36 ;
goto V_581;
}
if ( ! V_11 -> V_8 )
goto V_421;
F_30 ( V_167 -> V_492 ) ;
V_58 = F_285 ( V_11 , V_11 -> V_8 , NULL , NULL ) ;
if ( V_58 < 0 ) {
F_102 ( & V_11 -> V_22 ,
L_195
L_196 ) ;
F_32 ( V_167 -> V_492 ) ;
goto V_581;
}
V_58 = F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_582 , 0 ,
V_11 -> V_8 -> V_56 . V_575 , 0 ,
NULL , 0 , V_200 ) ;
if ( V_58 < 0 ) {
F_31 ( & V_11 -> V_22 ,
L_197 ,
V_11 -> V_8 -> V_56 . V_575 , V_58 ) ;
F_32 ( V_167 -> V_492 ) ;
goto V_581;
}
F_32 ( V_167 -> V_492 ) ;
F_82 ( V_11 , V_93 ) ;
for ( V_57 = 0 ; V_57 < V_11 -> V_8 -> V_56 . V_583 ; V_57 ++ ) {
struct V_584 * V_355 = V_11 -> V_8 ;
struct V_130 * V_131 = V_355 -> V_10 [ V_57 ] ;
struct V_585 * V_56 ;
V_56 = & V_131 -> V_299 -> V_56 ;
if ( V_56 -> V_586 == 0 ) {
F_286 ( V_11 , V_131 , true ) ;
F_287 ( V_11 , V_131 , true ) ;
V_58 = 0 ;
} else {
V_131 -> V_587 = 1 ;
V_58 = F_100 ( V_11 , V_56 -> V_588 ,
V_56 -> V_586 ) ;
V_131 -> V_587 = 0 ;
}
if ( V_58 < 0 ) {
F_31 ( & V_11 -> V_22 , L_198
L_199 ,
V_56 -> V_588 ,
V_56 -> V_586 ,
V_58 ) ;
goto V_581;
}
for ( V_578 = 0 ; V_578 < V_131 -> V_299 -> V_56 . V_296 ; V_578 ++ )
V_131 -> V_299 -> V_237 [ V_578 ] . V_589 = 0 ;
}
V_421:
F_215 ( V_11 , 1 ) ;
F_241 ( V_11 ) ;
F_210 ( V_11 ) ;
F_288 ( V_11 ) ;
V_11 -> V_17 = V_17 ;
return 0 ;
V_581:
F_288 ( V_11 ) ;
V_11 -> V_17 = V_17 ;
V_580:
F_72 ( V_577 , V_74 ) ;
return - V_123 ;
}
int F_272 ( struct V_7 * V_11 )
{
int V_58 ;
int V_57 ;
unsigned int V_590 ;
struct V_82 * V_83 ;
struct V_584 * V_355 = V_11 -> V_8 ;
struct V_1 * V_2 = F_4 ( V_11 -> V_25 ) ;
if ( V_11 -> V_92 == V_211 ||
V_11 -> V_92 == V_326 ) {
F_23 ( & V_11 -> V_22 , L_191 ,
V_11 -> V_92 ) ;
return - V_71 ;
}
if ( ! V_11 -> V_25 ) {
F_23 ( & V_11 -> V_22 , L_200 , V_125 ) ;
return - V_579 ;
}
V_83 = V_2 -> V_84 [ V_11 -> V_137 - 1 ] ;
V_590 = F_289 () ;
F_189 ( V_11 ) ;
if ( V_355 ) {
for ( V_57 = 0 ; V_57 < V_355 -> V_56 . V_583 ; ++ V_57 ) {
struct V_130 * V_591 = V_355 -> V_10 [ V_57 ] ;
struct V_592 * V_166 ;
int V_593 = 0 ;
if ( V_591 -> V_22 . V_168 ) {
V_166 = F_290 ( V_591 -> V_22 . V_168 ) ;
if ( V_166 -> V_594 && V_166 -> V_595 )
V_593 = ( V_166 -> V_594 ) ( V_591 ) ;
else if ( V_591 -> V_596 ==
V_597 )
V_593 = 1 ;
if ( V_593 )
F_291 ( V_591 ) ;
}
}
}
F_203 ( V_83 ) ;
V_58 = F_218 ( V_11 ) ;
F_204 ( V_83 ) ;
if ( V_355 ) {
for ( V_57 = V_355 -> V_56 . V_583 - 1 ; V_57 >= 0 ; -- V_57 ) {
struct V_130 * V_591 = V_355 -> V_10 [ V_57 ] ;
struct V_592 * V_166 ;
int V_598 = V_591 -> V_599 ;
if ( ! V_598 && V_591 -> V_22 . V_168 ) {
V_166 = F_290 ( V_591 -> V_22 . V_168 ) ;
if ( V_166 -> V_595 )
V_598 = ( V_166 -> V_595 ) ( V_591 ) ;
else if ( V_591 -> V_596 ==
V_597 )
V_598 = 1 ;
if ( V_598 )
V_591 -> V_599 = 1 ;
}
}
F_292 ( V_11 ) ;
}
F_192 ( V_11 ) ;
F_293 ( V_590 ) ;
return V_58 ;
}
void F_294 ( struct V_130 * V_600 )
{
if ( F_64 ( & V_600 -> V_601 ) )
F_128 ( V_600 ) ;
}
struct V_7 * F_295 ( struct V_7 * V_4 ,
int V_74 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
if ( V_74 < 1 || V_74 > V_4 -> V_9 )
return NULL ;
return V_2 -> V_84 [ V_74 - 1 ] -> V_207 ;
}
void F_110 ( struct V_7 * V_4 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
enum V_602 V_371 ;
int V_57 ;
if ( ! V_2 )
return;
if ( ! F_3 ( V_4 ) ) {
for ( V_57 = 1 ; V_57 <= V_4 -> V_9 ; V_57 ++ ) {
struct V_82 * V_83 = V_2 -> V_84 [ V_57 - 1 ] ;
V_371 = V_83 -> V_371 ;
if ( V_371 == V_374 ) {
T_3 V_603 = 1 << ( V_57 % 8 ) ;
if ( ! ( V_56 -> V_37 . V_253 . V_254 [ V_57 / 8 ] & V_603 ) ) {
F_23 ( & V_83 -> V_22 , L_201 ) ;
V_56 -> V_37 . V_253 . V_254 [ V_57 / 8 ] |= V_603 ;
}
}
}
} else {
T_1 V_604 = F_13 ( V_56 -> V_37 . V_38 . V_254 ) ;
for ( V_57 = 1 ; V_57 <= V_4 -> V_9 ; V_57 ++ ) {
struct V_82 * V_83 = V_2 -> V_84 [ V_57 - 1 ] ;
V_371 = V_83 -> V_371 ;
if ( V_371 == V_374 ) {
T_1 V_603 = 1 << V_57 ;
if ( ! ( V_604 & V_603 ) ) {
F_23 ( & V_83 -> V_22 , L_201 ) ;
V_604 |= V_603 ;
}
}
}
V_56 -> V_37 . V_38 . V_254 = F_232 ( V_604 ) ;
}
}
T_7 F_296 ( struct V_7 * V_4 ,
int V_74 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
if ( ! V_2 )
return NULL ;
return F_297 ( & V_2 -> V_84 [ V_74 - 1 ] -> V_22 ) ;
}
