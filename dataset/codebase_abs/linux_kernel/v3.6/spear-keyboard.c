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
static int T_3 F_13 ( struct V_33 * V_34 ,
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
static int T_3 F_17 ( struct V_33 * V_34 )
{
struct V_42 * V_43 = F_18 ( & V_34 -> V_23 ) ;
const struct V_44 * V_45 = V_43 ? V_43 -> V_45 : NULL ;
struct V_3 * V_4 ;
struct V_5 * V_5 ;
struct V_46 * V_47 ;
int V_1 ;
int error ;
V_47 = F_19 ( V_34 , V_48 , 0 ) ;
if ( ! V_47 ) {
F_14 ( & V_34 -> V_23 , L_6 ) ;
return - V_49 ;
}
V_1 = F_20 ( V_34 , 0 ) ;
if ( V_1 < 0 ) {
F_14 ( & V_34 -> V_23 , L_7 ) ;
return V_1 ;
}
V_4 = F_21 ( sizeof( * V_4 ) , V_50 ) ;
V_5 = F_22 () ;
if ( ! V_4 || ! V_5 ) {
F_14 ( & V_34 -> V_23 , L_8 ) ;
error = - V_51 ;
goto V_52;
}
V_4 -> V_6 = V_5 ;
V_4 -> V_1 = V_1 ;
if ( ! V_43 ) {
error = F_13 ( V_34 , V_4 ) ;
if ( error )
goto V_52;
} else {
V_4 -> V_29 = V_43 -> V_29 ;
V_4 -> V_40 = V_43 -> V_40 ;
V_4 -> V_38 = V_43 -> V_38 ;
}
V_4 -> V_47 = F_23 ( V_47 -> V_53 , F_24 ( V_47 ) ,
V_34 -> V_54 ) ;
if ( ! V_4 -> V_47 ) {
F_14 ( & V_34 -> V_23 , L_9 ) ;
error = - V_49 ;
goto V_52;
}
V_4 -> V_10 = F_25 ( V_47 -> V_53 , F_24 ( V_47 ) ) ;
if ( ! V_4 -> V_10 ) {
F_14 ( & V_34 -> V_23 , L_10 ) ;
error = - V_51 ;
goto V_55;
}
V_4 -> V_24 = F_26 ( & V_34 -> V_23 , NULL ) ;
if ( F_27 ( V_4 -> V_24 ) ) {
error = F_28 ( V_4 -> V_24 ) ;
goto V_56;
}
V_5 -> V_54 = L_11 ;
V_5 -> V_57 = L_12 ;
V_5 -> V_23 . V_58 = & V_34 -> V_23 ;
V_5 -> V_59 . V_60 = V_61 ;
V_5 -> V_59 . V_62 = 0x0001 ;
V_5 -> V_59 . V_63 = 0x0001 ;
V_5 -> V_59 . V_64 = 0x0100 ;
V_5 -> V_65 = F_7 ;
V_5 -> V_66 = F_11 ;
error = F_29 ( V_45 , NULL , V_67 , V_68 ,
V_4 -> V_19 , V_5 ) ;
if ( error ) {
F_14 ( & V_34 -> V_23 , L_13 ) ;
goto V_69;
}
if ( V_4 -> V_40 )
F_30 ( V_70 , V_5 -> V_71 ) ;
F_31 ( V_5 , V_20 , V_21 ) ;
F_32 ( V_5 , V_4 ) ;
error = F_33 ( V_1 , F_1 , 0 , L_14 , V_4 ) ;
if ( error ) {
F_14 ( & V_34 -> V_23 , L_15 ) ;
goto V_69;
}
error = F_34 ( V_5 ) ;
if ( error ) {
F_14 ( & V_34 -> V_23 , L_16 ) ;
goto V_72;
}
F_35 ( & V_34 -> V_23 , 1 ) ;
F_36 ( V_34 , V_4 ) ;
return 0 ;
V_72:
F_37 ( V_4 -> V_1 , V_4 ) ;
V_69:
F_38 ( V_4 -> V_24 ) ;
V_56:
F_39 ( V_4 -> V_10 ) ;
V_55:
F_40 ( V_47 -> V_53 , F_24 ( V_47 ) ) ;
V_52:
F_41 ( V_5 ) ;
F_42 ( V_4 ) ;
return error ;
}
static int T_4 F_43 ( struct V_33 * V_34 )
{
struct V_3 * V_4 = F_44 ( V_34 ) ;
F_37 ( V_4 -> V_1 , V_4 ) ;
F_45 ( V_4 -> V_6 ) ;
F_38 ( V_4 -> V_24 ) ;
F_39 ( V_4 -> V_10 ) ;
F_40 ( V_4 -> V_47 -> V_53 , F_24 ( V_4 -> V_47 ) ) ;
F_42 ( V_4 ) ;
F_35 ( & V_34 -> V_23 , 0 ) ;
F_36 ( V_34 , NULL ) ;
return 0 ;
}
static int F_46 ( struct V_73 * V_23 )
{
struct V_33 * V_34 = F_47 ( V_23 ) ;
struct V_3 * V_4 = F_44 ( V_34 ) ;
struct V_5 * V_5 = V_4 -> V_6 ;
unsigned int V_74 = 0 , V_75 , V_9 ;
F_48 ( & V_5 -> V_76 ) ;
F_9 ( V_4 -> V_24 ) ;
V_75 = F_2 ( V_4 -> V_10 + V_31 ) ;
if ( F_49 ( & V_34 -> V_23 ) ) {
F_50 ( V_4 -> V_1 ) ;
if ( V_4 -> V_38 )
V_74 = V_4 -> V_38 / 1000000 - 1 ;
else
V_74 = F_10 ( V_4 -> V_24 ) / 1000000 - 1 ;
V_9 = V_75 &
~ ( V_25 << V_26 ) ;
V_9 |= ( V_74 & V_25 )
<< V_26 ;
F_6 ( V_9 , V_4 -> V_10 + V_31 ) ;
} else {
if ( V_5 -> V_77 ) {
F_6 ( V_75 & ~ V_32 ,
V_4 -> V_10 + V_31 ) ;
F_12 ( V_4 -> V_24 ) ;
}
}
if ( V_5 -> V_77 )
V_4 -> V_75 = V_75 ;
F_12 ( V_4 -> V_24 ) ;
F_51 ( & V_5 -> V_76 ) ;
return 0 ;
}
static int F_52 ( struct V_73 * V_23 )
{
struct V_33 * V_34 = F_47 ( V_23 ) ;
struct V_3 * V_4 = F_44 ( V_34 ) ;
struct V_5 * V_5 = V_4 -> V_6 ;
F_48 ( & V_5 -> V_76 ) ;
if ( F_49 ( & V_34 -> V_23 ) ) {
F_53 ( V_4 -> V_1 ) ;
} else {
if ( V_5 -> V_77 )
F_9 ( V_4 -> V_24 ) ;
}
if ( V_5 -> V_77 )
F_6 ( V_4 -> V_75 , V_4 -> V_10 + V_31 ) ;
F_51 ( & V_5 -> V_76 ) ;
return 0 ;
}
