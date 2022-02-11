static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 , V_12 ;
unsigned long V_13 ;
V_11 = 256 ;
V_13 = F_2 ( V_4 ) * V_11 ;
V_12 = F_3 ( V_9 , V_14 ,
0 , V_15 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_3 ( V_9 , V_16 ,
0 , V_15 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_3 ( V_10 , 0 , V_13 , V_15 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static int F_4 ( struct V_17 * V_18 )
{
int V_19 , V_12 ;
struct V_20 * V_21 = V_18 -> V_22 . V_23 ;
struct V_24 * V_25 = & V_26 ;
V_25 -> V_22 = & V_18 -> V_22 ;
for ( V_19 = 0 ; V_21 && V_19 < F_5 ( V_27 ) ; V_19 ++ ) {
if ( ! V_27 [ V_19 ] . V_28 ) {
V_27 [ V_19 ] . V_29 = F_6 ( V_21 ,
L_1 , V_19 ) ;
if ( ! V_27 [ V_19 ] . V_29 ) {
F_7 ( & V_18 -> V_22 ,
L_2 ) ;
return - V_30 ;
}
}
if ( ! V_27 [ V_19 ] . V_31 )
V_27 [ V_19 ] . V_32 =
V_27 [ V_19 ] . V_29 ;
V_27 [ V_19 ] . V_33 = NULL ;
V_27 [ V_19 ] . V_34 = F_6 ( V_21 ,
L_3 , V_19 ) ;
if ( ! V_27 [ 0 ] . V_34 ) {
F_7 ( & V_18 -> V_22 ,
L_4 ) ;
return - V_30 ;
}
}
V_12 = F_8 ( V_25 -> V_22 , V_25 ) ;
if ( V_12 )
F_7 ( & V_18 -> V_22 , L_5 , V_12 ) ;
return V_12 ;
}
