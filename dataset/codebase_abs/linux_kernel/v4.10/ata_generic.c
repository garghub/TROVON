static int F_1 ( struct V_1 * V_2 , struct V_3 * * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
const struct V_7 * V_8 = V_6 -> V_9 -> V_10 ;
int V_11 = 0 ;
struct V_3 * V_12 ;
if ( V_8 -> V_13 & V_14 ) {
V_11 = 0xff ;
} else if ( V_6 -> V_15 . V_16 ) {
V_11 = F_2 ( V_6 -> V_15 . V_16 + V_17 ) ;
}
F_3 (dev, link, ENABLED) {
V_12 -> V_18 = V_19 ;
V_12 -> V_20 = V_21 ;
if ( V_11 & ( 1 << ( 5 + V_12 -> V_22 ) ) ) {
unsigned int V_23 = F_4 ( V_12 -> V_8 ) ;
const char * V_24 ;
if ( V_23 & ( V_25 | V_26 ) )
V_24 = F_5 ( V_23 ) ;
else {
V_24 = L_1 ;
V_23 |= F_6 ( V_21 ) ;
}
F_7 ( V_12 , L_2 , V_24 ) ;
V_12 -> V_27 = F_8 ( V_23 ) ;
V_12 -> V_28 = F_9 ( V_12 -> V_27 ) ;
V_12 -> V_29 &= ~ V_30 ;
} else {
F_7 ( V_12 , L_3 ) ;
V_12 -> V_27 = V_19 ;
V_12 -> V_28 = V_31 ;
V_12 -> V_29 |= V_30 ;
}
}
return 0 ;
}
static int F_10 ( struct V_32 * V_12 )
{
T_1 V_33 ;
T_2 V_34 ;
F_11 ( V_12 , 0xF8 , & V_33 ) ;
if ( V_33 != 0 )
return 0 ;
F_12 ( V_12 , 0x40 , & V_34 ) ;
if ( V_34 != 0 )
return 0 ;
F_13 ( V_12 , 0x40 , 1 ) ;
F_12 ( V_12 , 0x40 , & V_34 ) ;
if ( V_34 ) {
F_13 ( V_12 , 0x40 , 0 ) ;
return 0 ;
}
return 1 ;
}
static int F_14 ( struct V_32 * V_12 , const struct V_7 * V_8 )
{
T_2 V_35 ;
static const struct V_36 V_37 = {
. V_29 = V_38 ,
. V_39 = V_40 ,
. V_41 = V_42 ,
. V_43 = V_44 ,
. V_45 = & V_46
} ;
const struct V_36 * V_47 [] = { & V_37 , NULL } ;
if ( ( V_8 -> V_13 & V_48 ) && V_49 == 0 )
return - V_50 ;
if ( ( V_8 -> V_13 & V_51 ) && ! V_49 )
if ( ! F_10 ( V_12 ) )
return - V_50 ;
if ( V_12 -> V_52 == V_53 &&
V_12 -> V_54 == V_55 &&
( ! ( F_15 ( V_12 -> V_56 ) & 1 ) ) )
return - V_50 ;
if ( V_12 -> V_52 == V_57 &&
V_12 -> V_54 == V_58 &&
( ! ( F_15 ( V_12 -> V_56 ) & 1 ) ) )
return - V_50 ;
F_12 ( V_12 , V_59 , & V_35 ) ;
if ( ! ( V_35 & V_60 ) )
return - V_50 ;
if ( V_12 -> V_52 == V_61 )
F_16 ( V_12 ) ;
if ( V_12 -> V_52 == V_62 ) {
int V_63 = F_17 ( V_12 ) ;
if ( V_63 < 0 )
return V_63 ;
F_18 ( V_12 ) ;
}
return F_19 ( V_12 , V_47 , & V_64 , ( void * ) V_8 , 0 ) ;
}
