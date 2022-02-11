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
if ( args -> V_56 >= V_54 -> V_62 )
goto V_63;
V_56 = V_54 -> V_56 [ args -> V_56 ] ;
if ( V_56 == NULL )
goto V_63;
V_31 = - V_64 ;
V_2 = F_40 ( sizeof( * V_2 ) , V_65 ) ;
if ( ! V_2 )
goto V_63;
V_2 -> V_39 = V_2 ;
F_41 ( V_2 -> V_66 , V_52 ) ;
V_2 -> V_67 = V_56 -> V_68 ;
V_2 -> V_69 = V_56 -> V_70 ;
V_2 -> V_71 = V_54 -> V_20 ;
V_2 -> V_72 = args -> V_73 ? : V_54 -> V_74 ;
V_2 -> V_75 = V_56 -> V_74 ;
V_2 -> V_76 = V_54 -> V_77 ;
V_2 -> V_78 = F_42 ( V_2 ) ;
V_31 = - V_64 ;
if ( V_2 -> V_78 == NULL )
goto V_79;
V_2 -> V_32 = V_54 ;
F_43 ( & V_2 -> V_80 ) ;
F_44 ( & V_2 -> V_81 ) ;
if ( ! F_45 ( V_52 ) )
V_2 -> V_82 = 1 ;
V_2 -> V_83 = V_52 -> V_84 ;
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
F_48 ( & V_2 -> V_40 , 1 ) ;
V_31 = F_23 ( V_2 , V_54 -> V_33 ) ;
if ( V_31 < 0 )
goto V_92;
V_58 = F_49 ( args -> V_93 , V_2 ) ;
if ( F_19 ( V_58 ) ) {
F_21 ( V_27 L_7 ,
args -> V_93 ) ;
V_31 = F_20 ( V_58 ) ;
goto V_94;
}
F_36 ( V_2 , F_50 () -> V_46 ) ;
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
F_53 () ;
V_60:
F_54 ( V_52 ) ;
return F_55 ( V_31 ) ;
}
struct V_1 * F_56 ( struct V_50 * args )
{
struct V_51 * V_52 ;
struct V_1 * V_2 ;
struct V_95 V_96 = {
. V_3 = args -> V_3 ,
. V_97 = args -> V_98 ,
. V_99 = args -> V_100 ,
. V_101 = args -> V_102 ,
. V_103 = args -> V_104 ,
. V_59 = args -> V_59 ,
. V_105 = args -> V_105 ,
} ;
char V_59 [ 48 ] ;
if ( V_96 . V_59 == NULL ) {
struct V_106 * V_107 =
(struct V_106 * ) args -> V_102 ;
struct V_108 * sin =
(struct V_108 * ) args -> V_102 ;
struct V_109 * V_110 =
(struct V_109 * ) args -> V_102 ;
V_59 [ 0 ] = '\0' ;
switch ( args -> V_102 -> V_111 ) {
case V_112 :
snprintf ( V_59 , sizeof( V_59 ) , L_8 ,
V_107 -> V_113 ) ;
break;
case V_114 :
snprintf ( V_59 , sizeof( V_59 ) , L_9 ,
& sin -> V_115 . V_116 ) ;
break;
case V_117 :
snprintf ( V_59 , sizeof( V_59 ) , L_10 ,
& V_110 -> V_118 ) ;
break;
default:
return F_55 ( - V_61 ) ;
}
V_96 . V_59 = V_59 ;
}
V_52 = F_57 ( & V_96 ) ;
if ( F_19 ( V_52 ) )
return (struct V_1 * ) V_52 ;
V_52 -> V_119 = 1 ;
if ( args -> V_120 & V_121 )
V_52 -> V_119 = 0 ;
V_2 = F_37 ( args , V_52 ) ;
if ( F_19 ( V_2 ) )
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
static struct V_1 * F_60 ( struct V_50 * args ,
struct V_1 * V_2 )
{
struct V_51 * V_52 ;
struct V_1 * V_130 ;
int V_31 ;
V_31 = - V_64 ;
F_61 () ;
V_52 = F_62 ( F_63 ( V_2 -> V_66 ) ) ;
F_64 () ;
if ( V_52 == NULL )
goto V_63;
args -> V_59 = V_52 -> V_59 ;
V_130 = F_37 ( args , V_52 ) ;
if ( F_19 ( V_130 ) ) {
V_31 = F_20 ( V_130 ) ;
goto V_63;
}
F_65 ( & V_2 -> V_40 ) ;
V_130 -> V_39 = V_2 ;
V_130 -> V_82 = 0 ;
V_130 -> V_123 = V_2 -> V_123 ;
V_130 -> V_127 = V_2 -> V_127 ;
V_130 -> V_129 = V_2 -> V_129 ;
return V_130 ;
V_63:
F_38 ( L_11 , V_37 , V_31 ) ;
return F_55 ( V_31 ) ;
}
struct V_1 * F_66 ( struct V_1 * V_2 )
{
struct V_50 args = {
. V_54 = V_2 -> V_32 ,
. V_73 = V_2 -> V_72 ,
. V_56 = V_2 -> V_75 ,
. V_93 = V_2 -> V_11 -> V_131 ,
. V_90 = V_2 -> V_89 ,
} ;
return F_60 ( & args , V_2 ) ;
}
struct V_1 *
F_67 ( struct V_1 * V_2 , T_2 V_132 )
{
struct V_50 args = {
. V_54 = V_2 -> V_32 ,
. V_73 = V_2 -> V_72 ,
. V_56 = V_2 -> V_75 ,
. V_93 = V_132 ,
. V_90 = V_2 -> V_89 ,
} ;
return F_60 ( & args , V_2 ) ;
}
void F_68 ( struct V_1 * V_2 )
{
struct V_133 * V_134 ;
if ( F_69 ( & V_2 -> V_80 ) )
return;
F_38 ( L_12 , V_2 ) ;
F_4 ( & V_2 -> V_81 ) ;
F_28 (rovr, &clnt->cl_tasks, tk_task) {
if ( ! F_70 ( V_134 ) )
continue;
if ( ! ( V_134 -> V_135 & V_136 ) ) {
V_134 -> V_135 |= V_136 ;
F_71 ( V_134 , - V_137 ) ;
if ( F_72 ( V_134 ) )
F_73 ( V_134 -> V_138 ,
V_134 ) ;
}
}
F_6 ( & V_2 -> V_81 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
F_74 () ;
F_75 ( L_13 ,
V_2 -> V_71 ,
F_63 ( V_2 -> V_66 ) -> V_59 ) ;
while ( ! F_69 ( & V_2 -> V_80 ) ) {
F_68 ( V_2 ) ;
F_76 ( V_139 ,
F_69 ( & V_2 -> V_80 ) , 1 * V_140 ) ;
}
F_31 ( V_2 ) ;
}
static void
F_77 ( struct V_1 * V_2 )
{
F_75 ( L_14 ,
V_2 -> V_71 ,
F_63 ( V_2 -> V_66 ) -> V_59 ) ;
if ( V_2 -> V_39 != V_2 )
F_31 ( V_2 -> V_39 ) ;
F_7 ( V_2 ) ;
F_11 ( V_2 ) ;
F_52 ( V_2 -> V_78 ) ;
F_51 ( V_2 -> V_89 ) ;
V_2 -> V_78 = NULL ;
F_54 ( F_78 ( V_2 -> V_66 ) ) ;
F_53 () ;
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
if ( F_69 ( & V_2 -> V_80 ) )
F_82 ( & V_139 ) ;
if ( F_81 ( & V_2 -> V_40 ) )
F_79 ( V_2 ) ;
}
struct V_1 * F_83 ( struct V_1 * V_141 ,
const struct V_53 * V_54 ,
T_3 V_142 )
{
struct V_50 args = {
. V_54 = V_54 ,
. V_73 = V_54 -> V_74 ,
. V_56 = V_142 ,
. V_93 = V_141 -> V_11 -> V_131 ,
. V_90 = V_141 -> V_89 ,
} ;
struct V_1 * V_2 ;
int V_31 ;
V_2 = F_60 ( & args , V_141 ) ;
if ( F_19 ( V_2 ) )
goto V_143;
V_31 = F_58 ( V_2 ) ;
if ( V_31 != 0 ) {
F_59 ( V_2 ) ;
V_2 = F_55 ( V_31 ) ;
}
V_143:
return V_2 ;
}
void F_84 ( struct V_133 * V_144 )
{
struct V_1 * V_2 = V_144 -> V_145 ;
if ( V_2 != NULL ) {
F_4 ( & V_2 -> V_81 ) ;
F_8 ( & V_144 -> V_146 ) ;
F_6 ( & V_2 -> V_81 ) ;
V_144 -> V_145 = NULL ;
F_31 ( V_2 ) ;
}
}
static
void F_85 ( struct V_133 * V_144 , struct V_1 * V_2 )
{
if ( V_2 != NULL ) {
F_84 ( V_144 ) ;
V_144 -> V_145 = V_2 ;
F_65 ( & V_2 -> V_40 ) ;
if ( V_2 -> V_123 )
V_144 -> V_135 |= V_147 ;
if ( F_86 () ) {
struct V_51 * V_52 ;
F_61 () ;
V_52 = F_63 ( V_2 -> V_66 ) ;
if ( V_52 -> V_148 )
V_144 -> V_135 |= V_149 ;
F_64 () ;
}
F_4 ( & V_2 -> V_81 ) ;
F_87 ( & V_144 -> V_146 , & V_2 -> V_80 ) ;
F_6 ( & V_2 -> V_81 ) ;
}
}
void F_88 ( struct V_133 * V_144 , struct V_1 * V_2 )
{
F_84 ( V_144 ) ;
F_85 ( V_144 , V_2 ) ;
}
static void
F_89 ( struct V_133 * V_144 , const struct V_150 * V_151 )
{
if ( V_151 != NULL ) {
V_144 -> V_152 . V_153 = V_151 -> V_153 ;
V_144 -> V_152 . V_154 = V_151 -> V_154 ;
V_144 -> V_152 . V_155 = V_151 -> V_155 ;
if ( V_151 -> V_156 != NULL )
V_144 -> V_152 . V_156 = F_90 ( V_151 -> V_156 ) ;
}
}
static void
F_91 ( struct V_133 * V_144 , void * V_157 )
{
}
struct V_133 * F_92 ( const struct V_158 * V_159 )
{
struct V_133 * V_144 ;
V_144 = F_93 ( V_159 ) ;
if ( F_19 ( V_144 ) )
goto V_143;
F_85 ( V_144 , V_159 -> V_160 ) ;
F_89 ( V_144 , V_159 -> V_150 ) ;
if ( V_144 -> V_161 == NULL )
F_94 ( V_144 ) ;
F_65 ( & V_144 -> V_162 ) ;
F_95 ( V_144 ) ;
V_143:
return V_144 ;
}
int F_96 ( struct V_1 * V_2 , const struct V_150 * V_151 , int V_120 )
{
struct V_133 * V_144 ;
struct V_158 V_159 = {
. V_160 = V_2 ,
. V_150 = V_151 ,
. V_163 = & V_164 ,
. V_120 = V_120 ,
} ;
int V_165 ;
F_97 ( V_120 & V_166 ) ;
if ( V_120 & V_166 ) {
F_98 ( V_159 . V_163 ,
V_159 . V_167 ) ;
return - V_61 ;
}
V_144 = F_92 ( & V_159 ) ;
if ( F_19 ( V_144 ) )
return F_20 ( V_144 ) ;
V_165 = V_144 -> V_168 ;
F_99 ( V_144 ) ;
return V_165 ;
}
int
F_100 ( struct V_1 * V_2 , const struct V_150 * V_151 , int V_120 ,
const struct V_169 * V_170 , void * V_157 )
{
struct V_133 * V_144 ;
struct V_158 V_159 = {
. V_160 = V_2 ,
. V_150 = V_151 ,
. V_163 = V_170 ,
. V_167 = V_157 ,
. V_120 = V_120 | V_166 ,
} ;
V_144 = F_92 ( & V_159 ) ;
if ( F_19 ( V_144 ) )
return F_20 ( V_144 ) ;
F_99 ( V_144 ) ;
return 0 ;
}
struct V_133 * F_101 ( struct V_171 * V_172 ,
const struct V_169 * V_170 )
{
struct V_133 * V_144 ;
struct V_173 * V_174 = & V_172 -> V_175 ;
struct V_158 V_159 = {
. V_163 = V_170 ,
} ;
F_38 ( L_16 , V_172 ) ;
V_144 = F_93 ( & V_159 ) ;
if ( F_19 ( V_144 ) ) {
F_102 ( V_172 ) ;
goto V_143;
}
V_144 -> V_176 = V_172 ;
V_174 -> V_24 = V_174 -> V_177 [ 0 ] . V_178 + V_174 -> V_179 +
V_174 -> V_180 [ 0 ] . V_178 ;
V_144 -> V_161 = V_181 ;
F_65 ( & V_144 -> V_162 ) ;
F_97 ( F_103 ( & V_144 -> V_162 ) != 2 ) ;
F_95 ( V_144 ) ;
V_143:
F_38 ( L_17 , V_144 ) ;
return V_144 ;
}
void
F_94 ( struct V_133 * V_144 )
{
V_144 -> V_161 = V_182 ;
}
T_4 F_104 ( struct V_1 * V_2 , struct V_183 * V_184 , T_4 V_185 )
{
T_4 V_186 ;
struct V_51 * V_52 ;
F_61 () ;
V_52 = F_63 ( V_2 -> V_66 ) ;
V_186 = V_52 -> V_103 ;
if ( V_186 > V_185 )
V_186 = V_185 ;
memcpy ( V_184 , & V_52 -> V_187 , V_186 ) ;
F_64 () ;
return V_186 ;
}
const char * F_105 ( struct V_1 * V_2 ,
enum V_188 V_189 )
{
struct V_51 * V_52 ;
V_52 = F_63 ( V_2 -> V_66 ) ;
if ( V_52 -> V_190 [ V_189 ] != NULL )
return V_52 -> V_190 [ V_189 ] ;
else
return L_18 ;
}
static int F_106 ( struct V_3 * V_3 , struct V_183 * V_191 , T_4 V_192 ,
struct V_183 * V_184 , int V_193 )
{
struct V_194 * V_195 ;
int V_31 ;
V_31 = F_107 ( V_3 , V_191 -> V_111 ,
V_196 , V_197 , & V_195 , 1 ) ;
if ( V_31 < 0 ) {
F_38 ( L_19 , V_31 ) ;
goto V_143;
}
switch ( V_191 -> V_111 ) {
case V_114 :
V_31 = F_108 ( V_195 ,
(struct V_183 * ) & V_198 ,
sizeof( V_198 ) ) ;
break;
case V_117 :
V_31 = F_108 ( V_195 ,
(struct V_183 * ) & V_199 ,
sizeof( V_199 ) ) ;
break;
default:
V_31 = - V_200 ;
goto V_143;
}
if ( V_31 < 0 ) {
F_38 ( L_20 , V_31 ) ;
goto V_201;
}
V_31 = F_109 ( V_195 , V_191 , V_192 , 0 ) ;
if ( V_31 < 0 ) {
F_38 ( L_21 , V_31 ) ;
goto V_201;
}
V_31 = F_110 ( V_195 , V_184 , & V_193 ) ;
if ( V_31 < 0 ) {
F_38 ( L_22 , V_31 ) ;
goto V_201;
}
V_31 = 0 ;
if ( V_184 -> V_111 == V_117 ) {
struct V_109 * V_110 = (struct V_109 * ) V_184 ;
V_110 -> V_202 = 0 ;
}
F_38 ( L_23 , V_37 ) ;
V_201:
F_111 ( V_195 ) ;
V_143:
return V_31 ;
}
static int F_112 ( int V_203 , struct V_183 * V_184 , T_4 V_193 )
{
switch ( V_203 ) {
case V_114 :
if ( V_193 < sizeof( V_198 ) )
return - V_61 ;
memcpy ( V_184 , & V_198 ,
sizeof( V_198 ) ) ;
break;
case V_117 :
if ( V_193 < sizeof( V_199 ) )
return - V_61 ;
memcpy ( V_184 , & V_199 ,
sizeof( V_199 ) ) ;
default:
F_38 ( L_24 ,
V_37 ) ;
return - V_200 ;
}
F_38 ( L_25 , V_37 ) ;
return 0 ;
}
int F_113 ( struct V_1 * V_2 , struct V_183 * V_184 , T_4 V_193 )
{
struct V_204 V_102 ;
struct V_183 * V_191 = (struct V_183 * ) & V_102 ;
struct V_51 * V_52 ;
struct V_3 * V_3 ;
T_4 V_192 ;
int V_31 ;
F_61 () ;
V_52 = F_63 ( V_2 -> V_66 ) ;
V_192 = V_52 -> V_103 ;
memcpy ( V_191 , & V_52 -> V_187 , V_192 ) ;
V_3 = F_114 ( V_52 -> V_205 ) ;
F_64 () ;
F_115 ( V_191 , 0 ) ;
V_31 = F_106 ( V_3 , V_191 , V_192 , V_184 , V_193 ) ;
F_116 ( V_3 ) ;
if ( V_31 != 0 )
return F_112 ( V_191 -> V_111 , V_184 , V_193 ) ;
return 0 ;
}
void
F_117 ( struct V_1 * V_2 , unsigned int V_206 , unsigned int V_207 )
{
struct V_51 * V_52 ;
F_61 () ;
V_52 = F_63 ( V_2 -> V_66 ) ;
if ( V_52 -> V_208 -> V_209 )
V_52 -> V_208 -> V_209 ( V_52 , V_206 , V_207 ) ;
F_64 () ;
}
int F_118 ( struct V_1 * V_2 )
{
int V_98 ;
F_61 () ;
V_98 = F_63 ( V_2 -> V_66 ) -> V_210 ;
F_64 () ;
return V_98 ;
}
struct V_3 * F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_211 ;
F_61 () ;
V_211 = F_63 ( V_2 -> V_66 ) -> V_205 ;
F_64 () ;
return V_211 ;
}
T_4 F_119 ( struct V_1 * V_2 )
{
T_4 V_211 ;
F_61 () ;
V_211 = F_63 ( V_2 -> V_66 ) -> V_212 ;
F_64 () ;
return V_211 ;
}
unsigned long F_120 ( struct V_1 * V_2 )
{
unsigned long V_211 ;
F_61 () ;
V_211 = F_63 ( V_2 -> V_66 ) -> V_84 -> V_88 ;
F_64 () ;
return V_211 ;
}
void F_121 ( struct V_1 * V_2 )
{
if ( V_2 -> V_82 ) {
F_61 () ;
F_122 ( F_63 ( V_2 -> V_66 ) ) ;
F_64 () ;
}
}
int
F_123 ( struct V_133 * V_144 )
{
if ( F_124 ( V_144 ) )
return 0 ;
V_144 -> V_161 = V_182 ;
if ( V_144 -> V_170 -> V_213 != NULL )
V_144 -> V_161 = V_214 ;
return 1 ;
}
int
F_125 ( struct V_133 * V_144 )
{
if ( F_124 ( V_144 ) )
return 0 ;
V_144 -> V_161 = V_182 ;
return 1 ;
}
static const char * F_126 ( const struct V_133 * V_144 )
{
const struct V_215 * V_216 = V_144 -> V_152 . V_153 ;
if ( V_216 ) {
if ( V_216 -> V_217 )
return V_216 -> V_217 ;
else
return L_26 ;
} else
return L_27 ;
}
static void
V_182 ( struct V_133 * V_144 )
{
struct V_1 * V_2 = V_144 -> V_145 ;
F_38 ( L_28 , V_144 -> V_218 ,
V_2 -> V_71 , V_2 -> V_75 ,
F_126 ( V_144 ) ,
( F_127 ( V_144 ) ? L_29 : L_30 ) ) ;
V_144 -> V_152 . V_153 -> V_219 ++ ;
V_2 -> V_76 -> V_220 ++ ;
V_144 -> V_161 = V_221 ;
}
static void
V_221 ( struct V_133 * V_144 )
{
F_128 ( V_144 ) ;
V_144 -> V_168 = 0 ;
V_144 -> V_161 = V_222 ;
F_129 ( V_144 ) ;
}
static void
V_222 ( struct V_133 * V_144 )
{
int V_165 = V_144 -> V_168 ;
F_128 ( V_144 ) ;
V_144 -> V_168 = 0 ;
if ( V_165 >= 0 ) {
if ( V_144 -> V_176 ) {
V_144 -> V_161 = V_223 ;
return;
}
F_21 ( V_36 L_31 ,
V_37 , V_165 ) ;
F_71 ( V_144 , - V_137 ) ;
return;
}
if ( V_144 -> V_176 ) {
F_21 ( V_36 L_32 ,
V_37 , V_165 ) ;
F_130 ( V_144 ) ;
}
switch ( V_165 ) {
case - V_64 :
F_131 ( V_144 , V_140 >> 2 ) ;
case - V_224 :
V_144 -> V_161 = V_221 ;
return;
case - V_137 :
break;
default:
F_21 ( V_36 L_33 ,
V_37 , V_165 ) ;
break;
}
F_71 ( V_144 , V_165 ) ;
}
static void
V_223 ( struct V_133 * V_144 )
{
F_128 ( V_144 ) ;
V_144 -> V_161 = V_225 ;
V_144 -> V_168 = 0 ;
V_144 -> V_145 -> V_76 -> V_226 ++ ;
F_132 ( V_144 ) ;
}
static void
V_225 ( struct V_133 * V_144 )
{
int V_165 = V_144 -> V_168 ;
F_128 ( V_144 ) ;
V_144 -> V_168 = 0 ;
V_144 -> V_161 = V_223 ;
switch ( V_165 ) {
case 0 :
if ( F_133 ( V_144 ) )
V_144 -> V_161 = V_227 ;
return;
case - V_228 :
F_131 ( V_144 , 3 * V_140 ) ;
case - V_229 :
case - V_224 :
V_165 = - V_230 ;
if ( ! V_144 -> V_231 )
break;
V_144 -> V_231 -- ;
F_38 ( L_34 ,
V_144 -> V_218 , V_37 ) ;
return;
}
F_38 ( L_35 ,
V_144 -> V_218 , V_37 , V_165 ) ;
F_71 ( V_144 , V_165 ) ;
}
static void
V_227 ( struct V_133 * V_144 )
{
unsigned int V_232 = V_144 -> V_176 -> V_233 -> V_234 -> V_235 ;
struct V_171 * V_172 = V_144 -> V_176 ;
struct V_51 * V_52 = V_172 -> V_236 ;
struct V_215 * V_216 = V_144 -> V_152 . V_153 ;
F_128 ( V_144 ) ;
V_144 -> V_168 = 0 ;
V_144 -> V_161 = V_237 ;
if ( V_172 -> V_238 )
return;
if ( V_216 -> V_239 != 0 ) {
F_134 ( V_216 -> V_240 == 0 ) ;
if ( V_216 -> V_241 != NULL )
F_134 ( V_216 -> V_242 == 0 ) ;
}
V_172 -> V_243 = V_244 + ( V_232 << 1 ) + V_216 -> V_240 ;
V_172 -> V_243 <<= 2 ;
V_172 -> V_245 = V_246 + V_232 + V_216 -> V_242 ;
V_172 -> V_245 <<= 2 ;
V_172 -> V_238 = V_52 -> V_208 -> V_247 ( V_144 ,
V_172 -> V_243 + V_172 -> V_245 ) ;
if ( V_172 -> V_238 != NULL )
return;
F_38 ( L_36 , V_144 -> V_218 ) ;
if ( F_127 ( V_144 ) || ! F_135 ( V_248 ) ) {
V_144 -> V_161 = V_227 ;
F_131 ( V_144 , V_140 >> 4 ) ;
return;
}
F_71 ( V_144 , - V_249 ) ;
}
static inline int
F_136 ( struct V_133 * V_144 )
{
return V_144 -> V_176 -> V_175 . V_24 == 0 ;
}
static inline void
F_137 ( struct V_133 * V_144 )
{
V_144 -> V_176 -> V_175 . V_24 = 0 ;
V_144 -> V_176 -> V_250 = 0 ;
}
static inline void
F_138 ( struct V_173 * V_184 , void * V_251 , T_4 V_24 )
{
V_184 -> V_177 [ 0 ] . V_252 = V_251 ;
V_184 -> V_177 [ 0 ] . V_178 = V_24 ;
V_184 -> V_180 [ 0 ] . V_178 = 0 ;
V_184 -> V_179 = 0 ;
V_184 -> V_120 = 0 ;
V_184 -> V_24 = 0 ;
V_184 -> V_193 = V_24 ;
}
static void
F_139 ( struct V_133 * V_144 )
{
struct V_171 * V_172 = V_144 -> V_176 ;
T_5 V_253 ;
T_6 * V_254 ;
F_128 ( V_144 ) ;
F_138 ( & V_172 -> V_175 ,
V_172 -> V_238 ,
V_172 -> V_243 ) ;
F_138 ( & V_172 -> V_255 ,
( char * ) V_172 -> V_238 + V_172 -> V_243 ,
V_172 -> V_245 ) ;
V_254 = F_140 ( V_144 ) ;
if ( V_254 == NULL ) {
F_21 ( V_27 L_37 ) ;
F_71 ( V_144 , - V_137 ) ;
return;
}
V_253 = V_144 -> V_152 . V_153 -> V_256 ;
if ( V_253 == NULL )
return;
V_144 -> V_168 = F_141 ( V_144 , V_253 , V_172 , V_254 ,
V_144 -> V_152 . V_154 ) ;
}
static void
V_237 ( struct V_133 * V_144 )
{
struct V_51 * V_52 = V_144 -> V_176 -> V_236 ;
F_128 ( V_144 ) ;
V_144 -> V_161 = V_257 ;
if ( ! F_45 ( V_52 ) ) {
V_144 -> V_161 = V_258 ;
V_144 -> V_259 = V_52 -> V_260 ;
V_52 -> V_208 -> V_261 ( V_144 ) ;
}
}
static void
V_258 ( struct V_133 * V_144 )
{
int V_165 = - V_137 ;
if ( V_144 -> V_168 >= 0 ) {
F_128 ( V_144 ) ;
V_144 -> V_168 = 0 ;
V_144 -> V_161 = V_257 ;
return;
}
F_142 ( V_144 ) ;
switch ( V_144 -> V_168 ) {
case - V_64 :
F_38 ( L_38 , V_144 -> V_218 ) ;
F_131 ( V_144 , V_140 >> 2 ) ;
goto V_262;
case - V_230 :
F_38 ( L_39
L_40 , V_144 -> V_218 ) ;
if ( V_144 -> V_152 . V_153 -> V_239 == 0 ) {
V_165 = - V_263 ;
break;
}
if ( V_144 -> V_264 == 0 )
break;
V_144 -> V_264 -- ;
F_131 ( V_144 , 3 * V_140 ) ;
goto V_262;
case - V_228 :
F_38 ( L_41 ,
V_144 -> V_218 ) ;
goto V_262;
case - V_265 :
F_38 ( L_42 ,
V_144 -> V_218 ) ;
break;
case - V_266 :
F_38 ( L_43 ,
V_144 -> V_218 ) ;
V_144 -> V_168 = 0 ;
V_144 -> V_161 = V_237 ;
return;
case - V_267 :
case - V_268 :
case - V_269 :
case - V_270 :
case - V_271 :
case - V_272 :
case - V_273 :
F_38 ( L_44 ,
V_144 -> V_218 , V_144 -> V_168 ) ;
if ( ! F_143 ( V_144 ) ) {
F_131 ( V_144 , 5 * V_140 ) ;
goto V_262;
}
V_165 = V_144 -> V_168 ;
break;
default:
F_38 ( L_45 ,
V_144 -> V_218 , - V_144 -> V_168 ) ;
}
F_71 ( V_144 , V_165 ) ;
return;
V_262:
V_144 -> V_161 = V_274 ;
}
static void
V_257 ( struct V_133 * V_144 )
{
struct V_51 * V_52 = V_144 -> V_176 -> V_236 ;
F_38 ( L_46 ,
V_144 -> V_218 , V_52 ,
( F_144 ( V_52 ) ? L_47 : L_48 ) ) ;
V_144 -> V_161 = V_275 ;
if ( ! F_144 ( V_52 ) ) {
V_144 -> V_161 = V_276 ;
if ( V_144 -> V_168 < 0 )
return;
F_145 ( V_144 ) ;
}
}
static void
V_276 ( struct V_133 * V_144 )
{
struct V_1 * V_2 = V_144 -> V_145 ;
int V_165 = V_144 -> V_168 ;
F_128 ( V_144 ) ;
V_144 -> V_168 = 0 ;
if ( V_165 >= 0 || V_165 == - V_224 ) {
V_2 -> V_76 -> V_277 ++ ;
V_144 -> V_161 = V_275 ;
return;
}
F_146 ( V_144 , V_165 ) ;
switch ( V_165 ) {
case - V_228 :
V_144 -> V_161 = V_274 ;
break;
default:
F_71 ( V_144 , - V_137 ) ;
}
}
static void
V_275 ( struct V_133 * V_144 )
{
F_128 ( V_144 ) ;
V_144 -> V_161 = V_278 ;
if ( V_144 -> V_168 < 0 )
return;
V_144 -> V_168 = F_147 ( V_144 ) ;
if ( V_144 -> V_168 != 0 )
return;
V_144 -> V_161 = V_279 ;
if ( F_136 ( V_144 ) ) {
F_139 ( V_144 ) ;
if ( V_144 -> V_168 != 0 ) {
if ( V_144 -> V_168 == - V_224 )
F_131 ( V_144 , V_140 >> 4 ) ;
else
F_71 ( V_144 , V_144 -> V_168 ) ;
return;
}
}
F_148 ( V_144 ) ;
if ( V_144 -> V_168 < 0 )
return;
V_279 ( V_144 ) ;
if ( F_149 ( V_144 ) )
return;
V_144 -> V_161 = V_280 ;
F_73 ( & V_144 -> V_176 -> V_236 -> V_281 , V_144 ) ;
}
static void
V_279 ( struct V_133 * V_144 )
{
V_144 -> V_161 = V_278 ;
if ( V_144 -> V_168 == 0 ) {
F_150 ( V_144 ) ;
F_137 ( V_144 ) ;
return;
}
switch ( V_144 -> V_168 ) {
case - V_224 :
break;
default:
F_128 ( V_144 ) ;
F_150 ( V_144 ) ;
F_137 ( V_144 ) ;
break;
case - V_267 :
case - V_270 :
case - V_271 :
case - V_272 :
if ( F_143 ( V_144 ) ) {
F_150 ( V_144 ) ;
F_71 ( V_144 , V_144 -> V_168 ) ;
break;
}
case - V_268 :
case - V_269 :
case - V_273 :
F_137 ( V_144 ) ;
}
}
static void
V_181 ( struct V_133 * V_144 )
{
struct V_171 * V_172 = V_144 -> V_176 ;
V_144 -> V_168 = F_147 ( V_144 ) ;
if ( V_144 -> V_168 == - V_224 ) {
V_144 -> V_168 = 0 ;
V_144 -> V_161 = V_181 ;
return;
}
V_144 -> V_161 = V_280 ;
if ( V_144 -> V_168 < 0 ) {
F_21 ( V_282 L_49
L_50 , V_144 -> V_168 ) ;
return;
}
F_148 ( V_144 ) ;
F_150 ( V_144 ) ;
F_128 ( V_144 ) ;
switch ( V_144 -> V_168 ) {
case 0 :
break;
case - V_270 :
case - V_271 :
case - V_272 :
case - V_228 :
F_21 ( V_282 L_49
L_50 , V_144 -> V_168 ) ;
F_151 ( V_172 -> V_236 ,
V_172 -> V_283 ) ;
break;
default:
F_97 ( V_144 -> V_168 == - V_224 ) ;
F_21 ( V_282 L_49
L_50 , V_144 -> V_168 ) ;
break;
}
F_73 ( & V_172 -> V_236 -> V_281 , V_144 ) ;
}
static void
V_278 ( struct V_133 * V_144 )
{
struct V_1 * V_2 = V_144 -> V_145 ;
struct V_171 * V_172 = V_144 -> V_176 ;
int V_165 ;
if ( V_172 -> V_284 > 0 && ! V_172 -> V_250 )
V_144 -> V_168 = V_172 -> V_284 ;
F_128 ( V_144 ) ;
V_165 = V_144 -> V_168 ;
if ( V_165 >= 0 ) {
V_144 -> V_161 = V_285 ;
return;
}
F_152 ( V_144 ) ;
V_144 -> V_168 = 0 ;
switch( V_165 ) {
case - V_270 :
case - V_271 :
case - V_272 :
F_131 ( V_144 , 3 * V_140 ) ;
case - V_228 :
V_144 -> V_161 = V_274 ;
if ( V_144 -> V_145 -> V_127 )
F_151 ( V_172 -> V_236 ,
V_172 -> V_283 ) ;
break;
case - V_268 :
case - V_267 :
F_121 ( V_2 ) ;
F_131 ( V_144 , 3 * V_140 ) ;
case - V_273 :
case - V_269 :
V_144 -> V_161 = V_237 ;
break;
case - V_224 :
V_144 -> V_161 = V_275 ;
break;
case - V_137 :
F_71 ( V_144 , V_165 ) ;
break;
default:
if ( V_2 -> V_129 )
F_21 ( L_51 ,
V_2 -> V_71 , - V_165 ) ;
F_71 ( V_144 , V_165 ) ;
}
}
static void
V_274 ( struct V_133 * V_144 )
{
struct V_1 * V_2 = V_144 -> V_145 ;
if ( F_153 ( V_144 -> V_176 ) == 0 ) {
F_38 ( L_52 , V_144 -> V_218 ) ;
goto V_286;
}
F_38 ( L_53 , V_144 -> V_218 ) ;
V_144 -> V_287 ++ ;
if ( F_143 ( V_144 ) ) {
F_71 ( V_144 , - V_228 ) ;
return;
}
if ( F_154 ( V_144 ) ) {
if ( V_2 -> V_129 ) {
F_61 () ;
F_21 ( V_282 L_54 ,
V_2 -> V_71 ,
F_63 ( V_2 -> V_66 ) -> V_59 ) ;
F_64 () ;
}
if ( V_144 -> V_135 & V_288 )
F_71 ( V_144 , - V_228 ) ;
else
F_71 ( V_144 , - V_137 ) ;
return;
}
if ( ! ( V_144 -> V_135 & V_289 ) ) {
V_144 -> V_135 |= V_289 ;
if ( V_2 -> V_129 ) {
F_61 () ;
F_21 ( V_282 L_55 ,
V_2 -> V_71 ,
F_63 ( V_2 -> V_66 ) -> V_59 ) ;
F_64 () ;
}
}
F_121 ( V_2 ) ;
F_155 ( V_144 ) ;
V_286:
V_2 -> V_76 -> V_290 ++ ;
V_144 -> V_161 = V_237 ;
V_144 -> V_168 = 0 ;
}
static void
V_285 ( struct V_133 * V_144 )
{
struct V_1 * V_2 = V_144 -> V_145 ;
struct V_171 * V_172 = V_144 -> V_176 ;
T_7 V_291 = V_144 -> V_152 . V_153 -> V_241 ;
T_6 * V_254 ;
F_128 ( V_144 ) ;
if ( V_144 -> V_135 & V_289 ) {
if ( V_2 -> V_129 ) {
F_61 () ;
F_21 ( V_282 L_56 ,
V_2 -> V_71 ,
F_63 ( V_2 -> V_66 ) -> V_59 ) ;
F_64 () ;
}
V_144 -> V_135 &= ~ V_289 ;
}
F_156 () ;
V_172 -> V_255 . V_24 = V_172 -> V_292 . V_24 ;
F_157 ( memcmp ( & V_172 -> V_255 , & V_172 -> V_292 ,
sizeof( V_172 -> V_255 ) ) != 0 ) ;
if ( V_172 -> V_255 . V_24 < 12 ) {
if ( ! F_154 ( V_144 ) ) {
V_144 -> V_161 = V_237 ;
V_2 -> V_76 -> V_290 ++ ;
goto V_293;
}
F_38 ( L_57 ,
V_2 -> V_71 , V_144 -> V_168 ) ;
V_144 -> V_161 = V_274 ;
goto V_293;
}
V_254 = F_158 ( V_144 ) ;
if ( F_19 ( V_254 ) ) {
if ( V_254 == F_55 ( - V_224 ) )
goto V_293;
return;
}
V_144 -> V_161 = V_280 ;
if ( V_291 ) {
V_144 -> V_168 = F_159 ( V_144 , V_291 , V_172 , V_254 ,
V_144 -> V_152 . V_155 ) ;
}
F_38 ( L_58 , V_144 -> V_218 ,
V_144 -> V_168 ) ;
return;
V_293:
V_144 -> V_168 = 0 ;
if ( V_144 -> V_176 == V_172 ) {
V_172 -> V_284 = V_172 -> V_255 . V_24 = 0 ;
if ( V_144 -> V_145 -> V_127 )
F_151 ( V_172 -> V_236 ,
V_172 -> V_283 ) ;
}
}
static T_6 *
F_140 ( struct V_133 * V_144 )
{
struct V_1 * V_2 = V_144 -> V_145 ;
struct V_171 * V_172 = V_144 -> V_176 ;
T_6 * V_254 = V_172 -> V_294 [ 0 ] . V_252 ;
V_254 = F_160 ( V_172 -> V_236 , V_254 ) ;
* V_254 ++ = V_172 -> V_295 ;
* V_254 ++ = F_161 ( V_296 ) ;
* V_254 ++ = F_161 ( V_297 ) ;
* V_254 ++ = F_161 ( V_2 -> V_72 ) ;
* V_254 ++ = F_161 ( V_2 -> V_75 ) ;
* V_254 ++ = F_161 ( V_144 -> V_152 . V_153 -> V_239 ) ;
V_254 = F_162 ( V_144 , V_254 ) ;
V_172 -> V_298 = F_163 ( & V_172 -> V_294 [ 0 ] , V_254 ) ;
return V_254 ;
}
static T_6 *
F_158 ( struct V_133 * V_144 )
{
struct V_1 * V_2 = V_144 -> V_145 ;
struct V_299 * V_300 = & V_144 -> V_176 -> V_255 . V_177 [ 0 ] ;
int V_24 = V_144 -> V_176 -> V_255 . V_24 >> 2 ;
T_6 * V_254 = V_300 -> V_252 ;
T_3 V_301 ;
int error = - V_230 ;
if ( ( V_144 -> V_176 -> V_255 . V_24 & 3 ) != 0 ) {
F_38 ( L_59
L_60 , V_144 -> V_218 , V_37 ,
V_144 -> V_176 -> V_255 . V_24 ) ;
goto V_302;
}
if ( ( V_24 -= 3 ) < 0 )
goto V_303;
V_254 += 1 ;
if ( ( V_301 = F_164 ( * V_254 ++ ) ) != V_304 ) {
F_38 ( L_61 ,
V_144 -> V_218 , V_37 , V_301 ) ;
goto V_305;
}
if ( ( V_301 = F_164 ( * V_254 ++ ) ) != V_306 ) {
if ( -- V_24 < 0 )
goto V_303;
switch ( ( V_301 = F_164 ( * V_254 ++ ) ) ) {
case V_307 :
break;
case V_308 :
F_38 ( L_62 ,
V_144 -> V_218 , V_37 ) ;
error = - V_266 ;
goto V_63;
default:
F_38 ( L_63
L_64 ,
V_144 -> V_218 , V_37 , V_301 ) ;
goto V_302;
}
if ( -- V_24 < 0 )
goto V_303;
switch ( ( V_301 = F_164 ( * V_254 ++ ) ) ) {
case V_309 :
case V_310 :
case V_311 :
case V_312 :
if ( ! V_144 -> V_231 )
break;
V_144 -> V_231 -- ;
F_38 ( L_65 ,
V_144 -> V_218 , V_37 ) ;
F_155 ( V_144 ) ;
F_130 ( V_144 ) ;
V_144 -> V_161 = V_221 ;
goto V_293;
case V_313 :
case V_314 :
if ( ! V_144 -> V_315 )
break;
V_144 -> V_315 -- ;
F_38 ( L_66 ,
V_144 -> V_218 , V_37 ) ;
V_144 -> V_161 = V_237 ;
goto V_293;
case V_316 :
F_61 () ;
F_21 ( V_282 L_67
L_68 ,
F_63 ( V_2 -> V_66 ) -> V_59 ) ;
F_64 () ;
break;
default:
F_38 ( L_69 ,
V_144 -> V_218 , V_37 , V_301 ) ;
error = - V_137 ;
}
F_38 ( L_70 ,
V_144 -> V_218 , V_37 , V_301 ) ;
goto V_63;
}
if ( ! ( V_254 = F_165 ( V_144 , V_254 ) ) ) {
F_38 ( L_71 ,
V_144 -> V_218 , V_37 ) ;
goto V_305;
}
V_24 = V_254 - ( T_6 * ) V_300 -> V_252 - 1 ;
if ( V_24 < 0 )
goto V_303;
switch ( ( V_301 = F_164 ( * V_254 ++ ) ) ) {
case V_317 :
return V_254 ;
case V_318 :
F_75 ( L_72
L_73 , V_144 -> V_218 , V_37 ,
( unsigned int ) V_2 -> V_72 ,
F_63 ( V_2 -> V_66 ) -> V_59 ) ;
error = - V_265 ;
goto V_63;
case V_319 :
F_75 ( L_74
L_73 , V_144 -> V_218 , V_37 ,
( unsigned int ) V_2 -> V_72 ,
( unsigned int ) V_2 -> V_75 ,
F_63 ( V_2 -> V_66 ) -> V_59 ) ;
error = - V_266 ;
goto V_63;
case V_320 :
F_75 ( L_75
L_76 ,
V_144 -> V_218 , V_37 ,
F_126 ( V_144 ) ,
V_2 -> V_72 , V_2 -> V_75 ,
F_63 ( V_2 -> V_66 ) -> V_59 ) ;
error = - V_263 ;
goto V_63;
case V_321 :
F_38 ( L_77 ,
V_144 -> V_218 , V_37 ) ;
break;
default:
F_38 ( L_78 ,
V_144 -> V_218 , V_37 , V_301 ) ;
}
V_305:
V_2 -> V_76 -> V_322 ++ ;
if ( V_144 -> V_315 ) {
V_144 -> V_315 -- ;
F_38 ( L_79 ,
V_144 -> V_218 , V_37 ) ;
V_144 -> V_161 = V_237 ;
V_293:
return F_55 ( - V_224 ) ;
}
V_302:
error = - V_137 ;
V_63:
F_71 ( V_144 , error ) ;
F_38 ( L_80 , V_144 -> V_218 ,
V_37 , error ) ;
return F_55 ( error ) ;
V_303:
F_38 ( L_81 , V_144 -> V_218 ,
V_37 ) ;
goto V_305;
}
static void F_166 ( void * V_323 , struct V_324 * V_325 , void * V_326 )
{
}
static int F_167 ( void * V_323 , struct V_324 * V_325 , void * V_326 )
{
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_150 V_151 = {
. V_153 = & V_327 ,
} ;
int V_31 ;
V_151 . V_156 = V_328 . V_329 ( NULL , NULL , 0 ) ;
V_31 = F_96 ( V_2 , & V_151 , V_147 | V_330 ) ;
F_168 ( V_151 . V_156 ) ;
return V_31 ;
}
struct V_133 * F_169 ( struct V_1 * V_2 , struct V_156 * V_331 , int V_120 )
{
struct V_150 V_151 = {
. V_153 = & V_327 ,
. V_156 = V_331 ,
} ;
struct V_158 V_159 = {
. V_160 = V_2 ,
. V_150 = & V_151 ,
. V_163 = & V_164 ,
. V_120 = V_120 ,
} ;
return F_92 ( & V_159 ) ;
}
static void F_170 ( void )
{
F_21 ( V_27 L_82
L_83 ) ;
}
static void F_171 ( const struct V_1 * V_2 ,
const struct V_133 * V_144 )
{
const char * V_332 = L_84 ;
if ( F_72 ( V_144 ) )
V_332 = F_172 ( V_144 -> V_138 ) ;
F_21 ( V_27 L_85 ,
V_144 -> V_218 , V_144 -> V_135 , V_144 -> V_168 ,
V_2 , V_144 -> V_176 , V_144 -> V_259 , V_144 -> V_170 ,
V_2 -> V_71 , V_2 -> V_75 , F_126 ( V_144 ) ,
V_144 -> V_161 , V_332 ) ;
}
void F_173 ( struct V_3 * V_3 )
{
struct V_1 * V_2 ;
struct V_133 * V_144 ;
int V_333 = 0 ;
struct V_4 * V_5 = F_3 ( V_3 , V_6 ) ;
F_4 ( & V_5 -> V_7 ) ;
F_28 (clnt, &sn->all_clients, cl_clients) {
F_4 ( & V_2 -> V_81 ) ;
F_28 (task, &clnt->cl_tasks, tk_task) {
if ( ! V_333 ) {
F_170 () ;
V_333 ++ ;
}
F_171 ( V_2 , V_144 ) ;
}
F_6 ( & V_2 -> V_81 ) ;
}
F_6 ( & V_5 -> V_7 ) ;
}
