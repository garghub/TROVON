static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 + 28 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_4 , void * V_5 )
{
int V_6 ;
V_6 = F_4 ( F_5 ( 29 ) , V_4 , V_7 ,
L_1 , V_5 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_6 ( V_3 + 28 , L_2 ) ;
if ( V_6 ) {
F_7 ( F_5 ( 29 ) , V_5 ) ;
return V_6 ;
}
F_8 ( V_3 + 28 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 , void * V_5 )
{
F_7 ( F_5 ( 29 ) , V_5 ) ;
F_10 ( V_3 + 28 ) ;
}
void T_2 F_11 ( void )
{
F_12 ( V_8 , F_13 ( V_8 ) ,
L_3 ) ;
F_14 ( & V_9 ) ;
F_15 ( V_3 | 28 | V_10 | V_11 ) ;
F_16 ( 1 , & V_12 ) ;
F_17 ( & V_13 ) ;
}
