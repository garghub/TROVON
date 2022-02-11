void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = NULL ;
}
int F_2 ( struct V_4 * V_5 , struct V_1 * V_2 ,
unsigned int V_6 )
{
V_2 -> V_6 = V_6 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_3 = F_3 ( V_5 , V_7 , V_6 ) ;
if ( ! V_2 -> V_3 ) {
F_4 ( V_8 L_1 ,
V_6 ) ;
return - V_9 ;
}
return 0 ;
}
void F_5 ( struct V_1 * V_2 , unsigned int V_10 ,
unsigned int V_11 , unsigned int V_12 )
{
F_6 ( V_10 , & V_2 -> V_3 -> V_10 ) ;
F_6 ( V_11 , & V_2 -> V_3 -> V_11 ) ;
F_6 ( V_12 , & V_2 -> V_3 -> V_12 ) ;
F_6 ( 0 , & V_2 -> V_3 -> V_13 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
F_6 ( 0 , & V_2 -> V_3 -> V_13 ) ;
}
