static inline T_1 F_1 ( const struct V_1 * V_2 ,
unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( const struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
T_1 V_10 , V_11 ;
if ( V_9 -> V_12 )
return 0 ;
V_11 = F_1 ( V_2 , V_13 ) ;
V_11 |= V_14 ;
F_3 ( V_2 , V_13 , V_11 ) ;
F_7 ( V_2 -> V_15 ) ;
V_10 = F_1 ( V_2 , V_16 ) ;
V_10 |= V_17 ;
F_3 ( V_2 , V_16 , V_10 ) ;
return 0 ;
}
static void F_8 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
T_1 V_10 ;
if ( V_9 -> V_12 )
return;
V_10 = F_1 ( V_2 , V_16 ) ;
V_10 &= ~ V_17 ;
F_3 ( V_2 , V_16 , V_10 ) ;
F_9 ( V_2 -> V_15 ) ;
}
static int F_10 ( struct V_6 * V_7 , int V_18 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
T_1 V_11 ;
T_1 V_19 ;
if ( V_7 -> V_20 == V_21 )
V_19 = V_22 | V_23 ;
else
V_19 = V_24 | V_25 ;
V_11 = F_1 ( V_2 , V_13 ) ;
switch ( V_18 ) {
case V_26 :
case V_27 :
case V_28 :
V_11 |= V_19 ;
break;
case V_29 :
case V_30 :
case V_31 :
V_11 &= ~ V_19 ;
break;
default:
return - V_32 ;
}
F_3 ( V_2 , V_13 , V_11 ) ;
return 0 ;
}
static int F_11 ( struct V_8 * V_9 , unsigned int V_33 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
T_1 V_34 = 0 ;
T_1 V_10 ;
V_10 = F_1 ( V_2 , V_16 ) ;
V_10 &= ~ ( V_35 | V_36 ) ;
switch ( V_33 & V_37 ) {
case V_38 :
V_10 |= V_35 | V_36 ;
V_34 |= V_39 ;
break;
case V_40 :
V_10 |= V_36 ;
break;
case V_41 :
V_10 |= V_35 ;
break;
case V_42 :
break;
default:
return - V_32 ;
}
switch ( V_33 & V_43 ) {
case V_44 :
V_34 |= V_45 ;
break;
case V_46 :
break;
default:
return - V_32 ;
}
switch ( V_33 & V_47 ) {
case V_48 :
break;
default:
return - V_32 ;
}
F_3 ( V_2 , V_16 , V_10 ) ;
F_3 ( V_2 , V_49 , V_34 ) ;
return 0 ;
}
static int F_12 ( struct V_6 * V_7 ,
struct V_50 * V_51 , struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
enum V_52 V_53 ;
struct V_54 * V_55 ;
unsigned int V_56 ;
T_1 V_11 ;
V_11 = F_1 ( V_2 , V_13 ) ;
switch ( F_13 ( V_51 ) ) {
case V_57 :
V_56 = 0 ;
V_53 = V_58 ;
break;
case V_59 :
V_56 = 1 ;
V_53 = V_60 ;
break;
default:
return - V_32 ;
}
if ( V_7 -> V_20 == V_21 ) {
V_11 &= ~ V_61 ;
V_11 |= V_56 << V_62 ;
if ( F_14 ( V_51 ) == 1 )
V_11 |= V_63 ;
else
V_11 &= ~ V_63 ;
V_55 = & V_2 -> V_64 ;
V_55 -> V_65 . V_66 = V_53 ;
} else {
V_11 &= ~ V_67 ;
V_11 |= V_56 << V_68 ;
V_55 = & V_2 -> V_69 ;
V_55 -> V_65 . V_70 = V_53 ;
}
F_3 ( V_2 , V_13 , V_11 ) ;
F_15 ( V_9 , V_7 , V_55 ) ;
return 0 ;
}
static int F_16 ( struct V_8 * V_9 , int V_71 ,
unsigned int V_72 , int V_73 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
struct V_74 * V_75 ;
int V_76 = 0 ;
switch ( V_71 ) {
case V_77 :
V_75 = F_17 ( NULL , L_1 ) ;
F_18 ( V_2 -> V_15 , V_75 ) ;
break;
case V_78 :
V_75 = F_17 ( NULL , L_2 ) ;
F_18 ( V_2 -> V_15 , V_75 ) ;
V_76 = F_19 ( V_2 -> V_15 , V_72 ) ;
break;
default:
return - V_32 ;
}
F_20 ( V_75 ) ;
return V_76 ;
}
static int F_21 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
T_1 V_10 ;
if ( V_9 -> V_12 ) {
V_10 = F_1 ( V_2 , V_16 ) ;
V_10 &= ~ V_17 ;
F_3 ( V_2 , V_16 , V_10 ) ;
F_9 ( V_2 -> V_15 ) ;
}
F_9 ( V_2 -> V_79 ) ;
return 0 ;
}
static int F_22 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
T_1 V_10 ;
F_7 ( V_2 -> V_79 ) ;
if ( V_9 -> V_12 ) {
F_7 ( V_2 -> V_15 ) ;
V_10 = F_1 ( V_2 , V_16 ) ;
V_10 |= V_17 ;
F_3 ( V_2 , V_16 , V_10 ) ;
}
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_80 * V_65 ;
V_65 = & V_2 -> V_64 . V_65 ;
V_65 -> V_70 = V_81 ,
V_65 -> V_82 = V_83 ;
V_65 -> V_84 = V_85 ;
V_65 -> V_86 = V_87 ;
V_65 -> V_88 = V_89 ;
V_2 -> V_64 . V_90 = V_2 -> V_91 + V_92 ;
V_65 = & V_2 -> V_69 . V_65 ;
V_65 -> V_66 = V_81 ,
V_65 -> V_82 = V_83 ;
V_65 -> V_84 = V_93 ;
V_65 -> V_86 = V_94 ;
V_65 -> V_88 = V_89 ;
V_2 -> V_69 . V_90 = V_2 -> V_91 + V_92 ;
}
static int F_24 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
T_1 V_10 ;
F_7 ( V_2 -> V_79 ) ;
F_23 ( V_2 ) ;
V_10 = ( 7 << V_95 ) |
( 8 << V_96 ) |
V_97 |
V_98 |
V_99 ;
F_3 ( V_2 , V_16 , V_100 ) ;
F_3 ( V_2 , V_16 , V_10 ) ;
return 0 ;
}
static int F_25 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
F_9 ( V_2 -> V_79 ) ;
return 0 ;
}
static int T_2 F_26 ( struct V_101 * V_102 )
{
struct V_1 * V_2 ;
int V_76 ;
V_2 = F_27 ( sizeof( * V_2 ) , V_103 ) ;
if ( ! V_2 )
return - V_104 ;
V_2 -> V_105 = F_28 ( V_102 , V_106 , 0 ) ;
if ( ! V_2 -> V_105 ) {
V_76 = - V_107 ;
goto V_108;
}
V_2 -> V_105 = F_29 ( V_2 -> V_105 -> V_109 , F_30 ( V_2 -> V_105 ) ,
V_102 -> V_110 ) ;
if ( ! V_2 -> V_105 ) {
V_76 = - V_111 ;
goto V_108;
}
V_2 -> V_4 = F_31 ( V_2 -> V_105 -> V_109 , F_30 ( V_2 -> V_105 ) ) ;
if ( ! V_2 -> V_4 ) {
V_76 = - V_111 ;
goto V_112;
}
V_2 -> V_91 = V_2 -> V_105 -> V_109 ;
V_2 -> V_79 = F_17 ( & V_102 -> V_113 , L_3 ) ;
if ( F_32 ( V_2 -> V_79 ) ) {
V_76 = F_33 ( V_2 -> V_79 ) ;
goto V_114;
}
V_2 -> V_15 = F_17 ( & V_102 -> V_113 , L_4 ) ;
if ( F_32 ( V_2 -> V_15 ) ) {
V_76 = F_33 ( V_2 -> V_15 ) ;
goto V_115;
}
F_34 ( V_102 , V_2 ) ;
V_76 = F_35 ( & V_102 -> V_113 , & V_116 ) ;
if ( V_76 ) {
F_36 ( & V_102 -> V_113 , L_5 ) ;
goto V_117;
}
return 0 ;
V_117:
F_20 ( V_2 -> V_15 ) ;
V_115:
F_20 ( V_2 -> V_79 ) ;
V_114:
F_37 ( V_2 -> V_4 ) ;
V_112:
F_38 ( V_2 -> V_105 -> V_109 , F_30 ( V_2 -> V_105 ) ) ;
V_108:
F_39 ( V_2 ) ;
return V_76 ;
}
static int T_3 F_40 ( struct V_101 * V_102 )
{
struct V_1 * V_2 = F_41 ( V_102 ) ;
F_42 ( & V_102 -> V_113 ) ;
F_20 ( V_2 -> V_15 ) ;
F_20 ( V_2 -> V_79 ) ;
F_37 ( V_2 -> V_4 ) ;
F_38 ( V_2 -> V_105 -> V_109 , F_30 ( V_2 -> V_105 ) ) ;
F_34 ( V_102 , NULL ) ;
F_39 ( V_2 ) ;
return 0 ;
}
