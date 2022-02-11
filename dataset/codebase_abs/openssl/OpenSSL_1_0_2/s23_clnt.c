static const T_1 * F_1 ( int V_1 )
{
#ifndef F_2
if ( V_1 == V_2 )
return ( F_3 () ) ;
#endif
#ifndef F_4
if ( V_1 == V_3 )
return ( F_5 () ) ;
#endif
if ( V_1 == V_4 )
return ( F_6 () ) ;
else if ( V_1 == V_5 )
return ( F_7 () ) ;
else if ( V_1 == V_6 )
return ( F_8 () ) ;
else
return ( NULL ) ;
}
int F_9 ( T_2 * V_7 )
{
T_3 * V_8 = NULL ;
unsigned long Time = ( unsigned long ) time ( NULL ) ;
void (* F_10) ( const T_2 * V_9 , int type , int V_10 ) = NULL ;
int V_11 = - 1 ;
int V_12 , V_13 ;
F_11 ( & Time , sizeof( Time ) , 0 ) ;
F_12 () ;
F_13 () ;
if ( V_7 -> V_14 != NULL )
F_10 = V_7 -> V_14 ;
else if ( V_7 -> V_15 -> V_14 != NULL )
F_10 = V_7 -> V_15 -> V_14 ;
V_7 -> V_16 ++ ;
if ( ! F_14 ( V_7 ) || F_15 ( V_7 ) )
F_16 ( V_7 ) ;
for (; ; ) {
V_13 = V_7 -> V_13 ;
switch ( V_7 -> V_13 ) {
case V_17 :
case V_18 :
case V_17 | V_18 :
case V_19 | V_18 :
if ( V_7 -> V_20 != NULL ) {
F_17 ( V_21 ,
V_22 ) ;
V_11 = - 1 ;
goto V_23;
}
V_7 -> V_24 = 0 ;
if ( F_10 != NULL )
F_10 ( V_7 , V_25 , 1 ) ;
V_7 -> type = V_18 ;
if ( V_7 -> V_26 == NULL ) {
if ( ( V_8 = F_18 () ) == NULL ) {
V_11 = - 1 ;
goto V_23;
}
if ( ! F_19 ( V_8 , V_27 ) ) {
V_11 = - 1 ;
goto V_23;
}
V_7 -> V_26 = V_8 ;
V_8 = NULL ;
}
if ( ! F_20 ( V_7 ) ) {
V_11 = - 1 ;
goto V_23;
}
F_21 ( V_7 ) ;
V_7 -> V_13 = V_28 ;
V_7 -> V_15 -> V_29 . V_30 ++ ;
V_7 -> V_31 = 0 ;
break;
case V_28 :
case V_32 :
V_7 -> V_33 = 0 ;
V_11 = F_22 ( V_7 ) ;
if ( V_11 <= 0 )
goto V_23;
V_7 -> V_13 = V_34 ;
V_7 -> V_31 = 0 ;
break;
case V_34 :
case V_35 :
V_11 = F_23 ( V_7 ) ;
if ( V_11 >= 0 )
F_10 = NULL ;
goto V_23;
default:
F_17 ( V_21 , V_36 ) ;
V_11 = - 1 ;
goto V_23;
}
if ( V_7 -> V_37 ) {
( void ) F_24 ( V_7 -> V_38 ) ;
}
if ( ( F_10 != NULL ) && ( V_7 -> V_13 != V_13 ) ) {
V_12 = V_7 -> V_13 ;
V_7 -> V_13 = V_13 ;
F_10 ( V_7 , V_39 , 1 ) ;
V_7 -> V_13 = V_12 ;
}
}
V_23:
V_7 -> V_16 -- ;
if ( V_8 != NULL )
F_25 ( V_8 ) ;
if ( F_10 != NULL )
F_10 ( V_7 , V_40 , V_11 ) ;
return ( V_11 ) ;
}
static int F_26 ( T_2 * V_7 )
{
T_4 * V_41 ;
F_27 ( T_4 ) * V_42 ;
int V_43 ;
V_42 = F_28 ( V_7 ) ;
for ( V_43 = 0 ; V_43 < F_29 ( V_42 ) ; V_43 ++ ) {
V_41 = F_30 ( V_42 , V_43 ) ;
if ( V_41 -> V_44 == V_45 )
return 0 ;
}
return 1 ;
}
int F_31 ( T_2 * V_7 , int V_24 , unsigned char * V_46 , int V_47 )
{
int V_48 = 0 ;
if ( V_47 < 4 )
return 0 ;
if ( V_24 )
V_48 = ( V_7 -> V_49 & V_50 ) != 0 ;
else
V_48 = ( V_7 -> V_49 & V_51 ) != 0 ;
if ( V_48 ) {
unsigned long Time = ( unsigned long ) time ( NULL ) ;
unsigned char * V_52 = V_46 ;
F_32 ( Time , V_52 ) ;
return F_33 ( V_52 , V_47 - 4 ) ;
} else
return F_33 ( V_46 , V_47 ) ;
}
static int F_22 ( T_2 * V_7 )
{
unsigned char * V_8 ;
unsigned char * V_52 , * V_53 ;
int V_43 , V_54 ;
unsigned long V_55 ;
int V_56 ;
int V_57 = 0 , V_58 , V_59 ;
int V_60 = 0 ;
#ifndef F_34
int V_61 ;
T_5 * V_62 ;
#endif
int V_11 ;
unsigned long V_63 , V_64 = V_7 -> V_64 ;
V_56 = ( V_64 & V_65 ) ? 0 : 1 ;
if ( V_56 && F_26 ( V_7 ) )
V_56 = 0 ;
V_63 = V_66 | V_67
#if ! F_35 ( F_4 )
| V_68
#endif
#if ! F_35 ( F_2 )
| ( V_56 ? V_65 : 0 )
#endif
;
#if ! F_35 ( V_69 )
V_57 = V_6 ;
if ( ( V_64 & V_70 ) && ( V_64 & V_63 ) != V_63 )
V_57 = V_5 ;
#else
V_57 = V_5 ;
#endif
V_63 &= ~ V_66 ;
if ( ( V_64 & V_66 ) && ( V_64 & V_63 ) != V_63 )
V_57 = V_4 ;
V_63 &= ~ V_67 ;
#if ! F_35 ( F_4 )
if ( ( V_64 & V_67 ) && ( V_64 & V_63 ) != V_63 )
V_57 = V_3 ;
V_63 &= ~ V_68 ;
#endif
#if ! F_35 ( F_2 )
if ( ( V_64 & V_68 ) && ( V_64 & V_63 ) != V_63 )
V_57 = V_2 ;
#endif
#ifndef F_36
if ( V_57 != V_2 ) {
if ( V_7 -> V_71 != NULL )
V_56 = 0 ;
if ( V_7 -> V_72 != - 1 )
V_56 = 0 ;
# ifdef F_37
if ( V_7 -> V_15 -> V_73 != 0
|| V_7 -> V_74 != NULL )
V_56 = 0 ;
# endif
if ( V_7 -> V_75 -> V_76 . V_77 != 0 )
V_56 = 0 ;
}
#endif
V_8 = ( unsigned char * ) V_7 -> V_26 -> V_78 ;
if ( V_7 -> V_13 == V_28 ) {
#if 0
if (!ssl_get_new_session(s, 0)) {
return (-1);
}
#endif
V_52 = V_7 -> V_79 -> V_80 ;
if ( F_31 ( V_7 , 0 , V_52 , V_81 ) <= 0 )
return - 1 ;
if ( V_57 == V_6 ) {
V_58 = V_82 ;
V_59 = V_83 ;
} else if ( F_38 ( V_7 ) ) {
F_17 ( V_84 ,
V_85 ) ;
return - 1 ;
} else if ( V_57 == V_5 ) {
V_58 = V_86 ;
V_59 = V_87 ;
} else if ( V_57 == V_4 ) {
V_58 = V_88 ;
V_59 = V_89 ;
}
#ifdef F_39
else if ( F_40 () ) {
F_17 ( V_84 ,
V_90 ) ;
return - 1 ;
}
#endif
else if ( V_57 == V_3 ) {
V_58 = V_91 ;
V_59 = V_92 ;
} else if ( V_57 == V_2 ) {
V_58 = V_93 ;
V_59 = V_94 ;
} else {
F_17 ( V_84 , V_95 ) ;
return ( - 1 ) ;
}
V_7 -> V_96 = V_57 ;
if ( V_56 ) {
V_53 = & ( V_8 [ 2 ] ) ;
V_52 = V_53 + 9 ;
* ( V_53 ++ ) = V_97 ;
* ( V_53 ++ ) = V_58 ;
* ( V_53 ++ ) = V_59 ;
V_43 = F_41 ( V_7 , F_28 ( V_7 ) , V_52 , 0 ) ;
if ( V_43 == 0 ) {
F_17 ( V_84 , V_98 ) ;
return - 1 ;
}
F_42 ( V_43 , V_53 ) ;
V_52 += V_43 ;
#if 0
s->session->session_id_length = 0;
#endif
F_42 ( 0 , V_53 ) ;
if ( V_7 -> V_64 & V_99 )
V_54 = V_100 ;
else
V_54 = V_101 ;
if ( V_81 < V_54 )
V_43 = V_81 ;
else
V_43 = V_54 ;
F_42 ( V_43 , V_53 ) ;
memset ( & ( V_7 -> V_79 -> V_80 [ 0 ] ) , 0 , V_81 ) ;
if ( F_33
( & ( V_7 -> V_79 -> V_80 [ V_81 - V_43 ] ) , V_43 ) <= 0 )
return - 1 ;
memcpy ( V_52 , & ( V_7 -> V_79 -> V_80 [ V_81 - V_43 ] ) , V_43 ) ;
V_52 += V_43 ;
V_43 = V_52 - & ( V_8 [ 2 ] ) ;
V_8 [ 0 ] = ( ( V_43 >> 8 ) & 0xff ) | 0x80 ;
V_8 [ 1 ] = ( V_43 & 0xff ) ;
V_7 -> V_31 = V_43 + 2 ;
V_7 -> V_102 = 0 ;
F_43 ( V_7 , & ( V_8 [ 2 ] ) , V_43 ) ;
} else {
V_53 = V_52 = & ( V_8 [ 9 ] ) ;
* ( V_52 ++ ) = V_58 ;
* ( V_52 ++ ) = V_59 ;
memcpy ( V_52 , V_7 -> V_79 -> V_80 , V_81 ) ;
V_52 += V_81 ;
* ( V_52 ++ ) = 0 ;
V_43 = F_41 ( V_7 , F_28 ( V_7 ) , & ( V_52 [ 2 ] ) ,
V_103 ) ;
if ( V_43 == 0 ) {
F_17 ( V_84 , V_98 ) ;
return - 1 ;
}
#ifdef F_44
if ( F_45 ( V_7 ) >= V_6
&& V_43 > F_44 )
V_43 = F_44 & ~ 1 ;
#endif
F_42 ( V_43 , V_52 ) ;
V_52 += V_43 ;
#ifdef F_34
* ( V_52 ++ ) = 1 ;
#else
if ( ( V_7 -> V_64 & V_104 )
|| ! V_7 -> V_15 -> V_105 )
V_61 = 0 ;
else
V_61 = F_46 ( V_7 -> V_15 -> V_105 ) ;
* ( V_52 ++ ) = 1 + V_61 ;
for ( V_43 = 0 ; V_43 < V_61 ; V_43 ++ ) {
V_62 = F_47 ( V_7 -> V_15 -> V_105 , V_43 ) ;
* ( V_52 ++ ) = V_62 -> V_106 ;
}
#endif
* ( V_52 ++ ) = 0 ;
#ifndef F_36
if ( F_48 ( V_7 ) <= 0 ) {
F_17 ( V_84 , V_107 ) ;
return - 1 ;
}
if ( ( V_52 =
F_49 ( V_7 , V_52 ,
V_8 + V_27 ,
& V_60 ) ) == NULL ) {
F_50 ( V_7 , V_108 , V_60 ) ;
F_17 ( V_84 , V_109 ) ;
return - 1 ;
}
#endif
V_55 = V_52 - V_53 ;
V_53 = & ( V_8 [ 5 ] ) ;
* ( V_53 ++ ) = V_110 ;
F_51 ( V_55 , V_53 ) ;
V_55 += 4 ;
if ( V_55 > V_27 ) {
F_17 ( V_84 , V_109 ) ;
return - 1 ;
}
V_53 = V_8 ;
* ( V_53 ++ ) = V_111 ;
* ( V_53 ++ ) = V_58 ;
if ( F_52 ( V_7 ) > V_4 )
* ( V_53 ++ ) = 1 ;
else
* ( V_53 ++ ) = V_59 ;
F_42 ( ( int ) V_55 , V_53 ) ;
V_7 -> V_31 = V_52 - V_8 ;
V_7 -> V_102 = 0 ;
F_43 ( V_7 , & ( V_8 [ 5 ] ) , V_7 -> V_31 - 5 ) ;
}
V_7 -> V_13 = V_32 ;
V_7 -> V_102 = 0 ;
}
V_11 = F_53 ( V_7 ) ;
if ( ( V_11 >= 2 ) && V_7 -> V_112 ) {
if ( V_56 )
V_7 -> V_112 ( 1 , V_2 , 0 , V_7 -> V_26 -> V_78 + 2 ,
V_11 - 2 , V_7 , V_7 -> V_113 ) ;
else {
V_7 -> V_112 ( 1 , V_57 , V_114 , V_7 -> V_26 -> V_78 , 5 ,
V_7 , V_7 -> V_113 ) ;
V_7 -> V_112 ( 1 , V_57 , V_111 ,
V_7 -> V_26 -> V_78 + 5 , V_11 - 5 , V_7 ,
V_7 -> V_113 ) ;
}
}
return V_11 ;
}
static int F_23 ( T_2 * V_7 )
{
char V_8 [ 8 ] ;
unsigned char * V_52 ;
int V_43 ;
int V_115 ;
V_115 = F_54 ( V_7 , 7 ) ;
if ( V_115 != 7 )
return ( V_115 ) ;
V_52 = V_7 -> V_116 ;
memcpy ( V_8 , V_52 , V_115 ) ;
if ( ( V_52 [ 0 ] & 0x80 ) && ( V_52 [ 2 ] == V_117 ) &&
( V_52 [ 5 ] == 0x00 ) && ( V_52 [ 6 ] == 0x02 ) ) {
#ifdef F_2
F_17 ( V_118 , V_119 ) ;
goto V_120;
#else
int V_54 ;
if ( V_7 -> V_64 & V_65 ) {
F_17 ( V_118 , V_119 ) ;
goto V_120;
}
if ( V_7 -> V_121 == NULL ) {
if ( ! F_55 ( V_7 ) )
goto V_120;
} else
F_56 ( V_7 ) ;
if ( V_7 -> V_64 & V_99 )
V_54 = V_100 ;
else
V_54 = V_101 ;
V_43 = ( V_81 < V_54 )
? V_81 : V_54 ;
V_7 -> V_121 -> V_122 = V_43 ;
memcpy ( V_7 -> V_121 -> V_123 ,
& ( V_7 -> V_79 -> V_80 [ V_81 - V_43 ] ) , V_43 ) ;
if ( V_7 -> V_79 != NULL )
F_57 ( V_7 ) ;
if ( ! F_58 ( V_7 -> V_26 ,
V_124 ) ) {
F_17 ( V_118 , V_125 ) ;
goto V_120;
}
V_7 -> V_13 = V_126 ;
if ( ! ( V_7 -> V_96 == V_2 ) )
V_7 -> V_121 -> V_127 = 1 ;
V_7 -> V_128 = V_129 ;
V_7 -> V_130 = V_115 ;
V_7 -> V_116 = & ( V_7 -> V_121 -> V_131 [ 0 ] ) ;
memcpy ( V_7 -> V_116 , V_8 , V_115 ) ;
V_7 -> V_121 -> V_132 = V_115 ;
V_7 -> V_121 -> V_133 = 0 ;
V_7 -> V_121 -> V_134 = 1 ;
V_7 -> V_135 = F_3 () ;
V_7 -> V_136 = V_7 -> V_135 -> V_137 ;
#endif
} else if ( V_52 [ 1 ] == V_91 &&
V_52 [ 2 ] <= V_83 &&
( ( V_52 [ 0 ] == V_111 && V_52 [ 5 ] == V_138 ) ||
( V_52 [ 0 ] == V_139 && V_52 [ 3 ] == 0 && V_52 [ 4 ] == 2 ) ) ) {
#ifndef F_4
if ( ( V_52 [ 2 ] == V_92 ) && ! ( V_7 -> V_64 & V_68 ) ) {
# ifdef F_39
if ( F_40 () ) {
F_17 ( V_118 ,
V_90 ) ;
goto V_120;
}
# endif
V_7 -> V_57 = V_3 ;
V_7 -> V_135 = F_5 () ;
} else
#endif
if ( ( V_52 [ 2 ] == V_89 ) && ! ( V_7 -> V_64 & V_67 ) ) {
V_7 -> V_57 = V_4 ;
V_7 -> V_135 = F_6 () ;
} else if ( ( V_52 [ 2 ] == V_87 ) &&
! ( V_7 -> V_64 & V_66 ) ) {
V_7 -> V_57 = V_5 ;
V_7 -> V_135 = F_7 () ;
} else if ( ( V_52 [ 2 ] == V_83 ) &&
! ( V_7 -> V_64 & V_70 ) ) {
V_7 -> V_57 = V_6 ;
V_7 -> V_135 = F_8 () ;
} else {
F_17 ( V_118 , V_119 ) ;
goto V_120;
}
F_59 ( V_7 -> V_57 <= V_140 ) ;
if ( V_52 [ 0 ] == V_139 && V_52 [ 5 ] != V_141 ) {
void (* F_10) ( const T_2 * V_9 , int type , int V_10 ) = NULL ;
int V_61 ;
if ( V_7 -> V_14 != NULL )
F_10 = V_7 -> V_14 ;
else if ( V_7 -> V_15 -> V_14 != NULL )
F_10 = V_7 -> V_15 -> V_14 ;
V_43 = V_52 [ 5 ] ;
if ( F_10 != NULL ) {
V_61 = ( V_43 << 8 ) | V_52 [ 6 ] ;
F_10 ( V_7 , V_142 , V_61 ) ;
}
if ( V_7 -> V_112 ) {
V_7 -> V_112 ( 0 , V_7 -> V_57 , V_114 , V_52 , 5 , V_7 ,
V_7 -> V_113 ) ;
V_7 -> V_112 ( 0 , V_7 -> V_57 , V_139 , V_52 + 5 , 2 , V_7 ,
V_7 -> V_113 ) ;
}
V_7 -> V_143 = V_144 ;
F_17 ( V_118 , V_145 + V_52 [ 6 ] ) ;
goto V_120;
}
if ( ! F_60 ( V_7 , 1 ) )
goto V_120;
V_7 -> V_13 = V_146 ;
V_7 -> V_128 = V_129 ;
V_7 -> V_130 = V_115 ;
if ( V_7 -> V_79 -> V_131 . V_8 == NULL )
if ( ! F_61 ( V_7 ) )
goto V_120;
V_7 -> V_116 = & ( V_7 -> V_79 -> V_131 . V_8 [ 0 ] ) ;
memcpy ( V_7 -> V_116 , V_8 , V_115 ) ;
V_7 -> V_79 -> V_131 . V_147 = V_115 ;
V_7 -> V_79 -> V_131 . V_148 = 0 ;
V_7 -> V_136 = V_7 -> V_135 -> V_137 ;
} else {
F_17 ( V_118 , V_149 ) ;
goto V_120;
}
V_7 -> V_31 = 0 ;
if ( ! F_62 ( V_7 , 0 ) )
goto V_120;
return ( F_63 ( V_7 ) ) ;
V_120:
return ( - 1 ) ;
}
