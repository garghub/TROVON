static int F_1 ( T_1 * V_1 , int V_2 , long V_3 , void * V_4 , void (* F_2) ( void ) )
{
int V_5 = 1 ;
T_2 * V_6 ;
T_3 * V_7 ;
T_4 V_8 ;
if ( V_9 == - 1 ) {
F_3 ( V_10 , V_11 ) ;
return 0 ;
}
V_6 = F_4 ( V_1 , V_9 ) ;
V_7 = F_5 ( stdout , V_12 ) ;
if ( V_7 == NULL ) {
F_3 ( V_10 , V_13 ) ;
return 0 ;
}
switch ( V_2 ) {
case V_14 :
V_5 = F_6 ( V_6 , V_7 ) ;
break;
case V_15 :
V_5 = F_7 ( V_6 , V_7 , NULL ) ;
break;
case V_16 :
V_5 = F_7 ( V_6 , V_7 , V_4 ) ;
break;
case V_17 :
V_5 = F_8 ( V_6 , V_7 ) ;
break;
case V_18 :
V_8 = F_9 ( V_4 ) ;
if ( V_8 != NULL ) {
F_10 ( V_6 -> V_19 ) ;
V_6 -> V_19 = V_8 ;
F_11 ( V_6 , L_1 , V_4 ) ;
} else {
F_3 ( V_10 , V_20 ) ;
V_5 = 0 ;
}
break;
case V_21 :
if ( V_3 & 1 ) {
V_6 -> V_22 |= V_23 ;
V_6 -> V_22 &= ~ V_24 ;
} else {
V_6 -> V_22 |= V_24 ;
V_6 -> V_22 &= ~ V_23 ;
}
F_11 ( V_6 , L_2 , V_3 ) ;
break;
case V_25 :
V_6 -> V_26 = ( int ) V_3 ;
F_11 ( V_6 , L_3 , V_6 -> V_26 ) ;
break;
case V_27 :
V_8 = F_9 ( V_4 ) ;
if ( V_8 != NULL ) {
V_6 -> V_28 = V_8 ;
F_11 ( V_6 , L_4 , V_6 -> V_28 ) ;
} else {
F_3 ( V_10 , V_20 ) ;
V_5 = 0 ;
}
break;
case V_29 :
V_6 -> V_30 = V_3 ;
F_11 ( V_6 , L_5 , V_6 -> V_30 ) ;
break;
case V_31 :
V_5 = F_12 ( V_6 , V_3 ) ;
break;
case V_32 :
V_6 -> V_33 = V_3 ;
break;
case V_34 :
if ( V_3 < 1 || V_3 > 3 ) {
F_3 ( V_10 , V_35 ) ;
F_13 ( V_7 ) ;
return 0 ;
}
V_6 -> V_36 = V_3 ;
break;
case V_37 :
V_5 = F_14 ( V_6 , V_4 , V_6 -> V_38 , 1 ) ;
break;
case V_39 :
V_6 -> V_38 = V_3 ;
break;
default:
F_3 ( V_10 , V_40 ) ;
V_5 = 0 ;
}
F_13 ( V_7 ) ;
return V_5 ;
}
static int F_15 ( T_1 * V_1 )
{
T_2 * V_6 ;
const T_5 * V_41 ;
# ifndef F_16
const T_6 * V_42 ;
# endif
T_7 V_43 ;
if ( V_9 < 0 ) {
V_9 = F_17 ( 0 , NULL , NULL , NULL , 0 ) ;
if ( V_9 < 0 )
goto V_44;
V_45 = F_18 ( 0 , NULL , NULL , NULL , 0 ) ;
V_46 = F_19 ( 0 , NULL , NULL , NULL , 0 ) ;
V_41 = F_20 () ;
if ( ! F_21 ( V_47 ,
F_22 ( V_41 ) )
|| ! F_23 ( V_47 ,
F_24 ( V_41 ) )
|| ! F_25 ( V_47 , V_48 )
|| ! F_26 ( V_47 , V_49 )
|| ! F_27 ( V_47 ,
F_28 ( V_41 ) )
|| ! F_29 ( V_47 ,
F_30 ( V_41 ) )
|| ! F_31 ( V_47 , V_50 )
|| ! F_32 ( V_47 , V_51 ) ) {
goto V_44;
}
# ifndef F_16
V_52 = F_33 ( 0 , NULL , NULL , NULL , 0 ) ;
V_42 = F_34 () ;
if ( ! F_35 ( V_53 , V_54 )
|| ! F_36 ( V_53 ,
F_37 ( V_42 ) )
|| ! F_38 ( V_53 , V_55 )
|| ! F_39 ( V_53 ,
F_40 ( V_42 ) )
|| ! F_41 ( V_53 ,
F_42 ( V_42 ) ) ) {
goto V_44;
}
# endif
}
V_6 = F_43 () ;
if ( V_6 == NULL )
goto V_44;
F_44 ( V_1 , V_9 , V_6 ) ;
# ifdef F_45
{
T_8 V_56 = F_46 ( F_47 ( L_6 ) ) ;
T_8 V_57 = F_48 ( F_47 ( L_7 ) ) ;
if ( V_56 )
V_6 -> V_58 =
( V_59 ) F_49 ( V_56 ,
L_8 ) ;
if ( V_57 )
V_6 -> V_60 =
( V_61 ) F_49 ( V_57 , L_9 ) ;
if ( V_56 && ! F_50 () )
V_6 -> V_62 = V_63 ;
}
# endif
if ( F_51 ( & V_43 , NULL , NULL , V_64 ,
V_65 ) ) {
V_66 = 1 ;
F_52 ( V_43 , 0 ) ;
}
return 1 ;
V_44:
F_3 ( V_67 , V_20 ) ;
return 0 ;
return 1 ;
}
static int F_53 ( T_1 * V_1 )
{
F_54 ( V_47 ) ;
V_47 = NULL ;
# ifndef F_16
F_55 ( V_53 ) ;
V_53 = NULL ;
# endif
F_56 () ;
return 1 ;
}
static int F_57 ( T_1 * V_1 )
{
T_2 * V_6 ;
V_6 = F_4 ( V_1 , V_9 ) ;
F_58 ( V_6 ) ;
F_44 ( V_1 , V_9 , NULL ) ;
return 1 ;
}
static int F_59 ( T_1 * V_1 )
{
V_47 = F_60 ( L_10 , 0 ) ;
if ( V_47 == NULL )
return 0 ;
# ifndef F_16
V_53 = F_61 ( L_11 , 0 ) ;
if ( V_53 == NULL )
goto V_44;
# endif
if ( ! F_62 ( V_1 , V_68 )
|| ! F_63 ( V_1 , V_69 )
|| ! F_64 ( V_1 , V_70 )
|| ! F_65 ( V_1 , F_15 )
|| ! F_66 ( V_1 , F_57 )
|| ! F_67 ( V_1 , F_53 )
|| ! F_68 ( V_1 , V_47 )
# ifndef F_16
|| ! F_69 ( V_1 , V_53 )
# endif
|| ! F_70 ( V_1 , V_71 )
|| ! F_71 ( V_1 ,
V_72 )
|| ! F_72 ( V_1 , V_73 )
|| ! F_73 ( V_1 , F_1 ) )
goto V_44;
F_74 () ;
return 1 ;
V_44:
F_54 ( V_47 ) ;
V_47 = NULL ;
# ifndef F_16
F_55 ( V_53 ) ;
V_53 = NULL ;
# endif
return 0 ;
}
static int F_75 ( T_1 * V_1 , const char * V_74 )
{
if ( V_74 && ( strcmp ( V_74 , V_68 ) != 0 ) )
return 0 ;
if ( ! F_59 ( V_1 ) )
return 0 ;
return 1 ;
}
static T_1 * F_76 ( void )
{
T_1 * V_5 = F_77 () ;
if ( V_5 == NULL )
return NULL ;
if ( ! F_59 ( V_5 ) ) {
F_78 ( V_5 ) ;
return NULL ;
}
return V_5 ;
}
void F_79 ( void )
{
T_1 * V_75 = F_76 () ;
if ( ! V_75 )
return;
F_80 ( V_75 ) ;
F_78 ( V_75 ) ;
F_81 () ;
}
static int F_82 ( T_9 * V_76 , unsigned char * V_77 , int V_78 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_78 / 2 ; V_3 ++ ) {
unsigned char V_79 ;
V_79 = V_77 [ V_3 ] ;
V_77 [ V_3 ] = V_77 [ V_78 - V_3 - 1 ] ;
V_77 [ V_78 - V_3 - 1 ] = V_79 ;
}
if ( ! F_83 ( V_77 , V_78 , V_76 ) )
return 0 ;
return 1 ;
}
static T_10 * F_84 ( T_1 * V_80 , T_11 * V_81 )
{
unsigned char * V_82 = NULL ;
T_12 V_83 ;
T_13 * V_84 ;
T_14 * V_85 = NULL ;
T_15 * V_86 = NULL ;
T_10 * V_5 = NULL ;
if ( ! F_85 ( V_81 -> V_81 , 0 , V_87 , 0 , NULL , & V_83 ) ) {
F_3 ( V_88 , V_89 ) ;
F_86 () ;
return NULL ;
}
V_82 = F_87 ( V_83 ) ;
if ( V_82 == NULL )
goto V_44;
if ( ! F_85 ( V_81 -> V_81 , 0 , V_87 , 0 , V_82 , & V_83 ) ) {
F_3 ( V_88 , V_90 ) ;
F_86 () ;
goto V_91;
}
V_84 = ( T_13 * ) V_82 ;
if ( V_84 -> V_92 != V_87 ) {
F_3 ( V_88 , V_93 ) ;
goto V_91;
}
if ( V_84 -> V_94 == V_95 || V_84 -> V_94 == V_96 ) {
T_16 * V_97 ;
T_12 V_98 ;
T_9 * V_1 = NULL , * V_99 = NULL ;
unsigned char * V_100 ;
V_97 = ( T_16 * ) ( V_84 + 1 ) ;
if ( V_97 -> V_101 != 0x31415352 ) {
char V_102 [ 10 ] ;
F_88 ( V_102 , 10 , L_12 , V_97 -> V_101 ) ;
F_3 ( V_88 ,
V_103 ) ;
F_89 ( 2 , L_13 , V_102 ) ;
goto V_91;
}
V_100 = ( unsigned char * ) ( V_97 + 1 ) ;
V_85 = F_90 ( V_80 ) ;
if ( ! V_85 )
goto V_44;
V_1 = F_91 () ;
V_99 = F_91 () ;
if ( V_1 == NULL || V_99 == NULL ) {
F_92 ( V_1 ) ;
F_92 ( V_99 ) ;
goto V_44;
}
F_93 ( V_85 , V_99 , V_1 , NULL ) ;
if ( ! F_94 ( V_1 , V_97 -> V_104 ) )
goto V_44;
V_98 = V_97 -> V_105 / 8 ;
if ( ! F_82 ( V_99 , V_100 , V_98 ) )
goto V_44;
F_95 ( V_85 , V_46 , V_81 ) ;
if ( ( V_5 = F_96 () ) == NULL )
goto V_44;
F_97 ( V_5 , V_85 ) ;
V_85 = NULL ;
# ifndef F_16
} else if ( V_84 -> V_94 == V_106 ) {
T_17 * V_107 ;
T_12 V_108 ;
unsigned char * V_109 ;
T_9 * V_4 , * V_110 , * V_111 , * V_112 ;
V_107 = ( T_17 * ) ( V_84 + 1 ) ;
if ( V_107 -> V_101 != 0x31535344 ) {
char V_102 [ 10 ] ;
F_88 ( V_102 , 10 , L_12 , V_107 -> V_101 ) ;
F_3 ( V_88 ,
V_113 ) ;
F_89 ( 2 , L_13 , V_102 ) ;
goto V_91;
}
V_108 = V_107 -> V_105 / 8 ;
V_109 = ( unsigned char * ) ( V_107 + 1 ) ;
V_86 = F_98 ( V_80 ) ;
if ( ! V_86 )
goto V_44;
V_4 = F_91 () ;
V_110 = F_91 () ;
V_111 = F_91 () ;
V_112 = F_91 () ;
if ( V_4 == NULL || V_110 == NULL || V_111 == NULL || V_112 == NULL ) {
F_92 ( V_4 ) ;
F_92 ( V_110 ) ;
F_92 ( V_111 ) ;
F_92 ( V_112 ) ;
goto V_44;
}
F_99 ( V_86 , V_4 , V_110 , V_111 ) ;
F_100 ( V_86 , V_112 , NULL ) ;
if ( ! F_82 ( V_4 , V_109 , V_108 ) )
goto V_44;
V_109 += V_108 ;
if ( ! F_82 ( V_110 , V_109 , 20 ) )
goto V_44;
V_109 += 20 ;
if ( ! F_82 ( V_111 , V_109 , V_108 ) )
goto V_44;
V_109 += V_108 ;
if ( ! F_82 ( V_112 , V_109 , V_108 ) )
goto V_44;
V_109 += V_108 ;
F_101 ( V_86 , V_52 , V_81 ) ;
if ( ( V_5 = F_96 () ) == NULL )
goto V_44;
F_102 ( V_5 , V_86 ) ;
V_86 = NULL ;
# endif
} else {
char V_114 [ 10 ] ;
F_88 ( V_114 , 10 , L_14 , V_84 -> V_94 ) ;
F_3 ( V_88 ,
V_115 ) ;
F_89 ( 2 , L_15 , V_114 ) ;
goto V_91;
}
V_91:
F_10 ( V_82 ) ;
if ( ! V_5 ) {
F_103 ( V_85 ) ;
# ifndef F_16
F_104 ( V_86 ) ;
# endif
}
return V_5 ;
V_44:
F_3 ( V_88 , V_20 ) ;
goto V_91;
}
static T_10 * V_71 ( T_1 * V_80 , const char * V_116 ,
T_18 * V_117 , void * V_118 )
{
T_2 * V_6 ;
T_11 * V_81 ;
T_10 * V_5 ;
V_6 = F_4 ( V_80 , V_9 ) ;
if ( ! V_6 ) {
F_3 ( V_119 , V_120 ) ;
return NULL ;
}
V_81 = F_105 ( V_6 , V_116 ) ;
if ( ! V_81 )
return NULL ;
V_5 = F_84 ( V_80 , V_81 ) ;
if ( ! V_5 )
F_106 ( V_81 ) ;
return V_5 ;
}
int V_48 ( int V_121 , const unsigned char * V_122 ,
unsigned char * V_123 , T_14 * V_124 , int V_125 )
{
F_3 ( V_126 , V_127 ) ;
return - 1 ;
}
int V_51 ( int V_128 , const unsigned char * V_129 , unsigned int V_130 ,
unsigned char * V_131 , unsigned int * V_132 , const T_14 * V_124 )
{
T_19 V_133 ;
T_20 V_134 ;
T_12 V_135 ;
unsigned int V_3 ;
int V_5 = - 1 ;
T_11 * V_136 ;
T_2 * V_6 ;
V_6 = F_4 ( F_107 ( V_124 ) , V_9 ) ;
F_11 ( V_6 , L_16 ) ;
V_136 = F_108 ( V_124 , V_46 ) ;
if ( ! V_136 ) {
F_3 ( V_137 , V_138 ) ;
return - 1 ;
}
switch ( V_128 ) {
case V_139 :
V_133 = V_140 ;
break;
case V_141 :
V_133 = V_142 ;
break;
case V_143 :
V_133 = V_144 ;
break;
case V_145 :
V_133 = V_146 ;
break;
case V_147 :
V_133 = V_148 ;
break;
case V_149 :
V_133 = V_150 ;
break;
default:
{
char V_114 [ 10 ] ;
F_88 ( V_114 , 10 , L_17 , V_128 ) ;
F_3 ( V_137 , V_151 ) ;
F_89 ( 2 , L_18 , V_114 ) ;
return - 1 ;
}
}
if ( ! F_109 ( V_136 -> V_43 , V_133 , 0 , 0 , & V_134 ) ) {
F_3 ( V_137 , V_152 ) ;
F_86 () ;
return - 1 ;
}
if ( ! F_110 ( V_134 , V_153 , ( unsigned char * ) V_129 , 0 ) ) {
F_3 ( V_137 , V_154 ) ;
F_86 () ;
goto V_91;
}
V_135 = F_111 ( V_124 ) ;
if ( ! F_112 ( V_134 , V_136 -> V_155 , NULL , 0 , V_131 , & V_135 ) ) {
F_3 ( V_137 , V_156 ) ;
F_86 () ;
goto V_91;
} else {
V_5 = 1 ;
for ( V_3 = 0 ; V_3 < V_135 / 2 ; V_3 ++ ) {
unsigned char V_79 ;
V_79 = V_131 [ V_3 ] ;
V_131 [ V_3 ] = V_131 [ V_135 - V_3 - 1 ] ;
V_131 [ V_135 - V_3 - 1 ] = V_79 ;
}
* V_132 = V_135 ;
}
V_91:
F_113 ( V_134 ) ;
return V_5 ;
}
int V_49 ( int V_121 , const unsigned char * V_122 ,
unsigned char * V_123 , T_14 * V_124 , int V_125 )
{
int V_3 ;
unsigned char * V_157 ;
T_11 * V_136 ;
T_2 * V_6 ;
T_12 V_158 ;
if ( V_121 <= 0 )
return V_121 ;
V_6 = F_4 ( F_107 ( V_124 ) , V_9 ) ;
F_11 ( V_6 , L_19 ) ;
V_136 = F_108 ( V_124 , V_46 ) ;
if ( ! V_136 ) {
F_3 ( V_159 , V_138 ) ;
return - 1 ;
}
if ( V_125 != V_160 ) {
char V_161 [ 10 ] ;
F_88 ( V_161 , 10 , L_20 , V_125 ) ;
F_3 ( V_159 , V_162 ) ;
F_89 ( 2 , L_21 , V_161 ) ;
return - 1 ;
}
if ( ( V_157 = F_87 ( V_121 ) ) == NULL ) {
F_3 ( V_159 , V_20 ) ;
return - 1 ;
}
for ( V_3 = 0 ; V_3 < V_121 ; V_3 ++ )
V_157 [ V_121 - V_3 - 1 ] = V_122 [ V_3 ] ;
V_158 = V_121 ;
if ( ! F_114 ( V_136 -> V_81 , 0 , TRUE , 0 , V_157 , & V_158 ) ) {
F_3 ( V_159 , V_163 ) ;
F_86 () ;
F_10 ( V_157 ) ;
return - 1 ;
} else
memcpy ( V_123 , V_157 , ( V_121 = ( int ) V_158 ) ) ;
F_10 ( V_157 ) ;
return V_121 ;
}
static int V_50 ( T_14 * V_124 )
{
T_11 * V_136 ;
V_136 = F_108 ( V_124 , V_46 ) ;
F_106 ( V_136 ) ;
F_95 ( V_124 , V_46 , 0 ) ;
return 1 ;
}
static T_21 * V_54 ( const unsigned char * V_164 , int V_158 ,
T_15 * V_165 )
{
T_20 V_134 ;
T_12 V_135 ;
T_21 * V_5 = NULL ;
T_11 * V_136 ;
T_2 * V_6 ;
unsigned char V_166 [ 40 ] ;
V_6 = F_4 ( F_115 ( V_165 ) , V_9 ) ;
F_11 ( V_6 , L_22 ) ;
V_136 = F_116 ( V_165 , V_52 ) ;
if ( ! V_136 ) {
F_3 ( V_167 , V_138 ) ;
return NULL ;
}
if ( V_158 != 20 ) {
F_3 ( V_167 , V_168 ) ;
return NULL ;
}
if ( ! F_109 ( V_136 -> V_43 , V_146 , 0 , 0 , & V_134 ) ) {
F_3 ( V_167 , V_152 ) ;
F_86 () ;
return NULL ;
}
if ( ! F_110 ( V_134 , V_153 , ( unsigned char * ) V_164 , 0 ) ) {
F_3 ( V_167 , V_154 ) ;
F_86 () ;
goto V_91;
}
V_135 = sizeof( V_166 ) ;
if ( ! F_112 ( V_134 , V_136 -> V_155 , NULL , 0 , V_166 , & V_135 ) ) {
F_3 ( V_167 , V_156 ) ;
F_86 () ;
goto V_91;
} else {
T_9 * V_169 = F_91 () , * V_170 = F_91 () ;
if ( V_169 == NULL || V_170 == NULL
|| ! F_82 ( V_169 , V_166 , 20 )
|| ! F_82 ( V_170 , V_166 + 20 , 20 )
|| ( V_5 = F_117 () ) == NULL ) {
F_92 ( V_169 ) ;
F_92 ( V_170 ) ;
goto V_91;
}
F_118 ( V_5 , V_169 , V_170 ) ;
}
V_91:
F_119 ( V_166 , 40 ) ;
F_113 ( V_134 ) ;
return V_5 ;
}
static int V_55 ( T_15 * V_165 )
{
T_11 * V_136 ;
V_136 = F_116 ( V_165 , V_52 ) ;
F_106 ( V_136 ) ;
F_101 ( V_165 , V_52 , 0 ) ;
return 1 ;
}
static void F_120 ( T_2 * V_6 , int V_171 , char * V_172 ,
T_22 V_173 )
{
T_3 * V_7 ;
if ( ! V_6 || ( V_6 -> V_26 < V_171 ) || ( ! V_6 -> V_28 ) )
return;
V_7 = F_121 ( V_6 -> V_28 , L_23 ) ;
if ( V_7 == NULL ) {
F_3 ( V_174 , V_13 ) ;
return;
}
F_122 ( V_7 , V_172 , V_173 ) ;
F_13 ( V_7 ) ;
}
static void F_11 ( T_2 * V_6 , char * V_172 , ... )
{
T_22 args ;
va_start ( args , V_172 ) ;
F_120 ( V_6 , V_175 , V_172 , args ) ;
va_end ( args ) ;
}
static void F_86 ( void )
{
F_123 ( F_124 () ) ;
}
static void F_123 ( T_12 V_91 )
{
char V_161 [ 10 ] ;
F_88 ( V_161 , 10 , L_24 , V_91 ) ;
F_89 ( 2 , L_25 , V_161 ) ;
}
static char * F_125 ( T_23 V_176 )
{
char * V_177 ;
int V_178 , V_179 ;
if ( ! V_176 )
return NULL ;
V_178 = ( int ) wcslen ( V_176 ) + 1 ;
V_179 = F_126 ( V_180 , 0 , V_176 , V_178 , NULL , 0 , NULL , NULL ) ;
if ( ! V_179 ) {
F_3 ( V_181 , V_182 ) ;
return NULL ;
}
V_177 = F_87 ( V_179 ) ;
if ( V_177 == NULL ) {
F_3 ( V_181 , V_20 ) ;
return NULL ;
}
if ( ! F_126 ( V_180 , 0 , V_176 , V_178 , V_177 , V_179 , NULL , NULL ) ) {
F_10 ( V_177 ) ;
F_3 ( V_181 , V_182 ) ;
return NULL ;
}
return V_177 ;
}
static int F_127 ( T_2 * V_6 , T_4 * V_183 , T_12 * V_184 ,
T_12 V_185 )
{
T_12 V_83 , V_91 ;
T_24 V_186 ;
F_11 ( V_6 , L_26 , V_185 ) ;
if ( ! F_128 ( V_185 , NULL , 0 , V_184 , NULL , & V_83 ) ) {
V_91 = F_124 () ;
if ( V_91 == V_187 )
return 2 ;
F_3 ( V_188 , V_189 ) ;
F_123 ( V_91 ) ;
return 0 ;
}
V_186 = F_87 ( V_83 ) ;
if ( V_186 == NULL ) {
F_3 ( V_188 , V_20 ) ;
return 0 ;
}
if ( ! F_128 ( V_185 , NULL , 0 , V_184 , V_186 , & V_83 ) ) {
V_91 = F_124 () ;
F_10 ( V_186 ) ;
if ( V_91 == V_187 )
return 2 ;
F_3 ( V_188 , V_189 ) ;
F_123 ( V_91 ) ;
return 0 ;
}
if ( sizeof( V_190 ) != sizeof( char ) ) {
* V_183 = F_125 ( ( V_191 * ) V_186 ) ;
F_10 ( V_186 ) ;
if ( * V_183 == NULL )
return 0 ;
} else
* V_183 = ( char * ) V_186 ;
F_11 ( V_6 , L_27 , * V_183 ,
* V_184 ) ;
return 1 ;
}
static int F_6 ( T_2 * V_6 , T_3 * V_7 )
{
T_12 V_185 , V_184 ;
int V_5 ;
T_4 V_192 = NULL ;
F_11 ( V_6 , L_28 ) ;
F_129 ( V_7 , L_29 ) ;
for ( V_185 = 0 ; ; V_185 ++ ) {
V_5 = F_127 ( V_6 , & V_192 , & V_184 , V_185 ) ;
if ( V_5 == 2 )
break;
if ( V_5 == 0 )
break;
F_129 ( V_7 , L_30 , V_185 , V_192 , V_184 ) ;
F_10 ( V_192 ) ;
}
return 1 ;
}
static int F_8 ( T_2 * V_6 , T_3 * V_7 )
{
int V_5 = 1 ;
T_7 V_43 ;
T_12 V_91 , V_185 , V_193 , V_194 = 0 , V_195 ;
T_4 V_196 ;
T_24 V_197 = NULL ;
F_11 ( V_6 , L_31 , V_6 -> V_197 ,
V_6 -> V_38 ) ;
if ( V_6 -> V_197 && sizeof( V_190 ) != sizeof( char ) ) {
if ( ( V_195 =
F_130 ( V_180 , 0 , V_6 -> V_197 , - 1 , NULL , 0 ) ) ) {
V_197 = F_131 ( V_195 * sizeof( V_191 ) ) ;
F_130 ( V_180 , 0 , V_6 -> V_197 , - 1 , ( V_191 * ) V_197 ,
V_195 ) ;
}
if ( ! V_197 ) {
F_3 ( V_198 , V_20 ) ;
F_86 () ;
return 0 ;
}
} else
V_197 = ( V_190 * ) V_6 -> V_197 ;
if ( ! F_51
( & V_43 , NULL , V_197 , V_6 -> V_38 , V_65 ) ) {
F_3 ( V_198 ,
V_199 ) ;
F_86 () ;
return 0 ;
}
if ( ! F_132
( V_43 , V_200 , NULL , & V_194 , V_201 ) ) {
F_3 ( V_198 , V_202 ) ;
F_86 () ;
F_52 ( V_43 , 0 ) ;
return 0 ;
}
F_11 ( V_6 , L_32 , V_194 ) ;
if ( V_194 == 0 )
V_194 = 1024 ;
V_196 = F_87 ( V_194 ) ;
if ( V_196 == NULL ) {
F_3 ( V_198 , V_20 ) ;
goto V_91;
}
for ( V_185 = 0 ; ; V_185 ++ ) {
V_195 = V_194 ;
V_196 [ 0 ] = 0 ;
if ( V_185 == 0 )
V_193 = V_201 ;
else
V_193 = 0 ;
if ( ! F_132
( V_43 , V_200 , ( V_203 * ) V_196 , & V_195 , V_193 ) ) {
V_91 = F_124 () ;
if ( V_91 == V_187 )
goto V_204;
F_3 ( V_198 , V_202 ) ;
F_123 ( V_91 ) ;
goto V_91;
}
F_11 ( V_6 , L_33 ,
V_196 , V_195 , V_185 , V_193 ) ;
if ( ! V_196 [ 0 ] && ( V_195 == V_194 ) ) {
F_11 ( V_6 , L_34 ) ;
goto V_204;
}
F_129 ( V_7 , L_35 , V_185 , V_196 ) ;
}
V_91:
V_5 = 0 ;
V_204:
F_10 ( V_196 ) ;
F_52 ( V_43 , 0 ) ;
return V_5 ;
}
static T_25 * F_133 ( T_2 * V_6 , T_26 V_205 )
{
T_12 V_83 ;
T_25 * V_206 ;
if ( ! F_134
( V_205 , V_207 , NULL , & V_83 ) )
return NULL ;
V_206 = F_87 ( V_83 ) ;
if ( V_206 == NULL ) {
F_3 ( V_208 , V_20 ) ;
return NULL ;
}
if ( ! F_134
( V_205 , V_207 , V_206 , & V_83 ) ) {
F_3 ( V_208 ,
V_209 ) ;
F_86 () ;
F_10 ( V_206 ) ;
return NULL ;
}
return V_206 ;
}
static void F_135 ( T_2 * V_6 , T_3 * V_7 ,
T_25 * V_206 )
{
char * V_192 = NULL , * V_210 = NULL ;
if ( ! V_206 ) {
F_129 ( V_7 , L_36 ) ;
return;
}
V_192 = F_125 ( V_206 -> V_211 ) ;
V_210 = F_125 ( V_206 -> V_212 ) ;
if ( ! V_192 || ! V_210 )
goto V_91;
F_129 ( V_7 , L_37 ) ;
F_129 ( V_7 , L_38 , V_192 ,
V_206 -> V_213 ) ;
F_129 ( V_7 , L_39 , V_210 ,
V_206 -> V_214 ) ;
V_91:
F_10 ( V_192 ) ;
F_10 ( V_210 ) ;
}
static char * F_136 ( T_2 * V_6 , T_26 V_205 )
{
T_27 V_215 ;
T_12 V_158 ;
F_11 ( V_6 , L_40 ) ;
if ( ! F_134
( V_205 , V_216 , NULL , & V_158 ) )
return NULL ;
V_215 = F_87 ( V_158 ) ;
if ( V_215 == NULL )
return NULL ;
if ( F_134
( V_205 , V_216 , V_215 , & V_158 ) ) {
char * V_217 = F_125 ( V_215 ) ;
F_10 ( V_215 ) ;
return V_217 ;
}
F_3 ( V_218 , V_219 ) ;
F_86 () ;
F_10 ( V_215 ) ;
return NULL ;
}
static void F_137 ( T_2 * V_6 , T_3 * V_7 , T_26 V_205 )
{
T_28 * V_220 ;
const unsigned char * V_4 ;
unsigned long V_193 = V_6 -> V_33 ;
if ( V_193 & V_221 ) {
char * V_217 ;
V_217 = F_136 ( V_6 , V_205 ) ;
if ( V_217 ) {
F_129 ( V_7 , L_41 , V_217 ) ;
F_10 ( V_217 ) ;
} else
F_129 ( V_7 , L_42 ) ;
}
V_4 = V_205 -> V_222 ;
V_220 = F_138 ( NULL , & V_4 , V_205 -> V_223 ) ;
if ( ! V_220 )
F_129 ( V_7 , L_43 ) ;
if ( V_193 & V_224 ) {
F_129 ( V_7 , L_44 ) ;
F_139 ( V_7 , F_140 ( V_220 ) , 0 , V_225 ) ;
F_129 ( V_7 , L_45 ) ;
F_139 ( V_7 , F_141 ( V_220 ) , 0 , V_225 ) ;
F_129 ( V_7 , L_46 ) ;
}
if ( V_193 & V_226 )
F_142 ( V_7 , V_220 , V_225 , 0 ) ;
if ( V_193 & V_227 ) {
T_25 * V_206 ;
V_206 = F_133 ( V_6 , V_205 ) ;
F_135 ( V_6 , V_7 , V_206 ) ;
F_10 ( V_206 ) ;
}
if ( V_193 & V_228 )
F_143 ( V_7 , V_220 ) ;
F_144 ( V_220 ) ;
}
static T_29 F_145 ( T_2 * V_6 , char * V_19 )
{
T_29 V_229 ;
if ( ! V_19 )
V_19 = V_6 -> V_19 ;
if ( ! V_19 )
V_19 = L_47 ;
F_11 ( V_6 , L_48 , V_19 ) ;
V_229 = F_146 ( V_230 , 0 , 0 ,
V_6 -> V_22 , V_19 ) ;
if ( ! V_229 ) {
F_3 ( V_231 , V_232 ) ;
F_86 () ;
}
return V_229 ;
}
int F_7 ( T_2 * V_6 , T_3 * V_7 , char * V_74 )
{
char * V_19 ;
int V_185 ;
int V_5 = 1 ;
T_29 V_229 ;
T_26 V_205 = NULL ;
V_19 = V_6 -> V_19 ;
if ( ! V_19 )
V_19 = L_47 ;
F_11 ( V_6 , L_49 , V_19 ) ;
V_229 = F_145 ( V_6 , V_19 ) ;
if ( ! V_229 )
return 0 ;
if ( V_74 ) {
V_205 = F_147 ( V_6 , V_74 , V_229 ) ;
if ( ! V_205 ) {
V_5 = 0 ;
goto V_91;
}
F_137 ( V_6 , V_7 , V_205 ) ;
F_148 ( V_205 ) ;
} else {
for ( V_185 = 0 ; ; V_185 ++ ) {
V_205 = F_149 ( V_229 , V_205 ) ;
if ( ! V_205 )
break;
F_129 ( V_7 , L_50 , V_185 ) ;
F_137 ( V_6 , V_7 , V_205 ) ;
}
}
V_91:
F_150 ( V_229 , 0 ) ;
return V_5 ;
}
static T_26 F_147 ( T_2 * V_6 , const char * V_74 ,
T_29 V_229 )
{
T_26 V_205 = NULL ;
char * V_217 = NULL ;
int V_233 ;
switch ( V_6 -> V_36 ) {
case V_234 :
return F_151 ( V_229 ,
V_235 , 0 ,
V_236 , V_74 , NULL ) ;
case V_237 :
for (; ; ) {
V_205 = F_149 ( V_229 , V_205 ) ;
if ( ! V_205 )
return NULL ;
V_217 = F_136 ( V_6 , V_205 ) ;
if ( V_217 ) {
if ( strcmp ( V_217 , V_74 ) )
V_233 = 0 ;
else
V_233 = 1 ;
F_10 ( V_217 ) ;
if ( V_233 )
return V_205 ;
}
}
default:
return NULL ;
}
}
static T_11 * F_152 ( T_2 * V_6 , const V_190 * V_210 ,
V_190 * V_192 , T_12 V_184 , T_12 V_155 )
{
T_12 V_238 = 0 ;
T_11 * V_81 = F_87 ( sizeof( * V_81 ) ) ;
if ( V_81 == NULL )
return NULL ;
if ( V_184 == V_239 && V_66 ) {
V_192 = NULL ;
V_184 = V_64 ;
F_11 ( V_6 , L_51 , V_210 ) ;
} else if ( sizeof( V_190 ) == sizeof( char ) ) {
F_11 ( V_6 , L_52 ,
V_210 , V_192 , V_184 ) ;
} else if ( V_6 && V_6 -> V_26 >= V_175 && V_6 -> V_28 ) {
char * V_240 = F_125 ( ( V_191 * ) V_210 ) ;
char * V_241 = F_125 ( ( V_191 * ) V_192 ) ;
F_11 ( V_6 , L_52 ,
V_240 , V_241 , V_184 ) ;
F_10 ( V_241 ) ;
F_10 ( V_240 ) ;
}
if ( V_6 -> V_22 & V_23 )
V_238 = V_242 ;
if ( ! F_51 ( & V_81 -> V_43 , V_210 , V_192 , V_184 , V_238 ) ) {
F_3 ( V_243 , V_199 ) ;
F_86 () ;
goto V_91;
}
if ( ! F_153 ( V_81 -> V_43 , V_155 , & V_81 -> V_81 ) ) {
F_3 ( V_243 , V_244 ) ;
F_86 () ;
F_52 ( V_81 -> V_43 , 0 ) ;
goto V_91;
}
V_81 -> V_155 = V_155 ;
V_81 -> V_245 = NULL ;
return V_81 ;
V_91:
F_10 ( V_81 ) ;
return NULL ;
}
static T_11 * F_154 ( T_2 * V_6 , T_26 V_205 )
{
T_11 * V_81 = NULL ;
T_25 * V_206 = NULL ;
char * V_192 = NULL , * V_210 = NULL ;
V_206 = F_133 ( V_6 , V_205 ) ;
if ( ! V_206 )
goto V_91;
if ( sizeof( V_190 ) != sizeof( char ) )
V_81 = F_152 ( V_6 , ( V_190 * ) V_206 -> V_212 ,
( V_190 * ) V_206 -> V_211 ,
V_206 -> V_213 , V_206 -> V_214 ) ;
else {
V_192 = F_125 ( V_206 -> V_211 ) ;
V_210 = F_125 ( V_206 -> V_212 ) ;
if ( ! V_192 || ! V_210 )
goto V_91;
V_81 = F_152 ( V_6 , ( V_190 * ) V_210 , ( V_190 * ) V_192 ,
V_206 -> V_213 , V_206 -> V_214 ) ;
}
V_91:
F_10 ( V_206 ) ;
F_10 ( V_192 ) ;
F_10 ( V_210 ) ;
return V_81 ;
}
T_11 * F_105 ( T_2 * V_6 , const char * V_74 )
{
T_26 V_205 ;
T_29 V_229 ;
T_11 * V_81 = NULL ;
switch ( V_6 -> V_36 ) {
case V_234 :
case V_237 :
V_229 = F_145 ( V_6 , NULL ) ;
if ( ! V_229 )
return NULL ;
V_205 = F_147 ( V_6 , V_74 , V_229 ) ;
if ( V_205 ) {
V_81 = F_154 ( V_6 , V_205 ) ;
F_148 ( V_205 ) ;
}
F_150 ( V_229 , 0 ) ;
break;
case V_246 :
if ( sizeof( V_190 ) != sizeof( char ) ) {
V_191 * V_210 , * V_192 ;
T_12 V_83 ;
if ( ( V_83 = F_130 ( V_180 , 0 , V_74 , - 1 , NULL , 0 ) ) &&
( V_210 = F_131 ( V_83 * sizeof( V_191 ) ) ,
F_130 ( V_180 , 0 , V_74 , - 1 , V_210 , V_83 ) ) &&
( V_83 =
F_130 ( V_180 , 0 , V_6 -> V_197 , - 1 , NULL , 0 ) )
&& ( V_192 =
F_131 ( V_83 * sizeof( V_191 ) ) , F_130 ( V_180 ,
0 ,
V_6 -> V_197 ,
- 1 ,
V_192 ,
V_83 ) ) )
V_81 =
F_152 ( V_6 , ( V_190 * ) V_210 , ( V_190 * ) V_192 ,
V_6 -> V_38 , V_6 -> V_30 ) ;
} else
V_81 = F_152 ( V_6 , ( V_190 * ) V_74 ,
( V_190 * ) V_6 -> V_197 ,
V_6 -> V_38 , V_6 -> V_30 ) ;
break;
}
return V_81 ;
}
void F_106 ( T_11 * V_81 )
{
if ( ! V_81 )
return;
F_155 ( V_81 -> V_81 ) ;
F_52 ( V_81 -> V_43 , 0 ) ;
if ( V_81 -> V_245 )
F_148 ( V_81 -> V_245 ) ;
F_10 ( V_81 ) ;
}
static T_2 * F_43 ( void )
{
T_2 * V_6 = F_156 ( sizeof( * V_6 ) ) ;
if ( V_6 == NULL ) {
F_3 ( V_247 , V_20 ) ;
return NULL ;
}
V_6 -> V_38 = V_239 ;
V_6 -> V_33 = V_224 | V_221 ;
V_6 -> V_30 = V_248 ;
V_6 -> V_22 = V_249 |
V_250 | V_24 ;
V_6 -> V_36 = V_234 ;
V_6 -> V_62 = V_251 ;
return V_6 ;
}
static void F_58 ( T_2 * V_6 )
{
F_11 ( V_6 , L_53 , V_6 ) ;
if ( ! V_6 )
return;
F_10 ( V_6 -> V_197 ) ;
F_10 ( V_6 -> V_28 ) ;
F_10 ( V_6 -> V_19 ) ;
F_10 ( V_6 -> V_252 ) ;
F_10 ( V_6 ) ;
}
static int F_14 ( T_2 * V_6 , T_4 V_183 , T_12 type ,
int V_253 )
{
T_4 V_254 ;
F_11 ( V_6 , L_54 , V_183 , type ) ;
if ( V_253 ) {
T_7 V_43 ;
T_24 V_186 = NULL ;
if ( sizeof( V_190 ) != sizeof( char ) ) {
T_12 V_83 ;
if ( ( V_83 = F_130 ( V_180 , 0 , V_183 , - 1 , NULL , 0 ) ) ) {
V_186 = F_131 ( V_83 * sizeof( V_191 ) ) ;
F_130 ( V_180 , 0 , V_183 , - 1 , ( V_191 * ) V_186 , V_83 ) ;
}
} else
V_186 = ( V_190 * ) V_183 ;
if ( ! V_186 || ! F_51 ( & V_43 , NULL , V_186 , type ,
V_65 ) ) {
F_3 ( V_255 ,
V_199 ) ;
F_86 () ;
return 0 ;
}
F_52 ( V_43 , 0 ) ;
}
V_254 = F_9 ( V_183 ) ;
if ( V_254 == NULL ) {
F_3 ( V_255 , V_20 ) ;
return 0 ;
}
F_10 ( V_6 -> V_197 ) ;
V_6 -> V_197 = V_254 ;
V_6 -> V_38 = type ;
return 1 ;
}
static int F_12 ( T_2 * V_6 , int V_185 )
{
T_4 V_183 ;
T_12 type ;
int V_256 ;
if ( F_127 ( V_6 , & V_183 , & type , V_185 ) != 1 )
return 0 ;
V_256 = F_14 ( V_6 , V_183 , type , 0 ) ;
F_10 ( V_183 ) ;
return V_256 ;
}
T_30
int F_157 ( T_1 * V_1 , const char * V_74 , const T_31 * V_257 )
{
return 0 ;
}
void F_79 ( void )
{
}
