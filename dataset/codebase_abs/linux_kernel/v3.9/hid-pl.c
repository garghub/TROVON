static int F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_3 ;
int V_10 , V_11 ;
V_10 = V_5 -> V_12 . V_13 . V_14 ;
V_11 = V_5 -> V_12 . V_13 . V_15 ;
F_3 ( L_1 , V_10 , V_11 ) ;
V_10 = V_10 * V_9 -> V_16 / 0xffff ;
V_11 = V_11 * V_9 -> V_16 / 0xffff ;
* V_9 -> V_17 = V_10 ;
* V_9 -> V_18 = V_11 ;
F_3 ( L_2 , V_10 , V_11 ) ;
F_4 ( V_7 , V_9 -> V_19 , V_20 ) ;
return 0 ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_21 * V_19 ;
struct V_22 * V_23 ;
struct V_24 * V_25 =
& V_7 -> V_26 [ V_27 ] . V_25 ;
struct V_24 * V_28 = V_25 ;
struct V_1 * V_2 ;
int error ;
T_1 V_16 ;
T_1 * V_17 ;
T_1 * V_18 ;
if ( F_6 ( V_25 ) ) {
F_7 ( V_7 , L_3 ) ;
return - V_29 ;
}
F_8 (hidinput, &hid->inputs, list) {
V_28 = V_28 -> V_30 ;
if ( V_28 == V_25 ) {
F_7 ( V_7 , L_4 ) ;
return - V_29 ;
}
V_19 = F_9 ( V_28 , struct V_21 , V_31 ) ;
if ( V_19 -> V_32 < 1 ) {
F_7 ( V_7 , L_5 ) ;
return - V_29 ;
}
V_16 = 0x7f ;
if ( V_19 -> V_33 [ 0 ] -> V_34 >= 4 ) {
V_19 -> V_33 [ 0 ] -> V_35 [ 0 ] = 0x00 ;
V_19 -> V_33 [ 0 ] -> V_35 [ 1 ] = 0x00 ;
V_17 = & V_19 -> V_33 [ 0 ] -> V_35 [ 2 ] ;
V_18 = & V_19 -> V_33 [ 0 ] -> V_35 [ 3 ] ;
F_3 ( L_6 ) ;
} else if ( V_19 -> V_32 >= 4 && V_19 -> V_33 [ 0 ] -> V_36 == 1 &&
V_19 -> V_33 [ 0 ] -> V_37 [ 0 ] . V_7 == ( V_38 | 0x43 ) ) {
V_19 -> V_33 [ 0 ] -> V_35 [ 0 ] = 0x00 ;
V_19 -> V_33 [ 1 ] -> V_35 [ 0 ] = 0x00 ;
V_17 = & V_19 -> V_33 [ 2 ] -> V_35 [ 0 ] ;
V_18 = & V_19 -> V_33 [ 3 ] -> V_35 [ 0 ] ;
if ( V_7 -> V_39 == V_40 )
V_16 = 0xff ;
F_3 ( L_7 ) ;
} else {
F_7 ( V_7 , L_8 ) ;
return - V_29 ;
}
V_9 = F_10 ( sizeof( struct V_8 ) , V_41 ) ;
if ( ! V_9 )
return - V_42 ;
V_2 = V_23 -> V_43 ;
F_11 ( V_44 , V_2 -> V_45 ) ;
error = F_12 ( V_2 , V_9 , F_1 ) ;
if ( error ) {
F_13 ( V_9 ) ;
return error ;
}
V_9 -> V_19 = V_19 ;
V_9 -> V_17 = V_17 ;
V_9 -> V_18 = V_18 ;
V_9 -> V_16 = V_16 ;
* V_17 = 0x00 ;
* V_18 = 0x00 ;
F_4 ( V_7 , V_9 -> V_19 , V_20 ) ;
}
F_14 ( V_7 , L_9 ) ;
return 0 ;
}
static inline int F_5 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_15 ( struct V_6 * V_46 , const struct V_47 * V_48 )
{
int V_49 ;
if ( V_48 -> V_50 )
V_46 -> V_51 |= V_52 ;
V_49 = F_16 ( V_46 ) ;
if ( V_49 ) {
F_7 ( V_46 , L_10 ) ;
goto V_53;
}
V_49 = F_17 ( V_46 , V_54 & ~ V_55 ) ;
if ( V_49 ) {
F_7 ( V_46 , L_11 ) ;
goto V_53;
}
F_5 ( V_46 ) ;
return 0 ;
V_53:
return V_49 ;
}
