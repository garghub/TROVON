static T_1
F_1 (
T_2 * V_1 , T_1 V_2 , T_3 * T_4 V_3 , T_5 * V_4 )
{
T_1 V_5 ;
T_6 V_6 , V_7 ;
T_7 * V_8 ;
T_5 * V_9 ;
V_5 = V_2 ;
V_6 = F_2 ( V_1 , V_2 ) ;
if ( V_6 == 0 )
return - 1 ;
V_9 = F_3 (
V_4 , V_1 , V_2 , - 1 , V_10 , & V_8 ,
L_1 , F_4 ( V_6 , V_11 , L_2 ) ) ;
F_5 ( V_9 , V_12 ,
V_1 , V_2 , 1 , V_13 ) ;
V_2 ++ ;
V_7 = F_2 ( V_1 , V_2 ) ;
F_5 ( V_9 , V_14 ,
V_1 , V_2 , 1 , V_13 ) ;
V_2 ++ ;
switch ( V_6 ) {
case V_15 :
F_5 ( V_9 , V_16 ,
V_1 , V_2 , 1 , V_13 ) ;
V_2 ++ ;
break;
case V_17 :
F_5 ( V_9 , V_18 ,
V_1 , V_2 , 1 , V_13 ) ;
V_2 ++ ;
F_5 ( V_9 , V_19 ,
V_1 , V_2 , 1 , V_13 ) ;
V_2 ++ ;
break;
case V_20 :
F_5 ( V_9 , V_21 , V_1 , V_2 , 1 , V_22 ) ;
V_2 ++ ;
F_5 ( V_9 , V_23 ,
V_1 , V_2 , 4 , V_13 ) ;
V_2 += 4 ;
break;
default:
V_2 += V_7 ;
break;
}
F_6 ( V_8 , V_2 - V_5 ) ;
return V_2 - V_5 ;
}
static int
F_7 ( T_2 * V_1 , T_3 * T_4 , T_5 * V_4 , void * T_8 V_3 )
{
T_7 * V_24 ;
T_5 * V_25 ;
T_1 V_2 = 0 ;
T_6 V_26 ;
T_1 V_27 ;
F_8 ( T_4 -> V_28 , V_29 ) ;
F_9 ( T_4 -> V_28 , V_30 , L_3 ) ;
V_24 = F_10 ( V_4 , V_31 ,
V_1 , 0 , F_11 ( V_1 ) ,
L_4 ) ;
V_25 = F_12 ( V_24 , V_32 ) ;
F_5 ( V_25 , V_33 , V_1 , V_2 , 1 , V_13 ) ;
V_2 ++ ;
V_26 = F_2 ( V_1 , V_2 ) ;
F_5 ( V_25 , V_34 ,
V_1 , V_2 , 1 , V_13 ) ;
F_13 ( T_4 -> V_28 , V_29 , L_5 ,
F_14 ( V_26 , V_35 , L_6 ) ) ;
V_2 ++ ;
while ( F_15 ( V_1 , V_2 ) > 0 ) {
V_27 = F_1 ( V_1 , V_2 , T_4 , V_25 ) ;
if ( V_27 <= 0 )
break;
V_2 += V_27 ;
}
return F_11 ( V_1 ) ;
}
void
F_16 ( void )
{
static T_9 V_36 [] = {
{ & V_33 ,
{ L_7 , L_8 , V_37 , V_38 ,
NULL , 0 , NULL , V_39 } } ,
{ & V_34 ,
{ L_9 , L_10 , V_37 , V_40 ,
F_17 ( V_35 ) , 0 , NULL , V_39 } } ,
{ & V_12 ,
{ L_11 , L_12 , V_37 , V_40 ,
F_17 ( V_11 ) , 0 , NULL , V_39 } } ,
{ & V_14 ,
{ L_13 , L_14 , V_37 , V_38 ,
NULL , 0 , NULL , V_39 } } ,
{ & V_16 ,
{ L_15 , L_16 , V_37 , V_38 ,
F_17 ( V_41 ) , 0 , NULL , V_39 } } ,
{ & V_18 ,
{ L_17 , L_18 , V_37 , V_38 ,
NULL , 0 , NULL , V_39 } } ,
{ & V_19 ,
{ L_19 , L_20 , V_37 , V_38 ,
NULL , 0 , NULL , V_39 } } ,
{ & V_23 ,
{ L_21 , L_22 , V_42 , V_40 ,
NULL , 0 , NULL , V_39 } } ,
{ & V_21 ,
{ L_23 , L_24 , V_37 , V_40 ,
NULL , 0 , NULL , V_39 } } ,
} ;
static T_1 * V_43 [] = {
& V_32 ,
& V_10
} ;
V_31 = F_18 (
L_25 , L_3 , L_26 ) ;
F_19 ( V_31 , V_36 , F_20 ( V_36 ) ) ;
F_21 ( V_43 , F_20 ( V_43 ) ) ;
}
void
F_22 ( void )
{
T_10 V_44 ;
V_44 = F_23 ( F_7 , V_31 ) ;
F_24 ( L_27 , V_45 , V_44 ) ;
}
