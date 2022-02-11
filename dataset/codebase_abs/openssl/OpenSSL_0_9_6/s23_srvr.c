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
memcpy ( ( char * ) & V_6 ,
( char * ) F_7 () , sizeof( T_1 ) ) ;
V_6 . V_7 = V_8 ;
V_6 . V_9 = F_1 ;
V_5 = 0 ;
}
return ( & V_6 ) ;
}
int V_8 ( T_2 * V_10 )
{
T_3 * V_11 ;
unsigned long Time = time ( NULL ) ;
void (* F_8)() = NULL ;
int V_12 = - 1 ;
int V_13 , V_14 ;
F_9 ( & Time , sizeof( Time ) , 0 ) ;
F_10 () ;
F_11 () ;
if ( V_10 -> V_15 != NULL )
F_8 = V_10 -> V_15 ;
else if ( V_10 -> V_16 -> V_15 != NULL )
F_8 = V_10 -> V_16 -> V_15 ;
if ( ! F_12 ( V_10 ) || F_13 ( V_10 ) ) F_14 ( V_10 ) ;
V_10 -> V_17 ++ ;
for (; ; )
{
V_14 = V_10 -> V_14 ;
switch( V_10 -> V_14 )
{
case V_18 :
case V_19 :
case V_18 | V_19 :
case V_20 | V_19 :
V_10 -> V_21 = 1 ;
if ( F_8 != NULL ) F_8 ( V_10 , V_22 , 1 ) ;
V_10 -> type = V_19 ;
if ( V_10 -> V_23 == NULL )
{
if ( ( V_11 = F_15 () ) == NULL )
{
V_12 = - 1 ;
goto V_24;
}
if ( ! F_16 ( V_11 , V_25 ) )
{
V_12 = - 1 ;
goto V_24;
}
V_10 -> V_23 = V_11 ;
}
F_17 ( V_10 ) ;
V_10 -> V_14 = V_26 ;
V_10 -> V_16 -> V_27 . V_28 ++ ;
V_10 -> V_29 = 0 ;
break;
case V_26 :
case V_30 :
V_10 -> V_31 = 0 ;
V_12 = F_18 ( V_10 ) ;
if ( V_12 >= 0 ) F_8 = NULL ;
goto V_24;
default:
F_19 ( V_32 , V_33 ) ;
V_12 = - 1 ;
goto V_24;
}
if ( ( F_8 != NULL ) && ( V_10 -> V_14 != V_14 ) )
{
V_13 = V_10 -> V_14 ;
V_10 -> V_14 = V_14 ;
F_8 ( V_10 , V_34 , 1 ) ;
V_10 -> V_14 = V_13 ;
}
}
V_24:
if ( F_8 != NULL )
F_8 ( V_10 , V_35 , V_12 ) ;
V_10 -> V_17 -- ;
return ( V_12 ) ;
}
int F_18 ( T_2 * V_10 )
{
char V_36 [ 11 ] ;
char * V_11 = & ( V_36 [ 0 ] ) ;
unsigned char * V_37 , * V_38 , * V_39 ;
unsigned int V_40 ;
unsigned int V_41 , V_42 , V_43 ;
int V_44 = 0 , V_45 ;
int type = 0 ;
int V_46 [ 2 ] ;
#ifndef F_20
int V_47 = 0 ;
#endif
if ( V_10 -> V_14 == V_26 )
{
V_46 [ 0 ] = V_46 [ 1 ] = 0 ;
if ( ! F_21 ( V_10 ) ) goto V_48;
V_44 = F_22 ( V_10 , sizeof V_36 ) ;
if ( V_44 != sizeof V_36 ) return ( V_44 ) ;
V_37 = V_10 -> V_49 ;
memcpy ( V_11 , V_37 , V_44 ) ;
if ( ( V_37 [ 0 ] & 0x80 ) && ( V_37 [ 2 ] == V_50 ) )
{
if ( ( V_37 [ 3 ] == 0x00 ) && ( V_37 [ 4 ] == 0x02 ) )
{
V_46 [ 0 ] = V_37 [ 3 ] ; V_46 [ 1 ] = V_37 [ 4 ] ;
if ( ! ( V_10 -> V_51 & V_52 ) )
type = 1 ;
}
else if ( V_37 [ 3 ] == V_53 )
{
V_46 [ 0 ] = V_37 [ 3 ] ; V_46 [ 1 ] = V_37 [ 4 ] ;
if ( V_37 [ 4 ] >= V_54 )
{
if ( ! ( V_10 -> V_51 & V_55 ) )
{
V_10 -> V_56 = V_4 ;
V_10 -> V_14 = V_30 ;
}
else if ( ! ( V_10 -> V_51 & V_57 ) )
{
V_10 -> V_56 = V_3 ;
V_10 -> V_14 = V_30 ;
}
else if ( ! ( V_10 -> V_51 & V_52 ) )
{
type = 1 ;
}
}
else if ( ! ( V_10 -> V_51 & V_57 ) )
{
V_10 -> V_56 = V_3 ;
V_10 -> V_14 = V_30 ;
}
else if ( ! ( V_10 -> V_51 & V_52 ) )
type = 1 ;
if ( V_10 -> V_51 & V_58 )
{
#if 0
STACK_OF(SSL_CIPHER) *sk;
SSL_CIPHER *c;
int ne2,ne3;
j=((p[0]&0x7f)<<8)|p[1];
if (j > (1024*4))
{
SSLerr(SSL_F_SSL23_GET_CLIENT_HELLO,SSL_R_RECORD_TOO_LARGE);
goto err;
}
n=ssl23_read_bytes(s,j+2);
if (n <= 0) return(n);
p=s->packet;
if ((buf=OPENSSL_malloc(n)) == NULL)
{
SSLerr(SSL_F_SSL23_GET_CLIENT_HELLO,ERR_R_MALLOC_FAILURE);
goto err;
}
memcpy(buf,p,n);
p+=5;
n2s(p,csl);
p+=4;
sk=ssl_bytes_to_cipher_list(
s,p,csl,NULL);
if (sk != NULL)
{
ne2=ne3=0;
for (j=0; j<sk_SSL_CIPHER_num(sk); j++)
{
c=sk_SSL_CIPHER_value(sk,j);
if (!SSL_C_IS_EXPORT(c))
{
if ((c->id>>24L) == 2L)
ne2=1;
else
ne3=1;
}
}
if (ne2 && !ne3)
{
type=1;
use_sslv2_strong=1;
goto next_bit;
}
}
#else
F_19 ( V_59 , V_60 ) ;
goto V_48;
#endif
}
}
}
else if ( ( V_37 [ 0 ] == V_61 ) &&
( V_37 [ 1 ] == V_53 ) &&
( V_37 [ 5 ] == V_62 ) &&
( ( V_37 [ 3 ] == 0 && V_37 [ 4 ] < 5 )
|| ( V_37 [ 9 ] == V_37 [ 1 ] ) ) )
{
V_46 [ 0 ] = V_37 [ 1 ] ;
if ( V_37 [ 3 ] == 0 && V_37 [ 4 ] < 6 )
{
F_19 ( V_59 , V_63 ) ;
goto V_48;
}
V_46 [ 1 ] = V_37 [ 10 ] ;
if ( V_46 [ 1 ] >= V_54 )
{
if ( ! ( V_10 -> V_51 & V_55 ) )
{
V_10 -> V_56 = V_4 ;
type = 3 ;
}
else if ( ! ( V_10 -> V_51 & V_57 ) )
{
V_10 -> V_56 = V_3 ;
type = 3 ;
}
}
else if ( ! ( V_10 -> V_51 & V_57 ) )
{
V_10 -> V_56 = V_3 ;
type = 3 ;
}
}
else if ( ( strncmp ( L_1 , ( char * ) V_37 , 4 ) == 0 ) ||
( strncmp ( L_2 , ( char * ) V_37 , 5 ) == 0 ) ||
( strncmp ( L_3 , ( char * ) V_37 , 5 ) == 0 ) ||
( strncmp ( L_4 , ( char * ) V_37 , 4 ) == 0 ) )
{
F_19 ( V_59 , V_64 ) ;
goto V_48;
}
else if ( strncmp ( L_5 , ( char * ) V_37 , 7 ) == 0 )
{
F_19 ( V_59 , V_65 ) ;
goto V_48;
}
}
if ( V_10 -> V_14 == V_30 )
{
type = 2 ;
V_37 = V_10 -> V_49 ;
V_46 [ 0 ] = V_37 [ 3 ] ;
V_46 [ 1 ] = V_37 [ 4 ] ;
V_44 = ( ( V_37 [ 0 ] & 0x7f ) << 8 ) | V_37 [ 1 ] ;
if ( V_44 > ( 1024 * 4 ) )
{
F_19 ( V_59 , V_66 ) ;
goto V_48;
}
V_45 = F_22 ( V_10 , V_44 + 2 ) ;
if ( V_45 <= 0 ) return ( V_45 ) ;
F_23 ( V_10 , & ( V_10 -> V_49 [ 2 ] ) , V_10 -> V_67 - 2 ) ;
V_37 = V_10 -> V_49 ;
V_37 += 5 ;
F_24 ( V_37 , V_41 ) ;
F_24 ( V_37 , V_42 ) ;
F_24 ( V_37 , V_43 ) ;
V_38 = ( unsigned char * ) V_10 -> V_23 -> V_68 ;
if ( ( V_41 + V_42 + V_43 + 11 ) != V_10 -> V_67 )
{
F_19 ( V_59 , V_69 ) ;
goto V_48;
}
* ( V_38 ++ ) = V_53 ;
* ( V_38 ++ ) = V_46 [ 1 ] ;
V_40 = ( V_43 > V_70 ) ? V_70 : V_43 ;
memset ( V_38 , 0 , V_70 ) ;
memcpy ( & ( V_38 [ V_70 - V_40 ] ) , & ( V_37 [ V_41 + V_42 ] ) , V_40 ) ;
V_38 += V_70 ;
* ( V_38 ++ ) = 0 ;
V_45 = 0 ;
V_39 = V_38 ;
V_38 += 2 ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 += 3 )
{
if ( V_37 [ V_40 ] != 0 ) continue;
* ( V_38 ++ ) = V_37 [ V_40 + 1 ] ;
* ( V_38 ++ ) = V_37 [ V_40 + 2 ] ;
V_45 += 2 ;
}
F_25 ( V_45 , V_39 ) ;
* ( V_38 ++ ) = 1 ;
* ( V_38 ++ ) = 0 ;
V_40 = ( V_38 - ( unsigned char * ) V_10 -> V_23 -> V_68 ) ;
V_10 -> V_71 -> V_72 . V_73 = 1 ;
V_10 -> V_71 -> V_72 . V_74 = V_62 ;
V_10 -> V_71 -> V_72 . V_75 = V_40 ;
}
if ( type == 1 )
{
#ifdef F_2
F_19 ( V_59 , V_76 ) ;
goto V_48;
#else
if ( V_10 -> V_77 == NULL )
{
if ( ! F_26 ( V_10 ) )
goto V_48;
}
else
F_27 ( V_10 ) ;
if ( V_10 -> V_71 != NULL ) F_28 ( V_10 ) ;
if ( ! F_16 ( V_10 -> V_23 ,
V_78 ) )
{
goto V_48;
}
V_10 -> V_14 = V_79 ;
if ( ( V_10 -> V_51 & V_80 ) ||
V_47 ||
( V_10 -> V_51 & V_55 && V_10 -> V_51 & V_57 ) )
V_10 -> V_77 -> V_81 = 0 ;
else
V_10 -> V_77 -> V_81 = 1 ;
V_10 -> V_82 = V_83 ;
V_10 -> V_67 = V_44 ;
V_10 -> V_49 = & ( V_10 -> V_77 -> V_84 [ 0 ] ) ;
memcpy ( V_10 -> V_49 , V_11 , V_44 ) ;
V_10 -> V_77 -> V_85 = V_44 ;
V_10 -> V_77 -> V_86 = 0 ;
V_10 -> V_87 = F_3 () ;
V_10 -> V_88 = V_10 -> V_87 -> V_7 ;
#endif
}
if ( ( type == 2 ) || ( type == 3 ) )
{
if ( ! F_29 ( V_10 , 1 ) ) goto V_48;
V_10 -> V_14 = V_89 ;
if ( type == 3 )
{
V_10 -> V_82 = V_83 ;
V_10 -> V_67 = V_44 ;
V_10 -> V_49 = & ( V_10 -> V_71 -> V_84 . V_11 [ 0 ] ) ;
memcpy ( V_10 -> V_49 , V_11 , V_44 ) ;
V_10 -> V_71 -> V_84 . V_90 = V_44 ;
V_10 -> V_71 -> V_84 . V_91 = 0 ;
}
else
{
V_10 -> V_67 = 0 ;
V_10 -> V_71 -> V_84 . V_90 = 0 ;
V_10 -> V_71 -> V_84 . V_91 = 0 ;
}
if ( V_10 -> V_56 == V_4 )
V_10 -> V_87 = F_5 () ;
else
V_10 -> V_87 = F_4 () ;
#if 0
s->client_version=(v[0]<<8)|v[1];
#endif
V_10 -> V_88 = V_10 -> V_87 -> V_7 ;
}
if ( ( type < 1 ) || ( type > 3 ) )
{
F_19 ( V_59 , V_92 ) ;
goto V_48;
}
V_10 -> V_29 = 0 ;
if ( V_11 != V_36 ) F_30 ( V_11 ) ;
V_10 -> V_93 = 1 ;
return ( F_31 ( V_10 ) ) ;
V_48:
if ( V_11 != V_36 ) F_30 ( V_11 ) ;
return ( - 1 ) ;
}
