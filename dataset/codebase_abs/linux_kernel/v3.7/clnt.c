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
static struct V_1 * F_60 ( struct V_49 * args ,
struct V_1 * V_2 )
{
struct V_50 * V_51 ;
struct V_1 * V_130 ;
int V_31 ;
V_31 = - V_64 ;
F_61 () ;
V_51 = F_62 ( F_63 ( V_2 -> V_66 ) ) ;
F_64 () ;
if ( V_51 == NULL )
goto V_63;
args -> V_58 = V_51 -> V_58 ;
V_130 = F_37 ( args , V_51 ) ;
if ( F_18 ( V_130 ) ) {
V_31 = F_19 ( V_130 ) ;
goto V_131;
}
F_65 ( & V_2 -> V_39 ) ;
V_130 -> V_38 = V_2 ;
V_130 -> V_82 = 0 ;
V_130 -> V_123 = V_2 -> V_123 ;
V_130 -> V_127 = V_2 -> V_127 ;
V_130 -> V_129 = V_2 -> V_129 ;
return V_130 ;
V_131:
F_53 ( V_51 ) ;
V_63:
F_38 ( L_10 , V_36 , V_31 ) ;
return F_55 ( V_31 ) ;
}
struct V_1 * F_66 ( struct V_1 * V_2 )
{
struct V_49 args = {
. V_53 = V_2 -> V_32 ,
. V_73 = V_2 -> V_72 ,
. V_55 = V_2 -> V_75 ,
. V_93 = V_2 -> V_11 -> V_132 ,
. V_90 = V_2 -> V_89 ,
} ;
return F_60 ( & args , V_2 ) ;
}
struct V_1 *
F_67 ( struct V_1 * V_2 , T_2 V_133 )
{
struct V_49 args = {
. V_53 = V_2 -> V_32 ,
. V_73 = V_2 -> V_72 ,
. V_55 = V_2 -> V_75 ,
. V_93 = V_133 ,
. V_90 = V_2 -> V_89 ,
} ;
return F_60 ( & args , V_2 ) ;
}
void F_68 ( struct V_1 * V_2 )
{
struct V_134 * V_135 ;
if ( F_69 ( & V_2 -> V_80 ) )
return;
F_38 ( L_11 , V_2 ) ;
F_4 ( & V_2 -> V_81 ) ;
F_28 (rovr, &clnt->cl_tasks, tk_task) {
if ( ! F_70 ( V_135 ) )
continue;
if ( ! ( V_135 -> V_136 & V_137 ) ) {
V_135 -> V_136 |= V_137 ;
F_71 ( V_135 , - V_138 ) ;
if ( F_72 ( V_135 ) )
F_73 ( V_135 -> V_139 ,
V_135 ) ;
}
}
F_6 ( & V_2 -> V_81 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
F_74 ( L_12 ,
V_2 -> V_71 ,
F_63 ( V_2 -> V_66 ) -> V_58 ) ;
while ( ! F_69 ( & V_2 -> V_80 ) ) {
F_68 ( V_2 ) ;
F_75 ( V_140 ,
F_69 ( & V_2 -> V_80 ) , 1 * V_141 ) ;
}
F_31 ( V_2 ) ;
}
static void
F_76 ( struct V_1 * V_2 )
{
F_74 ( L_13 ,
V_2 -> V_71 ,
F_63 ( V_2 -> V_66 ) -> V_58 ) ;
if ( V_2 -> V_38 != V_2 )
F_31 ( V_2 -> V_38 ) ;
F_7 ( V_2 ) ;
F_11 ( V_2 ) ;
F_52 ( V_2 -> V_78 ) ;
F_51 ( V_2 -> V_89 ) ;
V_2 -> V_78 = NULL ;
F_53 ( F_77 ( V_2 -> V_66 ) ) ;
F_54 () ;
F_51 ( V_2 ) ;
}
static void
F_78 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 == NULL ) {
F_76 ( V_2 ) ;
return;
}
F_65 ( & V_2 -> V_39 ) ;
F_79 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
if ( F_80 ( & V_2 -> V_39 ) )
F_76 ( V_2 ) ;
}
void
F_31 ( struct V_1 * V_2 )
{
F_38 ( L_14 , V_2 ) ;
if ( F_69 ( & V_2 -> V_80 ) )
F_81 ( & V_140 ) ;
if ( F_80 ( & V_2 -> V_39 ) )
F_78 ( V_2 ) ;
}
struct V_1 * F_82 ( struct V_1 * V_142 ,
const struct V_52 * V_53 ,
T_3 V_143 )
{
struct V_1 * V_2 ;
const struct V_54 * V_55 ;
int V_31 ;
F_25 ( V_143 >= V_53 -> V_62 || ! V_53 -> V_55 [ V_143 ] ) ;
V_55 = V_53 -> V_55 [ V_143 ] ;
V_2 = F_66 ( V_142 ) ;
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
void F_83 ( struct V_134 * V_145 )
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
void F_84 ( struct V_134 * V_145 , struct V_1 * V_2 )
{
if ( V_2 != NULL ) {
F_83 ( V_145 ) ;
V_145 -> V_146 = V_2 ;
F_65 ( & V_2 -> V_39 ) ;
if ( V_2 -> V_123 )
V_145 -> V_136 |= V_148 ;
if ( F_85 () ) {
struct V_50 * V_51 ;
F_61 () ;
V_51 = F_63 ( V_2 -> V_66 ) ;
if ( V_51 -> V_149 )
V_145 -> V_136 |= V_150 ;
F_64 () ;
}
F_4 ( & V_2 -> V_81 ) ;
F_86 ( & V_145 -> V_147 , & V_2 -> V_80 ) ;
F_6 ( & V_2 -> V_81 ) ;
}
}
void F_87 ( struct V_134 * V_145 , struct V_1 * V_2 )
{
F_83 ( V_145 ) ;
F_84 ( V_145 , V_2 ) ;
}
static void
F_88 ( struct V_134 * V_145 , const struct V_151 * V_152 )
{
if ( V_152 != NULL ) {
V_145 -> V_153 . V_154 = V_152 -> V_154 ;
V_145 -> V_153 . V_155 = V_152 -> V_155 ;
V_145 -> V_153 . V_156 = V_152 -> V_156 ;
if ( V_152 -> V_157 != NULL )
V_145 -> V_153 . V_157 = F_89 ( V_152 -> V_157 ) ;
}
}
static void
F_90 ( struct V_134 * V_145 , void * V_158 )
{
}
struct V_134 * F_91 ( const struct V_159 * V_160 )
{
struct V_134 * V_145 ;
V_145 = F_92 ( V_160 ) ;
if ( F_18 ( V_145 ) )
goto V_144;
F_84 ( V_145 , V_160 -> V_161 ) ;
F_88 ( V_145 , V_160 -> V_151 ) ;
if ( V_145 -> V_162 == NULL )
F_93 ( V_145 ) ;
F_65 ( & V_145 -> V_163 ) ;
F_94 ( V_145 ) ;
V_144:
return V_145 ;
}
int F_95 ( struct V_1 * V_2 , const struct V_151 * V_152 , int V_120 )
{
struct V_134 * V_145 ;
struct V_159 V_160 = {
. V_161 = V_2 ,
. V_151 = V_152 ,
. V_164 = & V_165 ,
. V_120 = V_120 ,
} ;
int V_166 ;
F_25 ( V_120 & V_167 ) ;
V_145 = F_91 ( & V_160 ) ;
if ( F_18 ( V_145 ) )
return F_19 ( V_145 ) ;
V_166 = V_145 -> V_168 ;
F_96 ( V_145 ) ;
return V_166 ;
}
int
F_97 ( struct V_1 * V_2 , const struct V_151 * V_152 , int V_120 ,
const struct V_169 * V_170 , void * V_158 )
{
struct V_134 * V_145 ;
struct V_159 V_160 = {
. V_161 = V_2 ,
. V_151 = V_152 ,
. V_164 = V_170 ,
. V_171 = V_158 ,
. V_120 = V_120 | V_167 ,
} ;
V_145 = F_91 ( & V_160 ) ;
if ( F_18 ( V_145 ) )
return F_19 ( V_145 ) ;
F_96 ( V_145 ) ;
return 0 ;
}
struct V_134 * F_98 ( struct V_172 * V_173 ,
const struct V_169 * V_170 )
{
struct V_134 * V_145 ;
struct V_174 * V_175 = & V_173 -> V_176 ;
struct V_159 V_160 = {
. V_164 = V_170 ,
} ;
F_38 ( L_15 , V_173 ) ;
V_145 = F_92 ( & V_160 ) ;
if ( F_18 ( V_145 ) ) {
F_99 ( V_173 ) ;
goto V_144;
}
V_145 -> V_177 = V_173 ;
V_175 -> V_24 = V_175 -> V_178 [ 0 ] . V_179 + V_175 -> V_180 +
V_175 -> V_181 [ 0 ] . V_179 ;
V_145 -> V_162 = V_182 ;
F_65 ( & V_145 -> V_163 ) ;
F_25 ( F_100 ( & V_145 -> V_163 ) != 2 ) ;
F_94 ( V_145 ) ;
V_144:
F_38 ( L_16 , V_145 ) ;
return V_145 ;
}
void
F_93 ( struct V_134 * V_145 )
{
V_145 -> V_162 = V_183 ;
}
T_4 F_101 ( struct V_1 * V_2 , struct V_184 * V_185 , T_4 V_186 )
{
T_4 V_187 ;
struct V_50 * V_51 ;
F_61 () ;
V_51 = F_63 ( V_2 -> V_66 ) ;
V_187 = V_51 -> V_103 ;
if ( V_187 > V_186 )
V_187 = V_186 ;
memcpy ( V_185 , & V_51 -> V_188 , V_187 ) ;
F_64 () ;
return V_187 ;
}
const char * F_102 ( struct V_1 * V_2 ,
enum V_189 V_190 )
{
struct V_50 * V_51 ;
V_51 = F_63 ( V_2 -> V_66 ) ;
if ( V_51 -> V_191 [ V_190 ] != NULL )
return V_51 -> V_191 [ V_190 ] ;
else
return L_17 ;
}
static int F_103 ( struct V_3 * V_3 , struct V_184 * V_192 , T_4 V_193 ,
struct V_184 * V_185 , int V_194 )
{
struct V_195 * V_196 ;
int V_31 ;
V_31 = F_104 ( V_3 , V_192 -> V_111 ,
V_197 , V_198 , & V_196 , 1 ) ;
if ( V_31 < 0 ) {
F_38 ( L_18 , V_31 ) ;
goto V_144;
}
switch ( V_192 -> V_111 ) {
case V_114 :
V_31 = F_105 ( V_196 ,
(struct V_184 * ) & V_199 ,
sizeof( V_199 ) ) ;
break;
case V_117 :
V_31 = F_105 ( V_196 ,
(struct V_184 * ) & V_200 ,
sizeof( V_200 ) ) ;
break;
default:
V_31 = - V_201 ;
goto V_144;
}
if ( V_31 < 0 ) {
F_38 ( L_19 , V_31 ) ;
goto V_202;
}
V_31 = F_106 ( V_196 , V_192 , V_193 , 0 ) ;
if ( V_31 < 0 ) {
F_38 ( L_20 , V_31 ) ;
goto V_202;
}
V_31 = F_107 ( V_196 , V_185 , & V_194 ) ;
if ( V_31 < 0 ) {
F_38 ( L_21 , V_31 ) ;
goto V_202;
}
V_31 = 0 ;
if ( V_185 -> V_111 == V_117 ) {
struct V_109 * V_110 = (struct V_109 * ) V_185 ;
V_110 -> V_203 = 0 ;
}
F_38 ( L_22 , V_36 ) ;
V_202:
F_108 ( V_196 ) ;
V_144:
return V_31 ;
}
static int F_109 ( int V_204 , struct V_184 * V_185 , T_4 V_194 )
{
switch ( V_204 ) {
case V_114 :
if ( V_194 < sizeof( V_199 ) )
return - V_60 ;
memcpy ( V_185 , & V_199 ,
sizeof( V_199 ) ) ;
break;
case V_117 :
if ( V_194 < sizeof( V_200 ) )
return - V_60 ;
memcpy ( V_185 , & V_200 ,
sizeof( V_200 ) ) ;
default:
F_38 ( L_23 ,
V_36 ) ;
return - V_201 ;
}
F_38 ( L_24 , V_36 ) ;
return 0 ;
}
int F_110 ( struct V_1 * V_2 , struct V_184 * V_185 , T_4 V_194 )
{
struct V_205 V_102 ;
struct V_184 * V_192 = (struct V_184 * ) & V_102 ;
struct V_50 * V_51 ;
struct V_3 * V_3 ;
T_4 V_193 ;
int V_31 ;
F_61 () ;
V_51 = F_63 ( V_2 -> V_66 ) ;
V_193 = V_51 -> V_103 ;
memcpy ( V_192 , & V_51 -> V_188 , V_193 ) ;
V_3 = F_111 ( V_51 -> V_206 ) ;
F_64 () ;
F_112 ( V_192 , 0 ) ;
V_31 = F_103 ( V_3 , V_192 , V_193 , V_185 , V_194 ) ;
F_113 ( V_3 ) ;
if ( V_31 != 0 )
return F_109 ( V_192 -> V_111 , V_185 , V_194 ) ;
return 0 ;
}
void
F_114 ( struct V_1 * V_2 , unsigned int V_207 , unsigned int V_208 )
{
struct V_50 * V_51 ;
F_61 () ;
V_51 = F_63 ( V_2 -> V_66 ) ;
if ( V_51 -> V_209 -> V_210 )
V_51 -> V_209 -> V_210 ( V_51 , V_207 , V_208 ) ;
F_64 () ;
}
int F_115 ( struct V_1 * V_2 )
{
int V_98 ;
F_61 () ;
V_98 = F_63 ( V_2 -> V_66 ) -> V_211 ;
F_64 () ;
return V_98 ;
}
struct V_3 * F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_212 ;
F_61 () ;
V_212 = F_63 ( V_2 -> V_66 ) -> V_206 ;
F_64 () ;
return V_212 ;
}
T_4 F_116 ( struct V_1 * V_2 )
{
T_4 V_212 ;
F_61 () ;
V_212 = F_63 ( V_2 -> V_66 ) -> V_213 ;
F_64 () ;
return V_212 ;
}
void F_117 ( struct V_1 * V_2 )
{
if ( V_2 -> V_82 ) {
F_61 () ;
F_118 ( F_63 ( V_2 -> V_66 ) ) ;
F_64 () ;
}
}
int
F_119 ( struct V_134 * V_145 )
{
if ( F_120 ( V_145 ) )
return 0 ;
V_145 -> V_162 = V_183 ;
if ( V_145 -> V_170 -> V_214 != NULL )
V_145 -> V_162 = V_215 ;
return 1 ;
}
int
F_121 ( struct V_134 * V_145 )
{
if ( F_120 ( V_145 ) )
return 0 ;
V_145 -> V_162 = V_183 ;
return 1 ;
}
static const char * F_122 ( const struct V_134 * V_145 )
{
const struct V_216 * V_217 = V_145 -> V_153 . V_154 ;
if ( V_217 ) {
if ( V_217 -> V_218 )
return V_217 -> V_218 ;
else
return L_25 ;
} else
return L_26 ;
}
static void
V_183 ( struct V_134 * V_145 )
{
struct V_1 * V_2 = V_145 -> V_146 ;
F_38 ( L_27 , V_145 -> V_219 ,
V_2 -> V_71 , V_2 -> V_75 ,
F_122 ( V_145 ) ,
( F_123 ( V_145 ) ? L_28 : L_29 ) ) ;
V_145 -> V_153 . V_154 -> V_220 ++ ;
V_2 -> V_76 -> V_221 ++ ;
V_145 -> V_162 = V_222 ;
}
static void
V_222 ( struct V_134 * V_145 )
{
F_124 ( V_145 ) ;
V_145 -> V_168 = 0 ;
V_145 -> V_162 = V_223 ;
F_125 ( V_145 ) ;
}
static void
V_223 ( struct V_134 * V_145 )
{
int V_166 = V_145 -> V_168 ;
F_124 ( V_145 ) ;
V_145 -> V_168 = 0 ;
if ( V_166 >= 0 ) {
if ( V_145 -> V_177 ) {
V_145 -> V_162 = V_224 ;
return;
}
F_20 ( V_35 L_30 ,
V_36 , V_166 ) ;
F_71 ( V_145 , - V_138 ) ;
return;
}
if ( V_145 -> V_177 ) {
F_20 ( V_35 L_31 ,
V_36 , V_166 ) ;
F_126 ( V_145 ) ;
}
switch ( V_166 ) {
case - V_64 :
F_127 ( V_145 , V_141 >> 2 ) ;
case - V_225 :
V_145 -> V_162 = V_222 ;
return;
case - V_138 :
break;
default:
F_20 ( V_35 L_32 ,
V_36 , V_166 ) ;
break;
}
F_71 ( V_145 , V_166 ) ;
}
static void
V_224 ( struct V_134 * V_145 )
{
F_124 ( V_145 ) ;
V_145 -> V_162 = V_226 ;
V_145 -> V_168 = 0 ;
V_145 -> V_146 -> V_76 -> V_227 ++ ;
F_128 ( V_145 ) ;
}
static void
V_226 ( struct V_134 * V_145 )
{
int V_166 = V_145 -> V_168 ;
F_124 ( V_145 ) ;
V_145 -> V_168 = 0 ;
V_145 -> V_162 = V_224 ;
switch ( V_166 ) {
case 0 :
if ( F_129 ( V_145 ) )
V_145 -> V_162 = V_228 ;
return;
case - V_229 :
F_127 ( V_145 , 3 * V_141 ) ;
case - V_225 :
V_166 = - V_230 ;
if ( ! V_145 -> V_231 )
break;
V_145 -> V_231 -- ;
F_38 ( L_33 ,
V_145 -> V_219 , V_36 ) ;
return;
}
F_38 ( L_34 ,
V_145 -> V_219 , V_36 , V_166 ) ;
F_71 ( V_145 , V_166 ) ;
}
static void
V_228 ( struct V_134 * V_145 )
{
unsigned int V_232 = V_145 -> V_177 -> V_233 -> V_234 -> V_235 ;
struct V_172 * V_173 = V_145 -> V_177 ;
struct V_50 * V_51 = V_145 -> V_236 ;
struct V_216 * V_217 = V_145 -> V_153 . V_154 ;
F_124 ( V_145 ) ;
V_145 -> V_168 = 0 ;
V_145 -> V_162 = V_237 ;
if ( V_173 -> V_238 )
return;
if ( V_217 -> V_239 != 0 ) {
F_25 ( V_217 -> V_240 == 0 ) ;
if ( V_217 -> V_241 != NULL )
F_25 ( V_217 -> V_242 == 0 ) ;
}
V_173 -> V_243 = V_244 + ( V_232 << 1 ) + V_217 -> V_240 ;
V_173 -> V_243 <<= 2 ;
V_173 -> V_245 = V_246 + V_232 + V_217 -> V_242 ;
V_173 -> V_245 <<= 2 ;
V_173 -> V_238 = V_51 -> V_209 -> V_247 ( V_145 ,
V_173 -> V_243 + V_173 -> V_245 ) ;
if ( V_173 -> V_238 != NULL )
return;
F_38 ( L_35 , V_145 -> V_219 ) ;
if ( F_123 ( V_145 ) || ! F_130 ( V_248 ) ) {
V_145 -> V_162 = V_228 ;
F_127 ( V_145 , V_141 >> 4 ) ;
return;
}
F_71 ( V_145 , - V_249 ) ;
}
static inline int
F_131 ( struct V_134 * V_145 )
{
return V_145 -> V_177 -> V_176 . V_24 == 0 ;
}
static inline void
F_132 ( struct V_134 * V_145 )
{
V_145 -> V_177 -> V_176 . V_24 = 0 ;
V_145 -> V_177 -> V_250 = 0 ;
}
static inline void
F_133 ( struct V_174 * V_185 , void * V_251 , T_4 V_24 )
{
V_185 -> V_178 [ 0 ] . V_252 = V_251 ;
V_185 -> V_178 [ 0 ] . V_179 = V_24 ;
V_185 -> V_181 [ 0 ] . V_179 = 0 ;
V_185 -> V_180 = 0 ;
V_185 -> V_120 = 0 ;
V_185 -> V_24 = 0 ;
V_185 -> V_194 = V_24 ;
}
static void
F_134 ( struct V_134 * V_145 )
{
struct V_172 * V_173 = V_145 -> V_177 ;
T_5 V_253 ;
T_6 * V_254 ;
F_124 ( V_145 ) ;
F_133 ( & V_173 -> V_176 ,
V_173 -> V_238 ,
V_173 -> V_243 ) ;
F_133 ( & V_173 -> V_255 ,
( char * ) V_173 -> V_238 + V_173 -> V_243 ,
V_173 -> V_245 ) ;
V_254 = F_135 ( V_145 ) ;
if ( V_254 == NULL ) {
F_20 ( V_27 L_36 ) ;
F_71 ( V_145 , - V_138 ) ;
return;
}
V_253 = V_145 -> V_153 . V_154 -> V_256 ;
if ( V_253 == NULL )
return;
V_145 -> V_168 = F_136 ( V_145 , V_253 , V_173 , V_254 ,
V_145 -> V_153 . V_155 ) ;
}
static void
V_237 ( struct V_134 * V_145 )
{
struct V_50 * V_51 = V_145 -> V_236 ;
F_124 ( V_145 ) ;
V_145 -> V_162 = V_257 ;
if ( ! F_45 ( V_51 ) ) {
V_145 -> V_162 = V_258 ;
V_145 -> V_259 = V_51 -> V_260 ;
V_51 -> V_209 -> V_261 ( V_145 ) ;
}
}
static void
V_258 ( struct V_134 * V_145 )
{
int V_166 = - V_138 ;
if ( V_145 -> V_168 >= 0 ) {
F_124 ( V_145 ) ;
V_145 -> V_168 = 0 ;
V_145 -> V_162 = V_257 ;
return;
}
F_137 ( V_145 ) ;
switch ( V_145 -> V_168 ) {
case - V_64 :
F_38 ( L_37 , V_145 -> V_219 ) ;
F_127 ( V_145 , V_141 >> 2 ) ;
goto V_262;
case - V_230 :
F_38 ( L_38
L_39 , V_145 -> V_219 ) ;
if ( V_145 -> V_153 . V_154 -> V_239 == 0 ) {
V_166 = - V_263 ;
break;
}
if ( V_145 -> V_264 == 0 )
break;
V_145 -> V_264 -- ;
F_127 ( V_145 , 3 * V_141 ) ;
goto V_262;
case - V_229 :
F_38 ( L_40 ,
V_145 -> V_219 ) ;
goto V_262;
case - V_265 :
F_38 ( L_41 ,
V_145 -> V_219 ) ;
break;
case - V_266 :
F_38 ( L_42 ,
V_145 -> V_219 ) ;
V_145 -> V_168 = 0 ;
V_145 -> V_162 = V_237 ;
return;
case - V_267 :
case - V_268 :
case - V_269 :
case - V_270 :
case - V_271 :
case - V_272 :
case - V_273 :
F_38 ( L_43 ,
V_145 -> V_219 , V_145 -> V_168 ) ;
if ( ! F_138 ( V_145 ) ) {
F_127 ( V_145 , 5 * V_141 ) ;
goto V_262;
}
V_166 = V_145 -> V_168 ;
break;
default:
F_38 ( L_44 ,
V_145 -> V_219 , - V_145 -> V_168 ) ;
}
F_71 ( V_145 , V_166 ) ;
return;
V_262:
V_145 -> V_162 = V_274 ;
}
static void
V_257 ( struct V_134 * V_145 )
{
struct V_50 * V_51 = V_145 -> V_236 ;
F_38 ( L_45 ,
V_145 -> V_219 , V_51 ,
( F_139 ( V_51 ) ? L_46 : L_47 ) ) ;
V_145 -> V_162 = V_275 ;
if ( ! F_139 ( V_51 ) ) {
V_145 -> V_162 = V_276 ;
if ( V_145 -> V_168 < 0 )
return;
F_140 ( V_145 ) ;
}
}
static void
V_276 ( struct V_134 * V_145 )
{
struct V_1 * V_2 = V_145 -> V_146 ;
int V_166 = V_145 -> V_168 ;
F_124 ( V_145 ) ;
V_145 -> V_168 = 0 ;
if ( V_166 >= 0 || V_166 == - V_225 ) {
V_2 -> V_76 -> V_277 ++ ;
V_145 -> V_162 = V_275 ;
return;
}
F_141 ( V_145 , V_166 ) ;
switch ( V_166 ) {
case - V_229 :
V_145 -> V_162 = V_274 ;
break;
default:
F_71 ( V_145 , - V_138 ) ;
}
}
static void
V_275 ( struct V_134 * V_145 )
{
F_124 ( V_145 ) ;
V_145 -> V_162 = V_278 ;
if ( V_145 -> V_168 < 0 )
return;
V_145 -> V_168 = F_142 ( V_145 ) ;
if ( V_145 -> V_168 != 0 )
return;
V_145 -> V_162 = V_279 ;
if ( F_131 ( V_145 ) ) {
F_25 ( V_145 -> V_177 -> V_250 != 0 ) ;
F_134 ( V_145 ) ;
if ( V_145 -> V_168 != 0 ) {
if ( V_145 -> V_168 == - V_225 )
F_127 ( V_145 , V_141 >> 4 ) ;
else
F_71 ( V_145 , V_145 -> V_168 ) ;
return;
}
}
F_143 ( V_145 ) ;
if ( V_145 -> V_168 < 0 )
return;
V_279 ( V_145 ) ;
if ( F_144 ( V_145 ) )
return;
V_145 -> V_162 = V_280 ;
F_73 ( & V_145 -> V_236 -> V_281 , V_145 ) ;
}
static void
V_279 ( struct V_134 * V_145 )
{
V_145 -> V_162 = V_278 ;
if ( V_145 -> V_168 == 0 ) {
F_145 ( V_145 ) ;
F_132 ( V_145 ) ;
return;
}
switch ( V_145 -> V_168 ) {
case - V_225 :
break;
default:
F_124 ( V_145 ) ;
F_145 ( V_145 ) ;
F_132 ( V_145 ) ;
break;
case - V_267 :
case - V_270 :
case - V_271 :
case - V_272 :
if ( F_138 ( V_145 ) ) {
F_145 ( V_145 ) ;
F_71 ( V_145 , V_145 -> V_168 ) ;
break;
}
case - V_268 :
case - V_269 :
case - V_273 :
F_132 ( V_145 ) ;
}
}
static void
V_182 ( struct V_134 * V_145 )
{
struct V_172 * V_173 = V_145 -> V_177 ;
F_25 ( V_145 -> V_168 != 0 ) ;
V_145 -> V_168 = F_142 ( V_145 ) ;
if ( V_145 -> V_168 == - V_225 ) {
V_145 -> V_168 = 0 ;
V_145 -> V_162 = V_182 ;
return;
}
V_145 -> V_162 = V_280 ;
if ( V_145 -> V_168 < 0 ) {
F_20 ( V_282 L_48
L_49 , V_145 -> V_168 ) ;
return;
}
F_143 ( V_145 ) ;
F_145 ( V_145 ) ;
F_124 ( V_145 ) ;
switch ( V_145 -> V_168 ) {
case 0 :
break;
case - V_270 :
case - V_271 :
case - V_272 :
case - V_229 :
F_20 ( V_282 L_48
L_49 , V_145 -> V_168 ) ;
F_146 ( V_145 -> V_236 ,
V_173 -> V_283 ) ;
break;
default:
F_25 ( V_145 -> V_168 == - V_225 ) ;
F_20 ( V_282 L_48
L_49 , V_145 -> V_168 ) ;
break;
}
F_73 ( & V_173 -> V_284 -> V_281 , V_145 ) ;
}
static void
V_278 ( struct V_134 * V_145 )
{
struct V_1 * V_2 = V_145 -> V_146 ;
struct V_172 * V_173 = V_145 -> V_177 ;
int V_166 ;
if ( V_173 -> V_285 > 0 && ! V_173 -> V_250 )
V_145 -> V_168 = V_173 -> V_285 ;
F_124 ( V_145 ) ;
V_166 = V_145 -> V_168 ;
if ( V_166 >= 0 ) {
V_145 -> V_162 = V_286 ;
return;
}
F_147 ( V_145 ) ;
V_145 -> V_168 = 0 ;
switch( V_166 ) {
case - V_270 :
case - V_271 :
case - V_272 :
F_127 ( V_145 , 3 * V_141 ) ;
case - V_229 :
V_145 -> V_162 = V_274 ;
if ( V_145 -> V_146 -> V_127 )
F_146 ( V_145 -> V_236 ,
V_173 -> V_283 ) ;
break;
case - V_268 :
case - V_267 :
F_117 ( V_2 ) ;
F_127 ( V_145 , 3 * V_141 ) ;
case - V_273 :
case - V_269 :
V_145 -> V_162 = V_237 ;
break;
case - V_225 :
V_145 -> V_162 = V_275 ;
break;
case - V_138 :
F_71 ( V_145 , V_166 ) ;
break;
default:
if ( V_2 -> V_129 )
F_20 ( L_50 ,
V_2 -> V_71 , - V_166 ) ;
F_71 ( V_145 , V_166 ) ;
}
}
static void
V_274 ( struct V_134 * V_145 )
{
struct V_1 * V_2 = V_145 -> V_146 ;
if ( F_148 ( V_145 -> V_177 ) == 0 ) {
F_38 ( L_51 , V_145 -> V_219 ) ;
goto V_287;
}
F_38 ( L_52 , V_145 -> V_219 ) ;
V_145 -> V_288 ++ ;
if ( F_138 ( V_145 ) ) {
F_71 ( V_145 , - V_229 ) ;
return;
}
if ( F_149 ( V_145 ) ) {
if ( V_2 -> V_129 ) {
F_61 () ;
F_20 ( V_282 L_53 ,
V_2 -> V_71 ,
F_63 ( V_2 -> V_66 ) -> V_58 ) ;
F_64 () ;
}
if ( V_145 -> V_136 & V_289 )
F_71 ( V_145 , - V_229 ) ;
else
F_71 ( V_145 , - V_138 ) ;
return;
}
if ( ! ( V_145 -> V_136 & V_290 ) ) {
V_145 -> V_136 |= V_290 ;
if ( V_2 -> V_129 ) {
F_61 () ;
F_20 ( V_282 L_54 ,
V_2 -> V_71 ,
F_63 ( V_2 -> V_66 ) -> V_58 ) ;
F_64 () ;
}
}
F_117 ( V_2 ) ;
F_150 ( V_145 ) ;
V_287:
V_2 -> V_76 -> V_291 ++ ;
V_145 -> V_162 = V_237 ;
V_145 -> V_168 = 0 ;
}
static void
V_286 ( struct V_134 * V_145 )
{
struct V_1 * V_2 = V_145 -> V_146 ;
struct V_172 * V_173 = V_145 -> V_177 ;
T_7 V_292 = V_145 -> V_153 . V_154 -> V_241 ;
T_6 * V_254 ;
F_124 ( V_145 ) ;
if ( V_145 -> V_136 & V_290 ) {
if ( V_2 -> V_129 ) {
F_61 () ;
F_20 ( V_282 L_55 ,
V_2 -> V_71 ,
F_63 ( V_2 -> V_66 ) -> V_58 ) ;
F_64 () ;
}
V_145 -> V_136 &= ~ V_290 ;
}
F_151 () ;
V_173 -> V_255 . V_24 = V_173 -> V_293 . V_24 ;
F_152 ( memcmp ( & V_173 -> V_255 , & V_173 -> V_293 ,
sizeof( V_173 -> V_255 ) ) != 0 ) ;
if ( V_173 -> V_255 . V_24 < 12 ) {
if ( ! F_149 ( V_145 ) ) {
V_145 -> V_162 = V_237 ;
V_2 -> V_76 -> V_291 ++ ;
goto V_294;
}
F_38 ( L_56 ,
V_2 -> V_71 , V_145 -> V_168 ) ;
V_145 -> V_162 = V_274 ;
goto V_294;
}
V_254 = F_153 ( V_145 ) ;
if ( F_18 ( V_254 ) ) {
if ( V_254 == F_55 ( - V_225 ) )
goto V_294;
return;
}
V_145 -> V_162 = V_280 ;
if ( V_292 ) {
V_145 -> V_168 = F_154 ( V_145 , V_292 , V_173 , V_254 ,
V_145 -> V_153 . V_156 ) ;
}
F_38 ( L_57 , V_145 -> V_219 ,
V_145 -> V_168 ) ;
return;
V_294:
V_145 -> V_168 = 0 ;
if ( V_145 -> V_177 == V_173 ) {
V_173 -> V_285 = V_173 -> V_255 . V_24 = 0 ;
if ( V_145 -> V_146 -> V_127 )
F_146 ( V_145 -> V_236 ,
V_173 -> V_283 ) ;
}
}
static T_6 *
F_135 ( struct V_134 * V_145 )
{
struct V_1 * V_2 = V_145 -> V_146 ;
struct V_172 * V_173 = V_145 -> V_177 ;
T_6 * V_254 = V_173 -> V_295 [ 0 ] . V_252 ;
V_254 = F_155 ( V_145 -> V_236 , V_254 ) ;
* V_254 ++ = V_173 -> V_296 ;
* V_254 ++ = F_156 ( V_297 ) ;
* V_254 ++ = F_156 ( V_298 ) ;
* V_254 ++ = F_156 ( V_2 -> V_72 ) ;
* V_254 ++ = F_156 ( V_2 -> V_75 ) ;
* V_254 ++ = F_156 ( V_145 -> V_153 . V_154 -> V_239 ) ;
V_254 = F_157 ( V_145 , V_254 ) ;
V_173 -> V_299 = F_158 ( & V_173 -> V_295 [ 0 ] , V_254 ) ;
return V_254 ;
}
static T_6 *
F_153 ( struct V_134 * V_145 )
{
struct V_1 * V_2 = V_145 -> V_146 ;
struct V_300 * V_301 = & V_145 -> V_177 -> V_255 . V_178 [ 0 ] ;
int V_24 = V_145 -> V_177 -> V_255 . V_24 >> 2 ;
T_6 * V_254 = V_301 -> V_252 ;
T_3 V_302 ;
int error = - V_230 ;
if ( ( V_145 -> V_177 -> V_255 . V_24 & 3 ) != 0 ) {
F_38 ( L_58
L_59 , V_145 -> V_219 , V_36 ,
V_145 -> V_177 -> V_255 . V_24 ) ;
goto V_303;
}
if ( ( V_24 -= 3 ) < 0 )
goto V_304;
V_254 += 1 ;
if ( ( V_302 = F_159 ( * V_254 ++ ) ) != V_305 ) {
F_38 ( L_60 ,
V_145 -> V_219 , V_36 , V_302 ) ;
goto V_306;
}
if ( ( V_302 = F_159 ( * V_254 ++ ) ) != V_307 ) {
if ( -- V_24 < 0 )
goto V_304;
switch ( ( V_302 = F_159 ( * V_254 ++ ) ) ) {
case V_308 :
break;
case V_309 :
F_38 ( L_61 ,
V_145 -> V_219 , V_36 ) ;
error = - V_266 ;
goto V_63;
default:
F_38 ( L_62
L_63 ,
V_145 -> V_219 , V_36 , V_302 ) ;
goto V_303;
}
if ( -- V_24 < 0 )
goto V_304;
switch ( ( V_302 = F_159 ( * V_254 ++ ) ) ) {
case V_310 :
case V_311 :
case V_312 :
case V_313 :
if ( ! V_145 -> V_231 )
break;
V_145 -> V_231 -- ;
F_38 ( L_64 ,
V_145 -> V_219 , V_36 ) ;
F_150 ( V_145 ) ;
F_126 ( V_145 ) ;
V_145 -> V_162 = V_222 ;
goto V_294;
case V_314 :
case V_315 :
if ( ! V_145 -> V_316 )
break;
V_145 -> V_316 -- ;
F_38 ( L_65 ,
V_145 -> V_219 , V_36 ) ;
V_145 -> V_162 = V_237 ;
goto V_294;
case V_317 :
F_61 () ;
F_20 ( V_282 L_66
L_67 ,
F_63 ( V_2 -> V_66 ) -> V_58 ) ;
F_64 () ;
break;
default:
F_38 ( L_68 ,
V_145 -> V_219 , V_36 , V_302 ) ;
error = - V_138 ;
}
F_38 ( L_69 ,
V_145 -> V_219 , V_36 , V_302 ) ;
goto V_63;
}
if ( ! ( V_254 = F_160 ( V_145 , V_254 ) ) ) {
F_38 ( L_70 ,
V_145 -> V_219 , V_36 ) ;
goto V_306;
}
V_24 = V_254 - ( T_6 * ) V_301 -> V_252 - 1 ;
if ( V_24 < 0 )
goto V_304;
switch ( ( V_302 = F_159 ( * V_254 ++ ) ) ) {
case V_318 :
return V_254 ;
case V_319 :
F_74 ( L_71
L_72 , V_145 -> V_219 , V_36 ,
( unsigned int ) V_2 -> V_72 ,
F_63 ( V_2 -> V_66 ) -> V_58 ) ;
error = - V_265 ;
goto V_63;
case V_320 :
F_74 ( L_73
L_72 , V_145 -> V_219 , V_36 ,
( unsigned int ) V_2 -> V_72 ,
( unsigned int ) V_2 -> V_75 ,
F_63 ( V_2 -> V_66 ) -> V_58 ) ;
error = - V_266 ;
goto V_63;
case V_321 :
F_74 ( L_74
L_75 ,
V_145 -> V_219 , V_36 ,
F_122 ( V_145 ) ,
V_2 -> V_72 , V_2 -> V_75 ,
F_63 ( V_2 -> V_66 ) -> V_58 ) ;
error = - V_263 ;
goto V_63;
case V_322 :
F_38 ( L_76 ,
V_145 -> V_219 , V_36 ) ;
break;
default:
F_38 ( L_77 ,
V_145 -> V_219 , V_36 , V_302 ) ;
}
V_306:
V_2 -> V_76 -> V_323 ++ ;
if ( V_145 -> V_316 ) {
V_145 -> V_316 -- ;
F_38 ( L_78 ,
V_145 -> V_219 , V_36 ) ;
V_145 -> V_162 = V_237 ;
V_294:
return F_55 ( - V_225 ) ;
}
V_303:
error = - V_138 ;
V_63:
F_71 ( V_145 , error ) ;
F_38 ( L_79 , V_145 -> V_219 ,
V_36 , error ) ;
return F_55 ( error ) ;
V_304:
F_38 ( L_80 , V_145 -> V_219 ,
V_36 ) ;
goto V_306;
}
static void F_161 ( void * V_324 , struct V_325 * V_326 , void * V_327 )
{
}
static int F_162 ( void * V_324 , struct V_325 * V_326 , void * V_327 )
{
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_151 V_152 = {
. V_154 = & V_328 ,
} ;
int V_31 ;
V_152 . V_157 = V_329 . V_330 ( NULL , NULL , 0 ) ;
V_31 = F_95 ( V_2 , & V_152 , V_148 | V_331 ) ;
F_163 ( V_152 . V_157 ) ;
return V_31 ;
}
struct V_134 * F_164 ( struct V_1 * V_2 , struct V_157 * V_332 , int V_120 )
{
struct V_151 V_152 = {
. V_154 = & V_328 ,
. V_157 = V_332 ,
} ;
struct V_159 V_160 = {
. V_161 = V_2 ,
. V_151 = & V_152 ,
. V_164 = & V_165 ,
. V_120 = V_120 ,
} ;
return F_91 ( & V_160 ) ;
}
static void F_165 ( void )
{
F_20 ( V_27 L_81
L_82 ) ;
}
static void F_166 ( const struct V_1 * V_2 ,
const struct V_134 * V_145 )
{
const char * V_333 = L_83 ;
if ( F_72 ( V_145 ) )
V_333 = F_167 ( V_145 -> V_139 ) ;
F_20 ( V_27 L_84 ,
V_145 -> V_219 , V_145 -> V_136 , V_145 -> V_168 ,
V_2 , V_145 -> V_177 , V_145 -> V_259 , V_145 -> V_170 ,
V_2 -> V_71 , V_2 -> V_75 , F_122 ( V_145 ) ,
V_145 -> V_162 , V_333 ) ;
}
void F_168 ( struct V_3 * V_3 )
{
struct V_1 * V_2 ;
struct V_134 * V_145 ;
int V_334 = 0 ;
struct V_4 * V_5 = F_3 ( V_3 , V_6 ) ;
F_4 ( & V_5 -> V_7 ) ;
F_28 (clnt, &sn->all_clients, cl_clients) {
F_4 ( & V_2 -> V_81 ) ;
F_28 (task, &clnt->cl_tasks, tk_task) {
if ( ! V_334 ) {
F_165 () ;
V_334 ++ ;
}
F_166 ( V_2 , V_145 ) ;
}
F_6 ( & V_2 -> V_81 ) ;
}
F_6 ( & V_5 -> V_7 ) ;
}
