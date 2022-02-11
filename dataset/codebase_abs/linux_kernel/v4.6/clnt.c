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
V_2 -> V_49 = F_41 ( V_2 -> V_50 ,
V_48 , sizeof( V_2 -> V_50 ) ) ;
}
static int F_42 ( struct V_1 * V_2 ,
T_2 V_51 ,
const char * V_52 )
{
struct V_53 V_54 = {
. V_51 = V_51 ,
. V_55 = V_52 ,
} ;
struct V_56 * V_57 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_10 * V_11 ;
int V_28 ;
F_43 ( V_2 ) ;
V_11 = F_12 ( V_3 ) ;
if ( V_11 ) {
V_28 = F_23 ( V_11 , V_2 ) ;
if ( V_28 )
goto V_58;
}
F_1 ( V_2 ) ;
if ( V_11 )
F_13 ( V_3 ) ;
V_57 = F_44 ( & V_54 , V_2 ) ;
if ( F_18 ( V_57 ) ) {
F_45 ( L_6 ,
V_51 ) ;
V_28 = F_21 ( V_57 ) ;
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
return V_28 ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_60 ;
V_60 = F_48 ( & V_61 , 0 , 0 , V_62 ) ;
if ( V_60 < 0 )
return V_60 ;
V_2 -> V_63 = V_60 ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_50 ( & V_61 , V_2 -> V_63 ) ;
}
static struct V_1 * F_51 ( const struct V_64 * args ,
struct V_65 * V_66 ,
struct V_39 * V_40 ,
struct V_1 * V_67 )
{
const struct V_68 * V_69 = args -> V_69 ;
const struct V_70 * V_71 ;
struct V_1 * V_2 = NULL ;
const struct V_41 * V_42 ;
const char * V_48 = args -> V_48 ;
int V_28 ;
F_45 ( L_7 ,
V_69 -> V_18 , args -> V_72 , V_40 ) ;
V_28 = F_52 () ;
if ( V_28 )
goto V_73;
V_28 = - V_74 ;
if ( args -> V_71 >= V_69 -> V_75 )
goto V_76;
V_71 = V_69 -> V_71 [ args -> V_71 ] ;
if ( V_71 == NULL )
goto V_76;
V_28 = - V_77 ;
V_2 = F_53 ( sizeof( * V_2 ) , V_62 ) ;
if ( ! V_2 )
goto V_76;
V_2 -> V_33 = V_67 ? : V_2 ;
V_28 = F_47 ( V_2 ) ;
if ( V_28 )
goto V_78;
V_2 -> V_79 = V_71 -> V_80 ;
V_2 -> V_81 = V_71 -> V_82 ;
V_2 -> V_83 = args -> V_84 ? : V_69 -> V_85 ;
V_2 -> V_86 = V_71 -> V_85 ;
V_2 -> V_87 = V_69 -> V_88 ;
V_2 -> V_89 = F_54 ( V_2 ) ;
F_55 ( & V_2 -> V_24 ) ;
V_28 = - V_77 ;
if ( V_2 -> V_89 == NULL )
goto V_90;
V_2 -> V_16 = V_69 ;
F_56 ( & V_2 -> V_91 ) ;
F_57 ( & V_2 -> V_44 ) ;
V_42 = V_40 -> V_42 ;
if ( args -> V_42 != NULL ) {
memcpy ( & V_2 -> V_92 , args -> V_42 ,
sizeof( V_2 -> V_92 ) ) ;
V_42 = & V_2 -> V_92 ;
}
F_35 ( V_2 , V_40 , V_42 ) ;
F_58 ( & V_2 -> V_93 , V_66 ) ;
F_59 ( V_66 ) ;
V_2 -> V_94 = & V_2 -> V_95 ;
F_60 ( & V_2 -> V_95 , V_2 -> V_47 -> V_96 ) ;
F_61 ( & V_2 -> V_26 , 1 ) ;
if ( V_48 == NULL )
V_48 = F_62 () -> V_48 ;
F_40 ( V_2 , V_48 ) ;
V_28 = F_42 ( V_2 , args -> V_97 , args -> V_52 ) ;
if ( V_28 )
goto V_98;
if ( V_67 )
F_63 ( & V_67 -> V_26 ) ;
return V_2 ;
V_98:
F_64 ( V_2 -> V_89 ) ;
V_90:
F_49 ( V_2 ) ;
V_78:
F_65 ( V_2 ) ;
V_76:
F_66 () ;
V_73:
F_59 ( V_66 ) ;
F_67 ( V_40 ) ;
return F_19 ( V_28 ) ;
}
struct V_1 * F_68 ( struct V_64 * args ,
struct V_39 * V_40 )
{
struct V_1 * V_2 = NULL ;
struct V_65 * V_66 ;
V_66 = F_69 ( V_40 , V_62 ) ;
if ( V_66 == NULL )
return F_19 ( - V_77 ) ;
V_2 = F_51 ( args , V_66 , V_40 , NULL ) ;
if ( F_18 ( V_2 ) )
return V_2 ;
if ( ! ( args -> V_99 & V_100 ) ) {
int V_28 = F_70 ( V_2 ) ;
if ( V_28 != 0 ) {
F_71 ( V_2 ) ;
return F_19 ( V_28 ) ;
}
}
V_2 -> V_101 = 1 ;
if ( args -> V_99 & V_102 )
V_2 -> V_101 = 0 ;
if ( args -> V_99 & V_103 )
V_2 -> V_46 = 1 ;
if ( args -> V_99 & V_104 )
V_2 -> V_105 = 1 ;
if ( args -> V_99 & V_106 )
V_2 -> V_107 = 1 ;
if ( ! ( args -> V_99 & V_108 ) )
V_2 -> V_109 = 1 ;
return V_2 ;
}
struct V_1 * F_72 ( struct V_64 * args )
{
struct V_39 * V_40 ;
struct V_110 V_111 = {
. V_3 = args -> V_3 ,
. V_112 = args -> V_113 ,
. V_114 = args -> V_115 ,
. V_116 = args -> V_117 ,
. V_118 = args -> V_119 ,
. V_72 = args -> V_72 ,
. V_120 = args -> V_120 ,
} ;
char V_72 [ 48 ] ;
if ( args -> V_99 & V_121 )
V_111 . V_99 |= V_122 ;
if ( args -> V_99 & V_123 )
V_111 . V_99 |= V_124 ;
if ( V_111 . V_72 == NULL ) {
struct V_125 * V_126 =
(struct V_125 * ) args -> V_117 ;
struct V_127 * sin =
(struct V_127 * ) args -> V_117 ;
struct V_128 * V_129 =
(struct V_128 * ) args -> V_117 ;
V_72 [ 0 ] = '\0' ;
switch ( args -> V_117 -> V_130 ) {
case V_131 :
snprintf ( V_72 , sizeof( V_72 ) , L_8 ,
V_126 -> V_132 ) ;
break;
case V_133 :
snprintf ( V_72 , sizeof( V_72 ) , L_9 ,
& sin -> V_134 . V_135 ) ;
break;
case V_136 :
snprintf ( V_72 , sizeof( V_72 ) , L_10 ,
& V_129 -> V_137 ) ;
break;
default:
return F_19 ( - V_74 ) ;
}
V_111 . V_72 = V_72 ;
}
V_40 = F_73 ( & V_111 ) ;
if ( F_18 ( V_40 ) )
return (struct V_1 * ) V_40 ;
V_40 -> V_138 = 1 ;
if ( args -> V_99 & V_139 )
V_40 -> V_138 = 0 ;
return F_68 ( args , V_40 ) ;
}
static struct V_1 * F_74 ( struct V_64 * args ,
struct V_1 * V_2 )
{
struct V_65 * V_66 ;
struct V_39 * V_40 ;
struct V_1 * V_140 ;
int V_28 ;
V_28 = - V_77 ;
F_75 () ;
V_40 = F_76 ( F_77 ( V_2 -> V_45 ) ) ;
V_66 = F_78 ( F_77 ( V_2 -> V_93 . V_141 ) ) ;
F_79 () ;
if ( V_40 == NULL || V_66 == NULL ) {
F_67 ( V_40 ) ;
F_59 ( V_66 ) ;
goto V_76;
}
args -> V_72 = V_40 -> V_72 ;
args -> V_48 = V_2 -> V_50 ;
V_140 = F_51 ( args , V_66 , V_40 , V_2 ) ;
if ( F_18 ( V_140 ) ) {
V_28 = F_21 ( V_140 ) ;
goto V_76;
}
V_140 -> V_46 = 0 ;
V_140 -> V_101 = V_2 -> V_101 ;
V_140 -> V_105 = V_2 -> V_105 ;
V_140 -> V_107 = V_2 -> V_107 ;
V_140 -> V_109 = V_2 -> V_109 ;
return V_140 ;
V_76:
F_45 ( L_11 , V_31 , V_28 ) ;
return F_19 ( V_28 ) ;
}
struct V_1 * F_80 ( struct V_1 * V_2 )
{
struct V_64 args = {
. V_69 = V_2 -> V_16 ,
. V_84 = V_2 -> V_83 ,
. V_71 = V_2 -> V_86 ,
. V_97 = V_2 -> V_142 -> V_143 ,
} ;
return F_74 ( & args , V_2 ) ;
}
struct V_1 *
F_81 ( struct V_1 * V_2 , T_2 V_144 )
{
struct V_64 args = {
. V_69 = V_2 -> V_16 ,
. V_84 = V_2 -> V_83 ,
. V_71 = V_2 -> V_86 ,
. V_97 = V_144 ,
} ;
return F_74 ( & args , V_2 ) ;
}
int F_82 ( struct V_1 * V_2 ,
struct V_110 * args ,
const struct V_41 * V_42 )
{
const struct V_41 * V_145 ;
T_2 V_51 ;
struct V_65 * V_66 , * V_146 ;
struct V_39 * V_40 , * V_43 ;
struct V_1 * V_67 ;
int V_28 ;
V_40 = F_73 ( args ) ;
if ( F_18 ( V_40 ) ) {
F_45 ( L_12 ,
V_2 ) ;
return F_21 ( V_40 ) ;
}
V_66 = F_69 ( V_40 , V_62 ) ;
if ( V_66 == NULL ) {
F_67 ( V_40 ) ;
return - V_77 ;
}
V_51 = V_2 -> V_142 -> V_143 ;
V_145 = V_2 -> V_47 ;
V_43 = F_35 ( V_2 , V_40 , V_42 ) ;
V_146 = F_83 ( & V_2 -> V_93 , V_66 ) ;
F_7 ( V_2 ) ;
F_9 ( V_2 ) ;
F_46 ( V_2 ) ;
V_67 = V_2 -> V_33 ;
V_2 -> V_33 = V_2 ;
V_28 = F_42 ( V_2 , V_51 , NULL ) ;
if ( V_28 )
goto V_147;
F_84 () ;
if ( V_67 != V_2 )
F_85 ( V_67 ) ;
F_59 ( V_146 ) ;
F_67 ( V_43 ) ;
F_45 ( L_13 , V_2 ) ;
return 0 ;
V_147:
V_66 = F_83 ( & V_2 -> V_93 , V_146 ) ;
F_35 ( V_2 , V_43 , V_145 ) ;
V_2 -> V_33 = V_67 ;
F_42 ( V_2 , V_51 , NULL ) ;
F_59 ( V_66 ) ;
F_67 ( V_40 ) ;
F_45 ( L_14 , V_2 ) ;
return V_28 ;
}
static
int F_86 ( struct V_1 * V_2 , struct V_148 * V_149 )
{
struct V_65 * V_66 ;
F_75 () ;
V_66 = F_78 ( F_77 ( V_2 -> V_93 . V_141 ) ) ;
F_79 () ;
if ( V_66 == NULL )
return - V_150 ;
F_87 ( V_149 , V_66 ) ;
F_59 ( V_66 ) ;
return 0 ;
}
int F_88 ( struct V_1 * V_2 ,
int (* F_89)( struct V_1 * , struct V_39 * , void * ) ,
void * V_151 )
{
struct V_148 V_149 ;
int V_152 ;
V_152 = F_86 ( V_2 , & V_149 ) ;
if ( V_152 )
return V_152 ;
for (; ; ) {
struct V_39 * V_40 = F_90 ( & V_149 ) ;
if ( ! V_40 )
break;
V_152 = F_89 ( V_2 , V_40 , V_151 ) ;
F_67 ( V_40 ) ;
if ( V_152 < 0 )
break;
}
F_91 ( & V_149 ) ;
return V_152 ;
}
void F_92 ( struct V_1 * V_2 )
{
struct V_153 * V_154 ;
if ( F_93 ( & V_2 -> V_91 ) )
return;
F_45 ( L_15 , V_2 ) ;
F_4 ( & V_2 -> V_44 ) ;
F_29 (rovr, &clnt->cl_tasks, tk_task) {
if ( ! F_94 ( V_154 ) )
continue;
if ( ! ( V_154 -> V_155 & V_156 ) ) {
V_154 -> V_155 |= V_156 ;
F_95 ( V_154 , - V_157 ) ;
if ( F_96 ( V_154 ) )
F_97 ( V_154 -> V_158 ,
V_154 ) ;
}
}
F_6 ( & V_2 -> V_44 ) ;
}
void F_71 ( struct V_1 * V_2 )
{
F_98 () ;
F_99 ( L_16 ,
V_2 -> V_16 -> V_18 ,
F_77 ( V_2 -> V_45 ) -> V_72 ) ;
while ( ! F_93 ( & V_2 -> V_91 ) ) {
F_92 ( V_2 ) ;
F_100 ( V_159 ,
F_93 ( & V_2 -> V_91 ) , 1 * V_160 ) ;
}
F_85 ( V_2 ) ;
}
static struct V_1 *
F_101 ( struct V_1 * V_2 )
{
struct V_1 * V_67 = NULL ;
F_99 ( L_17 ,
V_2 -> V_16 -> V_18 ,
F_77 ( V_2 -> V_45 ) -> V_72 ) ;
if ( V_2 -> V_33 != V_2 )
V_67 = V_2 -> V_33 ;
F_46 ( V_2 ) ;
F_11 ( V_2 ) ;
F_7 ( V_2 ) ;
F_64 ( V_2 -> V_89 ) ;
V_2 -> V_89 = NULL ;
F_67 ( F_102 ( V_2 -> V_45 ) ) ;
F_91 ( & V_2 -> V_93 ) ;
F_66 () ;
F_49 ( V_2 ) ;
F_65 ( V_2 ) ;
return V_67 ;
}
static struct V_1 *
F_103 ( struct V_1 * V_2 )
{
if ( V_2 -> V_142 == NULL )
return F_101 ( V_2 ) ;
F_63 ( & V_2 -> V_26 ) ;
F_104 ( V_2 -> V_142 ) ;
V_2 -> V_142 = NULL ;
if ( F_105 ( & V_2 -> V_26 ) )
return F_101 ( V_2 ) ;
return NULL ;
}
void
F_85 ( struct V_1 * V_2 )
{
F_45 ( L_18 , V_2 ) ;
do {
if ( F_93 ( & V_2 -> V_91 ) )
F_106 ( & V_159 ) ;
if ( ! F_105 ( & V_2 -> V_26 ) )
break;
V_2 = F_103 ( V_2 ) ;
} while ( V_2 != NULL );
}
struct V_1 * F_107 ( struct V_1 * V_43 ,
const struct V_68 * V_69 ,
T_3 V_161 )
{
struct V_64 args = {
. V_69 = V_69 ,
. V_84 = V_69 -> V_85 ,
. V_71 = V_161 ,
. V_97 = V_43 -> V_142 -> V_143 ,
} ;
struct V_1 * V_2 ;
int V_28 ;
V_2 = F_74 ( & args , V_43 ) ;
if ( F_18 ( V_2 ) )
goto V_58;
V_28 = F_70 ( V_2 ) ;
if ( V_28 != 0 ) {
F_71 ( V_2 ) ;
V_2 = F_19 ( V_28 ) ;
}
V_58:
return V_2 ;
}
void F_108 ( struct V_153 * V_162 )
{
struct V_1 * V_2 = V_162 -> V_163 ;
struct V_39 * V_40 = V_162 -> V_164 ;
if ( V_2 != NULL ) {
F_4 ( & V_2 -> V_44 ) ;
F_8 ( & V_162 -> V_165 ) ;
F_6 ( & V_2 -> V_44 ) ;
V_162 -> V_163 = NULL ;
F_85 ( V_2 ) ;
}
if ( V_40 != NULL ) {
V_162 -> V_164 = NULL ;
F_67 ( V_40 ) ;
}
}
static
void F_109 ( struct V_153 * V_162 , struct V_1 * V_2 )
{
if ( V_2 != NULL ) {
F_108 ( V_162 ) ;
if ( V_162 -> V_164 == NULL )
V_162 -> V_164 = F_90 ( & V_2 -> V_93 ) ;
V_162 -> V_163 = V_2 ;
F_63 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_101 )
V_162 -> V_155 |= V_166 ;
if ( V_2 -> V_105 )
V_162 -> V_155 |= V_167 ;
if ( F_25 ( & V_2 -> V_168 ) )
V_162 -> V_155 |= V_169 ;
F_4 ( & V_2 -> V_44 ) ;
F_110 ( & V_162 -> V_165 , & V_2 -> V_91 ) ;
F_6 ( & V_2 -> V_44 ) ;
}
}
static void
F_111 ( struct V_153 * V_162 , const struct V_170 * V_171 )
{
if ( V_171 != NULL ) {
V_162 -> V_172 . V_173 = V_171 -> V_173 ;
V_162 -> V_172 . V_174 = V_171 -> V_174 ;
V_162 -> V_172 . V_175 = V_171 -> V_175 ;
if ( V_171 -> V_176 != NULL )
V_162 -> V_172 . V_176 = F_112 ( V_171 -> V_176 ) ;
}
}
static void
F_113 ( struct V_153 * V_162 , void * V_151 )
{
}
struct V_153 * F_114 ( const struct V_177 * V_178 )
{
struct V_153 * V_162 ;
V_162 = F_115 ( V_178 ) ;
if ( F_18 ( V_162 ) )
goto V_58;
F_109 ( V_162 , V_178 -> V_179 ) ;
F_111 ( V_162 , V_178 -> V_170 ) ;
if ( V_162 -> V_180 == NULL )
F_116 ( V_162 ) ;
F_63 ( & V_162 -> V_181 ) ;
F_117 ( V_162 ) ;
V_58:
return V_162 ;
}
int F_118 ( struct V_1 * V_2 , const struct V_170 * V_171 , int V_99 )
{
struct V_153 * V_162 ;
struct V_177 V_178 = {
. V_179 = V_2 ,
. V_170 = V_171 ,
. V_182 = & V_183 ,
. V_99 = V_99 ,
} ;
int V_184 ;
F_119 ( V_99 & V_185 ) ;
if ( V_99 & V_185 ) {
F_120 ( V_178 . V_182 ,
V_178 . V_186 ) ;
return - V_74 ;
}
V_162 = F_114 ( & V_178 ) ;
if ( F_18 ( V_162 ) )
return F_21 ( V_162 ) ;
V_184 = V_162 -> V_187 ;
F_121 ( V_162 ) ;
return V_184 ;
}
int
F_122 ( struct V_1 * V_2 , const struct V_170 * V_171 , int V_99 ,
const struct V_188 * V_189 , void * V_151 )
{
struct V_153 * V_162 ;
struct V_177 V_178 = {
. V_179 = V_2 ,
. V_170 = V_171 ,
. V_182 = V_189 ,
. V_186 = V_151 ,
. V_99 = V_99 | V_185 ,
} ;
V_162 = F_114 ( & V_178 ) ;
if ( F_18 ( V_162 ) )
return F_21 ( V_162 ) ;
F_121 ( V_162 ) ;
return 0 ;
}
struct V_153 * F_123 ( struct V_190 * V_191 )
{
struct V_153 * V_162 ;
struct V_192 * V_193 = & V_191 -> V_194 ;
struct V_177 V_178 = {
. V_182 = & V_183 ,
. V_99 = V_195 ,
} ;
F_45 ( L_19 , V_191 ) ;
V_162 = F_115 ( & V_178 ) ;
if ( F_18 ( V_162 ) ) {
F_124 ( V_191 ) ;
goto V_58;
}
V_162 -> V_196 = V_191 ;
V_193 -> V_197 = V_193 -> V_198 [ 0 ] . V_199 + V_193 -> V_200 +
V_193 -> V_201 [ 0 ] . V_199 ;
V_162 -> V_180 = V_202 ;
F_63 ( & V_162 -> V_181 ) ;
F_119 ( F_25 ( & V_162 -> V_181 ) != 2 ) ;
F_117 ( V_162 ) ;
V_58:
F_45 ( L_20 , V_162 ) ;
return V_162 ;
}
void
F_116 ( struct V_153 * V_162 )
{
V_162 -> V_180 = V_203 ;
}
T_4 F_125 ( struct V_1 * V_2 , struct V_204 * V_205 , T_4 V_206 )
{
T_4 V_207 ;
struct V_39 * V_40 ;
F_75 () ;
V_40 = F_77 ( V_2 -> V_45 ) ;
V_207 = V_40 -> V_118 ;
if ( V_207 > V_206 )
V_207 = V_206 ;
memcpy ( V_205 , & V_40 -> V_208 , V_207 ) ;
F_79 () ;
return V_207 ;
}
const char * F_126 ( struct V_1 * V_2 ,
enum V_209 V_210 )
{
struct V_39 * V_40 ;
V_40 = F_77 ( V_2 -> V_45 ) ;
if ( V_40 -> V_211 [ V_210 ] != NULL )
return V_40 -> V_211 [ V_210 ] ;
else
return L_21 ;
}
static int F_127 ( struct V_3 * V_3 , struct V_204 * V_212 , T_4 V_213 ,
struct V_204 * V_205 , int V_214 )
{
struct V_215 * V_216 ;
int V_28 ;
V_28 = F_128 ( V_3 , V_212 -> V_130 ,
V_217 , V_218 , & V_216 , 1 ) ;
if ( V_28 < 0 ) {
F_45 ( L_22 , V_28 ) ;
goto V_58;
}
switch ( V_212 -> V_130 ) {
case V_133 :
V_28 = F_129 ( V_216 ,
(struct V_204 * ) & V_219 ,
sizeof( V_219 ) ) ;
break;
case V_136 :
V_28 = F_129 ( V_216 ,
(struct V_204 * ) & V_220 ,
sizeof( V_220 ) ) ;
break;
default:
V_28 = - V_221 ;
goto V_58;
}
if ( V_28 < 0 ) {
F_45 ( L_23 , V_28 ) ;
goto V_222;
}
V_28 = F_130 ( V_216 , V_212 , V_213 , 0 ) ;
if ( V_28 < 0 ) {
F_45 ( L_24 , V_28 ) ;
goto V_222;
}
V_28 = F_131 ( V_216 , V_205 , & V_214 ) ;
if ( V_28 < 0 ) {
F_45 ( L_25 , V_28 ) ;
goto V_222;
}
V_28 = 0 ;
if ( V_205 -> V_130 == V_136 ) {
struct V_128 * V_129 = (struct V_128 * ) V_205 ;
V_129 -> V_223 = 0 ;
}
F_45 ( L_26 , V_31 ) ;
V_222:
F_132 ( V_216 ) ;
V_58:
return V_28 ;
}
static int F_133 ( int V_224 , struct V_204 * V_205 , T_4 V_214 )
{
switch ( V_224 ) {
case V_133 :
if ( V_214 < sizeof( V_219 ) )
return - V_74 ;
memcpy ( V_205 , & V_219 ,
sizeof( V_219 ) ) ;
break;
case V_136 :
if ( V_214 < sizeof( V_220 ) )
return - V_74 ;
memcpy ( V_205 , & V_220 ,
sizeof( V_220 ) ) ;
break;
default:
F_45 ( L_27 ,
V_31 ) ;
return - V_221 ;
}
F_45 ( L_28 , V_31 ) ;
return 0 ;
}
int F_134 ( struct V_1 * V_2 , struct V_204 * V_205 , T_4 V_214 )
{
struct V_225 V_117 ;
struct V_204 * V_212 = (struct V_204 * ) & V_117 ;
struct V_39 * V_40 ;
struct V_3 * V_3 ;
T_4 V_213 ;
int V_28 ;
F_75 () ;
V_40 = F_77 ( V_2 -> V_45 ) ;
V_213 = V_40 -> V_118 ;
memcpy ( V_212 , & V_40 -> V_208 , V_213 ) ;
V_3 = F_135 ( V_40 -> V_226 ) ;
F_79 () ;
F_136 ( V_212 , 0 ) ;
V_28 = F_127 ( V_3 , V_212 , V_213 , V_205 , V_214 ) ;
F_137 ( V_3 ) ;
if ( V_28 != 0 )
return F_133 ( V_212 -> V_130 , V_205 , V_214 ) ;
return 0 ;
}
void
F_138 ( struct V_1 * V_2 , unsigned int V_227 , unsigned int V_228 )
{
struct V_39 * V_40 ;
F_75 () ;
V_40 = F_77 ( V_2 -> V_45 ) ;
if ( V_40 -> V_229 -> V_230 )
V_40 -> V_229 -> V_230 ( V_40 , V_227 , V_228 ) ;
F_79 () ;
}
int F_139 ( struct V_1 * V_2 )
{
int V_113 ;
F_75 () ;
V_113 = F_77 ( V_2 -> V_45 ) -> V_231 ;
F_79 () ;
return V_113 ;
}
struct V_3 * F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_152 ;
F_75 () ;
V_152 = F_77 ( V_2 -> V_45 ) -> V_226 ;
F_79 () ;
return V_152 ;
}
T_4 F_140 ( struct V_1 * V_2 )
{
T_4 V_152 ;
F_75 () ;
V_152 = F_77 ( V_2 -> V_45 ) -> V_232 ;
F_79 () ;
return V_152 ;
}
unsigned long F_141 ( struct V_1 * V_2 )
{
unsigned long V_152 ;
F_75 () ;
V_152 = F_77 ( V_2 -> V_45 ) -> V_42 -> V_96 ;
F_79 () ;
return V_152 ;
}
void F_142 ( struct V_1 * V_2 )
{
if ( V_2 -> V_46 ) {
F_75 () ;
F_143 ( F_77 ( V_2 -> V_45 ) ) ;
F_79 () ;
}
}
int
F_144 ( struct V_153 * V_162 )
{
if ( F_145 ( V_162 ) )
return 0 ;
V_162 -> V_180 = V_203 ;
V_162 -> V_187 = 0 ;
if ( V_162 -> V_189 -> V_233 != NULL )
V_162 -> V_180 = V_234 ;
return 1 ;
}
int
F_146 ( struct V_153 * V_162 )
{
if ( F_145 ( V_162 ) )
return 0 ;
V_162 -> V_180 = V_203 ;
V_162 -> V_187 = 0 ;
return 1 ;
}
const char
* F_147 ( const struct V_153 * V_162 )
{
const struct V_235 * V_236 = V_162 -> V_172 . V_173 ;
if ( V_236 ) {
if ( V_236 -> V_237 )
return V_236 -> V_237 ;
else
return L_29 ;
} else
return L_30 ;
}
static void
V_203 ( struct V_153 * V_162 )
{
struct V_1 * V_2 = V_162 -> V_163 ;
F_45 ( L_31 , V_162 -> V_238 ,
V_2 -> V_16 -> V_18 , V_2 -> V_86 ,
F_147 ( V_162 ) ,
( F_148 ( V_162 ) ? L_32 : L_33 ) ) ;
V_162 -> V_172 . V_173 -> V_239 ++ ;
V_2 -> V_87 -> V_240 ++ ;
V_162 -> V_180 = V_241 ;
}
static void
V_241 ( struct V_153 * V_162 )
{
F_149 ( V_162 ) ;
V_162 -> V_187 = 0 ;
V_162 -> V_180 = V_242 ;
F_150 ( V_162 ) ;
}
static void
V_242 ( struct V_153 * V_162 )
{
int V_184 = V_162 -> V_187 ;
F_149 ( V_162 ) ;
V_162 -> V_187 = 0 ;
if ( V_184 >= 0 ) {
if ( V_162 -> V_196 ) {
V_162 -> V_180 = V_243 ;
return;
}
F_20 ( V_30 L_34 ,
V_31 , V_184 ) ;
F_95 ( V_162 , - V_157 ) ;
return;
}
if ( V_162 -> V_196 ) {
F_20 ( V_30 L_35 ,
V_31 , V_184 ) ;
F_151 ( V_162 ) ;
}
switch ( V_184 ) {
case - V_77 :
F_152 ( V_162 , V_160 >> 2 ) ;
case - V_150 :
V_162 -> V_180 = V_244 ;
return;
case - V_157 :
break;
default:
F_20 ( V_30 L_36 ,
V_31 , V_184 ) ;
break;
}
F_95 ( V_162 , V_184 ) ;
}
static void
V_244 ( struct V_153 * V_162 )
{
F_149 ( V_162 ) ;
V_162 -> V_187 = 0 ;
V_162 -> V_180 = V_242 ;
F_153 ( V_162 ) ;
}
static void
V_243 ( struct V_153 * V_162 )
{
F_149 ( V_162 ) ;
V_162 -> V_180 = V_245 ;
V_162 -> V_187 = 0 ;
V_162 -> V_163 -> V_87 -> V_246 ++ ;
F_154 ( V_162 ) ;
}
static void
V_245 ( struct V_153 * V_162 )
{
int V_184 = V_162 -> V_187 ;
F_149 ( V_162 ) ;
V_162 -> V_187 = 0 ;
V_162 -> V_180 = V_243 ;
switch ( V_184 ) {
case 0 :
if ( F_155 ( V_162 ) ) {
V_162 -> V_180 = V_247 ;
return;
}
case - V_248 :
F_152 ( V_162 , 3 * V_160 ) ;
case - V_150 :
V_184 = - V_249 ;
case - V_250 :
if ( ! V_162 -> V_251 )
break;
V_162 -> V_251 -- ;
F_45 ( L_37 ,
V_162 -> V_238 , V_31 ) ;
return;
}
F_45 ( L_38 ,
V_162 -> V_238 , V_31 , V_184 ) ;
F_95 ( V_162 , V_184 ) ;
}
static void
V_247 ( struct V_153 * V_162 )
{
unsigned int V_252 = V_162 -> V_196 -> V_253 -> V_254 -> V_255 ;
struct V_190 * V_191 = V_162 -> V_196 ;
struct V_39 * V_40 = V_191 -> V_256 ;
struct V_235 * V_236 = V_162 -> V_172 . V_173 ;
F_149 ( V_162 ) ;
V_162 -> V_187 = 0 ;
V_162 -> V_180 = V_257 ;
if ( V_191 -> V_258 )
return;
if ( V_236 -> V_259 != 0 ) {
F_156 ( V_236 -> V_260 == 0 ) ;
if ( V_236 -> V_261 != NULL )
F_156 ( V_236 -> V_262 == 0 ) ;
}
V_191 -> V_263 = V_264 + ( V_252 << 1 ) + V_236 -> V_260 ;
V_191 -> V_263 <<= 2 ;
V_191 -> V_265 = V_266 + V_252 + V_236 -> V_262 ;
V_191 -> V_265 <<= 2 ;
V_191 -> V_258 = V_40 -> V_229 -> V_267 ( V_162 ,
V_191 -> V_263 + V_191 -> V_265 ) ;
if ( V_191 -> V_258 != NULL )
return;
F_157 ( V_40 ) ;
F_45 ( L_39 , V_162 -> V_238 ) ;
if ( F_148 ( V_162 ) || ! F_158 ( V_268 ) ) {
V_162 -> V_180 = V_247 ;
F_152 ( V_162 , V_160 >> 4 ) ;
return;
}
F_95 ( V_162 , - V_269 ) ;
}
static inline int
F_159 ( struct V_153 * V_162 )
{
return V_162 -> V_196 -> V_194 . V_197 == 0 ;
}
static inline void
F_160 ( struct V_153 * V_162 )
{
V_162 -> V_196 -> V_194 . V_197 = 0 ;
V_162 -> V_196 -> V_270 = 0 ;
}
static inline void
F_161 ( struct V_192 * V_205 , void * V_271 , T_4 V_197 )
{
V_205 -> V_198 [ 0 ] . V_272 = V_271 ;
V_205 -> V_198 [ 0 ] . V_199 = V_197 ;
V_205 -> V_201 [ 0 ] . V_199 = 0 ;
V_205 -> V_200 = 0 ;
V_205 -> V_99 = 0 ;
V_205 -> V_197 = 0 ;
V_205 -> V_214 = V_197 ;
}
static void
F_162 ( struct V_153 * V_162 )
{
struct V_190 * V_191 = V_162 -> V_196 ;
T_5 V_273 ;
T_6 * V_274 ;
F_149 ( V_162 ) ;
F_161 ( & V_191 -> V_194 ,
V_191 -> V_258 ,
V_191 -> V_263 ) ;
F_161 ( & V_191 -> V_275 ,
( char * ) V_191 -> V_258 + V_191 -> V_263 ,
V_191 -> V_265 ) ;
V_274 = F_163 ( V_162 ) ;
if ( V_274 == NULL ) {
F_20 ( V_21 L_40 ) ;
F_95 ( V_162 , - V_157 ) ;
return;
}
V_273 = V_162 -> V_172 . V_173 -> V_276 ;
if ( V_273 == NULL )
return;
V_162 -> V_187 = F_164 ( V_162 , V_273 , V_191 , V_274 ,
V_162 -> V_172 . V_174 ) ;
}
static void
V_257 ( struct V_153 * V_162 )
{
struct V_39 * V_40 = V_162 -> V_196 -> V_256 ;
F_149 ( V_162 ) ;
V_162 -> V_180 = V_277 ;
if ( ! F_38 ( V_40 ) ) {
V_162 -> V_180 = V_278 ;
V_162 -> V_279 = V_40 -> V_280 ;
V_40 -> V_229 -> V_281 ( V_162 ) ;
}
}
static void
V_278 ( struct V_153 * V_162 )
{
int V_184 = - V_157 ;
if ( V_162 -> V_187 >= 0 ) {
F_149 ( V_162 ) ;
V_162 -> V_187 = 0 ;
V_162 -> V_180 = V_277 ;
return;
}
F_165 ( V_162 ) ;
switch ( V_162 -> V_187 ) {
case - V_77 :
F_45 ( L_41 , V_162 -> V_238 ) ;
F_152 ( V_162 , V_160 >> 2 ) ;
goto V_282;
case - V_249 :
F_45 ( L_42
L_43 , V_162 -> V_238 ) ;
if ( V_162 -> V_172 . V_173 -> V_259 == 0 ) {
V_184 = - V_283 ;
break;
}
if ( V_162 -> V_284 == 0 )
break;
V_162 -> V_284 -- ;
F_152 ( V_162 , 3 * V_160 ) ;
goto V_282;
case - V_248 :
F_45 ( L_44 ,
V_162 -> V_238 ) ;
goto V_282;
case - V_285 :
F_45 ( L_45 ,
V_162 -> V_238 ) ;
break;
case - V_286 :
F_45 ( L_46 ,
V_162 -> V_238 ) ;
goto V_282;
case - V_287 :
case - V_288 :
case - V_289 :
case - V_290 :
case - V_291 :
case - V_292 :
case - V_293 :
case - V_294 :
case - V_295 :
F_45 ( L_47 ,
V_162 -> V_238 , V_162 -> V_187 ) ;
if ( ! F_166 ( V_162 ) ) {
F_152 ( V_162 , 5 * V_160 ) ;
goto V_282;
}
V_184 = V_162 -> V_187 ;
break;
default:
F_45 ( L_48 ,
V_162 -> V_238 , - V_162 -> V_187 ) ;
}
F_95 ( V_162 , V_184 ) ;
return;
V_282:
V_162 -> V_187 = 0 ;
V_162 -> V_180 = V_296 ;
}
static void
V_277 ( struct V_153 * V_162 )
{
struct V_39 * V_40 = V_162 -> V_196 -> V_256 ;
F_45 ( L_49 ,
V_162 -> V_238 , V_40 ,
( F_167 ( V_40 ) ? L_50 : L_51 ) ) ;
V_162 -> V_180 = V_297 ;
if ( ! F_167 ( V_40 ) ) {
V_162 -> V_180 = V_298 ;
if ( V_162 -> V_187 < 0 )
return;
if ( V_162 -> V_155 & V_299 ) {
F_95 ( V_162 , - V_290 ) ;
return;
}
F_168 ( V_162 ) ;
}
}
static void
V_298 ( struct V_153 * V_162 )
{
struct V_1 * V_2 = V_162 -> V_163 ;
int V_184 = V_162 -> V_187 ;
F_149 ( V_162 ) ;
F_169 ( V_162 , V_184 ) ;
V_162 -> V_187 = 0 ;
switch ( V_184 ) {
case - V_287 :
case - V_288 :
case - V_289 :
case - V_293 :
case - V_292 :
case - V_300 :
case - V_294 :
case - V_295 :
if ( F_166 ( V_162 ) )
break;
F_152 ( V_162 , 3 * V_160 ) ;
case - V_150 :
case - V_248 :
V_162 -> V_180 = V_296 ;
return;
case 0 :
V_2 -> V_87 -> V_301 ++ ;
V_162 -> V_180 = V_297 ;
return;
}
F_95 ( V_162 , V_184 ) ;
}
static void
V_297 ( struct V_153 * V_162 )
{
int V_302 = F_170 ( V_162 ) ;
F_149 ( V_162 ) ;
V_162 -> V_180 = V_303 ;
if ( V_162 -> V_187 < 0 )
return;
if ( ! F_171 ( V_162 ) )
return;
V_162 -> V_180 = V_304 ;
if ( F_159 ( V_162 ) ) {
F_162 ( V_162 ) ;
if ( V_162 -> V_187 != 0 ) {
if ( V_162 -> V_187 == - V_150 )
F_152 ( V_162 , V_160 >> 4 ) ;
else
F_95 ( V_162 , V_162 -> V_187 ) ;
return;
}
}
F_172 ( V_162 ) ;
if ( V_162 -> V_187 < 0 )
return;
if ( V_302 )
V_162 -> V_163 -> V_87 -> V_305 ++ ;
V_304 ( V_162 ) ;
if ( F_173 ( V_162 ) )
return;
V_162 -> V_180 = V_306 ;
F_97 ( & V_162 -> V_196 -> V_256 -> V_307 , V_162 ) ;
}
static void
V_304 ( struct V_153 * V_162 )
{
V_162 -> V_180 = V_303 ;
if ( V_162 -> V_187 == 0 ) {
F_174 ( V_162 ) ;
F_160 ( V_162 ) ;
return;
}
switch ( V_162 -> V_187 ) {
case - V_150 :
case - V_294 :
break;
default:
F_149 ( V_162 ) ;
F_174 ( V_162 ) ;
F_160 ( V_162 ) ;
break;
case - V_287 :
case - V_291 :
case - V_292 :
case - V_293 :
case - V_308 :
if ( F_166 ( V_162 ) ) {
F_174 ( V_162 ) ;
F_95 ( V_162 , V_162 -> V_187 ) ;
break;
}
case - V_288 :
case - V_289 :
case - V_300 :
case - V_290 :
case - V_295 :
F_160 ( V_162 ) ;
}
}
static void
V_202 ( struct V_153 * V_162 )
{
struct V_190 * V_191 = V_162 -> V_196 ;
if ( ! F_171 ( V_162 ) )
goto V_309;
if ( V_162 -> V_187 < 0 ) {
F_20 ( V_310 L_52
L_53 , V_162 -> V_187 ) ;
goto V_311;
}
if ( V_191 -> V_312 != V_191 -> V_256 -> V_313 )
V_191 -> V_270 = 0 ;
F_172 ( V_162 ) ;
if ( V_162 -> V_187 == - V_150 )
goto V_314;
F_174 ( V_162 ) ;
F_149 ( V_162 ) ;
switch ( V_162 -> V_187 ) {
case 0 :
case - V_291 :
case - V_292 :
case - V_293 :
case - V_288 :
case - V_287 :
case - V_300 :
case - V_290 :
case - V_295 :
break;
case - V_248 :
F_20 ( V_310 L_52
L_53 , V_162 -> V_187 ) ;
F_175 ( V_191 -> V_256 ,
V_191 -> V_312 ) ;
break;
default:
F_119 ( V_162 -> V_187 == - V_150 ) ;
F_20 ( V_310 L_52
L_53 , V_162 -> V_187 ) ;
break;
}
F_97 ( & V_191 -> V_256 -> V_307 , V_162 ) ;
V_311:
V_162 -> V_180 = V_306 ;
return;
V_314:
V_191 -> V_312 = V_191 -> V_256 -> V_313 ;
V_309:
V_162 -> V_187 = 0 ;
}
static void
V_303 ( struct V_153 * V_162 )
{
struct V_1 * V_2 = V_162 -> V_163 ;
struct V_190 * V_191 = V_162 -> V_196 ;
int V_184 ;
if ( V_191 -> V_315 > 0 && ! V_191 -> V_270 )
V_162 -> V_187 = V_191 -> V_315 ;
F_149 ( V_162 ) ;
V_184 = V_162 -> V_187 ;
if ( V_184 >= 0 ) {
V_162 -> V_180 = V_316 ;
return;
}
F_176 ( V_162 ) ;
V_162 -> V_187 = 0 ;
switch( V_184 ) {
case - V_291 :
case - V_292 :
case - V_293 :
case - V_308 :
if ( F_166 ( V_162 ) ) {
F_95 ( V_162 , V_184 ) ;
break;
}
F_152 ( V_162 , 3 * V_160 ) ;
case - V_248 :
V_162 -> V_180 = V_296 ;
if ( ! ( V_162 -> V_155 & V_167 )
&& V_162 -> V_163 -> V_107 )
F_175 ( V_191 -> V_256 ,
V_191 -> V_312 ) ;
break;
case - V_287 :
case - V_288 :
case - V_289 :
F_142 ( V_2 ) ;
case - V_300 :
F_152 ( V_162 , 3 * V_160 ) ;
case - V_295 :
case - V_290 :
V_162 -> V_180 = V_257 ;
break;
case - V_294 :
F_152 ( V_162 , V_160 >> 2 ) ;
case - V_150 :
V_162 -> V_180 = V_297 ;
break;
case - V_157 :
F_95 ( V_162 , V_184 ) ;
break;
default:
if ( V_2 -> V_109 )
F_20 ( L_54 ,
V_2 -> V_16 -> V_18 , - V_184 ) ;
F_95 ( V_162 , V_184 ) ;
}
}
static void
V_296 ( struct V_153 * V_162 )
{
struct V_1 * V_2 = V_162 -> V_163 ;
if ( F_177 ( V_162 -> V_196 ) == 0 ) {
F_45 ( L_55 , V_162 -> V_238 ) ;
goto V_317;
}
F_45 ( L_56 , V_162 -> V_238 ) ;
V_162 -> V_318 ++ ;
if ( F_166 ( V_162 ) ) {
F_95 ( V_162 , - V_248 ) ;
return;
}
if ( F_178 ( V_162 ) ) {
if ( V_2 -> V_109 ) {
F_20 ( V_310 L_57 ,
V_2 -> V_16 -> V_18 ,
V_162 -> V_164 -> V_72 ) ;
}
if ( V_162 -> V_155 & V_319 )
F_95 ( V_162 , - V_248 ) ;
else
F_95 ( V_162 , - V_157 ) ;
return;
}
if ( ! ( V_162 -> V_155 & V_320 ) ) {
V_162 -> V_155 |= V_320 ;
if ( V_2 -> V_109 ) {
F_20 ( V_310 L_58 ,
V_2 -> V_16 -> V_18 ,
V_162 -> V_164 -> V_72 ) ;
}
}
F_142 ( V_2 ) ;
F_179 ( V_162 ) ;
V_317:
V_162 -> V_180 = V_257 ;
V_162 -> V_187 = 0 ;
}
static void
V_316 ( struct V_153 * V_162 )
{
struct V_1 * V_2 = V_162 -> V_163 ;
struct V_190 * V_191 = V_162 -> V_196 ;
T_7 V_321 = V_162 -> V_172 . V_173 -> V_261 ;
T_6 * V_274 ;
F_149 ( V_162 ) ;
if ( V_162 -> V_155 & V_320 ) {
if ( V_2 -> V_109 ) {
F_20 ( V_310 L_59 ,
V_2 -> V_16 -> V_18 ,
V_162 -> V_164 -> V_72 ) ;
}
V_162 -> V_155 &= ~ V_320 ;
}
F_180 () ;
V_191 -> V_275 . V_197 = V_191 -> V_322 . V_197 ;
F_181 ( memcmp ( & V_191 -> V_275 , & V_191 -> V_322 ,
sizeof( V_191 -> V_275 ) ) != 0 ) ;
if ( V_191 -> V_275 . V_197 < 12 ) {
if ( ! F_178 ( V_162 ) ) {
V_162 -> V_180 = V_257 ;
goto V_309;
}
F_45 ( L_60 ,
V_2 -> V_16 -> V_18 , V_162 -> V_187 ) ;
V_162 -> V_180 = V_296 ;
goto V_309;
}
V_274 = F_182 ( V_162 ) ;
if ( F_18 ( V_274 ) ) {
if ( V_274 == F_19 ( - V_150 ) )
goto V_309;
return;
}
V_162 -> V_180 = V_306 ;
if ( V_321 ) {
V_162 -> V_187 = F_183 ( V_162 , V_321 , V_191 , V_274 ,
V_162 -> V_172 . V_175 ) ;
}
F_45 ( L_61 , V_162 -> V_238 ,
V_162 -> V_187 ) ;
return;
V_309:
V_162 -> V_187 = 0 ;
if ( V_162 -> V_196 == V_191 ) {
V_191 -> V_315 = V_191 -> V_275 . V_197 = 0 ;
if ( V_162 -> V_163 -> V_107 )
F_175 ( V_191 -> V_256 ,
V_191 -> V_312 ) ;
}
}
static T_6 *
F_163 ( struct V_153 * V_162 )
{
struct V_1 * V_2 = V_162 -> V_163 ;
struct V_190 * V_191 = V_162 -> V_196 ;
T_6 * V_274 = V_191 -> V_323 [ 0 ] . V_272 ;
V_274 = F_184 ( V_191 -> V_256 , V_274 ) ;
* V_274 ++ = V_191 -> V_324 ;
* V_274 ++ = F_185 ( V_325 ) ;
* V_274 ++ = F_185 ( V_326 ) ;
* V_274 ++ = F_185 ( V_2 -> V_83 ) ;
* V_274 ++ = F_185 ( V_2 -> V_86 ) ;
* V_274 ++ = F_185 ( V_162 -> V_172 . V_173 -> V_259 ) ;
V_274 = F_186 ( V_162 , V_274 ) ;
V_191 -> V_327 = F_187 ( & V_191 -> V_323 [ 0 ] , V_274 ) ;
return V_274 ;
}
static T_6 *
F_182 ( struct V_153 * V_162 )
{
struct V_1 * V_2 = V_162 -> V_163 ;
struct V_328 * V_329 = & V_162 -> V_196 -> V_275 . V_198 [ 0 ] ;
int V_197 = V_162 -> V_196 -> V_275 . V_197 >> 2 ;
T_6 * V_274 = V_329 -> V_272 ;
T_3 V_330 ;
int error = - V_249 ;
if ( ( V_162 -> V_196 -> V_275 . V_197 & 3 ) != 0 ) {
F_45 ( L_62
L_63 , V_162 -> V_238 , V_31 ,
V_162 -> V_196 -> V_275 . V_197 ) ;
error = - V_157 ;
goto V_76;
}
if ( ( V_197 -= 3 ) < 0 )
goto V_331;
V_274 += 1 ;
if ( ( V_330 = F_188 ( * V_274 ++ ) ) != V_332 ) {
F_45 ( L_64 ,
V_162 -> V_238 , V_31 , V_330 ) ;
error = - V_157 ;
goto V_333;
}
if ( ( V_330 = F_188 ( * V_274 ++ ) ) != V_334 ) {
if ( -- V_197 < 0 )
goto V_331;
switch ( ( V_330 = F_188 ( * V_274 ++ ) ) ) {
case V_335 :
break;
case V_336 :
F_45 ( L_65 ,
V_162 -> V_238 , V_31 ) ;
error = - V_286 ;
goto V_76;
default:
F_45 ( L_66
L_67 ,
V_162 -> V_238 , V_31 , V_330 ) ;
error = - V_157 ;
goto V_76;
}
if ( -- V_197 < 0 )
goto V_331;
switch ( ( V_330 = F_188 ( * V_274 ++ ) ) ) {
case V_337 :
case V_338 :
case V_339 :
case V_340 :
if ( ! V_162 -> V_251 )
break;
V_162 -> V_251 -- ;
F_45 ( L_68 ,
V_162 -> V_238 , V_31 ) ;
F_179 ( V_162 ) ;
F_151 ( V_162 ) ;
V_162 -> V_180 = V_241 ;
goto V_309;
case V_341 :
case V_342 :
if ( ! V_162 -> V_343 )
break;
V_162 -> V_343 -- ;
F_45 ( L_69 ,
V_162 -> V_238 , V_31 ) ;
V_162 -> V_180 = V_257 ;
goto V_309;
case V_344 :
F_20 ( V_310 L_70
L_71 ,
V_162 -> V_164 -> V_72 ) ;
break;
default:
F_45 ( L_72 ,
V_162 -> V_238 , V_31 , V_330 ) ;
error = - V_157 ;
}
F_45 ( L_73 ,
V_162 -> V_238 , V_31 , V_330 ) ;
goto V_76;
}
V_274 = F_189 ( V_162 , V_274 ) ;
if ( F_18 ( V_274 ) ) {
error = F_21 ( V_274 ) ;
F_45 ( L_74 ,
V_162 -> V_238 , V_31 , error ) ;
goto V_333;
}
V_197 = V_274 - ( T_6 * ) V_329 -> V_272 - 1 ;
if ( V_197 < 0 )
goto V_331;
switch ( ( V_330 = F_188 ( * V_274 ++ ) ) ) {
case V_345 :
return V_274 ;
case V_346 :
F_45 ( L_75
L_76 , V_162 -> V_238 , V_31 ,
( unsigned int ) V_2 -> V_83 ,
V_162 -> V_164 -> V_72 ) ;
error = - V_285 ;
goto V_76;
case V_347 :
F_45 ( L_77
L_76 , V_162 -> V_238 , V_31 ,
( unsigned int ) V_2 -> V_83 ,
( unsigned int ) V_2 -> V_86 ,
V_162 -> V_164 -> V_72 ) ;
error = - V_286 ;
goto V_76;
case V_348 :
F_45 ( L_78
L_79 ,
V_162 -> V_238 , V_31 ,
F_147 ( V_162 ) ,
V_2 -> V_83 , V_2 -> V_86 ,
V_162 -> V_164 -> V_72 ) ;
error = - V_283 ;
goto V_76;
case V_349 :
F_45 ( L_80 ,
V_162 -> V_238 , V_31 ) ;
break;
default:
F_45 ( L_81 ,
V_162 -> V_238 , V_31 , V_330 ) ;
}
V_333:
V_2 -> V_87 -> V_350 ++ ;
if ( V_162 -> V_343 ) {
V_162 -> V_343 -- ;
F_45 ( L_82 ,
V_162 -> V_238 , V_31 ) ;
V_162 -> V_180 = V_257 ;
V_309:
return F_19 ( - V_150 ) ;
}
V_76:
F_95 ( V_162 , error ) ;
F_45 ( L_83 , V_162 -> V_238 ,
V_31 , error ) ;
return F_19 ( error ) ;
V_331:
F_45 ( L_84 , V_162 -> V_238 ,
V_31 ) ;
goto V_333;
}
static void F_190 ( void * V_351 , struct V_352 * V_353 , void * V_354 )
{
}
static int F_191 ( void * V_351 , struct V_352 * V_353 , void * V_354 )
{
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_170 V_171 = {
. V_173 = & V_355 ,
} ;
int V_28 ;
V_171 . V_176 = V_356 . V_357 ( NULL , NULL , 0 ) ;
V_28 = F_118 ( V_2 , & V_171 , V_166 | V_195 ) ;
F_192 ( V_171 . V_176 ) ;
return V_28 ;
}
static
struct V_153 * F_193 ( struct V_1 * V_2 ,
struct V_39 * V_40 , struct V_176 * V_358 , int V_99 ,
const struct V_188 * V_229 , void * V_151 )
{
struct V_170 V_171 = {
. V_173 = & V_355 ,
. V_176 = V_358 ,
} ;
struct V_177 V_178 = {
. V_179 = V_2 ,
. V_39 = V_40 ,
. V_170 = & V_171 ,
. V_182 = ( V_229 != NULL ) ? V_229 : & V_183 ,
. V_186 = V_151 ,
. V_99 = V_99 ,
} ;
return F_114 ( & V_178 ) ;
}
struct V_153 * F_194 ( struct V_1 * V_2 , struct V_176 * V_358 , int V_99 )
{
return F_193 ( V_2 , NULL , V_358 , V_99 , NULL , NULL ) ;
}
static void F_195 ( struct V_153 * V_162 , void * V_359 )
{
struct V_360 * V_151 = V_359 ;
if ( V_162 -> V_187 == 0 )
F_196 ( V_151 -> V_66 , V_151 -> V_40 ) ;
}
static void F_197 ( void * V_359 )
{
struct V_360 * V_151 = V_359 ;
F_67 ( V_151 -> V_40 ) ;
F_59 ( V_151 -> V_66 ) ;
F_65 ( V_151 ) ;
}
int F_198 ( struct V_1 * V_2 ,
struct V_65 * V_66 , struct V_39 * V_40 ,
void * V_361 )
{
struct V_360 * V_151 ;
struct V_176 * V_358 ;
struct V_153 * V_162 ;
V_151 = F_199 ( sizeof( * V_151 ) , V_362 ) ;
if ( ! V_151 )
return - V_77 ;
V_151 -> V_66 = F_78 ( V_66 ) ;
V_151 -> V_40 = F_76 ( V_40 ) ;
V_358 = V_356 . V_357 ( NULL , NULL , 0 ) ;
V_162 = F_193 ( V_2 , V_40 , V_358 ,
V_166 | V_195 | V_185 ,
& V_363 , V_151 ) ;
F_192 ( V_358 ) ;
if ( F_18 ( V_162 ) )
return F_21 ( V_162 ) ;
F_121 ( V_162 ) ;
return 1 ;
}
int F_200 ( struct V_1 * V_2 ,
struct V_110 * V_111 ,
int (* F_201)( struct V_1 * ,
struct V_65 * ,
struct V_39 * ,
void * ) ,
void * V_151 )
{
struct V_65 * V_66 ;
struct V_39 * V_40 ;
unsigned char V_138 ;
int V_152 = 0 ;
F_75 () ;
V_66 = F_78 ( F_77 ( V_2 -> V_93 . V_141 ) ) ;
V_40 = F_202 ( & V_2 -> V_93 ) ;
if ( V_66 == NULL || V_40 == NULL ) {
F_79 () ;
return - V_150 ;
}
V_138 = V_40 -> V_138 ;
F_79 () ;
V_40 = F_73 ( V_111 ) ;
if ( F_18 ( V_40 ) ) {
V_152 = F_21 ( V_40 ) ;
goto V_364;
}
V_40 -> V_138 = V_138 ;
F_203 ( V_66 ) ;
if ( F_201 ) {
V_152 = F_201 ( V_2 , V_66 , V_40 , V_151 ) ;
if ( V_152 != 0 )
goto V_365;
}
F_196 ( V_66 , V_40 ) ;
V_365:
F_67 ( V_40 ) ;
V_364:
F_59 ( V_66 ) ;
return V_152 ;
}
static void F_204 ( void )
{
F_20 ( V_21 L_85
L_86 ) ;
}
static void F_205 ( const struct V_1 * V_2 ,
const struct V_153 * V_162 )
{
const char * V_366 = L_87 ;
if ( F_96 ( V_162 ) )
V_366 = F_206 ( V_162 -> V_158 ) ;
F_20 ( V_21 L_88 ,
V_162 -> V_238 , V_162 -> V_155 , V_162 -> V_187 ,
V_2 , V_162 -> V_196 , V_162 -> V_279 , V_162 -> V_189 ,
V_2 -> V_16 -> V_18 , V_2 -> V_86 , F_147 ( V_162 ) ,
V_162 -> V_180 , V_366 ) ;
}
void F_207 ( struct V_3 * V_3 )
{
struct V_1 * V_2 ;
struct V_153 * V_162 ;
int V_367 = 0 ;
struct V_4 * V_5 = F_3 ( V_3 , V_6 ) ;
F_4 ( & V_5 -> V_7 ) ;
F_29 (clnt, &sn->all_clients, cl_clients) {
F_4 ( & V_2 -> V_44 ) ;
F_29 (task, &clnt->cl_tasks, tk_task) {
if ( ! V_367 ) {
F_204 () ;
V_367 ++ ;
}
F_205 ( V_2 , V_162 ) ;
}
F_6 ( & V_2 -> V_44 ) ;
}
F_6 ( & V_5 -> V_7 ) ;
}
static int
F_208 ( struct V_1 * V_2 ,
struct V_39 * V_40 ,
void * V_361 )
{
return F_209 ( V_40 ) ;
}
int
F_210 ( struct V_1 * V_2 )
{
if ( F_211 ( & V_2 -> V_168 ) == 1 )
return F_88 ( V_2 ,
F_208 , NULL ) ;
return 0 ;
}
static int
F_212 ( struct V_1 * V_2 ,
struct V_39 * V_40 ,
void * V_361 )
{
F_213 ( V_40 ) ;
return 0 ;
}
void
F_214 ( struct V_1 * V_2 )
{
if ( F_215 ( & V_2 -> V_168 ) == 0 )
F_88 ( V_2 ,
F_212 , NULL ) ;
}
