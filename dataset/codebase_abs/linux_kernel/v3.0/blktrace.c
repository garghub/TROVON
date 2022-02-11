static void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 ,
const void * V_5 , T_2 V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 = NULL ;
int V_13 = 0 ;
int V_14 = F_2 () ;
bool V_15 = V_16 ;
if ( V_15 ) {
V_12 = V_17 -> V_12 ;
V_13 = F_3 () ;
V_10 = F_4 ( V_12 , V_18 ,
sizeof( * V_8 ) + V_6 ,
0 , V_13 ) ;
if ( ! V_10 )
return;
V_8 = F_5 ( V_10 ) ;
goto V_19;
}
if ( ! V_2 -> V_20 )
return;
V_8 = F_6 ( V_2 -> V_20 , sizeof( * V_8 ) + V_6 ) ;
if ( V_8 ) {
V_8 -> V_21 = V_22 | V_23 ;
V_8 -> time = F_7 ( F_8 () ) ;
V_19:
V_8 -> V_24 = V_2 -> V_25 ;
V_8 -> V_4 = V_4 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_14 = V_14 ;
V_8 -> V_26 = V_6 ;
memcpy ( ( void * ) V_8 + sizeof( * V_8 ) , V_5 , V_6 ) ;
if ( V_15 )
F_9 ( V_12 , V_10 , 0 , V_13 ) ;
}
}
static void F_10 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
V_28 -> V_29 = V_30 ;
F_1 ( V_2 , V_28 -> V_3 , V_31 , V_28 -> V_32 , sizeof( V_28 -> V_32 ) ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_33 V_34 ;
unsigned long V_35 ;
T_3 V_36 [ 2 ] ;
F_12 ( & V_34 ) ;
V_36 [ 0 ] = V_34 . V_37 ;
V_36 [ 1 ] = V_34 . V_38 ;
F_13 ( V_35 ) ;
F_1 ( V_2 , 0 , V_39 , V_36 , sizeof( V_36 ) ) ;
F_14 ( V_35 ) ;
}
void F_15 ( struct V_1 * V_2 , const char * V_40 , ... )
{
int V_41 ;
T_4 args ;
unsigned long V_35 ;
char * V_42 ;
if ( F_16 ( V_2 -> V_43 != V_44 &&
! V_16 ) )
return;
if ( ! ( V_2 -> V_45 & V_46 ) )
return;
F_13 ( V_35 ) ;
V_42 = F_17 ( V_2 -> V_47 , F_2 () ) ;
va_start ( args , V_40 ) ;
V_41 = F_18 ( V_42 , V_48 , V_40 , args ) ;
va_end ( args ) ;
F_1 ( V_2 , 0 , V_49 , V_42 , V_41 ) ;
F_14 ( V_35 ) ;
}
static int F_19 ( struct V_1 * V_2 , T_3 V_50 , T_5 V_51 ,
T_1 V_3 )
{
if ( ( ( V_2 -> V_45 << V_52 ) & V_50 ) == 0 )
return 1 ;
if ( V_51 && ( V_51 < V_2 -> V_53 || V_51 > V_2 -> V_54 ) )
return 1 ;
if ( V_2 -> V_3 && V_3 != V_2 -> V_3 )
return 1 ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 , T_5 V_51 , int V_55 ,
int V_56 , T_3 V_50 , int error , int V_26 , void * V_57 )
{
struct V_27 * V_28 = V_58 ;
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 = NULL ;
struct V_7 * V_8 ;
unsigned long V_35 = 0 ;
unsigned long * V_59 ;
T_1 V_3 ;
int V_14 , V_13 = 0 ;
bool V_15 = V_16 ;
if ( F_16 ( V_2 -> V_43 != V_44 && ! V_15 ) )
return;
V_50 |= V_60 [ V_56 & V_61 ] ;
V_50 |= F_21 ( V_56 , V_62 ) ;
V_50 |= F_21 ( V_56 , V_63 ) ;
V_50 |= F_21 ( V_56 , V_64 ) ;
V_50 |= F_21 ( V_56 , V_65 ) ;
V_3 = V_28 -> V_3 ;
if ( F_19 ( V_2 , V_50 , V_51 , V_3 ) )
return;
V_14 = F_22 () ;
if ( V_15 ) {
F_23 ( V_58 ) ;
V_12 = V_17 -> V_12 ;
V_13 = F_3 () ;
V_10 = F_4 ( V_12 , V_18 ,
sizeof( * V_8 ) + V_26 ,
0 , V_13 ) ;
if ( ! V_10 )
return;
V_8 = F_5 ( V_10 ) ;
goto V_19;
}
F_13 ( V_35 ) ;
if ( F_16 ( V_28 -> V_29 != V_30 ) )
F_10 ( V_2 , V_28 ) ;
V_8 = F_6 ( V_2 -> V_20 , sizeof( * V_8 ) + V_26 ) ;
if ( V_8 ) {
V_59 = F_17 ( V_2 -> V_59 , V_14 ) ;
V_8 -> V_21 = V_22 | V_23 ;
V_8 -> V_59 = ++ ( * V_59 ) ;
V_8 -> time = F_7 ( F_8 () ) ;
V_19:
V_8 -> V_14 = V_14 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_51 = V_51 ;
V_8 -> V_55 = V_55 ;
V_8 -> V_4 = V_50 ;
V_8 -> V_24 = V_2 -> V_25 ;
V_8 -> error = error ;
V_8 -> V_26 = V_26 ;
if ( V_26 )
memcpy ( ( void * ) V_8 + sizeof( * V_8 ) , V_57 , V_26 ) ;
if ( V_15 ) {
F_9 ( V_12 , V_10 , 0 , V_13 ) ;
return;
}
}
F_14 ( V_35 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_66 ) ;
F_25 ( V_2 -> V_67 ) ;
F_26 ( V_2 -> V_20 ) ;
F_25 ( V_2 -> V_68 ) ;
F_27 ( V_2 -> V_59 ) ;
F_27 ( V_2 -> V_47 ) ;
F_28 ( V_2 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_24 ( V_2 ) ;
if ( F_30 ( & V_69 ) )
F_31 () ;
}
int F_32 ( struct V_70 * V_71 )
{
struct V_1 * V_2 ;
V_2 = F_33 ( & V_71 -> V_1 , NULL ) ;
if ( ! V_2 )
return - V_72 ;
if ( V_2 -> V_43 != V_44 )
F_29 ( V_2 ) ;
return 0 ;
}
static int F_34 ( struct V_73 * V_73 , struct V_74 * V_75 )
{
V_75 -> V_76 = V_73 -> V_77 ;
return 0 ;
}
static T_6 F_35 ( struct V_74 * V_75 , char T_7 * V_12 ,
T_2 V_78 , T_8 * V_79 )
{
struct V_1 * V_2 = V_75 -> V_76 ;
char V_42 [ 16 ] ;
snprintf ( V_42 , sizeof( V_42 ) , L_1 , F_36 ( & V_2 -> V_80 ) ) ;
return F_37 ( V_12 , V_78 , V_79 , V_42 , strlen ( V_42 ) ) ;
}
static int F_38 ( struct V_73 * V_73 , struct V_74 * V_75 )
{
V_75 -> V_76 = V_73 -> V_77 ;
return 0 ;
}
static T_6 F_39 ( struct V_74 * V_75 , const char T_7 * V_12 ,
T_2 V_78 , T_8 * V_79 )
{
char * V_81 ;
struct V_1 * V_2 ;
if ( V_78 >= V_48 )
return - V_72 ;
V_81 = F_40 ( V_78 + 1 , V_82 ) ;
if ( V_81 == NULL )
return - V_83 ;
if ( F_41 ( V_81 , V_12 , V_78 ) ) {
F_28 ( V_81 ) ;
return - V_84 ;
}
V_81 [ V_78 ] = '\0' ;
V_2 = V_75 -> V_76 ;
F_15 ( V_2 , L_2 , V_81 ) ;
F_28 ( V_81 ) ;
return V_78 ;
}
static int F_42 ( struct V_85 * V_42 , void * V_86 ,
void * V_87 , T_2 V_88 )
{
struct V_1 * V_2 ;
if ( ! F_43 ( V_42 ) )
return 1 ;
V_2 = V_42 -> V_89 -> V_76 ;
F_44 ( & V_2 -> V_80 ) ;
return 0 ;
}
static int F_45 ( struct V_90 * V_90 )
{
F_25 ( V_90 ) ;
return 0 ;
}
static struct V_90 * F_46 ( const char * V_91 ,
struct V_90 * V_92 ,
int V_93 ,
struct V_85 * V_42 ,
int * V_94 )
{
return F_47 ( V_91 , V_93 , V_92 , V_42 ,
& V_95 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_96 * V_97 )
{
struct V_98 * V_99 = NULL ;
if ( V_97 )
V_99 = V_97 -> V_100 ;
if ( V_99 ) {
V_2 -> V_53 = V_99 -> V_101 ;
V_2 -> V_54 = V_99 -> V_101 + V_99 -> V_102 ;
} else {
V_2 -> V_53 = 0 ;
V_2 -> V_54 = - 1ULL ;
}
}
int F_49 ( struct V_70 * V_71 , char * V_103 , T_9 V_25 ,
struct V_96 * V_97 ,
struct V_104 * V_105 )
{
struct V_1 * V_106 , * V_2 = NULL ;
struct V_90 * V_68 = NULL ;
int V_107 , V_108 ;
if ( ! V_105 -> V_109 || ! V_105 -> V_110 )
return - V_72 ;
strncpy ( V_105 -> V_103 , V_103 , V_111 ) ;
V_105 -> V_103 [ V_111 - 1 ] = '\0' ;
for ( V_108 = 0 ; V_108 < strlen ( V_105 -> V_103 ) ; V_108 ++ )
if ( V_105 -> V_103 [ V_108 ] == '/' )
V_105 -> V_103 [ V_108 ] = '_' ;
V_2 = F_50 ( sizeof( * V_2 ) , V_82 ) ;
if ( ! V_2 )
return - V_83 ;
V_107 = - V_83 ;
V_2 -> V_59 = F_51 (unsigned long) ;
if ( ! V_2 -> V_59 )
goto V_112;
V_2 -> V_47 = F_52 ( V_48 , F_53 ( char ) ) ;
if ( ! V_2 -> V_47 )
goto V_112;
V_107 = - V_113 ;
F_54 ( & V_114 ) ;
if ( ! V_115 ) {
V_115 = F_55 ( L_3 , NULL ) ;
if ( ! V_115 ) {
F_56 ( & V_114 ) ;
goto V_112;
}
}
F_56 ( & V_114 ) ;
V_68 = F_55 ( V_105 -> V_103 , V_115 ) ;
if ( ! V_68 )
goto V_112;
V_2 -> V_68 = V_68 ;
V_2 -> V_25 = V_25 ;
F_57 ( & V_2 -> V_80 , 0 ) ;
V_107 = - V_116 ;
V_2 -> V_67 = F_47 ( L_4 , 0444 , V_68 , V_2 ,
& V_117 ) ;
if ( ! V_2 -> V_67 )
goto V_112;
V_2 -> V_66 = F_47 ( L_5 , 0222 , V_68 , V_2 , & V_118 ) ;
if ( ! V_2 -> V_66 )
goto V_112;
V_2 -> V_20 = F_58 ( L_6 , V_68 , V_105 -> V_109 ,
V_105 -> V_110 , & V_119 , V_2 ) ;
if ( ! V_2 -> V_20 )
goto V_112;
V_2 -> V_45 = V_105 -> V_45 ;
if ( ! V_2 -> V_45 )
V_2 -> V_45 = ( V_120 ) - 1 ;
F_48 ( V_2 , V_97 ) ;
if ( V_105 -> V_53 )
V_2 -> V_53 = V_105 -> V_53 ;
if ( V_105 -> V_54 )
V_2 -> V_54 = V_105 -> V_54 ;
V_2 -> V_3 = V_105 -> V_3 ;
V_2 -> V_43 = V_121 ;
V_107 = - V_122 ;
V_106 = F_33 ( & V_71 -> V_1 , V_2 ) ;
if ( V_106 ) {
( void ) F_33 ( & V_71 -> V_1 , V_106 ) ;
goto V_112;
}
if ( F_59 ( & V_69 ) == 1 )
F_60 () ;
return 0 ;
V_112:
F_24 ( V_2 ) ;
return V_107 ;
}
int F_61 ( struct V_70 * V_71 , char * V_103 , T_9 V_25 ,
struct V_96 * V_97 ,
char T_7 * V_123 )
{
struct V_104 V_105 ;
int V_107 ;
V_107 = F_41 ( & V_105 , V_123 , sizeof( V_105 ) ) ;
if ( V_107 )
return - V_84 ;
V_107 = F_49 ( V_71 , V_103 , V_25 , V_97 , & V_105 ) ;
if ( V_107 )
return V_107 ;
if ( F_62 ( V_123 , & V_105 , sizeof( V_105 ) ) ) {
F_32 ( V_71 ) ;
return - V_84 ;
}
return 0 ;
}
static int F_63 ( struct V_70 * V_71 , char * V_103 ,
T_9 V_25 , struct V_96 * V_97 ,
char T_7 * V_123 )
{
struct V_104 V_105 ;
struct V_124 V_125 ;
int V_107 ;
if ( F_41 ( & V_125 , V_123 , sizeof( V_125 ) ) )
return - V_84 ;
V_105 = (struct V_104 ) {
. V_45 = V_125 . V_45 ,
. V_109 = V_125 . V_109 ,
. V_110 = V_125 . V_110 ,
. V_53 = V_125 . V_53 ,
. V_54 = V_125 . V_54 ,
. V_3 = V_125 . V_3 ,
} ;
memcpy ( & V_105 . V_103 , & V_125 . V_103 , 32 ) ;
V_107 = F_49 ( V_71 , V_103 , V_25 , V_97 , & V_105 ) ;
if ( V_107 )
return V_107 ;
if ( F_62 ( V_123 , & V_105 . V_103 , 32 ) ) {
F_32 ( V_71 ) ;
return - V_84 ;
}
return 0 ;
}
int F_64 ( struct V_70 * V_71 , int V_126 )
{
int V_107 ;
struct V_1 * V_2 = V_71 -> V_1 ;
if ( V_2 == NULL )
return - V_72 ;
V_107 = - V_72 ;
if ( V_126 ) {
if ( V_2 -> V_43 == V_121 ||
V_2 -> V_43 == V_127 ) {
V_30 ++ ;
F_65 () ;
V_2 -> V_43 = V_44 ;
F_11 ( V_2 ) ;
V_107 = 0 ;
}
} else {
if ( V_2 -> V_43 == V_44 ) {
V_2 -> V_43 = V_127 ;
F_66 ( V_2 -> V_20 ) ;
V_107 = 0 ;
}
}
return V_107 ;
}
int F_67 ( struct V_96 * V_97 , unsigned V_128 , char T_7 * V_123 )
{
struct V_70 * V_71 ;
int V_107 , V_126 = 0 ;
char V_129 [ V_130 ] ;
V_71 = F_68 ( V_97 ) ;
if ( ! V_71 )
return - V_131 ;
F_54 ( & V_97 -> V_132 ) ;
switch ( V_128 ) {
case V_133 :
F_69 ( V_97 , V_129 ) ;
V_107 = F_61 ( V_71 , V_129 , V_97 -> V_134 , V_97 , V_123 ) ;
break;
#if F_70 ( V_135 ) && F_70 ( V_136 )
case V_137 :
F_69 ( V_97 , V_129 ) ;
V_107 = F_63 ( V_71 , V_129 , V_97 -> V_134 , V_97 , V_123 ) ;
break;
#endif
case V_138 :
V_126 = 1 ;
case V_139 :
V_107 = F_64 ( V_71 , V_126 ) ;
break;
case V_140 :
V_107 = F_32 ( V_71 ) ;
break;
default:
V_107 = - V_141 ;
break;
}
F_56 ( & V_97 -> V_132 ) ;
return V_107 ;
}
void F_71 ( struct V_70 * V_71 )
{
if ( V_71 -> V_1 ) {
F_64 ( V_71 , 0 ) ;
F_32 ( V_71 ) ;
}
}
static void F_72 ( struct V_70 * V_71 , struct V_142 * V_143 ,
T_3 V_50 )
{
struct V_1 * V_2 = V_71 -> V_1 ;
if ( F_73 ( ! V_2 ) )
return;
if ( V_143 -> V_144 == V_145 ) {
V_50 |= F_74 ( V_146 ) ;
F_20 ( V_2 , 0 , F_75 ( V_143 ) , V_143 -> V_147 ,
V_50 , V_143 -> V_148 , V_143 -> V_149 , V_143 -> V_128 ) ;
} else {
V_50 |= F_74 ( V_150 ) ;
F_20 ( V_2 , F_76 ( V_143 ) , F_75 ( V_143 ) ,
V_143 -> V_147 , V_50 , V_143 -> V_148 , 0 , NULL ) ;
}
}
static void F_77 ( void * V_151 ,
struct V_70 * V_71 , struct V_142 * V_143 )
{
F_72 ( V_71 , V_143 , V_152 ) ;
}
static void F_78 ( void * V_151 ,
struct V_70 * V_71 , struct V_142 * V_143 )
{
F_72 ( V_71 , V_143 , V_153 ) ;
}
static void F_79 ( void * V_151 ,
struct V_70 * V_71 , struct V_142 * V_143 )
{
F_72 ( V_71 , V_143 , V_154 ) ;
}
static void F_80 ( void * V_151 ,
struct V_70 * V_71 ,
struct V_142 * V_143 )
{
F_72 ( V_71 , V_143 , V_155 ) ;
}
static void F_81 ( void * V_151 ,
struct V_70 * V_71 ,
struct V_142 * V_143 )
{
F_72 ( V_71 , V_143 , V_156 ) ;
}
static void F_82 ( struct V_70 * V_71 , struct V_157 * V_157 ,
T_3 V_50 , int error )
{
struct V_1 * V_2 = V_71 -> V_1 ;
if ( F_73 ( ! V_2 ) )
return;
if ( ! error && ! F_83 ( V_157 , V_158 ) )
error = V_116 ;
F_20 ( V_2 , V_157 -> V_159 , V_157 -> V_160 , V_157 -> V_161 , V_50 ,
error , 0 , NULL ) ;
}
static void F_84 ( void * V_151 ,
struct V_70 * V_71 , struct V_157 * V_157 )
{
F_82 ( V_71 , V_157 , V_162 , 0 ) ;
}
static void F_85 ( void * V_151 ,
struct V_70 * V_71 , struct V_157 * V_157 ,
int error )
{
F_82 ( V_71 , V_157 , V_156 , error ) ;
}
static void F_86 ( void * V_151 ,
struct V_70 * V_71 ,
struct V_157 * V_157 )
{
F_82 ( V_71 , V_157 , V_163 , 0 ) ;
}
static void F_87 ( void * V_151 ,
struct V_70 * V_71 ,
struct V_157 * V_157 )
{
F_82 ( V_71 , V_157 , V_164 , 0 ) ;
}
static void F_88 ( void * V_151 ,
struct V_70 * V_71 , struct V_157 * V_157 )
{
F_82 ( V_71 , V_157 , V_165 , 0 ) ;
}
static void F_89 ( void * V_151 ,
struct V_70 * V_71 ,
struct V_157 * V_157 , int V_56 )
{
if ( V_157 )
F_82 ( V_71 , V_157 , V_166 , 0 ) ;
else {
struct V_1 * V_2 = V_71 -> V_1 ;
if ( V_2 )
F_20 ( V_2 , 0 , 0 , V_56 , V_166 , 0 , 0 , NULL ) ;
}
}
static void F_90 ( void * V_151 ,
struct V_70 * V_71 ,
struct V_157 * V_157 , int V_56 )
{
if ( V_157 )
F_82 ( V_71 , V_157 , V_167 , 0 ) ;
else {
struct V_1 * V_2 = V_71 -> V_1 ;
if ( V_2 )
F_20 ( V_2 , 0 , 0 , V_56 , V_167 ,
0 , 0 , NULL ) ;
}
}
static void F_91 ( void * V_151 , struct V_70 * V_71 )
{
struct V_1 * V_2 = V_71 -> V_1 ;
if ( V_2 )
F_20 ( V_2 , 0 , 0 , 0 , V_168 , 0 , 0 , NULL ) ;
}
static void F_92 ( void * V_151 , struct V_70 * V_71 ,
unsigned int V_169 , bool V_170 )
{
struct V_1 * V_2 = V_71 -> V_1 ;
if ( V_2 ) {
T_10 V_171 = F_93 ( V_169 ) ;
T_3 V_50 ;
if ( V_170 )
V_50 = V_172 ;
else
V_50 = V_173 ;
F_20 ( V_2 , 0 , 0 , 0 , V_50 , 0 , sizeof( V_171 ) , & V_171 ) ;
}
}
static void F_94 ( void * V_151 ,
struct V_70 * V_71 , struct V_157 * V_157 ,
unsigned int V_174 )
{
struct V_1 * V_2 = V_71 -> V_1 ;
if ( V_2 ) {
T_10 V_171 = F_93 ( V_174 ) ;
F_20 ( V_2 , V_157 -> V_159 , V_157 -> V_160 , V_157 -> V_161 ,
V_175 , ! F_83 ( V_157 , V_158 ) ,
sizeof( V_171 ) , & V_171 ) ;
}
}
static void F_95 ( void * V_151 ,
struct V_70 * V_71 , struct V_157 * V_157 ,
T_9 V_25 , T_5 V_176 )
{
struct V_1 * V_2 = V_71 -> V_1 ;
struct V_177 V_178 ;
if ( F_73 ( ! V_2 ) )
return;
V_178 . V_179 = F_96 ( V_25 ) ;
V_178 . V_180 = F_96 ( V_157 -> V_181 -> V_134 ) ;
V_178 . V_182 = F_93 ( V_176 ) ;
F_20 ( V_2 , V_157 -> V_159 , V_157 -> V_160 , V_157 -> V_161 ,
V_183 , ! F_83 ( V_157 , V_158 ) ,
sizeof( V_178 ) , & V_178 ) ;
}
static void F_97 ( void * V_151 ,
struct V_70 * V_71 ,
struct V_142 * V_143 , T_9 V_25 ,
T_5 V_176 )
{
struct V_1 * V_2 = V_71 -> V_1 ;
struct V_177 V_178 ;
if ( F_73 ( ! V_2 ) )
return;
V_178 . V_179 = F_96 ( V_25 ) ;
V_178 . V_180 = F_96 ( F_98 ( V_143 -> V_184 ) ) ;
V_178 . V_182 = F_93 ( V_176 ) ;
F_20 ( V_2 , F_76 ( V_143 ) , F_75 ( V_143 ) ,
F_99 ( V_143 ) , V_183 , ! ! V_143 -> V_148 ,
sizeof( V_178 ) , & V_178 ) ;
}
void F_100 ( struct V_70 * V_71 ,
struct V_142 * V_143 ,
void * V_5 , T_2 V_6 )
{
struct V_1 * V_2 = V_71 -> V_1 ;
if ( F_73 ( ! V_2 ) )
return;
if ( V_143 -> V_144 == V_145 )
F_20 ( V_2 , 0 , F_75 ( V_143 ) , 0 ,
V_185 , V_143 -> V_148 , V_6 , V_5 ) ;
else
F_20 ( V_2 , F_76 ( V_143 ) , F_75 ( V_143 ) , 0 ,
V_185 , V_143 -> V_148 , V_6 , V_5 ) ;
}
static void F_60 ( void )
{
int V_107 ;
V_107 = F_101 ( F_77 , NULL ) ;
F_102 ( V_107 ) ;
V_107 = F_103 ( F_78 , NULL ) ;
F_102 ( V_107 ) ;
V_107 = F_104 ( F_79 , NULL ) ;
F_102 ( V_107 ) ;
V_107 = F_105 ( F_80 , NULL ) ;
F_102 ( V_107 ) ;
V_107 = F_106 ( F_81 , NULL ) ;
F_102 ( V_107 ) ;
V_107 = F_107 ( F_84 , NULL ) ;
F_102 ( V_107 ) ;
V_107 = F_108 ( F_85 , NULL ) ;
F_102 ( V_107 ) ;
V_107 = F_109 ( F_86 , NULL ) ;
F_102 ( V_107 ) ;
V_107 = F_110 ( F_87 , NULL ) ;
F_102 ( V_107 ) ;
V_107 = F_111 ( F_88 , NULL ) ;
F_102 ( V_107 ) ;
V_107 = F_112 ( F_89 , NULL ) ;
F_102 ( V_107 ) ;
V_107 = F_113 ( F_90 , NULL ) ;
F_102 ( V_107 ) ;
V_107 = F_114 ( F_91 , NULL ) ;
F_102 ( V_107 ) ;
V_107 = F_115 ( F_92 , NULL ) ;
F_102 ( V_107 ) ;
V_107 = F_116 ( F_94 , NULL ) ;
F_102 ( V_107 ) ;
V_107 = F_117 ( F_95 , NULL ) ;
F_102 ( V_107 ) ;
V_107 = F_118 ( F_97 , NULL ) ;
F_102 ( V_107 ) ;
}
static void F_31 ( void )
{
F_119 ( F_97 , NULL ) ;
F_120 ( F_95 , NULL ) ;
F_121 ( F_94 , NULL ) ;
F_122 ( F_92 , NULL ) ;
F_123 ( F_91 , NULL ) ;
F_124 ( F_90 , NULL ) ;
F_125 ( F_89 , NULL ) ;
F_126 ( F_88 , NULL ) ;
F_127 ( F_87 , NULL ) ;
F_128 ( F_86 , NULL ) ;
F_129 ( F_85 , NULL ) ;
F_130 ( F_84 , NULL ) ;
F_131 ( F_81 , NULL ) ;
F_132 ( F_80 , NULL ) ;
F_133 ( F_79 , NULL ) ;
F_134 ( F_78 , NULL ) ;
F_135 ( F_77 , NULL ) ;
F_136 () ;
}
static void F_137 ( char * V_186 , const struct V_7 * V_8 )
{
int V_108 = 0 ;
int V_187 = V_8 -> V_4 >> V_52 ;
if ( V_8 -> V_4 == V_49 ) {
V_186 [ V_108 ++ ] = 'N' ;
goto V_188;
}
if ( V_187 & V_189 )
V_186 [ V_108 ++ ] = 'D' ;
else if ( V_187 & V_190 )
V_186 [ V_108 ++ ] = 'W' ;
else if ( V_8 -> V_55 )
V_186 [ V_108 ++ ] = 'R' ;
else
V_186 [ V_108 ++ ] = 'N' ;
if ( V_187 & V_191 )
V_186 [ V_108 ++ ] = 'A' ;
if ( V_187 & V_192 )
V_186 [ V_108 ++ ] = 'B' ;
if ( V_187 & V_193 )
V_186 [ V_108 ++ ] = 'S' ;
if ( V_187 & V_194 )
V_186 [ V_108 ++ ] = 'M' ;
V_188:
V_186 [ V_108 ] = '\0' ;
}
static inline
const struct V_7 * F_138 ( const struct V_195 * V_196 )
{
return ( const struct V_7 * ) V_196 ;
}
static inline const void * F_139 ( const struct V_195 * V_196 )
{
return F_138 ( V_196 ) + 1 ;
}
static inline T_3 F_140 ( const struct V_195 * V_196 )
{
return F_138 ( V_196 ) -> V_4 ;
}
static inline T_3 F_141 ( const struct V_195 * V_196 )
{
return F_138 ( V_196 ) -> V_55 ;
}
static inline T_3 F_142 ( const struct V_195 * V_196 )
{
return F_138 ( V_196 ) -> V_55 >> 9 ;
}
static inline unsigned long long F_143 ( const struct V_195 * V_196 )
{
return F_138 ( V_196 ) -> V_51 ;
}
static inline T_11 F_144 ( const struct V_195 * V_196 )
{
return F_138 ( V_196 ) -> error ;
}
static T_12 F_145 ( const struct V_195 * V_196 )
{
const T_12 * V_197 = F_139 ( V_196 ) ;
return F_146 ( * V_197 ) ;
}
static void F_147 ( const struct V_195 * V_196 ,
struct V_177 * V_178 )
{
const struct V_177 * V_198 = F_139 ( V_196 ) ;
T_12 V_182 = V_198 -> V_182 ;
V_178 -> V_179 = F_148 ( V_198 -> V_179 ) ;
V_178 -> V_180 = F_148 ( V_198 -> V_180 ) ;
V_178 -> V_182 = F_146 ( V_182 ) ;
}
static int F_149 ( struct V_199 * V_200 , const char * V_201 )
{
char V_186 [ 6 ] ;
unsigned long long V_202 = V_200 -> V_202 ;
unsigned long V_203 = F_150 ( V_202 , V_204 ) ;
unsigned V_205 = ( unsigned long ) V_202 ;
const struct V_7 * V_8 = F_138 ( V_200 -> V_196 ) ;
F_137 ( V_186 , V_8 ) ;
return F_151 ( & V_200 -> V_206 ,
L_7 ,
F_152 ( V_8 -> V_24 ) , F_153 ( V_8 -> V_24 ) , V_200 -> V_14 ,
V_205 , V_203 , V_200 -> V_196 -> V_3 , V_201 , V_186 ) ;
}
static int F_154 ( struct V_199 * V_200 , const char * V_201 )
{
char V_186 [ 6 ] ;
const struct V_7 * V_8 = F_138 ( V_200 -> V_196 ) ;
F_137 ( V_186 , V_8 ) ;
return F_151 ( & V_200 -> V_206 , L_8 ,
F_152 ( V_8 -> V_24 ) , F_153 ( V_8 -> V_24 ) , V_201 , V_186 ) ;
}
static int F_155 ( struct V_207 * V_208 , const struct V_195 * V_196 )
{
const unsigned char * V_209 ;
int V_26 ;
int V_108 , V_210 , V_107 ;
V_209 = F_139 ( V_196 ) ;
V_26 = F_138 ( V_196 ) -> V_26 ;
if ( ! V_26 )
return 1 ;
for ( V_210 = V_26 - 1 ; V_210 >= 0 ; V_210 -- )
if ( V_209 [ V_210 ] )
break;
V_210 ++ ;
if ( ! F_156 ( V_208 , '(' ) )
return 0 ;
for ( V_108 = 0 ; V_108 < V_26 ; V_108 ++ ) {
V_107 = F_151 ( V_208 , L_9 ,
V_108 == 0 ? L_10 : L_11 , V_209 [ V_108 ] ) ;
if ( ! V_107 )
return V_107 ;
if ( V_108 == V_210 && V_210 != V_26 - 1 )
return F_157 ( V_208 , L_12 ) ;
}
return F_157 ( V_208 , L_13 ) ;
}
static int F_158 ( struct V_207 * V_208 , const struct V_195 * V_196 )
{
char V_128 [ V_211 ] ;
F_159 ( V_196 -> V_3 , V_128 ) ;
if ( F_140 ( V_196 ) & F_74 ( V_146 ) ) {
int V_107 ;
V_107 = F_151 ( V_208 , L_14 , F_141 ( V_196 ) ) ;
if ( ! V_107 )
return 0 ;
V_107 = F_155 ( V_208 , V_196 ) ;
if ( ! V_107 )
return 0 ;
return F_151 ( V_208 , L_15 , V_128 ) ;
} else {
if ( F_142 ( V_196 ) )
return F_151 ( V_208 , L_16 ,
F_143 ( V_196 ) , F_142 ( V_196 ) , V_128 ) ;
return F_151 ( V_208 , L_15 , V_128 ) ;
}
}
static int F_160 ( struct V_207 * V_208 ,
const struct V_195 * V_196 )
{
if ( F_140 ( V_196 ) & F_74 ( V_146 ) ) {
int V_107 ;
V_107 = F_155 ( V_208 , V_196 ) ;
if ( V_107 )
return F_151 ( V_208 , L_17 , F_144 ( V_196 ) ) ;
return 0 ;
} else {
if ( F_142 ( V_196 ) )
return F_151 ( V_208 , L_18 ,
F_143 ( V_196 ) ,
F_142 ( V_196 ) , F_144 ( V_196 ) ) ;
return F_151 ( V_208 , L_19 ,
F_143 ( V_196 ) , F_144 ( V_196 ) ) ;
}
}
static int F_161 ( struct V_207 * V_208 , const struct V_195 * V_196 )
{
struct V_177 V_178 = { . V_179 = 0 , } ;
F_147 ( V_196 , & V_178 ) ;
return F_151 ( V_208 , L_20 ,
F_143 ( V_196 ) , F_142 ( V_196 ) ,
F_152 ( V_178 . V_179 ) , F_153 ( V_178 . V_179 ) ,
( unsigned long long ) V_178 . V_182 ) ;
}
static int F_162 ( struct V_207 * V_208 , const struct V_195 * V_196 )
{
char V_128 [ V_211 ] ;
F_159 ( V_196 -> V_3 , V_128 ) ;
return F_151 ( V_208 , L_15 , V_128 ) ;
}
static int F_163 ( struct V_207 * V_208 , const struct V_195 * V_196 )
{
char V_128 [ V_211 ] ;
F_159 ( V_196 -> V_3 , V_128 ) ;
return F_151 ( V_208 , L_21 , V_128 , F_145 ( V_196 ) ) ;
}
static int F_164 ( struct V_207 * V_208 , const struct V_195 * V_196 )
{
char V_128 [ V_211 ] ;
F_159 ( V_196 -> V_3 , V_128 ) ;
return F_151 ( V_208 , L_22 , F_143 ( V_196 ) ,
F_145 ( V_196 ) , V_128 ) ;
}
static int F_165 ( struct V_207 * V_208 , const struct V_195 * V_196 )
{
int V_107 ;
const struct V_7 * V_8 = F_138 ( V_196 ) ;
V_107 = F_166 ( V_208 , V_8 + 1 , V_8 -> V_26 ) ;
if ( V_107 )
return F_156 ( V_208 , '\n' ) ;
return V_107 ;
}
static void F_167 ( struct V_212 * V_213 )
{
if ( ! ( V_214 . V_197 & V_215 ) )
return;
F_168 ( V_213 , L_23
L_24 ) ;
}
static void F_169 ( struct V_216 * V_217 )
{
V_16 = true ;
}
static int F_170 ( struct V_216 * V_217 )
{
V_17 = V_217 ;
F_169 ( V_217 ) ;
return 0 ;
}
static void F_171 ( struct V_216 * V_217 )
{
V_16 = false ;
}
static void F_172 ( struct V_216 * V_217 )
{
F_171 ( V_217 ) ;
}
static enum V_218 F_173 ( struct V_199 * V_200 ,
bool V_219 )
{
struct V_207 * V_208 = & V_200 -> V_206 ;
const struct V_7 * V_8 ;
V_120 V_50 ;
int V_107 ;
bool V_220 ;
T_13 * V_221 ;
V_8 = F_138 ( V_200 -> V_196 ) ;
V_50 = V_8 -> V_4 & ( ( 1 << V_52 ) - 1 ) ;
V_220 = ! ! ( V_222 & V_223 ) ;
V_221 = V_219 ? & F_149 : & F_154 ;
if ( V_8 -> V_4 == V_49 ) {
V_107 = V_221 ( V_200 , V_220 ? L_25 : L_26 ) ;
if ( V_107 )
V_107 = F_165 ( V_208 , V_200 -> V_196 ) ;
goto V_188;
}
if ( F_16 ( V_50 == 0 || V_50 >= F_174 ( V_224 ) ) )
V_107 = F_151 ( V_208 , L_27 , V_50 ) ;
else {
V_107 = V_221 ( V_200 , V_224 [ V_50 ] . V_201 [ V_220 ] ) ;
if ( V_107 )
V_107 = V_224 [ V_50 ] . F_175 ( V_208 , V_200 -> V_196 ) ;
}
V_188:
return V_107 ? V_225 : V_226 ;
}
static enum V_218 F_176 ( struct V_199 * V_200 ,
int V_35 , struct V_227 * V_10 )
{
return F_173 ( V_200 , false ) ;
}
static int F_177 ( struct V_199 * V_200 )
{
struct V_207 * V_208 = & V_200 -> V_206 ;
struct V_7 * V_8 = (struct V_7 * ) V_200 -> V_196 ;
const int V_228 = F_178 ( struct V_7 , V_51 ) ;
struct V_7 V_229 = {
. V_21 = V_22 | V_23 ,
. time = V_200 -> V_202 ,
} ;
if ( ! F_166 ( V_208 , & V_229 , V_228 ) )
return 0 ;
return F_166 ( V_208 , & V_8 -> V_51 ,
sizeof( V_229 ) - V_228 + V_8 -> V_26 ) ;
}
static enum V_218
F_179 ( struct V_199 * V_200 , int V_35 ,
struct V_227 * V_10 )
{
return F_177 ( V_200 ) ?
V_225 : V_226 ;
}
static enum V_218 F_180 ( struct V_199 * V_200 )
{
if ( ! ( V_214 . V_197 & V_215 ) )
return V_230 ;
return F_173 ( V_200 , true ) ;
}
static int F_181 ( T_3 V_231 , T_3 V_232 , int V_233 )
{
if ( V_232 == V_215 ) {
if ( V_233 )
V_222 &= ~ V_234 ;
else
V_222 |= V_234 ;
}
return 0 ;
}
static int T_14 F_182 ( void )
{
if ( ! F_183 ( & V_235 ) ) {
F_184 ( L_28 ) ;
return 1 ;
}
if ( F_185 ( & V_15 ) != 0 ) {
F_184 ( L_29 ) ;
F_186 ( & V_235 ) ;
return 1 ;
}
return 0 ;
}
static int F_187 ( struct V_70 * V_71 )
{
struct V_1 * V_2 ;
V_2 = F_33 ( & V_71 -> V_1 , NULL ) ;
if ( V_2 == NULL )
return - V_72 ;
if ( F_30 ( & V_69 ) )
F_31 () ;
F_24 ( V_2 ) ;
return 0 ;
}
static int F_188 ( struct V_70 * V_71 ,
struct V_96 * V_97 )
{
struct V_1 * V_106 , * V_2 = NULL ;
int V_107 = - V_83 ;
V_2 = F_50 ( sizeof( * V_2 ) , V_82 ) ;
if ( ! V_2 )
return - V_83 ;
V_2 -> V_47 = F_52 ( V_48 , F_53 ( char ) ) ;
if ( ! V_2 -> V_47 )
goto V_236;
V_2 -> V_25 = V_97 -> V_134 ;
V_2 -> V_45 = ( V_120 ) - 1 ;
F_48 ( V_2 , V_97 ) ;
V_106 = F_33 ( & V_71 -> V_1 , V_2 ) ;
if ( V_106 != NULL ) {
( void ) F_33 ( & V_71 -> V_1 , V_106 ) ;
V_107 = - V_122 ;
goto V_236;
}
if ( F_59 ( & V_69 ) == 1 )
F_60 () ;
return 0 ;
V_236:
F_24 ( V_2 ) ;
return V_107 ;
}
static int F_189 ( const char * V_237 )
{
int V_108 ;
int V_238 = 0 ;
char * V_42 , * V_208 , * V_239 ;
V_42 = F_190 ( V_237 , V_82 ) ;
if ( V_42 == NULL )
return - V_83 ;
V_208 = F_191 ( V_42 ) ;
while ( 1 ) {
V_239 = F_192 ( & V_208 , L_30 ) ;
if ( V_239 == NULL )
break;
if ( * V_239 == '\0' )
continue;
for ( V_108 = 0 ; V_108 < F_174 ( V_240 ) ; V_108 ++ ) {
if ( strcasecmp ( V_239 , V_240 [ V_108 ] . V_237 ) == 0 ) {
V_238 |= V_240 [ V_108 ] . V_238 ;
break;
}
}
if ( V_108 == F_174 ( V_240 ) ) {
V_238 = - V_72 ;
break;
}
}
F_28 ( V_42 ) ;
return V_238 ;
}
static T_6 F_193 ( char * V_42 , int V_238 )
{
int V_108 ;
char * V_241 = V_42 ;
for ( V_108 = 0 ; V_108 < F_174 ( V_240 ) ; V_108 ++ ) {
if ( V_238 & V_240 [ V_108 ] . V_238 ) {
V_241 += sprintf ( V_241 , L_31 ,
( V_241 == V_42 ) ? L_10 : L_30 , V_240 [ V_108 ] . V_237 ) ;
}
}
* V_241 ++ = '\n' ;
return V_241 - V_42 ;
}
static struct V_70 * F_194 ( struct V_96 * V_97 )
{
if ( V_97 -> V_242 == NULL )
return NULL ;
return F_68 ( V_97 ) ;
}
static T_6 F_195 ( struct V_24 * V_25 ,
struct V_243 * V_244 ,
char * V_42 )
{
struct V_98 * V_241 = F_196 ( V_25 ) ;
struct V_70 * V_71 ;
struct V_96 * V_97 ;
T_6 V_107 = - V_131 ;
V_97 = F_197 ( F_198 ( V_241 ) ) ;
if ( V_97 == NULL )
goto V_188;
V_71 = F_194 ( V_97 ) ;
if ( V_71 == NULL )
goto V_245;
F_54 ( & V_97 -> V_132 ) ;
if ( V_244 == & V_246 ) {
V_107 = sprintf ( V_42 , L_1 , ! ! V_71 -> V_1 ) ;
goto V_247;
}
if ( V_71 -> V_1 == NULL )
V_107 = sprintf ( V_42 , L_32 ) ;
else if ( V_244 == & V_248 )
V_107 = F_193 ( V_42 , V_71 -> V_1 -> V_45 ) ;
else if ( V_244 == & V_249 )
V_107 = sprintf ( V_42 , L_1 , V_71 -> V_1 -> V_3 ) ;
else if ( V_244 == & V_250 )
V_107 = sprintf ( V_42 , L_33 , V_71 -> V_1 -> V_53 ) ;
else if ( V_244 == & V_251 )
V_107 = sprintf ( V_42 , L_33 , V_71 -> V_1 -> V_54 ) ;
V_247:
F_56 ( & V_97 -> V_132 ) ;
V_245:
F_199 ( V_97 ) ;
V_188:
return V_107 ;
}
static T_6 F_200 ( struct V_24 * V_25 ,
struct V_243 * V_244 ,
const char * V_42 , T_2 V_78 )
{
struct V_96 * V_97 ;
struct V_70 * V_71 ;
struct V_98 * V_241 ;
T_15 V_252 ;
T_6 V_107 = - V_72 ;
if ( V_78 == 0 )
goto V_188;
if ( V_244 == & V_248 ) {
if ( sscanf ( V_42 , L_34 , & V_252 ) != 1 ) {
V_107 = F_189 ( V_42 ) ;
if ( V_107 < 0 )
goto V_188;
V_252 = V_107 ;
}
} else if ( sscanf ( V_42 , L_35 , & V_252 ) != 1 )
goto V_188;
V_107 = - V_131 ;
V_241 = F_196 ( V_25 ) ;
V_97 = F_197 ( F_198 ( V_241 ) ) ;
if ( V_97 == NULL )
goto V_188;
V_71 = F_194 ( V_97 ) ;
if ( V_71 == NULL )
goto V_245;
F_54 ( & V_97 -> V_132 ) ;
if ( V_244 == & V_246 ) {
if ( V_252 )
V_107 = F_188 ( V_71 , V_97 ) ;
else
V_107 = F_187 ( V_71 ) ;
goto V_247;
}
V_107 = 0 ;
if ( V_71 -> V_1 == NULL )
V_107 = F_188 ( V_71 , V_97 ) ;
if ( V_107 == 0 ) {
if ( V_244 == & V_248 )
V_71 -> V_1 -> V_45 = V_252 ;
else if ( V_244 == & V_249 )
V_71 -> V_1 -> V_3 = V_252 ;
else if ( V_244 == & V_250 )
V_71 -> V_1 -> V_53 = V_252 ;
else if ( V_244 == & V_251 )
V_71 -> V_1 -> V_54 = V_252 ;
}
V_247:
F_56 ( & V_97 -> V_132 ) ;
V_245:
F_199 ( V_97 ) ;
V_188:
return V_107 ? V_107 : V_78 ;
}
int F_201 ( struct V_24 * V_25 )
{
return F_202 ( & V_25 -> V_253 , & V_254 ) ;
}
void F_203 ( struct V_24 * V_25 )
{
F_204 ( & V_25 -> V_253 , & V_254 ) ;
}
void F_205 ( char * V_42 , struct V_142 * V_143 )
{
int V_108 , V_210 ;
int V_6 = V_143 -> V_149 ;
unsigned char * V_128 = V_143 -> V_128 ;
if ( V_143 -> V_144 != V_145 ) {
V_42 [ 0 ] = '\0' ;
return;
}
for ( V_210 = V_6 - 1 ; V_210 >= 0 ; V_210 -- )
if ( V_128 [ V_210 ] )
break;
V_210 ++ ;
for ( V_108 = 0 ; V_108 < V_6 ; V_108 ++ ) {
V_42 += sprintf ( V_42 , L_9 , V_108 == 0 ? L_10 : L_11 , V_128 [ V_108 ] ) ;
if ( V_108 == V_210 && V_210 != V_6 - 1 ) {
sprintf ( V_42 , L_36 ) ;
break;
}
}
}
void F_206 ( char * V_186 , T_3 V_56 , int V_55 )
{
int V_108 = 0 ;
if ( V_56 & V_61 )
V_186 [ V_108 ++ ] = 'W' ;
else if ( V_56 & V_255 )
V_186 [ V_108 ++ ] = 'D' ;
else if ( V_55 )
V_186 [ V_108 ++ ] = 'R' ;
else
V_186 [ V_108 ++ ] = 'N' ;
if ( V_56 & V_256 )
V_186 [ V_108 ++ ] = 'A' ;
if ( V_56 & V_257 )
V_186 [ V_108 ++ ] = 'S' ;
if ( V_56 & V_258 )
V_186 [ V_108 ++ ] = 'M' ;
if ( V_56 & V_259 )
V_186 [ V_108 ++ ] = 'E' ;
V_186 [ V_108 ] = '\0' ;
}
