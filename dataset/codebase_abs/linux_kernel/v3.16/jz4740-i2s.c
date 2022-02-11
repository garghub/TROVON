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
T_1 V_11 ;
V_11 = F_1 ( V_2 , V_13 ) ;
switch ( F_13 ( V_51 ) ) {
case V_53 :
V_52 = 0 ;
break;
case V_54 :
V_52 = 1 ;
break;
default:
return - V_32 ;
}
if ( V_7 -> V_20 == V_21 ) {
V_11 &= ~ V_55 ;
V_11 |= V_52 << V_56 ;
if ( F_14 ( V_51 ) == 1 )
V_11 |= V_57 ;
else
V_11 &= ~ V_57 ;
} else {
V_11 &= ~ V_58 ;
V_11 |= V_52 << V_59 ;
}
F_3 ( V_2 , V_13 , V_11 ) ;
return 0 ;
}
static int F_15 ( struct V_8 * V_9 , int V_60 ,
unsigned int V_61 , int V_62 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
struct V_63 * V_64 ;
int V_65 = 0 ;
switch ( V_60 ) {
case V_66 :
V_64 = F_16 ( NULL , L_1 ) ;
F_17 ( V_2 -> V_15 , V_64 ) ;
break;
case V_67 :
V_64 = F_16 ( NULL , L_2 ) ;
F_17 ( V_2 -> V_15 , V_64 ) ;
V_65 = F_18 ( V_2 -> V_15 , V_61 ) ;
break;
default:
return - V_32 ;
}
F_19 ( V_64 ) ;
return V_65 ;
}
static int F_20 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
T_1 V_10 ;
if ( V_9 -> V_12 ) {
V_10 = F_1 ( V_2 , V_16 ) ;
V_10 &= ~ V_17 ;
F_3 ( V_2 , V_16 , V_10 ) ;
F_9 ( V_2 -> V_15 ) ;
}
F_9 ( V_2 -> V_68 ) ;
return 0 ;
}
static int F_21 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
T_1 V_10 ;
F_7 ( V_2 -> V_68 ) ;
if ( V_9 -> V_12 ) {
F_7 ( V_2 -> V_15 ) ;
V_10 = F_1 ( V_2 , V_16 ) ;
V_10 |= V_17 ;
F_3 ( V_2 , V_16 , V_10 ) ;
}
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_69 * V_70 ;
V_70 = & V_2 -> V_71 ;
V_70 -> V_72 = 16 ;
V_70 -> V_73 = V_74 ;
V_70 -> V_75 = V_2 -> V_76 + V_77 ;
V_70 = & V_2 -> V_78 ;
V_70 -> V_72 = 16 ;
V_70 -> V_73 = V_79 ;
V_70 -> V_75 = V_2 -> V_76 + V_77 ;
}
static int F_23 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
T_1 V_10 ;
F_7 ( V_2 -> V_68 ) ;
F_22 ( V_2 ) ;
F_24 ( V_9 , & V_2 -> V_71 ,
& V_2 -> V_78 ) ;
V_10 = ( 7 << V_80 ) |
( 8 << V_81 ) |
V_82 |
V_83 |
V_84 ;
F_3 ( V_2 , V_16 , V_85 ) ;
F_3 ( V_2 , V_16 , V_10 ) ;
return 0 ;
}
static int F_25 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
F_9 ( V_2 -> V_68 ) ;
return 0 ;
}
static int F_26 ( struct V_86 * V_87 )
{
struct V_1 * V_2 ;
struct V_88 * V_89 ;
int V_65 ;
V_2 = F_27 ( & V_87 -> V_90 , sizeof( * V_2 ) , V_91 ) ;
if ( ! V_2 )
return - V_92 ;
V_89 = F_28 ( V_87 , V_93 , 0 ) ;
V_2 -> V_4 = F_29 ( & V_87 -> V_90 , V_89 ) ;
if ( F_30 ( V_2 -> V_4 ) )
return F_31 ( V_2 -> V_4 ) ;
V_2 -> V_76 = V_89 -> V_94 ;
V_2 -> V_68 = F_32 ( & V_87 -> V_90 , L_3 ) ;
if ( F_30 ( V_2 -> V_68 ) )
return F_31 ( V_2 -> V_68 ) ;
V_2 -> V_15 = F_32 ( & V_87 -> V_90 , L_4 ) ;
if ( F_30 ( V_2 -> V_15 ) )
return F_31 ( V_2 -> V_15 ) ;
F_33 ( V_87 , V_2 ) ;
V_65 = F_34 ( & V_87 -> V_90 ,
& V_95 , & V_96 , 1 ) ;
if ( V_65 )
return V_65 ;
return F_35 ( & V_87 -> V_90 , NULL ,
V_97 ) ;
}
