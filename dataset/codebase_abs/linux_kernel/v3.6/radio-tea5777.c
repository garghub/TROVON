static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return ( V_3 * V_4 + V_5 ) * 16 ;
}
static int F_2 ( struct V_1 * V_2 )
{
T_2 V_3 ;
int V_6 ;
V_3 = F_3 ( T_1 , V_2 -> V_3 ,
V_7 , V_8 ) + 8 ;
F_4 ( V_3 , 16 ) ;
V_3 -= V_5 ;
F_4 ( V_3 , V_4 ) ;
V_2 -> V_9 &= ~ ( V_10 | V_11 ) ;
V_2 -> V_9 |= V_3 << V_12 ;
V_2 -> V_9 |= V_13 << V_14 ;
V_6 = V_2 -> V_15 -> V_9 ( V_2 , V_2 -> V_9 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_16 = false ;
V_2 -> V_17 = - 1 ;
V_2 -> V_3 = F_1 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_18 )
{
int V_6 ;
if ( V_2 -> V_17 != - 1 )
return 0 ;
if ( V_2 -> V_19 && V_2 -> V_16 ) {
V_6 = F_2 ( V_2 ) ;
if ( V_6 )
return V_6 ;
}
if ( V_18 ) {
if ( F_6 ( F_7 ( V_18 ) ) )
return - V_20 ;
}
V_6 = V_2 -> V_15 -> V_17 ( V_2 , & V_2 -> V_17 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_16 = true ;
return 0 ;
}
static int F_8 ( struct V_21 * V_21 , void * V_22 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = F_9 ( V_21 ) ;
F_10 ( V_24 -> V_25 , V_2 -> V_26 -> V_27 , sizeof( V_24 -> V_25 ) ) ;
F_10 ( V_24 -> V_28 , V_2 -> V_28 , sizeof( V_24 -> V_28 ) ) ;
F_11 ( V_24 -> V_28 , L_1 , sizeof( V_24 -> V_28 ) ) ;
F_10 ( V_24 -> V_29 , V_2 -> V_29 , sizeof( V_24 -> V_29 ) ) ;
V_24 -> V_30 = V_31 | V_32 ;
V_24 -> V_30 |= V_33 ;
V_24 -> V_34 = V_24 -> V_30 | V_35 ;
return 0 ;
}
static int F_12 ( struct V_21 * V_21 , void * V_22 ,
struct V_36 * V_24 )
{
struct V_1 * V_2 = F_9 ( V_21 ) ;
int V_6 ;
if ( V_24 -> V_37 > 0 )
return - V_38 ;
V_6 = F_5 ( V_2 , 0 ) ;
if ( V_6 )
return V_6 ;
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
if ( V_2 -> V_39 )
F_10 ( V_24 -> V_27 , L_2 , sizeof( V_24 -> V_27 ) ) ;
else
F_10 ( V_24 -> V_27 , L_3 , sizeof( V_24 -> V_27 ) ) ;
V_24 -> type = V_40 ;
V_24 -> V_41 = V_42 | V_43 |
V_44 ;
V_24 -> V_45 = V_7 ;
V_24 -> V_46 = V_8 ;
V_24 -> V_47 = ( V_2 -> V_17 & V_48 ) ?
V_49 : V_50 ;
V_24 -> V_51 = ( V_2 -> V_9 & V_52 ) ?
V_53 : V_54 ;
V_24 -> signal = ( V_2 -> V_17 & V_55 ) >>
( V_56 - 12 ) ;
V_2 -> V_17 = - 1 ;
return 0 ;
}
static int F_13 ( struct V_21 * V_21 , void * V_22 ,
struct V_36 * V_24 )
{
struct V_1 * V_2 = F_9 ( V_21 ) ;
if ( V_24 -> V_37 )
return - V_38 ;
if ( V_24 -> V_51 == V_53 )
V_2 -> V_9 |= V_52 ;
else
V_2 -> V_9 &= ~ V_52 ;
return F_2 ( V_2 ) ;
}
static int F_14 ( struct V_21 * V_21 , void * V_22 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = F_9 ( V_21 ) ;
if ( V_58 -> V_59 != 0 )
return - V_38 ;
V_58 -> type = V_40 ;
V_58 -> V_60 = V_2 -> V_3 ;
return 0 ;
}
static int F_15 ( struct V_21 * V_21 , void * V_22 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = F_9 ( V_21 ) ;
if ( V_58 -> V_59 != 0 || V_58 -> type != V_40 )
return - V_38 ;
V_2 -> V_3 = V_58 -> V_60 ;
return F_2 ( V_2 ) ;
}
static int F_16 ( struct V_21 * V_21 , void * V_61 ,
struct V_62 * V_63 )
{
struct V_1 * V_2 = F_9 ( V_21 ) ;
T_1 V_64 = V_2 -> V_3 ;
unsigned long V_65 ;
int V_6 , V_66 = 200 * 16 ;
const T_1 V_67 = V_7 ;
const T_1 V_68 = V_8 ;
if ( V_63 -> V_59 || V_63 -> V_69 )
return - V_38 ;
V_2 -> V_9 |= V_70 ;
if ( V_67 != V_2 -> V_67 ) {
V_2 -> V_9 &= ~ V_71 ;
V_2 -> V_3 = V_67 ;
V_6 = F_2 ( V_2 ) ;
if ( V_6 )
goto V_72;
V_2 -> V_67 = V_2 -> V_3 ;
}
if ( V_68 != V_2 -> V_68 ) {
V_2 -> V_9 |= V_71 ;
V_2 -> V_3 = V_68 ;
V_6 = F_2 ( V_2 ) ;
if ( V_6 )
goto V_72;
V_2 -> V_68 = V_2 -> V_3 ;
}
V_2 -> V_9 &= ~ V_70 ;
V_2 -> V_9 |= V_73 ;
if ( V_63 -> V_74 ) {
V_2 -> V_9 |= V_71 ;
V_2 -> V_3 = V_64 + V_66 ;
} else {
V_2 -> V_9 &= ~ V_71 ;
V_2 -> V_3 = V_64 - V_66 ;
}
V_6 = F_2 ( V_2 ) ;
if ( V_6 )
goto V_72;
V_65 = V_75 + F_7 ( 5000 ) ;
for (; ; ) {
if ( F_17 ( V_75 , V_65 ) ) {
V_6 = - V_76 ;
break;
}
V_6 = F_5 ( V_2 , 100 ) ;
if ( V_6 )
break;
V_2 -> V_3 = ( V_2 -> V_17 & V_77 ) ;
V_2 -> V_3 = F_1 ( V_2 , V_2 -> V_3 ) ;
if ( ( V_2 -> V_17 & V_78 ) ) {
V_2 -> V_9 &= ~ V_73 ;
return 0 ;
}
if ( V_2 -> V_17 & V_79 ) {
V_6 = - V_76 ;
break;
}
V_2 -> V_17 = - 1 ;
}
V_72:
V_2 -> V_9 &= ~ V_70 ;
V_2 -> V_9 &= ~ V_73 ;
V_2 -> V_3 = V_64 ;
F_2 ( V_2 ) ;
return V_6 ;
}
static int F_18 ( struct V_80 * V_81 )
{
struct V_1 * V_2 =
F_19 ( V_81 -> V_82 , struct V_1 , V_83 ) ;
switch ( V_81 -> V_84 ) {
case V_85 :
if ( V_81 -> V_86 )
V_2 -> V_9 |= V_87 ;
else
V_2 -> V_9 &= ~ V_87 ;
return F_2 ( V_2 ) ;
}
return - V_38 ;
}
int F_20 ( struct V_1 * V_2 , struct V_88 * V_89 )
{
int V_6 ;
V_2 -> V_9 = ( 1LL << V_90 ) |
( 1LL << V_91 ) |
( 1LL << V_92 ) |
( 1LL << V_93 ) |
( 2LL << V_94 ) ;
V_2 -> V_3 = 90500 * 16 ;
V_6 = F_2 ( V_2 ) ;
if ( V_6 ) {
F_21 ( V_2 -> V_26 , L_4 , V_6 ) ;
return V_6 ;
}
V_2 -> V_95 = V_96 ;
F_22 ( & V_2 -> V_95 , V_2 ) ;
F_23 ( & V_2 -> V_97 ) ;
F_10 ( V_2 -> V_95 . V_27 , V_2 -> V_26 -> V_27 , sizeof( V_2 -> V_95 . V_27 ) ) ;
V_2 -> V_95 . V_98 = & V_2 -> V_97 ;
V_2 -> V_95 . V_26 = V_2 -> V_26 ;
V_2 -> V_99 = V_100 ;
V_2 -> V_99 . V_89 = V_89 ;
V_2 -> V_95 . V_99 = & V_2 -> V_99 ;
F_24 ( V_101 , & V_2 -> V_95 . V_102 ) ;
V_2 -> V_95 . V_83 = & V_2 -> V_83 ;
F_25 ( & V_2 -> V_83 , 1 ) ;
F_26 ( & V_2 -> V_83 , & V_103 ,
V_85 , 0 , 1 , 1 , 1 ) ;
V_6 = V_2 -> V_83 . error ;
if ( V_6 ) {
F_21 ( V_2 -> V_26 , L_5 ) ;
F_27 ( & V_2 -> V_83 ) ;
return V_6 ;
}
F_28 ( & V_2 -> V_83 ) ;
V_6 = F_29 ( & V_2 -> V_95 , V_104 , - 1 ) ;
if ( V_6 ) {
F_21 ( V_2 -> V_26 , L_6 ) ;
F_27 ( V_2 -> V_95 . V_83 ) ;
return V_6 ;
}
return 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
F_31 ( & V_2 -> V_95 ) ;
F_27 ( V_2 -> V_95 . V_83 ) ;
}
