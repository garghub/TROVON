static void F_1 ( void * V_1 )
{
F_2 () ;
}
void F_3 ( int V_2 )
{
F_4 ( V_2 , F_1 , NULL , 1 ) ;
}
int F_5 ( void )
{
return F_6 ( F_1 , NULL , 1 ) ;
}
