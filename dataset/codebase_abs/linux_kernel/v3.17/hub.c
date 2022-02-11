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
unsigned long V_119 ;
F_33 ( & V_120 , V_119 ) ;
if ( ! V_2 -> V_121 && F_34 ( & V_2 -> V_122 ) ) {
F_35 ( & V_2 -> V_122 , & V_123 ) ;
F_36 (
F_37 ( V_2 -> V_114 ) ) ;
F_38 ( & V_124 ) ;
}
F_39 ( & V_120 , V_119 ) ;
}
void F_40 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = F_3 ( V_4 ) ;
if ( V_2 )
F_32 ( V_2 ) ;
}
void F_41 ( struct V_7 * V_4 ,
unsigned int V_125 )
{
struct V_1 * V_2 ;
if ( ! V_4 )
return;
V_2 = F_3 ( V_4 ) ;
if ( V_2 ) {
F_42 ( V_125 , V_2 -> V_126 ) ;
F_32 ( V_2 ) ;
}
}
static void F_43 ( struct V_127 * V_127 )
{
struct V_1 * V_2 = V_127 -> V_128 ;
int V_80 = V_127 -> V_80 ;
unsigned V_53 ;
unsigned long V_129 ;
switch ( V_80 ) {
case - V_130 :
case - V_131 :
case - V_132 :
return;
default:
F_22 ( V_2 -> V_114 , L_15 , V_80 ) ;
if ( ( ++ V_2 -> V_133 < 10 ) || V_2 -> error )
goto V_134;
V_2 -> error = V_80 ;
case 0 :
V_129 = 0 ;
for ( V_53 = 0 ; V_53 < V_127 -> V_135 ; ++ V_53 )
V_129 |= ( ( unsigned long ) ( ( * V_2 -> V_136 ) [ V_53 ] ) )
<< ( V_53 * 8 ) ;
V_2 -> V_137 [ 0 ] = V_129 ;
break;
}
V_2 -> V_133 = 0 ;
F_32 ( V_2 ) ;
V_134:
if ( V_2 -> V_89 )
return;
if ( ( V_80 = F_44 ( V_2 -> V_127 , V_138 ) ) != 0
&& V_80 != - V_113 && V_80 != - V_139 )
F_30 ( V_2 -> V_114 , L_16 , V_80 ) ;
}
static inline int
F_45 ( struct V_7 * V_4 , T_1 V_140 , T_1 V_141 )
{
if ( ( ( V_140 >> 11 ) & V_142 ) ==
V_143 ) {
int V_80 = F_14 ( V_4 , F_17 ( V_4 , 0 ) ,
V_144 , V_70 ,
V_140 ^ 0x8000 , V_141 , NULL , 0 , 1000 ) ;
if ( V_80 )
return V_80 ;
}
return F_14 ( V_4 , F_17 ( V_4 , 0 ) ,
V_144 , V_70 , V_140 ,
V_141 , NULL , 0 , 1000 ) ;
}
static void F_46 ( struct V_82 * V_83 )
{
struct V_1 * V_2 =
F_24 ( V_83 , struct V_1 , V_141 . V_145 ) ;
unsigned long V_119 ;
F_33 ( & V_2 -> V_141 . V_146 , V_119 ) ;
while ( ! F_34 ( & V_2 -> V_141 . V_147 ) ) {
struct V_148 * V_149 ;
struct V_150 * V_151 ;
struct V_7 * V_4 = V_2 -> V_4 ;
const struct V_152 * V_153 ;
int V_80 ;
V_149 = V_2 -> V_141 . V_147 . V_149 ;
V_151 = F_47 ( V_149 , struct V_150 , V_147 ) ;
F_48 ( & V_151 -> V_147 ) ;
F_39 ( & V_2 -> V_141 . V_146 , V_119 ) ;
V_80 = F_45 ( V_4 , V_151 -> V_140 , V_151 -> V_141 ) ;
if ( V_80 && V_80 != - V_113 )
F_30 ( & V_4 -> V_19 ,
L_17 ,
V_151 -> V_141 , V_151 -> V_140 , V_80 ) ;
V_153 = V_151 -> V_154 -> V_155 ;
if ( V_153 -> V_156 )
( V_153 -> V_156 ) ( V_151 -> V_154 , V_151 -> V_157 ) ;
F_49 ( V_151 ) ;
F_33 ( & V_2 -> V_141 . V_146 , V_119 ) ;
}
F_39 ( & V_2 -> V_141 . V_146 , V_119 ) ;
}
int F_50 ( struct V_7 * V_4 , struct V_1 * V_2 ,
int V_69 , bool V_158 )
{
int V_54 ;
if ( V_158 )
V_54 = F_19 ( V_4 , V_69 , V_159 ) ;
else
V_54 = F_18 ( V_4 , V_69 , V_159 ) ;
if ( V_54 )
return V_54 ;
if ( V_158 )
F_42 ( V_69 , V_2 -> V_160 ) ;
else
F_51 ( V_69 , V_2 -> V_160 ) ;
return 0 ;
}
int F_52 ( struct V_127 * V_127 )
{
struct V_7 * V_11 = V_127 -> V_19 ;
int V_161 = V_127 -> V_161 ;
struct V_162 * V_141 = V_11 -> V_141 ;
unsigned long V_119 ;
struct V_150 * V_151 ;
if ( ( V_151 = F_53 ( sizeof *V_151 , V_138 ) ) == NULL ) {
F_30 ( & V_11 -> V_19 , L_18 ) ;
return - V_163 ;
}
V_151 -> V_141 = V_141 -> V_164 ? V_11 -> V_165 : 1 ;
V_151 -> V_140 = F_54 ( V_161 ) ;
V_151 -> V_140 |= V_11 -> V_166 << 4 ;
V_151 -> V_140 |= F_55 ( V_161 )
? ( V_143 << 11 )
: ( V_167 << 11 ) ;
if ( F_56 ( V_161 ) )
V_151 -> V_140 |= 1 << 15 ;
V_151 -> V_154 = F_57 ( V_11 -> V_168 ) ;
V_151 -> V_157 = V_127 -> V_157 ;
F_33 ( & V_141 -> V_146 , V_119 ) ;
F_35 ( & V_151 -> V_147 , & V_141 -> V_147 ) ;
F_58 ( & V_141 -> V_145 ) ;
F_39 ( & V_141 -> V_146 , V_119 ) ;
return 0 ;
}
static void F_59 ( struct V_1 * V_2 , bool V_169 )
{
int V_69 ;
if ( F_60 ( V_2 ) )
F_22 ( V_2 -> V_114 , L_19 ) ;
else
F_22 ( V_2 -> V_114 , L_20
L_21 ) ;
for ( V_69 = 1 ; V_69 <= V_2 -> V_4 -> V_9 ; V_69 ++ )
if ( F_61 ( V_69 , V_2 -> V_160 ) )
F_19 ( V_2 -> V_4 , V_69 , V_159 ) ;
else
F_18 ( V_2 -> V_4 , V_69 ,
V_159 ) ;
if ( V_169 )
F_62 ( F_63 ( V_2 ) ) ;
}
static int F_64 ( struct V_1 * V_2 ,
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
* V_80 = F_12 ( V_2 -> V_80 -> V_2 . V_170 ) ;
* V_110 = F_12 ( V_2 -> V_80 -> V_2 . V_171 ) ;
V_54 = 0 ;
}
F_31 ( & V_2 -> V_111 ) ;
return V_54 ;
}
static int F_65 ( struct V_1 * V_2 , int V_69 ,
unsigned int V_172 )
{
return F_19 ( V_2 -> V_4 ,
V_69 | ( V_172 << 3 ) ,
V_173 ) ;
}
static int F_66 ( struct V_1 * V_2 , int V_69 )
{
int V_54 ;
int V_174 ;
T_1 V_175 , V_3 ;
if ( ! F_2 ( V_2 -> V_4 ) )
return - V_66 ;
V_54 = F_28 ( V_2 , V_69 , & V_3 , & V_175 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( ( V_3 & V_176 ) ==
V_177 ) {
F_22 ( & V_2 -> V_79 [ V_69 - 1 ] -> V_19 ,
L_22 ) ;
return V_54 ;
}
V_54 = F_65 ( V_2 , V_69 , V_178 ) ;
if ( V_54 )
return V_54 ;
for ( V_174 = 0 ; ; V_174 += V_179 ) {
V_54 = F_28 ( V_2 , V_69 , & V_3 , & V_175 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( ( V_3 & V_176 ) ==
V_178 )
break;
if ( V_174 >= V_180 )
break;
F_62 ( V_179 ) ;
}
if ( V_174 >= V_180 )
F_67 ( & V_2 -> V_79 [ V_69 - 1 ] -> V_19 ,
L_23 , V_174 ) ;
return F_65 ( V_2 , V_69 , V_177 ) ;
}
static int F_68 ( struct V_1 * V_2 , int V_69 , int V_181 )
{
struct V_77 * V_78 = V_2 -> V_79 [ V_69 - 1 ] ;
struct V_7 * V_4 = V_2 -> V_4 ;
int V_54 = 0 ;
if ( V_78 -> V_182 && V_181 )
F_69 ( V_78 -> V_182 , V_183 ) ;
if ( ! V_2 -> error ) {
if ( F_2 ( V_2 -> V_4 ) )
V_54 = F_66 ( V_2 , V_69 ) ;
else
V_54 = F_18 ( V_4 , V_69 ,
V_184 ) ;
}
if ( V_54 && V_54 != - V_113 )
F_30 ( & V_78 -> V_19 , L_24 , V_54 ) ;
return V_54 ;
}
static void F_70 ( struct V_1 * V_2 , int V_69 )
{
F_22 ( & V_2 -> V_79 [ V_69 - 1 ] -> V_19 , L_25 ) ;
F_68 ( V_2 , V_69 , 1 ) ;
F_42 ( V_69 , V_2 -> V_185 ) ;
F_32 ( V_2 ) ;
}
int F_71 ( struct V_7 * V_11 )
{
struct V_1 * V_2 ;
struct V_186 * V_187 ;
if ( ! V_11 -> V_22 )
return - V_66 ;
V_2 = F_3 ( V_11 -> V_22 ) ;
V_187 = F_37 ( V_2 -> V_114 ) ;
F_72 ( V_187 ) ;
F_42 ( V_11 -> V_125 , V_2 -> V_188 ) ;
F_70 ( V_2 , V_11 -> V_125 ) ;
F_73 ( V_187 ) ;
return 0 ;
}
static void F_74 ( struct V_1 * V_2 , enum V_189 type )
{
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_190 * V_154 ;
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
unsigned V_192 = F_63 ( V_2 ) ;
F_59 ( V_2 , false ) ;
F_75 ( & V_2 -> V_202 , V_203 ) ;
F_25 ( V_101 ,
& V_2 -> V_202 ,
F_76 ( V_192 ) ) ;
F_36 (
F_37 ( V_2 -> V_114 ) ) ;
return;
} else if ( type == V_204 ) {
V_154 = F_57 ( V_4 -> V_168 ) ;
if ( V_154 -> V_155 -> V_205 ) {
V_54 = V_154 -> V_155 -> V_205 ( V_154 , V_4 ,
& V_2 -> V_141 , V_206 ) ;
if ( V_54 < 0 ) {
F_30 ( V_2 -> V_114 , L_27
L_28
L_29 ) ;
F_30 ( V_2 -> V_114 , L_30
L_31
L_32 ) ;
}
}
F_59 ( V_2 , true ) ;
} else {
F_59 ( V_2 , true ) ;
}
}
V_194:
for ( V_69 = 1 ; V_69 <= V_4 -> V_9 ; ++ V_69 ) {
struct V_77 * V_78 = V_2 -> V_79 [ V_69 - 1 ] ;
struct V_7 * V_11 = V_78 -> V_182 ;
T_1 V_3 , V_175 ;
V_3 = V_175 = 0 ;
V_80 = F_28 ( V_2 , V_69 , & V_3 , & V_175 ) ;
if ( V_11 || ( V_3 & V_207 ) )
F_22 ( & V_78 -> V_19 , L_33 ,
V_3 , V_175 ) ;
if ( ( V_3 & V_208 ) && (
type != V_197 ||
! ( V_3 & V_207 ) ||
! V_11 ||
V_11 -> V_87 == V_183 ) ) {
V_3 &= ~ V_208 ;
if ( ! F_2 ( V_4 ) )
F_18 ( V_4 , V_69 ,
V_184 ) ;
}
if ( V_175 & V_209 ) {
V_191 = true ;
F_18 ( V_2 -> V_4 , V_69 ,
V_210 ) ;
}
if ( V_175 & V_211 ) {
V_191 = true ;
F_18 ( V_2 -> V_4 , V_69 ,
V_212 ) ;
}
if ( V_175 & V_213 ) {
V_191 = true ;
F_18 ( V_2 -> V_4 , V_69 ,
V_214 ) ;
}
if ( ( V_175 & V_215 ) &&
F_2 ( V_2 -> V_4 ) ) {
V_191 = true ;
F_18 ( V_2 -> V_4 , V_69 ,
V_216 ) ;
}
if ( ! ( V_3 & V_207 ) ||
( V_175 & V_209 ) )
F_51 ( V_69 , V_2 -> V_188 ) ;
if ( ! V_11 || V_11 -> V_87 == V_183 ) {
if ( V_11 || ( V_3 & V_207 ) ||
( V_3 & V_217 ) )
F_42 ( V_69 , V_2 -> V_185 ) ;
} else if ( V_3 & V_208 ) {
bool V_218 = ( V_3 &
V_176 ) ==
V_219 ;
if ( V_175 || ( F_2 ( V_2 -> V_4 ) &&
V_218 ) )
F_42 ( V_69 , V_2 -> V_185 ) ;
} else if ( V_11 -> V_220 ) {
#ifdef F_77
V_11 -> V_221 = 1 ;
#endif
if ( F_61 ( V_69 , V_2 -> V_160 ) )
F_42 ( V_69 , V_2 -> V_185 ) ;
} else {
F_69 ( V_11 , V_183 ) ;
F_42 ( V_69 , V_2 -> V_185 ) ;
}
}
if ( V_191 ) {
V_192 = V_222 ;
if ( type == V_193 ) {
F_75 ( & V_2 -> V_202 , V_223 ) ;
F_25 ( V_101 ,
& V_2 -> V_202 ,
F_76 ( V_192 ) ) ;
return;
} else {
F_62 ( V_192 ) ;
}
}
V_196:
V_2 -> V_89 = 0 ;
V_80 = F_44 ( V_2 -> V_127 , V_206 ) ;
if ( V_80 < 0 )
F_30 ( V_2 -> V_114 , L_34 , V_80 ) ;
if ( V_2 -> V_224 && V_100 )
F_25 ( V_101 ,
& V_2 -> V_84 , V_102 ) ;
F_32 ( V_2 ) ;
if ( type <= V_195 )
F_78 ( F_37 ( V_2 -> V_114 ) ) ;
}
static void V_203 ( struct V_82 * V_225 )
{
struct V_1 * V_2 = F_24 ( V_225 , struct V_1 , V_202 . V_83 ) ;
F_74 ( V_2 , V_193 ) ;
}
static void V_223 ( struct V_82 * V_225 )
{
struct V_1 * V_2 = F_24 ( V_225 , struct V_1 , V_202 . V_83 ) ;
F_74 ( V_2 , V_195 ) ;
}
static void F_79 ( struct V_1 * V_2 , enum V_226 type )
{
struct V_7 * V_4 = V_2 -> V_4 ;
int V_53 ;
F_80 ( & V_2 -> V_202 ) ;
V_2 -> V_89 = 1 ;
if ( type != V_227 ) {
for ( V_53 = 0 ; V_53 < V_4 -> V_9 ; ++ V_53 ) {
if ( V_2 -> V_79 [ V_53 ] -> V_182 )
F_81 ( & V_2 -> V_79 [ V_53 ] -> V_182 ) ;
}
}
F_82 ( V_2 -> V_127 ) ;
if ( V_2 -> V_224 )
F_80 ( & V_2 -> V_84 ) ;
if ( V_2 -> V_141 . V_2 )
F_83 ( & V_2 -> V_141 . V_145 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < V_2 -> V_4 -> V_9 ; ++ V_53 )
F_85 ( & V_2 -> V_79 [ V_53 ] -> V_19 ) ;
}
static int F_86 ( struct V_186 * V_187 )
{
struct V_1 * V_2 = F_4 ( V_187 ) ;
F_79 ( V_2 , V_228 ) ;
V_2 -> V_229 = 1 ;
F_84 ( V_2 ) ;
return 0 ;
}
static int F_87 ( struct V_186 * V_187 )
{
struct V_1 * V_2 = F_4 ( V_187 ) ;
V_2 -> V_229 = 0 ;
F_84 ( V_2 ) ;
F_74 ( V_2 , V_230 ) ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_231 * V_232 )
{
struct V_190 * V_154 ;
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_233 * V_234 = V_2 -> V_114 ;
T_1 V_235 , V_236 ;
T_1 V_237 ;
unsigned int V_161 ;
int V_238 , V_54 , V_53 ;
char * V_239 = L_35 ;
unsigned V_240 ;
unsigned V_241 ;
unsigned V_9 ;
V_2 -> V_136 = F_53 ( sizeof( * V_2 -> V_136 ) , V_242 ) ;
if ( ! V_2 -> V_136 ) {
V_54 = - V_163 ;
goto V_243;
}
V_2 -> V_80 = F_53 ( sizeof( * V_2 -> V_80 ) , V_242 ) ;
if ( ! V_2 -> V_80 ) {
V_54 = - V_163 ;
goto V_243;
}
F_89 ( & V_2 -> V_111 ) ;
V_2 -> V_33 = F_53 ( sizeof( * V_2 -> V_33 ) , V_242 ) ;
if ( ! V_2 -> V_33 ) {
V_54 = - V_163 ;
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
V_2 -> V_79 = F_90 ( V_9 * sizeof( struct V_77 * ) , V_242 ) ;
if ( ! V_2 -> V_79 ) {
V_54 = - V_163 ;
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
F_91 ( & V_2 -> V_141 . V_146 ) ;
F_92 ( & V_2 -> V_141 . V_147 ) ;
F_93 ( & V_2 -> V_141 . V_145 , F_46 ) ;
switch ( V_4 -> V_33 . V_258 ) {
case V_259 :
break;
case V_260 :
F_22 ( V_234 , L_50 ) ;
V_2 -> V_141 . V_2 = V_4 ;
break;
case V_261 :
V_54 = F_94 ( V_4 , 0 , 1 ) ;
if ( V_54 == 0 ) {
F_22 ( V_234 , L_51 ) ;
V_2 -> V_141 . V_164 = 1 ;
} else
F_30 ( V_234 , L_52 ,
V_54 ) ;
V_2 -> V_141 . V_2 = V_4 ;
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
V_2 -> V_141 . V_265 = 666 ;
F_22 ( V_234 , L_54
L_55 ,
8 , V_2 -> V_141 . V_265 ) ;
}
break;
case V_266 :
V_2 -> V_141 . V_265 = 666 * 2 ;
F_22 ( V_234 , L_54
L_55 ,
16 , V_2 -> V_141 . V_265 ) ;
break;
case V_267 :
V_2 -> V_141 . V_265 = 666 * 3 ;
F_22 ( V_234 , L_54
L_55 ,
24 , V_2 -> V_141 . V_265 ) ;
break;
case V_268 :
V_2 -> V_141 . V_265 = 666 * 4 ;
F_22 ( V_234 , L_54
L_55 ,
32 , V_2 -> V_141 . V_265 ) ;
break;
}
if ( V_237 & V_269 ) {
V_2 -> V_224 = 1 ;
F_22 ( V_234 , L_56 ) ;
}
F_22 ( V_234 , L_57 ,
V_2 -> V_33 -> V_270 * 2 ) ;
V_54 = F_95 ( V_4 , V_271 , 0 , & V_235 ) ;
if ( V_54 ) {
V_239 = L_58 ;
goto V_243;
}
V_154 = F_57 ( V_4 -> V_168 ) ;
if ( V_4 == V_4 -> V_168 -> V_272 ) {
if ( V_154 -> V_273 > 0 )
V_4 -> V_274 = V_154 -> V_273 ;
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
F_67 ( V_234 ,
L_60
L_61 ) ;
V_2 -> V_275 = V_240 ;
} else {
V_2 -> V_275 = V_241 ;
}
if ( V_2 -> V_275 < V_241 )
F_22 ( V_234 , L_62 ,
V_2 -> V_275 ) ;
V_54 = F_64 ( V_2 , & V_235 , & V_236 ) ;
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
V_161 = F_96 ( V_4 , V_232 -> V_284 ) ;
V_238 = F_97 ( V_4 , V_161 , F_98 ( V_161 ) ) ;
if ( V_238 > sizeof( * V_2 -> V_136 ) )
V_238 = sizeof( * V_2 -> V_136 ) ;
V_2 -> V_127 = F_99 ( 0 , V_242 ) ;
if ( ! V_2 -> V_127 ) {
V_54 = - V_163 ;
goto V_243;
}
F_100 ( V_2 -> V_127 , V_4 , V_161 , * V_2 -> V_136 , V_238 , F_43 ,
V_2 , V_232 -> V_285 ) ;
if ( V_2 -> V_224 && V_100 )
V_2 -> V_91 [ 0 ] = V_92 ;
F_29 ( & V_286 ) ;
for ( V_53 = 0 ; V_53 < V_9 ; V_53 ++ ) {
V_54 = F_101 ( V_2 , V_53 + 1 ) ;
if ( V_54 < 0 ) {
F_30 ( V_2 -> V_114 ,
L_68 , V_53 + 1 ) ;
break;
}
}
V_4 -> V_9 = V_53 ;
for ( V_53 = 0 ; V_53 < V_4 -> V_9 ; V_53 ++ ) {
struct V_77 * V_78 = V_2 -> V_79 [ V_53 ] ;
F_102 ( & V_78 -> V_19 ) ;
}
F_31 ( & V_286 ) ;
if ( V_54 < 0 )
goto V_243;
if ( V_154 -> V_155 -> V_205 ) {
V_54 = V_154 -> V_155 -> V_205 ( V_154 , V_4 ,
& V_2 -> V_141 , V_242 ) ;
if ( V_54 < 0 ) {
V_239 = L_69 ;
goto V_243;
}
}
F_103 ( V_4 , V_2 -> V_33 ) ;
F_74 ( V_2 , V_201 ) ;
return 0 ;
V_243:
F_30 ( V_234 , L_70 ,
V_239 , V_54 ) ;
return V_54 ;
}
static void F_104 ( struct V_287 * V_287 )
{
struct V_1 * V_2 = F_24 ( V_287 , struct V_1 , V_287 ) ;
F_105 ( F_37 ( V_2 -> V_114 ) ) ;
F_49 ( V_2 ) ;
}
static void F_106 ( struct V_186 * V_187 )
{
struct V_1 * V_2 = F_4 ( V_187 ) ;
struct V_7 * V_4 = F_107 ( V_187 ) ;
int V_69 ;
F_108 ( & V_120 ) ;
if ( ! F_34 ( & V_2 -> V_122 ) ) {
F_109 ( & V_2 -> V_122 ) ;
F_110 ( V_187 ) ;
}
V_2 -> V_121 = 1 ;
F_111 ( & V_120 ) ;
V_2 -> error = 0 ;
F_79 ( V_2 , V_288 ) ;
F_29 ( & V_286 ) ;
F_108 ( & V_289 ) ;
V_69 = V_4 -> V_9 ;
V_4 -> V_9 = 0 ;
F_112 ( V_187 , NULL ) ;
F_111 ( & V_289 ) ;
for (; V_69 > 0 ; -- V_69 )
F_113 ( V_2 , V_69 ) ;
F_31 ( & V_286 ) ;
if ( V_2 -> V_4 -> V_12 == V_13 )
V_290 -- ;
F_114 ( V_2 -> V_127 ) ;
F_49 ( V_2 -> V_79 ) ;
F_49 ( V_2 -> V_33 ) ;
F_49 ( V_2 -> V_80 ) ;
F_49 ( V_2 -> V_136 ) ;
F_115 ( & V_187 -> V_19 , false ) ;
F_116 ( & V_2 -> V_287 , F_104 ) ;
}
static int F_117 ( struct V_186 * V_187 , const struct V_291 * V_292 )
{
struct V_293 * V_280 ;
struct V_231 * V_232 ;
struct V_7 * V_4 ;
struct V_1 * V_2 ;
V_280 = V_187 -> V_294 ;
V_4 = F_107 ( V_187 ) ;
#ifdef F_118
if ( V_4 -> V_19 . V_295 . V_296 >= 0 )
F_119 ( & V_4 -> V_19 , 0 ) ;
#endif
if ( V_4 -> V_22 ) {
F_120 ( V_4 ) ;
} else {
const struct V_152 * V_153 = F_57 ( V_4 -> V_168 ) -> V_155 ;
if ( V_153 -> V_297 && V_153 -> V_298 )
F_120 ( V_4 ) ;
}
if ( V_4 -> V_199 == V_299 ) {
F_30 ( & V_187 -> V_19 ,
L_71 ) ;
return - V_300 ;
}
#ifdef F_121
if ( V_4 -> V_22 ) {
F_67 ( & V_187 -> V_19 , L_72 ) ;
return - V_113 ;
}
#endif
if ( ( V_280 -> V_280 . V_301 != 0 ) &&
( V_280 -> V_280 . V_301 != 1 ) ) {
V_302:
F_30 ( & V_187 -> V_19 , L_73 ) ;
return - V_116 ;
}
if ( V_280 -> V_280 . V_303 != 1 )
goto V_302;
V_232 = & V_280 -> V_232 [ 0 ] . V_280 ;
if ( ! F_122 ( V_232 ) )
goto V_302;
F_7 ( & V_187 -> V_19 , L_74 ) ;
V_2 = F_90 ( sizeof( * V_2 ) , V_242 ) ;
if ( ! V_2 ) {
F_22 ( & V_187 -> V_19 , L_75 ) ;
return - V_163 ;
}
F_123 ( & V_2 -> V_287 ) ;
F_92 ( & V_2 -> V_122 ) ;
V_2 -> V_114 = & V_187 -> V_19 ;
V_2 -> V_4 = V_4 ;
F_75 ( & V_2 -> V_84 , F_23 ) ;
F_75 ( & V_2 -> V_202 , NULL ) ;
F_124 ( V_187 ) ;
F_112 ( V_187 , V_2 ) ;
V_187 -> V_304 = 1 ;
F_115 ( & V_187 -> V_19 , true ) ;
if ( V_4 -> V_12 == V_13 )
V_290 ++ ;
if ( V_292 -> V_305 & V_306 )
V_2 -> V_307 = 1 ;
if ( F_88 ( V_2 , V_232 ) >= 0 )
return 0 ;
F_106 ( V_187 ) ;
return - V_113 ;
}
static int
F_125 ( struct V_186 * V_187 , unsigned int V_308 , void * V_309 )
{
struct V_7 * V_4 = F_107 ( V_187 ) ;
struct V_1 * V_2 = F_3 ( V_4 ) ;
switch ( V_308 ) {
case V_310 : {
struct V_311 * V_312 = V_309 ;
int V_53 ;
F_108 ( & V_289 ) ;
if ( V_4 -> V_166 <= 0 )
V_312 -> V_313 = 0 ;
else {
V_312 -> V_313 = V_4 -> V_9 ;
for ( V_53 = 0 ; V_53 < V_312 -> V_313 ; V_53 ++ ) {
if ( V_2 -> V_79 [ V_53 ] -> V_182 == NULL )
V_312 -> V_112 [ V_53 ] = 0 ;
else
V_312 -> V_112 [ V_53 ] =
V_2 -> V_79 [ V_53 ] -> V_182 -> V_166 ;
}
}
F_111 ( & V_289 ) ;
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
if ( V_4 -> V_87 == V_183 )
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
return - V_130 ;
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
if ( V_11 -> V_87 == V_183 || ! V_11 -> V_22 )
return false ;
V_2 = F_3 ( V_11 -> V_22 ) ;
return ! ! V_2 -> V_79 [ V_11 -> V_125 - 1 ] -> V_317 ;
}
static void F_131 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_3 ( V_11 ) ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_11 -> V_9 ; ++ V_53 ) {
if ( V_2 -> V_79 [ V_53 ] -> V_182 )
F_131 ( V_2 -> V_79 [ V_53 ] -> V_182 ) ;
}
if ( V_11 -> V_87 == V_323 )
V_11 -> V_324 -= V_325 ;
V_11 -> V_87 = V_183 ;
}
void F_69 ( struct V_7 * V_11 ,
enum V_326 V_327 )
{
unsigned long V_119 ;
int V_328 = - 1 ;
F_33 ( & V_289 , V_119 ) ;
if ( V_11 -> V_87 == V_183 )
;
else if ( V_327 != V_183 ) {
if ( V_11 -> V_22 ) {
if ( V_11 -> V_87 == V_323
|| V_327 == V_323 )
;
else if ( V_327 == V_88 )
V_328 = V_11 -> V_8 -> V_280 . V_17
& V_329 ;
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
F_39 ( & V_289 , V_119 ) ;
if ( V_328 >= 0 )
F_132 ( & V_11 -> V_19 , V_328 ) ;
}
static void F_133 ( struct V_7 * V_11 )
{
int V_166 ;
struct V_330 * V_168 = V_11 -> V_168 ;
if ( V_11 -> V_331 ) {
V_166 = V_11 -> V_125 + 1 ;
F_134 ( F_61 ( V_166 , V_168 -> V_332 . V_333 ) ) ;
} else {
V_166 = F_135 ( V_168 -> V_332 . V_333 , 128 ,
V_168 -> V_334 ) ;
if ( V_166 >= 128 )
V_166 = F_135 ( V_168 -> V_332 . V_333 ,
128 , 1 ) ;
V_168 -> V_334 = ( V_166 >= 127 ? 1 : V_166 + 1 ) ;
}
if ( V_166 < 128 ) {
F_42 ( V_166 , V_168 -> V_332 . V_333 ) ;
V_11 -> V_166 = V_166 ;
}
}
static void F_136 ( struct V_7 * V_11 )
{
if ( V_11 -> V_166 > 0 ) {
F_51 ( V_11 -> V_166 , V_11 -> V_168 -> V_332 . V_333 ) ;
V_11 -> V_166 = - 1 ;
}
}
static void F_137 ( struct V_7 * V_11 , int V_166 )
{
if ( ! V_11 -> V_331 )
V_11 -> V_166 = V_166 ;
}
static void F_138 ( struct V_7 * V_11 )
{
struct V_190 * V_154 = F_57 ( V_11 -> V_168 ) ;
if ( V_154 -> V_155 -> V_335 && V_11 -> V_22 )
V_154 -> V_155 -> V_335 ( V_154 , V_11 ) ;
}
static void F_139 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_3 ( V_11 ) ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_11 -> V_9 ; V_53 ++ ) {
if ( V_2 -> V_79 [ V_53 ] -> V_182 )
F_81 ( & V_2 -> V_79 [ V_53 ] -> V_182 ) ;
}
}
void F_81 ( struct V_7 * * V_336 )
{
struct V_77 * V_78 = NULL ;
struct V_7 * V_11 = * V_336 ;
struct V_1 * V_2 = NULL ;
int V_69 = 1 ;
F_69 ( V_11 , V_183 ) ;
F_7 ( & V_11 -> V_19 , L_76 ,
V_11 -> V_166 ) ;
F_140 ( V_11 ) ;
F_139 ( V_11 ) ;
F_22 ( & V_11 -> V_19 , L_77 ) ;
F_141 ( V_11 , 0 ) ;
F_142 ( V_11 ) ;
if ( V_11 -> V_22 ) {
V_69 = V_11 -> V_125 ;
V_2 = F_3 ( V_11 -> V_22 ) ;
V_78 = V_2 -> V_79 [ V_69 - 1 ] ;
F_143 ( & V_11 -> V_19 . V_337 , L_78 ) ;
F_143 ( & V_78 -> V_19 . V_337 , L_79 ) ;
if ( ! F_144 ( V_69 , V_2 -> V_338 ) )
F_145 ( & V_78 -> V_19 ) ;
}
F_146 ( & V_11 -> V_339 ) ;
F_147 ( V_11 ) ;
F_148 ( & V_11 -> V_19 ) ;
F_136 ( V_11 ) ;
F_108 ( & V_289 ) ;
* V_336 = NULL ;
F_111 ( & V_289 ) ;
if ( V_78 && F_149 ( V_69 , V_2 -> V_338 ) )
F_102 ( & V_78 -> V_19 ) ;
F_138 ( V_11 ) ;
F_150 ( & V_11 -> V_19 ) ;
}
static void F_151 ( struct V_7 * V_11 , char * V_292 , char * string )
{
if ( ! string )
return;
F_7 ( & V_11 -> V_19 , L_80 , V_292 , string ) ;
}
static void F_152 ( struct V_7 * V_11 )
{
F_7 ( & V_11 -> V_19 , L_81 ,
F_12 ( V_11 -> V_33 . V_340 ) ,
F_12 ( V_11 -> V_33 . V_341 ) ) ;
F_7 ( & V_11 -> V_19 ,
L_82 ,
V_11 -> V_33 . V_342 ,
V_11 -> V_33 . V_343 ,
V_11 -> V_33 . V_344 ) ;
F_151 ( V_11 , L_83 , V_11 -> V_345 ) ;
F_151 ( V_11 , L_84 , V_11 -> V_346 ) ;
F_151 ( V_11 , L_85 , V_11 -> V_347 ) ;
}
static inline void F_152 ( struct V_7 * V_11 ) { }
static int F_153 ( struct V_7 * V_11 )
{
int V_348 = 0 ;
#ifdef F_154
if ( ! V_11 -> V_168 -> V_349
&& V_11 -> V_350
&& V_11 -> V_22 == V_11 -> V_168 -> V_272 ) {
struct V_351 * V_280 = NULL ;
struct V_330 * V_168 = V_11 -> V_168 ;
if ( F_155 ( V_11 -> V_352 [ 0 ] ,
F_12 ( V_11 -> V_350 [ 0 ] . V_280 . V_353 ) ,
V_354 , ( void * * ) & V_280 ) == 0 ) {
if ( V_280 -> V_17 & V_355 ) {
unsigned V_69 = V_11 -> V_125 ;
F_7 ( & V_11 -> V_19 ,
L_86 ,
( V_69 == V_168 -> V_356 )
? L_40 : L_87 ) ;
if ( V_69 == V_168 -> V_356 )
V_168 -> V_357 = 1 ;
V_348 = F_14 ( V_11 ,
F_17 ( V_11 , 0 ) ,
V_71 , 0 ,
V_168 -> V_357
? V_358
: V_359 ,
0 , NULL , 0 , V_200 ) ;
if ( V_348 < 0 ) {
F_7 ( & V_11 -> V_19 ,
L_88 ,
V_348 ) ;
V_168 -> V_357 = 0 ;
}
}
}
}
if ( ! F_156 ( V_11 ) ) {
if ( V_11 -> V_168 -> V_357 || V_11 -> V_168 -> V_349 ) {
V_348 = F_157 ( V_11 , V_360 ) ;
if ( V_348 < 0 )
F_22 ( & V_11 -> V_19 , L_89 , V_348 ) ;
}
V_348 = - V_361 ;
goto V_243;
}
V_243:
#endif
return V_348 ;
}
static int F_158 ( struct V_7 * V_11 )
{
int V_348 ;
if ( V_11 -> V_350 == NULL ) {
V_348 = F_159 ( V_11 ) ;
if ( V_348 < 0 ) {
if ( V_348 != - V_113 )
F_30 ( & V_11 -> V_19 , L_90 ,
V_348 ) ;
return V_348 ;
}
}
V_11 -> V_345 = F_160 ( V_11 , V_11 -> V_33 . V_343 ) ;
V_11 -> V_346 = F_160 ( V_11 ,
V_11 -> V_33 . V_342 ) ;
V_11 -> V_347 = F_160 ( V_11 , V_11 -> V_33 . V_344 ) ;
V_348 = F_153 ( V_11 ) ;
if ( V_348 < 0 )
return V_348 ;
F_161 ( V_11 ) ;
return 0 ;
}
static void F_162 ( struct V_7 * V_11 )
{
struct V_7 * V_4 = V_11 -> V_22 ;
struct V_1 * V_2 ;
T_2 V_112 = V_11 -> V_125 ;
T_1 V_237 ;
bool V_362 = true ;
if ( ! V_4 )
return;
V_2 = F_3 ( V_11 -> V_22 ) ;
V_237 = F_12 ( V_2 -> V_33 -> V_237 ) ;
if ( ! ( V_237 & V_246 ) )
return;
if ( F_2 ( V_4 ) ) {
if ( F_12 ( V_2 -> V_33 -> V_34 . V_35 . V_249 )
& ( 1 << V_112 ) )
V_362 = false ;
} else {
if ( V_2 -> V_33 -> V_34 . V_248 . V_249 [ V_112 / 8 ] & ( 1 << ( V_112 % 8 ) ) )
V_362 = false ;
}
if ( V_362 )
V_11 -> V_362 = V_363 ;
else
V_11 -> V_362 = V_364 ;
switch ( V_2 -> V_79 [ V_11 -> V_125 - 1 ] -> V_365 ) {
case V_366 :
V_11 -> V_362 = V_363 ;
break;
case V_367 :
V_11 -> V_362 = V_364 ;
break;
default:
break;
}
}
int F_163 ( struct V_7 * V_11 )
{
int V_348 ;
if ( V_11 -> V_22 ) {
F_164 ( & V_11 -> V_19 , 0 ) ;
}
F_165 ( & V_11 -> V_19 ) ;
F_166 ( & V_11 -> V_19 ) ;
F_167 ( & V_11 -> V_19 ) ;
F_168 ( & V_11 -> V_19 ) ;
F_169 ( V_11 ) ;
V_348 = F_158 ( V_11 ) ;
if ( V_348 < 0 )
goto V_243;
F_22 ( & V_11 -> V_19 , L_91 ,
V_11 -> V_166 , V_11 -> V_168 -> V_368 ,
( ( ( V_11 -> V_168 -> V_368 - 1 ) * 128 ) + ( V_11 -> V_166 - 1 ) ) ) ;
V_11 -> V_19 . V_369 = F_170 ( V_370 ,
( ( ( V_11 -> V_168 -> V_368 - 1 ) * 128 ) + ( V_11 -> V_166 - 1 ) ) ) ;
F_152 ( V_11 ) ;
if ( V_11 -> V_347 )
F_171 ( V_11 -> V_347 , strlen ( V_11 -> V_347 ) ) ;
if ( V_11 -> V_345 )
F_171 ( V_11 -> V_345 , strlen ( V_11 -> V_345 ) ) ;
if ( V_11 -> V_346 )
F_171 ( V_11 -> V_346 ,
strlen ( V_11 -> V_346 ) ) ;
F_172 ( & V_11 -> V_19 ) ;
if ( V_11 -> V_22 )
F_162 ( V_11 ) ;
V_348 = F_173 ( & V_11 -> V_19 ) ;
if ( V_348 ) {
F_30 ( & V_11 -> V_19 , L_92 , V_348 ) ;
goto V_243;
}
if ( V_11 -> V_22 ) {
struct V_1 * V_2 = F_3 ( V_11 -> V_22 ) ;
int V_69 = V_11 -> V_125 ;
struct V_77 * V_78 = V_2 -> V_79 [ V_69 - 1 ] ;
V_348 = F_174 ( & V_11 -> V_19 . V_337 ,
& V_78 -> V_19 . V_337 , L_78 ) ;
if ( V_348 )
goto V_243;
V_348 = F_174 ( & V_78 -> V_19 . V_337 ,
& V_11 -> V_19 . V_337 , L_79 ) ;
if ( V_348 ) {
F_143 ( & V_11 -> V_19 . V_337 , L_78 ) ;
goto V_243;
}
if ( ! F_144 ( V_69 , V_2 -> V_338 ) )
F_145 ( & V_78 -> V_19 ) ;
}
( void ) F_175 ( & V_11 -> V_19 , & V_11 -> V_339 , V_11 ) ;
F_176 ( V_11 ) ;
F_177 ( & V_11 -> V_19 ) ;
return V_348 ;
V_243:
F_69 ( V_11 , V_183 ) ;
F_178 ( & V_11 -> V_19 ) ;
F_179 ( & V_11 -> V_19 ) ;
return V_348 ;
}
int F_180 ( struct V_7 * V_371 )
{
F_140 ( V_371 ) ;
if ( V_371 -> V_372 == 0 )
goto V_373;
V_371 -> V_372 = 0 ;
F_181 ( V_371 , - 1 ) ;
V_373:
F_147 ( V_371 ) ;
return 0 ;
}
int F_182 ( struct V_7 * V_371 )
{
int V_374 = 0 , V_375 ;
F_140 ( V_371 ) ;
if ( V_371 -> V_372 == 1 )
goto V_376;
V_374 = F_183 ( V_371 ) ;
if ( V_374 < 0 ) {
F_30 ( & V_371 -> V_19 ,
L_93 , V_374 ) ;
goto V_377;
}
V_374 = F_184 ( V_371 , sizeof( V_371 -> V_33 ) ) ;
if ( V_374 < 0 ) {
F_30 ( & V_371 -> V_19 , L_94
L_95 , V_374 ) ;
goto V_378;
}
V_371 -> V_372 = 1 ;
V_375 = F_185 ( V_371 ) ;
if ( V_375 >= 0 ) {
V_374 = F_181 ( V_371 , V_375 ) ;
if ( V_374 ) {
F_30 ( & V_371 -> V_19 ,
L_96 , V_375 , V_374 ) ;
}
}
F_7 ( & V_371 -> V_19 , L_97 ) ;
V_378:
F_186 ( V_371 ) ;
V_377:
V_376:
F_147 ( V_371 ) ;
return V_374 ;
}
static unsigned F_187 ( struct V_1 * V_2 )
{
struct V_190 * V_154 ;
if ( V_2 -> V_4 -> V_22 != NULL )
return 0 ;
V_154 = F_24 ( V_2 -> V_4 -> V_168 , struct V_190 , V_379 ) ;
return V_154 -> V_380 ;
}
static bool F_188 ( struct V_7 * V_11 , int V_381 )
{
if ( V_11 -> V_12 == V_49 )
return false ;
return F_189 ( V_381 ) ;
}
static bool F_190 ( struct V_1 * V_2 , int V_69 ,
T_1 V_3 )
{
T_1 V_382 ;
if ( ! F_2 ( V_2 -> V_4 ) )
return false ;
if ( F_61 ( V_69 , V_2 -> V_383 ) )
return true ;
V_382 = V_3 & V_176 ;
return V_382 == V_384
|| V_382 == V_385 ;
}
static int F_191 ( struct V_1 * V_2 , int V_69 ,
struct V_7 * V_11 , unsigned int V_192 , bool V_386 )
{
int V_387 , V_54 ;
T_1 V_3 ;
T_1 V_175 ;
for ( V_387 = 0 ;
V_387 < V_388 ;
V_387 += V_192 ) {
F_62 ( V_192 ) ;
V_54 = F_28 ( V_2 , V_69 , & V_3 , & V_175 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( ! ( V_3 & V_389 ) )
break;
if ( V_387 >= 2 * V_390 )
V_192 = V_391 ;
F_22 ( & V_2 -> V_79 [ V_69 - 1 ] -> V_19 ,
L_98 ,
V_386 ? L_99 : L_40 , V_192 ) ;
}
if ( ( V_3 & V_389 ) )
return - V_321 ;
if ( F_190 ( V_2 , V_69 , V_3 ) )
return - V_392 ;
if ( ! ( V_3 & V_207 ) )
return - V_392 ;
if ( ! F_2 ( V_2 -> V_4 ) &&
( V_175 & V_209 ) )
return - V_392 ;
if ( ! ( V_3 & V_208 ) )
return - V_321 ;
if ( ! V_11 )
return 0 ;
if ( F_187 ( V_2 ) )
V_11 -> V_12 = V_393 ;
else if ( F_2 ( V_2 -> V_4 ) )
V_11 -> V_12 = V_49 ;
else if ( V_3 & V_5 )
V_11 -> V_12 = V_13 ;
else if ( V_3 & V_6 )
V_11 -> V_12 = V_394 ;
else
V_11 -> V_12 = V_395 ;
return 0 ;
}
static void F_192 ( struct V_1 * V_2 , int V_69 ,
struct V_7 * V_11 , int * V_80 )
{
switch ( * V_80 ) {
case 0 :
F_62 ( 10 + 40 ) ;
if ( V_11 ) {
struct V_190 * V_154 = F_57 ( V_11 -> V_168 ) ;
F_137 ( V_11 , 0 ) ;
if ( V_154 -> V_155 -> V_396 )
V_154 -> V_155 -> V_396 ( V_154 , V_11 ) ;
}
case - V_392 :
case - V_113 :
F_18 ( V_2 -> V_4 ,
V_69 , V_214 ) ;
if ( F_2 ( V_2 -> V_4 ) ) {
F_18 ( V_2 -> V_4 , V_69 ,
V_216 ) ;
F_18 ( V_2 -> V_4 , V_69 ,
V_397 ) ;
F_18 ( V_2 -> V_4 , V_69 ,
V_210 ) ;
}
if ( V_11 )
F_69 ( V_11 , * V_80
? V_183
: V_398 ) ;
break;
}
}
static int F_193 ( struct V_1 * V_2 , int V_69 ,
struct V_7 * V_11 , unsigned int V_192 , bool V_386 )
{
int V_53 , V_80 ;
T_1 V_175 , V_3 ;
struct V_77 * V_78 = V_2 -> V_79 [ V_69 - 1 ] ;
if ( ! F_2 ( V_2 -> V_4 ) ) {
if ( V_386 ) {
F_30 ( V_2 -> V_114 , L_100
L_101 ) ;
return - V_66 ;
}
F_194 ( & V_399 ) ;
} else if ( ! V_386 ) {
V_80 = F_28 ( V_2 , V_69 ,
& V_3 , & V_175 ) ;
if ( V_80 < 0 )
goto V_400;
if ( F_190 ( V_2 , V_69 , V_3 ) )
V_386 = true ;
}
F_51 ( V_69 , V_2 -> V_383 ) ;
for ( V_53 = 0 ; V_53 < V_401 ; V_53 ++ ) {
V_80 = F_19 ( V_2 -> V_4 , V_69 , ( V_386 ?
V_402 :
V_403 ) ) ;
if ( V_80 == - V_113 ) {
;
} else if ( V_80 ) {
F_30 ( & V_78 -> V_19 ,
L_102 ,
V_386 ? L_99 : L_40 , V_80 ) ;
} else {
V_80 = F_191 ( V_2 , V_69 , V_11 , V_192 ,
V_386 ) ;
if ( V_80 && V_80 != - V_392 && V_80 != - V_113 )
F_22 ( V_2 -> V_114 ,
L_103 ,
V_80 ) ;
}
if ( V_80 == 0 || V_80 == - V_392 || V_80 == - V_113 ) {
F_192 ( V_2 , V_69 , V_11 , & V_80 ) ;
if ( ! F_2 ( V_2 -> V_4 ) )
goto V_400;
if ( F_28 ( V_2 , V_69 ,
& V_3 , & V_175 ) < 0 )
goto V_400;
if ( ! F_190 ( V_2 , V_69 ,
V_3 ) )
goto V_400;
if ( ! V_386 ) {
F_22 ( & V_78 -> V_19 ,
L_104 ) ;
V_386 = true ;
}
}
F_22 ( & V_78 -> V_19 ,
L_105 ,
V_386 ? L_99 : L_40 ) ;
V_192 = V_391 ;
}
F_30 ( & V_78 -> V_19 , L_106 ) ;
V_400:
if ( ! F_2 ( V_2 -> V_4 ) )
F_195 ( & V_399 ) ;
return V_80 ;
}
static int F_196 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_54 = 0 ;
if ( F_2 ( V_2 -> V_4 ) ) {
if ( V_3 & V_404 )
V_54 = 1 ;
} else {
if ( V_3 & V_405 )
V_54 = 1 ;
}
return V_54 ;
}
static void F_197 ( struct V_77 * V_78 )
__acquires( &port_dev->status_lock
static void F_198 ( struct V_77 * V_78 )
__releases( &port_dev->status_lock
static int F_199 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_54 = 0 ;
if ( F_2 ( V_2 -> V_4 ) ) {
if ( ( V_3 & V_176 )
== V_406 )
V_54 = 1 ;
} else {
if ( V_3 & V_407 )
V_54 = 1 ;
}
return V_54 ;
}
static int F_200 ( struct V_7 * V_11 ,
struct V_1 * V_2 , int V_69 ,
int V_80 , unsigned V_175 , unsigned V_3 )
{
struct V_77 * V_78 = V_2 -> V_79 [ V_69 - 1 ] ;
if ( V_80 == 0 && V_11 -> V_221
&& F_190 ( V_2 , V_69 , V_3 ) ) {
;
}
else if ( V_80 || F_199 ( V_2 , V_3 ) ||
! F_196 ( V_2 , V_3 ) ||
! ( V_3 & V_207 ) ) {
if ( V_80 >= 0 )
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
V_175 , V_3 , V_80 ) ;
} else if ( V_11 -> V_221 ) {
if ( V_175 & V_209 )
F_18 ( V_2 -> V_4 , V_69 ,
V_210 ) ;
if ( V_175 & V_211 )
F_18 ( V_2 -> V_4 , V_69 ,
V_212 ) ;
}
return V_80 ;
}
int F_201 ( struct V_7 * V_11 )
{
struct V_190 * V_154 = F_57 ( V_11 -> V_168 ) ;
if ( ! F_202 ( V_154 -> V_379 . V_272 ) ||
! F_202 ( V_11 ) )
return 0 ;
if ( ! V_11 -> V_8 )
return 0 ;
return F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_68 , V_271 ,
V_408 , 0 , NULL , 0 ,
V_200 ) ;
}
void F_203 ( struct V_7 * V_11 )
{
struct V_190 * V_154 = F_57 ( V_11 -> V_168 ) ;
if ( ! F_202 ( V_154 -> V_379 . V_272 ) ||
! F_202 ( V_11 ) )
return;
if ( ! V_11 -> V_8 )
return;
F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_71 , V_271 ,
V_408 , 0 , NULL , 0 ,
V_200 ) ;
}
static int F_204 ( struct V_7 * V_11 )
{
if ( V_11 -> V_12 < V_49 )
return F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_71 , V_271 ,
V_409 , 0 , NULL , 0 ,
V_200 ) ;
else
return F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_71 , V_410 ,
V_411 ,
V_412 |
V_413 ,
NULL , 0 , V_200 ) ;
}
static int F_205 ( struct V_7 * V_11 )
{
if ( V_11 -> V_12 < V_49 )
return F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_68 , V_271 ,
V_409 , 0 , NULL , 0 ,
V_200 ) ;
else
return F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_68 , V_410 ,
V_411 , 0 , NULL , 0 ,
V_200 ) ;
}
static unsigned F_206 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_3 ( V_11 ) ;
return V_11 -> V_414 +
( V_2 ? V_2 -> F_206 : 0 ) ;
}
int F_157 ( struct V_7 * V_11 , T_3 V_415 )
{
struct V_1 * V_2 = F_3 ( V_11 -> V_22 ) ;
struct V_77 * V_78 = V_2 -> V_79 [ V_11 -> V_125 - 1 ] ;
int V_69 = V_11 -> V_125 ;
int V_80 ;
bool V_416 = true ;
F_197 ( V_78 ) ;
if ( V_11 -> V_414 ) {
V_80 = F_204 ( V_11 ) ;
if ( V_80 ) {
F_22 ( & V_11 -> V_19 , L_108 ,
V_80 ) ;
if ( F_207 ( V_415 ) )
goto V_417;
}
}
if ( V_11 -> V_418 == 1 )
F_208 ( V_11 , 0 ) ;
if ( F_201 ( V_11 ) ) {
F_30 ( & V_11 -> V_19 , L_109 ) ;
V_80 = - V_163 ;
if ( F_207 ( V_415 ) )
goto V_419;
}
if ( F_209 ( V_11 ) ) {
F_30 ( & V_11 -> V_19 , L_110 ) ;
V_80 = - V_163 ;
if ( F_207 ( V_415 ) )
goto V_420;
}
if ( F_2 ( V_2 -> V_4 ) )
V_80 = F_65 ( V_2 , V_69 , V_406 ) ;
else if ( F_207 ( V_415 ) || F_206 ( V_11 ) > 0 )
V_80 = F_19 ( V_2 -> V_4 , V_69 ,
V_421 ) ;
else {
V_416 = false ;
V_80 = 0 ;
}
if ( V_80 ) {
F_22 ( & V_78 -> V_19 , L_111 , V_80 ) ;
F_210 ( V_11 ) ;
V_420:
F_203 ( V_11 ) ;
V_419:
if ( V_11 -> V_422 == 1 )
F_208 ( V_11 , 1 ) ;
if ( V_11 -> V_414 )
( void ) F_205 ( V_11 ) ;
V_417:
if ( ! F_207 ( V_415 ) )
V_80 = 0 ;
} else {
F_22 ( & V_11 -> V_19 , L_112 ,
( F_207 ( V_415 ) ? L_113 : L_40 ) ,
V_11 -> V_414 ) ;
if ( V_416 ) {
V_11 -> F_199 = 1 ;
F_62 ( 10 ) ;
}
F_69 ( V_11 , V_323 ) ;
}
if ( V_80 == 0 && ! V_11 -> V_414 && V_11 -> V_220
&& F_149 ( V_69 , V_2 -> V_338 ) )
F_211 ( & V_78 -> V_19 ) ;
F_176 ( V_2 -> V_4 ) ;
F_198 ( V_78 ) ;
return V_80 ;
}
static int F_212 ( struct V_7 * V_11 )
{
int V_80 = 0 ;
T_1 V_423 = 0 ;
F_22 ( & V_11 -> V_19 , L_114 ,
V_11 -> V_221 ? L_115 : L_116 ) ;
F_69 ( V_11 , V_11 -> V_8
? V_88
: V_424 ) ;
if ( V_11 -> V_221 ) {
V_425:
if ( V_11 -> V_426 & V_427 )
V_80 = - V_113 ;
else
V_80 = F_213 ( V_11 ) ;
}
if ( V_80 == 0 ) {
V_423 = 0 ;
V_80 = F_95 ( V_11 , V_271 , 0 , & V_423 ) ;
if ( V_80 && ! V_11 -> V_221 && V_11 -> V_220 ) {
F_22 ( & V_11 -> V_19 , L_117 ) ;
V_11 -> V_221 = 1 ;
goto V_425;
}
}
if ( V_80 ) {
F_22 ( & V_11 -> V_19 , L_118 ,
V_80 ) ;
} else if ( V_11 -> V_8 && ! V_11 -> V_221 ) {
if ( V_11 -> V_12 < V_49 ) {
if ( V_423 & ( 1 << V_409 ) )
V_80 = F_205 ( V_11 ) ;
} else {
V_80 = F_95 ( V_11 , V_410 , 0 ,
& V_423 ) ;
if ( ! V_80 && V_423 & ( V_428
| V_429 ) )
V_80 = F_205 ( V_11 ) ;
}
if ( V_80 )
F_22 ( & V_11 -> V_19 ,
L_119 ,
V_80 ) ;
V_80 = 0 ;
}
return V_80 ;
}
static int F_214 ( struct V_7 * V_11 ,
struct V_1 * V_2 , int * V_69 ,
T_1 * V_175 , T_1 * V_3 )
{
int V_80 = 0 , V_430 = 0 ;
while ( V_430 < 2000 ) {
if ( V_80 || * V_3 & V_207 )
break;
F_62 ( 20 ) ;
V_430 += 20 ;
V_80 = F_28 ( V_2 , * V_69 , V_3 , V_175 ) ;
}
return V_80 ;
}
int F_215 ( struct V_7 * V_11 , T_3 V_415 )
{
struct V_1 * V_2 = F_3 ( V_11 -> V_22 ) ;
struct V_77 * V_78 = V_2 -> V_79 [ V_11 -> V_125 - 1 ] ;
int V_69 = V_11 -> V_125 ;
int V_80 ;
T_1 V_175 , V_3 ;
if ( ! F_144 ( V_69 , V_2 -> V_338 ) ) {
V_80 = F_145 ( & V_78 -> V_19 ) ;
if ( V_80 < 0 ) {
F_22 ( & V_11 -> V_19 , L_120 ,
V_80 ) ;
return V_80 ;
}
}
F_197 ( V_78 ) ;
V_80 = F_28 ( V_2 , V_69 , & V_3 , & V_175 ) ;
if ( V_80 == 0 && ! F_199 ( V_2 , V_3 ) )
goto V_431;
if ( F_2 ( V_2 -> V_4 ) )
V_80 = F_65 ( V_2 , V_69 , V_219 ) ;
else
V_80 = F_18 ( V_2 -> V_4 ,
V_69 , V_421 ) ;
if ( V_80 ) {
F_22 ( & V_78 -> V_19 , L_121 , V_80 ) ;
} else {
F_22 ( & V_11 -> V_19 , L_122 ,
( F_207 ( V_415 ) ? L_113 : L_40 ) ) ;
F_62 ( 25 ) ;
V_80 = F_28 ( V_2 , V_69 , & V_3 , & V_175 ) ;
F_62 ( 10 ) ;
}
V_431:
if ( V_80 == 0 ) {
V_11 -> F_199 = 0 ;
if ( F_2 ( V_2 -> V_4 ) ) {
if ( V_175 & V_432 )
F_18 ( V_2 -> V_4 , V_69 ,
V_397 ) ;
} else {
if ( V_175 & V_433 )
F_18 ( V_2 -> V_4 , V_69 ,
V_434 ) ;
}
}
if ( V_11 -> V_220 && F_2 ( V_2 -> V_4 ) )
V_80 = F_214 ( V_11 , V_2 , & V_69 , & V_175 ,
& V_3 ) ;
V_80 = F_200 ( V_11 ,
V_2 , V_69 , V_80 , V_175 , V_3 ) ;
if ( V_80 == 0 )
V_80 = F_212 ( V_11 ) ;
if ( V_80 < 0 ) {
F_22 ( & V_11 -> V_19 , L_121 , V_80 ) ;
F_70 ( V_2 , V_69 ) ;
} else {
if ( V_11 -> V_422 == 1 )
F_208 ( V_11 , 1 ) ;
F_203 ( V_11 ) ;
F_210 ( V_11 ) ;
}
F_198 ( V_78 ) ;
return V_80 ;
}
int F_216 ( struct V_7 * V_11 )
{
int V_80 = 0 ;
F_140 ( V_11 ) ;
if ( V_11 -> V_87 == V_323 ) {
F_22 ( & V_11 -> V_19 , L_122 , L_123 ) ;
V_80 = F_183 ( V_11 ) ;
if ( V_80 == 0 ) {
F_186 ( V_11 ) ;
}
}
F_147 ( V_11 ) ;
return V_80 ;
}
static int F_217 ( struct V_1 * V_2 , unsigned int V_112 ,
T_1 V_3 , T_1 V_175 )
__must_hold( &port_dev->status_lock
static int F_217 ( struct V_1 * V_2 , unsigned int V_112 ,
T_1 V_3 , T_1 V_175 )
{
return 0 ;
}
static int F_218 ( struct V_1 * V_2 )
{
int V_69 ;
for ( V_69 = 1 ; V_69 <= V_2 -> V_4 -> V_9 ; ++ V_69 ) {
T_1 V_3 , V_175 ;
int V_80 ;
V_80 = F_28 ( V_2 , V_69 , & V_3 , & V_175 ) ;
if ( ! V_80 && V_175 )
return 1 ;
}
return 0 ;
}
static int F_219 ( struct V_186 * V_187 , T_3 V_415 )
{
struct V_1 * V_2 = F_4 ( V_187 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
unsigned V_69 ;
int V_80 ;
V_2 -> F_206 = 0 ;
for ( V_69 = 1 ; V_69 <= V_4 -> V_9 ; V_69 ++ ) {
struct V_77 * V_78 = V_2 -> V_79 [ V_69 - 1 ] ;
struct V_7 * V_11 = V_78 -> V_182 ;
if ( V_11 && V_11 -> V_435 ) {
F_67 ( & V_78 -> V_19 , L_124 ,
F_220 ( & V_11 -> V_19 ) ) ;
if ( F_207 ( V_415 ) )
return - V_321 ;
}
if ( V_11 )
V_2 -> F_206 +=
F_206 ( V_11 ) ;
}
if ( V_4 -> V_414 && V_2 -> V_307 ) {
if ( F_218 ( V_2 ) ) {
if ( F_207 ( V_415 ) )
return - V_321 ;
F_221 ( & V_4 -> V_19 , 2000 ) ;
}
}
if ( F_2 ( V_4 ) && V_4 -> V_414 ) {
for ( V_69 = 1 ; V_69 <= V_4 -> V_9 ; V_69 ++ ) {
V_80 = F_19 ( V_4 ,
V_69 |
V_436 |
V_437 |
V_438 ,
V_439 ) ;
}
}
F_22 ( & V_187 -> V_19 , L_114 , V_115 ) ;
F_79 ( V_2 , V_227 ) ;
return 0 ;
}
static int F_222 ( struct V_186 * V_187 )
{
struct V_1 * V_2 = F_4 ( V_187 ) ;
F_22 ( & V_187 -> V_19 , L_114 , V_115 ) ;
F_74 ( V_2 , V_197 ) ;
return 0 ;
}
static int F_223 ( struct V_186 * V_187 )
{
struct V_1 * V_2 = F_4 ( V_187 ) ;
F_22 ( & V_187 -> V_19 , L_114 , V_115 ) ;
F_74 ( V_2 , V_204 ) ;
return 0 ;
}
void F_224 ( struct V_7 * V_440 )
{
F_67 ( & V_440 -> V_19 , L_125 ) ;
V_440 -> V_221 = 1 ;
}
static int F_225 ( struct V_7 * V_11 , enum V_441 V_87 )
{
struct V_442 * V_443 ;
unsigned long long V_444 ;
unsigned long long V_445 ;
unsigned long long V_446 ;
unsigned long long V_447 ;
int V_54 ;
if ( V_11 -> V_87 != V_88 )
return 0 ;
V_444 = F_226 ( V_11 -> V_50 . V_43 , 1000 ) ;
V_445 = F_226 ( V_11 -> V_50 . V_40 , 1000 ) ;
V_446 = F_226 ( V_11 -> V_51 . V_43 , 1000 ) ;
V_447 = F_226 ( V_11 -> V_51 . V_40 , 1000 ) ;
if ( ( V_87 == V_448 &&
( V_444 > V_449 ||
V_445 > V_449 ) ) ||
( V_87 == V_450 &&
( V_446 > V_451 ||
V_447 > V_451 ) ) ) {
F_22 ( & V_11 -> V_19 , L_126 ,
V_452 [ V_87 ] , V_444 , V_445 ) ;
return - V_66 ;
}
if ( V_444 > V_449 )
V_444 = V_449 ;
if ( V_445 > V_449 )
V_445 = V_449 ;
if ( V_446 > V_451 )
V_446 = V_451 ;
if ( V_447 > V_451 )
V_447 = V_451 ;
V_443 = F_53 ( sizeof *( V_443 ) , V_206 ) ;
if ( ! V_443 )
return - V_163 ;
V_443 -> V_444 = V_444 ;
V_443 -> V_445 = V_445 ;
V_443 -> V_446 = F_227 ( V_446 ) ;
V_443 -> V_447 = F_227 ( V_447 ) ;
V_54 = F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_453 ,
V_271 ,
0 , 0 ,
V_443 , sizeof *( V_443 ) ,
V_200 ) ;
F_49 ( V_443 ) ;
return V_54 ;
}
static int F_228 ( struct V_7 * V_11 ,
enum V_441 V_87 , bool V_454 )
{
int V_54 ;
int V_67 ;
switch ( V_87 ) {
case V_448 :
V_67 = V_455 ;
break;
case V_450 :
V_67 = V_456 ;
break;
default:
F_67 ( & V_11 -> V_19 , L_127 ,
V_115 , V_454 ? L_128 : L_129 ) ;
return - V_66 ;
}
if ( V_11 -> V_87 != V_88 ) {
F_22 ( & V_11 -> V_19 , L_130
L_131 ,
V_115 , V_454 ? L_128 : L_129 ,
V_452 [ V_87 ] ) ;
return 0 ;
}
if ( V_454 ) {
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
F_67 ( & V_11 -> V_19 , L_132 ,
V_454 ? L_133 : L_134 ,
V_452 [ V_87 ] ) ;
return - V_321 ;
}
return 0 ;
}
static int F_229 ( struct V_7 * V_11 ,
enum V_441 V_87 , int V_457 )
{
int V_54 ;
int V_67 ;
switch ( V_87 ) {
case V_448 :
V_67 = V_458 ;
break;
case V_450 :
V_67 = V_459 ;
break;
default:
F_67 ( & V_11 -> V_19 , L_135 ,
V_115 ) ;
return - V_66 ;
}
if ( V_87 == V_448 && V_457 > V_460 &&
V_457 != V_461 ) {
F_67 ( & V_11 -> V_19 , L_136
L_137 ,
V_452 [ V_87 ] , V_457 ) ;
return - V_66 ;
}
V_54 = F_19 ( V_11 -> V_22 ,
F_230 ( V_457 ) | V_11 -> V_125 ,
V_67 ) ;
if ( V_54 < 0 ) {
F_67 ( & V_11 -> V_19 , L_138
L_139 , V_452 [ V_87 ] ,
V_457 , V_54 ) ;
return - V_321 ;
}
if ( V_87 == V_448 )
V_11 -> V_50 . V_457 = V_457 ;
else
V_11 -> V_51 . V_457 = V_457 ;
return 0 ;
}
static void F_231 ( struct V_190 * V_154 , struct V_7 * V_11 ,
enum V_441 V_87 )
{
int V_457 , V_54 ;
T_4 V_462 = V_11 -> V_14 -> V_18 -> V_20 ;
T_5 V_463 = V_11 -> V_14 -> V_18 -> V_21 ;
if ( ( V_87 == V_448 && V_462 == 0 ) ||
( V_87 == V_450 && V_463 == 0 ) )
return;
V_54 = F_225 ( V_11 , V_87 ) ;
if ( V_54 < 0 ) {
F_67 ( & V_11 -> V_19 , L_140 ,
V_452 [ V_87 ] ) ;
return;
}
V_457 = V_154 -> V_155 -> V_464 ( V_154 , V_11 , V_87 ) ;
if ( V_457 == 0 )
return;
if ( V_457 < 0 ) {
F_67 ( & V_11 -> V_19 , L_141
L_142 , V_452 [ V_87 ] ,
V_457 ) ;
return;
}
if ( F_229 ( V_11 , V_87 , V_457 ) )
V_154 -> V_155 -> V_465 ( V_154 , V_11 , V_87 ) ;
else if ( V_11 -> V_8 )
F_228 ( V_11 , V_87 , true ) ;
}
static int F_232 ( struct V_190 * V_154 , struct V_7 * V_11 ,
enum V_441 V_87 )
{
int V_67 ;
switch ( V_87 ) {
case V_448 :
V_67 = V_458 ;
break;
case V_450 :
V_67 = V_459 ;
break;
default:
F_67 ( & V_11 -> V_19 , L_143 ,
V_115 ) ;
return - V_66 ;
}
if ( F_229 ( V_11 , V_87 , 0 ) )
return - V_321 ;
F_228 ( V_11 , V_87 , false ) ;
if ( V_154 -> V_155 -> V_465 ( V_154 , V_11 , V_87 ) )
F_67 ( & V_11 -> V_19 , L_144
L_145 ,
V_452 [ V_87 ] ) ;
return 0 ;
}
int F_233 ( struct V_7 * V_11 )
{
struct V_190 * V_154 ;
if ( ! V_11 || ! V_11 -> V_22 ||
V_11 -> V_12 != V_49 ||
! V_11 -> V_23 ||
V_11 -> V_87 < V_398 )
return 0 ;
V_154 = F_57 ( V_11 -> V_168 ) ;
if ( ! V_154 || ! V_154 -> V_155 -> V_465 )
return 0 ;
V_11 -> V_466 ++ ;
if ( ( V_11 -> V_50 . V_457 == 0 && V_11 -> V_51 . V_457 == 0 ) )
return 0 ;
if ( F_232 ( V_154 , V_11 , V_448 ) )
goto V_467;
if ( F_232 ( V_154 , V_11 , V_450 ) )
goto V_467;
return 0 ;
V_467:
F_234 ( V_11 ) ;
return - V_321 ;
}
int F_209 ( struct V_7 * V_11 )
{
struct V_190 * V_154 = F_57 ( V_11 -> V_168 ) ;
int V_54 ;
if ( ! V_154 )
return - V_66 ;
F_29 ( V_154 -> V_468 ) ;
V_54 = F_233 ( V_11 ) ;
F_31 ( V_154 -> V_468 ) ;
return V_54 ;
}
void F_234 ( struct V_7 * V_11 )
{
struct V_190 * V_154 ;
if ( ! V_11 || ! V_11 -> V_22 ||
V_11 -> V_12 != V_49 ||
! V_11 -> V_23 ||
V_11 -> V_87 < V_398 )
return;
V_11 -> V_466 -- ;
V_154 = F_57 ( V_11 -> V_168 ) ;
if ( ! V_154 || ! V_154 -> V_155 -> V_464 ||
! V_154 -> V_155 -> V_465 )
return;
if ( V_11 -> V_466 > 0 )
return;
F_231 ( V_154 , V_11 , V_448 ) ;
F_231 ( V_154 , V_11 , V_450 ) ;
}
void F_210 ( struct V_7 * V_11 )
{
struct V_190 * V_154 = F_57 ( V_11 -> V_168 ) ;
if ( ! V_154 )
return;
F_29 ( V_154 -> V_468 ) ;
F_234 ( V_11 ) ;
F_31 ( V_154 -> V_468 ) ;
}
int F_233 ( struct V_7 * V_11 )
{
return 0 ;
}
void F_234 ( struct V_7 * V_11 ) { }
int F_209 ( struct V_7 * V_11 )
{
return 0 ;
}
void F_210 ( struct V_7 * V_11 ) { }
int F_201 ( struct V_7 * V_11 )
{
return 0 ;
}
void F_203 ( struct V_7 * V_11 ) { }
static int F_217 ( struct V_1 * V_2 , unsigned int V_112 ,
T_1 V_3 , T_1 V_175 )
{
return 0 ;
}
int F_235 ( struct V_1 * V_2 , int V_69 , bool V_469 )
{
int V_54 ;
T_1 V_175 , V_3 ;
unsigned V_470 = 0xffff ;
int V_174 , V_471 = 0 ;
struct V_77 * V_78 = V_2 -> V_79 [ V_69 - 1 ] ;
for ( V_174 = 0 ; ; V_174 += V_179 ) {
V_54 = F_28 ( V_2 , V_69 , & V_3 , & V_175 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( ! ( V_175 & V_209 ) &&
( V_3 & V_207 ) == V_470 ) {
if ( ! V_469 ||
( V_470 == V_207 ) )
V_471 += V_179 ;
if ( V_471 >= V_222 )
break;
} else {
V_471 = 0 ;
V_470 = V_3 & V_207 ;
}
if ( V_175 & V_209 ) {
F_18 ( V_2 -> V_4 , V_69 ,
V_210 ) ;
}
if ( V_174 >= V_180 )
break;
F_62 ( V_179 ) ;
}
F_22 ( & V_78 -> V_19 , L_146 ,
V_174 , V_471 , V_3 ) ;
if ( V_471 < V_222 )
return - V_104 ;
return V_3 ;
}
void F_236 ( struct V_7 * V_11 )
{
F_237 ( V_11 , 0 + V_62 , true ) ;
F_237 ( V_11 , 0 + V_472 , true ) ;
F_238 ( V_11 , & V_11 -> V_339 , true ) ;
}
static int F_239 ( struct V_7 * V_11 , int V_166 )
{
int V_473 ;
struct V_190 * V_154 = F_57 ( V_11 -> V_168 ) ;
if ( ! V_154 -> V_155 -> V_474 && V_166 <= 1 )
return - V_66 ;
if ( V_11 -> V_87 == V_424 )
return 0 ;
if ( V_11 -> V_87 != V_398 )
return - V_66 ;
if ( V_154 -> V_155 -> V_474 )
V_473 = V_154 -> V_155 -> V_474 ( V_154 , V_11 ) ;
else
V_473 = F_14 ( V_11 , F_240 () ,
V_475 , 0 , V_166 , 0 ,
NULL , 0 , V_200 ) ;
if ( V_473 == 0 ) {
F_137 ( V_11 , V_166 ) ;
F_69 ( V_11 , V_424 ) ;
F_236 ( V_11 ) ;
}
return V_473 ;
}
static void F_241 ( struct V_7 * V_11 )
{
struct V_1 * V_2 = F_3 ( V_11 -> V_22 ) ;
int V_365 = V_476 ;
if ( ! V_11 -> V_422 )
return;
if ( V_2 )
V_365 = V_2 -> V_79 [ V_11 -> V_125 - 1 ] -> V_365 ;
if ( ( V_11 -> V_14 -> V_15 -> V_17 & F_242 ( V_477 ) ) ||
V_365 == V_367 ) {
V_11 -> V_478 = 1 ;
F_208 ( V_11 , 1 ) ;
}
}
static int F_243 ( struct V_7 * V_11 )
{
struct V_190 * V_154 = F_57 ( V_11 -> V_168 ) ;
if ( ! V_154 -> V_155 -> V_479 )
return 0 ;
if ( V_11 -> V_87 == V_424 )
return 0 ;
if ( V_11 -> V_87 != V_398 )
return - V_66 ;
return V_154 -> V_155 -> V_479 ( V_154 , V_11 ) ;
}
static int
F_244 ( struct V_1 * V_2 , struct V_7 * V_11 , int V_69 ,
int V_480 )
{
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_190 * V_154 = F_57 ( V_4 -> V_168 ) ;
int V_53 , V_481 , V_473 ;
unsigned V_192 = V_390 ;
enum V_482 V_483 = V_11 -> V_12 ;
const char * V_12 ;
int V_166 = V_11 -> V_166 ;
if ( ! V_4 -> V_22 ) {
V_192 = V_484 ;
if ( V_69 == V_4 -> V_168 -> V_356 )
V_4 -> V_168 -> V_357 = 0 ;
}
if ( V_483 == V_394 )
V_192 = V_391 ;
F_29 ( & V_4 -> V_168 -> V_485 ) ;
V_473 = F_193 ( V_2 , V_69 , V_11 , V_192 , false ) ;
if ( V_473 < 0 )
goto V_243;
V_473 = - V_113 ;
if ( V_483 != V_486 && V_483 != V_11 -> V_12 ) {
F_22 ( & V_11 -> V_19 , L_147 ) ;
goto V_243;
}
V_483 = V_11 -> V_12 ;
switch ( V_11 -> V_12 ) {
case V_49 :
case V_393 :
V_11 -> V_339 . V_280 . V_487 = F_227 ( 512 ) ;
break;
case V_13 :
V_11 -> V_339 . V_280 . V_487 = F_227 ( 64 ) ;
break;
case V_395 :
V_11 -> V_339 . V_280 . V_487 = F_227 ( 64 ) ;
break;
case V_394 :
V_11 -> V_339 . V_280 . V_487 = F_227 ( 8 ) ;
break;
default:
goto V_243;
}
if ( V_11 -> V_12 == V_393 )
V_12 = L_148 ;
else
V_12 = F_245 ( V_11 -> V_12 ) ;
if ( V_11 -> V_12 != V_49 )
F_7 ( & V_11 -> V_19 ,
L_149 ,
( V_11 -> V_350 ) ? L_150 : L_151 , V_12 ,
V_166 , V_11 -> V_168 -> V_488 -> V_155 -> V_489 ) ;
if ( V_4 -> V_141 ) {
V_11 -> V_141 = V_4 -> V_141 ;
V_11 -> V_165 = V_4 -> V_165 ;
} else if ( V_11 -> V_12 != V_13
&& V_4 -> V_12 == V_13 ) {
if ( ! V_2 -> V_141 . V_2 ) {
F_30 ( & V_11 -> V_19 , L_152 ) ;
V_473 = - V_66 ;
goto V_243;
}
V_11 -> V_141 = & V_2 -> V_141 ;
V_11 -> V_165 = V_69 ;
}
for ( V_53 = 0 ; V_53 < V_490 ; ( ++ V_53 , F_62 ( 100 ) ) ) {
bool V_491 = false ;
if ( F_188 ( V_11 , V_480 ) ) {
struct V_492 * V_493 ;
int V_494 = 0 ;
V_491 = true ;
V_473 = F_243 ( V_11 ) ;
if ( V_473 < 0 ) {
F_30 ( & V_11 -> V_19 ,
L_153 ,
V_473 ) ;
goto V_243;
}
#define F_246 64
V_493 = F_53 ( F_246 , V_206 ) ;
if ( ! V_493 ) {
V_473 = - V_163 ;
continue;
}
for ( V_481 = 0 ; V_481 < 3 ; ++ V_481 ) {
V_493 -> V_495 = 0 ;
V_494 = F_14 ( V_11 , F_247 () ,
V_61 , V_62 ,
V_496 << 8 , 0 ,
V_493 , F_246 ,
V_497 ) ;
switch ( V_493 -> V_495 ) {
case 8 : case 16 : case 32 : case 64 : case 255 :
if ( V_493 -> V_498 ==
V_496 ) {
V_494 = 0 ;
break;
}
default:
if ( V_494 == 0 )
V_494 = - V_499 ;
break;
}
if ( V_494 == 0 )
break;
}
V_11 -> V_33 . V_495 =
V_493 -> V_495 ;
F_49 ( V_493 ) ;
V_473 = F_193 ( V_2 , V_69 , V_11 , V_192 , false ) ;
if ( V_473 < 0 )
goto V_243;
if ( V_483 != V_11 -> V_12 ) {
F_22 ( & V_11 -> V_19 ,
L_147 ) ;
V_473 = - V_113 ;
goto V_243;
}
if ( V_494 ) {
if ( V_494 != - V_113 )
F_30 ( & V_11 -> V_19 , L_154 ,
V_494 ) ;
V_473 = - V_500 ;
continue;
}
#undef F_246
}
if ( V_11 -> V_331 == 0 ) {
for ( V_481 = 0 ; V_481 < V_501 ; ++ V_481 ) {
V_473 = F_239 ( V_11 , V_166 ) ;
if ( V_473 >= 0 )
break;
F_62 ( 200 ) ;
}
if ( V_473 < 0 ) {
if ( V_473 != - V_113 )
F_30 ( & V_11 -> V_19 , L_155 ,
V_166 , V_473 ) ;
goto V_243;
}
if ( V_11 -> V_12 == V_49 ) {
V_166 = V_11 -> V_166 ;
F_7 ( & V_11 -> V_19 ,
L_156 ,
( V_11 -> V_350 ) ? L_150 : L_151 ,
V_166 , V_11 -> V_168 -> V_488 -> V_155 -> V_489 ) ;
}
F_62 ( 10 ) ;
if ( V_491 )
break;
}
V_473 = F_184 ( V_11 , 8 ) ;
if ( V_473 < 8 ) {
if ( V_473 != - V_113 )
F_30 ( & V_11 -> V_19 ,
L_157 ,
V_473 ) ;
if ( V_473 >= 0 )
V_473 = - V_500 ;
} else {
V_473 = 0 ;
break;
}
}
if ( V_473 )
goto V_243;
if ( V_154 -> V_502 && ! V_4 -> V_22 )
F_248 ( V_154 -> V_502 , V_11 -> V_12 ) ;
if ( ( V_11 -> V_12 == V_49 ) &&
( F_12 ( V_11 -> V_33 . V_503 ) < 0x0300 ) ) {
F_30 ( & V_11 -> V_19 , L_158
L_159 ) ;
F_193 ( V_2 , V_69 , V_11 ,
V_504 , true ) ;
V_473 = - V_66 ;
goto V_243;
}
if ( V_11 -> V_33 . V_495 == 0xff ||
V_11 -> V_12 == V_49 )
V_53 = 512 ;
else
V_53 = V_11 -> V_33 . V_495 ;
if ( F_249 ( & V_11 -> V_339 . V_280 ) != V_53 ) {
if ( V_11 -> V_12 == V_394 ||
! ( V_53 == 8 || V_53 == 16 || V_53 == 32 || V_53 == 64 ) ) {
F_30 ( & V_11 -> V_19 , L_160 , V_53 ) ;
V_473 = - V_500 ;
goto V_243;
}
if ( V_11 -> V_12 == V_395 )
F_22 ( & V_11 -> V_19 , L_161 , V_53 ) ;
else
F_67 ( & V_11 -> V_19 , L_162 , V_53 ) ;
V_11 -> V_339 . V_280 . V_487 = F_227 ( V_53 ) ;
F_236 ( V_11 ) ;
}
V_473 = F_184 ( V_11 , V_505 ) ;
if ( V_473 < ( signed ) sizeof( V_11 -> V_33 ) ) {
if ( V_473 != - V_113 )
F_30 ( & V_11 -> V_19 , L_163 ,
V_473 ) ;
if ( V_473 >= 0 )
V_473 = - V_506 ;
goto V_243;
}
if ( V_11 -> V_331 == 0 && F_12 ( V_11 -> V_33 . V_503 ) >= 0x0201 ) {
V_473 = F_250 ( V_11 ) ;
if ( ! V_473 ) {
V_11 -> V_23 = F_5 ( V_11 ) ;
F_11 ( V_11 ) ;
}
}
V_473 = 0 ;
if ( V_154 -> V_155 -> V_507 )
V_154 -> V_155 -> V_507 ( V_154 , V_11 ) ;
F_241 ( V_11 ) ;
V_243:
if ( V_473 ) {
F_68 ( V_2 , V_69 , 0 ) ;
F_137 ( V_11 , V_166 ) ;
}
F_31 ( & V_4 -> V_168 -> V_485 ) ;
return V_473 ;
}
static void
F_251 ( struct V_1 * V_2 , struct V_7 * V_11 , int V_69 )
{
struct V_508 * V_509 ;
int V_80 ;
V_509 = F_53 ( sizeof *V_509 , V_242 ) ;
if ( V_509 == NULL )
return;
V_80 = F_252 ( V_11 , V_510 , 0 ,
V_509 , sizeof *V_509 ) ;
if ( V_80 == sizeof *V_509 ) {
F_7 ( & V_11 -> V_19 , L_164
L_165 ) ;
if ( V_2 -> V_224 ) {
V_2 -> V_91 [ V_69 - 1 ] = V_94 ;
F_25 ( V_101 ,
& V_2 -> V_84 , 0 ) ;
}
}
F_49 ( V_509 ) ;
}
static unsigned
F_253 ( struct V_1 * V_2 )
{
struct V_7 * V_4 = V_2 -> V_4 ;
int V_278 ;
int V_69 ;
if ( ! V_2 -> V_276 )
return 0 ;
V_278 = V_4 -> V_274 - V_2 -> V_33 -> V_279 ;
for ( V_69 = 1 ; V_69 <= V_4 -> V_9 ; ++ V_69 ) {
struct V_77 * V_78 = V_2 -> V_79 [ V_69 - 1 ] ;
struct V_7 * V_11 = V_78 -> V_182 ;
unsigned V_240 ;
int V_511 ;
if ( ! V_11 )
continue;
if ( F_2 ( V_11 ) )
V_240 = 150 ;
else
V_240 = 100 ;
if ( V_11 -> V_8 )
V_511 = F_254 ( V_11 , V_11 -> V_8 ) ;
else if ( V_69 != V_11 -> V_168 -> V_356 || V_4 -> V_22 )
V_511 = V_240 ;
else
V_511 = 8 ;
if ( V_511 > V_2 -> V_275 )
F_67 ( & V_78 -> V_19 , L_166 ,
V_511 , V_2 -> V_275 ) ;
V_278 -= V_511 ;
}
if ( V_278 < 0 ) {
F_67 ( V_2 -> V_114 , L_167 ,
- V_278 ) ;
V_278 = 0 ;
}
return V_278 ;
}
static void F_255 ( struct V_1 * V_2 , int V_69 , T_1 V_3 ,
T_1 V_175 )
{
int V_80 , V_53 ;
unsigned V_240 ;
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_190 * V_154 = F_57 ( V_4 -> V_168 ) ;
struct V_77 * V_78 = V_2 -> V_79 [ V_69 - 1 ] ;
struct V_7 * V_11 = V_78 -> V_182 ;
static int V_512 = - 1 ;
if ( V_11 ) {
if ( V_154 -> V_502 && ! V_4 -> V_22 &&
! ( V_3 & V_207 ) )
F_256 ( V_154 -> V_502 , V_11 -> V_12 ) ;
F_81 ( & V_78 -> V_182 ) ;
}
if ( ! ( V_3 & V_207 ) ||
( V_175 & V_209 ) )
F_51 ( V_69 , V_2 -> V_188 ) ;
if ( V_175 & ( V_209 |
V_211 ) ) {
V_80 = F_257 ( V_2 , V_69 ) ;
if ( V_80 < 0 ) {
if ( V_80 != - V_113 &&
V_69 != V_512 &&
F_258 () )
F_30 ( & V_78 -> V_19 , L_168 ) ;
V_3 &= ~ V_207 ;
V_512 = V_69 ;
} else {
V_3 = V_80 ;
}
}
if ( ! ( V_3 & V_207 ) ||
F_61 ( V_69 , V_2 -> V_188 ) ) {
if ( F_60 ( V_2 )
&& ! F_196 ( V_2 , V_3 ) )
F_19 ( V_4 , V_69 , V_159 ) ;
if ( V_3 & V_208 )
goto V_400;
return;
}
if ( F_2 ( V_2 -> V_4 ) )
V_240 = 150 ;
else
V_240 = 100 ;
V_80 = 0 ;
for ( V_53 = 0 ; V_53 < V_513 ; V_53 ++ ) {
V_11 = F_259 ( V_4 , V_4 -> V_168 , V_69 ) ;
if ( ! V_11 ) {
F_30 ( & V_78 -> V_19 ,
L_169 ) ;
goto V_400;
}
F_69 ( V_11 , V_514 ) ;
V_11 -> V_274 = V_2 -> V_275 ;
V_11 -> V_199 = V_4 -> V_199 + 1 ;
V_11 -> V_331 = F_187 ( V_2 ) ;
if ( F_2 ( V_2 -> V_4 ) )
V_11 -> V_12 = V_49 ;
else
V_11 -> V_12 = V_486 ;
F_133 ( V_11 ) ;
if ( V_11 -> V_166 <= 0 ) {
V_80 = - V_392 ;
goto V_515;
}
F_197 ( V_78 ) ;
V_80 = F_244 ( V_2 , V_11 , V_69 , V_53 ) ;
F_198 ( V_78 ) ;
if ( V_80 < 0 )
goto V_515;
F_260 ( V_11 ) ;
if ( V_11 -> V_426 & V_516 )
F_62 ( 1000 ) ;
if ( V_11 -> V_33 . V_517 == V_518
&& V_11 -> V_274 <= V_240 ) {
T_1 V_519 ;
V_80 = F_95 ( V_11 , V_271 , 0 ,
& V_519 ) ;
if ( V_80 ) {
F_22 ( & V_11 -> V_19 , L_170 , V_80 ) ;
goto V_520;
}
if ( ( V_519 & ( 1 << V_277 ) ) == 0 ) {
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
V_80 = - V_392 ;
goto V_520;
}
}
if ( F_12 ( V_11 -> V_33 . V_503 ) >= 0x0200
&& V_11 -> V_12 == V_395
&& V_290 != 0 )
F_251 ( V_2 , V_11 , V_69 ) ;
V_80 = 0 ;
F_29 ( & V_286 ) ;
F_108 ( & V_289 ) ;
if ( V_4 -> V_87 == V_183 )
V_80 = - V_392 ;
else
V_78 -> V_182 = V_11 ;
F_111 ( & V_289 ) ;
F_31 ( & V_286 ) ;
if ( ! V_80 ) {
V_80 = F_163 ( V_11 ) ;
if ( V_80 ) {
F_29 ( & V_286 ) ;
F_108 ( & V_289 ) ;
V_78 -> V_182 = NULL ;
F_111 ( & V_289 ) ;
F_31 ( & V_286 ) ;
}
}
if ( V_80 )
goto V_520;
V_80 = F_253 ( V_2 ) ;
if ( V_80 )
F_22 ( V_2 -> V_114 , L_173 , V_80 ) ;
return;
V_520:
F_68 ( V_2 , V_69 , 1 ) ;
V_515:
F_236 ( V_11 ) ;
F_136 ( V_11 ) ;
F_138 ( V_11 ) ;
F_261 ( V_11 ) ;
if ( ( V_80 == - V_392 ) || ( V_80 == - V_361 ) )
break;
}
if ( V_2 -> V_4 -> V_22 ||
! V_154 -> V_155 -> V_521 ||
! ( V_154 -> V_155 -> V_521 ) ( V_154 , V_69 ) ) {
if ( V_80 != - V_392 && V_80 != - V_113 )
F_30 ( & V_78 -> V_19 ,
L_174 ) ;
}
V_400:
F_68 ( V_2 , V_69 , 1 ) ;
if ( V_154 -> V_155 -> V_522 && ! V_2 -> V_4 -> V_22 )
V_154 -> V_155 -> V_522 ( V_154 , V_69 ) ;
}
static void F_262 ( struct V_1 * V_2 , int V_69 ,
T_1 V_3 , T_1 V_175 )
__must_hold( &port_dev->status_lock
static void F_263 ( struct V_1 * V_2 , int V_69 )
__must_hold( &port_dev->status_lock
static void F_264 ( void )
{
struct V_148 * V_523 ;
struct V_7 * V_4 ;
struct V_186 * V_187 ;
struct V_1 * V_2 ;
struct V_233 * V_234 ;
T_1 V_235 ;
T_1 V_236 ;
int V_53 , V_54 ;
while ( 1 ) {
F_108 ( & V_120 ) ;
if ( F_34 ( & V_123 ) ) {
F_111 ( & V_120 ) ;
break;
}
V_523 = V_123 . V_149 ;
F_109 ( V_523 ) ;
V_2 = F_47 ( V_523 , struct V_1 , V_122 ) ;
F_265 ( & V_2 -> V_287 ) ;
V_4 = V_2 -> V_4 ;
F_266 ( V_4 ) ;
F_111 ( & V_120 ) ;
V_234 = V_2 -> V_114 ;
V_187 = F_37 ( V_234 ) ;
F_22 ( V_234 , L_175 ,
V_4 -> V_87 , V_4 -> V_9 ,
( T_1 ) V_2 -> V_185 [ 0 ] ,
( T_1 ) V_2 -> V_137 [ 0 ] ) ;
F_140 ( V_4 ) ;
if ( F_267 ( V_2 -> V_121 ) )
goto V_524;
if ( V_4 -> V_87 == V_183 ) {
V_2 -> error = - V_113 ;
F_79 ( V_2 , V_288 ) ;
goto V_515;
}
V_54 = F_72 ( V_187 ) ;
if ( V_54 ) {
F_22 ( V_234 , L_176 , V_54 ) ;
goto V_515;
}
if ( V_2 -> V_89 )
goto V_525;
if ( V_2 -> error ) {
F_22 ( V_234 , L_177 ,
V_2 -> error ) ;
V_54 = F_268 ( V_4 ) ;
if ( V_54 ) {
F_22 ( V_234 ,
L_178 , V_54 ) ;
goto V_525;
}
V_2 -> V_133 = 0 ;
V_2 -> error = 0 ;
}
for ( V_53 = 1 ; V_53 <= V_4 -> V_9 ; V_53 ++ ) {
struct V_77 * V_78 = V_2 -> V_79 [ V_53 - 1 ] ;
if ( F_61 ( V_53 , V_2 -> V_137 )
|| F_61 ( V_53 , V_2 -> V_185 )
|| F_61 ( V_53 , V_2 -> V_126 ) ) {
F_166 ( & V_78 -> V_19 ) ;
F_85 ( & V_78 -> V_19 ) ;
F_197 ( V_78 ) ;
F_263 ( V_2 , V_53 ) ;
F_198 ( V_78 ) ;
F_211 ( & V_78 -> V_19 ) ;
}
}
if ( F_149 ( 0 , V_2 -> V_137 ) == 0 )
;
else if ( F_64 ( V_2 , & V_235 , & V_236 ) < 0 )
F_30 ( V_234 , L_179 ) ;
else {
if ( V_236 & V_526 ) {
F_22 ( V_234 , L_180 ) ;
F_16 ( V_4 , V_527 ) ;
if ( V_235 & V_282 )
V_2 -> V_276 = 1 ;
else
V_2 -> V_276 = 0 ;
}
if ( V_236 & V_528 ) {
T_1 V_80 = 0 ;
T_1 V_529 ;
F_22 ( V_234 , L_181 ) ;
F_16 ( V_4 , V_530 ) ;
F_62 ( 500 ) ;
F_59 ( V_2 , true ) ;
F_64 ( V_2 , & V_80 , & V_529 ) ;
if ( V_80 & V_283 )
F_30 ( V_234 , L_182
L_183 ) ;
}
}
V_525:
F_110 ( V_187 ) ;
V_515:
F_73 ( V_187 ) ;
V_524:
F_147 ( V_4 ) ;
F_261 ( V_4 ) ;
F_116 ( & V_2 -> V_287 , F_104 ) ;
}
}
static int F_269 ( void * V_531 )
{
F_270 () ;
do {
F_264 () ;
F_271 ( V_124 ,
! F_34 ( & V_123 ) ||
F_272 () ) ;
} while ( ! F_272 () || ! F_34 ( & V_123 ) );
F_273 ( L_184 , V_532 ) ;
return 0 ;
}
int F_274 ( void )
{
if ( F_275 ( & V_533 ) < 0 ) {
F_276 ( V_534 L_185 ,
V_532 ) ;
return - 1 ;
}
V_535 = F_277 ( F_269 , NULL , L_186 ) ;
if ( ! F_278 ( V_535 ) )
return 0 ;
F_279 ( & V_533 ) ;
F_276 ( V_534 L_187 , V_532 ) ;
return - 1 ;
}
void F_280 ( void )
{
F_281 ( V_535 ) ;
F_279 ( & V_533 ) ;
}
static int F_282 ( struct V_7 * V_11 ,
struct V_492 * V_536 ,
struct V_537 * V_538 )
{
int V_85 = 0 ;
unsigned V_539 ;
unsigned V_540 = 0 ;
unsigned V_541 ;
unsigned V_542 ;
int V_543 ;
char * V_493 ;
if ( memcmp ( & V_11 -> V_33 , V_536 ,
sizeof( * V_536 ) ) != 0 )
return 1 ;
if ( ( V_538 && ! V_11 -> V_14 ) || ( ! V_538 && V_11 -> V_14 ) )
return 1 ;
if ( V_11 -> V_14 ) {
V_541 = F_12 ( V_11 -> V_14 -> V_280 -> V_353 ) ;
if ( V_541 != F_12 ( V_538 -> V_280 -> V_353 ) )
return 1 ;
if ( memcmp ( V_11 -> V_14 -> V_280 , V_538 -> V_280 , V_541 ) )
return 1 ;
}
if ( V_11 -> V_347 )
V_540 = strlen ( V_11 -> V_347 ) + 1 ;
V_541 = V_540 ;
for ( V_539 = 0 ; V_539 < V_11 -> V_33 . V_544 ; V_539 ++ ) {
V_542 = F_12 ( V_11 -> V_350 [ V_539 ] . V_280 . V_353 ) ;
V_541 = F_283 ( V_541 , V_542 ) ;
}
V_493 = F_53 ( V_541 , V_206 ) ;
if ( V_493 == NULL ) {
F_30 ( & V_11 -> V_19 , L_188 ) ;
return 1 ;
}
for ( V_539 = 0 ; V_539 < V_11 -> V_33 . V_544 ; V_539 ++ ) {
V_542 = F_12 ( V_11 -> V_350 [ V_539 ] . V_280 . V_353 ) ;
V_543 = F_252 ( V_11 , V_545 , V_539 , V_493 ,
V_542 ) ;
if ( V_543 != V_542 ) {
F_22 ( & V_11 -> V_19 , L_189 ,
V_539 , V_543 ) ;
V_85 = 1 ;
break;
}
if ( memcmp ( V_493 , V_11 -> V_352 [ V_539 ] , V_542 )
!= 0 ) {
F_22 ( & V_11 -> V_19 , L_190 ,
V_539 ,
( (struct V_546 * ) V_493 ) ->
V_547 ) ;
V_85 = 1 ;
break;
}
}
if ( ! V_85 && V_540 ) {
V_543 = F_284 ( V_11 , V_11 -> V_33 . V_344 ,
V_493 , V_540 ) ;
if ( V_543 + 1 != V_540 ) {
F_22 ( & V_11 -> V_19 , L_191 ,
V_543 ) ;
V_85 = 1 ;
} else if ( memcmp ( V_493 , V_11 -> V_347 , V_543 ) != 0 ) {
F_22 ( & V_11 -> V_19 , L_192 ) ;
V_85 = 1 ;
}
}
F_49 ( V_493 ) ;
return V_85 ;
}
static int F_213 ( struct V_7 * V_11 )
{
struct V_7 * V_548 = V_11 -> V_22 ;
struct V_1 * V_549 ;
struct V_190 * V_154 = F_57 ( V_11 -> V_168 ) ;
struct V_492 V_33 = V_11 -> V_33 ;
struct V_537 * V_14 ;
int V_53 , V_481 , V_54 = 0 ;
int V_69 = V_11 -> V_125 ;
if ( V_11 -> V_87 == V_183 ||
V_11 -> V_87 == V_323 ) {
F_22 ( & V_11 -> V_19 , L_193 ,
V_11 -> V_87 ) ;
return - V_66 ;
}
if ( ! V_548 )
return - V_550 ;
V_549 = F_3 ( V_548 ) ;
if ( V_11 -> V_418 == 1 )
F_208 ( V_11 , 0 ) ;
V_14 = V_11 -> V_14 ;
V_11 -> V_14 = NULL ;
V_54 = F_209 ( V_11 ) ;
if ( V_54 ) {
F_30 ( & V_11 -> V_19 , L_194 , V_115 ) ;
goto V_551;
}
V_54 = F_201 ( V_11 ) ;
if ( V_54 ) {
F_30 ( & V_11 -> V_19 , L_195 ,
V_115 ) ;
goto V_551;
}
for ( V_53 = 0 ; V_53 < V_513 ; ++ V_53 ) {
F_236 ( V_11 ) ;
V_54 = F_244 ( V_549 , V_11 , V_69 , V_53 ) ;
if ( V_54 >= 0 || V_54 == - V_392 || V_54 == - V_113 )
break;
}
if ( V_54 < 0 )
goto V_551;
if ( F_282 ( V_11 , & V_33 , V_14 ) ) {
F_7 ( & V_11 -> V_19 , L_196 ) ;
V_11 -> V_33 = V_33 ;
goto V_551;
}
if ( ! V_11 -> V_8 )
goto V_400;
F_29 ( V_154 -> V_468 ) ;
V_54 = F_285 ( V_11 , V_11 -> V_8 , NULL , NULL ) ;
if ( V_54 < 0 ) {
F_67 ( & V_11 -> V_19 ,
L_197
L_198 ) ;
F_31 ( V_154 -> V_468 ) ;
goto V_551;
}
V_54 = F_14 ( V_11 , F_17 ( V_11 , 0 ) ,
V_552 , 0 ,
V_11 -> V_8 -> V_280 . V_547 , 0 ,
NULL , 0 , V_200 ) ;
if ( V_54 < 0 ) {
F_30 ( & V_11 -> V_19 ,
L_199 ,
V_11 -> V_8 -> V_280 . V_547 , V_54 ) ;
F_31 ( V_154 -> V_468 ) ;
goto V_551;
}
F_31 ( V_154 -> V_468 ) ;
F_69 ( V_11 , V_88 ) ;
for ( V_53 = 0 ; V_53 < V_11 -> V_8 -> V_280 . V_553 ; V_53 ++ ) {
struct V_554 * V_350 = V_11 -> V_8 ;
struct V_186 * V_187 = V_350 -> V_10 [ V_53 ] ;
struct V_555 * V_280 ;
V_280 = & V_187 -> V_294 -> V_280 ;
if ( V_280 -> V_556 == 0 ) {
F_286 ( V_11 , V_187 , true ) ;
F_287 ( V_11 , V_187 , true ) ;
V_54 = 0 ;
} else {
V_187 -> V_557 = 1 ;
V_54 = F_94 ( V_11 , V_280 -> V_558 ,
V_280 -> V_556 ) ;
V_187 -> V_557 = 0 ;
}
if ( V_54 < 0 ) {
F_30 ( & V_11 -> V_19 , L_200
L_201 ,
V_280 -> V_558 ,
V_280 -> V_556 ,
V_54 ) ;
goto V_551;
}
for ( V_481 = 0 ; V_481 < V_187 -> V_294 -> V_280 . V_303 ; V_481 ++ )
V_187 -> V_294 -> V_232 [ V_481 ] . V_559 = 0 ;
}
V_400:
F_208 ( V_11 , 1 ) ;
F_210 ( V_11 ) ;
F_203 ( V_11 ) ;
F_288 ( V_11 ) ;
V_11 -> V_14 = V_14 ;
return 0 ;
V_551:
F_70 ( V_549 , V_69 ) ;
F_288 ( V_11 ) ;
V_11 -> V_14 = V_14 ;
return - V_113 ;
}
int F_268 ( struct V_7 * V_11 )
{
int V_54 ;
int V_53 ;
unsigned int V_560 ;
struct V_77 * V_78 ;
struct V_554 * V_350 = V_11 -> V_8 ;
struct V_1 * V_2 = F_3 ( V_11 -> V_22 ) ;
if ( V_11 -> V_87 == V_183 ||
V_11 -> V_87 == V_323 ) {
F_22 ( & V_11 -> V_19 , L_193 ,
V_11 -> V_87 ) ;
return - V_66 ;
}
if ( ! V_11 -> V_22 ) {
F_22 ( & V_11 -> V_19 , L_202 , V_115 ) ;
return - V_550 ;
}
V_78 = V_2 -> V_79 [ V_11 -> V_125 - 1 ] ;
V_560 = F_289 () ;
F_183 ( V_11 ) ;
if ( V_350 ) {
for ( V_53 = 0 ; V_53 < V_350 -> V_280 . V_553 ; ++ V_53 ) {
struct V_186 * V_561 = V_350 -> V_10 [ V_53 ] ;
struct V_562 * V_153 ;
int V_563 = 0 ;
if ( V_561 -> V_19 . V_155 ) {
V_153 = F_290 ( V_561 -> V_19 . V_155 ) ;
if ( V_153 -> V_564 && V_153 -> V_565 )
V_563 = ( V_153 -> V_564 ) ( V_561 ) ;
else if ( V_561 -> V_566 ==
V_567 )
V_563 = 1 ;
if ( V_563 )
F_291 ( V_561 ) ;
}
}
}
F_197 ( V_78 ) ;
V_54 = F_213 ( V_11 ) ;
F_198 ( V_78 ) ;
if ( V_350 ) {
for ( V_53 = V_350 -> V_280 . V_553 - 1 ; V_53 >= 0 ; -- V_53 ) {
struct V_186 * V_561 = V_350 -> V_10 [ V_53 ] ;
struct V_562 * V_153 ;
int V_568 = V_561 -> V_569 ;
if ( ! V_568 && V_561 -> V_19 . V_155 ) {
V_153 = F_290 ( V_561 -> V_19 . V_155 ) ;
if ( V_153 -> V_565 )
V_568 = ( V_153 -> V_565 ) ( V_561 ) ;
else if ( V_561 -> V_566 ==
V_567 )
V_568 = 1 ;
if ( V_568 )
V_561 -> V_569 = 1 ;
}
}
F_292 ( V_11 ) ;
}
F_186 ( V_11 ) ;
F_293 ( V_560 ) ;
return V_54 ;
}
void F_294 ( struct V_186 * V_570 )
{
F_58 ( & V_570 -> V_571 ) ;
}
struct V_7 * F_295 ( struct V_7 * V_4 ,
int V_69 )
{
struct V_1 * V_2 = F_3 ( V_4 ) ;
if ( V_69 < 1 || V_69 > V_4 -> V_9 )
return NULL ;
return V_2 -> V_79 [ V_69 - 1 ] -> V_182 ;
}
void F_103 ( struct V_7 * V_4 ,
struct V_60 * V_280 )
{
struct V_1 * V_2 = F_3 ( V_4 ) ;
enum V_572 V_365 ;
int V_53 ;
if ( ! V_2 )
return;
if ( ! F_2 ( V_4 ) ) {
for ( V_53 = 1 ; V_53 <= V_4 -> V_9 ; V_53 ++ ) {
struct V_77 * V_78 = V_2 -> V_79 [ V_53 - 1 ] ;
V_365 = V_78 -> V_365 ;
if ( V_365 == V_367 ) {
T_2 V_573 = 1 << ( V_53 % 8 ) ;
if ( ! ( V_280 -> V_34 . V_248 . V_249 [ V_53 / 8 ] & V_573 ) ) {
F_22 ( & V_78 -> V_19 , L_203 ) ;
V_280 -> V_34 . V_248 . V_249 [ V_53 / 8 ] |= V_573 ;
}
}
}
} else {
T_1 V_574 = F_12 ( V_280 -> V_34 . V_35 . V_249 ) ;
for ( V_53 = 1 ; V_53 <= V_4 -> V_9 ; V_53 ++ ) {
struct V_77 * V_78 = V_2 -> V_79 [ V_53 - 1 ] ;
V_365 = V_78 -> V_365 ;
if ( V_365 == V_367 ) {
T_1 V_573 = 1 << V_53 ;
if ( ! ( V_574 & V_573 ) ) {
F_22 ( & V_78 -> V_19 , L_203 ) ;
V_574 |= V_573 ;
}
}
}
V_280 -> V_34 . V_35 . V_249 = F_227 ( V_574 ) ;
}
}
T_6 F_296 ( struct V_7 * V_4 ,
int V_69 )
{
struct V_1 * V_2 = F_3 ( V_4 ) ;
if ( ! V_2 )
return NULL ;
return F_297 ( & V_2 -> V_79 [ V_69 - 1 ] -> V_19 ) ;
}
