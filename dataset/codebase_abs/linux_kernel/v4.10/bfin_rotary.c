static void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 , V_3 , 1 ) ;
F_3 ( V_2 ) ;
F_2 ( V_2 , V_3 , 0 ) ;
F_3 ( V_2 ) ;
}
static void F_4 ( struct V_4 * V_5 , int V_6 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
if ( V_5 -> V_7 ) {
F_1 ( V_2 ,
V_6 > 0 ? V_5 -> V_7 : V_5 -> V_8 ) ;
} else {
F_5 ( V_2 , V_5 -> V_9 , V_6 ) ;
F_3 ( V_2 ) ;
}
}
static T_1 F_6 ( int V_10 , void * V_11 )
{
struct V_4 * V_5 = V_11 ;
int V_6 ;
switch ( F_7 ( V_5 -> V_12 + V_13 ) ) {
case V_14 :
break;
case V_15 :
case V_16 :
V_6 = F_8 ( V_5 -> V_12 + V_17 ) ;
if ( V_6 )
F_4 ( V_5 , V_6 ) ;
break;
case V_18 :
F_1 ( V_5 -> V_2 , V_5 -> V_19 ) ;
break;
default:
break;
}
F_9 ( V_20 , V_5 -> V_12 + V_21 ) ;
F_9 ( - 1 , V_5 -> V_12 + V_13 ) ;
return V_22 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_11 ( V_2 ) ;
unsigned short V_23 ;
if ( V_5 -> V_24 & V_25 )
F_9 ( V_5 -> V_26 & V_27 ,
V_5 -> V_12 + V_28 ) ;
F_9 ( V_5 -> V_24 & ~ V_29 , V_5 -> V_12 + V_30 ) ;
V_23 = V_31 | V_32 ;
if ( V_5 -> V_19 )
V_23 |= V_33 ;
F_9 ( V_23 , V_5 -> V_12 + V_34 ) ;
F_9 ( V_5 -> V_24 | V_29 , V_5 -> V_12 + V_30 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_11 ( V_2 ) ;
F_9 ( 0 , V_5 -> V_12 + V_30 ) ;
F_9 ( 0 , V_5 -> V_12 + V_34 ) ;
}
static void F_13 ( void * V_35 )
{
F_14 ( V_35 ) ;
}
static int F_15 ( struct V_36 * V_37 )
{
struct V_38 * V_39 = & V_37 -> V_39 ;
const struct V_40 * V_41 = F_16 ( V_39 ) ;
struct V_4 * V_5 ;
struct V_42 * V_43 ;
struct V_1 * V_2 ;
int error ;
if ( ( V_41 -> V_44 && ! V_41 -> V_45 ) ||
( ! V_41 -> V_44 && V_41 -> V_45 ) ) {
return - V_46 ;
}
if ( V_41 -> V_47 ) {
error = F_17 ( V_41 -> V_47 ,
F_18 ( & V_37 -> V_39 ) ) ;
if ( error ) {
F_19 ( V_39 , L_1 ,
error ) ;
return error ;
}
error = F_20 ( V_39 , F_13 ,
V_41 -> V_47 ) ;
if ( error ) {
F_19 ( V_39 , L_2 ,
error ) ;
F_14 ( V_41 -> V_47 ) ;
return error ;
}
}
V_5 = F_21 ( V_39 , sizeof( struct V_4 ) , V_48 ) ;
if ( ! V_5 )
return - V_49 ;
V_43 = F_22 ( V_37 , V_50 , 0 ) ;
V_5 -> V_12 = F_23 ( V_39 , V_43 ) ;
if ( F_24 ( V_5 -> V_12 ) )
return F_25 ( V_5 -> V_12 ) ;
V_2 = F_26 ( V_39 ) ;
if ( ! V_2 )
return - V_49 ;
V_5 -> V_2 = V_2 ;
V_5 -> V_7 = V_41 -> V_44 ;
V_5 -> V_8 = V_41 -> V_45 ;
V_5 -> V_19 = V_41 -> V_51 ;
V_5 -> V_9 = V_41 -> V_52 ;
V_5 -> V_24 = V_41 -> V_24 ;
V_5 -> V_26 = V_41 -> V_26 ;
V_2 -> V_53 = V_37 -> V_53 ;
V_2 -> V_54 = L_3 ;
V_2 -> V_39 . V_55 = & V_37 -> V_39 ;
F_27 ( V_2 , V_5 ) ;
V_2 -> V_56 . V_57 = V_58 ;
V_2 -> V_56 . V_59 = 0x0001 ;
V_2 -> V_56 . V_60 = 0x0001 ;
V_2 -> V_56 . V_61 = 0x0100 ;
V_2 -> V_62 = F_10 ;
V_2 -> V_63 = F_12 ;
if ( V_5 -> V_7 ) {
F_28 ( V_64 , V_2 -> V_65 ) ;
F_28 ( V_5 -> V_7 , V_2 -> V_66 ) ;
F_28 ( V_5 -> V_8 , V_2 -> V_66 ) ;
} else {
F_28 ( V_67 , V_2 -> V_65 ) ;
F_28 ( V_5 -> V_9 , V_2 -> V_68 ) ;
}
if ( V_5 -> V_19 ) {
F_28 ( V_64 , V_2 -> V_65 ) ;
F_28 ( V_5 -> V_19 , V_2 -> V_66 ) ;
}
F_12 ( V_2 ) ;
V_5 -> V_10 = F_29 ( V_37 , 0 ) ;
if ( V_5 -> V_10 < 0 ) {
F_19 ( V_39 , L_4 ) ;
return - V_69 ;
}
error = F_30 ( V_39 , V_5 -> V_10 , F_6 ,
0 , F_18 ( V_39 ) , V_5 ) ;
if ( error ) {
F_19 ( V_39 , L_5 ,
V_5 -> V_10 , error ) ;
return error ;
}
error = F_31 ( V_2 ) ;
if ( error ) {
F_19 ( V_39 , L_6 , error ) ;
return error ;
}
F_32 ( V_37 , V_5 ) ;
F_33 ( & V_37 -> V_39 , 1 ) ;
return 0 ;
}
static int T_2 F_34 ( struct V_38 * V_39 )
{
struct V_36 * V_37 = F_35 ( V_39 ) ;
struct V_4 * V_5 = F_36 ( V_37 ) ;
V_5 -> V_70 = F_7 ( V_5 -> V_12 + V_30 ) ;
V_5 -> V_71 = F_7 ( V_5 -> V_12 + V_34 ) ;
V_5 -> V_72 = F_7 ( V_5 -> V_12 + V_28 ) ;
if ( F_37 ( & V_37 -> V_39 ) )
F_38 ( V_5 -> V_10 ) ;
return 0 ;
}
static int T_2 F_39 ( struct V_38 * V_39 )
{
struct V_36 * V_37 = F_35 ( V_39 ) ;
struct V_4 * V_5 = F_36 ( V_37 ) ;
F_9 ( V_5 -> V_72 , V_5 -> V_12 + V_28 ) ;
F_9 ( V_5 -> V_71 , V_5 -> V_12 + V_34 ) ;
F_9 ( V_5 -> V_70 & ~ V_29 , V_5 -> V_12 + V_30 ) ;
if ( F_37 ( & V_37 -> V_39 ) )
F_40 ( V_5 -> V_10 ) ;
if ( V_5 -> V_70 & V_29 )
F_9 ( V_5 -> V_70 , V_5 -> V_12 + V_30 ) ;
return 0 ;
}
