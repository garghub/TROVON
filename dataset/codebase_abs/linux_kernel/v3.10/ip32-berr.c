static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = V_2 -> V_5 & 4 ;
if ( V_3 )
return V_6 ;
F_2 ( L_1 , V_4 ? 'd' : 'i' , V_2 -> V_7 ) ;
F_3 ( V_2 ) ;
F_4 () ;
while( 1 ) ;
F_5 ( V_8 , V_9 ) ;
}
void T_1 F_6 ( void )
{
V_10 = F_1 ;
}
