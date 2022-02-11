int F_1 ( T_1 * V_1 )
{
if ( V_1 -> V_2 == NULL )
{
F_2 ( V_3 , V_4 ) ;
return ( 0 ) ;
}
if ( F_3 ( V_1 ) )
{
F_4 ( V_1 -> V_5 ) ;
V_1 -> V_5 = NULL ;
}
V_1 -> error = 0 ;
V_1 -> V_6 = 0 ;
V_1 -> V_7 = 0 ;
#if 0
if (s->renegotiate) return(1);
#else
if ( V_1 -> V_8 )
{
F_2 ( V_3 , V_9 ) ;
return 0 ;
}
#endif
V_1 -> type = 0 ;
V_1 -> V_10 = V_11 | ( ( V_1 -> V_12 ) ? V_13 : V_14 ) ;
V_1 -> V_15 = V_1 -> V_2 -> V_15 ;
V_1 -> V_16 = V_1 -> V_15 ;
V_1 -> V_17 = V_18 ;
V_1 -> V_19 = V_20 ;
#if 0
s->read_ahead=s->ctx->read_ahead;
#endif
if ( V_1 -> V_21 != NULL )
{
F_5 ( V_1 -> V_21 ) ;
V_1 -> V_21 = NULL ;
}
F_6 ( V_1 ) ;
F_7 ( & V_1 -> V_22 ) ;
F_7 ( & V_1 -> V_23 ) ;
V_1 -> V_24 = 0 ;
#if 1
if ( ! V_1 -> V_25 && ( V_1 -> V_5 == NULL ) && ( V_1 -> V_2 != V_1 -> V_26 -> V_2 ) )
{
V_1 -> V_2 -> V_27 ( V_1 ) ;
V_1 -> V_2 = V_1 -> V_26 -> V_2 ;
if ( ! V_1 -> V_2 -> V_28 ( V_1 ) )
return ( 0 ) ;
}
else
#endif
V_1 -> V_2 -> V_29 ( V_1 ) ;
return ( 1 ) ;
}
int F_8 ( T_2 * V_26 , const T_3 * V_30 )
{
F_9 ( V_31 ) * V_32 ;
V_26 -> V_2 = V_30 ;
V_32 = F_10 ( V_26 -> V_2 , & ( V_26 -> V_33 ) ,
& ( V_26 -> V_34 ) ,
V_30 -> V_15 == V_35 ? L_1 : V_36 ) ;
if ( ( V_32 == NULL ) || ( F_11 ( V_32 ) <= 0 ) )
{
F_2 ( V_37 , V_38 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
T_1 * F_12 ( T_2 * V_26 )
{
T_1 * V_1 ;
if ( V_26 == NULL )
{
F_2 ( V_39 , V_40 ) ;
return ( NULL ) ;
}
if ( V_26 -> V_2 == NULL )
{
F_2 ( V_39 , V_41 ) ;
return ( NULL ) ;
}
V_1 = ( T_1 * ) F_13 ( sizeof( T_1 ) ) ;
if ( V_1 == NULL ) goto V_42;
memset ( V_1 , 0 , sizeof( T_1 ) ) ;
#ifndef F_14
V_1 -> V_43 = F_15 () ;
#endif
V_1 -> V_44 = V_26 -> V_44 ;
V_1 -> V_45 = V_26 -> V_45 ;
V_1 -> V_46 = V_26 -> V_46 ;
if ( V_26 -> V_47 != NULL )
{
V_1 -> V_47 = F_16 ( V_26 -> V_47 ) ;
if ( V_1 -> V_47 == NULL )
goto V_42;
}
else
V_1 -> V_47 = NULL ;
V_1 -> V_48 = V_26 -> V_48 ;
V_1 -> V_49 = V_26 -> V_49 ;
V_1 -> V_50 = V_26 -> V_50 ;
V_1 -> V_51 = V_26 -> V_51 ;
#if 0
s->verify_depth=ctx->verify_depth;
#endif
V_1 -> V_52 = V_26 -> V_52 ;
F_17 ( V_1 -> V_52 <= sizeof V_1 -> V_53 ) ;
memcpy ( & V_1 -> V_53 , & V_26 -> V_53 , sizeof( V_1 -> V_53 ) ) ;
V_1 -> V_54 = V_26 -> V_55 ;
V_1 -> V_56 = V_26 -> V_56 ;
V_1 -> V_57 = F_18 () ;
if ( ! V_1 -> V_57 )
goto V_42;
F_19 ( V_1 -> V_57 , V_26 -> V_57 ) ;
#if 0
s->purpose = ctx->purpose;
s->trust = ctx->trust;
#endif
V_1 -> V_58 = V_26 -> V_58 ;
V_1 -> V_59 = V_26 -> V_59 ;
F_20 ( & V_26 -> V_60 , 1 , V_61 ) ;
V_1 -> V_26 = V_26 ;
#ifndef F_21
V_1 -> V_62 = 0 ;
V_1 -> V_63 = NULL ;
V_1 -> V_64 = 0 ;
V_1 -> V_65 = - 1 ;
V_1 -> V_66 = 0 ;
V_1 -> V_67 = NULL ;
V_1 -> V_68 = NULL ;
V_1 -> V_69 = NULL ;
V_1 -> V_70 = - 1 ;
F_20 ( & V_26 -> V_60 , 1 , V_61 ) ;
V_1 -> V_71 = V_26 ;
# ifndef F_22
V_1 -> V_72 = NULL ;
# endif
#endif
V_1 -> V_73 = V_74 ;
V_1 -> V_2 = V_26 -> V_2 ;
if ( ! V_1 -> V_2 -> V_28 ( V_1 ) )
goto V_42;
V_1 -> V_60 = 1 ;
V_1 -> V_12 = ( V_26 -> V_2 -> V_75 == V_76 ) ? 0 : 1 ;
F_1 ( V_1 ) ;
F_23 ( V_77 , V_1 , & V_1 -> V_78 ) ;
#ifndef F_24
V_1 -> V_79 = V_26 -> V_79 ;
V_1 -> V_80 = V_26 -> V_80 ;
#endif
return ( V_1 ) ;
V_42:
if ( V_1 != NULL )
{
if ( V_1 -> V_47 != NULL )
F_25 ( V_1 -> V_47 ) ;
if ( V_1 -> V_26 != NULL )
F_26 ( V_1 -> V_26 ) ;
F_27 ( V_1 ) ;
}
F_2 ( V_39 , V_81 ) ;
return ( NULL ) ;
}
int F_28 ( T_2 * V_26 , const unsigned char * V_53 ,
unsigned int V_82 )
{
if( V_82 > sizeof V_26 -> V_53 )
{
F_2 ( V_83 , V_84 ) ;
return 0 ;
}
V_26 -> V_52 = V_82 ;
memcpy ( V_26 -> V_53 , V_53 , V_82 ) ;
return 1 ;
}
int F_29 ( T_1 * V_85 , const unsigned char * V_53 ,
unsigned int V_82 )
{
if( V_82 > V_86 )
{
F_2 ( V_87 , V_84 ) ;
return 0 ;
}
V_85 -> V_52 = V_82 ;
memcpy ( V_85 -> V_53 , V_53 , V_82 ) ;
return 1 ;
}
int F_30 ( T_2 * V_26 , T_4 V_88 )
{
F_31 ( V_61 ) ;
V_26 -> V_56 = V_88 ;
F_32 ( V_61 ) ;
return 1 ;
}
int F_33 ( T_1 * V_85 , T_4 V_88 )
{
F_31 ( V_89 ) ;
V_85 -> V_56 = V_88 ;
F_32 ( V_89 ) ;
return 1 ;
}
int F_34 ( const T_1 * V_85 , const unsigned char * V_90 ,
unsigned int V_91 )
{
T_5 V_92 , * V_93 ;
if( V_91 > sizeof V_92 . V_94 )
return 0 ;
V_92 . V_95 = V_85 -> V_15 ;
V_92 . V_96 = V_91 ;
memcpy ( V_92 . V_94 , V_90 , V_91 ) ;
if( ( V_92 . V_95 == V_35 ) &&
( V_91 < V_97 ) )
{
memset ( V_92 . V_94 + V_91 , 0 ,
V_97 - V_91 ) ;
V_92 . V_96 = V_97 ;
}
F_35 ( V_61 ) ;
V_93 = F_36 ( V_85 -> V_26 -> V_98 , & V_92 ) ;
F_37 ( V_61 ) ;
return ( V_93 != NULL ) ;
}
int F_38 ( T_2 * V_1 , int V_99 )
{
return F_39 ( V_1 -> V_57 , V_99 ) ;
}
int F_40 ( T_1 * V_1 , int V_99 )
{
return F_39 ( V_1 -> V_57 , V_99 ) ;
}
int F_41 ( T_2 * V_1 , int V_100 )
{
return F_42 ( V_1 -> V_57 , V_100 ) ;
}
int F_43 ( T_1 * V_1 , int V_100 )
{
return F_42 ( V_1 -> V_57 , V_100 ) ;
}
int F_44 ( T_2 * V_26 , T_6 * V_101 )
{
return F_45 ( V_26 -> V_57 , V_101 ) ;
}
int F_46 ( T_1 * V_85 , T_6 * V_101 )
{
return F_45 ( V_85 -> V_57 , V_101 ) ;
}
void F_47 ( T_1 * V_1 )
{
int V_102 ;
if( V_1 == NULL )
return;
V_102 = F_20 ( & V_1 -> V_60 , - 1 , V_89 ) ;
#ifdef F_48
F_48 ( L_2 , V_1 ) ;
#endif
if ( V_102 > 0 ) return;
#ifdef F_49
if ( V_102 < 0 )
{
fprintf ( V_103 , L_3 ) ;
abort () ;
}
#endif
if ( V_1 -> V_57 )
F_50 ( V_1 -> V_57 ) ;
F_51 ( V_77 , V_1 , & V_1 -> V_78 ) ;
if ( V_1 -> V_104 != NULL )
{
if ( V_1 -> V_104 == V_1 -> V_105 )
{
V_1 -> V_105 = F_52 ( V_1 -> V_105 ) ;
}
F_53 ( V_1 -> V_104 ) ;
V_1 -> V_104 = NULL ;
}
if ( V_1 -> V_106 != NULL )
F_54 ( V_1 -> V_106 ) ;
if ( ( V_1 -> V_105 != NULL ) && ( V_1 -> V_105 != V_1 -> V_106 ) )
F_54 ( V_1 -> V_105 ) ;
if ( V_1 -> V_21 != NULL ) F_5 ( V_1 -> V_21 ) ;
if ( V_1 -> V_33 != NULL ) F_55 ( V_1 -> V_33 ) ;
if ( V_1 -> V_34 != NULL ) F_55 ( V_1 -> V_34 ) ;
if ( V_1 -> V_5 != NULL )
{
F_3 ( V_1 ) ;
F_4 ( V_1 -> V_5 ) ;
}
F_6 ( V_1 ) ;
F_7 ( & V_1 -> V_22 ) ;
F_7 ( & V_1 -> V_23 ) ;
if ( V_1 -> V_47 != NULL ) F_25 ( V_1 -> V_47 ) ;
#ifndef F_21
if ( V_1 -> V_107 )
F_27 ( V_1 -> V_107 ) ;
if ( V_1 -> V_71 ) F_26 ( V_1 -> V_71 ) ;
#ifndef F_56
if ( V_1 -> V_108 ) F_27 ( V_1 -> V_108 ) ;
if ( V_1 -> V_109 ) F_27 ( V_1 -> V_109 ) ;
#endif
if ( V_1 -> V_110 ) F_27 ( V_1 -> V_110 ) ;
if ( V_1 -> V_68 )
F_57 ( V_1 -> V_68 ,
V_111 ) ;
if ( V_1 -> V_67 )
F_58 ( V_1 -> V_67 , V_112 ) ;
if ( V_1 -> V_69 )
F_27 ( V_1 -> V_69 ) ;
#endif
if ( V_1 -> V_113 != NULL )
F_59 ( V_1 -> V_113 , V_114 ) ;
if ( V_1 -> V_2 != NULL ) V_1 -> V_2 -> V_27 ( V_1 ) ;
if ( V_1 -> V_26 ) F_26 ( V_1 -> V_26 ) ;
#ifndef F_14
if ( V_1 -> V_43 != NULL )
F_60 ( V_1 -> V_43 ) ;
#endif
#if ! F_61 ( F_21 ) && ! F_61 ( F_22 )
if ( V_1 -> V_72 )
F_27 ( V_1 -> V_72 ) ;
#endif
if ( V_1 -> V_115 )
F_62 ( V_1 -> V_115 ) ;
F_27 ( V_1 ) ;
}
void F_63 ( T_1 * V_1 , T_7 * V_106 , T_7 * V_105 )
{
if ( V_1 -> V_104 != NULL )
{
if ( V_1 -> V_105 == V_1 -> V_104 )
{
V_1 -> V_105 = V_1 -> V_105 -> V_116 ;
V_1 -> V_104 -> V_116 = NULL ;
}
}
if ( ( V_1 -> V_106 != NULL ) && ( V_1 -> V_106 != V_106 ) )
F_54 ( V_1 -> V_106 ) ;
if ( ( V_1 -> V_105 != NULL ) && ( V_1 -> V_105 != V_105 ) && ( V_1 -> V_106 != V_1 -> V_105 ) )
F_54 ( V_1 -> V_105 ) ;
V_1 -> V_106 = V_106 ;
V_1 -> V_105 = V_105 ;
}
T_7 * F_64 ( const T_1 * V_1 )
{ return ( V_1 -> V_106 ) ; }
T_7 * F_65 ( const T_1 * V_1 )
{ return ( V_1 -> V_105 ) ; }
int F_66 ( const T_1 * V_1 )
{
return ( F_67 ( V_1 ) ) ;
}
int F_67 ( const T_1 * V_1 )
{
int V_117 = - 1 ;
T_7 * V_118 , * V_92 ;
V_118 = F_64 ( V_1 ) ;
V_92 = F_68 ( V_118 , V_119 ) ;
if ( V_92 != NULL )
F_69 ( V_92 , & V_117 ) ;
return ( V_117 ) ;
}
int F_70 ( const T_1 * V_1 )
{
int V_117 = - 1 ;
T_7 * V_118 , * V_92 ;
V_118 = F_65 ( V_1 ) ;
V_92 = F_68 ( V_118 , V_119 ) ;
if ( V_92 != NULL )
F_69 ( V_92 , & V_117 ) ;
return ( V_117 ) ;
}
int F_71 ( T_1 * V_1 , int V_120 )
{
int V_117 = 0 ;
T_7 * V_121 = NULL ;
V_121 = F_72 ( F_73 () ) ;
if ( V_121 == NULL )
{
F_2 ( V_122 , V_123 ) ;
goto V_42;
}
F_74 ( V_121 , V_120 , V_124 ) ;
F_63 ( V_1 , V_121 , V_121 ) ;
V_117 = 1 ;
V_42:
return ( V_117 ) ;
}
int F_75 ( T_1 * V_1 , int V_120 )
{
int V_117 = 0 ;
T_7 * V_121 = NULL ;
if ( ( V_1 -> V_106 == NULL ) || ( F_76 ( V_1 -> V_106 ) != V_125 )
|| ( ( int ) F_69 ( V_1 -> V_106 , NULL ) != V_120 ) )
{
V_121 = F_72 ( F_73 () ) ;
if ( V_121 == NULL )
{ F_2 ( V_126 , V_123 ) ; goto V_42; }
F_74 ( V_121 , V_120 , V_124 ) ;
F_63 ( V_1 , F_64 ( V_1 ) , V_121 ) ;
}
else
F_63 ( V_1 , F_64 ( V_1 ) , F_64 ( V_1 ) ) ;
V_117 = 1 ;
V_42:
return ( V_117 ) ;
}
int F_77 ( T_1 * V_1 , int V_120 )
{
int V_117 = 0 ;
T_7 * V_121 = NULL ;
if ( ( V_1 -> V_105 == NULL ) || ( F_76 ( V_1 -> V_105 ) != V_125 )
|| ( ( int ) F_69 ( V_1 -> V_105 , NULL ) != V_120 ) )
{
V_121 = F_72 ( F_73 () ) ;
if ( V_121 == NULL )
{
F_2 ( V_127 , V_123 ) ;
goto V_42;
}
F_74 ( V_121 , V_120 , V_124 ) ;
F_63 ( V_1 , V_121 , F_65 ( V_1 ) ) ;
}
else
F_63 ( V_1 , F_65 ( V_1 ) , F_65 ( V_1 ) ) ;
V_117 = 1 ;
V_42:
return ( V_117 ) ;
}
T_8 F_78 ( const T_1 * V_1 , void * V_128 , T_8 V_129 )
{
T_8 V_117 = 0 ;
if ( V_1 -> V_130 != NULL )
{
V_117 = V_1 -> V_130 -> V_131 . V_132 ;
if ( V_129 > V_117 )
V_129 = V_117 ;
memcpy ( V_128 , V_1 -> V_130 -> V_131 . V_133 , V_129 ) ;
}
return V_117 ;
}
T_8 F_79 ( const T_1 * V_1 , void * V_128 , T_8 V_129 )
{
T_8 V_117 = 0 ;
if ( V_1 -> V_130 != NULL )
{
V_117 = V_1 -> V_130 -> V_131 . V_134 ;
if ( V_129 > V_117 )
V_129 = V_117 ;
memcpy ( V_128 , V_1 -> V_130 -> V_131 . V_135 , V_129 ) ;
}
return V_117 ;
}
int F_80 ( const T_1 * V_1 )
{
return ( V_1 -> V_51 ) ;
}
int F_81 ( const T_1 * V_1 )
{
return F_82 ( V_1 -> V_57 ) ;
}
int F_83 ( const T_2 * V_26 )
{
return ( V_26 -> V_51 ) ;
}
int F_84 ( const T_2 * V_26 )
{
return F_82 ( V_26 -> V_57 ) ;
}
void F_85 ( T_1 * V_1 , int V_45 ,
int (* F_86)( int V_136 , T_9 * V_26 ) )
{
V_1 -> V_51 = V_45 ;
if ( F_86 != NULL )
V_1 -> V_54 = F_86 ;
}
void F_87 ( T_1 * V_1 , int V_137 )
{
F_88 ( V_1 -> V_57 , V_137 ) ;
}
void F_89 ( T_1 * V_1 , int V_138 )
{
V_1 -> V_48 = V_138 ;
}
int F_90 ( const T_1 * V_1 )
{
return ( V_1 -> V_48 ) ;
}
int F_91 ( const T_1 * V_1 )
{
return ( V_1 -> V_2 -> V_139 ( V_1 ) ) ;
}
T_10 * F_92 ( const T_1 * V_1 )
{
T_10 * V_92 ;
if ( ( V_1 == NULL ) || ( V_1 -> V_5 == NULL ) )
V_92 = NULL ;
else
V_92 = V_1 -> V_5 -> V_140 ;
if ( V_92 == NULL ) return ( V_92 ) ;
F_20 ( & V_92 -> V_60 , 1 , V_141 ) ;
return ( V_92 ) ;
}
int F_93 ( const T_2 * V_26 )
{
if ( ( V_26 == NULL ) ||
( V_26 -> V_47 == NULL ) ||
( V_26 -> V_47 -> V_142 -> V_143 == NULL ) )
{
F_2 ( V_144 , V_145 ) ;
return ( 0 ) ;
}
if ( V_26 -> V_47 -> V_142 -> V_146 == NULL )
{
F_2 ( V_144 , V_147 ) ;
return ( 0 ) ;
}
return ( F_94 ( V_26 -> V_47 -> V_142 -> V_143 , V_26 -> V_47 -> V_142 -> V_146 ) ) ;
}
int F_95 ( const T_1 * V_85 )
{
if ( V_85 == NULL )
{
F_2 ( V_148 , V_149 ) ;
return ( 0 ) ;
}
if ( V_85 -> V_47 == NULL )
{
F_2 ( V_148 , V_145 ) ;
return 0 ;
}
if ( V_85 -> V_47 -> V_142 -> V_143 == NULL )
{
F_2 ( V_148 , V_145 ) ;
return ( 0 ) ;
}
if ( V_85 -> V_47 -> V_142 -> V_146 == NULL )
{
F_2 ( V_148 , V_147 ) ;
return ( 0 ) ;
}
return ( F_94 ( V_85 -> V_47 -> V_142 -> V_143 ,
V_85 -> V_47 -> V_142 -> V_146 ) ) ;
}
int F_96 ( T_1 * V_1 )
{
if ( V_1 -> V_150 == 0 )
F_97 ( V_1 ) ;
return ( V_1 -> V_2 -> V_75 ( V_1 ) ) ;
}
int F_98 ( T_1 * V_1 )
{
if ( V_1 -> V_150 == 0 )
F_99 ( V_1 ) ;
return ( V_1 -> V_2 -> V_151 ( V_1 ) ) ;
}
long F_100 ( const T_1 * V_1 )
{
return ( V_1 -> V_2 -> V_152 () ) ;
}
int F_101 ( T_1 * V_1 , void * V_128 , int V_153 )
{
if ( V_1 -> V_150 == 0 )
{
F_2 ( V_154 , V_155 ) ;
return - 1 ;
}
if ( V_1 -> V_7 & V_156 )
{
V_1 -> V_17 = V_18 ;
return ( 0 ) ;
}
return ( V_1 -> V_2 -> V_157 ( V_1 , V_128 , V_153 ) ) ;
}
int F_102 ( T_1 * V_1 , void * V_128 , int V_153 )
{
if ( V_1 -> V_150 == 0 )
{
F_2 ( V_158 , V_155 ) ;
return - 1 ;
}
if ( V_1 -> V_7 & V_156 )
{
return ( 0 ) ;
}
return ( V_1 -> V_2 -> V_159 ( V_1 , V_128 , V_153 ) ) ;
}
int F_103 ( T_1 * V_1 , const void * V_128 , int V_153 )
{
if ( V_1 -> V_150 == 0 )
{
F_2 ( V_160 , V_155 ) ;
return - 1 ;
}
if ( V_1 -> V_7 & V_161 )
{
V_1 -> V_17 = V_18 ;
F_2 ( V_160 , V_162 ) ;
return ( - 1 ) ;
}
return ( V_1 -> V_2 -> V_163 ( V_1 , V_128 , V_153 ) ) ;
}
int F_104 ( T_1 * V_1 )
{
if ( V_1 -> V_150 == 0 )
{
F_2 ( V_164 , V_155 ) ;
return - 1 ;
}
if ( ( V_1 != NULL ) && ! F_105 ( V_1 ) )
return ( V_1 -> V_2 -> V_165 ( V_1 ) ) ;
else
return ( 1 ) ;
}
int F_106 ( T_1 * V_1 )
{
if ( V_1 -> V_8 == 0 )
V_1 -> V_8 = 1 ;
V_1 -> V_166 = 1 ;
return ( V_1 -> V_2 -> V_167 ( V_1 ) ) ;
}
int F_107 ( T_1 * V_1 )
{
if ( V_1 -> V_8 == 0 )
V_1 -> V_8 = 1 ;
V_1 -> V_166 = 0 ;
return ( V_1 -> V_2 -> V_167 ( V_1 ) ) ;
}
int F_108 ( T_1 * V_1 )
{
return ( V_1 -> V_8 != 0 ) ;
}
long F_109 ( T_1 * V_1 , int V_168 , long V_169 , void * V_170 )
{
long V_171 ;
switch ( V_168 )
{
case V_172 :
return ( V_1 -> V_48 ) ;
case V_173 :
V_171 = V_1 -> V_48 ;
V_1 -> V_48 = V_169 ;
return ( V_171 ) ;
case V_174 :
V_1 -> V_50 = V_170 ;
return 1 ;
case V_175 :
return ( V_1 -> V_44 |= V_169 ) ;
case V_176 :
return ( V_1 -> V_44 &= ~ V_169 ) ;
case V_177 :
return ( V_1 -> V_45 |= V_169 ) ;
case V_178 :
return ( V_1 -> V_45 &= ~ V_169 ) ;
case V_179 :
return ( V_1 -> V_46 ) ;
case V_180 :
V_171 = V_1 -> V_46 ;
V_1 -> V_46 = V_169 ;
return ( V_171 ) ;
case V_181 :
#ifndef F_110
if ( V_169 < ( long ) F_111 () )
return 0 ;
#endif
if ( F_112 ( V_1 ) == V_182 ||
F_112 ( V_1 ) == V_183 )
{
V_1 -> V_184 -> V_185 = V_169 ;
return V_169 ;
}
return 0 ;
case V_186 :
if ( V_169 < 512 || V_169 > V_187 )
return 0 ;
V_1 -> V_59 = V_169 ;
return 1 ;
case V_188 :
if ( V_1 -> V_130 )
return V_1 -> V_130 -> V_189 ;
else return 0 ;
default:
return ( V_1 -> V_2 -> V_190 ( V_1 , V_168 , V_169 , V_170 ) ) ;
}
}
long F_113 ( T_1 * V_1 , int V_168 , void (* F_114)( void ) )
{
switch( V_168 )
{
case V_191 :
V_1 -> V_49 = ( void (*) ( int V_192 , int V_15 , int V_193 , const void * V_128 , T_8 V_194 , T_1 * V_85 , void * V_195 ) ) ( F_114 ) ;
return 1 ;
default:
return ( V_1 -> V_2 -> V_196 ( V_1 , V_168 , F_114 ) ) ;
}
}
long F_115 ( T_2 * V_26 , int V_168 , long V_169 , void * V_170 )
{
long V_171 ;
switch ( V_168 )
{
case V_172 :
return ( V_26 -> V_48 ) ;
case V_173 :
V_171 = V_26 -> V_48 ;
V_26 -> V_48 = V_169 ;
return ( V_171 ) ;
case V_174 :
V_26 -> V_50 = V_170 ;
return 1 ;
case V_179 :
return ( V_26 -> V_46 ) ;
case V_180 :
V_171 = V_26 -> V_46 ;
V_26 -> V_46 = V_169 ;
return ( V_171 ) ;
case V_197 :
V_171 = V_26 -> V_198 ;
V_26 -> V_198 = V_169 ;
return ( V_171 ) ;
case V_199 :
return ( V_26 -> V_198 ) ;
case V_200 :
V_171 = V_26 -> V_201 ;
V_26 -> V_201 = V_169 ;
return ( V_171 ) ;
case V_202 :
return ( V_26 -> V_201 ) ;
case V_203 :
return ( F_116 ( V_26 -> V_98 ) ) ;
case V_204 :
return ( V_26 -> V_205 . V_206 ) ;
case V_207 :
return ( V_26 -> V_205 . V_208 ) ;
case V_209 :
return ( V_26 -> V_205 . V_210 ) ;
case V_211 :
return ( V_26 -> V_205 . V_212 ) ;
case V_213 :
return ( V_26 -> V_205 . V_214 ) ;
case V_215 :
return ( V_26 -> V_205 . V_216 ) ;
case V_217 :
return ( V_26 -> V_205 . V_218 ) ;
case V_219 :
return ( V_26 -> V_205 . V_220 ) ;
case V_221 :
return ( V_26 -> V_205 . V_222 ) ;
case V_223 :
return ( V_26 -> V_205 . V_224 ) ;
case V_225 :
return ( V_26 -> V_205 . V_226 ) ;
case V_175 :
return ( V_26 -> V_44 |= V_169 ) ;
case V_176 :
return ( V_26 -> V_44 &= ~ V_169 ) ;
case V_177 :
return ( V_26 -> V_45 |= V_169 ) ;
case V_178 :
return ( V_26 -> V_45 &= ~ V_169 ) ;
case V_186 :
if ( V_169 < 512 || V_169 > V_187 )
return 0 ;
V_26 -> V_59 = V_169 ;
return 1 ;
default:
return ( V_26 -> V_2 -> V_227 ( V_26 , V_168 , V_169 , V_170 ) ) ;
}
}
long F_117 ( T_2 * V_26 , int V_168 , void (* F_114)( void ) )
{
switch( V_168 )
{
case V_191 :
V_26 -> V_49 = ( void (*) ( int V_192 , int V_15 , int V_193 , const void * V_128 , T_8 V_194 , T_1 * V_85 , void * V_195 ) ) ( F_114 ) ;
return 1 ;
default:
return ( V_26 -> V_2 -> V_228 ( V_26 , V_168 , F_114 ) ) ;
}
}
int F_118 ( const V_31 * V_229 , const V_31 * V_118 )
{
long V_171 ;
V_171 = V_229 -> V_90 - V_118 -> V_90 ;
if ( V_171 == 0L )
return ( 0 ) ;
else
return ( ( V_171 > 0 ) ? 1 : - 1 ) ;
}
int F_119 ( const V_31 * const * V_230 ,
const V_31 * const * V_231 )
{
long V_171 ;
V_171 = ( * V_230 ) -> V_90 - ( * V_231 ) -> V_90 ;
if ( V_171 == 0L )
return ( 0 ) ;
else
return ( ( V_171 > 0 ) ? 1 : - 1 ) ;
}
char * F_120 ( const T_1 * V_1 , int V_232 )
{
V_31 * V_233 ;
F_9 ( V_31 ) * V_32 ;
if ( V_1 == NULL ) return ( NULL ) ;
V_32 = F_121 ( V_1 ) ;
if ( ( V_32 == NULL ) || ( F_11 ( V_32 ) <= V_232 ) )
return ( NULL ) ;
V_233 = F_122 ( V_32 , V_232 ) ;
if ( V_233 == NULL ) return ( NULL ) ;
return ( V_233 -> V_234 ) ;
}
int F_123 ( T_2 * V_26 , const char * V_235 )
{
F_9 ( V_31 ) * V_32 ;
V_32 = F_10 ( V_26 -> V_2 , & V_26 -> V_33 ,
& V_26 -> V_34 , V_235 ) ;
if ( V_32 == NULL )
return 0 ;
else if ( F_11 ( V_32 ) == 0 )
{
F_2 ( V_236 , V_237 ) ;
return 0 ;
}
return 1 ;
}
int F_124 ( T_1 * V_1 , const char * V_235 )
{
F_9 ( V_31 ) * V_32 ;
V_32 = F_10 ( V_1 -> V_26 -> V_2 , & V_1 -> V_33 ,
& V_1 -> V_34 , V_235 ) ;
if ( V_32 == NULL )
return 0 ;
else if ( F_11 ( V_32 ) == 0 )
{
F_2 ( V_238 , V_237 ) ;
return 0 ;
}
return 1 ;
}
char * F_125 ( const T_1 * V_1 , char * V_128 , int V_194 )
{
char * V_93 ;
F_9 ( V_31 ) * V_32 ;
V_31 * V_233 ;
int V_102 ;
if ( ( V_1 -> V_5 == NULL ) || ( V_1 -> V_5 -> V_239 == NULL ) ||
( V_194 < 2 ) )
return ( NULL ) ;
V_93 = V_128 ;
V_32 = V_1 -> V_5 -> V_239 ;
for ( V_102 = 0 ; V_102 < F_11 ( V_32 ) ; V_102 ++ )
{
int V_232 ;
V_233 = F_122 ( V_32 , V_102 ) ;
V_232 = strlen ( V_233 -> V_234 ) ;
if ( V_232 + 1 > V_194 )
{
if ( V_93 != V_128 )
-- V_93 ;
* V_93 = '\0' ;
return V_128 ;
}
strcpy ( V_93 , V_233 -> V_234 ) ;
V_93 += V_232 ;
* ( V_93 ++ ) = ':' ;
V_194 -= V_232 + 1 ;
}
V_93 [ - 1 ] = '\0' ;
return ( V_128 ) ;
}
char * F_126 ( const T_1 * V_1 , const int type )
{
if ( type != V_240 )
return NULL ;
return V_1 -> V_5 && ! V_1 -> V_107 ?
V_1 -> V_5 -> V_107 :
V_1 -> V_107 ;
}
int F_127 ( const T_1 * V_1 )
{
if ( V_1 -> V_5 && ( ! V_1 -> V_107 ? V_1 -> V_5 -> V_107 : V_1 -> V_107 ) )
return V_240 ;
return - 1 ;
}
int F_128 ( unsigned char * * V_241 , unsigned char * V_242 , const unsigned char * V_12 , unsigned int V_243 , const unsigned char * V_244 , unsigned int V_245 )
{
unsigned int V_102 , V_246 ;
const unsigned char * V_247 ;
int V_248 = V_249 ;
for ( V_102 = 0 ; V_102 < V_243 ; )
{
for ( V_246 = 0 ; V_246 < V_245 ; )
{
if ( V_12 [ V_102 ] == V_244 [ V_246 ] &&
memcmp ( & V_12 [ V_102 + 1 ] , & V_244 [ V_246 + 1 ] , V_12 [ V_102 ] ) == 0 )
{
V_247 = & V_12 [ V_102 ] ;
V_248 = V_250 ;
goto V_251;
}
V_246 += V_244 [ V_246 ] ;
V_246 ++ ;
}
V_102 += V_12 [ V_102 ] ;
V_102 ++ ;
}
V_247 = V_244 ;
V_248 = V_252 ;
V_251:
* V_241 = ( unsigned char * ) V_247 + 1 ;
* V_242 = V_247 [ 0 ] ;
return V_248 ;
}
void F_129 ( const T_1 * V_1 , const unsigned char * * V_253 , unsigned * V_194 )
{
* V_253 = V_1 -> V_72 ;
if ( ! * V_253 ) {
* V_194 = 0 ;
} else {
* V_194 = V_1 -> V_254 ;
}
}
void F_130 ( T_2 * V_26 , int (* V_88) ( T_1 * V_85 , const unsigned char * * V_241 , unsigned int * V_242 , void * V_195 ) , void * V_195 )
{
V_26 -> V_255 = V_88 ;
V_26 -> V_256 = V_195 ;
}
void F_131 ( T_2 * V_26 , int (* V_88) ( T_1 * V_1 , unsigned char * * V_241 , unsigned char * V_242 , const unsigned char * V_257 , unsigned int V_258 , void * V_195 ) , void * V_195 )
{
V_26 -> V_259 = V_88 ;
V_26 -> V_260 = V_195 ;
}
int F_132 ( T_1 * V_1 , unsigned char * V_241 , T_8 V_261 ,
const char * V_262 , T_8 V_263 , const unsigned char * V_93 , T_8 V_264 ,
int V_265 )
{
if ( V_1 -> V_15 < V_266 )
return - 1 ;
return V_1 -> V_2 -> V_267 -> V_268 ( V_1 , V_241 , V_261 , V_262 ,
V_263 , V_93 , V_264 ,
V_265 ) ;
}
static unsigned long F_133 ( const T_5 * V_229 )
{
unsigned long V_171 ;
V_171 = ( unsigned long )
( ( unsigned int ) V_229 -> V_94 [ 0 ] ) |
( ( unsigned int ) V_229 -> V_94 [ 1 ] << 8L ) |
( ( unsigned long ) V_229 -> V_94 [ 2 ] << 16L ) |
( ( unsigned long ) V_229 -> V_94 [ 3 ] << 24L ) ;
return ( V_171 ) ;
}
static int F_134 ( const T_5 * V_229 , const T_5 * V_118 )
{
if ( V_229 -> V_95 != V_118 -> V_95 )
return ( 1 ) ;
if ( V_229 -> V_96 != V_118 -> V_96 )
return ( 1 ) ;
return ( memcmp ( V_229 -> V_94 , V_118 -> V_94 , V_229 -> V_96 ) ) ;
}
void
F_135 ( T_11 * V_269 )
{
T_12 * V_270 , * V_271 ;
for ( V_270 = V_269 -> V_272 ; V_270 ; V_270 = V_271 )
{
V_271 = V_270 -> V_271 ;
F_27 ( V_270 ) ;
}
F_27 ( V_269 ) ;
}
void F_26 ( T_2 * V_229 )
{
int V_102 ;
if ( V_229 == NULL ) return;
V_102 = F_20 ( & V_229 -> V_60 , - 1 , V_61 ) ;
#ifdef F_48
F_48 ( L_4 , V_229 ) ;
#endif
if ( V_102 > 0 ) return;
#ifdef F_49
if ( V_102 < 0 )
{
fprintf ( V_103 , L_5 ) ;
abort () ;
}
#endif
if ( V_229 -> V_57 )
F_50 ( V_229 -> V_57 ) ;
if ( V_229 -> V_98 != NULL )
F_136 ( V_229 , 0 ) ;
F_51 ( V_273 , V_229 , & V_229 -> V_78 ) ;
if ( V_229 -> V_98 != NULL )
F_137 ( V_229 -> V_98 ) ;
if ( V_229 -> V_274 != NULL )
F_138 ( V_229 -> V_274 ) ;
if ( V_229 -> V_33 != NULL )
F_55 ( V_229 -> V_33 ) ;
if ( V_229 -> V_34 != NULL )
F_55 ( V_229 -> V_34 ) ;
if ( V_229 -> V_47 != NULL )
F_25 ( V_229 -> V_47 ) ;
if ( V_229 -> V_113 != NULL )
F_59 ( V_229 -> V_113 , V_114 ) ;
if ( V_229 -> V_275 != NULL )
F_139 ( V_229 -> V_275 , V_276 ) ;
#if 0
if (a->comp_methods != NULL)
sk_SSL_COMP_pop_free(a->comp_methods,SSL_COMP_free);
#else
V_229 -> V_277 = NULL ;
#endif
if ( V_229 -> V_115 )
F_62 ( V_229 -> V_115 ) ;
#ifndef F_24
if ( V_229 -> V_278 )
F_27 ( V_229 -> V_278 ) ;
#endif
#ifndef F_140
F_141 ( V_229 ) ;
#endif
#ifndef F_142
if ( V_229 -> V_279 )
F_143 ( V_229 -> V_279 ) ;
#endif
#ifndef F_144
if ( V_229 -> V_280 )
F_135 ( V_229 -> V_280 ) ;
if ( V_229 -> V_281 )
F_135 ( V_229 -> V_281 ) ;
#endif
F_27 ( V_229 ) ;
}
void F_145 ( T_2 * V_26 , T_13 * V_88 )
{
V_26 -> V_282 = V_88 ;
}
void F_146 ( T_2 * V_26 , void * V_283 )
{
V_26 -> V_284 = V_283 ;
}
void F_147 ( T_2 * V_26 , int (* V_88)( T_9 * , void * ) , void * V_195 )
{
V_26 -> V_285 = V_88 ;
V_26 -> V_286 = V_195 ;
}
void F_148 ( T_2 * V_26 , int V_45 , int (* V_88)( int , T_9 * ) )
{
V_26 -> V_51 = V_45 ;
V_26 -> V_55 = V_88 ;
}
void F_149 ( T_2 * V_26 , int V_137 )
{
F_88 ( V_26 -> V_57 , V_137 ) ;
}
void F_150 ( T_14 * V_233 , const V_31 * V_287 )
{
T_15 * V_288 ;
int V_289 , V_290 , V_291 , V_292 , V_293 , V_294 , V_295 ;
int V_296 , V_297 , V_298 ;
int V_299 , V_300 , V_301 ;
unsigned long V_302 , V_303 , V_304 , V_305 ;
int V_306 , V_307 , V_308 , V_309 ;
#ifndef F_151
int V_310 ;
#endif
T_10 * V_311 = NULL ;
T_16 * V_312 = NULL ;
int V_313 = 0 , V_314 = 0 , V_315 = 0 ;
if ( V_233 == NULL ) return;
V_301 = F_152 ( V_287 ) ;
#ifndef F_153
V_290 = ( V_233 -> V_290 != NULL || V_233 -> V_316 != NULL ) ;
V_299 = ( V_233 -> V_316 != NULL ||
( V_290 && F_154 ( V_233 -> V_290 ) * 8 <= V_301 ) ) ;
#else
V_290 = V_299 = 0 ;
#endif
#ifndef F_155
V_292 = ( V_233 -> V_292 != NULL || V_233 -> V_317 != NULL ) ;
V_300 = ( V_233 -> V_317 != NULL ||
( V_292 && F_156 ( V_233 -> V_292 ) * 8 <= V_301 ) ) ;
#else
V_292 = V_300 = 0 ;
#endif
#ifndef F_151
V_310 = ( V_233 -> V_318 != NULL || V_233 -> V_319 != NULL ) ;
#endif
V_288 = & ( V_233 -> V_320 [ V_321 ] ) ;
V_289 = ( V_288 -> V_143 != NULL && V_288 -> V_146 != NULL ) ;
V_296 = ( V_289 && F_157 ( V_288 -> V_146 ) * 8 <= V_301 ) ;
V_288 = & ( V_233 -> V_320 [ V_322 ] ) ;
V_291 = ( V_288 -> V_143 != NULL && V_288 -> V_146 != NULL ) ;
V_288 = & ( V_233 -> V_320 [ V_323 ] ) ;
V_295 = ( V_288 -> V_143 != NULL && V_288 -> V_146 != NULL ) ;
V_288 = & ( V_233 -> V_320 [ V_324 ] ) ;
V_293 = ( V_288 -> V_143 != NULL && V_288 -> V_146 != NULL ) ;
V_297 = ( V_293 && F_157 ( V_288 -> V_146 ) * 8 <= V_301 ) ;
V_288 = & ( V_233 -> V_320 [ V_325 ] ) ;
V_294 = ( V_288 -> V_143 != NULL && V_288 -> V_146 != NULL ) ;
V_298 = ( V_294 && F_157 ( V_288 -> V_146 ) * 8 <= V_301 ) ;
V_288 = & ( V_233 -> V_320 [ V_326 ] ) ;
V_306 = ( V_288 -> V_143 != NULL && V_288 -> V_146 != NULL ) ;
V_302 = 0 ;
V_303 = 0 ;
V_304 = 0 ;
V_305 = 0 ;
#ifdef F_158
printf ( L_6 ,
V_290 , V_299 , V_292 , V_310 ,
V_289 , V_296 , V_291 , V_295 , V_293 , V_294 ) ;
#endif
V_288 = & ( V_233 -> V_320 [ V_327 ] ) ;
if ( V_288 -> V_143 != NULL && V_288 -> V_146 != NULL ) {
V_302 |= V_328 ;
V_303 |= V_329 ;
}
V_288 = & ( V_233 -> V_320 [ V_330 ] ) ;
if ( V_288 -> V_143 != NULL && V_288 -> V_146 != NULL ) {
V_302 |= V_328 ;
V_303 |= V_331 ;
}
if ( V_289 || ( V_290 && V_291 ) )
V_302 |= V_332 ;
if ( V_296 || ( V_299 && ( V_291 || V_289 ) ) )
V_304 |= V_332 ;
#if 0
if ( (dh_tmp || dh_rsa || dh_dsa) &&
(rsa_enc || rsa_sign || dsa_sign))
mask_k|=SSL_kEDH;
if ((dh_tmp_export || dh_rsa_export || dh_dsa_export) &&
(rsa_enc || rsa_sign || dsa_sign))
emask_k|=SSL_kEDH;
#endif
if ( V_300 )
V_304 |= V_333 ;
if ( V_292 )
V_302 |= V_333 ;
if ( V_293 ) V_302 |= V_334 ;
if ( V_297 ) V_304 |= V_334 ;
if ( V_294 ) V_302 |= V_335 ;
if ( V_298 ) V_304 |= V_335 ;
if ( V_289 || V_291 )
{
V_303 |= V_336 ;
V_305 |= V_336 ;
}
if ( V_295 )
{
V_303 |= V_337 ;
V_305 |= V_337 ;
}
V_303 |= V_338 ;
V_305 |= V_338 ;
#ifndef F_14
V_302 |= V_339 ;
V_303 |= V_340 ;
V_304 |= V_339 ;
V_305 |= V_340 ;
#endif
if ( V_306 )
{
V_311 = ( V_233 -> V_320 [ V_326 ] ) . V_143 ;
F_159 ( V_311 , - 1 , 0 ) ;
V_307 = ( V_311 -> V_341 & V_342 ) ?
( V_311 -> V_343 & V_344 ) : 1 ;
V_308 = ( V_311 -> V_341 & V_342 ) ?
( V_311 -> V_343 & V_345 ) : 1 ;
V_312 = F_160 ( V_311 ) ;
V_309 = ( V_312 != NULL ) ?
F_161 ( V_312 ) : 0 ;
F_162 ( V_312 ) ;
if ( ( V_311 -> V_346 ) && ( V_311 -> V_346 -> V_347 ) )
{
V_313 = F_163 ( V_311 -> V_346 -> V_347 ) ;
F_164 ( V_313 , & V_315 , & V_314 ) ;
}
#ifndef F_151
if ( V_307 )
{
if ( V_314 == V_348 || V_314 == V_349 )
{
V_302 |= V_350 ;
V_303 |= V_351 ;
if ( V_309 <= 163 )
{
V_304 |= V_350 ;
V_305 |= V_351 ;
}
}
if ( V_314 == V_352 )
{
V_302 |= V_353 ;
V_303 |= V_351 ;
if ( V_309 <= 163 )
{
V_304 |= V_353 ;
V_305 |= V_351 ;
}
}
}
#endif
#ifndef F_165
if ( V_308 )
{
V_303 |= V_354 ;
V_305 |= V_354 ;
}
#endif
}
#ifndef F_151
if ( V_310 )
{
V_302 |= V_355 ;
V_304 |= V_355 ;
}
#endif
#ifndef F_24
V_302 |= V_356 ;
V_303 |= V_357 ;
V_304 |= V_356 ;
V_305 |= V_357 ;
#endif
V_233 -> V_302 = V_302 ;
V_233 -> V_303 = V_303 ;
V_233 -> V_358 = V_304 ;
V_233 -> V_359 = V_305 ;
V_233 -> V_360 = 1 ;
}
int F_166 ( T_10 * V_311 , T_1 * V_1 )
{
unsigned long V_361 , V_362 ;
T_16 * V_363 = NULL ;
int V_364 = 0 ;
int V_313 = 0 , V_315 = 0 , V_314 = 0 ;
const V_31 * V_365 = V_1 -> V_130 -> V_131 . V_366 ;
V_361 = V_365 -> V_367 ;
V_362 = V_365 -> V_368 ;
if ( F_167 ( V_365 ) )
{
V_363 = F_160 ( V_311 ) ;
if ( V_363 == NULL ) return 0 ;
V_364 = F_161 ( V_363 ) ;
F_162 ( V_363 ) ;
if ( V_364 > 163 ) return 0 ;
}
F_159 ( V_311 , - 1 , 0 ) ;
if ( ( V_311 -> V_346 ) && ( V_311 -> V_346 -> V_347 ) )
{
V_313 = F_163 ( V_311 -> V_346 -> V_347 ) ;
F_164 ( V_313 , & V_315 , & V_314 ) ;
}
if ( V_361 & V_353 || V_361 & V_350 )
{
if ( F_168 ( V_311 , V_344 ) )
{
F_2 ( V_369 , V_370 ) ;
return 0 ;
}
if ( ( V_361 & V_353 ) && F_169 ( V_1 ) < V_371 )
{
if ( V_314 != V_352 )
{
F_2 ( V_369 , V_372 ) ;
return 0 ;
}
}
if ( ( V_361 & V_350 ) && F_169 ( V_1 ) < V_371 )
{
if ( V_314 != V_348 && V_314 != V_349 )
{
F_2 ( V_369 , V_373 ) ;
return 0 ;
}
}
}
if ( V_362 & V_354 )
{
if ( F_168 ( V_311 , V_345 ) )
{
F_2 ( V_369 , V_374 ) ;
return 0 ;
}
}
return 1 ;
}
T_10 * F_170 ( T_1 * V_1 )
{
unsigned long V_361 , V_362 ;
T_14 * V_233 ;
int V_102 ;
V_233 = V_1 -> V_47 ;
F_150 ( V_233 , V_1 -> V_130 -> V_131 . V_366 ) ;
V_361 = V_1 -> V_130 -> V_131 . V_366 -> V_367 ;
V_362 = V_1 -> V_130 -> V_131 . V_366 -> V_368 ;
if ( V_361 & ( V_350 | V_353 ) )
{
V_102 = V_326 ;
}
else if ( V_362 & V_354 )
{
V_102 = V_326 ;
}
else if ( V_361 & V_334 )
V_102 = V_324 ;
else if ( V_361 & V_335 )
V_102 = V_325 ;
else if ( V_362 & V_337 )
V_102 = V_323 ;
else if ( V_362 & V_336 )
{
if ( V_233 -> V_320 [ V_321 ] . V_143 == NULL )
V_102 = V_322 ;
else
V_102 = V_321 ;
}
else if ( V_362 & V_340 )
{
return ( NULL ) ;
}
else if ( V_362 & V_331 )
V_102 = V_330 ;
else if ( V_362 & V_329 )
V_102 = V_327 ;
else
{
F_2 ( V_375 , V_9 ) ;
return ( NULL ) ;
}
if ( V_233 -> V_320 [ V_102 ] . V_143 == NULL ) return ( NULL ) ;
return ( V_233 -> V_320 [ V_102 ] . V_143 ) ;
}
T_16 * F_171 ( T_1 * V_1 , const V_31 * V_287 , const T_17 * * V_376 )
{
unsigned long V_362 ;
T_14 * V_233 ;
int V_377 = - 1 ;
V_362 = V_287 -> V_368 ;
V_233 = V_1 -> V_47 ;
if ( ( V_362 & V_337 ) &&
( V_233 -> V_320 [ V_323 ] . V_146 != NULL ) )
V_377 = V_323 ;
else if ( V_362 & V_336 )
{
if ( V_233 -> V_320 [ V_322 ] . V_146 != NULL )
V_377 = V_322 ;
else if ( V_233 -> V_320 [ V_321 ] . V_146 != NULL )
V_377 = V_321 ;
}
else if ( ( V_362 & V_354 ) &&
( V_233 -> V_320 [ V_326 ] . V_146 != NULL ) )
V_377 = V_326 ;
if ( V_377 == - 1 )
{
F_2 ( V_378 , V_9 ) ;
return ( NULL ) ;
}
if ( V_376 )
* V_376 = V_233 -> V_320 [ V_377 ] . V_379 ;
return V_233 -> V_320 [ V_377 ] . V_146 ;
}
void F_172 ( T_1 * V_1 , int V_45 )
{
int V_102 ;
if ( V_1 -> V_5 -> V_96 == 0 ) return;
V_102 = V_1 -> V_380 -> V_201 ;
if ( ( V_102 & V_45 ) && ( ! V_1 -> V_6 )
&& ( ( V_102 & V_381 )
|| F_173 ( V_1 -> V_380 , V_1 -> V_5 ) )
&& ( V_1 -> V_380 -> V_382 != NULL ) )
{
F_20 ( & V_1 -> V_5 -> V_60 , 1 , V_383 ) ;
if ( ! V_1 -> V_380 -> V_382 ( V_1 , V_1 -> V_5 ) )
F_4 ( V_1 -> V_5 ) ;
}
if ( ( ! ( V_102 & V_384 ) ) &&
( ( V_102 & V_45 ) == V_45 ) )
{
if ( ( ( ( V_45 & V_385 )
? V_1 -> V_380 -> V_205 . V_208
: V_1 -> V_380 -> V_205 . V_214 ) & 0xff ) == 0xff )
{
F_136 ( V_1 -> V_380 , ( unsigned long ) time ( NULL ) ) ;
}
}
}
const T_3 * F_174 ( T_1 * V_1 )
{
return ( V_1 -> V_2 ) ;
}
int F_175 ( T_1 * V_1 , const T_3 * V_30 )
{
int V_386 = - 1 ;
int V_117 = 1 ;
if ( V_1 -> V_2 != V_30 )
{
if ( V_1 -> V_150 != NULL )
V_386 = ( V_1 -> V_150 == V_1 -> V_2 -> V_151 ) ;
if ( V_1 -> V_2 -> V_15 == V_30 -> V_15 )
V_1 -> V_2 = V_30 ;
else
{
V_1 -> V_2 -> V_27 ( V_1 ) ;
V_1 -> V_2 = V_30 ;
V_117 = V_1 -> V_2 -> V_28 ( V_1 ) ;
}
if ( V_386 == 1 )
V_1 -> V_150 = V_30 -> V_151 ;
else if ( V_386 == 0 )
V_1 -> V_150 = V_30 -> V_75 ;
}
return ( V_117 ) ;
}
int F_176 ( const T_1 * V_1 , int V_102 )
{
int V_387 ;
unsigned long V_171 ;
T_7 * V_121 ;
if ( V_102 > 0 ) return ( V_388 ) ;
if ( ( V_171 = F_177 () ) != 0 )
{
if ( F_178 ( V_171 ) == V_389 )
return ( V_390 ) ;
else
return ( V_391 ) ;
}
if ( ( V_102 < 0 ) && F_179 ( V_1 ) )
{
V_121 = F_64 ( V_1 ) ;
if ( F_180 ( V_121 ) )
return ( V_392 ) ;
else if ( F_181 ( V_121 ) )
return ( V_393 ) ;
else if ( F_182 ( V_121 ) )
{
V_387 = F_183 ( V_121 ) ;
if ( V_387 == V_394 )
return ( V_395 ) ;
else if ( V_387 == V_396 )
return ( V_397 ) ;
else
return ( V_390 ) ;
}
}
if ( ( V_102 < 0 ) && F_184 ( V_1 ) )
{
V_121 = F_65 ( V_1 ) ;
if ( F_181 ( V_121 ) )
return ( V_393 ) ;
else if ( F_180 ( V_121 ) )
return ( V_392 ) ;
else if ( F_182 ( V_121 ) )
{
V_387 = F_183 ( V_121 ) ;
if ( V_387 == V_394 )
return ( V_395 ) ;
else if ( V_387 == V_396 )
return ( V_397 ) ;
else
return ( V_390 ) ;
}
}
if ( ( V_102 < 0 ) && F_185 ( V_1 ) )
{
return ( V_398 ) ;
}
if ( V_102 == 0 )
{
if ( V_1 -> V_15 == V_35 )
{
return ( V_399 ) ;
}
else
{
if ( ( V_1 -> V_7 & V_156 ) &&
( V_1 -> V_130 -> V_400 == V_401 ) )
return ( V_399 ) ;
}
}
return ( V_390 ) ;
}
int F_186 ( T_1 * V_1 )
{
int V_117 = 1 ;
if ( V_1 -> V_150 == NULL )
{
F_2 ( V_402 , V_403 ) ;
return ( - 1 ) ;
}
V_1 -> V_2 -> V_404 ( V_1 ) ;
if ( F_105 ( V_1 ) || F_187 ( V_1 ) )
{
V_117 = V_1 -> V_150 ( V_1 ) ;
}
return ( V_117 ) ;
}
void F_97 ( T_1 * V_1 )
{
V_1 -> V_12 = 1 ;
V_1 -> V_7 = 0 ;
V_1 -> V_10 = V_13 | V_11 ;
V_1 -> V_150 = V_1 -> V_2 -> V_75 ;
F_6 ( V_1 ) ;
F_7 ( & V_1 -> V_22 ) ;
F_7 ( & V_1 -> V_23 ) ;
}
void F_99 ( T_1 * V_1 )
{
V_1 -> V_12 = 0 ;
V_1 -> V_7 = 0 ;
V_1 -> V_10 = V_14 | V_11 ;
V_1 -> V_150 = V_1 -> V_2 -> V_151 ;
F_6 ( V_1 ) ;
F_7 ( & V_1 -> V_22 ) ;
F_7 ( & V_1 -> V_23 ) ;
}
int V_76 ( T_1 * V_1 )
{
F_2 ( V_405 , V_406 ) ;
return ( 0 ) ;
}
int F_188 ( void )
{
F_2 ( V_407 , V_406 ) ;
return ( 0 ) ;
}
int F_189 ( const T_1 * V_1 )
{
F_2 ( V_408 , V_406 ) ;
return ( 0 ) ;
}
T_3 * F_190 ( int V_409 )
{
F_2 ( V_410 , V_406 ) ;
return ( NULL ) ;
}
const char * F_191 ( const T_1 * V_1 )
{
if ( V_1 -> V_15 == V_371 )
return ( L_7 ) ;
else if ( V_1 -> V_15 == V_411 )
return ( L_8 ) ;
if ( V_1 -> V_15 == V_266 )
return ( L_9 ) ;
else if ( V_1 -> V_15 == V_412 )
return ( L_10 ) ;
else if ( V_1 -> V_15 == V_35 )
return ( L_1 ) ;
else
return ( L_11 ) ;
}
T_1 * F_192 ( T_1 * V_1 )
{
F_9 ( V_413 ) * V_32 ;
V_413 * V_414 ;
T_1 * V_117 ;
int V_102 ;
if ( ( V_117 = F_12 ( F_193 ( V_1 ) ) ) == NULL )
return ( NULL ) ;
V_117 -> V_15 = V_1 -> V_15 ;
V_117 -> type = V_1 -> type ;
V_117 -> V_2 = V_1 -> V_2 ;
if ( V_1 -> V_5 != NULL )
{
F_194 ( V_117 , V_1 ) ;
}
else
{
V_117 -> V_2 -> V_27 ( V_117 ) ;
V_117 -> V_2 = V_1 -> V_2 ;
V_117 -> V_2 -> V_28 ( V_117 ) ;
if ( V_1 -> V_47 != NULL )
{
if ( V_117 -> V_47 != NULL )
{
F_25 ( V_117 -> V_47 ) ;
}
V_117 -> V_47 = F_16 ( V_1 -> V_47 ) ;
if ( V_117 -> V_47 == NULL )
goto V_42;
}
F_29 ( V_117 ,
V_1 -> V_53 , V_1 -> V_52 ) ;
}
V_117 -> V_44 = V_1 -> V_44 ;
V_117 -> V_45 = V_1 -> V_45 ;
F_195 ( V_117 , F_196 ( V_1 ) ) ;
F_89 ( V_117 , F_90 ( V_1 ) ) ;
V_117 -> V_49 = V_1 -> V_49 ;
V_117 -> V_50 = V_1 -> V_50 ;
F_85 ( V_117 , F_80 ( V_1 ) ,
F_197 ( V_1 ) ) ;
F_87 ( V_117 , F_81 ( V_1 ) ) ;
V_117 -> V_56 = V_1 -> V_56 ;
F_198 ( V_117 , F_199 ( V_1 ) ) ;
V_117 -> V_415 = V_1 -> V_415 ;
if ( ! F_200 ( V_77 , & V_117 -> V_78 , & V_1 -> V_78 ) )
goto V_42;
if ( V_1 -> V_106 != NULL )
{
if ( ! F_201 ( V_1 -> V_106 , ( char * ) & V_117 -> V_106 ) )
goto V_42;
}
if ( V_1 -> V_105 != NULL )
{
if ( V_1 -> V_105 != V_1 -> V_106 )
{
if ( ! F_201 ( V_1 -> V_105 , ( char * ) & V_117 -> V_105 ) )
goto V_42;
}
else
V_117 -> V_105 = V_117 -> V_106 ;
}
V_117 -> V_17 = V_1 -> V_17 ;
V_117 -> V_25 = V_1 -> V_25 ;
V_117 -> V_150 = V_1 -> V_150 ;
V_117 -> V_12 = V_1 -> V_12 ;
V_117 -> V_8 = V_1 -> V_8 ;
V_117 -> V_166 = V_1 -> V_166 ;
V_117 -> V_58 = V_1 -> V_58 ;
V_117 -> V_7 = V_1 -> V_7 ;
V_117 -> V_10 = V_1 -> V_10 ;
V_117 -> V_19 = V_1 -> V_19 ;
V_117 -> V_416 = 0 ;
V_117 -> V_6 = V_1 -> V_6 ;
F_19 ( V_117 -> V_57 , V_1 -> V_57 ) ;
if ( V_1 -> V_33 != NULL )
{
if ( ( V_117 -> V_33 = F_202 ( V_1 -> V_33 ) ) == NULL )
goto V_42;
}
if ( V_1 -> V_34 != NULL )
if ( ( V_117 -> V_34 = F_202 ( V_1 -> V_34 ) )
== NULL )
goto V_42;
if ( V_1 -> V_113 != NULL )
{
if ( ( V_32 = F_203 ( V_1 -> V_113 ) ) == NULL ) goto V_42;
V_117 -> V_113 = V_32 ;
for ( V_102 = 0 ; V_102 < F_204 ( V_32 ) ; V_102 ++ )
{
V_414 = F_205 ( V_32 , V_102 ) ;
if ( F_206 ( V_32 , V_102 , F_207 ( V_414 ) ) == NULL )
{
V_114 ( V_414 ) ;
goto V_42;
}
}
}
if ( 0 )
{
V_42:
if ( V_117 != NULL ) F_47 ( V_117 ) ;
V_117 = NULL ;
}
return ( V_117 ) ;
}
void F_6 ( T_1 * V_1 )
{
if ( V_1 -> V_417 != NULL )
{
F_208 ( V_1 -> V_417 ) ;
F_27 ( V_1 -> V_417 ) ;
V_1 -> V_417 = NULL ;
}
if ( V_1 -> V_418 != NULL )
{
F_208 ( V_1 -> V_418 ) ;
F_27 ( V_1 -> V_418 ) ;
V_1 -> V_418 = NULL ;
}
#ifndef F_209
if ( V_1 -> V_419 != NULL )
{
F_210 ( V_1 -> V_419 ) ;
V_1 -> V_419 = NULL ;
}
if ( V_1 -> V_420 != NULL )
{
F_210 ( V_1 -> V_420 ) ;
V_1 -> V_420 = NULL ;
}
#endif
}
T_10 * F_211 ( const T_1 * V_1 )
{
if ( V_1 -> V_47 != NULL )
return ( V_1 -> V_47 -> V_142 -> V_143 ) ;
else
return ( NULL ) ;
}
T_16 * F_212 ( T_1 * V_1 )
{
if ( V_1 -> V_47 != NULL )
return ( V_1 -> V_47 -> V_142 -> V_146 ) ;
else
return ( NULL ) ;
}
const V_31 * F_213 ( const T_1 * V_1 )
{
if ( ( V_1 -> V_5 != NULL ) && ( V_1 -> V_5 -> V_287 != NULL ) )
return ( V_1 -> V_5 -> V_287 ) ;
return ( NULL ) ;
}
const void * F_214 ( T_1 * V_1 )
{
return NULL ;
}
const void * F_215 ( T_1 * V_1 )
{
return NULL ;
}
const T_18 * F_214 ( T_1 * V_1 )
{
if ( V_1 -> V_420 != NULL )
return ( V_1 -> V_420 -> V_30 ) ;
return ( NULL ) ;
}
const T_18 * F_215 ( T_1 * V_1 )
{
if ( V_1 -> V_419 != NULL )
return ( V_1 -> V_419 -> V_30 ) ;
return ( NULL ) ;
}
int F_216 ( T_1 * V_1 , int V_421 )
{
T_7 * V_104 ;
if ( V_1 -> V_104 == NULL )
{
V_104 = F_72 ( F_217 () ) ;
if ( V_104 == NULL ) return ( 0 ) ;
V_1 -> V_104 = V_104 ;
}
else
{
V_104 = V_1 -> V_104 ;
if ( V_1 -> V_104 == V_1 -> V_105 )
V_1 -> V_105 = F_52 ( V_1 -> V_105 ) ;
}
( void ) F_218 ( V_104 ) ;
if ( ! F_219 ( V_104 , 1 ) )
{
F_2 ( V_422 , V_123 ) ;
return ( 0 ) ;
}
if ( V_421 )
{
if ( V_1 -> V_105 != V_104 )
V_1 -> V_105 = F_220 ( V_104 , V_1 -> V_105 ) ;
}
else
{
if ( V_1 -> V_105 == V_104 )
V_1 -> V_105 = F_52 ( V_104 ) ;
}
return ( 1 ) ;
}
void F_221 ( T_1 * V_1 )
{
if ( V_1 -> V_104 == NULL ) return;
if ( V_1 -> V_104 == V_1 -> V_105 )
{
V_1 -> V_105 = F_52 ( V_1 -> V_105 ) ;
#ifdef F_49
assert ( V_1 -> V_105 != NULL ) ;
#endif
}
F_53 ( V_1 -> V_104 ) ;
V_1 -> V_104 = NULL ;
}
void F_222 ( T_2 * V_26 , int V_45 )
{
V_26 -> V_58 = V_45 ;
}
int F_223 ( const T_2 * V_26 )
{
return ( V_26 -> V_58 ) ;
}
void F_224 ( T_1 * V_1 , int V_45 )
{
V_1 -> V_58 = V_45 ;
}
int F_225 ( const T_1 * V_1 )
{
return ( V_1 -> V_58 ) ;
}
void F_226 ( T_1 * V_1 , int V_45 )
{
V_1 -> V_7 = V_45 ;
}
int F_227 ( const T_1 * V_1 )
{
return ( V_1 -> V_7 ) ;
}
int F_112 ( const T_1 * V_1 )
{
return ( V_1 -> V_15 ) ;
}
T_2 * F_193 ( const T_1 * V_85 )
{
return ( V_85 -> V_26 ) ;
}
T_2 * F_228 ( T_1 * V_85 , T_2 * V_26 )
{
if ( V_85 -> V_26 == V_26 )
return V_85 -> V_26 ;
#ifndef F_21
if ( V_26 == NULL )
V_26 = V_85 -> V_71 ;
#endif
if ( V_85 -> V_47 != NULL )
F_25 ( V_85 -> V_47 ) ;
V_85 -> V_47 = F_16 ( V_26 -> V_47 ) ;
F_20 ( & V_26 -> V_60 , 1 , V_61 ) ;
if ( V_85 -> V_26 != NULL )
F_26 ( V_85 -> V_26 ) ;
V_85 -> V_26 = V_26 ;
return ( V_85 -> V_26 ) ;
}
int F_229 ( T_2 * V_26 )
{
return ( F_230 ( V_26 -> V_274 ) ) ;
}
int F_231 ( T_2 * V_26 , const char * V_423 ,
const char * V_424 )
{
return ( F_232 ( V_26 -> V_274 , V_423 , V_424 ) ) ;
}
void F_198 ( T_1 * V_85 ,
void (* V_88)( const T_1 * V_85 , int type , int V_425 ) )
{
V_85 -> V_426 = V_88 ;
}
int F_233 ( const T_1 * V_85 )
{
return ( V_85 -> V_10 ) ;
}
void F_234 ( T_1 * V_85 , int V_10 )
{
V_85 -> V_10 = V_10 ;
}
void F_235 ( T_1 * V_85 , long V_195 )
{
V_85 -> V_73 = V_195 ;
}
long F_236 ( const T_1 * V_85 )
{
return ( V_85 -> V_73 ) ;
}
int F_237 ( long V_427 , void * V_428 , T_19 * V_429 ,
T_20 * V_430 , T_21 * V_431 )
{
return F_238 ( V_77 , V_427 , V_428 ,
V_429 , V_430 , V_431 ) ;
}
int F_239 ( T_1 * V_1 , int V_377 , void * V_195 )
{
return ( F_240 ( & V_1 -> V_78 , V_377 , V_195 ) ) ;
}
void * F_241 ( const T_1 * V_1 , int V_377 )
{
return ( F_242 ( & V_1 -> V_78 , V_377 ) ) ;
}
int F_243 ( long V_427 , void * V_428 , T_19 * V_429 ,
T_20 * V_430 , T_21 * V_431 )
{
return F_238 ( V_273 , V_427 , V_428 ,
V_429 , V_430 , V_431 ) ;
}
int F_244 ( T_2 * V_1 , int V_377 , void * V_195 )
{
return ( F_240 ( & V_1 -> V_78 , V_377 , V_195 ) ) ;
}
void * F_245 ( const T_2 * V_1 , int V_377 )
{
return ( F_242 ( & V_1 -> V_78 , V_377 ) ) ;
}
int F_246 ( T_1 * V_1 )
{
return ( 1 ) ;
}
T_22 * F_247 ( const T_2 * V_26 )
{
return ( V_26 -> V_274 ) ;
}
void F_248 ( T_2 * V_26 , T_22 * V_432 )
{
if ( V_26 -> V_274 != NULL )
F_138 ( V_26 -> V_274 ) ;
V_26 -> V_274 = V_432 ;
}
int F_249 ( const T_1 * V_1 )
{
return ( V_1 -> V_17 ) ;
}
void F_250 ( T_2 * V_26 , T_23 * (* V_88)( T_1 * V_85 ,
int V_433 ,
int V_434 ) )
{
F_117 ( V_26 , V_435 , ( void ( * ) ( void ) ) V_88 ) ;
}
void F_251 ( T_1 * V_85 , T_23 * (* V_88)( T_1 * V_85 ,
int V_433 ,
int V_434 ) )
{
F_113 ( V_85 , V_435 , ( void ( * ) ( void ) ) V_88 ) ;
}
T_23 * V_88 ( T_1 * V_85 , int V_433 , int V_434 )
{}
void F_252 ( T_2 * V_26 , T_24 * (* F_253)( T_1 * V_85 , int V_433 ,
int V_434 ) )
{
F_117 ( V_26 , V_436 , ( void ( * ) ( void ) ) F_253 ) ;
}
void F_254 ( T_1 * V_85 , T_24 * (* F_253)( T_1 * V_85 , int V_433 ,
int V_434 ) )
{
F_113 ( V_85 , V_436 , ( void ( * ) ( void ) ) F_253 ) ;
}
void F_255 ( T_2 * V_26 , T_25 * (* F_256)( T_1 * V_85 , int V_433 ,
int V_434 ) )
{
F_117 ( V_26 , V_437 , ( void ( * ) ( void ) ) F_256 ) ;
}
void F_257 ( T_1 * V_85 , T_25 * (* F_256)( T_1 * V_85 , int V_433 ,
int V_434 ) )
{
F_113 ( V_85 , V_437 , ( void ( * ) ( void ) ) F_256 ) ;
}
int F_258 ( T_2 * V_26 , const char * V_438 )
{
if ( V_438 != NULL && strlen ( V_438 ) > V_439 )
{
F_2 ( V_440 , V_441 ) ;
return 0 ;
}
if ( V_26 -> V_278 != NULL )
F_27 ( V_26 -> V_278 ) ;
if ( V_438 != NULL )
{
V_26 -> V_278 = F_259 ( V_438 ) ;
if ( V_26 -> V_278 == NULL )
return 0 ;
}
else
V_26 -> V_278 = NULL ;
return 1 ;
}
int F_260 ( T_1 * V_1 , const char * V_438 )
{
if ( V_1 == NULL )
return 0 ;
if ( V_1 -> V_5 == NULL )
return 1 ;
if ( V_438 != NULL && strlen ( V_438 ) > V_439 )
{
F_2 ( V_442 , V_441 ) ;
return 0 ;
}
if ( V_1 -> V_5 -> V_278 != NULL )
F_27 ( V_1 -> V_5 -> V_278 ) ;
if ( V_438 != NULL )
{
V_1 -> V_5 -> V_278 = F_259 ( V_438 ) ;
if ( V_1 -> V_5 -> V_278 == NULL )
return 0 ;
}
else
V_1 -> V_5 -> V_278 = NULL ;
return 1 ;
}
const char * F_261 ( const T_1 * V_1 )
{
if ( V_1 == NULL || V_1 -> V_5 == NULL )
return NULL ;
return ( V_1 -> V_5 -> V_278 ) ;
}
const char * F_262 ( const T_1 * V_1 )
{
if ( V_1 == NULL || V_1 -> V_5 == NULL )
return NULL ;
return ( V_1 -> V_5 -> V_443 ) ;
}
void F_263 ( T_2 * V_26 , void (* V_88)( int V_192 , int V_15 , int V_193 , const void * V_128 , T_8 V_194 , T_1 * V_85 , void * V_195 ) )
{
F_117 ( V_26 , V_191 , ( void ( * ) ( void ) ) V_88 ) ;
}
void F_264 ( T_1 * V_85 , void (* V_88)( int V_192 , int V_15 , int V_193 , const void * V_128 , T_8 V_194 , T_1 * V_85 , void * V_195 ) )
{
F_113 ( V_85 , V_191 , ( void ( * ) ( void ) ) V_88 ) ;
}
T_26 * F_265 ( T_26 * * V_444 , const T_17 * V_445 )
{
F_7 ( V_444 ) ;
* V_444 = F_266 () ;
if ( V_445 ) F_267 ( * V_444 , V_445 , NULL ) ;
return * V_444 ;
}
void F_7 ( T_26 * * V_444 )
{
if ( * V_444 ) F_268 ( * V_444 ) ;
* V_444 = NULL ;
}
void F_269 ( T_1 * V_1 , int V_415 )
{
V_1 -> V_415 = V_415 ;
}
int F_270 ( T_1 * V_1 )
{
return V_1 -> V_6 ;
}
