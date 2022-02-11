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
V_9 = F_2 ( V_4 -> V_10 + V_16 ) ;
V_7 = V_4 -> V_17 [ V_9 ] ;
F_4 ( V_6 , V_18 , V_19 , V_9 ) ;
F_3 ( V_6 , V_7 , 1 ) ;
F_5 ( V_6 ) ;
V_4 -> V_14 = V_7 ;
F_6 ( 0 , V_4 -> V_10 + V_11 ) ;
return V_20 ;
}
static int F_7 ( struct V_5 * V_21 )
{
struct V_3 * V_4 = F_8 ( V_21 ) ;
int error ;
T_3 V_9 ;
V_4 -> V_14 = V_15 ;
error = F_9 ( V_4 -> V_22 ) ;
if ( error )
return error ;
V_9 = V_23 | V_24 | V_25 |
( V_4 -> V_26 << V_27 ) ;
F_10 ( V_9 , V_4 -> V_10 + V_28 ) ;
F_6 ( 1 , V_4 -> V_10 + V_11 ) ;
V_9 = F_11 ( V_4 -> V_10 + V_28 ) ;
V_9 |= V_29 ;
F_10 ( V_9 , V_4 -> V_10 + V_28 ) ;
return 0 ;
}
static void F_12 ( struct V_5 * V_21 )
{
struct V_3 * V_4 = F_8 ( V_21 ) ;
T_3 V_9 ;
V_9 = F_11 ( V_4 -> V_10 + V_28 ) ;
V_9 &= ~ V_29 ;
F_10 ( V_9 , V_4 -> V_10 + V_28 ) ;
F_13 ( V_4 -> V_22 ) ;
V_4 -> V_14 = V_15 ;
}
static int T_4 F_14 ( struct V_30 * V_31 ,
struct V_3 * V_4 )
{
struct V_32 * V_33 = V_31 -> V_21 . V_34 ;
int error ;
T_5 V_9 ;
if ( ! V_33 ) {
F_15 ( & V_31 -> V_21 , L_1 ) ;
return - V_35 ;
}
if ( F_16 ( V_33 , L_2 ) )
V_4 -> V_36 = true ;
error = F_17 ( V_33 , L_3 , & V_9 ) ;
if ( error ) {
F_15 ( & V_31 -> V_21 , L_4 ) ;
return error ;
}
V_4 -> V_26 = V_9 ;
return 0 ;
}
static inline int F_14 ( struct V_30 * V_31 ,
struct V_3 * V_4 )
{
return - V_37 ;
}
static int T_4 F_18 ( struct V_30 * V_31 )
{
struct V_38 * V_39 = F_19 ( & V_31 -> V_21 ) ;
const struct V_40 * V_41 = V_39 ? V_39 -> V_41 : NULL ;
struct V_3 * V_4 ;
struct V_5 * V_5 ;
struct V_42 * V_43 ;
int V_1 ;
int error ;
V_43 = F_20 ( V_31 , V_44 , 0 ) ;
if ( ! V_43 ) {
F_15 ( & V_31 -> V_21 , L_5 ) ;
return - V_45 ;
}
V_1 = F_21 ( V_31 , 0 ) ;
if ( V_1 < 0 ) {
F_15 ( & V_31 -> V_21 , L_6 ) ;
return V_1 ;
}
V_4 = F_22 ( sizeof( * V_4 ) , V_46 ) ;
V_5 = F_23 () ;
if ( ! V_4 || ! V_5 ) {
F_15 ( & V_31 -> V_21 , L_7 ) ;
error = - V_47 ;
goto V_48;
}
V_4 -> V_6 = V_5 ;
V_4 -> V_1 = V_1 ;
if ( ! V_39 ) {
error = F_14 ( V_31 , V_4 ) ;
if ( error )
goto V_48;
} else {
V_4 -> V_26 = V_39 -> V_26 ;
V_4 -> V_36 = V_39 -> V_36 ;
}
V_4 -> V_43 = F_24 ( V_43 -> V_49 , F_25 ( V_43 ) ,
V_31 -> V_50 ) ;
if ( ! V_4 -> V_43 ) {
F_15 ( & V_31 -> V_21 , L_8 ) ;
error = - V_45 ;
goto V_48;
}
V_4 -> V_10 = F_26 ( V_43 -> V_49 , F_25 ( V_43 ) ) ;
if ( ! V_4 -> V_10 ) {
F_15 ( & V_31 -> V_21 , L_9 ) ;
error = - V_47 ;
goto V_51;
}
V_4 -> V_22 = F_27 ( & V_31 -> V_21 , NULL ) ;
if ( F_28 ( V_4 -> V_22 ) ) {
error = F_29 ( V_4 -> V_22 ) ;
goto V_52;
}
V_5 -> V_50 = L_10 ;
V_5 -> V_53 = L_11 ;
V_5 -> V_21 . V_54 = & V_31 -> V_21 ;
V_5 -> V_55 . V_56 = V_57 ;
V_5 -> V_55 . V_58 = 0x0001 ;
V_5 -> V_55 . V_59 = 0x0001 ;
V_5 -> V_55 . V_60 = 0x0100 ;
V_5 -> V_61 = F_7 ;
V_5 -> V_62 = F_12 ;
error = F_30 ( V_41 , NULL , V_63 , V_64 ,
V_4 -> V_17 , V_5 ) ;
if ( error ) {
F_15 ( & V_31 -> V_21 , L_12 ) ;
goto V_65;
}
if ( V_4 -> V_36 )
F_31 ( V_66 , V_5 -> V_67 ) ;
F_32 ( V_5 , V_18 , V_19 ) ;
F_33 ( V_5 , V_4 ) ;
error = F_34 ( V_1 , F_1 , 0 , L_13 , V_4 ) ;
if ( error ) {
F_15 ( & V_31 -> V_21 , L_14 ) ;
goto V_65;
}
error = F_35 ( V_5 ) ;
if ( error ) {
F_15 ( & V_31 -> V_21 , L_15 ) ;
goto V_68;
}
F_36 ( & V_31 -> V_21 , 1 ) ;
F_37 ( V_31 , V_4 ) ;
return 0 ;
V_68:
F_38 ( V_4 -> V_1 , V_4 ) ;
V_65:
F_39 ( V_4 -> V_22 ) ;
V_52:
F_40 ( V_4 -> V_10 ) ;
V_51:
F_41 ( V_43 -> V_49 , F_25 ( V_43 ) ) ;
V_48:
F_42 ( V_5 ) ;
F_43 ( V_4 ) ;
return error ;
}
static int T_6 F_44 ( struct V_30 * V_31 )
{
struct V_3 * V_4 = F_45 ( V_31 ) ;
F_38 ( V_4 -> V_1 , V_4 ) ;
F_46 ( V_4 -> V_6 ) ;
F_39 ( V_4 -> V_22 ) ;
F_40 ( V_4 -> V_10 ) ;
F_41 ( V_4 -> V_43 -> V_49 , F_25 ( V_4 -> V_43 ) ) ;
F_43 ( V_4 ) ;
F_36 ( & V_31 -> V_21 , 1 ) ;
F_37 ( V_31 , NULL ) ;
return 0 ;
}
static int F_47 ( struct V_69 * V_21 )
{
struct V_30 * V_31 = F_48 ( V_21 ) ;
struct V_3 * V_4 = F_45 ( V_31 ) ;
struct V_5 * V_5 = V_4 -> V_6 ;
F_49 ( & V_5 -> V_70 ) ;
if ( V_5 -> V_71 )
F_9 ( V_4 -> V_22 ) ;
if ( F_50 ( & V_31 -> V_21 ) )
F_51 ( V_4 -> V_1 ) ;
F_52 ( & V_5 -> V_70 ) ;
return 0 ;
}
static int F_53 ( struct V_69 * V_21 )
{
struct V_30 * V_31 = F_48 ( V_21 ) ;
struct V_3 * V_4 = F_45 ( V_31 ) ;
struct V_5 * V_5 = V_4 -> V_6 ;
F_49 ( & V_5 -> V_70 ) ;
if ( F_50 ( & V_31 -> V_21 ) )
F_54 ( V_4 -> V_1 ) ;
if ( V_5 -> V_71 )
F_9 ( V_4 -> V_22 ) ;
F_52 ( & V_5 -> V_70 ) ;
return 0 ;
}
