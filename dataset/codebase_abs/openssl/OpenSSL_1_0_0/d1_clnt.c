static const T_1 * F_1 ( int V_1 )
{
if ( V_1 == V_2 || V_1 == V_3 )
return ( F_2 () ) ;
else
return ( NULL ) ;
}
int F_3 ( T_2 * V_4 )
{
T_3 * V_5 = NULL ;
unsigned long Time = ( unsigned long ) time ( NULL ) ;
void (* F_4)( const T_2 * V_6 , int type , int V_7 ) = NULL ;
int V_8 = - 1 ;
int V_9 , V_10 , V_11 = 0 ; ;
F_5 ( & Time , sizeof( Time ) , 0 ) ;
F_6 () ;
F_7 () ;
if ( V_4 -> V_12 != NULL )
F_4 = V_4 -> V_12 ;
else if ( V_4 -> V_13 -> V_12 != NULL )
F_4 = V_4 -> V_13 -> V_12 ;
V_4 -> V_14 ++ ;
if ( ! F_8 ( V_4 ) || F_9 ( V_4 ) ) F_10 ( V_4 ) ;
for (; ; )
{
V_10 = V_4 -> V_10 ;
switch( V_4 -> V_10 )
{
case V_15 :
V_4 -> V_16 = 1 ;
V_4 -> V_10 = V_17 ;
V_4 -> V_13 -> V_18 . V_19 ++ ;
case V_20 :
case V_17 :
case V_20 | V_17 :
case V_21 | V_17 :
V_4 -> V_22 = 0 ;
if ( F_4 != NULL ) F_4 ( V_4 , V_23 , 1 ) ;
if ( ( V_4 -> V_24 & 0xff00 ) != ( V_2 & 0xff00 ) &&
( V_4 -> V_24 & 0xff00 ) != ( V_3 & 0xff00 ) )
{
F_11 ( V_25 , V_26 ) ;
V_8 = - 1 ;
goto V_27;
}
V_4 -> type = V_17 ;
if ( V_4 -> V_28 == NULL )
{
if ( ( V_5 = F_12 () ) == NULL )
{
V_8 = - 1 ;
goto V_27;
}
if ( ! F_13 ( V_5 , V_29 ) )
{
V_8 = - 1 ;
goto V_27;
}
V_4 -> V_28 = V_5 ;
V_5 = NULL ;
}
if ( ! F_14 ( V_4 ) ) { V_8 = - 1 ; goto V_27; }
if ( ! F_15 ( V_4 , 0 ) ) { V_8 = - 1 ; goto V_27; }
V_4 -> V_10 = V_30 ;
V_4 -> V_13 -> V_18 . V_31 ++ ;
V_4 -> V_32 = 0 ;
memset ( V_4 -> V_33 -> V_34 , 0 , sizeof( V_4 -> V_33 -> V_34 ) ) ;
V_4 -> V_35 -> V_36 = 0 ;
V_4 -> V_37 = 0 ;
break;
case V_30 :
case V_38 :
V_4 -> V_39 = 0 ;
F_16 ( V_4 ) ;
F_17 ( V_4 ) ;
V_8 = F_18 ( V_4 ) ;
if ( V_8 <= 0 ) goto V_27;
if ( V_4 -> V_35 -> V_36 )
{
V_4 -> V_10 = V_40 ;
V_4 -> V_33 -> V_41 . V_42 = V_43 ;
}
else
V_4 -> V_10 = V_43 ;
V_4 -> V_32 = 0 ;
if ( V_4 -> V_44 != V_4 -> V_45 )
V_4 -> V_45 = F_19 ( V_4 -> V_44 , V_4 -> V_45 ) ;
break;
case V_43 :
case V_46 :
V_8 = F_20 ( V_4 ) ;
if ( V_8 <= 0 ) goto V_27;
else
{
F_21 ( V_4 ) ;
if ( V_4 -> V_37 )
V_4 -> V_10 = V_47 ;
else
V_4 -> V_10 = V_48 ;
}
V_4 -> V_32 = 0 ;
break;
case V_48 :
case V_49 :
V_8 = F_22 ( V_4 ) ;
if ( V_8 <= 0 )
goto V_27;
F_21 ( V_4 ) ;
if ( V_4 -> V_35 -> V_36 )
V_4 -> V_10 = V_30 ;
else
V_4 -> V_10 = V_50 ;
V_4 -> V_32 = 0 ;
break;
case V_50 :
case V_51 :
#ifndef F_23
V_8 = F_24 ( V_4 ) ;
if ( V_8 <= 0 ) goto V_27;
if ( V_8 == 2 )
{
V_4 -> V_37 = 1 ;
if ( V_4 -> V_52 )
V_4 -> V_10 = V_53 ;
else
V_4 -> V_10 = V_47 ;
V_4 -> V_32 = 0 ;
break;
}
#endif
if ( ! ( V_4 -> V_33 -> V_41 . V_54 -> V_55 & V_56 ) &&
! ( V_4 -> V_33 -> V_41 . V_54 -> V_57 & V_58 ) )
{
V_8 = F_25 ( V_4 ) ;
if ( V_8 <= 0 ) goto V_27;
#ifndef F_23
if ( V_4 -> V_59 )
V_4 -> V_10 = V_60 ;
else
V_4 -> V_10 = V_61 ;
}
else
{
V_11 = 1 ;
V_4 -> V_10 = V_61 ;
}
#else
}
else
V_11 = 1 ;
V_4 -> V_10 = V_61 ;
#endif
V_4 -> V_32 = 0 ;
break;
case V_61 :
case V_62 :
V_8 = F_26 ( V_4 ) ;
if ( V_8 <= 0 ) goto V_27;
V_4 -> V_10 = V_63 ;
V_4 -> V_32 = 0 ;
if ( ! F_27 ( V_4 ) )
{
V_8 = - 1 ;
goto V_27;
}
break;
case V_63 :
case V_64 :
V_8 = F_28 ( V_4 ) ;
if ( V_8 <= 0 ) goto V_27;
V_4 -> V_10 = V_65 ;
V_4 -> V_32 = 0 ;
break;
case V_65 :
case V_66 :
V_8 = F_29 ( V_4 ) ;
if ( V_8 <= 0 ) goto V_27;
if ( V_4 -> V_33 -> V_41 . V_67 )
V_4 -> V_10 = V_68 ;
else
V_4 -> V_10 = V_69 ;
V_4 -> V_32 = 0 ;
break;
case V_68 :
case V_70 :
case V_71 :
case V_72 :
F_17 ( V_4 ) ;
V_8 = F_30 ( V_4 ) ;
if ( V_8 <= 0 ) goto V_27;
V_4 -> V_10 = V_69 ;
V_4 -> V_32 = 0 ;
break;
case V_69 :
case V_73 :
F_17 ( V_4 ) ;
V_8 = F_31 ( V_4 ) ;
if ( V_8 <= 0 ) goto V_27;
if ( V_4 -> V_33 -> V_41 . V_67 == 1 )
{
V_4 -> V_10 = V_74 ;
}
else
{
V_4 -> V_10 = V_75 ;
V_4 -> V_33 -> V_76 = 0 ;
}
V_4 -> V_32 = 0 ;
break;
case V_74 :
case V_77 :
F_17 ( V_4 ) ;
V_8 = F_32 ( V_4 ) ;
if ( V_8 <= 0 ) goto V_27;
V_4 -> V_10 = V_75 ;
V_4 -> V_32 = 0 ;
V_4 -> V_33 -> V_76 = 0 ;
break;
case V_75 :
case V_78 :
F_17 ( V_4 ) ;
V_8 = F_33 ( V_4 ,
V_75 , V_78 ) ;
if ( V_8 <= 0 ) goto V_27;
V_4 -> V_10 = V_79 ;
V_4 -> V_32 = 0 ;
V_4 -> V_80 -> V_81 = V_4 -> V_33 -> V_41 . V_54 ;
#ifdef F_34
V_4 -> V_80 -> V_82 = 0 ;
#else
if ( V_4 -> V_33 -> V_41 . V_83 == NULL )
V_4 -> V_80 -> V_82 = 0 ;
else
V_4 -> V_80 -> V_82 =
V_4 -> V_33 -> V_41 . V_83 -> V_84 ;
#endif
if ( ! V_4 -> V_85 -> V_86 -> V_87 ( V_4 ) )
{
V_8 = - 1 ;
goto V_27;
}
if ( ! V_4 -> V_85 -> V_86 -> V_88 ( V_4 ,
V_89 ) )
{
V_8 = - 1 ;
goto V_27;
}
F_35 ( V_4 , V_90 ) ;
break;
case V_79 :
case V_91 :
F_17 ( V_4 ) ;
V_8 = F_36 ( V_4 ,
V_79 , V_91 ,
V_4 -> V_85 -> V_86 -> V_92 ,
V_4 -> V_85 -> V_86 -> V_93 ) ;
if ( V_8 <= 0 ) goto V_27;
V_4 -> V_10 = V_40 ;
V_4 -> V_33 -> V_94 &= ~ V_95 ;
if ( V_4 -> V_37 )
{
V_4 -> V_33 -> V_41 . V_42 = V_21 ;
if ( V_4 -> V_33 -> V_94 & V_96 )
{
V_4 -> V_10 = V_21 ;
V_4 -> V_33 -> V_94 |= V_95 ;
V_4 -> V_33 -> V_97 = 0 ;
}
}
else
{
#ifndef F_23
if ( V_4 -> V_52 )
V_4 -> V_33 -> V_41 . V_42 = V_53 ;
else
#endif
V_4 -> V_33 -> V_41 . V_42 = V_47 ;
}
V_4 -> V_32 = 0 ;
break;
#ifndef F_23
case V_53 :
case V_98 :
V_8 = F_37 ( V_4 ) ;
if ( V_8 <= 0 ) goto V_27;
V_4 -> V_10 = V_47 ;
V_4 -> V_32 = 0 ;
break;
case V_60 :
case V_99 :
V_8 = F_38 ( V_4 ) ;
if ( V_8 <= 0 ) goto V_27;
V_4 -> V_10 = V_61 ;
V_4 -> V_32 = 0 ;
break;
#endif
case V_47 :
case V_100 :
V_4 -> V_35 -> V_101 = 1 ;
V_8 = F_39 ( V_4 , V_47 ,
V_100 ) ;
if ( V_8 <= 0 ) goto V_27;
F_21 ( V_4 ) ;
if ( V_4 -> V_37 )
V_4 -> V_10 = V_75 ;
else
V_4 -> V_10 = V_21 ;
V_4 -> V_32 = 0 ;
break;
case V_40 :
V_4 -> V_102 = V_103 ;
if ( F_40 ( V_4 -> V_45 ) <= 0 )
{
V_8 = - 1 ;
goto V_27;
}
V_4 -> V_102 = V_104 ;
V_4 -> V_10 = V_4 -> V_33 -> V_41 . V_42 ;
break;
case V_21 :
F_41 ( V_4 ) ;
#if 0
if (s->init_buf != NULL)
{
BUF_MEM_free(s->init_buf);
s->init_buf=NULL;
}
#endif
if ( ! ( V_4 -> V_33 -> V_94 & V_95 ) )
F_42 ( V_4 ) ;
V_4 -> V_32 = 0 ;
V_4 -> V_16 = 0 ;
F_43 ( V_4 , V_105 ) ;
if ( V_4 -> V_37 ) V_4 -> V_13 -> V_18 . V_106 ++ ;
V_8 = 1 ;
V_4 -> V_107 = F_3 ;
V_4 -> V_13 -> V_18 . V_108 ++ ;
if ( F_4 != NULL ) F_4 ( V_4 , V_109 , 1 ) ;
V_4 -> V_35 -> V_110 = 0 ;
V_4 -> V_35 -> V_111 = 0 ;
goto V_27;
default:
F_11 ( V_25 , V_112 ) ;
V_8 = - 1 ;
goto V_27;
}
if ( ! V_4 -> V_33 -> V_41 . V_113 && ! V_11 )
{
if ( V_4 -> V_114 )
{
if ( ( V_8 = F_40 ( V_4 -> V_45 ) ) <= 0 )
goto V_27;
}
if ( ( F_4 != NULL ) && ( V_4 -> V_10 != V_10 ) )
{
V_9 = V_4 -> V_10 ;
V_4 -> V_10 = V_10 ;
F_4 ( V_4 , V_115 , 1 ) ;
V_4 -> V_10 = V_9 ;
}
}
V_11 = 0 ;
}
static int F_22 ( T_2 * V_4 )
{
int V_116 , V_117 , V_118 = 0 ;
unsigned char * V_119 ;
unsigned int V_120 ;
V_116 = V_4 -> V_85 -> V_121 ( V_4 ,
V_48 ,
V_49 ,
- 1 ,
V_4 -> V_122 ,
& V_118 ) ;
if ( ! V_118 ) return ( ( int ) V_116 ) ;
if ( V_4 -> V_33 -> V_41 . V_123 != V_124 )
{
V_4 -> V_35 -> V_36 = 0 ;
V_4 -> V_33 -> V_41 . V_113 = 1 ;
return ( 1 ) ;
}
V_119 = ( unsigned char * ) V_4 -> V_125 ;
if ( ( V_119 [ 0 ] != ( V_4 -> V_24 >> 8 ) ) || ( V_119 [ 1 ] != ( V_4 -> V_24 & 0xff ) ) )
{
F_11 ( V_126 , V_127 ) ;
V_4 -> V_24 = ( V_4 -> V_24 & 0xff00 ) | V_119 [ 1 ] ;
V_117 = V_128 ;
goto V_129;
}
V_119 += 2 ;
V_120 = * ( V_119 ++ ) ;
if ( V_120 > sizeof( V_4 -> V_35 -> V_130 ) )
{
V_117 = V_131 ;
goto V_129;
}
memcpy ( V_4 -> V_35 -> V_130 , V_119 , V_120 ) ;
V_4 -> V_35 -> V_120 = V_120 ;
V_4 -> V_35 -> V_36 = 1 ;
return 1 ;
V_129:
F_44 ( V_4 , V_132 , V_117 ) ;
return - 1 ;
}
int F_31 ( T_2 * V_4 )
{
unsigned char * V_133 , * V_134 ;
int V_116 ;
unsigned long V_135 ;
#ifndef F_45
unsigned char * V_136 ;
T_4 * V_137 = NULL ;
#endif
#ifndef F_46
T_5 V_138 ;
#endif
#ifndef F_47
T_6 * V_139 = NULL ;
const T_7 * V_140 = NULL ;
T_4 * V_141 = NULL ;
unsigned char * V_142 = NULL ;
int V_143 = 0 ;
T_8 * V_144 = NULL ;
#endif
if ( V_4 -> V_10 == V_69 )
{
V_134 = ( unsigned char * ) V_4 -> V_28 -> V_119 ;
V_133 = & ( V_134 [ V_145 ] ) ;
V_135 = V_4 -> V_33 -> V_41 . V_54 -> V_57 ;
if ( 0 ) {}
#ifndef F_45
else if ( V_135 & V_146 )
{
T_9 * V_147 ;
unsigned char V_148 [ V_149 ] ;
if ( V_4 -> V_80 -> V_150 -> V_151 != NULL )
V_147 = V_4 -> V_80 -> V_150 -> V_151 ;
else
{
V_137 = F_48 ( V_4 -> V_80 -> V_150 -> V_152 [ V_153 ] . V_154 ) ;
if ( ( V_137 == NULL ) ||
( V_137 -> type != V_155 ) ||
( V_137 -> V_137 . V_147 == NULL ) )
{
F_11 ( V_156 , V_26 ) ;
goto V_157;
}
V_147 = V_137 -> V_137 . V_147 ;
F_49 ( V_137 ) ;
}
V_148 [ 0 ] = V_4 -> V_158 >> 8 ;
V_148 [ 1 ] = V_4 -> V_158 & 0xff ;
if ( F_50 ( & ( V_148 [ 2 ] ) , sizeof V_148 - 2 ) <= 0 )
goto V_157;
V_4 -> V_80 -> V_159 = sizeof V_148 ;
V_136 = V_133 ;
if ( V_4 -> V_24 > V_160 )
V_133 += 2 ;
V_116 = F_51 ( sizeof V_148 ,
V_148 , V_133 , V_147 , V_161 ) ;
#ifdef F_52
if ( V_4 -> V_162 & V_163 ) V_133 [ 1 ] ++ ;
if ( V_4 -> V_162 & V_164 ) V_148 [ 0 ] = 0x70 ;
#endif
if ( V_116 <= 0 )
{
F_11 ( V_156 , V_165 ) ;
goto V_157;
}
if ( V_4 -> V_24 > V_160 )
{
F_53 ( V_116 , V_136 ) ;
V_116 += 2 ;
}
V_4 -> V_80 -> V_159 =
V_4 -> V_85 -> V_86 -> V_166 ( V_4 ,
V_4 -> V_80 -> V_167 ,
V_148 , sizeof V_148 ) ;
F_54 ( V_148 , sizeof V_148 ) ;
}
#endif
#ifndef F_46
else if ( V_135 & V_168 )
{
T_10 V_169 ;
T_11 * V_170 = V_4 -> V_170 ;
T_12 * V_171 ;
T_12 V_172 , * V_173 = NULL ;
T_13 V_174 ;
const T_14 * V_175 = NULL ;
unsigned char V_176 [ V_177 ] ;
unsigned char V_148 [ V_149 ] ;
unsigned char V_178 [ V_149
+ V_177 ] ;
int V_179 , V_180 = sizeof( V_178 ) ;
F_55 ( & V_174 ) ;
#ifdef F_56
printf ( L_1 ,
V_135 , V_168 ) ;
#endif
V_173 = NULL ;
#ifdef F_57
if ( F_57 ) V_173 = & V_172 ;
#endif
V_169 = F_58 ( V_170 , & V_171 , V_173 ,
& V_138 ) ;
V_175 = F_59 ( V_170 -> V_181 ) ;
if ( V_175 == NULL )
goto V_157;
#ifdef F_56
{
printf ( L_2 , V_169 ) ;
if ( V_169 && V_138 . V_182 )
printf ( L_3 , V_138 . V_182 ) ;
}
#endif
if ( V_169 )
{
F_44 ( V_4 , V_132 ,
V_183 ) ;
F_11 ( V_156 ,
V_138 . V_184 ) ;
goto V_157;
}
F_53 ( V_171 -> V_185 , V_133 ) ;
memcpy ( V_133 , V_171 -> V_119 , V_171 -> V_185 ) ;
V_133 += V_171 -> V_185 ;
V_116 = V_171 -> V_185 + 2 ;
if ( V_173 && V_173 -> V_185 )
{
F_53 ( V_173 -> V_185 , V_133 ) ;
memcpy ( V_133 , V_173 -> V_119 , V_173 -> V_185 ) ;
V_133 += V_173 -> V_185 ;
V_116 += V_173 -> V_185 + 2 ;
free ( V_173 -> V_119 ) ;
V_173 -> V_119 = NULL ;
V_173 -> V_185 = 0 ;
}
else
{
F_53 ( 0 , V_133 ) ;
V_116 += 2 ;
}
if ( F_50 ( V_148 , sizeof V_148 ) <= 0 )
goto V_157;
memset ( V_176 , 0 , sizeof V_176 ) ;
F_60 ( & V_174 , V_175 , NULL ,
V_170 -> V_186 , V_176 ) ;
F_61 ( & V_174 , V_178 , & V_180 , V_148 ,
sizeof V_148 ) ;
F_62 ( & V_174 , & ( V_178 [ V_180 ] ) , & V_179 ) ;
V_180 += V_179 ;
if ( V_180 > ( int ) sizeof V_178 )
{
F_11 ( V_156 , V_26 ) ;
goto V_157;
}
F_63 ( & V_174 ) ;
F_53 ( V_180 , V_133 ) ;
memcpy ( V_133 , V_178 , V_180 ) ;
V_133 += V_180 ;
V_116 += V_180 + 2 ;
V_4 -> V_80 -> V_159 =
V_4 -> V_85 -> V_86 -> V_166 ( V_4 ,
V_4 -> V_80 -> V_167 ,
V_148 , sizeof V_148 ) ;
F_54 ( V_148 , sizeof V_148 ) ;
F_54 ( V_178 , V_180 ) ;
}
#endif
#ifndef F_64
else if ( V_135 & ( V_187 | V_188 | V_189 ) )
{
T_15 * V_190 , * V_191 ;
if ( V_4 -> V_80 -> V_150 -> V_192 != NULL )
V_190 = V_4 -> V_80 -> V_150 -> V_192 ;
else
{
F_44 ( V_4 , V_132 , V_183 ) ;
F_11 ( V_156 , V_193 ) ;
goto V_157;
}
if ( ( V_191 = F_65 ( V_190 ) ) == NULL )
{
F_11 ( V_156 , V_194 ) ;
goto V_157;
}
if ( ! F_66 ( V_191 ) )
{
F_11 ( V_156 , V_194 ) ;
goto V_157;
}
V_116 = F_67 ( V_133 , V_190 -> V_195 , V_191 ) ;
if ( V_116 <= 0 )
{
F_11 ( V_156 , V_194 ) ;
goto V_157;
}
V_4 -> V_80 -> V_159 =
V_4 -> V_85 -> V_86 -> V_166 ( V_4 ,
V_4 -> V_80 -> V_167 , V_133 , V_116 ) ;
memset ( V_133 , 0 , V_116 ) ;
V_116 = F_68 ( V_191 -> V_195 ) ;
F_53 ( V_116 , V_133 ) ;
F_69 ( V_191 -> V_195 , V_133 ) ;
V_116 += 2 ;
F_70 ( V_191 ) ;
}
#endif
#ifndef F_47
else if ( V_135 & ( V_196 | V_197 | V_198 ) )
{
const T_16 * V_199 = NULL ;
T_6 * V_200 ;
int V_201 = 0 ;
int V_202 = 0 ;
if ( ( V_135 & ( V_197 | V_198 ) ) && ( V_4 -> V_203 != NULL ) )
{
}
if ( V_4 -> V_80 -> V_150 -> V_204 != NULL )
{
V_200 = V_4 -> V_80 -> V_150 -> V_204 ;
}
else
{
V_141 = F_48 ( V_4 -> V_80 -> \
V_150 -> V_152 [ V_205 ] . V_154 ) ;
if ( ( V_141 == NULL ) ||
( V_141 -> type != V_206 ) ||
( V_141 -> V_137 . V_207 == NULL ) )
{
F_11 ( V_156 ,
V_26 ) ;
goto V_157;
}
V_200 = V_141 -> V_137 . V_207 ;
}
V_199 = F_71 ( V_200 ) ;
V_140 = F_72 ( V_200 ) ;
if ( ( V_199 == NULL ) || ( V_140 == NULL ) )
{
F_11 ( V_156 ,
V_26 ) ;
goto V_157;
}
if ( ( V_139 = F_73 () ) == NULL )
{
F_11 ( V_156 , V_208 ) ;
goto V_157;
}
if ( ! F_74 ( V_139 , V_199 ) )
{
F_11 ( V_156 , V_209 ) ;
goto V_157;
}
if ( V_201 )
{
const T_17 * V_210 ;
V_200 = V_4 -> V_203 -> V_186 -> V_211 -> V_137 . V_207 ;
V_210 = F_75 ( V_200 ) ;
if ( V_210 == NULL )
{
F_11 ( V_156 , V_208 ) ;
goto V_157;
}
if ( ! F_76 ( V_139 , V_210 ) )
{
F_11 ( V_156 , V_209 ) ;
goto V_157;
}
}
else
{
if ( ! ( F_77 ( V_139 ) ) )
{
F_11 ( V_156 , V_212 ) ;
goto V_157;
}
}
V_202 = F_78 ( V_199 ) ;
if ( V_202 <= 0 )
{
F_11 ( V_156 ,
V_212 ) ;
goto V_157;
}
V_116 = F_79 ( V_133 , ( V_202 + 7 ) / 8 , V_140 , V_139 , NULL ) ;
if ( V_116 <= 0 )
{
F_11 ( V_156 ,
V_212 ) ;
goto V_157;
}
V_4 -> V_80 -> V_159 = V_4 -> V_85 -> V_86 \
-> V_166 ( V_4 ,
V_4 -> V_80 -> V_167 ,
V_133 , V_116 ) ;
memset ( V_133 , 0 , V_116 ) ;
if ( V_201 )
{
V_116 = 0 ;
}
else
{
V_143 =
F_80 ( V_199 ,
F_72 ( V_139 ) ,
V_213 ,
NULL , 0 , NULL ) ;
V_142 = ( unsigned char * )
F_81 ( V_143 *
sizeof( unsigned char ) ) ;
V_144 = F_82 () ;
if ( ( V_142 == NULL ) ||
( V_144 == NULL ) )
{
F_11 ( V_156 , V_208 ) ;
goto V_157;
}
V_116 = F_80 ( V_199 ,
F_72 ( V_139 ) ,
V_213 ,
V_142 , V_143 , V_144 ) ;
* V_133 = V_116 ;
V_133 += 1 ;
memcpy ( ( unsigned char * ) V_133 , V_142 , V_116 ) ;
V_116 += 1 ;
}
F_83 ( V_144 ) ;
if ( V_142 != NULL ) F_84 ( V_142 ) ;
if ( V_139 != NULL )
F_85 ( V_139 ) ;
F_49 ( V_141 ) ;
}
#endif
#ifndef F_86
else if ( V_135 & V_58 )
{
char V_214 [ V_215 ] ;
unsigned char * V_216 = NULL ;
unsigned char V_217 [ V_218 * 2 + 4 ] ;
unsigned int V_219 = 0 , V_220 = 0 ;
int V_221 = 1 ;
V_116 = 0 ;
if ( V_4 -> V_222 == NULL )
{
F_11 ( V_156 ,
V_223 ) ;
goto V_157;
}
V_220 = V_4 -> V_222 ( V_4 , V_4 -> V_13 -> V_224 ,
V_214 , V_215 ,
V_217 , sizeof( V_217 ) ) ;
if ( V_220 > V_218 )
{
F_11 ( V_156 ,
V_26 ) ;
goto V_221;
}
else if ( V_220 == 0 )
{
F_11 ( V_156 ,
V_225 ) ;
goto V_221;
}
V_219 = 2 + V_220 + 2 + V_220 ;
V_216 = V_217 ;
memmove ( V_217 + V_220 + 4 , V_217 , V_220 ) ;
F_53 ( V_220 , V_216 ) ;
memset ( V_216 , 0 , V_220 ) ;
V_216 += V_220 ;
F_53 ( V_220 , V_216 ) ;
if ( V_4 -> V_80 -> V_224 != NULL )
F_84 ( V_4 -> V_80 -> V_224 ) ;
V_4 -> V_80 -> V_224 = F_87 ( V_4 -> V_13 -> V_224 ) ;
if ( V_4 -> V_13 -> V_224 != NULL &&
V_4 -> V_80 -> V_224 == NULL )
{
F_11 ( V_156 ,
V_208 ) ;
goto V_221;
}
if ( V_4 -> V_80 -> V_226 != NULL )
F_84 ( V_4 -> V_80 -> V_226 ) ;
V_4 -> V_80 -> V_226 = F_87 ( V_214 ) ;
if ( V_4 -> V_80 -> V_226 == NULL )
{
F_11 ( V_156 ,
V_208 ) ;
goto V_221;
}
V_4 -> V_80 -> V_159 =
V_4 -> V_85 -> V_86 -> V_166 ( V_4 ,
V_4 -> V_80 -> V_167 ,
V_217 , V_219 ) ;
V_116 = strlen ( V_214 ) ;
F_53 ( V_116 , V_133 ) ;
memcpy ( V_133 , V_214 , V_116 ) ;
V_116 += 2 ;
V_221 = 0 ;
V_221:
F_54 ( V_214 , V_215 ) ;
F_54 ( V_217 , sizeof( V_217 ) ) ;
if ( V_221 != 0 )
{
F_44 ( V_4 , V_132 , V_183 ) ;
goto V_157;
}
}
#endif
else
{
F_44 ( V_4 , V_132 , V_183 ) ;
F_11 ( V_156 , V_26 ) ;
goto V_157;
}
V_134 = F_88 ( V_4 , V_134 ,
V_227 , V_116 , 0 , V_116 ) ;
V_4 -> V_10 = V_73 ;
V_4 -> V_32 = V_116 + V_145 ;
V_4 -> V_228 = 0 ;
F_89 ( V_4 , 0 ) ;
}
return ( F_90 ( V_4 , V_229 ) ) ;
V_157:
#ifndef F_47
F_83 ( V_144 ) ;
if ( V_142 != NULL ) F_84 ( V_142 ) ;
if ( V_139 != NULL )
F_85 ( V_139 ) ;
F_49 ( V_141 ) ;
#endif
return ( - 1 ) ;
}
int F_32 ( T_2 * V_4 )
{
unsigned char * V_133 , * V_134 ;
unsigned char V_119 [ V_230 + V_231 ] ;
T_4 * V_137 ;
#ifndef F_45
unsigned V_232 = 0 ;
#endif
unsigned long V_116 ;
#if ! F_91 ( V_233 ) || ! F_91 ( V_234 )
int V_235 ;
#endif
if ( V_4 -> V_10 == V_74 )
{
V_134 = ( unsigned char * ) V_4 -> V_28 -> V_119 ;
V_133 = & ( V_134 [ V_145 ] ) ;
V_137 = V_4 -> V_203 -> V_186 -> V_211 ;
V_4 -> V_85 -> V_86 -> V_236 ( V_4 ,
V_237 ,
& ( V_119 [ V_230 ] ) ) ;
#ifndef F_45
if ( V_137 -> type == V_155 )
{
V_4 -> V_85 -> V_86 -> V_236 ( V_4 ,
V_238 ,
& ( V_119 [ 0 ] ) ) ;
if ( F_92 ( V_239 , V_119 ,
V_230 + V_231 ,
& ( V_133 [ 2 ] ) , & V_232 , V_137 -> V_137 . V_147 ) <= 0 )
{
F_11 ( V_240 , V_241 ) ;
goto V_157;
}
F_53 ( V_232 , V_133 ) ;
V_116 = V_232 + 2 ;
}
else
#endif
#ifndef V_233
if ( V_137 -> type == V_242 )
{
if ( ! F_93 ( V_137 -> V_243 ,
& ( V_119 [ V_230 ] ) ,
V_231 , & ( V_133 [ 2 ] ) ,
( unsigned int * ) & V_235 , V_137 -> V_137 . V_244 ) )
{
F_11 ( V_240 , V_245 ) ;
goto V_157;
}
F_53 ( V_235 , V_133 ) ;
V_116 = V_235 + 2 ;
}
else
#endif
#ifndef V_234
if ( V_137 -> type == V_206 )
{
if ( ! F_94 ( V_137 -> V_243 ,
& ( V_119 [ V_230 ] ) ,
V_231 , & ( V_133 [ 2 ] ) ,
( unsigned int * ) & V_235 , V_137 -> V_137 . V_207 ) )
{
F_11 ( V_240 ,
V_246 ) ;
goto V_157;
}
F_53 ( V_235 , V_133 ) ;
V_116 = V_235 + 2 ;
}
else
#endif
{
F_11 ( V_240 , V_26 ) ;
goto V_157;
}
V_134 = F_88 ( V_4 , V_134 ,
V_247 , V_116 , 0 , V_116 ) ;
V_4 -> V_32 = ( int ) V_116 + V_145 ;
V_4 -> V_228 = 0 ;
F_89 ( V_4 , 0 ) ;
V_4 -> V_10 = V_77 ;
}
return ( F_90 ( V_4 , V_229 ) ) ;
V_157:
return ( - 1 ) ;
}
int F_30 ( T_2 * V_4 )
{
T_18 * V_154 = NULL ;
T_4 * V_137 = NULL ;
int V_248 ;
unsigned long V_249 ;
if ( V_4 -> V_10 == V_68 )
{
if ( ( V_4 -> V_203 == NULL ) ||
( V_4 -> V_203 -> V_186 -> V_154 == NULL ) ||
( V_4 -> V_203 -> V_186 -> V_211 == NULL ) )
V_4 -> V_10 = V_70 ;
else
V_4 -> V_10 = V_71 ;
}
if ( V_4 -> V_10 == V_70 )
{
V_248 = 0 ;
V_248 = F_95 ( V_4 , & V_154 , & V_137 ) ;
if ( V_248 < 0 )
{
V_4 -> V_102 = V_250 ;
return ( - 1 ) ;
}
V_4 -> V_102 = V_104 ;
if ( ( V_248 == 1 ) && ( V_137 != NULL ) && ( V_154 != NULL ) )
{
V_4 -> V_10 = V_70 ;
if ( ! F_96 ( V_4 , V_154 ) ||
! F_97 ( V_4 , V_137 ) )
V_248 = 0 ;
}
else if ( V_248 == 1 )
{
V_248 = 0 ;
F_11 ( V_251 , V_252 ) ;
}
if ( V_154 != NULL ) F_98 ( V_154 ) ;
if ( V_137 != NULL ) F_49 ( V_137 ) ;
if ( V_248 == 0 )
{
if ( V_4 -> V_24 == V_160 )
{
V_4 -> V_33 -> V_41 . V_67 = 0 ;
F_44 ( V_4 , V_253 , V_254 ) ;
return ( 1 ) ;
}
else
{
V_4 -> V_33 -> V_41 . V_67 = 2 ;
}
}
V_4 -> V_10 = V_71 ;
}
if ( V_4 -> V_10 == V_71 )
{
V_4 -> V_10 = V_72 ;
V_249 = F_99 ( V_4 ,
( V_4 -> V_33 -> V_41 . V_67 == 2 ) ? NULL : V_4 -> V_203 -> V_186 -> V_154 ) ;
V_4 -> V_32 = ( int ) V_249 ;
V_4 -> V_228 = 0 ;
F_89 ( V_4 , 0 ) ;
}
return ( F_90 ( V_4 , V_229 ) ) ;
}
