int F_1 ( T_1 * V_1 )
{
int V_2 ;
if ( V_1 -> V_3 == NULL )
{
F_2 ( V_4 , V_5 ) ;
return ( 0 ) ;
}
V_1 -> error = 0 ;
V_1 -> V_6 = 0 ;
V_1 -> V_7 = 0 ;
#if 0
if (s->new_session) return(1);
#endif
V_2 = V_1 -> V_2 ;
V_1 -> type = 0 ;
V_1 -> V_2 = V_8 | ( ( V_1 -> V_9 ) ? V_10 : V_11 ) ;
V_1 -> V_12 = V_1 -> V_3 -> V_12 ;
V_1 -> V_13 = V_1 -> V_12 ;
V_1 -> V_14 = V_15 ;
V_1 -> V_16 = V_17 ;
V_1 -> V_18 = V_1 -> V_19 -> V_18 ;
if ( V_1 -> V_20 != NULL )
{
F_3 ( V_1 -> V_20 ) ;
V_1 -> V_20 = NULL ;
}
F_4 ( V_1 ) ;
if ( F_5 ( V_1 ) )
{
F_6 ( V_1 -> V_21 ) ;
V_1 -> V_21 = NULL ;
}
V_1 -> V_22 = 0 ;
#if 1
if ( ( V_1 -> V_21 == NULL ) && ( V_1 -> V_3 != V_1 -> V_19 -> V_3 ) )
{
V_1 -> V_3 -> V_23 ( V_1 ) ;
V_1 -> V_3 = V_1 -> V_19 -> V_3 ;
if ( ! V_1 -> V_3 -> V_24 ( V_1 ) )
return ( 0 ) ;
}
else
#endif
V_1 -> V_3 -> V_25 ( V_1 ) ;
return ( 1 ) ;
}
int F_7 ( T_2 * V_19 , T_3 * V_26 )
{
F_8 ( V_27 ) * V_28 ;
V_19 -> V_3 = V_26 ;
V_28 = F_9 ( V_19 -> V_3 , & ( V_19 -> V_29 ) ,
& ( V_19 -> V_30 ) , V_31 ) ;
if ( ( V_28 == NULL ) || ( F_10 ( V_28 ) <= 0 ) )
{
F_2 ( V_32 , V_33 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
T_1 * F_11 ( T_2 * V_19 )
{
T_1 * V_1 ;
if ( V_19 == NULL )
{
F_2 ( V_34 , V_35 ) ;
return ( NULL ) ;
}
if ( V_19 -> V_3 == NULL )
{
F_2 ( V_34 , V_36 ) ;
return ( NULL ) ;
}
V_1 = ( T_1 * ) Malloc ( sizeof( T_1 ) ) ;
if ( V_1 == NULL ) goto V_37;
memset ( V_1 , 0 , sizeof( T_1 ) ) ;
if ( V_19 -> V_38 != NULL )
{
V_1 -> V_38 = F_12 ( V_19 -> V_38 ) ;
if ( V_1 -> V_38 == NULL )
goto V_37;
}
else
V_1 -> V_38 = NULL ;
V_1 -> V_39 = V_19 -> V_39 ;
memcpy ( & V_1 -> V_40 , & V_19 -> V_40 , sizeof( V_1 -> V_40 ) ) ;
V_1 -> V_41 = V_19 -> V_41 ;
V_1 -> V_42 = V_19 -> V_42 ;
V_1 -> V_43 = V_19 -> V_44 ;
F_13 ( & V_19 -> V_45 , 1 , V_46 ) ;
V_1 -> V_19 = V_19 ;
V_1 -> V_47 = V_48 ;
V_1 -> V_3 = V_19 -> V_3 ;
if ( ! V_1 -> V_3 -> V_24 ( V_1 ) )
goto V_37;
V_1 -> V_49 = V_19 -> V_49 ;
V_1 -> V_45 = 1 ;
V_1 -> V_9 = ( V_19 -> V_3 -> V_50 == V_51 ) ? 0 : 1 ;
V_1 -> V_52 = V_19 -> V_52 ;
F_1 ( V_1 ) ;
F_14 ( V_53 , ( char * ) V_1 , & V_1 -> V_54 ) ;
return ( V_1 ) ;
V_37:
if ( V_1 != NULL )
{
if ( V_1 -> V_38 != NULL )
F_15 ( V_1 -> V_38 ) ;
if ( V_1 -> V_19 != NULL )
F_16 ( V_1 -> V_19 ) ;
Free ( V_1 ) ;
}
F_2 ( V_34 , V_55 ) ;
return ( NULL ) ;
}
int F_17 ( T_2 * V_19 , const unsigned char * V_40 ,
unsigned int V_56 )
{
if( V_56 > V_57 )
{
F_2 ( V_58 , V_59 ) ;
return 0 ;
}
V_19 -> V_39 = V_56 ;
memcpy ( V_19 -> V_40 , V_40 , V_56 ) ;
return 1 ;
}
int F_18 ( T_1 * V_60 , const unsigned char * V_40 ,
unsigned int V_56 )
{
if( V_56 > V_57 )
{
F_2 ( V_61 , V_59 ) ;
return 0 ;
}
V_60 -> V_39 = V_56 ;
memcpy ( V_60 -> V_40 , V_40 , V_56 ) ;
return 1 ;
}
void F_19 ( T_1 * V_1 )
{
int V_62 ;
if( V_1 == NULL )
return;
V_62 = F_13 ( & V_1 -> V_45 , - 1 , V_63 ) ;
#ifdef F_20
F_20 ( L_1 , V_1 ) ;
#endif
if ( V_62 > 0 ) return;
#ifdef F_21
if ( V_62 < 0 )
{
fprintf ( V_64 , L_2 ) ;
abort () ;
}
#endif
F_22 ( V_53 , ( char * ) V_1 , & V_1 -> V_54 ) ;
if ( V_1 -> V_65 != NULL )
{
if ( V_1 -> V_65 == V_1 -> V_66 )
{
V_1 -> V_66 = F_23 ( V_1 -> V_66 ) ;
}
F_24 ( V_1 -> V_65 ) ;
V_1 -> V_65 = NULL ;
}
if ( V_1 -> V_67 != NULL )
F_25 ( V_1 -> V_67 ) ;
if ( ( V_1 -> V_66 != NULL ) && ( V_1 -> V_66 != V_1 -> V_67 ) )
F_25 ( V_1 -> V_66 ) ;
if ( V_1 -> V_20 != NULL ) F_3 ( V_1 -> V_20 ) ;
if ( V_1 -> V_29 != NULL ) F_26 ( V_1 -> V_29 ) ;
if ( V_1 -> V_30 != NULL ) F_26 ( V_1 -> V_30 ) ;
if ( V_1 -> V_21 != NULL )
{
F_5 ( V_1 ) ;
F_6 ( V_1 -> V_21 ) ;
}
F_4 ( V_1 ) ;
if ( V_1 -> V_38 != NULL ) F_15 ( V_1 -> V_38 ) ;
if ( V_1 -> V_19 ) F_16 ( V_1 -> V_19 ) ;
if ( V_1 -> V_68 != NULL )
F_27 ( V_1 -> V_68 , V_69 ) ;
if ( V_1 -> V_3 != NULL ) V_1 -> V_3 -> V_23 ( V_1 ) ;
Free ( ( char * ) V_1 ) ;
}
void F_28 ( T_1 * V_1 , T_4 * V_67 , T_4 * V_66 )
{
if ( V_1 -> V_65 != NULL )
{
if ( V_1 -> V_66 == V_1 -> V_65 )
{
V_1 -> V_66 = V_1 -> V_66 -> V_70 ;
V_1 -> V_65 -> V_70 = NULL ;
}
}
if ( ( V_1 -> V_67 != NULL ) && ( V_1 -> V_67 != V_67 ) )
F_25 ( V_1 -> V_67 ) ;
if ( ( V_1 -> V_66 != NULL ) && ( V_1 -> V_66 != V_66 ) && ( V_1 -> V_67 != V_1 -> V_66 ) )
F_25 ( V_1 -> V_66 ) ;
V_1 -> V_67 = V_67 ;
V_1 -> V_66 = V_66 ;
}
T_4 * F_29 ( T_1 * V_1 )
{ return ( V_1 -> V_67 ) ; }
T_4 * F_30 ( T_1 * V_1 )
{ return ( V_1 -> V_66 ) ; }
int F_31 ( T_1 * V_1 )
{
int V_71 = - 1 ;
T_4 * V_72 , * V_73 ;
V_72 = F_29 ( V_1 ) ;
V_73 = F_32 ( V_72 , V_74 ) ;
if ( V_73 != NULL )
F_33 ( V_73 , & V_71 ) ;
return ( V_71 ) ;
}
int F_34 ( T_1 * V_1 , int V_75 )
{
int V_71 = 0 ;
T_4 * V_76 = NULL ;
V_76 = F_35 ( F_36 () ) ;
if ( V_76 == NULL )
{
F_2 ( V_77 , V_78 ) ;
goto V_37;
}
F_37 ( V_76 , V_75 , V_79 ) ;
F_28 ( V_1 , V_76 , V_76 ) ;
V_71 = 1 ;
V_37:
return ( V_71 ) ;
}
int F_38 ( T_1 * V_1 , int V_75 )
{
int V_71 = 0 ;
T_4 * V_76 = NULL ;
if ( ( V_1 -> V_67 == NULL ) || ( F_39 ( V_1 -> V_67 ) != V_80 )
|| ( ( int ) F_33 ( V_1 -> V_67 , NULL ) != V_75 ) )
{
V_76 = F_35 ( F_36 () ) ;
if ( V_76 == NULL )
{ F_2 ( V_81 , V_78 ) ; goto V_37; }
F_37 ( V_76 , V_75 , V_79 ) ;
F_28 ( V_1 , F_29 ( V_1 ) , V_76 ) ;
}
else
F_28 ( V_1 , F_29 ( V_1 ) , F_29 ( V_1 ) ) ;
V_71 = 1 ;
V_37:
return ( V_71 ) ;
}
int F_40 ( T_1 * V_1 , int V_75 )
{
int V_71 = 0 ;
T_4 * V_76 = NULL ;
if ( ( V_1 -> V_66 == NULL ) || ( F_39 ( V_1 -> V_66 ) != V_80 )
|| ( ( int ) F_33 ( V_1 -> V_66 , NULL ) != V_75 ) )
{
V_76 = F_35 ( F_36 () ) ;
if ( V_76 == NULL )
{
F_2 ( V_82 , V_78 ) ;
goto V_37;
}
F_37 ( V_76 , V_75 , V_79 ) ;
F_28 ( V_1 , V_76 , F_30 ( V_1 ) ) ;
}
else
F_28 ( V_1 , F_30 ( V_1 ) , F_30 ( V_1 ) ) ;
V_71 = 1 ;
V_37:
return ( V_71 ) ;
}
int F_41 ( T_1 * V_1 )
{
return ( V_1 -> V_41 ) ;
}
int F_42 ( T_1 * V_1 )
{
return ( V_1 -> V_42 ) ;
}
int F_43 ( T_2 * V_19 )
{
return ( V_19 -> V_41 ) ;
}
int F_44 ( T_2 * V_19 )
{
return ( V_19 -> V_42 ) ;
}
void F_45 ( T_1 * V_1 , int V_83 ,
int (* F_46)( int V_84 , T_5 * V_19 ) )
{
V_1 -> V_41 = V_83 ;
if ( F_46 != NULL )
V_1 -> V_43 = F_46 ;
}
void F_47 ( T_1 * V_1 , int V_85 )
{
V_1 -> V_42 = V_85 ;
}
void F_48 ( T_1 * V_1 , int V_86 )
{
V_1 -> V_18 = V_86 ;
}
int F_49 ( T_1 * V_1 )
{
return ( V_1 -> V_18 ) ;
}
int F_50 ( T_1 * V_1 )
{
return ( V_1 -> V_3 -> V_87 ( V_1 ) ) ;
}
T_6 * F_51 ( T_1 * V_1 )
{
T_6 * V_73 ;
if ( ( V_1 == NULL ) || ( V_1 -> V_21 == NULL ) )
V_73 = NULL ;
else
V_73 = V_1 -> V_21 -> V_88 ;
if ( V_73 == NULL ) return ( V_73 ) ;
F_13 ( & V_73 -> V_45 , 1 , V_89 ) ;
return ( V_73 ) ;
}
int F_52 ( T_2 * V_19 )
{
if ( ( V_19 == NULL ) ||
( V_19 -> V_38 == NULL ) ||
( V_19 -> V_38 -> V_90 -> V_91 == NULL ) )
{
F_2 ( V_92 , V_93 ) ;
return ( 0 ) ;
}
if ( V_19 -> V_38 -> V_90 -> V_94 == NULL )
{
F_2 ( V_92 , V_95 ) ;
return ( 0 ) ;
}
return ( F_53 ( V_19 -> V_38 -> V_90 -> V_91 , V_19 -> V_38 -> V_90 -> V_94 ) ) ;
}
int F_54 ( T_1 * V_60 )
{
if ( V_60 == NULL )
{
F_2 ( V_96 , V_97 ) ;
return ( 0 ) ;
}
if ( V_60 -> V_38 == NULL )
return ( F_52 ( V_60 -> V_19 ) ) ;
if ( V_60 -> V_38 -> V_90 -> V_91 == NULL )
{
F_2 ( V_96 , V_93 ) ;
return ( 0 ) ;
}
if ( V_60 -> V_38 -> V_90 -> V_94 == NULL )
{
F_2 ( V_96 , V_95 ) ;
return ( 0 ) ;
}
return ( F_53 ( V_60 -> V_38 -> V_90 -> V_91 ,
V_60 -> V_38 -> V_90 -> V_94 ) ) ;
}
int F_55 ( T_1 * V_1 )
{
if ( V_1 -> V_98 == 0 )
F_56 ( V_1 ) ;
return ( V_1 -> V_3 -> V_50 ( V_1 ) ) ;
}
int F_57 ( T_1 * V_1 )
{
if ( V_1 -> V_98 == 0 )
F_58 ( V_1 ) ;
return ( V_1 -> V_3 -> V_99 ( V_1 ) ) ;
}
long F_59 ( T_1 * V_1 )
{
return ( V_1 -> V_3 -> V_100 () ) ;
}
int F_60 ( T_1 * V_1 , char * V_101 , int V_102 )
{
if ( V_1 -> V_98 == 0 )
{
F_2 ( V_103 , V_104 ) ;
return - 1 ;
}
if ( V_1 -> V_7 & V_105 )
{
V_1 -> V_14 = V_15 ;
return ( 0 ) ;
}
return ( V_1 -> V_3 -> V_106 ( V_1 , V_101 , V_102 ) ) ;
}
int F_61 ( T_1 * V_1 , char * V_101 , int V_102 )
{
if ( V_1 -> V_7 & V_105 )
{
return ( 0 ) ;
}
return ( V_1 -> V_3 -> V_107 ( V_1 , V_101 , V_102 ) ) ;
}
int F_62 ( T_1 * V_1 , const char * V_101 , int V_102 )
{
if ( V_1 -> V_98 == 0 )
{
F_2 ( V_108 , V_104 ) ;
return - 1 ;
}
if ( V_1 -> V_7 & V_109 )
{
V_1 -> V_14 = V_15 ;
F_2 ( V_108 , V_110 ) ;
return ( - 1 ) ;
}
return ( V_1 -> V_3 -> V_111 ( V_1 , V_101 , V_102 ) ) ;
}
int F_63 ( T_1 * V_1 )
{
if ( V_1 -> V_98 == 0 )
{
F_2 ( V_112 , V_104 ) ;
return - 1 ;
}
if ( ( V_1 != NULL ) && ! F_64 ( V_1 ) )
return ( V_1 -> V_3 -> V_113 ( V_1 ) ) ;
else
return ( 1 ) ;
}
int F_65 ( T_1 * V_1 )
{
V_1 -> V_114 = 1 ;
return ( V_1 -> V_3 -> V_115 ( V_1 ) ) ;
}
long F_66 ( T_1 * V_1 , int V_116 , long V_117 , char * V_118 )
{
long V_119 ;
switch ( V_116 )
{
case V_120 :
return ( V_1 -> V_18 ) ;
case V_121 :
V_119 = V_1 -> V_18 ;
V_1 -> V_18 = V_117 ;
return ( V_119 ) ;
case V_122 :
return ( V_1 -> V_52 |= V_117 ) ;
default:
return ( V_1 -> V_3 -> V_123 ( V_1 , V_116 , V_117 , V_118 ) ) ;
}
}
long F_67 ( T_2 * V_19 , int V_116 , long V_117 , char * V_118 )
{
long V_119 ;
switch ( V_116 )
{
case V_120 :
return ( V_19 -> V_18 ) ;
case V_121 :
V_119 = V_19 -> V_18 ;
V_19 -> V_18 = V_117 ;
return ( V_119 ) ;
case V_124 :
V_119 = V_19 -> V_125 ;
V_19 -> V_125 = V_117 ;
return ( V_119 ) ;
case V_126 :
return ( V_19 -> V_125 ) ;
case V_127 :
V_119 = V_19 -> V_128 ;
V_19 -> V_128 = V_117 ;
return ( V_119 ) ;
case V_129 :
return ( V_19 -> V_128 ) ;
case V_130 :
return ( V_19 -> V_131 -> V_132 ) ;
case V_133 :
return ( V_19 -> V_134 . V_135 ) ;
case V_136 :
return ( V_19 -> V_134 . V_137 ) ;
case V_138 :
return ( V_19 -> V_134 . V_139 ) ;
case V_140 :
return ( V_19 -> V_134 . V_141 ) ;
case V_142 :
return ( V_19 -> V_134 . V_143 ) ;
case V_144 :
return ( V_19 -> V_134 . V_145 ) ;
case V_146 :
return ( V_19 -> V_134 . V_147 ) ;
case V_148 :
return ( V_19 -> V_134 . V_149 ) ;
case V_150 :
return ( V_19 -> V_134 . V_151 ) ;
case V_152 :
return ( V_19 -> V_134 . V_153 ) ;
case V_154 :
return ( V_19 -> V_134 . V_155 ) ;
case V_122 :
return ( V_19 -> V_52 |= V_117 ) ;
default:
return ( V_19 -> V_3 -> V_156 ( V_19 , V_116 , V_117 , V_118 ) ) ;
}
}
int F_68 ( V_27 * V_157 , V_27 * V_72 )
{
long V_119 ;
V_119 = V_157 -> V_158 - V_72 -> V_158 ;
if ( V_119 == 0L )
return ( 0 ) ;
else
return ( ( V_119 > 0 ) ? 1 : - 1 ) ;
}
int F_69 ( V_27 * * V_159 , V_27 * * V_160 )
{
long V_119 ;
V_119 = ( * V_159 ) -> V_158 - ( * V_160 ) -> V_158 ;
if ( V_119 == 0L )
return ( 0 ) ;
else
return ( ( V_119 > 0 ) ? 1 : - 1 ) ;
}
char * F_70 ( T_1 * V_1 , int V_161 )
{
V_27 * V_162 ;
F_8 ( V_27 ) * V_28 ;
if ( V_1 == NULL ) return ( NULL ) ;
V_28 = F_71 ( V_1 ) ;
if ( ( V_28 == NULL ) || ( F_10 ( V_28 ) <= V_161 ) )
return ( NULL ) ;
V_162 = F_72 ( V_28 , V_161 ) ;
if ( V_162 == NULL ) return ( NULL ) ;
return ( V_162 -> V_163 ) ;
}
int F_73 ( T_2 * V_19 , char * V_164 )
{
F_8 ( V_27 ) * V_28 ;
V_28 = F_9 ( V_19 -> V_3 , & V_19 -> V_29 ,
& V_19 -> V_30 , V_164 ) ;
return ( ( V_28 == NULL ) ? 0 : 1 ) ;
}
int F_74 ( T_1 * V_1 , char * V_164 )
{
F_8 ( V_27 ) * V_28 ;
V_28 = F_9 ( V_1 -> V_19 -> V_3 , & V_1 -> V_29 ,
& V_1 -> V_30 , V_164 ) ;
return ( ( V_28 == NULL ) ? 0 : 1 ) ;
}
char * F_75 ( T_1 * V_1 , char * V_101 , int V_165 )
{
char * V_166 ;
const char * V_167 ;
F_8 ( V_27 ) * V_28 ;
V_27 * V_162 ;
int V_62 ;
if ( ( V_1 -> V_21 == NULL ) || ( V_1 -> V_21 -> V_168 == NULL ) ||
( V_165 < 2 ) )
return ( NULL ) ;
V_166 = V_101 ;
V_28 = V_1 -> V_21 -> V_168 ;
for ( V_62 = 0 ; V_62 < F_10 ( V_28 ) ; V_62 ++ )
{
V_165 -- ;
V_162 = F_72 ( V_28 , V_62 ) ;
for ( V_167 = V_162 -> V_163 ; * V_167 ; )
{
if ( V_165 -- == 0 )
{
* V_166 = '\0' ;
return ( V_101 ) ;
}
else
* ( V_166 ++ ) = * ( V_167 ++ ) ;
}
* ( V_166 ++ ) = ':' ;
}
V_166 [ - 1 ] = '\0' ;
return ( V_101 ) ;
}
long F_76 ( T_7 * V_157 )
{
unsigned long V_119 ;
V_119 = ( unsigned long )
( ( unsigned int ) V_157 -> V_169 [ 0 ] ) |
( ( unsigned int ) V_157 -> V_169 [ 1 ] << 8L ) |
( ( unsigned long ) V_157 -> V_169 [ 2 ] << 16L ) |
( ( unsigned long ) V_157 -> V_169 [ 3 ] << 24L ) ;
return ( V_119 ) ;
}
int F_77 ( T_7 * V_157 , T_7 * V_72 )
{
if ( V_157 -> V_170 != V_72 -> V_170 )
return ( 1 ) ;
if ( V_157 -> V_171 != V_72 -> V_171 )
return ( 1 ) ;
return ( memcmp ( V_157 -> V_169 , V_72 -> V_169 , V_157 -> V_171 ) ) ;
}
T_2 * F_78 ( T_3 * V_26 )
{
T_2 * V_71 = NULL ;
if ( V_26 == NULL )
{
F_2 ( V_172 , V_173 ) ;
return ( NULL ) ;
}
if ( F_79 () < 0 )
{
F_2 ( V_172 , V_174 ) ;
goto V_37;
}
V_71 = ( T_2 * ) Malloc ( sizeof( T_2 ) ) ;
if ( V_71 == NULL )
goto V_37;
memset ( V_71 , 0 , sizeof( T_2 ) ) ;
V_71 -> V_3 = V_26 ;
V_71 -> V_175 = NULL ;
V_71 -> V_128 = V_176 ;
V_71 -> V_125 = V_177 ;
V_71 -> V_178 = NULL ;
V_71 -> V_179 = NULL ;
V_71 -> V_180 = V_26 -> V_100 () ;
V_71 -> V_181 = NULL ;
V_71 -> V_182 = NULL ;
V_71 -> V_183 = NULL ;
memset ( ( char * ) & V_71 -> V_134 , 0 , sizeof( V_71 -> V_134 ) ) ;
V_71 -> V_45 = 1 ;
V_71 -> V_49 = 0 ;
V_71 -> V_184 = NULL ;
V_71 -> V_185 = NULL ;
V_71 -> V_186 = NULL ;
V_71 -> V_18 = 0 ;
V_71 -> V_41 = V_187 ;
V_71 -> V_42 = - 1 ;
V_71 -> V_44 = NULL ;
if ( ( V_71 -> V_38 = F_80 () ) == NULL )
goto V_37;
V_71 -> V_188 = NULL ;
V_71 -> V_189 = NULL ;
V_71 -> V_131 = F_81 ( F_76 , F_77 ) ;
if ( V_71 -> V_131 == NULL ) goto V_37;
V_71 -> V_175 = F_82 () ;
if ( V_71 -> V_175 == NULL ) goto V_37;
F_9 ( V_71 -> V_3 ,
& V_71 -> V_29 , & V_71 -> V_30 ,
V_31 ) ;
if ( V_71 -> V_29 == NULL
|| F_10 ( V_71 -> V_29 ) <= 0 )
{
F_2 ( V_172 , V_190 ) ;
goto V_191;
}
if ( ( V_71 -> V_192 = F_83 ( L_3 ) ) == NULL )
{
F_2 ( V_172 , V_193 ) ;
goto V_191;
}
if ( ( V_71 -> V_194 = F_83 ( L_4 ) ) == NULL )
{
F_2 ( V_172 , V_195 ) ;
goto V_191;
}
if ( ( V_71 -> V_196 = F_83 ( L_5 ) ) == NULL )
{
F_2 ( V_172 , V_197 ) ;
goto V_191;
}
if ( ( V_71 -> V_68 = F_84 () ) == NULL )
goto V_37;
F_14 ( V_198 , ( char * ) V_71 , & V_71 -> V_54 ) ;
V_71 -> V_199 = NULL ;
V_71 -> V_200 = F_85 () ;
return ( V_71 ) ;
V_37:
F_2 ( V_172 , V_55 ) ;
V_191:
if ( V_71 != NULL ) F_16 ( V_71 ) ;
return ( NULL ) ;
}
static void F_86 ( T_8 * V_201 )
{ Free ( V_201 ) ; }
void F_16 ( T_2 * V_157 )
{
int V_62 ;
if ( V_157 == NULL ) return;
V_62 = F_13 ( & V_157 -> V_45 , - 1 , V_46 ) ;
#ifdef F_20
F_20 ( L_6 , V_157 ) ;
#endif
if ( V_62 > 0 ) return;
#ifdef F_21
if ( V_62 < 0 )
{
fprintf ( V_64 , L_7 ) ;
abort () ;
}
#endif
F_22 ( V_198 , ( char * ) V_157 , & V_157 -> V_54 ) ;
if ( V_157 -> V_131 != NULL )
{
F_87 ( V_157 , 0 ) ;
F_88 ( V_157 -> V_131 ) ;
}
if ( V_157 -> V_175 != NULL )
F_89 ( V_157 -> V_175 ) ;
if ( V_157 -> V_29 != NULL )
F_26 ( V_157 -> V_29 ) ;
if ( V_157 -> V_30 != NULL )
F_26 ( V_157 -> V_30 ) ;
if ( V_157 -> V_38 != NULL )
F_15 ( V_157 -> V_38 ) ;
if ( V_157 -> V_68 != NULL )
F_27 ( V_157 -> V_68 , V_69 ) ;
if ( V_157 -> V_199 != NULL )
F_90 ( V_157 -> V_199 , V_202 ) ;
if ( V_157 -> V_200 != NULL )
F_91 ( V_157 -> V_200 , F_86 ) ;
Free ( ( char * ) V_157 ) ;
}
void F_92 ( T_2 * V_19 , T_9 * V_203 )
{
V_19 -> V_188 = V_203 ;
}
void F_93 ( T_2 * V_19 , int (* V_203)() , char * V_204 )
{
V_19 -> V_185 = V_203 ;
V_19 -> V_186 = V_204 ;
}
void F_94 ( T_2 * V_19 , int V_83 , int (* V_203)( int , T_5 * ) )
{
V_19 -> V_41 = V_83 ;
V_19 -> V_44 = V_203 ;
F_95 ( V_19 -> V_175 , V_203 ) ;
}
void F_96 ( T_2 * V_19 , int V_85 )
{
V_19 -> V_42 = V_85 ;
}
void F_97 ( T_10 * V_162 , V_27 * V_205 )
{
T_11 * V_206 ;
int V_207 , V_208 , V_209 , V_210 , V_211 , V_212 , V_213 ;
int V_214 , V_215 , V_216 ;
int V_217 , V_218 , V_219 ;
unsigned long V_220 , V_221 ;
if ( V_162 == NULL ) return;
V_219 = F_98 ( V_205 ) ;
#ifndef F_99
V_208 = ( V_162 -> V_208 != NULL || V_162 -> V_222 != NULL ) ;
V_217 = ( V_162 -> V_222 != NULL ||
( V_208 && F_100 ( V_162 -> V_208 ) * 8 <= V_219 ) ) ;
#else
V_208 = V_217 = 0 ;
#endif
#ifndef F_101
V_210 = ( V_162 -> V_210 != NULL || V_162 -> V_223 != NULL ) ;
V_218 = ( V_162 -> V_223 != NULL ||
( V_210 && F_102 ( V_162 -> V_210 ) * 8 <= V_219 ) ) ;
#else
V_210 = V_218 = 0 ;
#endif
V_206 = & ( V_162 -> V_224 [ V_225 ] ) ;
V_207 = ( V_206 -> V_91 != NULL && V_206 -> V_94 != NULL ) ;
V_214 = ( V_207 && F_103 ( V_206 -> V_94 ) * 8 <= V_219 ) ;
V_206 = & ( V_162 -> V_224 [ V_226 ] ) ;
V_209 = ( V_206 -> V_91 != NULL && V_206 -> V_94 != NULL ) ;
V_206 = & ( V_162 -> V_224 [ V_227 ] ) ;
V_213 = ( V_206 -> V_91 != NULL && V_206 -> V_94 != NULL ) ;
V_206 = & ( V_162 -> V_224 [ V_228 ] ) ;
V_211 = ( V_206 -> V_91 != NULL && V_206 -> V_94 != NULL ) ;
V_215 = ( V_211 && F_103 ( V_206 -> V_94 ) * 8 <= V_219 ) ;
V_206 = & ( V_162 -> V_224 [ V_229 ] ) ;
V_212 = ( V_206 -> V_91 != NULL && V_206 -> V_94 != NULL ) ;
V_216 = ( V_212 && F_103 ( V_206 -> V_94 ) * 8 <= V_219 ) ;
V_220 = 0 ;
V_221 = 0 ;
#ifdef F_104
printf ( L_8 ,
V_208 , V_217 , V_210 ,
V_207 , V_214 , V_209 , V_213 , V_211 , V_212 ) ;
#endif
if ( V_207 || ( V_208 && V_209 ) )
V_220 |= V_230 ;
if ( V_214 || ( V_217 && ( V_209 || V_207 ) ) )
V_221 |= V_230 ;
#if 0
if ( (dh_tmp || dh_rsa || dh_dsa) &&
(rsa_enc || rsa_sign || dsa_sign))
mask|=SSL_kEDH;
if ((dh_tmp_export || dh_rsa_export || dh_dsa_export) &&
(rsa_enc || rsa_sign || dsa_sign))
emask|=SSL_kEDH;
#endif
if ( V_218 )
V_221 |= V_231 ;
if ( V_210 )
V_220 |= V_231 ;
if ( V_211 ) V_220 |= V_232 ;
if ( V_215 ) V_221 |= V_232 ;
if ( V_212 ) V_220 |= V_233 ;
if ( V_216 ) V_221 |= V_233 ;
if ( V_207 || V_209 )
{
V_220 |= V_234 ;
V_221 |= V_234 ;
}
if ( V_213 )
{
V_220 |= V_235 ;
V_221 |= V_235 ;
}
#ifdef F_105
V_220 |= V_236 ;
V_221 |= V_236 ;
#endif
V_162 -> V_220 = V_220 ;
V_162 -> V_237 = V_221 ;
V_162 -> V_238 = 1 ;
}
T_6 * F_106 ( T_1 * V_1 )
{
unsigned long V_239 , V_220 , V_240 ;
T_10 * V_162 ;
int V_62 , V_241 ;
V_162 = V_1 -> V_38 ;
F_97 ( V_162 , V_1 -> V_242 -> V_243 . V_244 ) ;
V_239 = V_1 -> V_242 -> V_243 . V_244 -> V_245 ;
V_241 = F_107 ( V_239 ) ;
V_220 = V_241 ? V_162 -> V_237 : V_162 -> V_220 ;
V_240 = V_239 & ( V_246 | V_247 ) ;
if ( V_240 & V_232 )
V_62 = V_228 ;
else if ( V_240 & V_233 )
V_62 = V_229 ;
else if ( V_240 & V_235 )
V_62 = V_227 ;
else if ( V_240 & V_234 )
{
if ( V_162 -> V_224 [ V_225 ] . V_91 == NULL )
V_62 = V_226 ;
else
V_62 = V_225 ;
}
else
{
F_2 ( V_248 , V_249 ) ;
return ( NULL ) ;
}
if ( V_162 -> V_224 [ V_62 ] . V_91 == NULL ) return ( NULL ) ;
return ( V_162 -> V_224 [ V_62 ] . V_91 ) ;
}
T_12 * F_108 ( T_1 * V_1 , V_27 * V_205 )
{
unsigned long V_239 ;
T_10 * V_162 ;
V_239 = V_205 -> V_245 ;
V_162 = V_1 -> V_38 ;
if ( ( V_239 & V_235 ) &&
( V_162 -> V_224 [ V_227 ] . V_94 != NULL ) )
return ( V_162 -> V_224 [ V_227 ] . V_94 ) ;
else if ( V_239 & V_234 )
{
if ( V_162 -> V_224 [ V_226 ] . V_94 != NULL )
return ( V_162 -> V_224 [ V_226 ] . V_94 ) ;
else if ( V_162 -> V_224 [ V_225 ] . V_94 != NULL )
return ( V_162 -> V_224 [ V_225 ] . V_94 ) ;
else
return ( NULL ) ;
}
else
{
F_2 ( V_250 , V_249 ) ;
return ( NULL ) ;
}
}
void F_109 ( T_1 * V_1 , int V_83 )
{
int V_62 ;
if ( V_1 -> V_21 -> V_171 == 0 ) return;
if ( ( V_1 -> V_19 -> V_128 & V_83 )
&& ( ! V_1 -> V_6 )
&& F_110 ( V_1 -> V_19 , V_1 -> V_21 )
&& ( V_1 -> V_19 -> V_181 != NULL ) )
{
F_13 ( & V_1 -> V_21 -> V_45 , 1 , V_251 ) ;
if ( ! V_1 -> V_19 -> V_181 ( V_1 , V_1 -> V_21 ) )
F_6 ( V_1 -> V_21 ) ;
}
V_62 = V_1 -> V_19 -> V_128 ;
if ( ( ! ( V_62 & V_252 ) ) &&
( ( V_62 & V_83 ) == V_83 ) )
{
if ( ( ( ( V_83 & V_253 )
? V_1 -> V_19 -> V_134 . V_137
: V_1 -> V_19 -> V_134 . V_143 ) & 0xff ) == 0xff )
{
F_87 ( V_1 -> V_19 , time ( NULL ) ) ;
}
}
}
T_3 * F_111 ( T_1 * V_1 )
{
return ( V_1 -> V_3 ) ;
}
int F_112 ( T_1 * V_1 , T_3 * V_26 )
{
int V_254 = - 1 ;
int V_71 = 1 ;
if ( V_1 -> V_3 != V_26 )
{
if ( V_1 -> V_98 != NULL )
V_254 = ( V_1 -> V_98 == V_1 -> V_3 -> V_99 ) ;
if ( V_1 -> V_3 -> V_12 == V_26 -> V_12 )
V_1 -> V_3 = V_26 ;
else
{
V_1 -> V_3 -> V_23 ( V_1 ) ;
V_1 -> V_3 = V_26 ;
V_71 = V_1 -> V_3 -> V_24 ( V_1 ) ;
}
if ( V_254 == 1 )
V_1 -> V_98 = V_26 -> V_99 ;
else if ( V_254 == 0 )
V_1 -> V_98 = V_26 -> V_50 ;
}
return ( V_71 ) ;
}
int F_113 ( T_1 * V_1 , int V_62 )
{
int V_255 ;
unsigned long V_119 ;
T_4 * V_76 ;
if ( V_62 > 0 ) return ( V_256 ) ;
if ( ( V_119 = F_114 () ) != 0 )
{
if ( F_115 ( V_119 ) == V_257 )
return ( V_258 ) ;
else
return ( V_259 ) ;
}
if ( ( V_62 < 0 ) && F_116 ( V_1 ) )
{
V_76 = F_29 ( V_1 ) ;
if ( F_117 ( V_76 ) )
return ( V_260 ) ;
else if ( F_118 ( V_76 ) )
return ( V_261 ) ;
else if ( F_119 ( V_76 ) )
{
V_255 = F_120 ( V_76 ) ;
if ( V_255 == V_262 )
return ( V_263 ) ;
else
return ( V_258 ) ;
}
}
if ( ( V_62 < 0 ) && F_121 ( V_1 ) )
{
V_76 = F_30 ( V_1 ) ;
if ( F_118 ( V_76 ) )
return ( V_261 ) ;
else if ( F_117 ( V_76 ) )
return ( V_260 ) ;
else if ( F_119 ( V_76 ) )
{
V_255 = F_120 ( V_76 ) ;
if ( V_255 == V_262 )
return ( V_263 ) ;
else
return ( V_258 ) ;
}
}
if ( ( V_62 < 0 ) && F_122 ( V_1 ) )
{
return ( V_264 ) ;
}
if ( V_62 == 0 )
{
if ( V_1 -> V_12 == V_265 )
{
return ( V_266 ) ;
}
else
{
if ( ( V_1 -> V_7 & V_105 ) &&
( V_1 -> V_242 -> V_267 == V_268 ) )
return ( V_266 ) ;
}
}
return ( V_258 ) ;
}
int F_123 ( T_1 * V_1 )
{
int V_71 = 1 ;
if ( V_1 -> V_98 == NULL )
{
F_2 ( V_269 , V_270 ) ;
return ( - 1 ) ;
}
V_1 -> V_3 -> V_271 ( V_1 ) ;
if ( F_64 ( V_1 ) || F_124 ( V_1 ) )
{
V_71 = V_1 -> V_98 ( V_1 ) ;
}
return ( V_71 ) ;
}
void F_56 ( T_1 * V_1 )
{
V_1 -> V_9 = 1 ;
V_1 -> V_7 = 0 ;
V_1 -> V_2 = V_10 | V_8 ;
V_1 -> V_98 = V_1 -> V_3 -> V_50 ;
F_4 ( V_1 ) ;
}
void F_58 ( T_1 * V_1 )
{
V_1 -> V_9 = 0 ;
V_1 -> V_7 = 0 ;
V_1 -> V_2 = V_11 | V_8 ;
V_1 -> V_98 = V_1 -> V_3 -> V_99 ;
F_4 ( V_1 ) ;
}
int V_51 ( T_1 * V_1 )
{
F_2 ( V_272 , V_273 ) ;
return ( 0 ) ;
}
T_3 * F_125 ( int V_274 )
{
F_2 ( V_275 , V_273 ) ;
return ( NULL ) ;
}
char * F_126 ( T_1 * V_1 )
{
if ( V_1 -> V_12 == V_276 )
return ( L_9 ) ;
else if ( V_1 -> V_12 == V_277 )
return ( L_10 ) ;
else if ( V_1 -> V_12 == V_265 )
return ( L_11 ) ;
else
return ( L_12 ) ;
}
T_1 * F_127 ( T_1 * V_1 )
{
F_8 ( V_278 ) * V_28 ;
V_278 * V_279 ;
T_1 * V_71 ;
int V_62 ;
if ( ( V_71 = F_11 ( F_128 ( V_1 ) ) ) == NULL )
return ( NULL ) ;
if ( V_1 -> V_21 != NULL )
{
F_129 ( V_71 , V_1 ) ;
}
else
{
V_71 -> V_3 = V_1 -> V_3 ;
V_71 -> V_3 -> V_24 ( V_71 ) ;
if ( V_1 -> V_38 != NULL )
{
V_71 -> V_38 = F_12 ( V_1 -> V_38 ) ;
if ( V_71 -> V_38 == NULL )
goto V_37;
}
F_18 ( V_71 ,
V_1 -> V_40 , V_1 -> V_39 ) ;
}
F_48 ( V_71 , F_49 ( V_1 ) ) ;
F_45 ( V_71 , F_41 ( V_1 ) ,
F_130 ( V_1 ) ) ;
F_47 ( V_71 , F_42 ( V_1 ) ) ;
F_131 ( V_71 , F_132 ( V_1 ) ) ;
V_71 -> V_280 = V_1 -> V_280 ;
V_71 -> V_52 = V_1 -> V_52 ;
if ( ! F_133 ( V_53 , & V_71 -> V_54 , & V_1 -> V_54 ) )
goto V_37;
if ( V_1 -> V_67 != NULL )
{
if ( ! F_134 ( V_1 -> V_67 , ( char * ) & V_71 -> V_67 ) )
goto V_37;
}
if ( V_1 -> V_66 != NULL )
{
if ( V_1 -> V_66 != V_1 -> V_67 )
{
if ( ! F_134 ( V_1 -> V_66 , ( char * ) & V_71 -> V_66 ) )
goto V_37;
}
else
V_71 -> V_66 = V_71 -> V_67 ;
}
if ( V_1 -> V_29 != NULL )
{
if ( ( V_71 -> V_29 = F_135 ( V_1 -> V_29 ) ) == NULL )
goto V_37;
}
if ( V_1 -> V_30 != NULL )
if ( ( V_71 -> V_30 = F_135 ( V_1 -> V_30 ) )
== NULL )
goto V_37;
if ( V_1 -> V_68 != NULL )
{
if ( ( V_28 = F_136 ( V_1 -> V_68 ) ) == NULL ) goto V_37;
V_71 -> V_68 = V_28 ;
for ( V_62 = 0 ; V_62 < F_137 ( V_28 ) ; V_62 ++ )
{
V_279 = F_138 ( V_28 , V_62 ) ;
if ( F_139 ( V_28 , V_62 , F_140 ( V_279 ) ) == NULL )
{
V_69 ( V_279 ) ;
goto V_37;
}
}
}
V_71 -> V_7 = V_1 -> V_7 ;
V_71 -> V_2 = V_1 -> V_2 ;
V_71 -> V_98 = V_1 -> V_98 ;
V_71 -> V_9 = V_1 -> V_9 ;
if ( 0 )
{
V_37:
if ( V_71 != NULL ) F_19 ( V_71 ) ;
V_71 = NULL ;
}
return ( V_71 ) ;
}
void F_4 ( T_1 * V_1 )
{
if ( V_1 -> V_281 != NULL )
{
F_141 ( V_1 -> V_281 ) ;
Free ( V_1 -> V_281 ) ;
V_1 -> V_281 = NULL ;
}
if ( V_1 -> V_282 != NULL )
{
F_141 ( V_1 -> V_282 ) ;
Free ( V_1 -> V_282 ) ;
V_1 -> V_282 = NULL ;
}
if ( V_1 -> V_283 != NULL )
{
F_142 ( V_1 -> V_283 ) ;
V_1 -> V_283 = NULL ;
}
if ( V_1 -> V_284 != NULL )
{
F_142 ( V_1 -> V_284 ) ;
V_1 -> V_284 = NULL ;
}
}
T_6 * F_143 ( T_1 * V_1 )
{
if ( V_1 -> V_38 != NULL )
return ( V_1 -> V_38 -> V_90 -> V_91 ) ;
else
return ( NULL ) ;
}
T_12 * F_144 ( T_1 * V_1 )
{
if ( V_1 -> V_38 != NULL )
return ( V_1 -> V_38 -> V_90 -> V_94 ) ;
else
return ( NULL ) ;
}
V_27 * F_145 ( T_1 * V_1 )
{
if ( ( V_1 -> V_21 != NULL ) && ( V_1 -> V_21 -> V_205 != NULL ) )
return ( V_1 -> V_21 -> V_205 ) ;
return ( NULL ) ;
}
int F_146 ( T_1 * V_1 , int V_285 )
{
T_4 * V_65 ;
if ( V_1 -> V_65 == NULL )
{
V_65 = F_35 ( F_147 () ) ;
if ( V_65 == NULL ) return ( 0 ) ;
V_1 -> V_65 = V_65 ;
}
else
{
V_65 = V_1 -> V_65 ;
if ( V_1 -> V_65 == V_1 -> V_66 )
V_1 -> V_66 = F_23 ( V_1 -> V_66 ) ;
}
F_148 ( V_65 ) ;
if ( ! F_149 ( V_65 , 1 ) )
{
F_2 ( V_286 , V_78 ) ;
return ( 0 ) ;
}
if ( V_285 )
{
if ( V_1 -> V_66 != V_65 )
V_1 -> V_66 = F_150 ( V_65 , V_1 -> V_66 ) ;
}
else
{
if ( V_1 -> V_66 == V_65 )
V_1 -> V_66 = F_23 ( V_65 ) ;
}
return ( 1 ) ;
}
void F_151 ( T_1 * V_1 )
{
T_4 * V_287 ;
if ( V_1 -> V_65 == NULL ) return;
if ( V_1 -> V_65 == V_1 -> V_66 )
{
V_287 = F_23 ( V_1 -> V_66 ) ;
if ( V_287 != NULL )
V_1 -> V_66 = V_287 ;
else
abort () ;
}
F_24 ( V_1 -> V_65 ) ;
V_1 -> V_65 = NULL ;
}
void F_152 ( T_2 * V_19 , int V_83 )
{
V_19 -> V_49 = V_83 ;
}
int F_153 ( T_2 * V_19 )
{
return ( V_19 -> V_49 ) ;
}
void F_154 ( T_1 * V_1 , int V_83 )
{
V_1 -> V_49 = V_83 ;
}
int F_155 ( T_1 * V_1 )
{
return ( V_1 -> V_49 ) ;
}
void F_156 ( T_1 * V_1 , int V_83 )
{
V_1 -> V_7 = V_83 ;
}
int F_157 ( T_1 * V_1 )
{
return ( V_1 -> V_7 ) ;
}
int F_158 ( T_1 * V_1 )
{
return ( V_1 -> V_12 ) ;
}
T_2 * F_128 ( T_1 * V_60 )
{
return ( V_60 -> V_19 ) ;
}
int F_159 ( T_2 * V_19 )
{
return ( F_160 ( V_19 -> V_175 ) ) ;
}
int F_161 ( T_2 * V_19 , const char * V_288 ,
const char * V_289 )
{
return ( F_162 ( V_19 -> V_175 , V_288 , V_289 ) ) ;
}
void F_131 ( T_1 * V_60 , void (* V_203)() )
{
V_60 -> V_184 = V_203 ;
}
int F_163 ( T_1 * V_60 )
{
return ( V_60 -> V_2 ) ;
}
void F_164 ( T_1 * V_60 , long V_204 )
{
V_60 -> V_47 = V_204 ;
}
long F_165 ( T_1 * V_60 )
{
return ( V_60 -> V_47 ) ;
}
int F_166 ( long V_290 , char * V_291 , int (* F_167)() ,
int (* F_168)() , void (* F_169)() )
{
V_292 ++ ;
return ( F_170 ( V_292 - 1 ,
& V_53 , V_290 , V_291 , F_167 , F_168 , F_169 ) ) ;
}
int F_171 ( T_1 * V_1 , int V_293 , void * V_204 )
{
return ( F_172 ( & V_1 -> V_54 , V_293 , V_204 ) ) ;
}
void * F_173 ( T_1 * V_1 , int V_293 )
{
return ( F_174 ( & V_1 -> V_54 , V_293 ) ) ;
}
int F_175 ( long V_290 , char * V_291 , int (* F_167)() ,
int (* F_168)() , void (* F_169)() )
{
V_294 ++ ;
return ( F_170 ( V_294 - 1 ,
& V_198 , V_290 , V_291 , F_167 , F_168 , F_169 ) ) ;
}
int F_176 ( T_2 * V_1 , int V_293 , void * V_204 )
{
return ( F_172 ( & V_1 -> V_54 , V_293 , V_204 ) ) ;
}
void * F_177 ( T_2 * V_1 , int V_293 )
{
return ( F_174 ( & V_1 -> V_54 , V_293 ) ) ;
}
int F_178 ( T_1 * V_1 )
{
return ( 1 ) ;
}
T_13 * F_179 ( T_2 * V_19 )
{
return ( V_19 -> V_175 ) ;
}
void F_180 ( T_2 * V_19 , T_13 * V_295 )
{
if ( V_19 -> V_175 != NULL )
F_89 ( V_19 -> V_175 ) ;
V_19 -> V_175 = V_295 ;
}
int F_181 ( T_1 * V_1 )
{
return ( V_1 -> V_14 ) ;
}
void F_182 ( T_2 * V_19 , T_14 * (* V_203)( T_1 * V_60 , int V_241 ,
int V_296 ) )
{ F_67 ( V_19 , V_297 , 0 , ( char * ) V_203 ) ; }
void F_183 ( T_1 * V_60 , T_14 * (* V_203)( T_1 * V_60 , int V_241 ,
int V_296 ) )
{ F_66 ( V_60 , V_297 , 0 , ( char * ) V_203 ) ; }
T_14 * V_203 ( T_1 * V_60 , int V_241 , int V_296 )
{}
void F_184 ( T_2 * V_19 , T_15 * (* F_185)( T_1 * V_60 , int V_241 ,
int V_296 ) )
{ F_67 ( V_19 , V_298 , 0 , ( char * ) F_185 ) ; }
void F_186 ( T_1 * V_60 , T_15 * (* F_185)( T_1 * V_60 , int V_241 ,
int V_296 ) )
{ F_66 ( V_60 , V_298 , 0 , ( char * ) F_185 ) ; }
