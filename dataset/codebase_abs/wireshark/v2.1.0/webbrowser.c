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
#else
T_6 * error = NULL ;
T_2 * V_11 , * V_12 , * V_13 ;
T_2 * * V_14 ;
T_1 V_15 ;
F_12 ( V_1 != NULL , FALSE ) ;
if ( F_13 ( V_1 ) ) {
return TRUE ;
}
V_11 = F_14 ( V_16 . V_17 ) ;
if ( V_11 == NULL || ! strlen ( V_11 ) )
{
F_15 ( V_18 , V_19 ,
L_2
L_3
L_4 , V_1 ) ;
F_16 ( V_11 ) ;
return FALSE ;
}
V_12 = F_17 ( V_1 ) ;
if ( strstr ( V_11 , L_5 ) )
V_13 = F_18 ( V_11 , L_5 , V_12 ) ;
else
V_13 = F_19 ( V_11 , L_6 , V_12 , NULL ) ;
F_16 ( V_12 ) ;
if ( ! F_20 ( V_13 , NULL , & V_14 , & error ) )
{
F_15 ( V_18 , V_19 ,
L_7 ,
F_21 () , V_11 , F_22 () ,
error -> V_20 ,
L_8 ) ;
F_23 ( error ) ;
return FALSE ;
}
V_15 = F_24 ( NULL , V_14 , NULL ,
V_21 ,
NULL , NULL ,
NULL , & error ) ;
if ( ! V_15 )
{
F_15 ( V_18 , V_19 ,
L_9 ,
F_21 () , V_11 , F_22 () ,
error -> V_20 ,
L_8 ) ;
F_23 ( error ) ;
}
F_16 ( V_11 ) ;
F_16 ( V_13 ) ;
F_25 ( V_14 ) ;
return V_15 ;
#endif
}
T_1
F_26 ( const T_2 * V_22 )
{
#if F_4 ( V_2 )
V_3 V_23 ;
T_2 * V_24 ;
V_24 = F_19 ( V_22 ,
F_27 ( V_22 , L_10 ) ? L_11 : L_10 ,
NULL ) ;
V_23 = ( V_3 ) F_5 ( V_4 , F_6 ( L_12 ) , F_7 ( V_24 ) , NULL , NULL , V_5 ) ;
F_16 ( V_24 ) ;
return ( V_23 > 32 ) ;
#elif F_4 ( V_6 )
T_3 V_25 ;
T_4 V_26 ;
T_5 V_9 ;
V_25 = F_8 ( NULL , V_22 , V_27 ) ;
if ( V_25 == NULL )
return ( FALSE ) ;
V_26 = F_28 ( NULL , V_25 ,
V_28 , true ) ;
F_10 ( V_25 ) ;
if ( V_26 == NULL ) {
return ( FALSE ) ;
}
V_9 = F_11 ( V_26 , NULL ) ;
F_10 ( V_26 ) ;
return ( V_9 == 0 ) ;
#else
T_6 * error = NULL ;
T_2 * V_11 , * V_12 , * V_13 ;
T_2 * * V_14 ;
T_1 V_15 ;
F_12 ( V_22 != NULL , FALSE ) ;
if ( F_13 ( V_22 ) ) {
return TRUE ;
}
V_11 = F_14 ( V_16 . V_17 ) ;
if ( V_11 == NULL || ! strlen ( V_11 ) )
{
F_15 ( V_18 , V_19 ,
L_2
L_3
L_4 , V_22 ) ;
F_16 ( V_11 ) ;
return FALSE ;
}
V_12 = F_29 ( V_22 , NULL , & error ) ;
if ( V_12 == NULL )
{
F_15 ( V_18 , V_19 ,
L_13 ,
F_21 () , V_22 , F_22 () ,
error -> V_20 ) ;
F_23 ( error ) ;
return FALSE ;
}
if ( strstr ( V_11 , L_5 ) )
V_13 = F_18 ( V_11 , L_5 , V_12 ) ;
else
V_13 = F_19 ( V_11 , L_6 , V_12 , NULL ) ;
F_16 ( V_12 ) ;
if ( ! F_20 ( V_13 , NULL , & V_14 , & error ) )
{
F_15 ( V_18 , V_19 ,
L_7 ,
F_21 () , V_11 , F_22 () ,
error -> V_20 ,
L_8 ) ;
F_23 ( error ) ;
return FALSE ;
}
V_15 = F_24 ( NULL , V_14 , NULL ,
V_21 ,
NULL , NULL ,
NULL , & error ) ;
if ( ! V_15 )
{
F_15 ( V_18 , V_19 ,
L_9 ,
F_21 () , V_11 , F_22 () ,
error -> V_20 ,
L_8 ) ;
F_23 ( error ) ;
}
F_16 ( V_11 ) ;
F_16 ( V_13 ) ;
F_25 ( V_14 ) ;
return V_15 ;
#endif
}
static T_2 *
F_18 ( const T_2 * string ,
const T_2 * V_29 ,
const T_2 * V_30 )
{
T_2 * V_23 ;
T_2 * * V_31 ;
F_12 ( string != NULL , NULL ) ;
F_12 ( V_29 != NULL , NULL ) ;
F_12 ( V_30 != NULL , NULL ) ;
V_31 = F_30 ( string , V_29 , 0 ) ;
V_23 = F_31 ( V_30 , V_31 ) ;
F_25 ( V_31 ) ;
return V_23 ;
}
T_1 F_13 ( const T_2 * V_1 ) {
T_6 * error = NULL ;
T_2 * V_14 [ 3 ] ;
T_1 V_15 ;
V_14 [ 0 ] = L_14 ;
F_32 (cast-qual)
V_14 [ 1 ] = ( T_2 * ) V_1 ;
F_33 (cast-qual)
V_14 [ 2 ] = NULL ;
V_15 = F_24 ( NULL , V_14 , NULL ,
V_21 ,
NULL , NULL ,
NULL , & error ) ;
if ( V_15 )
return TRUE ;
F_34 ( L_15 , error -> V_20 ) ;
F_23 ( error ) ;
return FALSE ;
}
void
F_35 ( const T_2 * V_32 )
{
T_2 * V_33 ;
V_33 = F_36 ( V_32 ) ;
F_3 ( V_33 ) ;
F_16 ( V_33 ) ;
}
