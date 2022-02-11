void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 ) {
for ( V_3 = 0 ; V_3 < F_2 ( V_2 -> V_4 ) ; V_3 ++ )
F_3 ( V_2 -> V_4 [ V_3 ] ) ;
F_3 ( V_2 -> V_5 ) ;
F_3 ( V_2 -> V_6 ) ;
F_3 ( V_2 ) ;
}
}
int F_4 ( const struct V_7 * V_7 ,
const struct V_1 * V_2 )
{
const struct V_8 * V_9 ;
int V_10 ;
F_5 ( L_1 , V_11 ) ;
if ( V_7 -> type != & V_12 )
return - V_13 ;
V_9 = V_8 ( V_7 ) ;
if ( ! V_9 ||
! V_7 -> V_14 . V_15 [ 0 ] )
return - V_13 ;
if ( ! V_9 -> F_4 )
return - V_16 ;
V_10 = V_9 -> F_4 ( V_7 , V_2 ) ;
F_5 ( L_2 , V_11 , V_10 ) ;
return V_10 ;
}
