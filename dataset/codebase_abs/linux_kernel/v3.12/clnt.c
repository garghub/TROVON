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
F_10 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_10 * V_11 ;
V_11 = F_12 ( V_3 ) ;
if ( V_11 ) {
F_9 ( V_2 ) ;
F_13 ( V_3 ) ;
}
}
static struct V_12 * F_14 ( struct V_10 * V_13 ,
struct V_1 * V_2 )
{
static T_1 V_14 ;
const char * V_15 = V_2 -> V_16 -> V_17 ;
char V_18 [ 15 ] ;
struct V_12 * V_19 , * V_12 ;
V_19 = F_15 ( V_13 , V_15 ) ;
if ( V_19 == NULL ) {
F_16 ( L_1 , V_15 ) ;
return V_19 ;
}
for (; ; ) {
snprintf ( V_18 , sizeof( V_18 ) , L_2 , ( unsigned int ) V_14 ++ ) ;
V_18 [ sizeof( V_18 ) - 1 ] = '\0' ;
V_12 = F_17 ( V_19 , V_18 , V_2 ) ;
if ( ! F_18 ( V_12 ) )
break;
if ( V_12 == F_19 ( - V_20 ) )
continue;
F_20 ( V_21 L_3
L_4 ,
V_15 , V_18 , F_21 ( V_12 ) ) ;
break;
}
F_22 ( V_19 ) ;
return V_12 ;
}
static int
F_23 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
struct V_12 * V_12 ;
if ( V_2 -> V_16 -> V_17 != NULL ) {
V_12 = F_14 ( V_11 , V_2 ) ;
if ( F_18 ( V_12 ) )
return F_21 ( V_12 ) ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , unsigned long V_22 )
{
if ( V_2 -> V_16 -> V_17 == NULL )
return 1 ;
switch ( V_22 ) {
case V_23 :
if ( V_2 -> V_24 . V_25 != NULL )
return 1 ;
if ( F_25 ( & V_2 -> V_26 ) == 0 )
return 1 ;
break;
case V_27 :
if ( V_2 -> V_24 . V_25 == NULL )
return 1 ;
break;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , unsigned long V_22 ,
struct V_10 * V_13 )
{
struct V_12 * V_12 ;
int V_28 = 0 ;
switch ( V_22 ) {
case V_23 :
V_12 = F_14 ( V_13 , V_2 ) ;
if ( ! V_12 )
return - V_29 ;
if ( F_18 ( V_12 ) )
return F_21 ( V_12 ) ;
break;
case V_27 :
F_9 ( V_2 ) ;
break;
default:
F_20 ( V_30 L_5 , V_31 , V_22 ) ;
return - V_32 ;
}
return V_28 ;
}
static int F_27 ( struct V_1 * V_2 , unsigned long V_22 ,
struct V_10 * V_13 )
{
int error = 0 ;
for (; ; V_2 = V_2 -> V_33 ) {
if ( ! F_24 ( V_2 , V_22 ) )
error = F_26 ( V_2 , V_22 , V_13 ) ;
if ( error || V_2 == V_2 -> V_33 )
break;
}
return error ;
}
static struct V_1 * F_28 ( struct V_3 * V_3 , int V_22 )
{
struct V_4 * V_5 = F_3 ( V_3 , V_6 ) ;
struct V_1 * V_2 ;
F_4 ( & V_5 -> V_7 ) ;
F_29 (clnt, &sn->all_clients, cl_clients) {
if ( F_24 ( V_2 , V_22 ) )
continue;
F_6 ( & V_5 -> V_7 ) ;
return V_2 ;
}
F_6 ( & V_5 -> V_7 ) ;
return NULL ;
}
static int F_30 ( struct V_34 * V_35 , unsigned long V_22 ,
void * V_36 )
{
struct V_10 * V_13 = V_36 ;
struct V_1 * V_2 ;
int error = 0 ;
while ( ( V_2 = F_28 ( V_13 -> V_37 , V_22 ) ) ) {
error = F_27 ( V_2 , V_22 , V_13 ) ;
if ( error )
break;
}
return error ;
}
int F_31 ( void )
{
return F_32 ( & V_38 ) ;
}
void F_33 ( void )
{
return F_34 ( & V_38 ) ;
}
static void F_35 ( struct V_1 * V_2 , const char * V_39 )
{
V_2 -> V_40 = strlen ( V_39 ) ;
if ( V_2 -> V_40 > V_41 )
V_2 -> V_40 = V_41 ;
memcpy ( V_2 -> V_42 , V_39 , V_2 -> V_40 ) ;
}
static int F_36 ( const struct V_43 * args ,
struct V_1 * V_2 )
{
struct V_44 V_45 = {
. V_46 = args -> V_47 ,
. V_48 = args -> V_49 ,
} ;
struct V_50 * V_51 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_10 * V_11 ;
int V_28 ;
V_11 = F_12 ( V_3 ) ;
if ( V_11 ) {
V_28 = F_23 ( V_11 , V_2 ) ;
if ( V_28 )
goto V_52;
}
F_1 ( V_2 ) ;
if ( V_11 )
F_13 ( V_3 ) ;
V_51 = F_37 ( & V_45 , V_2 ) ;
if ( F_18 ( V_51 ) ) {
F_38 ( L_6 ,
args -> V_47 ) ;
V_28 = F_21 ( V_51 ) ;
goto V_53;
}
return 0 ;
V_53:
V_11 = F_12 ( V_3 ) ;
F_7 ( V_2 ) ;
F_9 ( V_2 ) ;
V_52:
if ( V_11 )
F_13 ( V_3 ) ;
return V_28 ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_54 ;
V_54 = F_40 ( & V_55 , 0 , 0 , V_56 ) ;
if ( V_54 < 0 )
return V_54 ;
V_2 -> V_57 = V_54 ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
F_42 ( & V_55 , V_2 -> V_57 ) ;
}
static struct V_1 * F_43 ( const struct V_43 * args ,
struct V_58 * V_59 ,
struct V_1 * V_60 )
{
const struct V_61 * V_62 = args -> V_62 ;
const struct V_63 * V_64 ;
struct V_1 * V_2 = NULL ;
int V_28 ;
F_38 ( L_7 ,
V_62 -> V_18 , args -> V_65 , V_59 ) ;
V_28 = F_44 () ;
if ( V_28 )
goto V_66;
V_28 = - V_67 ;
if ( args -> V_64 >= V_62 -> V_68 )
goto V_69;
V_64 = V_62 -> V_64 [ args -> V_64 ] ;
if ( V_64 == NULL )
goto V_69;
V_28 = - V_70 ;
V_2 = F_45 ( sizeof( * V_2 ) , V_56 ) ;
if ( ! V_2 )
goto V_69;
V_2 -> V_33 = V_60 ? : V_2 ;
V_28 = F_39 ( V_2 ) ;
if ( V_28 )
goto V_71;
F_46 ( V_2 -> V_72 , V_59 ) ;
V_2 -> V_73 = V_64 -> V_74 ;
V_2 -> V_75 = V_64 -> V_76 ;
V_2 -> V_77 = args -> V_78 ? : V_62 -> V_79 ;
V_2 -> V_80 = V_64 -> V_79 ;
V_2 -> V_81 = V_62 -> V_82 ;
V_2 -> V_83 = F_47 ( V_2 ) ;
F_48 ( & V_2 -> V_24 ) ;
V_28 = - V_70 ;
if ( V_2 -> V_83 == NULL )
goto V_84;
V_2 -> V_16 = V_62 ;
F_49 ( & V_2 -> V_85 ) ;
F_50 ( & V_2 -> V_86 ) ;
if ( ! F_51 ( V_59 ) )
V_2 -> V_87 = 1 ;
V_2 -> V_88 = V_59 -> V_89 ;
if ( args -> V_89 != NULL ) {
memcpy ( & V_2 -> V_90 , args -> V_89 ,
sizeof( V_2 -> V_90 ) ) ;
V_2 -> V_88 = & V_2 -> V_90 ;
}
V_2 -> V_91 = & V_2 -> V_92 ;
F_52 ( & V_2 -> V_92 , V_2 -> V_88 -> V_93 ) ;
F_53 ( & V_2 -> V_26 , 1 ) ;
F_35 ( V_2 , F_54 () -> V_39 ) ;
V_28 = F_36 ( args , V_2 ) ;
if ( V_28 )
goto V_94;
if ( V_60 )
F_55 ( & V_60 -> V_26 ) ;
return V_2 ;
V_94:
F_56 ( V_2 -> V_83 ) ;
V_84:
F_41 ( V_2 ) ;
V_71:
F_57 ( V_2 ) ;
V_69:
F_58 () ;
V_66:
F_59 ( V_59 ) ;
return F_19 ( V_28 ) ;
}
struct V_1 * F_60 ( struct V_43 * args )
{
struct V_58 * V_59 ;
struct V_1 * V_2 ;
struct V_95 V_96 = {
. V_3 = args -> V_3 ,
. V_97 = args -> V_98 ,
. V_99 = args -> V_100 ,
. V_101 = args -> V_102 ,
. V_103 = args -> V_104 ,
. V_65 = args -> V_65 ,
. V_105 = args -> V_105 ,
} ;
char V_65 [ 48 ] ;
if ( args -> V_106 & V_107 )
V_96 . V_106 |= V_108 ;
if ( args -> V_106 & V_109 )
V_96 . V_106 |= V_110 ;
if ( V_96 . V_65 == NULL ) {
struct V_111 * V_112 =
(struct V_111 * ) args -> V_102 ;
struct V_113 * sin =
(struct V_113 * ) args -> V_102 ;
struct V_114 * V_115 =
(struct V_114 * ) args -> V_102 ;
V_65 [ 0 ] = '\0' ;
switch ( args -> V_102 -> V_116 ) {
case V_117 :
snprintf ( V_65 , sizeof( V_65 ) , L_8 ,
V_112 -> V_118 ) ;
break;
case V_119 :
snprintf ( V_65 , sizeof( V_65 ) , L_9 ,
& sin -> V_120 . V_121 ) ;
break;
case V_122 :
snprintf ( V_65 , sizeof( V_65 ) , L_10 ,
& V_115 -> V_123 ) ;
break;
default:
return F_19 ( - V_67 ) ;
}
V_96 . V_65 = V_65 ;
}
V_59 = F_61 ( & V_96 ) ;
if ( F_18 ( V_59 ) )
return (struct V_1 * ) V_59 ;
V_59 -> V_124 = 1 ;
if ( args -> V_106 & V_125 )
V_59 -> V_124 = 0 ;
V_2 = F_43 ( args , V_59 , NULL ) ;
if ( F_18 ( V_2 ) )
return V_2 ;
if ( ! ( args -> V_106 & V_126 ) ) {
int V_28 = F_62 ( V_2 ) ;
if ( V_28 != 0 ) {
F_63 ( V_2 ) ;
return F_19 ( V_28 ) ;
}
}
V_2 -> V_127 = 1 ;
if ( args -> V_106 & V_128 )
V_2 -> V_127 = 0 ;
if ( args -> V_106 & V_129 )
V_2 -> V_87 = 1 ;
if ( args -> V_106 & V_130 )
V_2 -> V_131 = 1 ;
if ( ! ( args -> V_106 & V_132 ) )
V_2 -> V_133 = 1 ;
return V_2 ;
}
static struct V_1 * F_64 ( struct V_43 * args ,
struct V_1 * V_2 )
{
struct V_58 * V_59 ;
struct V_1 * V_134 ;
int V_28 ;
V_28 = - V_70 ;
F_65 () ;
V_59 = F_66 ( F_67 ( V_2 -> V_72 ) ) ;
F_68 () ;
if ( V_59 == NULL )
goto V_69;
args -> V_65 = V_59 -> V_65 ;
V_134 = F_43 ( args , V_59 , V_2 ) ;
if ( F_18 ( V_134 ) ) {
V_28 = F_21 ( V_134 ) ;
goto V_69;
}
V_134 -> V_87 = 0 ;
V_134 -> V_127 = V_2 -> V_127 ;
V_134 -> V_131 = V_2 -> V_131 ;
V_134 -> V_133 = V_2 -> V_133 ;
return V_134 ;
V_69:
F_38 ( L_11 , V_31 , V_28 ) ;
return F_19 ( V_28 ) ;
}
struct V_1 * F_69 ( struct V_1 * V_2 )
{
struct V_43 args = {
. V_62 = V_2 -> V_16 ,
. V_78 = V_2 -> V_77 ,
. V_64 = V_2 -> V_80 ,
. V_47 = V_2 -> V_135 -> V_136 ,
} ;
return F_64 ( & args , V_2 ) ;
}
struct V_1 *
F_70 ( struct V_1 * V_2 , T_2 V_137 )
{
struct V_43 args = {
. V_62 = V_2 -> V_16 ,
. V_78 = V_2 -> V_77 ,
. V_64 = V_2 -> V_80 ,
. V_47 = V_137 ,
} ;
return F_64 ( & args , V_2 ) ;
}
void F_71 ( struct V_1 * V_2 )
{
struct V_138 * V_139 ;
if ( F_72 ( & V_2 -> V_85 ) )
return;
F_38 ( L_12 , V_2 ) ;
F_4 ( & V_2 -> V_86 ) ;
F_29 (rovr, &clnt->cl_tasks, tk_task) {
if ( ! F_73 ( V_139 ) )
continue;
if ( ! ( V_139 -> V_140 & V_141 ) ) {
V_139 -> V_140 |= V_141 ;
F_74 ( V_139 , - V_142 ) ;
if ( F_75 ( V_139 ) )
F_76 ( V_139 -> V_143 ,
V_139 ) ;
}
}
F_6 ( & V_2 -> V_86 ) ;
}
void F_63 ( struct V_1 * V_2 )
{
F_77 () ;
F_78 ( L_13 ,
V_2 -> V_16 -> V_18 ,
F_67 ( V_2 -> V_72 ) -> V_65 ) ;
while ( ! F_72 ( & V_2 -> V_85 ) ) {
F_71 ( V_2 ) ;
F_79 ( V_144 ,
F_72 ( & V_2 -> V_85 ) , 1 * V_145 ) ;
}
F_80 ( V_2 ) ;
}
static void
F_81 ( struct V_1 * V_2 )
{
F_78 ( L_14 ,
V_2 -> V_16 -> V_18 ,
F_67 ( V_2 -> V_72 ) -> V_65 ) ;
if ( V_2 -> V_33 != V_2 )
F_80 ( V_2 -> V_33 ) ;
F_11 ( V_2 ) ;
F_7 ( V_2 ) ;
F_56 ( V_2 -> V_83 ) ;
V_2 -> V_83 = NULL ;
F_59 ( F_82 ( V_2 -> V_72 ) ) ;
F_58 () ;
F_41 ( V_2 ) ;
F_57 ( V_2 ) ;
}
static void
F_83 ( struct V_1 * V_2 )
{
if ( V_2 -> V_135 == NULL ) {
F_81 ( V_2 ) ;
return;
}
F_55 ( & V_2 -> V_26 ) ;
F_84 ( V_2 -> V_135 ) ;
V_2 -> V_135 = NULL ;
if ( F_85 ( & V_2 -> V_26 ) )
F_81 ( V_2 ) ;
}
void
F_80 ( struct V_1 * V_2 )
{
F_38 ( L_15 , V_2 ) ;
if ( F_72 ( & V_2 -> V_85 ) )
F_86 ( & V_144 ) ;
if ( F_85 ( & V_2 -> V_26 ) )
F_83 ( V_2 ) ;
}
struct V_1 * F_87 ( struct V_1 * V_146 ,
const struct V_61 * V_62 ,
T_3 V_147 )
{
struct V_43 args = {
. V_62 = V_62 ,
. V_78 = V_62 -> V_79 ,
. V_64 = V_147 ,
. V_47 = V_146 -> V_135 -> V_136 ,
} ;
struct V_1 * V_2 ;
int V_28 ;
V_2 = F_64 ( & args , V_146 ) ;
if ( F_18 ( V_2 ) )
goto V_52;
V_28 = F_62 ( V_2 ) ;
if ( V_28 != 0 ) {
F_63 ( V_2 ) ;
V_2 = F_19 ( V_28 ) ;
}
V_52:
return V_2 ;
}
void F_88 ( struct V_138 * V_148 )
{
struct V_1 * V_2 = V_148 -> V_149 ;
if ( V_2 != NULL ) {
F_4 ( & V_2 -> V_86 ) ;
F_8 ( & V_148 -> V_150 ) ;
F_6 ( & V_2 -> V_86 ) ;
V_148 -> V_149 = NULL ;
F_80 ( V_2 ) ;
}
}
static
void F_89 ( struct V_138 * V_148 , struct V_1 * V_2 )
{
if ( V_2 != NULL ) {
F_88 ( V_148 ) ;
V_148 -> V_149 = V_2 ;
F_55 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_127 )
V_148 -> V_140 |= V_151 ;
if ( F_90 () ) {
struct V_58 * V_59 ;
F_65 () ;
V_59 = F_67 ( V_2 -> V_72 ) ;
if ( V_59 -> V_152 )
V_148 -> V_140 |= V_153 ;
F_68 () ;
}
F_4 ( & V_2 -> V_86 ) ;
F_91 ( & V_148 -> V_150 , & V_2 -> V_85 ) ;
F_6 ( & V_2 -> V_86 ) ;
}
}
void F_92 ( struct V_138 * V_148 , struct V_1 * V_2 )
{
F_88 ( V_148 ) ;
F_89 ( V_148 , V_2 ) ;
}
static void
F_93 ( struct V_138 * V_148 , const struct V_154 * V_155 )
{
if ( V_155 != NULL ) {
V_148 -> V_156 . V_157 = V_155 -> V_157 ;
V_148 -> V_156 . V_158 = V_155 -> V_158 ;
V_148 -> V_156 . V_159 = V_155 -> V_159 ;
if ( V_155 -> V_160 != NULL )
V_148 -> V_156 . V_160 = F_94 ( V_155 -> V_160 ) ;
}
}
static void
F_95 ( struct V_138 * V_148 , void * V_161 )
{
}
struct V_138 * F_96 ( const struct V_162 * V_163 )
{
struct V_138 * V_148 ;
V_148 = F_97 ( V_163 ) ;
if ( F_18 ( V_148 ) )
goto V_52;
F_89 ( V_148 , V_163 -> V_164 ) ;
F_93 ( V_148 , V_163 -> V_154 ) ;
if ( V_148 -> V_165 == NULL )
F_98 ( V_148 ) ;
F_55 ( & V_148 -> V_166 ) ;
F_99 ( V_148 ) ;
V_52:
return V_148 ;
}
int F_100 ( struct V_1 * V_2 , const struct V_154 * V_155 , int V_106 )
{
struct V_138 * V_148 ;
struct V_162 V_163 = {
. V_164 = V_2 ,
. V_154 = V_155 ,
. V_167 = & V_168 ,
. V_106 = V_106 ,
} ;
int V_169 ;
F_101 ( V_106 & V_170 ) ;
if ( V_106 & V_170 ) {
F_102 ( V_163 . V_167 ,
V_163 . V_171 ) ;
return - V_67 ;
}
V_148 = F_96 ( & V_163 ) ;
if ( F_18 ( V_148 ) )
return F_21 ( V_148 ) ;
V_169 = V_148 -> V_172 ;
F_103 ( V_148 ) ;
return V_169 ;
}
int
F_104 ( struct V_1 * V_2 , const struct V_154 * V_155 , int V_106 ,
const struct V_173 * V_174 , void * V_161 )
{
struct V_138 * V_148 ;
struct V_162 V_163 = {
. V_164 = V_2 ,
. V_154 = V_155 ,
. V_167 = V_174 ,
. V_171 = V_161 ,
. V_106 = V_106 | V_170 ,
} ;
V_148 = F_96 ( & V_163 ) ;
if ( F_18 ( V_148 ) )
return F_21 ( V_148 ) ;
F_103 ( V_148 ) ;
return 0 ;
}
struct V_138 * F_105 ( struct V_175 * V_176 ,
const struct V_173 * V_174 )
{
struct V_138 * V_148 ;
struct V_177 * V_178 = & V_176 -> V_179 ;
struct V_162 V_163 = {
. V_167 = V_174 ,
} ;
F_38 ( L_16 , V_176 ) ;
V_148 = F_97 ( & V_163 ) ;
if ( F_18 ( V_148 ) ) {
F_106 ( V_176 ) ;
goto V_52;
}
V_148 -> V_180 = V_176 ;
V_178 -> V_181 = V_178 -> V_182 [ 0 ] . V_183 + V_178 -> V_184 +
V_178 -> V_185 [ 0 ] . V_183 ;
V_148 -> V_165 = V_186 ;
F_55 ( & V_148 -> V_166 ) ;
F_101 ( F_25 ( & V_148 -> V_166 ) != 2 ) ;
F_99 ( V_148 ) ;
V_52:
F_38 ( L_17 , V_148 ) ;
return V_148 ;
}
void
F_98 ( struct V_138 * V_148 )
{
V_148 -> V_165 = V_187 ;
}
T_4 F_107 ( struct V_1 * V_2 , struct V_188 * V_189 , T_4 V_190 )
{
T_4 V_191 ;
struct V_58 * V_59 ;
F_65 () ;
V_59 = F_67 ( V_2 -> V_72 ) ;
V_191 = V_59 -> V_103 ;
if ( V_191 > V_190 )
V_191 = V_190 ;
memcpy ( V_189 , & V_59 -> V_192 , V_191 ) ;
F_68 () ;
return V_191 ;
}
const char * F_108 ( struct V_1 * V_2 ,
enum V_193 V_194 )
{
struct V_58 * V_59 ;
V_59 = F_67 ( V_2 -> V_72 ) ;
if ( V_59 -> V_195 [ V_194 ] != NULL )
return V_59 -> V_195 [ V_194 ] ;
else
return L_18 ;
}
static int F_109 ( struct V_3 * V_3 , struct V_188 * V_196 , T_4 V_197 ,
struct V_188 * V_189 , int V_198 )
{
struct V_199 * V_200 ;
int V_28 ;
V_28 = F_110 ( V_3 , V_196 -> V_116 ,
V_201 , V_202 , & V_200 , 1 ) ;
if ( V_28 < 0 ) {
F_38 ( L_19 , V_28 ) ;
goto V_52;
}
switch ( V_196 -> V_116 ) {
case V_119 :
V_28 = F_111 ( V_200 ,
(struct V_188 * ) & V_203 ,
sizeof( V_203 ) ) ;
break;
case V_122 :
V_28 = F_111 ( V_200 ,
(struct V_188 * ) & V_204 ,
sizeof( V_204 ) ) ;
break;
default:
V_28 = - V_205 ;
goto V_52;
}
if ( V_28 < 0 ) {
F_38 ( L_20 , V_28 ) ;
goto V_206;
}
V_28 = F_112 ( V_200 , V_196 , V_197 , 0 ) ;
if ( V_28 < 0 ) {
F_38 ( L_21 , V_28 ) ;
goto V_206;
}
V_28 = F_113 ( V_200 , V_189 , & V_198 ) ;
if ( V_28 < 0 ) {
F_38 ( L_22 , V_28 ) ;
goto V_206;
}
V_28 = 0 ;
if ( V_189 -> V_116 == V_122 ) {
struct V_114 * V_115 = (struct V_114 * ) V_189 ;
V_115 -> V_207 = 0 ;
}
F_38 ( L_23 , V_31 ) ;
V_206:
F_114 ( V_200 ) ;
V_52:
return V_28 ;
}
static int F_115 ( int V_208 , struct V_188 * V_189 , T_4 V_198 )
{
switch ( V_208 ) {
case V_119 :
if ( V_198 < sizeof( V_203 ) )
return - V_67 ;
memcpy ( V_189 , & V_203 ,
sizeof( V_203 ) ) ;
break;
case V_122 :
if ( V_198 < sizeof( V_204 ) )
return - V_67 ;
memcpy ( V_189 , & V_204 ,
sizeof( V_204 ) ) ;
default:
F_38 ( L_24 ,
V_31 ) ;
return - V_205 ;
}
F_38 ( L_25 , V_31 ) ;
return 0 ;
}
int F_116 ( struct V_1 * V_2 , struct V_188 * V_189 , T_4 V_198 )
{
struct V_209 V_102 ;
struct V_188 * V_196 = (struct V_188 * ) & V_102 ;
struct V_58 * V_59 ;
struct V_3 * V_3 ;
T_4 V_197 ;
int V_28 ;
F_65 () ;
V_59 = F_67 ( V_2 -> V_72 ) ;
V_197 = V_59 -> V_103 ;
memcpy ( V_196 , & V_59 -> V_192 , V_197 ) ;
V_3 = F_117 ( V_59 -> V_210 ) ;
F_68 () ;
F_118 ( V_196 , 0 ) ;
V_28 = F_109 ( V_3 , V_196 , V_197 , V_189 , V_198 ) ;
F_119 ( V_3 ) ;
if ( V_28 != 0 )
return F_115 ( V_196 -> V_116 , V_189 , V_198 ) ;
return 0 ;
}
void
F_120 ( struct V_1 * V_2 , unsigned int V_211 , unsigned int V_212 )
{
struct V_58 * V_59 ;
F_65 () ;
V_59 = F_67 ( V_2 -> V_72 ) ;
if ( V_59 -> V_213 -> V_214 )
V_59 -> V_213 -> V_214 ( V_59 , V_211 , V_212 ) ;
F_68 () ;
}
int F_121 ( struct V_1 * V_2 )
{
int V_98 ;
F_65 () ;
V_98 = F_67 ( V_2 -> V_72 ) -> V_215 ;
F_68 () ;
return V_98 ;
}
struct V_3 * F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_216 ;
F_65 () ;
V_216 = F_67 ( V_2 -> V_72 ) -> V_210 ;
F_68 () ;
return V_216 ;
}
T_4 F_122 ( struct V_1 * V_2 )
{
T_4 V_216 ;
F_65 () ;
V_216 = F_67 ( V_2 -> V_72 ) -> V_217 ;
F_68 () ;
return V_216 ;
}
unsigned long F_123 ( struct V_1 * V_2 )
{
unsigned long V_216 ;
F_65 () ;
V_216 = F_67 ( V_2 -> V_72 ) -> V_89 -> V_93 ;
F_68 () ;
return V_216 ;
}
void F_124 ( struct V_1 * V_2 )
{
if ( V_2 -> V_87 ) {
F_65 () ;
F_125 ( F_67 ( V_2 -> V_72 ) ) ;
F_68 () ;
}
}
int
F_126 ( struct V_138 * V_148 )
{
if ( F_127 ( V_148 ) )
return 0 ;
V_148 -> V_165 = V_187 ;
if ( V_148 -> V_174 -> V_218 != NULL )
V_148 -> V_165 = V_219 ;
return 1 ;
}
int
F_128 ( struct V_138 * V_148 )
{
if ( F_127 ( V_148 ) )
return 0 ;
V_148 -> V_165 = V_187 ;
return 1 ;
}
static const char * F_129 ( const struct V_138 * V_148 )
{
const struct V_220 * V_221 = V_148 -> V_156 . V_157 ;
if ( V_221 ) {
if ( V_221 -> V_222 )
return V_221 -> V_222 ;
else
return L_26 ;
} else
return L_27 ;
}
static void
V_187 ( struct V_138 * V_148 )
{
struct V_1 * V_2 = V_148 -> V_149 ;
F_38 ( L_28 , V_148 -> V_223 ,
V_2 -> V_16 -> V_18 , V_2 -> V_80 ,
F_129 ( V_148 ) ,
( F_130 ( V_148 ) ? L_29 : L_30 ) ) ;
V_148 -> V_156 . V_157 -> V_224 ++ ;
V_2 -> V_81 -> V_225 ++ ;
V_148 -> V_165 = V_226 ;
}
static void
V_226 ( struct V_138 * V_148 )
{
F_131 ( V_148 ) ;
V_148 -> V_172 = 0 ;
V_148 -> V_165 = V_227 ;
F_132 ( V_148 ) ;
}
static void
V_227 ( struct V_138 * V_148 )
{
int V_169 = V_148 -> V_172 ;
F_131 ( V_148 ) ;
V_148 -> V_172 = 0 ;
if ( V_169 >= 0 ) {
if ( V_148 -> V_180 ) {
V_148 -> V_165 = V_228 ;
return;
}
F_20 ( V_30 L_31 ,
V_31 , V_169 ) ;
F_74 ( V_148 , - V_142 ) ;
return;
}
if ( V_148 -> V_180 ) {
F_20 ( V_30 L_32 ,
V_31 , V_169 ) ;
F_133 ( V_148 ) ;
}
switch ( V_169 ) {
case - V_70 :
F_134 ( V_148 , V_145 >> 2 ) ;
case - V_229 :
V_148 -> V_165 = V_230 ;
return;
case - V_142 :
break;
default:
F_20 ( V_30 L_33 ,
V_31 , V_169 ) ;
break;
}
F_74 ( V_148 , V_169 ) ;
}
static void
V_230 ( struct V_138 * V_148 )
{
F_131 ( V_148 ) ;
V_148 -> V_172 = 0 ;
V_148 -> V_165 = V_227 ;
F_135 ( V_148 ) ;
}
static void
V_228 ( struct V_138 * V_148 )
{
F_131 ( V_148 ) ;
V_148 -> V_165 = V_231 ;
V_148 -> V_172 = 0 ;
V_148 -> V_149 -> V_81 -> V_232 ++ ;
F_136 ( V_148 ) ;
}
static void
V_231 ( struct V_138 * V_148 )
{
int V_169 = V_148 -> V_172 ;
F_131 ( V_148 ) ;
V_148 -> V_172 = 0 ;
V_148 -> V_165 = V_228 ;
switch ( V_169 ) {
case 0 :
if ( F_137 ( V_148 ) )
V_148 -> V_165 = V_233 ;
return;
case - V_234 :
F_134 ( V_148 , 3 * V_145 ) ;
case - V_229 :
V_169 = - V_235 ;
case - V_236 :
if ( ! V_148 -> V_237 )
break;
V_148 -> V_237 -- ;
F_38 ( L_34 ,
V_148 -> V_223 , V_31 ) ;
return;
}
F_38 ( L_35 ,
V_148 -> V_223 , V_31 , V_169 ) ;
F_74 ( V_148 , V_169 ) ;
}
static void
V_233 ( struct V_138 * V_148 )
{
unsigned int V_238 = V_148 -> V_180 -> V_239 -> V_240 -> V_241 ;
struct V_175 * V_176 = V_148 -> V_180 ;
struct V_58 * V_59 = V_176 -> V_242 ;
struct V_220 * V_221 = V_148 -> V_156 . V_157 ;
F_131 ( V_148 ) ;
V_148 -> V_172 = 0 ;
V_148 -> V_165 = V_243 ;
if ( V_176 -> V_244 )
return;
if ( V_221 -> V_245 != 0 ) {
F_138 ( V_221 -> V_246 == 0 ) ;
if ( V_221 -> V_247 != NULL )
F_138 ( V_221 -> V_248 == 0 ) ;
}
V_176 -> V_249 = V_250 + ( V_238 << 1 ) + V_221 -> V_246 ;
V_176 -> V_249 <<= 2 ;
V_176 -> V_251 = V_252 + V_238 + V_221 -> V_248 ;
V_176 -> V_251 <<= 2 ;
V_176 -> V_244 = V_59 -> V_213 -> V_253 ( V_148 ,
V_176 -> V_249 + V_176 -> V_251 ) ;
if ( V_176 -> V_244 != NULL )
return;
F_38 ( L_36 , V_148 -> V_223 ) ;
if ( F_130 ( V_148 ) || ! F_139 ( V_254 ) ) {
V_148 -> V_165 = V_233 ;
F_134 ( V_148 , V_145 >> 4 ) ;
return;
}
F_74 ( V_148 , - V_255 ) ;
}
static inline int
F_140 ( struct V_138 * V_148 )
{
return V_148 -> V_180 -> V_179 . V_181 == 0 ;
}
static inline void
F_141 ( struct V_138 * V_148 )
{
V_148 -> V_180 -> V_179 . V_181 = 0 ;
V_148 -> V_180 -> V_256 = 0 ;
}
static inline void
F_142 ( struct V_177 * V_189 , void * V_257 , T_4 V_181 )
{
V_189 -> V_182 [ 0 ] . V_258 = V_257 ;
V_189 -> V_182 [ 0 ] . V_183 = V_181 ;
V_189 -> V_185 [ 0 ] . V_183 = 0 ;
V_189 -> V_184 = 0 ;
V_189 -> V_106 = 0 ;
V_189 -> V_181 = 0 ;
V_189 -> V_198 = V_181 ;
}
static void
F_143 ( struct V_138 * V_148 )
{
struct V_175 * V_176 = V_148 -> V_180 ;
T_5 V_259 ;
T_6 * V_260 ;
F_131 ( V_148 ) ;
F_142 ( & V_176 -> V_179 ,
V_176 -> V_244 ,
V_176 -> V_249 ) ;
F_142 ( & V_176 -> V_261 ,
( char * ) V_176 -> V_244 + V_176 -> V_249 ,
V_176 -> V_251 ) ;
V_260 = F_144 ( V_148 ) ;
if ( V_260 == NULL ) {
F_20 ( V_21 L_37 ) ;
F_74 ( V_148 , - V_142 ) ;
return;
}
V_259 = V_148 -> V_156 . V_157 -> V_262 ;
if ( V_259 == NULL )
return;
V_148 -> V_172 = F_145 ( V_148 , V_259 , V_176 , V_260 ,
V_148 -> V_156 . V_158 ) ;
}
static void
V_243 ( struct V_138 * V_148 )
{
struct V_58 * V_59 = V_148 -> V_180 -> V_242 ;
F_131 ( V_148 ) ;
V_148 -> V_165 = V_263 ;
if ( ! F_51 ( V_59 ) ) {
V_148 -> V_165 = V_264 ;
V_148 -> V_265 = V_59 -> V_266 ;
V_59 -> V_213 -> V_267 ( V_148 ) ;
}
}
static void
V_264 ( struct V_138 * V_148 )
{
int V_169 = - V_142 ;
if ( V_148 -> V_172 >= 0 ) {
F_131 ( V_148 ) ;
V_148 -> V_172 = 0 ;
V_148 -> V_165 = V_263 ;
return;
}
F_146 ( V_148 ) ;
switch ( V_148 -> V_172 ) {
case - V_70 :
F_38 ( L_38 , V_148 -> V_223 ) ;
F_134 ( V_148 , V_145 >> 2 ) ;
goto V_268;
case - V_235 :
F_38 ( L_39
L_40 , V_148 -> V_223 ) ;
if ( V_148 -> V_156 . V_157 -> V_245 == 0 ) {
V_169 = - V_269 ;
break;
}
if ( V_148 -> V_270 == 0 )
break;
V_148 -> V_270 -- ;
F_134 ( V_148 , 3 * V_145 ) ;
goto V_268;
case - V_234 :
F_38 ( L_41 ,
V_148 -> V_223 ) ;
goto V_268;
case - V_271 :
F_38 ( L_42 ,
V_148 -> V_223 ) ;
break;
case - V_272 :
F_38 ( L_43 ,
V_148 -> V_223 ) ;
V_148 -> V_172 = 0 ;
V_148 -> V_165 = V_243 ;
return;
case - V_273 :
case - V_274 :
case - V_275 :
case - V_276 :
case - V_277 :
case - V_278 :
case - V_279 :
F_38 ( L_44 ,
V_148 -> V_223 , V_148 -> V_172 ) ;
if ( ! F_147 ( V_148 ) ) {
F_134 ( V_148 , 5 * V_145 ) ;
goto V_268;
}
V_169 = V_148 -> V_172 ;
break;
default:
F_38 ( L_45 ,
V_148 -> V_223 , - V_148 -> V_172 ) ;
}
F_74 ( V_148 , V_169 ) ;
return;
V_268:
V_148 -> V_165 = V_280 ;
}
static void
V_263 ( struct V_138 * V_148 )
{
struct V_58 * V_59 = V_148 -> V_180 -> V_242 ;
F_38 ( L_46 ,
V_148 -> V_223 , V_59 ,
( F_148 ( V_59 ) ? L_47 : L_48 ) ) ;
V_148 -> V_165 = V_281 ;
if ( ! F_148 ( V_59 ) ) {
V_148 -> V_165 = V_282 ;
if ( V_148 -> V_172 < 0 )
return;
if ( V_148 -> V_140 & V_283 ) {
F_74 ( V_148 , - V_275 ) ;
return;
}
F_149 ( V_148 ) ;
}
}
static void
V_282 ( struct V_138 * V_148 )
{
struct V_1 * V_2 = V_148 -> V_149 ;
int V_169 = V_148 -> V_172 ;
F_131 ( V_148 ) ;
F_150 ( V_148 , V_169 ) ;
switch ( V_169 ) {
case - V_234 :
V_148 -> V_165 = V_280 ;
return;
case - V_273 :
case - V_274 :
case - V_278 :
if ( F_147 ( V_148 ) )
break;
case 0 :
case - V_229 :
V_148 -> V_172 = 0 ;
V_2 -> V_81 -> V_284 ++ ;
V_148 -> V_165 = V_281 ;
return;
}
F_74 ( V_148 , V_169 ) ;
}
static void
V_281 ( struct V_138 * V_148 )
{
F_131 ( V_148 ) ;
V_148 -> V_165 = V_285 ;
if ( V_148 -> V_172 < 0 )
return;
V_148 -> V_172 = F_151 ( V_148 ) ;
if ( V_148 -> V_172 != 0 )
return;
V_148 -> V_165 = V_286 ;
if ( F_140 ( V_148 ) ) {
F_143 ( V_148 ) ;
if ( V_148 -> V_172 != 0 ) {
if ( V_148 -> V_172 == - V_229 )
F_134 ( V_148 , V_145 >> 4 ) ;
else
F_74 ( V_148 , V_148 -> V_172 ) ;
return;
}
}
F_152 ( V_148 ) ;
if ( V_148 -> V_172 < 0 )
return;
V_286 ( V_148 ) ;
if ( F_153 ( V_148 ) )
return;
V_148 -> V_165 = V_287 ;
F_76 ( & V_148 -> V_180 -> V_242 -> V_288 , V_148 ) ;
}
static void
V_286 ( struct V_138 * V_148 )
{
V_148 -> V_165 = V_285 ;
if ( V_148 -> V_172 == 0 ) {
F_154 ( V_148 ) ;
F_141 ( V_148 ) ;
return;
}
switch ( V_148 -> V_172 ) {
case - V_229 :
break;
default:
F_131 ( V_148 ) ;
F_154 ( V_148 ) ;
F_141 ( V_148 ) ;
break;
case - V_273 :
case - V_276 :
case - V_277 :
case - V_278 :
if ( F_147 ( V_148 ) ) {
F_154 ( V_148 ) ;
F_74 ( V_148 , V_148 -> V_172 ) ;
break;
}
case - V_274 :
case - V_275 :
case - V_279 :
F_141 ( V_148 ) ;
}
}
static void
V_186 ( struct V_138 * V_148 )
{
struct V_175 * V_176 = V_148 -> V_180 ;
V_148 -> V_172 = F_151 ( V_148 ) ;
if ( V_148 -> V_172 == - V_229 ) {
V_148 -> V_172 = 0 ;
V_148 -> V_165 = V_186 ;
return;
}
V_148 -> V_165 = V_287 ;
if ( V_148 -> V_172 < 0 ) {
F_20 ( V_289 L_49
L_50 , V_148 -> V_172 ) ;
return;
}
F_152 ( V_148 ) ;
F_154 ( V_148 ) ;
F_131 ( V_148 ) ;
switch ( V_148 -> V_172 ) {
case 0 :
break;
case - V_276 :
case - V_277 :
case - V_278 :
case - V_234 :
F_20 ( V_289 L_49
L_50 , V_148 -> V_172 ) ;
F_155 ( V_176 -> V_242 ,
V_176 -> V_290 ) ;
break;
default:
F_101 ( V_148 -> V_172 == - V_229 ) ;
F_20 ( V_289 L_49
L_50 , V_148 -> V_172 ) ;
break;
}
F_76 ( & V_176 -> V_242 -> V_288 , V_148 ) ;
}
static void
V_285 ( struct V_138 * V_148 )
{
struct V_1 * V_2 = V_148 -> V_149 ;
struct V_175 * V_176 = V_148 -> V_180 ;
int V_169 ;
if ( V_176 -> V_291 > 0 && ! V_176 -> V_256 )
V_148 -> V_172 = V_176 -> V_291 ;
F_131 ( V_148 ) ;
V_169 = V_148 -> V_172 ;
if ( V_169 >= 0 ) {
V_148 -> V_165 = V_292 ;
return;
}
F_156 ( V_148 ) ;
V_148 -> V_172 = 0 ;
switch( V_169 ) {
case - V_276 :
case - V_277 :
case - V_278 :
F_134 ( V_148 , 3 * V_145 ) ;
case - V_234 :
V_148 -> V_165 = V_280 ;
if ( V_148 -> V_149 -> V_131 )
F_155 ( V_176 -> V_242 ,
V_176 -> V_290 ) ;
break;
case - V_274 :
case - V_273 :
F_124 ( V_2 ) ;
F_134 ( V_148 , 3 * V_145 ) ;
case - V_279 :
case - V_275 :
V_148 -> V_165 = V_243 ;
break;
case - V_229 :
V_148 -> V_165 = V_281 ;
break;
case - V_142 :
F_74 ( V_148 , V_169 ) ;
break;
default:
if ( V_2 -> V_133 )
F_20 ( L_51 ,
V_2 -> V_16 -> V_18 , - V_169 ) ;
F_74 ( V_148 , V_169 ) ;
}
}
static void
V_280 ( struct V_138 * V_148 )
{
struct V_1 * V_2 = V_148 -> V_149 ;
if ( F_157 ( V_148 -> V_180 ) == 0 ) {
F_38 ( L_52 , V_148 -> V_223 ) ;
goto V_293;
}
F_38 ( L_53 , V_148 -> V_223 ) ;
V_148 -> V_294 ++ ;
if ( F_147 ( V_148 ) ) {
F_74 ( V_148 , - V_234 ) ;
return;
}
if ( F_158 ( V_148 ) ) {
if ( V_2 -> V_133 ) {
F_65 () ;
F_20 ( V_289 L_54 ,
V_2 -> V_16 -> V_18 ,
F_67 ( V_2 -> V_72 ) -> V_65 ) ;
F_68 () ;
}
if ( V_148 -> V_140 & V_295 )
F_74 ( V_148 , - V_234 ) ;
else
F_74 ( V_148 , - V_142 ) ;
return;
}
if ( ! ( V_148 -> V_140 & V_296 ) ) {
V_148 -> V_140 |= V_296 ;
if ( V_2 -> V_133 ) {
F_65 () ;
F_20 ( V_289 L_55 ,
V_2 -> V_16 -> V_18 ,
F_67 ( V_2 -> V_72 ) -> V_65 ) ;
F_68 () ;
}
}
F_124 ( V_2 ) ;
F_159 ( V_148 ) ;
V_293:
V_2 -> V_81 -> V_297 ++ ;
V_148 -> V_165 = V_243 ;
V_148 -> V_172 = 0 ;
}
static void
V_292 ( struct V_138 * V_148 )
{
struct V_1 * V_2 = V_148 -> V_149 ;
struct V_175 * V_176 = V_148 -> V_180 ;
T_7 V_298 = V_148 -> V_156 . V_157 -> V_247 ;
T_6 * V_260 ;
F_131 ( V_148 ) ;
if ( V_148 -> V_140 & V_296 ) {
if ( V_2 -> V_133 ) {
F_65 () ;
F_20 ( V_289 L_56 ,
V_2 -> V_16 -> V_18 ,
F_67 ( V_2 -> V_72 ) -> V_65 ) ;
F_68 () ;
}
V_148 -> V_140 &= ~ V_296 ;
}
F_160 () ;
V_176 -> V_261 . V_181 = V_176 -> V_299 . V_181 ;
F_161 ( memcmp ( & V_176 -> V_261 , & V_176 -> V_299 ,
sizeof( V_176 -> V_261 ) ) != 0 ) ;
if ( V_176 -> V_261 . V_181 < 12 ) {
if ( ! F_158 ( V_148 ) ) {
V_148 -> V_165 = V_243 ;
V_2 -> V_81 -> V_297 ++ ;
goto V_300;
}
F_38 ( L_57 ,
V_2 -> V_16 -> V_18 , V_148 -> V_172 ) ;
V_148 -> V_165 = V_280 ;
goto V_300;
}
V_260 = F_162 ( V_148 ) ;
if ( F_18 ( V_260 ) ) {
if ( V_260 == F_19 ( - V_229 ) )
goto V_300;
return;
}
V_148 -> V_165 = V_287 ;
if ( V_298 ) {
V_148 -> V_172 = F_163 ( V_148 , V_298 , V_176 , V_260 ,
V_148 -> V_156 . V_159 ) ;
}
F_38 ( L_58 , V_148 -> V_223 ,
V_148 -> V_172 ) ;
return;
V_300:
V_148 -> V_172 = 0 ;
if ( V_148 -> V_180 == V_176 ) {
V_176 -> V_291 = V_176 -> V_261 . V_181 = 0 ;
if ( V_148 -> V_149 -> V_131 )
F_155 ( V_176 -> V_242 ,
V_176 -> V_290 ) ;
}
}
static T_6 *
F_144 ( struct V_138 * V_148 )
{
struct V_1 * V_2 = V_148 -> V_149 ;
struct V_175 * V_176 = V_148 -> V_180 ;
T_6 * V_260 = V_176 -> V_301 [ 0 ] . V_258 ;
V_260 = F_164 ( V_176 -> V_242 , V_260 ) ;
* V_260 ++ = V_176 -> V_302 ;
* V_260 ++ = F_165 ( V_303 ) ;
* V_260 ++ = F_165 ( V_304 ) ;
* V_260 ++ = F_165 ( V_2 -> V_77 ) ;
* V_260 ++ = F_165 ( V_2 -> V_80 ) ;
* V_260 ++ = F_165 ( V_148 -> V_156 . V_157 -> V_245 ) ;
V_260 = F_166 ( V_148 , V_260 ) ;
V_176 -> V_305 = F_167 ( & V_176 -> V_301 [ 0 ] , V_260 ) ;
return V_260 ;
}
static T_6 *
F_162 ( struct V_138 * V_148 )
{
struct V_1 * V_2 = V_148 -> V_149 ;
struct V_306 * V_307 = & V_148 -> V_180 -> V_261 . V_182 [ 0 ] ;
int V_181 = V_148 -> V_180 -> V_261 . V_181 >> 2 ;
T_6 * V_260 = V_307 -> V_258 ;
T_3 V_308 ;
int error = - V_235 ;
if ( ( V_148 -> V_180 -> V_261 . V_181 & 3 ) != 0 ) {
F_38 ( L_59
L_60 , V_148 -> V_223 , V_31 ,
V_148 -> V_180 -> V_261 . V_181 ) ;
error = - V_142 ;
goto V_69;
}
if ( ( V_181 -= 3 ) < 0 )
goto V_309;
V_260 += 1 ;
if ( ( V_308 = F_168 ( * V_260 ++ ) ) != V_310 ) {
F_38 ( L_61 ,
V_148 -> V_223 , V_31 , V_308 ) ;
error = - V_142 ;
goto V_311;
}
if ( ( V_308 = F_168 ( * V_260 ++ ) ) != V_312 ) {
if ( -- V_181 < 0 )
goto V_309;
switch ( ( V_308 = F_168 ( * V_260 ++ ) ) ) {
case V_313 :
break;
case V_314 :
F_38 ( L_62 ,
V_148 -> V_223 , V_31 ) ;
error = - V_272 ;
goto V_69;
default:
F_38 ( L_63
L_64 ,
V_148 -> V_223 , V_31 , V_308 ) ;
error = - V_142 ;
goto V_69;
}
if ( -- V_181 < 0 )
goto V_309;
switch ( ( V_308 = F_168 ( * V_260 ++ ) ) ) {
case V_315 :
case V_316 :
case V_317 :
case V_318 :
if ( ! V_148 -> V_237 )
break;
V_148 -> V_237 -- ;
F_38 ( L_65 ,
V_148 -> V_223 , V_31 ) ;
F_159 ( V_148 ) ;
F_133 ( V_148 ) ;
V_148 -> V_165 = V_226 ;
goto V_300;
case V_319 :
case V_320 :
if ( ! V_148 -> V_321 )
break;
V_148 -> V_321 -- ;
F_38 ( L_66 ,
V_148 -> V_223 , V_31 ) ;
V_148 -> V_165 = V_243 ;
goto V_300;
case V_322 :
F_65 () ;
F_20 ( V_289 L_67
L_68 ,
F_67 ( V_2 -> V_72 ) -> V_65 ) ;
F_68 () ;
break;
default:
F_38 ( L_69 ,
V_148 -> V_223 , V_31 , V_308 ) ;
error = - V_142 ;
}
F_38 ( L_70 ,
V_148 -> V_223 , V_31 , V_308 ) ;
goto V_69;
}
V_260 = F_169 ( V_148 , V_260 ) ;
if ( F_18 ( V_260 ) ) {
error = F_21 ( V_260 ) ;
F_38 ( L_71 ,
V_148 -> V_223 , V_31 , error ) ;
goto V_311;
}
V_181 = V_260 - ( T_6 * ) V_307 -> V_258 - 1 ;
if ( V_181 < 0 )
goto V_309;
switch ( ( V_308 = F_168 ( * V_260 ++ ) ) ) {
case V_323 :
return V_260 ;
case V_324 :
F_78 ( L_72
L_73 , V_148 -> V_223 , V_31 ,
( unsigned int ) V_2 -> V_77 ,
F_67 ( V_2 -> V_72 ) -> V_65 ) ;
error = - V_271 ;
goto V_69;
case V_325 :
F_78 ( L_74
L_73 , V_148 -> V_223 , V_31 ,
( unsigned int ) V_2 -> V_77 ,
( unsigned int ) V_2 -> V_80 ,
F_67 ( V_2 -> V_72 ) -> V_65 ) ;
error = - V_272 ;
goto V_69;
case V_326 :
F_78 ( L_75
L_76 ,
V_148 -> V_223 , V_31 ,
F_129 ( V_148 ) ,
V_2 -> V_77 , V_2 -> V_80 ,
F_67 ( V_2 -> V_72 ) -> V_65 ) ;
error = - V_269 ;
goto V_69;
case V_327 :
F_38 ( L_77 ,
V_148 -> V_223 , V_31 ) ;
break;
default:
F_38 ( L_78 ,
V_148 -> V_223 , V_31 , V_308 ) ;
}
V_311:
V_2 -> V_81 -> V_328 ++ ;
if ( V_148 -> V_321 ) {
V_148 -> V_321 -- ;
F_38 ( L_79 ,
V_148 -> V_223 , V_31 ) ;
V_148 -> V_165 = V_243 ;
V_300:
return F_19 ( - V_229 ) ;
}
V_69:
F_74 ( V_148 , error ) ;
F_38 ( L_80 , V_148 -> V_223 ,
V_31 , error ) ;
return F_19 ( error ) ;
V_309:
F_38 ( L_81 , V_148 -> V_223 ,
V_31 ) ;
goto V_311;
}
static void F_170 ( void * V_329 , struct V_330 * V_331 , void * V_332 )
{
}
static int F_171 ( void * V_329 , struct V_330 * V_331 , void * V_332 )
{
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_154 V_155 = {
. V_157 = & V_333 ,
} ;
int V_28 ;
V_155 . V_160 = V_334 . V_335 ( NULL , NULL , 0 ) ;
V_28 = F_100 ( V_2 , & V_155 , V_151 | V_336 ) ;
F_172 ( V_155 . V_160 ) ;
return V_28 ;
}
struct V_138 * F_173 ( struct V_1 * V_2 , struct V_160 * V_337 , int V_106 )
{
struct V_154 V_155 = {
. V_157 = & V_333 ,
. V_160 = V_337 ,
} ;
struct V_162 V_163 = {
. V_164 = V_2 ,
. V_154 = & V_155 ,
. V_167 = & V_168 ,
. V_106 = V_106 ,
} ;
return F_96 ( & V_163 ) ;
}
static void F_174 ( void )
{
F_20 ( V_21 L_82
L_83 ) ;
}
static void F_175 ( const struct V_1 * V_2 ,
const struct V_138 * V_148 )
{
const char * V_338 = L_84 ;
if ( F_75 ( V_148 ) )
V_338 = F_176 ( V_148 -> V_143 ) ;
F_20 ( V_21 L_85 ,
V_148 -> V_223 , V_148 -> V_140 , V_148 -> V_172 ,
V_2 , V_148 -> V_180 , V_148 -> V_265 , V_148 -> V_174 ,
V_2 -> V_16 -> V_18 , V_2 -> V_80 , F_129 ( V_148 ) ,
V_148 -> V_165 , V_338 ) ;
}
void F_177 ( struct V_3 * V_3 )
{
struct V_1 * V_2 ;
struct V_138 * V_148 ;
int V_339 = 0 ;
struct V_4 * V_5 = F_3 ( V_3 , V_6 ) ;
F_4 ( & V_5 -> V_7 ) ;
F_29 (clnt, &sn->all_clients, cl_clients) {
F_4 ( & V_2 -> V_86 ) ;
F_29 (task, &clnt->cl_tasks, tk_task) {
if ( ! V_339 ) {
F_174 () ;
V_339 ++ ;
}
F_175 ( V_2 , V_148 ) ;
}
F_6 ( & V_2 -> V_86 ) ;
}
F_6 ( & V_5 -> V_7 ) ;
}
