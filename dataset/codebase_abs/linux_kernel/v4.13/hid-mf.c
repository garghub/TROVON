static int F_1 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_3 ;
int V_10 , V_11 ;
V_10 = V_5 -> V_12 . V_13 . V_14 ;
V_11 = V_5 -> V_12 . V_13 . V_15 ;
F_3 ( L_1 , V_10 , V_11 ) ;
V_10 = V_10 * 0xff / 0xffff ;
V_11 = V_11 * 0xff / 0xffff ;
F_3 ( L_2 , V_10 , V_11 ) ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 0 ] = V_11 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 1 ] = V_10 ;
F_4 ( V_7 , V_9 -> V_16 , V_19 ) ;
return 0 ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_20 * V_21 =
& V_7 -> V_22 [ V_23 ] . V_21 ;
struct V_20 * V_24 ;
struct V_25 * V_16 ;
struct V_20 * V_26 = & V_7 -> V_27 ;
struct V_28 * V_29 ;
struct V_1 * V_2 ;
int error ;
F_6 (report_ptr, report_list) {
V_16 = F_7 ( V_24 , struct V_25 , V_30 ) ;
if ( V_16 -> V_31 < 1 || V_16 -> V_17 [ 0 ] -> V_32 < 2 ) {
F_8 ( V_7 , L_3 ) ;
return - V_33 ;
}
if ( F_9 ( V_26 , & V_7 -> V_27 ) ) {
F_8 ( V_7 , L_4 ) ;
return - V_33 ;
}
V_26 = V_26 -> V_34 ;
V_29 = F_7 ( V_26 , struct V_28 , V_30 ) ;
V_9 = F_10 ( sizeof( struct V_8 ) , V_35 ) ;
if ( ! V_9 )
return - V_36 ;
V_2 = V_29 -> V_29 ;
F_11 ( V_37 , V_2 -> V_38 ) ;
error = F_12 ( V_2 , V_9 , F_1 ) ;
if ( error ) {
F_13 ( V_9 ) ;
return error ;
}
V_9 -> V_16 = V_16 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 0 ] = 0x00 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 1 ] = 0x00 ;
F_4 ( V_7 , V_9 -> V_16 , V_19 ) ;
}
F_14 ( V_7 , L_5
L_6 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 , const struct V_39 * V_40 )
{
int error ;
F_16 ( & V_7 -> V_2 , L_7 ) ;
V_7 -> V_41 |= V_40 -> V_42 ;
error = F_17 ( V_7 ) ;
if ( error ) {
F_8 ( V_7 , L_8 ) ;
return error ;
}
error = F_18 ( V_7 , V_43 & ~ V_44 ) ;
if ( error ) {
F_8 ( V_7 , L_9 ) ;
return error ;
}
error = F_5 ( V_7 ) ;
if ( error ) {
F_8 ( V_7 , L_10 ) ;
F_19 ( V_7 ) ;
return error ;
}
return 0 ;
}
