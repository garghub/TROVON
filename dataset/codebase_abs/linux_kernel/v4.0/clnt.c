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
struct V_39 * V_40 ,
struct V_1 * V_65 )
{
const struct V_66 * V_67 = args -> V_67 ;
const struct V_68 * V_69 ;
struct V_1 * V_2 = NULL ;
const struct V_41 * V_42 ;
const char * V_48 = args -> V_48 ;
int V_28 ;
F_45 ( L_7 ,
V_67 -> V_18 , args -> V_70 , V_40 ) ;
V_28 = F_52 () ;
if ( V_28 )
goto V_71;
V_28 = - V_72 ;
if ( args -> V_69 >= V_67 -> V_73 )
goto V_74;
V_69 = V_67 -> V_69 [ args -> V_69 ] ;
if ( V_69 == NULL )
goto V_74;
V_28 = - V_75 ;
V_2 = F_53 ( sizeof( * V_2 ) , V_62 ) ;
if ( ! V_2 )
goto V_74;
V_2 -> V_33 = V_65 ? : V_2 ;
V_28 = F_47 ( V_2 ) ;
if ( V_28 )
goto V_76;
V_2 -> V_77 = V_69 -> V_78 ;
V_2 -> V_79 = V_69 -> V_80 ;
V_2 -> V_81 = args -> V_82 ? : V_67 -> V_83 ;
V_2 -> V_84 = V_69 -> V_83 ;
V_2 -> V_85 = V_67 -> V_86 ;
V_2 -> V_87 = F_54 ( V_2 ) ;
F_55 ( & V_2 -> V_24 ) ;
V_28 = - V_75 ;
if ( V_2 -> V_87 == NULL )
goto V_88;
V_2 -> V_16 = V_67 ;
F_56 ( & V_2 -> V_89 ) ;
F_57 ( & V_2 -> V_44 ) ;
V_42 = V_40 -> V_42 ;
if ( args -> V_42 != NULL ) {
memcpy ( & V_2 -> V_90 , args -> V_42 ,
sizeof( V_2 -> V_90 ) ) ;
V_42 = & V_2 -> V_90 ;
}
F_35 ( V_2 , V_40 , V_42 ) ;
V_2 -> V_91 = & V_2 -> V_92 ;
F_58 ( & V_2 -> V_92 , V_2 -> V_47 -> V_93 ) ;
F_59 ( & V_2 -> V_26 , 1 ) ;
if ( V_48 == NULL )
V_48 = F_60 () -> V_48 ;
F_40 ( V_2 , V_48 ) ;
V_28 = F_42 ( V_2 , args -> V_94 , args -> V_52 ) ;
if ( V_28 )
goto V_95;
if ( V_65 )
F_61 ( & V_65 -> V_26 ) ;
return V_2 ;
V_95:
F_62 ( V_2 -> V_87 ) ;
V_88:
F_49 ( V_2 ) ;
V_76:
F_63 ( V_2 ) ;
V_74:
F_64 () ;
V_71:
F_65 ( V_40 ) ;
return F_19 ( V_28 ) ;
}
struct V_1 * F_66 ( struct V_64 * args ,
struct V_39 * V_40 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_51 ( args , V_40 , NULL ) ;
if ( F_18 ( V_2 ) )
return V_2 ;
if ( ! ( args -> V_96 & V_97 ) ) {
int V_28 = F_67 ( V_2 ) ;
if ( V_28 != 0 ) {
F_68 ( V_2 ) ;
return F_19 ( V_28 ) ;
}
}
V_2 -> V_98 = 1 ;
if ( args -> V_96 & V_99 )
V_2 -> V_98 = 0 ;
if ( args -> V_96 & V_100 )
V_2 -> V_46 = 1 ;
if ( args -> V_96 & V_101 )
V_2 -> V_102 = 1 ;
if ( args -> V_96 & V_103 )
V_2 -> V_104 = 1 ;
if ( ! ( args -> V_96 & V_105 ) )
V_2 -> V_106 = 1 ;
return V_2 ;
}
struct V_1 * F_69 ( struct V_64 * args )
{
struct V_39 * V_40 ;
struct V_107 V_108 = {
. V_3 = args -> V_3 ,
. V_109 = args -> V_110 ,
. V_111 = args -> V_112 ,
. V_113 = args -> V_114 ,
. V_115 = args -> V_116 ,
. V_70 = args -> V_70 ,
. V_117 = args -> V_117 ,
} ;
char V_70 [ 48 ] ;
if ( args -> V_96 & V_118 )
V_108 . V_96 |= V_119 ;
if ( args -> V_96 & V_120 )
V_108 . V_96 |= V_121 ;
if ( V_108 . V_70 == NULL ) {
struct V_122 * V_123 =
(struct V_122 * ) args -> V_114 ;
struct V_124 * sin =
(struct V_124 * ) args -> V_114 ;
struct V_125 * V_126 =
(struct V_125 * ) args -> V_114 ;
V_70 [ 0 ] = '\0' ;
switch ( args -> V_114 -> V_127 ) {
case V_128 :
snprintf ( V_70 , sizeof( V_70 ) , L_8 ,
V_123 -> V_129 ) ;
break;
case V_130 :
snprintf ( V_70 , sizeof( V_70 ) , L_9 ,
& sin -> V_131 . V_132 ) ;
break;
case V_133 :
snprintf ( V_70 , sizeof( V_70 ) , L_10 ,
& V_126 -> V_134 ) ;
break;
default:
return F_19 ( - V_72 ) ;
}
V_108 . V_70 = V_70 ;
}
V_40 = F_70 ( & V_108 ) ;
if ( F_18 ( V_40 ) )
return (struct V_1 * ) V_40 ;
V_40 -> V_135 = 1 ;
if ( args -> V_96 & V_136 )
V_40 -> V_135 = 0 ;
return F_66 ( args , V_40 ) ;
}
static struct V_1 * F_71 ( struct V_64 * args ,
struct V_1 * V_2 )
{
struct V_39 * V_40 ;
struct V_1 * V_137 ;
int V_28 ;
V_28 = - V_75 ;
F_72 () ;
V_40 = F_73 ( F_74 ( V_2 -> V_45 ) ) ;
F_75 () ;
if ( V_40 == NULL )
goto V_74;
args -> V_70 = V_40 -> V_70 ;
args -> V_48 = V_2 -> V_50 ;
V_137 = F_51 ( args , V_40 , V_2 ) ;
if ( F_18 ( V_137 ) ) {
V_28 = F_21 ( V_137 ) ;
goto V_74;
}
V_137 -> V_46 = 0 ;
V_137 -> V_98 = V_2 -> V_98 ;
V_137 -> V_102 = V_2 -> V_102 ;
V_137 -> V_104 = V_2 -> V_104 ;
V_137 -> V_106 = V_2 -> V_106 ;
return V_137 ;
V_74:
F_45 ( L_11 , V_31 , V_28 ) ;
return F_19 ( V_28 ) ;
}
struct V_1 * F_76 ( struct V_1 * V_2 )
{
struct V_64 args = {
. V_67 = V_2 -> V_16 ,
. V_82 = V_2 -> V_81 ,
. V_69 = V_2 -> V_84 ,
. V_94 = V_2 -> V_138 -> V_139 ,
} ;
return F_71 ( & args , V_2 ) ;
}
struct V_1 *
F_77 ( struct V_1 * V_2 , T_2 V_140 )
{
struct V_64 args = {
. V_67 = V_2 -> V_16 ,
. V_82 = V_2 -> V_81 ,
. V_69 = V_2 -> V_84 ,
. V_94 = V_140 ,
} ;
return F_71 ( & args , V_2 ) ;
}
int F_78 ( struct V_1 * V_2 ,
struct V_107 * args ,
const struct V_41 * V_42 )
{
const struct V_41 * V_141 ;
T_2 V_51 ;
struct V_39 * V_40 , * V_43 ;
struct V_1 * V_65 ;
int V_28 ;
V_40 = F_70 ( args ) ;
if ( F_18 ( V_40 ) ) {
F_45 ( L_12 ,
V_2 ) ;
return F_21 ( V_40 ) ;
}
V_51 = V_2 -> V_138 -> V_139 ;
V_141 = V_2 -> V_47 ;
V_43 = F_35 ( V_2 , V_40 , V_42 ) ;
F_7 ( V_2 ) ;
F_9 ( V_2 ) ;
F_46 ( V_2 ) ;
V_65 = V_2 -> V_33 ;
V_2 -> V_33 = V_2 ;
V_28 = F_42 ( V_2 , V_51 , NULL ) ;
if ( V_28 )
goto V_142;
F_79 () ;
if ( V_65 != V_2 )
F_80 ( V_65 ) ;
F_65 ( V_43 ) ;
F_45 ( L_13 , V_2 ) ;
return 0 ;
V_142:
F_35 ( V_2 , V_43 , V_141 ) ;
V_2 -> V_33 = V_65 ;
F_42 ( V_2 , V_51 , NULL ) ;
F_65 ( V_40 ) ;
F_45 ( L_14 , V_2 ) ;
return V_28 ;
}
void F_81 ( struct V_1 * V_2 )
{
struct V_143 * V_144 ;
if ( F_82 ( & V_2 -> V_89 ) )
return;
F_45 ( L_15 , V_2 ) ;
F_4 ( & V_2 -> V_44 ) ;
F_29 (rovr, &clnt->cl_tasks, tk_task) {
if ( ! F_83 ( V_144 ) )
continue;
if ( ! ( V_144 -> V_145 & V_146 ) ) {
V_144 -> V_145 |= V_146 ;
F_84 ( V_144 , - V_147 ) ;
if ( F_85 ( V_144 ) )
F_86 ( V_144 -> V_148 ,
V_144 ) ;
}
}
F_6 ( & V_2 -> V_44 ) ;
}
void F_68 ( struct V_1 * V_2 )
{
F_87 () ;
F_88 ( L_16 ,
V_2 -> V_16 -> V_18 ,
F_74 ( V_2 -> V_45 ) -> V_70 ) ;
while ( ! F_82 ( & V_2 -> V_89 ) ) {
F_81 ( V_2 ) ;
F_89 ( V_149 ,
F_82 ( & V_2 -> V_89 ) , 1 * V_150 ) ;
}
F_80 ( V_2 ) ;
}
static struct V_1 *
F_90 ( struct V_1 * V_2 )
{
struct V_1 * V_65 = NULL ;
F_88 ( L_17 ,
V_2 -> V_16 -> V_18 ,
F_74 ( V_2 -> V_45 ) -> V_70 ) ;
if ( V_2 -> V_33 != V_2 )
V_65 = V_2 -> V_33 ;
F_46 ( V_2 ) ;
F_11 ( V_2 ) ;
F_7 ( V_2 ) ;
F_62 ( V_2 -> V_87 ) ;
V_2 -> V_87 = NULL ;
F_65 ( F_91 ( V_2 -> V_45 ) ) ;
F_64 () ;
F_49 ( V_2 ) ;
F_63 ( V_2 ) ;
return V_65 ;
}
static struct V_1 *
F_92 ( struct V_1 * V_2 )
{
if ( V_2 -> V_138 == NULL )
return F_90 ( V_2 ) ;
F_61 ( & V_2 -> V_26 ) ;
F_93 ( V_2 -> V_138 ) ;
V_2 -> V_138 = NULL ;
if ( F_94 ( & V_2 -> V_26 ) )
return F_90 ( V_2 ) ;
return NULL ;
}
void
F_80 ( struct V_1 * V_2 )
{
F_45 ( L_18 , V_2 ) ;
do {
if ( F_82 ( & V_2 -> V_89 ) )
F_95 ( & V_149 ) ;
if ( ! F_94 ( & V_2 -> V_26 ) )
break;
V_2 = F_92 ( V_2 ) ;
} while ( V_2 != NULL );
}
struct V_1 * F_96 ( struct V_1 * V_43 ,
const struct V_66 * V_67 ,
T_3 V_151 )
{
struct V_64 args = {
. V_67 = V_67 ,
. V_82 = V_67 -> V_83 ,
. V_69 = V_151 ,
. V_94 = V_43 -> V_138 -> V_139 ,
} ;
struct V_1 * V_2 ;
int V_28 ;
V_2 = F_71 ( & args , V_43 ) ;
if ( F_18 ( V_2 ) )
goto V_58;
V_28 = F_67 ( V_2 ) ;
if ( V_28 != 0 ) {
F_68 ( V_2 ) ;
V_2 = F_19 ( V_28 ) ;
}
V_58:
return V_2 ;
}
void F_97 ( struct V_143 * V_152 )
{
struct V_1 * V_2 = V_152 -> V_153 ;
if ( V_2 != NULL ) {
F_4 ( & V_2 -> V_44 ) ;
F_8 ( & V_152 -> V_154 ) ;
F_6 ( & V_2 -> V_44 ) ;
V_152 -> V_153 = NULL ;
F_80 ( V_2 ) ;
}
}
static
void F_98 ( struct V_143 * V_152 , struct V_1 * V_2 )
{
if ( V_2 != NULL ) {
F_97 ( V_152 ) ;
V_152 -> V_153 = V_2 ;
F_61 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_98 )
V_152 -> V_145 |= V_155 ;
if ( V_2 -> V_102 )
V_152 -> V_145 |= V_156 ;
if ( F_99 () ) {
struct V_39 * V_40 ;
F_72 () ;
V_40 = F_74 ( V_2 -> V_45 ) ;
if ( V_40 -> V_157 )
V_152 -> V_145 |= V_158 ;
F_75 () ;
}
F_4 ( & V_2 -> V_44 ) ;
F_100 ( & V_152 -> V_154 , & V_2 -> V_89 ) ;
F_6 ( & V_2 -> V_44 ) ;
}
}
void F_101 ( struct V_143 * V_152 , struct V_1 * V_2 )
{
F_97 ( V_152 ) ;
F_98 ( V_152 , V_2 ) ;
}
static void
F_102 ( struct V_143 * V_152 , const struct V_159 * V_160 )
{
if ( V_160 != NULL ) {
V_152 -> V_161 . V_162 = V_160 -> V_162 ;
V_152 -> V_161 . V_163 = V_160 -> V_163 ;
V_152 -> V_161 . V_164 = V_160 -> V_164 ;
if ( V_160 -> V_165 != NULL )
V_152 -> V_161 . V_165 = F_103 ( V_160 -> V_165 ) ;
}
}
static void
F_104 ( struct V_143 * V_152 , void * V_166 )
{
}
struct V_143 * F_105 ( const struct V_167 * V_168 )
{
struct V_143 * V_152 ;
V_152 = F_106 ( V_168 ) ;
if ( F_18 ( V_152 ) )
goto V_58;
F_98 ( V_152 , V_168 -> V_169 ) ;
F_102 ( V_152 , V_168 -> V_159 ) ;
if ( V_152 -> V_170 == NULL )
F_107 ( V_152 ) ;
F_61 ( & V_152 -> V_171 ) ;
F_108 ( V_152 ) ;
V_58:
return V_152 ;
}
int F_109 ( struct V_1 * V_2 , const struct V_159 * V_160 , int V_96 )
{
struct V_143 * V_152 ;
struct V_167 V_168 = {
. V_169 = V_2 ,
. V_159 = V_160 ,
. V_172 = & V_173 ,
. V_96 = V_96 ,
} ;
int V_174 ;
F_110 ( V_96 & V_175 ) ;
if ( V_96 & V_175 ) {
F_111 ( V_168 . V_172 ,
V_168 . V_176 ) ;
return - V_72 ;
}
V_152 = F_105 ( & V_168 ) ;
if ( F_18 ( V_152 ) )
return F_21 ( V_152 ) ;
V_174 = V_152 -> V_177 ;
F_112 ( V_152 ) ;
return V_174 ;
}
int
F_113 ( struct V_1 * V_2 , const struct V_159 * V_160 , int V_96 ,
const struct V_178 * V_179 , void * V_166 )
{
struct V_143 * V_152 ;
struct V_167 V_168 = {
. V_169 = V_2 ,
. V_159 = V_160 ,
. V_172 = V_179 ,
. V_176 = V_166 ,
. V_96 = V_96 | V_175 ,
} ;
V_152 = F_105 ( & V_168 ) ;
if ( F_18 ( V_152 ) )
return F_21 ( V_152 ) ;
F_112 ( V_152 ) ;
return 0 ;
}
struct V_143 * F_114 ( struct V_180 * V_181 ,
const struct V_178 * V_179 )
{
struct V_143 * V_152 ;
struct V_182 * V_183 = & V_181 -> V_184 ;
struct V_167 V_168 = {
. V_172 = V_179 ,
} ;
F_45 ( L_19 , V_181 ) ;
V_152 = F_106 ( & V_168 ) ;
if ( F_18 ( V_152 ) ) {
F_115 ( V_181 ) ;
goto V_58;
}
V_152 -> V_185 = V_181 ;
V_183 -> V_186 = V_183 -> V_187 [ 0 ] . V_188 + V_183 -> V_189 +
V_183 -> V_190 [ 0 ] . V_188 ;
V_152 -> V_170 = V_191 ;
F_61 ( & V_152 -> V_171 ) ;
F_110 ( F_25 ( & V_152 -> V_171 ) != 2 ) ;
F_108 ( V_152 ) ;
V_58:
F_45 ( L_20 , V_152 ) ;
return V_152 ;
}
void
F_107 ( struct V_143 * V_152 )
{
V_152 -> V_170 = V_192 ;
}
T_4 F_116 ( struct V_1 * V_2 , struct V_193 * V_194 , T_4 V_195 )
{
T_4 V_196 ;
struct V_39 * V_40 ;
F_72 () ;
V_40 = F_74 ( V_2 -> V_45 ) ;
V_196 = V_40 -> V_115 ;
if ( V_196 > V_195 )
V_196 = V_195 ;
memcpy ( V_194 , & V_40 -> V_197 , V_196 ) ;
F_75 () ;
return V_196 ;
}
const char * F_117 ( struct V_1 * V_2 ,
enum V_198 V_199 )
{
struct V_39 * V_40 ;
V_40 = F_74 ( V_2 -> V_45 ) ;
if ( V_40 -> V_200 [ V_199 ] != NULL )
return V_40 -> V_200 [ V_199 ] ;
else
return L_21 ;
}
static int F_118 ( struct V_3 * V_3 , struct V_193 * V_201 , T_4 V_202 ,
struct V_193 * V_194 , int V_203 )
{
struct V_204 * V_205 ;
int V_28 ;
V_28 = F_119 ( V_3 , V_201 -> V_127 ,
V_206 , V_207 , & V_205 , 1 ) ;
if ( V_28 < 0 ) {
F_45 ( L_22 , V_28 ) ;
goto V_58;
}
switch ( V_201 -> V_127 ) {
case V_130 :
V_28 = F_120 ( V_205 ,
(struct V_193 * ) & V_208 ,
sizeof( V_208 ) ) ;
break;
case V_133 :
V_28 = F_120 ( V_205 ,
(struct V_193 * ) & V_209 ,
sizeof( V_209 ) ) ;
break;
default:
V_28 = - V_210 ;
goto V_58;
}
if ( V_28 < 0 ) {
F_45 ( L_23 , V_28 ) ;
goto V_211;
}
V_28 = F_121 ( V_205 , V_201 , V_202 , 0 ) ;
if ( V_28 < 0 ) {
F_45 ( L_24 , V_28 ) ;
goto V_211;
}
V_28 = F_122 ( V_205 , V_194 , & V_203 ) ;
if ( V_28 < 0 ) {
F_45 ( L_25 , V_28 ) ;
goto V_211;
}
V_28 = 0 ;
if ( V_194 -> V_127 == V_133 ) {
struct V_125 * V_126 = (struct V_125 * ) V_194 ;
V_126 -> V_212 = 0 ;
}
F_45 ( L_26 , V_31 ) ;
V_211:
F_123 ( V_205 ) ;
V_58:
return V_28 ;
}
static int F_124 ( int V_213 , struct V_193 * V_194 , T_4 V_203 )
{
switch ( V_213 ) {
case V_130 :
if ( V_203 < sizeof( V_208 ) )
return - V_72 ;
memcpy ( V_194 , & V_208 ,
sizeof( V_208 ) ) ;
break;
case V_133 :
if ( V_203 < sizeof( V_209 ) )
return - V_72 ;
memcpy ( V_194 , & V_209 ,
sizeof( V_209 ) ) ;
default:
F_45 ( L_27 ,
V_31 ) ;
return - V_210 ;
}
F_45 ( L_28 , V_31 ) ;
return 0 ;
}
int F_125 ( struct V_1 * V_2 , struct V_193 * V_194 , T_4 V_203 )
{
struct V_214 V_114 ;
struct V_193 * V_201 = (struct V_193 * ) & V_114 ;
struct V_39 * V_40 ;
struct V_3 * V_3 ;
T_4 V_202 ;
int V_28 ;
F_72 () ;
V_40 = F_74 ( V_2 -> V_45 ) ;
V_202 = V_40 -> V_115 ;
memcpy ( V_201 , & V_40 -> V_197 , V_202 ) ;
V_3 = F_126 ( V_40 -> V_215 ) ;
F_75 () ;
F_127 ( V_201 , 0 ) ;
V_28 = F_118 ( V_3 , V_201 , V_202 , V_194 , V_203 ) ;
F_128 ( V_3 ) ;
if ( V_28 != 0 )
return F_124 ( V_201 -> V_127 , V_194 , V_203 ) ;
return 0 ;
}
void
F_129 ( struct V_1 * V_2 , unsigned int V_216 , unsigned int V_217 )
{
struct V_39 * V_40 ;
F_72 () ;
V_40 = F_74 ( V_2 -> V_45 ) ;
if ( V_40 -> V_218 -> V_219 )
V_40 -> V_218 -> V_219 ( V_40 , V_216 , V_217 ) ;
F_75 () ;
}
int F_130 ( struct V_1 * V_2 )
{
int V_110 ;
F_72 () ;
V_110 = F_74 ( V_2 -> V_45 ) -> V_220 ;
F_75 () ;
return V_110 ;
}
struct V_3 * F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_221 ;
F_72 () ;
V_221 = F_74 ( V_2 -> V_45 ) -> V_215 ;
F_75 () ;
return V_221 ;
}
T_4 F_131 ( struct V_1 * V_2 )
{
T_4 V_221 ;
F_72 () ;
V_221 = F_74 ( V_2 -> V_45 ) -> V_222 ;
F_75 () ;
return V_221 ;
}
unsigned long F_132 ( struct V_1 * V_2 )
{
unsigned long V_221 ;
F_72 () ;
V_221 = F_74 ( V_2 -> V_45 ) -> V_42 -> V_93 ;
F_75 () ;
return V_221 ;
}
void F_133 ( struct V_1 * V_2 )
{
if ( V_2 -> V_46 ) {
F_72 () ;
F_134 ( F_74 ( V_2 -> V_45 ) ) ;
F_75 () ;
}
}
int
F_135 ( struct V_143 * V_152 )
{
if ( F_136 ( V_152 ) )
return 0 ;
V_152 -> V_170 = V_192 ;
V_152 -> V_177 = 0 ;
if ( V_152 -> V_179 -> V_223 != NULL )
V_152 -> V_170 = V_224 ;
return 1 ;
}
int
F_137 ( struct V_143 * V_152 )
{
if ( F_136 ( V_152 ) )
return 0 ;
V_152 -> V_170 = V_192 ;
V_152 -> V_177 = 0 ;
return 1 ;
}
const char
* F_138 ( const struct V_143 * V_152 )
{
const struct V_225 * V_226 = V_152 -> V_161 . V_162 ;
if ( V_226 ) {
if ( V_226 -> V_227 )
return V_226 -> V_227 ;
else
return L_29 ;
} else
return L_30 ;
}
static void
V_192 ( struct V_143 * V_152 )
{
struct V_1 * V_2 = V_152 -> V_153 ;
F_45 ( L_31 , V_152 -> V_228 ,
V_2 -> V_16 -> V_18 , V_2 -> V_84 ,
F_138 ( V_152 ) ,
( F_139 ( V_152 ) ? L_32 : L_33 ) ) ;
V_152 -> V_161 . V_162 -> V_229 ++ ;
V_2 -> V_85 -> V_230 ++ ;
V_152 -> V_170 = V_231 ;
}
static void
V_231 ( struct V_143 * V_152 )
{
F_140 ( V_152 ) ;
V_152 -> V_177 = 0 ;
V_152 -> V_170 = V_232 ;
F_141 ( V_152 ) ;
}
static void
V_232 ( struct V_143 * V_152 )
{
int V_174 = V_152 -> V_177 ;
F_140 ( V_152 ) ;
V_152 -> V_177 = 0 ;
if ( V_174 >= 0 ) {
if ( V_152 -> V_185 ) {
V_152 -> V_170 = V_233 ;
return;
}
F_20 ( V_30 L_34 ,
V_31 , V_174 ) ;
F_84 ( V_152 , - V_147 ) ;
return;
}
if ( V_152 -> V_185 ) {
F_20 ( V_30 L_35 ,
V_31 , V_174 ) ;
F_142 ( V_152 ) ;
}
switch ( V_174 ) {
case - V_75 :
F_143 ( V_152 , V_150 >> 2 ) ;
case - V_234 :
V_152 -> V_170 = V_235 ;
return;
case - V_147 :
break;
default:
F_20 ( V_30 L_36 ,
V_31 , V_174 ) ;
break;
}
F_84 ( V_152 , V_174 ) ;
}
static void
V_235 ( struct V_143 * V_152 )
{
F_140 ( V_152 ) ;
V_152 -> V_177 = 0 ;
V_152 -> V_170 = V_232 ;
F_144 ( V_152 ) ;
}
static void
V_233 ( struct V_143 * V_152 )
{
F_140 ( V_152 ) ;
V_152 -> V_170 = V_236 ;
V_152 -> V_177 = 0 ;
V_152 -> V_153 -> V_85 -> V_237 ++ ;
F_145 ( V_152 ) ;
}
static void
V_236 ( struct V_143 * V_152 )
{
int V_174 = V_152 -> V_177 ;
F_140 ( V_152 ) ;
V_152 -> V_177 = 0 ;
V_152 -> V_170 = V_233 ;
switch ( V_174 ) {
case 0 :
if ( F_146 ( V_152 ) ) {
V_152 -> V_170 = V_238 ;
return;
}
case - V_239 :
F_143 ( V_152 , 3 * V_150 ) ;
case - V_234 :
V_174 = - V_240 ;
case - V_241 :
if ( ! V_152 -> V_242 )
break;
V_152 -> V_242 -- ;
F_45 ( L_37 ,
V_152 -> V_228 , V_31 ) ;
return;
}
F_45 ( L_38 ,
V_152 -> V_228 , V_31 , V_174 ) ;
F_84 ( V_152 , V_174 ) ;
}
static void
V_238 ( struct V_143 * V_152 )
{
unsigned int V_243 = V_152 -> V_185 -> V_244 -> V_245 -> V_246 ;
struct V_180 * V_181 = V_152 -> V_185 ;
struct V_39 * V_40 = V_181 -> V_247 ;
struct V_225 * V_226 = V_152 -> V_161 . V_162 ;
F_140 ( V_152 ) ;
V_152 -> V_177 = 0 ;
V_152 -> V_170 = V_248 ;
if ( V_181 -> V_249 )
return;
if ( V_226 -> V_250 != 0 ) {
F_147 ( V_226 -> V_251 == 0 ) ;
if ( V_226 -> V_252 != NULL )
F_147 ( V_226 -> V_253 == 0 ) ;
}
V_181 -> V_254 = V_255 + ( V_243 << 1 ) + V_226 -> V_251 ;
V_181 -> V_254 <<= 2 ;
V_181 -> V_256 = V_257 + V_243 + V_226 -> V_253 ;
V_181 -> V_256 <<= 2 ;
V_181 -> V_249 = V_40 -> V_218 -> V_258 ( V_152 ,
V_181 -> V_254 + V_181 -> V_256 ) ;
if ( V_181 -> V_249 != NULL )
return;
F_45 ( L_39 , V_152 -> V_228 ) ;
if ( F_139 ( V_152 ) || ! F_148 ( V_259 ) ) {
V_152 -> V_170 = V_238 ;
F_143 ( V_152 , V_150 >> 4 ) ;
return;
}
F_84 ( V_152 , - V_260 ) ;
}
static inline int
F_149 ( struct V_143 * V_152 )
{
return V_152 -> V_185 -> V_184 . V_186 == 0 ;
}
static inline void
F_150 ( struct V_143 * V_152 )
{
V_152 -> V_185 -> V_184 . V_186 = 0 ;
V_152 -> V_185 -> V_261 = 0 ;
}
static inline void
F_151 ( struct V_182 * V_194 , void * V_262 , T_4 V_186 )
{
V_194 -> V_187 [ 0 ] . V_263 = V_262 ;
V_194 -> V_187 [ 0 ] . V_188 = V_186 ;
V_194 -> V_190 [ 0 ] . V_188 = 0 ;
V_194 -> V_189 = 0 ;
V_194 -> V_96 = 0 ;
V_194 -> V_186 = 0 ;
V_194 -> V_203 = V_186 ;
}
static void
F_152 ( struct V_143 * V_152 )
{
struct V_180 * V_181 = V_152 -> V_185 ;
T_5 V_264 ;
T_6 * V_265 ;
F_140 ( V_152 ) ;
F_151 ( & V_181 -> V_184 ,
V_181 -> V_249 ,
V_181 -> V_254 ) ;
F_151 ( & V_181 -> V_266 ,
( char * ) V_181 -> V_249 + V_181 -> V_254 ,
V_181 -> V_256 ) ;
V_265 = F_153 ( V_152 ) ;
if ( V_265 == NULL ) {
F_20 ( V_21 L_40 ) ;
F_84 ( V_152 , - V_147 ) ;
return;
}
V_264 = V_152 -> V_161 . V_162 -> V_267 ;
if ( V_264 == NULL )
return;
V_152 -> V_177 = F_154 ( V_152 , V_264 , V_181 , V_265 ,
V_152 -> V_161 . V_163 ) ;
}
static void
V_248 ( struct V_143 * V_152 )
{
struct V_39 * V_40 = V_152 -> V_185 -> V_247 ;
F_140 ( V_152 ) ;
V_152 -> V_170 = V_268 ;
if ( ! F_38 ( V_40 ) ) {
V_152 -> V_170 = V_269 ;
V_152 -> V_270 = V_40 -> V_271 ;
V_40 -> V_218 -> V_272 ( V_152 ) ;
}
}
static void
V_269 ( struct V_143 * V_152 )
{
int V_174 = - V_147 ;
if ( V_152 -> V_177 >= 0 ) {
F_140 ( V_152 ) ;
V_152 -> V_177 = 0 ;
V_152 -> V_170 = V_268 ;
return;
}
F_155 ( V_152 ) ;
switch ( V_152 -> V_177 ) {
case - V_75 :
F_45 ( L_41 , V_152 -> V_228 ) ;
F_143 ( V_152 , V_150 >> 2 ) ;
goto V_273;
case - V_240 :
F_45 ( L_42
L_43 , V_152 -> V_228 ) ;
if ( V_152 -> V_161 . V_162 -> V_250 == 0 ) {
V_174 = - V_274 ;
break;
}
if ( V_152 -> V_275 == 0 )
break;
V_152 -> V_275 -- ;
F_143 ( V_152 , 3 * V_150 ) ;
goto V_273;
case - V_239 :
F_45 ( L_44 ,
V_152 -> V_228 ) ;
goto V_273;
case - V_276 :
F_45 ( L_45 ,
V_152 -> V_228 ) ;
break;
case - V_277 :
F_45 ( L_46 ,
V_152 -> V_228 ) ;
goto V_273;
case - V_278 :
case - V_279 :
case - V_280 :
case - V_281 :
case - V_282 :
case - V_283 :
case - V_284 :
case - V_285 :
case - V_286 :
F_45 ( L_47 ,
V_152 -> V_228 , V_152 -> V_177 ) ;
if ( ! F_156 ( V_152 ) ) {
F_143 ( V_152 , 5 * V_150 ) ;
goto V_273;
}
V_174 = V_152 -> V_177 ;
break;
default:
F_45 ( L_48 ,
V_152 -> V_228 , - V_152 -> V_177 ) ;
}
F_84 ( V_152 , V_174 ) ;
return;
V_273:
V_152 -> V_177 = 0 ;
V_152 -> V_170 = V_287 ;
}
static void
V_268 ( struct V_143 * V_152 )
{
struct V_39 * V_40 = V_152 -> V_185 -> V_247 ;
F_45 ( L_49 ,
V_152 -> V_228 , V_40 ,
( F_157 ( V_40 ) ? L_50 : L_51 ) ) ;
V_152 -> V_170 = V_288 ;
if ( ! F_157 ( V_40 ) ) {
V_152 -> V_170 = V_289 ;
if ( V_152 -> V_177 < 0 )
return;
if ( V_152 -> V_145 & V_290 ) {
F_84 ( V_152 , - V_281 ) ;
return;
}
F_158 ( V_152 ) ;
}
}
static void
V_289 ( struct V_143 * V_152 )
{
struct V_1 * V_2 = V_152 -> V_153 ;
int V_174 = V_152 -> V_177 ;
F_140 ( V_152 ) ;
F_159 ( V_152 , V_174 ) ;
V_152 -> V_177 = 0 ;
switch ( V_174 ) {
case - V_278 :
case - V_279 :
case - V_280 :
case - V_284 :
case - V_283 :
case - V_291 :
case - V_285 :
case - V_286 :
if ( F_156 ( V_152 ) )
break;
F_143 ( V_152 , 3 * V_150 ) ;
case - V_234 :
case - V_239 :
V_152 -> V_170 = V_287 ;
return;
case 0 :
V_2 -> V_85 -> V_292 ++ ;
V_152 -> V_170 = V_288 ;
return;
}
F_84 ( V_152 , V_174 ) ;
}
static void
V_288 ( struct V_143 * V_152 )
{
int V_293 = F_160 ( V_152 ) ;
F_140 ( V_152 ) ;
V_152 -> V_170 = V_294 ;
if ( V_152 -> V_177 < 0 )
return;
if ( ! F_161 ( V_152 ) )
return;
V_152 -> V_170 = V_295 ;
if ( F_149 ( V_152 ) ) {
F_152 ( V_152 ) ;
if ( V_152 -> V_177 != 0 ) {
if ( V_152 -> V_177 == - V_234 )
F_143 ( V_152 , V_150 >> 4 ) ;
else
F_84 ( V_152 , V_152 -> V_177 ) ;
return;
}
}
F_162 ( V_152 ) ;
if ( V_152 -> V_177 < 0 )
return;
if ( V_293 )
V_152 -> V_153 -> V_85 -> V_296 ++ ;
V_295 ( V_152 ) ;
if ( F_163 ( V_152 ) )
return;
V_152 -> V_170 = V_297 ;
F_86 ( & V_152 -> V_185 -> V_247 -> V_298 , V_152 ) ;
}
static void
V_295 ( struct V_143 * V_152 )
{
V_152 -> V_170 = V_294 ;
if ( V_152 -> V_177 == 0 ) {
F_164 ( V_152 ) ;
F_150 ( V_152 ) ;
return;
}
switch ( V_152 -> V_177 ) {
case - V_234 :
break;
default:
F_140 ( V_152 ) ;
F_164 ( V_152 ) ;
F_150 ( V_152 ) ;
break;
case - V_278 :
case - V_282 :
case - V_283 :
case - V_284 :
case - V_299 :
if ( F_156 ( V_152 ) ) {
F_164 ( V_152 ) ;
F_84 ( V_152 , V_152 -> V_177 ) ;
break;
}
case - V_279 :
case - V_280 :
case - V_291 :
case - V_281 :
case - V_285 :
case - V_286 :
F_150 ( V_152 ) ;
}
}
static void
V_191 ( struct V_143 * V_152 )
{
struct V_180 * V_181 = V_152 -> V_185 ;
if ( ! F_161 ( V_152 ) ) {
V_152 -> V_177 = 0 ;
V_152 -> V_170 = V_191 ;
return;
}
V_152 -> V_170 = V_297 ;
if ( V_152 -> V_177 < 0 ) {
F_20 ( V_300 L_52
L_53 , V_152 -> V_177 ) ;
return;
}
F_162 ( V_152 ) ;
F_164 ( V_152 ) ;
F_140 ( V_152 ) ;
switch ( V_152 -> V_177 ) {
case 0 :
break;
case - V_282 :
case - V_283 :
case - V_284 :
case - V_239 :
F_20 ( V_300 L_52
L_53 , V_152 -> V_177 ) ;
F_165 ( V_181 -> V_247 ,
V_181 -> V_301 ) ;
break;
default:
F_110 ( V_152 -> V_177 == - V_234 ) ;
F_20 ( V_300 L_52
L_53 , V_152 -> V_177 ) ;
break;
}
F_86 ( & V_181 -> V_247 -> V_298 , V_152 ) ;
}
static void
V_294 ( struct V_143 * V_152 )
{
struct V_1 * V_2 = V_152 -> V_153 ;
struct V_180 * V_181 = V_152 -> V_185 ;
int V_174 ;
if ( V_181 -> V_302 > 0 && ! V_181 -> V_261 )
V_152 -> V_177 = V_181 -> V_302 ;
F_140 ( V_152 ) ;
V_174 = V_152 -> V_177 ;
if ( V_174 >= 0 ) {
V_152 -> V_170 = V_303 ;
return;
}
F_166 ( V_152 ) ;
V_152 -> V_177 = 0 ;
switch( V_174 ) {
case - V_282 :
case - V_283 :
case - V_284 :
case - V_299 :
if ( F_156 ( V_152 ) ) {
F_84 ( V_152 , V_174 ) ;
break;
}
F_143 ( V_152 , 3 * V_150 ) ;
case - V_239 :
V_152 -> V_170 = V_287 ;
if ( ! ( V_152 -> V_145 & V_156 )
&& V_152 -> V_153 -> V_104 )
F_165 ( V_181 -> V_247 ,
V_181 -> V_301 ) ;
break;
case - V_278 :
case - V_279 :
case - V_280 :
F_133 ( V_2 ) ;
case - V_291 :
case - V_285 :
F_143 ( V_152 , 3 * V_150 ) ;
case - V_286 :
case - V_281 :
V_152 -> V_170 = V_248 ;
break;
case - V_234 :
V_152 -> V_170 = V_288 ;
break;
case - V_147 :
F_84 ( V_152 , V_174 ) ;
break;
default:
if ( V_2 -> V_106 )
F_20 ( L_54 ,
V_2 -> V_16 -> V_18 , - V_174 ) ;
F_84 ( V_152 , V_174 ) ;
}
}
static void
V_287 ( struct V_143 * V_152 )
{
struct V_1 * V_2 = V_152 -> V_153 ;
if ( F_167 ( V_152 -> V_185 ) == 0 ) {
F_45 ( L_55 , V_152 -> V_228 ) ;
goto V_304;
}
F_45 ( L_56 , V_152 -> V_228 ) ;
V_152 -> V_305 ++ ;
if ( F_156 ( V_152 ) ) {
F_84 ( V_152 , - V_239 ) ;
return;
}
if ( F_168 ( V_152 ) ) {
if ( V_2 -> V_106 ) {
F_72 () ;
F_20 ( V_300 L_57 ,
V_2 -> V_16 -> V_18 ,
F_74 ( V_2 -> V_45 ) -> V_70 ) ;
F_75 () ;
}
if ( V_152 -> V_145 & V_306 )
F_84 ( V_152 , - V_239 ) ;
else
F_84 ( V_152 , - V_147 ) ;
return;
}
if ( ! ( V_152 -> V_145 & V_307 ) ) {
V_152 -> V_145 |= V_307 ;
if ( V_2 -> V_106 ) {
F_72 () ;
F_20 ( V_300 L_58 ,
V_2 -> V_16 -> V_18 ,
F_74 ( V_2 -> V_45 ) -> V_70 ) ;
F_75 () ;
}
}
F_133 ( V_2 ) ;
F_169 ( V_152 ) ;
V_304:
V_152 -> V_170 = V_248 ;
V_152 -> V_177 = 0 ;
}
static void
V_303 ( struct V_143 * V_152 )
{
struct V_1 * V_2 = V_152 -> V_153 ;
struct V_180 * V_181 = V_152 -> V_185 ;
T_7 V_308 = V_152 -> V_161 . V_162 -> V_252 ;
T_6 * V_265 ;
F_140 ( V_152 ) ;
if ( V_152 -> V_145 & V_307 ) {
if ( V_2 -> V_106 ) {
F_72 () ;
F_20 ( V_300 L_59 ,
V_2 -> V_16 -> V_18 ,
F_74 ( V_2 -> V_45 ) -> V_70 ) ;
F_75 () ;
}
V_152 -> V_145 &= ~ V_307 ;
}
F_170 () ;
V_181 -> V_266 . V_186 = V_181 -> V_309 . V_186 ;
F_171 ( memcmp ( & V_181 -> V_266 , & V_181 -> V_309 ,
sizeof( V_181 -> V_266 ) ) != 0 ) ;
if ( V_181 -> V_266 . V_186 < 12 ) {
if ( ! F_168 ( V_152 ) ) {
V_152 -> V_170 = V_248 ;
goto V_310;
}
F_45 ( L_60 ,
V_2 -> V_16 -> V_18 , V_152 -> V_177 ) ;
V_152 -> V_170 = V_287 ;
goto V_310;
}
V_265 = F_172 ( V_152 ) ;
if ( F_18 ( V_265 ) ) {
if ( V_265 == F_19 ( - V_234 ) )
goto V_310;
return;
}
V_152 -> V_170 = V_297 ;
if ( V_308 ) {
V_152 -> V_177 = F_173 ( V_152 , V_308 , V_181 , V_265 ,
V_152 -> V_161 . V_164 ) ;
}
F_45 ( L_61 , V_152 -> V_228 ,
V_152 -> V_177 ) ;
return;
V_310:
V_152 -> V_177 = 0 ;
if ( V_152 -> V_185 == V_181 ) {
V_181 -> V_302 = V_181 -> V_266 . V_186 = 0 ;
if ( V_152 -> V_153 -> V_104 )
F_165 ( V_181 -> V_247 ,
V_181 -> V_301 ) ;
}
}
static T_6 *
F_153 ( struct V_143 * V_152 )
{
struct V_1 * V_2 = V_152 -> V_153 ;
struct V_180 * V_181 = V_152 -> V_185 ;
T_6 * V_265 = V_181 -> V_311 [ 0 ] . V_263 ;
V_265 = F_174 ( V_181 -> V_247 , V_265 ) ;
* V_265 ++ = V_181 -> V_312 ;
* V_265 ++ = F_175 ( V_313 ) ;
* V_265 ++ = F_175 ( V_314 ) ;
* V_265 ++ = F_175 ( V_2 -> V_81 ) ;
* V_265 ++ = F_175 ( V_2 -> V_84 ) ;
* V_265 ++ = F_175 ( V_152 -> V_161 . V_162 -> V_250 ) ;
V_265 = F_176 ( V_152 , V_265 ) ;
V_181 -> V_315 = F_177 ( & V_181 -> V_311 [ 0 ] , V_265 ) ;
return V_265 ;
}
static T_6 *
F_172 ( struct V_143 * V_152 )
{
struct V_1 * V_2 = V_152 -> V_153 ;
struct V_316 * V_317 = & V_152 -> V_185 -> V_266 . V_187 [ 0 ] ;
int V_186 = V_152 -> V_185 -> V_266 . V_186 >> 2 ;
T_6 * V_265 = V_317 -> V_263 ;
T_3 V_318 ;
int error = - V_240 ;
if ( ( V_152 -> V_185 -> V_266 . V_186 & 3 ) != 0 ) {
F_45 ( L_62
L_63 , V_152 -> V_228 , V_31 ,
V_152 -> V_185 -> V_266 . V_186 ) ;
error = - V_147 ;
goto V_74;
}
if ( ( V_186 -= 3 ) < 0 )
goto V_319;
V_265 += 1 ;
if ( ( V_318 = F_178 ( * V_265 ++ ) ) != V_320 ) {
F_45 ( L_64 ,
V_152 -> V_228 , V_31 , V_318 ) ;
error = - V_147 ;
goto V_321;
}
if ( ( V_318 = F_178 ( * V_265 ++ ) ) != V_322 ) {
if ( -- V_186 < 0 )
goto V_319;
switch ( ( V_318 = F_178 ( * V_265 ++ ) ) ) {
case V_323 :
break;
case V_324 :
F_45 ( L_65 ,
V_152 -> V_228 , V_31 ) ;
error = - V_277 ;
goto V_74;
default:
F_45 ( L_66
L_67 ,
V_152 -> V_228 , V_31 , V_318 ) ;
error = - V_147 ;
goto V_74;
}
if ( -- V_186 < 0 )
goto V_319;
switch ( ( V_318 = F_178 ( * V_265 ++ ) ) ) {
case V_325 :
case V_326 :
case V_327 :
case V_328 :
if ( ! V_152 -> V_242 )
break;
V_152 -> V_242 -- ;
F_45 ( L_68 ,
V_152 -> V_228 , V_31 ) ;
F_169 ( V_152 ) ;
F_142 ( V_152 ) ;
V_152 -> V_170 = V_231 ;
goto V_310;
case V_329 :
case V_330 :
if ( ! V_152 -> V_331 )
break;
V_152 -> V_331 -- ;
F_45 ( L_69 ,
V_152 -> V_228 , V_31 ) ;
V_152 -> V_170 = V_248 ;
goto V_310;
case V_332 :
F_72 () ;
F_20 ( V_300 L_70
L_71 ,
F_74 ( V_2 -> V_45 ) -> V_70 ) ;
F_75 () ;
break;
default:
F_45 ( L_72 ,
V_152 -> V_228 , V_31 , V_318 ) ;
error = - V_147 ;
}
F_45 ( L_73 ,
V_152 -> V_228 , V_31 , V_318 ) ;
goto V_74;
}
V_265 = F_179 ( V_152 , V_265 ) ;
if ( F_18 ( V_265 ) ) {
error = F_21 ( V_265 ) ;
F_45 ( L_74 ,
V_152 -> V_228 , V_31 , error ) ;
goto V_321;
}
V_186 = V_265 - ( T_6 * ) V_317 -> V_263 - 1 ;
if ( V_186 < 0 )
goto V_319;
switch ( ( V_318 = F_178 ( * V_265 ++ ) ) ) {
case V_333 :
return V_265 ;
case V_334 :
F_88 ( L_75
L_76 , V_152 -> V_228 , V_31 ,
( unsigned int ) V_2 -> V_81 ,
F_74 ( V_2 -> V_45 ) -> V_70 ) ;
error = - V_276 ;
goto V_74;
case V_335 :
F_88 ( L_77
L_76 , V_152 -> V_228 , V_31 ,
( unsigned int ) V_2 -> V_81 ,
( unsigned int ) V_2 -> V_84 ,
F_74 ( V_2 -> V_45 ) -> V_70 ) ;
error = - V_277 ;
goto V_74;
case V_336 :
F_88 ( L_78
L_79 ,
V_152 -> V_228 , V_31 ,
F_138 ( V_152 ) ,
V_2 -> V_81 , V_2 -> V_84 ,
F_74 ( V_2 -> V_45 ) -> V_70 ) ;
error = - V_274 ;
goto V_74;
case V_337 :
F_45 ( L_80 ,
V_152 -> V_228 , V_31 ) ;
break;
default:
F_45 ( L_81 ,
V_152 -> V_228 , V_31 , V_318 ) ;
}
V_321:
V_2 -> V_85 -> V_338 ++ ;
if ( V_152 -> V_331 ) {
V_152 -> V_331 -- ;
F_45 ( L_82 ,
V_152 -> V_228 , V_31 ) ;
V_152 -> V_170 = V_248 ;
V_310:
return F_19 ( - V_234 ) ;
}
V_74:
F_84 ( V_152 , error ) ;
F_45 ( L_83 , V_152 -> V_228 ,
V_31 , error ) ;
return F_19 ( error ) ;
V_319:
F_45 ( L_84 , V_152 -> V_228 ,
V_31 ) ;
goto V_321;
}
static void F_180 ( void * V_339 , struct V_340 * V_341 , void * V_342 )
{
}
static int F_181 ( void * V_339 , struct V_340 * V_341 , void * V_342 )
{
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_159 V_160 = {
. V_162 = & V_343 ,
} ;
int V_28 ;
V_160 . V_165 = V_344 . V_345 ( NULL , NULL , 0 ) ;
V_28 = F_109 ( V_2 , & V_160 , V_155 | V_346 ) ;
F_182 ( V_160 . V_165 ) ;
return V_28 ;
}
struct V_143 * F_183 ( struct V_1 * V_2 , struct V_165 * V_347 , int V_96 )
{
struct V_159 V_160 = {
. V_162 = & V_343 ,
. V_165 = V_347 ,
} ;
struct V_167 V_168 = {
. V_169 = V_2 ,
. V_159 = & V_160 ,
. V_172 = & V_173 ,
. V_96 = V_96 ,
} ;
return F_105 ( & V_168 ) ;
}
static void F_184 ( void )
{
F_20 ( V_21 L_85
L_86 ) ;
}
static void F_185 ( const struct V_1 * V_2 ,
const struct V_143 * V_152 )
{
const char * V_348 = L_87 ;
if ( F_85 ( V_152 ) )
V_348 = F_186 ( V_152 -> V_148 ) ;
F_20 ( V_21 L_88 ,
V_152 -> V_228 , V_152 -> V_145 , V_152 -> V_177 ,
V_2 , V_152 -> V_185 , V_152 -> V_270 , V_152 -> V_179 ,
V_2 -> V_16 -> V_18 , V_2 -> V_84 , F_138 ( V_152 ) ,
V_152 -> V_170 , V_348 ) ;
}
void F_187 ( struct V_3 * V_3 )
{
struct V_1 * V_2 ;
struct V_143 * V_152 ;
int V_349 = 0 ;
struct V_4 * V_5 = F_3 ( V_3 , V_6 ) ;
F_4 ( & V_5 -> V_7 ) ;
F_29 (clnt, &sn->all_clients, cl_clients) {
F_4 ( & V_2 -> V_44 ) ;
F_29 (task, &clnt->cl_tasks, tk_task) {
if ( ! V_349 ) {
F_184 () ;
V_349 ++ ;
}
F_185 ( V_2 , V_152 ) ;
}
F_6 ( & V_2 -> V_44 ) ;
}
F_6 ( & V_5 -> V_7 ) ;
}
