static T_1 F_1 ( int V_1 , void * V_2 )
{
char V_3 ;
F_2 ( V_4 , & V_3 , sizeof( V_3 ) ) ;
F_3 ( V_4 , V_5 ) ;
return V_6 ;
}
int F_4 ( int V_7 )
{
int V_8 ;
V_8 = F_5 ( V_5 , V_7 , V_9 , F_1 ,
0 , L_1 , NULL ) ;
if ( V_8 ) {
F_6 ( V_10 L_2
L_3 , V_8 ) ;
return - 1 ;
}
V_4 = V_7 ;
return 0 ;
}
void F_7 ( void )
{
F_8 ( & V_11 ) ;
}
void F_9 ( void )
{
F_10 ( & V_11 ) ;
}
