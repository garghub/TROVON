static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_3 * V_4 ;
T_4 * V_5 ;
T_1 * V_6 ;
T_5 type ;
F_2 ( V_2 -> V_7 , V_8 , L_1 ) ;
F_2 ( V_2 -> V_7 , V_9 , L_2 ) ;
if ( V_3 ) {
V_5 = F_3 ( V_3 , V_10 , V_1 , 0 , 4 , V_11 ) ;
V_4 = F_4 ( V_5 , V_12 ) ;
F_3 ( V_4 , V_13 , V_1 , 0 , 2 , V_14 ) ;
F_3 ( V_4 , V_15 , V_1 , 2 , 2 , V_14 ) ;
}
V_6 = F_5 ( V_1 , 4 ) ;
type = F_6 ( V_1 , 0 ) ;
switch ( type ) {
case V_16 :
F_7 ( V_17 , V_6 , V_2 , V_3 ) ;
break;
case V_18 :
F_7 ( V_19 , V_6 , V_2 , V_3 ) ;
break;
case V_20 :
case V_21 :
F_7 ( V_22 , V_6 , V_2 , V_3 ) ;
break;
default:
break;
}
}
void
F_8 ( void )
{
static T_6 V_23 [] = {
{ & V_13 ,
{ L_3 , L_4 ,
V_24 , V_25 , F_9 ( V_26 ) , 0x0 ,
NULL , V_27 } } ,
{ & V_15 ,
{ L_5 , L_6 ,
V_24 , V_25 , NULL , 0x0 ,
NULL , V_27 } }
} ;
static T_7 * V_28 [] = {
& V_12
} ;
V_10 = F_10 ( L_2 , L_1 , L_7 ) ;
F_11 ( V_10 , V_23 , F_12 ( V_23 ) ) ;
F_13 ( V_28 , F_12 ( V_28 ) ) ;
}
void
F_14 ( void )
{
T_8 V_29 ;
V_22 = F_15 ( L_8 ) ;
V_17 = F_15 ( L_9 ) ;
V_19 = F_15 ( L_10 ) ;
V_29 = F_16 ( F_1 , V_10 ) ;
F_17 ( L_11 , V_30 , V_29 ) ;
}
