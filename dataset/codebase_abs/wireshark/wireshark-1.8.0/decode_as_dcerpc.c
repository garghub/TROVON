static void
F_1 ( T_1 V_1 , T_1 T_2 V_2 )
{
F_2 ( ( V_3 * ) V_1 ) ;
}
static void
F_3 ( T_1 V_1 V_2 ) {
F_4 ( V_4 , F_1 , NULL ) ;
}
void
F_5 ( void ) {
T_3 * V_5 ;
V_5 = F_6 ( & V_6 ) ;
V_5 -> V_7 = F_3 ;
F_7 ( & V_6 , V_5 ) ;
}
static V_3 *
F_8 ( V_3 * V_8 )
{
V_3 * V_9 ;
V_9 = F_9 ( sizeof( V_3 ) ) ;
* V_9 = * V_8 ;
F_10 ( & V_9 -> V_10 , & V_8 -> V_10 ) ;
F_10 ( & V_9 -> V_11 , & V_8 -> V_11 ) ;
V_9 -> V_12 = F_11 ( V_8 -> V_12 -> V_13 ) ;
return V_9 ;
}
void
F_12 ( void * V_8 )
{
V_3 * V_14 = V_8 ;
F_13 ( ( void * ) V_14 -> V_10 . V_1 ) ;
F_13 ( ( void * ) V_14 -> V_11 . V_1 ) ;
if( V_14 -> V_12 )
F_14 ( V_14 -> V_12 , TRUE ) ;
F_13 ( V_14 ) ;
}
static T_4
F_15 ( T_5 V_15 , T_5 V_16 )
{
const V_3 * V_17 = V_15 ;
const V_3 * V_18 = V_16 ;
if(
F_16 ( & V_17 -> V_10 , & V_18 -> V_10 ) &&
F_16 ( & V_17 -> V_11 , & V_18 -> V_11 ) &&
V_17 -> V_19 == V_18 -> V_19 &&
V_17 -> V_20 == V_18 -> V_20 &&
V_17 -> V_21 == V_18 -> V_21 &&
V_17 -> V_22 == V_18 -> V_22 &&
V_17 -> V_23 == V_18 -> V_23 )
{
return 0 ;
}
return 1 ;
}
static void
F_17 ( T_1 V_1 , T_1 T_2 )
{
T_6 V_24 [ 20 ] ;
V_3 * V_14 = V_1 ;
F_18 ( V_24 , sizeof( V_24 ) , L_1 , V_14 -> V_22 ) ;
F_19 (
T_2 ,
L_2 ,
V_24 ,
L_3 ,
V_14 -> V_12 -> V_13 ) ;
}
void
F_20 ( T_1 T_2 )
{
F_4 ( V_4 , F_17 , T_2 ) ;
}
void
F_21 ( void )
{
V_3 * V_14 ;
while( V_4 ) {
V_14 = V_4 -> V_1 ;
F_12 ( V_14 ) ;
V_4 = F_22 (
V_4 ,
V_4 -> V_1 ) ;
}
}
static void
F_23 (
const T_6 * T_7 V_2 ,
V_3 * V_14 )
{
T_8 * V_25 ;
V_3 * V_26 ;
V_25 = F_24 ( V_4 ,
V_14 ,
F_15 ) ;
if( V_25 == NULL )
return;
V_26 = V_25 -> V_1 ;
V_4 = F_22 ( V_4 , V_25 -> V_1 ) ;
F_13 ( ( void * ) V_26 -> V_10 . V_1 ) ;
F_13 ( ( void * ) V_26 -> V_11 . V_1 ) ;
F_14 ( V_26 -> V_12 , TRUE ) ;
F_13 ( V_26 ) ;
}
static void
F_25 (
const T_6 * T_7 ,
V_3 * V_14 )
{
V_3 * V_9 ;
F_23 ( T_7 , V_14 ) ;
V_9 = F_8 ( V_14 ) ;
V_4 = F_26 ( V_4 , V_9 ) ;
}
static void
F_27 ( const T_6 * T_7 , V_3 * V_14 , T_9 * V_27 )
{
T_10 * V_28 ;
T_6 * V_29 ;
T_11 * V_30 ;
T_12 * V_31 ;
T_13 V_32 ;
V_30 = F_28 ( F_29 ( V_27 ) ) ;
if ( F_30 ( V_30 , & V_31 , & V_32 ) == FALSE )
{
V_29 = NULL ;
V_28 = NULL ;
} else {
F_31 ( V_31 , & V_32 , V_33 , & V_29 ,
V_34 + 1 , & V_28 , - 1 ) ;
}
if ( V_28 == NULL || ( V_29 != NULL && strcmp ( V_29 , L_4 ) == 0 ) ) {
F_23 ( T_7 , V_14 ) ;
} else {
V_14 -> V_12 = F_11 ( V_29 ) ;
V_14 -> V_35 = V_28 -> V_35 ;
V_14 -> V_36 = V_28 -> V_36 ;
F_25 ( T_7 , V_14 ) ;
}
F_13 ( V_29 ) ;
}
static void
F_32 ( T_9 * V_37 )
{
T_9 * V_27 ;
const T_6 * T_7 ;
V_3 * V_14 ;
V_27 = F_33 ( F_34 ( V_37 ) , V_38 ) ;
if ( V_39 == V_40 )
F_35 ( F_28 ( F_29 ( V_27 ) ) ) ;
V_14 = F_33 ( F_34 ( V_37 ) , V_41 ) ;
T_7 = L_2 ;
F_27 ( T_7 , V_14 , V_27 ) ;
}
static void
F_36 ( T_1 V_28 , T_1 V_42 , T_1 T_2 )
{
T_14 * V_43 = V_42 ;
if( strcmp ( V_43 -> V_44 , L_5 ) )
F_37 ( L_2 , V_43 -> V_44 , V_28 , T_2 ) ;
}
static T_9 *
F_38 ( T_9 * V_45 , const T_6 * T_7 V_2 )
{
T_9 * V_46 ;
T_9 * V_27 ;
F_39 ( V_45 , & V_27 , & V_46 ) ;
F_40 ( V_47 , F_36 , V_27 ) ;
F_41 ( V_27 ) ;
return ( V_46 ) ;
}
T_9 *
F_42 ( T_15 * V_48 )
{
T_9 * V_49 , * V_50 , * V_51 , * V_46 ;
T_16 * V_52 = F_11 ( L_6 ) ;
T_16 * V_53 = F_11 ( L_6 ) ;
V_3 * V_14 ;
V_14 = F_9 ( sizeof( V_3 ) ) ;
F_10 ( & V_14 -> V_10 , & V_48 -> V_54 ) ;
F_10 ( & V_14 -> V_11 , & V_48 -> V_55 ) ;
V_14 -> V_19 = V_48 -> V_19 ;
V_14 -> V_20 = V_48 -> V_56 ;
V_14 -> V_21 = V_48 -> V_57 ;
V_14 -> V_22 = V_48 -> V_58 ;
V_14 -> V_23 = F_43 ( V_48 ) ;
V_14 -> V_12 = NULL ;
V_14 -> V_36 = 0 ;
V_49 = F_44 ( V_59 , 5 , FALSE ) ;
F_45 ( F_34 ( V_49 ) , V_60 , F_32 ) ;
F_45 ( F_34 ( V_49 ) , V_61 , L_2 ) ;
F_45 ( F_34 ( V_49 ) , V_62 , L_2 ) ;
F_45 ( F_34 ( V_49 ) , V_41 , V_14 ) ;
V_50 = F_44 ( V_63 , 5 , FALSE ) ;
F_46 ( F_47 ( V_49 ) , V_50 , TRUE , TRUE , 0 ) ;
V_51 = F_48 ( L_7 ) ;
F_46 ( F_47 ( V_50 ) , V_51 , TRUE , TRUE , 0 ) ;
switch( V_14 -> V_19 ) {
case ( V_64 ) :
F_49 ( V_53 , L_8 ) ;
break;
case ( V_65 ) :
F_49 ( V_53 , L_9 ) ;
break;
default:
F_49 ( V_53 , L_10 ) ;
}
F_49 ( V_52 , L_11 , V_53 -> V_13 , V_14 -> V_20 ) ;
V_51 = F_48 ( V_52 -> V_13 ) ;
F_46 ( F_47 ( V_50 ) , V_51 , TRUE , TRUE , 0 ) ;
V_51 = F_48 ( L_12 ) ;
F_46 ( F_47 ( V_50 ) , V_51 , TRUE , TRUE , 0 ) ;
F_49 ( V_52 , L_11 , V_53 -> V_13 , V_14 -> V_21 ) ;
V_51 = F_48 ( V_52 -> V_13 ) ;
F_46 ( F_47 ( V_50 ) , V_51 , TRUE , TRUE , 0 ) ;
V_51 = F_48 ( L_12 ) ;
F_46 ( F_47 ( V_50 ) , V_51 , TRUE , TRUE , 0 ) ;
F_49 ( V_52 , L_13 , V_14 -> V_22 ) ;
V_51 = F_48 ( V_52 -> V_13 ) ;
F_46 ( F_47 ( V_50 ) , V_51 , TRUE , TRUE , 0 ) ;
V_51 = F_48 ( L_12 ) ;
F_46 ( F_47 ( V_50 ) , V_51 , TRUE , TRUE , 0 ) ;
F_50 ( V_51 , V_14 -> V_23 ) ;
F_49 ( V_52 , L_14 , V_14 -> V_23 ) ;
V_51 = F_48 ( V_52 -> V_13 ) ;
F_46 ( F_47 ( V_50 ) , V_51 , TRUE , TRUE , 0 ) ;
F_50 ( V_51 , V_14 -> V_23 ) ;
V_51 = F_48 ( L_15 ) ;
F_46 ( F_47 ( V_50 ) , V_51 , TRUE , TRUE , 0 ) ;
V_66 = F_51 ( V_66 , V_51 ) ;
V_46 = F_38 ( V_49 , L_16 ) ;
F_46 ( F_47 ( V_49 ) , V_46 , TRUE , TRUE , 0 ) ;
V_66 = F_51 ( V_66 , V_46 ) ;
F_14 ( V_52 , TRUE ) ;
return ( V_49 ) ;
}
