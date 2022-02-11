static void
F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 ) {
F_2 ( & V_2 -> V_4 ,
L_1 ) ;
return;
}
F_3 ( V_2 -> V_3 ) ;
}
int
F_4 ( struct V_5 * V_6 , int V_7 , struct V_1 * * V_8 )
{
int V_9 ;
V_9 = F_5 ( & V_10 , V_6 , V_7 , V_8 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
