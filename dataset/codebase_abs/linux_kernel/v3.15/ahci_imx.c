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
V_11 = F_11 ( V_21 ) ;
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
V_47 |
V_48 |
V_49 |
V_50 |
V_41 |
V_51 |
V_52 |
V_53 ) ;
F_12 ( V_26 -> V_35 , V_36 ,
V_45 ,
V_45 ) ;
F_4 ( 100 , 200 ) ;
V_11 = F_8 ( V_21 ) ;
if ( V_11 ) {
F_13 ( V_29 , L_1 , V_11 ) ;
goto V_33;
}
}
F_4 ( 1000 , 2000 ) ;
return 0 ;
V_33:
if ( V_21 -> V_32 )
F_14 ( V_21 -> V_32 ) ;
return V_11 ;
}
static void F_15 ( struct V_20 * V_21 )
{
struct V_25 * V_26 = V_21 -> V_27 ;
if ( V_26 -> V_31 )
return;
if ( V_26 -> type == V_34 ) {
F_12 ( V_26 -> V_35 , V_36 ,
V_45 ,
! V_45 ) ;
}
F_16 ( V_21 ) ;
if ( V_21 -> V_32 )
F_14 ( V_21 -> V_32 ) ;
}
static void F_17 ( struct V_54 * V_55 )
{
T_2 V_56 ;
struct V_57 * V_29 ;
struct V_58 * V_59 = F_18 ( V_55 -> V_29 ) ;
struct V_20 * V_21 = V_59 -> V_60 ;
void T_1 * V_1 = V_21 -> V_1 ;
struct V_25 * V_26 = V_21 -> V_27 ;
F_19 ( V_55 ) ;
if ( ! ( V_26 -> V_61 ) || V_62 )
return;
V_26 -> V_61 = false ;
F_20 (dev, &ap->link, ENABLED)
return;
V_56 = F_2 ( V_1 + V_6 ) ;
F_3 ( V_56 | V_63 , V_1 + V_6 ) ;
F_15 ( V_21 ) ;
V_26 -> V_31 = true ;
}
static int F_21 ( struct V_64 * V_65 , unsigned int * V_66 ,
unsigned long V_67 )
{
struct V_54 * V_55 = V_65 -> V_55 ;
struct V_58 * V_59 = F_18 ( V_55 -> V_29 ) ;
struct V_20 * V_21 = V_59 -> V_60 ;
struct V_25 * V_26 = V_21 -> V_27 ;
int V_11 = - V_68 ;
if ( V_26 -> type == V_69 )
V_11 = V_70 . V_71 ( V_65 , V_66 , V_67 ) ;
else if ( V_26 -> type == V_34 )
V_11 = V_72 . V_71 ( V_65 , V_66 , V_67 ) ;
return V_11 ;
}
static int F_22 ( struct V_73 * V_74 )
{
struct V_28 * V_29 = & V_74 -> V_29 ;
const struct V_75 * V_76 ;
struct V_20 * V_21 ;
struct V_25 * V_26 ;
unsigned int V_56 ;
int V_11 ;
V_76 = F_23 ( V_77 , V_29 ) ;
if ( ! V_76 )
return - V_78 ;
V_26 = F_24 ( V_29 , sizeof( * V_26 ) , V_79 ) ;
if ( ! V_26 )
return - V_80 ;
V_26 -> V_30 = V_74 ;
V_26 -> V_31 = false ;
V_26 -> V_61 = true ;
V_26 -> type = (enum V_81 ) V_76 -> V_82 ;
V_26 -> V_83 = F_25 ( V_29 , L_2 ) ;
if ( F_26 ( V_26 -> V_83 ) ) {
F_13 ( V_29 , L_3 ) ;
return F_27 ( V_26 -> V_83 ) ;
}
if ( V_26 -> type == V_34 ) {
V_26 -> V_35 = F_28 (
L_4 ) ;
if ( F_26 ( V_26 -> V_35 ) ) {
F_13 ( V_29 ,
L_5 ) ;
return F_27 ( V_26 -> V_35 ) ;
}
}
V_21 = F_29 ( V_74 ) ;
if ( F_26 ( V_21 ) )
return F_27 ( V_21 ) ;
V_21 -> V_27 = V_26 ;
V_11 = F_9 ( V_21 ) ;
if ( V_11 )
return V_11 ;
V_56 = F_2 ( V_21 -> V_1 + V_84 ) ;
if ( ! ( V_56 & V_85 ) ) {
V_56 |= V_85 ;
F_3 ( V_56 , V_21 -> V_1 + V_84 ) ;
}
V_56 = F_2 ( V_21 -> V_1 + V_86 ) ;
if ( ! ( V_56 & 0x1 ) ) {
V_56 |= 0x1 ;
F_3 ( V_56 , V_21 -> V_1 + V_86 ) ;
}
V_56 = F_30 ( V_26 -> V_83 ) / 1000 ;
F_3 ( V_56 , V_21 -> V_1 + V_87 ) ;
V_11 = F_31 ( V_74 , V_21 , & V_88 , 0 , 0 ) ;
if ( V_11 )
F_15 ( V_21 ) ;
return V_11 ;
}
static void F_32 ( struct V_58 * V_59 )
{
struct V_20 * V_21 = V_59 -> V_60 ;
F_15 ( V_21 ) ;
}
static int F_33 ( struct V_28 * V_29 )
{
struct V_58 * V_59 = F_18 ( V_29 ) ;
struct V_20 * V_21 = V_59 -> V_60 ;
int V_11 ;
V_11 = F_34 ( V_29 ) ;
if ( V_11 )
return V_11 ;
F_15 ( V_21 ) ;
return 0 ;
}
static int F_35 ( struct V_28 * V_29 )
{
struct V_58 * V_59 = F_18 ( V_29 ) ;
struct V_20 * V_21 = V_59 -> V_60 ;
int V_11 ;
V_11 = F_9 ( V_21 ) ;
if ( V_11 )
return V_11 ;
return F_36 ( V_29 ) ;
}
