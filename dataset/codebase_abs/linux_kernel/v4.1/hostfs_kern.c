static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , struct V_1 , V_3 ) ;
}
static int T_1 F_3 ( char * V_4 , int * V_5 )
{
char * V_6 ;
V_6 = strchr ( V_4 , ',' ) ;
if ( V_6 != NULL )
* V_6 ++ = '\0' ;
if ( * V_4 != '\0' )
V_7 = V_4 ;
V_4 = V_6 ;
while ( V_4 ) {
V_6 = strchr ( V_4 , ',' ) ;
if ( V_6 != NULL )
* V_6 ++ = '\0' ;
if ( * V_4 != '\0' ) {
if ( ! strcmp ( V_4 , L_1 ) )
V_8 = 1 ;
else printf ( L_2 ,
V_4 ) ;
}
V_4 = V_6 ;
}
return 0 ;
}
static char * F_4 ( struct V_9 * V_9 , char * V_10 )
{
char * V_11 = F_5 ( V_9 , V_10 , V_12 ) ;
char * V_13 ;
T_2 V_14 ;
V_13 = V_9 -> V_15 -> V_16 ;
V_14 = strlen ( V_13 ) ;
if ( F_6 ( V_11 ) ) {
F_7 ( V_10 ) ;
return NULL ;
}
F_8 ( V_11 + strlen ( V_11 ) + 1 != V_10 + V_12 ) ;
F_9 ( V_10 , V_13 , V_12 ) ;
if ( V_14 > V_11 - V_10 ) {
F_7 ( V_10 ) ;
return NULL ;
}
if ( V_11 > V_10 + V_14 )
strcpy ( V_10 + V_14 , V_11 ) ;
return V_10 ;
}
static char * F_10 ( struct V_9 * V_9 )
{
char * V_10 = F_11 () ;
if ( ! V_10 )
return NULL ;
return F_4 ( V_9 , V_10 ) ;
}
static char * F_12 ( struct V_2 * V_17 )
{
struct V_9 * V_9 ;
char * V_10 ;
V_9 = F_13 ( V_17 ) ;
if ( ! V_9 )
return NULL ;
V_10 = F_10 ( V_9 ) ;
F_14 ( V_9 ) ;
return V_10 ;
}
static char * F_15 ( char * V_18 )
{
int V_14 , V_19 ;
char * V_10 , * V_20 , * V_21 ;
V_10 = F_11 () ;
if ( ! V_10 ) {
V_19 = - V_22 ;
goto V_23;
}
V_19 = F_16 ( V_18 , V_10 , V_12 ) ;
if ( V_19 < 0 )
goto V_23;
else if ( V_19 == V_12 ) {
V_19 = - V_24 ;
goto V_23;
}
if ( * V_10 == '/' )
return V_10 ;
V_21 = strrchr ( V_18 , '/' ) ;
if ( V_21 == NULL )
return V_10 ;
* ( V_21 + 1 ) = '\0' ;
V_14 = strlen ( V_18 ) + strlen ( V_10 ) + 1 ;
V_20 = F_17 ( V_14 , V_25 ) ;
if ( V_20 == NULL ) {
V_19 = - V_22 ;
goto V_23;
}
sprintf ( V_20 , L_3 , V_18 , V_10 ) ;
F_7 ( V_10 ) ;
F_18 ( V_18 ) ;
return V_20 ;
V_23:
F_7 ( V_10 ) ;
return F_19 ( V_19 ) ;
}
static struct V_2 * F_20 ( struct V_26 * V_27 )
{
struct V_2 * V_2 = F_21 ( V_27 ) ;
if ( ! V_2 )
return F_19 ( - V_22 ) ;
return V_2 ;
}
static int F_22 ( struct V_9 * V_9 , struct V_28 * V_29 )
{
int V_30 ;
long long V_31 ;
long long V_32 ;
long long V_33 ;
long long V_34 ;
long long V_35 ;
V_30 = F_23 ( V_9 -> V_15 -> V_16 ,
& V_29 -> V_36 , & V_31 , & V_32 , & V_33 , & V_34 ,
& V_35 , & V_29 -> V_37 , sizeof( V_29 -> V_37 ) ,
& V_29 -> V_38 ) ;
if ( V_30 )
return V_30 ;
V_29 -> V_31 = V_31 ;
V_29 -> V_32 = V_32 ;
V_29 -> V_33 = V_33 ;
V_29 -> V_34 = V_34 ;
V_29 -> V_35 = V_35 ;
V_29 -> V_39 = V_40 ;
return 0 ;
}
static struct V_2 * F_24 ( struct V_26 * V_27 )
{
struct V_1 * V_41 ;
V_41 = F_17 ( sizeof( * V_41 ) , V_25 ) ;
if ( V_41 == NULL )
return NULL ;
V_41 -> V_42 = - 1 ;
V_41 -> V_43 = 0 ;
F_25 ( & V_41 -> V_3 ) ;
F_26 ( & V_41 -> V_44 ) ;
return & V_41 -> V_3 ;
}
static void F_27 ( struct V_2 * V_2 )
{
F_28 ( & V_2 -> V_45 ) ;
F_29 ( V_2 ) ;
if ( F_1 ( V_2 ) -> V_42 != - 1 ) {
F_30 ( & F_1 ( V_2 ) -> V_42 ) ;
F_1 ( V_2 ) -> V_42 = - 1 ;
}
}
static void F_31 ( struct V_46 * V_47 )
{
struct V_2 * V_2 = F_32 ( V_47 , struct V_2 , V_48 ) ;
F_18 ( F_1 ( V_2 ) ) ;
}
static void F_33 ( struct V_2 * V_2 )
{
F_34 ( & V_2 -> V_48 , F_31 ) ;
}
static int F_35 ( struct V_49 * V_50 , struct V_9 * V_13 )
{
const char * V_51 = V_13 -> V_15 -> V_16 ;
T_2 V_52 = strlen ( V_7 ) + 1 ;
if ( strlen ( V_51 ) > V_52 )
F_36 ( V_50 , L_4 , V_51 + V_52 ) ;
if ( V_8 )
F_37 ( V_50 , L_5 ) ;
return 0 ;
}
static int F_38 ( struct V_53 * V_53 , struct V_54 * V_55 )
{
void * V_56 ;
char * V_10 ;
unsigned long long V_57 , V_17 ;
int error , V_14 ;
unsigned int type ;
V_10 = F_10 ( V_53 -> V_58 . V_9 ) ;
if ( V_10 == NULL )
return - V_22 ;
V_56 = F_39 ( V_10 , & error ) ;
F_7 ( V_10 ) ;
if ( V_56 == NULL )
return - error ;
V_57 = V_55 -> V_59 ;
F_40 ( V_56 , V_57 ) ;
while ( ( V_10 = F_41 ( V_56 , & V_57 , & V_17 , & V_14 , & type ) ) != NULL ) {
if ( ! F_42 ( V_55 , V_10 , V_14 , V_17 , type ) )
break;
V_55 -> V_59 = V_57 ;
}
F_43 ( V_56 ) ;
return 0 ;
}
static int F_44 ( struct V_2 * V_17 , struct V_53 * V_53 )
{
char * V_10 ;
T_3 V_43 ;
int V_30 ;
int V_60 , V_61 , V_42 ;
V_43 = V_53 -> V_62 & ( V_63 | V_64 ) ;
if ( ( V_43 & F_1 ( V_17 ) -> V_43 ) == V_43 )
return 0 ;
V_43 |= F_1 ( V_17 ) -> V_43 ;
V_65:
V_60 = V_61 = 0 ;
if ( V_43 & V_63 )
V_60 = 1 ;
if ( V_43 & V_64 )
V_60 = V_61 = 1 ;
V_10 = F_10 ( V_53 -> V_58 . V_9 ) ;
if ( V_10 == NULL )
return - V_22 ;
V_42 = F_45 ( V_10 , V_60 , V_61 , V_8 ) ;
F_7 ( V_10 ) ;
if ( V_42 < 0 )
return V_42 ;
F_46 ( & F_1 ( V_17 ) -> V_44 ) ;
if ( ( V_43 & F_1 ( V_17 ) -> V_43 ) == V_43 ) {
F_47 ( & F_1 ( V_17 ) -> V_44 ) ;
F_30 ( & V_42 ) ;
return 0 ;
}
if ( ( V_43 | F_1 ( V_17 ) -> V_43 ) != V_43 ) {
V_43 |= F_1 ( V_17 ) -> V_43 ;
F_47 ( & F_1 ( V_17 ) -> V_44 ) ;
F_30 ( & V_42 ) ;
goto V_65;
}
if ( F_1 ( V_17 ) -> V_42 == - 1 ) {
F_1 ( V_17 ) -> V_42 = V_42 ;
} else {
V_30 = F_48 ( V_42 , F_1 ( V_17 ) -> V_42 ) ;
F_30 ( & V_42 ) ;
if ( V_30 < 0 ) {
F_47 ( & F_1 ( V_17 ) -> V_44 ) ;
return V_30 ;
}
}
F_1 ( V_17 ) -> V_43 = V_43 ;
F_47 ( & F_1 ( V_17 ) -> V_44 ) ;
return 0 ;
}
static int F_49 ( struct V_2 * V_2 , struct V_53 * V_53 )
{
F_50 ( V_2 -> V_66 ) ;
return 0 ;
}
static int F_51 ( struct V_53 * V_53 , T_4 V_67 , T_4 V_21 ,
int V_68 )
{
struct V_2 * V_2 = V_53 -> V_69 -> V_70 ;
int V_71 ;
V_71 = F_52 ( V_2 -> V_66 , V_67 , V_21 ) ;
if ( V_71 )
return V_71 ;
F_46 ( & V_2 -> V_72 ) ;
V_71 = F_53 ( F_1 ( V_2 ) -> V_42 , V_68 ) ;
F_47 ( & V_2 -> V_72 ) ;
return V_71 ;
}
static int F_54 ( struct V_73 * V_73 , struct V_74 * V_75 )
{
struct V_76 * V_77 = V_73 -> V_77 ;
struct V_2 * V_2 = V_77 -> V_70 ;
char * V_78 ;
T_4 V_79 = F_55 ( V_73 ) ;
int V_80 = V_81 ;
int V_82 = V_2 -> V_83 >> V_84 ;
int V_30 ;
if ( V_73 -> V_85 >= V_82 )
V_80 = V_2 -> V_83 & ( V_81 - 1 ) ;
V_78 = F_56 ( V_73 ) ;
V_30 = F_57 ( F_1 ( V_2 ) -> V_42 , & V_79 , V_78 , V_80 ) ;
if ( V_30 != V_80 ) {
F_58 ( V_73 ) ;
goto V_86;
}
if ( V_79 > V_2 -> V_83 )
V_2 -> V_83 = V_79 ;
if ( F_59 ( V_73 ) )
F_60 ( V_73 ) ;
V_30 = 0 ;
V_86:
F_61 ( V_73 ) ;
F_62 ( V_73 ) ;
return V_30 ;
}
static int F_63 ( struct V_53 * V_53 , struct V_73 * V_73 )
{
char * V_78 ;
T_4 V_67 = F_55 ( V_73 ) ;
int V_87 , V_71 = 0 ;
V_78 = F_56 ( V_73 ) ;
V_87 = F_64 ( F_65 ( V_53 ) -> V_42 , & V_67 , V_78 ,
V_81 ) ;
if ( V_87 < 0 ) {
F_58 ( V_73 ) ;
F_66 ( V_73 ) ;
V_71 = V_87 ;
goto V_86;
}
memset ( V_78 + V_87 , 0 , V_81 - V_87 ) ;
F_60 ( V_73 ) ;
F_67 ( V_73 ) ;
V_86:
F_68 ( V_73 ) ;
F_61 ( V_73 ) ;
F_62 ( V_73 ) ;
return V_71 ;
}
static int F_69 ( struct V_53 * V_53 , struct V_76 * V_77 ,
T_4 V_59 , unsigned V_14 , unsigned V_88 ,
struct V_73 * * V_89 , void * * V_90 )
{
T_5 V_85 = V_59 >> V_84 ;
* V_89 = F_70 ( V_77 , V_85 , V_88 ) ;
if ( ! * V_89 )
return - V_22 ;
return 0 ;
}
static int F_71 ( struct V_53 * V_53 , struct V_76 * V_77 ,
T_4 V_59 , unsigned V_14 , unsigned V_91 ,
struct V_73 * V_73 , void * V_90 )
{
struct V_2 * V_2 = V_77 -> V_70 ;
void * V_78 ;
unsigned V_92 = V_59 & ( V_81 - 1 ) ;
int V_30 ;
V_78 = F_56 ( V_73 ) ;
V_30 = F_57 ( F_65 ( V_53 ) -> V_42 , & V_59 , V_78 + V_92 , V_91 ) ;
F_61 ( V_73 ) ;
if ( ! F_72 ( V_73 ) && V_30 == V_81 )
F_67 ( V_73 ) ;
if ( V_30 > 0 && ( V_59 > V_2 -> V_83 ) )
V_2 -> V_83 = V_59 ;
F_62 ( V_73 ) ;
F_73 ( V_73 ) ;
return V_30 ;
}
static int F_74 ( struct V_2 * V_17 , char * V_10 )
{
T_6 V_93 ;
struct V_94 V_95 ;
int V_30 = F_75 ( V_10 , & V_95 , - 1 ) ;
if ( V_30 )
return V_30 ;
V_93 = F_76 ( V_95 . V_96 , V_95 . V_97 ) ;
switch ( V_95 . V_43 & V_98 ) {
case V_99 :
V_17 -> V_100 = & V_101 ;
break;
case V_102 :
V_17 -> V_100 = & V_103 ;
V_17 -> V_104 = & V_105 ;
break;
case V_106 :
case V_107 :
case V_108 :
case V_109 :
F_77 ( V_17 , V_95 . V_43 & V_98 , V_93 ) ;
V_17 -> V_100 = & V_110 ;
break;
case V_111 :
V_17 -> V_100 = & V_110 ;
V_17 -> V_104 = & V_112 ;
V_17 -> V_66 -> V_113 = & V_114 ;
break;
default:
return - V_115 ;
}
V_17 -> V_116 = V_95 . V_17 ;
V_17 -> V_117 = V_95 . V_43 ;
F_78 ( V_17 , V_95 . V_118 ) ;
F_79 ( V_17 , V_95 . V_119 ) ;
F_80 ( V_17 , V_95 . V_120 ) ;
V_17 -> V_121 = V_95 . V_122 ;
V_17 -> V_123 = V_95 . V_124 ;
V_17 -> V_125 = V_95 . ctime ;
V_17 -> V_83 = V_95 . V_126 ;
V_17 -> V_127 = V_95 . V_128 ;
return 0 ;
}
static int F_81 ( struct V_2 * V_56 , struct V_9 * V_9 , T_7 V_43 ,
bool V_129 )
{
struct V_2 * V_2 ;
char * V_10 ;
int error , V_42 ;
V_2 = F_20 ( V_56 -> V_130 ) ;
if ( F_6 ( V_2 ) ) {
error = F_82 ( V_2 ) ;
goto V_86;
}
error = - V_22 ;
V_10 = F_10 ( V_9 ) ;
if ( V_10 == NULL )
goto V_131;
V_42 = F_83 ( V_10 , V_43 & 0777 ) ;
if ( V_42 < 0 )
error = V_42 ;
else
error = F_74 ( V_2 , V_10 ) ;
F_7 ( V_10 ) ;
if ( error )
goto V_131;
F_1 ( V_2 ) -> V_42 = V_42 ;
F_1 ( V_2 ) -> V_43 = V_63 | V_64 ;
F_84 ( V_9 , V_2 ) ;
return 0 ;
V_131:
F_85 ( V_2 ) ;
V_86:
return error ;
}
static struct V_9 * F_86 ( struct V_2 * V_17 , struct V_9 * V_9 ,
unsigned int V_88 )
{
struct V_2 * V_2 ;
char * V_10 ;
int V_30 ;
V_2 = F_20 ( V_17 -> V_130 ) ;
if ( F_6 ( V_2 ) ) {
V_30 = F_82 ( V_2 ) ;
goto V_86;
}
V_30 = - V_22 ;
V_10 = F_10 ( V_9 ) ;
if ( V_10 == NULL )
goto V_131;
V_30 = F_74 ( V_2 , V_10 ) ;
F_7 ( V_10 ) ;
if ( V_30 == - V_132 ) {
F_85 ( V_2 ) ;
V_2 = NULL ;
}
else if ( V_30 )
goto V_131;
F_87 ( V_9 , V_2 ) ;
return NULL ;
V_131:
F_85 ( V_2 ) ;
V_86:
return F_19 ( V_30 ) ;
}
static int F_88 ( struct V_9 * V_133 , struct V_2 * V_17 ,
struct V_9 * V_92 )
{
char * V_134 , * V_135 ;
int V_30 ;
if ( ( V_134 = F_10 ( V_92 ) ) == NULL )
return - V_22 ;
V_135 = F_10 ( V_133 ) ;
if ( V_135 == NULL ) {
F_7 ( V_134 ) ;
return - V_22 ;
}
V_30 = F_89 ( V_135 , V_134 ) ;
F_7 ( V_134 ) ;
F_7 ( V_135 ) ;
return V_30 ;
}
static int F_90 ( struct V_2 * V_17 , struct V_9 * V_9 )
{
char * V_53 ;
int V_30 ;
if ( V_8 )
return - V_136 ;
if ( ( V_53 = F_10 ( V_9 ) ) == NULL )
return - V_22 ;
V_30 = F_91 ( V_53 ) ;
F_7 ( V_53 ) ;
return V_30 ;
}
static int F_92 ( struct V_2 * V_17 , struct V_9 * V_9 ,
const char * V_133 )
{
char * V_53 ;
int V_30 ;
if ( ( V_53 = F_10 ( V_9 ) ) == NULL )
return - V_22 ;
V_30 = F_93 ( V_53 , V_133 ) ;
F_7 ( V_53 ) ;
return V_30 ;
}
static int F_94 ( struct V_2 * V_17 , struct V_9 * V_9 , T_7 V_43 )
{
char * V_53 ;
int V_30 ;
if ( ( V_53 = F_10 ( V_9 ) ) == NULL )
return - V_22 ;
V_30 = F_95 ( V_53 , V_43 ) ;
F_7 ( V_53 ) ;
return V_30 ;
}
static int F_96 ( struct V_2 * V_17 , struct V_9 * V_9 )
{
char * V_53 ;
int V_30 ;
if ( ( V_53 = F_10 ( V_9 ) ) == NULL )
return - V_22 ;
V_30 = F_97 ( V_53 ) ;
F_7 ( V_53 ) ;
return V_30 ;
}
static int F_98 ( struct V_2 * V_56 , struct V_9 * V_9 , T_7 V_43 , T_6 V_137 )
{
struct V_2 * V_2 ;
char * V_10 ;
int V_30 ;
V_2 = F_20 ( V_56 -> V_130 ) ;
if ( F_6 ( V_2 ) ) {
V_30 = F_82 ( V_2 ) ;
goto V_86;
}
V_30 = - V_22 ;
V_10 = F_10 ( V_9 ) ;
if ( V_10 == NULL )
goto V_131;
F_77 ( V_2 , V_43 , V_137 ) ;
V_30 = F_99 ( V_10 , V_43 , F_100 ( V_137 ) , F_101 ( V_137 ) ) ;
if ( ! V_30 )
goto V_23;
V_30 = F_74 ( V_2 , V_10 ) ;
F_7 ( V_10 ) ;
if ( V_30 )
goto V_131;
if ( V_30 )
goto V_131;
F_84 ( V_9 , V_2 ) ;
return 0 ;
V_23:
F_7 ( V_10 ) ;
V_131:
F_85 ( V_2 ) ;
V_86:
return V_30 ;
}
static int F_102 ( struct V_2 * V_138 , struct V_9 * V_139 ,
struct V_2 * V_140 , struct V_9 * V_141 ,
unsigned int V_88 )
{
char * V_142 , * V_143 ;
int V_30 ;
if ( V_88 & ~ ( V_144 | V_145 ) )
return - V_146 ;
V_142 = F_10 ( V_139 ) ;
if ( V_142 == NULL )
return - V_22 ;
V_143 = F_10 ( V_141 ) ;
if ( V_143 == NULL ) {
F_7 ( V_142 ) ;
return - V_22 ;
}
if ( ! V_88 )
V_30 = F_103 ( V_142 , V_143 ) ;
else
V_30 = F_104 ( V_142 , V_143 , V_88 ) ;
F_7 ( V_142 ) ;
F_7 ( V_143 ) ;
return V_30 ;
}
static int F_105 ( struct V_2 * V_17 , int V_147 )
{
char * V_10 ;
int V_60 = 0 , V_61 = 0 , V_148 = 0 , V_30 ;
if ( V_147 & V_149 )
return - V_150 ;
if ( V_147 & V_151 ) V_60 = 1 ;
if ( V_147 & V_152 ) V_61 = 1 ;
if ( V_147 & V_153 ) V_148 = 1 ;
V_10 = F_12 ( V_17 ) ;
if ( V_10 == NULL )
return - V_22 ;
if ( F_106 ( V_17 -> V_117 ) || F_107 ( V_17 -> V_117 ) ||
F_108 ( V_17 -> V_117 ) || F_109 ( V_17 -> V_117 ) )
V_30 = 0 ;
else
V_30 = F_110 ( V_10 , V_60 , V_61 , V_148 ) ;
F_7 ( V_10 ) ;
if ( ! V_30 )
V_30 = F_111 ( V_17 , V_147 ) ;
return V_30 ;
}
static int F_112 ( struct V_9 * V_9 , struct V_154 * V_155 )
{
struct V_2 * V_2 = F_113 ( V_9 ) ;
struct V_156 V_157 ;
char * V_10 ;
int V_30 ;
int V_42 = F_1 ( V_2 ) -> V_42 ;
V_30 = F_114 ( V_2 , V_155 ) ;
if ( V_30 )
return V_30 ;
if ( V_8 )
V_155 -> V_158 &= ~ V_159 ;
V_157 . V_158 = 0 ;
if ( V_155 -> V_158 & V_160 ) {
V_157 . V_158 |= V_161 ;
V_157 . V_162 = V_155 -> V_162 ;
}
if ( V_155 -> V_158 & V_163 ) {
V_157 . V_158 |= V_164 ;
V_157 . V_165 = F_115 ( & V_166 , V_155 -> V_165 ) ;
}
if ( V_155 -> V_158 & V_167 ) {
V_157 . V_158 |= V_168 ;
V_157 . V_169 = F_116 ( & V_166 , V_155 -> V_169 ) ;
}
if ( V_155 -> V_158 & V_159 ) {
V_157 . V_158 |= V_170 ;
V_157 . V_171 = V_155 -> V_171 ;
}
if ( V_155 -> V_158 & V_172 ) {
V_157 . V_158 |= V_173 ;
V_157 . V_174 = V_155 -> V_174 ;
}
if ( V_155 -> V_158 & V_175 ) {
V_157 . V_158 |= V_176 ;
V_157 . V_177 = V_155 -> V_177 ;
}
if ( V_155 -> V_158 & V_178 ) {
V_157 . V_158 |= V_179 ;
V_157 . V_180 = V_155 -> V_180 ;
}
if ( V_155 -> V_158 & V_181 ) {
V_157 . V_158 |= V_182 ;
}
if ( V_155 -> V_158 & V_183 ) {
V_157 . V_158 |= V_184 ;
}
V_10 = F_10 ( V_9 ) ;
if ( V_10 == NULL )
return - V_22 ;
V_30 = F_117 ( V_10 , & V_157 , V_42 ) ;
F_7 ( V_10 ) ;
if ( V_30 )
return V_30 ;
if ( ( V_155 -> V_158 & V_159 ) &&
V_155 -> V_171 != F_118 ( V_2 ) )
F_119 ( V_2 , V_155 -> V_171 ) ;
F_120 ( V_2 , V_155 ) ;
F_121 ( V_2 ) ;
return 0 ;
}
static void * F_122 ( struct V_9 * V_9 , struct V_185 * V_186 )
{
char * V_18 = F_11 () ;
if ( V_18 ) {
char * V_187 = F_10 ( V_9 ) ;
int V_30 = - V_22 ;
if ( V_187 ) {
V_30 = F_16 ( V_187 , V_18 , V_12 ) ;
if ( V_30 == V_12 )
V_30 = - V_24 ;
F_7 ( V_187 ) ;
}
if ( V_30 < 0 ) {
F_7 ( V_18 ) ;
V_18 = F_19 ( V_30 ) ;
}
} else {
V_18 = F_19 ( - V_22 ) ;
}
F_123 ( V_186 , V_18 ) ;
return NULL ;
}
static void F_124 ( struct V_9 * V_9 , struct V_185 * V_186 , void * V_188 )
{
char * V_189 = F_125 ( V_186 ) ;
if ( ! F_6 ( V_189 ) )
F_7 ( V_189 ) ;
}
static int F_126 ( struct V_26 * V_27 , void * V_190 , int V_191 )
{
struct V_2 * V_192 ;
char * V_193 , * V_194 = V_190 ;
int V_30 ;
V_27 -> V_195 = 1024 ;
V_27 -> V_196 = 10 ;
V_27 -> V_197 = V_40 ;
V_27 -> V_198 = & V_199 ;
V_27 -> V_200 = & V_201 ;
V_27 -> V_202 = V_203 ;
if ( V_194 == NULL )
V_194 = L_6 ;
V_30 = - V_22 ;
V_27 -> V_16 = V_193 =
F_17 ( strlen ( V_7 ) + strlen ( V_194 ) + 2 , V_25 ) ;
if ( V_193 == NULL )
goto V_86;
sprintf ( V_193 , L_7 , V_7 , V_194 ) ;
V_192 = F_21 ( V_27 ) ;
if ( ! V_192 )
goto V_86;
V_30 = F_74 ( V_192 , V_193 ) ;
if ( V_30 )
goto V_131;
if ( F_127 ( V_192 -> V_117 ) ) {
char * V_10 = F_15 ( V_193 ) ;
if ( F_6 ( V_10 ) )
V_30 = F_82 ( V_10 ) ;
else
V_30 = F_74 ( V_192 , V_10 ) ;
F_18 ( V_10 ) ;
if ( V_30 )
goto V_131;
}
V_30 = - V_22 ;
V_27 -> V_204 = F_128 ( V_192 ) ;
if ( V_27 -> V_204 == NULL )
goto V_86;
return 0 ;
V_131:
F_85 ( V_192 ) ;
V_86:
return V_30 ;
}
static struct V_9 * F_129 ( struct V_205 * type ,
int V_88 , const char * V_206 ,
void * V_207 )
{
return F_130 ( type , V_88 , V_207 , F_126 ) ;
}
static void F_131 ( struct V_26 * V_189 )
{
F_132 ( V_189 ) ;
F_18 ( V_189 -> V_16 ) ;
}
static int T_1 F_133 ( void )
{
return F_134 ( & V_208 ) ;
}
static void T_8 F_135 ( void )
{
F_136 ( & V_208 ) ;
}
