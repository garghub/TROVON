int T_1 F_1 ( struct V_1 const * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( sizeof( * V_5 ) * V_3 , V_6 ) ;
if ( ! V_5 )
return - V_7 ;
for (; V_3 ; V_3 -- , V_2 ++ , V_5 ++ ) {
V_5 -> V_2 = * V_2 ;
F_3 ( & V_5 -> V_8 , & V_9 ) ;
}
return 0 ;
}
