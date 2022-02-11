static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( & V_2 -> V_4 , & V_5 ) ;
F_4 ( & V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_6 ( & V_2 -> V_4 ) ;
F_4 ( & V_3 ) ;
}
static int
F_7 ( struct V_1 * V_2 , char * V_6 )
{
static T_1 V_7 ;
struct V_8 V_9 ;
struct V_10 V_10 ;
char V_11 [ 15 ] ;
struct V_12 V_13 = {
. V_11 = V_11 ,
} ;
int error ;
V_2 -> V_14 . V_15 = F_8 ( - V_16 ) ;
V_2 -> V_14 . V_17 = F_8 ( - V_16 ) ;
if ( V_6 == NULL )
return 0 ;
V_10 . V_15 = F_9 () ;
if ( F_10 ( V_10 . V_15 ) )
return F_11 ( V_10 . V_15 ) ;
error = F_12 ( V_10 . V_15 -> V_18 , V_10 . V_15 , V_6 , 0 , & V_9 ) ;
if ( error )
goto V_19;
for (; ; ) {
V_13 . V_20 = snprintf ( V_11 , sizeof( V_11 ) , L_1 , ( unsigned int ) V_7 ++ ) ;
V_11 [ sizeof( V_11 ) - 1 ] = '\0' ;
V_13 . V_21 = F_13 ( V_13 . V_11 , V_13 . V_20 ) ;
V_10 . V_17 = F_14 ( V_9 . V_10 . V_17 , & V_13 , V_2 ) ;
if ( ! F_10 ( V_10 . V_17 ) )
break;
error = F_11 ( V_10 . V_17 ) ;
if ( error != - V_22 ) {
F_15 ( V_23 L_2
L_3 ,
V_6 , V_11 , error ) ;
goto V_24;
}
}
F_16 ( & V_9 . V_10 ) ;
V_2 -> V_14 = V_10 ;
return 0 ;
V_24:
F_16 ( & V_9 . V_10 ) ;
V_19:
F_17 () ;
return error ;
}
static struct V_1 * F_18 ( const struct V_25 * args , struct V_26 * V_27 )
{
struct V_28 * V_29 = args -> V_29 ;
struct V_30 * V_31 ;
struct V_1 * V_2 = NULL ;
struct V_32 * V_33 ;
int V_19 ;
T_2 V_20 ;
V_19 = - V_34 ;
V_20 = strlen ( args -> V_35 ) ;
if ( V_20 > V_36 )
goto V_37;
V_20 ++ ;
F_19 ( L_4 ,
V_29 -> V_11 , args -> V_35 , V_27 ) ;
V_19 = F_20 () ;
if ( V_19 )
goto V_37;
V_19 = - V_34 ;
if ( ! V_27 )
goto V_38;
if ( args -> V_31 >= V_29 -> V_39 )
goto V_40;
V_31 = V_29 -> V_31 [ args -> V_31 ] ;
if ( V_31 == NULL )
goto V_40;
V_19 = - V_41 ;
V_2 = F_21 ( sizeof( * V_2 ) , V_42 ) ;
if ( ! V_2 )
goto V_40;
V_2 -> V_43 = V_2 ;
V_2 -> V_44 = V_2 -> V_45 ;
if ( V_20 > sizeof( V_2 -> V_45 ) ) {
char * V_46 = F_22 ( V_20 , V_42 ) ;
if ( V_46 != NULL )
V_2 -> V_44 = V_46 ;
else
V_20 = sizeof( V_2 -> V_45 ) ;
}
F_23 ( V_2 -> V_44 , args -> V_35 , V_20 ) ;
V_2 -> V_47 = V_27 ;
V_2 -> V_48 = V_31 -> V_49 ;
V_2 -> V_50 = V_31 -> V_51 ;
V_2 -> V_52 = V_29 -> V_11 ;
V_2 -> V_53 = args -> V_54 ? : V_29 -> V_55 ;
V_2 -> V_56 = V_31 -> V_55 ;
V_2 -> V_57 = V_29 -> V_58 ;
V_2 -> V_59 = F_24 ( V_2 ) ;
V_19 = - V_41 ;
if ( V_2 -> V_59 == NULL )
goto V_60;
V_2 -> V_61 = V_29 ;
F_25 ( & V_2 -> V_62 ) ;
F_26 ( & V_2 -> V_63 ) ;
if ( ! F_27 ( V_2 -> V_47 ) )
V_2 -> V_64 = 1 ;
V_2 -> V_65 = V_27 -> V_66 ;
if ( args -> V_66 != NULL ) {
memcpy ( & V_2 -> V_67 , args -> V_66 ,
sizeof( V_2 -> V_67 ) ) ;
V_2 -> V_65 = & V_2 -> V_67 ;
}
V_2 -> V_68 = & V_2 -> V_69 ;
F_28 ( & V_2 -> V_69 , V_2 -> V_65 -> V_70 ) ;
V_2 -> V_71 = NULL ;
if ( args -> V_72 ) {
V_2 -> V_71 = F_29 ( args -> V_72 , V_42 ) ;
if ( ! V_2 -> V_71 )
goto V_73;
}
F_30 ( & V_2 -> V_74 , 1 ) ;
V_19 = F_7 ( V_2 , V_29 -> V_75 ) ;
if ( V_19 < 0 )
goto V_76;
V_33 = F_31 ( args -> V_77 , V_2 ) ;
if ( F_10 ( V_33 ) ) {
F_15 ( V_23 L_5 ,
args -> V_77 ) ;
V_19 = F_11 ( V_33 ) ;
goto V_78;
}
V_2 -> V_79 = strlen ( F_32 () -> V_80 ) ;
if ( V_2 -> V_79 > V_81 )
V_2 -> V_79 = V_81 ;
memcpy ( V_2 -> V_82 , F_32 () -> V_80 , V_2 -> V_79 ) ;
F_1 ( V_2 ) ;
return V_2 ;
V_78:
if ( ! F_10 ( V_2 -> V_14 . V_17 ) ) {
F_33 ( V_2 -> V_14 . V_17 ) ;
F_17 () ;
}
V_76:
F_34 ( V_2 -> V_71 ) ;
V_73:
F_35 ( V_2 -> V_59 ) ;
V_60:
if ( V_2 -> V_44 != V_2 -> V_45 )
F_34 ( V_2 -> V_44 ) ;
F_34 ( V_2 ) ;
V_40:
F_36 ( V_27 ) ;
V_38:
F_37 () ;
V_37:
return F_8 ( V_19 ) ;
}
struct V_1 * F_38 ( struct V_25 * args )
{
struct V_26 * V_27 ;
struct V_1 * V_2 ;
struct V_83 V_84 = {
. V_85 = args -> V_85 ,
. V_86 = args -> V_87 ,
. V_88 = args -> V_89 ,
. V_90 = args -> V_91 ,
. V_92 = args -> V_93 ,
. V_94 = args -> V_94 ,
} ;
char V_35 [ 48 ] ;
if ( args -> V_35 == NULL ) {
struct V_95 * V_96 =
(struct V_95 * ) args -> V_91 ;
struct V_97 * sin =
(struct V_97 * ) args -> V_91 ;
struct V_98 * V_99 =
(struct V_98 * ) args -> V_91 ;
V_35 [ 0 ] = '\0' ;
switch ( args -> V_91 -> V_100 ) {
case V_101 :
snprintf ( V_35 , sizeof( V_35 ) , L_6 ,
V_96 -> V_102 ) ;
break;
case V_103 :
snprintf ( V_35 , sizeof( V_35 ) , L_7 ,
& sin -> V_104 . V_105 ) ;
break;
case V_106 :
snprintf ( V_35 , sizeof( V_35 ) , L_8 ,
& V_99 -> V_107 ) ;
break;
default:
return F_8 ( - V_34 ) ;
}
args -> V_35 = V_35 ;
}
V_27 = F_39 ( & V_84 ) ;
if ( F_10 ( V_27 ) )
return (struct V_1 * ) V_27 ;
V_27 -> V_108 = 1 ;
if ( args -> V_109 & V_110 )
V_27 -> V_108 = 0 ;
V_2 = F_18 ( args , V_27 ) ;
if ( F_10 ( V_2 ) )
return V_2 ;
if ( ! ( args -> V_109 & V_111 ) ) {
int V_19 = F_40 ( V_2 ) ;
if ( V_19 != 0 ) {
F_41 ( V_2 ) ;
return F_8 ( V_19 ) ;
}
}
V_2 -> V_112 = 1 ;
if ( args -> V_109 & V_113 )
V_2 -> V_112 = 0 ;
if ( args -> V_109 & V_114 )
V_2 -> V_64 = 1 ;
if ( args -> V_109 & V_115 )
V_2 -> V_116 = 1 ;
if ( ! ( args -> V_109 & V_117 ) )
V_2 -> V_118 = 1 ;
return V_2 ;
}
struct V_1 *
F_42 ( struct V_1 * V_2 )
{
struct V_1 * V_119 ;
int V_19 = - V_41 ;
V_119 = F_43 ( V_2 , sizeof( * V_119 ) , V_42 ) ;
if ( ! V_119 )
goto V_120;
V_119 -> V_43 = V_2 ;
V_119 -> V_64 = 0 ;
F_25 ( & V_119 -> V_62 ) ;
F_26 ( & V_119 -> V_63 ) ;
F_28 ( & V_119 -> V_69 , V_2 -> V_65 -> V_70 ) ;
V_119 -> V_59 = F_24 ( V_2 ) ;
if ( V_119 -> V_59 == NULL )
goto V_60;
if ( V_2 -> V_71 ) {
V_119 -> V_71 = F_29 ( V_2 -> V_71 , V_42 ) ;
if ( V_119 -> V_71 == NULL )
goto V_73;
}
F_30 ( & V_119 -> V_74 , 1 ) ;
V_19 = F_7 ( V_119 , V_2 -> V_61 -> V_75 ) ;
if ( V_19 != 0 )
goto V_76;
if ( V_119 -> V_121 )
F_44 ( & V_119 -> V_121 -> V_122 ) ;
F_45 ( V_2 -> V_47 ) ;
F_44 ( & V_2 -> V_74 ) ;
F_1 ( V_119 ) ;
F_20 () ;
return V_119 ;
V_76:
F_34 ( V_119 -> V_71 ) ;
V_73:
F_35 ( V_119 -> V_59 ) ;
V_60:
F_34 ( V_119 ) ;
V_120:
F_19 ( L_9 , V_123 , V_19 ) ;
return F_8 ( V_19 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
struct V_124 * V_125 ;
if ( F_47 ( & V_2 -> V_62 ) )
return;
F_19 ( L_10 , V_2 ) ;
F_2 ( & V_2 -> V_63 ) ;
F_48 (rovr, &clnt->cl_tasks, tk_task) {
if ( ! F_49 ( V_125 ) )
continue;
if ( ! ( V_125 -> V_126 & V_127 ) ) {
V_125 -> V_126 |= V_127 ;
F_50 ( V_125 , - V_128 ) ;
if ( F_51 ( V_125 ) )
F_52 ( V_125 -> V_129 ,
V_125 ) ;
}
}
F_4 ( & V_2 -> V_63 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
F_19 ( L_11 ,
V_2 -> V_52 , V_2 -> V_44 ) ;
while ( ! F_47 ( & V_2 -> V_62 ) ) {
F_46 ( V_2 ) ;
F_53 ( V_130 ,
F_47 ( & V_2 -> V_62 ) , 1 * V_131 ) ;
}
F_54 ( V_2 ) ;
}
static void
F_55 ( struct V_1 * V_2 )
{
F_19 ( L_12 ,
V_2 -> V_52 , V_2 -> V_44 ) ;
if ( ! F_10 ( V_2 -> V_14 . V_17 ) ) {
F_33 ( V_2 -> V_14 . V_17 ) ;
F_17 () ;
}
if ( V_2 -> V_43 != V_2 ) {
F_54 ( V_2 -> V_43 ) ;
goto V_132;
}
if ( V_2 -> V_44 != V_2 -> V_45 )
F_34 ( V_2 -> V_44 ) ;
V_132:
F_5 ( V_2 ) ;
F_35 ( V_2 -> V_59 ) ;
F_34 ( V_2 -> V_71 ) ;
V_2 -> V_59 = NULL ;
F_36 ( V_2 -> V_47 ) ;
F_37 () ;
F_34 ( V_2 ) ;
}
static void
F_56 ( struct V_1 * V_2 )
{
if ( V_2 -> V_121 == NULL ) {
F_55 ( V_2 ) ;
return;
}
F_44 ( & V_2 -> V_74 ) ;
F_57 ( V_2 -> V_121 ) ;
V_2 -> V_121 = NULL ;
if ( F_58 ( & V_2 -> V_74 ) )
F_55 ( V_2 ) ;
}
void
F_54 ( struct V_1 * V_2 )
{
F_19 ( L_13 , V_2 ) ;
if ( F_47 ( & V_2 -> V_62 ) )
F_59 ( & V_130 ) ;
if ( F_58 ( & V_2 -> V_74 ) )
F_56 ( V_2 ) ;
}
struct V_1 * F_60 ( struct V_1 * V_133 ,
struct V_28 * V_29 ,
T_3 V_134 )
{
struct V_1 * V_2 ;
struct V_30 * V_31 ;
int V_19 ;
F_61 ( V_134 >= V_29 -> V_39 || ! V_29 -> V_31 [ V_134 ] ) ;
V_31 = V_29 -> V_31 [ V_134 ] ;
V_2 = F_42 ( V_133 ) ;
if ( F_10 ( V_2 ) )
goto V_135;
V_2 -> V_48 = V_31 -> V_49 ;
V_2 -> V_50 = V_31 -> V_51 ;
V_2 -> V_52 = V_29 -> V_11 ;
V_2 -> V_53 = V_29 -> V_55 ;
V_2 -> V_56 = V_31 -> V_55 ;
V_2 -> V_57 = V_29 -> V_58 ;
V_19 = F_40 ( V_2 ) ;
if ( V_19 != 0 ) {
F_41 ( V_2 ) ;
V_2 = F_8 ( V_19 ) ;
}
V_135:
return V_2 ;
}
void F_62 ( struct V_124 * V_136 )
{
struct V_1 * V_2 = V_136 -> V_137 ;
if ( V_2 != NULL ) {
F_2 ( & V_2 -> V_63 ) ;
F_6 ( & V_136 -> V_138 ) ;
F_4 ( & V_2 -> V_63 ) ;
V_136 -> V_137 = NULL ;
F_54 ( V_2 ) ;
}
}
static
void F_63 ( struct V_124 * V_136 , struct V_1 * V_2 )
{
if ( V_2 != NULL ) {
F_62 ( V_136 ) ;
V_136 -> V_137 = V_2 ;
F_44 ( & V_2 -> V_74 ) ;
if ( V_2 -> V_112 )
V_136 -> V_126 |= V_139 ;
F_2 ( & V_2 -> V_63 ) ;
F_64 ( & V_136 -> V_138 , & V_2 -> V_62 ) ;
F_4 ( & V_2 -> V_63 ) ;
}
}
void F_65 ( struct V_124 * V_136 , struct V_1 * V_2 )
{
F_62 ( V_136 ) ;
F_63 ( V_136 , V_2 ) ;
}
static void
F_66 ( struct V_124 * V_136 , const struct V_140 * V_141 )
{
if ( V_141 != NULL ) {
V_136 -> V_142 . V_143 = V_141 -> V_143 ;
V_136 -> V_142 . V_144 = V_141 -> V_144 ;
V_136 -> V_142 . V_145 = V_141 -> V_145 ;
if ( V_141 -> V_146 != NULL )
V_136 -> V_142 . V_146 = F_67 ( V_141 -> V_146 ) ;
}
}
static void
F_68 ( struct V_124 * V_136 , void * V_147 )
{
}
struct V_124 * F_69 ( const struct V_148 * V_149 )
{
struct V_124 * V_136 ;
V_136 = F_70 ( V_149 ) ;
if ( F_10 ( V_136 ) )
goto V_135;
F_63 ( V_136 , V_149 -> V_150 ) ;
F_66 ( V_136 , V_149 -> V_140 ) ;
if ( V_136 -> V_151 == NULL )
F_71 ( V_136 ) ;
F_44 ( & V_136 -> V_152 ) ;
F_72 ( V_136 ) ;
V_135:
return V_136 ;
}
int F_73 ( struct V_1 * V_2 , const struct V_140 * V_141 , int V_109 )
{
struct V_124 * V_136 ;
struct V_148 V_149 = {
. V_150 = V_2 ,
. V_140 = V_141 ,
. V_153 = & V_154 ,
. V_109 = V_109 ,
} ;
int V_155 ;
F_61 ( V_109 & V_156 ) ;
V_136 = F_69 ( & V_149 ) ;
if ( F_10 ( V_136 ) )
return F_11 ( V_136 ) ;
V_155 = V_136 -> V_157 ;
F_74 ( V_136 ) ;
return V_155 ;
}
int
F_75 ( struct V_1 * V_2 , const struct V_140 * V_141 , int V_109 ,
const struct V_158 * V_159 , void * V_147 )
{
struct V_124 * V_136 ;
struct V_148 V_149 = {
. V_150 = V_2 ,
. V_140 = V_141 ,
. V_153 = V_159 ,
. V_160 = V_147 ,
. V_109 = V_109 | V_156 ,
} ;
V_136 = F_69 ( & V_149 ) ;
if ( F_10 ( V_136 ) )
return F_11 ( V_136 ) ;
F_74 ( V_136 ) ;
return 0 ;
}
struct V_124 * F_76 ( struct V_161 * V_162 ,
const struct V_158 * V_159 )
{
struct V_124 * V_136 ;
struct V_163 * V_164 = & V_162 -> V_165 ;
struct V_148 V_149 = {
. V_153 = V_159 ,
} ;
F_19 ( L_14 , V_162 ) ;
V_136 = F_70 ( & V_149 ) ;
if ( F_10 ( V_136 ) ) {
F_77 ( V_162 ) ;
goto V_135;
}
V_136 -> V_166 = V_162 ;
V_164 -> V_20 = V_164 -> V_167 [ 0 ] . V_168 + V_164 -> V_169 +
V_164 -> V_170 [ 0 ] . V_168 ;
V_136 -> V_151 = V_171 ;
F_44 ( & V_136 -> V_152 ) ;
F_61 ( F_78 ( & V_136 -> V_152 ) != 2 ) ;
F_72 ( V_136 ) ;
V_135:
F_19 ( L_15 , V_136 ) ;
return V_136 ;
}
void
F_71 ( struct V_124 * V_136 )
{
V_136 -> V_151 = V_172 ;
}
T_2 F_79 ( struct V_1 * V_2 , struct V_173 * V_46 , T_2 V_174 )
{
T_2 V_175 ;
struct V_26 * V_27 = V_2 -> V_47 ;
V_175 = sizeof( V_27 -> V_176 ) ;
if ( V_175 > V_174 )
V_175 = V_174 ;
memcpy ( V_46 , & V_2 -> V_47 -> V_176 , V_175 ) ;
return V_27 -> V_92 ;
}
const char * F_80 ( struct V_1 * V_2 ,
enum V_177 V_178 )
{
struct V_26 * V_27 = V_2 -> V_47 ;
if ( V_27 -> V_179 [ V_178 ] != NULL )
return V_27 -> V_179 [ V_178 ] ;
else
return L_16 ;
}
void
F_81 ( struct V_1 * V_2 , unsigned int V_180 , unsigned int V_181 )
{
struct V_26 * V_27 = V_2 -> V_47 ;
if ( V_27 -> V_182 -> V_183 )
V_27 -> V_182 -> V_183 ( V_27 , V_180 , V_181 ) ;
}
T_2 F_82 ( struct V_1 * V_2 )
{
return V_2 -> V_47 -> V_184 ;
}
void F_83 ( struct V_1 * V_2 )
{
if ( V_2 -> V_64 )
F_84 ( V_2 -> V_47 ) ;
}
int
F_85 ( struct V_124 * V_136 )
{
if ( F_86 ( V_136 ) )
return 0 ;
V_136 -> V_151 = V_185 ;
return 1 ;
}
int
F_87 ( struct V_124 * V_136 )
{
if ( F_86 ( V_136 ) )
return 0 ;
V_136 -> V_151 = V_172 ;
return 1 ;
}
static const char * F_88 ( const struct V_124 * V_136 )
{
const struct V_186 * V_187 = V_136 -> V_142 . V_143 ;
if ( V_187 ) {
if ( V_187 -> V_188 )
return V_187 -> V_188 ;
else
return L_17 ;
} else
return L_18 ;
}
static void
V_172 ( struct V_124 * V_136 )
{
struct V_1 * V_2 = V_136 -> V_137 ;
F_19 ( L_19 , V_136 -> V_189 ,
V_2 -> V_52 , V_2 -> V_56 ,
F_88 ( V_136 ) ,
( F_89 ( V_136 ) ? L_20 : L_21 ) ) ;
V_136 -> V_142 . V_143 -> V_190 ++ ;
V_2 -> V_57 -> V_191 ++ ;
V_136 -> V_151 = V_192 ;
}
static void
V_192 ( struct V_124 * V_136 )
{
F_90 ( V_136 ) ;
V_136 -> V_157 = 0 ;
V_136 -> V_151 = V_193 ;
F_91 ( V_136 ) ;
}
static void
V_193 ( struct V_124 * V_136 )
{
int V_155 = V_136 -> V_157 ;
F_90 ( V_136 ) ;
V_136 -> V_157 = 0 ;
if ( V_155 >= 0 ) {
if ( V_136 -> V_166 ) {
V_136 -> V_151 = V_194 ;
return;
}
F_15 ( V_195 L_22 ,
V_123 , V_155 ) ;
F_50 ( V_136 , - V_128 ) ;
return;
}
if ( V_136 -> V_166 ) {
F_15 ( V_195 L_23 ,
V_123 , V_155 ) ;
F_92 ( V_136 ) ;
}
switch ( V_155 ) {
case - V_196 :
V_136 -> V_151 = V_192 ;
return;
case - V_128 :
break;
default:
F_15 ( V_195 L_24 ,
V_123 , V_155 ) ;
break;
}
F_50 ( V_136 , V_155 ) ;
}
static void
V_194 ( struct V_124 * V_136 )
{
F_90 ( V_136 ) ;
V_136 -> V_151 = V_197 ;
V_136 -> V_157 = 0 ;
V_136 -> V_137 -> V_57 -> V_198 ++ ;
F_93 ( V_136 ) ;
}
static void
V_197 ( struct V_124 * V_136 )
{
int V_155 = V_136 -> V_157 ;
F_90 ( V_136 ) ;
V_136 -> V_157 = 0 ;
V_136 -> V_151 = V_194 ;
switch ( V_155 ) {
case 0 :
if ( F_94 ( V_136 ) )
V_136 -> V_151 = V_199 ;
return;
case - V_200 :
F_95 ( V_136 , 3 * V_131 ) ;
case - V_196 :
V_155 = - V_201 ;
if ( ! V_136 -> V_202 )
break;
V_136 -> V_202 -- ;
F_19 ( L_25 ,
V_136 -> V_189 , V_123 ) ;
return;
}
F_19 ( L_26 ,
V_136 -> V_189 , V_123 , V_155 ) ;
F_50 ( V_136 , V_155 ) ;
}
static void
V_199 ( struct V_124 * V_136 )
{
unsigned int V_203 = V_136 -> V_166 -> V_204 -> V_205 -> V_206 ;
struct V_161 * V_162 = V_136 -> V_166 ;
struct V_26 * V_27 = V_136 -> V_207 ;
struct V_186 * V_187 = V_136 -> V_142 . V_143 ;
F_90 ( V_136 ) ;
V_136 -> V_157 = 0 ;
V_136 -> V_151 = V_208 ;
if ( V_162 -> V_209 )
return;
if ( V_187 -> V_210 != 0 ) {
F_61 ( V_187 -> V_211 == 0 ) ;
if ( V_187 -> V_212 != NULL )
F_61 ( V_187 -> V_213 == 0 ) ;
}
V_162 -> V_214 = V_215 + ( V_203 << 1 ) + V_187 -> V_211 ;
V_162 -> V_214 <<= 2 ;
V_162 -> V_216 = V_217 + V_203 + V_187 -> V_213 ;
V_162 -> V_216 <<= 2 ;
V_162 -> V_209 = V_27 -> V_182 -> V_218 ( V_136 ,
V_162 -> V_214 + V_162 -> V_216 ) ;
if ( V_162 -> V_209 != NULL )
return;
F_19 ( L_27 , V_136 -> V_189 ) ;
if ( F_89 ( V_136 ) || ! F_96 ( V_219 ) ) {
V_136 -> V_151 = V_199 ;
F_95 ( V_136 , V_131 >> 4 ) ;
return;
}
F_50 ( V_136 , - V_220 ) ;
}
static inline int
F_97 ( struct V_124 * V_136 )
{
return V_136 -> V_166 -> V_165 . V_20 == 0 ;
}
static inline void
F_98 ( struct V_124 * V_136 )
{
V_136 -> V_166 -> V_165 . V_20 = 0 ;
V_136 -> V_166 -> V_221 = 0 ;
}
static inline void
F_99 ( struct V_163 * V_46 , void * V_222 , T_2 V_20 )
{
V_46 -> V_167 [ 0 ] . V_223 = V_222 ;
V_46 -> V_167 [ 0 ] . V_168 = V_20 ;
V_46 -> V_170 [ 0 ] . V_168 = 0 ;
V_46 -> V_169 = 0 ;
V_46 -> V_109 = 0 ;
V_46 -> V_20 = 0 ;
V_46 -> V_224 = V_20 ;
}
static void
F_100 ( struct V_124 * V_136 )
{
struct V_161 * V_162 = V_136 -> V_166 ;
T_4 V_225 ;
T_5 * V_226 ;
F_90 ( V_136 ) ;
F_99 ( & V_162 -> V_165 ,
V_162 -> V_209 ,
V_162 -> V_214 ) ;
F_99 ( & V_162 -> V_227 ,
( char * ) V_162 -> V_209 + V_162 -> V_214 ,
V_162 -> V_216 ) ;
V_226 = F_101 ( V_136 ) ;
if ( V_226 == NULL ) {
F_15 ( V_23 L_28 ) ;
F_50 ( V_136 , - V_128 ) ;
return;
}
V_225 = V_136 -> V_142 . V_143 -> V_228 ;
if ( V_225 == NULL )
return;
V_136 -> V_157 = F_102 ( V_136 , V_225 , V_162 , V_226 ,
V_136 -> V_142 . V_144 ) ;
}
static void
V_208 ( struct V_124 * V_136 )
{
struct V_26 * V_27 = V_136 -> V_207 ;
F_90 ( V_136 ) ;
V_136 -> V_151 = V_229 ;
if ( ! F_27 ( V_27 ) ) {
V_136 -> V_151 = V_230 ;
V_136 -> V_231 = V_27 -> V_232 ;
V_27 -> V_182 -> V_233 ( V_136 ) ;
}
}
static void
V_230 ( struct V_124 * V_136 )
{
int V_155 = - V_128 ;
if ( V_136 -> V_157 >= 0 ) {
F_90 ( V_136 ) ;
V_136 -> V_157 = 0 ;
V_136 -> V_151 = V_229 ;
return;
}
switch ( V_136 -> V_157 ) {
case - V_41 :
F_19 ( L_29 , V_136 -> V_189 ) ;
F_95 ( V_136 , V_131 >> 2 ) ;
goto V_234;
case - V_201 :
F_19 ( L_30
L_31 , V_136 -> V_189 ) ;
if ( V_136 -> V_142 . V_143 -> V_210 == 0 ) {
V_155 = - V_235 ;
break;
}
if ( V_136 -> V_236 == 0 )
break;
V_136 -> V_236 -- ;
F_95 ( V_136 , 3 * V_131 ) ;
goto V_234;
case - V_200 :
F_19 ( L_32 ,
V_136 -> V_189 ) ;
goto V_234;
case - V_237 :
F_19 ( L_33 ,
V_136 -> V_189 ) ;
break;
case - V_238 :
F_19 ( L_34 ,
V_136 -> V_189 ) ;
V_136 -> V_157 = 0 ;
V_136 -> V_151 = V_208 ;
return;
case - V_239 :
case - V_240 :
case - V_241 :
case - V_242 :
case - V_243 :
case - V_244 :
case - V_245 :
F_19 ( L_35 ,
V_136 -> V_189 , V_136 -> V_157 ) ;
if ( ! F_103 ( V_136 ) ) {
F_95 ( V_136 , 5 * V_131 ) ;
goto V_234;
}
V_155 = V_136 -> V_157 ;
break;
default:
F_19 ( L_36 ,
V_136 -> V_189 , - V_136 -> V_157 ) ;
}
F_50 ( V_136 , V_155 ) ;
return;
V_234:
V_136 -> V_151 = V_246 ;
}
static void
V_229 ( struct V_124 * V_136 )
{
struct V_26 * V_27 = V_136 -> V_207 ;
F_19 ( L_37 ,
V_136 -> V_189 , V_27 ,
( F_104 ( V_27 ) ? L_38 : L_39 ) ) ;
V_136 -> V_151 = V_247 ;
if ( ! F_104 ( V_27 ) ) {
V_136 -> V_151 = V_248 ;
if ( V_136 -> V_157 < 0 )
return;
F_105 ( V_136 ) ;
}
}
static void
V_248 ( struct V_124 * V_136 )
{
struct V_1 * V_2 = V_136 -> V_137 ;
int V_155 = V_136 -> V_157 ;
F_90 ( V_136 ) ;
V_136 -> V_157 = 0 ;
if ( V_155 >= 0 || V_155 == - V_196 ) {
V_2 -> V_57 -> V_249 ++ ;
V_136 -> V_151 = V_247 ;
return;
}
switch ( V_155 ) {
case - V_200 :
V_136 -> V_151 = V_246 ;
break;
default:
F_50 ( V_136 , - V_128 ) ;
}
}
static void
V_247 ( struct V_124 * V_136 )
{
F_90 ( V_136 ) ;
V_136 -> V_151 = V_250 ;
if ( V_136 -> V_157 < 0 )
return;
V_136 -> V_157 = F_106 ( V_136 ) ;
if ( V_136 -> V_157 != 0 )
return;
V_136 -> V_151 = V_251 ;
if ( F_97 ( V_136 ) ) {
F_61 ( V_136 -> V_166 -> V_221 != 0 ) ;
F_100 ( V_136 ) ;
if ( V_136 -> V_157 != 0 ) {
if ( V_136 -> V_157 == - V_196 )
F_95 ( V_136 , V_131 >> 4 ) ;
else
F_50 ( V_136 , V_136 -> V_157 ) ;
return;
}
}
F_107 ( V_136 ) ;
if ( V_136 -> V_157 < 0 )
return;
V_251 ( V_136 ) ;
if ( F_108 ( V_136 ) )
return;
V_136 -> V_151 = V_252 ;
F_52 ( & V_136 -> V_207 -> V_253 , V_136 ) ;
}
static void
V_251 ( struct V_124 * V_136 )
{
V_136 -> V_151 = V_250 ;
if ( V_136 -> V_157 == 0 ) {
F_109 ( V_136 ) ;
F_98 ( V_136 ) ;
return;
}
switch ( V_136 -> V_157 ) {
case - V_196 :
break;
default:
F_90 ( V_136 ) ;
F_109 ( V_136 ) ;
F_98 ( V_136 ) ;
break;
case - V_239 :
case - V_242 :
case - V_243 :
case - V_244 :
if ( F_103 ( V_136 ) ) {
F_109 ( V_136 ) ;
F_50 ( V_136 , V_136 -> V_157 ) ;
break;
}
case - V_240 :
case - V_241 :
case - V_245 :
F_98 ( V_136 ) ;
}
}
static void
V_171 ( struct V_124 * V_136 )
{
struct V_161 * V_162 = V_136 -> V_166 ;
F_61 ( V_136 -> V_157 != 0 ) ;
V_136 -> V_157 = F_106 ( V_136 ) ;
if ( V_136 -> V_157 == - V_196 ) {
V_136 -> V_157 = 0 ;
V_136 -> V_151 = V_171 ;
return;
}
V_136 -> V_151 = V_252 ;
if ( V_136 -> V_157 < 0 ) {
F_15 ( V_254 L_40
L_41 , V_136 -> V_157 ) ;
return;
}
F_107 ( V_136 ) ;
F_109 ( V_136 ) ;
F_90 ( V_136 ) ;
switch ( V_136 -> V_157 ) {
case 0 :
break;
case - V_242 :
case - V_243 :
case - V_244 :
case - V_200 :
F_15 ( V_254 L_40
L_41 , V_136 -> V_157 ) ;
F_110 ( V_136 -> V_207 ,
V_162 -> V_255 ) ;
break;
default:
F_61 ( V_136 -> V_157 == - V_196 ) ;
F_15 ( V_254 L_40
L_41 , V_136 -> V_157 ) ;
break;
}
F_52 ( & V_162 -> V_256 -> V_253 , V_136 ) ;
}
static void
V_250 ( struct V_124 * V_136 )
{
struct V_1 * V_2 = V_136 -> V_137 ;
struct V_161 * V_162 = V_136 -> V_166 ;
int V_155 ;
if ( V_162 -> V_257 > 0 && ! V_162 -> V_221 )
V_136 -> V_157 = V_162 -> V_257 ;
F_90 ( V_136 ) ;
V_155 = V_136 -> V_157 ;
if ( V_155 >= 0 ) {
V_136 -> V_151 = V_258 ;
return;
}
V_136 -> V_157 = 0 ;
switch( V_155 ) {
case - V_242 :
case - V_243 :
case - V_244 :
F_95 ( V_136 , 3 * V_131 ) ;
case - V_200 :
V_136 -> V_151 = V_246 ;
if ( V_136 -> V_137 -> V_116 )
F_110 ( V_136 -> V_207 ,
V_162 -> V_255 ) ;
break;
case - V_240 :
case - V_239 :
F_83 ( V_2 ) ;
F_95 ( V_136 , 3 * V_131 ) ;
case - V_245 :
case - V_241 :
V_136 -> V_151 = V_208 ;
break;
case - V_196 :
V_136 -> V_151 = V_247 ;
break;
case - V_128 :
F_50 ( V_136 , V_155 ) ;
break;
default:
if ( V_2 -> V_118 )
F_15 ( L_42 ,
V_2 -> V_52 , - V_155 ) ;
F_50 ( V_136 , V_155 ) ;
}
}
static void
V_246 ( struct V_124 * V_136 )
{
struct V_1 * V_2 = V_136 -> V_137 ;
if ( F_111 ( V_136 -> V_166 ) == 0 ) {
F_19 ( L_43 , V_136 -> V_189 ) ;
goto V_259;
}
F_19 ( L_44 , V_136 -> V_189 ) ;
V_136 -> V_260 ++ ;
if ( F_103 ( V_136 ) ) {
F_50 ( V_136 , - V_200 ) ;
return;
}
if ( F_112 ( V_136 ) ) {
if ( V_2 -> V_118 )
F_15 ( V_254 L_45 ,
V_2 -> V_52 , V_2 -> V_44 ) ;
if ( V_136 -> V_126 & V_261 )
F_50 ( V_136 , - V_200 ) ;
else
F_50 ( V_136 , - V_128 ) ;
return;
}
if ( ! ( V_136 -> V_126 & V_262 ) ) {
V_136 -> V_126 |= V_262 ;
if ( V_2 -> V_118 )
F_15 ( V_254 L_46 ,
V_2 -> V_52 , V_2 -> V_44 ) ;
}
F_83 ( V_2 ) ;
F_113 ( V_136 ) ;
V_259:
V_2 -> V_57 -> V_263 ++ ;
V_136 -> V_151 = V_208 ;
V_136 -> V_157 = 0 ;
}
static void
V_258 ( struct V_124 * V_136 )
{
struct V_1 * V_2 = V_136 -> V_137 ;
struct V_161 * V_162 = V_136 -> V_166 ;
T_6 V_264 = V_136 -> V_142 . V_143 -> V_212 ;
T_5 * V_226 ;
F_19 ( L_47 ,
V_136 -> V_189 , V_136 -> V_157 ) ;
if ( V_136 -> V_126 & V_262 ) {
if ( V_2 -> V_118 )
F_15 ( V_254 L_48 ,
V_2 -> V_52 , V_2 -> V_44 ) ;
V_136 -> V_126 &= ~ V_262 ;
}
F_114 () ;
V_162 -> V_227 . V_20 = V_162 -> V_265 . V_20 ;
F_115 ( memcmp ( & V_162 -> V_227 , & V_162 -> V_265 ,
sizeof( V_162 -> V_227 ) ) != 0 ) ;
if ( V_162 -> V_227 . V_20 < 12 ) {
if ( ! F_112 ( V_136 ) ) {
V_136 -> V_151 = V_208 ;
V_2 -> V_57 -> V_263 ++ ;
goto V_266;
}
F_19 ( L_49 ,
V_2 -> V_52 , V_136 -> V_157 ) ;
V_136 -> V_151 = V_246 ;
goto V_266;
}
V_226 = F_116 ( V_136 ) ;
if ( F_10 ( V_226 ) ) {
if ( V_226 == F_8 ( - V_196 ) )
goto V_266;
return;
}
V_136 -> V_151 = V_252 ;
if ( V_264 ) {
V_136 -> V_157 = F_117 ( V_136 , V_264 , V_162 , V_226 ,
V_136 -> V_142 . V_145 ) ;
}
F_19 ( L_50 , V_136 -> V_189 ,
V_136 -> V_157 ) ;
return;
V_266:
V_136 -> V_157 = 0 ;
if ( V_136 -> V_166 == V_162 ) {
V_162 -> V_257 = V_162 -> V_227 . V_20 = 0 ;
if ( V_136 -> V_137 -> V_116 )
F_110 ( V_136 -> V_207 ,
V_162 -> V_255 ) ;
}
}
static T_5 *
F_101 ( struct V_124 * V_136 )
{
struct V_1 * V_2 = V_136 -> V_137 ;
struct V_161 * V_162 = V_136 -> V_166 ;
T_5 * V_226 = V_162 -> V_267 [ 0 ] . V_223 ;
V_226 = F_118 ( V_136 -> V_207 , V_226 ) ;
* V_226 ++ = V_162 -> V_268 ;
* V_226 ++ = F_119 ( V_269 ) ;
* V_226 ++ = F_119 ( V_270 ) ;
* V_226 ++ = F_119 ( V_2 -> V_53 ) ;
* V_226 ++ = F_119 ( V_2 -> V_56 ) ;
* V_226 ++ = F_119 ( V_136 -> V_142 . V_143 -> V_210 ) ;
V_226 = F_120 ( V_136 , V_226 ) ;
V_162 -> V_271 = F_121 ( & V_162 -> V_267 [ 0 ] , V_226 ) ;
return V_226 ;
}
static T_5 *
F_116 ( struct V_124 * V_136 )
{
struct V_272 * V_273 = & V_136 -> V_166 -> V_227 . V_167 [ 0 ] ;
int V_20 = V_136 -> V_166 -> V_227 . V_20 >> 2 ;
T_5 * V_226 = V_273 -> V_223 ;
T_3 V_274 ;
int error = - V_201 ;
if ( ( V_136 -> V_166 -> V_227 . V_20 & 3 ) != 0 ) {
F_19 ( L_51
L_52 , V_136 -> V_189 , V_123 ,
V_136 -> V_166 -> V_227 . V_20 ) ;
goto V_275;
}
if ( ( V_20 -= 3 ) < 0 )
goto V_276;
V_226 += 1 ;
if ( ( V_274 = F_122 ( * V_226 ++ ) ) != V_277 ) {
F_19 ( L_53 ,
V_136 -> V_189 , V_123 , V_274 ) ;
goto V_278;
}
if ( ( V_274 = F_122 ( * V_226 ++ ) ) != V_279 ) {
if ( -- V_20 < 0 )
goto V_276;
switch ( ( V_274 = F_122 ( * V_226 ++ ) ) ) {
case V_280 :
break;
case V_281 :
F_19 ( L_54
L_55 ,
V_136 -> V_189 , V_123 ) ;
error = - V_238 ;
goto V_40;
default:
F_19 ( L_56
L_57 ,
V_136 -> V_189 , V_123 , V_274 ) ;
goto V_275;
}
if ( -- V_20 < 0 )
goto V_276;
switch ( ( V_274 = F_122 ( * V_226 ++ ) ) ) {
case V_282 :
case V_283 :
case V_284 :
case V_285 :
if ( ! V_136 -> V_202 )
break;
V_136 -> V_202 -- ;
F_19 ( L_58 ,
V_136 -> V_189 , V_123 ) ;
F_113 ( V_136 ) ;
F_92 ( V_136 ) ;
V_136 -> V_151 = V_192 ;
goto V_266;
case V_286 :
case V_287 :
if ( ! V_136 -> V_288 )
break;
V_136 -> V_288 -- ;
F_19 ( L_59 ,
V_136 -> V_189 , V_123 ) ;
V_136 -> V_151 = V_208 ;
goto V_266;
case V_289 :
F_15 ( V_254 L_60
L_61 , V_136 -> V_137 -> V_44 ) ;
break;
default:
F_19 ( L_62 ,
V_136 -> V_189 , V_123 , V_274 ) ;
error = - V_128 ;
}
F_19 ( L_63 ,
V_136 -> V_189 , V_123 , V_274 ) ;
goto V_40;
}
if ( ! ( V_226 = F_123 ( V_136 , V_226 ) ) ) {
F_19 ( L_64 ,
V_136 -> V_189 , V_123 ) ;
goto V_278;
}
V_20 = V_226 - ( T_5 * ) V_273 -> V_223 - 1 ;
if ( V_20 < 0 )
goto V_276;
switch ( ( V_274 = F_122 ( * V_226 ++ ) ) ) {
case V_290 :
return V_226 ;
case V_291 :
F_19 ( L_65 ,
V_136 -> V_189 , V_123 ,
( unsigned int ) V_136 -> V_137 -> V_53 ,
V_136 -> V_137 -> V_44 ) ;
error = - V_237 ;
goto V_40;
case V_292 :
F_19 ( L_66
L_67 , V_136 -> V_189 , V_123 ,
( unsigned int ) V_136 -> V_137 -> V_53 ,
( unsigned int ) V_136 -> V_137 -> V_56 ,
V_136 -> V_137 -> V_44 ) ;
error = - V_238 ;
goto V_40;
case V_293 :
F_19 ( L_68
L_69 ,
V_136 -> V_189 , V_123 ,
F_88 ( V_136 ) ,
V_136 -> V_137 -> V_53 ,
V_136 -> V_137 -> V_56 ,
V_136 -> V_137 -> V_44 ) ;
error = - V_235 ;
goto V_40;
case V_294 :
F_19 ( L_70 ,
V_136 -> V_189 , V_123 ) ;
break;
default:
F_19 ( L_71 ,
V_136 -> V_189 , V_123 , V_274 ) ;
}
V_278:
V_136 -> V_137 -> V_57 -> V_295 ++ ;
if ( V_136 -> V_288 ) {
V_136 -> V_288 -- ;
F_19 ( L_72 ,
V_136 -> V_189 , V_123 ) ;
V_136 -> V_151 = V_208 ;
V_266:
return F_8 ( - V_196 ) ;
}
V_275:
error = - V_128 ;
V_40:
F_50 ( V_136 , error ) ;
F_19 ( L_73 , V_136 -> V_189 ,
V_123 , error ) ;
return F_8 ( error ) ;
V_276:
F_19 ( L_74 , V_136 -> V_189 ,
V_123 ) ;
goto V_278;
}
static void F_124 ( void * V_296 , struct V_297 * V_298 , void * V_299 )
{
}
static int F_125 ( void * V_296 , struct V_297 * V_298 , void * V_299 )
{
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_140 V_141 = {
. V_143 = & V_300 ,
} ;
int V_19 ;
V_141 . V_146 = V_301 . V_302 ( NULL , NULL , 0 ) ;
V_19 = F_73 ( V_2 , & V_141 , V_139 | V_303 ) ;
F_126 ( V_141 . V_146 ) ;
return V_19 ;
}
struct V_124 * F_127 ( struct V_1 * V_2 , struct V_146 * V_304 , int V_109 )
{
struct V_140 V_141 = {
. V_143 = & V_300 ,
. V_146 = V_304 ,
} ;
struct V_148 V_149 = {
. V_150 = V_2 ,
. V_140 = & V_141 ,
. V_153 = & V_154 ,
. V_109 = V_109 ,
} ;
return F_69 ( & V_149 ) ;
}
static void F_128 ( void )
{
F_15 ( V_23 L_75
L_76 ) ;
}
static void F_129 ( const struct V_1 * V_2 ,
const struct V_124 * V_136 )
{
const char * V_305 = L_77 ;
if ( F_51 ( V_136 ) )
V_305 = F_130 ( V_136 -> V_129 ) ;
F_15 ( V_23 L_78 ,
V_136 -> V_189 , V_136 -> V_126 , V_136 -> V_157 ,
V_2 , V_136 -> V_166 , V_136 -> V_231 , V_136 -> V_159 ,
V_2 -> V_52 , V_2 -> V_56 , F_88 ( V_136 ) ,
V_136 -> V_151 , V_305 ) ;
}
void F_131 ( void )
{
struct V_1 * V_2 ;
struct V_124 * V_136 ;
int V_306 = 0 ;
F_2 ( & V_3 ) ;
F_48 (clnt, &all_clients, cl_clients) {
F_2 ( & V_2 -> V_63 ) ;
F_48 (task, &clnt->cl_tasks, tk_task) {
if ( ! V_306 ) {
F_128 () ;
V_306 ++ ;
}
F_129 ( V_2 , V_136 ) ;
}
F_4 ( & V_2 -> V_63 ) ;
}
F_4 ( & V_3 ) ;
}
