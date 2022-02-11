static int F_1 ( T_1 * V_1 )
{
#ifndef F_2
const T_2 * V_2 ;
#endif
#ifndef F_3
const T_3 * V_3 ;
#endif
if( ! F_4 ( V_1 , V_4 ) ||
! F_5 ( V_1 , V_5 ) ||
#ifndef F_2
! F_6 ( V_1 , & V_6 ) ||
#endif
#ifndef F_3
! F_7 ( V_1 , & V_7 ) ||
#endif
! F_8 ( V_1 , & V_8 ) ||
! F_9 ( V_1 , V_9 ) ||
! F_10 ( V_1 , V_10 ) ||
! F_11 ( V_1 , V_11 ) ||
! F_12 ( V_1 , V_12 ) ||
! F_13 ( V_1 , V_13 ) ||
! F_14 ( V_1 , V_14 ) ||
! F_15 ( V_1 , V_15 ) )
return 0 ;
#ifndef F_2
V_2 = F_16 () ;
V_6 . V_16 = V_2 -> V_16 ;
V_6 . V_17 = V_2 -> V_17 ;
V_6 . V_18 = V_2 -> V_18 ;
V_6 . V_19 = V_2 -> V_19 ;
#endif
#ifndef F_3
V_3 = F_17 () ;
V_7 . V_20 = V_3 -> V_20 ;
V_7 . V_21 = V_3 -> V_21 ;
#endif
F_18 () ;
return 1 ;
}
static T_1 * F_19 ( void )
{
T_1 * V_22 = F_20 () ;
if( ! V_22 )
return NULL ;
if( ! F_1 ( V_22 ) )
{
F_21 ( V_22 ) ;
return NULL ;
}
return V_22 ;
}
void F_22 ( void )
{
T_1 * V_23 = F_19 () ;
if( ! V_23 ) return;
F_23 ( V_23 ) ;
F_21 ( V_23 ) ;
F_24 () ;
}
static void F_25 ( void )
{
if( V_24 )
F_26 ( ( void * ) V_24 ) ;
V_24 = NULL ;
}
static const char * F_27 ( void )
{
if( V_24 )
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
* V_26 = F_31 ( & V_32 , sizeof( V_32 ) , & V_29 ,
V_27 ) ;
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
#ifndef F_2
T_10 * V_36 ;
T_11 * V_37 ;
T_12 * V_38 ;
T_13 * V_39 ;
#endif
T_14 * V_40 ;
T_15 * V_41 ;
if( V_42 != NULL )
{
F_35 ( V_43 , V_44 ) ;
goto V_45;
}
V_42 = F_36 ( NULL , F_27 () , NULL , 0 ) ;
if( V_42 == NULL )
{
F_35 ( V_43 , V_46 ) ;
goto V_45;
}
if( ! ( V_33 = ( T_7 * )
F_37 ( V_42 , V_47 ) ) ||
! ( V_34 = ( T_8 * )
F_37 ( V_42 , V_48 ) ) ||
! ( V_35 = ( T_9 * )
F_37 ( V_42 , V_49 ) ) ||
#ifndef F_2
! ( V_36 = ( T_10 * )
F_37 ( V_42 , V_50 ) ) ||
! ( V_37 = ( T_11 * )
F_37 ( V_42 , V_51 ) ) ||
! ( V_38 = ( T_12 * )
F_37 ( V_42 , V_52 ) ) ||
! ( V_39 = ( T_13 * )
F_37 ( V_42 , V_53 ) ) ||
#endif
! ( V_40 = ( T_14 * )
F_37 ( V_42 , V_54 ) ) ||
! ( V_41 = ( T_15 * )
F_37 ( V_42 , V_55 ) ) )
{
F_35 ( V_43 , V_46 ) ;
goto V_45;
}
F_31 = V_33 ;
F_33 = V_34 ;
V_56 = V_35 ;
#ifndef F_2
V_57 = V_36 ;
V_58 = V_37 ;
V_59 = V_38 ;
V_60 = V_39 ;
#endif
V_61 = V_40 ;
V_62 = V_41 ;
if ( V_63 == 0 )
{
if ( F_38 () != NULL &&
F_39 () != NULL &&
F_40 () != NULL )
{
V_32 . V_64 = V_65 ;
V_32 . V_66 = V_67 ;
V_32 . V_68 = V_69 ;
V_32 . V_70 = V_71 ;
}
}
if( ! F_30 ( & V_72 , & V_73 ) )
{
F_35 ( V_43 , V_74 ) ;
goto V_45;
}
#ifndef F_2
if ( V_75 == - 1 )
V_75 = F_41 ( 0 ,
L_2 ,
NULL , NULL , V_76 ) ;
#endif
return 1 ;
V_45:
if( V_42 )
F_42 ( V_42 ) ;
V_42 = NULL ;
F_31 = NULL ;
F_33 = NULL ;
V_56 = NULL ;
#ifndef F_2
V_57 = NULL ;
V_58 = NULL ;
V_59 = NULL ;
V_60 = NULL ;
#endif
V_62 = NULL ;
V_61 = NULL ;
return 0 ;
}
static int V_11 ( T_1 * V_1 )
{
int V_77 = 1 ;
F_25 () ;
if( V_42 == NULL )
{
F_35 ( V_78 , V_79 ) ;
V_77 = 0 ;
goto V_45;
}
F_32 ( V_72 ) ;
if( ! F_42 ( V_42 ) )
{
F_35 ( V_78 , V_46 ) ;
V_77 = 0 ;
goto V_45;
}
V_45:
if ( V_80 )
F_43 ( V_80 ) ;
V_42 = NULL ;
F_31 = NULL ;
F_33 = NULL ;
V_56 = NULL ;
#ifndef F_2
V_57 = NULL ;
V_58 = NULL ;
V_59 = NULL ;
V_60 = NULL ;
#endif
V_62 = NULL ;
V_61 = NULL ;
return V_77 ;
}
static int V_12 ( T_1 * V_1 , int V_81 , long V_82 , void * V_83 , void (* F_44)( void ) )
{
int V_77 = 1 ;
switch( V_81 )
{
case V_84 :
if( V_42 )
{
F_35 ( V_85 , V_44 ) ;
return 0 ;
}
if( V_83 == NULL )
{
F_35 ( V_85 , V_86 ) ;
return 0 ;
}
return F_28 ( ( const char * ) V_83 ) ;
case V_87 :
{
T_16 * V_88 = ( T_16 * ) V_83 ;
F_45 ( V_89 ) ;
if ( V_80 )
{
F_43 ( V_80 ) ;
V_80 = NULL ;
}
if ( F_46 ( & V_88 -> V_90 , 1 , V_91 ) > 1 )
V_80 = V_88 ;
else
F_35 ( V_85 , V_92 ) ;
}
F_47 ( V_89 ) ;
break;
case V_93 :
F_45 ( V_89 ) ;
V_73 . V_94 = ( V_95 * ) F_44 ;
F_47 ( V_89 ) ;
break;
case V_96 :
case V_97 :
F_45 ( V_89 ) ;
V_73 . V_98 = ( V_99 * ) V_83 ;
F_47 ( V_89 ) ;
break;
case V_100 :
case V_101 :
F_45 ( V_89 ) ;
V_73 . V_102 = V_83 ;
F_47 ( V_89 ) ;
break;
case V_103 :
case V_104 :
F_45 ( V_89 ) ;
if( V_82 )
V_32 . V_105 |=
V_106 ;
else
V_32 . V_105 &=
~ V_106 ;
F_47 ( V_89 ) ;
break;
case V_107 :
F_45 ( V_89 ) ;
V_63 = 1 ;
F_47 ( V_89 ) ;
break;
case V_108 :
F_45 ( V_89 ) ;
V_63 = ( ( V_82 == 0 ) ? 0 : 1 ) ;
F_47 ( V_89 ) ;
break;
default:
F_35 ( V_85 ,
V_109 ) ;
V_77 = 0 ;
break;
}
return V_77 ;
}
static T_17 * V_13 ( T_1 * V_110 , const char * V_111 ,
V_99 * V_98 , void * V_102 )
{
#ifndef F_2
T_18 * V_112 = NULL ;
#endif
T_17 * V_113 = NULL ;
#ifndef F_2
T_19 V_1 , V_114 ;
T_20 * V_115 ;
#endif
#if ! F_48 ( F_2 )
char V_28 [ 1024 ] ;
T_6 V_29 ;
T_21 V_116 ;
#endif
#if ! F_48 ( F_2 )
V_29 . V_30 = V_28 ;
V_29 . V_31 = sizeof( V_28 ) ;
#endif
if( ! V_72 )
{
F_35 ( V_117 ,
V_118 ) ;
goto V_45;
}
#ifndef F_2
V_115 = F_49 ( sizeof( T_20 ) ) ;
if ( ! V_115 )
{
F_35 ( V_117 ,
V_119 ) ;
goto V_45;
}
V_116 . V_98 = V_98 ;
V_116 . V_102 = V_102 ;
if ( V_58 ( V_72 , V_111 , V_115 ,
& V_29 , & V_116 ) )
{
F_35 ( V_117 ,
V_120 ) ;
F_50 ( 1 , V_29 . V_30 ) ;
goto V_45;
}
if ( ! * V_115 )
{
F_35 ( V_117 ,
V_121 ) ;
goto V_45;
}
#endif
#ifndef F_2
V_112 = F_51 ( V_110 ) ;
F_52 ( V_112 , V_75 , ( char * ) V_115 ) ;
V_112 -> V_1 = F_53 () ;
V_112 -> V_114 = F_53 () ;
V_112 -> V_105 |= V_122 ;
F_54 ( V_112 -> V_1 , V_1 ) ;
F_54 ( V_112 -> V_114 , V_114 ) ;
if ( V_59 ( * V_115 , & V_114 , & V_1 , & V_29 )
!= V_123 )
{
F_35 ( V_117 , V_120 ) ;
F_50 ( 1 , V_29 . V_30 ) ;
goto V_45;
}
F_55 ( V_112 -> V_1 , V_1 . V_31 / sizeof( V_124 ) ) ;
F_55 ( V_112 -> V_114 , V_114 . V_31 / sizeof( V_124 ) ) ;
F_54 ( V_112 -> V_1 , V_1 ) ;
F_54 ( V_112 -> V_114 , V_114 ) ;
if ( V_59 ( * V_115 , & V_114 , & V_1 , & V_29 ) )
{
F_35 ( V_117 ,
V_120 ) ;
F_50 ( 1 , V_29 . V_30 ) ;
goto V_45;
}
V_112 -> V_1 -> V_125 = V_1 . V_31 / sizeof( V_124 ) ;
F_56 ( V_112 -> V_1 ) ;
V_112 -> V_114 -> V_125 = V_114 . V_31 / sizeof( V_124 ) ;
F_56 ( V_112 -> V_114 ) ;
V_113 = F_57 () ;
F_58 ( V_113 , V_112 ) ;
#endif
if ( ! V_113 )
F_35 ( V_117 ,
V_126 ) ;
return V_113 ;
V_45:
#ifndef F_2
if ( V_112 )
F_59 ( V_112 ) ;
#endif
return NULL ;
}
static T_17 * V_14 ( T_1 * V_110 , const char * V_111 ,
V_99 * V_98 , void * V_102 )
{
T_17 * V_113 = NULL ;
#ifndef F_2
V_113 = V_13 ( V_110 , V_111 ,
V_98 , V_102 ) ;
#endif
if ( V_113 )
switch( V_113 -> type )
{
#ifndef F_2
case V_127 :
{
T_18 * V_128 = NULL ;
F_45 ( V_129 ) ;
V_128 = V_113 -> V_130 . V_128 ;
V_113 -> V_130 . V_128 = F_60 () ;
V_113 -> V_130 . V_128 -> V_114 = V_128 -> V_114 ;
V_113 -> V_130 . V_128 -> V_1 = V_128 -> V_1 ;
V_128 -> V_114 = NULL ;
V_128 -> V_1 = NULL ;
F_47 ( V_129 ) ;
F_59 ( V_128 ) ;
}
break;
#endif
default:
F_35 ( V_131 ,
V_109 ) ;
goto V_45;
}
return V_113 ;
V_45:
if ( V_113 )
F_61 ( V_113 ) ;
return NULL ;
}
static int F_62 ( T_22 * V_132 , const T_22 * V_133 , const T_22 * V_83 ,
const T_22 * V_134 , T_23 * V_135 )
{
char V_28 [ 1024 ] ;
T_6 V_29 ;
T_19 V_136 , V_137 , V_138 , V_139 ;
int V_77 , V_22 ;
V_77 = 0 ;
V_29 . V_30 = V_28 ;
V_29 . V_31 = sizeof( V_28 ) ;
if( ! V_72 )
{
F_35 ( V_140 , V_118 ) ;
goto V_45;
}
F_55 ( V_132 , V_134 -> V_125 ) ;
F_63 ( V_136 , V_133 ) ;
F_63 ( V_137 , V_83 ) ;
F_63 ( V_138 , V_134 ) ;
F_54 ( V_132 , V_139 ) ;
V_22 = V_56 ( V_72 , V_136 , V_137 , V_138 , & V_139 , & V_29 ) ;
V_132 -> V_125 = V_139 . V_31 / sizeof( V_124 ) ;
F_56 ( V_132 ) ;
if ( V_22 < 0 )
{
if( V_22 == V_141 )
{
F_35 ( V_140 , V_142 ) ;
}
else
{
F_35 ( V_140 , V_143 ) ;
}
F_50 ( 1 , V_29 . V_30 ) ;
goto V_45;
}
V_77 = 1 ;
V_45:
return V_77 ;
}
static int F_64 ( T_22 * V_132 , const T_22 * V_144 , T_18 * V_128 , T_23 * V_135 )
{
char V_28 [ 1024 ] ;
T_6 V_29 ;
T_20 * V_115 ;
int V_77 = 0 , V_22 ;
V_29 . V_30 = V_28 ;
V_29 . V_31 = sizeof( V_28 ) ;
if( ! V_72 )
{
F_35 ( V_145 , V_118 ) ;
goto V_45;
}
if ( ( V_115 = ( T_20 * ) F_65 ( V_128 , V_75 ) )
!= NULL )
{
T_19 V_136 , V_139 ;
if( ! V_128 -> V_114 )
{
F_35 ( V_145 ,
V_146 ) ;
goto V_45;
}
F_55 ( V_132 , V_128 -> V_114 -> V_125 ) ;
F_63 ( V_136 , V_144 ) ;
F_54 ( V_132 , V_139 ) ;
V_22 = V_57 ( V_136 , * V_115 , & V_139 , & V_29 ) ;
V_132 -> V_125 = V_139 . V_31 / sizeof( V_124 ) ;
F_56 ( V_132 ) ;
if ( V_22 < 0 )
{
if( V_22 == V_141 )
{
F_35 ( V_145 ,
V_142 ) ;
}
else
{
F_35 ( V_145 ,
V_143 ) ;
}
F_50 ( 1 , V_29 . V_30 ) ;
goto V_45;
}
}
else
{
T_19 V_136 , V_137 , V_147 , V_148 , V_149 , V_150 , V_139 ;
if( ! V_128 -> V_83 || ! V_128 -> V_151 || ! V_128 -> V_152 || ! V_128 -> V_153 || ! V_128 -> V_154 )
{
F_35 ( V_145 ,
V_146 ) ;
goto V_45;
}
F_55 ( V_132 , V_128 -> V_114 -> V_125 ) ;
F_63 ( V_136 , V_144 ) ;
F_63 ( V_137 , V_128 -> V_83 ) ;
F_63 ( V_147 , V_128 -> V_151 ) ;
F_63 ( V_148 , V_128 -> V_152 ) ;
F_63 ( V_149 , V_128 -> V_153 ) ;
F_63 ( V_150 , V_128 -> V_154 ) ;
F_54 ( V_132 , V_139 ) ;
V_22 = V_62 ( V_72 , V_136 , V_137 , V_147 ,
V_148 , V_149 , V_150 , & V_139 , & V_29 ) ;
V_132 -> V_125 = V_139 . V_31 / sizeof( V_124 ) ;
F_56 ( V_132 ) ;
if ( V_22 < 0 )
{
if( V_22 == V_141 )
{
F_35 ( V_145 ,
V_142 ) ;
}
else
{
F_35 ( V_145 ,
V_143 ) ;
}
F_50 ( 1 , V_29 . V_30 ) ;
goto V_45;
}
}
V_77 = 1 ;
V_45:
return V_77 ;
}
static int F_66 ( T_22 * V_132 , const T_22 * V_133 , const T_22 * V_83 ,
const T_22 * V_134 , T_23 * V_135 , T_24 * V_155 )
{
return F_62 ( V_132 , V_133 , V_83 , V_134 , V_135 ) ;
}
static int F_67 ( const T_25 * V_156 , T_22 * V_132 ,
const T_22 * V_133 , const T_22 * V_83 ,
const T_22 * V_134 , T_23 * V_135 , T_24 * V_155 )
{
return F_62 ( V_132 , V_133 , V_83 , V_134 , V_135 ) ;
}
static int F_68 ( unsigned char * V_30 , int V_157 )
{
char V_28 [ 1024 ] ;
T_6 V_29 ;
int V_77 = 0 ;
int V_22 ;
V_29 . V_30 = V_28 ;
V_29 . V_31 = sizeof( V_28 ) ;
if( ! V_72 )
{
F_35 ( V_158 , V_118 ) ;
goto V_45;
}
V_22 = V_61 ( V_72 , V_30 , V_157 , & V_29 ) ;
if ( V_22 < 0 )
{
if( V_22 == V_141 )
{
F_35 ( V_158 ,
V_142 ) ;
}
else
{
F_35 ( V_158 ,
V_143 ) ;
}
F_50 ( 1 , V_29 . V_30 ) ;
goto V_45;
}
V_77 = 1 ;
V_45:
return V_77 ;
}
static int F_69 ( void )
{
return 1 ;
}
static void V_76 ( void * V_159 , void * V_160 , T_26 * V_161 ,
int V_162 , long V_163 , void * V_164 )
{
char V_28 [ 1024 ] ;
T_6 V_29 ;
#ifndef F_2
T_20 * V_115 ;
#endif
#if ! F_48 ( F_2 )
int V_22 ;
#endif
V_29 . V_30 = V_28 ;
V_29 . V_31 = sizeof( V_28 ) ;
#ifndef F_2
V_115 = ( T_20 * ) V_160 ;
if( V_115 )
{
V_22 = V_60 ( * V_115 , NULL ) ;
F_26 ( V_115 ) ;
}
#endif
}
static int V_65 ( T_27 * V_165 ,
T_5 * V_166 )
{
V_165 -> V_167 = F_70 () ;
if ( V_165 -> V_167 == 0 )
return 1 ;
return 0 ;
}
static int V_67 ( T_27 * V_165 )
{
F_45 ( V_165 -> V_167 ) ;
return 0 ;
}
static void V_69 ( T_27 * V_165 )
{
F_47 ( V_165 -> V_167 ) ;
}
static void V_71 ( T_27 * V_165 )
{
F_71 ( V_165 -> V_167 ) ;
}
static int F_72 ( const char * V_168 ,
int * V_169 , char * V_30 ,
T_21 * V_116 ,
T_5 * V_166 )
{
V_95 * V_170 = NULL ;
void * V_102 = NULL ;
V_99 * V_98 = NULL ;
if ( V_168 && ! * V_168 )
V_168 = NULL ;
if ( V_166 )
{
if ( V_166 -> V_98 )
V_98 = V_166 -> V_98 ;
if ( V_166 -> V_94 )
V_170 = V_166 -> V_94 ;
if ( V_166 -> V_102 )
V_102 = V_166 -> V_102 ;
}
if ( V_116 )
{
if ( V_116 -> V_98 )
{
V_98 = V_116 -> V_98 ;
V_170 = NULL ;
}
if ( V_116 -> V_102 )
V_102 = V_116 -> V_102 ;
}
if ( V_170 == NULL && V_98 == NULL )
{
F_35 ( V_171 , V_172 ) ;
return - 1 ;
}
if ( V_98 )
{
T_28 * V_173 = F_73 ( V_98 ) ;
if ( V_173 )
{
int V_174 ;
char * V_175 = F_74 ( V_173 ,
L_3 , V_168 ) ;
V_174 = F_75 ( V_173 , V_175 ,
V_176 ,
V_30 , 0 , ( * V_169 ) - 1 ) ;
F_76 ( V_173 , V_102 ) ;
F_77 ( V_173 , V_177 , 1 , 0 , 0 ) ;
if ( V_174 >= 0 )
do
{
V_174 = F_78 ( V_173 ) ;
}
while ( V_174 < 0 && F_77 ( V_173 , V_178 , 0 , 0 , 0 ) );
if ( V_174 >= 0 )
* V_169 = strlen ( V_30 ) ;
F_79 ( V_173 ) ;
F_26 ( V_175 ) ;
}
}
else
{
* V_169 = V_170 ( V_30 , * V_169 , 0 , V_102 ) ;
}
if( ! * V_169 )
return - 1 ;
return 0 ;
}
static int F_80 ( const char * V_168 ,
const char * V_179 ,
T_21 * V_116 ,
T_5 * V_166 )
{
int V_174 = - 1 ;
T_28 * V_173 ;
void * V_102 = NULL ;
V_99 * V_98 = NULL ;
if ( V_166 )
{
if ( V_166 -> V_98 )
V_98 = V_166 -> V_98 ;
if ( V_166 -> V_102 )
V_102 = V_166 -> V_102 ;
}
if ( V_116 )
{
if ( V_116 -> V_98 )
V_98 = V_116 -> V_98 ;
if ( V_116 -> V_102 )
V_102 = V_116 -> V_102 ;
}
if ( V_98 == NULL )
{
F_35 ( V_180 ,
V_172 ) ;
return - 1 ;
}
V_173 = F_73 ( V_98 ) ;
if ( V_173 )
{
char V_181 ;
char V_30 [ V_182 ] ;
if ( V_179 && * V_179 )
F_81 ( V_30 , sizeof( V_30 ) - 1 ,
L_4 , V_179 ) ;
else
V_30 [ 0 ] = 0 ;
V_174 = F_82 ( V_173 , V_30 ) ;
if ( V_174 >= 0 && V_168 )
{
F_81 ( V_30 , sizeof( V_30 ) - 1 ,
L_5 , V_168 ) ;
V_174 = F_83 ( V_173 , V_30 ,
L_6 ,
L_7 , L_8 , V_183 , & V_181 ) ;
}
F_76 ( V_173 , V_102 ) ;
if ( V_174 >= 0 )
V_174 = F_78 ( V_173 ) ;
F_79 ( V_173 ) ;
if ( V_174 == - 2 || ( V_174 >= 0 && V_181 == 'C' ) )
V_174 = 1 ;
else if ( V_174 < 0 )
V_174 = - 1 ;
else
V_174 = 0 ;
}
return V_174 ;
}
static void F_84 ( void * V_184 , const char * V_185 )
{
T_16 * V_186 = NULL ;
F_45 ( V_91 ) ;
if ( V_184 )
V_186 = * ( T_16 * * ) V_184 ;
if ( V_186 )
{
F_85 ( V_186 , L_9 , V_185 ) ;
}
F_47 ( V_91 ) ;
}
static int F_86 ( T_1 * V_1 , const char * V_187 )
{
if( V_187 && ( strcmp ( V_187 , V_4 ) != 0 ) &&
( strcmp ( V_187 , V_188 ) != 0 ) )
return 0 ;
if( ! F_1 ( V_1 ) )
return 0 ;
return 1 ;
}
