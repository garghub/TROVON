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
struct V_16 * V_21 , * V_16 ;
V_21 = F_15 ( V_17 , V_18 ) ;
if ( V_21 == NULL ) {
F_16 ( L_1 , V_18 ) ;
return V_21 ;
}
for (; ; ) {
snprintf ( V_20 , sizeof( V_20 ) , L_2 , ( unsigned int ) V_19 ++ ) ;
V_20 [ sizeof( V_20 ) - 1 ] = '\0' ;
V_16 = F_17 ( V_21 , V_20 , V_2 ) ;
if ( ! F_18 ( V_16 ) )
break;
if ( V_16 == F_19 ( - V_22 ) )
continue;
F_20 ( V_23 L_3
L_4 ,
V_18 , V_20 , F_21 ( V_16 ) ) ;
break;
}
F_22 ( V_21 ) ;
return V_16 ;
}
static int
F_23 ( struct V_1 * V_2 , const char * V_18 ,
struct V_14 * V_15 )
{
struct V_16 * V_16 ;
V_2 -> V_10 = NULL ;
if ( V_18 == NULL )
return 0 ;
V_16 = F_14 ( V_15 , V_2 , V_18 ) ;
if ( F_18 ( V_16 ) )
return F_21 ( V_16 ) ;
V_2 -> V_10 = V_16 ;
return 0 ;
}
static inline int F_24 ( struct V_1 * V_2 , unsigned long V_24 )
{
if ( ( ( V_24 == V_25 ) && V_2 -> V_10 ) ||
( ( V_24 == V_26 ) && ! V_2 -> V_10 ) )
return 1 ;
if ( ( V_24 == V_25 ) && F_25 ( & V_2 -> V_27 ) == 0 )
return 1 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , unsigned long V_24 ,
struct V_14 * V_17 )
{
struct V_16 * V_16 ;
int V_28 = 0 ;
switch ( V_24 ) {
case V_25 :
V_16 = F_14 ( V_17 , V_2 ,
V_2 -> V_29 -> V_30 ) ;
if ( ! V_16 )
return - V_31 ;
if ( F_18 ( V_16 ) )
return F_21 ( V_16 ) ;
V_2 -> V_10 = V_16 ;
if ( V_2 -> V_11 -> V_12 -> V_32 ) {
V_28 = V_2 -> V_11 -> V_12 -> V_32 ( V_2 -> V_11 ) ;
if ( V_28 )
F_9 ( V_2 ) ;
}
break;
case V_26 :
F_9 ( V_2 ) ;
break;
default:
F_20 ( V_33 L_5 , V_34 , V_24 ) ;
return - V_35 ;
}
return V_28 ;
}
static int F_27 ( struct V_1 * V_2 , unsigned long V_24 ,
struct V_14 * V_17 )
{
int error = 0 ;
for (; ; V_2 = V_2 -> V_36 ) {
if ( ! F_24 ( V_2 , V_24 ) )
error = F_26 ( V_2 , V_24 , V_17 ) ;
if ( error || V_2 == V_2 -> V_36 )
break;
}
return error ;
}
static struct V_1 * F_28 ( struct V_3 * V_3 , int V_24 )
{
struct V_4 * V_5 = F_3 ( V_3 , V_6 ) ;
struct V_1 * V_2 ;
F_4 ( & V_5 -> V_7 ) ;
F_29 (clnt, &sn->all_clients, cl_clients) {
if ( V_2 -> V_29 -> V_30 == NULL )
continue;
if ( F_24 ( V_2 , V_24 ) )
continue;
F_6 ( & V_5 -> V_7 ) ;
return V_2 ;
}
F_6 ( & V_5 -> V_7 ) ;
return NULL ;
}
static int F_30 ( struct V_37 * V_38 , unsigned long V_24 ,
void * V_39 )
{
struct V_14 * V_17 = V_39 ;
struct V_1 * V_2 ;
int error = 0 ;
while ( ( V_2 = F_28 ( V_17 -> V_40 , V_24 ) ) ) {
error = F_27 ( V_2 , V_24 , V_17 ) ;
if ( error )
break;
}
return error ;
}
int F_31 ( void )
{
return F_32 ( & V_41 ) ;
}
void F_33 ( void )
{
return F_34 ( & V_41 ) ;
}
static void F_35 ( struct V_1 * V_2 , const char * V_42 )
{
V_2 -> V_43 = strlen ( V_42 ) ;
if ( V_2 -> V_43 > V_44 )
V_2 -> V_43 = V_44 ;
memcpy ( V_2 -> V_45 , V_42 , V_2 -> V_43 ) ;
}
static int F_36 ( const struct V_46 * args ,
struct V_1 * V_2 )
{
const struct V_47 * V_48 = args -> V_48 ;
struct V_49 * V_50 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_14 * V_15 ;
int V_28 ;
V_15 = F_12 ( V_3 ) ;
if ( V_15 ) {
V_28 = F_23 ( V_2 , V_48 -> V_30 , V_15 ) ;
if ( V_28 )
goto V_51;
}
F_1 ( V_2 ) ;
if ( V_15 )
F_13 ( V_3 ) ;
V_50 = F_37 ( args -> V_52 , V_2 ) ;
if ( F_18 ( V_50 ) ) {
F_38 ( L_6 ,
args -> V_52 ) ;
V_28 = F_21 ( V_50 ) ;
goto V_53;
}
return 0 ;
V_53:
V_15 = F_12 ( V_3 ) ;
F_7 ( V_2 ) ;
F_9 ( V_2 ) ;
V_51:
if ( V_15 )
F_13 ( V_3 ) ;
return V_28 ;
}
static struct V_1 * F_39 ( const struct V_46 * args , struct V_54 * V_55 )
{
const struct V_47 * V_48 = args -> V_48 ;
const struct V_56 * V_57 ;
struct V_1 * V_2 = NULL ;
int V_28 ;
F_38 ( L_7 ,
V_48 -> V_20 , args -> V_58 , V_55 ) ;
V_28 = F_40 () ;
if ( V_28 )
goto V_59;
V_28 = - V_60 ;
if ( args -> V_57 >= V_48 -> V_61 )
goto V_62;
V_57 = V_48 -> V_57 [ args -> V_57 ] ;
if ( V_57 == NULL )
goto V_62;
V_28 = - V_63 ;
V_2 = F_41 ( sizeof( * V_2 ) , V_64 ) ;
if ( ! V_2 )
goto V_62;
V_2 -> V_36 = V_2 ;
F_42 ( V_2 -> V_65 , V_55 ) ;
V_2 -> V_66 = V_57 -> V_67 ;
V_2 -> V_68 = V_57 -> V_69 ;
V_2 -> V_70 = V_48 -> V_20 ;
V_2 -> V_71 = args -> V_72 ? : V_48 -> V_73 ;
V_2 -> V_74 = V_57 -> V_73 ;
V_2 -> V_75 = V_48 -> V_76 ;
V_2 -> V_77 = F_43 ( V_2 ) ;
V_28 = - V_63 ;
if ( V_2 -> V_77 == NULL )
goto V_78;
V_2 -> V_29 = V_48 ;
F_44 ( & V_2 -> V_79 ) ;
F_45 ( & V_2 -> V_80 ) ;
if ( ! F_46 ( V_55 ) )
V_2 -> V_81 = 1 ;
V_2 -> V_82 = V_55 -> V_83 ;
if ( args -> V_83 != NULL ) {
memcpy ( & V_2 -> V_84 , args -> V_83 ,
sizeof( V_2 -> V_84 ) ) ;
V_2 -> V_82 = & V_2 -> V_84 ;
}
V_2 -> V_85 = & V_2 -> V_86 ;
F_47 ( & V_2 -> V_86 , V_2 -> V_82 -> V_87 ) ;
V_2 -> V_88 = NULL ;
if ( args -> V_89 ) {
V_2 -> V_88 = F_48 ( args -> V_89 , V_64 ) ;
if ( ! V_2 -> V_88 )
goto V_90;
}
F_49 ( & V_2 -> V_27 , 1 ) ;
F_35 ( V_2 , F_50 () -> V_42 ) ;
V_28 = F_36 ( args , V_2 ) ;
if ( V_28 )
goto V_91;
return V_2 ;
V_91:
F_51 ( V_2 -> V_88 ) ;
V_90:
F_52 ( V_2 -> V_77 ) ;
V_78:
F_51 ( V_2 ) ;
V_62:
F_53 () ;
V_59:
F_54 ( V_55 ) ;
return F_19 ( V_28 ) ;
}
struct V_1 * F_55 ( struct V_46 * args )
{
struct V_54 * V_55 ;
struct V_1 * V_2 ;
struct V_92 V_93 = {
. V_3 = args -> V_3 ,
. V_94 = args -> V_95 ,
. V_96 = args -> V_97 ,
. V_98 = args -> V_99 ,
. V_100 = args -> V_101 ,
. V_58 = args -> V_58 ,
. V_102 = args -> V_102 ,
} ;
char V_58 [ 48 ] ;
if ( args -> V_103 & V_104 )
V_93 . V_103 |= V_105 ;
if ( args -> V_103 & V_106 )
V_93 . V_103 |= V_107 ;
if ( V_93 . V_58 == NULL ) {
struct V_108 * V_109 =
(struct V_108 * ) args -> V_99 ;
struct V_110 * sin =
(struct V_110 * ) args -> V_99 ;
struct V_111 * V_112 =
(struct V_111 * ) args -> V_99 ;
V_58 [ 0 ] = '\0' ;
switch ( args -> V_99 -> V_113 ) {
case V_114 :
snprintf ( V_58 , sizeof( V_58 ) , L_8 ,
V_109 -> V_115 ) ;
break;
case V_116 :
snprintf ( V_58 , sizeof( V_58 ) , L_9 ,
& sin -> V_117 . V_118 ) ;
break;
case V_119 :
snprintf ( V_58 , sizeof( V_58 ) , L_10 ,
& V_112 -> V_120 ) ;
break;
default:
return F_19 ( - V_60 ) ;
}
V_93 . V_58 = V_58 ;
}
V_55 = F_56 ( & V_93 ) ;
if ( F_18 ( V_55 ) )
return (struct V_1 * ) V_55 ;
V_55 -> V_121 = 1 ;
if ( args -> V_103 & V_122 )
V_55 -> V_121 = 0 ;
V_2 = F_39 ( args , V_55 ) ;
if ( F_18 ( V_2 ) )
return V_2 ;
if ( ! ( args -> V_103 & V_123 ) ) {
int V_28 = F_57 ( V_2 ) ;
if ( V_28 != 0 ) {
F_58 ( V_2 ) ;
return F_19 ( V_28 ) ;
}
}
V_2 -> V_124 = 1 ;
if ( args -> V_103 & V_125 )
V_2 -> V_124 = 0 ;
if ( args -> V_103 & V_126 )
V_2 -> V_81 = 1 ;
if ( args -> V_103 & V_127 )
V_2 -> V_128 = 1 ;
if ( ! ( args -> V_103 & V_129 ) )
V_2 -> V_130 = 1 ;
return V_2 ;
}
static struct V_1 * F_59 ( struct V_46 * args ,
struct V_1 * V_2 )
{
struct V_54 * V_55 ;
struct V_1 * V_131 ;
int V_28 ;
V_28 = - V_63 ;
F_60 () ;
V_55 = F_61 ( F_62 ( V_2 -> V_65 ) ) ;
F_63 () ;
if ( V_55 == NULL )
goto V_62;
args -> V_58 = V_55 -> V_58 ;
V_131 = F_39 ( args , V_55 ) ;
if ( F_18 ( V_131 ) ) {
V_28 = F_21 ( V_131 ) ;
goto V_62;
}
F_64 ( & V_2 -> V_27 ) ;
V_131 -> V_36 = V_2 ;
V_131 -> V_81 = 0 ;
V_131 -> V_124 = V_2 -> V_124 ;
V_131 -> V_128 = V_2 -> V_128 ;
V_131 -> V_130 = V_2 -> V_130 ;
return V_131 ;
V_62:
F_38 ( L_11 , V_34 , V_28 ) ;
return F_19 ( V_28 ) ;
}
struct V_1 * F_65 ( struct V_1 * V_2 )
{
struct V_46 args = {
. V_48 = V_2 -> V_29 ,
. V_72 = V_2 -> V_71 ,
. V_57 = V_2 -> V_74 ,
. V_52 = V_2 -> V_11 -> V_132 ,
. V_89 = V_2 -> V_88 ,
} ;
return F_59 ( & args , V_2 ) ;
}
struct V_1 *
F_66 ( struct V_1 * V_2 , T_2 V_133 )
{
struct V_46 args = {
. V_48 = V_2 -> V_29 ,
. V_72 = V_2 -> V_71 ,
. V_57 = V_2 -> V_74 ,
. V_52 = V_133 ,
. V_89 = V_2 -> V_88 ,
} ;
return F_59 ( & args , V_2 ) ;
}
void F_67 ( struct V_1 * V_2 )
{
struct V_134 * V_135 ;
if ( F_68 ( & V_2 -> V_79 ) )
return;
F_38 ( L_12 , V_2 ) ;
F_4 ( & V_2 -> V_80 ) ;
F_29 (rovr, &clnt->cl_tasks, tk_task) {
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
F_6 ( & V_2 -> V_80 ) ;
}
void F_58 ( struct V_1 * V_2 )
{
F_73 () ;
F_74 ( L_13 ,
V_2 -> V_70 ,
F_62 ( V_2 -> V_65 ) -> V_58 ) ;
while ( ! F_68 ( & V_2 -> V_79 ) ) {
F_67 ( V_2 ) ;
F_75 ( V_140 ,
F_68 ( & V_2 -> V_79 ) , 1 * V_141 ) ;
}
F_76 ( V_2 ) ;
}
static void
F_77 ( struct V_1 * V_2 )
{
F_74 ( L_14 ,
V_2 -> V_70 ,
F_62 ( V_2 -> V_65 ) -> V_58 ) ;
if ( V_2 -> V_36 != V_2 )
F_76 ( V_2 -> V_36 ) ;
F_11 ( V_2 ) ;
F_7 ( V_2 ) ;
F_52 ( V_2 -> V_77 ) ;
F_51 ( V_2 -> V_88 ) ;
V_2 -> V_77 = NULL ;
F_54 ( F_78 ( V_2 -> V_65 ) ) ;
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
F_64 ( & V_2 -> V_27 ) ;
F_80 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
if ( F_81 ( & V_2 -> V_27 ) )
F_77 ( V_2 ) ;
}
void
F_76 ( struct V_1 * V_2 )
{
F_38 ( L_15 , V_2 ) ;
if ( F_68 ( & V_2 -> V_79 ) )
F_82 ( & V_140 ) ;
if ( F_81 ( & V_2 -> V_27 ) )
F_79 ( V_2 ) ;
}
struct V_1 * F_83 ( struct V_1 * V_142 ,
const struct V_47 * V_48 ,
T_3 V_143 )
{
struct V_46 args = {
. V_48 = V_48 ,
. V_72 = V_48 -> V_73 ,
. V_57 = V_143 ,
. V_52 = V_142 -> V_11 -> V_132 ,
. V_89 = V_142 -> V_88 ,
} ;
struct V_1 * V_2 ;
int V_28 ;
V_2 = F_59 ( & args , V_142 ) ;
if ( F_18 ( V_2 ) )
goto V_51;
V_28 = F_57 ( V_2 ) ;
if ( V_28 != 0 ) {
F_58 ( V_2 ) ;
V_2 = F_19 ( V_28 ) ;
}
V_51:
return V_2 ;
}
void F_84 ( struct V_134 * V_144 )
{
struct V_1 * V_2 = V_144 -> V_145 ;
if ( V_2 != NULL ) {
F_4 ( & V_2 -> V_80 ) ;
F_8 ( & V_144 -> V_146 ) ;
F_6 ( & V_2 -> V_80 ) ;
V_144 -> V_145 = NULL ;
F_76 ( V_2 ) ;
}
}
static
void F_85 ( struct V_134 * V_144 , struct V_1 * V_2 )
{
if ( V_2 != NULL ) {
F_84 ( V_144 ) ;
V_144 -> V_145 = V_2 ;
F_64 ( & V_2 -> V_27 ) ;
if ( V_2 -> V_124 )
V_144 -> V_136 |= V_147 ;
if ( F_86 () ) {
struct V_54 * V_55 ;
F_60 () ;
V_55 = F_62 ( V_2 -> V_65 ) ;
if ( V_55 -> V_148 )
V_144 -> V_136 |= V_149 ;
F_63 () ;
}
F_4 ( & V_2 -> V_80 ) ;
F_87 ( & V_144 -> V_146 , & V_2 -> V_79 ) ;
F_6 ( & V_2 -> V_80 ) ;
}
}
void F_88 ( struct V_134 * V_144 , struct V_1 * V_2 )
{
F_84 ( V_144 ) ;
F_85 ( V_144 , V_2 ) ;
}
static void
F_89 ( struct V_134 * V_144 , const struct V_150 * V_151 )
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
F_91 ( struct V_134 * V_144 , void * V_157 )
{
}
struct V_134 * F_92 ( const struct V_158 * V_159 )
{
struct V_134 * V_144 ;
V_144 = F_93 ( V_159 ) ;
if ( F_18 ( V_144 ) )
goto V_51;
F_85 ( V_144 , V_159 -> V_160 ) ;
F_89 ( V_144 , V_159 -> V_150 ) ;
if ( V_144 -> V_161 == NULL )
F_94 ( V_144 ) ;
F_64 ( & V_144 -> V_162 ) ;
F_95 ( V_144 ) ;
V_51:
return V_144 ;
}
int F_96 ( struct V_1 * V_2 , const struct V_150 * V_151 , int V_103 )
{
struct V_134 * V_144 ;
struct V_158 V_159 = {
. V_160 = V_2 ,
. V_150 = V_151 ,
. V_163 = & V_164 ,
. V_103 = V_103 ,
} ;
int V_165 ;
F_97 ( V_103 & V_166 ) ;
if ( V_103 & V_166 ) {
F_98 ( V_159 . V_163 ,
V_159 . V_167 ) ;
return - V_60 ;
}
V_144 = F_92 ( & V_159 ) ;
if ( F_18 ( V_144 ) )
return F_21 ( V_144 ) ;
V_165 = V_144 -> V_168 ;
F_99 ( V_144 ) ;
return V_165 ;
}
int
F_100 ( struct V_1 * V_2 , const struct V_150 * V_151 , int V_103 ,
const struct V_169 * V_170 , void * V_157 )
{
struct V_134 * V_144 ;
struct V_158 V_159 = {
. V_160 = V_2 ,
. V_150 = V_151 ,
. V_163 = V_170 ,
. V_167 = V_157 ,
. V_103 = V_103 | V_166 ,
} ;
V_144 = F_92 ( & V_159 ) ;
if ( F_18 ( V_144 ) )
return F_21 ( V_144 ) ;
F_99 ( V_144 ) ;
return 0 ;
}
struct V_134 * F_101 ( struct V_171 * V_172 ,
const struct V_169 * V_170 )
{
struct V_134 * V_144 ;
struct V_173 * V_174 = & V_172 -> V_175 ;
struct V_158 V_159 = {
. V_163 = V_170 ,
} ;
F_38 ( L_16 , V_172 ) ;
V_144 = F_93 ( & V_159 ) ;
if ( F_18 ( V_144 ) ) {
F_102 ( V_172 ) ;
goto V_51;
}
V_144 -> V_176 = V_172 ;
V_174 -> V_177 = V_174 -> V_178 [ 0 ] . V_179 + V_174 -> V_180 +
V_174 -> V_181 [ 0 ] . V_179 ;
V_144 -> V_161 = V_182 ;
F_64 ( & V_144 -> V_162 ) ;
F_97 ( F_25 ( & V_144 -> V_162 ) != 2 ) ;
F_95 ( V_144 ) ;
V_51:
F_38 ( L_17 , V_144 ) ;
return V_144 ;
}
void
F_94 ( struct V_134 * V_144 )
{
V_144 -> V_161 = V_183 ;
}
T_4 F_103 ( struct V_1 * V_2 , struct V_184 * V_185 , T_4 V_186 )
{
T_4 V_187 ;
struct V_54 * V_55 ;
F_60 () ;
V_55 = F_62 ( V_2 -> V_65 ) ;
V_187 = V_55 -> V_100 ;
if ( V_187 > V_186 )
V_187 = V_186 ;
memcpy ( V_185 , & V_55 -> V_188 , V_187 ) ;
F_63 () ;
return V_187 ;
}
const char * F_104 ( struct V_1 * V_2 ,
enum V_189 V_190 )
{
struct V_54 * V_55 ;
V_55 = F_62 ( V_2 -> V_65 ) ;
if ( V_55 -> V_191 [ V_190 ] != NULL )
return V_55 -> V_191 [ V_190 ] ;
else
return L_18 ;
}
static int F_105 ( struct V_3 * V_3 , struct V_184 * V_192 , T_4 V_193 ,
struct V_184 * V_185 , int V_194 )
{
struct V_195 * V_196 ;
int V_28 ;
V_28 = F_106 ( V_3 , V_192 -> V_113 ,
V_197 , V_198 , & V_196 , 1 ) ;
if ( V_28 < 0 ) {
F_38 ( L_19 , V_28 ) ;
goto V_51;
}
switch ( V_192 -> V_113 ) {
case V_116 :
V_28 = F_107 ( V_196 ,
(struct V_184 * ) & V_199 ,
sizeof( V_199 ) ) ;
break;
case V_119 :
V_28 = F_107 ( V_196 ,
(struct V_184 * ) & V_200 ,
sizeof( V_200 ) ) ;
break;
default:
V_28 = - V_201 ;
goto V_51;
}
if ( V_28 < 0 ) {
F_38 ( L_20 , V_28 ) ;
goto V_202;
}
V_28 = F_108 ( V_196 , V_192 , V_193 , 0 ) ;
if ( V_28 < 0 ) {
F_38 ( L_21 , V_28 ) ;
goto V_202;
}
V_28 = F_109 ( V_196 , V_185 , & V_194 ) ;
if ( V_28 < 0 ) {
F_38 ( L_22 , V_28 ) ;
goto V_202;
}
V_28 = 0 ;
if ( V_185 -> V_113 == V_119 ) {
struct V_111 * V_112 = (struct V_111 * ) V_185 ;
V_112 -> V_203 = 0 ;
}
F_38 ( L_23 , V_34 ) ;
V_202:
F_110 ( V_196 ) ;
V_51:
return V_28 ;
}
static int F_111 ( int V_204 , struct V_184 * V_185 , T_4 V_194 )
{
switch ( V_204 ) {
case V_116 :
if ( V_194 < sizeof( V_199 ) )
return - V_60 ;
memcpy ( V_185 , & V_199 ,
sizeof( V_199 ) ) ;
break;
case V_119 :
if ( V_194 < sizeof( V_200 ) )
return - V_60 ;
memcpy ( V_185 , & V_200 ,
sizeof( V_200 ) ) ;
default:
F_38 ( L_24 ,
V_34 ) ;
return - V_201 ;
}
F_38 ( L_25 , V_34 ) ;
return 0 ;
}
int F_112 ( struct V_1 * V_2 , struct V_184 * V_185 , T_4 V_194 )
{
struct V_205 V_99 ;
struct V_184 * V_192 = (struct V_184 * ) & V_99 ;
struct V_54 * V_55 ;
struct V_3 * V_3 ;
T_4 V_193 ;
int V_28 ;
F_60 () ;
V_55 = F_62 ( V_2 -> V_65 ) ;
V_193 = V_55 -> V_100 ;
memcpy ( V_192 , & V_55 -> V_188 , V_193 ) ;
V_3 = F_113 ( V_55 -> V_206 ) ;
F_63 () ;
F_114 ( V_192 , 0 ) ;
V_28 = F_105 ( V_3 , V_192 , V_193 , V_185 , V_194 ) ;
F_115 ( V_3 ) ;
if ( V_28 != 0 )
return F_111 ( V_192 -> V_113 , V_185 , V_194 ) ;
return 0 ;
}
void
F_116 ( struct V_1 * V_2 , unsigned int V_207 , unsigned int V_208 )
{
struct V_54 * V_55 ;
F_60 () ;
V_55 = F_62 ( V_2 -> V_65 ) ;
if ( V_55 -> V_209 -> V_210 )
V_55 -> V_209 -> V_210 ( V_55 , V_207 , V_208 ) ;
F_63 () ;
}
int F_117 ( struct V_1 * V_2 )
{
int V_95 ;
F_60 () ;
V_95 = F_62 ( V_2 -> V_65 ) -> V_211 ;
F_63 () ;
return V_95 ;
}
struct V_3 * F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_212 ;
F_60 () ;
V_212 = F_62 ( V_2 -> V_65 ) -> V_206 ;
F_63 () ;
return V_212 ;
}
T_4 F_118 ( struct V_1 * V_2 )
{
T_4 V_212 ;
F_60 () ;
V_212 = F_62 ( V_2 -> V_65 ) -> V_213 ;
F_63 () ;
return V_212 ;
}
unsigned long F_119 ( struct V_1 * V_2 )
{
unsigned long V_212 ;
F_60 () ;
V_212 = F_62 ( V_2 -> V_65 ) -> V_83 -> V_87 ;
F_63 () ;
return V_212 ;
}
void F_120 ( struct V_1 * V_2 )
{
if ( V_2 -> V_81 ) {
F_60 () ;
F_121 ( F_62 ( V_2 -> V_65 ) ) ;
F_63 () ;
}
}
int
F_122 ( struct V_134 * V_144 )
{
if ( F_123 ( V_144 ) )
return 0 ;
V_144 -> V_161 = V_183 ;
if ( V_144 -> V_170 -> V_214 != NULL )
V_144 -> V_161 = V_215 ;
return 1 ;
}
int
F_124 ( struct V_134 * V_144 )
{
if ( F_123 ( V_144 ) )
return 0 ;
V_144 -> V_161 = V_183 ;
return 1 ;
}
static const char * F_125 ( const struct V_134 * V_144 )
{
const struct V_216 * V_217 = V_144 -> V_152 . V_153 ;
if ( V_217 ) {
if ( V_217 -> V_218 )
return V_217 -> V_218 ;
else
return L_26 ;
} else
return L_27 ;
}
static void
V_183 ( struct V_134 * V_144 )
{
struct V_1 * V_2 = V_144 -> V_145 ;
F_38 ( L_28 , V_144 -> V_219 ,
V_2 -> V_70 , V_2 -> V_74 ,
F_125 ( V_144 ) ,
( F_126 ( V_144 ) ? L_29 : L_30 ) ) ;
V_144 -> V_152 . V_153 -> V_220 ++ ;
V_2 -> V_75 -> V_221 ++ ;
V_144 -> V_161 = V_222 ;
}
static void
V_222 ( struct V_134 * V_144 )
{
F_127 ( V_144 ) ;
V_144 -> V_168 = 0 ;
V_144 -> V_161 = V_223 ;
F_128 ( V_144 ) ;
}
static void
V_223 ( struct V_134 * V_144 )
{
int V_165 = V_144 -> V_168 ;
F_127 ( V_144 ) ;
V_144 -> V_168 = 0 ;
if ( V_165 >= 0 ) {
if ( V_144 -> V_176 ) {
V_144 -> V_161 = V_224 ;
return;
}
F_20 ( V_33 L_31 ,
V_34 , V_165 ) ;
F_70 ( V_144 , - V_138 ) ;
return;
}
if ( V_144 -> V_176 ) {
F_20 ( V_33 L_32 ,
V_34 , V_165 ) ;
F_129 ( V_144 ) ;
}
switch ( V_165 ) {
case - V_63 :
F_130 ( V_144 , V_141 >> 2 ) ;
case - V_225 :
V_144 -> V_161 = V_226 ;
return;
case - V_138 :
break;
default:
F_20 ( V_33 L_33 ,
V_34 , V_165 ) ;
break;
}
F_70 ( V_144 , V_165 ) ;
}
static void
V_226 ( struct V_134 * V_144 )
{
F_127 ( V_144 ) ;
V_144 -> V_168 = 0 ;
V_144 -> V_161 = V_223 ;
F_131 ( V_144 ) ;
}
static void
V_224 ( struct V_134 * V_144 )
{
F_127 ( V_144 ) ;
V_144 -> V_161 = V_227 ;
V_144 -> V_168 = 0 ;
V_144 -> V_145 -> V_75 -> V_228 ++ ;
F_132 ( V_144 ) ;
}
static void
V_227 ( struct V_134 * V_144 )
{
int V_165 = V_144 -> V_168 ;
F_127 ( V_144 ) ;
V_144 -> V_168 = 0 ;
V_144 -> V_161 = V_224 ;
switch ( V_165 ) {
case 0 :
if ( F_133 ( V_144 ) )
V_144 -> V_161 = V_229 ;
return;
case - V_230 :
F_130 ( V_144 , 3 * V_141 ) ;
case - V_231 :
case - V_225 :
V_165 = - V_232 ;
if ( ! V_144 -> V_233 )
break;
V_144 -> V_233 -- ;
F_38 ( L_34 ,
V_144 -> V_219 , V_34 ) ;
return;
}
F_38 ( L_35 ,
V_144 -> V_219 , V_34 , V_165 ) ;
F_70 ( V_144 , V_165 ) ;
}
static void
V_229 ( struct V_134 * V_144 )
{
unsigned int V_234 = V_144 -> V_176 -> V_235 -> V_236 -> V_237 ;
struct V_171 * V_172 = V_144 -> V_176 ;
struct V_54 * V_55 = V_172 -> V_238 ;
struct V_216 * V_217 = V_144 -> V_152 . V_153 ;
F_127 ( V_144 ) ;
V_144 -> V_168 = 0 ;
V_144 -> V_161 = V_239 ;
if ( V_172 -> V_240 )
return;
if ( V_217 -> V_241 != 0 ) {
F_134 ( V_217 -> V_242 == 0 ) ;
if ( V_217 -> V_243 != NULL )
F_134 ( V_217 -> V_244 == 0 ) ;
}
V_172 -> V_245 = V_246 + ( V_234 << 1 ) + V_217 -> V_242 ;
V_172 -> V_245 <<= 2 ;
V_172 -> V_247 = V_248 + V_234 + V_217 -> V_244 ;
V_172 -> V_247 <<= 2 ;
V_172 -> V_240 = V_55 -> V_209 -> V_249 ( V_144 ,
V_172 -> V_245 + V_172 -> V_247 ) ;
if ( V_172 -> V_240 != NULL )
return;
F_38 ( L_36 , V_144 -> V_219 ) ;
if ( F_126 ( V_144 ) || ! F_135 ( V_250 ) ) {
V_144 -> V_161 = V_229 ;
F_130 ( V_144 , V_141 >> 4 ) ;
return;
}
F_70 ( V_144 , - V_251 ) ;
}
static inline int
F_136 ( struct V_134 * V_144 )
{
return V_144 -> V_176 -> V_175 . V_177 == 0 ;
}
static inline void
F_137 ( struct V_134 * V_144 )
{
V_144 -> V_176 -> V_175 . V_177 = 0 ;
V_144 -> V_176 -> V_252 = 0 ;
}
static inline void
F_138 ( struct V_173 * V_185 , void * V_253 , T_4 V_177 )
{
V_185 -> V_178 [ 0 ] . V_254 = V_253 ;
V_185 -> V_178 [ 0 ] . V_179 = V_177 ;
V_185 -> V_181 [ 0 ] . V_179 = 0 ;
V_185 -> V_180 = 0 ;
V_185 -> V_103 = 0 ;
V_185 -> V_177 = 0 ;
V_185 -> V_194 = V_177 ;
}
static void
F_139 ( struct V_134 * V_144 )
{
struct V_171 * V_172 = V_144 -> V_176 ;
T_5 V_255 ;
T_6 * V_256 ;
F_127 ( V_144 ) ;
F_138 ( & V_172 -> V_175 ,
V_172 -> V_240 ,
V_172 -> V_245 ) ;
F_138 ( & V_172 -> V_257 ,
( char * ) V_172 -> V_240 + V_172 -> V_245 ,
V_172 -> V_247 ) ;
V_256 = F_140 ( V_144 ) ;
if ( V_256 == NULL ) {
F_20 ( V_23 L_37 ) ;
F_70 ( V_144 , - V_138 ) ;
return;
}
V_255 = V_144 -> V_152 . V_153 -> V_258 ;
if ( V_255 == NULL )
return;
V_144 -> V_168 = F_141 ( V_144 , V_255 , V_172 , V_256 ,
V_144 -> V_152 . V_154 ) ;
}
static void
V_239 ( struct V_134 * V_144 )
{
struct V_54 * V_55 = V_144 -> V_176 -> V_238 ;
F_127 ( V_144 ) ;
V_144 -> V_161 = V_259 ;
if ( ! F_46 ( V_55 ) ) {
V_144 -> V_161 = V_260 ;
V_144 -> V_261 = V_55 -> V_262 ;
V_55 -> V_209 -> V_263 ( V_144 ) ;
}
}
static void
V_260 ( struct V_134 * V_144 )
{
int V_165 = - V_138 ;
if ( V_144 -> V_168 >= 0 ) {
F_127 ( V_144 ) ;
V_144 -> V_168 = 0 ;
V_144 -> V_161 = V_259 ;
return;
}
F_142 ( V_144 ) ;
switch ( V_144 -> V_168 ) {
case - V_63 :
F_38 ( L_38 , V_144 -> V_219 ) ;
F_130 ( V_144 , V_141 >> 2 ) ;
goto V_264;
case - V_232 :
F_38 ( L_39
L_40 , V_144 -> V_219 ) ;
if ( V_144 -> V_152 . V_153 -> V_241 == 0 ) {
V_165 = - V_265 ;
break;
}
if ( V_144 -> V_266 == 0 )
break;
V_144 -> V_266 -- ;
F_130 ( V_144 , 3 * V_141 ) ;
goto V_264;
case - V_230 :
F_38 ( L_41 ,
V_144 -> V_219 ) ;
goto V_264;
case - V_267 :
F_38 ( L_42 ,
V_144 -> V_219 ) ;
break;
case - V_268 :
F_38 ( L_43 ,
V_144 -> V_219 ) ;
V_144 -> V_168 = 0 ;
V_144 -> V_161 = V_239 ;
return;
case - V_269 :
case - V_270 :
case - V_271 :
case - V_272 :
case - V_273 :
case - V_274 :
case - V_275 :
F_38 ( L_44 ,
V_144 -> V_219 , V_144 -> V_168 ) ;
if ( ! F_143 ( V_144 ) ) {
F_130 ( V_144 , 5 * V_141 ) ;
goto V_264;
}
V_165 = V_144 -> V_168 ;
break;
default:
F_38 ( L_45 ,
V_144 -> V_219 , - V_144 -> V_168 ) ;
}
F_70 ( V_144 , V_165 ) ;
return;
V_264:
V_144 -> V_161 = V_276 ;
}
static void
V_259 ( struct V_134 * V_144 )
{
struct V_54 * V_55 = V_144 -> V_176 -> V_238 ;
F_38 ( L_46 ,
V_144 -> V_219 , V_55 ,
( F_144 ( V_55 ) ? L_47 : L_48 ) ) ;
V_144 -> V_161 = V_277 ;
if ( ! F_144 ( V_55 ) ) {
V_144 -> V_161 = V_278 ;
if ( V_144 -> V_168 < 0 )
return;
if ( V_144 -> V_136 & V_279 ) {
F_70 ( V_144 , - V_271 ) ;
return;
}
F_145 ( V_144 ) ;
}
}
static void
V_278 ( struct V_134 * V_144 )
{
struct V_1 * V_2 = V_144 -> V_145 ;
int V_165 = V_144 -> V_168 ;
F_127 ( V_144 ) ;
F_146 ( V_144 , V_165 ) ;
switch ( V_165 ) {
case - V_230 :
V_144 -> V_161 = V_276 ;
return;
case - V_269 :
case - V_270 :
case - V_274 :
if ( F_143 ( V_144 ) )
break;
case 0 :
case - V_225 :
V_144 -> V_168 = 0 ;
V_2 -> V_75 -> V_280 ++ ;
V_144 -> V_161 = V_277 ;
return;
}
F_70 ( V_144 , V_165 ) ;
}
static void
V_277 ( struct V_134 * V_144 )
{
F_127 ( V_144 ) ;
V_144 -> V_161 = V_281 ;
if ( V_144 -> V_168 < 0 )
return;
V_144 -> V_168 = F_147 ( V_144 ) ;
if ( V_144 -> V_168 != 0 )
return;
V_144 -> V_161 = V_282 ;
if ( F_136 ( V_144 ) ) {
F_139 ( V_144 ) ;
if ( V_144 -> V_168 != 0 ) {
if ( V_144 -> V_168 == - V_225 )
F_130 ( V_144 , V_141 >> 4 ) ;
else
F_70 ( V_144 , V_144 -> V_168 ) ;
return;
}
}
F_148 ( V_144 ) ;
if ( V_144 -> V_168 < 0 )
return;
V_282 ( V_144 ) ;
if ( F_149 ( V_144 ) )
return;
V_144 -> V_161 = V_283 ;
F_72 ( & V_144 -> V_176 -> V_238 -> V_284 , V_144 ) ;
}
static void
V_282 ( struct V_134 * V_144 )
{
V_144 -> V_161 = V_281 ;
if ( V_144 -> V_168 == 0 ) {
F_150 ( V_144 ) ;
F_137 ( V_144 ) ;
return;
}
switch ( V_144 -> V_168 ) {
case - V_225 :
break;
default:
F_127 ( V_144 ) ;
F_150 ( V_144 ) ;
F_137 ( V_144 ) ;
break;
case - V_269 :
case - V_272 :
case - V_273 :
case - V_274 :
if ( F_143 ( V_144 ) ) {
F_150 ( V_144 ) ;
F_70 ( V_144 , V_144 -> V_168 ) ;
break;
}
case - V_270 :
case - V_271 :
case - V_275 :
F_137 ( V_144 ) ;
}
}
static void
V_182 ( struct V_134 * V_144 )
{
struct V_171 * V_172 = V_144 -> V_176 ;
V_144 -> V_168 = F_147 ( V_144 ) ;
if ( V_144 -> V_168 == - V_225 ) {
V_144 -> V_168 = 0 ;
V_144 -> V_161 = V_182 ;
return;
}
V_144 -> V_161 = V_283 ;
if ( V_144 -> V_168 < 0 ) {
F_20 ( V_285 L_49
L_50 , V_144 -> V_168 ) ;
return;
}
F_148 ( V_144 ) ;
F_150 ( V_144 ) ;
F_127 ( V_144 ) ;
switch ( V_144 -> V_168 ) {
case 0 :
break;
case - V_272 :
case - V_273 :
case - V_274 :
case - V_230 :
F_20 ( V_285 L_49
L_50 , V_144 -> V_168 ) ;
F_151 ( V_172 -> V_238 ,
V_172 -> V_286 ) ;
break;
default:
F_97 ( V_144 -> V_168 == - V_225 ) ;
F_20 ( V_285 L_49
L_50 , V_144 -> V_168 ) ;
break;
}
F_72 ( & V_172 -> V_238 -> V_284 , V_144 ) ;
}
static void
V_281 ( struct V_134 * V_144 )
{
struct V_1 * V_2 = V_144 -> V_145 ;
struct V_171 * V_172 = V_144 -> V_176 ;
int V_165 ;
if ( V_172 -> V_287 > 0 && ! V_172 -> V_252 )
V_144 -> V_168 = V_172 -> V_287 ;
F_127 ( V_144 ) ;
V_165 = V_144 -> V_168 ;
if ( V_165 >= 0 ) {
V_144 -> V_161 = V_288 ;
return;
}
F_152 ( V_144 ) ;
V_144 -> V_168 = 0 ;
switch( V_165 ) {
case - V_272 :
case - V_273 :
case - V_274 :
F_130 ( V_144 , 3 * V_141 ) ;
case - V_230 :
V_144 -> V_161 = V_276 ;
if ( V_144 -> V_145 -> V_128 )
F_151 ( V_172 -> V_238 ,
V_172 -> V_286 ) ;
break;
case - V_270 :
case - V_269 :
F_120 ( V_2 ) ;
F_130 ( V_144 , 3 * V_141 ) ;
case - V_275 :
case - V_271 :
V_144 -> V_161 = V_239 ;
break;
case - V_225 :
V_144 -> V_161 = V_277 ;
break;
case - V_138 :
F_70 ( V_144 , V_165 ) ;
break;
default:
if ( V_2 -> V_130 )
F_20 ( L_51 ,
V_2 -> V_70 , - V_165 ) ;
F_70 ( V_144 , V_165 ) ;
}
}
static void
V_276 ( struct V_134 * V_144 )
{
struct V_1 * V_2 = V_144 -> V_145 ;
if ( F_153 ( V_144 -> V_176 ) == 0 ) {
F_38 ( L_52 , V_144 -> V_219 ) ;
goto V_289;
}
F_38 ( L_53 , V_144 -> V_219 ) ;
V_144 -> V_290 ++ ;
if ( F_143 ( V_144 ) ) {
F_70 ( V_144 , - V_230 ) ;
return;
}
if ( F_154 ( V_144 ) ) {
if ( V_2 -> V_130 ) {
F_60 () ;
F_20 ( V_285 L_54 ,
V_2 -> V_70 ,
F_62 ( V_2 -> V_65 ) -> V_58 ) ;
F_63 () ;
}
if ( V_144 -> V_136 & V_291 )
F_70 ( V_144 , - V_230 ) ;
else
F_70 ( V_144 , - V_138 ) ;
return;
}
if ( ! ( V_144 -> V_136 & V_292 ) ) {
V_144 -> V_136 |= V_292 ;
if ( V_2 -> V_130 ) {
F_60 () ;
F_20 ( V_285 L_55 ,
V_2 -> V_70 ,
F_62 ( V_2 -> V_65 ) -> V_58 ) ;
F_63 () ;
}
}
F_120 ( V_2 ) ;
F_155 ( V_144 ) ;
V_289:
V_2 -> V_75 -> V_293 ++ ;
V_144 -> V_161 = V_239 ;
V_144 -> V_168 = 0 ;
}
static void
V_288 ( struct V_134 * V_144 )
{
struct V_1 * V_2 = V_144 -> V_145 ;
struct V_171 * V_172 = V_144 -> V_176 ;
T_7 V_294 = V_144 -> V_152 . V_153 -> V_243 ;
T_6 * V_256 ;
F_127 ( V_144 ) ;
if ( V_144 -> V_136 & V_292 ) {
if ( V_2 -> V_130 ) {
F_60 () ;
F_20 ( V_285 L_56 ,
V_2 -> V_70 ,
F_62 ( V_2 -> V_65 ) -> V_58 ) ;
F_63 () ;
}
V_144 -> V_136 &= ~ V_292 ;
}
F_156 () ;
V_172 -> V_257 . V_177 = V_172 -> V_295 . V_177 ;
F_157 ( memcmp ( & V_172 -> V_257 , & V_172 -> V_295 ,
sizeof( V_172 -> V_257 ) ) != 0 ) ;
if ( V_172 -> V_257 . V_177 < 12 ) {
if ( ! F_154 ( V_144 ) ) {
V_144 -> V_161 = V_239 ;
V_2 -> V_75 -> V_293 ++ ;
goto V_296;
}
F_38 ( L_57 ,
V_2 -> V_70 , V_144 -> V_168 ) ;
V_144 -> V_161 = V_276 ;
goto V_296;
}
V_256 = F_158 ( V_144 ) ;
if ( F_18 ( V_256 ) ) {
if ( V_256 == F_19 ( - V_225 ) )
goto V_296;
return;
}
V_144 -> V_161 = V_283 ;
if ( V_294 ) {
V_144 -> V_168 = F_159 ( V_144 , V_294 , V_172 , V_256 ,
V_144 -> V_152 . V_155 ) ;
}
F_38 ( L_58 , V_144 -> V_219 ,
V_144 -> V_168 ) ;
return;
V_296:
V_144 -> V_168 = 0 ;
if ( V_144 -> V_176 == V_172 ) {
V_172 -> V_287 = V_172 -> V_257 . V_177 = 0 ;
if ( V_144 -> V_145 -> V_128 )
F_151 ( V_172 -> V_238 ,
V_172 -> V_286 ) ;
}
}
static T_6 *
F_140 ( struct V_134 * V_144 )
{
struct V_1 * V_2 = V_144 -> V_145 ;
struct V_171 * V_172 = V_144 -> V_176 ;
T_6 * V_256 = V_172 -> V_297 [ 0 ] . V_254 ;
V_256 = F_160 ( V_172 -> V_238 , V_256 ) ;
* V_256 ++ = V_172 -> V_298 ;
* V_256 ++ = F_161 ( V_299 ) ;
* V_256 ++ = F_161 ( V_300 ) ;
* V_256 ++ = F_161 ( V_2 -> V_71 ) ;
* V_256 ++ = F_161 ( V_2 -> V_74 ) ;
* V_256 ++ = F_161 ( V_144 -> V_152 . V_153 -> V_241 ) ;
V_256 = F_162 ( V_144 , V_256 ) ;
V_172 -> V_301 = F_163 ( & V_172 -> V_297 [ 0 ] , V_256 ) ;
return V_256 ;
}
static T_6 *
F_158 ( struct V_134 * V_144 )
{
struct V_1 * V_2 = V_144 -> V_145 ;
struct V_302 * V_303 = & V_144 -> V_176 -> V_257 . V_178 [ 0 ] ;
int V_177 = V_144 -> V_176 -> V_257 . V_177 >> 2 ;
T_6 * V_256 = V_303 -> V_254 ;
T_3 V_304 ;
int error = - V_232 ;
if ( ( V_144 -> V_176 -> V_257 . V_177 & 3 ) != 0 ) {
F_38 ( L_59
L_60 , V_144 -> V_219 , V_34 ,
V_144 -> V_176 -> V_257 . V_177 ) ;
goto V_305;
}
if ( ( V_177 -= 3 ) < 0 )
goto V_306;
V_256 += 1 ;
if ( ( V_304 = F_164 ( * V_256 ++ ) ) != V_307 ) {
F_38 ( L_61 ,
V_144 -> V_219 , V_34 , V_304 ) ;
goto V_308;
}
if ( ( V_304 = F_164 ( * V_256 ++ ) ) != V_309 ) {
if ( -- V_177 < 0 )
goto V_306;
switch ( ( V_304 = F_164 ( * V_256 ++ ) ) ) {
case V_310 :
break;
case V_311 :
F_38 ( L_62 ,
V_144 -> V_219 , V_34 ) ;
error = - V_268 ;
goto V_62;
default:
F_38 ( L_63
L_64 ,
V_144 -> V_219 , V_34 , V_304 ) ;
goto V_305;
}
if ( -- V_177 < 0 )
goto V_306;
switch ( ( V_304 = F_164 ( * V_256 ++ ) ) ) {
case V_312 :
case V_313 :
case V_314 :
case V_315 :
if ( ! V_144 -> V_233 )
break;
V_144 -> V_233 -- ;
F_38 ( L_65 ,
V_144 -> V_219 , V_34 ) ;
F_155 ( V_144 ) ;
F_129 ( V_144 ) ;
V_144 -> V_161 = V_222 ;
goto V_296;
case V_316 :
case V_317 :
if ( ! V_144 -> V_318 )
break;
V_144 -> V_318 -- ;
F_38 ( L_66 ,
V_144 -> V_219 , V_34 ) ;
V_144 -> V_161 = V_239 ;
goto V_296;
case V_319 :
F_60 () ;
F_20 ( V_285 L_67
L_68 ,
F_62 ( V_2 -> V_65 ) -> V_58 ) ;
F_63 () ;
break;
default:
F_38 ( L_69 ,
V_144 -> V_219 , V_34 , V_304 ) ;
error = - V_138 ;
}
F_38 ( L_70 ,
V_144 -> V_219 , V_34 , V_304 ) ;
goto V_62;
}
if ( ! ( V_256 = F_165 ( V_144 , V_256 ) ) ) {
F_38 ( L_71 ,
V_144 -> V_219 , V_34 ) ;
goto V_308;
}
V_177 = V_256 - ( T_6 * ) V_303 -> V_254 - 1 ;
if ( V_177 < 0 )
goto V_306;
switch ( ( V_304 = F_164 ( * V_256 ++ ) ) ) {
case V_320 :
return V_256 ;
case V_321 :
F_74 ( L_72
L_73 , V_144 -> V_219 , V_34 ,
( unsigned int ) V_2 -> V_71 ,
F_62 ( V_2 -> V_65 ) -> V_58 ) ;
error = - V_267 ;
goto V_62;
case V_322 :
F_74 ( L_74
L_73 , V_144 -> V_219 , V_34 ,
( unsigned int ) V_2 -> V_71 ,
( unsigned int ) V_2 -> V_74 ,
F_62 ( V_2 -> V_65 ) -> V_58 ) ;
error = - V_268 ;
goto V_62;
case V_323 :
F_74 ( L_75
L_76 ,
V_144 -> V_219 , V_34 ,
F_125 ( V_144 ) ,
V_2 -> V_71 , V_2 -> V_74 ,
F_62 ( V_2 -> V_65 ) -> V_58 ) ;
error = - V_265 ;
goto V_62;
case V_324 :
F_38 ( L_77 ,
V_144 -> V_219 , V_34 ) ;
break;
default:
F_38 ( L_78 ,
V_144 -> V_219 , V_34 , V_304 ) ;
}
V_308:
V_2 -> V_75 -> V_325 ++ ;
if ( V_144 -> V_318 ) {
V_144 -> V_318 -- ;
F_38 ( L_79 ,
V_144 -> V_219 , V_34 ) ;
V_144 -> V_161 = V_239 ;
V_296:
return F_19 ( - V_225 ) ;
}
V_305:
error = - V_138 ;
V_62:
F_70 ( V_144 , error ) ;
F_38 ( L_80 , V_144 -> V_219 ,
V_34 , error ) ;
return F_19 ( error ) ;
V_306:
F_38 ( L_81 , V_144 -> V_219 ,
V_34 ) ;
goto V_308;
}
static void F_166 ( void * V_326 , struct V_327 * V_328 , void * V_329 )
{
}
static int F_167 ( void * V_326 , struct V_327 * V_328 , void * V_329 )
{
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_150 V_151 = {
. V_153 = & V_330 ,
} ;
int V_28 ;
V_151 . V_156 = V_331 . V_332 ( NULL , NULL , 0 ) ;
V_28 = F_96 ( V_2 , & V_151 , V_147 | V_333 ) ;
F_168 ( V_151 . V_156 ) ;
return V_28 ;
}
struct V_134 * F_169 ( struct V_1 * V_2 , struct V_156 * V_334 , int V_103 )
{
struct V_150 V_151 = {
. V_153 = & V_330 ,
. V_156 = V_334 ,
} ;
struct V_158 V_159 = {
. V_160 = V_2 ,
. V_150 = & V_151 ,
. V_163 = & V_164 ,
. V_103 = V_103 ,
} ;
return F_92 ( & V_159 ) ;
}
static void F_170 ( void )
{
F_20 ( V_23 L_82
L_83 ) ;
}
static void F_171 ( const struct V_1 * V_2 ,
const struct V_134 * V_144 )
{
const char * V_335 = L_84 ;
if ( F_71 ( V_144 ) )
V_335 = F_172 ( V_144 -> V_139 ) ;
F_20 ( V_23 L_85 ,
V_144 -> V_219 , V_144 -> V_136 , V_144 -> V_168 ,
V_2 , V_144 -> V_176 , V_144 -> V_261 , V_144 -> V_170 ,
V_2 -> V_70 , V_2 -> V_74 , F_125 ( V_144 ) ,
V_144 -> V_161 , V_335 ) ;
}
void F_173 ( struct V_3 * V_3 )
{
struct V_1 * V_2 ;
struct V_134 * V_144 ;
int V_336 = 0 ;
struct V_4 * V_5 = F_3 ( V_3 , V_6 ) ;
F_4 ( & V_5 -> V_7 ) ;
F_29 (clnt, &sn->all_clients, cl_clients) {
F_4 ( & V_2 -> V_80 ) ;
F_29 (task, &clnt->cl_tasks, tk_task) {
if ( ! V_336 ) {
F_170 () ;
V_336 ++ ;
}
F_171 ( V_2 , V_144 ) ;
}
F_6 ( & V_2 -> V_80 ) ;
}
F_6 ( & V_5 -> V_7 ) ;
}
