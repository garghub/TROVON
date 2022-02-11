static int F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_3 ;
T_1 V_10 , V_11 ;
V_10 = V_5 -> V_12 . V_13 . V_14 ;
V_11 = V_5 -> V_12 . V_13 . V_15 ;
V_9 -> V_16 -> V_17 [ 2 ] -> V_18 [ 0 ] = V_10 / 256 ;
V_9 -> V_16 -> V_17 [ 3 ] -> V_18 [ 0 ] = V_11 / 256 ;
F_3 ( V_7 , V_9 -> V_16 , V_19 ) ;
return 0 ;
}
static int F_4 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_20 * V_16 ;
struct V_21 * V_22 =
F_5 ( & V_7 -> V_23 , struct V_21 , V_24 ) ;
struct V_25 * V_26 =
& V_7 -> V_27 [ V_28 ] . V_26 ;
struct V_1 * V_2 = V_22 -> V_29 ;
int V_30 = 0 ;
int error ;
int V_31 , V_32 ;
if ( F_6 ( V_26 ) ) {
F_7 ( V_7 , L_1 ) ;
return - V_33 ;
}
V_16 = F_5 ( V_26 , struct V_20 , V_24 ) ;
for ( V_31 = 0 ; V_31 < V_16 -> V_34 ; V_31 ++ ) {
for ( V_32 = 0 ; V_32 < V_16 -> V_17 [ V_31 ] -> V_35 ; V_32 ++ ) {
V_16 -> V_17 [ V_31 ] -> V_18 [ V_32 ] = 0x00 ;
V_30 ++ ;
}
}
if ( V_30 < 4 ) {
F_7 ( V_7 , L_2 ,
V_30 ) ;
return - V_33 ;
}
V_9 = F_8 ( sizeof( * V_9 ) , V_36 ) ;
if ( ! V_9 )
return - V_37 ;
F_9 ( V_38 , V_2 -> V_39 ) ;
error = F_10 ( V_2 , V_9 , F_1 ) ;
if ( error ) {
F_11 ( V_9 ) ;
return error ;
}
V_9 -> V_16 = V_16 ;
F_3 ( V_7 , V_9 -> V_16 , V_19 ) ;
F_12 ( V_7 , L_3 ) ;
return 0 ;
}
static int F_13 ( struct V_6 * V_40 , const struct V_41 * V_42 )
{
int V_43 ;
if ( V_42 -> V_44 )
V_40 -> V_45 |= V_46 ;
V_43 = F_14 ( V_40 ) ;
if ( V_43 ) {
F_7 ( V_40 , L_4 ) ;
goto V_47;
}
V_43 = F_15 ( V_40 , V_48 & ~ V_49 ) ;
if ( V_43 ) {
F_7 ( V_40 , L_5 ) ;
goto V_47;
}
F_4 ( V_40 ) ;
return 0 ;
V_47:
return V_43 ;
}
