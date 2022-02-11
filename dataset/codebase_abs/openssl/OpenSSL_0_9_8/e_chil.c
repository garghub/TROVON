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
else if ( F_41 () != NULL )
{
F_35 ( V_43 , V_72 ) ;
F_42 ( 1 , L_2 ) ;
goto V_45;
}
}
if( ! F_30 ( & V_73 , & V_74 ) )
{
F_35 ( V_43 , V_75 ) ;
goto V_45;
}
#ifndef F_2
if ( V_76 == - 1 )
V_76 = F_43 ( 0 ,
L_3 ,
NULL , NULL , V_77 ) ;
#endif
return 1 ;
V_45:
if( V_42 )
F_44 ( V_42 ) ;
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
int V_78 = 1 ;
F_25 () ;
if( V_42 == NULL )
{
F_35 ( V_79 , V_80 ) ;
V_78 = 0 ;
goto V_45;
}
F_32 ( V_73 ) ;
if( ! F_44 ( V_42 ) )
{
F_35 ( V_79 , V_46 ) ;
V_78 = 0 ;
goto V_45;
}
V_45:
if ( V_81 )
F_45 ( V_81 ) ;
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
return V_78 ;
}
static int V_12 ( T_1 * V_1 , int V_82 , long V_83 , void * V_84 , void (* F_46)( void ) )
{
int V_78 = 1 ;
switch( V_82 )
{
case V_85 :
if( V_42 )
{
F_35 ( V_86 , V_44 ) ;
return 0 ;
}
if( V_84 == NULL )
{
F_35 ( V_86 , V_87 ) ;
return 0 ;
}
return F_28 ( ( const char * ) V_84 ) ;
case V_88 :
{
T_16 * V_89 = ( T_16 * ) V_84 ;
F_47 ( V_90 ) ;
if ( V_81 )
{
F_45 ( V_81 ) ;
V_81 = NULL ;
}
if ( F_48 ( & V_89 -> V_91 , 1 , V_92 ) > 1 )
V_81 = V_89 ;
else
F_35 ( V_86 , V_93 ) ;
}
F_49 ( V_90 ) ;
break;
case V_94 :
F_47 ( V_90 ) ;
V_74 . V_95 = ( V_96 * ) F_46 ;
F_49 ( V_90 ) ;
break;
case V_97 :
case V_98 :
F_47 ( V_90 ) ;
V_74 . V_99 = ( V_100 * ) V_84 ;
F_49 ( V_90 ) ;
break;
case V_101 :
case V_102 :
F_47 ( V_90 ) ;
V_74 . V_103 = V_84 ;
F_49 ( V_90 ) ;
break;
case V_104 :
case V_105 :
F_47 ( V_90 ) ;
if( V_83 )
V_32 . V_106 |=
V_107 ;
else
V_32 . V_106 &=
~ V_107 ;
F_49 ( V_90 ) ;
break;
case V_108 :
F_47 ( V_90 ) ;
V_63 = 1 ;
F_49 ( V_90 ) ;
break;
case V_109 :
F_47 ( V_90 ) ;
V_63 = ( ( V_83 == 0 ) ? 0 : 1 ) ;
F_49 ( V_90 ) ;
break;
default:
F_35 ( V_86 ,
V_110 ) ;
V_78 = 0 ;
break;
}
return V_78 ;
}
static T_17 * V_13 ( T_1 * V_111 , const char * V_112 ,
V_100 * V_99 , void * V_103 )
{
#ifndef F_2
T_18 * V_113 = NULL ;
#endif
T_17 * V_114 = NULL ;
#ifndef F_2
T_19 V_1 , V_115 ;
T_20 * V_116 ;
#endif
#if ! F_50 ( F_2 )
char V_28 [ 1024 ] ;
T_6 V_29 ;
#endif
T_21 V_117 ;
#if ! F_50 ( F_2 )
V_29 . V_30 = V_28 ;
V_29 . V_31 = sizeof( V_28 ) ;
#endif
if( ! V_73 )
{
F_35 ( V_118 ,
V_119 ) ;
goto V_45;
}
#ifndef F_2
V_116 = F_51 ( sizeof( T_20 ) ) ;
if ( ! V_116 )
{
F_35 ( V_118 ,
V_120 ) ;
goto V_45;
}
V_117 . V_99 = V_99 ;
V_117 . V_103 = V_103 ;
if ( V_58 ( V_73 , V_112 , V_116 ,
& V_29 , & V_117 ) )
{
F_35 ( V_118 ,
V_121 ) ;
F_42 ( 1 , V_29 . V_30 ) ;
goto V_45;
}
if ( ! * V_116 )
{
F_35 ( V_118 ,
V_122 ) ;
goto V_45;
}
#endif
#ifndef F_2
V_113 = F_52 ( V_111 ) ;
F_53 ( V_113 , V_76 , ( char * ) V_116 ) ;
V_113 -> V_1 = F_54 () ;
V_113 -> V_115 = F_54 () ;
V_113 -> V_106 |= V_123 ;
F_55 ( V_113 -> V_1 , V_1 ) ;
F_55 ( V_113 -> V_115 , V_115 ) ;
if ( V_59 ( * V_116 , & V_115 , & V_1 , & V_29 )
!= V_124 )
{
F_35 ( V_118 , V_121 ) ;
F_42 ( 1 , V_29 . V_30 ) ;
goto V_45;
}
F_56 ( V_113 -> V_1 , V_1 . V_31 / sizeof( V_125 ) ) ;
F_56 ( V_113 -> V_115 , V_115 . V_31 / sizeof( V_125 ) ) ;
F_55 ( V_113 -> V_1 , V_1 ) ;
F_55 ( V_113 -> V_115 , V_115 ) ;
if ( V_59 ( * V_116 , & V_115 , & V_1 , & V_29 ) )
{
F_35 ( V_118 ,
V_121 ) ;
F_42 ( 1 , V_29 . V_30 ) ;
goto V_45;
}
V_113 -> V_1 -> V_126 = V_1 . V_31 / sizeof( V_125 ) ;
F_57 ( V_113 -> V_1 ) ;
V_113 -> V_115 -> V_126 = V_115 . V_31 / sizeof( V_125 ) ;
F_57 ( V_113 -> V_115 ) ;
V_114 = F_58 () ;
F_59 ( V_114 , V_113 ) ;
#endif
if ( ! V_114 )
F_35 ( V_118 ,
V_127 ) ;
return V_114 ;
V_45:
if ( V_114 )
F_60 ( V_114 ) ;
#ifndef F_2
if ( V_113 )
F_61 ( V_113 ) ;
#endif
return NULL ;
}
static T_17 * V_14 ( T_1 * V_111 , const char * V_112 ,
V_100 * V_99 , void * V_103 )
{
T_17 * V_114 = NULL ;
#ifndef F_2
V_114 = V_13 ( V_111 , V_112 ,
V_99 , V_103 ) ;
#endif
if ( V_114 )
switch( V_114 -> type )
{
#ifndef F_2
case V_128 :
{
T_18 * V_129 = NULL ;
F_47 ( V_130 ) ;
V_129 = V_114 -> V_131 . V_129 ;
V_114 -> V_131 . V_129 = F_62 () ;
V_114 -> V_131 . V_129 -> V_115 = V_129 -> V_115 ;
V_114 -> V_131 . V_129 -> V_1 = V_129 -> V_1 ;
V_129 -> V_115 = NULL ;
V_129 -> V_1 = NULL ;
F_49 ( V_130 ) ;
F_61 ( V_129 ) ;
}
break;
#endif
default:
F_35 ( V_132 ,
V_110 ) ;
goto V_45;
}
return V_114 ;
V_45:
if ( V_114 )
F_60 ( V_114 ) ;
return NULL ;
}
static int F_63 ( T_22 * V_133 , const T_22 * V_134 , const T_22 * V_84 ,
const T_22 * V_135 , T_23 * V_136 )
{
char V_28 [ 1024 ] ;
T_6 V_29 ;
T_19 V_137 , V_138 , V_139 , V_140 ;
int V_78 , V_22 ;
V_78 = 0 ;
V_29 . V_30 = V_28 ;
V_29 . V_31 = sizeof( V_28 ) ;
if( ! V_73 )
{
F_35 ( V_141 , V_119 ) ;
goto V_45;
}
F_56 ( V_133 , V_135 -> V_126 ) ;
F_64 ( V_137 , V_134 ) ;
F_64 ( V_138 , V_84 ) ;
F_64 ( V_139 , V_135 ) ;
F_55 ( V_133 , V_140 ) ;
V_22 = V_56 ( V_73 , V_137 , V_138 , V_139 , & V_140 , & V_29 ) ;
V_133 -> V_126 = V_140 . V_31 / sizeof( V_125 ) ;
F_57 ( V_133 ) ;
if ( V_22 < 0 )
{
if( V_22 == V_142 )
{
F_35 ( V_141 , V_143 ) ;
}
else
{
F_35 ( V_141 , V_144 ) ;
}
F_42 ( 1 , V_29 . V_30 ) ;
goto V_45;
}
V_78 = 1 ;
V_45:
return V_78 ;
}
static int F_65 ( T_22 * V_133 , const T_22 * V_145 , T_18 * V_129 , T_23 * V_136 )
{
char V_28 [ 1024 ] ;
T_6 V_29 ;
T_20 * V_116 ;
int V_78 = 0 , V_22 ;
V_29 . V_30 = V_28 ;
V_29 . V_31 = sizeof( V_28 ) ;
if( ! V_73 )
{
F_35 ( V_146 , V_119 ) ;
goto V_45;
}
if ( ( V_116 = ( T_20 * ) F_66 ( V_129 , V_76 ) )
!= NULL )
{
T_19 V_137 , V_140 ;
if( ! V_129 -> V_115 )
{
F_35 ( V_146 ,
V_147 ) ;
goto V_45;
}
F_56 ( V_133 , V_129 -> V_115 -> V_126 ) ;
F_64 ( V_137 , V_145 ) ;
F_55 ( V_133 , V_140 ) ;
V_22 = V_57 ( V_137 , * V_116 , & V_140 , & V_29 ) ;
V_133 -> V_126 = V_140 . V_31 / sizeof( V_125 ) ;
F_57 ( V_133 ) ;
if ( V_22 < 0 )
{
if( V_22 == V_142 )
{
F_35 ( V_146 ,
V_143 ) ;
}
else
{
F_35 ( V_146 ,
V_144 ) ;
}
F_42 ( 1 , V_29 . V_30 ) ;
goto V_45;
}
}
else
{
T_19 V_137 , V_138 , V_148 , V_149 , V_150 , V_151 , V_140 ;
if( ! V_129 -> V_84 || ! V_129 -> V_152 || ! V_129 -> V_153 || ! V_129 -> V_154 || ! V_129 -> V_155 )
{
F_35 ( V_146 ,
V_147 ) ;
goto V_45;
}
F_56 ( V_133 , V_129 -> V_115 -> V_126 ) ;
F_64 ( V_137 , V_145 ) ;
F_64 ( V_138 , V_129 -> V_84 ) ;
F_64 ( V_148 , V_129 -> V_152 ) ;
F_64 ( V_149 , V_129 -> V_153 ) ;
F_64 ( V_150 , V_129 -> V_154 ) ;
F_64 ( V_151 , V_129 -> V_155 ) ;
F_55 ( V_133 , V_140 ) ;
V_22 = V_62 ( V_73 , V_137 , V_138 , V_148 ,
V_149 , V_150 , V_151 , & V_140 , & V_29 ) ;
V_133 -> V_126 = V_140 . V_31 / sizeof( V_125 ) ;
F_57 ( V_133 ) ;
if ( V_22 < 0 )
{
if( V_22 == V_142 )
{
F_35 ( V_146 ,
V_143 ) ;
}
else
{
F_35 ( V_146 ,
V_144 ) ;
}
F_42 ( 1 , V_29 . V_30 ) ;
goto V_45;
}
}
V_78 = 1 ;
V_45:
return V_78 ;
}
static int F_67 ( T_22 * V_133 , const T_22 * V_134 , const T_22 * V_84 ,
const T_22 * V_135 , T_23 * V_136 , T_24 * V_156 )
{
return F_63 ( V_133 , V_134 , V_84 , V_135 , V_136 ) ;
}
static int F_68 ( const T_25 * V_157 , T_22 * V_133 ,
const T_22 * V_134 , const T_22 * V_84 ,
const T_22 * V_135 , T_23 * V_136 , T_24 * V_156 )
{
return F_63 ( V_133 , V_134 , V_84 , V_135 , V_136 ) ;
}
static int F_69 ( unsigned char * V_30 , int V_158 )
{
char V_28 [ 1024 ] ;
T_6 V_29 ;
int V_78 = 0 ;
int V_22 ;
V_29 . V_30 = V_28 ;
V_29 . V_31 = sizeof( V_28 ) ;
if( ! V_73 )
{
F_35 ( V_159 , V_119 ) ;
goto V_45;
}
V_22 = V_61 ( V_73 , V_30 , V_158 , & V_29 ) ;
if ( V_22 < 0 )
{
if( V_22 == V_142 )
{
F_35 ( V_159 ,
V_143 ) ;
}
else
{
F_35 ( V_159 ,
V_144 ) ;
}
F_42 ( 1 , V_29 . V_30 ) ;
goto V_45;
}
V_78 = 1 ;
V_45:
return V_78 ;
}
static int F_70 ( void )
{
return 1 ;
}
static void V_77 ( void * V_160 , void * V_161 , T_26 * V_162 ,
int V_163 , long V_164 , void * V_165 )
{
char V_28 [ 1024 ] ;
T_6 V_29 ;
#ifndef F_2
T_20 * V_116 ;
#endif
#if ! F_50 ( F_2 )
int V_22 ;
#endif
V_29 . V_30 = V_28 ;
V_29 . V_31 = sizeof( V_28 ) ;
#ifndef F_2
V_116 = ( T_20 * ) V_161 ;
if( V_116 )
{
V_22 = V_60 ( * V_116 , NULL ) ;
F_26 ( V_116 ) ;
}
#endif
}
static int V_65 ( T_27 * V_166 ,
T_5 * V_167 )
{
V_166 -> V_168 = F_71 () ;
if ( V_166 -> V_168 == 0 )
return 1 ;
return 0 ;
}
static int V_67 ( T_27 * V_166 )
{
F_47 ( V_166 -> V_168 ) ;
return 0 ;
}
static void V_69 ( T_27 * V_166 )
{
F_49 ( V_166 -> V_168 ) ;
}
static void V_71 ( T_27 * V_166 )
{
F_72 ( V_166 -> V_168 ) ;
}
static int F_73 ( const char * V_169 ,
int * V_170 , char * V_30 ,
T_21 * V_117 ,
T_5 * V_167 )
{
V_96 * V_171 = NULL ;
void * V_103 = NULL ;
V_100 * V_99 = NULL ;
if ( V_167 )
{
if ( V_167 -> V_99 )
V_99 = V_167 -> V_99 ;
if ( V_167 -> V_95 )
V_171 = V_167 -> V_95 ;
if ( V_167 -> V_103 )
V_103 = V_167 -> V_103 ;
}
if ( V_117 )
{
if ( V_117 -> V_99 )
{
V_99 = V_117 -> V_99 ;
V_171 = NULL ;
}
if ( V_117 -> V_103 )
V_103 = V_117 -> V_103 ;
}
if ( V_171 == NULL && V_99 == NULL )
{
F_35 ( V_172 , V_173 ) ;
return - 1 ;
}
if ( V_99 )
{
T_28 * V_174 = F_74 ( V_99 ) ;
if ( V_174 )
{
int V_175 ;
char * V_176 = F_75 ( V_174 ,
L_4 , V_169 ) ;
V_175 = F_76 ( V_174 , V_176 ,
V_177 ,
V_30 , 0 , ( * V_170 ) - 1 ) ;
F_77 ( V_174 , V_103 ) ;
F_78 ( V_174 , V_178 , 1 , 0 , 0 ) ;
if ( V_175 >= 0 )
do
{
V_175 = F_79 ( V_174 ) ;
}
while ( V_175 < 0 && F_78 ( V_174 , V_179 , 0 , 0 , 0 ) );
if ( V_175 >= 0 )
* V_170 = strlen ( V_30 ) ;
F_80 ( V_174 ) ;
F_26 ( V_176 ) ;
}
}
else
{
* V_170 = V_171 ( V_30 , * V_170 , 0 , V_103 ) ;
}
if( ! * V_170 )
return - 1 ;
return 0 ;
}
static int F_81 ( const char * V_169 ,
const char * V_180 ,
T_21 * V_117 ,
T_5 * V_167 )
{
int V_175 = - 1 ;
T_28 * V_174 ;
void * V_103 = NULL ;
V_100 * V_99 = NULL ;
if ( V_167 )
{
if ( V_167 -> V_99 )
V_99 = V_167 -> V_99 ;
if ( V_167 -> V_103 )
V_103 = V_167 -> V_103 ;
}
if ( V_117 )
{
if ( V_117 -> V_99 )
V_99 = V_117 -> V_99 ;
if ( V_117 -> V_103 )
V_103 = V_117 -> V_103 ;
}
if ( V_99 == NULL )
{
F_35 ( V_181 ,
V_173 ) ;
return - 1 ;
}
V_174 = F_74 ( V_99 ) ;
if ( V_174 )
{
char V_182 ;
char V_30 [ V_183 ] ;
if ( V_180 )
F_82 ( V_30 , sizeof( V_30 ) - 1 ,
L_5 , V_180 ) ;
V_175 = F_83 ( V_174 , V_30 ) ;
if ( V_175 >= 0 && V_169 )
{
F_82 ( V_30 , sizeof( V_30 ) - 1 ,
L_6 , V_169 ) ;
V_175 = F_84 ( V_174 , V_30 ,
L_7 ,
L_8 , L_9 , V_184 , & V_182 ) ;
}
F_77 ( V_174 , V_103 ) ;
if ( V_175 >= 0 )
V_175 = F_79 ( V_174 ) ;
F_80 ( V_174 ) ;
if ( V_175 == - 2 || ( V_175 >= 0 && V_182 == 'C' ) )
V_175 = 1 ;
else if ( V_175 < 0 )
V_175 = - 1 ;
else
V_175 = 0 ;
}
return V_175 ;
}
static void F_85 ( void * V_185 , const char * V_186 )
{
T_16 * V_187 = NULL ;
F_47 ( V_92 ) ;
if ( V_185 )
V_187 = * ( T_16 * * ) V_185 ;
if ( V_187 )
{
F_86 ( V_187 , L_10 , V_186 ) ;
}
F_49 ( V_92 ) ;
}
static int F_87 ( T_1 * V_1 , const char * V_188 )
{
if( V_188 && ( strcmp ( V_188 , V_4 ) != 0 ) &&
( strcmp ( V_188 , V_189 ) != 0 ) )
return 0 ;
if( ! F_1 ( V_1 ) )
return 0 ;
return 1 ;
}
