int F_1 ( void )
{
static int V_1 = - 1 ;
if ( V_1 < 0 )
{
V_1 = F_2 (
0 , L_1 , NULL , NULL , NULL ) ;
}
return ( V_1 ) ;
}
T_1 * F_3 ( void )
{
T_1 * V_2 ;
V_2 = ( T_1 * ) F_4 ( sizeof( T_1 ) ) ;
if ( V_2 == NULL )
{
F_5 ( V_3 , V_4 ) ;
return ( NULL ) ;
}
memset ( V_2 , 0 , sizeof( T_1 ) ) ;
V_2 -> V_5 = & ( V_2 -> V_6 [ V_7 ] ) ;
V_2 -> V_8 = 1 ;
return ( V_2 ) ;
}
T_1 * F_6 ( T_1 * V_9 )
{
T_1 * V_2 ;
int V_10 ;
V_2 = ( T_1 * ) F_4 ( sizeof( T_1 ) ) ;
if ( V_2 == NULL )
{
F_5 ( V_11 , V_4 ) ;
return ( NULL ) ;
}
memset ( V_2 , 0 , sizeof( T_1 ) ) ;
V_2 -> V_5 = & V_2 -> V_6 [ V_9 -> V_5 - & V_9 -> V_6 [ 0 ] ] ;
V_2 -> V_12 = V_9 -> V_12 ;
V_2 -> V_13 = V_9 -> V_13 ;
V_2 -> V_14 = V_9 -> V_14 ;
#ifndef F_7
if ( V_9 -> V_15 != NULL )
{
V_2 -> V_15 = V_9 -> V_15 ;
F_8 ( & V_2 -> V_15 -> V_8 , 1 , V_16 ) ;
}
V_2 -> V_17 = V_9 -> V_17 ;
#endif
#ifndef F_9
if ( V_9 -> V_18 != NULL )
{
V_2 -> V_18 = F_10 ( V_9 -> V_18 ) ;
if ( V_2 -> V_18 == NULL )
{
F_5 ( V_11 , V_19 ) ;
goto V_20;
}
if ( V_9 -> V_18 -> V_21 )
{
T_2 * V_22 = F_11 ( V_9 -> V_18 -> V_21 ) ;
if ( ! V_22 )
{
F_5 ( V_11 , V_23 ) ;
goto V_20;
}
V_2 -> V_18 -> V_21 = V_22 ;
}
if ( V_9 -> V_18 -> V_24 )
{
T_2 * V_22 = F_11 ( V_9 -> V_18 -> V_24 ) ;
if ( ! V_22 )
{
F_5 ( V_11 , V_23 ) ;
goto V_20;
}
V_2 -> V_18 -> V_24 = V_22 ;
}
}
V_2 -> V_25 = V_9 -> V_25 ;
#endif
for ( V_10 = 0 ; V_10 < V_26 ; V_10 ++ )
{
if ( V_9 -> V_6 [ V_10 ] . V_27 != NULL )
{
V_2 -> V_6 [ V_10 ] . V_27 = V_9 -> V_6 [ V_10 ] . V_27 ;
F_8 ( & V_2 -> V_6 [ V_10 ] . V_27 -> V_8 , 1 ,
V_28 ) ;
}
if ( V_9 -> V_6 [ V_10 ] . V_29 != NULL )
{
V_2 -> V_6 [ V_10 ] . V_29 = V_9 -> V_6 [ V_10 ] . V_29 ;
F_8 ( & V_2 -> V_6 [ V_10 ] . V_29 -> V_8 , 1 ,
V_30 ) ;
switch( V_10 )
{
case V_7 :
case V_31 :
break;
case V_32 :
break;
case V_33 :
case V_34 :
break;
default:
F_5 ( V_11 , V_35 ) ;
}
}
}
V_2 -> V_8 = 1 ;
return ( V_2 ) ;
V_20:
#ifndef F_7
if ( V_2 -> V_15 != NULL )
F_12 ( V_2 -> V_15 ) ;
#endif
#ifndef F_9
if ( V_2 -> V_18 != NULL )
F_13 ( V_2 -> V_18 ) ;
#endif
for ( V_10 = 0 ; V_10 < V_26 ; V_10 ++ )
{
if ( V_2 -> V_6 [ V_10 ] . V_27 != NULL )
F_14 ( V_2 -> V_6 [ V_10 ] . V_27 ) ;
if ( V_2 -> V_6 [ V_10 ] . V_29 != NULL )
F_15 ( V_2 -> V_6 [ V_10 ] . V_29 ) ;
}
return NULL ;
}
void F_16 ( T_1 * V_36 )
{
int V_10 ;
if( V_36 == NULL )
return;
V_10 = F_8 ( & V_36 -> V_8 , - 1 , V_37 ) ;
#ifdef F_17
F_17 ( L_2 , V_36 ) ;
#endif
if ( V_10 > 0 ) return;
#ifdef F_18
if ( V_10 < 0 )
{
fprintf ( V_38 , L_3 ) ;
abort () ;
}
#endif
#ifndef F_7
if ( V_36 -> V_15 ) F_12 ( V_36 -> V_15 ) ;
#endif
#ifndef F_9
if ( V_36 -> V_18 ) F_13 ( V_36 -> V_18 ) ;
#endif
for ( V_10 = 0 ; V_10 < V_26 ; V_10 ++ )
{
if ( V_36 -> V_6 [ V_10 ] . V_27 != NULL )
F_14 ( V_36 -> V_6 [ V_10 ] . V_27 ) ;
if ( V_36 -> V_6 [ V_10 ] . V_29 != NULL )
F_15 ( V_36 -> V_6 [ V_10 ] . V_29 ) ;
#if 0
if (c->pkeys[i].publickey != NULL)
EVP_PKEY_free(c->pkeys[i].publickey);
#endif
}
F_19 ( V_36 ) ;
}
int F_20 ( T_1 * * V_39 )
{
if ( V_39 == NULL )
{
F_5 ( V_40 , V_41 ) ;
return ( 0 ) ;
}
if ( * V_39 == NULL )
{
if ( ( * V_39 = F_3 () ) == NULL )
{
F_5 ( V_40 , V_4 ) ;
return ( 0 ) ;
}
}
return ( 1 ) ;
}
T_3 * F_21 ( void )
{
T_3 * V_2 ;
V_2 = F_4 ( sizeof *V_2 ) ;
if ( V_2 == NULL )
{
F_5 ( V_42 , V_4 ) ;
return NULL ;
}
memset ( V_2 , 0 , sizeof *V_2 ) ;
V_2 -> V_43 = & ( V_2 -> V_44 [ V_7 ] ) ;
V_2 -> V_8 = 1 ;
return V_2 ;
}
void F_22 ( T_3 * V_45 )
{
int V_10 ;
if ( V_45 == NULL )
return;
V_10 = F_8 ( & V_45 -> V_8 , - 1 , V_46 ) ;
#ifdef F_17
F_17 ( L_4 , V_45 ) ;
#endif
if ( V_10 > 0 )
return;
#ifdef F_18
if ( V_10 < 0 )
{
fprintf ( V_38 , L_5 ) ;
abort () ;
}
#endif
if ( V_45 -> V_47 != NULL )
F_23 ( V_45 -> V_47 , F_14 ) ;
for ( V_10 = 0 ; V_10 < V_26 ; V_10 ++ )
{
if ( V_45 -> V_44 [ V_10 ] . V_27 != NULL )
F_14 ( V_45 -> V_44 [ V_10 ] . V_27 ) ;
#if 0
if (sc->peer_pkeys[i].privatekey != NULL)
EVP_PKEY_free(sc->peer_pkeys[i].privatekey);
#endif
}
#ifndef F_7
if ( V_45 -> V_48 != NULL )
F_12 ( V_45 -> V_48 ) ;
#endif
#ifndef F_9
if ( V_45 -> V_49 != NULL )
F_13 ( V_45 -> V_49 ) ;
#endif
F_19 ( V_45 ) ;
}
int F_24 ( T_3 * V_45 , int type )
{
V_45 -> V_50 = type ;
return ( 1 ) ;
}
int F_25 ( T_4 * V_51 , T_5 * V_52 )
{
return ( F_26 ( & ( V_51 -> V_53 ) , V_52 ) ) ;
}
int F_27 ( T_6 * V_54 , T_5 * V_52 )
{
return ( F_26 ( & ( V_54 -> V_53 ) , V_52 ) ) ;
}
static int F_28 ( const T_7 * const * V_55 , const T_7 * const * V_22 )
{
return ( F_29 ( * V_55 , * V_22 ) ) ;
}
