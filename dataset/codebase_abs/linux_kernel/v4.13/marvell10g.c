static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 ,
T_1 V_5 , T_1 V_6 )
{
int V_7 , V_8 , V_9 ;
V_7 = F_2 ( V_2 , V_3 , V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
V_8 = ( V_7 & ~ V_5 ) | ( V_6 & V_5 ) ;
if ( V_8 == V_7 )
return 0 ;
V_9 = F_3 ( V_2 , V_3 , V_4 , V_8 ) ;
return V_9 < 0 ? V_9 : 1 ;
}
static int F_4 ( struct V_1 * V_2 )
{
T_2 V_10 = V_11 | V_12 ;
if ( ! V_2 -> V_13 ||
( V_2 -> V_14 . V_15 & V_10 ) != V_10 )
return - V_16 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_7 ( V_17 ) = { 0 , } ;
T_2 V_5 ;
int V_8 ;
if ( V_2 -> V_18 != V_19 &&
V_2 -> V_18 != V_20 &&
V_2 -> V_18 != V_21 &&
V_2 -> V_18 != V_22 &&
V_2 -> V_18 != V_23 )
return - V_16 ;
F_8 ( V_24 , V_17 ) ;
F_8 ( V_25 , V_17 ) ;
if ( V_2 -> V_14 . V_15 & V_12 ) {
V_8 = F_2 ( V_2 , V_26 , V_27 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 & V_28 )
F_8 ( V_29 , V_17 ) ;
}
V_8 = F_2 ( V_2 , V_30 , V_31 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 & ( V_32 | V_33 |
V_34 | V_35 |
V_36 | V_37 |
V_38 ) )
F_8 ( V_39 , V_17 ) ;
if ( V_8 & V_32 )
F_8 ( V_40 , V_17 ) ;
if ( V_8 & V_33 )
F_8 ( V_41 , V_17 ) ;
if ( V_8 & V_34 )
F_8 ( V_42 , V_17 ) ;
if ( V_8 & V_43 ) {
V_8 = F_2 ( V_2 , V_30 , V_44 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 & ( V_45 | V_46 |
V_47 | V_48 ) )
F_8 ( V_49 , V_17 ) ;
if ( V_8 & V_50 )
F_8 ( V_39 , V_17 ) ;
if ( V_8 & ( V_51 | V_52 |
V_53 ) )
F_8 ( V_54 , V_17 ) ;
if ( V_8 & V_50 )
F_8 ( V_55 ,
V_17 ) ;
if ( V_8 & V_45 )
F_8 ( V_56 ,
V_17 ) ;
if ( V_8 & V_51 )
F_8 ( V_57 ,
V_17 ) ;
if ( V_8 & V_52 )
F_8 ( V_58 ,
V_17 ) ;
if ( V_8 & V_46 )
F_8 ( V_59 ,
V_17 ) ;
if ( V_8 & V_53 )
F_8 ( V_60 ,
V_17 ) ;
if ( V_8 & V_47 )
F_8 ( V_61 ,
V_17 ) ;
if ( V_8 & V_48 )
F_8 ( V_62 ,
V_17 ) ;
}
if ( ! F_9 ( & V_5 , V_17 ) )
F_10 ( & V_2 -> V_63 . V_64 ,
L_1 ,
V_65 , V_17 ) ;
V_2 -> V_17 &= V_5 ;
V_2 -> V_66 &= V_2 -> V_17 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
bool V_67 = false ;
T_2 V_66 ;
int V_9 ;
if ( V_2 -> V_68 == V_69 ) {
V_9 = F_12 ( V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
return F_13 ( V_2 ) ;
}
V_2 -> V_66 &= V_2 -> V_17 ;
V_66 = V_2 -> V_66 ;
V_9 = F_1 ( V_2 , V_26 , V_70 ,
V_71 | V_72 |
V_73 | V_74 ,
F_14 ( V_66 ) ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 > 0 )
V_67 = true ;
V_9 = F_1 ( V_2 , V_26 , V_75 ,
V_76 | V_77 ,
F_15 ( V_66 ) ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 > 0 )
V_67 = true ;
V_9 = F_1 ( V_2 , V_26 , V_78 ,
V_79 ,
V_66 & V_80 ?
V_79 : 0 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 > 0 )
V_67 = true ;
if ( V_67 )
V_9 = F_16 ( V_2 ) ;
return V_9 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_2 ( V_2 , V_81 , V_82 + V_27 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 & V_83 )
return 1 ;
return F_18 ( V_2 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
V_2 -> V_84 = 1 ;
V_2 -> V_85 = V_86 ;
V_2 -> V_87 = V_88 ;
if ( V_2 -> V_18 == V_19 )
V_2 -> V_18 = V_23 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
T_2 V_10 = V_2 -> V_14 . V_15 ;
int V_8 ;
V_10 &= ~ ( F_21 ( V_89 ) | F_21 ( V_90 ) |
F_21 ( V_91 ) ) ;
V_2 -> V_85 = V_92 ;
V_2 -> V_87 = V_93 ;
V_2 -> V_94 = 0 ;
V_2 -> V_84 = 0 ;
V_2 -> V_95 = 0 ;
V_2 -> V_96 = 0 ;
V_8 = F_2 ( V_2 , V_81 , V_82 + V_27 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 & V_83 )
return F_19 ( V_2 ) ;
V_8 = F_22 ( V_2 , V_10 ) ;
if ( V_8 < 0 )
return V_8 ;
V_2 -> V_84 = V_8 > 0 ? 1 : 0 ;
V_8 = F_2 ( V_2 , V_26 , V_27 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 & V_97 ) {
V_8 = F_23 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_2 ( V_2 , V_26 , V_98 ) ;
if ( V_8 < 0 )
return V_8 ;
V_2 -> V_94 |= F_24 ( V_8 ) ;
if ( V_2 -> V_68 == V_99 ) {
V_8 = F_2 ( V_2 , V_26 , V_100 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 & V_101 )
V_2 -> V_85 = V_86 ;
else if ( V_8 & V_102 )
V_2 -> V_85 = V_103 ;
else if ( V_8 & V_104 )
V_2 -> V_85 = V_105 ;
else if ( V_8 & V_106 )
V_2 -> V_85 = V_107 ;
V_2 -> V_87 = V_88 ;
}
}
if ( V_2 -> V_68 != V_99 ) {
V_8 = F_25 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
}
if ( ( V_2 -> V_18 == V_19 ||
V_2 -> V_18 == V_23 ) && V_2 -> V_84 ) {
if ( V_2 -> V_85 == V_86 )
V_2 -> V_18 = V_23 ;
else if ( V_2 -> V_85 >= V_107 &&
V_2 -> V_85 < V_86 )
V_2 -> V_18 = V_19 ;
}
return 0 ;
}
