static int
F_1 ( T_1 * V_1 , int V_2 , T_2 * V_3 ,
T_3 * V_4 , T_4 * V_5 )
{
V_2 = F_2 ( V_1 , V_2 , V_3 , V_4 , V_5 ,
V_6 , V_7 ,
L_1 , V_8 ) ;
V_2 = F_2 ( V_1 , V_2 , V_3 , V_4 , V_5 ,
V_6 , V_7 ,
L_2 , V_9 ) ;
V_2 = F_2 ( V_1 , V_2 , V_3 , V_4 , V_5 ,
V_6 , V_7 ,
L_3 , V_10 ) ;
return V_2 ;
}
static int
F_3 ( T_1 * V_1 , int V_2 , T_2 * V_3 ,
T_3 * V_4 , T_4 * V_5 )
{
V_2 = F_4 ( V_1 , V_2 , V_3 , V_4 , V_5 ,
V_11 , NULL ) ;
return V_2 ;
}
void
F_5 ( void )
{
static T_5 V_12 [] = {
{ & V_13 ,
{ L_4 , L_5 , V_14 , V_15 ,
NULL , 0x0 , NULL , V_16 } } ,
{ & V_11 ,
{ L_6 , L_7 , V_17 , V_18 , F_6 ( V_19 ) , 0x0 , NULL , V_16 } } ,
{ & V_8 , {
L_1 , L_8 ,
V_20 , V_21 , NULL , 0 , L_9 , V_16 } } ,
{ & V_9 , {
L_2 , L_10 ,
V_20 , V_21 , NULL , 0 , L_11 , V_16 } } ,
{ & V_10 , {
L_3 , L_12 ,
V_20 , V_21 , NULL , 0 , L_13 , V_16 } }
} ;
static T_6 * V_22 [] = {
& V_23
} ;
V_24 = F_7 (
L_14 , L_15 , L_16 ) ;
F_8 ( V_24 , V_12 , F_9 ( V_12 ) ) ;
F_10 ( V_22 , F_9 ( V_22 ) ) ;
}
void
F_11 ( void )
{
F_12 ( V_24 , V_23 , & V_25 ,
V_26 , V_27 , V_13 ) ;
}
