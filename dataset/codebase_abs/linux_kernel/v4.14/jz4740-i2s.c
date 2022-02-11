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
int V_12 ;
if ( V_9 -> V_13 )
return 0 ;
V_11 = F_1 ( V_2 , V_14 ) ;
V_11 |= V_15 ;
F_3 ( V_2 , V_14 , V_11 ) ;
V_12 = F_7 ( V_2 -> V_16 ) ;
if ( V_12 )
return V_12 ;
V_10 = F_1 ( V_2 , V_17 ) ;
V_10 |= V_18 ;
F_3 ( V_2 , V_17 , V_10 ) ;
return 0 ;
}
static void F_8 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
T_1 V_10 ;
if ( V_9 -> V_13 )
return;
V_10 = F_1 ( V_2 , V_17 ) ;
V_10 &= ~ V_18 ;
F_3 ( V_2 , V_17 , V_10 ) ;
F_9 ( V_2 -> V_16 ) ;
}
static int F_10 ( struct V_6 * V_7 , int V_19 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
T_1 V_11 ;
T_1 V_20 ;
if ( V_7 -> V_21 == V_22 )
V_20 = V_23 | V_24 ;
else
V_20 = V_25 | V_26 ;
V_11 = F_1 ( V_2 , V_14 ) ;
switch ( V_19 ) {
case V_27 :
case V_28 :
case V_29 :
V_11 |= V_20 ;
break;
case V_30 :
case V_31 :
case V_32 :
V_11 &= ~ V_20 ;
break;
default:
return - V_33 ;
}
F_3 ( V_2 , V_14 , V_11 ) ;
return 0 ;
}
static int F_11 ( struct V_8 * V_9 , unsigned int V_34 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
T_1 V_35 = 0 ;
T_1 V_10 ;
V_10 = F_1 ( V_2 , V_17 ) ;
V_10 &= ~ ( V_36 | V_37 ) ;
switch ( V_34 & V_38 ) {
case V_39 :
V_10 |= V_36 | V_37 ;
V_35 |= V_40 ;
break;
case V_41 :
V_10 |= V_37 ;
break;
case V_42 :
V_10 |= V_36 ;
break;
case V_43 :
break;
default:
return - V_33 ;
}
switch ( V_34 & V_44 ) {
case V_45 :
V_35 |= V_46 ;
break;
case V_47 :
break;
default:
return - V_33 ;
}
switch ( V_34 & V_48 ) {
case V_49 :
break;
default:
return - V_33 ;
}
F_3 ( V_2 , V_17 , V_10 ) ;
F_3 ( V_2 , V_50 , V_35 ) ;
return 0 ;
}
static int F_12 ( struct V_6 * V_7 ,
struct V_51 * V_52 , struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
unsigned int V_53 ;
T_1 V_11 , V_54 ;
int div ;
V_11 = F_1 ( V_2 , V_14 ) ;
V_54 = F_1 ( V_2 , V_55 ) ;
div = F_13 ( V_2 -> V_16 ) / ( 64 * F_14 ( V_52 ) ) ;
switch ( F_15 ( V_52 ) ) {
case V_56 :
V_53 = 0 ;
break;
case V_57 :
V_53 = 1 ;
break;
default:
return - V_33 ;
}
if ( V_7 -> V_21 == V_22 ) {
V_11 &= ~ V_58 ;
V_11 |= V_53 << V_59 ;
if ( F_16 ( V_52 ) == 1 )
V_11 |= V_60 ;
else
V_11 &= ~ V_60 ;
V_54 &= ~ V_61 ;
V_54 |= ( div - 1 ) << V_62 ;
} else {
V_11 &= ~ V_63 ;
V_11 |= V_53 << V_64 ;
if ( V_2 -> V_65 >= V_66 ) {
V_54 &= ~ V_67 ;
V_54 |= ( div - 1 ) << V_68 ;
} else {
V_54 &= ~ V_61 ;
V_54 |= ( div - 1 ) << V_62 ;
}
}
F_3 ( V_2 , V_14 , V_11 ) ;
F_3 ( V_2 , V_55 , V_54 ) ;
return 0 ;
}
static int F_17 ( struct V_8 * V_9 , int V_69 ,
unsigned int V_70 , int V_71 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
struct V_72 * V_73 ;
int V_12 = 0 ;
switch ( V_69 ) {
case V_74 :
V_73 = F_18 ( NULL , L_1 ) ;
F_19 ( V_2 -> V_16 , V_73 ) ;
break;
case V_75 :
V_73 = F_18 ( NULL , L_2 ) ;
F_19 ( V_2 -> V_16 , V_73 ) ;
V_12 = F_20 ( V_2 -> V_16 , V_70 ) ;
break;
default:
return - V_33 ;
}
F_21 ( V_73 ) ;
return V_12 ;
}
static int F_22 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
T_1 V_10 ;
if ( V_9 -> V_13 ) {
V_10 = F_1 ( V_2 , V_17 ) ;
V_10 &= ~ V_18 ;
F_3 ( V_2 , V_17 , V_10 ) ;
F_9 ( V_2 -> V_16 ) ;
}
F_9 ( V_2 -> V_76 ) ;
return 0 ;
}
static int F_23 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
T_1 V_10 ;
int V_12 ;
V_12 = F_7 ( V_2 -> V_76 ) ;
if ( V_12 )
return V_12 ;
if ( V_9 -> V_13 ) {
V_12 = F_7 ( V_2 -> V_16 ) ;
if ( V_12 ) {
F_9 ( V_2 -> V_76 ) ;
return V_12 ;
}
V_10 = F_1 ( V_2 , V_17 ) ;
V_10 |= V_18 ;
F_3 ( V_2 , V_17 , V_10 ) ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_77 * V_78 ;
V_78 = & V_2 -> V_79 ;
V_78 -> V_80 = 16 ;
V_78 -> V_81 = V_82 ;
V_78 -> V_83 = V_2 -> V_84 + V_85 ;
V_78 = & V_2 -> V_86 ;
V_78 -> V_80 = 16 ;
V_78 -> V_81 = V_87 ;
V_78 -> V_83 = V_2 -> V_84 + V_85 ;
}
static int F_25 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
T_1 V_10 ;
int V_12 ;
V_12 = F_7 ( V_2 -> V_76 ) ;
if ( V_12 )
return V_12 ;
F_24 ( V_2 ) ;
F_26 ( V_9 , & V_2 -> V_79 ,
& V_2 -> V_86 ) ;
if ( V_2 -> V_65 >= V_66 ) {
V_10 = ( 7 << V_88 ) |
( 8 << V_89 ) |
V_90 |
V_91 |
V_92 ;
} else {
V_10 = ( 7 << V_93 ) |
( 8 << V_94 ) |
V_90 |
V_91 |
V_92 ;
}
F_3 ( V_2 , V_17 , V_95 ) ;
F_3 ( V_2 , V_17 , V_10 ) ;
return 0 ;
}
static int F_27 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
F_9 ( V_2 -> V_76 ) ;
return 0 ;
}
static int F_28 ( struct V_96 * V_97 )
{
struct V_1 * V_2 ;
struct V_98 * V_99 ;
int V_12 ;
const struct V_100 * V_101 ;
V_2 = F_29 ( & V_97 -> V_102 , sizeof( * V_2 ) , V_103 ) ;
if ( ! V_2 )
return - V_104 ;
V_101 = F_30 ( V_105 , & V_97 -> V_102 ) ;
if ( V_101 )
V_2 -> V_65 = (enum V_106 ) V_101 -> V_107 ;
V_99 = F_31 ( V_97 , V_108 , 0 ) ;
V_2 -> V_4 = F_32 ( & V_97 -> V_102 , V_99 ) ;
if ( F_33 ( V_2 -> V_4 ) )
return F_34 ( V_2 -> V_4 ) ;
V_2 -> V_84 = V_99 -> V_109 ;
V_2 -> V_76 = F_35 ( & V_97 -> V_102 , L_3 ) ;
if ( F_33 ( V_2 -> V_76 ) )
return F_34 ( V_2 -> V_76 ) ;
V_2 -> V_16 = F_35 ( & V_97 -> V_102 , L_4 ) ;
if ( F_33 ( V_2 -> V_16 ) )
return F_34 ( V_2 -> V_16 ) ;
F_36 ( V_97 , V_2 ) ;
if ( V_2 -> V_65 == V_66 )
V_12 = F_37 ( & V_97 -> V_102 ,
& V_110 , & V_111 , 1 ) ;
else
V_12 = F_37 ( & V_97 -> V_102 ,
& V_110 , & V_112 , 1 ) ;
if ( V_12 )
return V_12 ;
return F_38 ( & V_97 -> V_102 , NULL ,
V_113 ) ;
}
