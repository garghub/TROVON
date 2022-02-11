static void
F_1 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * V_3 )
{
T_5 * V_4 ;
T_4 * V_5 ;
int V_6 = 0 ;
switch ( T_3 -> V_7 ) {
case V_8 :
F_2 ( T_3 -> V_9 , V_10 , L_1 ) ;
break;
case V_11 :
F_2 ( T_3 -> V_9 , V_10 , L_2 ) ;
break;
default:
F_3 ( T_3 -> V_9 , V_10 , L_3 ,
T_3 -> V_7 ) ;
break;
}
V_4 = F_4 ( V_3 , V_12 , V_1 , V_6 , - 1 , V_13 ) ;
V_5 = F_5 ( V_4 , V_14 ) ;
F_4 ( V_5 , V_15 , V_1 , V_6 , 2 , V_16 ) ;
V_6 += 2 ;
F_4 ( V_5 , V_17 , V_1 , V_6 , 1 , V_16 ) ;
V_6 ++ ;
F_4 ( V_5 , V_18 , V_1 , V_6 , - 1 , V_13 ) ;
}
void
F_6 ( void )
{
static T_6 V_19 [] = {
{ & V_15 ,
{ L_4 , L_5 ,
V_20 , V_21 , NULL , 0x0FFF ,
NULL , V_22 }
} ,
{ & V_17 ,
{ L_6 , L_7 ,
V_23 , V_24 , NULL , 0x0 ,
NULL , V_22 }
} ,
{ & V_18 ,
{ L_8 , L_9 ,
V_25 , V_26 , NULL , 0x0 ,
NULL , V_22 }
} ,
} ;
static T_7 * V_27 [] = {
& V_14
} ;
V_12 = F_7 ( L_10 , L_11 , L_12 ) ;
F_8 ( L_12 , F_1 , V_12 ) ;
F_9 ( V_12 , V_19 , F_10 ( V_19 ) ) ;
F_11 ( V_27 , F_10 ( V_27 ) ) ;
}
void
F_12 ( void )
{
T_8 V_28 ;
V_28 = F_13 ( L_12 ) ;
F_14 ( L_13 , V_29 , V_28 ) ;
F_14 ( L_14 , V_30 , V_28 ) ;
}
