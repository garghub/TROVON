int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
if ( F_2 () == V_5 ) {
F_3 ( L_1 ) ;
return - V_6 ;
}
return F_4 ( V_2 , V_3 , V_4 ) ;
}
void T_1 F_5 ( void )
{
struct V_7 * V_8 ;
struct V_7 * V_9 ;
V_8 = F_6 ( NULL , L_2 ) ;
F_7 ( V_8 , V_10 ) ;
F_8 ( V_8 ) ;
V_9 = F_6 ( NULL , L_3 ) ;
F_8 ( V_9 ) ;
F_7 ( V_9 , V_10 ) ;
F_9 ( V_9 ) ;
F_9 ( V_8 ) ;
return;
}
static int T_1 F_10 ( void )
{
int V_11 ;
if ( ! F_11 () )
return 0 ;
V_11 = F_12 ( L_4 ) ;
if ( ! V_11 )
F_13 ( L_5 , L_6 , L_7 ) ;
return V_11 ;
}
