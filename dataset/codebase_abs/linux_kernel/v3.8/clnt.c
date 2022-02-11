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
struct V_21 V_22 = { . V_20 = V_20 } ;
struct V_16 * V_23 , * V_16 ;
int error ;
V_23 = F_15 ( V_17 , V_18 ) ;
if ( V_23 == NULL ) {
F_16 ( L_1 , V_18 ) ;
return V_23 ;
}
for (; ; ) {
V_22 . V_24 = snprintf ( V_20 , sizeof( V_20 ) , L_2 , ( unsigned int ) V_19 ++ ) ;
V_20 [ sizeof( V_20 ) - 1 ] = '\0' ;
V_22 . V_25 = F_17 ( V_22 . V_20 , V_22 . V_24 ) ;
V_16 = F_18 ( V_23 , & V_22 , V_2 ) ;
if ( ! F_19 ( V_16 ) )
break;
error = F_20 ( V_16 ) ;
if ( error != - V_26 ) {
F_21 ( V_27 L_3
L_4 ,
V_18 , V_20 , error ) ;
break;
}
}
F_22 ( V_23 ) ;
return V_16 ;
}
static int
F_23 ( struct V_1 * V_2 , const char * V_18 )
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
if ( F_19 ( V_16 ) )
return F_20 ( V_16 ) ;
V_2 -> V_10 = V_16 ;
return 0 ;
}
static inline int F_24 ( struct V_1 * V_2 , unsigned long V_28 )
{
if ( ( ( V_28 == V_29 ) && V_2 -> V_10 ) ||
( ( V_28 == V_30 ) && ! V_2 -> V_10 ) )
return 1 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , unsigned long V_28 ,
struct V_14 * V_17 )
{
struct V_16 * V_16 ;
int V_31 = 0 ;
switch ( V_28 ) {
case V_29 :
V_16 = F_14 ( V_17 , V_2 ,
V_2 -> V_32 -> V_33 ) ;
if ( ! V_16 )
return - V_34 ;
if ( F_19 ( V_16 ) )
return F_20 ( V_16 ) ;
V_2 -> V_10 = V_16 ;
if ( V_2 -> V_11 -> V_12 -> V_35 ) {
V_31 = V_2 -> V_11 -> V_12 -> V_35 ( V_2 -> V_11 ) ;
if ( V_31 )
F_9 ( V_2 ) ;
}
break;
case V_30 :
F_9 ( V_2 ) ;
break;
default:
F_21 ( V_36 L_5 , V_37 , V_28 ) ;
return - V_38 ;
}
return V_31 ;
}
static int F_26 ( struct V_1 * V_2 , unsigned long V_28 ,
struct V_14 * V_17 )
{
int error = 0 ;
for (; ; V_2 = V_2 -> V_39 ) {
if ( ! F_24 ( V_2 , V_28 ) )
error = F_25 ( V_2 , V_28 , V_17 ) ;
if ( error || V_2 == V_2 -> V_39 )
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
continue;
if ( F_24 ( V_2 , V_28 ) )
continue;
if ( F_29 ( & V_2 -> V_40 ) == 0 )
continue;
F_6 ( & V_5 -> V_7 ) ;
return V_2 ;
}
F_6 ( & V_5 -> V_7 ) ;
return NULL ;
}
static int F_30 ( struct V_41 * V_42 , unsigned long V_28 ,
void * V_43 )
{
struct V_14 * V_17 = V_43 ;
struct V_1 * V_2 ;
int error = 0 ;
while ( ( V_2 = F_27 ( V_17 -> V_44 , V_28 ) ) ) {
error = F_26 ( V_2 , V_28 , V_17 ) ;
F_31 ( V_2 ) ;
if ( error )
break;
}
return error ;
}
int F_32 ( void )
{
return F_33 ( & V_45 ) ;
}
void F_34 ( void )
{
return F_35 ( & V_45 ) ;
}
static void F_36 ( struct V_1 * V_2 , const char * V_46 )
{
V_2 -> V_47 = strlen ( V_46 ) ;
if ( V_2 -> V_47 > V_48 )
V_2 -> V_47 = V_48 ;
memcpy ( V_2 -> V_49 , V_46 , V_2 -> V_47 ) ;
}
static struct V_1 * F_37 ( const struct V_50 * args , struct V_51 * V_52 )
{
const struct V_53 * V_54 = args -> V_54 ;
const struct V_55 * V_56 ;
struct V_1 * V_2 = NULL ;
struct V_57 * V_58 ;
int V_31 ;
F_38 ( L_6 ,
V_54 -> V_20 , args -> V_59 , V_52 ) ;
V_31 = F_39 () ;
if ( V_31 )
goto V_60;
V_31 = - V_61 ;
if ( ! V_52 )
goto V_62;
if ( args -> V_56 >= V_54 -> V_63 )
goto V_64;
V_56 = V_54 -> V_56 [ args -> V_56 ] ;
if ( V_56 == NULL )
goto V_64;
V_31 = - V_65 ;
V_2 = F_40 ( sizeof( * V_2 ) , V_66 ) ;
if ( ! V_2 )
goto V_64;
V_2 -> V_39 = V_2 ;
F_41 ( V_2 -> V_67 , V_52 ) ;
V_2 -> V_68 = V_56 -> V_69 ;
V_2 -> V_70 = V_56 -> V_71 ;
V_2 -> V_72 = V_54 -> V_20 ;
V_2 -> V_73 = args -> V_74 ? : V_54 -> V_75 ;
V_2 -> V_76 = V_56 -> V_75 ;
V_2 -> V_77 = V_54 -> V_78 ;
V_2 -> V_79 = F_42 ( V_2 ) ;
V_31 = - V_65 ;
if ( V_2 -> V_79 == NULL )
goto V_80;
V_2 -> V_32 = V_54 ;
F_43 ( & V_2 -> V_81 ) ;
F_44 ( & V_2 -> V_82 ) ;
if ( ! F_45 ( V_52 ) )
V_2 -> V_83 = 1 ;
V_2 -> V_84 = V_52 -> V_85 ;
if ( args -> V_85 != NULL ) {
memcpy ( & V_2 -> V_86 , args -> V_85 ,
sizeof( V_2 -> V_86 ) ) ;
V_2 -> V_84 = & V_2 -> V_86 ;
}
V_2 -> V_87 = & V_2 -> V_88 ;
F_46 ( & V_2 -> V_88 , V_2 -> V_84 -> V_89 ) ;
V_2 -> V_90 = NULL ;
if ( args -> V_91 ) {
V_2 -> V_90 = F_47 ( args -> V_91 , V_66 ) ;
if ( ! V_2 -> V_90 )
goto V_92;
}
F_48 ( & V_2 -> V_40 , 1 ) ;
V_31 = F_23 ( V_2 , V_54 -> V_33 ) ;
if ( V_31 < 0 )
goto V_93;
V_58 = F_49 ( args -> V_94 , V_2 ) ;
if ( F_19 ( V_58 ) ) {
F_21 ( V_27 L_7 ,
args -> V_94 ) ;
V_31 = F_20 ( V_58 ) ;
goto V_95;
}
F_36 ( V_2 , F_50 () -> V_46 ) ;
F_1 ( V_2 ) ;
return V_2 ;
V_95:
F_11 ( V_2 ) ;
V_93:
F_51 ( V_2 -> V_90 ) ;
V_92:
F_52 ( V_2 -> V_79 ) ;
V_80:
F_51 ( V_2 ) ;
V_64:
F_53 ( V_52 ) ;
V_62:
F_54 () ;
V_60:
return F_55 ( V_31 ) ;
}
struct V_1 * F_56 ( struct V_50 * args )
{
struct V_51 * V_52 ;
struct V_1 * V_2 ;
struct V_96 V_97 = {
. V_3 = args -> V_3 ,
. V_98 = args -> V_99 ,
. V_100 = args -> V_101 ,
. V_102 = args -> V_103 ,
. V_104 = args -> V_105 ,
. V_59 = args -> V_59 ,
. V_106 = args -> V_106 ,
} ;
char V_59 [ 48 ] ;
if ( V_97 . V_59 == NULL ) {
struct V_107 * V_108 =
(struct V_107 * ) args -> V_103 ;
struct V_109 * sin =
(struct V_109 * ) args -> V_103 ;
struct V_110 * V_111 =
(struct V_110 * ) args -> V_103 ;
V_59 [ 0 ] = '\0' ;
switch ( args -> V_103 -> V_112 ) {
case V_113 :
snprintf ( V_59 , sizeof( V_59 ) , L_8 ,
V_108 -> V_114 ) ;
break;
case V_115 :
snprintf ( V_59 , sizeof( V_59 ) , L_9 ,
& sin -> V_116 . V_117 ) ;
break;
case V_118 :
snprintf ( V_59 , sizeof( V_59 ) , L_10 ,
& V_111 -> V_119 ) ;
break;
default:
return F_55 ( - V_61 ) ;
}
V_97 . V_59 = V_59 ;
}
V_52 = F_57 ( & V_97 ) ;
if ( F_19 ( V_52 ) )
return (struct V_1 * ) V_52 ;
V_52 -> V_120 = 1 ;
if ( args -> V_121 & V_122 )
V_52 -> V_120 = 0 ;
V_2 = F_37 ( args , V_52 ) ;
if ( F_19 ( V_2 ) )
return V_2 ;
if ( ! ( args -> V_121 & V_123 ) ) {
int V_31 = F_58 ( V_2 ) ;
if ( V_31 != 0 ) {
F_59 ( V_2 ) ;
return F_55 ( V_31 ) ;
}
}
V_2 -> V_124 = 1 ;
if ( args -> V_121 & V_125 )
V_2 -> V_124 = 0 ;
if ( args -> V_121 & V_126 )
V_2 -> V_83 = 1 ;
if ( args -> V_121 & V_127 )
V_2 -> V_128 = 1 ;
if ( ! ( args -> V_121 & V_129 ) )
V_2 -> V_130 = 1 ;
return V_2 ;
}
static struct V_1 * F_60 ( struct V_50 * args ,
struct V_1 * V_2 )
{
struct V_51 * V_52 ;
struct V_1 * V_131 ;
int V_31 ;
V_31 = - V_65 ;
F_61 () ;
V_52 = F_62 ( F_63 ( V_2 -> V_67 ) ) ;
F_64 () ;
if ( V_52 == NULL )
goto V_64;
args -> V_59 = V_52 -> V_59 ;
V_131 = F_37 ( args , V_52 ) ;
if ( F_19 ( V_131 ) ) {
V_31 = F_20 ( V_131 ) ;
goto V_132;
}
F_65 ( & V_2 -> V_40 ) ;
V_131 -> V_39 = V_2 ;
V_131 -> V_83 = 0 ;
V_131 -> V_124 = V_2 -> V_124 ;
V_131 -> V_128 = V_2 -> V_128 ;
V_131 -> V_130 = V_2 -> V_130 ;
return V_131 ;
V_132:
F_53 ( V_52 ) ;
V_64:
F_38 ( L_11 , V_37 , V_31 ) ;
return F_55 ( V_31 ) ;
}
struct V_1 * F_66 ( struct V_1 * V_2 )
{
struct V_50 args = {
. V_54 = V_2 -> V_32 ,
. V_74 = V_2 -> V_73 ,
. V_56 = V_2 -> V_76 ,
. V_94 = V_2 -> V_11 -> V_133 ,
. V_91 = V_2 -> V_90 ,
} ;
return F_60 ( & args , V_2 ) ;
}
struct V_1 *
F_67 ( struct V_1 * V_2 , T_2 V_134 )
{
struct V_50 args = {
. V_54 = V_2 -> V_32 ,
. V_74 = V_2 -> V_73 ,
. V_56 = V_2 -> V_76 ,
. V_94 = V_134 ,
. V_91 = V_2 -> V_90 ,
} ;
return F_60 ( & args , V_2 ) ;
}
void F_68 ( struct V_1 * V_2 )
{
struct V_135 * V_136 ;
if ( F_69 ( & V_2 -> V_81 ) )
return;
F_38 ( L_12 , V_2 ) ;
F_4 ( & V_2 -> V_82 ) ;
F_28 (rovr, &clnt->cl_tasks, tk_task) {
if ( ! F_70 ( V_136 ) )
continue;
if ( ! ( V_136 -> V_137 & V_138 ) ) {
V_136 -> V_137 |= V_138 ;
F_71 ( V_136 , - V_139 ) ;
if ( F_72 ( V_136 ) )
F_73 ( V_136 -> V_140 ,
V_136 ) ;
}
}
F_6 ( & V_2 -> V_82 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
F_74 () ;
F_75 ( L_13 ,
V_2 -> V_72 ,
F_63 ( V_2 -> V_67 ) -> V_59 ) ;
while ( ! F_69 ( & V_2 -> V_81 ) ) {
F_68 ( V_2 ) ;
F_76 ( V_141 ,
F_69 ( & V_2 -> V_81 ) , 1 * V_142 ) ;
}
F_31 ( V_2 ) ;
}
static void
F_77 ( struct V_1 * V_2 )
{
F_75 ( L_14 ,
V_2 -> V_72 ,
F_63 ( V_2 -> V_67 ) -> V_59 ) ;
if ( V_2 -> V_39 != V_2 )
F_31 ( V_2 -> V_39 ) ;
F_7 ( V_2 ) ;
F_11 ( V_2 ) ;
F_52 ( V_2 -> V_79 ) ;
F_51 ( V_2 -> V_90 ) ;
V_2 -> V_79 = NULL ;
F_53 ( F_78 ( V_2 -> V_67 ) ) ;
F_54 () ;
F_51 ( V_2 ) ;
}
static void
F_79 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 == NULL ) {
F_77 ( V_2 ) ;
return;
}
F_65 ( & V_2 -> V_40 ) ;
F_80 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
if ( F_81 ( & V_2 -> V_40 ) )
F_77 ( V_2 ) ;
}
void
F_31 ( struct V_1 * V_2 )
{
F_38 ( L_15 , V_2 ) ;
if ( F_69 ( & V_2 -> V_81 ) )
F_82 ( & V_141 ) ;
if ( F_81 ( & V_2 -> V_40 ) )
F_79 ( V_2 ) ;
}
struct V_1 * F_83 ( struct V_1 * V_143 ,
const struct V_53 * V_54 ,
T_3 V_144 )
{
struct V_50 args = {
. V_54 = V_54 ,
. V_74 = V_54 -> V_75 ,
. V_56 = V_144 ,
. V_94 = V_143 -> V_11 -> V_133 ,
. V_91 = V_143 -> V_90 ,
} ;
struct V_1 * V_2 ;
int V_31 ;
V_2 = F_60 ( & args , V_143 ) ;
if ( F_19 ( V_2 ) )
goto V_145;
V_31 = F_58 ( V_2 ) ;
if ( V_31 != 0 ) {
F_59 ( V_2 ) ;
V_2 = F_55 ( V_31 ) ;
}
V_145:
return V_2 ;
}
void F_84 ( struct V_135 * V_146 )
{
struct V_1 * V_2 = V_146 -> V_147 ;
if ( V_2 != NULL ) {
F_4 ( & V_2 -> V_82 ) ;
F_8 ( & V_146 -> V_148 ) ;
F_6 ( & V_2 -> V_82 ) ;
V_146 -> V_147 = NULL ;
F_31 ( V_2 ) ;
}
}
static
void F_85 ( struct V_135 * V_146 , struct V_1 * V_2 )
{
if ( V_2 != NULL ) {
F_84 ( V_146 ) ;
V_146 -> V_147 = V_2 ;
F_65 ( & V_2 -> V_40 ) ;
if ( V_2 -> V_124 )
V_146 -> V_137 |= V_149 ;
if ( F_86 () ) {
struct V_51 * V_52 ;
F_61 () ;
V_52 = F_63 ( V_2 -> V_67 ) ;
if ( V_52 -> V_150 )
V_146 -> V_137 |= V_151 ;
F_64 () ;
}
F_4 ( & V_2 -> V_82 ) ;
F_87 ( & V_146 -> V_148 , & V_2 -> V_81 ) ;
F_6 ( & V_2 -> V_82 ) ;
}
}
void F_88 ( struct V_135 * V_146 , struct V_1 * V_2 )
{
F_84 ( V_146 ) ;
F_85 ( V_146 , V_2 ) ;
}
static void
F_89 ( struct V_135 * V_146 , const struct V_152 * V_153 )
{
if ( V_153 != NULL ) {
V_146 -> V_154 . V_155 = V_153 -> V_155 ;
V_146 -> V_154 . V_156 = V_153 -> V_156 ;
V_146 -> V_154 . V_157 = V_153 -> V_157 ;
if ( V_153 -> V_158 != NULL )
V_146 -> V_154 . V_158 = F_90 ( V_153 -> V_158 ) ;
}
}
static void
F_91 ( struct V_135 * V_146 , void * V_159 )
{
}
struct V_135 * F_92 ( const struct V_160 * V_161 )
{
struct V_135 * V_146 ;
V_146 = F_93 ( V_161 ) ;
if ( F_19 ( V_146 ) )
goto V_145;
F_85 ( V_146 , V_161 -> V_162 ) ;
F_89 ( V_146 , V_161 -> V_152 ) ;
if ( V_146 -> V_163 == NULL )
F_94 ( V_146 ) ;
F_65 ( & V_146 -> V_164 ) ;
F_95 ( V_146 ) ;
V_145:
return V_146 ;
}
int F_96 ( struct V_1 * V_2 , const struct V_152 * V_153 , int V_121 )
{
struct V_135 * V_146 ;
struct V_160 V_161 = {
. V_162 = V_2 ,
. V_152 = V_153 ,
. V_165 = & V_166 ,
. V_121 = V_121 ,
} ;
int V_167 ;
F_97 ( V_121 & V_168 ) ;
if ( V_121 & V_168 ) {
F_98 ( V_161 . V_165 ,
V_161 . V_169 ) ;
return - V_61 ;
}
V_146 = F_92 ( & V_161 ) ;
if ( F_19 ( V_146 ) )
return F_20 ( V_146 ) ;
V_167 = V_146 -> V_170 ;
F_99 ( V_146 ) ;
return V_167 ;
}
int
F_100 ( struct V_1 * V_2 , const struct V_152 * V_153 , int V_121 ,
const struct V_171 * V_172 , void * V_159 )
{
struct V_135 * V_146 ;
struct V_160 V_161 = {
. V_162 = V_2 ,
. V_152 = V_153 ,
. V_165 = V_172 ,
. V_169 = V_159 ,
. V_121 = V_121 | V_168 ,
} ;
V_146 = F_92 ( & V_161 ) ;
if ( F_19 ( V_146 ) )
return F_20 ( V_146 ) ;
F_99 ( V_146 ) ;
return 0 ;
}
struct V_135 * F_101 ( struct V_173 * V_174 ,
const struct V_171 * V_172 )
{
struct V_135 * V_146 ;
struct V_175 * V_176 = & V_174 -> V_177 ;
struct V_160 V_161 = {
. V_165 = V_172 ,
} ;
F_38 ( L_16 , V_174 ) ;
V_146 = F_93 ( & V_161 ) ;
if ( F_19 ( V_146 ) ) {
F_102 ( V_174 ) ;
goto V_145;
}
V_146 -> V_178 = V_174 ;
V_176 -> V_24 = V_176 -> V_179 [ 0 ] . V_180 + V_176 -> V_181 +
V_176 -> V_182 [ 0 ] . V_180 ;
V_146 -> V_163 = V_183 ;
F_65 ( & V_146 -> V_164 ) ;
F_97 ( F_103 ( & V_146 -> V_164 ) != 2 ) ;
F_95 ( V_146 ) ;
V_145:
F_38 ( L_17 , V_146 ) ;
return V_146 ;
}
void
F_94 ( struct V_135 * V_146 )
{
V_146 -> V_163 = V_184 ;
}
T_4 F_104 ( struct V_1 * V_2 , struct V_185 * V_186 , T_4 V_187 )
{
T_4 V_188 ;
struct V_51 * V_52 ;
F_61 () ;
V_52 = F_63 ( V_2 -> V_67 ) ;
V_188 = V_52 -> V_104 ;
if ( V_188 > V_187 )
V_188 = V_187 ;
memcpy ( V_186 , & V_52 -> V_189 , V_188 ) ;
F_64 () ;
return V_188 ;
}
const char * F_105 ( struct V_1 * V_2 ,
enum V_190 V_191 )
{
struct V_51 * V_52 ;
V_52 = F_63 ( V_2 -> V_67 ) ;
if ( V_52 -> V_192 [ V_191 ] != NULL )
return V_52 -> V_192 [ V_191 ] ;
else
return L_18 ;
}
static int F_106 ( struct V_3 * V_3 , struct V_185 * V_193 , T_4 V_194 ,
struct V_185 * V_186 , int V_195 )
{
struct V_196 * V_197 ;
int V_31 ;
V_31 = F_107 ( V_3 , V_193 -> V_112 ,
V_198 , V_199 , & V_197 , 1 ) ;
if ( V_31 < 0 ) {
F_38 ( L_19 , V_31 ) ;
goto V_145;
}
switch ( V_193 -> V_112 ) {
case V_115 :
V_31 = F_108 ( V_197 ,
(struct V_185 * ) & V_200 ,
sizeof( V_200 ) ) ;
break;
case V_118 :
V_31 = F_108 ( V_197 ,
(struct V_185 * ) & V_201 ,
sizeof( V_201 ) ) ;
break;
default:
V_31 = - V_202 ;
goto V_145;
}
if ( V_31 < 0 ) {
F_38 ( L_20 , V_31 ) ;
goto V_203;
}
V_31 = F_109 ( V_197 , V_193 , V_194 , 0 ) ;
if ( V_31 < 0 ) {
F_38 ( L_21 , V_31 ) ;
goto V_203;
}
V_31 = F_110 ( V_197 , V_186 , & V_195 ) ;
if ( V_31 < 0 ) {
F_38 ( L_22 , V_31 ) ;
goto V_203;
}
V_31 = 0 ;
if ( V_186 -> V_112 == V_118 ) {
struct V_110 * V_111 = (struct V_110 * ) V_186 ;
V_111 -> V_204 = 0 ;
}
F_38 ( L_23 , V_37 ) ;
V_203:
F_111 ( V_197 ) ;
V_145:
return V_31 ;
}
static int F_112 ( int V_205 , struct V_185 * V_186 , T_4 V_195 )
{
switch ( V_205 ) {
case V_115 :
if ( V_195 < sizeof( V_200 ) )
return - V_61 ;
memcpy ( V_186 , & V_200 ,
sizeof( V_200 ) ) ;
break;
case V_118 :
if ( V_195 < sizeof( V_201 ) )
return - V_61 ;
memcpy ( V_186 , & V_201 ,
sizeof( V_201 ) ) ;
default:
F_38 ( L_24 ,
V_37 ) ;
return - V_202 ;
}
F_38 ( L_25 , V_37 ) ;
return 0 ;
}
int F_113 ( struct V_1 * V_2 , struct V_185 * V_186 , T_4 V_195 )
{
struct V_206 V_103 ;
struct V_185 * V_193 = (struct V_185 * ) & V_103 ;
struct V_51 * V_52 ;
struct V_3 * V_3 ;
T_4 V_194 ;
int V_31 ;
F_61 () ;
V_52 = F_63 ( V_2 -> V_67 ) ;
V_194 = V_52 -> V_104 ;
memcpy ( V_193 , & V_52 -> V_189 , V_194 ) ;
V_3 = F_114 ( V_52 -> V_207 ) ;
F_64 () ;
F_115 ( V_193 , 0 ) ;
V_31 = F_106 ( V_3 , V_193 , V_194 , V_186 , V_195 ) ;
F_116 ( V_3 ) ;
if ( V_31 != 0 )
return F_112 ( V_193 -> V_112 , V_186 , V_195 ) ;
return 0 ;
}
void
F_117 ( struct V_1 * V_2 , unsigned int V_208 , unsigned int V_209 )
{
struct V_51 * V_52 ;
F_61 () ;
V_52 = F_63 ( V_2 -> V_67 ) ;
if ( V_52 -> V_210 -> V_211 )
V_52 -> V_210 -> V_211 ( V_52 , V_208 , V_209 ) ;
F_64 () ;
}
int F_118 ( struct V_1 * V_2 )
{
int V_99 ;
F_61 () ;
V_99 = F_63 ( V_2 -> V_67 ) -> V_212 ;
F_64 () ;
return V_99 ;
}
struct V_3 * F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_213 ;
F_61 () ;
V_213 = F_63 ( V_2 -> V_67 ) -> V_207 ;
F_64 () ;
return V_213 ;
}
T_4 F_119 ( struct V_1 * V_2 )
{
T_4 V_213 ;
F_61 () ;
V_213 = F_63 ( V_2 -> V_67 ) -> V_214 ;
F_64 () ;
return V_213 ;
}
void F_120 ( struct V_1 * V_2 )
{
if ( V_2 -> V_83 ) {
F_61 () ;
F_121 ( F_63 ( V_2 -> V_67 ) ) ;
F_64 () ;
}
}
int
F_122 ( struct V_135 * V_146 )
{
if ( F_123 ( V_146 ) )
return 0 ;
V_146 -> V_163 = V_184 ;
if ( V_146 -> V_172 -> V_215 != NULL )
V_146 -> V_163 = V_216 ;
return 1 ;
}
int
F_124 ( struct V_135 * V_146 )
{
if ( F_123 ( V_146 ) )
return 0 ;
V_146 -> V_163 = V_184 ;
return 1 ;
}
static const char * F_125 ( const struct V_135 * V_146 )
{
const struct V_217 * V_218 = V_146 -> V_154 . V_155 ;
if ( V_218 ) {
if ( V_218 -> V_219 )
return V_218 -> V_219 ;
else
return L_26 ;
} else
return L_27 ;
}
static void
V_184 ( struct V_135 * V_146 )
{
struct V_1 * V_2 = V_146 -> V_147 ;
F_38 ( L_28 , V_146 -> V_220 ,
V_2 -> V_72 , V_2 -> V_76 ,
F_125 ( V_146 ) ,
( F_126 ( V_146 ) ? L_29 : L_30 ) ) ;
V_146 -> V_154 . V_155 -> V_221 ++ ;
V_2 -> V_77 -> V_222 ++ ;
V_146 -> V_163 = V_223 ;
}
static void
V_223 ( struct V_135 * V_146 )
{
F_127 ( V_146 ) ;
V_146 -> V_170 = 0 ;
V_146 -> V_163 = V_224 ;
F_128 ( V_146 ) ;
}
static void
V_224 ( struct V_135 * V_146 )
{
int V_167 = V_146 -> V_170 ;
F_127 ( V_146 ) ;
V_146 -> V_170 = 0 ;
if ( V_167 >= 0 ) {
if ( V_146 -> V_178 ) {
V_146 -> V_163 = V_225 ;
return;
}
F_21 ( V_36 L_31 ,
V_37 , V_167 ) ;
F_71 ( V_146 , - V_139 ) ;
return;
}
if ( V_146 -> V_178 ) {
F_21 ( V_36 L_32 ,
V_37 , V_167 ) ;
F_129 ( V_146 ) ;
}
switch ( V_167 ) {
case - V_65 :
F_130 ( V_146 , V_142 >> 2 ) ;
case - V_226 :
V_146 -> V_163 = V_223 ;
return;
case - V_139 :
break;
default:
F_21 ( V_36 L_33 ,
V_37 , V_167 ) ;
break;
}
F_71 ( V_146 , V_167 ) ;
}
static void
V_225 ( struct V_135 * V_146 )
{
F_127 ( V_146 ) ;
V_146 -> V_163 = V_227 ;
V_146 -> V_170 = 0 ;
V_146 -> V_147 -> V_77 -> V_228 ++ ;
F_131 ( V_146 ) ;
}
static void
V_227 ( struct V_135 * V_146 )
{
int V_167 = V_146 -> V_170 ;
F_127 ( V_146 ) ;
V_146 -> V_170 = 0 ;
V_146 -> V_163 = V_225 ;
switch ( V_167 ) {
case 0 :
if ( F_132 ( V_146 ) )
V_146 -> V_163 = V_229 ;
return;
case - V_230 :
F_130 ( V_146 , 3 * V_142 ) ;
case - V_231 :
case - V_226 :
V_167 = - V_232 ;
if ( ! V_146 -> V_233 )
break;
V_146 -> V_233 -- ;
F_38 ( L_34 ,
V_146 -> V_220 , V_37 ) ;
return;
}
F_38 ( L_35 ,
V_146 -> V_220 , V_37 , V_167 ) ;
F_71 ( V_146 , V_167 ) ;
}
static void
V_229 ( struct V_135 * V_146 )
{
unsigned int V_234 = V_146 -> V_178 -> V_235 -> V_236 -> V_237 ;
struct V_173 * V_174 = V_146 -> V_178 ;
struct V_51 * V_52 = V_146 -> V_238 ;
struct V_217 * V_218 = V_146 -> V_154 . V_155 ;
F_127 ( V_146 ) ;
V_146 -> V_170 = 0 ;
V_146 -> V_163 = V_239 ;
if ( V_174 -> V_240 )
return;
if ( V_218 -> V_241 != 0 ) {
F_133 ( V_218 -> V_242 == 0 ) ;
if ( V_218 -> V_243 != NULL )
F_133 ( V_218 -> V_244 == 0 ) ;
}
V_174 -> V_245 = V_246 + ( V_234 << 1 ) + V_218 -> V_242 ;
V_174 -> V_245 <<= 2 ;
V_174 -> V_247 = V_248 + V_234 + V_218 -> V_244 ;
V_174 -> V_247 <<= 2 ;
V_174 -> V_240 = V_52 -> V_210 -> V_249 ( V_146 ,
V_174 -> V_245 + V_174 -> V_247 ) ;
if ( V_174 -> V_240 != NULL )
return;
F_38 ( L_36 , V_146 -> V_220 ) ;
if ( F_126 ( V_146 ) || ! F_134 ( V_250 ) ) {
V_146 -> V_163 = V_229 ;
F_130 ( V_146 , V_142 >> 4 ) ;
return;
}
F_71 ( V_146 , - V_251 ) ;
}
static inline int
F_135 ( struct V_135 * V_146 )
{
return V_146 -> V_178 -> V_177 . V_24 == 0 ;
}
static inline void
F_136 ( struct V_135 * V_146 )
{
V_146 -> V_178 -> V_177 . V_24 = 0 ;
V_146 -> V_178 -> V_252 = 0 ;
}
static inline void
F_137 ( struct V_175 * V_186 , void * V_253 , T_4 V_24 )
{
V_186 -> V_179 [ 0 ] . V_254 = V_253 ;
V_186 -> V_179 [ 0 ] . V_180 = V_24 ;
V_186 -> V_182 [ 0 ] . V_180 = 0 ;
V_186 -> V_181 = 0 ;
V_186 -> V_121 = 0 ;
V_186 -> V_24 = 0 ;
V_186 -> V_195 = V_24 ;
}
static void
F_138 ( struct V_135 * V_146 )
{
struct V_173 * V_174 = V_146 -> V_178 ;
T_5 V_255 ;
T_6 * V_256 ;
F_127 ( V_146 ) ;
F_137 ( & V_174 -> V_177 ,
V_174 -> V_240 ,
V_174 -> V_245 ) ;
F_137 ( & V_174 -> V_257 ,
( char * ) V_174 -> V_240 + V_174 -> V_245 ,
V_174 -> V_247 ) ;
V_256 = F_139 ( V_146 ) ;
if ( V_256 == NULL ) {
F_21 ( V_27 L_37 ) ;
F_71 ( V_146 , - V_139 ) ;
return;
}
V_255 = V_146 -> V_154 . V_155 -> V_258 ;
if ( V_255 == NULL )
return;
V_146 -> V_170 = F_140 ( V_146 , V_255 , V_174 , V_256 ,
V_146 -> V_154 . V_156 ) ;
}
static void
V_239 ( struct V_135 * V_146 )
{
struct V_51 * V_52 = V_146 -> V_238 ;
F_127 ( V_146 ) ;
V_146 -> V_163 = V_259 ;
if ( ! F_45 ( V_52 ) ) {
V_146 -> V_163 = V_260 ;
V_146 -> V_261 = V_52 -> V_262 ;
V_52 -> V_210 -> V_263 ( V_146 ) ;
}
}
static void
V_260 ( struct V_135 * V_146 )
{
int V_167 = - V_139 ;
if ( V_146 -> V_170 >= 0 ) {
F_127 ( V_146 ) ;
V_146 -> V_170 = 0 ;
V_146 -> V_163 = V_259 ;
return;
}
F_141 ( V_146 ) ;
switch ( V_146 -> V_170 ) {
case - V_65 :
F_38 ( L_38 , V_146 -> V_220 ) ;
F_130 ( V_146 , V_142 >> 2 ) ;
goto V_264;
case - V_232 :
F_38 ( L_39
L_40 , V_146 -> V_220 ) ;
if ( V_146 -> V_154 . V_155 -> V_241 == 0 ) {
V_167 = - V_265 ;
break;
}
if ( V_146 -> V_266 == 0 )
break;
V_146 -> V_266 -- ;
F_130 ( V_146 , 3 * V_142 ) ;
goto V_264;
case - V_230 :
F_38 ( L_41 ,
V_146 -> V_220 ) ;
goto V_264;
case - V_267 :
F_38 ( L_42 ,
V_146 -> V_220 ) ;
break;
case - V_268 :
F_38 ( L_43 ,
V_146 -> V_220 ) ;
V_146 -> V_170 = 0 ;
V_146 -> V_163 = V_239 ;
return;
case - V_269 :
case - V_270 :
case - V_271 :
case - V_272 :
case - V_273 :
case - V_274 :
case - V_275 :
F_38 ( L_44 ,
V_146 -> V_220 , V_146 -> V_170 ) ;
if ( ! F_142 ( V_146 ) ) {
F_130 ( V_146 , 5 * V_142 ) ;
goto V_264;
}
V_167 = V_146 -> V_170 ;
break;
default:
F_38 ( L_45 ,
V_146 -> V_220 , - V_146 -> V_170 ) ;
}
F_71 ( V_146 , V_167 ) ;
return;
V_264:
V_146 -> V_163 = V_276 ;
}
static void
V_259 ( struct V_135 * V_146 )
{
struct V_51 * V_52 = V_146 -> V_238 ;
F_38 ( L_46 ,
V_146 -> V_220 , V_52 ,
( F_143 ( V_52 ) ? L_47 : L_48 ) ) ;
V_146 -> V_163 = V_277 ;
if ( ! F_143 ( V_52 ) ) {
V_146 -> V_163 = V_278 ;
if ( V_146 -> V_170 < 0 )
return;
F_144 ( V_146 ) ;
}
}
static void
V_278 ( struct V_135 * V_146 )
{
struct V_1 * V_2 = V_146 -> V_147 ;
int V_167 = V_146 -> V_170 ;
F_127 ( V_146 ) ;
V_146 -> V_170 = 0 ;
if ( V_167 >= 0 || V_167 == - V_226 ) {
V_2 -> V_77 -> V_279 ++ ;
V_146 -> V_163 = V_277 ;
return;
}
F_145 ( V_146 , V_167 ) ;
switch ( V_167 ) {
case - V_230 :
V_146 -> V_163 = V_276 ;
break;
default:
F_71 ( V_146 , - V_139 ) ;
}
}
static void
V_277 ( struct V_135 * V_146 )
{
F_127 ( V_146 ) ;
V_146 -> V_163 = V_280 ;
if ( V_146 -> V_170 < 0 )
return;
V_146 -> V_170 = F_146 ( V_146 ) ;
if ( V_146 -> V_170 != 0 )
return;
V_146 -> V_163 = V_281 ;
if ( F_135 ( V_146 ) ) {
F_138 ( V_146 ) ;
if ( V_146 -> V_170 != 0 ) {
if ( V_146 -> V_170 == - V_226 )
F_130 ( V_146 , V_142 >> 4 ) ;
else
F_71 ( V_146 , V_146 -> V_170 ) ;
return;
}
}
F_147 ( V_146 ) ;
if ( V_146 -> V_170 < 0 )
return;
V_281 ( V_146 ) ;
if ( F_148 ( V_146 ) )
return;
V_146 -> V_163 = V_282 ;
F_73 ( & V_146 -> V_238 -> V_283 , V_146 ) ;
}
static void
V_281 ( struct V_135 * V_146 )
{
V_146 -> V_163 = V_280 ;
if ( V_146 -> V_170 == 0 ) {
F_149 ( V_146 ) ;
F_136 ( V_146 ) ;
return;
}
switch ( V_146 -> V_170 ) {
case - V_226 :
break;
default:
F_127 ( V_146 ) ;
F_149 ( V_146 ) ;
F_136 ( V_146 ) ;
break;
case - V_269 :
case - V_272 :
case - V_273 :
case - V_274 :
if ( F_142 ( V_146 ) ) {
F_149 ( V_146 ) ;
F_71 ( V_146 , V_146 -> V_170 ) ;
break;
}
case - V_270 :
case - V_271 :
case - V_275 :
F_136 ( V_146 ) ;
}
}
static void
V_183 ( struct V_135 * V_146 )
{
struct V_173 * V_174 = V_146 -> V_178 ;
V_146 -> V_170 = F_146 ( V_146 ) ;
if ( V_146 -> V_170 == - V_226 ) {
V_146 -> V_170 = 0 ;
V_146 -> V_163 = V_183 ;
return;
}
V_146 -> V_163 = V_282 ;
if ( V_146 -> V_170 < 0 ) {
F_21 ( V_284 L_49
L_50 , V_146 -> V_170 ) ;
return;
}
F_147 ( V_146 ) ;
F_149 ( V_146 ) ;
F_127 ( V_146 ) ;
switch ( V_146 -> V_170 ) {
case 0 :
break;
case - V_272 :
case - V_273 :
case - V_274 :
case - V_230 :
F_21 ( V_284 L_49
L_50 , V_146 -> V_170 ) ;
F_150 ( V_146 -> V_238 ,
V_174 -> V_285 ) ;
break;
default:
F_97 ( V_146 -> V_170 == - V_226 ) ;
F_21 ( V_284 L_49
L_50 , V_146 -> V_170 ) ;
break;
}
F_73 ( & V_174 -> V_286 -> V_283 , V_146 ) ;
}
static void
V_280 ( struct V_135 * V_146 )
{
struct V_1 * V_2 = V_146 -> V_147 ;
struct V_173 * V_174 = V_146 -> V_178 ;
int V_167 ;
if ( V_174 -> V_287 > 0 && ! V_174 -> V_252 )
V_146 -> V_170 = V_174 -> V_287 ;
F_127 ( V_146 ) ;
V_167 = V_146 -> V_170 ;
if ( V_167 >= 0 ) {
V_146 -> V_163 = V_288 ;
return;
}
F_151 ( V_146 ) ;
V_146 -> V_170 = 0 ;
switch( V_167 ) {
case - V_272 :
case - V_273 :
case - V_274 :
F_130 ( V_146 , 3 * V_142 ) ;
case - V_230 :
V_146 -> V_163 = V_276 ;
if ( V_146 -> V_147 -> V_128 )
F_150 ( V_146 -> V_238 ,
V_174 -> V_285 ) ;
break;
case - V_270 :
case - V_269 :
F_120 ( V_2 ) ;
F_130 ( V_146 , 3 * V_142 ) ;
case - V_275 :
case - V_271 :
V_146 -> V_163 = V_239 ;
break;
case - V_226 :
V_146 -> V_163 = V_277 ;
break;
case - V_139 :
F_71 ( V_146 , V_167 ) ;
break;
default:
if ( V_2 -> V_130 )
F_21 ( L_51 ,
V_2 -> V_72 , - V_167 ) ;
F_71 ( V_146 , V_167 ) ;
}
}
static void
V_276 ( struct V_135 * V_146 )
{
struct V_1 * V_2 = V_146 -> V_147 ;
if ( F_152 ( V_146 -> V_178 ) == 0 ) {
F_38 ( L_52 , V_146 -> V_220 ) ;
goto V_289;
}
F_38 ( L_53 , V_146 -> V_220 ) ;
V_146 -> V_290 ++ ;
if ( F_142 ( V_146 ) ) {
F_71 ( V_146 , - V_230 ) ;
return;
}
if ( F_153 ( V_146 ) ) {
if ( V_2 -> V_130 ) {
F_61 () ;
F_21 ( V_284 L_54 ,
V_2 -> V_72 ,
F_63 ( V_2 -> V_67 ) -> V_59 ) ;
F_64 () ;
}
if ( V_146 -> V_137 & V_291 )
F_71 ( V_146 , - V_230 ) ;
else
F_71 ( V_146 , - V_139 ) ;
return;
}
if ( ! ( V_146 -> V_137 & V_292 ) ) {
V_146 -> V_137 |= V_292 ;
if ( V_2 -> V_130 ) {
F_61 () ;
F_21 ( V_284 L_55 ,
V_2 -> V_72 ,
F_63 ( V_2 -> V_67 ) -> V_59 ) ;
F_64 () ;
}
}
F_120 ( V_2 ) ;
F_154 ( V_146 ) ;
V_289:
V_2 -> V_77 -> V_293 ++ ;
V_146 -> V_163 = V_239 ;
V_146 -> V_170 = 0 ;
}
static void
V_288 ( struct V_135 * V_146 )
{
struct V_1 * V_2 = V_146 -> V_147 ;
struct V_173 * V_174 = V_146 -> V_178 ;
T_7 V_294 = V_146 -> V_154 . V_155 -> V_243 ;
T_6 * V_256 ;
F_127 ( V_146 ) ;
if ( V_146 -> V_137 & V_292 ) {
if ( V_2 -> V_130 ) {
F_61 () ;
F_21 ( V_284 L_56 ,
V_2 -> V_72 ,
F_63 ( V_2 -> V_67 ) -> V_59 ) ;
F_64 () ;
}
V_146 -> V_137 &= ~ V_292 ;
}
F_155 () ;
V_174 -> V_257 . V_24 = V_174 -> V_295 . V_24 ;
F_156 ( memcmp ( & V_174 -> V_257 , & V_174 -> V_295 ,
sizeof( V_174 -> V_257 ) ) != 0 ) ;
if ( V_174 -> V_257 . V_24 < 12 ) {
if ( ! F_153 ( V_146 ) ) {
V_146 -> V_163 = V_239 ;
V_2 -> V_77 -> V_293 ++ ;
goto V_296;
}
F_38 ( L_57 ,
V_2 -> V_72 , V_146 -> V_170 ) ;
V_146 -> V_163 = V_276 ;
goto V_296;
}
V_256 = F_157 ( V_146 ) ;
if ( F_19 ( V_256 ) ) {
if ( V_256 == F_55 ( - V_226 ) )
goto V_296;
return;
}
V_146 -> V_163 = V_282 ;
if ( V_294 ) {
V_146 -> V_170 = F_158 ( V_146 , V_294 , V_174 , V_256 ,
V_146 -> V_154 . V_157 ) ;
}
F_38 ( L_58 , V_146 -> V_220 ,
V_146 -> V_170 ) ;
return;
V_296:
V_146 -> V_170 = 0 ;
if ( V_146 -> V_178 == V_174 ) {
V_174 -> V_287 = V_174 -> V_257 . V_24 = 0 ;
if ( V_146 -> V_147 -> V_128 )
F_150 ( V_146 -> V_238 ,
V_174 -> V_285 ) ;
}
}
static T_6 *
F_139 ( struct V_135 * V_146 )
{
struct V_1 * V_2 = V_146 -> V_147 ;
struct V_173 * V_174 = V_146 -> V_178 ;
T_6 * V_256 = V_174 -> V_297 [ 0 ] . V_254 ;
V_256 = F_159 ( V_146 -> V_238 , V_256 ) ;
* V_256 ++ = V_174 -> V_298 ;
* V_256 ++ = F_160 ( V_299 ) ;
* V_256 ++ = F_160 ( V_300 ) ;
* V_256 ++ = F_160 ( V_2 -> V_73 ) ;
* V_256 ++ = F_160 ( V_2 -> V_76 ) ;
* V_256 ++ = F_160 ( V_146 -> V_154 . V_155 -> V_241 ) ;
V_256 = F_161 ( V_146 , V_256 ) ;
V_174 -> V_301 = F_162 ( & V_174 -> V_297 [ 0 ] , V_256 ) ;
return V_256 ;
}
static T_6 *
F_157 ( struct V_135 * V_146 )
{
struct V_1 * V_2 = V_146 -> V_147 ;
struct V_302 * V_303 = & V_146 -> V_178 -> V_257 . V_179 [ 0 ] ;
int V_24 = V_146 -> V_178 -> V_257 . V_24 >> 2 ;
T_6 * V_256 = V_303 -> V_254 ;
T_3 V_304 ;
int error = - V_232 ;
if ( ( V_146 -> V_178 -> V_257 . V_24 & 3 ) != 0 ) {
F_38 ( L_59
L_60 , V_146 -> V_220 , V_37 ,
V_146 -> V_178 -> V_257 . V_24 ) ;
goto V_305;
}
if ( ( V_24 -= 3 ) < 0 )
goto V_306;
V_256 += 1 ;
if ( ( V_304 = F_163 ( * V_256 ++ ) ) != V_307 ) {
F_38 ( L_61 ,
V_146 -> V_220 , V_37 , V_304 ) ;
goto V_308;
}
if ( ( V_304 = F_163 ( * V_256 ++ ) ) != V_309 ) {
if ( -- V_24 < 0 )
goto V_306;
switch ( ( V_304 = F_163 ( * V_256 ++ ) ) ) {
case V_310 :
break;
case V_311 :
F_38 ( L_62 ,
V_146 -> V_220 , V_37 ) ;
error = - V_268 ;
goto V_64;
default:
F_38 ( L_63
L_64 ,
V_146 -> V_220 , V_37 , V_304 ) ;
goto V_305;
}
if ( -- V_24 < 0 )
goto V_306;
switch ( ( V_304 = F_163 ( * V_256 ++ ) ) ) {
case V_312 :
case V_313 :
case V_314 :
case V_315 :
if ( ! V_146 -> V_233 )
break;
V_146 -> V_233 -- ;
F_38 ( L_65 ,
V_146 -> V_220 , V_37 ) ;
F_154 ( V_146 ) ;
F_129 ( V_146 ) ;
V_146 -> V_163 = V_223 ;
goto V_296;
case V_316 :
case V_317 :
if ( ! V_146 -> V_318 )
break;
V_146 -> V_318 -- ;
F_38 ( L_66 ,
V_146 -> V_220 , V_37 ) ;
V_146 -> V_163 = V_239 ;
goto V_296;
case V_319 :
F_61 () ;
F_21 ( V_284 L_67
L_68 ,
F_63 ( V_2 -> V_67 ) -> V_59 ) ;
F_64 () ;
break;
default:
F_38 ( L_69 ,
V_146 -> V_220 , V_37 , V_304 ) ;
error = - V_139 ;
}
F_38 ( L_70 ,
V_146 -> V_220 , V_37 , V_304 ) ;
goto V_64;
}
if ( ! ( V_256 = F_164 ( V_146 , V_256 ) ) ) {
F_38 ( L_71 ,
V_146 -> V_220 , V_37 ) ;
goto V_308;
}
V_24 = V_256 - ( T_6 * ) V_303 -> V_254 - 1 ;
if ( V_24 < 0 )
goto V_306;
switch ( ( V_304 = F_163 ( * V_256 ++ ) ) ) {
case V_320 :
return V_256 ;
case V_321 :
F_75 ( L_72
L_73 , V_146 -> V_220 , V_37 ,
( unsigned int ) V_2 -> V_73 ,
F_63 ( V_2 -> V_67 ) -> V_59 ) ;
error = - V_267 ;
goto V_64;
case V_322 :
F_75 ( L_74
L_73 , V_146 -> V_220 , V_37 ,
( unsigned int ) V_2 -> V_73 ,
( unsigned int ) V_2 -> V_76 ,
F_63 ( V_2 -> V_67 ) -> V_59 ) ;
error = - V_268 ;
goto V_64;
case V_323 :
F_75 ( L_75
L_76 ,
V_146 -> V_220 , V_37 ,
F_125 ( V_146 ) ,
V_2 -> V_73 , V_2 -> V_76 ,
F_63 ( V_2 -> V_67 ) -> V_59 ) ;
error = - V_265 ;
goto V_64;
case V_324 :
F_38 ( L_77 ,
V_146 -> V_220 , V_37 ) ;
break;
default:
F_38 ( L_78 ,
V_146 -> V_220 , V_37 , V_304 ) ;
}
V_308:
V_2 -> V_77 -> V_325 ++ ;
if ( V_146 -> V_318 ) {
V_146 -> V_318 -- ;
F_38 ( L_79 ,
V_146 -> V_220 , V_37 ) ;
V_146 -> V_163 = V_239 ;
V_296:
return F_55 ( - V_226 ) ;
}
V_305:
error = - V_139 ;
V_64:
F_71 ( V_146 , error ) ;
F_38 ( L_80 , V_146 -> V_220 ,
V_37 , error ) ;
return F_55 ( error ) ;
V_306:
F_38 ( L_81 , V_146 -> V_220 ,
V_37 ) ;
goto V_308;
}
static void F_165 ( void * V_326 , struct V_327 * V_328 , void * V_329 )
{
}
static int F_166 ( void * V_326 , struct V_327 * V_328 , void * V_329 )
{
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_152 V_153 = {
. V_155 = & V_330 ,
} ;
int V_31 ;
V_153 . V_158 = V_331 . V_332 ( NULL , NULL , 0 ) ;
V_31 = F_96 ( V_2 , & V_153 , V_149 | V_333 ) ;
F_167 ( V_153 . V_158 ) ;
return V_31 ;
}
struct V_135 * F_168 ( struct V_1 * V_2 , struct V_158 * V_334 , int V_121 )
{
struct V_152 V_153 = {
. V_155 = & V_330 ,
. V_158 = V_334 ,
} ;
struct V_160 V_161 = {
. V_162 = V_2 ,
. V_152 = & V_153 ,
. V_165 = & V_166 ,
. V_121 = V_121 ,
} ;
return F_92 ( & V_161 ) ;
}
static void F_169 ( void )
{
F_21 ( V_27 L_82
L_83 ) ;
}
static void F_170 ( const struct V_1 * V_2 ,
const struct V_135 * V_146 )
{
const char * V_335 = L_84 ;
if ( F_72 ( V_146 ) )
V_335 = F_171 ( V_146 -> V_140 ) ;
F_21 ( V_27 L_85 ,
V_146 -> V_220 , V_146 -> V_137 , V_146 -> V_170 ,
V_2 , V_146 -> V_178 , V_146 -> V_261 , V_146 -> V_172 ,
V_2 -> V_72 , V_2 -> V_76 , F_125 ( V_146 ) ,
V_146 -> V_163 , V_335 ) ;
}
void F_172 ( struct V_3 * V_3 )
{
struct V_1 * V_2 ;
struct V_135 * V_146 ;
int V_336 = 0 ;
struct V_4 * V_5 = F_3 ( V_3 , V_6 ) ;
F_4 ( & V_5 -> V_7 ) ;
F_28 (clnt, &sn->all_clients, cl_clients) {
F_4 ( & V_2 -> V_82 ) ;
F_28 (task, &clnt->cl_tasks, tk_task) {
if ( ! V_336 ) {
F_169 () ;
V_336 ++ ;
}
F_170 ( V_2 , V_146 ) ;
}
F_6 ( & V_2 -> V_82 ) ;
}
F_6 ( & V_5 -> V_7 ) ;
}
