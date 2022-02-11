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
V_50 |= F_21 ( V_56 , V_66 ) ;
V_50 |= F_21 ( V_56 , V_67 ) ;
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
F_25 ( V_2 -> V_68 ) ;
F_25 ( V_2 -> V_69 ) ;
F_26 ( V_2 -> V_20 ) ;
F_25 ( V_2 -> V_70 ) ;
F_27 ( V_2 -> V_59 ) ;
F_27 ( V_2 -> V_47 ) ;
F_28 ( V_2 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_24 ( V_2 ) ;
if ( F_30 ( & V_71 ) )
F_31 () ;
}
int F_32 ( struct V_72 * V_73 )
{
struct V_1 * V_2 ;
V_2 = F_33 ( & V_73 -> V_1 , NULL ) ;
if ( ! V_2 )
return - V_74 ;
if ( V_2 -> V_43 != V_44 )
F_29 ( V_2 ) ;
return 0 ;
}
static T_6 F_34 ( struct V_75 * V_76 , char T_7 * V_12 ,
T_2 V_77 , T_8 * V_78 )
{
struct V_1 * V_2 = V_76 -> V_79 ;
char V_42 [ 16 ] ;
snprintf ( V_42 , sizeof( V_42 ) , L_1 , F_35 ( & V_2 -> V_80 ) ) ;
return F_36 ( V_12 , V_77 , V_78 , V_42 , strlen ( V_42 ) ) ;
}
static T_6 F_37 ( struct V_75 * V_76 , const char T_7 * V_12 ,
T_2 V_77 , T_8 * V_78 )
{
char * V_81 ;
struct V_1 * V_2 ;
if ( V_77 >= V_48 )
return - V_74 ;
V_81 = F_38 ( V_77 + 1 , V_82 ) ;
if ( V_81 == NULL )
return - V_83 ;
if ( F_39 ( V_81 , V_12 , V_77 ) ) {
F_28 ( V_81 ) ;
return - V_84 ;
}
V_81 [ V_77 ] = '\0' ;
V_2 = V_76 -> V_79 ;
F_15 ( V_2 , L_2 , V_81 ) ;
F_28 ( V_81 ) ;
return V_77 ;
}
static int F_40 ( struct V_85 * V_42 , void * V_86 ,
void * V_87 , T_2 V_88 )
{
struct V_1 * V_2 ;
if ( ! F_41 ( V_42 ) )
return 1 ;
V_2 = V_42 -> V_89 -> V_79 ;
F_42 ( & V_2 -> V_80 ) ;
return 0 ;
}
static int F_43 ( struct V_90 * V_90 )
{
F_25 ( V_90 ) ;
return 0 ;
}
static struct V_90 * F_44 ( const char * V_91 ,
struct V_90 * V_92 ,
T_9 V_93 ,
struct V_85 * V_42 ,
int * V_94 )
{
return F_45 ( V_91 , V_93 , V_92 , V_42 ,
& V_95 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
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
int F_47 ( struct V_72 * V_73 , char * V_103 , T_10 V_25 ,
struct V_96 * V_97 ,
struct V_104 * V_105 )
{
struct V_1 * V_106 , * V_2 = NULL ;
struct V_90 * V_70 = NULL ;
int V_107 , V_108 ;
if ( ! V_105 -> V_109 || ! V_105 -> V_110 )
return - V_74 ;
strncpy ( V_105 -> V_103 , V_103 , V_111 ) ;
V_105 -> V_103 [ V_111 - 1 ] = '\0' ;
for ( V_108 = 0 ; V_108 < strlen ( V_105 -> V_103 ) ; V_108 ++ )
if ( V_105 -> V_103 [ V_108 ] == '/' )
V_105 -> V_103 [ V_108 ] = '_' ;
V_2 = F_48 ( sizeof( * V_2 ) , V_82 ) ;
if ( ! V_2 )
return - V_83 ;
V_107 = - V_83 ;
V_2 -> V_59 = F_49 (unsigned long) ;
if ( ! V_2 -> V_59 )
goto V_112;
V_2 -> V_47 = F_50 ( V_48 , F_51 ( char ) ) ;
if ( ! V_2 -> V_47 )
goto V_112;
V_107 = - V_113 ;
F_52 ( & V_114 ) ;
if ( ! V_115 ) {
V_115 = F_53 ( L_3 , NULL ) ;
if ( ! V_115 ) {
F_54 ( & V_114 ) ;
goto V_112;
}
}
F_54 ( & V_114 ) ;
V_70 = F_53 ( V_105 -> V_103 , V_115 ) ;
if ( ! V_70 )
goto V_112;
V_2 -> V_70 = V_70 ;
V_2 -> V_25 = V_25 ;
F_55 ( & V_2 -> V_80 , 0 ) ;
V_107 = - V_116 ;
V_2 -> V_69 = F_45 ( L_4 , 0444 , V_70 , V_2 ,
& V_117 ) ;
if ( ! V_2 -> V_69 )
goto V_112;
V_2 -> V_68 = F_45 ( L_5 , 0222 , V_70 , V_2 , & V_118 ) ;
if ( ! V_2 -> V_68 )
goto V_112;
V_2 -> V_20 = F_56 ( L_6 , V_70 , V_105 -> V_109 ,
V_105 -> V_110 , & V_119 , V_2 ) ;
if ( ! V_2 -> V_20 )
goto V_112;
V_2 -> V_45 = V_105 -> V_45 ;
if ( ! V_2 -> V_45 )
V_2 -> V_45 = ( V_120 ) - 1 ;
F_46 ( V_2 , V_97 ) ;
if ( V_105 -> V_53 )
V_2 -> V_53 = V_105 -> V_53 ;
if ( V_105 -> V_54 )
V_2 -> V_54 = V_105 -> V_54 ;
V_2 -> V_3 = V_105 -> V_3 ;
V_2 -> V_43 = V_121 ;
V_107 = - V_122 ;
V_106 = F_33 ( & V_73 -> V_1 , V_2 ) ;
if ( V_106 ) {
( void ) F_33 ( & V_73 -> V_1 , V_106 ) ;
goto V_112;
}
if ( F_57 ( & V_71 ) == 1 )
F_58 () ;
return 0 ;
V_112:
F_24 ( V_2 ) ;
return V_107 ;
}
int F_59 ( struct V_72 * V_73 , char * V_103 , T_10 V_25 ,
struct V_96 * V_97 ,
char T_7 * V_123 )
{
struct V_104 V_105 ;
int V_107 ;
V_107 = F_39 ( & V_105 , V_123 , sizeof( V_105 ) ) ;
if ( V_107 )
return - V_84 ;
V_107 = F_47 ( V_73 , V_103 , V_25 , V_97 , & V_105 ) ;
if ( V_107 )
return V_107 ;
if ( F_60 ( V_123 , & V_105 , sizeof( V_105 ) ) ) {
F_32 ( V_73 ) ;
return - V_84 ;
}
return 0 ;
}
static int F_61 ( struct V_72 * V_73 , char * V_103 ,
T_10 V_25 , struct V_96 * V_97 ,
char T_7 * V_123 )
{
struct V_104 V_105 ;
struct V_124 V_125 ;
int V_107 ;
if ( F_39 ( & V_125 , V_123 , sizeof( V_125 ) ) )
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
V_107 = F_47 ( V_73 , V_103 , V_25 , V_97 , & V_105 ) ;
if ( V_107 )
return V_107 ;
if ( F_60 ( V_123 , & V_105 . V_103 , 32 ) ) {
F_32 ( V_73 ) ;
return - V_84 ;
}
return 0 ;
}
int F_62 ( struct V_72 * V_73 , int V_126 )
{
int V_107 ;
struct V_1 * V_2 = V_73 -> V_1 ;
if ( V_2 == NULL )
return - V_74 ;
V_107 = - V_74 ;
if ( V_126 ) {
if ( V_2 -> V_43 == V_121 ||
V_2 -> V_43 == V_127 ) {
V_30 ++ ;
F_63 () ;
V_2 -> V_43 = V_44 ;
F_11 ( V_2 ) ;
V_107 = 0 ;
}
} else {
if ( V_2 -> V_43 == V_44 ) {
V_2 -> V_43 = V_127 ;
F_64 ( V_2 -> V_20 ) ;
V_107 = 0 ;
}
}
return V_107 ;
}
int F_65 ( struct V_96 * V_97 , unsigned V_128 , char T_7 * V_123 )
{
struct V_72 * V_73 ;
int V_107 , V_126 = 0 ;
char V_129 [ V_130 ] ;
V_73 = F_66 ( V_97 ) ;
if ( ! V_73 )
return - V_131 ;
F_52 ( & V_97 -> V_132 ) ;
switch ( V_128 ) {
case V_133 :
F_67 ( V_97 , V_129 ) ;
V_107 = F_59 ( V_73 , V_129 , V_97 -> V_134 , V_97 , V_123 ) ;
break;
#if F_68 ( V_135 ) && F_68 ( V_136 )
case V_137 :
F_67 ( V_97 , V_129 ) ;
V_107 = F_61 ( V_73 , V_129 , V_97 -> V_134 , V_97 , V_123 ) ;
break;
#endif
case V_138 :
V_126 = 1 ;
case V_139 :
V_107 = F_62 ( V_73 , V_126 ) ;
break;
case V_140 :
V_107 = F_32 ( V_73 ) ;
break;
default:
V_107 = - V_141 ;
break;
}
F_54 ( & V_97 -> V_132 ) ;
return V_107 ;
}
void F_69 ( struct V_72 * V_73 )
{
if ( V_73 -> V_1 ) {
F_62 ( V_73 , 0 ) ;
F_32 ( V_73 ) ;
}
}
static void F_70 ( struct V_72 * V_73 , struct V_142 * V_143 ,
T_3 V_50 )
{
struct V_1 * V_2 = V_73 -> V_1 ;
if ( F_71 ( ! V_2 ) )
return;
if ( V_143 -> V_144 == V_145 ) {
V_50 |= F_72 ( V_146 ) ;
F_20 ( V_2 , 0 , F_73 ( V_143 ) , V_143 -> V_147 ,
V_50 , V_143 -> V_148 , V_143 -> V_149 , V_143 -> V_128 ) ;
} else {
V_50 |= F_72 ( V_150 ) ;
F_20 ( V_2 , F_74 ( V_143 ) , F_73 ( V_143 ) ,
V_143 -> V_147 , V_50 , V_143 -> V_148 , 0 , NULL ) ;
}
}
static void F_75 ( void * V_151 ,
struct V_72 * V_73 , struct V_142 * V_143 )
{
F_70 ( V_73 , V_143 , V_152 ) ;
}
static void F_76 ( void * V_151 ,
struct V_72 * V_73 , struct V_142 * V_143 )
{
F_70 ( V_73 , V_143 , V_153 ) ;
}
static void F_77 ( void * V_151 ,
struct V_72 * V_73 , struct V_142 * V_143 )
{
F_70 ( V_73 , V_143 , V_154 ) ;
}
static void F_78 ( void * V_151 ,
struct V_72 * V_73 ,
struct V_142 * V_143 )
{
F_70 ( V_73 , V_143 , V_155 ) ;
}
static void F_79 ( void * V_151 ,
struct V_72 * V_73 ,
struct V_142 * V_143 )
{
F_70 ( V_73 , V_143 , V_156 ) ;
}
static void F_80 ( struct V_72 * V_73 , struct V_157 * V_157 ,
T_3 V_50 , int error )
{
struct V_1 * V_2 = V_73 -> V_1 ;
if ( F_71 ( ! V_2 ) )
return;
if ( ! error && ! F_81 ( V_157 , V_158 ) )
error = V_116 ;
F_20 ( V_2 , V_157 -> V_159 , V_157 -> V_160 , V_157 -> V_161 , V_50 ,
error , 0 , NULL ) ;
}
static void F_82 ( void * V_151 ,
struct V_72 * V_73 , struct V_157 * V_157 )
{
F_80 ( V_73 , V_157 , V_162 , 0 ) ;
}
static void F_83 ( void * V_151 ,
struct V_72 * V_73 , struct V_157 * V_157 ,
int error )
{
F_80 ( V_73 , V_157 , V_156 , error ) ;
}
static void F_84 ( void * V_151 ,
struct V_72 * V_73 ,
struct V_157 * V_157 )
{
F_80 ( V_73 , V_157 , V_163 , 0 ) ;
}
static void F_85 ( void * V_151 ,
struct V_72 * V_73 ,
struct V_157 * V_157 )
{
F_80 ( V_73 , V_157 , V_164 , 0 ) ;
}
static void F_86 ( void * V_151 ,
struct V_72 * V_73 , struct V_157 * V_157 )
{
F_80 ( V_73 , V_157 , V_165 , 0 ) ;
}
static void F_87 ( void * V_151 ,
struct V_72 * V_73 ,
struct V_157 * V_157 , int V_56 )
{
if ( V_157 )
F_80 ( V_73 , V_157 , V_166 , 0 ) ;
else {
struct V_1 * V_2 = V_73 -> V_1 ;
if ( V_2 )
F_20 ( V_2 , 0 , 0 , V_56 , V_166 , 0 , 0 , NULL ) ;
}
}
static void F_88 ( void * V_151 ,
struct V_72 * V_73 ,
struct V_157 * V_157 , int V_56 )
{
if ( V_157 )
F_80 ( V_73 , V_157 , V_167 , 0 ) ;
else {
struct V_1 * V_2 = V_73 -> V_1 ;
if ( V_2 )
F_20 ( V_2 , 0 , 0 , V_56 , V_167 ,
0 , 0 , NULL ) ;
}
}
static void F_89 ( void * V_151 , struct V_72 * V_73 )
{
struct V_1 * V_2 = V_73 -> V_1 ;
if ( V_2 )
F_20 ( V_2 , 0 , 0 , 0 , V_168 , 0 , 0 , NULL ) ;
}
static void F_90 ( void * V_151 , struct V_72 * V_73 ,
unsigned int V_169 , bool V_170 )
{
struct V_1 * V_2 = V_73 -> V_1 ;
if ( V_2 ) {
T_11 V_171 = F_91 ( V_169 ) ;
T_3 V_50 ;
if ( V_170 )
V_50 = V_172 ;
else
V_50 = V_173 ;
F_20 ( V_2 , 0 , 0 , 0 , V_50 , 0 , sizeof( V_171 ) , & V_171 ) ;
}
}
static void F_92 ( void * V_151 ,
struct V_72 * V_73 , struct V_157 * V_157 ,
unsigned int V_174 )
{
struct V_1 * V_2 = V_73 -> V_1 ;
if ( V_2 ) {
T_11 V_171 = F_91 ( V_174 ) ;
F_20 ( V_2 , V_157 -> V_159 , V_157 -> V_160 , V_157 -> V_161 ,
V_175 , ! F_81 ( V_157 , V_158 ) ,
sizeof( V_171 ) , & V_171 ) ;
}
}
static void F_93 ( void * V_151 ,
struct V_72 * V_73 , struct V_157 * V_157 ,
T_10 V_25 , T_5 V_176 )
{
struct V_1 * V_2 = V_73 -> V_1 ;
struct V_177 V_178 ;
if ( F_71 ( ! V_2 ) )
return;
V_178 . V_179 = F_94 ( V_25 ) ;
V_178 . V_180 = F_94 ( V_157 -> V_181 -> V_134 ) ;
V_178 . V_182 = F_91 ( V_176 ) ;
F_20 ( V_2 , V_157 -> V_159 , V_157 -> V_160 , V_157 -> V_161 ,
V_183 , ! F_81 ( V_157 , V_158 ) ,
sizeof( V_178 ) , & V_178 ) ;
}
static void F_95 ( void * V_151 ,
struct V_72 * V_73 ,
struct V_142 * V_143 , T_10 V_25 ,
T_5 V_176 )
{
struct V_1 * V_2 = V_73 -> V_1 ;
struct V_177 V_178 ;
if ( F_71 ( ! V_2 ) )
return;
V_178 . V_179 = F_94 ( V_25 ) ;
V_178 . V_180 = F_94 ( F_96 ( V_143 -> V_184 ) ) ;
V_178 . V_182 = F_91 ( V_176 ) ;
F_20 ( V_2 , F_74 ( V_143 ) , F_73 ( V_143 ) ,
F_97 ( V_143 ) , V_183 , ! ! V_143 -> V_148 ,
sizeof( V_178 ) , & V_178 ) ;
}
void F_98 ( struct V_72 * V_73 ,
struct V_142 * V_143 ,
void * V_5 , T_2 V_6 )
{
struct V_1 * V_2 = V_73 -> V_1 ;
if ( F_71 ( ! V_2 ) )
return;
if ( V_143 -> V_144 == V_145 )
F_20 ( V_2 , 0 , F_73 ( V_143 ) , 0 ,
V_185 , V_143 -> V_148 , V_6 , V_5 ) ;
else
F_20 ( V_2 , F_74 ( V_143 ) , F_73 ( V_143 ) , 0 ,
V_185 , V_143 -> V_148 , V_6 , V_5 ) ;
}
static void F_58 ( void )
{
int V_107 ;
V_107 = F_99 ( F_75 , NULL ) ;
F_100 ( V_107 ) ;
V_107 = F_101 ( F_76 , NULL ) ;
F_100 ( V_107 ) ;
V_107 = F_102 ( F_77 , NULL ) ;
F_100 ( V_107 ) ;
V_107 = F_103 ( F_78 , NULL ) ;
F_100 ( V_107 ) ;
V_107 = F_104 ( F_79 , NULL ) ;
F_100 ( V_107 ) ;
V_107 = F_105 ( F_82 , NULL ) ;
F_100 ( V_107 ) ;
V_107 = F_106 ( F_83 , NULL ) ;
F_100 ( V_107 ) ;
V_107 = F_107 ( F_84 , NULL ) ;
F_100 ( V_107 ) ;
V_107 = F_108 ( F_85 , NULL ) ;
F_100 ( V_107 ) ;
V_107 = F_109 ( F_86 , NULL ) ;
F_100 ( V_107 ) ;
V_107 = F_110 ( F_87 , NULL ) ;
F_100 ( V_107 ) ;
V_107 = F_111 ( F_88 , NULL ) ;
F_100 ( V_107 ) ;
V_107 = F_112 ( F_89 , NULL ) ;
F_100 ( V_107 ) ;
V_107 = F_113 ( F_90 , NULL ) ;
F_100 ( V_107 ) ;
V_107 = F_114 ( F_92 , NULL ) ;
F_100 ( V_107 ) ;
V_107 = F_115 ( F_93 , NULL ) ;
F_100 ( V_107 ) ;
V_107 = F_116 ( F_95 , NULL ) ;
F_100 ( V_107 ) ;
}
static void F_31 ( void )
{
F_117 ( F_95 , NULL ) ;
F_118 ( F_93 , NULL ) ;
F_119 ( F_92 , NULL ) ;
F_120 ( F_90 , NULL ) ;
F_121 ( F_89 , NULL ) ;
F_122 ( F_88 , NULL ) ;
F_123 ( F_87 , NULL ) ;
F_124 ( F_86 , NULL ) ;
F_125 ( F_85 , NULL ) ;
F_126 ( F_84 , NULL ) ;
F_127 ( F_83 , NULL ) ;
F_128 ( F_82 , NULL ) ;
F_129 ( F_79 , NULL ) ;
F_130 ( F_78 , NULL ) ;
F_131 ( F_77 , NULL ) ;
F_132 ( F_76 , NULL ) ;
F_133 ( F_75 , NULL ) ;
F_134 () ;
}
static void F_135 ( char * V_186 , const struct V_7 * V_8 )
{
int V_108 = 0 ;
int V_187 = V_8 -> V_4 >> V_52 ;
if ( V_8 -> V_4 == V_49 ) {
V_186 [ V_108 ++ ] = 'N' ;
goto V_188;
}
if ( V_187 & V_189 )
V_186 [ V_108 ++ ] = 'F' ;
if ( V_187 & V_190 )
V_186 [ V_108 ++ ] = 'D' ;
else if ( V_187 & V_191 )
V_186 [ V_108 ++ ] = 'W' ;
else if ( V_8 -> V_55 )
V_186 [ V_108 ++ ] = 'R' ;
else
V_186 [ V_108 ++ ] = 'N' ;
if ( V_187 & V_192 )
V_186 [ V_108 ++ ] = 'F' ;
if ( V_187 & V_193 )
V_186 [ V_108 ++ ] = 'A' ;
if ( V_187 & V_194 )
V_186 [ V_108 ++ ] = 'S' ;
if ( V_187 & V_195 )
V_186 [ V_108 ++ ] = 'M' ;
V_188:
V_186 [ V_108 ] = '\0' ;
}
static inline
const struct V_7 * F_136 ( const struct V_196 * V_197 )
{
return ( const struct V_7 * ) V_197 ;
}
static inline const void * F_137 ( const struct V_196 * V_197 )
{
return F_136 ( V_197 ) + 1 ;
}
static inline T_3 F_138 ( const struct V_196 * V_197 )
{
return F_136 ( V_197 ) -> V_4 ;
}
static inline T_3 F_139 ( const struct V_196 * V_197 )
{
return F_136 ( V_197 ) -> V_55 ;
}
static inline T_3 F_140 ( const struct V_196 * V_197 )
{
return F_136 ( V_197 ) -> V_55 >> 9 ;
}
static inline unsigned long long F_141 ( const struct V_196 * V_197 )
{
return F_136 ( V_197 ) -> V_51 ;
}
static inline T_12 F_142 ( const struct V_196 * V_197 )
{
return F_136 ( V_197 ) -> error ;
}
static T_13 F_143 ( const struct V_196 * V_197 )
{
const T_13 * V_198 = F_137 ( V_197 ) ;
return F_144 ( * V_198 ) ;
}
static void F_145 ( const struct V_196 * V_197 ,
struct V_177 * V_178 )
{
const struct V_177 * V_199 = F_137 ( V_197 ) ;
T_13 V_182 = V_199 -> V_182 ;
V_178 -> V_179 = F_146 ( V_199 -> V_179 ) ;
V_178 -> V_180 = F_146 ( V_199 -> V_180 ) ;
V_178 -> V_182 = F_144 ( V_182 ) ;
}
static int F_147 ( struct V_200 * V_201 , const char * V_202 )
{
char V_186 [ V_203 ] ;
unsigned long long V_204 = V_201 -> V_204 ;
unsigned long V_205 = F_148 ( V_204 , V_206 ) ;
unsigned V_207 = ( unsigned long ) V_204 ;
const struct V_7 * V_8 = F_136 ( V_201 -> V_197 ) ;
F_135 ( V_186 , V_8 ) ;
return F_149 ( & V_201 -> V_208 ,
L_7 ,
F_150 ( V_8 -> V_24 ) , F_151 ( V_8 -> V_24 ) , V_201 -> V_14 ,
V_207 , V_205 , V_201 -> V_197 -> V_3 , V_202 , V_186 ) ;
}
static int F_152 ( struct V_200 * V_201 , const char * V_202 )
{
char V_186 [ V_203 ] ;
const struct V_7 * V_8 = F_136 ( V_201 -> V_197 ) ;
F_135 ( V_186 , V_8 ) ;
return F_149 ( & V_201 -> V_208 , L_8 ,
F_150 ( V_8 -> V_24 ) , F_151 ( V_8 -> V_24 ) , V_202 , V_186 ) ;
}
static int F_153 ( struct V_209 * V_210 , const struct V_196 * V_197 )
{
const unsigned char * V_211 ;
int V_26 ;
int V_108 , V_212 , V_107 ;
V_211 = F_137 ( V_197 ) ;
V_26 = F_136 ( V_197 ) -> V_26 ;
if ( ! V_26 )
return 1 ;
for ( V_212 = V_26 - 1 ; V_212 >= 0 ; V_212 -- )
if ( V_211 [ V_212 ] )
break;
V_212 ++ ;
if ( ! F_154 ( V_210 , '(' ) )
return 0 ;
for ( V_108 = 0 ; V_108 < V_26 ; V_108 ++ ) {
V_107 = F_149 ( V_210 , L_9 ,
V_108 == 0 ? L_10 : L_11 , V_211 [ V_108 ] ) ;
if ( ! V_107 )
return V_107 ;
if ( V_108 == V_212 && V_212 != V_26 - 1 )
return F_155 ( V_210 , L_12 ) ;
}
return F_155 ( V_210 , L_13 ) ;
}
static int F_156 ( struct V_209 * V_210 , const struct V_196 * V_197 )
{
char V_128 [ V_213 ] ;
F_157 ( V_197 -> V_3 , V_128 ) ;
if ( F_138 ( V_197 ) & F_72 ( V_146 ) ) {
int V_107 ;
V_107 = F_149 ( V_210 , L_14 , F_139 ( V_197 ) ) ;
if ( ! V_107 )
return 0 ;
V_107 = F_153 ( V_210 , V_197 ) ;
if ( ! V_107 )
return 0 ;
return F_149 ( V_210 , L_15 , V_128 ) ;
} else {
if ( F_140 ( V_197 ) )
return F_149 ( V_210 , L_16 ,
F_141 ( V_197 ) , F_140 ( V_197 ) , V_128 ) ;
return F_149 ( V_210 , L_15 , V_128 ) ;
}
}
static int F_158 ( struct V_209 * V_210 ,
const struct V_196 * V_197 )
{
if ( F_138 ( V_197 ) & F_72 ( V_146 ) ) {
int V_107 ;
V_107 = F_153 ( V_210 , V_197 ) ;
if ( V_107 )
return F_149 ( V_210 , L_17 , F_142 ( V_197 ) ) ;
return 0 ;
} else {
if ( F_140 ( V_197 ) )
return F_149 ( V_210 , L_18 ,
F_141 ( V_197 ) ,
F_140 ( V_197 ) , F_142 ( V_197 ) ) ;
return F_149 ( V_210 , L_19 ,
F_141 ( V_197 ) , F_142 ( V_197 ) ) ;
}
}
static int F_159 ( struct V_209 * V_210 , const struct V_196 * V_197 )
{
struct V_177 V_178 = { . V_179 = 0 , } ;
F_145 ( V_197 , & V_178 ) ;
return F_149 ( V_210 , L_20 ,
F_141 ( V_197 ) , F_140 ( V_197 ) ,
F_150 ( V_178 . V_179 ) , F_151 ( V_178 . V_179 ) ,
( unsigned long long ) V_178 . V_182 ) ;
}
static int F_160 ( struct V_209 * V_210 , const struct V_196 * V_197 )
{
char V_128 [ V_213 ] ;
F_157 ( V_197 -> V_3 , V_128 ) ;
return F_149 ( V_210 , L_15 , V_128 ) ;
}
static int F_161 ( struct V_209 * V_210 , const struct V_196 * V_197 )
{
char V_128 [ V_213 ] ;
F_157 ( V_197 -> V_3 , V_128 ) ;
return F_149 ( V_210 , L_21 , V_128 , F_143 ( V_197 ) ) ;
}
static int F_162 ( struct V_209 * V_210 , const struct V_196 * V_197 )
{
char V_128 [ V_213 ] ;
F_157 ( V_197 -> V_3 , V_128 ) ;
return F_149 ( V_210 , L_22 , F_141 ( V_197 ) ,
F_143 ( V_197 ) , V_128 ) ;
}
static int F_163 ( struct V_209 * V_210 , const struct V_196 * V_197 )
{
int V_107 ;
const struct V_7 * V_8 = F_136 ( V_197 ) ;
V_107 = F_164 ( V_210 , V_8 + 1 , V_8 -> V_26 ) ;
if ( V_107 )
return F_154 ( V_210 , '\n' ) ;
return V_107 ;
}
static void F_165 ( struct V_214 * V_215 )
{
if ( ! ( V_216 . V_198 & V_217 ) )
return;
F_166 ( V_215 , L_23
L_24 ) ;
}
static void F_167 ( struct V_218 * V_219 )
{
V_16 = true ;
}
static int F_168 ( struct V_218 * V_219 )
{
V_17 = V_219 ;
F_167 ( V_219 ) ;
return 0 ;
}
static void F_169 ( struct V_218 * V_219 )
{
V_16 = false ;
}
static void F_170 ( struct V_218 * V_219 )
{
F_169 ( V_219 ) ;
}
static enum V_220 F_171 ( struct V_200 * V_201 ,
bool V_221 )
{
struct V_209 * V_210 = & V_201 -> V_208 ;
const struct V_7 * V_8 ;
V_120 V_50 ;
int V_107 ;
bool V_222 ;
T_14 * V_223 ;
V_8 = F_136 ( V_201 -> V_197 ) ;
V_50 = V_8 -> V_4 & ( ( 1 << V_52 ) - 1 ) ;
V_222 = ! ! ( V_224 & V_225 ) ;
V_223 = V_221 ? & F_147 : & F_152 ;
if ( V_8 -> V_4 == V_49 ) {
V_107 = V_223 ( V_201 , V_222 ? L_25 : L_26 ) ;
if ( V_107 )
V_107 = F_163 ( V_210 , V_201 -> V_197 ) ;
goto V_188;
}
if ( F_16 ( V_50 == 0 || V_50 >= F_172 ( V_226 ) ) )
V_107 = F_149 ( V_210 , L_27 , V_50 ) ;
else {
V_107 = V_223 ( V_201 , V_226 [ V_50 ] . V_202 [ V_222 ] ) ;
if ( V_107 )
V_107 = V_226 [ V_50 ] . F_173 ( V_210 , V_201 -> V_197 ) ;
}
V_188:
return V_107 ? V_227 : V_228 ;
}
static enum V_220 F_174 ( struct V_200 * V_201 ,
int V_35 , struct V_229 * V_10 )
{
return F_171 ( V_201 , false ) ;
}
static int F_175 ( struct V_200 * V_201 )
{
struct V_209 * V_210 = & V_201 -> V_208 ;
struct V_7 * V_8 = (struct V_7 * ) V_201 -> V_197 ;
const int V_230 = F_176 ( struct V_7 , V_51 ) ;
struct V_7 V_231 = {
. V_21 = V_22 | V_23 ,
. time = V_201 -> V_204 ,
} ;
if ( ! F_164 ( V_210 , & V_231 , V_230 ) )
return 0 ;
return F_164 ( V_210 , & V_8 -> V_51 ,
sizeof( V_231 ) - V_230 + V_8 -> V_26 ) ;
}
static enum V_220
F_177 ( struct V_200 * V_201 , int V_35 ,
struct V_229 * V_10 )
{
return F_175 ( V_201 ) ?
V_227 : V_228 ;
}
static enum V_220 F_178 ( struct V_200 * V_201 )
{
if ( ! ( V_216 . V_198 & V_217 ) )
return V_232 ;
return F_171 ( V_201 , true ) ;
}
static int F_179 ( T_3 V_233 , T_3 V_234 , int V_235 )
{
if ( V_234 == V_217 ) {
if ( V_235 )
V_224 &= ~ V_236 ;
else
V_224 |= V_236 ;
}
return 0 ;
}
static int T_15 F_180 ( void )
{
if ( ! F_181 ( & V_237 ) ) {
F_182 ( L_28 ) ;
return 1 ;
}
if ( F_183 ( & V_15 ) != 0 ) {
F_182 ( L_29 ) ;
F_184 ( & V_237 ) ;
return 1 ;
}
return 0 ;
}
static int F_185 ( struct V_72 * V_73 )
{
struct V_1 * V_2 ;
V_2 = F_33 ( & V_73 -> V_1 , NULL ) ;
if ( V_2 == NULL )
return - V_74 ;
if ( F_30 ( & V_71 ) )
F_31 () ;
F_24 ( V_2 ) ;
return 0 ;
}
static int F_186 ( struct V_72 * V_73 ,
struct V_96 * V_97 )
{
struct V_1 * V_106 , * V_2 = NULL ;
int V_107 = - V_83 ;
V_2 = F_48 ( sizeof( * V_2 ) , V_82 ) ;
if ( ! V_2 )
return - V_83 ;
V_2 -> V_47 = F_50 ( V_48 , F_51 ( char ) ) ;
if ( ! V_2 -> V_47 )
goto V_238;
V_2 -> V_25 = V_97 -> V_134 ;
V_2 -> V_45 = ( V_120 ) - 1 ;
F_46 ( V_2 , V_97 ) ;
V_106 = F_33 ( & V_73 -> V_1 , V_2 ) ;
if ( V_106 != NULL ) {
( void ) F_33 ( & V_73 -> V_1 , V_106 ) ;
V_107 = - V_122 ;
goto V_238;
}
if ( F_57 ( & V_71 ) == 1 )
F_58 () ;
return 0 ;
V_238:
F_24 ( V_2 ) ;
return V_107 ;
}
static int F_187 ( const char * V_239 )
{
int V_108 ;
int V_240 = 0 ;
char * V_42 , * V_210 , * V_241 ;
V_42 = F_188 ( V_239 , V_82 ) ;
if ( V_42 == NULL )
return - V_83 ;
V_210 = F_189 ( V_42 ) ;
while ( 1 ) {
V_241 = F_190 ( & V_210 , L_30 ) ;
if ( V_241 == NULL )
break;
if ( * V_241 == '\0' )
continue;
for ( V_108 = 0 ; V_108 < F_172 ( V_242 ) ; V_108 ++ ) {
if ( strcasecmp ( V_241 , V_242 [ V_108 ] . V_239 ) == 0 ) {
V_240 |= V_242 [ V_108 ] . V_240 ;
break;
}
}
if ( V_108 == F_172 ( V_242 ) ) {
V_240 = - V_74 ;
break;
}
}
F_28 ( V_42 ) ;
return V_240 ;
}
static T_6 F_191 ( char * V_42 , int V_240 )
{
int V_108 ;
char * V_243 = V_42 ;
for ( V_108 = 0 ; V_108 < F_172 ( V_242 ) ; V_108 ++ ) {
if ( V_240 & V_242 [ V_108 ] . V_240 ) {
V_243 += sprintf ( V_243 , L_31 ,
( V_243 == V_42 ) ? L_10 : L_30 , V_242 [ V_108 ] . V_239 ) ;
}
}
* V_243 ++ = '\n' ;
return V_243 - V_42 ;
}
static struct V_72 * F_192 ( struct V_96 * V_97 )
{
if ( V_97 -> V_244 == NULL )
return NULL ;
return F_66 ( V_97 ) ;
}
static T_6 F_193 ( struct V_24 * V_25 ,
struct V_245 * V_246 ,
char * V_42 )
{
struct V_98 * V_243 = F_194 ( V_25 ) ;
struct V_72 * V_73 ;
struct V_96 * V_97 ;
T_6 V_107 = - V_131 ;
V_97 = F_195 ( F_196 ( V_243 ) ) ;
if ( V_97 == NULL )
goto V_188;
V_73 = F_192 ( V_97 ) ;
if ( V_73 == NULL )
goto V_247;
F_52 ( & V_97 -> V_132 ) ;
if ( V_246 == & V_248 ) {
V_107 = sprintf ( V_42 , L_1 , ! ! V_73 -> V_1 ) ;
goto V_249;
}
if ( V_73 -> V_1 == NULL )
V_107 = sprintf ( V_42 , L_32 ) ;
else if ( V_246 == & V_250 )
V_107 = F_191 ( V_42 , V_73 -> V_1 -> V_45 ) ;
else if ( V_246 == & V_251 )
V_107 = sprintf ( V_42 , L_1 , V_73 -> V_1 -> V_3 ) ;
else if ( V_246 == & V_252 )
V_107 = sprintf ( V_42 , L_33 , V_73 -> V_1 -> V_53 ) ;
else if ( V_246 == & V_253 )
V_107 = sprintf ( V_42 , L_33 , V_73 -> V_1 -> V_54 ) ;
V_249:
F_54 ( & V_97 -> V_132 ) ;
V_247:
F_197 ( V_97 ) ;
V_188:
return V_107 ;
}
static T_6 F_198 ( struct V_24 * V_25 ,
struct V_245 * V_246 ,
const char * V_42 , T_2 V_77 )
{
struct V_96 * V_97 ;
struct V_72 * V_73 ;
struct V_98 * V_243 ;
T_16 V_254 ;
T_6 V_107 = - V_74 ;
if ( V_77 == 0 )
goto V_188;
if ( V_246 == & V_250 ) {
if ( sscanf ( V_42 , L_34 , & V_254 ) != 1 ) {
V_107 = F_187 ( V_42 ) ;
if ( V_107 < 0 )
goto V_188;
V_254 = V_107 ;
}
} else if ( sscanf ( V_42 , L_35 , & V_254 ) != 1 )
goto V_188;
V_107 = - V_131 ;
V_243 = F_194 ( V_25 ) ;
V_97 = F_195 ( F_196 ( V_243 ) ) ;
if ( V_97 == NULL )
goto V_188;
V_73 = F_192 ( V_97 ) ;
if ( V_73 == NULL )
goto V_247;
F_52 ( & V_97 -> V_132 ) ;
if ( V_246 == & V_248 ) {
if ( V_254 )
V_107 = F_186 ( V_73 , V_97 ) ;
else
V_107 = F_185 ( V_73 ) ;
goto V_249;
}
V_107 = 0 ;
if ( V_73 -> V_1 == NULL )
V_107 = F_186 ( V_73 , V_97 ) ;
if ( V_107 == 0 ) {
if ( V_246 == & V_250 )
V_73 -> V_1 -> V_45 = V_254 ;
else if ( V_246 == & V_251 )
V_73 -> V_1 -> V_3 = V_254 ;
else if ( V_246 == & V_252 )
V_73 -> V_1 -> V_53 = V_254 ;
else if ( V_246 == & V_253 )
V_73 -> V_1 -> V_54 = V_254 ;
}
V_249:
F_54 ( & V_97 -> V_132 ) ;
V_247:
F_197 ( V_97 ) ;
V_188:
return V_107 ? V_107 : V_77 ;
}
int F_199 ( struct V_24 * V_25 )
{
return F_200 ( & V_25 -> V_255 , & V_256 ) ;
}
void F_201 ( struct V_24 * V_25 )
{
F_202 ( & V_25 -> V_255 , & V_256 ) ;
}
void F_203 ( char * V_42 , struct V_142 * V_143 )
{
int V_108 , V_212 ;
int V_6 = V_143 -> V_149 ;
unsigned char * V_128 = V_143 -> V_128 ;
if ( V_143 -> V_144 != V_145 ) {
V_42 [ 0 ] = '\0' ;
return;
}
for ( V_212 = V_6 - 1 ; V_212 >= 0 ; V_212 -- )
if ( V_128 [ V_212 ] )
break;
V_212 ++ ;
for ( V_108 = 0 ; V_108 < V_6 ; V_108 ++ ) {
V_42 += sprintf ( V_42 , L_9 , V_108 == 0 ? L_10 : L_11 , V_128 [ V_108 ] ) ;
if ( V_108 == V_212 && V_212 != V_6 - 1 ) {
sprintf ( V_42 , L_36 ) ;
break;
}
}
}
void F_204 ( char * V_186 , T_3 V_56 , int V_55 )
{
int V_108 = 0 ;
if ( V_56 & V_257 )
V_186 [ V_108 ++ ] = 'F' ;
if ( V_56 & V_61 )
V_186 [ V_108 ++ ] = 'W' ;
else if ( V_56 & V_258 )
V_186 [ V_108 ++ ] = 'D' ;
else if ( V_55 )
V_186 [ V_108 ++ ] = 'R' ;
else
V_186 [ V_108 ++ ] = 'N' ;
if ( V_56 & V_259 )
V_186 [ V_108 ++ ] = 'F' ;
if ( V_56 & V_260 )
V_186 [ V_108 ++ ] = 'A' ;
if ( V_56 & V_261 )
V_186 [ V_108 ++ ] = 'S' ;
if ( V_56 & V_262 )
V_186 [ V_108 ++ ] = 'M' ;
if ( V_56 & V_263 )
V_186 [ V_108 ++ ] = 'E' ;
V_186 [ V_108 ] = '\0' ;
}
