static const T_1 * F_1 ( int V_1 )
{
if ( V_1 == V_2 )
return ( F_2 () ) ;
else
return ( NULL ) ;
}
int F_3 ( T_2 * V_3 )
{
T_3 * V_4 ;
unsigned long Time = ( unsigned long ) time ( NULL ) ;
void (* F_4)( const T_2 * V_5 , int type , int V_6 ) = NULL ;
unsigned long V_7 ;
int V_8 = - 1 ;
int V_9 , V_10 , V_11 = 0 ;
int V_12 ;
#ifndef F_5
unsigned char V_13 [ 64 ] ;
char V_14 [ sizeof( V_15 ) ] ;
#endif
F_6 ( & Time , sizeof( Time ) , 0 ) ;
F_7 () ;
F_8 () ;
if ( V_3 -> V_16 != NULL )
F_4 = V_3 -> V_16 ;
else if ( V_3 -> V_17 -> V_16 != NULL )
F_4 = V_3 -> V_17 -> V_16 ;
V_12 = V_3 -> V_18 -> V_12 ;
V_3 -> V_19 ++ ;
if ( ! F_9 ( V_3 ) || F_10 ( V_3 ) ) F_11 ( V_3 ) ;
V_3 -> V_18 -> V_12 = V_12 ;
#ifndef F_5
F_12 ( F_13 ( V_3 ) , V_20 , V_3 -> V_19 , NULL ) ;
#endif
if ( V_3 -> V_21 == NULL )
{
F_14 ( V_22 , V_23 ) ;
return ( - 1 ) ;
}
#ifndef F_15
if ( V_3 -> V_24 )
{
F_16 ( V_3 ) ;
V_3 -> V_24 = 0 ;
V_3 -> V_25 ++ ;
}
#endif
for (; ; )
{
V_10 = V_3 -> V_10 ;
switch ( V_3 -> V_10 )
{
case V_26 :
V_3 -> V_27 = 1 ;
case V_28 :
case V_29 :
case V_28 | V_29 :
case V_30 | V_29 :
V_3 -> V_31 = 1 ;
if ( F_4 != NULL ) F_4 ( V_3 , V_32 , 1 ) ;
if ( ( V_3 -> V_33 & 0xff00 ) != ( V_2 & 0xff00 ) )
{
F_14 ( V_22 , V_34 ) ;
return - 1 ;
}
V_3 -> type = V_29 ;
if ( V_3 -> V_35 == NULL )
{
if ( ( V_4 = F_17 () ) == NULL )
{
V_8 = - 1 ;
goto V_36;
}
if ( ! F_18 ( V_4 , V_37 ) )
{
V_8 = - 1 ;
goto V_36;
}
V_3 -> V_35 = V_4 ;
}
if ( ! F_19 ( V_3 ) )
{
V_8 = - 1 ;
goto V_36;
}
V_3 -> V_38 = 0 ;
if ( V_3 -> V_10 != V_26 )
{
#ifndef F_5
if ( ! F_20 ( F_13 ( V_3 ) ) )
#endif
if ( ! F_21 ( V_3 , 1 ) ) { V_8 = - 1 ; goto V_36; }
F_22 ( V_3 ) ;
V_3 -> V_10 = V_39 ;
V_3 -> V_17 -> V_40 . V_41 ++ ;
}
else
{
V_3 -> V_17 -> V_40 . V_42 ++ ;
V_3 -> V_10 = V_43 ;
}
break;
case V_43 :
case V_44 :
V_3 -> V_45 = 0 ;
F_23 ( V_3 ) ;
V_8 = F_24 ( V_3 ) ;
if ( V_8 <= 0 ) goto V_36;
V_3 -> V_46 -> V_47 . V_48 = V_49 ;
V_3 -> V_10 = V_50 ;
V_3 -> V_38 = 0 ;
F_22 ( V_3 ) ;
break;
case V_49 :
V_3 -> V_10 = V_30 ;
break;
case V_39 :
case V_51 :
case V_52 :
V_3 -> V_45 = 0 ;
V_8 = F_25 ( V_3 ) ;
if ( V_8 <= 0 ) goto V_36;
F_16 ( V_3 ) ;
if ( V_8 == 1 && ( F_26 ( V_3 ) & V_53 ) )
V_3 -> V_10 = V_54 ;
else
V_3 -> V_10 = V_55 ;
V_3 -> V_38 = 0 ;
if ( V_12 )
{
memcpy ( V_3 -> V_46 -> V_56 , V_3 -> V_46 -> V_57 , sizeof( V_3 -> V_46 -> V_56 ) ) ;
}
if ( V_12 && V_3 -> V_10 == V_55 )
{
V_8 = 2 ;
V_3 -> V_18 -> V_12 = 0 ;
V_3 -> V_18 -> V_58 = 2 ;
V_3 -> V_18 -> V_59 = 1 ;
V_3 -> V_18 -> V_60 = 1 ;
goto V_36;
}
break;
case V_54 :
case V_61 :
V_8 = F_27 ( V_3 ) ;
if ( V_8 <= 0 ) goto V_36;
V_3 -> V_10 = V_50 ;
V_3 -> V_46 -> V_47 . V_48 = V_39 ;
if ( V_3 -> V_33 != V_62 )
F_22 ( V_3 ) ;
break;
#ifndef F_5
case V_63 :
if ( F_28 ( F_29 ( V_3 ) ) )
{
V_3 -> V_46 -> V_64 = 2 ;
V_3 -> V_65 = V_66 ;
F_30 ( F_29 ( V_3 ) ) ;
F_31 ( F_29 ( V_3 ) ) ;
V_8 = - 1 ;
goto V_36;
}
V_3 -> V_10 = V_67 ;
break;
case V_68 :
V_8 = F_32 ( F_13 ( V_3 ) ) ;
if ( V_8 < 0 ) goto V_36;
if ( V_8 == 0 )
{
if ( V_3 -> V_18 -> V_48 != V_30 )
{
V_3 -> V_46 -> V_64 = 2 ;
V_3 -> V_65 = V_66 ;
F_30 ( F_29 ( V_3 ) ) ;
F_31 ( F_29 ( V_3 ) ) ;
V_8 = - 1 ;
goto V_36;
}
}
V_3 -> V_10 = V_3 -> V_18 -> V_48 ;
break;
#endif
case V_55 :
case V_69 :
V_3 -> V_27 = 2 ;
F_23 ( V_3 ) ;
V_8 = F_33 ( V_3 ) ;
if ( V_8 <= 0 ) goto V_36;
if ( V_3 -> V_70 )
{
#ifndef F_5
snprintf ( ( char * ) V_14 , sizeof( V_15 ) ,
V_15 ) ;
F_34 ( V_3 , V_13 ,
sizeof( V_13 ) , V_14 ,
sizeof( V_14 ) , NULL , 0 , 0 ) ;
F_12 ( F_13 ( V_3 ) , V_71 ,
sizeof( V_13 ) , V_13 ) ;
#endif
#ifndef F_35
if ( V_3 -> V_72 )
V_3 -> V_10 = V_73 ;
else
V_3 -> V_10 = V_74 ;
#else
V_3 -> V_10 = V_74 ;
#endif
}
else
V_3 -> V_10 = V_75 ;
V_3 -> V_38 = 0 ;
break;
case V_75 :
case V_76 :
if ( ! ( V_3 -> V_46 -> V_47 . V_77 -> V_78 & V_79 )
&& ! ( V_3 -> V_46 -> V_47 . V_77 -> V_80 & V_81 ) )
{
F_23 ( V_3 ) ;
V_8 = F_36 ( V_3 ) ;
if ( V_8 <= 0 ) goto V_36;
#ifndef F_35
if ( V_3 -> V_82 )
V_3 -> V_10 = V_83 ;
else
V_3 -> V_10 = V_84 ;
}
else
{
V_11 = 1 ;
V_3 -> V_10 = V_84 ;
}
#else
}
else
V_11 = 1 ;
V_3 -> V_10 = V_84 ;
#endif
V_3 -> V_38 = 0 ;
break;
case V_84 :
case V_85 :
V_7 = V_3 -> V_46 -> V_47 . V_77 -> V_80 ;
if ( ( V_3 -> V_86 & V_87 )
#ifndef F_37
&& ! ( V_7 & V_88 )
#endif
)
V_3 -> V_46 -> V_47 . V_89 = 1 ;
else
V_3 -> V_46 -> V_47 . V_89 = 0 ;
if ( V_3 -> V_46 -> V_47 . V_89
#ifndef F_38
|| ( ( V_7 & V_81 ) && V_3 -> V_17 -> V_90 )
#endif
|| ( V_7 & ( V_91 | V_92 | V_93 ) )
|| ( V_7 & V_94 )
|| ( ( V_7 & V_95 )
&& ( V_3 -> V_21 -> V_96 [ V_97 ] . V_98 == NULL
|| ( F_39 ( V_3 -> V_46 -> V_47 . V_77 )
&& F_40 ( V_3 -> V_21 -> V_96 [ V_97 ] . V_98 ) * 8 > F_41 ( V_3 -> V_46 -> V_47 . V_77 )
)
)
)
)
{
F_23 ( V_3 ) ;
V_8 = F_42 ( V_3 ) ;
if ( V_8 <= 0 ) goto V_36;
}
else
V_11 = 1 ;
V_3 -> V_10 = V_99 ;
V_3 -> V_38 = 0 ;
break;
case V_99 :
case V_100 :
if (
! ( V_3 -> V_101 & V_102 ) ||
( ( V_3 -> V_103 -> V_104 != NULL ) &&
( V_3 -> V_101 & V_105 ) ) ||
( ( V_3 -> V_46 -> V_47 . V_77 -> V_78 & V_79 ) &&
! ( V_3 -> V_101 & V_106 ) ) ||
( V_3 -> V_46 -> V_47 . V_77 -> V_78 & V_107 )
|| ( V_3 -> V_46 -> V_47 . V_77 -> V_80 & V_81 ) )
{
V_11 = 1 ;
V_3 -> V_46 -> V_47 . V_108 = 0 ;
V_3 -> V_10 = V_109 ;
#ifndef F_5
if ( F_20 ( F_13 ( V_3 ) ) )
{
V_3 -> V_18 -> V_48 = V_109 ;
V_3 -> V_10 = V_68 ;
}
#endif
}
else
{
V_3 -> V_46 -> V_47 . V_108 = 1 ;
F_23 ( V_3 ) ;
V_8 = F_43 ( V_3 ) ;
if ( V_8 <= 0 ) goto V_36;
#ifndef F_44
V_3 -> V_10 = V_109 ;
#ifndef F_5
if ( F_20 ( F_13 ( V_3 ) ) )
{
V_3 -> V_18 -> V_48 = V_109 ;
V_3 -> V_10 = V_68 ;
}
#endif
#else
V_3 -> V_10 = V_50 ;
V_3 -> V_46 -> V_47 . V_48 = V_110 ;
#ifndef F_5
if ( F_20 ( F_13 ( V_3 ) ) )
{
V_3 -> V_18 -> V_48 = V_3 -> V_46 -> V_47 . V_48 ;
V_3 -> V_46 -> V_47 . V_48 = V_68 ;
}
#endif
#endif
V_3 -> V_38 = 0 ;
}
break;
case V_109 :
case V_111 :
F_23 ( V_3 ) ;
V_8 = F_45 ( V_3 ) ;
if ( V_8 <= 0 ) goto V_36;
V_3 -> V_46 -> V_47 . V_48 = V_110 ;
V_3 -> V_10 = V_50 ;
V_3 -> V_38 = 0 ;
break;
case V_50 :
V_3 -> V_65 = V_112 ;
if ( F_46 ( V_3 -> V_113 ) <= 0 )
{
if ( ! F_47 ( V_3 -> V_113 ) )
{
V_3 -> V_65 = V_114 ;
V_3 -> V_10 = V_3 -> V_46 -> V_47 . V_48 ;
}
V_8 = - 1 ;
goto V_36;
}
V_3 -> V_65 = V_114 ;
V_3 -> V_10 = V_3 -> V_46 -> V_47 . V_48 ;
break;
case V_110 :
case V_115 :
V_8 = F_48 ( V_3 ) ;
if ( V_8 <= 0 )
goto V_36;
if ( V_8 == 2 )
{
F_16 ( V_3 ) ;
V_3 -> V_10 = V_52 ;
}
else {
V_8 = F_49 ( V_3 ) ;
if ( V_8 <= 0 ) goto V_36;
V_3 -> V_38 = 0 ;
V_3 -> V_10 = V_116 ;
}
break;
case V_116 :
case V_117 :
V_8 = F_50 ( V_3 ) ;
if ( V_8 <= 0 ) goto V_36;
#ifndef F_5
snprintf ( ( char * ) V_14 , sizeof( V_15 ) ,
V_15 ) ;
F_34 ( V_3 , V_13 ,
sizeof( V_13 ) , V_14 ,
sizeof( V_14 ) , NULL , 0 , 0 ) ;
F_12 ( F_13 ( V_3 ) , V_71 ,
sizeof( V_13 ) , V_13 ) ;
#endif
V_3 -> V_10 = V_118 ;
V_3 -> V_38 = 0 ;
if ( V_8 == 2 )
{
V_3 -> V_10 = V_67 ;
V_3 -> V_38 = 0 ;
}
else
{
V_3 -> V_10 = V_118 ;
V_3 -> V_38 = 0 ;
V_3 -> V_119 -> V_120 -> V_121 ( V_3 ,
V_122 ,
& ( V_3 -> V_46 -> V_47 . V_123 [ 0 ] ) ) ;
V_3 -> V_119 -> V_120 -> V_121 ( V_3 ,
V_124 ,
& ( V_3 -> V_46 -> V_47 . V_123 [ V_125 ] ) ) ;
}
break;
case V_118 :
case V_126 :
V_3 -> V_18 -> V_127 = 1 ;
V_8 = F_51 ( V_3 ) ;
if ( V_8 <= 0 ) goto V_36;
#ifndef F_5
if ( F_20 ( F_13 ( V_3 ) ) &&
V_10 == V_26 )
V_3 -> V_10 = V_63 ;
else
#endif
V_3 -> V_10 = V_67 ;
V_3 -> V_38 = 0 ;
break;
case V_67 :
case V_128 :
V_3 -> V_18 -> V_127 = 1 ;
V_8 = F_52 ( V_3 , V_67 ,
V_128 ) ;
if ( V_8 <= 0 ) goto V_36;
F_16 ( V_3 ) ;
if ( V_3 -> V_70 )
V_3 -> V_10 = V_30 ;
#ifndef F_35
else if ( V_3 -> V_72 )
V_3 -> V_10 = V_73 ;
#endif
else
V_3 -> V_10 = V_74 ;
V_3 -> V_38 = 0 ;
break;
#ifndef F_35
case V_73 :
case V_129 :
V_8 = F_53 ( V_3 ) ;
if ( V_8 <= 0 ) goto V_36;
V_3 -> V_10 = V_74 ;
V_3 -> V_38 = 0 ;
break;
case V_83 :
case V_130 :
V_8 = F_54 ( V_3 ) ;
if ( V_8 <= 0 ) goto V_36;
V_3 -> V_10 = V_84 ;
V_3 -> V_38 = 0 ;
break;
#endif
case V_74 :
case V_131 :
V_3 -> V_103 -> V_132 = V_3 -> V_46 -> V_47 . V_77 ;
if ( ! V_3 -> V_119 -> V_120 -> V_133 ( V_3 ) )
{ V_8 = - 1 ; goto V_36; }
V_8 = F_55 ( V_3 ,
V_74 , V_131 ) ;
if ( V_8 <= 0 ) goto V_36;
#ifndef F_5
F_12 ( F_13 ( V_3 ) , V_134 , 0 , NULL ) ;
#endif
V_3 -> V_10 = V_135 ;
V_3 -> V_38 = 0 ;
if ( ! V_3 -> V_119 -> V_120 -> V_136 ( V_3 ,
V_137 ) )
{
V_8 = - 1 ;
goto V_36;
}
F_56 ( V_3 , V_138 ) ;
break;
case V_135 :
case V_139 :
V_8 = F_57 ( V_3 ,
V_135 , V_139 ,
V_3 -> V_119 -> V_120 -> V_140 ,
V_3 -> V_119 -> V_120 -> V_141 ) ;
if ( V_8 <= 0 ) goto V_36;
V_3 -> V_10 = V_50 ;
if ( V_3 -> V_70 )
V_3 -> V_46 -> V_47 . V_48 = V_67 ;
else
{
V_3 -> V_46 -> V_47 . V_48 = V_30 ;
#ifndef F_5
if ( F_20 ( F_13 ( V_3 ) ) )
{
V_3 -> V_18 -> V_48 = V_3 -> V_46 -> V_47 . V_48 ;
V_3 -> V_46 -> V_47 . V_48 = V_68 ;
}
#endif
}
V_3 -> V_38 = 0 ;
break;
case V_30 :
F_58 ( V_3 ) ;
#if 0
BUF_MEM_free(s->init_buf);
s->init_buf=NULL;
#endif
F_59 ( V_3 ) ;
V_3 -> V_38 = 0 ;
if ( V_3 -> V_27 == 2 )
{
V_3 -> V_27 = 0 ;
V_3 -> V_142 = 0 ;
F_60 ( V_3 , V_143 ) ;
V_3 -> V_17 -> V_40 . V_144 ++ ;
V_3 -> V_145 = F_3 ;
if ( F_4 != NULL ) F_4 ( V_3 , V_146 , 1 ) ;
}
V_8 = 1 ;
V_3 -> V_18 -> V_58 = 0 ;
V_3 -> V_18 -> V_59 = 0 ;
V_3 -> V_18 -> V_60 = 0 ;
goto V_36;
default:
F_14 ( V_22 , V_147 ) ;
V_8 = - 1 ;
goto V_36;
}
if ( ! V_3 -> V_46 -> V_47 . V_148 && ! V_11 )
{
if ( V_3 -> V_149 )
{
if ( ( V_8 = F_46 ( V_3 -> V_113 ) ) <= 0 )
goto V_36;
}
if ( ( F_4 != NULL ) && ( V_3 -> V_10 != V_10 ) )
{
V_9 = V_3 -> V_10 ;
V_3 -> V_10 = V_10 ;
F_4 ( V_3 , V_150 , 1 ) ;
V_3 -> V_10 = V_9 ;
}
}
V_11 = 0 ;
}
int F_27 ( T_2 * V_3 )
{
unsigned int V_151 ;
unsigned char * V_152 , * V_4 , * V_153 ;
if ( V_3 -> V_10 == V_54 )
{
V_4 = ( unsigned char * ) V_3 -> V_35 -> V_154 ;
V_152 = V_153 = & ( V_4 [ V_155 ] ) ;
* ( V_153 ++ ) = V_3 -> V_33 >> 8 ;
* ( V_153 ++ ) = V_3 -> V_33 & 0xFF ;
if ( V_3 -> V_17 -> V_156 == NULL ||
V_3 -> V_17 -> V_156 ( V_3 , V_3 -> V_18 -> V_157 ,
& ( V_3 -> V_18 -> V_158 ) ) == 0 )
{
F_14 ( V_159 , V_34 ) ;
return 0 ;
}
* ( V_153 ++ ) = ( unsigned char ) V_3 -> V_18 -> V_158 ;
memcpy ( V_153 , V_3 -> V_18 -> V_157 , V_3 -> V_18 -> V_158 ) ;
V_153 += V_3 -> V_18 -> V_158 ;
V_151 = V_153 - V_152 ;
F_61 ( V_3 , V_4 ,
V_160 , V_151 , 0 , V_151 ) ;
V_3 -> V_10 = V_61 ;
V_3 -> V_38 = V_153 - V_4 ;
V_3 -> V_161 = 0 ;
}
return ( F_62 ( V_3 , V_162 ) ) ;
}
int F_33 ( T_2 * V_3 )
{
unsigned char * V_4 ;
unsigned char * V_153 , * V_163 ;
int V_164 ;
unsigned int V_165 ;
unsigned long V_166 , Time ;
if ( V_3 -> V_10 == V_55 )
{
V_4 = ( unsigned char * ) V_3 -> V_35 -> V_154 ;
V_153 = V_3 -> V_46 -> V_167 ;
Time = ( unsigned long ) time ( NULL ) ;
F_63 ( Time , V_153 ) ;
F_64 ( V_153 , V_168 - sizeof( Time ) ) ;
V_163 = V_153 = & ( V_4 [ V_155 ] ) ;
* ( V_153 ++ ) = V_3 -> V_33 >> 8 ;
* ( V_153 ++ ) = V_3 -> V_33 & 0xff ;
memcpy ( V_153 , V_3 -> V_46 -> V_167 , V_168 ) ;
V_153 += V_168 ;
if ( ! ( V_3 -> V_17 -> V_169 & V_143 ) )
V_3 -> V_103 -> V_170 = 0 ;
V_165 = V_3 -> V_103 -> V_170 ;
if ( V_165 > sizeof V_3 -> V_103 -> V_171 )
{
F_14 ( V_172 , V_34 ) ;
return - 1 ;
}
* ( V_153 ++ ) = V_165 ;
memcpy ( V_153 , V_3 -> V_103 -> V_171 , V_165 ) ;
V_153 += V_165 ;
if ( V_3 -> V_46 -> V_47 . V_77 == NULL )
return - 1 ;
V_164 = F_65 ( V_3 -> V_46 -> V_47 . V_77 , V_153 ) ;
V_153 += V_164 ;
#ifdef F_66
* ( V_153 ++ ) = 0 ;
#else
if ( V_3 -> V_46 -> V_47 . V_173 == NULL )
* ( V_153 ++ ) = 0 ;
else
* ( V_153 ++ ) = V_3 -> V_46 -> V_47 . V_173 -> V_174 ;
#endif
#ifndef F_35
if ( ( V_153 = F_67 ( V_3 , V_153 , V_4 + V_37 ) ) == NULL )
{
F_14 ( V_172 , V_34 ) ;
return - 1 ;
}
#endif
V_166 = ( V_153 - V_163 ) ;
V_163 = V_4 ;
V_163 = F_61 ( V_3 , V_163 , V_175 , V_166 , 0 , V_166 ) ;
V_3 -> V_10 = V_69 ;
V_3 -> V_38 = V_153 - V_4 ;
V_3 -> V_161 = 0 ;
F_68 ( V_3 , 0 ) ;
}
return ( F_62 ( V_3 , V_162 ) ) ;
}
int F_45 ( T_2 * V_3 )
{
unsigned char * V_153 ;
if ( V_3 -> V_10 == V_109 )
{
V_153 = ( unsigned char * ) V_3 -> V_35 -> V_154 ;
V_153 = F_61 ( V_3 , V_153 , V_176 , 0 , 0 , 0 ) ;
V_3 -> V_10 = V_111 ;
V_3 -> V_38 = V_155 ;
V_3 -> V_161 = 0 ;
F_68 ( V_3 , 0 ) ;
}
return ( F_62 ( V_3 , V_162 ) ) ;
}
int F_42 ( T_2 * V_3 )
{
#ifndef F_69
unsigned char * V_177 ;
int V_178 , V_179 ;
T_4 * V_180 ;
unsigned char V_181 [ V_125 + V_182 ] ;
unsigned int V_183 ;
#endif
#ifndef F_70
T_5 * V_184 = NULL , * V_185 ;
#endif
#ifndef F_71
T_6 * V_186 = NULL , * V_187 ;
unsigned char * V_188 = NULL ;
int V_189 = 0 ;
int V_190 = 0 ;
T_7 * V_191 = NULL ;
#endif
T_8 * V_192 ;
unsigned char * V_153 , * V_163 ;
int V_193 , V_164 ;
unsigned long type ;
int V_194 ;
T_9 * V_21 ;
T_10 * V_195 [ 4 ] ;
int V_196 [ 4 ] , V_197 ;
T_3 * V_4 ;
T_11 V_198 ;
F_72 ( & V_198 ) ;
if ( V_3 -> V_10 == V_84 )
{
type = V_3 -> V_46 -> V_47 . V_77 -> V_80 ;
V_21 = V_3 -> V_21 ;
V_4 = V_3 -> V_35 ;
V_195 [ 0 ] = V_195 [ 1 ] = V_195 [ 2 ] = V_195 [ 3 ] = NULL ;
V_194 = 0 ;
#ifndef F_69
if ( type & V_95 )
{
V_180 = V_21 -> V_199 ;
if ( ( V_180 == NULL ) && ( V_3 -> V_21 -> V_200 != NULL ) )
{
V_180 = V_3 -> V_21 -> V_200 ( V_3 ,
F_39 ( V_3 -> V_46 -> V_47 . V_77 ) ,
F_41 ( V_3 -> V_46 -> V_47 . V_77 ) ) ;
if( V_180 == NULL )
{
V_193 = V_201 ;
F_14 ( V_202 , V_203 ) ;
goto V_204;
}
F_73 ( V_180 ) ;
V_21 -> V_199 = V_180 ;
}
if ( V_180 == NULL )
{
V_193 = V_201 ;
F_14 ( V_202 , V_205 ) ;
goto V_204;
}
V_195 [ 0 ] = V_180 -> V_194 ;
V_195 [ 1 ] = V_180 -> V_206 ;
V_3 -> V_46 -> V_47 . V_89 = 1 ;
}
else
#endif
#ifndef F_70
if ( type & V_91 )
{
V_185 = V_21 -> V_207 ;
if ( ( V_185 == NULL ) && ( V_3 -> V_21 -> V_208 != NULL ) )
V_185 = V_3 -> V_21 -> V_208 ( V_3 ,
F_39 ( V_3 -> V_46 -> V_47 . V_77 ) ,
F_41 ( V_3 -> V_46 -> V_47 . V_77 ) ) ;
if ( V_185 == NULL )
{
V_193 = V_201 ;
F_14 ( V_202 , V_209 ) ;
goto V_204;
}
if ( V_3 -> V_46 -> V_47 . V_184 != NULL )
{
F_74 ( V_184 ) ;
F_14 ( V_202 , V_34 ) ;
goto V_210;
}
if ( ( V_184 = F_75 ( V_185 ) ) == NULL )
{
F_14 ( V_202 , V_211 ) ;
goto V_210;
}
V_3 -> V_46 -> V_47 . V_184 = V_184 ;
if ( ( V_185 -> V_212 == NULL ||
V_185 -> V_213 == NULL ||
( V_3 -> V_86 & V_214 ) ) )
{
if( ! F_76 ( V_184 ) )
{
F_14 ( V_202 ,
V_211 ) ;
goto V_210;
}
}
else
{
V_184 -> V_212 = F_77 ( V_185 -> V_212 ) ;
V_184 -> V_213 = F_77 ( V_185 -> V_213 ) ;
if ( ( V_184 -> V_212 == NULL ) ||
( V_184 -> V_213 == NULL ) )
{
F_14 ( V_202 , V_211 ) ;
goto V_210;
}
}
V_195 [ 0 ] = V_184 -> V_153 ;
V_195 [ 1 ] = V_184 -> V_215 ;
V_195 [ 2 ] = V_184 -> V_212 ;
}
else
#endif
#ifndef F_71
if ( type & V_94 )
{
const T_12 * V_216 ;
V_187 = V_21 -> V_217 ;
if ( ( V_187 == NULL ) && ( V_3 -> V_21 -> V_218 != NULL ) )
{
V_187 = V_3 -> V_21 -> V_218 ( V_3 ,
F_39 ( V_3 -> V_46 -> V_47 . V_77 ) ,
F_41 ( V_3 -> V_46 -> V_47 . V_77 ) ) ;
}
if ( V_187 == NULL )
{
V_193 = V_201 ;
F_14 ( V_202 , V_219 ) ;
goto V_204;
}
if ( V_3 -> V_46 -> V_47 . V_186 != NULL )
{
F_78 ( V_3 -> V_46 -> V_47 . V_186 ) ;
F_14 ( V_202 , V_34 ) ;
goto V_210;
}
if ( V_187 == NULL )
{
F_14 ( V_202 , V_220 ) ;
goto V_210;
}
if ( ( V_186 = F_79 ( V_187 ) ) == NULL )
{
F_14 ( V_202 , V_220 ) ;
goto V_210;
}
V_3 -> V_46 -> V_47 . V_186 = V_186 ;
if ( ( F_80 ( V_186 ) == NULL ) ||
( F_81 ( V_186 ) == NULL ) ||
( V_3 -> V_86 & V_221 ) )
{
if( ! F_82 ( V_186 ) )
{
F_14 ( V_202 , V_220 ) ;
goto V_210;
}
}
if ( ( ( V_216 = F_83 ( V_186 ) ) == NULL ) ||
( F_80 ( V_186 ) == NULL ) ||
( F_81 ( V_186 ) == NULL ) )
{
F_14 ( V_202 , V_220 ) ;
goto V_210;
}
if ( F_39 ( V_3 -> V_46 -> V_47 . V_77 ) &&
( F_84 ( V_216 ) > 163 ) )
{
F_14 ( V_202 , V_222 ) ;
goto V_210;
}
if ( ( V_190 =
F_85 ( F_86 ( V_216 ) ) )
== 0 )
{
F_14 ( V_202 , V_223 ) ;
goto V_210;
}
V_189 = F_87 ( V_216 ,
F_80 ( V_186 ) ,
V_224 ,
NULL , 0 , NULL ) ;
V_188 = ( unsigned char * )
F_88 ( V_189 *sizeof( unsigned char ) ) ;
V_191 = F_89 () ;
if ( ( V_188 == NULL ) || ( V_191 == NULL ) )
{
F_14 ( V_202 , V_225 ) ;
goto V_210;
}
V_189 = F_87 ( V_216 ,
F_80 ( V_186 ) ,
V_224 ,
V_188 , V_189 , V_191 ) ;
if ( V_189 == 0 )
{
F_14 ( V_202 , V_220 ) ;
goto V_210;
}
F_90 ( V_191 ) ; V_191 = NULL ;
V_194 = 4 + V_189 ;
V_195 [ 0 ] = NULL ;
V_195 [ 1 ] = NULL ;
V_195 [ 2 ] = NULL ;
V_195 [ 3 ] = NULL ;
}
else
#endif
#ifndef F_38
if ( type & V_81 )
{
V_194 += 2 + strlen ( V_3 -> V_17 -> V_90 ) ;
}
else
#endif
{
V_193 = V_201 ;
F_14 ( V_202 , V_226 ) ;
goto V_204;
}
for ( V_164 = 0 ; V_195 [ V_164 ] != NULL ; V_164 ++ )
{
V_196 [ V_164 ] = F_91 ( V_195 [ V_164 ] ) ;
V_194 += 2 + V_196 [ V_164 ] ;
}
if ( ! ( V_3 -> V_46 -> V_47 . V_77 -> V_78 & V_79 )
&& ! ( V_3 -> V_46 -> V_47 . V_77 -> V_80 & V_81 ) )
{
if ( ( V_192 = F_92 ( V_3 , V_3 -> V_46 -> V_47 . V_77 , NULL ) )
== NULL )
{
V_193 = V_227 ;
goto V_204;
}
V_197 = F_40 ( V_192 ) ;
}
else
{
V_192 = NULL ;
V_197 = 0 ;
}
if ( ! F_93 ( V_4 , V_194 + V_155 + V_197 ) )
{
F_14 ( V_202 , V_228 ) ;
goto V_210;
}
V_163 = ( unsigned char * ) V_3 -> V_35 -> V_154 ;
V_153 = & ( V_163 [ V_155 ] ) ;
for ( V_164 = 0 ; V_195 [ V_164 ] != NULL ; V_164 ++ )
{
F_94 ( V_196 [ V_164 ] , V_153 ) ;
F_95 ( V_195 [ V_164 ] , V_153 ) ;
V_153 += V_196 [ V_164 ] ;
}
#ifndef F_71
if ( type & V_94 )
{
* V_153 = V_229 ;
V_153 += 1 ;
* V_153 = 0 ;
V_153 += 1 ;
* V_153 = V_190 ;
V_153 += 1 ;
* V_153 = V_189 ;
V_153 += 1 ;
memcpy ( ( unsigned char * ) V_153 ,
( unsigned char * ) V_188 ,
V_189 ) ;
F_96 ( V_188 ) ;
V_153 += V_189 ;
}
#endif
#ifndef F_38
if ( type & V_81 )
{
F_94 ( strlen ( V_3 -> V_17 -> V_90 ) , V_153 ) ;
strncpy ( ( char * ) V_153 , V_3 -> V_17 -> V_90 , strlen ( V_3 -> V_17 -> V_90 ) ) ;
V_153 += strlen ( V_3 -> V_17 -> V_90 ) ;
}
#endif
if ( V_192 != NULL )
{
#ifndef F_69
if ( V_192 -> type == V_230 )
{
V_177 = V_181 ;
V_178 = 0 ;
for ( V_179 = 2 ; V_179 > 0 ; V_179 -- )
{
F_97 ( & V_198 , ( V_179 == 2 )
? V_3 -> V_17 -> V_231 : V_3 -> V_17 -> V_232 , NULL ) ;
F_98 ( & V_198 , & ( V_3 -> V_46 -> V_233 [ 0 ] ) , V_168 ) ;
F_98 ( & V_198 , & ( V_3 -> V_46 -> V_167 [ 0 ] ) , V_168 ) ;
F_98 ( & V_198 , & ( V_163 [ V_155 ] ) , V_194 ) ;
F_99 ( & V_198 , V_177 ,
( unsigned int * ) & V_164 ) ;
V_177 += V_164 ;
V_178 += V_164 ;
}
if ( F_100 ( V_234 , V_181 , V_178 ,
& ( V_153 [ 2 ] ) , & V_183 , V_192 -> V_192 . V_180 ) <= 0 )
{
F_14 ( V_202 , V_235 ) ;
goto V_210;
}
F_94 ( V_183 , V_153 ) ;
V_194 += V_183 + 2 ;
}
else
#endif
#if ! F_101 ( V_236 )
if ( V_192 -> type == V_237 )
{
F_102 ( & V_198 , F_103 () , NULL ) ;
F_104 ( & V_198 , & ( V_3 -> V_46 -> V_233 [ 0 ] ) , V_168 ) ;
F_104 ( & V_198 , & ( V_3 -> V_46 -> V_167 [ 0 ] ) , V_168 ) ;
F_104 ( & V_198 , & ( V_163 [ V_155 ] ) , V_194 ) ;
if ( ! F_105 ( & V_198 , & ( V_153 [ 2 ] ) ,
( unsigned int * ) & V_164 , V_192 ) )
{
F_14 ( V_202 , V_238 ) ;
goto V_210;
}
F_94 ( V_164 , V_153 ) ;
V_194 += V_164 + 2 ;
}
else
#endif
#if ! F_101 ( V_239 )
if ( V_192 -> type == V_240 )
{
F_102 ( & V_198 , F_106 () , NULL ) ;
F_104 ( & V_198 , & ( V_3 -> V_46 -> V_233 [ 0 ] ) , V_168 ) ;
F_104 ( & V_198 , & ( V_3 -> V_46 -> V_167 [ 0 ] ) , V_168 ) ;
F_104 ( & V_198 , & ( V_163 [ V_155 ] ) , V_194 ) ;
if ( ! F_105 ( & V_198 , & ( V_153 [ 2 ] ) ,
( unsigned int * ) & V_164 , V_192 ) )
{
F_14 ( V_202 , V_241 ) ;
goto V_210;
}
F_94 ( V_164 , V_153 ) ;
V_194 += V_164 + 2 ;
}
else
#endif
{
V_193 = V_201 ;
F_14 ( V_202 , V_242 ) ;
goto V_204;
}
}
V_163 = F_61 ( V_3 , V_163 ,
V_243 , V_194 , 0 , V_194 ) ;
V_3 -> V_38 = V_194 + V_155 ;
V_3 -> V_161 = 0 ;
F_68 ( V_3 , 0 ) ;
}
V_3 -> V_10 = V_85 ;
F_107 ( & V_198 ) ;
return ( F_62 ( V_3 , V_162 ) ) ;
V_204:
F_108 ( V_3 , V_244 , V_193 ) ;
V_210:
#ifndef F_71
if ( V_188 != NULL ) F_96 ( V_188 ) ;
F_90 ( V_191 ) ;
#endif
F_107 ( & V_198 ) ;
return ( - 1 ) ;
}
int F_43 ( T_2 * V_3 )
{
unsigned char * V_153 , * V_163 ;
int V_164 , V_178 , V_245 , V_246 , V_194 ;
F_109 ( V_247 ) * V_248 = NULL ;
V_247 * V_249 ;
T_3 * V_4 ;
unsigned int V_151 ;
if ( V_3 -> V_10 == V_99 )
{
V_4 = V_3 -> V_35 ;
V_163 = V_153 = ( unsigned char * ) & ( V_4 -> V_154 [ V_155 ] ) ;
V_153 ++ ;
V_194 = F_110 ( V_3 , V_153 ) ;
V_163 [ 0 ] = V_194 ;
V_153 += V_194 ;
V_194 ++ ;
V_246 = V_194 ;
V_153 += 2 ;
V_194 += 2 ;
V_248 = F_111 ( V_3 ) ;
V_245 = 0 ;
if ( V_248 != NULL )
{
for ( V_164 = 0 ; V_164 < F_112 ( V_248 ) ; V_164 ++ )
{
V_249 = F_113 ( V_248 , V_164 ) ;
V_178 = F_114 ( V_249 , NULL ) ;
if ( ! F_93 ( V_4 , V_155 + V_194 + V_178 + 2 ) )
{
F_14 ( V_250 , V_251 ) ;
goto V_210;
}
V_153 = ( unsigned char * ) & ( V_4 -> V_154 [ V_155 + V_194 ] ) ;
if ( ! ( V_3 -> V_86 & V_252 ) )
{
F_94 ( V_178 , V_153 ) ;
F_114 ( V_249 , & V_153 ) ;
V_194 += 2 + V_178 ;
V_245 += 2 + V_178 ;
}
else
{
V_163 = V_153 ;
F_114 ( V_249 , & V_153 ) ;
V_178 -= 2 ; F_94 ( V_178 , V_163 ) ; V_178 += 2 ;
V_194 += V_178 ;
V_245 += V_178 ;
}
}
}
V_153 = ( unsigned char * ) & ( V_4 -> V_154 [ V_155 + V_246 ] ) ;
F_94 ( V_245 , V_153 ) ;
V_163 = ( unsigned char * ) V_4 -> V_154 ;
* ( V_163 ++ ) = V_253 ;
F_115 ( V_194 , V_163 ) ;
F_94 ( V_3 -> V_18 -> V_59 , V_163 ) ;
V_3 -> V_18 -> V_59 ++ ;
V_3 -> V_38 = V_194 + V_155 ;
V_3 -> V_161 = 0 ;
#ifdef F_44
V_153 = ( unsigned char * ) V_3 -> V_35 -> V_154 + V_3 -> V_38 ;
* ( V_153 ++ ) = V_176 ;
* ( V_153 ++ ) = 0 ;
* ( V_153 ++ ) = 0 ;
* ( V_153 ++ ) = 0 ;
V_3 -> V_38 += 4 ;
#endif
V_151 = V_3 -> V_38 - V_155 ;
F_61 ( V_3 , ( void * ) V_3 -> V_35 -> V_154 ,
V_253 , V_151 , 0 , V_151 ) ;
F_68 ( V_3 , 0 ) ;
V_3 -> V_10 = V_100 ;
}
return ( F_62 ( V_3 , V_162 ) ) ;
V_210:
return ( - 1 ) ;
}
int F_36 ( T_2 * V_3 )
{
unsigned long V_166 ;
T_13 * V_254 ;
if ( V_3 -> V_10 == V_75 )
{
V_254 = F_116 ( V_3 ) ;
if ( V_254 == NULL )
{
if ( ( V_3 -> V_46 -> V_47 . V_77 -> V_80 != V_88 ) ||
( V_3 -> V_46 -> V_47 . V_77 -> V_78 != V_107 ) )
{
F_14 ( V_255 , V_34 ) ;
return ( 0 ) ;
}
}
V_166 = F_117 ( V_3 , V_254 ) ;
V_3 -> V_10 = V_76 ;
V_3 -> V_38 = ( int ) V_166 ;
V_3 -> V_161 = 0 ;
F_68 ( V_3 , 0 ) ;
}
return ( F_62 ( V_3 , V_162 ) ) ;
}
int F_53 ( T_2 * V_3 )
{
if ( V_3 -> V_10 == V_73 )
{
unsigned char * V_153 , * V_256 , * V_257 ;
int V_258 , V_259 ;
unsigned int V_260 , V_151 ;
T_14 V_17 ;
T_15 V_261 ;
T_16 * V_262 = V_3 -> V_263 ;
unsigned char V_264 [ V_265 ] ;
unsigned char V_266 [ 16 ] ;
V_259 = F_118 ( V_3 -> V_103 , NULL ) ;
if ( V_259 > 0xFF00 )
return - 1 ;
if ( ! F_18 ( V_3 -> V_35 ,
V_155 + 22 + V_265 +
V_267 + V_268 + V_259 ) )
return - 1 ;
V_256 = F_88 ( V_259 ) ;
if ( ! V_256 )
return - 1 ;
V_153 = V_256 ;
F_118 ( V_3 -> V_103 , & V_153 ) ;
V_153 = ( unsigned char * ) & ( V_3 -> V_35 -> V_154 [ V_155 ] ) ;
F_119 ( & V_17 ) ;
F_120 ( & V_261 ) ;
if ( V_262 -> V_269 )
{
if ( V_262 -> V_269 ( V_3 , V_266 , V_264 , & V_17 ,
& V_261 , 1 ) < 0 )
{
F_96 ( V_256 ) ;
return - 1 ;
}
}
else
{
F_64 ( V_264 , 16 ) ;
F_121 ( & V_17 , F_122 () , NULL ,
V_262 -> V_270 , V_264 ) ;
F_123 ( & V_261 , V_262 -> V_271 , 16 ,
F_124 () , NULL ) ;
memcpy ( V_266 , V_262 -> V_272 , 16 ) ;
}
F_63 ( V_3 -> V_103 -> V_273 , V_153 ) ;
V_153 += 2 ;
V_257 = V_153 ;
memcpy ( V_153 , V_266 , 16 ) ;
V_153 += 16 ;
memcpy ( V_153 , V_264 , F_125 ( & V_17 ) ) ;
V_153 += F_125 ( & V_17 ) ;
F_126 ( & V_17 , V_153 , & V_258 , V_256 , V_259 ) ;
V_153 += V_258 ;
F_127 ( & V_17 , V_153 , & V_258 ) ;
V_153 += V_258 ;
F_128 ( & V_17 ) ;
F_129 ( & V_261 , V_257 , V_153 - V_257 ) ;
F_130 ( & V_261 , V_153 , & V_260 ) ;
F_131 ( & V_261 ) ;
V_153 += V_260 ;
V_258 = V_153 - ( unsigned char * ) ( V_3 -> V_35 -> V_154 ) ;
V_153 = ( unsigned char * ) & ( V_3 -> V_35 -> V_154 [ V_155 ] ) + 4 ;
F_94 ( V_258 - V_155 - 6 , V_153 ) ;
V_3 -> V_38 = V_258 ;
V_3 -> V_10 = V_129 ;
V_3 -> V_161 = 0 ;
F_96 ( V_256 ) ;
V_151 = V_3 -> V_38 - V_155 ;
F_61 ( V_3 , ( void * ) V_3 -> V_35 -> V_154 ,
V_274 , V_151 , 0 , V_151 ) ;
F_68 ( V_3 , 0 ) ;
}
return ( F_62 ( V_3 , V_162 ) ) ;
}
