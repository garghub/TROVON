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
static int F_14 ( struct V_7 * V_4 , void * V_55 )
{
int V_56 , V_57 , V_58 ;
unsigned V_59 ;
if ( F_3 ( V_4 ) ) {
V_59 = V_60 ;
V_58 = V_61 ;
} else {
V_59 = V_62 ;
V_58 = sizeof( struct V_63 ) ;
}
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
V_57 = F_15 ( V_4 , F_16 ( V_4 , 0 ) ,
V_64 , V_65 | V_66 ,
V_59 << 8 , 0 , V_55 , V_58 ,
V_67 ) ;
if ( V_57 >= ( V_68 + 2 ) )
return V_57 ;
}
return - V_69 ;
}
static int F_17 ( struct V_7 * V_4 , int V_70 )
{
return F_15 ( V_4 , F_18 ( V_4 , 0 ) ,
V_71 , V_66 , V_70 , 0 , NULL , 0 , 1000 ) ;
}
int F_19 ( struct V_7 * V_4 , int V_72 , int V_70 )
{
return F_15 ( V_4 , F_18 ( V_4 , 0 ) ,
V_71 , V_73 , V_70 , V_72 ,
NULL , 0 , 1000 ) ;
}
static int F_20 ( struct V_7 * V_4 , int V_72 , int V_70 )
{
return F_15 ( V_4 , F_18 ( V_4 , 0 ) ,
V_74 , V_73 , V_70 , V_72 ,
NULL , 0 , 1000 ) ;
}
static char * F_21 ( int V_75 )
{
switch ( V_75 ) {
case V_76 :
return L_9 ;
case V_77 :
return L_10 ;
case V_78 :
return L_11 ;
case V_79 :
return L_12 ;
default:
return L_13 ;
}
}
static void F_22 ( struct V_1 * V_2 , int V_72 , int V_75 )
{
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
int V_83 ;
V_83 = F_20 ( V_2 -> V_4 , ( V_75 << 8 ) | V_72 ,
V_84 ) ;
F_23 ( & V_81 -> V_22 , L_14 ,
F_21 ( V_75 ) , V_83 ) ;
}
static void F_24 ( struct V_85 * V_86 )
{
struct V_1 * V_2 =
F_25 ( V_86 , struct V_1 , V_87 . V_86 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
unsigned V_56 ;
unsigned V_88 = 0 ;
int V_89 = - 1 ;
if ( V_4 -> V_90 != V_91 || V_2 -> V_92 )
return;
for ( V_56 = 0 ; V_56 < V_4 -> V_9 ; V_56 ++ ) {
unsigned V_75 , V_93 ;
switch ( V_2 -> V_94 [ V_56 ] ) {
case V_95 :
V_89 = V_56 ;
V_75 = V_79 ;
V_93 = V_96 ;
break;
case V_97 :
V_75 = V_77 ;
V_93 = V_98 ;
break;
case V_98 :
V_75 = V_78 ;
V_93 = V_97 ;
break;
case V_99 :
V_75 = V_76 ;
V_93 = V_100 ;
break;
case V_100 :
V_75 = V_78 ;
V_93 = V_99 ;
break;
case V_101 :
V_75 = V_77 ;
V_93 = V_102 ;
break;
case V_102 :
V_75 = V_76 ;
V_93 = V_101 ;
break;
default:
continue;
}
if ( V_75 != V_79 )
V_88 = 1 ;
F_22 ( V_2 , V_56 + 1 , V_75 ) ;
V_2 -> V_94 [ V_56 ] = V_93 ;
}
if ( ! V_88 && V_103 ) {
V_89 ++ ;
V_89 %= V_4 -> V_9 ;
F_22 ( V_2 , V_89 + 1 , V_77 ) ;
V_2 -> V_94 [ V_89 ] = V_95 ;
V_88 ++ ;
}
if ( V_88 )
F_26 ( V_104 ,
& V_2 -> V_87 , V_105 ) ;
}
static int F_27 ( struct V_7 * V_4 ,
struct V_106 * V_55 )
{
int V_56 , V_83 = - V_107 ;
for ( V_56 = 0 ; V_56 < V_108 &&
( V_83 == - V_107 || V_83 == - V_109 ) ; V_56 ++ ) {
V_83 = F_15 ( V_4 , F_16 ( V_4 , 0 ) ,
V_110 , V_65 | V_66 , 0 , 0 ,
V_55 , sizeof( * V_55 ) , V_111 ) ;
}
return V_83 ;
}
static int F_28 ( struct V_7 * V_4 , int V_72 ,
void * V_55 , T_1 V_112 , T_1 V_113 )
{
int V_56 , V_83 = - V_107 ;
for ( V_56 = 0 ; V_56 < V_108 &&
( V_83 == - V_107 || V_83 == - V_109 ) ; V_56 ++ ) {
V_83 = F_15 ( V_4 , F_16 ( V_4 , 0 ) ,
V_110 , V_65 | V_73 , V_112 ,
V_72 , V_55 , V_113 , V_111 ) ;
}
return V_83 ;
}
static int F_29 ( struct V_1 * V_2 , int V_72 , int type ,
T_1 * V_83 , T_1 * V_114 , T_2 * V_115 )
{
int V_57 ;
int V_116 = 4 ;
if ( type != V_117 )
V_116 = 8 ;
F_30 ( & V_2 -> V_118 ) ;
V_57 = F_28 ( V_2 -> V_4 , V_72 , & V_2 -> V_83 -> V_119 , type , V_116 ) ;
if ( V_57 < V_116 ) {
if ( V_57 != - V_120 )
F_31 ( V_2 -> V_121 ,
L_15 , V_122 , V_57 ) ;
if ( V_57 >= 0 )
V_57 = - V_123 ;
} else {
* V_83 = F_13 ( V_2 -> V_83 -> V_119 . V_124 ) ;
* V_114 = F_13 ( V_2 -> V_83 -> V_119 . V_125 ) ;
if ( type != V_117 && V_115 )
* V_115 = F_7 (
V_2 -> V_83 -> V_119 . V_126 ) ;
V_57 = 0 ;
}
F_32 ( & V_2 -> V_118 ) ;
return V_57 ;
}
static int F_33 ( struct V_1 * V_2 , int V_72 ,
T_1 * V_83 , T_1 * V_114 )
{
return F_29 ( V_2 , V_72 , V_117 ,
V_83 , V_114 , NULL ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_127 * V_128 ;
if ( V_2 -> V_129 || F_35 ( & V_2 -> V_130 ) )
return;
V_128 = F_36 ( V_2 -> V_121 ) ;
F_37 ( V_128 ) ;
F_38 ( & V_2 -> V_131 ) ;
if ( F_39 ( V_132 , & V_2 -> V_130 ) )
return;
F_40 ( V_128 ) ;
F_41 ( & V_2 -> V_131 , V_133 ) ;
}
void F_42 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
if ( V_2 )
F_34 ( V_2 ) ;
}
void F_43 ( struct V_7 * V_4 ,
unsigned int V_134 )
{
struct V_1 * V_2 ;
if ( ! V_4 )
return;
V_2 = F_4 ( V_4 ) ;
if ( V_2 ) {
F_44 ( V_134 , V_2 -> V_135 ) ;
F_34 ( V_2 ) ;
}
}
static void F_45 ( struct V_136 * V_136 )
{
struct V_1 * V_2 = V_136 -> V_137 ;
int V_83 = V_136 -> V_83 ;
unsigned V_56 ;
unsigned long V_138 ;
switch ( V_83 ) {
case - V_139 :
case - V_140 :
case - V_141 :
return;
default:
F_23 ( V_2 -> V_121 , L_16 , V_83 ) ;
if ( ( ++ V_2 -> V_142 < 10 ) || V_2 -> error )
goto V_143;
V_2 -> error = V_83 ;
case 0 :
V_138 = 0 ;
for ( V_56 = 0 ; V_56 < V_136 -> V_144 ; ++ V_56 )
V_138 |= ( ( unsigned long ) ( ( * V_2 -> V_145 ) [ V_56 ] ) )
<< ( V_56 * 8 ) ;
V_2 -> V_146 [ 0 ] = V_138 ;
break;
}
V_2 -> V_142 = 0 ;
F_34 ( V_2 ) ;
V_143:
if ( V_2 -> V_92 )
return;
V_83 = F_46 ( V_2 -> V_136 , V_147 ) ;
if ( V_83 != 0 && V_83 != - V_120 && V_83 != - V_148 )
F_31 ( V_2 -> V_121 , L_17 , V_83 ) ;
}
static inline int
F_47 ( struct V_7 * V_4 , T_1 V_149 , T_1 V_150 )
{
if ( ( ( V_149 >> 11 ) & V_151 ) ==
V_152 ) {
int V_83 = F_15 ( V_4 , F_18 ( V_4 , 0 ) ,
V_153 , V_73 ,
V_149 ^ 0x8000 , V_150 , NULL , 0 , 1000 ) ;
if ( V_83 )
return V_83 ;
}
return F_15 ( V_4 , F_18 ( V_4 , 0 ) ,
V_153 , V_73 , V_149 ,
V_150 , NULL , 0 , 1000 ) ;
}
static void F_48 ( struct V_85 * V_86 )
{
struct V_1 * V_2 =
F_25 ( V_86 , struct V_1 , V_150 . V_154 ) ;
unsigned long V_155 ;
F_49 ( & V_2 -> V_150 . V_156 , V_155 ) ;
while ( ! F_50 ( & V_2 -> V_150 . V_157 ) ) {
struct V_158 * V_159 ;
struct V_160 * V_161 ;
struct V_7 * V_4 = V_2 -> V_4 ;
const struct V_162 * V_163 ;
int V_83 ;
V_159 = V_2 -> V_150 . V_157 . V_159 ;
V_161 = F_51 ( V_159 , struct V_160 , V_157 ) ;
F_52 ( & V_161 -> V_157 ) ;
F_53 ( & V_2 -> V_150 . V_156 , V_155 ) ;
V_83 = F_47 ( V_4 , V_161 -> V_149 , V_161 -> V_150 ) ;
if ( V_83 && V_83 != - V_120 )
F_31 ( & V_4 -> V_22 ,
L_18 ,
V_161 -> V_150 , V_161 -> V_149 , V_83 ) ;
V_163 = V_161 -> V_164 -> V_165 ;
if ( V_163 -> V_166 )
( V_163 -> V_166 ) ( V_161 -> V_164 , V_161 -> V_167 ) ;
F_54 ( V_161 ) ;
F_49 ( & V_2 -> V_150 . V_156 , V_155 ) ;
}
F_53 ( & V_2 -> V_150 . V_156 , V_155 ) ;
}
int F_55 ( struct V_7 * V_4 , struct V_1 * V_2 ,
int V_72 , bool V_168 )
{
int V_57 ;
if ( V_168 )
V_57 = F_20 ( V_4 , V_72 , V_169 ) ;
else
V_57 = F_19 ( V_4 , V_72 , V_169 ) ;
if ( V_57 )
return V_57 ;
if ( V_168 )
F_44 ( V_72 , V_2 -> V_170 ) ;
else
F_56 ( V_72 , V_2 -> V_170 ) ;
return 0 ;
}
int F_57 ( struct V_136 * V_136 )
{
struct V_7 * V_11 = V_136 -> V_22 ;
int V_171 = V_136 -> V_171 ;
struct V_172 * V_150 = V_11 -> V_150 ;
unsigned long V_155 ;
struct V_160 * V_161 ;
V_161 = F_58 ( sizeof *V_161 , V_147 ) ;
if ( V_161 == NULL ) {
F_31 ( & V_11 -> V_22 , L_19 ) ;
return - V_173 ;
}
V_161 -> V_150 = V_150 -> V_174 ? V_11 -> V_175 : 1 ;
V_161 -> V_149 = F_59 ( V_171 ) ;
V_161 -> V_149 |= V_11 -> V_176 << 4 ;
V_161 -> V_149 |= F_60 ( V_171 )
? ( V_152 << 11 )
: ( V_177 << 11 ) ;
if ( F_61 ( V_171 ) )
V_161 -> V_149 |= 1 << 15 ;
V_161 -> V_164 = F_62 ( V_11 -> V_178 ) ;
V_161 -> V_167 = V_136 -> V_167 ;
F_49 ( & V_150 -> V_156 , V_155 ) ;
F_63 ( & V_161 -> V_157 , & V_150 -> V_157 ) ;
F_64 ( & V_150 -> V_154 ) ;
F_53 ( & V_150 -> V_156 , V_155 ) ;
return 0 ;
}
static void F_65 ( struct V_1 * V_2 , bool V_179 )
{
int V_72 ;
if ( F_66 ( V_2 ) )
F_23 ( V_2 -> V_121 , L_20 ) ;
else
F_23 ( V_2 -> V_121 , L_21
L_22 ) ;
for ( V_72 = 1 ; V_72 <= V_2 -> V_4 -> V_9 ; V_72 ++ )
if ( F_67 ( V_72 , V_2 -> V_170 ) )
F_20 ( V_2 -> V_4 , V_72 , V_169 ) ;
else
F_19 ( V_2 -> V_4 , V_72 ,
V_169 ) ;
if ( V_179 )
F_68 ( F_69 ( V_2 ) ) ;
}
static int F_70 ( struct V_1 * V_2 ,
T_1 * V_83 , T_1 * V_114 )
{
int V_57 ;
F_30 ( & V_2 -> V_118 ) ;
V_57 = F_27 ( V_2 -> V_4 , & V_2 -> V_83 -> V_2 ) ;
if ( V_57 < 0 ) {
if ( V_57 != - V_120 )
F_31 ( V_2 -> V_121 ,
L_15 , V_122 , V_57 ) ;
} else {
* V_83 = F_13 ( V_2 -> V_83 -> V_2 . V_180 ) ;
* V_114 = F_13 ( V_2 -> V_83 -> V_2 . V_181 ) ;
V_57 = 0 ;
}
F_32 ( & V_2 -> V_118 ) ;
return V_57 ;
}
static int F_71 ( struct V_1 * V_2 , int V_72 ,
unsigned int V_182 )
{
return F_20 ( V_2 -> V_4 ,
V_72 | ( V_182 << 3 ) ,
V_183 ) ;
}
static void F_72 ( struct V_1 * V_2 , int V_72 )
{
F_23 ( & V_2 -> V_82 [ V_72 - 1 ] -> V_22 , L_23 ) ;
F_73 ( V_2 , V_72 , 1 ) ;
F_44 ( V_72 , V_2 -> V_184 ) ;
F_34 ( V_2 ) ;
}
int F_74 ( struct V_7 * V_11 )
{
struct V_1 * V_2 ;
struct V_127 * V_128 ;
if ( ! V_11 -> V_25 )
return - V_69 ;
V_2 = F_4 ( V_11 -> V_25 ) ;
V_128 = F_36 ( V_2 -> V_121 ) ;
F_75 ( V_128 ) ;
F_44 ( V_11 -> V_134 , V_2 -> V_185 ) ;
F_72 ( V_2 , V_11 -> V_134 ) ;
F_76 ( V_128 ) ;
return 0 ;
}
static void F_77 ( struct V_1 * V_2 , enum V_186 type )
{
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_187 * V_164 ;
int V_57 ;
int V_72 ;
int V_83 ;
bool V_188 = false ;
unsigned V_189 ;
if ( type == V_190 || type == V_191 ) {
F_78 ( & V_4 -> V_22 ) ;
if ( V_2 -> V_129 )
goto V_129;
if ( type == V_190 )
goto V_192;
goto V_193;
}
F_38 ( & V_2 -> V_131 ) ;
if ( type != V_194 ) {
if ( V_4 -> V_25 && F_3 ( V_4 ) ) {
V_57 = F_15 ( V_4 , F_18 ( V_4 , 0 ) ,
V_195 , V_66 ,
V_4 -> V_196 - 1 , 0 , NULL , 0 ,
V_197 ) ;
if ( V_57 < 0 )
F_31 ( V_2 -> V_121 ,
L_24 ) ;
}
if ( type == V_198 ) {
V_189 = F_69 ( V_2 ) ;
F_65 ( V_2 , false ) ;
F_79 ( & V_2 -> V_199 , V_200 ) ;
F_26 ( V_104 ,
& V_2 -> V_199 ,
F_80 ( V_189 ) ) ;
F_37 (
F_36 ( V_2 -> V_121 ) ) ;
return;
} else if ( type == V_201 ) {
V_164 = F_62 ( V_4 -> V_178 ) ;
if ( V_164 -> V_165 -> V_202 ) {
V_57 = V_164 -> V_165 -> V_202 ( V_164 , V_4 ,
& V_2 -> V_150 , V_203 ) ;
if ( V_57 < 0 ) {
F_31 ( V_2 -> V_121 , L_25
L_26
L_27 ) ;
F_31 ( V_2 -> V_121 , L_28
L_29
L_30 ) ;
}
}
F_65 ( V_2 , true ) ;
} else {
F_65 ( V_2 , true ) ;
}
}
V_192:
for ( V_72 = 1 ; V_72 <= V_4 -> V_9 ; ++ V_72 ) {
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
struct V_7 * V_11 = V_81 -> V_204 ;
T_1 V_3 , V_205 ;
V_3 = V_205 = 0 ;
V_83 = F_33 ( V_2 , V_72 , & V_3 , & V_205 ) ;
if ( V_11 || ( V_3 & V_206 ) )
F_23 ( & V_81 -> V_22 , L_31 ,
V_3 , V_205 ) ;
if ( ( V_3 & V_207 ) && (
type != V_194 ||
! ( V_3 & V_206 ) ||
! V_11 ||
V_11 -> V_90 == V_208 ) ) {
V_3 &= ~ V_207 ;
if ( ! F_3 ( V_4 ) )
F_19 ( V_4 , V_72 ,
V_209 ) ;
}
if ( V_205 & V_210 ) {
V_188 = true ;
F_19 ( V_2 -> V_4 , V_72 ,
V_211 ) ;
}
if ( V_205 & V_212 ) {
V_188 = true ;
F_19 ( V_2 -> V_4 , V_72 ,
V_213 ) ;
}
if ( V_205 & V_214 ) {
V_188 = true ;
F_19 ( V_2 -> V_4 , V_72 ,
V_215 ) ;
}
if ( ( V_205 & V_216 ) &&
F_3 ( V_2 -> V_4 ) ) {
V_188 = true ;
F_19 ( V_2 -> V_4 , V_72 ,
V_217 ) ;
}
if ( ! ( V_3 & V_206 ) ||
( V_205 & V_210 ) )
F_56 ( V_72 , V_2 -> V_185 ) ;
if ( ! V_11 || V_11 -> V_90 == V_208 ) {
if ( V_11 || ( V_3 & V_206 ) ||
( V_3 & V_218 ) )
F_44 ( V_72 , V_2 -> V_184 ) ;
} else if ( V_3 & V_207 ) {
bool V_219 = ( V_3 &
V_220 ) ==
V_221 ;
if ( V_205 || ( F_3 ( V_2 -> V_4 ) &&
V_219 ) )
F_44 ( V_72 , V_2 -> V_184 ) ;
} else if ( V_11 -> V_222 ) {
#ifdef F_81
V_11 -> V_223 = 1 ;
#endif
if ( F_67 ( V_72 , V_2 -> V_170 ) )
F_44 ( V_72 , V_2 -> V_184 ) ;
} else {
F_82 ( V_11 , V_208 ) ;
F_44 ( V_72 , V_2 -> V_184 ) ;
}
}
if ( V_188 ) {
V_189 = V_224 ;
if ( type == V_190 ) {
F_79 ( & V_2 -> V_199 , V_225 ) ;
F_26 ( V_104 ,
& V_2 -> V_199 ,
F_80 ( V_189 ) ) ;
F_83 ( & V_4 -> V_22 ) ;
return;
} else {
F_68 ( V_189 ) ;
}
}
V_193:
V_2 -> V_92 = 0 ;
V_83 = F_46 ( V_2 -> V_136 , V_203 ) ;
if ( V_83 < 0 )
F_31 ( V_2 -> V_121 , L_32 , V_83 ) ;
if ( V_2 -> V_226 && V_103 )
F_26 ( V_104 ,
& V_2 -> V_87 , V_105 ) ;
F_34 ( V_2 ) ;
if ( type == V_190 || type == V_191 ) {
V_129:
F_40 ( F_36 ( V_2 -> V_121 ) ) ;
F_83 ( & V_4 -> V_22 ) ;
}
F_41 ( & V_2 -> V_131 , V_133 ) ;
}
static void V_200 ( struct V_85 * V_227 )
{
struct V_1 * V_2 = F_25 ( V_227 , struct V_1 , V_199 . V_86 ) ;
F_77 ( V_2 , V_190 ) ;
}
static void V_225 ( struct V_85 * V_227 )
{
struct V_1 * V_2 = F_25 ( V_227 , struct V_1 , V_199 . V_86 ) ;
F_77 ( V_2 , V_191 ) ;
}
static void F_84 ( struct V_1 * V_2 , enum V_228 type )
{
struct V_7 * V_4 = V_2 -> V_4 ;
int V_56 ;
V_2 -> V_92 = 1 ;
if ( type != V_229 ) {
for ( V_56 = 0 ; V_56 < V_4 -> V_9 ; ++ V_56 ) {
if ( V_2 -> V_82 [ V_56 ] -> V_204 )
F_85 ( & V_2 -> V_82 [ V_56 ] -> V_204 ) ;
}
}
F_86 ( V_2 -> V_136 ) ;
if ( V_2 -> V_226 )
F_87 ( & V_2 -> V_87 ) ;
if ( V_2 -> V_150 . V_2 )
F_88 ( & V_2 -> V_150 . V_154 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_2 -> V_4 -> V_9 ; ++ V_56 )
F_90 ( & V_2 -> V_82 [ V_56 ] -> V_22 ) ;
}
static int F_91 ( struct V_127 * V_128 )
{
struct V_1 * V_2 = F_5 ( V_128 ) ;
F_84 ( V_2 , V_230 ) ;
V_2 -> V_231 = 1 ;
F_89 ( V_2 ) ;
return 0 ;
}
static int F_92 ( struct V_127 * V_128 )
{
struct V_1 * V_2 = F_5 ( V_128 ) ;
V_2 -> V_231 = 0 ;
F_89 ( V_2 ) ;
F_77 ( V_2 , V_232 ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_233 * V_234 )
{
struct V_187 * V_164 ;
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_235 * V_236 = V_2 -> V_121 ;
T_1 V_237 , V_238 ;
T_1 V_239 ;
unsigned int V_171 ;
int V_240 , V_57 , V_56 ;
char * V_241 = L_33 ;
unsigned V_242 ;
unsigned V_243 ;
unsigned V_9 ;
V_2 -> V_145 = F_58 ( sizeof( * V_2 -> V_145 ) , V_244 ) ;
if ( ! V_2 -> V_145 ) {
V_57 = - V_173 ;
goto V_245;
}
V_2 -> V_83 = F_58 ( sizeof( * V_2 -> V_83 ) , V_244 ) ;
if ( ! V_2 -> V_83 ) {
V_57 = - V_173 ;
goto V_245;
}
F_94 ( & V_2 -> V_118 ) ;
V_2 -> V_36 = F_58 ( sizeof( * V_2 -> V_36 ) , V_244 ) ;
if ( ! V_2 -> V_36 ) {
V_57 = - V_173 ;
goto V_245;
}
V_57 = F_14 ( V_4 , V_2 -> V_36 ) ;
if ( V_57 < 0 ) {
V_241 = L_34 ;
goto V_245;
} else if ( V_2 -> V_36 -> V_246 > V_247 ) {
V_241 = L_35 ;
V_57 = - V_120 ;
goto V_245;
} else if ( V_2 -> V_36 -> V_246 == 0 ) {
V_241 = L_36 ;
V_57 = - V_120 ;
goto V_245;
}
V_9 = V_2 -> V_36 -> V_246 ;
F_8 ( V_236 , L_37 , V_9 ,
( V_9 == 1 ) ? L_38 : L_39 ) ;
V_2 -> V_82 = F_95 ( V_9 * sizeof( struct V_80 * ) , V_244 ) ;
if ( ! V_2 -> V_82 ) {
V_57 = - V_173 ;
goto V_245;
}
V_239 = F_13 ( V_2 -> V_36 -> V_239 ) ;
if ( F_3 ( V_4 ) ) {
V_242 = 150 ;
V_243 = 900 ;
} else {
V_242 = 100 ;
V_243 = 500 ;
}
if ( ( V_239 & V_248 ) &&
! ( F_3 ( V_4 ) ) ) {
char V_249 [ V_247 + 1 ] ;
for ( V_56 = 0 ; V_56 < V_9 ; V_56 ++ )
V_249 [ V_56 ] = V_2 -> V_36 -> V_37 . V_250 . V_251
[ ( ( V_56 + 1 ) / 8 ) ] & ( 1 << ( ( V_56 + 1 ) % 8 ) )
? 'F' : 'R' ;
V_249 [ V_9 ] = 0 ;
F_23 ( V_236 , L_40 , V_249 ) ;
} else
F_23 ( V_236 , L_41 ) ;
switch ( V_239 & V_252 ) {
case V_253 :
F_23 ( V_236 , L_42 ) ;
break;
case V_254 :
F_23 ( V_236 , L_43 ) ;
break;
case V_255 :
case V_252 :
F_23 ( V_236 , L_44 ) ;
break;
}
switch ( V_239 & V_256 ) {
case V_257 :
F_23 ( V_236 , L_45 ) ;
break;
case V_258 :
F_23 ( V_236 , L_46 ) ;
break;
case V_259 :
case V_256 :
F_23 ( V_236 , L_47 ) ;
break;
}
F_96 ( & V_2 -> V_150 . V_156 ) ;
F_97 ( & V_2 -> V_150 . V_157 ) ;
F_98 ( & V_2 -> V_150 . V_154 , F_48 ) ;
switch ( V_4 -> V_36 . V_260 ) {
case V_261 :
break;
case V_262 :
F_23 ( V_236 , L_48 ) ;
V_2 -> V_150 . V_2 = V_4 ;
break;
case V_263 :
V_57 = F_99 ( V_4 , 0 , 1 ) ;
if ( V_57 == 0 ) {
F_23 ( V_236 , L_49 ) ;
V_2 -> V_150 . V_174 = 1 ;
} else
F_31 ( V_236 , L_50 ,
V_57 ) ;
V_2 -> V_150 . V_2 = V_4 ;
break;
case V_264 :
break;
default:
F_23 ( V_236 , L_51 ,
V_4 -> V_36 . V_260 ) ;
break;
}
switch ( V_239 & V_265 ) {
case V_266 :
if ( V_4 -> V_36 . V_260 != 0 ) {
V_2 -> V_150 . V_267 = 666 ;
F_23 ( V_236 , L_52
L_53 ,
8 , V_2 -> V_150 . V_267 ) ;
}
break;
case V_268 :
V_2 -> V_150 . V_267 = 666 * 2 ;
F_23 ( V_236 , L_52
L_53 ,
16 , V_2 -> V_150 . V_267 ) ;
break;
case V_269 :
V_2 -> V_150 . V_267 = 666 * 3 ;
F_23 ( V_236 , L_52
L_53 ,
24 , V_2 -> V_150 . V_267 ) ;
break;
case V_270 :
V_2 -> V_150 . V_267 = 666 * 4 ;
F_23 ( V_236 , L_52
L_53 ,
32 , V_2 -> V_150 . V_267 ) ;
break;
}
if ( V_239 & V_271 ) {
V_2 -> V_226 = 1 ;
F_23 ( V_236 , L_54 ) ;
}
F_23 ( V_236 , L_55 ,
V_2 -> V_36 -> V_272 * 2 ) ;
V_57 = F_100 ( V_4 , V_273 , 0 , & V_237 ) ;
if ( V_57 ) {
V_241 = L_56 ;
goto V_245;
}
V_164 = F_62 ( V_4 -> V_178 ) ;
if ( V_4 == V_4 -> V_178 -> V_274 ) {
if ( V_164 -> V_275 > 0 )
V_4 -> V_276 = V_164 -> V_275 ;
else
V_4 -> V_276 = V_243 * V_9 ;
if ( V_4 -> V_276 >= V_243 )
V_2 -> V_277 = V_243 ;
else {
V_2 -> V_277 = V_4 -> V_276 ;
V_2 -> V_278 = 1 ;
}
} else if ( ( V_237 & ( 1 << V_279 ) ) == 0 ) {
int V_280 = V_4 -> V_276 -
V_2 -> V_36 -> V_281 ;
F_23 ( V_236 , L_57 ,
V_2 -> V_36 -> V_281 ) ;
V_2 -> V_278 = 1 ;
if ( V_280 < V_9 * V_242 )
F_101 ( V_236 ,
L_58
L_59 ) ;
V_2 -> V_277 = V_242 ;
} else {
V_2 -> V_277 = V_243 ;
}
if ( V_2 -> V_277 < V_243 )
F_23 ( V_236 , L_60 ,
V_2 -> V_277 ) ;
V_57 = F_70 ( V_2 , & V_237 , & V_238 ) ;
if ( V_57 < 0 ) {
V_241 = L_56 ;
goto V_245;
}
if ( V_4 -> V_8 -> V_282 . V_20 & V_283 )
F_23 ( V_236 , L_61 ,
( V_237 & V_284 )
? L_62 : L_63 ) ;
if ( ( V_239 & V_256 ) == 0 )
F_23 ( V_236 , L_64 ,
( V_237 & V_285 ) ? L_38 : L_65 ) ;
V_171 = F_102 ( V_4 , V_234 -> V_286 ) ;
V_240 = F_103 ( V_4 , V_171 , F_104 ( V_171 ) ) ;
if ( V_240 > sizeof( * V_2 -> V_145 ) )
V_240 = sizeof( * V_2 -> V_145 ) ;
V_2 -> V_136 = F_105 ( 0 , V_244 ) ;
if ( ! V_2 -> V_136 ) {
V_57 = - V_173 ;
goto V_245;
}
F_106 ( V_2 -> V_136 , V_4 , V_171 , * V_2 -> V_145 , V_240 , F_45 ,
V_2 , V_234 -> V_287 ) ;
if ( V_2 -> V_226 && V_103 )
V_2 -> V_94 [ 0 ] = V_95 ;
F_30 ( & V_288 ) ;
for ( V_56 = 0 ; V_56 < V_9 ; V_56 ++ ) {
V_57 = F_107 ( V_2 , V_56 + 1 ) ;
if ( V_57 < 0 ) {
F_31 ( V_2 -> V_121 ,
L_66 , V_56 + 1 ) ;
break;
}
}
V_4 -> V_9 = V_56 ;
for ( V_56 = 0 ; V_56 < V_4 -> V_9 ; V_56 ++ ) {
struct V_80 * V_81 = V_2 -> V_82 [ V_56 ] ;
F_108 ( & V_81 -> V_22 ) ;
}
F_32 ( & V_288 ) ;
if ( V_57 < 0 )
goto V_245;
if ( V_164 -> V_165 -> V_202 ) {
V_57 = V_164 -> V_165 -> V_202 ( V_164 , V_4 ,
& V_2 -> V_150 , V_244 ) ;
if ( V_57 < 0 ) {
V_241 = L_67 ;
goto V_245;
}
}
F_109 ( V_4 , V_2 -> V_36 ) ;
F_77 ( V_2 , V_198 ) ;
return 0 ;
V_245:
F_31 ( V_236 , L_68 ,
V_241 , V_57 ) ;
return V_57 ;
}
static void V_133 ( struct V_131 * V_131 )
{
struct V_1 * V_2 = F_25 ( V_131 , struct V_1 , V_131 ) ;
F_110 ( V_2 -> V_4 ) ;
F_111 ( F_36 ( V_2 -> V_121 ) ) ;
F_54 ( V_2 ) ;
}
static void F_112 ( struct V_127 * V_128 )
{
struct V_1 * V_2 = F_5 ( V_128 ) ;
struct V_7 * V_4 = F_113 ( V_128 ) ;
int V_72 ;
V_2 -> V_129 = 1 ;
V_2 -> error = 0 ;
F_84 ( V_2 , V_289 ) ;
F_30 ( & V_288 ) ;
F_114 ( & V_290 ) ;
V_72 = V_4 -> V_9 ;
V_4 -> V_9 = 0 ;
F_115 ( V_128 , NULL ) ;
F_116 ( & V_290 ) ;
for (; V_72 > 0 ; -- V_72 )
F_117 ( V_2 , V_72 ) ;
F_32 ( & V_288 ) ;
if ( V_2 -> V_4 -> V_14 == V_15 )
V_291 -- ;
F_118 ( V_2 -> V_136 ) ;
F_54 ( V_2 -> V_82 ) ;
F_54 ( V_2 -> V_36 ) ;
F_54 ( V_2 -> V_83 ) ;
F_54 ( V_2 -> V_145 ) ;
F_119 ( & V_128 -> V_22 , false ) ;
F_41 ( & V_2 -> V_131 , V_133 ) ;
}
static int F_120 ( struct V_127 * V_128 , const struct V_292 * V_293 )
{
struct V_294 * V_282 ;
struct V_233 * V_234 ;
struct V_7 * V_4 ;
struct V_1 * V_2 ;
V_282 = V_128 -> V_295 ;
V_4 = F_113 ( V_128 ) ;
#ifdef F_81
if ( V_4 -> V_22 . V_296 . V_297 >= 0 )
F_121 ( & V_4 -> V_22 , 0 ) ;
#endif
if ( V_4 -> V_25 ) {
F_122 ( V_4 ) ;
} else {
const struct V_162 * V_163 = F_62 ( V_4 -> V_178 ) -> V_165 ;
if ( V_163 -> V_298 && V_163 -> V_299 )
F_122 ( V_4 ) ;
}
if ( V_4 -> V_196 == V_300 ) {
F_31 ( & V_128 -> V_22 ,
L_69 ) ;
return - V_301 ;
}
#ifdef F_123
if ( V_4 -> V_25 ) {
F_101 ( & V_128 -> V_22 , L_70 ) ;
return - V_120 ;
}
#endif
if ( ( V_282 -> V_282 . V_302 != 0 ) &&
( V_282 -> V_282 . V_302 != 1 ) ) {
V_303:
F_31 ( & V_128 -> V_22 , L_71 ) ;
return - V_123 ;
}
if ( V_282 -> V_282 . V_304 != 1 )
goto V_303;
V_234 = & V_282 -> V_234 [ 0 ] . V_282 ;
if ( ! F_124 ( V_234 ) )
goto V_303;
F_8 ( & V_128 -> V_22 , L_72 ) ;
V_2 = F_95 ( sizeof( * V_2 ) , V_244 ) ;
if ( ! V_2 )
return - V_173 ;
F_125 ( & V_2 -> V_131 ) ;
V_2 -> V_121 = & V_128 -> V_22 ;
V_2 -> V_4 = V_4 ;
F_79 ( & V_2 -> V_87 , F_24 ) ;
F_79 ( & V_2 -> V_199 , NULL ) ;
F_98 ( & V_2 -> V_130 , V_305 ) ;
F_126 ( V_128 ) ;
F_127 ( V_4 ) ;
F_115 ( V_128 , V_2 ) ;
V_128 -> V_306 = 1 ;
F_119 ( & V_128 -> V_22 , true ) ;
if ( V_4 -> V_14 == V_15 )
V_291 ++ ;
if ( V_293 -> V_307 & V_308 )
V_2 -> V_309 = 1 ;
if ( F_93 ( V_2 , V_234 ) >= 0 )
return 0 ;
F_112 ( V_128 ) ;
return - V_120 ;
}
static int
F_128 ( struct V_127 * V_128 , unsigned int V_310 , void * V_311 )
{
struct V_7 * V_4 = F_113 ( V_128 ) ;
struct V_1 * V_2 = F_4 ( V_4 ) ;
switch ( V_310 ) {
case V_312 : {
struct V_313 * V_314 = V_311 ;
int V_56 ;
F_114 ( & V_290 ) ;
if ( V_4 -> V_176 <= 0 )
V_314 -> V_315 = 0 ;
else {
V_314 -> V_315 = V_4 -> V_9 ;
for ( V_56 = 0 ; V_56 < V_314 -> V_315 ; V_56 ++ ) {
if ( V_2 -> V_82 [ V_56 ] -> V_204 == NULL )
V_314 -> V_119 [ V_56 ] = 0 ;
else
V_314 -> V_119 [ V_56 ] =
V_2 -> V_82 [ V_56 ] -> V_204 -> V_176 ;
}
}
F_116 ( & V_290 ) ;
return V_314 -> V_315 + 1 ;
}
default:
return - V_316 ;
}
}
static int F_129 ( struct V_7 * V_4 , unsigned V_72 ,
struct V_317 * * * V_318 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
if ( V_4 -> V_90 == V_208 )
return - V_120 ;
if ( V_72 == 0 || V_72 > V_4 -> V_9 )
return - V_69 ;
* V_318 = & ( V_2 -> V_82 [ V_72 - 1 ] -> V_319 ) ;
return 0 ;
}
int F_130 ( struct V_7 * V_4 , unsigned V_72 ,
struct V_317 * V_320 )
{
int V_321 ;
struct V_317 * * V_322 ;
V_321 = F_129 ( V_4 , V_72 , & V_322 ) ;
if ( V_321 )
return V_321 ;
if ( * V_322 )
return - V_323 ;
* V_322 = V_320 ;
return V_321 ;
}
int F_131 ( struct V_7 * V_4 , unsigned V_72 ,
struct V_317 * V_320 )
{
int V_321 ;
struct V_317 * * V_322 ;
V_321 = F_129 ( V_4 , V_72 , & V_322 ) ;
if ( V_321 )
return V_321 ;
if ( * V_322 != V_320 )
return - V_139 ;
* V_322 = NULL ;
return V_321 ;
}
void F_132 ( struct V_7 * V_4 , struct V_317 * V_320 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
int V_324 ;
for ( V_324 = 0 ; V_324 < V_4 -> V_9 ; V_324 ++ ) {
if ( V_2 -> V_82 [ V_324 ] -> V_319 == V_320 )
V_2 -> V_82 [ V_324 ] -> V_319 = NULL ;
}
}
bool F_133 ( struct V_7 * V_11 )
{
struct V_1 * V_2 ;
if ( V_11 -> V_90 == V_208 || ! V_11 -> V_25 )
return false ;
V_2 = F_4 ( V_11 -> V_25 ) ;
return ! ! V_2 -> V_82 [ V_11 -> V_134 - 1 ] -> V_319 ;
}
static void F_134 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_4 ( V_11 ) ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_11 -> V_9 ; ++ V_56 ) {
if ( V_2 -> V_82 [ V_56 ] -> V_204 )
F_134 ( V_2 -> V_82 [ V_56 ] -> V_204 ) ;
}
if ( V_11 -> V_90 == V_325 )
V_11 -> V_326 -= V_327 ;
V_11 -> V_90 = V_208 ;
}
void F_82 ( struct V_7 * V_11 ,
enum V_328 V_329 )
{
unsigned long V_155 ;
int V_330 = - 1 ;
F_49 ( & V_290 , V_155 ) ;
if ( V_11 -> V_90 == V_208 )
;
else if ( V_329 != V_208 ) {
if ( V_11 -> V_25 ) {
if ( V_11 -> V_90 == V_325
|| V_329 == V_325 )
;
else if ( V_329 == V_91 )
V_330 = ( V_11 -> V_12 &
V_331 ) ? 0 :
V_11 -> V_8 -> V_282 . V_20 &
V_332 ;
else
V_330 = 0 ;
}
if ( V_11 -> V_90 == V_325 &&
V_329 != V_325 )
V_11 -> V_326 -= V_327 ;
else if ( V_329 == V_325 &&
V_11 -> V_90 != V_325 )
V_11 -> V_326 += V_327 ;
V_11 -> V_90 = V_329 ;
} else
F_134 ( V_11 ) ;
F_53 ( & V_290 , V_155 ) ;
if ( V_330 >= 0 )
F_135 ( & V_11 -> V_22 , V_330 ) ;
}
static void F_136 ( struct V_7 * V_11 )
{
int V_176 ;
struct V_333 * V_178 = V_11 -> V_178 ;
F_30 ( & V_178 -> V_334 ) ;
if ( V_11 -> V_335 ) {
V_176 = V_11 -> V_134 + 1 ;
F_137 ( F_67 ( V_176 , V_178 -> V_336 . V_337 ) ) ;
} else {
V_176 = F_138 ( V_178 -> V_336 . V_337 , 128 ,
V_178 -> V_338 ) ;
if ( V_176 >= 128 )
V_176 = F_138 ( V_178 -> V_336 . V_337 ,
128 , 1 ) ;
V_178 -> V_338 = ( V_176 >= 127 ? 1 : V_176 + 1 ) ;
}
if ( V_176 < 128 ) {
F_44 ( V_176 , V_178 -> V_336 . V_337 ) ;
V_11 -> V_176 = V_176 ;
}
F_32 ( & V_178 -> V_334 ) ;
}
static void F_139 ( struct V_7 * V_11 )
{
if ( V_11 -> V_176 > 0 ) {
F_56 ( V_11 -> V_176 , V_11 -> V_178 -> V_336 . V_337 ) ;
V_11 -> V_176 = - 1 ;
}
}
static void F_140 ( struct V_7 * V_11 , int V_176 )
{
if ( ! V_11 -> V_335 )
V_11 -> V_176 = V_176 ;
}
static void F_141 ( struct V_7 * V_11 )
{
struct V_187 * V_164 = F_62 ( V_11 -> V_178 ) ;
if ( V_164 -> V_165 -> V_339 && V_11 -> V_25 )
V_164 -> V_165 -> V_339 ( V_164 , V_11 ) ;
}
static void F_142 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_4 ( V_11 ) ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_11 -> V_9 ; V_56 ++ ) {
if ( V_2 -> V_82 [ V_56 ] -> V_204 )
F_85 ( & V_2 -> V_82 [ V_56 ] -> V_204 ) ;
}
}
void F_85 ( struct V_7 * * V_340 )
{
struct V_80 * V_81 = NULL ;
struct V_7 * V_11 = * V_340 ;
struct V_1 * V_2 = NULL ;
int V_72 = 1 ;
F_82 ( V_11 , V_208 ) ;
F_8 ( & V_11 -> V_22 , L_73 ,
V_11 -> V_176 ) ;
F_143 ( V_11 ) ;
F_142 ( V_11 ) ;
F_23 ( & V_11 -> V_22 , L_74 ) ;
F_144 ( V_11 , 0 ) ;
F_145 ( V_11 ) ;
if ( V_11 -> V_25 ) {
V_72 = V_11 -> V_134 ;
V_2 = F_4 ( V_11 -> V_25 ) ;
V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
F_146 ( & V_11 -> V_22 . V_341 , L_75 ) ;
F_146 ( & V_81 -> V_22 . V_341 , L_76 ) ;
if ( ! F_147 ( V_72 , V_2 -> V_342 ) )
F_148 ( & V_81 -> V_22 ) ;
}
F_149 ( & V_11 -> V_343 ) ;
F_150 ( V_11 ) ;
F_151 ( & V_11 -> V_22 ) ;
F_139 ( V_11 ) ;
F_114 ( & V_290 ) ;
* V_340 = NULL ;
F_116 ( & V_290 ) ;
if ( V_81 && F_152 ( V_72 , V_2 -> V_342 ) )
F_108 ( & V_81 -> V_22 ) ;
F_141 ( V_11 ) ;
F_153 ( & V_11 -> V_22 ) ;
}
static void F_154 ( struct V_7 * V_11 , char * V_293 , char * string )
{
if ( ! string )
return;
F_8 ( & V_11 -> V_22 , L_77 , V_293 , string ) ;
}
static void F_155 ( struct V_7 * V_11 )
{
F_8 ( & V_11 -> V_22 , L_78 ,
F_13 ( V_11 -> V_36 . V_344 ) ,
F_13 ( V_11 -> V_36 . V_345 ) ) ;
F_8 ( & V_11 -> V_22 ,
L_79 ,
V_11 -> V_36 . V_346 ,
V_11 -> V_36 . V_347 ,
V_11 -> V_36 . V_348 ) ;
F_154 ( V_11 , L_80 , V_11 -> V_349 ) ;
F_154 ( V_11 , L_81 , V_11 -> V_350 ) ;
F_154 ( V_11 , L_82 , V_11 -> V_351 ) ;
}
static inline void F_155 ( struct V_7 * V_11 ) { }
static int F_156 ( struct V_7 * V_11 )
{
int V_352 = 0 ;
#ifdef F_157
if ( ! V_11 -> V_178 -> V_353
&& V_11 -> V_354
&& V_11 -> V_25 == V_11 -> V_178 -> V_274 ) {
struct V_355 * V_282 = NULL ;
struct V_333 * V_178 = V_11 -> V_178 ;
unsigned V_72 = V_11 -> V_134 ;
V_352 = F_158 ( V_11 -> V_356 [ 0 ] ,
F_13 ( V_11 -> V_354 [ 0 ] . V_282 . V_357 ) ,
V_358 , ( void * * ) & V_282 ) ;
if ( V_352 || ! ( V_282 -> V_20 & V_359 ) )
return 0 ;
F_8 ( & V_11 -> V_22 , L_83 ,
( V_72 == V_178 -> V_360 ) ? L_38 : L_84 ) ;
if ( V_72 == V_178 -> V_360 ) {
V_178 -> V_361 = 1 ;
V_352 = F_15 ( V_11 ,
F_18 ( V_11 , 0 ) ,
V_74 , 0 ,
V_362 ,
0 , NULL , 0 ,
V_197 ) ;
if ( V_352 < 0 ) {
F_31 ( & V_11 -> V_22 , L_85 ,
V_352 ) ;
V_178 -> V_361 = 0 ;
}
} else if ( V_282 -> V_363 == sizeof
( struct V_355 ) ) {
V_352 = F_15 ( V_11 ,
F_18 ( V_11 , 0 ) ,
V_74 , 0 ,
V_364 ,
0 , NULL , 0 ,
V_197 ) ;
if ( V_352 < 0 )
F_31 ( & V_11 -> V_22 ,
L_86 ,
V_352 ) ;
}
}
#endif
return V_352 ;
}
static int F_159 ( struct V_7 * V_11 )
{
int V_352 ;
struct V_187 * V_164 = F_62 ( V_11 -> V_178 ) ;
if ( V_11 -> V_354 == NULL ) {
V_352 = F_160 ( V_11 ) ;
if ( V_352 < 0 ) {
if ( V_352 != - V_120 )
F_31 ( & V_11 -> V_22 , L_87 ,
V_352 ) ;
return V_352 ;
}
}
V_11 -> V_349 = F_161 ( V_11 , V_11 -> V_36 . V_347 ) ;
V_11 -> V_350 = F_161 ( V_11 ,
V_11 -> V_36 . V_346 ) ;
V_11 -> V_351 = F_161 ( V_11 , V_11 -> V_36 . V_348 ) ;
V_352 = F_156 ( V_11 ) ;
if ( V_352 < 0 )
return V_352 ;
if ( F_162 ( V_365 ) && V_164 -> V_366 &&
! F_163 ( V_11 ) ) {
if ( F_162 ( F_157 ) && ( V_11 -> V_178 -> V_361
|| V_11 -> V_178 -> V_353 ) ) {
V_352 = F_164 ( V_11 , V_367 ) ;
if ( V_352 < 0 )
F_23 ( & V_11 -> V_22 , L_88 , V_352 ) ;
}
return - V_368 ;
}
F_165 ( V_11 ) ;
return 0 ;
}
static void F_166 ( struct V_7 * V_11 )
{
struct V_7 * V_4 = V_11 -> V_25 ;
struct V_1 * V_2 ;
T_3 V_119 = V_11 -> V_134 ;
T_1 V_239 ;
bool V_369 = true ;
if ( ! V_4 )
return;
V_2 = F_4 ( V_11 -> V_25 ) ;
switch ( V_2 -> V_82 [ V_11 -> V_134 - 1 ] -> V_370 ) {
case V_371 :
V_11 -> V_369 = V_372 ;
return;
case V_373 :
case V_374 :
V_11 -> V_369 = V_375 ;
return;
default:
break;
}
V_239 = F_13 ( V_2 -> V_36 -> V_239 ) ;
if ( ! ( V_239 & V_248 ) )
return;
if ( F_3 ( V_4 ) ) {
if ( F_13 ( V_2 -> V_36 -> V_37 . V_38 . V_251 )
& ( 1 << V_119 ) )
V_369 = false ;
} else {
if ( V_2 -> V_36 -> V_37 . V_250 . V_251 [ V_119 / 8 ] & ( 1 << ( V_119 % 8 ) ) )
V_369 = false ;
}
if ( V_369 )
V_11 -> V_369 = V_372 ;
else
V_11 -> V_369 = V_375 ;
}
int F_167 ( struct V_7 * V_11 )
{
int V_352 ;
if ( V_11 -> V_25 ) {
F_168 ( & V_11 -> V_22 , 0 ) ;
}
F_169 ( & V_11 -> V_22 ) ;
F_170 ( & V_11 -> V_22 ) ;
F_171 ( & V_11 -> V_22 ) ;
F_172 ( & V_11 -> V_22 ) ;
F_173 ( V_11 ) ;
V_352 = F_159 ( V_11 ) ;
if ( V_352 < 0 )
goto V_245;
F_23 ( & V_11 -> V_22 , L_89 ,
V_11 -> V_176 , V_11 -> V_178 -> V_376 ,
( ( ( V_11 -> V_178 -> V_376 - 1 ) * 128 ) + ( V_11 -> V_176 - 1 ) ) ) ;
V_11 -> V_22 . V_377 = F_174 ( V_378 ,
( ( ( V_11 -> V_178 -> V_376 - 1 ) * 128 ) + ( V_11 -> V_176 - 1 ) ) ) ;
F_155 ( V_11 ) ;
if ( V_11 -> V_351 )
F_175 ( V_11 -> V_351 , strlen ( V_11 -> V_351 ) ) ;
if ( V_11 -> V_349 )
F_175 ( V_11 -> V_349 , strlen ( V_11 -> V_349 ) ) ;
if ( V_11 -> V_350 )
F_175 ( V_11 -> V_350 ,
strlen ( V_11 -> V_350 ) ) ;
F_176 ( & V_11 -> V_22 ) ;
if ( V_11 -> V_25 )
F_166 ( V_11 ) ;
V_352 = F_177 ( & V_11 -> V_22 ) ;
if ( V_352 ) {
F_31 ( & V_11 -> V_22 , L_90 , V_352 ) ;
goto V_245;
}
if ( V_11 -> V_25 ) {
struct V_1 * V_2 = F_4 ( V_11 -> V_25 ) ;
int V_72 = V_11 -> V_134 ;
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
V_352 = F_178 ( & V_11 -> V_22 . V_341 ,
& V_81 -> V_22 . V_341 , L_75 ) ;
if ( V_352 )
goto V_245;
V_352 = F_178 ( & V_81 -> V_22 . V_341 ,
& V_11 -> V_22 . V_341 , L_76 ) ;
if ( V_352 ) {
F_146 ( & V_11 -> V_22 . V_341 , L_75 ) ;
goto V_245;
}
if ( ! F_147 ( V_72 , V_2 -> V_342 ) )
F_148 ( & V_81 -> V_22 ) ;
}
( void ) F_179 ( & V_11 -> V_22 , & V_11 -> V_343 , V_11 ) ;
F_180 ( V_11 ) ;
F_181 ( & V_11 -> V_22 ) ;
return V_352 ;
V_245:
F_82 ( V_11 , V_208 ) ;
F_182 ( & V_11 -> V_22 ) ;
F_183 ( & V_11 -> V_22 ) ;
return V_352 ;
}
int F_184 ( struct V_7 * V_379 )
{
F_143 ( V_379 ) ;
if ( V_379 -> V_380 == 0 )
goto V_381;
V_379 -> V_380 = 0 ;
F_185 ( V_379 , - 1 ) ;
V_381:
F_150 ( V_379 ) ;
return 0 ;
}
int F_186 ( struct V_7 * V_379 )
{
int V_382 = 0 , V_383 ;
F_143 ( V_379 ) ;
if ( V_379 -> V_380 == 1 )
goto V_384;
V_382 = F_187 ( V_379 ) ;
if ( V_382 < 0 ) {
F_31 ( & V_379 -> V_22 ,
L_91 , V_382 ) ;
goto V_385;
}
if ( V_379 -> V_335 ) {
V_382 = F_188 ( V_379 , sizeof( V_379 -> V_36 ) ) ;
if ( V_382 < 0 ) {
F_31 ( & V_379 -> V_22 , L_92
L_93 , V_382 ) ;
goto V_386;
}
}
V_379 -> V_380 = 1 ;
V_383 = F_189 ( V_379 ) ;
if ( V_383 >= 0 ) {
V_382 = F_185 ( V_379 , V_383 ) ;
if ( V_382 ) {
F_31 ( & V_379 -> V_22 ,
L_94 , V_383 , V_382 ) ;
}
}
F_8 ( & V_379 -> V_22 , L_95 ) ;
V_386:
F_190 ( V_379 ) ;
V_385:
V_384:
F_150 ( V_379 ) ;
return V_382 ;
}
static int F_191 ( struct V_7 * V_4 , int V_387 )
{
int V_388 ;
T_2 V_389 ;
int V_56 ;
struct V_390 * V_391 = V_4 -> V_17 -> V_391 ;
if ( ! V_391 )
return 0 ;
V_388 = F_7 ( V_391 -> V_20 ) &
V_392 ;
for ( V_56 = 0 ; V_56 <= V_388 ; V_56 ++ ) {
V_389 = F_7 ( V_391 -> V_393 [ V_56 ] ) ;
if ( V_387 == ( V_389 & V_394 ) )
return ! ! ( V_389 & V_395 ) ;
}
return 0 ;
}
static unsigned F_192 ( struct V_1 * V_2 )
{
struct V_187 * V_164 ;
if ( V_2 -> V_4 -> V_25 != NULL )
return 0 ;
V_164 = F_62 ( V_2 -> V_4 -> V_178 ) ;
return V_164 -> V_396 ;
}
static bool F_193 ( struct V_7 * V_11 , int V_397 )
{
if ( V_11 -> V_14 >= V_52 )
return false ;
return F_194 ( V_397 ) ;
}
static bool F_195 ( struct V_1 * V_2 , int V_72 ,
T_1 V_3 )
{
T_1 V_398 ;
if ( ! F_3 ( V_2 -> V_4 ) )
return false ;
if ( F_67 ( V_72 , V_2 -> V_399 ) )
return true ;
V_398 = V_3 & V_220 ;
return V_398 == V_400
|| V_398 == V_401 ;
}
static int F_196 ( struct V_1 * V_2 , int V_72 ,
struct V_7 * V_11 , unsigned int V_189 , bool V_402 )
{
int V_403 , V_57 ;
T_1 V_3 ;
T_1 V_205 ;
T_2 V_404 = 0 ;
for ( V_403 = 0 ;
V_403 < V_405 ;
V_403 += V_189 ) {
F_68 ( V_189 ) ;
if ( F_2 ( V_2 -> V_4 ) )
V_57 = F_29 ( V_2 , V_72 ,
V_406 ,
& V_3 , & V_205 ,
& V_404 ) ;
else
V_57 = F_33 ( V_2 , V_72 , & V_3 ,
& V_205 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( ! ( V_3 & V_407 ) &&
( V_3 & V_206 ) )
break;
if ( V_403 >= 2 * V_408 )
V_189 = V_409 ;
F_23 ( & V_2 -> V_82 [ V_72 - 1 ] -> V_22 ,
L_96 ,
V_402 ? L_97 : L_38 , V_189 ) ;
}
if ( ( V_3 & V_407 ) )
return - V_323 ;
if ( F_195 ( V_2 , V_72 , V_3 ) )
return - V_410 ;
if ( ! ( V_3 & V_206 ) )
return - V_410 ;
if ( ! F_3 ( V_2 -> V_4 ) &&
( V_205 & V_210 ) )
return - V_410 ;
if ( ! ( V_3 & V_207 ) )
return - V_323 ;
if ( ! V_11 )
return 0 ;
if ( F_192 ( V_2 ) )
V_11 -> V_14 = V_411 ;
else if ( F_2 ( V_2 -> V_4 ) &&
F_191 ( V_2 -> V_4 , V_404 &
V_412 ) )
V_11 -> V_14 = V_413 ;
else if ( F_3 ( V_2 -> V_4 ) )
V_11 -> V_14 = V_52 ;
else if ( V_3 & V_5 )
V_11 -> V_14 = V_15 ;
else if ( V_3 & V_6 )
V_11 -> V_14 = V_414 ;
else
V_11 -> V_14 = V_16 ;
return 0 ;
}
static int F_197 ( struct V_1 * V_2 , int V_72 ,
struct V_7 * V_11 , unsigned int V_189 , bool V_402 )
{
int V_56 , V_83 ;
T_1 V_205 , V_3 ;
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
if ( ! F_3 ( V_2 -> V_4 ) ) {
if ( V_402 ) {
F_31 ( V_2 -> V_121 , L_98
L_99 ) ;
return - V_69 ;
}
F_198 ( & V_415 ) ;
} else if ( ! V_402 ) {
if ( F_33 ( V_2 , V_72 , & V_3 , & V_205 ) == 0 )
if ( F_195 ( V_2 , V_72 ,
V_3 ) )
V_402 = true ;
}
F_56 ( V_72 , V_2 -> V_399 ) ;
for ( V_56 = 0 ; V_56 < V_416 ; V_56 ++ ) {
V_83 = F_20 ( V_2 -> V_4 , V_72 , ( V_402 ?
V_417 :
V_418 ) ) ;
if ( V_83 == - V_120 ) {
;
} else if ( V_83 ) {
F_31 ( & V_81 -> V_22 ,
L_100 ,
V_402 ? L_97 : L_38 , V_83 ) ;
} else {
V_83 = F_196 ( V_2 , V_72 , V_11 , V_189 ,
V_402 ) ;
if ( V_83 && V_83 != - V_410 && V_83 != - V_120 )
F_23 ( V_2 -> V_121 ,
L_101 ,
V_83 ) ;
}
if ( V_83 == 0 || V_83 == - V_410 || V_83 == - V_120 ) {
F_19 ( V_2 -> V_4 , V_72 ,
V_215 ) ;
if ( ! F_3 ( V_2 -> V_4 ) )
goto V_419;
F_19 ( V_2 -> V_4 , V_72 ,
V_217 ) ;
F_19 ( V_2 -> V_4 , V_72 ,
V_420 ) ;
F_19 ( V_2 -> V_4 , V_72 ,
V_211 ) ;
if ( F_33 ( V_2 , V_72 ,
& V_3 , & V_205 ) < 0 )
goto V_419;
if ( ! F_195 ( V_2 , V_72 ,
V_3 ) )
goto V_419;
if ( ! V_402 ) {
F_23 ( & V_81 -> V_22 ,
L_102 ) ;
V_402 = true ;
}
}
F_23 ( & V_81 -> V_22 ,
L_103 ,
V_402 ? L_97 : L_38 ) ;
V_189 = V_409 ;
}
F_31 ( & V_81 -> V_22 , L_104 ) ;
V_419:
if ( V_83 == 0 ) {
F_68 ( 10 + 40 ) ;
if ( V_11 ) {
struct V_187 * V_164 = F_62 ( V_11 -> V_178 ) ;
F_140 ( V_11 , 0 ) ;
if ( V_164 -> V_165 -> V_421 )
V_164 -> V_165 -> V_421 ( V_164 , V_11 ) ;
F_82 ( V_11 , V_422 ) ;
}
} else {
if ( V_11 )
F_82 ( V_11 , V_208 ) ;
}
if ( ! F_3 ( V_2 -> V_4 ) )
F_199 ( & V_415 ) ;
return V_83 ;
}
static int F_200 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_57 = 0 ;
if ( F_3 ( V_2 -> V_4 ) ) {
if ( V_3 & V_423 )
V_57 = 1 ;
} else {
if ( V_3 & V_424 )
V_57 = 1 ;
}
return V_57 ;
}
static void F_201 ( struct V_80 * V_81 )
__acquires( &port_dev->status_lock
static void F_202 ( struct V_80 * V_81 )
__releases( &port_dev->status_lock
static int F_203 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_57 = 0 ;
if ( F_3 ( V_2 -> V_4 ) ) {
if ( ( V_3 & V_220 )
== V_425 )
V_57 = 1 ;
} else {
if ( V_3 & V_426 )
V_57 = 1 ;
}
return V_57 ;
}
static int F_204 ( struct V_7 * V_11 ,
struct V_1 * V_2 , int V_72 ,
int V_83 , T_1 V_205 , T_1 V_3 )
{
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
int V_427 = 3 ;
V_397:
if ( V_83 == 0 && V_11 -> V_223
&& F_195 ( V_2 , V_72 , V_3 ) ) {
;
}
else if ( V_83 || F_203 ( V_2 , V_3 ) ||
! F_200 ( V_2 , V_3 ) ) {
if ( V_83 >= 0 )
V_83 = - V_120 ;
} else if ( ! ( V_3 & V_206 ) ) {
if ( V_427 -- ) {
F_205 ( 200 , 300 ) ;
V_83 = F_33 ( V_2 , V_72 , & V_3 ,
& V_205 ) ;
goto V_397;
}
V_83 = - V_120 ;
}
else if ( ! ( V_3 & V_207 ) && ! V_11 -> V_223 ) {
if ( V_11 -> V_222 )
V_11 -> V_223 = 1 ;
else
V_83 = - V_120 ;
}
if ( V_83 ) {
F_23 ( & V_81 -> V_22 , L_105 ,
V_205 , V_3 , V_83 ) ;
} else if ( V_11 -> V_223 ) {
if ( V_205 & V_210 )
F_19 ( V_2 -> V_4 , V_72 ,
V_211 ) ;
if ( V_205 & V_212 )
F_19 ( V_2 -> V_4 , V_72 ,
V_213 ) ;
}
return V_83 ;
}
int F_206 ( struct V_7 * V_11 )
{
struct V_187 * V_164 = F_62 ( V_11 -> V_178 ) ;
if ( ! F_207 ( V_164 -> V_428 . V_274 ) ||
! F_207 ( V_11 ) )
return 0 ;
if ( ! V_11 -> V_8 )
return 0 ;
return F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_71 , V_273 ,
V_429 , 0 , NULL , 0 ,
V_197 ) ;
}
void F_208 ( struct V_7 * V_11 )
{
struct V_187 * V_164 = F_62 ( V_11 -> V_178 ) ;
if ( ! F_207 ( V_164 -> V_428 . V_274 ) ||
! F_207 ( V_11 ) )
return;
if ( ! V_11 -> V_8 )
return;
F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_74 , V_273 ,
V_429 , 0 , NULL , 0 ,
V_197 ) ;
}
static int F_209 ( struct V_7 * V_11 )
{
if ( V_11 -> V_14 < V_52 )
return F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_74 , V_273 ,
V_430 , 0 , NULL , 0 ,
V_197 ) ;
else
return F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_74 , V_431 ,
V_432 ,
V_433 |
V_434 ,
NULL , 0 , V_197 ) ;
}
static int F_210 ( struct V_7 * V_11 )
{
if ( V_11 -> V_14 < V_52 )
return F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_71 , V_273 ,
V_430 , 0 , NULL , 0 ,
V_197 ) ;
else
return F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_74 , V_431 ,
V_432 , 0 , NULL , 0 ,
V_197 ) ;
}
static unsigned F_211 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_4 ( V_11 ) ;
return V_11 -> V_435 +
( V_2 ? V_2 -> F_211 : 0 ) ;
}
int F_164 ( struct V_7 * V_11 , T_4 V_436 )
{
struct V_1 * V_2 = F_4 ( V_11 -> V_25 ) ;
struct V_80 * V_81 = V_2 -> V_82 [ V_11 -> V_134 - 1 ] ;
int V_72 = V_11 -> V_134 ;
int V_83 ;
bool V_437 = true ;
F_201 ( V_81 ) ;
if ( V_11 -> V_435 ) {
V_83 = F_209 ( V_11 ) ;
if ( V_83 ) {
F_23 ( & V_11 -> V_22 , L_106 ,
V_83 ) ;
if ( F_212 ( V_436 ) )
goto V_438;
}
}
if ( V_11 -> V_439 == 1 )
F_213 ( V_11 , 0 ) ;
if ( F_206 ( V_11 ) ) {
F_31 ( & V_11 -> V_22 , L_107 ) ;
V_83 = - V_173 ;
if ( F_212 ( V_436 ) )
goto V_440;
}
if ( F_214 ( V_11 ) ) {
F_31 ( & V_11 -> V_22 , L_108 ) ;
V_83 = - V_173 ;
if ( F_212 ( V_436 ) )
goto V_441;
}
if ( F_3 ( V_2 -> V_4 ) )
V_83 = F_71 ( V_2 , V_72 , V_425 ) ;
else if ( F_212 ( V_436 ) || F_211 ( V_11 ) > 0 )
V_83 = F_20 ( V_2 -> V_4 , V_72 ,
V_442 ) ;
else {
V_437 = false ;
V_83 = 0 ;
}
if ( V_83 ) {
F_23 ( & V_81 -> V_22 , L_109 , V_83 ) ;
F_215 ( V_11 ) ;
V_441:
F_208 ( V_11 ) ;
V_440:
if ( V_11 -> V_443 == 1 )
F_213 ( V_11 , 1 ) ;
if ( V_11 -> V_435 )
( void ) F_210 ( V_11 ) ;
V_438:
if ( ! F_212 ( V_436 ) )
V_83 = 0 ;
} else {
F_23 ( & V_11 -> V_22 , L_110 ,
( F_212 ( V_436 ) ? L_111 : L_38 ) ,
V_11 -> V_435 ) ;
if ( V_437 ) {
V_11 -> F_203 = 1 ;
F_68 ( 10 ) ;
}
F_82 ( V_11 , V_325 ) ;
}
if ( V_83 == 0 && ! V_11 -> V_435 && V_11 -> V_222
&& F_152 ( V_72 , V_2 -> V_342 ) )
F_216 ( & V_81 -> V_22 ) ;
F_180 ( V_2 -> V_4 ) ;
F_202 ( V_81 ) ;
return V_83 ;
}
static int F_217 ( struct V_7 * V_11 )
{
int V_83 = 0 ;
T_1 V_444 = 0 ;
F_23 ( & V_11 -> V_22 , L_112 ,
V_11 -> V_223 ? L_113 : L_114 ) ;
F_82 ( V_11 , V_11 -> V_8
? V_91
: V_445 ) ;
if ( V_11 -> V_223 ) {
V_446:
if ( V_11 -> V_12 & V_447 )
V_83 = - V_120 ;
else
V_83 = F_218 ( V_11 ) ;
}
if ( V_83 == 0 ) {
V_444 = 0 ;
V_83 = F_100 ( V_11 , V_273 , 0 , & V_444 ) ;
if ( V_83 && ! V_11 -> V_223 && V_11 -> V_222 ) {
F_23 ( & V_11 -> V_22 , L_115 ) ;
V_11 -> V_223 = 1 ;
goto V_446;
}
}
if ( V_83 ) {
F_23 ( & V_11 -> V_22 , L_116 ,
V_83 ) ;
} else if ( V_11 -> V_8 && ! V_11 -> V_223 ) {
if ( V_11 -> V_14 < V_52 ) {
if ( V_444 & ( 1 << V_430 ) )
V_83 = F_210 ( V_11 ) ;
} else {
V_83 = F_100 ( V_11 , V_431 , 0 ,
& V_444 ) ;
if ( ! V_83 && V_444 & ( V_448
| V_449 ) )
V_83 = F_210 ( V_11 ) ;
}
if ( V_83 )
F_23 ( & V_11 -> V_22 ,
L_117 ,
V_83 ) ;
V_83 = 0 ;
}
return V_83 ;
}
static int F_219 ( struct V_7 * V_11 ,
struct V_1 * V_2 , int * V_72 ,
T_1 * V_205 , T_1 * V_3 )
{
int V_83 = 0 , V_450 = 0 ;
while ( V_450 < 2000 ) {
if ( V_83 || * V_3 & V_206 )
break;
F_68 ( 20 ) ;
V_450 += 20 ;
V_83 = F_33 ( V_2 , * V_72 , V_3 , V_205 ) ;
}
F_23 ( & V_11 -> V_22 , L_118 , V_450 ) ;
return V_83 ;
}
int F_220 ( struct V_7 * V_11 , T_4 V_436 )
{
struct V_1 * V_2 = F_4 ( V_11 -> V_25 ) ;
struct V_80 * V_81 = V_2 -> V_82 [ V_11 -> V_134 - 1 ] ;
int V_72 = V_11 -> V_134 ;
int V_83 ;
T_1 V_205 , V_3 ;
if ( ! F_147 ( V_72 , V_2 -> V_342 ) ) {
V_83 = F_148 ( & V_81 -> V_22 ) ;
if ( V_83 < 0 ) {
F_23 ( & V_11 -> V_22 , L_119 ,
V_83 ) ;
return V_83 ;
}
}
F_201 ( V_81 ) ;
V_83 = F_33 ( V_2 , V_72 , & V_3 , & V_205 ) ;
if ( V_83 == 0 && ! F_203 ( V_2 , V_3 ) )
goto V_451;
if ( F_3 ( V_2 -> V_4 ) )
V_83 = F_71 ( V_2 , V_72 , V_221 ) ;
else
V_83 = F_19 ( V_2 -> V_4 ,
V_72 , V_442 ) ;
if ( V_83 ) {
F_23 ( & V_81 -> V_22 , L_120 , V_83 ) ;
} else {
F_23 ( & V_11 -> V_22 , L_121 ,
( F_212 ( V_436 ) ? L_111 : L_38 ) ) ;
F_68 ( V_452 ) ;
V_83 = F_33 ( V_2 , V_72 , & V_3 , & V_205 ) ;
F_68 ( 10 ) ;
}
V_451:
if ( V_83 == 0 ) {
V_11 -> F_203 = 0 ;
if ( F_3 ( V_2 -> V_4 ) ) {
if ( V_205 & V_453 )
F_19 ( V_2 -> V_4 , V_72 ,
V_420 ) ;
} else {
if ( V_205 & V_454 )
F_19 ( V_2 -> V_4 , V_72 ,
V_455 ) ;
}
}
if ( V_11 -> V_222 )
V_83 = F_219 ( V_11 , V_2 , & V_72 , & V_205 ,
& V_3 ) ;
V_83 = F_204 ( V_11 ,
V_2 , V_72 , V_83 , V_205 , V_3 ) ;
if ( V_83 == 0 )
V_83 = F_217 ( V_11 ) ;
if ( V_83 < 0 ) {
F_23 ( & V_11 -> V_22 , L_120 , V_83 ) ;
F_72 ( V_2 , V_72 ) ;
} else {
if ( V_11 -> V_443 == 1 )
F_213 ( V_11 , 1 ) ;
F_208 ( V_11 ) ;
F_215 ( V_11 ) ;
}
F_202 ( V_81 ) ;
return V_83 ;
}
int F_221 ( struct V_7 * V_11 )
{
int V_83 = 0 ;
F_143 ( V_11 ) ;
if ( V_11 -> V_90 == V_325 ) {
F_23 ( & V_11 -> V_22 , L_121 , L_122 ) ;
V_83 = F_187 ( V_11 ) ;
if ( V_83 == 0 ) {
F_190 ( V_11 ) ;
}
}
F_150 ( V_11 ) ;
return V_83 ;
}
static int F_222 ( struct V_1 * V_2 , unsigned int V_119 ,
T_1 V_3 , T_1 V_205 )
__must_hold( &port_dev->status_lock
static int F_223 ( struct V_1 * V_2 )
{
int V_72 ;
for ( V_72 = 1 ; V_72 <= V_2 -> V_4 -> V_9 ; ++ V_72 ) {
T_1 V_3 , V_205 ;
int V_83 ;
V_83 = F_33 ( V_2 , V_72 , & V_3 , & V_205 ) ;
if ( ! V_83 && V_205 )
return 1 ;
}
return 0 ;
}
static int F_224 ( struct V_127 * V_128 , T_4 V_436 )
{
struct V_1 * V_2 = F_5 ( V_128 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
unsigned V_72 ;
int V_83 ;
V_2 -> F_211 = 0 ;
for ( V_72 = 1 ; V_72 <= V_4 -> V_9 ; V_72 ++ ) {
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
struct V_7 * V_11 = V_81 -> V_204 ;
if ( V_11 && V_11 -> V_456 ) {
F_101 ( & V_81 -> V_22 , L_123 ,
F_225 ( & V_11 -> V_22 ) ) ;
if ( F_212 ( V_436 ) )
return - V_323 ;
}
if ( V_11 )
V_2 -> F_211 +=
F_211 ( V_11 ) ;
}
if ( V_4 -> V_435 && V_2 -> V_309 ) {
if ( F_223 ( V_2 ) ) {
if ( F_212 ( V_436 ) )
return - V_323 ;
F_226 ( & V_4 -> V_22 , 2000 ) ;
}
}
if ( F_3 ( V_4 ) && V_4 -> V_435 ) {
for ( V_72 = 1 ; V_72 <= V_4 -> V_9 ; V_72 ++ ) {
V_83 = F_20 ( V_4 ,
V_72 |
V_457 |
V_458 |
V_459 ,
V_460 ) ;
}
}
F_23 ( & V_128 -> V_22 , L_112 , V_122 ) ;
F_84 ( V_2 , V_229 ) ;
return 0 ;
}
static int F_227 ( struct V_127 * V_128 )
{
struct V_1 * V_2 = F_5 ( V_128 ) ;
F_23 ( & V_128 -> V_22 , L_112 , V_122 ) ;
F_77 ( V_2 , V_194 ) ;
return 0 ;
}
static int F_228 ( struct V_127 * V_128 )
{
struct V_1 * V_2 = F_5 ( V_128 ) ;
F_23 ( & V_128 -> V_22 , L_112 , V_122 ) ;
F_77 ( V_2 , V_201 ) ;
return 0 ;
}
void F_229 ( struct V_7 * V_461 )
{
F_101 ( & V_461 -> V_22 , L_124 ) ;
V_461 -> V_223 = 1 ;
}
static int F_230 ( struct V_7 * V_11 , enum V_462 V_90 )
{
struct V_463 * V_464 ;
unsigned long long V_465 ;
unsigned long long V_466 ;
unsigned long long V_467 ;
unsigned long long V_468 ;
int V_57 ;
if ( V_11 -> V_90 != V_91 )
return 0 ;
V_465 = F_231 ( V_11 -> V_53 . V_46 , 1000 ) ;
V_466 = F_231 ( V_11 -> V_53 . V_43 , 1000 ) ;
V_467 = F_231 ( V_11 -> V_54 . V_46 , 1000 ) ;
V_468 = F_231 ( V_11 -> V_54 . V_43 , 1000 ) ;
if ( ( V_90 == V_469 &&
( V_465 > V_470 ||
V_466 > V_470 ) ) ||
( V_90 == V_471 &&
( V_467 > V_472 ||
V_468 > V_472 ) ) ) {
F_23 ( & V_11 -> V_22 , L_125 ,
V_473 [ V_90 ] , V_465 , V_466 ) ;
return - V_69 ;
}
if ( V_465 > V_470 )
V_465 = V_470 ;
if ( V_466 > V_470 )
V_466 = V_470 ;
if ( V_467 > V_472 )
V_467 = V_472 ;
if ( V_468 > V_472 )
V_468 = V_472 ;
V_464 = F_58 ( sizeof *( V_464 ) , V_203 ) ;
if ( ! V_464 )
return - V_173 ;
V_464 -> V_465 = V_465 ;
V_464 -> V_466 = V_466 ;
V_464 -> V_467 = F_232 ( V_467 ) ;
V_464 -> V_468 = F_232 ( V_468 ) ;
V_57 = F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_474 ,
V_273 ,
0 , 0 ,
V_464 , sizeof *( V_464 ) ,
V_197 ) ;
F_54 ( V_464 ) ;
return V_57 ;
}
static int F_233 ( struct V_7 * V_11 ,
enum V_462 V_90 , bool V_475 )
{
int V_57 ;
int V_70 ;
switch ( V_90 ) {
case V_469 :
V_70 = V_476 ;
break;
case V_471 :
V_70 = V_477 ;
break;
default:
F_101 ( & V_11 -> V_22 , L_126 ,
V_122 , V_475 ? L_127 : L_128 ) ;
return - V_69 ;
}
if ( V_11 -> V_90 != V_91 ) {
F_23 ( & V_11 -> V_22 , L_129
L_130 ,
V_122 , V_475 ? L_127 : L_128 ,
V_473 [ V_90 ] ) ;
return 0 ;
}
if ( V_475 ) {
V_57 = F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_74 ,
V_273 ,
V_70 ,
0 , NULL , 0 ,
V_197 ) ;
} else {
V_57 = F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_71 ,
V_273 ,
V_70 ,
0 , NULL , 0 ,
V_197 ) ;
}
if ( V_57 < 0 ) {
F_101 ( & V_11 -> V_22 , L_131 ,
V_475 ? L_132 : L_133 ,
V_473 [ V_90 ] ) ;
return - V_323 ;
}
return 0 ;
}
static int F_234 ( struct V_7 * V_11 ,
enum V_462 V_90 , int V_478 )
{
int V_57 ;
int V_70 ;
switch ( V_90 ) {
case V_469 :
V_70 = V_479 ;
break;
case V_471 :
V_70 = V_480 ;
break;
default:
F_101 ( & V_11 -> V_22 , L_134 ,
V_122 ) ;
return - V_69 ;
}
if ( V_90 == V_469 && V_478 > V_481 &&
V_478 != V_482 ) {
F_101 ( & V_11 -> V_22 , L_135
L_136 ,
V_473 [ V_90 ] , V_478 ) ;
return - V_69 ;
}
V_57 = F_20 ( V_11 -> V_25 ,
F_235 ( V_478 ) | V_11 -> V_134 ,
V_70 ) ;
if ( V_57 < 0 ) {
F_101 ( & V_11 -> V_22 , L_137
L_138 , V_473 [ V_90 ] ,
V_478 , V_57 ) ;
return - V_323 ;
}
if ( V_90 == V_469 )
V_11 -> V_53 . V_478 = V_478 ;
else
V_11 -> V_54 . V_478 = V_478 ;
return 0 ;
}
static void F_236 ( struct V_187 * V_164 , struct V_7 * V_11 ,
enum V_462 V_90 )
{
int V_478 , V_57 ;
T_5 V_483 = V_11 -> V_17 -> V_21 -> V_23 ;
T_6 V_484 = V_11 -> V_17 -> V_21 -> V_24 ;
if ( ( V_90 == V_469 && V_483 == 0 ) ||
( V_90 == V_471 && V_484 == 0 ) )
return;
V_57 = F_230 ( V_11 , V_90 ) ;
if ( V_57 < 0 ) {
F_101 ( & V_11 -> V_22 , L_139 ,
V_473 [ V_90 ] ) ;
return;
}
V_478 = V_164 -> V_165 -> V_485 ( V_164 , V_11 , V_90 ) ;
if ( V_478 == 0 )
return;
if ( V_478 < 0 ) {
F_101 ( & V_11 -> V_22 , L_140
L_141 , V_473 [ V_90 ] ,
V_478 ) ;
return;
}
if ( F_234 ( V_11 , V_90 , V_478 ) ) {
V_164 -> V_165 -> V_486 ( V_164 , V_11 , V_90 ) ;
} else {
if ( V_11 -> V_8 )
F_233 ( V_11 , V_90 , true ) ;
if ( V_90 == V_469 )
V_11 -> V_487 = 1 ;
else if ( V_90 == V_471 )
V_11 -> V_488 = 1 ;
}
}
static int F_237 ( struct V_187 * V_164 , struct V_7 * V_11 ,
enum V_462 V_90 )
{
switch ( V_90 ) {
case V_469 :
case V_471 :
break;
default:
F_101 ( & V_11 -> V_22 , L_142 ,
V_122 ) ;
return - V_69 ;
}
if ( F_234 ( V_11 , V_90 , 0 ) )
return - V_323 ;
F_233 ( V_11 , V_90 , false ) ;
if ( V_164 -> V_165 -> V_486 ( V_164 , V_11 , V_90 ) )
F_101 ( & V_11 -> V_22 , L_143
L_144 ,
V_473 [ V_90 ] ) ;
if ( V_90 == V_469 )
V_11 -> V_487 = 0 ;
else if ( V_90 == V_471 )
V_11 -> V_488 = 0 ;
return 0 ;
}
int F_238 ( struct V_7 * V_11 )
{
struct V_187 * V_164 ;
if ( ! V_11 || ! V_11 -> V_25 ||
V_11 -> V_14 < V_52 ||
! V_11 -> V_26 ||
V_11 -> V_90 < V_422 )
return 0 ;
V_164 = F_62 ( V_11 -> V_178 ) ;
if ( ! V_164 || ! V_164 -> V_165 -> V_486 )
return 0 ;
V_11 -> V_489 ++ ;
if ( ( V_11 -> V_53 . V_478 == 0 && V_11 -> V_54 . V_478 == 0 ) )
return 0 ;
if ( F_237 ( V_164 , V_11 , V_469 ) )
goto V_490;
if ( F_237 ( V_164 , V_11 , V_471 ) )
goto V_490;
return 0 ;
V_490:
F_239 ( V_11 ) ;
return - V_323 ;
}
int F_214 ( struct V_7 * V_11 )
{
struct V_187 * V_164 = F_62 ( V_11 -> V_178 ) ;
int V_57 ;
if ( ! V_164 )
return - V_69 ;
F_30 ( V_164 -> V_491 ) ;
V_57 = F_238 ( V_11 ) ;
F_32 ( V_164 -> V_491 ) ;
return V_57 ;
}
void F_239 ( struct V_7 * V_11 )
{
struct V_187 * V_164 ;
struct V_1 * V_2 ;
struct V_80 * V_81 ;
if ( ! V_11 || ! V_11 -> V_25 ||
V_11 -> V_14 < V_52 ||
! V_11 -> V_26 ||
V_11 -> V_90 < V_422 )
return;
V_11 -> V_489 -- ;
V_164 = F_62 ( V_11 -> V_178 ) ;
if ( ! V_164 || ! V_164 -> V_165 -> V_485 ||
! V_164 -> V_165 -> V_486 )
return;
if ( V_11 -> V_489 > 0 )
return;
V_2 = F_4 ( V_11 -> V_25 ) ;
if ( ! V_2 )
return;
V_81 = V_2 -> V_82 [ V_11 -> V_134 - 1 ] ;
if ( V_81 -> V_492 )
F_236 ( V_164 , V_11 , V_469 ) ;
if ( V_81 -> V_493 )
F_236 ( V_164 , V_11 , V_471 ) ;
}
void F_215 ( struct V_7 * V_11 )
{
struct V_187 * V_164 = F_62 ( V_11 -> V_178 ) ;
if ( ! V_164 )
return;
F_30 ( V_164 -> V_491 ) ;
F_239 ( V_11 ) ;
F_32 ( V_164 -> V_491 ) ;
}
static void F_240 ( struct V_1 * V_2 ,
struct V_80 * V_81 )
{
struct V_7 * V_11 = V_81 -> V_204 ;
int V_57 ;
if ( V_11 && V_11 -> F_203 && V_11 -> V_435 ) {
V_57 = F_71 ( V_2 , V_81 -> V_134 ,
V_221 ) ;
if ( ! V_57 ) {
F_68 ( V_452 ) ;
V_57 = F_210 ( V_11 ) ;
}
if ( V_57 )
F_101 ( & V_11 -> V_22 ,
L_145 ) ;
V_11 -> V_435 = 0 ;
}
}
static inline void F_240 ( struct V_1 * V_2 ,
struct V_80 * V_81 ) { }
int F_238 ( struct V_7 * V_11 )
{
return 0 ;
}
void F_239 ( struct V_7 * V_11 ) { }
int F_214 ( struct V_7 * V_11 )
{
return 0 ;
}
void F_215 ( struct V_7 * V_11 ) { }
int F_206 ( struct V_7 * V_11 )
{
return 0 ;
}
void F_208 ( struct V_7 * V_11 ) { }
static int F_222 ( struct V_1 * V_2 , unsigned int V_119 ,
T_1 V_3 , T_1 V_205 )
{
return 0 ;
}
static int F_73 ( struct V_1 * V_2 , int V_72 , int V_494 )
{
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
struct V_7 * V_4 = V_2 -> V_4 ;
int V_57 = 0 ;
if ( ! V_2 -> error ) {
if ( F_3 ( V_2 -> V_4 ) ) {
F_240 ( V_2 , V_81 ) ;
V_57 = F_71 ( V_2 , V_81 -> V_134 ,
V_425 ) ;
} else {
V_57 = F_19 ( V_4 , V_72 ,
V_209 ) ;
}
}
if ( V_81 -> V_204 && V_494 )
F_82 ( V_81 -> V_204 , V_208 ) ;
if ( V_57 && V_57 != - V_120 )
F_31 ( & V_81 -> V_22 , L_146 , V_57 ) ;
return V_57 ;
}
int F_241 ( struct V_1 * V_2 , int V_72 , bool V_495 )
{
int V_57 ;
T_1 V_205 , V_3 ;
unsigned V_496 = 0xffff ;
int V_497 , V_498 = 0 ;
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
for ( V_497 = 0 ; ; V_497 += V_499 ) {
V_57 = F_33 ( V_2 , V_72 , & V_3 , & V_205 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( ! ( V_205 & V_210 ) &&
( V_3 & V_206 ) == V_496 ) {
if ( ! V_495 ||
( V_496 == V_206 ) )
V_498 += V_499 ;
if ( V_498 >= V_224 )
break;
} else {
V_498 = 0 ;
V_496 = V_3 & V_206 ;
}
if ( V_205 & V_210 ) {
F_19 ( V_2 -> V_4 , V_72 ,
V_211 ) ;
}
if ( V_497 >= V_500 )
break;
F_68 ( V_499 ) ;
}
F_23 ( & V_81 -> V_22 , L_147 ,
V_497 , V_498 , V_3 ) ;
if ( V_498 < V_224 )
return - V_107 ;
return V_3 ;
}
void F_242 ( struct V_7 * V_11 )
{
F_243 ( V_11 , 0 + V_65 , true ) ;
F_243 ( V_11 , 0 + V_501 , true ) ;
F_244 ( V_11 , & V_11 -> V_343 , true ) ;
}
static int F_245 ( struct V_7 * V_11 , int V_176 )
{
int V_502 ;
struct V_187 * V_164 = F_62 ( V_11 -> V_178 ) ;
if ( ! V_164 -> V_165 -> V_503 && V_176 <= 1 )
return - V_69 ;
if ( V_11 -> V_90 == V_445 )
return 0 ;
if ( V_11 -> V_90 != V_422 )
return - V_69 ;
if ( V_164 -> V_165 -> V_503 )
V_502 = V_164 -> V_165 -> V_503 ( V_164 , V_11 ) ;
else
V_502 = F_15 ( V_11 , F_246 () ,
V_504 , 0 , V_176 , 0 ,
NULL , 0 , V_197 ) ;
if ( V_502 == 0 ) {
F_140 ( V_11 , V_176 ) ;
F_82 ( V_11 , V_445 ) ;
F_242 ( V_11 ) ;
}
return V_502 ;
}
static void F_247 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_4 ( V_11 -> V_25 ) ;
int V_370 = V_505 ;
if ( ! V_11 -> V_443 )
return;
if ( V_2 )
V_370 = V_2 -> V_82 [ V_11 -> V_134 - 1 ] -> V_370 ;
if ( ( V_11 -> V_17 -> V_18 -> V_20 & F_248 ( V_506 ) ) ||
V_370 == V_373 ) {
V_11 -> V_507 = 1 ;
F_213 ( V_11 , 1 ) ;
}
}
static int F_249 ( struct V_7 * V_11 )
{
struct V_187 * V_164 = F_62 ( V_11 -> V_178 ) ;
if ( ! V_164 -> V_165 -> V_508 )
return 0 ;
if ( V_11 -> V_90 == V_445 )
return 0 ;
if ( V_11 -> V_90 != V_422 )
return - V_69 ;
return V_164 -> V_165 -> V_508 ( V_164 , V_11 ) ;
}
static int
F_250 ( struct V_1 * V_2 , struct V_7 * V_11 , int V_72 ,
int V_509 )
{
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_187 * V_164 = F_62 ( V_4 -> V_178 ) ;
int V_427 , V_510 , V_502 , V_56 ;
unsigned V_189 = V_408 ;
enum V_511 V_512 = V_11 -> V_14 ;
const char * V_14 ;
int V_176 = V_11 -> V_176 ;
if ( ! V_4 -> V_25 ) {
V_189 = V_513 ;
if ( V_72 == V_4 -> V_178 -> V_360 )
V_4 -> V_178 -> V_361 = 0 ;
}
if ( V_512 == V_414 )
V_189 = V_409 ;
F_30 ( V_164 -> V_514 ) ;
V_502 = F_197 ( V_2 , V_72 , V_11 , V_189 , false ) ;
if ( V_502 < 0 )
goto V_245;
V_502 = - V_120 ;
if ( V_512 != V_515 && V_512 != V_11 -> V_14 &&
! ( V_512 == V_52 && V_11 -> V_14 > V_512 ) ) {
F_23 ( & V_11 -> V_22 , L_148 ) ;
goto V_245;
}
V_512 = V_11 -> V_14 ;
switch ( V_11 -> V_14 ) {
case V_413 :
case V_52 :
case V_411 :
V_11 -> V_343 . V_282 . V_516 = F_232 ( 512 ) ;
break;
case V_15 :
V_11 -> V_343 . V_282 . V_516 = F_232 ( 64 ) ;
break;
case V_16 :
V_11 -> V_343 . V_282 . V_516 = F_232 ( 64 ) ;
break;
case V_414 :
V_11 -> V_343 . V_282 . V_516 = F_232 ( 8 ) ;
break;
default:
goto V_245;
}
if ( V_11 -> V_14 == V_411 )
V_14 = L_149 ;
else
V_14 = F_251 ( V_11 -> V_14 ) ;
if ( V_11 -> V_14 < V_52 )
F_8 ( & V_11 -> V_22 ,
L_150 ,
( V_11 -> V_354 ) ? L_151 : L_152 , V_14 ,
V_176 , V_11 -> V_178 -> V_517 -> V_165 -> V_518 ) ;
if ( V_4 -> V_150 ) {
V_11 -> V_150 = V_4 -> V_150 ;
V_11 -> V_175 = V_4 -> V_175 ;
} else if ( V_11 -> V_14 != V_15
&& V_4 -> V_14 == V_15 ) {
if ( ! V_2 -> V_150 . V_2 ) {
F_31 ( & V_11 -> V_22 , L_153 ) ;
V_502 = - V_69 ;
goto V_245;
}
V_11 -> V_150 = & V_2 -> V_150 ;
V_11 -> V_175 = V_72 ;
}
for ( V_427 = 0 ; V_427 < V_519 ; ( ++ V_427 , F_68 ( 100 ) ) ) {
bool V_520 = false ;
if ( F_193 ( V_11 , V_509 ) ) {
struct V_521 * V_522 ;
int V_523 = 0 ;
V_520 = true ;
V_502 = F_249 ( V_11 ) ;
if ( V_502 < 0 ) {
F_31 ( & V_11 -> V_22 ,
L_154 ,
V_502 ) ;
goto V_245;
}
#define F_252 64
V_522 = F_58 ( F_252 , V_203 ) ;
if ( ! V_522 ) {
V_502 = - V_173 ;
continue;
}
for ( V_510 = 0 ; V_510 < 3 ; ++ V_510 ) {
V_522 -> V_524 = 0 ;
V_523 = F_15 ( V_11 , F_253 () ,
V_64 , V_65 ,
V_525 << 8 , 0 ,
V_522 , F_252 ,
V_526 ) ;
switch ( V_522 -> V_524 ) {
case 8 : case 16 : case 32 : case 64 : case 255 :
if ( V_522 -> V_527 ==
V_525 ) {
V_523 = 0 ;
break;
}
default:
if ( V_523 == 0 )
V_523 = - V_528 ;
break;
}
if ( V_523 == 0 || ( V_523 == - V_107 && V_427 == 0 ) )
break;
}
V_11 -> V_36 . V_524 =
V_522 -> V_524 ;
F_54 ( V_522 ) ;
V_502 = F_197 ( V_2 , V_72 , V_11 , V_189 , false ) ;
if ( V_502 < 0 )
goto V_245;
if ( V_512 != V_11 -> V_14 ) {
F_23 ( & V_11 -> V_22 ,
L_148 ) ;
V_502 = - V_120 ;
goto V_245;
}
if ( V_523 ) {
if ( V_523 != - V_120 )
F_31 ( & V_11 -> V_22 , L_155 ,
V_523 ) ;
V_502 = - V_529 ;
continue;
}
#undef F_252
}
if ( V_11 -> V_335 == 0 ) {
for ( V_510 = 0 ; V_510 < V_530 ; ++ V_510 ) {
V_502 = F_245 ( V_11 , V_176 ) ;
if ( V_502 >= 0 )
break;
F_68 ( 200 ) ;
}
if ( V_502 < 0 ) {
if ( V_502 != - V_120 )
F_31 ( & V_11 -> V_22 , L_156 ,
V_176 , V_502 ) ;
goto V_245;
}
if ( V_11 -> V_14 >= V_52 ) {
V_176 = V_11 -> V_176 ;
F_8 ( & V_11 -> V_22 ,
L_157 ,
( V_11 -> V_354 ) ? L_151 : L_152 ,
( V_11 -> V_14 == V_413 ) ? L_158 : L_38 ,
V_176 , V_11 -> V_178 -> V_517 -> V_165 -> V_518 ) ;
}
F_68 ( 10 ) ;
if ( V_520 )
break;
}
V_502 = F_188 ( V_11 , 8 ) ;
if ( V_502 < 8 ) {
if ( V_502 != - V_120 )
F_31 ( & V_11 -> V_22 ,
L_159 ,
V_502 ) ;
if ( V_502 >= 0 )
V_502 = - V_529 ;
} else {
V_502 = 0 ;
break;
}
}
if ( V_502 )
goto V_245;
if ( ( V_11 -> V_14 >= V_52 ) &&
( F_13 ( V_11 -> V_36 . V_531 ) < 0x0300 ) ) {
F_31 ( & V_11 -> V_22 , L_160
L_161 ) ;
F_197 ( V_2 , V_72 , V_11 ,
V_532 , true ) ;
V_502 = - V_69 ;
goto V_245;
}
if ( V_11 -> V_36 . V_524 == 0xff ||
V_11 -> V_14 >= V_52 )
V_56 = 512 ;
else
V_56 = V_11 -> V_36 . V_524 ;
if ( F_254 ( & V_11 -> V_343 . V_282 ) != V_56 ) {
if ( V_11 -> V_14 == V_414 ||
! ( V_56 == 8 || V_56 == 16 || V_56 == 32 || V_56 == 64 ) ) {
F_31 ( & V_11 -> V_22 , L_162 , V_56 ) ;
V_502 = - V_529 ;
goto V_245;
}
if ( V_11 -> V_14 == V_16 )
F_23 ( & V_11 -> V_22 , L_163 , V_56 ) ;
else
F_101 ( & V_11 -> V_22 , L_164 , V_56 ) ;
V_11 -> V_343 . V_282 . V_516 = F_232 ( V_56 ) ;
F_242 ( V_11 ) ;
}
V_502 = F_188 ( V_11 , V_533 ) ;
if ( V_502 < ( signed ) sizeof( V_11 -> V_36 ) ) {
if ( V_502 != - V_120 )
F_31 ( & V_11 -> V_22 , L_165 ,
V_502 ) ;
if ( V_502 >= 0 )
V_502 = - V_534 ;
goto V_245;
}
F_255 ( V_11 ) ;
if ( V_11 -> V_335 == 0 && F_13 ( V_11 -> V_36 . V_531 ) >= 0x0201 ) {
V_502 = F_256 ( V_11 ) ;
if ( ! V_502 ) {
V_11 -> V_26 = F_6 ( V_11 ) ;
F_12 ( V_11 ) ;
}
}
V_502 = 0 ;
if ( V_164 -> V_165 -> V_535 )
V_164 -> V_165 -> V_535 ( V_164 , V_11 ) ;
F_247 ( V_11 ) ;
V_245:
if ( V_502 ) {
F_73 ( V_2 , V_72 , 0 ) ;
F_140 ( V_11 , V_176 ) ;
}
F_32 ( V_164 -> V_514 ) ;
return V_502 ;
}
static void
F_257 ( struct V_1 * V_2 , struct V_7 * V_11 , int V_72 )
{
struct V_536 * V_537 ;
int V_83 ;
if ( V_11 -> V_12 & V_538 )
return;
V_537 = F_58 ( sizeof *V_537 , V_244 ) ;
if ( V_537 == NULL )
return;
V_83 = F_258 ( V_11 , V_539 , 0 ,
V_537 , sizeof *V_537 ) ;
if ( V_83 == sizeof *V_537 ) {
F_8 ( & V_11 -> V_22 , L_166
L_167 ) ;
if ( V_2 -> V_226 ) {
V_2 -> V_94 [ V_72 - 1 ] = V_97 ;
F_26 ( V_104 ,
& V_2 -> V_87 , 0 ) ;
}
}
F_54 ( V_537 ) ;
}
static unsigned
F_259 ( struct V_1 * V_2 )
{
struct V_7 * V_4 = V_2 -> V_4 ;
int V_280 ;
int V_72 ;
if ( ! V_2 -> V_278 )
return 0 ;
V_280 = V_4 -> V_276 - V_2 -> V_36 -> V_281 ;
for ( V_72 = 1 ; V_72 <= V_4 -> V_9 ; ++ V_72 ) {
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
struct V_7 * V_11 = V_81 -> V_204 ;
unsigned V_242 ;
int V_540 ;
if ( ! V_11 )
continue;
if ( F_3 ( V_11 ) )
V_242 = 150 ;
else
V_242 = 100 ;
if ( V_11 -> V_8 )
V_540 = F_260 ( V_11 , V_11 -> V_8 ) ;
else if ( V_72 != V_11 -> V_178 -> V_360 || V_4 -> V_25 )
V_540 = V_242 ;
else
V_540 = 8 ;
if ( V_540 > V_2 -> V_277 )
F_101 ( & V_81 -> V_22 , L_168 ,
V_540 , V_2 -> V_277 ) ;
V_280 -= V_540 ;
}
if ( V_280 < 0 ) {
F_101 ( V_2 -> V_121 , L_169 ,
- V_280 ) ;
V_280 = 0 ;
}
return V_280 ;
}
static void F_261 ( struct V_1 * V_2 , int V_72 , T_1 V_3 ,
T_1 V_205 )
{
int V_83 , V_56 ;
unsigned V_242 ;
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_187 * V_164 = F_62 ( V_4 -> V_178 ) ;
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
struct V_7 * V_11 = V_81 -> V_204 ;
static int V_541 = - 1 ;
if ( V_11 ) {
if ( V_164 -> V_542 && ! V_4 -> V_25 )
F_262 ( V_164 -> V_542 , V_11 -> V_14 ) ;
F_85 ( & V_81 -> V_204 ) ;
}
if ( ! ( V_3 & V_206 ) ||
( V_205 & V_210 ) )
F_56 ( V_72 , V_2 -> V_185 ) ;
if ( V_205 & ( V_210 |
V_212 ) ) {
V_83 = F_263 ( V_2 , V_72 ) ;
if ( V_83 < 0 ) {
if ( V_83 != - V_120 &&
V_72 != V_541 &&
F_264 () )
F_31 ( & V_81 -> V_22 , L_170 ) ;
V_3 &= ~ V_206 ;
V_541 = V_72 ;
} else {
V_3 = V_83 ;
}
}
if ( ! ( V_3 & V_206 ) ||
F_67 ( V_72 , V_2 -> V_185 ) ) {
if ( F_66 ( V_2 )
&& ! F_200 ( V_2 , V_3 )
&& ! V_81 -> V_319 )
F_20 ( V_4 , V_72 , V_169 ) ;
if ( V_3 & V_207 )
goto V_419;
return;
}
if ( F_3 ( V_2 -> V_4 ) )
V_242 = 150 ;
else
V_242 = 100 ;
V_83 = 0 ;
for ( V_56 = 0 ; V_56 < V_543 ; V_56 ++ ) {
V_11 = F_265 ( V_4 , V_4 -> V_178 , V_72 ) ;
if ( ! V_11 ) {
F_31 ( & V_81 -> V_22 ,
L_171 ) ;
goto V_419;
}
F_82 ( V_11 , V_544 ) ;
V_11 -> V_276 = V_2 -> V_277 ;
V_11 -> V_196 = V_4 -> V_196 + 1 ;
V_11 -> V_335 = F_192 ( V_2 ) ;
if ( F_3 ( V_2 -> V_4 ) )
V_11 -> V_14 = V_52 ;
else
V_11 -> V_14 = V_515 ;
F_136 ( V_11 ) ;
if ( V_11 -> V_176 <= 0 ) {
V_83 = - V_410 ;
goto V_545;
}
F_201 ( V_81 ) ;
V_83 = F_250 ( V_2 , V_11 , V_72 , V_56 ) ;
F_202 ( V_81 ) ;
if ( V_83 < 0 )
goto V_545;
if ( V_11 -> V_12 & V_546 )
F_68 ( 1000 ) ;
if ( V_11 -> V_36 . V_547 == V_548
&& V_11 -> V_276 <= V_242 ) {
T_1 V_549 ;
V_83 = F_100 ( V_11 , V_273 , 0 ,
& V_549 ) ;
if ( V_83 ) {
F_23 ( & V_11 -> V_22 , L_172 , V_83 ) ;
goto V_550;
}
if ( ( V_549 & ( 1 << V_279 ) ) == 0 ) {
F_31 ( & V_11 -> V_22 ,
L_173
L_174 ) ;
if ( V_2 -> V_226 ) {
V_2 -> V_94 [ V_72 - 1 ] =
V_99 ;
F_26 (
V_104 ,
& V_2 -> V_87 , 0 ) ;
}
V_83 = - V_410 ;
goto V_550;
}
}
if ( F_13 ( V_11 -> V_36 . V_531 ) >= 0x0200
&& V_11 -> V_14 == V_16
&& V_291 != 0 )
F_257 ( V_2 , V_11 , V_72 ) ;
V_83 = 0 ;
F_30 ( & V_288 ) ;
F_114 ( & V_290 ) ;
if ( V_4 -> V_90 == V_208 )
V_83 = - V_410 ;
else
V_81 -> V_204 = V_11 ;
F_116 ( & V_290 ) ;
F_32 ( & V_288 ) ;
if ( ! V_83 ) {
V_83 = F_167 ( V_11 ) ;
if ( V_83 ) {
F_30 ( & V_288 ) ;
F_114 ( & V_290 ) ;
V_81 -> V_204 = NULL ;
F_116 ( & V_290 ) ;
F_32 ( & V_288 ) ;
} else {
if ( V_164 -> V_542 && ! V_4 -> V_25 )
F_266 ( V_164 -> V_542 ,
V_11 -> V_14 ) ;
}
}
if ( V_83 )
goto V_550;
V_83 = F_259 ( V_2 ) ;
if ( V_83 )
F_23 ( V_2 -> V_121 , L_175 , V_83 ) ;
return;
V_550:
F_73 ( V_2 , V_72 , 1 ) ;
V_545:
F_242 ( V_11 ) ;
F_139 ( V_11 ) ;
F_141 ( V_11 ) ;
F_110 ( V_11 ) ;
if ( ( V_83 == - V_410 ) || ( V_83 == - V_368 ) )
break;
}
if ( V_2 -> V_4 -> V_25 ||
! V_164 -> V_165 -> V_551 ||
! ( V_164 -> V_165 -> V_551 ) ( V_164 , V_72 ) ) {
if ( V_83 != - V_410 && V_83 != - V_120 )
F_31 ( & V_81 -> V_22 ,
L_176 ) ;
}
V_419:
F_73 ( V_2 , V_72 , 1 ) ;
if ( V_164 -> V_165 -> V_552 && ! V_2 -> V_4 -> V_25 )
V_164 -> V_165 -> V_552 ( V_164 , V_72 ) ;
}
static void F_267 ( struct V_1 * V_2 , int V_72 ,
T_1 V_3 , T_1 V_205 )
__must_hold( &port_dev->status_lock
static void F_268 ( struct V_1 * V_2 , int V_72 )
__must_hold( &port_dev->status_lock
static void V_305 ( struct V_85 * V_86 )
{
struct V_7 * V_4 ;
struct V_127 * V_128 ;
struct V_1 * V_2 ;
struct V_235 * V_236 ;
T_1 V_237 ;
T_1 V_238 ;
int V_56 , V_57 ;
V_2 = F_25 ( V_86 , struct V_1 , V_130 ) ;
V_4 = V_2 -> V_4 ;
V_236 = V_2 -> V_121 ;
V_128 = F_36 ( V_236 ) ;
F_23 ( V_236 , L_177 ,
V_4 -> V_90 , V_4 -> V_9 ,
( T_1 ) V_2 -> V_184 [ 0 ] ,
( T_1 ) V_2 -> V_146 [ 0 ] ) ;
F_143 ( V_4 ) ;
if ( F_269 ( V_2 -> V_129 ) )
goto V_553;
if ( V_4 -> V_90 == V_208 ) {
V_2 -> error = - V_120 ;
F_84 ( V_2 , V_289 ) ;
goto V_553;
}
V_57 = F_75 ( V_128 ) ;
if ( V_57 ) {
F_23 ( V_236 , L_178 , V_57 ) ;
goto V_553;
}
if ( V_2 -> V_92 )
goto V_554;
if ( V_2 -> error ) {
F_23 ( V_236 , L_179 , V_2 -> error ) ;
V_57 = F_270 ( V_4 ) ;
if ( V_57 ) {
F_23 ( V_236 , L_180 , V_57 ) ;
goto V_554;
}
V_2 -> V_142 = 0 ;
V_2 -> error = 0 ;
}
for ( V_56 = 1 ; V_56 <= V_4 -> V_9 ; V_56 ++ ) {
struct V_80 * V_81 = V_2 -> V_82 [ V_56 - 1 ] ;
if ( F_67 ( V_56 , V_2 -> V_146 )
|| F_67 ( V_56 , V_2 -> V_184 )
|| F_67 ( V_56 , V_2 -> V_135 ) ) {
F_170 ( & V_81 -> V_22 ) ;
F_90 ( & V_81 -> V_22 ) ;
F_201 ( V_81 ) ;
F_268 ( V_2 , V_56 ) ;
F_202 ( V_81 ) ;
F_216 ( & V_81 -> V_22 ) ;
}
}
if ( F_152 ( 0 , V_2 -> V_146 ) == 0 )
;
else if ( F_70 ( V_2 , & V_237 , & V_238 ) < 0 )
F_31 ( V_236 , L_181 ) ;
else {
if ( V_238 & V_555 ) {
F_23 ( V_236 , L_182 ) ;
F_17 ( V_4 , V_556 ) ;
if ( V_237 & V_284 )
V_2 -> V_278 = 1 ;
else
V_2 -> V_278 = 0 ;
}
if ( V_238 & V_557 ) {
T_1 V_83 = 0 ;
T_1 V_558 ;
F_23 ( V_236 , L_183 ) ;
F_17 ( V_4 , V_559 ) ;
F_68 ( 500 ) ;
F_65 ( V_2 , true ) ;
F_70 ( V_2 , & V_83 , & V_558 ) ;
if ( V_83 & V_285 )
F_31 ( V_236 , L_184 ) ;
}
}
V_554:
F_271 ( V_128 ) ;
V_553:
F_150 ( V_4 ) ;
F_76 ( V_128 ) ;
F_41 ( & V_2 -> V_131 , V_133 ) ;
}
int F_272 ( void )
{
if ( F_273 ( & V_560 ) < 0 ) {
F_274 ( V_561 L_185 ,
V_562 ) ;
return - 1 ;
}
V_132 = F_275 ( L_186 , V_563 , 0 ) ;
if ( V_132 )
return 0 ;
F_276 ( & V_560 ) ;
F_277 ( L_187 , V_562 ) ;
return - 1 ;
}
void F_278 ( void )
{
F_279 ( V_132 ) ;
F_276 ( & V_560 ) ;
}
static int F_280 ( struct V_7 * V_11 ,
struct V_521 * V_564 ,
struct V_565 * V_566 )
{
int V_88 = 0 ;
unsigned V_567 ;
unsigned V_568 = 0 ;
unsigned V_116 ;
unsigned V_569 ;
int V_113 ;
char * V_522 ;
if ( memcmp ( & V_11 -> V_36 , V_564 ,
sizeof( * V_564 ) ) != 0 )
return 1 ;
if ( ( V_566 && ! V_11 -> V_17 ) || ( ! V_566 && V_11 -> V_17 ) )
return 1 ;
if ( V_11 -> V_17 ) {
V_116 = F_13 ( V_11 -> V_17 -> V_282 -> V_357 ) ;
if ( V_116 != F_13 ( V_566 -> V_282 -> V_357 ) )
return 1 ;
if ( memcmp ( V_11 -> V_17 -> V_282 , V_566 -> V_282 , V_116 ) )
return 1 ;
}
if ( V_11 -> V_351 )
V_568 = strlen ( V_11 -> V_351 ) + 1 ;
V_116 = V_568 ;
for ( V_567 = 0 ; V_567 < V_11 -> V_36 . V_570 ; V_567 ++ ) {
V_569 = F_13 ( V_11 -> V_354 [ V_567 ] . V_282 . V_357 ) ;
V_116 = F_281 ( V_116 , V_569 ) ;
}
V_522 = F_58 ( V_116 , V_203 ) ;
if ( ! V_522 )
return 1 ;
for ( V_567 = 0 ; V_567 < V_11 -> V_36 . V_570 ; V_567 ++ ) {
V_569 = F_13 ( V_11 -> V_354 [ V_567 ] . V_282 . V_357 ) ;
V_113 = F_258 ( V_11 , V_571 , V_567 , V_522 ,
V_569 ) ;
if ( V_113 != V_569 ) {
F_23 ( & V_11 -> V_22 , L_188 ,
V_567 , V_113 ) ;
V_88 = 1 ;
break;
}
if ( memcmp ( V_522 , V_11 -> V_356 [ V_567 ] , V_569 )
!= 0 ) {
F_23 ( & V_11 -> V_22 , L_189 ,
V_567 ,
( (struct V_572 * ) V_522 ) ->
V_573 ) ;
V_88 = 1 ;
break;
}
}
if ( ! V_88 && V_568 ) {
V_113 = F_282 ( V_11 , V_11 -> V_36 . V_348 ,
V_522 , V_568 ) ;
if ( V_113 + 1 != V_568 ) {
F_23 ( & V_11 -> V_22 , L_190 ,
V_113 ) ;
V_88 = 1 ;
} else if ( memcmp ( V_522 , V_11 -> V_351 , V_113 ) != 0 ) {
F_23 ( & V_11 -> V_22 , L_191 ) ;
V_88 = 1 ;
}
}
F_54 ( V_522 ) ;
return V_88 ;
}
static int F_218 ( struct V_7 * V_11 )
{
struct V_7 * V_574 = V_11 -> V_25 ;
struct V_1 * V_575 ;
struct V_187 * V_164 = F_62 ( V_11 -> V_178 ) ;
struct V_521 V_36 = V_11 -> V_36 ;
struct V_565 * V_17 ;
int V_56 , V_576 , V_57 = 0 ;
int V_72 = V_11 -> V_134 ;
if ( V_11 -> V_90 == V_208 ||
V_11 -> V_90 == V_325 ) {
F_23 ( & V_11 -> V_22 , L_192 ,
V_11 -> V_90 ) ;
return - V_69 ;
}
if ( ! V_574 )
return - V_577 ;
V_575 = F_4 ( V_574 ) ;
if ( V_11 -> V_439 == 1 )
F_213 ( V_11 , 0 ) ;
V_57 = F_214 ( V_11 ) ;
if ( V_57 ) {
F_31 ( & V_11 -> V_22 , L_193 , V_122 ) ;
goto V_578;
}
V_57 = F_206 ( V_11 ) ;
if ( V_57 ) {
F_31 ( & V_11 -> V_22 , L_194 ,
V_122 ) ;
goto V_578;
}
V_17 = V_11 -> V_17 ;
V_11 -> V_17 = NULL ;
for ( V_56 = 0 ; V_56 < V_543 ; ++ V_56 ) {
F_242 ( V_11 ) ;
V_57 = F_250 ( V_575 , V_11 , V_72 , V_56 ) ;
if ( V_57 >= 0 || V_57 == - V_410 || V_57 == - V_120 )
break;
}
if ( V_57 < 0 )
goto V_579;
if ( F_280 ( V_11 , & V_36 , V_17 ) ) {
F_8 ( & V_11 -> V_22 , L_195 ) ;
V_11 -> V_36 = V_36 ;
goto V_579;
}
if ( ! V_11 -> V_8 )
goto V_419;
F_30 ( V_164 -> V_491 ) ;
V_57 = F_283 ( V_11 , V_11 -> V_8 , NULL , NULL ) ;
if ( V_57 < 0 ) {
F_101 ( & V_11 -> V_22 ,
L_196
L_197 ) ;
F_32 ( V_164 -> V_491 ) ;
goto V_579;
}
V_57 = F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_580 , 0 ,
V_11 -> V_8 -> V_282 . V_573 , 0 ,
NULL , 0 , V_197 ) ;
if ( V_57 < 0 ) {
F_31 ( & V_11 -> V_22 ,
L_198 ,
V_11 -> V_8 -> V_282 . V_573 , V_57 ) ;
F_32 ( V_164 -> V_491 ) ;
goto V_579;
}
F_32 ( V_164 -> V_491 ) ;
F_82 ( V_11 , V_91 ) ;
for ( V_56 = 0 ; V_56 < V_11 -> V_8 -> V_282 . V_581 ; V_56 ++ ) {
struct V_582 * V_354 = V_11 -> V_8 ;
struct V_127 * V_128 = V_354 -> V_10 [ V_56 ] ;
struct V_583 * V_282 ;
V_282 = & V_128 -> V_295 -> V_282 ;
if ( V_282 -> V_584 == 0 ) {
F_284 ( V_11 , V_128 , true ) ;
F_285 ( V_11 , V_128 , true ) ;
V_57 = 0 ;
} else {
V_128 -> V_585 = 1 ;
V_57 = F_99 ( V_11 , V_282 -> V_586 ,
V_282 -> V_584 ) ;
V_128 -> V_585 = 0 ;
}
if ( V_57 < 0 ) {
F_31 ( & V_11 -> V_22 , L_199
L_200 ,
V_282 -> V_586 ,
V_282 -> V_584 ,
V_57 ) ;
goto V_579;
}
for ( V_576 = 0 ; V_576 < V_128 -> V_295 -> V_282 . V_304 ; V_576 ++ )
V_128 -> V_295 -> V_234 [ V_576 ] . V_587 = 0 ;
}
V_419:
F_213 ( V_11 , 1 ) ;
F_215 ( V_11 ) ;
F_208 ( V_11 ) ;
F_286 ( V_11 ) ;
V_11 -> V_17 = V_17 ;
return 0 ;
V_579:
F_286 ( V_11 ) ;
V_11 -> V_17 = V_17 ;
V_578:
F_72 ( V_575 , V_72 ) ;
return - V_120 ;
}
int F_270 ( struct V_7 * V_11 )
{
int V_57 ;
int V_56 ;
unsigned int V_588 ;
struct V_80 * V_81 ;
struct V_582 * V_354 = V_11 -> V_8 ;
struct V_1 * V_2 = F_4 ( V_11 -> V_25 ) ;
if ( V_11 -> V_90 == V_208 ||
V_11 -> V_90 == V_325 ) {
F_23 ( & V_11 -> V_22 , L_192 ,
V_11 -> V_90 ) ;
return - V_69 ;
}
if ( ! V_11 -> V_25 ) {
F_23 ( & V_11 -> V_22 , L_201 , V_122 ) ;
return - V_577 ;
}
V_81 = V_2 -> V_82 [ V_11 -> V_134 - 1 ] ;
V_588 = F_287 () ;
F_187 ( V_11 ) ;
if ( V_354 ) {
for ( V_56 = 0 ; V_56 < V_354 -> V_282 . V_581 ; ++ V_56 ) {
struct V_127 * V_589 = V_354 -> V_10 [ V_56 ] ;
struct V_590 * V_163 ;
int V_591 = 0 ;
if ( V_589 -> V_22 . V_165 ) {
V_163 = F_288 ( V_589 -> V_22 . V_165 ) ;
if ( V_163 -> V_592 && V_163 -> V_593 )
V_591 = ( V_163 -> V_592 ) ( V_589 ) ;
else if ( V_589 -> V_594 ==
V_595 )
V_591 = 1 ;
if ( V_591 )
F_289 ( V_589 ) ;
}
}
}
F_201 ( V_81 ) ;
V_57 = F_218 ( V_11 ) ;
F_202 ( V_81 ) ;
if ( V_354 ) {
for ( V_56 = V_354 -> V_282 . V_581 - 1 ; V_56 >= 0 ; -- V_56 ) {
struct V_127 * V_589 = V_354 -> V_10 [ V_56 ] ;
struct V_590 * V_163 ;
int V_596 = V_589 -> V_597 ;
if ( ! V_596 && V_589 -> V_22 . V_165 ) {
V_163 = F_288 ( V_589 -> V_22 . V_165 ) ;
if ( V_163 -> V_593 )
V_596 = ( V_163 -> V_593 ) ( V_589 ) ;
else if ( V_589 -> V_594 ==
V_595 )
V_596 = 1 ;
if ( V_596 )
V_589 -> V_597 = 1 ;
}
}
F_290 ( V_11 ) ;
}
F_190 ( V_11 ) ;
F_291 ( V_588 ) ;
return V_57 ;
}
void F_292 ( struct V_127 * V_598 )
{
if ( F_64 ( & V_598 -> V_599 ) )
F_126 ( V_598 ) ;
}
struct V_7 * F_293 ( struct V_7 * V_4 ,
int V_72 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
if ( V_72 < 1 || V_72 > V_4 -> V_9 )
return NULL ;
return V_2 -> V_82 [ V_72 - 1 ] -> V_204 ;
}
void F_109 ( struct V_7 * V_4 ,
struct V_63 * V_282 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
enum V_600 V_370 ;
int V_56 ;
if ( ! V_2 )
return;
if ( ! F_3 ( V_4 ) ) {
for ( V_56 = 1 ; V_56 <= V_4 -> V_9 ; V_56 ++ ) {
struct V_80 * V_81 = V_2 -> V_82 [ V_56 - 1 ] ;
V_370 = V_81 -> V_370 ;
if ( V_370 == V_373 ) {
T_3 V_601 = 1 << ( V_56 % 8 ) ;
if ( ! ( V_282 -> V_37 . V_250 . V_251 [ V_56 / 8 ] & V_601 ) ) {
F_23 ( & V_81 -> V_22 , L_202 ) ;
V_282 -> V_37 . V_250 . V_251 [ V_56 / 8 ] |= V_601 ;
}
}
}
} else {
T_1 V_602 = F_13 ( V_282 -> V_37 . V_38 . V_251 ) ;
for ( V_56 = 1 ; V_56 <= V_4 -> V_9 ; V_56 ++ ) {
struct V_80 * V_81 = V_2 -> V_82 [ V_56 - 1 ] ;
V_370 = V_81 -> V_370 ;
if ( V_370 == V_373 ) {
T_1 V_601 = 1 << V_56 ;
if ( ! ( V_602 & V_601 ) ) {
F_23 ( & V_81 -> V_22 , L_202 ) ;
V_602 |= V_601 ;
}
}
}
V_282 -> V_37 . V_38 . V_251 = F_232 ( V_602 ) ;
}
}
T_7 F_294 ( struct V_7 * V_4 ,
int V_72 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
if ( ! V_2 )
return NULL ;
return F_295 ( & V_2 -> V_82 [ V_72 - 1 ] -> V_22 ) ;
}
