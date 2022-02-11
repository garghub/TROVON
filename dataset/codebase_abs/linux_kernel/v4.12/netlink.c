int F_1 ( const struct V_1 * V_2 , struct V_3 * * * V_4 )
{
T_1 V_5 = V_6 . V_5 ;
* V_4 = F_2 ( & V_6 ) ;
if ( ! * V_4 )
return - V_7 ;
return F_3 ( V_2 , V_8 , * V_4 , V_5 , V_9 ,
NULL ) ;
}
int T_2 F_4 ( void )
{
int V_10 ;
V_10 = F_5 ( & V_6 ) ;
if ( V_10 ) {
F_6 ( L_1 ) ;
return V_10 ;
}
return 0 ;
}
void F_7 ( void )
{
F_8 ( & V_6 ) ;
}
