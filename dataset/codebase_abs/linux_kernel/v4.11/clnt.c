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
switch ( V_22 ) {
case V_23 :
V_12 = F_14 ( V_13 , V_2 ) ;
if ( ! V_12 )
return - V_28 ;
if ( F_18 ( V_12 ) )
return F_21 ( V_12 ) ;
break;
case V_27 :
F_9 ( V_2 ) ;
break;
default:
F_20 ( V_29 L_5 , V_30 , V_22 ) ;
return - V_31 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , unsigned long V_22 ,
struct V_10 * V_13 )
{
int error = 0 ;
for (; ; V_2 = V_2 -> V_32 ) {
if ( ! F_24 ( V_2 , V_22 ) )
error = F_26 ( V_2 , V_22 , V_13 ) ;
if ( error || V_2 == V_2 -> V_32 )
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
static int F_30 ( struct V_33 * V_34 , unsigned long V_22 ,
void * V_35 )
{
struct V_10 * V_13 = V_35 ;
struct V_1 * V_2 ;
int error = 0 ;
while ( ( V_2 = F_28 ( V_13 -> V_36 , V_22 ) ) ) {
error = F_27 ( V_2 , V_22 , V_13 ) ;
if ( error )
break;
}
return error ;
}
int F_31 ( void )
{
return F_32 ( & V_37 ) ;
}
void F_33 ( void )
{
return F_34 ( & V_37 ) ;
}
static struct V_38 * F_35 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
const struct V_40 * V_41 )
{
struct V_38 * V_42 ;
F_4 ( & V_2 -> V_43 ) ;
V_42 = F_36 ( V_2 -> V_44 ,
F_37 ( & V_2 -> V_43 ) ) ;
if ( ! F_38 ( V_39 ) )
V_2 -> V_45 = 1 ;
V_2 -> V_46 = V_41 ;
F_39 ( V_2 -> V_44 , V_39 ) ;
F_6 ( & V_2 -> V_43 ) ;
return V_42 ;
}
static void F_40 ( struct V_1 * V_2 , const char * V_47 )
{
V_2 -> V_48 = F_41 ( V_2 -> V_49 ,
V_47 , sizeof( V_2 -> V_49 ) ) ;
}
static int F_42 ( struct V_1 * V_2 ,
T_2 V_50 ,
const char * V_51 )
{
struct V_52 V_53 = {
. V_50 = V_50 ,
. V_54 = V_51 ,
} ;
struct V_55 * V_56 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_10 * V_11 ;
int V_57 ;
F_43 ( V_2 ) ;
V_11 = F_12 ( V_3 ) ;
if ( V_11 ) {
V_57 = F_23 ( V_11 , V_2 ) ;
if ( V_57 )
goto V_58;
}
F_1 ( V_2 ) ;
if ( V_11 )
F_13 ( V_3 ) ;
V_56 = F_44 ( & V_53 , V_2 ) ;
if ( F_18 ( V_56 ) ) {
F_45 ( L_6 ,
V_50 ) ;
V_57 = F_21 ( V_56 ) ;
goto V_59;
}
return 0 ;
V_59:
V_11 = F_12 ( V_3 ) ;
F_7 ( V_2 ) ;
F_9 ( V_2 ) ;
V_58:
if ( V_11 )
F_13 ( V_3 ) ;
F_46 ( V_2 ) ;
return V_57 ;
}
void F_47 ( void )
{
F_48 ( & V_60 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_61 ;
V_61 = F_50 ( & V_60 , 0 , 0 , V_62 ) ;
if ( V_61 < 0 )
return V_61 ;
V_2 -> V_63 = V_61 ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_52 ( & V_60 , V_2 -> V_63 ) ;
}
static struct V_1 * F_53 ( const struct V_64 * args ,
struct V_65 * V_66 ,
struct V_38 * V_39 ,
struct V_1 * V_67 )
{
const struct V_68 * V_69 = args -> V_69 ;
const struct V_70 * V_71 ;
struct V_1 * V_2 = NULL ;
const struct V_40 * V_41 ;
const char * V_47 = args -> V_47 ;
int V_57 ;
F_45 ( L_7 ,
V_69 -> V_18 , args -> V_72 , V_39 ) ;
V_57 = F_54 () ;
if ( V_57 )
goto V_73;
V_57 = - V_74 ;
if ( args -> V_71 >= V_69 -> V_75 )
goto V_76;
V_71 = V_69 -> V_71 [ args -> V_71 ] ;
if ( V_71 == NULL )
goto V_76;
V_57 = - V_77 ;
V_2 = F_55 ( sizeof( * V_2 ) , V_62 ) ;
if ( ! V_2 )
goto V_76;
V_2 -> V_32 = V_67 ? : V_2 ;
V_57 = F_49 ( V_2 ) ;
if ( V_57 )
goto V_78;
V_2 -> V_79 = V_71 -> V_80 ;
V_2 -> V_81 = V_71 -> V_82 ;
V_2 -> V_83 = args -> V_84 ? : V_69 -> V_85 ;
V_2 -> V_86 = V_71 -> V_85 ;
V_2 -> V_87 = V_69 -> V_88 ;
V_2 -> V_89 = F_56 ( V_2 ) ;
F_57 ( & V_2 -> V_24 ) ;
V_57 = - V_77 ;
if ( V_2 -> V_89 == NULL )
goto V_90;
V_2 -> V_16 = V_69 ;
F_58 ( & V_2 -> V_91 ) ;
F_59 ( & V_2 -> V_43 ) ;
V_41 = V_39 -> V_41 ;
if ( args -> V_41 != NULL ) {
memcpy ( & V_2 -> V_92 , args -> V_41 ,
sizeof( V_2 -> V_92 ) ) ;
V_41 = & V_2 -> V_92 ;
}
F_35 ( V_2 , V_39 , V_41 ) ;
F_60 ( & V_2 -> V_93 , V_66 ) ;
F_61 ( V_66 ) ;
V_2 -> V_94 = & V_2 -> V_95 ;
F_62 ( & V_2 -> V_95 , V_2 -> V_46 -> V_96 ) ;
F_63 ( & V_2 -> V_26 , 1 ) ;
if ( V_47 == NULL )
V_47 = F_64 () -> V_47 ;
F_40 ( V_2 , V_47 ) ;
V_57 = F_42 ( V_2 , args -> V_97 , args -> V_51 ) ;
if ( V_57 )
goto V_98;
if ( V_67 )
F_65 ( & V_67 -> V_26 ) ;
return V_2 ;
V_98:
F_66 ( V_2 -> V_89 ) ;
V_90:
F_51 ( V_2 ) ;
V_78:
F_67 ( V_2 ) ;
V_76:
F_68 () ;
V_73:
F_61 ( V_66 ) ;
F_69 ( V_39 ) ;
return F_19 ( V_57 ) ;
}
static struct V_1 * F_70 ( struct V_64 * args ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = NULL ;
struct V_65 * V_66 ;
if ( args -> V_99 && args -> V_99 -> V_100 ) {
F_71 ( ! ( args -> V_101 & V_102 ) ) ;
V_66 = args -> V_99 -> V_100 ;
F_72 ( V_66 ) ;
} else {
V_66 = F_73 ( V_39 , V_62 ) ;
if ( V_66 == NULL ) {
F_69 ( V_39 ) ;
return F_19 ( - V_77 ) ;
}
if ( V_39 -> V_99 ) {
F_72 ( V_66 ) ;
V_39 -> V_99 -> V_100 = V_66 ;
}
}
V_2 = F_53 ( args , V_66 , V_39 , NULL ) ;
if ( F_18 ( V_2 ) )
return V_2 ;
if ( ! ( args -> V_103 & V_104 ) ) {
int V_57 = F_74 ( V_2 ) ;
if ( V_57 != 0 ) {
F_75 ( V_2 ) ;
return F_19 ( V_57 ) ;
}
}
V_2 -> V_105 = 1 ;
if ( args -> V_103 & V_106 )
V_2 -> V_105 = 0 ;
if ( args -> V_103 & V_107 )
V_2 -> V_45 = 1 ;
if ( args -> V_103 & V_108 )
V_2 -> V_109 = 1 ;
if ( args -> V_103 & V_110 )
V_2 -> V_111 = 1 ;
if ( ! ( args -> V_103 & V_112 ) )
V_2 -> V_113 = 1 ;
return V_2 ;
}
struct V_1 * F_76 ( struct V_64 * args )
{
struct V_38 * V_39 ;
struct V_114 V_115 = {
. V_3 = args -> V_3 ,
. V_116 = args -> V_101 ,
. V_117 = args -> V_118 ,
. V_119 = args -> V_120 ,
. V_121 = args -> V_122 ,
. V_72 = args -> V_72 ,
. V_99 = args -> V_99 ,
} ;
char V_72 [ 48 ] ;
if ( args -> V_99 ) {
F_71 ( ! ( args -> V_101 & V_102 ) ) ;
V_39 = args -> V_99 -> V_123 ;
if ( V_39 ) {
F_77 ( V_39 ) ;
return F_70 ( args , V_39 ) ;
}
}
if ( args -> V_103 & V_124 )
V_115 . V_103 |= V_125 ;
if ( args -> V_103 & V_126 )
V_115 . V_103 |= V_127 ;
if ( V_115 . V_72 == NULL ) {
struct V_128 * V_129 =
(struct V_128 * ) args -> V_120 ;
struct V_130 * sin =
(struct V_130 * ) args -> V_120 ;
struct V_131 * V_132 =
(struct V_131 * ) args -> V_120 ;
V_72 [ 0 ] = '\0' ;
switch ( args -> V_120 -> V_133 ) {
case V_134 :
snprintf ( V_72 , sizeof( V_72 ) , L_8 ,
V_129 -> V_135 ) ;
break;
case V_136 :
snprintf ( V_72 , sizeof( V_72 ) , L_9 ,
& sin -> V_137 . V_138 ) ;
break;
case V_139 :
snprintf ( V_72 , sizeof( V_72 ) , L_10 ,
& V_132 -> V_140 ) ;
break;
default:
return F_19 ( - V_74 ) ;
}
V_115 . V_72 = V_72 ;
}
V_39 = F_78 ( & V_115 ) ;
if ( F_18 ( V_39 ) )
return (struct V_1 * ) V_39 ;
V_39 -> V_141 = 1 ;
if ( args -> V_103 & V_142 )
V_39 -> V_141 = 0 ;
return F_70 ( args , V_39 ) ;
}
static struct V_1 * F_79 ( struct V_64 * args ,
struct V_1 * V_2 )
{
struct V_65 * V_66 ;
struct V_38 * V_39 ;
struct V_1 * V_143 ;
int V_57 ;
V_57 = - V_77 ;
F_80 () ;
V_39 = F_77 ( F_81 ( V_2 -> V_44 ) ) ;
V_66 = F_72 ( F_81 ( V_2 -> V_93 . V_144 ) ) ;
F_82 () ;
if ( V_39 == NULL || V_66 == NULL ) {
F_69 ( V_39 ) ;
F_61 ( V_66 ) ;
goto V_76;
}
args -> V_72 = V_39 -> V_72 ;
args -> V_47 = V_2 -> V_49 ;
V_143 = F_53 ( args , V_66 , V_39 , V_2 ) ;
if ( F_18 ( V_143 ) ) {
V_57 = F_21 ( V_143 ) ;
goto V_76;
}
V_143 -> V_45 = 0 ;
V_143 -> V_105 = V_2 -> V_105 ;
V_143 -> V_109 = V_2 -> V_109 ;
V_143 -> V_111 = V_2 -> V_111 ;
V_143 -> V_113 = V_2 -> V_113 ;
return V_143 ;
V_76:
F_45 ( L_11 , V_30 , V_57 ) ;
return F_19 ( V_57 ) ;
}
struct V_1 * F_83 ( struct V_1 * V_2 )
{
struct V_64 args = {
. V_69 = V_2 -> V_16 ,
. V_84 = V_2 -> V_83 ,
. V_71 = V_2 -> V_86 ,
. V_97 = V_2 -> V_145 -> V_146 ,
} ;
return F_79 ( & args , V_2 ) ;
}
struct V_1 *
F_84 ( struct V_1 * V_2 , T_2 V_147 )
{
struct V_64 args = {
. V_69 = V_2 -> V_16 ,
. V_84 = V_2 -> V_83 ,
. V_71 = V_2 -> V_86 ,
. V_97 = V_147 ,
} ;
return F_79 ( & args , V_2 ) ;
}
int F_85 ( struct V_1 * V_2 ,
struct V_114 * args ,
const struct V_40 * V_41 )
{
const struct V_40 * V_148 ;
T_2 V_50 ;
struct V_65 * V_66 , * V_149 ;
struct V_38 * V_39 , * V_42 ;
struct V_1 * V_67 ;
int V_57 ;
V_39 = F_78 ( args ) ;
if ( F_18 ( V_39 ) ) {
F_45 ( L_12 ,
V_2 ) ;
return F_21 ( V_39 ) ;
}
V_66 = F_73 ( V_39 , V_62 ) ;
if ( V_66 == NULL ) {
F_69 ( V_39 ) ;
return - V_77 ;
}
V_50 = V_2 -> V_145 -> V_146 ;
V_148 = V_2 -> V_46 ;
V_42 = F_35 ( V_2 , V_39 , V_41 ) ;
V_149 = F_86 ( & V_2 -> V_93 , V_66 ) ;
F_7 ( V_2 ) ;
F_9 ( V_2 ) ;
F_46 ( V_2 ) ;
V_67 = V_2 -> V_32 ;
V_2 -> V_32 = V_2 ;
V_57 = F_42 ( V_2 , V_50 , NULL ) ;
if ( V_57 )
goto V_150;
F_87 () ;
if ( V_67 != V_2 )
F_88 ( V_67 ) ;
F_61 ( V_149 ) ;
F_69 ( V_42 ) ;
F_45 ( L_13 , V_2 ) ;
return 0 ;
V_150:
V_66 = F_86 ( & V_2 -> V_93 , V_149 ) ;
F_35 ( V_2 , V_42 , V_148 ) ;
V_2 -> V_32 = V_67 ;
F_42 ( V_2 , V_50 , NULL ) ;
F_61 ( V_66 ) ;
F_69 ( V_39 ) ;
F_45 ( L_14 , V_2 ) ;
return V_57 ;
}
static
int F_89 ( struct V_1 * V_2 , struct V_151 * V_152 )
{
struct V_65 * V_66 ;
F_80 () ;
V_66 = F_72 ( F_81 ( V_2 -> V_93 . V_144 ) ) ;
F_82 () ;
if ( V_66 == NULL )
return - V_153 ;
F_90 ( V_152 , V_66 ) ;
F_61 ( V_66 ) ;
return 0 ;
}
int F_91 ( struct V_1 * V_2 ,
int (* F_92)( struct V_1 * , struct V_38 * , void * ) ,
void * V_154 )
{
struct V_151 V_152 ;
int V_155 ;
V_155 = F_89 ( V_2 , & V_152 ) ;
if ( V_155 )
return V_155 ;
for (; ; ) {
struct V_38 * V_39 = F_93 ( & V_152 ) ;
if ( ! V_39 )
break;
V_155 = F_92 ( V_2 , V_39 , V_154 ) ;
F_69 ( V_39 ) ;
if ( V_155 < 0 )
break;
}
F_94 ( & V_152 ) ;
return V_155 ;
}
void F_95 ( struct V_1 * V_2 )
{
struct V_156 * V_157 ;
if ( F_96 ( & V_2 -> V_91 ) )
return;
F_45 ( L_15 , V_2 ) ;
F_4 ( & V_2 -> V_43 ) ;
F_29 (rovr, &clnt->cl_tasks, tk_task) {
if ( ! F_97 ( V_157 ) )
continue;
if ( ! ( V_157 -> V_158 & V_159 ) ) {
V_157 -> V_158 |= V_159 ;
F_98 ( V_157 , - V_160 ) ;
if ( F_99 ( V_157 ) )
F_100 ( V_157 -> V_161 ,
V_157 ) ;
}
}
F_6 ( & V_2 -> V_43 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
F_101 () ;
F_102 ( L_16 ,
V_2 -> V_16 -> V_18 ,
F_81 ( V_2 -> V_44 ) -> V_72 ) ;
while ( ! F_96 ( & V_2 -> V_91 ) ) {
F_95 ( V_2 ) ;
F_103 ( V_162 ,
F_96 ( & V_2 -> V_91 ) , 1 * V_163 ) ;
}
F_88 ( V_2 ) ;
}
static struct V_1 *
F_104 ( struct V_1 * V_2 )
{
struct V_1 * V_67 = NULL ;
F_102 ( L_17 ,
V_2 -> V_16 -> V_18 ,
F_81 ( V_2 -> V_44 ) -> V_72 ) ;
if ( V_2 -> V_32 != V_2 )
V_67 = V_2 -> V_32 ;
F_46 ( V_2 ) ;
F_11 ( V_2 ) ;
F_7 ( V_2 ) ;
F_66 ( V_2 -> V_89 ) ;
V_2 -> V_89 = NULL ;
F_69 ( F_105 ( V_2 -> V_44 ) ) ;
F_94 ( & V_2 -> V_93 ) ;
F_68 () ;
F_51 ( V_2 ) ;
F_67 ( V_2 ) ;
return V_67 ;
}
static struct V_1 *
F_106 ( struct V_1 * V_2 )
{
if ( V_2 -> V_145 == NULL )
return F_104 ( V_2 ) ;
F_65 ( & V_2 -> V_26 ) ;
F_107 ( V_2 -> V_145 ) ;
V_2 -> V_145 = NULL ;
if ( F_108 ( & V_2 -> V_26 ) )
return F_104 ( V_2 ) ;
return NULL ;
}
void
F_88 ( struct V_1 * V_2 )
{
F_45 ( L_18 , V_2 ) ;
do {
if ( F_96 ( & V_2 -> V_91 ) )
F_109 ( & V_162 ) ;
if ( ! F_108 ( & V_2 -> V_26 ) )
break;
V_2 = F_106 ( V_2 ) ;
} while ( V_2 != NULL );
}
struct V_1 * F_110 ( struct V_1 * V_42 ,
const struct V_68 * V_69 ,
T_3 V_164 )
{
struct V_64 args = {
. V_69 = V_69 ,
. V_84 = V_69 -> V_85 ,
. V_71 = V_164 ,
. V_97 = V_42 -> V_145 -> V_146 ,
} ;
struct V_1 * V_2 ;
int V_57 ;
V_2 = F_79 ( & args , V_42 ) ;
if ( F_18 ( V_2 ) )
goto V_58;
V_57 = F_74 ( V_2 ) ;
if ( V_57 != 0 ) {
F_75 ( V_2 ) ;
V_2 = F_19 ( V_57 ) ;
}
V_58:
return V_2 ;
}
void F_111 ( struct V_156 * V_165 )
{
struct V_1 * V_2 = V_165 -> V_166 ;
struct V_38 * V_39 = V_165 -> V_167 ;
if ( V_2 != NULL ) {
F_4 ( & V_2 -> V_43 ) ;
F_8 ( & V_165 -> V_168 ) ;
F_6 ( & V_2 -> V_43 ) ;
V_165 -> V_166 = NULL ;
F_88 ( V_2 ) ;
}
if ( V_39 != NULL ) {
V_165 -> V_167 = NULL ;
F_69 ( V_39 ) ;
}
}
static
void F_112 ( struct V_156 * V_165 , struct V_1 * V_2 )
{
if ( V_2 != NULL ) {
if ( V_165 -> V_167 == NULL )
V_165 -> V_167 = F_93 ( & V_2 -> V_93 ) ;
V_165 -> V_166 = V_2 ;
F_65 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_105 )
V_165 -> V_158 |= V_169 ;
if ( V_2 -> V_109 )
V_165 -> V_158 |= V_170 ;
if ( F_25 ( & V_2 -> V_171 ) )
V_165 -> V_158 |= V_172 ;
F_4 ( & V_2 -> V_43 ) ;
F_113 ( & V_165 -> V_168 , & V_2 -> V_91 ) ;
F_6 ( & V_2 -> V_43 ) ;
}
}
static void
F_114 ( struct V_156 * V_165 , const struct V_173 * V_174 )
{
if ( V_174 != NULL ) {
V_165 -> V_175 . V_176 = V_174 -> V_176 ;
V_165 -> V_175 . V_177 = V_174 -> V_177 ;
V_165 -> V_175 . V_178 = V_174 -> V_178 ;
if ( V_174 -> V_179 != NULL )
V_165 -> V_175 . V_179 = F_115 ( V_174 -> V_179 ) ;
}
}
static void
F_116 ( struct V_156 * V_165 , void * V_154 )
{
}
struct V_156 * F_117 ( const struct V_180 * V_181 )
{
struct V_156 * V_165 ;
V_165 = F_118 ( V_181 ) ;
if ( F_18 ( V_165 ) )
goto V_58;
F_112 ( V_165 , V_181 -> V_182 ) ;
F_114 ( V_165 , V_181 -> V_173 ) ;
if ( V_165 -> V_183 == NULL )
F_119 ( V_165 ) ;
F_65 ( & V_165 -> V_184 ) ;
F_120 ( V_165 ) ;
V_58:
return V_165 ;
}
int F_121 ( struct V_1 * V_2 , const struct V_173 * V_174 , int V_103 )
{
struct V_156 * V_165 ;
struct V_180 V_181 = {
. V_182 = V_2 ,
. V_173 = V_174 ,
. V_185 = & V_186 ,
. V_103 = V_103 ,
} ;
int V_187 ;
F_71 ( V_103 & V_188 ) ;
if ( V_103 & V_188 ) {
F_122 ( V_181 . V_185 ,
V_181 . V_189 ) ;
return - V_74 ;
}
V_165 = F_117 ( & V_181 ) ;
if ( F_18 ( V_165 ) )
return F_21 ( V_165 ) ;
V_187 = V_165 -> V_190 ;
F_123 ( V_165 ) ;
return V_187 ;
}
int
F_124 ( struct V_1 * V_2 , const struct V_173 * V_174 , int V_103 ,
const struct V_191 * V_192 , void * V_154 )
{
struct V_156 * V_165 ;
struct V_180 V_181 = {
. V_182 = V_2 ,
. V_173 = V_174 ,
. V_185 = V_192 ,
. V_189 = V_154 ,
. V_103 = V_103 | V_188 ,
} ;
V_165 = F_117 ( & V_181 ) ;
if ( F_18 ( V_165 ) )
return F_21 ( V_165 ) ;
F_123 ( V_165 ) ;
return 0 ;
}
struct V_156 * F_125 ( struct V_193 * V_194 )
{
struct V_156 * V_165 ;
struct V_195 * V_196 = & V_194 -> V_197 ;
struct V_180 V_181 = {
. V_185 = & V_186 ,
. V_103 = V_198 ,
} ;
F_45 ( L_19 , V_194 ) ;
V_165 = F_118 ( & V_181 ) ;
if ( F_18 ( V_165 ) ) {
F_126 ( V_194 ) ;
goto V_58;
}
V_165 -> V_199 = V_194 ;
V_196 -> V_200 = V_196 -> V_201 [ 0 ] . V_202 + V_196 -> V_203 +
V_196 -> V_204 [ 0 ] . V_202 ;
V_165 -> V_183 = V_205 ;
F_65 ( & V_165 -> V_184 ) ;
F_71 ( F_25 ( & V_165 -> V_184 ) != 2 ) ;
F_120 ( V_165 ) ;
V_58:
F_45 ( L_20 , V_165 ) ;
return V_165 ;
}
void
F_119 ( struct V_156 * V_165 )
{
V_165 -> V_183 = V_206 ;
}
T_4 F_127 ( struct V_1 * V_2 , struct V_207 * V_208 , T_4 V_209 )
{
T_4 V_210 ;
struct V_38 * V_39 ;
F_80 () ;
V_39 = F_81 ( V_2 -> V_44 ) ;
V_210 = V_39 -> V_121 ;
if ( V_210 > V_209 )
V_210 = V_209 ;
memcpy ( V_208 , & V_39 -> V_211 , V_210 ) ;
F_82 () ;
return V_210 ;
}
const char * F_128 ( struct V_1 * V_2 ,
enum V_212 V_213 )
{
struct V_38 * V_39 ;
V_39 = F_81 ( V_2 -> V_44 ) ;
if ( V_39 -> V_214 [ V_213 ] != NULL )
return V_39 -> V_214 [ V_213 ] ;
else
return L_21 ;
}
static int F_129 ( struct V_3 * V_3 , struct V_207 * V_215 , T_4 V_216 ,
struct V_207 * V_208 , int V_217 )
{
struct V_218 * V_219 ;
int V_57 ;
V_57 = F_130 ( V_3 , V_215 -> V_133 ,
V_220 , V_221 , & V_219 , 1 ) ;
if ( V_57 < 0 ) {
F_45 ( L_22 , V_57 ) ;
goto V_58;
}
switch ( V_215 -> V_133 ) {
case V_136 :
V_57 = F_131 ( V_219 ,
(struct V_207 * ) & V_222 ,
sizeof( V_222 ) ) ;
break;
case V_139 :
V_57 = F_131 ( V_219 ,
(struct V_207 * ) & V_223 ,
sizeof( V_223 ) ) ;
break;
default:
V_57 = - V_224 ;
goto V_58;
}
if ( V_57 < 0 ) {
F_45 ( L_23 , V_57 ) ;
goto V_225;
}
V_57 = F_132 ( V_219 , V_215 , V_216 , 0 ) ;
if ( V_57 < 0 ) {
F_45 ( L_24 , V_57 ) ;
goto V_225;
}
V_57 = F_133 ( V_219 , V_208 , & V_217 ) ;
if ( V_57 < 0 ) {
F_45 ( L_25 , V_57 ) ;
goto V_225;
}
V_57 = 0 ;
if ( V_208 -> V_133 == V_139 ) {
struct V_131 * V_132 = (struct V_131 * ) V_208 ;
V_132 -> V_226 = 0 ;
}
F_45 ( L_26 , V_30 ) ;
V_225:
F_134 ( V_219 ) ;
V_58:
return V_57 ;
}
static int F_135 ( int V_227 , struct V_207 * V_208 , T_4 V_217 )
{
switch ( V_227 ) {
case V_136 :
if ( V_217 < sizeof( V_222 ) )
return - V_74 ;
memcpy ( V_208 , & V_222 ,
sizeof( V_222 ) ) ;
break;
case V_139 :
if ( V_217 < sizeof( V_223 ) )
return - V_74 ;
memcpy ( V_208 , & V_223 ,
sizeof( V_223 ) ) ;
break;
default:
F_45 ( L_27 ,
V_30 ) ;
return - V_224 ;
}
F_45 ( L_28 , V_30 ) ;
return 0 ;
}
int F_136 ( struct V_1 * V_2 , struct V_207 * V_208 , T_4 V_217 )
{
struct V_228 V_120 ;
struct V_207 * V_215 = (struct V_207 * ) & V_120 ;
struct V_38 * V_39 ;
struct V_3 * V_3 ;
T_4 V_216 ;
int V_57 ;
F_80 () ;
V_39 = F_81 ( V_2 -> V_44 ) ;
V_216 = V_39 -> V_121 ;
memcpy ( V_215 , & V_39 -> V_211 , V_216 ) ;
V_3 = F_137 ( V_39 -> V_229 ) ;
F_82 () ;
F_138 ( V_215 , 0 ) ;
V_57 = F_129 ( V_3 , V_215 , V_216 , V_208 , V_217 ) ;
F_139 ( V_3 ) ;
if ( V_57 != 0 )
return F_135 ( V_215 -> V_133 , V_208 , V_217 ) ;
return 0 ;
}
void
F_140 ( struct V_1 * V_2 , unsigned int V_230 , unsigned int V_231 )
{
struct V_38 * V_39 ;
F_80 () ;
V_39 = F_81 ( V_2 -> V_44 ) ;
if ( V_39 -> V_232 -> V_233 )
V_39 -> V_232 -> V_233 ( V_39 , V_230 , V_231 ) ;
F_82 () ;
}
int F_141 ( struct V_1 * V_2 )
{
int V_101 ;
F_80 () ;
V_101 = F_81 ( V_2 -> V_44 ) -> V_234 ;
F_82 () ;
return V_101 ;
}
struct V_3 * F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_155 ;
F_80 () ;
V_155 = F_81 ( V_2 -> V_44 ) -> V_229 ;
F_82 () ;
return V_155 ;
}
T_4 F_142 ( struct V_1 * V_2 )
{
T_4 V_155 ;
F_80 () ;
V_155 = F_81 ( V_2 -> V_44 ) -> V_235 ;
F_82 () ;
return V_155 ;
}
T_4 F_143 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
T_4 V_155 ;
F_80 () ;
V_39 = F_81 ( V_2 -> V_44 ) ;
V_155 = V_39 -> V_232 -> V_236 ( V_39 ) ;
F_82 () ;
return V_155 ;
}
void F_144 ( struct V_1 * V_2 )
{
if ( V_2 -> V_45 ) {
F_80 () ;
F_145 ( F_81 ( V_2 -> V_44 ) ) ;
F_82 () ;
}
}
int
F_146 ( struct V_156 * V_165 )
{
if ( F_147 ( V_165 ) )
return 0 ;
V_165 -> V_183 = V_206 ;
V_165 -> V_190 = 0 ;
if ( V_165 -> V_192 -> V_237 != NULL )
V_165 -> V_183 = V_238 ;
return 1 ;
}
int
F_148 ( struct V_156 * V_165 )
{
if ( F_147 ( V_165 ) )
return 0 ;
V_165 -> V_183 = V_206 ;
V_165 -> V_190 = 0 ;
return 1 ;
}
const char
* F_149 ( const struct V_156 * V_165 )
{
const struct V_239 * V_240 = V_165 -> V_175 . V_176 ;
if ( V_240 ) {
if ( V_240 -> V_241 )
return V_240 -> V_241 ;
else
return L_29 ;
} else
return L_30 ;
}
static void
V_206 ( struct V_156 * V_165 )
{
struct V_1 * V_2 = V_165 -> V_166 ;
F_45 ( L_31 , V_165 -> V_242 ,
V_2 -> V_16 -> V_18 , V_2 -> V_86 ,
F_149 ( V_165 ) ,
( F_150 ( V_165 ) ? L_32 : L_33 ) ) ;
V_165 -> V_175 . V_176 -> V_243 ++ ;
V_2 -> V_87 -> V_244 ++ ;
V_165 -> V_183 = V_245 ;
}
static void
V_245 ( struct V_156 * V_165 )
{
F_151 ( V_165 ) ;
V_165 -> V_190 = 0 ;
V_165 -> V_183 = V_246 ;
F_152 ( V_165 ) ;
}
static void
V_246 ( struct V_156 * V_165 )
{
int V_187 = V_165 -> V_190 ;
F_151 ( V_165 ) ;
V_165 -> V_190 = 0 ;
if ( V_187 >= 0 ) {
if ( V_165 -> V_199 ) {
V_165 -> V_183 = V_247 ;
return;
}
F_20 ( V_29 L_34 ,
V_30 , V_187 ) ;
F_98 ( V_165 , - V_160 ) ;
return;
}
if ( V_165 -> V_199 ) {
F_20 ( V_29 L_35 ,
V_30 , V_187 ) ;
F_153 ( V_165 ) ;
}
switch ( V_187 ) {
case - V_77 :
F_154 ( V_165 , V_163 >> 2 ) ;
case - V_153 :
V_165 -> V_183 = V_248 ;
return;
case - V_160 :
break;
default:
F_20 ( V_29 L_36 ,
V_30 , V_187 ) ;
break;
}
F_98 ( V_165 , V_187 ) ;
}
static void
V_248 ( struct V_156 * V_165 )
{
F_151 ( V_165 ) ;
V_165 -> V_190 = 0 ;
V_165 -> V_183 = V_246 ;
F_155 ( V_165 ) ;
}
static void
V_247 ( struct V_156 * V_165 )
{
F_151 ( V_165 ) ;
V_165 -> V_183 = V_249 ;
V_165 -> V_190 = 0 ;
V_165 -> V_166 -> V_87 -> V_250 ++ ;
F_156 ( V_165 ) ;
}
static void
V_249 ( struct V_156 * V_165 )
{
int V_187 = V_165 -> V_190 ;
F_151 ( V_165 ) ;
V_165 -> V_190 = 0 ;
V_165 -> V_183 = V_247 ;
switch ( V_187 ) {
case 0 :
if ( F_157 ( V_165 ) ) {
V_165 -> V_183 = V_251 ;
return;
}
case - V_252 :
F_154 ( V_165 , 3 * V_163 ) ;
case - V_153 :
V_187 = - V_253 ;
case - V_254 :
if ( ! V_165 -> V_255 )
break;
V_165 -> V_255 -- ;
F_45 ( L_37 ,
V_165 -> V_242 , V_30 ) ;
return;
}
F_45 ( L_38 ,
V_165 -> V_242 , V_30 , V_187 ) ;
F_98 ( V_165 , V_187 ) ;
}
static void
V_251 ( struct V_156 * V_165 )
{
unsigned int V_256 = V_165 -> V_199 -> V_257 -> V_258 -> V_259 ;
struct V_193 * V_194 = V_165 -> V_199 ;
struct V_38 * V_39 = V_194 -> V_260 ;
struct V_239 * V_240 = V_165 -> V_175 . V_176 ;
int V_187 ;
F_151 ( V_165 ) ;
V_165 -> V_190 = 0 ;
V_165 -> V_183 = V_261 ;
if ( V_194 -> V_262 )
return;
if ( V_240 -> V_263 != 0 ) {
F_158 ( V_240 -> V_264 == 0 ) ;
if ( V_240 -> V_265 != NULL )
F_158 ( V_240 -> V_266 == 0 ) ;
}
V_194 -> V_267 = V_268 + ( V_256 << 1 ) + V_240 -> V_264 ;
V_194 -> V_267 <<= 2 ;
V_194 -> V_269 = V_270 + V_256 + V_240 -> V_266 ;
V_194 -> V_269 <<= 2 ;
V_187 = V_39 -> V_232 -> V_271 ( V_165 ) ;
F_159 ( V_39 ) ;
if ( V_187 == 0 )
return;
if ( V_187 != - V_77 ) {
F_98 ( V_165 , V_187 ) ;
return;
}
F_45 ( L_39 , V_165 -> V_242 ) ;
if ( F_150 ( V_165 ) || ! F_160 ( V_272 ) ) {
V_165 -> V_183 = V_251 ;
F_154 ( V_165 , V_163 >> 4 ) ;
return;
}
F_98 ( V_165 , - V_273 ) ;
}
static inline int
F_161 ( struct V_156 * V_165 )
{
return V_165 -> V_199 -> V_197 . V_200 == 0 ;
}
static inline void
F_162 ( struct V_156 * V_165 )
{
V_165 -> V_199 -> V_197 . V_200 = 0 ;
V_165 -> V_199 -> V_274 = 0 ;
}
static void
F_163 ( struct V_156 * V_165 )
{
struct V_193 * V_194 = V_165 -> V_199 ;
T_5 V_275 ;
T_6 * V_276 ;
F_151 ( V_165 ) ;
F_164 ( & V_194 -> V_197 ,
V_194 -> V_262 ,
V_194 -> V_267 ) ;
F_164 ( & V_194 -> V_277 ,
V_194 -> V_278 ,
V_194 -> V_269 ) ;
V_276 = F_165 ( V_165 ) ;
if ( V_276 == NULL ) {
F_20 ( V_21 L_40 ) ;
F_98 ( V_165 , - V_160 ) ;
return;
}
V_275 = V_165 -> V_175 . V_176 -> V_279 ;
if ( V_275 == NULL )
return;
V_165 -> V_190 = F_166 ( V_165 , V_275 , V_194 , V_276 ,
V_165 -> V_175 . V_177 ) ;
}
static void
V_261 ( struct V_156 * V_165 )
{
struct V_38 * V_39 = V_165 -> V_199 -> V_260 ;
F_151 ( V_165 ) ;
V_165 -> V_183 = V_280 ;
if ( ! F_38 ( V_39 ) ) {
V_165 -> V_183 = V_281 ;
V_165 -> V_282 = V_39 -> V_283 ;
V_39 -> V_232 -> V_284 ( V_165 ) ;
}
}
static void
V_281 ( struct V_156 * V_165 )
{
int V_187 = - V_160 ;
if ( V_165 -> V_190 >= 0 ) {
F_151 ( V_165 ) ;
V_165 -> V_190 = 0 ;
V_165 -> V_183 = V_280 ;
return;
}
F_167 ( V_165 ) ;
switch ( V_165 -> V_190 ) {
case - V_77 :
F_45 ( L_41 , V_165 -> V_242 ) ;
F_154 ( V_165 , V_163 >> 2 ) ;
goto V_285;
case - V_253 :
F_45 ( L_42
L_43 , V_165 -> V_242 ) ;
if ( V_165 -> V_175 . V_176 -> V_263 == 0 ) {
V_187 = - V_286 ;
break;
}
if ( V_165 -> V_287 == 0 )
break;
V_165 -> V_287 -- ;
F_154 ( V_165 , 3 * V_163 ) ;
goto V_285;
case - V_252 :
F_45 ( L_44 ,
V_165 -> V_242 ) ;
goto V_285;
case - V_288 :
F_45 ( L_45 ,
V_165 -> V_242 ) ;
break;
case - V_289 :
F_45 ( L_46 ,
V_165 -> V_242 ) ;
goto V_285;
case - V_290 :
case - V_291 :
case - V_292 :
case - V_293 :
case - V_294 :
case - V_295 :
case - V_296 :
case - V_297 :
case - V_298 :
F_45 ( L_47 ,
V_165 -> V_242 , V_165 -> V_190 ) ;
if ( ! F_168 ( V_165 ) ) {
F_154 ( V_165 , 5 * V_163 ) ;
goto V_285;
}
V_187 = V_165 -> V_190 ;
break;
default:
F_45 ( L_48 ,
V_165 -> V_242 , - V_165 -> V_190 ) ;
}
F_98 ( V_165 , V_187 ) ;
return;
V_285:
V_165 -> V_190 = 0 ;
V_165 -> V_183 = V_299 ;
}
static void
V_280 ( struct V_156 * V_165 )
{
struct V_38 * V_39 = V_165 -> V_199 -> V_260 ;
F_45 ( L_49 ,
V_165 -> V_242 , V_39 ,
( F_169 ( V_39 ) ? L_50 : L_51 ) ) ;
V_165 -> V_183 = V_300 ;
if ( ! F_169 ( V_39 ) ) {
V_165 -> V_183 = V_301 ;
if ( V_165 -> V_190 < 0 )
return;
if ( V_165 -> V_158 & V_302 ) {
F_98 ( V_165 , - V_293 ) ;
return;
}
F_170 ( V_165 ) ;
}
}
static void
V_301 ( struct V_156 * V_165 )
{
struct V_1 * V_2 = V_165 -> V_166 ;
int V_187 = V_165 -> V_190 ;
F_151 ( V_165 ) ;
F_171 ( V_165 , V_187 ) ;
V_165 -> V_190 = 0 ;
switch ( V_187 ) {
case - V_290 :
case - V_291 :
case - V_292 :
case - V_296 :
case - V_295 :
case - V_303 :
case - V_297 :
case - V_298 :
F_172 ( V_165 -> V_199 -> V_260 ,
V_165 -> V_199 -> V_304 ) ;
if ( F_168 ( V_165 ) )
break;
F_154 ( V_165 , 3 * V_163 ) ;
case - V_153 :
case - V_252 :
V_165 -> V_183 = V_299 ;
return;
case 0 :
V_2 -> V_87 -> V_305 ++ ;
V_165 -> V_183 = V_300 ;
return;
}
F_98 ( V_165 , V_187 ) ;
}
static void
V_300 ( struct V_156 * V_165 )
{
int V_306 = F_173 ( V_165 ) ;
F_151 ( V_165 ) ;
V_165 -> V_183 = V_307 ;
if ( V_165 -> V_190 < 0 )
return;
if ( ! F_174 ( V_165 ) )
return;
V_165 -> V_183 = V_308 ;
if ( F_161 ( V_165 ) ) {
F_163 ( V_165 ) ;
if ( V_165 -> V_190 != 0 ) {
if ( V_165 -> V_190 == - V_153 )
F_154 ( V_165 , V_163 >> 4 ) ;
else
F_98 ( V_165 , V_165 -> V_190 ) ;
return;
}
}
F_175 ( V_165 ) ;
if ( V_165 -> V_190 < 0 )
return;
if ( V_306 )
V_165 -> V_166 -> V_87 -> V_309 ++ ;
V_308 ( V_165 ) ;
if ( F_176 ( V_165 ) )
return;
V_165 -> V_183 = V_310 ;
F_100 ( & V_165 -> V_199 -> V_260 -> V_311 , V_165 ) ;
}
static void
V_308 ( struct V_156 * V_165 )
{
V_165 -> V_183 = V_307 ;
if ( V_165 -> V_190 == 0 ) {
F_177 ( V_165 ) ;
F_162 ( V_165 ) ;
return;
}
switch ( V_165 -> V_190 ) {
case - V_153 :
case - V_297 :
break;
default:
F_151 ( V_165 ) ;
F_177 ( V_165 ) ;
F_162 ( V_165 ) ;
break;
case - V_290 :
case - V_294 :
case - V_295 :
case - V_296 :
case - V_312 :
if ( F_168 ( V_165 ) ) {
F_177 ( V_165 ) ;
F_98 ( V_165 , V_165 -> V_190 ) ;
break;
}
case - V_291 :
case - V_292 :
case - V_303 :
case - V_293 :
case - V_298 :
F_162 ( V_165 ) ;
}
}
static void
V_205 ( struct V_156 * V_165 )
{
struct V_193 * V_194 = V_165 -> V_199 ;
if ( ! F_174 ( V_165 ) )
goto V_313;
if ( V_165 -> V_190 < 0 ) {
F_20 ( V_314 L_52
L_53 , V_165 -> V_190 ) ;
goto V_315;
}
if ( V_194 -> V_304 != V_194 -> V_260 -> V_316 )
V_194 -> V_274 = 0 ;
F_175 ( V_165 ) ;
if ( V_165 -> V_190 == - V_153 )
goto V_317;
F_177 ( V_165 ) ;
F_151 ( V_165 ) ;
switch ( V_165 -> V_190 ) {
case 0 :
case - V_294 :
case - V_295 :
case - V_296 :
case - V_291 :
case - V_290 :
case - V_303 :
case - V_293 :
case - V_298 :
break;
case - V_252 :
F_20 ( V_314 L_52
L_53 , V_165 -> V_190 ) ;
F_172 ( V_194 -> V_260 ,
V_194 -> V_304 ) ;
break;
default:
F_71 ( V_165 -> V_190 == - V_153 ) ;
F_20 ( V_314 L_52
L_53 , V_165 -> V_190 ) ;
break;
}
F_100 ( & V_194 -> V_260 -> V_311 , V_165 ) ;
V_315:
V_165 -> V_183 = V_310 ;
return;
V_317:
V_194 -> V_304 = V_194 -> V_260 -> V_316 ;
V_313:
V_165 -> V_190 = 0 ;
}
static void
V_307 ( struct V_156 * V_165 )
{
struct V_1 * V_2 = V_165 -> V_166 ;
struct V_193 * V_194 = V_165 -> V_199 ;
int V_187 ;
if ( V_194 -> V_318 > 0 && ! V_194 -> V_274 )
V_165 -> V_190 = V_194 -> V_318 ;
F_151 ( V_165 ) ;
V_187 = V_165 -> V_190 ;
if ( V_187 >= 0 ) {
V_165 -> V_183 = V_319 ;
return;
}
F_178 ( V_165 ) ;
V_165 -> V_190 = 0 ;
switch( V_187 ) {
case - V_294 :
case - V_295 :
case - V_296 :
case - V_312 :
if ( F_168 ( V_165 ) ) {
F_98 ( V_165 , V_187 ) ;
break;
}
F_154 ( V_165 , 3 * V_163 ) ;
case - V_252 :
V_165 -> V_183 = V_299 ;
if ( ! ( V_165 -> V_158 & V_170 )
&& V_165 -> V_166 -> V_111 )
F_172 ( V_194 -> V_260 ,
V_194 -> V_304 ) ;
break;
case - V_290 :
case - V_291 :
case - V_292 :
F_144 ( V_2 ) ;
case - V_303 :
F_154 ( V_165 , 3 * V_163 ) ;
case - V_298 :
case - V_293 :
V_165 -> V_183 = V_261 ;
break;
case - V_297 :
F_154 ( V_165 , V_163 >> 2 ) ;
case - V_153 :
V_165 -> V_183 = V_300 ;
break;
case - V_160 :
F_98 ( V_165 , V_187 ) ;
break;
default:
if ( V_2 -> V_113 )
F_20 ( L_54 ,
V_2 -> V_16 -> V_18 , - V_187 ) ;
F_98 ( V_165 , V_187 ) ;
}
}
static void
V_299 ( struct V_156 * V_165 )
{
struct V_1 * V_2 = V_165 -> V_166 ;
if ( F_179 ( V_165 -> V_199 ) == 0 ) {
F_45 ( L_55 , V_165 -> V_242 ) ;
goto V_320;
}
F_45 ( L_56 , V_165 -> V_242 ) ;
V_165 -> V_321 ++ ;
if ( F_168 ( V_165 ) ) {
F_98 ( V_165 , - V_252 ) ;
return;
}
if ( F_180 ( V_165 ) ) {
if ( V_2 -> V_113 ) {
F_20 ( V_314 L_57 ,
V_2 -> V_16 -> V_18 ,
V_165 -> V_167 -> V_72 ) ;
}
if ( V_165 -> V_158 & V_322 )
F_98 ( V_165 , - V_252 ) ;
else
F_98 ( V_165 , - V_160 ) ;
return;
}
if ( ! ( V_165 -> V_158 & V_323 ) ) {
V_165 -> V_158 |= V_323 ;
if ( V_2 -> V_113 ) {
F_20 ( V_314 L_58 ,
V_2 -> V_16 -> V_18 ,
V_165 -> V_167 -> V_72 ) ;
}
}
F_144 ( V_2 ) ;
F_181 ( V_165 ) ;
V_320:
V_165 -> V_183 = V_261 ;
V_165 -> V_190 = 0 ;
}
static void
V_319 ( struct V_156 * V_165 )
{
struct V_1 * V_2 = V_165 -> V_166 ;
struct V_193 * V_194 = V_165 -> V_199 ;
T_7 V_324 = V_165 -> V_175 . V_176 -> V_265 ;
T_6 * V_276 ;
F_151 ( V_165 ) ;
if ( V_165 -> V_158 & V_323 ) {
if ( V_2 -> V_113 ) {
F_20 ( V_314 L_59 ,
V_2 -> V_16 -> V_18 ,
V_165 -> V_167 -> V_72 ) ;
}
V_165 -> V_158 &= ~ V_323 ;
}
F_182 () ;
V_194 -> V_277 . V_200 = V_194 -> V_325 . V_200 ;
F_183 ( memcmp ( & V_194 -> V_277 , & V_194 -> V_325 ,
sizeof( V_194 -> V_277 ) ) != 0 ) ;
if ( V_194 -> V_277 . V_200 < 12 ) {
if ( ! F_180 ( V_165 ) ) {
V_165 -> V_183 = V_261 ;
goto V_313;
}
F_45 ( L_60 ,
V_2 -> V_16 -> V_18 , V_165 -> V_190 ) ;
V_165 -> V_183 = V_299 ;
goto V_313;
}
V_276 = F_184 ( V_165 ) ;
if ( F_18 ( V_276 ) ) {
if ( V_276 == F_19 ( - V_153 ) )
goto V_313;
return;
}
V_165 -> V_183 = V_310 ;
if ( V_324 ) {
V_165 -> V_190 = F_185 ( V_165 , V_324 , V_194 , V_276 ,
V_165 -> V_175 . V_178 ) ;
}
F_45 ( L_61 , V_165 -> V_242 ,
V_165 -> V_190 ) ;
return;
V_313:
V_165 -> V_190 = 0 ;
if ( V_165 -> V_199 == V_194 ) {
V_194 -> V_318 = V_194 -> V_277 . V_200 = 0 ;
if ( V_165 -> V_166 -> V_111 )
F_172 ( V_194 -> V_260 ,
V_194 -> V_304 ) ;
}
}
static T_6 *
F_165 ( struct V_156 * V_165 )
{
struct V_1 * V_2 = V_165 -> V_166 ;
struct V_193 * V_194 = V_165 -> V_199 ;
T_6 * V_276 = V_194 -> V_326 [ 0 ] . V_327 ;
V_276 = F_186 ( V_194 -> V_260 , V_276 ) ;
* V_276 ++ = V_194 -> V_328 ;
* V_276 ++ = F_187 ( V_329 ) ;
* V_276 ++ = F_187 ( V_330 ) ;
* V_276 ++ = F_187 ( V_2 -> V_83 ) ;
* V_276 ++ = F_187 ( V_2 -> V_86 ) ;
* V_276 ++ = F_187 ( V_165 -> V_175 . V_176 -> V_263 ) ;
V_276 = F_188 ( V_165 , V_276 ) ;
V_194 -> V_331 = F_189 ( & V_194 -> V_326 [ 0 ] , V_276 ) ;
return V_276 ;
}
static T_6 *
F_184 ( struct V_156 * V_165 )
{
struct V_1 * V_2 = V_165 -> V_166 ;
struct V_332 * V_333 = & V_165 -> V_199 -> V_277 . V_201 [ 0 ] ;
int V_200 = V_165 -> V_199 -> V_277 . V_200 >> 2 ;
T_6 * V_276 = V_333 -> V_327 ;
T_3 V_334 ;
int error = - V_253 ;
if ( ( V_165 -> V_199 -> V_277 . V_200 & 3 ) != 0 ) {
F_45 ( L_62
L_63 , V_165 -> V_242 , V_30 ,
V_165 -> V_199 -> V_277 . V_200 ) ;
error = - V_160 ;
goto V_76;
}
if ( ( V_200 -= 3 ) < 0 )
goto V_335;
V_276 += 1 ;
if ( ( V_334 = F_190 ( * V_276 ++ ) ) != V_336 ) {
F_45 ( L_64 ,
V_165 -> V_242 , V_30 , V_334 ) ;
error = - V_160 ;
goto V_337;
}
if ( ( V_334 = F_190 ( * V_276 ++ ) ) != V_338 ) {
if ( -- V_200 < 0 )
goto V_335;
switch ( ( V_334 = F_190 ( * V_276 ++ ) ) ) {
case V_339 :
break;
case V_340 :
F_45 ( L_65 ,
V_165 -> V_242 , V_30 ) ;
error = - V_289 ;
goto V_76;
default:
F_45 ( L_66
L_67 ,
V_165 -> V_242 , V_30 , V_334 ) ;
error = - V_160 ;
goto V_76;
}
if ( -- V_200 < 0 )
goto V_335;
switch ( ( V_334 = F_190 ( * V_276 ++ ) ) ) {
case V_341 :
case V_342 :
case V_343 :
case V_344 :
if ( ! V_165 -> V_255 )
break;
V_165 -> V_255 -- ;
F_45 ( L_68 ,
V_165 -> V_242 , V_30 ) ;
F_181 ( V_165 ) ;
F_153 ( V_165 ) ;
V_165 -> V_183 = V_245 ;
goto V_313;
case V_345 :
case V_346 :
if ( ! V_165 -> V_347 )
break;
V_165 -> V_347 -- ;
F_45 ( L_69 ,
V_165 -> V_242 , V_30 ) ;
V_165 -> V_183 = V_261 ;
goto V_313;
case V_348 :
F_20 ( V_314 L_70
L_71 ,
V_165 -> V_167 -> V_72 ) ;
break;
default:
F_45 ( L_72 ,
V_165 -> V_242 , V_30 , V_334 ) ;
error = - V_160 ;
}
F_45 ( L_73 ,
V_165 -> V_242 , V_30 , V_334 ) ;
goto V_76;
}
V_276 = F_191 ( V_165 , V_276 ) ;
if ( F_18 ( V_276 ) ) {
error = F_21 ( V_276 ) ;
F_45 ( L_74 ,
V_165 -> V_242 , V_30 , error ) ;
goto V_337;
}
V_200 = V_276 - ( T_6 * ) V_333 -> V_327 - 1 ;
if ( V_200 < 0 )
goto V_335;
switch ( ( V_334 = F_190 ( * V_276 ++ ) ) ) {
case V_349 :
return V_276 ;
case V_350 :
F_45 ( L_75
L_76 , V_165 -> V_242 , V_30 ,
( unsigned int ) V_2 -> V_83 ,
V_165 -> V_167 -> V_72 ) ;
error = - V_288 ;
goto V_76;
case V_351 :
F_45 ( L_77
L_76 , V_165 -> V_242 , V_30 ,
( unsigned int ) V_2 -> V_83 ,
( unsigned int ) V_2 -> V_86 ,
V_165 -> V_167 -> V_72 ) ;
error = - V_289 ;
goto V_76;
case V_352 :
F_45 ( L_78
L_79 ,
V_165 -> V_242 , V_30 ,
F_149 ( V_165 ) ,
V_2 -> V_83 , V_2 -> V_86 ,
V_165 -> V_167 -> V_72 ) ;
error = - V_286 ;
goto V_76;
case V_353 :
F_45 ( L_80 ,
V_165 -> V_242 , V_30 ) ;
break;
default:
F_45 ( L_81 ,
V_165 -> V_242 , V_30 , V_334 ) ;
}
V_337:
V_2 -> V_87 -> V_354 ++ ;
if ( V_165 -> V_347 ) {
V_165 -> V_347 -- ;
F_45 ( L_82 ,
V_165 -> V_242 , V_30 ) ;
V_165 -> V_183 = V_261 ;
V_313:
return F_19 ( - V_153 ) ;
}
V_76:
F_98 ( V_165 , error ) ;
F_45 ( L_83 , V_165 -> V_242 ,
V_30 , error ) ;
return F_19 ( error ) ;
V_335:
F_45 ( L_84 , V_165 -> V_242 ,
V_30 ) ;
goto V_337;
}
static void F_192 ( void * V_355 , struct V_356 * V_357 , void * V_358 )
{
}
static int F_193 ( void * V_355 , struct V_356 * V_357 , void * V_358 )
{
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_173 V_174 = {
. V_176 = & V_359 ,
} ;
int V_57 ;
V_174 . V_179 = V_360 . V_361 ( NULL , NULL , 0 ) ;
V_57 = F_121 ( V_2 , & V_174 , V_169 | V_198 ) ;
F_194 ( V_174 . V_179 ) ;
return V_57 ;
}
static
struct V_156 * F_195 ( struct V_1 * V_2 ,
struct V_38 * V_39 , struct V_179 * V_362 , int V_103 ,
const struct V_191 * V_232 , void * V_154 )
{
struct V_173 V_174 = {
. V_176 = & V_359 ,
. V_179 = V_362 ,
} ;
struct V_180 V_181 = {
. V_182 = V_2 ,
. V_38 = V_39 ,
. V_173 = & V_174 ,
. V_185 = ( V_232 != NULL ) ? V_232 : & V_186 ,
. V_189 = V_154 ,
. V_103 = V_103 ,
} ;
return F_117 ( & V_181 ) ;
}
struct V_156 * F_196 ( struct V_1 * V_2 , struct V_179 * V_362 , int V_103 )
{
return F_195 ( V_2 , NULL , V_362 , V_103 , NULL , NULL ) ;
}
static void F_197 ( struct V_156 * V_165 , void * V_363 )
{
struct V_364 * V_154 = V_363 ;
if ( V_165 -> V_190 == 0 )
F_198 ( V_154 -> V_66 , V_154 -> V_39 ) ;
}
static void F_199 ( void * V_363 )
{
struct V_364 * V_154 = V_363 ;
F_69 ( V_154 -> V_39 ) ;
F_61 ( V_154 -> V_66 ) ;
F_67 ( V_154 ) ;
}
int F_200 ( struct V_1 * V_2 ,
struct V_65 * V_66 , struct V_38 * V_39 ,
void * V_365 )
{
struct V_364 * V_154 ;
struct V_179 * V_362 ;
struct V_156 * V_165 ;
V_154 = F_201 ( sizeof( * V_154 ) , V_366 ) ;
if ( ! V_154 )
return - V_77 ;
V_154 -> V_66 = F_72 ( V_66 ) ;
V_154 -> V_39 = F_77 ( V_39 ) ;
V_362 = V_360 . V_361 ( NULL , NULL , 0 ) ;
V_165 = F_195 ( V_2 , V_39 , V_362 ,
V_169 | V_198 | V_188 ,
& V_367 , V_154 ) ;
F_194 ( V_362 ) ;
if ( F_18 ( V_165 ) )
return F_21 ( V_165 ) ;
F_123 ( V_165 ) ;
return 1 ;
}
int F_202 ( struct V_1 * V_2 ,
struct V_65 * V_66 ,
struct V_38 * V_39 ,
void * V_154 )
{
struct V_179 * V_362 ;
struct V_156 * V_165 ;
struct V_368 * V_369 = (struct V_368 * ) V_154 ;
int V_187 = - V_303 ;
V_39 = F_77 ( V_39 ) ;
F_72 ( V_66 ) ;
if ( F_203 ( V_66 , (struct V_207 * ) & V_39 -> V_211 ) )
goto V_76;
V_362 = V_360 . V_361 ( NULL , NULL , 0 ) ;
V_165 = F_195 ( V_2 , V_39 , V_362 ,
V_169 | V_198 ,
NULL , NULL ) ;
F_194 ( V_362 ) ;
if ( F_18 ( V_165 ) ) {
V_187 = F_21 ( V_165 ) ;
goto V_76;
}
V_187 = V_165 -> V_190 ;
F_123 ( V_165 ) ;
if ( V_187 < 0 )
goto V_76;
V_369 -> V_370 ( V_2 , V_39 , V_369 -> V_154 ) ;
return 1 ;
V_76:
F_69 ( V_39 ) ;
F_61 ( V_66 ) ;
F_16 ( L_85 ,
V_187 , V_39 -> V_214 [ V_371 ] ) ;
return V_187 ;
}
int F_204 ( struct V_1 * V_2 ,
struct V_114 * V_115 ,
int (* F_205)( struct V_1 * ,
struct V_65 * ,
struct V_38 * ,
void * ) ,
void * V_154 )
{
struct V_65 * V_66 ;
struct V_38 * V_39 ;
unsigned long V_372 ;
unsigned long V_373 ;
unsigned char V_141 ;
int V_155 = 0 ;
F_80 () ;
V_66 = F_72 ( F_81 ( V_2 -> V_93 . V_144 ) ) ;
V_39 = F_206 ( & V_2 -> V_93 ) ;
if ( V_66 == NULL || V_39 == NULL ) {
F_82 () ;
return - V_153 ;
}
V_141 = V_39 -> V_141 ;
V_372 = V_39 -> V_372 ;
V_373 = V_39 -> V_374 ;
F_82 () ;
V_39 = F_78 ( V_115 ) ;
if ( F_18 ( V_39 ) ) {
V_155 = F_21 ( V_39 ) ;
goto V_375;
}
V_39 -> V_141 = V_141 ;
if ( V_39 -> V_232 -> V_376 != NULL )
V_39 -> V_232 -> V_376 ( V_39 ,
V_372 ,
V_373 ) ;
F_207 ( V_66 ) ;
if ( F_205 ) {
V_155 = F_205 ( V_2 , V_66 , V_39 , V_154 ) ;
if ( V_155 != 0 )
goto V_377;
}
F_198 ( V_66 , V_39 ) ;
V_377:
F_69 ( V_39 ) ;
V_375:
F_61 ( V_66 ) ;
return V_155 ;
}
static int
F_208 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
void * V_154 )
{
struct V_378 * V_379 = V_154 ;
if ( V_39 -> V_232 -> V_376 )
V_39 -> V_232 -> V_376 ( V_39 ,
V_379 -> V_372 ,
V_379 -> V_373 ) ;
return 0 ;
}
void
F_209 ( struct V_1 * V_2 ,
unsigned long V_372 ,
unsigned long V_373 )
{
struct V_378 V_41 = {
. V_372 = V_372 ,
. V_373 = V_373 ,
} ;
F_91 ( V_2 ,
F_208 ,
& V_41 ) ;
}
void F_210 ( struct V_1 * V_2 )
{
F_80 () ;
F_61 ( F_81 ( V_2 -> V_93 . V_144 ) ) ;
F_82 () ;
}
void F_211 ( struct V_1 * V_2 , struct V_38 * V_39 )
{
F_80 () ;
F_198 ( F_81 ( V_2 -> V_93 . V_144 ) ,
V_39 ) ;
F_82 () ;
}
bool F_212 ( struct V_1 * V_2 ,
const struct V_207 * V_215 )
{
struct V_65 * V_66 ;
bool V_155 ;
F_80 () ;
V_66 = F_81 ( V_2 -> V_93 . V_144 ) ;
V_155 = F_203 ( V_66 , V_215 ) ;
F_82 () ;
return V_155 ;
}
static void F_213 ( void )
{
F_20 ( V_21 L_86
L_87 ) ;
}
static void F_214 ( const struct V_1 * V_2 ,
const struct V_156 * V_165 )
{
const char * V_380 = L_88 ;
if ( F_99 ( V_165 ) )
V_380 = F_215 ( V_165 -> V_161 ) ;
F_20 ( V_21 L_89 ,
V_165 -> V_242 , V_165 -> V_158 , V_165 -> V_190 ,
V_2 , V_165 -> V_199 , V_165 -> V_282 , V_165 -> V_192 ,
V_2 -> V_16 -> V_18 , V_2 -> V_86 , F_149 ( V_165 ) ,
V_165 -> V_183 , V_380 ) ;
}
void F_216 ( struct V_3 * V_3 )
{
struct V_1 * V_2 ;
struct V_156 * V_165 ;
int V_381 = 0 ;
struct V_4 * V_5 = F_3 ( V_3 , V_6 ) ;
F_4 ( & V_5 -> V_7 ) ;
F_29 (clnt, &sn->all_clients, cl_clients) {
F_4 ( & V_2 -> V_43 ) ;
F_29 (task, &clnt->cl_tasks, tk_task) {
if ( ! V_381 ) {
F_213 () ;
V_381 ++ ;
}
F_214 ( V_2 , V_165 ) ;
}
F_6 ( & V_2 -> V_43 ) ;
}
F_6 ( & V_5 -> V_7 ) ;
}
static int
F_217 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
void * V_365 )
{
return F_218 ( V_39 ) ;
}
int
F_219 ( struct V_1 * V_2 )
{
if ( F_220 ( & V_2 -> V_171 ) == 1 )
return F_91 ( V_2 ,
F_217 , NULL ) ;
return 0 ;
}
static int
F_221 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
void * V_365 )
{
F_222 ( V_39 ) ;
return 0 ;
}
void
F_223 ( struct V_1 * V_2 )
{
if ( F_224 ( & V_2 -> V_171 ) == 0 )
F_91 ( V_2 ,
F_221 , NULL ) ;
}
