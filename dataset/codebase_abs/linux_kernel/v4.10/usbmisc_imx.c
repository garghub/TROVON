static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
unsigned long V_6 ;
T_1 V_7 = 0 ;
if ( V_2 -> V_8 > 1 )
return - V_9 ;
F_3 ( & V_4 -> V_10 , V_6 ) ;
switch ( V_2 -> V_8 ) {
case 0 :
V_7 = F_4 ( V_4 -> V_11 ) ;
V_7 &= ~ ( V_12 | V_13 ) ;
V_7 |= ( V_14 & V_15 ) << V_16 ;
V_7 |= ( V_17 | V_18 ) ;
F_5 ( V_7 , V_4 -> V_11 ) ;
break;
case 1 :
V_7 = F_4 ( V_4 -> V_11 ) ;
V_7 &= ~ ( V_19 | V_20 | V_21 ) ;
V_7 |= ( V_22 & V_15 ) << V_23 ;
V_7 |= ( V_24 | V_25 | V_26 |
V_27 | V_28 ) ;
F_5 ( V_7 , V_4 -> V_11 ) ;
break;
}
F_6 ( & V_4 -> V_10 , V_6 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
void T_2 * V_29 ;
unsigned long V_6 ;
T_1 V_7 ;
if ( V_2 -> V_8 > 2 )
return - V_9 ;
if ( V_2 -> V_30 ) {
F_3 ( & V_4 -> V_10 , V_6 ) ;
V_29 = V_4 -> V_11 + V_31 ;
V_7 = F_4 ( V_29 ) ;
F_5 ( V_7 | V_32 , V_29 ) ;
F_6 ( & V_4 -> V_10 , V_6 ) ;
F_8 ( 5000 , 10000 ) ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
unsigned long V_6 ;
T_1 V_7 ;
switch ( V_2 -> V_8 ) {
case 0 :
V_7 = V_33 ;
break;
case 1 :
V_7 = V_34 ;
break;
case 2 :
V_7 = V_35 ;
break;
default:
return - V_9 ;
}
F_3 ( & V_4 -> V_10 , V_6 ) ;
if ( V_2 -> V_36 )
V_7 = F_4 ( V_4 -> V_11 ) | V_7 ;
else
V_7 = F_4 ( V_4 -> V_11 ) & ~ V_7 ;
F_5 ( V_7 , V_4 -> V_11 ) ;
F_6 ( & V_4 -> V_10 , V_6 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
void T_2 * V_29 = NULL ;
unsigned long V_6 ;
T_1 V_7 = 0 ;
if ( V_2 -> V_8 > 3 )
return - V_9 ;
V_7 = F_4 ( V_4 -> V_11 + V_37 ) ;
V_7 &= ~ V_38 ;
V_7 |= V_39 ;
F_5 ( V_7 , V_4 -> V_11 + V_37 ) ;
F_3 ( & V_4 -> V_10 , V_6 ) ;
switch ( V_2 -> V_8 ) {
case 0 :
if ( V_2 -> V_36 ) {
V_29 = V_4 -> V_11 + V_40 ;
V_7 = F_4 ( V_29 ) | V_41 ;
F_5 ( V_7 , V_29 ) ;
}
break;
case 1 :
if ( V_2 -> V_36 ) {
V_29 = V_4 -> V_11 + V_40 ;
V_7 = F_4 ( V_29 ) | V_42 ;
F_5 ( V_7 , V_29 ) ;
}
break;
case 2 :
if ( V_2 -> V_43 ) {
V_29 = V_4 -> V_11 + V_44 ;
V_7 = F_4 ( V_29 ) | V_45 ;
V_7 &= ~ V_46 ;
V_7 |= V_47 ;
F_5 ( V_7 , V_29 ) ;
V_29 = V_4 -> V_11 + V_48 ;
V_7 = F_4 ( V_29 ) | V_49
| V_50 ;
F_5 ( V_7 , V_29 ) ;
V_29 = V_4 -> V_11 + V_51 ;
V_7 = F_4 ( V_29 ) | V_52 ;
F_5 ( V_7 , V_29 ) ;
}
if ( V_2 -> V_36 ) {
V_29 = V_4 -> V_11 + V_48 ;
V_7 = F_4 ( V_29 ) | V_53 ;
F_5 ( V_7 , V_29 ) ;
}
break;
case 3 :
if ( V_2 -> V_43 ) {
V_29 = V_4 -> V_11 + V_44 ;
V_7 = F_4 ( V_29 ) | V_54 ;
V_7 &= ~ V_55 ;
V_7 |= V_56 ;
F_5 ( V_7 , V_29 ) ;
V_29 = V_4 -> V_11 + V_57 ;
V_7 = F_4 ( V_29 ) | V_49
| V_50 ;
F_5 ( V_7 , V_29 ) ;
V_29 = V_4 -> V_11 + V_51 ;
V_7 = F_4 ( V_29 ) | V_58 ;
F_5 ( V_7 , V_29 ) ;
}
if ( V_2 -> V_36 ) {
V_29 = V_4 -> V_11 + V_57 ;
V_7 = F_4 ( V_29 ) | V_53 ;
F_5 ( V_7 , V_29 ) ;
}
break;
}
F_6 ( & V_4 -> V_10 , V_6 ) ;
return 0 ;
}
static int F_11
( struct V_1 * V_2 , bool V_59 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
unsigned long V_6 ;
T_1 V_7 ;
T_1 V_60 = ( V_61 |
V_62 | V_63 ) ;
int V_64 = 0 ;
if ( V_2 -> V_8 > 3 )
return - V_9 ;
F_3 ( & V_4 -> V_10 , V_6 ) ;
V_7 = F_4 ( V_4 -> V_11 + V_2 -> V_8 * 4 ) ;
if ( V_59 ) {
V_7 |= V_60 ;
F_5 ( V_7 , V_4 -> V_11 + V_2 -> V_8 * 4 ) ;
} else {
if ( V_7 & V_65 )
F_12 ( L_1 , V_2 -> V_8 ) ;
V_7 &= ~ V_60 ;
F_5 ( V_7 , V_4 -> V_11 + V_2 -> V_8 * 4 ) ;
}
F_6 ( & V_4 -> V_10 , V_6 ) ;
return V_64 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
unsigned long V_6 ;
T_1 V_29 ;
if ( V_2 -> V_8 > 3 )
return - V_9 ;
F_3 ( & V_4 -> V_10 , V_6 ) ;
V_29 = F_4 ( V_4 -> V_11 + V_2 -> V_8 * 4 ) ;
if ( V_2 -> V_36 ) {
V_29 |= V_66 ;
} else if ( V_2 -> V_67 == 1 ) {
V_29 &= ~ ( V_66 | V_68 ) ;
}
F_5 ( V_29 , V_4 -> V_11 + V_2 -> V_8 * 4 ) ;
V_29 = F_4 ( V_4 -> V_11 + V_2 -> V_8 * 4 ) ;
F_5 ( V_29 | V_69 ,
V_4 -> V_11 + V_2 -> V_8 * 4 ) ;
F_6 ( & V_4 -> V_10 , V_6 ) ;
F_11 ( V_2 , false ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
void T_2 * V_29 = NULL ;
unsigned long V_6 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
T_1 V_7 ;
F_13 ( V_2 ) ;
if ( V_2 -> V_8 == 0 || V_2 -> V_8 == 1 ) {
V_29 = V_4 -> V_11 + V_70 + V_2 -> V_8 * 4 ;
F_3 ( & V_4 -> V_10 , V_6 ) ;
V_7 = F_4 ( V_29 ) ;
F_5 ( V_7 | V_71 , V_29 ) ;
V_7 = F_4 ( V_4 -> V_11 + V_2 -> V_8 * 4 ) ;
F_5 ( V_7 & ~ V_72 ,
V_4 -> V_11 + V_2 -> V_8 * 4 ) ;
F_6 ( & V_4 -> V_10 , V_6 ) ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
T_1 V_29 ;
if ( V_2 -> V_8 >= 1 )
return - V_9 ;
if ( V_2 -> V_36 ) {
V_29 = F_4 ( V_4 -> V_11 ) ;
F_5 ( V_29 | V_73 , V_4 -> V_11 ) ;
}
return 0 ;
}
static int F_16
( struct V_1 * V_2 , bool V_59 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
unsigned long V_6 ;
T_1 V_7 ;
T_1 V_60 = ( V_61 |
V_62 | V_63 ) ;
F_3 ( & V_4 -> V_10 , V_6 ) ;
V_7 = F_4 ( V_4 -> V_11 ) ;
if ( V_59 ) {
F_5 ( V_7 | V_60 , V_4 -> V_11 ) ;
} else {
if ( V_7 & V_65 )
F_17 ( V_2 -> V_5 , L_2 ) ;
F_5 ( V_7 & ~ V_60 , V_4 -> V_11 ) ;
}
F_6 ( & V_4 -> V_10 , V_6 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
unsigned long V_6 ;
T_1 V_29 ;
if ( V_2 -> V_8 >= 1 )
return - V_9 ;
F_3 ( & V_4 -> V_10 , V_6 ) ;
V_29 = F_4 ( V_4 -> V_11 ) ;
if ( V_2 -> V_36 ) {
V_29 |= V_66 ;
} else if ( V_2 -> V_67 == 1 ) {
V_29 &= ~ ( V_66 | V_68 ) ;
}
F_5 ( V_29 , V_4 -> V_11 ) ;
V_29 = F_4 ( V_4 -> V_11 + V_74 ) ;
V_29 &= ~ V_75 ;
F_5 ( V_29 | V_76 ,
V_4 -> V_11 + V_74 ) ;
F_6 ( & V_4 -> V_10 , V_6 ) ;
F_16 ( V_2 , false ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! V_2 )
return 0 ;
V_4 = F_2 ( V_2 -> V_5 ) ;
if ( ! V_4 -> V_77 -> V_78 )
return 0 ;
return V_4 -> V_77 -> V_78 ( V_2 ) ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! V_2 )
return 0 ;
V_4 = F_2 ( V_2 -> V_5 ) ;
if ( ! V_4 -> V_77 -> V_79 )
return 0 ;
return V_4 -> V_77 -> V_79 ( V_2 ) ;
}
int F_21 ( struct V_1 * V_2 , bool V_59 )
{
struct V_3 * V_4 ;
if ( ! V_2 )
return 0 ;
V_4 = F_2 ( V_2 -> V_5 ) ;
if ( ! V_4 -> V_77 -> V_80 )
return 0 ;
return V_4 -> V_77 -> V_80 ( V_2 , V_59 ) ;
}
static int F_22 ( struct V_81 * V_82 )
{
struct V_83 * V_84 ;
struct V_3 * V_2 ;
const struct V_85 * V_86 ;
V_86 = F_23 ( V_87 , & V_82 -> V_5 ) ;
if ( ! V_86 )
return - V_88 ;
V_2 = F_24 ( & V_82 -> V_5 , sizeof( * V_2 ) , V_89 ) ;
if ( ! V_2 )
return - V_90 ;
F_25 ( & V_2 -> V_10 ) ;
V_84 = F_26 ( V_82 , V_91 , 0 ) ;
V_2 -> V_11 = F_27 ( & V_82 -> V_5 , V_84 ) ;
if ( F_28 ( V_2 -> V_11 ) )
return F_29 ( V_2 -> V_11 ) ;
V_2 -> V_77 = ( const struct V_92 * ) V_86 -> V_2 ;
F_30 ( V_82 , V_2 ) ;
return 0 ;
}
static int F_31 ( struct V_81 * V_82 )
{
return 0 ;
}
