static int
F_1 ( T_1 * V_1 , int V_2 ,
T_2 * V_3 , T_3 * V_4 , T_4 * V_5 )
{
V_2 = F_2 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
V_2 = F_3 ( V_1 , V_2 , V_3 , V_4 , V_5 , 4 ) ;
V_2 = F_4 ( V_1 , V_2 , V_3 , V_4 , V_5 ,
V_6 , NULL ) ;
return V_2 ;
}
static int
F_5 ( T_1 * V_1 , int V_2 ,
T_2 * V_3 , T_3 * V_4 , T_4 * V_5 )
{
V_2 = F_6 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
V_2 = F_4 ( V_1 , V_2 , V_3 , V_4 , V_5 ,
V_6 , NULL ) ;
V_2 = F_7 ( V_1 , V_2 , V_3 , V_4 , V_5 ,
NULL ) ;
return V_2 ;
}
void
F_8 ( void )
{
static T_5 V_7 [] = {
{ & V_8 ,
{ L_1 , L_2 , V_9 , V_10 , NULL , 0x0 , NULL , V_11 } } ,
{ & V_6 ,
{ L_3 , L_4 , V_12 , V_13 , NULL , 0x0 , NULL , V_11 } } ,
} ;
static T_6 * V_14 [] = {
& V_15
} ;
V_16 = F_9 ( L_5 ,
L_6 ,
L_7 ) ;
F_10 ( V_16 , V_7 , F_11 ( V_7 ) ) ;
F_12 ( V_14 , F_11 ( V_14 ) ) ;
}
void
F_13 ( void )
{
F_14 ( V_16 , V_15 ,
& V_17 , V_18 ,
V_19 , V_8 ) ;
}
