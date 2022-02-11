int F_1 ( const struct V_1 * V_1 ,
const struct V_2 * V_3 )
{
const struct V_4 * V_5 ;
int V_6 ;
F_2 ( L_1 , V_7 ) ;
if ( V_1 -> type != & V_8 )
return - V_9 ;
V_5 = V_4 ( V_1 ) ;
if ( ! V_5 ||
! V_1 -> V_10 . V_11 )
return - V_9 ;
if ( ! V_5 -> F_1 )
return - V_12 ;
V_6 = V_5 -> F_1 ( V_1 , V_3 ) ;
F_2 ( L_2 , V_7 , V_6 ) ;
return V_6 ;
}
