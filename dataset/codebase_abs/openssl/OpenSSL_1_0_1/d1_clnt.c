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
int V_9 , V_10 , V_11 = 0 ;
#ifndef F_5
unsigned char V_12 [ 64 ] ;
char V_13 [ sizeof( V_14 ) ] ;
#endif
F_6 ( & Time , sizeof( Time ) , 0 ) ;
F_7 () ;
F_8 () ;
if ( V_4 -> V_15 != NULL )
F_4 = V_4 -> V_15 ;
else if ( V_4 -> V_16 -> V_15 != NULL )
F_4 = V_4 -> V_16 -> V_15 ;
V_4 -> V_17 ++ ;
if ( ! F_9 ( V_4 ) || F_10 ( V_4 ) ) F_11 ( V_4 ) ;
#ifndef F_5
F_12 ( F_13 ( V_4 ) , V_18 , V_4 -> V_17 , NULL ) ;
#endif
#ifndef F_14
if ( V_4 -> V_19 )
{
F_15 ( V_4 ) ;
V_4 -> V_19 = 0 ;
V_4 -> V_20 ++ ;
}
#endif
for (; ; )
{
V_10 = V_4 -> V_10 ;
switch( V_4 -> V_10 )
{
case V_21 :
V_4 -> V_22 = 1 ;
V_4 -> V_10 = V_23 ;
V_4 -> V_16 -> V_24 . V_25 ++ ;
case V_26 :
case V_23 :
case V_26 | V_23 :
case V_27 | V_23 :
V_4 -> V_28 = 0 ;
if ( F_4 != NULL ) F_4 ( V_4 , V_29 , 1 ) ;
if ( ( V_4 -> V_30 & 0xff00 ) != ( V_2 & 0xff00 ) &&
( V_4 -> V_30 & 0xff00 ) != ( V_3 & 0xff00 ) )
{
F_16 ( V_31 , V_32 ) ;
V_8 = - 1 ;
goto V_33;
}
V_4 -> type = V_23 ;
if ( V_4 -> V_34 == NULL )
{
if ( ( V_5 = F_17 () ) == NULL )
{
V_8 = - 1 ;
goto V_33;
}
if ( ! F_18 ( V_5 , V_35 ) )
{
V_8 = - 1 ;
goto V_33;
}
V_4 -> V_34 = V_5 ;
V_5 = NULL ;
}
if ( ! F_19 ( V_4 ) ) { V_8 = - 1 ; goto V_33; }
if ( ! F_20 ( V_4 , 0 ) ) { V_8 = - 1 ; goto V_33; }
V_4 -> V_10 = V_36 ;
V_4 -> V_16 -> V_24 . V_37 ++ ;
V_4 -> V_38 = 0 ;
memset ( V_4 -> V_39 -> V_40 , 0 , sizeof( V_4 -> V_39 -> V_40 ) ) ;
V_4 -> V_41 -> V_42 = 0 ;
V_4 -> V_43 = 0 ;
break;
#ifndef F_5
case V_44 :
if ( F_21 ( F_22 ( V_4 ) ) )
{
V_4 -> V_39 -> V_45 = 2 ;
V_4 -> V_46 = V_47 ;
F_23 ( F_22 ( V_4 ) ) ;
F_24 ( F_22 ( V_4 ) ) ;
V_8 = - 1 ;
goto V_33;
}
V_4 -> V_10 = V_4 -> V_39 -> V_48 . V_49 ;
break;
case V_50 :
V_8 = F_25 ( F_13 ( V_4 ) ) ;
if ( V_8 < 0 ) goto V_33;
if ( V_8 == 0 )
{
V_4 -> V_39 -> V_45 = 2 ;
V_4 -> V_46 = V_47 ;
F_23 ( F_22 ( V_4 ) ) ;
F_24 ( F_22 ( V_4 ) ) ;
V_8 = - 1 ;
goto V_33;
}
V_4 -> V_10 = V_4 -> V_41 -> V_49 ;
break;
#endif
case V_36 :
case V_51 :
V_4 -> V_52 = 0 ;
F_26 ( V_4 ) ;
F_27 ( V_4 ) ;
V_8 = F_28 ( V_4 ) ;
if ( V_8 <= 0 ) goto V_33;
if ( V_4 -> V_41 -> V_42 )
{
V_4 -> V_10 = V_53 ;
V_4 -> V_39 -> V_48 . V_49 = V_54 ;
}
else
V_4 -> V_10 = V_54 ;
V_4 -> V_38 = 0 ;
#ifndef F_5
if ( ! F_29 ( F_13 ( V_4 ) ) )
{
#endif
if ( V_4 -> V_55 != V_4 -> V_56 )
V_4 -> V_56 = F_30 ( V_4 -> V_55 , V_4 -> V_56 ) ;
#ifndef F_5
}
#endif
break;
case V_54 :
case V_57 :
V_8 = F_31 ( V_4 ) ;
if ( V_8 <= 0 ) goto V_33;
else
{
if ( V_4 -> V_43 )
{
#ifndef F_5
snprintf ( ( char * ) V_13 , sizeof( V_14 ) ,
V_14 ) ;
F_32 ( V_4 , V_12 ,
sizeof( V_12 ) , V_13 ,
sizeof( V_13 ) , NULL , 0 , 0 ) ;
F_12 ( F_13 ( V_4 ) , V_58 ,
sizeof( V_12 ) , V_12 ) ;
#endif
V_4 -> V_10 = V_59 ;
}
else
V_4 -> V_10 = V_60 ;
}
V_4 -> V_38 = 0 ;
break;
case V_60 :
case V_61 :
V_8 = F_33 ( V_4 ) ;
if ( V_8 <= 0 )
goto V_33;
F_15 ( V_4 ) ;
if ( V_4 -> V_41 -> V_42 )
V_4 -> V_10 = V_36 ;
else
V_4 -> V_10 = V_62 ;
V_4 -> V_38 = 0 ;
break;
case V_62 :
case V_63 :
#ifndef F_34
V_8 = F_35 ( V_4 ) ;
if ( V_8 <= 0 ) goto V_33;
if ( V_8 == 2 )
{
V_4 -> V_43 = 1 ;
if ( V_4 -> V_64 )
V_4 -> V_10 = V_65 ;
else
V_4 -> V_10 = V_59 ;
V_4 -> V_38 = 0 ;
break;
}
#endif
if ( ! ( V_4 -> V_39 -> V_48 . V_66 -> V_67 & V_68 ) &&
! ( V_4 -> V_39 -> V_48 . V_66 -> V_69 & V_70 ) )
{
V_8 = F_36 ( V_4 ) ;
if ( V_8 <= 0 ) goto V_33;
#ifndef F_34
if ( V_4 -> V_71 )
V_4 -> V_10 = V_72 ;
else
V_4 -> V_10 = V_73 ;
}
else
{
V_11 = 1 ;
V_4 -> V_10 = V_73 ;
}
#else
}
else
V_11 = 1 ;
V_4 -> V_10 = V_73 ;
#endif
V_4 -> V_38 = 0 ;
break;
case V_73 :
case V_74 :
V_8 = F_37 ( V_4 ) ;
if ( V_8 <= 0 ) goto V_33;
V_4 -> V_10 = V_75 ;
V_4 -> V_38 = 0 ;
if ( ! F_38 ( V_4 ) )
{
V_8 = - 1 ;
goto V_33;
}
break;
case V_75 :
case V_76 :
V_8 = F_39 ( V_4 ) ;
if ( V_8 <= 0 ) goto V_33;
V_4 -> V_10 = V_77 ;
V_4 -> V_38 = 0 ;
break;
case V_77 :
case V_78 :
V_8 = F_40 ( V_4 ) ;
if ( V_8 <= 0 ) goto V_33;
F_15 ( V_4 ) ;
if ( V_4 -> V_39 -> V_48 . V_79 )
V_4 -> V_39 -> V_48 . V_49 = V_80 ;
else
V_4 -> V_39 -> V_48 . V_49 = V_81 ;
V_4 -> V_38 = 0 ;
#ifndef F_5
if ( F_29 ( F_13 ( V_4 ) ) &&
V_10 == V_21 )
V_4 -> V_10 = V_44 ;
else
#endif
V_4 -> V_10 = V_4 -> V_39 -> V_48 . V_49 ;
break;
case V_80 :
case V_82 :
case V_83 :
case V_84 :
F_27 ( V_4 ) ;
V_8 = F_41 ( V_4 ) ;
if ( V_8 <= 0 ) goto V_33;
V_4 -> V_10 = V_81 ;
V_4 -> V_38 = 0 ;
break;
case V_81 :
case V_85 :
F_27 ( V_4 ) ;
V_8 = F_42 ( V_4 ) ;
if ( V_8 <= 0 ) goto V_33;
#ifndef F_5
snprintf ( ( char * ) V_13 , sizeof( V_14 ) ,
V_14 ) ;
F_32 ( V_4 , V_12 ,
sizeof( V_12 ) , V_13 ,
sizeof( V_13 ) , NULL , 0 , 0 ) ;
F_12 ( F_13 ( V_4 ) , V_58 ,
sizeof( V_12 ) , V_12 ) ;
#endif
if ( V_4 -> V_39 -> V_48 . V_79 == 1 )
{
V_4 -> V_10 = V_86 ;
}
else
{
#ifndef F_5
if ( F_29 ( F_13 ( V_4 ) ) )
{
V_4 -> V_41 -> V_49 = V_87 ;
V_4 -> V_10 = V_50 ;
}
else
#endif
V_4 -> V_10 = V_87 ;
V_4 -> V_39 -> V_88 = 0 ;
}
V_4 -> V_38 = 0 ;
break;
case V_86 :
case V_89 :
F_27 ( V_4 ) ;
V_8 = F_43 ( V_4 ) ;
if ( V_8 <= 0 ) goto V_33;
#ifndef F_5
if ( F_29 ( F_13 ( V_4 ) ) )
{
V_4 -> V_41 -> V_49 = V_87 ;
V_4 -> V_10 = V_50 ;
}
else
#endif
V_4 -> V_10 = V_87 ;
V_4 -> V_38 = 0 ;
V_4 -> V_39 -> V_88 = 0 ;
break;
case V_87 :
case V_90 :
if ( ! V_4 -> V_43 )
F_27 ( V_4 ) ;
V_8 = F_44 ( V_4 ,
V_87 , V_90 ) ;
if ( V_8 <= 0 ) goto V_33;
#ifndef F_5
F_12 ( F_13 ( V_4 ) , V_91 , 0 , NULL ) ;
#endif
V_4 -> V_10 = V_92 ;
V_4 -> V_38 = 0 ;
V_4 -> V_93 -> V_94 = V_4 -> V_39 -> V_48 . V_66 ;
#ifdef F_45
V_4 -> V_93 -> V_95 = 0 ;
#else
if ( V_4 -> V_39 -> V_48 . V_96 == NULL )
V_4 -> V_93 -> V_95 = 0 ;
else
V_4 -> V_93 -> V_95 =
V_4 -> V_39 -> V_48 . V_96 -> V_97 ;
#endif
if ( ! V_4 -> V_98 -> V_99 -> V_100 ( V_4 ) )
{
V_8 = - 1 ;
goto V_33;
}
if ( ! V_4 -> V_98 -> V_99 -> V_101 ( V_4 ,
V_102 ) )
{
V_8 = - 1 ;
goto V_33;
}
F_46 ( V_4 , V_103 ) ;
break;
case V_92 :
case V_104 :
if ( ! V_4 -> V_43 )
F_27 ( V_4 ) ;
V_8 = F_47 ( V_4 ,
V_92 , V_104 ,
V_4 -> V_98 -> V_99 -> V_105 ,
V_4 -> V_98 -> V_99 -> V_106 ) ;
if ( V_8 <= 0 ) goto V_33;
V_4 -> V_10 = V_53 ;
V_4 -> V_39 -> V_107 &= ~ V_108 ;
if ( V_4 -> V_43 )
{
V_4 -> V_39 -> V_48 . V_49 = V_27 ;
#ifndef F_5
if ( F_29 ( F_13 ( V_4 ) ) )
{
V_4 -> V_41 -> V_49 = V_4 -> V_39 -> V_48 . V_49 ;
V_4 -> V_39 -> V_48 . V_49 = V_50 ;
}
#endif
if ( V_4 -> V_39 -> V_107 & V_109 )
{
V_4 -> V_10 = V_27 ;
#ifndef F_5
if ( F_29 ( F_13 ( V_4 ) ) )
{
V_4 -> V_41 -> V_49 = V_27 ;
V_4 -> V_10 = V_50 ;
}
#endif
V_4 -> V_39 -> V_107 |= V_108 ;
V_4 -> V_39 -> V_110 = 0 ;
}
}
else
{
#ifndef F_34
if ( V_4 -> V_64 )
V_4 -> V_39 -> V_48 . V_49 = V_65 ;
else
#endif
V_4 -> V_39 -> V_48 . V_49 = V_59 ;
}
V_4 -> V_38 = 0 ;
break;
#ifndef F_34
case V_65 :
case V_111 :
V_8 = F_48 ( V_4 ) ;
if ( V_8 <= 0 ) goto V_33;
V_4 -> V_10 = V_59 ;
V_4 -> V_38 = 0 ;
break;
case V_72 :
case V_112 :
V_8 = F_49 ( V_4 ) ;
if ( V_8 <= 0 ) goto V_33;
V_4 -> V_10 = V_73 ;
V_4 -> V_38 = 0 ;
break;
#endif
case V_59 :
case V_113 :
V_4 -> V_41 -> V_114 = 1 ;
V_8 = F_50 ( V_4 , V_59 ,
V_113 ) ;
if ( V_8 <= 0 ) goto V_33;
F_15 ( V_4 ) ;
if ( V_4 -> V_43 )
V_4 -> V_10 = V_87 ;
else
V_4 -> V_10 = V_27 ;
#ifndef F_5
if ( F_29 ( F_13 ( V_4 ) ) &&
V_10 == V_21 )
{
V_4 -> V_41 -> V_49 = V_4 -> V_10 ;
V_4 -> V_10 = V_50 ;
}
#endif
V_4 -> V_38 = 0 ;
break;
case V_53 :
V_4 -> V_46 = V_115 ;
if ( F_51 ( V_4 -> V_56 ) <= 0 )
{
if ( ! F_52 ( V_4 -> V_56 ) )
{
V_4 -> V_46 = V_116 ;
V_4 -> V_10 = V_4 -> V_39 -> V_48 . V_49 ;
}
V_8 = - 1 ;
goto V_33;
}
V_4 -> V_46 = V_116 ;
V_4 -> V_10 = V_4 -> V_39 -> V_48 . V_49 ;
break;
case V_27 :
F_53 ( V_4 ) ;
#if 0
if (s->init_buf != NULL)
{
BUF_MEM_free(s->init_buf);
s->init_buf=NULL;
}
#endif
if ( ! ( V_4 -> V_39 -> V_107 & V_108 ) )
F_54 ( V_4 ) ;
V_4 -> V_38 = 0 ;
V_4 -> V_22 = 0 ;
V_4 -> V_117 = 0 ;
F_55 ( V_4 , V_118 ) ;
if ( V_4 -> V_43 ) V_4 -> V_16 -> V_24 . V_119 ++ ;
V_8 = 1 ;
V_4 -> V_120 = F_3 ;
V_4 -> V_16 -> V_24 . V_121 ++ ;
if ( F_4 != NULL ) F_4 ( V_4 , V_122 , 1 ) ;
V_4 -> V_41 -> V_123 = 0 ;
V_4 -> V_41 -> V_124 = 0 ;
goto V_33;
default:
F_16 ( V_31 , V_125 ) ;
V_8 = - 1 ;
goto V_33;
}
if ( ! V_4 -> V_39 -> V_48 . V_126 && ! V_11 )
{
if ( V_4 -> V_127 )
{
if ( ( V_8 = F_51 ( V_4 -> V_56 ) ) <= 0 )
goto V_33;
}
if ( ( F_4 != NULL ) && ( V_4 -> V_10 != V_10 ) )
{
V_9 = V_4 -> V_10 ;
V_4 -> V_10 = V_10 ;
F_4 ( V_4 , V_128 , 1 ) ;
V_4 -> V_10 = V_9 ;
}
}
V_11 = 0 ;
}
static int F_33 ( T_2 * V_4 )
{
int V_129 , V_130 , V_131 = 0 ;
unsigned char * V_132 ;
unsigned int V_133 ;
V_129 = V_4 -> V_98 -> V_134 ( V_4 ,
V_60 ,
V_61 ,
- 1 ,
V_4 -> V_135 ,
& V_131 ) ;
if ( ! V_131 ) return ( ( int ) V_129 ) ;
if ( V_4 -> V_39 -> V_48 . V_136 != V_137 )
{
V_4 -> V_41 -> V_42 = 0 ;
V_4 -> V_39 -> V_48 . V_126 = 1 ;
return ( 1 ) ;
}
V_132 = ( unsigned char * ) V_4 -> V_138 ;
if ( ( V_132 [ 0 ] != ( V_4 -> V_30 >> 8 ) ) || ( V_132 [ 1 ] != ( V_4 -> V_30 & 0xff ) ) )
{
F_16 ( V_139 , V_140 ) ;
V_4 -> V_30 = ( V_4 -> V_30 & 0xff00 ) | V_132 [ 1 ] ;
V_130 = V_141 ;
goto V_142;
}
V_132 += 2 ;
V_133 = * ( V_132 ++ ) ;
if ( V_133 > sizeof( V_4 -> V_41 -> V_143 ) )
{
V_130 = V_144 ;
goto V_142;
}
memcpy ( V_4 -> V_41 -> V_143 , V_132 , V_133 ) ;
V_4 -> V_41 -> V_133 = V_133 ;
V_4 -> V_41 -> V_42 = 1 ;
return 1 ;
V_142:
F_56 ( V_4 , V_145 , V_130 ) ;
return - 1 ;
}
int F_42 ( T_2 * V_4 )
{
unsigned char * V_146 , * V_147 ;
int V_129 ;
unsigned long V_148 ;
#ifndef F_57
unsigned char * V_149 ;
T_4 * V_150 = NULL ;
#endif
#ifndef F_58
T_5 V_151 ;
#endif
#ifndef F_59
T_6 * V_152 = NULL ;
const T_7 * V_153 = NULL ;
T_4 * V_154 = NULL ;
unsigned char * V_155 = NULL ;
int V_156 = 0 ;
T_8 * V_157 = NULL ;
#endif
if ( V_4 -> V_10 == V_81 )
{
V_147 = ( unsigned char * ) V_4 -> V_34 -> V_132 ;
V_146 = & ( V_147 [ V_158 ] ) ;
V_148 = V_4 -> V_39 -> V_48 . V_66 -> V_69 ;
if ( 0 ) {}
#ifndef F_57
else if ( V_148 & V_159 )
{
T_9 * V_160 ;
unsigned char V_161 [ V_162 ] ;
if ( V_4 -> V_93 -> V_163 -> V_164 != NULL )
V_160 = V_4 -> V_93 -> V_163 -> V_164 ;
else
{
V_150 = F_60 ( V_4 -> V_93 -> V_163 -> V_165 [ V_166 ] . V_167 ) ;
if ( ( V_150 == NULL ) ||
( V_150 -> type != V_168 ) ||
( V_150 -> V_150 . V_160 == NULL ) )
{
F_16 ( V_169 , V_32 ) ;
goto V_170;
}
V_160 = V_150 -> V_150 . V_160 ;
F_61 ( V_150 ) ;
}
V_161 [ 0 ] = V_4 -> V_171 >> 8 ;
V_161 [ 1 ] = V_4 -> V_171 & 0xff ;
if ( F_62 ( & ( V_161 [ 2 ] ) , sizeof V_161 - 2 ) <= 0 )
goto V_170;
V_4 -> V_93 -> V_172 = sizeof V_161 ;
V_149 = V_146 ;
if ( V_4 -> V_30 > V_173 )
V_146 += 2 ;
V_129 = F_63 ( sizeof V_161 ,
V_161 , V_146 , V_160 , V_174 ) ;
#ifdef F_64
if ( V_4 -> V_175 & V_176 ) V_146 [ 1 ] ++ ;
if ( V_4 -> V_175 & V_177 ) V_161 [ 0 ] = 0x70 ;
#endif
if ( V_129 <= 0 )
{
F_16 ( V_169 , V_178 ) ;
goto V_170;
}
if ( V_4 -> V_30 > V_173 )
{
F_65 ( V_129 , V_149 ) ;
V_129 += 2 ;
}
V_4 -> V_93 -> V_172 =
V_4 -> V_98 -> V_99 -> V_179 ( V_4 ,
V_4 -> V_93 -> V_180 ,
V_161 , sizeof V_161 ) ;
F_66 ( V_161 , sizeof V_161 ) ;
}
#endif
#ifndef F_58
else if ( V_148 & V_181 )
{
T_10 V_182 ;
T_11 * V_183 = V_4 -> V_183 ;
T_12 * V_184 ;
T_12 V_185 , * V_186 = NULL ;
T_13 V_187 ;
const T_14 * V_188 = NULL ;
unsigned char V_189 [ V_190 ] ;
unsigned char V_161 [ V_162 ] ;
unsigned char V_191 [ V_162
+ V_190 ] ;
int V_192 , V_193 = sizeof( V_191 ) ;
F_67 ( & V_187 ) ;
#ifdef F_68
printf ( L_1 ,
V_148 , V_181 ) ;
#endif
V_186 = NULL ;
#ifdef F_69
if ( F_69 ) V_186 = & V_185 ;
#endif
V_182 = F_70 ( V_183 , & V_184 , V_186 ,
& V_151 ) ;
V_188 = F_71 ( V_183 -> V_194 ) ;
if ( V_188 == NULL )
goto V_170;
#ifdef F_68
{
printf ( L_2 , V_182 ) ;
if ( V_182 && V_151 . V_195 )
printf ( L_3 , V_151 . V_195 ) ;
}
#endif
if ( V_182 )
{
F_56 ( V_4 , V_145 ,
V_196 ) ;
F_16 ( V_169 ,
V_151 . V_197 ) ;
goto V_170;
}
F_65 ( V_184 -> V_198 , V_146 ) ;
memcpy ( V_146 , V_184 -> V_132 , V_184 -> V_198 ) ;
V_146 += V_184 -> V_198 ;
V_129 = V_184 -> V_198 + 2 ;
if ( V_186 && V_186 -> V_198 )
{
F_65 ( V_186 -> V_198 , V_146 ) ;
memcpy ( V_146 , V_186 -> V_132 , V_186 -> V_198 ) ;
V_146 += V_186 -> V_198 ;
V_129 += V_186 -> V_198 + 2 ;
free ( V_186 -> V_132 ) ;
V_186 -> V_132 = NULL ;
V_186 -> V_198 = 0 ;
}
else
{
F_65 ( 0 , V_146 ) ;
V_129 += 2 ;
}
if ( F_62 ( V_161 , sizeof V_161 ) <= 0 )
goto V_170;
memset ( V_189 , 0 , sizeof V_189 ) ;
F_72 ( & V_187 , V_188 , NULL ,
V_183 -> V_199 , V_189 ) ;
F_73 ( & V_187 , V_191 , & V_193 , V_161 ,
sizeof V_161 ) ;
F_74 ( & V_187 , & ( V_191 [ V_193 ] ) , & V_192 ) ;
V_193 += V_192 ;
if ( V_193 > ( int ) sizeof V_191 )
{
F_16 ( V_169 , V_32 ) ;
goto V_170;
}
F_75 ( & V_187 ) ;
F_65 ( V_193 , V_146 ) ;
memcpy ( V_146 , V_191 , V_193 ) ;
V_146 += V_193 ;
V_129 += V_193 + 2 ;
V_4 -> V_93 -> V_172 =
V_4 -> V_98 -> V_99 -> V_179 ( V_4 ,
V_4 -> V_93 -> V_180 ,
V_161 , sizeof V_161 ) ;
F_66 ( V_161 , sizeof V_161 ) ;
F_66 ( V_191 , V_193 ) ;
}
#endif
#ifndef F_76
else if ( V_148 & ( V_200 | V_201 | V_202 ) )
{
T_15 * V_203 , * V_204 ;
if ( V_4 -> V_93 -> V_163 -> V_205 != NULL )
V_203 = V_4 -> V_93 -> V_163 -> V_205 ;
else
{
F_56 ( V_4 , V_145 , V_196 ) ;
F_16 ( V_169 , V_206 ) ;
goto V_170;
}
if ( ( V_204 = F_77 ( V_203 ) ) == NULL )
{
F_16 ( V_169 , V_207 ) ;
goto V_170;
}
if ( ! F_78 ( V_204 ) )
{
F_16 ( V_169 , V_207 ) ;
goto V_170;
}
V_129 = F_79 ( V_146 , V_203 -> V_208 , V_204 ) ;
if ( V_129 <= 0 )
{
F_16 ( V_169 , V_207 ) ;
goto V_170;
}
V_4 -> V_93 -> V_172 =
V_4 -> V_98 -> V_99 -> V_179 ( V_4 ,
V_4 -> V_93 -> V_180 , V_146 , V_129 ) ;
memset ( V_146 , 0 , V_129 ) ;
V_129 = F_80 ( V_204 -> V_208 ) ;
F_65 ( V_129 , V_146 ) ;
F_81 ( V_204 -> V_208 , V_146 ) ;
V_129 += 2 ;
F_82 ( V_204 ) ;
}
#endif
#ifndef F_59
else if ( V_148 & ( V_209 | V_210 | V_211 ) )
{
const T_16 * V_212 = NULL ;
T_6 * V_213 ;
int V_214 = 0 ;
int V_215 = 0 ;
if ( ( V_148 & ( V_210 | V_211 ) ) && ( V_4 -> V_216 != NULL ) )
{
}
if ( V_4 -> V_93 -> V_163 -> V_217 != NULL )
{
V_213 = V_4 -> V_93 -> V_163 -> V_217 ;
}
else
{
V_154 = F_60 ( V_4 -> V_93 -> \
V_163 -> V_165 [ V_218 ] . V_167 ) ;
if ( ( V_154 == NULL ) ||
( V_154 -> type != V_219 ) ||
( V_154 -> V_150 . V_220 == NULL ) )
{
F_16 ( V_169 ,
V_32 ) ;
goto V_170;
}
V_213 = V_154 -> V_150 . V_220 ;
}
V_212 = F_83 ( V_213 ) ;
V_153 = F_84 ( V_213 ) ;
if ( ( V_212 == NULL ) || ( V_153 == NULL ) )
{
F_16 ( V_169 ,
V_32 ) ;
goto V_170;
}
if ( ( V_152 = F_85 () ) == NULL )
{
F_16 ( V_169 , V_221 ) ;
goto V_170;
}
if ( ! F_86 ( V_152 , V_212 ) )
{
F_16 ( V_169 , V_222 ) ;
goto V_170;
}
if ( V_214 )
{
const T_17 * V_223 ;
V_213 = V_4 -> V_216 -> V_199 -> V_224 -> V_150 . V_220 ;
V_223 = F_87 ( V_213 ) ;
if ( V_223 == NULL )
{
F_16 ( V_169 , V_221 ) ;
goto V_170;
}
if ( ! F_88 ( V_152 , V_223 ) )
{
F_16 ( V_169 , V_222 ) ;
goto V_170;
}
}
else
{
if ( ! ( F_89 ( V_152 ) ) )
{
F_16 ( V_169 , V_225 ) ;
goto V_170;
}
}
V_215 = F_90 ( V_212 ) ;
if ( V_215 <= 0 )
{
F_16 ( V_169 ,
V_225 ) ;
goto V_170;
}
V_129 = F_91 ( V_146 , ( V_215 + 7 ) / 8 , V_153 , V_152 , NULL ) ;
if ( V_129 <= 0 )
{
F_16 ( V_169 ,
V_225 ) ;
goto V_170;
}
V_4 -> V_93 -> V_172 = V_4 -> V_98 -> V_99 \
-> V_179 ( V_4 ,
V_4 -> V_93 -> V_180 ,
V_146 , V_129 ) ;
memset ( V_146 , 0 , V_129 ) ;
if ( V_214 )
{
V_129 = 0 ;
}
else
{
V_156 =
F_92 ( V_212 ,
F_84 ( V_152 ) ,
V_226 ,
NULL , 0 , NULL ) ;
V_155 = ( unsigned char * )
F_93 ( V_156 *
sizeof( unsigned char ) ) ;
V_157 = F_94 () ;
if ( ( V_155 == NULL ) ||
( V_157 == NULL ) )
{
F_16 ( V_169 , V_221 ) ;
goto V_170;
}
V_129 = F_92 ( V_212 ,
F_84 ( V_152 ) ,
V_226 ,
V_155 , V_156 , V_157 ) ;
* V_146 = V_129 ;
V_146 += 1 ;
memcpy ( ( unsigned char * ) V_146 , V_155 , V_129 ) ;
V_129 += 1 ;
}
F_95 ( V_157 ) ;
if ( V_155 != NULL ) F_96 ( V_155 ) ;
if ( V_152 != NULL )
F_97 ( V_152 ) ;
F_61 ( V_154 ) ;
}
#endif
#ifndef F_98
else if ( V_148 & V_70 )
{
char V_227 [ V_228 ] ;
unsigned char * V_229 = NULL ;
unsigned char V_230 [ V_231 * 2 + 4 ] ;
unsigned int V_232 = 0 , V_233 = 0 ;
int V_234 = 1 ;
V_129 = 0 ;
if ( V_4 -> V_235 == NULL )
{
F_16 ( V_169 ,
V_236 ) ;
goto V_170;
}
V_233 = V_4 -> V_235 ( V_4 , V_4 -> V_16 -> V_237 ,
V_227 , V_228 ,
V_230 , sizeof( V_230 ) ) ;
if ( V_233 > V_231 )
{
F_16 ( V_169 ,
V_32 ) ;
goto V_234;
}
else if ( V_233 == 0 )
{
F_16 ( V_169 ,
V_238 ) ;
goto V_234;
}
V_232 = 2 + V_233 + 2 + V_233 ;
V_229 = V_230 ;
memmove ( V_230 + V_233 + 4 , V_230 , V_233 ) ;
F_65 ( V_233 , V_229 ) ;
memset ( V_229 , 0 , V_233 ) ;
V_229 += V_233 ;
F_65 ( V_233 , V_229 ) ;
if ( V_4 -> V_93 -> V_237 != NULL )
F_96 ( V_4 -> V_93 -> V_237 ) ;
V_4 -> V_93 -> V_237 = F_99 ( V_4 -> V_16 -> V_237 ) ;
if ( V_4 -> V_16 -> V_237 != NULL &&
V_4 -> V_93 -> V_237 == NULL )
{
F_16 ( V_169 ,
V_221 ) ;
goto V_234;
}
if ( V_4 -> V_93 -> V_239 != NULL )
F_96 ( V_4 -> V_93 -> V_239 ) ;
V_4 -> V_93 -> V_239 = F_99 ( V_227 ) ;
if ( V_4 -> V_93 -> V_239 == NULL )
{
F_16 ( V_169 ,
V_221 ) ;
goto V_234;
}
V_4 -> V_93 -> V_172 =
V_4 -> V_98 -> V_99 -> V_179 ( V_4 ,
V_4 -> V_93 -> V_180 ,
V_230 , V_232 ) ;
V_129 = strlen ( V_227 ) ;
F_65 ( V_129 , V_146 ) ;
memcpy ( V_146 , V_227 , V_129 ) ;
V_129 += 2 ;
V_234 = 0 ;
V_234:
F_66 ( V_227 , V_228 ) ;
F_66 ( V_230 , sizeof( V_230 ) ) ;
if ( V_234 != 0 )
{
F_56 ( V_4 , V_145 , V_196 ) ;
goto V_170;
}
}
#endif
else
{
F_56 ( V_4 , V_145 , V_196 ) ;
F_16 ( V_169 , V_32 ) ;
goto V_170;
}
V_147 = F_100 ( V_4 , V_147 ,
V_240 , V_129 , 0 , V_129 ) ;
V_4 -> V_10 = V_85 ;
V_4 -> V_38 = V_129 + V_158 ;
V_4 -> V_241 = 0 ;
F_101 ( V_4 , 0 ) ;
}
return ( F_102 ( V_4 , V_242 ) ) ;
V_170:
#ifndef F_59
F_95 ( V_157 ) ;
if ( V_155 != NULL ) F_96 ( V_155 ) ;
if ( V_152 != NULL )
F_97 ( V_152 ) ;
F_61 ( V_154 ) ;
#endif
return ( - 1 ) ;
}
int F_43 ( T_2 * V_4 )
{
unsigned char * V_146 , * V_147 ;
unsigned char V_132 [ V_243 + V_244 ] ;
T_4 * V_150 ;
#ifndef F_57
unsigned V_245 = 0 ;
#endif
unsigned long V_129 ;
#if ! F_103 ( V_246 ) || ! F_103 ( V_247 )
int V_248 ;
#endif
if ( V_4 -> V_10 == V_86 )
{
V_147 = ( unsigned char * ) V_4 -> V_34 -> V_132 ;
V_146 = & ( V_147 [ V_158 ] ) ;
V_150 = V_4 -> V_216 -> V_199 -> V_224 ;
V_4 -> V_98 -> V_99 -> V_249 ( V_4 ,
V_250 ,
& ( V_132 [ V_243 ] ) ) ;
#ifndef F_57
if ( V_150 -> type == V_168 )
{
V_4 -> V_98 -> V_99 -> V_249 ( V_4 ,
V_251 ,
& ( V_132 [ 0 ] ) ) ;
if ( F_104 ( V_252 , V_132 ,
V_243 + V_244 ,
& ( V_146 [ 2 ] ) , & V_245 , V_150 -> V_150 . V_160 ) <= 0 )
{
F_16 ( V_253 , V_254 ) ;
goto V_170;
}
F_65 ( V_245 , V_146 ) ;
V_129 = V_245 + 2 ;
}
else
#endif
#ifndef V_246
if ( V_150 -> type == V_255 )
{
if ( ! F_105 ( V_150 -> V_256 ,
& ( V_132 [ V_243 ] ) ,
V_244 , & ( V_146 [ 2 ] ) ,
( unsigned int * ) & V_248 , V_150 -> V_150 . V_257 ) )
{
F_16 ( V_253 , V_258 ) ;
goto V_170;
}
F_65 ( V_248 , V_146 ) ;
V_129 = V_248 + 2 ;
}
else
#endif
#ifndef V_247
if ( V_150 -> type == V_219 )
{
if ( ! F_106 ( V_150 -> V_256 ,
& ( V_132 [ V_243 ] ) ,
V_244 , & ( V_146 [ 2 ] ) ,
( unsigned int * ) & V_248 , V_150 -> V_150 . V_220 ) )
{
F_16 ( V_253 ,
V_259 ) ;
goto V_170;
}
F_65 ( V_248 , V_146 ) ;
V_129 = V_248 + 2 ;
}
else
#endif
{
F_16 ( V_253 , V_32 ) ;
goto V_170;
}
V_147 = F_100 ( V_4 , V_147 ,
V_260 , V_129 , 0 , V_129 ) ;
V_4 -> V_38 = ( int ) V_129 + V_158 ;
V_4 -> V_241 = 0 ;
F_101 ( V_4 , 0 ) ;
V_4 -> V_10 = V_89 ;
}
return ( F_102 ( V_4 , V_242 ) ) ;
V_170:
return ( - 1 ) ;
}
int F_41 ( T_2 * V_4 )
{
T_18 * V_167 = NULL ;
T_4 * V_150 = NULL ;
int V_261 ;
unsigned long V_262 ;
if ( V_4 -> V_10 == V_80 )
{
if ( ( V_4 -> V_216 == NULL ) ||
( V_4 -> V_216 -> V_199 -> V_167 == NULL ) ||
( V_4 -> V_216 -> V_199 -> V_224 == NULL ) )
V_4 -> V_10 = V_82 ;
else
V_4 -> V_10 = V_83 ;
}
if ( V_4 -> V_10 == V_82 )
{
V_261 = 0 ;
V_261 = F_107 ( V_4 , & V_167 , & V_150 ) ;
if ( V_261 < 0 )
{
V_4 -> V_46 = V_263 ;
return ( - 1 ) ;
}
V_4 -> V_46 = V_116 ;
if ( ( V_261 == 1 ) && ( V_150 != NULL ) && ( V_167 != NULL ) )
{
V_4 -> V_10 = V_82 ;
if ( ! F_108 ( V_4 , V_167 ) ||
! F_109 ( V_4 , V_150 ) )
V_261 = 0 ;
}
else if ( V_261 == 1 )
{
V_261 = 0 ;
F_16 ( V_264 , V_265 ) ;
}
if ( V_167 != NULL ) F_110 ( V_167 ) ;
if ( V_150 != NULL ) F_61 ( V_150 ) ;
if ( V_261 == 0 )
{
if ( V_4 -> V_30 == V_173 )
{
V_4 -> V_39 -> V_48 . V_79 = 0 ;
F_56 ( V_4 , V_266 , V_267 ) ;
return ( 1 ) ;
}
else
{
V_4 -> V_39 -> V_48 . V_79 = 2 ;
}
}
V_4 -> V_10 = V_83 ;
}
if ( V_4 -> V_10 == V_83 )
{
V_4 -> V_10 = V_84 ;
V_262 = F_111 ( V_4 ,
( V_4 -> V_39 -> V_48 . V_79 == 2 ) ? NULL : V_4 -> V_216 -> V_199 -> V_167 ) ;
V_4 -> V_38 = ( int ) V_262 ;
V_4 -> V_241 = 0 ;
F_101 ( V_4 , 0 ) ;
}
return ( F_102 ( V_4 , V_242 ) ) ;
}
