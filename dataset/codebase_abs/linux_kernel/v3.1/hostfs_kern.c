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
F_33 ( & V_2 -> V_48 ) ;
F_18 ( F_1 ( V_2 ) ) ;
}
static void F_34 ( struct V_2 * V_2 )
{
F_35 ( & V_2 -> V_47 , F_31 ) ;
}
static int F_36 ( struct V_49 * V_50 , struct V_51 * V_52 )
{
const char * V_53 = V_52 -> V_54 -> V_16 ;
T_2 V_55 = strlen ( V_8 ) + 1 ;
if ( strlen ( V_53 ) > V_55 )
F_37 ( V_50 , L_4 , V_53 + V_55 ) ;
return 0 ;
}
int F_38 ( struct V_56 * V_56 , void * V_57 , T_3 V_58 )
{
void * V_59 ;
char * V_10 ;
unsigned long long V_60 , V_18 ;
int error , V_14 ;
V_10 = F_10 ( V_56 -> V_61 . V_4 ) ;
if ( V_10 == NULL )
return - V_23 ;
V_59 = F_39 ( V_10 , & error ) ;
F_8 ( V_10 ) ;
if ( V_59 == NULL )
return - error ;
V_60 = V_56 -> V_62 ;
while ( ( V_10 = F_40 ( V_59 , & V_60 , & V_18 , & V_14 ) ) != NULL ) {
error = (* V_58)( V_57 , V_10 , V_14 , V_56 -> V_62 ,
V_18 , V_63 ) ;
if ( error ) break;
V_56 -> V_62 = V_60 ;
}
F_41 ( V_59 ) ;
return 0 ;
}
int F_42 ( struct V_2 * V_18 , struct V_56 * V_56 )
{
static F_43 ( V_64 ) ;
char * V_10 ;
T_4 V_65 = 0 ;
int V_31 ;
int V_66 = 0 , V_67 = 0 , V_43 ;
V_65 = V_56 -> V_68 & ( V_69 | V_70 ) ;
if ( ( V_65 & F_1 ( V_18 ) -> V_65 ) == V_65 )
return 0 ;
V_65 |= F_1 ( V_18 ) -> V_65 ;
V_71:
if ( V_65 & V_69 )
V_66 = 1 ;
if ( V_65 & V_70 )
V_67 = 1 ;
if ( V_67 )
V_66 = 1 ;
V_10 = F_10 ( V_56 -> V_61 . V_4 ) ;
if ( V_10 == NULL )
return - V_23 ;
V_43 = F_44 ( V_10 , V_66 , V_67 , V_9 ) ;
F_8 ( V_10 ) ;
if ( V_43 < 0 )
return V_43 ;
F_45 ( & V_64 ) ;
if ( ( V_65 & F_1 ( V_18 ) -> V_65 ) == V_65 ) {
F_46 ( & V_64 ) ;
return 0 ;
}
if ( ( V_65 | F_1 ( V_18 ) -> V_65 ) != V_65 ) {
V_65 |= F_1 ( V_18 ) -> V_65 ;
F_46 ( & V_64 ) ;
F_30 ( & V_43 ) ;
goto V_71;
}
if ( F_1 ( V_18 ) -> V_43 == - 1 ) {
F_1 ( V_18 ) -> V_43 = V_43 ;
} else {
V_31 = F_47 ( V_43 , F_1 ( V_18 ) -> V_43 ) ;
F_30 ( & V_43 ) ;
if ( V_31 < 0 ) {
F_46 ( & V_64 ) ;
return V_31 ;
}
}
F_1 ( V_18 ) -> V_65 = V_65 ;
F_46 ( & V_64 ) ;
return 0 ;
}
int F_48 ( struct V_56 * V_56 , T_5 V_72 , T_5 V_22 , int V_73 )
{
struct V_2 * V_2 = V_56 -> V_74 -> V_75 ;
int V_76 ;
V_76 = F_49 ( V_2 -> V_77 , V_72 , V_22 ) ;
if ( V_76 )
return V_76 ;
F_45 ( & V_2 -> V_78 ) ;
V_76 = F_50 ( F_1 ( V_2 ) -> V_43 , V_73 ) ;
F_46 ( & V_2 -> V_78 ) ;
return V_76 ;
}
int F_51 ( struct V_79 * V_79 , struct V_80 * V_81 )
{
struct V_82 * V_83 = V_79 -> V_83 ;
struct V_2 * V_2 = V_83 -> V_75 ;
char * V_84 ;
unsigned long long V_85 ;
int V_86 = V_87 ;
int V_88 = V_2 -> V_89 >> V_90 ;
int V_31 ;
if ( V_79 -> V_91 >= V_88 )
V_86 = V_2 -> V_89 & ( V_87 - 1 ) ;
V_84 = F_52 ( V_79 ) ;
V_85 = ( ( unsigned long long ) V_79 -> V_91 ) << V_90 ;
V_31 = F_53 ( F_1 ( V_2 ) -> V_43 , & V_85 , V_84 , V_86 ) ;
if ( V_31 != V_86 ) {
F_54 ( V_79 ) ;
goto V_25;
}
if ( V_85 > V_2 -> V_89 )
V_2 -> V_89 = V_85 ;
if ( F_55 ( V_79 ) )
F_56 ( V_79 ) ;
V_31 = 0 ;
V_25:
F_57 ( V_79 ) ;
F_58 ( V_79 ) ;
return V_31 ;
}
int F_59 ( struct V_56 * V_56 , struct V_79 * V_79 )
{
char * V_84 ;
long long V_72 ;
int V_31 = 0 ;
V_72 = ( long long ) V_79 -> V_91 << V_90 ;
V_84 = F_52 ( V_79 ) ;
V_31 = F_60 ( F_61 ( V_56 ) -> V_43 , & V_72 , V_84 ,
V_87 ) ;
if ( V_31 < 0 )
goto V_25;
memset ( & V_84 [ V_31 ] , 0 , V_87 - V_31 ) ;
F_62 ( V_79 ) ;
F_63 ( V_79 ) ;
if ( F_55 ( V_79 ) ) F_56 ( V_79 ) ;
V_31 = 0 ;
V_25:
F_57 ( V_79 ) ;
F_58 ( V_79 ) ;
return V_31 ;
}
int F_64 ( struct V_56 * V_56 , struct V_82 * V_83 ,
T_5 V_92 , unsigned V_14 , unsigned V_93 ,
struct V_79 * * V_94 , void * * V_95 )
{
T_6 V_91 = V_92 >> V_90 ;
* V_94 = F_65 ( V_83 , V_91 , V_93 ) ;
if ( ! * V_94 )
return - V_23 ;
return 0 ;
}
int F_66 ( struct V_56 * V_56 , struct V_82 * V_83 ,
T_5 V_92 , unsigned V_14 , unsigned V_96 ,
struct V_79 * V_79 , void * V_95 )
{
struct V_2 * V_2 = V_83 -> V_75 ;
void * V_84 ;
unsigned V_97 = V_92 & ( V_87 - 1 ) ;
int V_31 ;
V_84 = F_52 ( V_79 ) ;
V_31 = F_53 ( F_61 ( V_56 ) -> V_43 , & V_92 , V_84 + V_97 , V_96 ) ;
F_57 ( V_79 ) ;
if ( ! F_67 ( V_79 ) && V_31 == V_87 )
F_63 ( V_79 ) ;
if ( V_31 > 0 && ( V_92 > V_2 -> V_89 ) )
V_2 -> V_89 = V_92 ;
F_58 ( V_79 ) ;
F_68 ( V_79 ) ;
return V_31 ;
}
static int F_69 ( struct V_2 * V_18 , char * V_10 )
{
T_7 V_98 ;
struct V_99 V_100 ;
int V_31 = F_70 ( V_10 , & V_100 , - 1 ) ;
if ( V_31 )
return V_31 ;
V_98 = F_71 ( V_100 . V_101 , V_100 . V_102 ) ;
switch ( V_100 . V_65 & V_103 ) {
case V_104 :
V_18 -> V_105 = & V_106 ;
break;
case V_107 :
V_18 -> V_105 = & V_108 ;
V_18 -> V_109 = & V_110 ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
F_72 ( V_18 , V_100 . V_65 & V_103 , V_98 ) ;
V_18 -> V_105 = & V_115 ;
break;
default:
V_18 -> V_105 = & V_115 ;
V_18 -> V_109 = & V_116 ;
V_18 -> V_77 -> V_117 = & V_118 ;
}
V_18 -> V_119 = V_100 . V_18 ;
V_18 -> V_120 = V_100 . V_65 ;
V_18 -> V_121 = V_100 . V_122 ;
V_18 -> V_123 = V_100 . V_124 ;
V_18 -> V_125 = V_100 . V_126 ;
V_18 -> V_127 = V_100 . V_128 ;
V_18 -> V_129 = V_100 . V_130 ;
V_18 -> V_131 = V_100 . ctime ;
V_18 -> V_89 = V_100 . V_132 ;
V_18 -> V_133 = V_100 . V_134 ;
return 0 ;
}
int F_73 ( struct V_2 * V_59 , struct V_4 * V_4 , int V_65 ,
struct V_135 * V_136 )
{
struct V_2 * V_2 ;
char * V_10 ;
int error , V_43 ;
V_2 = F_20 ( V_59 -> V_137 ) ;
if ( F_7 ( V_2 ) ) {
error = F_74 ( V_2 ) ;
goto V_25;
}
error = - V_23 ;
V_10 = F_10 ( V_4 ) ;
if ( V_10 == NULL )
goto V_138;
V_43 = F_75 ( V_10 ,
V_65 & V_139 , V_65 & V_140 , V_65 & V_141 ,
V_65 & V_142 , V_65 & V_143 , V_65 & V_144 ,
V_65 & V_145 , V_65 & V_146 , V_65 & V_147 ) ;
if ( V_43 < 0 )
error = V_43 ;
else
error = F_69 ( V_2 , V_10 ) ;
F_8 ( V_10 ) ;
if ( error )
goto V_138;
F_1 ( V_2 ) -> V_43 = V_43 ;
F_1 ( V_2 ) -> V_65 = V_69 | V_70 ;
F_76 ( V_4 , V_2 ) ;
return 0 ;
V_138:
F_77 ( V_2 ) ;
V_25:
return error ;
}
struct V_4 * F_78 ( struct V_2 * V_18 , struct V_4 * V_4 ,
struct V_135 * V_136 )
{
struct V_2 * V_2 ;
char * V_10 ;
int V_31 ;
V_2 = F_20 ( V_18 -> V_137 ) ;
if ( F_7 ( V_2 ) ) {
V_31 = F_74 ( V_2 ) ;
goto V_25;
}
V_31 = - V_23 ;
V_10 = F_10 ( V_4 ) ;
if ( V_10 == NULL )
goto V_138;
V_31 = F_69 ( V_2 , V_10 ) ;
F_8 ( V_10 ) ;
if ( V_31 == - V_148 ) {
F_77 ( V_2 ) ;
V_2 = NULL ;
}
else if ( V_31 )
goto V_138;
F_79 ( V_4 , V_2 ) ;
return NULL ;
V_138:
F_77 ( V_2 ) ;
V_25:
return F_19 ( V_31 ) ;
}
int F_80 ( struct V_4 * V_149 , struct V_2 * V_18 , struct V_4 * V_97 )
{
char * V_150 , * V_151 ;
int V_31 ;
if ( ( V_150 = F_10 ( V_97 ) ) == NULL )
return - V_23 ;
V_151 = F_10 ( V_149 ) ;
if ( V_151 == NULL ) {
F_8 ( V_150 ) ;
return - V_23 ;
}
V_31 = F_81 ( V_151 , V_150 ) ;
F_8 ( V_150 ) ;
F_8 ( V_151 ) ;
return V_31 ;
}
int F_82 ( struct V_2 * V_18 , struct V_4 * V_4 )
{
char * V_56 ;
int V_31 ;
if ( V_9 )
return - V_152 ;
if ( ( V_56 = F_10 ( V_4 ) ) == NULL )
return - V_23 ;
V_31 = F_83 ( V_56 ) ;
F_8 ( V_56 ) ;
return V_31 ;
}
int F_84 ( struct V_2 * V_18 , struct V_4 * V_4 , const char * V_149 )
{
char * V_56 ;
int V_31 ;
if ( ( V_56 = F_10 ( V_4 ) ) == NULL )
return - V_23 ;
V_31 = F_85 ( V_56 , V_149 ) ;
F_8 ( V_56 ) ;
return V_31 ;
}
int F_86 ( struct V_2 * V_18 , struct V_4 * V_4 , int V_65 )
{
char * V_56 ;
int V_31 ;
if ( ( V_56 = F_10 ( V_4 ) ) == NULL )
return - V_23 ;
V_31 = F_87 ( V_56 , V_65 ) ;
F_8 ( V_56 ) ;
return V_31 ;
}
int F_88 ( struct V_2 * V_18 , struct V_4 * V_4 )
{
char * V_56 ;
int V_31 ;
if ( ( V_56 = F_10 ( V_4 ) ) == NULL )
return - V_23 ;
V_31 = F_89 ( V_56 ) ;
F_8 ( V_56 ) ;
return V_31 ;
}
int F_90 ( struct V_2 * V_59 , struct V_4 * V_4 , int V_65 , T_7 V_153 )
{
struct V_2 * V_2 ;
char * V_10 ;
int V_31 ;
V_2 = F_20 ( V_59 -> V_137 ) ;
if ( F_7 ( V_2 ) ) {
V_31 = F_74 ( V_2 ) ;
goto V_25;
}
V_31 = - V_23 ;
V_10 = F_10 ( V_4 ) ;
if ( V_10 == NULL )
goto V_138;
F_72 ( V_2 , V_65 , V_153 ) ;
V_31 = F_91 ( V_10 , V_65 , F_92 ( V_153 ) , F_93 ( V_153 ) ) ;
if ( ! V_31 )
goto V_26;
V_31 = F_69 ( V_2 , V_10 ) ;
F_8 ( V_10 ) ;
if ( V_31 )
goto V_138;
if ( V_31 )
goto V_138;
F_76 ( V_4 , V_2 ) ;
return 0 ;
V_26:
F_8 ( V_10 ) ;
V_138:
F_77 ( V_2 ) ;
V_25:
return V_31 ;
}
int F_94 ( struct V_2 * V_154 , struct V_4 * V_97 ,
struct V_2 * V_155 , struct V_4 * V_149 )
{
char * V_150 , * V_151 ;
int V_31 ;
if ( ( V_150 = F_10 ( V_97 ) ) == NULL )
return - V_23 ;
if ( ( V_151 = F_10 ( V_149 ) ) == NULL ) {
F_8 ( V_150 ) ;
return - V_23 ;
}
V_31 = F_95 ( V_150 , V_151 ) ;
F_8 ( V_150 ) ;
F_8 ( V_151 ) ;
return V_31 ;
}
int F_96 ( struct V_2 * V_18 , int V_156 )
{
char * V_10 ;
int V_66 = 0 , V_67 = 0 , V_157 = 0 , V_31 ;
if ( V_156 & V_158 )
return - V_159 ;
if ( V_156 & V_160 ) V_66 = 1 ;
if ( V_156 & V_161 ) V_67 = 1 ;
if ( V_156 & V_162 ) V_157 = 1 ;
V_10 = F_12 ( V_18 ) ;
if ( V_10 == NULL )
return - V_23 ;
if ( F_97 ( V_18 -> V_120 ) || F_98 ( V_18 -> V_120 ) ||
F_99 ( V_18 -> V_120 ) || F_100 ( V_18 -> V_120 ) )
V_31 = 0 ;
else
V_31 = F_101 ( V_10 , V_66 , V_67 , V_157 ) ;
F_8 ( V_10 ) ;
if ( ! V_31 )
V_31 = F_102 ( V_18 , V_156 ) ;
return V_31 ;
}
int F_103 ( struct V_4 * V_4 , struct V_163 * V_164 )
{
struct V_2 * V_2 = V_4 -> V_165 ;
struct V_166 V_167 ;
char * V_10 ;
int V_31 ;
int V_43 = F_1 ( V_2 ) -> V_43 ;
V_31 = F_104 ( V_2 , V_164 ) ;
if ( V_31 )
return V_31 ;
if ( V_9 )
V_164 -> V_168 &= ~ V_169 ;
V_167 . V_168 = 0 ;
if ( V_164 -> V_168 & V_170 ) {
V_167 . V_168 |= V_171 ;
V_167 . V_172 = V_164 -> V_172 ;
}
if ( V_164 -> V_168 & V_173 ) {
V_167 . V_168 |= V_174 ;
V_167 . V_175 = V_164 -> V_175 ;
}
if ( V_164 -> V_168 & V_176 ) {
V_167 . V_168 |= V_177 ;
V_167 . V_178 = V_164 -> V_178 ;
}
if ( V_164 -> V_168 & V_169 ) {
V_167 . V_168 |= V_179 ;
V_167 . V_180 = V_164 -> V_180 ;
}
if ( V_164 -> V_168 & V_181 ) {
V_167 . V_168 |= V_182 ;
V_167 . V_183 = V_164 -> V_183 ;
}
if ( V_164 -> V_168 & V_184 ) {
V_167 . V_168 |= V_185 ;
V_167 . V_186 = V_164 -> V_186 ;
}
if ( V_164 -> V_168 & V_187 ) {
V_167 . V_168 |= V_188 ;
V_167 . V_189 = V_164 -> V_189 ;
}
if ( V_164 -> V_168 & V_190 ) {
V_167 . V_168 |= V_191 ;
}
if ( V_164 -> V_168 & V_192 ) {
V_167 . V_168 |= V_193 ;
}
V_10 = F_10 ( V_4 ) ;
if ( V_10 == NULL )
return - V_23 ;
V_31 = F_105 ( V_10 , & V_167 , V_43 ) ;
F_8 ( V_10 ) ;
if ( V_31 )
return V_31 ;
if ( ( V_164 -> V_168 & V_169 ) &&
V_164 -> V_180 != F_106 ( V_2 ) ) {
int error ;
error = F_107 ( V_2 , V_164 -> V_180 ) ;
if ( V_31 )
return V_31 ;
}
F_108 ( V_2 , V_164 ) ;
F_109 ( V_2 ) ;
return 0 ;
}
static void * F_110 ( struct V_4 * V_4 , struct V_135 * V_136 )
{
char * V_19 = F_11 () ;
if ( V_19 ) {
char * V_194 = F_10 ( V_4 ) ;
int V_31 = - V_23 ;
if ( V_194 ) {
V_31 = F_17 ( V_194 , V_19 , V_12 ) ;
if ( V_31 == V_12 )
V_31 = - V_195 ;
F_8 ( V_194 ) ;
}
if ( V_31 < 0 ) {
F_8 ( V_19 ) ;
V_19 = F_19 ( V_31 ) ;
}
} else {
V_19 = F_19 ( - V_23 ) ;
}
F_111 ( V_136 , V_19 ) ;
return NULL ;
}
static void F_112 ( struct V_4 * V_4 , struct V_135 * V_136 , void * V_196 )
{
char * V_17 = F_113 ( V_136 ) ;
if ( ! F_7 ( V_17 ) )
F_8 ( V_17 ) ;
}
static int F_114 ( struct V_27 * V_28 , void * V_197 , int V_198 )
{
struct V_2 * V_199 ;
char * V_200 , * V_201 = V_197 ;
int V_31 ;
V_28 -> V_202 = 1024 ;
V_28 -> V_203 = 10 ;
V_28 -> V_204 = V_41 ;
V_28 -> V_205 = & V_206 ;
V_28 -> V_207 = & V_208 ;
V_28 -> V_209 = V_210 ;
if ( V_201 == NULL )
V_201 = L_5 ;
V_31 = - V_23 ;
V_28 -> V_16 = V_200 =
F_16 ( strlen ( V_8 ) + strlen ( V_201 ) + 2 , V_24 ) ;
if ( V_200 == NULL )
goto V_25;
sprintf ( V_200 , L_6 , V_8 , V_201 ) ;
V_199 = F_21 ( V_28 ) ;
if ( ! V_199 )
goto V_25;
V_31 = F_69 ( V_199 , V_200 ) ;
if ( V_31 )
goto V_138;
if ( F_115 ( V_199 -> V_120 ) ) {
char * V_10 = F_15 ( V_200 ) ;
if ( F_7 ( V_10 ) )
V_31 = F_74 ( V_10 ) ;
else
V_31 = F_69 ( V_199 , V_10 ) ;
F_18 ( V_10 ) ;
if ( V_31 )
goto V_138;
}
V_31 = - V_23 ;
V_28 -> V_211 = F_116 ( V_199 ) ;
if ( V_28 -> V_211 == NULL )
goto V_138;
return 0 ;
V_138:
F_77 ( V_199 ) ;
V_25:
return V_31 ;
}
static struct V_4 * F_117 ( struct V_212 * type ,
int V_93 , const char * V_213 ,
void * V_214 )
{
return F_118 ( type , V_93 , V_214 , F_114 ) ;
}
static void F_119 ( struct V_27 * V_17 )
{
F_120 ( V_17 ) ;
F_18 ( V_17 -> V_16 ) ;
}
static int T_1 F_121 ( void )
{
return F_122 ( & V_215 ) ;
}
static void T_8 F_123 ( void )
{
F_124 ( & V_215 ) ;
}
