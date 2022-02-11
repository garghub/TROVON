void *
F_1 ( void )
{
memset ( & V_1 , 0 , sizeof ( V_1 ) ) ;
F_2 ( & V_1 , 64000 , 0 ) ;
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
return 64000 ;
}
int
F_6 ( void * T_1 V_2 , const void * V_3 , int V_4 , void * V_5 ,
int * V_6 )
{
* V_6 = F_7 ( & V_1 , V_5 , V_3 , V_4 ) ;
return 0 ;
}
