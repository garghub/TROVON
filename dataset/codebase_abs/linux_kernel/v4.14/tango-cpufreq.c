static int T_1 F_1 ( void )
{
struct V_1 * V_2 = F_2 ( 0 ) ;
unsigned long V_3 ;
struct V_4 * V_5 ;
void * V_6 ;
if ( ! F_3 ( V_7 , V_8 ) )
return - V_9 ;
V_5 = F_4 ( V_2 , NULL ) ;
if ( F_5 ( V_5 ) )
return - V_9 ;
V_3 = F_6 ( V_5 ) ;
F_7 ( V_2 , V_3 / 1 , 0 ) ;
F_7 ( V_2 , V_3 / 2 , 0 ) ;
F_7 ( V_2 , V_3 / 3 , 0 ) ;
F_7 ( V_2 , V_3 / 5 , 0 ) ;
F_7 ( V_2 , V_3 / 9 , 0 ) ;
V_6 = F_8 ( NULL , L_1 , - 1 , NULL , 0 ) ;
return F_9 ( V_6 ) ;
}
