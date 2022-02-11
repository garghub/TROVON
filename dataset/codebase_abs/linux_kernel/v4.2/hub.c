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
if ( V_11 -> V_12 == V_13 || V_11 -> V_12 == V_14 ) {
if ( V_11 -> V_15 -> V_16 &&
( V_17 &
F_6 ( V_11 -> V_15 -> V_16 -> V_18 ) ) )
return 1 ;
return 0 ;
}
if ( ! V_11 -> V_15 -> V_19 ) {
F_7 ( & V_11 -> V_20 , L_5 ) ;
return 0 ;
}
if ( V_11 -> V_15 -> V_19 -> V_21 == 0 &&
V_11 -> V_15 -> V_19 -> V_22 == 0 ) {
if ( V_11 -> V_23 )
F_7 ( & V_11 -> V_20 , L_6 ) ;
else
F_7 ( & V_11 -> V_20 , L_7 ) ;
return 0 ;
}
if ( ! V_11 -> V_23 || V_11 -> V_23 -> V_24 )
return 1 ;
return 0 ;
}
static void F_8 ( struct V_7 * V_11 ,
struct V_25 * V_26 ,
unsigned int V_27 ,
struct V_1 * V_2 ,
struct V_25 * V_28 ,
unsigned int V_29 )
{
unsigned int V_30 ;
unsigned int V_31 ;
unsigned int V_32 ;
V_30 = V_28 -> V_33 +
( V_2 -> V_34 -> V_35 . V_36 . V_37 * 100 ) ;
V_31 = V_27 * 1000 ;
V_32 = V_29 * 1000 ;
if ( V_31 > V_32 )
V_30 += V_31 ;
else
V_30 += V_32 ;
V_26 -> V_33 = V_30 ;
}
static void F_9 ( struct V_7 * V_11 ,
struct V_25 * V_26 ,
unsigned int V_27 ,
struct V_1 * V_2 ,
struct V_25 * V_28 ,
unsigned int V_29 ,
unsigned int V_38 )
{
unsigned int V_39 ;
unsigned int V_40 ;
if ( V_27 > V_29 )
V_39 = V_27 * 1000 ;
else
V_39 = V_29 * 1000 ;
V_40 = V_38 * 1000 + V_28 -> V_41 ;
if ( V_39 > V_40 )
V_26 -> V_41 = V_39 ;
else
V_26 -> V_41 = V_40 ;
}
static void F_10 ( struct V_7 * V_11 ,
struct V_25 * V_26 )
{
struct V_7 * V_23 ;
unsigned int V_42 ;
unsigned int V_43 ;
V_43 = V_26 -> V_41 ;
for ( V_23 = V_11 -> V_23 , V_42 = 0 ; V_23 -> V_23 ;
V_23 = V_23 -> V_23 )
V_42 ++ ;
if ( V_42 > 0 )
V_43 += 2100 + 250 * ( V_42 - 1 ) ;
V_43 += 250 * V_42 ;
V_26 -> V_44 = V_43 ;
}
static void F_11 ( struct V_7 * V_11 )
{
struct V_1 * V_2 ;
unsigned int V_45 ;
unsigned int V_46 ;
unsigned int V_47 ;
unsigned int V_48 ;
unsigned int V_49 ;
if ( ! V_11 -> V_24 || V_11 -> V_12 != V_50 )
return;
V_2 = F_3 ( V_11 -> V_23 ) ;
if ( ! V_2 )
return;
V_46 = V_11 -> V_15 -> V_19 -> V_21 ;
V_47 = F_12 ( V_11 -> V_15 -> V_19 -> V_22 ) ;
V_48 = V_11 -> V_23 -> V_15 -> V_19 -> V_21 ;
V_49 = F_12 ( V_11 -> V_23 -> V_15 -> V_19 -> V_22 ) ;
F_8 ( V_11 , & V_11 -> V_51 , V_46 ,
V_2 , & V_11 -> V_23 -> V_51 , V_48 ) ;
F_8 ( V_11 , & V_11 -> V_52 , V_47 ,
V_2 , & V_11 -> V_23 -> V_52 , V_49 ) ;
V_45 = 1 ;
F_9 ( V_11 , & V_11 -> V_51 , V_46 ,
V_2 , & V_11 -> V_23 -> V_51 , V_48 ,
V_45 ) ;
if ( V_49 > V_48 )
V_45 = 1 + V_49 - V_48 ;
else
V_45 = 1 + V_48 ;
F_9 ( V_11 , & V_11 -> V_52 , V_47 ,
V_2 , & V_11 -> V_23 -> V_52 , V_49 ,
V_45 ) ;
F_10 ( V_11 , & V_11 -> V_51 ) ;
F_10 ( V_11 , & V_11 -> V_52 ) ;
}
static int F_13 ( struct V_7 * V_4 , void * V_53 )
{
int V_54 , V_55 , V_56 ;
unsigned V_57 ;
if ( F_2 ( V_4 ) ) {
V_57 = V_58 ;
V_56 = V_59 ;
} else {
V_57 = V_60 ;
V_56 = sizeof( struct V_61 ) ;
}
for ( V_54 = 0 ; V_54 < 3 ; V_54 ++ ) {
V_55 = F_14 ( V_4 , F_15 ( V_4 , 0 ) ,
V_62 , V_63 | V_64 ,
V_57 << 8 , 0 , V_53 , V_56 ,
V_65 ) ;
if ( V_55 >= ( V_66 + 2 ) )
return V_55 ;
}
return - V_67 ;
}
static int F_16 ( struct V_7 * V_4 , int V_68 )
{
return F_14 ( V_4 , F_17 ( V_4 , 0 ) ,
V_69 , V_64 , V_68 , 0 , NULL , 0 , 1000 ) ;
}
int F_18 ( struct V_7 * V_4 , int V_70 , int V_68 )
{
return F_14 ( V_4 , F_17 ( V_4 , 0 ) ,
V_69 , V_71 , V_68 , V_70 ,
NULL , 0 , 1000 ) ;
}
static int F_19 ( struct V_7 * V_4 , int V_70 , int V_68 )
{
return F_14 ( V_4 , F_17 ( V_4 , 0 ) ,
V_72 , V_71 , V_68 , V_70 ,
NULL , 0 , 1000 ) ;
}
static char * F_20 ( int V_73 )
{
switch ( V_73 ) {
case V_74 :
return L_8 ;
case V_75 :
return L_9 ;
case V_76 :
return L_10 ;
case V_77 :
return L_11 ;
default:
return L_12 ;
}
}
static void F_21 ( struct V_1 * V_2 , int V_70 , int V_73 )
{
struct V_78 * V_79 = V_2 -> V_80 [ V_70 - 1 ] ;
int V_81 ;
V_81 = F_19 ( V_2 -> V_4 , ( V_73 << 8 ) | V_70 ,
V_82 ) ;
F_22 ( & V_79 -> V_20 , L_13 ,
F_20 ( V_73 ) , V_81 ) ;
}
static void F_23 ( struct V_83 * V_84 )
{
struct V_1 * V_2 =
F_24 ( V_84 , struct V_1 , V_85 . V_84 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
unsigned V_54 ;
unsigned V_86 = 0 ;
int V_87 = - 1 ;
if ( V_4 -> V_88 != V_89 || V_2 -> V_90 )
return;
for ( V_54 = 0 ; V_54 < V_4 -> V_9 ; V_54 ++ ) {
unsigned V_73 , V_91 ;
switch ( V_2 -> V_92 [ V_54 ] ) {
case V_93 :
V_87 = V_54 ;
V_73 = V_77 ;
V_91 = V_94 ;
break;
case V_95 :
V_73 = V_75 ;
V_91 = V_96 ;
break;
case V_96 :
V_73 = V_76 ;
V_91 = V_95 ;
break;
case V_97 :
V_73 = V_74 ;
V_91 = V_98 ;
break;
case V_98 :
V_73 = V_76 ;
V_91 = V_97 ;
break;
case V_99 :
V_73 = V_75 ;
V_91 = V_100 ;
break;
case V_100 :
V_73 = V_74 ;
V_91 = V_99 ;
break;
default:
continue;
}
if ( V_73 != V_77 )
V_86 = 1 ;
F_21 ( V_2 , V_54 + 1 , V_73 ) ;
V_2 -> V_92 [ V_54 ] = V_91 ;
}
if ( ! V_86 && V_101 ) {
V_87 ++ ;
V_87 %= V_4 -> V_9 ;
F_21 ( V_2 , V_87 + 1 , V_75 ) ;
V_2 -> V_92 [ V_87 ] = V_93 ;
V_86 ++ ;
}
if ( V_86 )
F_25 ( V_102 ,
& V_2 -> V_85 , V_103 ) ;
}
static int F_26 ( struct V_7 * V_4 ,
struct V_104 * V_53 )
{
int V_54 , V_81 = - V_105 ;
for ( V_54 = 0 ; V_54 < V_106 &&
( V_81 == - V_105 || V_81 == - V_107 ) ; V_54 ++ ) {
V_81 = F_14 ( V_4 , F_15 ( V_4 , 0 ) ,
V_108 , V_63 | V_64 , 0 , 0 ,
V_53 , sizeof( * V_53 ) , V_109 ) ;
}
return V_81 ;
}
static int F_27 ( struct V_7 * V_4 , int V_70 ,
struct V_110 * V_53 )
{
int V_54 , V_81 = - V_105 ;
for ( V_54 = 0 ; V_54 < V_106 &&
( V_81 == - V_105 || V_81 == - V_107 ) ; V_54 ++ ) {
V_81 = F_14 ( V_4 , F_15 ( V_4 , 0 ) ,
V_108 , V_63 | V_71 , 0 , V_70 ,
V_53 , sizeof( * V_53 ) , V_109 ) ;
}
return V_81 ;
}
static int F_28 ( struct V_1 * V_2 , int V_70 ,
T_1 * V_81 , T_1 * V_111 )
{
int V_55 ;
F_29 ( & V_2 -> V_112 ) ;
V_55 = F_27 ( V_2 -> V_4 , V_70 , & V_2 -> V_81 -> V_113 ) ;
if ( V_55 < 4 ) {
if ( V_55 != - V_114 )
F_30 ( V_2 -> V_115 ,
L_14 , V_116 , V_55 ) ;
if ( V_55 >= 0 )
V_55 = - V_117 ;
} else {
* V_81 = F_12 ( V_2 -> V_81 -> V_113 . V_118 ) ;
* V_111 = F_12 ( V_2 -> V_81 -> V_113 . V_119 ) ;
V_55 = 0 ;
}
F_31 ( & V_2 -> V_112 ) ;
return V_55 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_120 * V_121 ;
if ( V_2 -> V_122 || F_33 ( & V_2 -> V_123 ) )
return;
V_121 = F_34 ( V_2 -> V_115 ) ;
F_35 ( V_121 ) ;
F_36 ( & V_2 -> V_124 ) ;
if ( F_37 ( V_125 , & V_2 -> V_123 ) )
return;
F_38 ( V_121 ) ;
F_39 ( & V_2 -> V_124 , V_126 ) ;
}
void F_40 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = F_3 ( V_4 ) ;
if ( V_2 )
F_32 ( V_2 ) ;
}
void F_41 ( struct V_7 * V_4 ,
unsigned int V_127 )
{
struct V_1 * V_2 ;
if ( ! V_4 )
return;
V_2 = F_3 ( V_4 ) ;
if ( V_2 ) {
F_42 ( V_127 , V_2 -> V_128 ) ;
F_32 ( V_2 ) ;
}
}
static void F_43 ( struct V_129 * V_129 )
{
struct V_1 * V_2 = V_129 -> V_130 ;
int V_81 = V_129 -> V_81 ;
unsigned V_54 ;
unsigned long V_131 ;
switch ( V_81 ) {
case - V_132 :
case - V_133 :
case - V_134 :
return;
default:
F_22 ( V_2 -> V_115 , L_15 , V_81 ) ;
if ( ( ++ V_2 -> V_135 < 10 ) || V_2 -> error )
goto V_136;
V_2 -> error = V_81 ;
case 0 :
V_131 = 0 ;
for ( V_54 = 0 ; V_54 < V_129 -> V_137 ; ++ V_54 )
V_131 |= ( ( unsigned long ) ( ( * V_2 -> V_138 ) [ V_54 ] ) )
<< ( V_54 * 8 ) ;
V_2 -> V_139 [ 0 ] = V_131 ;
break;
}
V_2 -> V_135 = 0 ;
F_32 ( V_2 ) ;
V_136:
if ( V_2 -> V_90 )
return;
if ( ( V_81 = F_44 ( V_2 -> V_129 , V_140 ) ) != 0
&& V_81 != - V_114 && V_81 != - V_141 )
F_30 ( V_2 -> V_115 , L_16 , V_81 ) ;
}
static inline int
F_45 ( struct V_7 * V_4 , T_1 V_142 , T_1 V_143 )
{
if ( ( ( V_142 >> 11 ) & V_144 ) ==
V_145 ) {
int V_81 = F_14 ( V_4 , F_17 ( V_4 , 0 ) ,
V_146 , V_71 ,
V_142 ^ 0x8000 , V_143 , NULL , 0 , 1000 ) ;
if ( V_81 )
return V_81 ;
}
return F_14 ( V_4 , F_17 ( V_4 , 0 ) ,
V_146 , V_71 , V_142 ,
V_143 , NULL , 0 , 1000 ) ;
}
static void F_46 ( struct V_83 * V_84 )
{
struct V_1 * V_2 =
F_24 ( V_84 , struct V_1 , V_143 . V_147 ) ;
unsigned long V_148 ;
F_47 ( & V_2 -> V_143 . V_149 , V_148 ) ;
while ( ! F_48 ( & V_2 -> V_143 . V_150 ) ) {
struct V_151 * V_152 ;
struct V_153 * V_154 ;
struct V_7 * V_4 = V_2 -> V_4 ;
const struct V_155 * V_156 ;
int V_81 ;
V_152 = V_2 -> V_143 . V_150 . V_152 ;
V_154 = F_49 ( V_152 , struct V_153 , V_150 ) ;
F_50 ( & V_154 -> V_150 ) ;
F_51 ( & V_2 -> V_143 . V_149 , V_148 ) ;
V_81 = F_45 ( V_4 , V_154 -> V_142 , V_154 -> V_143 ) ;
if ( V_81 && V_81 != - V_114 )
F_30 ( & V_4 -> V_20 ,
L_17 ,
V_154 -> V_143 , V_154 -> V_142 , V_81 ) ;
V_156 = V_154 -> V_157 -> V_158 ;
if ( V_156 -> V_159 )
( V_156 -> V_159 ) ( V_154 -> V_157 , V_154 -> V_160 ) ;
F_52 ( V_154 ) ;
F_47 ( & V_2 -> V_143 . V_149 , V_148 ) ;
}
F_51 ( & V_2 -> V_143 . V_149 , V_148 ) ;
}
int F_53 ( struct V_7 * V_4 , struct V_1 * V_2 ,
int V_70 , bool V_161 )
{
int V_55 ;
if ( V_161 )
V_55 = F_19 ( V_4 , V_70 , V_162 ) ;
else
V_55 = F_18 ( V_4 , V_70 , V_162 ) ;
if ( V_55 )
return V_55 ;
if ( V_161 )
F_42 ( V_70 , V_2 -> V_163 ) ;
else
F_54 ( V_70 , V_2 -> V_163 ) ;
return 0 ;
}
int F_55 ( struct V_129 * V_129 )
{
struct V_7 * V_11 = V_129 -> V_20 ;
int V_164 = V_129 -> V_164 ;
struct V_165 * V_143 = V_11 -> V_143 ;
unsigned long V_148 ;
struct V_153 * V_154 ;
V_154 = F_56 ( sizeof *V_154 , V_140 ) ;
if ( V_154 == NULL ) {
F_30 ( & V_11 -> V_20 , L_18 ) ;
return - V_166 ;
}
V_154 -> V_143 = V_143 -> V_167 ? V_11 -> V_168 : 1 ;
V_154 -> V_142 = F_57 ( V_164 ) ;
V_154 -> V_142 |= V_11 -> V_169 << 4 ;
V_154 -> V_142 |= F_58 ( V_164 )
? ( V_145 << 11 )
: ( V_170 << 11 ) ;
if ( F_59 ( V_164 ) )
V_154 -> V_142 |= 1 << 15 ;
V_154 -> V_157 = F_60 ( V_11 -> V_171 ) ;
V_154 -> V_160 = V_129 -> V_160 ;
F_47 ( & V_143 -> V_149 , V_148 ) ;
F_61 ( & V_154 -> V_150 , & V_143 -> V_150 ) ;
F_62 ( & V_143 -> V_147 ) ;
F_51 ( & V_143 -> V_149 , V_148 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 , bool V_172 )
{
int V_70 ;
if ( F_64 ( V_2 ) )
F_22 ( V_2 -> V_115 , L_19 ) ;
else
F_22 ( V_2 -> V_115 , L_20
L_21 ) ;
for ( V_70 = 1 ; V_70 <= V_2 -> V_4 -> V_9 ; V_70 ++ )
if ( F_65 ( V_70 , V_2 -> V_163 ) )
F_19 ( V_2 -> V_4 , V_70 , V_162 ) ;
else
F_18 ( V_2 -> V_4 , V_70 ,
V_162 ) ;
if ( V_172 )
F_66 ( F_67 ( V_2 ) ) ;
}
static int F_68 ( struct V_1 * V_2 ,
T_1 * V_81 , T_1 * V_111 )
{
int V_55 ;
F_29 ( & V_2 -> V_112 ) ;
V_55 = F_26 ( V_2 -> V_4 , & V_2 -> V_81 -> V_2 ) ;
if ( V_55 < 0 ) {
if ( V_55 != - V_114 )
F_30 ( V_2 -> V_115 ,
L_14 , V_116 , V_55 ) ;
} else {
* V_81 = F_12 ( V_2 -> V_81 -> V_2 . V_173 ) ;
* V_111 = F_12 ( V_2 -> V_81 -> V_2 . V_174 ) ;
V_55 = 0 ;
}
F_31 ( & V_2 -> V_112 ) ;
return V_55 ;
}
static int F_69 ( struct V_1 * V_2 , int V_70 ,
unsigned int V_175 )
{
return F_19 ( V_2 -> V_4 ,
V_70 | ( V_175 << 3 ) ,
V_176 ) ;
}
static int F_70 ( struct V_1 * V_2 , int V_70 )
{
int V_55 ;
int V_177 ;
T_1 V_178 , V_3 ;
if ( ! F_2 ( V_2 -> V_4 ) )
return - V_67 ;
V_55 = F_28 ( V_2 , V_70 , & V_3 , & V_178 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( ( V_3 & V_179 ) ==
V_180 ) {
F_22 ( & V_2 -> V_80 [ V_70 - 1 ] -> V_20 ,
L_22 ) ;
return V_55 ;
}
V_55 = F_69 ( V_2 , V_70 , V_181 ) ;
if ( V_55 )
return V_55 ;
for ( V_177 = 0 ; ; V_177 += V_182 ) {
V_55 = F_28 ( V_2 , V_70 , & V_3 , & V_178 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( ( V_3 & V_179 ) ==
V_181 )
break;
if ( V_177 >= V_183 )
break;
F_66 ( V_182 ) ;
}
if ( V_177 >= V_183 )
F_71 ( & V_2 -> V_80 [ V_70 - 1 ] -> V_20 ,
L_23 , V_177 ) ;
return F_69 ( V_2 , V_70 , V_180 ) ;
}
static int F_72 ( struct V_1 * V_2 , int V_70 , int V_184 )
{
struct V_78 * V_79 = V_2 -> V_80 [ V_70 - 1 ] ;
struct V_7 * V_4 = V_2 -> V_4 ;
int V_55 = 0 ;
if ( V_79 -> V_185 && V_184 )
F_73 ( V_79 -> V_185 , V_186 ) ;
if ( ! V_2 -> error ) {
if ( F_2 ( V_2 -> V_4 ) )
V_55 = F_70 ( V_2 , V_70 ) ;
else
V_55 = F_18 ( V_4 , V_70 ,
V_187 ) ;
}
if ( V_55 && V_55 != - V_114 )
F_30 ( & V_79 -> V_20 , L_24 , V_55 ) ;
return V_55 ;
}
static void F_74 ( struct V_1 * V_2 , int V_70 )
{
F_22 ( & V_2 -> V_80 [ V_70 - 1 ] -> V_20 , L_25 ) ;
F_72 ( V_2 , V_70 , 1 ) ;
F_42 ( V_70 , V_2 -> V_188 ) ;
F_32 ( V_2 ) ;
}
int F_75 ( struct V_7 * V_11 )
{
struct V_1 * V_2 ;
struct V_120 * V_121 ;
if ( ! V_11 -> V_23 )
return - V_67 ;
V_2 = F_3 ( V_11 -> V_23 ) ;
V_121 = F_34 ( V_2 -> V_115 ) ;
F_76 ( V_121 ) ;
F_42 ( V_11 -> V_127 , V_2 -> V_189 ) ;
F_74 ( V_2 , V_11 -> V_127 ) ;
F_77 ( V_121 ) ;
return 0 ;
}
static void F_78 ( struct V_1 * V_2 , enum V_190 type )
{
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_191 * V_157 ;
int V_55 ;
int V_70 ;
int V_81 ;
bool V_192 = false ;
unsigned V_193 ;
if ( type == V_194 )
goto V_195;
if ( type == V_196 )
goto V_197;
if ( type != V_198 ) {
if ( V_4 -> V_23 && F_2 ( V_4 ) ) {
V_55 = F_14 ( V_4 , F_17 ( V_4 , 0 ) ,
V_199 , V_64 ,
V_4 -> V_200 - 1 , 0 , NULL , 0 ,
V_201 ) ;
if ( V_55 < 0 )
F_30 ( V_2 -> V_115 ,
L_26 ) ;
}
if ( type == V_202 ) {
unsigned V_193 = F_67 ( V_2 ) ;
F_63 ( V_2 , false ) ;
F_79 ( & V_2 -> V_203 , V_204 ) ;
F_25 ( V_102 ,
& V_2 -> V_203 ,
F_80 ( V_193 ) ) ;
F_35 (
F_34 ( V_2 -> V_115 ) ) ;
return;
} else if ( type == V_205 ) {
V_157 = F_60 ( V_4 -> V_171 ) ;
if ( V_157 -> V_158 -> V_206 ) {
V_55 = V_157 -> V_158 -> V_206 ( V_157 , V_4 ,
& V_2 -> V_143 , V_207 ) ;
if ( V_55 < 0 ) {
F_30 ( V_2 -> V_115 , L_27
L_28
L_29 ) ;
F_30 ( V_2 -> V_115 , L_30
L_31
L_32 ) ;
}
}
F_63 ( V_2 , true ) ;
} else {
F_63 ( V_2 , true ) ;
}
}
V_195:
for ( V_70 = 1 ; V_70 <= V_4 -> V_9 ; ++ V_70 ) {
struct V_78 * V_79 = V_2 -> V_80 [ V_70 - 1 ] ;
struct V_7 * V_11 = V_79 -> V_185 ;
T_1 V_3 , V_178 ;
V_3 = V_178 = 0 ;
V_81 = F_28 ( V_2 , V_70 , & V_3 , & V_178 ) ;
if ( V_11 || ( V_3 & V_208 ) )
F_22 ( & V_79 -> V_20 , L_33 ,
V_3 , V_178 ) ;
if ( ( V_3 & V_209 ) && (
type != V_198 ||
! ( V_3 & V_208 ) ||
! V_11 ||
V_11 -> V_88 == V_186 ) ) {
V_3 &= ~ V_209 ;
if ( ! F_2 ( V_4 ) )
F_18 ( V_4 , V_70 ,
V_187 ) ;
}
if ( V_178 & V_210 ) {
V_192 = true ;
F_18 ( V_2 -> V_4 , V_70 ,
V_211 ) ;
}
if ( V_178 & V_212 ) {
V_192 = true ;
F_18 ( V_2 -> V_4 , V_70 ,
V_213 ) ;
}
if ( V_178 & V_214 ) {
V_192 = true ;
F_18 ( V_2 -> V_4 , V_70 ,
V_215 ) ;
}
if ( ( V_178 & V_216 ) &&
F_2 ( V_2 -> V_4 ) ) {
V_192 = true ;
F_18 ( V_2 -> V_4 , V_70 ,
V_217 ) ;
}
if ( ! ( V_3 & V_208 ) ||
( V_178 & V_210 ) )
F_54 ( V_70 , V_2 -> V_189 ) ;
if ( ! V_11 || V_11 -> V_88 == V_186 ) {
if ( V_11 || ( V_3 & V_208 ) ||
( V_3 & V_218 ) )
F_42 ( V_70 , V_2 -> V_188 ) ;
} else if ( V_3 & V_209 ) {
bool V_219 = ( V_3 &
V_179 ) ==
V_220 ;
if ( V_178 || ( F_2 ( V_2 -> V_4 ) &&
V_219 ) )
F_42 ( V_70 , V_2 -> V_188 ) ;
} else if ( V_11 -> V_221 ) {
#ifdef F_81
V_11 -> V_222 = 1 ;
#endif
if ( F_65 ( V_70 , V_2 -> V_163 ) )
F_42 ( V_70 , V_2 -> V_188 ) ;
} else {
F_73 ( V_11 , V_186 ) ;
F_42 ( V_70 , V_2 -> V_188 ) ;
}
}
if ( V_192 ) {
V_193 = V_223 ;
if ( type == V_194 ) {
F_79 ( & V_2 -> V_203 , V_224 ) ;
F_25 ( V_102 ,
& V_2 -> V_203 ,
F_80 ( V_193 ) ) ;
return;
} else {
F_66 ( V_193 ) ;
}
}
V_197:
V_2 -> V_90 = 0 ;
V_81 = F_44 ( V_2 -> V_129 , V_207 ) ;
if ( V_81 < 0 )
F_30 ( V_2 -> V_115 , L_34 , V_81 ) ;
if ( V_2 -> V_225 && V_101 )
F_25 ( V_102 ,
& V_2 -> V_85 , V_103 ) ;
F_32 ( V_2 ) ;
if ( type <= V_196 )
F_38 ( F_34 ( V_2 -> V_115 ) ) ;
}
static void V_204 ( struct V_83 * V_226 )
{
struct V_1 * V_2 = F_24 ( V_226 , struct V_1 , V_203 . V_84 ) ;
F_78 ( V_2 , V_194 ) ;
}
static void V_224 ( struct V_83 * V_226 )
{
struct V_1 * V_2 = F_24 ( V_226 , struct V_1 , V_203 . V_84 ) ;
F_78 ( V_2 , V_196 ) ;
}
static void F_82 ( struct V_1 * V_2 , enum V_227 type )
{
struct V_7 * V_4 = V_2 -> V_4 ;
int V_54 ;
F_83 ( & V_2 -> V_203 ) ;
V_2 -> V_90 = 1 ;
if ( type != V_228 ) {
for ( V_54 = 0 ; V_54 < V_4 -> V_9 ; ++ V_54 ) {
if ( V_2 -> V_80 [ V_54 ] -> V_185 )
F_84 ( & V_2 -> V_80 [ V_54 ] -> V_185 ) ;
}
}
F_85 ( V_2 -> V_129 ) ;
if ( V_2 -> V_225 )
F_83 ( & V_2 -> V_85 ) ;
if ( V_2 -> V_143 . V_2 )
F_86 ( & V_2 -> V_143 . V_147 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < V_2 -> V_4 -> V_9 ; ++ V_54 )
F_88 ( & V_2 -> V_80 [ V_54 ] -> V_20 ) ;
}
static int F_89 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = F_4 ( V_121 ) ;
F_82 ( V_2 , V_229 ) ;
V_2 -> V_230 = 1 ;
F_87 ( V_2 ) ;
return 0 ;
}
static int F_90 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = F_4 ( V_121 ) ;
V_2 -> V_230 = 0 ;
F_87 ( V_2 ) ;
F_78 ( V_2 , V_231 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_232 * V_233 )
{
struct V_191 * V_157 ;
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_234 * V_235 = V_2 -> V_115 ;
T_1 V_236 , V_237 ;
T_1 V_238 ;
unsigned int V_164 ;
int V_239 , V_55 , V_54 ;
char * V_240 = L_35 ;
unsigned V_241 ;
unsigned V_242 ;
unsigned V_9 ;
V_2 -> V_138 = F_56 ( sizeof( * V_2 -> V_138 ) , V_243 ) ;
if ( ! V_2 -> V_138 ) {
V_55 = - V_166 ;
goto V_244;
}
V_2 -> V_81 = F_56 ( sizeof( * V_2 -> V_81 ) , V_243 ) ;
if ( ! V_2 -> V_81 ) {
V_55 = - V_166 ;
goto V_244;
}
F_92 ( & V_2 -> V_112 ) ;
V_2 -> V_34 = F_56 ( sizeof( * V_2 -> V_34 ) , V_243 ) ;
if ( ! V_2 -> V_34 ) {
V_55 = - V_166 ;
goto V_244;
}
V_55 = F_13 ( V_4 , V_2 -> V_34 ) ;
if ( V_55 < 0 ) {
V_240 = L_36 ;
goto V_244;
} else if ( V_2 -> V_34 -> V_245 > V_246 ) {
V_240 = L_37 ;
V_55 = - V_114 ;
goto V_244;
} else if ( V_2 -> V_34 -> V_245 == 0 ) {
V_240 = L_38 ;
V_55 = - V_114 ;
goto V_244;
}
V_9 = V_2 -> V_34 -> V_245 ;
F_7 ( V_235 , L_39 , V_9 ,
( V_9 == 1 ) ? L_40 : L_41 ) ;
V_2 -> V_80 = F_93 ( V_9 * sizeof( struct V_78 * ) , V_243 ) ;
if ( ! V_2 -> V_80 ) {
V_55 = - V_166 ;
goto V_244;
}
V_238 = F_12 ( V_2 -> V_34 -> V_238 ) ;
if ( F_2 ( V_4 ) ) {
V_241 = 150 ;
V_242 = 900 ;
} else {
V_241 = 100 ;
V_242 = 500 ;
}
if ( ( V_238 & V_247 ) &&
! ( F_2 ( V_4 ) ) ) {
int V_54 ;
char V_248 [ V_246 + 1 ] ;
for ( V_54 = 0 ; V_54 < V_9 ; V_54 ++ )
V_248 [ V_54 ] = V_2 -> V_34 -> V_35 . V_249 . V_250
[ ( ( V_54 + 1 ) / 8 ) ] & ( 1 << ( ( V_54 + 1 ) % 8 ) )
? 'F' : 'R' ;
V_248 [ V_9 ] = 0 ;
F_22 ( V_235 , L_42 , V_248 ) ;
} else
F_22 ( V_235 , L_43 ) ;
switch ( V_238 & V_251 ) {
case V_252 :
F_22 ( V_235 , L_44 ) ;
break;
case V_253 :
F_22 ( V_235 , L_45 ) ;
break;
case V_254 :
case V_251 :
F_22 ( V_235 , L_46 ) ;
break;
}
switch ( V_238 & V_255 ) {
case V_256 :
F_22 ( V_235 , L_47 ) ;
break;
case V_257 :
F_22 ( V_235 , L_48 ) ;
break;
case V_258 :
case V_255 :
F_22 ( V_235 , L_49 ) ;
break;
}
F_94 ( & V_2 -> V_143 . V_149 ) ;
F_95 ( & V_2 -> V_143 . V_150 ) ;
F_96 ( & V_2 -> V_143 . V_147 , F_46 ) ;
switch ( V_4 -> V_34 . V_259 ) {
case V_260 :
break;
case V_261 :
F_22 ( V_235 , L_50 ) ;
V_2 -> V_143 . V_2 = V_4 ;
break;
case V_262 :
V_55 = F_97 ( V_4 , 0 , 1 ) ;
if ( V_55 == 0 ) {
F_22 ( V_235 , L_51 ) ;
V_2 -> V_143 . V_167 = 1 ;
} else
F_30 ( V_235 , L_52 ,
V_55 ) ;
V_2 -> V_143 . V_2 = V_4 ;
break;
case V_263 :
break;
default:
F_22 ( V_235 , L_53 ,
V_4 -> V_34 . V_259 ) ;
break;
}
switch ( V_238 & V_264 ) {
case V_265 :
if ( V_4 -> V_34 . V_259 != 0 ) {
V_2 -> V_143 . V_266 = 666 ;
F_22 ( V_235 , L_54
L_55 ,
8 , V_2 -> V_143 . V_266 ) ;
}
break;
case V_267 :
V_2 -> V_143 . V_266 = 666 * 2 ;
F_22 ( V_235 , L_54
L_55 ,
16 , V_2 -> V_143 . V_266 ) ;
break;
case V_268 :
V_2 -> V_143 . V_266 = 666 * 3 ;
F_22 ( V_235 , L_54
L_55 ,
24 , V_2 -> V_143 . V_266 ) ;
break;
case V_269 :
V_2 -> V_143 . V_266 = 666 * 4 ;
F_22 ( V_235 , L_54
L_55 ,
32 , V_2 -> V_143 . V_266 ) ;
break;
}
if ( V_238 & V_270 ) {
V_2 -> V_225 = 1 ;
F_22 ( V_235 , L_56 ) ;
}
F_22 ( V_235 , L_57 ,
V_2 -> V_34 -> V_271 * 2 ) ;
V_55 = F_98 ( V_4 , V_272 , 0 , & V_236 ) ;
if ( V_55 ) {
V_240 = L_58 ;
goto V_244;
}
V_157 = F_60 ( V_4 -> V_171 ) ;
if ( V_4 == V_4 -> V_171 -> V_273 ) {
if ( V_157 -> V_274 > 0 )
V_4 -> V_275 = V_157 -> V_274 ;
else
V_4 -> V_275 = V_242 * V_9 ;
if ( V_4 -> V_275 >= V_242 )
V_2 -> V_276 = V_242 ;
else {
V_2 -> V_276 = V_4 -> V_275 ;
V_2 -> V_277 = 1 ;
}
} else if ( ( V_236 & ( 1 << V_278 ) ) == 0 ) {
int V_279 = V_4 -> V_275 -
V_2 -> V_34 -> V_280 ;
F_22 ( V_235 , L_59 ,
V_2 -> V_34 -> V_280 ) ;
V_2 -> V_277 = 1 ;
if ( V_279 < V_9 * V_241 )
F_71 ( V_235 ,
L_60
L_61 ) ;
V_2 -> V_276 = V_241 ;
} else {
V_2 -> V_276 = V_242 ;
}
if ( V_2 -> V_276 < V_242 )
F_22 ( V_235 , L_62 ,
V_2 -> V_276 ) ;
V_55 = F_68 ( V_2 , & V_236 , & V_237 ) ;
if ( V_55 < 0 ) {
V_240 = L_58 ;
goto V_244;
}
if ( V_4 -> V_8 -> V_281 . V_18 & V_282 )
F_22 ( V_235 , L_63 ,
( V_236 & V_283 )
? L_64 : L_65 ) ;
if ( ( V_238 & V_255 ) == 0 )
F_22 ( V_235 , L_66 ,
( V_236 & V_284 ) ? L_40 : L_67 ) ;
V_164 = F_99 ( V_4 , V_233 -> V_285 ) ;
V_239 = F_100 ( V_4 , V_164 , F_101 ( V_164 ) ) ;
if ( V_239 > sizeof( * V_2 -> V_138 ) )
V_239 = sizeof( * V_2 -> V_138 ) ;
V_2 -> V_129 = F_102 ( 0 , V_243 ) ;
if ( ! V_2 -> V_129 ) {
V_55 = - V_166 ;
goto V_244;
}
F_103 ( V_2 -> V_129 , V_4 , V_164 , * V_2 -> V_138 , V_239 , F_43 ,
V_2 , V_233 -> V_286 ) ;
if ( V_2 -> V_225 && V_101 )
V_2 -> V_92 [ 0 ] = V_93 ;
F_29 ( & V_287 ) ;
for ( V_54 = 0 ; V_54 < V_9 ; V_54 ++ ) {
V_55 = F_104 ( V_2 , V_54 + 1 ) ;
if ( V_55 < 0 ) {
F_30 ( V_2 -> V_115 ,
L_68 , V_54 + 1 ) ;
break;
}
}
V_4 -> V_9 = V_54 ;
for ( V_54 = 0 ; V_54 < V_4 -> V_9 ; V_54 ++ ) {
struct V_78 * V_79 = V_2 -> V_80 [ V_54 ] ;
F_105 ( & V_79 -> V_20 ) ;
}
F_31 ( & V_287 ) ;
if ( V_55 < 0 )
goto V_244;
if ( V_157 -> V_158 -> V_206 ) {
V_55 = V_157 -> V_158 -> V_206 ( V_157 , V_4 ,
& V_2 -> V_143 , V_243 ) ;
if ( V_55 < 0 ) {
V_240 = L_69 ;
goto V_244;
}
}
F_106 ( V_4 , V_2 -> V_34 ) ;
F_78 ( V_2 , V_202 ) ;
return 0 ;
V_244:
F_30 ( V_235 , L_70 ,
V_240 , V_55 ) ;
return V_55 ;
}
static void V_126 ( struct V_124 * V_124 )
{
struct V_1 * V_2 = F_24 ( V_124 , struct V_1 , V_124 ) ;
F_107 ( V_2 -> V_4 ) ;
F_108 ( F_34 ( V_2 -> V_115 ) ) ;
F_52 ( V_2 ) ;
}
static void F_109 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = F_4 ( V_121 ) ;
struct V_7 * V_4 = F_110 ( V_121 ) ;
int V_70 ;
V_2 -> V_122 = 1 ;
V_2 -> error = 0 ;
F_82 ( V_2 , V_288 ) ;
F_29 ( & V_287 ) ;
F_111 ( & V_289 ) ;
V_70 = V_4 -> V_9 ;
V_4 -> V_9 = 0 ;
F_112 ( V_121 , NULL ) ;
F_113 ( & V_289 ) ;
for (; V_70 > 0 ; -- V_70 )
F_114 ( V_2 , V_70 ) ;
F_31 ( & V_287 ) ;
if ( V_2 -> V_4 -> V_12 == V_13 )
V_290 -- ;
F_115 ( V_2 -> V_129 ) ;
F_52 ( V_2 -> V_80 ) ;
F_52 ( V_2 -> V_34 ) ;
F_52 ( V_2 -> V_81 ) ;
F_52 ( V_2 -> V_138 ) ;
F_116 ( & V_121 -> V_20 , false ) ;
F_39 ( & V_2 -> V_124 , V_126 ) ;
}
static int F_117 ( struct V_120 * V_121 , const struct V_291 * V_292 )
{
struct V_293 * V_281 ;
struct V_232 * V_233 ;
struct V_7 * V_4 ;
struct V_1 * V_2 ;
V_281 = V_121 -> V_294 ;
V_4 = F_110 ( V_121 ) ;
#ifdef F_81
if ( V_4 -> V_20 . V_295 . V_296 >= 0 )
F_118 ( & V_4 -> V_20 , 0 ) ;
#endif
if ( V_4 -> V_23 ) {
F_119 ( V_4 ) ;
} else {
const struct V_155 * V_156 = F_60 ( V_4 -> V_171 ) -> V_158 ;
if ( V_156 -> V_297 && V_156 -> V_298 )
F_119 ( V_4 ) ;
}
if ( V_4 -> V_200 == V_299 ) {
F_30 ( & V_121 -> V_20 ,
L_71 ) ;
return - V_300 ;
}
#ifdef F_120
if ( V_4 -> V_23 ) {
F_71 ( & V_121 -> V_20 , L_72 ) ;
return - V_114 ;
}
#endif
if ( ( V_281 -> V_281 . V_301 != 0 ) &&
( V_281 -> V_281 . V_301 != 1 ) ) {
V_302:
F_30 ( & V_121 -> V_20 , L_73 ) ;
return - V_117 ;
}
if ( V_281 -> V_281 . V_303 != 1 )
goto V_302;
V_233 = & V_281 -> V_233 [ 0 ] . V_281 ;
if ( ! F_121 ( V_233 ) )
goto V_302;
F_7 ( & V_121 -> V_20 , L_74 ) ;
V_2 = F_93 ( sizeof( * V_2 ) , V_243 ) ;
if ( ! V_2 ) {
F_22 ( & V_121 -> V_20 , L_75 ) ;
return - V_166 ;
}
F_122 ( & V_2 -> V_124 ) ;
V_2 -> V_115 = & V_121 -> V_20 ;
V_2 -> V_4 = V_4 ;
F_79 ( & V_2 -> V_85 , F_23 ) ;
F_79 ( & V_2 -> V_203 , NULL ) ;
F_96 ( & V_2 -> V_123 , V_304 ) ;
F_123 ( V_121 ) ;
F_124 ( V_4 ) ;
F_112 ( V_121 , V_2 ) ;
V_121 -> V_305 = 1 ;
F_116 ( & V_121 -> V_20 , true ) ;
if ( V_4 -> V_12 == V_13 )
V_290 ++ ;
if ( V_292 -> V_306 & V_307 )
V_2 -> V_308 = 1 ;
if ( F_91 ( V_2 , V_233 ) >= 0 )
return 0 ;
F_109 ( V_121 ) ;
return - V_114 ;
}
static int
F_125 ( struct V_120 * V_121 , unsigned int V_309 , void * V_310 )
{
struct V_7 * V_4 = F_110 ( V_121 ) ;
struct V_1 * V_2 = F_3 ( V_4 ) ;
switch ( V_309 ) {
case V_311 : {
struct V_312 * V_313 = V_310 ;
int V_54 ;
F_111 ( & V_289 ) ;
if ( V_4 -> V_169 <= 0 )
V_313 -> V_314 = 0 ;
else {
V_313 -> V_314 = V_4 -> V_9 ;
for ( V_54 = 0 ; V_54 < V_313 -> V_314 ; V_54 ++ ) {
if ( V_2 -> V_80 [ V_54 ] -> V_185 == NULL )
V_313 -> V_113 [ V_54 ] = 0 ;
else
V_313 -> V_113 [ V_54 ] =
V_2 -> V_80 [ V_54 ] -> V_185 -> V_169 ;
}
}
F_113 ( & V_289 ) ;
return V_313 -> V_314 + 1 ;
}
default:
return - V_315 ;
}
}
static int F_126 ( struct V_7 * V_4 , unsigned V_70 ,
struct V_316 * * * V_317 )
{
struct V_1 * V_2 = F_3 ( V_4 ) ;
if ( V_4 -> V_88 == V_186 )
return - V_114 ;
if ( V_70 == 0 || V_70 > V_4 -> V_9 )
return - V_67 ;
* V_317 = & ( V_2 -> V_80 [ V_70 - 1 ] -> V_318 ) ;
return 0 ;
}
int F_127 ( struct V_7 * V_4 , unsigned V_70 ,
struct V_316 * V_319 )
{
int V_320 ;
struct V_316 * * V_321 ;
V_320 = F_126 ( V_4 , V_70 , & V_321 ) ;
if ( V_320 )
return V_320 ;
if ( * V_321 )
return - V_322 ;
* V_321 = V_319 ;
return V_320 ;
}
int F_128 ( struct V_7 * V_4 , unsigned V_70 ,
struct V_316 * V_319 )
{
int V_320 ;
struct V_316 * * V_321 ;
V_320 = F_126 ( V_4 , V_70 , & V_321 ) ;
if ( V_320 )
return V_320 ;
if ( * V_321 != V_319 )
return - V_132 ;
* V_321 = NULL ;
return V_320 ;
}
void F_129 ( struct V_7 * V_4 , struct V_316 * V_319 )
{
struct V_1 * V_2 = F_3 ( V_4 ) ;
int V_323 ;
for ( V_323 = 0 ; V_323 < V_4 -> V_9 ; V_323 ++ ) {
if ( V_2 -> V_80 [ V_323 ] -> V_318 == V_319 )
V_2 -> V_80 [ V_323 ] -> V_318 = NULL ;
}
}
bool F_130 ( struct V_7 * V_11 )
{
struct V_1 * V_2 ;
if ( V_11 -> V_88 == V_186 || ! V_11 -> V_23 )
return false ;
V_2 = F_3 ( V_11 -> V_23 ) ;
return ! ! V_2 -> V_80 [ V_11 -> V_127 - 1 ] -> V_318 ;
}
static void F_131 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_3 ( V_11 ) ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_11 -> V_9 ; ++ V_54 ) {
if ( V_2 -> V_80 [ V_54 ] -> V_185 )
F_131 ( V_2 -> V_80 [ V_54 ] -> V_185 ) ;
}
if ( V_11 -> V_88 == V_324 )
V_11 -> V_325 -= V_326 ;
V_11 -> V_88 = V_186 ;
}
void F_73 ( struct V_7 * V_11 ,
enum V_327 V_328 )
{
unsigned long V_148 ;
int V_329 = - 1 ;
F_47 ( & V_289 , V_148 ) ;
if ( V_11 -> V_88 == V_186 )
;
else if ( V_328 != V_186 ) {
if ( V_11 -> V_23 ) {
if ( V_11 -> V_88 == V_324
|| V_328 == V_324 )
;
else if ( V_328 == V_89 )
V_329 = ( V_11 -> V_330 &
V_331 ) ? 0 :
V_11 -> V_8 -> V_281 . V_18 &
V_332 ;
else
V_329 = 0 ;
}
if ( V_11 -> V_88 == V_324 &&
V_328 != V_324 )
V_11 -> V_325 -= V_326 ;
else if ( V_328 == V_324 &&
V_11 -> V_88 != V_324 )
V_11 -> V_325 += V_326 ;
V_11 -> V_88 = V_328 ;
} else
F_131 ( V_11 ) ;
F_51 ( & V_289 , V_148 ) ;
if ( V_329 >= 0 )
F_132 ( & V_11 -> V_20 , V_329 ) ;
}
static void F_133 ( struct V_7 * V_11 )
{
int V_169 ;
struct V_333 * V_171 = V_11 -> V_171 ;
F_29 ( & V_171 -> V_334 ) ;
if ( V_11 -> V_335 ) {
V_169 = V_11 -> V_127 + 1 ;
F_134 ( F_65 ( V_169 , V_171 -> V_336 . V_337 ) ) ;
} else {
V_169 = F_135 ( V_171 -> V_336 . V_337 , 128 ,
V_171 -> V_338 ) ;
if ( V_169 >= 128 )
V_169 = F_135 ( V_171 -> V_336 . V_337 ,
128 , 1 ) ;
V_171 -> V_338 = ( V_169 >= 127 ? 1 : V_169 + 1 ) ;
}
if ( V_169 < 128 ) {
F_42 ( V_169 , V_171 -> V_336 . V_337 ) ;
V_11 -> V_169 = V_169 ;
}
F_31 ( & V_171 -> V_334 ) ;
}
static void F_136 ( struct V_7 * V_11 )
{
if ( V_11 -> V_169 > 0 ) {
F_54 ( V_11 -> V_169 , V_11 -> V_171 -> V_336 . V_337 ) ;
V_11 -> V_169 = - 1 ;
}
}
static void F_137 ( struct V_7 * V_11 , int V_169 )
{
if ( ! V_11 -> V_335 )
V_11 -> V_169 = V_169 ;
}
static void F_138 ( struct V_7 * V_11 )
{
struct V_191 * V_157 = F_60 ( V_11 -> V_171 ) ;
if ( V_157 -> V_158 -> V_339 && V_11 -> V_23 )
V_157 -> V_158 -> V_339 ( V_157 , V_11 ) ;
}
static void F_139 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_3 ( V_11 ) ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_11 -> V_9 ; V_54 ++ ) {
if ( V_2 -> V_80 [ V_54 ] -> V_185 )
F_84 ( & V_2 -> V_80 [ V_54 ] -> V_185 ) ;
}
}
void F_84 ( struct V_7 * * V_340 )
{
struct V_78 * V_79 = NULL ;
struct V_7 * V_11 = * V_340 ;
struct V_1 * V_2 = NULL ;
int V_70 = 1 ;
F_73 ( V_11 , V_186 ) ;
F_7 ( & V_11 -> V_20 , L_76 ,
V_11 -> V_169 ) ;
F_140 ( V_11 ) ;
F_139 ( V_11 ) ;
F_22 ( & V_11 -> V_20 , L_77 ) ;
F_141 ( V_11 , 0 ) ;
F_142 ( V_11 ) ;
if ( V_11 -> V_23 ) {
V_70 = V_11 -> V_127 ;
V_2 = F_3 ( V_11 -> V_23 ) ;
V_79 = V_2 -> V_80 [ V_70 - 1 ] ;
F_143 ( & V_11 -> V_20 . V_341 , L_78 ) ;
F_143 ( & V_79 -> V_20 . V_341 , L_79 ) ;
if ( ! F_144 ( V_70 , V_2 -> V_342 ) )
F_145 ( & V_79 -> V_20 ) ;
}
F_146 ( & V_11 -> V_343 ) ;
F_147 ( V_11 ) ;
F_148 ( & V_11 -> V_20 ) ;
F_136 ( V_11 ) ;
F_111 ( & V_289 ) ;
* V_340 = NULL ;
F_113 ( & V_289 ) ;
if ( V_79 && F_149 ( V_70 , V_2 -> V_342 ) )
F_105 ( & V_79 -> V_20 ) ;
F_138 ( V_11 ) ;
F_150 ( & V_11 -> V_20 ) ;
}
static void F_151 ( struct V_7 * V_11 , char * V_292 , char * string )
{
if ( ! string )
return;
F_7 ( & V_11 -> V_20 , L_80 , V_292 , string ) ;
}
static void F_152 ( struct V_7 * V_11 )
{
F_7 ( & V_11 -> V_20 , L_81 ,
F_12 ( V_11 -> V_34 . V_344 ) ,
F_12 ( V_11 -> V_34 . V_345 ) ) ;
F_7 ( & V_11 -> V_20 ,
L_82 ,
V_11 -> V_34 . V_346 ,
V_11 -> V_34 . V_347 ,
V_11 -> V_34 . V_348 ) ;
F_151 ( V_11 , L_83 , V_11 -> V_349 ) ;
F_151 ( V_11 , L_84 , V_11 -> V_350 ) ;
F_151 ( V_11 , L_85 , V_11 -> V_351 ) ;
}
static inline void F_152 ( struct V_7 * V_11 ) { }
static int F_153 ( struct V_7 * V_11 )
{
int V_352 = 0 ;
#ifdef F_154
if ( ! V_11 -> V_171 -> V_353
&& V_11 -> V_354
&& V_11 -> V_23 == V_11 -> V_171 -> V_273 ) {
struct V_355 * V_281 = NULL ;
struct V_333 * V_171 = V_11 -> V_171 ;
if ( F_155 ( V_11 -> V_356 [ 0 ] ,
F_12 ( V_11 -> V_354 [ 0 ] . V_281 . V_357 ) ,
V_358 , ( void * * ) & V_281 ) == 0 ) {
if ( V_281 -> V_18 & V_359 ) {
unsigned V_70 = V_11 -> V_127 ;
F_7 ( & V_11 -> V_20 ,
L_86 ,
( V_70 == V_171 -> V_360 )
? L_40 : L_87 ) ;
if ( V_70 == V_171 -> V_360 )
V_171 -> V_361 = 1 ;
V_352 = F_14 ( V_11 ,
F_17 ( V_11 , 0 ) ,
V_72 , 0 ,
V_171 -> V_361
? V_362
: V_363 ,
0 , NULL , 0 , V_201 ) ;
if ( V_352 < 0 ) {
F_7 ( & V_11 -> V_20 ,
L_88 ,
V_352 ) ;
V_171 -> V_361 = 0 ;
}
}
}
}
#endif
return V_352 ;
}
static int F_156 ( struct V_7 * V_11 )
{
int V_352 ;
struct V_191 * V_157 = F_60 ( V_11 -> V_171 ) ;
if ( V_11 -> V_354 == NULL ) {
V_352 = F_157 ( V_11 ) ;
if ( V_352 < 0 ) {
if ( V_352 != - V_114 )
F_30 ( & V_11 -> V_20 , L_89 ,
V_352 ) ;
return V_352 ;
}
}
V_11 -> V_349 = F_158 ( V_11 , V_11 -> V_34 . V_347 ) ;
V_11 -> V_350 = F_158 ( V_11 ,
V_11 -> V_34 . V_346 ) ;
V_11 -> V_351 = F_158 ( V_11 , V_11 -> V_34 . V_348 ) ;
V_352 = F_153 ( V_11 ) ;
if ( V_352 < 0 )
return V_352 ;
if ( F_159 ( V_364 ) && V_157 -> V_365 &&
! F_160 ( V_11 ) ) {
if ( F_159 ( F_154 ) && ( V_11 -> V_171 -> V_361
|| V_11 -> V_171 -> V_353 ) ) {
V_352 = F_161 ( V_11 , V_366 ) ;
if ( V_352 < 0 )
F_22 ( & V_11 -> V_20 , L_90 , V_352 ) ;
}
return - V_367 ;
}
F_162 ( V_11 ) ;
return 0 ;
}
static void F_163 ( struct V_7 * V_11 )
{
struct V_7 * V_4 = V_11 -> V_23 ;
struct V_1 * V_2 ;
T_2 V_113 = V_11 -> V_127 ;
T_1 V_238 ;
bool V_368 = true ;
if ( ! V_4 )
return;
V_2 = F_3 ( V_11 -> V_23 ) ;
switch ( V_2 -> V_80 [ V_11 -> V_127 - 1 ] -> V_369 ) {
case V_370 :
V_11 -> V_368 = V_371 ;
return;
case V_372 :
case V_373 :
V_11 -> V_368 = V_374 ;
return;
default:
break;
}
V_238 = F_12 ( V_2 -> V_34 -> V_238 ) ;
if ( ! ( V_238 & V_247 ) )
return;
if ( F_2 ( V_4 ) ) {
if ( F_12 ( V_2 -> V_34 -> V_35 . V_36 . V_250 )
& ( 1 << V_113 ) )
V_368 = false ;
} else {
if ( V_2 -> V_34 -> V_35 . V_249 . V_250 [ V_113 / 8 ] & ( 1 << ( V_113 % 8 ) ) )
V_368 = false ;
}
if ( V_368 )
V_11 -> V_368 = V_371 ;
else
V_11 -> V_368 = V_374 ;
}
int F_164 ( struct V_7 * V_11 )
{
int V_352 ;
if ( V_11 -> V_23 ) {
F_165 ( & V_11 -> V_20 , 0 ) ;
}
F_166 ( & V_11 -> V_20 ) ;
F_167 ( & V_11 -> V_20 ) ;
F_168 ( & V_11 -> V_20 ) ;
F_169 ( & V_11 -> V_20 ) ;
F_170 ( V_11 ) ;
V_352 = F_156 ( V_11 ) ;
if ( V_352 < 0 )
goto V_244;
F_22 ( & V_11 -> V_20 , L_91 ,
V_11 -> V_169 , V_11 -> V_171 -> V_375 ,
( ( ( V_11 -> V_171 -> V_375 - 1 ) * 128 ) + ( V_11 -> V_169 - 1 ) ) ) ;
V_11 -> V_20 . V_376 = F_171 ( V_377 ,
( ( ( V_11 -> V_171 -> V_375 - 1 ) * 128 ) + ( V_11 -> V_169 - 1 ) ) ) ;
F_152 ( V_11 ) ;
if ( V_11 -> V_351 )
F_172 ( V_11 -> V_351 , strlen ( V_11 -> V_351 ) ) ;
if ( V_11 -> V_349 )
F_172 ( V_11 -> V_349 , strlen ( V_11 -> V_349 ) ) ;
if ( V_11 -> V_350 )
F_172 ( V_11 -> V_350 ,
strlen ( V_11 -> V_350 ) ) ;
F_173 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_23 )
F_163 ( V_11 ) ;
V_352 = F_174 ( & V_11 -> V_20 ) ;
if ( V_352 ) {
F_30 ( & V_11 -> V_20 , L_92 , V_352 ) ;
goto V_244;
}
if ( V_11 -> V_23 ) {
struct V_1 * V_2 = F_3 ( V_11 -> V_23 ) ;
int V_70 = V_11 -> V_127 ;
struct V_78 * V_79 = V_2 -> V_80 [ V_70 - 1 ] ;
V_352 = F_175 ( & V_11 -> V_20 . V_341 ,
& V_79 -> V_20 . V_341 , L_78 ) ;
if ( V_352 )
goto V_244;
V_352 = F_175 ( & V_79 -> V_20 . V_341 ,
& V_11 -> V_20 . V_341 , L_79 ) ;
if ( V_352 ) {
F_143 ( & V_11 -> V_20 . V_341 , L_78 ) ;
goto V_244;
}
if ( ! F_144 ( V_70 , V_2 -> V_342 ) )
F_145 ( & V_79 -> V_20 ) ;
}
( void ) F_176 ( & V_11 -> V_20 , & V_11 -> V_343 , V_11 ) ;
F_177 ( V_11 ) ;
F_178 ( & V_11 -> V_20 ) ;
return V_352 ;
V_244:
F_73 ( V_11 , V_186 ) ;
F_179 ( & V_11 -> V_20 ) ;
F_180 ( & V_11 -> V_20 ) ;
return V_352 ;
}
int F_181 ( struct V_7 * V_378 )
{
F_140 ( V_378 ) ;
if ( V_378 -> V_379 == 0 )
goto V_380;
V_378 -> V_379 = 0 ;
F_182 ( V_378 , - 1 ) ;
V_380:
F_147 ( V_378 ) ;
return 0 ;
}
int F_183 ( struct V_7 * V_378 )
{
int V_381 = 0 , V_382 ;
F_140 ( V_378 ) ;
if ( V_378 -> V_379 == 1 )
goto V_383;
V_381 = F_184 ( V_378 ) ;
if ( V_381 < 0 ) {
F_30 ( & V_378 -> V_20 ,
L_93 , V_381 ) ;
goto V_384;
}
if ( V_378 -> V_335 ) {
V_381 = F_185 ( V_378 , sizeof( V_378 -> V_34 ) ) ;
if ( V_381 < 0 ) {
F_30 ( & V_378 -> V_20 , L_94
L_95 , V_381 ) ;
goto V_385;
}
}
V_378 -> V_379 = 1 ;
V_382 = F_186 ( V_378 ) ;
if ( V_382 >= 0 ) {
V_381 = F_182 ( V_378 , V_382 ) ;
if ( V_381 ) {
F_30 ( & V_378 -> V_20 ,
L_96 , V_382 , V_381 ) ;
}
}
F_7 ( & V_378 -> V_20 , L_97 ) ;
V_385:
F_187 ( V_378 ) ;
V_384:
V_383:
F_147 ( V_378 ) ;
return V_381 ;
}
static unsigned F_188 ( struct V_1 * V_2 )
{
struct V_191 * V_157 ;
if ( V_2 -> V_4 -> V_23 != NULL )
return 0 ;
V_157 = F_24 ( V_2 -> V_4 -> V_171 , struct V_191 , V_386 ) ;
return V_157 -> V_387 ;
}
static bool F_189 ( struct V_7 * V_11 , int V_388 )
{
if ( V_11 -> V_12 == V_50 )
return false ;
return F_190 ( V_388 ) ;
}
static bool F_191 ( struct V_1 * V_2 , int V_70 ,
T_1 V_3 )
{
T_1 V_389 ;
if ( ! F_2 ( V_2 -> V_4 ) )
return false ;
if ( F_65 ( V_70 , V_2 -> V_390 ) )
return true ;
V_389 = V_3 & V_179 ;
return V_389 == V_391
|| V_389 == V_392 ;
}
static int F_192 ( struct V_1 * V_2 , int V_70 ,
struct V_7 * V_11 , unsigned int V_193 , bool V_393 )
{
int V_394 , V_55 ;
T_1 V_3 ;
T_1 V_178 ;
for ( V_394 = 0 ;
V_394 < V_395 ;
V_394 += V_193 ) {
F_66 ( V_193 ) ;
V_55 = F_28 ( V_2 , V_70 , & V_3 , & V_178 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( ! ( V_3 & V_396 ) )
break;
if ( V_394 >= 2 * V_397 )
V_193 = V_398 ;
F_22 ( & V_2 -> V_80 [ V_70 - 1 ] -> V_20 ,
L_98 ,
V_393 ? L_99 : L_40 , V_193 ) ;
}
if ( ( V_3 & V_396 ) )
return - V_322 ;
if ( F_191 ( V_2 , V_70 , V_3 ) )
return - V_399 ;
if ( ! ( V_3 & V_208 ) )
return - V_399 ;
if ( ! F_2 ( V_2 -> V_4 ) &&
( V_178 & V_210 ) )
return - V_399 ;
if ( ! ( V_3 & V_209 ) )
return - V_322 ;
if ( ! V_11 )
return 0 ;
if ( F_188 ( V_2 ) )
V_11 -> V_12 = V_400 ;
else if ( F_2 ( V_2 -> V_4 ) )
V_11 -> V_12 = V_50 ;
else if ( V_3 & V_5 )
V_11 -> V_12 = V_13 ;
else if ( V_3 & V_6 )
V_11 -> V_12 = V_401 ;
else
V_11 -> V_12 = V_14 ;
return 0 ;
}
static int F_193 ( struct V_1 * V_2 , int V_70 ,
struct V_7 * V_11 , unsigned int V_193 , bool V_393 )
{
int V_54 , V_81 ;
T_1 V_178 , V_3 ;
struct V_78 * V_79 = V_2 -> V_80 [ V_70 - 1 ] ;
if ( ! F_2 ( V_2 -> V_4 ) ) {
if ( V_393 ) {
F_30 ( V_2 -> V_115 , L_100
L_101 ) ;
return - V_67 ;
}
F_194 ( & V_402 ) ;
} else if ( ! V_393 ) {
if ( F_28 ( V_2 , V_70 , & V_3 , & V_178 ) == 0 )
if ( F_191 ( V_2 , V_70 ,
V_3 ) )
V_393 = true ;
}
F_54 ( V_70 , V_2 -> V_390 ) ;
for ( V_54 = 0 ; V_54 < V_403 ; V_54 ++ ) {
V_81 = F_19 ( V_2 -> V_4 , V_70 , ( V_393 ?
V_404 :
V_405 ) ) ;
if ( V_81 == - V_114 ) {
;
} else if ( V_81 ) {
F_30 ( & V_79 -> V_20 ,
L_102 ,
V_393 ? L_99 : L_40 , V_81 ) ;
} else {
V_81 = F_192 ( V_2 , V_70 , V_11 , V_193 ,
V_393 ) ;
if ( V_81 && V_81 != - V_399 && V_81 != - V_114 )
F_22 ( V_2 -> V_115 ,
L_103 ,
V_81 ) ;
}
if ( V_81 == 0 || V_81 == - V_399 || V_81 == - V_114 ) {
F_18 ( V_2 -> V_4 , V_70 ,
V_215 ) ;
if ( ! F_2 ( V_2 -> V_4 ) )
goto V_406;
F_18 ( V_2 -> V_4 , V_70 ,
V_217 ) ;
F_18 ( V_2 -> V_4 , V_70 ,
V_407 ) ;
F_18 ( V_2 -> V_4 , V_70 ,
V_211 ) ;
if ( F_28 ( V_2 , V_70 ,
& V_3 , & V_178 ) < 0 )
goto V_406;
if ( ! F_191 ( V_2 , V_70 ,
V_3 ) )
goto V_406;
if ( ! V_393 ) {
F_22 ( & V_79 -> V_20 ,
L_104 ) ;
V_393 = true ;
}
}
F_22 ( & V_79 -> V_20 ,
L_105 ,
V_393 ? L_99 : L_40 ) ;
V_193 = V_398 ;
}
F_30 ( & V_79 -> V_20 , L_106 ) ;
V_406:
if ( V_81 == 0 ) {
F_66 ( 10 + 40 ) ;
if ( V_11 ) {
struct V_191 * V_157 = F_60 ( V_11 -> V_171 ) ;
F_137 ( V_11 , 0 ) ;
if ( V_157 -> V_158 -> V_408 )
V_157 -> V_158 -> V_408 ( V_157 , V_11 ) ;
F_73 ( V_11 , V_409 ) ;
}
} else {
if ( V_11 )
F_73 ( V_11 , V_186 ) ;
}
if ( ! F_2 ( V_2 -> V_4 ) )
F_195 ( & V_402 ) ;
return V_81 ;
}
static int F_196 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_55 = 0 ;
if ( F_2 ( V_2 -> V_4 ) ) {
if ( V_3 & V_410 )
V_55 = 1 ;
} else {
if ( V_3 & V_411 )
V_55 = 1 ;
}
return V_55 ;
}
static void F_197 ( struct V_78 * V_79 )
__acquires( &port_dev->status_lock
static void F_198 ( struct V_78 * V_79 )
__releases( &port_dev->status_lock
static int F_199 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_55 = 0 ;
if ( F_2 ( V_2 -> V_4 ) ) {
if ( ( V_3 & V_179 )
== V_412 )
V_55 = 1 ;
} else {
if ( V_3 & V_413 )
V_55 = 1 ;
}
return V_55 ;
}
static int F_200 ( struct V_7 * V_11 ,
struct V_1 * V_2 , int V_70 ,
int V_81 , T_1 V_178 , T_1 V_3 )
{
struct V_78 * V_79 = V_2 -> V_80 [ V_70 - 1 ] ;
int V_414 = 3 ;
V_388:
if ( V_81 == 0 && V_11 -> V_222
&& F_191 ( V_2 , V_70 , V_3 ) ) {
;
}
else if ( V_81 || F_199 ( V_2 , V_3 ) ||
! F_196 ( V_2 , V_3 ) ) {
if ( V_81 >= 0 )
V_81 = - V_114 ;
} else if ( ! ( V_3 & V_208 ) ) {
if ( V_414 -- ) {
F_201 ( 200 , 300 ) ;
V_81 = F_28 ( V_2 , V_70 , & V_3 ,
& V_178 ) ;
goto V_388;
}
V_81 = - V_114 ;
}
else if ( ! ( V_3 & V_209 ) && ! V_11 -> V_222 ) {
if ( V_11 -> V_221 )
V_11 -> V_222 = 1 ;
else
V_81 = - V_114 ;
}
if ( V_81 ) {
F_22 ( & V_79 -> V_20 , L_107 ,
V_178 , V_3 , V_81 ) ;
} else if ( V_11 -> V_222 ) {
if ( V_178 & V_210 )
F_18 ( V_2 -> V_4 , V_70 ,
V_211 ) ;
if ( V_178 & V_212 )
F_18 ( V_2 -> V_4 , V_70 ,
V_213 ) ;
}
return V_81 ;
}
int F_202 ( struct V_7 * V_11 )
{
struct V_191 * V_157 = F_60 ( V_11 -> V_171 ) ;
if ( ! F_203 ( V_157 -> V_386 . V_273 ) ||
! F_203 ( V_11 ) )
return 0 ;
if ( ! V_11 -> V_8 )
return 0 ;
return F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_69 , V_272 ,
V_415 , 0 , NULL , 0 ,
V_201 ) ;
}
void F_204 ( struct V_7 * V_11 )
{
struct V_191 * V_157 = F_60 ( V_11 -> V_171 ) ;
if ( ! F_203 ( V_157 -> V_386 . V_273 ) ||
! F_203 ( V_11 ) )
return;
if ( ! V_11 -> V_8 )
return;
F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_72 , V_272 ,
V_415 , 0 , NULL , 0 ,
V_201 ) ;
}
static int F_205 ( struct V_7 * V_11 )
{
if ( V_11 -> V_12 < V_50 )
return F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_72 , V_272 ,
V_416 , 0 , NULL , 0 ,
V_201 ) ;
else
return F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_72 , V_417 ,
V_418 ,
V_419 |
V_420 ,
NULL , 0 , V_201 ) ;
}
static int F_206 ( struct V_7 * V_11 )
{
if ( V_11 -> V_12 < V_50 )
return F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_69 , V_272 ,
V_416 , 0 , NULL , 0 ,
V_201 ) ;
else
return F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_69 , V_417 ,
V_418 , 0 , NULL , 0 ,
V_201 ) ;
}
static unsigned F_207 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_3 ( V_11 ) ;
return V_11 -> V_421 +
( V_2 ? V_2 -> F_207 : 0 ) ;
}
int F_161 ( struct V_7 * V_11 , T_3 V_422 )
{
struct V_1 * V_2 = F_3 ( V_11 -> V_23 ) ;
struct V_78 * V_79 = V_2 -> V_80 [ V_11 -> V_127 - 1 ] ;
int V_70 = V_11 -> V_127 ;
int V_81 ;
bool V_423 = true ;
F_197 ( V_79 ) ;
if ( V_11 -> V_421 ) {
V_81 = F_205 ( V_11 ) ;
if ( V_81 ) {
F_22 ( & V_11 -> V_20 , L_108 ,
V_81 ) ;
if ( F_208 ( V_422 ) )
goto V_424;
}
}
if ( V_11 -> V_425 == 1 )
F_209 ( V_11 , 0 ) ;
if ( F_202 ( V_11 ) ) {
F_30 ( & V_11 -> V_20 , L_109 ) ;
V_81 = - V_166 ;
if ( F_208 ( V_422 ) )
goto V_426;
}
if ( F_210 ( V_11 ) ) {
F_30 ( & V_11 -> V_20 , L_110 ) ;
V_81 = - V_166 ;
if ( F_208 ( V_422 ) )
goto V_427;
}
if ( F_2 ( V_2 -> V_4 ) )
V_81 = F_69 ( V_2 , V_70 , V_412 ) ;
else if ( F_208 ( V_422 ) || F_207 ( V_11 ) > 0 )
V_81 = F_19 ( V_2 -> V_4 , V_70 ,
V_428 ) ;
else {
V_423 = false ;
V_81 = 0 ;
}
if ( V_81 ) {
F_22 ( & V_79 -> V_20 , L_111 , V_81 ) ;
F_211 ( V_11 ) ;
V_427:
F_204 ( V_11 ) ;
V_426:
if ( V_11 -> V_429 == 1 )
F_209 ( V_11 , 1 ) ;
if ( V_11 -> V_421 )
( void ) F_206 ( V_11 ) ;
V_424:
if ( ! F_208 ( V_422 ) )
V_81 = 0 ;
} else {
F_22 ( & V_11 -> V_20 , L_112 ,
( F_208 ( V_422 ) ? L_113 : L_40 ) ,
V_11 -> V_421 ) ;
if ( V_423 ) {
V_11 -> F_199 = 1 ;
F_66 ( 10 ) ;
}
F_73 ( V_11 , V_324 ) ;
}
if ( V_81 == 0 && ! V_11 -> V_421 && V_11 -> V_221
&& F_149 ( V_70 , V_2 -> V_342 ) )
F_212 ( & V_79 -> V_20 ) ;
F_177 ( V_2 -> V_4 ) ;
F_198 ( V_79 ) ;
return V_81 ;
}
static int F_213 ( struct V_7 * V_11 )
{
int V_81 = 0 ;
T_1 V_430 = 0 ;
F_22 ( & V_11 -> V_20 , L_114 ,
V_11 -> V_222 ? L_115 : L_116 ) ;
F_73 ( V_11 , V_11 -> V_8
? V_89
: V_431 ) ;
if ( V_11 -> V_222 ) {
V_432:
if ( V_11 -> V_330 & V_433 )
V_81 = - V_114 ;
else
V_81 = F_214 ( V_11 ) ;
}
if ( V_81 == 0 ) {
V_430 = 0 ;
V_81 = F_98 ( V_11 , V_272 , 0 , & V_430 ) ;
if ( V_81 && ! V_11 -> V_222 && V_11 -> V_221 ) {
F_22 ( & V_11 -> V_20 , L_117 ) ;
V_11 -> V_222 = 1 ;
goto V_432;
}
}
if ( V_81 ) {
F_22 ( & V_11 -> V_20 , L_118 ,
V_81 ) ;
} else if ( V_11 -> V_8 && ! V_11 -> V_222 ) {
if ( V_11 -> V_12 < V_50 ) {
if ( V_430 & ( 1 << V_416 ) )
V_81 = F_206 ( V_11 ) ;
} else {
V_81 = F_98 ( V_11 , V_417 , 0 ,
& V_430 ) ;
if ( ! V_81 && V_430 & ( V_434
| V_435 ) )
V_81 = F_206 ( V_11 ) ;
}
if ( V_81 )
F_22 ( & V_11 -> V_20 ,
L_119 ,
V_81 ) ;
V_81 = 0 ;
}
return V_81 ;
}
static int F_215 ( struct V_7 * V_11 ,
struct V_1 * V_2 , int * V_70 ,
T_1 * V_178 , T_1 * V_3 )
{
int V_81 = 0 , V_436 = 0 ;
while ( V_436 < 2000 ) {
if ( V_81 || * V_3 & V_208 )
break;
F_66 ( 20 ) ;
V_436 += 20 ;
V_81 = F_28 ( V_2 , * V_70 , V_3 , V_178 ) ;
}
return V_81 ;
}
int F_216 ( struct V_7 * V_11 , T_3 V_422 )
{
struct V_1 * V_2 = F_3 ( V_11 -> V_23 ) ;
struct V_78 * V_79 = V_2 -> V_80 [ V_11 -> V_127 - 1 ] ;
int V_70 = V_11 -> V_127 ;
int V_81 ;
T_1 V_178 , V_3 ;
if ( ! F_144 ( V_70 , V_2 -> V_342 ) ) {
V_81 = F_145 ( & V_79 -> V_20 ) ;
if ( V_81 < 0 ) {
F_22 ( & V_11 -> V_20 , L_120 ,
V_81 ) ;
return V_81 ;
}
}
F_197 ( V_79 ) ;
V_81 = F_28 ( V_2 , V_70 , & V_3 , & V_178 ) ;
if ( V_81 == 0 && ! F_199 ( V_2 , V_3 ) )
goto V_437;
if ( F_2 ( V_2 -> V_4 ) )
V_81 = F_69 ( V_2 , V_70 , V_220 ) ;
else
V_81 = F_18 ( V_2 -> V_4 ,
V_70 , V_428 ) ;
if ( V_81 ) {
F_22 ( & V_79 -> V_20 , L_121 , V_81 ) ;
} else {
F_22 ( & V_11 -> V_20 , L_122 ,
( F_208 ( V_422 ) ? L_113 : L_40 ) ) ;
F_66 ( V_438 ) ;
V_81 = F_28 ( V_2 , V_70 , & V_3 , & V_178 ) ;
F_66 ( 10 ) ;
}
V_437:
if ( V_81 == 0 ) {
V_11 -> F_199 = 0 ;
if ( F_2 ( V_2 -> V_4 ) ) {
if ( V_178 & V_439 )
F_18 ( V_2 -> V_4 , V_70 ,
V_407 ) ;
} else {
if ( V_178 & V_440 )
F_18 ( V_2 -> V_4 , V_70 ,
V_441 ) ;
}
}
if ( V_11 -> V_221 && F_2 ( V_2 -> V_4 ) )
V_81 = F_215 ( V_11 , V_2 , & V_70 , & V_178 ,
& V_3 ) ;
V_81 = F_200 ( V_11 ,
V_2 , V_70 , V_81 , V_178 , V_3 ) ;
if ( V_81 == 0 )
V_81 = F_213 ( V_11 ) ;
if ( V_81 < 0 ) {
F_22 ( & V_11 -> V_20 , L_121 , V_81 ) ;
F_74 ( V_2 , V_70 ) ;
} else {
if ( V_11 -> V_429 == 1 )
F_209 ( V_11 , 1 ) ;
F_204 ( V_11 ) ;
F_211 ( V_11 ) ;
}
F_198 ( V_79 ) ;
return V_81 ;
}
int F_217 ( struct V_7 * V_11 )
{
int V_81 = 0 ;
F_140 ( V_11 ) ;
if ( V_11 -> V_88 == V_324 ) {
F_22 ( & V_11 -> V_20 , L_122 , L_123 ) ;
V_81 = F_184 ( V_11 ) ;
if ( V_81 == 0 ) {
F_187 ( V_11 ) ;
}
}
F_147 ( V_11 ) ;
return V_81 ;
}
static int F_218 ( struct V_1 * V_2 , unsigned int V_113 ,
T_1 V_3 , T_1 V_178 )
__must_hold( &port_dev->status_lock
static int F_219 ( struct V_1 * V_2 )
{
int V_70 ;
for ( V_70 = 1 ; V_70 <= V_2 -> V_4 -> V_9 ; ++ V_70 ) {
T_1 V_3 , V_178 ;
int V_81 ;
V_81 = F_28 ( V_2 , V_70 , & V_3 , & V_178 ) ;
if ( ! V_81 && V_178 )
return 1 ;
}
return 0 ;
}
static int F_220 ( struct V_120 * V_121 , T_3 V_422 )
{
struct V_1 * V_2 = F_4 ( V_121 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
unsigned V_70 ;
int V_81 ;
V_2 -> F_207 = 0 ;
for ( V_70 = 1 ; V_70 <= V_4 -> V_9 ; V_70 ++ ) {
struct V_78 * V_79 = V_2 -> V_80 [ V_70 - 1 ] ;
struct V_7 * V_11 = V_79 -> V_185 ;
if ( V_11 && V_11 -> V_442 ) {
F_71 ( & V_79 -> V_20 , L_124 ,
F_221 ( & V_11 -> V_20 ) ) ;
if ( F_208 ( V_422 ) )
return - V_322 ;
}
if ( V_11 )
V_2 -> F_207 +=
F_207 ( V_11 ) ;
}
if ( V_4 -> V_421 && V_2 -> V_308 ) {
if ( F_219 ( V_2 ) ) {
if ( F_208 ( V_422 ) )
return - V_322 ;
F_222 ( & V_4 -> V_20 , 2000 ) ;
}
}
if ( F_2 ( V_4 ) && V_4 -> V_421 ) {
for ( V_70 = 1 ; V_70 <= V_4 -> V_9 ; V_70 ++ ) {
V_81 = F_19 ( V_4 ,
V_70 |
V_443 |
V_444 |
V_445 ,
V_446 ) ;
}
}
F_22 ( & V_121 -> V_20 , L_114 , V_116 ) ;
F_82 ( V_2 , V_228 ) ;
return 0 ;
}
static int F_223 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = F_4 ( V_121 ) ;
F_22 ( & V_121 -> V_20 , L_114 , V_116 ) ;
F_78 ( V_2 , V_198 ) ;
return 0 ;
}
static int F_224 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = F_4 ( V_121 ) ;
F_22 ( & V_121 -> V_20 , L_114 , V_116 ) ;
F_78 ( V_2 , V_205 ) ;
return 0 ;
}
void F_225 ( struct V_7 * V_447 )
{
F_71 ( & V_447 -> V_20 , L_125 ) ;
V_447 -> V_222 = 1 ;
}
static int F_226 ( struct V_7 * V_11 , enum V_448 V_88 )
{
struct V_449 * V_450 ;
unsigned long long V_451 ;
unsigned long long V_452 ;
unsigned long long V_453 ;
unsigned long long V_454 ;
int V_55 ;
if ( V_11 -> V_88 != V_89 )
return 0 ;
V_451 = F_227 ( V_11 -> V_51 . V_44 , 1000 ) ;
V_452 = F_227 ( V_11 -> V_51 . V_41 , 1000 ) ;
V_453 = F_227 ( V_11 -> V_52 . V_44 , 1000 ) ;
V_454 = F_227 ( V_11 -> V_52 . V_41 , 1000 ) ;
if ( ( V_88 == V_455 &&
( V_451 > V_456 ||
V_452 > V_456 ) ) ||
( V_88 == V_457 &&
( V_453 > V_458 ||
V_454 > V_458 ) ) ) {
F_22 ( & V_11 -> V_20 , L_126 ,
V_459 [ V_88 ] , V_451 , V_452 ) ;
return - V_67 ;
}
if ( V_451 > V_456 )
V_451 = V_456 ;
if ( V_452 > V_456 )
V_452 = V_456 ;
if ( V_453 > V_458 )
V_453 = V_458 ;
if ( V_454 > V_458 )
V_454 = V_458 ;
V_450 = F_56 ( sizeof *( V_450 ) , V_207 ) ;
if ( ! V_450 )
return - V_166 ;
V_450 -> V_451 = V_451 ;
V_450 -> V_452 = V_452 ;
V_450 -> V_453 = F_228 ( V_453 ) ;
V_450 -> V_454 = F_228 ( V_454 ) ;
V_55 = F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_460 ,
V_272 ,
0 , 0 ,
V_450 , sizeof *( V_450 ) ,
V_201 ) ;
F_52 ( V_450 ) ;
return V_55 ;
}
static int F_229 ( struct V_7 * V_11 ,
enum V_448 V_88 , bool V_461 )
{
int V_55 ;
int V_68 ;
switch ( V_88 ) {
case V_455 :
V_68 = V_462 ;
break;
case V_457 :
V_68 = V_463 ;
break;
default:
F_71 ( & V_11 -> V_20 , L_127 ,
V_116 , V_461 ? L_128 : L_129 ) ;
return - V_67 ;
}
if ( V_11 -> V_88 != V_89 ) {
F_22 ( & V_11 -> V_20 , L_130
L_131 ,
V_116 , V_461 ? L_128 : L_129 ,
V_459 [ V_88 ] ) ;
return 0 ;
}
if ( V_461 ) {
V_55 = F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_72 ,
V_272 ,
V_68 ,
0 , NULL , 0 ,
V_201 ) ;
} else {
V_55 = F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_69 ,
V_272 ,
V_68 ,
0 , NULL , 0 ,
V_201 ) ;
}
if ( V_55 < 0 ) {
F_71 ( & V_11 -> V_20 , L_132 ,
V_461 ? L_133 : L_134 ,
V_459 [ V_88 ] ) ;
return - V_322 ;
}
return 0 ;
}
static int F_230 ( struct V_7 * V_11 ,
enum V_448 V_88 , int V_464 )
{
int V_55 ;
int V_68 ;
switch ( V_88 ) {
case V_455 :
V_68 = V_465 ;
break;
case V_457 :
V_68 = V_466 ;
break;
default:
F_71 ( & V_11 -> V_20 , L_135 ,
V_116 ) ;
return - V_67 ;
}
if ( V_88 == V_455 && V_464 > V_467 &&
V_464 != V_468 ) {
F_71 ( & V_11 -> V_20 , L_136
L_137 ,
V_459 [ V_88 ] , V_464 ) ;
return - V_67 ;
}
V_55 = F_19 ( V_11 -> V_23 ,
F_231 ( V_464 ) | V_11 -> V_127 ,
V_68 ) ;
if ( V_55 < 0 ) {
F_71 ( & V_11 -> V_20 , L_138
L_139 , V_459 [ V_88 ] ,
V_464 , V_55 ) ;
return - V_322 ;
}
if ( V_88 == V_455 )
V_11 -> V_51 . V_464 = V_464 ;
else
V_11 -> V_52 . V_464 = V_464 ;
return 0 ;
}
static void F_232 ( struct V_191 * V_157 , struct V_7 * V_11 ,
enum V_448 V_88 )
{
int V_464 , V_55 ;
T_4 V_469 = V_11 -> V_15 -> V_19 -> V_21 ;
T_5 V_470 = V_11 -> V_15 -> V_19 -> V_22 ;
if ( ( V_88 == V_455 && V_469 == 0 ) ||
( V_88 == V_457 && V_470 == 0 ) )
return;
V_55 = F_226 ( V_11 , V_88 ) ;
if ( V_55 < 0 ) {
F_71 ( & V_11 -> V_20 , L_140 ,
V_459 [ V_88 ] ) ;
return;
}
V_464 = V_157 -> V_158 -> V_471 ( V_157 , V_11 , V_88 ) ;
if ( V_464 == 0 )
return;
if ( V_464 < 0 ) {
F_71 ( & V_11 -> V_20 , L_141
L_142 , V_459 [ V_88 ] ,
V_464 ) ;
return;
}
if ( F_230 ( V_11 , V_88 , V_464 ) )
V_157 -> V_158 -> V_472 ( V_157 , V_11 , V_88 ) ;
else if ( V_11 -> V_8 )
F_229 ( V_11 , V_88 , true ) ;
}
static int F_233 ( struct V_191 * V_157 , struct V_7 * V_11 ,
enum V_448 V_88 )
{
switch ( V_88 ) {
case V_455 :
case V_457 :
break;
default:
F_71 ( & V_11 -> V_20 , L_143 ,
V_116 ) ;
return - V_67 ;
}
if ( F_230 ( V_11 , V_88 , 0 ) )
return - V_322 ;
F_229 ( V_11 , V_88 , false ) ;
if ( V_157 -> V_158 -> V_472 ( V_157 , V_11 , V_88 ) )
F_71 ( & V_11 -> V_20 , L_144
L_145 ,
V_459 [ V_88 ] ) ;
return 0 ;
}
int F_234 ( struct V_7 * V_11 )
{
struct V_191 * V_157 ;
if ( ! V_11 || ! V_11 -> V_23 ||
V_11 -> V_12 != V_50 ||
! V_11 -> V_24 ||
V_11 -> V_88 < V_409 )
return 0 ;
V_157 = F_60 ( V_11 -> V_171 ) ;
if ( ! V_157 || ! V_157 -> V_158 -> V_472 )
return 0 ;
V_11 -> V_473 ++ ;
if ( ( V_11 -> V_51 . V_464 == 0 && V_11 -> V_52 . V_464 == 0 ) )
return 0 ;
if ( F_233 ( V_157 , V_11 , V_455 ) )
goto V_474;
if ( F_233 ( V_157 , V_11 , V_457 ) )
goto V_474;
return 0 ;
V_474:
F_235 ( V_11 ) ;
return - V_322 ;
}
int F_210 ( struct V_7 * V_11 )
{
struct V_191 * V_157 = F_60 ( V_11 -> V_171 ) ;
int V_55 ;
if ( ! V_157 )
return - V_67 ;
F_29 ( V_157 -> V_475 ) ;
V_55 = F_234 ( V_11 ) ;
F_31 ( V_157 -> V_475 ) ;
return V_55 ;
}
void F_235 ( struct V_7 * V_11 )
{
struct V_191 * V_157 ;
if ( ! V_11 || ! V_11 -> V_23 ||
V_11 -> V_12 != V_50 ||
! V_11 -> V_24 ||
V_11 -> V_88 < V_409 )
return;
V_11 -> V_473 -- ;
V_157 = F_60 ( V_11 -> V_171 ) ;
if ( ! V_157 || ! V_157 -> V_158 -> V_471 ||
! V_157 -> V_158 -> V_472 )
return;
if ( V_11 -> V_473 > 0 )
return;
F_232 ( V_157 , V_11 , V_455 ) ;
F_232 ( V_157 , V_11 , V_457 ) ;
}
void F_211 ( struct V_7 * V_11 )
{
struct V_191 * V_157 = F_60 ( V_11 -> V_171 ) ;
if ( ! V_157 )
return;
F_29 ( V_157 -> V_475 ) ;
F_235 ( V_11 ) ;
F_31 ( V_157 -> V_475 ) ;
}
int F_234 ( struct V_7 * V_11 )
{
return 0 ;
}
void F_235 ( struct V_7 * V_11 ) { }
int F_210 ( struct V_7 * V_11 )
{
return 0 ;
}
void F_211 ( struct V_7 * V_11 ) { }
int F_202 ( struct V_7 * V_11 )
{
return 0 ;
}
void F_204 ( struct V_7 * V_11 ) { }
static int F_218 ( struct V_1 * V_2 , unsigned int V_113 ,
T_1 V_3 , T_1 V_178 )
{
return 0 ;
}
int F_236 ( struct V_1 * V_2 , int V_70 , bool V_476 )
{
int V_55 ;
T_1 V_178 , V_3 ;
unsigned V_477 = 0xffff ;
int V_177 , V_478 = 0 ;
struct V_78 * V_79 = V_2 -> V_80 [ V_70 - 1 ] ;
for ( V_177 = 0 ; ; V_177 += V_182 ) {
V_55 = F_28 ( V_2 , V_70 , & V_3 , & V_178 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( ! ( V_178 & V_210 ) &&
( V_3 & V_208 ) == V_477 ) {
if ( ! V_476 ||
( V_477 == V_208 ) )
V_478 += V_182 ;
if ( V_478 >= V_223 )
break;
} else {
V_478 = 0 ;
V_477 = V_3 & V_208 ;
}
if ( V_178 & V_210 ) {
F_18 ( V_2 -> V_4 , V_70 ,
V_211 ) ;
}
if ( V_177 >= V_183 )
break;
F_66 ( V_182 ) ;
}
F_22 ( & V_79 -> V_20 , L_146 ,
V_177 , V_478 , V_3 ) ;
if ( V_478 < V_223 )
return - V_105 ;
return V_3 ;
}
void F_237 ( struct V_7 * V_11 )
{
F_238 ( V_11 , 0 + V_63 , true ) ;
F_238 ( V_11 , 0 + V_479 , true ) ;
F_239 ( V_11 , & V_11 -> V_343 , true ) ;
}
static int F_240 ( struct V_7 * V_11 , int V_169 )
{
int V_480 ;
struct V_191 * V_157 = F_60 ( V_11 -> V_171 ) ;
if ( ! V_157 -> V_158 -> V_481 && V_169 <= 1 )
return - V_67 ;
if ( V_11 -> V_88 == V_431 )
return 0 ;
if ( V_11 -> V_88 != V_409 )
return - V_67 ;
if ( V_157 -> V_158 -> V_481 )
V_480 = V_157 -> V_158 -> V_481 ( V_157 , V_11 ) ;
else
V_480 = F_14 ( V_11 , F_241 () ,
V_482 , 0 , V_169 , 0 ,
NULL , 0 , V_201 ) ;
if ( V_480 == 0 ) {
F_137 ( V_11 , V_169 ) ;
F_73 ( V_11 , V_431 ) ;
F_237 ( V_11 ) ;
}
return V_480 ;
}
static void F_242 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_3 ( V_11 -> V_23 ) ;
int V_369 = V_483 ;
if ( ! V_11 -> V_429 )
return;
if ( V_2 )
V_369 = V_2 -> V_80 [ V_11 -> V_127 - 1 ] -> V_369 ;
if ( ( V_11 -> V_15 -> V_16 -> V_18 & F_243 ( V_484 ) ) ||
V_369 == V_372 ) {
V_11 -> V_485 = 1 ;
F_209 ( V_11 , 1 ) ;
}
}
static int F_244 ( struct V_7 * V_11 )
{
struct V_191 * V_157 = F_60 ( V_11 -> V_171 ) ;
if ( ! V_157 -> V_158 -> V_486 )
return 0 ;
if ( V_11 -> V_88 == V_431 )
return 0 ;
if ( V_11 -> V_88 != V_409 )
return - V_67 ;
return V_157 -> V_158 -> V_486 ( V_157 , V_11 ) ;
}
static int
F_245 ( struct V_1 * V_2 , struct V_7 * V_11 , int V_70 ,
int V_487 )
{
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_191 * V_157 = F_60 ( V_4 -> V_171 ) ;
int V_54 , V_488 , V_480 ;
unsigned V_193 = V_397 ;
enum V_489 V_490 = V_11 -> V_12 ;
const char * V_12 ;
int V_169 = V_11 -> V_169 ;
if ( ! V_4 -> V_23 ) {
V_193 = V_491 ;
if ( V_70 == V_4 -> V_171 -> V_360 )
V_4 -> V_171 -> V_361 = 0 ;
}
if ( V_490 == V_401 )
V_193 = V_398 ;
F_29 ( & V_4 -> V_171 -> V_334 ) ;
V_480 = F_193 ( V_2 , V_70 , V_11 , V_193 , false ) ;
if ( V_480 < 0 )
goto V_244;
V_480 = - V_114 ;
if ( V_490 != V_492 && V_490 != V_11 -> V_12 ) {
F_22 ( & V_11 -> V_20 , L_147 ) ;
goto V_244;
}
V_490 = V_11 -> V_12 ;
switch ( V_11 -> V_12 ) {
case V_50 :
case V_400 :
V_11 -> V_343 . V_281 . V_493 = F_228 ( 512 ) ;
break;
case V_13 :
V_11 -> V_343 . V_281 . V_493 = F_228 ( 64 ) ;
break;
case V_14 :
V_11 -> V_343 . V_281 . V_493 = F_228 ( 64 ) ;
break;
case V_401 :
V_11 -> V_343 . V_281 . V_493 = F_228 ( 8 ) ;
break;
default:
goto V_244;
}
if ( V_11 -> V_12 == V_400 )
V_12 = L_148 ;
else
V_12 = F_246 ( V_11 -> V_12 ) ;
if ( V_11 -> V_12 != V_50 )
F_7 ( & V_11 -> V_20 ,
L_149 ,
( V_11 -> V_354 ) ? L_150 : L_151 , V_12 ,
V_169 , V_11 -> V_171 -> V_494 -> V_158 -> V_495 ) ;
if ( V_4 -> V_143 ) {
V_11 -> V_143 = V_4 -> V_143 ;
V_11 -> V_168 = V_4 -> V_168 ;
} else if ( V_11 -> V_12 != V_13
&& V_4 -> V_12 == V_13 ) {
if ( ! V_2 -> V_143 . V_2 ) {
F_30 ( & V_11 -> V_20 , L_152 ) ;
V_480 = - V_67 ;
goto V_244;
}
V_11 -> V_143 = & V_2 -> V_143 ;
V_11 -> V_168 = V_70 ;
}
for ( V_54 = 0 ; V_54 < V_496 ; ( ++ V_54 , F_66 ( 100 ) ) ) {
bool V_497 = false ;
if ( F_189 ( V_11 , V_487 ) ) {
struct V_498 * V_499 ;
int V_500 = 0 ;
V_497 = true ;
V_480 = F_244 ( V_11 ) ;
if ( V_480 < 0 ) {
F_30 ( & V_11 -> V_20 ,
L_153 ,
V_480 ) ;
goto V_244;
}
#define F_247 64
V_499 = F_56 ( F_247 , V_207 ) ;
if ( ! V_499 ) {
V_480 = - V_166 ;
continue;
}
for ( V_488 = 0 ; V_488 < 3 ; ++ V_488 ) {
V_499 -> V_501 = 0 ;
V_500 = F_14 ( V_11 , F_248 () ,
V_62 , V_63 ,
V_502 << 8 , 0 ,
V_499 , F_247 ,
V_503 ) ;
switch ( V_499 -> V_501 ) {
case 8 : case 16 : case 32 : case 64 : case 255 :
if ( V_499 -> V_504 ==
V_502 ) {
V_500 = 0 ;
break;
}
default:
if ( V_500 == 0 )
V_500 = - V_505 ;
break;
}
if ( V_500 == 0 )
break;
}
V_11 -> V_34 . V_501 =
V_499 -> V_501 ;
F_52 ( V_499 ) ;
V_480 = F_193 ( V_2 , V_70 , V_11 , V_193 , false ) ;
if ( V_480 < 0 )
goto V_244;
if ( V_490 != V_11 -> V_12 ) {
F_22 ( & V_11 -> V_20 ,
L_147 ) ;
V_480 = - V_114 ;
goto V_244;
}
if ( V_500 ) {
if ( V_500 != - V_114 )
F_30 ( & V_11 -> V_20 , L_154 ,
V_500 ) ;
V_480 = - V_506 ;
continue;
}
#undef F_247
}
if ( V_11 -> V_335 == 0 ) {
for ( V_488 = 0 ; V_488 < V_507 ; ++ V_488 ) {
V_480 = F_240 ( V_11 , V_169 ) ;
if ( V_480 >= 0 )
break;
F_66 ( 200 ) ;
}
if ( V_480 < 0 ) {
if ( V_480 != - V_114 )
F_30 ( & V_11 -> V_20 , L_155 ,
V_169 , V_480 ) ;
goto V_244;
}
if ( V_11 -> V_12 == V_50 ) {
V_169 = V_11 -> V_169 ;
F_7 ( & V_11 -> V_20 ,
L_156 ,
( V_11 -> V_354 ) ? L_150 : L_151 ,
V_169 , V_11 -> V_171 -> V_494 -> V_158 -> V_495 ) ;
}
F_66 ( 10 ) ;
if ( V_497 )
break;
}
V_480 = F_185 ( V_11 , 8 ) ;
if ( V_480 < 8 ) {
if ( V_480 != - V_114 )
F_30 ( & V_11 -> V_20 ,
L_157 ,
V_480 ) ;
if ( V_480 >= 0 )
V_480 = - V_506 ;
} else {
V_480 = 0 ;
break;
}
}
if ( V_480 )
goto V_244;
if ( ( V_11 -> V_12 == V_50 ) &&
( F_12 ( V_11 -> V_34 . V_508 ) < 0x0300 ) ) {
F_30 ( & V_11 -> V_20 , L_158
L_159 ) ;
F_193 ( V_2 , V_70 , V_11 ,
V_509 , true ) ;
V_480 = - V_67 ;
goto V_244;
}
if ( V_11 -> V_34 . V_501 == 0xff ||
V_11 -> V_12 == V_50 )
V_54 = 512 ;
else
V_54 = V_11 -> V_34 . V_501 ;
if ( F_249 ( & V_11 -> V_343 . V_281 ) != V_54 ) {
if ( V_11 -> V_12 == V_401 ||
! ( V_54 == 8 || V_54 == 16 || V_54 == 32 || V_54 == 64 ) ) {
F_30 ( & V_11 -> V_20 , L_160 , V_54 ) ;
V_480 = - V_506 ;
goto V_244;
}
if ( V_11 -> V_12 == V_14 )
F_22 ( & V_11 -> V_20 , L_161 , V_54 ) ;
else
F_71 ( & V_11 -> V_20 , L_162 , V_54 ) ;
V_11 -> V_343 . V_281 . V_493 = F_228 ( V_54 ) ;
F_237 ( V_11 ) ;
}
V_480 = F_185 ( V_11 , V_510 ) ;
if ( V_480 < ( signed ) sizeof( V_11 -> V_34 ) ) {
if ( V_480 != - V_114 )
F_30 ( & V_11 -> V_20 , L_163 ,
V_480 ) ;
if ( V_480 >= 0 )
V_480 = - V_511 ;
goto V_244;
}
if ( V_11 -> V_335 == 0 && F_12 ( V_11 -> V_34 . V_508 ) >= 0x0201 ) {
V_480 = F_250 ( V_11 ) ;
if ( ! V_480 ) {
V_11 -> V_24 = F_5 ( V_11 ) ;
F_11 ( V_11 ) ;
}
}
V_480 = 0 ;
if ( V_157 -> V_158 -> V_512 )
V_157 -> V_158 -> V_512 ( V_157 , V_11 ) ;
F_242 ( V_11 ) ;
V_244:
if ( V_480 ) {
F_72 ( V_2 , V_70 , 0 ) ;
F_137 ( V_11 , V_169 ) ;
}
F_31 ( & V_4 -> V_171 -> V_334 ) ;
return V_480 ;
}
static void
F_251 ( struct V_1 * V_2 , struct V_7 * V_11 , int V_70 )
{
struct V_513 * V_514 ;
int V_81 ;
if ( V_11 -> V_330 & V_515 )
return;
V_514 = F_56 ( sizeof *V_514 , V_243 ) ;
if ( V_514 == NULL )
return;
V_81 = F_252 ( V_11 , V_516 , 0 ,
V_514 , sizeof *V_514 ) ;
if ( V_81 == sizeof *V_514 ) {
F_7 ( & V_11 -> V_20 , L_164
L_165 ) ;
if ( V_2 -> V_225 ) {
V_2 -> V_92 [ V_70 - 1 ] = V_95 ;
F_25 ( V_102 ,
& V_2 -> V_85 , 0 ) ;
}
}
F_52 ( V_514 ) ;
}
static unsigned
F_253 ( struct V_1 * V_2 )
{
struct V_7 * V_4 = V_2 -> V_4 ;
int V_279 ;
int V_70 ;
if ( ! V_2 -> V_277 )
return 0 ;
V_279 = V_4 -> V_275 - V_2 -> V_34 -> V_280 ;
for ( V_70 = 1 ; V_70 <= V_4 -> V_9 ; ++ V_70 ) {
struct V_78 * V_79 = V_2 -> V_80 [ V_70 - 1 ] ;
struct V_7 * V_11 = V_79 -> V_185 ;
unsigned V_241 ;
int V_517 ;
if ( ! V_11 )
continue;
if ( F_2 ( V_11 ) )
V_241 = 150 ;
else
V_241 = 100 ;
if ( V_11 -> V_8 )
V_517 = F_254 ( V_11 , V_11 -> V_8 ) ;
else if ( V_70 != V_11 -> V_171 -> V_360 || V_4 -> V_23 )
V_517 = V_241 ;
else
V_517 = 8 ;
if ( V_517 > V_2 -> V_276 )
F_71 ( & V_79 -> V_20 , L_166 ,
V_517 , V_2 -> V_276 ) ;
V_279 -= V_517 ;
}
if ( V_279 < 0 ) {
F_71 ( V_2 -> V_115 , L_167 ,
- V_279 ) ;
V_279 = 0 ;
}
return V_279 ;
}
static void F_255 ( struct V_1 * V_2 , int V_70 , T_1 V_3 ,
T_1 V_178 )
{
int V_81 , V_54 ;
unsigned V_241 ;
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_191 * V_157 = F_60 ( V_4 -> V_171 ) ;
struct V_78 * V_79 = V_2 -> V_80 [ V_70 - 1 ] ;
struct V_7 * V_11 = V_79 -> V_185 ;
static int V_518 = - 1 ;
if ( V_11 ) {
if ( V_157 -> V_519 && ! V_4 -> V_23 )
F_256 ( V_157 -> V_519 , V_11 -> V_12 ) ;
F_84 ( & V_79 -> V_185 ) ;
}
if ( ! ( V_3 & V_208 ) ||
( V_178 & V_210 ) )
F_54 ( V_70 , V_2 -> V_189 ) ;
if ( V_178 & ( V_210 |
V_212 ) ) {
V_81 = F_257 ( V_2 , V_70 ) ;
if ( V_81 < 0 ) {
if ( V_81 != - V_114 &&
V_70 != V_518 &&
F_258 () )
F_30 ( & V_79 -> V_20 , L_168 ) ;
V_3 &= ~ V_208 ;
V_518 = V_70 ;
} else {
V_3 = V_81 ;
}
}
if ( ! ( V_3 & V_208 ) ||
F_65 ( V_70 , V_2 -> V_189 ) ) {
if ( F_64 ( V_2 )
&& ! F_196 ( V_2 , V_3 )
&& ! V_79 -> V_318 )
F_19 ( V_4 , V_70 , V_162 ) ;
if ( V_3 & V_209 )
goto V_406;
return;
}
if ( F_2 ( V_2 -> V_4 ) )
V_241 = 150 ;
else
V_241 = 100 ;
V_81 = 0 ;
for ( V_54 = 0 ; V_54 < V_520 ; V_54 ++ ) {
V_11 = F_259 ( V_4 , V_4 -> V_171 , V_70 ) ;
if ( ! V_11 ) {
F_30 ( & V_79 -> V_20 ,
L_169 ) ;
goto V_406;
}
F_73 ( V_11 , V_521 ) ;
V_11 -> V_275 = V_2 -> V_276 ;
V_11 -> V_200 = V_4 -> V_200 + 1 ;
V_11 -> V_335 = F_188 ( V_2 ) ;
if ( F_2 ( V_2 -> V_4 ) )
V_11 -> V_12 = V_50 ;
else
V_11 -> V_12 = V_492 ;
F_133 ( V_11 ) ;
if ( V_11 -> V_169 <= 0 ) {
V_81 = - V_399 ;
goto V_522;
}
F_197 ( V_79 ) ;
V_81 = F_245 ( V_2 , V_11 , V_70 , V_54 ) ;
F_198 ( V_79 ) ;
if ( V_81 < 0 )
goto V_522;
F_260 ( V_11 ) ;
if ( V_11 -> V_330 & V_523 )
F_66 ( 1000 ) ;
if ( V_11 -> V_34 . V_524 == V_525
&& V_11 -> V_275 <= V_241 ) {
T_1 V_526 ;
V_81 = F_98 ( V_11 , V_272 , 0 ,
& V_526 ) ;
if ( V_81 ) {
F_22 ( & V_11 -> V_20 , L_170 , V_81 ) ;
goto V_527;
}
if ( ( V_526 & ( 1 << V_278 ) ) == 0 ) {
F_30 ( & V_11 -> V_20 ,
L_171
L_172 ) ;
if ( V_2 -> V_225 ) {
V_2 -> V_92 [ V_70 - 1 ] =
V_97 ;
F_25 (
V_102 ,
& V_2 -> V_85 , 0 ) ;
}
V_81 = - V_399 ;
goto V_527;
}
}
if ( F_12 ( V_11 -> V_34 . V_508 ) >= 0x0200
&& V_11 -> V_12 == V_14
&& V_290 != 0 )
F_251 ( V_2 , V_11 , V_70 ) ;
V_81 = 0 ;
F_29 ( & V_287 ) ;
F_111 ( & V_289 ) ;
if ( V_4 -> V_88 == V_186 )
V_81 = - V_399 ;
else
V_79 -> V_185 = V_11 ;
F_113 ( & V_289 ) ;
F_31 ( & V_287 ) ;
if ( ! V_81 ) {
V_81 = F_164 ( V_11 ) ;
if ( V_81 ) {
F_29 ( & V_287 ) ;
F_111 ( & V_289 ) ;
V_79 -> V_185 = NULL ;
F_113 ( & V_289 ) ;
F_31 ( & V_287 ) ;
} else {
if ( V_157 -> V_519 && ! V_4 -> V_23 )
F_261 ( V_157 -> V_519 ,
V_11 -> V_12 ) ;
}
}
if ( V_81 )
goto V_527;
V_81 = F_253 ( V_2 ) ;
if ( V_81 )
F_22 ( V_2 -> V_115 , L_173 , V_81 ) ;
return;
V_527:
F_72 ( V_2 , V_70 , 1 ) ;
V_522:
F_237 ( V_11 ) ;
F_136 ( V_11 ) ;
F_138 ( V_11 ) ;
F_107 ( V_11 ) ;
if ( ( V_81 == - V_399 ) || ( V_81 == - V_367 ) )
break;
}
if ( V_2 -> V_4 -> V_23 ||
! V_157 -> V_158 -> V_528 ||
! ( V_157 -> V_158 -> V_528 ) ( V_157 , V_70 ) ) {
if ( V_81 != - V_399 && V_81 != - V_114 )
F_30 ( & V_79 -> V_20 ,
L_174 ) ;
}
V_406:
F_72 ( V_2 , V_70 , 1 ) ;
if ( V_157 -> V_158 -> V_529 && ! V_2 -> V_4 -> V_23 )
V_157 -> V_158 -> V_529 ( V_157 , V_70 ) ;
}
static void F_262 ( struct V_1 * V_2 , int V_70 ,
T_1 V_3 , T_1 V_178 )
__must_hold( &port_dev->status_lock
static void F_263 ( struct V_1 * V_2 , int V_70 )
__must_hold( &port_dev->status_lock
static void V_304 ( struct V_83 * V_84 )
{
struct V_7 * V_4 ;
struct V_120 * V_121 ;
struct V_1 * V_2 ;
struct V_234 * V_235 ;
T_1 V_236 ;
T_1 V_237 ;
int V_54 , V_55 ;
V_2 = F_24 ( V_84 , struct V_1 , V_123 ) ;
V_4 = V_2 -> V_4 ;
V_235 = V_2 -> V_115 ;
V_121 = F_34 ( V_235 ) ;
F_22 ( V_235 , L_175 ,
V_4 -> V_88 , V_4 -> V_9 ,
( T_1 ) V_2 -> V_188 [ 0 ] ,
( T_1 ) V_2 -> V_139 [ 0 ] ) ;
F_140 ( V_4 ) ;
if ( F_264 ( V_2 -> V_122 ) )
goto V_530;
if ( V_4 -> V_88 == V_186 ) {
V_2 -> error = - V_114 ;
F_82 ( V_2 , V_288 ) ;
goto V_530;
}
V_55 = F_76 ( V_121 ) ;
if ( V_55 ) {
F_22 ( V_235 , L_176 , V_55 ) ;
goto V_530;
}
if ( V_2 -> V_90 )
goto V_531;
if ( V_2 -> error ) {
F_22 ( V_235 , L_177 , V_2 -> error ) ;
V_55 = F_265 ( V_4 ) ;
if ( V_55 ) {
F_22 ( V_235 , L_178 , V_55 ) ;
goto V_531;
}
V_2 -> V_135 = 0 ;
V_2 -> error = 0 ;
}
for ( V_54 = 1 ; V_54 <= V_4 -> V_9 ; V_54 ++ ) {
struct V_78 * V_79 = V_2 -> V_80 [ V_54 - 1 ] ;
if ( F_65 ( V_54 , V_2 -> V_139 )
|| F_65 ( V_54 , V_2 -> V_188 )
|| F_65 ( V_54 , V_2 -> V_128 ) ) {
F_167 ( & V_79 -> V_20 ) ;
F_88 ( & V_79 -> V_20 ) ;
F_197 ( V_79 ) ;
F_263 ( V_2 , V_54 ) ;
F_198 ( V_79 ) ;
F_212 ( & V_79 -> V_20 ) ;
}
}
if ( F_149 ( 0 , V_2 -> V_139 ) == 0 )
;
else if ( F_68 ( V_2 , & V_236 , & V_237 ) < 0 )
F_30 ( V_235 , L_179 ) ;
else {
if ( V_237 & V_532 ) {
F_22 ( V_235 , L_180 ) ;
F_16 ( V_4 , V_533 ) ;
if ( V_236 & V_283 )
V_2 -> V_277 = 1 ;
else
V_2 -> V_277 = 0 ;
}
if ( V_237 & V_534 ) {
T_1 V_81 = 0 ;
T_1 V_535 ;
F_22 ( V_235 , L_181 ) ;
F_16 ( V_4 , V_536 ) ;
F_66 ( 500 ) ;
F_63 ( V_2 , true ) ;
F_68 ( V_2 , & V_81 , & V_535 ) ;
if ( V_81 & V_284 )
F_30 ( V_235 , L_182 ) ;
}
}
V_531:
F_266 ( V_121 ) ;
V_530:
F_147 ( V_4 ) ;
F_77 ( V_121 ) ;
F_39 ( & V_2 -> V_124 , V_126 ) ;
}
int F_267 ( void )
{
if ( F_268 ( & V_537 ) < 0 ) {
F_269 ( V_538 L_183 ,
V_539 ) ;
return - 1 ;
}
V_125 = F_270 ( L_184 , V_540 , 0 ) ;
if ( V_125 )
return 0 ;
F_271 ( & V_537 ) ;
F_272 ( L_185 , V_539 ) ;
return - 1 ;
}
void F_273 ( void )
{
F_274 ( V_125 ) ;
F_271 ( & V_537 ) ;
}
static int F_275 ( struct V_7 * V_11 ,
struct V_498 * V_541 ,
struct V_542 * V_543 )
{
int V_86 = 0 ;
unsigned V_544 ;
unsigned V_545 = 0 ;
unsigned V_546 ;
unsigned V_547 ;
int V_548 ;
char * V_499 ;
if ( memcmp ( & V_11 -> V_34 , V_541 ,
sizeof( * V_541 ) ) != 0 )
return 1 ;
if ( ( V_543 && ! V_11 -> V_15 ) || ( ! V_543 && V_11 -> V_15 ) )
return 1 ;
if ( V_11 -> V_15 ) {
V_546 = F_12 ( V_11 -> V_15 -> V_281 -> V_357 ) ;
if ( V_546 != F_12 ( V_543 -> V_281 -> V_357 ) )
return 1 ;
if ( memcmp ( V_11 -> V_15 -> V_281 , V_543 -> V_281 , V_546 ) )
return 1 ;
}
if ( V_11 -> V_351 )
V_545 = strlen ( V_11 -> V_351 ) + 1 ;
V_546 = V_545 ;
for ( V_544 = 0 ; V_544 < V_11 -> V_34 . V_549 ; V_544 ++ ) {
V_547 = F_12 ( V_11 -> V_354 [ V_544 ] . V_281 . V_357 ) ;
V_546 = F_276 ( V_546 , V_547 ) ;
}
V_499 = F_56 ( V_546 , V_207 ) ;
if ( V_499 == NULL ) {
F_30 ( & V_11 -> V_20 , L_186 ) ;
return 1 ;
}
for ( V_544 = 0 ; V_544 < V_11 -> V_34 . V_549 ; V_544 ++ ) {
V_547 = F_12 ( V_11 -> V_354 [ V_544 ] . V_281 . V_357 ) ;
V_548 = F_252 ( V_11 , V_550 , V_544 , V_499 ,
V_547 ) ;
if ( V_548 != V_547 ) {
F_22 ( & V_11 -> V_20 , L_187 ,
V_544 , V_548 ) ;
V_86 = 1 ;
break;
}
if ( memcmp ( V_499 , V_11 -> V_356 [ V_544 ] , V_547 )
!= 0 ) {
F_22 ( & V_11 -> V_20 , L_188 ,
V_544 ,
( (struct V_551 * ) V_499 ) ->
V_552 ) ;
V_86 = 1 ;
break;
}
}
if ( ! V_86 && V_545 ) {
V_548 = F_277 ( V_11 , V_11 -> V_34 . V_348 ,
V_499 , V_545 ) ;
if ( V_548 + 1 != V_545 ) {
F_22 ( & V_11 -> V_20 , L_189 ,
V_548 ) ;
V_86 = 1 ;
} else if ( memcmp ( V_499 , V_11 -> V_351 , V_548 ) != 0 ) {
F_22 ( & V_11 -> V_20 , L_190 ) ;
V_86 = 1 ;
}
}
F_52 ( V_499 ) ;
return V_86 ;
}
static int F_214 ( struct V_7 * V_11 )
{
struct V_7 * V_553 = V_11 -> V_23 ;
struct V_1 * V_554 ;
struct V_191 * V_157 = F_60 ( V_11 -> V_171 ) ;
struct V_498 V_34 = V_11 -> V_34 ;
struct V_542 * V_15 ;
int V_54 , V_488 , V_55 = 0 ;
int V_70 = V_11 -> V_127 ;
if ( V_11 -> V_88 == V_186 ||
V_11 -> V_88 == V_324 ) {
F_22 ( & V_11 -> V_20 , L_191 ,
V_11 -> V_88 ) ;
return - V_67 ;
}
if ( ! V_553 )
return - V_555 ;
V_554 = F_3 ( V_553 ) ;
if ( V_11 -> V_425 == 1 )
F_209 ( V_11 , 0 ) ;
V_15 = V_11 -> V_15 ;
V_11 -> V_15 = NULL ;
V_55 = F_210 ( V_11 ) ;
if ( V_55 ) {
F_30 ( & V_11 -> V_20 , L_192 , V_116 ) ;
goto V_556;
}
V_55 = F_202 ( V_11 ) ;
if ( V_55 ) {
F_30 ( & V_11 -> V_20 , L_193 ,
V_116 ) ;
goto V_556;
}
for ( V_54 = 0 ; V_54 < V_520 ; ++ V_54 ) {
F_237 ( V_11 ) ;
V_55 = F_245 ( V_554 , V_11 , V_70 , V_54 ) ;
if ( V_55 >= 0 || V_55 == - V_399 || V_55 == - V_114 )
break;
}
if ( V_55 < 0 )
goto V_556;
if ( F_275 ( V_11 , & V_34 , V_15 ) ) {
F_7 ( & V_11 -> V_20 , L_194 ) ;
V_11 -> V_34 = V_34 ;
goto V_556;
}
if ( ! V_11 -> V_8 )
goto V_406;
F_29 ( V_157 -> V_475 ) ;
V_55 = F_278 ( V_11 , V_11 -> V_8 , NULL , NULL ) ;
if ( V_55 < 0 ) {
F_71 ( & V_11 -> V_20 ,
L_195
L_196 ) ;
F_31 ( V_157 -> V_475 ) ;
goto V_556;
}
V_55 = F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_557 , 0 ,
V_11 -> V_8 -> V_281 . V_552 , 0 ,
NULL , 0 , V_201 ) ;
if ( V_55 < 0 ) {
F_30 ( & V_11 -> V_20 ,
L_197 ,
V_11 -> V_8 -> V_281 . V_552 , V_55 ) ;
F_31 ( V_157 -> V_475 ) ;
goto V_556;
}
F_31 ( V_157 -> V_475 ) ;
F_73 ( V_11 , V_89 ) ;
for ( V_54 = 0 ; V_54 < V_11 -> V_8 -> V_281 . V_558 ; V_54 ++ ) {
struct V_559 * V_354 = V_11 -> V_8 ;
struct V_120 * V_121 = V_354 -> V_10 [ V_54 ] ;
struct V_560 * V_281 ;
V_281 = & V_121 -> V_294 -> V_281 ;
if ( V_281 -> V_561 == 0 ) {
F_279 ( V_11 , V_121 , true ) ;
F_280 ( V_11 , V_121 , true ) ;
V_55 = 0 ;
} else {
V_121 -> V_562 = 1 ;
V_55 = F_97 ( V_11 , V_281 -> V_563 ,
V_281 -> V_561 ) ;
V_121 -> V_562 = 0 ;
}
if ( V_55 < 0 ) {
F_30 ( & V_11 -> V_20 , L_198
L_199 ,
V_281 -> V_563 ,
V_281 -> V_561 ,
V_55 ) ;
goto V_556;
}
for ( V_488 = 0 ; V_488 < V_121 -> V_294 -> V_281 . V_303 ; V_488 ++ )
V_121 -> V_294 -> V_233 [ V_488 ] . V_564 = 0 ;
}
V_406:
F_209 ( V_11 , 1 ) ;
F_211 ( V_11 ) ;
F_204 ( V_11 ) ;
F_281 ( V_11 ) ;
V_11 -> V_15 = V_15 ;
return 0 ;
V_556:
F_74 ( V_554 , V_70 ) ;
F_281 ( V_11 ) ;
V_11 -> V_15 = V_15 ;
return - V_114 ;
}
int F_265 ( struct V_7 * V_11 )
{
int V_55 ;
int V_54 ;
unsigned int V_565 ;
struct V_78 * V_79 ;
struct V_559 * V_354 = V_11 -> V_8 ;
struct V_1 * V_2 = F_3 ( V_11 -> V_23 ) ;
if ( V_11 -> V_88 == V_186 ||
V_11 -> V_88 == V_324 ) {
F_22 ( & V_11 -> V_20 , L_191 ,
V_11 -> V_88 ) ;
return - V_67 ;
}
if ( ! V_11 -> V_23 ) {
F_22 ( & V_11 -> V_20 , L_200 , V_116 ) ;
return - V_555 ;
}
V_79 = V_2 -> V_80 [ V_11 -> V_127 - 1 ] ;
V_565 = F_282 () ;
F_184 ( V_11 ) ;
if ( V_354 ) {
for ( V_54 = 0 ; V_54 < V_354 -> V_281 . V_558 ; ++ V_54 ) {
struct V_120 * V_566 = V_354 -> V_10 [ V_54 ] ;
struct V_567 * V_156 ;
int V_568 = 0 ;
if ( V_566 -> V_20 . V_158 ) {
V_156 = F_283 ( V_566 -> V_20 . V_158 ) ;
if ( V_156 -> V_569 && V_156 -> V_570 )
V_568 = ( V_156 -> V_569 ) ( V_566 ) ;
else if ( V_566 -> V_571 ==
V_572 )
V_568 = 1 ;
if ( V_568 )
F_284 ( V_566 ) ;
}
}
}
F_197 ( V_79 ) ;
V_55 = F_214 ( V_11 ) ;
F_198 ( V_79 ) ;
if ( V_354 ) {
for ( V_54 = V_354 -> V_281 . V_558 - 1 ; V_54 >= 0 ; -- V_54 ) {
struct V_120 * V_566 = V_354 -> V_10 [ V_54 ] ;
struct V_567 * V_156 ;
int V_573 = V_566 -> V_574 ;
if ( ! V_573 && V_566 -> V_20 . V_158 ) {
V_156 = F_283 ( V_566 -> V_20 . V_158 ) ;
if ( V_156 -> V_570 )
V_573 = ( V_156 -> V_570 ) ( V_566 ) ;
else if ( V_566 -> V_571 ==
V_572 )
V_573 = 1 ;
if ( V_573 )
V_566 -> V_574 = 1 ;
}
}
F_285 ( V_11 ) ;
}
F_187 ( V_11 ) ;
F_286 ( V_565 ) ;
return V_55 ;
}
void F_287 ( struct V_120 * V_575 )
{
if ( F_62 ( & V_575 -> V_576 ) )
F_123 ( V_575 ) ;
}
struct V_7 * F_288 ( struct V_7 * V_4 ,
int V_70 )
{
struct V_1 * V_2 = F_3 ( V_4 ) ;
if ( V_70 < 1 || V_70 > V_4 -> V_9 )
return NULL ;
return V_2 -> V_80 [ V_70 - 1 ] -> V_185 ;
}
void F_106 ( struct V_7 * V_4 ,
struct V_61 * V_281 )
{
struct V_1 * V_2 = F_3 ( V_4 ) ;
enum V_577 V_369 ;
int V_54 ;
if ( ! V_2 )
return;
if ( ! F_2 ( V_4 ) ) {
for ( V_54 = 1 ; V_54 <= V_4 -> V_9 ; V_54 ++ ) {
struct V_78 * V_79 = V_2 -> V_80 [ V_54 - 1 ] ;
V_369 = V_79 -> V_369 ;
if ( V_369 == V_372 ) {
T_2 V_578 = 1 << ( V_54 % 8 ) ;
if ( ! ( V_281 -> V_35 . V_249 . V_250 [ V_54 / 8 ] & V_578 ) ) {
F_22 ( & V_79 -> V_20 , L_201 ) ;
V_281 -> V_35 . V_249 . V_250 [ V_54 / 8 ] |= V_578 ;
}
}
}
} else {
T_1 V_579 = F_12 ( V_281 -> V_35 . V_36 . V_250 ) ;
for ( V_54 = 1 ; V_54 <= V_4 -> V_9 ; V_54 ++ ) {
struct V_78 * V_79 = V_2 -> V_80 [ V_54 - 1 ] ;
V_369 = V_79 -> V_369 ;
if ( V_369 == V_372 ) {
T_1 V_578 = 1 << V_54 ;
if ( ! ( V_579 & V_578 ) ) {
F_22 ( & V_79 -> V_20 , L_201 ) ;
V_579 |= V_578 ;
}
}
}
V_281 -> V_35 . V_36 . V_250 = F_228 ( V_579 ) ;
}
}
T_6 F_289 ( struct V_7 * V_4 ,
int V_70 )
{
struct V_1 * V_2 = F_3 ( V_4 ) ;
if ( ! V_2 )
return NULL ;
return F_290 ( & V_2 -> V_80 [ V_70 - 1 ] -> V_20 ) ;
}
