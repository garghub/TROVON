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
static int F_72 ( struct V_1 * V_2 , int V_72 )
{
int V_57 ;
int V_184 ;
T_1 V_185 , V_3 ;
if ( ! F_3 ( V_2 -> V_4 ) )
return - V_69 ;
V_57 = F_33 ( V_2 , V_72 , & V_3 , & V_185 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( ( V_3 & V_186 ) ==
V_187 ) {
F_23 ( & V_2 -> V_82 [ V_72 - 1 ] -> V_22 ,
L_23 ) ;
return V_57 ;
}
V_57 = F_71 ( V_2 , V_72 , V_188 ) ;
if ( V_57 )
return V_57 ;
for ( V_184 = 0 ; ; V_184 += V_189 ) {
V_57 = F_33 ( V_2 , V_72 , & V_3 , & V_185 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( ( V_3 & V_186 ) ==
V_188 )
break;
if ( V_184 >= V_190 )
break;
F_68 ( V_189 ) ;
}
if ( V_184 >= V_190 )
F_73 ( & V_2 -> V_82 [ V_72 - 1 ] -> V_22 ,
L_24 , V_184 ) ;
return F_71 ( V_2 , V_72 , V_187 ) ;
}
static int F_74 ( struct V_1 * V_2 , int V_72 , int V_191 )
{
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
struct V_7 * V_4 = V_2 -> V_4 ;
int V_57 = 0 ;
if ( V_81 -> V_192 && V_191 )
F_75 ( V_81 -> V_192 , V_193 ) ;
if ( ! V_2 -> error ) {
if ( F_3 ( V_2 -> V_4 ) )
V_57 = F_72 ( V_2 , V_72 ) ;
else
V_57 = F_19 ( V_4 , V_72 ,
V_194 ) ;
}
if ( V_57 && V_57 != - V_120 )
F_31 ( & V_81 -> V_22 , L_25 , V_57 ) ;
return V_57 ;
}
static void F_76 ( struct V_1 * V_2 , int V_72 )
{
F_23 ( & V_2 -> V_82 [ V_72 - 1 ] -> V_22 , L_26 ) ;
F_74 ( V_2 , V_72 , 1 ) ;
F_44 ( V_72 , V_2 -> V_195 ) ;
F_34 ( V_2 ) ;
}
int F_77 ( struct V_7 * V_11 )
{
struct V_1 * V_2 ;
struct V_127 * V_128 ;
if ( ! V_11 -> V_25 )
return - V_69 ;
V_2 = F_4 ( V_11 -> V_25 ) ;
V_128 = F_36 ( V_2 -> V_121 ) ;
F_78 ( V_128 ) ;
F_44 ( V_11 -> V_134 , V_2 -> V_196 ) ;
F_76 ( V_2 , V_11 -> V_134 ) ;
F_79 ( V_128 ) ;
return 0 ;
}
static void F_80 ( struct V_1 * V_2 , enum V_197 type )
{
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_198 * V_164 ;
int V_57 ;
int V_72 ;
int V_83 ;
bool V_199 = false ;
unsigned V_200 ;
if ( type == V_201 || type == V_202 ) {
F_81 ( & V_4 -> V_22 ) ;
if ( V_2 -> V_129 )
goto V_129;
if ( type == V_201 )
goto V_203;
goto V_204;
}
F_38 ( & V_2 -> V_131 ) ;
if ( type != V_205 ) {
if ( V_4 -> V_25 && F_3 ( V_4 ) ) {
V_57 = F_15 ( V_4 , F_18 ( V_4 , 0 ) ,
V_206 , V_66 ,
V_4 -> V_207 - 1 , 0 , NULL , 0 ,
V_208 ) ;
if ( V_57 < 0 )
F_31 ( V_2 -> V_121 ,
L_27 ) ;
}
if ( type == V_209 ) {
V_200 = F_69 ( V_2 ) ;
F_65 ( V_2 , false ) ;
F_82 ( & V_2 -> V_210 , V_211 ) ;
F_26 ( V_104 ,
& V_2 -> V_210 ,
F_83 ( V_200 ) ) ;
F_37 (
F_36 ( V_2 -> V_121 ) ) ;
return;
} else if ( type == V_212 ) {
V_164 = F_62 ( V_4 -> V_178 ) ;
if ( V_164 -> V_165 -> V_213 ) {
V_57 = V_164 -> V_165 -> V_213 ( V_164 , V_4 ,
& V_2 -> V_150 , V_214 ) ;
if ( V_57 < 0 ) {
F_31 ( V_2 -> V_121 , L_28
L_29
L_30 ) ;
F_31 ( V_2 -> V_121 , L_31
L_32
L_33 ) ;
}
}
F_65 ( V_2 , true ) ;
} else {
F_65 ( V_2 , true ) ;
}
}
V_203:
for ( V_72 = 1 ; V_72 <= V_4 -> V_9 ; ++ V_72 ) {
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
struct V_7 * V_11 = V_81 -> V_192 ;
T_1 V_3 , V_185 ;
V_3 = V_185 = 0 ;
V_83 = F_33 ( V_2 , V_72 , & V_3 , & V_185 ) ;
if ( V_11 || ( V_3 & V_215 ) )
F_23 ( & V_81 -> V_22 , L_34 ,
V_3 , V_185 ) ;
if ( ( V_3 & V_216 ) && (
type != V_205 ||
! ( V_3 & V_215 ) ||
! V_11 ||
V_11 -> V_90 == V_193 ) ) {
V_3 &= ~ V_216 ;
if ( ! F_3 ( V_4 ) )
F_19 ( V_4 , V_72 ,
V_194 ) ;
}
if ( V_185 & V_217 ) {
V_199 = true ;
F_19 ( V_2 -> V_4 , V_72 ,
V_218 ) ;
}
if ( V_185 & V_219 ) {
V_199 = true ;
F_19 ( V_2 -> V_4 , V_72 ,
V_220 ) ;
}
if ( V_185 & V_221 ) {
V_199 = true ;
F_19 ( V_2 -> V_4 , V_72 ,
V_222 ) ;
}
if ( ( V_185 & V_223 ) &&
F_3 ( V_2 -> V_4 ) ) {
V_199 = true ;
F_19 ( V_2 -> V_4 , V_72 ,
V_224 ) ;
}
if ( ! ( V_3 & V_215 ) ||
( V_185 & V_217 ) )
F_56 ( V_72 , V_2 -> V_196 ) ;
if ( ! V_11 || V_11 -> V_90 == V_193 ) {
if ( V_11 || ( V_3 & V_215 ) ||
( V_3 & V_225 ) )
F_44 ( V_72 , V_2 -> V_195 ) ;
} else if ( V_3 & V_216 ) {
bool V_226 = ( V_3 &
V_186 ) ==
V_227 ;
if ( V_185 || ( F_3 ( V_2 -> V_4 ) &&
V_226 ) )
F_44 ( V_72 , V_2 -> V_195 ) ;
} else if ( V_11 -> V_228 ) {
#ifdef F_84
V_11 -> V_229 = 1 ;
#endif
if ( F_67 ( V_72 , V_2 -> V_170 ) )
F_44 ( V_72 , V_2 -> V_195 ) ;
} else {
F_75 ( V_11 , V_193 ) ;
F_44 ( V_72 , V_2 -> V_195 ) ;
}
}
if ( V_199 ) {
V_200 = V_230 ;
if ( type == V_201 ) {
F_82 ( & V_2 -> V_210 , V_231 ) ;
F_26 ( V_104 ,
& V_2 -> V_210 ,
F_83 ( V_200 ) ) ;
F_85 ( & V_4 -> V_22 ) ;
return;
} else {
F_68 ( V_200 ) ;
}
}
V_204:
V_2 -> V_92 = 0 ;
V_83 = F_46 ( V_2 -> V_136 , V_214 ) ;
if ( V_83 < 0 )
F_31 ( V_2 -> V_121 , L_35 , V_83 ) ;
if ( V_2 -> V_232 && V_103 )
F_26 ( V_104 ,
& V_2 -> V_87 , V_105 ) ;
F_34 ( V_2 ) ;
if ( type == V_201 || type == V_202 ) {
V_129:
F_40 ( F_36 ( V_2 -> V_121 ) ) ;
F_85 ( & V_4 -> V_22 ) ;
}
F_41 ( & V_2 -> V_131 , V_133 ) ;
}
static void V_211 ( struct V_85 * V_233 )
{
struct V_1 * V_2 = F_25 ( V_233 , struct V_1 , V_210 . V_86 ) ;
F_80 ( V_2 , V_201 ) ;
}
static void V_231 ( struct V_85 * V_233 )
{
struct V_1 * V_2 = F_25 ( V_233 , struct V_1 , V_210 . V_86 ) ;
F_80 ( V_2 , V_202 ) ;
}
static void F_86 ( struct V_1 * V_2 , enum V_234 type )
{
struct V_7 * V_4 = V_2 -> V_4 ;
int V_56 ;
V_2 -> V_92 = 1 ;
if ( type != V_235 ) {
for ( V_56 = 0 ; V_56 < V_4 -> V_9 ; ++ V_56 ) {
if ( V_2 -> V_82 [ V_56 ] -> V_192 )
F_87 ( & V_2 -> V_82 [ V_56 ] -> V_192 ) ;
}
}
F_88 ( V_2 -> V_136 ) ;
if ( V_2 -> V_232 )
F_89 ( & V_2 -> V_87 ) ;
if ( V_2 -> V_150 . V_2 )
F_90 ( & V_2 -> V_150 . V_154 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_2 -> V_4 -> V_9 ; ++ V_56 )
F_92 ( & V_2 -> V_82 [ V_56 ] -> V_22 ) ;
}
static int F_93 ( struct V_127 * V_128 )
{
struct V_1 * V_2 = F_5 ( V_128 ) ;
F_86 ( V_2 , V_236 ) ;
V_2 -> V_237 = 1 ;
F_91 ( V_2 ) ;
return 0 ;
}
static int F_94 ( struct V_127 * V_128 )
{
struct V_1 * V_2 = F_5 ( V_128 ) ;
V_2 -> V_237 = 0 ;
F_91 ( V_2 ) ;
F_80 ( V_2 , V_238 ) ;
return 0 ;
}
static int F_95 ( struct V_1 * V_2 ,
struct V_239 * V_240 )
{
struct V_198 * V_164 ;
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_241 * V_242 = V_2 -> V_121 ;
T_1 V_243 , V_244 ;
T_1 V_245 ;
unsigned int V_171 ;
int V_246 , V_57 , V_56 ;
char * V_247 = L_36 ;
unsigned V_248 ;
unsigned V_249 ;
unsigned V_9 ;
V_2 -> V_145 = F_58 ( sizeof( * V_2 -> V_145 ) , V_250 ) ;
if ( ! V_2 -> V_145 ) {
V_57 = - V_173 ;
goto V_251;
}
V_2 -> V_83 = F_58 ( sizeof( * V_2 -> V_83 ) , V_250 ) ;
if ( ! V_2 -> V_83 ) {
V_57 = - V_173 ;
goto V_251;
}
F_96 ( & V_2 -> V_118 ) ;
V_2 -> V_36 = F_58 ( sizeof( * V_2 -> V_36 ) , V_250 ) ;
if ( ! V_2 -> V_36 ) {
V_57 = - V_173 ;
goto V_251;
}
V_57 = F_14 ( V_4 , V_2 -> V_36 ) ;
if ( V_57 < 0 ) {
V_247 = L_37 ;
goto V_251;
} else if ( V_2 -> V_36 -> V_252 > V_253 ) {
V_247 = L_38 ;
V_57 = - V_120 ;
goto V_251;
} else if ( V_2 -> V_36 -> V_252 == 0 ) {
V_247 = L_39 ;
V_57 = - V_120 ;
goto V_251;
}
V_9 = V_2 -> V_36 -> V_252 ;
F_8 ( V_242 , L_40 , V_9 ,
( V_9 == 1 ) ? L_41 : L_42 ) ;
V_2 -> V_82 = F_97 ( V_9 * sizeof( struct V_80 * ) , V_250 ) ;
if ( ! V_2 -> V_82 ) {
V_57 = - V_173 ;
goto V_251;
}
V_245 = F_13 ( V_2 -> V_36 -> V_245 ) ;
if ( F_3 ( V_4 ) ) {
V_248 = 150 ;
V_249 = 900 ;
} else {
V_248 = 100 ;
V_249 = 500 ;
}
if ( ( V_245 & V_254 ) &&
! ( F_3 ( V_4 ) ) ) {
char V_255 [ V_253 + 1 ] ;
for ( V_56 = 0 ; V_56 < V_9 ; V_56 ++ )
V_255 [ V_56 ] = V_2 -> V_36 -> V_37 . V_256 . V_257
[ ( ( V_56 + 1 ) / 8 ) ] & ( 1 << ( ( V_56 + 1 ) % 8 ) )
? 'F' : 'R' ;
V_255 [ V_9 ] = 0 ;
F_23 ( V_242 , L_43 , V_255 ) ;
} else
F_23 ( V_242 , L_44 ) ;
switch ( V_245 & V_258 ) {
case V_259 :
F_23 ( V_242 , L_45 ) ;
break;
case V_260 :
F_23 ( V_242 , L_46 ) ;
break;
case V_261 :
case V_258 :
F_23 ( V_242 , L_47 ) ;
break;
}
switch ( V_245 & V_262 ) {
case V_263 :
F_23 ( V_242 , L_48 ) ;
break;
case V_264 :
F_23 ( V_242 , L_49 ) ;
break;
case V_265 :
case V_262 :
F_23 ( V_242 , L_50 ) ;
break;
}
F_98 ( & V_2 -> V_150 . V_156 ) ;
F_99 ( & V_2 -> V_150 . V_157 ) ;
F_100 ( & V_2 -> V_150 . V_154 , F_48 ) ;
switch ( V_4 -> V_36 . V_266 ) {
case V_267 :
break;
case V_268 :
F_23 ( V_242 , L_51 ) ;
V_2 -> V_150 . V_2 = V_4 ;
break;
case V_269 :
V_57 = F_101 ( V_4 , 0 , 1 ) ;
if ( V_57 == 0 ) {
F_23 ( V_242 , L_52 ) ;
V_2 -> V_150 . V_174 = 1 ;
} else
F_31 ( V_242 , L_53 ,
V_57 ) ;
V_2 -> V_150 . V_2 = V_4 ;
break;
case V_270 :
break;
default:
F_23 ( V_242 , L_54 ,
V_4 -> V_36 . V_266 ) ;
break;
}
switch ( V_245 & V_271 ) {
case V_272 :
if ( V_4 -> V_36 . V_266 != 0 ) {
V_2 -> V_150 . V_273 = 666 ;
F_23 ( V_242 , L_55
L_56 ,
8 , V_2 -> V_150 . V_273 ) ;
}
break;
case V_274 :
V_2 -> V_150 . V_273 = 666 * 2 ;
F_23 ( V_242 , L_55
L_56 ,
16 , V_2 -> V_150 . V_273 ) ;
break;
case V_275 :
V_2 -> V_150 . V_273 = 666 * 3 ;
F_23 ( V_242 , L_55
L_56 ,
24 , V_2 -> V_150 . V_273 ) ;
break;
case V_276 :
V_2 -> V_150 . V_273 = 666 * 4 ;
F_23 ( V_242 , L_55
L_56 ,
32 , V_2 -> V_150 . V_273 ) ;
break;
}
if ( V_245 & V_277 ) {
V_2 -> V_232 = 1 ;
F_23 ( V_242 , L_57 ) ;
}
F_23 ( V_242 , L_58 ,
V_2 -> V_36 -> V_278 * 2 ) ;
V_57 = F_102 ( V_4 , V_279 , 0 , & V_243 ) ;
if ( V_57 ) {
V_247 = L_59 ;
goto V_251;
}
V_164 = F_62 ( V_4 -> V_178 ) ;
if ( V_4 == V_4 -> V_178 -> V_280 ) {
if ( V_164 -> V_281 > 0 )
V_4 -> V_282 = V_164 -> V_281 ;
else
V_4 -> V_282 = V_249 * V_9 ;
if ( V_4 -> V_282 >= V_249 )
V_2 -> V_283 = V_249 ;
else {
V_2 -> V_283 = V_4 -> V_282 ;
V_2 -> V_284 = 1 ;
}
} else if ( ( V_243 & ( 1 << V_285 ) ) == 0 ) {
int V_286 = V_4 -> V_282 -
V_2 -> V_36 -> V_287 ;
F_23 ( V_242 , L_60 ,
V_2 -> V_36 -> V_287 ) ;
V_2 -> V_284 = 1 ;
if ( V_286 < V_9 * V_248 )
F_73 ( V_242 ,
L_61
L_62 ) ;
V_2 -> V_283 = V_248 ;
} else {
V_2 -> V_283 = V_249 ;
}
if ( V_2 -> V_283 < V_249 )
F_23 ( V_242 , L_63 ,
V_2 -> V_283 ) ;
V_57 = F_70 ( V_2 , & V_243 , & V_244 ) ;
if ( V_57 < 0 ) {
V_247 = L_59 ;
goto V_251;
}
if ( V_4 -> V_8 -> V_288 . V_20 & V_289 )
F_23 ( V_242 , L_64 ,
( V_243 & V_290 )
? L_65 : L_66 ) ;
if ( ( V_245 & V_262 ) == 0 )
F_23 ( V_242 , L_67 ,
( V_243 & V_291 ) ? L_41 : L_68 ) ;
V_171 = F_103 ( V_4 , V_240 -> V_292 ) ;
V_246 = F_104 ( V_4 , V_171 , F_105 ( V_171 ) ) ;
if ( V_246 > sizeof( * V_2 -> V_145 ) )
V_246 = sizeof( * V_2 -> V_145 ) ;
V_2 -> V_136 = F_106 ( 0 , V_250 ) ;
if ( ! V_2 -> V_136 ) {
V_57 = - V_173 ;
goto V_251;
}
F_107 ( V_2 -> V_136 , V_4 , V_171 , * V_2 -> V_145 , V_246 , F_45 ,
V_2 , V_240 -> V_293 ) ;
if ( V_2 -> V_232 && V_103 )
V_2 -> V_94 [ 0 ] = V_95 ;
F_30 ( & V_294 ) ;
for ( V_56 = 0 ; V_56 < V_9 ; V_56 ++ ) {
V_57 = F_108 ( V_2 , V_56 + 1 ) ;
if ( V_57 < 0 ) {
F_31 ( V_2 -> V_121 ,
L_69 , V_56 + 1 ) ;
break;
}
}
V_4 -> V_9 = V_56 ;
for ( V_56 = 0 ; V_56 < V_4 -> V_9 ; V_56 ++ ) {
struct V_80 * V_81 = V_2 -> V_82 [ V_56 ] ;
F_109 ( & V_81 -> V_22 ) ;
}
F_32 ( & V_294 ) ;
if ( V_57 < 0 )
goto V_251;
if ( V_164 -> V_165 -> V_213 ) {
V_57 = V_164 -> V_165 -> V_213 ( V_164 , V_4 ,
& V_2 -> V_150 , V_250 ) ;
if ( V_57 < 0 ) {
V_247 = L_70 ;
goto V_251;
}
}
F_110 ( V_4 , V_2 -> V_36 ) ;
F_80 ( V_2 , V_209 ) ;
return 0 ;
V_251:
F_31 ( V_242 , L_71 ,
V_247 , V_57 ) ;
return V_57 ;
}
static void V_133 ( struct V_131 * V_131 )
{
struct V_1 * V_2 = F_25 ( V_131 , struct V_1 , V_131 ) ;
F_111 ( V_2 -> V_4 ) ;
F_112 ( F_36 ( V_2 -> V_121 ) ) ;
F_54 ( V_2 ) ;
}
static void F_113 ( struct V_127 * V_128 )
{
struct V_1 * V_2 = F_5 ( V_128 ) ;
struct V_7 * V_4 = F_114 ( V_128 ) ;
int V_72 ;
V_2 -> V_129 = 1 ;
V_2 -> error = 0 ;
F_86 ( V_2 , V_295 ) ;
F_30 ( & V_294 ) ;
F_115 ( & V_296 ) ;
V_72 = V_4 -> V_9 ;
V_4 -> V_9 = 0 ;
F_116 ( V_128 , NULL ) ;
F_117 ( & V_296 ) ;
for (; V_72 > 0 ; -- V_72 )
F_118 ( V_2 , V_72 ) ;
F_32 ( & V_294 ) ;
if ( V_2 -> V_4 -> V_14 == V_15 )
V_297 -- ;
F_119 ( V_2 -> V_136 ) ;
F_54 ( V_2 -> V_82 ) ;
F_54 ( V_2 -> V_36 ) ;
F_54 ( V_2 -> V_83 ) ;
F_54 ( V_2 -> V_145 ) ;
F_120 ( & V_128 -> V_22 , false ) ;
F_41 ( & V_2 -> V_131 , V_133 ) ;
}
static int F_121 ( struct V_127 * V_128 , const struct V_298 * V_299 )
{
struct V_300 * V_288 ;
struct V_239 * V_240 ;
struct V_7 * V_4 ;
struct V_1 * V_2 ;
V_288 = V_128 -> V_301 ;
V_4 = F_114 ( V_128 ) ;
#ifdef F_84
if ( V_4 -> V_22 . V_302 . V_303 >= 0 )
F_122 ( & V_4 -> V_22 , 0 ) ;
#endif
if ( V_4 -> V_25 ) {
F_123 ( V_4 ) ;
} else {
const struct V_162 * V_163 = F_62 ( V_4 -> V_178 ) -> V_165 ;
if ( V_163 -> V_304 && V_163 -> V_305 )
F_123 ( V_4 ) ;
}
if ( V_4 -> V_207 == V_306 ) {
F_31 ( & V_128 -> V_22 ,
L_72 ) ;
return - V_307 ;
}
#ifdef F_124
if ( V_4 -> V_25 ) {
F_73 ( & V_128 -> V_22 , L_73 ) ;
return - V_120 ;
}
#endif
if ( ( V_288 -> V_288 . V_308 != 0 ) &&
( V_288 -> V_288 . V_308 != 1 ) ) {
V_309:
F_31 ( & V_128 -> V_22 , L_74 ) ;
return - V_123 ;
}
if ( V_288 -> V_288 . V_310 != 1 )
goto V_309;
V_240 = & V_288 -> V_240 [ 0 ] . V_288 ;
if ( ! F_125 ( V_240 ) )
goto V_309;
F_8 ( & V_128 -> V_22 , L_75 ) ;
V_2 = F_97 ( sizeof( * V_2 ) , V_250 ) ;
if ( ! V_2 )
return - V_173 ;
F_126 ( & V_2 -> V_131 ) ;
V_2 -> V_121 = & V_128 -> V_22 ;
V_2 -> V_4 = V_4 ;
F_82 ( & V_2 -> V_87 , F_24 ) ;
F_82 ( & V_2 -> V_210 , NULL ) ;
F_100 ( & V_2 -> V_130 , V_311 ) ;
F_127 ( V_128 ) ;
F_128 ( V_4 ) ;
F_116 ( V_128 , V_2 ) ;
V_128 -> V_312 = 1 ;
F_120 ( & V_128 -> V_22 , true ) ;
if ( V_4 -> V_14 == V_15 )
V_297 ++ ;
if ( V_299 -> V_313 & V_314 )
V_2 -> V_315 = 1 ;
if ( F_95 ( V_2 , V_240 ) >= 0 )
return 0 ;
F_113 ( V_128 ) ;
return - V_120 ;
}
static int
F_129 ( struct V_127 * V_128 , unsigned int V_316 , void * V_317 )
{
struct V_7 * V_4 = F_114 ( V_128 ) ;
struct V_1 * V_2 = F_4 ( V_4 ) ;
switch ( V_316 ) {
case V_318 : {
struct V_319 * V_320 = V_317 ;
int V_56 ;
F_115 ( & V_296 ) ;
if ( V_4 -> V_176 <= 0 )
V_320 -> V_321 = 0 ;
else {
V_320 -> V_321 = V_4 -> V_9 ;
for ( V_56 = 0 ; V_56 < V_320 -> V_321 ; V_56 ++ ) {
if ( V_2 -> V_82 [ V_56 ] -> V_192 == NULL )
V_320 -> V_119 [ V_56 ] = 0 ;
else
V_320 -> V_119 [ V_56 ] =
V_2 -> V_82 [ V_56 ] -> V_192 -> V_176 ;
}
}
F_117 ( & V_296 ) ;
return V_320 -> V_321 + 1 ;
}
default:
return - V_322 ;
}
}
static int F_130 ( struct V_7 * V_4 , unsigned V_72 ,
struct V_323 * * * V_324 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
if ( V_4 -> V_90 == V_193 )
return - V_120 ;
if ( V_72 == 0 || V_72 > V_4 -> V_9 )
return - V_69 ;
* V_324 = & ( V_2 -> V_82 [ V_72 - 1 ] -> V_325 ) ;
return 0 ;
}
int F_131 ( struct V_7 * V_4 , unsigned V_72 ,
struct V_323 * V_326 )
{
int V_327 ;
struct V_323 * * V_328 ;
V_327 = F_130 ( V_4 , V_72 , & V_328 ) ;
if ( V_327 )
return V_327 ;
if ( * V_328 )
return - V_329 ;
* V_328 = V_326 ;
return V_327 ;
}
int F_132 ( struct V_7 * V_4 , unsigned V_72 ,
struct V_323 * V_326 )
{
int V_327 ;
struct V_323 * * V_328 ;
V_327 = F_130 ( V_4 , V_72 , & V_328 ) ;
if ( V_327 )
return V_327 ;
if ( * V_328 != V_326 )
return - V_139 ;
* V_328 = NULL ;
return V_327 ;
}
void F_133 ( struct V_7 * V_4 , struct V_323 * V_326 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
int V_330 ;
for ( V_330 = 0 ; V_330 < V_4 -> V_9 ; V_330 ++ ) {
if ( V_2 -> V_82 [ V_330 ] -> V_325 == V_326 )
V_2 -> V_82 [ V_330 ] -> V_325 = NULL ;
}
}
bool F_134 ( struct V_7 * V_11 )
{
struct V_1 * V_2 ;
if ( V_11 -> V_90 == V_193 || ! V_11 -> V_25 )
return false ;
V_2 = F_4 ( V_11 -> V_25 ) ;
return ! ! V_2 -> V_82 [ V_11 -> V_134 - 1 ] -> V_325 ;
}
static void F_135 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_4 ( V_11 ) ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_11 -> V_9 ; ++ V_56 ) {
if ( V_2 -> V_82 [ V_56 ] -> V_192 )
F_135 ( V_2 -> V_82 [ V_56 ] -> V_192 ) ;
}
if ( V_11 -> V_90 == V_331 )
V_11 -> V_332 -= V_333 ;
V_11 -> V_90 = V_193 ;
}
void F_75 ( struct V_7 * V_11 ,
enum V_334 V_335 )
{
unsigned long V_155 ;
int V_336 = - 1 ;
F_49 ( & V_296 , V_155 ) ;
if ( V_11 -> V_90 == V_193 )
;
else if ( V_335 != V_193 ) {
if ( V_11 -> V_25 ) {
if ( V_11 -> V_90 == V_331
|| V_335 == V_331 )
;
else if ( V_335 == V_91 )
V_336 = ( V_11 -> V_12 &
V_337 ) ? 0 :
V_11 -> V_8 -> V_288 . V_20 &
V_338 ;
else
V_336 = 0 ;
}
if ( V_11 -> V_90 == V_331 &&
V_335 != V_331 )
V_11 -> V_332 -= V_333 ;
else if ( V_335 == V_331 &&
V_11 -> V_90 != V_331 )
V_11 -> V_332 += V_333 ;
V_11 -> V_90 = V_335 ;
} else
F_135 ( V_11 ) ;
F_53 ( & V_296 , V_155 ) ;
if ( V_336 >= 0 )
F_136 ( & V_11 -> V_22 , V_336 ) ;
}
static void F_137 ( struct V_7 * V_11 )
{
int V_176 ;
struct V_339 * V_178 = V_11 -> V_178 ;
F_30 ( & V_178 -> V_340 ) ;
if ( V_11 -> V_341 ) {
V_176 = V_11 -> V_134 + 1 ;
F_138 ( F_67 ( V_176 , V_178 -> V_342 . V_343 ) ) ;
} else {
V_176 = F_139 ( V_178 -> V_342 . V_343 , 128 ,
V_178 -> V_344 ) ;
if ( V_176 >= 128 )
V_176 = F_139 ( V_178 -> V_342 . V_343 ,
128 , 1 ) ;
V_178 -> V_344 = ( V_176 >= 127 ? 1 : V_176 + 1 ) ;
}
if ( V_176 < 128 ) {
F_44 ( V_176 , V_178 -> V_342 . V_343 ) ;
V_11 -> V_176 = V_176 ;
}
F_32 ( & V_178 -> V_340 ) ;
}
static void F_140 ( struct V_7 * V_11 )
{
if ( V_11 -> V_176 > 0 ) {
F_56 ( V_11 -> V_176 , V_11 -> V_178 -> V_342 . V_343 ) ;
V_11 -> V_176 = - 1 ;
}
}
static void F_141 ( struct V_7 * V_11 , int V_176 )
{
if ( ! V_11 -> V_341 )
V_11 -> V_176 = V_176 ;
}
static void F_142 ( struct V_7 * V_11 )
{
struct V_198 * V_164 = F_62 ( V_11 -> V_178 ) ;
if ( V_164 -> V_165 -> V_345 && V_11 -> V_25 )
V_164 -> V_165 -> V_345 ( V_164 , V_11 ) ;
}
static void F_143 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_4 ( V_11 ) ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_11 -> V_9 ; V_56 ++ ) {
if ( V_2 -> V_82 [ V_56 ] -> V_192 )
F_87 ( & V_2 -> V_82 [ V_56 ] -> V_192 ) ;
}
}
void F_87 ( struct V_7 * * V_346 )
{
struct V_80 * V_81 = NULL ;
struct V_7 * V_11 = * V_346 ;
struct V_1 * V_2 = NULL ;
int V_72 = 1 ;
F_75 ( V_11 , V_193 ) ;
F_8 ( & V_11 -> V_22 , L_76 ,
V_11 -> V_176 ) ;
F_144 ( V_11 ) ;
F_143 ( V_11 ) ;
F_23 ( & V_11 -> V_22 , L_77 ) ;
F_145 ( V_11 , 0 ) ;
F_146 ( V_11 ) ;
if ( V_11 -> V_25 ) {
V_72 = V_11 -> V_134 ;
V_2 = F_4 ( V_11 -> V_25 ) ;
V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
F_147 ( & V_11 -> V_22 . V_347 , L_78 ) ;
F_147 ( & V_81 -> V_22 . V_347 , L_79 ) ;
if ( ! F_148 ( V_72 , V_2 -> V_348 ) )
F_149 ( & V_81 -> V_22 ) ;
}
F_150 ( & V_11 -> V_349 ) ;
F_151 ( V_11 ) ;
F_152 ( & V_11 -> V_22 ) ;
F_140 ( V_11 ) ;
F_115 ( & V_296 ) ;
* V_346 = NULL ;
F_117 ( & V_296 ) ;
if ( V_81 && F_153 ( V_72 , V_2 -> V_348 ) )
F_109 ( & V_81 -> V_22 ) ;
F_142 ( V_11 ) ;
F_154 ( & V_11 -> V_22 ) ;
}
static void F_155 ( struct V_7 * V_11 , char * V_299 , char * string )
{
if ( ! string )
return;
F_8 ( & V_11 -> V_22 , L_80 , V_299 , string ) ;
}
static void F_156 ( struct V_7 * V_11 )
{
F_8 ( & V_11 -> V_22 , L_81 ,
F_13 ( V_11 -> V_36 . V_350 ) ,
F_13 ( V_11 -> V_36 . V_351 ) ) ;
F_8 ( & V_11 -> V_22 ,
L_82 ,
V_11 -> V_36 . V_352 ,
V_11 -> V_36 . V_353 ,
V_11 -> V_36 . V_354 ) ;
F_155 ( V_11 , L_83 , V_11 -> V_355 ) ;
F_155 ( V_11 , L_84 , V_11 -> V_356 ) ;
F_155 ( V_11 , L_85 , V_11 -> V_357 ) ;
}
static inline void F_156 ( struct V_7 * V_11 ) { }
static int F_157 ( struct V_7 * V_11 )
{
int V_358 = 0 ;
#ifdef F_158
if ( ! V_11 -> V_178 -> V_359
&& V_11 -> V_360
&& V_11 -> V_25 == V_11 -> V_178 -> V_280 ) {
struct V_361 * V_288 = NULL ;
struct V_339 * V_178 = V_11 -> V_178 ;
unsigned V_72 = V_11 -> V_134 ;
V_358 = F_159 ( V_11 -> V_362 [ 0 ] ,
F_13 ( V_11 -> V_360 [ 0 ] . V_288 . V_363 ) ,
V_364 , ( void * * ) & V_288 ) ;
if ( V_358 || ! ( V_288 -> V_20 & V_365 ) )
return 0 ;
F_8 ( & V_11 -> V_22 , L_86 ,
( V_72 == V_178 -> V_366 ) ? L_41 : L_87 ) ;
if ( V_72 == V_178 -> V_366 ) {
V_178 -> V_367 = 1 ;
V_358 = F_15 ( V_11 ,
F_18 ( V_11 , 0 ) ,
V_74 , 0 ,
V_368 ,
0 , NULL , 0 ,
V_208 ) ;
if ( V_358 < 0 ) {
F_31 ( & V_11 -> V_22 , L_88 ,
V_358 ) ;
V_178 -> V_367 = 0 ;
}
} else if ( V_288 -> V_369 == sizeof
( struct V_361 ) ) {
V_358 = F_15 ( V_11 ,
F_18 ( V_11 , 0 ) ,
V_74 , 0 ,
V_370 ,
0 , NULL , 0 ,
V_208 ) ;
if ( V_358 < 0 )
F_31 ( & V_11 -> V_22 ,
L_89 ,
V_358 ) ;
}
}
#endif
return V_358 ;
}
static int F_160 ( struct V_7 * V_11 )
{
int V_358 ;
struct V_198 * V_164 = F_62 ( V_11 -> V_178 ) ;
if ( V_11 -> V_360 == NULL ) {
V_358 = F_161 ( V_11 ) ;
if ( V_358 < 0 ) {
if ( V_358 != - V_120 )
F_31 ( & V_11 -> V_22 , L_90 ,
V_358 ) ;
return V_358 ;
}
}
V_11 -> V_355 = F_162 ( V_11 , V_11 -> V_36 . V_353 ) ;
V_11 -> V_356 = F_162 ( V_11 ,
V_11 -> V_36 . V_352 ) ;
V_11 -> V_357 = F_162 ( V_11 , V_11 -> V_36 . V_354 ) ;
V_358 = F_157 ( V_11 ) ;
if ( V_358 < 0 )
return V_358 ;
if ( F_163 ( V_371 ) && V_164 -> V_372 &&
! F_164 ( V_11 ) ) {
if ( F_163 ( F_158 ) && ( V_11 -> V_178 -> V_367
|| V_11 -> V_178 -> V_359 ) ) {
V_358 = F_165 ( V_11 , V_373 ) ;
if ( V_358 < 0 )
F_23 ( & V_11 -> V_22 , L_91 , V_358 ) ;
}
return - V_374 ;
}
F_166 ( V_11 ) ;
return 0 ;
}
static void F_167 ( struct V_7 * V_11 )
{
struct V_7 * V_4 = V_11 -> V_25 ;
struct V_1 * V_2 ;
T_3 V_119 = V_11 -> V_134 ;
T_1 V_245 ;
bool V_375 = true ;
if ( ! V_4 )
return;
V_2 = F_4 ( V_11 -> V_25 ) ;
switch ( V_2 -> V_82 [ V_11 -> V_134 - 1 ] -> V_376 ) {
case V_377 :
V_11 -> V_375 = V_378 ;
return;
case V_379 :
case V_380 :
V_11 -> V_375 = V_381 ;
return;
default:
break;
}
V_245 = F_13 ( V_2 -> V_36 -> V_245 ) ;
if ( ! ( V_245 & V_254 ) )
return;
if ( F_3 ( V_4 ) ) {
if ( F_13 ( V_2 -> V_36 -> V_37 . V_38 . V_257 )
& ( 1 << V_119 ) )
V_375 = false ;
} else {
if ( V_2 -> V_36 -> V_37 . V_256 . V_257 [ V_119 / 8 ] & ( 1 << ( V_119 % 8 ) ) )
V_375 = false ;
}
if ( V_375 )
V_11 -> V_375 = V_378 ;
else
V_11 -> V_375 = V_381 ;
}
int F_168 ( struct V_7 * V_11 )
{
int V_358 ;
if ( V_11 -> V_25 ) {
F_169 ( & V_11 -> V_22 , 0 ) ;
}
F_170 ( & V_11 -> V_22 ) ;
F_171 ( & V_11 -> V_22 ) ;
F_172 ( & V_11 -> V_22 ) ;
F_173 ( & V_11 -> V_22 ) ;
F_174 ( V_11 ) ;
V_358 = F_160 ( V_11 ) ;
if ( V_358 < 0 )
goto V_251;
F_23 ( & V_11 -> V_22 , L_92 ,
V_11 -> V_176 , V_11 -> V_178 -> V_382 ,
( ( ( V_11 -> V_178 -> V_382 - 1 ) * 128 ) + ( V_11 -> V_176 - 1 ) ) ) ;
V_11 -> V_22 . V_383 = F_175 ( V_384 ,
( ( ( V_11 -> V_178 -> V_382 - 1 ) * 128 ) + ( V_11 -> V_176 - 1 ) ) ) ;
F_156 ( V_11 ) ;
if ( V_11 -> V_357 )
F_176 ( V_11 -> V_357 , strlen ( V_11 -> V_357 ) ) ;
if ( V_11 -> V_355 )
F_176 ( V_11 -> V_355 , strlen ( V_11 -> V_355 ) ) ;
if ( V_11 -> V_356 )
F_176 ( V_11 -> V_356 ,
strlen ( V_11 -> V_356 ) ) ;
F_177 ( & V_11 -> V_22 ) ;
if ( V_11 -> V_25 )
F_167 ( V_11 ) ;
V_358 = F_178 ( & V_11 -> V_22 ) ;
if ( V_358 ) {
F_31 ( & V_11 -> V_22 , L_93 , V_358 ) ;
goto V_251;
}
if ( V_11 -> V_25 ) {
struct V_1 * V_2 = F_4 ( V_11 -> V_25 ) ;
int V_72 = V_11 -> V_134 ;
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
V_358 = F_179 ( & V_11 -> V_22 . V_347 ,
& V_81 -> V_22 . V_347 , L_78 ) ;
if ( V_358 )
goto V_251;
V_358 = F_179 ( & V_81 -> V_22 . V_347 ,
& V_11 -> V_22 . V_347 , L_79 ) ;
if ( V_358 ) {
F_147 ( & V_11 -> V_22 . V_347 , L_78 ) ;
goto V_251;
}
if ( ! F_148 ( V_72 , V_2 -> V_348 ) )
F_149 ( & V_81 -> V_22 ) ;
}
( void ) F_180 ( & V_11 -> V_22 , & V_11 -> V_349 , V_11 ) ;
F_181 ( V_11 ) ;
F_182 ( & V_11 -> V_22 ) ;
return V_358 ;
V_251:
F_75 ( V_11 , V_193 ) ;
F_183 ( & V_11 -> V_22 ) ;
F_184 ( & V_11 -> V_22 ) ;
return V_358 ;
}
int F_185 ( struct V_7 * V_385 )
{
F_144 ( V_385 ) ;
if ( V_385 -> V_386 == 0 )
goto V_387;
V_385 -> V_386 = 0 ;
F_186 ( V_385 , - 1 ) ;
V_387:
F_151 ( V_385 ) ;
return 0 ;
}
int F_187 ( struct V_7 * V_385 )
{
int V_388 = 0 , V_389 ;
F_144 ( V_385 ) ;
if ( V_385 -> V_386 == 1 )
goto V_390;
V_388 = F_188 ( V_385 ) ;
if ( V_388 < 0 ) {
F_31 ( & V_385 -> V_22 ,
L_94 , V_388 ) ;
goto V_391;
}
if ( V_385 -> V_341 ) {
V_388 = F_189 ( V_385 , sizeof( V_385 -> V_36 ) ) ;
if ( V_388 < 0 ) {
F_31 ( & V_385 -> V_22 , L_95
L_96 , V_388 ) ;
goto V_392;
}
}
V_385 -> V_386 = 1 ;
V_389 = F_190 ( V_385 ) ;
if ( V_389 >= 0 ) {
V_388 = F_186 ( V_385 , V_389 ) ;
if ( V_388 ) {
F_31 ( & V_385 -> V_22 ,
L_97 , V_389 , V_388 ) ;
}
}
F_8 ( & V_385 -> V_22 , L_98 ) ;
V_392:
F_191 ( V_385 ) ;
V_391:
V_390:
F_151 ( V_385 ) ;
return V_388 ;
}
static int F_192 ( struct V_7 * V_4 , int V_393 )
{
int V_394 ;
T_2 V_395 ;
int V_56 ;
struct V_396 * V_397 = V_4 -> V_17 -> V_397 ;
if ( ! V_397 )
return 0 ;
V_394 = F_7 ( V_397 -> V_20 ) &
V_398 ;
for ( V_56 = 0 ; V_56 <= V_394 ; V_56 ++ ) {
V_395 = F_7 ( V_397 -> V_399 [ V_56 ] ) ;
if ( V_393 == ( V_395 & V_400 ) )
return ! ! ( V_395 & V_401 ) ;
}
return 0 ;
}
static unsigned F_193 ( struct V_1 * V_2 )
{
struct V_198 * V_164 ;
if ( V_2 -> V_4 -> V_25 != NULL )
return 0 ;
V_164 = F_62 ( V_2 -> V_4 -> V_178 ) ;
return V_164 -> V_402 ;
}
static bool F_194 ( struct V_7 * V_11 , int V_403 )
{
if ( V_11 -> V_14 >= V_52 )
return false ;
return F_195 ( V_403 ) ;
}
static bool F_196 ( struct V_1 * V_2 , int V_72 ,
T_1 V_3 )
{
T_1 V_404 ;
if ( ! F_3 ( V_2 -> V_4 ) )
return false ;
if ( F_67 ( V_72 , V_2 -> V_405 ) )
return true ;
V_404 = V_3 & V_186 ;
return V_404 == V_406
|| V_404 == V_407 ;
}
static int F_197 ( struct V_1 * V_2 , int V_72 ,
struct V_7 * V_11 , unsigned int V_200 , bool V_408 )
{
int V_409 , V_57 ;
T_1 V_3 ;
T_1 V_185 ;
T_2 V_410 = 0 ;
for ( V_409 = 0 ;
V_409 < V_411 ;
V_409 += V_200 ) {
F_68 ( V_200 ) ;
if ( F_2 ( V_2 -> V_4 ) )
V_57 = F_29 ( V_2 , V_72 ,
V_412 ,
& V_3 , & V_185 ,
& V_410 ) ;
else
V_57 = F_33 ( V_2 , V_72 , & V_3 ,
& V_185 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( ! ( V_3 & V_413 ) )
break;
if ( V_409 >= 2 * V_414 )
V_200 = V_415 ;
F_23 ( & V_2 -> V_82 [ V_72 - 1 ] -> V_22 ,
L_99 ,
V_408 ? L_100 : L_41 , V_200 ) ;
}
if ( ( V_3 & V_413 ) )
return - V_329 ;
if ( F_196 ( V_2 , V_72 , V_3 ) )
return - V_416 ;
if ( ! ( V_3 & V_215 ) )
return - V_416 ;
if ( ! F_3 ( V_2 -> V_4 ) &&
( V_185 & V_217 ) )
return - V_416 ;
if ( ! ( V_3 & V_216 ) )
return - V_329 ;
if ( ! V_11 )
return 0 ;
if ( F_193 ( V_2 ) )
V_11 -> V_14 = V_417 ;
else if ( F_2 ( V_2 -> V_4 ) &&
F_192 ( V_2 -> V_4 , V_410 &
V_418 ) )
V_11 -> V_14 = V_419 ;
else if ( F_3 ( V_2 -> V_4 ) )
V_11 -> V_14 = V_52 ;
else if ( V_3 & V_5 )
V_11 -> V_14 = V_15 ;
else if ( V_3 & V_6 )
V_11 -> V_14 = V_420 ;
else
V_11 -> V_14 = V_16 ;
return 0 ;
}
static int F_198 ( struct V_1 * V_2 , int V_72 ,
struct V_7 * V_11 , unsigned int V_200 , bool V_408 )
{
int V_56 , V_83 ;
T_1 V_185 , V_3 ;
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
if ( ! F_3 ( V_2 -> V_4 ) ) {
if ( V_408 ) {
F_31 ( V_2 -> V_121 , L_101
L_102 ) ;
return - V_69 ;
}
F_199 ( & V_421 ) ;
} else if ( ! V_408 ) {
if ( F_33 ( V_2 , V_72 , & V_3 , & V_185 ) == 0 )
if ( F_196 ( V_2 , V_72 ,
V_3 ) )
V_408 = true ;
}
F_56 ( V_72 , V_2 -> V_405 ) ;
for ( V_56 = 0 ; V_56 < V_422 ; V_56 ++ ) {
V_83 = F_20 ( V_2 -> V_4 , V_72 , ( V_408 ?
V_423 :
V_424 ) ) ;
if ( V_83 == - V_120 ) {
;
} else if ( V_83 ) {
F_31 ( & V_81 -> V_22 ,
L_103 ,
V_408 ? L_100 : L_41 , V_83 ) ;
} else {
V_83 = F_197 ( V_2 , V_72 , V_11 , V_200 ,
V_408 ) ;
if ( V_83 && V_83 != - V_416 && V_83 != - V_120 )
F_23 ( V_2 -> V_121 ,
L_104 ,
V_83 ) ;
}
if ( V_83 == 0 || V_83 == - V_416 || V_83 == - V_120 ) {
F_19 ( V_2 -> V_4 , V_72 ,
V_222 ) ;
if ( ! F_3 ( V_2 -> V_4 ) )
goto V_425;
F_19 ( V_2 -> V_4 , V_72 ,
V_224 ) ;
F_19 ( V_2 -> V_4 , V_72 ,
V_426 ) ;
F_19 ( V_2 -> V_4 , V_72 ,
V_218 ) ;
if ( F_33 ( V_2 , V_72 ,
& V_3 , & V_185 ) < 0 )
goto V_425;
if ( ! F_196 ( V_2 , V_72 ,
V_3 ) )
goto V_425;
if ( ! V_408 ) {
F_23 ( & V_81 -> V_22 ,
L_105 ) ;
V_408 = true ;
}
}
F_23 ( & V_81 -> V_22 ,
L_106 ,
V_408 ? L_100 : L_41 ) ;
V_200 = V_415 ;
}
F_31 ( & V_81 -> V_22 , L_107 ) ;
V_425:
if ( V_83 == 0 ) {
F_68 ( 10 + 40 ) ;
if ( V_11 ) {
struct V_198 * V_164 = F_62 ( V_11 -> V_178 ) ;
F_141 ( V_11 , 0 ) ;
if ( V_164 -> V_165 -> V_427 )
V_164 -> V_165 -> V_427 ( V_164 , V_11 ) ;
F_75 ( V_11 , V_428 ) ;
}
} else {
if ( V_11 )
F_75 ( V_11 , V_193 ) ;
}
if ( ! F_3 ( V_2 -> V_4 ) )
F_200 ( & V_421 ) ;
return V_83 ;
}
static int F_201 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_57 = 0 ;
if ( F_3 ( V_2 -> V_4 ) ) {
if ( V_3 & V_429 )
V_57 = 1 ;
} else {
if ( V_3 & V_430 )
V_57 = 1 ;
}
return V_57 ;
}
static void F_202 ( struct V_80 * V_81 )
__acquires( &port_dev->status_lock
static void F_203 ( struct V_80 * V_81 )
__releases( &port_dev->status_lock
static int F_204 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_57 = 0 ;
if ( F_3 ( V_2 -> V_4 ) ) {
if ( ( V_3 & V_186 )
== V_431 )
V_57 = 1 ;
} else {
if ( V_3 & V_432 )
V_57 = 1 ;
}
return V_57 ;
}
static int F_205 ( struct V_7 * V_11 ,
struct V_1 * V_2 , int V_72 ,
int V_83 , T_1 V_185 , T_1 V_3 )
{
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
int V_433 = 3 ;
V_403:
if ( V_83 == 0 && V_11 -> V_229
&& F_196 ( V_2 , V_72 , V_3 ) ) {
;
}
else if ( V_83 || F_204 ( V_2 , V_3 ) ||
! F_201 ( V_2 , V_3 ) ) {
if ( V_83 >= 0 )
V_83 = - V_120 ;
} else if ( ! ( V_3 & V_215 ) ) {
if ( V_433 -- ) {
F_206 ( 200 , 300 ) ;
V_83 = F_33 ( V_2 , V_72 , & V_3 ,
& V_185 ) ;
goto V_403;
}
V_83 = - V_120 ;
}
else if ( ! ( V_3 & V_216 ) && ! V_11 -> V_229 ) {
if ( V_11 -> V_228 )
V_11 -> V_229 = 1 ;
else
V_83 = - V_120 ;
}
if ( V_83 ) {
F_23 ( & V_81 -> V_22 , L_108 ,
V_185 , V_3 , V_83 ) ;
} else if ( V_11 -> V_229 ) {
if ( V_185 & V_217 )
F_19 ( V_2 -> V_4 , V_72 ,
V_218 ) ;
if ( V_185 & V_219 )
F_19 ( V_2 -> V_4 , V_72 ,
V_220 ) ;
}
return V_83 ;
}
int F_207 ( struct V_7 * V_11 )
{
struct V_198 * V_164 = F_62 ( V_11 -> V_178 ) ;
if ( ! F_208 ( V_164 -> V_434 . V_280 ) ||
! F_208 ( V_11 ) )
return 0 ;
if ( ! V_11 -> V_8 )
return 0 ;
return F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_71 , V_279 ,
V_435 , 0 , NULL , 0 ,
V_208 ) ;
}
void F_209 ( struct V_7 * V_11 )
{
struct V_198 * V_164 = F_62 ( V_11 -> V_178 ) ;
if ( ! F_208 ( V_164 -> V_434 . V_280 ) ||
! F_208 ( V_11 ) )
return;
if ( ! V_11 -> V_8 )
return;
F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_74 , V_279 ,
V_435 , 0 , NULL , 0 ,
V_208 ) ;
}
static int F_210 ( struct V_7 * V_11 )
{
if ( V_11 -> V_14 < V_52 )
return F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_74 , V_279 ,
V_436 , 0 , NULL , 0 ,
V_208 ) ;
else
return F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_74 , V_437 ,
V_438 ,
V_439 |
V_440 ,
NULL , 0 , V_208 ) ;
}
static int F_211 ( struct V_7 * V_11 )
{
if ( V_11 -> V_14 < V_52 )
return F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_71 , V_279 ,
V_436 , 0 , NULL , 0 ,
V_208 ) ;
else
return F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_74 , V_437 ,
V_438 , 0 , NULL , 0 ,
V_208 ) ;
}
static unsigned F_212 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_4 ( V_11 ) ;
return V_11 -> V_441 +
( V_2 ? V_2 -> F_212 : 0 ) ;
}
int F_165 ( struct V_7 * V_11 , T_4 V_442 )
{
struct V_1 * V_2 = F_4 ( V_11 -> V_25 ) ;
struct V_80 * V_81 = V_2 -> V_82 [ V_11 -> V_134 - 1 ] ;
int V_72 = V_11 -> V_134 ;
int V_83 ;
bool V_443 = true ;
F_202 ( V_81 ) ;
if ( V_11 -> V_441 ) {
V_83 = F_210 ( V_11 ) ;
if ( V_83 ) {
F_23 ( & V_11 -> V_22 , L_109 ,
V_83 ) ;
if ( F_213 ( V_442 ) )
goto V_444;
}
}
if ( V_11 -> V_445 == 1 )
F_214 ( V_11 , 0 ) ;
if ( F_207 ( V_11 ) ) {
F_31 ( & V_11 -> V_22 , L_110 ) ;
V_83 = - V_173 ;
if ( F_213 ( V_442 ) )
goto V_446;
}
if ( F_215 ( V_11 ) ) {
F_31 ( & V_11 -> V_22 , L_111 ) ;
V_83 = - V_173 ;
if ( F_213 ( V_442 ) )
goto V_447;
}
if ( F_3 ( V_2 -> V_4 ) )
V_83 = F_71 ( V_2 , V_72 , V_431 ) ;
else if ( F_213 ( V_442 ) || F_212 ( V_11 ) > 0 )
V_83 = F_20 ( V_2 -> V_4 , V_72 ,
V_448 ) ;
else {
V_443 = false ;
V_83 = 0 ;
}
if ( V_83 ) {
F_23 ( & V_81 -> V_22 , L_112 , V_83 ) ;
F_216 ( V_11 ) ;
V_447:
F_209 ( V_11 ) ;
V_446:
if ( V_11 -> V_449 == 1 )
F_214 ( V_11 , 1 ) ;
if ( V_11 -> V_441 )
( void ) F_211 ( V_11 ) ;
V_444:
if ( ! F_213 ( V_442 ) )
V_83 = 0 ;
} else {
F_23 ( & V_11 -> V_22 , L_113 ,
( F_213 ( V_442 ) ? L_114 : L_41 ) ,
V_11 -> V_441 ) ;
if ( V_443 ) {
V_11 -> F_204 = 1 ;
F_68 ( 10 ) ;
}
F_75 ( V_11 , V_331 ) ;
}
if ( V_83 == 0 && ! V_11 -> V_441 && V_11 -> V_228
&& F_153 ( V_72 , V_2 -> V_348 ) )
F_217 ( & V_81 -> V_22 ) ;
F_181 ( V_2 -> V_4 ) ;
F_203 ( V_81 ) ;
return V_83 ;
}
static int F_218 ( struct V_7 * V_11 )
{
int V_83 = 0 ;
T_1 V_450 = 0 ;
F_23 ( & V_11 -> V_22 , L_115 ,
V_11 -> V_229 ? L_116 : L_117 ) ;
F_75 ( V_11 , V_11 -> V_8
? V_91
: V_451 ) ;
if ( V_11 -> V_229 ) {
V_452:
if ( V_11 -> V_12 & V_453 )
V_83 = - V_120 ;
else
V_83 = F_219 ( V_11 ) ;
}
if ( V_83 == 0 ) {
V_450 = 0 ;
V_83 = F_102 ( V_11 , V_279 , 0 , & V_450 ) ;
if ( V_83 && ! V_11 -> V_229 && V_11 -> V_228 ) {
F_23 ( & V_11 -> V_22 , L_118 ) ;
V_11 -> V_229 = 1 ;
goto V_452;
}
}
if ( V_83 ) {
F_23 ( & V_11 -> V_22 , L_119 ,
V_83 ) ;
} else if ( V_11 -> V_8 && ! V_11 -> V_229 ) {
if ( V_11 -> V_14 < V_52 ) {
if ( V_450 & ( 1 << V_436 ) )
V_83 = F_211 ( V_11 ) ;
} else {
V_83 = F_102 ( V_11 , V_437 , 0 ,
& V_450 ) ;
if ( ! V_83 && V_450 & ( V_454
| V_455 ) )
V_83 = F_211 ( V_11 ) ;
}
if ( V_83 )
F_23 ( & V_11 -> V_22 ,
L_120 ,
V_83 ) ;
V_83 = 0 ;
}
return V_83 ;
}
static int F_220 ( struct V_7 * V_11 ,
struct V_1 * V_2 , int * V_72 ,
T_1 * V_185 , T_1 * V_3 )
{
int V_83 = 0 , V_456 = 0 ;
while ( V_456 < 2000 ) {
if ( V_83 || * V_3 & V_215 )
break;
F_68 ( 20 ) ;
V_456 += 20 ;
V_83 = F_33 ( V_2 , * V_72 , V_3 , V_185 ) ;
}
F_23 ( & V_11 -> V_22 , L_121 , V_456 ) ;
return V_83 ;
}
int F_221 ( struct V_7 * V_11 , T_4 V_442 )
{
struct V_1 * V_2 = F_4 ( V_11 -> V_25 ) ;
struct V_80 * V_81 = V_2 -> V_82 [ V_11 -> V_134 - 1 ] ;
int V_72 = V_11 -> V_134 ;
int V_83 ;
T_1 V_185 , V_3 ;
if ( ! F_148 ( V_72 , V_2 -> V_348 ) ) {
V_83 = F_149 ( & V_81 -> V_22 ) ;
if ( V_83 < 0 ) {
F_23 ( & V_11 -> V_22 , L_122 ,
V_83 ) ;
return V_83 ;
}
}
F_202 ( V_81 ) ;
V_83 = F_33 ( V_2 , V_72 , & V_3 , & V_185 ) ;
if ( V_83 == 0 && ! F_204 ( V_2 , V_3 ) )
goto V_457;
if ( F_3 ( V_2 -> V_4 ) )
V_83 = F_71 ( V_2 , V_72 , V_227 ) ;
else
V_83 = F_19 ( V_2 -> V_4 ,
V_72 , V_448 ) ;
if ( V_83 ) {
F_23 ( & V_81 -> V_22 , L_123 , V_83 ) ;
} else {
F_23 ( & V_11 -> V_22 , L_124 ,
( F_213 ( V_442 ) ? L_114 : L_41 ) ) ;
F_68 ( V_458 ) ;
V_83 = F_33 ( V_2 , V_72 , & V_3 , & V_185 ) ;
F_68 ( 10 ) ;
}
V_457:
if ( V_83 == 0 ) {
V_11 -> F_204 = 0 ;
if ( F_3 ( V_2 -> V_4 ) ) {
if ( V_185 & V_459 )
F_19 ( V_2 -> V_4 , V_72 ,
V_426 ) ;
} else {
if ( V_185 & V_460 )
F_19 ( V_2 -> V_4 , V_72 ,
V_461 ) ;
}
}
if ( V_11 -> V_228 )
V_83 = F_220 ( V_11 , V_2 , & V_72 , & V_185 ,
& V_3 ) ;
V_83 = F_205 ( V_11 ,
V_2 , V_72 , V_83 , V_185 , V_3 ) ;
if ( V_83 == 0 )
V_83 = F_218 ( V_11 ) ;
if ( V_83 < 0 ) {
F_23 ( & V_11 -> V_22 , L_123 , V_83 ) ;
F_76 ( V_2 , V_72 ) ;
} else {
if ( V_11 -> V_449 == 1 )
F_214 ( V_11 , 1 ) ;
F_209 ( V_11 ) ;
F_216 ( V_11 ) ;
}
F_203 ( V_81 ) ;
return V_83 ;
}
int F_222 ( struct V_7 * V_11 )
{
int V_83 = 0 ;
F_144 ( V_11 ) ;
if ( V_11 -> V_90 == V_331 ) {
F_23 ( & V_11 -> V_22 , L_124 , L_125 ) ;
V_83 = F_188 ( V_11 ) ;
if ( V_83 == 0 ) {
F_191 ( V_11 ) ;
}
}
F_151 ( V_11 ) ;
return V_83 ;
}
static int F_223 ( struct V_1 * V_2 , unsigned int V_119 ,
T_1 V_3 , T_1 V_185 )
__must_hold( &port_dev->status_lock
static int F_224 ( struct V_1 * V_2 )
{
int V_72 ;
for ( V_72 = 1 ; V_72 <= V_2 -> V_4 -> V_9 ; ++ V_72 ) {
T_1 V_3 , V_185 ;
int V_83 ;
V_83 = F_33 ( V_2 , V_72 , & V_3 , & V_185 ) ;
if ( ! V_83 && V_185 )
return 1 ;
}
return 0 ;
}
static int F_225 ( struct V_127 * V_128 , T_4 V_442 )
{
struct V_1 * V_2 = F_5 ( V_128 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
unsigned V_72 ;
int V_83 ;
V_2 -> F_212 = 0 ;
for ( V_72 = 1 ; V_72 <= V_4 -> V_9 ; V_72 ++ ) {
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
struct V_7 * V_11 = V_81 -> V_192 ;
if ( V_11 && V_11 -> V_462 ) {
F_73 ( & V_81 -> V_22 , L_126 ,
F_226 ( & V_11 -> V_22 ) ) ;
if ( F_213 ( V_442 ) )
return - V_329 ;
}
if ( V_11 )
V_2 -> F_212 +=
F_212 ( V_11 ) ;
}
if ( V_4 -> V_441 && V_2 -> V_315 ) {
if ( F_224 ( V_2 ) ) {
if ( F_213 ( V_442 ) )
return - V_329 ;
F_227 ( & V_4 -> V_22 , 2000 ) ;
}
}
if ( F_3 ( V_4 ) && V_4 -> V_441 ) {
for ( V_72 = 1 ; V_72 <= V_4 -> V_9 ; V_72 ++ ) {
V_83 = F_20 ( V_4 ,
V_72 |
V_463 |
V_464 |
V_465 ,
V_466 ) ;
}
}
F_23 ( & V_128 -> V_22 , L_115 , V_122 ) ;
F_86 ( V_2 , V_235 ) ;
return 0 ;
}
static int F_228 ( struct V_127 * V_128 )
{
struct V_1 * V_2 = F_5 ( V_128 ) ;
F_23 ( & V_128 -> V_22 , L_115 , V_122 ) ;
F_80 ( V_2 , V_205 ) ;
return 0 ;
}
static int F_229 ( struct V_127 * V_128 )
{
struct V_1 * V_2 = F_5 ( V_128 ) ;
F_23 ( & V_128 -> V_22 , L_115 , V_122 ) ;
F_80 ( V_2 , V_212 ) ;
return 0 ;
}
void F_230 ( struct V_7 * V_467 )
{
F_73 ( & V_467 -> V_22 , L_127 ) ;
V_467 -> V_229 = 1 ;
}
static int F_231 ( struct V_7 * V_11 , enum V_468 V_90 )
{
struct V_469 * V_470 ;
unsigned long long V_471 ;
unsigned long long V_472 ;
unsigned long long V_473 ;
unsigned long long V_474 ;
int V_57 ;
if ( V_11 -> V_90 != V_91 )
return 0 ;
V_471 = F_232 ( V_11 -> V_53 . V_46 , 1000 ) ;
V_472 = F_232 ( V_11 -> V_53 . V_43 , 1000 ) ;
V_473 = F_232 ( V_11 -> V_54 . V_46 , 1000 ) ;
V_474 = F_232 ( V_11 -> V_54 . V_43 , 1000 ) ;
if ( ( V_90 == V_475 &&
( V_471 > V_476 ||
V_472 > V_476 ) ) ||
( V_90 == V_477 &&
( V_473 > V_478 ||
V_474 > V_478 ) ) ) {
F_23 ( & V_11 -> V_22 , L_128 ,
V_479 [ V_90 ] , V_471 , V_472 ) ;
return - V_69 ;
}
if ( V_471 > V_476 )
V_471 = V_476 ;
if ( V_472 > V_476 )
V_472 = V_476 ;
if ( V_473 > V_478 )
V_473 = V_478 ;
if ( V_474 > V_478 )
V_474 = V_478 ;
V_470 = F_58 ( sizeof *( V_470 ) , V_214 ) ;
if ( ! V_470 )
return - V_173 ;
V_470 -> V_471 = V_471 ;
V_470 -> V_472 = V_472 ;
V_470 -> V_473 = F_233 ( V_473 ) ;
V_470 -> V_474 = F_233 ( V_474 ) ;
V_57 = F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_480 ,
V_279 ,
0 , 0 ,
V_470 , sizeof *( V_470 ) ,
V_208 ) ;
F_54 ( V_470 ) ;
return V_57 ;
}
static int F_234 ( struct V_7 * V_11 ,
enum V_468 V_90 , bool V_481 )
{
int V_57 ;
int V_70 ;
switch ( V_90 ) {
case V_475 :
V_70 = V_482 ;
break;
case V_477 :
V_70 = V_483 ;
break;
default:
F_73 ( & V_11 -> V_22 , L_129 ,
V_122 , V_481 ? L_130 : L_131 ) ;
return - V_69 ;
}
if ( V_11 -> V_90 != V_91 ) {
F_23 ( & V_11 -> V_22 , L_132
L_133 ,
V_122 , V_481 ? L_130 : L_131 ,
V_479 [ V_90 ] ) ;
return 0 ;
}
if ( V_481 ) {
V_57 = F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_74 ,
V_279 ,
V_70 ,
0 , NULL , 0 ,
V_208 ) ;
} else {
V_57 = F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_71 ,
V_279 ,
V_70 ,
0 , NULL , 0 ,
V_208 ) ;
}
if ( V_57 < 0 ) {
F_73 ( & V_11 -> V_22 , L_134 ,
V_481 ? L_135 : L_136 ,
V_479 [ V_90 ] ) ;
return - V_329 ;
}
return 0 ;
}
static int F_235 ( struct V_7 * V_11 ,
enum V_468 V_90 , int V_484 )
{
int V_57 ;
int V_70 ;
switch ( V_90 ) {
case V_475 :
V_70 = V_485 ;
break;
case V_477 :
V_70 = V_486 ;
break;
default:
F_73 ( & V_11 -> V_22 , L_137 ,
V_122 ) ;
return - V_69 ;
}
if ( V_90 == V_475 && V_484 > V_487 &&
V_484 != V_488 ) {
F_73 ( & V_11 -> V_22 , L_138
L_139 ,
V_479 [ V_90 ] , V_484 ) ;
return - V_69 ;
}
V_57 = F_20 ( V_11 -> V_25 ,
F_236 ( V_484 ) | V_11 -> V_134 ,
V_70 ) ;
if ( V_57 < 0 ) {
F_73 ( & V_11 -> V_22 , L_140
L_141 , V_479 [ V_90 ] ,
V_484 , V_57 ) ;
return - V_329 ;
}
if ( V_90 == V_475 )
V_11 -> V_53 . V_484 = V_484 ;
else
V_11 -> V_54 . V_484 = V_484 ;
return 0 ;
}
static void F_237 ( struct V_198 * V_164 , struct V_7 * V_11 ,
enum V_468 V_90 )
{
int V_484 , V_57 ;
T_5 V_489 = V_11 -> V_17 -> V_21 -> V_23 ;
T_6 V_490 = V_11 -> V_17 -> V_21 -> V_24 ;
if ( ( V_90 == V_475 && V_489 == 0 ) ||
( V_90 == V_477 && V_490 == 0 ) )
return;
V_57 = F_231 ( V_11 , V_90 ) ;
if ( V_57 < 0 ) {
F_73 ( & V_11 -> V_22 , L_142 ,
V_479 [ V_90 ] ) ;
return;
}
V_484 = V_164 -> V_165 -> V_491 ( V_164 , V_11 , V_90 ) ;
if ( V_484 == 0 )
return;
if ( V_484 < 0 ) {
F_73 ( & V_11 -> V_22 , L_143
L_144 , V_479 [ V_90 ] ,
V_484 ) ;
return;
}
if ( F_235 ( V_11 , V_90 , V_484 ) ) {
V_164 -> V_165 -> V_492 ( V_164 , V_11 , V_90 ) ;
} else {
if ( V_11 -> V_8 )
F_234 ( V_11 , V_90 , true ) ;
if ( V_90 == V_475 )
V_11 -> V_493 = 1 ;
else if ( V_90 == V_477 )
V_11 -> V_494 = 1 ;
}
}
static int F_238 ( struct V_198 * V_164 , struct V_7 * V_11 ,
enum V_468 V_90 )
{
switch ( V_90 ) {
case V_475 :
case V_477 :
break;
default:
F_73 ( & V_11 -> V_22 , L_145 ,
V_122 ) ;
return - V_69 ;
}
if ( F_235 ( V_11 , V_90 , 0 ) )
return - V_329 ;
F_234 ( V_11 , V_90 , false ) ;
if ( V_164 -> V_165 -> V_492 ( V_164 , V_11 , V_90 ) )
F_73 ( & V_11 -> V_22 , L_146
L_147 ,
V_479 [ V_90 ] ) ;
if ( V_90 == V_475 )
V_11 -> V_493 = 0 ;
else if ( V_90 == V_477 )
V_11 -> V_494 = 0 ;
return 0 ;
}
int F_239 ( struct V_7 * V_11 )
{
struct V_198 * V_164 ;
if ( ! V_11 || ! V_11 -> V_25 ||
V_11 -> V_14 < V_52 ||
! V_11 -> V_26 ||
V_11 -> V_90 < V_428 )
return 0 ;
V_164 = F_62 ( V_11 -> V_178 ) ;
if ( ! V_164 || ! V_164 -> V_165 -> V_492 )
return 0 ;
V_11 -> V_495 ++ ;
if ( ( V_11 -> V_53 . V_484 == 0 && V_11 -> V_54 . V_484 == 0 ) )
return 0 ;
if ( F_238 ( V_164 , V_11 , V_475 ) )
goto V_496;
if ( F_238 ( V_164 , V_11 , V_477 ) )
goto V_496;
return 0 ;
V_496:
F_240 ( V_11 ) ;
return - V_329 ;
}
int F_215 ( struct V_7 * V_11 )
{
struct V_198 * V_164 = F_62 ( V_11 -> V_178 ) ;
int V_57 ;
if ( ! V_164 )
return - V_69 ;
F_30 ( V_164 -> V_497 ) ;
V_57 = F_239 ( V_11 ) ;
F_32 ( V_164 -> V_497 ) ;
return V_57 ;
}
void F_240 ( struct V_7 * V_11 )
{
struct V_198 * V_164 ;
struct V_1 * V_2 ;
struct V_80 * V_81 ;
if ( ! V_11 || ! V_11 -> V_25 ||
V_11 -> V_14 < V_52 ||
! V_11 -> V_26 ||
V_11 -> V_90 < V_428 )
return;
V_11 -> V_495 -- ;
V_164 = F_62 ( V_11 -> V_178 ) ;
if ( ! V_164 || ! V_164 -> V_165 -> V_491 ||
! V_164 -> V_165 -> V_492 )
return;
if ( V_11 -> V_495 > 0 )
return;
V_2 = F_4 ( V_11 -> V_25 ) ;
if ( ! V_2 )
return;
V_81 = V_2 -> V_82 [ V_11 -> V_134 - 1 ] ;
if ( V_81 -> V_498 )
F_237 ( V_164 , V_11 , V_475 ) ;
if ( V_81 -> V_499 )
F_237 ( V_164 , V_11 , V_477 ) ;
}
void F_216 ( struct V_7 * V_11 )
{
struct V_198 * V_164 = F_62 ( V_11 -> V_178 ) ;
if ( ! V_164 )
return;
F_30 ( V_164 -> V_497 ) ;
F_240 ( V_11 ) ;
F_32 ( V_164 -> V_497 ) ;
}
int F_239 ( struct V_7 * V_11 )
{
return 0 ;
}
void F_240 ( struct V_7 * V_11 ) { }
int F_215 ( struct V_7 * V_11 )
{
return 0 ;
}
void F_216 ( struct V_7 * V_11 ) { }
int F_207 ( struct V_7 * V_11 )
{
return 0 ;
}
void F_209 ( struct V_7 * V_11 ) { }
static int F_223 ( struct V_1 * V_2 , unsigned int V_119 ,
T_1 V_3 , T_1 V_185 )
{
return 0 ;
}
int F_241 ( struct V_1 * V_2 , int V_72 , bool V_500 )
{
int V_57 ;
T_1 V_185 , V_3 ;
unsigned V_501 = 0xffff ;
int V_184 , V_502 = 0 ;
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
for ( V_184 = 0 ; ; V_184 += V_189 ) {
V_57 = F_33 ( V_2 , V_72 , & V_3 , & V_185 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( ! ( V_185 & V_217 ) &&
( V_3 & V_215 ) == V_501 ) {
if ( ! V_500 ||
( V_501 == V_215 ) )
V_502 += V_189 ;
if ( V_502 >= V_230 )
break;
} else {
V_502 = 0 ;
V_501 = V_3 & V_215 ;
}
if ( V_185 & V_217 ) {
F_19 ( V_2 -> V_4 , V_72 ,
V_218 ) ;
}
if ( V_184 >= V_190 )
break;
F_68 ( V_189 ) ;
}
F_23 ( & V_81 -> V_22 , L_148 ,
V_184 , V_502 , V_3 ) ;
if ( V_502 < V_230 )
return - V_107 ;
return V_3 ;
}
void F_242 ( struct V_7 * V_11 )
{
F_243 ( V_11 , 0 + V_65 , true ) ;
F_243 ( V_11 , 0 + V_503 , true ) ;
F_244 ( V_11 , & V_11 -> V_349 , true ) ;
}
static int F_245 ( struct V_7 * V_11 , int V_176 )
{
int V_504 ;
struct V_198 * V_164 = F_62 ( V_11 -> V_178 ) ;
if ( ! V_164 -> V_165 -> V_505 && V_176 <= 1 )
return - V_69 ;
if ( V_11 -> V_90 == V_451 )
return 0 ;
if ( V_11 -> V_90 != V_428 )
return - V_69 ;
if ( V_164 -> V_165 -> V_505 )
V_504 = V_164 -> V_165 -> V_505 ( V_164 , V_11 ) ;
else
V_504 = F_15 ( V_11 , F_246 () ,
V_506 , 0 , V_176 , 0 ,
NULL , 0 , V_208 ) ;
if ( V_504 == 0 ) {
F_141 ( V_11 , V_176 ) ;
F_75 ( V_11 , V_451 ) ;
F_242 ( V_11 ) ;
}
return V_504 ;
}
static void F_247 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_4 ( V_11 -> V_25 ) ;
int V_376 = V_507 ;
if ( ! V_11 -> V_449 )
return;
if ( V_2 )
V_376 = V_2 -> V_82 [ V_11 -> V_134 - 1 ] -> V_376 ;
if ( ( V_11 -> V_17 -> V_18 -> V_20 & F_248 ( V_508 ) ) ||
V_376 == V_379 ) {
V_11 -> V_509 = 1 ;
F_214 ( V_11 , 1 ) ;
}
}
static int F_249 ( struct V_7 * V_11 )
{
struct V_198 * V_164 = F_62 ( V_11 -> V_178 ) ;
if ( ! V_164 -> V_165 -> V_510 )
return 0 ;
if ( V_11 -> V_90 == V_451 )
return 0 ;
if ( V_11 -> V_90 != V_428 )
return - V_69 ;
return V_164 -> V_165 -> V_510 ( V_164 , V_11 ) ;
}
static int
F_250 ( struct V_1 * V_2 , struct V_7 * V_11 , int V_72 ,
int V_511 )
{
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_198 * V_164 = F_62 ( V_4 -> V_178 ) ;
int V_433 , V_512 , V_504 , V_56 ;
unsigned V_200 = V_414 ;
enum V_513 V_514 = V_11 -> V_14 ;
const char * V_14 ;
int V_176 = V_11 -> V_176 ;
if ( ! V_4 -> V_25 ) {
V_200 = V_515 ;
if ( V_72 == V_4 -> V_178 -> V_366 )
V_4 -> V_178 -> V_367 = 0 ;
}
if ( V_514 == V_420 )
V_200 = V_415 ;
F_30 ( V_164 -> V_516 ) ;
V_504 = F_198 ( V_2 , V_72 , V_11 , V_200 , false ) ;
if ( V_504 < 0 )
goto V_251;
V_504 = - V_120 ;
if ( V_514 != V_517 && V_514 != V_11 -> V_14 &&
! ( V_514 == V_52 && V_11 -> V_14 > V_514 ) ) {
F_23 ( & V_11 -> V_22 , L_149 ) ;
goto V_251;
}
V_514 = V_11 -> V_14 ;
switch ( V_11 -> V_14 ) {
case V_419 :
case V_52 :
case V_417 :
V_11 -> V_349 . V_288 . V_518 = F_233 ( 512 ) ;
break;
case V_15 :
V_11 -> V_349 . V_288 . V_518 = F_233 ( 64 ) ;
break;
case V_16 :
V_11 -> V_349 . V_288 . V_518 = F_233 ( 64 ) ;
break;
case V_420 :
V_11 -> V_349 . V_288 . V_518 = F_233 ( 8 ) ;
break;
default:
goto V_251;
}
if ( V_11 -> V_14 == V_417 )
V_14 = L_150 ;
else
V_14 = F_251 ( V_11 -> V_14 ) ;
if ( V_11 -> V_14 < V_52 )
F_8 ( & V_11 -> V_22 ,
L_151 ,
( V_11 -> V_360 ) ? L_152 : L_153 , V_14 ,
V_176 , V_11 -> V_178 -> V_519 -> V_165 -> V_520 ) ;
if ( V_4 -> V_150 ) {
V_11 -> V_150 = V_4 -> V_150 ;
V_11 -> V_175 = V_4 -> V_175 ;
} else if ( V_11 -> V_14 != V_15
&& V_4 -> V_14 == V_15 ) {
if ( ! V_2 -> V_150 . V_2 ) {
F_31 ( & V_11 -> V_22 , L_154 ) ;
V_504 = - V_69 ;
goto V_251;
}
V_11 -> V_150 = & V_2 -> V_150 ;
V_11 -> V_175 = V_72 ;
}
for ( V_433 = 0 ; V_433 < V_521 ; ( ++ V_433 , F_68 ( 100 ) ) ) {
bool V_522 = false ;
if ( F_194 ( V_11 , V_511 ) ) {
struct V_523 * V_524 ;
int V_525 = 0 ;
V_522 = true ;
V_504 = F_249 ( V_11 ) ;
if ( V_504 < 0 ) {
F_31 ( & V_11 -> V_22 ,
L_155 ,
V_504 ) ;
goto V_251;
}
#define F_252 64
V_524 = F_58 ( F_252 , V_214 ) ;
if ( ! V_524 ) {
V_504 = - V_173 ;
continue;
}
for ( V_512 = 0 ; V_512 < 3 ; ++ V_512 ) {
V_524 -> V_526 = 0 ;
V_525 = F_15 ( V_11 , F_253 () ,
V_64 , V_65 ,
V_527 << 8 , 0 ,
V_524 , F_252 ,
V_528 ) ;
switch ( V_524 -> V_526 ) {
case 8 : case 16 : case 32 : case 64 : case 255 :
if ( V_524 -> V_529 ==
V_527 ) {
V_525 = 0 ;
break;
}
default:
if ( V_525 == 0 )
V_525 = - V_530 ;
break;
}
if ( V_525 == 0 || ( V_525 == - V_107 && V_433 == 0 ) )
break;
}
V_11 -> V_36 . V_526 =
V_524 -> V_526 ;
F_54 ( V_524 ) ;
V_504 = F_198 ( V_2 , V_72 , V_11 , V_200 , false ) ;
if ( V_504 < 0 )
goto V_251;
if ( V_514 != V_11 -> V_14 ) {
F_23 ( & V_11 -> V_22 ,
L_149 ) ;
V_504 = - V_120 ;
goto V_251;
}
if ( V_525 ) {
if ( V_525 != - V_120 )
F_31 ( & V_11 -> V_22 , L_156 ,
V_525 ) ;
V_504 = - V_531 ;
continue;
}
#undef F_252
}
if ( V_11 -> V_341 == 0 ) {
for ( V_512 = 0 ; V_512 < V_532 ; ++ V_512 ) {
V_504 = F_245 ( V_11 , V_176 ) ;
if ( V_504 >= 0 )
break;
F_68 ( 200 ) ;
}
if ( V_504 < 0 ) {
if ( V_504 != - V_120 )
F_31 ( & V_11 -> V_22 , L_157 ,
V_176 , V_504 ) ;
goto V_251;
}
if ( V_11 -> V_14 >= V_52 ) {
V_176 = V_11 -> V_176 ;
F_8 ( & V_11 -> V_22 ,
L_158 ,
( V_11 -> V_360 ) ? L_152 : L_153 ,
( V_11 -> V_14 == V_419 ) ? L_159 : L_41 ,
V_176 , V_11 -> V_178 -> V_519 -> V_165 -> V_520 ) ;
}
F_68 ( 10 ) ;
if ( V_522 )
break;
}
V_504 = F_189 ( V_11 , 8 ) ;
if ( V_504 < 8 ) {
if ( V_504 != - V_120 )
F_31 ( & V_11 -> V_22 ,
L_160 ,
V_504 ) ;
if ( V_504 >= 0 )
V_504 = - V_531 ;
} else {
V_504 = 0 ;
break;
}
}
if ( V_504 )
goto V_251;
if ( ( V_11 -> V_14 >= V_52 ) &&
( F_13 ( V_11 -> V_36 . V_533 ) < 0x0300 ) ) {
F_31 ( & V_11 -> V_22 , L_161
L_162 ) ;
F_198 ( V_2 , V_72 , V_11 ,
V_534 , true ) ;
V_504 = - V_69 ;
goto V_251;
}
if ( V_11 -> V_36 . V_526 == 0xff ||
V_11 -> V_14 >= V_52 )
V_56 = 512 ;
else
V_56 = V_11 -> V_36 . V_526 ;
if ( F_254 ( & V_11 -> V_349 . V_288 ) != V_56 ) {
if ( V_11 -> V_14 == V_420 ||
! ( V_56 == 8 || V_56 == 16 || V_56 == 32 || V_56 == 64 ) ) {
F_31 ( & V_11 -> V_22 , L_163 , V_56 ) ;
V_504 = - V_531 ;
goto V_251;
}
if ( V_11 -> V_14 == V_16 )
F_23 ( & V_11 -> V_22 , L_164 , V_56 ) ;
else
F_73 ( & V_11 -> V_22 , L_165 , V_56 ) ;
V_11 -> V_349 . V_288 . V_518 = F_233 ( V_56 ) ;
F_242 ( V_11 ) ;
}
V_504 = F_189 ( V_11 , V_535 ) ;
if ( V_504 < ( signed ) sizeof( V_11 -> V_36 ) ) {
if ( V_504 != - V_120 )
F_31 ( & V_11 -> V_22 , L_166 ,
V_504 ) ;
if ( V_504 >= 0 )
V_504 = - V_536 ;
goto V_251;
}
F_255 ( V_11 ) ;
if ( V_11 -> V_341 == 0 && F_13 ( V_11 -> V_36 . V_533 ) >= 0x0201 ) {
V_504 = F_256 ( V_11 ) ;
if ( ! V_504 ) {
V_11 -> V_26 = F_6 ( V_11 ) ;
F_12 ( V_11 ) ;
}
}
V_504 = 0 ;
if ( V_164 -> V_165 -> V_537 )
V_164 -> V_165 -> V_537 ( V_164 , V_11 ) ;
F_247 ( V_11 ) ;
V_251:
if ( V_504 ) {
F_74 ( V_2 , V_72 , 0 ) ;
F_141 ( V_11 , V_176 ) ;
}
F_32 ( V_164 -> V_516 ) ;
return V_504 ;
}
static void
F_257 ( struct V_1 * V_2 , struct V_7 * V_11 , int V_72 )
{
struct V_538 * V_539 ;
int V_83 ;
if ( V_11 -> V_12 & V_540 )
return;
V_539 = F_58 ( sizeof *V_539 , V_250 ) ;
if ( V_539 == NULL )
return;
V_83 = F_258 ( V_11 , V_541 , 0 ,
V_539 , sizeof *V_539 ) ;
if ( V_83 == sizeof *V_539 ) {
F_8 ( & V_11 -> V_22 , L_167
L_168 ) ;
if ( V_2 -> V_232 ) {
V_2 -> V_94 [ V_72 - 1 ] = V_97 ;
F_26 ( V_104 ,
& V_2 -> V_87 , 0 ) ;
}
}
F_54 ( V_539 ) ;
}
static unsigned
F_259 ( struct V_1 * V_2 )
{
struct V_7 * V_4 = V_2 -> V_4 ;
int V_286 ;
int V_72 ;
if ( ! V_2 -> V_284 )
return 0 ;
V_286 = V_4 -> V_282 - V_2 -> V_36 -> V_287 ;
for ( V_72 = 1 ; V_72 <= V_4 -> V_9 ; ++ V_72 ) {
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
struct V_7 * V_11 = V_81 -> V_192 ;
unsigned V_248 ;
int V_542 ;
if ( ! V_11 )
continue;
if ( F_3 ( V_11 ) )
V_248 = 150 ;
else
V_248 = 100 ;
if ( V_11 -> V_8 )
V_542 = F_260 ( V_11 , V_11 -> V_8 ) ;
else if ( V_72 != V_11 -> V_178 -> V_366 || V_4 -> V_25 )
V_542 = V_248 ;
else
V_542 = 8 ;
if ( V_542 > V_2 -> V_283 )
F_73 ( & V_81 -> V_22 , L_169 ,
V_542 , V_2 -> V_283 ) ;
V_286 -= V_542 ;
}
if ( V_286 < 0 ) {
F_73 ( V_2 -> V_121 , L_170 ,
- V_286 ) ;
V_286 = 0 ;
}
return V_286 ;
}
static void F_261 ( struct V_1 * V_2 , int V_72 , T_1 V_3 ,
T_1 V_185 )
{
int V_83 , V_56 ;
unsigned V_248 ;
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_198 * V_164 = F_62 ( V_4 -> V_178 ) ;
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
struct V_7 * V_11 = V_81 -> V_192 ;
static int V_543 = - 1 ;
if ( V_11 ) {
if ( V_164 -> V_544 && ! V_4 -> V_25 )
F_262 ( V_164 -> V_544 , V_11 -> V_14 ) ;
F_87 ( & V_81 -> V_192 ) ;
}
if ( ! ( V_3 & V_215 ) ||
( V_185 & V_217 ) )
F_56 ( V_72 , V_2 -> V_196 ) ;
if ( V_185 & ( V_217 |
V_219 ) ) {
V_83 = F_263 ( V_2 , V_72 ) ;
if ( V_83 < 0 ) {
if ( V_83 != - V_120 &&
V_72 != V_543 &&
F_264 () )
F_31 ( & V_81 -> V_22 , L_171 ) ;
V_3 &= ~ V_215 ;
V_543 = V_72 ;
} else {
V_3 = V_83 ;
}
}
if ( ! ( V_3 & V_215 ) ||
F_67 ( V_72 , V_2 -> V_196 ) ) {
if ( F_66 ( V_2 )
&& ! F_201 ( V_2 , V_3 )
&& ! V_81 -> V_325 )
F_20 ( V_4 , V_72 , V_169 ) ;
if ( V_3 & V_216 )
goto V_425;
return;
}
if ( F_3 ( V_2 -> V_4 ) )
V_248 = 150 ;
else
V_248 = 100 ;
V_83 = 0 ;
for ( V_56 = 0 ; V_56 < V_545 ; V_56 ++ ) {
V_11 = F_265 ( V_4 , V_4 -> V_178 , V_72 ) ;
if ( ! V_11 ) {
F_31 ( & V_81 -> V_22 ,
L_172 ) ;
goto V_425;
}
F_75 ( V_11 , V_546 ) ;
V_11 -> V_282 = V_2 -> V_283 ;
V_11 -> V_207 = V_4 -> V_207 + 1 ;
V_11 -> V_341 = F_193 ( V_2 ) ;
if ( F_3 ( V_2 -> V_4 ) )
V_11 -> V_14 = V_52 ;
else
V_11 -> V_14 = V_517 ;
F_137 ( V_11 ) ;
if ( V_11 -> V_176 <= 0 ) {
V_83 = - V_416 ;
goto V_547;
}
F_202 ( V_81 ) ;
V_83 = F_250 ( V_2 , V_11 , V_72 , V_56 ) ;
F_203 ( V_81 ) ;
if ( V_83 < 0 )
goto V_547;
if ( V_11 -> V_12 & V_548 )
F_68 ( 1000 ) ;
if ( V_11 -> V_36 . V_549 == V_550
&& V_11 -> V_282 <= V_248 ) {
T_1 V_551 ;
V_83 = F_102 ( V_11 , V_279 , 0 ,
& V_551 ) ;
if ( V_83 ) {
F_23 ( & V_11 -> V_22 , L_173 , V_83 ) ;
goto V_552;
}
if ( ( V_551 & ( 1 << V_285 ) ) == 0 ) {
F_31 ( & V_11 -> V_22 ,
L_174
L_175 ) ;
if ( V_2 -> V_232 ) {
V_2 -> V_94 [ V_72 - 1 ] =
V_99 ;
F_26 (
V_104 ,
& V_2 -> V_87 , 0 ) ;
}
V_83 = - V_416 ;
goto V_552;
}
}
if ( F_13 ( V_11 -> V_36 . V_533 ) >= 0x0200
&& V_11 -> V_14 == V_16
&& V_297 != 0 )
F_257 ( V_2 , V_11 , V_72 ) ;
V_83 = 0 ;
F_30 ( & V_294 ) ;
F_115 ( & V_296 ) ;
if ( V_4 -> V_90 == V_193 )
V_83 = - V_416 ;
else
V_81 -> V_192 = V_11 ;
F_117 ( & V_296 ) ;
F_32 ( & V_294 ) ;
if ( ! V_83 ) {
V_83 = F_168 ( V_11 ) ;
if ( V_83 ) {
F_30 ( & V_294 ) ;
F_115 ( & V_296 ) ;
V_81 -> V_192 = NULL ;
F_117 ( & V_296 ) ;
F_32 ( & V_294 ) ;
} else {
if ( V_164 -> V_544 && ! V_4 -> V_25 )
F_266 ( V_164 -> V_544 ,
V_11 -> V_14 ) ;
}
}
if ( V_83 )
goto V_552;
V_83 = F_259 ( V_2 ) ;
if ( V_83 )
F_23 ( V_2 -> V_121 , L_176 , V_83 ) ;
return;
V_552:
F_74 ( V_2 , V_72 , 1 ) ;
V_547:
F_242 ( V_11 ) ;
F_140 ( V_11 ) ;
F_142 ( V_11 ) ;
F_111 ( V_11 ) ;
if ( ( V_83 == - V_416 ) || ( V_83 == - V_374 ) )
break;
}
if ( V_2 -> V_4 -> V_25 ||
! V_164 -> V_165 -> V_553 ||
! ( V_164 -> V_165 -> V_553 ) ( V_164 , V_72 ) ) {
if ( V_83 != - V_416 && V_83 != - V_120 )
F_31 ( & V_81 -> V_22 ,
L_177 ) ;
}
V_425:
F_74 ( V_2 , V_72 , 1 ) ;
if ( V_164 -> V_165 -> V_554 && ! V_2 -> V_4 -> V_25 )
V_164 -> V_165 -> V_554 ( V_164 , V_72 ) ;
}
static void F_267 ( struct V_1 * V_2 , int V_72 ,
T_1 V_3 , T_1 V_185 )
__must_hold( &port_dev->status_lock
static void F_268 ( struct V_1 * V_2 , int V_72 )
__must_hold( &port_dev->status_lock
static void V_311 ( struct V_85 * V_86 )
{
struct V_7 * V_4 ;
struct V_127 * V_128 ;
struct V_1 * V_2 ;
struct V_241 * V_242 ;
T_1 V_243 ;
T_1 V_244 ;
int V_56 , V_57 ;
V_2 = F_25 ( V_86 , struct V_1 , V_130 ) ;
V_4 = V_2 -> V_4 ;
V_242 = V_2 -> V_121 ;
V_128 = F_36 ( V_242 ) ;
F_23 ( V_242 , L_178 ,
V_4 -> V_90 , V_4 -> V_9 ,
( T_1 ) V_2 -> V_195 [ 0 ] ,
( T_1 ) V_2 -> V_146 [ 0 ] ) ;
F_144 ( V_4 ) ;
if ( F_269 ( V_2 -> V_129 ) )
goto V_555;
if ( V_4 -> V_90 == V_193 ) {
V_2 -> error = - V_120 ;
F_86 ( V_2 , V_295 ) ;
goto V_555;
}
V_57 = F_78 ( V_128 ) ;
if ( V_57 ) {
F_23 ( V_242 , L_179 , V_57 ) ;
goto V_555;
}
if ( V_2 -> V_92 )
goto V_556;
if ( V_2 -> error ) {
F_23 ( V_242 , L_180 , V_2 -> error ) ;
V_57 = F_270 ( V_4 ) ;
if ( V_57 ) {
F_23 ( V_242 , L_181 , V_57 ) ;
goto V_556;
}
V_2 -> V_142 = 0 ;
V_2 -> error = 0 ;
}
for ( V_56 = 1 ; V_56 <= V_4 -> V_9 ; V_56 ++ ) {
struct V_80 * V_81 = V_2 -> V_82 [ V_56 - 1 ] ;
if ( F_67 ( V_56 , V_2 -> V_146 )
|| F_67 ( V_56 , V_2 -> V_195 )
|| F_67 ( V_56 , V_2 -> V_135 ) ) {
F_171 ( & V_81 -> V_22 ) ;
F_92 ( & V_81 -> V_22 ) ;
F_202 ( V_81 ) ;
F_268 ( V_2 , V_56 ) ;
F_203 ( V_81 ) ;
F_217 ( & V_81 -> V_22 ) ;
}
}
if ( F_153 ( 0 , V_2 -> V_146 ) == 0 )
;
else if ( F_70 ( V_2 , & V_243 , & V_244 ) < 0 )
F_31 ( V_242 , L_182 ) ;
else {
if ( V_244 & V_557 ) {
F_23 ( V_242 , L_183 ) ;
F_17 ( V_4 , V_558 ) ;
if ( V_243 & V_290 )
V_2 -> V_284 = 1 ;
else
V_2 -> V_284 = 0 ;
}
if ( V_244 & V_559 ) {
T_1 V_83 = 0 ;
T_1 V_560 ;
F_23 ( V_242 , L_184 ) ;
F_17 ( V_4 , V_561 ) ;
F_68 ( 500 ) ;
F_65 ( V_2 , true ) ;
F_70 ( V_2 , & V_83 , & V_560 ) ;
if ( V_83 & V_291 )
F_31 ( V_242 , L_185 ) ;
}
}
V_556:
F_271 ( V_128 ) ;
V_555:
F_151 ( V_4 ) ;
F_79 ( V_128 ) ;
F_41 ( & V_2 -> V_131 , V_133 ) ;
}
int F_272 ( void )
{
if ( F_273 ( & V_562 ) < 0 ) {
F_274 ( V_563 L_186 ,
V_564 ) ;
return - 1 ;
}
V_132 = F_275 ( L_187 , V_565 , 0 ) ;
if ( V_132 )
return 0 ;
F_276 ( & V_562 ) ;
F_277 ( L_188 , V_564 ) ;
return - 1 ;
}
void F_278 ( void )
{
F_279 ( V_132 ) ;
F_276 ( & V_562 ) ;
}
static int F_280 ( struct V_7 * V_11 ,
struct V_523 * V_566 ,
struct V_567 * V_568 )
{
int V_88 = 0 ;
unsigned V_569 ;
unsigned V_570 = 0 ;
unsigned V_116 ;
unsigned V_571 ;
int V_113 ;
char * V_524 ;
if ( memcmp ( & V_11 -> V_36 , V_566 ,
sizeof( * V_566 ) ) != 0 )
return 1 ;
if ( ( V_568 && ! V_11 -> V_17 ) || ( ! V_568 && V_11 -> V_17 ) )
return 1 ;
if ( V_11 -> V_17 ) {
V_116 = F_13 ( V_11 -> V_17 -> V_288 -> V_363 ) ;
if ( V_116 != F_13 ( V_568 -> V_288 -> V_363 ) )
return 1 ;
if ( memcmp ( V_11 -> V_17 -> V_288 , V_568 -> V_288 , V_116 ) )
return 1 ;
}
if ( V_11 -> V_357 )
V_570 = strlen ( V_11 -> V_357 ) + 1 ;
V_116 = V_570 ;
for ( V_569 = 0 ; V_569 < V_11 -> V_36 . V_572 ; V_569 ++ ) {
V_571 = F_13 ( V_11 -> V_360 [ V_569 ] . V_288 . V_363 ) ;
V_116 = F_281 ( V_116 , V_571 ) ;
}
V_524 = F_58 ( V_116 , V_214 ) ;
if ( ! V_524 )
return 1 ;
for ( V_569 = 0 ; V_569 < V_11 -> V_36 . V_572 ; V_569 ++ ) {
V_571 = F_13 ( V_11 -> V_360 [ V_569 ] . V_288 . V_363 ) ;
V_113 = F_258 ( V_11 , V_573 , V_569 , V_524 ,
V_571 ) ;
if ( V_113 != V_571 ) {
F_23 ( & V_11 -> V_22 , L_189 ,
V_569 , V_113 ) ;
V_88 = 1 ;
break;
}
if ( memcmp ( V_524 , V_11 -> V_362 [ V_569 ] , V_571 )
!= 0 ) {
F_23 ( & V_11 -> V_22 , L_190 ,
V_569 ,
( (struct V_574 * ) V_524 ) ->
V_575 ) ;
V_88 = 1 ;
break;
}
}
if ( ! V_88 && V_570 ) {
V_113 = F_282 ( V_11 , V_11 -> V_36 . V_354 ,
V_524 , V_570 ) ;
if ( V_113 + 1 != V_570 ) {
F_23 ( & V_11 -> V_22 , L_191 ,
V_113 ) ;
V_88 = 1 ;
} else if ( memcmp ( V_524 , V_11 -> V_357 , V_113 ) != 0 ) {
F_23 ( & V_11 -> V_22 , L_192 ) ;
V_88 = 1 ;
}
}
F_54 ( V_524 ) ;
return V_88 ;
}
static int F_219 ( struct V_7 * V_11 )
{
struct V_7 * V_576 = V_11 -> V_25 ;
struct V_1 * V_577 ;
struct V_198 * V_164 = F_62 ( V_11 -> V_178 ) ;
struct V_523 V_36 = V_11 -> V_36 ;
struct V_567 * V_17 ;
int V_56 , V_578 , V_57 = 0 ;
int V_72 = V_11 -> V_134 ;
if ( V_11 -> V_90 == V_193 ||
V_11 -> V_90 == V_331 ) {
F_23 ( & V_11 -> V_22 , L_193 ,
V_11 -> V_90 ) ;
return - V_69 ;
}
if ( ! V_576 )
return - V_579 ;
V_577 = F_4 ( V_576 ) ;
if ( V_11 -> V_445 == 1 )
F_214 ( V_11 , 0 ) ;
V_57 = F_215 ( V_11 ) ;
if ( V_57 ) {
F_31 ( & V_11 -> V_22 , L_194 , V_122 ) ;
goto V_580;
}
V_57 = F_207 ( V_11 ) ;
if ( V_57 ) {
F_31 ( & V_11 -> V_22 , L_195 ,
V_122 ) ;
goto V_580;
}
V_17 = V_11 -> V_17 ;
V_11 -> V_17 = NULL ;
for ( V_56 = 0 ; V_56 < V_545 ; ++ V_56 ) {
F_242 ( V_11 ) ;
V_57 = F_250 ( V_577 , V_11 , V_72 , V_56 ) ;
if ( V_57 >= 0 || V_57 == - V_416 || V_57 == - V_120 )
break;
}
if ( V_57 < 0 )
goto V_581;
if ( F_280 ( V_11 , & V_36 , V_17 ) ) {
F_8 ( & V_11 -> V_22 , L_196 ) ;
V_11 -> V_36 = V_36 ;
goto V_581;
}
if ( ! V_11 -> V_8 )
goto V_425;
F_30 ( V_164 -> V_497 ) ;
V_57 = F_283 ( V_11 , V_11 -> V_8 , NULL , NULL ) ;
if ( V_57 < 0 ) {
F_73 ( & V_11 -> V_22 ,
L_197
L_198 ) ;
F_32 ( V_164 -> V_497 ) ;
goto V_581;
}
V_57 = F_15 ( V_11 , F_18 ( V_11 , 0 ) ,
V_582 , 0 ,
V_11 -> V_8 -> V_288 . V_575 , 0 ,
NULL , 0 , V_208 ) ;
if ( V_57 < 0 ) {
F_31 ( & V_11 -> V_22 ,
L_199 ,
V_11 -> V_8 -> V_288 . V_575 , V_57 ) ;
F_32 ( V_164 -> V_497 ) ;
goto V_581;
}
F_32 ( V_164 -> V_497 ) ;
F_75 ( V_11 , V_91 ) ;
for ( V_56 = 0 ; V_56 < V_11 -> V_8 -> V_288 . V_583 ; V_56 ++ ) {
struct V_584 * V_360 = V_11 -> V_8 ;
struct V_127 * V_128 = V_360 -> V_10 [ V_56 ] ;
struct V_585 * V_288 ;
V_288 = & V_128 -> V_301 -> V_288 ;
if ( V_288 -> V_586 == 0 ) {
F_284 ( V_11 , V_128 , true ) ;
F_285 ( V_11 , V_128 , true ) ;
V_57 = 0 ;
} else {
V_128 -> V_587 = 1 ;
V_57 = F_101 ( V_11 , V_288 -> V_588 ,
V_288 -> V_586 ) ;
V_128 -> V_587 = 0 ;
}
if ( V_57 < 0 ) {
F_31 ( & V_11 -> V_22 , L_200
L_201 ,
V_288 -> V_588 ,
V_288 -> V_586 ,
V_57 ) ;
goto V_581;
}
for ( V_578 = 0 ; V_578 < V_128 -> V_301 -> V_288 . V_310 ; V_578 ++ )
V_128 -> V_301 -> V_240 [ V_578 ] . V_589 = 0 ;
}
V_425:
F_214 ( V_11 , 1 ) ;
F_216 ( V_11 ) ;
F_209 ( V_11 ) ;
F_286 ( V_11 ) ;
V_11 -> V_17 = V_17 ;
return 0 ;
V_581:
F_286 ( V_11 ) ;
V_11 -> V_17 = V_17 ;
V_580:
F_76 ( V_577 , V_72 ) ;
return - V_120 ;
}
int F_270 ( struct V_7 * V_11 )
{
int V_57 ;
int V_56 ;
unsigned int V_590 ;
struct V_80 * V_81 ;
struct V_584 * V_360 = V_11 -> V_8 ;
struct V_1 * V_2 = F_4 ( V_11 -> V_25 ) ;
if ( V_11 -> V_90 == V_193 ||
V_11 -> V_90 == V_331 ) {
F_23 ( & V_11 -> V_22 , L_193 ,
V_11 -> V_90 ) ;
return - V_69 ;
}
if ( ! V_11 -> V_25 ) {
F_23 ( & V_11 -> V_22 , L_202 , V_122 ) ;
return - V_579 ;
}
V_81 = V_2 -> V_82 [ V_11 -> V_134 - 1 ] ;
V_590 = F_287 () ;
F_188 ( V_11 ) ;
if ( V_360 ) {
for ( V_56 = 0 ; V_56 < V_360 -> V_288 . V_583 ; ++ V_56 ) {
struct V_127 * V_591 = V_360 -> V_10 [ V_56 ] ;
struct V_592 * V_163 ;
int V_593 = 0 ;
if ( V_591 -> V_22 . V_165 ) {
V_163 = F_288 ( V_591 -> V_22 . V_165 ) ;
if ( V_163 -> V_594 && V_163 -> V_595 )
V_593 = ( V_163 -> V_594 ) ( V_591 ) ;
else if ( V_591 -> V_596 ==
V_597 )
V_593 = 1 ;
if ( V_593 )
F_289 ( V_591 ) ;
}
}
}
F_202 ( V_81 ) ;
V_57 = F_219 ( V_11 ) ;
F_203 ( V_81 ) ;
if ( V_360 ) {
for ( V_56 = V_360 -> V_288 . V_583 - 1 ; V_56 >= 0 ; -- V_56 ) {
struct V_127 * V_591 = V_360 -> V_10 [ V_56 ] ;
struct V_592 * V_163 ;
int V_598 = V_591 -> V_599 ;
if ( ! V_598 && V_591 -> V_22 . V_165 ) {
V_163 = F_288 ( V_591 -> V_22 . V_165 ) ;
if ( V_163 -> V_595 )
V_598 = ( V_163 -> V_595 ) ( V_591 ) ;
else if ( V_591 -> V_596 ==
V_597 )
V_598 = 1 ;
if ( V_598 )
V_591 -> V_599 = 1 ;
}
}
F_290 ( V_11 ) ;
}
F_191 ( V_11 ) ;
F_291 ( V_590 ) ;
return V_57 ;
}
void F_292 ( struct V_127 * V_600 )
{
if ( F_64 ( & V_600 -> V_601 ) )
F_127 ( V_600 ) ;
}
struct V_7 * F_293 ( struct V_7 * V_4 ,
int V_72 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
if ( V_72 < 1 || V_72 > V_4 -> V_9 )
return NULL ;
return V_2 -> V_82 [ V_72 - 1 ] -> V_192 ;
}
void F_110 ( struct V_7 * V_4 ,
struct V_63 * V_288 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
enum V_602 V_376 ;
int V_56 ;
if ( ! V_2 )
return;
if ( ! F_3 ( V_4 ) ) {
for ( V_56 = 1 ; V_56 <= V_4 -> V_9 ; V_56 ++ ) {
struct V_80 * V_81 = V_2 -> V_82 [ V_56 - 1 ] ;
V_376 = V_81 -> V_376 ;
if ( V_376 == V_379 ) {
T_3 V_603 = 1 << ( V_56 % 8 ) ;
if ( ! ( V_288 -> V_37 . V_256 . V_257 [ V_56 / 8 ] & V_603 ) ) {
F_23 ( & V_81 -> V_22 , L_203 ) ;
V_288 -> V_37 . V_256 . V_257 [ V_56 / 8 ] |= V_603 ;
}
}
}
} else {
T_1 V_604 = F_13 ( V_288 -> V_37 . V_38 . V_257 ) ;
for ( V_56 = 1 ; V_56 <= V_4 -> V_9 ; V_56 ++ ) {
struct V_80 * V_81 = V_2 -> V_82 [ V_56 - 1 ] ;
V_376 = V_81 -> V_376 ;
if ( V_376 == V_379 ) {
T_1 V_603 = 1 << V_56 ;
if ( ! ( V_604 & V_603 ) ) {
F_23 ( & V_81 -> V_22 , L_203 ) ;
V_604 |= V_603 ;
}
}
}
V_288 -> V_37 . V_38 . V_257 = F_233 ( V_604 ) ;
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
