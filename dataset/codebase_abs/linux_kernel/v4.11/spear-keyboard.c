static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned int V_7 ;
T_2 V_8 , V_9 ;
V_8 = F_2 ( V_4 -> V_10 + V_11 ) ;
if ( ! ( V_8 & V_12 ) )
return V_13 ;
if ( V_4 -> V_14 != V_15 ) {
F_3 ( V_6 , V_4 -> V_14 , 0 ) ;
V_4 -> V_14 = V_15 ;
}
V_9 = F_2 ( V_4 -> V_10 + V_16 ) &
( V_17 | V_18 ) ;
V_7 = V_4 -> V_19 [ V_9 ] ;
F_4 ( V_6 , V_20 , V_21 , V_9 ) ;
F_3 ( V_6 , V_7 , 1 ) ;
F_5 ( V_6 ) ;
V_4 -> V_14 = V_7 ;
F_6 ( 0 , V_4 -> V_10 + V_11 ) ;
return V_22 ;
}
static int F_7 ( struct V_5 * V_23 )
{
struct V_3 * V_4 = F_8 ( V_23 ) ;
int error ;
T_2 V_9 ;
V_4 -> V_14 = V_15 ;
error = F_9 ( V_4 -> V_24 ) ;
if ( error )
return error ;
V_9 = F_10 ( V_4 -> V_24 ) / 1000000 - 1 ;
V_9 = ( V_9 & V_25 ) << V_26 ;
V_9 = V_27 | V_28 | V_9 |
( V_4 -> V_29 << V_30 ) ;
F_6 ( V_9 , V_4 -> V_10 + V_31 ) ;
F_6 ( 1 , V_4 -> V_10 + V_11 ) ;
V_9 = F_2 ( V_4 -> V_10 + V_31 ) ;
V_9 |= V_32 ;
F_6 ( V_9 , V_4 -> V_10 + V_31 ) ;
return 0 ;
}
static void F_11 ( struct V_5 * V_23 )
{
struct V_3 * V_4 = F_8 ( V_23 ) ;
T_2 V_9 ;
V_9 = F_2 ( V_4 -> V_10 + V_31 ) ;
V_9 &= ~ V_32 ;
F_6 ( V_9 , V_4 -> V_10 + V_31 ) ;
F_12 ( V_4 -> V_24 ) ;
V_4 -> V_14 = V_15 ;
}
static int F_13 ( struct V_33 * V_34 ,
struct V_3 * V_4 )
{
struct V_35 * V_36 = V_34 -> V_23 . V_37 ;
int error ;
T_2 V_9 , V_38 ;
if ( ! V_36 ) {
F_14 ( & V_34 -> V_23 , L_1 ) ;
return - V_39 ;
}
if ( F_15 ( V_36 , L_2 ) )
V_4 -> V_40 = true ;
if ( F_16 ( V_36 , L_3 , & V_38 ) )
V_4 -> V_38 = V_38 ;
error = F_16 ( V_36 , L_4 , & V_9 ) ;
if ( error ) {
F_14 ( & V_34 -> V_23 , L_5 ) ;
return error ;
}
V_4 -> V_29 = V_9 ;
return 0 ;
}
static inline int F_13 ( struct V_33 * V_34 ,
struct V_3 * V_4 )
{
return - V_41 ;
}
static int F_17 ( struct V_33 * V_34 )
{
struct V_42 * V_43 = F_18 ( & V_34 -> V_23 ) ;
const struct V_44 * V_45 = V_43 ? V_43 -> V_45 : NULL ;
struct V_3 * V_4 ;
struct V_5 * V_5 ;
struct V_46 * V_47 ;
int V_1 ;
int error ;
V_1 = F_19 ( V_34 , 0 ) ;
if ( V_1 < 0 ) {
F_14 ( & V_34 -> V_23 , L_6 ) ;
return V_1 ;
}
V_4 = F_20 ( & V_34 -> V_23 , sizeof( * V_4 ) , V_48 ) ;
if ( ! V_4 ) {
F_14 ( & V_34 -> V_23 , L_7 ) ;
return - V_49 ;
}
V_5 = F_21 ( & V_34 -> V_23 ) ;
if ( ! V_5 ) {
F_14 ( & V_34 -> V_23 , L_8 ) ;
return - V_49 ;
}
V_4 -> V_6 = V_5 ;
V_4 -> V_1 = V_1 ;
if ( ! V_43 ) {
error = F_13 ( V_34 , V_4 ) ;
if ( error )
return error ;
} else {
V_4 -> V_29 = V_43 -> V_29 ;
V_4 -> V_40 = V_43 -> V_40 ;
V_4 -> V_38 = V_43 -> V_38 ;
}
V_47 = F_22 ( V_34 , V_50 , 0 ) ;
V_4 -> V_10 = F_23 ( & V_34 -> V_23 , V_47 ) ;
if ( F_24 ( V_4 -> V_10 ) )
return F_25 ( V_4 -> V_10 ) ;
V_4 -> V_24 = F_26 ( & V_34 -> V_23 , NULL ) ;
if ( F_24 ( V_4 -> V_24 ) )
return F_25 ( V_4 -> V_24 ) ;
V_5 -> V_51 = L_9 ;
V_5 -> V_52 = L_10 ;
V_5 -> V_53 . V_54 = V_55 ;
V_5 -> V_53 . V_56 = 0x0001 ;
V_5 -> V_53 . V_57 = 0x0001 ;
V_5 -> V_53 . V_58 = 0x0100 ;
V_5 -> V_59 = F_7 ;
V_5 -> V_60 = F_11 ;
error = F_27 ( V_45 , NULL , V_61 , V_62 ,
V_4 -> V_19 , V_5 ) ;
if ( error ) {
F_14 ( & V_34 -> V_23 , L_11 ) ;
return error ;
}
if ( V_4 -> V_40 )
F_28 ( V_63 , V_5 -> V_64 ) ;
F_29 ( V_5 , V_20 , V_21 ) ;
F_30 ( V_5 , V_4 ) ;
error = F_31 ( & V_34 -> V_23 , V_1 , F_1 , 0 ,
L_12 , V_4 ) ;
if ( error ) {
F_14 ( & V_34 -> V_23 , L_13 ) ;
return error ;
}
error = F_32 ( V_4 -> V_24 ) ;
if ( error )
return error ;
error = F_33 ( V_5 ) ;
if ( error ) {
F_14 ( & V_34 -> V_23 , L_14 ) ;
F_34 ( V_4 -> V_24 ) ;
return error ;
}
F_35 ( & V_34 -> V_23 , 1 ) ;
F_36 ( V_34 , V_4 ) ;
return 0 ;
}
static int F_37 ( struct V_33 * V_34 )
{
struct V_3 * V_4 = F_38 ( V_34 ) ;
F_39 ( V_4 -> V_6 ) ;
F_34 ( V_4 -> V_24 ) ;
return 0 ;
}
static int T_3 F_40 ( struct V_65 * V_23 )
{
struct V_33 * V_34 = F_41 ( V_23 ) ;
struct V_3 * V_4 = F_38 ( V_34 ) ;
struct V_5 * V_5 = V_4 -> V_6 ;
unsigned int V_66 = 0 , V_67 , V_9 ;
F_42 ( & V_5 -> V_68 ) ;
F_9 ( V_4 -> V_24 ) ;
V_67 = F_2 ( V_4 -> V_10 + V_31 ) ;
if ( F_43 ( & V_34 -> V_23 ) ) {
if ( ! F_44 ( V_4 -> V_1 ) )
V_4 -> V_69 = true ;
if ( V_4 -> V_38 )
V_66 = V_4 -> V_38 / 1000000 - 1 ;
else
V_66 = F_10 ( V_4 -> V_24 ) / 1000000 - 1 ;
V_9 = V_67 &
~ ( V_25 << V_26 ) ;
V_9 |= ( V_66 & V_25 )
<< V_26 ;
F_6 ( V_9 , V_4 -> V_10 + V_31 ) ;
} else {
if ( V_5 -> V_70 ) {
F_6 ( V_67 & ~ V_32 ,
V_4 -> V_10 + V_31 ) ;
F_12 ( V_4 -> V_24 ) ;
}
}
if ( V_5 -> V_70 )
V_4 -> V_67 = V_67 ;
F_12 ( V_4 -> V_24 ) ;
F_45 ( & V_5 -> V_68 ) ;
return 0 ;
}
static int T_3 F_46 ( struct V_65 * V_23 )
{
struct V_33 * V_34 = F_41 ( V_23 ) ;
struct V_3 * V_4 = F_38 ( V_34 ) ;
struct V_5 * V_5 = V_4 -> V_6 ;
F_42 ( & V_5 -> V_68 ) ;
if ( F_43 ( & V_34 -> V_23 ) ) {
if ( V_4 -> V_69 ) {
V_4 -> V_69 = false ;
F_47 ( V_4 -> V_1 ) ;
}
} else {
if ( V_5 -> V_70 )
F_9 ( V_4 -> V_24 ) ;
}
if ( V_5 -> V_70 )
F_6 ( V_4 -> V_67 , V_4 -> V_10 + V_31 ) ;
F_45 ( & V_5 -> V_68 ) ;
return 0 ;
}
