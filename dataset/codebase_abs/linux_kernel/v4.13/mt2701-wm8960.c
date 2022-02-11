static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
unsigned int V_11 ;
unsigned int V_12 = F_2 ( V_4 ) ;
unsigned int V_13 = V_12 > 192000 ? 2 : 4 ;
unsigned int V_14 = 64 ;
V_11 = V_12 * V_14 * V_13 ;
F_3 ( V_10 , 0 , V_11 , V_15 ) ;
F_3 ( V_9 , 0 , V_11 , V_16 ) ;
return 0 ;
}
static int F_4 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_21 ;
struct V_22 * V_23 , * V_24 ;
int V_25 , V_26 ;
V_23 = F_5 ( V_18 -> V_27 . V_28 ,
L_1 , 0 ) ;
if ( ! V_23 ) {
F_6 ( & V_18 -> V_27 , L_2 ) ;
return - V_29 ;
}
for ( V_26 = 0 ; V_26 < V_20 -> V_30 ; V_26 ++ ) {
if ( V_31 [ V_26 ] . V_32 )
continue;
V_31 [ V_26 ] . V_33 = V_23 ;
}
V_20 -> V_27 = & V_18 -> V_27 ;
V_24 = F_5 ( V_18 -> V_27 . V_28 ,
L_3 , 0 ) ;
if ( ! V_24 ) {
F_6 ( & V_18 -> V_27 ,
L_4 ) ;
return - V_29 ;
}
for ( V_26 = 0 ; V_26 < V_20 -> V_30 ; V_26 ++ ) {
if ( V_31 [ V_26 ] . V_34 )
continue;
V_31 [ V_26 ] . V_35 = V_24 ;
}
V_25 = F_7 ( V_20 , L_5 ) ;
if ( V_25 ) {
F_6 ( & V_18 -> V_27 , L_6 , V_25 ) ;
return V_25 ;
}
V_25 = F_8 ( & V_18 -> V_27 , V_20 ) ;
if ( V_25 )
F_6 ( & V_18 -> V_27 , L_7 ,
V_36 , V_25 ) ;
return V_25 ;
}
