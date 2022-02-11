static int F_1 ( void T_1 * V_1 , T_2 V_2 , bool assert )
{
int V_3 = 10 ;
T_2 V_4 ;
T_2 V_5 ;
V_4 = F_2 ( V_1 + V_6 ) ;
if ( assert )
V_4 |= V_2 ;
else
V_4 &= ~ V_2 ;
F_3 ( V_4 , V_1 + V_6 ) ;
do {
V_5 = F_2 ( V_1 + V_7 ) ;
if ( ( assert ? V_5 : ~ V_5 ) & V_8 )
break;
F_4 ( 100 , 200 ) ;
} while ( -- V_3 );
return V_3 ? 0 : - V_9 ;
}
static int F_5 ( T_3 V_10 , void T_1 * V_1 )
{
T_2 V_4 = V_10 ;
int V_11 ;
F_3 ( V_4 , V_1 + V_6 ) ;
V_11 = F_1 ( V_1 , V_12 , true ) ;
if ( V_11 )
return V_11 ;
V_11 = F_1 ( V_1 , V_12 , false ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int F_6 ( T_3 V_13 , void T_1 * V_1 )
{
T_2 V_4 = V_13 ;
int V_11 ;
F_3 ( V_4 , V_1 + V_6 ) ;
V_11 = F_1 ( V_1 , V_14 , true ) ;
if ( V_11 )
return V_11 ;
V_11 = F_1 ( V_1 , V_14 , false ) ;
if ( V_11 )
return V_11 ;
if ( V_13 & V_15 ) {
V_4 |= V_16 ;
F_3 ( V_4 , V_1 + V_6 ) ;
goto V_17;
}
V_11 = F_1 ( V_1 , V_16 , true ) ;
if ( V_11 )
return V_11 ;
V_11 = F_1 ( V_1 , V_16 , false ) ;
if ( V_11 )
return V_11 ;
V_17:
return 0 ;
}
static int F_7 ( T_3 * V_13 , void T_1 * V_1 )
{
int V_11 ;
V_11 = F_1 ( V_1 , V_18 , true ) ;
if ( V_11 )
return V_11 ;
* V_13 = F_2 ( V_1 + V_7 ) & V_19 ;
V_11 = F_1 ( V_1 , V_18 , false ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int F_8 ( struct V_20 * V_21 )
{
void T_1 * V_1 = V_21 -> V_1 ;
int V_3 = 10 ;
T_3 V_13 ;
int V_11 ;
V_11 = F_5 ( V_22 , V_1 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_6 ( V_15 , V_1 ) ;
if ( V_11 )
return V_11 ;
do {
F_4 ( 100 , 200 ) ;
V_11 = F_5 ( V_23 , V_1 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_7 ( & V_13 , V_1 ) ;
if ( V_11 )
return V_11 ;
if ( V_13 & V_24 )
break;
} while ( -- V_3 );
return V_3 ? 0 : - V_9 ;
}
static int F_9 ( struct V_20 * V_21 )
{
struct V_25 * V_26 = V_21 -> V_27 ;
struct V_28 * V_29 = & V_26 -> V_30 -> V_29 ;
int V_11 ;
if ( V_26 -> V_31 )
return 0 ;
V_11 = F_10 ( V_21 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_11 ( V_26 -> V_32 ) ;
if ( V_11 < 0 )
goto V_33;
if ( V_26 -> type == V_34 ) {
F_12 ( V_26 -> V_35 , V_36 ,
V_37 |
V_38 |
V_39 |
V_40 |
V_41 |
V_42 |
V_43 |
V_44 |
V_45 |
V_46 ,
V_26 -> V_47 ) ;
F_12 ( V_26 -> V_35 , V_36 ,
V_45 ,
V_45 ) ;
F_4 ( 100 , 200 ) ;
V_11 = F_8 ( V_21 ) ;
if ( V_11 ) {
F_13 ( V_29 , L_1 , V_11 ) ;
goto V_48;
}
}
F_4 ( 1000 , 2000 ) ;
return 0 ;
V_48:
F_14 ( V_26 -> V_32 ) ;
V_33:
F_15 ( V_21 ) ;
return V_11 ;
}
static void F_16 ( struct V_20 * V_21 )
{
struct V_25 * V_26 = V_21 -> V_27 ;
if ( V_26 -> V_31 )
return;
if ( V_26 -> type == V_34 ) {
F_12 ( V_26 -> V_35 , V_36 ,
V_45 ,
! V_45 ) ;
}
F_14 ( V_26 -> V_32 ) ;
F_15 ( V_21 ) ;
}
static void F_17 ( struct V_49 * V_50 )
{
T_2 V_51 ;
struct V_52 * V_29 ;
struct V_53 * V_54 = F_18 ( V_50 -> V_29 ) ;
struct V_20 * V_21 = V_54 -> V_55 ;
void T_1 * V_1 = V_21 -> V_1 ;
struct V_25 * V_26 = V_21 -> V_27 ;
F_19 ( V_50 ) ;
if ( ! ( V_26 -> V_56 ) || V_57 )
return;
V_26 -> V_56 = false ;
F_20 (dev, &ap->link, ENABLED)
return;
V_51 = F_2 ( V_1 + V_6 ) ;
F_3 ( V_51 | V_58 , V_1 + V_6 ) ;
F_16 ( V_21 ) ;
V_26 -> V_31 = true ;
F_21 ( V_50 -> V_29 , L_2 ) ;
F_21 ( V_50 -> V_29 , L_3 V_59 L_4 ) ;
}
static int F_22 ( struct V_60 * V_61 , unsigned int * V_62 ,
unsigned long V_63 )
{
struct V_49 * V_50 = V_61 -> V_50 ;
struct V_53 * V_54 = F_18 ( V_50 -> V_29 ) ;
struct V_20 * V_21 = V_54 -> V_55 ;
struct V_25 * V_26 = V_21 -> V_27 ;
int V_11 = - V_64 ;
if ( V_26 -> type == V_65 )
V_11 = V_66 . V_67 ( V_61 , V_62 , V_63 ) ;
else if ( V_26 -> type == V_34 )
V_11 = V_68 . V_67 ( V_61 , V_62 , V_63 ) ;
return V_11 ;
}
static T_2 F_23 ( struct V_28 * V_29 ,
const struct V_69 * V_70 , T_4 V_71 )
{
struct V_72 * V_73 = V_29 -> V_74 ;
T_2 V_75 = 0 ;
int V_76 , V_77 ;
for ( V_76 = 0 ; V_76 < V_71 ; V_76 ++ , V_70 ++ ) {
T_2 V_78 ;
if ( V_70 -> V_79 == 0 ) {
if ( F_24 ( V_73 , V_70 -> V_80 ) )
V_75 |= V_70 -> V_81 ;
else
V_75 |= V_70 -> V_82 ;
continue;
}
if ( F_25 ( V_73 , V_70 -> V_80 , & V_78 ) ) {
F_21 ( V_29 , L_5 ,
V_70 -> V_80 , V_70 -> V_82 ) ;
V_75 |= V_70 -> V_82 ;
continue;
}
for ( V_77 = 0 ; V_77 < V_70 -> V_79 ; V_77 ++ ) {
if ( V_70 -> V_83 [ V_77 ] . V_84 == V_78 ) {
F_21 ( V_29 , L_6 ,
V_70 -> V_80 , V_78 , V_70 -> V_83 [ V_77 ] . V_75 ) ;
V_75 |= V_70 -> V_83 [ V_77 ] . V_75 ;
break;
}
}
if ( V_77 == V_70 -> V_79 ) {
F_13 ( V_29 , L_7 ,
V_70 -> V_80 ) ;
V_75 |= V_70 -> V_82 ;
}
}
return V_75 ;
}
static int F_26 ( struct V_85 * V_86 )
{
struct V_28 * V_29 = & V_86 -> V_29 ;
const struct V_87 * V_88 ;
struct V_20 * V_21 ;
struct V_25 * V_26 ;
unsigned int V_51 ;
int V_11 ;
V_88 = F_27 ( V_89 , V_29 ) ;
if ( ! V_88 )
return - V_90 ;
V_26 = F_28 ( V_29 , sizeof( * V_26 ) , V_91 ) ;
if ( ! V_26 )
return - V_92 ;
V_26 -> V_30 = V_86 ;
V_26 -> V_31 = false ;
V_26 -> V_56 = true ;
V_26 -> type = (enum V_93 ) V_88 -> V_94 ;
V_26 -> V_95 = F_29 ( V_29 , L_8 ) ;
if ( F_30 ( V_26 -> V_95 ) ) {
F_13 ( V_29 , L_9 ) ;
return F_31 ( V_26 -> V_95 ) ;
}
V_26 -> V_32 = F_29 ( V_29 , L_10 ) ;
if ( F_30 ( V_26 -> V_32 ) ) {
F_13 ( V_29 , L_11 ) ;
return F_31 ( V_26 -> V_32 ) ;
}
V_26 -> V_96 = F_29 ( V_29 , L_12 ) ;
if ( F_30 ( V_26 -> V_96 ) ) {
F_13 ( V_29 , L_13 ) ;
return F_31 ( V_26 -> V_96 ) ;
}
if ( V_26 -> type == V_34 ) {
T_2 V_75 ;
V_26 -> V_35 = F_32 (
L_14 ) ;
if ( F_30 ( V_26 -> V_35 ) ) {
F_13 ( V_29 ,
L_15 ) ;
return F_31 ( V_26 -> V_35 ) ;
}
V_75 = F_23 ( V_29 , V_97 ,
F_33 ( V_97 ) ) ;
V_26 -> V_47 =
V_98 |
V_99 |
V_100 |
V_75 ;
}
V_21 = F_34 ( V_86 ) ;
if ( F_30 ( V_21 ) )
return F_31 ( V_21 ) ;
V_21 -> V_27 = V_26 ;
V_11 = F_11 ( V_26 -> V_95 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_9 ( V_21 ) ;
if ( V_11 )
goto V_48;
V_51 = F_2 ( V_21 -> V_1 + V_101 ) ;
if ( ! ( V_51 & V_102 ) ) {
V_51 |= V_102 ;
F_3 ( V_51 , V_21 -> V_1 + V_101 ) ;
}
V_51 = F_2 ( V_21 -> V_1 + V_103 ) ;
if ( ! ( V_51 & 0x1 ) ) {
V_51 |= 0x1 ;
F_3 ( V_51 , V_21 -> V_1 + V_103 ) ;
}
V_51 = F_35 ( V_26 -> V_96 ) / 1000 ;
F_3 ( V_51 , V_21 -> V_1 + V_104 ) ;
V_11 = F_36 ( V_86 , V_21 , & V_105 ,
& V_106 ) ;
if ( V_11 )
goto V_107;
return 0 ;
V_107:
F_16 ( V_21 ) ;
V_48:
F_14 ( V_26 -> V_95 ) ;
return V_11 ;
}
static void F_37 ( struct V_53 * V_54 )
{
struct V_20 * V_21 = V_54 -> V_55 ;
struct V_25 * V_26 = V_21 -> V_27 ;
F_16 ( V_21 ) ;
F_14 ( V_26 -> V_95 ) ;
}
static int F_38 ( struct V_28 * V_29 )
{
struct V_53 * V_54 = F_18 ( V_29 ) ;
struct V_20 * V_21 = V_54 -> V_55 ;
int V_11 ;
V_11 = F_39 ( V_29 ) ;
if ( V_11 )
return V_11 ;
F_16 ( V_21 ) ;
return 0 ;
}
static int F_40 ( struct V_28 * V_29 )
{
struct V_53 * V_54 = F_18 ( V_29 ) ;
struct V_20 * V_21 = V_54 -> V_55 ;
int V_11 ;
V_11 = F_9 ( V_21 ) ;
if ( V_11 )
return V_11 ;
return F_41 ( V_29 ) ;
}
