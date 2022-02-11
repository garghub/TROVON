static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * V_4 )
{
int V_5 = 0 ;
T_3 * V_6 ;
T_4 * V_7 ;
T_5 * V_8 ;
T_6 V_9 ;
T_6 V_10 ;
T_6 V_11 ;
T_7 V_12 ;
int V_13 ;
if ( V_4 == NULL )
return 0 ;
V_8 = ( T_5 * ) V_4 ;
F_2 ( V_2 -> V_14 , V_15 , L_1 ) ;
F_3 ( V_2 -> V_14 , V_16 ) ;
V_7 = F_4 ( V_3 , V_17 , V_1 , V_5 , - 1 , V_18 ) ;
V_6 = F_5 ( V_7 , V_19 ) ;
if ( * V_8 ) {
V_9 = F_6 ( V_1 , V_5 ) ;
F_7 ( V_2 -> V_14 , V_16 , L_2 ,
F_8 ( V_9 , V_20 ,
L_3 ) ) ;
F_9 ( V_6 , V_21 , V_1 ,
V_5 , 1 , V_9 ) ;
V_5 ++ ;
switch ( V_9 ) {
case V_22 :
case V_23 :
case V_24 :
case V_25 :
while ( F_10 ( V_1 , V_5 ) > 0 ) {
F_4 ( V_6 , V_26 , V_1 , V_5 , 1 , V_27 ) ;
V_5 ++ ;
F_4 ( V_6 , V_28 , V_1 , V_5 , 1 , V_27 ) ;
V_5 ++ ;
}
break;
case V_29 :
break;
case V_30 :
V_10 = F_6 ( V_1 , V_5 ) ;
F_9 ( V_6 , V_31 , V_1 ,
V_5 , 1 , V_10 ) ;
V_5 ++ ;
if ( V_10 != 0 ) {
F_4 ( V_6 , V_32 ,
V_1 , V_5 , 1 , V_27 ) ;
}
break;
case V_33 :
if ( F_10 ( V_1 , V_5 ) > 0 ) {
V_11 = F_6 ( V_1 , V_5 ) ;
F_4 ( V_6 , V_34 , V_1 , V_5 , 1 , V_27 ) ;
V_5 ++ ;
switch ( V_11 ) {
case 0x01 :
F_4 ( V_6 , V_35 , V_1 , V_5 , 1 , V_27 ) ;
V_5 ++ ;
break;
case 0x08 :
F_4 ( V_6 , V_36 , V_1 , V_5 , 1 , V_27 ) ;
V_5 ++ ;
break;
default:
F_4 ( V_6 , V_37 , V_1 , V_5 , 1 , V_27 ) ;
V_5 ++ ;
break;
}
}
break;
case V_38 :
F_4 ( V_6 , V_39 , V_1 , V_5 , - 1 , V_18 ) ;
break;
case V_40 :
F_4 ( V_6 , V_39 , V_1 , V_5 , - 1 , V_18 ) ;
break;
default:
F_4 ( V_6 , V_41 , V_1 , V_5 , - 1 , V_18 ) ;
break;
}
} else {
F_2 ( V_2 -> V_14 , V_16 , L_4 ) ;
if ( V_3 ) {
while ( F_11 ( V_1 , V_5 ) ) {
F_12 ( V_1 , V_5 , - 1 ,
& V_12 , FALSE ) ;
V_13 = V_12 - V_5 ;
F_4 ( V_6 , V_42 , V_1 , V_5 , V_13 , V_18 | V_43 ) ;
V_5 = V_12 ;
}
}
}
return F_13 ( V_1 ) ;
}
void
F_14 ( void )
{
static T_8 V_44 [] = {
{ & V_21 ,
{ L_5 , L_6 , V_45 , V_46 ,
F_15 ( V_20 ) , 0x0 , L_7 ,
V_47 } } ,
{ & V_31 ,
{ L_8 , L_9 , V_45 , V_46 ,
F_15 ( V_48 ) , 0x0 , L_10 ,
V_47 } } ,
{ & V_32 ,
{ L_11 , L_12 , V_45 , V_46 ,
F_15 ( V_20 ) , 0x0 , L_13 ,
V_47 } } ,
{ & V_34 , { L_14 , L_15 , V_45 , V_49 , F_15 ( V_50 ) , 0x0 , NULL , V_47 } } ,
{ & V_35 , { L_16 , L_17 , V_45 , V_46 , NULL , 0x0 , NULL , V_47 } } ,
{ & V_36 , { L_18 , L_19 , V_45 , V_46 , NULL , 0x0 , NULL , V_47 } } ,
{ & V_37 , { L_20 , L_21 , V_45 , V_46 , NULL , 0x0 , NULL , V_47 } } ,
{ & V_39 , { L_22 , L_23 , V_51 , V_52 , NULL , 0x0 , NULL , V_47 } } ,
{ & V_41 , { L_24 , L_25 , V_51 , V_52 , NULL , 0x0 , NULL , V_47 } } ,
{ & V_42 , { L_26 , L_27 , V_53 , V_52 , NULL , 0x0 , NULL , V_47 } } ,
{ & V_26 , { L_28 , L_29 , V_45 , V_49 , NULL , 0x0 , NULL , V_47 } } ,
{ & V_28 , { L_30 , L_31 , V_45 , V_49 , NULL , 0x0 , NULL , V_47 } } ,
} ;
static T_7 * V_54 [] = {
& V_19 ,
} ;
V_17 = F_16 ( L_1 , L_1 , L_32 ) ;
F_17 ( V_17 , V_44 , F_18 ( V_44 ) ) ;
F_19 ( V_54 , F_18 ( V_54 ) ) ;
}
void
F_20 ( void )
{
T_9 V_55 ;
V_55 = F_21 ( F_1 , V_17 ) ;
F_22 ( L_33 , V_56 , V_55 ) ;
}
