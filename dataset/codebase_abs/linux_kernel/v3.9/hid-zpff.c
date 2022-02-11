static int F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_3 ;
int V_10 , V_11 ;
V_10 = V_5 -> V_12 . V_13 . V_14 ;
V_11 = V_5 -> V_12 . V_13 . V_15 ;
F_3 ( L_1 , V_10 , V_11 ) ;
V_10 = V_10 * 0x7f / 0xffff ;
V_11 = V_11 * 0x7f / 0xffff ;
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
struct V_21 * V_22 = F_6 ( V_7 -> V_23 . V_24 ,
struct V_21 , V_25 ) ;
struct V_26 * V_27 =
& V_7 -> V_28 [ V_29 ] . V_27 ;
struct V_1 * V_2 = V_22 -> V_30 ;
int error ;
if ( F_7 ( V_27 ) ) {
F_8 ( V_7 , L_3 ) ;
return - V_31 ;
}
V_16 = F_6 ( V_27 -> V_24 , struct V_20 , V_25 ) ;
if ( V_16 -> V_32 < 4 ) {
F_8 ( V_7 , L_4 ) ;
return - V_31 ;
}
V_9 = F_9 ( sizeof( struct V_8 ) , V_33 ) ;
if ( ! V_9 )
return - V_34 ;
F_10 ( V_35 , V_2 -> V_36 ) ;
error = F_11 ( V_2 , V_9 , F_1 ) ;
if ( error ) {
F_12 ( V_9 ) ;
return error ;
}
V_9 -> V_16 = V_16 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 0 ] = 0x00 ;
V_9 -> V_16 -> V_17 [ 1 ] -> V_18 [ 0 ] = 0x02 ;
V_9 -> V_16 -> V_17 [ 2 ] -> V_18 [ 0 ] = 0x00 ;
V_9 -> V_16 -> V_17 [ 3 ] -> V_18 [ 0 ] = 0x00 ;
F_4 ( V_7 , V_9 -> V_16 , V_19 ) ;
F_13 ( V_7 , L_5 ) ;
return 0 ;
}
static inline int F_5 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_14 ( struct V_6 * V_37 , const struct V_38 * V_39 )
{
int V_40 ;
V_40 = F_15 ( V_37 ) ;
if ( V_40 ) {
F_8 ( V_37 , L_6 ) ;
goto V_41;
}
V_40 = F_16 ( V_37 , V_42 & ~ V_43 ) ;
if ( V_40 ) {
F_8 ( V_37 , L_7 ) ;
goto V_41;
}
F_5 ( V_37 ) ;
return 0 ;
V_41:
return V_40 ;
}
