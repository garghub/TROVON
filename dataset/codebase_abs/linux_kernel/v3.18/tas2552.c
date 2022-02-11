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
if ( ! V_15 -> V_22 )
return - V_23 ;
F_2 ( V_6 , V_24 , V_25 , 0 ) ;
if ( V_15 -> V_22 == V_26 ||
V_15 -> V_22 == V_27 ) {
F_2 ( V_6 , V_28 ,
V_29 ,
V_30 ) ;
} else {
V_20 = F_5 ( V_6 , V_31 ) ;
V_20 = ( V_20 >> 7 ) ;
V_17 = F_6 ( V_11 ) ;
if ( V_17 == 48000 )
V_18 = V_26 ;
else if ( V_17 == 44100 )
V_18 = V_27 ;
else {
F_7 ( V_6 -> V_16 , L_1 ,
F_6 ( V_11 ) ) ;
return - V_23 ;
}
V_21 = ( V_18 * 2 * ( 1 << V_20 ) ) / V_15 -> V_22 ;
V_19 = ( V_18 * 2 * ( 1 << V_20 ) ) % V_15 -> V_22 ;
F_2 ( V_6 , V_31 ,
V_32 , V_21 ) ;
F_8 ( V_6 , V_28 ,
( V_19 >> 7 ) & V_33 ) ;
F_8 ( V_6 , V_34 ,
V_19 & V_35 ) ;
}
return 0 ;
}
static int F_9 ( struct V_12 * V_13 , unsigned int V_36 )
{
struct V_14 * V_6 = V_13 -> V_6 ;
T_1 V_37 ;
T_1 V_38 ;
switch ( V_36 & V_39 ) {
case V_40 :
V_37 = 0x00 ;
break;
case V_41 :
V_37 = V_42 ;
break;
case V_43 :
V_37 = V_44 ;
break;
case V_45 :
V_37 = ( V_44 | V_42 ) ;
break;
default:
F_7 ( V_6 -> V_16 , L_2 ) ;
return - V_23 ;
}
V_38 = V_44 | V_42 ;
switch ( V_36 & V_46 ) {
case V_47 :
V_37 &= V_48 ;
break;
case V_49 :
V_37 |= V_50 ;
break;
case V_51 :
V_37 |= V_52 ;
break;
case V_53 :
V_37 |= V_54 ;
break;
default:
F_7 ( V_6 -> V_16 , L_3 ) ;
return - V_23 ;
}
if ( V_36 & V_46 )
V_38 |= V_55 ;
F_2 ( V_6 , V_56 , V_38 ,
V_37 ) ;
return 0 ;
}
static int F_10 ( struct V_12 * V_13 , int V_57 ,
unsigned int V_58 , int V_59 )
{
struct V_14 * V_6 = V_13 -> V_6 ;
struct V_1 * V_15 = F_4 ( V_6 -> V_16 ) ;
V_15 -> V_22 = V_58 ;
return 0 ;
}
static int F_11 ( struct V_12 * V_13 , int V_60 )
{
T_1 V_4 ;
struct V_14 * V_6 = V_13 -> V_6 ;
if ( V_60 )
V_4 = V_61 ;
else
V_4 = ~ V_61 ;
F_2 ( V_6 , V_7 , V_61 , V_4 ) ;
return 0 ;
}
static int F_12 ( struct V_62 * V_16 )
{
struct V_1 * V_15 = F_4 ( V_16 ) ;
F_1 ( V_15 , 0 ) ;
F_13 ( V_15 -> V_63 , true ) ;
F_14 ( V_15 -> V_63 ) ;
if ( V_15 -> V_64 )
F_15 ( V_15 -> V_64 , 0 ) ;
return 0 ;
}
static int F_16 ( struct V_62 * V_16 )
{
struct V_1 * V_15 = F_4 ( V_16 ) ;
if ( V_15 -> V_64 )
F_15 ( V_15 -> V_64 , 1 ) ;
F_1 ( V_15 , 1 ) ;
F_13 ( V_15 -> V_63 , false ) ;
F_17 ( V_15 -> V_63 ) ;
return 0 ;
}
static int F_18 ( struct V_14 * V_6 )
{
struct V_1 * V_15 = F_19 ( V_6 ) ;
struct V_65 * V_66 = & V_6 -> V_66 ;
int V_67 ;
V_15 -> V_6 = V_6 ;
V_67 = F_20 ( F_21 ( V_15 -> V_68 ) ,
V_15 -> V_68 ) ;
if ( V_67 != 0 ) {
F_22 ( V_6 -> V_16 , L_4 ,
V_67 ) ;
return V_67 ;
}
if ( V_15 -> V_64 )
F_15 ( V_15 -> V_64 , 1 ) ;
V_67 = F_23 ( V_6 -> V_16 ) ;
if ( V_67 < 0 ) {
F_22 ( V_6 -> V_16 , L_5 ,
V_67 ) ;
goto V_69;
}
F_8 ( V_6 , V_7 , V_61 |
V_70 ) ;
F_8 ( V_6 , V_71 , V_72 |
V_73 | V_74 ) ;
F_8 ( V_6 , V_75 , V_76 ) ;
F_8 ( V_6 , V_77 , V_78 | 0x8 ) ;
F_8 ( V_6 , V_79 , V_80 ) ;
F_8 ( V_6 , V_81 , V_82 |
V_83 ) ;
V_67 = F_24 ( V_15 -> V_63 , V_84 ,
F_21 ( V_84 ) ) ;
if ( V_67 != 0 ) {
F_22 ( V_6 -> V_16 , L_6 ,
V_67 ) ;
goto V_85;
}
F_8 ( V_6 , V_24 , V_86 |
V_87 | V_88 ) ;
F_25 ( V_66 , V_89 ,
F_21 ( V_89 ) ) ;
F_26 ( V_66 , V_90 ,
F_21 ( V_90 ) ) ;
return 0 ;
V_85:
F_27 ( V_6 -> V_16 ) ;
V_69:
if ( V_15 -> V_64 )
F_15 ( V_15 -> V_64 , 0 ) ;
F_28 ( F_21 ( V_15 -> V_68 ) ,
V_15 -> V_68 ) ;
return - V_91 ;
}
static int F_29 ( struct V_14 * V_6 )
{
struct V_1 * V_15 = F_19 ( V_6 ) ;
F_27 ( V_6 -> V_16 ) ;
if ( V_15 -> V_64 )
F_15 ( V_15 -> V_64 , 0 ) ;
return 0 ;
}
static int F_30 ( struct V_14 * V_6 )
{
struct V_1 * V_15 = F_19 ( V_6 ) ;
int V_67 ;
V_67 = F_28 ( F_21 ( V_15 -> V_68 ) ,
V_15 -> V_68 ) ;
if ( V_67 != 0 )
F_22 ( V_6 -> V_16 , L_7 ,
V_67 ) ;
return 0 ;
}
static int F_31 ( struct V_14 * V_6 )
{
struct V_1 * V_15 = F_19 ( V_6 ) ;
int V_67 ;
V_67 = F_20 ( F_21 ( V_15 -> V_68 ) ,
V_15 -> V_68 ) ;
if ( V_67 != 0 ) {
F_22 ( V_6 -> V_16 , L_4 ,
V_67 ) ;
}
return 0 ;
}
static int F_32 ( struct V_92 * V_93 ,
const struct V_94 * V_95 )
{
struct V_62 * V_16 ;
struct V_1 * V_96 ;
int V_67 ;
int V_97 ;
V_16 = & V_93 -> V_16 ;
V_96 = F_33 ( & V_93 -> V_16 , sizeof( * V_96 ) , V_98 ) ;
if ( V_96 == NULL )
return - V_99 ;
V_96 -> V_64 = F_34 ( V_16 , L_8 ) ;
if ( F_35 ( V_96 -> V_64 ) ) {
V_67 = F_36 ( V_96 -> V_64 ) ;
if ( V_67 != - V_100 && V_67 != - V_101 )
return V_67 ;
V_96 -> V_64 = NULL ;
} else {
F_37 ( V_96 -> V_64 , 0 ) ;
}
V_96 -> V_102 = V_93 ;
V_96 -> V_63 = F_38 ( V_93 , & V_103 ) ;
if ( F_35 ( V_96 -> V_63 ) ) {
V_67 = F_36 ( V_96 -> V_63 ) ;
F_22 ( & V_93 -> V_16 , L_9 ,
V_67 ) ;
return V_67 ;
}
for ( V_97 = 0 ; V_97 < F_21 ( V_96 -> V_68 ) ; V_97 ++ )
V_96 -> V_68 [ V_97 ] . V_104 = V_105 [ V_97 ] ;
V_67 = F_39 ( V_16 , F_21 ( V_96 -> V_68 ) ,
V_96 -> V_68 ) ;
if ( V_67 != 0 ) {
F_22 ( V_16 , L_10 , V_67 ) ;
return V_67 ;
}
F_40 ( & V_93 -> V_16 ) ;
F_41 ( & V_93 -> V_16 , 1000 ) ;
F_42 ( & V_93 -> V_16 ) ;
F_43 ( & V_93 -> V_16 ) ;
F_44 ( & V_93 -> V_16 ) ;
F_45 ( & V_93 -> V_16 ) ;
F_46 ( & V_93 -> V_16 , V_96 ) ;
V_67 = F_47 ( & V_93 -> V_16 ,
& V_106 ,
V_107 , F_21 ( V_107 ) ) ;
if ( V_67 < 0 )
F_22 ( & V_93 -> V_16 , L_11 , V_67 ) ;
return V_67 ;
}
static int F_48 ( struct V_92 * V_93 )
{
F_49 ( & V_93 -> V_16 ) ;
return 0 ;
}
