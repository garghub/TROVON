static void
F_1 ( T_1 * V_1 , T_2 * V_2 )
{
T_3 V_3 ;
F_2 ( V_2 , V_4 , V_1 , V_5 , V_6 , V_7 ) ;
V_3 = F_3 ( V_1 , V_8 ) - V_9 ;
if ( V_3 > 0 )
F_2 ( V_2 , V_10 , V_1 , V_9 , V_3 , V_11 ) ;
}
static void
F_4 ( T_1 * V_1 , T_2 * V_2 )
{
T_3 V_12 ;
F_2 ( V_2 , V_13 , V_1 , V_14 , V_15 , V_7 ) ;
F_2 ( V_2 , V_16 , V_1 , V_17 , V_18 , V_7 ) ;
V_12 = F_3 ( V_1 , V_8 ) - V_19 ;
if ( V_12 > 0 ) {
F_2 ( V_2 , V_20 , V_1 , V_19 , V_12 , V_11 ) ;
}
}
static void
F_5 ( T_1 * V_1 , T_4 * V_21 , T_2 * V_22 )
{
T_5 type ;
type = F_6 ( V_1 , V_23 ) ;
if ( F_7 ( V_21 -> V_24 , V_25 ) ) {
F_8 ( V_21 -> V_24 , V_25 , L_1 , F_9 ( type , V_26 , L_2 ) ) ;
}
F_2 ( V_22 , V_27 , V_1 , V_23 , V_28 , V_7 ) ;
F_2 ( V_22 , V_29 , V_1 , V_30 , V_31 , V_7 ) ;
F_2 ( V_22 , V_32 , V_1 , V_8 , V_33 , V_7 ) ;
switch ( type ) {
case V_34 :
F_1 ( V_1 , V_22 ) ;
break;
case V_35 :
F_4 ( V_1 , V_22 ) ;
break;
}
}
static int
F_10 ( T_1 * V_1 , T_4 * V_21 , T_2 * V_36 )
{
T_6 * V_37 ;
T_2 * V_22 ;
F_11 ( V_21 -> V_24 , V_38 , L_3 ) ;
if ( V_36 ) {
V_37 = F_2 ( V_36 , V_39 , V_1 , 0 , - 1 , V_11 ) ;
V_22 = F_12 ( V_37 , V_40 ) ;
} else {
V_22 = NULL ;
} ;
F_5 ( V_1 , V_21 , V_22 ) ;
return ( TRUE ) ;
}
void
F_13 ( void )
{
static T_7 V_41 [] = {
{ & V_27 , { L_4 , L_5 , V_42 , V_43 , F_14 ( V_26 ) , 0x0 , NULL , V_44 } } ,
{ & V_29 , { L_6 , L_7 , V_42 , V_43 , NULL , 0x0 , NULL , V_44 } } ,
{ & V_32 , { L_8 , L_9 , V_45 , V_43 , NULL , 0x0 , NULL , V_44 } } ,
{ & V_4 , { L_10 , L_11 , V_46 , V_43 , NULL , 0x0 , NULL , V_44 } } ,
{ & V_10 , { L_12 , L_13 , V_47 , V_48 , NULL , 0x0 , NULL , V_44 } } ,
{ & V_13 , { L_10 , L_14 , V_46 , V_43 , NULL , 0x0 , NULL , V_44 } } ,
{ & V_16 , { L_15 , L_16 , V_46 , V_43 , NULL , 0x0 , NULL , V_44 } } ,
{ & V_20 , { L_17 , L_18 , V_47 , V_48 , NULL , 0x0 , NULL , V_44 } } ,
} ;
static T_8 * V_49 [] = {
& V_40
} ;
V_39 = F_15 ( L_19 , L_3 , L_20 ) ;
F_16 ( V_39 , V_41 , F_17 ( V_41 ) ) ;
F_18 ( V_49 , F_17 ( V_49 ) ) ;
}
void
F_19 ( void )
{
T_9 V_50 ;
V_50 = F_20 ( F_10 , V_39 ) ;
F_21 ( L_21 , V_51 , V_50 ) ;
F_21 ( L_21 , V_52 , V_50 ) ;
}
