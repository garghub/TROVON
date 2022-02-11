static int F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
if ( V_4 . V_5 )
return V_4 . V_5 ( F_2 ( V_1 ) ,
F_3 ( V_6 ) ) ;
return - V_7 ;
}
void T_1 F_4 ( unsigned int V_1 )
{
const struct V_8 V_9 = {
. type = V_10 ,
} ;
if ( V_4 . V_11 )
V_4 . V_11 ( V_9 ) ;
F_5 ( L_1 , V_1 ) ;
}
bool T_2 F_6 ( void )
{
return ( V_4 . V_5 != NULL ) ;
}
