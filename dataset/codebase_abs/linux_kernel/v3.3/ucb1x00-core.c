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
F_3 ( V_2 , V_12 , V_2 -> V_11 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
}
static int F_10 ( struct V_13 * V_14 , unsigned V_15 )
{
struct V_1 * V_2 = F_9 ( V_14 , struct V_1 , V_17 ) ;
return F_7 ( V_2 , V_12 ) & ( 1 << V_15 ) ;
}
static int F_11 ( struct V_13 * V_14 , unsigned V_15 )
{
struct V_1 * V_2 = F_9 ( V_14 , struct V_1 , V_17 ) ;
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_2 -> V_7 &= ~ ( 1 << V_15 ) ;
F_3 ( V_2 , V_8 , V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
return 0 ;
}
static int F_12 ( struct V_13 * V_14 , unsigned V_15
, int V_16 )
{
struct V_1 * V_2 = F_9 ( V_14 , struct V_1 , V_17 ) ;
unsigned long V_5 ;
unsigned V_18 , V_19 = 1 << V_15 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_18 = V_2 -> V_11 ;
if ( V_16 )
V_2 -> V_11 |= V_19 ;
else
V_2 -> V_11 &= ~ V_19 ;
if ( V_18 != V_2 -> V_11 )
F_3 ( V_2 , V_12 , V_2 -> V_11 ) ;
if ( ! ( V_2 -> V_7 & V_19 ) ) {
V_2 -> V_7 |= V_19 ;
F_3 ( V_2 , V_8 , V_2 -> V_7 ) ;
}
F_4 ( & V_2 -> V_6 , V_5 ) ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_20 ) ;
V_2 -> V_21 |= V_22 ;
F_15 ( V_2 ) ;
F_3 ( V_2 , V_23 , V_2 -> V_21 ) ;
}
unsigned int F_16 ( struct V_1 * V_2 , int V_24 , int V_25 )
{
unsigned int V_26 ;
if ( V_25 )
V_24 |= V_27 ;
F_3 ( V_2 , V_23 , V_2 -> V_21 | V_24 ) ;
F_3 ( V_2 , V_23 , V_2 -> V_21 | V_24 | V_28 ) ;
for (; ; ) {
V_26 = F_7 ( V_2 , V_29 ) ;
if ( V_26 & V_30 )
break;
F_17 ( V_31 ) ;
F_18 ( 1 ) ;
}
return F_19 ( V_26 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
V_2 -> V_21 &= ~ V_22 ;
F_3 ( V_2 , V_23 , V_2 -> V_21 ) ;
F_21 ( V_2 ) ;
F_22 ( & V_2 -> V_20 ) ;
}
static T_1 F_23 ( int V_32 , void * V_33 )
{
struct V_1 * V_2 = V_33 ;
struct F_23 * V_34 ;
unsigned int V_35 , V_36 ;
F_15 ( V_2 ) ;
V_35 = F_7 ( V_2 , V_37 ) ;
F_3 ( V_2 , V_38 , V_35 ) ;
F_3 ( V_2 , V_38 , 0 ) ;
for ( V_36 = 0 , V_34 = V_2 -> V_39 ; V_36 < 16 && V_35 ; V_36 ++ , V_35 >>= 1 , V_34 ++ )
if ( V_35 & 1 && V_34 -> V_40 )
V_34 -> V_40 ( V_36 , V_34 -> V_33 ) ;
F_21 ( V_2 ) ;
return V_41 ;
}
int F_24 ( struct V_1 * V_2 , unsigned int V_42 , void (* V_40)( int , void * ) , void * V_33 )
{
struct F_23 * V_34 ;
int V_43 = - V_44 ;
if ( V_42 < 16 ) {
V_34 = V_2 -> V_39 + V_42 ;
V_43 = - V_45 ;
F_25 ( & V_2 -> V_46 ) ;
if ( V_34 -> V_40 == NULL ) {
V_34 -> V_33 = V_33 ;
V_34 -> V_40 = V_40 ;
V_43 = 0 ;
}
F_26 ( & V_2 -> V_46 ) ;
}
return V_43 ;
}
void F_27 ( struct V_1 * V_2 , unsigned int V_42 , int V_47 )
{
unsigned long V_5 ;
if ( V_42 < 16 ) {
F_2 ( & V_2 -> V_46 , V_5 ) ;
F_15 ( V_2 ) ;
if ( V_47 & V_48 ) {
V_2 -> V_49 |= 1 << V_42 ;
F_3 ( V_2 , V_50 , V_2 -> V_49 ) ;
}
if ( V_47 & V_51 ) {
V_2 -> V_52 |= 1 << V_42 ;
F_3 ( V_2 , V_53 , V_2 -> V_52 ) ;
}
F_21 ( V_2 ) ;
F_4 ( & V_2 -> V_46 , V_5 ) ;
}
}
void F_28 ( struct V_1 * V_2 , unsigned int V_42 , int V_47 )
{
unsigned long V_5 ;
if ( V_42 < 16 ) {
F_2 ( & V_2 -> V_46 , V_5 ) ;
F_15 ( V_2 ) ;
if ( V_47 & V_48 ) {
V_2 -> V_49 &= ~ ( 1 << V_42 ) ;
F_3 ( V_2 , V_50 , V_2 -> V_49 ) ;
}
if ( V_47 & V_51 ) {
V_2 -> V_52 &= ~ ( 1 << V_42 ) ;
F_3 ( V_2 , V_53 , V_2 -> V_52 ) ;
}
F_21 ( V_2 ) ;
F_4 ( & V_2 -> V_46 , V_5 ) ;
}
}
int F_29 ( struct V_1 * V_2 , unsigned int V_42 , void * V_33 )
{
struct F_23 * V_34 ;
int V_43 ;
if ( V_42 >= 16 )
goto V_54;
V_34 = V_2 -> V_39 + V_42 ;
V_43 = - V_55 ;
F_25 ( & V_2 -> V_46 ) ;
if ( V_34 -> V_33 == V_33 ) {
V_2 -> V_49 &= ~ ( 1 << V_42 ) ;
V_2 -> V_52 &= ~ ( 1 << V_42 ) ;
F_15 ( V_2 ) ;
F_3 ( V_2 , V_50 , V_2 -> V_49 ) ;
F_3 ( V_2 , V_53 , V_2 -> V_52 ) ;
F_21 ( V_2 ) ;
V_34 -> V_40 = NULL ;
V_34 -> V_33 = NULL ;
V_43 = 0 ;
}
F_26 ( & V_2 -> V_46 ) ;
return V_43 ;
V_54:
F_30 ( V_56 L_1 , V_42 ) ;
return - V_44 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_57 * V_58 )
{
struct V_59 * V_60 ;
int V_43 = - V_61 ;
V_60 = F_32 ( sizeof( struct V_59 ) , V_62 ) ;
if ( V_60 ) {
V_60 -> V_2 = V_2 ;
V_60 -> V_58 = V_58 ;
V_43 = V_58 -> V_63 ( V_60 ) ;
if ( V_43 == 0 ) {
F_33 ( & V_60 -> V_64 , & V_2 -> V_65 ) ;
F_33 ( & V_60 -> V_66 , & V_58 -> V_65 ) ;
} else {
F_34 ( V_60 ) ;
}
}
return V_43 ;
}
static void F_35 ( struct V_59 * V_60 )
{
V_60 -> V_58 -> remove ( V_60 ) ;
F_36 ( & V_60 -> V_64 ) ;
F_36 ( & V_60 -> V_66 ) ;
F_34 ( V_60 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
unsigned long V_19 ;
V_19 = F_38 () ;
if ( ! V_19 ) {
F_39 ( V_19 ) ;
return V_67 ;
}
F_3 ( V_2 , V_50 , V_68 ) ;
F_3 ( V_2 , V_53 , V_68 ) ;
F_3 ( V_2 , V_38 , 0xffff ) ;
F_3 ( V_2 , V_38 , 0 ) ;
F_3 ( V_2 , V_23 , V_22 ) ;
F_3 ( V_2 , V_23 , V_22 | V_28 ) ;
while ( ( F_7 ( V_2 , V_29 ) & V_30 ) == 0 ) ;
F_3 ( V_2 , V_23 , 0 ) ;
F_3 ( V_2 , V_50 , 0 ) ;
F_3 ( V_2 , V_53 , 0 ) ;
F_3 ( V_2 , V_38 , 0xffff ) ;
F_3 ( V_2 , V_38 , 0 ) ;
return F_39 ( V_19 ) ;
}
static void F_40 ( struct V_69 * V_60 )
{
struct V_1 * V_2 = F_41 ( V_60 ) ;
F_34 ( V_2 ) ;
}
static int F_42 ( struct V_70 * V_70 )
{
struct V_1 * V_2 ;
struct V_57 * V_58 ;
unsigned int V_71 ;
int V_43 = - V_72 ;
int V_73 ;
F_43 ( V_70 ) ;
V_71 = F_44 ( V_70 , V_74 ) ;
if ( V_71 != V_75 && V_71 != V_76 && V_71 != V_77 ) {
F_30 ( V_78 L_2 , V_71 ) ;
goto V_79;
}
V_2 = F_45 ( sizeof( struct V_1 ) , V_62 ) ;
V_43 = - V_61 ;
if ( ! V_2 )
goto V_79;
V_2 -> V_60 . V_80 = & V_81 ;
V_2 -> V_60 . V_82 = & V_70 -> V_83 ;
F_46 ( & V_2 -> V_60 , L_3 ) ;
F_47 ( & V_2 -> V_46 ) ;
F_47 ( & V_2 -> V_6 ) ;
F_48 ( & V_2 -> V_20 , 1 ) ;
V_2 -> V_71 = V_71 ;
V_2 -> V_70 = V_70 ;
V_2 -> V_34 = F_37 ( V_2 ) ;
if ( V_2 -> V_34 == V_67 ) {
F_30 ( V_56 L_4 ) ;
V_43 = - V_72 ;
goto V_84;
}
V_2 -> V_17 . V_85 = - 1 ;
if ( V_70 -> V_86 != 0 ) {
V_2 -> V_17 . V_87 = F_49 ( & V_2 -> V_60 ) ;
V_2 -> V_17 . V_85 = V_70 -> V_86 ;
V_2 -> V_17 . V_88 = 10 ;
V_2 -> V_17 . V_9 = F_8 ;
V_2 -> V_17 . V_89 = F_10 ;
V_2 -> V_17 . V_90 = F_11 ;
V_2 -> V_17 . V_91 = F_12 ;
V_43 = F_50 ( & V_2 -> V_17 ) ;
if ( V_43 )
goto V_84;
} else
F_51 ( & V_2 -> V_60 , L_5 ) ;
V_43 = F_52 ( V_2 -> V_34 , F_23 , V_92 ,
L_6 , V_2 ) ;
if ( V_43 ) {
F_30 ( V_56 L_7 ,
V_2 -> V_34 , V_43 ) ;
goto V_93;
}
F_53 ( V_70 , V_2 ) ;
V_43 = F_54 ( & V_2 -> V_60 ) ;
if ( V_43 )
goto V_94;
F_55 ( & V_2 -> V_65 ) ;
F_56 ( & V_95 ) ;
F_33 ( & V_2 -> V_96 , & V_97 ) ;
F_57 (drv, &ucb1x00_drivers, node) {
F_31 ( V_2 , V_58 ) ;
}
F_58 ( & V_95 ) ;
goto V_4;
V_94:
F_59 ( V_2 -> V_34 , V_2 ) ;
V_93:
if ( V_2 -> V_17 . V_85 != - 1 )
V_73 = F_60 ( & V_2 -> V_17 ) ;
V_84:
F_34 ( V_2 ) ;
V_79:
F_61 ( V_70 ) ;
V_4:
return V_43 ;
}
static void F_62 ( struct V_70 * V_70 )
{
struct V_1 * V_2 = F_63 ( V_70 ) ;
struct V_98 * V_99 , * V_100 ;
int V_43 ;
F_56 ( & V_95 ) ;
F_36 ( & V_2 -> V_96 ) ;
F_64 (l, n, &ucb->devs) {
struct V_59 * V_60 = F_65 ( V_99 , struct V_59 , V_64 ) ;
F_35 ( V_60 ) ;
}
F_58 ( & V_95 ) ;
if ( V_2 -> V_17 . V_85 != - 1 ) {
V_43 = F_60 ( & V_2 -> V_17 ) ;
if ( V_43 )
F_66 ( & V_2 -> V_60 , L_8 , V_43 ) ;
}
F_59 ( V_2 -> V_34 , V_2 ) ;
F_67 ( & V_2 -> V_60 ) ;
}
int F_68 ( struct V_57 * V_58 )
{
struct V_1 * V_2 ;
F_55 ( & V_58 -> V_65 ) ;
F_56 ( & V_95 ) ;
F_33 ( & V_58 -> V_96 , & V_101 ) ;
F_57 (ucb, &ucb1x00_devices, node) {
F_31 ( V_2 , V_58 ) ;
}
F_58 ( & V_95 ) ;
return 0 ;
}
void F_69 ( struct V_57 * V_58 )
{
struct V_98 * V_100 , * V_99 ;
F_56 ( & V_95 ) ;
F_36 ( & V_58 -> V_96 ) ;
F_64 (l, n, &drv->devs) {
struct V_59 * V_60 = F_65 ( V_99 , struct V_59 , V_66 ) ;
F_35 ( V_60 ) ;
}
F_58 ( & V_95 ) ;
}
static int F_70 ( struct V_70 * V_70 , T_2 V_102 )
{
struct V_1 * V_2 = F_63 ( V_70 ) ;
struct V_59 * V_60 ;
F_56 ( & V_95 ) ;
F_57 (dev, &ucb->devs, dev_node) {
if ( V_60 -> V_58 -> V_103 )
V_60 -> V_58 -> V_103 ( V_60 , V_102 ) ;
}
F_58 ( & V_95 ) ;
return 0 ;
}
static int F_71 ( struct V_70 * V_70 )
{
struct V_1 * V_2 = F_63 ( V_70 ) ;
struct V_59 * V_60 ;
F_3 ( V_2 , V_12 , V_2 -> V_11 ) ;
F_3 ( V_2 , V_8 , V_2 -> V_7 ) ;
F_56 ( & V_95 ) ;
F_57 (dev, &ucb->devs, dev_node) {
if ( V_60 -> V_58 -> V_104 )
V_60 -> V_58 -> V_104 ( V_60 ) ;
}
F_58 ( & V_95 ) ;
return 0 ;
}
static int T_3 F_72 ( void )
{
int V_43 = F_73 ( & V_81 ) ;
if ( V_43 == 0 ) {
V_43 = F_74 ( & V_57 ) ;
if ( V_43 )
F_75 ( & V_81 ) ;
}
return V_43 ;
}
static void T_4 F_76 ( void )
{
F_77 ( & V_57 ) ;
F_75 ( & V_81 ) ;
}
