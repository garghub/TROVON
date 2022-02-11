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
V_9 = V_23 | V_24 | V_25 ;
F_10 ( V_9 , V_4 -> V_10 + V_26 ) ;
F_6 ( 1 , V_4 -> V_10 + V_11 ) ;
V_9 = F_11 ( V_4 -> V_10 + V_26 ) ;
V_9 |= V_27 ;
F_10 ( V_9 , V_4 -> V_10 + V_26 ) ;
return 0 ;
}
static void F_12 ( struct V_5 * V_21 )
{
struct V_3 * V_4 = F_8 ( V_21 ) ;
T_3 V_9 ;
V_9 = F_11 ( V_4 -> V_10 + V_26 ) ;
V_9 &= ~ V_27 ;
F_10 ( V_9 , V_4 -> V_10 + V_26 ) ;
F_13 ( V_4 -> V_22 ) ;
V_4 -> V_14 = V_15 ;
}
static int T_4 F_14 ( struct V_28 * V_29 )
{
const struct V_30 * V_31 = V_29 -> V_21 . V_32 ;
const struct V_33 * V_34 ;
struct V_3 * V_4 ;
struct V_5 * V_5 ;
struct V_35 * V_36 ;
int V_1 ;
int error ;
if ( ! V_31 ) {
F_15 ( & V_29 -> V_21 , L_1 ) ;
return - V_37 ;
}
V_34 = V_31 -> V_34 ;
if ( ! V_34 ) {
F_15 ( & V_29 -> V_21 , L_2 ) ;
return - V_37 ;
}
V_36 = F_16 ( V_29 , V_38 , 0 ) ;
if ( ! V_36 ) {
F_15 ( & V_29 -> V_21 , L_3 ) ;
return - V_39 ;
}
V_1 = F_17 ( V_29 , 0 ) ;
if ( V_1 < 0 ) {
F_15 ( & V_29 -> V_21 , L_4 ) ;
return V_1 ;
}
V_4 = F_18 ( sizeof( * V_4 ) , V_40 ) ;
V_5 = F_19 () ;
if ( ! V_4 || ! V_5 ) {
F_15 ( & V_29 -> V_21 , L_5 ) ;
error = - V_41 ;
goto V_42;
}
V_4 -> V_6 = V_5 ;
V_4 -> V_1 = V_1 ;
V_4 -> V_36 = F_20 ( V_36 -> V_43 , F_21 ( V_36 ) ,
V_29 -> V_44 ) ;
if ( ! V_4 -> V_36 ) {
F_15 ( & V_29 -> V_21 , L_6 ) ;
error = - V_39 ;
goto V_42;
}
V_4 -> V_10 = F_22 ( V_36 -> V_43 , F_21 ( V_36 ) ) ;
if ( ! V_4 -> V_10 ) {
F_15 ( & V_29 -> V_21 , L_7 ) ;
error = - V_41 ;
goto V_45;
}
V_4 -> V_22 = F_23 ( & V_29 -> V_21 , NULL ) ;
if ( F_24 ( V_4 -> V_22 ) ) {
error = F_25 ( V_4 -> V_22 ) ;
goto V_46;
}
V_5 -> V_44 = L_8 ;
V_5 -> V_47 = L_9 ;
V_5 -> V_21 . V_48 = & V_29 -> V_21 ;
V_5 -> V_49 . V_50 = V_51 ;
V_5 -> V_49 . V_52 = 0x0001 ;
V_5 -> V_49 . V_53 = 0x0001 ;
V_5 -> V_49 . V_54 = 0x0100 ;
V_5 -> V_55 = F_7 ;
V_5 -> V_56 = F_12 ;
F_26 ( V_57 , V_5 -> V_58 ) ;
if ( V_31 -> V_59 )
F_26 ( V_60 , V_5 -> V_58 ) ;
F_27 ( V_5 , V_18 , V_19 ) ;
V_5 -> V_61 = V_4 -> V_17 ;
V_5 -> V_62 = sizeof( V_4 -> V_17 [ 0 ] ) ;
V_5 -> V_63 = F_28 ( V_4 -> V_17 ) ;
F_29 ( V_34 , V_64 ,
V_5 -> V_61 , V_5 -> V_65 ) ;
F_30 ( V_5 , V_4 ) ;
error = F_31 ( V_1 , F_1 , 0 , L_10 , V_4 ) ;
if ( error ) {
F_15 ( & V_29 -> V_21 , L_11 ) ;
goto V_66;
}
error = F_32 ( V_5 ) ;
if ( error ) {
F_15 ( & V_29 -> V_21 , L_12 ) ;
goto V_67;
}
F_33 ( & V_29 -> V_21 , 1 ) ;
F_34 ( V_29 , V_4 ) ;
return 0 ;
V_67:
F_35 ( V_4 -> V_1 , V_4 ) ;
V_66:
F_36 ( V_4 -> V_22 ) ;
V_46:
F_37 ( V_4 -> V_10 ) ;
V_45:
F_38 ( V_36 -> V_43 , F_21 ( V_36 ) ) ;
V_42:
F_39 ( V_5 ) ;
F_40 ( V_4 ) ;
return error ;
}
static int T_5 F_41 ( struct V_28 * V_29 )
{
struct V_3 * V_4 = F_42 ( V_29 ) ;
F_35 ( V_4 -> V_1 , V_4 ) ;
F_43 ( V_4 -> V_6 ) ;
F_36 ( V_4 -> V_22 ) ;
F_37 ( V_4 -> V_10 ) ;
F_38 ( V_4 -> V_36 -> V_43 , F_21 ( V_4 -> V_36 ) ) ;
F_40 ( V_4 ) ;
F_33 ( & V_29 -> V_21 , 1 ) ;
F_34 ( V_29 , NULL ) ;
return 0 ;
}
static int F_44 ( struct V_68 * V_21 )
{
struct V_28 * V_29 = F_45 ( V_21 ) ;
struct V_3 * V_4 = F_42 ( V_29 ) ;
struct V_5 * V_5 = V_4 -> V_6 ;
F_46 ( & V_5 -> V_69 ) ;
if ( V_5 -> V_70 )
F_9 ( V_4 -> V_22 ) ;
if ( F_47 ( & V_29 -> V_21 ) )
F_48 ( V_4 -> V_1 ) ;
F_49 ( & V_5 -> V_69 ) ;
return 0 ;
}
static int F_50 ( struct V_68 * V_21 )
{
struct V_28 * V_29 = F_45 ( V_21 ) ;
struct V_3 * V_4 = F_42 ( V_29 ) ;
struct V_5 * V_5 = V_4 -> V_6 ;
F_46 ( & V_5 -> V_69 ) ;
if ( F_47 ( & V_29 -> V_21 ) )
F_51 ( V_4 -> V_1 ) ;
if ( V_5 -> V_70 )
F_9 ( V_4 -> V_22 ) ;
F_49 ( & V_5 -> V_69 ) ;
return 0 ;
}
static int T_6 F_52 ( void )
{
return F_53 ( & V_71 ) ;
}
static void T_7 F_54 ( void )
{
F_55 ( & V_71 ) ;
}
