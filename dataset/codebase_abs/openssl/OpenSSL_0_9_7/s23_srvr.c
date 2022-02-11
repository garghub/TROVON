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
T_3 * V_12 ;
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
V_11 -> V_24 = 1 ;
if ( F_10 != NULL ) F_10 ( V_11 , V_25 , 1 ) ;
V_11 -> type = V_22 ;
if ( V_11 -> V_26 == NULL )
{
if ( ( V_12 = F_17 () ) == NULL )
{
V_15 = - 1 ;
goto V_27;
}
if ( ! F_18 ( V_12 , V_28 ) )
{
V_15 = - 1 ;
goto V_27;
}
V_11 -> V_26 = V_12 ;
}
F_19 ( V_11 ) ;
V_11 -> V_17 = V_29 ;
V_11 -> V_19 -> V_30 . V_31 ++ ;
V_11 -> V_32 = 0 ;
break;
case V_29 :
case V_33 :
V_11 -> V_34 = 0 ;
V_15 = F_20 ( V_11 ) ;
if ( V_15 >= 0 ) F_10 = NULL ;
goto V_27;
default:
F_21 ( V_35 , V_36 ) ;
V_15 = - 1 ;
goto V_27;
}
if ( ( F_10 != NULL ) && ( V_11 -> V_17 != V_17 ) )
{
V_16 = V_11 -> V_17 ;
V_11 -> V_17 = V_17 ;
F_10 ( V_11 , V_37 , 1 ) ;
V_11 -> V_17 = V_16 ;
}
}
V_27:
V_11 -> V_20 -- ;
if ( F_10 != NULL )
F_10 ( V_11 , V_38 , V_15 ) ;
return ( V_15 ) ;
}
int F_20 ( T_2 * V_11 )
{
char V_39 [ 11 ] ;
char * V_12 = & ( V_39 [ 0 ] ) ;
unsigned char * V_40 , * V_41 , * V_42 , * V_43 ;
unsigned int V_44 ;
unsigned int V_45 , V_46 , V_47 ;
int V_48 = 0 , V_49 ;
int type = 0 ;
int V_50 [ 2 ] ;
#ifndef F_22
int V_51 = 0 ;
#endif
if ( V_11 -> V_17 == V_29 )
{
V_50 [ 0 ] = V_50 [ 1 ] = 0 ;
if ( ! F_23 ( V_11 ) ) goto V_52;
V_48 = F_24 ( V_11 , sizeof V_39 ) ;
if ( V_48 != sizeof V_39 ) return ( V_48 ) ;
V_40 = V_11 -> V_53 ;
memcpy ( V_12 , V_40 , V_48 ) ;
if ( ( V_40 [ 0 ] & 0x80 ) && ( V_40 [ 2 ] == V_54 ) )
{
if ( ( V_40 [ 3 ] == 0x00 ) && ( V_40 [ 4 ] == 0x02 ) )
{
V_50 [ 0 ] = V_40 [ 3 ] ; V_50 [ 1 ] = V_40 [ 4 ] ;
if ( ! ( V_11 -> V_55 & V_56 ) )
type = 1 ;
}
else if ( V_40 [ 3 ] == V_57 )
{
V_50 [ 0 ] = V_40 [ 3 ] ; V_50 [ 1 ] = V_40 [ 4 ] ;
if ( V_40 [ 4 ] >= V_58 )
{
if ( ! ( V_11 -> V_55 & V_59 ) )
{
V_11 -> V_60 = V_4 ;
V_11 -> V_17 = V_33 ;
}
else if ( ! ( V_11 -> V_55 & V_61 ) )
{
V_11 -> V_60 = V_3 ;
V_11 -> V_17 = V_33 ;
}
else if ( ! ( V_11 -> V_55 & V_56 ) )
{
type = 1 ;
}
}
else if ( ! ( V_11 -> V_55 & V_61 ) )
{
V_11 -> V_60 = V_3 ;
V_11 -> V_17 = V_33 ;
}
else if ( ! ( V_11 -> V_55 & V_56 ) )
type = 1 ;
}
}
else if ( ( V_40 [ 0 ] == V_62 ) &&
( V_40 [ 1 ] == V_57 ) &&
( V_40 [ 5 ] == V_63 ) &&
( ( V_40 [ 3 ] == 0 && V_40 [ 4 ] < 5 )
|| ( V_40 [ 9 ] == V_40 [ 1 ] ) ) )
{
V_50 [ 0 ] = V_40 [ 1 ] ;
if ( V_40 [ 3 ] == 0 && V_40 [ 4 ] < 6 )
{
#if 0
SSLerr(SSL_F_SSL23_GET_CLIENT_HELLO,SSL_R_RECORD_TOO_SMALL);
goto err;
#else
V_50 [ 1 ] = V_58 ;
#endif
}
else
V_50 [ 1 ] = V_40 [ 10 ] ;
if ( V_50 [ 1 ] >= V_58 )
{
if ( ! ( V_11 -> V_55 & V_59 ) )
{
V_11 -> V_60 = V_4 ;
type = 3 ;
}
else if ( ! ( V_11 -> V_55 & V_61 ) )
{
V_11 -> V_60 = V_3 ;
type = 3 ;
}
}
else
{
if ( ! ( V_11 -> V_55 & V_61 ) )
{
V_11 -> V_60 = V_3 ;
type = 3 ;
}
else if ( ! ( V_11 -> V_55 & V_59 ) )
{
V_11 -> V_60 = V_4 ;
type = 3 ;
}
}
}
else if ( ( strncmp ( L_1 , ( char * ) V_40 , 4 ) == 0 ) ||
( strncmp ( L_2 , ( char * ) V_40 , 5 ) == 0 ) ||
( strncmp ( L_3 , ( char * ) V_40 , 5 ) == 0 ) ||
( strncmp ( L_4 , ( char * ) V_40 , 4 ) == 0 ) )
{
F_21 ( V_64 , V_65 ) ;
goto V_52;
}
else if ( strncmp ( L_5 , ( char * ) V_40 , 7 ) == 0 )
{
F_21 ( V_64 , V_66 ) ;
goto V_52;
}
}
if ( V_11 -> V_17 == V_33 )
{
type = 2 ;
V_40 = V_11 -> V_53 ;
V_50 [ 0 ] = V_40 [ 3 ] ;
V_50 [ 1 ] = V_40 [ 4 ] ;
V_48 = ( ( V_40 [ 0 ] & 0x7f ) << 8 ) | V_40 [ 1 ] ;
if ( V_48 > ( 1024 * 4 ) )
{
F_21 ( V_64 , V_67 ) ;
goto V_52;
}
V_49 = F_24 ( V_11 , V_48 + 2 ) ;
if ( V_49 <= 0 ) return ( V_49 ) ;
F_25 ( V_11 , V_11 -> V_53 + 2 , V_11 -> V_68 - 2 ) ;
if ( V_11 -> V_69 )
V_11 -> V_69 ( 0 , V_2 , 0 , V_11 -> V_53 + 2 , V_11 -> V_68 - 2 , V_11 , V_11 -> V_70 ) ;
V_40 = V_11 -> V_53 ;
V_40 += 5 ;
F_26 ( V_40 , V_45 ) ;
F_26 ( V_40 , V_46 ) ;
F_26 ( V_40 , V_47 ) ;
V_41 = ( unsigned char * ) V_11 -> V_26 -> V_71 ;
if ( ( V_45 + V_46 + V_47 + 11 ) != V_11 -> V_68 )
{
F_21 ( V_64 , V_72 ) ;
goto V_52;
}
* ( V_41 ++ ) = V_63 ;
V_42 = V_41 ;
V_41 += 3 ;
* ( V_41 ++ ) = V_57 ;
* ( V_41 ++ ) = V_50 [ 1 ] ;
V_44 = ( V_47 > V_73 ) ? V_73 : V_47 ;
memset ( V_41 , 0 , V_73 ) ;
memcpy ( & ( V_41 [ V_73 - V_44 ] ) , & ( V_40 [ V_45 + V_46 ] ) , V_44 ) ;
V_41 += V_73 ;
* ( V_41 ++ ) = 0 ;
V_49 = 0 ;
V_43 = V_41 ;
V_41 += 2 ;
for ( V_44 = 0 ; V_44 < V_45 ; V_44 += 3 )
{
if ( V_40 [ V_44 ] != 0 ) continue;
* ( V_41 ++ ) = V_40 [ V_44 + 1 ] ;
* ( V_41 ++ ) = V_40 [ V_44 + 2 ] ;
V_49 += 2 ;
}
F_27 ( V_49 , V_43 ) ;
* ( V_41 ++ ) = 1 ;
* ( V_41 ++ ) = 0 ;
V_44 = ( V_41 - ( unsigned char * ) V_11 -> V_26 -> V_71 ) - 4 ;
F_28 ( ( long ) V_44 , V_42 ) ;
V_11 -> V_74 -> V_75 . V_76 = 1 ;
V_11 -> V_74 -> V_75 . V_77 = V_63 ;
V_11 -> V_74 -> V_75 . V_78 = V_44 ;
}
if ( type == 1 )
{
#ifdef F_2
F_21 ( V_64 , V_79 ) ;
goto V_52;
#else
if ( V_11 -> V_80 == NULL )
{
if ( ! F_29 ( V_11 ) )
goto V_52;
}
else
F_30 ( V_11 ) ;
if ( V_11 -> V_74 != NULL ) F_31 ( V_11 ) ;
if ( ! F_32 ( V_11 -> V_26 ,
V_81 ) )
{
goto V_52;
}
V_11 -> V_17 = V_82 ;
if ( ( V_11 -> V_55 & V_83 ) ||
V_51 ||
( V_11 -> V_55 & V_59 && V_11 -> V_55 & V_61 ) )
V_11 -> V_80 -> V_84 = 0 ;
else
V_11 -> V_80 -> V_84 = 1 ;
V_11 -> V_85 = V_86 ;
V_11 -> V_68 = V_48 ;
V_11 -> V_53 = & ( V_11 -> V_80 -> V_87 [ 0 ] ) ;
memcpy ( V_11 -> V_53 , V_12 , V_48 ) ;
V_11 -> V_80 -> V_88 = V_48 ;
V_11 -> V_80 -> V_89 = 0 ;
V_11 -> V_90 = F_3 () ;
V_11 -> V_91 = V_11 -> V_90 -> V_8 ;
#endif
}
if ( ( type == 2 ) || ( type == 3 ) )
{
if ( ! F_33 ( V_11 , 1 ) ) goto V_52;
V_11 -> V_17 = V_92 ;
if ( type == 3 )
{
V_11 -> V_85 = V_86 ;
V_11 -> V_68 = V_48 ;
V_11 -> V_53 = & ( V_11 -> V_74 -> V_87 . V_12 [ 0 ] ) ;
memcpy ( V_11 -> V_53 , V_12 , V_48 ) ;
V_11 -> V_74 -> V_87 . V_93 = V_48 ;
V_11 -> V_74 -> V_87 . V_94 = 0 ;
}
else
{
V_11 -> V_68 = 0 ;
V_11 -> V_74 -> V_87 . V_93 = 0 ;
V_11 -> V_74 -> V_87 . V_94 = 0 ;
}
if ( V_11 -> V_60 == V_4 )
V_11 -> V_90 = F_5 () ;
else
V_11 -> V_90 = F_4 () ;
#if 0
s->client_version=(v[0]<<8)|v[1];
#endif
V_11 -> V_91 = V_11 -> V_90 -> V_8 ;
}
if ( ( type < 1 ) || ( type > 3 ) )
{
F_21 ( V_64 , V_95 ) ;
goto V_52;
}
V_11 -> V_32 = 0 ;
if ( V_12 != V_39 ) F_34 ( V_12 ) ;
V_11 -> V_96 = 1 ;
return ( F_35 ( V_11 ) ) ;
V_52:
if ( V_12 != V_39 ) F_34 ( V_12 ) ;
return ( - 1 ) ;
}
