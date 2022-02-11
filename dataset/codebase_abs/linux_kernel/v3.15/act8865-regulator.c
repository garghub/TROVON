static int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
struct V_5 * V_6 )
{
int V_7 , V_8 ;
struct V_3 * V_9 ;
struct V_10 * V_11 ;
V_9 = F_2 ( V_2 -> V_4 , L_1 ) ;
if ( ! V_9 ) {
F_3 ( V_2 , L_2 ) ;
return - V_12 ;
}
V_7 = F_4 ( V_2 , V_9 ,
V_13 , F_5 ( V_13 ) ) ;
F_6 ( V_9 ) ;
if ( V_7 <= 0 )
return V_7 ;
V_6 -> V_14 = F_7 ( V_2 ,
sizeof( struct V_10 ) *
F_5 ( V_13 ) , V_15 ) ;
if ( ! V_6 -> V_14 )
return - V_16 ;
V_6 -> V_17 = V_7 ;
V_11 = V_6 -> V_14 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_13 ) ; V_8 ++ ) {
V_11 -> V_18 = V_8 ;
V_11 -> V_19 = V_13 [ V_8 ] . V_19 ;
V_11 -> V_20 = V_13 [ V_8 ] . V_21 ;
V_4 [ V_8 ] = V_13 [ V_8 ] . V_4 ;
V_11 ++ ;
}
return 0 ;
}
static inline int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
struct V_5 * V_6 )
{
return 0 ;
}
static int F_8 ( struct V_22 * V_23 ,
const struct V_24 * V_25 )
{
struct V_26 * V_27 ;
struct V_1 * V_2 = & V_23 -> V_2 ;
struct V_5 * V_6 = F_9 ( V_2 ) ;
struct V_28 V_29 = { } ;
struct V_30 * V_30 ;
struct V_3 * V_4 [ V_31 ] ;
int V_8 , V_18 ;
int V_32 = - V_12 ;
int error ;
if ( V_2 -> V_4 && ! V_6 ) {
const struct V_33 * V_18 ;
struct V_5 V_34 ;
V_18 = F_10 ( F_11 ( V_35 ) , V_2 ) ;
if ( ! V_18 )
return - V_36 ;
V_32 = F_1 ( V_2 , V_4 , & V_34 ) ;
if ( V_32 < 0 )
return V_32 ;
V_6 = & V_34 ;
}
if ( V_6 -> V_17 > V_31 ) {
F_3 ( V_2 , L_3 ) ;
return - V_12 ;
}
V_30 = F_7 ( V_2 , sizeof( struct V_30 ) , V_15 ) ;
if ( ! V_30 )
return - V_16 ;
V_30 -> V_37 = F_12 ( V_23 , & V_38 ) ;
if ( F_13 ( V_30 -> V_37 ) ) {
error = F_14 ( V_30 -> V_37 ) ;
F_3 ( & V_23 -> V_2 , L_4 ,
error ) ;
return error ;
}
for ( V_8 = 0 ; V_8 < V_31 ; V_8 ++ ) {
V_18 = V_6 -> V_14 [ V_8 ] . V_18 ;
V_29 . V_2 = V_2 ;
V_29 . V_21 = V_6 -> V_14 [ V_8 ] . V_20 ;
V_29 . V_4 = V_4 [ V_8 ] ;
V_29 . V_39 = V_30 ;
V_29 . V_37 = V_30 -> V_37 ;
V_27 = F_15 ( & V_23 -> V_2 , & V_40 [ V_8 ] ,
& V_29 ) ;
if ( F_13 ( V_27 ) ) {
F_3 ( V_2 , L_5 ,
V_40 [ V_18 ] . V_19 ) ;
return F_14 ( V_27 ) ;
}
}
F_16 ( V_23 , V_30 ) ;
return 0 ;
}
