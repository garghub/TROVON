static const T_1 * F_1 ( int V_1 )
{
#ifndef F_2
if ( V_1 == V_2 )
return ( F_3 () ) ;
#endif
if ( V_1 == V_3 )
return ( F_4 () ) ;
else if ( V_1 == V_4 )
return ( F_5 () ) ;
else if ( V_1 == V_5 )
return ( F_6 () ) ;
else if ( V_1 == V_6 )
return ( F_7 () ) ;
else
return ( NULL ) ;
}
int F_8 ( T_2 * V_7 )
{
T_3 * V_8 = NULL ;
unsigned long Time = ( unsigned long ) time ( NULL ) ;
void (* F_9)( const T_2 * V_9 , int type , int V_10 ) = NULL ;
int V_11 = - 1 ;
int V_12 , V_13 ;
F_10 ( & Time , sizeof( Time ) , 0 ) ;
F_11 () ;
F_12 () ;
if ( V_7 -> V_14 != NULL )
F_9 = V_7 -> V_14 ;
else if ( V_7 -> V_15 -> V_14 != NULL )
F_9 = V_7 -> V_15 -> V_14 ;
V_7 -> V_16 ++ ;
if ( ! F_13 ( V_7 ) || F_14 ( V_7 ) ) F_15 ( V_7 ) ;
for (; ; )
{
V_13 = V_7 -> V_13 ;
switch( V_7 -> V_13 )
{
case V_17 :
case V_18 :
case V_17 | V_18 :
case V_19 | V_18 :
if ( V_7 -> V_20 != NULL )
{
F_16 ( V_21 , V_22 ) ;
V_11 = - 1 ;
goto V_23;
}
V_7 -> V_24 = 0 ;
if ( F_9 != NULL ) F_9 ( V_7 , V_25 , 1 ) ;
V_7 -> type = V_18 ;
if ( V_7 -> V_26 == NULL )
{
if ( ( V_8 = F_17 () ) == NULL )
{
V_11 = - 1 ;
goto V_23;
}
if ( ! F_18 ( V_8 , V_27 ) )
{
V_11 = - 1 ;
goto V_23;
}
V_7 -> V_26 = V_8 ;
V_8 = NULL ;
}
if ( ! F_19 ( V_7 ) ) { V_11 = - 1 ; goto V_23; }
F_20 ( V_7 ) ;
V_7 -> V_13 = V_28 ;
V_7 -> V_15 -> V_29 . V_30 ++ ;
V_7 -> V_31 = 0 ;
break;
case V_28 :
case V_32 :
V_7 -> V_33 = 0 ;
V_11 = F_21 ( V_7 ) ;
if ( V_11 <= 0 ) goto V_23;
V_7 -> V_13 = V_34 ;
V_7 -> V_31 = 0 ;
break;
case V_34 :
case V_35 :
V_11 = F_22 ( V_7 ) ;
if ( V_11 >= 0 ) F_9 = NULL ;
goto V_23;
default:
F_16 ( V_21 , V_36 ) ;
V_11 = - 1 ;
goto V_23;
}
if ( V_7 -> V_37 ) { ( void ) F_23 ( V_7 -> V_38 ) ; }
if ( ( F_9 != NULL ) && ( V_7 -> V_13 != V_13 ) )
{
V_12 = V_7 -> V_13 ;
V_7 -> V_13 = V_13 ;
F_9 ( V_7 , V_39 , 1 ) ;
V_7 -> V_13 = V_12 ;
}
}
V_23:
V_7 -> V_16 -- ;
if ( V_8 != NULL )
F_24 ( V_8 ) ;
if ( F_9 != NULL )
F_9 ( V_7 , V_40 , V_11 ) ;
return ( V_11 ) ;
}
static int F_25 ( T_2 * V_7 )
{
T_4 * V_41 ;
F_26 ( T_4 ) * V_42 ;
int V_43 ;
V_42 = F_27 ( V_7 ) ;
for ( V_43 = 0 ; V_43 < F_28 ( V_42 ) ; V_43 ++ )
{
V_41 = F_29 ( V_42 , V_43 ) ;
if ( V_41 -> V_44 == V_45 )
return 0 ;
}
return 1 ;
}
static int F_21 ( T_2 * V_7 )
{
unsigned char * V_8 ;
unsigned char * V_46 , * V_47 ;
int V_43 , V_48 ;
unsigned long Time , V_49 ;
int V_50 ;
int V_51 = 0 , V_52 , V_53 ;
#ifndef F_30
int V_54 ;
T_5 * V_55 ;
#endif
int V_11 ;
V_50 = ( V_7 -> V_56 & V_57 ) ? 0 : 1 ;
if ( V_50 && F_25 ( V_7 ) )
V_50 = 0 ;
if ( ! ( V_7 -> V_56 & V_58 ) )
{
V_51 = V_6 ;
}
else if ( ! ( V_7 -> V_56 & V_59 ) )
{
V_51 = V_5 ;
}
else if ( ! ( V_7 -> V_56 & V_60 ) )
{
V_51 = V_4 ;
}
else if ( ! ( V_7 -> V_56 & V_61 ) )
{
V_51 = V_3 ;
}
else if ( ! ( V_7 -> V_56 & V_57 ) )
{
V_51 = V_2 ;
}
#ifndef F_31
if ( V_51 != V_2 )
{
if ( V_7 -> V_62 != NULL )
V_50 = 0 ;
if ( V_7 -> V_63 != - 1 )
V_50 = 0 ;
#ifdef F_32
if ( V_7 -> V_15 -> V_64 != 0 || V_7 -> V_65 != NULL )
V_50 = 0 ;
#endif
}
#endif
V_8 = ( unsigned char * ) V_7 -> V_26 -> V_66 ;
if ( V_7 -> V_13 == V_28 )
{
#if 0
if (!ssl_get_new_session(s,0))
{
return(-1);
}
#endif
V_46 = V_7 -> V_67 -> V_68 ;
Time = ( unsigned long ) time ( NULL ) ;
F_33 ( Time , V_46 ) ;
if ( F_34 ( V_46 , V_69 - 4 ) <= 0 )
return - 1 ;
if ( V_51 == V_6 )
{
V_52 = V_70 ;
V_53 = V_71 ;
}
else if ( V_51 == V_5 )
{
V_52 = V_72 ;
V_53 = V_73 ;
}
else if ( V_51 == V_4 )
{
V_52 = V_74 ;
V_53 = V_75 ;
}
#ifdef F_35
else if( F_36 () )
{
F_16 ( V_76 ,
V_77 ) ;
return - 1 ;
}
#endif
else if ( V_51 == V_3 )
{
V_52 = V_78 ;
V_53 = V_79 ;
}
else if ( V_51 == V_2 )
{
V_52 = V_80 ;
V_53 = V_81 ;
}
else
{
F_16 ( V_76 , V_82 ) ;
return ( - 1 ) ;
}
V_7 -> V_83 = V_51 ;
if ( V_50 )
{
V_47 = & ( V_8 [ 2 ] ) ;
V_46 = V_47 + 9 ;
* ( V_47 ++ ) = V_84 ;
* ( V_47 ++ ) = V_52 ;
* ( V_47 ++ ) = V_53 ;
V_43 = F_37 ( V_7 , F_27 ( V_7 ) , V_46 , 0 ) ;
if ( V_43 == 0 )
{
F_16 ( V_76 , V_85 ) ;
return - 1 ;
}
F_38 ( V_43 , V_47 ) ;
V_46 += V_43 ;
#if 0
s->session->session_id_length=0;
#endif
F_38 ( 0 , V_47 ) ;
if ( V_7 -> V_56 & V_86 )
V_48 = V_87 ;
else
V_48 = V_88 ;
if ( V_69 < V_48 )
V_43 = V_69 ;
else
V_43 = V_48 ;
F_38 ( V_43 , V_47 ) ;
memset ( & ( V_7 -> V_67 -> V_68 [ 0 ] ) , 0 , V_69 ) ;
if ( F_34 ( & ( V_7 -> V_67 -> V_68 [ V_69 - V_43 ] ) , V_43 ) <= 0 )
return - 1 ;
memcpy ( V_46 , & ( V_7 -> V_67 -> V_68 [ V_69 - V_43 ] ) , V_43 ) ;
V_46 += V_43 ;
V_43 = V_46 - & ( V_8 [ 2 ] ) ;
V_8 [ 0 ] = ( ( V_43 >> 8 ) & 0xff ) | 0x80 ;
V_8 [ 1 ] = ( V_43 & 0xff ) ;
V_7 -> V_31 = V_43 + 2 ;
V_7 -> V_89 = 0 ;
F_39 ( V_7 , & ( V_8 [ 2 ] ) , V_43 ) ;
}
else
{
V_47 = V_46 = & ( V_8 [ 9 ] ) ;
* ( V_46 ++ ) = V_52 ;
* ( V_46 ++ ) = V_53 ;
memcpy ( V_46 , V_7 -> V_67 -> V_68 , V_69 ) ;
V_46 += V_69 ;
* ( V_46 ++ ) = 0 ;
V_43 = F_37 ( V_7 , F_27 ( V_7 ) , & ( V_46 [ 2 ] ) , V_90 ) ;
if ( V_43 == 0 )
{
F_16 ( V_76 , V_85 ) ;
return - 1 ;
}
F_38 ( V_43 , V_46 ) ;
V_46 += V_43 ;
#ifdef F_30
* ( V_46 ++ ) = 1 ;
#else
if ( ( V_7 -> V_56 & V_91 )
|| ! V_7 -> V_15 -> V_92 )
V_54 = 0 ;
else
V_54 = F_40 ( V_7 -> V_15 -> V_92 ) ;
* ( V_46 ++ ) = 1 + V_54 ;
for ( V_43 = 0 ; V_43 < V_54 ; V_43 ++ )
{
V_55 = F_41 ( V_7 -> V_15 -> V_92 , V_43 ) ;
* ( V_46 ++ ) = V_55 -> V_93 ;
}
#endif
* ( V_46 ++ ) = 0 ;
#ifndef F_31
if ( F_42 ( V_7 ) <= 0 )
{
F_16 ( V_76 , V_94 ) ;
return - 1 ;
}
if ( ( V_46 = F_43 ( V_7 , V_46 , V_8 + V_27 ) ) == NULL )
{
F_16 ( V_76 , V_95 ) ;
return - 1 ;
}
#endif
V_49 = V_46 - V_47 ;
V_47 = & ( V_8 [ 5 ] ) ;
* ( V_47 ++ ) = V_96 ;
F_44 ( V_49 , V_47 ) ;
V_49 += 4 ;
if ( V_49 > V_27 )
{
F_16 ( V_76 , V_95 ) ;
return - 1 ;
}
V_47 = V_8 ;
* ( V_47 ++ ) = V_97 ;
* ( V_47 ++ ) = V_52 ;
* ( V_47 ++ ) = V_53 ;
F_38 ( ( int ) V_49 , V_47 ) ;
V_7 -> V_31 = V_46 - V_8 ;
V_7 -> V_89 = 0 ;
F_39 ( V_7 , & ( V_8 [ 5 ] ) , V_7 -> V_31 - 5 ) ;
}
V_7 -> V_13 = V_32 ;
V_7 -> V_89 = 0 ;
}
V_11 = F_45 ( V_7 ) ;
if ( ( V_11 >= 2 ) && V_7 -> V_98 )
{
if ( V_50 )
V_7 -> V_98 ( 1 , V_2 , 0 , V_7 -> V_26 -> V_66 + 2 , V_11 - 2 , V_7 , V_7 -> V_99 ) ;
else
V_7 -> V_98 ( 1 , V_51 , V_97 , V_7 -> V_26 -> V_66 + 5 , V_11 - 5 , V_7 , V_7 -> V_99 ) ;
}
return V_11 ;
}
static int F_22 ( T_2 * V_7 )
{
char V_8 [ 8 ] ;
unsigned char * V_46 ;
int V_43 ;
int V_100 ;
V_100 = F_46 ( V_7 , 7 ) ;
if ( V_100 != 7 ) return ( V_100 ) ;
V_46 = V_7 -> V_101 ;
memcpy ( V_8 , V_46 , V_100 ) ;
if ( ( V_46 [ 0 ] & 0x80 ) && ( V_46 [ 2 ] == V_102 ) &&
( V_46 [ 5 ] == 0x00 ) && ( V_46 [ 6 ] == 0x02 ) )
{
#ifdef F_2
F_16 ( V_103 , V_104 ) ;
goto V_105;
#else
int V_48 ;
if ( V_7 -> V_56 & V_57 )
{
F_16 ( V_103 , V_104 ) ;
goto V_105;
}
if ( V_7 -> V_106 == NULL )
{
if ( ! F_47 ( V_7 ) )
goto V_105;
}
else
F_48 ( V_7 ) ;
if ( V_7 -> V_56 & V_86 )
V_48 = V_87 ;
else
V_48 = V_88 ;
V_43 = ( V_69 < V_48 )
? V_69 : V_48 ;
V_7 -> V_106 -> V_107 = V_43 ;
memcpy ( V_7 -> V_106 -> V_108 ,
& ( V_7 -> V_67 -> V_68 [ V_69 - V_43 ] ) , V_43 ) ;
if ( V_7 -> V_67 != NULL ) F_49 ( V_7 ) ;
if ( ! F_50 ( V_7 -> V_26 ,
V_109 ) )
{
F_16 ( V_103 , V_110 ) ;
goto V_105;
}
V_7 -> V_13 = V_111 ;
if ( ! ( V_7 -> V_83 == V_2 ) )
V_7 -> V_106 -> V_112 = 1 ;
V_7 -> V_113 = V_114 ;
V_7 -> V_115 = V_100 ;
V_7 -> V_101 = & ( V_7 -> V_106 -> V_116 [ 0 ] ) ;
memcpy ( V_7 -> V_101 , V_8 , V_100 ) ;
V_7 -> V_106 -> V_117 = V_100 ;
V_7 -> V_106 -> V_118 = 0 ;
V_7 -> V_106 -> V_119 = 1 ;
V_7 -> V_120 = F_3 () ;
V_7 -> V_121 = V_7 -> V_120 -> V_122 ;
#endif
}
else if ( V_46 [ 1 ] == V_78 &&
V_46 [ 2 ] <= V_71 &&
( ( V_46 [ 0 ] == V_97 && V_46 [ 5 ] == V_123 ) ||
( V_46 [ 0 ] == V_124 && V_46 [ 3 ] == 0 && V_46 [ 4 ] == 2 ) ) )
{
if ( ( V_46 [ 2 ] == V_79 ) &&
! ( V_7 -> V_56 & V_61 ) )
{
#ifdef F_35
if( F_36 () )
{
F_16 ( V_103 ,
V_77 ) ;
goto V_105;
}
#endif
V_7 -> V_51 = V_3 ;
V_7 -> V_120 = F_4 () ;
}
else if ( ( V_46 [ 2 ] == V_75 ) &&
! ( V_7 -> V_56 & V_60 ) )
{
V_7 -> V_51 = V_4 ;
V_7 -> V_120 = F_5 () ;
}
else if ( ( V_46 [ 2 ] == V_73 ) &&
! ( V_7 -> V_56 & V_59 ) )
{
V_7 -> V_51 = V_5 ;
V_7 -> V_120 = F_6 () ;
}
else if ( ( V_46 [ 2 ] == V_71 ) &&
! ( V_7 -> V_56 & V_58 ) )
{
V_7 -> V_51 = V_6 ;
V_7 -> V_120 = F_7 () ;
}
else
{
F_16 ( V_103 , V_104 ) ;
goto V_105;
}
if ( V_46 [ 0 ] == V_124 && V_46 [ 5 ] != V_125 )
{
void (* F_9)( const T_2 * V_9 , int type , int V_10 ) = NULL ;
int V_54 ;
if ( V_7 -> V_14 != NULL )
F_9 = V_7 -> V_14 ;
else if ( V_7 -> V_15 -> V_14 != NULL )
F_9 = V_7 -> V_15 -> V_14 ;
V_43 = V_46 [ 5 ] ;
if ( F_9 != NULL )
{
V_54 = ( V_43 << 8 ) | V_46 [ 6 ] ;
F_9 ( V_7 , V_126 , V_54 ) ;
}
if ( V_7 -> V_98 )
V_7 -> V_98 ( 0 , V_7 -> V_51 , V_124 , V_46 + 5 , 2 , V_7 , V_7 -> V_99 ) ;
V_7 -> V_127 = V_128 ;
F_16 ( V_103 , V_129 + V_46 [ 6 ] ) ;
goto V_105;
}
if ( ! F_51 ( V_7 , 1 ) ) goto V_105;
V_7 -> V_13 = V_130 ;
V_7 -> V_113 = V_114 ;
V_7 -> V_115 = V_100 ;
if ( V_7 -> V_67 -> V_116 . V_8 == NULL )
if ( ! F_52 ( V_7 ) )
goto V_105;
V_7 -> V_101 = & ( V_7 -> V_67 -> V_116 . V_8 [ 0 ] ) ;
memcpy ( V_7 -> V_101 , V_8 , V_100 ) ;
V_7 -> V_67 -> V_116 . V_131 = V_100 ;
V_7 -> V_67 -> V_116 . V_132 = 0 ;
V_7 -> V_121 = V_7 -> V_120 -> V_122 ;
}
else
{
F_16 ( V_103 , V_133 ) ;
goto V_105;
}
V_7 -> V_31 = 0 ;
if ( ! F_53 ( V_7 , 0 ) )
goto V_105;
return ( F_54 ( V_7 ) ) ;
V_105:
return ( - 1 ) ;
}
