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
static void F_5 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
F_6 ( V_4 , V_2 -> V_15 + ( V_3 << V_2 -> V_16 ) ) ;
if ( V_3 == V_17 ) {
int V_18 = 1000 ;
while ( V_18 -- ) {
unsigned int V_19 = V_2 -> V_13 ( V_2 , V_17 ) ;
if ( ( V_4 & ~ V_20 ) == ( V_19 & ~ V_20 ) )
return;
F_2 ( V_2 ) ;
F_6 ( V_4 , V_2 -> V_15 + ( V_17 << V_2 -> V_16 ) ) ;
}
}
}
static unsigned int F_7 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 = F_8 ( V_2 -> V_15 + ( V_3 << V_2 -> V_16 ) ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static unsigned int F_9 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 ;
V_4 = ( V_21 ) F_10 ( V_2 -> V_15 + ( V_3 << V_2 -> V_16 ) ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
V_4 &= 0xff ;
F_12 ( V_4 , V_2 -> V_15 + ( V_3 << V_2 -> V_16 ) ) ;
F_10 ( V_2 -> V_15 + ( V_17 << V_2 -> V_16 ) ) ;
if ( V_3 == V_17 ) {
int V_18 = 1000 ;
while ( V_18 -- ) {
unsigned int V_19 = V_2 -> V_13 ( V_2 , V_17 ) ;
if ( ( V_4 & ~ V_20 ) == ( V_19 & ~ V_20 ) )
return;
F_2 ( V_2 ) ;
F_12 ( V_4 & 0xff ,
V_2 -> V_15 + ( V_17 << V_2 -> V_16 ) ) ;
}
}
}
static void F_13 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
F_14 ( V_4 , V_2 -> V_15 + ( V_3 << V_2 -> V_16 ) ) ;
if ( V_3 == V_17 ) {
int V_18 = 1000 ;
while ( V_18 -- ) {
unsigned int V_19 = V_2 -> V_13 ( V_2 , V_17 ) ;
if ( ( V_4 & ~ V_20 ) == ( V_19 & ~ V_20 ) )
return;
F_2 ( V_2 ) ;
F_14 ( V_4 , V_2 -> V_15 + ( V_17 << V_2 -> V_16 ) ) ;
}
}
}
static unsigned int F_15 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 = F_16 ( V_2 -> V_15 + ( V_3 << V_2 -> V_16 ) ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_22 = V_2 -> V_13 ( V_2 , V_23 ) ;
if ( F_18 ( V_2 , V_22 ) ) {
return 1 ;
} else if ( ( V_22 & V_24 ) == V_24 ) {
( void ) V_2 -> V_13 ( V_2 , V_6 -> V_25 ) ;
return 1 ;
}
return 0 ;
}
static void
F_19 ( struct V_1 * V_26 , unsigned int V_27 , unsigned int V_28 )
{
if ( ! V_27 )
F_20 ( V_26 -> V_29 ) ;
F_21 ( V_26 , V_27 , V_28 ) ;
if ( V_27 )
F_22 ( V_26 -> V_29 ) ;
}
static void F_23 ( struct V_1 * V_2 , struct V_30 * V_31 ,
struct V_30 * V_28 )
{
unsigned int V_32 = F_24 ( V_31 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_33 ;
int V_34 ;
if ( F_25 ( V_6 -> V_35 ) || ! V_28 )
goto V_36;
F_26 ( V_6 -> V_35 ) ;
V_33 = F_27 ( V_6 -> V_35 , V_32 * 16 ) ;
V_34 = F_28 ( V_6 -> V_35 , V_33 ) ;
F_29 ( V_6 -> V_35 ) ;
if ( ! V_34 )
V_2 -> V_37 = V_33 ;
V_2 -> V_38 &= ~ V_39 ;
if ( V_31 -> V_40 & V_41 )
V_2 -> V_38 |= V_39 ;
V_36:
F_30 ( V_2 , V_31 , V_28 ) ;
}
static bool F_31 ( struct V_42 * V_43 , void * V_44 )
{
return false ;
}
static bool F_32 ( struct V_42 * V_43 , void * V_44 )
{
return V_44 == V_43 -> V_45 -> V_29 -> V_46 ;
}
static void F_33 ( struct V_1 * V_2 , struct V_5 * V_47 )
{
if ( V_2 -> V_29 -> V_48 ) {
struct V_49 * V_50 = V_2 -> V_29 -> V_48 ;
int V_51 ;
V_51 = F_34 ( V_50 , L_1 ) ;
if ( V_51 >= 0 )
V_2 -> line = V_51 ;
#ifdef F_35
if ( F_36 ( V_50 , L_2 ) ) {
V_2 -> V_13 = F_9 ;
V_2 -> V_52 = F_11 ;
V_2 -> V_53 = V_54 | V_55 | V_56 ;
V_2 -> type = V_57 ;
V_47 -> V_25 = 0x27 ;
V_47 -> V_58 = true ;
}
#endif
} else if ( F_37 ( V_2 -> V_29 ) ) {
V_2 -> V_59 = V_60 ;
V_2 -> V_16 = 2 ;
V_2 -> V_13 = F_15 ;
V_2 -> V_61 = F_23 ;
V_47 -> V_62 = true ;
}
if ( F_38 ( F_39 ( V_2 -> V_29 ) ,
V_63 , L_3 ) ) {
V_2 -> V_61 = F_23 ;
V_47 -> V_64 . V_65 = V_2 -> V_29 -> V_46 ;
V_47 -> V_64 . V_66 = V_2 -> V_29 -> V_46 ;
V_47 -> V_64 . V_67 = F_32 ;
}
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
T_1 V_68 ;
V_68 = F_16 ( V_2 -> V_15 + V_69 ) ;
if ( ! V_68 )
return;
F_41 ( V_2 -> V_29 , L_4 ,
( V_68 >> 24 ) & 0xff , ( V_68 >> 16 ) & 0xff , ( V_68 >> 8 ) & 0xff ) ;
V_68 = F_16 ( V_2 -> V_15 + V_70 ) ;
if ( ! V_68 )
return;
if ( V_68 & V_71 ) {
V_2 -> type = V_72 ;
V_2 -> V_53 |= V_56 ;
V_2 -> V_73 = F_42 ( V_68 ) ;
V_12 -> V_74 = V_75 ;
}
if ( V_68 & V_76 )
V_12 -> V_74 |= V_77 ;
}
static int F_43 ( struct V_78 * V_79 )
{
struct V_11 V_80 = {} ;
struct V_81 * V_82 = F_44 ( V_79 , V_63 , 0 ) ;
int V_83 = F_45 ( V_79 , 0 ) ;
struct V_1 * V_2 = & V_80 . V_26 ;
struct V_5 * V_47 ;
int V_84 ;
T_1 V_85 ;
if ( ! V_82 ) {
F_46 ( & V_79 -> V_29 , L_5 ) ;
return - V_86 ;
}
if ( V_83 < 0 ) {
if ( V_83 != - V_87 )
F_46 ( & V_79 -> V_29 , L_6 ) ;
return V_83 ;
}
F_47 ( & V_2 -> V_88 ) ;
V_2 -> V_89 = V_82 -> V_90 ;
V_2 -> V_83 = V_83 ;
V_2 -> V_91 = F_17 ;
V_2 -> V_92 = F_19 ;
V_2 -> type = V_93 ;
V_2 -> V_53 = V_55 | V_94 ;
V_2 -> V_29 = & V_79 -> V_29 ;
V_2 -> V_59 = V_95 ;
V_2 -> V_13 = F_7 ;
V_2 -> V_52 = F_5 ;
V_2 -> V_15 = F_48 ( & V_79 -> V_29 , V_82 -> V_90 , F_49 ( V_82 ) ) ;
if ( ! V_2 -> V_15 )
return - V_96 ;
V_47 = F_50 ( & V_79 -> V_29 , sizeof( * V_47 ) , V_97 ) ;
if ( ! V_47 )
return - V_96 ;
V_47 -> V_64 . V_67 = F_31 ;
V_47 -> V_25 = V_98 ;
V_2 -> V_7 = V_47 ;
V_47 -> V_62 = F_51 ( V_2 -> V_29 ,
L_7 ) ;
V_84 = F_52 ( V_2 -> V_29 , L_8 , & V_85 ) ;
if ( ! V_84 )
V_2 -> V_16 = V_85 ;
V_84 = F_52 ( V_2 -> V_29 , L_9 , & V_85 ) ;
if ( ! V_84 && V_85 == 4 ) {
V_2 -> V_59 = V_60 ;
V_2 -> V_13 = F_15 ;
V_2 -> V_52 = F_13 ;
}
if ( F_51 ( V_2 -> V_29 , L_10 ) ) {
V_47 -> V_9 |= V_99 ;
V_47 -> V_10 |= V_100 ;
}
if ( F_51 ( V_2 -> V_29 , L_11 ) ) {
V_47 -> V_9 |= V_101 ;
V_47 -> V_10 |= V_102 ;
}
if ( F_51 ( V_2 -> V_29 , L_12 ) ) {
V_47 -> V_9 |= V_103 ;
V_47 -> V_10 |= V_104 ;
}
if ( F_51 ( V_2 -> V_29 , L_13 ) ) {
V_47 -> V_10 |= V_105 ;
V_47 -> V_10 |= V_106 ;
}
F_52 ( V_2 -> V_29 , L_14 , & V_2 -> V_37 ) ;
V_47 -> V_35 = F_53 ( & V_79 -> V_29 , L_15 ) ;
if ( F_25 ( V_47 -> V_35 ) && F_54 ( V_47 -> V_35 ) != - V_87 )
V_47 -> V_35 = F_53 ( & V_79 -> V_29 , NULL ) ;
if ( F_25 ( V_47 -> V_35 ) && F_54 ( V_47 -> V_35 ) == - V_87 )
return - V_87 ;
if ( ! F_55 ( V_47 -> V_35 ) ) {
V_84 = F_29 ( V_47 -> V_35 ) ;
if ( V_84 )
F_56 ( & V_79 -> V_29 , L_16 ,
V_84 ) ;
else
V_2 -> V_37 = F_57 ( V_47 -> V_35 ) ;
}
if ( ! V_2 -> V_37 ) {
F_46 ( & V_79 -> V_29 , L_17 ) ;
return - V_86 ;
}
V_47 -> V_107 = F_53 ( & V_79 -> V_29 , L_18 ) ;
if ( F_25 ( V_47 -> V_35 ) && F_54 ( V_47 -> V_35 ) == - V_87 ) {
V_84 = - V_87 ;
goto V_108;
}
if ( ! F_25 ( V_47 -> V_107 ) ) {
V_84 = F_29 ( V_47 -> V_107 ) ;
if ( V_84 ) {
F_46 ( & V_79 -> V_29 , L_19 ) ;
goto V_108;
}
}
V_47 -> V_109 = F_58 ( & V_79 -> V_29 , NULL ) ;
if ( F_25 ( V_47 -> V_109 ) && F_54 ( V_47 -> V_109 ) == - V_87 ) {
V_84 = - V_87 ;
goto V_110;
}
if ( ! F_25 ( V_47 -> V_109 ) )
F_59 ( V_47 -> V_109 ) ;
F_33 ( V_2 , V_47 ) ;
if ( V_47 -> V_62 ) {
V_2 -> V_52 = NULL ;
V_2 -> V_91 = NULL ;
}
if ( ! V_47 -> V_58 )
F_40 ( V_2 ) ;
if ( V_2 -> V_73 ) {
V_47 -> V_64 . V_111 . V_112 = V_2 -> V_73 / 4 ;
V_47 -> V_64 . V_113 . V_114 = V_2 -> V_73 / 4 ;
V_80 . V_64 = & V_47 -> V_64 ;
}
V_47 -> line = F_60 ( & V_80 ) ;
if ( V_47 -> line < 0 ) {
V_84 = V_47 -> line ;
goto V_115;
}
F_61 ( V_79 , V_47 ) ;
F_62 ( & V_79 -> V_29 ) ;
F_63 ( & V_79 -> V_29 ) ;
return 0 ;
V_115:
if ( ! F_25 ( V_47 -> V_109 ) )
F_64 ( V_47 -> V_109 ) ;
V_110:
if ( ! F_25 ( V_47 -> V_107 ) )
F_26 ( V_47 -> V_107 ) ;
V_108:
if ( ! F_25 ( V_47 -> V_35 ) )
F_26 ( V_47 -> V_35 ) ;
return V_84 ;
}
static int F_65 ( struct V_78 * V_79 )
{
struct V_5 * V_47 = F_66 ( V_79 ) ;
F_20 ( & V_79 -> V_29 ) ;
F_67 ( V_47 -> line ) ;
if ( ! F_25 ( V_47 -> V_109 ) )
F_64 ( V_47 -> V_109 ) ;
if ( ! F_25 ( V_47 -> V_107 ) )
F_26 ( V_47 -> V_107 ) ;
if ( ! F_25 ( V_47 -> V_35 ) )
F_26 ( V_47 -> V_35 ) ;
F_68 ( & V_79 -> V_29 ) ;
F_69 ( & V_79 -> V_29 ) ;
return 0 ;
}
static int F_70 ( struct V_45 * V_29 )
{
struct V_5 * V_47 = F_71 ( V_29 ) ;
F_72 ( V_47 -> line ) ;
return 0 ;
}
static int F_73 ( struct V_45 * V_29 )
{
struct V_5 * V_47 = F_71 ( V_29 ) ;
F_74 ( V_47 -> line ) ;
return 0 ;
}
static int F_75 ( struct V_45 * V_29 )
{
struct V_5 * V_47 = F_71 ( V_29 ) ;
if ( ! F_25 ( V_47 -> V_35 ) )
F_26 ( V_47 -> V_35 ) ;
if ( ! F_25 ( V_47 -> V_107 ) )
F_26 ( V_47 -> V_107 ) ;
return 0 ;
}
static int F_76 ( struct V_45 * V_29 )
{
struct V_5 * V_47 = F_71 ( V_29 ) ;
if ( ! F_25 ( V_47 -> V_107 ) )
F_29 ( V_47 -> V_107 ) ;
if ( ! F_25 ( V_47 -> V_35 ) )
F_29 ( V_47 -> V_35 ) ;
return 0 ;
}
