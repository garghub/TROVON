static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
V_6 = F_2 ( & V_2 -> V_8 , sizeof( * V_6 ) , V_9 ) ;
if ( ! V_6 )
return - V_10 ;
V_6 -> V_11 = F_3 ( V_2 , 0 , 0 ) ;
if ( ! V_6 -> V_11 ) {
F_4 ( & V_2 -> V_8 ,
L_1 ) ;
return - V_10 ;
}
F_5 ( V_12 | V_13 ,
V_6 -> V_11 ) ;
F_6 ( V_2 , V_6 ) ;
V_7 = F_7 ( V_2 , 1 ) ;
if ( V_7 != 0 ) {
F_5 ( 0 , V_6 -> V_11 ) ;
F_4 ( & V_2 -> V_8 ,
L_2 ,
V_7 ) ;
return V_7 ;
}
return 0 ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
F_5 ( 0 , V_6 -> V_11 ) ;
}
