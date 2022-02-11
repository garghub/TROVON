static inline int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_3 == V_8 ) {
V_4 |= V_6 -> V_9 ;
V_4 &= ~ V_6 -> V_10 ;
}
return V_4 ;
}
static void F_2 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
F_4 ( V_12 ) ;
( void ) V_2 -> V_13 ( V_2 , V_14 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_4 )
{
void T_1 * V_3 = V_2 -> V_15 + ( V_16 << V_2 -> V_17 ) ;
int V_18 = 1000 ;
while ( V_18 -- ) {
unsigned int V_19 = V_2 -> V_13 ( V_2 , V_16 ) ;
if ( ( V_4 & ~ V_20 ) == ( V_19 & ~ V_20 ) )
return;
F_2 ( V_2 ) ;
#ifdef F_6
if ( V_2 -> type == V_21 )
F_7 ( V_4 & 0xff , V_3 ) ;
else
#endif
if ( V_2 -> V_22 == V_23 )
F_8 ( V_4 , V_3 ) ;
else if ( V_2 -> V_22 == V_24 )
F_9 ( V_4 , V_3 ) ;
else
F_10 ( V_4 , V_3 ) ;
}
}
static void F_11 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_10 ( V_4 , V_2 -> V_15 + ( V_3 << V_2 -> V_17 ) ) ;
if ( V_3 == V_16 && ! V_6 -> V_25 )
F_5 ( V_2 , V_4 ) ;
}
static unsigned int F_12 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 = F_13 ( V_2 -> V_15 + ( V_3 << V_2 -> V_17 ) ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static unsigned int F_14 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 ;
V_4 = ( V_26 ) F_15 ( V_2 -> V_15 + ( V_3 << V_2 -> V_17 ) ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static void F_16 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_4 &= 0xff ;
F_7 ( V_4 , V_2 -> V_15 + ( V_3 << V_2 -> V_17 ) ) ;
F_15 ( V_2 -> V_15 + ( V_16 << V_2 -> V_17 ) ) ;
if ( V_3 == V_16 && ! V_6 -> V_25 )
F_5 ( V_2 , V_4 ) ;
}
static void F_17 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_8 ( V_4 , V_2 -> V_15 + ( V_3 << V_2 -> V_17 ) ) ;
if ( V_3 == V_16 && ! V_6 -> V_25 )
F_5 ( V_2 , V_4 ) ;
}
static unsigned int F_18 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 = F_19 ( V_2 -> V_15 + ( V_3 << V_2 -> V_17 ) ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static void F_20 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_9 ( V_4 , V_2 -> V_15 + ( V_3 << V_2 -> V_17 ) ) ;
if ( V_3 == V_16 && ! V_6 -> V_25 )
F_5 ( V_2 , V_4 ) ;
}
static unsigned int F_21 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 = F_22 ( V_2 -> V_15 + ( V_3 << V_2 -> V_17 ) ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_27 = V_2 -> V_13 ( V_2 , V_28 ) ;
if ( F_24 ( V_2 , V_27 ) )
return 1 ;
if ( ( V_27 & V_29 ) == V_29 ) {
( void ) V_2 -> V_13 ( V_2 , V_6 -> V_30 ) ;
return 1 ;
}
return 0 ;
}
static void
F_25 ( struct V_1 * V_31 , unsigned int V_32 , unsigned int V_33 )
{
if ( ! V_32 )
F_26 ( V_31 -> V_34 ) ;
F_27 ( V_31 , V_32 , V_33 ) ;
if ( V_32 )
F_28 ( V_31 -> V_34 ) ;
}
static void F_29 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_35 * V_33 )
{
unsigned int V_37 = F_30 ( V_36 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_38 ;
int V_39 ;
if ( F_31 ( V_6 -> V_40 ) || ! V_33 )
goto V_41;
F_32 ( V_6 -> V_40 ) ;
V_38 = F_33 ( V_6 -> V_40 , V_37 * 16 ) ;
V_39 = F_34 ( V_6 -> V_40 , V_38 ) ;
F_35 ( V_6 -> V_40 ) ;
if ( ! V_39 )
V_2 -> V_42 = V_38 ;
V_2 -> V_43 &= ~ V_44 ;
if ( V_36 -> V_45 & V_46 )
V_2 -> V_43 |= V_44 ;
V_41:
F_36 ( V_2 , V_36 , V_33 ) ;
}
static bool F_37 ( struct V_47 * V_48 , void * V_49 )
{
return false ;
}
static bool F_38 ( struct V_47 * V_48 , void * V_49 )
{
return V_49 == V_48 -> V_50 -> V_34 -> V_51 ;
}
static void F_39 ( struct V_1 * V_2 , struct V_5 * V_52 )
{
if ( V_2 -> V_34 -> V_53 ) {
struct V_54 * V_55 = V_2 -> V_34 -> V_53 ;
int V_56 ;
V_56 = F_40 ( V_55 , L_1 ) ;
if ( V_56 >= 0 )
V_2 -> line = V_56 ;
#ifdef F_6
if ( F_41 ( V_55 , L_2 ) ) {
V_2 -> V_13 = F_14 ;
V_2 -> V_57 = F_16 ;
V_2 -> V_58 = V_59 | V_60 | V_61 ;
V_2 -> type = V_21 ;
V_52 -> V_30 = 0x27 ;
V_52 -> V_62 = true ;
}
#endif
if ( F_42 ( V_2 -> V_34 -> V_53 ) ) {
V_2 -> V_22 = V_24 ;
V_2 -> V_13 = F_21 ;
V_2 -> V_57 = F_20 ;
}
} else if ( F_43 ( V_2 -> V_34 ) ) {
V_2 -> V_22 = V_23 ;
V_2 -> V_17 = 2 ;
V_2 -> V_13 = F_18 ;
V_2 -> V_63 = F_29 ;
V_52 -> V_25 = true ;
}
if ( F_44 ( F_45 ( V_2 -> V_34 ) ,
V_64 , L_3 ) ) {
V_2 -> V_63 = F_29 ;
V_52 -> V_65 . V_66 = V_2 -> V_34 -> V_51 ;
V_52 -> V_65 . V_67 = V_2 -> V_34 -> V_51 ;
V_52 -> V_65 . V_68 = F_38 ;
}
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
T_2 V_69 ;
if ( V_2 -> V_22 == V_24 )
V_69 = F_22 ( V_2 -> V_15 + V_70 ) ;
else
V_69 = F_19 ( V_2 -> V_15 + V_70 ) ;
if ( ! V_69 )
return;
F_47 ( V_2 -> V_34 , L_4 ,
( V_69 >> 24 ) & 0xff , ( V_69 >> 16 ) & 0xff , ( V_69 >> 8 ) & 0xff ) ;
if ( V_2 -> V_22 == V_24 )
V_69 = F_22 ( V_2 -> V_15 + V_71 ) ;
else
V_69 = F_19 ( V_2 -> V_15 + V_71 ) ;
if ( ! V_69 )
return;
if ( V_69 & V_72 ) {
V_2 -> type = V_73 ;
V_2 -> V_58 |= V_61 ;
V_2 -> V_74 = F_48 ( V_69 ) ;
V_12 -> V_75 = V_76 ;
}
if ( V_69 & V_77 )
V_12 -> V_75 |= V_78 ;
}
static int F_49 ( struct V_79 * V_80 )
{
struct V_11 V_81 = {} ;
struct V_82 * V_83 = F_50 ( V_80 , V_64 , 0 ) ;
int V_84 = F_51 ( V_80 , 0 ) ;
struct V_1 * V_2 = & V_81 . V_31 ;
struct V_5 * V_52 ;
int V_85 ;
T_2 V_86 ;
if ( ! V_83 ) {
F_52 ( & V_80 -> V_34 , L_5 ) ;
return - V_87 ;
}
if ( V_84 < 0 ) {
if ( V_84 != - V_88 )
F_52 ( & V_80 -> V_34 , L_6 ) ;
return V_84 ;
}
F_53 ( & V_2 -> V_89 ) ;
V_2 -> V_90 = V_83 -> V_91 ;
V_2 -> V_84 = V_84 ;
V_2 -> V_92 = F_23 ;
V_2 -> V_93 = F_25 ;
V_2 -> type = V_94 ;
V_2 -> V_58 = V_60 | V_95 ;
V_2 -> V_34 = & V_80 -> V_34 ;
V_2 -> V_22 = V_96 ;
V_2 -> V_13 = F_12 ;
V_2 -> V_57 = F_11 ;
V_2 -> V_15 = F_54 ( & V_80 -> V_34 , V_83 -> V_91 , F_55 ( V_83 ) ) ;
if ( ! V_2 -> V_15 )
return - V_97 ;
V_52 = F_56 ( & V_80 -> V_34 , sizeof( * V_52 ) , V_98 ) ;
if ( ! V_52 )
return - V_97 ;
V_52 -> V_65 . V_68 = F_37 ;
V_52 -> V_30 = V_99 ;
V_2 -> V_7 = V_52 ;
V_52 -> V_25 = F_57 ( V_2 -> V_34 ,
L_7 ) ;
V_85 = F_58 ( V_2 -> V_34 , L_8 , & V_86 ) ;
if ( ! V_85 )
V_2 -> V_17 = V_86 ;
V_85 = F_58 ( V_2 -> V_34 , L_9 , & V_86 ) ;
if ( ! V_85 && V_86 == 4 ) {
V_2 -> V_22 = V_23 ;
V_2 -> V_13 = F_18 ;
V_2 -> V_57 = F_17 ;
}
if ( F_57 ( V_2 -> V_34 , L_10 ) ) {
V_52 -> V_9 |= V_100 ;
V_52 -> V_10 |= V_101 ;
}
if ( F_57 ( V_2 -> V_34 , L_11 ) ) {
V_52 -> V_9 |= V_102 ;
V_52 -> V_10 |= V_103 ;
}
if ( F_57 ( V_2 -> V_34 , L_12 ) ) {
V_52 -> V_9 |= V_104 ;
V_52 -> V_10 |= V_105 ;
}
if ( F_57 ( V_2 -> V_34 , L_13 ) ) {
V_52 -> V_10 |= V_106 ;
V_52 -> V_10 |= V_107 ;
}
F_58 ( V_2 -> V_34 , L_14 , & V_2 -> V_42 ) ;
V_52 -> V_40 = F_59 ( & V_80 -> V_34 , L_15 ) ;
if ( F_31 ( V_52 -> V_40 ) && F_60 ( V_52 -> V_40 ) != - V_88 )
V_52 -> V_40 = F_59 ( & V_80 -> V_34 , NULL ) ;
if ( F_31 ( V_52 -> V_40 ) && F_60 ( V_52 -> V_40 ) == - V_88 )
return - V_88 ;
if ( ! F_61 ( V_52 -> V_40 ) ) {
V_85 = F_35 ( V_52 -> V_40 ) ;
if ( V_85 )
F_62 ( & V_80 -> V_34 , L_16 ,
V_85 ) ;
else
V_2 -> V_42 = F_63 ( V_52 -> V_40 ) ;
}
if ( ! V_2 -> V_42 ) {
F_52 ( & V_80 -> V_34 , L_17 ) ;
return - V_87 ;
}
V_52 -> V_108 = F_59 ( & V_80 -> V_34 , L_18 ) ;
if ( F_31 ( V_52 -> V_40 ) && F_60 ( V_52 -> V_40 ) == - V_88 ) {
V_85 = - V_88 ;
goto V_109;
}
if ( ! F_31 ( V_52 -> V_108 ) ) {
V_85 = F_35 ( V_52 -> V_108 ) ;
if ( V_85 ) {
F_52 ( & V_80 -> V_34 , L_19 ) ;
goto V_109;
}
}
V_52 -> V_110 = F_64 ( & V_80 -> V_34 , NULL ) ;
if ( F_31 ( V_52 -> V_110 ) && F_60 ( V_52 -> V_110 ) == - V_88 ) {
V_85 = - V_88 ;
goto V_111;
}
if ( ! F_31 ( V_52 -> V_110 ) )
F_65 ( V_52 -> V_110 ) ;
F_39 ( V_2 , V_52 ) ;
if ( V_52 -> V_25 )
V_2 -> V_92 = NULL ;
if ( ! V_52 -> V_62 )
F_46 ( V_2 ) ;
if ( V_2 -> V_74 ) {
V_52 -> V_65 . V_112 . V_113 = V_2 -> V_74 / 4 ;
V_52 -> V_65 . V_114 . V_115 = V_2 -> V_74 / 4 ;
V_81 . V_65 = & V_52 -> V_65 ;
}
V_52 -> line = F_66 ( & V_81 ) ;
if ( V_52 -> line < 0 ) {
V_85 = V_52 -> line ;
goto V_116;
}
F_67 ( V_80 , V_52 ) ;
F_68 ( & V_80 -> V_34 ) ;
F_69 ( & V_80 -> V_34 ) ;
return 0 ;
V_116:
if ( ! F_31 ( V_52 -> V_110 ) )
F_70 ( V_52 -> V_110 ) ;
V_111:
if ( ! F_31 ( V_52 -> V_108 ) )
F_32 ( V_52 -> V_108 ) ;
V_109:
if ( ! F_31 ( V_52 -> V_40 ) )
F_32 ( V_52 -> V_40 ) ;
return V_85 ;
}
static int F_71 ( struct V_79 * V_80 )
{
struct V_5 * V_52 = F_72 ( V_80 ) ;
F_26 ( & V_80 -> V_34 ) ;
F_73 ( V_52 -> line ) ;
if ( ! F_31 ( V_52 -> V_110 ) )
F_70 ( V_52 -> V_110 ) ;
if ( ! F_31 ( V_52 -> V_108 ) )
F_32 ( V_52 -> V_108 ) ;
if ( ! F_31 ( V_52 -> V_40 ) )
F_32 ( V_52 -> V_40 ) ;
F_74 ( & V_80 -> V_34 ) ;
F_75 ( & V_80 -> V_34 ) ;
return 0 ;
}
static int F_76 ( struct V_50 * V_34 )
{
struct V_5 * V_52 = F_77 ( V_34 ) ;
F_78 ( V_52 -> line ) ;
return 0 ;
}
static int F_79 ( struct V_50 * V_34 )
{
struct V_5 * V_52 = F_77 ( V_34 ) ;
F_80 ( V_52 -> line ) ;
return 0 ;
}
static int F_81 ( struct V_50 * V_34 )
{
struct V_5 * V_52 = F_77 ( V_34 ) ;
if ( ! F_31 ( V_52 -> V_40 ) )
F_32 ( V_52 -> V_40 ) ;
if ( ! F_31 ( V_52 -> V_108 ) )
F_32 ( V_52 -> V_108 ) ;
return 0 ;
}
static int F_82 ( struct V_50 * V_34 )
{
struct V_5 * V_52 = F_77 ( V_34 ) ;
if ( ! F_31 ( V_52 -> V_108 ) )
F_35 ( V_52 -> V_108 ) ;
if ( ! F_31 ( V_52 -> V_40 ) )
F_35 ( V_52 -> V_40 ) ;
return 0 ;
}
