static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
int V_6 ;
V_4 = F_2 ( V_2 -> V_7 . V_8 -> V_9 ) ;
if ( ! V_4 )
return 0 ;
V_5 = F_3 ( V_4 , L_1 ) ;
if ( ! V_5 ) {
F_4 ( & V_2 -> V_7 , L_2 ) ;
return - V_10 ;
}
V_6 = F_5 ( & V_2 -> V_7 , V_5 , V_11 ,
F_6 ( V_11 ) ) ;
F_7 ( V_5 ) ;
if ( V_6 < 0 ) {
F_4 ( & V_2 -> V_7 , L_3 ,
V_6 ) ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_12 * V_12 = F_9 ( V_2 -> V_7 . V_8 ) ;
struct V_13 V_14 = { } ;
struct V_15 * V_16 ;
int V_6 , V_17 ;
V_6 = F_1 ( V_2 ) ;
if ( V_6 )
return V_6 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
V_14 . V_7 = & V_2 -> V_7 ;
V_14 . V_19 = V_11 [ V_17 ] . V_19 ;
V_14 . V_9 = V_11 [ V_17 ] . V_9 ;
V_14 . V_20 = V_12 -> V_20 ;
V_16 = F_10 ( & V_2 -> V_7 ,
& V_21 [ V_17 ] ,
& V_14 ) ;
if ( F_11 ( V_16 ) ) {
F_4 ( & V_2 -> V_7 , L_4 ,
V_21 [ V_17 ] . V_22 ) ;
return F_12 ( V_16 ) ;
}
}
return 0 ;
}
