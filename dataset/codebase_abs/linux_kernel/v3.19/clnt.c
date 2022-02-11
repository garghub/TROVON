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
static struct V_39 * F_35 ( struct V_1 * V_2 ,
struct V_39 * V_40 ,
const struct V_41 * V_42 )
{
struct V_39 * V_43 ;
F_4 ( & V_2 -> V_44 ) ;
V_43 = F_36 ( V_2 -> V_45 ,
F_37 ( & V_2 -> V_44 ) ) ;
if ( ! F_38 ( V_40 ) )
V_2 -> V_46 = 1 ;
V_2 -> V_47 = V_42 ;
F_39 ( V_2 -> V_45 , V_40 ) ;
F_6 ( & V_2 -> V_44 ) ;
return V_43 ;
}
static void F_40 ( struct V_1 * V_2 , const char * V_48 )
{
V_2 -> V_49 = strlen ( V_48 ) ;
if ( V_2 -> V_49 > V_50 )
V_2 -> V_49 = V_50 ;
memcpy ( V_2 -> V_51 , V_48 , V_2 -> V_49 ) ;
}
static int F_41 ( struct V_1 * V_2 ,
T_2 V_52 ,
const char * V_53 )
{
struct V_54 V_55 = {
. V_52 = V_52 ,
. V_56 = V_53 ,
} ;
struct V_57 * V_58 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_10 * V_11 ;
int V_28 ;
V_28 = F_42 ( V_2 ) ;
if ( V_28 )
return V_28 ;
V_11 = F_12 ( V_3 ) ;
if ( V_11 ) {
V_28 = F_23 ( V_11 , V_2 ) ;
if ( V_28 )
goto V_59;
}
F_1 ( V_2 ) ;
if ( V_11 )
F_13 ( V_3 ) ;
V_58 = F_43 ( & V_55 , V_2 ) ;
if ( F_18 ( V_58 ) ) {
F_44 ( L_6 ,
V_52 ) ;
V_28 = F_21 ( V_58 ) ;
goto V_60;
}
return 0 ;
V_60:
V_11 = F_12 ( V_3 ) ;
F_7 ( V_2 ) ;
F_9 ( V_2 ) ;
V_59:
if ( V_11 )
F_13 ( V_3 ) ;
F_45 ( V_2 ) ;
return V_28 ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_61 ;
V_61 = F_47 ( & V_62 , 0 , 0 , V_63 ) ;
if ( V_61 < 0 )
return V_61 ;
V_2 -> V_64 = V_61 ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_49 ( & V_62 , V_2 -> V_64 ) ;
}
static struct V_1 * F_50 ( const struct V_65 * args ,
struct V_39 * V_40 ,
struct V_1 * V_66 )
{
const struct V_67 * V_68 = args -> V_68 ;
const struct V_69 * V_70 ;
struct V_1 * V_2 = NULL ;
const struct V_41 * V_42 ;
int V_28 ;
F_44 ( L_7 ,
V_68 -> V_18 , args -> V_71 , V_40 ) ;
V_28 = F_51 () ;
if ( V_28 )
goto V_72;
V_28 = - V_73 ;
if ( args -> V_70 >= V_68 -> V_74 )
goto V_75;
V_70 = V_68 -> V_70 [ args -> V_70 ] ;
if ( V_70 == NULL )
goto V_75;
V_28 = - V_76 ;
V_2 = F_52 ( sizeof( * V_2 ) , V_63 ) ;
if ( ! V_2 )
goto V_75;
V_2 -> V_33 = V_66 ? : V_2 ;
V_28 = F_46 ( V_2 ) ;
if ( V_28 )
goto V_77;
V_2 -> V_78 = V_70 -> V_79 ;
V_2 -> V_80 = V_70 -> V_81 ;
V_2 -> V_82 = args -> V_83 ? : V_68 -> V_84 ;
V_2 -> V_85 = V_70 -> V_84 ;
V_2 -> V_86 = V_68 -> V_87 ;
V_2 -> V_88 = F_53 ( V_2 ) ;
F_54 ( & V_2 -> V_24 ) ;
V_28 = - V_76 ;
if ( V_2 -> V_88 == NULL )
goto V_89;
V_2 -> V_16 = V_68 ;
F_55 ( & V_2 -> V_90 ) ;
F_56 ( & V_2 -> V_44 ) ;
V_42 = V_40 -> V_42 ;
if ( args -> V_42 != NULL ) {
memcpy ( & V_2 -> V_91 , args -> V_42 ,
sizeof( V_2 -> V_91 ) ) ;
V_42 = & V_2 -> V_91 ;
}
F_35 ( V_2 , V_40 , V_42 ) ;
V_2 -> V_92 = & V_2 -> V_93 ;
F_57 ( & V_2 -> V_93 , V_2 -> V_47 -> V_94 ) ;
F_58 ( & V_2 -> V_26 , 1 ) ;
F_40 ( V_2 , F_59 () -> V_48 ) ;
V_28 = F_41 ( V_2 , args -> V_95 , args -> V_53 ) ;
if ( V_28 )
goto V_96;
if ( V_66 )
F_60 ( & V_66 -> V_26 ) ;
return V_2 ;
V_96:
F_61 ( V_2 -> V_88 ) ;
V_89:
F_48 ( V_2 ) ;
V_77:
F_62 ( V_2 ) ;
V_75:
F_63 () ;
V_72:
F_64 ( V_40 ) ;
return F_19 ( V_28 ) ;
}
struct V_1 * F_65 ( struct V_65 * args ,
struct V_39 * V_40 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_50 ( args , V_40 , NULL ) ;
if ( F_18 ( V_2 ) )
return V_2 ;
if ( ! ( args -> V_97 & V_98 ) ) {
int V_28 = F_66 ( V_2 ) ;
if ( V_28 != 0 ) {
F_67 ( V_2 ) ;
return F_19 ( V_28 ) ;
}
}
V_2 -> V_99 = 1 ;
if ( args -> V_97 & V_100 )
V_2 -> V_99 = 0 ;
if ( args -> V_97 & V_101 )
V_2 -> V_46 = 1 ;
if ( args -> V_97 & V_102 )
V_2 -> V_103 = 1 ;
if ( args -> V_97 & V_104 )
V_2 -> V_105 = 1 ;
if ( ! ( args -> V_97 & V_106 ) )
V_2 -> V_107 = 1 ;
return V_2 ;
}
struct V_1 * F_68 ( struct V_65 * args )
{
struct V_39 * V_40 ;
struct V_108 V_109 = {
. V_3 = args -> V_3 ,
. V_110 = args -> V_111 ,
. V_112 = args -> V_113 ,
. V_114 = args -> V_115 ,
. V_116 = args -> V_117 ,
. V_71 = args -> V_71 ,
. V_118 = args -> V_118 ,
} ;
char V_71 [ 48 ] ;
if ( args -> V_97 & V_119 )
V_109 . V_97 |= V_120 ;
if ( args -> V_97 & V_121 )
V_109 . V_97 |= V_122 ;
if ( V_109 . V_71 == NULL ) {
struct V_123 * V_124 =
(struct V_123 * ) args -> V_115 ;
struct V_125 * sin =
(struct V_125 * ) args -> V_115 ;
struct V_126 * V_127 =
(struct V_126 * ) args -> V_115 ;
V_71 [ 0 ] = '\0' ;
switch ( args -> V_115 -> V_128 ) {
case V_129 :
snprintf ( V_71 , sizeof( V_71 ) , L_8 ,
V_124 -> V_130 ) ;
break;
case V_131 :
snprintf ( V_71 , sizeof( V_71 ) , L_9 ,
& sin -> V_132 . V_133 ) ;
break;
case V_134 :
snprintf ( V_71 , sizeof( V_71 ) , L_10 ,
& V_127 -> V_135 ) ;
break;
default:
return F_19 ( - V_73 ) ;
}
V_109 . V_71 = V_71 ;
}
V_40 = F_69 ( & V_109 ) ;
if ( F_18 ( V_40 ) )
return (struct V_1 * ) V_40 ;
V_40 -> V_136 = 1 ;
if ( args -> V_97 & V_137 )
V_40 -> V_136 = 0 ;
return F_65 ( args , V_40 ) ;
}
static struct V_1 * F_70 ( struct V_65 * args ,
struct V_1 * V_2 )
{
struct V_39 * V_40 ;
struct V_1 * V_138 ;
int V_28 ;
V_28 = - V_76 ;
F_71 () ;
V_40 = F_72 ( F_73 ( V_2 -> V_45 ) ) ;
F_74 () ;
if ( V_40 == NULL )
goto V_75;
args -> V_71 = V_40 -> V_71 ;
V_138 = F_50 ( args , V_40 , V_2 ) ;
if ( F_18 ( V_138 ) ) {
V_28 = F_21 ( V_138 ) ;
goto V_75;
}
V_138 -> V_46 = 0 ;
V_138 -> V_99 = V_2 -> V_99 ;
V_138 -> V_103 = V_2 -> V_103 ;
V_138 -> V_105 = V_2 -> V_105 ;
V_138 -> V_107 = V_2 -> V_107 ;
return V_138 ;
V_75:
F_44 ( L_11 , V_31 , V_28 ) ;
return F_19 ( V_28 ) ;
}
struct V_1 * F_75 ( struct V_1 * V_2 )
{
struct V_65 args = {
. V_68 = V_2 -> V_16 ,
. V_83 = V_2 -> V_82 ,
. V_70 = V_2 -> V_85 ,
. V_95 = V_2 -> V_139 -> V_140 ,
} ;
return F_70 ( & args , V_2 ) ;
}
struct V_1 *
F_76 ( struct V_1 * V_2 , T_2 V_141 )
{
struct V_65 args = {
. V_68 = V_2 -> V_16 ,
. V_83 = V_2 -> V_82 ,
. V_70 = V_2 -> V_85 ,
. V_95 = V_141 ,
} ;
return F_70 ( & args , V_2 ) ;
}
int F_77 ( struct V_1 * V_2 ,
struct V_108 * args ,
const struct V_41 * V_42 )
{
const struct V_41 * V_142 ;
T_2 V_52 ;
struct V_39 * V_40 , * V_43 ;
struct V_1 * V_66 ;
int V_28 ;
V_40 = F_69 ( args ) ;
if ( F_18 ( V_40 ) ) {
F_44 ( L_12 ,
V_2 ) ;
return F_21 ( V_40 ) ;
}
V_52 = V_2 -> V_139 -> V_140 ;
V_142 = V_2 -> V_47 ;
V_43 = F_35 ( V_2 , V_40 , V_42 ) ;
F_7 ( V_2 ) ;
F_9 ( V_2 ) ;
F_45 ( V_2 ) ;
V_66 = V_2 -> V_33 ;
V_2 -> V_33 = V_2 ;
V_28 = F_41 ( V_2 , V_52 , NULL ) ;
if ( V_28 )
goto V_143;
F_78 () ;
if ( V_66 != V_2 )
F_79 ( V_66 ) ;
F_64 ( V_43 ) ;
F_44 ( L_13 , V_2 ) ;
return 0 ;
V_143:
F_35 ( V_2 , V_43 , V_142 ) ;
V_2 -> V_33 = V_66 ;
F_41 ( V_2 , V_52 , NULL ) ;
F_64 ( V_40 ) ;
F_44 ( L_14 , V_2 ) ;
return V_28 ;
}
void F_80 ( struct V_1 * V_2 )
{
struct V_144 * V_145 ;
if ( F_81 ( & V_2 -> V_90 ) )
return;
F_44 ( L_15 , V_2 ) ;
F_4 ( & V_2 -> V_44 ) ;
F_29 (rovr, &clnt->cl_tasks, tk_task) {
if ( ! F_82 ( V_145 ) )
continue;
if ( ! ( V_145 -> V_146 & V_147 ) ) {
V_145 -> V_146 |= V_147 ;
F_83 ( V_145 , - V_148 ) ;
if ( F_84 ( V_145 ) )
F_85 ( V_145 -> V_149 ,
V_145 ) ;
}
}
F_6 ( & V_2 -> V_44 ) ;
}
void F_67 ( struct V_1 * V_2 )
{
F_86 () ;
F_87 ( L_16 ,
V_2 -> V_16 -> V_18 ,
F_73 ( V_2 -> V_45 ) -> V_71 ) ;
while ( ! F_81 ( & V_2 -> V_90 ) ) {
F_80 ( V_2 ) ;
F_88 ( V_150 ,
F_81 ( & V_2 -> V_90 ) , 1 * V_151 ) ;
}
F_79 ( V_2 ) ;
}
static struct V_1 *
F_89 ( struct V_1 * V_2 )
{
struct V_1 * V_66 = NULL ;
F_87 ( L_17 ,
V_2 -> V_16 -> V_18 ,
F_73 ( V_2 -> V_45 ) -> V_71 ) ;
if ( V_2 -> V_33 != V_2 )
V_66 = V_2 -> V_33 ;
F_45 ( V_2 ) ;
F_11 ( V_2 ) ;
F_7 ( V_2 ) ;
F_61 ( V_2 -> V_88 ) ;
V_2 -> V_88 = NULL ;
F_64 ( F_90 ( V_2 -> V_45 ) ) ;
F_63 () ;
F_48 ( V_2 ) ;
F_62 ( V_2 ) ;
return V_66 ;
}
static struct V_1 *
F_91 ( struct V_1 * V_2 )
{
if ( V_2 -> V_139 == NULL )
return F_89 ( V_2 ) ;
F_60 ( & V_2 -> V_26 ) ;
F_92 ( V_2 -> V_139 ) ;
V_2 -> V_139 = NULL ;
if ( F_93 ( & V_2 -> V_26 ) )
return F_89 ( V_2 ) ;
return NULL ;
}
void
F_79 ( struct V_1 * V_2 )
{
F_44 ( L_18 , V_2 ) ;
do {
if ( F_81 ( & V_2 -> V_90 ) )
F_94 ( & V_150 ) ;
if ( ! F_93 ( & V_2 -> V_26 ) )
break;
V_2 = F_91 ( V_2 ) ;
} while ( V_2 != NULL );
}
struct V_1 * F_95 ( struct V_1 * V_43 ,
const struct V_67 * V_68 ,
T_3 V_152 )
{
struct V_65 args = {
. V_68 = V_68 ,
. V_83 = V_68 -> V_84 ,
. V_70 = V_152 ,
. V_95 = V_43 -> V_139 -> V_140 ,
} ;
struct V_1 * V_2 ;
int V_28 ;
V_2 = F_70 ( & args , V_43 ) ;
if ( F_18 ( V_2 ) )
goto V_59;
V_28 = F_66 ( V_2 ) ;
if ( V_28 != 0 ) {
F_67 ( V_2 ) ;
V_2 = F_19 ( V_28 ) ;
}
V_59:
return V_2 ;
}
void F_96 ( struct V_144 * V_153 )
{
struct V_1 * V_2 = V_153 -> V_154 ;
if ( V_2 != NULL ) {
F_4 ( & V_2 -> V_44 ) ;
F_8 ( & V_153 -> V_155 ) ;
F_6 ( & V_2 -> V_44 ) ;
V_153 -> V_154 = NULL ;
F_79 ( V_2 ) ;
}
}
static
void F_97 ( struct V_144 * V_153 , struct V_1 * V_2 )
{
if ( V_2 != NULL ) {
F_96 ( V_153 ) ;
V_153 -> V_154 = V_2 ;
F_60 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_99 )
V_153 -> V_146 |= V_156 ;
if ( V_2 -> V_103 )
V_153 -> V_146 |= V_157 ;
if ( F_98 () ) {
struct V_39 * V_40 ;
F_71 () ;
V_40 = F_73 ( V_2 -> V_45 ) ;
if ( V_40 -> V_158 )
V_153 -> V_146 |= V_159 ;
F_74 () ;
}
F_4 ( & V_2 -> V_44 ) ;
F_99 ( & V_153 -> V_155 , & V_2 -> V_90 ) ;
F_6 ( & V_2 -> V_44 ) ;
}
}
void F_100 ( struct V_144 * V_153 , struct V_1 * V_2 )
{
F_96 ( V_153 ) ;
F_97 ( V_153 , V_2 ) ;
}
static void
F_101 ( struct V_144 * V_153 , const struct V_160 * V_161 )
{
if ( V_161 != NULL ) {
V_153 -> V_162 . V_163 = V_161 -> V_163 ;
V_153 -> V_162 . V_164 = V_161 -> V_164 ;
V_153 -> V_162 . V_165 = V_161 -> V_165 ;
if ( V_161 -> V_166 != NULL )
V_153 -> V_162 . V_166 = F_102 ( V_161 -> V_166 ) ;
}
}
static void
F_103 ( struct V_144 * V_153 , void * V_167 )
{
}
struct V_144 * F_104 ( const struct V_168 * V_169 )
{
struct V_144 * V_153 ;
V_153 = F_105 ( V_169 ) ;
if ( F_18 ( V_153 ) )
goto V_59;
F_97 ( V_153 , V_169 -> V_170 ) ;
F_101 ( V_153 , V_169 -> V_160 ) ;
if ( V_153 -> V_171 == NULL )
F_106 ( V_153 ) ;
F_60 ( & V_153 -> V_172 ) ;
F_107 ( V_153 ) ;
V_59:
return V_153 ;
}
int F_108 ( struct V_1 * V_2 , const struct V_160 * V_161 , int V_97 )
{
struct V_144 * V_153 ;
struct V_168 V_169 = {
. V_170 = V_2 ,
. V_160 = V_161 ,
. V_173 = & V_174 ,
. V_97 = V_97 ,
} ;
int V_175 ;
F_109 ( V_97 & V_176 ) ;
if ( V_97 & V_176 ) {
F_110 ( V_169 . V_173 ,
V_169 . V_177 ) ;
return - V_73 ;
}
V_153 = F_104 ( & V_169 ) ;
if ( F_18 ( V_153 ) )
return F_21 ( V_153 ) ;
V_175 = V_153 -> V_178 ;
F_111 ( V_153 ) ;
return V_175 ;
}
int
F_112 ( struct V_1 * V_2 , const struct V_160 * V_161 , int V_97 ,
const struct V_179 * V_180 , void * V_167 )
{
struct V_144 * V_153 ;
struct V_168 V_169 = {
. V_170 = V_2 ,
. V_160 = V_161 ,
. V_173 = V_180 ,
. V_177 = V_167 ,
. V_97 = V_97 | V_176 ,
} ;
V_153 = F_104 ( & V_169 ) ;
if ( F_18 ( V_153 ) )
return F_21 ( V_153 ) ;
F_111 ( V_153 ) ;
return 0 ;
}
struct V_144 * F_113 ( struct V_181 * V_182 ,
const struct V_179 * V_180 )
{
struct V_144 * V_153 ;
struct V_183 * V_184 = & V_182 -> V_185 ;
struct V_168 V_169 = {
. V_173 = V_180 ,
} ;
F_44 ( L_19 , V_182 ) ;
V_153 = F_105 ( & V_169 ) ;
if ( F_18 ( V_153 ) ) {
F_114 ( V_182 ) ;
goto V_59;
}
V_153 -> V_186 = V_182 ;
V_184 -> V_187 = V_184 -> V_188 [ 0 ] . V_189 + V_184 -> V_190 +
V_184 -> V_191 [ 0 ] . V_189 ;
V_153 -> V_171 = V_192 ;
F_60 ( & V_153 -> V_172 ) ;
F_109 ( F_25 ( & V_153 -> V_172 ) != 2 ) ;
F_107 ( V_153 ) ;
V_59:
F_44 ( L_20 , V_153 ) ;
return V_153 ;
}
void
F_106 ( struct V_144 * V_153 )
{
V_153 -> V_171 = V_193 ;
}
T_4 F_115 ( struct V_1 * V_2 , struct V_194 * V_195 , T_4 V_196 )
{
T_4 V_197 ;
struct V_39 * V_40 ;
F_71 () ;
V_40 = F_73 ( V_2 -> V_45 ) ;
V_197 = V_40 -> V_116 ;
if ( V_197 > V_196 )
V_197 = V_196 ;
memcpy ( V_195 , & V_40 -> V_198 , V_197 ) ;
F_74 () ;
return V_197 ;
}
const char * F_116 ( struct V_1 * V_2 ,
enum V_199 V_200 )
{
struct V_39 * V_40 ;
V_40 = F_73 ( V_2 -> V_45 ) ;
if ( V_40 -> V_201 [ V_200 ] != NULL )
return V_40 -> V_201 [ V_200 ] ;
else
return L_21 ;
}
static int F_117 ( struct V_3 * V_3 , struct V_194 * V_202 , T_4 V_203 ,
struct V_194 * V_195 , int V_204 )
{
struct V_205 * V_206 ;
int V_28 ;
V_28 = F_118 ( V_3 , V_202 -> V_128 ,
V_207 , V_208 , & V_206 , 1 ) ;
if ( V_28 < 0 ) {
F_44 ( L_22 , V_28 ) ;
goto V_59;
}
switch ( V_202 -> V_128 ) {
case V_131 :
V_28 = F_119 ( V_206 ,
(struct V_194 * ) & V_209 ,
sizeof( V_209 ) ) ;
break;
case V_134 :
V_28 = F_119 ( V_206 ,
(struct V_194 * ) & V_210 ,
sizeof( V_210 ) ) ;
break;
default:
V_28 = - V_211 ;
goto V_59;
}
if ( V_28 < 0 ) {
F_44 ( L_23 , V_28 ) ;
goto V_212;
}
V_28 = F_120 ( V_206 , V_202 , V_203 , 0 ) ;
if ( V_28 < 0 ) {
F_44 ( L_24 , V_28 ) ;
goto V_212;
}
V_28 = F_121 ( V_206 , V_195 , & V_204 ) ;
if ( V_28 < 0 ) {
F_44 ( L_25 , V_28 ) ;
goto V_212;
}
V_28 = 0 ;
if ( V_195 -> V_128 == V_134 ) {
struct V_126 * V_127 = (struct V_126 * ) V_195 ;
V_127 -> V_213 = 0 ;
}
F_44 ( L_26 , V_31 ) ;
V_212:
F_122 ( V_206 ) ;
V_59:
return V_28 ;
}
static int F_123 ( int V_214 , struct V_194 * V_195 , T_4 V_204 )
{
switch ( V_214 ) {
case V_131 :
if ( V_204 < sizeof( V_209 ) )
return - V_73 ;
memcpy ( V_195 , & V_209 ,
sizeof( V_209 ) ) ;
break;
case V_134 :
if ( V_204 < sizeof( V_210 ) )
return - V_73 ;
memcpy ( V_195 , & V_210 ,
sizeof( V_210 ) ) ;
default:
F_44 ( L_27 ,
V_31 ) ;
return - V_211 ;
}
F_44 ( L_28 , V_31 ) ;
return 0 ;
}
int F_124 ( struct V_1 * V_2 , struct V_194 * V_195 , T_4 V_204 )
{
struct V_215 V_115 ;
struct V_194 * V_202 = (struct V_194 * ) & V_115 ;
struct V_39 * V_40 ;
struct V_3 * V_3 ;
T_4 V_203 ;
int V_28 ;
F_71 () ;
V_40 = F_73 ( V_2 -> V_45 ) ;
V_203 = V_40 -> V_116 ;
memcpy ( V_202 , & V_40 -> V_198 , V_203 ) ;
V_3 = F_125 ( V_40 -> V_216 ) ;
F_74 () ;
F_126 ( V_202 , 0 ) ;
V_28 = F_117 ( V_3 , V_202 , V_203 , V_195 , V_204 ) ;
F_127 ( V_3 ) ;
if ( V_28 != 0 )
return F_123 ( V_202 -> V_128 , V_195 , V_204 ) ;
return 0 ;
}
void
F_128 ( struct V_1 * V_2 , unsigned int V_217 , unsigned int V_218 )
{
struct V_39 * V_40 ;
F_71 () ;
V_40 = F_73 ( V_2 -> V_45 ) ;
if ( V_40 -> V_219 -> V_220 )
V_40 -> V_219 -> V_220 ( V_40 , V_217 , V_218 ) ;
F_74 () ;
}
int F_129 ( struct V_1 * V_2 )
{
int V_111 ;
F_71 () ;
V_111 = F_73 ( V_2 -> V_45 ) -> V_221 ;
F_74 () ;
return V_111 ;
}
struct V_3 * F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_222 ;
F_71 () ;
V_222 = F_73 ( V_2 -> V_45 ) -> V_216 ;
F_74 () ;
return V_222 ;
}
T_4 F_130 ( struct V_1 * V_2 )
{
T_4 V_222 ;
F_71 () ;
V_222 = F_73 ( V_2 -> V_45 ) -> V_223 ;
F_74 () ;
return V_222 ;
}
unsigned long F_131 ( struct V_1 * V_2 )
{
unsigned long V_222 ;
F_71 () ;
V_222 = F_73 ( V_2 -> V_45 ) -> V_42 -> V_94 ;
F_74 () ;
return V_222 ;
}
void F_132 ( struct V_1 * V_2 )
{
if ( V_2 -> V_46 ) {
F_71 () ;
F_133 ( F_73 ( V_2 -> V_45 ) ) ;
F_74 () ;
}
}
int
F_134 ( struct V_144 * V_153 )
{
if ( F_135 ( V_153 ) )
return 0 ;
V_153 -> V_171 = V_193 ;
V_153 -> V_178 = 0 ;
if ( V_153 -> V_180 -> V_224 != NULL )
V_153 -> V_171 = V_225 ;
return 1 ;
}
int
F_136 ( struct V_144 * V_153 )
{
if ( F_135 ( V_153 ) )
return 0 ;
V_153 -> V_171 = V_193 ;
V_153 -> V_178 = 0 ;
return 1 ;
}
const char
* F_137 ( const struct V_144 * V_153 )
{
const struct V_226 * V_227 = V_153 -> V_162 . V_163 ;
if ( V_227 ) {
if ( V_227 -> V_228 )
return V_227 -> V_228 ;
else
return L_29 ;
} else
return L_30 ;
}
static void
V_193 ( struct V_144 * V_153 )
{
struct V_1 * V_2 = V_153 -> V_154 ;
F_44 ( L_31 , V_153 -> V_229 ,
V_2 -> V_16 -> V_18 , V_2 -> V_85 ,
F_137 ( V_153 ) ,
( F_138 ( V_153 ) ? L_32 : L_33 ) ) ;
V_153 -> V_162 . V_163 -> V_230 ++ ;
V_2 -> V_86 -> V_231 ++ ;
V_153 -> V_171 = V_232 ;
}
static void
V_232 ( struct V_144 * V_153 )
{
F_139 ( V_153 ) ;
V_153 -> V_178 = 0 ;
V_153 -> V_171 = V_233 ;
F_140 ( V_153 ) ;
}
static void
V_233 ( struct V_144 * V_153 )
{
int V_175 = V_153 -> V_178 ;
F_139 ( V_153 ) ;
V_153 -> V_178 = 0 ;
if ( V_175 >= 0 ) {
if ( V_153 -> V_186 ) {
V_153 -> V_171 = V_234 ;
return;
}
F_20 ( V_30 L_34 ,
V_31 , V_175 ) ;
F_83 ( V_153 , - V_148 ) ;
return;
}
if ( V_153 -> V_186 ) {
F_20 ( V_30 L_35 ,
V_31 , V_175 ) ;
F_141 ( V_153 ) ;
}
switch ( V_175 ) {
case - V_76 :
F_142 ( V_153 , V_151 >> 2 ) ;
case - V_235 :
V_153 -> V_171 = V_236 ;
return;
case - V_148 :
break;
default:
F_20 ( V_30 L_36 ,
V_31 , V_175 ) ;
break;
}
F_83 ( V_153 , V_175 ) ;
}
static void
V_236 ( struct V_144 * V_153 )
{
F_139 ( V_153 ) ;
V_153 -> V_178 = 0 ;
V_153 -> V_171 = V_233 ;
F_143 ( V_153 ) ;
}
static void
V_234 ( struct V_144 * V_153 )
{
F_139 ( V_153 ) ;
V_153 -> V_171 = V_237 ;
V_153 -> V_178 = 0 ;
V_153 -> V_154 -> V_86 -> V_238 ++ ;
F_144 ( V_153 ) ;
}
static void
V_237 ( struct V_144 * V_153 )
{
int V_175 = V_153 -> V_178 ;
F_139 ( V_153 ) ;
V_153 -> V_178 = 0 ;
V_153 -> V_171 = V_234 ;
switch ( V_175 ) {
case 0 :
if ( F_145 ( V_153 ) ) {
V_153 -> V_171 = V_239 ;
return;
}
case - V_240 :
F_142 ( V_153 , 3 * V_151 ) ;
case - V_235 :
V_175 = - V_241 ;
case - V_242 :
if ( ! V_153 -> V_243 )
break;
V_153 -> V_243 -- ;
F_44 ( L_37 ,
V_153 -> V_229 , V_31 ) ;
return;
}
F_44 ( L_38 ,
V_153 -> V_229 , V_31 , V_175 ) ;
F_83 ( V_153 , V_175 ) ;
}
static void
V_239 ( struct V_144 * V_153 )
{
unsigned int V_244 = V_153 -> V_186 -> V_245 -> V_246 -> V_247 ;
struct V_181 * V_182 = V_153 -> V_186 ;
struct V_39 * V_40 = V_182 -> V_248 ;
struct V_226 * V_227 = V_153 -> V_162 . V_163 ;
F_139 ( V_153 ) ;
V_153 -> V_178 = 0 ;
V_153 -> V_171 = V_249 ;
if ( V_182 -> V_250 )
return;
if ( V_227 -> V_251 != 0 ) {
F_146 ( V_227 -> V_252 == 0 ) ;
if ( V_227 -> V_253 != NULL )
F_146 ( V_227 -> V_254 == 0 ) ;
}
V_182 -> V_255 = V_256 + ( V_244 << 1 ) + V_227 -> V_252 ;
V_182 -> V_255 <<= 2 ;
V_182 -> V_257 = V_258 + V_244 + V_227 -> V_254 ;
V_182 -> V_257 <<= 2 ;
V_182 -> V_250 = V_40 -> V_219 -> V_259 ( V_153 ,
V_182 -> V_255 + V_182 -> V_257 ) ;
if ( V_182 -> V_250 != NULL )
return;
F_44 ( L_39 , V_153 -> V_229 ) ;
if ( F_138 ( V_153 ) || ! F_147 ( V_260 ) ) {
V_153 -> V_171 = V_239 ;
F_142 ( V_153 , V_151 >> 4 ) ;
return;
}
F_83 ( V_153 , - V_261 ) ;
}
static inline int
F_148 ( struct V_144 * V_153 )
{
return V_153 -> V_186 -> V_185 . V_187 == 0 ;
}
static inline void
F_149 ( struct V_144 * V_153 )
{
V_153 -> V_186 -> V_185 . V_187 = 0 ;
V_153 -> V_186 -> V_262 = 0 ;
}
static inline void
F_150 ( struct V_183 * V_195 , void * V_263 , T_4 V_187 )
{
V_195 -> V_188 [ 0 ] . V_264 = V_263 ;
V_195 -> V_188 [ 0 ] . V_189 = V_187 ;
V_195 -> V_191 [ 0 ] . V_189 = 0 ;
V_195 -> V_190 = 0 ;
V_195 -> V_97 = 0 ;
V_195 -> V_187 = 0 ;
V_195 -> V_204 = V_187 ;
}
static void
F_151 ( struct V_144 * V_153 )
{
struct V_181 * V_182 = V_153 -> V_186 ;
T_5 V_265 ;
T_6 * V_266 ;
F_139 ( V_153 ) ;
F_150 ( & V_182 -> V_185 ,
V_182 -> V_250 ,
V_182 -> V_255 ) ;
F_150 ( & V_182 -> V_267 ,
( char * ) V_182 -> V_250 + V_182 -> V_255 ,
V_182 -> V_257 ) ;
V_266 = F_152 ( V_153 ) ;
if ( V_266 == NULL ) {
F_20 ( V_21 L_40 ) ;
F_83 ( V_153 , - V_148 ) ;
return;
}
V_265 = V_153 -> V_162 . V_163 -> V_268 ;
if ( V_265 == NULL )
return;
V_153 -> V_178 = F_153 ( V_153 , V_265 , V_182 , V_266 ,
V_153 -> V_162 . V_164 ) ;
}
static void
V_249 ( struct V_144 * V_153 )
{
struct V_39 * V_40 = V_153 -> V_186 -> V_248 ;
F_139 ( V_153 ) ;
V_153 -> V_171 = V_269 ;
if ( ! F_38 ( V_40 ) ) {
V_153 -> V_171 = V_270 ;
V_153 -> V_271 = V_40 -> V_272 ;
V_40 -> V_219 -> V_273 ( V_153 ) ;
}
}
static void
V_270 ( struct V_144 * V_153 )
{
int V_175 = - V_148 ;
if ( V_153 -> V_178 >= 0 ) {
F_139 ( V_153 ) ;
V_153 -> V_178 = 0 ;
V_153 -> V_171 = V_269 ;
return;
}
F_154 ( V_153 ) ;
switch ( V_153 -> V_178 ) {
case - V_76 :
F_44 ( L_41 , V_153 -> V_229 ) ;
F_142 ( V_153 , V_151 >> 2 ) ;
goto V_274;
case - V_241 :
F_44 ( L_42
L_43 , V_153 -> V_229 ) ;
if ( V_153 -> V_162 . V_163 -> V_251 == 0 ) {
V_175 = - V_275 ;
break;
}
if ( V_153 -> V_276 == 0 )
break;
V_153 -> V_276 -- ;
F_142 ( V_153 , 3 * V_151 ) ;
goto V_274;
case - V_240 :
F_44 ( L_44 ,
V_153 -> V_229 ) ;
goto V_274;
case - V_277 :
F_44 ( L_45 ,
V_153 -> V_229 ) ;
break;
case - V_278 :
F_44 ( L_46 ,
V_153 -> V_229 ) ;
goto V_274;
case - V_279 :
case - V_280 :
case - V_281 :
case - V_282 :
case - V_283 :
case - V_284 :
case - V_285 :
case - V_286 :
case - V_287 :
F_44 ( L_47 ,
V_153 -> V_229 , V_153 -> V_178 ) ;
if ( ! F_155 ( V_153 ) ) {
F_142 ( V_153 , 5 * V_151 ) ;
goto V_274;
}
V_175 = V_153 -> V_178 ;
break;
default:
F_44 ( L_48 ,
V_153 -> V_229 , - V_153 -> V_178 ) ;
}
F_83 ( V_153 , V_175 ) ;
return;
V_274:
V_153 -> V_178 = 0 ;
V_153 -> V_171 = V_288 ;
}
static void
V_269 ( struct V_144 * V_153 )
{
struct V_39 * V_40 = V_153 -> V_186 -> V_248 ;
F_44 ( L_49 ,
V_153 -> V_229 , V_40 ,
( F_156 ( V_40 ) ? L_50 : L_51 ) ) ;
V_153 -> V_171 = V_289 ;
if ( ! F_156 ( V_40 ) ) {
V_153 -> V_171 = V_290 ;
if ( V_153 -> V_178 < 0 )
return;
if ( V_153 -> V_146 & V_291 ) {
F_83 ( V_153 , - V_282 ) ;
return;
}
F_157 ( V_153 ) ;
}
}
static void
V_290 ( struct V_144 * V_153 )
{
struct V_1 * V_2 = V_153 -> V_154 ;
int V_175 = V_153 -> V_178 ;
F_139 ( V_153 ) ;
F_158 ( V_153 , V_175 ) ;
V_153 -> V_178 = 0 ;
switch ( V_175 ) {
case - V_279 :
case - V_280 :
case - V_281 :
case - V_285 :
case - V_284 :
case - V_286 :
case - V_287 :
if ( F_155 ( V_153 ) )
break;
F_142 ( V_153 , 3 * V_151 ) ;
case - V_235 :
case - V_240 :
V_153 -> V_171 = V_288 ;
return;
case 0 :
V_2 -> V_86 -> V_292 ++ ;
V_153 -> V_171 = V_289 ;
return;
}
F_83 ( V_153 , V_175 ) ;
}
static void
V_289 ( struct V_144 * V_153 )
{
int V_293 = F_159 ( V_153 ) ;
F_139 ( V_153 ) ;
V_153 -> V_171 = V_294 ;
if ( V_153 -> V_178 < 0 )
return;
if ( ! F_160 ( V_153 ) )
return;
V_153 -> V_171 = V_295 ;
if ( F_148 ( V_153 ) ) {
F_151 ( V_153 ) ;
if ( V_153 -> V_178 != 0 ) {
if ( V_153 -> V_178 == - V_235 )
F_142 ( V_153 , V_151 >> 4 ) ;
else
F_83 ( V_153 , V_153 -> V_178 ) ;
return;
}
}
F_161 ( V_153 ) ;
if ( V_153 -> V_178 < 0 )
return;
if ( V_293 )
V_153 -> V_154 -> V_86 -> V_296 ++ ;
V_295 ( V_153 ) ;
if ( F_162 ( V_153 ) )
return;
V_153 -> V_171 = V_297 ;
F_85 ( & V_153 -> V_186 -> V_248 -> V_298 , V_153 ) ;
}
static void
V_295 ( struct V_144 * V_153 )
{
V_153 -> V_171 = V_294 ;
if ( V_153 -> V_178 == 0 ) {
F_163 ( V_153 ) ;
F_149 ( V_153 ) ;
return;
}
switch ( V_153 -> V_178 ) {
case - V_235 :
break;
default:
F_139 ( V_153 ) ;
F_163 ( V_153 ) ;
F_149 ( V_153 ) ;
break;
case - V_279 :
case - V_283 :
case - V_284 :
case - V_285 :
case - V_299 :
if ( F_155 ( V_153 ) ) {
F_163 ( V_153 ) ;
F_83 ( V_153 , V_153 -> V_178 ) ;
break;
}
case - V_280 :
case - V_281 :
case - V_282 :
case - V_286 :
case - V_287 :
F_149 ( V_153 ) ;
}
}
static void
V_192 ( struct V_144 * V_153 )
{
struct V_181 * V_182 = V_153 -> V_186 ;
if ( ! F_160 ( V_153 ) ) {
V_153 -> V_178 = 0 ;
V_153 -> V_171 = V_192 ;
return;
}
V_153 -> V_171 = V_297 ;
if ( V_153 -> V_178 < 0 ) {
F_20 ( V_300 L_52
L_53 , V_153 -> V_178 ) ;
return;
}
F_161 ( V_153 ) ;
F_163 ( V_153 ) ;
F_139 ( V_153 ) ;
switch ( V_153 -> V_178 ) {
case 0 :
break;
case - V_283 :
case - V_284 :
case - V_285 :
case - V_240 :
F_20 ( V_300 L_52
L_53 , V_153 -> V_178 ) ;
F_164 ( V_182 -> V_248 ,
V_182 -> V_301 ) ;
break;
default:
F_109 ( V_153 -> V_178 == - V_235 ) ;
F_20 ( V_300 L_52
L_53 , V_153 -> V_178 ) ;
break;
}
F_85 ( & V_182 -> V_248 -> V_298 , V_153 ) ;
}
static void
V_294 ( struct V_144 * V_153 )
{
struct V_1 * V_2 = V_153 -> V_154 ;
struct V_181 * V_182 = V_153 -> V_186 ;
int V_175 ;
if ( V_182 -> V_302 > 0 && ! V_182 -> V_262 )
V_153 -> V_178 = V_182 -> V_302 ;
F_139 ( V_153 ) ;
V_175 = V_153 -> V_178 ;
if ( V_175 >= 0 ) {
V_153 -> V_171 = V_303 ;
return;
}
F_165 ( V_153 ) ;
V_153 -> V_178 = 0 ;
switch( V_175 ) {
case - V_283 :
case - V_284 :
case - V_285 :
case - V_299 :
if ( F_155 ( V_153 ) ) {
F_83 ( V_153 , V_175 ) ;
break;
}
F_142 ( V_153 , 3 * V_151 ) ;
case - V_240 :
V_153 -> V_171 = V_288 ;
if ( ! ( V_153 -> V_146 & V_157 )
&& V_153 -> V_154 -> V_105 )
F_164 ( V_182 -> V_248 ,
V_182 -> V_301 ) ;
break;
case - V_279 :
case - V_280 :
case - V_281 :
F_132 ( V_2 ) ;
case - V_286 :
F_142 ( V_153 , 3 * V_151 ) ;
case - V_287 :
case - V_282 :
V_153 -> V_171 = V_249 ;
break;
case - V_235 :
V_153 -> V_171 = V_289 ;
break;
case - V_148 :
F_83 ( V_153 , V_175 ) ;
break;
default:
if ( V_2 -> V_107 )
F_20 ( L_54 ,
V_2 -> V_16 -> V_18 , - V_175 ) ;
F_83 ( V_153 , V_175 ) ;
}
}
static void
V_288 ( struct V_144 * V_153 )
{
struct V_1 * V_2 = V_153 -> V_154 ;
if ( F_166 ( V_153 -> V_186 ) == 0 ) {
F_44 ( L_55 , V_153 -> V_229 ) ;
goto V_304;
}
F_44 ( L_56 , V_153 -> V_229 ) ;
V_153 -> V_305 ++ ;
if ( F_155 ( V_153 ) ) {
F_83 ( V_153 , - V_240 ) ;
return;
}
if ( F_167 ( V_153 ) ) {
if ( V_2 -> V_107 ) {
F_71 () ;
F_20 ( V_300 L_57 ,
V_2 -> V_16 -> V_18 ,
F_73 ( V_2 -> V_45 ) -> V_71 ) ;
F_74 () ;
}
if ( V_153 -> V_146 & V_306 )
F_83 ( V_153 , - V_240 ) ;
else
F_83 ( V_153 , - V_148 ) ;
return;
}
if ( ! ( V_153 -> V_146 & V_307 ) ) {
V_153 -> V_146 |= V_307 ;
if ( V_2 -> V_107 ) {
F_71 () ;
F_20 ( V_300 L_58 ,
V_2 -> V_16 -> V_18 ,
F_73 ( V_2 -> V_45 ) -> V_71 ) ;
F_74 () ;
}
}
F_132 ( V_2 ) ;
F_168 ( V_153 ) ;
V_304:
V_153 -> V_171 = V_249 ;
V_153 -> V_178 = 0 ;
}
static void
V_303 ( struct V_144 * V_153 )
{
struct V_1 * V_2 = V_153 -> V_154 ;
struct V_181 * V_182 = V_153 -> V_186 ;
T_7 V_308 = V_153 -> V_162 . V_163 -> V_253 ;
T_6 * V_266 ;
F_139 ( V_153 ) ;
if ( V_153 -> V_146 & V_307 ) {
if ( V_2 -> V_107 ) {
F_71 () ;
F_20 ( V_300 L_59 ,
V_2 -> V_16 -> V_18 ,
F_73 ( V_2 -> V_45 ) -> V_71 ) ;
F_74 () ;
}
V_153 -> V_146 &= ~ V_307 ;
}
F_169 () ;
V_182 -> V_267 . V_187 = V_182 -> V_309 . V_187 ;
F_170 ( memcmp ( & V_182 -> V_267 , & V_182 -> V_309 ,
sizeof( V_182 -> V_267 ) ) != 0 ) ;
if ( V_182 -> V_267 . V_187 < 12 ) {
if ( ! F_167 ( V_153 ) ) {
V_153 -> V_171 = V_249 ;
goto V_310;
}
F_44 ( L_60 ,
V_2 -> V_16 -> V_18 , V_153 -> V_178 ) ;
V_153 -> V_171 = V_288 ;
goto V_310;
}
V_266 = F_171 ( V_153 ) ;
if ( F_18 ( V_266 ) ) {
if ( V_266 == F_19 ( - V_235 ) )
goto V_310;
return;
}
V_153 -> V_171 = V_297 ;
if ( V_308 ) {
V_153 -> V_178 = F_172 ( V_153 , V_308 , V_182 , V_266 ,
V_153 -> V_162 . V_165 ) ;
}
F_44 ( L_61 , V_153 -> V_229 ,
V_153 -> V_178 ) ;
return;
V_310:
V_153 -> V_178 = 0 ;
if ( V_153 -> V_186 == V_182 ) {
V_182 -> V_302 = V_182 -> V_267 . V_187 = 0 ;
if ( V_153 -> V_154 -> V_105 )
F_164 ( V_182 -> V_248 ,
V_182 -> V_301 ) ;
}
}
static T_6 *
F_152 ( struct V_144 * V_153 )
{
struct V_1 * V_2 = V_153 -> V_154 ;
struct V_181 * V_182 = V_153 -> V_186 ;
T_6 * V_266 = V_182 -> V_311 [ 0 ] . V_264 ;
V_266 = F_173 ( V_182 -> V_248 , V_266 ) ;
* V_266 ++ = V_182 -> V_312 ;
* V_266 ++ = F_174 ( V_313 ) ;
* V_266 ++ = F_174 ( V_314 ) ;
* V_266 ++ = F_174 ( V_2 -> V_82 ) ;
* V_266 ++ = F_174 ( V_2 -> V_85 ) ;
* V_266 ++ = F_174 ( V_153 -> V_162 . V_163 -> V_251 ) ;
V_266 = F_175 ( V_153 , V_266 ) ;
V_182 -> V_315 = F_176 ( & V_182 -> V_311 [ 0 ] , V_266 ) ;
return V_266 ;
}
static T_6 *
F_171 ( struct V_144 * V_153 )
{
struct V_1 * V_2 = V_153 -> V_154 ;
struct V_316 * V_317 = & V_153 -> V_186 -> V_267 . V_188 [ 0 ] ;
int V_187 = V_153 -> V_186 -> V_267 . V_187 >> 2 ;
T_6 * V_266 = V_317 -> V_264 ;
T_3 V_318 ;
int error = - V_241 ;
if ( ( V_153 -> V_186 -> V_267 . V_187 & 3 ) != 0 ) {
F_44 ( L_62
L_63 , V_153 -> V_229 , V_31 ,
V_153 -> V_186 -> V_267 . V_187 ) ;
error = - V_148 ;
goto V_75;
}
if ( ( V_187 -= 3 ) < 0 )
goto V_319;
V_266 += 1 ;
if ( ( V_318 = F_177 ( * V_266 ++ ) ) != V_320 ) {
F_44 ( L_64 ,
V_153 -> V_229 , V_31 , V_318 ) ;
error = - V_148 ;
goto V_321;
}
if ( ( V_318 = F_177 ( * V_266 ++ ) ) != V_322 ) {
if ( -- V_187 < 0 )
goto V_319;
switch ( ( V_318 = F_177 ( * V_266 ++ ) ) ) {
case V_323 :
break;
case V_324 :
F_44 ( L_65 ,
V_153 -> V_229 , V_31 ) ;
error = - V_278 ;
goto V_75;
default:
F_44 ( L_66
L_67 ,
V_153 -> V_229 , V_31 , V_318 ) ;
error = - V_148 ;
goto V_75;
}
if ( -- V_187 < 0 )
goto V_319;
switch ( ( V_318 = F_177 ( * V_266 ++ ) ) ) {
case V_325 :
case V_326 :
case V_327 :
case V_328 :
if ( ! V_153 -> V_243 )
break;
V_153 -> V_243 -- ;
F_44 ( L_68 ,
V_153 -> V_229 , V_31 ) ;
F_168 ( V_153 ) ;
F_141 ( V_153 ) ;
V_153 -> V_171 = V_232 ;
goto V_310;
case V_329 :
case V_330 :
if ( ! V_153 -> V_331 )
break;
V_153 -> V_331 -- ;
F_44 ( L_69 ,
V_153 -> V_229 , V_31 ) ;
V_153 -> V_171 = V_249 ;
goto V_310;
case V_332 :
F_71 () ;
F_20 ( V_300 L_70
L_71 ,
F_73 ( V_2 -> V_45 ) -> V_71 ) ;
F_74 () ;
break;
default:
F_44 ( L_72 ,
V_153 -> V_229 , V_31 , V_318 ) ;
error = - V_148 ;
}
F_44 ( L_73 ,
V_153 -> V_229 , V_31 , V_318 ) ;
goto V_75;
}
V_266 = F_178 ( V_153 , V_266 ) ;
if ( F_18 ( V_266 ) ) {
error = F_21 ( V_266 ) ;
F_44 ( L_74 ,
V_153 -> V_229 , V_31 , error ) ;
goto V_321;
}
V_187 = V_266 - ( T_6 * ) V_317 -> V_264 - 1 ;
if ( V_187 < 0 )
goto V_319;
switch ( ( V_318 = F_177 ( * V_266 ++ ) ) ) {
case V_333 :
return V_266 ;
case V_334 :
F_87 ( L_75
L_76 , V_153 -> V_229 , V_31 ,
( unsigned int ) V_2 -> V_82 ,
F_73 ( V_2 -> V_45 ) -> V_71 ) ;
error = - V_277 ;
goto V_75;
case V_335 :
F_87 ( L_77
L_76 , V_153 -> V_229 , V_31 ,
( unsigned int ) V_2 -> V_82 ,
( unsigned int ) V_2 -> V_85 ,
F_73 ( V_2 -> V_45 ) -> V_71 ) ;
error = - V_278 ;
goto V_75;
case V_336 :
F_87 ( L_78
L_79 ,
V_153 -> V_229 , V_31 ,
F_137 ( V_153 ) ,
V_2 -> V_82 , V_2 -> V_85 ,
F_73 ( V_2 -> V_45 ) -> V_71 ) ;
error = - V_275 ;
goto V_75;
case V_337 :
F_44 ( L_80 ,
V_153 -> V_229 , V_31 ) ;
break;
default:
F_44 ( L_81 ,
V_153 -> V_229 , V_31 , V_318 ) ;
}
V_321:
V_2 -> V_86 -> V_338 ++ ;
if ( V_153 -> V_331 ) {
V_153 -> V_331 -- ;
F_44 ( L_82 ,
V_153 -> V_229 , V_31 ) ;
V_153 -> V_171 = V_249 ;
V_310:
return F_19 ( - V_235 ) ;
}
V_75:
F_83 ( V_153 , error ) ;
F_44 ( L_83 , V_153 -> V_229 ,
V_31 , error ) ;
return F_19 ( error ) ;
V_319:
F_44 ( L_84 , V_153 -> V_229 ,
V_31 ) ;
goto V_321;
}
static void F_179 ( void * V_339 , struct V_340 * V_341 , void * V_342 )
{
}
static int F_180 ( void * V_339 , struct V_340 * V_341 , void * V_342 )
{
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_160 V_161 = {
. V_163 = & V_343 ,
} ;
int V_28 ;
V_161 . V_166 = V_344 . V_345 ( NULL , NULL , 0 ) ;
V_28 = F_108 ( V_2 , & V_161 , V_156 | V_346 ) ;
F_181 ( V_161 . V_166 ) ;
return V_28 ;
}
struct V_144 * F_182 ( struct V_1 * V_2 , struct V_166 * V_347 , int V_97 )
{
struct V_160 V_161 = {
. V_163 = & V_343 ,
. V_166 = V_347 ,
} ;
struct V_168 V_169 = {
. V_170 = V_2 ,
. V_160 = & V_161 ,
. V_173 = & V_174 ,
. V_97 = V_97 ,
} ;
return F_104 ( & V_169 ) ;
}
static void F_183 ( void )
{
F_20 ( V_21 L_85
L_86 ) ;
}
static void F_184 ( const struct V_1 * V_2 ,
const struct V_144 * V_153 )
{
const char * V_348 = L_87 ;
if ( F_84 ( V_153 ) )
V_348 = F_185 ( V_153 -> V_149 ) ;
F_20 ( V_21 L_88 ,
V_153 -> V_229 , V_153 -> V_146 , V_153 -> V_178 ,
V_2 , V_153 -> V_186 , V_153 -> V_271 , V_153 -> V_180 ,
V_2 -> V_16 -> V_18 , V_2 -> V_85 , F_137 ( V_153 ) ,
V_153 -> V_171 , V_348 ) ;
}
void F_186 ( struct V_3 * V_3 )
{
struct V_1 * V_2 ;
struct V_144 * V_153 ;
int V_349 = 0 ;
struct V_4 * V_5 = F_3 ( V_3 , V_6 ) ;
F_4 ( & V_5 -> V_7 ) ;
F_29 (clnt, &sn->all_clients, cl_clients) {
F_4 ( & V_2 -> V_44 ) ;
F_29 (task, &clnt->cl_tasks, tk_task) {
if ( ! V_349 ) {
F_183 () ;
V_349 ++ ;
}
F_184 ( V_2 , V_153 ) ;
}
F_6 ( & V_2 -> V_44 ) ;
}
F_6 ( & V_5 -> V_7 ) ;
}
