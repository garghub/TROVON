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
if ( V_7 <= 0 )
return V_7 ;
V_6 -> V_14 = F_6 ( V_2 ,
sizeof( struct V_10 ) *
F_5 ( V_13 ) , V_15 ) ;
if ( ! V_6 -> V_14 ) {
F_3 ( V_2 , L_3 ,
V_16 ) ;
return - V_17 ;
}
V_6 -> V_18 = V_7 ;
V_11 = V_6 -> V_14 ;
for ( V_8 = 0 ; V_8 < F_5 ( V_13 ) ; V_8 ++ ) {
V_11 -> V_19 = V_8 ;
V_11 -> V_20 = V_13 [ V_8 ] . V_20 ;
V_11 -> V_21 = V_13 [ V_8 ] . V_22 ;
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
static int F_7 ( struct V_23 * V_24 ,
const struct V_25 * V_26 )
{
struct V_27 * * V_28 ;
struct V_1 * V_2 = & V_24 -> V_2 ;
struct V_5 * V_6 = F_8 ( V_2 ) ;
struct V_29 V_30 = { } ;
struct V_31 * V_31 ;
struct V_3 * V_4 [ V_32 ] ;
int V_8 , V_19 ;
int V_33 = - V_12 ;
int error ;
if ( V_2 -> V_4 && ! V_6 ) {
const struct V_34 * V_19 ;
struct V_5 V_35 ;
V_19 = F_9 ( F_10 ( V_36 ) , V_2 ) ;
if ( ! V_19 )
return - V_37 ;
V_33 = F_1 ( V_2 , V_4 , & V_35 ) ;
if ( V_33 < 0 )
return V_33 ;
V_6 = & V_35 ;
}
if ( V_6 -> V_18 > V_32 ) {
F_3 ( V_2 , L_4 ) ;
return - V_12 ;
}
V_31 = F_6 ( V_2 , sizeof( struct V_31 ) , V_15 ) ;
if ( ! V_31 )
return - V_17 ;
V_28 = V_31 -> V_28 ;
V_31 -> V_38 = F_11 ( V_24 , & V_39 ) ;
if ( F_12 ( V_31 -> V_38 ) ) {
error = F_13 ( V_31 -> V_38 ) ;
F_3 ( & V_24 -> V_2 , L_5 ,
error ) ;
return error ;
}
for ( V_8 = 0 ; V_8 < V_32 ; V_8 ++ ) {
V_19 = V_6 -> V_14 [ V_8 ] . V_19 ;
V_30 . V_2 = V_2 ;
V_30 . V_22 = V_6 -> V_14 [ V_8 ] . V_21 ;
V_30 . V_4 = V_4 [ V_8 ] ;
V_30 . V_40 = V_31 ;
V_30 . V_38 = V_31 -> V_38 ;
V_28 [ V_8 ] = F_14 ( & V_24 -> V_2 ,
& V_41 [ V_8 ] , & V_30 ) ;
if ( F_12 ( V_28 [ V_8 ] ) ) {
F_3 ( V_2 , L_6 ,
V_41 [ V_19 ] . V_20 ) ;
return F_13 ( V_28 [ V_8 ] ) ;
}
}
F_15 ( V_24 , V_31 ) ;
return 0 ;
}
