static inline
struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( ( V_3 ) , struct V_1 ,
V_4 [ ( V_3 ) -> V_5 ] ) ;
}
static unsigned int F_3 ( unsigned long V_6 , T_1 * V_7 )
{
switch ( V_6 ) {
case 9600 * V_8 :
* V_7 = V_9 ;
break;
case 10 * V_10 :
* V_7 = V_11 ;
break;
case 12 * V_10 :
* V_7 = V_12 ;
break;
case 19200 * V_8 :
* V_7 = V_13 ;
break;
case 20 * V_10 :
* V_7 = V_14 ;
break;
case 24 * V_10 :
* V_7 = V_15 ;
break;
case 50 * V_10 :
* V_7 = V_16 ;
break;
default:
return - V_17 ;
}
return 0 ;
}
static void F_4 ( struct V_2 * V_3 ,
unsigned int V_18 )
{
unsigned int V_19 ;
if ( ! V_3 -> V_20 )
return;
V_19 = V_18 ? 0 : V_21 ;
F_5 ( V_3 -> V_20 , V_3 -> V_22 ,
V_21 , V_19 ) ;
}
static unsigned int
F_6 ( struct V_2 * V_3 )
{
static T_1 V_7 ;
struct V_1 * V_23 = F_1 ( V_3 ) ;
V_7 = F_7 ( V_23 -> V_24 + V_25 ) ;
V_7 &= ~ V_26 ;
V_7 |= V_27 ;
V_7 &= ~ V_28 |
V_29 |
V_30 ;
switch ( V_23 -> V_31 ) {
case V_16 :
V_7 |= ( V_32 |
F_8 ( 0x00 ) ) ;
break;
case V_15 :
V_7 |= ( V_33 |
F_8 ( 0x88 ) ) ;
break;
case V_14 :
V_7 |= ( V_34 |
F_8 ( 0x00 ) ) ;
break;
case V_13 :
V_7 |= ( V_35 |
F_8 ( 0x88 ) ) ;
break;
default:
F_9 ( V_23 -> V_36 , L_1 ) ;
break;
}
return V_7 ;
}
static unsigned int
F_10 ( struct V_2 * V_3 )
{
static T_1 V_7 ;
struct V_1 * V_23 = F_1 ( V_3 ) ;
V_7 = F_7 ( V_23 -> V_24 + V_25 ) ;
V_7 &= ~ V_26 ;
V_7 |= V_27 ;
V_7 &= ~ V_37 |
V_29 |
V_30 ;
V_7 |= F_11 ( V_23 -> V_31 ) ;
return V_7 ;
}
static void F_12 ( struct V_1 * V_23 )
{
T_1 V_7 ;
V_7 = F_7 ( V_23 -> V_24 + V_38 ) ;
V_7 &= ~ V_39 ;
V_7 |= V_40 ;
F_13 ( V_7 , V_23 -> V_24 + V_38 ) ;
V_7 = F_7 ( V_23 -> V_24 + V_41 ) ;
V_7 &= ~ V_42 ;
F_13 ( V_7 , V_23 -> V_24 + V_41 ) ;
}
static void F_14 ( struct V_1 * V_23 )
{
T_1 V_7 ;
V_7 = F_7 ( V_23 -> V_24 + V_43 ) ;
V_7 &= ~ V_44 ;
V_7 |= V_45 ;
F_13 ( V_7 , V_23 -> V_24 + V_43 ) ;
V_7 = F_7 ( V_23 -> V_24 + V_38 ) ;
V_7 &= ~ V_39 ;
V_7 |= V_40 ;
F_13 ( V_7 , V_23 -> V_24 + V_38 ) ;
F_13 ( V_46 , V_23 -> V_24 + V_47 ) ;
V_7 = F_7 ( V_23 -> V_24 + V_41 ) ;
V_7 &= ~ V_48 ;
F_13 ( V_7 , V_23 -> V_24 + V_41 ) ;
}
static int F_15 ( struct V_49 * V_49 )
{
int V_50 ;
T_1 V_7 ;
struct V_2 * V_3 = F_16 ( V_49 ) ;
struct V_1 * V_23 = F_1 ( V_3 ) ;
V_50 = F_17 ( V_23 -> V_51 ) ;
if ( V_50 )
return V_50 ;
F_13 ( 0x0 , V_23 -> V_24 + V_52 ) ;
F_13 ( 0x0 , V_23 -> V_24 + V_53 ) ;
V_7 = V_54 |
F_18 ( 0x20 ) ;
F_13 ( V_7 , V_23 -> V_24 + V_55 ) ;
V_7 = F_7 ( V_23 -> V_24 + V_43 ) ;
V_7 &= ~ V_56 ;
F_13 ( V_7 , V_23 -> V_24 + V_43 ) ;
V_7 = F_7 ( V_23 -> V_24 + V_57 ) ;
V_7 |= V_58 ;
F_13 ( V_7 , V_23 -> V_24 + V_57 ) ;
V_3 -> V_59 -> V_60 ( V_23 ) ;
V_7 = V_3 -> V_59 -> V_61 ( V_3 ) ;
V_7 |= V_62 |
V_63 |
V_64 |
V_65 |
V_66 ;
F_13 ( V_7 , V_23 -> V_24 + V_25 ) ;
F_19 ( 10 ) ;
V_7 &= ~ V_66 ;
F_13 ( V_7 , V_23 -> V_24 + V_25 ) ;
F_20 ( V_23 -> V_51 ) ;
return 0 ;
}
static int F_21 ( struct V_49 * V_49 )
{
int V_50 ;
T_1 V_7 ;
struct V_2 * V_3 = F_16 ( V_49 ) ;
struct V_1 * V_23 = F_1 ( V_3 ) ;
V_50 = F_17 ( V_23 -> V_51 ) ;
if ( V_50 )
return V_50 ;
V_7 = V_46 |
V_67 |
V_68 ;
F_13 ( V_7 , V_23 -> V_24 + V_47 ) ;
V_7 = F_7 ( V_23 -> V_24 + V_25 ) ;
V_7 &= ~ ( V_63 |
V_64 |
V_65 ) ;
F_13 ( V_7 , V_23 -> V_24 + V_25 ) ;
V_7 = F_7 ( V_23 -> V_24 + V_41 ) ;
V_7 |= V_42 |
V_48 ;
F_13 ( V_7 , V_23 -> V_24 + V_41 ) ;
F_20 ( V_23 -> V_51 ) ;
return 0 ;
}
static int F_22 ( struct V_49 * V_49 )
{
int V_50 ;
struct V_2 * V_3 = F_16 ( V_49 ) ;
struct V_1 * V_23 = F_1 ( V_3 ) ;
F_9 ( V_23 -> V_36 , L_2 ) ;
F_17 ( V_23 -> V_69 ) ;
if ( V_23 -> V_70 ) {
V_50 = F_23 ( V_23 -> V_70 ) ;
if ( V_50 ) {
F_24 ( V_23 -> V_36 , L_3 ) ;
goto V_71;
}
}
V_3 -> V_59 -> V_72 ( V_3 , 0 ) ;
return 0 ;
V_71:
F_20 ( V_23 -> V_69 ) ;
return V_50 ;
}
static int F_25 ( struct V_49 * V_49 )
{
struct V_2 * V_3 = F_16 ( V_49 ) ;
struct V_1 * V_23 = F_1 ( V_3 ) ;
F_9 ( V_23 -> V_36 , L_4 ) ;
V_3 -> V_59 -> V_72 ( V_3 , 1 ) ;
if ( V_23 -> V_70 )
F_26 ( V_23 -> V_70 ) ;
F_20 ( V_23 -> V_69 ) ;
return 0 ;
}
static struct V_49 * F_27 ( struct V_73 * V_36 ,
struct V_74 * args )
{
struct V_1 * V_23 = F_28 ( V_36 ) ;
if ( F_29 ( args -> args [ 0 ] > V_75 ) )
return F_30 ( - V_76 ) ;
return V_23 -> V_4 [ args -> args [ 0 ] ] . V_49 ;
}
static int F_31 ( struct V_77 * V_78 )
{
struct V_73 * V_36 = & V_78 -> V_36 ;
struct V_79 * V_80 = V_36 -> V_81 ;
struct V_1 * V_23 ;
struct V_82 * V_82 ;
struct V_83 * V_84 ;
const struct V_85 * V_86 ;
const struct V_87 * V_88 ;
struct V_89 * V_20 ;
T_1 V_22 ;
unsigned long V_90 ;
int V_91 , V_50 ;
int V_92 ;
V_23 = F_32 ( V_36 , sizeof( * V_23 ) , V_93 ) ;
if ( ! V_23 )
return - V_94 ;
F_33 ( V_36 , V_23 ) ;
V_23 -> V_36 = V_36 ;
V_84 = F_34 ( V_78 , V_95 , 0 ) ;
V_23 -> V_24 = F_35 ( V_36 , V_84 ) ;
if ( F_36 ( V_23 -> V_24 ) )
return F_37 ( V_23 -> V_24 ) ;
V_86 = F_38 ( V_96 , V_78 -> V_36 . V_81 ) ;
V_88 = V_86 -> V_97 ;
V_23 -> V_88 = V_88 ;
V_23 -> V_51 = F_39 ( V_36 , L_5 ) ;
if ( F_36 ( V_23 -> V_51 ) ) {
F_24 ( V_36 , L_6 ) ;
return F_37 ( V_23 -> V_51 ) ;
}
V_23 -> V_69 = F_39 ( V_36 , L_7 ) ;
if ( F_36 ( V_23 -> V_69 ) ) {
F_24 ( V_36 , L_8 ) ;
return F_37 ( V_23 -> V_69 ) ;
}
V_90 = F_40 ( V_23 -> V_69 ) ;
V_50 = F_3 ( V_90 , & V_23 -> V_31 ) ;
if ( V_50 ) {
F_24 ( V_23 -> V_36 , L_9 ,
V_90 ) ;
return V_50 ;
}
V_20 = F_41 ( V_36 -> V_81 ,
L_10 ) ;
if ( F_36 ( V_20 ) ) {
F_24 ( V_36 , L_11 ) ;
return F_37 ( V_20 ) ;
}
V_92 = F_42 ( V_80 , L_12 ) ;
if ( V_92 < 0 )
F_9 ( V_36 , L_13 ) ;
switch ( V_92 ) {
case 1 :
V_22 = V_23 -> V_88 -> V_98 ;
break;
case 0 :
default:
V_22 = V_23 -> V_88 -> V_99 ;
break;
}
V_23 -> V_70 = F_43 ( V_36 , L_14 ) ;
if ( F_36 ( V_23 -> V_70 ) ) {
V_50 = F_37 ( V_23 -> V_70 ) ;
if ( V_50 == - V_100 )
return V_50 ;
F_44 ( V_36 , L_15 ) ;
V_23 -> V_70 = NULL ;
}
F_45 ( V_36 , L_16 ) ;
for ( V_91 = 0 ; V_91 < V_75 ; V_91 ++ ) {
struct V_49 * V_49 = F_46 ( V_36 , NULL ,
& V_101 ,
NULL ) ;
if ( F_36 ( V_49 ) ) {
F_24 ( V_36 , L_17 ) ;
return F_37 ( V_49 ) ;
}
V_23 -> V_4 [ V_91 ] . V_49 = V_49 ;
V_23 -> V_4 [ V_91 ] . V_5 = V_91 ;
V_23 -> V_4 [ V_91 ] . V_20 = V_20 ;
V_23 -> V_4 [ V_91 ] . V_22 = V_22 ;
V_23 -> V_4 [ V_91 ] . V_59 = & V_88 -> V_59 [ V_91 ] ;
F_47 ( V_49 , & V_23 -> V_4 [ V_91 ] ) ;
}
V_82 = F_48 ( V_36 ,
F_27 ) ;
if ( F_36 ( V_82 ) ) {
F_24 ( V_23 -> V_36 , L_18 ) ;
return F_37 ( V_82 ) ;
}
return 0 ;
}
