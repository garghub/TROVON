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
V_11 = F_12 ( V_3 ) ;
if ( V_11 ) {
V_28 = F_23 ( V_11 , V_2 ) ;
if ( V_28 )
goto V_59;
}
F_1 ( V_2 ) ;
if ( V_11 )
F_13 ( V_3 ) ;
V_58 = F_42 ( & V_55 , V_2 ) ;
if ( F_18 ( V_58 ) ) {
F_43 ( L_6 ,
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
return V_28 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_61 ;
V_61 = F_45 ( & V_62 , 0 , 0 , V_63 ) ;
if ( V_61 < 0 )
return V_61 ;
V_2 -> V_64 = V_61 ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_47 ( & V_62 , V_2 -> V_64 ) ;
}
static struct V_1 * F_48 ( const struct V_65 * args ,
struct V_39 * V_40 ,
struct V_1 * V_66 )
{
const struct V_67 * V_68 = args -> V_68 ;
const struct V_69 * V_70 ;
struct V_1 * V_2 = NULL ;
const struct V_41 * V_42 ;
int V_28 ;
F_43 ( L_7 ,
V_68 -> V_18 , args -> V_71 , V_40 ) ;
V_28 = F_49 () ;
if ( V_28 )
goto V_72;
V_28 = - V_73 ;
if ( args -> V_70 >= V_68 -> V_74 )
goto V_75;
V_70 = V_68 -> V_70 [ args -> V_70 ] ;
if ( V_70 == NULL )
goto V_75;
V_28 = - V_76 ;
V_2 = F_50 ( sizeof( * V_2 ) , V_63 ) ;
if ( ! V_2 )
goto V_75;
V_2 -> V_33 = V_66 ? : V_2 ;
V_28 = F_44 ( V_2 ) ;
if ( V_28 )
goto V_77;
V_2 -> V_78 = V_70 -> V_79 ;
V_2 -> V_80 = V_70 -> V_81 ;
V_2 -> V_82 = args -> V_83 ? : V_68 -> V_84 ;
V_2 -> V_85 = V_70 -> V_84 ;
V_2 -> V_86 = V_68 -> V_87 ;
V_2 -> V_88 = F_51 ( V_2 ) ;
F_52 ( & V_2 -> V_24 ) ;
V_28 = - V_76 ;
if ( V_2 -> V_88 == NULL )
goto V_89;
V_2 -> V_16 = V_68 ;
F_53 ( & V_2 -> V_90 ) ;
F_54 ( & V_2 -> V_44 ) ;
V_42 = V_40 -> V_42 ;
if ( args -> V_42 != NULL ) {
memcpy ( & V_2 -> V_91 , args -> V_42 ,
sizeof( V_2 -> V_91 ) ) ;
V_42 = & V_2 -> V_91 ;
}
F_35 ( V_2 , V_40 , V_42 ) ;
V_2 -> V_92 = & V_2 -> V_93 ;
F_55 ( & V_2 -> V_93 , V_2 -> V_47 -> V_94 ) ;
F_56 ( & V_2 -> V_26 , 1 ) ;
F_40 ( V_2 , F_57 () -> V_48 ) ;
V_28 = F_41 ( V_2 , args -> V_95 , args -> V_53 ) ;
if ( V_28 )
goto V_96;
if ( V_66 )
F_58 ( & V_66 -> V_26 ) ;
return V_2 ;
V_96:
F_59 ( V_2 -> V_88 ) ;
V_89:
F_46 ( V_2 ) ;
V_77:
F_60 ( V_2 ) ;
V_75:
F_61 () ;
V_72:
F_62 ( V_40 ) ;
return F_19 ( V_28 ) ;
}
struct V_1 * F_63 ( struct V_65 * args ,
struct V_39 * V_40 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_48 ( args , V_40 , NULL ) ;
if ( F_18 ( V_2 ) )
return V_2 ;
if ( ! ( args -> V_97 & V_98 ) ) {
int V_28 = F_64 ( V_2 ) ;
if ( V_28 != 0 ) {
F_65 ( V_2 ) ;
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
if ( ! ( args -> V_97 & V_104 ) )
V_2 -> V_105 = 1 ;
return V_2 ;
}
struct V_1 * F_66 ( struct V_65 * args )
{
struct V_39 * V_40 ;
struct V_106 V_107 = {
. V_3 = args -> V_3 ,
. V_108 = args -> V_109 ,
. V_110 = args -> V_111 ,
. V_112 = args -> V_113 ,
. V_114 = args -> V_115 ,
. V_71 = args -> V_71 ,
. V_116 = args -> V_116 ,
} ;
char V_71 [ 48 ] ;
if ( args -> V_97 & V_117 )
V_107 . V_97 |= V_118 ;
if ( args -> V_97 & V_119 )
V_107 . V_97 |= V_120 ;
if ( V_107 . V_71 == NULL ) {
struct V_121 * V_122 =
(struct V_121 * ) args -> V_113 ;
struct V_123 * sin =
(struct V_123 * ) args -> V_113 ;
struct V_124 * V_125 =
(struct V_124 * ) args -> V_113 ;
V_71 [ 0 ] = '\0' ;
switch ( args -> V_113 -> V_126 ) {
case V_127 :
snprintf ( V_71 , sizeof( V_71 ) , L_8 ,
V_122 -> V_128 ) ;
break;
case V_129 :
snprintf ( V_71 , sizeof( V_71 ) , L_9 ,
& sin -> V_130 . V_131 ) ;
break;
case V_132 :
snprintf ( V_71 , sizeof( V_71 ) , L_10 ,
& V_125 -> V_133 ) ;
break;
default:
return F_19 ( - V_73 ) ;
}
V_107 . V_71 = V_71 ;
}
V_40 = F_67 ( & V_107 ) ;
if ( F_18 ( V_40 ) )
return (struct V_1 * ) V_40 ;
V_40 -> V_134 = 1 ;
if ( args -> V_97 & V_135 )
V_40 -> V_134 = 0 ;
return F_63 ( args , V_40 ) ;
}
static struct V_1 * F_68 ( struct V_65 * args ,
struct V_1 * V_2 )
{
struct V_39 * V_40 ;
struct V_1 * V_136 ;
int V_28 ;
V_28 = - V_76 ;
F_69 () ;
V_40 = F_70 ( F_71 ( V_2 -> V_45 ) ) ;
F_72 () ;
if ( V_40 == NULL )
goto V_75;
args -> V_71 = V_40 -> V_71 ;
V_136 = F_48 ( args , V_40 , V_2 ) ;
if ( F_18 ( V_136 ) ) {
V_28 = F_21 ( V_136 ) ;
goto V_75;
}
V_136 -> V_46 = 0 ;
V_136 -> V_99 = V_2 -> V_99 ;
V_136 -> V_103 = V_2 -> V_103 ;
V_136 -> V_105 = V_2 -> V_105 ;
return V_136 ;
V_75:
F_43 ( L_11 , V_31 , V_28 ) ;
return F_19 ( V_28 ) ;
}
struct V_1 * F_73 ( struct V_1 * V_2 )
{
struct V_65 args = {
. V_68 = V_2 -> V_16 ,
. V_83 = V_2 -> V_82 ,
. V_70 = V_2 -> V_85 ,
. V_95 = V_2 -> V_137 -> V_138 ,
} ;
return F_68 ( & args , V_2 ) ;
}
struct V_1 *
F_74 ( struct V_1 * V_2 , T_2 V_139 )
{
struct V_65 args = {
. V_68 = V_2 -> V_16 ,
. V_83 = V_2 -> V_82 ,
. V_70 = V_2 -> V_85 ,
. V_95 = V_139 ,
} ;
return F_68 ( & args , V_2 ) ;
}
int F_75 ( struct V_1 * V_2 ,
struct V_106 * args ,
const struct V_41 * V_42 )
{
const struct V_41 * V_140 ;
T_2 V_52 ;
struct V_39 * V_40 , * V_43 ;
struct V_1 * V_66 ;
int V_28 ;
V_40 = F_67 ( args ) ;
if ( F_18 ( V_40 ) ) {
F_43 ( L_12 ,
V_2 ) ;
return F_21 ( V_40 ) ;
}
V_52 = V_2 -> V_137 -> V_138 ;
V_140 = V_2 -> V_47 ;
V_43 = F_35 ( V_2 , V_40 , V_42 ) ;
F_7 ( V_2 ) ;
F_9 ( V_2 ) ;
V_66 = V_2 -> V_33 ;
V_2 -> V_33 = V_2 ;
V_28 = F_41 ( V_2 , V_52 , NULL ) ;
if ( V_28 )
goto V_141;
F_76 () ;
if ( V_66 != V_2 )
F_77 ( V_66 ) ;
F_62 ( V_43 ) ;
F_43 ( L_13 , V_2 ) ;
return 0 ;
V_141:
F_35 ( V_2 , V_43 , V_140 ) ;
V_2 -> V_33 = V_66 ;
F_41 ( V_2 , V_52 , NULL ) ;
F_62 ( V_40 ) ;
F_43 ( L_14 , V_2 ) ;
return V_28 ;
}
void F_78 ( struct V_1 * V_2 )
{
struct V_142 * V_143 ;
if ( F_79 ( & V_2 -> V_90 ) )
return;
F_43 ( L_15 , V_2 ) ;
F_4 ( & V_2 -> V_44 ) ;
F_29 (rovr, &clnt->cl_tasks, tk_task) {
if ( ! F_80 ( V_143 ) )
continue;
if ( ! ( V_143 -> V_144 & V_145 ) ) {
V_143 -> V_144 |= V_145 ;
F_81 ( V_143 , - V_146 ) ;
if ( F_82 ( V_143 ) )
F_83 ( V_143 -> V_147 ,
V_143 ) ;
}
}
F_6 ( & V_2 -> V_44 ) ;
}
void F_65 ( struct V_1 * V_2 )
{
F_84 () ;
F_85 ( L_16 ,
V_2 -> V_16 -> V_18 ,
F_71 ( V_2 -> V_45 ) -> V_71 ) ;
while ( ! F_79 ( & V_2 -> V_90 ) ) {
F_78 ( V_2 ) ;
F_86 ( V_148 ,
F_79 ( & V_2 -> V_90 ) , 1 * V_149 ) ;
}
F_77 ( V_2 ) ;
}
static struct V_1 *
F_87 ( struct V_1 * V_2 )
{
struct V_1 * V_66 = NULL ;
F_85 ( L_17 ,
V_2 -> V_16 -> V_18 ,
F_71 ( V_2 -> V_45 ) -> V_71 ) ;
if ( V_2 -> V_33 != V_2 )
V_66 = V_2 -> V_33 ;
F_11 ( V_2 ) ;
F_7 ( V_2 ) ;
F_59 ( V_2 -> V_88 ) ;
V_2 -> V_88 = NULL ;
F_62 ( F_88 ( V_2 -> V_45 ) ) ;
F_61 () ;
F_46 ( V_2 ) ;
F_60 ( V_2 ) ;
return V_66 ;
}
static struct V_1 *
F_89 ( struct V_1 * V_2 )
{
if ( V_2 -> V_137 == NULL )
return F_87 ( V_2 ) ;
F_58 ( & V_2 -> V_26 ) ;
F_90 ( V_2 -> V_137 ) ;
V_2 -> V_137 = NULL ;
if ( F_91 ( & V_2 -> V_26 ) )
return F_87 ( V_2 ) ;
return NULL ;
}
void
F_77 ( struct V_1 * V_2 )
{
F_43 ( L_18 , V_2 ) ;
do {
if ( F_79 ( & V_2 -> V_90 ) )
F_92 ( & V_148 ) ;
if ( ! F_91 ( & V_2 -> V_26 ) )
break;
V_2 = F_89 ( V_2 ) ;
} while ( V_2 != NULL );
}
struct V_1 * F_93 ( struct V_1 * V_43 ,
const struct V_67 * V_68 ,
T_3 V_150 )
{
struct V_65 args = {
. V_68 = V_68 ,
. V_83 = V_68 -> V_84 ,
. V_70 = V_150 ,
. V_95 = V_43 -> V_137 -> V_138 ,
} ;
struct V_1 * V_2 ;
int V_28 ;
V_2 = F_68 ( & args , V_43 ) ;
if ( F_18 ( V_2 ) )
goto V_59;
V_28 = F_64 ( V_2 ) ;
if ( V_28 != 0 ) {
F_65 ( V_2 ) ;
V_2 = F_19 ( V_28 ) ;
}
V_59:
return V_2 ;
}
void F_94 ( struct V_142 * V_151 )
{
struct V_1 * V_2 = V_151 -> V_152 ;
if ( V_2 != NULL ) {
F_4 ( & V_2 -> V_44 ) ;
F_8 ( & V_151 -> V_153 ) ;
F_6 ( & V_2 -> V_44 ) ;
V_151 -> V_152 = NULL ;
F_77 ( V_2 ) ;
}
}
static
void F_95 ( struct V_142 * V_151 , struct V_1 * V_2 )
{
if ( V_2 != NULL ) {
F_94 ( V_151 ) ;
V_151 -> V_152 = V_2 ;
F_58 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_99 )
V_151 -> V_144 |= V_154 ;
if ( V_2 -> V_155 )
V_151 -> V_144 |= V_156 ;
if ( F_96 () ) {
struct V_39 * V_40 ;
F_69 () ;
V_40 = F_71 ( V_2 -> V_45 ) ;
if ( V_40 -> V_157 )
V_151 -> V_144 |= V_158 ;
F_72 () ;
}
F_4 ( & V_2 -> V_44 ) ;
F_97 ( & V_151 -> V_153 , & V_2 -> V_90 ) ;
F_6 ( & V_2 -> V_44 ) ;
}
}
void F_98 ( struct V_142 * V_151 , struct V_1 * V_2 )
{
F_94 ( V_151 ) ;
F_95 ( V_151 , V_2 ) ;
}
static void
F_99 ( struct V_142 * V_151 , const struct V_159 * V_160 )
{
if ( V_160 != NULL ) {
V_151 -> V_161 . V_162 = V_160 -> V_162 ;
V_151 -> V_161 . V_163 = V_160 -> V_163 ;
V_151 -> V_161 . V_164 = V_160 -> V_164 ;
if ( V_160 -> V_165 != NULL )
V_151 -> V_161 . V_165 = F_100 ( V_160 -> V_165 ) ;
}
}
static void
F_101 ( struct V_142 * V_151 , void * V_166 )
{
}
struct V_142 * F_102 ( const struct V_167 * V_168 )
{
struct V_142 * V_151 ;
V_151 = F_103 ( V_168 ) ;
if ( F_18 ( V_151 ) )
goto V_59;
F_95 ( V_151 , V_168 -> V_169 ) ;
F_99 ( V_151 , V_168 -> V_159 ) ;
if ( V_151 -> V_170 == NULL )
F_104 ( V_151 ) ;
F_58 ( & V_151 -> V_171 ) ;
F_105 ( V_151 ) ;
V_59:
return V_151 ;
}
int F_106 ( struct V_1 * V_2 , const struct V_159 * V_160 , int V_97 )
{
struct V_142 * V_151 ;
struct V_167 V_168 = {
. V_169 = V_2 ,
. V_159 = V_160 ,
. V_172 = & V_173 ,
. V_97 = V_97 ,
} ;
int V_174 ;
F_107 ( V_97 & V_175 ) ;
if ( V_97 & V_175 ) {
F_108 ( V_168 . V_172 ,
V_168 . V_176 ) ;
return - V_73 ;
}
V_151 = F_102 ( & V_168 ) ;
if ( F_18 ( V_151 ) )
return F_21 ( V_151 ) ;
V_174 = V_151 -> V_177 ;
F_109 ( V_151 ) ;
return V_174 ;
}
int
F_110 ( struct V_1 * V_2 , const struct V_159 * V_160 , int V_97 ,
const struct V_178 * V_179 , void * V_166 )
{
struct V_142 * V_151 ;
struct V_167 V_168 = {
. V_169 = V_2 ,
. V_159 = V_160 ,
. V_172 = V_179 ,
. V_176 = V_166 ,
. V_97 = V_97 | V_175 ,
} ;
V_151 = F_102 ( & V_168 ) ;
if ( F_18 ( V_151 ) )
return F_21 ( V_151 ) ;
F_109 ( V_151 ) ;
return 0 ;
}
struct V_142 * F_111 ( struct V_180 * V_181 ,
const struct V_178 * V_179 )
{
struct V_142 * V_151 ;
struct V_182 * V_183 = & V_181 -> V_184 ;
struct V_167 V_168 = {
. V_172 = V_179 ,
} ;
F_43 ( L_19 , V_181 ) ;
V_151 = F_103 ( & V_168 ) ;
if ( F_18 ( V_151 ) ) {
F_112 ( V_181 ) ;
goto V_59;
}
V_151 -> V_185 = V_181 ;
V_183 -> V_186 = V_183 -> V_187 [ 0 ] . V_188 + V_183 -> V_189 +
V_183 -> V_190 [ 0 ] . V_188 ;
V_151 -> V_170 = V_191 ;
F_58 ( & V_151 -> V_171 ) ;
F_107 ( F_25 ( & V_151 -> V_171 ) != 2 ) ;
F_105 ( V_151 ) ;
V_59:
F_43 ( L_20 , V_151 ) ;
return V_151 ;
}
void
F_104 ( struct V_142 * V_151 )
{
V_151 -> V_170 = V_192 ;
}
T_4 F_113 ( struct V_1 * V_2 , struct V_193 * V_194 , T_4 V_195 )
{
T_4 V_196 ;
struct V_39 * V_40 ;
F_69 () ;
V_40 = F_71 ( V_2 -> V_45 ) ;
V_196 = V_40 -> V_114 ;
if ( V_196 > V_195 )
V_196 = V_195 ;
memcpy ( V_194 , & V_40 -> V_197 , V_196 ) ;
F_72 () ;
return V_196 ;
}
const char * F_114 ( struct V_1 * V_2 ,
enum V_198 V_199 )
{
struct V_39 * V_40 ;
V_40 = F_71 ( V_2 -> V_45 ) ;
if ( V_40 -> V_200 [ V_199 ] != NULL )
return V_40 -> V_200 [ V_199 ] ;
else
return L_21 ;
}
static int F_115 ( struct V_3 * V_3 , struct V_193 * V_201 , T_4 V_202 ,
struct V_193 * V_194 , int V_203 )
{
struct V_204 * V_205 ;
int V_28 ;
V_28 = F_116 ( V_3 , V_201 -> V_126 ,
V_206 , V_207 , & V_205 , 1 ) ;
if ( V_28 < 0 ) {
F_43 ( L_22 , V_28 ) ;
goto V_59;
}
switch ( V_201 -> V_126 ) {
case V_129 :
V_28 = F_117 ( V_205 ,
(struct V_193 * ) & V_208 ,
sizeof( V_208 ) ) ;
break;
case V_132 :
V_28 = F_117 ( V_205 ,
(struct V_193 * ) & V_209 ,
sizeof( V_209 ) ) ;
break;
default:
V_28 = - V_210 ;
goto V_59;
}
if ( V_28 < 0 ) {
F_43 ( L_23 , V_28 ) ;
goto V_211;
}
V_28 = F_118 ( V_205 , V_201 , V_202 , 0 ) ;
if ( V_28 < 0 ) {
F_43 ( L_24 , V_28 ) ;
goto V_211;
}
V_28 = F_119 ( V_205 , V_194 , & V_203 ) ;
if ( V_28 < 0 ) {
F_43 ( L_25 , V_28 ) ;
goto V_211;
}
V_28 = 0 ;
if ( V_194 -> V_126 == V_132 ) {
struct V_124 * V_125 = (struct V_124 * ) V_194 ;
V_125 -> V_212 = 0 ;
}
F_43 ( L_26 , V_31 ) ;
V_211:
F_120 ( V_205 ) ;
V_59:
return V_28 ;
}
static int F_121 ( int V_213 , struct V_193 * V_194 , T_4 V_203 )
{
switch ( V_213 ) {
case V_129 :
if ( V_203 < sizeof( V_208 ) )
return - V_73 ;
memcpy ( V_194 , & V_208 ,
sizeof( V_208 ) ) ;
break;
case V_132 :
if ( V_203 < sizeof( V_209 ) )
return - V_73 ;
memcpy ( V_194 , & V_209 ,
sizeof( V_209 ) ) ;
default:
F_43 ( L_27 ,
V_31 ) ;
return - V_210 ;
}
F_43 ( L_28 , V_31 ) ;
return 0 ;
}
int F_122 ( struct V_1 * V_2 , struct V_193 * V_194 , T_4 V_203 )
{
struct V_214 V_113 ;
struct V_193 * V_201 = (struct V_193 * ) & V_113 ;
struct V_39 * V_40 ;
struct V_3 * V_3 ;
T_4 V_202 ;
int V_28 ;
F_69 () ;
V_40 = F_71 ( V_2 -> V_45 ) ;
V_202 = V_40 -> V_114 ;
memcpy ( V_201 , & V_40 -> V_197 , V_202 ) ;
V_3 = F_123 ( V_40 -> V_215 ) ;
F_72 () ;
F_124 ( V_201 , 0 ) ;
V_28 = F_115 ( V_3 , V_201 , V_202 , V_194 , V_203 ) ;
F_125 ( V_3 ) ;
if ( V_28 != 0 )
return F_121 ( V_201 -> V_126 , V_194 , V_203 ) ;
return 0 ;
}
void
F_126 ( struct V_1 * V_2 , unsigned int V_216 , unsigned int V_217 )
{
struct V_39 * V_40 ;
F_69 () ;
V_40 = F_71 ( V_2 -> V_45 ) ;
if ( V_40 -> V_218 -> V_219 )
V_40 -> V_218 -> V_219 ( V_40 , V_216 , V_217 ) ;
F_72 () ;
}
int F_127 ( struct V_1 * V_2 )
{
int V_109 ;
F_69 () ;
V_109 = F_71 ( V_2 -> V_45 ) -> V_220 ;
F_72 () ;
return V_109 ;
}
struct V_3 * F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_221 ;
F_69 () ;
V_221 = F_71 ( V_2 -> V_45 ) -> V_215 ;
F_72 () ;
return V_221 ;
}
T_4 F_128 ( struct V_1 * V_2 )
{
T_4 V_221 ;
F_69 () ;
V_221 = F_71 ( V_2 -> V_45 ) -> V_222 ;
F_72 () ;
return V_221 ;
}
unsigned long F_129 ( struct V_1 * V_2 )
{
unsigned long V_221 ;
F_69 () ;
V_221 = F_71 ( V_2 -> V_45 ) -> V_42 -> V_94 ;
F_72 () ;
return V_221 ;
}
void F_130 ( struct V_1 * V_2 )
{
if ( V_2 -> V_46 ) {
F_69 () ;
F_131 ( F_71 ( V_2 -> V_45 ) ) ;
F_72 () ;
}
}
int
F_132 ( struct V_142 * V_151 )
{
if ( F_133 ( V_151 ) )
return 0 ;
V_151 -> V_170 = V_192 ;
V_151 -> V_177 = 0 ;
if ( V_151 -> V_179 -> V_223 != NULL )
V_151 -> V_170 = V_224 ;
return 1 ;
}
int
F_134 ( struct V_142 * V_151 )
{
if ( F_133 ( V_151 ) )
return 0 ;
V_151 -> V_170 = V_192 ;
V_151 -> V_177 = 0 ;
return 1 ;
}
static const char * F_135 ( const struct V_142 * V_151 )
{
const struct V_225 * V_226 = V_151 -> V_161 . V_162 ;
if ( V_226 ) {
if ( V_226 -> V_227 )
return V_226 -> V_227 ;
else
return L_29 ;
} else
return L_30 ;
}
static void
V_192 ( struct V_142 * V_151 )
{
struct V_1 * V_2 = V_151 -> V_152 ;
F_43 ( L_31 , V_151 -> V_228 ,
V_2 -> V_16 -> V_18 , V_2 -> V_85 ,
F_135 ( V_151 ) ,
( F_136 ( V_151 ) ? L_32 : L_33 ) ) ;
V_151 -> V_161 . V_162 -> V_229 ++ ;
V_2 -> V_86 -> V_230 ++ ;
V_151 -> V_170 = V_231 ;
}
static void
V_231 ( struct V_142 * V_151 )
{
F_137 ( V_151 ) ;
V_151 -> V_177 = 0 ;
V_151 -> V_170 = V_232 ;
F_138 ( V_151 ) ;
}
static void
V_232 ( struct V_142 * V_151 )
{
int V_174 = V_151 -> V_177 ;
F_137 ( V_151 ) ;
V_151 -> V_177 = 0 ;
if ( V_174 >= 0 ) {
if ( V_151 -> V_185 ) {
V_151 -> V_170 = V_233 ;
return;
}
F_20 ( V_30 L_34 ,
V_31 , V_174 ) ;
F_81 ( V_151 , - V_146 ) ;
return;
}
if ( V_151 -> V_185 ) {
F_20 ( V_30 L_35 ,
V_31 , V_174 ) ;
F_139 ( V_151 ) ;
}
switch ( V_174 ) {
case - V_76 :
F_140 ( V_151 , V_149 >> 2 ) ;
case - V_234 :
V_151 -> V_170 = V_235 ;
return;
case - V_146 :
break;
default:
F_20 ( V_30 L_36 ,
V_31 , V_174 ) ;
break;
}
F_81 ( V_151 , V_174 ) ;
}
static void
V_235 ( struct V_142 * V_151 )
{
F_137 ( V_151 ) ;
V_151 -> V_177 = 0 ;
V_151 -> V_170 = V_232 ;
F_141 ( V_151 ) ;
}
static void
V_233 ( struct V_142 * V_151 )
{
F_137 ( V_151 ) ;
V_151 -> V_170 = V_236 ;
V_151 -> V_177 = 0 ;
V_151 -> V_152 -> V_86 -> V_237 ++ ;
F_142 ( V_151 ) ;
}
static void
V_236 ( struct V_142 * V_151 )
{
int V_174 = V_151 -> V_177 ;
F_137 ( V_151 ) ;
V_151 -> V_177 = 0 ;
V_151 -> V_170 = V_233 ;
switch ( V_174 ) {
case 0 :
if ( F_143 ( V_151 ) ) {
V_151 -> V_170 = V_238 ;
return;
}
case - V_239 :
F_140 ( V_151 , 3 * V_149 ) ;
case - V_234 :
V_174 = - V_240 ;
case - V_241 :
if ( ! V_151 -> V_242 )
break;
V_151 -> V_242 -- ;
F_43 ( L_37 ,
V_151 -> V_228 , V_31 ) ;
return;
}
F_43 ( L_38 ,
V_151 -> V_228 , V_31 , V_174 ) ;
F_81 ( V_151 , V_174 ) ;
}
static void
V_238 ( struct V_142 * V_151 )
{
unsigned int V_243 = V_151 -> V_185 -> V_244 -> V_245 -> V_246 ;
struct V_180 * V_181 = V_151 -> V_185 ;
struct V_39 * V_40 = V_181 -> V_247 ;
struct V_225 * V_226 = V_151 -> V_161 . V_162 ;
F_137 ( V_151 ) ;
V_151 -> V_177 = 0 ;
V_151 -> V_170 = V_248 ;
if ( V_181 -> V_249 )
return;
if ( V_226 -> V_250 != 0 ) {
F_144 ( V_226 -> V_251 == 0 ) ;
if ( V_226 -> V_252 != NULL )
F_144 ( V_226 -> V_253 == 0 ) ;
}
V_181 -> V_254 = V_255 + ( V_243 << 1 ) + V_226 -> V_251 ;
V_181 -> V_254 <<= 2 ;
V_181 -> V_256 = V_257 + V_243 + V_226 -> V_253 ;
V_181 -> V_256 <<= 2 ;
V_181 -> V_249 = V_40 -> V_218 -> V_258 ( V_151 ,
V_181 -> V_254 + V_181 -> V_256 ) ;
if ( V_181 -> V_249 != NULL )
return;
F_43 ( L_39 , V_151 -> V_228 ) ;
if ( F_136 ( V_151 ) || ! F_145 ( V_259 ) ) {
V_151 -> V_170 = V_238 ;
F_140 ( V_151 , V_149 >> 4 ) ;
return;
}
F_81 ( V_151 , - V_260 ) ;
}
static inline int
F_146 ( struct V_142 * V_151 )
{
return V_151 -> V_185 -> V_184 . V_186 == 0 ;
}
static inline void
F_147 ( struct V_142 * V_151 )
{
V_151 -> V_185 -> V_184 . V_186 = 0 ;
V_151 -> V_185 -> V_261 = 0 ;
}
static inline void
F_148 ( struct V_182 * V_194 , void * V_262 , T_4 V_186 )
{
V_194 -> V_187 [ 0 ] . V_263 = V_262 ;
V_194 -> V_187 [ 0 ] . V_188 = V_186 ;
V_194 -> V_190 [ 0 ] . V_188 = 0 ;
V_194 -> V_189 = 0 ;
V_194 -> V_97 = 0 ;
V_194 -> V_186 = 0 ;
V_194 -> V_203 = V_186 ;
}
static void
F_149 ( struct V_142 * V_151 )
{
struct V_180 * V_181 = V_151 -> V_185 ;
T_5 V_264 ;
T_6 * V_265 ;
F_137 ( V_151 ) ;
F_148 ( & V_181 -> V_184 ,
V_181 -> V_249 ,
V_181 -> V_254 ) ;
F_148 ( & V_181 -> V_266 ,
( char * ) V_181 -> V_249 + V_181 -> V_254 ,
V_181 -> V_256 ) ;
V_265 = F_150 ( V_151 ) ;
if ( V_265 == NULL ) {
F_20 ( V_21 L_40 ) ;
F_81 ( V_151 , - V_146 ) ;
return;
}
V_264 = V_151 -> V_161 . V_162 -> V_267 ;
if ( V_264 == NULL )
return;
V_151 -> V_177 = F_151 ( V_151 , V_264 , V_181 , V_265 ,
V_151 -> V_161 . V_163 ) ;
}
static void
V_248 ( struct V_142 * V_151 )
{
struct V_39 * V_40 = V_151 -> V_185 -> V_247 ;
F_137 ( V_151 ) ;
V_151 -> V_170 = V_268 ;
if ( ! F_38 ( V_40 ) ) {
V_151 -> V_170 = V_269 ;
V_151 -> V_270 = V_40 -> V_271 ;
V_40 -> V_218 -> V_272 ( V_151 ) ;
}
}
static void
V_269 ( struct V_142 * V_151 )
{
int V_174 = - V_146 ;
if ( V_151 -> V_177 >= 0 ) {
F_137 ( V_151 ) ;
V_151 -> V_177 = 0 ;
V_151 -> V_170 = V_268 ;
return;
}
F_152 ( V_151 ) ;
switch ( V_151 -> V_177 ) {
case - V_76 :
F_43 ( L_41 , V_151 -> V_228 ) ;
F_140 ( V_151 , V_149 >> 2 ) ;
goto V_273;
case - V_240 :
F_43 ( L_42
L_43 , V_151 -> V_228 ) ;
if ( V_151 -> V_161 . V_162 -> V_250 == 0 ) {
V_174 = - V_274 ;
break;
}
if ( V_151 -> V_275 == 0 )
break;
V_151 -> V_275 -- ;
F_140 ( V_151 , 3 * V_149 ) ;
goto V_273;
case - V_239 :
F_43 ( L_44 ,
V_151 -> V_228 ) ;
goto V_273;
case - V_276 :
F_43 ( L_45 ,
V_151 -> V_228 ) ;
break;
case - V_277 :
F_43 ( L_46 ,
V_151 -> V_228 ) ;
goto V_273;
case - V_278 :
case - V_279 :
case - V_280 :
case - V_281 :
case - V_282 :
case - V_283 :
case - V_284 :
case - V_285 :
F_43 ( L_47 ,
V_151 -> V_228 , V_151 -> V_177 ) ;
if ( ! F_153 ( V_151 ) ) {
F_140 ( V_151 , 5 * V_149 ) ;
goto V_273;
}
V_174 = V_151 -> V_177 ;
break;
default:
F_43 ( L_48 ,
V_151 -> V_228 , - V_151 -> V_177 ) ;
}
F_81 ( V_151 , V_174 ) ;
return;
V_273:
V_151 -> V_177 = 0 ;
V_151 -> V_170 = V_286 ;
}
static void
V_268 ( struct V_142 * V_151 )
{
struct V_39 * V_40 = V_151 -> V_185 -> V_247 ;
F_43 ( L_49 ,
V_151 -> V_228 , V_40 ,
( F_154 ( V_40 ) ? L_50 : L_51 ) ) ;
V_151 -> V_170 = V_287 ;
if ( ! F_154 ( V_40 ) ) {
V_151 -> V_170 = V_288 ;
if ( V_151 -> V_177 < 0 )
return;
if ( V_151 -> V_144 & V_289 ) {
F_81 ( V_151 , - V_281 ) ;
return;
}
F_155 ( V_151 ) ;
}
}
static void
V_288 ( struct V_142 * V_151 )
{
struct V_1 * V_2 = V_151 -> V_152 ;
int V_174 = V_151 -> V_177 ;
F_137 ( V_151 ) ;
F_156 ( V_151 , V_174 ) ;
V_151 -> V_177 = 0 ;
switch ( V_174 ) {
case - V_278 :
case - V_279 :
case - V_280 :
case - V_284 :
case - V_283 :
if ( F_153 ( V_151 ) )
break;
F_140 ( V_151 , 3 * V_149 ) ;
case - V_234 :
case - V_239 :
V_151 -> V_170 = V_286 ;
return;
case 0 :
V_2 -> V_86 -> V_290 ++ ;
V_151 -> V_170 = V_287 ;
return;
}
F_81 ( V_151 , V_174 ) ;
}
static void
V_287 ( struct V_142 * V_151 )
{
int V_291 = F_157 ( V_151 ) ;
F_137 ( V_151 ) ;
V_151 -> V_170 = V_292 ;
if ( V_151 -> V_177 < 0 )
return;
if ( ! F_158 ( V_151 ) )
return;
V_151 -> V_170 = V_293 ;
if ( F_146 ( V_151 ) ) {
F_149 ( V_151 ) ;
if ( V_151 -> V_177 != 0 ) {
if ( V_151 -> V_177 == - V_234 )
F_140 ( V_151 , V_149 >> 4 ) ;
else
F_81 ( V_151 , V_151 -> V_177 ) ;
return;
}
}
F_159 ( V_151 ) ;
if ( V_151 -> V_177 < 0 )
return;
if ( V_291 )
V_151 -> V_152 -> V_86 -> V_294 ++ ;
V_293 ( V_151 ) ;
if ( F_160 ( V_151 ) )
return;
V_151 -> V_170 = V_295 ;
F_83 ( & V_151 -> V_185 -> V_247 -> V_296 , V_151 ) ;
}
static void
V_293 ( struct V_142 * V_151 )
{
V_151 -> V_170 = V_292 ;
if ( V_151 -> V_177 == 0 ) {
F_161 ( V_151 ) ;
F_147 ( V_151 ) ;
return;
}
switch ( V_151 -> V_177 ) {
case - V_234 :
break;
default:
F_137 ( V_151 ) ;
F_161 ( V_151 ) ;
F_147 ( V_151 ) ;
break;
case - V_278 :
case - V_282 :
case - V_283 :
case - V_284 :
if ( F_153 ( V_151 ) ) {
F_161 ( V_151 ) ;
F_81 ( V_151 , V_151 -> V_177 ) ;
break;
}
case - V_279 :
case - V_280 :
case - V_281 :
case - V_285 :
F_147 ( V_151 ) ;
}
}
static void
V_191 ( struct V_142 * V_151 )
{
struct V_180 * V_181 = V_151 -> V_185 ;
if ( ! F_158 ( V_151 ) ) {
V_151 -> V_177 = 0 ;
V_151 -> V_170 = V_191 ;
return;
}
V_151 -> V_170 = V_295 ;
if ( V_151 -> V_177 < 0 ) {
F_20 ( V_297 L_52
L_53 , V_151 -> V_177 ) ;
return;
}
F_159 ( V_151 ) ;
F_161 ( V_151 ) ;
F_137 ( V_151 ) ;
switch ( V_151 -> V_177 ) {
case 0 :
break;
case - V_282 :
case - V_283 :
case - V_284 :
case - V_239 :
F_20 ( V_297 L_52
L_53 , V_151 -> V_177 ) ;
F_162 ( V_181 -> V_247 ,
V_181 -> V_298 ) ;
break;
default:
F_107 ( V_151 -> V_177 == - V_234 ) ;
F_20 ( V_297 L_52
L_53 , V_151 -> V_177 ) ;
break;
}
F_83 ( & V_181 -> V_247 -> V_296 , V_151 ) ;
}
static void
V_292 ( struct V_142 * V_151 )
{
struct V_1 * V_2 = V_151 -> V_152 ;
struct V_180 * V_181 = V_151 -> V_185 ;
int V_174 ;
if ( V_181 -> V_299 > 0 && ! V_181 -> V_261 )
V_151 -> V_177 = V_181 -> V_299 ;
F_137 ( V_151 ) ;
V_174 = V_151 -> V_177 ;
if ( V_174 >= 0 ) {
V_151 -> V_170 = V_300 ;
return;
}
F_163 ( V_151 ) ;
V_151 -> V_177 = 0 ;
switch( V_174 ) {
case - V_282 :
case - V_283 :
case - V_284 :
if ( F_153 ( V_151 ) ) {
F_81 ( V_151 , V_174 ) ;
break;
}
F_140 ( V_151 , 3 * V_149 ) ;
case - V_239 :
V_151 -> V_170 = V_286 ;
if ( ! ( V_151 -> V_144 & V_156 )
&& V_151 -> V_152 -> V_103 )
F_162 ( V_181 -> V_247 ,
V_181 -> V_298 ) ;
break;
case - V_278 :
case - V_279 :
case - V_280 :
F_130 ( V_2 ) ;
F_140 ( V_151 , 3 * V_149 ) ;
case - V_285 :
case - V_281 :
V_151 -> V_170 = V_248 ;
break;
case - V_234 :
V_151 -> V_170 = V_287 ;
break;
case - V_146 :
F_81 ( V_151 , V_174 ) ;
break;
default:
if ( V_2 -> V_105 )
F_20 ( L_54 ,
V_2 -> V_16 -> V_18 , - V_174 ) ;
F_81 ( V_151 , V_174 ) ;
}
}
static void
V_286 ( struct V_142 * V_151 )
{
struct V_1 * V_2 = V_151 -> V_152 ;
if ( F_164 ( V_151 -> V_185 ) == 0 ) {
F_43 ( L_55 , V_151 -> V_228 ) ;
goto V_301;
}
F_43 ( L_56 , V_151 -> V_228 ) ;
V_151 -> V_302 ++ ;
if ( F_153 ( V_151 ) ) {
F_81 ( V_151 , - V_239 ) ;
return;
}
if ( F_165 ( V_151 ) ) {
if ( V_2 -> V_105 ) {
F_69 () ;
F_20 ( V_297 L_57 ,
V_2 -> V_16 -> V_18 ,
F_71 ( V_2 -> V_45 ) -> V_71 ) ;
F_72 () ;
}
if ( V_151 -> V_144 & V_303 )
F_81 ( V_151 , - V_239 ) ;
else
F_81 ( V_151 , - V_146 ) ;
return;
}
if ( ! ( V_151 -> V_144 & V_304 ) ) {
V_151 -> V_144 |= V_304 ;
if ( V_2 -> V_105 ) {
F_69 () ;
F_20 ( V_297 L_58 ,
V_2 -> V_16 -> V_18 ,
F_71 ( V_2 -> V_45 ) -> V_71 ) ;
F_72 () ;
}
}
F_130 ( V_2 ) ;
F_166 ( V_151 ) ;
V_301:
V_151 -> V_170 = V_248 ;
V_151 -> V_177 = 0 ;
}
static void
V_300 ( struct V_142 * V_151 )
{
struct V_1 * V_2 = V_151 -> V_152 ;
struct V_180 * V_181 = V_151 -> V_185 ;
T_7 V_305 = V_151 -> V_161 . V_162 -> V_252 ;
T_6 * V_265 ;
F_137 ( V_151 ) ;
if ( V_151 -> V_144 & V_304 ) {
if ( V_2 -> V_105 ) {
F_69 () ;
F_20 ( V_297 L_59 ,
V_2 -> V_16 -> V_18 ,
F_71 ( V_2 -> V_45 ) -> V_71 ) ;
F_72 () ;
}
V_151 -> V_144 &= ~ V_304 ;
}
F_167 () ;
V_181 -> V_266 . V_186 = V_181 -> V_306 . V_186 ;
F_168 ( memcmp ( & V_181 -> V_266 , & V_181 -> V_306 ,
sizeof( V_181 -> V_266 ) ) != 0 ) ;
if ( V_181 -> V_266 . V_186 < 12 ) {
if ( ! F_165 ( V_151 ) ) {
V_151 -> V_170 = V_248 ;
goto V_307;
}
F_43 ( L_60 ,
V_2 -> V_16 -> V_18 , V_151 -> V_177 ) ;
V_151 -> V_170 = V_286 ;
goto V_307;
}
V_265 = F_169 ( V_151 ) ;
if ( F_18 ( V_265 ) ) {
if ( V_265 == F_19 ( - V_234 ) )
goto V_307;
return;
}
V_151 -> V_170 = V_295 ;
if ( V_305 ) {
V_151 -> V_177 = F_170 ( V_151 , V_305 , V_181 , V_265 ,
V_151 -> V_161 . V_164 ) ;
}
F_43 ( L_61 , V_151 -> V_228 ,
V_151 -> V_177 ) ;
return;
V_307:
V_151 -> V_177 = 0 ;
if ( V_151 -> V_185 == V_181 ) {
V_181 -> V_299 = V_181 -> V_266 . V_186 = 0 ;
if ( V_151 -> V_152 -> V_103 )
F_162 ( V_181 -> V_247 ,
V_181 -> V_298 ) ;
}
}
static T_6 *
F_150 ( struct V_142 * V_151 )
{
struct V_1 * V_2 = V_151 -> V_152 ;
struct V_180 * V_181 = V_151 -> V_185 ;
T_6 * V_265 = V_181 -> V_308 [ 0 ] . V_263 ;
V_265 = F_171 ( V_181 -> V_247 , V_265 ) ;
* V_265 ++ = V_181 -> V_309 ;
* V_265 ++ = F_172 ( V_310 ) ;
* V_265 ++ = F_172 ( V_311 ) ;
* V_265 ++ = F_172 ( V_2 -> V_82 ) ;
* V_265 ++ = F_172 ( V_2 -> V_85 ) ;
* V_265 ++ = F_172 ( V_151 -> V_161 . V_162 -> V_250 ) ;
V_265 = F_173 ( V_151 , V_265 ) ;
V_181 -> V_312 = F_174 ( & V_181 -> V_308 [ 0 ] , V_265 ) ;
return V_265 ;
}
static T_6 *
F_169 ( struct V_142 * V_151 )
{
struct V_1 * V_2 = V_151 -> V_152 ;
struct V_313 * V_314 = & V_151 -> V_185 -> V_266 . V_187 [ 0 ] ;
int V_186 = V_151 -> V_185 -> V_266 . V_186 >> 2 ;
T_6 * V_265 = V_314 -> V_263 ;
T_3 V_315 ;
int error = - V_240 ;
if ( ( V_151 -> V_185 -> V_266 . V_186 & 3 ) != 0 ) {
F_43 ( L_62
L_63 , V_151 -> V_228 , V_31 ,
V_151 -> V_185 -> V_266 . V_186 ) ;
error = - V_146 ;
goto V_75;
}
if ( ( V_186 -= 3 ) < 0 )
goto V_316;
V_265 += 1 ;
if ( ( V_315 = F_175 ( * V_265 ++ ) ) != V_317 ) {
F_43 ( L_64 ,
V_151 -> V_228 , V_31 , V_315 ) ;
error = - V_146 ;
goto V_318;
}
if ( ( V_315 = F_175 ( * V_265 ++ ) ) != V_319 ) {
if ( -- V_186 < 0 )
goto V_316;
switch ( ( V_315 = F_175 ( * V_265 ++ ) ) ) {
case V_320 :
break;
case V_321 :
F_43 ( L_65 ,
V_151 -> V_228 , V_31 ) ;
error = - V_277 ;
goto V_75;
default:
F_43 ( L_66
L_67 ,
V_151 -> V_228 , V_31 , V_315 ) ;
error = - V_146 ;
goto V_75;
}
if ( -- V_186 < 0 )
goto V_316;
switch ( ( V_315 = F_175 ( * V_265 ++ ) ) ) {
case V_322 :
case V_323 :
case V_324 :
case V_325 :
if ( ! V_151 -> V_242 )
break;
V_151 -> V_242 -- ;
F_43 ( L_68 ,
V_151 -> V_228 , V_31 ) ;
F_166 ( V_151 ) ;
F_139 ( V_151 ) ;
V_151 -> V_170 = V_231 ;
goto V_307;
case V_326 :
case V_327 :
if ( ! V_151 -> V_328 )
break;
V_151 -> V_328 -- ;
F_43 ( L_69 ,
V_151 -> V_228 , V_31 ) ;
V_151 -> V_170 = V_248 ;
goto V_307;
case V_329 :
F_69 () ;
F_20 ( V_297 L_70
L_71 ,
F_71 ( V_2 -> V_45 ) -> V_71 ) ;
F_72 () ;
break;
default:
F_43 ( L_72 ,
V_151 -> V_228 , V_31 , V_315 ) ;
error = - V_146 ;
}
F_43 ( L_73 ,
V_151 -> V_228 , V_31 , V_315 ) ;
goto V_75;
}
V_265 = F_176 ( V_151 , V_265 ) ;
if ( F_18 ( V_265 ) ) {
error = F_21 ( V_265 ) ;
F_43 ( L_74 ,
V_151 -> V_228 , V_31 , error ) ;
goto V_318;
}
V_186 = V_265 - ( T_6 * ) V_314 -> V_263 - 1 ;
if ( V_186 < 0 )
goto V_316;
switch ( ( V_315 = F_175 ( * V_265 ++ ) ) ) {
case V_330 :
return V_265 ;
case V_331 :
F_85 ( L_75
L_76 , V_151 -> V_228 , V_31 ,
( unsigned int ) V_2 -> V_82 ,
F_71 ( V_2 -> V_45 ) -> V_71 ) ;
error = - V_276 ;
goto V_75;
case V_332 :
F_85 ( L_77
L_76 , V_151 -> V_228 , V_31 ,
( unsigned int ) V_2 -> V_82 ,
( unsigned int ) V_2 -> V_85 ,
F_71 ( V_2 -> V_45 ) -> V_71 ) ;
error = - V_277 ;
goto V_75;
case V_333 :
F_85 ( L_78
L_79 ,
V_151 -> V_228 , V_31 ,
F_135 ( V_151 ) ,
V_2 -> V_82 , V_2 -> V_85 ,
F_71 ( V_2 -> V_45 ) -> V_71 ) ;
error = - V_274 ;
goto V_75;
case V_334 :
F_43 ( L_80 ,
V_151 -> V_228 , V_31 ) ;
break;
default:
F_43 ( L_81 ,
V_151 -> V_228 , V_31 , V_315 ) ;
}
V_318:
V_2 -> V_86 -> V_335 ++ ;
if ( V_151 -> V_328 ) {
V_151 -> V_328 -- ;
F_43 ( L_82 ,
V_151 -> V_228 , V_31 ) ;
V_151 -> V_170 = V_248 ;
V_307:
return F_19 ( - V_234 ) ;
}
V_75:
F_81 ( V_151 , error ) ;
F_43 ( L_83 , V_151 -> V_228 ,
V_31 , error ) ;
return F_19 ( error ) ;
V_316:
F_43 ( L_84 , V_151 -> V_228 ,
V_31 ) ;
goto V_318;
}
static void F_177 ( void * V_336 , struct V_337 * V_338 , void * V_339 )
{
}
static int F_178 ( void * V_336 , struct V_337 * V_338 , void * V_339 )
{
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_159 V_160 = {
. V_162 = & V_340 ,
} ;
int V_28 ;
V_160 . V_165 = V_341 . V_342 ( NULL , NULL , 0 ) ;
V_28 = F_106 ( V_2 , & V_160 , V_154 | V_343 ) ;
F_179 ( V_160 . V_165 ) ;
return V_28 ;
}
struct V_142 * F_180 ( struct V_1 * V_2 , struct V_165 * V_344 , int V_97 )
{
struct V_159 V_160 = {
. V_162 = & V_340 ,
. V_165 = V_344 ,
} ;
struct V_167 V_168 = {
. V_169 = V_2 ,
. V_159 = & V_160 ,
. V_172 = & V_173 ,
. V_97 = V_97 ,
} ;
return F_102 ( & V_168 ) ;
}
static void F_181 ( void )
{
F_20 ( V_21 L_85
L_86 ) ;
}
static void F_182 ( const struct V_1 * V_2 ,
const struct V_142 * V_151 )
{
const char * V_345 = L_87 ;
if ( F_82 ( V_151 ) )
V_345 = F_183 ( V_151 -> V_147 ) ;
F_20 ( V_21 L_88 ,
V_151 -> V_228 , V_151 -> V_144 , V_151 -> V_177 ,
V_2 , V_151 -> V_185 , V_151 -> V_270 , V_151 -> V_179 ,
V_2 -> V_16 -> V_18 , V_2 -> V_85 , F_135 ( V_151 ) ,
V_151 -> V_170 , V_345 ) ;
}
void F_184 ( struct V_3 * V_3 )
{
struct V_1 * V_2 ;
struct V_142 * V_151 ;
int V_346 = 0 ;
struct V_4 * V_5 = F_3 ( V_3 , V_6 ) ;
F_4 ( & V_5 -> V_7 ) ;
F_29 (clnt, &sn->all_clients, cl_clients) {
F_4 ( & V_2 -> V_44 ) ;
F_29 (task, &clnt->cl_tasks, tk_task) {
if ( ! V_346 ) {
F_181 () ;
V_346 ++ ;
}
F_182 ( V_2 , V_151 ) ;
}
F_6 ( & V_2 -> V_44 ) ;
}
F_6 ( & V_5 -> V_7 ) ;
}
