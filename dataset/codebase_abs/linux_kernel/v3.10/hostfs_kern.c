static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , struct V_1 , V_3 ) ;
}
static int F_3 ( const struct V_4 * V_4 )
{
return 1 ;
}
static int T_1 F_4 ( char * V_5 , int * V_6 )
{
char * V_7 ;
V_7 = strchr ( V_5 , ',' ) ;
if ( V_7 != NULL )
* V_7 ++ = '\0' ;
if ( * V_5 != '\0' )
V_8 = V_5 ;
V_5 = V_7 ;
while ( V_5 ) {
V_7 = strchr ( V_5 , ',' ) ;
if ( V_7 != NULL )
* V_7 ++ = '\0' ;
if ( * V_5 != '\0' ) {
if ( ! strcmp ( V_5 , L_1 ) )
V_9 = 1 ;
else printf ( L_2 ,
V_5 ) ;
}
V_5 = V_7 ;
}
return 0 ;
}
static char * F_5 ( struct V_4 * V_4 , char * V_10 )
{
char * V_11 = F_6 ( V_4 , V_10 , V_12 ) ;
char * V_13 ;
T_2 V_14 ;
V_13 = V_4 -> V_15 -> V_16 ;
V_14 = strlen ( V_13 ) ;
if ( F_7 ( V_11 ) ) {
F_8 ( V_10 ) ;
return NULL ;
}
F_9 ( V_10 , V_13 , V_12 ) ;
if ( V_14 > V_11 - V_10 ) {
F_8 ( V_10 ) ;
return NULL ;
}
if ( V_11 > V_10 + V_14 ) {
char * V_17 = V_10 + V_14 ;
while ( ( * V_17 ++ = * V_11 ++ ) != '\0' )
;
}
return V_10 ;
}
static char * F_10 ( struct V_4 * V_4 )
{
char * V_10 = F_11 () ;
if ( ! V_10 )
return NULL ;
return F_5 ( V_4 , V_10 ) ;
}
static char * F_12 ( struct V_2 * V_18 )
{
struct V_4 * V_4 ;
char * V_10 ;
V_4 = F_13 ( V_18 ) ;
if ( ! V_4 )
return NULL ;
V_10 = F_10 ( V_4 ) ;
F_14 ( V_4 ) ;
return V_10 ;
}
static char * F_15 ( char * V_19 )
{
int V_14 , V_20 ;
char * V_10 , * V_21 , * V_22 ;
V_14 = 64 ;
while ( 1 ) {
V_20 = - V_23 ;
V_10 = F_16 ( V_14 , V_24 ) ;
if ( V_10 == NULL )
goto V_25;
V_20 = F_17 ( V_19 , V_10 , V_14 ) ;
if ( V_20 < V_14 )
break;
V_14 *= 2 ;
F_18 ( V_10 ) ;
}
if ( V_20 < 0 )
goto V_26;
if ( * V_10 == '/' )
return V_10 ;
V_22 = strrchr ( V_19 , '/' ) ;
if ( V_22 == NULL )
return V_10 ;
* ( V_22 + 1 ) = '\0' ;
V_14 = strlen ( V_19 ) + strlen ( V_10 ) + 1 ;
V_21 = F_16 ( V_14 , V_24 ) ;
if ( V_21 == NULL ) {
V_20 = - V_23 ;
goto V_26;
}
sprintf ( V_21 , L_3 , V_19 , V_10 ) ;
F_18 ( V_10 ) ;
F_18 ( V_19 ) ;
return V_21 ;
V_26:
F_18 ( V_10 ) ;
V_25:
return F_19 ( V_20 ) ;
}
static struct V_2 * F_20 ( struct V_27 * V_28 )
{
struct V_2 * V_2 = F_21 ( V_28 ) ;
if ( ! V_2 )
return F_19 ( - V_23 ) ;
return V_2 ;
}
int F_22 ( struct V_4 * V_4 , struct V_29 * V_30 )
{
int V_31 ;
long long V_32 ;
long long V_33 ;
long long V_34 ;
long long V_35 ;
long long V_36 ;
V_31 = F_23 ( V_4 -> V_15 -> V_16 ,
& V_30 -> V_37 , & V_32 , & V_33 , & V_34 , & V_35 ,
& V_36 , & V_30 -> V_38 , sizeof( V_30 -> V_38 ) ,
& V_30 -> V_39 ) ;
if ( V_31 )
return V_31 ;
V_30 -> V_32 = V_32 ;
V_30 -> V_33 = V_33 ;
V_30 -> V_34 = V_34 ;
V_30 -> V_35 = V_35 ;
V_30 -> V_36 = V_36 ;
V_30 -> V_40 = V_41 ;
return 0 ;
}
static struct V_2 * F_24 ( struct V_27 * V_28 )
{
struct V_1 * V_42 ;
V_42 = F_16 ( sizeof( * V_42 ) , V_24 ) ;
if ( V_42 == NULL )
return NULL ;
V_42 -> V_43 = - 1 ;
V_42 -> V_44 = 0 ;
F_25 ( & V_42 -> V_3 ) ;
return & V_42 -> V_3 ;
}
static void F_26 ( struct V_2 * V_2 )
{
F_27 ( & V_2 -> V_45 , 0 ) ;
F_28 ( V_2 ) ;
if ( F_1 ( V_2 ) -> V_43 != - 1 ) {
F_29 ( & F_1 ( V_2 ) -> V_43 ) ;
F_1 ( V_2 ) -> V_43 = - 1 ;
}
}
static void F_30 ( struct V_46 * V_47 )
{
struct V_2 * V_2 = F_31 ( V_47 , struct V_2 , V_48 ) ;
F_18 ( F_1 ( V_2 ) ) ;
}
static void F_32 ( struct V_2 * V_2 )
{
F_33 ( & V_2 -> V_48 , F_30 ) ;
}
static int F_34 ( struct V_49 * V_50 , struct V_4 * V_13 )
{
const char * V_51 = V_13 -> V_15 -> V_16 ;
T_2 V_52 = strlen ( V_8 ) + 1 ;
if ( strlen ( V_51 ) > V_52 )
F_35 ( V_50 , L_4 , V_51 + V_52 ) ;
return 0 ;
}
int F_36 ( struct V_53 * V_53 , void * V_54 , T_3 V_55 )
{
void * V_56 ;
char * V_10 ;
unsigned long long V_57 , V_18 ;
int error , V_14 ;
unsigned int type ;
V_10 = F_10 ( V_53 -> V_58 . V_4 ) ;
if ( V_10 == NULL )
return - V_23 ;
V_56 = F_37 ( V_10 , & error ) ;
F_8 ( V_10 ) ;
if ( V_56 == NULL )
return - error ;
V_57 = V_53 -> V_59 ;
while ( ( V_10 = F_38 ( V_56 , & V_57 , & V_18 , & V_14 , & type ) ) != NULL ) {
error = (* V_55)( V_54 , V_10 , V_14 , V_53 -> V_59 ,
V_18 , type ) ;
if ( error ) break;
V_53 -> V_59 = V_57 ;
}
F_39 ( V_56 ) ;
return 0 ;
}
int F_40 ( struct V_2 * V_18 , struct V_53 * V_53 )
{
static F_41 ( V_60 ) ;
char * V_10 ;
T_4 V_44 = 0 ;
int V_31 ;
int V_61 = 0 , V_62 = 0 , V_43 ;
V_44 = V_53 -> V_63 & ( V_64 | V_65 ) ;
if ( ( V_44 & F_1 ( V_18 ) -> V_44 ) == V_44 )
return 0 ;
V_44 |= F_1 ( V_18 ) -> V_44 ;
V_66:
if ( V_44 & V_64 )
V_61 = 1 ;
if ( V_44 & V_65 )
V_62 = 1 ;
if ( V_62 )
V_61 = 1 ;
V_10 = F_10 ( V_53 -> V_58 . V_4 ) ;
if ( V_10 == NULL )
return - V_23 ;
V_43 = F_42 ( V_10 , V_61 , V_62 , V_9 ) ;
F_8 ( V_10 ) ;
if ( V_43 < 0 )
return V_43 ;
F_43 ( & V_60 ) ;
if ( ( V_44 & F_1 ( V_18 ) -> V_44 ) == V_44 ) {
F_44 ( & V_60 ) ;
return 0 ;
}
if ( ( V_44 | F_1 ( V_18 ) -> V_44 ) != V_44 ) {
V_44 |= F_1 ( V_18 ) -> V_44 ;
F_44 ( & V_60 ) ;
F_29 ( & V_43 ) ;
goto V_66;
}
if ( F_1 ( V_18 ) -> V_43 == - 1 ) {
F_1 ( V_18 ) -> V_43 = V_43 ;
} else {
V_31 = F_45 ( V_43 , F_1 ( V_18 ) -> V_43 ) ;
F_29 ( & V_43 ) ;
if ( V_31 < 0 ) {
F_44 ( & V_60 ) ;
return V_31 ;
}
}
F_1 ( V_18 ) -> V_44 = V_44 ;
F_44 ( & V_60 ) ;
return 0 ;
}
int F_46 ( struct V_53 * V_53 , T_5 V_67 , T_5 V_22 , int V_68 )
{
struct V_2 * V_2 = V_53 -> V_69 -> V_70 ;
int V_71 ;
V_71 = F_47 ( V_2 -> V_72 , V_67 , V_22 ) ;
if ( V_71 )
return V_71 ;
F_43 ( & V_2 -> V_73 ) ;
V_71 = F_48 ( F_1 ( V_2 ) -> V_43 , V_68 ) ;
F_44 ( & V_2 -> V_73 ) ;
return V_71 ;
}
int F_49 ( struct V_74 * V_74 , struct V_75 * V_76 )
{
struct V_77 * V_78 = V_74 -> V_78 ;
struct V_2 * V_2 = V_78 -> V_70 ;
char * V_79 ;
unsigned long long V_80 ;
int V_81 = V_82 ;
int V_83 = V_2 -> V_84 >> V_85 ;
int V_31 ;
if ( V_74 -> V_86 >= V_83 )
V_81 = V_2 -> V_84 & ( V_82 - 1 ) ;
V_79 = F_50 ( V_74 ) ;
V_80 = ( ( unsigned long long ) V_74 -> V_86 ) << V_85 ;
V_31 = F_51 ( F_1 ( V_2 ) -> V_43 , & V_80 , V_79 , V_81 ) ;
if ( V_31 != V_81 ) {
F_52 ( V_74 ) ;
goto V_25;
}
if ( V_80 > V_2 -> V_84 )
V_2 -> V_84 = V_80 ;
if ( F_53 ( V_74 ) )
F_54 ( V_74 ) ;
V_31 = 0 ;
V_25:
F_55 ( V_74 ) ;
F_56 ( V_74 ) ;
return V_31 ;
}
int F_57 ( struct V_53 * V_53 , struct V_74 * V_74 )
{
char * V_79 ;
long long V_67 ;
int V_31 = 0 ;
V_67 = ( long long ) V_74 -> V_86 << V_85 ;
V_79 = F_50 ( V_74 ) ;
V_31 = F_58 ( F_59 ( V_53 ) -> V_43 , & V_67 , V_79 ,
V_82 ) ;
if ( V_31 < 0 )
goto V_25;
memset ( & V_79 [ V_31 ] , 0 , V_82 - V_31 ) ;
F_60 ( V_74 ) ;
F_61 ( V_74 ) ;
if ( F_53 ( V_74 ) ) F_54 ( V_74 ) ;
V_31 = 0 ;
V_25:
F_55 ( V_74 ) ;
F_56 ( V_74 ) ;
return V_31 ;
}
int F_62 ( struct V_53 * V_53 , struct V_77 * V_78 ,
T_5 V_87 , unsigned V_14 , unsigned V_88 ,
struct V_74 * * V_89 , void * * V_90 )
{
T_6 V_86 = V_87 >> V_85 ;
* V_89 = F_63 ( V_78 , V_86 , V_88 ) ;
if ( ! * V_89 )
return - V_23 ;
return 0 ;
}
int F_64 ( struct V_53 * V_53 , struct V_77 * V_78 ,
T_5 V_87 , unsigned V_14 , unsigned V_91 ,
struct V_74 * V_74 , void * V_90 )
{
struct V_2 * V_2 = V_78 -> V_70 ;
void * V_79 ;
unsigned V_92 = V_87 & ( V_82 - 1 ) ;
int V_31 ;
V_79 = F_50 ( V_74 ) ;
V_31 = F_51 ( F_59 ( V_53 ) -> V_43 , & V_87 , V_79 + V_92 , V_91 ) ;
F_55 ( V_74 ) ;
if ( ! F_65 ( V_74 ) && V_31 == V_82 )
F_61 ( V_74 ) ;
if ( V_31 > 0 && ( V_87 > V_2 -> V_84 ) )
V_2 -> V_84 = V_87 ;
F_56 ( V_74 ) ;
F_66 ( V_74 ) ;
return V_31 ;
}
static int F_67 ( struct V_2 * V_18 , char * V_10 )
{
T_7 V_93 ;
struct V_94 V_95 ;
int V_31 = F_68 ( V_10 , & V_95 , - 1 ) ;
if ( V_31 )
return V_31 ;
V_93 = F_69 ( V_95 . V_96 , V_95 . V_97 ) ;
switch ( V_95 . V_44 & V_98 ) {
case V_99 :
V_18 -> V_100 = & V_101 ;
break;
case V_102 :
V_18 -> V_100 = & V_103 ;
V_18 -> V_104 = & V_105 ;
break;
case V_106 :
case V_107 :
case V_108 :
case V_109 :
F_70 ( V_18 , V_95 . V_44 & V_98 , V_93 ) ;
V_18 -> V_100 = & V_110 ;
break;
default:
V_18 -> V_100 = & V_110 ;
V_18 -> V_104 = & V_111 ;
V_18 -> V_72 -> V_112 = & V_113 ;
}
V_18 -> V_114 = V_95 . V_18 ;
V_18 -> V_115 = V_95 . V_44 ;
F_71 ( V_18 , V_95 . V_116 ) ;
F_72 ( V_18 , V_95 . V_117 ) ;
F_73 ( V_18 , V_95 . V_118 ) ;
V_18 -> V_119 = V_95 . V_120 ;
V_18 -> V_121 = V_95 . V_122 ;
V_18 -> V_123 = V_95 . ctime ;
V_18 -> V_84 = V_95 . V_124 ;
V_18 -> V_125 = V_95 . V_126 ;
return 0 ;
}
int F_74 ( struct V_2 * V_56 , struct V_4 * V_4 , T_8 V_44 ,
bool V_127 )
{
struct V_2 * V_2 ;
char * V_10 ;
int error , V_43 ;
V_2 = F_20 ( V_56 -> V_128 ) ;
if ( F_7 ( V_2 ) ) {
error = F_75 ( V_2 ) ;
goto V_25;
}
error = - V_23 ;
V_10 = F_10 ( V_4 ) ;
if ( V_10 == NULL )
goto V_129;
V_43 = F_76 ( V_10 ,
V_44 & V_130 , V_44 & V_131 , V_44 & V_132 ,
V_44 & V_133 , V_44 & V_134 , V_44 & V_135 ,
V_44 & V_136 , V_44 & V_137 , V_44 & V_138 ) ;
if ( V_43 < 0 )
error = V_43 ;
else
error = F_67 ( V_2 , V_10 ) ;
F_8 ( V_10 ) ;
if ( error )
goto V_129;
F_1 ( V_2 ) -> V_43 = V_43 ;
F_1 ( V_2 ) -> V_44 = V_64 | V_65 ;
F_77 ( V_4 , V_2 ) ;
return 0 ;
V_129:
F_78 ( V_2 ) ;
V_25:
return error ;
}
struct V_4 * F_79 ( struct V_2 * V_18 , struct V_4 * V_4 ,
unsigned int V_88 )
{
struct V_2 * V_2 ;
char * V_10 ;
int V_31 ;
V_2 = F_20 ( V_18 -> V_128 ) ;
if ( F_7 ( V_2 ) ) {
V_31 = F_75 ( V_2 ) ;
goto V_25;
}
V_31 = - V_23 ;
V_10 = F_10 ( V_4 ) ;
if ( V_10 == NULL )
goto V_129;
V_31 = F_67 ( V_2 , V_10 ) ;
F_8 ( V_10 ) ;
if ( V_31 == - V_139 ) {
F_78 ( V_2 ) ;
V_2 = NULL ;
}
else if ( V_31 )
goto V_129;
F_80 ( V_4 , V_2 ) ;
return NULL ;
V_129:
F_78 ( V_2 ) ;
V_25:
return F_19 ( V_31 ) ;
}
int F_81 ( struct V_4 * V_140 , struct V_2 * V_18 , struct V_4 * V_92 )
{
char * V_141 , * V_142 ;
int V_31 ;
if ( ( V_141 = F_10 ( V_92 ) ) == NULL )
return - V_23 ;
V_142 = F_10 ( V_140 ) ;
if ( V_142 == NULL ) {
F_8 ( V_141 ) ;
return - V_23 ;
}
V_31 = F_82 ( V_142 , V_141 ) ;
F_8 ( V_141 ) ;
F_8 ( V_142 ) ;
return V_31 ;
}
int F_83 ( struct V_2 * V_18 , struct V_4 * V_4 )
{
char * V_53 ;
int V_31 ;
if ( V_9 )
return - V_143 ;
if ( ( V_53 = F_10 ( V_4 ) ) == NULL )
return - V_23 ;
V_31 = F_84 ( V_53 ) ;
F_8 ( V_53 ) ;
return V_31 ;
}
int F_85 ( struct V_2 * V_18 , struct V_4 * V_4 , const char * V_140 )
{
char * V_53 ;
int V_31 ;
if ( ( V_53 = F_10 ( V_4 ) ) == NULL )
return - V_23 ;
V_31 = F_86 ( V_53 , V_140 ) ;
F_8 ( V_53 ) ;
return V_31 ;
}
int F_87 ( struct V_2 * V_18 , struct V_4 * V_4 , T_8 V_44 )
{
char * V_53 ;
int V_31 ;
if ( ( V_53 = F_10 ( V_4 ) ) == NULL )
return - V_23 ;
V_31 = F_88 ( V_53 , V_44 ) ;
F_8 ( V_53 ) ;
return V_31 ;
}
int F_89 ( struct V_2 * V_18 , struct V_4 * V_4 )
{
char * V_53 ;
int V_31 ;
if ( ( V_53 = F_10 ( V_4 ) ) == NULL )
return - V_23 ;
V_31 = F_90 ( V_53 ) ;
F_8 ( V_53 ) ;
return V_31 ;
}
static int F_91 ( struct V_2 * V_56 , struct V_4 * V_4 , T_8 V_44 , T_7 V_144 )
{
struct V_2 * V_2 ;
char * V_10 ;
int V_31 ;
V_2 = F_20 ( V_56 -> V_128 ) ;
if ( F_7 ( V_2 ) ) {
V_31 = F_75 ( V_2 ) ;
goto V_25;
}
V_31 = - V_23 ;
V_10 = F_10 ( V_4 ) ;
if ( V_10 == NULL )
goto V_129;
F_70 ( V_2 , V_44 , V_144 ) ;
V_31 = F_92 ( V_10 , V_44 , F_93 ( V_144 ) , F_94 ( V_144 ) ) ;
if ( ! V_31 )
goto V_26;
V_31 = F_67 ( V_2 , V_10 ) ;
F_8 ( V_10 ) ;
if ( V_31 )
goto V_129;
if ( V_31 )
goto V_129;
F_77 ( V_4 , V_2 ) ;
return 0 ;
V_26:
F_8 ( V_10 ) ;
V_129:
F_78 ( V_2 ) ;
V_25:
return V_31 ;
}
int F_95 ( struct V_2 * V_145 , struct V_4 * V_92 ,
struct V_2 * V_146 , struct V_4 * V_140 )
{
char * V_141 , * V_142 ;
int V_31 ;
if ( ( V_141 = F_10 ( V_92 ) ) == NULL )
return - V_23 ;
if ( ( V_142 = F_10 ( V_140 ) ) == NULL ) {
F_8 ( V_141 ) ;
return - V_23 ;
}
V_31 = F_96 ( V_141 , V_142 ) ;
F_8 ( V_141 ) ;
F_8 ( V_142 ) ;
return V_31 ;
}
int F_97 ( struct V_2 * V_18 , int V_147 )
{
char * V_10 ;
int V_61 = 0 , V_62 = 0 , V_148 = 0 , V_31 ;
if ( V_147 & V_149 )
return - V_150 ;
if ( V_147 & V_151 ) V_61 = 1 ;
if ( V_147 & V_152 ) V_62 = 1 ;
if ( V_147 & V_153 ) V_148 = 1 ;
V_10 = F_12 ( V_18 ) ;
if ( V_10 == NULL )
return - V_23 ;
if ( F_98 ( V_18 -> V_115 ) || F_99 ( V_18 -> V_115 ) ||
F_100 ( V_18 -> V_115 ) || F_101 ( V_18 -> V_115 ) )
V_31 = 0 ;
else
V_31 = F_102 ( V_10 , V_61 , V_62 , V_148 ) ;
F_8 ( V_10 ) ;
if ( ! V_31 )
V_31 = F_103 ( V_18 , V_147 ) ;
return V_31 ;
}
int F_104 ( struct V_4 * V_4 , struct V_154 * V_155 )
{
struct V_2 * V_2 = V_4 -> V_156 ;
struct V_157 V_158 ;
char * V_10 ;
int V_31 ;
int V_43 = F_1 ( V_2 ) -> V_43 ;
V_31 = F_105 ( V_2 , V_155 ) ;
if ( V_31 )
return V_31 ;
if ( V_9 )
V_155 -> V_159 &= ~ V_160 ;
V_158 . V_159 = 0 ;
if ( V_155 -> V_159 & V_161 ) {
V_158 . V_159 |= V_162 ;
V_158 . V_163 = V_155 -> V_163 ;
}
if ( V_155 -> V_159 & V_164 ) {
V_158 . V_159 |= V_165 ;
V_158 . V_166 = F_106 ( & V_167 , V_155 -> V_166 ) ;
}
if ( V_155 -> V_159 & V_168 ) {
V_158 . V_159 |= V_169 ;
V_158 . V_170 = F_107 ( & V_167 , V_155 -> V_170 ) ;
}
if ( V_155 -> V_159 & V_160 ) {
V_158 . V_159 |= V_171 ;
V_158 . V_172 = V_155 -> V_172 ;
}
if ( V_155 -> V_159 & V_173 ) {
V_158 . V_159 |= V_174 ;
V_158 . V_175 = V_155 -> V_175 ;
}
if ( V_155 -> V_159 & V_176 ) {
V_158 . V_159 |= V_177 ;
V_158 . V_178 = V_155 -> V_178 ;
}
if ( V_155 -> V_159 & V_179 ) {
V_158 . V_159 |= V_180 ;
V_158 . V_181 = V_155 -> V_181 ;
}
if ( V_155 -> V_159 & V_182 ) {
V_158 . V_159 |= V_183 ;
}
if ( V_155 -> V_159 & V_184 ) {
V_158 . V_159 |= V_185 ;
}
V_10 = F_10 ( V_4 ) ;
if ( V_10 == NULL )
return - V_23 ;
V_31 = F_108 ( V_10 , & V_158 , V_43 ) ;
F_8 ( V_10 ) ;
if ( V_31 )
return V_31 ;
if ( ( V_155 -> V_159 & V_160 ) &&
V_155 -> V_172 != F_109 ( V_2 ) )
F_110 ( V_2 , V_155 -> V_172 ) ;
F_111 ( V_2 , V_155 ) ;
F_112 ( V_2 ) ;
return 0 ;
}
static void * F_113 ( struct V_4 * V_4 , struct V_186 * V_187 )
{
char * V_19 = F_11 () ;
if ( V_19 ) {
char * V_188 = F_10 ( V_4 ) ;
int V_31 = - V_23 ;
if ( V_188 ) {
V_31 = F_17 ( V_188 , V_19 , V_12 ) ;
if ( V_31 == V_12 )
V_31 = - V_189 ;
F_8 ( V_188 ) ;
}
if ( V_31 < 0 ) {
F_8 ( V_19 ) ;
V_19 = F_19 ( V_31 ) ;
}
} else {
V_19 = F_19 ( - V_23 ) ;
}
F_114 ( V_187 , V_19 ) ;
return NULL ;
}
static void F_115 ( struct V_4 * V_4 , struct V_186 * V_187 , void * V_190 )
{
char * V_17 = F_116 ( V_187 ) ;
if ( ! F_7 ( V_17 ) )
F_8 ( V_17 ) ;
}
static int F_117 ( struct V_27 * V_28 , void * V_191 , int V_192 )
{
struct V_2 * V_193 ;
char * V_194 , * V_195 = V_191 ;
int V_31 ;
V_28 -> V_196 = 1024 ;
V_28 -> V_197 = 10 ;
V_28 -> V_198 = V_41 ;
V_28 -> V_199 = & V_200 ;
V_28 -> V_201 = & V_202 ;
V_28 -> V_203 = V_204 ;
if ( V_195 == NULL )
V_195 = L_5 ;
V_31 = - V_23 ;
V_28 -> V_16 = V_194 =
F_16 ( strlen ( V_8 ) + strlen ( V_195 ) + 2 , V_24 ) ;
if ( V_194 == NULL )
goto V_25;
sprintf ( V_194 , L_6 , V_8 , V_195 ) ;
V_193 = F_21 ( V_28 ) ;
if ( ! V_193 )
goto V_25;
V_31 = F_67 ( V_193 , V_194 ) ;
if ( V_31 )
goto V_129;
if ( F_118 ( V_193 -> V_115 ) ) {
char * V_10 = F_15 ( V_194 ) ;
if ( F_7 ( V_10 ) )
V_31 = F_75 ( V_10 ) ;
else
V_31 = F_67 ( V_193 , V_10 ) ;
F_18 ( V_10 ) ;
if ( V_31 )
goto V_129;
}
V_31 = - V_23 ;
V_28 -> V_205 = F_119 ( V_193 ) ;
if ( V_28 -> V_205 == NULL )
goto V_25;
return 0 ;
V_129:
F_78 ( V_193 ) ;
V_25:
return V_31 ;
}
static struct V_4 * F_120 ( struct V_206 * type ,
int V_88 , const char * V_207 ,
void * V_208 )
{
return F_121 ( type , V_88 , V_208 , F_117 ) ;
}
static void F_122 ( struct V_27 * V_17 )
{
F_123 ( V_17 ) ;
F_18 ( V_17 -> V_16 ) ;
}
static int T_1 F_124 ( void )
{
return F_125 ( & V_209 ) ;
}
static void T_9 F_126 ( void )
{
F_127 ( & V_209 ) ;
}
