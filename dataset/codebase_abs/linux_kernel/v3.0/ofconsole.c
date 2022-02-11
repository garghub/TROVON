static int F_1 ( void )
{
void * V_1 ;
if ( ( ( V_1 = F_2 ( L_1 ) ) != NULL )
&& ( F_3 ( V_1 , L_2 , & V_2 ,
sizeof( V_2 ) )
== sizeof( V_2 ) ) )
return 0 ;
return - 1 ;
}
static void F_4 ( const char * V_3 , int V_4 )
{
F_5 ( L_3 , 3 , 1 , V_2 , V_3 , V_4 ) ;
}
void F_6 ( void )
{
V_5 . V_6 = F_1 ;
V_5 . V_7 = F_4 ;
}
