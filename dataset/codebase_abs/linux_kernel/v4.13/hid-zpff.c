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
struct V_1 * V_2 = V_22 -> V_26 ;
int V_27 , error ;
for ( V_27 = 0 ; V_27 < 4 ; V_27 ++ ) {
V_16 = F_7 ( V_7 , V_28 , 0 , V_27 , 1 ) ;
if ( ! V_16 )
return - V_29 ;
}
V_9 = F_8 ( sizeof( struct V_8 ) , V_30 ) ;
if ( ! V_9 )
return - V_31 ;
F_9 ( V_32 , V_2 -> V_33 ) ;
error = F_10 ( V_2 , V_9 , F_1 ) ;
if ( error ) {
F_11 ( V_9 ) ;
return error ;
}
V_9 -> V_16 = V_16 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 0 ] = 0x00 ;
V_9 -> V_16 -> V_17 [ 1 ] -> V_18 [ 0 ] = 0x02 ;
V_9 -> V_16 -> V_17 [ 2 ] -> V_18 [ 0 ] = 0x00 ;
V_9 -> V_16 -> V_17 [ 3 ] -> V_18 [ 0 ] = 0x00 ;
F_4 ( V_7 , V_9 -> V_16 , V_19 ) ;
F_12 ( V_7 , L_3 ) ;
return 0 ;
}
static inline int F_5 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_13 ( struct V_6 * V_34 , const struct V_35 * V_36 )
{
int V_37 ;
V_37 = F_14 ( V_34 ) ;
if ( V_37 ) {
F_15 ( V_34 , L_4 ) ;
goto V_38;
}
V_37 = F_16 ( V_34 , V_39 & ~ V_40 ) ;
if ( V_37 ) {
F_15 ( V_34 , L_5 ) ;
goto V_38;
}
F_5 ( V_34 ) ;
return 0 ;
V_38:
return V_37 ;
}
