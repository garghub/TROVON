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
V_2 = ( T_1 * ) Malloc ( sizeof( T_1 ) ) ;
if ( V_2 == NULL )
{
F_4 ( V_3 , V_4 ) ;
return ( NULL ) ;
}
memset ( V_2 , 0 , sizeof( T_1 ) ) ;
V_2 -> V_5 = & ( V_2 -> V_6 [ V_7 ] ) ;
V_2 -> V_8 = 1 ;
return ( V_2 ) ;
}
T_1 * F_5 ( T_1 * V_9 )
{
T_1 * V_2 ;
int V_10 ;
V_2 = ( T_1 * ) Malloc ( sizeof( T_1 ) ) ;
if ( V_2 == NULL )
{
F_4 ( V_11 , V_4 ) ;
return ( NULL ) ;
}
memset ( V_2 , 0 , sizeof( T_1 ) ) ;
V_2 -> V_5 = & V_2 -> V_6 [ V_9 -> V_5 - & V_9 -> V_6 [ 0 ] ] ;
V_2 -> V_12 = V_9 -> V_12 ;
V_2 -> V_13 = V_9 -> V_13 ;
V_2 -> V_14 = V_9 -> V_14 ;
#ifndef F_6
if ( V_9 -> V_15 != NULL )
{
V_2 -> V_15 = V_9 -> V_15 ;
F_7 ( & V_2 -> V_15 -> V_8 , 1 , V_16 ) ;
}
V_2 -> V_17 = V_9 -> V_17 ;
#endif
#ifndef F_8
if ( V_9 -> V_18 != NULL )
{
V_2 -> V_18 = F_9 ( V_9 -> V_18 ) ;
if ( V_2 -> V_18 == NULL )
{
F_4 ( V_3 , V_19 ) ;
goto V_20;
}
}
V_2 -> V_21 = V_9 -> V_21 ;
#endif
for ( V_10 = 0 ; V_10 < V_22 ; V_10 ++ )
{
if ( V_9 -> V_6 [ V_10 ] . V_23 != NULL )
{
V_2 -> V_6 [ V_10 ] . V_23 = V_9 -> V_6 [ V_10 ] . V_23 ;
F_7 ( & V_2 -> V_6 [ V_10 ] . V_23 -> V_8 , 1 ,
V_24 ) ;
}
if ( V_9 -> V_6 [ V_10 ] . V_25 != NULL )
{
V_2 -> V_6 [ V_10 ] . V_25 = V_9 -> V_6 [ V_10 ] . V_25 ;
F_7 ( & V_2 -> V_6 [ V_10 ] . V_25 -> V_8 , 1 ,
V_26 ) ;
switch( V_10 )
{
case V_7 :
case V_27 :
break;
case V_28 :
break;
case V_29 :
case V_30 :
break;
default:
F_4 ( V_11 , V_31 ) ;
}
}
}
V_2 -> V_8 = 1 ;
return ( V_2 ) ;
V_20:
#ifndef F_6
if ( V_2 -> V_15 != NULL )
F_10 ( V_2 -> V_15 ) ;
#endif
#ifndef F_8
if ( V_2 -> V_18 != NULL )
F_11 ( V_2 -> V_18 ) ;
#endif
for ( V_10 = 0 ; V_10 < V_22 ; V_10 ++ )
{
if ( V_2 -> V_6 [ V_10 ] . V_23 != NULL )
F_12 ( V_2 -> V_6 [ V_10 ] . V_23 ) ;
if ( V_2 -> V_6 [ V_10 ] . V_25 != NULL )
F_13 ( V_2 -> V_6 [ V_10 ] . V_25 ) ;
}
return NULL ;
}
void F_14 ( T_1 * V_32 )
{
int V_10 ;
if( V_32 == NULL )
return;
V_10 = F_7 ( & V_32 -> V_8 , - 1 , V_33 ) ;
#ifdef F_15
F_15 ( L_2 , V_32 ) ;
#endif
if ( V_10 > 0 ) return;
#ifdef F_16
if ( V_10 < 0 )
{
fprintf ( V_34 , L_3 ) ;
abort () ;
}
#endif
#ifndef F_6
if ( V_32 -> V_15 ) F_10 ( V_32 -> V_15 ) ;
#endif
#ifndef F_8
if ( V_32 -> V_18 ) F_11 ( V_32 -> V_18 ) ;
#endif
for ( V_10 = 0 ; V_10 < V_22 ; V_10 ++ )
{
if ( V_32 -> V_6 [ V_10 ] . V_23 != NULL )
F_12 ( V_32 -> V_6 [ V_10 ] . V_23 ) ;
if ( V_32 -> V_6 [ V_10 ] . V_25 != NULL )
F_13 ( V_32 -> V_6 [ V_10 ] . V_25 ) ;
#if 0
if (c->pkeys[i].publickey != NULL)
EVP_PKEY_free(c->pkeys[i].publickey);
#endif
}
Free ( V_32 ) ;
}
int F_17 ( T_1 * * V_35 )
{
if ( V_35 == NULL )
{
F_4 ( V_36 , V_37 ) ;
return ( 0 ) ;
}
if ( * V_35 == NULL )
{
if ( ( * V_35 = F_3 () ) == NULL )
{
F_4 ( V_36 , V_4 ) ;
return ( 0 ) ;
}
}
return ( 1 ) ;
}
T_2 * F_18 ( void )
{
T_2 * V_2 ;
V_2 = Malloc ( sizeof *V_2 ) ;
if ( V_2 == NULL )
{
F_4 ( V_38 , V_4 ) ;
return NULL ;
}
memset ( V_2 , 0 , sizeof *V_2 ) ;
V_2 -> V_39 = & ( V_2 -> V_40 [ V_7 ] ) ;
V_2 -> V_8 = 1 ;
return V_2 ;
}
void F_19 ( T_2 * V_41 )
{
int V_10 ;
if ( V_41 == NULL )
return;
V_10 = F_7 ( & V_41 -> V_8 , - 1 , V_42 ) ;
#ifdef F_15
F_15 ( L_4 , V_41 ) ;
#endif
if ( V_10 > 0 )
return;
#ifdef F_16
if ( V_10 < 0 )
{
fprintf ( V_34 , L_5 ) ;
abort () ;
}
#endif
if ( V_41 -> V_43 != NULL )
F_20 ( V_41 -> V_43 , F_12 ) ;
for ( V_10 = 0 ; V_10 < V_22 ; V_10 ++ )
{
if ( V_41 -> V_40 [ V_10 ] . V_23 != NULL )
F_12 ( V_41 -> V_40 [ V_10 ] . V_23 ) ;
#if 0
if (sc->peer_pkeys[i].privatekey != NULL)
EVP_PKEY_free(sc->peer_pkeys[i].privatekey);
#endif
}
#ifndef F_6
if ( V_41 -> V_44 != NULL )
F_10 ( V_41 -> V_44 ) ;
#endif
#ifndef F_8
if ( V_41 -> V_45 != NULL )
F_11 ( V_41 -> V_45 ) ;
#endif
Free ( V_41 ) ;
}
int F_21 ( T_2 * V_41 , int type )
{
V_41 -> V_46 = type ;
return ( 1 ) ;
}
T_3 * F_22 ( T_3 * V_47 )
{
int V_10 ;
T_3 * V_2 ;
T_4 * V_48 ;
V_2 = F_23 () ;
for ( V_10 = 0 ; V_10 < F_24 ( V_47 ) ; V_10 ++ )
{
V_48 = F_25 ( ( T_4 * ) F_26 ( V_47 , V_10 ) ) ;
if ( ( V_48 == NULL ) || ! F_27 ( V_2 , ( char * ) V_48 ) )
{
F_28 ( V_2 , V_49 ) ;
return ( NULL ) ;
}
}
return ( V_2 ) ;
}
int F_29 ( T_5 * V_50 , T_6 * V_51 )
{
return ( F_30 ( & ( V_50 -> V_52 ) , V_51 ) ) ;
}
int F_31 ( T_7 * V_53 , T_6 * V_51 )
{
return ( F_30 ( & ( V_53 -> V_52 ) , V_51 ) ) ;
}
static int F_32 ( T_4 * * V_54 , T_4 * * V_55 )
{
return ( F_33 ( * V_54 , * V_55 ) ) ;
}
