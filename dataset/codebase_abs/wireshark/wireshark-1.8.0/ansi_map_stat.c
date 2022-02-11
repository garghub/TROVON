static
T_1 * F_1 ( void )
{
T_2 * V_1 ;
T_1 * V_2 ;
T_3 * V_3 ;
T_4 * V_4 ;
T_5 * V_5 ;
T_6 * V_6 ;
T_7 * V_7 ;
V_1 = F_2 ( V_8 ,
V_9 ,
V_10 ,
V_9 ,
V_9 ,
V_11 ) ;
V_2 = F_3 ( F_4 ( V_1 ) ) ;
V_6 = F_5 ( V_2 ) ;
V_5 = F_6 ( V_1 ) ;
F_7 ( V_6 , TRUE ) ;
F_8 ( V_5 , V_12 , V_13 ) ;
F_9 ( V_6 , FALSE ) ;
F_10 ( F_11 ( V_1 ) ) ;
V_4 = F_12 () ;
V_3 = F_13 ( L_1 , V_4 ,
L_2 , V_12 ,
NULL ) ;
F_14 ( V_3 , V_4 , V_14 ,
F_15 ( V_12 ) , NULL ) ;
F_16 ( V_3 , V_12 ) ;
F_17 ( V_3 , TRUE ) ;
F_18 ( V_3 , V_15 ) ;
F_19 ( V_3 , 60 ) ;
F_20 ( V_6 , V_3 ) ;
V_4 = F_12 () ;
V_3 = F_13 ( L_3 , V_4 ,
L_2 , V_16 ,
NULL ) ;
F_16 ( V_3 , V_16 ) ;
F_17 ( V_3 , TRUE ) ;
F_18 ( V_3 , V_15 ) ;
F_19 ( V_3 , 290 ) ;
F_20 ( V_6 , V_3 ) ;
V_4 = F_12 () ;
V_3 = F_13 ( L_4 , V_4 ,
L_2 , V_17 ,
NULL ) ;
F_16 ( V_3 , V_17 ) ;
F_17 ( V_3 , TRUE ) ;
F_18 ( V_3 , V_15 ) ;
F_19 ( V_3 , 50 ) ;
F_20 ( V_6 , V_3 ) ;
V_4 = F_12 () ;
V_3 = F_13 ( L_5 , V_4 ,
L_2 , V_18 ,
NULL ) ;
F_16 ( V_3 , V_18 ) ;
F_17 ( V_3 , TRUE ) ;
F_18 ( V_3 , V_15 ) ;
F_19 ( V_3 , 100 ) ;
F_20 ( V_6 , V_3 ) ;
V_4 = F_12 () ;
V_3 = F_13 ( L_6 , V_4 ,
L_2 , V_19 ,
NULL ) ;
F_14 ( V_3 , V_4 , V_20 ,
F_15 ( V_19 ) , NULL ) ;
F_16 ( V_3 , V_19 ) ;
F_17 ( V_3 , TRUE ) ;
F_18 ( V_3 , V_15 ) ;
F_19 ( V_3 , 50 ) ;
F_20 ( V_6 , V_3 ) ;
F_21 ( F_5 ( V_6 ) , TRUE ) ;
F_9 ( F_5 ( V_6 ) , TRUE ) ;
V_7 = F_22 ( F_5 ( V_2 ) ) ;
F_23 ( V_7 , V_21 ) ;
return V_2 ;
}
static void
F_24 (
void * V_22 )
{
T_8 * V_23 = V_22 ;
memset ( V_23 , 0 , sizeof( T_8 ) ) ;
}
static T_9
F_25 (
void * V_22 ,
T_10 * T_11 V_24 ,
T_12 * T_13 V_24 ,
const void * V_25 )
{
T_8 * V_23 = V_22 ;
const T_14 * V_26 = V_25 ;
#if 0
if (data_p->message_type >= ANSI_MAP_MAX_NUM_MESSAGE_TYPES)
{
return(FALSE);
}
#endif
V_23 -> V_27 [ V_26 -> V_27 ] ++ ;
V_23 -> V_28 [ V_26 -> V_27 ] += V_26 -> V_28 ;
return ( TRUE ) ;
}
static void
F_26 (
void * V_22 )
{
T_8 * V_23 = V_22 ;
int V_29 ;
float V_30 ;
T_2 * V_1 ;
T_15 V_31 ;
if ( V_32 . V_33 && V_22 )
{
V_29 = 0 ;
V_1 = F_27 ( F_28 ( F_5 ( V_32 . V_34 ) ) ) ;
while ( V_35 [ V_29 ] . V_36 )
{
V_30 = 0.0f ;
if ( V_23 -> V_27 [ V_35 [ V_29 ] . V_37 ] != 0 ) {
V_30 = ( float ) V_23 -> V_28 [ V_35 [ V_29 ] . V_37 ] / ( float ) V_23 -> V_27 [ V_35 [ V_29 ] . V_37 ] ;
}
F_29 ( V_1 , & V_31 , V_38 ,
V_12 , V_35 [ V_29 ] . V_37 ,
V_16 , V_35 [ V_29 ] . V_36 ,
V_17 , ( V_39 ) V_23 -> V_27 [ V_35 [ V_29 ] . V_37 ] ,
V_18 , ( V_39 ) V_23 -> V_28 [ V_35 [ V_29 ] . V_37 ] ,
V_19 , V_30 ,
- 1 ) ;
V_29 ++ ;
}
}
}
static void
F_30 (
T_16 * V_33 V_24 ,
T_17 V_40 )
{
memset ( ( void * ) V_40 , 0 , sizeof( V_41 ) ) ;
}
static void
F_31 (
V_41 * V_42 ,
const char * V_43 )
{
T_1 * V_44 ;
T_1 * V_45 ;
T_1 * V_46 ;
V_42 -> V_33 = F_32 ( V_43 ) ;
F_33 ( F_34 ( V_42 -> V_33 ) , TRUE ) ;
F_35 ( F_34 ( V_42 -> V_33 ) , 500 , 450 ) ;
V_44 = F_36 ( V_47 , 3 , FALSE ) ;
F_37 ( F_38 ( V_42 -> V_33 ) , V_44 ) ;
F_39 ( F_38 ( V_44 ) , 12 ) ;
V_42 -> V_48 = F_40 ( NULL , NULL ) ;
F_41 ( F_42 ( V_44 ) , V_42 -> V_48 , TRUE , TRUE , 0 ) ;
V_42 -> V_34 = F_1 () ;
F_37 ( F_38 ( V_42 -> V_48 ) , V_42 -> V_34 ) ;
V_46 = F_43 ( V_49 , NULL ) ;
F_41 ( F_42 ( V_44 ) , V_46 , FALSE , FALSE , 0 ) ;
V_45 = F_44 ( F_11 ( V_46 ) , V_49 ) ;
F_45 ( V_42 -> V_33 , V_45 , V_50 ) ;
F_46 ( V_42 -> V_33 , L_7 , F_47 ( V_51 ) , NULL ) ;
F_46 ( V_42 -> V_33 , L_8 , F_47 ( F_30 ) , V_42 ) ;
F_48 ( V_42 -> V_33 ) ;
F_49 ( V_42 -> V_33 ) ;
}
void
F_50 ( T_18 * T_19 V_24 , T_17 V_40 V_24 )
{
if ( V_32 . V_33 ) {
F_51 ( F_52 ( V_32 . V_33 ) ) ;
return;
}
F_31 ( & V_32 , L_9 ) ;
F_26 ( & V_52 ) ;
}
static void
F_53 (
const char * T_20 V_24 ,
void * T_21 V_24 )
{
F_50 ( NULL , NULL ) ;
}
void
F_54 ( void )
{
T_22 * V_53 ;
memset ( ( void * ) & V_52 , 0 , sizeof( T_8 ) ) ;
V_53 =
F_55 ( L_10 , & V_52 , NULL , 0 ,
F_24 ,
F_25 ,
F_26 ) ;
if ( V_53 != NULL )
{
F_56 ( V_54 , V_55 , L_11 , V_53 -> V_56 ) ;
F_57 ( V_53 , TRUE ) ;
exit ( 1 ) ;
}
F_58 ( L_10 , F_53 , NULL ) ;
}
