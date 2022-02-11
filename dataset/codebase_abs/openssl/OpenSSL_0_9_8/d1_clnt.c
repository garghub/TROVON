static T_1 * F_1 ( int V_1 )
{
if ( V_1 == V_2 )
return ( F_2 () ) ;
else
return ( NULL ) ;
}
T_1 * F_2 ( void )
{
static int V_3 = 1 ;
static T_1 V_4 ;
if ( V_3 )
{
F_3 ( V_5 ) ;
if ( V_3 )
{
memcpy ( ( char * ) & V_4 , ( char * ) F_4 () ,
sizeof( T_1 ) ) ;
V_4 . V_6 = V_7 ;
V_4 . V_8 = F_1 ;
V_3 = 0 ;
}
F_5 ( V_5 ) ;
}
return ( & V_4 ) ;
}
int V_7 ( T_2 * V_9 )
{
T_3 * V_10 = NULL ;
unsigned long Time = time ( NULL ) , V_11 ;
long V_12 ;
void (* F_6)( const T_2 * V_13 , int type , int V_14 ) = NULL ;
int V_15 = - 1 ;
int V_16 , V_17 , V_18 = 0 ; ;
F_7 ( & Time , sizeof( Time ) , 0 ) ;
F_8 () ;
F_9 () ;
if ( V_9 -> V_19 != NULL )
F_6 = V_9 -> V_19 ;
else if ( V_9 -> V_20 -> V_19 != NULL )
F_6 = V_9 -> V_20 -> V_19 ;
V_9 -> V_21 ++ ;
if ( ! F_10 ( V_9 ) || F_11 ( V_9 ) ) F_12 ( V_9 ) ;
for (; ; )
{
V_17 = V_9 -> V_17 ;
switch( V_9 -> V_17 )
{
case V_22 :
V_9 -> V_23 = 1 ;
V_9 -> V_17 = V_24 ;
V_9 -> V_20 -> V_25 . V_26 ++ ;
case V_27 :
case V_24 :
case V_27 | V_24 :
case V_28 | V_24 :
V_9 -> V_29 = 0 ;
if ( F_6 != NULL ) F_6 ( V_9 , V_30 , 1 ) ;
if ( ( V_9 -> V_31 & 0xff00 ) != ( V_2 & 0xff00 ) )
{
F_13 ( V_32 , V_33 ) ;
V_15 = - 1 ;
goto V_34;
}
V_9 -> type = V_24 ;
if ( V_9 -> V_35 == NULL )
{
if ( ( V_10 = F_14 () ) == NULL )
{
V_15 = - 1 ;
goto V_34;
}
if ( ! F_15 ( V_10 , V_36 ) )
{
V_15 = - 1 ;
goto V_34;
}
V_9 -> V_35 = V_10 ;
V_10 = NULL ;
}
if ( ! F_16 ( V_9 ) ) { V_15 = - 1 ; goto V_34; }
if ( ! F_17 ( V_9 , 0 ) ) { V_15 = - 1 ; goto V_34; }
F_18 ( V_9 ) ;
V_9 -> V_17 = V_37 ;
V_9 -> V_20 -> V_25 . V_38 ++ ;
V_9 -> V_39 = 0 ;
break;
case V_37 :
case V_40 :
V_9 -> V_41 = 0 ;
V_15 = F_19 ( V_9 ) ;
if ( V_15 <= 0 ) goto V_34;
if ( V_9 -> V_42 -> V_43 )
{
V_9 -> V_17 = V_44 ;
V_9 -> V_45 -> V_46 . V_47 = V_48 ;
}
else
V_9 -> V_17 = V_48 ;
V_9 -> V_39 = 0 ;
if ( V_9 -> V_49 != V_9 -> V_50 )
V_9 -> V_50 = F_20 ( V_9 -> V_49 , V_9 -> V_50 ) ;
break;
case V_48 :
case V_51 :
V_15 = F_21 ( V_9 ) ;
if ( V_15 <= 0 ) goto V_34;
else
{
if ( V_9 -> V_52 )
V_9 -> V_17 = V_53 ;
else
V_9 -> V_17 = V_54 ;
}
V_9 -> V_39 = 0 ;
break;
case V_54 :
case V_55 :
V_15 = F_22 ( V_9 ) ;
if ( V_15 <= 0 )
goto V_34;
if ( V_9 -> V_42 -> V_43 )
V_9 -> V_17 = V_37 ;
else
V_9 -> V_17 = V_56 ;
V_9 -> V_39 = 0 ;
break;
case V_56 :
case V_57 :
if ( ! ( V_9 -> V_45 -> V_46 . V_58 -> V_59 & V_60 ) )
{
V_15 = F_23 ( V_9 ) ;
if ( V_15 <= 0 ) goto V_34;
}
else
V_18 = 1 ;
V_9 -> V_17 = V_61 ;
V_9 -> V_39 = 0 ;
break;
case V_61 :
case V_62 :
V_15 = F_24 ( V_9 ) ;
if ( V_15 <= 0 ) goto V_34;
V_9 -> V_17 = V_63 ;
V_9 -> V_39 = 0 ;
if ( ! F_25 ( V_9 ) )
{
V_15 = - 1 ;
goto V_34;
}
break;
case V_63 :
case V_64 :
V_15 = F_26 ( V_9 ) ;
if ( V_15 <= 0 ) goto V_34;
V_9 -> V_17 = V_65 ;
V_9 -> V_39 = 0 ;
break;
case V_65 :
case V_66 :
V_15 = F_27 ( V_9 ) ;
if ( V_15 <= 0 ) goto V_34;
if ( V_9 -> V_45 -> V_46 . V_67 )
V_9 -> V_17 = V_68 ;
else
V_9 -> V_17 = V_69 ;
V_9 -> V_39 = 0 ;
break;
case V_68 :
case V_70 :
case V_71 :
case V_72 :
V_15 = F_28 ( V_9 ) ;
if ( V_15 <= 0 ) goto V_34;
V_9 -> V_17 = V_69 ;
V_9 -> V_39 = 0 ;
break;
case V_69 :
case V_73 :
V_15 = F_29 ( V_9 ) ;
if ( V_15 <= 0 ) goto V_34;
V_11 = V_9 -> V_45 -> V_46 . V_58 -> V_59 ;
if ( V_9 -> V_45 -> V_46 . V_67 == 1 )
{
V_9 -> V_17 = V_74 ;
}
else
{
V_9 -> V_17 = V_75 ;
V_9 -> V_45 -> V_76 = 0 ;
}
V_9 -> V_39 = 0 ;
break;
case V_74 :
case V_77 :
V_15 = F_30 ( V_9 ) ;
if ( V_15 <= 0 ) goto V_34;
V_9 -> V_17 = V_75 ;
V_9 -> V_39 = 0 ;
V_9 -> V_45 -> V_76 = 0 ;
break;
case V_75 :
case V_78 :
V_15 = F_31 ( V_9 ,
V_75 , V_78 ) ;
if ( V_15 <= 0 ) goto V_34;
V_9 -> V_17 = V_79 ;
V_9 -> V_39 = 0 ;
V_9 -> V_80 -> V_81 = V_9 -> V_45 -> V_46 . V_58 ;
if ( V_9 -> V_45 -> V_46 . V_82 == NULL )
V_9 -> V_80 -> V_83 = 0 ;
else
V_9 -> V_80 -> V_83 =
V_9 -> V_45 -> V_46 . V_82 -> V_84 ;
if ( ! V_9 -> V_85 -> V_86 -> V_87 ( V_9 ) )
{
V_15 = - 1 ;
goto V_34;
}
if ( ! V_9 -> V_85 -> V_86 -> V_88 ( V_9 ,
V_89 ) )
{
V_15 = - 1 ;
goto V_34;
}
F_32 ( V_9 , V_90 ) ;
break;
case V_79 :
case V_91 :
V_15 = F_33 ( V_9 ,
V_79 , V_91 ,
V_9 -> V_85 -> V_86 -> V_92 ,
V_9 -> V_85 -> V_86 -> V_93 ) ;
if ( V_15 <= 0 ) goto V_34;
V_9 -> V_17 = V_44 ;
V_9 -> V_45 -> V_94 &= ~ V_95 ;
if ( V_9 -> V_52 )
{
V_9 -> V_45 -> V_46 . V_47 = V_28 ;
if ( V_9 -> V_45 -> V_94 & V_96 )
{
V_9 -> V_17 = V_28 ;
V_9 -> V_45 -> V_94 |= V_95 ;
V_9 -> V_45 -> V_97 = 0 ;
}
}
else
{
V_9 -> V_45 -> V_46 . V_47 = V_53 ;
}
V_9 -> V_39 = 0 ;
break;
case V_53 :
case V_98 :
V_15 = F_34 ( V_9 , V_53 ,
V_98 ) ;
if ( V_15 <= 0 ) goto V_34;
if ( V_9 -> V_52 )
V_9 -> V_17 = V_75 ;
else
V_9 -> V_17 = V_28 ;
V_9 -> V_39 = 0 ;
break;
case V_44 :
V_12 = F_35 ( V_9 -> V_50 , V_99 , 0 , NULL ) ;
if ( V_12 > 0 )
{
V_9 -> V_100 = V_101 ;
V_12 = F_36 ( V_9 -> V_50 ) ;
if ( V_12 <= 0 ) { V_15 = - 1 ; goto V_34; }
V_9 -> V_100 = V_102 ;
}
V_9 -> V_17 = V_9 -> V_45 -> V_46 . V_47 ;
break;
case V_28 :
F_37 ( V_9 ) ;
#if 0
if (s->init_buf != NULL)
{
BUF_MEM_free(s->init_buf);
s->init_buf=NULL;
}
#endif
if ( ! ( V_9 -> V_45 -> V_94 & V_95 ) )
F_38 ( V_9 ) ;
V_9 -> V_39 = 0 ;
V_9 -> V_23 = 0 ;
F_39 ( V_9 , V_103 ) ;
if ( V_9 -> V_52 ) V_9 -> V_20 -> V_25 . V_104 ++ ;
V_15 = 1 ;
V_9 -> V_105 = V_7 ;
V_9 -> V_20 -> V_25 . V_106 ++ ;
if ( F_6 != NULL ) F_6 ( V_9 , V_107 , 1 ) ;
V_9 -> V_42 -> V_108 = 0 ;
goto V_34;
default:
F_13 ( V_32 , V_109 ) ;
V_15 = - 1 ;
goto V_34;
}
if ( ! V_9 -> V_45 -> V_46 . V_110 && ! V_18 )
{
if ( V_9 -> V_111 )
{
if ( ( V_15 = F_36 ( V_9 -> V_50 ) ) <= 0 )
goto V_34;
}
if ( ( F_6 != NULL ) && ( V_9 -> V_17 != V_17 ) )
{
V_16 = V_9 -> V_17 ;
V_9 -> V_17 = V_17 ;
F_6 ( V_9 , V_112 , 1 ) ;
V_9 -> V_17 = V_16 ;
}
}
V_18 = 0 ;
}
V_34:
V_9 -> V_21 -- ;
if ( V_10 != NULL )
F_40 ( V_10 ) ;
if ( F_6 != NULL )
F_6 ( V_9 , V_113 , V_15 ) ;
return ( V_15 ) ;
}
int F_19 ( T_2 * V_9 )
{
unsigned char * V_10 ;
unsigned char * V_114 , * V_115 ;
int V_116 , V_117 ;
unsigned long Time , V_11 ;
T_4 * V_118 ;
V_10 = ( unsigned char * ) V_9 -> V_35 -> V_119 ;
if ( V_9 -> V_17 == V_37 )
{
if ( ( V_9 -> V_80 == NULL ) ||
( V_9 -> V_80 -> V_120 != V_9 -> V_31 ) ||
( V_9 -> V_80 -> V_121 ) )
{
if ( ! F_41 ( V_9 , 0 ) )
goto V_122;
}
V_114 = V_9 -> V_45 -> V_123 ;
Time = time ( NULL ) ;
F_42 ( Time , V_114 ) ;
F_43 ( V_114 , V_124 - sizeof( Time ) ) ;
V_115 = V_114 = & ( V_10 [ V_125 ] ) ;
* ( V_114 ++ ) = V_9 -> V_31 >> 8 ;
* ( V_114 ++ ) = V_9 -> V_31 & 0xff ;
V_9 -> V_126 = V_9 -> V_31 ;
memcpy ( V_114 , V_9 -> V_45 -> V_123 , V_124 ) ;
V_114 += V_124 ;
if ( V_9 -> V_23 )
V_116 = 0 ;
else
V_116 = V_9 -> V_80 -> V_127 ;
* ( V_114 ++ ) = V_116 ;
if ( V_116 != 0 )
{
if ( V_116 > sizeof V_9 -> V_80 -> V_128 )
{
F_13 ( V_129 , V_33 ) ;
goto V_122;
}
memcpy ( V_114 , V_9 -> V_80 -> V_128 , V_116 ) ;
V_114 += V_116 ;
}
if ( V_9 -> V_42 -> V_130 > sizeof( V_9 -> V_42 -> V_131 ) )
{
F_13 ( V_129 , V_33 ) ;
goto V_122;
}
* ( V_114 ++ ) = V_9 -> V_42 -> V_130 ;
memcpy ( V_114 , V_9 -> V_42 -> V_131 , V_9 -> V_42 -> V_130 ) ;
V_114 += V_9 -> V_42 -> V_130 ;
V_116 = F_44 ( V_9 , F_45 ( V_9 ) , & ( V_114 [ 2 ] ) , 0 ) ;
if ( V_116 == 0 )
{
F_13 ( V_129 , V_132 ) ;
goto V_122;
}
F_46 ( V_116 , V_114 ) ;
V_114 += V_116 ;
if ( V_9 -> V_20 -> V_133 == NULL )
V_117 = 0 ;
else
V_117 = F_47 ( V_9 -> V_20 -> V_133 ) ;
* ( V_114 ++ ) = 1 + V_117 ;
for ( V_116 = 0 ; V_116 < V_117 ; V_116 ++ )
{
V_118 = F_48 ( V_9 -> V_20 -> V_133 , V_116 ) ;
* ( V_114 ++ ) = V_118 -> V_84 ;
}
* ( V_114 ++ ) = 0 ;
V_11 = ( V_114 - V_115 ) ;
V_115 = V_10 ;
V_115 = F_49 ( V_9 , V_115 , V_134 , V_11 , 0 , V_11 ) ;
V_9 -> V_17 = V_40 ;
V_9 -> V_39 = V_114 - V_10 ;
V_9 -> V_135 = 0 ;
F_50 ( V_9 , 0 ) ;
}
return ( F_51 ( V_9 , V_136 ) ) ;
V_122:
return ( - 1 ) ;
}
static int F_22 ( T_2 * V_9 )
{
int V_137 , V_138 , V_139 = 0 ;
unsigned char * V_119 ;
unsigned int V_130 ;
V_137 = V_9 -> V_85 -> V_140 ( V_9 ,
V_54 ,
V_55 ,
- 1 ,
V_9 -> V_141 ,
& V_139 ) ;
if ( ! V_139 ) return ( ( int ) V_137 ) ;
if ( V_9 -> V_45 -> V_46 . V_142 != V_143 )
{
V_9 -> V_42 -> V_43 = 0 ;
V_9 -> V_45 -> V_46 . V_110 = 1 ;
return ( 1 ) ;
}
V_119 = ( unsigned char * ) V_9 -> V_144 ;
if ( ( V_119 [ 0 ] != ( V_9 -> V_31 >> 8 ) ) || ( V_119 [ 1 ] != ( V_9 -> V_31 & 0xff ) ) )
{
F_13 ( V_145 , V_146 ) ;
V_9 -> V_31 = ( V_9 -> V_31 & 0xff00 ) | V_119 [ 1 ] ;
V_138 = V_147 ;
goto V_148;
}
V_119 += 2 ;
V_130 = * ( V_119 ++ ) ;
if ( V_130 > sizeof( V_9 -> V_42 -> V_131 ) )
{
V_138 = V_149 ;
goto V_148;
}
memcpy ( V_9 -> V_42 -> V_131 , V_119 , V_130 ) ;
V_9 -> V_42 -> V_130 = V_130 ;
V_9 -> V_42 -> V_43 = 1 ;
return 1 ;
V_148:
F_52 ( V_9 , V_150 , V_138 ) ;
return - 1 ;
}
int F_29 ( T_2 * V_9 )
{
unsigned char * V_114 , * V_115 ;
int V_137 ;
unsigned long V_11 ;
#ifndef F_53
unsigned char * V_151 ;
T_5 * V_152 = NULL ;
#endif
#ifndef F_54
T_6 V_153 ;
#endif
if ( V_9 -> V_17 == V_69 )
{
V_115 = ( unsigned char * ) V_9 -> V_35 -> V_119 ;
V_114 = & ( V_115 [ V_125 ] ) ;
V_11 = V_9 -> V_45 -> V_46 . V_58 -> V_59 ;
if ( 0 ) {}
#ifndef F_53
else if ( V_11 & V_154 )
{
T_7 * V_155 ;
unsigned char V_156 [ V_157 ] ;
if ( V_9 -> V_80 -> V_158 -> V_159 != NULL )
V_155 = V_9 -> V_80 -> V_158 -> V_159 ;
else
{
V_152 = F_55 ( V_9 -> V_80 -> V_158 -> V_160 [ V_161 ] . V_162 ) ;
if ( ( V_152 == NULL ) ||
( V_152 -> type != V_163 ) ||
( V_152 -> V_152 . V_155 == NULL ) )
{
F_13 ( V_164 , V_33 ) ;
goto V_122;
}
V_155 = V_152 -> V_152 . V_155 ;
F_56 ( V_152 ) ;
}
V_156 [ 0 ] = V_9 -> V_126 >> 8 ;
V_156 [ 1 ] = V_9 -> V_126 & 0xff ;
if ( F_57 ( & ( V_156 [ 2 ] ) , sizeof V_156 - 2 ) <= 0 )
goto V_122;
V_9 -> V_80 -> V_165 = sizeof V_156 ;
V_151 = V_114 ;
if ( V_9 -> V_31 > V_166 )
V_114 += 2 ;
V_137 = F_58 ( sizeof V_156 ,
V_156 , V_114 , V_155 , V_167 ) ;
#ifdef F_59
if ( V_9 -> V_168 & V_169 ) V_114 [ 1 ] ++ ;
if ( V_9 -> V_168 & V_170 ) V_156 [ 0 ] = 0x70 ;
#endif
if ( V_137 <= 0 )
{
F_13 ( V_164 , V_171 ) ;
goto V_122;
}
if ( V_9 -> V_31 > V_166 )
{
F_46 ( V_137 , V_151 ) ;
V_137 += 2 ;
}
V_9 -> V_80 -> V_165 =
V_9 -> V_85 -> V_86 -> V_172 ( V_9 ,
V_9 -> V_80 -> V_173 ,
V_156 , sizeof V_156 ) ;
F_60 ( V_156 , sizeof V_156 ) ;
}
#endif
#ifndef F_54
else if ( V_11 & V_174 )
{
T_8 V_175 ;
T_9 * V_176 = V_9 -> V_176 ;
T_10 * V_177 ;
T_10 V_178 , * V_179 = NULL ;
T_11 V_180 ;
T_12 * V_181 = NULL ;
unsigned char V_182 [ V_183 ] ;
unsigned char V_156 [ V_157 ] ;
unsigned char V_184 [ V_157
+ V_183 ] ;
int V_185 , V_186 = sizeof( V_184 ) ;
F_61 ( & V_180 ) ;
#ifdef F_62
printf ( L_1 ,
V_11 , V_174 ) ;
#endif
V_179 = NULL ;
#ifdef F_63
if ( F_63 ) V_179 = & V_178 ;
#endif
V_175 = F_64 ( V_176 , & V_177 , V_179 ,
& V_153 ) ;
V_181 = F_65 ( V_176 -> V_187 ) ;
if ( V_181 == NULL )
goto V_122;
#ifdef F_62
{
printf ( L_2 , V_175 ) ;
if ( V_175 && V_153 . V_188 )
printf ( L_3 , V_153 . V_188 ) ;
}
#endif
if ( V_175 )
{
F_52 ( V_9 , V_150 ,
V_189 ) ;
F_13 ( V_164 ,
V_153 . V_190 ) ;
goto V_122;
}
F_46 ( V_177 -> V_191 , V_114 ) ;
memcpy ( V_114 , V_177 -> V_119 , V_177 -> V_191 ) ;
V_114 += V_177 -> V_191 ;
V_137 = V_177 -> V_191 + 2 ;
if ( V_179 && V_179 -> V_191 )
{
F_46 ( V_179 -> V_191 , V_114 ) ;
memcpy ( V_114 , V_179 -> V_119 , V_179 -> V_191 ) ;
V_114 += V_179 -> V_191 ;
V_137 += V_179 -> V_191 + 2 ;
free ( V_179 -> V_119 ) ;
V_179 -> V_119 = NULL ;
V_179 -> V_191 = 0 ;
}
else
{
F_46 ( 0 , V_114 ) ;
V_137 += 2 ;
}
if ( F_57 ( V_156 , sizeof V_156 ) <= 0 )
goto V_122;
memset ( V_182 , 0 , sizeof V_182 ) ;
F_66 ( & V_180 , V_181 , NULL ,
V_176 -> V_192 , V_182 ) ;
F_67 ( & V_180 , V_184 , & V_186 , V_156 ,
sizeof V_156 ) ;
F_68 ( & V_180 , & ( V_184 [ V_186 ] ) , & V_185 ) ;
V_186 += V_185 ;
if ( V_186 > sizeof V_184 )
{
F_13 ( V_164 , V_33 ) ;
goto V_122;
}
F_69 ( & V_180 ) ;
F_46 ( V_186 , V_114 ) ;
memcpy ( V_114 , V_184 , V_186 ) ;
V_114 += V_186 ;
V_137 += V_186 + 2 ;
V_9 -> V_80 -> V_165 =
V_9 -> V_85 -> V_86 -> V_172 ( V_9 ,
V_9 -> V_80 -> V_173 ,
V_156 , sizeof V_156 ) ;
F_60 ( V_156 , sizeof V_156 ) ;
F_60 ( V_184 , V_186 ) ;
}
#endif
#ifndef F_70
else if ( V_11 & ( V_193 | V_194 | V_195 ) )
{
T_13 * V_196 , * V_197 ;
if ( V_9 -> V_80 -> V_158 -> V_198 != NULL )
V_196 = V_9 -> V_80 -> V_158 -> V_198 ;
else
{
F_52 ( V_9 , V_150 , V_189 ) ;
F_13 ( V_164 , V_199 ) ;
goto V_122;
}
if ( ( V_197 = F_71 ( V_196 ) ) == NULL )
{
F_13 ( V_164 , V_200 ) ;
goto V_122;
}
if ( ! F_72 ( V_197 ) )
{
F_13 ( V_164 , V_200 ) ;
goto V_122;
}
V_137 = F_73 ( V_114 , V_196 -> V_201 , V_197 ) ;
if ( V_137 <= 0 )
{
F_13 ( V_164 , V_200 ) ;
goto V_122;
}
V_9 -> V_80 -> V_165 =
V_9 -> V_85 -> V_86 -> V_172 ( V_9 ,
V_9 -> V_80 -> V_173 , V_114 , V_137 ) ;
memset ( V_114 , 0 , V_137 ) ;
V_137 = F_74 ( V_197 -> V_201 ) ;
F_46 ( V_137 , V_114 ) ;
F_75 ( V_197 -> V_201 , V_114 ) ;
V_137 += 2 ;
F_76 ( V_197 ) ;
}
#endif
else
{
F_52 ( V_9 , V_150 , V_189 ) ;
F_13 ( V_164 , V_33 ) ;
goto V_122;
}
V_115 = F_49 ( V_9 , V_115 ,
V_202 , V_137 , 0 , V_137 ) ;
V_9 -> V_17 = V_73 ;
V_9 -> V_39 = V_137 + V_125 ;
V_9 -> V_135 = 0 ;
F_50 ( V_9 , 0 ) ;
}
return ( F_51 ( V_9 , V_136 ) ) ;
V_122:
return ( - 1 ) ;
}
int F_30 ( T_2 * V_9 )
{
unsigned char * V_114 , * V_115 ;
unsigned char V_119 [ V_203 + V_204 ] ;
T_5 * V_152 ;
#ifndef F_53
unsigned V_205 = 0 ;
#endif
unsigned long V_137 ;
#ifndef F_77
int V_117 ;
#endif
if ( V_9 -> V_17 == V_74 )
{
V_115 = ( unsigned char * ) V_9 -> V_35 -> V_119 ;
V_114 = & ( V_115 [ V_125 ] ) ;
V_152 = V_9 -> V_206 -> V_192 -> V_207 ;
V_9 -> V_85 -> V_86 -> V_208 ( V_9 , & ( V_9 -> V_45 -> V_209 ) ,
& ( V_119 [ V_203 ] ) ) ;
#ifndef F_53
if ( V_152 -> type == V_163 )
{
V_9 -> V_85 -> V_86 -> V_208 ( V_9 ,
& ( V_9 -> V_45 -> V_210 ) , & ( V_119 [ 0 ] ) ) ;
if ( F_78 ( V_211 , V_119 ,
V_203 + V_204 ,
& ( V_114 [ 2 ] ) , & V_205 , V_152 -> V_152 . V_155 ) <= 0 )
{
F_13 ( V_212 , V_213 ) ;
goto V_122;
}
F_46 ( V_205 , V_114 ) ;
V_137 = V_205 + 2 ;
}
else
#endif
#ifndef F_77
if ( V_152 -> type == V_214 )
{
if ( ! F_79 ( V_152 -> V_215 ,
& ( V_119 [ V_203 ] ) ,
V_204 , & ( V_114 [ 2 ] ) ,
( unsigned int * ) & V_117 , V_152 -> V_152 . V_216 ) )
{
F_13 ( V_212 , V_217 ) ;
goto V_122;
}
F_46 ( V_117 , V_114 ) ;
V_137 = V_117 + 2 ;
}
else
#endif
{
F_13 ( V_212 , V_33 ) ;
goto V_122;
}
V_115 = F_49 ( V_9 , V_115 ,
V_218 , V_137 , 0 , V_137 ) ;
V_9 -> V_39 = ( int ) V_137 + V_125 ;
V_9 -> V_135 = 0 ;
F_50 ( V_9 , 0 ) ;
V_9 -> V_17 = V_77 ;
}
return ( F_51 ( V_9 , V_136 ) ) ;
V_122:
return ( - 1 ) ;
}
int F_28 ( T_2 * V_9 )
{
T_14 * V_162 = NULL ;
T_5 * V_152 = NULL ;
int V_116 ;
unsigned long V_11 ;
if ( V_9 -> V_17 == V_68 )
{
if ( ( V_9 -> V_206 == NULL ) ||
( V_9 -> V_206 -> V_192 -> V_162 == NULL ) ||
( V_9 -> V_206 -> V_192 -> V_207 == NULL ) )
V_9 -> V_17 = V_70 ;
else
V_9 -> V_17 = V_71 ;
}
if ( V_9 -> V_17 == V_70 )
{
V_116 = 0 ;
if ( V_9 -> V_20 -> V_219 != NULL )
V_116 = V_9 -> V_20 -> V_219 ( V_9 , & ( V_162 ) , & ( V_152 ) ) ;
if ( V_116 < 0 )
{
V_9 -> V_100 = V_220 ;
return ( - 1 ) ;
}
V_9 -> V_100 = V_102 ;
if ( ( V_116 == 1 ) && ( V_152 != NULL ) && ( V_162 != NULL ) )
{
V_9 -> V_17 = V_70 ;
if ( ! F_80 ( V_9 , V_162 ) ||
! F_81 ( V_9 , V_152 ) )
V_116 = 0 ;
}
else if ( V_116 == 1 )
{
V_116 = 0 ;
F_13 ( V_221 , V_222 ) ;
}
if ( V_162 != NULL ) F_82 ( V_162 ) ;
if ( V_152 != NULL ) F_56 ( V_152 ) ;
if ( V_116 == 0 )
{
if ( V_9 -> V_31 == V_166 )
{
V_9 -> V_45 -> V_46 . V_67 = 0 ;
F_52 ( V_9 , V_223 , V_224 ) ;
return ( 1 ) ;
}
else
{
V_9 -> V_45 -> V_46 . V_67 = 2 ;
}
}
V_9 -> V_17 = V_71 ;
}
if ( V_9 -> V_17 == V_71 )
{
V_9 -> V_17 = V_72 ;
V_11 = F_83 ( V_9 ,
( V_9 -> V_45 -> V_46 . V_67 == 2 ) ? NULL : V_9 -> V_206 -> V_192 -> V_162 ) ;
V_9 -> V_39 = ( int ) V_11 ;
V_9 -> V_135 = 0 ;
F_50 ( V_9 , 0 ) ;
}
return ( F_51 ( V_9 , V_136 ) ) ;
}
