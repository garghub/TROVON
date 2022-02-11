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
F_39 ( & V_63 -> V_65 -> V_66 -> V_67 . V_68 ) ;
F_40 ( & V_63 -> V_64 , F_36 ) ;
}
static void F_41 ( struct V_69 * V_70 )
{
struct V_62 * V_63 = V_70 -> V_71 ;
struct V_72 * V_65 ;
unsigned long V_73 ;
F_42 ( ! V_63 ) ;
V_65 = V_63 -> V_65 ;
F_43 ( & V_65 -> V_66 -> V_67 . V_68 , V_73 ) ;
F_44 ( V_70 ) ;
F_38 ( V_63 ) ;
F_45 ( & V_65 -> V_66 -> V_67 . V_68 , V_73 ) ;
}
static T_3 F_46 ( struct V_69 * V_70 )
{
return 0 ;
}
static int F_47 ( struct V_46 * V_46 )
{
struct V_48 * V_49 = F_12 ( V_46 ,
struct V_48 , V_46 ) ;
if ( V_49 -> V_74 ) {
F_2 ( L_5
L_6 ,
V_49 , F_48 ( & V_49 -> V_46 . V_75 ) ,
V_49 -> V_46 . V_76 ,
V_49 -> V_46 . V_77 ,
V_49 -> V_46 . V_58 ) ;
return 0 ;
}
V_49 -> V_51 |= V_78 ;
V_49 -> V_79 = V_46 -> V_80 ;
V_49 -> V_81 = F_49 ( V_46 ) ;
V_49 -> V_82 = V_46 -> V_83 ;
V_49 -> V_84 = V_46 -> V_85 ;
V_49 -> V_86 = V_46 -> V_87 ;
V_49 -> V_88 = V_46 -> V_89 ;
V_49 -> V_90 = V_46 -> V_91 -> V_92 . V_93 ;
V_46 -> V_94 = 0 ;
return F_50 ( V_49 ) ;
}
static int F_51 ( struct V_46 * V_46 )
{
unsigned long V_73 ;
F_43 ( & V_46 -> V_95 , V_73 ) ;
if ( V_46 -> V_77 == V_96 ||
V_46 -> V_77 == V_97 ) {
F_45 ( & V_46 -> V_95 , V_73 ) ;
F_52 ( & V_46 -> V_98 ,
50 ) ;
return 0 ;
}
F_45 ( & V_46 -> V_95 , V_73 ) ;
return 0 ;
}
static void F_53 ( struct V_99 * V_100 )
{
return;
}
static int F_54 ( struct V_46 * V_46 )
{
if ( ! ( V_46 -> V_58 & V_59 ) ) {
struct V_48 * V_49 = F_12 ( V_46 ,
struct V_48 , V_46 ) ;
return V_49 -> V_101 ;
}
return 0 ;
}
static int F_55 ( T_7 * V_65 , struct V_48 * V_49 ,
unsigned char * V_102 , T_8 V_80 , int V_103 ,
int V_104 , int V_105 )
{
struct V_46 * V_46 = & V_49 -> V_46 ;
struct V_69 * V_70 ;
struct V_62 * V_63 ;
#ifdef F_56
struct V_26 * V_27 ;
struct V_28 * V_29 ;
#endif
int V_73 = V_106 ;
if ( V_105 )
V_73 |= V_107 ;
if ( V_46 -> V_108 != V_109 )
V_73 |= V_110 ;
V_63 = V_49 -> V_63 ;
if ( ! V_63 ) {
F_57 ( L_7 ) ;
return - V_20 ;
}
V_70 = V_63 -> V_70 ;
if ( ! V_70 ) {
F_57 ( L_8 ) ;
return - V_20 ;
}
#ifdef F_56
V_27 = V_70 -> V_27 ;
V_29 = F_12 ( V_27 , struct V_28 , V_27 ) ;
if ( F_58 ( V_29 -> V_34 . V_111 ) ) {
return 0 ;
}
#endif
V_49 -> V_53 -> V_54 . V_112 ++ ;
return F_59 ( V_46 , V_70 , V_102 , & V_49 -> V_113 [ 0 ] ,
V_49 -> V_114 , V_80 , V_103 ,
V_104 , V_73 ) ;
}
static void F_60 ( struct V_41 * V_42 )
{
struct V_48 * V_49 = F_12 ( V_42 , struct V_48 , V_42 ) ;
V_49 -> V_50 = 0 ;
V_49 -> V_53 -> V_54 . V_115 ++ ;
if ( ! V_49 -> V_116 ) {
if ( V_49 -> V_46 . V_76 & V_117 ) {
F_61 ( & V_49 -> V_46 . V_98 ) ;
return;
}
switch ( V_49 -> V_118 ) {
case V_119 :
V_49 -> V_46 . V_94 =
V_120 ;
break;
case V_121 :
V_49 -> V_46 . V_94 =
V_122 ;
break;
case V_123 :
V_49 -> V_46 . V_94 =
V_124 ;
break;
case V_125 :
default:
break;
}
if ( V_49 -> V_46 . V_94 )
F_62 ( & V_49 -> V_46 ,
V_49 -> V_46 . V_94 ) ;
else
F_62 ( & V_49 -> V_46 ,
V_126 ) ;
return;
}
return F_63 ( & V_49 -> V_46 ) ;
}
static void F_64 ( struct V_48 * V_49 )
{
V_49 -> V_51 |= V_127 ;
V_49 -> V_50 = 1 ;
F_24 ( & V_49 -> V_42 , F_60 ) ;
F_29 ( F_30 () , V_47 , & V_49 -> V_42 ) ;
}
static int F_65 ( T_8 V_128 )
{
return 0 ;
}
static int F_66 ( struct V_48 * V_49 ,
T_9 * V_129 )
{
struct V_46 * V_46 = & V_49 -> V_46 ;
if ( ! ( V_46 -> V_130 & V_131 ) )
* V_129 |= V_132 ;
if ( ! ( V_46 -> V_130 & V_133 ) )
* V_129 |= V_134 ;
return 0 ;
}
static int F_67 ( struct V_43 * V_44 , T_2 V_135 ,
T_9 V_136 , T_8 V_128 )
{
struct V_62 * V_63 = V_44 -> V_63 ;
struct V_46 * V_46 = & V_44 -> V_46 ;
int V_137 = 0 ;
int V_73 = V_106 ;
switch ( V_136 ) {
case V_138 :
F_2 ( L_9 , V_63 -> V_65 -> V_139 ) ;
V_137 = V_140 ;
V_73 |= V_141 ;
break;
case V_142 :
F_2 ( L_10 , V_63 -> V_65 -> V_139 ) ;
V_137 = V_140 ;
break;
case V_143 :
F_2 ( L_11 , V_63 -> V_65 -> V_139 ) ;
V_137 = V_144 ;
break;
case V_145 :
F_2 ( L_12 , V_63 -> V_65 -> V_139 ) ;
V_137 = V_146 ;
break;
case V_147 :
F_2 ( L_13 , V_63 -> V_65 -> V_139 ) ;
V_137 = V_148 ;
break;
case V_149 :
F_2 ( L_14 , V_63 -> V_65 -> V_139 ) ;
V_137 = V_150 ;
break;
case V_151 :
F_2 ( L_15 , V_63 -> V_65 -> V_139 ) ;
V_137 = V_152 ;
break;
default:
F_2 ( L_16 ,
V_63 -> V_65 -> V_139 , V_136 ) ;
return - V_153 ;
}
return F_68 ( V_46 , V_63 -> V_70 , NULL , V_135 , V_44 ,
V_137 , V_154 , V_128 , V_73 ) ;
}
static int F_69 ( struct V_46 * V_46 )
{
struct V_48 * V_49 = F_12 ( V_46 ,
struct V_48 , V_46 ) ;
if ( V_49 -> V_74 ) {
F_2 ( L_17
L_6 ,
V_49 , F_48 ( & V_49 -> V_46 . V_75 ) ,
V_49 -> V_46 . V_76 ,
V_49 -> V_46 . V_77 ,
V_49 -> V_46 . V_58 ) ;
return 0 ;
}
V_49 -> V_51 |= V_155 ;
V_49 -> V_79 = V_46 -> V_80 ;
V_49 -> V_81 = F_49 ( V_46 ) ;
V_49 -> V_82 = V_46 -> V_83 ;
V_49 -> V_84 = V_46 -> V_85 ;
V_49 -> V_156 = 0 ;
V_49 -> V_86 = V_46 -> V_87 ;
V_49 -> V_88 = V_46 -> V_89 ;
V_49 -> V_90 = V_46 -> V_91 -> V_92 . V_93 ;
V_46 -> V_94 = 0 ;
return F_70 ( V_49 , V_157 | V_158 ,
V_46 -> V_159 ) ;
}
static int F_71 ( struct V_46 * V_46 )
{
struct V_48 * V_49 = F_12 ( V_46 ,
struct V_48 , V_46 ) ;
int V_160 = V_158 ;
if ( V_49 -> V_74 ) {
F_2 (
L_18 ,
V_49 , F_48 ( & V_49 -> V_46 . V_75 ) ,
V_49 -> V_46 . V_76 , V_49 -> V_46 . V_77 ,
V_49 -> V_46 . V_58 ) ;
return 0 ;
}
V_49 -> V_79 = V_46 -> V_80 ;
V_49 -> V_84 = NULL ;
V_49 -> V_82 = 0 ;
V_49 -> V_156 = 0 ;
V_49 -> V_81 = F_49 ( V_46 ) ;
if ( V_49 -> V_51 & V_161 ) {
F_72 ( L_19 , V_49 ) ;
F_73 () ;
}
V_49 -> V_51 |= V_161 ;
if ( V_46 -> V_162 == V_163 ) {
if ( V_46 -> V_58 & V_164 ) {
V_46 -> V_58 &= ~ V_164 ;
V_46 -> V_165 = 0 ;
}
V_46 -> V_58 |= V_166 ;
V_46 -> V_165 += V_46 -> V_80 ;
V_49 -> V_79 = 0 ;
}
return F_70 ( V_49 , V_160 , V_46 -> V_159 ) ;
}
static void F_74 ( struct V_46 * V_46 )
{
struct V_167 * V_168 = V_46 -> V_167 ;
struct V_43 * V_44 = F_12 ( V_46 ,
struct V_43 , V_46 ) ;
F_2 ( L_20 ,
V_44 , V_168 -> V_169 , V_168 -> V_170 ) ;
switch ( V_168 -> V_170 ) {
case V_171 :
V_44 -> V_172 = V_173 ;
break;
case V_174 :
V_44 -> V_172 = V_175 ;
break;
case V_176 :
V_44 -> V_172 = V_177 ;
break;
case V_178 :
default:
V_44 -> V_172 = V_179 ;
break;
}
F_75 ( V_44 ) ;
}
static void F_76 ( struct V_46 * V_46 )
{
struct V_48 * V_49 = F_12 ( V_46 ,
struct V_48 , V_46 ) ;
if ( F_77 ( V_49 ) )
return;
}
static void F_78 ( struct V_62 * V_63 )
{
struct V_99 * V_180 = V_63 -> V_70 -> V_99 ;
struct V_26 * V_27 = V_180 -> V_27 ;
struct V_181 * V_181 = V_27 -> V_182 ;
struct V_30 * V_31 = F_12 ( V_181 ,
struct V_30 , V_183 ) ;
struct V_184 * V_100 = F_12 ( V_180 ,
struct V_184 , V_99 ) ;
void * V_185 ;
F_2 ( L_21 , V_100 -> V_186 ) ;
V_185 = F_79 ( & V_31 -> V_187 , V_100 -> V_186 ) ;
if ( F_27 ( V_185 && ( V_185 != V_180 ) ) ) {
F_80 ( & V_31 -> V_187 , V_100 -> V_186 ,
V_185 , V_154 ) ;
}
F_2 ( L_22 ,
V_180 , V_100 -> V_188 , V_100 -> V_186 ) ;
F_81 ( V_31 , V_100 , V_63 ) ;
}
static void F_82 ( struct V_62 * V_63 )
{
F_39 ( & V_63 -> V_65 -> V_66 -> V_67 . V_68 ) ;
F_44 ( V_63 -> V_70 ) ;
}
static int F_83 ( struct V_99 * V_180 ,
const char * V_1 )
{
struct V_184 * V_100 =
F_12 ( V_180 , struct V_184 , V_99 ) ;
T_2 V_23 ;
if ( F_1 ( V_1 , & V_23 , 1 ) < 0 )
return - V_20 ;
V_100 -> V_188 = V_23 ;
F_3 ( & V_100 -> V_189 [ 0 ] , V_10 , V_23 ) ;
return 0 ;
}
static T_1 F_84 ( struct V_190 * V_191 ,
char * V_192 )
{
struct V_26 * V_27 = F_85 ( V_191 ) ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return snprintf ( V_192 , V_193 , L_23 ,
F_86 ( & V_29 -> V_194 ) ) ;
}
static void F_87 ( struct V_41 * V_42 )
{
struct V_28 * V_195 = F_12 ( V_42 ,
struct V_28 , V_196 ) ;
struct V_26 * V_27 = & V_195 -> V_27 ;
struct V_72 * V_197 = V_195 -> V_31 -> V_198 ;
if ( ! F_88 ( & V_27 -> V_199 . V_200 ) ) {
F_89 ( & V_195 -> V_194 , 1 ) ;
F_90 ( V_197 ) ;
}
F_61 ( & V_195 -> V_201 ) ;
}
static void F_91 ( struct V_41 * V_42 )
{
struct V_28 * V_195 = F_12 ( V_42 ,
struct V_28 , V_196 ) ;
struct V_26 * V_27 = & V_195 -> V_27 ;
struct V_72 * V_197 = V_195 -> V_31 -> V_198 ;
if ( ! F_92 ( V_197 -> V_202 . V_203 ) ) {
F_89 ( & V_195 -> V_194 , 0 ) ;
F_93 ( & V_27 -> V_199 . V_200 ) ;
}
F_61 ( & V_195 -> V_201 ) ;
}
static T_1 F_94 ( struct V_190 * V_191 ,
const char * V_192 , T_4 V_21 )
{
struct V_26 * V_27 = F_85 ( V_191 ) ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_204 ;
int V_25 ;
V_25 = F_95 ( V_192 , 0 , & V_204 ) ;
if ( V_25 < 0 ) {
F_57 ( L_24 , V_25 ) ;
return - V_20 ;
}
if ( ( V_204 != 1 ) && ( V_204 != 0 ) ) {
F_57 ( L_25 , V_204 ) ;
return - V_20 ;
}
if ( V_204 ) {
if ( F_86 ( & V_29 -> V_194 ) )
return - V_205 ;
F_24 ( & V_29 -> V_196 , F_87 ) ;
} else {
if ( ! F_86 ( & V_29 -> V_194 ) )
return V_21 ;
F_24 ( & V_29 -> V_196 , F_91 ) ;
}
F_96 ( & V_29 -> V_201 ) ;
F_97 ( & V_29 -> V_196 ) ;
F_98 ( & V_29 -> V_201 ) ;
if ( V_204 ) {
if ( ! F_86 ( & V_29 -> V_194 ) )
return - V_206 ;
} else {
if ( F_86 ( & V_29 -> V_194 ) )
return - V_207 ;
}
return V_21 ;
}
static T_1 F_99 ( struct V_190 * V_191 ,
char * V_192 )
{
return F_100 ( F_85 ( V_191 ) , V_192 ) ;
}
static T_1 F_101 ( struct V_190 * V_191 ,
const char * V_192 , T_4 V_21 )
{
struct V_26 * V_27 = F_85 ( V_191 ) ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_208 ;
int V_209 = F_95 ( V_192 , 0 , & V_208 ) ;
if ( V_209 ) {
F_57 ( L_26 , V_209 ) ;
return V_209 ;
}
if ( V_208 != 0 && V_208 != 1 && V_208 != 3 ) {
F_57 ( L_27 , V_208 ) ;
return - V_20 ;
}
V_29 -> V_34 . V_40 = V_208 ;
return V_21 ;
}
static T_1 F_102 ( struct V_190 * V_191 ,
char * V_192 )
{
struct V_26 * V_27 = F_85 ( V_191 ) ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
return sprintf ( V_192 , L_23 , V_29 -> V_34 . V_40 ) ;
}
static struct V_26 * F_103 (
struct V_181 * V_2 ,
struct V_210 * V_211 ,
const char * V_1 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_183 ) ;
struct V_28 * V_29 ;
unsigned long V_212 ;
int V_209 ;
if ( strstr ( V_1 , L_28 ) != V_1 )
return F_104 ( - V_20 ) ;
if ( F_95 ( V_1 + 5 , 10 , & V_212 ) || V_212 > V_213 )
return F_104 ( - V_20 ) ;
if ( ( V_212 != 1 ) ) {
F_57 ( L_29 ) ;
return F_104 ( - V_153 ) ;
}
V_29 = F_105 ( sizeof( struct V_28 ) , V_214 ) ;
if ( ! V_29 ) {
F_57 ( L_30 ) ;
return F_104 ( - V_215 ) ;
}
V_29 -> V_31 = V_31 ;
V_29 -> V_33 = V_212 ;
V_29 -> V_34 . V_35 = 1 ;
V_29 -> V_34 . V_37 = 1 ;
V_29 -> V_34 . V_36 = 1 ;
V_29 -> V_34 . V_39 = 1 ;
V_29 -> V_34 . V_111 = 0 ;
V_209 = F_106 ( V_2 , & V_29 -> V_27 , V_216 ) ;
if ( V_209 < 0 ) {
F_107 ( V_29 ) ;
return NULL ;
}
V_31 -> V_217 = V_29 ;
return & V_29 -> V_27 ;
}
static void F_108 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
struct V_30 * V_31 = V_29 -> V_31 ;
struct V_72 * V_65 = V_31 -> V_198 ;
if ( V_65 -> V_202 . V_203 && ! V_65 -> V_202 . V_203 -> V_218 )
F_92 ( V_65 -> V_202 . V_203 ) ;
F_109 ( V_27 ) ;
V_31 -> V_217 = NULL ;
F_107 ( V_29 ) ;
}
static T_1 F_110 ( struct V_190 * V_191 ,
char * V_192 )
{
return F_84 ( V_191 , V_192 ) ;
}
static T_1 F_111 ( struct V_190 * V_191 ,
const char * V_192 , T_4 V_21 )
{
struct V_26 * V_27 = F_85 ( V_191 ) ;
struct V_181 * V_181 = V_27 -> V_182 ;
struct V_30 * V_31 = F_12 ( V_181 ,
struct V_30 , V_183 ) ;
struct V_72 * V_65 = V_31 -> V_198 ;
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
unsigned long V_204 ;
int V_25 ;
V_25 = F_95 ( V_192 , 0 , & V_204 ) ;
if ( V_25 < 0 ) {
F_57 ( L_24 , V_25 ) ;
return - V_20 ;
}
if ( ( V_204 != 1 ) && ( V_204 != 0 ) ) {
F_57 ( L_25 , V_204 ) ;
return - V_20 ;
}
if ( V_204 ) {
if ( F_86 ( & V_29 -> V_194 ) )
return - V_205 ;
F_89 ( & V_29 -> V_194 , 1 ) ;
F_90 ( V_65 ) ;
} else {
if ( ! F_86 ( & V_29 -> V_194 ) )
return V_21 ;
F_89 ( & V_29 -> V_194 , 0 ) ;
F_92 ( V_65 -> V_202 . V_203 ) ;
}
return V_21 ;
}
static struct V_26 * F_112 (
struct V_181 * V_2 ,
struct V_210 * V_211 ,
const char * V_1 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_183 ) ;
struct V_28 * V_29 ;
unsigned long V_212 ;
int V_209 ;
if ( strstr ( V_1 , L_28 ) != V_1 )
return F_104 ( - V_20 ) ;
if ( F_95 ( V_1 + 5 , 10 , & V_212 ) || V_212 > V_213 )
return F_104 ( - V_20 ) ;
V_29 = F_105 ( sizeof( struct V_28 ) , V_214 ) ;
if ( ! V_29 ) {
F_57 ( L_30 ) ;
return F_104 ( - V_215 ) ;
}
V_29 -> V_31 = V_31 ;
V_29 -> V_33 = V_212 ;
V_29 -> V_34 . V_35 = 1 ;
V_29 -> V_34 . V_37 = 1 ;
V_29 -> V_34 . V_36 = 1 ;
V_29 -> V_34 . V_39 = 1 ;
V_209 = F_106 ( V_2 , & V_29 -> V_27 , V_216 ) ;
if ( V_209 < 0 ) {
F_107 ( V_29 ) ;
return NULL ;
}
V_31 -> V_217 = V_29 ;
return & V_29 -> V_27 ;
}
static struct V_62 * F_113 (
T_7 * V_65 ,
const T_10 * V_219 )
{
struct V_30 * V_31 ;
struct V_99 * V_180 ;
struct V_184 * V_100 ;
T_3 V_220 ;
V_31 = V_65 -> V_202 . V_221 ;
if ( ! V_31 ) {
F_57 ( L_31 ) ;
F_73 () ;
return NULL ;
}
V_220 = F_114 ( V_219 ) ;
F_2 ( L_32 , V_220 ) ;
V_180 = F_115 ( & V_31 -> V_187 , V_220 ) ;
if ( ! V_180 ) {
F_2 ( L_33 , V_220 ) ;
return NULL ;
}
F_2 ( L_34 ,
V_180 , V_180 -> V_222 ) ;
V_100 = F_12 ( V_180 , struct V_184 , V_99 ) ;
if ( ! V_100 -> V_62 ) {
F_57 ( L_35 ) ;
return NULL ;
}
return V_100 -> V_62 ;
}
static void F_116 (
struct V_30 * V_31 ,
struct V_99 * V_223 ,
struct V_184 * V_100 ,
struct V_69 * V_70 ,
struct V_62 * V_62 ,
T_10 * V_219 )
{
T_3 V_220 ;
void * V_224 ;
int V_25 ;
V_220 = F_114 ( V_219 ) ;
F_2 ( L_36 , V_220 ) ;
V_224 = F_115 ( & V_31 -> V_187 , V_220 ) ;
if ( ! V_224 ) {
if ( V_223 ) {
F_2 ( L_37 ) ;
V_100 -> V_186 = V_220 ;
V_25 = F_80 ( & V_31 -> V_187 , V_220 ,
V_223 , V_154 ) ;
if ( V_25 )
F_117 ( V_225 L_38 ,
( int ) V_220 ) ;
} else {
F_2 ( L_39 ) ;
}
V_62 -> V_70 = V_70 ;
V_100 -> V_62 = V_62 ;
return;
}
if ( V_100 -> V_62 ) {
if ( V_223 == NULL ) {
F_2 ( L_40 ) ;
F_79 ( & V_31 -> V_187 , V_220 ) ;
V_100 -> V_62 = NULL ;
return;
}
F_2 ( L_41 ) ;
F_118 ( & V_31 -> V_187 , V_220 , V_223 ) ;
V_62 -> V_70 = V_70 ;
V_100 -> V_62 = V_62 ;
return;
}
if ( V_223 == NULL ) {
F_2 ( L_42 ) ;
F_79 ( & V_31 -> V_187 , V_220 ) ;
return;
}
F_2 ( L_43 ) ;
F_118 ( & V_31 -> V_187 , V_220 , V_223 ) ;
V_62 -> V_70 = V_70 ;
V_100 -> V_62 = V_62 ;
F_2 ( L_44 ,
V_100 -> V_62 , V_223 , V_223 -> V_222 ) ;
}
static struct V_62 * F_119 (
T_7 * V_65 ,
const T_9 V_226 )
{
struct V_30 * V_31 ;
struct V_99 * V_180 ;
struct V_184 * V_100 ;
struct V_227 * V_228 ;
V_31 = V_65 -> V_202 . V_221 ;
if ( ! V_31 ) {
F_57 ( L_31 ) ;
F_73 () ;
return NULL ;
}
F_2 ( L_45 , V_226 ) ;
V_228 = V_31 -> V_229 + V_226 ;
V_180 = V_228 -> V_180 ;
if ( ! V_180 ) {
F_2 ( L_46 ,
V_226 ) ;
return NULL ;
}
V_100 = F_12 ( V_180 , struct V_184 , V_99 ) ;
if ( ! V_100 -> V_62 ) {
F_57 ( L_35 ) ;
return NULL ;
}
return V_100 -> V_62 ;
}
static void F_120 (
struct V_30 * V_31 ,
struct V_99 * V_223 ,
struct V_184 * V_100 ,
struct V_69 * V_70 ,
struct V_62 * V_62 ,
T_9 V_226 )
{
struct V_99 * V_230 ;
struct V_227 * V_228 ;
F_2 ( L_47 , V_226 ) ;
V_228 = & ( (struct V_227 * )
V_31 -> V_229 ) [ V_226 ] ;
V_230 = V_228 -> V_180 ;
if ( ! V_230 ) {
F_2 ( L_48 ) ;
V_228 -> V_180 = V_223 ;
if ( V_62 -> V_70 != V_70 )
V_62 -> V_70 = V_70 ;
if ( V_100 -> V_62 != V_62 )
V_100 -> V_62 = V_62 ;
return;
}
if ( V_100 -> V_62 ) {
if ( V_223 == NULL ) {
F_2 ( L_49 ) ;
V_228 -> V_180 = NULL ;
V_100 -> V_62 = NULL ;
return;
}
F_2 ( L_50 ) ;
V_228 -> V_180 = V_223 ;
if ( V_62 -> V_70 != V_70 )
V_62 -> V_70 = V_70 ;
if ( V_100 -> V_62 != V_62 )
V_100 -> V_62 = V_62 ;
return;
}
if ( V_223 == NULL ) {
F_2 ( L_51 ) ;
V_228 -> V_180 = NULL ;
return;
}
F_2 ( L_52 ) ;
V_228 -> V_180 = V_223 ;
if ( V_62 -> V_70 != V_70 )
V_62 -> V_70 = V_70 ;
if ( V_100 -> V_62 != V_62 )
V_100 -> V_62 = V_62 ;
F_2 ( L_53 ,
V_100 -> V_62 , V_223 , V_223 -> V_222 ) ;
}
static void F_81 ( struct V_30 * V_31 ,
struct V_184 * V_100 , struct V_62 * V_63 )
{
struct V_69 * V_70 = V_63 -> V_70 ;
unsigned char V_231 [ 3 ] ;
V_231 [ 0 ] = V_63 -> V_232 . V_14 . V_233 ;
V_231 [ 1 ] = V_63 -> V_232 . V_14 . V_234 ;
V_231 [ 2 ] = V_63 -> V_232 . V_14 . V_235 ;
F_116 ( V_31 , NULL , V_100 , V_70 ,
V_63 , V_231 ) ;
F_120 ( V_31 , NULL , V_100 , V_70 ,
V_63 , V_63 -> V_226 ) ;
}
static void F_121 ( struct V_62 * V_63 )
{
struct V_203 * V_67 = V_63 -> V_67 ;
struct V_236 * V_237 = V_67 -> V_237 ;
T_7 * V_65 = F_122 ( V_237 -> V_238 ) ;
struct V_69 * V_70 ;
struct V_30 * V_31 ;
F_42 ( F_123 () ) ;
V_70 = V_63 -> V_70 ;
if ( ! V_70 ) {
F_57 ( L_54 ) ;
F_73 () ;
return;
}
V_31 = V_65 -> V_202 . V_221 ;
if ( ! V_31 ) {
F_57 ( L_31 ) ;
F_73 () ;
return;
}
F_124 ( V_70 ) ;
F_125 ( V_63 -> V_70 ) ;
F_126 ( V_63 -> V_70 ) ;
}
static int F_127 ( struct V_26 * V_27 ,
struct V_69 * V_70 , void * V_239 )
{
struct V_28 * V_29 = F_12 ( V_27 ,
struct V_28 , V_27 ) ;
struct V_30 * V_31 = V_29 -> V_31 ;
struct V_236 * V_237 = V_31 -> V_198 -> V_66 ;
struct V_99 * V_180 = V_70 -> V_99 ;
struct V_184 * V_100 = F_12 ( V_180 ,
struct V_184 , V_99 ) ;
struct V_62 * V_240 = V_239 ;
T_9 V_226 = V_240 -> V_226 ;
unsigned long V_73 ;
unsigned char V_231 [ 3 ] ;
V_231 [ 0 ] = V_240 -> V_232 . V_14 . V_233 ;
V_231 [ 1 ] = V_240 -> V_232 . V_14 . V_234 ;
V_231 [ 2 ] = V_240 -> V_232 . V_14 . V_235 ;
F_43 ( & V_237 -> V_67 . V_68 , V_73 ) ;
F_116 ( V_31 , V_180 , V_100 ,
V_70 , V_240 , V_231 ) ;
F_120 ( V_31 , V_180 , V_100 ,
V_70 , V_240 , V_226 ) ;
F_45 ( & V_237 -> V_67 . V_68 , V_73 ) ;
return 0 ;
}
static int F_128 (
T_7 * V_65 ,
unsigned char * V_241 ,
struct V_62 * V_240 )
{
struct V_236 * V_237 = V_65 -> V_66 ;
struct V_30 * V_31 ;
struct V_28 * V_29 ;
struct V_69 * V_70 ;
unsigned char V_242 [ 36 ] ;
int V_243 = ( V_237 -> V_244 ) ? V_237 -> V_244 :
V_245 ;
V_31 = V_65 -> V_202 . V_221 ;
if ( ! V_31 ) {
F_57 ( L_31 ) ;
F_73 () ;
return - V_20 ;
}
V_29 = V_31 -> V_217 ;
if ( ! V_29 ) {
F_57 ( L_55 ) ;
return - V_20 ;
}
memset ( & V_242 , 0 , 36 ) ;
snprintf ( V_242 , sizeof( V_242 ) , L_56 , V_241 ) ;
V_70 = F_129 ( & V_29 -> V_27 , V_243 ,
sizeof( struct V_48 ) ,
V_246 , V_242 ,
V_240 , F_127 ) ;
if ( F_130 ( V_70 ) )
return F_131 ( V_70 ) ;
return 0 ;
}
static void F_132 ( struct V_62 * V_63 , T_11 V_219 ,
T_9 V_226 , bool V_247 )
{
struct V_203 * V_67 = V_63 -> V_67 ;
struct V_236 * V_237 = V_67 -> V_237 ;
T_7 * V_65 = F_122 ( V_237 -> V_238 ) ;
struct V_30 * V_31 = V_65 -> V_202 . V_221 ;
struct V_99 * V_180 = V_63 -> V_70 -> V_99 ;
struct V_184 * V_100 = F_12 ( V_180 ,
struct V_184 , V_99 ) ;
T_3 V_220 ;
if ( V_63 -> V_226 != V_226 || V_63 -> V_232 . V_248 != V_219 . V_248 )
F_133 ( L_57 ,
V_63 , V_63 -> V_242 ,
V_63 -> V_226 , V_226 , V_63 -> V_232 . V_14 . V_233 ,
V_63 -> V_232 . V_14 . V_234 , V_63 -> V_232 . V_14 . V_235 , V_219 . V_14 . V_233 ,
V_219 . V_14 . V_234 , V_219 . V_14 . V_235 ) ;
if ( V_63 -> V_226 != V_226 ) {
if ( V_31 -> V_229 [ V_63 -> V_226 ] . V_180 == V_180 )
V_31 -> V_229 [ V_63 -> V_226 ] . V_180 = NULL ;
V_31 -> V_229 [ V_226 ] . V_180 = V_180 ;
V_63 -> V_226 = V_226 ;
}
if ( V_63 -> V_232 . V_248 != V_219 . V_248 ) {
V_220 = ( ( ( T_3 ) V_63 -> V_232 . V_14 . V_233 << 16 ) |
( ( T_3 ) V_63 -> V_232 . V_14 . V_234 << 8 ) |
( ( T_3 ) V_63 -> V_232 . V_14 . V_235 ) ) ;
if ( F_115 ( & V_31 -> V_187 , V_220 ) )
F_134 ( F_79 ( & V_31 -> V_187 , V_220 ) !=
V_180 , L_58 ,
V_63 -> V_232 . V_14 . V_233 , V_63 -> V_232 . V_14 . V_234 ,
V_63 -> V_232 . V_14 . V_235 ) ;
else
F_134 ( 1 , L_59 ,
V_63 -> V_232 . V_14 . V_233 , V_63 -> V_232 . V_14 . V_234 ,
V_63 -> V_232 . V_14 . V_235 ) ;
V_220 = ( ( ( T_3 ) V_219 . V_14 . V_233 << 16 ) |
( ( T_3 ) V_219 . V_14 . V_234 << 8 ) |
( ( T_3 ) V_219 . V_14 . V_235 ) ) ;
if ( F_115 ( & V_31 -> V_187 , V_220 ) ) {
F_134 ( 1 , L_60 ,
V_219 . V_14 . V_233 , V_219 . V_14 . V_234 , V_219 . V_14 . V_235 ) ;
F_118 ( & V_31 -> V_187 , V_220 , V_180 ) ;
} else {
F_80 ( & V_31 -> V_187 , V_220 , V_180 ,
V_154 ) ;
}
V_63 -> V_232 = V_219 ;
V_100 -> V_186 = V_220 ;
}
V_63 -> V_247 = V_247 ;
V_63 -> V_249 = 1 ;
V_63 -> V_250 = 0 ;
}
static int F_135 ( struct V_30 * V_31 )
{
int V_25 ;
V_25 = F_136 ( & V_31 -> V_187 ) ;
if ( V_25 ) {
F_57 ( L_61 ) ;
return V_25 ;
}
V_31 -> V_229 = F_137 ( sizeof( struct V_227 ) *
65536 ) ;
if ( ! V_31 -> V_229 ) {
F_57 ( L_62 ,
sizeof( struct V_227 ) * 65536 ) ;
F_138 ( & V_31 -> V_187 ) ;
return - V_215 ;
}
memset ( V_31 -> V_229 , 0 , sizeof( struct V_227 )
* 65536 ) ;
F_2 ( L_63 ,
sizeof( struct V_227 ) * 65536 ) ;
return 0 ;
}
static int F_139 ( struct V_72 * V_65 ,
void * V_221 ,
T_2 V_251 , T_2 V_252 )
{
struct V_236 * V_237 = V_65 -> V_66 ;
struct V_30 * V_31 =
(struct V_30 * ) V_221 ;
V_237 -> V_67 . V_253 = & V_254 ;
V_65 -> V_202 . V_221 = V_221 ;
V_31 -> V_198 = V_65 ;
return 0 ;
}
static struct V_181 * F_140 (
struct V_255 * V_256 ,
struct V_210 * V_211 ,
const char * V_1 )
{
struct V_30 * V_31 ;
T_2 V_22 ;
int V_209 = - V_206 ;
if ( F_1 ( V_1 , & V_22 , 1 ) < 0 )
return F_104 ( - V_20 ) ;
V_31 = F_105 ( sizeof( struct V_30 ) , V_214 ) ;
if ( ! V_31 ) {
F_57 ( L_64 ) ;
return F_104 ( - V_215 ) ;
}
V_31 -> V_257 = V_22 ;
F_3 ( & V_31 -> V_258 [ 0 ] , V_10 ,
V_22 ) ;
sprintf ( V_31 -> V_32 , L_65 , ( unsigned long long ) V_22 ) ;
V_209 = F_135 ( V_31 ) ;
if ( V_209 != 0 )
goto V_259;
V_209 = F_141 ( V_31 , V_22 , 0 , 0 ,
F_139 ) ;
if ( V_209 != 0 )
goto V_260;
return & V_31 -> V_183 ;
V_260:
F_142 ( V_31 -> V_229 ) ;
F_138 ( & V_31 -> V_187 ) ;
V_259:
F_107 ( V_31 ) ;
return F_104 ( V_209 ) ;
}
static void F_143 ( struct V_181 * V_2 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_183 ) ;
struct V_72 * V_65 = V_31 -> V_198 ;
struct V_99 * V_185 ;
T_3 V_220 = 0 ;
if ( V_65 -> V_202 . V_203 && ! V_65 -> V_202 . V_203 -> V_261 )
F_144 ( V_65 -> V_202 . V_203 ) ;
F_145 ( V_65 ) ;
F_142 ( V_31 -> V_229 ) ;
F_146 (&lport->lport_fcport_map, key, node)
F_79 ( & V_31 -> V_187 , V_220 ) ;
F_138 ( & V_31 -> V_187 ) ;
F_107 ( V_31 ) ;
}
static int F_147 ( struct V_72 * V_197 ,
void * V_221 ,
T_2 V_251 , T_2 V_252 )
{
struct V_262 * V_263 ;
struct V_264 * V_265 = V_197 -> V_266 ;
struct V_72 * V_267 ;
struct V_30 * V_31 =
(struct V_30 * ) V_221 ;
struct V_30 * V_268 =
(struct V_30 * ) V_197 -> V_202 . V_221 ;
struct V_269 V_270 ;
if ( F_148 ( V_197 ) ) {
F_57 ( L_66 ) ;
return - V_207 ;
}
if ( ! V_268 || ! V_268 -> V_217 ||
! F_86 ( & V_268 -> V_217 -> V_194 ) ) {
F_57 ( L_67 ) ;
return - V_207 ;
}
memset ( & V_270 , 0 , sizeof( V_270 ) ) ;
V_270 . V_242 = V_251 ;
V_270 . V_271 = V_252 ;
V_270 . V_272 = V_273 ;
V_270 . V_274 = V_275 ;
V_270 . V_276 = false ;
V_263 = F_149 ( V_265 , 0 , & V_270 ) ;
if ( ! V_263 ) {
F_57 ( L_68 ) ;
return - V_206 ;
}
V_267 = (struct V_72 * ) V_263 -> V_277 ;
V_267 -> V_202 . V_221 = V_221 ;
V_31 -> V_198 = V_267 ;
F_150 ( V_267 -> V_266 ) ;
return 0 ;
}
static struct V_181 * F_151 (
struct V_255 * V_256 ,
struct V_210 * V_211 ,
const char * V_1 )
{
struct V_30 * V_31 ;
T_2 V_278 , V_251 , V_252 ;
char * V_239 , V_279 [ 128 ] ;
int V_209 ;
snprintf ( V_279 , 128 , L_69 , V_1 ) ;
V_239 = strchr ( V_279 , '@' ) ;
if ( ! V_239 ) {
F_57 ( L_70 ) ;
return F_104 ( - V_20 ) ;
}
* V_239 ++ = '\0' ;
if ( F_1 ( V_279 , & V_278 , 1 ) < 0 )
return F_104 ( - V_20 ) ;
if ( F_9 ( V_239 , strlen ( V_239 ) + 1 ,
& V_251 , & V_252 ) < 0 )
return F_104 ( - V_20 ) ;
V_31 = F_105 ( sizeof( struct V_30 ) , V_214 ) ;
if ( ! V_31 ) {
F_57 ( L_71 ) ;
return F_104 ( - V_215 ) ;
}
V_31 -> V_280 = V_251 ;
V_31 -> V_281 = V_252 ;
sprintf ( V_31 -> V_32 , L_65 , ( unsigned long long ) V_251 ) ;
V_209 = F_135 ( V_31 ) ;
if ( V_209 != 0 )
goto V_259;
V_209 = F_141 ( V_31 , V_278 , V_251 , V_252 ,
F_147 ) ;
if ( V_209 != 0 )
goto V_260;
return & V_31 -> V_183 ;
V_260:
F_142 ( V_31 -> V_229 ) ;
F_138 ( & V_31 -> V_187 ) ;
V_259:
F_107 ( V_31 ) ;
return F_104 ( V_209 ) ;
}
static void F_152 ( struct V_181 * V_2 )
{
struct V_30 * V_31 = F_12 ( V_2 ,
struct V_30 , V_183 ) ;
struct V_72 * V_267 = V_31 -> V_198 ;
struct V_236 * V_237 = V_267 -> V_66 ;
T_7 * V_197 = F_122 ( V_237 -> V_238 ) ;
F_153 ( V_267 -> V_266 ) ;
F_154 ( V_267 -> V_262 ) ;
F_153 ( V_197 -> V_266 ) ;
F_107 ( V_31 ) ;
}
static T_1 F_155 ( struct V_190 * V_191 ,
char * V_192 )
{
return sprintf ( V_192 ,
L_72 ,
V_282 , F_156 () -> V_283 ,
F_156 () -> V_284 , F_156 () -> V_285 ) ;
}
static int F_157 ( void )
{
int V_209 ;
F_2 ( L_73 ,
V_282 , F_156 () -> V_283 ,
F_156 () -> V_284 , F_156 () -> V_285 ) ;
V_209 = F_158 ( & V_286 ) ;
if ( V_209 )
return V_209 ;
V_209 = F_158 ( & V_287 ) ;
if ( V_209 )
goto V_288;
V_47 = F_159 ( L_74 ,
V_289 , 0 ) ;
if ( ! V_47 ) {
V_209 = - V_215 ;
goto V_290;
}
V_291 = F_159 ( L_75 , 0 , 0 ) ;
if ( ! V_291 ) {
V_209 = - V_215 ;
goto V_292;
}
return 0 ;
V_292:
F_160 ( V_47 ) ;
V_290:
F_161 ( & V_287 ) ;
V_288:
F_161 ( & V_286 ) ;
return V_209 ;
}
static void F_162 ( void )
{
F_160 ( V_291 ) ;
F_160 ( V_47 ) ;
F_161 ( & V_286 ) ;
F_161 ( & V_287 ) ;
}
static int T_12 F_163 ( void )
{
int V_209 ;
V_209 = F_157 () ;
if ( V_209 < 0 )
return V_209 ;
return 0 ;
}
static void T_13 F_164 ( void )
{
F_162 () ;
}
