static T_1 F_1 ( const char * V_1 , T_2 * V_2 , int V_3 )
{
const char * V_4 ;
char V_5 ;
T_3 V_6 ;
T_3 V_7 = 0 ;
T_3 V_8 = 0 ;
T_3 V_9 ;
* V_2 = 0 ;
for ( V_4 = V_1 ; V_4 < & V_1 [ V_10 - 1 ] ; V_4 ++ ) {
V_5 = * V_4 ;
if ( V_5 == '\n' && V_4 [ 1 ] == '\0' )
continue;
if ( V_3 && V_8 ++ == 2 && V_7 ++ < 7 ) {
V_8 = 0 ;
if ( V_5 == ':' )
continue;
V_9 = 1 ;
goto V_11;
}
if ( V_5 == '\0' ) {
V_9 = 2 ;
if ( V_3 && V_7 != 8 )
goto V_11;
return V_4 - V_1 ;
}
V_9 = 3 ;
if ( isdigit ( V_5 ) )
V_6 = V_5 - '0' ;
else if ( isxdigit ( V_5 ) && ( islower ( V_5 ) || ! V_3 ) )
V_6 = tolower ( V_5 ) - 'a' + 10 ;
else
goto V_11;
* V_2 = ( * V_2 << 4 ) | V_6 ;
}
V_9 = 4 ;
V_11:
F_2 ( L_1 ,
V_9 , V_4 - V_1 , V_8 , V_7 ) ;
return - 1 ;
}
static T_1 F_3 ( char * V_12 , T_4 V_13 , T_2 V_2 )
{
T_5 V_14 [ 8 ] ;
F_4 ( V_2 , V_14 ) ;
return snprintf ( V_12 , V_13 ,
L_2 ,
V_14 [ 0 ] , V_14 [ 1 ] , V_14 [ 2 ] , V_14 [ 3 ] , V_14 [ 4 ] , V_14 [ 5 ] , V_14 [ 6 ] , V_14 [ 7 ] ) ;
}
static char * F_5 ( void )
{
return L_3 ;
}
static int F_6 ( const char * V_15 , T_2 * V_16 )
{
unsigned int V_17 , V_18 ;
T_5 V_2 [ 8 ] ;
memset ( V_2 , 0 , sizeof( V_2 ) ) ;
for ( V_17 = 0 , V_18 = 0 ; V_17 < 16 ; V_17 ++ ) {
int V_19 ;
V_19 = F_7 ( * V_15 ++ ) ;
if ( V_19 >= 0 )
V_18 = ( V_18 << 4 ) | V_19 ;
else
return - V_20 ;
if ( V_17 % 2 ) {
V_2 [ V_17 / 2 ] = V_18 & 0xff ;
V_18 = 0 ;
}
}
* V_16 = F_8 ( V_2 ) ;
return 0 ;
}
static int F_9 (
const char * V_1 ,
T_4 V_21 ,
T_2 * V_22 ,
T_2 * V_23 )
{
unsigned int V_24 = V_21 ;
int V_25 ;
* V_22 = 0 ;
* V_23 = 0 ;
if ( V_1 [ V_24 - 1 ] == '\n' || V_1 [ V_24 - 1 ] == 0 )
V_24 -- ;
if ( ( V_24 != ( 16 + 1 + 16 ) ) || ( V_1 [ 16 ] != ':' ) )
return - V_20 ;
V_25 = F_6 ( & V_1 [ 0 ] , V_22 ) ;
if ( V_25 != 0 )
return V_25 ;
V_25 = F_6 ( & V_1 [ 17 ] , V_23 ) ;
if ( V_25 != 0 )
return V_25 ;
return 0 ;
}
static char * F_10 ( void )
{
return L_4 ;
}
static char * F_11 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
struct V_30 * V_31 = V_29 -> V_31 ;
return V_31 -> V_32 ;
}
static T_6 F_13 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return V_29 -> V_33 ;
}
static int F_14 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return V_29 -> V_34 . V_35 ;
}
static int F_15 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return V_29 -> V_34 . V_36 ;
}
static int F_16 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return V_29 -> V_34 . V_37 ;
}
static int F_17 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return V_29 -> V_34 . V_38 ;
}
static int F_18 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return V_29 -> V_34 . V_39 ;
}
static int F_19 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return V_29 -> V_34 . V_40 ;
}
static T_3 F_20 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return V_29 -> V_33 ;
}
static void F_21 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = F_12 ( V_42 ,
struct V_43 , V_45 ) ;
F_22 ( & V_44 -> V_46 , 0 ) ;
}
static void F_23 ( struct V_43 * V_44 )
{
F_24 ( & V_44 -> V_45 , F_21 ) ;
F_25 ( V_47 , & V_44 -> V_45 ) ;
}
static void F_26 ( struct V_41 * V_42 )
{
struct V_48 * V_49 = F_12 ( V_42 , struct V_48 , V_42 ) ;
V_49 -> V_50 = 0 ;
F_27 ( V_49 -> V_51 & V_52 ) ;
V_49 -> V_53 -> V_54 . V_55 ++ ;
V_49 -> V_51 |= V_52 ;
F_22 ( & V_49 -> V_46 , 0 ) ;
}
static void F_28 ( struct V_48 * V_49 )
{
V_49 -> V_53 -> V_54 . V_56 ++ ;
V_49 -> V_50 = 1 ;
F_27 ( V_49 -> V_51 & V_57 ) ;
V_49 -> V_51 |= V_57 ;
F_24 ( & V_49 -> V_42 , F_26 ) ;
F_29 ( F_30 () , V_47 , & V_49 -> V_42 ) ;
}
static int F_31 ( struct V_46 * V_46 )
{
struct V_48 * V_49 ;
if ( ( V_46 -> V_58 & V_59 ) == 0 ) {
V_49 = F_12 ( V_46 , struct V_48 , V_46 ) ;
V_49 -> V_51 |= V_60 ;
}
return F_32 ( V_46 ) ;
}
static void F_33 ( struct V_46 * V_46 )
{
struct V_48 * V_49 ;
if ( V_46 -> V_58 & V_59 ) {
struct V_43 * V_44 = F_12 ( V_46 ,
struct V_43 , V_46 ) ;
F_34 ( V_44 ) ;
return;
}
V_49 = F_12 ( V_46 , struct V_48 , V_46 ) ;
F_35 ( V_49 ) ;
}
static void F_36 ( struct V_61 * V_61 )
{
struct V_62 * V_63 = F_12 ( V_61 ,
struct V_62 , V_64 ) ;
F_37 ( V_63 ) ;
}
static void F_38 ( struct V_62 * V_63 )
{
if ( ! V_63 )
return;
F_39 ( & V_63 -> V_53 -> V_65 -> V_66 . V_67 ) ;
F_40 ( & V_63 -> V_64 , F_36 ) ;
}
static void F_41 ( struct V_68 * V_69 )
{
struct V_62 * V_63 = V_69 -> V_70 ;
struct V_71 * V_53 ;
unsigned long V_72 ;
F_42 ( ! V_63 ) ;
V_53 = V_63 -> V_53 ;
F_43 ( & V_53 -> V_65 -> V_66 . V_67 , V_72 ) ;
F_44 ( V_69 ) ;
F_38 ( V_63 ) ;
F_45 ( & V_53 -> V_65 -> V_66 . V_67 , V_72 ) ;
}
static T_3 F_46 ( struct V_68 * V_69 )
{
return 0 ;
}
static int F_47 ( struct V_46 * V_46 )
{
struct V_48 * V_49 = F_12 ( V_46 ,
struct V_48 , V_46 ) ;
if ( V_49 -> V_73 ) {
F_2 ( L_5
L_6 ,
V_49 , F_48 ( & V_49 -> V_46 . V_74 ) ,
V_49 -> V_46 . V_75 ,
V_49 -> V_46 . V_76 ,
V_49 -> V_46 . V_58 ) ;
return 0 ;
}
V_49 -> V_51 |= V_77 ;
V_49 -> V_78 = V_46 -> V_79 ;
V_49 -> V_80 = F_49 ( V_46 ) ;
V_49 -> V_81 = V_46 -> V_82 ;
V_49 -> V_83 = V_46 -> V_84 ;
V_49 -> V_85 = V_46 -> V_86 ;
V_49 -> V_87 = V_46 -> V_88 ;
V_49 -> V_89 = V_46 -> V_90 -> V_91 . V_92 ;
V_46 -> V_93 = 0 ;
return F_50 ( V_49 ) ;
}
static int F_51 ( struct V_46 * V_46 )
{
unsigned long V_72 ;
F_43 ( & V_46 -> V_94 , V_72 ) ;
if ( V_46 -> V_76 == V_95 ||
V_46 -> V_76 == V_96 ) {
F_45 ( & V_46 -> V_94 , V_72 ) ;
F_52 ( & V_46 -> V_97 ,
50 ) ;
return 0 ;
}
F_45 ( & V_46 -> V_94 , V_72 ) ;
return 0 ;
}
static void F_53 ( struct V_98 * V_99 )
{
return;
}
static int F_54 ( struct V_46 * V_46 )
{
if ( ! ( V_46 -> V_58 & V_59 ) ) {
struct V_48 * V_49 = F_12 ( V_46 ,
struct V_48 , V_46 ) ;
return V_49 -> V_100 ;
}
return 0 ;
}
static int F_55 ( T_7 * V_53 , struct V_48 * V_49 ,
unsigned char * V_101 , T_8 V_79 , int V_102 ,
int V_103 , int V_104 )
{
struct V_46 * V_46 = & V_49 -> V_46 ;
struct V_68 * V_69 ;
struct V_62 * V_63 ;
#ifdef F_56
struct V_26 * V_27 ;
struct V_28 * V_29 ;
#endif
int V_72 = V_105 ;
if ( V_104 )
V_72 |= V_106 ;
if ( V_46 -> V_107 != V_108 )
V_72 |= V_109 ;
V_63 = V_49 -> V_63 ;
if ( ! V_63 ) {
F_57 ( L_7 ) ;
return - V_20 ;
}
V_69 = V_63 -> V_69 ;
if ( ! V_69 ) {
F_57 ( L_8 ) ;
return - V_20 ;
}
#ifdef F_56
V_27 = V_69 -> V_27 ;
V_29 = F_12 ( V_27 , struct V_28 , V_27 ) ;
if ( F_58 ( V_29 -> V_34 . V_110 ) ) {
return 0 ;
}
#endif
V_49 -> V_53 -> V_54 . V_111 ++ ;
return F_59 ( V_46 , V_69 , V_101 , & V_49 -> V_112 [ 0 ] ,
V_49 -> V_113 , V_79 , V_102 ,
V_103 , V_72 ) ;
}
static void F_60 ( struct V_41 * V_42 )
{
struct V_48 * V_49 = F_12 ( V_42 , struct V_48 , V_42 ) ;
unsigned long V_72 ;
V_49 -> V_50 = 0 ;
F_43 ( & V_49 -> V_114 , V_72 ) ;
V_49 -> V_115 = 1 ;
if ( V_49 -> V_73 ) {
V_49 -> V_116 = 1 ;
F_45 ( & V_49 -> V_114 , V_72 ) ;
F_28 ( V_49 ) ;
return;
}
F_45 ( & V_49 -> V_114 , V_72 ) ;
V_49 -> V_53 -> V_54 . V_117 ++ ;
if ( ! V_49 -> V_118 ) {
if ( V_49 -> V_46 . V_75 & V_119 ) {
F_61 ( & V_49 -> V_46 . V_97 ) ;
return;
}
switch ( V_49 -> V_120 ) {
case V_121 :
V_49 -> V_46 . V_93 =
V_122 ;
break;
case V_123 :
V_49 -> V_46 . V_93 =
V_124 ;
break;
case V_125 :
V_49 -> V_46 . V_93 =
V_126 ;
break;
case V_127 :
default:
break;
}
if ( V_49 -> V_46 . V_93 )
F_62 ( & V_49 -> V_46 ,
V_49 -> V_46 . V_93 ) ;
else
F_62 ( & V_49 -> V_46 ,
V_128 ) ;
return;
}
return F_63 ( & V_49 -> V_46 ) ;
}
static void F_64 ( struct V_48 * V_49 )
{
V_49 -> V_51 |= V_129 ;
V_49 -> V_50 = 1 ;
F_24 ( & V_49 -> V_42 , F_60 ) ;
F_29 ( F_30 () , V_47 , & V_49 -> V_42 ) ;
}
static int F_65 ( T_8 V_130 )
{
return 0 ;
}
static int F_66 ( struct V_48 * V_49 ,
T_9 * V_131 )
{
struct V_46 * V_46 = & V_49 -> V_46 ;
if ( ! ( V_46 -> V_132 & V_133 ) )
* V_131 |= V_134 ;
if ( ! ( V_46 -> V_132 & V_135 ) )
* V_131 |= V_136 ;
return 0 ;
}
static int F_67 ( struct V_43 * V_44 , T_8 V_137 ,
T_9 V_138 , T_8 V_130 )
{
struct V_62 * V_63 = V_44 -> V_63 ;
struct V_46 * V_46 = & V_44 -> V_46 ;
int V_139 = 0 ;
switch ( V_138 ) {
case V_140 :
F_2 ( L_9 , V_63 -> V_53 -> V_141 ) ;
V_139 = V_142 ;
break;
case V_143 :
F_2 ( L_10 , V_63 -> V_53 -> V_141 ) ;
V_139 = V_142 ;
break;
case V_144 :
F_2 ( L_11 , V_63 -> V_53 -> V_141 ) ;
V_139 = V_145 ;
break;
case V_146 :
F_2 ( L_12 , V_63 -> V_53 -> V_141 ) ;
V_139 = V_147 ;
break;
case V_148 :
F_2 ( L_13 , V_63 -> V_53 -> V_141 ) ;
V_139 = V_149 ;
break;
case V_150 :
F_2 ( L_14 , V_63 -> V_53 -> V_141 ) ;
V_139 = V_151 ;
break;
case V_152 :
F_2 ( L_15 , V_63 -> V_53 -> V_141 ) ;
V_139 = V_153 ;
break;
default:
F_2 ( L_16 ,
V_63 -> V_53 -> V_141 , V_138 ) ;
return - V_154 ;
}
return F_68 ( V_46 , V_63 -> V_69 , NULL , V_137 , V_44 ,
V_139 , V_155 , V_130 , V_105 ) ;
}
static int F_69 ( struct V_46 * V_46 )
{
struct V_48 * V_49 = F_12 ( V_46 ,
struct V_48 , V_46 ) ;
if ( V_49 -> V_73 ) {
F_2 ( L_17
L_6 ,
V_49 , F_48 ( & V_49 -> V_46 . V_74 ) ,
V_49 -> V_46 . V_75 ,
V_49 -> V_46 . V_76 ,
V_49 -> V_46 . V_58 ) ;
return 0 ;
}
V_49 -> V_51 |= V_156 ;
V_49 -> V_78 = V_46 -> V_79 ;
V_49 -> V_80 = F_49 ( V_46 ) ;
V_49 -> V_81 = V_46 -> V_82 ;
V_49 -> V_83 = V_46 -> V_84 ;
V_49 -> V_157 = 0 ;
V_49 -> V_85 = V_46 -> V_86 ;
V_49 -> V_87 = V_46 -> V_88 ;
V_49 -> V_89 = V_46 -> V_90 -> V_91 . V_92 ;
V_46 -> V_93 = 0 ;
return F_70 ( V_49 , V_158 | V_159 ,
V_46 -> V_160 ) ;
}
static int F_71 ( struct V_46 * V_46 )
{
struct V_48 * V_49 = F_12 ( V_46 ,
struct V_48 , V_46 ) ;
int V_161 = V_159 ;
V_49 -> V_78 = V_46 -> V_79 ;
V_49 -> V_83 = NULL ;
V_49 -> V_81 = 0 ;
V_49 -> V_157 = 0 ;
V_49 -> V_80 = F_49 ( V_46 ) ;
if ( V_49 -> V_51 & V_162 ) {
F_72 ( L_18 , V_49 ) ;
F_73 () ;
}
V_49 -> V_51 |= V_162 ;
if ( V_46 -> V_163 == V_164 ) {
if ( V_46 -> V_58 & V_165 ) {
V_46 -> V_58 &= ~ V_165 ;
V_46 -> V_166 = 0 ;
}
V_46 -> V_58 |= V_167 ;
V_46 -> V_166 += V_46 -> V_79 ;
V_49 -> V_78 = 0 ;
}
return F_70 ( V_49 , V_161 , V_46 -> V_160 ) ;
}
static void F_74 ( struct V_46 * V_46 )
{
struct V_168 * V_169 = V_46 -> V_168 ;
struct V_43 * V_44 = F_12 ( V_46 ,
struct V_43 , V_46 ) ;
F_2 ( L_19 ,
V_44 , V_169 -> V_170 , V_169 -> V_171 ) ;
switch ( V_169 -> V_171 ) {
case V_172 :
V_44 -> V_173 = V_174 ;
break;
case V_175 :
V_44 -> V_173 = V_176 ;
break;
case V_177 :
V_44 -> V_173 = V_178 ;
break;
case V_179 :
default:
V_44 -> V_173 = V_180 ;
break;
}
F_75 ( V_44 ) ;
}
static void F_76 ( struct V_46 * V_46 )
{
struct V_48 * V_49 = F_12 ( V_46 ,
struct V_48 , V_46 ) ;
unsigned long V_72 ;
if ( F_77 ( V_49 ) )
return;
F_43 ( & V_49 -> V_114 , V_72 ) ;
if ( ( V_49 -> V_100 == V_181 ) ||
( ( V_49 -> V_100 == V_182 ) &&
F_78 ( V_49 ) ) ) {
V_49 -> V_116 = 1 ;
F_45 ( & V_49 -> V_114 , V_72 ) ;
F_28 ( V_49 ) ;
return;
}
F_45 ( & V_49 -> V_114 , V_72 ) ;
return;
}
static void F_79 ( struct V_62 * V_63 )
{
struct V_98 * V_183 = V_63 -> V_69 -> V_98 ;
struct V_26 * V_27 = V_183 -> V_27 ;
struct V_184 * V_184 = V_27 -> V_185 ;
struct V_30 * V_31 = F_12 ( V_184 ,
struct V_30 , V_186 ) ;
struct V_187 * V_99 = F_12 ( V_183 ,
struct V_187 , V_98 ) ;
void * V_188 ;
F_2 ( L_20 , V_99 -> V_189 ) ;
V_188 = F_80 ( & V_31 -> V_190 , V_99 -> V_189 ) ;
if ( F_27 ( V_188 && ( V_188 != V_183 ) ) ) {
F_81 ( & V_31 -> V_190 , V_99 -> V_189 ,
V_188 , V_155 ) ;
}
F_2 ( L_21 ,
V_183 , V_99 -> V_191 , V_99 -> V_189 ) ;
F_82 ( V_31 , V_99 , V_63 ) ;
}
static void F_83 ( struct V_62 * V_63 )
{
F_39 ( & V_63 -> V_53 -> V_65 -> V_66 . V_67 ) ;
F_44 ( V_63 -> V_69 ) ;
}
static int F_84 ( struct V_98 * V_183 ,
const char * V_1 )
{
struct V_187 * V_99 =
F_12 ( V_183 , struct V_187 , V_98 ) ;
T_2 V_23 ;
if ( F_1 ( V_1 , & V_23 , 1 ) < 0 )
return - V_20 ;
V_99 -> V_191 = V_23 ;
F_3 ( & V_99 -> V_192 [ 0 ] , V_10 , V_23 ) ;
return 0 ;
}
static T_1 F_85 ( struct V_193 * V_194 ,
char * V_195 )
{
struct V_26 * V_27 = F_86 ( V_194 ) ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return snprintf ( V_195 , V_196 , L_22 ,
F_87 ( & V_29 -> V_197 ) ) ;
}
static void F_88 ( struct V_41 * V_42 )
{
struct V_28 * V_198 = F_12 ( V_42 ,
struct V_28 , V_199 ) ;
struct V_26 * V_27 = & V_198 -> V_27 ;
struct V_71 * V_200 = V_198 -> V_31 -> V_201 ;
if ( ! F_89 ( & V_27 -> V_202 . V_203 ) ) {
F_90 ( & V_198 -> V_197 , 1 ) ;
F_91 ( V_200 ) ;
}
F_61 ( & V_198 -> V_204 ) ;
}
static void F_92 ( struct V_41 * V_42 )
{
struct V_28 * V_198 = F_12 ( V_42 ,
struct V_28 , V_199 ) ;
struct V_26 * V_27 = & V_198 -> V_27 ;
struct V_71 * V_200 = V_198 -> V_31 -> V_201 ;
if ( ! F_93 ( V_200 -> V_205 . V_206 ) ) {
F_90 ( & V_198 -> V_197 , 0 ) ;
F_94 ( & V_27 -> V_202 . V_203 ) ;
}
F_61 ( & V_198 -> V_204 ) ;
}
static T_1 F_95 ( struct V_193 * V_194 ,
const char * V_195 , T_4 V_21 )
{
struct V_26 * V_27 = F_86 ( V_194 ) ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_207 ;
int V_25 ;
V_25 = F_96 ( V_195 , 0 , & V_207 ) ;
if ( V_25 < 0 ) {
F_57 ( L_23 , V_25 ) ;
return - V_20 ;
}
if ( ( V_207 != 1 ) && ( V_207 != 0 ) ) {
F_57 ( L_24 , V_207 ) ;
return - V_20 ;
}
if ( V_207 ) {
if ( F_87 ( & V_29 -> V_197 ) )
return - V_208 ;
F_24 ( & V_29 -> V_199 , F_88 ) ;
} else {
if ( ! F_87 ( & V_29 -> V_197 ) )
return V_21 ;
F_24 ( & V_29 -> V_199 , F_92 ) ;
}
F_97 ( & V_29 -> V_204 ) ;
F_98 ( & V_29 -> V_199 ) ;
F_99 ( & V_29 -> V_204 ) ;
if ( V_207 ) {
if ( ! F_87 ( & V_29 -> V_197 ) )
return - V_209 ;
} else {
if ( F_87 ( & V_29 -> V_197 ) )
return - V_210 ;
}
return V_21 ;
}
static T_1 F_100 ( struct V_193 * V_194 ,
char * V_195 )
{
return F_101 ( F_86 ( V_194 ) , V_195 ) ;
}
static T_1 F_102 ( struct V_193 * V_194 ,
const char * V_195 , T_4 V_21 )
{
struct V_26 * V_27 = F_86 ( V_194 ) ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_211 ;
int V_212 = F_96 ( V_195 , 0 , & V_211 ) ;
if ( V_212 ) {
F_57 ( L_25 , V_212 ) ;
return V_212 ;
}
if ( V_211 != 0 && V_211 != 1 && V_211 != 3 ) {
F_57 ( L_26 , V_211 ) ;
return - V_20 ;
}
V_29 -> V_34 . V_40 = V_211 ;
return V_21 ;
}
static T_1 F_103 ( struct V_193 * V_194 ,
char * V_195 )
{
struct V_26 * V_27 = F_86 ( V_194 ) ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return sprintf ( V_195 , L_22 , V_29 -> V_34 . V_40 ) ;
}
static struct V_26 * F_104 (
struct V_184 * V_2 ,
struct V_213 * V_214 ,
const char * V_1 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_186 ) ;
struct V_28 * V_29 ;
unsigned long V_215 ;
int V_212 ;
if ( strstr ( V_1 , L_27 ) != V_1 )
return F_105 ( - V_20 ) ;
if ( F_96 ( V_1 + 5 , 10 , & V_215 ) || V_215 > V_216 )
return F_105 ( - V_20 ) ;
if ( ( V_215 != 1 ) ) {
F_57 ( L_28 ) ;
return F_105 ( - V_154 ) ;
}
V_29 = F_106 ( sizeof( struct V_28 ) , V_217 ) ;
if ( ! V_29 ) {
F_57 ( L_29 ) ;
return F_105 ( - V_218 ) ;
}
V_29 -> V_31 = V_31 ;
V_29 -> V_33 = V_215 ;
V_29 -> V_34 . V_35 = 1 ;
V_29 -> V_34 . V_37 = 1 ;
V_29 -> V_34 . V_36 = 1 ;
V_29 -> V_34 . V_39 = 1 ;
V_29 -> V_34 . V_110 = 0 ;
V_212 = F_107 ( V_2 , & V_29 -> V_27 , V_219 ) ;
if ( V_212 < 0 ) {
F_108 ( V_29 ) ;
return NULL ;
}
V_31 -> V_220 = V_29 ;
return & V_29 -> V_27 ;
}
static void F_109 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
struct V_30 * V_31 = V_29 -> V_31 ;
struct V_71 * V_53 = V_31 -> V_201 ;
if ( V_53 -> V_205 . V_206 && ! V_53 -> V_205 . V_206 -> V_221 )
F_93 ( V_53 -> V_205 . V_206 ) ;
F_110 ( V_27 ) ;
V_31 -> V_220 = NULL ;
F_108 ( V_29 ) ;
}
static T_1 F_111 ( struct V_193 * V_194 ,
char * V_195 )
{
return F_85 ( V_194 , V_195 ) ;
}
static T_1 F_112 ( struct V_193 * V_194 ,
const char * V_195 , T_4 V_21 )
{
struct V_26 * V_27 = F_86 ( V_194 ) ;
struct V_184 * V_184 = V_27 -> V_185 ;
struct V_30 * V_31 = F_12 ( V_184 ,
struct V_30 , V_186 ) ;
struct V_71 * V_53 = V_31 -> V_201 ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_207 ;
int V_25 ;
V_25 = F_96 ( V_195 , 0 , & V_207 ) ;
if ( V_25 < 0 ) {
F_57 ( L_23 , V_25 ) ;
return - V_20 ;
}
if ( ( V_207 != 1 ) && ( V_207 != 0 ) ) {
F_57 ( L_24 , V_207 ) ;
return - V_20 ;
}
if ( V_207 ) {
if ( F_87 ( & V_29 -> V_197 ) )
return - V_208 ;
F_90 ( & V_29 -> V_197 , 1 ) ;
F_91 ( V_53 ) ;
} else {
if ( ! F_87 ( & V_29 -> V_197 ) )
return V_21 ;
F_90 ( & V_29 -> V_197 , 0 ) ;
F_93 ( V_53 -> V_205 . V_206 ) ;
}
return V_21 ;
}
static struct V_26 * F_113 (
struct V_184 * V_2 ,
struct V_213 * V_214 ,
const char * V_1 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_186 ) ;
struct V_28 * V_29 ;
unsigned long V_215 ;
int V_212 ;
if ( strstr ( V_1 , L_27 ) != V_1 )
return F_105 ( - V_20 ) ;
if ( F_96 ( V_1 + 5 , 10 , & V_215 ) || V_215 > V_216 )
return F_105 ( - V_20 ) ;
V_29 = F_106 ( sizeof( struct V_28 ) , V_217 ) ;
if ( ! V_29 ) {
F_57 ( L_29 ) ;
return F_105 ( - V_218 ) ;
}
V_29 -> V_31 = V_31 ;
V_29 -> V_33 = V_215 ;
V_29 -> V_34 . V_35 = 1 ;
V_29 -> V_34 . V_37 = 1 ;
V_29 -> V_34 . V_36 = 1 ;
V_29 -> V_34 . V_39 = 1 ;
V_212 = F_107 ( V_2 , & V_29 -> V_27 , V_219 ) ;
if ( V_212 < 0 ) {
F_108 ( V_29 ) ;
return NULL ;
}
V_31 -> V_220 = V_29 ;
return & V_29 -> V_27 ;
}
static struct V_62 * F_114 (
T_7 * V_53 ,
const T_10 * V_222 )
{
struct V_30 * V_31 ;
struct V_98 * V_183 ;
struct V_187 * V_99 ;
T_3 V_223 ;
V_31 = V_53 -> V_205 . V_224 ;
if ( ! V_31 ) {
F_57 ( L_30 ) ;
F_73 () ;
return NULL ;
}
V_223 = F_115 ( V_222 ) ;
F_2 ( L_31 , V_223 ) ;
V_183 = F_116 ( & V_31 -> V_190 , V_223 ) ;
if ( ! V_183 ) {
F_2 ( L_32 , V_223 ) ;
return NULL ;
}
F_2 ( L_33 ,
V_183 , V_183 -> V_225 ) ;
V_99 = F_12 ( V_183 , struct V_187 , V_98 ) ;
if ( ! V_99 -> V_62 ) {
F_57 ( L_34 ) ;
return NULL ;
}
return V_99 -> V_62 ;
}
static void F_117 (
struct V_30 * V_31 ,
struct V_98 * V_226 ,
struct V_187 * V_99 ,
struct V_68 * V_69 ,
struct V_62 * V_62 ,
T_10 * V_222 )
{
T_3 V_223 ;
void * V_227 ;
int V_25 ;
V_223 = F_115 ( V_222 ) ;
F_2 ( L_35 , V_223 ) ;
V_227 = F_116 ( & V_31 -> V_190 , V_223 ) ;
if ( ! V_227 ) {
if ( V_226 ) {
F_2 ( L_36 ) ;
V_99 -> V_189 = V_223 ;
V_25 = F_81 ( & V_31 -> V_190 , V_223 ,
V_226 , V_155 ) ;
if ( V_25 )
F_118 ( V_228 L_37 ,
( int ) V_223 ) ;
} else {
F_2 ( L_38 ) ;
}
V_62 -> V_69 = V_69 ;
V_99 -> V_62 = V_62 ;
return;
}
if ( V_99 -> V_62 ) {
if ( V_226 == NULL ) {
F_2 ( L_39 ) ;
F_80 ( & V_31 -> V_190 , V_223 ) ;
V_99 -> V_62 = NULL ;
return;
}
F_2 ( L_40 ) ;
F_119 ( & V_31 -> V_190 , V_223 , V_226 ) ;
V_62 -> V_69 = V_69 ;
V_99 -> V_62 = V_62 ;
return;
}
if ( V_226 == NULL ) {
F_2 ( L_41 ) ;
F_80 ( & V_31 -> V_190 , V_223 ) ;
return;
}
F_2 ( L_42 ) ;
F_119 ( & V_31 -> V_190 , V_223 , V_226 ) ;
V_62 -> V_69 = V_69 ;
V_99 -> V_62 = V_62 ;
F_2 ( L_43 ,
V_99 -> V_62 , V_226 , V_226 -> V_225 ) ;
}
static struct V_62 * F_120 (
T_7 * V_53 ,
const T_9 V_229 )
{
struct V_30 * V_31 ;
struct V_98 * V_183 ;
struct V_187 * V_99 ;
struct V_230 * V_231 ;
V_31 = V_53 -> V_205 . V_224 ;
if ( ! V_31 ) {
F_57 ( L_30 ) ;
F_73 () ;
return NULL ;
}
F_2 ( L_44 , V_229 ) ;
V_231 = V_31 -> V_232 + V_229 ;
V_183 = V_231 -> V_183 ;
if ( ! V_183 ) {
F_2 ( L_45 ,
V_229 ) ;
return NULL ;
}
V_99 = F_12 ( V_183 , struct V_187 , V_98 ) ;
if ( ! V_99 -> V_62 ) {
F_57 ( L_34 ) ;
return NULL ;
}
return V_99 -> V_62 ;
}
static void F_121 (
struct V_30 * V_31 ,
struct V_98 * V_226 ,
struct V_187 * V_99 ,
struct V_68 * V_69 ,
struct V_62 * V_62 ,
T_9 V_229 )
{
struct V_98 * V_233 ;
struct V_230 * V_231 ;
F_2 ( L_46 , V_229 ) ;
V_231 = & ( (struct V_230 * )
V_31 -> V_232 ) [ V_229 ] ;
V_233 = V_231 -> V_183 ;
if ( ! V_233 ) {
F_2 ( L_47 ) ;
V_231 -> V_183 = V_226 ;
if ( V_62 -> V_69 != V_69 )
V_62 -> V_69 = V_69 ;
if ( V_99 -> V_62 != V_62 )
V_99 -> V_62 = V_62 ;
return;
}
if ( V_99 -> V_62 ) {
if ( V_226 == NULL ) {
F_2 ( L_48 ) ;
V_231 -> V_183 = NULL ;
V_99 -> V_62 = NULL ;
return;
}
F_2 ( L_49 ) ;
V_231 -> V_183 = V_226 ;
if ( V_62 -> V_69 != V_69 )
V_62 -> V_69 = V_69 ;
if ( V_99 -> V_62 != V_62 )
V_99 -> V_62 = V_62 ;
return;
}
if ( V_226 == NULL ) {
F_2 ( L_50 ) ;
V_231 -> V_183 = NULL ;
return;
}
F_2 ( L_51 ) ;
V_231 -> V_183 = V_226 ;
if ( V_62 -> V_69 != V_69 )
V_62 -> V_69 = V_69 ;
if ( V_99 -> V_62 != V_62 )
V_99 -> V_62 = V_62 ;
F_2 ( L_52 ,
V_99 -> V_62 , V_226 , V_226 -> V_225 ) ;
}
static void F_82 ( struct V_30 * V_31 ,
struct V_187 * V_99 , struct V_62 * V_63 )
{
struct V_68 * V_69 = V_63 -> V_69 ;
unsigned char V_234 [ 3 ] ;
V_234 [ 0 ] = V_63 -> V_235 . V_14 . V_236 ;
V_234 [ 1 ] = V_63 -> V_235 . V_14 . V_237 ;
V_234 [ 2 ] = V_63 -> V_235 . V_14 . V_238 ;
F_117 ( V_31 , NULL , V_99 , V_69 ,
V_63 , V_234 ) ;
F_121 ( V_31 , NULL , V_99 , V_69 ,
V_63 , V_63 -> V_229 ) ;
}
static void F_122 ( struct V_62 * V_63 )
{
struct V_206 * V_66 = V_63 -> V_66 ;
struct V_239 * V_240 = V_66 -> V_240 ;
T_7 * V_53 = F_123 ( V_240 -> V_241 ) ;
struct V_68 * V_69 ;
struct V_30 * V_31 ;
F_42 ( F_124 () ) ;
V_69 = V_63 -> V_69 ;
if ( ! V_69 ) {
F_57 ( L_53 ) ;
F_73 () ;
return;
}
V_31 = V_53 -> V_205 . V_224 ;
if ( ! V_31 ) {
F_57 ( L_30 ) ;
F_73 () ;
return;
}
F_125 ( V_69 ) ;
F_126 ( V_63 -> V_69 ) ;
F_127 ( V_63 -> V_69 ) ;
}
static int F_128 ( struct V_26 * V_27 ,
struct V_68 * V_69 , void * V_242 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
struct V_30 * V_31 = V_29 -> V_31 ;
struct V_239 * V_240 = V_31 -> V_201 -> V_65 ;
struct V_98 * V_183 = V_69 -> V_98 ;
struct V_187 * V_99 = F_12 ( V_183 ,
struct V_187 , V_98 ) ;
struct V_62 * V_243 = V_242 ;
T_9 V_229 = V_243 -> V_229 ;
unsigned long V_72 ;
unsigned char V_234 [ 3 ] ;
V_234 [ 0 ] = V_243 -> V_235 . V_14 . V_236 ;
V_234 [ 1 ] = V_243 -> V_235 . V_14 . V_237 ;
V_234 [ 2 ] = V_243 -> V_235 . V_14 . V_238 ;
F_43 ( & V_240 -> V_66 . V_67 , V_72 ) ;
F_117 ( V_31 , V_183 , V_99 ,
V_69 , V_243 , V_234 ) ;
F_121 ( V_31 , V_183 , V_99 ,
V_69 , V_243 , V_229 ) ;
F_45 ( & V_240 -> V_66 . V_67 , V_72 ) ;
return 0 ;
}
static int F_129 (
T_7 * V_53 ,
unsigned char * V_244 ,
struct V_62 * V_243 )
{
struct V_239 * V_240 = V_53 -> V_65 ;
struct V_30 * V_31 ;
struct V_28 * V_29 ;
struct V_68 * V_69 ;
unsigned char V_245 [ 36 ] ;
int V_246 = ( V_240 -> V_247 ) ? V_240 -> V_247 :
V_248 ;
V_31 = V_53 -> V_205 . V_224 ;
if ( ! V_31 ) {
F_57 ( L_30 ) ;
F_73 () ;
return - V_20 ;
}
V_29 = V_31 -> V_220 ;
if ( ! V_29 ) {
F_57 ( L_54 ) ;
return - V_20 ;
}
memset ( & V_245 , 0 , 36 ) ;
snprintf ( V_245 , sizeof( V_245 ) , L_55 , V_244 ) ;
V_69 = F_130 ( & V_29 -> V_27 , V_246 ,
sizeof( struct V_48 ) ,
V_249 , V_245 ,
V_243 , F_128 ) ;
if ( F_131 ( V_69 ) )
return F_132 ( V_69 ) ;
return 0 ;
}
static void F_133 ( struct V_62 * V_63 , T_11 V_222 ,
T_9 V_229 , bool V_250 )
{
struct V_206 * V_66 = V_63 -> V_66 ;
struct V_239 * V_240 = V_66 -> V_240 ;
T_7 * V_53 = F_123 ( V_240 -> V_241 ) ;
struct V_30 * V_31 = V_53 -> V_205 . V_224 ;
struct V_98 * V_183 = V_63 -> V_69 -> V_98 ;
struct V_187 * V_99 = F_12 ( V_183 ,
struct V_187 , V_98 ) ;
T_3 V_223 ;
if ( V_63 -> V_229 != V_229 || V_63 -> V_235 . V_251 != V_222 . V_251 )
F_134 ( L_56 ,
V_63 , V_63 -> V_245 ,
V_63 -> V_229 , V_229 , V_63 -> V_235 . V_14 . V_236 ,
V_63 -> V_235 . V_14 . V_237 , V_63 -> V_235 . V_14 . V_238 , V_222 . V_14 . V_236 ,
V_222 . V_14 . V_237 , V_222 . V_14 . V_238 ) ;
if ( V_63 -> V_229 != V_229 ) {
if ( V_31 -> V_232 [ V_63 -> V_229 ] . V_183 == V_183 )
V_31 -> V_232 [ V_63 -> V_229 ] . V_183 = NULL ;
V_31 -> V_232 [ V_229 ] . V_183 = V_183 ;
V_63 -> V_229 = V_229 ;
}
if ( V_63 -> V_235 . V_251 != V_222 . V_251 ) {
V_223 = ( ( ( T_3 ) V_63 -> V_235 . V_14 . V_236 << 16 ) |
( ( T_3 ) V_63 -> V_235 . V_14 . V_237 << 8 ) |
( ( T_3 ) V_63 -> V_235 . V_14 . V_238 ) ) ;
if ( F_116 ( & V_31 -> V_190 , V_223 ) )
F_135 ( F_80 ( & V_31 -> V_190 , V_223 ) !=
V_183 , L_57 ,
V_63 -> V_235 . V_14 . V_236 , V_63 -> V_235 . V_14 . V_237 ,
V_63 -> V_235 . V_14 . V_238 ) ;
else
F_135 ( 1 , L_58 ,
V_63 -> V_235 . V_14 . V_236 , V_63 -> V_235 . V_14 . V_237 ,
V_63 -> V_235 . V_14 . V_238 ) ;
V_223 = ( ( ( T_3 ) V_222 . V_14 . V_236 << 16 ) |
( ( T_3 ) V_222 . V_14 . V_237 << 8 ) |
( ( T_3 ) V_222 . V_14 . V_238 ) ) ;
if ( F_116 ( & V_31 -> V_190 , V_223 ) ) {
F_135 ( 1 , L_59 ,
V_222 . V_14 . V_236 , V_222 . V_14 . V_237 , V_222 . V_14 . V_238 ) ;
F_119 ( & V_31 -> V_190 , V_223 , V_183 ) ;
} else {
F_81 ( & V_31 -> V_190 , V_223 , V_183 ,
V_155 ) ;
}
V_63 -> V_235 = V_222 ;
V_99 -> V_189 = V_223 ;
}
V_63 -> V_250 = V_250 ;
V_63 -> V_252 = 1 ;
V_63 -> V_253 = 0 ;
}
static int F_136 ( struct V_30 * V_31 )
{
int V_25 ;
V_25 = F_137 ( & V_31 -> V_190 ) ;
if ( V_25 ) {
F_57 ( L_60 ) ;
return V_25 ;
}
V_31 -> V_232 = F_138 ( sizeof( struct V_230 ) *
65536 ) ;
if ( ! V_31 -> V_232 ) {
F_57 ( L_61 ,
sizeof( struct V_230 ) * 65536 ) ;
F_139 ( & V_31 -> V_190 ) ;
return - V_218 ;
}
memset ( V_31 -> V_232 , 0 , sizeof( struct V_230 )
* 65536 ) ;
F_2 ( L_62 ,
sizeof( struct V_230 ) * 65536 ) ;
return 0 ;
}
static int F_140 ( struct V_71 * V_53 ,
void * V_224 ,
T_2 V_254 , T_2 V_255 )
{
struct V_239 * V_240 = V_53 -> V_65 ;
struct V_30 * V_31 =
(struct V_30 * ) V_224 ;
V_240 -> V_66 . V_256 = & V_257 ;
V_53 -> V_205 . V_224 = V_224 ;
V_31 -> V_201 = V_53 ;
return 0 ;
}
static struct V_184 * F_141 (
struct V_258 * V_259 ,
struct V_213 * V_214 ,
const char * V_1 )
{
struct V_30 * V_31 ;
T_2 V_22 ;
int V_212 = - V_209 ;
if ( F_1 ( V_1 , & V_22 , 1 ) < 0 )
return F_105 ( - V_20 ) ;
V_31 = F_106 ( sizeof( struct V_30 ) , V_217 ) ;
if ( ! V_31 ) {
F_57 ( L_63 ) ;
return F_105 ( - V_218 ) ;
}
V_31 -> V_260 = V_22 ;
F_3 ( & V_31 -> V_261 [ 0 ] , V_10 ,
V_22 ) ;
sprintf ( V_31 -> V_32 , L_64 , ( unsigned long long ) V_22 ) ;
V_212 = F_136 ( V_31 ) ;
if ( V_212 != 0 )
goto V_262;
V_212 = F_142 ( V_31 , V_22 , 0 , 0 ,
F_140 ) ;
if ( V_212 != 0 )
goto V_263;
return & V_31 -> V_186 ;
V_263:
F_143 ( V_31 -> V_232 ) ;
F_139 ( & V_31 -> V_190 ) ;
V_262:
F_108 ( V_31 ) ;
return F_105 ( V_212 ) ;
}
static void F_144 ( struct V_184 * V_2 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_186 ) ;
struct V_71 * V_53 = V_31 -> V_201 ;
struct V_98 * V_188 ;
T_3 V_223 = 0 ;
if ( V_53 -> V_205 . V_206 && ! V_53 -> V_205 . V_206 -> V_264 )
F_145 ( V_53 -> V_205 . V_206 ) ;
F_146 ( V_53 ) ;
F_143 ( V_31 -> V_232 ) ;
F_147 (&lport->lport_fcport_map, key, node)
F_80 ( & V_31 -> V_190 , V_223 ) ;
F_139 ( & V_31 -> V_190 ) ;
F_108 ( V_31 ) ;
}
static int F_148 ( struct V_71 * V_200 ,
void * V_224 ,
T_2 V_254 , T_2 V_255 )
{
struct V_265 * V_266 ;
struct V_267 * V_268 = V_200 -> V_269 ;
struct V_71 * V_270 ;
struct V_30 * V_31 =
(struct V_30 * ) V_224 ;
struct V_30 * V_271 =
(struct V_30 * ) V_200 -> V_205 . V_224 ;
struct V_272 V_273 ;
if ( F_149 ( V_200 ) ) {
F_57 ( L_65 ) ;
return - V_210 ;
}
if ( ! V_271 || ! V_271 -> V_220 ||
! F_87 ( & V_271 -> V_220 -> V_197 ) ) {
F_57 ( L_66 ) ;
return - V_210 ;
}
memset ( & V_273 , 0 , sizeof( V_273 ) ) ;
V_273 . V_245 = V_254 ;
V_273 . V_274 = V_255 ;
V_273 . V_275 = V_276 ;
V_273 . V_277 = V_278 ;
V_273 . V_279 = false ;
V_266 = F_150 ( V_268 , 0 , & V_273 ) ;
if ( ! V_266 ) {
F_57 ( L_67 ) ;
return - V_209 ;
}
V_270 = (struct V_71 * ) V_266 -> V_280 ;
V_270 -> V_205 . V_224 = V_224 ;
V_31 -> V_201 = V_270 ;
F_151 ( V_270 -> V_269 ) ;
return 0 ;
}
static struct V_184 * F_152 (
struct V_258 * V_259 ,
struct V_213 * V_214 ,
const char * V_1 )
{
struct V_30 * V_31 ;
T_2 V_281 , V_254 , V_255 ;
char * V_242 , V_282 [ 128 ] ;
int V_212 ;
snprintf ( V_282 , 128 , L_68 , V_1 ) ;
V_242 = strchr ( V_282 , '@' ) ;
if ( ! V_242 ) {
F_57 ( L_69 ) ;
return F_105 ( - V_20 ) ;
}
* V_242 ++ = '\0' ;
if ( F_1 ( V_282 , & V_281 , 1 ) < 0 )
return F_105 ( - V_20 ) ;
if ( F_9 ( V_242 , strlen ( V_242 ) + 1 ,
& V_254 , & V_255 ) < 0 )
return F_105 ( - V_20 ) ;
V_31 = F_106 ( sizeof( struct V_30 ) , V_217 ) ;
if ( ! V_31 ) {
F_57 ( L_70 ) ;
return F_105 ( - V_218 ) ;
}
V_31 -> V_283 = V_254 ;
V_31 -> V_284 = V_255 ;
sprintf ( V_31 -> V_32 , L_64 , ( unsigned long long ) V_254 ) ;
V_212 = F_136 ( V_31 ) ;
if ( V_212 != 0 )
goto V_262;
V_212 = F_142 ( V_31 , V_281 , V_254 , V_255 ,
F_148 ) ;
if ( V_212 != 0 )
goto V_263;
return & V_31 -> V_186 ;
V_263:
F_143 ( V_31 -> V_232 ) ;
F_139 ( & V_31 -> V_190 ) ;
V_262:
F_108 ( V_31 ) ;
return F_105 ( V_212 ) ;
}
static void F_153 ( struct V_184 * V_2 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_186 ) ;
struct V_71 * V_270 = V_31 -> V_201 ;
struct V_239 * V_240 = V_270 -> V_65 ;
T_7 * V_200 = F_123 ( V_240 -> V_241 ) ;
F_154 ( V_270 -> V_269 ) ;
F_155 ( V_270 -> V_265 ) ;
F_154 ( V_200 -> V_269 ) ;
F_108 ( V_31 ) ;
}
static T_1 F_156 ( struct V_193 * V_194 ,
char * V_195 )
{
return sprintf ( V_195 ,
L_71
V_285 L_72 , V_286 , F_157 () -> V_287 ,
F_157 () -> V_288 ) ;
}
static int F_158 ( void )
{
int V_212 ;
F_2 ( L_73
V_285 L_72 , V_286 , F_157 () -> V_287 ,
F_157 () -> V_288 ) ;
V_212 = F_159 ( & V_289 ) ;
if ( V_212 )
return V_212 ;
V_212 = F_159 ( & V_290 ) ;
if ( V_212 )
goto V_291;
V_47 = F_160 ( L_74 ,
V_292 , 0 ) ;
if ( ! V_47 ) {
V_212 = - V_218 ;
goto V_293;
}
V_294 = F_160 ( L_75 , 0 , 0 ) ;
if ( ! V_294 ) {
V_212 = - V_218 ;
goto V_295;
}
return 0 ;
V_295:
F_161 ( V_47 ) ;
V_293:
F_162 ( & V_290 ) ;
V_291:
F_162 ( & V_289 ) ;
return V_212 ;
}
static void F_163 ( void )
{
F_161 ( V_294 ) ;
F_161 ( V_47 ) ;
F_162 ( & V_289 ) ;
F_162 ( & V_290 ) ;
}
static int T_12 F_164 ( void )
{
int V_212 ;
V_212 = F_158 () ;
if ( V_212 < 0 )
return V_212 ;
return 0 ;
}
static void T_13 F_165 ( void )
{
F_163 () ;
}
