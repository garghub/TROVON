static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_4 . V_5 ) ;
struct V_6 V_7 = { } ;
struct V_8 * V_9 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
V_7 . V_4 = V_2 -> V_4 . V_5 ;
V_7 . V_12 = V_3 -> V_12 ;
V_9 = F_3 ( & V_2 -> V_4 ,
& V_13 [ V_10 ] ,
& V_7 ) ;
if ( F_4 ( V_9 ) ) {
F_5 ( & V_2 -> V_4 , L_1 ,
V_13 [ V_10 ] . V_14 ) ;
return F_6 ( V_9 ) ;
}
}
return 0 ;
}
