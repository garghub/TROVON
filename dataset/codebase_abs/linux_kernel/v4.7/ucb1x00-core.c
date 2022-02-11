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
struct V_1 * V_2 = F_9 ( V_14 ) ;
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
struct V_1 * V_2 = F_9 ( V_14 ) ;
unsigned V_17 ;
F_10 ( V_2 ) ;
V_17 = F_7 ( V_2 , V_12 ) ;
F_11 ( V_2 ) ;
return ! ! ( V_17 & ( 1 << V_15 ) ) ;
}
static int F_13 ( struct V_13 * V_14 , unsigned V_15 )
{
struct V_1 * V_2 = F_9 ( V_14 ) ;
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
struct V_1 * V_2 = F_9 ( V_14 ) ;
unsigned long V_5 ;
unsigned V_18 , V_19 = 1 << V_15 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_18 = V_2 -> V_11 ;
if ( V_16 )
V_2 -> V_11 |= V_19 ;
else
V_2 -> V_11 &= ~ V_19 ;
F_10 ( V_2 ) ;
if ( V_18 != V_2 -> V_11 )
F_3 ( V_2 , V_12 , V_2 -> V_11 ) ;
if ( ! ( V_2 -> V_7 & V_19 ) ) {
V_2 -> V_7 |= V_19 ;
F_3 ( V_2 , V_8 , V_2 -> V_7 ) ;
}
F_11 ( V_2 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
return 0 ;
}
static int F_15 ( struct V_13 * V_14 , unsigned V_15 )
{
struct V_1 * V_2 = F_9 ( V_14 ) ;
return V_2 -> V_20 > 0 ? V_2 -> V_20 + V_15 : - V_21 ;
}
void F_16 ( struct V_1 * V_2 )
{
F_17 ( & V_2 -> V_22 ) ;
V_2 -> V_23 |= V_24 ;
F_10 ( V_2 ) ;
F_3 ( V_2 , V_25 , V_2 -> V_23 ) ;
}
unsigned int F_18 ( struct V_1 * V_2 , int V_26 , int V_27 )
{
unsigned int V_17 ;
if ( V_27 )
V_26 |= V_28 ;
F_3 ( V_2 , V_25 , V_2 -> V_23 | V_26 ) ;
F_3 ( V_2 , V_25 , V_2 -> V_23 | V_26 | V_29 ) ;
for (; ; ) {
V_17 = F_7 ( V_2 , V_30 ) ;
if ( V_17 & V_31 )
break;
F_19 ( V_32 ) ;
F_20 ( 1 ) ;
}
return F_21 ( V_17 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
V_2 -> V_23 &= ~ V_24 ;
F_3 ( V_2 , V_25 , V_2 -> V_23 ) ;
F_11 ( V_2 ) ;
F_23 ( & V_2 -> V_22 ) ;
}
static void F_24 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_25 ( V_34 ) ;
unsigned int V_35 , V_36 ;
F_10 ( V_2 ) ;
V_35 = F_7 ( V_2 , V_37 ) ;
F_3 ( V_2 , V_38 , V_35 ) ;
F_3 ( V_2 , V_38 , 0 ) ;
for ( V_36 = 0 ; V_36 < 16 && V_35 ; V_36 ++ , V_35 >>= 1 )
if ( V_35 & 1 )
F_26 ( V_2 -> V_20 + V_36 ) ;
F_11 ( V_2 ) ;
}
static void F_27 ( struct V_1 * V_2 , unsigned V_19 )
{
F_10 ( V_2 ) ;
if ( V_2 -> V_39 & V_19 )
F_3 ( V_2 , V_40 , V_2 -> V_39 &
V_2 -> V_41 ) ;
if ( V_2 -> V_42 & V_19 )
F_3 ( V_2 , V_43 , V_2 -> V_42 &
V_2 -> V_41 ) ;
F_11 ( V_2 ) ;
}
static void F_28 ( struct V_44 * V_45 )
{
}
static void F_29 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_30 ( V_45 ) ;
unsigned V_19 = 1 << ( V_45 -> V_46 - V_2 -> V_20 ) ;
F_31 ( & V_2 -> V_47 ) ;
V_2 -> V_41 &= ~ V_19 ;
F_27 ( V_2 , V_19 ) ;
F_32 ( & V_2 -> V_47 ) ;
}
static void F_33 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_30 ( V_45 ) ;
unsigned V_19 = 1 << ( V_45 -> V_46 - V_2 -> V_20 ) ;
F_31 ( & V_2 -> V_47 ) ;
V_2 -> V_41 |= V_19 ;
F_27 ( V_2 , V_19 ) ;
F_32 ( & V_2 -> V_47 ) ;
}
static int F_34 ( struct V_44 * V_45 , unsigned int type )
{
struct V_1 * V_2 = F_30 ( V_45 ) ;
unsigned V_19 = 1 << ( V_45 -> V_46 - V_2 -> V_20 ) ;
F_31 ( & V_2 -> V_47 ) ;
if ( type & V_48 )
V_2 -> V_39 |= V_19 ;
else
V_2 -> V_39 &= ~ V_19 ;
if ( type & V_49 )
V_2 -> V_42 |= V_19 ;
else
V_2 -> V_42 &= ~ V_19 ;
if ( V_2 -> V_41 & V_19 ) {
F_3 ( V_2 , V_40 , V_2 -> V_39 &
V_2 -> V_41 ) ;
F_3 ( V_2 , V_43 , V_2 -> V_42 &
V_2 -> V_41 ) ;
}
F_32 ( & V_2 -> V_47 ) ;
return 0 ;
}
static int F_35 ( struct V_44 * V_45 , unsigned int V_50 )
{
struct V_1 * V_2 = F_30 ( V_45 ) ;
struct V_51 * V_52 = V_2 -> V_53 -> V_54 . V_55 ;
unsigned V_19 = 1 << ( V_45 -> V_46 - V_2 -> V_20 ) ;
if ( ! V_52 || ! V_52 -> V_56 )
return - V_57 ;
F_31 ( & V_2 -> V_47 ) ;
if ( V_50 )
V_2 -> V_58 |= V_19 ;
else
V_2 -> V_58 &= ~ V_19 ;
F_32 ( & V_2 -> V_47 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
struct V_61 * V_62 ;
int V_63 ;
V_62 = F_37 ( sizeof( struct V_61 ) , V_64 ) ;
if ( ! V_62 )
return - V_65 ;
V_62 -> V_2 = V_2 ;
V_62 -> V_60 = V_60 ;
V_63 = V_60 -> V_66 ( V_62 ) ;
if ( V_63 ) {
F_38 ( V_62 ) ;
return V_63 ;
}
F_39 ( & V_62 -> V_67 , & V_2 -> V_68 ) ;
F_39 ( & V_62 -> V_69 , & V_60 -> V_68 ) ;
return V_63 ;
}
static void F_40 ( struct V_61 * V_62 )
{
V_62 -> V_60 -> remove ( V_62 ) ;
F_41 ( & V_62 -> V_67 ) ;
F_41 ( & V_62 -> V_69 ) ;
F_38 ( V_62 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
unsigned long V_19 ;
V_19 = F_43 () ;
if ( ! V_19 ) {
F_44 ( V_19 ) ;
return V_70 ;
}
F_3 ( V_2 , V_40 , V_71 ) ;
F_3 ( V_2 , V_43 , V_71 ) ;
F_3 ( V_2 , V_38 , 0xffff ) ;
F_3 ( V_2 , V_38 , 0 ) ;
F_3 ( V_2 , V_25 , V_24 ) ;
F_3 ( V_2 , V_25 , V_24 | V_29 ) ;
while ( ( F_7 ( V_2 , V_30 ) & V_31 ) == 0 ) ;
F_3 ( V_2 , V_25 , 0 ) ;
F_3 ( V_2 , V_40 , 0 ) ;
F_3 ( V_2 , V_43 , 0 ) ;
F_3 ( V_2 , V_38 , 0xffff ) ;
F_3 ( V_2 , V_38 , 0 ) ;
return F_44 ( V_19 ) ;
}
static void F_45 ( struct V_72 * V_62 )
{
struct V_1 * V_2 = F_46 ( V_62 ) ;
F_38 ( V_2 ) ;
}
static int F_47 ( struct V_53 * V_53 )
{
struct V_51 * V_52 = V_53 -> V_54 . V_55 ;
struct V_59 * V_60 ;
struct V_1 * V_2 ;
unsigned V_73 , V_36 , V_20 ;
int V_63 = - V_74 ;
if ( V_52 && V_52 -> V_75 )
V_52 -> V_75 ( V_76 ) ;
F_48 ( V_53 ) ;
V_73 = F_49 ( V_53 , V_77 ) ;
F_50 ( V_53 ) ;
if ( V_73 != V_78 && V_73 != V_79 && V_73 != V_80 ) {
F_51 ( V_81 L_1 , V_73 ) ;
goto V_4;
}
V_2 = F_52 ( sizeof( struct V_1 ) , V_64 ) ;
V_63 = - V_65 ;
if ( ! V_2 )
goto V_4;
F_53 ( & V_2 -> V_62 ) ;
V_2 -> V_62 . V_82 = & V_83 ;
V_2 -> V_62 . V_84 = & V_53 -> V_54 ;
F_54 ( & V_2 -> V_62 , L_2 ) ;
F_55 ( & V_2 -> V_47 ) ;
F_56 ( & V_2 -> V_6 ) ;
F_57 ( & V_2 -> V_22 ) ;
V_2 -> V_73 = V_73 ;
V_2 -> V_53 = V_53 ;
V_63 = F_58 ( & V_2 -> V_62 ) ;
if ( V_63 )
goto V_85;
F_10 ( V_2 ) ;
V_2 -> V_46 = F_42 ( V_2 ) ;
F_11 ( V_2 ) ;
if ( V_2 -> V_46 == V_70 ) {
F_59 ( & V_2 -> V_62 , L_3 ) ;
V_63 = - V_74 ;
goto V_86;
}
V_2 -> V_87 . V_88 = - 1 ;
V_20 = V_52 ? V_52 -> V_20 : 0 ;
V_2 -> V_20 = F_60 ( - 1 , V_20 , 16 , - 1 ) ;
if ( V_2 -> V_20 < 0 ) {
F_59 ( & V_2 -> V_62 , L_4 ,
V_2 -> V_20 ) ;
V_63 = V_2 -> V_20 ;
goto V_89;
}
for ( V_36 = 0 ; V_36 < 16 ; V_36 ++ ) {
unsigned V_46 = V_2 -> V_20 + V_36 ;
F_61 ( V_46 , & V_90 , V_91 ) ;
F_62 ( V_46 , V_2 ) ;
F_63 ( V_46 , V_92 ) ;
}
F_64 ( V_2 -> V_46 , V_48 ) ;
F_65 ( V_2 -> V_46 , F_24 , V_2 ) ;
if ( V_52 && V_52 -> V_93 ) {
V_2 -> V_87 . V_94 = F_66 ( & V_2 -> V_62 ) ;
V_2 -> V_87 . V_84 = & V_2 -> V_62 ;
V_2 -> V_87 . V_95 = V_96 ;
V_2 -> V_87 . V_88 = V_52 -> V_93 ;
V_2 -> V_87 . V_97 = 10 ;
V_2 -> V_87 . V_9 = F_8 ;
V_2 -> V_87 . V_98 = F_12 ;
V_2 -> V_87 . V_99 = F_13 ;
V_2 -> V_87 . V_100 = F_14 ;
V_2 -> V_87 . V_101 = F_15 ;
V_63 = F_67 ( & V_2 -> V_87 , V_2 ) ;
if ( V_63 )
goto V_102;
} else
F_68 ( & V_2 -> V_62 , L_5 ) ;
F_69 ( V_53 , V_2 ) ;
if ( V_52 )
F_70 ( & V_2 -> V_62 , V_52 -> V_56 ) ;
F_71 ( & V_2 -> V_68 ) ;
F_17 ( & V_103 ) ;
F_39 ( & V_2 -> V_104 , & V_105 ) ;
F_72 (drv, &ucb1x00_drivers, node) {
F_36 ( V_2 , V_60 ) ;
}
F_23 ( & V_103 ) ;
return V_63 ;
V_102:
F_73 ( V_2 -> V_46 , NULL ) ;
V_89:
if ( V_2 -> V_20 > 0 )
F_74 ( V_2 -> V_20 , 16 ) ;
V_86:
F_75 ( & V_2 -> V_62 ) ;
V_85:
F_76 ( & V_2 -> V_62 ) ;
V_4:
if ( V_52 && V_52 -> V_75 )
V_52 -> V_75 ( V_106 ) ;
return V_63 ;
}
static void F_77 ( struct V_53 * V_53 )
{
struct V_51 * V_52 = V_53 -> V_54 . V_55 ;
struct V_1 * V_2 = F_78 ( V_53 ) ;
struct V_107 * V_108 , * V_109 ;
F_17 ( & V_103 ) ;
F_41 ( & V_2 -> V_104 ) ;
F_79 (l, n, &ucb->devs) {
struct V_61 * V_62 = F_80 ( V_108 , struct V_61 , V_67 ) ;
F_40 ( V_62 ) ;
}
F_23 ( & V_103 ) ;
if ( V_2 -> V_87 . V_88 != - 1 )
F_81 ( & V_2 -> V_87 ) ;
F_73 ( V_2 -> V_46 , NULL ) ;
F_74 ( V_2 -> V_20 , 16 ) ;
F_82 ( & V_2 -> V_62 ) ;
if ( V_52 && V_52 -> V_75 )
V_52 -> V_75 ( V_110 ) ;
}
int F_83 ( struct V_59 * V_60 )
{
struct V_1 * V_2 ;
F_71 ( & V_60 -> V_68 ) ;
F_17 ( & V_103 ) ;
F_39 ( & V_60 -> V_104 , & V_111 ) ;
F_72 (ucb, &ucb1x00_devices, node) {
F_36 ( V_2 , V_60 ) ;
}
F_23 ( & V_103 ) ;
return 0 ;
}
void F_84 ( struct V_59 * V_60 )
{
struct V_107 * V_109 , * V_108 ;
F_17 ( & V_103 ) ;
F_41 ( & V_60 -> V_104 ) ;
F_79 (l, n, &drv->devs) {
struct V_61 * V_62 = F_80 ( V_108 , struct V_61 , V_69 ) ;
F_40 ( V_62 ) ;
}
F_23 ( & V_103 ) ;
}
static int F_85 ( struct V_72 * V_62 )
{
struct V_51 * V_52 = F_86 ( V_62 ) ;
struct V_1 * V_2 = F_87 ( V_62 ) ;
struct V_61 * V_112 ;
F_17 ( & V_103 ) ;
F_72 (udev, &ucb->devs, dev_node) {
if ( V_112 -> V_60 -> V_113 )
V_112 -> V_60 -> V_113 ( V_112 ) ;
}
F_23 ( & V_103 ) ;
if ( V_2 -> V_58 ) {
unsigned long V_5 ;
F_88 ( & V_2 -> V_47 , V_5 ) ;
F_10 ( V_2 ) ;
F_3 ( V_2 , V_40 , V_2 -> V_39 &
V_2 -> V_58 ) ;
F_3 ( V_2 , V_43 , V_2 -> V_42 &
V_2 -> V_58 ) ;
F_11 ( V_2 ) ;
F_89 ( & V_2 -> V_47 , V_5 ) ;
F_90 ( V_2 -> V_46 ) ;
} else if ( V_52 && V_52 -> V_75 )
V_52 -> V_75 ( V_114 ) ;
return 0 ;
}
static int F_91 ( struct V_72 * V_62 )
{
struct V_51 * V_52 = F_86 ( V_62 ) ;
struct V_1 * V_2 = F_87 ( V_62 ) ;
struct V_61 * V_112 ;
if ( ! V_2 -> V_58 && V_52 && V_52 -> V_75 )
V_52 -> V_75 ( V_115 ) ;
F_10 ( V_2 ) ;
F_3 ( V_2 , V_12 , V_2 -> V_11 ) ;
F_3 ( V_2 , V_8 , V_2 -> V_7 ) ;
if ( V_2 -> V_58 ) {
unsigned long V_5 ;
F_88 ( & V_2 -> V_47 , V_5 ) ;
F_3 ( V_2 , V_40 , V_2 -> V_39 &
V_2 -> V_41 ) ;
F_3 ( V_2 , V_43 , V_2 -> V_42 &
V_2 -> V_41 ) ;
F_89 ( & V_2 -> V_47 , V_5 ) ;
F_92 ( V_2 -> V_46 ) ;
}
F_11 ( V_2 ) ;
F_17 ( & V_103 ) ;
F_72 (udev, &ucb->devs, dev_node) {
if ( V_112 -> V_60 -> V_116 )
V_112 -> V_60 -> V_116 ( V_112 ) ;
}
F_23 ( & V_103 ) ;
return 0 ;
}
static int T_1 F_93 ( void )
{
int V_63 = F_94 ( & V_83 ) ;
if ( V_63 == 0 ) {
V_63 = F_95 ( & V_59 ) ;
if ( V_63 )
F_96 ( & V_83 ) ;
}
return V_63 ;
}
static void T_2 F_97 ( void )
{
F_98 ( & V_59 ) ;
F_96 ( & V_83 ) ;
}
