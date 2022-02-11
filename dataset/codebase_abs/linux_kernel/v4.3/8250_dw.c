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
if ( V_32 < 115200 )
V_32 = 115200 ;
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
static void F_32 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_12 -> V_26 ;
T_1 V_45 = F_16 ( V_2 -> V_15 + V_46 ) ;
if ( ! V_45 )
return;
F_33 ( V_2 -> V_29 , L_1 ,
( V_45 >> 24 ) & 0xff , ( V_45 >> 16 ) & 0xff , ( V_45 >> 8 ) & 0xff ) ;
V_45 = F_16 ( V_2 -> V_15 + V_47 ) ;
if ( ! V_45 )
return;
if ( V_45 & V_48 ) {
V_2 -> type = V_49 ;
V_2 -> V_50 |= V_51 ;
V_2 -> V_52 = F_34 ( V_45 ) ;
V_12 -> V_53 = V_2 -> V_52 ;
V_12 -> V_54 = V_55 ;
}
if ( V_45 & V_56 )
V_12 -> V_54 |= V_57 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_5 * V_58 )
{
struct V_59 * V_60 = V_2 -> V_29 -> V_61 ;
struct V_11 * V_12 = F_3 ( V_2 ) ;
T_1 V_62 ;
bool V_63 = true ;
int V_64 ;
#ifdef F_36
if ( F_37 ( V_60 , L_2 ) ) {
V_2 -> V_13 = F_9 ;
V_2 -> V_65 = F_11 ;
V_2 -> V_50 = V_66 | V_67 | V_51 ;
V_2 -> type = V_68 ;
V_58 -> V_25 = 0x27 ;
V_63 = false ;
} else
#endif
if ( ! F_38 ( V_60 , L_3 , & V_62 ) ) {
switch ( V_62 ) {
case 1 :
break;
case 4 :
V_2 -> V_69 = V_70 ;
V_2 -> V_13 = F_15 ;
V_2 -> V_65 = F_13 ;
break;
default:
F_39 ( V_2 -> V_29 , L_4 , V_62 ) ;
return - V_71 ;
}
}
if ( V_63 )
F_32 ( V_12 ) ;
if ( V_2 -> V_52 ) {
V_12 -> V_72 = & V_58 -> V_72 ;
V_12 -> V_72 -> V_73 . V_74 = V_2 -> V_52 / 4 ;
V_12 -> V_72 -> V_75 . V_76 = V_2 -> V_52 / 4 ;
}
if ( ! F_38 ( V_60 , L_5 , & V_62 ) )
V_2 -> V_16 = V_62 ;
V_64 = F_40 ( V_60 , L_6 ) ;
if ( V_64 >= 0 )
V_2 -> line = V_64 ;
if ( F_41 ( V_60 , L_7 ) ) {
V_58 -> V_9 |= V_77 ;
V_58 -> V_10 |= V_78 ;
}
if ( F_41 ( V_60 , L_8 ) ) {
V_58 -> V_9 |= V_79 ;
V_58 -> V_10 |= V_80 ;
}
if ( F_41 ( V_60 , L_9 ) ) {
V_58 -> V_9 |= V_81 ;
V_58 -> V_10 |= V_82 ;
}
if ( F_41 ( V_60 , L_10 ) ) {
V_58 -> V_10 |= V_83 ;
V_58 -> V_10 |= V_84 ;
}
return 0 ;
}
static bool F_42 ( struct V_42 * V_43 , void * V_44 )
{
struct V_85 * V_29 = V_44 ;
if ( V_29 != V_43 -> V_85 -> V_29 -> V_86 )
return false ;
return true ;
}
static int F_43 ( struct V_11 * V_12 ,
struct V_5 * V_58 )
{
struct V_1 * V_2 = & V_12 -> V_26 ;
F_32 ( V_12 ) ;
V_2 -> V_69 = V_70 ;
V_2 -> V_13 = F_15 ;
V_2 -> V_65 = F_13 ;
V_2 -> V_16 = 2 ;
if ( F_44 ( F_45 ( V_12 -> V_26 . V_29 ) ,
V_87 , L_11 ) ) {
V_58 -> V_72 . V_88 = V_12 -> V_26 . V_29 -> V_86 ;
V_58 -> V_72 . V_89 = V_12 -> V_26 . V_29 -> V_86 ;
V_58 -> V_72 . V_90 = F_42 ;
}
V_12 -> V_72 = & V_58 -> V_72 ;
V_12 -> V_72 -> V_73 . V_74 = V_2 -> V_52 / 4 ;
V_12 -> V_72 -> V_75 . V_76 = V_2 -> V_52 / 4 ;
V_12 -> V_26 . V_91 = F_23 ;
return 0 ;
}
static int F_46 ( struct V_92 * V_93 )
{
struct V_11 V_94 = {} ;
struct V_95 * V_96 = F_47 ( V_93 , V_87 , 0 ) ;
int V_97 = F_48 ( V_93 , 0 ) ;
struct V_5 * V_58 ;
int V_98 ;
if ( ! V_96 ) {
F_39 ( & V_93 -> V_29 , L_12 ) ;
return - V_71 ;
}
if ( V_97 < 0 ) {
if ( V_97 != - V_99 )
F_39 ( & V_93 -> V_29 , L_13 ) ;
return V_97 ;
}
F_49 ( & V_94 . V_26 . V_100 ) ;
V_94 . V_26 . V_101 = V_96 -> V_102 ;
V_94 . V_26 . V_97 = V_97 ;
V_94 . V_26 . V_103 = F_17 ;
V_94 . V_26 . V_104 = F_19 ;
V_94 . V_26 . type = V_105 ;
V_94 . V_26 . V_50 = V_67 | V_106 | V_107 ;
V_94 . V_26 . V_29 = & V_93 -> V_29 ;
V_94 . V_26 . V_15 = F_50 ( & V_93 -> V_29 , V_96 -> V_102 ,
F_51 ( V_96 ) ) ;
if ( ! V_94 . V_26 . V_15 )
return - V_108 ;
V_58 = F_52 ( & V_93 -> V_29 , sizeof( * V_58 ) , V_109 ) ;
if ( ! V_58 )
return - V_108 ;
V_58 -> V_25 = V_110 ;
F_53 ( & V_93 -> V_29 , L_14 ,
& V_94 . V_26 . V_37 ) ;
V_58 -> V_35 = F_54 ( & V_93 -> V_29 , L_15 ) ;
if ( F_25 ( V_58 -> V_35 ) && F_55 ( V_58 -> V_35 ) != - V_99 )
V_58 -> V_35 = F_54 ( & V_93 -> V_29 , NULL ) ;
if ( F_25 ( V_58 -> V_35 ) && F_55 ( V_58 -> V_35 ) == - V_99 )
return - V_99 ;
if ( ! F_56 ( V_58 -> V_35 ) ) {
V_98 = F_29 ( V_58 -> V_35 ) ;
if ( V_98 )
F_57 ( & V_93 -> V_29 , L_16 ,
V_98 ) ;
else
V_94 . V_26 . V_37 = F_58 ( V_58 -> V_35 ) ;
}
if ( ! V_94 . V_26 . V_37 ) {
F_39 ( & V_93 -> V_29 , L_17 ) ;
return - V_71 ;
}
V_58 -> V_111 = F_54 ( & V_93 -> V_29 , L_18 ) ;
if ( F_25 ( V_58 -> V_35 ) && F_55 ( V_58 -> V_35 ) == - V_99 ) {
V_98 = - V_99 ;
goto V_112;
}
if ( ! F_25 ( V_58 -> V_111 ) ) {
V_98 = F_29 ( V_58 -> V_111 ) ;
if ( V_98 ) {
F_39 ( & V_93 -> V_29 , L_19 ) ;
goto V_112;
}
}
V_58 -> V_113 = F_59 ( & V_93 -> V_29 , NULL ) ;
if ( F_25 ( V_58 -> V_113 ) && F_55 ( V_58 -> V_113 ) == - V_99 ) {
V_98 = - V_99 ;
goto V_114;
}
if ( ! F_25 ( V_58 -> V_113 ) )
F_60 ( V_58 -> V_113 ) ;
V_58 -> V_72 . V_88 = V_58 ;
V_58 -> V_72 . V_89 = V_58 ;
V_58 -> V_72 . V_90 = F_31 ;
V_94 . V_26 . V_69 = V_115 ;
V_94 . V_26 . V_13 = F_7 ;
V_94 . V_26 . V_65 = F_5 ;
V_94 . V_26 . V_7 = V_58 ;
if ( V_93 -> V_29 . V_61 ) {
V_98 = F_35 ( & V_94 . V_26 , V_58 ) ;
if ( V_98 )
goto V_116;
} else if ( F_61 ( & V_93 -> V_29 ) ) {
V_98 = F_43 ( & V_94 , V_58 ) ;
if ( V_98 )
goto V_116;
} else {
V_98 = - V_117 ;
goto V_116;
}
V_58 -> line = F_62 ( & V_94 ) ;
if ( V_58 -> line < 0 ) {
V_98 = V_58 -> line ;
goto V_116;
}
F_63 ( V_93 , V_58 ) ;
F_64 ( & V_93 -> V_29 ) ;
F_65 ( & V_93 -> V_29 ) ;
return 0 ;
V_116:
if ( ! F_25 ( V_58 -> V_113 ) )
F_66 ( V_58 -> V_113 ) ;
V_114:
if ( ! F_25 ( V_58 -> V_111 ) )
F_26 ( V_58 -> V_111 ) ;
V_112:
if ( ! F_25 ( V_58 -> V_35 ) )
F_26 ( V_58 -> V_35 ) ;
return V_98 ;
}
static int F_67 ( struct V_92 * V_93 )
{
struct V_5 * V_58 = F_68 ( V_93 ) ;
F_20 ( & V_93 -> V_29 ) ;
F_69 ( V_58 -> line ) ;
if ( ! F_25 ( V_58 -> V_113 ) )
F_66 ( V_58 -> V_113 ) ;
if ( ! F_25 ( V_58 -> V_111 ) )
F_26 ( V_58 -> V_111 ) ;
if ( ! F_25 ( V_58 -> V_35 ) )
F_26 ( V_58 -> V_35 ) ;
F_70 ( & V_93 -> V_29 ) ;
F_71 ( & V_93 -> V_29 ) ;
return 0 ;
}
static int F_72 ( struct V_85 * V_29 )
{
struct V_5 * V_58 = F_73 ( V_29 ) ;
F_74 ( V_58 -> line ) ;
return 0 ;
}
static int F_75 ( struct V_85 * V_29 )
{
struct V_5 * V_58 = F_73 ( V_29 ) ;
F_76 ( V_58 -> line ) ;
return 0 ;
}
static int F_77 ( struct V_85 * V_29 )
{
struct V_5 * V_58 = F_73 ( V_29 ) ;
if ( ! F_25 ( V_58 -> V_35 ) )
F_26 ( V_58 -> V_35 ) ;
if ( ! F_25 ( V_58 -> V_111 ) )
F_26 ( V_58 -> V_111 ) ;
return 0 ;
}
static int F_78 ( struct V_85 * V_29 )
{
struct V_5 * V_58 = F_73 ( V_29 ) ;
if ( ! F_25 ( V_58 -> V_111 ) )
F_29 ( V_58 -> V_111 ) ;
if ( ! F_25 ( V_58 -> V_35 ) )
F_29 ( V_58 -> V_35 ) ;
return 0 ;
}
