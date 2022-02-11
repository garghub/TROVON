static const T_1 * F_1 ( int V_1 )
{
if ( V_1 == V_2 || V_1 == V_3 )
return ( F_2 () ) ;
else if ( V_1 == V_4 )
return ( F_3 () ) ;
else
return ( NULL ) ;
}
int F_4 ( T_2 * V_5 )
{
T_3 * V_6 = NULL ;
unsigned long Time = ( unsigned long ) time ( NULL ) ;
void (* F_5) ( const T_2 * V_7 , int type , int V_8 ) = NULL ;
int V_9 = - 1 ;
int V_10 , V_11 , V_12 = 0 ;
#ifndef F_6
unsigned char V_13 [ 64 ] ;
char V_14 [ sizeof( V_15 ) ] ;
#endif
F_7 ( & Time , sizeof( Time ) , 0 ) ;
F_8 () ;
F_9 () ;
if ( V_5 -> V_16 != NULL )
F_5 = V_5 -> V_16 ;
else if ( V_5 -> V_17 -> V_16 != NULL )
F_5 = V_5 -> V_17 -> V_16 ;
V_5 -> V_18 ++ ;
if ( ! F_10 ( V_5 ) || F_11 ( V_5 ) )
F_12 ( V_5 ) ;
#ifndef F_6
F_13 ( F_14 ( V_5 ) , V_19 ,
V_5 -> V_18 , NULL ) ;
#endif
#ifndef F_15
if ( V_5 -> V_20 ) {
F_16 ( V_5 ) ;
V_5 -> V_20 = 0 ;
V_5 -> V_21 ++ ;
}
#endif
for (; ; ) {
V_11 = V_5 -> V_11 ;
switch ( V_5 -> V_11 ) {
case V_22 :
V_5 -> V_23 = 1 ;
V_5 -> V_11 = V_24 ;
V_5 -> V_17 -> V_25 . V_26 ++ ;
case V_27 :
case V_24 :
case V_27 | V_24 :
case V_28 | V_24 :
V_5 -> V_29 = 0 ;
if ( F_5 != NULL )
F_5 ( V_5 , V_30 , 1 ) ;
if ( ( V_5 -> V_31 & 0xff00 ) != ( V_2 & 0xff00 ) &&
( V_5 -> V_31 & 0xff00 ) != ( V_3 & 0xff00 ) ) {
F_17 ( V_32 , V_33 ) ;
V_9 = - 1 ;
goto V_34;
}
V_5 -> type = V_24 ;
if ( V_5 -> V_35 == NULL ) {
if ( ( V_6 = F_18 () ) == NULL ) {
V_9 = - 1 ;
goto V_34;
}
if ( ! F_19 ( V_6 , V_36 ) ) {
V_9 = - 1 ;
goto V_34;
}
V_5 -> V_35 = V_6 ;
V_6 = NULL ;
}
if ( ! F_20 ( V_5 ) ) {
V_9 = - 1 ;
goto V_34;
}
if ( ! F_21 ( V_5 , 0 ) ) {
V_9 = - 1 ;
goto V_34;
}
V_5 -> V_11 = V_37 ;
V_5 -> V_17 -> V_25 . V_38 ++ ;
V_5 -> V_39 = 0 ;
memset ( V_5 -> V_40 -> V_41 , 0 , sizeof( V_5 -> V_40 -> V_41 ) ) ;
V_5 -> V_42 -> V_43 = 0 ;
V_5 -> V_44 = 0 ;
V_5 -> V_42 -> V_45 = 0 ;
V_5 -> V_40 -> V_46 = 0 ;
break;
#ifndef F_6
case V_47 :
if ( F_22 ( F_23 ( V_5 ) ) ) {
V_5 -> V_40 -> V_48 = 2 ;
V_5 -> V_49 = V_50 ;
F_24 ( F_23 ( V_5 ) ) ;
F_25 ( F_23 ( V_5 ) ) ;
V_9 = - 1 ;
goto V_34;
}
V_5 -> V_11 = V_5 -> V_40 -> V_51 . V_52 ;
break;
case V_53 :
V_9 = F_26 ( F_14 ( V_5 ) ) ;
if ( V_9 < 0 )
goto V_34;
if ( V_9 == 0 ) {
V_5 -> V_40 -> V_48 = 2 ;
V_5 -> V_49 = V_50 ;
F_24 ( F_23 ( V_5 ) ) ;
F_25 ( F_23 ( V_5 ) ) ;
V_9 = - 1 ;
goto V_34;
}
V_5 -> V_11 = V_5 -> V_42 -> V_52 ;
break;
#endif
case V_37 :
case V_54 :
V_5 -> V_55 = 0 ;
F_27 ( V_5 ) ;
F_28 ( V_5 ) ;
V_9 = F_29 ( V_5 ) ;
if ( V_9 <= 0 )
goto V_34;
if ( V_5 -> V_42 -> V_43 ) {
V_5 -> V_11 = V_56 ;
V_5 -> V_40 -> V_51 . V_52 = V_57 ;
} else
V_5 -> V_11 = V_57 ;
V_5 -> V_39 = 0 ;
#ifndef F_6
if ( ! F_30 ( F_14 ( V_5 ) ) ) {
#endif
if ( V_5 -> V_58 != V_5 -> V_59 )
V_5 -> V_59 = F_31 ( V_5 -> V_58 , V_5 -> V_59 ) ;
#ifndef F_6
}
#endif
break;
case V_57 :
case V_60 :
V_9 = F_32 ( V_5 ) ;
if ( V_9 <= 0 )
goto V_34;
else {
if ( V_5 -> V_44 ) {
#ifndef F_6
snprintf ( ( char * ) V_14 ,
sizeof( V_15 ) ,
V_15 ) ;
F_33 ( V_5 , V_13 ,
sizeof( V_13 ) ,
V_14 ,
sizeof( V_14 ) , NULL , 0 ,
0 ) ;
F_13 ( F_14 ( V_5 ) ,
V_61 ,
sizeof( V_13 ) , V_13 ) ;
#endif
V_5 -> V_11 = V_62 ;
} else
V_5 -> V_11 = V_63 ;
}
V_5 -> V_39 = 0 ;
break;
case V_63 :
case V_64 :
V_9 = F_34 ( V_5 ) ;
if ( V_9 <= 0 )
goto V_34;
F_16 ( V_5 ) ;
if ( V_5 -> V_42 -> V_43 )
V_5 -> V_11 = V_37 ;
else
V_5 -> V_11 = V_65 ;
V_5 -> V_39 = 0 ;
break;
case V_65 :
case V_66 :
if ( ! ( V_5 -> V_40 -> V_51 . V_67 -> V_68 & V_69 ) &&
! ( V_5 -> V_40 -> V_51 . V_67 -> V_70 & V_71 ) ) {
V_9 = F_35 ( V_5 ) ;
if ( V_9 <= 0 )
goto V_34;
#ifndef F_36
if ( V_5 -> V_72 )
V_5 -> V_11 = V_73 ;
else
V_5 -> V_11 = V_74 ;
} else {
V_12 = 1 ;
V_5 -> V_11 = V_74 ;
}
#else
} else
V_12 = 1 ;
V_5 -> V_11 = V_74 ;
#endif
V_5 -> V_39 = 0 ;
break;
case V_74 :
case V_75 :
V_9 = F_37 ( V_5 ) ;
if ( V_9 <= 0 )
goto V_34;
V_5 -> V_11 = V_76 ;
V_5 -> V_39 = 0 ;
if ( ! F_38 ( V_5 ) ) {
V_9 = - 1 ;
goto V_34;
}
break;
case V_76 :
case V_77 :
V_9 = F_39 ( V_5 ) ;
if ( V_9 <= 0 )
goto V_34;
V_5 -> V_11 = V_78 ;
V_5 -> V_39 = 0 ;
break;
case V_78 :
case V_79 :
V_9 = F_40 ( V_5 ) ;
if ( V_9 <= 0 )
goto V_34;
F_16 ( V_5 ) ;
if ( V_5 -> V_40 -> V_51 . V_80 )
V_5 -> V_40 -> V_51 . V_52 = V_81 ;
else
V_5 -> V_40 -> V_51 . V_52 = V_82 ;
V_5 -> V_39 = 0 ;
#ifndef F_6
if ( F_30 ( F_14 ( V_5 ) ) &&
V_11 == V_22 )
V_5 -> V_11 = V_47 ;
else
#endif
V_5 -> V_11 = V_5 -> V_40 -> V_51 . V_52 ;
break;
case V_81 :
case V_83 :
case V_84 :
case V_85 :
F_28 ( V_5 ) ;
V_9 = F_41 ( V_5 ) ;
if ( V_9 <= 0 )
goto V_34;
V_5 -> V_11 = V_82 ;
V_5 -> V_39 = 0 ;
break;
case V_82 :
case V_86 :
F_28 ( V_5 ) ;
V_9 = F_42 ( V_5 ) ;
if ( V_9 <= 0 )
goto V_34;
#ifndef F_6
snprintf ( ( char * ) V_14 , sizeof( V_15 ) ,
V_15 ) ;
F_33 ( V_5 , V_13 ,
sizeof( V_13 ) , V_14 ,
sizeof( V_14 ) , NULL , 0 , 0 ) ;
F_13 ( F_14 ( V_5 ) , V_61 ,
sizeof( V_13 ) , V_13 ) ;
#endif
if ( V_5 -> V_40 -> V_51 . V_80 == 1 ) {
V_5 -> V_11 = V_87 ;
} else {
#ifndef F_6
if ( F_30 ( F_14 ( V_5 ) ) ) {
V_5 -> V_42 -> V_52 = V_88 ;
V_5 -> V_11 = V_53 ;
} else
#endif
V_5 -> V_11 = V_88 ;
}
V_5 -> V_39 = 0 ;
break;
case V_87 :
case V_89 :
F_28 ( V_5 ) ;
V_9 = F_43 ( V_5 ) ;
if ( V_9 <= 0 )
goto V_34;
#ifndef F_6
if ( F_30 ( F_14 ( V_5 ) ) ) {
V_5 -> V_42 -> V_52 = V_88 ;
V_5 -> V_11 = V_53 ;
} else
#endif
V_5 -> V_11 = V_88 ;
V_5 -> V_39 = 0 ;
break;
case V_88 :
case V_90 :
if ( ! V_5 -> V_44 )
F_28 ( V_5 ) ;
V_9 = F_44 ( V_5 ,
V_88 ,
V_90 ) ;
if ( V_9 <= 0 )
goto V_34;
V_5 -> V_11 = V_91 ;
V_5 -> V_39 = 0 ;
V_5 -> V_92 -> V_93 = V_5 -> V_40 -> V_51 . V_67 ;
#ifdef F_45
V_5 -> V_92 -> V_94 = 0 ;
#else
if ( V_5 -> V_40 -> V_51 . V_95 == NULL )
V_5 -> V_92 -> V_94 = 0 ;
else
V_5 -> V_92 -> V_94 = V_5 -> V_40 -> V_51 . V_95 -> V_96 ;
#endif
if ( ! V_5 -> V_97 -> V_98 -> V_99 ( V_5 ) ) {
V_9 = - 1 ;
goto V_34;
}
if ( ! V_5 -> V_97 -> V_98 -> V_100 ( V_5 ,
V_101 ) )
{
V_9 = - 1 ;
goto V_34;
}
#ifndef F_6
if ( V_5 -> V_44 ) {
F_13 ( F_14 ( V_5 ) , V_102 ,
0 , NULL ) ;
}
#endif
F_46 ( V_5 , V_103 ) ;
break;
case V_91 :
case V_104 :
if ( ! V_5 -> V_44 )
F_28 ( V_5 ) ;
V_9 = F_47 ( V_5 ,
V_91 ,
V_104 ,
V_5 -> V_97 ->
V_98 -> V_105 ,
V_5 -> V_97 ->
V_98 -> V_106 ) ;
if ( V_9 <= 0 )
goto V_34;
V_5 -> V_11 = V_56 ;
V_5 -> V_40 -> V_107 &= ~ V_108 ;
if ( V_5 -> V_44 ) {
V_5 -> V_40 -> V_51 . V_52 = V_28 ;
#ifndef F_6
if ( F_30 ( F_14 ( V_5 ) ) ) {
V_5 -> V_42 -> V_52 = V_5 -> V_40 -> V_51 . V_52 ;
V_5 -> V_40 -> V_51 . V_52 = V_53 ;
}
#endif
if ( V_5 -> V_40 -> V_107 & V_109 ) {
V_5 -> V_11 = V_28 ;
#ifndef F_6
if ( F_30 ( F_14 ( V_5 ) ) ) {
V_5 -> V_42 -> V_52 = V_28 ;
V_5 -> V_11 = V_53 ;
}
#endif
V_5 -> V_40 -> V_107 |= V_108 ;
V_5 -> V_40 -> V_110 = 0 ;
}
} else {
#ifndef F_6
F_13 ( F_14 ( V_5 ) , V_102 ,
0 , NULL ) ;
#endif
#ifndef F_36
if ( V_5 -> V_111 )
V_5 -> V_40 -> V_51 . V_52 = V_112 ;
else
#endif
V_5 -> V_40 -> V_51 . V_52 = V_62 ;
}
V_5 -> V_39 = 0 ;
break;
#ifndef F_36
case V_112 :
case V_113 :
V_9 = F_48 ( V_5 ) ;
if ( V_9 <= 0 )
goto V_34;
V_5 -> V_11 = V_62 ;
V_5 -> V_39 = 0 ;
break;
case V_73 :
case V_114 :
V_9 = F_49 ( V_5 ) ;
if ( V_9 <= 0 )
goto V_34;
V_5 -> V_11 = V_74 ;
V_5 -> V_39 = 0 ;
break;
#endif
case V_62 :
case V_115 :
V_5 -> V_42 -> V_45 = 1 ;
V_9 = F_50 ( V_5 , V_62 ,
V_115 ) ;
if ( V_9 <= 0 )
goto V_34;
F_16 ( V_5 ) ;
if ( V_5 -> V_44 )
V_5 -> V_11 = V_88 ;
else
V_5 -> V_11 = V_28 ;
#ifndef F_6
if ( F_30 ( F_14 ( V_5 ) ) &&
V_11 == V_22 ) {
V_5 -> V_42 -> V_52 = V_5 -> V_11 ;
V_5 -> V_11 = V_53 ;
}
#endif
V_5 -> V_39 = 0 ;
break;
case V_56 :
V_5 -> V_49 = V_116 ;
if ( F_51 ( V_5 -> V_59 ) <= 0 ) {
if ( ! F_52 ( V_5 -> V_59 ) ) {
V_5 -> V_49 = V_117 ;
V_5 -> V_11 = V_5 -> V_40 -> V_51 . V_52 ;
}
V_9 = - 1 ;
goto V_34;
}
V_5 -> V_49 = V_117 ;
V_5 -> V_11 = V_5 -> V_40 -> V_51 . V_52 ;
break;
case V_28 :
F_53 ( V_5 ) ;
#if 0
if (s->init_buf != NULL) {
BUF_MEM_free(s->init_buf);
s->init_buf = NULL;
}
#endif
if ( ! ( V_5 -> V_40 -> V_107 & V_108 ) )
F_54 ( V_5 ) ;
V_5 -> V_39 = 0 ;
V_5 -> V_23 = 0 ;
V_5 -> V_118 = 0 ;
F_55 ( V_5 , V_119 ) ;
if ( V_5 -> V_44 )
V_5 -> V_17 -> V_25 . V_120 ++ ;
V_9 = 1 ;
V_5 -> V_121 = F_4 ;
V_5 -> V_17 -> V_25 . V_122 ++ ;
if ( F_5 != NULL )
F_5 ( V_5 , V_123 , 1 ) ;
V_5 -> V_42 -> V_124 = 0 ;
V_5 -> V_42 -> V_125 = 0 ;
goto V_34;
default:
F_17 ( V_32 , V_126 ) ;
V_9 = - 1 ;
goto V_34;
}
if ( ! V_5 -> V_40 -> V_51 . V_127 && ! V_12 ) {
if ( V_5 -> V_128 ) {
if ( ( V_9 = F_51 ( V_5 -> V_59 ) ) <= 0 )
goto V_34;
}
if ( ( F_5 != NULL ) && ( V_5 -> V_11 != V_11 ) ) {
V_10 = V_5 -> V_11 ;
V_5 -> V_11 = V_11 ;
F_5 ( V_5 , V_129 , 1 ) ;
V_5 -> V_11 = V_10 ;
}
}
V_12 = 0 ;
}
int F_34 ( T_2 * V_5 )
{
int V_130 , V_131 , V_132 = 0 ;
unsigned char * V_133 ;
unsigned int V_134 ;
V_5 -> V_135 = 1 ;
V_130 = V_5 -> V_97 -> V_136 ( V_5 ,
V_63 ,
V_64 ,
- 1 , V_5 -> V_137 , & V_132 ) ;
V_5 -> V_135 = 0 ;
if ( ! V_132 )
return ( ( int ) V_130 ) ;
if ( V_5 -> V_40 -> V_51 . V_138 != V_139 ) {
V_5 -> V_42 -> V_43 = 0 ;
V_5 -> V_40 -> V_51 . V_127 = 1 ;
return ( 1 ) ;
}
V_133 = ( unsigned char * ) V_5 -> V_140 ;
#if 0
if (s->method->version != DTLS_ANY_VERSION &&
((data[0] != (s->version >> 8)) || (data[1] != (s->version & 0xff))))
{
SSLerr(SSL_F_DTLS1_GET_HELLO_VERIFY, SSL_R_WRONG_SSL_VERSION);
s->version = (s->version & 0xff00) | data[1];
al = SSL_AD_PROTOCOL_VERSION;
goto f_err;
}
#endif
V_133 += 2 ;
V_134 = * ( V_133 ++ ) ;
if ( V_134 > sizeof( V_5 -> V_42 -> V_141 ) ) {
V_131 = V_142 ;
goto V_143;
}
memcpy ( V_5 -> V_42 -> V_141 , V_133 , V_134 ) ;
V_5 -> V_42 -> V_134 = V_134 ;
V_5 -> V_42 -> V_43 = 1 ;
return 1 ;
V_143:
F_56 ( V_5 , V_144 , V_131 ) ;
return - 1 ;
}
