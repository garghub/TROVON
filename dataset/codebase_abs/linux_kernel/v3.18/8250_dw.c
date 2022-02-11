static inline int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_3 == V_8 && V_6 -> V_9 & V_10 ) {
V_4 |= V_11 ;
V_4 &= ~ V_12 ;
}
return V_4 ;
}
static void F_2 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
F_4 ( V_14 ) ;
( void ) V_2 -> V_15 ( V_2 , V_16 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_3 == V_17 )
V_6 -> V_9 = V_4 ;
F_6 ( V_4 , V_2 -> V_18 + ( V_3 << V_2 -> V_19 ) ) ;
if ( V_3 == V_20 ) {
int V_21 = 1000 ;
while ( V_21 -- ) {
unsigned int V_22 = V_2 -> V_15 ( V_2 , V_20 ) ;
if ( ( V_4 & ~ V_23 ) == ( V_22 & ~ V_23 ) )
return;
F_2 ( V_2 ) ;
F_6 ( V_4 , V_2 -> V_18 + ( V_20 << V_2 -> V_19 ) ) ;
}
F_7 ( V_2 -> V_24 , L_1 , V_4 ) ;
}
}
static unsigned int F_8 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 = F_9 ( V_2 -> V_18 + ( V_3 << V_2 -> V_19 ) ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
F_5 ( V_2 , V_3 , V_4 ) ;
F_8 ( V_2 , V_20 ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_3 == V_17 )
V_6 -> V_9 = V_4 ;
F_12 ( V_4 , V_2 -> V_18 + ( V_3 << V_2 -> V_19 ) ) ;
if ( V_3 == V_20 ) {
int V_21 = 1000 ;
while ( V_21 -- ) {
unsigned int V_22 = V_2 -> V_15 ( V_2 , V_20 ) ;
if ( ( V_4 & ~ V_23 ) == ( V_22 & ~ V_23 ) )
return;
F_2 ( V_2 ) ;
F_12 ( V_4 , V_2 -> V_18 + ( V_20 << V_2 -> V_19 ) ) ;
}
F_7 ( V_2 -> V_24 , L_1 , V_4 ) ;
}
}
static unsigned int F_13 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 = F_14 ( V_2 -> V_18 + ( V_3 << V_2 -> V_19 ) ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_25 = V_2 -> V_15 ( V_2 , V_26 ) ;
if ( F_16 ( V_2 , V_25 ) ) {
return 1 ;
} else if ( ( V_25 & V_27 ) == V_27 ) {
( void ) V_2 -> V_15 ( V_2 , V_6 -> V_28 ) ;
return 1 ;
}
return 0 ;
}
static void
F_17 ( struct V_1 * V_29 , unsigned int V_30 , unsigned int V_31 )
{
if ( ! V_30 )
F_18 ( V_29 -> V_24 ) ;
F_19 ( V_29 , V_30 , V_31 ) ;
if ( V_30 )
F_20 ( V_29 -> V_24 ) ;
}
static void F_21 ( struct V_1 * V_2 , struct V_32 * V_33 ,
struct V_32 * V_31 )
{
unsigned int V_34 = F_22 ( V_33 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_35 ;
int V_36 ;
if ( F_23 ( V_6 -> V_37 ) || ! V_31 )
goto V_38;
if ( V_34 < 115200 )
V_34 = 115200 ;
F_24 ( V_6 -> V_37 ) ;
V_35 = F_25 ( V_6 -> V_37 , V_34 * 16 ) ;
V_36 = F_26 ( V_6 -> V_37 , V_35 ) ;
F_27 ( V_6 -> V_37 ) ;
if ( ! V_36 )
V_2 -> V_39 = V_35 ;
V_38:
F_28 ( V_2 , V_33 , V_31 ) ;
}
static bool F_29 ( struct V_40 * V_41 , void * V_42 )
{
return false ;
}
static void F_30 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = & V_14 -> V_29 ;
T_1 V_43 = F_14 ( V_2 -> V_18 + V_44 ) ;
if ( ! V_43 )
return;
F_31 ( V_2 -> V_24 , L_2 ,
( V_43 >> 24 ) & 0xff , ( V_43 >> 16 ) & 0xff , ( V_43 >> 8 ) & 0xff ) ;
V_43 = F_14 ( V_2 -> V_18 + V_45 ) ;
if ( ! V_43 )
return;
if ( V_43 & V_46 ) {
V_2 -> type = V_47 ;
V_2 -> V_48 |= V_49 ;
V_2 -> V_50 = F_32 ( V_43 ) ;
V_14 -> V_51 = V_2 -> V_50 ;
V_14 -> V_52 = V_53 ;
}
if ( V_43 & V_54 )
V_14 -> V_52 |= V_55 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_5 * V_56 )
{
struct V_57 * V_58 = V_2 -> V_24 -> V_59 ;
struct V_13 * V_14 = F_3 ( V_2 ) ;
T_1 V_60 ;
bool V_61 = true ;
if ( F_34 ( V_58 , L_3 ) ) {
#ifdef F_35
V_2 -> V_18 += 7 ;
#endif
V_2 -> V_62 = F_10 ;
V_2 -> V_48 = V_63 | V_64 | V_49 ;
V_2 -> type = V_65 ;
V_56 -> V_28 = 0x27 ;
V_61 = false ;
} else if ( ! F_36 ( V_58 , L_4 , & V_60 ) ) {
switch ( V_60 ) {
case 1 :
break;
case 4 :
V_2 -> V_66 = V_67 ;
V_2 -> V_15 = F_13 ;
V_2 -> V_62 = F_11 ;
break;
default:
F_7 ( V_2 -> V_24 , L_5 , V_60 ) ;
return - V_68 ;
}
}
if ( V_61 )
F_30 ( V_14 ) ;
if ( ! F_36 ( V_58 , L_6 , & V_60 ) )
V_2 -> V_19 = V_60 ;
if ( V_2 -> V_39 )
return 0 ;
if ( F_36 ( V_58 , L_7 , & V_60 ) ) {
F_7 ( V_2 -> V_24 , L_8 ) ;
return - V_68 ;
}
V_2 -> V_39 = V_60 ;
return 0 ;
}
static int F_37 ( struct V_13 * V_14 ,
struct V_5 * V_56 )
{
struct V_1 * V_2 = & V_14 -> V_29 ;
F_30 ( V_14 ) ;
V_2 -> V_66 = V_67 ;
V_2 -> V_15 = F_13 ;
V_2 -> V_62 = F_11 ;
V_2 -> V_19 = 2 ;
V_14 -> V_69 = & V_56 -> V_69 ;
V_14 -> V_69 -> V_70 . V_71 = V_2 -> V_50 / 4 ;
V_14 -> V_69 -> V_72 . V_73 = V_2 -> V_50 / 4 ;
V_14 -> V_29 . V_74 = F_21 ;
return 0 ;
}
static int F_38 ( struct V_75 * V_76 )
{
struct V_13 V_77 = {} ;
struct V_78 * V_79 = F_39 ( V_76 , V_80 , 0 ) ;
struct V_78 * V_81 = F_39 ( V_76 , V_82 , 0 ) ;
struct V_5 * V_56 ;
int V_83 ;
if ( ! V_79 || ! V_81 ) {
F_7 ( & V_76 -> V_24 , L_9 ) ;
return - V_68 ;
}
F_40 ( & V_77 . V_29 . V_84 ) ;
V_77 . V_29 . V_85 = V_79 -> V_86 ;
V_77 . V_29 . V_81 = V_81 -> V_86 ;
V_77 . V_29 . V_87 = F_15 ;
V_77 . V_29 . V_88 = F_17 ;
V_77 . V_29 . type = V_89 ;
V_77 . V_29 . V_48 = V_64 | V_90 | V_91 ;
V_77 . V_29 . V_24 = & V_76 -> V_24 ;
V_77 . V_29 . V_18 = F_41 ( & V_76 -> V_24 , V_79 -> V_86 ,
F_42 ( V_79 ) ) ;
if ( ! V_77 . V_29 . V_18 )
return - V_92 ;
V_56 = F_43 ( & V_76 -> V_24 , sizeof( * V_56 ) , V_93 ) ;
if ( ! V_56 )
return - V_92 ;
V_56 -> V_28 = V_94 ;
V_56 -> V_37 = F_44 ( & V_76 -> V_24 , L_10 ) ;
if ( F_23 ( V_56 -> V_37 ) && F_45 ( V_56 -> V_37 ) != - V_95 )
V_56 -> V_37 = F_44 ( & V_76 -> V_24 , NULL ) ;
if ( F_23 ( V_56 -> V_37 ) && F_45 ( V_56 -> V_37 ) == - V_95 )
return - V_95 ;
if ( ! F_23 ( V_56 -> V_37 ) ) {
V_83 = F_27 ( V_56 -> V_37 ) ;
if ( V_83 )
F_46 ( & V_76 -> V_24 , L_11 ,
V_83 ) ;
else
V_77 . V_29 . V_39 = F_47 ( V_56 -> V_37 ) ;
}
V_56 -> V_96 = F_44 ( & V_76 -> V_24 , L_12 ) ;
if ( F_23 ( V_56 -> V_37 ) && F_45 ( V_56 -> V_37 ) == - V_95 ) {
V_83 = - V_95 ;
goto V_97;
}
if ( ! F_23 ( V_56 -> V_96 ) ) {
V_83 = F_27 ( V_56 -> V_96 ) ;
if ( V_83 ) {
F_7 ( & V_76 -> V_24 , L_13 ) ;
goto V_97;
}
}
V_56 -> V_98 = F_48 ( & V_76 -> V_24 , NULL ) ;
if ( F_23 ( V_56 -> V_98 ) && F_45 ( V_56 -> V_98 ) == - V_95 ) {
V_83 = - V_95 ;
goto V_99;
}
if ( ! F_23 ( V_56 -> V_98 ) )
F_49 ( V_56 -> V_98 ) ;
V_56 -> V_69 . V_100 = V_56 ;
V_56 -> V_69 . V_101 = V_56 ;
V_56 -> V_69 . V_102 = F_29 ;
V_77 . V_29 . V_66 = V_103 ;
V_77 . V_29 . V_15 = F_8 ;
V_77 . V_29 . V_62 = F_5 ;
V_77 . V_29 . V_7 = V_56 ;
if ( V_76 -> V_24 . V_59 ) {
V_83 = F_33 ( & V_77 . V_29 , V_56 ) ;
if ( V_83 )
goto V_104;
} else if ( F_50 ( & V_76 -> V_24 ) ) {
V_83 = F_37 ( & V_77 , V_56 ) ;
if ( V_83 )
goto V_104;
} else {
V_83 = - V_105 ;
goto V_104;
}
V_56 -> line = F_51 ( & V_77 ) ;
if ( V_56 -> line < 0 ) {
V_83 = V_56 -> line ;
goto V_104;
}
F_52 ( V_76 , V_56 ) ;
F_53 ( & V_76 -> V_24 ) ;
F_54 ( & V_76 -> V_24 ) ;
return 0 ;
V_104:
if ( ! F_23 ( V_56 -> V_98 ) )
F_55 ( V_56 -> V_98 ) ;
V_99:
if ( ! F_23 ( V_56 -> V_96 ) )
F_24 ( V_56 -> V_96 ) ;
V_97:
if ( ! F_23 ( V_56 -> V_37 ) )
F_24 ( V_56 -> V_37 ) ;
return V_83 ;
}
static int F_56 ( struct V_75 * V_76 )
{
struct V_5 * V_56 = F_57 ( V_76 ) ;
F_18 ( & V_76 -> V_24 ) ;
F_58 ( V_56 -> line ) ;
if ( ! F_23 ( V_56 -> V_98 ) )
F_55 ( V_56 -> V_98 ) ;
if ( ! F_23 ( V_56 -> V_96 ) )
F_24 ( V_56 -> V_96 ) ;
if ( ! F_23 ( V_56 -> V_37 ) )
F_24 ( V_56 -> V_37 ) ;
F_59 ( & V_76 -> V_24 ) ;
F_60 ( & V_76 -> V_24 ) ;
return 0 ;
}
static int F_61 ( struct V_106 * V_24 )
{
struct V_5 * V_56 = F_62 ( V_24 ) ;
F_63 ( V_56 -> line ) ;
return 0 ;
}
static int F_64 ( struct V_106 * V_24 )
{
struct V_5 * V_56 = F_62 ( V_24 ) ;
F_65 ( V_56 -> line ) ;
return 0 ;
}
static int F_66 ( struct V_106 * V_24 )
{
struct V_5 * V_56 = F_62 ( V_24 ) ;
if ( ! F_23 ( V_56 -> V_37 ) )
F_24 ( V_56 -> V_37 ) ;
if ( ! F_23 ( V_56 -> V_96 ) )
F_24 ( V_56 -> V_96 ) ;
return 0 ;
}
static int F_67 ( struct V_106 * V_24 )
{
struct V_5 * V_56 = F_62 ( V_24 ) ;
if ( ! F_23 ( V_56 -> V_96 ) )
F_27 ( V_56 -> V_96 ) ;
if ( ! F_23 ( V_56 -> V_37 ) )
F_27 ( V_56 -> V_37 ) ;
return 0 ;
}
