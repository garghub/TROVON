static int F_1 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * V_3 )
{
int V_4 = 0 ;
T_5 V_5 = F_2 ( V_1 , V_4 ) ;
T_6 * V_6 = F_3 ( V_3 , V_7 , V_1 , V_4 , 4 , V_5 ) ;
return F_4 ( V_1 , V_4 , 4 , V_6 , V_5 ) ;
}
static int F_5 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_3 )
{
return F_6 ( V_1 , T_3 , 0 , V_3 , V_8 ) ;
}
static int F_7 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_3 )
{
int V_4 = 0 ;
while( F_8 ( V_1 , V_4 ) > 0 ) {
V_4 = F_9 ( V_1 , T_3 , V_4 , V_3 ) ;
}
return V_4 ;
}
void
F_10 ( void )
{
static T_7 V_9 [] = {
{ & V_10 ,
{ L_1 , L_2 , V_11 , V_12 , NULL , 0x0 , NULL , V_13 }
} ,
{ & V_7 ,
{ L_3 , L_4 , V_14 , V_15 , NULL , 0x0 , NULL , V_13 } ,
} ,
} ;
static T_8 * V_16 [] = {
& V_17 ,
} ;
V_18 = F_11 ( L_5 , L_6 , L_7 ) ;
F_12 ( V_18 , V_9 , F_13 ( V_9 ) ) ;
F_14 ( V_16 , F_13 ( V_16 ) ) ;
}
void
F_15 ( void )
{
F_16 ( V_18 , V_17 , V_19 , V_20 ) ;
}
