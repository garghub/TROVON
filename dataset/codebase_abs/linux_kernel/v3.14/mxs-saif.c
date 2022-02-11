static int F_1 ( struct V_1 * V_2 ,
int V_3 , unsigned int V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
switch ( V_3 ) {
case V_8 :
V_7 -> V_9 = V_4 ;
break;
default:
return - V_10 ;
}
return 0 ;
}
static inline struct V_6 * F_3 ( struct V_6 * V_7 )
{
return V_6 [ V_7 -> V_11 ] ;
}
static int F_4 ( struct V_6 * V_7 ,
unsigned int V_9 ,
unsigned int V_12 )
{
T_1 V_13 ;
int V_14 ;
struct V_6 * V_15 ;
F_5 ( V_7 -> V_16 , L_1 , V_9 , V_12 ) ;
V_15 = F_3 ( V_7 ) ;
if ( ! V_15 )
return - V_10 ;
F_5 ( V_7 -> V_16 , L_2 , V_15 -> V_17 ) ;
if ( V_15 -> V_18 && V_12 != V_15 -> V_19 ) {
F_6 ( V_7 -> V_16 ,
L_3 ,
V_15 -> V_17 , V_15 -> V_19 ) ;
return - V_10 ;
}
V_13 = F_7 ( V_15 -> V_20 + V_21 ) ;
V_13 &= ~ V_22 ;
V_13 &= ~ V_23 ;
F_8 ( V_15 -> V_24 ) ;
if ( V_15 -> V_25 ) {
if ( V_9 % 32 == 0 ) {
V_13 &= ~ V_23 ;
V_14 = F_9 ( V_15 -> V_24 , 512 * V_12 ) ;
} else if ( V_9 % 48 == 0 ) {
V_13 |= V_23 ;
V_14 = F_9 ( V_15 -> V_24 , 384 * V_12 ) ;
} else {
F_10 ( V_15 -> V_24 ) ;
return - V_10 ;
}
} else {
V_14 = F_9 ( V_15 -> V_24 , 512 * V_12 ) ;
V_13 &= ~ V_23 ;
}
F_10 ( V_15 -> V_24 ) ;
if ( V_14 )
return V_14 ;
V_15 -> V_19 = V_12 ;
if ( ! V_15 -> V_25 ) {
F_11 ( V_13 , V_15 -> V_20 + V_21 ) ;
return 0 ;
}
switch ( V_9 / V_12 ) {
case 32 :
V_13 |= F_12 ( 4 ) ;
break;
case 64 :
V_13 |= F_12 ( 3 ) ;
break;
case 128 :
V_13 |= F_12 ( 2 ) ;
break;
case 256 :
V_13 |= F_12 ( 1 ) ;
break;
case 512 :
V_13 |= F_12 ( 0 ) ;
break;
case 48 :
V_13 |= F_12 ( 3 ) ;
break;
case 96 :
V_13 |= F_12 ( 2 ) ;
break;
case 192 :
V_13 |= F_12 ( 1 ) ;
break;
case 384 :
V_13 |= F_12 ( 0 ) ;
break;
default:
return - V_10 ;
}
F_11 ( V_13 , V_15 -> V_20 + V_21 ) ;
return 0 ;
}
int F_13 ( unsigned int V_26 )
{
struct V_6 * V_7 = V_6 [ V_26 ] ;
T_1 V_27 ;
if ( ! V_7 )
return - V_10 ;
V_27 = F_7 ( V_7 -> V_20 + V_28 ) ;
if ( V_27 & V_29 ) {
F_6 ( V_7 -> V_16 , L_4 ) ;
return - V_30 ;
}
F_10 ( V_7 -> V_24 ) ;
F_11 ( V_31 ,
V_7 -> V_20 + V_21 + V_32 ) ;
F_11 ( V_33 ,
V_7 -> V_20 + V_21 + V_34 ) ;
V_7 -> V_25 = 0 ;
return 0 ;
}
int F_14 ( unsigned int V_26 , unsigned int V_9 ,
unsigned int V_12 )
{
struct V_6 * V_7 = V_6 [ V_26 ] ;
T_1 V_27 ;
int V_14 ;
struct V_6 * V_15 ;
if ( ! V_7 )
return - V_10 ;
F_11 ( V_35 ,
V_7 -> V_20 + V_21 + V_34 ) ;
F_11 ( V_31 ,
V_7 -> V_20 + V_21 + V_34 ) ;
V_15 = F_3 ( V_7 ) ;
if ( V_7 != V_15 ) {
F_6 ( V_7 -> V_16 , L_5 ) ;
return - V_10 ;
}
V_27 = F_7 ( V_7 -> V_20 + V_28 ) ;
if ( V_27 & V_29 ) {
F_6 ( V_7 -> V_16 , L_4 ) ;
return - V_30 ;
}
V_7 -> V_25 = 1 ;
V_14 = F_4 ( V_7 , V_9 , V_12 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_8 ( V_7 -> V_24 ) ;
if ( V_14 )
return V_14 ;
F_11 ( V_33 ,
V_7 -> V_20 + V_21 + V_32 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned int V_36 )
{
T_1 V_13 , V_27 ;
T_1 V_37 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_27 = F_7 ( V_7 -> V_20 + V_28 ) ;
if ( V_27 & V_29 ) {
F_6 ( V_2 -> V_16 , L_4 ) ;
return - V_30 ;
}
V_37 = F_7 ( V_7 -> V_20 + V_21 ) ;
V_37 = V_37 & ~ V_38 & ~ V_39 \
& ~ V_40 & ~ V_41 ;
V_13 = 0 ;
switch ( V_36 & V_42 ) {
case V_43 :
V_13 |= V_41 ;
V_13 &= ~ V_39 ;
break;
case V_44 :
V_13 &= ~ V_41 ;
V_13 &= ~ V_39 ;
V_13 &= ~ V_40 ;
break;
default:
return - V_10 ;
}
switch ( V_36 & V_45 ) {
case V_46 :
V_13 |= V_38 ;
V_13 |= V_39 ;
break;
case V_47 :
V_13 |= V_38 ;
V_13 &= ~ V_39 ;
break;
case V_48 :
V_13 &= ~ V_38 ;
V_13 |= V_39 ;
break;
case V_49 :
V_13 &= ~ V_38 ;
V_13 &= ~ V_39 ;
break;
}
switch ( V_36 & V_50 ) {
case V_51 :
if ( V_7 -> V_17 == V_7 -> V_11 )
V_13 &= ~ V_52 ;
else
V_13 |= V_52 ;
F_11 ( V_13 | V_37 , V_7 -> V_20 + V_21 ) ;
break;
default:
return - V_10 ;
}
return 0 ;
}
static int F_16 ( struct V_53 * V_54 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_55 = 0 ;
V_7 -> V_56 = 0 ;
F_11 ( V_35 ,
V_7 -> V_20 + V_21 + V_34 ) ;
F_11 ( V_31 ,
V_7 -> V_20 + V_21 + V_34 ) ;
return 0 ;
}
static int F_17 ( struct V_53 * V_54 ,
struct V_57 * V_58 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_6 * V_15 ;
T_1 V_13 , V_27 ;
int V_14 ;
V_15 = F_3 ( V_7 ) ;
if ( ! V_15 )
return - V_10 ;
if ( ! V_7 -> V_9 && V_7 -> V_25 ) {
F_6 ( V_2 -> V_16 , L_6 ) ;
return - V_10 ;
}
V_27 = F_7 ( V_7 -> V_20 + V_28 ) ;
if ( V_27 & V_29 ) {
F_6 ( V_2 -> V_16 , L_4 ) ;
return - V_30 ;
}
V_14 = F_4 ( V_7 , V_7 -> V_9 , F_18 ( V_58 ) ) ;
if ( V_14 ) {
F_6 ( V_2 -> V_16 , L_7 ) ;
return V_14 ;
}
F_19 ( V_7 -> V_24 ) ;
if ( V_7 != V_15 ) {
F_20 ( V_7 -> V_24 ) ;
V_14 = F_9 ( V_7 -> V_24 , 24000000 ) ;
F_21 ( V_7 -> V_24 ) ;
if ( V_14 )
return V_14 ;
F_19 ( V_15 -> V_24 ) ;
}
V_13 = F_7 ( V_7 -> V_20 + V_21 ) ;
V_13 &= ~ V_59 ;
V_13 &= ~ V_60 ;
switch ( F_22 ( V_58 ) ) {
case V_61 :
V_13 |= F_23 ( 0 ) ;
break;
case V_62 :
V_13 |= F_23 ( 4 ) ;
V_13 |= V_60 ;
break;
case V_63 :
V_13 |= F_23 ( 8 ) ;
V_13 |= V_60 ;
break;
default:
return - V_10 ;
}
if ( V_54 -> V_64 == V_65 ) {
V_13 &= ~ V_66 ;
} else {
V_13 |= V_66 ;
}
F_11 ( V_13 , V_7 -> V_20 + V_21 ) ;
return 0 ;
}
static int F_24 ( struct V_53 * V_54 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_11 ( V_67 ,
V_7 -> V_20 + V_21 + V_32 ) ;
return 0 ;
}
static int F_25 ( struct V_53 * V_54 , int V_68 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_6 * V_15 ;
T_1 V_69 ;
int V_14 ;
V_15 = F_3 ( V_7 ) ;
if ( ! V_15 )
return - V_10 ;
switch ( V_68 ) {
case V_70 :
case V_71 :
case V_72 :
if ( V_7 -> V_73 == V_74 )
return 0 ;
F_5 ( V_2 -> V_16 , L_8 ) ;
V_14 = F_20 ( V_15 -> V_24 ) ;
if ( V_14 ) {
F_6 ( V_7 -> V_16 , L_9 ) ;
return V_14 ;
}
if ( V_7 != V_15 ) {
V_14 = F_20 ( V_7 -> V_24 ) ;
if ( V_14 ) {
F_6 ( V_7 -> V_16 , L_9 ) ;
F_21 ( V_15 -> V_24 ) ;
return V_14 ;
}
F_11 ( V_33 ,
V_7 -> V_20 + V_21 + V_32 ) ;
}
if ( ! V_15 -> V_25 )
F_11 ( V_33 ,
V_15 -> V_20 + V_21 + V_32 ) ;
if ( V_54 -> V_64 == V_65 ) {
F_11 ( 0 , V_7 -> V_20 + V_75 ) ;
F_11 ( 0 , V_7 -> V_20 + V_75 ) ;
} else {
F_7 ( V_7 -> V_20 + V_75 ) ;
F_7 ( V_7 -> V_20 + V_75 ) ;
}
V_15 -> V_18 = 1 ;
V_7 -> V_73 = V_74 ;
F_5 ( V_7 -> V_16 , L_10 ,
F_7 ( V_7 -> V_20 + V_21 ) ,
F_7 ( V_7 -> V_20 + V_28 ) ) ;
F_5 ( V_15 -> V_16 , L_10 ,
F_7 ( V_15 -> V_20 + V_21 ) ,
F_7 ( V_15 -> V_20 + V_28 ) ) ;
break;
case V_76 :
case V_77 :
case V_78 :
if ( V_7 -> V_73 == V_79 )
return 0 ;
F_5 ( V_2 -> V_16 , L_11 ) ;
V_69 = V_80 / V_15 -> V_19 ;
if ( ! V_15 -> V_25 ) {
F_11 ( V_33 ,
V_15 -> V_20 + V_21 + V_34 ) ;
F_26 ( V_69 ) ;
}
F_21 ( V_15 -> V_24 ) ;
if ( V_7 != V_15 ) {
F_11 ( V_33 ,
V_7 -> V_20 + V_21 + V_34 ) ;
F_26 ( V_69 ) ;
F_21 ( V_7 -> V_24 ) ;
}
V_15 -> V_18 = 0 ;
V_7 -> V_73 = V_79 ;
break;
default:
return - V_10 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_81 )
{
struct V_6 * V_7 = F_28 ( V_81 -> V_16 ) ;
F_29 ( V_81 , V_7 ) ;
return 0 ;
}
static T_2 F_30 ( int V_82 , void * V_83 )
{
struct V_6 * V_7 = V_83 ;
unsigned int V_27 ;
V_27 = F_7 ( V_7 -> V_20 + V_28 ) ;
if ( ! ( V_27 & ( V_84 |
V_85 ) ) )
return V_86 ;
if ( V_27 & V_84 ) {
F_5 ( V_7 -> V_16 , L_12 , ++ V_7 -> V_55 ) ;
F_11 ( V_84 ,
V_7 -> V_20 + V_28 + V_34 ) ;
}
if ( V_27 & V_85 ) {
F_5 ( V_7 -> V_16 , L_13 , ++ V_7 -> V_56 ) ;
F_11 ( V_85 ,
V_7 -> V_20 + V_28 + V_34 ) ;
}
F_5 ( V_7 -> V_16 , L_14 ,
F_7 ( V_7 -> V_20 + V_21 ) ,
F_7 ( V_7 -> V_20 + V_28 ) ) ;
return V_87 ;
}
static int F_31 ( struct V_88 * V_89 )
{
struct V_6 * V_7 = F_32 ( V_89 ) ;
struct V_90 * V_91 = V_89 -> V_16 . V_92 ;
struct V_24 * V_24 ;
int V_14 ;
V_24 = F_33 ( & V_89 -> V_16 , L_15 ,
F_34 ( V_7 -> V_24 ) , 0 ,
V_7 -> V_20 + V_21 ,
V_93 , 3 ,
0 , NULL ) ;
if ( F_35 ( V_24 ) ) {
V_14 = F_36 ( V_24 ) ;
if ( V_14 == - V_94 )
return 0 ;
F_6 ( & V_89 -> V_16 , L_16 , V_14 ) ;
return F_36 ( V_24 ) ;
}
V_14 = F_37 ( V_91 , V_95 , V_24 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
static int F_38 ( struct V_88 * V_89 )
{
struct V_90 * V_91 = V_89 -> V_16 . V_92 ;
struct V_96 * V_97 ;
struct V_6 * V_7 ;
int V_14 = 0 ;
struct V_90 * V_98 ;
if ( ! V_91 )
return - V_10 ;
V_7 = F_39 ( & V_89 -> V_16 , sizeof( * V_7 ) , V_99 ) ;
if ( ! V_7 )
return - V_100 ;
V_14 = F_40 ( V_91 , L_17 ) ;
if ( V_14 < 0 )
return V_14 ;
else
V_7 -> V_17 = V_14 ;
V_98 = F_41 ( V_91 , L_18 , 0 ) ;
if ( ! V_98 ) {
V_7 -> V_11 = V_7 -> V_17 ;
} else {
V_14 = F_40 ( V_98 , L_17 ) ;
if ( V_14 < 0 )
return V_14 ;
else
V_7 -> V_11 = V_14 ;
}
if ( V_7 -> V_11 >= F_42 ( V_6 ) ) {
F_6 ( & V_89 -> V_16 , L_19 ) ;
return - V_10 ;
}
V_6 [ V_7 -> V_17 ] = V_7 ;
V_7 -> V_24 = F_43 ( & V_89 -> V_16 , NULL ) ;
if ( F_35 ( V_7 -> V_24 ) ) {
V_14 = F_36 ( V_7 -> V_24 ) ;
F_6 ( & V_89 -> V_16 , L_20 ,
V_14 ) ;
return V_14 ;
}
V_97 = F_44 ( V_89 , V_101 , 0 ) ;
V_7 -> V_20 = F_45 ( & V_89 -> V_16 , V_97 ) ;
if ( F_35 ( V_7 -> V_20 ) )
return F_36 ( V_7 -> V_20 ) ;
V_7 -> V_82 = F_46 ( V_89 , 0 ) ;
if ( V_7 -> V_82 < 0 ) {
V_14 = V_7 -> V_82 ;
F_6 ( & V_89 -> V_16 , L_21 ,
V_14 ) ;
return V_14 ;
}
V_7 -> V_16 = & V_89 -> V_16 ;
V_14 = F_47 ( & V_89 -> V_16 , V_7 -> V_82 , F_30 , 0 ,
L_22 , V_7 ) ;
if ( V_14 ) {
F_6 ( & V_89 -> V_16 , L_23 ) ;
return V_14 ;
}
F_48 ( V_89 , V_7 ) ;
if ( V_7 -> V_17 == 0 ) {
V_14 = F_31 ( V_89 ) ;
if ( V_14 )
F_49 ( & V_89 -> V_16 , L_24 ) ;
}
V_14 = F_50 ( & V_89 -> V_16 , & V_102 ,
& V_103 , 1 ) ;
if ( V_14 ) {
F_6 ( & V_89 -> V_16 , L_25 ) ;
return V_14 ;
}
V_14 = F_51 ( & V_89 -> V_16 ) ;
if ( V_14 ) {
F_6 ( & V_89 -> V_16 , L_26 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
