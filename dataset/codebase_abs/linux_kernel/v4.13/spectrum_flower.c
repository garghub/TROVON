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
V_11 = F_10 ( V_5 ) ;
if ( V_11 )
return V_11 ;
} else if ( F_11 ( V_9 ) ) {
int V_12 = F_12 ( V_9 ) ;
struct V_2 * V_13 ;
struct V_14 * V_15 ;
T_1 V_16 ;
V_15 = F_13 ( V_1 ) ;
V_16 = F_14 ( V_15 ) ;
V_11 = F_15 ( V_1 , V_5 ,
V_16 ) ;
if ( V_11 )
return V_11 ;
V_13 = F_16 ( F_17 ( V_3 ) , V_12 ) ;
if ( V_13 == V_3 )
V_13 = NULL ;
V_11 = F_18 ( V_1 , V_5 ,
V_13 ) ;
if ( V_11 )
return V_11 ;
} else if ( F_19 ( V_9 ) ) {
T_1 V_17 = F_20 ( F_21 ( V_9 ) ) ;
T_2 V_18 = F_22 ( V_9 ) ;
T_3 V_19 = F_23 ( V_9 ) ;
T_1 V_20 = F_24 ( V_9 ) ;
return F_25 ( V_1 , V_5 ,
V_18 , V_20 ,
V_17 , V_19 ) ;
} else {
F_26 ( V_1 -> V_21 -> V_3 , L_1 ) ;
return - V_22 ;
}
}
return 0 ;
}
static void F_27 ( struct V_4 * V_5 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 =
F_28 ( V_24 -> V_27 ,
V_28 ,
V_24 -> V_26 ) ;
struct V_25 * V_29 =
F_28 ( V_24 -> V_27 ,
V_28 ,
V_24 -> V_29 ) ;
F_29 ( V_5 , V_30 ,
F_30 ( V_26 -> V_31 ) , F_30 ( V_29 -> V_31 ) ) ;
F_29 ( V_5 , V_32 ,
F_30 ( V_26 -> V_33 ) , F_30 ( V_29 -> V_33 ) ) ;
}
static void F_31 ( struct V_4 * V_5 ,
struct V_23 * V_24 )
{
struct V_34 * V_26 =
F_28 ( V_24 -> V_27 ,
V_35 ,
V_24 -> V_26 ) ;
struct V_34 * V_29 =
F_28 ( V_24 -> V_27 ,
V_35 ,
V_24 -> V_29 ) ;
T_4 V_36 = sizeof( V_26 -> V_31 ) / 2 ;
F_32 ( V_5 , V_37 ,
& V_26 -> V_31 . V_38 [ 0 ] ,
& V_29 -> V_31 . V_38 [ 0 ] ,
V_36 ) ;
F_32 ( V_5 , V_39 ,
& V_26 -> V_31 . V_38 [ V_36 ] ,
& V_29 -> V_31 . V_38 [ V_36 ] ,
V_36 ) ;
F_32 ( V_5 , V_40 ,
& V_26 -> V_33 . V_38 [ 0 ] ,
& V_29 -> V_33 . V_38 [ 0 ] ,
V_36 ) ;
F_32 ( V_5 , V_41 ,
& V_26 -> V_33 . V_38 [ V_36 ] ,
& V_29 -> V_33 . V_38 [ V_36 ] ,
V_36 ) ;
}
static int F_33 ( struct V_1 * V_1 ,
struct V_4 * V_5 ,
struct V_23 * V_24 ,
T_3 V_42 )
{
struct V_43 * V_26 , * V_29 ;
if ( ! F_34 ( V_24 -> V_27 , V_44 ) )
return 0 ;
if ( V_42 != V_45 && V_42 != V_46 ) {
F_26 ( V_1 -> V_21 -> V_3 , L_2 ) ;
return - V_47 ;
}
V_26 = F_28 ( V_24 -> V_27 ,
V_44 ,
V_24 -> V_26 ) ;
V_29 = F_28 ( V_24 -> V_27 ,
V_44 ,
V_24 -> V_29 ) ;
F_29 ( V_5 , V_48 ,
F_35 ( V_26 -> V_33 ) , F_35 ( V_29 -> V_33 ) ) ;
F_29 ( V_5 , V_49 ,
F_35 ( V_26 -> V_31 ) , F_35 ( V_29 -> V_31 ) ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_1 ,
struct V_4 * V_5 ,
struct V_23 * V_24 ,
T_3 V_42 )
{
struct V_50 * V_26 , * V_29 ;
if ( ! F_34 ( V_24 -> V_27 , V_51 ) )
return 0 ;
if ( V_42 != V_45 ) {
F_26 ( V_1 -> V_21 -> V_3 , L_3 ) ;
return - V_47 ;
}
V_26 = F_28 ( V_24 -> V_27 ,
V_51 ,
V_24 -> V_26 ) ;
V_29 = F_28 ( V_24 -> V_27 ,
V_51 ,
V_24 -> V_29 ) ;
F_29 ( V_5 , V_52 ,
F_35 ( V_26 -> V_53 ) , F_35 ( V_29 -> V_53 ) ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_23 * V_24 )
{
T_1 V_54 = 0 ;
T_3 V_42 = 0 ;
int V_11 ;
if ( V_24 -> V_27 -> V_55 &
~ ( F_38 ( V_56 ) |
F_38 ( V_57 ) |
F_38 ( V_58 ) |
F_38 ( V_28 ) |
F_38 ( V_35 ) |
F_38 ( V_44 ) |
F_38 ( V_51 ) |
F_38 ( V_59 ) ) ) {
F_26 ( V_1 -> V_21 -> V_3 , L_4 ) ;
return - V_22 ;
}
F_39 ( V_5 , V_24 -> V_19 ) ;
if ( F_34 ( V_24 -> V_27 , V_56 ) ) {
struct V_60 * V_26 =
F_28 ( V_24 -> V_27 ,
V_56 ,
V_24 -> V_26 ) ;
V_54 = V_26 -> V_54 ;
}
if ( F_34 ( V_24 -> V_27 , V_57 ) ) {
struct V_61 * V_26 =
F_28 ( V_24 -> V_27 ,
V_57 ,
V_24 -> V_26 ) ;
struct V_61 * V_29 =
F_28 ( V_24 -> V_27 ,
V_57 ,
V_24 -> V_29 ) ;
T_1 V_62 = F_35 ( V_26 -> V_63 ) ;
T_1 V_64 = F_35 ( V_29 -> V_63 ) ;
if ( V_62 == V_65 ) {
V_62 = 0 ;
V_64 = 0 ;
}
F_29 ( V_5 ,
V_66 ,
V_62 , V_64 ) ;
V_42 = V_26 -> V_42 ;
F_29 ( V_5 ,
V_67 ,
V_26 -> V_42 , V_29 -> V_42 ) ;
}
if ( F_34 ( V_24 -> V_27 , V_58 ) ) {
struct V_68 * V_26 =
F_28 ( V_24 -> V_27 ,
V_58 ,
V_24 -> V_26 ) ;
struct V_68 * V_29 =
F_28 ( V_24 -> V_27 ,
V_58 ,
V_24 -> V_29 ) ;
F_32 ( V_5 ,
V_69 ,
V_26 -> V_33 , V_29 -> V_33 ,
sizeof( V_26 -> V_33 ) ) ;
F_32 ( V_5 ,
V_70 ,
V_26 -> V_31 , V_29 -> V_31 ,
sizeof( V_26 -> V_31 ) ) ;
}
if ( F_34 ( V_24 -> V_27 , V_59 ) ) {
struct V_71 * V_26 =
F_28 ( V_24 -> V_27 ,
V_59 ,
V_24 -> V_26 ) ;
struct V_71 * V_29 =
F_28 ( V_24 -> V_27 ,
V_59 ,
V_24 -> V_29 ) ;
if ( V_29 -> V_72 != 0 )
F_29 ( V_5 ,
V_73 ,
V_26 -> V_72 ,
V_29 -> V_72 ) ;
if ( V_29 -> V_74 != 0 )
F_29 ( V_5 ,
V_75 ,
V_26 -> V_74 ,
V_29 -> V_74 ) ;
}
if ( V_54 == V_28 )
F_27 ( V_5 , V_24 ) ;
if ( V_54 == V_35 )
F_31 ( V_5 , V_24 ) ;
V_11 = F_33 ( V_1 , V_5 , V_24 , V_42 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_36 ( V_1 , V_5 , V_24 , V_42 ) ;
if ( V_11 )
return V_11 ;
return F_1 ( V_1 , V_3 , V_5 , V_24 -> V_7 ) ;
}
int F_40 ( struct V_76 * V_76 , bool V_77 ,
T_5 V_78 , struct V_23 * V_24 )
{
struct V_1 * V_1 = V_76 -> V_1 ;
struct V_2 * V_3 = V_76 -> V_3 ;
struct V_4 * V_5 ;
struct V_79 * V_80 ;
struct V_81 * V_82 ;
int V_11 ;
V_80 = F_41 ( V_1 , V_3 , V_77 ,
V_83 ) ;
if ( F_42 ( V_80 ) )
return F_43 ( V_80 ) ;
V_82 = F_44 ( V_1 , V_80 , V_24 -> V_84 ) ;
if ( F_42 ( V_82 ) ) {
V_11 = F_43 ( V_82 ) ;
goto V_85;
}
V_5 = F_45 ( V_82 ) ;
V_11 = F_37 ( V_1 , V_3 , V_5 , V_24 ) ;
if ( V_11 )
goto V_86;
V_11 = F_46 ( V_5 ) ;
if ( V_11 )
goto V_87;
V_11 = F_47 ( V_1 , V_82 ) ;
if ( V_11 )
goto V_88;
F_48 ( V_1 , V_80 ) ;
return 0 ;
V_88:
V_87:
V_86:
F_49 ( V_1 , V_82 ) ;
V_85:
F_48 ( V_1 , V_80 ) ;
return V_11 ;
}
void F_50 ( struct V_76 * V_76 , bool V_77 ,
struct V_23 * V_24 )
{
struct V_1 * V_1 = V_76 -> V_1 ;
struct V_79 * V_80 ;
struct V_81 * V_82 ;
V_80 = F_41 ( V_1 , V_76 -> V_3 ,
V_77 ,
V_83 ) ;
if ( F_42 ( V_80 ) )
return;
V_82 = F_51 ( V_1 , V_80 , V_24 -> V_84 ) ;
if ( V_82 ) {
F_52 ( V_1 , V_82 ) ;
F_49 ( V_1 , V_82 ) ;
}
F_48 ( V_1 , V_80 ) ;
}
int F_53 ( struct V_76 * V_76 , bool V_77 ,
struct V_23 * V_24 )
{
struct V_1 * V_1 = V_76 -> V_1 ;
struct V_79 * V_80 ;
struct V_81 * V_82 ;
T_6 V_89 ;
T_6 V_90 ;
T_6 V_91 ;
int V_11 ;
V_80 = F_41 ( V_1 , V_76 -> V_3 ,
V_77 ,
V_83 ) ;
if ( F_54 ( F_42 ( V_80 ) ) )
return - V_47 ;
V_82 = F_51 ( V_1 , V_80 , V_24 -> V_84 ) ;
if ( ! V_82 )
return - V_47 ;
V_11 = F_55 ( V_1 , V_82 , & V_89 , & V_91 ,
& V_90 ) ;
if ( V_11 )
goto V_92;
F_56 ( V_24 -> V_7 , V_91 , V_89 , V_90 ) ;
F_48 ( V_1 , V_80 ) ;
return 0 ;
V_92:
F_48 ( V_1 , V_80 ) ;
return V_11 ;
}
