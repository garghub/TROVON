static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 * V_5 ;
T_3 * V_6 ;
T_6 V_7 ;
T_7 V_8 ;
F_2 ( V_2 -> V_9 , V_10 , L_1 ) ;
if ( V_3 ) {
V_5 = F_3 ( V_3 , V_11 , V_1 , 0 , 5 , V_12 ) ;
V_6 = F_4 ( V_5 , V_13 ) ;
V_7 = F_5 ( V_1 , 2 ) ;
F_6 ( V_6 , V_14 , V_1 , 2 , 1 , V_7 ) ;
V_8 = F_7 ( V_1 , 3 ) ;
F_6 ( V_6 , V_15 , V_1 , 3 , 2 , V_8 ) ;
}
return 5 ;
}
void
F_8 ( void )
{
static T_8 V_16 [] = {
{ & V_14 ,
{ L_2 , L_3 , V_17 , V_18 ,
NULL , 0x0 , NULL , V_19 } } ,
{ & V_15 ,
{ L_4 , L_5 , V_20 , V_21 ,
NULL , 0x0 , NULL , V_19 } } ,
} ;
static T_9 * V_22 [] = {
& V_13
} ;
V_11 = F_9 ( L_6 , L_1 , L_7 ) ;
F_10 ( V_11 , V_16 , F_11 ( V_16 ) ) ;
F_12 ( V_22 , F_11 ( V_22 ) ) ;
F_13 ( L_7 , F_1 , V_11 ) ;
}
