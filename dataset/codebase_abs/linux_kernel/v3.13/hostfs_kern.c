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
F_8 ( V_10 , V_13 , V_12 ) ;
if ( V_14 > V_11 - V_10 ) {
F_7 ( V_10 ) ;
return NULL ;
}
if ( V_11 > V_10 + V_14 ) {
char * V_17 = V_10 + V_14 ;
while ( ( * V_17 ++ = * V_11 ++ ) != '\0' )
;
}
return V_10 ;
}
static char * F_9 ( struct V_9 * V_9 )
{
char * V_10 = F_10 () ;
if ( ! V_10 )
return NULL ;
return F_4 ( V_9 , V_10 ) ;
}
static char * F_11 ( struct V_2 * V_18 )
{
struct V_9 * V_9 ;
char * V_10 ;
V_9 = F_12 ( V_18 ) ;
if ( ! V_9 )
return NULL ;
V_10 = F_9 ( V_9 ) ;
F_13 ( V_9 ) ;
return V_10 ;
}
static char * F_14 ( char * V_19 )
{
int V_14 , V_20 ;
char * V_10 , * V_21 , * V_22 ;
V_14 = 64 ;
while ( 1 ) {
V_20 = - V_23 ;
V_10 = F_15 ( V_14 , V_24 ) ;
if ( V_10 == NULL )
goto V_25;
V_20 = F_16 ( V_19 , V_10 , V_14 ) ;
if ( V_20 < V_14 )
break;
V_14 *= 2 ;
F_17 ( V_10 ) ;
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
V_21 = F_15 ( V_14 , V_24 ) ;
if ( V_21 == NULL ) {
V_20 = - V_23 ;
goto V_26;
}
sprintf ( V_21 , L_3 , V_19 , V_10 ) ;
F_17 ( V_10 ) ;
F_17 ( V_19 ) ;
return V_21 ;
V_26:
F_17 ( V_10 ) ;
V_25:
return F_18 ( V_20 ) ;
}
static struct V_2 * F_19 ( struct V_27 * V_28 )
{
struct V_2 * V_2 = F_20 ( V_28 ) ;
if ( ! V_2 )
return F_18 ( - V_23 ) ;
return V_2 ;
}
int F_21 ( struct V_9 * V_9 , struct V_29 * V_30 )
{
int V_31 ;
long long V_32 ;
long long V_33 ;
long long V_34 ;
long long V_35 ;
long long V_36 ;
V_31 = F_22 ( V_9 -> V_15 -> V_16 ,
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
static struct V_2 * F_23 ( struct V_27 * V_28 )
{
struct V_1 * V_42 ;
V_42 = F_15 ( sizeof( * V_42 ) , V_24 ) ;
if ( V_42 == NULL )
return NULL ;
V_42 -> V_43 = - 1 ;
V_42 -> V_44 = 0 ;
F_24 ( & V_42 -> V_3 ) ;
return & V_42 -> V_3 ;
}
static void F_25 ( struct V_2 * V_2 )
{
F_26 ( & V_2 -> V_45 , 0 ) ;
F_27 ( V_2 ) ;
if ( F_1 ( V_2 ) -> V_43 != - 1 ) {
F_28 ( & F_1 ( V_2 ) -> V_43 ) ;
F_1 ( V_2 ) -> V_43 = - 1 ;
}
}
static void F_29 ( struct V_46 * V_47 )
{
struct V_2 * V_2 = F_30 ( V_47 , struct V_2 , V_48 ) ;
F_17 ( F_1 ( V_2 ) ) ;
}
static void F_31 ( struct V_2 * V_2 )
{
F_32 ( & V_2 -> V_48 , F_29 ) ;
}
static int F_33 ( struct V_49 * V_50 , struct V_9 * V_13 )
{
const char * V_51 = V_13 -> V_15 -> V_16 ;
T_2 V_52 = strlen ( V_7 ) + 1 ;
if ( strlen ( V_51 ) > V_52 )
F_34 ( V_50 , L_4 , V_51 + V_52 ) ;
return 0 ;
}
int F_35 ( struct V_53 * V_53 , struct V_54 * V_55 )
{
void * V_56 ;
char * V_10 ;
unsigned long long V_57 , V_18 ;
int error , V_14 ;
unsigned int type ;
V_10 = F_9 ( V_53 -> V_58 . V_9 ) ;
if ( V_10 == NULL )
return - V_23 ;
V_56 = F_36 ( V_10 , & error ) ;
F_7 ( V_10 ) ;
if ( V_56 == NULL )
return - error ;
V_57 = V_55 -> V_59 ;
while ( ( V_10 = F_37 ( V_56 , & V_57 , & V_18 , & V_14 , & type ) ) != NULL ) {
if ( ! F_38 ( V_55 , V_10 , V_14 , V_18 , type ) )
break;
V_55 -> V_59 = V_57 ;
}
F_39 ( V_56 ) ;
return 0 ;
}
int F_40 ( struct V_2 * V_18 , struct V_53 * V_53 )
{
static F_41 ( V_60 ) ;
char * V_10 ;
T_3 V_44 = 0 ;
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
V_10 = F_9 ( V_53 -> V_58 . V_9 ) ;
if ( V_10 == NULL )
return - V_23 ;
V_43 = F_42 ( V_10 , V_61 , V_62 , V_8 ) ;
F_7 ( V_10 ) ;
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
F_28 ( & V_43 ) ;
goto V_66;
}
if ( F_1 ( V_18 ) -> V_43 == - 1 ) {
F_1 ( V_18 ) -> V_43 = V_43 ;
} else {
V_31 = F_45 ( V_43 , F_1 ( V_18 ) -> V_43 ) ;
F_28 ( & V_43 ) ;
if ( V_31 < 0 ) {
F_44 ( & V_60 ) ;
return V_31 ;
}
}
F_1 ( V_18 ) -> V_44 = V_44 ;
F_44 ( & V_60 ) ;
return 0 ;
}
static int F_46 ( struct V_2 * V_2 , struct V_53 * V_53 )
{
F_47 ( V_2 -> V_67 ) ;
return 0 ;
}
int F_48 ( struct V_53 * V_53 , T_4 V_68 , T_4 V_22 , int V_69 )
{
struct V_2 * V_2 = V_53 -> V_70 -> V_71 ;
int V_72 ;
V_72 = F_49 ( V_2 -> V_67 , V_68 , V_22 ) ;
if ( V_72 )
return V_72 ;
F_43 ( & V_2 -> V_73 ) ;
V_72 = F_50 ( F_1 ( V_2 ) -> V_43 , V_69 ) ;
F_44 ( & V_2 -> V_73 ) ;
return V_72 ;
}
int F_51 ( struct V_74 * V_74 , struct V_75 * V_76 )
{
struct V_77 * V_78 = V_74 -> V_78 ;
struct V_2 * V_2 = V_78 -> V_71 ;
char * V_79 ;
unsigned long long V_80 ;
int V_81 = V_82 ;
int V_83 = V_2 -> V_84 >> V_85 ;
int V_31 ;
if ( V_74 -> V_86 >= V_83 )
V_81 = V_2 -> V_84 & ( V_82 - 1 ) ;
V_79 = F_52 ( V_74 ) ;
V_80 = ( ( unsigned long long ) V_74 -> V_86 ) << V_85 ;
V_31 = F_53 ( F_1 ( V_2 ) -> V_43 , & V_80 , V_79 , V_81 ) ;
if ( V_31 != V_81 ) {
F_54 ( V_74 ) ;
goto V_25;
}
if ( V_80 > V_2 -> V_84 )
V_2 -> V_84 = V_80 ;
if ( F_55 ( V_74 ) )
F_56 ( V_74 ) ;
V_31 = 0 ;
V_25:
F_57 ( V_74 ) ;
F_58 ( V_74 ) ;
return V_31 ;
}
int F_59 ( struct V_53 * V_53 , struct V_74 * V_74 )
{
char * V_79 ;
long long V_68 ;
int V_31 = 0 ;
V_68 = ( long long ) V_74 -> V_86 << V_85 ;
V_79 = F_52 ( V_74 ) ;
V_31 = F_60 ( F_61 ( V_53 ) -> V_43 , & V_68 , V_79 ,
V_82 ) ;
if ( V_31 < 0 )
goto V_25;
memset ( & V_79 [ V_31 ] , 0 , V_82 - V_31 ) ;
F_62 ( V_74 ) ;
F_63 ( V_74 ) ;
if ( F_55 ( V_74 ) ) F_56 ( V_74 ) ;
V_31 = 0 ;
V_25:
F_57 ( V_74 ) ;
F_58 ( V_74 ) ;
return V_31 ;
}
int F_64 ( struct V_53 * V_53 , struct V_77 * V_78 ,
T_4 V_59 , unsigned V_14 , unsigned V_87 ,
struct V_74 * * V_88 , void * * V_89 )
{
T_5 V_86 = V_59 >> V_85 ;
* V_88 = F_65 ( V_78 , V_86 , V_87 ) ;
if ( ! * V_88 )
return - V_23 ;
return 0 ;
}
int F_66 ( struct V_53 * V_53 , struct V_77 * V_78 ,
T_4 V_59 , unsigned V_14 , unsigned V_90 ,
struct V_74 * V_74 , void * V_89 )
{
struct V_2 * V_2 = V_78 -> V_71 ;
void * V_79 ;
unsigned V_91 = V_59 & ( V_82 - 1 ) ;
int V_31 ;
V_79 = F_52 ( V_74 ) ;
V_31 = F_53 ( F_61 ( V_53 ) -> V_43 , & V_59 , V_79 + V_91 , V_90 ) ;
F_57 ( V_74 ) ;
if ( ! F_67 ( V_74 ) && V_31 == V_82 )
F_63 ( V_74 ) ;
if ( V_31 > 0 && ( V_59 > V_2 -> V_84 ) )
V_2 -> V_84 = V_59 ;
F_58 ( V_74 ) ;
F_68 ( V_74 ) ;
return V_31 ;
}
static int F_69 ( struct V_2 * V_18 , char * V_10 )
{
T_6 V_92 ;
struct V_93 V_94 ;
int V_31 = F_70 ( V_10 , & V_94 , - 1 ) ;
if ( V_31 )
return V_31 ;
V_92 = F_71 ( V_94 . V_95 , V_94 . V_96 ) ;
switch ( V_94 . V_44 & V_97 ) {
case V_98 :
V_18 -> V_99 = & V_100 ;
break;
case V_101 :
V_18 -> V_99 = & V_102 ;
V_18 -> V_103 = & V_104 ;
break;
case V_105 :
case V_106 :
case V_107 :
case V_108 :
F_72 ( V_18 , V_94 . V_44 & V_97 , V_92 ) ;
V_18 -> V_99 = & V_109 ;
break;
default:
V_18 -> V_99 = & V_109 ;
V_18 -> V_103 = & V_110 ;
V_18 -> V_67 -> V_111 = & V_112 ;
}
V_18 -> V_113 = V_94 . V_18 ;
V_18 -> V_114 = V_94 . V_44 ;
F_73 ( V_18 , V_94 . V_115 ) ;
F_74 ( V_18 , V_94 . V_116 ) ;
F_75 ( V_18 , V_94 . V_117 ) ;
V_18 -> V_118 = V_94 . V_119 ;
V_18 -> V_120 = V_94 . V_121 ;
V_18 -> V_122 = V_94 . ctime ;
V_18 -> V_84 = V_94 . V_123 ;
V_18 -> V_124 = V_94 . V_125 ;
return 0 ;
}
int F_76 ( struct V_2 * V_56 , struct V_9 * V_9 , T_7 V_44 ,
bool V_126 )
{
struct V_2 * V_2 ;
char * V_10 ;
int error , V_43 ;
V_2 = F_19 ( V_56 -> V_127 ) ;
if ( F_6 ( V_2 ) ) {
error = F_77 ( V_2 ) ;
goto V_25;
}
error = - V_23 ;
V_10 = F_9 ( V_9 ) ;
if ( V_10 == NULL )
goto V_128;
V_43 = F_78 ( V_10 ,
V_44 & V_129 , V_44 & V_130 , V_44 & V_131 ,
V_44 & V_132 , V_44 & V_133 , V_44 & V_134 ,
V_44 & V_135 , V_44 & V_136 , V_44 & V_137 ) ;
if ( V_43 < 0 )
error = V_43 ;
else
error = F_69 ( V_2 , V_10 ) ;
F_7 ( V_10 ) ;
if ( error )
goto V_128;
F_1 ( V_2 ) -> V_43 = V_43 ;
F_1 ( V_2 ) -> V_44 = V_64 | V_65 ;
F_79 ( V_9 , V_2 ) ;
return 0 ;
V_128:
F_80 ( V_2 ) ;
V_25:
return error ;
}
struct V_9 * F_81 ( struct V_2 * V_18 , struct V_9 * V_9 ,
unsigned int V_87 )
{
struct V_2 * V_2 ;
char * V_10 ;
int V_31 ;
V_2 = F_19 ( V_18 -> V_127 ) ;
if ( F_6 ( V_2 ) ) {
V_31 = F_77 ( V_2 ) ;
goto V_25;
}
V_31 = - V_23 ;
V_10 = F_9 ( V_9 ) ;
if ( V_10 == NULL )
goto V_128;
V_31 = F_69 ( V_2 , V_10 ) ;
F_7 ( V_10 ) ;
if ( V_31 == - V_138 ) {
F_80 ( V_2 ) ;
V_2 = NULL ;
}
else if ( V_31 )
goto V_128;
F_82 ( V_9 , V_2 ) ;
return NULL ;
V_128:
F_80 ( V_2 ) ;
V_25:
return F_18 ( V_31 ) ;
}
int F_83 ( struct V_9 * V_139 , struct V_2 * V_18 , struct V_9 * V_91 )
{
char * V_140 , * V_141 ;
int V_31 ;
if ( ( V_140 = F_9 ( V_91 ) ) == NULL )
return - V_23 ;
V_141 = F_9 ( V_139 ) ;
if ( V_141 == NULL ) {
F_7 ( V_140 ) ;
return - V_23 ;
}
V_31 = F_84 ( V_141 , V_140 ) ;
F_7 ( V_140 ) ;
F_7 ( V_141 ) ;
return V_31 ;
}
int F_85 ( struct V_2 * V_18 , struct V_9 * V_9 )
{
char * V_53 ;
int V_31 ;
if ( V_8 )
return - V_142 ;
if ( ( V_53 = F_9 ( V_9 ) ) == NULL )
return - V_23 ;
V_31 = F_86 ( V_53 ) ;
F_7 ( V_53 ) ;
return V_31 ;
}
int F_87 ( struct V_2 * V_18 , struct V_9 * V_9 , const char * V_139 )
{
char * V_53 ;
int V_31 ;
if ( ( V_53 = F_9 ( V_9 ) ) == NULL )
return - V_23 ;
V_31 = F_88 ( V_53 , V_139 ) ;
F_7 ( V_53 ) ;
return V_31 ;
}
int F_89 ( struct V_2 * V_18 , struct V_9 * V_9 , T_7 V_44 )
{
char * V_53 ;
int V_31 ;
if ( ( V_53 = F_9 ( V_9 ) ) == NULL )
return - V_23 ;
V_31 = F_90 ( V_53 , V_44 ) ;
F_7 ( V_53 ) ;
return V_31 ;
}
int F_91 ( struct V_2 * V_18 , struct V_9 * V_9 )
{
char * V_53 ;
int V_31 ;
if ( ( V_53 = F_9 ( V_9 ) ) == NULL )
return - V_23 ;
V_31 = F_92 ( V_53 ) ;
F_7 ( V_53 ) ;
return V_31 ;
}
static int F_93 ( struct V_2 * V_56 , struct V_9 * V_9 , T_7 V_44 , T_6 V_143 )
{
struct V_2 * V_2 ;
char * V_10 ;
int V_31 ;
V_2 = F_19 ( V_56 -> V_127 ) ;
if ( F_6 ( V_2 ) ) {
V_31 = F_77 ( V_2 ) ;
goto V_25;
}
V_31 = - V_23 ;
V_10 = F_9 ( V_9 ) ;
if ( V_10 == NULL )
goto V_128;
F_72 ( V_2 , V_44 , V_143 ) ;
V_31 = F_94 ( V_10 , V_44 , F_95 ( V_143 ) , F_96 ( V_143 ) ) ;
if ( ! V_31 )
goto V_26;
V_31 = F_69 ( V_2 , V_10 ) ;
F_7 ( V_10 ) ;
if ( V_31 )
goto V_128;
if ( V_31 )
goto V_128;
F_79 ( V_9 , V_2 ) ;
return 0 ;
V_26:
F_7 ( V_10 ) ;
V_128:
F_80 ( V_2 ) ;
V_25:
return V_31 ;
}
int F_97 ( struct V_2 * V_144 , struct V_9 * V_91 ,
struct V_2 * V_145 , struct V_9 * V_139 )
{
char * V_140 , * V_141 ;
int V_31 ;
if ( ( V_140 = F_9 ( V_91 ) ) == NULL )
return - V_23 ;
if ( ( V_141 = F_9 ( V_139 ) ) == NULL ) {
F_7 ( V_140 ) ;
return - V_23 ;
}
V_31 = F_98 ( V_140 , V_141 ) ;
F_7 ( V_140 ) ;
F_7 ( V_141 ) ;
return V_31 ;
}
int F_99 ( struct V_2 * V_18 , int V_146 )
{
char * V_10 ;
int V_61 = 0 , V_62 = 0 , V_147 = 0 , V_31 ;
if ( V_146 & V_148 )
return - V_149 ;
if ( V_146 & V_150 ) V_61 = 1 ;
if ( V_146 & V_151 ) V_62 = 1 ;
if ( V_146 & V_152 ) V_147 = 1 ;
V_10 = F_11 ( V_18 ) ;
if ( V_10 == NULL )
return - V_23 ;
if ( F_100 ( V_18 -> V_114 ) || F_101 ( V_18 -> V_114 ) ||
F_102 ( V_18 -> V_114 ) || F_103 ( V_18 -> V_114 ) )
V_31 = 0 ;
else
V_31 = F_104 ( V_10 , V_61 , V_62 , V_147 ) ;
F_7 ( V_10 ) ;
if ( ! V_31 )
V_31 = F_105 ( V_18 , V_146 ) ;
return V_31 ;
}
int F_106 ( struct V_9 * V_9 , struct V_153 * V_154 )
{
struct V_2 * V_2 = V_9 -> V_155 ;
struct V_156 V_157 ;
char * V_10 ;
int V_31 ;
int V_43 = F_1 ( V_2 ) -> V_43 ;
V_31 = F_107 ( V_2 , V_154 ) ;
if ( V_31 )
return V_31 ;
if ( V_8 )
V_154 -> V_158 &= ~ V_159 ;
V_157 . V_158 = 0 ;
if ( V_154 -> V_158 & V_160 ) {
V_157 . V_158 |= V_161 ;
V_157 . V_162 = V_154 -> V_162 ;
}
if ( V_154 -> V_158 & V_163 ) {
V_157 . V_158 |= V_164 ;
V_157 . V_165 = F_108 ( & V_166 , V_154 -> V_165 ) ;
}
if ( V_154 -> V_158 & V_167 ) {
V_157 . V_158 |= V_168 ;
V_157 . V_169 = F_109 ( & V_166 , V_154 -> V_169 ) ;
}
if ( V_154 -> V_158 & V_159 ) {
V_157 . V_158 |= V_170 ;
V_157 . V_171 = V_154 -> V_171 ;
}
if ( V_154 -> V_158 & V_172 ) {
V_157 . V_158 |= V_173 ;
V_157 . V_174 = V_154 -> V_174 ;
}
if ( V_154 -> V_158 & V_175 ) {
V_157 . V_158 |= V_176 ;
V_157 . V_177 = V_154 -> V_177 ;
}
if ( V_154 -> V_158 & V_178 ) {
V_157 . V_158 |= V_179 ;
V_157 . V_180 = V_154 -> V_180 ;
}
if ( V_154 -> V_158 & V_181 ) {
V_157 . V_158 |= V_182 ;
}
if ( V_154 -> V_158 & V_183 ) {
V_157 . V_158 |= V_184 ;
}
V_10 = F_9 ( V_9 ) ;
if ( V_10 == NULL )
return - V_23 ;
V_31 = F_110 ( V_10 , & V_157 , V_43 ) ;
F_7 ( V_10 ) ;
if ( V_31 )
return V_31 ;
if ( ( V_154 -> V_158 & V_159 ) &&
V_154 -> V_171 != F_111 ( V_2 ) )
F_112 ( V_2 , V_154 -> V_171 ) ;
F_113 ( V_2 , V_154 ) ;
F_114 ( V_2 ) ;
return 0 ;
}
static void * F_115 ( struct V_9 * V_9 , struct V_185 * V_186 )
{
char * V_19 = F_10 () ;
if ( V_19 ) {
char * V_187 = F_9 ( V_9 ) ;
int V_31 = - V_23 ;
if ( V_187 ) {
V_31 = F_16 ( V_187 , V_19 , V_12 ) ;
if ( V_31 == V_12 )
V_31 = - V_188 ;
F_7 ( V_187 ) ;
}
if ( V_31 < 0 ) {
F_7 ( V_19 ) ;
V_19 = F_18 ( V_31 ) ;
}
} else {
V_19 = F_18 ( - V_23 ) ;
}
F_116 ( V_186 , V_19 ) ;
return NULL ;
}
static void F_117 ( struct V_9 * V_9 , struct V_185 * V_186 , void * V_189 )
{
char * V_17 = F_118 ( V_186 ) ;
if ( ! F_6 ( V_17 ) )
F_7 ( V_17 ) ;
}
static int F_119 ( struct V_27 * V_28 , void * V_190 , int V_191 )
{
struct V_2 * V_192 ;
char * V_193 , * V_194 = V_190 ;
int V_31 ;
V_28 -> V_195 = 1024 ;
V_28 -> V_196 = 10 ;
V_28 -> V_197 = V_41 ;
V_28 -> V_198 = & V_199 ;
V_28 -> V_200 = & V_201 ;
V_28 -> V_202 = V_203 ;
if ( V_194 == NULL )
V_194 = L_5 ;
V_31 = - V_23 ;
V_28 -> V_16 = V_193 =
F_15 ( strlen ( V_7 ) + strlen ( V_194 ) + 2 , V_24 ) ;
if ( V_193 == NULL )
goto V_25;
sprintf ( V_193 , L_6 , V_7 , V_194 ) ;
V_192 = F_20 ( V_28 ) ;
if ( ! V_192 )
goto V_25;
V_31 = F_69 ( V_192 , V_193 ) ;
if ( V_31 )
goto V_128;
if ( F_120 ( V_192 -> V_114 ) ) {
char * V_10 = F_14 ( V_193 ) ;
if ( F_6 ( V_10 ) )
V_31 = F_77 ( V_10 ) ;
else
V_31 = F_69 ( V_192 , V_10 ) ;
F_17 ( V_10 ) ;
if ( V_31 )
goto V_128;
}
V_31 = - V_23 ;
V_28 -> V_204 = F_121 ( V_192 ) ;
if ( V_28 -> V_204 == NULL )
goto V_25;
return 0 ;
V_128:
F_80 ( V_192 ) ;
V_25:
return V_31 ;
}
static struct V_9 * F_122 ( struct V_205 * type ,
int V_87 , const char * V_206 ,
void * V_207 )
{
return F_123 ( type , V_87 , V_207 , F_119 ) ;
}
static void F_124 ( struct V_27 * V_17 )
{
F_125 ( V_17 ) ;
F_17 ( V_17 -> V_16 ) ;
}
static int T_1 F_126 ( void )
{
return F_127 ( & V_208 ) ;
}
static void T_8 F_128 ( void )
{
F_129 ( & V_208 ) ;
}
