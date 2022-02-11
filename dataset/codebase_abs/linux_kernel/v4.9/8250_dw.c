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
const struct V_63 * V_56 ;
V_56 = F_44 ( V_2 -> V_34 -> V_64 -> V_65 ,
V_2 -> V_34 ) ;
if ( V_56 && ! strcmp ( V_56 -> V_56 , L_3 ) ) {
V_2 -> V_22 = V_23 ;
V_2 -> V_17 = 2 ;
V_2 -> V_13 = F_18 ;
V_52 -> V_25 = true ;
}
V_2 -> V_66 = F_29 ;
}
if ( F_45 ( F_46 ( V_2 -> V_34 ) ,
V_67 , L_4 ) ) {
V_2 -> V_66 = F_29 ;
V_52 -> V_68 . V_69 = V_2 -> V_34 -> V_51 ;
V_52 -> V_68 . V_70 = V_2 -> V_34 -> V_51 ;
V_52 -> V_68 . V_71 = F_38 ;
}
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
T_2 V_72 ;
if ( V_2 -> V_22 == V_24 )
V_72 = F_22 ( V_2 -> V_15 + V_73 ) ;
else
V_72 = F_19 ( V_2 -> V_15 + V_73 ) ;
if ( ! V_72 )
return;
F_48 ( V_2 -> V_34 , L_5 ,
( V_72 >> 24 ) & 0xff , ( V_72 >> 16 ) & 0xff , ( V_72 >> 8 ) & 0xff ) ;
if ( V_2 -> V_22 == V_24 )
V_72 = F_22 ( V_2 -> V_15 + V_74 ) ;
else
V_72 = F_19 ( V_2 -> V_15 + V_74 ) ;
if ( ! V_72 )
return;
if ( V_72 & V_75 ) {
V_2 -> type = V_76 ;
V_2 -> V_58 |= V_61 ;
V_2 -> V_77 = F_49 ( V_72 ) ;
V_12 -> V_78 = V_79 ;
}
if ( V_72 & V_80 )
V_12 -> V_78 |= V_81 ;
}
static int F_50 ( struct V_82 * V_83 )
{
struct V_11 V_84 = {} ;
struct V_85 * V_86 = F_51 ( V_83 , V_67 , 0 ) ;
int V_87 = F_52 ( V_83 , 0 ) ;
struct V_1 * V_2 = & V_84 . V_31 ;
struct V_50 * V_34 = & V_83 -> V_34 ;
struct V_5 * V_52 ;
int V_88 ;
T_2 V_89 ;
if ( ! V_86 ) {
F_53 ( V_34 , L_6 ) ;
return - V_90 ;
}
if ( V_87 < 0 ) {
if ( V_87 != - V_91 )
F_53 ( V_34 , L_7 ) ;
return V_87 ;
}
F_54 ( & V_2 -> V_92 ) ;
V_2 -> V_93 = V_86 -> V_94 ;
V_2 -> V_87 = V_87 ;
V_2 -> V_95 = F_23 ;
V_2 -> V_96 = F_25 ;
V_2 -> type = V_97 ;
V_2 -> V_58 = V_60 | V_98 ;
V_2 -> V_34 = V_34 ;
V_2 -> V_22 = V_99 ;
V_2 -> V_13 = F_12 ;
V_2 -> V_57 = F_11 ;
V_2 -> V_15 = F_55 ( V_34 , V_86 -> V_94 , F_56 ( V_86 ) ) ;
if ( ! V_2 -> V_15 )
return - V_100 ;
V_52 = F_57 ( V_34 , sizeof( * V_52 ) , V_101 ) ;
if ( ! V_52 )
return - V_100 ;
V_52 -> V_68 . V_71 = F_37 ;
V_52 -> V_30 = V_102 ;
V_2 -> V_7 = V_52 ;
V_52 -> V_25 = F_58 ( V_34 ,
L_8 ) ;
V_88 = F_59 ( V_34 , L_9 , & V_89 ) ;
if ( ! V_88 )
V_2 -> V_17 = V_89 ;
V_88 = F_59 ( V_34 , L_10 , & V_89 ) ;
if ( ! V_88 && V_89 == 4 ) {
V_2 -> V_22 = V_23 ;
V_2 -> V_13 = F_18 ;
V_2 -> V_57 = F_17 ;
}
if ( F_58 ( V_34 , L_11 ) ) {
V_52 -> V_9 |= V_103 ;
V_52 -> V_10 |= V_104 ;
}
if ( F_58 ( V_34 , L_12 ) ) {
V_52 -> V_9 |= V_105 ;
V_52 -> V_10 |= V_106 ;
}
if ( F_58 ( V_34 , L_13 ) ) {
V_52 -> V_9 |= V_107 ;
V_52 -> V_10 |= V_108 ;
}
if ( F_58 ( V_34 , L_14 ) ) {
V_52 -> V_10 |= V_109 ;
V_52 -> V_10 |= V_110 ;
}
F_59 ( V_34 , L_15 , & V_2 -> V_42 ) ;
V_52 -> V_40 = F_60 ( V_34 , L_16 ) ;
if ( F_31 ( V_52 -> V_40 ) && F_61 ( V_52 -> V_40 ) != - V_91 )
V_52 -> V_40 = F_60 ( V_34 , NULL ) ;
if ( F_31 ( V_52 -> V_40 ) && F_61 ( V_52 -> V_40 ) == - V_91 )
return - V_91 ;
if ( ! F_62 ( V_52 -> V_40 ) ) {
V_88 = F_35 ( V_52 -> V_40 ) ;
if ( V_88 )
F_63 ( V_34 , L_17 ,
V_88 ) ;
else
V_2 -> V_42 = F_64 ( V_52 -> V_40 ) ;
}
if ( ! V_2 -> V_42 ) {
F_53 ( V_34 , L_18 ) ;
return - V_90 ;
}
V_52 -> V_111 = F_60 ( V_34 , L_19 ) ;
if ( F_31 ( V_52 -> V_111 ) && F_61 ( V_52 -> V_111 ) == - V_91 ) {
V_88 = - V_91 ;
goto V_112;
}
if ( ! F_31 ( V_52 -> V_111 ) ) {
V_88 = F_35 ( V_52 -> V_111 ) ;
if ( V_88 ) {
F_53 ( V_34 , L_20 ) ;
goto V_112;
}
}
V_52 -> V_113 = F_65 ( V_34 , NULL ) ;
if ( F_31 ( V_52 -> V_113 ) && F_61 ( V_52 -> V_113 ) == - V_91 ) {
V_88 = - V_91 ;
goto V_114;
}
if ( ! F_31 ( V_52 -> V_113 ) )
F_66 ( V_52 -> V_113 ) ;
F_39 ( V_2 , V_52 ) ;
if ( V_52 -> V_25 )
V_2 -> V_95 = NULL ;
if ( ! V_52 -> V_62 )
F_47 ( V_2 ) ;
if ( V_2 -> V_77 ) {
V_52 -> V_68 . V_115 . V_116 = V_2 -> V_77 / 4 ;
V_52 -> V_68 . V_117 . V_118 = V_2 -> V_77 / 4 ;
V_84 . V_68 = & V_52 -> V_68 ;
}
V_52 -> line = F_67 ( & V_84 ) ;
if ( V_52 -> line < 0 ) {
V_88 = V_52 -> line ;
goto V_119;
}
F_68 ( V_83 , V_52 ) ;
F_69 ( V_34 ) ;
F_70 ( V_34 ) ;
return 0 ;
V_119:
if ( ! F_31 ( V_52 -> V_113 ) )
F_71 ( V_52 -> V_113 ) ;
V_114:
if ( ! F_31 ( V_52 -> V_111 ) )
F_32 ( V_52 -> V_111 ) ;
V_112:
if ( ! F_31 ( V_52 -> V_40 ) )
F_32 ( V_52 -> V_40 ) ;
return V_88 ;
}
static int F_72 ( struct V_82 * V_83 )
{
struct V_5 * V_52 = F_73 ( V_83 ) ;
F_26 ( & V_83 -> V_34 ) ;
F_74 ( V_52 -> line ) ;
if ( ! F_31 ( V_52 -> V_113 ) )
F_71 ( V_52 -> V_113 ) ;
if ( ! F_31 ( V_52 -> V_111 ) )
F_32 ( V_52 -> V_111 ) ;
if ( ! F_31 ( V_52 -> V_40 ) )
F_32 ( V_52 -> V_40 ) ;
F_75 ( & V_83 -> V_34 ) ;
F_76 ( & V_83 -> V_34 ) ;
return 0 ;
}
static int F_77 ( struct V_50 * V_34 )
{
struct V_5 * V_52 = F_78 ( V_34 ) ;
F_79 ( V_52 -> line ) ;
return 0 ;
}
static int F_80 ( struct V_50 * V_34 )
{
struct V_5 * V_52 = F_78 ( V_34 ) ;
F_81 ( V_52 -> line ) ;
return 0 ;
}
static int F_82 ( struct V_50 * V_34 )
{
struct V_5 * V_52 = F_78 ( V_34 ) ;
if ( ! F_31 ( V_52 -> V_40 ) )
F_32 ( V_52 -> V_40 ) ;
if ( ! F_31 ( V_52 -> V_111 ) )
F_32 ( V_52 -> V_111 ) ;
return 0 ;
}
static int F_83 ( struct V_50 * V_34 )
{
struct V_5 * V_52 = F_78 ( V_34 ) ;
if ( ! F_31 ( V_52 -> V_111 ) )
F_35 ( V_52 -> V_111 ) ;
if ( ! F_31 ( V_52 -> V_40 ) )
F_35 ( V_52 -> V_40 ) ;
return 0 ;
}
