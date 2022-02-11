static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
return F_2 ( V_9 , 0 , F_3 ( V_4 ) * 256 ,
V_10 ) ;
}
static int F_4 ( struct V_5 * V_11 )
{
int V_12 ;
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_15 * V_16 = V_11 -> V_16 ;
V_12 = F_5 ( V_14 , L_1 , V_17 ,
& V_18 , NULL , 0 ) ;
if ( V_12 ) {
F_6 ( V_14 -> V_19 , L_2 , V_12 ) ;
return V_12 ;
}
V_12 = F_7 ( & V_18 ,
F_8 ( V_20 ) ,
V_20 ) ;
if ( V_12 ) {
F_6 ( V_14 -> V_19 , L_3 , V_12 ) ;
return V_12 ;
}
return F_9 ( V_16 , & V_18 ) ;
}
static int F_10 ( struct V_21 * V_22 )
{
struct V_13 * V_14 = & V_23 ;
struct V_24 * V_25 , * V_26 ;
int V_12 , V_27 ;
V_26 = F_11 ( V_22 -> V_19 . V_28 ,
L_4 , 0 ) ;
if ( ! V_26 ) {
F_6 ( & V_22 -> V_19 , L_5 ) ;
return - V_29 ;
}
for ( V_27 = 0 ; V_27 < V_14 -> V_30 ; V_27 ++ ) {
if ( V_31 [ V_27 ] . V_32 )
continue;
V_31 [ V_27 ] . V_33 = V_26 ;
}
V_25 = F_11 ( V_22 -> V_19 . V_28 ,
L_6 , 0 ) ;
if ( ! V_25 ) {
F_6 ( & V_22 -> V_19 ,
L_7 ) ;
return - V_29 ;
}
for ( V_27 = 0 ; V_27 < V_14 -> V_30 ; V_27 ++ ) {
if ( V_31 [ V_27 ] . V_34 )
continue;
V_31 [ V_27 ] . V_35 = V_25 ;
}
V_14 -> V_19 = & V_22 -> V_19 ;
V_12 = F_12 ( & V_22 -> V_19 , V_14 ) ;
if ( V_12 )
F_6 ( & V_22 -> V_19 , L_8 ,
V_36 , V_12 ) ;
return V_12 ;
}
