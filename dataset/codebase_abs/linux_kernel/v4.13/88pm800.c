static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static int F_3 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_4 ( V_7 -> V_10 . V_11 ) ;
struct V_12 * V_13 = F_5 ( V_7 -> V_10 . V_11 ) ;
struct V_14 * V_15 ;
struct V_16 V_17 = { } ;
struct V_18 * V_19 ;
int V_20 , V_21 ;
if ( V_13 && V_13 -> V_22 ) {
unsigned int V_23 = 0 ;
for ( V_20 = 0 ; V_20 < F_6 ( V_13 -> V_24 ) ; V_20 ++ ) {
if ( V_13 -> V_24 [ V_20 ] )
V_23 ++ ;
}
if ( V_23 != V_13 -> V_22 )
return - V_25 ;
}
V_15 = F_7 ( & V_7 -> V_10 , sizeof( * V_15 ) ,
V_26 ) ;
if ( ! V_15 )
return - V_27 ;
V_15 -> V_28 = V_9 -> V_29 -> V_30 ;
V_15 -> V_9 = V_9 ;
F_8 ( V_7 , V_15 ) ;
V_17 . V_10 = V_9 -> V_10 ;
V_17 . V_31 = V_15 -> V_28 ;
for ( V_20 = 0 ; V_20 < V_32 ; V_20 ++ ) {
struct V_1 * V_33 ;
if ( V_13 && V_13 -> V_22 ) {
V_19 = V_13 -> V_24 [ V_20 ] ;
if ( ! V_19 )
continue;
V_17 . V_19 = V_19 ;
}
V_17 . V_34 = & V_3 [ V_20 ] ;
V_33 = F_9 ( & V_7 -> V_10 ,
& V_3 [ V_20 ] . V_35 , & V_17 ) ;
if ( F_10 ( V_33 ) ) {
V_21 = F_11 ( V_33 ) ;
F_12 ( & V_7 -> V_10 , L_1 ,
V_3 [ V_20 ] . V_35 . V_36 ) ;
return V_21 ;
}
}
return 0 ;
}
