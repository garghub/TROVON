static int F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 , bool V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
const struct V_9 * V_10 ;
F_2 ( V_11 ) ;
int V_12 ;
if ( ! F_3 ( V_8 ) )
return 0 ;
V_12 = F_4 ( V_1 , V_6 ) ;
if ( V_12 )
return V_12 ;
F_5 ( V_8 , & V_11 ) ;
F_6 (a, &actions, list) {
if ( F_7 ( V_10 ) ) {
V_12 = F_8 ( V_6 ) ;
if ( V_12 )
return V_12 ;
} else if ( F_9 ( V_10 ) ) {
V_12 = F_10 ( V_6 ) ;
if ( V_12 )
return V_12 ;
} else if ( F_11 ( V_10 ) ) {
T_1 V_13 = F_12 ( V_10 ) ;
struct V_14 * V_15 ;
T_2 V_16 ;
V_15 = F_13 ( V_1 , V_3 ,
V_4 ,
V_13 ,
V_17 ) ;
if ( F_14 ( V_15 ) )
return F_15 ( V_15 ) ;
V_16 = F_16 ( V_15 ) ;
F_17 ( V_6 , V_16 ) ;
} else if ( F_18 ( V_10 ) ) {
int V_18 = F_19 ( V_10 ) ;
struct V_2 * V_19 ;
struct V_20 * V_21 ;
T_2 V_22 ;
V_21 = F_20 ( V_1 ) ;
V_22 = F_21 ( V_21 ) ;
V_12 = F_22 ( V_1 , V_6 ,
V_22 ) ;
if ( V_12 )
return V_12 ;
V_19 = F_23 ( F_24 ( V_3 ) , V_18 ) ;
if ( V_19 == V_3 )
V_19 = NULL ;
V_12 = F_25 ( V_1 , V_6 ,
V_19 ) ;
if ( V_12 )
return V_12 ;
} else if ( F_26 ( V_10 ) ) {
T_2 V_23 = F_27 ( F_28 ( V_10 ) ) ;
T_1 V_24 = F_29 ( V_10 ) ;
T_3 V_25 = F_30 ( V_10 ) ;
T_2 V_26 = F_31 ( V_10 ) ;
return F_32 ( V_1 , V_6 ,
V_24 , V_26 ,
V_23 , V_25 ) ;
} else {
F_33 ( V_1 -> V_27 -> V_3 , L_1 ) ;
return - V_28 ;
}
}
return 0 ;
}
static void F_34 ( struct V_5 * V_6 ,
struct V_29 * V_30 )
{
struct V_31 * V_32 =
F_35 ( V_30 -> V_33 ,
V_34 ,
V_30 -> V_32 ) ;
struct V_31 * V_35 =
F_35 ( V_30 -> V_33 ,
V_34 ,
V_30 -> V_35 ) ;
F_36 ( V_6 , V_36 ,
F_37 ( V_32 -> V_37 ) , F_37 ( V_35 -> V_37 ) ) ;
F_36 ( V_6 , V_38 ,
F_37 ( V_32 -> V_39 ) , F_37 ( V_35 -> V_39 ) ) ;
}
static void F_38 ( struct V_5 * V_6 ,
struct V_29 * V_30 )
{
struct V_40 * V_32 =
F_35 ( V_30 -> V_33 ,
V_41 ,
V_30 -> V_32 ) ;
struct V_40 * V_35 =
F_35 ( V_30 -> V_33 ,
V_41 ,
V_30 -> V_35 ) ;
T_4 V_42 = sizeof( V_32 -> V_37 ) / 2 ;
F_39 ( V_6 , V_43 ,
& V_32 -> V_37 . V_44 [ 0 ] ,
& V_35 -> V_37 . V_44 [ 0 ] ,
V_42 ) ;
F_39 ( V_6 , V_45 ,
& V_32 -> V_37 . V_44 [ V_42 ] ,
& V_35 -> V_37 . V_44 [ V_42 ] ,
V_42 ) ;
F_39 ( V_6 , V_46 ,
& V_32 -> V_39 . V_44 [ 0 ] ,
& V_35 -> V_39 . V_44 [ 0 ] ,
V_42 ) ;
F_39 ( V_6 , V_47 ,
& V_32 -> V_39 . V_44 [ V_42 ] ,
& V_35 -> V_39 . V_44 [ V_42 ] ,
V_42 ) ;
}
static int F_40 ( struct V_1 * V_1 ,
struct V_5 * V_6 ,
struct V_29 * V_30 ,
T_3 V_48 )
{
struct V_49 * V_32 , * V_35 ;
if ( ! F_41 ( V_30 -> V_33 , V_50 ) )
return 0 ;
if ( V_48 != V_51 && V_48 != V_52 ) {
F_33 ( V_1 -> V_27 -> V_3 , L_2 ) ;
return - V_53 ;
}
V_32 = F_35 ( V_30 -> V_33 ,
V_50 ,
V_30 -> V_32 ) ;
V_35 = F_35 ( V_30 -> V_33 ,
V_50 ,
V_30 -> V_35 ) ;
F_36 ( V_6 , V_54 ,
F_42 ( V_32 -> V_39 ) , F_42 ( V_35 -> V_39 ) ) ;
F_36 ( V_6 , V_55 ,
F_42 ( V_32 -> V_37 ) , F_42 ( V_35 -> V_37 ) ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_1 ,
struct V_5 * V_6 ,
struct V_29 * V_30 ,
T_3 V_48 )
{
struct V_56 * V_32 , * V_35 ;
if ( ! F_41 ( V_30 -> V_33 , V_57 ) )
return 0 ;
if ( V_48 != V_51 ) {
F_33 ( V_1 -> V_27 -> V_3 , L_3 ) ;
return - V_53 ;
}
V_32 = F_35 ( V_30 -> V_33 ,
V_57 ,
V_30 -> V_32 ) ;
V_35 = F_35 ( V_30 -> V_33 ,
V_57 ,
V_30 -> V_35 ) ;
F_36 ( V_6 , V_58 ,
F_42 ( V_32 -> V_59 ) , F_42 ( V_35 -> V_59 ) ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_1 ,
struct V_5 * V_6 ,
struct V_29 * V_30 ,
T_2 V_60 )
{
struct V_61 * V_32 , * V_35 ;
if ( ! F_41 ( V_30 -> V_33 , V_62 ) )
return 0 ;
if ( V_60 != V_63 && V_60 != V_64 ) {
F_33 ( V_1 -> V_27 -> V_3 , L_4 ) ;
return - V_53 ;
}
V_32 = F_35 ( V_30 -> V_33 ,
V_62 ,
V_30 -> V_32 ) ;
V_35 = F_35 ( V_30 -> V_33 ,
V_62 ,
V_30 -> V_35 ) ;
F_36 ( V_6 , V_65 ,
V_32 -> V_66 , V_35 -> V_66 ) ;
F_36 ( V_6 , V_67 ,
V_32 -> V_68 & 0x3 , V_35 -> V_68 & 0x3 ) ;
F_36 ( V_6 , V_69 ,
V_32 -> V_68 >> 6 , V_35 -> V_68 >> 6 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_1 ,
struct V_2 * V_3 , bool V_4 ,
struct V_5 * V_6 ,
struct V_29 * V_30 )
{
T_2 V_70 = 0 ;
T_2 V_71 = 0 ;
T_2 V_72 = 0 ;
T_3 V_48 = 0 ;
int V_12 ;
if ( V_30 -> V_33 -> V_73 &
~ ( F_46 ( V_74 ) |
F_46 ( V_75 ) |
F_46 ( V_76 ) |
F_46 ( V_34 ) |
F_46 ( V_41 ) |
F_46 ( V_50 ) |
F_46 ( V_57 ) |
F_46 ( V_62 ) |
F_46 ( V_77 ) ) ) {
F_33 ( V_1 -> V_27 -> V_3 , L_5 ) ;
return - V_28 ;
}
F_47 ( V_6 , V_30 -> V_78 . V_25 ) ;
if ( F_41 ( V_30 -> V_33 , V_74 ) ) {
struct V_79 * V_32 =
F_35 ( V_30 -> V_33 ,
V_74 ,
V_30 -> V_32 ) ;
V_72 = V_32 -> V_72 ;
}
if ( F_41 ( V_30 -> V_33 , V_75 ) ) {
struct V_80 * V_32 =
F_35 ( V_30 -> V_33 ,
V_75 ,
V_30 -> V_32 ) ;
struct V_80 * V_35 =
F_35 ( V_30 -> V_33 ,
V_75 ,
V_30 -> V_35 ) ;
V_71 = F_42 ( V_32 -> V_60 ) ;
V_70 = F_42 ( V_35 -> V_60 ) ;
if ( V_71 == V_81 ) {
V_71 = 0 ;
V_70 = 0 ;
}
F_36 ( V_6 ,
V_82 ,
V_71 , V_70 ) ;
V_48 = V_32 -> V_48 ;
F_36 ( V_6 ,
V_83 ,
V_32 -> V_48 , V_35 -> V_48 ) ;
}
if ( F_41 ( V_30 -> V_33 , V_76 ) ) {
struct V_84 * V_32 =
F_35 ( V_30 -> V_33 ,
V_76 ,
V_30 -> V_32 ) ;
struct V_84 * V_35 =
F_35 ( V_30 -> V_33 ,
V_76 ,
V_30 -> V_35 ) ;
F_39 ( V_6 ,
V_85 ,
V_32 -> V_39 , V_35 -> V_39 ,
sizeof( V_32 -> V_39 ) ) ;
F_39 ( V_6 ,
V_86 ,
V_32 -> V_37 , V_35 -> V_37 ,
sizeof( V_32 -> V_37 ) ) ;
}
if ( F_41 ( V_30 -> V_33 , V_77 ) ) {
struct V_87 * V_32 =
F_35 ( V_30 -> V_33 ,
V_77 ,
V_30 -> V_32 ) ;
struct V_87 * V_35 =
F_35 ( V_30 -> V_33 ,
V_77 ,
V_30 -> V_35 ) ;
if ( V_35 -> V_88 != 0 )
F_36 ( V_6 ,
V_89 ,
V_32 -> V_88 ,
V_35 -> V_88 ) ;
if ( V_35 -> V_90 != 0 )
F_36 ( V_6 ,
V_91 ,
V_32 -> V_90 ,
V_35 -> V_90 ) ;
}
if ( V_72 == V_34 )
F_34 ( V_6 , V_30 ) ;
if ( V_72 == V_41 )
F_38 ( V_6 , V_30 ) ;
V_12 = F_40 ( V_1 , V_6 , V_30 , V_48 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_43 ( V_1 , V_6 , V_30 , V_48 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_44 ( V_1 , V_6 , V_30 , V_71 & V_70 ) ;
if ( V_12 )
return V_12 ;
return F_1 ( V_1 , V_3 , V_4 ,
V_6 , V_30 -> V_8 ) ;
}
int F_48 ( struct V_92 * V_92 , bool V_4 ,
struct V_29 * V_30 )
{
struct V_1 * V_1 = V_92 -> V_1 ;
struct V_2 * V_3 = V_92 -> V_3 ;
struct V_5 * V_6 ;
struct V_14 * V_15 ;
struct V_93 * V_94 ;
int V_12 ;
V_15 = F_49 ( V_1 , V_3 , V_4 ,
V_30 -> V_78 . V_13 ,
V_17 ) ;
if ( F_14 ( V_15 ) )
return F_15 ( V_15 ) ;
V_94 = F_50 ( V_1 , V_15 , V_30 -> V_95 ) ;
if ( F_14 ( V_94 ) ) {
V_12 = F_15 ( V_94 ) ;
goto V_96;
}
V_6 = F_51 ( V_94 ) ;
V_12 = F_45 ( V_1 , V_3 , V_4 , V_6 , V_30 ) ;
if ( V_12 )
goto V_97;
V_12 = F_52 ( V_6 ) ;
if ( V_12 )
goto V_98;
V_12 = F_53 ( V_1 , V_94 ) ;
if ( V_12 )
goto V_99;
F_54 ( V_1 , V_15 ) ;
return 0 ;
V_99:
V_98:
V_97:
F_55 ( V_1 , V_94 ) ;
V_96:
F_54 ( V_1 , V_15 ) ;
return V_12 ;
}
void F_56 ( struct V_92 * V_92 , bool V_4 ,
struct V_29 * V_30 )
{
struct V_1 * V_1 = V_92 -> V_1 ;
struct V_14 * V_15 ;
struct V_93 * V_94 ;
V_15 = F_49 ( V_1 , V_92 -> V_3 ,
V_4 , V_30 -> V_78 . V_13 ,
V_17 ) ;
if ( F_14 ( V_15 ) )
return;
V_94 = F_57 ( V_1 , V_15 , V_30 -> V_95 ) ;
if ( V_94 ) {
F_58 ( V_1 , V_94 ) ;
F_55 ( V_1 , V_94 ) ;
}
F_54 ( V_1 , V_15 ) ;
}
int F_59 ( struct V_92 * V_92 , bool V_4 ,
struct V_29 * V_30 )
{
struct V_1 * V_1 = V_92 -> V_1 ;
struct V_14 * V_15 ;
struct V_93 * V_94 ;
T_5 V_100 ;
T_5 V_101 ;
T_5 V_102 ;
int V_12 ;
V_15 = F_49 ( V_1 , V_92 -> V_3 ,
V_4 , V_30 -> V_78 . V_13 ,
V_17 ) ;
if ( F_60 ( F_14 ( V_15 ) ) )
return - V_53 ;
V_94 = F_57 ( V_1 , V_15 , V_30 -> V_95 ) ;
if ( ! V_94 )
return - V_53 ;
V_12 = F_61 ( V_1 , V_94 , & V_100 , & V_102 ,
& V_101 ) ;
if ( V_12 )
goto V_103;
F_62 ( V_30 -> V_8 , V_102 , V_100 , V_101 ) ;
F_54 ( V_1 , V_15 ) ;
return 0 ;
V_103:
F_54 ( V_1 , V_15 ) ;
return V_12 ;
}
