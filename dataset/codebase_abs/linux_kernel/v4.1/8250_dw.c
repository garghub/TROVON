static inline int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_3 == V_8 && V_6 -> V_9 & V_10 ) {
V_4 |= V_11 ;
V_4 &= ~ V_12 ;
}
if ( V_3 == V_8 ) {
V_4 |= V_6 -> V_13 ;
V_4 &= ~ V_6 -> V_14 ;
}
return V_4 ;
}
static void F_2 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_3 ( V_2 ) ;
F_4 ( V_16 ) ;
( void ) V_2 -> V_17 ( V_2 , V_18 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_3 == V_19 )
V_6 -> V_9 = V_4 ;
F_6 ( V_4 , V_2 -> V_20 + ( V_3 << V_2 -> V_21 ) ) ;
if ( V_3 == V_22 ) {
int V_23 = 1000 ;
while ( V_23 -- ) {
unsigned int V_24 = V_2 -> V_17 ( V_2 , V_22 ) ;
if ( ( V_4 & ~ V_25 ) == ( V_24 & ~ V_25 ) )
return;
F_2 ( V_2 ) ;
F_6 ( V_4 , V_2 -> V_20 + ( V_22 << V_2 -> V_21 ) ) ;
}
}
}
static unsigned int F_7 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 = F_8 ( V_2 -> V_20 + ( V_3 << V_2 -> V_21 ) ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static unsigned int F_9 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 ;
V_4 = ( V_26 ) F_10 ( V_2 -> V_20 + ( V_3 << V_2 -> V_21 ) ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_3 == V_19 )
V_6 -> V_9 = V_4 ;
V_4 &= 0xff ;
F_12 ( V_4 , V_2 -> V_20 + ( V_3 << V_2 -> V_21 ) ) ;
F_10 ( V_2 -> V_20 + ( V_22 << V_2 -> V_21 ) ) ;
if ( V_3 == V_22 ) {
int V_23 = 1000 ;
while ( V_23 -- ) {
unsigned int V_24 = V_2 -> V_17 ( V_2 , V_22 ) ;
if ( ( V_4 & ~ V_25 ) == ( V_24 & ~ V_25 ) )
return;
F_2 ( V_2 ) ;
F_12 ( V_4 & 0xff ,
V_2 -> V_20 + ( V_22 << V_2 -> V_21 ) ) ;
}
}
}
static void F_13 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_3 == V_19 )
V_6 -> V_9 = V_4 ;
F_14 ( V_4 , V_2 -> V_20 + ( V_3 << V_2 -> V_21 ) ) ;
if ( V_3 == V_22 ) {
int V_23 = 1000 ;
while ( V_23 -- ) {
unsigned int V_24 = V_2 -> V_17 ( V_2 , V_22 ) ;
if ( ( V_4 & ~ V_25 ) == ( V_24 & ~ V_25 ) )
return;
F_2 ( V_2 ) ;
F_14 ( V_4 , V_2 -> V_20 + ( V_22 << V_2 -> V_21 ) ) ;
}
}
}
static unsigned int F_15 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 = F_16 ( V_2 -> V_20 + ( V_3 << V_2 -> V_21 ) ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_27 = V_2 -> V_17 ( V_2 , V_28 ) ;
if ( F_18 ( V_2 , V_27 ) ) {
return 1 ;
} else if ( ( V_27 & V_29 ) == V_29 ) {
( void ) V_2 -> V_17 ( V_2 , V_6 -> V_30 ) ;
return 1 ;
}
return 0 ;
}
static void
F_19 ( struct V_1 * V_31 , unsigned int V_32 , unsigned int V_33 )
{
if ( ! V_32 )
F_20 ( V_31 -> V_34 ) ;
F_21 ( V_31 , V_32 , V_33 ) ;
if ( V_32 )
F_22 ( V_31 -> V_34 ) ;
}
static void F_23 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_35 * V_33 )
{
unsigned int V_37 = F_24 ( V_36 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_38 ;
int V_39 ;
if ( F_25 ( V_6 -> V_40 ) || ! V_33 )
goto V_41;
if ( V_37 < 115200 )
V_37 = 115200 ;
F_26 ( V_6 -> V_40 ) ;
V_38 = F_27 ( V_6 -> V_40 , V_37 * 16 ) ;
V_39 = F_28 ( V_6 -> V_40 , V_38 ) ;
F_29 ( V_6 -> V_40 ) ;
if ( ! V_39 )
V_2 -> V_42 = V_38 ;
V_41:
F_30 ( V_2 , V_36 , V_33 ) ;
}
static bool F_31 ( struct V_43 * V_44 , void * V_45 )
{
return false ;
}
static void F_32 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = & V_16 -> V_31 ;
T_1 V_46 = F_16 ( V_2 -> V_20 + V_47 ) ;
if ( ! V_46 )
return;
F_33 ( V_2 -> V_34 , L_1 ,
( V_46 >> 24 ) & 0xff , ( V_46 >> 16 ) & 0xff , ( V_46 >> 8 ) & 0xff ) ;
V_46 = F_16 ( V_2 -> V_20 + V_48 ) ;
if ( ! V_46 )
return;
if ( V_46 & V_49 ) {
V_2 -> type = V_50 ;
V_2 -> V_51 |= V_52 ;
V_2 -> V_53 = F_34 ( V_46 ) ;
V_16 -> V_54 = V_2 -> V_53 ;
V_16 -> V_55 = V_56 ;
}
if ( V_46 & V_57 )
V_16 -> V_55 |= V_58 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_5 * V_59 )
{
struct V_60 * V_61 = V_2 -> V_34 -> V_62 ;
struct V_15 * V_16 = F_3 ( V_2 ) ;
T_1 V_63 ;
bool V_64 = true ;
int V_65 ;
#ifdef F_36
if ( F_37 ( V_61 , L_2 ) ) {
V_2 -> V_17 = F_9 ;
V_2 -> V_66 = F_11 ;
V_2 -> V_51 = V_67 | V_68 | V_52 ;
V_2 -> type = V_69 ;
V_59 -> V_30 = 0x27 ;
V_64 = false ;
} else
#endif
if ( ! F_38 ( V_61 , L_3 , & V_63 ) ) {
switch ( V_63 ) {
case 1 :
break;
case 4 :
V_2 -> V_70 = V_71 ;
V_2 -> V_17 = F_15 ;
V_2 -> V_66 = F_13 ;
break;
default:
F_39 ( V_2 -> V_34 , L_4 , V_63 ) ;
return - V_72 ;
}
}
if ( V_64 )
F_32 ( V_16 ) ;
if ( V_2 -> V_53 ) {
V_16 -> V_73 = & V_59 -> V_73 ;
V_16 -> V_73 -> V_74 . V_75 = V_2 -> V_53 / 4 ;
V_16 -> V_73 -> V_76 . V_77 = V_2 -> V_53 / 4 ;
}
if ( ! F_38 ( V_61 , L_5 , & V_63 ) )
V_2 -> V_21 = V_63 ;
V_65 = F_40 ( V_61 , L_6 ) ;
if ( V_65 >= 0 )
V_2 -> line = V_65 ;
if ( F_41 ( V_61 , L_7 ) ) {
V_59 -> V_13 |= V_78 ;
V_59 -> V_14 |= V_79 ;
}
if ( F_41 ( V_61 , L_8 ) ) {
V_59 -> V_13 |= V_80 ;
V_59 -> V_14 |= V_81 ;
}
if ( F_41 ( V_61 , L_9 ) ) {
V_59 -> V_13 |= V_11 ;
V_59 -> V_14 |= V_12 ;
}
if ( F_41 ( V_61 , L_10 ) ) {
V_59 -> V_14 |= V_82 ;
V_59 -> V_14 |= V_83 ;
}
return 0 ;
}
static int F_42 ( struct V_15 * V_16 ,
struct V_5 * V_59 )
{
struct V_1 * V_2 = & V_16 -> V_31 ;
F_32 ( V_16 ) ;
V_2 -> V_70 = V_71 ;
V_2 -> V_17 = F_15 ;
V_2 -> V_66 = F_13 ;
V_2 -> V_21 = 2 ;
V_16 -> V_73 = & V_59 -> V_73 ;
V_16 -> V_73 -> V_74 . V_75 = V_2 -> V_53 / 4 ;
V_16 -> V_73 -> V_76 . V_77 = V_2 -> V_53 / 4 ;
V_16 -> V_31 . V_84 = F_23 ;
return 0 ;
}
static int F_43 ( struct V_85 * V_86 )
{
struct V_15 V_87 = {} ;
struct V_88 * V_89 = F_44 ( V_86 , V_90 , 0 ) ;
int V_91 = F_45 ( V_86 , 0 ) ;
struct V_5 * V_59 ;
int V_92 ;
if ( ! V_89 ) {
F_39 ( & V_86 -> V_34 , L_11 ) ;
return - V_72 ;
}
if ( V_91 < 0 ) {
if ( V_91 != - V_93 )
F_39 ( & V_86 -> V_34 , L_12 ) ;
return V_91 ;
}
F_46 ( & V_87 . V_31 . V_94 ) ;
V_87 . V_31 . V_95 = V_89 -> V_96 ;
V_87 . V_31 . V_91 = V_91 ;
V_87 . V_31 . V_97 = F_17 ;
V_87 . V_31 . V_98 = F_19 ;
V_87 . V_31 . type = V_99 ;
V_87 . V_31 . V_51 = V_68 | V_100 | V_101 ;
V_87 . V_31 . V_34 = & V_86 -> V_34 ;
V_87 . V_31 . V_20 = F_47 ( & V_86 -> V_34 , V_89 -> V_96 ,
F_48 ( V_89 ) ) ;
if ( ! V_87 . V_31 . V_20 )
return - V_102 ;
V_59 = F_49 ( & V_86 -> V_34 , sizeof( * V_59 ) , V_103 ) ;
if ( ! V_59 )
return - V_102 ;
V_59 -> V_30 = V_104 ;
F_50 ( & V_86 -> V_34 , L_13 ,
& V_87 . V_31 . V_42 ) ;
V_59 -> V_40 = F_51 ( & V_86 -> V_34 , L_14 ) ;
if ( F_25 ( V_59 -> V_40 ) && F_52 ( V_59 -> V_40 ) != - V_93 )
V_59 -> V_40 = F_51 ( & V_86 -> V_34 , NULL ) ;
if ( F_25 ( V_59 -> V_40 ) && F_52 ( V_59 -> V_40 ) == - V_93 )
return - V_93 ;
if ( ! F_53 ( V_59 -> V_40 ) ) {
V_92 = F_29 ( V_59 -> V_40 ) ;
if ( V_92 )
F_54 ( & V_86 -> V_34 , L_15 ,
V_92 ) ;
else
V_87 . V_31 . V_42 = F_55 ( V_59 -> V_40 ) ;
}
if ( ! V_87 . V_31 . V_42 ) {
F_39 ( & V_86 -> V_34 , L_16 ) ;
return - V_72 ;
}
V_59 -> V_105 = F_51 ( & V_86 -> V_34 , L_17 ) ;
if ( F_25 ( V_59 -> V_40 ) && F_52 ( V_59 -> V_40 ) == - V_93 ) {
V_92 = - V_93 ;
goto V_106;
}
if ( ! F_25 ( V_59 -> V_105 ) ) {
V_92 = F_29 ( V_59 -> V_105 ) ;
if ( V_92 ) {
F_39 ( & V_86 -> V_34 , L_18 ) ;
goto V_106;
}
}
V_59 -> V_107 = F_56 ( & V_86 -> V_34 , NULL ) ;
if ( F_25 ( V_59 -> V_107 ) && F_52 ( V_59 -> V_107 ) == - V_93 ) {
V_92 = - V_93 ;
goto V_108;
}
if ( ! F_25 ( V_59 -> V_107 ) )
F_57 ( V_59 -> V_107 ) ;
V_59 -> V_73 . V_109 = V_59 ;
V_59 -> V_73 . V_110 = V_59 ;
V_59 -> V_73 . V_111 = F_31 ;
V_87 . V_31 . V_70 = V_112 ;
V_87 . V_31 . V_17 = F_7 ;
V_87 . V_31 . V_66 = F_5 ;
V_87 . V_31 . V_7 = V_59 ;
if ( V_86 -> V_34 . V_62 ) {
V_92 = F_35 ( & V_87 . V_31 , V_59 ) ;
if ( V_92 )
goto V_113;
} else if ( F_58 ( & V_86 -> V_34 ) ) {
V_92 = F_42 ( & V_87 , V_59 ) ;
if ( V_92 )
goto V_113;
} else {
V_92 = - V_114 ;
goto V_113;
}
V_59 -> line = F_59 ( & V_87 ) ;
if ( V_59 -> line < 0 ) {
V_92 = V_59 -> line ;
goto V_113;
}
F_60 ( V_86 , V_59 ) ;
F_61 ( & V_86 -> V_34 ) ;
F_62 ( & V_86 -> V_34 ) ;
return 0 ;
V_113:
if ( ! F_25 ( V_59 -> V_107 ) )
F_63 ( V_59 -> V_107 ) ;
V_108:
if ( ! F_25 ( V_59 -> V_105 ) )
F_26 ( V_59 -> V_105 ) ;
V_106:
if ( ! F_25 ( V_59 -> V_40 ) )
F_26 ( V_59 -> V_40 ) ;
return V_92 ;
}
static int F_64 ( struct V_85 * V_86 )
{
struct V_5 * V_59 = F_65 ( V_86 ) ;
F_20 ( & V_86 -> V_34 ) ;
F_66 ( V_59 -> line ) ;
if ( ! F_25 ( V_59 -> V_107 ) )
F_63 ( V_59 -> V_107 ) ;
if ( ! F_25 ( V_59 -> V_105 ) )
F_26 ( V_59 -> V_105 ) ;
if ( ! F_25 ( V_59 -> V_40 ) )
F_26 ( V_59 -> V_40 ) ;
F_67 ( & V_86 -> V_34 ) ;
F_68 ( & V_86 -> V_34 ) ;
return 0 ;
}
static int F_69 ( struct V_115 * V_34 )
{
struct V_5 * V_59 = F_70 ( V_34 ) ;
F_71 ( V_59 -> line ) ;
return 0 ;
}
static int F_72 ( struct V_115 * V_34 )
{
struct V_5 * V_59 = F_70 ( V_34 ) ;
F_73 ( V_59 -> line ) ;
return 0 ;
}
static int F_74 ( struct V_115 * V_34 )
{
struct V_5 * V_59 = F_70 ( V_34 ) ;
if ( ! F_25 ( V_59 -> V_40 ) )
F_26 ( V_59 -> V_40 ) ;
if ( ! F_25 ( V_59 -> V_105 ) )
F_26 ( V_59 -> V_105 ) ;
return 0 ;
}
static int F_75 ( struct V_115 * V_34 )
{
struct V_5 * V_59 = F_70 ( V_34 ) ;
if ( ! F_25 ( V_59 -> V_105 ) )
F_29 ( V_59 -> V_105 ) ;
if ( ! F_25 ( V_59 -> V_40 ) )
F_29 ( V_59 -> V_40 ) ;
return 0 ;
}
