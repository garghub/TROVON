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
T_3 * V_10 ;
unsigned long V_11 , Time = time ( NULL ) ;
void (* F_6)( const T_2 * V_12 , int type , int V_13 ) = NULL ;
long V_14 ;
int V_15 = - 1 ;
int V_16 , V_17 , V_18 = 0 ;
F_7 ( & Time , sizeof( Time ) , 0 ) ;
F_8 () ;
F_9 () ;
if ( V_9 -> V_19 != NULL )
F_6 = V_9 -> V_19 ;
else if ( V_9 -> V_20 -> V_19 != NULL )
F_6 = V_9 -> V_20 -> V_19 ;
V_9 -> V_21 ++ ;
if ( ! F_10 ( V_9 ) || F_11 ( V_9 ) ) F_12 ( V_9 ) ;
if ( V_9 -> V_22 == NULL )
{
F_13 ( V_23 , V_24 ) ;
return ( - 1 ) ;
}
for (; ; )
{
V_17 = V_9 -> V_17 ;
switch ( V_9 -> V_17 )
{
case V_25 :
V_9 -> V_26 = 1 ;
case V_27 :
case V_28 :
case V_27 | V_28 :
case V_29 | V_28 :
V_9 -> V_30 = 1 ;
if ( F_6 != NULL ) F_6 ( V_9 , V_31 , 1 ) ;
if ( ( V_9 -> V_32 & 0xff00 ) != ( V_2 & 0xff00 ) )
{
F_13 ( V_23 , V_33 ) ;
return - 1 ;
}
V_9 -> type = V_28 ;
if ( V_9 -> V_34 == NULL )
{
if ( ( V_10 = F_14 () ) == NULL )
{
V_15 = - 1 ;
goto V_35;
}
if ( ! F_15 ( V_10 , V_36 ) )
{
V_15 = - 1 ;
goto V_35;
}
V_9 -> V_34 = V_10 ;
}
if ( ! F_16 ( V_9 ) )
{
V_15 = - 1 ;
goto V_35;
}
V_9 -> V_37 = 0 ;
if ( V_9 -> V_17 != V_25 )
{
if ( ! F_17 ( V_9 , 1 ) ) { V_15 = - 1 ; goto V_35; }
F_18 ( V_9 ) ;
V_9 -> V_17 = V_38 ;
V_9 -> V_20 -> V_39 . V_40 ++ ;
}
else
{
V_9 -> V_20 -> V_39 . V_41 ++ ;
V_9 -> V_17 = V_42 ;
}
if ( ( F_19 ( V_9 ) & V_43 ) )
V_9 -> V_44 -> V_45 = 1 ;
else
V_9 -> V_44 -> V_45 = 0 ;
break;
case V_42 :
case V_46 :
V_9 -> V_47 = 0 ;
V_15 = F_20 ( V_9 ) ;
if ( V_15 <= 0 ) goto V_35;
V_9 -> V_48 -> V_49 . V_50 = V_51 ;
V_9 -> V_17 = V_52 ;
V_9 -> V_37 = 0 ;
F_18 ( V_9 ) ;
break;
case V_51 :
V_9 -> V_17 = V_29 ;
break;
case V_38 :
case V_53 :
case V_54 :
V_9 -> V_47 = 0 ;
V_15 = F_21 ( V_9 ) ;
if ( V_15 <= 0 ) goto V_35;
V_9 -> V_26 = 2 ;
if ( V_9 -> V_44 -> V_45 )
V_9 -> V_17 = V_55 ;
else
V_9 -> V_17 = V_56 ;
V_9 -> V_37 = 0 ;
break;
case V_55 :
case V_57 :
V_15 = F_22 ( V_9 ) ;
if ( V_15 <= 0 ) goto V_35;
V_9 -> V_44 -> V_45 = 0 ;
V_9 -> V_17 = V_52 ;
V_9 -> V_48 -> V_49 . V_50 = V_38 ;
break;
case V_56 :
case V_58 :
V_15 = F_23 ( V_9 ) ;
if ( V_15 <= 0 ) goto V_35;
if ( V_9 -> V_59 )
V_9 -> V_17 = V_60 ;
else
V_9 -> V_17 = V_61 ;
V_9 -> V_37 = 0 ;
break;
case V_61 :
case V_62 :
if ( ! ( V_9 -> V_48 -> V_49 . V_63 -> V_64 & V_65 ) )
{
V_15 = F_24 ( V_9 ) ;
if ( V_15 <= 0 ) goto V_35;
}
else
V_18 = 1 ;
V_9 -> V_17 = V_66 ;
V_9 -> V_37 = 0 ;
break;
case V_66 :
case V_67 :
V_11 = V_9 -> V_48 -> V_49 . V_63 -> V_64 ;
if ( ( V_9 -> V_68 & V_69 )
#ifndef F_25
&& ! ( V_11 & V_70 )
#endif
)
V_9 -> V_48 -> V_49 . V_71 = 1 ;
else
V_9 -> V_48 -> V_49 . V_71 = 0 ;
if ( V_9 -> V_48 -> V_49 . V_71
|| ( V_11 & ( V_72 | V_73 ) )
|| ( ( V_11 & V_74 )
&& ( V_9 -> V_22 -> V_75 [ V_76 ] . V_77 == NULL
|| ( F_26 ( V_9 -> V_48 -> V_49 . V_63 )
&& F_27 ( V_9 -> V_22 -> V_75 [ V_76 ] . V_77 ) * 8 > F_28 ( V_9 -> V_48 -> V_49 . V_63 )
)
)
)
)
{
V_15 = F_29 ( V_9 ) ;
if ( V_15 <= 0 ) goto V_35;
}
else
V_18 = 1 ;
V_9 -> V_17 = V_78 ;
V_9 -> V_37 = 0 ;
break;
case V_78 :
case V_79 :
if (
! ( V_9 -> V_80 & V_81 ) ||
( ( V_9 -> V_82 -> V_83 != NULL ) &&
( V_9 -> V_80 & V_84 ) ) ||
( ( V_9 -> V_48 -> V_49 . V_63 -> V_64 & V_65 ) &&
! ( V_9 -> V_80 & V_85 ) ) ||
( V_9 -> V_48 -> V_49 . V_63 -> V_64 & V_86 ) )
{
V_18 = 1 ;
V_9 -> V_48 -> V_49 . V_87 = 0 ;
V_9 -> V_17 = V_88 ;
}
else
{
V_9 -> V_48 -> V_49 . V_87 = 1 ;
V_15 = F_30 ( V_9 ) ;
if ( V_15 <= 0 ) goto V_35;
#ifndef F_31
V_9 -> V_17 = V_88 ;
#else
V_9 -> V_17 = V_52 ;
V_9 -> V_48 -> V_49 . V_50 = V_89 ;
#endif
V_9 -> V_37 = 0 ;
}
break;
case V_88 :
case V_90 :
V_15 = F_32 ( V_9 ) ;
if ( V_15 <= 0 ) goto V_35;
V_9 -> V_48 -> V_49 . V_50 = V_89 ;
V_9 -> V_17 = V_52 ;
V_9 -> V_37 = 0 ;
break;
case V_52 :
V_14 = F_33 ( V_9 -> V_91 , V_92 , 0 , NULL ) ;
if ( V_14 > 0 )
{
V_9 -> V_93 = V_94 ;
V_14 = F_34 ( V_9 -> V_91 ) ;
if ( V_14 <= 0 ) { V_15 = - 1 ; goto V_35; }
V_9 -> V_93 = V_95 ;
}
V_9 -> V_17 = V_9 -> V_48 -> V_49 . V_50 ;
break;
case V_89 :
case V_96 :
V_15 = F_35 ( V_9 ) ;
if ( V_15 <= 0 )
goto V_35;
if ( V_15 == 2 )
V_9 -> V_17 = V_54 ;
else {
V_15 = F_36 ( V_9 ) ;
if ( V_15 <= 0 ) goto V_35;
V_9 -> V_37 = 0 ;
V_9 -> V_17 = V_97 ;
}
break;
case V_97 :
case V_98 :
V_15 = F_37 ( V_9 ) ;
if ( V_15 <= 0 ) goto V_35;
V_9 -> V_17 = V_99 ;
V_9 -> V_37 = 0 ;
V_9 -> V_100 -> V_101 -> V_102 ( V_9 ,
& ( V_9 -> V_48 -> V_103 ) ,
& ( V_9 -> V_48 -> V_49 . V_104 [ 0 ] ) ) ;
V_9 -> V_100 -> V_101 -> V_102 ( V_9 ,
& ( V_9 -> V_48 -> V_105 ) ,
& ( V_9 -> V_48 -> V_49 . V_104 [ V_106 ] ) ) ;
break;
case V_99 :
case V_107 :
V_15 = F_38 ( V_9 ) ;
if ( V_15 <= 0 ) goto V_35;
V_9 -> V_17 = V_108 ;
V_9 -> V_37 = 0 ;
break;
case V_108 :
case V_109 :
V_15 = F_39 ( V_9 , V_108 ,
V_109 ) ;
if ( V_15 <= 0 ) goto V_35;
if ( V_9 -> V_59 )
V_9 -> V_17 = V_29 ;
else
V_9 -> V_17 = V_60 ;
V_9 -> V_37 = 0 ;
break;
case V_60 :
case V_110 :
V_9 -> V_82 -> V_111 = V_9 -> V_48 -> V_49 . V_63 ;
if ( ! V_9 -> V_100 -> V_101 -> V_112 ( V_9 ) )
{ V_15 = - 1 ; goto V_35; }
V_15 = F_40 ( V_9 ,
V_60 , V_110 ) ;
if ( V_15 <= 0 ) goto V_35;
V_9 -> V_17 = V_113 ;
V_9 -> V_37 = 0 ;
if ( ! V_9 -> V_100 -> V_101 -> V_114 ( V_9 ,
V_115 ) )
{
V_15 = - 1 ;
goto V_35;
}
F_41 ( V_9 , V_116 ) ;
break;
case V_113 :
case V_117 :
V_15 = F_42 ( V_9 ,
V_113 , V_117 ,
V_9 -> V_100 -> V_101 -> V_118 ,
V_9 -> V_100 -> V_101 -> V_119 ) ;
if ( V_15 <= 0 ) goto V_35;
V_9 -> V_17 = V_52 ;
if ( V_9 -> V_59 )
V_9 -> V_48 -> V_49 . V_50 = V_108 ;
else
V_9 -> V_48 -> V_49 . V_50 = V_29 ;
V_9 -> V_37 = 0 ;
break;
case V_29 :
F_43 ( V_9 ) ;
#if 0
BUF_MEM_free(s->init_buf);
s->init_buf=NULL;
#endif
F_44 ( V_9 ) ;
V_9 -> V_37 = 0 ;
if ( V_9 -> V_26 == 2 )
{
V_9 -> V_26 = 0 ;
F_45 ( V_9 , V_120 ) ;
V_9 -> V_20 -> V_39 . V_121 ++ ;
V_9 -> V_122 = V_7 ;
if ( F_6 != NULL ) F_6 ( V_9 , V_123 , 1 ) ;
}
V_15 = 1 ;
V_9 -> V_44 -> V_124 = 0 ;
V_9 -> V_44 -> V_125 = 0 ;
goto V_35;
default:
F_13 ( V_23 , V_126 ) ;
V_15 = - 1 ;
goto V_35;
}
if ( ! V_9 -> V_48 -> V_49 . V_127 && ! V_18 )
{
if ( V_9 -> V_128 )
{
if ( ( V_15 = F_34 ( V_9 -> V_91 ) ) <= 0 )
goto V_35;
}
if ( ( F_6 != NULL ) && ( V_9 -> V_17 != V_17 ) )
{
V_16 = V_9 -> V_17 ;
V_9 -> V_17 = V_17 ;
F_6 ( V_9 , V_129 , 1 ) ;
V_9 -> V_17 = V_16 ;
}
}
V_18 = 0 ;
}
V_35:
V_9 -> V_21 -- ;
if ( F_6 != NULL )
F_6 ( V_9 , V_130 , V_15 ) ;
return ( V_15 ) ;
}
int F_20 ( T_2 * V_9 )
{
unsigned char * V_131 ;
if ( V_9 -> V_17 == V_42 )
{
V_131 = ( unsigned char * ) V_9 -> V_34 -> V_132 ;
V_131 = F_46 ( V_9 , V_131 , V_133 , 0 , 0 , 0 ) ;
V_9 -> V_17 = V_46 ;
V_9 -> V_37 = V_134 ;
V_9 -> V_135 = 0 ;
}
return ( F_47 ( V_9 , V_136 ) ) ;
}
int F_22 ( T_2 * V_9 )
{
unsigned int V_137 ;
unsigned char * V_138 , * V_10 , * V_131 ;
if ( V_9 -> V_17 == V_55 )
{
V_10 = ( unsigned char * ) V_9 -> V_34 -> V_132 ;
V_138 = V_131 = & ( V_10 [ V_134 ] ) ;
* ( V_131 ++ ) = V_9 -> V_32 >> 8 ;
* ( V_131 ++ ) = V_9 -> V_32 & 0xFF ;
* ( V_131 ++ ) = ( unsigned char ) V_9 -> V_44 -> V_139 ;
if ( V_9 -> V_20 -> V_140 != NULL &&
V_9 -> V_20 -> V_140 ( V_9 , V_9 -> V_44 -> V_141 ,
& ( V_9 -> V_44 -> V_139 ) ) == 0 )
{
F_13 ( V_142 , V_33 ) ;
return 0 ;
}
memcpy ( V_131 , V_9 -> V_44 -> V_141 , V_9 -> V_44 -> V_139 ) ;
V_131 += V_9 -> V_44 -> V_139 ;
V_137 = V_131 - V_138 ;
F_46 ( V_9 , V_10 ,
V_143 , V_137 , 0 , V_137 ) ;
V_9 -> V_17 = V_57 ;
V_9 -> V_37 = V_131 - V_10 ;
V_9 -> V_135 = 0 ;
F_48 ( V_9 , 0 ) ;
}
return ( F_47 ( V_9 , V_136 ) ) ;
}
int F_23 ( T_2 * V_9 )
{
unsigned char * V_10 ;
unsigned char * V_131 , * V_144 ;
int V_145 , V_146 ;
unsigned long V_11 , Time ;
if ( V_9 -> V_17 == V_56 )
{
V_10 = ( unsigned char * ) V_9 -> V_34 -> V_132 ;
V_131 = V_9 -> V_48 -> V_147 ;
Time = time ( NULL ) ;
F_49 ( Time , V_131 ) ;
F_50 ( V_131 , V_148 - sizeof( Time ) ) ;
V_144 = V_131 = & ( V_10 [ V_134 ] ) ;
* ( V_131 ++ ) = V_9 -> V_32 >> 8 ;
* ( V_131 ++ ) = V_9 -> V_32 & 0xff ;
memcpy ( V_131 , V_9 -> V_48 -> V_147 , V_148 ) ;
V_131 += V_148 ;
if ( ! ( V_9 -> V_20 -> V_149 & V_120 ) )
V_9 -> V_82 -> V_150 = 0 ;
V_146 = V_9 -> V_82 -> V_150 ;
if ( V_146 > sizeof V_9 -> V_82 -> V_151 )
{
F_13 ( V_152 , V_33 ) ;
return - 1 ;
}
* ( V_131 ++ ) = V_146 ;
memcpy ( V_131 , V_9 -> V_82 -> V_151 , V_146 ) ;
V_131 += V_146 ;
V_145 = F_51 ( V_9 -> V_48 -> V_49 . V_63 , V_131 ) ;
V_131 += V_145 ;
if ( V_9 -> V_48 -> V_49 . V_153 == NULL )
* ( V_131 ++ ) = 0 ;
else
* ( V_131 ++ ) = V_9 -> V_48 -> V_49 . V_153 -> V_154 ;
V_11 = ( V_131 - V_144 ) ;
V_144 = V_10 ;
V_144 = F_46 ( V_9 , V_144 , V_155 , V_11 , 0 , V_11 ) ;
V_9 -> V_17 = V_156 ;
V_9 -> V_37 = V_131 - V_10 ;
V_9 -> V_135 = 0 ;
F_48 ( V_9 , 0 ) ;
}
return ( F_47 ( V_9 , V_136 ) ) ;
}
int F_32 ( T_2 * V_9 )
{
unsigned char * V_131 ;
if ( V_9 -> V_17 == V_88 )
{
V_131 = ( unsigned char * ) V_9 -> V_34 -> V_132 ;
V_131 = F_46 ( V_9 , V_131 , V_157 , 0 , 0 , 0 ) ;
V_9 -> V_17 = V_90 ;
V_9 -> V_37 = V_134 ;
V_9 -> V_135 = 0 ;
F_48 ( V_9 , 0 ) ;
}
return ( F_47 ( V_9 , V_136 ) ) ;
}
int F_29 ( T_2 * V_9 )
{
#ifndef F_52
unsigned char * V_158 ;
int V_159 , V_160 ;
T_4 * V_161 ;
unsigned char V_162 [ V_106 + V_163 ] ;
unsigned int V_164 ;
#endif
#ifndef F_53
T_5 * V_165 = NULL , * V_166 ;
#endif
T_6 * V_167 ;
unsigned char * V_131 , * V_144 ;
int V_168 , V_145 ;
unsigned long type ;
int V_169 ;
T_7 * V_22 ;
T_8 * V_170 [ 4 ] ;
int V_171 [ 4 ] , V_172 ;
T_3 * V_10 ;
T_9 V_173 ;
F_54 ( & V_173 ) ;
if ( V_9 -> V_17 == V_66 )
{
type = V_9 -> V_48 -> V_49 . V_63 -> V_64 & V_174 ;
V_22 = V_9 -> V_22 ;
V_10 = V_9 -> V_34 ;
V_170 [ 0 ] = V_170 [ 1 ] = V_170 [ 2 ] = V_170 [ 3 ] = NULL ;
V_169 = 0 ;
#ifndef F_52
if ( type & V_74 )
{
V_161 = V_22 -> V_175 ;
if ( ( V_161 == NULL ) && ( V_9 -> V_22 -> V_176 != NULL ) )
{
V_161 = V_9 -> V_22 -> V_176 ( V_9 ,
F_26 ( V_9 -> V_48 -> V_49 . V_63 ) ,
F_28 ( V_9 -> V_48 -> V_49 . V_63 ) ) ;
if( V_161 == NULL )
{
V_168 = V_177 ;
F_13 ( V_178 , V_179 ) ;
goto V_180;
}
F_55 ( V_161 ) ;
V_22 -> V_175 = V_161 ;
}
if ( V_161 == NULL )
{
V_168 = V_177 ;
F_13 ( V_178 , V_181 ) ;
goto V_180;
}
V_170 [ 0 ] = V_161 -> V_169 ;
V_170 [ 1 ] = V_161 -> V_182 ;
V_9 -> V_48 -> V_49 . V_71 = 1 ;
}
else
#endif
#ifndef F_53
if ( type & V_183 )
{
V_166 = V_22 -> V_184 ;
if ( ( V_166 == NULL ) && ( V_9 -> V_22 -> V_185 != NULL ) )
V_166 = V_9 -> V_22 -> V_185 ( V_9 ,
F_26 ( V_9 -> V_48 -> V_49 . V_63 ) ,
F_28 ( V_9 -> V_48 -> V_49 . V_63 ) ) ;
if ( V_166 == NULL )
{
V_168 = V_177 ;
F_13 ( V_178 , V_186 ) ;
goto V_180;
}
if ( V_9 -> V_48 -> V_49 . V_165 != NULL )
{
F_56 ( V_165 ) ;
F_13 ( V_178 , V_33 ) ;
goto V_187;
}
if ( ( V_165 = F_57 ( V_166 ) ) == NULL )
{
F_13 ( V_178 , V_188 ) ;
goto V_187;
}
V_9 -> V_48 -> V_49 . V_165 = V_165 ;
if ( ( V_166 -> V_189 == NULL ||
V_166 -> V_190 == NULL ||
( V_9 -> V_68 & V_191 ) ) )
{
if( ! F_58 ( V_165 ) )
{
F_13 ( V_178 ,
V_188 ) ;
goto V_187;
}
}
else
{
V_165 -> V_189 = F_59 ( V_166 -> V_189 ) ;
V_165 -> V_190 = F_59 ( V_166 -> V_190 ) ;
if ( ( V_165 -> V_189 == NULL ) ||
( V_165 -> V_190 == NULL ) )
{
F_13 ( V_178 , V_188 ) ;
goto V_187;
}
}
V_170 [ 0 ] = V_165 -> V_131 ;
V_170 [ 1 ] = V_165 -> V_192 ;
V_170 [ 2 ] = V_165 -> V_189 ;
}
else
#endif
{
V_168 = V_177 ;
F_13 ( V_178 , V_193 ) ;
goto V_180;
}
for ( V_145 = 0 ; V_170 [ V_145 ] != NULL ; V_145 ++ )
{
V_171 [ V_145 ] = F_60 ( V_170 [ V_145 ] ) ;
V_169 += 2 + V_171 [ V_145 ] ;
}
if ( ! ( V_9 -> V_48 -> V_49 . V_63 -> V_64 & V_65 ) )
{
if ( ( V_167 = F_61 ( V_9 , V_9 -> V_48 -> V_49 . V_63 ) )
== NULL )
{
V_168 = V_194 ;
goto V_180;
}
V_172 = F_27 ( V_167 ) ;
}
else
{
V_167 = NULL ;
V_172 = 0 ;
}
if ( ! F_62 ( V_10 , V_169 + V_134 + V_172 ) )
{
F_13 ( V_178 , V_195 ) ;
goto V_187;
}
V_144 = ( unsigned char * ) V_9 -> V_34 -> V_132 ;
V_131 = & ( V_144 [ V_134 ] ) ;
for ( V_145 = 0 ; V_170 [ V_145 ] != NULL ; V_145 ++ )
{
F_63 ( V_171 [ V_145 ] , V_131 ) ;
F_64 ( V_170 [ V_145 ] , V_131 ) ;
V_131 += V_171 [ V_145 ] ;
}
if ( V_167 != NULL )
{
#ifndef F_52
if ( V_167 -> type == V_196 )
{
V_158 = V_162 ;
V_159 = 0 ;
for ( V_160 = 2 ; V_160 > 0 ; V_160 -- )
{
F_65 ( & V_173 , ( V_160 == 2 )
? V_9 -> V_20 -> V_197 : V_9 -> V_20 -> V_198 , NULL ) ;
F_66 ( & V_173 , & ( V_9 -> V_48 -> V_199 [ 0 ] ) , V_148 ) ;
F_66 ( & V_173 , & ( V_9 -> V_48 -> V_147 [ 0 ] ) , V_148 ) ;
F_66 ( & V_173 , & ( V_144 [ V_134 ] ) , V_169 ) ;
F_67 ( & V_173 , V_158 ,
( unsigned int * ) & V_145 ) ;
V_158 += V_145 ;
V_159 += V_145 ;
}
if ( F_68 ( V_200 , V_162 , V_159 ,
& ( V_131 [ 2 ] ) , & V_164 , V_167 -> V_167 . V_161 ) <= 0 )
{
F_13 ( V_178 , V_201 ) ;
goto V_187;
}
F_63 ( V_164 , V_131 ) ;
V_169 += V_164 + 2 ;
}
else
#endif
#if ! F_69 ( V_202 )
if ( V_167 -> type == V_203 )
{
F_70 ( & V_173 , F_71 () , NULL ) ;
F_72 ( & V_173 , & ( V_9 -> V_48 -> V_199 [ 0 ] ) , V_148 ) ;
F_72 ( & V_173 , & ( V_9 -> V_48 -> V_147 [ 0 ] ) , V_148 ) ;
F_72 ( & V_173 , & ( V_144 [ V_134 ] ) , V_169 ) ;
if ( ! F_73 ( & V_173 , & ( V_131 [ 2 ] ) ,
( unsigned int * ) & V_145 , V_167 ) )
{
F_13 ( V_178 , V_204 ) ;
goto V_187;
}
F_63 ( V_145 , V_131 ) ;
V_169 += V_145 + 2 ;
}
else
#endif
{
V_168 = V_177 ;
F_13 ( V_178 , V_205 ) ;
goto V_180;
}
}
V_144 = F_46 ( V_9 , V_144 ,
V_206 , V_169 , 0 , V_169 ) ;
V_9 -> V_37 = V_169 + V_134 ;
V_9 -> V_135 = 0 ;
F_48 ( V_9 , 0 ) ;
}
V_9 -> V_17 = V_67 ;
F_74 ( & V_173 ) ;
return ( F_47 ( V_9 , V_136 ) ) ;
V_180:
F_75 ( V_9 , V_207 , V_168 ) ;
V_187:
F_74 ( & V_173 ) ;
return ( - 1 ) ;
}
int F_30 ( T_2 * V_9 )
{
unsigned char * V_131 , * V_144 ;
int V_145 , V_159 , V_208 , V_209 , V_169 ;
F_76 ( V_210 ) * V_211 = NULL ;
V_210 * V_212 ;
T_3 * V_10 ;
if ( V_9 -> V_17 == V_78 )
{
V_10 = V_9 -> V_34 ;
V_144 = V_131 = ( unsigned char * ) & ( V_10 -> V_132 [ V_134 ] ) ;
V_131 ++ ;
V_169 = F_77 ( V_9 , V_131 ) ;
V_144 [ 0 ] = V_169 ;
V_131 += V_169 ;
V_169 ++ ;
V_209 = V_169 ;
V_131 += 2 ;
V_169 += 2 ;
V_211 = F_78 ( V_9 ) ;
V_208 = 0 ;
if ( V_211 != NULL )
{
for ( V_145 = 0 ; V_145 < F_79 ( V_211 ) ; V_145 ++ )
{
V_212 = F_80 ( V_211 , V_145 ) ;
V_159 = F_81 ( V_212 , NULL ) ;
if ( ! F_62 ( V_10 , V_134 + V_169 + V_159 + 2 ) )
{
F_13 ( V_213 , V_214 ) ;
goto V_187;
}
V_131 = ( unsigned char * ) & ( V_10 -> V_132 [ V_134 + V_169 ] ) ;
if ( ! ( V_9 -> V_68 & V_215 ) )
{
F_63 ( V_159 , V_131 ) ;
F_81 ( V_212 , & V_131 ) ;
V_169 += 2 + V_159 ;
V_208 += 2 + V_159 ;
}
else
{
V_144 = V_131 ;
F_81 ( V_212 , & V_131 ) ;
V_159 -= 2 ; F_63 ( V_159 , V_144 ) ; V_159 += 2 ;
V_169 += V_159 ;
V_208 += V_159 ;
}
}
}
V_131 = ( unsigned char * ) & ( V_10 -> V_132 [ V_134 + V_209 ] ) ;
F_63 ( V_208 , V_131 ) ;
V_144 = ( unsigned char * ) V_10 -> V_132 ;
* ( V_144 ++ ) = V_216 ;
F_82 ( V_169 , V_144 ) ;
F_63 ( V_9 -> V_44 -> V_125 , V_144 ) ;
V_9 -> V_44 -> V_125 ++ ;
V_9 -> V_37 = V_169 + V_134 ;
V_9 -> V_135 = 0 ;
#ifdef F_31
V_131 = ( unsigned char * ) V_9 -> V_34 -> V_132 + V_9 -> V_37 ;
* ( V_131 ++ ) = V_157 ;
* ( V_131 ++ ) = 0 ;
* ( V_131 ++ ) = 0 ;
* ( V_131 ++ ) = 0 ;
V_9 -> V_37 += 4 ;
#endif
F_48 ( V_9 , 0 ) ;
V_9 -> V_17 = V_79 ;
}
return ( F_47 ( V_9 , V_136 ) ) ;
V_187:
return ( - 1 ) ;
}
int F_24 ( T_2 * V_9 )
{
unsigned long V_11 ;
T_10 * V_217 ;
if ( V_9 -> V_17 == V_61 )
{
V_217 = F_83 ( V_9 ) ;
if ( V_217 == NULL &&
( V_9 -> V_48 -> V_49 . V_63 -> V_64
& ( V_174 | V_218 ) )
!= ( V_86 | V_219 ) )
{
F_13 ( V_220 , V_33 ) ;
return ( 0 ) ;
}
V_11 = F_84 ( V_9 , V_217 ) ;
V_9 -> V_17 = V_62 ;
V_9 -> V_37 = ( int ) V_11 ;
V_9 -> V_135 = 0 ;
F_48 ( V_9 , 0 ) ;
}
return ( F_47 ( V_9 , V_136 ) ) ;
}
