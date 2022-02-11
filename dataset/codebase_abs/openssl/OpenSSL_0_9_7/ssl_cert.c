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
for ( V_11 = 0 ; V_11 < V_26 ; V_11 ++ )
{
if ( V_10 -> V_7 [ V_11 ] . V_27 != NULL )
{
V_3 -> V_7 [ V_11 ] . V_27 = V_10 -> V_7 [ V_11 ] . V_27 ;
F_14 ( & V_3 -> V_7 [ V_11 ] . V_27 -> V_9 , 1 ,
V_28 ) ;
}
if ( V_10 -> V_7 [ V_11 ] . V_29 != NULL )
{
V_3 -> V_7 [ V_11 ] . V_29 = V_10 -> V_7 [ V_11 ] . V_29 ;
F_14 ( & V_3 -> V_7 [ V_11 ] . V_29 -> V_9 , 1 ,
V_30 ) ;
switch( V_11 )
{
case V_8 :
case V_31 :
break;
case V_32 :
break;
case V_33 :
case V_34 :
break;
default:
F_7 ( V_12 , V_35 ) ;
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
F_15 ( V_3 -> V_16 ) ;
#endif
#ifndef F_11
if ( V_3 -> V_18 != NULL )
F_16 ( V_3 -> V_18 ) ;
#endif
for ( V_11 = 0 ; V_11 < V_26 ; V_11 ++ )
{
if ( V_3 -> V_7 [ V_11 ] . V_27 != NULL )
F_17 ( V_3 -> V_7 [ V_11 ] . V_27 ) ;
if ( V_3 -> V_7 [ V_11 ] . V_29 != NULL )
F_18 ( V_3 -> V_7 [ V_11 ] . V_29 ) ;
}
return NULL ;
}
void F_19 ( T_1 * V_36 )
{
int V_11 ;
if( V_36 == NULL )
return;
V_11 = F_14 ( & V_36 -> V_9 , - 1 , V_37 ) ;
#ifdef F_20
F_20 ( L_2 , V_36 ) ;
#endif
if ( V_11 > 0 ) return;
#ifdef F_21
if ( V_11 < 0 )
{
fprintf ( V_38 , L_3 ) ;
abort () ;
}
#endif
#ifndef F_9
if ( V_36 -> V_16 ) F_15 ( V_36 -> V_16 ) ;
#endif
#ifndef F_11
if ( V_36 -> V_18 ) F_16 ( V_36 -> V_18 ) ;
#endif
for ( V_11 = 0 ; V_11 < V_26 ; V_11 ++ )
{
if ( V_36 -> V_7 [ V_11 ] . V_27 != NULL )
F_17 ( V_36 -> V_7 [ V_11 ] . V_27 ) ;
if ( V_36 -> V_7 [ V_11 ] . V_29 != NULL )
F_18 ( V_36 -> V_7 [ V_11 ] . V_29 ) ;
#if 0
if (c->pkeys[i].publickey != NULL)
EVP_PKEY_free(c->pkeys[i].publickey);
#endif
}
F_22 ( V_36 ) ;
}
int F_23 ( T_1 * * V_39 )
{
if ( V_39 == NULL )
{
F_7 ( V_40 , V_41 ) ;
return ( 0 ) ;
}
if ( * V_39 == NULL )
{
if ( ( * V_39 = F_5 () ) == NULL )
{
F_7 ( V_40 , V_5 ) ;
return ( 0 ) ;
}
}
return ( 1 ) ;
}
T_3 * F_24 ( void )
{
T_3 * V_3 ;
V_3 = F_6 ( sizeof *V_3 ) ;
if ( V_3 == NULL )
{
F_7 ( V_42 , V_5 ) ;
return NULL ;
}
memset ( V_3 , 0 , sizeof *V_3 ) ;
V_3 -> V_43 = & ( V_3 -> V_44 [ V_8 ] ) ;
V_3 -> V_9 = 1 ;
return V_3 ;
}
void F_25 ( T_3 * V_45 )
{
int V_11 ;
if ( V_45 == NULL )
return;
V_11 = F_14 ( & V_45 -> V_9 , - 1 , V_46 ) ;
#ifdef F_20
F_20 ( L_4 , V_45 ) ;
#endif
if ( V_11 > 0 )
return;
#ifdef F_21
if ( V_11 < 0 )
{
fprintf ( V_38 , L_5 ) ;
abort () ;
}
#endif
if ( V_45 -> V_47 != NULL )
F_26 ( V_45 -> V_47 , F_17 ) ;
for ( V_11 = 0 ; V_11 < V_26 ; V_11 ++ )
{
if ( V_45 -> V_44 [ V_11 ] . V_27 != NULL )
F_17 ( V_45 -> V_44 [ V_11 ] . V_27 ) ;
#if 0
if (sc->peer_pkeys[i].privatekey != NULL)
EVP_PKEY_free(sc->peer_pkeys[i].privatekey);
#endif
}
#ifndef F_9
if ( V_45 -> V_48 != NULL )
F_15 ( V_45 -> V_48 ) ;
#endif
#ifndef F_11
if ( V_45 -> V_49 != NULL )
F_16 ( V_45 -> V_49 ) ;
#endif
F_22 ( V_45 ) ;
}
int F_27 ( T_3 * V_45 , int type )
{
V_45 -> V_50 = type ;
return ( 1 ) ;
}
int F_28 ( T_4 * V_51 , T_5 * V_52 )
{
return ( F_29 ( & ( V_51 -> V_53 ) , V_52 ) ) ;
}
int F_30 ( T_6 * V_54 , T_5 * V_52 )
{
return ( F_29 ( & ( V_54 -> V_53 ) , V_52 ) ) ;
}
static int F_31 ( const T_7 * const * V_55 , const T_7 * const * V_22 )
{
return ( F_32 ( * V_55 , * V_22 ) ) ;
}
