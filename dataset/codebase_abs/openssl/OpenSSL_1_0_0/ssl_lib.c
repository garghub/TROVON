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
if (s->new_session) return(1);
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
#endif
V_1 -> V_72 = V_73 ;
V_1 -> V_2 = V_26 -> V_2 ;
if ( ! V_1 -> V_2 -> V_28 ( V_1 ) )
goto V_42;
V_1 -> V_60 = 1 ;
V_1 -> V_12 = ( V_26 -> V_2 -> V_74 == V_75 ) ? 0 : 1 ;
F_1 ( V_1 ) ;
F_22 ( V_76 , V_1 , & V_1 -> V_77 ) ;
#ifndef F_23
V_1 -> V_78 = V_26 -> V_78 ;
V_1 -> V_79 = V_26 -> V_79 ;
#endif
return ( V_1 ) ;
V_42:
if ( V_1 != NULL )
{
if ( V_1 -> V_47 != NULL )
F_24 ( V_1 -> V_47 ) ;
if ( V_1 -> V_26 != NULL )
F_25 ( V_1 -> V_26 ) ;
F_26 ( V_1 ) ;
}
F_2 ( V_39 , V_80 ) ;
return ( NULL ) ;
}
int F_27 ( T_2 * V_26 , const unsigned char * V_53 ,
unsigned int V_81 )
{
if( V_81 > sizeof V_26 -> V_53 )
{
F_2 ( V_82 , V_83 ) ;
return 0 ;
}
V_26 -> V_52 = V_81 ;
memcpy ( V_26 -> V_53 , V_53 , V_81 ) ;
return 1 ;
}
int F_28 ( T_1 * V_84 , const unsigned char * V_53 ,
unsigned int V_81 )
{
if( V_81 > V_85 )
{
F_2 ( V_86 , V_83 ) ;
return 0 ;
}
V_84 -> V_52 = V_81 ;
memcpy ( V_84 -> V_53 , V_53 , V_81 ) ;
return 1 ;
}
int F_29 ( T_2 * V_26 , T_4 V_87 )
{
F_30 ( V_61 ) ;
V_26 -> V_56 = V_87 ;
F_31 ( V_61 ) ;
return 1 ;
}
int F_32 ( T_1 * V_84 , T_4 V_87 )
{
F_30 ( V_88 ) ;
V_84 -> V_56 = V_87 ;
F_31 ( V_88 ) ;
return 1 ;
}
int F_33 ( const T_1 * V_84 , const unsigned char * V_89 ,
unsigned int V_90 )
{
T_5 V_91 , * V_92 ;
if( V_90 > sizeof V_91 . V_93 )
return 0 ;
V_91 . V_94 = V_84 -> V_15 ;
V_91 . V_95 = V_90 ;
memcpy ( V_91 . V_93 , V_89 , V_90 ) ;
if( ( V_91 . V_94 == V_35 ) &&
( V_90 < V_96 ) )
{
memset ( V_91 . V_93 + V_90 , 0 ,
V_96 - V_90 ) ;
V_91 . V_95 = V_96 ;
}
F_34 ( V_61 ) ;
V_92 = F_35 ( V_84 -> V_26 -> V_97 , & V_91 ) ;
F_36 ( V_61 ) ;
return ( V_92 != NULL ) ;
}
int F_37 ( T_2 * V_1 , int V_98 )
{
return F_38 ( V_1 -> V_57 , V_98 ) ;
}
int F_39 ( T_1 * V_1 , int V_98 )
{
return F_38 ( V_1 -> V_57 , V_98 ) ;
}
int F_40 ( T_2 * V_1 , int V_99 )
{
return F_41 ( V_1 -> V_57 , V_99 ) ;
}
int F_42 ( T_1 * V_1 , int V_99 )
{
return F_41 ( V_1 -> V_57 , V_99 ) ;
}
int F_43 ( T_2 * V_26 , T_6 * V_100 )
{
return F_44 ( V_26 -> V_57 , V_100 ) ;
}
int F_45 ( T_1 * V_84 , T_6 * V_100 )
{
return F_44 ( V_84 -> V_57 , V_100 ) ;
}
void F_46 ( T_1 * V_1 )
{
int V_101 ;
if( V_1 == NULL )
return;
V_101 = F_20 ( & V_1 -> V_60 , - 1 , V_88 ) ;
#ifdef F_47
F_47 ( L_2 , V_1 ) ;
#endif
if ( V_101 > 0 ) return;
#ifdef F_48
if ( V_101 < 0 )
{
fprintf ( V_102 , L_3 ) ;
abort () ;
}
#endif
if ( V_1 -> V_57 )
F_49 ( V_1 -> V_57 ) ;
F_50 ( V_76 , V_1 , & V_1 -> V_77 ) ;
if ( V_1 -> V_103 != NULL )
{
if ( V_1 -> V_103 == V_1 -> V_104 )
{
V_1 -> V_104 = F_51 ( V_1 -> V_104 ) ;
}
F_52 ( V_1 -> V_103 ) ;
V_1 -> V_103 = NULL ;
}
if ( V_1 -> V_105 != NULL )
F_53 ( V_1 -> V_105 ) ;
if ( ( V_1 -> V_104 != NULL ) && ( V_1 -> V_104 != V_1 -> V_105 ) )
F_53 ( V_1 -> V_104 ) ;
if ( V_1 -> V_21 != NULL ) F_5 ( V_1 -> V_21 ) ;
if ( V_1 -> V_33 != NULL ) F_54 ( V_1 -> V_33 ) ;
if ( V_1 -> V_34 != NULL ) F_54 ( V_1 -> V_34 ) ;
if ( V_1 -> V_5 != NULL )
{
F_3 ( V_1 ) ;
F_4 ( V_1 -> V_5 ) ;
}
F_6 ( V_1 ) ;
F_7 ( & V_1 -> V_22 ) ;
F_7 ( & V_1 -> V_23 ) ;
if ( V_1 -> V_47 != NULL ) F_24 ( V_1 -> V_47 ) ;
#ifndef F_21
if ( V_1 -> V_106 )
F_26 ( V_1 -> V_106 ) ;
if ( V_1 -> V_71 ) F_25 ( V_1 -> V_71 ) ;
#ifndef F_55
if ( V_1 -> V_107 ) F_26 ( V_1 -> V_107 ) ;
if ( V_1 -> V_108 ) F_26 ( V_1 -> V_108 ) ;
#endif
if ( V_1 -> V_109 ) F_26 ( V_1 -> V_109 ) ;
if ( V_1 -> V_68 )
F_56 ( V_1 -> V_68 ,
V_110 ) ;
if ( V_1 -> V_67 )
F_57 ( V_1 -> V_67 , V_111 ) ;
if ( V_1 -> V_69 )
F_26 ( V_1 -> V_69 ) ;
#endif
if ( V_1 -> V_112 != NULL )
F_58 ( V_1 -> V_112 , V_113 ) ;
if ( V_1 -> V_2 != NULL ) V_1 -> V_2 -> V_27 ( V_1 ) ;
if ( V_1 -> V_26 ) F_25 ( V_1 -> V_26 ) ;
#ifndef F_14
if ( V_1 -> V_43 != NULL )
F_59 ( V_1 -> V_43 ) ;
#endif
F_26 ( V_1 ) ;
}
void F_60 ( T_1 * V_1 , T_7 * V_105 , T_7 * V_104 )
{
if ( V_1 -> V_103 != NULL )
{
if ( V_1 -> V_104 == V_1 -> V_103 )
{
V_1 -> V_104 = V_1 -> V_104 -> V_114 ;
V_1 -> V_103 -> V_114 = NULL ;
}
}
if ( ( V_1 -> V_105 != NULL ) && ( V_1 -> V_105 != V_105 ) )
F_53 ( V_1 -> V_105 ) ;
if ( ( V_1 -> V_104 != NULL ) && ( V_1 -> V_104 != V_104 ) && ( V_1 -> V_105 != V_1 -> V_104 ) )
F_53 ( V_1 -> V_104 ) ;
V_1 -> V_105 = V_105 ;
V_1 -> V_104 = V_104 ;
}
T_7 * F_61 ( const T_1 * V_1 )
{ return ( V_1 -> V_105 ) ; }
T_7 * F_62 ( const T_1 * V_1 )
{ return ( V_1 -> V_104 ) ; }
int F_63 ( const T_1 * V_1 )
{
return ( F_64 ( V_1 ) ) ;
}
int F_64 ( const T_1 * V_1 )
{
int V_115 = - 1 ;
T_7 * V_116 , * V_91 ;
V_116 = F_61 ( V_1 ) ;
V_91 = F_65 ( V_116 , V_117 ) ;
if ( V_91 != NULL )
F_66 ( V_91 , & V_115 ) ;
return ( V_115 ) ;
}
int F_67 ( const T_1 * V_1 )
{
int V_115 = - 1 ;
T_7 * V_116 , * V_91 ;
V_116 = F_62 ( V_1 ) ;
V_91 = F_65 ( V_116 , V_117 ) ;
if ( V_91 != NULL )
F_66 ( V_91 , & V_115 ) ;
return ( V_115 ) ;
}
int F_68 ( T_1 * V_1 , int V_118 )
{
int V_115 = 0 ;
T_7 * V_119 = NULL ;
V_119 = F_69 ( F_70 () ) ;
if ( V_119 == NULL )
{
F_2 ( V_120 , V_121 ) ;
goto V_42;
}
F_71 ( V_119 , V_118 , V_122 ) ;
F_60 ( V_1 , V_119 , V_119 ) ;
V_115 = 1 ;
V_42:
return ( V_115 ) ;
}
int F_72 ( T_1 * V_1 , int V_118 )
{
int V_115 = 0 ;
T_7 * V_119 = NULL ;
if ( ( V_1 -> V_105 == NULL ) || ( F_73 ( V_1 -> V_105 ) != V_123 )
|| ( ( int ) F_66 ( V_1 -> V_105 , NULL ) != V_118 ) )
{
V_119 = F_69 ( F_70 () ) ;
if ( V_119 == NULL )
{ F_2 ( V_124 , V_121 ) ; goto V_42; }
F_71 ( V_119 , V_118 , V_122 ) ;
F_60 ( V_1 , F_61 ( V_1 ) , V_119 ) ;
}
else
F_60 ( V_1 , F_61 ( V_1 ) , F_61 ( V_1 ) ) ;
V_115 = 1 ;
V_42:
return ( V_115 ) ;
}
int F_74 ( T_1 * V_1 , int V_118 )
{
int V_115 = 0 ;
T_7 * V_119 = NULL ;
if ( ( V_1 -> V_104 == NULL ) || ( F_73 ( V_1 -> V_104 ) != V_123 )
|| ( ( int ) F_66 ( V_1 -> V_104 , NULL ) != V_118 ) )
{
V_119 = F_69 ( F_70 () ) ;
if ( V_119 == NULL )
{
F_2 ( V_125 , V_121 ) ;
goto V_42;
}
F_71 ( V_119 , V_118 , V_122 ) ;
F_60 ( V_1 , V_119 , F_62 ( V_1 ) ) ;
}
else
F_60 ( V_1 , F_62 ( V_1 ) , F_62 ( V_1 ) ) ;
V_115 = 1 ;
V_42:
return ( V_115 ) ;
}
T_8 F_75 ( const T_1 * V_1 , void * V_126 , T_8 V_127 )
{
T_8 V_115 = 0 ;
if ( V_1 -> V_128 != NULL )
{
V_115 = V_1 -> V_128 -> V_129 . V_130 ;
if ( V_127 > V_115 )
V_127 = V_115 ;
memcpy ( V_126 , V_1 -> V_128 -> V_129 . V_131 , V_127 ) ;
}
return V_115 ;
}
T_8 F_76 ( const T_1 * V_1 , void * V_126 , T_8 V_127 )
{
T_8 V_115 = 0 ;
if ( V_1 -> V_128 != NULL )
{
V_115 = V_1 -> V_128 -> V_129 . V_132 ;
if ( V_127 > V_115 )
V_127 = V_115 ;
memcpy ( V_126 , V_1 -> V_128 -> V_129 . V_133 , V_127 ) ;
}
return V_115 ;
}
int F_77 ( const T_1 * V_1 )
{
return ( V_1 -> V_51 ) ;
}
int F_78 ( const T_1 * V_1 )
{
return F_79 ( V_1 -> V_57 ) ;
}
int F_80 ( const T_2 * V_26 )
{
return ( V_26 -> V_51 ) ;
}
int F_81 ( const T_2 * V_26 )
{
return F_79 ( V_26 -> V_57 ) ;
}
void F_82 ( T_1 * V_1 , int V_45 ,
int (* F_83)( int V_134 , T_9 * V_26 ) )
{
V_1 -> V_51 = V_45 ;
if ( F_83 != NULL )
V_1 -> V_54 = F_83 ;
}
void F_84 ( T_1 * V_1 , int V_135 )
{
F_85 ( V_1 -> V_57 , V_135 ) ;
}
void F_86 ( T_1 * V_1 , int V_136 )
{
V_1 -> V_48 = V_136 ;
}
int F_87 ( const T_1 * V_1 )
{
return ( V_1 -> V_48 ) ;
}
int F_88 ( const T_1 * V_1 )
{
return ( V_1 -> V_2 -> V_137 ( V_1 ) ) ;
}
T_10 * F_89 ( const T_1 * V_1 )
{
T_10 * V_91 ;
if ( ( V_1 == NULL ) || ( V_1 -> V_5 == NULL ) )
V_91 = NULL ;
else
V_91 = V_1 -> V_5 -> V_138 ;
if ( V_91 == NULL ) return ( V_91 ) ;
F_20 ( & V_91 -> V_60 , 1 , V_139 ) ;
return ( V_91 ) ;
}
int F_90 ( const T_2 * V_26 )
{
if ( ( V_26 == NULL ) ||
( V_26 -> V_47 == NULL ) ||
( V_26 -> V_47 -> V_140 -> V_141 == NULL ) )
{
F_2 ( V_142 , V_143 ) ;
return ( 0 ) ;
}
if ( V_26 -> V_47 -> V_140 -> V_144 == NULL )
{
F_2 ( V_142 , V_145 ) ;
return ( 0 ) ;
}
return ( F_91 ( V_26 -> V_47 -> V_140 -> V_141 , V_26 -> V_47 -> V_140 -> V_144 ) ) ;
}
int F_92 ( const T_1 * V_84 )
{
if ( V_84 == NULL )
{
F_2 ( V_146 , V_147 ) ;
return ( 0 ) ;
}
if ( V_84 -> V_47 == NULL )
{
F_2 ( V_146 , V_143 ) ;
return 0 ;
}
if ( V_84 -> V_47 -> V_140 -> V_141 == NULL )
{
F_2 ( V_146 , V_143 ) ;
return ( 0 ) ;
}
if ( V_84 -> V_47 -> V_140 -> V_144 == NULL )
{
F_2 ( V_146 , V_145 ) ;
return ( 0 ) ;
}
return ( F_91 ( V_84 -> V_47 -> V_140 -> V_141 ,
V_84 -> V_47 -> V_140 -> V_144 ) ) ;
}
int F_93 ( T_1 * V_1 )
{
if ( V_1 -> V_148 == 0 )
F_94 ( V_1 ) ;
return ( V_1 -> V_2 -> V_74 ( V_1 ) ) ;
}
int F_95 ( T_1 * V_1 )
{
if ( V_1 -> V_148 == 0 )
F_96 ( V_1 ) ;
return ( V_1 -> V_2 -> V_149 ( V_1 ) ) ;
}
long F_97 ( const T_1 * V_1 )
{
return ( V_1 -> V_2 -> V_150 () ) ;
}
int F_98 ( T_1 * V_1 , void * V_126 , int V_151 )
{
if ( V_1 -> V_148 == 0 )
{
F_2 ( V_152 , V_153 ) ;
return - 1 ;
}
if ( V_1 -> V_7 & V_154 )
{
V_1 -> V_17 = V_18 ;
return ( 0 ) ;
}
return ( V_1 -> V_2 -> V_155 ( V_1 , V_126 , V_151 ) ) ;
}
int F_99 ( T_1 * V_1 , void * V_126 , int V_151 )
{
if ( V_1 -> V_148 == 0 )
{
F_2 ( V_156 , V_153 ) ;
return - 1 ;
}
if ( V_1 -> V_7 & V_154 )
{
return ( 0 ) ;
}
return ( V_1 -> V_2 -> V_157 ( V_1 , V_126 , V_151 ) ) ;
}
int F_100 ( T_1 * V_1 , const void * V_126 , int V_151 )
{
if ( V_1 -> V_148 == 0 )
{
F_2 ( V_158 , V_153 ) ;
return - 1 ;
}
if ( V_1 -> V_7 & V_159 )
{
V_1 -> V_17 = V_18 ;
F_2 ( V_158 , V_160 ) ;
return ( - 1 ) ;
}
return ( V_1 -> V_2 -> V_161 ( V_1 , V_126 , V_151 ) ) ;
}
int F_101 ( T_1 * V_1 )
{
if ( V_1 -> V_148 == 0 )
{
F_2 ( V_162 , V_153 ) ;
return - 1 ;
}
if ( ( V_1 != NULL ) && ! F_102 ( V_1 ) )
return ( V_1 -> V_2 -> V_163 ( V_1 ) ) ;
else
return ( 1 ) ;
}
int F_103 ( T_1 * V_1 )
{
if ( V_1 -> V_8 == 0 )
{
V_1 -> V_8 = 1 ;
}
return ( V_1 -> V_2 -> V_164 ( V_1 ) ) ;
}
int F_104 ( T_1 * V_1 )
{
return ( V_1 -> V_8 != 0 ) ;
}
long F_105 ( T_1 * V_1 , int V_165 , long V_166 , void * V_167 )
{
long V_168 ;
switch ( V_165 )
{
case V_169 :
return ( V_1 -> V_48 ) ;
case V_170 :
V_168 = V_1 -> V_48 ;
V_1 -> V_48 = V_166 ;
return ( V_168 ) ;
case V_171 :
V_1 -> V_50 = V_167 ;
return 1 ;
case V_172 :
return ( V_1 -> V_44 |= V_166 ) ;
case V_173 :
return ( V_1 -> V_44 &= ~ V_166 ) ;
case V_174 :
return ( V_1 -> V_45 |= V_166 ) ;
case V_175 :
return ( V_1 -> V_45 &= ~ V_166 ) ;
case V_176 :
return ( V_1 -> V_46 ) ;
case V_177 :
V_168 = V_1 -> V_46 ;
V_1 -> V_46 = V_166 ;
return ( V_168 ) ;
case V_178 :
if ( F_106 ( V_1 ) == V_179 ||
F_106 ( V_1 ) == V_180 )
{
V_1 -> V_181 -> V_182 = V_166 ;
return V_166 ;
}
return 0 ;
case V_183 :
if ( V_166 < 512 || V_166 > V_184 )
return 0 ;
V_1 -> V_59 = V_166 ;
return 1 ;
case V_185 :
if ( V_1 -> V_128 )
return V_1 -> V_128 -> V_186 ;
else return 0 ;
default:
return ( V_1 -> V_2 -> V_187 ( V_1 , V_165 , V_166 , V_167 ) ) ;
}
}
long F_107 ( T_1 * V_1 , int V_165 , void (* F_108)( void ) )
{
switch( V_165 )
{
case V_188 :
V_1 -> V_49 = ( void (*) ( int V_189 , int V_15 , int V_190 , const void * V_126 , T_8 V_191 , T_1 * V_84 , void * V_192 ) ) ( F_108 ) ;
return 1 ;
default:
return ( V_1 -> V_2 -> V_193 ( V_1 , V_165 , F_108 ) ) ;
}
}
long F_109 ( T_2 * V_26 , int V_165 , long V_166 , void * V_167 )
{
long V_168 ;
switch ( V_165 )
{
case V_169 :
return ( V_26 -> V_48 ) ;
case V_170 :
V_168 = V_26 -> V_48 ;
V_26 -> V_48 = V_166 ;
return ( V_168 ) ;
case V_171 :
V_26 -> V_50 = V_167 ;
return 1 ;
case V_176 :
return ( V_26 -> V_46 ) ;
case V_177 :
V_168 = V_26 -> V_46 ;
V_26 -> V_46 = V_166 ;
return ( V_168 ) ;
case V_194 :
V_168 = V_26 -> V_195 ;
V_26 -> V_195 = V_166 ;
return ( V_168 ) ;
case V_196 :
return ( V_26 -> V_195 ) ;
case V_197 :
V_168 = V_26 -> V_198 ;
V_26 -> V_198 = V_166 ;
return ( V_168 ) ;
case V_199 :
return ( V_26 -> V_198 ) ;
case V_200 :
return ( F_110 ( V_26 -> V_97 ) ) ;
case V_201 :
return ( V_26 -> V_202 . V_203 ) ;
case V_204 :
return ( V_26 -> V_202 . V_205 ) ;
case V_206 :
return ( V_26 -> V_202 . V_207 ) ;
case V_208 :
return ( V_26 -> V_202 . V_209 ) ;
case V_210 :
return ( V_26 -> V_202 . V_211 ) ;
case V_212 :
return ( V_26 -> V_202 . V_213 ) ;
case V_214 :
return ( V_26 -> V_202 . V_215 ) ;
case V_216 :
return ( V_26 -> V_202 . V_217 ) ;
case V_218 :
return ( V_26 -> V_202 . V_219 ) ;
case V_220 :
return ( V_26 -> V_202 . V_221 ) ;
case V_222 :
return ( V_26 -> V_202 . V_223 ) ;
case V_172 :
return ( V_26 -> V_44 |= V_166 ) ;
case V_173 :
return ( V_26 -> V_44 &= ~ V_166 ) ;
case V_174 :
return ( V_26 -> V_45 |= V_166 ) ;
case V_175 :
return ( V_26 -> V_45 &= ~ V_166 ) ;
case V_183 :
if ( V_166 < 512 || V_166 > V_184 )
return 0 ;
V_26 -> V_59 = V_166 ;
return 1 ;
default:
return ( V_26 -> V_2 -> V_224 ( V_26 , V_165 , V_166 , V_167 ) ) ;
}
}
long F_111 ( T_2 * V_26 , int V_165 , void (* F_108)( void ) )
{
switch( V_165 )
{
case V_188 :
V_26 -> V_49 = ( void (*) ( int V_189 , int V_15 , int V_190 , const void * V_126 , T_8 V_191 , T_1 * V_84 , void * V_192 ) ) ( F_108 ) ;
return 1 ;
default:
return ( V_26 -> V_2 -> V_225 ( V_26 , V_165 , F_108 ) ) ;
}
}
int F_112 ( const V_31 * V_226 , const V_31 * V_116 )
{
long V_168 ;
V_168 = V_226 -> V_89 - V_116 -> V_89 ;
if ( V_168 == 0L )
return ( 0 ) ;
else
return ( ( V_168 > 0 ) ? 1 : - 1 ) ;
}
int F_113 ( const V_31 * const * V_227 ,
const V_31 * const * V_228 )
{
long V_168 ;
V_168 = ( * V_227 ) -> V_89 - ( * V_228 ) -> V_89 ;
if ( V_168 == 0L )
return ( 0 ) ;
else
return ( ( V_168 > 0 ) ? 1 : - 1 ) ;
}
char * F_114 ( const T_1 * V_1 , int V_229 )
{
V_31 * V_230 ;
F_9 ( V_31 ) * V_32 ;
if ( V_1 == NULL ) return ( NULL ) ;
V_32 = F_115 ( V_1 ) ;
if ( ( V_32 == NULL ) || ( F_11 ( V_32 ) <= V_229 ) )
return ( NULL ) ;
V_230 = F_116 ( V_32 , V_229 ) ;
if ( V_230 == NULL ) return ( NULL ) ;
return ( V_230 -> V_231 ) ;
}
int F_117 ( T_2 * V_26 , const char * V_232 )
{
F_9 ( V_31 ) * V_32 ;
V_32 = F_10 ( V_26 -> V_2 , & V_26 -> V_33 ,
& V_26 -> V_34 , V_232 ) ;
if ( V_32 == NULL )
return 0 ;
else if ( F_11 ( V_32 ) == 0 )
{
F_2 ( V_233 , V_234 ) ;
return 0 ;
}
return 1 ;
}
int F_118 ( T_1 * V_1 , const char * V_232 )
{
F_9 ( V_31 ) * V_32 ;
V_32 = F_10 ( V_1 -> V_26 -> V_2 , & V_1 -> V_33 ,
& V_1 -> V_34 , V_232 ) ;
if ( V_32 == NULL )
return 0 ;
else if ( F_11 ( V_32 ) == 0 )
{
F_2 ( V_235 , V_234 ) ;
return 0 ;
}
return 1 ;
}
char * F_119 ( const T_1 * V_1 , char * V_126 , int V_191 )
{
char * V_92 ;
F_9 ( V_31 ) * V_32 ;
V_31 * V_230 ;
int V_101 ;
if ( ( V_1 -> V_5 == NULL ) || ( V_1 -> V_5 -> V_236 == NULL ) ||
( V_191 < 2 ) )
return ( NULL ) ;
V_92 = V_126 ;
V_32 = V_1 -> V_5 -> V_236 ;
for ( V_101 = 0 ; V_101 < F_11 ( V_32 ) ; V_101 ++ )
{
int V_229 ;
V_230 = F_116 ( V_32 , V_101 ) ;
V_229 = strlen ( V_230 -> V_231 ) ;
if ( V_229 + 1 > V_191 )
{
if ( V_92 != V_126 )
-- V_92 ;
* V_92 = '\0' ;
return V_126 ;
}
strcpy ( V_92 , V_230 -> V_231 ) ;
V_92 += V_229 ;
* ( V_92 ++ ) = ':' ;
V_191 -= V_229 + 1 ;
}
V_92 [ - 1 ] = '\0' ;
return ( V_126 ) ;
}
char * F_120 ( const T_1 * V_1 , const int type )
{
if ( type != V_237 )
return NULL ;
return V_1 -> V_5 && ! V_1 -> V_106 ?
V_1 -> V_5 -> V_106 :
V_1 -> V_106 ;
}
int F_121 ( const T_1 * V_1 )
{
if ( V_1 -> V_5 && ( ! V_1 -> V_106 ? V_1 -> V_5 -> V_106 : V_1 -> V_106 ) )
return V_237 ;
return - 1 ;
}
static unsigned long F_122 ( const T_5 * V_226 )
{
unsigned long V_168 ;
V_168 = ( unsigned long )
( ( unsigned int ) V_226 -> V_93 [ 0 ] ) |
( ( unsigned int ) V_226 -> V_93 [ 1 ] << 8L ) |
( ( unsigned long ) V_226 -> V_93 [ 2 ] << 16L ) |
( ( unsigned long ) V_226 -> V_93 [ 3 ] << 24L ) ;
return ( V_168 ) ;
}
static int F_123 ( const T_5 * V_226 , const T_5 * V_116 )
{
if ( V_226 -> V_94 != V_116 -> V_94 )
return ( 1 ) ;
if ( V_226 -> V_95 != V_116 -> V_95 )
return ( 1 ) ;
return ( memcmp ( V_226 -> V_93 , V_116 -> V_93 , V_226 -> V_95 ) ) ;
}
void
F_124 ( T_11 * V_238 )
{
T_12 * V_239 , * V_240 ;
for ( V_239 = V_238 -> V_241 ; V_239 ; V_239 = V_240 )
{
V_240 = V_239 -> V_240 ;
F_26 ( V_239 ) ;
}
F_26 ( V_238 ) ;
}
void F_25 ( T_2 * V_226 )
{
int V_101 ;
if ( V_226 == NULL ) return;
V_101 = F_20 ( & V_226 -> V_60 , - 1 , V_61 ) ;
#ifdef F_47
F_47 ( L_4 , V_226 ) ;
#endif
if ( V_101 > 0 ) return;
#ifdef F_48
if ( V_101 < 0 )
{
fprintf ( V_102 , L_5 ) ;
abort () ;
}
#endif
if ( V_226 -> V_57 )
F_49 ( V_226 -> V_57 ) ;
if ( V_226 -> V_97 != NULL )
F_125 ( V_226 , 0 ) ;
F_50 ( V_242 , V_226 , & V_226 -> V_77 ) ;
if ( V_226 -> V_97 != NULL )
F_126 ( V_226 -> V_97 ) ;
if ( V_226 -> V_243 != NULL )
F_127 ( V_226 -> V_243 ) ;
if ( V_226 -> V_33 != NULL )
F_54 ( V_226 -> V_33 ) ;
if ( V_226 -> V_34 != NULL )
F_54 ( V_226 -> V_34 ) ;
if ( V_226 -> V_47 != NULL )
F_24 ( V_226 -> V_47 ) ;
if ( V_226 -> V_112 != NULL )
F_58 ( V_226 -> V_112 , V_113 ) ;
if ( V_226 -> V_244 != NULL )
F_128 ( V_226 -> V_244 , V_245 ) ;
#if 0
if (a->comp_methods != NULL)
sk_SSL_COMP_pop_free(a->comp_methods,SSL_COMP_free);
#else
V_226 -> V_246 = NULL ;
#endif
#ifndef F_23
if ( V_226 -> V_247 )
F_26 ( V_226 -> V_247 ) ;
#endif
#ifndef F_129
if ( V_226 -> V_248 )
F_130 ( V_226 -> V_248 ) ;
#endif
#ifndef F_131
if ( V_226 -> V_249 )
F_124 ( V_226 -> V_249 ) ;
if ( V_226 -> V_250 )
F_124 ( V_226 -> V_250 ) ;
#endif
F_26 ( V_226 ) ;
}
void F_132 ( T_2 * V_26 , T_13 * V_87 )
{
V_26 -> V_251 = V_87 ;
}
void F_133 ( T_2 * V_26 , void * V_252 )
{
V_26 -> V_253 = V_252 ;
}
void F_134 ( T_2 * V_26 , int (* V_87)( T_9 * , void * ) , void * V_192 )
{
V_26 -> V_254 = V_87 ;
V_26 -> V_255 = V_192 ;
}
void F_135 ( T_2 * V_26 , int V_45 , int (* V_87)( int , T_9 * ) )
{
V_26 -> V_51 = V_45 ;
V_26 -> V_55 = V_87 ;
}
void F_136 ( T_2 * V_26 , int V_135 )
{
F_85 ( V_26 -> V_57 , V_135 ) ;
}
void F_137 ( T_14 * V_230 , const V_31 * V_256 )
{
T_15 * V_257 ;
int V_258 , V_259 , V_260 , V_261 , V_262 , V_263 , V_264 ;
int V_265 , V_266 , V_267 ;
int V_268 , V_269 , V_270 ;
unsigned long V_271 , V_272 , V_273 , V_274 ;
int V_275 , V_276 , V_277 , V_278 ;
#ifndef F_138
int V_279 ;
#endif
T_10 * V_280 = NULL ;
T_16 * V_281 = NULL ;
int V_282 = 0 ;
if ( V_230 == NULL ) return;
V_270 = F_139 ( V_256 ) ;
#ifndef F_140
V_259 = ( V_230 -> V_259 != NULL || V_230 -> V_283 != NULL ) ;
V_268 = ( V_230 -> V_283 != NULL ||
( V_259 && F_141 ( V_230 -> V_259 ) * 8 <= V_270 ) ) ;
#else
V_259 = V_268 = 0 ;
#endif
#ifndef F_142
V_261 = ( V_230 -> V_261 != NULL || V_230 -> V_284 != NULL ) ;
V_269 = ( V_230 -> V_284 != NULL ||
( V_261 && F_143 ( V_230 -> V_261 ) * 8 <= V_270 ) ) ;
#else
V_261 = V_269 = 0 ;
#endif
#ifndef F_138
V_279 = ( V_230 -> V_285 != NULL || V_230 -> V_286 != NULL ) ;
#endif
V_257 = & ( V_230 -> V_287 [ V_288 ] ) ;
V_258 = ( V_257 -> V_141 != NULL && V_257 -> V_144 != NULL ) ;
V_265 = ( V_258 && F_144 ( V_257 -> V_144 ) * 8 <= V_270 ) ;
V_257 = & ( V_230 -> V_287 [ V_289 ] ) ;
V_260 = ( V_257 -> V_141 != NULL && V_257 -> V_144 != NULL ) ;
V_257 = & ( V_230 -> V_287 [ V_290 ] ) ;
V_264 = ( V_257 -> V_141 != NULL && V_257 -> V_144 != NULL ) ;
V_257 = & ( V_230 -> V_287 [ V_291 ] ) ;
V_262 = ( V_257 -> V_141 != NULL && V_257 -> V_144 != NULL ) ;
V_266 = ( V_262 && F_144 ( V_257 -> V_144 ) * 8 <= V_270 ) ;
V_257 = & ( V_230 -> V_287 [ V_292 ] ) ;
V_263 = ( V_257 -> V_141 != NULL && V_257 -> V_144 != NULL ) ;
V_267 = ( V_263 && F_144 ( V_257 -> V_144 ) * 8 <= V_270 ) ;
V_257 = & ( V_230 -> V_287 [ V_293 ] ) ;
V_275 = ( V_257 -> V_141 != NULL && V_257 -> V_144 != NULL ) ;
V_271 = 0 ;
V_272 = 0 ;
V_273 = 0 ;
V_274 = 0 ;
#ifdef F_145
printf ( L_6 ,
V_259 , V_268 , V_261 , V_279 ,
V_258 , V_265 , V_260 , V_264 , V_262 , V_263 ) ;
#endif
V_257 = & ( V_230 -> V_287 [ V_294 ] ) ;
if ( V_257 -> V_141 != NULL && V_257 -> V_144 != NULL ) {
V_271 |= V_295 ;
V_272 |= V_296 ;
}
V_257 = & ( V_230 -> V_287 [ V_297 ] ) ;
if ( V_257 -> V_141 != NULL && V_257 -> V_144 != NULL ) {
V_271 |= V_295 ;
V_272 |= V_298 ;
}
if ( V_258 || ( V_259 && V_260 ) )
V_271 |= V_299 ;
if ( V_265 || ( V_268 && ( V_260 || V_258 ) ) )
V_273 |= V_299 ;
#if 0
if ( (dh_tmp || dh_rsa || dh_dsa) &&
(rsa_enc || rsa_sign || dsa_sign))
mask_k|=SSL_kEDH;
if ((dh_tmp_export || dh_rsa_export || dh_dsa_export) &&
(rsa_enc || rsa_sign || dsa_sign))
emask_k|=SSL_kEDH;
#endif
if ( V_269 )
V_273 |= V_300 ;
if ( V_261 )
V_271 |= V_300 ;
if ( V_262 ) V_271 |= V_301 ;
if ( V_266 ) V_273 |= V_301 ;
if ( V_263 ) V_271 |= V_302 ;
if ( V_267 ) V_273 |= V_302 ;
if ( V_258 || V_260 )
{
V_272 |= V_303 ;
V_274 |= V_303 ;
}
if ( V_264 )
{
V_272 |= V_304 ;
V_274 |= V_304 ;
}
V_272 |= V_305 ;
V_274 |= V_305 ;
#ifndef F_14
V_271 |= V_306 ;
V_272 |= V_307 ;
V_273 |= V_306 ;
V_274 |= V_307 ;
#endif
if ( V_275 )
{
V_280 = ( V_230 -> V_287 [ V_293 ] ) . V_141 ;
F_146 ( V_280 , - 1 , 0 ) ;
V_276 = ( V_280 -> V_308 & V_309 ) ?
( V_280 -> V_310 & V_311 ) : 1 ;
V_277 = ( V_280 -> V_308 & V_309 ) ?
( V_280 -> V_310 & V_312 ) : 1 ;
V_281 = F_147 ( V_280 ) ;
V_278 = ( V_281 != NULL ) ?
F_148 ( V_281 ) : 0 ;
F_149 ( V_281 ) ;
if ( ( V_280 -> V_313 ) && ( V_280 -> V_313 -> V_314 ) )
V_282 = F_150 ( V_280 -> V_313 -> V_314 ) ;
#ifndef F_138
if ( V_276 )
{
const char * V_315 = F_151 ( V_282 ) ;
if ( V_315 == NULL )
{
F_152 () ;
V_315 = L_7 ;
}
if ( strstr ( V_315 , L_8 ) )
{
V_271 |= V_316 ;
V_272 |= V_317 ;
if ( V_278 <= 163 )
{
V_273 |= V_316 ;
V_274 |= V_317 ;
}
}
if ( V_282 == V_318 )
{
V_271 |= V_319 ;
V_272 |= V_317 ;
if ( V_278 <= 163 )
{
V_273 |= V_319 ;
V_274 |= V_317 ;
}
}
}
#endif
#ifndef F_153
if ( V_277 )
{
V_272 |= V_320 ;
V_274 |= V_320 ;
}
#endif
}
#ifndef F_138
if ( V_279 )
{
V_271 |= V_321 ;
V_273 |= V_321 ;
}
#endif
#ifndef F_23
V_271 |= V_322 ;
V_272 |= V_323 ;
V_273 |= V_322 ;
V_274 |= V_323 ;
#endif
V_230 -> V_271 = V_271 ;
V_230 -> V_272 = V_272 ;
V_230 -> V_324 = V_273 ;
V_230 -> V_325 = V_274 ;
V_230 -> V_326 = 1 ;
}
int F_154 ( T_10 * V_280 , const V_31 * V_327 )
{
unsigned long V_328 , V_329 ;
T_16 * V_330 = NULL ;
int V_331 = 0 ;
int V_282 = 0 ;
V_328 = V_327 -> V_332 ;
V_329 = V_327 -> V_333 ;
if ( F_155 ( V_327 ) )
{
V_330 = F_147 ( V_280 ) ;
if ( V_330 == NULL ) return 0 ;
V_331 = F_148 ( V_330 ) ;
F_149 ( V_330 ) ;
if ( V_331 > 163 ) return 0 ;
}
F_146 ( V_280 , - 1 , 0 ) ;
if ( ( V_280 -> V_313 ) && ( V_280 -> V_313 -> V_314 ) )
V_282 = F_150 ( V_280 -> V_313 -> V_314 ) ;
if ( V_328 & V_319 || V_328 & V_316 )
{
if ( F_156 ( V_280 , V_311 ) )
{
F_2 ( V_334 , V_335 ) ;
return 0 ;
}
if ( V_328 & V_319 )
{
if ( V_282 != V_318 )
{
F_2 ( V_334 , V_336 ) ;
return 0 ;
}
}
if ( V_328 & V_316 )
{
const char * V_315 = F_151 ( V_282 ) ;
if ( V_315 == NULL )
{
F_152 () ;
V_315 = L_7 ;
}
if ( strstr ( V_315 , L_8 ) == NULL )
{
F_2 ( V_334 , V_337 ) ;
return 0 ;
}
}
}
if ( V_329 & V_320 )
{
if ( F_156 ( V_280 , V_312 ) )
{
F_2 ( V_334 , V_338 ) ;
return 0 ;
}
}
return 1 ;
}
T_10 * F_157 ( T_1 * V_1 )
{
unsigned long V_328 , V_329 , V_271 , V_272 ;
T_14 * V_230 ;
int V_101 , V_339 ;
V_230 = V_1 -> V_47 ;
F_137 ( V_230 , V_1 -> V_128 -> V_129 . V_340 ) ;
V_339 = F_155 ( V_1 -> V_128 -> V_129 . V_340 ) ;
if ( V_339 )
{
V_271 = V_230 -> V_324 ;
V_272 = V_230 -> V_325 ;
}
else
{
V_271 = V_230 -> V_271 ;
V_272 = V_230 -> V_272 ;
}
V_328 = V_1 -> V_128 -> V_129 . V_340 -> V_332 ;
V_329 = V_1 -> V_128 -> V_129 . V_340 -> V_333 ;
if ( V_328 & ( V_316 | V_319 ) )
{
V_101 = V_293 ;
}
else if ( V_329 & V_320 )
{
V_101 = V_293 ;
}
else if ( V_328 & V_301 )
V_101 = V_291 ;
else if ( V_328 & V_302 )
V_101 = V_292 ;
else if ( V_329 & V_304 )
V_101 = V_290 ;
else if ( V_329 & V_303 )
{
if ( V_230 -> V_287 [ V_288 ] . V_141 == NULL )
V_101 = V_289 ;
else
V_101 = V_288 ;
}
else if ( V_329 & V_307 )
{
return ( NULL ) ;
}
else if ( V_329 & V_298 )
V_101 = V_297 ;
else if ( V_329 & V_296 )
V_101 = V_294 ;
else
{
F_2 ( V_341 , V_9 ) ;
return ( NULL ) ;
}
if ( V_230 -> V_287 [ V_101 ] . V_141 == NULL ) return ( NULL ) ;
return ( V_230 -> V_287 [ V_101 ] . V_141 ) ;
}
T_16 * F_158 ( T_1 * V_1 , const V_31 * V_256 )
{
unsigned long V_329 ;
T_14 * V_230 ;
V_329 = V_256 -> V_333 ;
V_230 = V_1 -> V_47 ;
if ( ( V_329 & V_304 ) &&
( V_230 -> V_287 [ V_290 ] . V_144 != NULL ) )
return ( V_230 -> V_287 [ V_290 ] . V_144 ) ;
else if ( V_329 & V_303 )
{
if ( V_230 -> V_287 [ V_289 ] . V_144 != NULL )
return ( V_230 -> V_287 [ V_289 ] . V_144 ) ;
else if ( V_230 -> V_287 [ V_288 ] . V_144 != NULL )
return ( V_230 -> V_287 [ V_288 ] . V_144 ) ;
else
return ( NULL ) ;
}
else if ( ( V_329 & V_320 ) &&
( V_230 -> V_287 [ V_293 ] . V_144 != NULL ) )
return ( V_230 -> V_287 [ V_293 ] . V_144 ) ;
else
{
F_2 ( V_342 , V_9 ) ;
return ( NULL ) ;
}
}
void F_159 ( T_1 * V_1 , int V_45 )
{
int V_101 ;
if ( V_1 -> V_5 -> V_95 == 0 ) return;
V_101 = V_1 -> V_343 -> V_198 ;
if ( ( V_101 & V_45 ) && ( ! V_1 -> V_6 )
&& ( ( V_101 & V_344 )
|| F_160 ( V_1 -> V_343 , V_1 -> V_5 ) )
&& ( V_1 -> V_343 -> V_345 != NULL ) )
{
F_20 ( & V_1 -> V_5 -> V_60 , 1 , V_346 ) ;
if ( ! V_1 -> V_343 -> V_345 ( V_1 , V_1 -> V_5 ) )
F_4 ( V_1 -> V_5 ) ;
}
if ( ( ! ( V_101 & V_347 ) ) &&
( ( V_101 & V_45 ) == V_45 ) )
{
if ( ( ( ( V_45 & V_348 )
? V_1 -> V_343 -> V_202 . V_205
: V_1 -> V_343 -> V_202 . V_211 ) & 0xff ) == 0xff )
{
F_125 ( V_1 -> V_343 , ( unsigned long ) time ( NULL ) ) ;
}
}
}
const T_3 * F_161 ( T_1 * V_1 )
{
return ( V_1 -> V_2 ) ;
}
int F_162 ( T_1 * V_1 , const T_3 * V_30 )
{
int V_349 = - 1 ;
int V_115 = 1 ;
if ( V_1 -> V_2 != V_30 )
{
if ( V_1 -> V_148 != NULL )
V_349 = ( V_1 -> V_148 == V_1 -> V_2 -> V_149 ) ;
if ( V_1 -> V_2 -> V_15 == V_30 -> V_15 )
V_1 -> V_2 = V_30 ;
else
{
V_1 -> V_2 -> V_27 ( V_1 ) ;
V_1 -> V_2 = V_30 ;
V_115 = V_1 -> V_2 -> V_28 ( V_1 ) ;
}
if ( V_349 == 1 )
V_1 -> V_148 = V_30 -> V_149 ;
else if ( V_349 == 0 )
V_1 -> V_148 = V_30 -> V_74 ;
}
return ( V_115 ) ;
}
int F_163 ( const T_1 * V_1 , int V_101 )
{
int V_350 ;
unsigned long V_168 ;
T_7 * V_119 ;
if ( V_101 > 0 ) return ( V_351 ) ;
if ( ( V_168 = F_164 () ) != 0 )
{
if ( F_165 ( V_168 ) == V_352 )
return ( V_353 ) ;
else
return ( V_354 ) ;
}
if ( ( V_101 < 0 ) && F_166 ( V_1 ) )
{
V_119 = F_61 ( V_1 ) ;
if ( F_167 ( V_119 ) )
return ( V_355 ) ;
else if ( F_168 ( V_119 ) )
return ( V_356 ) ;
else if ( F_169 ( V_119 ) )
{
V_350 = F_170 ( V_119 ) ;
if ( V_350 == V_357 )
return ( V_358 ) ;
else if ( V_350 == V_359 )
return ( V_360 ) ;
else
return ( V_353 ) ;
}
}
if ( ( V_101 < 0 ) && F_171 ( V_1 ) )
{
V_119 = F_62 ( V_1 ) ;
if ( F_168 ( V_119 ) )
return ( V_356 ) ;
else if ( F_167 ( V_119 ) )
return ( V_355 ) ;
else if ( F_169 ( V_119 ) )
{
V_350 = F_170 ( V_119 ) ;
if ( V_350 == V_357 )
return ( V_358 ) ;
else if ( V_350 == V_359 )
return ( V_360 ) ;
else
return ( V_353 ) ;
}
}
if ( ( V_101 < 0 ) && F_172 ( V_1 ) )
{
return ( V_361 ) ;
}
if ( V_101 == 0 )
{
if ( V_1 -> V_15 == V_35 )
{
return ( V_362 ) ;
}
else
{
if ( ( V_1 -> V_7 & V_154 ) &&
( V_1 -> V_128 -> V_363 == V_364 ) )
return ( V_362 ) ;
}
}
return ( V_353 ) ;
}
int F_173 ( T_1 * V_1 )
{
int V_115 = 1 ;
if ( V_1 -> V_148 == NULL )
{
F_2 ( V_365 , V_366 ) ;
return ( - 1 ) ;
}
V_1 -> V_2 -> V_367 ( V_1 ) ;
if ( F_102 ( V_1 ) || F_174 ( V_1 ) )
{
V_115 = V_1 -> V_148 ( V_1 ) ;
}
return ( V_115 ) ;
}
void F_94 ( T_1 * V_1 )
{
V_1 -> V_12 = 1 ;
V_1 -> V_7 = 0 ;
V_1 -> V_10 = V_13 | V_11 ;
V_1 -> V_148 = V_1 -> V_2 -> V_74 ;
F_6 ( V_1 ) ;
F_7 ( & V_1 -> V_22 ) ;
F_7 ( & V_1 -> V_23 ) ;
}
void F_96 ( T_1 * V_1 )
{
V_1 -> V_12 = 0 ;
V_1 -> V_7 = 0 ;
V_1 -> V_10 = V_14 | V_11 ;
V_1 -> V_148 = V_1 -> V_2 -> V_149 ;
F_6 ( V_1 ) ;
F_7 ( & V_1 -> V_22 ) ;
F_7 ( & V_1 -> V_23 ) ;
}
int V_75 ( T_1 * V_1 )
{
F_2 ( V_368 , V_369 ) ;
return ( 0 ) ;
}
int F_175 ( void )
{
F_2 ( V_370 , V_369 ) ;
return ( 0 ) ;
}
int F_176 ( const T_1 * V_1 )
{
F_2 ( V_371 , V_369 ) ;
return ( 0 ) ;
}
T_3 * F_177 ( int V_372 )
{
F_2 ( V_373 , V_369 ) ;
return ( NULL ) ;
}
const char * F_178 ( const T_1 * V_1 )
{
if ( V_1 -> V_15 == V_374 )
return ( L_9 ) ;
else if ( V_1 -> V_15 == V_375 )
return ( L_10 ) ;
else if ( V_1 -> V_15 == V_35 )
return ( L_1 ) ;
else
return ( L_7 ) ;
}
T_1 * F_179 ( T_1 * V_1 )
{
F_9 ( V_376 ) * V_32 ;
V_376 * V_377 ;
T_1 * V_115 ;
int V_101 ;
if ( ( V_115 = F_12 ( F_180 ( V_1 ) ) ) == NULL )
return ( NULL ) ;
V_115 -> V_15 = V_1 -> V_15 ;
V_115 -> type = V_1 -> type ;
V_115 -> V_2 = V_1 -> V_2 ;
if ( V_1 -> V_5 != NULL )
{
F_181 ( V_115 , V_1 ) ;
}
else
{
V_115 -> V_2 -> V_27 ( V_115 ) ;
V_115 -> V_2 = V_1 -> V_2 ;
V_115 -> V_2 -> V_28 ( V_115 ) ;
if ( V_1 -> V_47 != NULL )
{
if ( V_115 -> V_47 != NULL )
{
F_24 ( V_115 -> V_47 ) ;
}
V_115 -> V_47 = F_16 ( V_1 -> V_47 ) ;
if ( V_115 -> V_47 == NULL )
goto V_42;
}
F_28 ( V_115 ,
V_1 -> V_53 , V_1 -> V_52 ) ;
}
V_115 -> V_44 = V_1 -> V_44 ;
V_115 -> V_45 = V_1 -> V_45 ;
F_182 ( V_115 , F_183 ( V_1 ) ) ;
F_86 ( V_115 , F_87 ( V_1 ) ) ;
V_115 -> V_49 = V_1 -> V_49 ;
V_115 -> V_50 = V_1 -> V_50 ;
F_82 ( V_115 , F_77 ( V_1 ) ,
F_184 ( V_1 ) ) ;
F_84 ( V_115 , F_78 ( V_1 ) ) ;
V_115 -> V_56 = V_1 -> V_56 ;
F_185 ( V_115 , F_186 ( V_1 ) ) ;
V_115 -> V_378 = V_1 -> V_378 ;
if ( ! F_187 ( V_76 , & V_115 -> V_77 , & V_1 -> V_77 ) )
goto V_42;
if ( V_1 -> V_105 != NULL )
{
if ( ! F_188 ( V_1 -> V_105 , ( char * ) & V_115 -> V_105 ) )
goto V_42;
}
if ( V_1 -> V_104 != NULL )
{
if ( V_1 -> V_104 != V_1 -> V_105 )
{
if ( ! F_188 ( V_1 -> V_104 , ( char * ) & V_115 -> V_104 ) )
goto V_42;
}
else
V_115 -> V_104 = V_115 -> V_105 ;
}
V_115 -> V_17 = V_1 -> V_17 ;
V_115 -> V_25 = V_1 -> V_25 ;
V_115 -> V_148 = V_1 -> V_148 ;
V_115 -> V_12 = V_1 -> V_12 ;
V_115 -> V_8 = V_1 -> V_8 ;
V_115 -> V_58 = V_1 -> V_58 ;
V_115 -> V_7 = V_1 -> V_7 ;
V_115 -> V_10 = V_1 -> V_10 ;
V_115 -> V_19 = V_1 -> V_19 ;
V_115 -> V_379 = 0 ;
V_115 -> V_6 = V_1 -> V_6 ;
F_19 ( V_115 -> V_57 , V_1 -> V_57 ) ;
if ( V_1 -> V_33 != NULL )
{
if ( ( V_115 -> V_33 = F_189 ( V_1 -> V_33 ) ) == NULL )
goto V_42;
}
if ( V_1 -> V_34 != NULL )
if ( ( V_115 -> V_34 = F_189 ( V_1 -> V_34 ) )
== NULL )
goto V_42;
if ( V_1 -> V_112 != NULL )
{
if ( ( V_32 = F_190 ( V_1 -> V_112 ) ) == NULL ) goto V_42;
V_115 -> V_112 = V_32 ;
for ( V_101 = 0 ; V_101 < F_191 ( V_32 ) ; V_101 ++ )
{
V_377 = F_192 ( V_32 , V_101 ) ;
if ( F_193 ( V_32 , V_101 , F_194 ( V_377 ) ) == NULL )
{
V_113 ( V_377 ) ;
goto V_42;
}
}
}
if ( 0 )
{
V_42:
if ( V_115 != NULL ) F_46 ( V_115 ) ;
V_115 = NULL ;
}
return ( V_115 ) ;
}
void F_6 ( T_1 * V_1 )
{
if ( V_1 -> V_380 != NULL )
{
F_195 ( V_1 -> V_380 ) ;
F_26 ( V_1 -> V_380 ) ;
V_1 -> V_380 = NULL ;
}
if ( V_1 -> V_381 != NULL )
{
F_195 ( V_1 -> V_381 ) ;
F_26 ( V_1 -> V_381 ) ;
V_1 -> V_381 = NULL ;
}
#ifndef F_196
if ( V_1 -> V_382 != NULL )
{
F_197 ( V_1 -> V_382 ) ;
V_1 -> V_382 = NULL ;
}
if ( V_1 -> V_383 != NULL )
{
F_197 ( V_1 -> V_383 ) ;
V_1 -> V_383 = NULL ;
}
#endif
}
T_10 * F_198 ( const T_1 * V_1 )
{
if ( V_1 -> V_47 != NULL )
return ( V_1 -> V_47 -> V_140 -> V_141 ) ;
else
return ( NULL ) ;
}
T_16 * F_199 ( T_1 * V_1 )
{
if ( V_1 -> V_47 != NULL )
return ( V_1 -> V_47 -> V_140 -> V_144 ) ;
else
return ( NULL ) ;
}
const V_31 * F_200 ( const T_1 * V_1 )
{
if ( ( V_1 -> V_5 != NULL ) && ( V_1 -> V_5 -> V_256 != NULL ) )
return ( V_1 -> V_5 -> V_256 ) ;
return ( NULL ) ;
}
const void * F_201 ( T_1 * V_1 )
{
return NULL ;
}
const void * F_202 ( T_1 * V_1 )
{
return NULL ;
}
const T_17 * F_201 ( T_1 * V_1 )
{
if ( V_1 -> V_383 != NULL )
return ( V_1 -> V_383 -> V_30 ) ;
return ( NULL ) ;
}
const T_17 * F_202 ( T_1 * V_1 )
{
if ( V_1 -> V_382 != NULL )
return ( V_1 -> V_382 -> V_30 ) ;
return ( NULL ) ;
}
int F_203 ( T_1 * V_1 , int V_384 )
{
T_7 * V_103 ;
if ( V_1 -> V_103 == NULL )
{
V_103 = F_69 ( F_204 () ) ;
if ( V_103 == NULL ) return ( 0 ) ;
V_1 -> V_103 = V_103 ;
}
else
{
V_103 = V_1 -> V_103 ;
if ( V_1 -> V_103 == V_1 -> V_104 )
V_1 -> V_104 = F_51 ( V_1 -> V_104 ) ;
}
( void ) F_205 ( V_103 ) ;
if ( ! F_206 ( V_103 , 1 ) )
{
F_2 ( V_385 , V_121 ) ;
return ( 0 ) ;
}
if ( V_384 )
{
if ( V_1 -> V_104 != V_103 )
V_1 -> V_104 = F_207 ( V_103 , V_1 -> V_104 ) ;
}
else
{
if ( V_1 -> V_104 == V_103 )
V_1 -> V_104 = F_51 ( V_103 ) ;
}
return ( 1 ) ;
}
void F_208 ( T_1 * V_1 )
{
if ( V_1 -> V_103 == NULL ) return;
if ( V_1 -> V_103 == V_1 -> V_104 )
{
V_1 -> V_104 = F_51 ( V_1 -> V_104 ) ;
#ifdef F_48
assert ( V_1 -> V_104 != NULL ) ;
#endif
}
F_52 ( V_1 -> V_103 ) ;
V_1 -> V_103 = NULL ;
}
void F_209 ( T_2 * V_26 , int V_45 )
{
V_26 -> V_58 = V_45 ;
}
int F_210 ( const T_2 * V_26 )
{
return ( V_26 -> V_58 ) ;
}
void F_211 ( T_1 * V_1 , int V_45 )
{
V_1 -> V_58 = V_45 ;
}
int F_212 ( const T_1 * V_1 )
{
return ( V_1 -> V_58 ) ;
}
void F_213 ( T_1 * V_1 , int V_45 )
{
V_1 -> V_7 = V_45 ;
}
int F_214 ( const T_1 * V_1 )
{
return ( V_1 -> V_7 ) ;
}
int F_106 ( const T_1 * V_1 )
{
return ( V_1 -> V_15 ) ;
}
T_2 * F_180 ( const T_1 * V_84 )
{
return ( V_84 -> V_26 ) ;
}
T_2 * F_215 ( T_1 * V_84 , T_2 * V_26 )
{
if ( V_84 -> V_26 == V_26 )
return V_84 -> V_26 ;
#ifndef F_21
if ( V_26 == NULL )
V_26 = V_84 -> V_71 ;
#endif
if ( V_84 -> V_47 != NULL )
F_24 ( V_84 -> V_47 ) ;
V_84 -> V_47 = F_16 ( V_26 -> V_47 ) ;
F_20 ( & V_26 -> V_60 , 1 , V_61 ) ;
if ( V_84 -> V_26 != NULL )
F_25 ( V_84 -> V_26 ) ;
V_84 -> V_26 = V_26 ;
return ( V_84 -> V_26 ) ;
}
int F_216 ( T_2 * V_26 )
{
return ( F_217 ( V_26 -> V_243 ) ) ;
}
int F_218 ( T_2 * V_26 , const char * V_386 ,
const char * V_387 )
{
return ( F_219 ( V_26 -> V_243 , V_386 , V_387 ) ) ;
}
void F_185 ( T_1 * V_84 ,
void (* V_87)( const T_1 * V_84 , int type , int V_388 ) )
{
V_84 -> V_389 = V_87 ;
}
int F_220 ( const T_1 * V_84 )
{
return ( V_84 -> V_10 ) ;
}
void F_221 ( T_1 * V_84 , long V_192 )
{
V_84 -> V_72 = V_192 ;
}
long F_222 ( const T_1 * V_84 )
{
return ( V_84 -> V_72 ) ;
}
int F_223 ( long V_390 , void * V_391 , T_18 * V_392 ,
T_19 * V_393 , T_20 * V_394 )
{
return F_224 ( V_76 , V_390 , V_391 ,
V_392 , V_393 , V_394 ) ;
}
int F_225 ( T_1 * V_1 , int V_395 , void * V_192 )
{
return ( F_226 ( & V_1 -> V_77 , V_395 , V_192 ) ) ;
}
void * F_227 ( const T_1 * V_1 , int V_395 )
{
return ( F_228 ( & V_1 -> V_77 , V_395 ) ) ;
}
int F_229 ( long V_390 , void * V_391 , T_18 * V_392 ,
T_19 * V_393 , T_20 * V_394 )
{
return F_224 ( V_242 , V_390 , V_391 ,
V_392 , V_393 , V_394 ) ;
}
int F_230 ( T_2 * V_1 , int V_395 , void * V_192 )
{
return ( F_226 ( & V_1 -> V_77 , V_395 , V_192 ) ) ;
}
void * F_231 ( const T_2 * V_1 , int V_395 )
{
return ( F_228 ( & V_1 -> V_77 , V_395 ) ) ;
}
int F_232 ( T_1 * V_1 )
{
return ( 1 ) ;
}
T_21 * F_233 ( const T_2 * V_26 )
{
return ( V_26 -> V_243 ) ;
}
void F_234 ( T_2 * V_26 , T_21 * V_396 )
{
if ( V_26 -> V_243 != NULL )
F_127 ( V_26 -> V_243 ) ;
V_26 -> V_243 = V_396 ;
}
int F_235 ( const T_1 * V_1 )
{
return ( V_1 -> V_17 ) ;
}
void F_236 ( T_2 * V_26 , T_22 * (* V_87)( T_1 * V_84 ,
int V_339 ,
int V_397 ) )
{
F_111 ( V_26 , V_398 , ( void ( * ) ( void ) ) V_87 ) ;
}
void F_237 ( T_1 * V_84 , T_22 * (* V_87)( T_1 * V_84 ,
int V_339 ,
int V_397 ) )
{
F_107 ( V_84 , V_398 , ( void ( * ) ( void ) ) V_87 ) ;
}
T_22 * V_87 ( T_1 * V_84 , int V_339 , int V_397 )
{}
void F_238 ( T_2 * V_26 , T_23 * (* F_239)( T_1 * V_84 , int V_339 ,
int V_397 ) )
{
F_111 ( V_26 , V_399 , ( void ( * ) ( void ) ) F_239 ) ;
}
void F_240 ( T_1 * V_84 , T_23 * (* F_239)( T_1 * V_84 , int V_339 ,
int V_397 ) )
{
F_107 ( V_84 , V_399 , ( void ( * ) ( void ) ) F_239 ) ;
}
void F_241 ( T_2 * V_26 , T_24 * (* F_242)( T_1 * V_84 , int V_339 ,
int V_397 ) )
{
F_111 ( V_26 , V_400 , ( void ( * ) ( void ) ) F_242 ) ;
}
void F_243 ( T_1 * V_84 , T_24 * (* F_242)( T_1 * V_84 , int V_339 ,
int V_397 ) )
{
F_107 ( V_84 , V_400 , ( void ( * ) ( void ) ) F_242 ) ;
}
int F_244 ( T_2 * V_26 , const char * V_401 )
{
if ( V_401 != NULL && strlen ( V_401 ) > V_402 )
{
F_2 ( V_403 , V_404 ) ;
return 0 ;
}
if ( V_26 -> V_247 != NULL )
F_26 ( V_26 -> V_247 ) ;
if ( V_401 != NULL )
{
V_26 -> V_247 = F_245 ( V_401 ) ;
if ( V_26 -> V_247 == NULL )
return 0 ;
}
else
V_26 -> V_247 = NULL ;
return 1 ;
}
int F_246 ( T_1 * V_1 , const char * V_401 )
{
if ( V_1 == NULL )
return 0 ;
if ( V_1 -> V_5 == NULL )
return 1 ;
if ( V_401 != NULL && strlen ( V_401 ) > V_402 )
{
F_2 ( V_405 , V_404 ) ;
return 0 ;
}
if ( V_1 -> V_5 -> V_247 != NULL )
F_26 ( V_1 -> V_5 -> V_247 ) ;
if ( V_401 != NULL )
{
V_1 -> V_5 -> V_247 = F_245 ( V_401 ) ;
if ( V_1 -> V_5 -> V_247 == NULL )
return 0 ;
}
else
V_1 -> V_5 -> V_247 = NULL ;
return 1 ;
}
const char * F_247 ( const T_1 * V_1 )
{
if ( V_1 == NULL || V_1 -> V_5 == NULL )
return NULL ;
return ( V_1 -> V_5 -> V_247 ) ;
}
const char * F_248 ( const T_1 * V_1 )
{
if ( V_1 == NULL || V_1 -> V_5 == NULL )
return NULL ;
return ( V_1 -> V_5 -> V_406 ) ;
}
void F_249 ( T_2 * V_26 , void (* V_87)( int V_189 , int V_15 , int V_190 , const void * V_126 , T_8 V_191 , T_1 * V_84 , void * V_192 ) )
{
F_111 ( V_26 , V_188 , ( void ( * ) ( void ) ) V_87 ) ;
}
void F_250 ( T_1 * V_84 , void (* V_87)( int V_189 , int V_15 , int V_190 , const void * V_126 , T_8 V_191 , T_1 * V_84 , void * V_192 ) )
{
F_107 ( V_84 , V_188 , ( void ( * ) ( void ) ) V_87 ) ;
}
T_25 * F_251 ( T_25 * * V_407 , const T_26 * V_408 )
{
F_7 ( V_407 ) ;
* V_407 = F_252 () ;
if ( V_408 ) F_253 ( * V_407 , V_408 , NULL ) ;
return * V_407 ;
}
void F_7 ( T_25 * * V_407 )
{
if ( * V_407 ) F_254 ( * V_407 ) ;
* V_407 = NULL ;
}
