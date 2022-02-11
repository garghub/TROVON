static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_4 = F_2 ( & V_2 -> V_6 , sizeof( * V_4 ) , V_7 ) ;
if ( ! V_4 )
return - V_8 ;
V_4 -> V_6 = & V_2 -> V_6 ;
F_3 ( V_2 , V_4 ) ;
V_4 -> V_9 = F_4 ( V_2 , & V_10 ) ;
if ( F_5 ( V_4 -> V_9 ) ) {
V_5 = F_6 ( V_4 -> V_9 ) ;
F_7 ( V_4 -> V_6 , L_1 , V_5 ) ;
return V_5 ;
}
V_5 = F_8 ( V_4 -> V_6 , V_11 , V_12 ,
F_9 ( V_12 ) , NULL , 0 , NULL ) ;
if ( V_5 ) {
F_7 ( V_4 -> V_6 , L_2 , V_5 ) ;
return V_5 ;
}
return 0 ;
}
