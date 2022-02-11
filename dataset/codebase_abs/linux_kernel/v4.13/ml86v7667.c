static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_2 * F_3 ( struct V_5 * V_6 )
{
return & F_2 ( V_6 -> V_7 , struct V_1 , V_8 ) -> V_4 ;
}
static int F_4 ( struct V_9 * V_10 , const T_1 V_11 ,
const T_1 V_12 , const T_1 V_13 )
{
int V_14 = F_5 ( V_10 , V_11 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = ( V_14 & ~ V_12 ) | ( V_13 & V_12 ) ;
return F_6 ( V_10 , V_11 , V_14 ) ;
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_2 * V_4 = F_3 ( V_6 ) ;
struct V_9 * V_10 = F_8 ( V_4 ) ;
int V_15 = - V_16 ;
switch ( V_6 -> V_17 ) {
case V_18 :
V_15 = F_4 ( V_10 , V_19 ,
V_20 , V_6 -> V_14 ) ;
break;
case V_21 :
V_15 = F_4 ( V_10 , V_22 ,
V_23 , V_6 -> V_14 ) ;
break;
case V_24 :
V_15 = F_4 ( V_10 , V_25 , V_26 ,
V_6 -> V_14 << V_27 ) ;
break;
case V_28 :
V_15 = F_4 ( V_10 , V_29 , ~ 0 , V_6 -> V_14 ) ;
break;
case V_30 :
V_15 = F_4 ( V_10 , V_31 ,
V_32 ,
V_6 -> V_14 << V_33 ) ;
break;
case V_34 :
V_15 = F_4 ( V_10 , V_31 ,
V_35 ,
V_6 -> V_14 << V_36 ) ;
break;
case V_37 :
V_15 = F_4 ( V_10 , V_38 ,
V_39 ,
V_6 -> V_14 << V_40 ) ;
break;
case V_41 :
V_15 = F_4 ( V_10 , V_42 ,
V_43 ,
V_6 -> V_14 << V_44 ) ;
break;
}
return V_15 ;
}
static int F_9 ( struct V_2 * V_4 , T_2 * V_45 )
{
struct V_9 * V_10 = F_8 ( V_4 ) ;
int V_46 ;
V_46 = F_5 ( V_10 , V_47 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_46 & V_48 )
* V_45 &= V_46 & V_49 ? V_50 : V_51 ;
else
* V_45 = V_52 ;
return 0 ;
}
static int F_10 ( struct V_2 * V_4 , T_3 * V_46 )
{
struct V_9 * V_10 = F_8 ( V_4 ) ;
int V_53 ;
V_53 = F_5 ( V_10 , V_47 ) ;
if ( V_53 < 0 )
return V_53 ;
* V_46 = V_53 & V_48 ? 0 : V_54 ;
return 0 ;
}
static int F_11 ( struct V_2 * V_4 ,
struct V_55 * V_56 ,
struct V_57 * V_58 )
{
if ( V_58 -> V_59 || V_58 -> V_60 > 0 )
return - V_16 ;
V_58 -> V_58 = V_61 ;
return 0 ;
}
static int F_12 ( struct V_2 * V_4 ,
struct V_55 * V_56 ,
struct V_62 * V_63 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_65 * V_66 = & V_63 -> V_63 ;
if ( V_63 -> V_59 )
return - V_16 ;
V_66 -> V_58 = V_61 ;
V_66 -> V_67 = V_68 ;
V_66 -> V_69 = V_70 ;
V_66 -> V_71 = 720 ;
V_66 -> V_72 = V_64 -> V_45 & V_51 ? 480 : 576 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_4 ,
struct V_73 * V_56 )
{
V_56 -> V_74 = V_75 | V_76 |
V_77 ;
V_56 -> type = V_78 ;
return 0 ;
}
static int F_14 ( struct V_2 * V_4 , T_2 * V_45 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
* V_45 = V_64 -> V_45 ;
return 0 ;
}
static int F_15 ( struct V_2 * V_4 , T_2 V_45 )
{
struct V_1 * V_64 = F_1 ( V_4 ) ;
struct V_9 * V_10 = F_8 ( & V_64 -> V_4 ) ;
int V_15 ;
T_1 V_79 ;
V_79 = V_45 & V_51 ? V_80 : V_81 ;
V_15 = F_4 ( V_10 , V_82 , V_83 , V_79 ) ;
if ( V_15 < 0 )
return V_15 ;
V_64 -> V_45 = V_45 ;
return 0 ;
}
static int F_16 ( struct V_2 * V_4 ,
struct V_84 * V_11 )
{
struct V_9 * V_10 = F_8 ( V_4 ) ;
int V_15 ;
V_15 = F_5 ( V_10 , ( T_1 ) V_11 -> V_11 ) ;
if ( V_15 < 0 )
return V_15 ;
V_11 -> V_14 = V_15 ;
V_11 -> V_85 = sizeof( T_1 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_4 ,
const struct V_84 * V_11 )
{
struct V_9 * V_10 = F_8 ( V_4 ) ;
return F_6 ( V_10 , ( T_1 ) V_11 -> V_11 , ( T_1 ) V_11 -> V_14 ) ;
}
static int F_18 ( struct V_1 * V_64 )
{
struct V_9 * V_10 = F_8 ( & V_64 -> V_4 ) ;
int V_14 ;
int V_15 ;
V_15 = F_4 ( V_10 , V_82 ,
V_86 | V_87 ,
V_88 | V_87 ) ;
V_15 |= F_4 ( V_10 , V_89 , V_90 ,
V_90 ) ;
V_15 |= F_4 ( V_10 , V_91 , V_92 ,
F_19 ( 7 ) ) ;
V_15 |= F_4 ( V_10 , V_19 , V_93 ,
V_93 ) ;
V_15 |= F_4 ( V_10 , V_22 , V_94 , 0 ) ;
V_14 = F_5 ( V_10 , V_47 ) ;
if ( V_14 < 0 )
return V_14 ;
V_64 -> V_45 = V_14 & V_49 ? V_50 : V_51 ;
V_15 |= F_4 ( V_10 , V_95 , V_96 , 0 ) ;
V_14 = V_64 -> V_45 & V_51 ? V_80 : V_81 ;
V_15 |= F_4 ( V_10 , V_82 , V_83 , V_14 ) ;
return V_15 ;
}
static int F_20 ( struct V_9 * V_10 ,
const struct V_97 * V_98 )
{
struct V_1 * V_64 ;
int V_15 ;
if ( ! F_21 ( V_10 -> V_99 , V_100 ) )
return - V_101 ;
V_64 = F_22 ( & V_10 -> V_102 , sizeof( * V_64 ) , V_103 ) ;
if ( ! V_64 )
return - V_104 ;
F_23 ( & V_64 -> V_4 , V_10 , & V_105 ) ;
F_24 ( & V_64 -> V_8 , 8 ) ;
F_25 ( & V_64 -> V_8 , & V_106 ,
V_18 , - 64 , 63 , 1 , 0 ) ;
F_25 ( & V_64 -> V_8 , & V_106 ,
V_21 , - 8 , 7 , 1 , 0 ) ;
F_25 ( & V_64 -> V_8 , & V_106 ,
V_24 , - 32 , 31 , 1 , 0 ) ;
F_25 ( & V_64 -> V_8 , & V_106 ,
V_28 , - 128 , 127 , 1 , 0 ) ;
F_25 ( & V_64 -> V_8 , & V_106 ,
V_30 , - 4 , 3 , 1 , 0 ) ;
F_25 ( & V_64 -> V_8 , & V_106 ,
V_34 , - 4 , 3 , 1 , 0 ) ;
F_25 ( & V_64 -> V_8 , & V_106 ,
V_37 , 0 , 1 , 1 , 0 ) ;
F_25 ( & V_64 -> V_8 , & V_106 ,
V_41 , 0 , 1 , 1 , 0 ) ;
V_64 -> V_4 . V_107 = & V_64 -> V_8 ;
V_15 = V_64 -> V_8 . error ;
if ( V_15 )
goto V_108;
F_26 ( & V_64 -> V_8 ) ;
V_15 = F_18 ( V_64 ) ;
if ( V_15 )
goto V_108;
F_27 ( V_10 , L_1 ,
V_10 -> V_109 , V_10 -> V_99 -> V_110 ) ;
return 0 ;
V_108:
F_28 ( & V_64 -> V_8 ) ;
F_29 ( & V_64 -> V_4 ) ;
F_30 ( V_10 , L_2 ,
V_10 -> V_109 , V_10 -> V_99 -> V_110 ) ;
return V_15 ;
}
static int F_31 ( struct V_9 * V_10 )
{
struct V_2 * V_4 = F_32 ( V_10 ) ;
struct V_1 * V_64 = F_1 ( V_4 ) ;
F_28 ( & V_64 -> V_8 ) ;
F_29 ( & V_64 -> V_4 ) ;
return 0 ;
}
