bool F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
return F_2 ( V_4 , V_2 , V_3 ) ;
}
bool F_3 ( struct V_1 * V_2 , unsigned long V_3 )
{
return F_4 ( V_4 , V_2 , V_3 ) ;
}
bool F_5 ( struct V_1 * V_2 )
{
bool V_5 ;
V_5 = F_6 ( V_2 ) ;
F_7 ( V_4 ) ;
return V_5 ;
}
int F_8 ( void )
{
V_4 = F_9 ( L_1 , V_6 ) ;
if ( ! V_4 )
return - V_7 ;
else
return 0 ;
}
void F_10 ( void )
{
F_7 ( V_4 ) ;
F_11 ( V_4 ) ;
V_4 = NULL ;
}
