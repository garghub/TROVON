int F_1 ( int V_1 , struct V_2 const * V_3 , unsigned V_4 )
{
int V_5 ;
F_2 ( & V_6 ) ;
if ( V_1 >= V_7 )
V_7 = V_1 + 1 ;
for ( V_5 = 0 ; V_4 ; V_4 -- , V_3 ++ ) {
struct V_8 * V_9 ;
V_9 = F_3 ( sizeof( * V_9 ) , V_10 ) ;
if ( ! V_9 ) {
F_4 ( L_1 ) ;
V_5 = - V_11 ;
break;
}
V_9 -> V_1 = V_1 ;
V_9 -> V_12 = * V_3 ;
F_5 ( & V_9 -> V_13 , & V_14 ) ;
}
F_6 ( & V_6 ) ;
return V_5 ;
}
