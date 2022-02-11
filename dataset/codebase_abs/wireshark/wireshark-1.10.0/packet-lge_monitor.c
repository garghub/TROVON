static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
int V_4 = 0 ;
T_4 V_5 ;
T_1 * V_6 = NULL ;
T_5 * V_7 ;
T_3 * V_8 ;
F_2 ( V_2 -> V_9 , V_10 , L_1 ) ;
V_7 = F_3 ( V_3 , V_11 , V_1 , 0 , V_12 , V_13 ) ;
V_8 = F_4 ( V_7 , V_14 ) ;
F_5 ( V_8 , V_1 , V_4 , V_12 , L_2 ) ;
F_3 ( V_8 , V_15 , V_1 , V_4 , 4 , V_16 ) ;
V_4 = V_4 + 4 ;
V_5 = F_6 ( V_1 , V_4 ) ;
F_3 ( V_8 , V_17 , V_1 , V_4 , 4 , V_16 ) ;
V_4 = V_4 + 4 ;
F_3 ( V_8 , V_18 , V_1 , V_4 , 4 , V_16 ) ;
V_4 = V_4 + 4 ;
V_6 = F_7 ( V_1 , V_4 ) ;
switch ( V_5 ) {
case 0 :
F_8 ( V_19 , V_6 , V_2 , V_3 ) ;
break;
case 1 :
F_8 ( V_20 , V_6 , V_2 , V_3 ) ;
break;
case 2 :
F_8 ( V_21 , V_6 , V_2 , V_3 ) ;
return;
case 3 :
F_8 ( V_22 , V_6 , V_2 , V_3 ) ;
return;
default:
F_5 ( V_8 , V_1 , V_4 , - 1 , L_3 ) ;
break;
}
return;
}
void
F_9 ( void )
{
static T_6 V_23 ;
static T_7 V_24 ;
static T_8 V_25 = FALSE ;
if ( ! V_25 ) {
V_23 = F_10 ( F_1 , V_11 ) ;
F_11 ( L_4 , V_23 ) ;
V_19 = F_12 ( L_5 ) ;
V_22 = F_12 ( L_6 ) ;
V_20 = F_12 ( L_7 ) ;
V_21 = F_12 ( L_8 ) ;
V_25 = TRUE ;
}
else {
if ( V_24 != 0 ) {
F_13 ( L_4 , V_24 , V_23 ) ;
}
}
if ( V_26 != 0 ) {
F_14 ( L_4 , V_26 , V_23 ) ;
}
V_24 = V_26 ;
}
void
F_15 ( void )
{
T_9 * V_27 ;
static T_10 V_28 [] = {
{ & V_15 ,
{ L_9 , L_10 ,
V_29 , V_30 , F_16 ( V_31 ) , 0x0 ,
NULL , V_32 }
} ,
{ & V_17 ,
{ L_11 , L_12 ,
V_29 , V_30 , F_16 ( V_33 ) , 0x0 ,
NULL , V_32 }
} ,
{ & V_18 ,
{ L_13 , L_14 ,
V_29 , V_30 , NULL , 0x0 ,
NULL , V_32 }
} ,
} ;
static T_11 * V_34 [] = {
& V_14 ,
} ;
V_11 = F_17 ( L_1 , L_15 , L_16 ) ;
F_18 ( V_11 , V_28 , F_19 ( V_28 ) ) ;
F_20 ( V_34 , F_19 ( V_34 ) ) ;
V_27 = F_21 ( V_11 , F_9 ) ;
F_22 ( V_27 , L_4 ,
L_17 ,
L_18 ,
10 ,
& V_26 ) ;
}
