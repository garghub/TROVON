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
if ( V_20 . V_21 & V_22 )
return - V_23 ;
V_18 -> V_24 = F_7 ( V_20 . V_25 & V_26 ) ;
V_18 -> V_27 = F_7 ( V_20 . V_21 & V_28 ) ;
V_18 -> V_29 = F_7 ( V_20 . V_30 & V_31 ) ;
V_18 -> V_32 = F_7 ( V_20 . V_33 ) ;
V_18 -> V_34 = F_7 ( V_20 . V_35 ) - 1 ;
V_18 -> V_36 = F_7 ( V_20 . V_37 ) - 1 ;
V_18 -> V_38 = F_7 ( V_20 . V_39 ) +
( ( V_20 . V_30 & V_40 ) ? 100 : 0 ) ;
return F_8 ( V_18 ) ;
}
static int F_9 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_19 V_20 ;
V_20 . V_25 = F_10 ( V_18 -> V_24 ) ;
V_20 . V_21 = F_10 ( V_18 -> V_27 ) ;
V_20 . V_30 = F_10 ( V_18 -> V_29 ) | V_41 ;
V_20 . V_35 = F_10 ( V_18 -> V_34 + 1 ) ;
V_20 . V_33 = F_10 ( V_18 -> V_32 ) ;
V_20 . V_37 = F_10 ( V_18 -> V_36 + 1 ) ;
if ( V_18 -> V_38 >= 100 ) {
V_20 . V_30 |= V_40 ;
V_20 . V_39 = F_10 ( V_18 -> V_38 - 100 ) ;
} else
V_20 . V_39 = F_10 ( V_18 -> V_38 ) ;
return F_4 ( V_2 , & V_20 , 0 , sizeof( V_20 ) ) ;
}
static int F_11 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
unsigned char V_44 ;
int error ;
T_2 V_45 = 0 ;
if ( F_12 ( V_43 , L_1 , & V_45 ) )
return 0 ;
switch ( V_45 ) {
case 180 + 940 :
if ( F_13 ( V_43 , L_2 ) ) {
F_14 ( V_2 , L_3 ) ;
return - V_23 ;
}
V_44 = 0x05 ;
break;
case 180 + 20000 :
if ( ! F_13 ( V_43 , L_2 ) ) {
F_14 ( V_2 , L_4 ) ;
return - V_23 ;
}
V_44 = 0x45 ;
break;
default:
F_14 ( V_2 , L_5 , V_45 ) ;
return - V_23 ;
}
error = F_4 ( V_2 , & V_44 , V_46 , 1 ) ;
if ( error )
return error ;
V_44 = 0x20 ;
error = F_4 ( V_2 , & V_44 , V_47 , 1 ) ;
if ( error )
return error ;
F_15 ( V_2 , L_6 ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 ,
const struct V_48 * V_49 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
struct V_50 * V_51 ;
T_1 V_44 ;
int error ;
if ( ! F_17 ( V_7 -> V_14 , V_52 ) )
return - V_53 ;
error = F_1 ( V_2 , & V_44 , V_54 , 1 ) ;
if ( ! error && ( V_44 & V_55 ) ) {
F_18 ( V_2 , L_7 ) ;
V_44 &= ~ V_55 ;
error = F_4 ( V_2 , & V_44 , V_54 , 1 ) ;
}
if ( error )
return error ;
error = F_1 ( V_2 , & V_44 , V_56 , 1 ) ;
if ( error )
return error ;
if ( V_44 & V_22 )
F_18 ( V_2 , L_8 ) ;
if ( V_7 -> V_2 . V_57 )
F_11 ( V_2 , V_7 -> V_2 . V_57 ) ;
V_51 = F_19 ( & V_7 -> V_2 , V_58 . V_59 . V_60 ,
& V_61 , V_62 ) ;
if ( F_20 ( V_51 ) )
return F_21 ( V_51 ) ;
F_22 ( V_7 , V_51 ) ;
return 0 ;
}
