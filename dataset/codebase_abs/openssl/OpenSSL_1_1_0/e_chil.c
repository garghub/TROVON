static int F_1 ( T_1 * V_1 )
{
# ifndef F_2
const T_2 * V_2 ;
# endif
# ifndef F_3
const T_3 * V_3 ;
# endif
V_4 = F_4 () ;
if ( V_4 == NULL ) {
F_5 ( V_5 , V_6 ) ;
return 0 ;
}
if ( ! F_6 ( V_1 , V_7 ) ||
! F_7 ( V_1 , V_8 ) ||
# ifndef F_2
! F_8 ( V_1 , & V_9 ) ||
# endif
# ifndef F_3
! F_9 ( V_1 , & V_10 ) ||
# endif
! F_10 ( V_1 , & V_11 ) ||
! F_11 ( V_1 , V_12 ) ||
! F_12 ( V_1 , V_13 ) ||
! F_13 ( V_1 , V_14 ) ||
! F_14 ( V_1 , V_15 ) ||
! F_15 ( V_1 , V_16 ) ||
! F_16 ( V_1 , V_17 ) ||
! F_17 ( V_1 , V_18 ) )
return 0 ;
# ifndef F_2
V_2 = F_18 () ;
V_9 . V_19 = V_2 -> V_19 ;
V_9 . V_20 = V_2 -> V_20 ;
V_9 . V_21 = V_2 -> V_21 ;
V_9 . V_22 = V_2 -> V_22 ;
# endif
# ifndef F_3
V_3 = F_19 () ;
V_10 . V_23 = V_3 -> V_23 ;
V_10 . V_24 = V_3 -> V_24 ;
# endif
F_20 () ;
return 1 ;
}
static T_1 * F_21 ( void )
{
T_1 * V_25 = F_22 () ;
if ( V_25 == NULL )
return NULL ;
if ( ! F_1 ( V_25 ) ) {
F_23 ( V_25 ) ;
return NULL ;
}
return V_25 ;
}
void F_24 ( void )
{
T_1 * V_26 = F_21 () ;
if ( ! V_26 )
return;
F_25 ( V_26 ) ;
F_23 ( V_26 ) ;
F_26 () ;
}
static void F_27 ( void )
{
F_28 ( V_27 ) ;
V_27 = NULL ;
}
static const char * F_29 ( void )
{
if ( V_27 )
return V_27 ;
return L_1 ;
}
static long F_30 ( const char * V_28 )
{
F_27 () ;
return ( ( ( V_27 = F_31 ( V_28 ) ) != NULL ) ? 1 : 0 ) ;
}
static int F_32 ( T_4 * V_29 ,
T_5 * V_30 )
{
char V_31 [ 1024 ] ;
T_6 V_32 ;
V_32 . V_33 = V_31 ;
V_32 . V_34 = sizeof( V_31 ) ;
* V_29 = F_33 ( & V_35 , sizeof( V_35 ) , & V_32 , V_30 ) ;
if ( ! * V_29 )
return 0 ;
return 1 ;
}
static void F_34 ( T_4 V_29 )
{
F_35 ( V_29 ) ;
}
static int V_12 ( T_1 * V_1 )
{
F_27 () ;
F_36 () ;
F_37 ( V_4 ) ;
return 1 ;
}
static int V_13 ( T_1 * V_1 )
{
T_7 * V_36 ;
T_8 * V_37 ;
T_9 * V_38 ;
# ifndef F_2
T_10 * V_39 ;
T_11 * V_40 ;
T_12 * V_41 ;
T_13 * V_42 ;
# endif
T_14 * V_43 ;
T_15 * V_44 ;
if ( V_45 != NULL ) {
F_5 ( V_46 , V_47 ) ;
goto V_48;
}
V_45 = F_38 ( NULL , F_29 () , NULL , 0 ) ;
if ( V_45 == NULL ) {
F_5 ( V_46 , V_49 ) ;
goto V_48;
}
#define F_39 ( T_16 , V_28 ) (t *)DSO_bind_func(hwcrhk_dso, name)
if ( ( V_36 = F_39 ( T_7 , V_50 ) ) == NULL
|| ( V_37 = F_39 ( T_8 , V_51 ) ) == NULL
|| ( V_38 = F_39 ( T_9 , V_52 ) ) == NULL
# ifndef F_2
|| ( V_39 = F_39 ( T_10 , V_53 ) ) == NULL
|| ( V_40 = F_39 ( T_11 , V_54 ) ) == NULL
|| ( V_41 = F_39 ( T_12 , V_55 ) ) == NULL
|| ( V_42 = F_39 ( T_13 , V_56 ) ) == NULL
# endif
|| ( V_43 = F_39 ( T_14 , V_57 ) ) == NULL
|| ( V_44 = F_39 ( T_15 , V_58 ) ) == NULL ) {
F_5 ( V_46 , V_49 ) ;
goto V_48;
}
F_33 = V_36 ;
F_35 = V_37 ;
V_59 = V_38 ;
# ifndef F_2
V_60 = V_39 ;
V_61 = V_40 ;
V_62 = V_41 ;
V_63 = V_42 ;
# endif
V_64 = V_43 ;
V_65 = V_44 ;
if ( V_66 == 0 ) {
V_35 . V_67 = V_68 ;
V_35 . V_69 = V_70 ;
V_35 . V_71 = V_72 ;
V_35 . V_73 = V_74 ;
}
if ( ! F_32 ( & V_75 , & V_76 ) ) {
F_5 ( V_46 , V_77 ) ;
goto V_48;
}
# ifndef F_2
if ( V_78 == - 1 )
V_78 = F_40 ( 0 ,
L_2 ,
NULL , NULL , NULL ) ;
# endif
return 1 ;
V_48:
F_41 ( V_45 ) ;
V_45 = NULL ;
F_33 = NULL ;
F_35 = NULL ;
V_59 = NULL ;
# ifndef F_2
V_60 = NULL ;
V_61 = NULL ;
V_62 = NULL ;
V_63 = NULL ;
# endif
V_65 = NULL ;
V_64 = NULL ;
return 0 ;
}
static int V_14 ( T_1 * V_1 )
{
int V_79 = 1 ;
F_27 () ;
if ( V_45 == NULL ) {
F_5 ( V_80 , V_81 ) ;
V_79 = 0 ;
goto V_48;
}
F_34 ( V_75 ) ;
if ( ! F_41 ( V_45 ) ) {
F_5 ( V_80 , V_49 ) ;
V_79 = 0 ;
goto V_48;
}
V_48:
F_42 ( V_82 ) ;
V_45 = NULL ;
F_33 = NULL ;
F_35 = NULL ;
V_59 = NULL ;
# ifndef F_2
V_60 = NULL ;
V_61 = NULL ;
V_62 = NULL ;
V_63 = NULL ;
# endif
V_65 = NULL ;
V_64 = NULL ;
return V_79 ;
}
static int V_15 ( T_1 * V_1 , int V_83 , long V_84 , void * V_85 , void (* F_43) ( void ) )
{
int V_79 = 1 ;
switch ( V_83 ) {
case V_86 :
if ( V_45 ) {
F_5 ( V_87 , V_47 ) ;
return 0 ;
}
if ( V_85 == NULL ) {
F_5 ( V_87 , V_88 ) ;
return 0 ;
}
return F_30 ( ( const char * ) V_85 ) ;
case V_89 :
{
T_17 * V_90 = ( T_17 * ) V_85 ;
F_44 ( V_4 ) ;
F_42 ( V_82 ) ;
V_82 = NULL ;
if ( F_45 ( V_90 ) )
V_82 = V_90 ;
else
F_5 ( V_87 , V_91 ) ;
}
F_46 ( V_4 ) ;
break;
case V_92 :
F_44 ( V_4 ) ;
V_76 . V_93 = ( V_94 * ) F_43 ;
F_46 ( V_4 ) ;
break;
case V_95 :
case V_96 :
F_44 ( V_4 ) ;
V_76 . V_97 = ( V_98 * ) V_85 ;
F_46 ( V_4 ) ;
break;
case V_99 :
case V_100 :
F_44 ( V_4 ) ;
V_76 . V_101 = V_85 ;
F_46 ( V_4 ) ;
break;
case V_102 :
case V_103 :
F_44 ( V_4 ) ;
if ( V_84 )
V_35 . V_104 |= V_105 ;
else
V_35 . V_104 &= ~ V_105 ;
F_46 ( V_4 ) ;
break;
case V_106 :
F_44 ( V_4 ) ;
V_66 = 1 ;
F_46 ( V_4 ) ;
break;
case V_107 :
F_44 ( V_4 ) ;
V_66 = ( ( V_84 == 0 ) ? 0 : 1 ) ;
F_46 ( V_4 ) ;
break;
default:
F_5 ( V_87 ,
V_108 ) ;
V_79 = 0 ;
break;
}
return V_79 ;
}
static T_18 * V_16 ( T_1 * V_109 , const char * V_110 ,
V_98 * V_97 ,
void * V_101 )
{
# ifndef F_2
T_19 * V_111 = NULL ;
# endif
T_18 * V_112 = NULL ;
# ifndef F_2
T_20 V_1 , V_113 ;
T_21 * V_114 ;
# endif
# if ! F_47 ( F_2 )
char V_31 [ 1024 ] ;
T_6 V_32 ;
T_22 V_115 ;
# endif
# if ! F_47 ( F_2 )
V_32 . V_33 = V_31 ;
V_32 . V_34 = sizeof( V_31 ) ;
# endif
if ( ! V_75 ) {
F_5 ( V_116 , V_117 ) ;
goto V_48;
}
# ifndef F_2
V_114 = F_48 ( sizeof( * V_114 ) ) ;
if ( V_114 == NULL ) {
F_5 ( V_116 , V_6 ) ;
goto V_48;
}
V_115 . V_97 = V_97 ;
V_115 . V_101 = V_101 ;
if ( V_61 ( V_75 , V_110 , V_114 , & V_32 , & V_115 ) ) {
F_5 ( V_116 , V_118 ) ;
F_49 ( 1 , V_32 . V_33 ) ;
goto V_48;
}
if ( ! * V_114 ) {
F_5 ( V_116 , V_119 ) ;
goto V_48;
}
# endif
# ifndef F_2
V_111 = F_50 ( V_109 ) ;
F_51 ( V_111 , V_78 , ( char * ) V_114 ) ;
V_111 -> V_1 = F_52 () ;
V_111 -> V_113 = F_52 () ;
V_111 -> V_104 |= V_120 ;
F_53 ( V_111 -> V_1 , V_1 ) ;
F_53 ( V_111 -> V_113 , V_113 ) ;
if ( V_62 ( * V_114 , & V_113 , & V_1 , & V_32 )
!= V_121 ) {
F_5 ( V_116 , V_118 ) ;
F_49 ( 1 , V_32 . V_33 ) ;
goto V_48;
}
F_54 ( V_111 -> V_1 , V_1 . V_34 / sizeof( V_122 ) ) ;
F_54 ( V_111 -> V_113 , V_113 . V_34 / sizeof( V_122 ) ) ;
F_53 ( V_111 -> V_1 , V_1 ) ;
F_53 ( V_111 -> V_113 , V_113 ) ;
if ( V_62 ( * V_114 , & V_113 , & V_1 , & V_32 ) ) {
F_5 ( V_116 , V_118 ) ;
F_49 ( 1 , V_32 . V_33 ) ;
goto V_48;
}
V_111 -> V_1 -> V_123 = V_1 . V_34 / sizeof( V_122 ) ;
F_55 ( V_111 -> V_1 ) ;
V_111 -> V_113 -> V_123 = V_113 . V_34 / sizeof( V_122 ) ;
F_55 ( V_111 -> V_113 ) ;
V_112 = F_56 () ;
if ( V_112 == NULL ) {
F_5 ( V_116 , V_118 ) ;
goto V_48;
}
F_57 ( V_112 , V_111 ) ;
# endif
if ( V_112 == NULL )
F_5 ( V_116 ,
V_124 ) ;
return V_112 ;
V_48:
# ifndef F_2
F_58 ( V_111 ) ;
# endif
return NULL ;
}
static T_18 * V_17 ( T_1 * V_109 , const char * V_110 ,
V_98 * V_97 , void * V_101 )
{
T_18 * V_112 = NULL ;
# ifndef F_2
V_112 = V_16 ( V_109 , V_110 , V_97 , V_101 ) ;
# endif
if ( V_112 )
switch ( V_112 -> type ) {
# ifndef F_2
case V_125 :
{
T_19 * V_126 = NULL ;
F_44 ( V_4 ) ;
V_126 = V_112 -> V_127 . V_126 ;
V_112 -> V_127 . V_126 = F_59 () ;
V_112 -> V_127 . V_126 -> V_113 = V_126 -> V_113 ;
V_112 -> V_127 . V_126 -> V_1 = V_126 -> V_1 ;
V_126 -> V_113 = NULL ;
V_126 -> V_1 = NULL ;
F_46 ( V_4 ) ;
F_58 ( V_126 ) ;
}
break;
# endif
default:
F_5 ( V_128 ,
V_108 ) ;
goto V_48;
}
return V_112 ;
V_48:
F_60 ( V_112 ) ;
return NULL ;
}
static int F_61 ( T_23 * V_129 , const T_23 * V_130 , const T_23 * V_85 ,
const T_23 * V_131 , T_24 * V_132 )
{
char V_31 [ 1024 ] ;
T_6 V_32 ;
T_20 V_133 , V_134 , V_135 , V_136 ;
int V_79 , V_25 ;
V_79 = 0 ;
V_32 . V_33 = V_31 ;
V_32 . V_34 = sizeof( V_31 ) ;
if ( ! V_75 ) {
F_5 ( V_137 , V_117 ) ;
goto V_48;
}
F_54 ( V_129 , V_131 -> V_123 ) ;
F_62 ( V_133 , V_130 ) ;
F_62 ( V_134 , V_85 ) ;
F_62 ( V_135 , V_131 ) ;
F_53 ( V_129 , V_136 ) ;
V_25 = V_59 ( V_75 , V_133 , V_134 , V_135 , & V_136 , & V_32 ) ;
V_129 -> V_123 = V_136 . V_34 / sizeof( V_122 ) ;
F_55 ( V_129 ) ;
if ( V_25 < 0 ) {
if ( V_25 == V_138 ) {
F_5 ( V_137 , V_139 ) ;
} else {
F_5 ( V_137 , V_140 ) ;
}
F_49 ( 1 , V_32 . V_33 ) ;
goto V_48;
}
V_79 = 1 ;
V_48:
return V_79 ;
}
static int F_63 ( T_23 * V_129 , const T_23 * V_141 , T_19 * V_126 ,
T_24 * V_132 )
{
char V_31 [ 1024 ] ;
T_6 V_32 ;
T_21 * V_114 ;
int V_79 = 0 , V_25 ;
V_32 . V_33 = V_31 ;
V_32 . V_34 = sizeof( V_31 ) ;
if ( ! V_75 ) {
F_5 ( V_142 , V_117 ) ;
goto V_48;
}
if ( ( V_114 =
( T_21 * ) F_64 ( V_126 , V_78 ) )
!= NULL ) {
T_20 V_133 , V_136 ;
if ( ! V_126 -> V_113 ) {
F_5 ( V_142 ,
V_143 ) ;
goto V_48;
}
F_54 ( V_129 , V_126 -> V_113 -> V_123 ) ;
F_62 ( V_133 , V_141 ) ;
F_53 ( V_129 , V_136 ) ;
V_25 = V_60 ( V_133 , * V_114 , & V_136 , & V_32 ) ;
V_129 -> V_123 = V_136 . V_34 / sizeof( V_122 ) ;
F_55 ( V_129 ) ;
if ( V_25 < 0 ) {
if ( V_25 == V_138 ) {
F_5 ( V_142 ,
V_139 ) ;
} else {
F_5 ( V_142 ,
V_140 ) ;
}
F_49 ( 1 , V_32 . V_33 ) ;
goto V_48;
}
} else {
T_20 V_133 , V_134 , V_144 , V_145 , V_146 , V_147 , V_136 ;
if ( ! V_126 -> V_85 || ! V_126 -> V_148 || ! V_126 -> V_149 || ! V_126 -> V_150 || ! V_126 -> V_151 ) {
F_5 ( V_142 ,
V_143 ) ;
goto V_48;
}
F_54 ( V_129 , V_126 -> V_113 -> V_123 ) ;
F_62 ( V_133 , V_141 ) ;
F_62 ( V_134 , V_126 -> V_85 ) ;
F_62 ( V_144 , V_126 -> V_148 ) ;
F_62 ( V_145 , V_126 -> V_149 ) ;
F_62 ( V_146 , V_126 -> V_150 ) ;
F_62 ( V_147 , V_126 -> V_151 ) ;
F_53 ( V_129 , V_136 ) ;
V_25 = V_65 ( V_75 , V_133 , V_134 , V_144 ,
V_145 , V_146 , V_147 , & V_136 , & V_32 ) ;
V_129 -> V_123 = V_136 . V_34 / sizeof( V_122 ) ;
F_55 ( V_129 ) ;
if ( V_25 < 0 ) {
if ( V_25 == V_138 ) {
F_5 ( V_142 ,
V_139 ) ;
} else {
F_5 ( V_142 ,
V_140 ) ;
}
F_49 ( 1 , V_32 . V_33 ) ;
goto V_48;
}
}
V_79 = 1 ;
V_48:
return V_79 ;
}
static int F_65 ( T_23 * V_129 , const T_23 * V_130 , const T_23 * V_85 ,
const T_23 * V_131 , T_24 * V_132 ,
T_25 * V_152 )
{
return F_61 ( V_129 , V_130 , V_85 , V_131 , V_132 ) ;
}
static int F_66 ( T_19 * V_126 )
{
T_21 * V_114 ;
V_114 = F_64 ( V_126 , V_78 ) ;
if ( V_114 ) {
V_63 ( * V_114 , NULL ) ;
F_28 ( V_114 ) ;
F_51 ( V_126 , V_78 , NULL ) ;
}
return 1 ;
}
static int F_67 ( const T_26 * V_153 , T_23 * V_129 ,
const T_23 * V_130 , const T_23 * V_85 ,
const T_23 * V_131 , T_24 * V_132 , T_25 * V_152 )
{
return F_61 ( V_129 , V_130 , V_85 , V_131 , V_132 ) ;
}
static int F_68 ( unsigned char * V_33 , int V_154 )
{
char V_31 [ 1024 ] ;
T_6 V_32 ;
int V_79 = 0 ;
int V_25 ;
V_32 . V_33 = V_31 ;
V_32 . V_34 = sizeof( V_31 ) ;
if ( ! V_75 ) {
F_5 ( V_155 , V_117 ) ;
goto V_48;
}
V_25 = V_64 ( V_75 , V_33 , V_154 , & V_32 ) ;
if ( V_25 < 0 ) {
if ( V_25 == V_138 ) {
F_5 ( V_155 , V_139 ) ;
} else {
F_5 ( V_155 , V_140 ) ;
}
F_49 ( 1 , V_32 . V_33 ) ;
goto V_48;
}
V_79 = 1 ;
V_48:
return V_79 ;
}
static int F_69 ( void )
{
return 1 ;
}
static int V_68 ( T_27 * V_156 ,
T_5 * V_157 )
{
V_156 -> V_158 = F_4 () ;
if ( V_156 -> V_158 == NULL ) {
F_5 ( V_159 , V_6 ) ;
return 1 ;
}
return 0 ;
}
static int V_70 ( T_27 * V_156 )
{
F_44 ( V_156 -> V_158 ) ;
return 0 ;
}
static void V_72 ( T_27 * V_156 )
{
F_46 ( V_156 -> V_158 ) ;
}
static void V_74 ( T_27 * V_156 )
{
F_37 ( V_156 -> V_158 ) ;
}
static int F_70 ( const char * V_160 ,
int * V_161 , char * V_33 ,
T_22 * V_115 ,
T_5 * V_157 )
{
V_94 * V_162 = NULL ;
void * V_101 = NULL ;
V_98 * V_97 = NULL ;
if ( V_160 && ! * V_160 )
V_160 = NULL ;
if ( V_157 ) {
if ( V_157 -> V_97 )
V_97 = V_157 -> V_97 ;
if ( V_157 -> V_93 )
V_162 = V_157 -> V_93 ;
if ( V_157 -> V_101 )
V_101 = V_157 -> V_101 ;
}
if ( V_115 ) {
if ( V_115 -> V_97 ) {
V_97 = V_115 -> V_97 ;
V_162 = NULL ;
}
if ( V_115 -> V_101 )
V_101 = V_115 -> V_101 ;
}
if ( V_162 == NULL && V_97 == NULL ) {
F_5 ( V_163 , V_164 ) ;
return - 1 ;
}
if ( V_97 ) {
T_28 * V_165 = F_71 ( V_97 ) ;
if ( V_165 ) {
int V_166 ;
char * V_167 = F_72 ( V_165 ,
L_3 , V_160 ) ;
V_166 = F_73 ( V_165 , V_167 ,
V_168 ,
V_33 , 0 , ( * V_161 ) - 1 ) ;
F_74 ( V_165 , V_101 ) ;
F_75 ( V_165 , V_169 , 1 , 0 , 0 ) ;
if ( V_166 >= 0 )
do {
V_166 = F_76 ( V_165 ) ;
}
while ( V_166 < 0 && F_75 ( V_165 , V_170 , 0 , 0 , 0 ) );
if ( V_166 >= 0 )
* V_161 = strlen ( V_33 ) ;
F_77 ( V_165 ) ;
F_28 ( V_167 ) ;
}
} else {
* V_161 = V_162 ( V_33 , * V_161 , 0 , V_101 ) ;
}
if ( ! * V_161 )
return - 1 ;
return 0 ;
}
static int F_78 ( const char * V_160 ,
const char * V_171 ,
T_22 * V_115 ,
T_5 * V_157 )
{
int V_166 = - 1 ;
T_28 * V_165 ;
void * V_101 = NULL ;
V_98 * V_97 = NULL ;
if ( V_157 ) {
if ( V_157 -> V_97 )
V_97 = V_157 -> V_97 ;
if ( V_157 -> V_101 )
V_101 = V_157 -> V_101 ;
}
if ( V_115 ) {
if ( V_115 -> V_97 )
V_97 = V_115 -> V_97 ;
if ( V_115 -> V_101 )
V_101 = V_115 -> V_101 ;
}
if ( V_97 == NULL ) {
F_5 ( V_172 , V_164 ) ;
return - 1 ;
}
V_165 = F_71 ( V_97 ) ;
if ( V_165 ) {
char V_173 = '\0' ;
char V_33 [ V_174 ] ;
if ( V_171 && * V_171 )
F_79 ( V_33 , sizeof( V_33 ) - 1 ,
L_4 , V_171 ) ;
else
V_33 [ 0 ] = 0 ;
V_166 = F_80 ( V_165 , V_33 ) ;
if ( V_166 >= 0 && V_160 ) {
F_79 ( V_33 , sizeof( V_33 ) - 1 ,
L_5 , V_160 ) ;
V_166 = F_81 ( V_165 , V_33 ,
L_6 ,
L_7 , L_8 , V_175 ,
& V_173 ) ;
}
F_74 ( V_165 , V_101 ) ;
if ( V_166 >= 0 )
V_166 = F_76 ( V_165 ) ;
F_77 ( V_165 ) ;
if ( V_166 == - 2 || ( V_166 >= 0 && V_173 == 'C' ) )
V_166 = 1 ;
else if ( V_166 < 0 )
V_166 = - 1 ;
else
V_166 = 0 ;
}
return V_166 ;
}
static void F_82 ( void * V_176 , const char * V_177 )
{
T_17 * V_178 = NULL ;
if ( V_176 )
V_178 = * ( T_17 * * ) V_176 ;
if ( V_178 ) {
F_83 ( V_178 , L_9 , V_177 ) ;
}
}
static int F_84 ( T_1 * V_1 , const char * V_179 )
{
if ( V_179 && ( strcmp ( V_179 , V_7 ) != 0 ) &&
( strcmp ( V_179 , V_180 ) != 0 ) )
return 0 ;
if ( ! F_1 ( V_1 ) )
return 0 ;
return 1 ;
}
