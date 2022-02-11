int F_1 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = V_3 ;
int V_8 = 0 ;
F_2 ( & V_2 -> V_9 ) ;
if ( ! V_5 -> V_10 ) {
V_8 = F_3 ( & V_5 -> V_11 -> V_12 , V_5 ,
1 , 0 , V_13 ) ;
if ( V_8 >= 0 )
V_5 -> V_10 = V_8 ;
}
V_7 -> V_10 = V_5 -> V_10 ;
F_4 ( & V_2 -> V_9 ) ;
F_5 ( L_1 , V_7 -> V_10 ) ;
return V_8 < 0 ? V_8 : 0 ;
}
int F_6 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_3 ;
struct V_4 * V_14 ;
F_5 ( L_1 , V_7 -> V_10 ) ;
F_2 ( & V_2 -> V_9 ) ;
V_14 = F_7 ( & V_5 -> V_11 -> V_12 , V_7 -> V_10 ) ;
if ( V_14 ) {
V_14 -> V_15 = 1 ;
F_8 ( & V_5 -> V_11 -> V_12 , NULL , V_7 -> V_10 ) ;
}
F_4 ( & V_2 -> V_9 ) ;
return V_14 ? 0 : - V_16 ;
}
