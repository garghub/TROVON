int F_1 ( struct V_1 * V_1 , unsigned long V_2 )
{
if ( F_2 () == V_3 ) {
F_3 ( L_1 ) ;
return - V_4 ;
}
return F_4 ( V_1 , V_2 ) ;
}
void T_1 F_5 ( void )
{
struct V_1 * V_5 ;
struct V_1 * V_6 ;
V_5 = F_6 ( NULL , L_2 ) ;
F_7 ( V_5 , V_7 ) ;
F_8 ( V_5 ) ;
V_6 = F_6 ( NULL , L_3 ) ;
F_8 ( V_6 ) ;
F_7 ( V_6 , V_7 ) ;
F_9 ( V_6 ) ;
F_9 ( V_5 ) ;
return;
}
static int T_1 F_10 ( void )
{
int V_8 ;
if ( ! F_11 () )
return 0 ;
V_8 = F_12 ( L_4 ) ;
if ( ! V_8 )
F_13 ( L_5 , L_6 , L_7 ) ;
return V_8 ;
}
