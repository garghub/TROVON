static int F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_3 ;
T_1 V_10 , V_11 ;
V_10 = V_5 -> V_12 . V_13 . V_14 ;
V_11 = V_5 -> V_12 . V_13 . V_15 ;
F_3 ( & V_2 -> V_2 , L_1 , V_10 , V_11 ) ;
V_10 = V_10 * 0xff / 0xffff ;
V_11 = ( V_11 != 0 ) ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 1 ] = V_11 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 2 ] = V_10 ;
F_3 ( & V_2 -> V_2 , L_2 , V_10 , V_11 ) ;
F_4 ( V_7 , V_9 -> V_16 , V_19 ) ;
return 0 ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_20 * V_16 ;
struct V_21 * V_22 ;
struct V_23 * V_24 =
& V_7 -> V_25 [ V_26 ] . V_24 ;
struct V_23 * V_27 = V_24 ;
struct V_1 * V_2 ;
int error ;
if ( F_6 ( V_24 ) ) {
F_7 ( V_7 , L_3 ) ;
return - V_28 ;
}
F_8 (hidinput, &hid->inputs, list) {
V_27 = V_27 -> V_29 ;
if ( V_27 == V_24 ) {
F_7 ( V_7 , L_4 ) ;
return - V_28 ;
}
V_16 = F_9 ( V_27 , struct V_20 , V_30 ) ;
if ( V_16 -> V_31 < 1 ) {
F_7 ( V_7 , L_5 ) ;
return - V_28 ;
}
if ( V_16 -> V_17 [ 0 ] -> V_32 < 3 ) {
F_7 ( V_7 , L_6 ) ;
return - V_28 ;
}
V_9 = F_10 ( sizeof( struct V_8 ) , V_33 ) ;
if ( ! V_9 )
return - V_34 ;
V_2 = V_22 -> V_35 ;
F_11 ( V_36 , V_2 -> V_37 ) ;
error = F_12 ( V_2 , V_9 , F_1 ) ;
if ( error ) {
F_13 ( V_9 ) ;
return error ;
}
V_9 -> V_16 = V_16 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 0 ] = 0x01 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 1 ] = 0x00 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 2 ] = 0x00 ;
F_4 ( V_7 , V_9 -> V_16 , V_19 ) ;
}
F_14 ( V_7 , L_7 ) ;
return 0 ;
}
static inline int F_5 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_15 ( struct V_6 * V_38 , const struct V_39 * V_40 )
{
int V_41 ;
V_38 -> V_42 |= V_40 -> V_43 ;
V_41 = F_16 ( V_38 ) ;
if ( V_41 ) {
F_7 ( V_38 , L_8 ) ;
goto V_44;
}
V_41 = F_17 ( V_38 , V_45 & ~ V_46 ) ;
if ( V_41 ) {
F_7 ( V_38 , L_9 ) ;
goto V_44;
}
F_5 ( V_38 ) ;
return 0 ;
V_44:
return V_41 ;
}
static int T_2 F_18 ( void )
{
return F_19 ( & V_47 ) ;
}
static void T_3 F_20 ( void )
{
F_21 ( & V_47 ) ;
}
