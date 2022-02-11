static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , bool V_6 )
{
unsigned long V_5 ;
V_5 = F_1 ( V_2 , V_7 ) ;
if ( V_6 )
V_5 |= V_8 | V_9 ;
else
V_5 &= ~ ( V_8 | V_9 ) ;
F_3 ( V_2 , V_7 , V_5 ) ;
}
static void F_6 ( struct V_1 * V_2 , bool V_6 )
{
unsigned long V_5 ;
V_5 = F_1 ( V_2 , V_7 ) ;
if ( V_6 )
V_5 |= V_10 | V_9 ;
else
V_5 &= ~ ( V_10 | V_9 ) ;
F_3 ( V_2 , V_7 , V_5 ) ;
}
static void F_7 ( struct V_1 * V_2 , bool V_6 )
{
unsigned long V_5 ;
V_5 = F_1 ( V_2 , V_11 ) ;
V_5 |= V_12 | V_13 ;
if ( V_6 )
V_5 |= V_14 ;
else
V_5 &= ~ V_14 ;
F_3 ( V_2 , V_11 , V_5 ) ;
}
static void F_8 ( struct V_1 * V_2 , bool V_6 )
{
unsigned long V_5 ;
V_5 = F_1 ( V_2 , V_15 ) ;
V_5 |= V_16 | V_13 ;
if ( V_6 )
V_5 |= V_17 ;
else
V_5 &= ~ V_17 ;
F_3 ( V_2 , V_15 , V_5 ) ;
}
static int F_9 ( struct V_18 * V_19 )
{
struct V_1 * V_20 = F_10 ( V_19 -> V_21 ) ;
F_11 ( V_19 , V_20 ) ;
V_20 -> V_22 . V_23 = V_20 -> V_24 + V_25 ;
V_20 -> V_22 . V_26 = 16 ;
V_20 -> V_27 . V_23 = V_20 -> V_24 + V_25 ;
V_20 -> V_27 . V_26 = 16 ;
F_12 ( V_19 , & V_20 -> V_22 ,
& V_20 -> V_27 ) ;
return 0 ;
}
static int F_13 ( struct V_18 * V_28 , unsigned int V_29 )
{
struct V_1 * V_2 = F_14 ( V_28 ) ;
unsigned long V_5 ;
V_5 = F_1 ( V_2 , V_30 ) ;
V_5 &= ~ ( V_31 | V_32 ) ;
V_5 |= V_33 << V_34 ;
switch ( V_29 & V_35 ) {
case V_36 :
V_2 -> V_37 = 1 ;
V_5 |= V_38 ;
break;
case V_39 :
V_2 -> V_37 = 0 ;
V_5 &= ~ V_38 ;
break;
default:
F_15 ( V_28 -> V_21 , L_1 ) ;
return - V_40 ;
}
F_3 ( V_2 , V_30 , V_5 ) ;
return 0 ;
}
static int F_16 ( struct V_41 * V_42 ,
struct V_43 * V_44 ,
struct V_18 * V_45 )
{
struct V_1 * V_2 = F_14 ( V_45 ) ;
struct V_46 * V_47 ;
unsigned int V_48 = V_33 ;
unsigned int V_49 = 32 ;
unsigned int V_50 = 0 ;
unsigned int V_51 = 0 ;
unsigned long V_5 ;
V_47 = F_17 ( V_45 , V_42 ) ;
V_47 -> V_52 = V_49 >> 3 ;
switch ( F_18 ( V_44 ) ) {
case V_53 :
case V_54 :
case V_55 :
V_48 = 1 ;
break;
default:
V_48 = 0 ;
F_15 ( V_45 -> V_21 , L_2 ) ;
return - V_40 ;
}
V_5 = F_1 ( V_2 , V_30 ) ;
V_5 |= F_19 ( V_48 ) | F_20 ( 1 ) ;
F_3 ( V_2 , V_30 , V_5 ) ;
F_3 ( V_2 , V_56 , V_50 ) ;
if ( V_2 -> V_37 )
V_51 = F_21 ( V_2 -> V_57 ,
F_22 ( V_44 ) * V_58 * V_49 ) ;
return V_51 ;
}
static int F_23 ( struct V_41 * V_42 , int V_59 ,
struct V_18 * V_19 )
{
int V_60 = ( V_42 -> V_61 == V_62 ) ;
struct V_1 * V_20 = F_10 ( V_19 -> V_21 ) ;
unsigned int V_5 ;
int V_51 = 0 ;
switch ( V_59 ) {
case V_63 :
if ( V_60 ) {
V_5 = F_1 ( V_20 , V_15 ) ;
V_5 |= V_64 ;
F_3 ( V_20 , V_15 , V_5 ) ;
F_8 ( V_20 , true ) ;
} else {
V_5 = F_1 ( V_20 , V_11 ) ;
V_5 |= V_65 ;
F_3 ( V_20 , V_11 , V_5 ) ;
F_7 ( V_20 , true ) ;
}
break;
case V_66 :
case V_67 :
if ( V_60 )
F_6 ( V_20 , true ) ;
else
F_5 ( V_20 , true ) ;
break;
case V_68 :
if ( V_60 )
F_8 ( V_20 , false ) ;
else
F_7 ( V_20 , false ) ;
break;
case V_69 :
case V_70 :
if ( V_60 )
F_6 ( V_20 , false ) ;
else
F_5 ( V_20 , false ) ;
break;
default:
V_51 = - V_40 ;
break;
}
return V_51 ;
}
static int F_24 ( struct V_41 * V_42 ,
struct V_18 * V_19 )
{
struct V_1 * V_20 = F_10 ( V_19 -> V_21 ) ;
int V_51 ;
V_51 = F_25 ( V_20 -> V_57 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_25 ( V_20 -> V_71 ) ;
if ( V_51 ) {
F_26 ( V_20 -> V_57 ) ;
return V_51 ;
}
return 0 ;
}
static void F_27 ( struct V_41 * V_42 ,
struct V_18 * V_19 )
{
struct V_1 * V_20 = F_10 ( V_19 -> V_21 ) ;
F_26 ( V_20 -> V_71 ) ;
F_26 ( V_20 -> V_57 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
unsigned int V_5 ;
F_3 ( V_2 , V_7 , V_72 ) ;
V_5 = F_1 ( V_2 , V_30 ) ;
V_5 |= V_73 ;
V_5 &= ~ V_74 ;
V_5 |= V_75 ;
F_3 ( V_2 , V_30 , V_5 ) ;
F_3 ( V_2 , V_76 , V_77 ) ;
F_3 ( V_2 , V_78 , V_79 ) ;
F_3 ( V_2 , V_15 , V_64 ) ;
F_3 ( V_2 , V_11 , V_65 ) ;
V_5 = F_1 ( V_2 , V_15 ) ;
V_5 &= ~ ( V_80 | V_81 ) ;
V_5 |= F_29 ( 8 ) ;
F_3 ( V_2 , V_15 , V_5 ) ;
V_5 = F_1 ( V_2 , V_11 ) ;
V_5 &= ~ ( V_82 | V_83 ) ;
V_5 |= F_29 ( 8 ) ;
F_3 ( V_2 , V_11 , V_5 ) ;
}
static int F_30 ( struct V_84 * V_85 )
{
struct V_86 * V_21 = & V_85 -> V_21 ;
struct V_87 V_88 ;
unsigned int V_89 ;
struct V_1 * V_20 ;
unsigned int V_90 ;
struct V_91 * V_92 ;
struct V_93 * V_94 ;
int V_51 ;
V_20 = F_31 ( & V_85 -> V_21 , sizeof( * V_20 ) , V_95 ) ;
if ( ! V_20 )
return - V_96 ;
V_20 -> V_21 = V_21 ;
V_20 -> V_57 = F_32 ( & V_85 -> V_21 , L_3 ) ;
if ( F_33 ( V_20 -> V_57 ) ) {
F_15 ( & V_85 -> V_21 , L_4 ) ;
return F_34 ( V_20 -> V_57 ) ;
}
V_20 -> V_71 = F_32 ( & V_85 -> V_21 , L_5 ) ;
if ( F_33 ( V_20 -> V_71 ) ) {
F_15 ( & V_85 -> V_21 , L_6 ) ;
return F_34 ( V_20 -> V_71 ) ;
}
V_92 = F_35 ( V_85 , V_97 , 0 ) ;
V_20 -> V_24 = V_92 -> V_98 ;
V_20 -> V_4 = F_36 ( & V_85 -> V_21 , V_92 ) ;
if ( F_33 ( V_20 -> V_4 ) )
return F_34 ( V_20 -> V_4 ) ;
V_51 = F_37 ( V_85 -> V_21 . V_99 ,
L_7 , 2 , 0 , & V_88 ) ;
if ( V_51 ) {
F_15 ( & V_85 -> V_21 , L_8 ) ;
return V_51 ;
}
V_89 = V_88 . args [ 0 ] ;
V_90 = V_88 . args [ 1 ] ;
V_94 = F_38 ( V_88 . V_100 ) ;
if ( F_33 ( V_94 ) ) {
F_39 ( V_88 . V_100 ) ;
return F_34 ( V_94 ) ;
}
F_40 ( V_94 , V_89 , V_90 , V_90 ) ;
F_39 ( V_88 . V_100 ) ;
F_28 ( V_20 ) ;
F_41 ( V_85 , V_20 ) ;
V_51 = F_42 ( & V_85 -> V_21 , & V_101 ,
& V_102 , 1 ) ;
if ( V_51 ) {
F_15 ( & V_85 -> V_21 , L_9 , V_51 ) ;
return V_51 ;
}
V_51 = F_43 ( & V_85 -> V_21 , NULL , 0 ) ;
if ( V_51 )
F_15 ( & V_85 -> V_21 , L_10 , V_51 ) ;
return V_51 ;
}
