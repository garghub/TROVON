static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 = V_4 -> V_6 ;
return F_3 ( V_4 -> V_7 , V_2 -> V_8 -> V_9 ,
V_6 -> V_10 , V_6 -> V_11 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 = V_4 -> V_6 ;
int V_12 ;
F_5 ( V_4 -> V_7 , V_2 -> V_8 -> V_9 , & V_12 ) ;
return ( V_12 & V_6 -> V_10 ) == V_6 -> V_11 ;
}
static int F_6 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 . V_18 ;
struct V_3 * V_19 ;
struct V_20 * V_21 ;
struct V_22 V_23 = { } ;
struct V_24 * V_7 ;
const struct V_5 * V_6 ;
int V_25 = 0 ;
int V_26 , V_27 , V_28 = 0 ;
V_26 = F_7 ( & V_14 -> V_17 , V_16 , V_29 ,
V_30 ) ;
if ( V_26 < 0 )
return V_26 ;
V_19 = F_8 ( & V_14 -> V_17 , sizeof( struct V_3 )
* V_26 , V_31 ) ;
if ( V_19 == NULL ) {
F_9 ( & V_14 -> V_17 , L_1 ) ;
return - V_32 ;
}
V_7 = F_10 ( V_16 , L_2 ) ;
if ( F_11 ( V_7 ) )
return F_12 ( V_7 ) ;
V_23 . V_24 = V_7 ;
V_23 . V_17 = & V_14 -> V_17 ;
for ( V_27 = 0 ; V_27 < V_30 && V_28 < V_26 ; V_27 ++ ) {
if ( ! V_29 [ V_27 ] . V_33 ||
! V_29 [ V_27 ] . V_18 )
continue;
V_6 = V_29 [ V_27 ] . V_34 ;
if ( ! V_6 )
return - V_35 ;
V_21 = F_13 ( V_14 , V_36 , 0 ) ;
if ( ! V_21 )
return - V_37 ;
V_19 [ V_28 ] . V_7 = V_7 ;
V_19 [ V_28 ] . V_6 = V_6 ;
V_19 [ V_28 ] . V_8 . V_38 = V_6 -> V_38 ;
V_19 [ V_28 ] . V_8 . V_39 = V_40 ;
V_19 [ V_28 ] . V_8 . type = V_41 ;
V_19 [ V_28 ] . V_8 . V_42 = & V_43 ;
V_19 [ V_28 ] . V_8 . V_44 = V_45 ;
V_19 [ V_28 ] . V_8 . V_46 = 2 ;
V_19 [ V_28 ] . V_8 . V_47 = V_6 -> V_47 ;
V_19 [ V_28 ] . V_8 . V_48 = V_21 -> V_49 ;
V_19 [ V_28 ] . V_8 . V_50 = V_6 -> V_51 ;
V_19 [ V_28 ] . V_8 . V_9 = V_21 -> V_49 ;
V_19 [ V_28 ] . V_8 . V_10 = V_6 -> V_10 ;
V_23 . V_33 = V_29 [ V_27 ] . V_33 ;
V_23 . V_34 = & V_19 [ V_28 ] ;
V_23 . V_18 = V_29 [ V_27 ] . V_18 ;
V_19 [ V_28 ] . V_17 = F_14 ( & V_14 -> V_17 ,
& V_19 [ V_28 ] . V_8 , & V_23 ) ;
if ( F_11 ( V_19 [ V_28 ] . V_17 ) ) {
V_25 = F_12 ( V_19 [ V_28 ] . V_17 ) ;
F_9 ( & V_14 -> V_17 ,
L_3 , V_25 ) ;
goto V_52;
}
V_28 ++ ;
}
F_15 ( V_14 , V_19 ) ;
V_52:
return V_25 ;
}
