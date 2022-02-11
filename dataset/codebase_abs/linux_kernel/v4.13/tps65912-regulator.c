static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
struct V_7 V_8 = { } ;
struct V_9 * V_10 ;
int V_11 ;
F_3 ( V_2 , V_4 ) ;
V_8 . V_5 = & V_2 -> V_5 ;
V_8 . V_12 = V_4 ;
V_8 . V_5 -> V_13 = V_4 -> V_5 -> V_13 ;
V_8 . V_14 = V_4 -> V_14 ;
for ( V_11 = 0 ; V_11 < F_4 ( V_15 ) ; V_11 ++ ) {
V_10 = F_5 ( & V_2 -> V_5 , & V_15 [ V_11 ] ,
& V_8 ) ;
if ( F_6 ( V_10 ) ) {
F_7 ( V_4 -> V_5 , L_1 ,
V_2 -> V_16 ) ;
return F_8 ( V_10 ) ;
}
}
return 0 ;
}
