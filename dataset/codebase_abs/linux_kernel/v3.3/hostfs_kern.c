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
V_42 = F_25 ( sizeof( * V_42 ) , V_24 ) ;
if ( V_42 == NULL )
return NULL ;
V_42 -> V_43 = - 1 ;
F_26 ( & V_42 -> V_3 ) ;
return & V_42 -> V_3 ;
}
static void F_27 ( struct V_2 * V_2 )
{
F_28 ( & V_2 -> V_44 , 0 ) ;
F_29 ( V_2 ) ;
if ( F_1 ( V_2 ) -> V_43 != - 1 ) {
F_30 ( & F_1 ( V_2 ) -> V_43 ) ;
F_1 ( V_2 ) -> V_43 = - 1 ;
}
}
static void F_31 ( struct V_45 * V_46 )
{
struct V_2 * V_2 = F_32 ( V_46 , struct V_2 , V_47 ) ;
F_18 ( F_1 ( V_2 ) ) ;
}
static void F_33 ( struct V_2 * V_2 )
{
F_34 ( & V_2 -> V_47 , F_31 ) ;
}
static int F_35 ( struct V_48 * V_49 , struct V_4 * V_13 )
{
const char * V_50 = V_13 -> V_15 -> V_16 ;
T_2 V_51 = strlen ( V_8 ) + 1 ;
if ( strlen ( V_50 ) > V_51 )
F_36 ( V_49 , L_4 , V_50 + V_51 ) ;
return 0 ;
}
int F_37 ( struct V_52 * V_52 , void * V_53 , T_3 V_54 )
{
void * V_55 ;
char * V_10 ;
unsigned long long V_56 , V_18 ;
int error , V_14 ;
V_10 = F_10 ( V_52 -> V_57 . V_4 ) ;
if ( V_10 == NULL )
return - V_23 ;
V_55 = F_38 ( V_10 , & error ) ;
F_8 ( V_10 ) ;
if ( V_55 == NULL )
return - error ;
V_56 = V_52 -> V_58 ;
while ( ( V_10 = F_39 ( V_55 , & V_56 , & V_18 , & V_14 ) ) != NULL ) {
error = (* V_54)( V_53 , V_10 , V_14 , V_52 -> V_58 ,
V_18 , V_59 ) ;
if ( error ) break;
V_52 -> V_58 = V_56 ;
}
F_40 ( V_55 ) ;
return 0 ;
}
int F_41 ( struct V_2 * V_18 , struct V_52 * V_52 )
{
static F_42 ( V_60 ) ;
char * V_10 ;
T_4 V_61 = 0 ;
int V_31 ;
int V_62 = 0 , V_63 = 0 , V_43 ;
V_61 = V_52 -> V_64 & ( V_65 | V_66 ) ;
if ( ( V_61 & F_1 ( V_18 ) -> V_61 ) == V_61 )
return 0 ;
V_61 |= F_1 ( V_18 ) -> V_61 ;
V_67:
if ( V_61 & V_65 )
V_62 = 1 ;
if ( V_61 & V_66 )
V_63 = 1 ;
if ( V_63 )
V_62 = 1 ;
V_10 = F_10 ( V_52 -> V_57 . V_4 ) ;
if ( V_10 == NULL )
return - V_23 ;
V_43 = F_43 ( V_10 , V_62 , V_63 , V_9 ) ;
F_8 ( V_10 ) ;
if ( V_43 < 0 )
return V_43 ;
F_44 ( & V_60 ) ;
if ( ( V_61 & F_1 ( V_18 ) -> V_61 ) == V_61 ) {
F_45 ( & V_60 ) ;
return 0 ;
}
if ( ( V_61 | F_1 ( V_18 ) -> V_61 ) != V_61 ) {
V_61 |= F_1 ( V_18 ) -> V_61 ;
F_45 ( & V_60 ) ;
F_30 ( & V_43 ) ;
goto V_67;
}
if ( F_1 ( V_18 ) -> V_43 == - 1 ) {
F_1 ( V_18 ) -> V_43 = V_43 ;
} else {
V_31 = F_46 ( V_43 , F_1 ( V_18 ) -> V_43 ) ;
F_30 ( & V_43 ) ;
if ( V_31 < 0 ) {
F_45 ( & V_60 ) ;
return V_31 ;
}
}
F_1 ( V_18 ) -> V_61 = V_61 ;
F_45 ( & V_60 ) ;
return 0 ;
}
int F_47 ( struct V_52 * V_52 , T_5 V_68 , T_5 V_22 , int V_69 )
{
struct V_2 * V_2 = V_52 -> V_70 -> V_71 ;
int V_72 ;
V_72 = F_48 ( V_2 -> V_73 , V_68 , V_22 ) ;
if ( V_72 )
return V_72 ;
F_44 ( & V_2 -> V_74 ) ;
V_72 = F_49 ( F_1 ( V_2 ) -> V_43 , V_69 ) ;
F_45 ( & V_2 -> V_74 ) ;
return V_72 ;
}
int F_50 ( struct V_75 * V_75 , struct V_76 * V_77 )
{
struct V_78 * V_79 = V_75 -> V_79 ;
struct V_2 * V_2 = V_79 -> V_71 ;
char * V_80 ;
unsigned long long V_81 ;
int V_82 = V_83 ;
int V_84 = V_2 -> V_85 >> V_86 ;
int V_31 ;
if ( V_75 -> V_87 >= V_84 )
V_82 = V_2 -> V_85 & ( V_83 - 1 ) ;
V_80 = F_51 ( V_75 ) ;
V_81 = ( ( unsigned long long ) V_75 -> V_87 ) << V_86 ;
V_31 = F_52 ( F_1 ( V_2 ) -> V_43 , & V_81 , V_80 , V_82 ) ;
if ( V_31 != V_82 ) {
F_53 ( V_75 ) ;
goto V_25;
}
if ( V_81 > V_2 -> V_85 )
V_2 -> V_85 = V_81 ;
if ( F_54 ( V_75 ) )
F_55 ( V_75 ) ;
V_31 = 0 ;
V_25:
F_56 ( V_75 ) ;
F_57 ( V_75 ) ;
return V_31 ;
}
int F_58 ( struct V_52 * V_52 , struct V_75 * V_75 )
{
char * V_80 ;
long long V_68 ;
int V_31 = 0 ;
V_68 = ( long long ) V_75 -> V_87 << V_86 ;
V_80 = F_51 ( V_75 ) ;
V_31 = F_59 ( F_60 ( V_52 ) -> V_43 , & V_68 , V_80 ,
V_83 ) ;
if ( V_31 < 0 )
goto V_25;
memset ( & V_80 [ V_31 ] , 0 , V_83 - V_31 ) ;
F_61 ( V_75 ) ;
F_62 ( V_75 ) ;
if ( F_54 ( V_75 ) ) F_55 ( V_75 ) ;
V_31 = 0 ;
V_25:
F_56 ( V_75 ) ;
F_57 ( V_75 ) ;
return V_31 ;
}
int F_63 ( struct V_52 * V_52 , struct V_78 * V_79 ,
T_5 V_88 , unsigned V_14 , unsigned V_89 ,
struct V_75 * * V_90 , void * * V_91 )
{
T_6 V_87 = V_88 >> V_86 ;
* V_90 = F_64 ( V_79 , V_87 , V_89 ) ;
if ( ! * V_90 )
return - V_23 ;
return 0 ;
}
int F_65 ( struct V_52 * V_52 , struct V_78 * V_79 ,
T_5 V_88 , unsigned V_14 , unsigned V_92 ,
struct V_75 * V_75 , void * V_91 )
{
struct V_2 * V_2 = V_79 -> V_71 ;
void * V_80 ;
unsigned V_93 = V_88 & ( V_83 - 1 ) ;
int V_31 ;
V_80 = F_51 ( V_75 ) ;
V_31 = F_52 ( F_60 ( V_52 ) -> V_43 , & V_88 , V_80 + V_93 , V_92 ) ;
F_56 ( V_75 ) ;
if ( ! F_66 ( V_75 ) && V_31 == V_83 )
F_62 ( V_75 ) ;
if ( V_31 > 0 && ( V_88 > V_2 -> V_85 ) )
V_2 -> V_85 = V_88 ;
F_57 ( V_75 ) ;
F_67 ( V_75 ) ;
return V_31 ;
}
static int F_68 ( struct V_2 * V_18 , char * V_10 )
{
T_7 V_94 ;
struct V_95 V_96 ;
int V_31 = F_69 ( V_10 , & V_96 , - 1 ) ;
if ( V_31 )
return V_31 ;
V_94 = F_70 ( V_96 . V_97 , V_96 . V_98 ) ;
switch ( V_96 . V_61 & V_99 ) {
case V_100 :
V_18 -> V_101 = & V_102 ;
break;
case V_103 :
V_18 -> V_101 = & V_104 ;
V_18 -> V_105 = & V_106 ;
break;
case V_107 :
case V_108 :
case V_109 :
case V_110 :
F_71 ( V_18 , V_96 . V_61 & V_99 , V_94 ) ;
V_18 -> V_101 = & V_111 ;
break;
default:
V_18 -> V_101 = & V_111 ;
V_18 -> V_105 = & V_112 ;
V_18 -> V_73 -> V_113 = & V_114 ;
}
V_18 -> V_115 = V_96 . V_18 ;
V_18 -> V_116 = V_96 . V_61 ;
F_72 ( V_18 , V_96 . V_117 ) ;
V_18 -> V_118 = V_96 . V_119 ;
V_18 -> V_120 = V_96 . V_121 ;
V_18 -> V_122 = V_96 . V_123 ;
V_18 -> V_124 = V_96 . V_125 ;
V_18 -> V_126 = V_96 . ctime ;
V_18 -> V_85 = V_96 . V_127 ;
V_18 -> V_128 = V_96 . V_129 ;
return 0 ;
}
int F_73 ( struct V_2 * V_55 , struct V_4 * V_4 , T_8 V_61 ,
struct V_130 * V_131 )
{
struct V_2 * V_2 ;
char * V_10 ;
int error , V_43 ;
V_2 = F_20 ( V_55 -> V_132 ) ;
if ( F_7 ( V_2 ) ) {
error = F_74 ( V_2 ) ;
goto V_25;
}
error = - V_23 ;
V_10 = F_10 ( V_4 ) ;
if ( V_10 == NULL )
goto V_133;
V_43 = F_75 ( V_10 ,
V_61 & V_134 , V_61 & V_135 , V_61 & V_136 ,
V_61 & V_137 , V_61 & V_138 , V_61 & V_139 ,
V_61 & V_140 , V_61 & V_141 , V_61 & V_142 ) ;
if ( V_43 < 0 )
error = V_43 ;
else
error = F_68 ( V_2 , V_10 ) ;
F_8 ( V_10 ) ;
if ( error )
goto V_133;
F_1 ( V_2 ) -> V_43 = V_43 ;
F_1 ( V_2 ) -> V_61 = V_65 | V_66 ;
F_76 ( V_4 , V_2 ) ;
return 0 ;
V_133:
F_77 ( V_2 ) ;
V_25:
return error ;
}
struct V_4 * F_78 ( struct V_2 * V_18 , struct V_4 * V_4 ,
struct V_130 * V_131 )
{
struct V_2 * V_2 ;
char * V_10 ;
int V_31 ;
V_2 = F_20 ( V_18 -> V_132 ) ;
if ( F_7 ( V_2 ) ) {
V_31 = F_74 ( V_2 ) ;
goto V_25;
}
V_31 = - V_23 ;
V_10 = F_10 ( V_4 ) ;
if ( V_10 == NULL )
goto V_133;
V_31 = F_68 ( V_2 , V_10 ) ;
F_8 ( V_10 ) ;
if ( V_31 == - V_143 ) {
F_77 ( V_2 ) ;
V_2 = NULL ;
}
else if ( V_31 )
goto V_133;
F_79 ( V_4 , V_2 ) ;
return NULL ;
V_133:
F_77 ( V_2 ) ;
V_25:
return F_19 ( V_31 ) ;
}
int F_80 ( struct V_4 * V_144 , struct V_2 * V_18 , struct V_4 * V_93 )
{
char * V_145 , * V_146 ;
int V_31 ;
if ( ( V_145 = F_10 ( V_93 ) ) == NULL )
return - V_23 ;
V_146 = F_10 ( V_144 ) ;
if ( V_146 == NULL ) {
F_8 ( V_145 ) ;
return - V_23 ;
}
V_31 = F_81 ( V_146 , V_145 ) ;
F_8 ( V_145 ) ;
F_8 ( V_146 ) ;
return V_31 ;
}
int F_82 ( struct V_2 * V_18 , struct V_4 * V_4 )
{
char * V_52 ;
int V_31 ;
if ( V_9 )
return - V_147 ;
if ( ( V_52 = F_10 ( V_4 ) ) == NULL )
return - V_23 ;
V_31 = F_83 ( V_52 ) ;
F_8 ( V_52 ) ;
return V_31 ;
}
int F_84 ( struct V_2 * V_18 , struct V_4 * V_4 , const char * V_144 )
{
char * V_52 ;
int V_31 ;
if ( ( V_52 = F_10 ( V_4 ) ) == NULL )
return - V_23 ;
V_31 = F_85 ( V_52 , V_144 ) ;
F_8 ( V_52 ) ;
return V_31 ;
}
int F_86 ( struct V_2 * V_18 , struct V_4 * V_4 , T_8 V_61 )
{
char * V_52 ;
int V_31 ;
if ( ( V_52 = F_10 ( V_4 ) ) == NULL )
return - V_23 ;
V_31 = F_87 ( V_52 , V_61 ) ;
F_8 ( V_52 ) ;
return V_31 ;
}
int F_88 ( struct V_2 * V_18 , struct V_4 * V_4 )
{
char * V_52 ;
int V_31 ;
if ( ( V_52 = F_10 ( V_4 ) ) == NULL )
return - V_23 ;
V_31 = F_89 ( V_52 ) ;
F_8 ( V_52 ) ;
return V_31 ;
}
static int F_90 ( struct V_2 * V_55 , struct V_4 * V_4 , T_8 V_61 , T_7 V_148 )
{
struct V_2 * V_2 ;
char * V_10 ;
int V_31 ;
V_2 = F_20 ( V_55 -> V_132 ) ;
if ( F_7 ( V_2 ) ) {
V_31 = F_74 ( V_2 ) ;
goto V_25;
}
V_31 = - V_23 ;
V_10 = F_10 ( V_4 ) ;
if ( V_10 == NULL )
goto V_133;
F_71 ( V_2 , V_61 , V_148 ) ;
V_31 = F_91 ( V_10 , V_61 , F_92 ( V_148 ) , F_93 ( V_148 ) ) ;
if ( ! V_31 )
goto V_26;
V_31 = F_68 ( V_2 , V_10 ) ;
F_8 ( V_10 ) ;
if ( V_31 )
goto V_133;
if ( V_31 )
goto V_133;
F_76 ( V_4 , V_2 ) ;
return 0 ;
V_26:
F_8 ( V_10 ) ;
V_133:
F_77 ( V_2 ) ;
V_25:
return V_31 ;
}
int F_94 ( struct V_2 * V_149 , struct V_4 * V_93 ,
struct V_2 * V_150 , struct V_4 * V_144 )
{
char * V_145 , * V_146 ;
int V_31 ;
if ( ( V_145 = F_10 ( V_93 ) ) == NULL )
return - V_23 ;
if ( ( V_146 = F_10 ( V_144 ) ) == NULL ) {
F_8 ( V_145 ) ;
return - V_23 ;
}
V_31 = F_95 ( V_145 , V_146 ) ;
F_8 ( V_145 ) ;
F_8 ( V_146 ) ;
return V_31 ;
}
int F_96 ( struct V_2 * V_18 , int V_151 )
{
char * V_10 ;
int V_62 = 0 , V_63 = 0 , V_152 = 0 , V_31 ;
if ( V_151 & V_153 )
return - V_154 ;
if ( V_151 & V_155 ) V_62 = 1 ;
if ( V_151 & V_156 ) V_63 = 1 ;
if ( V_151 & V_157 ) V_152 = 1 ;
V_10 = F_12 ( V_18 ) ;
if ( V_10 == NULL )
return - V_23 ;
if ( F_97 ( V_18 -> V_116 ) || F_98 ( V_18 -> V_116 ) ||
F_99 ( V_18 -> V_116 ) || F_100 ( V_18 -> V_116 ) )
V_31 = 0 ;
else
V_31 = F_101 ( V_10 , V_62 , V_63 , V_152 ) ;
F_8 ( V_10 ) ;
if ( ! V_31 )
V_31 = F_102 ( V_18 , V_151 ) ;
return V_31 ;
}
int F_103 ( struct V_4 * V_4 , struct V_158 * V_159 )
{
struct V_2 * V_2 = V_4 -> V_160 ;
struct V_161 V_162 ;
char * V_10 ;
int V_31 ;
int V_43 = F_1 ( V_2 ) -> V_43 ;
V_31 = F_104 ( V_2 , V_159 ) ;
if ( V_31 )
return V_31 ;
if ( V_9 )
V_159 -> V_163 &= ~ V_164 ;
V_162 . V_163 = 0 ;
if ( V_159 -> V_163 & V_165 ) {
V_162 . V_163 |= V_166 ;
V_162 . V_167 = V_159 -> V_167 ;
}
if ( V_159 -> V_163 & V_168 ) {
V_162 . V_163 |= V_169 ;
V_162 . V_170 = V_159 -> V_170 ;
}
if ( V_159 -> V_163 & V_171 ) {
V_162 . V_163 |= V_172 ;
V_162 . V_173 = V_159 -> V_173 ;
}
if ( V_159 -> V_163 & V_164 ) {
V_162 . V_163 |= V_174 ;
V_162 . V_175 = V_159 -> V_175 ;
}
if ( V_159 -> V_163 & V_176 ) {
V_162 . V_163 |= V_177 ;
V_162 . V_178 = V_159 -> V_178 ;
}
if ( V_159 -> V_163 & V_179 ) {
V_162 . V_163 |= V_180 ;
V_162 . V_181 = V_159 -> V_181 ;
}
if ( V_159 -> V_163 & V_182 ) {
V_162 . V_163 |= V_183 ;
V_162 . V_184 = V_159 -> V_184 ;
}
if ( V_159 -> V_163 & V_185 ) {
V_162 . V_163 |= V_186 ;
}
if ( V_159 -> V_163 & V_187 ) {
V_162 . V_163 |= V_188 ;
}
V_10 = F_10 ( V_4 ) ;
if ( V_10 == NULL )
return - V_23 ;
V_31 = F_105 ( V_10 , & V_162 , V_43 ) ;
F_8 ( V_10 ) ;
if ( V_31 )
return V_31 ;
if ( ( V_159 -> V_163 & V_164 ) &&
V_159 -> V_175 != F_106 ( V_2 ) ) {
int error ;
error = F_107 ( V_2 , V_159 -> V_175 ) ;
if ( V_31 )
return V_31 ;
}
F_108 ( V_2 , V_159 ) ;
F_109 ( V_2 ) ;
return 0 ;
}
static void * F_110 ( struct V_4 * V_4 , struct V_130 * V_131 )
{
char * V_19 = F_11 () ;
if ( V_19 ) {
char * V_189 = F_10 ( V_4 ) ;
int V_31 = - V_23 ;
if ( V_189 ) {
V_31 = F_17 ( V_189 , V_19 , V_12 ) ;
if ( V_31 == V_12 )
V_31 = - V_190 ;
F_8 ( V_189 ) ;
}
if ( V_31 < 0 ) {
F_8 ( V_19 ) ;
V_19 = F_19 ( V_31 ) ;
}
} else {
V_19 = F_19 ( - V_23 ) ;
}
F_111 ( V_131 , V_19 ) ;
return NULL ;
}
static void F_112 ( struct V_4 * V_4 , struct V_130 * V_131 , void * V_191 )
{
char * V_17 = F_113 ( V_131 ) ;
if ( ! F_7 ( V_17 ) )
F_8 ( V_17 ) ;
}
static int F_114 ( struct V_27 * V_28 , void * V_192 , int V_193 )
{
struct V_2 * V_194 ;
char * V_195 , * V_196 = V_192 ;
int V_31 ;
V_28 -> V_197 = 1024 ;
V_28 -> V_198 = 10 ;
V_28 -> V_199 = V_41 ;
V_28 -> V_200 = & V_201 ;
V_28 -> V_202 = & V_203 ;
V_28 -> V_204 = V_205 ;
if ( V_196 == NULL )
V_196 = L_5 ;
V_31 = - V_23 ;
V_28 -> V_16 = V_195 =
F_16 ( strlen ( V_8 ) + strlen ( V_196 ) + 2 , V_24 ) ;
if ( V_195 == NULL )
goto V_25;
sprintf ( V_195 , L_6 , V_8 , V_196 ) ;
V_194 = F_21 ( V_28 ) ;
if ( ! V_194 )
goto V_25;
V_31 = F_68 ( V_194 , V_195 ) ;
if ( V_31 )
goto V_133;
if ( F_115 ( V_194 -> V_116 ) ) {
char * V_10 = F_15 ( V_195 ) ;
if ( F_7 ( V_10 ) )
V_31 = F_74 ( V_10 ) ;
else
V_31 = F_68 ( V_194 , V_10 ) ;
F_18 ( V_10 ) ;
if ( V_31 )
goto V_133;
}
V_31 = - V_23 ;
V_28 -> V_206 = F_116 ( V_194 ) ;
if ( V_28 -> V_206 == NULL )
goto V_133;
return 0 ;
V_133:
F_77 ( V_194 ) ;
V_25:
return V_31 ;
}
static struct V_4 * F_117 ( struct V_207 * type ,
int V_89 , const char * V_208 ,
void * V_209 )
{
return F_118 ( type , V_89 , V_209 , F_114 ) ;
}
static void F_119 ( struct V_27 * V_17 )
{
F_120 ( V_17 ) ;
F_18 ( V_17 -> V_16 ) ;
}
static int T_1 F_121 ( void )
{
return F_122 ( & V_210 ) ;
}
static void T_9 F_123 ( void )
{
F_124 ( & V_210 ) ;
}
