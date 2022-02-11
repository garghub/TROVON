void F_1 ( void )
{
T_1 V_1 ;
T_1 V_2 ;
V_1 = F_2 ( L_1 ) ;
V_2 = F_2 ( L_2 ) ;
F_3 ( L_3 , V_3 , V_1 ) ;
F_3 ( L_3 , V_4 , V_2 ) ;
}
void F_4 ( void )
{
static T_2 V_5 [] = {
{ & V_6 ,
{ L_4 , L_3 , V_7 , V_8 ,
F_5 ( V_9 ) , 0x0 , L_5 , V_10 }
}
} ;
F_6 ( V_11 , L_3 , L_6 , V_5 ) ;
}
