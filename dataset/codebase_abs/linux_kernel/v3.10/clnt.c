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
F_38 ( L_7 ,
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
if ( args -> V_106 & V_107 )
V_96 . V_106 |= V_108 ;
if ( args -> V_106 & V_109 )
V_96 . V_106 |= V_110 ;
if ( V_96 . V_59 == NULL ) {
struct V_111 * V_112 =
(struct V_111 * ) args -> V_102 ;
struct V_113 * sin =
(struct V_113 * ) args -> V_102 ;
struct V_114 * V_115 =
(struct V_114 * ) args -> V_102 ;
V_59 [ 0 ] = '\0' ;
switch ( args -> V_102 -> V_116 ) {
case V_117 :
snprintf ( V_59 , sizeof( V_59 ) , L_8 ,
V_112 -> V_118 ) ;
break;
case V_119 :
snprintf ( V_59 , sizeof( V_59 ) , L_9 ,
& sin -> V_120 . V_121 ) ;
break;
case V_122 :
snprintf ( V_59 , sizeof( V_59 ) , L_10 ,
& V_115 -> V_123 ) ;
break;
default:
return F_55 ( - V_61 ) ;
}
V_96 . V_59 = V_59 ;
}
V_52 = F_57 ( & V_96 ) ;
if ( F_19 ( V_52 ) )
return (struct V_1 * ) V_52 ;
V_52 -> V_124 = 1 ;
if ( args -> V_106 & V_125 )
V_52 -> V_124 = 0 ;
V_2 = F_37 ( args , V_52 ) ;
if ( F_19 ( V_2 ) )
return V_2 ;
if ( ! ( args -> V_106 & V_126 ) ) {
int V_31 = F_58 ( V_2 ) ;
if ( V_31 != 0 ) {
F_59 ( V_2 ) ;
return F_55 ( V_31 ) ;
}
}
V_2 -> V_127 = 1 ;
if ( args -> V_106 & V_128 )
V_2 -> V_127 = 0 ;
if ( args -> V_106 & V_129 )
V_2 -> V_82 = 1 ;
if ( args -> V_106 & V_130 )
V_2 -> V_131 = 1 ;
if ( ! ( args -> V_106 & V_132 ) )
V_2 -> V_133 = 1 ;
return V_2 ;
}
static struct V_1 * F_60 ( struct V_50 * args ,
struct V_1 * V_2 )
{
struct V_51 * V_52 ;
struct V_1 * V_134 ;
int V_31 ;
V_31 = - V_64 ;
F_61 () ;
V_52 = F_62 ( F_63 ( V_2 -> V_66 ) ) ;
F_64 () ;
if ( V_52 == NULL )
goto V_63;
args -> V_59 = V_52 -> V_59 ;
V_134 = F_37 ( args , V_52 ) ;
if ( F_19 ( V_134 ) ) {
V_31 = F_20 ( V_134 ) ;
goto V_63;
}
F_65 ( & V_2 -> V_40 ) ;
V_134 -> V_39 = V_2 ;
V_134 -> V_82 = 0 ;
V_134 -> V_127 = V_2 -> V_127 ;
V_134 -> V_131 = V_2 -> V_131 ;
V_134 -> V_133 = V_2 -> V_133 ;
return V_134 ;
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
. V_93 = V_2 -> V_11 -> V_135 ,
. V_90 = V_2 -> V_89 ,
} ;
return F_60 ( & args , V_2 ) ;
}
struct V_1 *
F_67 ( struct V_1 * V_2 , T_2 V_136 )
{
struct V_50 args = {
. V_54 = V_2 -> V_32 ,
. V_73 = V_2 -> V_72 ,
. V_56 = V_2 -> V_75 ,
. V_93 = V_136 ,
. V_90 = V_2 -> V_89 ,
} ;
return F_60 ( & args , V_2 ) ;
}
void F_68 ( struct V_1 * V_2 )
{
struct V_137 * V_138 ;
if ( F_69 ( & V_2 -> V_80 ) )
return;
F_38 ( L_12 , V_2 ) ;
F_4 ( & V_2 -> V_81 ) ;
F_28 (rovr, &clnt->cl_tasks, tk_task) {
if ( ! F_70 ( V_138 ) )
continue;
if ( ! ( V_138 -> V_139 & V_140 ) ) {
V_138 -> V_139 |= V_140 ;
F_71 ( V_138 , - V_141 ) ;
if ( F_72 ( V_138 ) )
F_73 ( V_138 -> V_142 ,
V_138 ) ;
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
F_76 ( V_143 ,
F_69 ( & V_2 -> V_80 ) , 1 * V_144 ) ;
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
F_82 ( & V_143 ) ;
if ( F_81 ( & V_2 -> V_40 ) )
F_79 ( V_2 ) ;
}
struct V_1 * F_83 ( struct V_1 * V_145 ,
const struct V_53 * V_54 ,
T_3 V_146 )
{
struct V_50 args = {
. V_54 = V_54 ,
. V_73 = V_54 -> V_74 ,
. V_56 = V_146 ,
. V_93 = V_145 -> V_11 -> V_135 ,
. V_90 = V_145 -> V_89 ,
} ;
struct V_1 * V_2 ;
int V_31 ;
V_2 = F_60 ( & args , V_145 ) ;
if ( F_19 ( V_2 ) )
goto V_147;
V_31 = F_58 ( V_2 ) ;
if ( V_31 != 0 ) {
F_59 ( V_2 ) ;
V_2 = F_55 ( V_31 ) ;
}
V_147:
return V_2 ;
}
void F_84 ( struct V_137 * V_148 )
{
struct V_1 * V_2 = V_148 -> V_149 ;
if ( V_2 != NULL ) {
F_4 ( & V_2 -> V_81 ) ;
F_8 ( & V_148 -> V_150 ) ;
F_6 ( & V_2 -> V_81 ) ;
V_148 -> V_149 = NULL ;
F_31 ( V_2 ) ;
}
}
static
void F_85 ( struct V_137 * V_148 , struct V_1 * V_2 )
{
if ( V_2 != NULL ) {
F_84 ( V_148 ) ;
V_148 -> V_149 = V_2 ;
F_65 ( & V_2 -> V_40 ) ;
if ( V_2 -> V_127 )
V_148 -> V_139 |= V_151 ;
if ( F_86 () ) {
struct V_51 * V_52 ;
F_61 () ;
V_52 = F_63 ( V_2 -> V_66 ) ;
if ( V_52 -> V_152 )
V_148 -> V_139 |= V_153 ;
F_64 () ;
}
F_4 ( & V_2 -> V_81 ) ;
F_87 ( & V_148 -> V_150 , & V_2 -> V_80 ) ;
F_6 ( & V_2 -> V_81 ) ;
}
}
void F_88 ( struct V_137 * V_148 , struct V_1 * V_2 )
{
F_84 ( V_148 ) ;
F_85 ( V_148 , V_2 ) ;
}
static void
F_89 ( struct V_137 * V_148 , const struct V_154 * V_155 )
{
if ( V_155 != NULL ) {
V_148 -> V_156 . V_157 = V_155 -> V_157 ;
V_148 -> V_156 . V_158 = V_155 -> V_158 ;
V_148 -> V_156 . V_159 = V_155 -> V_159 ;
if ( V_155 -> V_160 != NULL )
V_148 -> V_156 . V_160 = F_90 ( V_155 -> V_160 ) ;
}
}
static void
F_91 ( struct V_137 * V_148 , void * V_161 )
{
}
struct V_137 * F_92 ( const struct V_162 * V_163 )
{
struct V_137 * V_148 ;
V_148 = F_93 ( V_163 ) ;
if ( F_19 ( V_148 ) )
goto V_147;
F_85 ( V_148 , V_163 -> V_164 ) ;
F_89 ( V_148 , V_163 -> V_154 ) ;
if ( V_148 -> V_165 == NULL )
F_94 ( V_148 ) ;
F_65 ( & V_148 -> V_166 ) ;
F_95 ( V_148 ) ;
V_147:
return V_148 ;
}
int F_96 ( struct V_1 * V_2 , const struct V_154 * V_155 , int V_106 )
{
struct V_137 * V_148 ;
struct V_162 V_163 = {
. V_164 = V_2 ,
. V_154 = V_155 ,
. V_167 = & V_168 ,
. V_106 = V_106 ,
} ;
int V_169 ;
F_97 ( V_106 & V_170 ) ;
if ( V_106 & V_170 ) {
F_98 ( V_163 . V_167 ,
V_163 . V_171 ) ;
return - V_61 ;
}
V_148 = F_92 ( & V_163 ) ;
if ( F_19 ( V_148 ) )
return F_20 ( V_148 ) ;
V_169 = V_148 -> V_172 ;
F_99 ( V_148 ) ;
return V_169 ;
}
int
F_100 ( struct V_1 * V_2 , const struct V_154 * V_155 , int V_106 ,
const struct V_173 * V_174 , void * V_161 )
{
struct V_137 * V_148 ;
struct V_162 V_163 = {
. V_164 = V_2 ,
. V_154 = V_155 ,
. V_167 = V_174 ,
. V_171 = V_161 ,
. V_106 = V_106 | V_170 ,
} ;
V_148 = F_92 ( & V_163 ) ;
if ( F_19 ( V_148 ) )
return F_20 ( V_148 ) ;
F_99 ( V_148 ) ;
return 0 ;
}
struct V_137 * F_101 ( struct V_175 * V_176 ,
const struct V_173 * V_174 )
{
struct V_137 * V_148 ;
struct V_177 * V_178 = & V_176 -> V_179 ;
struct V_162 V_163 = {
. V_167 = V_174 ,
} ;
F_38 ( L_16 , V_176 ) ;
V_148 = F_93 ( & V_163 ) ;
if ( F_19 ( V_148 ) ) {
F_102 ( V_176 ) ;
goto V_147;
}
V_148 -> V_180 = V_176 ;
V_178 -> V_24 = V_178 -> V_181 [ 0 ] . V_182 + V_178 -> V_183 +
V_178 -> V_184 [ 0 ] . V_182 ;
V_148 -> V_165 = V_185 ;
F_65 ( & V_148 -> V_166 ) ;
F_97 ( F_103 ( & V_148 -> V_166 ) != 2 ) ;
F_95 ( V_148 ) ;
V_147:
F_38 ( L_17 , V_148 ) ;
return V_148 ;
}
void
F_94 ( struct V_137 * V_148 )
{
V_148 -> V_165 = V_186 ;
}
T_4 F_104 ( struct V_1 * V_2 , struct V_187 * V_188 , T_4 V_189 )
{
T_4 V_190 ;
struct V_51 * V_52 ;
F_61 () ;
V_52 = F_63 ( V_2 -> V_66 ) ;
V_190 = V_52 -> V_103 ;
if ( V_190 > V_189 )
V_190 = V_189 ;
memcpy ( V_188 , & V_52 -> V_191 , V_190 ) ;
F_64 () ;
return V_190 ;
}
const char * F_105 ( struct V_1 * V_2 ,
enum V_192 V_193 )
{
struct V_51 * V_52 ;
V_52 = F_63 ( V_2 -> V_66 ) ;
if ( V_52 -> V_194 [ V_193 ] != NULL )
return V_52 -> V_194 [ V_193 ] ;
else
return L_18 ;
}
static int F_106 ( struct V_3 * V_3 , struct V_187 * V_195 , T_4 V_196 ,
struct V_187 * V_188 , int V_197 )
{
struct V_198 * V_199 ;
int V_31 ;
V_31 = F_107 ( V_3 , V_195 -> V_116 ,
V_200 , V_201 , & V_199 , 1 ) ;
if ( V_31 < 0 ) {
F_38 ( L_19 , V_31 ) ;
goto V_147;
}
switch ( V_195 -> V_116 ) {
case V_119 :
V_31 = F_108 ( V_199 ,
(struct V_187 * ) & V_202 ,
sizeof( V_202 ) ) ;
break;
case V_122 :
V_31 = F_108 ( V_199 ,
(struct V_187 * ) & V_203 ,
sizeof( V_203 ) ) ;
break;
default:
V_31 = - V_204 ;
goto V_147;
}
if ( V_31 < 0 ) {
F_38 ( L_20 , V_31 ) ;
goto V_205;
}
V_31 = F_109 ( V_199 , V_195 , V_196 , 0 ) ;
if ( V_31 < 0 ) {
F_38 ( L_21 , V_31 ) ;
goto V_205;
}
V_31 = F_110 ( V_199 , V_188 , & V_197 ) ;
if ( V_31 < 0 ) {
F_38 ( L_22 , V_31 ) ;
goto V_205;
}
V_31 = 0 ;
if ( V_188 -> V_116 == V_122 ) {
struct V_114 * V_115 = (struct V_114 * ) V_188 ;
V_115 -> V_206 = 0 ;
}
F_38 ( L_23 , V_37 ) ;
V_205:
F_111 ( V_199 ) ;
V_147:
return V_31 ;
}
static int F_112 ( int V_207 , struct V_187 * V_188 , T_4 V_197 )
{
switch ( V_207 ) {
case V_119 :
if ( V_197 < sizeof( V_202 ) )
return - V_61 ;
memcpy ( V_188 , & V_202 ,
sizeof( V_202 ) ) ;
break;
case V_122 :
if ( V_197 < sizeof( V_203 ) )
return - V_61 ;
memcpy ( V_188 , & V_203 ,
sizeof( V_203 ) ) ;
default:
F_38 ( L_24 ,
V_37 ) ;
return - V_204 ;
}
F_38 ( L_25 , V_37 ) ;
return 0 ;
}
int F_113 ( struct V_1 * V_2 , struct V_187 * V_188 , T_4 V_197 )
{
struct V_208 V_102 ;
struct V_187 * V_195 = (struct V_187 * ) & V_102 ;
struct V_51 * V_52 ;
struct V_3 * V_3 ;
T_4 V_196 ;
int V_31 ;
F_61 () ;
V_52 = F_63 ( V_2 -> V_66 ) ;
V_196 = V_52 -> V_103 ;
memcpy ( V_195 , & V_52 -> V_191 , V_196 ) ;
V_3 = F_114 ( V_52 -> V_209 ) ;
F_64 () ;
F_115 ( V_195 , 0 ) ;
V_31 = F_106 ( V_3 , V_195 , V_196 , V_188 , V_197 ) ;
F_116 ( V_3 ) ;
if ( V_31 != 0 )
return F_112 ( V_195 -> V_116 , V_188 , V_197 ) ;
return 0 ;
}
void
F_117 ( struct V_1 * V_2 , unsigned int V_210 , unsigned int V_211 )
{
struct V_51 * V_52 ;
F_61 () ;
V_52 = F_63 ( V_2 -> V_66 ) ;
if ( V_52 -> V_212 -> V_213 )
V_52 -> V_212 -> V_213 ( V_52 , V_210 , V_211 ) ;
F_64 () ;
}
int F_118 ( struct V_1 * V_2 )
{
int V_98 ;
F_61 () ;
V_98 = F_63 ( V_2 -> V_66 ) -> V_214 ;
F_64 () ;
return V_98 ;
}
struct V_3 * F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_215 ;
F_61 () ;
V_215 = F_63 ( V_2 -> V_66 ) -> V_209 ;
F_64 () ;
return V_215 ;
}
T_4 F_119 ( struct V_1 * V_2 )
{
T_4 V_215 ;
F_61 () ;
V_215 = F_63 ( V_2 -> V_66 ) -> V_216 ;
F_64 () ;
return V_215 ;
}
unsigned long F_120 ( struct V_1 * V_2 )
{
unsigned long V_215 ;
F_61 () ;
V_215 = F_63 ( V_2 -> V_66 ) -> V_84 -> V_88 ;
F_64 () ;
return V_215 ;
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
F_123 ( struct V_137 * V_148 )
{
if ( F_124 ( V_148 ) )
return 0 ;
V_148 -> V_165 = V_186 ;
if ( V_148 -> V_174 -> V_217 != NULL )
V_148 -> V_165 = V_218 ;
return 1 ;
}
int
F_125 ( struct V_137 * V_148 )
{
if ( F_124 ( V_148 ) )
return 0 ;
V_148 -> V_165 = V_186 ;
return 1 ;
}
static const char * F_126 ( const struct V_137 * V_148 )
{
const struct V_219 * V_220 = V_148 -> V_156 . V_157 ;
if ( V_220 ) {
if ( V_220 -> V_221 )
return V_220 -> V_221 ;
else
return L_26 ;
} else
return L_27 ;
}
static void
V_186 ( struct V_137 * V_148 )
{
struct V_1 * V_2 = V_148 -> V_149 ;
F_38 ( L_28 , V_148 -> V_222 ,
V_2 -> V_71 , V_2 -> V_75 ,
F_126 ( V_148 ) ,
( F_127 ( V_148 ) ? L_29 : L_30 ) ) ;
V_148 -> V_156 . V_157 -> V_223 ++ ;
V_2 -> V_76 -> V_224 ++ ;
V_148 -> V_165 = V_225 ;
}
static void
V_225 ( struct V_137 * V_148 )
{
F_128 ( V_148 ) ;
V_148 -> V_172 = 0 ;
V_148 -> V_165 = V_226 ;
F_129 ( V_148 ) ;
}
static void
V_226 ( struct V_137 * V_148 )
{
int V_169 = V_148 -> V_172 ;
F_128 ( V_148 ) ;
V_148 -> V_172 = 0 ;
if ( V_169 >= 0 ) {
if ( V_148 -> V_180 ) {
V_148 -> V_165 = V_227 ;
return;
}
F_21 ( V_36 L_31 ,
V_37 , V_169 ) ;
F_71 ( V_148 , - V_141 ) ;
return;
}
if ( V_148 -> V_180 ) {
F_21 ( V_36 L_32 ,
V_37 , V_169 ) ;
F_130 ( V_148 ) ;
}
switch ( V_169 ) {
case - V_64 :
F_131 ( V_148 , V_144 >> 2 ) ;
case - V_228 :
V_148 -> V_165 = V_229 ;
return;
case - V_141 :
break;
default:
F_21 ( V_36 L_33 ,
V_37 , V_169 ) ;
break;
}
F_71 ( V_148 , V_169 ) ;
}
static void
V_229 ( struct V_137 * V_148 )
{
F_128 ( V_148 ) ;
V_148 -> V_172 = 0 ;
V_148 -> V_165 = V_226 ;
F_132 ( V_148 ) ;
}
static void
V_227 ( struct V_137 * V_148 )
{
F_128 ( V_148 ) ;
V_148 -> V_165 = V_230 ;
V_148 -> V_172 = 0 ;
V_148 -> V_149 -> V_76 -> V_231 ++ ;
F_133 ( V_148 ) ;
}
static void
V_230 ( struct V_137 * V_148 )
{
int V_169 = V_148 -> V_172 ;
F_128 ( V_148 ) ;
V_148 -> V_172 = 0 ;
V_148 -> V_165 = V_227 ;
switch ( V_169 ) {
case 0 :
if ( F_134 ( V_148 ) )
V_148 -> V_165 = V_232 ;
return;
case - V_233 :
F_131 ( V_148 , 3 * V_144 ) ;
case - V_234 :
case - V_228 :
V_169 = - V_235 ;
if ( ! V_148 -> V_236 )
break;
V_148 -> V_236 -- ;
F_38 ( L_34 ,
V_148 -> V_222 , V_37 ) ;
return;
}
F_38 ( L_35 ,
V_148 -> V_222 , V_37 , V_169 ) ;
F_71 ( V_148 , V_169 ) ;
}
static void
V_232 ( struct V_137 * V_148 )
{
unsigned int V_237 = V_148 -> V_180 -> V_238 -> V_239 -> V_240 ;
struct V_175 * V_176 = V_148 -> V_180 ;
struct V_51 * V_52 = V_176 -> V_241 ;
struct V_219 * V_220 = V_148 -> V_156 . V_157 ;
F_128 ( V_148 ) ;
V_148 -> V_172 = 0 ;
V_148 -> V_165 = V_242 ;
if ( V_176 -> V_243 )
return;
if ( V_220 -> V_244 != 0 ) {
F_135 ( V_220 -> V_245 == 0 ) ;
if ( V_220 -> V_246 != NULL )
F_135 ( V_220 -> V_247 == 0 ) ;
}
V_176 -> V_248 = V_249 + ( V_237 << 1 ) + V_220 -> V_245 ;
V_176 -> V_248 <<= 2 ;
V_176 -> V_250 = V_251 + V_237 + V_220 -> V_247 ;
V_176 -> V_250 <<= 2 ;
V_176 -> V_243 = V_52 -> V_212 -> V_252 ( V_148 ,
V_176 -> V_248 + V_176 -> V_250 ) ;
if ( V_176 -> V_243 != NULL )
return;
F_38 ( L_36 , V_148 -> V_222 ) ;
if ( F_127 ( V_148 ) || ! F_136 ( V_253 ) ) {
V_148 -> V_165 = V_232 ;
F_131 ( V_148 , V_144 >> 4 ) ;
return;
}
F_71 ( V_148 , - V_254 ) ;
}
static inline int
F_137 ( struct V_137 * V_148 )
{
return V_148 -> V_180 -> V_179 . V_24 == 0 ;
}
static inline void
F_138 ( struct V_137 * V_148 )
{
V_148 -> V_180 -> V_179 . V_24 = 0 ;
V_148 -> V_180 -> V_255 = 0 ;
}
static inline void
F_139 ( struct V_177 * V_188 , void * V_256 , T_4 V_24 )
{
V_188 -> V_181 [ 0 ] . V_257 = V_256 ;
V_188 -> V_181 [ 0 ] . V_182 = V_24 ;
V_188 -> V_184 [ 0 ] . V_182 = 0 ;
V_188 -> V_183 = 0 ;
V_188 -> V_106 = 0 ;
V_188 -> V_24 = 0 ;
V_188 -> V_197 = V_24 ;
}
static void
F_140 ( struct V_137 * V_148 )
{
struct V_175 * V_176 = V_148 -> V_180 ;
T_5 V_258 ;
T_6 * V_259 ;
F_128 ( V_148 ) ;
F_139 ( & V_176 -> V_179 ,
V_176 -> V_243 ,
V_176 -> V_248 ) ;
F_139 ( & V_176 -> V_260 ,
( char * ) V_176 -> V_243 + V_176 -> V_248 ,
V_176 -> V_250 ) ;
V_259 = F_141 ( V_148 ) ;
if ( V_259 == NULL ) {
F_21 ( V_27 L_37 ) ;
F_71 ( V_148 , - V_141 ) ;
return;
}
V_258 = V_148 -> V_156 . V_157 -> V_261 ;
if ( V_258 == NULL )
return;
V_148 -> V_172 = F_142 ( V_148 , V_258 , V_176 , V_259 ,
V_148 -> V_156 . V_158 ) ;
}
static void
V_242 ( struct V_137 * V_148 )
{
struct V_51 * V_52 = V_148 -> V_180 -> V_241 ;
F_128 ( V_148 ) ;
V_148 -> V_165 = V_262 ;
if ( ! F_45 ( V_52 ) ) {
V_148 -> V_165 = V_263 ;
V_148 -> V_264 = V_52 -> V_265 ;
V_52 -> V_212 -> V_266 ( V_148 ) ;
}
}
static void
V_263 ( struct V_137 * V_148 )
{
int V_169 = - V_141 ;
if ( V_148 -> V_172 >= 0 ) {
F_128 ( V_148 ) ;
V_148 -> V_172 = 0 ;
V_148 -> V_165 = V_262 ;
return;
}
F_143 ( V_148 ) ;
switch ( V_148 -> V_172 ) {
case - V_64 :
F_38 ( L_38 , V_148 -> V_222 ) ;
F_131 ( V_148 , V_144 >> 2 ) ;
goto V_267;
case - V_235 :
F_38 ( L_39
L_40 , V_148 -> V_222 ) ;
if ( V_148 -> V_156 . V_157 -> V_244 == 0 ) {
V_169 = - V_268 ;
break;
}
if ( V_148 -> V_269 == 0 )
break;
V_148 -> V_269 -- ;
F_131 ( V_148 , 3 * V_144 ) ;
goto V_267;
case - V_233 :
F_38 ( L_41 ,
V_148 -> V_222 ) ;
goto V_267;
case - V_270 :
F_38 ( L_42 ,
V_148 -> V_222 ) ;
break;
case - V_271 :
F_38 ( L_43 ,
V_148 -> V_222 ) ;
V_148 -> V_172 = 0 ;
V_148 -> V_165 = V_242 ;
return;
case - V_272 :
case - V_273 :
case - V_274 :
case - V_275 :
case - V_276 :
case - V_277 :
case - V_278 :
F_38 ( L_44 ,
V_148 -> V_222 , V_148 -> V_172 ) ;
if ( ! F_144 ( V_148 ) ) {
F_131 ( V_148 , 5 * V_144 ) ;
goto V_267;
}
V_169 = V_148 -> V_172 ;
break;
default:
F_38 ( L_45 ,
V_148 -> V_222 , - V_148 -> V_172 ) ;
}
F_71 ( V_148 , V_169 ) ;
return;
V_267:
V_148 -> V_165 = V_279 ;
}
static void
V_262 ( struct V_137 * V_148 )
{
struct V_51 * V_52 = V_148 -> V_180 -> V_241 ;
F_38 ( L_46 ,
V_148 -> V_222 , V_52 ,
( F_145 ( V_52 ) ? L_47 : L_48 ) ) ;
V_148 -> V_165 = V_280 ;
if ( ! F_145 ( V_52 ) ) {
V_148 -> V_165 = V_281 ;
if ( V_148 -> V_172 < 0 )
return;
F_146 ( V_148 ) ;
}
}
static void
V_281 ( struct V_137 * V_148 )
{
struct V_1 * V_2 = V_148 -> V_149 ;
int V_169 = V_148 -> V_172 ;
F_128 ( V_148 ) ;
F_147 ( V_148 , V_169 ) ;
switch ( V_169 ) {
case - V_233 :
V_148 -> V_165 = V_279 ;
return;
case - V_272 :
case - V_273 :
case - V_277 :
if ( F_144 ( V_148 ) )
break;
case 0 :
case - V_228 :
V_148 -> V_172 = 0 ;
V_2 -> V_76 -> V_282 ++ ;
V_148 -> V_165 = V_280 ;
return;
}
F_71 ( V_148 , V_169 ) ;
}
static void
V_280 ( struct V_137 * V_148 )
{
F_128 ( V_148 ) ;
V_148 -> V_165 = V_283 ;
if ( V_148 -> V_172 < 0 )
return;
V_148 -> V_172 = F_148 ( V_148 ) ;
if ( V_148 -> V_172 != 0 )
return;
V_148 -> V_165 = V_284 ;
if ( F_137 ( V_148 ) ) {
F_140 ( V_148 ) ;
if ( V_148 -> V_172 != 0 ) {
if ( V_148 -> V_172 == - V_228 )
F_131 ( V_148 , V_144 >> 4 ) ;
else
F_71 ( V_148 , V_148 -> V_172 ) ;
return;
}
}
F_149 ( V_148 ) ;
if ( V_148 -> V_172 < 0 )
return;
V_284 ( V_148 ) ;
if ( F_150 ( V_148 ) )
return;
V_148 -> V_165 = V_285 ;
F_73 ( & V_148 -> V_180 -> V_241 -> V_286 , V_148 ) ;
}
static void
V_284 ( struct V_137 * V_148 )
{
V_148 -> V_165 = V_283 ;
if ( V_148 -> V_172 == 0 ) {
F_151 ( V_148 ) ;
F_138 ( V_148 ) ;
return;
}
switch ( V_148 -> V_172 ) {
case - V_228 :
break;
default:
F_128 ( V_148 ) ;
F_151 ( V_148 ) ;
F_138 ( V_148 ) ;
break;
case - V_272 :
case - V_275 :
case - V_276 :
case - V_277 :
if ( F_144 ( V_148 ) ) {
F_151 ( V_148 ) ;
F_71 ( V_148 , V_148 -> V_172 ) ;
break;
}
case - V_273 :
case - V_274 :
case - V_278 :
F_138 ( V_148 ) ;
}
}
static void
V_185 ( struct V_137 * V_148 )
{
struct V_175 * V_176 = V_148 -> V_180 ;
V_148 -> V_172 = F_148 ( V_148 ) ;
if ( V_148 -> V_172 == - V_228 ) {
V_148 -> V_172 = 0 ;
V_148 -> V_165 = V_185 ;
return;
}
V_148 -> V_165 = V_285 ;
if ( V_148 -> V_172 < 0 ) {
F_21 ( V_287 L_49
L_50 , V_148 -> V_172 ) ;
return;
}
F_149 ( V_148 ) ;
F_151 ( V_148 ) ;
F_128 ( V_148 ) ;
switch ( V_148 -> V_172 ) {
case 0 :
break;
case - V_275 :
case - V_276 :
case - V_277 :
case - V_233 :
F_21 ( V_287 L_49
L_50 , V_148 -> V_172 ) ;
F_152 ( V_176 -> V_241 ,
V_176 -> V_288 ) ;
break;
default:
F_97 ( V_148 -> V_172 == - V_228 ) ;
F_21 ( V_287 L_49
L_50 , V_148 -> V_172 ) ;
break;
}
F_73 ( & V_176 -> V_241 -> V_286 , V_148 ) ;
}
static void
V_283 ( struct V_137 * V_148 )
{
struct V_1 * V_2 = V_148 -> V_149 ;
struct V_175 * V_176 = V_148 -> V_180 ;
int V_169 ;
if ( V_176 -> V_289 > 0 && ! V_176 -> V_255 )
V_148 -> V_172 = V_176 -> V_289 ;
F_128 ( V_148 ) ;
V_169 = V_148 -> V_172 ;
if ( V_169 >= 0 ) {
V_148 -> V_165 = V_290 ;
return;
}
F_153 ( V_148 ) ;
V_148 -> V_172 = 0 ;
switch( V_169 ) {
case - V_275 :
case - V_276 :
case - V_277 :
F_131 ( V_148 , 3 * V_144 ) ;
case - V_233 :
V_148 -> V_165 = V_279 ;
if ( V_148 -> V_149 -> V_131 )
F_152 ( V_176 -> V_241 ,
V_176 -> V_288 ) ;
break;
case - V_273 :
case - V_272 :
F_121 ( V_2 ) ;
F_131 ( V_148 , 3 * V_144 ) ;
case - V_278 :
case - V_274 :
V_148 -> V_165 = V_242 ;
break;
case - V_228 :
V_148 -> V_165 = V_280 ;
break;
case - V_141 :
F_71 ( V_148 , V_169 ) ;
break;
default:
if ( V_2 -> V_133 )
F_21 ( L_51 ,
V_2 -> V_71 , - V_169 ) ;
F_71 ( V_148 , V_169 ) ;
}
}
static void
V_279 ( struct V_137 * V_148 )
{
struct V_1 * V_2 = V_148 -> V_149 ;
if ( F_154 ( V_148 -> V_180 ) == 0 ) {
F_38 ( L_52 , V_148 -> V_222 ) ;
goto V_291;
}
F_38 ( L_53 , V_148 -> V_222 ) ;
V_148 -> V_292 ++ ;
if ( F_144 ( V_148 ) ) {
F_71 ( V_148 , - V_233 ) ;
return;
}
if ( F_155 ( V_148 ) ) {
if ( V_2 -> V_133 ) {
F_61 () ;
F_21 ( V_287 L_54 ,
V_2 -> V_71 ,
F_63 ( V_2 -> V_66 ) -> V_59 ) ;
F_64 () ;
}
if ( V_148 -> V_139 & V_293 )
F_71 ( V_148 , - V_233 ) ;
else
F_71 ( V_148 , - V_141 ) ;
return;
}
if ( ! ( V_148 -> V_139 & V_294 ) ) {
V_148 -> V_139 |= V_294 ;
if ( V_2 -> V_133 ) {
F_61 () ;
F_21 ( V_287 L_55 ,
V_2 -> V_71 ,
F_63 ( V_2 -> V_66 ) -> V_59 ) ;
F_64 () ;
}
}
F_121 ( V_2 ) ;
F_156 ( V_148 ) ;
V_291:
V_2 -> V_76 -> V_295 ++ ;
V_148 -> V_165 = V_242 ;
V_148 -> V_172 = 0 ;
}
static void
V_290 ( struct V_137 * V_148 )
{
struct V_1 * V_2 = V_148 -> V_149 ;
struct V_175 * V_176 = V_148 -> V_180 ;
T_7 V_296 = V_148 -> V_156 . V_157 -> V_246 ;
T_6 * V_259 ;
F_128 ( V_148 ) ;
if ( V_148 -> V_139 & V_294 ) {
if ( V_2 -> V_133 ) {
F_61 () ;
F_21 ( V_287 L_56 ,
V_2 -> V_71 ,
F_63 ( V_2 -> V_66 ) -> V_59 ) ;
F_64 () ;
}
V_148 -> V_139 &= ~ V_294 ;
}
F_157 () ;
V_176 -> V_260 . V_24 = V_176 -> V_297 . V_24 ;
F_158 ( memcmp ( & V_176 -> V_260 , & V_176 -> V_297 ,
sizeof( V_176 -> V_260 ) ) != 0 ) ;
if ( V_176 -> V_260 . V_24 < 12 ) {
if ( ! F_155 ( V_148 ) ) {
V_148 -> V_165 = V_242 ;
V_2 -> V_76 -> V_295 ++ ;
goto V_298;
}
F_38 ( L_57 ,
V_2 -> V_71 , V_148 -> V_172 ) ;
V_148 -> V_165 = V_279 ;
goto V_298;
}
V_259 = F_159 ( V_148 ) ;
if ( F_19 ( V_259 ) ) {
if ( V_259 == F_55 ( - V_228 ) )
goto V_298;
return;
}
V_148 -> V_165 = V_285 ;
if ( V_296 ) {
V_148 -> V_172 = F_160 ( V_148 , V_296 , V_176 , V_259 ,
V_148 -> V_156 . V_159 ) ;
}
F_38 ( L_58 , V_148 -> V_222 ,
V_148 -> V_172 ) ;
return;
V_298:
V_148 -> V_172 = 0 ;
if ( V_148 -> V_180 == V_176 ) {
V_176 -> V_289 = V_176 -> V_260 . V_24 = 0 ;
if ( V_148 -> V_149 -> V_131 )
F_152 ( V_176 -> V_241 ,
V_176 -> V_288 ) ;
}
}
static T_6 *
F_141 ( struct V_137 * V_148 )
{
struct V_1 * V_2 = V_148 -> V_149 ;
struct V_175 * V_176 = V_148 -> V_180 ;
T_6 * V_259 = V_176 -> V_299 [ 0 ] . V_257 ;
V_259 = F_161 ( V_176 -> V_241 , V_259 ) ;
* V_259 ++ = V_176 -> V_300 ;
* V_259 ++ = F_162 ( V_301 ) ;
* V_259 ++ = F_162 ( V_302 ) ;
* V_259 ++ = F_162 ( V_2 -> V_72 ) ;
* V_259 ++ = F_162 ( V_2 -> V_75 ) ;
* V_259 ++ = F_162 ( V_148 -> V_156 . V_157 -> V_244 ) ;
V_259 = F_163 ( V_148 , V_259 ) ;
V_176 -> V_303 = F_164 ( & V_176 -> V_299 [ 0 ] , V_259 ) ;
return V_259 ;
}
static T_6 *
F_159 ( struct V_137 * V_148 )
{
struct V_1 * V_2 = V_148 -> V_149 ;
struct V_304 * V_305 = & V_148 -> V_180 -> V_260 . V_181 [ 0 ] ;
int V_24 = V_148 -> V_180 -> V_260 . V_24 >> 2 ;
T_6 * V_259 = V_305 -> V_257 ;
T_3 V_306 ;
int error = - V_235 ;
if ( ( V_148 -> V_180 -> V_260 . V_24 & 3 ) != 0 ) {
F_38 ( L_59
L_60 , V_148 -> V_222 , V_37 ,
V_148 -> V_180 -> V_260 . V_24 ) ;
goto V_307;
}
if ( ( V_24 -= 3 ) < 0 )
goto V_308;
V_259 += 1 ;
if ( ( V_306 = F_165 ( * V_259 ++ ) ) != V_309 ) {
F_38 ( L_61 ,
V_148 -> V_222 , V_37 , V_306 ) ;
goto V_310;
}
if ( ( V_306 = F_165 ( * V_259 ++ ) ) != V_311 ) {
if ( -- V_24 < 0 )
goto V_308;
switch ( ( V_306 = F_165 ( * V_259 ++ ) ) ) {
case V_312 :
break;
case V_313 :
F_38 ( L_62 ,
V_148 -> V_222 , V_37 ) ;
error = - V_271 ;
goto V_63;
default:
F_38 ( L_63
L_64 ,
V_148 -> V_222 , V_37 , V_306 ) ;
goto V_307;
}
if ( -- V_24 < 0 )
goto V_308;
switch ( ( V_306 = F_165 ( * V_259 ++ ) ) ) {
case V_314 :
case V_315 :
case V_316 :
case V_317 :
if ( ! V_148 -> V_236 )
break;
V_148 -> V_236 -- ;
F_38 ( L_65 ,
V_148 -> V_222 , V_37 ) ;
F_156 ( V_148 ) ;
F_130 ( V_148 ) ;
V_148 -> V_165 = V_225 ;
goto V_298;
case V_318 :
case V_319 :
if ( ! V_148 -> V_320 )
break;
V_148 -> V_320 -- ;
F_38 ( L_66 ,
V_148 -> V_222 , V_37 ) ;
V_148 -> V_165 = V_242 ;
goto V_298;
case V_321 :
F_61 () ;
F_21 ( V_287 L_67
L_68 ,
F_63 ( V_2 -> V_66 ) -> V_59 ) ;
F_64 () ;
break;
default:
F_38 ( L_69 ,
V_148 -> V_222 , V_37 , V_306 ) ;
error = - V_141 ;
}
F_38 ( L_70 ,
V_148 -> V_222 , V_37 , V_306 ) ;
goto V_63;
}
if ( ! ( V_259 = F_166 ( V_148 , V_259 ) ) ) {
F_38 ( L_71 ,
V_148 -> V_222 , V_37 ) ;
goto V_310;
}
V_24 = V_259 - ( T_6 * ) V_305 -> V_257 - 1 ;
if ( V_24 < 0 )
goto V_308;
switch ( ( V_306 = F_165 ( * V_259 ++ ) ) ) {
case V_322 :
return V_259 ;
case V_323 :
F_75 ( L_72
L_73 , V_148 -> V_222 , V_37 ,
( unsigned int ) V_2 -> V_72 ,
F_63 ( V_2 -> V_66 ) -> V_59 ) ;
error = - V_270 ;
goto V_63;
case V_324 :
F_75 ( L_74
L_73 , V_148 -> V_222 , V_37 ,
( unsigned int ) V_2 -> V_72 ,
( unsigned int ) V_2 -> V_75 ,
F_63 ( V_2 -> V_66 ) -> V_59 ) ;
error = - V_271 ;
goto V_63;
case V_325 :
F_75 ( L_75
L_76 ,
V_148 -> V_222 , V_37 ,
F_126 ( V_148 ) ,
V_2 -> V_72 , V_2 -> V_75 ,
F_63 ( V_2 -> V_66 ) -> V_59 ) ;
error = - V_268 ;
goto V_63;
case V_326 :
F_38 ( L_77 ,
V_148 -> V_222 , V_37 ) ;
break;
default:
F_38 ( L_78 ,
V_148 -> V_222 , V_37 , V_306 ) ;
}
V_310:
V_2 -> V_76 -> V_327 ++ ;
if ( V_148 -> V_320 ) {
V_148 -> V_320 -- ;
F_38 ( L_79 ,
V_148 -> V_222 , V_37 ) ;
V_148 -> V_165 = V_242 ;
V_298:
return F_55 ( - V_228 ) ;
}
V_307:
error = - V_141 ;
V_63:
F_71 ( V_148 , error ) ;
F_38 ( L_80 , V_148 -> V_222 ,
V_37 , error ) ;
return F_55 ( error ) ;
V_308:
F_38 ( L_81 , V_148 -> V_222 ,
V_37 ) ;
goto V_310;
}
static void F_167 ( void * V_328 , struct V_329 * V_330 , void * V_331 )
{
}
static int F_168 ( void * V_328 , struct V_329 * V_330 , void * V_331 )
{
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_154 V_155 = {
. V_157 = & V_332 ,
} ;
int V_31 ;
V_155 . V_160 = V_333 . V_334 ( NULL , NULL , 0 ) ;
V_31 = F_96 ( V_2 , & V_155 , V_151 | V_335 ) ;
F_169 ( V_155 . V_160 ) ;
return V_31 ;
}
struct V_137 * F_170 ( struct V_1 * V_2 , struct V_160 * V_336 , int V_106 )
{
struct V_154 V_155 = {
. V_157 = & V_332 ,
. V_160 = V_336 ,
} ;
struct V_162 V_163 = {
. V_164 = V_2 ,
. V_154 = & V_155 ,
. V_167 = & V_168 ,
. V_106 = V_106 ,
} ;
return F_92 ( & V_163 ) ;
}
static void F_171 ( void )
{
F_21 ( V_27 L_82
L_83 ) ;
}
static void F_172 ( const struct V_1 * V_2 ,
const struct V_137 * V_148 )
{
const char * V_337 = L_84 ;
if ( F_72 ( V_148 ) )
V_337 = F_173 ( V_148 -> V_142 ) ;
F_21 ( V_27 L_85 ,
V_148 -> V_222 , V_148 -> V_139 , V_148 -> V_172 ,
V_2 , V_148 -> V_180 , V_148 -> V_264 , V_148 -> V_174 ,
V_2 -> V_71 , V_2 -> V_75 , F_126 ( V_148 ) ,
V_148 -> V_165 , V_337 ) ;
}
void F_174 ( struct V_3 * V_3 )
{
struct V_1 * V_2 ;
struct V_137 * V_148 ;
int V_338 = 0 ;
struct V_4 * V_5 = F_3 ( V_3 , V_6 ) ;
F_4 ( & V_5 -> V_7 ) ;
F_28 (clnt, &sn->all_clients, cl_clients) {
F_4 ( & V_2 -> V_81 ) ;
F_28 (task, &clnt->cl_tasks, tk_task) {
if ( ! V_338 ) {
F_171 () ;
V_338 ++ ;
}
F_172 ( V_2 , V_148 ) ;
}
F_6 ( & V_2 -> V_81 ) ;
}
F_6 ( & V_5 -> V_7 ) ;
}
