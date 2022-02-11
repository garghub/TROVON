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
T_1 V_7 ;
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
T_1 V_7 ;
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
if ( ! V_23 -> V_70 -> V_71 ) {
F_17 ( V_23 -> V_72 ) ;
F_17 ( V_23 -> V_73 ) ;
F_17 ( V_23 -> V_74 ) ;
}
if ( V_23 -> V_75 ) {
V_50 = F_23 ( V_23 -> V_75 ) ;
if ( V_50 ) {
F_24 ( V_23 -> V_36 ,
L_3 ) ;
goto V_76;
}
}
if ( V_23 -> V_77 ) {
V_50 = F_23 ( V_23 -> V_77 ) ;
if ( V_50 ) {
F_24 ( V_23 -> V_36 , L_4 ) ;
goto V_78;
}
}
V_3 -> V_59 -> V_79 ( V_3 , 0 ) ;
return 0 ;
V_78:
if ( V_23 -> V_75 )
F_25 ( V_23 -> V_75 ) ;
V_76:
F_20 ( V_23 -> V_69 ) ;
if ( ! V_23 -> V_70 -> V_71 ) {
F_20 ( V_23 -> V_74 ) ;
F_20 ( V_23 -> V_73 ) ;
F_20 ( V_23 -> V_72 ) ;
}
return V_50 ;
}
static int F_26 ( struct V_49 * V_49 )
{
struct V_2 * V_3 = F_16 ( V_49 ) ;
struct V_1 * V_23 = F_1 ( V_3 ) ;
F_9 ( V_23 -> V_36 , L_5 ) ;
V_3 -> V_59 -> V_79 ( V_3 , 1 ) ;
if ( V_23 -> V_77 )
F_25 ( V_23 -> V_77 ) ;
if ( V_23 -> V_75 )
F_25 ( V_23 -> V_75 ) ;
F_20 ( V_23 -> V_69 ) ;
if ( ! V_23 -> V_70 -> V_71 ) {
F_20 ( V_23 -> V_74 ) ;
F_20 ( V_23 -> V_72 ) ;
F_20 ( V_23 -> V_73 ) ;
}
return 0 ;
}
static struct V_49 * F_27 ( struct V_80 * V_36 ,
struct V_81 * args )
{
struct V_1 * V_23 = F_28 ( V_36 ) ;
if ( F_29 ( args -> args [ 0 ] >= V_82 ) )
return F_30 ( - V_83 ) ;
return V_23 -> V_4 [ args -> args [ 0 ] ] . V_49 ;
}
static int F_31 ( struct V_1 * V_23 )
{
unsigned long V_84 ;
int V_50 ;
V_23 -> V_51 = F_32 ( V_23 -> V_36 , L_6 ) ;
if ( F_33 ( V_23 -> V_51 ) ) {
F_24 ( V_23 -> V_36 , L_7 ) ;
return F_34 ( V_23 -> V_51 ) ;
}
V_23 -> V_69 = F_32 ( V_23 -> V_36 , L_8 ) ;
if ( F_33 ( V_23 -> V_69 ) ) {
F_24 ( V_23 -> V_36 , L_9 ) ;
return F_34 ( V_23 -> V_69 ) ;
}
V_84 = F_35 ( V_23 -> V_69 ) ;
V_50 = F_3 ( V_84 , & V_23 -> V_31 ) ;
if ( V_50 ) {
F_24 ( V_23 -> V_36 , L_10 ,
V_84 ) ;
return V_50 ;
}
if ( ! V_23 -> V_70 -> V_71 ) {
V_23 -> V_72 = F_32 ( V_23 -> V_36 , L_11 ) ;
if ( F_33 ( V_23 -> V_72 ) ) {
F_36 ( V_23 -> V_36 ,
L_12 ) ;
V_23 -> V_72 = NULL ;
}
V_23 -> V_73 = F_32 ( V_23 -> V_36 , L_13 ) ;
if ( F_33 ( V_23 -> V_73 ) ) {
F_36 ( V_23 -> V_36 ,
L_14 ) ;
V_23 -> V_73 = NULL ;
}
V_23 -> V_74 = F_32 ( V_23 -> V_36 , L_15 ) ;
if ( F_33 ( V_23 -> V_74 ) ) {
F_36 ( V_23 -> V_36 ,
L_16 ) ;
V_23 -> V_74 = NULL ;
}
}
return 0 ;
}
static int F_37 ( struct V_85 * V_86 )
{
struct V_80 * V_36 = & V_86 -> V_36 ;
struct V_87 * V_88 = V_36 -> V_89 ;
struct V_1 * V_23 ;
struct V_90 * V_90 ;
struct V_91 * V_92 ;
const struct V_93 * V_70 ;
struct V_94 * V_20 ;
T_1 V_22 ;
int V_95 , V_50 ;
int V_96 ;
V_23 = F_38 ( V_36 , sizeof( * V_23 ) , V_97 ) ;
if ( ! V_23 )
return - V_98 ;
F_39 ( V_36 , V_23 ) ;
V_23 -> V_36 = V_36 ;
V_92 = F_40 ( V_86 , V_99 , 0 ) ;
V_23 -> V_24 = F_41 ( V_36 , V_92 ) ;
if ( F_33 ( V_23 -> V_24 ) )
return F_34 ( V_23 -> V_24 ) ;
V_70 = F_42 ( V_36 ) ;
if ( ! V_70 )
return - V_17 ;
V_23 -> V_70 = V_70 ;
V_50 = F_31 ( V_23 ) ;
if ( V_50 ) {
F_24 ( V_36 , L_17 ) ;
return V_50 ;
}
V_20 = F_43 ( V_36 -> V_89 ,
L_18 ) ;
if ( F_33 ( V_20 ) ) {
F_24 ( V_36 , L_19 ) ;
return F_34 ( V_20 ) ;
}
V_96 = F_44 ( V_88 , L_20 ) ;
if ( V_96 < 0 )
F_9 ( V_36 , L_21 ) ;
switch ( V_96 ) {
case 1 :
V_22 = V_23 -> V_70 -> V_100 ;
break;
case 0 :
default:
V_22 = V_23 -> V_70 -> V_101 ;
break;
}
V_23 -> V_77 = F_45 ( V_36 , L_22 ) ;
if ( F_33 ( V_23 -> V_77 ) ) {
V_50 = F_34 ( V_23 -> V_77 ) ;
if ( V_50 == - V_102 )
return V_50 ;
F_46 ( V_36 , L_23 ) ;
V_23 -> V_77 = NULL ;
}
V_23 -> V_75 = F_45 ( V_36 , L_24 ) ;
if ( F_33 ( V_23 -> V_75 ) ) {
V_50 = F_34 ( V_23 -> V_75 ) ;
if ( V_50 == - V_102 )
return V_50 ;
F_46 ( V_36 , L_25 ) ;
V_23 -> V_75 = NULL ;
}
F_47 ( V_36 , L_26 ) ;
for ( V_95 = 0 ; V_95 < V_82 ; V_95 ++ ) {
struct V_49 * V_49 = F_48 ( V_36 , NULL ,
& V_103 ) ;
if ( F_33 ( V_49 ) ) {
F_24 ( V_36 , L_27 ) ;
return F_34 ( V_49 ) ;
}
V_23 -> V_4 [ V_95 ] . V_49 = V_49 ;
V_23 -> V_4 [ V_95 ] . V_5 = V_95 ;
V_23 -> V_4 [ V_95 ] . V_20 = V_20 ;
V_23 -> V_4 [ V_95 ] . V_22 = V_22 ;
V_23 -> V_4 [ V_95 ] . V_59 = & V_70 -> V_59 [ V_95 ] ;
F_49 ( V_49 , & V_23 -> V_4 [ V_95 ] ) ;
}
V_90 = F_50 ( V_36 ,
F_27 ) ;
if ( F_33 ( V_90 ) ) {
F_24 ( V_23 -> V_36 , L_28 ) ;
return F_34 ( V_90 ) ;
}
return 0 ;
}
