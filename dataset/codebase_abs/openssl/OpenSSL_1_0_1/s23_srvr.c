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
T_3 * V_8 ;
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
V_7 -> V_20 = 1 ;
if ( F_9 != NULL ) F_9 ( V_7 , V_21 , 1 ) ;
V_7 -> type = V_18 ;
if ( V_7 -> V_22 == NULL )
{
if ( ( V_8 = F_16 () ) == NULL )
{
V_11 = - 1 ;
goto V_23;
}
if ( ! F_17 ( V_8 , V_24 ) )
{
V_11 = - 1 ;
goto V_23;
}
V_7 -> V_22 = V_8 ;
}
F_18 ( V_7 ) ;
V_7 -> V_13 = V_25 ;
V_7 -> V_15 -> V_26 . V_27 ++ ;
V_7 -> V_28 = 0 ;
break;
case V_25 :
case V_29 :
V_7 -> V_30 = 0 ;
V_11 = F_19 ( V_7 ) ;
if ( V_11 >= 0 ) F_9 = NULL ;
goto V_23;
default:
F_20 ( V_31 , V_32 ) ;
V_11 = - 1 ;
goto V_23;
}
if ( ( F_9 != NULL ) && ( V_7 -> V_13 != V_13 ) )
{
V_12 = V_7 -> V_13 ;
V_7 -> V_13 = V_13 ;
F_9 ( V_7 , V_33 , 1 ) ;
V_7 -> V_13 = V_12 ;
}
}
V_23:
V_7 -> V_16 -- ;
if ( F_9 != NULL )
F_9 ( V_7 , V_34 , V_11 ) ;
return ( V_11 ) ;
}
int F_19 ( T_2 * V_7 )
{
char V_35 [ 11 ] ;
char * V_8 = & ( V_35 [ 0 ] ) ;
unsigned char * V_36 , * V_37 , * V_38 , * V_39 ;
unsigned int V_40 ;
unsigned int V_41 , V_42 , V_43 ;
int V_44 = 0 , V_45 ;
int type = 0 ;
int V_46 [ 2 ] ;
if ( V_7 -> V_13 == V_25 )
{
V_46 [ 0 ] = V_46 [ 1 ] = 0 ;
if ( ! F_21 ( V_7 ) ) goto V_47;
V_44 = F_22 ( V_7 , sizeof V_35 ) ;
if ( V_44 != sizeof V_35 ) return ( V_44 ) ;
V_36 = V_7 -> V_48 ;
memcpy ( V_8 , V_36 , V_44 ) ;
if ( ( V_36 [ 0 ] & 0x80 ) && ( V_36 [ 2 ] == V_49 ) )
{
if ( ( V_36 [ 3 ] == 0x00 ) && ( V_36 [ 4 ] == 0x02 ) )
{
V_46 [ 0 ] = V_36 [ 3 ] ; V_46 [ 1 ] = V_36 [ 4 ] ;
if ( ! ( V_7 -> V_50 & V_51 ) )
type = 1 ;
}
else if ( V_36 [ 3 ] == V_52 )
{
V_46 [ 0 ] = V_36 [ 3 ] ; V_46 [ 1 ] = V_36 [ 4 ] ;
if ( V_36 [ 4 ] >= V_53 )
{
if ( V_36 [ 4 ] >= V_54 &&
! ( V_7 -> V_50 & V_55 ) )
{
V_7 -> V_56 = V_6 ;
V_7 -> V_13 = V_29 ;
}
else if ( V_36 [ 4 ] >= V_57 &&
! ( V_7 -> V_50 & V_58 ) )
{
V_7 -> V_56 = V_5 ;
V_7 -> V_13 = V_29 ;
}
else if ( ! ( V_7 -> V_50 & V_59 ) )
{
V_7 -> V_56 = V_4 ;
V_7 -> V_13 = V_29 ;
}
else if ( ! ( V_7 -> V_50 & V_60 ) )
{
V_7 -> V_56 = V_3 ;
V_7 -> V_13 = V_29 ;
}
else if ( ! ( V_7 -> V_50 & V_51 ) )
{
type = 1 ;
}
}
else if ( ! ( V_7 -> V_50 & V_60 ) )
{
V_7 -> V_56 = V_3 ;
V_7 -> V_13 = V_29 ;
}
else if ( ! ( V_7 -> V_50 & V_51 ) )
type = 1 ;
}
}
else if ( ( V_36 [ 0 ] == V_61 ) &&
( V_36 [ 1 ] == V_52 ) &&
( V_36 [ 5 ] == V_62 ) &&
( ( V_36 [ 3 ] == 0 && V_36 [ 4 ] < 5 )
|| ( V_36 [ 9 ] >= V_36 [ 1 ] ) ) )
{
V_46 [ 0 ] = V_36 [ 1 ] ;
if ( V_36 [ 3 ] == 0 && V_36 [ 4 ] < 6 )
{
#if 0
SSLerr(SSL_F_SSL23_GET_CLIENT_HELLO,SSL_R_RECORD_TOO_SMALL);
goto err;
#else
V_46 [ 1 ] = V_53 ;
#endif
}
else if ( V_36 [ 9 ] > V_52 )
V_46 [ 1 ] = 0xff ;
else
V_46 [ 1 ] = V_36 [ 10 ] ;
if ( V_46 [ 1 ] >= V_53 )
{
if ( V_46 [ 1 ] >= V_54 &&
! ( V_7 -> V_50 & V_55 ) )
{
V_7 -> V_56 = V_6 ;
type = 3 ;
}
else if ( V_46 [ 1 ] >= V_57 &&
! ( V_7 -> V_50 & V_58 ) )
{
V_7 -> V_56 = V_5 ;
type = 3 ;
}
else if ( ! ( V_7 -> V_50 & V_59 ) )
{
V_7 -> V_56 = V_4 ;
type = 3 ;
}
else if ( ! ( V_7 -> V_50 & V_60 ) )
{
V_7 -> V_56 = V_3 ;
type = 3 ;
}
}
else
{
if ( ! ( V_7 -> V_50 & V_60 ) )
{
V_7 -> V_56 = V_3 ;
type = 3 ;
}
else if ( ! ( V_7 -> V_50 & V_59 ) )
{
V_7 -> V_56 = V_4 ;
type = 3 ;
}
}
}
else if ( ( strncmp ( L_1 , ( char * ) V_36 , 4 ) == 0 ) ||
( strncmp ( L_2 , ( char * ) V_36 , 5 ) == 0 ) ||
( strncmp ( L_3 , ( char * ) V_36 , 5 ) == 0 ) ||
( strncmp ( L_4 , ( char * ) V_36 , 4 ) == 0 ) )
{
F_20 ( V_63 , V_64 ) ;
goto V_47;
}
else if ( strncmp ( L_5 , ( char * ) V_36 , 7 ) == 0 )
{
F_20 ( V_63 , V_65 ) ;
goto V_47;
}
}
#ifdef F_23
if ( F_24 () && ( V_7 -> V_56 < V_4 ) )
{
F_20 ( V_63 ,
V_66 ) ;
goto V_47;
}
#endif
if ( V_7 -> V_13 == V_29 )
{
type = 2 ;
V_36 = V_7 -> V_48 ;
V_46 [ 0 ] = V_36 [ 3 ] ;
V_46 [ 1 ] = V_36 [ 4 ] ;
V_44 = ( ( V_36 [ 0 ] & 0x7f ) << 8 ) | V_36 [ 1 ] ;
if ( V_44 > ( 1024 * 4 ) )
{
F_20 ( V_63 , V_67 ) ;
goto V_47;
}
V_45 = F_22 ( V_7 , V_44 + 2 ) ;
if ( V_45 <= 0 ) return ( V_45 ) ;
F_25 ( V_7 , V_7 -> V_48 + 2 , V_7 -> V_68 - 2 ) ;
if ( V_7 -> V_69 )
V_7 -> V_69 ( 0 , V_2 , 0 , V_7 -> V_48 + 2 , V_7 -> V_68 - 2 , V_7 , V_7 -> V_70 ) ;
V_36 = V_7 -> V_48 ;
V_36 += 5 ;
F_26 ( V_36 , V_41 ) ;
F_26 ( V_36 , V_42 ) ;
F_26 ( V_36 , V_43 ) ;
V_37 = ( unsigned char * ) V_7 -> V_22 -> V_71 ;
if ( ( V_41 + V_42 + V_43 + 11 ) != V_7 -> V_68 )
{
F_20 ( V_63 , V_72 ) ;
goto V_47;
}
* ( V_37 ++ ) = V_62 ;
V_38 = V_37 ;
V_37 += 3 ;
* ( V_37 ++ ) = V_52 ;
* ( V_37 ++ ) = V_46 [ 1 ] ;
V_40 = ( V_43 > V_73 ) ? V_73 : V_43 ;
memset ( V_37 , 0 , V_73 ) ;
memcpy ( & ( V_37 [ V_73 - V_40 ] ) , & ( V_36 [ V_41 + V_42 ] ) , V_40 ) ;
V_37 += V_73 ;
* ( V_37 ++ ) = 0 ;
V_45 = 0 ;
V_39 = V_37 ;
V_37 += 2 ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 += 3 )
{
if ( V_36 [ V_40 ] != 0 ) continue;
* ( V_37 ++ ) = V_36 [ V_40 + 1 ] ;
* ( V_37 ++ ) = V_36 [ V_40 + 2 ] ;
V_45 += 2 ;
}
F_27 ( V_45 , V_39 ) ;
* ( V_37 ++ ) = 1 ;
* ( V_37 ++ ) = 0 ;
#if 0
p = p+csl+sil+cl;
while (p < s->packet+s->packet_length)
{
*(d++)=*(p++);
}
#endif
V_40 = ( V_37 - ( unsigned char * ) V_7 -> V_22 -> V_71 ) - 4 ;
F_28 ( ( long ) V_40 , V_38 ) ;
V_7 -> V_74 -> V_75 . V_76 = 1 ;
V_7 -> V_74 -> V_75 . V_77 = V_62 ;
V_7 -> V_74 -> V_75 . V_78 = V_40 ;
}
if ( type == 1 )
{
#ifdef F_2
F_20 ( V_63 , V_79 ) ;
goto V_47;
#else
if ( V_7 -> V_80 == NULL )
{
if ( ! F_29 ( V_7 ) )
goto V_47;
}
else
F_30 ( V_7 ) ;
if ( V_7 -> V_74 != NULL ) F_31 ( V_7 ) ;
if ( ! F_32 ( V_7 -> V_22 ,
V_81 ) )
{
goto V_47;
}
V_7 -> V_13 = V_82 ;
if ( V_7 -> V_50 & V_59 && V_7 -> V_50 & V_60 )
V_7 -> V_80 -> V_83 = 0 ;
else
V_7 -> V_80 -> V_83 = 1 ;
V_7 -> V_84 = V_85 ;
V_7 -> V_68 = V_44 ;
V_7 -> V_48 = & ( V_7 -> V_80 -> V_86 [ 0 ] ) ;
memcpy ( V_7 -> V_48 , V_8 , V_44 ) ;
V_7 -> V_80 -> V_87 = V_44 ;
V_7 -> V_80 -> V_88 = 0 ;
V_7 -> V_89 = F_3 () ;
V_7 -> V_90 = V_7 -> V_89 -> V_91 ;
#endif
}
if ( ( type == 2 ) || ( type == 3 ) )
{
if ( ! F_33 ( V_7 , 1 ) ) goto V_47;
V_7 -> V_13 = V_92 ;
if ( type == 3 )
{
V_7 -> V_84 = V_85 ;
V_7 -> V_68 = V_44 ;
if ( V_7 -> V_74 -> V_86 . V_8 == NULL )
if ( ! F_34 ( V_7 ) )
goto V_47;
V_7 -> V_48 = & ( V_7 -> V_74 -> V_86 . V_8 [ 0 ] ) ;
memcpy ( V_7 -> V_48 , V_8 , V_44 ) ;
V_7 -> V_74 -> V_86 . V_93 = V_44 ;
V_7 -> V_74 -> V_86 . V_94 = 0 ;
}
else
{
V_7 -> V_68 = 0 ;
V_7 -> V_74 -> V_86 . V_93 = 0 ;
V_7 -> V_74 -> V_86 . V_94 = 0 ;
}
if ( V_7 -> V_56 == V_6 )
V_7 -> V_89 = F_7 () ;
else if ( V_7 -> V_56 == V_5 )
V_7 -> V_89 = F_6 () ;
else if ( V_7 -> V_56 == V_4 )
V_7 -> V_89 = F_5 () ;
else
V_7 -> V_89 = F_4 () ;
#if 0
s->client_version=(v[0]<<8)|v[1];
#endif
V_7 -> V_90 = V_7 -> V_89 -> V_91 ;
}
if ( ( type < 1 ) || ( type > 3 ) )
{
F_20 ( V_63 , V_95 ) ;
goto V_47;
}
V_7 -> V_28 = 0 ;
if ( V_8 != V_35 ) F_35 ( V_8 ) ;
return ( F_36 ( V_7 ) ) ;
V_47:
if ( V_8 != V_35 ) F_35 ( V_8 ) ;
return ( - 1 ) ;
}
