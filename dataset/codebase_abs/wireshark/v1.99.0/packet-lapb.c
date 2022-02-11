static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_3 * V_4 , * V_5 ;
T_4 V_6 ;
int V_7 ;
T_5 V_8 ;
T_1 * V_9 ;
F_2 ( V_2 -> V_10 , V_11 , L_1 ) ;
F_3 ( V_2 -> V_10 , V_12 ) ;
switch ( V_2 -> V_13 ) {
case V_14 :
F_2 ( V_2 -> V_10 , V_15 , L_2 ) ;
F_2 ( V_2 -> V_10 , V_16 , L_3 ) ;
break;
case V_17 :
F_2 ( V_2 -> V_10 , V_15 , L_3 ) ;
F_2 ( V_2 -> V_10 , V_16 , L_2 ) ;
break;
default:
F_2 ( V_2 -> V_10 , V_15 , L_4 ) ;
F_2 ( V_2 -> V_10 , V_16 , L_4 ) ;
break;
}
V_8 = F_4 ( V_1 , 0 ) ;
if ( V_8 != 0x01 && V_8 != 0x03 && V_8 != 0x07 && V_8 != 0x0f )
{
F_2 ( V_2 -> V_10 , V_12 , L_5 ) ;
if ( V_3 )
F_5 ( V_3 , V_18 , V_1 , 0 , - 1 ,
L_5 ) ;
return;
}
switch ( V_2 -> V_13 ) {
case V_14 :
if ( V_8 == 0x03 )
V_7 = TRUE ;
else
V_7 = FALSE ;
break;
case V_17 :
if ( V_8 == 0x01 )
V_7 = TRUE ;
else
V_7 = FALSE ;
break;
default:
V_7 = FALSE ;
break;
}
V_5 = F_5 ( V_3 , V_18 , V_1 , 0 , 2 ,
L_1 ) ;
V_4 = F_6 ( V_5 , V_19 ) ;
F_7 ( V_4 , V_20 , V_1 , 0 , 1 , V_8 ) ;
V_6 = F_8 ( V_1 , 1 , V_2 , V_4 , V_21 ,
V_22 , & V_23 , NULL , NULL , NULL ,
V_7 , FALSE , FALSE ) ;
if ( F_9 ( V_6 ) ) {
V_9 = F_10 ( V_1 , 2 ) ;
switch ( V_2 -> V_13 ) {
case V_14 :
case V_17 :
F_11 ( V_24 , V_9 , V_2 , V_3 ) ;
break;
default:
F_11 ( V_25 , V_9 , V_2 , V_3 ) ;
break;
}
}
}
void
F_12 ( void )
{
static T_6 V_26 [] = {
{ & V_20 ,
{ L_6 , L_7 , V_27 , V_28 , NULL , 0x0 ,
NULL , V_29 } } ,
{ & V_21 ,
{ L_8 , L_9 , V_27 , V_28 , NULL , 0x0 ,
NULL , V_29 } } ,
{ & V_30 ,
{ L_10 , L_11 , V_27 , V_31 ,
NULL , V_32 , NULL , V_29 } } ,
{ & V_33 ,
{ L_12 , L_13 , V_27 , V_31 ,
NULL , V_34 , NULL , V_29 } } ,
{ & V_35 ,
{ L_14 , L_15 , V_36 , 8 ,
F_13 ( & V_37 ) , V_38 , NULL , V_29 } } ,
{ & V_39 ,
{ L_16 , L_17 , V_36 , 8 ,
F_13 ( & V_37 ) , V_38 , NULL , V_29 } } ,
{ & V_40 ,
{ L_18 , L_19 , V_27 , V_28 ,
F_14 ( V_41 ) , V_42 , NULL , V_29 } } ,
{ & V_43 ,
{ L_20 , L_21 , V_27 , V_28 ,
F_14 ( V_44 ) , V_45 , NULL , V_29 } } ,
{ & V_46 ,
{ L_22 , L_23 , V_27 , V_28 ,
F_14 ( V_47 ) , V_45 , NULL , V_29 } } ,
{ & V_48 ,
{ L_24 , L_25 , V_27 , V_28 ,
F_14 ( V_49 ) , V_50 , NULL , V_29 } } ,
{ & V_51 ,
{ L_24 , L_25 , V_27 , V_28 ,
F_14 ( V_49 ) , V_52 , NULL , V_29 } } ,
} ;
static T_7 * V_53 [] = {
& V_19 ,
& V_22 ,
} ;
V_18 = F_15 ( L_26 ,
L_1 , L_27 ) ;
F_16 ( V_18 , V_26 , F_17 ( V_26 ) ) ;
F_18 ( V_53 , F_17 ( V_53 ) ) ;
F_19 ( L_27 , F_1 , V_18 ) ;
}
void
F_20 ( void )
{
T_8 V_54 ;
V_24 = F_21 ( L_28 ) ;
V_25 = F_21 ( L_29 ) ;
V_54 = F_21 ( L_27 ) ;
F_22 ( L_30 , V_55 , V_54 ) ;
}
