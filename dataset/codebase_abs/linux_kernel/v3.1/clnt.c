static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( & V_2 -> V_4 , & V_5 ) ;
F_4 ( & V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_6 ( & V_2 -> V_4 ) ;
F_4 ( & V_3 ) ;
}
static int
F_7 ( struct V_1 * V_2 , char * V_6 )
{
static T_1 V_7 ;
struct V_8 V_8 , V_9 ;
char V_10 [ 15 ] ;
struct V_11 V_12 = {
. V_10 = V_10 ,
} ;
int error ;
V_2 -> V_13 . V_14 = F_8 ( - V_15 ) ;
V_2 -> V_13 . V_16 = F_8 ( - V_15 ) ;
if ( V_6 == NULL )
return 0 ;
V_8 . V_14 = F_9 () ;
if ( F_10 ( V_8 . V_14 ) )
return F_11 ( V_8 . V_14 ) ;
error = F_12 ( V_8 . V_14 -> V_17 , V_8 . V_14 , V_6 , 0 , & V_9 ) ;
if ( error )
goto V_18;
for (; ; ) {
V_12 . V_19 = snprintf ( V_10 , sizeof( V_10 ) , L_1 , ( unsigned int ) V_7 ++ ) ;
V_10 [ sizeof( V_10 ) - 1 ] = '\0' ;
V_12 . V_20 = F_13 ( V_12 . V_10 , V_12 . V_19 ) ;
V_8 . V_16 = F_14 ( V_9 . V_16 , & V_12 , V_2 ) ;
if ( ! F_10 ( V_8 . V_16 ) )
break;
error = F_11 ( V_8 . V_16 ) ;
if ( error != - V_21 ) {
F_15 ( V_22 L_2
L_3 ,
V_6 , V_10 , error ) ;
goto V_23;
}
}
F_16 ( & V_9 ) ;
V_2 -> V_13 = V_8 ;
return 0 ;
V_23:
F_16 ( & V_9 ) ;
V_18:
F_17 () ;
return error ;
}
static struct V_1 * F_18 ( const struct V_24 * args , struct V_25 * V_26 )
{
struct V_27 * V_28 = args -> V_28 ;
struct V_29 * V_30 ;
struct V_1 * V_2 = NULL ;
struct V_31 * V_32 ;
int V_18 ;
T_2 V_19 ;
V_18 = - V_33 ;
V_19 = strlen ( args -> V_34 ) ;
if ( V_19 > V_35 )
goto V_36;
V_19 ++ ;
F_19 ( L_4 ,
V_28 -> V_10 , args -> V_34 , V_26 ) ;
V_18 = F_20 () ;
if ( V_18 )
goto V_36;
V_18 = - V_33 ;
if ( ! V_26 )
goto V_37;
if ( args -> V_30 >= V_28 -> V_38 )
goto V_39;
V_30 = V_28 -> V_30 [ args -> V_30 ] ;
if ( V_30 == NULL )
goto V_39;
V_18 = - V_40 ;
V_2 = F_21 ( sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 )
goto V_39;
V_2 -> V_42 = V_2 ;
V_2 -> V_43 = V_2 -> V_44 ;
if ( V_19 > sizeof( V_2 -> V_44 ) ) {
char * V_45 = F_22 ( V_19 , V_41 ) ;
if ( V_45 != NULL )
V_2 -> V_43 = V_45 ;
else
V_19 = sizeof( V_2 -> V_44 ) ;
}
F_23 ( V_2 -> V_43 , args -> V_34 , V_19 ) ;
V_2 -> V_46 = V_26 ;
V_2 -> V_47 = V_30 -> V_48 ;
V_2 -> V_49 = V_30 -> V_50 ;
V_2 -> V_51 = V_28 -> V_10 ;
V_2 -> V_52 = args -> V_53 ? : V_28 -> V_54 ;
V_2 -> V_55 = V_30 -> V_54 ;
V_2 -> V_56 = V_28 -> V_57 ;
V_2 -> V_58 = F_24 ( V_2 ) ;
V_18 = - V_40 ;
if ( V_2 -> V_58 == NULL )
goto V_59;
V_2 -> V_60 = V_28 ;
F_25 ( & V_2 -> V_61 ) ;
F_26 ( & V_2 -> V_62 ) ;
if ( ! F_27 ( V_2 -> V_46 ) )
V_2 -> V_63 = 1 ;
V_2 -> V_64 = V_26 -> V_65 ;
if ( args -> V_65 != NULL ) {
memcpy ( & V_2 -> V_66 , args -> V_65 ,
sizeof( V_2 -> V_66 ) ) ;
V_2 -> V_64 = & V_2 -> V_66 ;
}
V_2 -> V_67 = & V_2 -> V_68 ;
F_28 ( & V_2 -> V_68 , V_2 -> V_64 -> V_69 ) ;
V_2 -> V_70 = NULL ;
if ( args -> V_71 ) {
V_2 -> V_70 = F_29 ( args -> V_71 , V_41 ) ;
if ( ! V_2 -> V_70 )
goto V_72;
}
F_30 ( & V_2 -> V_73 , 1 ) ;
V_18 = F_7 ( V_2 , V_28 -> V_74 ) ;
if ( V_18 < 0 )
goto V_75;
V_32 = F_31 ( args -> V_76 , V_2 ) ;
if ( F_10 ( V_32 ) ) {
F_15 ( V_22 L_5 ,
args -> V_76 ) ;
V_18 = F_11 ( V_32 ) ;
goto V_77;
}
V_2 -> V_78 = strlen ( F_32 () -> V_79 ) ;
if ( V_2 -> V_78 > V_80 )
V_2 -> V_78 = V_80 ;
memcpy ( V_2 -> V_81 , F_32 () -> V_79 , V_2 -> V_78 ) ;
F_1 ( V_2 ) ;
return V_2 ;
V_77:
if ( ! F_10 ( V_2 -> V_13 . V_16 ) ) {
F_33 ( V_2 -> V_13 . V_16 ) ;
F_17 () ;
}
V_75:
F_34 ( V_2 -> V_70 ) ;
V_72:
F_35 ( V_2 -> V_58 ) ;
V_59:
if ( V_2 -> V_43 != V_2 -> V_44 )
F_34 ( V_2 -> V_43 ) ;
F_34 ( V_2 ) ;
V_39:
F_36 ( V_26 ) ;
V_37:
F_37 () ;
V_36:
return F_8 ( V_18 ) ;
}
struct V_1 * F_38 ( struct V_24 * args )
{
struct V_25 * V_26 ;
struct V_1 * V_2 ;
struct V_82 V_83 = {
. V_84 = args -> V_84 ,
. V_85 = args -> V_86 ,
. V_87 = args -> V_88 ,
. V_89 = args -> V_90 ,
. V_91 = args -> V_92 ,
. V_93 = args -> V_93 ,
} ;
char V_34 [ 48 ] ;
if ( args -> V_34 == NULL ) {
struct V_94 * V_95 =
(struct V_94 * ) args -> V_90 ;
struct V_96 * sin =
(struct V_96 * ) args -> V_90 ;
struct V_97 * V_98 =
(struct V_97 * ) args -> V_90 ;
V_34 [ 0 ] = '\0' ;
switch ( args -> V_90 -> V_99 ) {
case V_100 :
snprintf ( V_34 , sizeof( V_34 ) , L_6 ,
V_95 -> V_101 ) ;
break;
case V_102 :
snprintf ( V_34 , sizeof( V_34 ) , L_7 ,
& sin -> V_103 . V_104 ) ;
break;
case V_105 :
snprintf ( V_34 , sizeof( V_34 ) , L_8 ,
& V_98 -> V_106 ) ;
break;
default:
return F_8 ( - V_33 ) ;
}
args -> V_34 = V_34 ;
}
V_26 = F_39 ( & V_83 ) ;
if ( F_10 ( V_26 ) )
return (struct V_1 * ) V_26 ;
V_26 -> V_107 = 1 ;
if ( args -> V_108 & V_109 )
V_26 -> V_107 = 0 ;
V_2 = F_18 ( args , V_26 ) ;
if ( F_10 ( V_2 ) )
return V_2 ;
if ( ! ( args -> V_108 & V_110 ) ) {
int V_18 = F_40 ( V_2 ) ;
if ( V_18 != 0 ) {
F_41 ( V_2 ) ;
return F_8 ( V_18 ) ;
}
}
V_2 -> V_111 = 1 ;
if ( args -> V_108 & V_112 )
V_2 -> V_111 = 0 ;
if ( args -> V_108 & V_113 )
V_2 -> V_63 = 1 ;
if ( args -> V_108 & V_114 )
V_2 -> V_115 = 1 ;
if ( ! ( args -> V_108 & V_116 ) )
V_2 -> V_117 = 1 ;
return V_2 ;
}
struct V_1 *
F_42 ( struct V_1 * V_2 )
{
struct V_1 * V_118 ;
int V_18 = - V_40 ;
V_118 = F_43 ( V_2 , sizeof( * V_118 ) , V_41 ) ;
if ( ! V_118 )
goto V_119;
V_118 -> V_42 = V_2 ;
V_118 -> V_63 = 0 ;
F_25 ( & V_118 -> V_61 ) ;
F_26 ( & V_118 -> V_62 ) ;
F_28 ( & V_118 -> V_68 , V_2 -> V_64 -> V_69 ) ;
V_118 -> V_58 = F_24 ( V_2 ) ;
if ( V_118 -> V_58 == NULL )
goto V_59;
if ( V_2 -> V_70 ) {
V_118 -> V_70 = F_29 ( V_2 -> V_70 , V_41 ) ;
if ( V_118 -> V_70 == NULL )
goto V_72;
}
F_30 ( & V_118 -> V_73 , 1 ) ;
V_18 = F_7 ( V_118 , V_2 -> V_60 -> V_74 ) ;
if ( V_18 != 0 )
goto V_75;
if ( V_118 -> V_120 )
F_44 ( & V_118 -> V_120 -> V_121 ) ;
F_45 ( V_2 -> V_46 ) ;
F_44 ( & V_2 -> V_73 ) ;
F_1 ( V_118 ) ;
F_20 () ;
return V_118 ;
V_75:
F_34 ( V_118 -> V_70 ) ;
V_72:
F_35 ( V_118 -> V_58 ) ;
V_59:
F_34 ( V_118 ) ;
V_119:
F_19 ( L_9 , V_122 , V_18 ) ;
return F_8 ( V_18 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
struct V_123 * V_124 ;
if ( F_47 ( & V_2 -> V_61 ) )
return;
F_19 ( L_10 , V_2 ) ;
F_2 ( & V_2 -> V_62 ) ;
F_48 (rovr, &clnt->cl_tasks, tk_task) {
if ( ! F_49 ( V_124 ) )
continue;
if ( ! ( V_124 -> V_125 & V_126 ) ) {
V_124 -> V_125 |= V_126 ;
F_50 ( V_124 , - V_127 ) ;
if ( F_51 ( V_124 ) )
F_52 ( V_124 -> V_128 ,
V_124 ) ;
}
}
F_4 ( & V_2 -> V_62 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
F_19 ( L_11 ,
V_2 -> V_51 , V_2 -> V_43 ) ;
while ( ! F_47 ( & V_2 -> V_61 ) ) {
F_46 ( V_2 ) ;
F_53 ( V_129 ,
F_47 ( & V_2 -> V_61 ) , 1 * V_130 ) ;
}
F_54 ( V_2 ) ;
}
static void
F_55 ( struct V_1 * V_2 )
{
F_19 ( L_12 ,
V_2 -> V_51 , V_2 -> V_43 ) ;
if ( ! F_10 ( V_2 -> V_13 . V_16 ) ) {
F_33 ( V_2 -> V_13 . V_16 ) ;
F_17 () ;
}
if ( V_2 -> V_42 != V_2 ) {
F_54 ( V_2 -> V_42 ) ;
goto V_131;
}
if ( V_2 -> V_43 != V_2 -> V_44 )
F_34 ( V_2 -> V_43 ) ;
V_131:
F_5 ( V_2 ) ;
F_35 ( V_2 -> V_58 ) ;
F_34 ( V_2 -> V_70 ) ;
V_2 -> V_58 = NULL ;
F_36 ( V_2 -> V_46 ) ;
F_37 () ;
F_34 ( V_2 ) ;
}
static void
F_56 ( struct V_1 * V_2 )
{
if ( V_2 -> V_120 == NULL ) {
F_55 ( V_2 ) ;
return;
}
F_44 ( & V_2 -> V_73 ) ;
F_57 ( V_2 -> V_120 ) ;
V_2 -> V_120 = NULL ;
if ( F_58 ( & V_2 -> V_73 ) )
F_55 ( V_2 ) ;
}
void
F_54 ( struct V_1 * V_2 )
{
F_19 ( L_13 , V_2 ) ;
if ( F_47 ( & V_2 -> V_61 ) )
F_59 ( & V_129 ) ;
if ( F_58 ( & V_2 -> V_73 ) )
F_56 ( V_2 ) ;
}
struct V_1 * F_60 ( struct V_1 * V_132 ,
struct V_27 * V_28 ,
T_3 V_133 )
{
struct V_1 * V_2 ;
struct V_29 * V_30 ;
int V_18 ;
F_61 ( V_133 >= V_28 -> V_38 || ! V_28 -> V_30 [ V_133 ] ) ;
V_30 = V_28 -> V_30 [ V_133 ] ;
V_2 = F_42 ( V_132 ) ;
if ( F_10 ( V_2 ) )
goto V_134;
V_2 -> V_47 = V_30 -> V_48 ;
V_2 -> V_49 = V_30 -> V_50 ;
V_2 -> V_51 = V_28 -> V_10 ;
V_2 -> V_52 = V_28 -> V_54 ;
V_2 -> V_55 = V_30 -> V_54 ;
V_2 -> V_56 = V_28 -> V_57 ;
V_18 = F_40 ( V_2 ) ;
if ( V_18 != 0 ) {
F_41 ( V_2 ) ;
V_2 = F_8 ( V_18 ) ;
}
V_134:
return V_2 ;
}
void F_62 ( struct V_123 * V_135 )
{
struct V_1 * V_2 = V_135 -> V_136 ;
if ( V_2 != NULL ) {
F_2 ( & V_2 -> V_62 ) ;
F_6 ( & V_135 -> V_137 ) ;
F_4 ( & V_2 -> V_62 ) ;
V_135 -> V_136 = NULL ;
F_54 ( V_2 ) ;
}
}
static
void F_63 ( struct V_123 * V_135 , struct V_1 * V_2 )
{
if ( V_2 != NULL ) {
F_62 ( V_135 ) ;
V_135 -> V_136 = V_2 ;
F_44 ( & V_2 -> V_73 ) ;
if ( V_2 -> V_111 )
V_135 -> V_125 |= V_138 ;
F_2 ( & V_2 -> V_62 ) ;
F_64 ( & V_135 -> V_137 , & V_2 -> V_61 ) ;
F_4 ( & V_2 -> V_62 ) ;
}
}
void F_65 ( struct V_123 * V_135 , struct V_1 * V_2 )
{
F_62 ( V_135 ) ;
F_63 ( V_135 , V_2 ) ;
}
static void
F_66 ( struct V_123 * V_135 , const struct V_139 * V_140 )
{
if ( V_140 != NULL ) {
V_135 -> V_141 . V_142 = V_140 -> V_142 ;
V_135 -> V_141 . V_143 = V_140 -> V_143 ;
V_135 -> V_141 . V_144 = V_140 -> V_144 ;
if ( V_140 -> V_145 != NULL )
V_135 -> V_141 . V_145 = F_67 ( V_140 -> V_145 ) ;
}
}
static void
F_68 ( struct V_123 * V_135 , void * V_146 )
{
}
struct V_123 * F_69 ( const struct V_147 * V_148 )
{
struct V_123 * V_135 ;
V_135 = F_70 ( V_148 ) ;
if ( F_10 ( V_135 ) )
goto V_134;
F_63 ( V_135 , V_148 -> V_149 ) ;
F_66 ( V_135 , V_148 -> V_139 ) ;
if ( V_135 -> V_150 == NULL )
F_71 ( V_135 ) ;
F_44 ( & V_135 -> V_151 ) ;
F_72 ( V_135 ) ;
V_134:
return V_135 ;
}
int F_73 ( struct V_1 * V_2 , const struct V_139 * V_140 , int V_108 )
{
struct V_123 * V_135 ;
struct V_147 V_148 = {
. V_149 = V_2 ,
. V_139 = V_140 ,
. V_152 = & V_153 ,
. V_108 = V_108 ,
} ;
int V_154 ;
F_61 ( V_108 & V_155 ) ;
V_135 = F_69 ( & V_148 ) ;
if ( F_10 ( V_135 ) )
return F_11 ( V_135 ) ;
V_154 = V_135 -> V_156 ;
F_74 ( V_135 ) ;
return V_154 ;
}
int
F_75 ( struct V_1 * V_2 , const struct V_139 * V_140 , int V_108 ,
const struct V_157 * V_158 , void * V_146 )
{
struct V_123 * V_135 ;
struct V_147 V_148 = {
. V_149 = V_2 ,
. V_139 = V_140 ,
. V_152 = V_158 ,
. V_159 = V_146 ,
. V_108 = V_108 | V_155 ,
} ;
V_135 = F_69 ( & V_148 ) ;
if ( F_10 ( V_135 ) )
return F_11 ( V_135 ) ;
F_74 ( V_135 ) ;
return 0 ;
}
struct V_123 * F_76 ( struct V_160 * V_161 ,
const struct V_157 * V_158 )
{
struct V_123 * V_135 ;
struct V_162 * V_163 = & V_161 -> V_164 ;
struct V_147 V_148 = {
. V_152 = V_158 ,
} ;
F_19 ( L_14 , V_161 ) ;
V_135 = F_70 ( & V_148 ) ;
if ( F_10 ( V_135 ) ) {
F_77 ( V_161 ) ;
goto V_134;
}
V_135 -> V_165 = V_161 ;
V_163 -> V_19 = V_163 -> V_166 [ 0 ] . V_167 + V_163 -> V_168 +
V_163 -> V_169 [ 0 ] . V_167 ;
V_135 -> V_150 = V_170 ;
F_44 ( & V_135 -> V_151 ) ;
F_61 ( F_78 ( & V_135 -> V_151 ) != 2 ) ;
F_72 ( V_135 ) ;
V_134:
F_19 ( L_15 , V_135 ) ;
return V_135 ;
}
void
F_71 ( struct V_123 * V_135 )
{
V_135 -> V_150 = V_171 ;
}
T_2 F_79 ( struct V_1 * V_2 , struct V_172 * V_45 , T_2 V_173 )
{
T_2 V_174 ;
struct V_25 * V_26 = V_2 -> V_46 ;
V_174 = sizeof( V_26 -> V_175 ) ;
if ( V_174 > V_173 )
V_174 = V_173 ;
memcpy ( V_45 , & V_2 -> V_46 -> V_175 , V_174 ) ;
return V_26 -> V_91 ;
}
const char * F_80 ( struct V_1 * V_2 ,
enum V_176 V_177 )
{
struct V_25 * V_26 = V_2 -> V_46 ;
if ( V_26 -> V_178 [ V_177 ] != NULL )
return V_26 -> V_178 [ V_177 ] ;
else
return L_16 ;
}
void
F_81 ( struct V_1 * V_2 , unsigned int V_179 , unsigned int V_180 )
{
struct V_25 * V_26 = V_2 -> V_46 ;
if ( V_26 -> V_181 -> V_182 )
V_26 -> V_181 -> V_182 ( V_26 , V_179 , V_180 ) ;
}
T_2 F_82 ( struct V_1 * V_2 )
{
return V_2 -> V_46 -> V_183 ;
}
void F_83 ( struct V_1 * V_2 )
{
if ( V_2 -> V_63 )
F_84 ( V_2 -> V_46 ) ;
}
int
F_85 ( struct V_123 * V_135 )
{
if ( F_86 ( V_135 ) )
return 0 ;
V_135 -> V_150 = V_184 ;
return 1 ;
}
int
F_87 ( struct V_123 * V_135 )
{
if ( F_86 ( V_135 ) )
return 0 ;
V_135 -> V_150 = V_171 ;
return 1 ;
}
static const char * F_88 ( const struct V_123 * V_135 )
{
const struct V_185 * V_186 = V_135 -> V_141 . V_142 ;
if ( V_186 ) {
if ( V_186 -> V_187 )
return V_186 -> V_187 ;
else
return L_17 ;
} else
return L_18 ;
}
static void
V_171 ( struct V_123 * V_135 )
{
struct V_1 * V_2 = V_135 -> V_136 ;
F_19 ( L_19 , V_135 -> V_188 ,
V_2 -> V_51 , V_2 -> V_55 ,
F_88 ( V_135 ) ,
( F_89 ( V_135 ) ? L_20 : L_21 ) ) ;
V_135 -> V_141 . V_142 -> V_189 ++ ;
V_2 -> V_56 -> V_190 ++ ;
V_135 -> V_150 = V_191 ;
}
static void
V_191 ( struct V_123 * V_135 )
{
F_90 ( V_135 ) ;
V_135 -> V_156 = 0 ;
V_135 -> V_150 = V_192 ;
F_91 ( V_135 ) ;
}
static void
V_192 ( struct V_123 * V_135 )
{
int V_154 = V_135 -> V_156 ;
F_90 ( V_135 ) ;
V_135 -> V_156 = 0 ;
if ( V_154 >= 0 ) {
if ( V_135 -> V_165 ) {
V_135 -> V_150 = V_193 ;
return;
}
F_15 ( V_194 L_22 ,
V_122 , V_154 ) ;
F_50 ( V_135 , - V_127 ) ;
return;
}
if ( V_135 -> V_165 ) {
F_15 ( V_194 L_23 ,
V_122 , V_154 ) ;
F_92 ( V_135 ) ;
}
switch ( V_154 ) {
case - V_195 :
V_135 -> V_150 = V_191 ;
return;
case - V_127 :
break;
default:
F_15 ( V_194 L_24 ,
V_122 , V_154 ) ;
break;
}
F_50 ( V_135 , V_154 ) ;
}
static void
V_193 ( struct V_123 * V_135 )
{
F_90 ( V_135 ) ;
V_135 -> V_150 = V_196 ;
V_135 -> V_156 = 0 ;
V_135 -> V_136 -> V_56 -> V_197 ++ ;
F_93 ( V_135 ) ;
}
static void
V_196 ( struct V_123 * V_135 )
{
int V_154 = V_135 -> V_156 ;
F_90 ( V_135 ) ;
V_135 -> V_156 = 0 ;
V_135 -> V_150 = V_193 ;
switch ( V_154 ) {
case 0 :
if ( F_94 ( V_135 ) )
V_135 -> V_150 = V_198 ;
return;
case - V_199 :
F_95 ( V_135 , 3 * V_130 ) ;
case - V_195 :
V_154 = - V_200 ;
if ( ! V_135 -> V_201 )
break;
V_135 -> V_201 -- ;
F_19 ( L_25 ,
V_135 -> V_188 , V_122 ) ;
return;
}
F_19 ( L_26 ,
V_135 -> V_188 , V_122 , V_154 ) ;
F_50 ( V_135 , V_154 ) ;
}
static void
V_198 ( struct V_123 * V_135 )
{
unsigned int V_202 = V_135 -> V_165 -> V_203 -> V_204 -> V_205 ;
struct V_160 * V_161 = V_135 -> V_165 ;
struct V_25 * V_26 = V_135 -> V_206 ;
struct V_185 * V_186 = V_135 -> V_141 . V_142 ;
F_90 ( V_135 ) ;
V_135 -> V_156 = 0 ;
V_135 -> V_150 = V_207 ;
if ( V_161 -> V_208 )
return;
if ( V_186 -> V_209 != 0 ) {
F_61 ( V_186 -> V_210 == 0 ) ;
if ( V_186 -> V_211 != NULL )
F_61 ( V_186 -> V_212 == 0 ) ;
}
V_161 -> V_213 = V_214 + ( V_202 << 1 ) + V_186 -> V_210 ;
V_161 -> V_213 <<= 2 ;
V_161 -> V_215 = V_216 + V_202 + V_186 -> V_212 ;
V_161 -> V_215 <<= 2 ;
V_161 -> V_208 = V_26 -> V_181 -> V_217 ( V_135 ,
V_161 -> V_213 + V_161 -> V_215 ) ;
if ( V_161 -> V_208 != NULL )
return;
F_19 ( L_27 , V_135 -> V_188 ) ;
if ( F_89 ( V_135 ) || ! F_96 ( V_218 ) ) {
V_135 -> V_150 = V_198 ;
F_95 ( V_135 , V_130 >> 4 ) ;
return;
}
F_50 ( V_135 , - V_219 ) ;
}
static inline int
F_97 ( struct V_123 * V_135 )
{
return V_135 -> V_165 -> V_164 . V_19 == 0 ;
}
static inline void
F_98 ( struct V_123 * V_135 )
{
V_135 -> V_165 -> V_164 . V_19 = 0 ;
V_135 -> V_165 -> V_220 = 0 ;
}
static inline void
F_99 ( struct V_162 * V_45 , void * V_221 , T_2 V_19 )
{
V_45 -> V_166 [ 0 ] . V_222 = V_221 ;
V_45 -> V_166 [ 0 ] . V_167 = V_19 ;
V_45 -> V_169 [ 0 ] . V_167 = 0 ;
V_45 -> V_168 = 0 ;
V_45 -> V_108 = 0 ;
V_45 -> V_19 = 0 ;
V_45 -> V_223 = V_19 ;
}
static void
F_100 ( struct V_123 * V_135 )
{
struct V_160 * V_161 = V_135 -> V_165 ;
T_4 V_224 ;
T_5 * V_225 ;
F_90 ( V_135 ) ;
F_99 ( & V_161 -> V_164 ,
V_161 -> V_208 ,
V_161 -> V_213 ) ;
F_99 ( & V_161 -> V_226 ,
( char * ) V_161 -> V_208 + V_161 -> V_213 ,
V_161 -> V_215 ) ;
V_225 = F_101 ( V_135 ) ;
if ( V_225 == NULL ) {
F_15 ( V_22 L_28 ) ;
F_50 ( V_135 , - V_127 ) ;
return;
}
V_224 = V_135 -> V_141 . V_142 -> V_227 ;
if ( V_224 == NULL )
return;
V_135 -> V_156 = F_102 ( V_135 , V_224 , V_161 , V_225 ,
V_135 -> V_141 . V_143 ) ;
}
static void
V_207 ( struct V_123 * V_135 )
{
struct V_25 * V_26 = V_135 -> V_206 ;
F_90 ( V_135 ) ;
V_135 -> V_150 = V_228 ;
if ( ! F_27 ( V_26 ) ) {
V_135 -> V_150 = V_229 ;
V_135 -> V_230 = V_26 -> V_231 ;
V_26 -> V_181 -> V_232 ( V_135 ) ;
}
}
static void
V_229 ( struct V_123 * V_135 )
{
int V_154 = - V_127 ;
if ( V_135 -> V_156 >= 0 ) {
F_90 ( V_135 ) ;
V_135 -> V_156 = 0 ;
V_135 -> V_150 = V_228 ;
return;
}
switch ( V_135 -> V_156 ) {
case - V_40 :
F_19 ( L_29 , V_135 -> V_188 ) ;
F_95 ( V_135 , V_130 >> 2 ) ;
goto V_233;
case - V_200 :
F_19 ( L_30
L_31 , V_135 -> V_188 ) ;
if ( V_135 -> V_141 . V_142 -> V_209 == 0 ) {
V_154 = - V_234 ;
break;
}
if ( V_135 -> V_235 == 0 )
break;
V_135 -> V_235 -- ;
F_95 ( V_135 , 3 * V_130 ) ;
goto V_233;
case - V_199 :
F_19 ( L_32 ,
V_135 -> V_188 ) ;
goto V_233;
case - V_236 :
F_19 ( L_33 ,
V_135 -> V_188 ) ;
break;
case - V_237 :
F_19 ( L_34 ,
V_135 -> V_188 ) ;
V_135 -> V_156 = 0 ;
V_135 -> V_150 = V_207 ;
return;
case - V_238 :
case - V_239 :
case - V_240 :
case - V_241 :
case - V_242 :
case - V_243 :
case - V_244 :
F_19 ( L_35 ,
V_135 -> V_188 , V_135 -> V_156 ) ;
if ( ! F_103 ( V_135 ) ) {
F_95 ( V_135 , 5 * V_130 ) ;
goto V_233;
}
V_154 = V_135 -> V_156 ;
break;
default:
F_19 ( L_36 ,
V_135 -> V_188 , - V_135 -> V_156 ) ;
}
F_50 ( V_135 , V_154 ) ;
return;
V_233:
V_135 -> V_150 = V_245 ;
}
static void
V_228 ( struct V_123 * V_135 )
{
struct V_25 * V_26 = V_135 -> V_206 ;
F_19 ( L_37 ,
V_135 -> V_188 , V_26 ,
( F_104 ( V_26 ) ? L_38 : L_39 ) ) ;
V_135 -> V_150 = V_246 ;
if ( ! F_104 ( V_26 ) ) {
V_135 -> V_150 = V_247 ;
if ( V_135 -> V_156 < 0 )
return;
F_105 ( V_135 ) ;
}
}
static void
V_247 ( struct V_123 * V_135 )
{
struct V_1 * V_2 = V_135 -> V_136 ;
int V_154 = V_135 -> V_156 ;
F_90 ( V_135 ) ;
V_135 -> V_156 = 0 ;
if ( V_154 >= 0 || V_154 == - V_195 ) {
V_2 -> V_56 -> V_248 ++ ;
V_135 -> V_150 = V_246 ;
return;
}
switch ( V_154 ) {
case - V_199 :
V_135 -> V_150 = V_245 ;
break;
default:
F_50 ( V_135 , - V_127 ) ;
}
}
static void
V_246 ( struct V_123 * V_135 )
{
F_90 ( V_135 ) ;
V_135 -> V_150 = V_249 ;
if ( V_135 -> V_156 < 0 )
return;
V_135 -> V_156 = F_106 ( V_135 ) ;
if ( V_135 -> V_156 != 0 )
return;
V_135 -> V_150 = V_250 ;
if ( F_97 ( V_135 ) ) {
F_61 ( V_135 -> V_165 -> V_220 != 0 ) ;
F_100 ( V_135 ) ;
if ( V_135 -> V_156 != 0 ) {
if ( V_135 -> V_156 == - V_195 )
F_95 ( V_135 , V_130 >> 4 ) ;
else
F_50 ( V_135 , V_135 -> V_156 ) ;
return;
}
}
F_107 ( V_135 ) ;
if ( V_135 -> V_156 < 0 )
return;
V_250 ( V_135 ) ;
if ( F_108 ( V_135 ) )
return;
V_135 -> V_150 = V_251 ;
F_52 ( & V_135 -> V_206 -> V_252 , V_135 ) ;
}
static void
V_250 ( struct V_123 * V_135 )
{
V_135 -> V_150 = V_249 ;
if ( V_135 -> V_156 == 0 ) {
F_109 ( V_135 ) ;
F_98 ( V_135 ) ;
return;
}
switch ( V_135 -> V_156 ) {
case - V_195 :
break;
default:
F_90 ( V_135 ) ;
F_109 ( V_135 ) ;
F_98 ( V_135 ) ;
break;
case - V_238 :
case - V_241 :
case - V_242 :
case - V_243 :
if ( F_103 ( V_135 ) ) {
F_109 ( V_135 ) ;
F_50 ( V_135 , V_135 -> V_156 ) ;
break;
}
case - V_239 :
case - V_240 :
case - V_244 :
F_98 ( V_135 ) ;
}
}
static void
V_170 ( struct V_123 * V_135 )
{
struct V_160 * V_161 = V_135 -> V_165 ;
F_61 ( V_135 -> V_156 != 0 ) ;
V_135 -> V_156 = F_106 ( V_135 ) ;
if ( V_135 -> V_156 == - V_195 ) {
V_135 -> V_156 = 0 ;
V_135 -> V_150 = V_170 ;
return;
}
V_135 -> V_150 = V_251 ;
if ( V_135 -> V_156 < 0 ) {
F_15 ( V_253 L_40
L_41 , V_135 -> V_156 ) ;
return;
}
F_107 ( V_135 ) ;
F_109 ( V_135 ) ;
F_90 ( V_135 ) ;
switch ( V_135 -> V_156 ) {
case 0 :
break;
case - V_241 :
case - V_242 :
case - V_243 :
case - V_199 :
F_15 ( V_253 L_40
L_41 , V_135 -> V_156 ) ;
F_110 ( V_135 -> V_206 ,
V_161 -> V_254 ) ;
break;
default:
F_61 ( V_135 -> V_156 == - V_195 ) ;
F_15 ( V_253 L_40
L_41 , V_135 -> V_156 ) ;
break;
}
F_52 ( & V_161 -> V_255 -> V_252 , V_135 ) ;
}
static void
V_249 ( struct V_123 * V_135 )
{
struct V_1 * V_2 = V_135 -> V_136 ;
struct V_160 * V_161 = V_135 -> V_165 ;
int V_154 ;
if ( V_161 -> V_256 > 0 && ! V_161 -> V_220 )
V_135 -> V_156 = V_161 -> V_256 ;
F_90 ( V_135 ) ;
V_154 = V_135 -> V_156 ;
if ( V_154 >= 0 ) {
V_135 -> V_150 = V_257 ;
return;
}
V_135 -> V_156 = 0 ;
switch( V_154 ) {
case - V_241 :
case - V_242 :
case - V_243 :
F_95 ( V_135 , 3 * V_130 ) ;
case - V_199 :
V_135 -> V_150 = V_245 ;
if ( V_135 -> V_136 -> V_115 )
F_110 ( V_135 -> V_206 ,
V_161 -> V_254 ) ;
break;
case - V_239 :
case - V_238 :
F_83 ( V_2 ) ;
F_95 ( V_135 , 3 * V_130 ) ;
case - V_244 :
case - V_240 :
V_135 -> V_150 = V_207 ;
break;
case - V_195 :
V_135 -> V_150 = V_246 ;
break;
case - V_127 :
F_50 ( V_135 , V_154 ) ;
break;
default:
if ( V_2 -> V_117 )
F_15 ( L_42 ,
V_2 -> V_51 , - V_154 ) ;
F_50 ( V_135 , V_154 ) ;
}
}
static void
V_245 ( struct V_123 * V_135 )
{
struct V_1 * V_2 = V_135 -> V_136 ;
if ( F_111 ( V_135 -> V_165 ) == 0 ) {
F_19 ( L_43 , V_135 -> V_188 ) ;
goto V_258;
}
F_19 ( L_44 , V_135 -> V_188 ) ;
V_135 -> V_259 ++ ;
if ( F_103 ( V_135 ) ) {
F_50 ( V_135 , - V_199 ) ;
return;
}
if ( F_112 ( V_135 ) ) {
if ( V_2 -> V_117 )
F_15 ( V_253 L_45 ,
V_2 -> V_51 , V_2 -> V_43 ) ;
if ( V_135 -> V_125 & V_260 )
F_50 ( V_135 , - V_199 ) ;
else
F_50 ( V_135 , - V_127 ) ;
return;
}
if ( ! ( V_135 -> V_125 & V_261 ) ) {
V_135 -> V_125 |= V_261 ;
if ( V_2 -> V_117 )
F_15 ( V_253 L_46 ,
V_2 -> V_51 , V_2 -> V_43 ) ;
}
F_83 ( V_2 ) ;
F_113 ( V_135 ) ;
V_258:
V_2 -> V_56 -> V_262 ++ ;
V_135 -> V_150 = V_207 ;
V_135 -> V_156 = 0 ;
}
static void
V_257 ( struct V_123 * V_135 )
{
struct V_1 * V_2 = V_135 -> V_136 ;
struct V_160 * V_161 = V_135 -> V_165 ;
T_6 V_263 = V_135 -> V_141 . V_142 -> V_211 ;
T_5 * V_225 ;
F_90 ( V_135 ) ;
if ( V_135 -> V_125 & V_261 ) {
if ( V_2 -> V_117 )
F_15 ( V_253 L_47 ,
V_2 -> V_51 , V_2 -> V_43 ) ;
V_135 -> V_125 &= ~ V_261 ;
}
F_114 () ;
V_161 -> V_226 . V_19 = V_161 -> V_264 . V_19 ;
F_115 ( memcmp ( & V_161 -> V_226 , & V_161 -> V_264 ,
sizeof( V_161 -> V_226 ) ) != 0 ) ;
if ( V_161 -> V_226 . V_19 < 12 ) {
if ( ! F_112 ( V_135 ) ) {
V_135 -> V_150 = V_207 ;
V_2 -> V_56 -> V_262 ++ ;
goto V_265;
}
F_19 ( L_48 ,
V_2 -> V_51 , V_135 -> V_156 ) ;
V_135 -> V_150 = V_245 ;
goto V_265;
}
V_225 = F_116 ( V_135 ) ;
if ( F_10 ( V_225 ) ) {
if ( V_225 == F_8 ( - V_195 ) )
goto V_265;
return;
}
V_135 -> V_150 = V_251 ;
if ( V_263 ) {
V_135 -> V_156 = F_117 ( V_135 , V_263 , V_161 , V_225 ,
V_135 -> V_141 . V_144 ) ;
}
F_19 ( L_49 , V_135 -> V_188 ,
V_135 -> V_156 ) ;
return;
V_265:
V_135 -> V_156 = 0 ;
if ( V_135 -> V_165 == V_161 ) {
V_161 -> V_256 = V_161 -> V_226 . V_19 = 0 ;
if ( V_135 -> V_136 -> V_115 )
F_110 ( V_135 -> V_206 ,
V_161 -> V_254 ) ;
}
}
static T_5 *
F_101 ( struct V_123 * V_135 )
{
struct V_1 * V_2 = V_135 -> V_136 ;
struct V_160 * V_161 = V_135 -> V_165 ;
T_5 * V_225 = V_161 -> V_266 [ 0 ] . V_222 ;
V_225 = F_118 ( V_135 -> V_206 , V_225 ) ;
* V_225 ++ = V_161 -> V_267 ;
* V_225 ++ = F_119 ( V_268 ) ;
* V_225 ++ = F_119 ( V_269 ) ;
* V_225 ++ = F_119 ( V_2 -> V_52 ) ;
* V_225 ++ = F_119 ( V_2 -> V_55 ) ;
* V_225 ++ = F_119 ( V_135 -> V_141 . V_142 -> V_209 ) ;
V_225 = F_120 ( V_135 , V_225 ) ;
V_161 -> V_270 = F_121 ( & V_161 -> V_266 [ 0 ] , V_225 ) ;
return V_225 ;
}
static T_5 *
F_116 ( struct V_123 * V_135 )
{
struct V_271 * V_272 = & V_135 -> V_165 -> V_226 . V_166 [ 0 ] ;
int V_19 = V_135 -> V_165 -> V_226 . V_19 >> 2 ;
T_5 * V_225 = V_272 -> V_222 ;
T_3 V_273 ;
int error = - V_200 ;
if ( ( V_135 -> V_165 -> V_226 . V_19 & 3 ) != 0 ) {
F_19 ( L_50
L_51 , V_135 -> V_188 , V_122 ,
V_135 -> V_165 -> V_226 . V_19 ) ;
goto V_274;
}
if ( ( V_19 -= 3 ) < 0 )
goto V_275;
V_225 += 1 ;
if ( ( V_273 = F_122 ( * V_225 ++ ) ) != V_276 ) {
F_19 ( L_52 ,
V_135 -> V_188 , V_122 , V_273 ) ;
goto V_277;
}
if ( ( V_273 = F_122 ( * V_225 ++ ) ) != V_278 ) {
if ( -- V_19 < 0 )
goto V_275;
switch ( ( V_273 = F_122 ( * V_225 ++ ) ) ) {
case V_279 :
break;
case V_280 :
F_19 ( L_53 ,
V_135 -> V_188 , V_122 ) ;
error = - V_237 ;
goto V_39;
default:
F_19 ( L_54
L_55 ,
V_135 -> V_188 , V_122 , V_273 ) ;
goto V_274;
}
if ( -- V_19 < 0 )
goto V_275;
switch ( ( V_273 = F_122 ( * V_225 ++ ) ) ) {
case V_281 :
case V_282 :
case V_283 :
case V_284 :
if ( ! V_135 -> V_201 )
break;
V_135 -> V_201 -- ;
F_19 ( L_56 ,
V_135 -> V_188 , V_122 ) ;
F_113 ( V_135 ) ;
F_92 ( V_135 ) ;
V_135 -> V_150 = V_191 ;
goto V_265;
case V_285 :
case V_286 :
if ( ! V_135 -> V_287 )
break;
V_135 -> V_287 -- ;
F_19 ( L_57 ,
V_135 -> V_188 , V_122 ) ;
V_135 -> V_150 = V_207 ;
goto V_265;
case V_288 :
F_15 ( V_253 L_58
L_59 , V_135 -> V_136 -> V_43 ) ;
break;
default:
F_19 ( L_60 ,
V_135 -> V_188 , V_122 , V_273 ) ;
error = - V_127 ;
}
F_19 ( L_61 ,
V_135 -> V_188 , V_122 , V_273 ) ;
goto V_39;
}
if ( ! ( V_225 = F_123 ( V_135 , V_225 ) ) ) {
F_19 ( L_62 ,
V_135 -> V_188 , V_122 ) ;
goto V_277;
}
V_19 = V_225 - ( T_5 * ) V_272 -> V_222 - 1 ;
if ( V_19 < 0 )
goto V_275;
switch ( ( V_273 = F_122 ( * V_225 ++ ) ) ) {
case V_289 :
return V_225 ;
case V_290 :
F_19 ( L_63 ,
V_135 -> V_188 , V_122 ,
( unsigned int ) V_135 -> V_136 -> V_52 ,
V_135 -> V_136 -> V_43 ) ;
error = - V_236 ;
goto V_39;
case V_291 :
F_19 ( L_64
L_65 , V_135 -> V_188 , V_122 ,
( unsigned int ) V_135 -> V_136 -> V_52 ,
( unsigned int ) V_135 -> V_136 -> V_55 ,
V_135 -> V_136 -> V_43 ) ;
error = - V_237 ;
goto V_39;
case V_292 :
F_19 ( L_66
L_67 ,
V_135 -> V_188 , V_122 ,
F_88 ( V_135 ) ,
V_135 -> V_136 -> V_52 ,
V_135 -> V_136 -> V_55 ,
V_135 -> V_136 -> V_43 ) ;
error = - V_234 ;
goto V_39;
case V_293 :
F_19 ( L_68 ,
V_135 -> V_188 , V_122 ) ;
break;
default:
F_19 ( L_69 ,
V_135 -> V_188 , V_122 , V_273 ) ;
}
V_277:
V_135 -> V_136 -> V_56 -> V_294 ++ ;
if ( V_135 -> V_287 ) {
V_135 -> V_287 -- ;
F_19 ( L_70 ,
V_135 -> V_188 , V_122 ) ;
V_135 -> V_150 = V_207 ;
V_265:
return F_8 ( - V_195 ) ;
}
V_274:
error = - V_127 ;
V_39:
F_50 ( V_135 , error ) ;
F_19 ( L_71 , V_135 -> V_188 ,
V_122 , error ) ;
return F_8 ( error ) ;
V_275:
F_19 ( L_72 , V_135 -> V_188 ,
V_122 ) ;
goto V_277;
}
static void F_124 ( void * V_295 , struct V_296 * V_297 , void * V_298 )
{
}
static int F_125 ( void * V_295 , struct V_296 * V_297 , void * V_298 )
{
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_139 V_140 = {
. V_142 = & V_299 ,
} ;
int V_18 ;
V_140 . V_145 = V_300 . V_301 ( NULL , NULL , 0 ) ;
V_18 = F_73 ( V_2 , & V_140 , V_138 | V_302 ) ;
F_126 ( V_140 . V_145 ) ;
return V_18 ;
}
struct V_123 * F_127 ( struct V_1 * V_2 , struct V_145 * V_303 , int V_108 )
{
struct V_139 V_140 = {
. V_142 = & V_299 ,
. V_145 = V_303 ,
} ;
struct V_147 V_148 = {
. V_149 = V_2 ,
. V_139 = & V_140 ,
. V_152 = & V_153 ,
. V_108 = V_108 ,
} ;
return F_69 ( & V_148 ) ;
}
static void F_128 ( void )
{
F_15 ( V_22 L_73
L_74 ) ;
}
static void F_129 ( const struct V_1 * V_2 ,
const struct V_123 * V_135 )
{
const char * V_304 = L_75 ;
if ( F_51 ( V_135 ) )
V_304 = F_130 ( V_135 -> V_128 ) ;
F_15 ( V_22 L_76 ,
V_135 -> V_188 , V_135 -> V_125 , V_135 -> V_156 ,
V_2 , V_135 -> V_165 , V_135 -> V_230 , V_135 -> V_158 ,
V_2 -> V_51 , V_2 -> V_55 , F_88 ( V_135 ) ,
V_135 -> V_150 , V_304 ) ;
}
void F_131 ( void )
{
struct V_1 * V_2 ;
struct V_123 * V_135 ;
int V_305 = 0 ;
F_2 ( & V_3 ) ;
F_48 (clnt, &all_clients, cl_clients) {
F_2 ( & V_2 -> V_62 ) ;
F_48 (task, &clnt->cl_tasks, tk_task) {
if ( ! V_305 ) {
F_128 () ;
V_305 ++ ;
}
F_129 ( V_2 , V_135 ) ;
}
F_4 ( & V_2 -> V_62 ) ;
}
F_4 ( & V_3 ) ;
}
