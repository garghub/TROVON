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
T_3 * V_6 ;
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
V_5 -> V_18 = 1 ;
if ( F_7 != NULL ) F_7 ( V_5 , V_19 , 1 ) ;
V_5 -> type = V_16 ;
if ( V_5 -> V_20 == NULL )
{
if ( ( V_6 = F_14 () ) == NULL )
{
V_9 = - 1 ;
goto V_21;
}
if ( ! F_15 ( V_6 , V_22 ) )
{
V_9 = - 1 ;
goto V_21;
}
V_5 -> V_20 = V_6 ;
}
F_16 ( V_5 ) ;
V_5 -> V_11 = V_23 ;
V_5 -> V_13 -> V_24 . V_25 ++ ;
V_5 -> V_26 = 0 ;
break;
case V_23 :
case V_27 :
V_5 -> V_28 = 0 ;
V_9 = F_17 ( V_5 ) ;
if ( V_9 >= 0 ) F_7 = NULL ;
goto V_21;
default:
F_18 ( V_29 , V_30 ) ;
V_9 = - 1 ;
goto V_21;
}
if ( ( F_7 != NULL ) && ( V_5 -> V_11 != V_11 ) )
{
V_10 = V_5 -> V_11 ;
V_5 -> V_11 = V_11 ;
F_7 ( V_5 , V_31 , 1 ) ;
V_5 -> V_11 = V_10 ;
}
}
V_21:
V_5 -> V_14 -- ;
if ( F_7 != NULL )
F_7 ( V_5 , V_32 , V_9 ) ;
return ( V_9 ) ;
}
int F_17 ( T_2 * V_5 )
{
char V_33 [ 11 ] ;
char * V_6 = & ( V_33 [ 0 ] ) ;
unsigned char * V_34 , * V_35 , * V_36 , * V_37 ;
unsigned int V_38 ;
unsigned int V_39 , V_40 , V_41 ;
int V_42 = 0 , V_43 ;
int type = 0 ;
int V_44 [ 2 ] ;
if ( V_5 -> V_11 == V_23 )
{
V_44 [ 0 ] = V_44 [ 1 ] = 0 ;
if ( ! F_19 ( V_5 ) ) goto V_45;
V_42 = F_20 ( V_5 , sizeof V_33 ) ;
if ( V_42 != sizeof V_33 ) return ( V_42 ) ;
V_34 = V_5 -> V_46 ;
memcpy ( V_6 , V_34 , V_42 ) ;
if ( ( V_34 [ 0 ] & 0x80 ) && ( V_34 [ 2 ] == V_47 ) )
{
if ( ( V_34 [ 3 ] == 0x00 ) && ( V_34 [ 4 ] == 0x02 ) )
{
V_44 [ 0 ] = V_34 [ 3 ] ; V_44 [ 1 ] = V_34 [ 4 ] ;
if ( ! ( V_5 -> V_48 & V_49 ) )
type = 1 ;
}
else if ( V_34 [ 3 ] == V_50 )
{
V_44 [ 0 ] = V_34 [ 3 ] ; V_44 [ 1 ] = V_34 [ 4 ] ;
if ( V_34 [ 4 ] >= V_51 )
{
if ( ! ( V_5 -> V_48 & V_52 ) )
{
V_5 -> V_53 = V_4 ;
V_5 -> V_11 = V_27 ;
}
else if ( ! ( V_5 -> V_48 & V_54 ) )
{
V_5 -> V_53 = V_3 ;
V_5 -> V_11 = V_27 ;
}
else if ( ! ( V_5 -> V_48 & V_49 ) )
{
type = 1 ;
}
}
else if ( ! ( V_5 -> V_48 & V_54 ) )
{
V_5 -> V_53 = V_3 ;
V_5 -> V_11 = V_27 ;
}
else if ( ! ( V_5 -> V_48 & V_49 ) )
type = 1 ;
}
}
else if ( ( V_34 [ 0 ] == V_55 ) &&
( V_34 [ 1 ] == V_50 ) &&
( V_34 [ 5 ] == V_56 ) &&
( ( V_34 [ 3 ] == 0 && V_34 [ 4 ] < 5 )
|| ( V_34 [ 9 ] >= V_34 [ 1 ] ) ) )
{
V_44 [ 0 ] = V_34 [ 1 ] ;
if ( V_34 [ 3 ] == 0 && V_34 [ 4 ] < 6 )
{
#if 0
SSLerr(SSL_F_SSL23_GET_CLIENT_HELLO,SSL_R_RECORD_TOO_SMALL);
goto err;
#else
V_44 [ 1 ] = V_51 ;
#endif
}
else if ( V_34 [ 9 ] > V_50 )
V_44 [ 1 ] = 0xff ;
else
V_44 [ 1 ] = V_34 [ 10 ] ;
if ( V_44 [ 1 ] >= V_51 )
{
if ( ! ( V_5 -> V_48 & V_52 ) )
{
V_5 -> V_53 = V_4 ;
type = 3 ;
}
else if ( ! ( V_5 -> V_48 & V_54 ) )
{
V_5 -> V_53 = V_3 ;
type = 3 ;
}
}
else
{
if ( ! ( V_5 -> V_48 & V_54 ) )
{
V_5 -> V_53 = V_3 ;
type = 3 ;
}
else if ( ! ( V_5 -> V_48 & V_52 ) )
{
V_5 -> V_53 = V_4 ;
type = 3 ;
}
}
}
else if ( ( strncmp ( L_1 , ( char * ) V_34 , 4 ) == 0 ) ||
( strncmp ( L_2 , ( char * ) V_34 , 5 ) == 0 ) ||
( strncmp ( L_3 , ( char * ) V_34 , 5 ) == 0 ) ||
( strncmp ( L_4 , ( char * ) V_34 , 4 ) == 0 ) )
{
F_18 ( V_57 , V_58 ) ;
goto V_45;
}
else if ( strncmp ( L_5 , ( char * ) V_34 , 7 ) == 0 )
{
F_18 ( V_57 , V_59 ) ;
goto V_45;
}
}
if ( V_5 -> V_11 == V_27 )
{
type = 2 ;
V_34 = V_5 -> V_46 ;
V_44 [ 0 ] = V_34 [ 3 ] ;
V_44 [ 1 ] = V_34 [ 4 ] ;
V_42 = ( ( V_34 [ 0 ] & 0x7f ) << 8 ) | V_34 [ 1 ] ;
if ( V_42 > ( 1024 * 4 ) )
{
F_18 ( V_57 , V_60 ) ;
goto V_45;
}
V_43 = F_20 ( V_5 , V_42 + 2 ) ;
if ( V_43 <= 0 ) return ( V_43 ) ;
F_21 ( V_5 , V_5 -> V_46 + 2 , V_5 -> V_61 - 2 ) ;
if ( V_5 -> V_62 )
V_5 -> V_62 ( 0 , V_2 , 0 , V_5 -> V_46 + 2 , V_5 -> V_61 - 2 , V_5 , V_5 -> V_63 ) ;
V_34 = V_5 -> V_46 ;
V_34 += 5 ;
F_22 ( V_34 , V_39 ) ;
F_22 ( V_34 , V_40 ) ;
F_22 ( V_34 , V_41 ) ;
V_35 = ( unsigned char * ) V_5 -> V_20 -> V_64 ;
if ( ( V_39 + V_40 + V_41 + 11 ) != V_5 -> V_61 )
{
F_18 ( V_57 , V_65 ) ;
goto V_45;
}
* ( V_35 ++ ) = V_56 ;
V_36 = V_35 ;
V_35 += 3 ;
* ( V_35 ++ ) = V_50 ;
* ( V_35 ++ ) = V_44 [ 1 ] ;
V_38 = ( V_41 > V_66 ) ? V_66 : V_41 ;
memset ( V_35 , 0 , V_66 ) ;
memcpy ( & ( V_35 [ V_66 - V_38 ] ) , & ( V_34 [ V_39 + V_40 ] ) , V_38 ) ;
V_35 += V_66 ;
* ( V_35 ++ ) = 0 ;
V_43 = 0 ;
V_37 = V_35 ;
V_35 += 2 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 += 3 )
{
if ( V_34 [ V_38 ] != 0 ) continue;
* ( V_35 ++ ) = V_34 [ V_38 + 1 ] ;
* ( V_35 ++ ) = V_34 [ V_38 + 2 ] ;
V_43 += 2 ;
}
F_23 ( V_43 , V_37 ) ;
* ( V_35 ++ ) = 1 ;
* ( V_35 ++ ) = 0 ;
#if 0
p = p+csl+sil+cl;
while (p < s->packet+s->packet_length)
{
*(d++)=*(p++);
}
#endif
V_38 = ( V_35 - ( unsigned char * ) V_5 -> V_20 -> V_64 ) - 4 ;
F_24 ( ( long ) V_38 , V_36 ) ;
V_5 -> V_67 -> V_68 . V_69 = 1 ;
V_5 -> V_67 -> V_68 . V_70 = V_56 ;
V_5 -> V_67 -> V_68 . V_71 = V_38 ;
}
if ( type == 1 )
{
#ifdef F_2
F_18 ( V_57 , V_72 ) ;
goto V_45;
#else
if ( V_5 -> V_73 == NULL )
{
if ( ! F_25 ( V_5 ) )
goto V_45;
}
else
F_26 ( V_5 ) ;
if ( V_5 -> V_67 != NULL ) F_27 ( V_5 ) ;
if ( ! F_28 ( V_5 -> V_20 ,
V_74 ) )
{
goto V_45;
}
V_5 -> V_11 = V_75 ;
if ( V_5 -> V_48 & V_52 && V_5 -> V_48 & V_54 )
V_5 -> V_73 -> V_76 = 0 ;
else
V_5 -> V_73 -> V_76 = 1 ;
V_5 -> V_77 = V_78 ;
V_5 -> V_61 = V_42 ;
V_5 -> V_46 = & ( V_5 -> V_73 -> V_79 [ 0 ] ) ;
memcpy ( V_5 -> V_46 , V_6 , V_42 ) ;
V_5 -> V_73 -> V_80 = V_42 ;
V_5 -> V_73 -> V_81 = 0 ;
V_5 -> V_82 = F_3 () ;
V_5 -> V_83 = V_5 -> V_82 -> V_84 ;
#endif
}
if ( ( type == 2 ) || ( type == 3 ) )
{
if ( ! F_29 ( V_5 , 1 ) ) goto V_45;
V_5 -> V_11 = V_85 ;
if ( type == 3 )
{
V_5 -> V_77 = V_78 ;
V_5 -> V_61 = V_42 ;
if ( V_5 -> V_67 -> V_79 . V_6 == NULL )
if ( ! F_30 ( V_5 ) )
goto V_45;
V_5 -> V_46 = & ( V_5 -> V_67 -> V_79 . V_6 [ 0 ] ) ;
memcpy ( V_5 -> V_46 , V_6 , V_42 ) ;
V_5 -> V_67 -> V_79 . V_86 = V_42 ;
V_5 -> V_67 -> V_79 . V_87 = 0 ;
}
else
{
V_5 -> V_61 = 0 ;
V_5 -> V_67 -> V_79 . V_86 = 0 ;
V_5 -> V_67 -> V_79 . V_87 = 0 ;
}
if ( V_5 -> V_53 == V_4 )
V_5 -> V_82 = F_5 () ;
else
V_5 -> V_82 = F_4 () ;
#if 0
s->client_version=(v[0]<<8)|v[1];
#endif
V_5 -> V_83 = V_5 -> V_82 -> V_84 ;
}
if ( ( type < 1 ) || ( type > 3 ) )
{
F_18 ( V_57 , V_88 ) ;
goto V_45;
}
V_5 -> V_26 = 0 ;
if ( V_6 != V_33 ) F_31 ( V_6 ) ;
return ( F_32 ( V_5 ) ) ;
V_45:
if ( V_6 != V_33 ) F_31 ( V_6 ) ;
return ( - 1 ) ;
}
