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
V_48 |
V_49 |
V_50 |
V_51 |
V_42 |
V_52 |
V_53 |
V_54 ) ;
F_12 ( V_26 -> V_36 , V_37 ,
V_46 ,
V_46 ) ;
F_4 ( 100 , 200 ) ;
V_11 = F_8 ( V_21 ) ;
if ( V_11 ) {
F_13 ( V_29 , L_1 , V_11 ) ;
goto V_34;
}
}
F_4 ( 1000 , 2000 ) ;
return 0 ;
V_34:
if ( V_21 -> V_32 )
F_14 ( V_21 -> V_32 ) ;
return V_11 ;
}
static void F_15 ( struct V_20 * V_21 )
{
struct V_25 * V_26 = V_21 -> V_27 ;
if ( V_26 -> V_31 )
return;
if ( V_26 -> type == V_35 ) {
F_12 ( V_26 -> V_36 , V_37 ,
V_46 ,
! V_46 ) ;
}
F_16 ( V_26 -> V_33 ) ;
if ( V_21 -> V_32 )
F_14 ( V_21 -> V_32 ) ;
}
static void F_17 ( struct V_55 * V_56 )
{
T_2 V_57 ;
struct V_58 * V_29 ;
struct V_59 * V_60 = F_18 ( V_56 -> V_29 ) ;
struct V_20 * V_21 = V_60 -> V_61 ;
void T_1 * V_1 = V_21 -> V_1 ;
struct V_25 * V_26 = V_21 -> V_27 ;
F_19 ( V_56 ) ;
if ( ! ( V_26 -> V_62 ) || V_63 )
return;
V_26 -> V_62 = false ;
F_20 (dev, &ap->link, ENABLED)
return;
V_57 = F_2 ( V_1 + V_6 ) ;
F_3 ( V_57 | V_64 , V_1 + V_6 ) ;
F_15 ( V_21 ) ;
V_26 -> V_31 = true ;
F_21 ( V_56 -> V_29 , L_2 ) ;
F_21 ( V_56 -> V_29 , L_3 V_65 L_4 ) ;
}
static int F_22 ( struct V_66 * V_67 , unsigned int * V_68 ,
unsigned long V_69 )
{
struct V_55 * V_56 = V_67 -> V_56 ;
struct V_59 * V_60 = F_18 ( V_56 -> V_29 ) ;
struct V_20 * V_21 = V_60 -> V_61 ;
struct V_25 * V_26 = V_21 -> V_27 ;
int V_11 = - V_70 ;
if ( V_26 -> type == V_71 )
V_11 = V_72 . V_73 ( V_67 , V_68 , V_69 ) ;
else if ( V_26 -> type == V_35 )
V_11 = V_74 . V_73 ( V_67 , V_68 , V_69 ) ;
return V_11 ;
}
static int F_23 ( struct V_75 * V_76 )
{
struct V_28 * V_29 = & V_76 -> V_29 ;
const struct V_77 * V_78 ;
struct V_20 * V_21 ;
struct V_25 * V_26 ;
unsigned int V_57 ;
int V_11 ;
V_78 = F_24 ( V_79 , V_29 ) ;
if ( ! V_78 )
return - V_80 ;
V_26 = F_25 ( V_29 , sizeof( * V_26 ) , V_81 ) ;
if ( ! V_26 )
return - V_82 ;
V_26 -> V_30 = V_76 ;
V_26 -> V_31 = false ;
V_26 -> V_62 = true ;
V_26 -> type = (enum V_83 ) V_78 -> V_84 ;
V_26 -> V_85 = F_26 ( V_29 , L_5 ) ;
if ( F_27 ( V_26 -> V_85 ) ) {
F_13 ( V_29 , L_6 ) ;
return F_28 ( V_26 -> V_85 ) ;
}
V_26 -> V_33 = F_26 ( V_29 , L_7 ) ;
if ( F_27 ( V_26 -> V_33 ) ) {
F_13 ( V_29 , L_8 ) ;
return F_28 ( V_26 -> V_33 ) ;
}
V_26 -> V_86 = F_26 ( V_29 , L_9 ) ;
if ( F_27 ( V_26 -> V_86 ) ) {
F_13 ( V_29 , L_10 ) ;
return F_28 ( V_26 -> V_86 ) ;
}
if ( V_26 -> type == V_35 ) {
V_26 -> V_36 = F_29 (
L_11 ) ;
if ( F_27 ( V_26 -> V_36 ) ) {
F_13 ( V_29 ,
L_12 ) ;
return F_28 ( V_26 -> V_36 ) ;
}
}
V_21 = F_30 ( V_76 ) ;
if ( F_27 ( V_21 ) )
return F_28 ( V_21 ) ;
V_21 -> V_27 = V_26 ;
V_11 = F_11 ( V_26 -> V_85 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_9 ( V_21 ) ;
if ( V_11 )
goto V_87;
V_57 = F_2 ( V_21 -> V_1 + V_88 ) ;
if ( ! ( V_57 & V_89 ) ) {
V_57 |= V_89 ;
F_3 ( V_57 , V_21 -> V_1 + V_88 ) ;
}
V_57 = F_2 ( V_21 -> V_1 + V_90 ) ;
if ( ! ( V_57 & 0x1 ) ) {
V_57 |= 0x1 ;
F_3 ( V_57 , V_21 -> V_1 + V_90 ) ;
}
V_57 = F_31 ( V_26 -> V_86 ) / 1000 ;
F_3 ( V_57 , V_21 -> V_1 + V_91 ) ;
V_11 = F_32 ( V_76 , V_21 , & V_92 ,
0 , 0 , 0 ) ;
if ( V_11 )
goto V_93;
return 0 ;
V_93:
F_15 ( V_21 ) ;
V_87:
F_16 ( V_26 -> V_85 ) ;
return V_11 ;
}
static void F_33 ( struct V_59 * V_60 )
{
struct V_20 * V_21 = V_60 -> V_61 ;
struct V_25 * V_26 = V_21 -> V_27 ;
F_15 ( V_21 ) ;
F_16 ( V_26 -> V_85 ) ;
}
static int F_34 ( struct V_28 * V_29 )
{
struct V_59 * V_60 = F_18 ( V_29 ) ;
struct V_20 * V_21 = V_60 -> V_61 ;
int V_11 ;
V_11 = F_35 ( V_29 ) ;
if ( V_11 )
return V_11 ;
F_15 ( V_21 ) ;
return 0 ;
}
static int F_36 ( struct V_28 * V_29 )
{
struct V_59 * V_60 = F_18 ( V_29 ) ;
struct V_20 * V_21 = V_60 -> V_61 ;
int V_11 ;
V_11 = F_9 ( V_21 ) ;
if ( V_11 )
return V_11 ;
return F_37 ( V_29 ) ;
}
