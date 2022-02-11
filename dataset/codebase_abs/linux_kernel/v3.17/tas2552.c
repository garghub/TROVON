static void F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
if ( V_3 )
V_4 = 0 ;
else
V_4 = V_5 ;
F_2 ( V_2 -> V_6 , V_7 ,
V_5 , V_4 ) ;
}
static int F_3 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_14 * V_6 = V_13 -> V_6 ;
struct V_1 * V_15 = F_4 ( V_6 -> V_16 ) ;
int V_17 , V_18 ;
int V_19 ;
T_1 V_20 , V_21 ;
F_2 ( V_6 , V_22 , V_23 ,
V_24 ) ;
if ( ! V_15 -> V_25 )
return - V_26 ;
F_2 ( V_6 , V_22 , V_27 , 0 ) ;
if ( V_15 -> V_25 == V_28 ||
V_15 -> V_25 == V_29 ) {
F_2 ( V_6 , V_30 ,
V_31 ,
V_32 ) ;
} else {
V_20 = F_5 ( V_6 , V_33 ) ;
V_20 = ( V_20 >> 7 ) ;
V_17 = F_6 ( V_11 ) ;
if ( V_17 == 48000 )
V_18 = V_28 ;
else if ( V_17 == 44100 )
V_18 = V_29 ;
else {
F_7 ( V_6 -> V_16 , L_1 ,
F_6 ( V_11 ) ) ;
return - V_26 ;
}
V_21 = ( V_18 * 2 * ( 1 << V_20 ) ) / V_15 -> V_25 ;
V_19 = ( V_18 * 2 * ( 1 << V_20 ) ) % V_15 -> V_25 ;
F_2 ( V_6 , V_33 ,
V_34 , V_21 ) ;
F_8 ( V_6 , V_30 ,
( V_19 >> 7 ) & V_35 ) ;
F_8 ( V_6 , V_36 ,
V_19 & V_37 ) ;
}
F_2 ( V_6 , V_22 , V_27 ,
V_27 ) ;
return 0 ;
}
static int F_9 ( struct V_12 * V_13 , unsigned int V_38 )
{
struct V_14 * V_6 = V_13 -> V_6 ;
T_1 V_39 ;
T_1 V_40 ;
switch ( V_38 & V_41 ) {
case V_42 :
V_39 = 0x00 ;
break;
case V_43 :
V_39 = V_44 ;
break;
case V_45 :
V_39 = V_46 ;
break;
case V_47 :
V_39 = ( V_46 | V_44 ) ;
break;
default:
F_7 ( V_6 -> V_16 , L_2 ) ;
return - V_26 ;
}
V_40 = V_46 | V_44 ;
switch ( V_38 & V_48 ) {
case V_49 :
V_39 &= V_50 ;
break;
case V_51 :
V_39 |= V_52 ;
break;
case V_53 :
V_39 |= V_54 ;
break;
case V_55 :
V_39 |= V_56 ;
break;
default:
F_7 ( V_6 -> V_16 , L_3 ) ;
return - V_26 ;
}
if ( V_38 & V_48 )
V_40 |= V_57 ;
F_2 ( V_6 , V_58 , V_40 ,
V_39 ) ;
return 0 ;
}
static int F_10 ( struct V_12 * V_13 , int V_59 ,
unsigned int V_60 , int V_61 )
{
struct V_14 * V_6 = V_13 -> V_6 ;
struct V_1 * V_15 = F_4 ( V_6 -> V_16 ) ;
V_15 -> V_25 = V_60 ;
return 0 ;
}
static int F_11 ( struct V_12 * V_13 , int V_62 )
{
T_1 V_4 ;
struct V_14 * V_6 = V_13 -> V_6 ;
if ( V_62 )
V_4 = V_63 ;
else
V_4 = ~ V_63 ;
F_2 ( V_6 , V_7 , V_63 , V_4 ) ;
return 0 ;
}
static int F_12 ( struct V_64 * V_16 )
{
struct V_1 * V_15 = F_4 ( V_16 ) ;
F_1 ( V_15 , 0 ) ;
F_13 ( V_15 -> V_65 , true ) ;
F_14 ( V_15 -> V_65 ) ;
if ( V_15 -> V_66 )
F_15 ( V_15 -> V_66 , 0 ) ;
return 0 ;
}
static int F_16 ( struct V_64 * V_16 )
{
struct V_1 * V_15 = F_4 ( V_16 ) ;
if ( V_15 -> V_66 )
F_15 ( V_15 -> V_66 , 1 ) ;
F_1 ( V_15 , 1 ) ;
F_13 ( V_15 -> V_65 , false ) ;
F_17 ( V_15 -> V_65 ) ;
return 0 ;
}
static void F_18 ( struct V_8 * V_9 ,
struct V_12 * V_13 )
{
struct V_14 * V_6 = V_13 -> V_6 ;
F_2 ( V_6 , V_22 , V_27 , 0 ) ;
}
static int F_19 ( struct V_14 * V_6 )
{
struct V_1 * V_15 = F_20 ( V_6 ) ;
int V_67 ;
V_15 -> V_6 = V_6 ;
V_67 = F_21 ( F_22 ( V_15 -> V_68 ) ,
V_15 -> V_68 ) ;
if ( V_67 != 0 ) {
F_23 ( V_6 -> V_16 , L_4 ,
V_67 ) ;
return V_67 ;
}
if ( V_15 -> V_66 )
F_15 ( V_15 -> V_66 , 1 ) ;
V_67 = F_24 ( V_6 -> V_16 ) ;
if ( V_67 < 0 ) {
F_23 ( V_6 -> V_16 , L_5 ,
V_67 ) ;
goto V_69;
}
F_8 ( V_6 , V_7 , V_63 |
V_70 ) ;
F_8 ( V_6 , V_71 , V_72 |
V_73 | V_74 ) ;
F_8 ( V_6 , V_75 , V_76 ) ;
F_8 ( V_6 , V_77 , V_78 | 0x8 ) ;
F_8 ( V_6 , V_79 , V_80 ) ;
F_8 ( V_6 , V_81 , V_82 |
V_83 ) ;
V_67 = F_25 ( V_15 -> V_65 , V_84 ,
F_22 ( V_84 ) ) ;
if ( V_67 != 0 ) {
F_23 ( V_6 -> V_16 , L_6 ,
V_67 ) ;
goto V_85;
}
F_8 ( V_6 , V_22 , V_24 |
V_86 | V_87 |
V_88 ) ;
return 0 ;
V_85:
F_26 ( V_6 -> V_16 ) ;
V_69:
if ( V_15 -> V_66 )
F_15 ( V_15 -> V_66 , 0 ) ;
F_27 ( F_22 ( V_15 -> V_68 ) ,
V_15 -> V_68 ) ;
return - V_89 ;
}
static int F_28 ( struct V_14 * V_6 )
{
struct V_1 * V_15 = F_20 ( V_6 ) ;
F_26 ( V_6 -> V_16 ) ;
if ( V_15 -> V_66 )
F_15 ( V_15 -> V_66 , 0 ) ;
return 0 ;
}
static int F_29 ( struct V_14 * V_6 )
{
struct V_1 * V_15 = F_20 ( V_6 ) ;
int V_67 ;
V_67 = F_27 ( F_22 ( V_15 -> V_68 ) ,
V_15 -> V_68 ) ;
if ( V_67 != 0 )
F_23 ( V_6 -> V_16 , L_7 ,
V_67 ) ;
return 0 ;
}
static int F_30 ( struct V_14 * V_6 )
{
struct V_1 * V_15 = F_20 ( V_6 ) ;
int V_67 ;
V_67 = F_21 ( F_22 ( V_15 -> V_68 ) ,
V_15 -> V_68 ) ;
if ( V_67 != 0 ) {
F_23 ( V_6 -> V_16 , L_4 ,
V_67 ) ;
}
return 0 ;
}
static int F_31 ( struct V_90 * V_91 ,
const struct V_92 * V_93 )
{
struct V_64 * V_16 ;
struct V_1 * V_94 ;
int V_67 ;
int V_95 ;
V_16 = & V_91 -> V_16 ;
V_94 = F_32 ( & V_91 -> V_16 , sizeof( * V_94 ) , V_96 ) ;
if ( V_94 == NULL )
return - V_97 ;
V_94 -> V_66 = F_33 ( V_16 , L_8 ) ;
if ( F_34 ( V_94 -> V_66 ) ) {
V_67 = F_35 ( V_94 -> V_66 ) ;
if ( V_67 != - V_98 && V_67 != - V_99 )
return V_67 ;
V_94 -> V_66 = NULL ;
} else {
F_36 ( V_94 -> V_66 , 0 ) ;
}
V_94 -> V_100 = V_91 ;
V_94 -> V_65 = F_37 ( V_91 , & V_101 ) ;
if ( F_34 ( V_94 -> V_65 ) ) {
V_67 = F_35 ( V_94 -> V_65 ) ;
F_23 ( & V_91 -> V_16 , L_9 ,
V_67 ) ;
return V_67 ;
}
for ( V_95 = 0 ; V_95 < F_22 ( V_94 -> V_68 ) ; V_95 ++ )
V_94 -> V_68 [ V_95 ] . V_102 = V_103 [ V_95 ] ;
V_67 = F_38 ( V_16 , F_22 ( V_94 -> V_68 ) ,
V_94 -> V_68 ) ;
if ( V_67 != 0 ) {
F_23 ( V_16 , L_10 , V_67 ) ;
return V_67 ;
}
F_39 ( & V_91 -> V_16 ) ;
F_40 ( & V_91 -> V_16 , 1000 ) ;
F_41 ( & V_91 -> V_16 ) ;
F_42 ( & V_91 -> V_16 ) ;
F_43 ( & V_91 -> V_16 ) ;
F_44 ( & V_91 -> V_16 ) ;
F_45 ( & V_91 -> V_16 , V_94 ) ;
V_67 = F_46 ( & V_91 -> V_16 ,
& V_104 ,
V_105 , F_22 ( V_105 ) ) ;
if ( V_67 < 0 )
F_23 ( & V_91 -> V_16 , L_11 , V_67 ) ;
return V_67 ;
}
static int F_47 ( struct V_90 * V_91 )
{
F_48 ( & V_91 -> V_16 ) ;
return 0 ;
}
