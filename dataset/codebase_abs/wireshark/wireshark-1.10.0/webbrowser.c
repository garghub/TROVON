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
const T_2 * V_12 [ 3 ] ;
T_1 V_13 ;
F_12 ( V_1 != NULL , FALSE ) ;
V_12 [ 0 ] = L_2 ;
V_12 [ 1 ] = V_1 ;
V_12 [ 2 ] = NULL ;
V_13 = F_13 ( NULL , ( T_2 * * ) V_12 , NULL ,
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
T_1
F_25 ( const T_2 * V_23 )
{
#if F_4 ( V_2 )
V_3 V_24 ;
T_2 * V_25 ;
V_25 = F_22 ( V_23 ,
F_26 ( V_23 , L_10 ) ? L_11 : L_10 ,
NULL ) ;
V_24 = ( V_3 ) F_5 ( V_4 , F_6 ( L_12 ) , F_7 ( V_25 ) , NULL , NULL , V_5 ) ;
F_19 ( V_25 ) ;
return ( V_24 > 32 ) ;
#elif F_4 ( V_6 )
T_3 V_26 ;
T_4 V_27 ;
T_5 V_9 ;
V_26 = F_8 ( NULL , V_23 , V_28 ) ;
if ( V_26 == NULL )
return ( FALSE ) ;
V_27 = F_27 ( NULL , V_26 ,
V_29 , true ) ;
F_10 ( V_26 ) ;
if ( V_27 == NULL ) {
return ( FALSE ) ;
}
V_9 = F_11 ( V_27 , NULL ) ;
F_10 ( V_27 ) ;
return ( V_9 == 0 ) ;
#elif F_4 ( V_11 )
T_6 * error = NULL ;
const T_2 * V_12 [ 3 ] ;
T_1 V_13 ;
F_12 ( V_23 != NULL , FALSE ) ;
V_12 [ 0 ] = L_2 ;
V_12 [ 1 ] = V_23 ;
V_12 [ 2 ] = NULL ;
V_13 = F_13 ( NULL , ( T_2 * * ) V_12 , NULL ,
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
T_6 * error ;
T_2 * V_18 ;
T_2 * V_19 ;
T_2 * V_20 ;
T_2 * * V_12 ;
T_1 V_13 ;
F_12 ( V_23 != NULL , FALSE ) ;
V_18 = F_18 ( V_21 . V_22 ) ;
if ( V_18 == NULL || ! strlen ( V_18 ) )
{
F_14 ( V_15 , V_16 ,
L_4
L_5 ) ;
F_19 ( V_18 ) ;
return FALSE ;
}
V_19 = F_28 ( V_23 , NULL , & error ) ;
if ( V_19 == NULL )
{
F_14 ( V_15 , V_16 ,
L_13 ,
F_15 () , V_23 , F_16 () ,
error -> V_17 ) ;
F_17 ( error ) ;
return FALSE ;
}
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
const T_2 * V_30 ,
const T_2 * V_31 )
{
T_2 * V_24 ;
T_2 * * V_32 ;
F_12 ( string != NULL , NULL ) ;
F_12 ( V_30 != NULL , NULL ) ;
F_12 ( V_31 != NULL , NULL ) ;
V_32 = F_29 ( string , V_30 , 0 ) ;
V_24 = F_30 ( V_31 , V_32 ) ;
F_24 ( V_32 ) ;
return V_24 ;
}
void
F_31 ( const T_2 * V_33 )
{
T_2 * V_34 ;
V_34 = F_32 ( V_33 ) ;
F_3 ( V_34 ) ;
F_19 ( V_34 ) ;
}
