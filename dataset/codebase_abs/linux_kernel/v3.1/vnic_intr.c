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
F_4 ( L_1 , V_6 ) ;
return - V_8 ;
}
return 0 ;
}
void F_5 ( struct V_1 * V_2 , T_1 V_9 ,
unsigned int V_10 , unsigned int V_11 )
{
F_6 ( V_2 , V_9 ) ;
F_7 ( V_10 , & V_2 -> V_3 -> V_10 ) ;
F_7 ( V_11 , & V_2 -> V_3 -> V_11 ) ;
F_7 ( 0 , & V_2 -> V_3 -> V_12 ) ;
}
void F_6 ( struct V_1 * V_2 ,
T_1 V_9 )
{
F_7 ( F_8 ( V_2 -> V_5 ,
V_9 ) , & V_2 -> V_3 -> V_9 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
F_7 ( 0 , & V_2 -> V_3 -> V_12 ) ;
}
