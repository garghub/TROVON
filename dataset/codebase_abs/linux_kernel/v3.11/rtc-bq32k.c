static int F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 V_9 [] = {
{
. V_10 = V_7 -> V_10 ,
. V_11 = 0 ,
. V_5 = 1 ,
. V_12 = & V_4 ,
} , {
. V_10 = V_7 -> V_10 ,
. V_11 = V_13 ,
. V_5 = V_5 ,
. V_12 = V_3 ,
}
} ;
if ( F_3 ( V_7 -> V_14 , V_9 , 2 ) == 2 )
return 0 ;
return - V_15 ;
}
static int F_4 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_16 [ V_5 + 1 ] ;
V_16 [ 0 ] = V_4 ;
memcpy ( & V_16 [ 1 ] , V_3 , V_5 ) ;
if ( F_5 ( V_7 , V_16 , V_5 + 1 ) == V_5 + 1 )
return 0 ;
return - V_15 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_19 V_20 ;
int error ;
error = F_1 ( V_2 , & V_20 , 0 , sizeof( V_20 ) ) ;
if ( error )
return error ;
V_18 -> V_21 = F_7 ( V_20 . V_22 & V_23 ) ;
V_18 -> V_24 = F_7 ( V_20 . V_25 & V_23 ) ;
V_18 -> V_26 = F_7 ( V_20 . V_27 & V_28 ) ;
V_18 -> V_29 = F_7 ( V_20 . V_30 ) ;
V_18 -> V_31 = F_7 ( V_20 . V_32 ) - 1 ;
V_18 -> V_33 = F_7 ( V_20 . V_34 ) - 1 ;
V_18 -> V_35 = F_7 ( V_20 . V_36 ) +
( ( V_20 . V_27 & V_37 ) ? 100 : 0 ) ;
return F_8 ( V_18 ) ;
}
static int F_9 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_19 V_20 ;
V_20 . V_22 = F_10 ( V_18 -> V_21 ) ;
V_20 . V_25 = F_10 ( V_18 -> V_24 ) ;
V_20 . V_27 = F_10 ( V_18 -> V_26 ) | V_38 ;
V_20 . V_32 = F_10 ( V_18 -> V_31 + 1 ) ;
V_20 . V_30 = F_10 ( V_18 -> V_29 ) ;
V_20 . V_34 = F_10 ( V_18 -> V_33 + 1 ) ;
if ( V_18 -> V_35 >= 100 ) {
V_20 . V_27 |= V_37 ;
V_20 . V_36 = F_10 ( V_18 -> V_35 - 100 ) ;
} else
V_20 . V_36 = F_10 ( V_18 -> V_35 ) ;
return F_4 ( V_2 , & V_20 , 0 , sizeof( V_20 ) ) ;
}
static int F_11 ( struct V_6 * V_7 ,
const struct V_39 * V_40 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
struct V_41 * V_42 ;
T_1 V_43 ;
int error ;
if ( ! F_12 ( V_7 -> V_14 , V_44 ) )
return - V_45 ;
error = F_1 ( V_2 , & V_43 , V_46 , 1 ) ;
if ( ! error && ( V_43 & V_47 ) ) {
F_13 ( V_2 , L_1 ) ;
V_43 &= ~ V_47 ;
error = F_4 ( V_2 , & V_43 , V_46 , 1 ) ;
}
if ( error )
return error ;
error = F_1 ( V_2 , & V_43 , V_48 , 1 ) ;
if ( ! error && ( V_43 & V_49 ) ) {
F_13 ( V_2 , L_2 ) ;
V_43 &= ~ V_49 ;
error = F_4 ( V_2 , & V_43 , V_48 , 1 ) ;
}
if ( error )
return error ;
V_42 = F_14 ( & V_7 -> V_2 , V_50 . V_51 . V_52 ,
& V_53 , V_54 ) ;
if ( F_15 ( V_42 ) )
return F_16 ( V_42 ) ;
F_17 ( V_7 , V_42 ) ;
return 0 ;
}
