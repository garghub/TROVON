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
static unsigned int F_10 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 ;
V_4 = ( V_25 ) F_11 ( V_2 -> V_18 + ( V_3 << V_2 -> V_19 ) ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static void F_12 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_3 == V_17 )
V_6 -> V_9 = V_4 ;
V_4 &= 0xff ;
F_13 ( V_4 , V_2 -> V_18 + ( V_3 << V_2 -> V_19 ) ) ;
F_11 ( V_2 -> V_18 + ( V_20 << V_2 -> V_19 ) ) ;
if ( V_3 == V_20 ) {
int V_21 = 1000 ;
while ( V_21 -- ) {
unsigned int V_22 = V_2 -> V_15 ( V_2 , V_20 ) ;
if ( ( V_4 & ~ V_23 ) == ( V_22 & ~ V_23 ) )
return;
F_2 ( V_2 ) ;
F_13 ( V_4 & 0xff ,
V_2 -> V_18 + ( V_20 << V_2 -> V_19 ) ) ;
}
F_7 ( V_2 -> V_24 , L_1 , V_4 ) ;
}
}
static void F_14 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_3 == V_17 )
V_6 -> V_9 = V_4 ;
F_15 ( V_4 , V_2 -> V_18 + ( V_3 << V_2 -> V_19 ) ) ;
if ( V_3 == V_20 ) {
int V_21 = 1000 ;
while ( V_21 -- ) {
unsigned int V_22 = V_2 -> V_15 ( V_2 , V_20 ) ;
if ( ( V_4 & ~ V_23 ) == ( V_22 & ~ V_23 ) )
return;
F_2 ( V_2 ) ;
F_15 ( V_4 , V_2 -> V_18 + ( V_20 << V_2 -> V_19 ) ) ;
}
F_7 ( V_2 -> V_24 , L_1 , V_4 ) ;
}
}
static unsigned int F_16 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 = F_17 ( V_2 -> V_18 + ( V_3 << V_2 -> V_19 ) ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_26 = V_2 -> V_15 ( V_2 , V_27 ) ;
if ( F_19 ( V_2 , V_26 ) ) {
return 1 ;
} else if ( ( V_26 & V_28 ) == V_28 ) {
( void ) V_2 -> V_15 ( V_2 , V_6 -> V_29 ) ;
return 1 ;
}
return 0 ;
}
static void
F_20 ( struct V_1 * V_30 , unsigned int V_31 , unsigned int V_32 )
{
if ( ! V_31 )
F_21 ( V_30 -> V_24 ) ;
F_22 ( V_30 , V_31 , V_32 ) ;
if ( V_31 )
F_23 ( V_30 -> V_24 ) ;
}
static void F_24 ( struct V_1 * V_2 , struct V_33 * V_34 ,
struct V_33 * V_32 )
{
unsigned int V_35 = F_25 ( V_34 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_36 ;
int V_37 ;
if ( F_26 ( V_6 -> V_38 ) || ! V_32 )
goto V_39;
if ( V_35 < 115200 )
V_35 = 115200 ;
F_27 ( V_6 -> V_38 ) ;
V_36 = F_28 ( V_6 -> V_38 , V_35 * 16 ) ;
V_37 = F_29 ( V_6 -> V_38 , V_36 ) ;
F_30 ( V_6 -> V_38 ) ;
if ( ! V_37 )
V_2 -> V_40 = V_36 ;
V_39:
F_31 ( V_2 , V_34 , V_32 ) ;
}
static bool F_32 ( struct V_41 * V_42 , void * V_43 )
{
return false ;
}
static void F_33 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = & V_14 -> V_30 ;
T_1 V_44 = F_17 ( V_2 -> V_18 + V_45 ) ;
if ( ! V_44 )
return;
F_34 ( V_2 -> V_24 , L_2 ,
( V_44 >> 24 ) & 0xff , ( V_44 >> 16 ) & 0xff , ( V_44 >> 8 ) & 0xff ) ;
V_44 = F_17 ( V_2 -> V_18 + V_46 ) ;
if ( ! V_44 )
return;
if ( V_44 & V_47 ) {
V_2 -> type = V_48 ;
V_2 -> V_49 |= V_50 ;
V_2 -> V_51 = F_35 ( V_44 ) ;
V_14 -> V_52 = V_2 -> V_51 ;
V_14 -> V_53 = V_54 ;
}
if ( V_44 & V_55 )
V_14 -> V_53 |= V_56 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_5 * V_57 )
{
struct V_58 * V_59 = V_2 -> V_24 -> V_60 ;
struct V_13 * V_14 = F_3 ( V_2 ) ;
T_1 V_61 ;
bool V_62 = true ;
int V_63 ;
#ifdef F_37
if ( F_38 ( V_59 , L_3 ) ) {
V_2 -> V_15 = F_10 ;
V_2 -> V_64 = F_12 ;
V_2 -> V_49 = V_65 | V_66 | V_50 ;
V_2 -> type = V_67 ;
V_57 -> V_29 = 0x27 ;
V_62 = false ;
} else
#endif
if ( ! F_39 ( V_59 , L_4 , & V_61 ) ) {
switch ( V_61 ) {
case 1 :
break;
case 4 :
V_2 -> V_68 = V_69 ;
V_2 -> V_15 = F_16 ;
V_2 -> V_64 = F_14 ;
break;
default:
F_7 ( V_2 -> V_24 , L_5 , V_61 ) ;
return - V_70 ;
}
}
if ( V_62 )
F_33 ( V_14 ) ;
if ( V_2 -> V_51 ) {
V_14 -> V_71 = & V_57 -> V_71 ;
V_14 -> V_71 -> V_72 . V_73 = V_2 -> V_51 / 4 ;
V_14 -> V_71 -> V_74 . V_75 = V_2 -> V_51 / 4 ;
}
if ( ! F_39 ( V_59 , L_6 , & V_61 ) )
V_2 -> V_19 = V_61 ;
V_63 = F_40 ( V_59 , L_7 ) ;
if ( V_63 >= 0 )
V_2 -> line = V_63 ;
if ( V_2 -> V_40 )
return 0 ;
if ( F_39 ( V_59 , L_8 , & V_61 ) ) {
F_7 ( V_2 -> V_24 , L_9 ) ;
return - V_70 ;
}
V_2 -> V_40 = V_61 ;
return 0 ;
}
static int F_41 ( struct V_13 * V_14 ,
struct V_5 * V_57 )
{
struct V_1 * V_2 = & V_14 -> V_30 ;
F_33 ( V_14 ) ;
V_2 -> V_68 = V_69 ;
V_2 -> V_15 = F_16 ;
V_2 -> V_64 = F_14 ;
V_2 -> V_19 = 2 ;
V_14 -> V_71 = & V_57 -> V_71 ;
V_14 -> V_71 -> V_72 . V_73 = V_2 -> V_51 / 4 ;
V_14 -> V_71 -> V_74 . V_75 = V_2 -> V_51 / 4 ;
V_14 -> V_30 . V_76 = F_24 ;
return 0 ;
}
static int F_42 ( struct V_77 * V_78 )
{
struct V_13 V_79 = {} ;
struct V_80 * V_81 = F_43 ( V_78 , V_82 , 0 ) ;
struct V_80 * V_83 = F_43 ( V_78 , V_84 , 0 ) ;
struct V_5 * V_57 ;
int V_85 ;
if ( ! V_81 || ! V_83 ) {
F_7 ( & V_78 -> V_24 , L_10 ) ;
return - V_70 ;
}
F_44 ( & V_79 . V_30 . V_86 ) ;
V_79 . V_30 . V_87 = V_81 -> V_88 ;
V_79 . V_30 . V_83 = V_83 -> V_88 ;
V_79 . V_30 . V_89 = F_18 ;
V_79 . V_30 . V_90 = F_20 ;
V_79 . V_30 . type = V_91 ;
V_79 . V_30 . V_49 = V_66 | V_92 | V_93 ;
V_79 . V_30 . V_24 = & V_78 -> V_24 ;
V_79 . V_30 . V_18 = F_45 ( & V_78 -> V_24 , V_81 -> V_88 ,
F_46 ( V_81 ) ) ;
if ( ! V_79 . V_30 . V_18 )
return - V_94 ;
V_57 = F_47 ( & V_78 -> V_24 , sizeof( * V_57 ) , V_95 ) ;
if ( ! V_57 )
return - V_94 ;
V_57 -> V_29 = V_96 ;
V_57 -> V_38 = F_48 ( & V_78 -> V_24 , L_11 ) ;
if ( F_26 ( V_57 -> V_38 ) && F_49 ( V_57 -> V_38 ) != - V_97 )
V_57 -> V_38 = F_48 ( & V_78 -> V_24 , NULL ) ;
if ( F_26 ( V_57 -> V_38 ) && F_49 ( V_57 -> V_38 ) == - V_97 )
return - V_97 ;
if ( ! F_26 ( V_57 -> V_38 ) ) {
V_85 = F_30 ( V_57 -> V_38 ) ;
if ( V_85 )
F_50 ( & V_78 -> V_24 , L_12 ,
V_85 ) ;
else
V_79 . V_30 . V_40 = F_51 ( V_57 -> V_38 ) ;
}
V_57 -> V_98 = F_48 ( & V_78 -> V_24 , L_13 ) ;
if ( F_26 ( V_57 -> V_38 ) && F_49 ( V_57 -> V_38 ) == - V_97 ) {
V_85 = - V_97 ;
goto V_99;
}
if ( ! F_26 ( V_57 -> V_98 ) ) {
V_85 = F_30 ( V_57 -> V_98 ) ;
if ( V_85 ) {
F_7 ( & V_78 -> V_24 , L_14 ) ;
goto V_99;
}
}
V_57 -> V_100 = F_52 ( & V_78 -> V_24 , NULL ) ;
if ( F_26 ( V_57 -> V_100 ) && F_49 ( V_57 -> V_100 ) == - V_97 ) {
V_85 = - V_97 ;
goto V_101;
}
if ( ! F_26 ( V_57 -> V_100 ) )
F_53 ( V_57 -> V_100 ) ;
V_57 -> V_71 . V_102 = V_57 ;
V_57 -> V_71 . V_103 = V_57 ;
V_57 -> V_71 . V_104 = F_32 ;
V_79 . V_30 . V_68 = V_105 ;
V_79 . V_30 . V_15 = F_8 ;
V_79 . V_30 . V_64 = F_5 ;
V_79 . V_30 . V_7 = V_57 ;
if ( V_78 -> V_24 . V_60 ) {
V_85 = F_36 ( & V_79 . V_30 , V_57 ) ;
if ( V_85 )
goto V_106;
} else if ( F_54 ( & V_78 -> V_24 ) ) {
V_85 = F_41 ( & V_79 , V_57 ) ;
if ( V_85 )
goto V_106;
} else {
V_85 = - V_107 ;
goto V_106;
}
V_57 -> line = F_55 ( & V_79 ) ;
if ( V_57 -> line < 0 ) {
V_85 = V_57 -> line ;
goto V_106;
}
F_56 ( V_78 , V_57 ) ;
F_57 ( & V_78 -> V_24 ) ;
F_58 ( & V_78 -> V_24 ) ;
return 0 ;
V_106:
if ( ! F_26 ( V_57 -> V_100 ) )
F_59 ( V_57 -> V_100 ) ;
V_101:
if ( ! F_26 ( V_57 -> V_98 ) )
F_27 ( V_57 -> V_98 ) ;
V_99:
if ( ! F_26 ( V_57 -> V_38 ) )
F_27 ( V_57 -> V_38 ) ;
return V_85 ;
}
static int F_60 ( struct V_77 * V_78 )
{
struct V_5 * V_57 = F_61 ( V_78 ) ;
F_21 ( & V_78 -> V_24 ) ;
F_62 ( V_57 -> line ) ;
if ( ! F_26 ( V_57 -> V_100 ) )
F_59 ( V_57 -> V_100 ) ;
if ( ! F_26 ( V_57 -> V_98 ) )
F_27 ( V_57 -> V_98 ) ;
if ( ! F_26 ( V_57 -> V_38 ) )
F_27 ( V_57 -> V_38 ) ;
F_63 ( & V_78 -> V_24 ) ;
F_64 ( & V_78 -> V_24 ) ;
return 0 ;
}
static int F_65 ( struct V_108 * V_24 )
{
struct V_5 * V_57 = F_66 ( V_24 ) ;
F_67 ( V_57 -> line ) ;
return 0 ;
}
static int F_68 ( struct V_108 * V_24 )
{
struct V_5 * V_57 = F_66 ( V_24 ) ;
F_69 ( V_57 -> line ) ;
return 0 ;
}
static int F_70 ( struct V_108 * V_24 )
{
struct V_5 * V_57 = F_66 ( V_24 ) ;
if ( ! F_26 ( V_57 -> V_38 ) )
F_27 ( V_57 -> V_38 ) ;
if ( ! F_26 ( V_57 -> V_98 ) )
F_27 ( V_57 -> V_98 ) ;
return 0 ;
}
static int F_71 ( struct V_108 * V_24 )
{
struct V_5 * V_57 = F_66 ( V_24 ) ;
if ( ! F_26 ( V_57 -> V_98 ) )
F_30 ( V_57 -> V_98 ) ;
if ( ! F_26 ( V_57 -> V_38 ) )
F_30 ( V_57 -> V_38 ) ;
return 0 ;
}
