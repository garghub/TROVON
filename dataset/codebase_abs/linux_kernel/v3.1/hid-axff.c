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
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 0 ] = V_10 ;
V_9 -> V_16 -> V_17 [ 1 ] -> V_18 [ 0 ] = V_11 ;
V_9 -> V_16 -> V_17 [ 2 ] -> V_18 [ 0 ] = V_10 ;
V_9 -> V_16 -> V_17 [ 3 ] -> V_18 [ 0 ] = V_11 ;
F_3 ( L_2 , V_10 , V_11 ) ;
F_4 ( V_7 , V_9 -> V_16 , V_19 ) ;
return 0 ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_20 * V_16 ;
struct V_21 * V_22 = F_6 ( & V_7 -> V_23 , struct V_21 , V_24 ) ;
struct V_25 * V_26 = & V_7 -> V_27 [ V_28 ] . V_26 ;
struct V_1 * V_2 = V_22 -> V_29 ;
int error ;
if ( F_7 ( V_26 ) ) {
F_8 ( V_7 , L_3 ) ;
return - V_30 ;
}
V_16 = F_6 ( V_26 , struct V_20 , V_24 ) ;
if ( V_16 -> V_31 < 4 ) {
F_8 ( V_7 , L_4 , V_16 -> V_31 ) ;
return - V_30 ;
}
V_9 = F_9 ( sizeof( struct V_8 ) , V_32 ) ;
if ( ! V_9 )
return - V_33 ;
F_10 ( V_34 , V_2 -> V_35 ) ;
error = F_11 ( V_2 , V_9 , F_1 ) ;
if ( error )
goto V_36;
V_9 -> V_16 = V_16 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 0 ] = 0x00 ;
V_9 -> V_16 -> V_17 [ 1 ] -> V_18 [ 0 ] = 0x00 ;
V_9 -> V_16 -> V_17 [ 2 ] -> V_18 [ 0 ] = 0x00 ;
V_9 -> V_16 -> V_17 [ 3 ] -> V_18 [ 0 ] = 0x00 ;
F_4 ( V_7 , V_9 -> V_16 , V_19 ) ;
F_12 ( V_7 , L_5 ) ;
return 0 ;
V_36:
F_13 ( V_9 ) ;
return error ;
}
static inline int F_5 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_14 ( struct V_6 * V_37 , const struct V_38 * V_39 )
{
int error ;
F_15 ( & V_37 -> V_2 , L_6 ) ;
error = F_16 ( V_37 ) ;
if ( error ) {
F_8 ( V_37 , L_7 ) ;
return error ;
}
error = F_17 ( V_37 , V_40 & ~ V_41 ) ;
if ( error ) {
F_8 ( V_37 , L_8 ) ;
return error ;
}
error = F_5 ( V_37 ) ;
if ( error ) {
F_18 ( V_37 ,
L_9 ,
error ) ;
}
error = F_19 ( V_37 ) ;
if ( error ) {
F_20 ( & V_37 -> V_2 , L_10 ) ;
F_21 ( V_37 ) ;
return error ;
}
return 0 ;
}
static void F_22 ( struct V_6 * V_37 )
{
F_23 ( V_37 ) ;
F_21 ( V_37 ) ;
}
static int T_1 F_24 ( void )
{
return F_25 ( & V_42 ) ;
}
static void T_2 F_26 ( void )
{
F_27 ( & V_42 ) ;
}
