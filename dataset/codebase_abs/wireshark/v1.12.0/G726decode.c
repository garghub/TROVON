void *
F_1 ( void )
{
memset ( & V_1 , 0 , sizeof ( V_1 ) ) ;
F_2 ( & V_1 , 32000 , 0 , 1 ) ;
return NULL ;
}
void
F_3 ( void * T_1 V_2 )
{
}
int
F_4 ( void * T_1 V_2 )
{
return 1 ;
}
int
F_5 ( void * T_1 V_2 )
{
return 32000 ;
}
int
F_6 ( void * T_1 V_2 , const void * V_3 , int V_4 , void * V_5 ,
int * V_6 )
{
* V_6 = 2 * F_7 ( & V_1 , V_5 , ( void * ) V_3 , V_4 ) ;
return 0 ;
}
