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
* V_9 -> V_16 = V_10 ;
* V_9 -> V_17 = V_11 ;
F_3 ( L_2 , V_10 , V_11 ) ;
F_4 ( V_7 , V_9 -> V_18 , V_19 ) ;
return 0 ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_20 * V_18 ;
struct V_21 * V_22 ;
struct V_23 * V_24 =
& V_7 -> V_25 [ V_26 ] . V_24 ;
struct V_23 * V_27 = V_24 ;
struct V_1 * V_2 ;
int error ;
T_1 * V_16 ;
T_1 * V_17 ;
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
V_18 = F_9 ( V_27 , struct V_20 , V_30 ) ;
if ( V_18 -> V_31 < 1 ) {
F_7 ( V_7 , L_5 ) ;
return - V_28 ;
}
if ( V_18 -> V_32 [ 0 ] -> V_33 >= 4 ) {
V_18 -> V_32 [ 0 ] -> V_34 [ 0 ] = 0x00 ;
V_18 -> V_32 [ 0 ] -> V_34 [ 1 ] = 0x00 ;
V_16 = & V_18 -> V_32 [ 0 ] -> V_34 [ 2 ] ;
V_17 = & V_18 -> V_32 [ 0 ] -> V_34 [ 3 ] ;
F_3 ( L_6 ) ;
} else if ( V_18 -> V_31 >= 4 && V_18 -> V_32 [ 0 ] -> V_35 == 1 &&
V_18 -> V_32 [ 0 ] -> V_36 [ 0 ] . V_7 == ( V_37 | 0x43 ) ) {
V_18 -> V_32 [ 0 ] -> V_34 [ 0 ] = 0x00 ;
V_18 -> V_32 [ 1 ] -> V_34 [ 0 ] = 0x00 ;
V_16 = & V_18 -> V_32 [ 2 ] -> V_34 [ 0 ] ;
V_17 = & V_18 -> V_32 [ 3 ] -> V_34 [ 0 ] ;
F_3 ( L_7 ) ;
} else {
F_7 ( V_7 , L_8 ) ;
return - V_28 ;
}
V_9 = F_10 ( sizeof( struct V_8 ) , V_38 ) ;
if ( ! V_9 )
return - V_39 ;
V_2 = V_22 -> V_40 ;
F_11 ( V_41 , V_2 -> V_42 ) ;
error = F_12 ( V_2 , V_9 , F_1 ) ;
if ( error ) {
F_13 ( V_9 ) ;
return error ;
}
V_9 -> V_18 = V_18 ;
V_9 -> V_16 = V_16 ;
V_9 -> V_17 = V_17 ;
* V_16 = 0x00 ;
* V_17 = 0x00 ;
F_4 ( V_7 , V_9 -> V_18 , V_19 ) ;
}
F_14 ( V_7 , L_9 ) ;
return 0 ;
}
static inline int F_5 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_15 ( struct V_6 * V_43 , const struct V_44 * V_45 )
{
int V_46 ;
if ( V_45 -> V_47 )
V_43 -> V_48 |= V_49 ;
V_46 = F_16 ( V_43 ) ;
if ( V_46 ) {
F_7 ( V_43 , L_10 ) ;
goto V_50;
}
V_46 = F_17 ( V_43 , V_51 & ~ V_52 ) ;
if ( V_46 ) {
F_7 ( V_43 , L_11 ) ;
goto V_50;
}
F_5 ( V_43 ) ;
return 0 ;
V_50:
return V_46 ;
}
static int T_2 F_18 ( void )
{
return F_19 ( & V_53 ) ;
}
static void T_3 F_20 ( void )
{
F_21 ( & V_53 ) ;
}
