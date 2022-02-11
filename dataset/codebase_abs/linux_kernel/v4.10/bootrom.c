static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( V_2 , V_4 , V_5 ) ;
return 0 ;
}
static int F_3 ( struct V_6 * V_6 , struct V_7 * V_7 )
{
return F_4 ( V_7 , F_1 , NULL ) ;
}
static int F_5 ( void )
{
if ( ! F_6 ( L_1 , 0444 ,
NULL , NULL , & V_8 ) ) {
F_7 ( L_2 ) ;
return - V_9 ;
}
return 0 ;
}
