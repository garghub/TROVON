static int F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_3 ;
int V_10 , V_11 ;
V_10 = V_5 -> V_12 . V_13 . V_14 ;
V_11 = V_5 -> V_12 . V_13 . V_15 ;
F_3 ( L_1 , V_10 , V_11 ) ;
V_10 = V_10 * 0xfe / 0xffff ;
V_11 = V_11 * 0xfe / 0xffff ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 0 ] = 0x51 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 1 ] = 0x0 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 2 ] = V_11 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 3 ] = 0 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 4 ] = V_10 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 5 ] = 0 ;
F_3 ( L_2 , V_10 , V_11 ) ;
F_4 ( V_7 , V_9 -> V_16 , V_19 ) ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 0 ] = 0xfa ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 1 ] = 0xfe ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 2 ] = 0x0 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 4 ] = 0x0 ;
F_4 ( V_7 , V_9 -> V_16 , V_19 ) ;
return 0 ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_20 * V_16 ;
struct V_21 * V_22 = F_6 ( V_7 -> V_23 . V_24 ,
struct V_21 , V_25 ) ;
struct V_26 * V_27 =
& V_7 -> V_28 [ V_29 ] . V_27 ;
struct V_26 * V_30 = V_27 ;
struct V_1 * V_2 = V_22 -> V_31 ;
int error ;
if ( F_7 ( V_27 ) ) {
F_8 ( V_7 , L_3 ) ;
return - V_32 ;
}
V_30 = V_30 -> V_24 ;
V_16 = F_6 ( V_30 , struct V_20 , V_25 ) ;
if ( V_16 -> V_33 < 1 ) {
F_8 ( V_7 , L_4 ) ;
return - V_32 ;
}
if ( V_16 -> V_17 [ 0 ] -> V_34 < 6 ) {
F_8 ( V_7 , L_5 ) ;
return - V_32 ;
}
V_9 = F_9 ( sizeof( struct V_8 ) , V_35 ) ;
if ( ! V_9 )
return - V_36 ;
F_10 ( V_37 , V_2 -> V_38 ) ;
error = F_11 ( V_2 , V_9 , F_1 ) ;
if ( error ) {
F_12 ( V_9 ) ;
return error ;
}
V_9 -> V_16 = V_16 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 0 ] = 0x51 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 1 ] = 0x00 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 2 ] = 0x00 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 3 ] = 0x00 ;
F_4 ( V_7 , V_9 -> V_16 , V_19 ) ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 0 ] = 0xfa ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 1 ] = 0xfe ;
F_4 ( V_7 , V_9 -> V_16 , V_19 ) ;
F_13 ( V_7 , L_6 ) ;
return 0 ;
}
static inline int F_5 ( struct V_6 * V_39 )
{
return 0 ;
}
static int F_14 ( struct V_6 * V_39 , const struct V_40 * V_41 )
{
int V_42 ;
F_15 ( & V_39 -> V_2 , L_7 ) ;
V_42 = F_16 ( V_39 ) ;
if ( V_42 ) {
F_8 ( V_39 , L_8 ) ;
goto V_43;
}
V_42 = F_17 ( V_39 , V_44 & ~ V_45 ) ;
if ( V_42 ) {
F_8 ( V_39 , L_9 ) ;
goto V_43;
}
F_5 ( V_39 ) ;
return 0 ;
V_43:
return V_42 ;
}
static int T_1 F_18 ( void )
{
return F_19 ( & V_46 ) ;
}
static void T_2 F_20 ( void )
{
F_21 ( & V_46 ) ;
}
