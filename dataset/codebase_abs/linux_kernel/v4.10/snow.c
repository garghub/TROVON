static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_5 * V_7 ;
int V_8 ;
V_4 = F_2 ( V_2 , V_2 -> V_9 [ 0 ] . V_10 ) ;
V_6 = V_4 -> V_6 ;
V_7 = V_4 -> V_7 ;
V_8 = F_3 ( V_6 , 0 ,
V_11 , V_12 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_3 ( V_7 , V_13 ,
0 , V_12 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_4 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = & V_16 ;
struct V_17 * V_18 , * V_19 ;
int V_20 , V_8 ;
V_18 = F_5 ( V_15 -> V_21 . V_22 ,
L_1 , 0 ) ;
if ( ! V_18 ) {
F_6 ( & V_15 -> V_21 ,
L_2 ) ;
return - V_23 ;
}
V_19 = F_5 ( V_15 -> V_21 . V_22 ,
L_3 , 0 ) ;
if ( ! V_19 ) {
F_6 ( & V_15 -> V_21 ,
L_4 ) ;
return - V_23 ;
}
for ( V_20 = 0 ; V_20 < F_7 ( V_24 ) ; V_20 ++ ) {
V_24 [ V_20 ] . V_25 = V_19 ;
V_24 [ V_20 ] . V_26 = V_18 ;
V_24 [ V_20 ] . V_27 = V_18 ;
}
V_2 -> V_21 = & V_15 -> V_21 ;
F_8 ( V_2 , L_5 ) ;
V_8 = F_9 ( & V_15 -> V_21 , V_2 ) ;
if ( V_8 ) {
F_6 ( & V_15 -> V_21 , L_6 , V_8 ) ;
return V_8 ;
}
return V_8 ;
}
