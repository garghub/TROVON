static int F_1 ( T_1 * V_1 )
{
# ifndef F_2
const T_2 * V_2 ;
# endif
# ifndef F_3
const T_3 * V_3 ;
# endif
if ( ! F_4 ( V_1 , V_4 ) ||
! F_5 ( V_1 , V_5 ) ||
# ifndef F_2
! F_6 ( V_1 , & V_6 ) ||
# endif
# ifndef F_3
! F_7 ( V_1 , & V_7 ) ||
# endif
! F_8 ( V_1 , & V_8 ) ||
! F_9 ( V_1 , V_9 ) ||
! F_10 ( V_1 , V_10 ) ||
! F_11 ( V_1 , V_11 ) ||
! F_12 ( V_1 , V_12 ) ||
! F_13 ( V_1 , V_13 ) ||
! F_14 ( V_1 , V_14 ) ||
! F_15 ( V_1 , V_15 ) )
return 0 ;
# ifndef F_2
V_2 = F_16 () ;
V_6 . V_16 = V_2 -> V_16 ;
V_6 . V_17 = V_2 -> V_17 ;
V_6 . V_18 = V_2 -> V_18 ;
V_6 . V_19 = V_2 -> V_19 ;
# endif
# ifndef F_3
V_3 = F_17 () ;
V_7 . V_20 = V_3 -> V_20 ;
V_7 . V_21 = V_3 -> V_21 ;
# endif
F_18 () ;
return 1 ;
}
static T_1 * F_19 ( void )
{
T_1 * V_22 = F_20 () ;
if ( ! V_22 )
return NULL ;
if ( ! F_1 ( V_22 ) ) {
F_21 ( V_22 ) ;
return NULL ;
}
return V_22 ;
}
void F_22 ( void )
{
T_1 * V_23 = F_19 () ;
if ( ! V_23 )
return;
F_23 ( V_23 ) ;
F_21 ( V_23 ) ;
F_24 () ;
}
static void F_25 ( void )
{
if ( V_24 )
F_26 ( ( void * ) V_24 ) ;
V_24 = NULL ;
}
static const char * F_27 ( void )
{
if ( V_24 )
return V_24 ;
return L_1 ;
}
static long F_28 ( const char * V_25 )
{
F_25 () ;
return ( ( ( V_24 = F_29 ( V_25 ) ) != NULL ) ? 1 : 0 ) ;
}
static int F_30 ( T_4 * V_26 ,
T_5 * V_27 )
{
char V_28 [ 1024 ] ;
T_6 V_29 ;
V_29 . V_30 = V_28 ;
V_29 . V_31 = sizeof( V_28 ) ;
* V_26 = F_31 ( & V_32 , sizeof( V_32 ) , & V_29 , V_27 ) ;
if ( ! * V_26 )
return 0 ;
return 1 ;
}
static void F_32 ( T_4 V_26 )
{
F_33 ( V_26 ) ;
}
static int V_9 ( T_1 * V_1 )
{
F_25 () ;
F_34 () ;
return 1 ;
}
static int V_10 ( T_1 * V_1 )
{
T_7 * V_33 ;
T_8 * V_34 ;
T_9 * V_35 ;
# ifndef F_2
T_10 * V_36 ;
T_11 * V_37 ;
T_12 * V_38 ;
T_13 * V_39 ;
# endif
T_14 * V_40 ;
T_15 * V_41 ;
if ( V_42 != NULL ) {
F_35 ( V_43 , V_44 ) ;
goto V_45;
}
V_42 = F_36 ( NULL , F_27 () , NULL , 0 ) ;
if ( V_42 == NULL ) {
F_35 ( V_43 , V_46 ) ;
goto V_45;
}
if ( ! ( V_33 = ( T_7 * )
F_37 ( V_42 , V_47 ) ) ||
! ( V_34 = ( T_8 * )
F_37 ( V_42 , V_48 ) ) ||
! ( V_35 = ( T_9 * )
F_37 ( V_42 , V_49 ) ) ||
# ifndef F_2
! ( V_36 = ( T_10 * )
F_37 ( V_42 , V_50 ) ) ||
! ( V_37 = ( T_11 * )
F_37 ( V_42 , V_51 ) ) ||
! ( V_38 = ( T_12 * )
F_37 ( V_42 , V_52 ) ) ||
! ( V_39 = ( T_13 * )
F_37 ( V_42 , V_53 ) ) ||
# endif
! ( V_40 = ( T_14 * )
F_37 ( V_42 , V_54 ) ) ||
! ( V_41 = ( T_15 * )
F_37 ( V_42 , V_55 ) ) ) {
F_35 ( V_43 , V_46 ) ;
goto V_45;
}
F_31 = V_33 ;
F_33 = V_34 ;
V_56 = V_35 ;
# ifndef F_2
V_57 = V_36 ;
V_58 = V_37 ;
V_59 = V_38 ;
V_60 = V_39 ;
# endif
V_61 = V_40 ;
V_62 = V_41 ;
if ( V_63 == 0 ) {
if ( F_38 () != NULL &&
F_39 () != NULL &&
F_40 () != NULL ) {
V_32 . V_64 = V_65 ;
V_32 . V_66 = V_67 ;
V_32 . V_68 = V_69 ;
V_32 . V_70 = V_71 ;
}
}
if ( ! F_30 ( & V_72 , & V_73 ) ) {
F_35 ( V_43 , V_74 ) ;
goto V_45;
}
# ifndef F_2
if ( V_75 == - 1 )
V_75 = F_41 ( 0 ,
L_2 ,
NULL , NULL , NULL ) ;
# endif
return 1 ;
V_45:
if ( V_42 )
F_42 ( V_42 ) ;
V_42 = NULL ;
F_31 = NULL ;
F_33 = NULL ;
V_56 = NULL ;
# ifndef F_2
V_57 = NULL ;
V_58 = NULL ;
V_59 = NULL ;
V_60 = NULL ;
# endif
V_62 = NULL ;
V_61 = NULL ;
return 0 ;
}
static int V_11 ( T_1 * V_1 )
{
int V_76 = 1 ;
F_25 () ;
if ( V_42 == NULL ) {
F_35 ( V_77 , V_78 ) ;
V_76 = 0 ;
goto V_45;
}
F_32 ( V_72 ) ;
if ( ! F_42 ( V_42 ) ) {
F_35 ( V_77 , V_46 ) ;
V_76 = 0 ;
goto V_45;
}
V_45:
if ( V_79 )
F_43 ( V_79 ) ;
V_42 = NULL ;
F_31 = NULL ;
F_33 = NULL ;
V_56 = NULL ;
# ifndef F_2
V_57 = NULL ;
V_58 = NULL ;
V_59 = NULL ;
V_60 = NULL ;
# endif
V_62 = NULL ;
V_61 = NULL ;
return V_76 ;
}
static int V_12 ( T_1 * V_1 , int V_80 , long V_81 , void * V_82 , void (* F_44) ( void ) )
{
int V_76 = 1 ;
switch ( V_80 ) {
case V_83 :
if ( V_42 ) {
F_35 ( V_84 , V_44 ) ;
return 0 ;
}
if ( V_82 == NULL ) {
F_35 ( V_84 , V_85 ) ;
return 0 ;
}
return F_28 ( ( const char * ) V_82 ) ;
case V_86 :
{
T_16 * V_87 = ( T_16 * ) V_82 ;
F_45 ( V_88 ) ;
if ( V_79 ) {
F_43 ( V_79 ) ;
V_79 = NULL ;
}
if ( F_46 ( & V_87 -> V_89 , 1 , V_90 ) > 1 )
V_79 = V_87 ;
else
F_35 ( V_84 , V_91 ) ;
}
F_47 ( V_88 ) ;
break;
case V_92 :
F_45 ( V_88 ) ;
V_73 . V_93 = ( V_94 * ) F_44 ;
F_47 ( V_88 ) ;
break;
case V_95 :
case V_96 :
F_45 ( V_88 ) ;
V_73 . V_97 = ( V_98 * ) V_82 ;
F_47 ( V_88 ) ;
break;
case V_99 :
case V_100 :
F_45 ( V_88 ) ;
V_73 . V_101 = V_82 ;
F_47 ( V_88 ) ;
break;
case V_102 :
case V_103 :
F_45 ( V_88 ) ;
if ( V_81 )
V_32 . V_104 |= V_105 ;
else
V_32 . V_104 &= ~ V_105 ;
F_47 ( V_88 ) ;
break;
case V_106 :
F_45 ( V_88 ) ;
V_63 = 1 ;
F_47 ( V_88 ) ;
break;
case V_107 :
F_45 ( V_88 ) ;
V_63 = ( ( V_81 == 0 ) ? 0 : 1 ) ;
F_47 ( V_88 ) ;
break;
default:
F_35 ( V_84 ,
V_108 ) ;
V_76 = 0 ;
break;
}
return V_76 ;
}
static T_17 * V_13 ( T_1 * V_109 , const char * V_110 ,
V_98 * V_97 ,
void * V_101 )
{
# ifndef F_2
T_18 * V_111 = NULL ;
# endif
T_17 * V_112 = NULL ;
# ifndef F_2
T_19 V_1 , V_113 ;
T_20 * V_114 ;
# endif
# if ! F_48 ( F_2 )
char V_28 [ 1024 ] ;
T_6 V_29 ;
T_21 V_115 ;
# endif
# if ! F_48 ( F_2 )
V_29 . V_30 = V_28 ;
V_29 . V_31 = sizeof( V_28 ) ;
# endif
if ( ! V_72 ) {
F_35 ( V_116 , V_117 ) ;
goto V_45;
}
# ifndef F_2
V_114 = F_49 ( sizeof( T_20 ) ) ;
if ( ! V_114 ) {
F_35 ( V_116 , V_118 ) ;
goto V_45;
}
V_115 . V_97 = V_97 ;
V_115 . V_101 = V_101 ;
if ( V_58 ( V_72 , V_110 , V_114 , & V_29 , & V_115 ) ) {
F_35 ( V_116 , V_119 ) ;
F_50 ( 1 , V_29 . V_30 ) ;
goto V_45;
}
if ( ! * V_114 ) {
F_35 ( V_116 , V_120 ) ;
goto V_45;
}
# endif
# ifndef F_2
V_111 = F_51 ( V_109 ) ;
F_52 ( V_111 , V_75 , ( char * ) V_114 ) ;
V_111 -> V_1 = F_53 () ;
V_111 -> V_113 = F_53 () ;
V_111 -> V_104 |= V_121 ;
F_54 ( V_111 -> V_1 , V_1 ) ;
F_54 ( V_111 -> V_113 , V_113 ) ;
if ( V_59 ( * V_114 , & V_113 , & V_1 , & V_29 )
!= V_122 ) {
F_35 ( V_116 , V_119 ) ;
F_50 ( 1 , V_29 . V_30 ) ;
goto V_45;
}
F_55 ( V_111 -> V_1 , V_1 . V_31 / sizeof( V_123 ) ) ;
F_55 ( V_111 -> V_113 , V_113 . V_31 / sizeof( V_123 ) ) ;
F_54 ( V_111 -> V_1 , V_1 ) ;
F_54 ( V_111 -> V_113 , V_113 ) ;
if ( V_59 ( * V_114 , & V_113 , & V_1 , & V_29 ) ) {
F_35 ( V_116 , V_119 ) ;
F_50 ( 1 , V_29 . V_30 ) ;
goto V_45;
}
V_111 -> V_1 -> V_124 = V_1 . V_31 / sizeof( V_123 ) ;
F_56 ( V_111 -> V_1 ) ;
V_111 -> V_113 -> V_124 = V_113 . V_31 / sizeof( V_123 ) ;
F_56 ( V_111 -> V_113 ) ;
V_112 = F_57 () ;
F_58 ( V_112 , V_111 ) ;
# endif
if ( ! V_112 )
F_35 ( V_116 ,
V_125 ) ;
return V_112 ;
V_45:
# ifndef F_2
if ( V_111 )
F_59 ( V_111 ) ;
# endif
return NULL ;
}
static T_17 * V_14 ( T_1 * V_109 , const char * V_110 ,
V_98 * V_97 , void * V_101 )
{
T_17 * V_112 = NULL ;
# ifndef F_2
V_112 = V_13 ( V_109 , V_110 , V_97 , V_101 ) ;
# endif
if ( V_112 )
switch ( V_112 -> type ) {
# ifndef F_2
case V_126 :
{
T_18 * V_127 = NULL ;
F_45 ( V_128 ) ;
V_127 = V_112 -> V_129 . V_127 ;
V_112 -> V_129 . V_127 = F_60 () ;
V_112 -> V_129 . V_127 -> V_113 = V_127 -> V_113 ;
V_112 -> V_129 . V_127 -> V_1 = V_127 -> V_1 ;
V_127 -> V_113 = NULL ;
V_127 -> V_1 = NULL ;
F_47 ( V_128 ) ;
F_59 ( V_127 ) ;
}
break;
# endif
default:
F_35 ( V_130 ,
V_108 ) ;
goto V_45;
}
return V_112 ;
V_45:
if ( V_112 )
F_61 ( V_112 ) ;
return NULL ;
}
static int F_62 ( T_22 * V_131 , const T_22 * V_132 , const T_22 * V_82 ,
const T_22 * V_133 , T_23 * V_134 )
{
char V_28 [ 1024 ] ;
T_6 V_29 ;
T_19 V_135 , V_136 , V_137 , V_138 ;
int V_76 , V_22 ;
V_76 = 0 ;
V_29 . V_30 = V_28 ;
V_29 . V_31 = sizeof( V_28 ) ;
if ( ! V_72 ) {
F_35 ( V_139 , V_117 ) ;
goto V_45;
}
F_55 ( V_131 , V_133 -> V_124 ) ;
F_63 ( V_135 , V_132 ) ;
F_63 ( V_136 , V_82 ) ;
F_63 ( V_137 , V_133 ) ;
F_54 ( V_131 , V_138 ) ;
V_22 = V_56 ( V_72 , V_135 , V_136 , V_137 , & V_138 , & V_29 ) ;
V_131 -> V_124 = V_138 . V_31 / sizeof( V_123 ) ;
F_56 ( V_131 ) ;
if ( V_22 < 0 ) {
if ( V_22 == V_140 ) {
F_35 ( V_139 , V_141 ) ;
} else {
F_35 ( V_139 , V_142 ) ;
}
F_50 ( 1 , V_29 . V_30 ) ;
goto V_45;
}
V_76 = 1 ;
V_45:
return V_76 ;
}
static int F_64 ( T_22 * V_131 , const T_22 * V_143 , T_18 * V_127 ,
T_23 * V_134 )
{
char V_28 [ 1024 ] ;
T_6 V_29 ;
T_20 * V_114 ;
int V_76 = 0 , V_22 ;
V_29 . V_30 = V_28 ;
V_29 . V_31 = sizeof( V_28 ) ;
if ( ! V_72 ) {
F_35 ( V_144 , V_117 ) ;
goto V_45;
}
if ( ( V_114 =
( T_20 * ) F_65 ( V_127 , V_75 ) )
!= NULL ) {
T_19 V_135 , V_138 ;
if ( ! V_127 -> V_113 ) {
F_35 ( V_144 ,
V_145 ) ;
goto V_45;
}
F_55 ( V_131 , V_127 -> V_113 -> V_124 ) ;
F_63 ( V_135 , V_143 ) ;
F_54 ( V_131 , V_138 ) ;
V_22 = V_57 ( V_135 , * V_114 , & V_138 , & V_29 ) ;
V_131 -> V_124 = V_138 . V_31 / sizeof( V_123 ) ;
F_56 ( V_131 ) ;
if ( V_22 < 0 ) {
if ( V_22 == V_140 ) {
F_35 ( V_144 ,
V_141 ) ;
} else {
F_35 ( V_144 ,
V_142 ) ;
}
F_50 ( 1 , V_29 . V_30 ) ;
goto V_45;
}
} else {
T_19 V_135 , V_136 , V_146 , V_147 , V_148 , V_149 , V_138 ;
if ( ! V_127 -> V_82 || ! V_127 -> V_150 || ! V_127 -> V_151 || ! V_127 -> V_152 || ! V_127 -> V_153 ) {
F_35 ( V_144 ,
V_145 ) ;
goto V_45;
}
F_55 ( V_131 , V_127 -> V_113 -> V_124 ) ;
F_63 ( V_135 , V_143 ) ;
F_63 ( V_136 , V_127 -> V_82 ) ;
F_63 ( V_146 , V_127 -> V_150 ) ;
F_63 ( V_147 , V_127 -> V_151 ) ;
F_63 ( V_148 , V_127 -> V_152 ) ;
F_63 ( V_149 , V_127 -> V_153 ) ;
F_54 ( V_131 , V_138 ) ;
V_22 = V_62 ( V_72 , V_135 , V_136 , V_146 ,
V_147 , V_148 , V_149 , & V_138 , & V_29 ) ;
V_131 -> V_124 = V_138 . V_31 / sizeof( V_123 ) ;
F_56 ( V_131 ) ;
if ( V_22 < 0 ) {
if ( V_22 == V_140 ) {
F_35 ( V_144 ,
V_141 ) ;
} else {
F_35 ( V_144 ,
V_142 ) ;
}
F_50 ( 1 , V_29 . V_30 ) ;
goto V_45;
}
}
V_76 = 1 ;
V_45:
return V_76 ;
}
static int F_66 ( T_22 * V_131 , const T_22 * V_132 , const T_22 * V_82 ,
const T_22 * V_133 , T_23 * V_134 ,
T_24 * V_154 )
{
return F_62 ( V_131 , V_132 , V_82 , V_133 , V_134 ) ;
}
static int F_67 ( T_18 * V_127 )
{
T_20 * V_114 ;
V_114 = F_65 ( V_127 , V_75 ) ;
if ( V_114 ) {
V_60 ( * V_114 , NULL ) ;
F_26 ( V_114 ) ;
F_52 ( V_127 , V_75 , NULL ) ;
}
return 1 ;
}
static int F_68 ( const T_25 * V_155 , T_22 * V_131 ,
const T_22 * V_132 , const T_22 * V_82 ,
const T_22 * V_133 , T_23 * V_134 , T_24 * V_154 )
{
return F_62 ( V_131 , V_132 , V_82 , V_133 , V_134 ) ;
}
static int F_69 ( unsigned char * V_30 , int V_156 )
{
char V_28 [ 1024 ] ;
T_6 V_29 ;
int V_76 = 0 ;
int V_22 ;
V_29 . V_30 = V_28 ;
V_29 . V_31 = sizeof( V_28 ) ;
if ( ! V_72 ) {
F_35 ( V_157 , V_117 ) ;
goto V_45;
}
V_22 = V_61 ( V_72 , V_30 , V_156 , & V_29 ) ;
if ( V_22 < 0 ) {
if ( V_22 == V_140 ) {
F_35 ( V_157 , V_141 ) ;
} else {
F_35 ( V_157 , V_142 ) ;
}
F_50 ( 1 , V_29 . V_30 ) ;
goto V_45;
}
V_76 = 1 ;
V_45:
return V_76 ;
}
static int F_70 ( void )
{
return 1 ;
}
static int V_65 ( T_26 * V_158 ,
T_5 * V_159 )
{
V_158 -> V_160 = F_71 () ;
if ( V_158 -> V_160 == 0 )
return 1 ;
return 0 ;
}
static int V_67 ( T_26 * V_158 )
{
F_45 ( V_158 -> V_160 ) ;
return 0 ;
}
static void V_69 ( T_26 * V_158 )
{
F_47 ( V_158 -> V_160 ) ;
}
static void V_71 ( T_26 * V_158 )
{
F_72 ( V_158 -> V_160 ) ;
}
static int F_73 ( const char * V_161 ,
int * V_162 , char * V_30 ,
T_21 * V_115 ,
T_5 * V_159 )
{
V_94 * V_163 = NULL ;
void * V_101 = NULL ;
V_98 * V_97 = NULL ;
if ( V_161 && ! * V_161 )
V_161 = NULL ;
if ( V_159 ) {
if ( V_159 -> V_97 )
V_97 = V_159 -> V_97 ;
if ( V_159 -> V_93 )
V_163 = V_159 -> V_93 ;
if ( V_159 -> V_101 )
V_101 = V_159 -> V_101 ;
}
if ( V_115 ) {
if ( V_115 -> V_97 ) {
V_97 = V_115 -> V_97 ;
V_163 = NULL ;
}
if ( V_115 -> V_101 )
V_101 = V_115 -> V_101 ;
}
if ( V_163 == NULL && V_97 == NULL ) {
F_35 ( V_164 , V_165 ) ;
return - 1 ;
}
if ( V_97 ) {
T_27 * V_166 = F_74 ( V_97 ) ;
if ( V_166 ) {
int V_167 ;
char * V_168 = F_75 ( V_166 ,
L_3 , V_161 ) ;
V_167 = F_76 ( V_166 , V_168 ,
V_169 ,
V_30 , 0 , ( * V_162 ) - 1 ) ;
F_77 ( V_166 , V_101 ) ;
F_78 ( V_166 , V_170 , 1 , 0 , 0 ) ;
if ( V_167 >= 0 )
do {
V_167 = F_79 ( V_166 ) ;
}
while ( V_167 < 0 && F_78 ( V_166 , V_171 , 0 , 0 , 0 ) );
if ( V_167 >= 0 )
* V_162 = strlen ( V_30 ) ;
F_80 ( V_166 ) ;
F_26 ( V_168 ) ;
}
} else {
* V_162 = V_163 ( V_30 , * V_162 , 0 , V_101 ) ;
}
if ( ! * V_162 )
return - 1 ;
return 0 ;
}
static int F_81 ( const char * V_161 ,
const char * V_172 ,
T_21 * V_115 ,
T_5 * V_159 )
{
int V_167 = - 1 ;
T_27 * V_166 ;
void * V_101 = NULL ;
V_98 * V_97 = NULL ;
if ( V_159 ) {
if ( V_159 -> V_97 )
V_97 = V_159 -> V_97 ;
if ( V_159 -> V_101 )
V_101 = V_159 -> V_101 ;
}
if ( V_115 ) {
if ( V_115 -> V_97 )
V_97 = V_115 -> V_97 ;
if ( V_115 -> V_101 )
V_101 = V_115 -> V_101 ;
}
if ( V_97 == NULL ) {
F_35 ( V_173 , V_165 ) ;
return - 1 ;
}
V_166 = F_74 ( V_97 ) ;
if ( V_166 ) {
char V_174 ;
char V_30 [ V_175 ] ;
if ( V_172 && * V_172 )
F_82 ( V_30 , sizeof( V_30 ) - 1 ,
L_4 , V_172 ) ;
else
V_30 [ 0 ] = 0 ;
V_167 = F_83 ( V_166 , V_30 ) ;
if ( V_167 >= 0 && V_161 ) {
F_82 ( V_30 , sizeof( V_30 ) - 1 ,
L_5 , V_161 ) ;
V_167 = F_84 ( V_166 , V_30 ,
L_6 ,
L_7 , L_8 , V_176 ,
& V_174 ) ;
}
F_77 ( V_166 , V_101 ) ;
if ( V_167 >= 0 )
V_167 = F_79 ( V_166 ) ;
F_80 ( V_166 ) ;
if ( V_167 == - 2 || ( V_167 >= 0 && V_174 == 'C' ) )
V_167 = 1 ;
else if ( V_167 < 0 )
V_167 = - 1 ;
else
V_167 = 0 ;
}
return V_167 ;
}
static void F_85 ( void * V_177 , const char * V_178 )
{
T_16 * V_179 = NULL ;
F_45 ( V_90 ) ;
if ( V_177 )
V_179 = * ( T_16 * * ) V_177 ;
if ( V_179 ) {
F_86 ( V_179 , L_9 , V_178 ) ;
}
F_47 ( V_90 ) ;
}
static int F_87 ( T_1 * V_1 , const char * V_180 )
{
if ( V_180 && ( strcmp ( V_180 , V_4 ) != 0 ) &&
( strcmp ( V_180 , V_181 ) != 0 ) )
return 0 ;
if ( ! F_1 ( V_1 ) )
return 0 ;
return 1 ;
}
