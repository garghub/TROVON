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
if ( V_21 -> V_32 ) {
V_11 = F_10 ( V_21 -> V_32 ) ;
if ( V_11 )
return V_11 ;
}
V_11 = F_11 ( V_26 -> V_33 ) ;
if ( V_11 < 0 )
goto V_34;
if ( V_26 -> type == V_35 ) {
F_12 ( V_26 -> V_36 , V_37 ,
V_38 |
V_39 |
V_40 |
V_41 |
V_42 |
V_43 |
V_44 |
V_45 |
V_46 |
V_47 ,
V_26 -> V_48 ) ;
F_12 ( V_26 -> V_36 , V_37 ,
V_46 ,
V_46 ) ;
F_4 ( 100 , 200 ) ;
V_11 = F_8 ( V_21 ) ;
if ( V_11 ) {
F_13 ( V_29 , L_1 , V_11 ) ;
goto V_49;
}
}
F_4 ( 1000 , 2000 ) ;
return 0 ;
V_49:
F_14 ( V_26 -> V_33 ) ;
V_34:
if ( V_21 -> V_32 )
F_15 ( V_21 -> V_32 ) ;
return V_11 ;
}
static void F_16 ( struct V_20 * V_21 )
{
struct V_25 * V_26 = V_21 -> V_27 ;
if ( V_26 -> V_31 )
return;
if ( V_26 -> type == V_35 ) {
F_12 ( V_26 -> V_36 , V_37 ,
V_46 ,
! V_46 ) ;
}
F_14 ( V_26 -> V_33 ) ;
if ( V_21 -> V_32 )
F_15 ( V_21 -> V_32 ) ;
}
static void F_17 ( struct V_50 * V_51 )
{
T_2 V_52 ;
struct V_53 * V_29 ;
struct V_54 * V_55 = F_18 ( V_51 -> V_29 ) ;
struct V_20 * V_21 = V_55 -> V_56 ;
void T_1 * V_1 = V_21 -> V_1 ;
struct V_25 * V_26 = V_21 -> V_27 ;
F_19 ( V_51 ) ;
if ( ! ( V_26 -> V_57 ) || V_58 )
return;
V_26 -> V_57 = false ;
F_20 (dev, &ap->link, ENABLED)
return;
V_52 = F_2 ( V_1 + V_6 ) ;
F_3 ( V_52 | V_59 , V_1 + V_6 ) ;
F_16 ( V_21 ) ;
V_26 -> V_31 = true ;
F_21 ( V_51 -> V_29 , L_2 ) ;
F_21 ( V_51 -> V_29 , L_3 V_60 L_4 ) ;
}
static int F_22 ( struct V_61 * V_62 , unsigned int * V_63 ,
unsigned long V_64 )
{
struct V_50 * V_51 = V_62 -> V_51 ;
struct V_54 * V_55 = F_18 ( V_51 -> V_29 ) ;
struct V_20 * V_21 = V_55 -> V_56 ;
struct V_25 * V_26 = V_21 -> V_27 ;
int V_11 = - V_65 ;
if ( V_26 -> type == V_66 )
V_11 = V_67 . V_68 ( V_62 , V_63 , V_64 ) ;
else if ( V_26 -> type == V_35 )
V_11 = V_69 . V_68 ( V_62 , V_63 , V_64 ) ;
return V_11 ;
}
static T_2 F_23 ( struct V_28 * V_29 ,
const struct V_70 * V_71 , T_4 V_72 )
{
struct V_73 * V_74 = V_29 -> V_75 ;
T_2 V_76 = 0 ;
int V_77 , V_78 ;
for ( V_77 = 0 ; V_77 < V_72 ; V_77 ++ , V_71 ++ ) {
T_2 V_79 ;
if ( V_71 -> V_80 == 0 ) {
if ( F_24 ( V_74 , V_71 -> V_81 ) )
V_76 |= V_71 -> V_82 ;
else
V_76 |= V_71 -> V_83 ;
continue;
}
if ( F_25 ( V_74 , V_71 -> V_81 , & V_79 ) ) {
F_21 ( V_29 , L_5 ,
V_71 -> V_81 , V_71 -> V_83 ) ;
V_76 |= V_71 -> V_83 ;
continue;
}
for ( V_78 = 0 ; V_78 < V_71 -> V_80 ; V_78 ++ ) {
if ( V_71 -> V_84 [ V_78 ] . V_85 == V_79 ) {
F_21 ( V_29 , L_6 ,
V_71 -> V_81 , V_79 , V_71 -> V_84 [ V_78 ] . V_76 ) ;
V_76 |= V_71 -> V_84 [ V_78 ] . V_76 ;
break;
}
}
if ( V_78 == V_71 -> V_80 ) {
F_13 ( V_29 , L_7 ,
V_71 -> V_81 ) ;
V_76 |= V_71 -> V_83 ;
}
}
return V_76 ;
}
static int F_26 ( struct V_86 * V_87 )
{
struct V_28 * V_29 = & V_87 -> V_29 ;
const struct V_88 * V_89 ;
struct V_20 * V_21 ;
struct V_25 * V_26 ;
unsigned int V_52 ;
int V_11 ;
V_89 = F_27 ( V_90 , V_29 ) ;
if ( ! V_89 )
return - V_91 ;
V_26 = F_28 ( V_29 , sizeof( * V_26 ) , V_92 ) ;
if ( ! V_26 )
return - V_93 ;
V_26 -> V_30 = V_87 ;
V_26 -> V_31 = false ;
V_26 -> V_57 = true ;
V_26 -> type = (enum V_94 ) V_89 -> V_95 ;
V_26 -> V_96 = F_29 ( V_29 , L_8 ) ;
if ( F_30 ( V_26 -> V_96 ) ) {
F_13 ( V_29 , L_9 ) ;
return F_31 ( V_26 -> V_96 ) ;
}
V_26 -> V_33 = F_29 ( V_29 , L_10 ) ;
if ( F_30 ( V_26 -> V_33 ) ) {
F_13 ( V_29 , L_11 ) ;
return F_31 ( V_26 -> V_33 ) ;
}
V_26 -> V_97 = F_29 ( V_29 , L_12 ) ;
if ( F_30 ( V_26 -> V_97 ) ) {
F_13 ( V_29 , L_13 ) ;
return F_31 ( V_26 -> V_97 ) ;
}
if ( V_26 -> type == V_35 ) {
T_2 V_76 ;
V_26 -> V_36 = F_32 (
L_14 ) ;
if ( F_30 ( V_26 -> V_36 ) ) {
F_13 ( V_29 ,
L_15 ) ;
return F_31 ( V_26 -> V_36 ) ;
}
V_76 = F_23 ( V_29 , V_98 ,
F_33 ( V_98 ) ) ;
V_26 -> V_48 =
V_99 |
V_100 |
V_101 |
V_76 ;
}
V_21 = F_34 ( V_87 ) ;
if ( F_30 ( V_21 ) )
return F_31 ( V_21 ) ;
V_21 -> V_27 = V_26 ;
V_11 = F_11 ( V_26 -> V_96 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_9 ( V_21 ) ;
if ( V_11 )
goto V_49;
V_52 = F_2 ( V_21 -> V_1 + V_102 ) ;
if ( ! ( V_52 & V_103 ) ) {
V_52 |= V_103 ;
F_3 ( V_52 , V_21 -> V_1 + V_102 ) ;
}
V_52 = F_2 ( V_21 -> V_1 + V_104 ) ;
if ( ! ( V_52 & 0x1 ) ) {
V_52 |= 0x1 ;
F_3 ( V_52 , V_21 -> V_1 + V_104 ) ;
}
V_52 = F_35 ( V_26 -> V_97 ) / 1000 ;
F_3 ( V_52 , V_21 -> V_1 + V_105 ) ;
V_11 = F_36 ( V_87 , V_21 , & V_106 ) ;
if ( V_11 )
goto V_107;
return 0 ;
V_107:
F_16 ( V_21 ) ;
V_49:
F_14 ( V_26 -> V_96 ) ;
return V_11 ;
}
static void F_37 ( struct V_54 * V_55 )
{
struct V_20 * V_21 = V_55 -> V_56 ;
struct V_25 * V_26 = V_21 -> V_27 ;
F_16 ( V_21 ) ;
F_14 ( V_26 -> V_96 ) ;
}
static int F_38 ( struct V_28 * V_29 )
{
struct V_54 * V_55 = F_18 ( V_29 ) ;
struct V_20 * V_21 = V_55 -> V_56 ;
int V_11 ;
V_11 = F_39 ( V_29 ) ;
if ( V_11 )
return V_11 ;
F_16 ( V_21 ) ;
return 0 ;
}
static int F_40 ( struct V_28 * V_29 )
{
struct V_54 * V_55 = F_18 ( V_29 ) ;
struct V_20 * V_21 = V_55 -> V_56 ;
int V_11 ;
V_11 = F_9 ( V_21 ) ;
if ( V_11 )
return V_11 ;
return F_41 ( V_29 ) ;
}
