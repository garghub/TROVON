static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_4 ;
V_3 = F_2 ( V_2 , V_5 ) ;
V_3 |= V_6 ;
F_3 ( V_2 , V_3 , V_5 ) ;
V_4 = F_4 ( F_5 () , 20 ) ;
while ( ! ( ( V_3 = F_6 ( V_2 , V_5 ) )
& V_7 ) ) {
if ( F_7 ( F_5 () , V_4 ) ) {
F_8 ( F_9 ( V_2 -> V_8 ) , L_1 ) ;
return - V_9 ;
}
F_10 ( 900 , 1100 ) ;
}
return 0 ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned char V_10 , bool V_11 )
{
T_1 V_3 ;
T_1 V_12 ;
V_3 = F_2 ( V_2 , V_13 ) ;
V_12 = ( 0x1 << ( V_14 + V_10 ) ) ;
if ( V_11 )
V_3 |= V_12 ;
else
V_3 &= ~ V_12 ;
F_3 ( V_2 , V_3 , V_13 ) ;
}
static void F_12 ( struct V_1 * V_2 , bool V_11 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 , V_13 ) ;
if ( V_11 )
V_3 &= ~ V_15 ;
else
V_3 |= V_15 ;
F_3 ( V_2 , V_3 , V_13 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
unsigned char V_10 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 , V_13 ) ;
V_3 |= ( F_14 ( V_10 ) << V_16 ) ;
F_3 ( V_2 , V_3 , V_13 ) ;
V_2 -> V_8 -> V_17 |= V_18 ;
V_2 -> V_8 -> V_17 &= ~ V_19 ;
}
static void F_15 ( struct V_1 * V_2 ,
unsigned char V_10 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 , V_13 ) ;
V_3 &= ~ ( F_14 ( V_10 ) << V_16 ) ;
F_3 ( V_2 , V_3 , V_13 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
unsigned char V_10 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 , V_20 ) ;
V_3 |= F_14 ( V_10 ) ;
F_3 ( V_2 , V_3 , V_20 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 , V_20 ) ;
V_3 |= V_21 ;
F_3 ( V_2 , V_3 , V_20 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_19 ( V_2 ) ;
struct V_24 * V_25 = F_20 ( V_23 ) ;
T_1 V_3 ;
V_3 = F_2 ( V_2 , V_26 ) ;
V_3 &= ~ V_27 ;
F_3 ( V_2 , V_3 , V_26 ) ;
V_3 = F_2 ( V_2 , V_28 ) ;
V_3 &= ~ V_29 ;
F_3 ( V_2 , V_3 , V_28 ) ;
V_3 = F_2 ( V_2 , V_30 ) ;
V_3 &= ~ V_29 ;
F_3 ( V_2 , V_3 , V_30 ) ;
V_2 -> V_31 = V_32 ;
V_2 -> V_33 = 1 << ( V_25 -> V_33 - 1 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
unsigned char V_10 , T_3 V_12 )
{
if ( ! ( V_12 & V_34 ) )
return;
F_18 ( V_2 ) ;
F_12 ( V_2 , true ) ;
F_11 ( V_2 , V_10 , false ) ;
F_17 ( V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_3 V_12 )
{
struct V_22 * V_23 = F_19 ( V_2 ) ;
struct V_24 * V_25 = F_20 ( V_23 ) ;
F_23 ( V_2 , V_12 ) ;
F_21 ( V_2 , V_25 -> V_10 , V_12 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
unsigned int V_35 )
{
T_4 V_36 ;
V_36 = F_6 ( V_2 , V_37 ) ;
V_36 &= ~ V_38 ;
if ( V_35 == V_39 )
V_36 |= V_40 ;
else if ( V_35 == V_41 )
V_36 |= V_42 ;
else if ( V_35 == V_43 )
V_36 |= V_44 ;
else if ( V_35 == V_45 )
V_36 |= V_46 ;
else if ( V_35 == V_47 )
V_36 |= V_48 ;
else if ( ( V_35 == V_49 ) ||
( V_35 == V_50 ) )
V_36 |= V_51 ;
else if ( V_35 == V_52 )
V_36 |= V_53 ;
F_25 ( V_2 , V_36 , V_37 ) ;
}
static void F_26 ( struct V_1 * V_2 , unsigned char V_54 ,
unsigned short V_55 )
{
struct V_56 * V_8 = V_2 -> V_8 ;
T_3 V_57 = V_2 -> V_57 ;
F_27 ( V_2 , V_54 , V_55 ) ;
if ( V_2 -> V_57 == V_57 )
return;
if ( V_2 -> V_57 == 0 )
V_55 = 0 ;
if ( ! F_28 ( V_8 -> V_58 . V_59 ) )
F_29 ( V_8 , V_8 -> V_58 . V_59 , V_55 ) ;
}
static void F_30 ( struct V_56 * V_8 , struct V_60 * V_61 )
{
struct V_1 * V_2 = F_31 ( V_8 ) ;
struct V_22 * V_23 = F_19 ( V_2 ) ;
struct V_24 * V_25 = F_20 ( V_23 ) ;
T_1 V_3 ;
if ( ( V_61 -> V_35 == V_52 ) ||
( V_61 -> V_35 == V_39 ) ||
( V_61 -> V_35 == V_62 ) ) {
V_2 -> V_63 = false ;
V_2 -> V_64 |= V_65 ;
V_2 -> V_66 &= ~ V_67 ;
V_3 = F_6 ( V_2 , V_37 ) ;
V_3 &= ~ V_68 ;
F_25 ( V_2 , V_3 , V_37 ) ;
} else {
V_2 -> V_64 &= ~ V_65 ;
}
F_32 ( V_8 , V_61 ) ;
F_33 ( V_2 , V_61 ) ;
if ( V_2 -> clock > V_69 )
F_11 ( V_2 , V_25 -> V_10 , true ) ;
}
static int F_34 ( struct V_56 * V_8 ,
struct V_60 * V_61 )
{
struct V_1 * V_2 = F_31 ( V_8 ) ;
F_1 ( V_2 ) ;
F_35 ( V_2 , V_61 -> V_70 ) ;
if ( F_36 ( V_8 -> V_58 . V_71 ) == - V_72 )
return 0 ;
return F_37 ( V_8 , V_61 ) ;
}
static void F_38 ( struct V_56 * V_8 , struct V_73 * V_74 )
{
struct V_1 * V_2 = F_31 ( V_8 ) ;
struct V_22 * V_23 = F_19 ( V_2 ) ;
struct V_24 * V_25 = F_20 ( V_23 ) ;
V_25 -> V_75 = V_74 -> type ;
}
static int F_39 ( struct V_56 * V_8 , T_1 V_76 )
{
struct V_1 * V_2 = F_31 ( V_8 ) ;
if ( V_2 -> V_35 == V_49 ||
V_2 -> V_35 == V_50 )
return 0 ;
if ( V_2 -> V_31 != V_32 )
F_18 ( V_2 ) ;
return F_40 ( V_8 , V_76 ) ;
}
static void F_41 ( struct V_56 * V_8 , int V_11 )
{
struct V_1 * V_2 = F_31 ( V_8 ) ;
struct V_22 * V_23 = F_19 ( V_2 ) ;
struct V_24 * V_25 = F_20 ( V_23 ) ;
T_1 V_3 ;
T_3 V_10 = V_25 -> V_10 ;
F_42 ( V_8 , V_11 ) ;
if ( V_11 ) {
V_3 = F_2 ( V_2 , V_77 ) ;
V_3 |= ( 1 << ( V_10 + V_78 ) ) ;
F_3 ( V_2 , V_3 , V_77 ) ;
} else {
V_3 = F_2 ( V_2 , V_77 ) ;
V_3 &= ~ ( 1 << ( V_10 + V_78 ) ) ;
F_3 ( V_2 , V_3 , V_77 ) ;
}
}
static void F_43 ( struct V_1 * V_2 )
{
V_2 -> V_79 . V_80 = F_30 ;
V_2 -> V_79 . V_81 =
F_34 ;
V_2 -> V_79 . V_82 = F_38 ;
V_2 -> V_79 . V_83 = F_39 ;
V_2 -> V_79 . V_84 = F_41 ;
}
static int F_44 ( struct V_85 * V_86 )
{
struct V_87 * V_88 = V_86 -> V_89 . V_90 ;
struct V_1 * V_2 = F_45 ( V_86 ) ;
struct V_56 * V_8 = V_2 -> V_8 ;
struct V_22 * V_23 = F_19 ( V_2 ) ;
struct V_24 * V_25 = F_20 ( V_23 ) ;
T_1 V_10 , V_91 ;
T_1 V_33 ;
if ( F_46 ( V_88 , L_2 ) )
V_2 -> V_64 |= V_92 ;
V_10 = 0x0 ;
if ( ! F_47 ( V_88 , L_3 , & V_10 ) ) {
V_91 = F_2 ( V_2 , V_77 ) ;
V_91 &= V_93 ;
if ( F_48 ( V_10 > V_91 ) ) {
F_8 ( F_9 ( V_8 ) , L_4 ,
V_10 , V_91 ) ;
return - V_94 ;
}
}
V_25 -> V_10 = V_10 ;
V_33 = V_95 ;
if ( ! F_47 ( V_88 , L_5 ,
& V_33 ) ) {
if ( F_48 ( V_33 >= V_96 ) ) {
F_8 ( F_9 ( V_8 ) , L_6 ,
V_95 ) ;
V_33 = V_95 ;
}
}
V_25 -> V_33 = V_33 ;
return F_49 ( V_88 , V_2 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_19 ( V_2 ) ;
struct V_24 * V_25 = F_20 ( V_23 ) ;
T_3 V_10 = V_25 -> V_10 ;
F_13 ( V_2 , V_10 ) ;
F_12 ( V_2 , true ) ;
F_16 ( V_2 , V_10 ) ;
F_11 ( V_2 , V_10 , false ) ;
F_17 ( V_2 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_19 ( V_2 ) ;
struct V_24 * V_25 = F_20 ( V_23 ) ;
T_3 V_10 = V_25 -> V_10 ;
F_15 ( V_2 , V_10 ) ;
}
static int F_52 ( struct V_85 * V_86 )
{
struct V_22 * V_23 ;
struct V_1 * V_2 ;
struct V_24 * V_25 ;
int V_97 ;
V_2 = F_53 ( V_86 , & V_98 ,
sizeof( struct V_24 ) ) ;
if ( F_28 ( V_2 ) )
return F_36 ( V_2 ) ;
V_23 = F_19 ( V_2 ) ;
V_25 = F_20 ( V_23 ) ;
F_43 ( V_2 ) ;
V_23 -> V_99 = F_54 ( & V_86 -> V_89 , L_7 ) ;
if ( F_28 ( V_23 -> V_99 ) ) {
V_97 = F_36 ( V_23 -> V_99 ) ;
F_8 ( & V_86 -> V_89 , L_8 , V_97 ) ;
goto V_100;
}
V_97 = F_55 ( V_23 -> V_99 ) ;
if ( V_97 )
goto V_100;
V_25 -> V_101 = F_54 ( & V_86 -> V_89 , L_9 ) ;
if ( F_28 ( V_25 -> V_101 ) ) {
V_97 = F_36 ( V_25 -> V_101 ) ;
if ( V_97 == - V_102 )
goto V_103;
} else {
V_97 = F_55 ( V_25 -> V_101 ) ;
if ( V_97 )
goto V_103;
}
V_97 = F_56 ( V_2 -> V_8 ) ;
if ( V_97 )
goto V_104;
F_57 ( V_86 ) ;
F_12 ( V_2 , false ) ;
V_97 = F_44 ( V_86 ) ;
if ( V_97 )
goto V_104;
V_97 = F_50 ( V_2 ) ;
if ( V_97 )
goto V_104;
F_58 ( & V_86 -> V_89 ) ;
F_59 ( & V_86 -> V_89 ) ;
F_60 ( & V_86 -> V_89 , 50 ) ;
F_61 ( & V_86 -> V_89 ) ;
F_62 ( & V_86 -> V_89 ) ;
F_63 ( & V_86 -> V_89 , 1 ) ;
V_97 = F_64 ( V_2 ) ;
if ( V_97 )
goto V_105;
F_65 ( & V_86 -> V_89 ) ;
return 0 ;
V_105:
F_66 ( & V_86 -> V_89 ) ;
F_67 ( & V_86 -> V_89 ) ;
F_51 ( V_2 ) ;
V_104:
F_68 ( V_25 -> V_101 ) ;
V_103:
F_68 ( V_23 -> V_99 ) ;
V_100:
F_69 ( V_86 ) ;
return V_97 ;
}
static int F_70 ( struct V_85 * V_86 )
{
struct V_1 * V_2 = F_45 ( V_86 ) ;
struct V_22 * V_23 = F_19 ( V_2 ) ;
struct V_24 * V_25 = F_20 ( V_23 ) ;
F_71 ( & V_86 -> V_89 ) ;
F_66 ( & V_86 -> V_89 ) ;
F_67 ( & V_86 -> V_89 ) ;
F_72 ( V_2 , 0 ) ;
F_51 ( V_2 ) ;
F_68 ( V_25 -> V_101 ) ;
F_68 ( V_23 -> V_99 ) ;
F_69 ( V_86 ) ;
return 0 ;
}
static int F_73 ( struct V_106 * V_89 )
{
struct V_1 * V_2 = F_74 ( V_89 ) ;
struct V_22 * V_23 = F_19 ( V_2 ) ;
struct V_24 * V_25 = F_20 ( V_23 ) ;
int V_107 ;
V_107 = F_75 ( V_89 ) ;
V_25 -> V_108 = true ;
return V_107 ;
}
static int F_76 ( struct V_106 * V_89 )
{
struct V_1 * V_2 = F_74 ( V_89 ) ;
struct V_22 * V_23 = F_19 ( V_2 ) ;
struct V_24 * V_25 = F_20 ( V_23 ) ;
int V_107 ;
V_107 = F_77 ( V_2 ) ;
if ( V_107 )
return V_107 ;
if ( V_2 -> V_31 != V_109 )
F_78 ( V_2 -> V_8 ) ;
F_68 ( V_23 -> V_99 ) ;
V_25 -> clock = 0 ;
return 0 ;
}
static int F_79 ( struct V_106 * V_89 )
{
struct V_1 * V_2 = F_74 ( V_89 ) ;
struct V_22 * V_23 = F_19 ( V_2 ) ;
struct V_24 * V_25 = F_20 ( V_23 ) ;
int V_107 ;
V_107 = F_55 ( V_23 -> V_99 ) ;
if ( V_107 ) {
F_8 ( V_89 , L_10 ) ;
return V_107 ;
}
if ( V_25 -> V_108 ) {
V_107 = F_50 ( V_2 ) ;
if ( V_107 )
goto V_110;
V_25 -> V_108 = false ;
}
V_107 = F_80 ( V_2 ) ;
if ( V_107 )
goto V_110;
return 0 ;
V_110:
F_68 ( V_23 -> V_99 ) ;
return V_107 ;
}
