static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_3 * V_5 , * V_6 ;
T_5 V_7 ;
int V_8 ;
T_6 V_9 ;
T_1 * V_10 ;
F_2 ( V_2 -> V_11 , V_12 , L_1 ) ;
F_3 ( V_2 -> V_11 , V_13 ) ;
switch ( V_2 -> V_14 ) {
case V_15 :
F_2 ( V_2 -> V_11 , V_16 , L_2 ) ;
F_2 ( V_2 -> V_11 , V_17 , L_3 ) ;
break;
case V_18 :
F_2 ( V_2 -> V_11 , V_16 , L_3 ) ;
F_2 ( V_2 -> V_11 , V_17 , L_2 ) ;
break;
default:
F_2 ( V_2 -> V_11 , V_16 , L_4 ) ;
F_2 ( V_2 -> V_11 , V_17 , L_4 ) ;
break;
}
V_9 = F_4 ( V_1 , 0 ) ;
if ( V_9 != 0x01 && V_9 != 0x03 && V_9 != 0x07 && V_9 != 0x0f )
{
F_2 ( V_2 -> V_11 , V_13 , L_5 ) ;
if ( V_3 )
F_5 ( V_3 , V_19 , V_1 , 0 , - 1 ,
L_5 ) ;
return 1 ;
}
switch ( V_2 -> V_14 ) {
case V_15 :
if ( V_9 == 0x03 )
V_8 = TRUE ;
else
V_8 = FALSE ;
break;
case V_18 :
if ( V_9 == 0x01 )
V_8 = TRUE ;
else
V_8 = FALSE ;
break;
default:
V_8 = FALSE ;
break;
}
V_6 = F_5 ( V_3 , V_19 , V_1 , 0 , 2 ,
L_1 ) ;
V_5 = F_6 ( V_6 , V_20 ) ;
F_7 ( V_5 , V_21 , V_1 , 0 , 1 , V_9 ) ;
V_7 = F_8 ( V_1 , 1 , V_2 , V_5 , V_22 ,
V_23 , & V_24 , NULL , NULL , NULL ,
V_8 , FALSE , FALSE ) ;
if ( F_9 ( V_7 ) ) {
V_10 = F_10 ( V_1 , 2 ) ;
switch ( V_2 -> V_14 ) {
case V_15 :
case V_18 :
F_11 ( V_25 , V_10 , V_2 , V_3 ) ;
break;
default:
F_11 ( V_26 , V_10 , V_2 , V_3 ) ;
break;
}
}
return F_12 ( V_1 ) ;
}
void
F_13 ( void )
{
static T_7 V_27 [] = {
{ & V_21 ,
{ L_6 , L_7 , V_28 , V_29 , NULL , 0x0 ,
NULL , V_30 } } ,
{ & V_22 ,
{ L_8 , L_9 , V_28 , V_29 , NULL , 0x0 ,
NULL , V_30 } } ,
{ & V_31 ,
{ L_10 , L_11 , V_28 , V_32 ,
NULL , V_33 , NULL , V_30 } } ,
{ & V_34 ,
{ L_12 , L_13 , V_28 , V_32 ,
NULL , V_35 , NULL , V_30 } } ,
{ & V_36 ,
{ L_14 , L_15 , V_37 , 8 ,
F_14 ( & V_38 ) , V_39 , NULL , V_30 } } ,
{ & V_40 ,
{ L_16 , L_17 , V_37 , 8 ,
F_14 ( & V_38 ) , V_39 , NULL , V_30 } } ,
{ & V_41 ,
{ L_18 , L_19 , V_28 , V_29 ,
F_15 ( V_42 ) , V_43 , NULL , V_30 } } ,
{ & V_44 ,
{ L_20 , L_21 , V_28 , V_29 ,
F_15 ( V_45 ) , V_46 , NULL , V_30 } } ,
{ & V_47 ,
{ L_22 , L_23 , V_28 , V_29 ,
F_15 ( V_48 ) , V_46 , NULL , V_30 } } ,
{ & V_49 ,
{ L_24 , L_25 , V_28 , V_29 ,
F_15 ( V_50 ) , V_51 , NULL , V_30 } } ,
{ & V_52 ,
{ L_24 , L_25 , V_28 , V_29 ,
F_15 ( V_50 ) , V_53 , NULL , V_30 } } ,
} ;
static T_8 * V_54 [] = {
& V_20 ,
& V_23 ,
} ;
V_19 = F_16 ( L_26 ,
L_1 , L_27 ) ;
F_17 ( V_19 , V_27 , F_18 ( V_27 ) ) ;
F_19 ( V_54 , F_18 ( V_54 ) ) ;
F_20 ( L_27 , F_1 , V_19 ) ;
}
void
F_21 ( void )
{
T_9 V_55 ;
V_25 = F_22 ( L_28 , V_19 ) ;
V_26 = F_22 ( L_29 , V_19 ) ;
V_55 = F_23 ( L_27 ) ;
F_24 ( L_30 , V_56 , V_55 ) ;
}
