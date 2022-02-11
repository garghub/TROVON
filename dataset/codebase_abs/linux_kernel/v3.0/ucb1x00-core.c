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
F_2 ( & V_2 -> V_6 , V_5 ) ;
V_2 -> V_7 |= ( 1 << V_15 ) ;
F_3 ( V_2 , V_8 , V_2 -> V_7 ) ;
if ( V_16 )
V_2 -> V_11 |= 1 << V_15 ;
else
V_2 -> V_11 &= ~ ( 1 << V_15 ) ;
F_3 ( V_2 , V_12 , V_2 -> V_11 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_18 ) ;
V_2 -> V_19 |= V_20 ;
F_15 ( V_2 ) ;
F_3 ( V_2 , V_21 , V_2 -> V_19 ) ;
}
unsigned int F_16 ( struct V_1 * V_2 , int V_22 , int V_23 )
{
unsigned int V_24 ;
if ( V_23 )
V_22 |= V_25 ;
F_3 ( V_2 , V_21 , V_2 -> V_19 | V_22 ) ;
F_3 ( V_2 , V_21 , V_2 -> V_19 | V_22 | V_26 ) ;
for (; ; ) {
V_24 = F_7 ( V_2 , V_27 ) ;
if ( V_24 & V_28 )
break;
F_17 ( V_29 ) ;
F_18 ( 1 ) ;
}
return F_19 ( V_24 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
V_2 -> V_19 &= ~ V_20 ;
F_3 ( V_2 , V_21 , V_2 -> V_19 ) ;
F_21 ( V_2 ) ;
F_22 ( & V_2 -> V_18 ) ;
}
static T_1 F_23 ( int V_30 , void * V_31 )
{
struct V_1 * V_2 = V_31 ;
struct F_23 * V_32 ;
unsigned int V_33 , V_34 ;
F_15 ( V_2 ) ;
V_33 = F_7 ( V_2 , V_35 ) ;
F_3 ( V_2 , V_36 , V_33 ) ;
F_3 ( V_2 , V_36 , 0 ) ;
for ( V_34 = 0 , V_32 = V_2 -> V_37 ; V_34 < 16 && V_33 ; V_34 ++ , V_33 >>= 1 , V_32 ++ )
if ( V_33 & 1 && V_32 -> V_38 )
V_32 -> V_38 ( V_34 , V_32 -> V_31 ) ;
F_21 ( V_2 ) ;
return V_39 ;
}
int F_24 ( struct V_1 * V_2 , unsigned int V_40 , void (* V_38)( int , void * ) , void * V_31 )
{
struct F_23 * V_32 ;
int V_41 = - V_42 ;
if ( V_40 < 16 ) {
V_32 = V_2 -> V_37 + V_40 ;
V_41 = - V_43 ;
F_25 ( & V_2 -> V_44 ) ;
if ( V_32 -> V_38 == NULL ) {
V_32 -> V_31 = V_31 ;
V_32 -> V_38 = V_38 ;
V_41 = 0 ;
}
F_26 ( & V_2 -> V_44 ) ;
}
return V_41 ;
}
void F_27 ( struct V_1 * V_2 , unsigned int V_40 , int V_45 )
{
unsigned long V_5 ;
if ( V_40 < 16 ) {
F_2 ( & V_2 -> V_44 , V_5 ) ;
F_15 ( V_2 ) ;
if ( V_45 & V_46 ) {
V_2 -> V_47 |= 1 << V_40 ;
F_3 ( V_2 , V_48 , V_2 -> V_47 ) ;
}
if ( V_45 & V_49 ) {
V_2 -> V_50 |= 1 << V_40 ;
F_3 ( V_2 , V_51 , V_2 -> V_50 ) ;
}
F_21 ( V_2 ) ;
F_4 ( & V_2 -> V_44 , V_5 ) ;
}
}
void F_28 ( struct V_1 * V_2 , unsigned int V_40 , int V_45 )
{
unsigned long V_5 ;
if ( V_40 < 16 ) {
F_2 ( & V_2 -> V_44 , V_5 ) ;
F_15 ( V_2 ) ;
if ( V_45 & V_46 ) {
V_2 -> V_47 &= ~ ( 1 << V_40 ) ;
F_3 ( V_2 , V_48 , V_2 -> V_47 ) ;
}
if ( V_45 & V_49 ) {
V_2 -> V_50 &= ~ ( 1 << V_40 ) ;
F_3 ( V_2 , V_51 , V_2 -> V_50 ) ;
}
F_21 ( V_2 ) ;
F_4 ( & V_2 -> V_44 , V_5 ) ;
}
}
int F_29 ( struct V_1 * V_2 , unsigned int V_40 , void * V_31 )
{
struct F_23 * V_32 ;
int V_41 ;
if ( V_40 >= 16 )
goto V_52;
V_32 = V_2 -> V_37 + V_40 ;
V_41 = - V_53 ;
F_25 ( & V_2 -> V_44 ) ;
if ( V_32 -> V_31 == V_31 ) {
V_2 -> V_47 &= ~ ( 1 << V_40 ) ;
V_2 -> V_50 &= ~ ( 1 << V_40 ) ;
F_15 ( V_2 ) ;
F_3 ( V_2 , V_48 , V_2 -> V_47 ) ;
F_3 ( V_2 , V_51 , V_2 -> V_50 ) ;
F_21 ( V_2 ) ;
V_32 -> V_38 = NULL ;
V_32 -> V_31 = NULL ;
V_41 = 0 ;
}
F_26 ( & V_2 -> V_44 ) ;
return V_41 ;
V_52:
F_30 ( V_54 L_1 , V_40 ) ;
return - V_42 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
struct V_57 * V_58 ;
int V_41 = - V_59 ;
V_58 = F_32 ( sizeof( struct V_57 ) , V_60 ) ;
if ( V_58 ) {
V_58 -> V_2 = V_2 ;
V_58 -> V_56 = V_56 ;
V_41 = V_56 -> V_61 ( V_58 ) ;
if ( V_41 == 0 ) {
F_33 ( & V_58 -> V_62 , & V_2 -> V_63 ) ;
F_33 ( & V_58 -> V_64 , & V_56 -> V_63 ) ;
} else {
F_34 ( V_58 ) ;
}
}
return V_41 ;
}
static void F_35 ( struct V_57 * V_58 )
{
V_58 -> V_56 -> remove ( V_58 ) ;
F_36 ( & V_58 -> V_62 ) ;
F_36 ( & V_58 -> V_64 ) ;
F_34 ( V_58 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
unsigned long V_65 ;
V_65 = F_38 () ;
if ( ! V_65 ) {
F_39 ( V_65 ) ;
return V_66 ;
}
F_3 ( V_2 , V_48 , V_67 ) ;
F_3 ( V_2 , V_51 , V_67 ) ;
F_3 ( V_2 , V_36 , 0xffff ) ;
F_3 ( V_2 , V_36 , 0 ) ;
F_3 ( V_2 , V_21 , V_20 ) ;
F_3 ( V_2 , V_21 , V_20 | V_26 ) ;
while ( ( F_7 ( V_2 , V_27 ) & V_28 ) == 0 ) ;
F_3 ( V_2 , V_21 , 0 ) ;
F_3 ( V_2 , V_48 , 0 ) ;
F_3 ( V_2 , V_51 , 0 ) ;
F_3 ( V_2 , V_36 , 0xffff ) ;
F_3 ( V_2 , V_36 , 0 ) ;
return F_39 ( V_65 ) ;
}
static void F_40 ( struct V_68 * V_58 )
{
struct V_1 * V_2 = F_41 ( V_58 ) ;
F_34 ( V_2 ) ;
}
static int F_42 ( struct V_69 * V_69 )
{
struct V_1 * V_2 ;
struct V_55 * V_56 ;
unsigned int V_70 ;
int V_41 = - V_71 ;
int V_72 ;
F_43 ( V_69 ) ;
V_70 = F_44 ( V_69 , V_73 ) ;
if ( V_70 != V_74 && V_70 != V_75 && V_70 != V_76 ) {
F_30 ( V_77 L_2 , V_70 ) ;
goto V_78;
}
V_2 = F_45 ( sizeof( struct V_1 ) , V_60 ) ;
V_41 = - V_59 ;
if ( ! V_2 )
goto V_78;
V_2 -> V_58 . V_79 = & V_80 ;
V_2 -> V_58 . V_81 = & V_69 -> V_82 ;
F_46 ( & V_2 -> V_58 , L_3 ) ;
F_47 ( & V_2 -> V_44 ) ;
F_47 ( & V_2 -> V_6 ) ;
F_48 ( & V_2 -> V_18 , 1 ) ;
V_2 -> V_70 = V_70 ;
V_2 -> V_69 = V_69 ;
V_2 -> V_32 = F_37 ( V_2 ) ;
if ( V_2 -> V_32 == V_66 ) {
F_30 ( V_54 L_4 ) ;
V_41 = - V_71 ;
goto V_83;
}
V_2 -> V_17 . V_84 = - 1 ;
if ( V_69 -> V_85 != 0 ) {
V_2 -> V_17 . V_86 = F_49 ( & V_2 -> V_58 ) ;
V_2 -> V_17 . V_84 = V_69 -> V_85 ;
V_2 -> V_17 . V_87 = 10 ;
V_2 -> V_17 . V_9 = F_8 ;
V_2 -> V_17 . V_88 = F_10 ;
V_2 -> V_17 . V_89 = F_11 ;
V_2 -> V_17 . V_90 = F_12 ;
V_41 = F_50 ( & V_2 -> V_17 ) ;
if ( V_41 )
goto V_83;
} else
F_51 ( & V_2 -> V_58 , L_5 ) ;
V_41 = F_52 ( V_2 -> V_32 , F_23 , V_91 ,
L_6 , V_2 ) ;
if ( V_41 ) {
F_30 ( V_54 L_7 ,
V_2 -> V_32 , V_41 ) ;
goto V_92;
}
F_53 ( V_69 , V_2 ) ;
V_41 = F_54 ( & V_2 -> V_58 ) ;
if ( V_41 )
goto V_93;
F_55 ( & V_2 -> V_63 ) ;
F_56 ( & V_94 ) ;
F_33 ( & V_2 -> V_95 , & V_96 ) ;
F_57 (drv, &ucb1x00_drivers, node) {
F_31 ( V_2 , V_56 ) ;
}
F_58 ( & V_94 ) ;
goto V_4;
V_93:
F_59 ( V_2 -> V_32 , V_2 ) ;
V_92:
if ( V_2 -> V_17 . V_84 != - 1 )
V_72 = F_60 ( & V_2 -> V_17 ) ;
V_83:
F_34 ( V_2 ) ;
V_78:
F_61 ( V_69 ) ;
V_4:
return V_41 ;
}
static void F_62 ( struct V_69 * V_69 )
{
struct V_1 * V_2 = F_63 ( V_69 ) ;
struct V_97 * V_98 , * V_99 ;
int V_41 ;
F_56 ( & V_94 ) ;
F_36 ( & V_2 -> V_95 ) ;
F_64 (l, n, &ucb->devs) {
struct V_57 * V_58 = F_65 ( V_98 , struct V_57 , V_62 ) ;
F_35 ( V_58 ) ;
}
F_58 ( & V_94 ) ;
if ( V_2 -> V_17 . V_84 != - 1 ) {
V_41 = F_60 ( & V_2 -> V_17 ) ;
if ( V_41 )
F_66 ( & V_2 -> V_58 , L_8 , V_41 ) ;
}
F_59 ( V_2 -> V_32 , V_2 ) ;
F_67 ( & V_2 -> V_58 ) ;
}
int F_68 ( struct V_55 * V_56 )
{
struct V_1 * V_2 ;
F_55 ( & V_56 -> V_63 ) ;
F_56 ( & V_94 ) ;
F_33 ( & V_56 -> V_95 , & V_100 ) ;
F_57 (ucb, &ucb1x00_devices, node) {
F_31 ( V_2 , V_56 ) ;
}
F_58 ( & V_94 ) ;
return 0 ;
}
void F_69 ( struct V_55 * V_56 )
{
struct V_97 * V_99 , * V_98 ;
F_56 ( & V_94 ) ;
F_36 ( & V_56 -> V_95 ) ;
F_64 (l, n, &drv->devs) {
struct V_57 * V_58 = F_65 ( V_98 , struct V_57 , V_64 ) ;
F_35 ( V_58 ) ;
}
F_58 ( & V_94 ) ;
}
static int F_70 ( struct V_69 * V_69 , T_2 V_101 )
{
struct V_1 * V_2 = F_63 ( V_69 ) ;
struct V_57 * V_58 ;
F_56 ( & V_94 ) ;
F_57 (dev, &ucb->devs, dev_node) {
if ( V_58 -> V_56 -> V_102 )
V_58 -> V_56 -> V_102 ( V_58 , V_101 ) ;
}
F_58 ( & V_94 ) ;
return 0 ;
}
static int F_71 ( struct V_69 * V_69 )
{
struct V_1 * V_2 = F_63 ( V_69 ) ;
struct V_57 * V_58 ;
F_3 ( V_2 , V_8 , V_2 -> V_7 ) ;
F_56 ( & V_94 ) ;
F_57 (dev, &ucb->devs, dev_node) {
if ( V_58 -> V_56 -> V_103 )
V_58 -> V_56 -> V_103 ( V_58 ) ;
}
F_58 ( & V_94 ) ;
return 0 ;
}
static int T_3 F_72 ( void )
{
int V_41 = F_73 ( & V_80 ) ;
if ( V_41 == 0 ) {
V_41 = F_74 ( & V_55 ) ;
if ( V_41 )
F_75 ( & V_80 ) ;
}
return V_41 ;
}
static void T_4 F_76 ( void )
{
F_77 ( & V_55 ) ;
F_75 ( & V_80 ) ;
}
