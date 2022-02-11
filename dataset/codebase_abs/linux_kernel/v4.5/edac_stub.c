static int T_1 F_1 ( char * V_1 )
{
if ( ! V_1 )
return - V_2 ;
if ( ! strncmp ( V_1 , L_1 , 2 ) )
F_2 ( V_3 ) ;
else if ( ! strncmp ( V_1 , L_2 , 3 ) )
F_2 ( V_4 ) ;
else if ( ! strncmp ( V_1 , L_3 , 5 ) )
F_2 ( V_5 ) ;
return 0 ;
}
int F_3 ( void )
{
if ( V_6 == V_7 )
return 0 ;
return F_4 ( & V_8 ) ;
}
void F_5 ( void )
{
V_9 ++ ;
}
