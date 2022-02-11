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
static T_3 F_16 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
char * V_12 )
{
int V_44 , error ;
error = F_1 ( V_2 , & V_44 , V_46 , 1 ) ;
if ( error )
return error ;
return sprintf ( V_12 , L_7 , ( V_44 & V_50 ) ? 1 : 0 ) ;
}
static T_3 F_17 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
const char * V_12 , T_4 V_51 )
{
int V_44 , V_52 , error ;
if ( F_18 ( V_12 , 0 , & V_52 ) )
return - V_23 ;
error = F_1 ( V_2 , & V_44 , V_46 , 1 ) ;
if ( error )
return error ;
if ( V_52 ) {
V_44 |= V_50 ;
error = F_4 ( V_2 , & V_44 , V_46 , 1 ) ;
if ( error )
return error ;
F_15 ( V_2 , L_8 ) ;
} else {
V_44 &= ~ V_50 ;
error = F_4 ( V_2 , & V_44 , V_46 , 1 ) ;
if ( error )
return error ;
F_15 ( V_2 , L_9 ) ;
}
return V_51 ;
}
static int F_19 ( struct V_1 * V_2 )
{
return F_20 ( V_2 , & V_53 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_22 ( V_2 , & V_53 ) ;
}
static int F_23 ( struct V_6 * V_7 ,
const struct V_54 * V_55 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
struct V_56 * V_57 ;
T_1 V_44 ;
int error ;
if ( ! F_24 ( V_7 -> V_14 , V_58 ) )
return - V_59 ;
error = F_1 ( V_2 , & V_44 , V_60 , 1 ) ;
if ( ! error && ( V_44 & V_61 ) ) {
F_25 ( V_2 , L_10 ) ;
V_44 &= ~ V_61 ;
error = F_4 ( V_2 , & V_44 , V_60 , 1 ) ;
}
if ( error )
return error ;
error = F_1 ( V_2 , & V_44 , V_62 , 1 ) ;
if ( error )
return error ;
if ( V_44 & V_22 )
F_25 ( V_2 , L_11 ) ;
if ( V_7 -> V_2 . V_63 )
F_11 ( V_2 , V_7 -> V_2 . V_63 ) ;
V_57 = F_26 ( & V_7 -> V_2 , V_64 . V_65 . V_66 ,
& V_67 , V_68 ) ;
if ( F_27 ( V_57 ) )
return F_28 ( V_57 ) ;
error = F_19 ( & V_7 -> V_2 ) ;
if ( error ) {
F_14 ( & V_7 -> V_2 ,
L_12 ) ;
return error ;
}
F_29 ( V_7 , V_57 ) ;
return 0 ;
}
static int F_30 ( struct V_6 * V_7 )
{
F_21 ( & V_7 -> V_2 ) ;
return 0 ;
}
