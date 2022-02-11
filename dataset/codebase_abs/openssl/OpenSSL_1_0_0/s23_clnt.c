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
else
return ( NULL ) ;
}
int F_6 ( T_2 * V_5 )
{
T_3 * V_6 = NULL ;
unsigned long Time = ( unsigned long ) time ( NULL ) ;
void (* F_7)( const T_2 * V_7 , int type , int V_8 ) = NULL ;
int V_9 = - 1 ;
int V_10 , V_11 ;
F_8 ( & Time , sizeof( Time ) , 0 ) ;
F_9 () ;
F_10 () ;
if ( V_5 -> V_12 != NULL )
F_7 = V_5 -> V_12 ;
else if ( V_5 -> V_13 -> V_12 != NULL )
F_7 = V_5 -> V_13 -> V_12 ;
V_5 -> V_14 ++ ;
if ( ! F_11 ( V_5 ) || F_12 ( V_5 ) ) F_13 ( V_5 ) ;
for (; ; )
{
V_11 = V_5 -> V_11 ;
switch( V_5 -> V_11 )
{
case V_15 :
case V_16 :
case V_15 | V_16 :
case V_17 | V_16 :
if ( V_5 -> V_18 != NULL )
{
F_14 ( V_19 , V_20 ) ;
V_9 = - 1 ;
goto V_21;
}
V_5 -> V_22 = 0 ;
if ( F_7 != NULL ) F_7 ( V_5 , V_23 , 1 ) ;
V_5 -> type = V_16 ;
if ( V_5 -> V_24 == NULL )
{
if ( ( V_6 = F_15 () ) == NULL )
{
V_9 = - 1 ;
goto V_21;
}
if ( ! F_16 ( V_6 , V_25 ) )
{
V_9 = - 1 ;
goto V_21;
}
V_5 -> V_24 = V_6 ;
V_6 = NULL ;
}
if ( ! F_17 ( V_5 ) ) { V_9 = - 1 ; goto V_21; }
F_18 ( V_5 ) ;
V_5 -> V_11 = V_26 ;
V_5 -> V_13 -> V_27 . V_28 ++ ;
V_5 -> V_29 = 0 ;
break;
case V_26 :
case V_30 :
V_5 -> V_31 = 0 ;
V_9 = F_19 ( V_5 ) ;
if ( V_9 <= 0 ) goto V_21;
V_5 -> V_11 = V_32 ;
V_5 -> V_29 = 0 ;
break;
case V_32 :
case V_33 :
V_9 = F_20 ( V_5 ) ;
if ( V_9 >= 0 ) F_7 = NULL ;
goto V_21;
default:
F_14 ( V_19 , V_34 ) ;
V_9 = - 1 ;
goto V_21;
}
if ( V_5 -> V_35 ) { ( void ) F_21 ( V_5 -> V_36 ) ; }
if ( ( F_7 != NULL ) && ( V_5 -> V_11 != V_11 ) )
{
V_10 = V_5 -> V_11 ;
V_5 -> V_11 = V_11 ;
F_7 ( V_5 , V_37 , 1 ) ;
V_5 -> V_11 = V_10 ;
}
}
V_21:
V_5 -> V_14 -- ;
if ( V_6 != NULL )
F_22 ( V_6 ) ;
if ( F_7 != NULL )
F_7 ( V_5 , V_38 , V_9 ) ;
return ( V_9 ) ;
}
static int F_23 ( T_2 * V_5 )
{
T_4 * V_39 ;
F_24 ( T_4 ) * V_40 ;
int V_41 ;
V_40 = F_25 ( V_5 ) ;
for ( V_41 = 0 ; V_41 < F_26 ( V_40 ) ; V_41 ++ )
{
V_39 = F_27 ( V_40 , V_41 ) ;
if ( V_39 -> V_42 == V_43 )
return 0 ;
}
return 1 ;
}
static int F_19 ( T_2 * V_5 )
{
unsigned char * V_6 ;
unsigned char * V_44 , * V_45 ;
int V_41 , V_46 ;
unsigned long Time , V_47 ;
int V_48 ;
int V_49 = 0 , V_50 , V_51 ;
#ifndef F_28
int V_52 ;
T_5 * V_53 ;
#endif
int V_9 ;
V_48 = ( V_5 -> V_54 & V_55 ) ? 0 : 1 ;
if ( V_48 && F_23 ( V_5 ) )
V_48 = 0 ;
if ( ! ( V_5 -> V_54 & V_56 ) )
{
V_49 = V_4 ;
}
else if ( ! ( V_5 -> V_54 & V_57 ) )
{
V_49 = V_3 ;
}
else if ( ! ( V_5 -> V_54 & V_55 ) )
{
V_49 = V_2 ;
}
#ifndef F_29
if ( V_49 != V_2 )
{
if ( V_5 -> V_58 != NULL )
V_48 = 0 ;
if ( V_5 -> V_59 != - 1 )
V_48 = 0 ;
#ifdef F_30
if ( V_5 -> V_13 -> V_60 != 0 || V_5 -> V_61 != NULL )
V_48 = 0 ;
#endif
}
#endif
V_6 = ( unsigned char * ) V_5 -> V_24 -> V_62 ;
if ( V_5 -> V_11 == V_26 )
{
#if 0
if (!ssl_get_new_session(s,0))
{
return(-1);
}
#endif
V_44 = V_5 -> V_63 -> V_64 ;
Time = ( unsigned long ) time ( NULL ) ;
F_31 ( Time , V_44 ) ;
if ( F_32 ( V_44 , V_65 - 4 ) <= 0 )
return - 1 ;
if ( V_49 == V_4 )
{
V_50 = V_66 ;
V_51 = V_67 ;
}
else if ( V_49 == V_3 )
{
V_50 = V_68 ;
V_51 = V_69 ;
}
else if ( V_49 == V_2 )
{
V_50 = V_70 ;
V_51 = V_71 ;
}
else
{
F_14 ( V_72 , V_73 ) ;
return ( - 1 ) ;
}
V_5 -> V_74 = V_49 ;
if ( V_48 )
{
V_45 = & ( V_6 [ 2 ] ) ;
V_44 = V_45 + 9 ;
* ( V_45 ++ ) = V_75 ;
* ( V_45 ++ ) = V_50 ;
* ( V_45 ++ ) = V_51 ;
V_41 = F_33 ( V_5 , F_25 ( V_5 ) , V_44 , 0 ) ;
if ( V_41 == 0 )
{
F_14 ( V_72 , V_76 ) ;
return - 1 ;
}
F_34 ( V_41 , V_45 ) ;
V_44 += V_41 ;
#if 0
s->session->session_id_length=0;
#endif
F_34 ( 0 , V_45 ) ;
if ( V_5 -> V_54 & V_77 )
V_46 = V_78 ;
else
V_46 = V_79 ;
if ( V_65 < V_46 )
V_41 = V_65 ;
else
V_41 = V_46 ;
F_34 ( V_41 , V_45 ) ;
memset ( & ( V_5 -> V_63 -> V_64 [ 0 ] ) , 0 , V_65 ) ;
if ( F_32 ( & ( V_5 -> V_63 -> V_64 [ V_65 - V_41 ] ) , V_41 ) <= 0 )
return - 1 ;
memcpy ( V_44 , & ( V_5 -> V_63 -> V_64 [ V_65 - V_41 ] ) , V_41 ) ;
V_44 += V_41 ;
V_41 = V_44 - & ( V_6 [ 2 ] ) ;
V_6 [ 0 ] = ( ( V_41 >> 8 ) & 0xff ) | 0x80 ;
V_6 [ 1 ] = ( V_41 & 0xff ) ;
V_5 -> V_29 = V_41 + 2 ;
V_5 -> V_80 = 0 ;
F_35 ( V_5 , & ( V_6 [ 2 ] ) , V_41 ) ;
}
else
{
V_45 = V_44 = & ( V_6 [ 9 ] ) ;
* ( V_44 ++ ) = V_50 ;
* ( V_44 ++ ) = V_51 ;
memcpy ( V_44 , V_5 -> V_63 -> V_64 , V_65 ) ;
V_44 += V_65 ;
* ( V_44 ++ ) = 0 ;
V_41 = F_33 ( V_5 , F_25 ( V_5 ) , & ( V_44 [ 2 ] ) , V_81 ) ;
if ( V_41 == 0 )
{
F_14 ( V_72 , V_76 ) ;
return - 1 ;
}
F_34 ( V_41 , V_44 ) ;
V_44 += V_41 ;
#ifdef F_28
* ( V_44 ++ ) = 1 ;
#else
if ( ( V_5 -> V_54 & V_82 )
|| ! V_5 -> V_13 -> V_83 )
V_52 = 0 ;
else
V_52 = F_36 ( V_5 -> V_13 -> V_83 ) ;
* ( V_44 ++ ) = 1 + V_52 ;
for ( V_41 = 0 ; V_41 < V_52 ; V_41 ++ )
{
V_53 = F_37 ( V_5 -> V_13 -> V_83 , V_41 ) ;
* ( V_44 ++ ) = V_53 -> V_84 ;
}
#endif
* ( V_44 ++ ) = 0 ;
#ifndef F_29
if ( F_38 ( V_5 ) <= 0 )
{
F_14 ( V_72 , V_85 ) ;
return - 1 ;
}
if ( ( V_44 = F_39 ( V_5 , V_44 , V_6 + V_25 ) ) == NULL )
{
F_14 ( V_72 , V_86 ) ;
return - 1 ;
}
#endif
V_47 = V_44 - V_45 ;
V_45 = & ( V_6 [ 5 ] ) ;
* ( V_45 ++ ) = V_87 ;
F_40 ( V_47 , V_45 ) ;
V_47 += 4 ;
if ( V_47 > V_25 )
{
F_14 ( V_72 , V_86 ) ;
return - 1 ;
}
V_45 = V_6 ;
* ( V_45 ++ ) = V_88 ;
* ( V_45 ++ ) = V_50 ;
* ( V_45 ++ ) = V_51 ;
F_34 ( ( int ) V_47 , V_45 ) ;
V_5 -> V_29 = V_44 - V_6 ;
V_5 -> V_80 = 0 ;
F_35 ( V_5 , & ( V_6 [ 5 ] ) , V_5 -> V_29 - 5 ) ;
}
V_5 -> V_11 = V_30 ;
V_5 -> V_80 = 0 ;
}
V_9 = F_41 ( V_5 ) ;
if ( ( V_9 >= 2 ) && V_5 -> V_89 )
{
if ( V_48 )
V_5 -> V_89 ( 1 , V_2 , 0 , V_5 -> V_24 -> V_62 + 2 , V_9 - 2 , V_5 , V_5 -> V_90 ) ;
else
V_5 -> V_89 ( 1 , V_49 , V_88 , V_5 -> V_24 -> V_62 + 5 , V_9 - 5 , V_5 , V_5 -> V_90 ) ;
}
return V_9 ;
}
static int F_20 ( T_2 * V_5 )
{
char V_6 [ 8 ] ;
unsigned char * V_44 ;
int V_41 ;
int V_91 ;
V_91 = F_42 ( V_5 , 7 ) ;
if ( V_91 != 7 ) return ( V_91 ) ;
V_44 = V_5 -> V_92 ;
memcpy ( V_6 , V_44 , V_91 ) ;
if ( ( V_44 [ 0 ] & 0x80 ) && ( V_44 [ 2 ] == V_93 ) &&
( V_44 [ 5 ] == 0x00 ) && ( V_44 [ 6 ] == 0x02 ) )
{
#ifdef F_2
F_14 ( V_94 , V_95 ) ;
goto V_96;
#else
int V_46 ;
if ( V_5 -> V_54 & V_55 )
{
F_14 ( V_94 , V_95 ) ;
goto V_96;
}
if ( V_5 -> V_97 == NULL )
{
if ( ! F_43 ( V_5 ) )
goto V_96;
}
else
F_44 ( V_5 ) ;
if ( V_5 -> V_54 & V_77 )
V_46 = V_78 ;
else
V_46 = V_79 ;
V_41 = ( V_65 < V_46 )
? V_65 : V_46 ;
V_5 -> V_97 -> V_98 = V_41 ;
memcpy ( V_5 -> V_97 -> V_99 ,
& ( V_5 -> V_63 -> V_64 [ V_65 - V_41 ] ) , V_41 ) ;
if ( V_5 -> V_63 != NULL ) F_45 ( V_5 ) ;
if ( ! F_46 ( V_5 -> V_24 ,
V_100 ) )
{
F_14 ( V_94 , V_101 ) ;
goto V_96;
}
V_5 -> V_11 = V_102 ;
if ( ! ( V_5 -> V_74 == V_2 ) )
V_5 -> V_97 -> V_103 = 1 ;
V_5 -> V_104 = V_105 ;
V_5 -> V_106 = V_91 ;
V_5 -> V_92 = & ( V_5 -> V_97 -> V_107 [ 0 ] ) ;
memcpy ( V_5 -> V_92 , V_6 , V_91 ) ;
V_5 -> V_97 -> V_108 = V_91 ;
V_5 -> V_97 -> V_109 = 0 ;
V_5 -> V_97 -> V_110 = 1 ;
V_5 -> V_111 = F_3 () ;
V_5 -> V_112 = V_5 -> V_111 -> V_113 ;
#endif
}
else if ( V_44 [ 1 ] == V_68 &&
( V_44 [ 2 ] == V_69 || V_44 [ 2 ] == V_67 ) &&
( ( V_44 [ 0 ] == V_88 && V_44 [ 5 ] == V_114 ) ||
( V_44 [ 0 ] == V_115 && V_44 [ 3 ] == 0 && V_44 [ 4 ] == 2 ) ) )
{
if ( ( V_44 [ 2 ] == V_69 ) &&
! ( V_5 -> V_54 & V_57 ) )
{
V_5 -> V_49 = V_3 ;
V_5 -> V_111 = F_4 () ;
}
else if ( ( V_44 [ 2 ] == V_67 ) &&
! ( V_5 -> V_54 & V_56 ) )
{
V_5 -> V_49 = V_4 ;
V_5 -> V_111 = F_5 () ;
}
else
{
F_14 ( V_94 , V_95 ) ;
goto V_96;
}
if ( V_44 [ 0 ] == V_115 && V_44 [ 5 ] != V_116 )
{
void (* F_7)( const T_2 * V_7 , int type , int V_8 ) = NULL ;
int V_52 ;
if ( V_5 -> V_12 != NULL )
F_7 = V_5 -> V_12 ;
else if ( V_5 -> V_13 -> V_12 != NULL )
F_7 = V_5 -> V_13 -> V_12 ;
V_41 = V_44 [ 5 ] ;
if ( F_7 != NULL )
{
V_52 = ( V_41 << 8 ) | V_44 [ 6 ] ;
F_7 ( V_5 , V_117 , V_52 ) ;
}
if ( V_5 -> V_89 )
V_5 -> V_89 ( 0 , V_5 -> V_49 , V_115 , V_44 + 5 , 2 , V_5 , V_5 -> V_90 ) ;
V_5 -> V_118 = V_119 ;
F_14 ( V_94 , V_120 + V_44 [ 6 ] ) ;
goto V_96;
}
if ( ! F_47 ( V_5 , 1 ) ) goto V_96;
V_5 -> V_11 = V_121 ;
V_5 -> V_104 = V_105 ;
V_5 -> V_106 = V_91 ;
if ( V_5 -> V_63 -> V_107 . V_6 == NULL )
if ( ! F_48 ( V_5 ) )
goto V_96;
V_5 -> V_92 = & ( V_5 -> V_63 -> V_107 . V_6 [ 0 ] ) ;
memcpy ( V_5 -> V_92 , V_6 , V_91 ) ;
V_5 -> V_63 -> V_107 . V_122 = V_91 ;
V_5 -> V_63 -> V_107 . V_123 = 0 ;
V_5 -> V_112 = V_5 -> V_111 -> V_113 ;
}
else
{
F_14 ( V_94 , V_124 ) ;
goto V_96;
}
V_5 -> V_29 = 0 ;
if ( ! F_49 ( V_5 , 0 ) )
goto V_96;
return ( F_50 ( V_5 ) ) ;
V_96:
return ( - 1 ) ;
}
