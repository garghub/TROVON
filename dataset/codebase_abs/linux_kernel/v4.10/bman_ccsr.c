static inline T_1 F_1 ( T_1 V_1 )
{
return F_2 ( V_2 + V_1 / 4 ) ;
}
static inline void F_3 ( T_1 V_1 , T_1 V_3 )
{
F_4 ( V_3 , V_2 + V_1 / 4 ) ;
}
static void F_5 ( T_2 * V_4 , T_3 * V_5 , T_3 * V_6 )
{
T_1 V_7 = F_1 ( V_8 ) ;
* V_4 = ( V_7 >> 16 ) ;
* V_5 = ( V_7 >> 8 ) & 0xff ;
* V_6 = V_7 & 0xff ;
}
static void F_6 ( T_4 V_9 , T_1 V_10 )
{
T_1 exp = F_7 ( V_10 ) ;
F_8 ( V_10 >= 4096 && V_10 <= 1024 * 1024 * 1024 &&
F_9 ( V_10 ) ) ;
F_8 ( ! ( V_9 & ( V_10 - 1 ) ) ) ;
F_3 ( V_11 , F_10 ( V_9 ) ) ;
F_3 ( V_12 , F_11 ( V_9 ) ) ;
F_3 ( V_13 , exp - 1 ) ;
}
static int F_12 ( struct V_14 * V_15 )
{
V_16 = V_15 -> V_17 ;
V_18 = V_15 -> V_10 ;
F_13 ( ! ( V_16 && V_18 ) ) ;
return 0 ;
}
static T_5 F_14 ( int V_19 , void * V_20 )
{
T_1 V_21 , V_22 , V_23 , V_24 , V_25 ;
struct V_26 * V_27 = V_20 ;
V_22 = F_1 ( V_28 ) ;
V_21 = F_1 ( V_29 ) ;
V_23 = F_1 ( V_30 ) ;
V_24 = V_21 & V_22 ;
if ( ! V_24 )
return V_31 ;
for ( V_25 = 0 ; V_25 < F_15 ( V_32 ) ; V_25 ++ ) {
if ( V_32 [ V_25 ] . V_33 & V_24 ) {
F_16 ( V_27 , L_1 ,
V_32 [ V_25 ] . V_34 ) ;
if ( V_32 [ V_25 ] . V_33 & V_23 ) {
F_3 ( V_30 , V_23 ) ;
}
if ( V_32 [ V_25 ] . V_33 & V_35 ) {
F_17 ( V_27 , L_2 ,
V_32 [ V_25 ] . V_33 ) ;
V_22 &= ~ V_32 [ V_25 ] . V_33 ;
F_3 ( V_28 , V_22 ) ;
}
}
}
F_3 ( V_29 , V_21 ) ;
return V_36 ;
}
static int F_18 ( struct V_37 * V_38 )
{
int V_39 , V_40 ;
struct V_26 * V_27 = & V_38 -> V_27 ;
struct V_41 * V_42 = V_27 -> V_43 ;
struct V_44 * V_45 ;
T_2 V_4 , V_46 ;
T_3 V_5 , V_6 ;
V_45 = F_19 ( V_38 , V_47 , 0 ) ;
if ( ! V_45 ) {
F_20 ( V_27 , L_3 ,
V_42 -> V_48 ) ;
return - V_49 ;
}
V_2 = F_21 ( V_27 , V_45 -> V_50 , F_22 ( V_45 ) ) ;
if ( ! V_2 )
return - V_49 ;
F_5 ( & V_4 , & V_5 , & V_6 ) ;
if ( V_5 == 1 && V_6 == 0 ) {
V_51 = V_52 ;
V_46 = V_53 ;
} else if ( V_5 == 2 && V_6 == 0 ) {
V_51 = V_54 ;
V_46 = 8 ;
} else if ( V_5 == 2 && V_6 == 1 ) {
V_51 = V_55 ;
V_46 = V_53 ;
} else {
F_20 ( V_27 , L_4 ,
V_4 , V_5 , V_6 ) ;
return - V_56 ;
}
F_6 ( V_16 , V_18 ) ;
V_40 = F_23 ( V_38 , 0 ) ;
if ( V_40 <= 0 ) {
F_24 ( V_27 , L_5 , V_42 -> V_48 ) ;
return - V_56 ;
}
V_39 = F_25 ( V_27 , V_40 , F_14 , V_57 , L_6 ,
V_27 ) ;
if ( V_39 ) {
F_20 ( V_27 , L_7 ,
V_39 , V_42 -> V_48 ) ;
return V_39 ;
}
F_3 ( V_58 , V_59 ) ;
F_3 ( V_29 , 0xffffffff ) ;
F_3 ( V_28 , 0xffffffff ) ;
V_60 = F_26 ( V_27 , 0 , - 1 , L_8 ) ;
if ( F_27 ( V_60 ) ) {
V_39 = F_28 ( V_60 ) ;
F_20 ( V_27 , L_9 , V_39 ) ;
return V_39 ;
}
V_39 = F_29 ( V_60 , V_61 , V_46 , - 1 ) ;
if ( V_39 ) {
F_20 ( V_27 , L_10 ,
0 , V_46 - 1 , V_39 ) ;
return V_39 ;
}
return 0 ;
}
