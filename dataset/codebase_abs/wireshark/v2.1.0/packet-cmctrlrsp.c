static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 * V_5 ;
T_3 * V_6 = NULL ;
T_6 V_7 ;
T_1 * V_8 ;
V_7 = F_2 ( V_1 , 0 ) ;
F_3 ( V_2 -> V_9 , V_10 ,
L_1 , V_7 ) ;
if ( V_3 )
{
V_5 =
F_4 ( V_3 , V_11 , V_1 , 0 , - 1 ,
L_2 ) ;
V_6 = F_5 ( V_5 , V_12 ) ;
F_6 ( V_6 , V_13 , V_1 , 0 , 2 ,
V_14 ) ;
}
V_8 = F_7 ( V_1 , 2 ) ;
F_8 ( V_15 , V_8 , V_2 , V_6 ) ;
return F_9 ( V_1 ) ;
}
void
F_10 ( void )
{
static T_7 V_16 [] = {
{ & V_13 ,
{ L_3 , L_4 ,
V_17 , V_18 , NULL , 0x0 ,
NULL , V_19 }
} ,
} ;
static T_8 * V_20 [] = {
& V_12 ,
} ;
V_11 =
F_11 ( L_5 ,
L_6 , L_7 ) ;
F_12 ( V_11 , V_16 , F_13 ( V_16 ) ) ;
F_14 ( V_20 , F_13 ( V_20 ) ) ;
F_15 ( L_7 , F_1 , V_11 ) ;
}
void
F_16 ( void )
{
T_9 V_21 ;
V_21 = F_17 ( L_7 ) ;
V_15 = F_17 ( L_8 ) ;
F_18 ( L_9 , 0x2B , V_21 ) ;
}
