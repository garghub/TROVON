static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = V_5 ;
V_2 -> V_3 . V_6 = V_7 ;
V_2 -> V_3 . V_8 = 1 ;
V_2 -> V_3 . V_9 = true ;
}
static void F_2 ( struct V_1 * V_2 )
{
struct V_10 * V_3 = & V_2 -> V_3 ;
struct V_11 V_12 ;
T_1 V_13 ;
T_1 V_14 ;
T_1 V_15 = 0 ;
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
V_14 =
F_3 ( V_2 -> V_16 + V_13 * V_17 ) ;
V_14 &= ~ V_18 ;
F_4 ( V_14 ,
V_2 -> V_16 + V_13 * V_17 ) ;
}
V_12 = V_19 [ V_3 -> V_4 ] ;
V_15 |= V_12 . V_20 ;
V_2 -> V_21 = V_12 . V_22 ;
V_15 |= V_3 -> V_8 ;
F_4 ( V_15 , V_2 -> V_16 + V_23 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_24 ;
V_24 = F_3 ( V_2 -> V_16 + V_25 ) ;
V_24 &= ~ ( V_26 |
V_27 ) ;
V_24 |= V_28 ;
F_4 ( V_24 , V_2 -> V_16 + V_25 ) ;
F_4 ( V_29 ,
V_2 -> V_16 + V_30 ) ;
F_4 ( V_29 ,
V_2 -> V_16 + V_31 ) ;
F_2 ( V_2 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 V_32 = 0 ;
T_1 V_33 ;
T_1 V_34 ;
V_34 = V_2 -> V_34 ;
V_32 |= ( V_18 |
V_35 ) ;
if ( V_2 -> V_3 . V_9 )
V_32 |= V_36 ;
V_32 |= F_7 ( V_34 ) ;
V_33 = F_3 ( V_2 -> V_16 + V_17 * V_34 +
V_37 ) ;
V_33 |= V_38 [ V_2 -> V_3 . V_6 ] ;
F_4 ( V_33 , V_2 -> V_16 + V_17 * V_34 +
V_37 ) ;
F_4 ( V_32 , V_2 -> V_16 + V_17 * V_34 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
T_1 V_39 = 24000000 ;
T_1 V_40 ;
T_1 V_8 = V_2 -> V_3 . V_8 ;
T_1 V_41 ;
V_40 = V_39 / V_2 -> V_21 ;
V_41 = ( V_8 + 1 ) * 6 ;
return V_40 / V_41 ;
}
static int F_9 ( struct V_42 * V_43 ,
struct V_44 const * V_45 ,
int * V_46 ,
int * V_47 ,
long V_48 )
{
struct V_1 * V_2 = F_10 ( V_43 ) ;
T_1 V_34 ;
long V_49 ;
switch ( V_48 ) {
case V_50 :
F_11 ( & V_43 -> V_51 ) ;
F_12 ( & V_2 -> V_52 ) ;
V_34 = V_45 -> V_34 & 0x03 ;
V_2 -> V_34 = V_34 ;
F_6 ( V_2 ) ;
V_49 = F_13
( & V_2 -> V_52 , V_53 ) ;
if ( V_49 == 0 ) {
F_14 ( & V_43 -> V_51 ) ;
return - V_54 ;
}
if ( V_49 < 0 ) {
F_14 ( & V_43 -> V_51 ) ;
return V_49 ;
}
* V_46 = V_2 -> V_55 ;
F_14 ( & V_43 -> V_51 ) ;
return V_56 ;
case V_57 :
V_2 -> V_58 = F_15 ( V_2 -> V_59 ) ;
* V_46 = V_2 -> V_58 / 1000 ;
* V_47 = 12 ;
return V_60 ;
case V_61 :
* V_46 = F_8 ( V_2 ) ;
return V_56 ;
default:
return - V_62 ;
}
}
static int F_16 ( struct V_1 * V_2 )
{
T_1 V_34 ;
T_1 V_55 ;
V_34 = V_2 -> V_34 & 0x03 ;
if ( V_34 < 2 )
V_55 = F_3 ( V_2 -> V_16 + V_63 ) ;
else
V_55 = F_3 ( V_2 -> V_16 + V_64 ) ;
if ( V_34 & 0x1 )
V_55 = ( V_55 >> 16 ) & 0xFFF ;
else
V_55 &= 0xFFF ;
return V_55 ;
}
static T_2 F_17 ( int V_65 , void * V_66 )
{
struct V_1 * V_2 = V_66 ;
int V_67 ;
V_67 = F_3 ( V_2 -> V_16 + V_68 ) ;
if ( V_67 & V_69 ) {
V_2 -> V_55 = F_16 ( V_2 ) ;
F_18 ( & V_2 -> V_52 ) ;
V_67 &= ~ V_69 ;
F_4 ( V_67 , V_2 -> V_16 + V_68 ) ;
}
if ( V_67 & V_70 ) {
F_19 ( L_1 ,
F_20 ( V_2 -> V_71 ) , V_67 ) ;
V_67 &= ~ V_70 ;
F_4 ( V_67 , V_2 -> V_16 + V_68 ) ;
}
return V_72 ;
}
static int F_21 ( struct V_42 * V_43 ,
unsigned V_73 , unsigned V_74 ,
unsigned * V_75 )
{
struct V_1 * V_2 = F_10 ( V_43 ) ;
if ( ! V_75 || V_73 % 4 || V_73 > V_25 )
return - V_62 ;
* V_75 = F_3 ( V_2 -> V_16 + V_73 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
T_1 V_76 ;
V_76 = F_3 ( V_2 -> V_16 + V_25 ) ;
V_76 |= V_26 |
V_27 ;
V_76 &= ~ V_28 ;
F_4 ( V_76 , V_2 -> V_16 + V_25 ) ;
}
static int F_23 ( struct V_77 * V_78 )
{
struct V_1 * V_2 ;
struct V_42 * V_43 ;
struct V_79 * V_80 ;
int V_65 ;
int V_49 ;
V_43 = F_24 ( & V_78 -> V_71 , sizeof( * V_2 ) ) ;
if ( ! V_43 ) {
F_25 ( & V_78 -> V_71 , L_2 ) ;
return - V_81 ;
}
V_2 = F_10 ( V_43 ) ;
V_2 -> V_71 = & V_78 -> V_71 ;
V_80 = F_26 ( V_78 , V_82 , 0 ) ;
V_2 -> V_16 = F_27 ( & V_78 -> V_71 , V_80 ) ;
if ( F_28 ( V_2 -> V_16 ) ) {
V_49 = F_29 ( V_2 -> V_16 ) ;
F_25 ( & V_78 -> V_71 ,
L_3 , V_49 ) ;
return V_49 ;
}
V_65 = F_30 ( V_78 , 0 ) ;
if ( V_65 < 0 ) {
F_25 ( & V_78 -> V_71 , L_4 ) ;
return V_65 ;
}
V_2 -> V_83 = F_31 ( & V_78 -> V_71 , L_5 ) ;
if ( F_28 ( V_2 -> V_83 ) ) {
V_49 = F_29 ( V_2 -> V_83 ) ;
F_25 ( & V_78 -> V_71 , L_6 , V_49 ) ;
return V_49 ;
}
V_2 -> V_59 = F_32 ( & V_78 -> V_71 , L_7 ) ;
if ( F_28 ( V_2 -> V_59 ) ) {
V_49 = F_29 ( V_2 -> V_59 ) ;
F_25 ( & V_78 -> V_71 ,
L_8 , V_49 ) ;
return V_49 ;
}
V_49 = F_33 ( V_2 -> V_59 ) ;
if ( V_49 ) {
F_25 ( & V_78 -> V_71 ,
L_9 ,
V_49 ) ;
return V_49 ;
}
F_34 ( V_78 , V_43 ) ;
F_35 ( & V_2 -> V_52 ) ;
V_43 -> V_84 = F_20 ( & V_78 -> V_71 ) ;
V_43 -> V_71 . V_85 = & V_78 -> V_71 ;
V_43 -> V_2 = & V_86 ;
V_43 -> V_87 = V_88 ;
V_43 -> V_89 = V_90 ;
V_43 -> V_91 = F_36 ( V_90 ) ;
V_49 = F_37 ( V_2 -> V_83 ) ;
if ( V_49 ) {
F_25 ( & V_78 -> V_71 ,
L_10 ) ;
goto V_92;
}
V_49 = F_38 ( V_2 -> V_71 , V_65 ,
F_17 , 0 ,
F_20 ( & V_78 -> V_71 ) , V_2 ) ;
if ( V_49 < 0 ) {
F_25 ( & V_78 -> V_71 , L_11 , V_65 ) ;
goto V_93;
}
F_1 ( V_2 ) ;
F_5 ( V_2 ) ;
V_49 = F_39 ( V_43 ) ;
if ( V_49 ) {
F_22 ( V_2 ) ;
F_25 ( & V_78 -> V_71 , L_12 ) ;
goto V_93;
}
return 0 ;
V_93:
F_40 ( V_2 -> V_83 ) ;
V_92:
F_41 ( V_2 -> V_59 ) ;
return V_49 ;
}
static int F_42 ( struct V_77 * V_78 )
{
struct V_42 * V_43 = F_43 ( V_78 ) ;
struct V_1 * V_2 = F_10 ( V_43 ) ;
F_44 ( V_43 ) ;
F_22 ( V_2 ) ;
F_40 ( V_2 -> V_83 ) ;
F_41 ( V_2 -> V_59 ) ;
return 0 ;
}
static int T_3 F_45 ( struct V_94 * V_71 )
{
struct V_42 * V_43 = F_46 ( V_71 ) ;
struct V_1 * V_2 = F_10 ( V_43 ) ;
F_22 ( V_2 ) ;
F_40 ( V_2 -> V_83 ) ;
F_41 ( V_2 -> V_59 ) ;
return 0 ;
}
static int T_3 F_47 ( struct V_94 * V_71 )
{
struct V_42 * V_43 = F_46 ( V_71 ) ;
struct V_1 * V_2 = F_10 ( V_43 ) ;
int V_49 ;
V_49 = F_33 ( V_2 -> V_59 ) ;
if ( V_49 ) {
F_25 ( V_2 -> V_71 ,
L_9 ,
V_49 ) ;
return V_49 ;
}
V_49 = F_37 ( V_2 -> V_83 ) ;
if ( V_49 ) {
F_25 ( V_2 -> V_71 ,
L_13 ) ;
F_41 ( V_2 -> V_59 ) ;
return V_49 ;
}
F_5 ( V_2 ) ;
return 0 ;
}
