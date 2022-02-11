static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
int V_7 , V_8 ;
struct V_9 V_10 = {} ;
V_10 . V_5 = & V_2 -> V_5 ;
V_10 . V_11 = V_4 ;
for ( V_8 = 0 ; V_8 < F_3 ( V_12 ) ; V_8 ++ ) {
struct V_13 * V_14 ;
V_10 . V_15 = V_4 -> V_15 ;
V_14 = F_4 ( & V_2 -> V_5 ,
& V_12 [ V_8 ] , & V_10 ) ;
if ( F_5 ( V_14 ) ) {
V_7 = F_6 ( V_14 ) ;
F_7 ( & V_2 -> V_5 ,
L_1 ,
V_8 , V_7 ) ;
return V_7 ;
}
}
return 0 ;
}
