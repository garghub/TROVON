static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 [ 0 ] . V_4 ;
struct V_3 * V_6 = V_2 -> V_5 [ 0 ] . V_6 ;
int V_7 ;
V_7 = F_2 ( V_4 , 0 ,
V_8 , V_9 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_2 ( V_6 , V_10 ,
0 , V_9 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_3 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_13 ;
struct V_14 * V_15 , * V_16 ;
int V_17 , V_7 ;
V_15 = F_4 ( V_12 -> V_18 . V_19 ,
L_1 , 0 ) ;
if ( ! V_15 ) {
F_5 ( & V_12 -> V_18 ,
L_2 ) ;
return - V_20 ;
}
V_16 = F_4 ( V_12 -> V_18 . V_19 ,
L_3 , 0 ) ;
if ( ! V_16 ) {
F_5 ( & V_12 -> V_18 ,
L_4 ) ;
return - V_20 ;
}
for ( V_17 = 0 ; V_17 < F_6 ( V_21 ) ; V_17 ++ ) {
V_21 [ V_17 ] . V_22 = V_16 ;
V_21 [ V_17 ] . V_23 = V_15 ;
V_21 [ V_17 ] . V_24 = V_15 ;
}
V_2 -> V_18 = & V_12 -> V_18 ;
F_7 ( V_2 , L_5 ) ;
V_7 = F_8 ( & V_12 -> V_18 , V_2 ) ;
if ( V_7 ) {
F_5 ( & V_12 -> V_18 , L_6 , V_7 ) ;
return V_7 ;
}
return V_7 ;
}
