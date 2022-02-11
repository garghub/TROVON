int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 ;
int V_8 ;
V_7 = F_2 ( V_2 ) ;
if ( ! V_7 ) {
F_3 ( L_1 , F_4 ( V_2 ) ) ;
return - V_9 ;
}
if ( V_5 == V_10 )
V_5 = V_7 -> V_11 ;
V_8 = F_5 ( V_7 , V_4 , V_5 ) ;
F_6 ( V_7 ) ;
return V_8 ;
}
