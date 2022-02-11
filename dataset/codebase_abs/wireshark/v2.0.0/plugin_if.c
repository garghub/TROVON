extern T_1 * F_1 ( void )
{
return V_1 ;
}
extern T_2 * F_2 ( int V_2 , const T_3 * V_3 ,
T_4 V_4 )
{
T_5 * V_5 = NULL ;
T_3 * V_6 = NULL ;
F_3 ( V_3 != NULL && strlen ( V_3 ) > 0 ) ;
F_3 ( F_4 ( V_2 ) != NULL ) ;
V_6 = F_5 ( F_6 ( V_2 ) , L_1 , NULL ) ;
F_3 ( F_7 ( V_7 , V_6 ) == NULL ) ;
V_5 = ( T_5 * ) F_8 ( sizeof( T_5 ) ) ;
V_5 -> type = V_8 ;
V_5 -> V_9 = V_2 ;
V_5 -> V_4 = V_4 ;
V_5 -> V_10 = 0 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_11 = F_9 ( V_3 ) ;
V_5 -> V_12 = F_9 ( V_3 ) ;
V_5 -> V_13 = 0 ;
V_5 -> V_14 = 0 ;
V_1 = F_10 ( V_1 , V_5 ) ;
V_7 = F_10 ( V_7 , V_6 ) ;
return V_5 ;
}
extern T_2 * F_11 ( T_2 * V_15 , const T_3 * V_16 )
{
F_3 ( V_15 != NULL && V_15 -> V_17 == NULL ) ;
F_3 ( V_16 != 0 ) ;
V_15 -> V_10 = F_9 ( V_16 ) ;
return V_15 ;
}
extern T_2 * F_12 ( T_2 * V_17 , const T_3 * V_3 )
{
T_5 * V_5 = NULL ;
F_3 ( V_3 != NULL && strlen ( V_3 ) > 0 ) ;
F_3 ( V_17 != NULL && V_17 -> type == V_8 ) ;
V_17 -> V_13 ++ ;
V_5 = ( T_5 * ) F_8 ( sizeof( T_5 ) ) ;
V_5 -> type = V_8 ;
V_5 -> V_17 = V_17 ;
V_5 -> V_9 = V_17 -> V_9 ;
V_5 -> V_4 = V_17 -> V_4 ;
V_5 -> V_6 = F_13 ( L_2 , V_17 -> V_6 , V_17 -> V_13 ) ;
V_5 -> V_11 = F_9 ( V_3 ) ;
V_5 -> V_12 = F_9 ( V_3 ) ;
V_17 -> V_18 = F_10 ( V_17 -> V_18 , V_5 ) ;
return V_5 ;
}
static void F_14 (
T_6 type , T_2 * V_17 , const T_3 * V_11 ,
const T_3 * V_12 , T_7 V_19 , T_8 V_20 )
{
T_5 * V_5 = NULL ;
F_3 ( V_17 != NULL && V_17 -> type == V_8 ) ;
F_3 ( V_11 != NULL && strlen ( V_11 ) > 0 ) ;
V_17 -> V_14 ++ ;
V_5 = ( T_5 * ) F_8 ( sizeof( T_5 ) ) ;
V_5 -> type = type ;
V_5 -> V_6 = F_13 ( L_3 , V_17 -> V_6 , V_17 -> V_14 ) ;
V_5 -> V_11 = F_9 ( V_11 ) ;
if ( V_12 != NULL && strlen ( V_12 ) > 0 )
V_5 -> V_12 = F_9 ( V_12 ) ;
V_5 -> V_19 = V_19 ;
V_5 -> V_20 = V_20 ;
V_17 -> V_18 = F_10 ( V_17 -> V_18 , V_5 ) ;
}
extern void F_15 ( T_2 * V_17 , const T_3 * V_11 ,
const T_3 * V_12 , T_7 V_19 , T_8 V_20 )
{
F_3 ( V_19 != NULL ) ;
F_14 ( V_21 , V_17 , V_11 , V_12 , V_19 , V_20 ) ;
}
extern void F_16 ( T_2 * V_17 , const T_3 * V_11 ,
const T_3 * V_12 , const T_3 * V_22 )
{
F_3 ( V_22 != NULL && strlen ( V_22 ) > 0 ) ;
F_14 ( V_23 , V_17 , V_11 , V_12 , NULL , ( T_8 ) F_9 ( V_22 ) ) ;
}
extern void F_17 ( T_2 * V_17 )
{
F_14 ( V_24 , V_17 , F_9 ( L_4 ) , NULL , NULL , NULL ) ;
}
static void
F_18 ( void )
{
if ( V_25 == 0 )
V_25 = F_19 ( V_26 , V_27 ) ;
}
static void F_20 ( T_9 V_28 , T_10 * V_29 )
{
T_11 V_30 ;
T_12 * V_31 = 0 ;
V_31 = ( T_12 * ) F_8 ( sizeof( T_12 ) ) ;
* V_31 = ( T_12 ) V_28 ;
F_18 () ;
if ( F_21 ( V_25 ) != 0 )
{
if ( F_22 ( V_25 , V_31 , NULL , ( T_8 * ) & V_30 ) )
{
if ( V_30 != NULL )
V_30 ( V_29 ) ;
}
}
}
extern void F_23 ( const char * V_32 , T_4 V_33 )
{
T_9 V_28 ;
T_10 * V_29 = NULL ;
V_28 = ( V_33 == TRUE ) ? V_34 : V_35 ;
V_29 = F_19 ( V_36 , V_37 ) ;
F_24 ( V_29 , F_9 ( L_5 ) , ( T_8 ) & V_28 ) ;
F_24 ( V_29 , F_9 ( L_6 ) , F_9 ( V_32 ) ) ;
F_24 ( V_29 , F_9 ( L_7 ) , ( T_8 ) & V_33 ) ;
F_20 ( V_28 , V_29 ) ;
}
extern void F_25 ( T_13 V_38 )
{
T_10 * V_29 = NULL ;
V_29 = F_19 ( V_36 , V_37 ) ;
F_24 ( V_29 , F_9 ( L_8 ) , F_26 ( V_38 ) ) ;
F_20 ( V_39 , V_29 ) ;
}
extern void F_27 ( const char * V_40 , const char * V_41 , const char * V_42 )
{
T_10 * V_29 = NULL ;
V_29 = F_19 ( V_36 , V_37 ) ;
F_24 ( V_29 , F_9 ( L_9 ) , F_9 ( V_40 ) ) ;
F_24 ( V_29 , F_9 ( L_10 ) , F_9 ( V_41 ) ) ;
F_24 ( V_29 , F_9 ( L_11 ) , F_9 ( V_42 ) ) ;
F_20 ( V_43 , V_29 ) ;
}
extern void F_28 ( T_9 V_28 , T_11 V_19 )
{
T_12 * V_31 = 0 ;
V_31 = ( T_12 * ) F_8 ( sizeof( T_12 ) ) ;
* V_31 = V_28 ;
F_18 () ;
if ( ! F_22 ( V_25 , V_31 , NULL , NULL ) )
F_24 ( V_25 , V_31 , V_19 ) ;
}
