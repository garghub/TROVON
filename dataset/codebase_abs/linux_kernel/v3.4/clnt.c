static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = F_3 ( V_3 , V_6 ) ;
F_4 ( & V_5 -> V_7 ) ;
F_5 ( & V_2 -> V_8 , & V_5 -> V_9 ) ;
F_6 ( & V_5 -> V_7 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = F_3 ( V_3 , V_6 ) ;
F_4 ( & V_5 -> V_7 ) ;
F_8 ( & V_2 -> V_8 ) ;
F_6 ( & V_5 -> V_7 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 ) {
if ( V_2 -> V_11 && V_2 -> V_11 -> V_12 -> V_13 )
V_2 -> V_11 -> V_12 -> V_13 ( V_2 -> V_11 ) ;
F_10 ( V_2 -> V_10 ) ;
}
V_2 -> V_10 = NULL ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_14 * V_15 ;
V_15 = F_12 ( V_3 ) ;
if ( V_15 ) {
F_9 ( V_2 ) ;
F_13 ( V_3 ) ;
}
}
static struct V_16 * F_14 ( struct V_14 * V_17 ,
struct V_1 * V_2 ,
const char * V_18 )
{
static T_1 V_19 ;
char V_20 [ 15 ] ;
struct V_21 V_22 = {
. V_20 = V_20 ,
} ;
struct V_16 * V_23 , * V_16 ;
int error ;
V_23 = F_15 ( V_17 , V_18 ) ;
if ( V_23 == NULL )
return V_23 ;
for (; ; ) {
V_22 . V_24 = snprintf ( V_20 , sizeof( V_20 ) , L_1 , ( unsigned int ) V_19 ++ ) ;
V_20 [ sizeof( V_20 ) - 1 ] = '\0' ;
V_22 . V_25 = F_16 ( V_22 . V_20 , V_22 . V_24 ) ;
V_16 = F_17 ( V_23 , & V_22 , V_2 ) ;
if ( ! F_18 ( V_16 ) )
break;
error = F_19 ( V_16 ) ;
if ( error != - V_26 ) {
F_20 ( V_27 L_2
L_3 ,
V_18 , V_20 , error ) ;
break;
}
}
F_21 ( V_23 ) ;
return V_16 ;
}
static int
F_22 ( struct V_1 * V_2 , const char * V_18 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_14 * V_15 ;
struct V_16 * V_16 ;
V_2 -> V_10 = NULL ;
if ( V_18 == NULL )
return 0 ;
V_15 = F_12 ( V_3 ) ;
if ( ! V_15 )
return 0 ;
V_16 = F_14 ( V_15 , V_2 , V_18 ) ;
F_13 ( V_3 ) ;
if ( F_18 ( V_16 ) )
return F_19 ( V_16 ) ;
V_2 -> V_10 = V_16 ;
return 0 ;
}
static inline int F_23 ( struct V_1 * V_2 , unsigned long V_28 )
{
if ( ( ( V_28 == V_29 ) && V_2 -> V_10 ) ||
( ( V_28 == V_30 ) && ! V_2 -> V_10 ) )
return 1 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , unsigned long V_28 ,
struct V_14 * V_17 )
{
struct V_16 * V_16 ;
int V_31 = 0 ;
switch ( V_28 ) {
case V_29 :
V_16 = F_14 ( V_17 , V_2 ,
V_2 -> V_32 -> V_33 ) ;
F_25 ( V_16 == NULL ) ;
if ( F_18 ( V_16 ) )
return F_19 ( V_16 ) ;
V_2 -> V_10 = V_16 ;
if ( V_2 -> V_11 -> V_12 -> V_34 ) {
V_31 = V_2 -> V_11 -> V_12 -> V_34 ( V_2 -> V_11 ) ;
if ( V_31 )
F_9 ( V_2 ) ;
}
break;
case V_30 :
F_9 ( V_2 ) ;
break;
default:
F_20 ( V_35 L_4 , V_36 , V_28 ) ;
return - V_37 ;
}
return V_31 ;
}
static int F_26 ( struct V_1 * V_2 , unsigned long V_28 ,
struct V_14 * V_17 )
{
int error = 0 ;
for (; ; V_2 = V_2 -> V_38 ) {
if ( ! F_23 ( V_2 , V_28 ) )
error = F_24 ( V_2 , V_28 , V_17 ) ;
if ( error || V_2 == V_2 -> V_38 )
break;
}
return error ;
}
static struct V_1 * F_27 ( struct V_3 * V_3 , int V_28 )
{
struct V_4 * V_5 = F_3 ( V_3 , V_6 ) ;
struct V_1 * V_2 ;
F_4 ( & V_5 -> V_7 ) ;
F_28 (clnt, &sn->all_clients, cl_clients) {
if ( V_2 -> V_32 -> V_33 == NULL )
break;
if ( F_23 ( V_2 , V_28 ) )
continue;
if ( F_29 ( & V_2 -> V_39 ) == 0 )
continue;
F_6 ( & V_5 -> V_7 ) ;
return V_2 ;
}
F_6 ( & V_5 -> V_7 ) ;
return NULL ;
}
static int F_30 ( struct V_40 * V_41 , unsigned long V_28 ,
void * V_42 )
{
struct V_14 * V_17 = V_42 ;
struct V_1 * V_2 ;
int error = 0 ;
while ( ( V_2 = F_27 ( V_17 -> V_43 , V_28 ) ) ) {
error = F_26 ( V_2 , V_28 , V_17 ) ;
F_31 ( V_2 ) ;
if ( error )
break;
}
return error ;
}
int F_32 ( void )
{
return F_33 ( & V_44 ) ;
}
void F_34 ( void )
{
return F_35 ( & V_44 ) ;
}
static void F_36 ( struct V_1 * V_2 , const char * V_45 )
{
V_2 -> V_46 = strlen ( V_45 ) ;
if ( V_2 -> V_46 > V_47 )
V_2 -> V_46 = V_47 ;
memcpy ( V_2 -> V_48 , V_45 , V_2 -> V_46 ) ;
}
static struct V_1 * F_37 ( const struct V_49 * args , struct V_50 * V_51 )
{
const struct V_52 * V_53 = args -> V_53 ;
const struct V_54 * V_55 ;
struct V_1 * V_2 = NULL ;
struct V_56 * V_57 ;
int V_31 ;
F_38 ( L_5 ,
V_53 -> V_20 , args -> V_58 , V_51 ) ;
V_31 = F_39 () ;
if ( V_31 )
goto V_59;
V_31 = - V_60 ;
if ( ! V_51 )
goto V_61;
if ( args -> V_55 >= V_53 -> V_62 )
goto V_63;
V_55 = V_53 -> V_55 [ args -> V_55 ] ;
if ( V_55 == NULL )
goto V_63;
V_31 = - V_64 ;
V_2 = F_40 ( sizeof( * V_2 ) , V_65 ) ;
if ( ! V_2 )
goto V_63;
V_2 -> V_38 = V_2 ;
F_41 ( V_2 -> V_66 , V_51 ) ;
V_2 -> V_67 = V_55 -> V_68 ;
V_2 -> V_69 = V_55 -> V_70 ;
V_2 -> V_71 = V_53 -> V_20 ;
V_2 -> V_72 = args -> V_73 ? : V_53 -> V_74 ;
V_2 -> V_75 = V_55 -> V_74 ;
V_2 -> V_76 = V_53 -> V_77 ;
V_2 -> V_78 = F_42 ( V_2 ) ;
V_31 = - V_64 ;
if ( V_2 -> V_78 == NULL )
goto V_79;
V_2 -> V_32 = V_53 ;
F_43 ( & V_2 -> V_80 ) ;
F_44 ( & V_2 -> V_81 ) ;
if ( ! F_45 ( V_51 ) )
V_2 -> V_82 = 1 ;
V_2 -> V_83 = V_51 -> V_84 ;
if ( args -> V_84 != NULL ) {
memcpy ( & V_2 -> V_85 , args -> V_84 ,
sizeof( V_2 -> V_85 ) ) ;
V_2 -> V_83 = & V_2 -> V_85 ;
}
V_2 -> V_86 = & V_2 -> V_87 ;
F_46 ( & V_2 -> V_87 , V_2 -> V_83 -> V_88 ) ;
V_2 -> V_89 = NULL ;
if ( args -> V_90 ) {
V_2 -> V_89 = F_47 ( args -> V_90 , V_65 ) ;
if ( ! V_2 -> V_89 )
goto V_91;
}
F_48 ( & V_2 -> V_39 , 1 ) ;
V_31 = F_22 ( V_2 , V_53 -> V_33 ) ;
if ( V_31 < 0 )
goto V_92;
V_57 = F_49 ( args -> V_93 , V_2 ) ;
if ( F_18 ( V_57 ) ) {
F_20 ( V_27 L_6 ,
args -> V_93 ) ;
V_31 = F_19 ( V_57 ) ;
goto V_94;
}
F_36 ( V_2 , F_50 () -> V_45 ) ;
F_1 ( V_2 ) ;
return V_2 ;
V_94:
F_11 ( V_2 ) ;
V_92:
F_51 ( V_2 -> V_89 ) ;
V_91:
F_52 ( V_2 -> V_78 ) ;
V_79:
F_51 ( V_2 ) ;
V_63:
F_53 ( V_51 ) ;
V_61:
F_54 () ;
V_59:
return F_55 ( V_31 ) ;
}
struct V_1 * F_56 ( struct V_49 * args )
{
struct V_50 * V_51 ;
struct V_1 * V_2 ;
struct V_95 V_96 = {
. V_3 = args -> V_3 ,
. V_97 = args -> V_98 ,
. V_99 = args -> V_100 ,
. V_101 = args -> V_102 ,
. V_103 = args -> V_104 ,
. V_58 = args -> V_58 ,
. V_105 = args -> V_105 ,
} ;
char V_58 [ 48 ] ;
if ( V_96 . V_58 == NULL ) {
struct V_106 * V_107 =
(struct V_106 * ) args -> V_102 ;
struct V_108 * sin =
(struct V_108 * ) args -> V_102 ;
struct V_109 * V_110 =
(struct V_109 * ) args -> V_102 ;
V_58 [ 0 ] = '\0' ;
switch ( args -> V_102 -> V_111 ) {
case V_112 :
snprintf ( V_58 , sizeof( V_58 ) , L_7 ,
V_107 -> V_113 ) ;
break;
case V_114 :
snprintf ( V_58 , sizeof( V_58 ) , L_8 ,
& sin -> V_115 . V_116 ) ;
break;
case V_117 :
snprintf ( V_58 , sizeof( V_58 ) , L_9 ,
& V_110 -> V_118 ) ;
break;
default:
return F_55 ( - V_60 ) ;
}
V_96 . V_58 = V_58 ;
}
V_51 = F_57 ( & V_96 ) ;
if ( F_18 ( V_51 ) )
return (struct V_1 * ) V_51 ;
V_51 -> V_119 = 1 ;
if ( args -> V_120 & V_121 )
V_51 -> V_119 = 0 ;
V_2 = F_37 ( args , V_51 ) ;
if ( F_18 ( V_2 ) )
return V_2 ;
if ( ! ( args -> V_120 & V_122 ) ) {
int V_31 = F_58 ( V_2 ) ;
if ( V_31 != 0 ) {
F_59 ( V_2 ) ;
return F_55 ( V_31 ) ;
}
}
V_2 -> V_123 = 1 ;
if ( args -> V_120 & V_124 )
V_2 -> V_123 = 0 ;
if ( args -> V_120 & V_125 )
V_2 -> V_82 = 1 ;
if ( args -> V_120 & V_126 )
V_2 -> V_127 = 1 ;
if ( ! ( args -> V_120 & V_128 ) )
V_2 -> V_129 = 1 ;
return V_2 ;
}
struct V_1 *
F_60 ( struct V_1 * V_2 )
{
struct V_1 * V_130 ;
struct V_50 * V_51 ;
int V_31 = - V_64 ;
V_130 = F_61 ( V_2 , sizeof( * V_130 ) , V_65 ) ;
if ( ! V_130 )
goto V_131;
V_130 -> V_38 = V_2 ;
V_130 -> V_82 = 0 ;
F_43 ( & V_130 -> V_80 ) ;
F_44 ( & V_130 -> V_81 ) ;
F_46 ( & V_130 -> V_87 , V_2 -> V_83 -> V_88 ) ;
V_130 -> V_78 = F_42 ( V_2 ) ;
if ( V_130 -> V_78 == NULL )
goto V_79;
if ( V_2 -> V_89 ) {
V_130 -> V_89 = F_47 ( V_2 -> V_89 , V_65 ) ;
if ( V_130 -> V_89 == NULL )
goto V_91;
}
F_62 () ;
V_51 = F_63 ( F_64 ( V_2 -> V_66 ) ) ;
F_65 () ;
if ( V_51 == NULL )
goto V_132;
F_41 ( V_130 -> V_66 , V_51 ) ;
F_48 ( & V_130 -> V_39 , 1 ) ;
V_31 = F_22 ( V_130 , V_2 -> V_32 -> V_33 ) ;
if ( V_31 != 0 )
goto V_92;
F_36 ( V_130 , F_50 () -> V_45 ) ;
if ( V_130 -> V_11 )
F_66 ( & V_130 -> V_11 -> V_133 ) ;
F_66 ( & V_2 -> V_39 ) ;
F_1 ( V_130 ) ;
F_39 () ;
return V_130 ;
V_92:
F_53 ( V_51 ) ;
V_132:
F_51 ( V_130 -> V_89 ) ;
V_91:
F_52 ( V_130 -> V_78 ) ;
V_79:
F_51 ( V_130 ) ;
V_131:
F_38 ( L_10 , V_36 , V_31 ) ;
return F_55 ( V_31 ) ;
}
void F_67 ( struct V_1 * V_2 )
{
struct V_134 * V_135 ;
if ( F_68 ( & V_2 -> V_80 ) )
return;
F_38 ( L_11 , V_2 ) ;
F_4 ( & V_2 -> V_81 ) ;
F_28 (rovr, &clnt->cl_tasks, tk_task) {
if ( ! F_69 ( V_135 ) )
continue;
if ( ! ( V_135 -> V_136 & V_137 ) ) {
V_135 -> V_136 |= V_137 ;
F_70 ( V_135 , - V_138 ) ;
if ( F_71 ( V_135 ) )
F_72 ( V_135 -> V_139 ,
V_135 ) ;
}
}
F_6 ( & V_2 -> V_81 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
F_73 ( L_12 ,
V_2 -> V_71 ,
F_64 ( V_2 -> V_66 ) -> V_58 ) ;
while ( ! F_68 ( & V_2 -> V_80 ) ) {
F_67 ( V_2 ) ;
F_74 ( V_140 ,
F_68 ( & V_2 -> V_80 ) , 1 * V_141 ) ;
}
F_31 ( V_2 ) ;
}
static void
F_75 ( struct V_1 * V_2 )
{
F_73 ( L_13 ,
V_2 -> V_71 ,
F_64 ( V_2 -> V_66 ) -> V_58 ) ;
if ( V_2 -> V_38 != V_2 )
F_31 ( V_2 -> V_38 ) ;
F_7 ( V_2 ) ;
F_11 ( V_2 ) ;
F_52 ( V_2 -> V_78 ) ;
F_51 ( V_2 -> V_89 ) ;
V_2 -> V_78 = NULL ;
F_53 ( F_76 ( V_2 -> V_66 ) ) ;
F_54 () ;
F_51 ( V_2 ) ;
}
static void
F_77 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 == NULL ) {
F_75 ( V_2 ) ;
return;
}
F_66 ( & V_2 -> V_39 ) ;
F_78 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
if ( F_79 ( & V_2 -> V_39 ) )
F_75 ( V_2 ) ;
}
void
F_31 ( struct V_1 * V_2 )
{
F_38 ( L_14 , V_2 ) ;
if ( F_68 ( & V_2 -> V_80 ) )
F_80 ( & V_140 ) ;
if ( F_79 ( & V_2 -> V_39 ) )
F_77 ( V_2 ) ;
}
struct V_1 * F_81 ( struct V_1 * V_142 ,
const struct V_52 * V_53 ,
T_2 V_143 )
{
struct V_1 * V_2 ;
const struct V_54 * V_55 ;
int V_31 ;
F_25 ( V_143 >= V_53 -> V_62 || ! V_53 -> V_55 [ V_143 ] ) ;
V_55 = V_53 -> V_55 [ V_143 ] ;
V_2 = F_60 ( V_142 ) ;
if ( F_18 ( V_2 ) )
goto V_144;
V_2 -> V_67 = V_55 -> V_68 ;
V_2 -> V_69 = V_55 -> V_70 ;
V_2 -> V_71 = V_53 -> V_20 ;
V_2 -> V_72 = V_53 -> V_74 ;
V_2 -> V_75 = V_55 -> V_74 ;
V_2 -> V_76 = V_53 -> V_77 ;
V_31 = F_58 ( V_2 ) ;
if ( V_31 != 0 ) {
F_59 ( V_2 ) ;
V_2 = F_55 ( V_31 ) ;
}
V_144:
return V_2 ;
}
void F_82 ( struct V_134 * V_145 )
{
struct V_1 * V_2 = V_145 -> V_146 ;
if ( V_2 != NULL ) {
F_4 ( & V_2 -> V_81 ) ;
F_8 ( & V_145 -> V_147 ) ;
F_6 ( & V_2 -> V_81 ) ;
V_145 -> V_146 = NULL ;
F_31 ( V_2 ) ;
}
}
static
void F_83 ( struct V_134 * V_145 , struct V_1 * V_2 )
{
if ( V_2 != NULL ) {
F_82 ( V_145 ) ;
V_145 -> V_146 = V_2 ;
F_66 ( & V_2 -> V_39 ) ;
if ( V_2 -> V_123 )
V_145 -> V_136 |= V_148 ;
F_4 ( & V_2 -> V_81 ) ;
F_84 ( & V_145 -> V_147 , & V_2 -> V_80 ) ;
F_6 ( & V_2 -> V_81 ) ;
}
}
void F_85 ( struct V_134 * V_145 , struct V_1 * V_2 )
{
F_82 ( V_145 ) ;
F_83 ( V_145 , V_2 ) ;
}
static void
F_86 ( struct V_134 * V_145 , const struct V_149 * V_150 )
{
if ( V_150 != NULL ) {
V_145 -> V_151 . V_152 = V_150 -> V_152 ;
V_145 -> V_151 . V_153 = V_150 -> V_153 ;
V_145 -> V_151 . V_154 = V_150 -> V_154 ;
if ( V_150 -> V_155 != NULL )
V_145 -> V_151 . V_155 = F_87 ( V_150 -> V_155 ) ;
}
}
static void
F_88 ( struct V_134 * V_145 , void * V_156 )
{
}
struct V_134 * F_89 ( const struct V_157 * V_158 )
{
struct V_134 * V_145 ;
V_145 = F_90 ( V_158 ) ;
if ( F_18 ( V_145 ) )
goto V_144;
F_83 ( V_145 , V_158 -> V_159 ) ;
F_86 ( V_145 , V_158 -> V_149 ) ;
if ( V_145 -> V_160 == NULL )
F_91 ( V_145 ) ;
F_66 ( & V_145 -> V_161 ) ;
F_92 ( V_145 ) ;
V_144:
return V_145 ;
}
int F_93 ( struct V_1 * V_2 , const struct V_149 * V_150 , int V_120 )
{
struct V_134 * V_145 ;
struct V_157 V_158 = {
. V_159 = V_2 ,
. V_149 = V_150 ,
. V_162 = & V_163 ,
. V_120 = V_120 ,
} ;
int V_164 ;
F_25 ( V_120 & V_165 ) ;
V_145 = F_89 ( & V_158 ) ;
if ( F_18 ( V_145 ) )
return F_19 ( V_145 ) ;
V_164 = V_145 -> V_166 ;
F_94 ( V_145 ) ;
return V_164 ;
}
int
F_95 ( struct V_1 * V_2 , const struct V_149 * V_150 , int V_120 ,
const struct V_167 * V_168 , void * V_156 )
{
struct V_134 * V_145 ;
struct V_157 V_158 = {
. V_159 = V_2 ,
. V_149 = V_150 ,
. V_162 = V_168 ,
. V_169 = V_156 ,
. V_120 = V_120 | V_165 ,
} ;
V_145 = F_89 ( & V_158 ) ;
if ( F_18 ( V_145 ) )
return F_19 ( V_145 ) ;
F_94 ( V_145 ) ;
return 0 ;
}
struct V_134 * F_96 ( struct V_170 * V_171 ,
const struct V_167 * V_168 )
{
struct V_134 * V_145 ;
struct V_172 * V_173 = & V_171 -> V_174 ;
struct V_157 V_158 = {
. V_162 = V_168 ,
} ;
F_38 ( L_15 , V_171 ) ;
V_145 = F_90 ( & V_158 ) ;
if ( F_18 ( V_145 ) ) {
F_97 ( V_171 ) ;
goto V_144;
}
V_145 -> V_175 = V_171 ;
V_173 -> V_24 = V_173 -> V_176 [ 0 ] . V_177 + V_173 -> V_178 +
V_173 -> V_179 [ 0 ] . V_177 ;
V_145 -> V_160 = V_180 ;
F_66 ( & V_145 -> V_161 ) ;
F_25 ( F_98 ( & V_145 -> V_161 ) != 2 ) ;
F_92 ( V_145 ) ;
V_144:
F_38 ( L_16 , V_145 ) ;
return V_145 ;
}
void
F_91 ( struct V_134 * V_145 )
{
V_145 -> V_160 = V_181 ;
}
T_3 F_99 ( struct V_1 * V_2 , struct V_182 * V_183 , T_3 V_184 )
{
T_3 V_185 ;
struct V_50 * V_51 ;
F_62 () ;
V_51 = F_64 ( V_2 -> V_66 ) ;
V_185 = V_51 -> V_103 ;
if ( V_185 > V_184 )
V_185 = V_184 ;
memcpy ( V_183 , & V_51 -> V_186 , V_185 ) ;
F_65 () ;
return V_185 ;
}
const char * F_100 ( struct V_1 * V_2 ,
enum V_187 V_188 )
{
struct V_50 * V_51 ;
V_51 = F_64 ( V_2 -> V_66 ) ;
if ( V_51 -> V_189 [ V_188 ] != NULL )
return V_51 -> V_189 [ V_188 ] ;
else
return L_17 ;
}
static int F_101 ( struct V_3 * V_3 , struct V_182 * V_190 , T_3 V_191 ,
struct V_182 * V_183 , int V_192 )
{
struct V_193 * V_194 ;
int V_31 ;
V_31 = F_102 ( V_3 , V_190 -> V_111 ,
V_195 , V_196 , & V_194 , 1 ) ;
if ( V_31 < 0 ) {
F_38 ( L_18 , V_31 ) ;
goto V_144;
}
switch ( V_190 -> V_111 ) {
case V_114 :
V_31 = F_103 ( V_194 ,
(struct V_182 * ) & V_197 ,
sizeof( V_197 ) ) ;
break;
case V_117 :
V_31 = F_103 ( V_194 ,
(struct V_182 * ) & V_198 ,
sizeof( V_198 ) ) ;
break;
default:
V_31 = - V_199 ;
goto V_144;
}
if ( V_31 < 0 ) {
F_38 ( L_19 , V_31 ) ;
goto V_200;
}
V_31 = F_104 ( V_194 , V_190 , V_191 , 0 ) ;
if ( V_31 < 0 ) {
F_38 ( L_20 , V_31 ) ;
goto V_200;
}
V_31 = F_105 ( V_194 , V_183 , & V_192 ) ;
if ( V_31 < 0 ) {
F_38 ( L_21 , V_31 ) ;
goto V_200;
}
V_31 = 0 ;
if ( V_183 -> V_111 == V_117 ) {
struct V_109 * V_110 = (struct V_109 * ) V_183 ;
V_110 -> V_201 = 0 ;
}
F_38 ( L_22 , V_36 ) ;
V_200:
F_106 ( V_194 ) ;
V_144:
return V_31 ;
}
static int F_107 ( int V_202 , struct V_182 * V_183 , T_3 V_192 )
{
switch ( V_202 ) {
case V_114 :
if ( V_192 < sizeof( V_197 ) )
return - V_60 ;
memcpy ( V_183 , & V_197 ,
sizeof( V_197 ) ) ;
break;
case V_117 :
if ( V_192 < sizeof( V_198 ) )
return - V_60 ;
memcpy ( V_183 , & V_198 ,
sizeof( V_198 ) ) ;
default:
F_38 ( L_23 ,
V_36 ) ;
return - V_199 ;
}
F_38 ( L_24 , V_36 ) ;
return 0 ;
}
int F_108 ( struct V_1 * V_2 , struct V_182 * V_183 , T_3 V_192 )
{
struct V_203 V_102 ;
struct V_182 * V_190 = (struct V_182 * ) & V_102 ;
struct V_50 * V_51 ;
struct V_3 * V_3 ;
T_3 V_191 ;
int V_31 ;
F_62 () ;
V_51 = F_64 ( V_2 -> V_66 ) ;
V_191 = V_51 -> V_103 ;
memcpy ( V_190 , & V_51 -> V_186 , V_191 ) ;
V_3 = F_109 ( V_51 -> V_204 ) ;
F_65 () ;
F_110 ( V_190 , 0 ) ;
V_31 = F_101 ( V_3 , V_190 , V_191 , V_183 , V_192 ) ;
F_111 ( V_3 ) ;
if ( V_31 != 0 )
return F_107 ( V_190 -> V_111 , V_183 , V_192 ) ;
return 0 ;
}
void
F_112 ( struct V_1 * V_2 , unsigned int V_205 , unsigned int V_206 )
{
struct V_50 * V_51 ;
F_62 () ;
V_51 = F_64 ( V_2 -> V_66 ) ;
if ( V_51 -> V_207 -> V_208 )
V_51 -> V_207 -> V_208 ( V_51 , V_205 , V_206 ) ;
F_65 () ;
}
int F_113 ( struct V_1 * V_2 )
{
int V_98 ;
F_62 () ;
V_98 = F_64 ( V_2 -> V_66 ) -> V_209 ;
F_65 () ;
return V_98 ;
}
struct V_3 * F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_210 ;
F_62 () ;
V_210 = F_64 ( V_2 -> V_66 ) -> V_204 ;
F_65 () ;
return V_210 ;
}
T_3 F_114 ( struct V_1 * V_2 )
{
T_3 V_210 ;
F_62 () ;
V_210 = F_64 ( V_2 -> V_66 ) -> V_211 ;
F_65 () ;
return V_210 ;
}
void F_115 ( struct V_1 * V_2 )
{
if ( V_2 -> V_82 ) {
F_62 () ;
F_116 ( F_64 ( V_2 -> V_66 ) ) ;
F_65 () ;
}
}
int
F_117 ( struct V_134 * V_145 )
{
if ( F_118 ( V_145 ) )
return 0 ;
V_145 -> V_160 = V_181 ;
if ( V_145 -> V_168 -> V_212 != NULL )
V_145 -> V_160 = V_213 ;
return 1 ;
}
int
F_119 ( struct V_134 * V_145 )
{
if ( F_118 ( V_145 ) )
return 0 ;
V_145 -> V_160 = V_181 ;
return 1 ;
}
static const char * F_120 ( const struct V_134 * V_145 )
{
const struct V_214 * V_215 = V_145 -> V_151 . V_152 ;
if ( V_215 ) {
if ( V_215 -> V_216 )
return V_215 -> V_216 ;
else
return L_25 ;
} else
return L_26 ;
}
static void
V_181 ( struct V_134 * V_145 )
{
struct V_1 * V_2 = V_145 -> V_146 ;
F_38 ( L_27 , V_145 -> V_217 ,
V_2 -> V_71 , V_2 -> V_75 ,
F_120 ( V_145 ) ,
( F_121 ( V_145 ) ? L_28 : L_29 ) ) ;
V_145 -> V_151 . V_152 -> V_218 ++ ;
V_2 -> V_76 -> V_219 ++ ;
V_145 -> V_160 = V_220 ;
}
static void
V_220 ( struct V_134 * V_145 )
{
F_122 ( V_145 ) ;
V_145 -> V_166 = 0 ;
V_145 -> V_160 = V_221 ;
F_123 ( V_145 ) ;
}
static void
V_221 ( struct V_134 * V_145 )
{
int V_164 = V_145 -> V_166 ;
F_122 ( V_145 ) ;
V_145 -> V_166 = 0 ;
if ( V_164 >= 0 ) {
if ( V_145 -> V_175 ) {
V_145 -> V_160 = V_222 ;
return;
}
F_20 ( V_35 L_30 ,
V_36 , V_164 ) ;
F_70 ( V_145 , - V_138 ) ;
return;
}
if ( V_145 -> V_175 ) {
F_20 ( V_35 L_31 ,
V_36 , V_164 ) ;
F_124 ( V_145 ) ;
}
switch ( V_164 ) {
case - V_223 :
V_145 -> V_160 = V_220 ;
return;
case - V_138 :
break;
default:
F_20 ( V_35 L_32 ,
V_36 , V_164 ) ;
break;
}
F_70 ( V_145 , V_164 ) ;
}
static void
V_222 ( struct V_134 * V_145 )
{
F_122 ( V_145 ) ;
V_145 -> V_160 = V_224 ;
V_145 -> V_166 = 0 ;
V_145 -> V_146 -> V_76 -> V_225 ++ ;
F_125 ( V_145 ) ;
}
static void
V_224 ( struct V_134 * V_145 )
{
int V_164 = V_145 -> V_166 ;
F_122 ( V_145 ) ;
V_145 -> V_166 = 0 ;
V_145 -> V_160 = V_222 ;
switch ( V_164 ) {
case 0 :
if ( F_126 ( V_145 ) )
V_145 -> V_160 = V_226 ;
return;
case - V_227 :
F_127 ( V_145 , 3 * V_141 ) ;
case - V_223 :
V_164 = - V_228 ;
if ( ! V_145 -> V_229 )
break;
V_145 -> V_229 -- ;
F_38 ( L_33 ,
V_145 -> V_217 , V_36 ) ;
return;
}
F_38 ( L_34 ,
V_145 -> V_217 , V_36 , V_164 ) ;
F_70 ( V_145 , V_164 ) ;
}
static void
V_226 ( struct V_134 * V_145 )
{
unsigned int V_230 = V_145 -> V_175 -> V_231 -> V_232 -> V_233 ;
struct V_170 * V_171 = V_145 -> V_175 ;
struct V_50 * V_51 = V_145 -> V_234 ;
struct V_214 * V_215 = V_145 -> V_151 . V_152 ;
F_122 ( V_145 ) ;
V_145 -> V_166 = 0 ;
V_145 -> V_160 = V_235 ;
if ( V_171 -> V_236 )
return;
if ( V_215 -> V_237 != 0 ) {
F_25 ( V_215 -> V_238 == 0 ) ;
if ( V_215 -> V_239 != NULL )
F_25 ( V_215 -> V_240 == 0 ) ;
}
V_171 -> V_241 = V_242 + ( V_230 << 1 ) + V_215 -> V_238 ;
V_171 -> V_241 <<= 2 ;
V_171 -> V_243 = V_244 + V_230 + V_215 -> V_240 ;
V_171 -> V_243 <<= 2 ;
V_171 -> V_236 = V_51 -> V_207 -> V_245 ( V_145 ,
V_171 -> V_241 + V_171 -> V_243 ) ;
if ( V_171 -> V_236 != NULL )
return;
F_38 ( L_35 , V_145 -> V_217 ) ;
if ( F_121 ( V_145 ) || ! F_128 ( V_246 ) ) {
V_145 -> V_160 = V_226 ;
F_127 ( V_145 , V_141 >> 4 ) ;
return;
}
F_70 ( V_145 , - V_247 ) ;
}
static inline int
F_129 ( struct V_134 * V_145 )
{
return V_145 -> V_175 -> V_174 . V_24 == 0 ;
}
static inline void
F_130 ( struct V_134 * V_145 )
{
V_145 -> V_175 -> V_174 . V_24 = 0 ;
V_145 -> V_175 -> V_248 = 0 ;
}
static inline void
F_131 ( struct V_172 * V_183 , void * V_249 , T_3 V_24 )
{
V_183 -> V_176 [ 0 ] . V_250 = V_249 ;
V_183 -> V_176 [ 0 ] . V_177 = V_24 ;
V_183 -> V_179 [ 0 ] . V_177 = 0 ;
V_183 -> V_178 = 0 ;
V_183 -> V_120 = 0 ;
V_183 -> V_24 = 0 ;
V_183 -> V_192 = V_24 ;
}
static void
F_132 ( struct V_134 * V_145 )
{
struct V_170 * V_171 = V_145 -> V_175 ;
T_4 V_251 ;
T_5 * V_252 ;
F_122 ( V_145 ) ;
F_131 ( & V_171 -> V_174 ,
V_171 -> V_236 ,
V_171 -> V_241 ) ;
F_131 ( & V_171 -> V_253 ,
( char * ) V_171 -> V_236 + V_171 -> V_241 ,
V_171 -> V_243 ) ;
V_252 = F_133 ( V_145 ) ;
if ( V_252 == NULL ) {
F_20 ( V_27 L_36 ) ;
F_70 ( V_145 , - V_138 ) ;
return;
}
V_251 = V_145 -> V_151 . V_152 -> V_254 ;
if ( V_251 == NULL )
return;
V_145 -> V_166 = F_134 ( V_145 , V_251 , V_171 , V_252 ,
V_145 -> V_151 . V_153 ) ;
}
static void
V_235 ( struct V_134 * V_145 )
{
struct V_50 * V_51 = V_145 -> V_234 ;
F_122 ( V_145 ) ;
V_145 -> V_160 = V_255 ;
if ( ! F_45 ( V_51 ) ) {
V_145 -> V_160 = V_256 ;
V_145 -> V_257 = V_51 -> V_258 ;
V_51 -> V_207 -> V_259 ( V_145 ) ;
}
}
static void
V_256 ( struct V_134 * V_145 )
{
int V_164 = - V_138 ;
if ( V_145 -> V_166 >= 0 ) {
F_122 ( V_145 ) ;
V_145 -> V_166 = 0 ;
V_145 -> V_160 = V_255 ;
return;
}
F_135 ( V_145 ) ;
switch ( V_145 -> V_166 ) {
case - V_64 :
F_38 ( L_37 , V_145 -> V_217 ) ;
F_127 ( V_145 , V_141 >> 2 ) ;
goto V_260;
case - V_228 :
F_38 ( L_38
L_39 , V_145 -> V_217 ) ;
if ( V_145 -> V_151 . V_152 -> V_237 == 0 ) {
V_164 = - V_261 ;
break;
}
if ( V_145 -> V_262 == 0 )
break;
V_145 -> V_262 -- ;
F_127 ( V_145 , 3 * V_141 ) ;
goto V_260;
case - V_227 :
F_38 ( L_40 ,
V_145 -> V_217 ) ;
goto V_260;
case - V_263 :
F_38 ( L_41 ,
V_145 -> V_217 ) ;
break;
case - V_264 :
F_38 ( L_42 ,
V_145 -> V_217 ) ;
V_145 -> V_166 = 0 ;
V_145 -> V_160 = V_235 ;
return;
case - V_265 :
case - V_266 :
case - V_267 :
case - V_268 :
case - V_269 :
case - V_270 :
case - V_271 :
F_38 ( L_43 ,
V_145 -> V_217 , V_145 -> V_166 ) ;
if ( ! F_136 ( V_145 ) ) {
F_127 ( V_145 , 5 * V_141 ) ;
goto V_260;
}
V_164 = V_145 -> V_166 ;
break;
default:
F_38 ( L_44 ,
V_145 -> V_217 , - V_145 -> V_166 ) ;
}
F_70 ( V_145 , V_164 ) ;
return;
V_260:
V_145 -> V_160 = V_272 ;
}
static void
V_255 ( struct V_134 * V_145 )
{
struct V_50 * V_51 = V_145 -> V_234 ;
F_38 ( L_45 ,
V_145 -> V_217 , V_51 ,
( F_137 ( V_51 ) ? L_46 : L_47 ) ) ;
V_145 -> V_160 = V_273 ;
if ( ! F_137 ( V_51 ) ) {
V_145 -> V_160 = V_274 ;
if ( V_145 -> V_166 < 0 )
return;
F_138 ( V_145 ) ;
}
}
static void
V_274 ( struct V_134 * V_145 )
{
struct V_1 * V_2 = V_145 -> V_146 ;
int V_164 = V_145 -> V_166 ;
F_122 ( V_145 ) ;
V_145 -> V_166 = 0 ;
if ( V_164 >= 0 || V_164 == - V_223 ) {
V_2 -> V_76 -> V_275 ++ ;
V_145 -> V_160 = V_273 ;
return;
}
F_139 ( V_145 , V_164 ) ;
switch ( V_164 ) {
case - V_227 :
V_145 -> V_160 = V_272 ;
break;
default:
F_70 ( V_145 , - V_138 ) ;
}
}
static void
V_273 ( struct V_134 * V_145 )
{
F_122 ( V_145 ) ;
V_145 -> V_160 = V_276 ;
if ( V_145 -> V_166 < 0 )
return;
V_145 -> V_166 = F_140 ( V_145 ) ;
if ( V_145 -> V_166 != 0 )
return;
V_145 -> V_160 = V_277 ;
if ( F_129 ( V_145 ) ) {
F_25 ( V_145 -> V_175 -> V_248 != 0 ) ;
F_132 ( V_145 ) ;
if ( V_145 -> V_166 != 0 ) {
if ( V_145 -> V_166 == - V_223 )
F_127 ( V_145 , V_141 >> 4 ) ;
else
F_70 ( V_145 , V_145 -> V_166 ) ;
return;
}
}
F_141 ( V_145 ) ;
if ( V_145 -> V_166 < 0 )
return;
V_277 ( V_145 ) ;
if ( F_142 ( V_145 ) )
return;
V_145 -> V_160 = V_278 ;
F_72 ( & V_145 -> V_234 -> V_279 , V_145 ) ;
}
static void
V_277 ( struct V_134 * V_145 )
{
V_145 -> V_160 = V_276 ;
if ( V_145 -> V_166 == 0 ) {
F_143 ( V_145 ) ;
F_130 ( V_145 ) ;
return;
}
switch ( V_145 -> V_166 ) {
case - V_223 :
break;
default:
F_122 ( V_145 ) ;
F_143 ( V_145 ) ;
F_130 ( V_145 ) ;
break;
case - V_265 :
case - V_268 :
case - V_269 :
case - V_270 :
if ( F_136 ( V_145 ) ) {
F_143 ( V_145 ) ;
F_70 ( V_145 , V_145 -> V_166 ) ;
break;
}
case - V_266 :
case - V_267 :
case - V_271 :
F_130 ( V_145 ) ;
}
}
static void
V_180 ( struct V_134 * V_145 )
{
struct V_170 * V_171 = V_145 -> V_175 ;
F_25 ( V_145 -> V_166 != 0 ) ;
V_145 -> V_166 = F_140 ( V_145 ) ;
if ( V_145 -> V_166 == - V_223 ) {
V_145 -> V_166 = 0 ;
V_145 -> V_160 = V_180 ;
return;
}
V_145 -> V_160 = V_278 ;
if ( V_145 -> V_166 < 0 ) {
F_20 ( V_280 L_48
L_49 , V_145 -> V_166 ) ;
return;
}
F_141 ( V_145 ) ;
F_143 ( V_145 ) ;
F_122 ( V_145 ) ;
switch ( V_145 -> V_166 ) {
case 0 :
break;
case - V_268 :
case - V_269 :
case - V_270 :
case - V_227 :
F_20 ( V_280 L_48
L_49 , V_145 -> V_166 ) ;
F_144 ( V_145 -> V_234 ,
V_171 -> V_281 ) ;
break;
default:
F_25 ( V_145 -> V_166 == - V_223 ) ;
F_20 ( V_280 L_48
L_49 , V_145 -> V_166 ) ;
break;
}
F_72 ( & V_171 -> V_282 -> V_279 , V_145 ) ;
}
static void
V_276 ( struct V_134 * V_145 )
{
struct V_1 * V_2 = V_145 -> V_146 ;
struct V_170 * V_171 = V_145 -> V_175 ;
int V_164 ;
if ( V_171 -> V_283 > 0 && ! V_171 -> V_248 )
V_145 -> V_166 = V_171 -> V_283 ;
F_122 ( V_145 ) ;
V_164 = V_145 -> V_166 ;
if ( V_164 >= 0 ) {
V_145 -> V_160 = V_284 ;
return;
}
F_145 ( V_145 ) ;
V_145 -> V_166 = 0 ;
switch( V_164 ) {
case - V_268 :
case - V_269 :
case - V_270 :
F_127 ( V_145 , 3 * V_141 ) ;
case - V_227 :
V_145 -> V_160 = V_272 ;
if ( V_145 -> V_146 -> V_127 )
F_144 ( V_145 -> V_234 ,
V_171 -> V_281 ) ;
break;
case - V_266 :
case - V_265 :
F_115 ( V_2 ) ;
F_127 ( V_145 , 3 * V_141 ) ;
case - V_271 :
case - V_267 :
V_145 -> V_160 = V_235 ;
break;
case - V_223 :
V_145 -> V_160 = V_273 ;
break;
case - V_138 :
F_70 ( V_145 , V_164 ) ;
break;
default:
if ( V_2 -> V_129 )
F_20 ( L_50 ,
V_2 -> V_71 , - V_164 ) ;
F_70 ( V_145 , V_164 ) ;
}
}
static void
V_272 ( struct V_134 * V_145 )
{
struct V_1 * V_2 = V_145 -> V_146 ;
if ( F_146 ( V_145 -> V_175 ) == 0 ) {
F_38 ( L_51 , V_145 -> V_217 ) ;
goto V_285;
}
F_38 ( L_52 , V_145 -> V_217 ) ;
V_145 -> V_286 ++ ;
if ( F_136 ( V_145 ) ) {
F_70 ( V_145 , - V_227 ) ;
return;
}
if ( F_147 ( V_145 ) ) {
if ( V_2 -> V_129 )
F_62 () ;
F_20 ( V_280 L_53 ,
V_2 -> V_71 ,
F_64 ( V_2 -> V_66 ) -> V_58 ) ;
F_65 () ;
if ( V_145 -> V_136 & V_287 )
F_70 ( V_145 , - V_227 ) ;
else
F_70 ( V_145 , - V_138 ) ;
return;
}
if ( ! ( V_145 -> V_136 & V_288 ) ) {
V_145 -> V_136 |= V_288 ;
if ( V_2 -> V_129 ) {
F_62 () ;
F_20 ( V_280 L_54 ,
V_2 -> V_71 ,
F_64 ( V_2 -> V_66 ) -> V_58 ) ;
F_65 () ;
}
}
F_115 ( V_2 ) ;
F_148 ( V_145 ) ;
V_285:
V_2 -> V_76 -> V_289 ++ ;
V_145 -> V_160 = V_235 ;
V_145 -> V_166 = 0 ;
}
static void
V_284 ( struct V_134 * V_145 )
{
struct V_1 * V_2 = V_145 -> V_146 ;
struct V_170 * V_171 = V_145 -> V_175 ;
T_6 V_290 = V_145 -> V_151 . V_152 -> V_239 ;
T_5 * V_252 ;
F_122 ( V_145 ) ;
if ( V_145 -> V_136 & V_288 ) {
if ( V_2 -> V_129 ) {
F_62 () ;
F_20 ( V_280 L_55 ,
V_2 -> V_71 ,
F_64 ( V_2 -> V_66 ) -> V_58 ) ;
F_65 () ;
}
V_145 -> V_136 &= ~ V_288 ;
}
F_149 () ;
V_171 -> V_253 . V_24 = V_171 -> V_291 . V_24 ;
F_150 ( memcmp ( & V_171 -> V_253 , & V_171 -> V_291 ,
sizeof( V_171 -> V_253 ) ) != 0 ) ;
if ( V_171 -> V_253 . V_24 < 12 ) {
if ( ! F_147 ( V_145 ) ) {
V_145 -> V_160 = V_235 ;
V_2 -> V_76 -> V_289 ++ ;
goto V_292;
}
F_38 ( L_56 ,
V_2 -> V_71 , V_145 -> V_166 ) ;
V_145 -> V_160 = V_272 ;
goto V_292;
}
V_252 = F_151 ( V_145 ) ;
if ( F_18 ( V_252 ) ) {
if ( V_252 == F_55 ( - V_223 ) )
goto V_292;
return;
}
V_145 -> V_160 = V_278 ;
if ( V_290 ) {
V_145 -> V_166 = F_152 ( V_145 , V_290 , V_171 , V_252 ,
V_145 -> V_151 . V_154 ) ;
}
F_38 ( L_57 , V_145 -> V_217 ,
V_145 -> V_166 ) ;
return;
V_292:
V_145 -> V_166 = 0 ;
if ( V_145 -> V_175 == V_171 ) {
V_171 -> V_283 = V_171 -> V_253 . V_24 = 0 ;
if ( V_145 -> V_146 -> V_127 )
F_144 ( V_145 -> V_234 ,
V_171 -> V_281 ) ;
}
}
static T_5 *
F_133 ( struct V_134 * V_145 )
{
struct V_1 * V_2 = V_145 -> V_146 ;
struct V_170 * V_171 = V_145 -> V_175 ;
T_5 * V_252 = V_171 -> V_293 [ 0 ] . V_250 ;
V_252 = F_153 ( V_145 -> V_234 , V_252 ) ;
* V_252 ++ = V_171 -> V_294 ;
* V_252 ++ = F_154 ( V_295 ) ;
* V_252 ++ = F_154 ( V_296 ) ;
* V_252 ++ = F_154 ( V_2 -> V_72 ) ;
* V_252 ++ = F_154 ( V_2 -> V_75 ) ;
* V_252 ++ = F_154 ( V_145 -> V_151 . V_152 -> V_237 ) ;
V_252 = F_155 ( V_145 , V_252 ) ;
V_171 -> V_297 = F_156 ( & V_171 -> V_293 [ 0 ] , V_252 ) ;
return V_252 ;
}
static T_5 *
F_151 ( struct V_134 * V_145 )
{
struct V_1 * V_2 = V_145 -> V_146 ;
struct V_298 * V_299 = & V_145 -> V_175 -> V_253 . V_176 [ 0 ] ;
int V_24 = V_145 -> V_175 -> V_253 . V_24 >> 2 ;
T_5 * V_252 = V_299 -> V_250 ;
T_2 V_300 ;
int error = - V_228 ;
if ( ( V_145 -> V_175 -> V_253 . V_24 & 3 ) != 0 ) {
F_38 ( L_58
L_59 , V_145 -> V_217 , V_36 ,
V_145 -> V_175 -> V_253 . V_24 ) ;
goto V_301;
}
if ( ( V_24 -= 3 ) < 0 )
goto V_302;
V_252 += 1 ;
if ( ( V_300 = F_157 ( * V_252 ++ ) ) != V_303 ) {
F_38 ( L_60 ,
V_145 -> V_217 , V_36 , V_300 ) ;
goto V_304;
}
if ( ( V_300 = F_157 ( * V_252 ++ ) ) != V_305 ) {
if ( -- V_24 < 0 )
goto V_302;
switch ( ( V_300 = F_157 ( * V_252 ++ ) ) ) {
case V_306 :
break;
case V_307 :
F_38 ( L_61 ,
V_145 -> V_217 , V_36 ) ;
error = - V_264 ;
goto V_63;
default:
F_38 ( L_62
L_63 ,
V_145 -> V_217 , V_36 , V_300 ) ;
goto V_301;
}
if ( -- V_24 < 0 )
goto V_302;
switch ( ( V_300 = F_157 ( * V_252 ++ ) ) ) {
case V_308 :
case V_309 :
case V_310 :
case V_311 :
if ( ! V_145 -> V_229 )
break;
V_145 -> V_229 -- ;
F_38 ( L_64 ,
V_145 -> V_217 , V_36 ) ;
F_148 ( V_145 ) ;
F_124 ( V_145 ) ;
V_145 -> V_160 = V_220 ;
goto V_292;
case V_312 :
case V_313 :
if ( ! V_145 -> V_314 )
break;
V_145 -> V_314 -- ;
F_38 ( L_65 ,
V_145 -> V_217 , V_36 ) ;
V_145 -> V_160 = V_235 ;
goto V_292;
case V_315 :
F_62 () ;
F_20 ( V_280 L_66
L_67 ,
F_64 ( V_2 -> V_66 ) -> V_58 ) ;
F_65 () ;
break;
default:
F_38 ( L_68 ,
V_145 -> V_217 , V_36 , V_300 ) ;
error = - V_138 ;
}
F_38 ( L_69 ,
V_145 -> V_217 , V_36 , V_300 ) ;
goto V_63;
}
if ( ! ( V_252 = F_158 ( V_145 , V_252 ) ) ) {
F_38 ( L_70 ,
V_145 -> V_217 , V_36 ) ;
goto V_304;
}
V_24 = V_252 - ( T_5 * ) V_299 -> V_250 - 1 ;
if ( V_24 < 0 )
goto V_302;
switch ( ( V_300 = F_157 ( * V_252 ++ ) ) ) {
case V_316 :
return V_252 ;
case V_317 :
F_73 ( L_71
L_72 , V_145 -> V_217 , V_36 ,
( unsigned int ) V_2 -> V_72 ,
F_64 ( V_2 -> V_66 ) -> V_58 ) ;
error = - V_263 ;
goto V_63;
case V_318 :
F_73 ( L_73
L_72 , V_145 -> V_217 , V_36 ,
( unsigned int ) V_2 -> V_72 ,
( unsigned int ) V_2 -> V_75 ,
F_64 ( V_2 -> V_66 ) -> V_58 ) ;
error = - V_264 ;
goto V_63;
case V_319 :
F_73 ( L_74
L_75 ,
V_145 -> V_217 , V_36 ,
F_120 ( V_145 ) ,
V_2 -> V_72 , V_2 -> V_75 ,
F_64 ( V_2 -> V_66 ) -> V_58 ) ;
error = - V_261 ;
goto V_63;
case V_320 :
F_38 ( L_76 ,
V_145 -> V_217 , V_36 ) ;
break;
default:
F_38 ( L_77 ,
V_145 -> V_217 , V_36 , V_300 ) ;
}
V_304:
V_2 -> V_76 -> V_321 ++ ;
if ( V_145 -> V_314 ) {
V_145 -> V_314 -- ;
F_38 ( L_78 ,
V_145 -> V_217 , V_36 ) ;
V_145 -> V_160 = V_235 ;
V_292:
return F_55 ( - V_223 ) ;
}
V_301:
error = - V_138 ;
V_63:
F_70 ( V_145 , error ) ;
F_38 ( L_79 , V_145 -> V_217 ,
V_36 , error ) ;
return F_55 ( error ) ;
V_302:
F_38 ( L_80 , V_145 -> V_217 ,
V_36 ) ;
goto V_304;
}
static void F_159 ( void * V_322 , struct V_323 * V_324 , void * V_325 )
{
}
static int F_160 ( void * V_322 , struct V_323 * V_324 , void * V_325 )
{
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_149 V_150 = {
. V_152 = & V_326 ,
} ;
int V_31 ;
V_150 . V_155 = V_327 . V_328 ( NULL , NULL , 0 ) ;
V_31 = F_93 ( V_2 , & V_150 , V_148 | V_329 ) ;
F_161 ( V_150 . V_155 ) ;
return V_31 ;
}
struct V_134 * F_162 ( struct V_1 * V_2 , struct V_155 * V_330 , int V_120 )
{
struct V_149 V_150 = {
. V_152 = & V_326 ,
. V_155 = V_330 ,
} ;
struct V_157 V_158 = {
. V_159 = V_2 ,
. V_149 = & V_150 ,
. V_162 = & V_163 ,
. V_120 = V_120 ,
} ;
return F_89 ( & V_158 ) ;
}
static void F_163 ( void )
{
F_20 ( V_27 L_81
L_82 ) ;
}
static void F_164 ( const struct V_1 * V_2 ,
const struct V_134 * V_145 )
{
const char * V_331 = L_83 ;
if ( F_71 ( V_145 ) )
V_331 = F_165 ( V_145 -> V_139 ) ;
F_20 ( V_27 L_84 ,
V_145 -> V_217 , V_145 -> V_136 , V_145 -> V_166 ,
V_2 , V_145 -> V_175 , V_145 -> V_257 , V_145 -> V_168 ,
V_2 -> V_71 , V_2 -> V_75 , F_120 ( V_145 ) ,
V_145 -> V_160 , V_331 ) ;
}
void F_166 ( struct V_3 * V_3 )
{
struct V_1 * V_2 ;
struct V_134 * V_145 ;
int V_332 = 0 ;
struct V_4 * V_5 = F_3 ( V_3 , V_6 ) ;
F_4 ( & V_5 -> V_7 ) ;
F_28 (clnt, &sn->all_clients, cl_clients) {
F_4 ( & V_2 -> V_81 ) ;
F_28 (task, &clnt->cl_tasks, tk_task) {
if ( ! V_332 ) {
F_163 () ;
V_332 ++ ;
}
F_164 ( V_2 , V_145 ) ;
}
F_6 ( & V_2 -> V_81 ) ;
}
F_6 ( & V_5 -> V_7 ) ;
}
