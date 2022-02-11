static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_3 * V_4 , * V_5 ;
int V_6 ;
T_4 V_7 ;
T_1 * V_8 ;
F_2 ( V_2 -> V_9 , V_10 , L_1 ) ;
F_3 ( V_2 -> V_9 , V_11 ) ;
switch ( V_2 -> V_12 ) {
case V_13 :
F_2 ( V_2 -> V_9 , V_14 , L_2 ) ;
F_2 ( V_2 -> V_9 , V_15 , L_3 ) ;
break;
case V_16 :
F_2 ( V_2 -> V_9 , V_14 , L_3 ) ;
F_2 ( V_2 -> V_9 , V_15 , L_2 ) ;
break;
default:
F_2 ( V_2 -> V_9 , V_14 , L_4 ) ;
F_2 ( V_2 -> V_9 , V_15 , L_4 ) ;
break;
}
V_7 = F_4 ( V_1 , 0 ) ;
if ( V_7 != 0x01 && V_7 != 0x03 && V_7 != 0x07 && V_7 != 0x0f )
{
F_2 ( V_2 -> V_9 , V_11 , L_5 ) ;
if ( V_3 )
F_5 ( V_3 , V_17 , V_1 , 0 , - 1 ,
L_5 ) ;
return;
}
switch ( V_2 -> V_12 ) {
case V_13 :
if ( V_7 == 0x03 )
V_6 = TRUE ;
else
V_6 = FALSE ;
break;
case V_16 :
if ( V_7 == 0x01 )
V_6 = TRUE ;
else
V_6 = FALSE ;
break;
default:
V_6 = FALSE ;
break;
}
if ( V_3 ) {
V_5 = F_5 ( V_3 , V_17 , V_1 , 0 , 2 ,
L_1 ) ;
V_4 = F_6 ( V_5 , V_18 ) ;
F_7 ( V_4 , V_19 , V_1 , 0 , 1 , V_7 ,
L_6 , V_7 ) ;
}
else
V_4 = NULL ;
F_8 ( V_1 , 1 , V_2 , V_4 , V_20 ,
V_21 , & V_22 , NULL , NULL , NULL ,
V_6 , FALSE , FALSE ) ;
if ( F_9 ( V_1 ) > 2 ) {
V_8 = F_10 ( V_1 , 2 ) ;
switch ( V_2 -> V_12 ) {
case V_13 :
case V_16 :
F_11 ( V_23 , V_8 , V_2 , V_3 ) ;
break;
default:
F_11 ( V_24 , V_8 , V_2 , V_3 ) ;
break;
}
}
}
void
F_12 ( void )
{
static T_5 V_25 [] = {
{ & V_19 ,
{ L_7 , L_8 , V_26 , V_27 , NULL , 0x0 ,
L_9 , V_28 } } ,
{ & V_20 ,
{ L_10 , L_11 , V_26 , V_27 , NULL , 0x0 ,
NULL , V_28 } } ,
{ & V_29 ,
{ L_12 , L_13 , V_26 , V_30 ,
NULL , V_31 , NULL , V_28 } } ,
{ & V_32 ,
{ L_14 , L_15 , V_26 , V_30 ,
NULL , V_33 , NULL , V_28 } } ,
{ & V_34 ,
{ L_16 , L_17 , V_35 , 8 ,
F_13 ( & V_36 ) , V_37 , NULL , V_28 } } ,
{ & V_38 ,
{ L_18 , L_19 , V_35 , 8 ,
F_13 ( & V_36 ) , V_37 , NULL , V_28 } } ,
{ & V_39 ,
{ L_20 , L_21 , V_26 , V_27 ,
F_14 ( V_40 ) , V_41 , NULL , V_28 } } ,
{ & V_42 ,
{ L_22 , L_23 , V_26 , V_27 ,
F_14 ( V_43 ) , V_44 , NULL , V_28 } } ,
{ & V_45 ,
{ L_24 , L_25 , V_26 , V_27 ,
F_14 ( V_46 ) , V_44 , NULL , V_28 } } ,
{ & V_47 ,
{ L_26 , L_27 , V_26 , V_27 ,
F_14 ( V_48 ) , V_49 , NULL , V_28 } } ,
{ & V_50 ,
{ L_26 , L_27 , V_26 , V_27 ,
F_14 ( V_48 ) , V_51 , NULL , V_28 } } ,
} ;
static T_6 * V_52 [] = {
& V_18 ,
& V_21 ,
} ;
V_17 = F_15 ( L_28 ,
L_1 , L_29 ) ;
F_16 ( V_17 , V_25 , F_17 ( V_25 ) ) ;
F_18 ( V_52 , F_17 ( V_52 ) ) ;
F_19 ( L_29 , F_1 , V_17 ) ;
}
void
F_20 ( void )
{
T_7 V_53 ;
V_23 = F_21 ( L_30 ) ;
V_24 = F_21 ( L_31 ) ;
V_53 = F_21 ( L_29 ) ;
F_22 ( L_32 , V_54 , V_53 ) ;
}
