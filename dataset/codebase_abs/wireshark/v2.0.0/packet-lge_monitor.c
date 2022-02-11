static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
int V_4 = 0 ;
T_4 V_5 ;
T_1 * V_6 = NULL ;
T_3 * V_7 ;
T_5 * V_8 ;
T_3 * V_9 ;
F_2 ( V_2 -> V_10 , V_11 , L_1 ) ;
V_8 = F_3 ( V_3 , V_12 , V_1 , 0 , V_13 , V_14 ) ;
V_9 = F_4 ( V_8 , V_15 ) ;
V_7 = F_5 ( V_9 , V_1 , V_4 , V_13 , V_16 , NULL , L_2 ) ;
F_3 ( V_7 , V_17 , V_1 , V_4 , 4 , V_18 ) ;
V_4 += 4 ;
V_5 = F_6 ( V_1 , V_4 ) ;
F_3 ( V_7 , V_19 , V_1 , V_4 , 4 , V_18 ) ;
V_4 += 4 ;
F_3 ( V_7 , V_20 , V_1 , V_4 , 4 , V_18 ) ;
V_4 += 4 ;
V_6 = F_7 ( V_1 , V_4 ) ;
switch ( V_5 ) {
case 0 :
F_8 ( V_21 , V_6 , V_2 , V_3 ) ;
break;
case 1 :
F_8 ( V_22 , V_6 , V_2 , V_3 ) ;
break;
case 2 :
F_8 ( V_23 , V_6 , V_2 , V_3 ) ;
return;
case 3 :
F_8 ( V_24 , V_6 , V_2 , V_3 ) ;
return;
default:
F_3 ( V_9 , V_25 , V_1 , V_4 , - 1 , V_14 ) ;
break;
}
return;
}
void
F_9 ( void )
{
static T_6 V_26 ;
static T_7 V_27 ;
static T_8 V_28 = FALSE ;
if ( ! V_28 ) {
V_26 = F_10 ( F_1 , V_12 ) ;
F_11 ( L_3 , V_26 ) ;
V_21 = F_12 ( L_4 ) ;
V_24 = F_12 ( L_5 ) ;
V_22 = F_12 ( L_6 ) ;
V_23 = F_12 ( L_7 ) ;
V_28 = TRUE ;
}
else {
if ( V_27 != 0 ) {
F_13 ( L_3 , V_27 , V_26 ) ;
}
}
if ( V_29 != 0 ) {
F_14 ( L_3 , V_29 , V_26 ) ;
}
V_27 = V_29 ;
}
void
F_15 ( void )
{
T_9 * V_30 ;
static T_10 V_31 [] = {
{ & V_17 ,
{ L_8 , L_9 ,
V_32 , V_33 , F_16 ( V_34 ) , 0x0 ,
NULL , V_35 }
} ,
{ & V_19 ,
{ L_10 , L_11 ,
V_32 , V_33 , F_16 ( V_36 ) , 0x0 ,
NULL , V_35 }
} ,
{ & V_20 ,
{ L_12 , L_13 ,
V_32 , V_33 , NULL , 0x0 ,
NULL , V_35 }
} ,
{ & V_25 ,
{ L_14 , L_15 ,
V_37 , V_38 , NULL , 0x0 ,
NULL , V_35 }
} ,
} ;
static T_11 * V_39 [] = {
& V_15 ,
& V_16
} ;
V_12 = F_17 ( L_1 , L_16 , L_17 ) ;
F_18 ( V_12 , V_31 , F_19 ( V_31 ) ) ;
F_20 ( V_39 , F_19 ( V_39 ) ) ;
V_30 = F_21 ( V_12 , F_9 ) ;
F_22 ( V_30 , L_3 ,
L_18 ,
L_19 ,
10 ,
& V_29 ) ;
}
