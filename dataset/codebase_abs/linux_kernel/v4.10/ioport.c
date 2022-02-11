void T_1 * F_1 ( unsigned long V_1 , unsigned int V_2 )
{
if ( V_3 . V_4 )
return V_3 . V_4 ( V_1 , V_2 ) ;
return ( void T_1 * ) ( V_1 + V_5 ) ;
}
void T_1 * F_2 ( unsigned long V_6 , unsigned int V_7 )
{
void T_1 * V_8 ;
V_8 = F_3 ( V_6 , V_7 ) ;
if ( V_8 )
return V_8 ;
return F_1 ( V_6 , V_7 ) ;
}
void F_4 ( void T_1 * V_1 )
{
if ( V_3 . V_9 )
V_3 . V_9 ( V_1 ) ;
}
