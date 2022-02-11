static T_1 * F_1 ( int V_1 )
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
T_1 * F_6 ( void )
{
static int V_5 = 1 ;
static T_1 V_6 ;
if ( V_5 )
{
F_7 ( V_7 ) ;
if ( V_5 )
{
memcpy ( ( char * ) & V_6 ,
( char * ) F_8 () , sizeof( T_1 ) ) ;
V_6 . V_8 = V_9 ;
V_6 . V_10 = F_1 ;
V_5 = 0 ;
}
F_9 ( V_7 ) ;
}
return ( & V_6 ) ;
}
int V_9 ( T_2 * V_11 )
{
T_3 * V_12 = NULL ;
unsigned long Time = time ( NULL ) ;
void (* F_10)( const T_2 * V_13 , int type , int V_14 ) = NULL ;
int V_15 = - 1 ;
int V_16 , V_17 ;
F_11 ( & Time , sizeof( Time ) , 0 ) ;
F_12 () ;
F_13 () ;
if ( V_11 -> V_18 != NULL )
F_10 = V_11 -> V_18 ;
else if ( V_11 -> V_19 -> V_18 != NULL )
F_10 = V_11 -> V_19 -> V_18 ;
V_11 -> V_20 ++ ;
if ( ! F_14 ( V_11 ) || F_15 ( V_11 ) ) F_16 ( V_11 ) ;
for (; ; )
{
V_17 = V_11 -> V_17 ;
switch( V_11 -> V_17 )
{
case V_21 :
case V_22 :
case V_21 | V_22 :
case V_23 | V_22 :
if ( V_11 -> V_24 != NULL )
{
F_17 ( V_25 , V_26 ) ;
V_15 = - 1 ;
goto V_27;
}
V_11 -> V_28 = 0 ;
if ( F_10 != NULL ) F_10 ( V_11 , V_29 , 1 ) ;
V_11 -> type = V_22 ;
if ( V_11 -> V_30 == NULL )
{
if ( ( V_12 = F_18 () ) == NULL )
{
V_15 = - 1 ;
goto V_27;
}
if ( ! F_19 ( V_12 , V_31 ) )
{
V_15 = - 1 ;
goto V_27;
}
V_11 -> V_30 = V_12 ;
V_12 = NULL ;
}
if ( ! F_20 ( V_11 ) ) { V_15 = - 1 ; goto V_27; }
F_21 ( V_11 ) ;
V_11 -> V_17 = V_32 ;
V_11 -> V_19 -> V_33 . V_34 ++ ;
V_11 -> V_35 = 0 ;
break;
case V_32 :
case V_36 :
V_11 -> V_37 = 0 ;
V_15 = F_22 ( V_11 ) ;
if ( V_15 <= 0 ) goto V_27;
V_11 -> V_17 = V_38 ;
V_11 -> V_35 = 0 ;
break;
case V_38 :
case V_39 :
V_15 = F_23 ( V_11 ) ;
if ( V_15 >= 0 ) F_10 = NULL ;
goto V_27;
default:
F_17 ( V_25 , V_40 ) ;
V_15 = - 1 ;
goto V_27;
}
if ( V_11 -> V_41 ) { ( void ) F_24 ( V_11 -> V_42 ) ; }
if ( ( F_10 != NULL ) && ( V_11 -> V_17 != V_17 ) )
{
V_16 = V_11 -> V_17 ;
V_11 -> V_17 = V_17 ;
F_10 ( V_11 , V_43 , 1 ) ;
V_11 -> V_17 = V_16 ;
}
}
V_27:
V_11 -> V_20 -- ;
if ( V_12 != NULL )
F_25 ( V_12 ) ;
if ( F_10 != NULL )
F_10 ( V_11 , V_44 , V_15 ) ;
return ( V_15 ) ;
}
static int F_22 ( T_2 * V_11 )
{
unsigned char * V_12 ;
unsigned char * V_45 , * V_46 ;
int V_47 , V_48 ;
int V_15 ;
V_12 = ( unsigned char * ) V_11 -> V_30 -> V_49 ;
if ( V_11 -> V_17 == V_32 )
{
#if 0
if (!ssl_get_new_session(s,0))
{
return(-1);
}
#endif
V_45 = V_11 -> V_50 -> V_51 ;
F_26 ( V_45 , V_52 ) ;
V_46 = & ( V_12 [ 2 ] ) ;
V_45 = V_46 + 9 ;
* ( V_46 ++ ) = V_53 ;
if ( ! ( V_11 -> V_54 & V_55 ) )
{
* ( V_46 ++ ) = V_56 ;
* ( V_46 ++ ) = V_57 ;
V_11 -> V_58 = V_4 ;
}
else if ( ! ( V_11 -> V_54 & V_59 ) )
{
* ( V_46 ++ ) = V_60 ;
* ( V_46 ++ ) = V_61 ;
V_11 -> V_58 = V_3 ;
}
else if ( ! ( V_11 -> V_54 & V_62 ) )
{
* ( V_46 ++ ) = V_63 ;
* ( V_46 ++ ) = V_64 ;
V_11 -> V_58 = V_2 ;
}
else
{
F_17 ( V_65 , V_66 ) ;
return ( - 1 ) ;
}
V_47 = F_27 ( V_11 , F_28 ( V_11 ) , V_45 ) ;
if ( V_47 == 0 )
{
F_17 ( V_65 , V_67 ) ;
return ( - 1 ) ;
}
F_29 ( V_47 , V_46 ) ;
V_45 += V_47 ;
#if 0
s->session->session_id_length=0;
#endif
F_29 ( 0 , V_46 ) ;
if ( V_11 -> V_54 & V_68 )
V_48 = V_69 ;
else
V_48 = V_70 ;
if ( V_52 < V_48 )
V_47 = V_52 ;
else
V_47 = V_48 ;
F_29 ( V_47 , V_46 ) ;
memset ( & ( V_11 -> V_50 -> V_51 [ 0 ] ) , 0 , V_52 ) ;
F_26 ( & ( V_11 -> V_50 -> V_51 [ V_52 - V_47 ] ) , V_47 ) ;
memcpy ( V_45 , & ( V_11 -> V_50 -> V_51 [ V_52 - V_47 ] ) , V_47 ) ;
V_45 += V_47 ;
V_47 = V_45 - & ( V_12 [ 2 ] ) ;
V_12 [ 0 ] = ( ( V_47 >> 8 ) & 0xff ) | 0x80 ;
V_12 [ 1 ] = ( V_47 & 0xff ) ;
V_11 -> V_17 = V_36 ;
V_11 -> V_35 = V_47 + 2 ;
V_11 -> V_71 = 0 ;
F_30 ( V_11 , & ( V_12 [ 2 ] ) , V_47 ) ;
}
V_15 = F_31 ( V_11 ) ;
if ( V_15 >= 2 )
if ( V_11 -> V_72 )
V_11 -> V_72 ( 1 , V_2 , 0 , V_11 -> V_30 -> V_49 + 2 , V_15 - 2 , V_11 , V_11 -> V_73 ) ;
return V_15 ;
}
static int F_23 ( T_2 * V_11 )
{
char V_12 [ 8 ] ;
unsigned char * V_45 ;
int V_47 ;
int V_74 ;
V_74 = F_32 ( V_11 , 7 ) ;
if ( V_74 != 7 ) return ( V_74 ) ;
V_45 = V_11 -> V_75 ;
memcpy ( V_12 , V_45 , V_74 ) ;
if ( ( V_45 [ 0 ] & 0x80 ) && ( V_45 [ 2 ] == V_76 ) &&
( V_45 [ 5 ] == 0x00 ) && ( V_45 [ 6 ] == 0x02 ) )
{
#ifdef F_2
F_17 ( V_77 , V_78 ) ;
goto V_79;
#else
int V_48 ;
if ( V_11 -> V_54 & V_62 )
{
F_17 ( V_77 , V_78 ) ;
goto V_79;
}
if ( V_11 -> V_80 == NULL )
{
if ( ! F_33 ( V_11 ) )
goto V_79;
}
else
F_34 ( V_11 ) ;
if ( V_11 -> V_54 & V_68 )
V_48 = V_69 ;
else
V_48 = V_70 ;
V_47 = ( V_52 < V_48 )
? V_52 : V_48 ;
V_11 -> V_80 -> V_81 = V_47 ;
memcpy ( V_11 -> V_80 -> V_82 ,
& ( V_11 -> V_50 -> V_51 [ V_52 - V_47 ] ) , V_47 ) ;
if ( V_11 -> V_50 != NULL ) F_35 ( V_11 ) ;
if ( ! F_36 ( V_11 -> V_30 ,
V_83 ) )
{
F_17 ( V_77 , V_84 ) ;
goto V_79;
}
V_11 -> V_17 = V_85 ;
if ( ! ( V_11 -> V_58 == V_2 ) )
V_11 -> V_80 -> V_86 = 1 ;
V_11 -> V_87 = V_88 ;
V_11 -> V_89 = V_74 ;
V_11 -> V_75 = & ( V_11 -> V_80 -> V_90 [ 0 ] ) ;
memcpy ( V_11 -> V_75 , V_12 , V_74 ) ;
V_11 -> V_80 -> V_91 = V_74 ;
V_11 -> V_80 -> V_92 = 0 ;
V_11 -> V_80 -> V_93 = 1 ;
V_11 -> V_94 = F_3 () ;
V_11 -> V_95 = V_11 -> V_94 -> V_8 ;
#endif
}
else if ( ( V_45 [ 0 ] == V_96 ) &&
( V_45 [ 1 ] == V_60 ) &&
( ( V_45 [ 2 ] == V_61 ) ||
( V_45 [ 2 ] == V_57 ) ) &&
( V_45 [ 5 ] == V_97 ) )
{
if ( ! F_37 ( V_11 , 1 ) ) goto V_79;
V_11 -> V_17 = V_98 ;
V_11 -> V_87 = V_88 ;
V_11 -> V_89 = V_74 ;
V_11 -> V_75 = & ( V_11 -> V_50 -> V_90 . V_12 [ 0 ] ) ;
memcpy ( V_11 -> V_75 , V_12 , V_74 ) ;
V_11 -> V_50 -> V_90 . V_99 = V_74 ;
V_11 -> V_50 -> V_90 . V_100 = 0 ;
if ( ( V_45 [ 2 ] == V_61 ) &&
! ( V_11 -> V_54 & V_59 ) )
{
V_11 -> V_101 = V_3 ;
V_11 -> V_94 = F_4 () ;
}
else if ( ( V_45 [ 2 ] == V_57 ) &&
! ( V_11 -> V_54 & V_55 ) )
{
V_11 -> V_101 = V_4 ;
V_11 -> V_94 = F_5 () ;
}
else
{
F_17 ( V_77 , V_78 ) ;
goto V_79;
}
V_11 -> V_95 = V_11 -> V_94 -> V_8 ;
}
else if ( ( V_45 [ 0 ] == V_102 ) &&
( V_45 [ 1 ] == V_60 ) &&
( ( V_45 [ 2 ] == V_61 ) ||
( V_45 [ 2 ] == V_57 ) ) &&
( V_45 [ 3 ] == 0 ) &&
( V_45 [ 4 ] == 2 ) )
{
void (* F_10)( const T_2 * V_13 , int type , int V_14 ) = NULL ;
int V_103 ;
if ( V_11 -> V_18 != NULL )
F_10 = V_11 -> V_18 ;
else if ( V_11 -> V_19 -> V_18 != NULL )
F_10 = V_11 -> V_19 -> V_18 ;
V_47 = V_45 [ 5 ] ;
if ( F_10 != NULL )
{
V_103 = ( V_47 << 8 ) | V_45 [ 6 ] ;
F_10 ( V_11 , V_104 , V_103 ) ;
}
V_11 -> V_105 = V_106 ;
F_17 ( V_77 , V_107 + V_45 [ 6 ] ) ;
goto V_79;
}
else
{
F_17 ( V_77 , V_108 ) ;
goto V_79;
}
V_11 -> V_35 = 0 ;
if ( ! F_38 ( V_11 , 0 ) )
goto V_79;
V_11 -> V_109 = 1 ;
return ( F_39 ( V_11 ) ) ;
V_79:
return ( - 1 ) ;
}
