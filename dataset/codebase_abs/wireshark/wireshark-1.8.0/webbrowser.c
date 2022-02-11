T_1
F_1 ( void )
{
#ifdef F_2
return TRUE ;
#else
return FALSE ;
#endif
}
T_1
F_3 ( const T_2 * V_1 )
{
#if F_4 ( V_2 )
return ( ( V_3 ) F_5 ( V_4 , F_6 ( L_1 ) , F_7 ( V_1 ) , NULL , NULL , V_5 ) > 32 ) ;
#elif F_4 ( V_6 )
T_3 V_7 ;
T_4 V_8 ;
T_5 V_9 ;
V_7 = F_8 ( NULL , V_1 , V_10 ) ;
if ( V_7 == NULL )
return ( FALSE ) ;
V_8 = F_9 ( NULL , V_7 , NULL ) ;
F_10 ( V_7 ) ;
if ( V_8 == NULL ) {
return ( FALSE ) ;
}
V_9 = F_11 ( V_8 , NULL ) ;
F_10 ( V_8 ) ;
return ( V_9 == 0 ) ;
#elif F_4 ( V_11 )
T_6 * error = NULL ;
T_2 * V_12 [ 3 ] ;
T_1 V_13 ;
F_12 ( V_1 != NULL , FALSE ) ;
V_12 [ 0 ] = L_2 ;
V_12 [ 1 ] = ( char * ) V_1 ;
V_12 [ 2 ] = NULL ;
V_13 = F_13 ( NULL , V_12 , NULL ,
V_14 ,
NULL , NULL ,
NULL , & error ) ;
if ( ! V_13 )
{
F_14 ( V_15 , V_16 ,
L_3 ,
F_15 () , F_16 () ,
error -> V_17 ) ;
F_17 ( error ) ;
}
return V_13 ;
#elif F_4 ( F_2 )
T_6 * error = NULL ;
T_2 * V_18 ;
T_2 * V_19 ;
T_2 * V_20 ;
T_2 * * V_12 ;
T_1 V_13 ;
F_12 ( V_1 != NULL , FALSE ) ;
V_18 = F_18 ( V_21 . V_22 ) ;
if ( V_18 == NULL || ! strlen ( V_18 ) )
{
F_14 ( V_15 , V_16 ,
L_4
L_5 ) ;
F_19 ( V_18 ) ;
return FALSE ;
}
V_19 = F_20 ( V_1 ) ;
if ( strstr ( V_18 , L_6 ) )
V_20 = F_21 ( V_18 , L_6 , V_19 ) ;
else
V_20 = F_22 ( V_18 , L_7 , V_19 , NULL ) ;
F_19 ( V_19 ) ;
if ( ! F_23 ( V_20 , NULL , & V_12 , & error ) )
{
F_14 ( V_15 , V_16 ,
L_8 ,
F_15 () , V_18 , F_16 () ,
error -> V_17 ,
L_5 ) ;
F_17 ( error ) ;
return FALSE ;
}
V_13 = F_13 ( NULL , V_12 , NULL ,
V_14 ,
NULL , NULL ,
NULL , & error ) ;
if ( ! V_13 )
{
F_14 ( V_15 , V_16 ,
L_9 ,
F_15 () , V_18 , F_16 () ,
error -> V_17 ,
L_5 ) ;
F_17 ( error ) ;
}
F_19 ( V_18 ) ;
F_19 ( V_20 ) ;
F_24 ( V_12 ) ;
return V_13 ;
#endif
}
T_2 *
F_25 ( const T_2 * V_23 )
{
int V_24 = 0 ;
T_2 * V_25 ;
T_7 * V_26 ;
V_26 = F_26 ( 200 ) ;
for( V_24 = 0 ; V_23 [ V_24 ] ; V_24 ++ ) {
switch( V_23 [ V_24 ] ) {
case ( ' ' ) :
F_27 ( V_26 , L_10 ) ;
break;
case ( '%' ) :
F_27 ( V_26 , L_11 ) ;
break;
case ( '\\' ) :
F_28 ( V_26 , '/' ) ;
break;
default:
F_28 ( V_26 , V_23 [ V_24 ] ) ;
}
}
#ifdef V_2
F_29 ( V_26 , L_12 ) ;
#else
F_29 ( V_26 , L_13 ) ;
#endif
V_25 = V_26 -> V_27 ;
F_30 ( V_26 , FALSE ) ;
return V_25 ;
}
T_1
F_31 ( const T_2 * V_28 )
{
#if F_4 ( V_2 )
V_3 V_29 ;
T_2 * V_30 ;
V_30 = F_22 ( V_28 ,
F_32 ( V_28 , L_14 ) ? L_15 : L_14 ,
NULL ) ;
V_29 = ( V_3 ) F_5 ( V_4 , F_6 ( L_16 ) , F_7 ( V_30 ) , NULL , NULL , V_5 ) ;
F_19 ( V_30 ) ;
return ( V_29 > 32 ) ;
#elif F_4 ( V_6 )
T_3 V_31 ;
T_4 V_32 ;
T_5 V_9 ;
V_31 = F_8 ( NULL , V_28 , V_33 ) ;
if ( V_31 == NULL )
return ( FALSE ) ;
V_32 = F_33 ( NULL , V_31 ,
V_34 , true ) ;
F_10 ( V_31 ) ;
if ( V_32 == NULL ) {
return ( FALSE ) ;
}
V_9 = F_11 ( V_32 , NULL ) ;
F_10 ( V_32 ) ;
return ( V_9 == 0 ) ;
#elif F_4 ( V_11 )
T_6 * error = NULL ;
T_2 * V_12 [ 3 ] ;
T_1 V_13 ;
F_12 ( V_28 != NULL , FALSE ) ;
V_12 [ 0 ] = L_2 ;
V_12 [ 1 ] = ( char * ) V_28 ;
V_12 [ 2 ] = NULL ;
V_13 = F_13 ( NULL , V_12 , NULL ,
V_14 ,
NULL , NULL ,
NULL , & error ) ;
if ( ! V_13 )
{
F_14 ( V_15 , V_16 ,
L_3 ,
F_15 () , F_16 () ,
error -> V_17 ) ;
F_17 ( error ) ;
}
return V_13 ;
#elif F_4 ( F_2 )
T_6 * error = NULL ;
T_2 * V_18 ;
T_2 * V_19 ;
T_2 * V_20 ;
T_2 * * V_12 ;
T_1 V_13 ;
F_12 ( V_28 != NULL , FALSE ) ;
V_18 = F_18 ( V_21 . V_22 ) ;
if ( V_18 == NULL || ! strlen ( V_18 ) )
{
F_14 ( V_15 , V_16 ,
L_4
L_5 ) ;
F_19 ( V_18 ) ;
return FALSE ;
}
V_19 = F_25 ( V_28 ) ;
if ( strstr ( V_18 , L_6 ) )
V_20 = F_21 ( V_18 , L_6 , V_19 ) ;
else
V_20 = F_22 ( V_18 , L_7 , V_19 , NULL ) ;
F_19 ( V_19 ) ;
if ( ! F_23 ( V_20 , NULL , & V_12 , & error ) )
{
F_14 ( V_15 , V_16 ,
L_8 ,
F_15 () , V_18 , F_16 () ,
error -> V_17 ,
L_5 ) ;
F_17 ( error ) ;
return FALSE ;
}
V_13 = F_13 ( NULL , V_12 , NULL ,
V_14 ,
NULL , NULL ,
NULL , & error ) ;
if ( ! V_13 )
{
F_14 ( V_15 , V_16 ,
L_9 ,
F_15 () , V_18 , F_16 () ,
error -> V_17 ,
L_5 ) ;
F_17 ( error ) ;
}
F_19 ( V_18 ) ;
F_19 ( V_20 ) ;
F_24 ( V_12 ) ;
return V_13 ;
#endif
}
static T_2 *
F_21 ( const T_2 * string ,
const T_2 * V_35 ,
const T_2 * V_36 )
{
T_2 * V_29 ;
T_2 * * V_37 ;
F_12 ( string != NULL , NULL ) ;
F_12 ( V_35 != NULL , NULL ) ;
F_12 ( V_36 != NULL , NULL ) ;
V_37 = F_34 ( string , V_35 , 0 ) ;
V_29 = F_35 ( V_36 , V_37 ) ;
F_24 ( V_37 ) ;
return V_29 ;
}
void
F_36 ( const T_2 * V_23 )
{
T_2 * V_38 ;
T_2 * V_39 ;
#ifdef V_2
if( ( strlen ( V_23 ) > 2 ) && ( V_23 [ 1 ] == ':' ) )
V_38 = F_18 ( V_23 ) ;
#else
if( ( strlen ( V_23 ) > 1 ) && ( V_23 [ 0 ] == '/' ) )
V_38 = F_18 ( V_23 ) ;
#endif
else
V_38 = F_37 ( L_17 , F_38 () , V_23 ) ;
V_39 = F_25 ( V_38 ) ;
F_3 ( V_39 ) ;
F_19 ( V_38 ) ;
F_19 ( V_39 ) ;
}
