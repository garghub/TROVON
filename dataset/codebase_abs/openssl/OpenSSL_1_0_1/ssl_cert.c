int F_1 ( void )
{
static volatile int V_1 = - 1 ;
int V_2 = 0 ;
F_2 ( V_3 ) ;
if ( V_1 < 0 )
{
F_3 ( V_3 ) ;
F_4 ( V_3 ) ;
V_2 = 1 ;
if ( V_1 < 0 )
{
V_1 = F_5 (
0 , L_1 , NULL , NULL , NULL ) ;
}
}
if ( V_2 )
F_6 ( V_3 ) ;
else
F_3 ( V_3 ) ;
return V_1 ;
}
static void F_7 ( T_1 * V_4 )
{
#ifndef F_8
V_4 -> V_5 [ V_6 ] . V_7 = F_9 () ;
#endif
#ifndef F_10
V_4 -> V_5 [ V_8 ] . V_7 = F_11 () ;
V_4 -> V_5 [ V_9 ] . V_7 = F_11 () ;
#endif
#ifndef F_12
V_4 -> V_5 [ V_10 ] . V_7 = F_13 () ;
#endif
}
T_1 * F_14 ( void )
{
T_1 * V_11 ;
V_11 = ( T_1 * ) F_15 ( sizeof( T_1 ) ) ;
if ( V_11 == NULL )
{
F_16 ( V_12 , V_13 ) ;
return ( NULL ) ;
}
memset ( V_11 , 0 , sizeof( T_1 ) ) ;
V_11 -> V_14 = & ( V_11 -> V_5 [ V_9 ] ) ;
V_11 -> V_15 = 1 ;
F_7 ( V_11 ) ;
return ( V_11 ) ;
}
T_1 * F_17 ( T_1 * V_4 )
{
T_1 * V_11 ;
int V_16 ;
V_11 = ( T_1 * ) F_15 ( sizeof( T_1 ) ) ;
if ( V_11 == NULL )
{
F_16 ( V_17 , V_13 ) ;
return ( NULL ) ;
}
memset ( V_11 , 0 , sizeof( T_1 ) ) ;
V_11 -> V_14 = & V_11 -> V_5 [ V_4 -> V_14 - & V_4 -> V_5 [ 0 ] ] ;
V_11 -> V_18 = V_4 -> V_18 ;
V_11 -> V_19 = V_4 -> V_19 ;
V_11 -> V_20 = V_4 -> V_20 ;
V_11 -> V_21 = V_4 -> V_21 ;
V_11 -> V_22 = V_4 -> V_22 ;
#ifndef F_10
if ( V_4 -> V_23 != NULL )
{
F_18 ( V_4 -> V_23 ) ;
V_11 -> V_23 = V_4 -> V_23 ;
}
V_11 -> V_24 = V_4 -> V_24 ;
#endif
#ifndef F_19
if ( V_4 -> V_25 != NULL )
{
V_11 -> V_25 = F_20 ( V_4 -> V_25 ) ;
if ( V_11 -> V_25 == NULL )
{
F_16 ( V_17 , V_26 ) ;
goto V_27;
}
if ( V_4 -> V_25 -> V_28 )
{
T_2 * V_29 = F_21 ( V_4 -> V_25 -> V_28 ) ;
if ( ! V_29 )
{
F_16 ( V_17 , V_30 ) ;
goto V_27;
}
V_11 -> V_25 -> V_28 = V_29 ;
}
if ( V_4 -> V_25 -> V_31 )
{
T_2 * V_29 = F_21 ( V_4 -> V_25 -> V_31 ) ;
if ( ! V_29 )
{
F_16 ( V_17 , V_30 ) ;
goto V_27;
}
V_11 -> V_25 -> V_31 = V_29 ;
}
}
V_11 -> V_32 = V_4 -> V_32 ;
#endif
#ifndef F_22
if ( V_4 -> V_33 )
{
V_11 -> V_33 = F_23 ( V_4 -> V_33 ) ;
if ( V_11 -> V_33 == NULL )
{
F_16 ( V_17 , V_34 ) ;
goto V_27;
}
}
V_11 -> V_35 = V_4 -> V_35 ;
#endif
for ( V_16 = 0 ; V_16 < V_36 ; V_16 ++ )
{
if ( V_4 -> V_5 [ V_16 ] . V_37 != NULL )
{
V_11 -> V_5 [ V_16 ] . V_37 = V_4 -> V_5 [ V_16 ] . V_37 ;
F_24 ( & V_11 -> V_5 [ V_16 ] . V_37 -> V_15 , 1 ,
V_38 ) ;
}
if ( V_4 -> V_5 [ V_16 ] . V_39 != NULL )
{
V_11 -> V_5 [ V_16 ] . V_39 = V_4 -> V_5 [ V_16 ] . V_39 ;
F_24 ( & V_11 -> V_5 [ V_16 ] . V_39 -> V_15 , 1 ,
V_40 ) ;
switch( V_16 )
{
case V_9 :
case V_8 :
break;
case V_6 :
break;
case V_41 :
case V_42 :
break;
case V_10 :
break;
default:
F_16 ( V_17 , V_43 ) ;
}
}
}
V_11 -> V_15 = 1 ;
F_7 ( V_11 ) ;
return ( V_11 ) ;
#if ! F_25 ( F_19 ) || ! F_25 ( F_22 )
V_27:
#endif
#ifndef F_10
if ( V_11 -> V_23 != NULL )
F_26 ( V_11 -> V_23 ) ;
#endif
#ifndef F_19
if ( V_11 -> V_25 != NULL )
F_27 ( V_11 -> V_25 ) ;
#endif
#ifndef F_22
if ( V_11 -> V_33 != NULL )
F_28 ( V_11 -> V_33 ) ;
#endif
for ( V_16 = 0 ; V_16 < V_36 ; V_16 ++ )
{
if ( V_11 -> V_5 [ V_16 ] . V_37 != NULL )
F_29 ( V_11 -> V_5 [ V_16 ] . V_37 ) ;
if ( V_11 -> V_5 [ V_16 ] . V_39 != NULL )
F_30 ( V_11 -> V_5 [ V_16 ] . V_39 ) ;
}
return NULL ;
}
void F_31 ( T_1 * V_44 )
{
int V_16 ;
if( V_44 == NULL )
return;
V_16 = F_24 ( & V_44 -> V_15 , - 1 , V_45 ) ;
#ifdef F_32
F_32 ( L_2 , V_44 ) ;
#endif
if ( V_16 > 0 ) return;
#ifdef F_33
if ( V_16 < 0 )
{
fprintf ( V_46 , L_3 ) ;
abort () ;
}
#endif
#ifndef F_10
if ( V_44 -> V_23 ) F_26 ( V_44 -> V_23 ) ;
#endif
#ifndef F_19
if ( V_44 -> V_25 ) F_27 ( V_44 -> V_25 ) ;
#endif
#ifndef F_22
if ( V_44 -> V_33 ) F_28 ( V_44 -> V_33 ) ;
#endif
for ( V_16 = 0 ; V_16 < V_36 ; V_16 ++ )
{
if ( V_44 -> V_5 [ V_16 ] . V_37 != NULL )
F_29 ( V_44 -> V_5 [ V_16 ] . V_37 ) ;
if ( V_44 -> V_5 [ V_16 ] . V_39 != NULL )
F_30 ( V_44 -> V_5 [ V_16 ] . V_39 ) ;
#if 0
if (c->pkeys[i].publickey != NULL)
EVP_PKEY_free(c->pkeys[i].publickey);
#endif
}
F_34 ( V_44 ) ;
}
int F_35 ( T_1 * * V_47 )
{
if ( V_47 == NULL )
{
F_16 ( V_48 , V_49 ) ;
return ( 0 ) ;
}
if ( * V_47 == NULL )
{
if ( ( * V_47 = F_14 () ) == NULL )
{
F_16 ( V_48 , V_13 ) ;
return ( 0 ) ;
}
}
return ( 1 ) ;
}
T_3 * F_36 ( void )
{
T_3 * V_11 ;
V_11 = F_15 ( sizeof *V_11 ) ;
if ( V_11 == NULL )
{
F_16 ( V_50 , V_13 ) ;
return NULL ;
}
memset ( V_11 , 0 , sizeof *V_11 ) ;
V_11 -> V_51 = & ( V_11 -> V_52 [ V_9 ] ) ;
V_11 -> V_15 = 1 ;
return V_11 ;
}
void F_37 ( T_3 * V_53 )
{
int V_16 ;
if ( V_53 == NULL )
return;
V_16 = F_24 ( & V_53 -> V_15 , - 1 , V_54 ) ;
#ifdef F_32
F_32 ( L_4 , V_53 ) ;
#endif
if ( V_16 > 0 )
return;
#ifdef F_33
if ( V_16 < 0 )
{
fprintf ( V_46 , L_5 ) ;
abort () ;
}
#endif
if ( V_53 -> V_55 != NULL )
F_38 ( V_53 -> V_55 , F_29 ) ;
for ( V_16 = 0 ; V_16 < V_36 ; V_16 ++ )
{
if ( V_53 -> V_52 [ V_16 ] . V_37 != NULL )
F_29 ( V_53 -> V_52 [ V_16 ] . V_37 ) ;
#if 0
if (sc->peer_pkeys[i].privatekey != NULL)
EVP_PKEY_free(sc->peer_pkeys[i].privatekey);
#endif
}
#ifndef F_10
if ( V_53 -> V_56 != NULL )
F_26 ( V_53 -> V_56 ) ;
#endif
#ifndef F_19
if ( V_53 -> V_57 != NULL )
F_27 ( V_53 -> V_57 ) ;
#endif
#ifndef F_22
if ( V_53 -> V_58 != NULL )
F_28 ( V_53 -> V_58 ) ;
#endif
F_34 ( V_53 ) ;
}
int F_39 ( T_3 * V_53 , int type )
{
V_53 -> V_59 = type ;
return ( 1 ) ;
}
int F_40 ( T_4 * V_60 , T_5 * V_61 )
{
return ( F_41 ( & ( V_60 -> V_62 ) , V_61 ) ) ;
}
int F_42 ( T_6 * V_63 , T_5 * V_61 )
{
return ( F_41 ( & ( V_63 -> V_62 ) , V_61 ) ) ;
}
static int F_43 ( const T_7 * const * V_64 , const T_7 * const * V_29 )
{
return ( F_44 ( * V_64 , * V_29 ) ) ;
}
