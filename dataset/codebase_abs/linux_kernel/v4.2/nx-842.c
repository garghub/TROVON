int F_1 ( struct F_1 * V_1 )
{
memcpy ( V_1 , F_2 () -> V_2 , sizeof( * V_1 ) ) ;
return 0 ;
}
T_1 F_3 ( void )
{
return F_2 () -> V_3 ;
}
int F_4 ( const unsigned char * V_4 , unsigned int V_5 ,
unsigned char * V_6 , unsigned int * V_7 , void * V_8 )
{
return F_2 () -> F_5 ( V_4 , V_5 , V_6 , V_7 , V_8 ) ;
}
int F_6 ( const unsigned char * V_4 , unsigned int V_5 ,
unsigned char * V_6 , unsigned int * V_7 , void * V_8 )
{
return F_2 () -> F_7 ( V_4 , V_5 , V_6 , V_7 , V_8 ) ;
}
static T_2 int F_8 ( void )
{
F_9 ( L_1 ) ;
F_9 ( L_2 ) ;
if ( ! F_10 () ) {
F_11 ( L_3 ) ;
return - V_9 ;
}
return 0 ;
}
static void T_3 F_12 ( void )
{
F_13 () ;
}
