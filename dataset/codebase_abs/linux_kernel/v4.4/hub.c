static inline char * F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( F_2 ( V_2 -> V_4 ) )
return L_1 ;
if ( V_3 & V_5 )
return L_2 ;
else if ( V_3 & V_6 )
return L_3 ;
else
return L_4 ;
}
struct V_1 * F_3 ( struct V_7 * V_4 )
{
if ( ! V_4 || ! V_4 -> V_8 || ! V_4 -> V_9 )
return NULL ;
return F_4 ( V_4 -> V_8 -> V_10 [ 0 ] ) ;
}
int F_5 ( struct V_7 * V_11 )
{
if ( V_11 -> V_12 & V_13 )
return 0 ;
if ( V_11 -> V_14 == V_15 || V_11 -> V_14 == V_16 ) {
if ( V_11 -> V_17 -> V_18 &&
( V_19 &
F_6 ( V_11 -> V_17 -> V_18 -> V_20 ) ) )
return 1 ;
return 0 ;
}
if ( ! V_11 -> V_17 -> V_21 ) {
F_7 ( & V_11 -> V_22 , L_5 ) ;
return 0 ;
}
if ( V_11 -> V_17 -> V_21 -> V_23 == 0 &&
V_11 -> V_17 -> V_21 -> V_24 == 0 ) {
if ( V_11 -> V_25 )
F_7 ( & V_11 -> V_22 , L_6 ) ;
else
F_7 ( & V_11 -> V_22 , L_7 ) ;
return 0 ;
}
if ( ! V_11 -> V_25 || V_11 -> V_25 -> V_26 )
return 1 ;
return 0 ;
}
static void F_8 ( struct V_7 * V_11 ,
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
static void F_9 ( struct V_7 * V_11 ,
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
static void F_10 ( struct V_7 * V_11 ,
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
static void F_11 ( struct V_7 * V_11 )
{
struct V_1 * V_2 ;
unsigned int V_47 ;
unsigned int V_48 ;
unsigned int V_49 ;
unsigned int V_50 ;
unsigned int V_51 ;
if ( ! V_11 -> V_26 || V_11 -> V_14 != V_52 )
return;
V_2 = F_3 ( V_11 -> V_25 ) ;
if ( ! V_2 )
return;
V_48 = V_11 -> V_17 -> V_21 -> V_23 ;
V_49 = F_12 ( V_11 -> V_17 -> V_21 -> V_24 ) ;
V_50 = V_11 -> V_25 -> V_17 -> V_21 -> V_23 ;
V_51 = F_12 ( V_11 -> V_25 -> V_17 -> V_21 -> V_24 ) ;
F_8 ( V_11 , & V_11 -> V_53 , V_48 ,
V_2 , & V_11 -> V_25 -> V_53 , V_50 ) ;
F_8 ( V_11 , & V_11 -> V_54 , V_49 ,
V_2 , & V_11 -> V_25 -> V_54 , V_51 ) ;
V_47 = 1 ;
F_9 ( V_11 , & V_11 -> V_53 , V_48 ,
V_2 , & V_11 -> V_25 -> V_53 , V_50 ,
V_47 ) ;
if ( V_51 > V_50 )
V_47 = 1 + V_51 - V_50 ;
else
V_47 = 1 + V_50 ;
F_9 ( V_11 , & V_11 -> V_54 , V_49 ,
V_2 , & V_11 -> V_25 -> V_54 , V_51 ,
V_47 ) ;
F_10 ( V_11 , & V_11 -> V_53 ) ;
F_10 ( V_11 , & V_11 -> V_54 ) ;
}
static int F_13 ( struct V_7 * V_4 , void * V_55 )
{
int V_56 , V_57 , V_58 ;
unsigned V_59 ;
if ( F_2 ( V_4 ) ) {
V_59 = V_60 ;
V_58 = V_61 ;
} else {
V_59 = V_62 ;
V_58 = sizeof( struct V_63 ) ;
}
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
V_57 = F_14 ( V_4 , F_15 ( V_4 , 0 ) ,
V_64 , V_65 | V_66 ,
V_59 << 8 , 0 , V_55 , V_58 ,
V_67 ) ;
if ( V_57 >= ( V_68 + 2 ) )
return V_57 ;
}
return - V_69 ;
}
static int F_16 ( struct V_7 * V_4 , int V_70 )
{
return F_14 ( V_4 , F_17 ( V_4 , 0 ) ,
V_71 , V_66 , V_70 , 0 , NULL , 0 , 1000 ) ;
}
int F_18 ( struct V_7 * V_4 , int V_72 , int V_70 )
{
return F_14 ( V_4 , F_17 ( V_4 , 0 ) ,
V_71 , V_73 , V_70 , V_72 ,
NULL , 0 , 1000 ) ;
}
static int F_19 ( struct V_7 * V_4 , int V_72 , int V_70 )
{
return F_14 ( V_4 , F_17 ( V_4 , 0 ) ,
V_74 , V_73 , V_70 , V_72 ,
NULL , 0 , 1000 ) ;
}
static char * F_20 ( int V_75 )
{
switch ( V_75 ) {
case V_76 :
return L_8 ;
case V_77 :
return L_9 ;
case V_78 :
return L_10 ;
case V_79 :
return L_11 ;
default:
return L_12 ;
}
}
static void F_21 ( struct V_1 * V_2 , int V_72 , int V_75 )
{
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
int V_83 ;
V_83 = F_19 ( V_2 -> V_4 , ( V_75 << 8 ) | V_72 ,
V_84 ) ;
F_22 ( & V_81 -> V_22 , L_13 ,
F_20 ( V_75 ) , V_83 ) ;
}
static void F_23 ( struct V_85 * V_86 )
{
struct V_1 * V_2 =
F_24 ( V_86 , struct V_1 , V_87 . V_86 ) ;
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
F_21 ( V_2 , V_56 + 1 , V_75 ) ;
V_2 -> V_94 [ V_56 ] = V_93 ;
}
if ( ! V_88 && V_103 ) {
V_89 ++ ;
V_89 %= V_4 -> V_9 ;
F_21 ( V_2 , V_89 + 1 , V_77 ) ;
V_2 -> V_94 [ V_89 ] = V_95 ;
V_88 ++ ;
}
if ( V_88 )
F_25 ( V_104 ,
& V_2 -> V_87 , V_105 ) ;
}
static int F_26 ( struct V_7 * V_4 ,
struct V_106 * V_55 )
{
int V_56 , V_83 = - V_107 ;
for ( V_56 = 0 ; V_56 < V_108 &&
( V_83 == - V_107 || V_83 == - V_109 ) ; V_56 ++ ) {
V_83 = F_14 ( V_4 , F_15 ( V_4 , 0 ) ,
V_110 , V_65 | V_66 , 0 , 0 ,
V_55 , sizeof( * V_55 ) , V_111 ) ;
}
return V_83 ;
}
static int F_27 ( struct V_7 * V_4 , int V_72 ,
struct V_112 * V_55 )
{
int V_56 , V_83 = - V_107 ;
for ( V_56 = 0 ; V_56 < V_108 &&
( V_83 == - V_107 || V_83 == - V_109 ) ; V_56 ++ ) {
V_83 = F_14 ( V_4 , F_15 ( V_4 , 0 ) ,
V_110 , V_65 | V_73 , 0 , V_72 ,
V_55 , sizeof( * V_55 ) , V_111 ) ;
}
return V_83 ;
}
static int F_28 ( struct V_1 * V_2 , int V_72 ,
T_1 * V_83 , T_1 * V_113 )
{
int V_57 ;
F_29 ( & V_2 -> V_114 ) ;
V_57 = F_27 ( V_2 -> V_4 , V_72 , & V_2 -> V_83 -> V_115 ) ;
if ( V_57 < 4 ) {
if ( V_57 != - V_116 )
F_30 ( V_2 -> V_117 ,
L_14 , V_118 , V_57 ) ;
if ( V_57 >= 0 )
V_57 = - V_119 ;
} else {
* V_83 = F_12 ( V_2 -> V_83 -> V_115 . V_120 ) ;
* V_113 = F_12 ( V_2 -> V_83 -> V_115 . V_121 ) ;
V_57 = 0 ;
}
F_31 ( & V_2 -> V_114 ) ;
return V_57 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_122 * V_123 ;
if ( V_2 -> V_124 || F_33 ( & V_2 -> V_125 ) )
return;
V_123 = F_34 ( V_2 -> V_117 ) ;
F_35 ( V_123 ) ;
F_36 ( & V_2 -> V_126 ) ;
if ( F_37 ( V_127 , & V_2 -> V_125 ) )
return;
F_38 ( V_123 ) ;
F_39 ( & V_2 -> V_126 , V_128 ) ;
}
void F_40 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = F_3 ( V_4 ) ;
if ( V_2 )
F_32 ( V_2 ) ;
}
void F_41 ( struct V_7 * V_4 ,
unsigned int V_129 )
{
struct V_1 * V_2 ;
if ( ! V_4 )
return;
V_2 = F_3 ( V_4 ) ;
if ( V_2 ) {
F_42 ( V_129 , V_2 -> V_130 ) ;
F_32 ( V_2 ) ;
}
}
static void F_43 ( struct V_131 * V_131 )
{
struct V_1 * V_2 = V_131 -> V_132 ;
int V_83 = V_131 -> V_83 ;
unsigned V_56 ;
unsigned long V_133 ;
switch ( V_83 ) {
case - V_134 :
case - V_135 :
case - V_136 :
return;
default:
F_22 ( V_2 -> V_117 , L_15 , V_83 ) ;
if ( ( ++ V_2 -> V_137 < 10 ) || V_2 -> error )
goto V_138;
V_2 -> error = V_83 ;
case 0 :
V_133 = 0 ;
for ( V_56 = 0 ; V_56 < V_131 -> V_139 ; ++ V_56 )
V_133 |= ( ( unsigned long ) ( ( * V_2 -> V_140 ) [ V_56 ] ) )
<< ( V_56 * 8 ) ;
V_2 -> V_141 [ 0 ] = V_133 ;
break;
}
V_2 -> V_137 = 0 ;
F_32 ( V_2 ) ;
V_138:
if ( V_2 -> V_92 )
return;
V_83 = F_44 ( V_2 -> V_131 , V_142 ) ;
if ( V_83 != 0 && V_83 != - V_116 && V_83 != - V_143 )
F_30 ( V_2 -> V_117 , L_16 , V_83 ) ;
}
static inline int
F_45 ( struct V_7 * V_4 , T_1 V_144 , T_1 V_145 )
{
if ( ( ( V_144 >> 11 ) & V_146 ) ==
V_147 ) {
int V_83 = F_14 ( V_4 , F_17 ( V_4 , 0 ) ,
V_148 , V_73 ,
V_144 ^ 0x8000 , V_145 , NULL , 0 , 1000 ) ;
if ( V_83 )
return V_83 ;
}
return F_14 ( V_4 , F_17 ( V_4 , 0 ) ,
V_148 , V_73 , V_144 ,
V_145 , NULL , 0 , 1000 ) ;
}
static void F_46 ( struct V_85 * V_86 )
{
struct V_1 * V_2 =
F_24 ( V_86 , struct V_1 , V_145 . V_149 ) ;
unsigned long V_150 ;
F_47 ( & V_2 -> V_145 . V_151 , V_150 ) ;
while ( ! F_48 ( & V_2 -> V_145 . V_152 ) ) {
struct V_153 * V_154 ;
struct V_155 * V_156 ;
struct V_7 * V_4 = V_2 -> V_4 ;
const struct V_157 * V_158 ;
int V_83 ;
V_154 = V_2 -> V_145 . V_152 . V_154 ;
V_156 = F_49 ( V_154 , struct V_155 , V_152 ) ;
F_50 ( & V_156 -> V_152 ) ;
F_51 ( & V_2 -> V_145 . V_151 , V_150 ) ;
V_83 = F_45 ( V_4 , V_156 -> V_144 , V_156 -> V_145 ) ;
if ( V_83 && V_83 != - V_116 )
F_30 ( & V_4 -> V_22 ,
L_17 ,
V_156 -> V_145 , V_156 -> V_144 , V_83 ) ;
V_158 = V_156 -> V_159 -> V_160 ;
if ( V_158 -> V_161 )
( V_158 -> V_161 ) ( V_156 -> V_159 , V_156 -> V_162 ) ;
F_52 ( V_156 ) ;
F_47 ( & V_2 -> V_145 . V_151 , V_150 ) ;
}
F_51 ( & V_2 -> V_145 . V_151 , V_150 ) ;
}
int F_53 ( struct V_7 * V_4 , struct V_1 * V_2 ,
int V_72 , bool V_163 )
{
int V_57 ;
if ( V_163 )
V_57 = F_19 ( V_4 , V_72 , V_164 ) ;
else
V_57 = F_18 ( V_4 , V_72 , V_164 ) ;
if ( V_57 )
return V_57 ;
if ( V_163 )
F_42 ( V_72 , V_2 -> V_165 ) ;
else
F_54 ( V_72 , V_2 -> V_165 ) ;
return 0 ;
}
int F_55 ( struct V_131 * V_131 )
{
struct V_7 * V_11 = V_131 -> V_22 ;
int V_166 = V_131 -> V_166 ;
struct V_167 * V_145 = V_11 -> V_145 ;
unsigned long V_150 ;
struct V_155 * V_156 ;
V_156 = F_56 ( sizeof *V_156 , V_142 ) ;
if ( V_156 == NULL ) {
F_30 ( & V_11 -> V_22 , L_18 ) ;
return - V_168 ;
}
V_156 -> V_145 = V_145 -> V_169 ? V_11 -> V_170 : 1 ;
V_156 -> V_144 = F_57 ( V_166 ) ;
V_156 -> V_144 |= V_11 -> V_171 << 4 ;
V_156 -> V_144 |= F_58 ( V_166 )
? ( V_147 << 11 )
: ( V_172 << 11 ) ;
if ( F_59 ( V_166 ) )
V_156 -> V_144 |= 1 << 15 ;
V_156 -> V_159 = F_60 ( V_11 -> V_173 ) ;
V_156 -> V_162 = V_131 -> V_162 ;
F_47 ( & V_145 -> V_151 , V_150 ) ;
F_61 ( & V_156 -> V_152 , & V_145 -> V_152 ) ;
F_62 ( & V_145 -> V_149 ) ;
F_51 ( & V_145 -> V_151 , V_150 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 , bool V_174 )
{
int V_72 ;
if ( F_64 ( V_2 ) )
F_22 ( V_2 -> V_117 , L_19 ) ;
else
F_22 ( V_2 -> V_117 , L_20
L_21 ) ;
for ( V_72 = 1 ; V_72 <= V_2 -> V_4 -> V_9 ; V_72 ++ )
if ( F_65 ( V_72 , V_2 -> V_165 ) )
F_19 ( V_2 -> V_4 , V_72 , V_164 ) ;
else
F_18 ( V_2 -> V_4 , V_72 ,
V_164 ) ;
if ( V_174 )
F_66 ( F_67 ( V_2 ) ) ;
}
static int F_68 ( struct V_1 * V_2 ,
T_1 * V_83 , T_1 * V_113 )
{
int V_57 ;
F_29 ( & V_2 -> V_114 ) ;
V_57 = F_26 ( V_2 -> V_4 , & V_2 -> V_83 -> V_2 ) ;
if ( V_57 < 0 ) {
if ( V_57 != - V_116 )
F_30 ( V_2 -> V_117 ,
L_14 , V_118 , V_57 ) ;
} else {
* V_83 = F_12 ( V_2 -> V_83 -> V_2 . V_175 ) ;
* V_113 = F_12 ( V_2 -> V_83 -> V_2 . V_176 ) ;
V_57 = 0 ;
}
F_31 ( & V_2 -> V_114 ) ;
return V_57 ;
}
static int F_69 ( struct V_1 * V_2 , int V_72 ,
unsigned int V_177 )
{
return F_19 ( V_2 -> V_4 ,
V_72 | ( V_177 << 3 ) ,
V_178 ) ;
}
static int F_70 ( struct V_1 * V_2 , int V_72 )
{
int V_57 ;
int V_179 ;
T_1 V_180 , V_3 ;
if ( ! F_2 ( V_2 -> V_4 ) )
return - V_69 ;
V_57 = F_28 ( V_2 , V_72 , & V_3 , & V_180 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( ( V_3 & V_181 ) ==
V_182 ) {
F_22 ( & V_2 -> V_82 [ V_72 - 1 ] -> V_22 ,
L_22 ) ;
return V_57 ;
}
V_57 = F_69 ( V_2 , V_72 , V_183 ) ;
if ( V_57 )
return V_57 ;
for ( V_179 = 0 ; ; V_179 += V_184 ) {
V_57 = F_28 ( V_2 , V_72 , & V_3 , & V_180 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( ( V_3 & V_181 ) ==
V_183 )
break;
if ( V_179 >= V_185 )
break;
F_66 ( V_184 ) ;
}
if ( V_179 >= V_185 )
F_71 ( & V_2 -> V_82 [ V_72 - 1 ] -> V_22 ,
L_23 , V_179 ) ;
return F_69 ( V_2 , V_72 , V_182 ) ;
}
static int F_72 ( struct V_1 * V_2 , int V_72 , int V_186 )
{
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
struct V_7 * V_4 = V_2 -> V_4 ;
int V_57 = 0 ;
if ( V_81 -> V_187 && V_186 )
F_73 ( V_81 -> V_187 , V_188 ) ;
if ( ! V_2 -> error ) {
if ( F_2 ( V_2 -> V_4 ) )
V_57 = F_70 ( V_2 , V_72 ) ;
else
V_57 = F_18 ( V_4 , V_72 ,
V_189 ) ;
}
if ( V_57 && V_57 != - V_116 )
F_30 ( & V_81 -> V_22 , L_24 , V_57 ) ;
return V_57 ;
}
static void F_74 ( struct V_1 * V_2 , int V_72 )
{
F_22 ( & V_2 -> V_82 [ V_72 - 1 ] -> V_22 , L_25 ) ;
F_72 ( V_2 , V_72 , 1 ) ;
F_42 ( V_72 , V_2 -> V_190 ) ;
F_32 ( V_2 ) ;
}
int F_75 ( struct V_7 * V_11 )
{
struct V_1 * V_2 ;
struct V_122 * V_123 ;
if ( ! V_11 -> V_25 )
return - V_69 ;
V_2 = F_3 ( V_11 -> V_25 ) ;
V_123 = F_34 ( V_2 -> V_117 ) ;
F_76 ( V_123 ) ;
F_42 ( V_11 -> V_129 , V_2 -> V_191 ) ;
F_74 ( V_2 , V_11 -> V_129 ) ;
F_77 ( V_123 ) ;
return 0 ;
}
static void F_78 ( struct V_1 * V_2 , enum V_192 type )
{
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_193 * V_159 ;
int V_57 ;
int V_72 ;
int V_83 ;
bool V_194 = false ;
unsigned V_195 ;
if ( type == V_196 || type == V_197 ) {
F_79 ( V_2 -> V_117 ) ;
if ( V_2 -> V_124 ) {
F_80 ( V_2 -> V_117 ) ;
F_39 ( & V_2 -> V_126 , V_128 ) ;
return;
}
if ( type == V_196 )
goto V_198;
goto V_199;
}
F_36 ( & V_2 -> V_126 ) ;
if ( type != V_200 ) {
if ( V_4 -> V_25 && F_2 ( V_4 ) ) {
V_57 = F_14 ( V_4 , F_17 ( V_4 , 0 ) ,
V_201 , V_66 ,
V_4 -> V_202 - 1 , 0 , NULL , 0 ,
V_203 ) ;
if ( V_57 < 0 )
F_30 ( V_2 -> V_117 ,
L_26 ) ;
}
if ( type == V_204 ) {
V_195 = F_67 ( V_2 ) ;
F_63 ( V_2 , false ) ;
F_81 ( & V_2 -> V_205 , V_206 ) ;
F_25 ( V_104 ,
& V_2 -> V_205 ,
F_82 ( V_195 ) ) ;
F_35 (
F_34 ( V_2 -> V_117 ) ) ;
return;
} else if ( type == V_207 ) {
V_159 = F_60 ( V_4 -> V_173 ) ;
if ( V_159 -> V_160 -> V_208 ) {
V_57 = V_159 -> V_160 -> V_208 ( V_159 , V_4 ,
& V_2 -> V_145 , V_209 ) ;
if ( V_57 < 0 ) {
F_30 ( V_2 -> V_117 , L_27
L_28
L_29 ) ;
F_30 ( V_2 -> V_117 , L_30
L_31
L_32 ) ;
}
}
F_63 ( V_2 , true ) ;
} else {
F_63 ( V_2 , true ) ;
}
}
V_198:
for ( V_72 = 1 ; V_72 <= V_4 -> V_9 ; ++ V_72 ) {
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
struct V_7 * V_11 = V_81 -> V_187 ;
T_1 V_3 , V_180 ;
V_3 = V_180 = 0 ;
V_83 = F_28 ( V_2 , V_72 , & V_3 , & V_180 ) ;
if ( V_11 || ( V_3 & V_210 ) )
F_22 ( & V_81 -> V_22 , L_33 ,
V_3 , V_180 ) ;
if ( ( V_3 & V_211 ) && (
type != V_200 ||
! ( V_3 & V_210 ) ||
! V_11 ||
V_11 -> V_90 == V_188 ) ) {
V_3 &= ~ V_211 ;
if ( ! F_2 ( V_4 ) )
F_18 ( V_4 , V_72 ,
V_189 ) ;
}
if ( V_180 & V_212 ) {
V_194 = true ;
F_18 ( V_2 -> V_4 , V_72 ,
V_213 ) ;
}
if ( V_180 & V_214 ) {
V_194 = true ;
F_18 ( V_2 -> V_4 , V_72 ,
V_215 ) ;
}
if ( V_180 & V_216 ) {
V_194 = true ;
F_18 ( V_2 -> V_4 , V_72 ,
V_217 ) ;
}
if ( ( V_180 & V_218 ) &&
F_2 ( V_2 -> V_4 ) ) {
V_194 = true ;
F_18 ( V_2 -> V_4 , V_72 ,
V_219 ) ;
}
if ( ! ( V_3 & V_210 ) ||
( V_180 & V_212 ) )
F_54 ( V_72 , V_2 -> V_191 ) ;
if ( ! V_11 || V_11 -> V_90 == V_188 ) {
if ( V_11 || ( V_3 & V_210 ) ||
( V_3 & V_220 ) )
F_42 ( V_72 , V_2 -> V_190 ) ;
} else if ( V_3 & V_211 ) {
bool V_221 = ( V_3 &
V_181 ) ==
V_222 ;
if ( V_180 || ( F_2 ( V_2 -> V_4 ) &&
V_221 ) )
F_42 ( V_72 , V_2 -> V_190 ) ;
} else if ( V_11 -> V_223 ) {
#ifdef F_83
V_11 -> V_224 = 1 ;
#endif
if ( F_65 ( V_72 , V_2 -> V_165 ) )
F_42 ( V_72 , V_2 -> V_190 ) ;
} else {
F_73 ( V_11 , V_188 ) ;
F_42 ( V_72 , V_2 -> V_190 ) ;
}
}
if ( V_194 ) {
V_195 = V_225 ;
if ( type == V_196 ) {
F_81 ( & V_2 -> V_205 , V_226 ) ;
F_25 ( V_104 ,
& V_2 -> V_205 ,
F_82 ( V_195 ) ) ;
F_80 ( V_2 -> V_117 ) ;
return;
} else {
F_66 ( V_195 ) ;
}
}
V_199:
V_2 -> V_92 = 0 ;
V_83 = F_44 ( V_2 -> V_131 , V_209 ) ;
if ( V_83 < 0 )
F_30 ( V_2 -> V_117 , L_34 , V_83 ) ;
if ( V_2 -> V_227 && V_103 )
F_25 ( V_104 ,
& V_2 -> V_87 , V_105 ) ;
F_32 ( V_2 ) ;
if ( type <= V_197 )
F_38 ( F_34 ( V_2 -> V_117 ) ) ;
if ( type == V_196 || type == V_197 )
F_80 ( V_2 -> V_117 ) ;
F_39 ( & V_2 -> V_126 , V_128 ) ;
}
static void V_206 ( struct V_85 * V_228 )
{
struct V_1 * V_2 = F_24 ( V_228 , struct V_1 , V_205 . V_86 ) ;
F_78 ( V_2 , V_196 ) ;
}
static void V_226 ( struct V_85 * V_228 )
{
struct V_1 * V_2 = F_24 ( V_228 , struct V_1 , V_205 . V_86 ) ;
F_78 ( V_2 , V_197 ) ;
}
static void F_84 ( struct V_1 * V_2 , enum V_229 type )
{
struct V_7 * V_4 = V_2 -> V_4 ;
int V_56 ;
F_85 ( & V_2 -> V_205 ) ;
V_2 -> V_92 = 1 ;
if ( type != V_230 ) {
for ( V_56 = 0 ; V_56 < V_4 -> V_9 ; ++ V_56 ) {
if ( V_2 -> V_82 [ V_56 ] -> V_187 )
F_86 ( & V_2 -> V_82 [ V_56 ] -> V_187 ) ;
}
}
F_87 ( V_2 -> V_131 ) ;
if ( V_2 -> V_227 )
F_85 ( & V_2 -> V_87 ) ;
if ( V_2 -> V_145 . V_2 )
F_88 ( & V_2 -> V_145 . V_149 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_2 -> V_4 -> V_9 ; ++ V_56 )
F_90 ( & V_2 -> V_82 [ V_56 ] -> V_22 ) ;
}
static int F_91 ( struct V_122 * V_123 )
{
struct V_1 * V_2 = F_4 ( V_123 ) ;
F_84 ( V_2 , V_231 ) ;
V_2 -> V_232 = 1 ;
F_89 ( V_2 ) ;
return 0 ;
}
static int F_92 ( struct V_122 * V_123 )
{
struct V_1 * V_2 = F_4 ( V_123 ) ;
V_2 -> V_232 = 0 ;
F_89 ( V_2 ) ;
F_78 ( V_2 , V_233 ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_234 * V_235 )
{
struct V_193 * V_159 ;
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_236 * V_237 = V_2 -> V_117 ;
T_1 V_238 , V_239 ;
T_1 V_240 ;
unsigned int V_166 ;
int V_241 , V_57 , V_56 ;
char * V_242 = L_35 ;
unsigned V_243 ;
unsigned V_244 ;
unsigned V_9 ;
V_2 -> V_140 = F_56 ( sizeof( * V_2 -> V_140 ) , V_245 ) ;
if ( ! V_2 -> V_140 ) {
V_57 = - V_168 ;
goto V_246;
}
V_2 -> V_83 = F_56 ( sizeof( * V_2 -> V_83 ) , V_245 ) ;
if ( ! V_2 -> V_83 ) {
V_57 = - V_168 ;
goto V_246;
}
F_94 ( & V_2 -> V_114 ) ;
V_2 -> V_36 = F_56 ( sizeof( * V_2 -> V_36 ) , V_245 ) ;
if ( ! V_2 -> V_36 ) {
V_57 = - V_168 ;
goto V_246;
}
V_57 = F_13 ( V_4 , V_2 -> V_36 ) ;
if ( V_57 < 0 ) {
V_242 = L_36 ;
goto V_246;
} else if ( V_2 -> V_36 -> V_247 > V_248 ) {
V_242 = L_37 ;
V_57 = - V_116 ;
goto V_246;
} else if ( V_2 -> V_36 -> V_247 == 0 ) {
V_242 = L_38 ;
V_57 = - V_116 ;
goto V_246;
}
V_9 = V_2 -> V_36 -> V_247 ;
F_7 ( V_237 , L_39 , V_9 ,
( V_9 == 1 ) ? L_40 : L_41 ) ;
V_2 -> V_82 = F_95 ( V_9 * sizeof( struct V_80 * ) , V_245 ) ;
if ( ! V_2 -> V_82 ) {
V_57 = - V_168 ;
goto V_246;
}
V_240 = F_12 ( V_2 -> V_36 -> V_240 ) ;
if ( F_2 ( V_4 ) ) {
V_243 = 150 ;
V_244 = 900 ;
} else {
V_243 = 100 ;
V_244 = 500 ;
}
if ( ( V_240 & V_249 ) &&
! ( F_2 ( V_4 ) ) ) {
char V_250 [ V_248 + 1 ] ;
for ( V_56 = 0 ; V_56 < V_9 ; V_56 ++ )
V_250 [ V_56 ] = V_2 -> V_36 -> V_37 . V_251 . V_252
[ ( ( V_56 + 1 ) / 8 ) ] & ( 1 << ( ( V_56 + 1 ) % 8 ) )
? 'F' : 'R' ;
V_250 [ V_9 ] = 0 ;
F_22 ( V_237 , L_42 , V_250 ) ;
} else
F_22 ( V_237 , L_43 ) ;
switch ( V_240 & V_253 ) {
case V_254 :
F_22 ( V_237 , L_44 ) ;
break;
case V_255 :
F_22 ( V_237 , L_45 ) ;
break;
case V_256 :
case V_253 :
F_22 ( V_237 , L_46 ) ;
break;
}
switch ( V_240 & V_257 ) {
case V_258 :
F_22 ( V_237 , L_47 ) ;
break;
case V_259 :
F_22 ( V_237 , L_48 ) ;
break;
case V_260 :
case V_257 :
F_22 ( V_237 , L_49 ) ;
break;
}
F_96 ( & V_2 -> V_145 . V_151 ) ;
F_97 ( & V_2 -> V_145 . V_152 ) ;
F_98 ( & V_2 -> V_145 . V_149 , F_46 ) ;
switch ( V_4 -> V_36 . V_261 ) {
case V_262 :
break;
case V_263 :
F_22 ( V_237 , L_50 ) ;
V_2 -> V_145 . V_2 = V_4 ;
break;
case V_264 :
V_57 = F_99 ( V_4 , 0 , 1 ) ;
if ( V_57 == 0 ) {
F_22 ( V_237 , L_51 ) ;
V_2 -> V_145 . V_169 = 1 ;
} else
F_30 ( V_237 , L_52 ,
V_57 ) ;
V_2 -> V_145 . V_2 = V_4 ;
break;
case V_265 :
break;
default:
F_22 ( V_237 , L_53 ,
V_4 -> V_36 . V_261 ) ;
break;
}
switch ( V_240 & V_266 ) {
case V_267 :
if ( V_4 -> V_36 . V_261 != 0 ) {
V_2 -> V_145 . V_268 = 666 ;
F_22 ( V_237 , L_54
L_55 ,
8 , V_2 -> V_145 . V_268 ) ;
}
break;
case V_269 :
V_2 -> V_145 . V_268 = 666 * 2 ;
F_22 ( V_237 , L_54
L_55 ,
16 , V_2 -> V_145 . V_268 ) ;
break;
case V_270 :
V_2 -> V_145 . V_268 = 666 * 3 ;
F_22 ( V_237 , L_54
L_55 ,
24 , V_2 -> V_145 . V_268 ) ;
break;
case V_271 :
V_2 -> V_145 . V_268 = 666 * 4 ;
F_22 ( V_237 , L_54
L_55 ,
32 , V_2 -> V_145 . V_268 ) ;
break;
}
if ( V_240 & V_272 ) {
V_2 -> V_227 = 1 ;
F_22 ( V_237 , L_56 ) ;
}
F_22 ( V_237 , L_57 ,
V_2 -> V_36 -> V_273 * 2 ) ;
V_57 = F_100 ( V_4 , V_274 , 0 , & V_238 ) ;
if ( V_57 ) {
V_242 = L_58 ;
goto V_246;
}
V_159 = F_60 ( V_4 -> V_173 ) ;
if ( V_4 == V_4 -> V_173 -> V_275 ) {
if ( V_159 -> V_276 > 0 )
V_4 -> V_277 = V_159 -> V_276 ;
else
V_4 -> V_277 = V_244 * V_9 ;
if ( V_4 -> V_277 >= V_244 )
V_2 -> V_278 = V_244 ;
else {
V_2 -> V_278 = V_4 -> V_277 ;
V_2 -> V_279 = 1 ;
}
} else if ( ( V_238 & ( 1 << V_280 ) ) == 0 ) {
int V_281 = V_4 -> V_277 -
V_2 -> V_36 -> V_282 ;
F_22 ( V_237 , L_59 ,
V_2 -> V_36 -> V_282 ) ;
V_2 -> V_279 = 1 ;
if ( V_281 < V_9 * V_243 )
F_71 ( V_237 ,
L_60
L_61 ) ;
V_2 -> V_278 = V_243 ;
} else {
V_2 -> V_278 = V_244 ;
}
if ( V_2 -> V_278 < V_244 )
F_22 ( V_237 , L_62 ,
V_2 -> V_278 ) ;
V_57 = F_68 ( V_2 , & V_238 , & V_239 ) ;
if ( V_57 < 0 ) {
V_242 = L_58 ;
goto V_246;
}
if ( V_4 -> V_8 -> V_283 . V_20 & V_284 )
F_22 ( V_237 , L_63 ,
( V_238 & V_285 )
? L_64 : L_65 ) ;
if ( ( V_240 & V_257 ) == 0 )
F_22 ( V_237 , L_66 ,
( V_238 & V_286 ) ? L_40 : L_67 ) ;
V_166 = F_101 ( V_4 , V_235 -> V_287 ) ;
V_241 = F_102 ( V_4 , V_166 , F_103 ( V_166 ) ) ;
if ( V_241 > sizeof( * V_2 -> V_140 ) )
V_241 = sizeof( * V_2 -> V_140 ) ;
V_2 -> V_131 = F_104 ( 0 , V_245 ) ;
if ( ! V_2 -> V_131 ) {
V_57 = - V_168 ;
goto V_246;
}
F_105 ( V_2 -> V_131 , V_4 , V_166 , * V_2 -> V_140 , V_241 , F_43 ,
V_2 , V_235 -> V_288 ) ;
if ( V_2 -> V_227 && V_103 )
V_2 -> V_94 [ 0 ] = V_95 ;
F_29 ( & V_289 ) ;
for ( V_56 = 0 ; V_56 < V_9 ; V_56 ++ ) {
V_57 = F_106 ( V_2 , V_56 + 1 ) ;
if ( V_57 < 0 ) {
F_30 ( V_2 -> V_117 ,
L_68 , V_56 + 1 ) ;
break;
}
}
V_4 -> V_9 = V_56 ;
for ( V_56 = 0 ; V_56 < V_4 -> V_9 ; V_56 ++ ) {
struct V_80 * V_81 = V_2 -> V_82 [ V_56 ] ;
F_107 ( & V_81 -> V_22 ) ;
}
F_31 ( & V_289 ) ;
if ( V_57 < 0 )
goto V_246;
if ( V_159 -> V_160 -> V_208 ) {
V_57 = V_159 -> V_160 -> V_208 ( V_159 , V_4 ,
& V_2 -> V_145 , V_245 ) ;
if ( V_57 < 0 ) {
V_242 = L_69 ;
goto V_246;
}
}
F_108 ( V_4 , V_2 -> V_36 ) ;
F_78 ( V_2 , V_204 ) ;
return 0 ;
V_246:
F_30 ( V_237 , L_70 ,
V_242 , V_57 ) ;
return V_57 ;
}
static void V_128 ( struct V_126 * V_126 )
{
struct V_1 * V_2 = F_24 ( V_126 , struct V_1 , V_126 ) ;
F_109 ( V_2 -> V_4 ) ;
F_110 ( F_34 ( V_2 -> V_117 ) ) ;
F_52 ( V_2 ) ;
}
static void F_111 ( struct V_122 * V_123 )
{
struct V_1 * V_2 = F_4 ( V_123 ) ;
struct V_7 * V_4 = F_112 ( V_123 ) ;
int V_72 ;
V_2 -> V_124 = 1 ;
V_2 -> error = 0 ;
F_84 ( V_2 , V_290 ) ;
F_29 ( & V_289 ) ;
F_113 ( & V_291 ) ;
V_72 = V_4 -> V_9 ;
V_4 -> V_9 = 0 ;
F_114 ( V_123 , NULL ) ;
F_115 ( & V_291 ) ;
for (; V_72 > 0 ; -- V_72 )
F_116 ( V_2 , V_72 ) ;
F_31 ( & V_289 ) ;
if ( V_2 -> V_4 -> V_14 == V_15 )
V_292 -- ;
F_117 ( V_2 -> V_131 ) ;
F_52 ( V_2 -> V_82 ) ;
F_52 ( V_2 -> V_36 ) ;
F_52 ( V_2 -> V_83 ) ;
F_52 ( V_2 -> V_140 ) ;
F_118 ( & V_123 -> V_22 , false ) ;
F_39 ( & V_2 -> V_126 , V_128 ) ;
}
static int F_119 ( struct V_122 * V_123 , const struct V_293 * V_294 )
{
struct V_295 * V_283 ;
struct V_234 * V_235 ;
struct V_7 * V_4 ;
struct V_1 * V_2 ;
V_283 = V_123 -> V_296 ;
V_4 = F_112 ( V_123 ) ;
#ifdef F_83
if ( V_4 -> V_22 . V_297 . V_298 >= 0 )
F_120 ( & V_4 -> V_22 , 0 ) ;
#endif
if ( V_4 -> V_25 ) {
F_121 ( V_4 ) ;
} else {
const struct V_157 * V_158 = F_60 ( V_4 -> V_173 ) -> V_160 ;
if ( V_158 -> V_299 && V_158 -> V_300 )
F_121 ( V_4 ) ;
}
if ( V_4 -> V_202 == V_301 ) {
F_30 ( & V_123 -> V_22 ,
L_71 ) ;
return - V_302 ;
}
#ifdef F_122
if ( V_4 -> V_25 ) {
F_71 ( & V_123 -> V_22 , L_72 ) ;
return - V_116 ;
}
#endif
if ( ( V_283 -> V_283 . V_303 != 0 ) &&
( V_283 -> V_283 . V_303 != 1 ) ) {
V_304:
F_30 ( & V_123 -> V_22 , L_73 ) ;
return - V_119 ;
}
if ( V_283 -> V_283 . V_305 != 1 )
goto V_304;
V_235 = & V_283 -> V_235 [ 0 ] . V_283 ;
if ( ! F_123 ( V_235 ) )
goto V_304;
F_7 ( & V_123 -> V_22 , L_74 ) ;
V_2 = F_95 ( sizeof( * V_2 ) , V_245 ) ;
if ( ! V_2 ) {
F_22 ( & V_123 -> V_22 , L_75 ) ;
return - V_168 ;
}
F_124 ( & V_2 -> V_126 ) ;
V_2 -> V_117 = & V_123 -> V_22 ;
V_2 -> V_4 = V_4 ;
F_81 ( & V_2 -> V_87 , F_23 ) ;
F_81 ( & V_2 -> V_205 , NULL ) ;
F_98 ( & V_2 -> V_125 , V_306 ) ;
F_125 ( V_123 ) ;
F_126 ( V_4 ) ;
F_114 ( V_123 , V_2 ) ;
V_123 -> V_307 = 1 ;
F_118 ( & V_123 -> V_22 , true ) ;
if ( V_4 -> V_14 == V_15 )
V_292 ++ ;
if ( V_294 -> V_308 & V_309 )
V_2 -> V_310 = 1 ;
if ( F_93 ( V_2 , V_235 ) >= 0 )
return 0 ;
F_111 ( V_123 ) ;
return - V_116 ;
}
static int
F_127 ( struct V_122 * V_123 , unsigned int V_311 , void * V_312 )
{
struct V_7 * V_4 = F_112 ( V_123 ) ;
struct V_1 * V_2 = F_3 ( V_4 ) ;
switch ( V_311 ) {
case V_313 : {
struct V_314 * V_315 = V_312 ;
int V_56 ;
F_113 ( & V_291 ) ;
if ( V_4 -> V_171 <= 0 )
V_315 -> V_316 = 0 ;
else {
V_315 -> V_316 = V_4 -> V_9 ;
for ( V_56 = 0 ; V_56 < V_315 -> V_316 ; V_56 ++ ) {
if ( V_2 -> V_82 [ V_56 ] -> V_187 == NULL )
V_315 -> V_115 [ V_56 ] = 0 ;
else
V_315 -> V_115 [ V_56 ] =
V_2 -> V_82 [ V_56 ] -> V_187 -> V_171 ;
}
}
F_115 ( & V_291 ) ;
return V_315 -> V_316 + 1 ;
}
default:
return - V_317 ;
}
}
static int F_128 ( struct V_7 * V_4 , unsigned V_72 ,
struct V_318 * * * V_319 )
{
struct V_1 * V_2 = F_3 ( V_4 ) ;
if ( V_4 -> V_90 == V_188 )
return - V_116 ;
if ( V_72 == 0 || V_72 > V_4 -> V_9 )
return - V_69 ;
* V_319 = & ( V_2 -> V_82 [ V_72 - 1 ] -> V_320 ) ;
return 0 ;
}
int F_129 ( struct V_7 * V_4 , unsigned V_72 ,
struct V_318 * V_321 )
{
int V_322 ;
struct V_318 * * V_323 ;
V_322 = F_128 ( V_4 , V_72 , & V_323 ) ;
if ( V_322 )
return V_322 ;
if ( * V_323 )
return - V_324 ;
* V_323 = V_321 ;
return V_322 ;
}
int F_130 ( struct V_7 * V_4 , unsigned V_72 ,
struct V_318 * V_321 )
{
int V_322 ;
struct V_318 * * V_323 ;
V_322 = F_128 ( V_4 , V_72 , & V_323 ) ;
if ( V_322 )
return V_322 ;
if ( * V_323 != V_321 )
return - V_134 ;
* V_323 = NULL ;
return V_322 ;
}
void F_131 ( struct V_7 * V_4 , struct V_318 * V_321 )
{
struct V_1 * V_2 = F_3 ( V_4 ) ;
int V_325 ;
for ( V_325 = 0 ; V_325 < V_4 -> V_9 ; V_325 ++ ) {
if ( V_2 -> V_82 [ V_325 ] -> V_320 == V_321 )
V_2 -> V_82 [ V_325 ] -> V_320 = NULL ;
}
}
bool F_132 ( struct V_7 * V_11 )
{
struct V_1 * V_2 ;
if ( V_11 -> V_90 == V_188 || ! V_11 -> V_25 )
return false ;
V_2 = F_3 ( V_11 -> V_25 ) ;
return ! ! V_2 -> V_82 [ V_11 -> V_129 - 1 ] -> V_320 ;
}
static void F_133 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_3 ( V_11 ) ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_11 -> V_9 ; ++ V_56 ) {
if ( V_2 -> V_82 [ V_56 ] -> V_187 )
F_133 ( V_2 -> V_82 [ V_56 ] -> V_187 ) ;
}
if ( V_11 -> V_90 == V_326 )
V_11 -> V_327 -= V_328 ;
V_11 -> V_90 = V_188 ;
}
void F_73 ( struct V_7 * V_11 ,
enum V_329 V_330 )
{
unsigned long V_150 ;
int V_331 = - 1 ;
F_47 ( & V_291 , V_150 ) ;
if ( V_11 -> V_90 == V_188 )
;
else if ( V_330 != V_188 ) {
if ( V_11 -> V_25 ) {
if ( V_11 -> V_90 == V_326
|| V_330 == V_326 )
;
else if ( V_330 == V_91 )
V_331 = ( V_11 -> V_12 &
V_332 ) ? 0 :
V_11 -> V_8 -> V_283 . V_20 &
V_333 ;
else
V_331 = 0 ;
}
if ( V_11 -> V_90 == V_326 &&
V_330 != V_326 )
V_11 -> V_327 -= V_328 ;
else if ( V_330 == V_326 &&
V_11 -> V_90 != V_326 )
V_11 -> V_327 += V_328 ;
V_11 -> V_90 = V_330 ;
} else
F_133 ( V_11 ) ;
F_51 ( & V_291 , V_150 ) ;
if ( V_331 >= 0 )
F_134 ( & V_11 -> V_22 , V_331 ) ;
}
static void F_135 ( struct V_7 * V_11 )
{
int V_171 ;
struct V_334 * V_173 = V_11 -> V_173 ;
F_29 ( & V_173 -> V_335 ) ;
if ( V_11 -> V_336 ) {
V_171 = V_11 -> V_129 + 1 ;
F_136 ( F_65 ( V_171 , V_173 -> V_337 . V_338 ) ) ;
} else {
V_171 = F_137 ( V_173 -> V_337 . V_338 , 128 ,
V_173 -> V_339 ) ;
if ( V_171 >= 128 )
V_171 = F_137 ( V_173 -> V_337 . V_338 ,
128 , 1 ) ;
V_173 -> V_339 = ( V_171 >= 127 ? 1 : V_171 + 1 ) ;
}
if ( V_171 < 128 ) {
F_42 ( V_171 , V_173 -> V_337 . V_338 ) ;
V_11 -> V_171 = V_171 ;
}
F_31 ( & V_173 -> V_335 ) ;
}
static void F_138 ( struct V_7 * V_11 )
{
if ( V_11 -> V_171 > 0 ) {
F_54 ( V_11 -> V_171 , V_11 -> V_173 -> V_337 . V_338 ) ;
V_11 -> V_171 = - 1 ;
}
}
static void F_139 ( struct V_7 * V_11 , int V_171 )
{
if ( ! V_11 -> V_336 )
V_11 -> V_171 = V_171 ;
}
static void F_140 ( struct V_7 * V_11 )
{
struct V_193 * V_159 = F_60 ( V_11 -> V_173 ) ;
if ( V_159 -> V_160 -> V_340 && V_11 -> V_25 )
V_159 -> V_160 -> V_340 ( V_159 , V_11 ) ;
}
static void F_141 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_3 ( V_11 ) ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_11 -> V_9 ; V_56 ++ ) {
if ( V_2 -> V_82 [ V_56 ] -> V_187 )
F_86 ( & V_2 -> V_82 [ V_56 ] -> V_187 ) ;
}
}
void F_86 ( struct V_7 * * V_341 )
{
struct V_80 * V_81 = NULL ;
struct V_7 * V_11 = * V_341 ;
struct V_1 * V_2 = NULL ;
int V_72 = 1 ;
F_73 ( V_11 , V_188 ) ;
F_7 ( & V_11 -> V_22 , L_76 ,
V_11 -> V_171 ) ;
F_142 ( V_11 ) ;
F_141 ( V_11 ) ;
F_22 ( & V_11 -> V_22 , L_77 ) ;
F_143 ( V_11 , 0 ) ;
F_144 ( V_11 ) ;
if ( V_11 -> V_25 ) {
V_72 = V_11 -> V_129 ;
V_2 = F_3 ( V_11 -> V_25 ) ;
V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
F_145 ( & V_11 -> V_22 . V_342 , L_78 ) ;
F_145 ( & V_81 -> V_22 . V_342 , L_79 ) ;
if ( ! F_146 ( V_72 , V_2 -> V_343 ) )
F_147 ( & V_81 -> V_22 ) ;
}
F_148 ( & V_11 -> V_344 ) ;
F_149 ( V_11 ) ;
F_150 ( & V_11 -> V_22 ) ;
F_138 ( V_11 ) ;
F_113 ( & V_291 ) ;
* V_341 = NULL ;
F_115 ( & V_291 ) ;
if ( V_81 && F_151 ( V_72 , V_2 -> V_343 ) )
F_107 ( & V_81 -> V_22 ) ;
F_140 ( V_11 ) ;
F_152 ( & V_11 -> V_22 ) ;
}
static void F_153 ( struct V_7 * V_11 , char * V_294 , char * string )
{
if ( ! string )
return;
F_7 ( & V_11 -> V_22 , L_80 , V_294 , string ) ;
}
static void F_154 ( struct V_7 * V_11 )
{
F_7 ( & V_11 -> V_22 , L_81 ,
F_12 ( V_11 -> V_36 . V_345 ) ,
F_12 ( V_11 -> V_36 . V_346 ) ) ;
F_7 ( & V_11 -> V_22 ,
L_82 ,
V_11 -> V_36 . V_347 ,
V_11 -> V_36 . V_348 ,
V_11 -> V_36 . V_349 ) ;
F_153 ( V_11 , L_83 , V_11 -> V_350 ) ;
F_153 ( V_11 , L_84 , V_11 -> V_351 ) ;
F_153 ( V_11 , L_85 , V_11 -> V_352 ) ;
}
static inline void F_154 ( struct V_7 * V_11 ) { }
static int F_155 ( struct V_7 * V_11 )
{
int V_353 = 0 ;
#ifdef F_156
if ( ! V_11 -> V_173 -> V_354
&& V_11 -> V_355
&& V_11 -> V_25 == V_11 -> V_173 -> V_275 ) {
struct V_356 * V_283 = NULL ;
struct V_334 * V_173 = V_11 -> V_173 ;
unsigned V_72 = V_11 -> V_129 ;
V_353 = F_157 ( V_11 -> V_357 [ 0 ] ,
F_12 ( V_11 -> V_355 [ 0 ] . V_283 . V_358 ) ,
V_359 , ( void * * ) & V_283 ) ;
if ( V_353 || ! ( V_283 -> V_20 & V_360 ) )
return 0 ;
F_7 ( & V_11 -> V_22 , L_86 ,
( V_72 == V_173 -> V_361 ) ? L_40 : L_87 ) ;
if ( V_72 == V_173 -> V_361 ) {
V_173 -> V_362 = 1 ;
V_353 = F_14 ( V_11 ,
F_17 ( V_11 , 0 ) ,
V_74 , 0 ,
V_363 ,
0 , NULL , 0 ,
V_203 ) ;
if ( V_353 < 0 ) {
F_30 ( & V_11 -> V_22 , L_88 ,
V_353 ) ;
V_173 -> V_362 = 0 ;
}
} else if ( V_283 -> V_364 == sizeof
( struct V_356 ) ) {
V_353 = F_14 ( V_11 ,
F_17 ( V_11 , 0 ) ,
V_74 , 0 ,
V_365 ,
0 , NULL , 0 ,
V_203 ) ;
if ( V_353 < 0 )
F_30 ( & V_11 -> V_22 ,
L_89 ,
V_353 ) ;
}
}
#endif
return V_353 ;
}
static int F_158 ( struct V_7 * V_11 )
{
int V_353 ;
struct V_193 * V_159 = F_60 ( V_11 -> V_173 ) ;
if ( V_11 -> V_355 == NULL ) {
V_353 = F_159 ( V_11 ) ;
if ( V_353 < 0 ) {
if ( V_353 != - V_116 )
F_30 ( & V_11 -> V_22 , L_90 ,
V_353 ) ;
return V_353 ;
}
}
V_11 -> V_350 = F_160 ( V_11 , V_11 -> V_36 . V_348 ) ;
V_11 -> V_351 = F_160 ( V_11 ,
V_11 -> V_36 . V_347 ) ;
V_11 -> V_352 = F_160 ( V_11 , V_11 -> V_36 . V_349 ) ;
V_353 = F_155 ( V_11 ) ;
if ( V_353 < 0 )
return V_353 ;
if ( F_161 ( V_366 ) && V_159 -> V_367 &&
! F_162 ( V_11 ) ) {
if ( F_161 ( F_156 ) && ( V_11 -> V_173 -> V_362
|| V_11 -> V_173 -> V_354 ) ) {
V_353 = F_163 ( V_11 , V_368 ) ;
if ( V_353 < 0 )
F_22 ( & V_11 -> V_22 , L_91 , V_353 ) ;
}
return - V_369 ;
}
F_164 ( V_11 ) ;
return 0 ;
}
static void F_165 ( struct V_7 * V_11 )
{
struct V_7 * V_4 = V_11 -> V_25 ;
struct V_1 * V_2 ;
T_2 V_115 = V_11 -> V_129 ;
T_1 V_240 ;
bool V_370 = true ;
if ( ! V_4 )
return;
V_2 = F_3 ( V_11 -> V_25 ) ;
switch ( V_2 -> V_82 [ V_11 -> V_129 - 1 ] -> V_371 ) {
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
V_240 = F_12 ( V_2 -> V_36 -> V_240 ) ;
if ( ! ( V_240 & V_249 ) )
return;
if ( F_2 ( V_4 ) ) {
if ( F_12 ( V_2 -> V_36 -> V_37 . V_38 . V_252 )
& ( 1 << V_115 ) )
V_370 = false ;
} else {
if ( V_2 -> V_36 -> V_37 . V_251 . V_252 [ V_115 / 8 ] & ( 1 << ( V_115 % 8 ) ) )
V_370 = false ;
}
if ( V_370 )
V_11 -> V_370 = V_373 ;
else
V_11 -> V_370 = V_376 ;
}
int F_166 ( struct V_7 * V_11 )
{
int V_353 ;
if ( V_11 -> V_25 ) {
F_167 ( & V_11 -> V_22 , 0 ) ;
}
F_168 ( & V_11 -> V_22 ) ;
F_169 ( & V_11 -> V_22 ) ;
F_170 ( & V_11 -> V_22 ) ;
F_171 ( & V_11 -> V_22 ) ;
F_172 ( V_11 ) ;
V_353 = F_158 ( V_11 ) ;
if ( V_353 < 0 )
goto V_246;
F_22 ( & V_11 -> V_22 , L_92 ,
V_11 -> V_171 , V_11 -> V_173 -> V_377 ,
( ( ( V_11 -> V_173 -> V_377 - 1 ) * 128 ) + ( V_11 -> V_171 - 1 ) ) ) ;
V_11 -> V_22 . V_378 = F_173 ( V_379 ,
( ( ( V_11 -> V_173 -> V_377 - 1 ) * 128 ) + ( V_11 -> V_171 - 1 ) ) ) ;
F_154 ( V_11 ) ;
if ( V_11 -> V_352 )
F_174 ( V_11 -> V_352 , strlen ( V_11 -> V_352 ) ) ;
if ( V_11 -> V_350 )
F_174 ( V_11 -> V_350 , strlen ( V_11 -> V_350 ) ) ;
if ( V_11 -> V_351 )
F_174 ( V_11 -> V_351 ,
strlen ( V_11 -> V_351 ) ) ;
F_175 ( & V_11 -> V_22 ) ;
if ( V_11 -> V_25 )
F_165 ( V_11 ) ;
V_353 = F_176 ( & V_11 -> V_22 ) ;
if ( V_353 ) {
F_30 ( & V_11 -> V_22 , L_93 , V_353 ) ;
goto V_246;
}
if ( V_11 -> V_25 ) {
struct V_1 * V_2 = F_3 ( V_11 -> V_25 ) ;
int V_72 = V_11 -> V_129 ;
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
V_353 = F_177 ( & V_11 -> V_22 . V_342 ,
& V_81 -> V_22 . V_342 , L_78 ) ;
if ( V_353 )
goto V_246;
V_353 = F_177 ( & V_81 -> V_22 . V_342 ,
& V_11 -> V_22 . V_342 , L_79 ) ;
if ( V_353 ) {
F_145 ( & V_11 -> V_22 . V_342 , L_78 ) ;
goto V_246;
}
if ( ! F_146 ( V_72 , V_2 -> V_343 ) )
F_147 ( & V_81 -> V_22 ) ;
}
( void ) F_178 ( & V_11 -> V_22 , & V_11 -> V_344 , V_11 ) ;
F_179 ( V_11 ) ;
F_180 ( & V_11 -> V_22 ) ;
return V_353 ;
V_246:
F_73 ( V_11 , V_188 ) ;
F_181 ( & V_11 -> V_22 ) ;
F_182 ( & V_11 -> V_22 ) ;
return V_353 ;
}
int F_183 ( struct V_7 * V_380 )
{
F_142 ( V_380 ) ;
if ( V_380 -> V_381 == 0 )
goto V_382;
V_380 -> V_381 = 0 ;
F_184 ( V_380 , - 1 ) ;
V_382:
F_149 ( V_380 ) ;
return 0 ;
}
int F_185 ( struct V_7 * V_380 )
{
int V_383 = 0 , V_384 ;
F_142 ( V_380 ) ;
if ( V_380 -> V_381 == 1 )
goto V_385;
V_383 = F_186 ( V_380 ) ;
if ( V_383 < 0 ) {
F_30 ( & V_380 -> V_22 ,
L_94 , V_383 ) ;
goto V_386;
}
if ( V_380 -> V_336 ) {
V_383 = F_187 ( V_380 , sizeof( V_380 -> V_36 ) ) ;
if ( V_383 < 0 ) {
F_30 ( & V_380 -> V_22 , L_95
L_96 , V_383 ) ;
goto V_387;
}
}
V_380 -> V_381 = 1 ;
V_384 = F_188 ( V_380 ) ;
if ( V_384 >= 0 ) {
V_383 = F_184 ( V_380 , V_384 ) ;
if ( V_383 ) {
F_30 ( & V_380 -> V_22 ,
L_97 , V_384 , V_383 ) ;
}
}
F_7 ( & V_380 -> V_22 , L_98 ) ;
V_387:
F_189 ( V_380 ) ;
V_386:
V_385:
F_149 ( V_380 ) ;
return V_383 ;
}
static unsigned F_190 ( struct V_1 * V_2 )
{
struct V_193 * V_159 ;
if ( V_2 -> V_4 -> V_25 != NULL )
return 0 ;
V_159 = F_24 ( V_2 -> V_4 -> V_173 , struct V_193 , V_388 ) ;
return V_159 -> V_389 ;
}
static bool F_191 ( struct V_7 * V_11 , int V_390 )
{
if ( V_11 -> V_14 == V_52 )
return false ;
return F_192 ( V_390 ) ;
}
static bool F_193 ( struct V_1 * V_2 , int V_72 ,
T_1 V_3 )
{
T_1 V_391 ;
if ( ! F_2 ( V_2 -> V_4 ) )
return false ;
if ( F_65 ( V_72 , V_2 -> V_392 ) )
return true ;
V_391 = V_3 & V_181 ;
return V_391 == V_393
|| V_391 == V_394 ;
}
static int F_194 ( struct V_1 * V_2 , int V_72 ,
struct V_7 * V_11 , unsigned int V_195 , bool V_395 )
{
int V_396 , V_57 ;
T_1 V_3 ;
T_1 V_180 ;
for ( V_396 = 0 ;
V_396 < V_397 ;
V_396 += V_195 ) {
F_66 ( V_195 ) ;
V_57 = F_28 ( V_2 , V_72 , & V_3 , & V_180 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( ! ( V_3 & V_398 ) )
break;
if ( V_396 >= 2 * V_399 )
V_195 = V_400 ;
F_22 ( & V_2 -> V_82 [ V_72 - 1 ] -> V_22 ,
L_99 ,
V_395 ? L_100 : L_40 , V_195 ) ;
}
if ( ( V_3 & V_398 ) )
return - V_324 ;
if ( F_193 ( V_2 , V_72 , V_3 ) )
return - V_401 ;
if ( ! ( V_3 & V_210 ) )
return - V_401 ;
if ( ! F_2 ( V_2 -> V_4 ) &&
( V_180 & V_212 ) )
return - V_401 ;
if ( ! ( V_3 & V_211 ) )
return - V_324 ;
if ( ! V_11 )
return 0 ;
if ( F_190 ( V_2 ) )
V_11 -> V_14 = V_402 ;
else if ( F_2 ( V_2 -> V_4 ) )
V_11 -> V_14 = V_52 ;
else if ( V_3 & V_5 )
V_11 -> V_14 = V_15 ;
else if ( V_3 & V_6 )
V_11 -> V_14 = V_403 ;
else
V_11 -> V_14 = V_16 ;
return 0 ;
}
static int F_195 ( struct V_1 * V_2 , int V_72 ,
struct V_7 * V_11 , unsigned int V_195 , bool V_395 )
{
int V_56 , V_83 ;
T_1 V_180 , V_3 ;
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
if ( ! F_2 ( V_2 -> V_4 ) ) {
if ( V_395 ) {
F_30 ( V_2 -> V_117 , L_101
L_102 ) ;
return - V_69 ;
}
F_196 ( & V_404 ) ;
} else if ( ! V_395 ) {
if ( F_28 ( V_2 , V_72 , & V_3 , & V_180 ) == 0 )
if ( F_193 ( V_2 , V_72 ,
V_3 ) )
V_395 = true ;
}
F_54 ( V_72 , V_2 -> V_392 ) ;
for ( V_56 = 0 ; V_56 < V_405 ; V_56 ++ ) {
V_83 = F_19 ( V_2 -> V_4 , V_72 , ( V_395 ?
V_406 :
V_407 ) ) ;
if ( V_83 == - V_116 ) {
;
} else if ( V_83 ) {
F_30 ( & V_81 -> V_22 ,
L_103 ,
V_395 ? L_100 : L_40 , V_83 ) ;
} else {
V_83 = F_194 ( V_2 , V_72 , V_11 , V_195 ,
V_395 ) ;
if ( V_83 && V_83 != - V_401 && V_83 != - V_116 )
F_22 ( V_2 -> V_117 ,
L_104 ,
V_83 ) ;
}
if ( V_83 == 0 || V_83 == - V_401 || V_83 == - V_116 ) {
F_18 ( V_2 -> V_4 , V_72 ,
V_217 ) ;
if ( ! F_2 ( V_2 -> V_4 ) )
goto V_408;
F_18 ( V_2 -> V_4 , V_72 ,
V_219 ) ;
F_18 ( V_2 -> V_4 , V_72 ,
V_409 ) ;
F_18 ( V_2 -> V_4 , V_72 ,
V_213 ) ;
if ( F_28 ( V_2 , V_72 ,
& V_3 , & V_180 ) < 0 )
goto V_408;
if ( ! F_193 ( V_2 , V_72 ,
V_3 ) )
goto V_408;
if ( ! V_395 ) {
F_22 ( & V_81 -> V_22 ,
L_105 ) ;
V_395 = true ;
}
}
F_22 ( & V_81 -> V_22 ,
L_106 ,
V_395 ? L_100 : L_40 ) ;
V_195 = V_400 ;
}
F_30 ( & V_81 -> V_22 , L_107 ) ;
V_408:
if ( V_83 == 0 ) {
F_66 ( 10 + 40 ) ;
if ( V_11 ) {
struct V_193 * V_159 = F_60 ( V_11 -> V_173 ) ;
F_139 ( V_11 , 0 ) ;
if ( V_159 -> V_160 -> V_410 )
V_159 -> V_160 -> V_410 ( V_159 , V_11 ) ;
F_73 ( V_11 , V_411 ) ;
}
} else {
if ( V_11 )
F_73 ( V_11 , V_188 ) ;
}
if ( ! F_2 ( V_2 -> V_4 ) )
F_197 ( & V_404 ) ;
return V_83 ;
}
static int F_198 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_57 = 0 ;
if ( F_2 ( V_2 -> V_4 ) ) {
if ( V_3 & V_412 )
V_57 = 1 ;
} else {
if ( V_3 & V_413 )
V_57 = 1 ;
}
return V_57 ;
}
static void F_199 ( struct V_80 * V_81 )
__acquires( &port_dev->status_lock
static void F_200 ( struct V_80 * V_81 )
__releases( &port_dev->status_lock
static int F_201 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_57 = 0 ;
if ( F_2 ( V_2 -> V_4 ) ) {
if ( ( V_3 & V_181 )
== V_414 )
V_57 = 1 ;
} else {
if ( V_3 & V_415 )
V_57 = 1 ;
}
return V_57 ;
}
static int F_202 ( struct V_7 * V_11 ,
struct V_1 * V_2 , int V_72 ,
int V_83 , T_1 V_180 , T_1 V_3 )
{
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
int V_416 = 3 ;
V_390:
if ( V_83 == 0 && V_11 -> V_224
&& F_193 ( V_2 , V_72 , V_3 ) ) {
;
}
else if ( V_83 || F_201 ( V_2 , V_3 ) ||
! F_198 ( V_2 , V_3 ) ) {
if ( V_83 >= 0 )
V_83 = - V_116 ;
} else if ( ! ( V_3 & V_210 ) ) {
if ( V_416 -- ) {
F_203 ( 200 , 300 ) ;
V_83 = F_28 ( V_2 , V_72 , & V_3 ,
& V_180 ) ;
goto V_390;
}
V_83 = - V_116 ;
}
else if ( ! ( V_3 & V_211 ) && ! V_11 -> V_224 ) {
if ( V_11 -> V_223 )
V_11 -> V_224 = 1 ;
else
V_83 = - V_116 ;
}
if ( V_83 ) {
F_22 ( & V_81 -> V_22 , L_108 ,
V_180 , V_3 , V_83 ) ;
} else if ( V_11 -> V_224 ) {
if ( V_180 & V_212 )
F_18 ( V_2 -> V_4 , V_72 ,
V_213 ) ;
if ( V_180 & V_214 )
F_18 ( V_2 -> V_4 , V_72 ,
V_215 ) ;
}
return V_83 ;
}
int F_204 ( struct V_7 * V_11 )
{
struct V_193 * V_159 = F_60 ( V_11 -> V_173 ) ;
if ( ! F_205 ( V_159 -> V_388 . V_275 ) ||
! F_205 ( V_11 ) )
return 0 ;
if ( ! V_11 -> V_8 )
return 0 ;
return F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_71 , V_274 ,
V_417 , 0 , NULL , 0 ,
V_203 ) ;
}
void F_206 ( struct V_7 * V_11 )
{
struct V_193 * V_159 = F_60 ( V_11 -> V_173 ) ;
if ( ! F_205 ( V_159 -> V_388 . V_275 ) ||
! F_205 ( V_11 ) )
return;
if ( ! V_11 -> V_8 )
return;
F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_74 , V_274 ,
V_417 , 0 , NULL , 0 ,
V_203 ) ;
}
static int F_207 ( struct V_7 * V_11 )
{
if ( V_11 -> V_14 < V_52 )
return F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_74 , V_274 ,
V_418 , 0 , NULL , 0 ,
V_203 ) ;
else
return F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_74 , V_419 ,
V_420 ,
V_421 |
V_422 ,
NULL , 0 , V_203 ) ;
}
static int F_208 ( struct V_7 * V_11 )
{
if ( V_11 -> V_14 < V_52 )
return F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_71 , V_274 ,
V_418 , 0 , NULL , 0 ,
V_203 ) ;
else
return F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_71 , V_419 ,
V_420 , 0 , NULL , 0 ,
V_203 ) ;
}
static unsigned F_209 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_3 ( V_11 ) ;
return V_11 -> V_423 +
( V_2 ? V_2 -> F_209 : 0 ) ;
}
int F_163 ( struct V_7 * V_11 , T_3 V_424 )
{
struct V_1 * V_2 = F_3 ( V_11 -> V_25 ) ;
struct V_80 * V_81 = V_2 -> V_82 [ V_11 -> V_129 - 1 ] ;
int V_72 = V_11 -> V_129 ;
int V_83 ;
bool V_425 = true ;
F_199 ( V_81 ) ;
if ( V_11 -> V_423 ) {
V_83 = F_207 ( V_11 ) ;
if ( V_83 ) {
F_22 ( & V_11 -> V_22 , L_109 ,
V_83 ) ;
if ( F_210 ( V_424 ) )
goto V_426;
}
}
if ( V_11 -> V_427 == 1 )
F_211 ( V_11 , 0 ) ;
if ( F_204 ( V_11 ) ) {
F_30 ( & V_11 -> V_22 , L_110 ) ;
V_83 = - V_168 ;
if ( F_210 ( V_424 ) )
goto V_428;
}
if ( F_212 ( V_11 ) ) {
F_30 ( & V_11 -> V_22 , L_111 ) ;
V_83 = - V_168 ;
if ( F_210 ( V_424 ) )
goto V_429;
}
if ( F_2 ( V_2 -> V_4 ) )
V_83 = F_69 ( V_2 , V_72 , V_414 ) ;
else if ( F_210 ( V_424 ) || F_209 ( V_11 ) > 0 )
V_83 = F_19 ( V_2 -> V_4 , V_72 ,
V_430 ) ;
else {
V_425 = false ;
V_83 = 0 ;
}
if ( V_83 ) {
F_22 ( & V_81 -> V_22 , L_112 , V_83 ) ;
F_213 ( V_11 ) ;
V_429:
F_206 ( V_11 ) ;
V_428:
if ( V_11 -> V_431 == 1 )
F_211 ( V_11 , 1 ) ;
if ( V_11 -> V_423 )
( void ) F_208 ( V_11 ) ;
V_426:
if ( ! F_210 ( V_424 ) )
V_83 = 0 ;
} else {
F_22 ( & V_11 -> V_22 , L_113 ,
( F_210 ( V_424 ) ? L_114 : L_40 ) ,
V_11 -> V_423 ) ;
if ( V_425 ) {
V_11 -> F_201 = 1 ;
F_66 ( 10 ) ;
}
F_73 ( V_11 , V_326 ) ;
}
if ( V_83 == 0 && ! V_11 -> V_423 && V_11 -> V_223
&& F_151 ( V_72 , V_2 -> V_343 ) )
F_214 ( & V_81 -> V_22 ) ;
F_179 ( V_2 -> V_4 ) ;
F_200 ( V_81 ) ;
return V_83 ;
}
static int F_215 ( struct V_7 * V_11 )
{
int V_83 = 0 ;
T_1 V_432 = 0 ;
F_22 ( & V_11 -> V_22 , L_115 ,
V_11 -> V_224 ? L_116 : L_117 ) ;
F_73 ( V_11 , V_11 -> V_8
? V_91
: V_433 ) ;
if ( V_11 -> V_224 ) {
V_434:
if ( V_11 -> V_12 & V_435 )
V_83 = - V_116 ;
else
V_83 = F_216 ( V_11 ) ;
}
if ( V_83 == 0 ) {
V_432 = 0 ;
V_83 = F_100 ( V_11 , V_274 , 0 , & V_432 ) ;
if ( V_83 && ! V_11 -> V_224 && V_11 -> V_223 ) {
F_22 ( & V_11 -> V_22 , L_118 ) ;
V_11 -> V_224 = 1 ;
goto V_434;
}
}
if ( V_83 ) {
F_22 ( & V_11 -> V_22 , L_119 ,
V_83 ) ;
} else if ( V_11 -> V_8 && ! V_11 -> V_224 ) {
if ( V_11 -> V_14 < V_52 ) {
if ( V_432 & ( 1 << V_418 ) )
V_83 = F_208 ( V_11 ) ;
} else {
V_83 = F_100 ( V_11 , V_419 , 0 ,
& V_432 ) ;
if ( ! V_83 && V_432 & ( V_436
| V_437 ) )
V_83 = F_208 ( V_11 ) ;
}
if ( V_83 )
F_22 ( & V_11 -> V_22 ,
L_120 ,
V_83 ) ;
V_83 = 0 ;
}
return V_83 ;
}
static int F_217 ( struct V_7 * V_11 ,
struct V_1 * V_2 , int * V_72 ,
T_1 * V_180 , T_1 * V_3 )
{
int V_83 = 0 , V_438 = 0 ;
while ( V_438 < 2000 ) {
if ( V_83 || * V_3 & V_210 )
break;
F_66 ( 20 ) ;
V_438 += 20 ;
V_83 = F_28 ( V_2 , * V_72 , V_3 , V_180 ) ;
}
return V_83 ;
}
int F_218 ( struct V_7 * V_11 , T_3 V_424 )
{
struct V_1 * V_2 = F_3 ( V_11 -> V_25 ) ;
struct V_80 * V_81 = V_2 -> V_82 [ V_11 -> V_129 - 1 ] ;
int V_72 = V_11 -> V_129 ;
int V_83 ;
T_1 V_180 , V_3 ;
if ( ! F_146 ( V_72 , V_2 -> V_343 ) ) {
V_83 = F_147 ( & V_81 -> V_22 ) ;
if ( V_83 < 0 ) {
F_22 ( & V_11 -> V_22 , L_121 ,
V_83 ) ;
return V_83 ;
}
}
F_199 ( V_81 ) ;
V_83 = F_28 ( V_2 , V_72 , & V_3 , & V_180 ) ;
if ( V_83 == 0 && ! F_201 ( V_2 , V_3 ) )
goto V_439;
if ( F_2 ( V_2 -> V_4 ) )
V_83 = F_69 ( V_2 , V_72 , V_222 ) ;
else
V_83 = F_18 ( V_2 -> V_4 ,
V_72 , V_430 ) ;
if ( V_83 ) {
F_22 ( & V_81 -> V_22 , L_122 , V_83 ) ;
} else {
F_22 ( & V_11 -> V_22 , L_123 ,
( F_210 ( V_424 ) ? L_114 : L_40 ) ) ;
F_66 ( V_440 ) ;
V_83 = F_28 ( V_2 , V_72 , & V_3 , & V_180 ) ;
F_66 ( 10 ) ;
}
V_439:
if ( V_83 == 0 ) {
V_11 -> F_201 = 0 ;
if ( F_2 ( V_2 -> V_4 ) ) {
if ( V_180 & V_441 )
F_18 ( V_2 -> V_4 , V_72 ,
V_409 ) ;
} else {
if ( V_180 & V_442 )
F_18 ( V_2 -> V_4 , V_72 ,
V_443 ) ;
}
}
if ( V_11 -> V_223 && F_2 ( V_2 -> V_4 ) )
V_83 = F_217 ( V_11 , V_2 , & V_72 , & V_180 ,
& V_3 ) ;
V_83 = F_202 ( V_11 ,
V_2 , V_72 , V_83 , V_180 , V_3 ) ;
if ( V_83 == 0 )
V_83 = F_215 ( V_11 ) ;
if ( V_83 < 0 ) {
F_22 ( & V_11 -> V_22 , L_122 , V_83 ) ;
F_74 ( V_2 , V_72 ) ;
} else {
if ( V_11 -> V_431 == 1 )
F_211 ( V_11 , 1 ) ;
F_206 ( V_11 ) ;
F_213 ( V_11 ) ;
}
F_200 ( V_81 ) ;
return V_83 ;
}
int F_219 ( struct V_7 * V_11 )
{
int V_83 = 0 ;
F_142 ( V_11 ) ;
if ( V_11 -> V_90 == V_326 ) {
F_22 ( & V_11 -> V_22 , L_123 , L_124 ) ;
V_83 = F_186 ( V_11 ) ;
if ( V_83 == 0 ) {
F_189 ( V_11 ) ;
}
}
F_149 ( V_11 ) ;
return V_83 ;
}
static int F_220 ( struct V_1 * V_2 , unsigned int V_115 ,
T_1 V_3 , T_1 V_180 )
__must_hold( &port_dev->status_lock
static int F_221 ( struct V_1 * V_2 )
{
int V_72 ;
for ( V_72 = 1 ; V_72 <= V_2 -> V_4 -> V_9 ; ++ V_72 ) {
T_1 V_3 , V_180 ;
int V_83 ;
V_83 = F_28 ( V_2 , V_72 , & V_3 , & V_180 ) ;
if ( ! V_83 && V_180 )
return 1 ;
}
return 0 ;
}
static int F_222 ( struct V_122 * V_123 , T_3 V_424 )
{
struct V_1 * V_2 = F_4 ( V_123 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
unsigned V_72 ;
int V_83 ;
V_2 -> F_209 = 0 ;
for ( V_72 = 1 ; V_72 <= V_4 -> V_9 ; V_72 ++ ) {
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
struct V_7 * V_11 = V_81 -> V_187 ;
if ( V_11 && V_11 -> V_444 ) {
F_71 ( & V_81 -> V_22 , L_125 ,
F_223 ( & V_11 -> V_22 ) ) ;
if ( F_210 ( V_424 ) )
return - V_324 ;
}
if ( V_11 )
V_2 -> F_209 +=
F_209 ( V_11 ) ;
}
if ( V_4 -> V_423 && V_2 -> V_310 ) {
if ( F_221 ( V_2 ) ) {
if ( F_210 ( V_424 ) )
return - V_324 ;
F_224 ( & V_4 -> V_22 , 2000 ) ;
}
}
if ( F_2 ( V_4 ) && V_4 -> V_423 ) {
for ( V_72 = 1 ; V_72 <= V_4 -> V_9 ; V_72 ++ ) {
V_83 = F_19 ( V_4 ,
V_72 |
V_445 |
V_446 |
V_447 ,
V_448 ) ;
}
}
F_22 ( & V_123 -> V_22 , L_115 , V_118 ) ;
F_84 ( V_2 , V_230 ) ;
return 0 ;
}
static int F_225 ( struct V_122 * V_123 )
{
struct V_1 * V_2 = F_4 ( V_123 ) ;
F_22 ( & V_123 -> V_22 , L_115 , V_118 ) ;
F_78 ( V_2 , V_200 ) ;
return 0 ;
}
static int F_226 ( struct V_122 * V_123 )
{
struct V_1 * V_2 = F_4 ( V_123 ) ;
F_22 ( & V_123 -> V_22 , L_115 , V_118 ) ;
F_78 ( V_2 , V_207 ) ;
return 0 ;
}
void F_227 ( struct V_7 * V_449 )
{
F_71 ( & V_449 -> V_22 , L_126 ) ;
V_449 -> V_224 = 1 ;
}
static int F_228 ( struct V_7 * V_11 , enum V_450 V_90 )
{
struct V_451 * V_452 ;
unsigned long long V_453 ;
unsigned long long V_454 ;
unsigned long long V_455 ;
unsigned long long V_456 ;
int V_57 ;
if ( V_11 -> V_90 != V_91 )
return 0 ;
V_453 = F_229 ( V_11 -> V_53 . V_46 , 1000 ) ;
V_454 = F_229 ( V_11 -> V_53 . V_43 , 1000 ) ;
V_455 = F_229 ( V_11 -> V_54 . V_46 , 1000 ) ;
V_456 = F_229 ( V_11 -> V_54 . V_43 , 1000 ) ;
if ( ( V_90 == V_457 &&
( V_453 > V_458 ||
V_454 > V_458 ) ) ||
( V_90 == V_459 &&
( V_455 > V_460 ||
V_456 > V_460 ) ) ) {
F_22 ( & V_11 -> V_22 , L_127 ,
V_461 [ V_90 ] , V_453 , V_454 ) ;
return - V_69 ;
}
if ( V_453 > V_458 )
V_453 = V_458 ;
if ( V_454 > V_458 )
V_454 = V_458 ;
if ( V_455 > V_460 )
V_455 = V_460 ;
if ( V_456 > V_460 )
V_456 = V_460 ;
V_452 = F_56 ( sizeof *( V_452 ) , V_209 ) ;
if ( ! V_452 )
return - V_168 ;
V_452 -> V_453 = V_453 ;
V_452 -> V_454 = V_454 ;
V_452 -> V_455 = F_230 ( V_455 ) ;
V_452 -> V_456 = F_230 ( V_456 ) ;
V_57 = F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_462 ,
V_274 ,
0 , 0 ,
V_452 , sizeof *( V_452 ) ,
V_203 ) ;
F_52 ( V_452 ) ;
return V_57 ;
}
static int F_231 ( struct V_7 * V_11 ,
enum V_450 V_90 , bool V_463 )
{
int V_57 ;
int V_70 ;
switch ( V_90 ) {
case V_457 :
V_70 = V_464 ;
break;
case V_459 :
V_70 = V_465 ;
break;
default:
F_71 ( & V_11 -> V_22 , L_128 ,
V_118 , V_463 ? L_129 : L_130 ) ;
return - V_69 ;
}
if ( V_11 -> V_90 != V_91 ) {
F_22 ( & V_11 -> V_22 , L_131
L_132 ,
V_118 , V_463 ? L_129 : L_130 ,
V_461 [ V_90 ] ) ;
return 0 ;
}
if ( V_463 ) {
V_57 = F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_74 ,
V_274 ,
V_70 ,
0 , NULL , 0 ,
V_203 ) ;
} else {
V_57 = F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_71 ,
V_274 ,
V_70 ,
0 , NULL , 0 ,
V_203 ) ;
}
if ( V_57 < 0 ) {
F_71 ( & V_11 -> V_22 , L_133 ,
V_463 ? L_134 : L_135 ,
V_461 [ V_90 ] ) ;
return - V_324 ;
}
return 0 ;
}
static int F_232 ( struct V_7 * V_11 ,
enum V_450 V_90 , int V_466 )
{
int V_57 ;
int V_70 ;
switch ( V_90 ) {
case V_457 :
V_70 = V_467 ;
break;
case V_459 :
V_70 = V_468 ;
break;
default:
F_71 ( & V_11 -> V_22 , L_136 ,
V_118 ) ;
return - V_69 ;
}
if ( V_90 == V_457 && V_466 > V_469 &&
V_466 != V_470 ) {
F_71 ( & V_11 -> V_22 , L_137
L_138 ,
V_461 [ V_90 ] , V_466 ) ;
return - V_69 ;
}
V_57 = F_19 ( V_11 -> V_25 ,
F_233 ( V_466 ) | V_11 -> V_129 ,
V_70 ) ;
if ( V_57 < 0 ) {
F_71 ( & V_11 -> V_22 , L_139
L_140 , V_461 [ V_90 ] ,
V_466 , V_57 ) ;
return - V_324 ;
}
if ( V_90 == V_457 )
V_11 -> V_53 . V_466 = V_466 ;
else
V_11 -> V_54 . V_466 = V_466 ;
return 0 ;
}
static void F_234 ( struct V_193 * V_159 , struct V_7 * V_11 ,
enum V_450 V_90 )
{
int V_466 , V_57 ;
T_4 V_471 = V_11 -> V_17 -> V_21 -> V_23 ;
T_5 V_472 = V_11 -> V_17 -> V_21 -> V_24 ;
if ( ( V_90 == V_457 && V_471 == 0 ) ||
( V_90 == V_459 && V_472 == 0 ) )
return;
V_57 = F_228 ( V_11 , V_90 ) ;
if ( V_57 < 0 ) {
F_71 ( & V_11 -> V_22 , L_141 ,
V_461 [ V_90 ] ) ;
return;
}
V_466 = V_159 -> V_160 -> V_473 ( V_159 , V_11 , V_90 ) ;
if ( V_466 == 0 )
return;
if ( V_466 < 0 ) {
F_71 ( & V_11 -> V_22 , L_142
L_143 , V_461 [ V_90 ] ,
V_466 ) ;
return;
}
if ( F_232 ( V_11 , V_90 , V_466 ) )
V_159 -> V_160 -> V_474 ( V_159 , V_11 , V_90 ) ;
else if ( V_11 -> V_8 )
F_231 ( V_11 , V_90 , true ) ;
}
static int F_235 ( struct V_193 * V_159 , struct V_7 * V_11 ,
enum V_450 V_90 )
{
switch ( V_90 ) {
case V_457 :
case V_459 :
break;
default:
F_71 ( & V_11 -> V_22 , L_144 ,
V_118 ) ;
return - V_69 ;
}
if ( F_232 ( V_11 , V_90 , 0 ) )
return - V_324 ;
F_231 ( V_11 , V_90 , false ) ;
if ( V_159 -> V_160 -> V_474 ( V_159 , V_11 , V_90 ) )
F_71 ( & V_11 -> V_22 , L_145
L_146 ,
V_461 [ V_90 ] ) ;
return 0 ;
}
int F_236 ( struct V_7 * V_11 )
{
struct V_193 * V_159 ;
if ( ! V_11 || ! V_11 -> V_25 ||
V_11 -> V_14 != V_52 ||
! V_11 -> V_26 ||
V_11 -> V_90 < V_411 )
return 0 ;
V_159 = F_60 ( V_11 -> V_173 ) ;
if ( ! V_159 || ! V_159 -> V_160 -> V_474 )
return 0 ;
V_11 -> V_475 ++ ;
if ( ( V_11 -> V_53 . V_466 == 0 && V_11 -> V_54 . V_466 == 0 ) )
return 0 ;
if ( F_235 ( V_159 , V_11 , V_457 ) )
goto V_476;
if ( F_235 ( V_159 , V_11 , V_459 ) )
goto V_476;
V_11 -> V_477 = 0 ;
return 0 ;
V_476:
F_237 ( V_11 ) ;
return - V_324 ;
}
int F_212 ( struct V_7 * V_11 )
{
struct V_193 * V_159 = F_60 ( V_11 -> V_173 ) ;
int V_57 ;
if ( ! V_159 )
return - V_69 ;
F_29 ( V_159 -> V_478 ) ;
V_57 = F_236 ( V_11 ) ;
F_31 ( V_159 -> V_478 ) ;
return V_57 ;
}
void F_237 ( struct V_7 * V_11 )
{
struct V_193 * V_159 ;
if ( ! V_11 || ! V_11 -> V_25 ||
V_11 -> V_14 != V_52 ||
! V_11 -> V_26 ||
V_11 -> V_90 < V_411 )
return;
V_11 -> V_475 -- ;
V_159 = F_60 ( V_11 -> V_173 ) ;
if ( ! V_159 || ! V_159 -> V_160 -> V_473 ||
! V_159 -> V_160 -> V_474 )
return;
if ( V_11 -> V_475 > 0 )
return;
F_234 ( V_159 , V_11 , V_457 ) ;
F_234 ( V_159 , V_11 , V_459 ) ;
V_11 -> V_477 = 1 ;
}
void F_213 ( struct V_7 * V_11 )
{
struct V_193 * V_159 = F_60 ( V_11 -> V_173 ) ;
if ( ! V_159 )
return;
F_29 ( V_159 -> V_478 ) ;
F_237 ( V_11 ) ;
F_31 ( V_159 -> V_478 ) ;
}
int F_236 ( struct V_7 * V_11 )
{
return 0 ;
}
void F_237 ( struct V_7 * V_11 ) { }
int F_212 ( struct V_7 * V_11 )
{
return 0 ;
}
void F_213 ( struct V_7 * V_11 ) { }
int F_204 ( struct V_7 * V_11 )
{
return 0 ;
}
void F_206 ( struct V_7 * V_11 ) { }
static int F_220 ( struct V_1 * V_2 , unsigned int V_115 ,
T_1 V_3 , T_1 V_180 )
{
return 0 ;
}
int F_238 ( struct V_1 * V_2 , int V_72 , bool V_479 )
{
int V_57 ;
T_1 V_180 , V_3 ;
unsigned V_480 = 0xffff ;
int V_179 , V_481 = 0 ;
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
for ( V_179 = 0 ; ; V_179 += V_184 ) {
V_57 = F_28 ( V_2 , V_72 , & V_3 , & V_180 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( ! ( V_180 & V_212 ) &&
( V_3 & V_210 ) == V_480 ) {
if ( ! V_479 ||
( V_480 == V_210 ) )
V_481 += V_184 ;
if ( V_481 >= V_225 )
break;
} else {
V_481 = 0 ;
V_480 = V_3 & V_210 ;
}
if ( V_180 & V_212 ) {
F_18 ( V_2 -> V_4 , V_72 ,
V_213 ) ;
}
if ( V_179 >= V_185 )
break;
F_66 ( V_184 ) ;
}
F_22 ( & V_81 -> V_22 , L_147 ,
V_179 , V_481 , V_3 ) ;
if ( V_481 < V_225 )
return - V_107 ;
return V_3 ;
}
void F_239 ( struct V_7 * V_11 )
{
F_240 ( V_11 , 0 + V_65 , true ) ;
F_240 ( V_11 , 0 + V_482 , true ) ;
F_241 ( V_11 , & V_11 -> V_344 , true ) ;
}
static int F_242 ( struct V_7 * V_11 , int V_171 )
{
int V_483 ;
struct V_193 * V_159 = F_60 ( V_11 -> V_173 ) ;
if ( ! V_159 -> V_160 -> V_484 && V_171 <= 1 )
return - V_69 ;
if ( V_11 -> V_90 == V_433 )
return 0 ;
if ( V_11 -> V_90 != V_411 )
return - V_69 ;
if ( V_159 -> V_160 -> V_484 )
V_483 = V_159 -> V_160 -> V_484 ( V_159 , V_11 ) ;
else
V_483 = F_14 ( V_11 , F_243 () ,
V_485 , 0 , V_171 , 0 ,
NULL , 0 , V_203 ) ;
if ( V_483 == 0 ) {
F_139 ( V_11 , V_171 ) ;
F_73 ( V_11 , V_433 ) ;
F_239 ( V_11 ) ;
}
return V_483 ;
}
static void F_244 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_3 ( V_11 -> V_25 ) ;
int V_371 = V_486 ;
if ( ! V_11 -> V_431 )
return;
if ( V_2 )
V_371 = V_2 -> V_82 [ V_11 -> V_129 - 1 ] -> V_371 ;
if ( ( V_11 -> V_17 -> V_18 -> V_20 & F_245 ( V_487 ) ) ||
V_371 == V_374 ) {
V_11 -> V_488 = 1 ;
F_211 ( V_11 , 1 ) ;
}
}
static int F_246 ( struct V_7 * V_11 )
{
struct V_193 * V_159 = F_60 ( V_11 -> V_173 ) ;
if ( ! V_159 -> V_160 -> V_489 )
return 0 ;
if ( V_11 -> V_90 == V_433 )
return 0 ;
if ( V_11 -> V_90 != V_411 )
return - V_69 ;
return V_159 -> V_160 -> V_489 ( V_159 , V_11 ) ;
}
static int
F_247 ( struct V_1 * V_2 , struct V_7 * V_11 , int V_72 ,
int V_490 )
{
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_193 * V_159 = F_60 ( V_4 -> V_173 ) ;
int V_56 , V_491 , V_483 ;
unsigned V_195 = V_399 ;
enum V_492 V_493 = V_11 -> V_14 ;
const char * V_14 ;
int V_171 = V_11 -> V_171 ;
if ( ! V_4 -> V_25 ) {
V_195 = V_494 ;
if ( V_72 == V_4 -> V_173 -> V_361 )
V_4 -> V_173 -> V_362 = 0 ;
}
if ( V_493 == V_403 )
V_195 = V_400 ;
F_29 ( & V_4 -> V_173 -> V_335 ) ;
V_483 = F_195 ( V_2 , V_72 , V_11 , V_195 , false ) ;
if ( V_483 < 0 )
goto V_246;
V_483 = - V_116 ;
if ( V_493 != V_495 && V_493 != V_11 -> V_14 ) {
F_22 ( & V_11 -> V_22 , L_148 ) ;
goto V_246;
}
V_493 = V_11 -> V_14 ;
switch ( V_11 -> V_14 ) {
case V_52 :
case V_402 :
V_11 -> V_344 . V_283 . V_496 = F_230 ( 512 ) ;
break;
case V_15 :
V_11 -> V_344 . V_283 . V_496 = F_230 ( 64 ) ;
break;
case V_16 :
V_11 -> V_344 . V_283 . V_496 = F_230 ( 64 ) ;
break;
case V_403 :
V_11 -> V_344 . V_283 . V_496 = F_230 ( 8 ) ;
break;
default:
goto V_246;
}
if ( V_11 -> V_14 == V_402 )
V_14 = L_149 ;
else
V_14 = F_248 ( V_11 -> V_14 ) ;
if ( V_11 -> V_14 != V_52 )
F_7 ( & V_11 -> V_22 ,
L_150 ,
( V_11 -> V_355 ) ? L_151 : L_152 , V_14 ,
V_171 , V_11 -> V_173 -> V_497 -> V_160 -> V_498 ) ;
if ( V_4 -> V_145 ) {
V_11 -> V_145 = V_4 -> V_145 ;
V_11 -> V_170 = V_4 -> V_170 ;
} else if ( V_11 -> V_14 != V_15
&& V_4 -> V_14 == V_15 ) {
if ( ! V_2 -> V_145 . V_2 ) {
F_30 ( & V_11 -> V_22 , L_153 ) ;
V_483 = - V_69 ;
goto V_246;
}
V_11 -> V_145 = & V_2 -> V_145 ;
V_11 -> V_170 = V_72 ;
}
for ( V_56 = 0 ; V_56 < V_499 ; ( ++ V_56 , F_66 ( 100 ) ) ) {
bool V_500 = false ;
if ( F_191 ( V_11 , V_490 ) ) {
struct V_501 * V_502 ;
int V_503 = 0 ;
V_500 = true ;
V_483 = F_246 ( V_11 ) ;
if ( V_483 < 0 ) {
F_30 ( & V_11 -> V_22 ,
L_154 ,
V_483 ) ;
goto V_246;
}
#define F_249 64
V_502 = F_56 ( F_249 , V_209 ) ;
if ( ! V_502 ) {
V_483 = - V_168 ;
continue;
}
for ( V_491 = 0 ; V_491 < 3 ; ++ V_491 ) {
V_502 -> V_504 = 0 ;
V_503 = F_14 ( V_11 , F_250 () ,
V_64 , V_65 ,
V_505 << 8 , 0 ,
V_502 , F_249 ,
V_506 ) ;
switch ( V_502 -> V_504 ) {
case 8 : case 16 : case 32 : case 64 : case 255 :
if ( V_502 -> V_507 ==
V_505 ) {
V_503 = 0 ;
break;
}
default:
if ( V_503 == 0 )
V_503 = - V_508 ;
break;
}
if ( V_503 == 0 )
break;
}
V_11 -> V_36 . V_504 =
V_502 -> V_504 ;
F_52 ( V_502 ) ;
V_483 = F_195 ( V_2 , V_72 , V_11 , V_195 , false ) ;
if ( V_483 < 0 )
goto V_246;
if ( V_493 != V_11 -> V_14 ) {
F_22 ( & V_11 -> V_22 ,
L_148 ) ;
V_483 = - V_116 ;
goto V_246;
}
if ( V_503 ) {
if ( V_503 != - V_116 )
F_30 ( & V_11 -> V_22 , L_155 ,
V_503 ) ;
V_483 = - V_509 ;
continue;
}
#undef F_249
}
if ( V_11 -> V_336 == 0 ) {
for ( V_491 = 0 ; V_491 < V_510 ; ++ V_491 ) {
V_483 = F_242 ( V_11 , V_171 ) ;
if ( V_483 >= 0 )
break;
F_66 ( 200 ) ;
}
if ( V_483 < 0 ) {
if ( V_483 != - V_116 )
F_30 ( & V_11 -> V_22 , L_156 ,
V_171 , V_483 ) ;
goto V_246;
}
if ( V_11 -> V_14 == V_52 ) {
V_171 = V_11 -> V_171 ;
F_7 ( & V_11 -> V_22 ,
L_157 ,
( V_11 -> V_355 ) ? L_151 : L_152 ,
V_171 , V_11 -> V_173 -> V_497 -> V_160 -> V_498 ) ;
}
F_66 ( 10 ) ;
if ( V_500 )
break;
}
V_483 = F_187 ( V_11 , 8 ) ;
if ( V_483 < 8 ) {
if ( V_483 != - V_116 )
F_30 ( & V_11 -> V_22 ,
L_158 ,
V_483 ) ;
if ( V_483 >= 0 )
V_483 = - V_509 ;
} else {
V_483 = 0 ;
break;
}
}
if ( V_483 )
goto V_246;
if ( ( V_11 -> V_14 == V_52 ) &&
( F_12 ( V_11 -> V_36 . V_511 ) < 0x0300 ) ) {
F_30 ( & V_11 -> V_22 , L_159
L_160 ) ;
F_195 ( V_2 , V_72 , V_11 ,
V_512 , true ) ;
V_483 = - V_69 ;
goto V_246;
}
if ( V_11 -> V_36 . V_504 == 0xff ||
V_11 -> V_14 == V_52 )
V_56 = 512 ;
else
V_56 = V_11 -> V_36 . V_504 ;
if ( F_251 ( & V_11 -> V_344 . V_283 ) != V_56 ) {
if ( V_11 -> V_14 == V_403 ||
! ( V_56 == 8 || V_56 == 16 || V_56 == 32 || V_56 == 64 ) ) {
F_30 ( & V_11 -> V_22 , L_161 , V_56 ) ;
V_483 = - V_509 ;
goto V_246;
}
if ( V_11 -> V_14 == V_16 )
F_22 ( & V_11 -> V_22 , L_162 , V_56 ) ;
else
F_71 ( & V_11 -> V_22 , L_163 , V_56 ) ;
V_11 -> V_344 . V_283 . V_496 = F_230 ( V_56 ) ;
F_239 ( V_11 ) ;
}
V_483 = F_187 ( V_11 , V_513 ) ;
if ( V_483 < ( signed ) sizeof( V_11 -> V_36 ) ) {
if ( V_483 != - V_116 )
F_30 ( & V_11 -> V_22 , L_164 ,
V_483 ) ;
if ( V_483 >= 0 )
V_483 = - V_514 ;
goto V_246;
}
F_252 ( V_11 ) ;
if ( V_11 -> V_336 == 0 && F_12 ( V_11 -> V_36 . V_511 ) >= 0x0201 ) {
V_483 = F_253 ( V_11 ) ;
if ( ! V_483 ) {
V_11 -> V_26 = F_5 ( V_11 ) ;
F_11 ( V_11 ) ;
}
}
V_483 = 0 ;
if ( V_159 -> V_160 -> V_515 )
V_159 -> V_160 -> V_515 ( V_159 , V_11 ) ;
F_244 ( V_11 ) ;
V_246:
if ( V_483 ) {
F_72 ( V_2 , V_72 , 0 ) ;
F_139 ( V_11 , V_171 ) ;
}
F_31 ( & V_4 -> V_173 -> V_335 ) ;
return V_483 ;
}
static void
F_254 ( struct V_1 * V_2 , struct V_7 * V_11 , int V_72 )
{
struct V_516 * V_517 ;
int V_83 ;
if ( V_11 -> V_12 & V_518 )
return;
V_517 = F_56 ( sizeof *V_517 , V_245 ) ;
if ( V_517 == NULL )
return;
V_83 = F_255 ( V_11 , V_519 , 0 ,
V_517 , sizeof *V_517 ) ;
if ( V_83 == sizeof *V_517 ) {
F_7 ( & V_11 -> V_22 , L_165
L_166 ) ;
if ( V_2 -> V_227 ) {
V_2 -> V_94 [ V_72 - 1 ] = V_97 ;
F_25 ( V_104 ,
& V_2 -> V_87 , 0 ) ;
}
}
F_52 ( V_517 ) ;
}
static unsigned
F_256 ( struct V_1 * V_2 )
{
struct V_7 * V_4 = V_2 -> V_4 ;
int V_281 ;
int V_72 ;
if ( ! V_2 -> V_279 )
return 0 ;
V_281 = V_4 -> V_277 - V_2 -> V_36 -> V_282 ;
for ( V_72 = 1 ; V_72 <= V_4 -> V_9 ; ++ V_72 ) {
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
struct V_7 * V_11 = V_81 -> V_187 ;
unsigned V_243 ;
int V_520 ;
if ( ! V_11 )
continue;
if ( F_2 ( V_11 ) )
V_243 = 150 ;
else
V_243 = 100 ;
if ( V_11 -> V_8 )
V_520 = F_257 ( V_11 , V_11 -> V_8 ) ;
else if ( V_72 != V_11 -> V_173 -> V_361 || V_4 -> V_25 )
V_520 = V_243 ;
else
V_520 = 8 ;
if ( V_520 > V_2 -> V_278 )
F_71 ( & V_81 -> V_22 , L_167 ,
V_520 , V_2 -> V_278 ) ;
V_281 -= V_520 ;
}
if ( V_281 < 0 ) {
F_71 ( V_2 -> V_117 , L_168 ,
- V_281 ) ;
V_281 = 0 ;
}
return V_281 ;
}
static void F_258 ( struct V_1 * V_2 , int V_72 , T_1 V_3 ,
T_1 V_180 )
{
int V_83 , V_56 ;
unsigned V_243 ;
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_193 * V_159 = F_60 ( V_4 -> V_173 ) ;
struct V_80 * V_81 = V_2 -> V_82 [ V_72 - 1 ] ;
struct V_7 * V_11 = V_81 -> V_187 ;
static int V_521 = - 1 ;
if ( V_11 ) {
if ( V_159 -> V_522 && ! V_4 -> V_25 )
F_259 ( V_159 -> V_522 , V_11 -> V_14 ) ;
F_86 ( & V_81 -> V_187 ) ;
}
if ( ! ( V_3 & V_210 ) ||
( V_180 & V_212 ) )
F_54 ( V_72 , V_2 -> V_191 ) ;
if ( V_180 & ( V_212 |
V_214 ) ) {
V_83 = F_260 ( V_2 , V_72 ) ;
if ( V_83 < 0 ) {
if ( V_83 != - V_116 &&
V_72 != V_521 &&
F_261 () )
F_30 ( & V_81 -> V_22 , L_169 ) ;
V_3 &= ~ V_210 ;
V_521 = V_72 ;
} else {
V_3 = V_83 ;
}
}
if ( ! ( V_3 & V_210 ) ||
F_65 ( V_72 , V_2 -> V_191 ) ) {
if ( F_64 ( V_2 )
&& ! F_198 ( V_2 , V_3 )
&& ! V_81 -> V_320 )
F_19 ( V_4 , V_72 , V_164 ) ;
if ( V_3 & V_211 )
goto V_408;
return;
}
if ( F_2 ( V_2 -> V_4 ) )
V_243 = 150 ;
else
V_243 = 100 ;
V_83 = 0 ;
for ( V_56 = 0 ; V_56 < V_523 ; V_56 ++ ) {
V_11 = F_262 ( V_4 , V_4 -> V_173 , V_72 ) ;
if ( ! V_11 ) {
F_30 ( & V_81 -> V_22 ,
L_170 ) ;
goto V_408;
}
F_73 ( V_11 , V_524 ) ;
V_11 -> V_277 = V_2 -> V_278 ;
V_11 -> V_202 = V_4 -> V_202 + 1 ;
V_11 -> V_336 = F_190 ( V_2 ) ;
if ( F_2 ( V_2 -> V_4 ) )
V_11 -> V_14 = V_52 ;
else
V_11 -> V_14 = V_495 ;
F_135 ( V_11 ) ;
if ( V_11 -> V_171 <= 0 ) {
V_83 = - V_401 ;
goto V_525;
}
F_199 ( V_81 ) ;
V_83 = F_247 ( V_2 , V_11 , V_72 , V_56 ) ;
F_200 ( V_81 ) ;
if ( V_83 < 0 )
goto V_525;
if ( V_11 -> V_12 & V_526 )
F_66 ( 1000 ) ;
if ( V_11 -> V_36 . V_527 == V_528
&& V_11 -> V_277 <= V_243 ) {
T_1 V_529 ;
V_83 = F_100 ( V_11 , V_274 , 0 ,
& V_529 ) ;
if ( V_83 ) {
F_22 ( & V_11 -> V_22 , L_171 , V_83 ) ;
goto V_530;
}
if ( ( V_529 & ( 1 << V_280 ) ) == 0 ) {
F_30 ( & V_11 -> V_22 ,
L_172
L_173 ) ;
if ( V_2 -> V_227 ) {
V_2 -> V_94 [ V_72 - 1 ] =
V_99 ;
F_25 (
V_104 ,
& V_2 -> V_87 , 0 ) ;
}
V_83 = - V_401 ;
goto V_530;
}
}
if ( F_12 ( V_11 -> V_36 . V_511 ) >= 0x0200
&& V_11 -> V_14 == V_16
&& V_292 != 0 )
F_254 ( V_2 , V_11 , V_72 ) ;
V_83 = 0 ;
F_29 ( & V_289 ) ;
F_113 ( & V_291 ) ;
if ( V_4 -> V_90 == V_188 )
V_83 = - V_401 ;
else
V_81 -> V_187 = V_11 ;
F_115 ( & V_291 ) ;
F_31 ( & V_289 ) ;
if ( ! V_83 ) {
V_83 = F_166 ( V_11 ) ;
if ( V_83 ) {
F_29 ( & V_289 ) ;
F_113 ( & V_291 ) ;
V_81 -> V_187 = NULL ;
F_115 ( & V_291 ) ;
F_31 ( & V_289 ) ;
} else {
if ( V_159 -> V_522 && ! V_4 -> V_25 )
F_263 ( V_159 -> V_522 ,
V_11 -> V_14 ) ;
}
}
if ( V_83 )
goto V_530;
V_83 = F_256 ( V_2 ) ;
if ( V_83 )
F_22 ( V_2 -> V_117 , L_174 , V_83 ) ;
return;
V_530:
F_72 ( V_2 , V_72 , 1 ) ;
V_525:
F_239 ( V_11 ) ;
F_138 ( V_11 ) ;
F_140 ( V_11 ) ;
F_109 ( V_11 ) ;
if ( ( V_83 == - V_401 ) || ( V_83 == - V_369 ) )
break;
}
if ( V_2 -> V_4 -> V_25 ||
! V_159 -> V_160 -> V_531 ||
! ( V_159 -> V_160 -> V_531 ) ( V_159 , V_72 ) ) {
if ( V_83 != - V_401 && V_83 != - V_116 )
F_30 ( & V_81 -> V_22 ,
L_175 ) ;
}
V_408:
F_72 ( V_2 , V_72 , 1 ) ;
if ( V_159 -> V_160 -> V_532 && ! V_2 -> V_4 -> V_25 )
V_159 -> V_160 -> V_532 ( V_159 , V_72 ) ;
}
static void F_264 ( struct V_1 * V_2 , int V_72 ,
T_1 V_3 , T_1 V_180 )
__must_hold( &port_dev->status_lock
static void F_265 ( struct V_1 * V_2 , int V_72 )
__must_hold( &port_dev->status_lock
static void V_306 ( struct V_85 * V_86 )
{
struct V_7 * V_4 ;
struct V_122 * V_123 ;
struct V_1 * V_2 ;
struct V_236 * V_237 ;
T_1 V_238 ;
T_1 V_239 ;
int V_56 , V_57 ;
V_2 = F_24 ( V_86 , struct V_1 , V_125 ) ;
V_4 = V_2 -> V_4 ;
V_237 = V_2 -> V_117 ;
V_123 = F_34 ( V_237 ) ;
F_22 ( V_237 , L_176 ,
V_4 -> V_90 , V_4 -> V_9 ,
( T_1 ) V_2 -> V_190 [ 0 ] ,
( T_1 ) V_2 -> V_141 [ 0 ] ) ;
F_142 ( V_4 ) ;
if ( F_266 ( V_2 -> V_124 ) )
goto V_533;
if ( V_4 -> V_90 == V_188 ) {
V_2 -> error = - V_116 ;
F_84 ( V_2 , V_290 ) ;
goto V_533;
}
V_57 = F_76 ( V_123 ) ;
if ( V_57 ) {
F_22 ( V_237 , L_177 , V_57 ) ;
goto V_533;
}
if ( V_2 -> V_92 )
goto V_534;
if ( V_2 -> error ) {
F_22 ( V_237 , L_178 , V_2 -> error ) ;
V_57 = F_267 ( V_4 ) ;
if ( V_57 ) {
F_22 ( V_237 , L_179 , V_57 ) ;
goto V_534;
}
V_2 -> V_137 = 0 ;
V_2 -> error = 0 ;
}
for ( V_56 = 1 ; V_56 <= V_4 -> V_9 ; V_56 ++ ) {
struct V_80 * V_81 = V_2 -> V_82 [ V_56 - 1 ] ;
if ( F_65 ( V_56 , V_2 -> V_141 )
|| F_65 ( V_56 , V_2 -> V_190 )
|| F_65 ( V_56 , V_2 -> V_130 ) ) {
F_169 ( & V_81 -> V_22 ) ;
F_90 ( & V_81 -> V_22 ) ;
F_199 ( V_81 ) ;
F_265 ( V_2 , V_56 ) ;
F_200 ( V_81 ) ;
F_214 ( & V_81 -> V_22 ) ;
}
}
if ( F_151 ( 0 , V_2 -> V_141 ) == 0 )
;
else if ( F_68 ( V_2 , & V_238 , & V_239 ) < 0 )
F_30 ( V_237 , L_180 ) ;
else {
if ( V_239 & V_535 ) {
F_22 ( V_237 , L_181 ) ;
F_16 ( V_4 , V_536 ) ;
if ( V_238 & V_285 )
V_2 -> V_279 = 1 ;
else
V_2 -> V_279 = 0 ;
}
if ( V_239 & V_537 ) {
T_1 V_83 = 0 ;
T_1 V_538 ;
F_22 ( V_237 , L_182 ) ;
F_16 ( V_4 , V_539 ) ;
F_66 ( 500 ) ;
F_63 ( V_2 , true ) ;
F_68 ( V_2 , & V_83 , & V_538 ) ;
if ( V_83 & V_286 )
F_30 ( V_237 , L_183 ) ;
}
}
V_534:
F_268 ( V_123 ) ;
V_533:
F_149 ( V_4 ) ;
F_77 ( V_123 ) ;
F_39 ( & V_2 -> V_126 , V_128 ) ;
}
int F_269 ( void )
{
if ( F_270 ( & V_540 ) < 0 ) {
F_271 ( V_541 L_184 ,
V_542 ) ;
return - 1 ;
}
V_127 = F_272 ( L_185 , V_543 , 0 ) ;
if ( V_127 )
return 0 ;
F_273 ( & V_540 ) ;
F_274 ( L_186 , V_542 ) ;
return - 1 ;
}
void F_275 ( void )
{
F_276 ( V_127 ) ;
F_273 ( & V_540 ) ;
}
static int F_277 ( struct V_7 * V_11 ,
struct V_501 * V_544 ,
struct V_545 * V_546 )
{
int V_88 = 0 ;
unsigned V_547 ;
unsigned V_548 = 0 ;
unsigned V_549 ;
unsigned V_550 ;
int V_551 ;
char * V_502 ;
if ( memcmp ( & V_11 -> V_36 , V_544 ,
sizeof( * V_544 ) ) != 0 )
return 1 ;
if ( ( V_546 && ! V_11 -> V_17 ) || ( ! V_546 && V_11 -> V_17 ) )
return 1 ;
if ( V_11 -> V_17 ) {
V_549 = F_12 ( V_11 -> V_17 -> V_283 -> V_358 ) ;
if ( V_549 != F_12 ( V_546 -> V_283 -> V_358 ) )
return 1 ;
if ( memcmp ( V_11 -> V_17 -> V_283 , V_546 -> V_283 , V_549 ) )
return 1 ;
}
if ( V_11 -> V_352 )
V_548 = strlen ( V_11 -> V_352 ) + 1 ;
V_549 = V_548 ;
for ( V_547 = 0 ; V_547 < V_11 -> V_36 . V_552 ; V_547 ++ ) {
V_550 = F_12 ( V_11 -> V_355 [ V_547 ] . V_283 . V_358 ) ;
V_549 = F_278 ( V_549 , V_550 ) ;
}
V_502 = F_56 ( V_549 , V_209 ) ;
if ( V_502 == NULL ) {
F_30 ( & V_11 -> V_22 , L_187 ) ;
return 1 ;
}
for ( V_547 = 0 ; V_547 < V_11 -> V_36 . V_552 ; V_547 ++ ) {
V_550 = F_12 ( V_11 -> V_355 [ V_547 ] . V_283 . V_358 ) ;
V_551 = F_255 ( V_11 , V_553 , V_547 , V_502 ,
V_550 ) ;
if ( V_551 != V_550 ) {
F_22 ( & V_11 -> V_22 , L_188 ,
V_547 , V_551 ) ;
V_88 = 1 ;
break;
}
if ( memcmp ( V_502 , V_11 -> V_357 [ V_547 ] , V_550 )
!= 0 ) {
F_22 ( & V_11 -> V_22 , L_189 ,
V_547 ,
( (struct V_554 * ) V_502 ) ->
V_555 ) ;
V_88 = 1 ;
break;
}
}
if ( ! V_88 && V_548 ) {
V_551 = F_279 ( V_11 , V_11 -> V_36 . V_349 ,
V_502 , V_548 ) ;
if ( V_551 + 1 != V_548 ) {
F_22 ( & V_11 -> V_22 , L_190 ,
V_551 ) ;
V_88 = 1 ;
} else if ( memcmp ( V_502 , V_11 -> V_352 , V_551 ) != 0 ) {
F_22 ( & V_11 -> V_22 , L_191 ) ;
V_88 = 1 ;
}
}
F_52 ( V_502 ) ;
return V_88 ;
}
static int F_216 ( struct V_7 * V_11 )
{
struct V_7 * V_556 = V_11 -> V_25 ;
struct V_1 * V_557 ;
struct V_193 * V_159 = F_60 ( V_11 -> V_173 ) ;
struct V_501 V_36 = V_11 -> V_36 ;
struct V_545 * V_17 ;
int V_56 , V_491 , V_57 = 0 ;
int V_72 = V_11 -> V_129 ;
if ( V_11 -> V_90 == V_188 ||
V_11 -> V_90 == V_326 ) {
F_22 ( & V_11 -> V_22 , L_192 ,
V_11 -> V_90 ) ;
return - V_69 ;
}
if ( ! V_556 )
return - V_558 ;
V_557 = F_3 ( V_556 ) ;
if ( V_11 -> V_427 == 1 )
F_211 ( V_11 , 0 ) ;
V_57 = F_212 ( V_11 ) ;
if ( V_57 ) {
F_30 ( & V_11 -> V_22 , L_193 , V_118 ) ;
goto V_559;
}
V_57 = F_204 ( V_11 ) ;
if ( V_57 ) {
F_30 ( & V_11 -> V_22 , L_194 ,
V_118 ) ;
goto V_559;
}
V_17 = V_11 -> V_17 ;
V_11 -> V_17 = NULL ;
for ( V_56 = 0 ; V_56 < V_523 ; ++ V_56 ) {
F_239 ( V_11 ) ;
V_57 = F_247 ( V_557 , V_11 , V_72 , V_56 ) ;
if ( V_57 >= 0 || V_57 == - V_401 || V_57 == - V_116 )
break;
}
if ( V_57 < 0 )
goto V_560;
if ( F_277 ( V_11 , & V_36 , V_17 ) ) {
F_7 ( & V_11 -> V_22 , L_195 ) ;
V_11 -> V_36 = V_36 ;
goto V_560;
}
if ( ! V_11 -> V_8 )
goto V_408;
F_29 ( V_159 -> V_478 ) ;
V_57 = F_280 ( V_11 , V_11 -> V_8 , NULL , NULL ) ;
if ( V_57 < 0 ) {
F_71 ( & V_11 -> V_22 ,
L_196
L_197 ) ;
F_31 ( V_159 -> V_478 ) ;
goto V_560;
}
V_57 = F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_561 , 0 ,
V_11 -> V_8 -> V_283 . V_555 , 0 ,
NULL , 0 , V_203 ) ;
if ( V_57 < 0 ) {
F_30 ( & V_11 -> V_22 ,
L_198 ,
V_11 -> V_8 -> V_283 . V_555 , V_57 ) ;
F_31 ( V_159 -> V_478 ) ;
goto V_560;
}
F_31 ( V_159 -> V_478 ) ;
F_73 ( V_11 , V_91 ) ;
for ( V_56 = 0 ; V_56 < V_11 -> V_8 -> V_283 . V_562 ; V_56 ++ ) {
struct V_563 * V_355 = V_11 -> V_8 ;
struct V_122 * V_123 = V_355 -> V_10 [ V_56 ] ;
struct V_564 * V_283 ;
V_283 = & V_123 -> V_296 -> V_283 ;
if ( V_283 -> V_565 == 0 ) {
F_281 ( V_11 , V_123 , true ) ;
F_282 ( V_11 , V_123 , true ) ;
V_57 = 0 ;
} else {
V_123 -> V_566 = 1 ;
V_57 = F_99 ( V_11 , V_283 -> V_567 ,
V_283 -> V_565 ) ;
V_123 -> V_566 = 0 ;
}
if ( V_57 < 0 ) {
F_30 ( & V_11 -> V_22 , L_199
L_200 ,
V_283 -> V_567 ,
V_283 -> V_565 ,
V_57 ) ;
goto V_560;
}
for ( V_491 = 0 ; V_491 < V_123 -> V_296 -> V_283 . V_305 ; V_491 ++ )
V_123 -> V_296 -> V_235 [ V_491 ] . V_568 = 0 ;
}
V_408:
F_211 ( V_11 , 1 ) ;
F_213 ( V_11 ) ;
F_206 ( V_11 ) ;
F_283 ( V_11 ) ;
V_11 -> V_17 = V_17 ;
return 0 ;
V_560:
F_283 ( V_11 ) ;
V_11 -> V_17 = V_17 ;
V_559:
F_74 ( V_557 , V_72 ) ;
return - V_116 ;
}
int F_267 ( struct V_7 * V_11 )
{
int V_57 ;
int V_56 ;
unsigned int V_569 ;
struct V_80 * V_81 ;
struct V_563 * V_355 = V_11 -> V_8 ;
struct V_1 * V_2 = F_3 ( V_11 -> V_25 ) ;
if ( V_11 -> V_90 == V_188 ||
V_11 -> V_90 == V_326 ) {
F_22 ( & V_11 -> V_22 , L_192 ,
V_11 -> V_90 ) ;
return - V_69 ;
}
if ( ! V_11 -> V_25 ) {
F_22 ( & V_11 -> V_22 , L_201 , V_118 ) ;
return - V_558 ;
}
V_81 = V_2 -> V_82 [ V_11 -> V_129 - 1 ] ;
V_569 = F_284 () ;
F_186 ( V_11 ) ;
if ( V_355 ) {
for ( V_56 = 0 ; V_56 < V_355 -> V_283 . V_562 ; ++ V_56 ) {
struct V_122 * V_570 = V_355 -> V_10 [ V_56 ] ;
struct V_571 * V_158 ;
int V_572 = 0 ;
if ( V_570 -> V_22 . V_160 ) {
V_158 = F_285 ( V_570 -> V_22 . V_160 ) ;
if ( V_158 -> V_573 && V_158 -> V_574 )
V_572 = ( V_158 -> V_573 ) ( V_570 ) ;
else if ( V_570 -> V_575 ==
V_576 )
V_572 = 1 ;
if ( V_572 )
F_286 ( V_570 ) ;
}
}
}
F_199 ( V_81 ) ;
V_57 = F_216 ( V_11 ) ;
F_200 ( V_81 ) ;
if ( V_355 ) {
for ( V_56 = V_355 -> V_283 . V_562 - 1 ; V_56 >= 0 ; -- V_56 ) {
struct V_122 * V_570 = V_355 -> V_10 [ V_56 ] ;
struct V_571 * V_158 ;
int V_577 = V_570 -> V_578 ;
if ( ! V_577 && V_570 -> V_22 . V_160 ) {
V_158 = F_285 ( V_570 -> V_22 . V_160 ) ;
if ( V_158 -> V_574 )
V_577 = ( V_158 -> V_574 ) ( V_570 ) ;
else if ( V_570 -> V_575 ==
V_576 )
V_577 = 1 ;
if ( V_577 )
V_570 -> V_578 = 1 ;
}
}
F_287 ( V_11 ) ;
}
F_189 ( V_11 ) ;
F_288 ( V_569 ) ;
return V_57 ;
}
void F_289 ( struct V_122 * V_579 )
{
if ( F_62 ( & V_579 -> V_580 ) )
F_125 ( V_579 ) ;
}
struct V_7 * F_290 ( struct V_7 * V_4 ,
int V_72 )
{
struct V_1 * V_2 = F_3 ( V_4 ) ;
if ( V_72 < 1 || V_72 > V_4 -> V_9 )
return NULL ;
return V_2 -> V_82 [ V_72 - 1 ] -> V_187 ;
}
void F_108 ( struct V_7 * V_4 ,
struct V_63 * V_283 )
{
struct V_1 * V_2 = F_3 ( V_4 ) ;
enum V_581 V_371 ;
int V_56 ;
if ( ! V_2 )
return;
if ( ! F_2 ( V_4 ) ) {
for ( V_56 = 1 ; V_56 <= V_4 -> V_9 ; V_56 ++ ) {
struct V_80 * V_81 = V_2 -> V_82 [ V_56 - 1 ] ;
V_371 = V_81 -> V_371 ;
if ( V_371 == V_374 ) {
T_2 V_582 = 1 << ( V_56 % 8 ) ;
if ( ! ( V_283 -> V_37 . V_251 . V_252 [ V_56 / 8 ] & V_582 ) ) {
F_22 ( & V_81 -> V_22 , L_202 ) ;
V_283 -> V_37 . V_251 . V_252 [ V_56 / 8 ] |= V_582 ;
}
}
}
} else {
T_1 V_583 = F_12 ( V_283 -> V_37 . V_38 . V_252 ) ;
for ( V_56 = 1 ; V_56 <= V_4 -> V_9 ; V_56 ++ ) {
struct V_80 * V_81 = V_2 -> V_82 [ V_56 - 1 ] ;
V_371 = V_81 -> V_371 ;
if ( V_371 == V_374 ) {
T_1 V_582 = 1 << V_56 ;
if ( ! ( V_583 & V_582 ) ) {
F_22 ( & V_81 -> V_22 , L_202 ) ;
V_583 |= V_582 ;
}
}
}
V_283 -> V_37 . V_38 . V_252 = F_230 ( V_583 ) ;
}
}
T_6 F_291 ( struct V_7 * V_4 ,
int V_72 )
{
struct V_1 * V_2 = F_3 ( V_4 ) ;
if ( ! V_2 )
return NULL ;
return F_292 ( & V_2 -> V_82 [ V_72 - 1 ] -> V_22 ) ;
}
