static T_1 F_1 ( int V_1 , void * V_2 )
{
if ( F_2 ( V_2 ) )
F_3 () ;
return V_3 ;
}
int F_4 ( struct V_4 * V_5 , int V_1 )
{
int V_6 ;
if ( ! V_1 ) {
V_5 -> V_7 = 0 ;
return 0 ;
}
V_6 = F_5 ( V_1 , F_1 , 0 ,
L_1 , V_5 ) ;
if ( ! V_6 )
V_5 -> V_7 = 1 ;
return V_6 ;
}
void F_6 ( struct V_4 * V_5 , int V_1 )
{
if ( ! V_5 -> V_7 )
return;
F_7 ( V_1 , V_5 ) ;
V_5 -> V_7 = 0 ;
}
void F_8 ( struct V_4 * V_5 , int V_1 )
{
F_6 ( V_5 , V_1 ) ;
}
