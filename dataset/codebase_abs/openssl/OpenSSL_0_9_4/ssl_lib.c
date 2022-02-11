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
V_1 -> V_53 = V_19 -> V_53 ;
F_1 ( V_1 ) ;
F_14 ( V_54 , ( char * ) V_1 , & V_1 -> V_55 ) ;
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
F_2 ( V_34 , V_56 ) ;
return ( NULL ) ;
}
int F_17 ( T_2 * V_19 , const unsigned char * V_40 ,
unsigned int V_57 )
{
if( V_57 > V_58 )
{
F_2 ( V_59 , V_60 ) ;
return 0 ;
}
V_19 -> V_39 = V_57 ;
memcpy ( V_19 -> V_40 , V_40 , V_57 ) ;
return 1 ;
}
int F_18 ( T_1 * V_61 , const unsigned char * V_40 ,
unsigned int V_57 )
{
if( V_57 > V_58 )
{
F_2 ( V_62 , V_60 ) ;
return 0 ;
}
V_61 -> V_39 = V_57 ;
memcpy ( V_61 -> V_40 , V_40 , V_57 ) ;
return 1 ;
}
void F_19 ( T_1 * V_1 )
{
int V_63 ;
if( V_1 == NULL )
return;
V_63 = F_13 ( & V_1 -> V_45 , - 1 , V_64 ) ;
#ifdef F_20
F_20 ( L_1 , V_1 ) ;
#endif
if ( V_63 > 0 ) return;
#ifdef F_21
if ( V_63 < 0 )
{
fprintf ( V_65 , L_2 ) ;
abort () ;
}
#endif
F_22 ( V_54 , ( char * ) V_1 , & V_1 -> V_55 ) ;
if ( V_1 -> V_66 != NULL )
{
if ( V_1 -> V_66 == V_1 -> V_67 )
{
V_1 -> V_67 = F_23 ( V_1 -> V_67 ) ;
}
F_24 ( V_1 -> V_66 ) ;
V_1 -> V_66 = NULL ;
}
if ( V_1 -> V_68 != NULL )
F_25 ( V_1 -> V_68 ) ;
if ( ( V_1 -> V_67 != NULL ) && ( V_1 -> V_67 != V_1 -> V_68 ) )
F_25 ( V_1 -> V_67 ) ;
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
if ( V_1 -> V_69 != NULL )
F_27 ( V_1 -> V_69 , V_70 ) ;
if ( V_1 -> V_3 != NULL ) V_1 -> V_3 -> V_23 ( V_1 ) ;
Free ( ( char * ) V_1 ) ;
}
void F_28 ( T_1 * V_1 , T_4 * V_68 , T_4 * V_67 )
{
if ( V_1 -> V_66 != NULL )
{
if ( V_1 -> V_67 == V_1 -> V_66 )
{
V_1 -> V_67 = V_1 -> V_67 -> V_71 ;
V_1 -> V_66 -> V_71 = NULL ;
}
}
if ( ( V_1 -> V_68 != NULL ) && ( V_1 -> V_68 != V_68 ) )
F_25 ( V_1 -> V_68 ) ;
if ( ( V_1 -> V_67 != NULL ) && ( V_1 -> V_67 != V_67 ) && ( V_1 -> V_68 != V_1 -> V_67 ) )
F_25 ( V_1 -> V_67 ) ;
V_1 -> V_68 = V_68 ;
V_1 -> V_67 = V_67 ;
}
T_4 * F_29 ( T_1 * V_1 )
{ return ( V_1 -> V_68 ) ; }
T_4 * F_30 ( T_1 * V_1 )
{ return ( V_1 -> V_67 ) ; }
int F_31 ( T_1 * V_1 )
{
int V_72 = - 1 ;
T_4 * V_73 , * V_74 ;
V_73 = F_29 ( V_1 ) ;
V_74 = F_32 ( V_73 , V_75 ) ;
if ( V_74 != NULL )
F_33 ( V_74 , & V_72 ) ;
return ( V_72 ) ;
}
int F_34 ( T_1 * V_1 , int V_76 )
{
int V_72 = 0 ;
T_4 * V_77 = NULL ;
V_77 = F_35 ( F_36 () ) ;
if ( V_77 == NULL )
{
F_2 ( V_78 , V_79 ) ;
goto V_37;
}
F_37 ( V_77 , V_76 , V_80 ) ;
F_28 ( V_1 , V_77 , V_77 ) ;
V_72 = 1 ;
V_37:
return ( V_72 ) ;
}
int F_38 ( T_1 * V_1 , int V_76 )
{
int V_72 = 0 ;
T_4 * V_77 = NULL ;
if ( ( V_1 -> V_68 == NULL ) || ( F_39 ( V_1 -> V_68 ) != V_81 )
|| ( ( int ) F_33 ( V_1 -> V_68 , NULL ) != V_76 ) )
{
V_77 = F_35 ( F_36 () ) ;
if ( V_77 == NULL )
{ F_2 ( V_82 , V_79 ) ; goto V_37; }
F_37 ( V_77 , V_76 , V_80 ) ;
F_28 ( V_1 , F_29 ( V_1 ) , V_77 ) ;
}
else
F_28 ( V_1 , F_29 ( V_1 ) , F_29 ( V_1 ) ) ;
V_72 = 1 ;
V_37:
return ( V_72 ) ;
}
int F_40 ( T_1 * V_1 , int V_76 )
{
int V_72 = 0 ;
T_4 * V_77 = NULL ;
if ( ( V_1 -> V_67 == NULL ) || ( F_39 ( V_1 -> V_67 ) != V_81 )
|| ( ( int ) F_33 ( V_1 -> V_67 , NULL ) != V_76 ) )
{
V_77 = F_35 ( F_36 () ) ;
if ( V_77 == NULL )
{
F_2 ( V_83 , V_79 ) ;
goto V_37;
}
F_37 ( V_77 , V_76 , V_80 ) ;
F_28 ( V_1 , V_77 , F_30 ( V_1 ) ) ;
}
else
F_28 ( V_1 , F_30 ( V_1 ) , F_30 ( V_1 ) ) ;
V_72 = 1 ;
V_37:
return ( V_72 ) ;
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
void F_45 ( T_1 * V_1 , int V_53 ,
int (* F_46)( int V_84 , T_5 * V_19 ) )
{
V_1 -> V_41 = V_53 ;
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
T_6 * V_74 ;
if ( ( V_1 == NULL ) || ( V_1 -> V_21 == NULL ) )
V_74 = NULL ;
else
V_74 = V_1 -> V_21 -> V_88 ;
if ( V_74 == NULL ) return ( V_74 ) ;
F_13 ( & V_74 -> V_45 , 1 , V_89 ) ;
return ( V_74 ) ;
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
int F_54 ( T_1 * V_61 )
{
if ( V_61 == NULL )
{
F_2 ( V_96 , V_97 ) ;
return ( 0 ) ;
}
if ( V_61 -> V_38 == NULL )
{
F_2 ( V_96 , V_93 ) ;
return 0 ;
}
if ( V_61 -> V_38 -> V_90 -> V_91 == NULL )
{
F_2 ( V_96 , V_93 ) ;
return ( 0 ) ;
}
if ( V_61 -> V_38 -> V_90 -> V_94 == NULL )
{
F_2 ( V_96 , V_95 ) ;
return ( 0 ) ;
}
return ( F_53 ( V_61 -> V_38 -> V_90 -> V_91 ,
V_61 -> V_38 -> V_90 -> V_94 ) ) ;
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
case V_123 :
return ( V_1 -> V_53 |= V_117 ) ;
default:
return ( V_1 -> V_3 -> V_124 ( V_1 , V_116 , V_117 , V_118 ) ) ;
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
case V_125 :
V_119 = V_19 -> V_126 ;
V_19 -> V_126 = V_117 ;
return ( V_119 ) ;
case V_127 :
return ( V_19 -> V_126 ) ;
case V_128 :
V_119 = V_19 -> V_129 ;
V_19 -> V_129 = V_117 ;
return ( V_119 ) ;
case V_130 :
return ( V_19 -> V_129 ) ;
case V_131 :
return ( V_19 -> V_132 -> V_133 ) ;
case V_134 :
return ( V_19 -> V_135 . V_136 ) ;
case V_137 :
return ( V_19 -> V_135 . V_138 ) ;
case V_139 :
return ( V_19 -> V_135 . V_140 ) ;
case V_141 :
return ( V_19 -> V_135 . V_142 ) ;
case V_143 :
return ( V_19 -> V_135 . V_144 ) ;
case V_145 :
return ( V_19 -> V_135 . V_146 ) ;
case V_147 :
return ( V_19 -> V_135 . V_148 ) ;
case V_149 :
return ( V_19 -> V_135 . V_150 ) ;
case V_151 :
return ( V_19 -> V_135 . V_152 ) ;
case V_153 :
return ( V_19 -> V_135 . V_154 ) ;
case V_155 :
return ( V_19 -> V_135 . V_156 ) ;
case V_122 :
return ( V_19 -> V_52 |= V_117 ) ;
case V_123 :
return ( V_19 -> V_53 |= V_117 ) ;
default:
return ( V_19 -> V_3 -> V_157 ( V_19 , V_116 , V_117 , V_118 ) ) ;
}
}
int F_68 ( V_27 * V_158 , V_27 * V_73 )
{
long V_119 ;
V_119 = V_158 -> V_159 - V_73 -> V_159 ;
if ( V_119 == 0L )
return ( 0 ) ;
else
return ( ( V_119 > 0 ) ? 1 : - 1 ) ;
}
int F_69 ( V_27 * * V_160 , V_27 * * V_161 )
{
long V_119 ;
V_119 = ( * V_160 ) -> V_159 - ( * V_161 ) -> V_159 ;
if ( V_119 == 0L )
return ( 0 ) ;
else
return ( ( V_119 > 0 ) ? 1 : - 1 ) ;
}
char * F_70 ( T_1 * V_1 , int V_162 )
{
V_27 * V_163 ;
F_8 ( V_27 ) * V_28 ;
if ( V_1 == NULL ) return ( NULL ) ;
V_28 = F_71 ( V_1 ) ;
if ( ( V_28 == NULL ) || ( F_10 ( V_28 ) <= V_162 ) )
return ( NULL ) ;
V_163 = F_72 ( V_28 , V_162 ) ;
if ( V_163 == NULL ) return ( NULL ) ;
return ( V_163 -> V_164 ) ;
}
int F_73 ( T_2 * V_19 , char * V_165 )
{
F_8 ( V_27 ) * V_28 ;
V_28 = F_9 ( V_19 -> V_3 , & V_19 -> V_29 ,
& V_19 -> V_30 , V_165 ) ;
return ( ( V_28 == NULL ) ? 0 : 1 ) ;
}
int F_74 ( T_1 * V_1 , char * V_165 )
{
F_8 ( V_27 ) * V_28 ;
V_28 = F_9 ( V_1 -> V_19 -> V_3 , & V_1 -> V_29 ,
& V_1 -> V_30 , V_165 ) ;
return ( ( V_28 == NULL ) ? 0 : 1 ) ;
}
char * F_75 ( T_1 * V_1 , char * V_101 , int V_166 )
{
char * V_167 ;
const char * V_168 ;
F_8 ( V_27 ) * V_28 ;
V_27 * V_163 ;
int V_63 ;
if ( ( V_1 -> V_21 == NULL ) || ( V_1 -> V_21 -> V_169 == NULL ) ||
( V_166 < 2 ) )
return ( NULL ) ;
V_167 = V_101 ;
V_28 = V_1 -> V_21 -> V_169 ;
for ( V_63 = 0 ; V_63 < F_10 ( V_28 ) ; V_63 ++ )
{
V_166 -- ;
V_163 = F_72 ( V_28 , V_63 ) ;
for ( V_168 = V_163 -> V_164 ; * V_168 ; )
{
if ( V_166 -- == 0 )
{
* V_167 = '\0' ;
return ( V_101 ) ;
}
else
* ( V_167 ++ ) = * ( V_168 ++ ) ;
}
* ( V_167 ++ ) = ':' ;
}
V_167 [ - 1 ] = '\0' ;
return ( V_101 ) ;
}
long F_76 ( T_7 * V_158 )
{
unsigned long V_119 ;
V_119 = ( unsigned long )
( ( unsigned int ) V_158 -> V_170 [ 0 ] ) |
( ( unsigned int ) V_158 -> V_170 [ 1 ] << 8L ) |
( ( unsigned long ) V_158 -> V_170 [ 2 ] << 16L ) |
( ( unsigned long ) V_158 -> V_170 [ 3 ] << 24L ) ;
return ( V_119 ) ;
}
int F_77 ( T_7 * V_158 , T_7 * V_73 )
{
if ( V_158 -> V_171 != V_73 -> V_171 )
return ( 1 ) ;
if ( V_158 -> V_172 != V_73 -> V_172 )
return ( 1 ) ;
return ( memcmp ( V_158 -> V_170 , V_73 -> V_170 , V_158 -> V_172 ) ) ;
}
T_2 * F_78 ( T_3 * V_26 )
{
T_2 * V_72 = NULL ;
if ( V_26 == NULL )
{
F_2 ( V_173 , V_174 ) ;
return ( NULL ) ;
}
if ( F_79 () < 0 )
{
F_2 ( V_173 , V_175 ) ;
goto V_37;
}
V_72 = ( T_2 * ) Malloc ( sizeof( T_2 ) ) ;
if ( V_72 == NULL )
goto V_37;
memset ( V_72 , 0 , sizeof( T_2 ) ) ;
V_72 -> V_3 = V_26 ;
V_72 -> V_176 = NULL ;
V_72 -> V_129 = V_177 ;
V_72 -> V_126 = V_178 ;
V_72 -> V_179 = NULL ;
V_72 -> V_180 = NULL ;
V_72 -> V_181 = V_26 -> V_100 () ;
V_72 -> V_182 = NULL ;
V_72 -> V_183 = NULL ;
V_72 -> V_184 = NULL ;
memset ( ( char * ) & V_72 -> V_135 , 0 , sizeof( V_72 -> V_135 ) ) ;
V_72 -> V_45 = 1 ;
V_72 -> V_49 = 0 ;
V_72 -> V_185 = NULL ;
V_72 -> V_186 = NULL ;
V_72 -> V_187 = NULL ;
V_72 -> V_18 = 0 ;
V_72 -> V_41 = V_188 ;
V_72 -> V_42 = - 1 ;
V_72 -> V_44 = NULL ;
if ( ( V_72 -> V_38 = F_80 () ) == NULL )
goto V_37;
V_72 -> V_189 = NULL ;
V_72 -> V_190 = NULL ;
V_72 -> V_191 = NULL ;
V_72 -> V_132 = F_81 ( F_76 , F_77 ) ;
if ( V_72 -> V_132 == NULL ) goto V_37;
V_72 -> V_176 = F_82 () ;
if ( V_72 -> V_176 == NULL ) goto V_37;
F_9 ( V_72 -> V_3 ,
& V_72 -> V_29 , & V_72 -> V_30 ,
V_31 ) ;
if ( V_72 -> V_29 == NULL
|| F_10 ( V_72 -> V_29 ) <= 0 )
{
F_2 ( V_173 , V_192 ) ;
goto V_193;
}
if ( ( V_72 -> V_194 = F_83 ( L_3 ) ) == NULL )
{
F_2 ( V_173 , V_195 ) ;
goto V_193;
}
if ( ( V_72 -> V_196 = F_83 ( L_4 ) ) == NULL )
{
F_2 ( V_173 , V_197 ) ;
goto V_193;
}
if ( ( V_72 -> V_198 = F_83 ( L_5 ) ) == NULL )
{
F_2 ( V_173 , V_199 ) ;
goto V_193;
}
if ( ( V_72 -> V_69 = F_84 () ) == NULL )
goto V_37;
F_14 ( V_200 , ( char * ) V_72 , & V_72 -> V_55 ) ;
V_72 -> V_201 = NULL ;
V_72 -> V_202 = F_85 () ;
return ( V_72 ) ;
V_37:
F_2 ( V_173 , V_56 ) ;
V_193:
if ( V_72 != NULL ) F_16 ( V_72 ) ;
return ( NULL ) ;
}
static void F_86 ( T_8 * V_203 )
{ Free ( V_203 ) ; }
void F_16 ( T_2 * V_158 )
{
int V_63 ;
if ( V_158 == NULL ) return;
V_63 = F_13 ( & V_158 -> V_45 , - 1 , V_46 ) ;
#ifdef F_20
F_20 ( L_6 , V_158 ) ;
#endif
if ( V_63 > 0 ) return;
#ifdef F_21
if ( V_63 < 0 )
{
fprintf ( V_65 , L_7 ) ;
abort () ;
}
#endif
F_22 ( V_200 , ( char * ) V_158 , & V_158 -> V_55 ) ;
if ( V_158 -> V_132 != NULL )
{
F_87 ( V_158 , 0 ) ;
F_88 ( V_158 -> V_132 ) ;
}
if ( V_158 -> V_176 != NULL )
F_89 ( V_158 -> V_176 ) ;
if ( V_158 -> V_29 != NULL )
F_26 ( V_158 -> V_29 ) ;
if ( V_158 -> V_30 != NULL )
F_26 ( V_158 -> V_30 ) ;
if ( V_158 -> V_38 != NULL )
F_15 ( V_158 -> V_38 ) ;
if ( V_158 -> V_69 != NULL )
F_27 ( V_158 -> V_69 , V_70 ) ;
if ( V_158 -> V_201 != NULL )
F_90 ( V_158 -> V_201 , V_204 ) ;
if ( V_158 -> V_202 != NULL )
F_91 ( V_158 -> V_202 , F_86 ) ;
Free ( ( char * ) V_158 ) ;
}
void F_92 ( T_2 * V_19 , T_9 * V_205 )
{
V_19 -> V_189 = V_205 ;
}
void F_93 ( T_2 * V_19 , void * V_206 )
{
V_19 -> V_190 = V_206 ;
}
void F_94 ( T_2 * V_19 , int (* V_205)() , char * V_207 )
{
V_19 -> V_186 = V_205 ;
V_19 -> V_187 = V_207 ;
}
void F_95 ( T_2 * V_19 , int V_53 , int (* V_205)( int , T_5 * ) )
{
V_19 -> V_41 = V_53 ;
V_19 -> V_44 = V_205 ;
F_96 ( V_19 -> V_176 , V_205 ) ;
}
void F_97 ( T_2 * V_19 , int V_85 )
{
V_19 -> V_42 = V_85 ;
}
void F_98 ( T_10 * V_163 , V_27 * V_208 )
{
T_11 * V_209 ;
int V_210 , V_211 , V_212 , V_213 , V_214 , V_215 , V_216 ;
int V_217 , V_218 , V_219 ;
int V_220 , V_221 , V_222 ;
unsigned long V_223 , V_224 ;
if ( V_163 == NULL ) return;
V_222 = F_99 ( V_208 ) ;
#ifndef F_100
V_211 = ( V_163 -> V_211 != NULL || V_163 -> V_225 != NULL ) ;
V_220 = ( V_163 -> V_225 != NULL ||
( V_211 && F_101 ( V_163 -> V_211 ) * 8 <= V_222 ) ) ;
#else
V_211 = V_220 = 0 ;
#endif
#ifndef F_102
V_213 = ( V_163 -> V_213 != NULL || V_163 -> V_226 != NULL ) ;
V_221 = ( V_163 -> V_226 != NULL ||
( V_213 && F_103 ( V_163 -> V_213 ) * 8 <= V_222 ) ) ;
#else
V_213 = V_221 = 0 ;
#endif
V_209 = & ( V_163 -> V_227 [ V_228 ] ) ;
V_210 = ( V_209 -> V_91 != NULL && V_209 -> V_94 != NULL ) ;
V_217 = ( V_210 && F_104 ( V_209 -> V_94 ) * 8 <= V_222 ) ;
V_209 = & ( V_163 -> V_227 [ V_229 ] ) ;
V_212 = ( V_209 -> V_91 != NULL && V_209 -> V_94 != NULL ) ;
V_209 = & ( V_163 -> V_227 [ V_230 ] ) ;
V_216 = ( V_209 -> V_91 != NULL && V_209 -> V_94 != NULL ) ;
V_209 = & ( V_163 -> V_227 [ V_231 ] ) ;
V_214 = ( V_209 -> V_91 != NULL && V_209 -> V_94 != NULL ) ;
V_218 = ( V_214 && F_104 ( V_209 -> V_94 ) * 8 <= V_222 ) ;
V_209 = & ( V_163 -> V_227 [ V_232 ] ) ;
V_215 = ( V_209 -> V_91 != NULL && V_209 -> V_94 != NULL ) ;
V_219 = ( V_215 && F_104 ( V_209 -> V_94 ) * 8 <= V_222 ) ;
V_223 = 0 ;
V_224 = 0 ;
#ifdef F_105
printf ( L_8 ,
V_211 , V_220 , V_213 ,
V_210 , V_217 , V_212 , V_216 , V_214 , V_215 ) ;
#endif
if ( V_210 || ( V_211 && V_212 ) )
V_223 |= V_233 ;
if ( V_217 || ( V_220 && ( V_212 || V_210 ) ) )
V_224 |= V_233 ;
#if 0
if ( (dh_tmp || dh_rsa || dh_dsa) &&
(rsa_enc || rsa_sign || dsa_sign))
mask|=SSL_kEDH;
if ((dh_tmp_export || dh_rsa_export || dh_dsa_export) &&
(rsa_enc || rsa_sign || dsa_sign))
emask|=SSL_kEDH;
#endif
if ( V_221 )
V_224 |= V_234 ;
if ( V_213 )
V_223 |= V_234 ;
if ( V_214 ) V_223 |= V_235 ;
if ( V_218 ) V_224 |= V_235 ;
if ( V_215 ) V_223 |= V_236 ;
if ( V_219 ) V_224 |= V_236 ;
if ( V_210 || V_212 )
{
V_223 |= V_237 ;
V_224 |= V_237 ;
}
if ( V_216 )
{
V_223 |= V_238 ;
V_224 |= V_238 ;
}
#ifdef F_106
V_223 |= V_239 ;
V_224 |= V_239 ;
#endif
V_163 -> V_223 = V_223 ;
V_163 -> V_240 = V_224 ;
V_163 -> V_241 = 1 ;
}
T_6 * F_107 ( T_1 * V_1 )
{
unsigned long V_242 , V_223 , V_243 ;
T_10 * V_163 ;
int V_63 , V_244 ;
V_163 = V_1 -> V_38 ;
F_98 ( V_163 , V_1 -> V_245 -> V_246 . V_247 ) ;
V_242 = V_1 -> V_245 -> V_246 . V_247 -> V_248 ;
V_244 = F_108 ( V_242 ) ;
V_223 = V_244 ? V_163 -> V_240 : V_163 -> V_223 ;
V_243 = V_242 & ( V_249 | V_250 ) ;
if ( V_243 & V_235 )
V_63 = V_231 ;
else if ( V_243 & V_236 )
V_63 = V_232 ;
else if ( V_243 & V_238 )
V_63 = V_230 ;
else if ( V_243 & V_237 )
{
if ( V_163 -> V_227 [ V_228 ] . V_91 == NULL )
V_63 = V_229 ;
else
V_63 = V_228 ;
}
else
{
F_2 ( V_251 , V_252 ) ;
return ( NULL ) ;
}
if ( V_163 -> V_227 [ V_63 ] . V_91 == NULL ) return ( NULL ) ;
return ( V_163 -> V_227 [ V_63 ] . V_91 ) ;
}
T_12 * F_109 ( T_1 * V_1 , V_27 * V_208 )
{
unsigned long V_242 ;
T_10 * V_163 ;
V_242 = V_208 -> V_248 ;
V_163 = V_1 -> V_38 ;
if ( ( V_242 & V_238 ) &&
( V_163 -> V_227 [ V_230 ] . V_94 != NULL ) )
return ( V_163 -> V_227 [ V_230 ] . V_94 ) ;
else if ( V_242 & V_237 )
{
if ( V_163 -> V_227 [ V_229 ] . V_94 != NULL )
return ( V_163 -> V_227 [ V_229 ] . V_94 ) ;
else if ( V_163 -> V_227 [ V_228 ] . V_94 != NULL )
return ( V_163 -> V_227 [ V_228 ] . V_94 ) ;
else
return ( NULL ) ;
}
else
{
F_2 ( V_253 , V_252 ) ;
return ( NULL ) ;
}
}
void F_110 ( T_1 * V_1 , int V_53 )
{
int V_63 ;
if ( V_1 -> V_21 -> V_172 == 0 ) return;
if ( ( V_1 -> V_19 -> V_129 & V_53 )
&& ( ! V_1 -> V_6 )
&& F_111 ( V_1 -> V_19 , V_1 -> V_21 )
&& ( V_1 -> V_19 -> V_182 != NULL ) )
{
F_13 ( & V_1 -> V_21 -> V_45 , 1 , V_254 ) ;
if ( ! V_1 -> V_19 -> V_182 ( V_1 , V_1 -> V_21 ) )
F_6 ( V_1 -> V_21 ) ;
}
V_63 = V_1 -> V_19 -> V_129 ;
if ( ( ! ( V_63 & V_255 ) ) &&
( ( V_63 & V_53 ) == V_53 ) )
{
if ( ( ( ( V_53 & V_256 )
? V_1 -> V_19 -> V_135 . V_138
: V_1 -> V_19 -> V_135 . V_144 ) & 0xff ) == 0xff )
{
F_87 ( V_1 -> V_19 , time ( NULL ) ) ;
}
}
}
T_3 * F_112 ( T_1 * V_1 )
{
return ( V_1 -> V_3 ) ;
}
int F_113 ( T_1 * V_1 , T_3 * V_26 )
{
int V_257 = - 1 ;
int V_72 = 1 ;
if ( V_1 -> V_3 != V_26 )
{
if ( V_1 -> V_98 != NULL )
V_257 = ( V_1 -> V_98 == V_1 -> V_3 -> V_99 ) ;
if ( V_1 -> V_3 -> V_12 == V_26 -> V_12 )
V_1 -> V_3 = V_26 ;
else
{
V_1 -> V_3 -> V_23 ( V_1 ) ;
V_1 -> V_3 = V_26 ;
V_72 = V_1 -> V_3 -> V_24 ( V_1 ) ;
}
if ( V_257 == 1 )
V_1 -> V_98 = V_26 -> V_99 ;
else if ( V_257 == 0 )
V_1 -> V_98 = V_26 -> V_50 ;
}
return ( V_72 ) ;
}
int F_114 ( T_1 * V_1 , int V_63 )
{
int V_258 ;
unsigned long V_119 ;
T_4 * V_77 ;
if ( V_63 > 0 ) return ( V_259 ) ;
if ( ( V_119 = F_115 () ) != 0 )
{
if ( F_116 ( V_119 ) == V_260 )
return ( V_261 ) ;
else
return ( V_262 ) ;
}
if ( ( V_63 < 0 ) && F_117 ( V_1 ) )
{
V_77 = F_29 ( V_1 ) ;
if ( F_118 ( V_77 ) )
return ( V_263 ) ;
else if ( F_119 ( V_77 ) )
return ( V_264 ) ;
else if ( F_120 ( V_77 ) )
{
V_258 = F_121 ( V_77 ) ;
if ( V_258 == V_265 )
return ( V_266 ) ;
else
return ( V_261 ) ;
}
}
if ( ( V_63 < 0 ) && F_122 ( V_1 ) )
{
V_77 = F_30 ( V_1 ) ;
if ( F_119 ( V_77 ) )
return ( V_264 ) ;
else if ( F_118 ( V_77 ) )
return ( V_263 ) ;
else if ( F_120 ( V_77 ) )
{
V_258 = F_121 ( V_77 ) ;
if ( V_258 == V_265 )
return ( V_266 ) ;
else
return ( V_261 ) ;
}
}
if ( ( V_63 < 0 ) && F_123 ( V_1 ) )
{
return ( V_267 ) ;
}
if ( V_63 == 0 )
{
if ( V_1 -> V_12 == V_268 )
{
return ( V_269 ) ;
}
else
{
if ( ( V_1 -> V_7 & V_105 ) &&
( V_1 -> V_245 -> V_270 == V_271 ) )
return ( V_269 ) ;
}
}
return ( V_261 ) ;
}
int F_124 ( T_1 * V_1 )
{
int V_72 = 1 ;
if ( V_1 -> V_98 == NULL )
{
F_2 ( V_272 , V_273 ) ;
return ( - 1 ) ;
}
V_1 -> V_3 -> V_274 ( V_1 ) ;
if ( F_64 ( V_1 ) || F_125 ( V_1 ) )
{
V_72 = V_1 -> V_98 ( V_1 ) ;
}
return ( V_72 ) ;
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
F_2 ( V_275 , V_276 ) ;
return ( 0 ) ;
}
T_3 * F_126 ( int V_277 )
{
F_2 ( V_278 , V_276 ) ;
return ( NULL ) ;
}
char * F_127 ( T_1 * V_1 )
{
if ( V_1 -> V_12 == V_279 )
return ( L_9 ) ;
else if ( V_1 -> V_12 == V_280 )
return ( L_10 ) ;
else if ( V_1 -> V_12 == V_268 )
return ( L_11 ) ;
else
return ( L_12 ) ;
}
T_1 * F_128 ( T_1 * V_1 )
{
F_8 ( V_281 ) * V_28 ;
V_281 * V_282 ;
T_1 * V_72 ;
int V_63 ;
if ( ( V_72 = F_11 ( F_129 ( V_1 ) ) ) == NULL )
return ( NULL ) ;
if ( V_1 -> V_21 != NULL )
{
F_130 ( V_72 , V_1 ) ;
}
else
{
V_72 -> V_3 = V_1 -> V_3 ;
V_72 -> V_3 -> V_24 ( V_72 ) ;
if ( V_1 -> V_38 != NULL )
{
V_72 -> V_38 = F_12 ( V_1 -> V_38 ) ;
if ( V_72 -> V_38 == NULL )
goto V_37;
}
F_18 ( V_72 ,
V_1 -> V_40 , V_1 -> V_39 ) ;
}
F_48 ( V_72 , F_49 ( V_1 ) ) ;
F_45 ( V_72 , F_41 ( V_1 ) ,
F_131 ( V_1 ) ) ;
F_47 ( V_72 , F_42 ( V_1 ) ) ;
F_132 ( V_72 , F_133 ( V_1 ) ) ;
V_72 -> V_283 = V_1 -> V_283 ;
V_72 -> V_52 = V_1 -> V_52 ;
if ( ! F_134 ( V_54 , & V_72 -> V_55 , & V_1 -> V_55 ) )
goto V_37;
if ( V_1 -> V_68 != NULL )
{
if ( ! F_135 ( V_1 -> V_68 , ( char * ) & V_72 -> V_68 ) )
goto V_37;
}
if ( V_1 -> V_67 != NULL )
{
if ( V_1 -> V_67 != V_1 -> V_68 )
{
if ( ! F_135 ( V_1 -> V_67 , ( char * ) & V_72 -> V_67 ) )
goto V_37;
}
else
V_72 -> V_67 = V_72 -> V_68 ;
}
if ( V_1 -> V_29 != NULL )
{
if ( ( V_72 -> V_29 = F_136 ( V_1 -> V_29 ) ) == NULL )
goto V_37;
}
if ( V_1 -> V_30 != NULL )
if ( ( V_72 -> V_30 = F_136 ( V_1 -> V_30 ) )
== NULL )
goto V_37;
if ( V_1 -> V_69 != NULL )
{
if ( ( V_28 = F_137 ( V_1 -> V_69 ) ) == NULL ) goto V_37;
V_72 -> V_69 = V_28 ;
for ( V_63 = 0 ; V_63 < F_138 ( V_28 ) ; V_63 ++ )
{
V_282 = F_139 ( V_28 , V_63 ) ;
if ( F_140 ( V_28 , V_63 , F_141 ( V_282 ) ) == NULL )
{
V_70 ( V_282 ) ;
goto V_37;
}
}
}
V_72 -> V_7 = V_1 -> V_7 ;
V_72 -> V_2 = V_1 -> V_2 ;
V_72 -> V_98 = V_1 -> V_98 ;
V_72 -> V_9 = V_1 -> V_9 ;
if ( 0 )
{
V_37:
if ( V_72 != NULL ) F_19 ( V_72 ) ;
V_72 = NULL ;
}
return ( V_72 ) ;
}
void F_4 ( T_1 * V_1 )
{
if ( V_1 -> V_284 != NULL )
{
F_142 ( V_1 -> V_284 ) ;
Free ( V_1 -> V_284 ) ;
V_1 -> V_284 = NULL ;
}
if ( V_1 -> V_285 != NULL )
{
F_142 ( V_1 -> V_285 ) ;
Free ( V_1 -> V_285 ) ;
V_1 -> V_285 = NULL ;
}
if ( V_1 -> V_286 != NULL )
{
F_143 ( V_1 -> V_286 ) ;
V_1 -> V_286 = NULL ;
}
if ( V_1 -> V_287 != NULL )
{
F_143 ( V_1 -> V_287 ) ;
V_1 -> V_287 = NULL ;
}
}
T_6 * F_144 ( T_1 * V_1 )
{
if ( V_1 -> V_38 != NULL )
return ( V_1 -> V_38 -> V_90 -> V_91 ) ;
else
return ( NULL ) ;
}
T_12 * F_145 ( T_1 * V_1 )
{
if ( V_1 -> V_38 != NULL )
return ( V_1 -> V_38 -> V_90 -> V_94 ) ;
else
return ( NULL ) ;
}
V_27 * F_146 ( T_1 * V_1 )
{
if ( ( V_1 -> V_21 != NULL ) && ( V_1 -> V_21 -> V_208 != NULL ) )
return ( V_1 -> V_21 -> V_208 ) ;
return ( NULL ) ;
}
int F_147 ( T_1 * V_1 , int V_288 )
{
T_4 * V_66 ;
if ( V_1 -> V_66 == NULL )
{
V_66 = F_35 ( F_148 () ) ;
if ( V_66 == NULL ) return ( 0 ) ;
V_1 -> V_66 = V_66 ;
}
else
{
V_66 = V_1 -> V_66 ;
if ( V_1 -> V_66 == V_1 -> V_67 )
V_1 -> V_67 = F_23 ( V_1 -> V_67 ) ;
}
( void ) F_149 ( V_66 ) ;
if ( ! F_150 ( V_66 , 1 ) )
{
F_2 ( V_289 , V_79 ) ;
return ( 0 ) ;
}
if ( V_288 )
{
if ( V_1 -> V_67 != V_66 )
V_1 -> V_67 = F_151 ( V_66 , V_1 -> V_67 ) ;
}
else
{
if ( V_1 -> V_67 == V_66 )
V_1 -> V_67 = F_23 ( V_66 ) ;
}
return ( 1 ) ;
}
void F_152 ( T_1 * V_1 )
{
T_4 * V_290 ;
if ( V_1 -> V_66 == NULL ) return;
if ( V_1 -> V_66 == V_1 -> V_67 )
{
V_290 = F_23 ( V_1 -> V_67 ) ;
if ( V_290 != NULL )
V_1 -> V_67 = V_290 ;
else
abort () ;
}
F_24 ( V_1 -> V_66 ) ;
V_1 -> V_66 = NULL ;
}
void F_153 ( T_2 * V_19 , int V_53 )
{
V_19 -> V_49 = V_53 ;
}
int F_154 ( T_2 * V_19 )
{
return ( V_19 -> V_49 ) ;
}
void F_155 ( T_1 * V_1 , int V_53 )
{
V_1 -> V_49 = V_53 ;
}
int F_156 ( T_1 * V_1 )
{
return ( V_1 -> V_49 ) ;
}
void F_157 ( T_1 * V_1 , int V_53 )
{
V_1 -> V_7 = V_53 ;
}
int F_158 ( T_1 * V_1 )
{
return ( V_1 -> V_7 ) ;
}
int F_159 ( T_1 * V_1 )
{
return ( V_1 -> V_12 ) ;
}
T_2 * F_129 ( T_1 * V_61 )
{
return ( V_61 -> V_19 ) ;
}
int F_160 ( T_2 * V_19 )
{
return ( F_161 ( V_19 -> V_176 ) ) ;
}
int F_162 ( T_2 * V_19 , const char * V_291 ,
const char * V_292 )
{
return ( F_163 ( V_19 -> V_176 , V_291 , V_292 ) ) ;
}
void F_132 ( T_1 * V_61 , void (* V_205)() )
{
V_61 -> V_185 = V_205 ;
}
int F_164 ( T_1 * V_61 )
{
return ( V_61 -> V_2 ) ;
}
void F_165 ( T_1 * V_61 , long V_207 )
{
V_61 -> V_47 = V_207 ;
}
long F_166 ( T_1 * V_61 )
{
return ( V_61 -> V_47 ) ;
}
int F_167 ( long V_293 , char * V_294 , int (* F_168)() ,
int (* F_169)() , void (* F_170)() )
{
V_295 ++ ;
return ( F_171 ( V_295 - 1 ,
& V_54 , V_293 , V_294 , F_168 , F_169 , F_170 ) ) ;
}
int F_172 ( T_1 * V_1 , int V_296 , void * V_207 )
{
return ( F_173 ( & V_1 -> V_55 , V_296 , V_207 ) ) ;
}
void * F_174 ( T_1 * V_1 , int V_296 )
{
return ( F_175 ( & V_1 -> V_55 , V_296 ) ) ;
}
int F_176 ( long V_293 , char * V_294 , int (* F_168)() ,
int (* F_169)() , void (* F_170)() )
{
V_297 ++ ;
return ( F_171 ( V_297 - 1 ,
& V_200 , V_293 , V_294 , F_168 , F_169 , F_170 ) ) ;
}
int F_177 ( T_2 * V_1 , int V_296 , void * V_207 )
{
return ( F_173 ( & V_1 -> V_55 , V_296 , V_207 ) ) ;
}
void * F_178 ( T_2 * V_1 , int V_296 )
{
return ( F_175 ( & V_1 -> V_55 , V_296 ) ) ;
}
int F_179 ( T_1 * V_1 )
{
return ( 1 ) ;
}
T_13 * F_180 ( T_2 * V_19 )
{
return ( V_19 -> V_176 ) ;
}
void F_181 ( T_2 * V_19 , T_13 * V_298 )
{
if ( V_19 -> V_176 != NULL )
F_89 ( V_19 -> V_176 ) ;
V_19 -> V_176 = V_298 ;
}
int F_182 ( T_1 * V_1 )
{
return ( V_1 -> V_14 ) ;
}
void F_183 ( T_2 * V_19 , T_14 * (* V_205)( T_1 * V_61 ,
int V_244 ,
int V_299 ) )
{ F_67 ( V_19 , V_300 , 0 , ( char * ) V_205 ) ; }
void F_184 ( T_1 * V_61 , T_14 * (* V_205)( T_1 * V_61 , int V_244 ,
int V_299 ) )
{ F_66 ( V_61 , V_300 , 0 , ( char * ) V_205 ) ; }
T_14 * V_205 ( T_1 * V_61 , int V_244 , int V_299 )
{}
void F_185 ( T_2 * V_19 , T_15 * (* F_186)( T_1 * V_61 , int V_244 ,
int V_299 ) )
{ F_67 ( V_19 , V_301 , 0 , ( char * ) F_186 ) ; }
void F_187 ( T_1 * V_61 , T_15 * (* F_186)( T_1 * V_61 , int V_244 ,
int V_299 ) )
{ F_66 ( V_61 , V_301 , 0 , ( char * ) F_186 ) ; }
