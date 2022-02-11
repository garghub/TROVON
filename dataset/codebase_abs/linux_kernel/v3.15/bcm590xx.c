static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_5 ;
int V_6 ;
V_5 = F_2 ( & V_2 -> V_7 , sizeof( * V_5 ) , V_8 ) ;
if ( ! V_5 )
return - V_9 ;
F_3 ( V_2 , V_5 ) ;
V_5 -> V_7 = & V_2 -> V_7 ;
V_5 -> V_1 = V_2 ;
V_5 -> V_10 = F_4 ( V_2 , & V_11 ) ;
if ( F_5 ( V_5 -> V_10 ) ) {
V_6 = F_6 ( V_5 -> V_10 ) ;
F_7 ( & V_2 -> V_7 , L_1 , V_6 ) ;
return V_6 ;
}
V_6 = F_8 ( & V_2 -> V_7 , - 1 , V_12 ,
F_9 ( V_12 ) , NULL , 0 , NULL ) ;
if ( V_6 < 0 )
F_7 ( & V_2 -> V_7 , L_2 , V_6 ) ;
return V_6 ;
}
