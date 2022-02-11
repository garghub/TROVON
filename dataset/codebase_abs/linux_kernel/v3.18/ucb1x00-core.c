void F_1 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_4 )
{
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_2 -> V_7 |= V_4 ;
V_2 -> V_7 &= ~ V_3 ;
F_3 ( V_2 , V_8 , V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
}
void F_5 ( struct V_1 * V_2 , unsigned int V_9 , unsigned int V_10 )
{
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_2 -> V_11 |= V_9 ;
V_2 -> V_11 &= ~ V_10 ;
F_3 ( V_2 , V_12 , V_2 -> V_11 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
}
unsigned int F_6 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , V_12 ) ;
}
static void F_8 ( struct V_13 * V_14 , unsigned V_15 , int V_16 )
{
struct V_1 * V_2 = F_9 ( V_14 , struct V_1 , V_17 ) ;
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
if ( V_16 )
V_2 -> V_11 |= 1 << V_15 ;
else
V_2 -> V_11 &= ~ ( 1 << V_15 ) ;
F_10 ( V_2 ) ;
F_3 ( V_2 , V_12 , V_2 -> V_11 ) ;
F_11 ( V_2 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
}
static int F_12 ( struct V_13 * V_14 , unsigned V_15 )
{
struct V_1 * V_2 = F_9 ( V_14 , struct V_1 , V_17 ) ;
unsigned V_18 ;
F_10 ( V_2 ) ;
V_18 = F_7 ( V_2 , V_12 ) ;
F_11 ( V_2 ) ;
return V_18 & ( 1 << V_15 ) ;
}
static int F_13 ( struct V_13 * V_14 , unsigned V_15 )
{
struct V_1 * V_2 = F_9 ( V_14 , struct V_1 , V_17 ) ;
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_2 -> V_7 &= ~ ( 1 << V_15 ) ;
F_10 ( V_2 ) ;
F_3 ( V_2 , V_8 , V_2 -> V_7 ) ;
F_11 ( V_2 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
return 0 ;
}
static int F_14 ( struct V_13 * V_14 , unsigned V_15
, int V_16 )
{
struct V_1 * V_2 = F_9 ( V_14 , struct V_1 , V_17 ) ;
unsigned long V_5 ;
unsigned V_19 , V_20 = 1 << V_15 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_19 = V_2 -> V_11 ;
if ( V_16 )
V_2 -> V_11 |= V_20 ;
else
V_2 -> V_11 &= ~ V_20 ;
F_10 ( V_2 ) ;
if ( V_19 != V_2 -> V_11 )
F_3 ( V_2 , V_12 , V_2 -> V_11 ) ;
if ( ! ( V_2 -> V_7 & V_20 ) ) {
V_2 -> V_7 |= V_20 ;
F_3 ( V_2 , V_8 , V_2 -> V_7 ) ;
}
F_11 ( V_2 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
return 0 ;
}
static int F_15 ( struct V_13 * V_14 , unsigned V_15 )
{
struct V_1 * V_2 = F_9 ( V_14 , struct V_1 , V_17 ) ;
return V_2 -> V_21 > 0 ? V_2 -> V_21 + V_15 : - V_22 ;
}
void F_16 ( struct V_1 * V_2 )
{
F_17 ( & V_2 -> V_23 ) ;
V_2 -> V_24 |= V_25 ;
F_10 ( V_2 ) ;
F_3 ( V_2 , V_26 , V_2 -> V_24 ) ;
}
unsigned int F_18 ( struct V_1 * V_2 , int V_27 , int V_28 )
{
unsigned int V_18 ;
if ( V_28 )
V_27 |= V_29 ;
F_3 ( V_2 , V_26 , V_2 -> V_24 | V_27 ) ;
F_3 ( V_2 , V_26 , V_2 -> V_24 | V_27 | V_30 ) ;
for (; ; ) {
V_18 = F_7 ( V_2 , V_31 ) ;
if ( V_18 & V_32 )
break;
F_19 ( V_33 ) ;
F_20 ( 1 ) ;
}
return F_21 ( V_18 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
V_2 -> V_24 &= ~ V_25 ;
F_3 ( V_2 , V_26 , V_2 -> V_24 ) ;
F_11 ( V_2 ) ;
F_23 ( & V_2 -> V_23 ) ;
}
static void F_24 ( unsigned int V_34 , struct V_35 * V_36 )
{
struct V_1 * V_2 = F_25 ( V_36 ) ;
unsigned int V_37 , V_38 ;
F_10 ( V_2 ) ;
V_37 = F_7 ( V_2 , V_39 ) ;
F_3 ( V_2 , V_40 , V_37 ) ;
F_3 ( V_2 , V_40 , 0 ) ;
for ( V_38 = 0 ; V_38 < 16 && V_37 ; V_38 ++ , V_37 >>= 1 , V_34 ++ )
if ( V_37 & 1 )
F_26 ( V_2 -> V_21 + V_38 ) ;
F_11 ( V_2 ) ;
}
static void F_27 ( struct V_1 * V_2 , unsigned V_20 )
{
F_10 ( V_2 ) ;
if ( V_2 -> V_41 & V_20 )
F_3 ( V_2 , V_42 , V_2 -> V_41 &
V_2 -> V_43 ) ;
if ( V_2 -> V_44 & V_20 )
F_3 ( V_2 , V_45 , V_2 -> V_44 &
V_2 -> V_43 ) ;
F_11 ( V_2 ) ;
}
static void F_28 ( struct V_46 * V_47 )
{
}
static void F_29 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_30 ( V_47 ) ;
unsigned V_20 = 1 << ( V_47 -> V_34 - V_2 -> V_21 ) ;
F_31 ( & V_2 -> V_48 ) ;
V_2 -> V_43 &= ~ V_20 ;
F_27 ( V_2 , V_20 ) ;
F_32 ( & V_2 -> V_48 ) ;
}
static void F_33 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_30 ( V_47 ) ;
unsigned V_20 = 1 << ( V_47 -> V_34 - V_2 -> V_21 ) ;
F_31 ( & V_2 -> V_48 ) ;
V_2 -> V_43 |= V_20 ;
F_27 ( V_2 , V_20 ) ;
F_32 ( & V_2 -> V_48 ) ;
}
static int F_34 ( struct V_46 * V_47 , unsigned int type )
{
struct V_1 * V_2 = F_30 ( V_47 ) ;
unsigned V_20 = 1 << ( V_47 -> V_34 - V_2 -> V_21 ) ;
F_31 ( & V_2 -> V_48 ) ;
if ( type & V_49 )
V_2 -> V_41 |= V_20 ;
else
V_2 -> V_41 &= ~ V_20 ;
if ( type & V_50 )
V_2 -> V_44 |= V_20 ;
else
V_2 -> V_44 &= ~ V_20 ;
if ( V_2 -> V_43 & V_20 ) {
F_3 ( V_2 , V_42 , V_2 -> V_41 &
V_2 -> V_43 ) ;
F_3 ( V_2 , V_45 , V_2 -> V_44 &
V_2 -> V_43 ) ;
}
F_32 ( & V_2 -> V_48 ) ;
return 0 ;
}
static int F_35 ( struct V_46 * V_47 , unsigned int V_51 )
{
struct V_1 * V_2 = F_30 ( V_47 ) ;
struct V_52 * V_53 = V_2 -> V_54 -> V_55 . V_56 ;
unsigned V_20 = 1 << ( V_47 -> V_34 - V_2 -> V_21 ) ;
if ( ! V_53 || ! V_53 -> V_57 )
return - V_58 ;
F_31 ( & V_2 -> V_48 ) ;
if ( V_51 )
V_2 -> V_59 |= V_20 ;
else
V_2 -> V_59 &= ~ V_20 ;
F_32 ( & V_2 -> V_48 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
struct V_62 * V_63 ;
int V_64 ;
V_63 = F_37 ( sizeof( struct V_62 ) , V_65 ) ;
if ( ! V_63 )
return - V_66 ;
V_63 -> V_2 = V_2 ;
V_63 -> V_61 = V_61 ;
V_64 = V_61 -> V_67 ( V_63 ) ;
if ( V_64 ) {
F_38 ( V_63 ) ;
return V_64 ;
}
F_39 ( & V_63 -> V_68 , & V_2 -> V_69 ) ;
F_39 ( & V_63 -> V_70 , & V_61 -> V_69 ) ;
return V_64 ;
}
static void F_40 ( struct V_62 * V_63 )
{
V_63 -> V_61 -> remove ( V_63 ) ;
F_41 ( & V_63 -> V_68 ) ;
F_41 ( & V_63 -> V_70 ) ;
F_38 ( V_63 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
unsigned long V_20 ;
V_20 = F_43 () ;
if ( ! V_20 ) {
F_44 ( V_20 ) ;
return V_71 ;
}
F_3 ( V_2 , V_42 , V_72 ) ;
F_3 ( V_2 , V_45 , V_72 ) ;
F_3 ( V_2 , V_40 , 0xffff ) ;
F_3 ( V_2 , V_40 , 0 ) ;
F_3 ( V_2 , V_26 , V_25 ) ;
F_3 ( V_2 , V_26 , V_25 | V_30 ) ;
while ( ( F_7 ( V_2 , V_31 ) & V_32 ) == 0 ) ;
F_3 ( V_2 , V_26 , 0 ) ;
F_3 ( V_2 , V_42 , 0 ) ;
F_3 ( V_2 , V_45 , 0 ) ;
F_3 ( V_2 , V_40 , 0xffff ) ;
F_3 ( V_2 , V_40 , 0 ) ;
return F_44 ( V_20 ) ;
}
static void F_45 ( struct V_73 * V_63 )
{
struct V_1 * V_2 = F_46 ( V_63 ) ;
F_38 ( V_2 ) ;
}
static int F_47 ( struct V_54 * V_54 )
{
struct V_52 * V_53 = V_54 -> V_55 . V_56 ;
struct V_60 * V_61 ;
struct V_1 * V_2 ;
unsigned V_74 , V_38 , V_21 ;
int V_64 = - V_75 ;
if ( V_53 && V_53 -> V_76 )
V_53 -> V_76 ( V_77 ) ;
F_48 ( V_54 ) ;
V_74 = F_49 ( V_54 , V_78 ) ;
F_50 ( V_54 ) ;
if ( V_74 != V_79 && V_74 != V_80 && V_74 != V_81 ) {
F_51 ( V_82 L_1 , V_74 ) ;
goto V_4;
}
V_2 = F_52 ( sizeof( struct V_1 ) , V_65 ) ;
V_64 = - V_66 ;
if ( ! V_2 )
goto V_4;
F_53 ( & V_2 -> V_63 ) ;
V_2 -> V_63 . V_83 = & V_84 ;
V_2 -> V_63 . V_85 = & V_54 -> V_55 ;
F_54 ( & V_2 -> V_63 , L_2 ) ;
F_55 ( & V_2 -> V_48 ) ;
F_56 ( & V_2 -> V_6 ) ;
F_57 ( & V_2 -> V_23 ) ;
V_2 -> V_74 = V_74 ;
V_2 -> V_54 = V_54 ;
V_64 = F_58 ( & V_2 -> V_63 ) ;
if ( V_64 )
goto V_86;
F_10 ( V_2 ) ;
V_2 -> V_34 = F_42 ( V_2 ) ;
F_11 ( V_2 ) ;
if ( V_2 -> V_34 == V_71 ) {
F_59 ( & V_2 -> V_63 , L_3 ) ;
V_64 = - V_75 ;
goto V_87;
}
V_2 -> V_17 . V_88 = - 1 ;
V_21 = V_53 ? V_53 -> V_21 : 0 ;
V_2 -> V_21 = F_60 ( - 1 , V_21 , 16 , - 1 ) ;
if ( V_2 -> V_21 < 0 ) {
F_59 ( & V_2 -> V_63 , L_4 ,
V_2 -> V_21 ) ;
V_64 = V_2 -> V_21 ;
goto V_89;
}
for ( V_38 = 0 ; V_38 < 16 ; V_38 ++ ) {
unsigned V_34 = V_2 -> V_21 + V_38 ;
F_61 ( V_34 , & V_90 , V_91 ) ;
F_62 ( V_34 , V_2 ) ;
F_63 ( V_34 , V_92 | V_93 ) ;
}
F_64 ( V_2 -> V_34 , V_49 ) ;
F_65 ( V_2 -> V_34 , V_2 ) ;
F_66 ( V_2 -> V_34 , F_24 ) ;
if ( V_53 && V_53 -> V_94 ) {
V_2 -> V_17 . V_95 = F_67 ( & V_2 -> V_63 ) ;
V_2 -> V_17 . V_63 = & V_2 -> V_63 ;
V_2 -> V_17 . V_96 = V_97 ;
V_2 -> V_17 . V_88 = V_53 -> V_94 ;
V_2 -> V_17 . V_98 = 10 ;
V_2 -> V_17 . V_9 = F_8 ;
V_2 -> V_17 . V_99 = F_12 ;
V_2 -> V_17 . V_100 = F_13 ;
V_2 -> V_17 . V_101 = F_14 ;
V_2 -> V_17 . V_102 = F_15 ;
V_64 = F_68 ( & V_2 -> V_17 ) ;
if ( V_64 )
goto V_103;
} else
F_69 ( & V_2 -> V_63 , L_5 ) ;
F_70 ( V_54 , V_2 ) ;
if ( V_53 )
F_71 ( & V_2 -> V_63 , V_53 -> V_57 ) ;
F_72 ( & V_2 -> V_69 ) ;
F_17 ( & V_104 ) ;
F_39 ( & V_2 -> V_105 , & V_106 ) ;
F_73 (drv, &ucb1x00_drivers, node) {
F_36 ( V_2 , V_61 ) ;
}
F_23 ( & V_104 ) ;
return V_64 ;
V_103:
F_66 ( V_2 -> V_34 , NULL ) ;
V_89:
if ( V_2 -> V_21 > 0 )
F_74 ( V_2 -> V_21 , 16 ) ;
V_87:
F_75 ( & V_2 -> V_63 ) ;
V_86:
F_76 ( & V_2 -> V_63 ) ;
V_4:
if ( V_53 && V_53 -> V_76 )
V_53 -> V_76 ( V_107 ) ;
return V_64 ;
}
static void F_77 ( struct V_54 * V_54 )
{
struct V_52 * V_53 = V_54 -> V_55 . V_56 ;
struct V_1 * V_2 = F_78 ( V_54 ) ;
struct V_108 * V_109 , * V_110 ;
F_17 ( & V_104 ) ;
F_41 ( & V_2 -> V_105 ) ;
F_79 (l, n, &ucb->devs) {
struct V_62 * V_63 = F_80 ( V_109 , struct V_62 , V_68 ) ;
F_40 ( V_63 ) ;
}
F_23 ( & V_104 ) ;
if ( V_2 -> V_17 . V_88 != - 1 )
F_81 ( & V_2 -> V_17 ) ;
F_66 ( V_2 -> V_34 , NULL ) ;
F_74 ( V_2 -> V_21 , 16 ) ;
F_82 ( & V_2 -> V_63 ) ;
if ( V_53 && V_53 -> V_76 )
V_53 -> V_76 ( V_111 ) ;
}
int F_83 ( struct V_60 * V_61 )
{
struct V_1 * V_2 ;
F_72 ( & V_61 -> V_69 ) ;
F_17 ( & V_104 ) ;
F_39 ( & V_61 -> V_105 , & V_112 ) ;
F_73 (ucb, &ucb1x00_devices, node) {
F_36 ( V_2 , V_61 ) ;
}
F_23 ( & V_104 ) ;
return 0 ;
}
void F_84 ( struct V_60 * V_61 )
{
struct V_108 * V_110 , * V_109 ;
F_17 ( & V_104 ) ;
F_41 ( & V_61 -> V_105 ) ;
F_79 (l, n, &drv->devs) {
struct V_62 * V_63 = F_80 ( V_109 , struct V_62 , V_70 ) ;
F_40 ( V_63 ) ;
}
F_23 ( & V_104 ) ;
}
static int F_85 ( struct V_73 * V_63 )
{
struct V_52 * V_53 = F_86 ( V_63 ) ;
struct V_1 * V_2 = F_87 ( V_63 ) ;
struct V_62 * V_113 ;
F_17 ( & V_104 ) ;
F_73 (udev, &ucb->devs, dev_node) {
if ( V_113 -> V_61 -> V_114 )
V_113 -> V_61 -> V_114 ( V_113 ) ;
}
F_23 ( & V_104 ) ;
if ( V_2 -> V_59 ) {
unsigned long V_5 ;
F_88 ( & V_2 -> V_48 , V_5 ) ;
F_10 ( V_2 ) ;
F_3 ( V_2 , V_42 , V_2 -> V_41 &
V_2 -> V_59 ) ;
F_3 ( V_2 , V_45 , V_2 -> V_44 &
V_2 -> V_59 ) ;
F_11 ( V_2 ) ;
F_89 ( & V_2 -> V_48 , V_5 ) ;
F_90 ( V_2 -> V_34 ) ;
} else if ( V_53 && V_53 -> V_76 )
V_53 -> V_76 ( V_115 ) ;
return 0 ;
}
static int F_91 ( struct V_73 * V_63 )
{
struct V_52 * V_53 = F_86 ( V_63 ) ;
struct V_1 * V_2 = F_87 ( V_63 ) ;
struct V_62 * V_113 ;
if ( ! V_2 -> V_59 && V_53 && V_53 -> V_76 )
V_53 -> V_76 ( V_116 ) ;
F_10 ( V_2 ) ;
F_3 ( V_2 , V_12 , V_2 -> V_11 ) ;
F_3 ( V_2 , V_8 , V_2 -> V_7 ) ;
if ( V_2 -> V_59 ) {
unsigned long V_5 ;
F_88 ( & V_2 -> V_48 , V_5 ) ;
F_3 ( V_2 , V_42 , V_2 -> V_41 &
V_2 -> V_43 ) ;
F_3 ( V_2 , V_45 , V_2 -> V_44 &
V_2 -> V_43 ) ;
F_89 ( & V_2 -> V_48 , V_5 ) ;
F_92 ( V_2 -> V_34 ) ;
}
F_11 ( V_2 ) ;
F_17 ( & V_104 ) ;
F_73 (udev, &ucb->devs, dev_node) {
if ( V_113 -> V_61 -> V_117 )
V_113 -> V_61 -> V_117 ( V_113 ) ;
}
F_23 ( & V_104 ) ;
return 0 ;
}
static int T_1 F_93 ( void )
{
int V_64 = F_94 ( & V_84 ) ;
if ( V_64 == 0 ) {
V_64 = F_95 ( & V_60 ) ;
if ( V_64 )
F_96 ( & V_84 ) ;
}
return V_64 ;
}
static void T_2 F_97 ( void )
{
F_98 ( & V_60 ) ;
F_96 ( & V_84 ) ;
}
