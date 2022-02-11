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
unsigned int V_52 ;
T_1 V_11 , V_53 ;
int div ;
V_11 = F_1 ( V_2 , V_13 ) ;
V_53 = F_1 ( V_2 , V_54 ) ;
div = F_13 ( V_2 -> V_15 ) / ( 64 * F_14 ( V_51 ) ) ;
switch ( F_15 ( V_51 ) ) {
case V_55 :
V_52 = 0 ;
break;
case V_56 :
V_52 = 1 ;
break;
default:
return - V_32 ;
}
if ( V_7 -> V_20 == V_21 ) {
V_11 &= ~ V_57 ;
V_11 |= V_52 << V_58 ;
if ( F_16 ( V_51 ) == 1 )
V_11 |= V_59 ;
else
V_11 &= ~ V_59 ;
} else {
V_11 &= ~ V_60 ;
V_11 |= V_52 << V_61 ;
}
V_53 &= ~ V_62 ;
V_53 |= ( div - 1 ) << V_63 ;
F_3 ( V_2 , V_13 , V_11 ) ;
F_3 ( V_2 , V_54 , V_53 ) ;
return 0 ;
}
static int F_17 ( struct V_8 * V_9 , int V_64 ,
unsigned int V_65 , int V_66 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
struct V_67 * V_68 ;
int V_69 = 0 ;
switch ( V_64 ) {
case V_70 :
V_68 = F_18 ( NULL , L_1 ) ;
F_19 ( V_2 -> V_15 , V_68 ) ;
break;
case V_71 :
V_68 = F_18 ( NULL , L_2 ) ;
F_19 ( V_2 -> V_15 , V_68 ) ;
V_69 = F_20 ( V_2 -> V_15 , V_65 ) ;
break;
default:
return - V_32 ;
}
F_21 ( V_68 ) ;
return V_69 ;
}
static int F_22 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
T_1 V_10 ;
if ( V_9 -> V_12 ) {
V_10 = F_1 ( V_2 , V_16 ) ;
V_10 &= ~ V_17 ;
F_3 ( V_2 , V_16 , V_10 ) ;
F_9 ( V_2 -> V_15 ) ;
}
F_9 ( V_2 -> V_72 ) ;
return 0 ;
}
static int F_23 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
T_1 V_10 ;
F_7 ( V_2 -> V_72 ) ;
if ( V_9 -> V_12 ) {
F_7 ( V_2 -> V_15 ) ;
V_10 = F_1 ( V_2 , V_16 ) ;
V_10 |= V_17 ;
F_3 ( V_2 , V_16 , V_10 ) ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_73 * V_74 ;
V_74 = & V_2 -> V_75 ;
V_74 -> V_76 = 16 ;
V_74 -> V_77 = V_78 ;
V_74 -> V_79 = V_2 -> V_80 + V_81 ;
V_74 = & V_2 -> V_82 ;
V_74 -> V_76 = 16 ;
V_74 -> V_77 = V_83 ;
V_74 -> V_79 = V_2 -> V_80 + V_81 ;
}
static int F_25 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
T_1 V_10 ;
F_7 ( V_2 -> V_72 ) ;
F_24 ( V_2 ) ;
F_26 ( V_9 , & V_2 -> V_75 ,
& V_2 -> V_82 ) ;
V_10 = ( 7 << V_84 ) |
( 8 << V_85 ) |
V_86 |
V_87 |
V_88 ;
F_3 ( V_2 , V_16 , V_89 ) ;
F_3 ( V_2 , V_16 , V_10 ) ;
return 0 ;
}
static int F_27 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
F_9 ( V_2 -> V_72 ) ;
return 0 ;
}
static int F_28 ( struct V_90 * V_91 )
{
struct V_1 * V_2 ;
struct V_92 * V_93 ;
int V_69 ;
V_2 = F_29 ( & V_91 -> V_94 , sizeof( * V_2 ) , V_95 ) ;
if ( ! V_2 )
return - V_96 ;
V_93 = F_30 ( V_91 , V_97 , 0 ) ;
V_2 -> V_4 = F_31 ( & V_91 -> V_94 , V_93 ) ;
if ( F_32 ( V_2 -> V_4 ) )
return F_33 ( V_2 -> V_4 ) ;
V_2 -> V_80 = V_93 -> V_98 ;
V_2 -> V_72 = F_34 ( & V_91 -> V_94 , L_3 ) ;
if ( F_32 ( V_2 -> V_72 ) )
return F_33 ( V_2 -> V_72 ) ;
V_2 -> V_15 = F_34 ( & V_91 -> V_94 , L_4 ) ;
if ( F_32 ( V_2 -> V_15 ) )
return F_33 ( V_2 -> V_15 ) ;
F_35 ( V_91 , V_2 ) ;
V_69 = F_36 ( & V_91 -> V_94 ,
& V_99 , & V_100 , 1 ) ;
if ( V_69 )
return V_69 ;
return F_37 ( & V_91 -> V_94 , NULL ,
V_101 ) ;
}
