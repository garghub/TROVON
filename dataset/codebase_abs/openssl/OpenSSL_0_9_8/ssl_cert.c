int F_1 ( void )
{
static volatile int V_1 = - 1 ;
if ( V_1 < 0 )
{
F_2 ( V_2 ) ;
if ( V_1 < 0 )
{
V_1 = F_3 (
0 , L_1 , NULL , NULL , NULL ) ;
}
F_4 ( V_2 ) ;
}
return V_1 ;
}
T_1 * F_5 ( void )
{
T_1 * V_3 ;
V_3 = ( T_1 * ) F_6 ( sizeof( T_1 ) ) ;
if ( V_3 == NULL )
{
F_7 ( V_4 , V_5 ) ;
return ( NULL ) ;
}
memset ( V_3 , 0 , sizeof( T_1 ) ) ;
V_3 -> V_6 = & ( V_3 -> V_7 [ V_8 ] ) ;
V_3 -> V_9 = 1 ;
return ( V_3 ) ;
}
T_1 * F_8 ( T_1 * V_10 )
{
T_1 * V_3 ;
int V_11 ;
V_3 = ( T_1 * ) F_6 ( sizeof( T_1 ) ) ;
if ( V_3 == NULL )
{
F_7 ( V_12 , V_5 ) ;
return ( NULL ) ;
}
memset ( V_3 , 0 , sizeof( T_1 ) ) ;
V_3 -> V_6 = & V_3 -> V_7 [ V_10 -> V_6 - & V_10 -> V_7 [ 0 ] ] ;
V_3 -> V_13 = V_10 -> V_13 ;
V_3 -> V_14 = V_10 -> V_14 ;
V_3 -> V_15 = V_10 -> V_15 ;
#ifndef F_9
if ( V_10 -> V_16 != NULL )
{
F_10 ( V_10 -> V_16 ) ;
V_3 -> V_16 = V_10 -> V_16 ;
}
V_3 -> V_17 = V_10 -> V_17 ;
#endif
#ifndef F_11
if ( V_10 -> V_18 != NULL )
{
V_3 -> V_18 = F_12 ( V_10 -> V_18 ) ;
if ( V_3 -> V_18 == NULL )
{
F_7 ( V_12 , V_19 ) ;
goto V_20;
}
if ( V_10 -> V_18 -> V_21 )
{
T_2 * V_22 = F_13 ( V_10 -> V_18 -> V_21 ) ;
if ( ! V_22 )
{
F_7 ( V_12 , V_23 ) ;
goto V_20;
}
V_3 -> V_18 -> V_21 = V_22 ;
}
if ( V_10 -> V_18 -> V_24 )
{
T_2 * V_22 = F_13 ( V_10 -> V_18 -> V_24 ) ;
if ( ! V_22 )
{
F_7 ( V_12 , V_23 ) ;
goto V_20;
}
V_3 -> V_18 -> V_24 = V_22 ;
}
}
V_3 -> V_25 = V_10 -> V_25 ;
#endif
#ifndef F_14
if ( V_10 -> V_26 )
{
F_15 ( V_10 -> V_26 ) ;
V_3 -> V_26 = V_10 -> V_26 ;
}
V_3 -> V_27 = V_10 -> V_27 ;
#endif
for ( V_11 = 0 ; V_11 < V_28 ; V_11 ++ )
{
if ( V_10 -> V_7 [ V_11 ] . V_29 != NULL )
{
V_3 -> V_7 [ V_11 ] . V_29 = V_10 -> V_7 [ V_11 ] . V_29 ;
F_16 ( & V_3 -> V_7 [ V_11 ] . V_29 -> V_9 , 1 ,
V_30 ) ;
}
if ( V_10 -> V_7 [ V_11 ] . V_31 != NULL )
{
V_3 -> V_7 [ V_11 ] . V_31 = V_10 -> V_7 [ V_11 ] . V_31 ;
F_16 ( & V_3 -> V_7 [ V_11 ] . V_31 -> V_9 , 1 ,
V_32 ) ;
switch( V_11 )
{
case V_8 :
case V_33 :
break;
case V_34 :
break;
case V_35 :
case V_36 :
break;
case V_37 :
break;
default:
F_7 ( V_12 , V_38 ) ;
}
}
}
V_3 -> V_9 = 1 ;
return ( V_3 ) ;
#ifndef F_11
V_20:
#endif
#ifndef F_9
if ( V_3 -> V_16 != NULL )
F_17 ( V_3 -> V_16 ) ;
#endif
#ifndef F_11
if ( V_3 -> V_18 != NULL )
F_18 ( V_3 -> V_18 ) ;
#endif
#ifndef F_14
if ( V_3 -> V_26 != NULL )
F_19 ( V_3 -> V_26 ) ;
#endif
for ( V_11 = 0 ; V_11 < V_28 ; V_11 ++ )
{
if ( V_3 -> V_7 [ V_11 ] . V_29 != NULL )
F_20 ( V_3 -> V_7 [ V_11 ] . V_29 ) ;
if ( V_3 -> V_7 [ V_11 ] . V_31 != NULL )
F_21 ( V_3 -> V_7 [ V_11 ] . V_31 ) ;
}
return NULL ;
}
void F_22 ( T_1 * V_39 )
{
int V_11 ;
if( V_39 == NULL )
return;
V_11 = F_16 ( & V_39 -> V_9 , - 1 , V_40 ) ;
#ifdef F_23
F_23 ( L_2 , V_39 ) ;
#endif
if ( V_11 > 0 ) return;
#ifdef F_24
if ( V_11 < 0 )
{
fprintf ( V_41 , L_3 ) ;
abort () ;
}
#endif
#ifndef F_9
if ( V_39 -> V_16 ) F_17 ( V_39 -> V_16 ) ;
#endif
#ifndef F_11
if ( V_39 -> V_18 ) F_18 ( V_39 -> V_18 ) ;
#endif
#ifndef F_14
if ( V_39 -> V_26 ) F_19 ( V_39 -> V_26 ) ;
#endif
for ( V_11 = 0 ; V_11 < V_28 ; V_11 ++ )
{
if ( V_39 -> V_7 [ V_11 ] . V_29 != NULL )
F_20 ( V_39 -> V_7 [ V_11 ] . V_29 ) ;
if ( V_39 -> V_7 [ V_11 ] . V_31 != NULL )
F_21 ( V_39 -> V_7 [ V_11 ] . V_31 ) ;
#if 0
if (c->pkeys[i].publickey != NULL)
EVP_PKEY_free(c->pkeys[i].publickey);
#endif
}
F_25 ( V_39 ) ;
}
int F_26 ( T_1 * * V_42 )
{
if ( V_42 == NULL )
{
F_7 ( V_43 , V_44 ) ;
return ( 0 ) ;
}
if ( * V_42 == NULL )
{
if ( ( * V_42 = F_5 () ) == NULL )
{
F_7 ( V_43 , V_5 ) ;
return ( 0 ) ;
}
}
return ( 1 ) ;
}
T_3 * F_27 ( void )
{
T_3 * V_3 ;
V_3 = F_6 ( sizeof *V_3 ) ;
if ( V_3 == NULL )
{
F_7 ( V_45 , V_5 ) ;
return NULL ;
}
memset ( V_3 , 0 , sizeof *V_3 ) ;
V_3 -> V_46 = & ( V_3 -> V_47 [ V_8 ] ) ;
V_3 -> V_9 = 1 ;
return V_3 ;
}
void F_28 ( T_3 * V_48 )
{
int V_11 ;
if ( V_48 == NULL )
return;
V_11 = F_16 ( & V_48 -> V_9 , - 1 , V_49 ) ;
#ifdef F_23
F_23 ( L_4 , V_48 ) ;
#endif
if ( V_11 > 0 )
return;
#ifdef F_24
if ( V_11 < 0 )
{
fprintf ( V_41 , L_5 ) ;
abort () ;
}
#endif
if ( V_48 -> V_50 != NULL )
F_29 ( V_48 -> V_50 , F_20 ) ;
for ( V_11 = 0 ; V_11 < V_28 ; V_11 ++ )
{
if ( V_48 -> V_47 [ V_11 ] . V_29 != NULL )
F_20 ( V_48 -> V_47 [ V_11 ] . V_29 ) ;
#if 0
if (sc->peer_pkeys[i].privatekey != NULL)
EVP_PKEY_free(sc->peer_pkeys[i].privatekey);
#endif
}
#ifndef F_9
if ( V_48 -> V_51 != NULL )
F_17 ( V_48 -> V_51 ) ;
#endif
#ifndef F_11
if ( V_48 -> V_52 != NULL )
F_18 ( V_48 -> V_52 ) ;
#endif
#ifndef F_14
if ( V_48 -> V_53 != NULL )
F_19 ( V_48 -> V_53 ) ;
#endif
F_25 ( V_48 ) ;
}
int F_30 ( T_3 * V_48 , int type )
{
V_48 -> V_54 = type ;
return ( 1 ) ;
}
int F_31 ( T_4 * V_55 , T_5 * V_56 )
{
return ( F_32 ( & ( V_55 -> V_57 ) , V_56 ) ) ;
}
int F_33 ( T_6 * V_58 , T_5 * V_56 )
{
return ( F_32 ( & ( V_58 -> V_57 ) , V_56 ) ) ;
}
static int F_34 ( const T_7 * const * V_59 , const T_7 * const * V_22 )
{
return ( F_35 ( * V_59 , * V_22 ) ) ;
}
