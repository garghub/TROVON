static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 V_6 = { } ;
struct V_7 * V_8 = V_2 -> V_9 . V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_13 ;
int V_14 , V_15 ;
V_13 = F_2 ( V_2 , & V_16 ) ;
if ( F_3 ( V_13 ) ) {
V_15 = F_4 ( V_13 ) ;
F_5 ( & V_2 -> V_9 , L_1 , V_15 ) ;
return V_15 ;
}
V_6 . V_9 = & V_2 -> V_9 ;
for ( V_14 = 0 ; V_14 < F_6 ( V_17 ) ; V_14 ++ ) {
if ( V_8 )
V_6 . V_18 = V_8 -> V_18 [ V_14 ] ;
else
V_6 . V_18 = NULL ;
V_12 = F_7 ( & V_2 -> V_9 ,
& V_17 [ V_14 ] ,
& V_6 ) ;
if ( F_3 ( V_12 ) ) {
V_15 = F_4 ( V_12 ) ;
F_5 ( & V_2 -> V_9 , L_2 ,
V_17 [ V_14 ] . V_19 , V_15 ) ;
return V_15 ;
}
}
return 0 ;
}
