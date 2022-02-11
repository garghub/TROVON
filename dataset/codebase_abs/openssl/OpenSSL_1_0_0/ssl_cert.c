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
T_1 * F_7 ( void )
{
T_1 * V_4 ;
V_4 = ( T_1 * ) F_8 ( sizeof( T_1 ) ) ;
if ( V_4 == NULL )
{
F_9 ( V_5 , V_6 ) ;
return ( NULL ) ;
}
memset ( V_4 , 0 , sizeof( T_1 ) ) ;
V_4 -> V_7 = & ( V_4 -> V_8 [ V_9 ] ) ;
V_4 -> V_10 = 1 ;
return ( V_4 ) ;
}
T_1 * F_10 ( T_1 * V_11 )
{
T_1 * V_4 ;
int V_12 ;
V_4 = ( T_1 * ) F_8 ( sizeof( T_1 ) ) ;
if ( V_4 == NULL )
{
F_9 ( V_13 , V_6 ) ;
return ( NULL ) ;
}
memset ( V_4 , 0 , sizeof( T_1 ) ) ;
V_4 -> V_7 = & V_4 -> V_8 [ V_11 -> V_7 - & V_11 -> V_8 [ 0 ] ] ;
V_4 -> V_14 = V_11 -> V_14 ;
V_4 -> V_15 = V_11 -> V_15 ;
V_4 -> V_16 = V_11 -> V_16 ;
V_4 -> V_17 = V_11 -> V_17 ;
V_4 -> V_18 = V_11 -> V_18 ;
#ifndef F_11
if ( V_11 -> V_19 != NULL )
{
F_12 ( V_11 -> V_19 ) ;
V_4 -> V_19 = V_11 -> V_19 ;
}
V_4 -> V_20 = V_11 -> V_20 ;
#endif
#ifndef F_13
if ( V_11 -> V_21 != NULL )
{
V_4 -> V_21 = F_14 ( V_11 -> V_21 ) ;
if ( V_4 -> V_21 == NULL )
{
F_9 ( V_13 , V_22 ) ;
goto V_23;
}
if ( V_11 -> V_21 -> V_24 )
{
T_2 * V_25 = F_15 ( V_11 -> V_21 -> V_24 ) ;
if ( ! V_25 )
{
F_9 ( V_13 , V_26 ) ;
goto V_23;
}
V_4 -> V_21 -> V_24 = V_25 ;
}
if ( V_11 -> V_21 -> V_27 )
{
T_2 * V_25 = F_15 ( V_11 -> V_21 -> V_27 ) ;
if ( ! V_25 )
{
F_9 ( V_13 , V_26 ) ;
goto V_23;
}
V_4 -> V_21 -> V_27 = V_25 ;
}
}
V_4 -> V_28 = V_11 -> V_28 ;
#endif
#ifndef F_16
if ( V_11 -> V_29 )
{
V_4 -> V_29 = F_17 ( V_11 -> V_29 ) ;
if ( V_4 -> V_29 == NULL )
{
F_9 ( V_13 , V_30 ) ;
goto V_23;
}
}
V_4 -> V_31 = V_11 -> V_31 ;
#endif
for ( V_12 = 0 ; V_12 < V_32 ; V_12 ++ )
{
if ( V_11 -> V_8 [ V_12 ] . V_33 != NULL )
{
V_4 -> V_8 [ V_12 ] . V_33 = V_11 -> V_8 [ V_12 ] . V_33 ;
F_18 ( & V_4 -> V_8 [ V_12 ] . V_33 -> V_10 , 1 ,
V_34 ) ;
}
if ( V_11 -> V_8 [ V_12 ] . V_35 != NULL )
{
V_4 -> V_8 [ V_12 ] . V_35 = V_11 -> V_8 [ V_12 ] . V_35 ;
F_18 ( & V_4 -> V_8 [ V_12 ] . V_35 -> V_10 , 1 ,
V_36 ) ;
switch( V_12 )
{
case V_9 :
case V_37 :
break;
case V_38 :
break;
case V_39 :
case V_40 :
break;
case V_41 :
break;
default:
F_9 ( V_13 , V_42 ) ;
}
}
}
V_4 -> V_10 = 1 ;
return ( V_4 ) ;
#if ! F_19 ( F_13 ) || ! F_19 ( F_16 )
V_23:
#endif
#ifndef F_11
if ( V_4 -> V_19 != NULL )
F_20 ( V_4 -> V_19 ) ;
#endif
#ifndef F_13
if ( V_4 -> V_21 != NULL )
F_21 ( V_4 -> V_21 ) ;
#endif
#ifndef F_16
if ( V_4 -> V_29 != NULL )
F_22 ( V_4 -> V_29 ) ;
#endif
for ( V_12 = 0 ; V_12 < V_32 ; V_12 ++ )
{
if ( V_4 -> V_8 [ V_12 ] . V_33 != NULL )
F_23 ( V_4 -> V_8 [ V_12 ] . V_33 ) ;
if ( V_4 -> V_8 [ V_12 ] . V_35 != NULL )
F_24 ( V_4 -> V_8 [ V_12 ] . V_35 ) ;
}
return NULL ;
}
void F_25 ( T_1 * V_43 )
{
int V_12 ;
if( V_43 == NULL )
return;
V_12 = F_18 ( & V_43 -> V_10 , - 1 , V_44 ) ;
#ifdef F_26
F_26 ( L_2 , V_43 ) ;
#endif
if ( V_12 > 0 ) return;
#ifdef F_27
if ( V_12 < 0 )
{
fprintf ( V_45 , L_3 ) ;
abort () ;
}
#endif
#ifndef F_11
if ( V_43 -> V_19 ) F_20 ( V_43 -> V_19 ) ;
#endif
#ifndef F_13
if ( V_43 -> V_21 ) F_21 ( V_43 -> V_21 ) ;
#endif
#ifndef F_16
if ( V_43 -> V_29 ) F_22 ( V_43 -> V_29 ) ;
#endif
for ( V_12 = 0 ; V_12 < V_32 ; V_12 ++ )
{
if ( V_43 -> V_8 [ V_12 ] . V_33 != NULL )
F_23 ( V_43 -> V_8 [ V_12 ] . V_33 ) ;
if ( V_43 -> V_8 [ V_12 ] . V_35 != NULL )
F_24 ( V_43 -> V_8 [ V_12 ] . V_35 ) ;
#if 0
if (c->pkeys[i].publickey != NULL)
EVP_PKEY_free(c->pkeys[i].publickey);
#endif
}
F_28 ( V_43 ) ;
}
int F_29 ( T_1 * * V_46 )
{
if ( V_46 == NULL )
{
F_9 ( V_47 , V_48 ) ;
return ( 0 ) ;
}
if ( * V_46 == NULL )
{
if ( ( * V_46 = F_7 () ) == NULL )
{
F_9 ( V_47 , V_6 ) ;
return ( 0 ) ;
}
}
return ( 1 ) ;
}
T_3 * F_30 ( void )
{
T_3 * V_4 ;
V_4 = F_8 ( sizeof *V_4 ) ;
if ( V_4 == NULL )
{
F_9 ( V_49 , V_6 ) ;
return NULL ;
}
memset ( V_4 , 0 , sizeof *V_4 ) ;
V_4 -> V_50 = & ( V_4 -> V_51 [ V_9 ] ) ;
V_4 -> V_10 = 1 ;
return V_4 ;
}
void F_31 ( T_3 * V_52 )
{
int V_12 ;
if ( V_52 == NULL )
return;
V_12 = F_18 ( & V_52 -> V_10 , - 1 , V_53 ) ;
#ifdef F_26
F_26 ( L_4 , V_52 ) ;
#endif
if ( V_12 > 0 )
return;
#ifdef F_27
if ( V_12 < 0 )
{
fprintf ( V_45 , L_5 ) ;
abort () ;
}
#endif
if ( V_52 -> V_54 != NULL )
F_32 ( V_52 -> V_54 , F_23 ) ;
for ( V_12 = 0 ; V_12 < V_32 ; V_12 ++ )
{
if ( V_52 -> V_51 [ V_12 ] . V_33 != NULL )
F_23 ( V_52 -> V_51 [ V_12 ] . V_33 ) ;
#if 0
if (sc->peer_pkeys[i].privatekey != NULL)
EVP_PKEY_free(sc->peer_pkeys[i].privatekey);
#endif
}
#ifndef F_11
if ( V_52 -> V_55 != NULL )
F_20 ( V_52 -> V_55 ) ;
#endif
#ifndef F_13
if ( V_52 -> V_56 != NULL )
F_21 ( V_52 -> V_56 ) ;
#endif
#ifndef F_16
if ( V_52 -> V_57 != NULL )
F_22 ( V_52 -> V_57 ) ;
#endif
F_28 ( V_52 ) ;
}
int F_33 ( T_3 * V_52 , int type )
{
V_52 -> V_58 = type ;
return ( 1 ) ;
}
int F_34 ( T_4 * V_59 , T_5 * V_60 )
{
return ( F_35 ( & ( V_59 -> V_61 ) , V_60 ) ) ;
}
int F_36 ( T_6 * V_62 , T_5 * V_60 )
{
return ( F_35 ( & ( V_62 -> V_61 ) , V_60 ) ) ;
}
static int F_37 ( const T_7 * const * V_63 , const T_7 * const * V_25 )
{
return ( F_38 ( * V_63 , * V_25 ) ) ;
}
