static int F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 )
{
const struct V_8 * V_9 ;
F_2 ( V_10 ) ;
int V_11 ;
if ( F_3 ( V_7 ) )
return 0 ;
V_11 = F_4 ( V_1 , V_5 ) ;
if ( V_11 )
return V_11 ;
F_5 ( V_7 , & V_10 ) ;
F_6 (a, &actions, list) {
if ( F_7 ( V_9 ) ) {
V_11 = F_8 ( V_5 ) ;
if ( V_11 )
return V_11 ;
} else if ( F_9 ( V_9 ) ) {
int V_12 = F_10 ( V_9 ) ;
struct V_2 * V_13 ;
V_11 = F_11 ( V_1 , V_5 ,
V_14 ) ;
if ( V_11 )
return V_11 ;
V_13 = F_12 ( F_13 ( V_3 ) , V_12 ) ;
if ( V_13 == V_3 )
V_13 = NULL ;
V_11 = F_14 ( V_1 , V_5 ,
V_13 ) ;
if ( V_11 )
return V_11 ;
} else if ( F_15 ( V_9 ) ) {
T_1 V_15 = F_16 ( F_17 ( V_9 ) ) ;
T_2 V_16 = F_18 ( V_9 ) ;
T_3 V_17 = F_19 ( V_9 ) ;
T_1 V_18 = F_20 ( V_9 ) ;
return F_21 ( V_1 , V_5 ,
V_16 , V_18 ,
V_15 , V_17 ) ;
} else {
F_22 ( V_1 -> V_19 -> V_3 , L_1 ) ;
return - V_20 ;
}
}
return 0 ;
}
static void F_23 ( struct V_4 * V_5 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 =
F_24 ( V_22 -> V_25 ,
V_26 ,
V_22 -> V_24 ) ;
struct V_23 * V_27 =
F_24 ( V_22 -> V_25 ,
V_26 ,
V_22 -> V_27 ) ;
F_25 ( V_5 , V_28 ,
F_26 ( V_24 -> V_29 ) , F_26 ( V_27 -> V_29 ) ) ;
F_25 ( V_5 , V_30 ,
F_26 ( V_24 -> V_31 ) , F_26 ( V_27 -> V_31 ) ) ;
}
static void F_27 ( struct V_4 * V_5 ,
struct V_21 * V_22 )
{
struct V_32 * V_24 =
F_24 ( V_22 -> V_25 ,
V_33 ,
V_22 -> V_24 ) ;
struct V_32 * V_27 =
F_24 ( V_22 -> V_25 ,
V_33 ,
V_22 -> V_27 ) ;
T_4 V_34 = sizeof( V_24 -> V_29 ) / 2 ;
F_28 ( V_5 , V_35 ,
& V_24 -> V_29 . V_36 [ 0 ] ,
& V_27 -> V_29 . V_36 [ 0 ] ,
V_34 ) ;
F_28 ( V_5 , V_37 ,
& V_24 -> V_29 . V_36 [ V_34 ] ,
& V_27 -> V_29 . V_36 [ V_34 ] ,
V_34 ) ;
F_28 ( V_5 , V_38 ,
& V_24 -> V_31 . V_36 [ 0 ] ,
& V_27 -> V_31 . V_36 [ 0 ] ,
V_34 ) ;
F_28 ( V_5 , V_39 ,
& V_24 -> V_31 . V_36 [ V_34 ] ,
& V_27 -> V_31 . V_36 [ V_34 ] ,
V_34 ) ;
}
static int F_29 ( struct V_1 * V_1 ,
struct V_4 * V_5 ,
struct V_21 * V_22 ,
T_3 V_40 )
{
struct V_41 * V_24 , * V_27 ;
if ( ! F_30 ( V_22 -> V_25 , V_42 ) )
return 0 ;
if ( V_40 != V_43 && V_40 != V_44 ) {
F_22 ( V_1 -> V_19 -> V_3 , L_2 ) ;
return - V_45 ;
}
V_24 = F_24 ( V_22 -> V_25 ,
V_42 ,
V_22 -> V_24 ) ;
V_27 = F_24 ( V_22 -> V_25 ,
V_42 ,
V_22 -> V_27 ) ;
F_25 ( V_5 , V_46 ,
F_31 ( V_24 -> V_31 ) , F_31 ( V_27 -> V_31 ) ) ;
F_25 ( V_5 , V_47 ,
F_31 ( V_24 -> V_29 ) , F_31 ( V_27 -> V_29 ) ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_21 * V_22 )
{
T_1 V_48 = 0 ;
T_3 V_40 = 0 ;
int V_11 ;
if ( V_22 -> V_25 -> V_49 &
~ ( F_33 ( V_50 ) |
F_33 ( V_51 ) |
F_33 ( V_52 ) |
F_33 ( V_26 ) |
F_33 ( V_33 ) |
F_33 ( V_42 ) |
F_33 ( V_53 ) ) ) {
F_22 ( V_1 -> V_19 -> V_3 , L_3 ) ;
return - V_20 ;
}
F_34 ( V_5 , V_22 -> V_17 ) ;
if ( F_30 ( V_22 -> V_25 , V_50 ) ) {
struct V_54 * V_24 =
F_24 ( V_22 -> V_25 ,
V_50 ,
V_22 -> V_24 ) ;
V_48 = V_24 -> V_48 ;
}
if ( F_30 ( V_22 -> V_25 , V_51 ) ) {
struct V_55 * V_24 =
F_24 ( V_22 -> V_25 ,
V_51 ,
V_22 -> V_24 ) ;
struct V_55 * V_27 =
F_24 ( V_22 -> V_25 ,
V_51 ,
V_22 -> V_27 ) ;
T_1 V_56 = F_31 ( V_24 -> V_57 ) ;
T_1 V_58 = F_31 ( V_27 -> V_57 ) ;
if ( V_56 == V_59 ) {
V_56 = 0 ;
V_58 = 0 ;
}
F_25 ( V_5 ,
V_60 ,
V_56 , V_58 ) ;
V_40 = V_24 -> V_40 ;
F_25 ( V_5 ,
V_61 ,
V_24 -> V_40 , V_27 -> V_40 ) ;
}
if ( F_30 ( V_22 -> V_25 , V_52 ) ) {
struct V_62 * V_24 =
F_24 ( V_22 -> V_25 ,
V_52 ,
V_22 -> V_24 ) ;
struct V_62 * V_27 =
F_24 ( V_22 -> V_25 ,
V_52 ,
V_22 -> V_27 ) ;
F_28 ( V_5 ,
V_63 ,
V_24 -> V_31 , V_27 -> V_31 ,
sizeof( V_24 -> V_31 ) ) ;
F_28 ( V_5 ,
V_64 ,
V_24 -> V_29 , V_27 -> V_29 ,
sizeof( V_24 -> V_29 ) ) ;
}
if ( F_30 ( V_22 -> V_25 , V_53 ) ) {
struct V_65 * V_24 =
F_24 ( V_22 -> V_25 ,
V_53 ,
V_22 -> V_24 ) ;
struct V_65 * V_27 =
F_24 ( V_22 -> V_25 ,
V_53 ,
V_22 -> V_27 ) ;
if ( V_27 -> V_66 != 0 )
F_25 ( V_5 ,
V_67 ,
V_24 -> V_66 ,
V_27 -> V_66 ) ;
if ( V_27 -> V_68 != 0 )
F_25 ( V_5 ,
V_69 ,
V_24 -> V_68 ,
V_27 -> V_68 ) ;
}
if ( V_48 == V_26 )
F_23 ( V_5 , V_22 ) ;
if ( V_48 == V_33 )
F_27 ( V_5 , V_22 ) ;
V_11 = F_29 ( V_1 , V_5 , V_22 , V_40 ) ;
if ( V_11 )
return V_11 ;
return F_1 ( V_1 , V_3 , V_5 , V_22 -> V_7 ) ;
}
int F_35 ( struct V_70 * V_70 , bool V_71 ,
T_5 V_72 , struct V_21 * V_22 )
{
struct V_1 * V_1 = V_70 -> V_1 ;
struct V_2 * V_3 = V_70 -> V_3 ;
struct V_4 * V_5 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
int V_11 ;
V_74 = F_36 ( V_1 , V_3 , V_71 ,
V_77 ) ;
if ( F_37 ( V_74 ) )
return F_38 ( V_74 ) ;
V_76 = F_39 ( V_1 , V_74 , V_22 -> V_78 ) ;
if ( F_37 ( V_76 ) ) {
V_11 = F_38 ( V_76 ) ;
goto V_79;
}
V_5 = F_40 ( V_76 ) ;
V_11 = F_32 ( V_1 , V_3 , V_5 , V_22 ) ;
if ( V_11 )
goto V_80;
V_11 = F_41 ( V_5 ) ;
if ( V_11 )
goto V_81;
V_11 = F_42 ( V_1 , V_76 ) ;
if ( V_11 )
goto V_82;
F_43 ( V_1 , V_74 ) ;
return 0 ;
V_82:
V_81:
V_80:
F_44 ( V_1 , V_76 ) ;
V_79:
F_43 ( V_1 , V_74 ) ;
return V_11 ;
}
void F_45 ( struct V_70 * V_70 , bool V_71 ,
struct V_21 * V_22 )
{
struct V_1 * V_1 = V_70 -> V_1 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
V_74 = F_36 ( V_1 , V_70 -> V_3 ,
V_71 ,
V_77 ) ;
if ( F_37 ( V_74 ) )
return;
V_76 = F_46 ( V_1 , V_74 , V_22 -> V_78 ) ;
if ( V_76 ) {
F_47 ( V_1 , V_76 ) ;
F_44 ( V_1 , V_76 ) ;
}
F_43 ( V_1 , V_74 ) ;
}
int F_48 ( struct V_70 * V_70 , bool V_71 ,
struct V_21 * V_22 )
{
struct V_1 * V_1 = V_70 -> V_1 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
struct V_8 * V_9 ;
F_2 ( V_10 ) ;
T_6 V_83 ;
T_6 V_84 ;
T_6 V_85 ;
int V_11 ;
V_74 = F_36 ( V_1 , V_70 -> V_3 ,
V_71 ,
V_77 ) ;
if ( F_49 ( F_37 ( V_74 ) ) )
return - V_45 ;
V_76 = F_46 ( V_1 , V_74 , V_22 -> V_78 ) ;
if ( ! V_76 )
return - V_45 ;
V_11 = F_50 ( V_1 , V_76 , & V_83 , & V_85 ,
& V_84 ) ;
if ( V_11 )
goto V_86;
F_51 () ;
F_5 ( V_22 -> V_7 , & V_10 ) ;
F_6 (a, &actions, list)
F_52 ( V_9 , V_85 , V_83 , V_84 ) ;
F_53 () ;
F_43 ( V_1 , V_74 ) ;
return 0 ;
V_86:
F_43 ( V_1 , V_74 ) ;
return V_11 ;
}
