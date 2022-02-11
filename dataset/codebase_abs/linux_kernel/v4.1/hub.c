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
static int F_5 ( struct V_7 * V_11 )
{
if ( V_11 -> V_12 == V_13 ) {
if ( V_11 -> V_14 -> V_15 &&
( V_16 &
F_6 ( V_11 -> V_14 -> V_15 -> V_17 ) ) )
return 1 ;
return 0 ;
}
if ( ! V_11 -> V_14 -> V_18 ) {
F_7 ( & V_11 -> V_19 , L_5 ) ;
return 0 ;
}
if ( V_11 -> V_14 -> V_18 -> V_20 == 0 &&
V_11 -> V_14 -> V_18 -> V_21 == 0 ) {
if ( V_11 -> V_22 )
F_7 ( & V_11 -> V_19 , L_6 ) ;
else
F_7 ( & V_11 -> V_19 , L_7 ) ;
return 0 ;
}
if ( ! V_11 -> V_22 || V_11 -> V_22 -> V_23 )
return 1 ;
return 0 ;
}
static void F_8 ( struct V_7 * V_11 ,
struct V_24 * V_25 ,
unsigned int V_26 ,
struct V_1 * V_2 ,
struct V_24 * V_27 ,
unsigned int V_28 )
{
unsigned int V_29 ;
unsigned int V_30 ;
unsigned int V_31 ;
V_29 = V_27 -> V_32 +
( V_2 -> V_33 -> V_34 . V_35 . V_36 * 100 ) ;
V_30 = V_26 * 1000 ;
V_31 = V_28 * 1000 ;
if ( V_30 > V_31 )
V_29 += V_30 ;
else
V_29 += V_31 ;
V_25 -> V_32 = V_29 ;
}
static void F_9 ( struct V_7 * V_11 ,
struct V_24 * V_25 ,
unsigned int V_26 ,
struct V_1 * V_2 ,
struct V_24 * V_27 ,
unsigned int V_28 ,
unsigned int V_37 )
{
unsigned int V_38 ;
unsigned int V_39 ;
if ( V_26 > V_28 )
V_38 = V_26 * 1000 ;
else
V_38 = V_28 * 1000 ;
V_39 = V_37 * 1000 + V_27 -> V_40 ;
if ( V_38 > V_39 )
V_25 -> V_40 = V_38 ;
else
V_25 -> V_40 = V_39 ;
}
static void F_10 ( struct V_7 * V_11 ,
struct V_24 * V_25 )
{
struct V_7 * V_22 ;
unsigned int V_41 ;
unsigned int V_42 ;
V_42 = V_25 -> V_40 ;
for ( V_22 = V_11 -> V_22 , V_41 = 0 ; V_22 -> V_22 ;
V_22 = V_22 -> V_22 )
V_41 ++ ;
if ( V_41 > 0 )
V_42 += 2100 + 250 * ( V_41 - 1 ) ;
V_42 += 250 * V_41 ;
V_25 -> V_43 = V_42 ;
}
static void F_11 ( struct V_7 * V_11 )
{
struct V_1 * V_2 ;
unsigned int V_44 ;
unsigned int V_45 ;
unsigned int V_46 ;
unsigned int V_47 ;
unsigned int V_48 ;
if ( ! V_11 -> V_23 || V_11 -> V_12 != V_49 )
return;
V_2 = F_3 ( V_11 -> V_22 ) ;
if ( ! V_2 )
return;
V_45 = V_11 -> V_14 -> V_18 -> V_20 ;
V_46 = F_12 ( V_11 -> V_14 -> V_18 -> V_21 ) ;
V_47 = V_11 -> V_22 -> V_14 -> V_18 -> V_20 ;
V_48 = F_12 ( V_11 -> V_22 -> V_14 -> V_18 -> V_21 ) ;
F_8 ( V_11 , & V_11 -> V_50 , V_45 ,
V_2 , & V_11 -> V_22 -> V_50 , V_47 ) ;
F_8 ( V_11 , & V_11 -> V_51 , V_46 ,
V_2 , & V_11 -> V_22 -> V_51 , V_48 ) ;
V_44 = 1 ;
F_9 ( V_11 , & V_11 -> V_50 , V_45 ,
V_2 , & V_11 -> V_22 -> V_50 , V_47 ,
V_44 ) ;
if ( V_48 > V_47 )
V_44 = 1 + V_48 - V_47 ;
else
V_44 = 1 + V_47 ;
F_9 ( V_11 , & V_11 -> V_51 , V_46 ,
V_2 , & V_11 -> V_22 -> V_51 , V_48 ,
V_44 ) ;
F_10 ( V_11 , & V_11 -> V_50 ) ;
F_10 ( V_11 , & V_11 -> V_51 ) ;
}
static int F_13 ( struct V_7 * V_4 , void * V_52 )
{
int V_53 , V_54 , V_55 ;
unsigned V_56 ;
if ( F_2 ( V_4 ) ) {
V_56 = V_57 ;
V_55 = V_58 ;
} else {
V_56 = V_59 ;
V_55 = sizeof( struct V_60 ) ;
}
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ ) {
V_54 = F_14 ( V_4 , F_15 ( V_4 , 0 ) ,
V_61 , V_62 | V_63 ,
V_56 << 8 , 0 , V_52 , V_55 ,
V_64 ) ;
if ( V_54 >= ( V_65 + 2 ) )
return V_54 ;
}
return - V_66 ;
}
static int F_16 ( struct V_7 * V_4 , int V_67 )
{
return F_14 ( V_4 , F_17 ( V_4 , 0 ) ,
V_68 , V_63 , V_67 , 0 , NULL , 0 , 1000 ) ;
}
int F_18 ( struct V_7 * V_4 , int V_69 , int V_67 )
{
return F_14 ( V_4 , F_17 ( V_4 , 0 ) ,
V_68 , V_70 , V_67 , V_69 ,
NULL , 0 , 1000 ) ;
}
static int F_19 ( struct V_7 * V_4 , int V_69 , int V_67 )
{
return F_14 ( V_4 , F_17 ( V_4 , 0 ) ,
V_71 , V_70 , V_67 , V_69 ,
NULL , 0 , 1000 ) ;
}
static char * F_20 ( int V_72 )
{
switch ( V_72 ) {
case V_73 :
return L_8 ;
case V_74 :
return L_9 ;
case V_75 :
return L_10 ;
case V_76 :
return L_11 ;
default:
return L_12 ;
}
}
static void F_21 ( struct V_1 * V_2 , int V_69 , int V_72 )
{
struct V_77 * V_78 = V_2 -> V_79 [ V_69 - 1 ] ;
int V_80 ;
V_80 = F_19 ( V_2 -> V_4 , ( V_72 << 8 ) | V_69 ,
V_81 ) ;
F_22 ( & V_78 -> V_19 , L_13 ,
F_20 ( V_72 ) , V_80 ) ;
}
static void F_23 ( struct V_82 * V_83 )
{
struct V_1 * V_2 =
F_24 ( V_83 , struct V_1 , V_84 . V_83 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
unsigned V_53 ;
unsigned V_85 = 0 ;
int V_86 = - 1 ;
if ( V_4 -> V_87 != V_88 || V_2 -> V_89 )
return;
for ( V_53 = 0 ; V_53 < V_4 -> V_9 ; V_53 ++ ) {
unsigned V_72 , V_90 ;
switch ( V_2 -> V_91 [ V_53 ] ) {
case V_92 :
V_86 = V_53 ;
V_72 = V_76 ;
V_90 = V_93 ;
break;
case V_94 :
V_72 = V_74 ;
V_90 = V_95 ;
break;
case V_95 :
V_72 = V_75 ;
V_90 = V_94 ;
break;
case V_96 :
V_72 = V_73 ;
V_90 = V_97 ;
break;
case V_97 :
V_72 = V_75 ;
V_90 = V_96 ;
break;
case V_98 :
V_72 = V_74 ;
V_90 = V_99 ;
break;
case V_99 :
V_72 = V_73 ;
V_90 = V_98 ;
break;
default:
continue;
}
if ( V_72 != V_76 )
V_85 = 1 ;
F_21 ( V_2 , V_53 + 1 , V_72 ) ;
V_2 -> V_91 [ V_53 ] = V_90 ;
}
if ( ! V_85 && V_100 ) {
V_86 ++ ;
V_86 %= V_4 -> V_9 ;
F_21 ( V_2 , V_86 + 1 , V_74 ) ;
V_2 -> V_91 [ V_86 ] = V_92 ;
V_85 ++ ;
}
if ( V_85 )
F_25 ( V_101 ,
& V_2 -> V_84 , V_102 ) ;
}
static int F_26 ( struct V_7 * V_4 ,
struct V_103 * V_52 )
{
int V_53 , V_80 = - V_104 ;
for ( V_53 = 0 ; V_53 < V_105 &&
( V_80 == - V_104 || V_80 == - V_106 ) ; V_53 ++ ) {
V_80 = F_14 ( V_4 , F_15 ( V_4 , 0 ) ,
V_107 , V_62 | V_63 , 0 , 0 ,
V_52 , sizeof( * V_52 ) , V_108 ) ;
}
return V_80 ;
}
static int F_27 ( struct V_7 * V_4 , int V_69 ,
struct V_109 * V_52 )
{
int V_53 , V_80 = - V_104 ;
for ( V_53 = 0 ; V_53 < V_105 &&
( V_80 == - V_104 || V_80 == - V_106 ) ; V_53 ++ ) {
V_80 = F_14 ( V_4 , F_15 ( V_4 , 0 ) ,
V_107 , V_62 | V_70 , 0 , V_69 ,
V_52 , sizeof( * V_52 ) , V_108 ) ;
}
return V_80 ;
}
static int F_28 ( struct V_1 * V_2 , int V_69 ,
T_1 * V_80 , T_1 * V_110 )
{
int V_54 ;
F_29 ( & V_2 -> V_111 ) ;
V_54 = F_27 ( V_2 -> V_4 , V_69 , & V_2 -> V_80 -> V_112 ) ;
if ( V_54 < 4 ) {
if ( V_54 != - V_113 )
F_30 ( V_2 -> V_114 ,
L_14 , V_115 , V_54 ) ;
if ( V_54 >= 0 )
V_54 = - V_116 ;
} else {
* V_80 = F_12 ( V_2 -> V_80 -> V_112 . V_117 ) ;
* V_110 = F_12 ( V_2 -> V_80 -> V_112 . V_118 ) ;
V_54 = 0 ;
}
F_31 ( & V_2 -> V_111 ) ;
return V_54 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_119 * V_120 ;
if ( V_2 -> V_121 || F_33 ( & V_2 -> V_122 ) )
return;
V_120 = F_34 ( V_2 -> V_114 ) ;
F_35 ( V_120 ) ;
F_36 ( & V_2 -> V_123 ) ;
if ( F_37 ( V_124 , & V_2 -> V_122 ) )
return;
F_38 ( V_120 ) ;
F_39 ( & V_2 -> V_123 , V_125 ) ;
}
void F_40 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = F_3 ( V_4 ) ;
if ( V_2 )
F_32 ( V_2 ) ;
}
void F_41 ( struct V_7 * V_4 ,
unsigned int V_126 )
{
struct V_1 * V_2 ;
if ( ! V_4 )
return;
V_2 = F_3 ( V_4 ) ;
if ( V_2 ) {
F_42 ( V_126 , V_2 -> V_127 ) ;
F_32 ( V_2 ) ;
}
}
static void F_43 ( struct V_128 * V_128 )
{
struct V_1 * V_2 = V_128 -> V_129 ;
int V_80 = V_128 -> V_80 ;
unsigned V_53 ;
unsigned long V_130 ;
switch ( V_80 ) {
case - V_131 :
case - V_132 :
case - V_133 :
return;
default:
F_22 ( V_2 -> V_114 , L_15 , V_80 ) ;
if ( ( ++ V_2 -> V_134 < 10 ) || V_2 -> error )
goto V_135;
V_2 -> error = V_80 ;
case 0 :
V_130 = 0 ;
for ( V_53 = 0 ; V_53 < V_128 -> V_136 ; ++ V_53 )
V_130 |= ( ( unsigned long ) ( ( * V_2 -> V_137 ) [ V_53 ] ) )
<< ( V_53 * 8 ) ;
V_2 -> V_138 [ 0 ] = V_130 ;
break;
}
V_2 -> V_134 = 0 ;
F_32 ( V_2 ) ;
V_135:
if ( V_2 -> V_89 )
return;
if ( ( V_80 = F_44 ( V_2 -> V_128 , V_139 ) ) != 0
&& V_80 != - V_113 && V_80 != - V_140 )
F_30 ( V_2 -> V_114 , L_16 , V_80 ) ;
}
static inline int
F_45 ( struct V_7 * V_4 , T_1 V_141 , T_1 V_142 )
{
if ( ( ( V_141 >> 11 ) & V_143 ) ==
V_144 ) {
int V_80 = F_14 ( V_4 , F_17 ( V_4 , 0 ) ,
V_145 , V_70 ,
V_141 ^ 0x8000 , V_142 , NULL , 0 , 1000 ) ;
if ( V_80 )
return V_80 ;
}
return F_14 ( V_4 , F_17 ( V_4 , 0 ) ,
V_145 , V_70 , V_141 ,
V_142 , NULL , 0 , 1000 ) ;
}
static void F_46 ( struct V_82 * V_83 )
{
struct V_1 * V_2 =
F_24 ( V_83 , struct V_1 , V_142 . V_146 ) ;
unsigned long V_147 ;
F_47 ( & V_2 -> V_142 . V_148 , V_147 ) ;
while ( ! F_48 ( & V_2 -> V_142 . V_149 ) ) {
struct V_150 * V_151 ;
struct V_152 * V_153 ;
struct V_7 * V_4 = V_2 -> V_4 ;
const struct V_154 * V_155 ;
int V_80 ;
V_151 = V_2 -> V_142 . V_149 . V_151 ;
V_153 = F_49 ( V_151 , struct V_152 , V_149 ) ;
F_50 ( & V_153 -> V_149 ) ;
F_51 ( & V_2 -> V_142 . V_148 , V_147 ) ;
V_80 = F_45 ( V_4 , V_153 -> V_141 , V_153 -> V_142 ) ;
if ( V_80 && V_80 != - V_113 )
F_30 ( & V_4 -> V_19 ,
L_17 ,
V_153 -> V_142 , V_153 -> V_141 , V_80 ) ;
V_155 = V_153 -> V_156 -> V_157 ;
if ( V_155 -> V_158 )
( V_155 -> V_158 ) ( V_153 -> V_156 , V_153 -> V_159 ) ;
F_52 ( V_153 ) ;
F_47 ( & V_2 -> V_142 . V_148 , V_147 ) ;
}
F_51 ( & V_2 -> V_142 . V_148 , V_147 ) ;
}
int F_53 ( struct V_7 * V_4 , struct V_1 * V_2 ,
int V_69 , bool V_160 )
{
int V_54 ;
if ( V_160 )
V_54 = F_19 ( V_4 , V_69 , V_161 ) ;
else
V_54 = F_18 ( V_4 , V_69 , V_161 ) ;
if ( V_54 )
return V_54 ;
if ( V_160 )
F_42 ( V_69 , V_2 -> V_162 ) ;
else
F_54 ( V_69 , V_2 -> V_162 ) ;
return 0 ;
}
int F_55 ( struct V_128 * V_128 )
{
struct V_7 * V_11 = V_128 -> V_19 ;
int V_163 = V_128 -> V_163 ;
struct V_164 * V_142 = V_11 -> V_142 ;
unsigned long V_147 ;
struct V_152 * V_153 ;
if ( ( V_153 = F_56 ( sizeof *V_153 , V_139 ) ) == NULL ) {
F_30 ( & V_11 -> V_19 , L_18 ) ;
return - V_165 ;
}
V_153 -> V_142 = V_142 -> V_166 ? V_11 -> V_167 : 1 ;
V_153 -> V_141 = F_57 ( V_163 ) ;
V_153 -> V_141 |= V_11 -> V_168 << 4 ;
V_153 -> V_141 |= F_58 ( V_163 )
? ( V_144 << 11 )
: ( V_169 << 11 ) ;
if ( F_59 ( V_163 ) )
V_153 -> V_141 |= 1 << 15 ;
V_153 -> V_156 = F_60 ( V_11 -> V_170 ) ;
V_153 -> V_159 = V_128 -> V_159 ;
F_47 ( & V_142 -> V_148 , V_147 ) ;
F_61 ( & V_153 -> V_149 , & V_142 -> V_149 ) ;
F_62 ( & V_142 -> V_146 ) ;
F_51 ( & V_142 -> V_148 , V_147 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 , bool V_171 )
{
int V_69 ;
if ( F_64 ( V_2 ) )
F_22 ( V_2 -> V_114 , L_19 ) ;
else
F_22 ( V_2 -> V_114 , L_20
L_21 ) ;
for ( V_69 = 1 ; V_69 <= V_2 -> V_4 -> V_9 ; V_69 ++ )
if ( F_65 ( V_69 , V_2 -> V_162 ) )
F_19 ( V_2 -> V_4 , V_69 , V_161 ) ;
else
F_18 ( V_2 -> V_4 , V_69 ,
V_161 ) ;
if ( V_171 )
F_66 ( F_67 ( V_2 ) ) ;
}
static int F_68 ( struct V_1 * V_2 ,
T_1 * V_80 , T_1 * V_110 )
{
int V_54 ;
F_29 ( & V_2 -> V_111 ) ;
V_54 = F_26 ( V_2 -> V_4 , & V_2 -> V_80 -> V_2 ) ;
if ( V_54 < 0 ) {
if ( V_54 != - V_113 )
F_30 ( V_2 -> V_114 ,
L_14 , V_115 , V_54 ) ;
} else {
* V_80 = F_12 ( V_2 -> V_80 -> V_2 . V_172 ) ;
* V_110 = F_12 ( V_2 -> V_80 -> V_2 . V_173 ) ;
V_54 = 0 ;
}
F_31 ( & V_2 -> V_111 ) ;
return V_54 ;
}
static int F_69 ( struct V_1 * V_2 , int V_69 ,
unsigned int V_174 )
{
return F_19 ( V_2 -> V_4 ,
V_69 | ( V_174 << 3 ) ,
V_175 ) ;
}
static int F_70 ( struct V_1 * V_2 , int V_69 )
{
int V_54 ;
int V_176 ;
T_1 V_177 , V_3 ;
if ( ! F_2 ( V_2 -> V_4 ) )
return - V_66 ;
V_54 = F_28 ( V_2 , V_69 , & V_3 , & V_177 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( ( V_3 & V_178 ) ==
V_179 ) {
F_22 ( & V_2 -> V_79 [ V_69 - 1 ] -> V_19 ,
L_22 ) ;
return V_54 ;
}
V_54 = F_69 ( V_2 , V_69 , V_180 ) ;
if ( V_54 )
return V_54 ;
for ( V_176 = 0 ; ; V_176 += V_181 ) {
V_54 = F_28 ( V_2 , V_69 , & V_3 , & V_177 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( ( V_3 & V_178 ) ==
V_180 )
break;
if ( V_176 >= V_182 )
break;
F_66 ( V_181 ) ;
}
if ( V_176 >= V_182 )
F_71 ( & V_2 -> V_79 [ V_69 - 1 ] -> V_19 ,
L_23 , V_176 ) ;
return F_69 ( V_2 , V_69 , V_179 ) ;
}
static int F_72 ( struct V_1 * V_2 , int V_69 , int V_183 )
{
struct V_77 * V_78 = V_2 -> V_79 [ V_69 - 1 ] ;
struct V_7 * V_4 = V_2 -> V_4 ;
int V_54 = 0 ;
if ( V_78 -> V_184 && V_183 )
F_73 ( V_78 -> V_184 , V_185 ) ;
if ( ! V_2 -> error ) {
if ( F_2 ( V_2 -> V_4 ) )
V_54 = F_70 ( V_2 , V_69 ) ;
else
V_54 = F_18 ( V_4 , V_69 ,
V_186 ) ;
}
if ( V_54 && V_54 != - V_113 )
F_30 ( & V_78 -> V_19 , L_24 , V_54 ) ;
return V_54 ;
}
static void F_74 ( struct V_1 * V_2 , int V_69 )
{
F_22 ( & V_2 -> V_79 [ V_69 - 1 ] -> V_19 , L_25 ) ;
F_72 ( V_2 , V_69 , 1 ) ;
F_42 ( V_69 , V_2 -> V_187 ) ;
F_32 ( V_2 ) ;
}
int F_75 ( struct V_7 * V_11 )
{
struct V_1 * V_2 ;
struct V_119 * V_120 ;
if ( ! V_11 -> V_22 )
return - V_66 ;
V_2 = F_3 ( V_11 -> V_22 ) ;
V_120 = F_34 ( V_2 -> V_114 ) ;
F_76 ( V_120 ) ;
F_42 ( V_11 -> V_126 , V_2 -> V_188 ) ;
F_74 ( V_2 , V_11 -> V_126 ) ;
F_77 ( V_120 ) ;
return 0 ;
}
static void F_78 ( struct V_1 * V_2 , enum V_189 type )
{
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_190 * V_156 ;
int V_54 ;
int V_69 ;
int V_80 ;
bool V_191 = false ;
unsigned V_192 ;
if ( type == V_193 )
goto V_194;
if ( type == V_195 )
goto V_196;
if ( type != V_197 ) {
if ( V_4 -> V_22 && F_2 ( V_4 ) ) {
V_54 = F_14 ( V_4 , F_17 ( V_4 , 0 ) ,
V_198 , V_63 ,
V_4 -> V_199 - 1 , 0 , NULL , 0 ,
V_200 ) ;
if ( V_54 < 0 )
F_30 ( V_2 -> V_114 ,
L_26 ) ;
}
if ( type == V_201 ) {
unsigned V_192 = F_67 ( V_2 ) ;
F_63 ( V_2 , false ) ;
F_79 ( & V_2 -> V_202 , V_203 ) ;
F_25 ( V_101 ,
& V_2 -> V_202 ,
F_80 ( V_192 ) ) ;
F_35 (
F_34 ( V_2 -> V_114 ) ) ;
return;
} else if ( type == V_204 ) {
V_156 = F_60 ( V_4 -> V_170 ) ;
if ( V_156 -> V_157 -> V_205 ) {
V_54 = V_156 -> V_157 -> V_205 ( V_156 , V_4 ,
& V_2 -> V_142 , V_206 ) ;
if ( V_54 < 0 ) {
F_30 ( V_2 -> V_114 , L_27
L_28
L_29 ) ;
F_30 ( V_2 -> V_114 , L_30
L_31
L_32 ) ;
}
}
F_63 ( V_2 , true ) ;
} else {
F_63 ( V_2 , true ) ;
}
}
V_194:
for ( V_69 = 1 ; V_69 <= V_4 -> V_9 ; ++ V_69 ) {
struct V_77 * V_78 = V_2 -> V_79 [ V_69 - 1 ] ;
struct V_7 * V_11 = V_78 -> V_184 ;
T_1 V_3 , V_177 ;
V_3 = V_177 = 0 ;
V_80 = F_28 ( V_2 , V_69 , & V_3 , & V_177 ) ;
if ( V_11 || ( V_3 & V_207 ) )
F_22 ( & V_78 -> V_19 , L_33 ,
V_3 , V_177 ) ;
if ( ( V_3 & V_208 ) && (
type != V_197 ||
! ( V_3 & V_207 ) ||
! V_11 ||
V_11 -> V_87 == V_185 ) ) {
V_3 &= ~ V_208 ;
if ( ! F_2 ( V_4 ) )
F_18 ( V_4 , V_69 ,
V_186 ) ;
}
if ( V_177 & V_209 ) {
V_191 = true ;
F_18 ( V_2 -> V_4 , V_69 ,
V_210 ) ;
}
if ( V_177 & V_211 ) {
V_191 = true ;
F_18 ( V_2 -> V_4 , V_69 ,
V_212 ) ;
}
if ( V_177 & V_213 ) {
V_191 = true ;
F_18 ( V_2 -> V_4 , V_69 ,
V_214 ) ;
}
if ( ( V_177 & V_215 ) &&
F_2 ( V_2 -> V_4 ) ) {
V_191 = true ;
F_18 ( V_2 -> V_4 , V_69 ,
V_216 ) ;
}
if ( ! ( V_3 & V_207 ) ||
( V_177 & V_209 ) )
F_54 ( V_69 , V_2 -> V_188 ) ;
if ( ! V_11 || V_11 -> V_87 == V_185 ) {
if ( V_11 || ( V_3 & V_207 ) ||
( V_3 & V_217 ) )
F_42 ( V_69 , V_2 -> V_187 ) ;
} else if ( V_3 & V_208 ) {
bool V_218 = ( V_3 &
V_178 ) ==
V_219 ;
if ( V_177 || ( F_2 ( V_2 -> V_4 ) &&
V_218 ) )
F_42 ( V_69 , V_2 -> V_187 ) ;
} else if ( V_11 -> V_220 ) {
#ifdef F_81
V_11 -> V_221 = 1 ;
#endif
if ( F_65 ( V_69 , V_2 -> V_162 ) )
F_42 ( V_69 , V_2 -> V_187 ) ;
} else {
F_73 ( V_11 , V_185 ) ;
F_42 ( V_69 , V_2 -> V_187 ) ;
}
}
if ( V_191 ) {
V_192 = V_222 ;
if ( type == V_193 ) {
F_79 ( & V_2 -> V_202 , V_223 ) ;
F_25 ( V_101 ,
& V_2 -> V_202 ,
F_80 ( V_192 ) ) ;
return;
} else {
F_66 ( V_192 ) ;
}
}
V_196:
V_2 -> V_89 = 0 ;
V_80 = F_44 ( V_2 -> V_128 , V_206 ) ;
if ( V_80 < 0 )
F_30 ( V_2 -> V_114 , L_34 , V_80 ) ;
if ( V_2 -> V_224 && V_100 )
F_25 ( V_101 ,
& V_2 -> V_84 , V_102 ) ;
F_32 ( V_2 ) ;
if ( type <= V_195 )
F_38 ( F_34 ( V_2 -> V_114 ) ) ;
}
static void V_203 ( struct V_82 * V_225 )
{
struct V_1 * V_2 = F_24 ( V_225 , struct V_1 , V_202 . V_83 ) ;
F_78 ( V_2 , V_193 ) ;
}
static void V_223 ( struct V_82 * V_225 )
{
struct V_1 * V_2 = F_24 ( V_225 , struct V_1 , V_202 . V_83 ) ;
F_78 ( V_2 , V_195 ) ;
}
static void F_82 ( struct V_1 * V_2 , enum V_226 type )
{
struct V_7 * V_4 = V_2 -> V_4 ;
int V_53 ;
F_83 ( & V_2 -> V_202 ) ;
V_2 -> V_89 = 1 ;
if ( type != V_227 ) {
for ( V_53 = 0 ; V_53 < V_4 -> V_9 ; ++ V_53 ) {
if ( V_2 -> V_79 [ V_53 ] -> V_184 )
F_84 ( & V_2 -> V_79 [ V_53 ] -> V_184 ) ;
}
}
F_85 ( V_2 -> V_128 ) ;
if ( V_2 -> V_224 )
F_83 ( & V_2 -> V_84 ) ;
if ( V_2 -> V_142 . V_2 )
F_86 ( & V_2 -> V_142 . V_146 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < V_2 -> V_4 -> V_9 ; ++ V_53 )
F_88 ( & V_2 -> V_79 [ V_53 ] -> V_19 ) ;
}
static int F_89 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = F_4 ( V_120 ) ;
F_82 ( V_2 , V_228 ) ;
V_2 -> V_229 = 1 ;
F_87 ( V_2 ) ;
return 0 ;
}
static int F_90 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = F_4 ( V_120 ) ;
V_2 -> V_229 = 0 ;
F_87 ( V_2 ) ;
F_78 ( V_2 , V_230 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_231 * V_232 )
{
struct V_190 * V_156 ;
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_233 * V_234 = V_2 -> V_114 ;
T_1 V_235 , V_236 ;
T_1 V_237 ;
unsigned int V_163 ;
int V_238 , V_54 , V_53 ;
char * V_239 = L_35 ;
unsigned V_240 ;
unsigned V_241 ;
unsigned V_9 ;
V_2 -> V_137 = F_56 ( sizeof( * V_2 -> V_137 ) , V_242 ) ;
if ( ! V_2 -> V_137 ) {
V_54 = - V_165 ;
goto V_243;
}
V_2 -> V_80 = F_56 ( sizeof( * V_2 -> V_80 ) , V_242 ) ;
if ( ! V_2 -> V_80 ) {
V_54 = - V_165 ;
goto V_243;
}
F_92 ( & V_2 -> V_111 ) ;
V_2 -> V_33 = F_56 ( sizeof( * V_2 -> V_33 ) , V_242 ) ;
if ( ! V_2 -> V_33 ) {
V_54 = - V_165 ;
goto V_243;
}
V_54 = F_13 ( V_4 , V_2 -> V_33 ) ;
if ( V_54 < 0 ) {
V_239 = L_36 ;
goto V_243;
} else if ( V_2 -> V_33 -> V_244 > V_245 ) {
V_239 = L_37 ;
V_54 = - V_113 ;
goto V_243;
} else if ( V_2 -> V_33 -> V_244 == 0 ) {
V_239 = L_38 ;
V_54 = - V_113 ;
goto V_243;
}
V_9 = V_2 -> V_33 -> V_244 ;
F_7 ( V_234 , L_39 , V_9 ,
( V_9 == 1 ) ? L_40 : L_41 ) ;
V_2 -> V_79 = F_93 ( V_9 * sizeof( struct V_77 * ) , V_242 ) ;
if ( ! V_2 -> V_79 ) {
V_54 = - V_165 ;
goto V_243;
}
V_237 = F_12 ( V_2 -> V_33 -> V_237 ) ;
if ( F_2 ( V_4 ) ) {
V_240 = 150 ;
V_241 = 900 ;
} else {
V_240 = 100 ;
V_241 = 500 ;
}
if ( ( V_237 & V_246 ) &&
! ( F_2 ( V_4 ) ) ) {
int V_53 ;
char V_247 [ V_245 + 1 ] ;
for ( V_53 = 0 ; V_53 < V_9 ; V_53 ++ )
V_247 [ V_53 ] = V_2 -> V_33 -> V_34 . V_248 . V_249
[ ( ( V_53 + 1 ) / 8 ) ] & ( 1 << ( ( V_53 + 1 ) % 8 ) )
? 'F' : 'R' ;
V_247 [ V_9 ] = 0 ;
F_22 ( V_234 , L_42 , V_247 ) ;
} else
F_22 ( V_234 , L_43 ) ;
switch ( V_237 & V_250 ) {
case V_251 :
F_22 ( V_234 , L_44 ) ;
break;
case V_252 :
F_22 ( V_234 , L_45 ) ;
break;
case V_253 :
case V_250 :
F_22 ( V_234 , L_46 ) ;
break;
}
switch ( V_237 & V_254 ) {
case V_255 :
F_22 ( V_234 , L_47 ) ;
break;
case V_256 :
F_22 ( V_234 , L_48 ) ;
break;
case V_257 :
case V_254 :
F_22 ( V_234 , L_49 ) ;
break;
}
F_94 ( & V_2 -> V_142 . V_148 ) ;
F_95 ( & V_2 -> V_142 . V_149 ) ;
F_96 ( & V_2 -> V_142 . V_146 , F_46 ) ;
switch ( V_4 -> V_33 . V_258 ) {
case V_259 :
break;
case V_260 :
F_22 ( V_234 , L_50 ) ;
V_2 -> V_142 . V_2 = V_4 ;
break;
case V_261 :
V_54 = F_97 ( V_4 , 0 , 1 ) ;
if ( V_54 == 0 ) {
F_22 ( V_234 , L_51 ) ;
V_2 -> V_142 . V_166 = 1 ;
} else
F_30 ( V_234 , L_52 ,
V_54 ) ;
V_2 -> V_142 . V_2 = V_4 ;
break;
case V_262 :
break;
default:
F_22 ( V_234 , L_53 ,
V_4 -> V_33 . V_258 ) ;
break;
}
switch ( V_237 & V_263 ) {
case V_264 :
if ( V_4 -> V_33 . V_258 != 0 ) {
V_2 -> V_142 . V_265 = 666 ;
F_22 ( V_234 , L_54
L_55 ,
8 , V_2 -> V_142 . V_265 ) ;
}
break;
case V_266 :
V_2 -> V_142 . V_265 = 666 * 2 ;
F_22 ( V_234 , L_54
L_55 ,
16 , V_2 -> V_142 . V_265 ) ;
break;
case V_267 :
V_2 -> V_142 . V_265 = 666 * 3 ;
F_22 ( V_234 , L_54
L_55 ,
24 , V_2 -> V_142 . V_265 ) ;
break;
case V_268 :
V_2 -> V_142 . V_265 = 666 * 4 ;
F_22 ( V_234 , L_54
L_55 ,
32 , V_2 -> V_142 . V_265 ) ;
break;
}
if ( V_237 & V_269 ) {
V_2 -> V_224 = 1 ;
F_22 ( V_234 , L_56 ) ;
}
F_22 ( V_234 , L_57 ,
V_2 -> V_33 -> V_270 * 2 ) ;
V_54 = F_98 ( V_4 , V_271 , 0 , & V_235 ) ;
if ( V_54 ) {
V_239 = L_58 ;
goto V_243;
}
V_156 = F_60 ( V_4 -> V_170 ) ;
if ( V_4 == V_4 -> V_170 -> V_272 ) {
if ( V_156 -> V_273 > 0 )
V_4 -> V_274 = V_156 -> V_273 ;
else
V_4 -> V_274 = V_241 * V_9 ;
if ( V_4 -> V_274 >= V_241 )
V_2 -> V_275 = V_241 ;
else {
V_2 -> V_275 = V_4 -> V_274 ;
V_2 -> V_276 = 1 ;
}
} else if ( ( V_235 & ( 1 << V_277 ) ) == 0 ) {
int V_278 = V_4 -> V_274 -
V_2 -> V_33 -> V_279 ;
F_22 ( V_234 , L_59 ,
V_2 -> V_33 -> V_279 ) ;
V_2 -> V_276 = 1 ;
if ( V_278 < V_9 * V_240 )
F_71 ( V_234 ,
L_60
L_61 ) ;
V_2 -> V_275 = V_240 ;
} else {
V_2 -> V_275 = V_241 ;
}
if ( V_2 -> V_275 < V_241 )
F_22 ( V_234 , L_62 ,
V_2 -> V_275 ) ;
V_54 = F_68 ( V_2 , & V_235 , & V_236 ) ;
if ( V_54 < 0 ) {
V_239 = L_58 ;
goto V_243;
}
if ( V_4 -> V_8 -> V_280 . V_17 & V_281 )
F_22 ( V_234 , L_63 ,
( V_235 & V_282 )
? L_64 : L_65 ) ;
if ( ( V_237 & V_254 ) == 0 )
F_22 ( V_234 , L_66 ,
( V_235 & V_283 ) ? L_40 : L_67 ) ;
V_163 = F_99 ( V_4 , V_232 -> V_284 ) ;
V_238 = F_100 ( V_4 , V_163 , F_101 ( V_163 ) ) ;
if ( V_238 > sizeof( * V_2 -> V_137 ) )
V_238 = sizeof( * V_2 -> V_137 ) ;
V_2 -> V_128 = F_102 ( 0 , V_242 ) ;
if ( ! V_2 -> V_128 ) {
V_54 = - V_165 ;
goto V_243;
}
F_103 ( V_2 -> V_128 , V_4 , V_163 , * V_2 -> V_137 , V_238 , F_43 ,
V_2 , V_232 -> V_285 ) ;
if ( V_2 -> V_224 && V_100 )
V_2 -> V_91 [ 0 ] = V_92 ;
F_29 ( & V_286 ) ;
for ( V_53 = 0 ; V_53 < V_9 ; V_53 ++ ) {
V_54 = F_104 ( V_2 , V_53 + 1 ) ;
if ( V_54 < 0 ) {
F_30 ( V_2 -> V_114 ,
L_68 , V_53 + 1 ) ;
break;
}
}
V_4 -> V_9 = V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_9 ; V_53 ++ ) {
struct V_77 * V_78 = V_2 -> V_79 [ V_53 ] ;
F_105 ( & V_78 -> V_19 ) ;
}
F_31 ( & V_286 ) ;
if ( V_54 < 0 )
goto V_243;
if ( V_156 -> V_157 -> V_205 ) {
V_54 = V_156 -> V_157 -> V_205 ( V_156 , V_4 ,
& V_2 -> V_142 , V_242 ) ;
if ( V_54 < 0 ) {
V_239 = L_69 ;
goto V_243;
}
}
F_106 ( V_4 , V_2 -> V_33 ) ;
F_78 ( V_2 , V_201 ) ;
return 0 ;
V_243:
F_30 ( V_234 , L_70 ,
V_239 , V_54 ) ;
return V_54 ;
}
static void V_125 ( struct V_123 * V_123 )
{
struct V_1 * V_2 = F_24 ( V_123 , struct V_1 , V_123 ) ;
F_107 ( V_2 -> V_4 ) ;
F_108 ( F_34 ( V_2 -> V_114 ) ) ;
F_52 ( V_2 ) ;
}
static void F_109 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = F_4 ( V_120 ) ;
struct V_7 * V_4 = F_110 ( V_120 ) ;
int V_69 ;
V_2 -> V_121 = 1 ;
V_2 -> error = 0 ;
F_82 ( V_2 , V_287 ) ;
F_29 ( & V_286 ) ;
F_111 ( & V_288 ) ;
V_69 = V_4 -> V_9 ;
V_4 -> V_9 = 0 ;
F_112 ( V_120 , NULL ) ;
F_113 ( & V_288 ) ;
for (; V_69 > 0 ; -- V_69 )
F_114 ( V_2 , V_69 ) ;
F_31 ( & V_286 ) ;
if ( V_2 -> V_4 -> V_12 == V_13 )
V_289 -- ;
F_115 ( V_2 -> V_128 ) ;
F_52 ( V_2 -> V_79 ) ;
F_52 ( V_2 -> V_33 ) ;
F_52 ( V_2 -> V_80 ) ;
F_52 ( V_2 -> V_137 ) ;
F_116 ( & V_120 -> V_19 , false ) ;
F_39 ( & V_2 -> V_123 , V_125 ) ;
}
static int F_117 ( struct V_119 * V_120 , const struct V_290 * V_291 )
{
struct V_292 * V_280 ;
struct V_231 * V_232 ;
struct V_7 * V_4 ;
struct V_1 * V_2 ;
V_280 = V_120 -> V_293 ;
V_4 = F_110 ( V_120 ) ;
#ifdef F_81
if ( V_4 -> V_19 . V_294 . V_295 >= 0 )
F_118 ( & V_4 -> V_19 , 0 ) ;
#endif
if ( V_4 -> V_22 ) {
F_119 ( V_4 ) ;
} else {
const struct V_154 * V_155 = F_60 ( V_4 -> V_170 ) -> V_157 ;
if ( V_155 -> V_296 && V_155 -> V_297 )
F_119 ( V_4 ) ;
}
if ( V_4 -> V_199 == V_298 ) {
F_30 ( & V_120 -> V_19 ,
L_71 ) ;
return - V_299 ;
}
#ifdef F_120
if ( V_4 -> V_22 ) {
F_71 ( & V_120 -> V_19 , L_72 ) ;
return - V_113 ;
}
#endif
if ( ( V_280 -> V_280 . V_300 != 0 ) &&
( V_280 -> V_280 . V_300 != 1 ) ) {
V_301:
F_30 ( & V_120 -> V_19 , L_73 ) ;
return - V_116 ;
}
if ( V_280 -> V_280 . V_302 != 1 )
goto V_301;
V_232 = & V_280 -> V_232 [ 0 ] . V_280 ;
if ( ! F_121 ( V_232 ) )
goto V_301;
F_7 ( & V_120 -> V_19 , L_74 ) ;
V_2 = F_93 ( sizeof( * V_2 ) , V_242 ) ;
if ( ! V_2 ) {
F_22 ( & V_120 -> V_19 , L_75 ) ;
return - V_165 ;
}
F_122 ( & V_2 -> V_123 ) ;
V_2 -> V_114 = & V_120 -> V_19 ;
V_2 -> V_4 = V_4 ;
F_79 ( & V_2 -> V_84 , F_23 ) ;
F_79 ( & V_2 -> V_202 , NULL ) ;
F_96 ( & V_2 -> V_122 , V_303 ) ;
F_123 ( V_120 ) ;
F_124 ( V_4 ) ;
F_112 ( V_120 , V_2 ) ;
V_120 -> V_304 = 1 ;
F_116 ( & V_120 -> V_19 , true ) ;
if ( V_4 -> V_12 == V_13 )
V_289 ++ ;
if ( V_291 -> V_305 & V_306 )
V_2 -> V_307 = 1 ;
if ( F_91 ( V_2 , V_232 ) >= 0 )
return 0 ;
F_109 ( V_120 ) ;
return - V_113 ;
}
static int
F_125 ( struct V_119 * V_120 , unsigned int V_308 , void * V_309 )
{
struct V_7 * V_4 = F_110 ( V_120 ) ;
struct V_1 * V_2 = F_3 ( V_4 ) ;
switch ( V_308 ) {
case V_310 : {
struct V_311 * V_312 = V_309 ;
int V_53 ;
F_111 ( & V_288 ) ;
if ( V_4 -> V_168 <= 0 )
V_312 -> V_313 = 0 ;
else {
V_312 -> V_313 = V_4 -> V_9 ;
for ( V_53 = 0 ; V_53 < V_312 -> V_313 ; V_53 ++ ) {
if ( V_2 -> V_79 [ V_53 ] -> V_184 == NULL )
V_312 -> V_112 [ V_53 ] = 0 ;
else
V_312 -> V_112 [ V_53 ] =
V_2 -> V_79 [ V_53 ] -> V_184 -> V_168 ;
}
}
F_113 ( & V_288 ) ;
return V_312 -> V_313 + 1 ;
}
default:
return - V_314 ;
}
}
static int F_126 ( struct V_7 * V_4 , unsigned V_69 ,
struct V_315 * * * V_316 )
{
struct V_1 * V_2 = F_3 ( V_4 ) ;
if ( V_4 -> V_87 == V_185 )
return - V_113 ;
if ( V_69 == 0 || V_69 > V_4 -> V_9 )
return - V_66 ;
* V_316 = & ( V_2 -> V_79 [ V_69 - 1 ] -> V_317 ) ;
return 0 ;
}
int F_127 ( struct V_7 * V_4 , unsigned V_69 ,
struct V_315 * V_318 )
{
int V_319 ;
struct V_315 * * V_320 ;
V_319 = F_126 ( V_4 , V_69 , & V_320 ) ;
if ( V_319 )
return V_319 ;
if ( * V_320 )
return - V_321 ;
* V_320 = V_318 ;
return V_319 ;
}
int F_128 ( struct V_7 * V_4 , unsigned V_69 ,
struct V_315 * V_318 )
{
int V_319 ;
struct V_315 * * V_320 ;
V_319 = F_126 ( V_4 , V_69 , & V_320 ) ;
if ( V_319 )
return V_319 ;
if ( * V_320 != V_318 )
return - V_131 ;
* V_320 = NULL ;
return V_319 ;
}
void F_129 ( struct V_7 * V_4 , struct V_315 * V_318 )
{
struct V_1 * V_2 = F_3 ( V_4 ) ;
int V_322 ;
for ( V_322 = 0 ; V_322 < V_4 -> V_9 ; V_322 ++ ) {
if ( V_2 -> V_79 [ V_322 ] -> V_317 == V_318 )
V_2 -> V_79 [ V_322 ] -> V_317 = NULL ;
}
}
bool F_130 ( struct V_7 * V_11 )
{
struct V_1 * V_2 ;
if ( V_11 -> V_87 == V_185 || ! V_11 -> V_22 )
return false ;
V_2 = F_3 ( V_11 -> V_22 ) ;
return ! ! V_2 -> V_79 [ V_11 -> V_126 - 1 ] -> V_317 ;
}
static void F_131 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_3 ( V_11 ) ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_11 -> V_9 ; ++ V_53 ) {
if ( V_2 -> V_79 [ V_53 ] -> V_184 )
F_131 ( V_2 -> V_79 [ V_53 ] -> V_184 ) ;
}
if ( V_11 -> V_87 == V_323 )
V_11 -> V_324 -= V_325 ;
V_11 -> V_87 = V_185 ;
}
void F_73 ( struct V_7 * V_11 ,
enum V_326 V_327 )
{
unsigned long V_147 ;
int V_328 = - 1 ;
F_47 ( & V_288 , V_147 ) ;
if ( V_11 -> V_87 == V_185 )
;
else if ( V_327 != V_185 ) {
if ( V_11 -> V_22 ) {
if ( V_11 -> V_87 == V_323
|| V_327 == V_323 )
;
else if ( V_327 == V_88 )
V_328 = ( V_11 -> V_329 &
V_330 ) ? 0 :
V_11 -> V_8 -> V_280 . V_17 &
V_331 ;
else
V_328 = 0 ;
}
if ( V_11 -> V_87 == V_323 &&
V_327 != V_323 )
V_11 -> V_324 -= V_325 ;
else if ( V_327 == V_323 &&
V_11 -> V_87 != V_323 )
V_11 -> V_324 += V_325 ;
V_11 -> V_87 = V_327 ;
} else
F_131 ( V_11 ) ;
F_51 ( & V_288 , V_147 ) ;
if ( V_328 >= 0 )
F_132 ( & V_11 -> V_19 , V_328 ) ;
}
static void F_133 ( struct V_7 * V_11 )
{
int V_168 ;
struct V_332 * V_170 = V_11 -> V_170 ;
F_29 ( & V_170 -> V_333 ) ;
if ( V_11 -> V_334 ) {
V_168 = V_11 -> V_126 + 1 ;
F_134 ( F_65 ( V_168 , V_170 -> V_335 . V_336 ) ) ;
} else {
V_168 = F_135 ( V_170 -> V_335 . V_336 , 128 ,
V_170 -> V_337 ) ;
if ( V_168 >= 128 )
V_168 = F_135 ( V_170 -> V_335 . V_336 ,
128 , 1 ) ;
V_170 -> V_337 = ( V_168 >= 127 ? 1 : V_168 + 1 ) ;
}
if ( V_168 < 128 ) {
F_42 ( V_168 , V_170 -> V_335 . V_336 ) ;
V_11 -> V_168 = V_168 ;
}
F_31 ( & V_170 -> V_333 ) ;
}
static void F_136 ( struct V_7 * V_11 )
{
if ( V_11 -> V_168 > 0 ) {
F_54 ( V_11 -> V_168 , V_11 -> V_170 -> V_335 . V_336 ) ;
V_11 -> V_168 = - 1 ;
}
}
static void F_137 ( struct V_7 * V_11 , int V_168 )
{
if ( ! V_11 -> V_334 )
V_11 -> V_168 = V_168 ;
}
static void F_138 ( struct V_7 * V_11 )
{
struct V_190 * V_156 = F_60 ( V_11 -> V_170 ) ;
if ( V_156 -> V_157 -> V_338 && V_11 -> V_22 )
V_156 -> V_157 -> V_338 ( V_156 , V_11 ) ;
}
static void F_139 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_3 ( V_11 ) ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_11 -> V_9 ; V_53 ++ ) {
if ( V_2 -> V_79 [ V_53 ] -> V_184 )
F_84 ( & V_2 -> V_79 [ V_53 ] -> V_184 ) ;
}
}
void F_84 ( struct V_7 * * V_339 )
{
struct V_77 * V_78 = NULL ;
struct V_7 * V_11 = * V_339 ;
struct V_1 * V_2 = NULL ;
int V_69 = 1 ;
F_73 ( V_11 , V_185 ) ;
F_7 ( & V_11 -> V_19 , L_76 ,
V_11 -> V_168 ) ;
F_140 ( V_11 ) ;
F_139 ( V_11 ) ;
F_22 ( & V_11 -> V_19 , L_77 ) ;
F_141 ( V_11 , 0 ) ;
F_142 ( V_11 ) ;
if ( V_11 -> V_22 ) {
V_69 = V_11 -> V_126 ;
V_2 = F_3 ( V_11 -> V_22 ) ;
V_78 = V_2 -> V_79 [ V_69 - 1 ] ;
F_143 ( & V_11 -> V_19 . V_340 , L_78 ) ;
F_143 ( & V_78 -> V_19 . V_340 , L_79 ) ;
if ( ! F_144 ( V_69 , V_2 -> V_341 ) )
F_145 ( & V_78 -> V_19 ) ;
}
F_146 ( & V_11 -> V_342 ) ;
F_147 ( V_11 ) ;
F_148 ( & V_11 -> V_19 ) ;
F_136 ( V_11 ) ;
F_111 ( & V_288 ) ;
* V_339 = NULL ;
F_113 ( & V_288 ) ;
if ( V_78 && F_149 ( V_69 , V_2 -> V_341 ) )
F_105 ( & V_78 -> V_19 ) ;
F_138 ( V_11 ) ;
F_150 ( & V_11 -> V_19 ) ;
}
static void F_151 ( struct V_7 * V_11 , char * V_291 , char * string )
{
if ( ! string )
return;
F_7 ( & V_11 -> V_19 , L_80 , V_291 , string ) ;
}
static void F_152 ( struct V_7 * V_11 )
{
F_7 ( & V_11 -> V_19 , L_81 ,
F_12 ( V_11 -> V_33 . V_343 ) ,
F_12 ( V_11 -> V_33 . V_344 ) ) ;
F_7 ( & V_11 -> V_19 ,
L_82 ,
V_11 -> V_33 . V_345 ,
V_11 -> V_33 . V_346 ,
V_11 -> V_33 . V_347 ) ;
F_151 ( V_11 , L_83 , V_11 -> V_348 ) ;
F_151 ( V_11 , L_84 , V_11 -> V_349 ) ;
F_151 ( V_11 , L_85 , V_11 -> V_350 ) ;
}
static inline void F_152 ( struct V_7 * V_11 ) { }
static int F_153 ( struct V_7 * V_11 )
{
int V_351 = 0 ;
#ifdef F_154
if ( ! V_11 -> V_170 -> V_352
&& V_11 -> V_353
&& V_11 -> V_22 == V_11 -> V_170 -> V_272 ) {
struct V_354 * V_280 = NULL ;
struct V_332 * V_170 = V_11 -> V_170 ;
if ( F_155 ( V_11 -> V_355 [ 0 ] ,
F_12 ( V_11 -> V_353 [ 0 ] . V_280 . V_356 ) ,
V_357 , ( void * * ) & V_280 ) == 0 ) {
if ( V_280 -> V_17 & V_358 ) {
unsigned V_69 = V_11 -> V_126 ;
F_7 ( & V_11 -> V_19 ,
L_86 ,
( V_69 == V_170 -> V_359 )
? L_40 : L_87 ) ;
if ( V_69 == V_170 -> V_359 )
V_170 -> V_360 = 1 ;
V_351 = F_14 ( V_11 ,
F_17 ( V_11 , 0 ) ,
V_71 , 0 ,
V_170 -> V_360
? V_361
: V_362 ,
0 , NULL , 0 , V_200 ) ;
if ( V_351 < 0 ) {
F_7 ( & V_11 -> V_19 ,
L_88 ,
V_351 ) ;
V_170 -> V_360 = 0 ;
}
}
}
}
#endif
return V_351 ;
}
static int F_156 ( struct V_7 * V_11 )
{
int V_351 ;
struct V_190 * V_156 = F_60 ( V_11 -> V_170 ) ;
if ( V_11 -> V_353 == NULL ) {
V_351 = F_157 ( V_11 ) ;
if ( V_351 < 0 ) {
if ( V_351 != - V_113 )
F_30 ( & V_11 -> V_19 , L_89 ,
V_351 ) ;
return V_351 ;
}
}
V_11 -> V_348 = F_158 ( V_11 , V_11 -> V_33 . V_346 ) ;
V_11 -> V_349 = F_158 ( V_11 ,
V_11 -> V_33 . V_345 ) ;
V_11 -> V_350 = F_158 ( V_11 , V_11 -> V_33 . V_347 ) ;
V_351 = F_153 ( V_11 ) ;
if ( V_351 < 0 )
return V_351 ;
if ( F_159 ( V_363 ) && V_156 -> V_364 &&
! F_160 ( V_11 ) ) {
if ( F_159 ( F_154 ) && ( V_11 -> V_170 -> V_360
|| V_11 -> V_170 -> V_352 ) ) {
V_351 = F_161 ( V_11 , V_365 ) ;
if ( V_351 < 0 )
F_22 ( & V_11 -> V_19 , L_90 , V_351 ) ;
}
return - V_366 ;
}
F_162 ( V_11 ) ;
return 0 ;
}
static void F_163 ( struct V_7 * V_11 )
{
struct V_7 * V_4 = V_11 -> V_22 ;
struct V_1 * V_2 ;
T_2 V_112 = V_11 -> V_126 ;
T_1 V_237 ;
bool V_367 = true ;
if ( ! V_4 )
return;
V_2 = F_3 ( V_11 -> V_22 ) ;
V_237 = F_12 ( V_2 -> V_33 -> V_237 ) ;
if ( ! ( V_237 & V_246 ) )
return;
if ( F_2 ( V_4 ) ) {
if ( F_12 ( V_2 -> V_33 -> V_34 . V_35 . V_249 )
& ( 1 << V_112 ) )
V_367 = false ;
} else {
if ( V_2 -> V_33 -> V_34 . V_248 . V_249 [ V_112 / 8 ] & ( 1 << ( V_112 % 8 ) ) )
V_367 = false ;
}
if ( V_367 )
V_11 -> V_367 = V_368 ;
else
V_11 -> V_367 = V_369 ;
switch ( V_2 -> V_79 [ V_11 -> V_126 - 1 ] -> V_370 ) {
case V_371 :
V_11 -> V_367 = V_368 ;
break;
case V_372 :
V_11 -> V_367 = V_369 ;
break;
default:
break;
}
}
int F_164 ( struct V_7 * V_11 )
{
int V_351 ;
if ( V_11 -> V_22 ) {
F_165 ( & V_11 -> V_19 , 0 ) ;
}
F_166 ( & V_11 -> V_19 ) ;
F_167 ( & V_11 -> V_19 ) ;
F_168 ( & V_11 -> V_19 ) ;
F_169 ( & V_11 -> V_19 ) ;
F_170 ( V_11 ) ;
V_351 = F_156 ( V_11 ) ;
if ( V_351 < 0 )
goto V_243;
F_22 ( & V_11 -> V_19 , L_91 ,
V_11 -> V_168 , V_11 -> V_170 -> V_373 ,
( ( ( V_11 -> V_170 -> V_373 - 1 ) * 128 ) + ( V_11 -> V_168 - 1 ) ) ) ;
V_11 -> V_19 . V_374 = F_171 ( V_375 ,
( ( ( V_11 -> V_170 -> V_373 - 1 ) * 128 ) + ( V_11 -> V_168 - 1 ) ) ) ;
F_152 ( V_11 ) ;
if ( V_11 -> V_350 )
F_172 ( V_11 -> V_350 , strlen ( V_11 -> V_350 ) ) ;
if ( V_11 -> V_348 )
F_172 ( V_11 -> V_348 , strlen ( V_11 -> V_348 ) ) ;
if ( V_11 -> V_349 )
F_172 ( V_11 -> V_349 ,
strlen ( V_11 -> V_349 ) ) ;
F_173 ( & V_11 -> V_19 ) ;
if ( V_11 -> V_22 )
F_163 ( V_11 ) ;
V_351 = F_174 ( & V_11 -> V_19 ) ;
if ( V_351 ) {
F_30 ( & V_11 -> V_19 , L_92 , V_351 ) ;
goto V_243;
}
if ( V_11 -> V_22 ) {
struct V_1 * V_2 = F_3 ( V_11 -> V_22 ) ;
int V_69 = V_11 -> V_126 ;
struct V_77 * V_78 = V_2 -> V_79 [ V_69 - 1 ] ;
V_351 = F_175 ( & V_11 -> V_19 . V_340 ,
& V_78 -> V_19 . V_340 , L_78 ) ;
if ( V_351 )
goto V_243;
V_351 = F_175 ( & V_78 -> V_19 . V_340 ,
& V_11 -> V_19 . V_340 , L_79 ) ;
if ( V_351 ) {
F_143 ( & V_11 -> V_19 . V_340 , L_78 ) ;
goto V_243;
}
if ( ! F_144 ( V_69 , V_2 -> V_341 ) )
F_145 ( & V_78 -> V_19 ) ;
}
( void ) F_176 ( & V_11 -> V_19 , & V_11 -> V_342 , V_11 ) ;
F_177 ( V_11 ) ;
F_178 ( & V_11 -> V_19 ) ;
return V_351 ;
V_243:
F_73 ( V_11 , V_185 ) ;
F_179 ( & V_11 -> V_19 ) ;
F_180 ( & V_11 -> V_19 ) ;
return V_351 ;
}
int F_181 ( struct V_7 * V_376 )
{
F_140 ( V_376 ) ;
if ( V_376 -> V_377 == 0 )
goto V_378;
V_376 -> V_377 = 0 ;
F_182 ( V_376 , - 1 ) ;
V_378:
F_147 ( V_376 ) ;
return 0 ;
}
int F_183 ( struct V_7 * V_376 )
{
int V_379 = 0 , V_380 ;
F_140 ( V_376 ) ;
if ( V_376 -> V_377 == 1 )
goto V_381;
V_379 = F_184 ( V_376 ) ;
if ( V_379 < 0 ) {
F_30 ( & V_376 -> V_19 ,
L_93 , V_379 ) ;
goto V_382;
}
if ( V_376 -> V_334 ) {
V_379 = F_185 ( V_376 , sizeof( V_376 -> V_33 ) ) ;
if ( V_379 < 0 ) {
F_30 ( & V_376 -> V_19 , L_94
L_95 , V_379 ) ;
goto V_383;
}
}
V_376 -> V_377 = 1 ;
V_380 = F_186 ( V_376 ) ;
if ( V_380 >= 0 ) {
V_379 = F_182 ( V_376 , V_380 ) ;
if ( V_379 ) {
F_30 ( & V_376 -> V_19 ,
L_96 , V_380 , V_379 ) ;
}
}
F_7 ( & V_376 -> V_19 , L_97 ) ;
V_383:
F_187 ( V_376 ) ;
V_382:
V_381:
F_147 ( V_376 ) ;
return V_379 ;
}
static unsigned F_188 ( struct V_1 * V_2 )
{
struct V_190 * V_156 ;
if ( V_2 -> V_4 -> V_22 != NULL )
return 0 ;
V_156 = F_24 ( V_2 -> V_4 -> V_170 , struct V_190 , V_384 ) ;
return V_156 -> V_385 ;
}
static bool F_189 ( struct V_7 * V_11 , int V_386 )
{
if ( V_11 -> V_12 == V_49 )
return false ;
return F_190 ( V_386 ) ;
}
static bool F_191 ( struct V_1 * V_2 , int V_69 ,
T_1 V_3 )
{
T_1 V_387 ;
if ( ! F_2 ( V_2 -> V_4 ) )
return false ;
if ( F_65 ( V_69 , V_2 -> V_388 ) )
return true ;
V_387 = V_3 & V_178 ;
return V_387 == V_389
|| V_387 == V_390 ;
}
static int F_192 ( struct V_1 * V_2 , int V_69 ,
struct V_7 * V_11 , unsigned int V_192 , bool V_391 )
{
int V_392 , V_54 ;
T_1 V_3 ;
T_1 V_177 ;
for ( V_392 = 0 ;
V_392 < V_393 ;
V_392 += V_192 ) {
F_66 ( V_192 ) ;
V_54 = F_28 ( V_2 , V_69 , & V_3 , & V_177 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( ! ( V_3 & V_394 ) )
break;
if ( V_392 >= 2 * V_395 )
V_192 = V_396 ;
F_22 ( & V_2 -> V_79 [ V_69 - 1 ] -> V_19 ,
L_98 ,
V_391 ? L_99 : L_40 , V_192 ) ;
}
if ( ( V_3 & V_394 ) )
return - V_321 ;
if ( F_191 ( V_2 , V_69 , V_3 ) )
return - V_397 ;
if ( ! ( V_3 & V_207 ) )
return - V_397 ;
if ( ! F_2 ( V_2 -> V_4 ) &&
( V_177 & V_209 ) )
return - V_397 ;
if ( ! ( V_3 & V_208 ) )
return - V_321 ;
if ( ! V_11 )
return 0 ;
if ( F_188 ( V_2 ) )
V_11 -> V_12 = V_398 ;
else if ( F_2 ( V_2 -> V_4 ) )
V_11 -> V_12 = V_49 ;
else if ( V_3 & V_5 )
V_11 -> V_12 = V_13 ;
else if ( V_3 & V_6 )
V_11 -> V_12 = V_399 ;
else
V_11 -> V_12 = V_400 ;
return 0 ;
}
static void F_193 ( struct V_1 * V_2 , int V_69 ,
struct V_7 * V_11 , int * V_80 )
{
switch ( * V_80 ) {
case 0 :
F_66 ( 10 + 40 ) ;
if ( V_11 ) {
struct V_190 * V_156 = F_60 ( V_11 -> V_170 ) ;
F_137 ( V_11 , 0 ) ;
if ( V_156 -> V_157 -> V_401 )
V_156 -> V_157 -> V_401 ( V_156 , V_11 ) ;
}
case - V_397 :
case - V_113 :
F_18 ( V_2 -> V_4 ,
V_69 , V_214 ) ;
if ( F_2 ( V_2 -> V_4 ) ) {
F_18 ( V_2 -> V_4 , V_69 ,
V_216 ) ;
F_18 ( V_2 -> V_4 , V_69 ,
V_402 ) ;
F_18 ( V_2 -> V_4 , V_69 ,
V_210 ) ;
}
if ( V_11 )
F_73 ( V_11 , * V_80
? V_185
: V_403 ) ;
break;
}
}
static int F_194 ( struct V_1 * V_2 , int V_69 ,
struct V_7 * V_11 , unsigned int V_192 , bool V_391 )
{
int V_53 , V_80 ;
T_1 V_177 , V_3 ;
struct V_77 * V_78 = V_2 -> V_79 [ V_69 - 1 ] ;
if ( ! F_2 ( V_2 -> V_4 ) ) {
if ( V_391 ) {
F_30 ( V_2 -> V_114 , L_100
L_101 ) ;
return - V_66 ;
}
F_195 ( & V_404 ) ;
} else if ( ! V_391 ) {
V_80 = F_28 ( V_2 , V_69 ,
& V_3 , & V_177 ) ;
if ( V_80 < 0 )
goto V_405;
if ( F_191 ( V_2 , V_69 , V_3 ) )
V_391 = true ;
}
F_54 ( V_69 , V_2 -> V_388 ) ;
for ( V_53 = 0 ; V_53 < V_406 ; V_53 ++ ) {
V_80 = F_19 ( V_2 -> V_4 , V_69 , ( V_391 ?
V_407 :
V_408 ) ) ;
if ( V_80 == - V_113 ) {
;
} else if ( V_80 ) {
F_30 ( & V_78 -> V_19 ,
L_102 ,
V_391 ? L_99 : L_40 , V_80 ) ;
} else {
V_80 = F_192 ( V_2 , V_69 , V_11 , V_192 ,
V_391 ) ;
if ( V_80 && V_80 != - V_397 && V_80 != - V_113 )
F_22 ( V_2 -> V_114 ,
L_103 ,
V_80 ) ;
}
if ( V_80 == 0 || V_80 == - V_397 || V_80 == - V_113 ) {
F_193 ( V_2 , V_69 , V_11 , & V_80 ) ;
if ( ! F_2 ( V_2 -> V_4 ) )
goto V_405;
if ( F_28 ( V_2 , V_69 ,
& V_3 , & V_177 ) < 0 )
goto V_405;
if ( ! F_191 ( V_2 , V_69 ,
V_3 ) )
goto V_405;
if ( ! V_391 ) {
F_22 ( & V_78 -> V_19 ,
L_104 ) ;
V_391 = true ;
}
}
F_22 ( & V_78 -> V_19 ,
L_105 ,
V_391 ? L_99 : L_40 ) ;
V_192 = V_396 ;
}
F_30 ( & V_78 -> V_19 , L_106 ) ;
V_405:
if ( ! F_2 ( V_2 -> V_4 ) )
F_196 ( & V_404 ) ;
return V_80 ;
}
static int F_197 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_54 = 0 ;
if ( F_2 ( V_2 -> V_4 ) ) {
if ( V_3 & V_409 )
V_54 = 1 ;
} else {
if ( V_3 & V_410 )
V_54 = 1 ;
}
return V_54 ;
}
static void F_198 ( struct V_77 * V_78 )
__acquires( &port_dev->status_lock
static void F_199 ( struct V_77 * V_78 )
__releases( &port_dev->status_lock
static int F_200 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_54 = 0 ;
if ( F_2 ( V_2 -> V_4 ) ) {
if ( ( V_3 & V_178 )
== V_411 )
V_54 = 1 ;
} else {
if ( V_3 & V_412 )
V_54 = 1 ;
}
return V_54 ;
}
static int F_201 ( struct V_7 * V_11 ,
struct V_1 * V_2 , int V_69 ,
int V_80 , T_1 V_177 , T_1 V_3 )
{
struct V_77 * V_78 = V_2 -> V_79 [ V_69 - 1 ] ;
int V_413 = 3 ;
V_386:
if ( V_80 == 0 && V_11 -> V_221
&& F_191 ( V_2 , V_69 , V_3 ) ) {
;
}
else if ( V_80 || F_200 ( V_2 , V_3 ) ||
! F_197 ( V_2 , V_3 ) ) {
if ( V_80 >= 0 )
V_80 = - V_113 ;
} else if ( ! ( V_3 & V_207 ) ) {
if ( V_413 -- ) {
F_202 ( 200 , 300 ) ;
V_80 = F_28 ( V_2 , V_69 , & V_3 ,
& V_177 ) ;
goto V_386;
}
V_80 = - V_113 ;
}
else if ( ! ( V_3 & V_208 ) && ! V_11 -> V_221 ) {
if ( V_11 -> V_220 )
V_11 -> V_221 = 1 ;
else
V_80 = - V_113 ;
}
if ( V_80 ) {
F_22 ( & V_78 -> V_19 , L_107 ,
V_177 , V_3 , V_80 ) ;
} else if ( V_11 -> V_221 ) {
if ( V_177 & V_209 )
F_18 ( V_2 -> V_4 , V_69 ,
V_210 ) ;
if ( V_177 & V_211 )
F_18 ( V_2 -> V_4 , V_69 ,
V_212 ) ;
}
return V_80 ;
}
int F_203 ( struct V_7 * V_11 )
{
struct V_190 * V_156 = F_60 ( V_11 -> V_170 ) ;
if ( ! F_204 ( V_156 -> V_384 . V_272 ) ||
! F_204 ( V_11 ) )
return 0 ;
if ( ! V_11 -> V_8 )
return 0 ;
return F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_68 , V_271 ,
V_414 , 0 , NULL , 0 ,
V_200 ) ;
}
void F_205 ( struct V_7 * V_11 )
{
struct V_190 * V_156 = F_60 ( V_11 -> V_170 ) ;
if ( ! F_204 ( V_156 -> V_384 . V_272 ) ||
! F_204 ( V_11 ) )
return;
if ( ! V_11 -> V_8 )
return;
F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_71 , V_271 ,
V_414 , 0 , NULL , 0 ,
V_200 ) ;
}
static int F_206 ( struct V_7 * V_11 )
{
if ( V_11 -> V_12 < V_49 )
return F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_71 , V_271 ,
V_415 , 0 , NULL , 0 ,
V_200 ) ;
else
return F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_71 , V_416 ,
V_417 ,
V_418 |
V_419 ,
NULL , 0 , V_200 ) ;
}
static int F_207 ( struct V_7 * V_11 )
{
if ( V_11 -> V_12 < V_49 )
return F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_68 , V_271 ,
V_415 , 0 , NULL , 0 ,
V_200 ) ;
else
return F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_68 , V_416 ,
V_417 , 0 , NULL , 0 ,
V_200 ) ;
}
static unsigned F_208 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_3 ( V_11 ) ;
return V_11 -> V_420 +
( V_2 ? V_2 -> F_208 : 0 ) ;
}
int F_161 ( struct V_7 * V_11 , T_3 V_421 )
{
struct V_1 * V_2 = F_3 ( V_11 -> V_22 ) ;
struct V_77 * V_78 = V_2 -> V_79 [ V_11 -> V_126 - 1 ] ;
int V_69 = V_11 -> V_126 ;
int V_80 ;
bool V_422 = true ;
F_198 ( V_78 ) ;
if ( V_11 -> V_420 ) {
V_80 = F_206 ( V_11 ) ;
if ( V_80 ) {
F_22 ( & V_11 -> V_19 , L_108 ,
V_80 ) ;
if ( F_209 ( V_421 ) )
goto V_423;
}
}
if ( V_11 -> V_424 == 1 )
F_210 ( V_11 , 0 ) ;
if ( F_203 ( V_11 ) ) {
F_30 ( & V_11 -> V_19 , L_109 ) ;
V_80 = - V_165 ;
if ( F_209 ( V_421 ) )
goto V_425;
}
if ( F_211 ( V_11 ) ) {
F_30 ( & V_11 -> V_19 , L_110 ) ;
V_80 = - V_165 ;
if ( F_209 ( V_421 ) )
goto V_426;
}
if ( F_2 ( V_2 -> V_4 ) )
V_80 = F_69 ( V_2 , V_69 , V_411 ) ;
else if ( F_209 ( V_421 ) || F_208 ( V_11 ) > 0 )
V_80 = F_19 ( V_2 -> V_4 , V_69 ,
V_427 ) ;
else {
V_422 = false ;
V_80 = 0 ;
}
if ( V_80 ) {
F_22 ( & V_78 -> V_19 , L_111 , V_80 ) ;
F_212 ( V_11 ) ;
V_426:
F_205 ( V_11 ) ;
V_425:
if ( V_11 -> V_428 == 1 )
F_210 ( V_11 , 1 ) ;
if ( V_11 -> V_420 )
( void ) F_207 ( V_11 ) ;
V_423:
if ( ! F_209 ( V_421 ) )
V_80 = 0 ;
} else {
F_22 ( & V_11 -> V_19 , L_112 ,
( F_209 ( V_421 ) ? L_113 : L_40 ) ,
V_11 -> V_420 ) ;
if ( V_422 ) {
V_11 -> F_200 = 1 ;
F_66 ( 10 ) ;
}
F_73 ( V_11 , V_323 ) ;
}
if ( V_80 == 0 && ! V_11 -> V_420 && V_11 -> V_220
&& F_149 ( V_69 , V_2 -> V_341 ) )
F_213 ( & V_78 -> V_19 ) ;
F_177 ( V_2 -> V_4 ) ;
F_199 ( V_78 ) ;
return V_80 ;
}
static int F_214 ( struct V_7 * V_11 )
{
int V_80 = 0 ;
T_1 V_429 = 0 ;
F_22 ( & V_11 -> V_19 , L_114 ,
V_11 -> V_221 ? L_115 : L_116 ) ;
F_73 ( V_11 , V_11 -> V_8
? V_88
: V_430 ) ;
if ( V_11 -> V_221 ) {
V_431:
if ( V_11 -> V_329 & V_432 )
V_80 = - V_113 ;
else
V_80 = F_215 ( V_11 ) ;
}
if ( V_80 == 0 ) {
V_429 = 0 ;
V_80 = F_98 ( V_11 , V_271 , 0 , & V_429 ) ;
if ( V_80 && ! V_11 -> V_221 && V_11 -> V_220 ) {
F_22 ( & V_11 -> V_19 , L_117 ) ;
V_11 -> V_221 = 1 ;
goto V_431;
}
}
if ( V_80 ) {
F_22 ( & V_11 -> V_19 , L_118 ,
V_80 ) ;
} else if ( V_11 -> V_8 && ! V_11 -> V_221 ) {
if ( V_11 -> V_12 < V_49 ) {
if ( V_429 & ( 1 << V_415 ) )
V_80 = F_207 ( V_11 ) ;
} else {
V_80 = F_98 ( V_11 , V_416 , 0 ,
& V_429 ) ;
if ( ! V_80 && V_429 & ( V_433
| V_434 ) )
V_80 = F_207 ( V_11 ) ;
}
if ( V_80 )
F_22 ( & V_11 -> V_19 ,
L_119 ,
V_80 ) ;
V_80 = 0 ;
}
return V_80 ;
}
static int F_216 ( struct V_7 * V_11 ,
struct V_1 * V_2 , int * V_69 ,
T_1 * V_177 , T_1 * V_3 )
{
int V_80 = 0 , V_435 = 0 ;
while ( V_435 < 2000 ) {
if ( V_80 || * V_3 & V_207 )
break;
F_66 ( 20 ) ;
V_435 += 20 ;
V_80 = F_28 ( V_2 , * V_69 , V_3 , V_177 ) ;
}
return V_80 ;
}
int F_217 ( struct V_7 * V_11 , T_3 V_421 )
{
struct V_1 * V_2 = F_3 ( V_11 -> V_22 ) ;
struct V_77 * V_78 = V_2 -> V_79 [ V_11 -> V_126 - 1 ] ;
int V_69 = V_11 -> V_126 ;
int V_80 ;
T_1 V_177 , V_3 ;
if ( ! F_144 ( V_69 , V_2 -> V_341 ) ) {
V_80 = F_145 ( & V_78 -> V_19 ) ;
if ( V_80 < 0 ) {
F_22 ( & V_11 -> V_19 , L_120 ,
V_80 ) ;
return V_80 ;
}
}
F_198 ( V_78 ) ;
V_80 = F_28 ( V_2 , V_69 , & V_3 , & V_177 ) ;
if ( V_80 == 0 && ! F_200 ( V_2 , V_3 ) )
goto V_436;
if ( F_2 ( V_2 -> V_4 ) )
V_80 = F_69 ( V_2 , V_69 , V_219 ) ;
else
V_80 = F_18 ( V_2 -> V_4 ,
V_69 , V_427 ) ;
if ( V_80 ) {
F_22 ( & V_78 -> V_19 , L_121 , V_80 ) ;
} else {
F_22 ( & V_11 -> V_19 , L_122 ,
( F_209 ( V_421 ) ? L_113 : L_40 ) ) ;
F_66 ( V_437 ) ;
V_80 = F_28 ( V_2 , V_69 , & V_3 , & V_177 ) ;
F_66 ( 10 ) ;
}
V_436:
if ( V_80 == 0 ) {
V_11 -> F_200 = 0 ;
if ( F_2 ( V_2 -> V_4 ) ) {
if ( V_177 & V_438 )
F_18 ( V_2 -> V_4 , V_69 ,
V_402 ) ;
} else {
if ( V_177 & V_439 )
F_18 ( V_2 -> V_4 , V_69 ,
V_440 ) ;
}
}
if ( V_11 -> V_220 && F_2 ( V_2 -> V_4 ) )
V_80 = F_216 ( V_11 , V_2 , & V_69 , & V_177 ,
& V_3 ) ;
V_80 = F_201 ( V_11 ,
V_2 , V_69 , V_80 , V_177 , V_3 ) ;
if ( V_80 == 0 )
V_80 = F_214 ( V_11 ) ;
if ( V_80 < 0 ) {
F_22 ( & V_11 -> V_19 , L_121 , V_80 ) ;
F_74 ( V_2 , V_69 ) ;
} else {
if ( V_11 -> V_428 == 1 )
F_210 ( V_11 , 1 ) ;
F_205 ( V_11 ) ;
F_212 ( V_11 ) ;
}
F_199 ( V_78 ) ;
return V_80 ;
}
int F_218 ( struct V_7 * V_11 )
{
int V_80 = 0 ;
F_140 ( V_11 ) ;
if ( V_11 -> V_87 == V_323 ) {
F_22 ( & V_11 -> V_19 , L_122 , L_123 ) ;
V_80 = F_184 ( V_11 ) ;
if ( V_80 == 0 ) {
F_187 ( V_11 ) ;
}
}
F_147 ( V_11 ) ;
return V_80 ;
}
static int F_219 ( struct V_1 * V_2 , unsigned int V_112 ,
T_1 V_3 , T_1 V_177 )
__must_hold( &port_dev->status_lock
static int F_220 ( struct V_1 * V_2 )
{
int V_69 ;
for ( V_69 = 1 ; V_69 <= V_2 -> V_4 -> V_9 ; ++ V_69 ) {
T_1 V_3 , V_177 ;
int V_80 ;
V_80 = F_28 ( V_2 , V_69 , & V_3 , & V_177 ) ;
if ( ! V_80 && V_177 )
return 1 ;
}
return 0 ;
}
static int F_221 ( struct V_119 * V_120 , T_3 V_421 )
{
struct V_1 * V_2 = F_4 ( V_120 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
unsigned V_69 ;
int V_80 ;
V_2 -> F_208 = 0 ;
for ( V_69 = 1 ; V_69 <= V_4 -> V_9 ; V_69 ++ ) {
struct V_77 * V_78 = V_2 -> V_79 [ V_69 - 1 ] ;
struct V_7 * V_11 = V_78 -> V_184 ;
if ( V_11 && V_11 -> V_441 ) {
F_71 ( & V_78 -> V_19 , L_124 ,
F_222 ( & V_11 -> V_19 ) ) ;
if ( F_209 ( V_421 ) )
return - V_321 ;
}
if ( V_11 )
V_2 -> F_208 +=
F_208 ( V_11 ) ;
}
if ( V_4 -> V_420 && V_2 -> V_307 ) {
if ( F_220 ( V_2 ) ) {
if ( F_209 ( V_421 ) )
return - V_321 ;
F_223 ( & V_4 -> V_19 , 2000 ) ;
}
}
if ( F_2 ( V_4 ) && V_4 -> V_420 ) {
for ( V_69 = 1 ; V_69 <= V_4 -> V_9 ; V_69 ++ ) {
V_80 = F_19 ( V_4 ,
V_69 |
V_442 |
V_443 |
V_444 ,
V_445 ) ;
}
}
F_22 ( & V_120 -> V_19 , L_114 , V_115 ) ;
F_82 ( V_2 , V_227 ) ;
return 0 ;
}
static int F_224 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = F_4 ( V_120 ) ;
F_22 ( & V_120 -> V_19 , L_114 , V_115 ) ;
F_78 ( V_2 , V_197 ) ;
return 0 ;
}
static int F_225 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = F_4 ( V_120 ) ;
F_22 ( & V_120 -> V_19 , L_114 , V_115 ) ;
F_78 ( V_2 , V_204 ) ;
return 0 ;
}
void F_226 ( struct V_7 * V_446 )
{
F_71 ( & V_446 -> V_19 , L_125 ) ;
V_446 -> V_221 = 1 ;
}
static int F_227 ( struct V_7 * V_11 , enum V_447 V_87 )
{
struct V_448 * V_449 ;
unsigned long long V_450 ;
unsigned long long V_451 ;
unsigned long long V_452 ;
unsigned long long V_453 ;
int V_54 ;
if ( V_11 -> V_87 != V_88 )
return 0 ;
V_450 = F_228 ( V_11 -> V_50 . V_43 , 1000 ) ;
V_451 = F_228 ( V_11 -> V_50 . V_40 , 1000 ) ;
V_452 = F_228 ( V_11 -> V_51 . V_43 , 1000 ) ;
V_453 = F_228 ( V_11 -> V_51 . V_40 , 1000 ) ;
if ( ( V_87 == V_454 &&
( V_450 > V_455 ||
V_451 > V_455 ) ) ||
( V_87 == V_456 &&
( V_452 > V_457 ||
V_453 > V_457 ) ) ) {
F_22 ( & V_11 -> V_19 , L_126 ,
V_458 [ V_87 ] , V_450 , V_451 ) ;
return - V_66 ;
}
if ( V_450 > V_455 )
V_450 = V_455 ;
if ( V_451 > V_455 )
V_451 = V_455 ;
if ( V_452 > V_457 )
V_452 = V_457 ;
if ( V_453 > V_457 )
V_453 = V_457 ;
V_449 = F_56 ( sizeof *( V_449 ) , V_206 ) ;
if ( ! V_449 )
return - V_165 ;
V_449 -> V_450 = V_450 ;
V_449 -> V_451 = V_451 ;
V_449 -> V_452 = F_229 ( V_452 ) ;
V_449 -> V_453 = F_229 ( V_453 ) ;
V_54 = F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_459 ,
V_271 ,
0 , 0 ,
V_449 , sizeof *( V_449 ) ,
V_200 ) ;
F_52 ( V_449 ) ;
return V_54 ;
}
static int F_230 ( struct V_7 * V_11 ,
enum V_447 V_87 , bool V_460 )
{
int V_54 ;
int V_67 ;
switch ( V_87 ) {
case V_454 :
V_67 = V_461 ;
break;
case V_456 :
V_67 = V_462 ;
break;
default:
F_71 ( & V_11 -> V_19 , L_127 ,
V_115 , V_460 ? L_128 : L_129 ) ;
return - V_66 ;
}
if ( V_11 -> V_87 != V_88 ) {
F_22 ( & V_11 -> V_19 , L_130
L_131 ,
V_115 , V_460 ? L_128 : L_129 ,
V_458 [ V_87 ] ) ;
return 0 ;
}
if ( V_460 ) {
V_54 = F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_71 ,
V_271 ,
V_67 ,
0 , NULL , 0 ,
V_200 ) ;
} else {
V_54 = F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_68 ,
V_271 ,
V_67 ,
0 , NULL , 0 ,
V_200 ) ;
}
if ( V_54 < 0 ) {
F_71 ( & V_11 -> V_19 , L_132 ,
V_460 ? L_133 : L_134 ,
V_458 [ V_87 ] ) ;
return - V_321 ;
}
return 0 ;
}
static int F_231 ( struct V_7 * V_11 ,
enum V_447 V_87 , int V_463 )
{
int V_54 ;
int V_67 ;
switch ( V_87 ) {
case V_454 :
V_67 = V_464 ;
break;
case V_456 :
V_67 = V_465 ;
break;
default:
F_71 ( & V_11 -> V_19 , L_135 ,
V_115 ) ;
return - V_66 ;
}
if ( V_87 == V_454 && V_463 > V_466 &&
V_463 != V_467 ) {
F_71 ( & V_11 -> V_19 , L_136
L_137 ,
V_458 [ V_87 ] , V_463 ) ;
return - V_66 ;
}
V_54 = F_19 ( V_11 -> V_22 ,
F_232 ( V_463 ) | V_11 -> V_126 ,
V_67 ) ;
if ( V_54 < 0 ) {
F_71 ( & V_11 -> V_19 , L_138
L_139 , V_458 [ V_87 ] ,
V_463 , V_54 ) ;
return - V_321 ;
}
if ( V_87 == V_454 )
V_11 -> V_50 . V_463 = V_463 ;
else
V_11 -> V_51 . V_463 = V_463 ;
return 0 ;
}
static void F_233 ( struct V_190 * V_156 , struct V_7 * V_11 ,
enum V_447 V_87 )
{
int V_463 , V_54 ;
T_4 V_468 = V_11 -> V_14 -> V_18 -> V_20 ;
T_5 V_469 = V_11 -> V_14 -> V_18 -> V_21 ;
if ( ( V_87 == V_454 && V_468 == 0 ) ||
( V_87 == V_456 && V_469 == 0 ) )
return;
V_54 = F_227 ( V_11 , V_87 ) ;
if ( V_54 < 0 ) {
F_71 ( & V_11 -> V_19 , L_140 ,
V_458 [ V_87 ] ) ;
return;
}
V_463 = V_156 -> V_157 -> V_470 ( V_156 , V_11 , V_87 ) ;
if ( V_463 == 0 )
return;
if ( V_463 < 0 ) {
F_71 ( & V_11 -> V_19 , L_141
L_142 , V_458 [ V_87 ] ,
V_463 ) ;
return;
}
if ( F_231 ( V_11 , V_87 , V_463 ) )
V_156 -> V_157 -> V_471 ( V_156 , V_11 , V_87 ) ;
else if ( V_11 -> V_8 )
F_230 ( V_11 , V_87 , true ) ;
}
static int F_234 ( struct V_190 * V_156 , struct V_7 * V_11 ,
enum V_447 V_87 )
{
switch ( V_87 ) {
case V_454 :
case V_456 :
break;
default:
F_71 ( & V_11 -> V_19 , L_143 ,
V_115 ) ;
return - V_66 ;
}
if ( F_231 ( V_11 , V_87 , 0 ) )
return - V_321 ;
F_230 ( V_11 , V_87 , false ) ;
if ( V_156 -> V_157 -> V_471 ( V_156 , V_11 , V_87 ) )
F_71 ( & V_11 -> V_19 , L_144
L_145 ,
V_458 [ V_87 ] ) ;
return 0 ;
}
int F_235 ( struct V_7 * V_11 )
{
struct V_190 * V_156 ;
if ( ! V_11 || ! V_11 -> V_22 ||
V_11 -> V_12 != V_49 ||
! V_11 -> V_23 ||
V_11 -> V_87 < V_403 )
return 0 ;
V_156 = F_60 ( V_11 -> V_170 ) ;
if ( ! V_156 || ! V_156 -> V_157 -> V_471 )
return 0 ;
V_11 -> V_472 ++ ;
if ( ( V_11 -> V_50 . V_463 == 0 && V_11 -> V_51 . V_463 == 0 ) )
return 0 ;
if ( F_234 ( V_156 , V_11 , V_454 ) )
goto V_473;
if ( F_234 ( V_156 , V_11 , V_456 ) )
goto V_473;
return 0 ;
V_473:
F_236 ( V_11 ) ;
return - V_321 ;
}
int F_211 ( struct V_7 * V_11 )
{
struct V_190 * V_156 = F_60 ( V_11 -> V_170 ) ;
int V_54 ;
if ( ! V_156 )
return - V_66 ;
F_29 ( V_156 -> V_474 ) ;
V_54 = F_235 ( V_11 ) ;
F_31 ( V_156 -> V_474 ) ;
return V_54 ;
}
void F_236 ( struct V_7 * V_11 )
{
struct V_190 * V_156 ;
if ( ! V_11 || ! V_11 -> V_22 ||
V_11 -> V_12 != V_49 ||
! V_11 -> V_23 ||
V_11 -> V_87 < V_403 )
return;
V_11 -> V_472 -- ;
V_156 = F_60 ( V_11 -> V_170 ) ;
if ( ! V_156 || ! V_156 -> V_157 -> V_470 ||
! V_156 -> V_157 -> V_471 )
return;
if ( V_11 -> V_472 > 0 )
return;
F_233 ( V_156 , V_11 , V_454 ) ;
F_233 ( V_156 , V_11 , V_456 ) ;
}
void F_212 ( struct V_7 * V_11 )
{
struct V_190 * V_156 = F_60 ( V_11 -> V_170 ) ;
if ( ! V_156 )
return;
F_29 ( V_156 -> V_474 ) ;
F_236 ( V_11 ) ;
F_31 ( V_156 -> V_474 ) ;
}
int F_235 ( struct V_7 * V_11 )
{
return 0 ;
}
void F_236 ( struct V_7 * V_11 ) { }
int F_211 ( struct V_7 * V_11 )
{
return 0 ;
}
void F_212 ( struct V_7 * V_11 ) { }
int F_203 ( struct V_7 * V_11 )
{
return 0 ;
}
void F_205 ( struct V_7 * V_11 ) { }
static int F_219 ( struct V_1 * V_2 , unsigned int V_112 ,
T_1 V_3 , T_1 V_177 )
{
return 0 ;
}
int F_237 ( struct V_1 * V_2 , int V_69 , bool V_475 )
{
int V_54 ;
T_1 V_177 , V_3 ;
unsigned V_476 = 0xffff ;
int V_176 , V_477 = 0 ;
struct V_77 * V_78 = V_2 -> V_79 [ V_69 - 1 ] ;
for ( V_176 = 0 ; ; V_176 += V_181 ) {
V_54 = F_28 ( V_2 , V_69 , & V_3 , & V_177 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( ! ( V_177 & V_209 ) &&
( V_3 & V_207 ) == V_476 ) {
if ( ! V_475 ||
( V_476 == V_207 ) )
V_477 += V_181 ;
if ( V_477 >= V_222 )
break;
} else {
V_477 = 0 ;
V_476 = V_3 & V_207 ;
}
if ( V_177 & V_209 ) {
F_18 ( V_2 -> V_4 , V_69 ,
V_210 ) ;
}
if ( V_176 >= V_182 )
break;
F_66 ( V_181 ) ;
}
F_22 ( & V_78 -> V_19 , L_146 ,
V_176 , V_477 , V_3 ) ;
if ( V_477 < V_222 )
return - V_104 ;
return V_3 ;
}
void F_238 ( struct V_7 * V_11 )
{
F_239 ( V_11 , 0 + V_62 , true ) ;
F_239 ( V_11 , 0 + V_478 , true ) ;
F_240 ( V_11 , & V_11 -> V_342 , true ) ;
}
static int F_241 ( struct V_7 * V_11 , int V_168 )
{
int V_479 ;
struct V_190 * V_156 = F_60 ( V_11 -> V_170 ) ;
if ( ! V_156 -> V_157 -> V_480 && V_168 <= 1 )
return - V_66 ;
if ( V_11 -> V_87 == V_430 )
return 0 ;
if ( V_11 -> V_87 != V_403 )
return - V_66 ;
if ( V_156 -> V_157 -> V_480 )
V_479 = V_156 -> V_157 -> V_480 ( V_156 , V_11 ) ;
else
V_479 = F_14 ( V_11 , F_242 () ,
V_481 , 0 , V_168 , 0 ,
NULL , 0 , V_200 ) ;
if ( V_479 == 0 ) {
F_137 ( V_11 , V_168 ) ;
F_73 ( V_11 , V_430 ) ;
F_238 ( V_11 ) ;
}
return V_479 ;
}
static void F_243 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_3 ( V_11 -> V_22 ) ;
int V_370 = V_482 ;
if ( ! V_11 -> V_428 )
return;
if ( V_2 )
V_370 = V_2 -> V_79 [ V_11 -> V_126 - 1 ] -> V_370 ;
if ( ( V_11 -> V_14 -> V_15 -> V_17 & F_244 ( V_483 ) ) ||
V_370 == V_372 ) {
V_11 -> V_484 = 1 ;
F_210 ( V_11 , 1 ) ;
}
}
static int F_245 ( struct V_7 * V_11 )
{
struct V_190 * V_156 = F_60 ( V_11 -> V_170 ) ;
if ( ! V_156 -> V_157 -> V_485 )
return 0 ;
if ( V_11 -> V_87 == V_430 )
return 0 ;
if ( V_11 -> V_87 != V_403 )
return - V_66 ;
return V_156 -> V_157 -> V_485 ( V_156 , V_11 ) ;
}
static int
F_246 ( struct V_1 * V_2 , struct V_7 * V_11 , int V_69 ,
int V_486 )
{
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_190 * V_156 = F_60 ( V_4 -> V_170 ) ;
int V_53 , V_487 , V_479 ;
unsigned V_192 = V_395 ;
enum V_488 V_489 = V_11 -> V_12 ;
const char * V_12 ;
int V_168 = V_11 -> V_168 ;
if ( ! V_4 -> V_22 ) {
V_192 = V_490 ;
if ( V_69 == V_4 -> V_170 -> V_359 )
V_4 -> V_170 -> V_360 = 0 ;
}
if ( V_489 == V_399 )
V_192 = V_396 ;
F_29 ( & V_4 -> V_170 -> V_333 ) ;
V_479 = F_194 ( V_2 , V_69 , V_11 , V_192 , false ) ;
if ( V_479 < 0 )
goto V_243;
V_479 = - V_113 ;
if ( V_489 != V_491 && V_489 != V_11 -> V_12 ) {
F_22 ( & V_11 -> V_19 , L_147 ) ;
goto V_243;
}
V_489 = V_11 -> V_12 ;
switch ( V_11 -> V_12 ) {
case V_49 :
case V_398 :
V_11 -> V_342 . V_280 . V_492 = F_229 ( 512 ) ;
break;
case V_13 :
V_11 -> V_342 . V_280 . V_492 = F_229 ( 64 ) ;
break;
case V_400 :
V_11 -> V_342 . V_280 . V_492 = F_229 ( 64 ) ;
break;
case V_399 :
V_11 -> V_342 . V_280 . V_492 = F_229 ( 8 ) ;
break;
default:
goto V_243;
}
if ( V_11 -> V_12 == V_398 )
V_12 = L_148 ;
else
V_12 = F_247 ( V_11 -> V_12 ) ;
if ( V_11 -> V_12 != V_49 )
F_7 ( & V_11 -> V_19 ,
L_149 ,
( V_11 -> V_353 ) ? L_150 : L_151 , V_12 ,
V_168 , V_11 -> V_170 -> V_493 -> V_157 -> V_494 ) ;
if ( V_4 -> V_142 ) {
V_11 -> V_142 = V_4 -> V_142 ;
V_11 -> V_167 = V_4 -> V_167 ;
} else if ( V_11 -> V_12 != V_13
&& V_4 -> V_12 == V_13 ) {
if ( ! V_2 -> V_142 . V_2 ) {
F_30 ( & V_11 -> V_19 , L_152 ) ;
V_479 = - V_66 ;
goto V_243;
}
V_11 -> V_142 = & V_2 -> V_142 ;
V_11 -> V_167 = V_69 ;
}
for ( V_53 = 0 ; V_53 < V_495 ; ( ++ V_53 , F_66 ( 100 ) ) ) {
bool V_496 = false ;
if ( F_189 ( V_11 , V_486 ) ) {
struct V_497 * V_498 ;
int V_499 = 0 ;
V_496 = true ;
V_479 = F_245 ( V_11 ) ;
if ( V_479 < 0 ) {
F_30 ( & V_11 -> V_19 ,
L_153 ,
V_479 ) ;
goto V_243;
}
#define F_248 64
V_498 = F_56 ( F_248 , V_206 ) ;
if ( ! V_498 ) {
V_479 = - V_165 ;
continue;
}
for ( V_487 = 0 ; V_487 < 3 ; ++ V_487 ) {
V_498 -> V_500 = 0 ;
V_499 = F_14 ( V_11 , F_249 () ,
V_61 , V_62 ,
V_501 << 8 , 0 ,
V_498 , F_248 ,
V_502 ) ;
switch ( V_498 -> V_500 ) {
case 8 : case 16 : case 32 : case 64 : case 255 :
if ( V_498 -> V_503 ==
V_501 ) {
V_499 = 0 ;
break;
}
default:
if ( V_499 == 0 )
V_499 = - V_504 ;
break;
}
if ( V_499 == 0 )
break;
}
V_11 -> V_33 . V_500 =
V_498 -> V_500 ;
F_52 ( V_498 ) ;
V_479 = F_194 ( V_2 , V_69 , V_11 , V_192 , false ) ;
if ( V_479 < 0 )
goto V_243;
if ( V_489 != V_11 -> V_12 ) {
F_22 ( & V_11 -> V_19 ,
L_147 ) ;
V_479 = - V_113 ;
goto V_243;
}
if ( V_499 ) {
if ( V_499 != - V_113 )
F_30 ( & V_11 -> V_19 , L_154 ,
V_499 ) ;
V_479 = - V_505 ;
continue;
}
#undef F_248
}
if ( V_11 -> V_334 == 0 ) {
for ( V_487 = 0 ; V_487 < V_506 ; ++ V_487 ) {
V_479 = F_241 ( V_11 , V_168 ) ;
if ( V_479 >= 0 )
break;
F_66 ( 200 ) ;
}
if ( V_479 < 0 ) {
if ( V_479 != - V_113 )
F_30 ( & V_11 -> V_19 , L_155 ,
V_168 , V_479 ) ;
goto V_243;
}
if ( V_11 -> V_12 == V_49 ) {
V_168 = V_11 -> V_168 ;
F_7 ( & V_11 -> V_19 ,
L_156 ,
( V_11 -> V_353 ) ? L_150 : L_151 ,
V_168 , V_11 -> V_170 -> V_493 -> V_157 -> V_494 ) ;
}
F_66 ( 10 ) ;
if ( V_496 )
break;
}
V_479 = F_185 ( V_11 , 8 ) ;
if ( V_479 < 8 ) {
if ( V_479 != - V_113 )
F_30 ( & V_11 -> V_19 ,
L_157 ,
V_479 ) ;
if ( V_479 >= 0 )
V_479 = - V_505 ;
} else {
V_479 = 0 ;
break;
}
}
if ( V_479 )
goto V_243;
if ( ( V_11 -> V_12 == V_49 ) &&
( F_12 ( V_11 -> V_33 . V_507 ) < 0x0300 ) ) {
F_30 ( & V_11 -> V_19 , L_158
L_159 ) ;
F_194 ( V_2 , V_69 , V_11 ,
V_508 , true ) ;
V_479 = - V_66 ;
goto V_243;
}
if ( V_11 -> V_33 . V_500 == 0xff ||
V_11 -> V_12 == V_49 )
V_53 = 512 ;
else
V_53 = V_11 -> V_33 . V_500 ;
if ( F_250 ( & V_11 -> V_342 . V_280 ) != V_53 ) {
if ( V_11 -> V_12 == V_399 ||
! ( V_53 == 8 || V_53 == 16 || V_53 == 32 || V_53 == 64 ) ) {
F_30 ( & V_11 -> V_19 , L_160 , V_53 ) ;
V_479 = - V_505 ;
goto V_243;
}
if ( V_11 -> V_12 == V_400 )
F_22 ( & V_11 -> V_19 , L_161 , V_53 ) ;
else
F_71 ( & V_11 -> V_19 , L_162 , V_53 ) ;
V_11 -> V_342 . V_280 . V_492 = F_229 ( V_53 ) ;
F_238 ( V_11 ) ;
}
V_479 = F_185 ( V_11 , V_509 ) ;
if ( V_479 < ( signed ) sizeof( V_11 -> V_33 ) ) {
if ( V_479 != - V_113 )
F_30 ( & V_11 -> V_19 , L_163 ,
V_479 ) ;
if ( V_479 >= 0 )
V_479 = - V_510 ;
goto V_243;
}
if ( V_11 -> V_334 == 0 && F_12 ( V_11 -> V_33 . V_507 ) >= 0x0201 ) {
V_479 = F_251 ( V_11 ) ;
if ( ! V_479 ) {
V_11 -> V_23 = F_5 ( V_11 ) ;
F_11 ( V_11 ) ;
}
}
V_479 = 0 ;
if ( V_156 -> V_157 -> V_511 )
V_156 -> V_157 -> V_511 ( V_156 , V_11 ) ;
F_243 ( V_11 ) ;
V_243:
if ( V_479 ) {
F_72 ( V_2 , V_69 , 0 ) ;
F_137 ( V_11 , V_168 ) ;
}
F_31 ( & V_4 -> V_170 -> V_333 ) ;
return V_479 ;
}
static void
F_252 ( struct V_1 * V_2 , struct V_7 * V_11 , int V_69 )
{
struct V_512 * V_513 ;
int V_80 ;
if ( V_11 -> V_329 & V_514 )
return;
V_513 = F_56 ( sizeof *V_513 , V_242 ) ;
if ( V_513 == NULL )
return;
V_80 = F_253 ( V_11 , V_515 , 0 ,
V_513 , sizeof *V_513 ) ;
if ( V_80 == sizeof *V_513 ) {
F_7 ( & V_11 -> V_19 , L_164
L_165 ) ;
if ( V_2 -> V_224 ) {
V_2 -> V_91 [ V_69 - 1 ] = V_94 ;
F_25 ( V_101 ,
& V_2 -> V_84 , 0 ) ;
}
}
F_52 ( V_513 ) ;
}
static unsigned
F_254 ( struct V_1 * V_2 )
{
struct V_7 * V_4 = V_2 -> V_4 ;
int V_278 ;
int V_69 ;
if ( ! V_2 -> V_276 )
return 0 ;
V_278 = V_4 -> V_274 - V_2 -> V_33 -> V_279 ;
for ( V_69 = 1 ; V_69 <= V_4 -> V_9 ; ++ V_69 ) {
struct V_77 * V_78 = V_2 -> V_79 [ V_69 - 1 ] ;
struct V_7 * V_11 = V_78 -> V_184 ;
unsigned V_240 ;
int V_516 ;
if ( ! V_11 )
continue;
if ( F_2 ( V_11 ) )
V_240 = 150 ;
else
V_240 = 100 ;
if ( V_11 -> V_8 )
V_516 = F_255 ( V_11 , V_11 -> V_8 ) ;
else if ( V_69 != V_11 -> V_170 -> V_359 || V_4 -> V_22 )
V_516 = V_240 ;
else
V_516 = 8 ;
if ( V_516 > V_2 -> V_275 )
F_71 ( & V_78 -> V_19 , L_166 ,
V_516 , V_2 -> V_275 ) ;
V_278 -= V_516 ;
}
if ( V_278 < 0 ) {
F_71 ( V_2 -> V_114 , L_167 ,
- V_278 ) ;
V_278 = 0 ;
}
return V_278 ;
}
static void F_256 ( struct V_1 * V_2 , int V_69 , T_1 V_3 ,
T_1 V_177 )
{
int V_80 , V_53 ;
unsigned V_240 ;
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_190 * V_156 = F_60 ( V_4 -> V_170 ) ;
struct V_77 * V_78 = V_2 -> V_79 [ V_69 - 1 ] ;
struct V_7 * V_11 = V_78 -> V_184 ;
static int V_517 = - 1 ;
if ( V_11 ) {
if ( V_156 -> V_518 && ! V_4 -> V_22 )
F_257 ( V_156 -> V_518 , V_11 -> V_12 ) ;
F_84 ( & V_78 -> V_184 ) ;
}
if ( ! ( V_3 & V_207 ) ||
( V_177 & V_209 ) )
F_54 ( V_69 , V_2 -> V_188 ) ;
if ( V_177 & ( V_209 |
V_211 ) ) {
V_80 = F_258 ( V_2 , V_69 ) ;
if ( V_80 < 0 ) {
if ( V_80 != - V_113 &&
V_69 != V_517 &&
F_259 () )
F_30 ( & V_78 -> V_19 , L_168 ) ;
V_3 &= ~ V_207 ;
V_517 = V_69 ;
} else {
V_3 = V_80 ;
}
}
if ( ! ( V_3 & V_207 ) ||
F_65 ( V_69 , V_2 -> V_188 ) ) {
if ( F_64 ( V_2 )
&& ! F_197 ( V_2 , V_3 )
&& ! V_78 -> V_317 )
F_19 ( V_4 , V_69 , V_161 ) ;
if ( V_3 & V_208 )
goto V_405;
return;
}
if ( F_2 ( V_2 -> V_4 ) )
V_240 = 150 ;
else
V_240 = 100 ;
V_80 = 0 ;
for ( V_53 = 0 ; V_53 < V_519 ; V_53 ++ ) {
V_11 = F_260 ( V_4 , V_4 -> V_170 , V_69 ) ;
if ( ! V_11 ) {
F_30 ( & V_78 -> V_19 ,
L_169 ) ;
goto V_405;
}
F_73 ( V_11 , V_520 ) ;
V_11 -> V_274 = V_2 -> V_275 ;
V_11 -> V_199 = V_4 -> V_199 + 1 ;
V_11 -> V_334 = F_188 ( V_2 ) ;
if ( F_2 ( V_2 -> V_4 ) )
V_11 -> V_12 = V_49 ;
else
V_11 -> V_12 = V_491 ;
F_133 ( V_11 ) ;
if ( V_11 -> V_168 <= 0 ) {
V_80 = - V_397 ;
goto V_521;
}
F_198 ( V_78 ) ;
V_80 = F_246 ( V_2 , V_11 , V_69 , V_53 ) ;
F_199 ( V_78 ) ;
if ( V_80 < 0 )
goto V_521;
F_261 ( V_11 ) ;
if ( V_11 -> V_329 & V_522 )
F_66 ( 1000 ) ;
if ( V_11 -> V_33 . V_523 == V_524
&& V_11 -> V_274 <= V_240 ) {
T_1 V_525 ;
V_80 = F_98 ( V_11 , V_271 , 0 ,
& V_525 ) ;
if ( V_80 ) {
F_22 ( & V_11 -> V_19 , L_170 , V_80 ) ;
goto V_526;
}
if ( ( V_525 & ( 1 << V_277 ) ) == 0 ) {
F_30 ( & V_11 -> V_19 ,
L_171
L_172 ) ;
if ( V_2 -> V_224 ) {
V_2 -> V_91 [ V_69 - 1 ] =
V_96 ;
F_25 (
V_101 ,
& V_2 -> V_84 , 0 ) ;
}
V_80 = - V_397 ;
goto V_526;
}
}
if ( F_12 ( V_11 -> V_33 . V_507 ) >= 0x0200
&& V_11 -> V_12 == V_400
&& V_289 != 0 )
F_252 ( V_2 , V_11 , V_69 ) ;
V_80 = 0 ;
F_29 ( & V_286 ) ;
F_111 ( & V_288 ) ;
if ( V_4 -> V_87 == V_185 )
V_80 = - V_397 ;
else
V_78 -> V_184 = V_11 ;
F_113 ( & V_288 ) ;
F_31 ( & V_286 ) ;
if ( ! V_80 ) {
V_80 = F_164 ( V_11 ) ;
if ( V_80 ) {
F_29 ( & V_286 ) ;
F_111 ( & V_288 ) ;
V_78 -> V_184 = NULL ;
F_113 ( & V_288 ) ;
F_31 ( & V_286 ) ;
} else {
if ( V_156 -> V_518 && ! V_4 -> V_22 )
F_262 ( V_156 -> V_518 ,
V_11 -> V_12 ) ;
}
}
if ( V_80 )
goto V_526;
V_80 = F_254 ( V_2 ) ;
if ( V_80 )
F_22 ( V_2 -> V_114 , L_173 , V_80 ) ;
return;
V_526:
F_72 ( V_2 , V_69 , 1 ) ;
V_521:
F_238 ( V_11 ) ;
F_136 ( V_11 ) ;
F_138 ( V_11 ) ;
F_107 ( V_11 ) ;
if ( ( V_80 == - V_397 ) || ( V_80 == - V_366 ) )
break;
}
if ( V_2 -> V_4 -> V_22 ||
! V_156 -> V_157 -> V_527 ||
! ( V_156 -> V_157 -> V_527 ) ( V_156 , V_69 ) ) {
if ( V_80 != - V_397 && V_80 != - V_113 )
F_30 ( & V_78 -> V_19 ,
L_174 ) ;
}
V_405:
F_72 ( V_2 , V_69 , 1 ) ;
if ( V_156 -> V_157 -> V_528 && ! V_2 -> V_4 -> V_22 )
V_156 -> V_157 -> V_528 ( V_156 , V_69 ) ;
}
static void F_263 ( struct V_1 * V_2 , int V_69 ,
T_1 V_3 , T_1 V_177 )
__must_hold( &port_dev->status_lock
static void F_264 ( struct V_1 * V_2 , int V_69 )
__must_hold( &port_dev->status_lock
static void V_303 ( struct V_82 * V_83 )
{
struct V_7 * V_4 ;
struct V_119 * V_120 ;
struct V_1 * V_2 ;
struct V_233 * V_234 ;
T_1 V_235 ;
T_1 V_236 ;
int V_53 , V_54 ;
V_2 = F_24 ( V_83 , struct V_1 , V_122 ) ;
V_4 = V_2 -> V_4 ;
V_234 = V_2 -> V_114 ;
V_120 = F_34 ( V_234 ) ;
F_22 ( V_234 , L_175 ,
V_4 -> V_87 , V_4 -> V_9 ,
( T_1 ) V_2 -> V_187 [ 0 ] ,
( T_1 ) V_2 -> V_138 [ 0 ] ) ;
F_140 ( V_4 ) ;
if ( F_265 ( V_2 -> V_121 ) )
goto V_529;
if ( V_4 -> V_87 == V_185 ) {
V_2 -> error = - V_113 ;
F_82 ( V_2 , V_287 ) ;
goto V_529;
}
V_54 = F_76 ( V_120 ) ;
if ( V_54 ) {
F_22 ( V_234 , L_176 , V_54 ) ;
goto V_529;
}
if ( V_2 -> V_89 )
goto V_530;
if ( V_2 -> error ) {
F_22 ( V_234 , L_177 , V_2 -> error ) ;
V_54 = F_266 ( V_4 ) ;
if ( V_54 ) {
F_22 ( V_234 , L_178 , V_54 ) ;
goto V_530;
}
V_2 -> V_134 = 0 ;
V_2 -> error = 0 ;
}
for ( V_53 = 1 ; V_53 <= V_4 -> V_9 ; V_53 ++ ) {
struct V_77 * V_78 = V_2 -> V_79 [ V_53 - 1 ] ;
if ( F_65 ( V_53 , V_2 -> V_138 )
|| F_65 ( V_53 , V_2 -> V_187 )
|| F_65 ( V_53 , V_2 -> V_127 ) ) {
F_167 ( & V_78 -> V_19 ) ;
F_88 ( & V_78 -> V_19 ) ;
F_198 ( V_78 ) ;
F_264 ( V_2 , V_53 ) ;
F_199 ( V_78 ) ;
F_213 ( & V_78 -> V_19 ) ;
}
}
if ( F_149 ( 0 , V_2 -> V_138 ) == 0 )
;
else if ( F_68 ( V_2 , & V_235 , & V_236 ) < 0 )
F_30 ( V_234 , L_179 ) ;
else {
if ( V_236 & V_531 ) {
F_22 ( V_234 , L_180 ) ;
F_16 ( V_4 , V_532 ) ;
if ( V_235 & V_282 )
V_2 -> V_276 = 1 ;
else
V_2 -> V_276 = 0 ;
}
if ( V_236 & V_533 ) {
T_1 V_80 = 0 ;
T_1 V_534 ;
F_22 ( V_234 , L_181 ) ;
F_16 ( V_4 , V_535 ) ;
F_66 ( 500 ) ;
F_63 ( V_2 , true ) ;
F_68 ( V_2 , & V_80 , & V_534 ) ;
if ( V_80 & V_283 )
F_30 ( V_234 , L_182 ) ;
}
}
V_530:
F_267 ( V_120 ) ;
V_529:
F_147 ( V_4 ) ;
F_77 ( V_120 ) ;
F_39 ( & V_2 -> V_123 , V_125 ) ;
}
int F_268 ( void )
{
if ( F_269 ( & V_536 ) < 0 ) {
F_270 ( V_537 L_183 ,
V_538 ) ;
return - 1 ;
}
V_124 = F_271 ( L_184 , V_539 , 0 ) ;
if ( V_124 )
return 0 ;
F_272 ( & V_536 ) ;
F_273 ( L_185 , V_538 ) ;
return - 1 ;
}
void F_274 ( void )
{
F_275 ( V_124 ) ;
F_272 ( & V_536 ) ;
}
static int F_276 ( struct V_7 * V_11 ,
struct V_497 * V_540 ,
struct V_541 * V_542 )
{
int V_85 = 0 ;
unsigned V_543 ;
unsigned V_544 = 0 ;
unsigned V_545 ;
unsigned V_546 ;
int V_547 ;
char * V_498 ;
if ( memcmp ( & V_11 -> V_33 , V_540 ,
sizeof( * V_540 ) ) != 0 )
return 1 ;
if ( ( V_542 && ! V_11 -> V_14 ) || ( ! V_542 && V_11 -> V_14 ) )
return 1 ;
if ( V_11 -> V_14 ) {
V_545 = F_12 ( V_11 -> V_14 -> V_280 -> V_356 ) ;
if ( V_545 != F_12 ( V_542 -> V_280 -> V_356 ) )
return 1 ;
if ( memcmp ( V_11 -> V_14 -> V_280 , V_542 -> V_280 , V_545 ) )
return 1 ;
}
if ( V_11 -> V_350 )
V_544 = strlen ( V_11 -> V_350 ) + 1 ;
V_545 = V_544 ;
for ( V_543 = 0 ; V_543 < V_11 -> V_33 . V_548 ; V_543 ++ ) {
V_546 = F_12 ( V_11 -> V_353 [ V_543 ] . V_280 . V_356 ) ;
V_545 = F_277 ( V_545 , V_546 ) ;
}
V_498 = F_56 ( V_545 , V_206 ) ;
if ( V_498 == NULL ) {
F_30 ( & V_11 -> V_19 , L_186 ) ;
return 1 ;
}
for ( V_543 = 0 ; V_543 < V_11 -> V_33 . V_548 ; V_543 ++ ) {
V_546 = F_12 ( V_11 -> V_353 [ V_543 ] . V_280 . V_356 ) ;
V_547 = F_253 ( V_11 , V_549 , V_543 , V_498 ,
V_546 ) ;
if ( V_547 != V_546 ) {
F_22 ( & V_11 -> V_19 , L_187 ,
V_543 , V_547 ) ;
V_85 = 1 ;
break;
}
if ( memcmp ( V_498 , V_11 -> V_355 [ V_543 ] , V_546 )
!= 0 ) {
F_22 ( & V_11 -> V_19 , L_188 ,
V_543 ,
( (struct V_550 * ) V_498 ) ->
V_551 ) ;
V_85 = 1 ;
break;
}
}
if ( ! V_85 && V_544 ) {
V_547 = F_278 ( V_11 , V_11 -> V_33 . V_347 ,
V_498 , V_544 ) ;
if ( V_547 + 1 != V_544 ) {
F_22 ( & V_11 -> V_19 , L_189 ,
V_547 ) ;
V_85 = 1 ;
} else if ( memcmp ( V_498 , V_11 -> V_350 , V_547 ) != 0 ) {
F_22 ( & V_11 -> V_19 , L_190 ) ;
V_85 = 1 ;
}
}
F_52 ( V_498 ) ;
return V_85 ;
}
static int F_215 ( struct V_7 * V_11 )
{
struct V_7 * V_552 = V_11 -> V_22 ;
struct V_1 * V_553 ;
struct V_190 * V_156 = F_60 ( V_11 -> V_170 ) ;
struct V_497 V_33 = V_11 -> V_33 ;
struct V_541 * V_14 ;
int V_53 , V_487 , V_54 = 0 ;
int V_69 = V_11 -> V_126 ;
if ( V_11 -> V_87 == V_185 ||
V_11 -> V_87 == V_323 ) {
F_22 ( & V_11 -> V_19 , L_191 ,
V_11 -> V_87 ) ;
return - V_66 ;
}
if ( ! V_552 )
return - V_554 ;
V_553 = F_3 ( V_552 ) ;
if ( V_11 -> V_424 == 1 )
F_210 ( V_11 , 0 ) ;
V_14 = V_11 -> V_14 ;
V_11 -> V_14 = NULL ;
V_54 = F_211 ( V_11 ) ;
if ( V_54 ) {
F_30 ( & V_11 -> V_19 , L_192 , V_115 ) ;
goto V_555;
}
V_54 = F_203 ( V_11 ) ;
if ( V_54 ) {
F_30 ( & V_11 -> V_19 , L_193 ,
V_115 ) ;
goto V_555;
}
for ( V_53 = 0 ; V_53 < V_519 ; ++ V_53 ) {
F_238 ( V_11 ) ;
V_54 = F_246 ( V_553 , V_11 , V_69 , V_53 ) ;
if ( V_54 >= 0 || V_54 == - V_397 || V_54 == - V_113 )
break;
}
if ( V_54 < 0 )
goto V_555;
if ( F_276 ( V_11 , & V_33 , V_14 ) ) {
F_7 ( & V_11 -> V_19 , L_194 ) ;
V_11 -> V_33 = V_33 ;
goto V_555;
}
if ( ! V_11 -> V_8 )
goto V_405;
F_29 ( V_156 -> V_474 ) ;
V_54 = F_279 ( V_11 , V_11 -> V_8 , NULL , NULL ) ;
if ( V_54 < 0 ) {
F_71 ( & V_11 -> V_19 ,
L_195
L_196 ) ;
F_31 ( V_156 -> V_474 ) ;
goto V_555;
}
V_54 = F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_556 , 0 ,
V_11 -> V_8 -> V_280 . V_551 , 0 ,
NULL , 0 , V_200 ) ;
if ( V_54 < 0 ) {
F_30 ( & V_11 -> V_19 ,
L_197 ,
V_11 -> V_8 -> V_280 . V_551 , V_54 ) ;
F_31 ( V_156 -> V_474 ) ;
goto V_555;
}
F_31 ( V_156 -> V_474 ) ;
F_73 ( V_11 , V_88 ) ;
for ( V_53 = 0 ; V_53 < V_11 -> V_8 -> V_280 . V_557 ; V_53 ++ ) {
struct V_558 * V_353 = V_11 -> V_8 ;
struct V_119 * V_120 = V_353 -> V_10 [ V_53 ] ;
struct V_559 * V_280 ;
V_280 = & V_120 -> V_293 -> V_280 ;
if ( V_280 -> V_560 == 0 ) {
F_280 ( V_11 , V_120 , true ) ;
F_281 ( V_11 , V_120 , true ) ;
V_54 = 0 ;
} else {
V_120 -> V_561 = 1 ;
V_54 = F_97 ( V_11 , V_280 -> V_562 ,
V_280 -> V_560 ) ;
V_120 -> V_561 = 0 ;
}
if ( V_54 < 0 ) {
F_30 ( & V_11 -> V_19 , L_198
L_199 ,
V_280 -> V_562 ,
V_280 -> V_560 ,
V_54 ) ;
goto V_555;
}
for ( V_487 = 0 ; V_487 < V_120 -> V_293 -> V_280 . V_302 ; V_487 ++ )
V_120 -> V_293 -> V_232 [ V_487 ] . V_563 = 0 ;
}
V_405:
F_210 ( V_11 , 1 ) ;
F_212 ( V_11 ) ;
F_205 ( V_11 ) ;
F_282 ( V_11 ) ;
V_11 -> V_14 = V_14 ;
return 0 ;
V_555:
F_74 ( V_553 , V_69 ) ;
F_282 ( V_11 ) ;
V_11 -> V_14 = V_14 ;
return - V_113 ;
}
int F_266 ( struct V_7 * V_11 )
{
int V_54 ;
int V_53 ;
unsigned int V_564 ;
struct V_77 * V_78 ;
struct V_558 * V_353 = V_11 -> V_8 ;
struct V_1 * V_2 = F_3 ( V_11 -> V_22 ) ;
if ( V_11 -> V_87 == V_185 ||
V_11 -> V_87 == V_323 ) {
F_22 ( & V_11 -> V_19 , L_191 ,
V_11 -> V_87 ) ;
return - V_66 ;
}
if ( ! V_11 -> V_22 ) {
F_22 ( & V_11 -> V_19 , L_200 , V_115 ) ;
return - V_554 ;
}
V_78 = V_2 -> V_79 [ V_11 -> V_126 - 1 ] ;
V_564 = F_283 () ;
F_184 ( V_11 ) ;
if ( V_353 ) {
for ( V_53 = 0 ; V_53 < V_353 -> V_280 . V_557 ; ++ V_53 ) {
struct V_119 * V_565 = V_353 -> V_10 [ V_53 ] ;
struct V_566 * V_155 ;
int V_567 = 0 ;
if ( V_565 -> V_19 . V_157 ) {
V_155 = F_284 ( V_565 -> V_19 . V_157 ) ;
if ( V_155 -> V_568 && V_155 -> V_569 )
V_567 = ( V_155 -> V_568 ) ( V_565 ) ;
else if ( V_565 -> V_570 ==
V_571 )
V_567 = 1 ;
if ( V_567 )
F_285 ( V_565 ) ;
}
}
}
F_198 ( V_78 ) ;
V_54 = F_215 ( V_11 ) ;
F_199 ( V_78 ) ;
if ( V_353 ) {
for ( V_53 = V_353 -> V_280 . V_557 - 1 ; V_53 >= 0 ; -- V_53 ) {
struct V_119 * V_565 = V_353 -> V_10 [ V_53 ] ;
struct V_566 * V_155 ;
int V_572 = V_565 -> V_573 ;
if ( ! V_572 && V_565 -> V_19 . V_157 ) {
V_155 = F_284 ( V_565 -> V_19 . V_157 ) ;
if ( V_155 -> V_569 )
V_572 = ( V_155 -> V_569 ) ( V_565 ) ;
else if ( V_565 -> V_570 ==
V_571 )
V_572 = 1 ;
if ( V_572 )
V_565 -> V_573 = 1 ;
}
}
F_286 ( V_11 ) ;
}
F_187 ( V_11 ) ;
F_287 ( V_564 ) ;
return V_54 ;
}
void F_288 ( struct V_119 * V_574 )
{
if ( F_62 ( & V_574 -> V_575 ) )
F_123 ( V_574 ) ;
}
struct V_7 * F_289 ( struct V_7 * V_4 ,
int V_69 )
{
struct V_1 * V_2 = F_3 ( V_4 ) ;
if ( V_69 < 1 || V_69 > V_4 -> V_9 )
return NULL ;
return V_2 -> V_79 [ V_69 - 1 ] -> V_184 ;
}
void F_106 ( struct V_7 * V_4 ,
struct V_60 * V_280 )
{
struct V_1 * V_2 = F_3 ( V_4 ) ;
enum V_576 V_370 ;
int V_53 ;
if ( ! V_2 )
return;
if ( ! F_2 ( V_4 ) ) {
for ( V_53 = 1 ; V_53 <= V_4 -> V_9 ; V_53 ++ ) {
struct V_77 * V_78 = V_2 -> V_79 [ V_53 - 1 ] ;
V_370 = V_78 -> V_370 ;
if ( V_370 == V_372 ) {
T_2 V_577 = 1 << ( V_53 % 8 ) ;
if ( ! ( V_280 -> V_34 . V_248 . V_249 [ V_53 / 8 ] & V_577 ) ) {
F_22 ( & V_78 -> V_19 , L_201 ) ;
V_280 -> V_34 . V_248 . V_249 [ V_53 / 8 ] |= V_577 ;
}
}
}
} else {
T_1 V_578 = F_12 ( V_280 -> V_34 . V_35 . V_249 ) ;
for ( V_53 = 1 ; V_53 <= V_4 -> V_9 ; V_53 ++ ) {
struct V_77 * V_78 = V_2 -> V_79 [ V_53 - 1 ] ;
V_370 = V_78 -> V_370 ;
if ( V_370 == V_372 ) {
T_1 V_577 = 1 << V_53 ;
if ( ! ( V_578 & V_577 ) ) {
F_22 ( & V_78 -> V_19 , L_201 ) ;
V_578 |= V_577 ;
}
}
}
V_280 -> V_34 . V_35 . V_249 = F_229 ( V_578 ) ;
}
}
T_6 F_290 ( struct V_7 * V_4 ,
int V_69 )
{
struct V_1 * V_2 = F_3 ( V_4 ) ;
if ( ! V_2 )
return NULL ;
return F_291 ( & V_2 -> V_79 [ V_69 - 1 ] -> V_19 ) ;
}
