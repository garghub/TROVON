int F_1 ( const struct V_1 * V_2 , struct V_3 * * * V_4 )
{
T_1 V_5 = V_6 . V_5 ;
* V_4 = V_6 . V_7 ;
if ( ! * V_4 )
return - V_8 ;
return F_2 ( V_2 , V_9 , * V_4 , V_5 , V_10 ) ;
}
int F_3 ( void )
{
int V_11 ;
V_11 = F_4 ( & V_6 ,
V_12 ) ;
if ( V_11 ) {
F_5 ( L_1 ) ;
return V_11 ;
}
return 0 ;
}
void F_6 ( void )
{
F_7 ( & V_6 ) ;
}
