static inline T_1 F_1 ( void T_2 * V_1 , unsigned V_2 )
{
return F_2 ( V_1 + V_2 ) ;
}
static inline void F_3 ( void T_2 * V_1 , unsigned V_2 ,
T_1 V_3 )
{
F_4 ( V_3 , V_1 + V_2 ) ;
}
static struct V_4 * F_5 ( struct V_5 * V_6 )
{
unsigned long V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
V_7 = F_6 ( V_6 -> V_10 ) ;
for (; V_9 -> V_7 ; V_9 ++ ) {
if ( V_7 == V_9 -> V_7 )
return & V_9 -> V_11 ;
}
F_7 ( V_6 -> V_12 , L_1 , V_7 ) ;
return NULL ;
}
static int F_8 ( struct V_6 * V_13 )
{
struct V_5 * V_6 = F_9 ( V_13 ) ;
F_10 ( V_6 -> V_14 , 0 ) ;
return 0 ;
}
static int F_11 ( struct V_6 * V_13 )
{
struct V_5 * V_6 = F_9 ( V_13 ) ;
F_10 ( V_6 -> V_14 , 1 ) ;
return 0 ;
}
static int F_12 ( struct V_5 * V_6 )
{
T_1 V_15 ;
unsigned long V_16 ;
V_16 = V_17 + F_13 ( V_18 ) ;
do {
F_14 () ;
V_15 = F_1 ( V_6 -> V_19 , V_20 ) ;
if ( V_15 & V_21 )
return 0 ;
} while ( ! F_15 ( V_17 , V_16 ) );
F_7 ( V_6 -> V_12 , L_2 ) ;
return - V_22 ;
}
static int F_16 ( struct V_5 * V_6 )
{
T_1 V_15 ;
struct V_4 * V_23 ;
V_23 = F_5 ( V_6 ) ;
if ( ! V_23 )
return - V_24 ;
V_15 = F_1 ( V_6 -> V_19 , V_25 ) ;
V_15 &= ~ V_26 ;
V_15 |= V_23 -> V_27 << V_28 ;
F_3 ( V_6 -> V_19 , V_25 , V_15 ) ;
V_15 = F_1 ( V_6 -> V_19 , V_29 ) ;
V_15 &= ~ V_30 ;
V_15 |= V_23 -> V_31 << V_32 ;
F_3 ( V_6 -> V_19 , V_29 , V_15 ) ;
V_15 = F_1 ( V_6 -> V_19 , V_25 ) ;
V_15 &= ~ V_33 ;
V_15 |= V_23 -> V_34 << V_35 ;
F_3 ( V_6 -> V_19 , V_25 , V_15 ) ;
V_15 = F_1 ( V_6 -> V_19 , V_36 ) ;
V_15 &= ~ V_37 ;
V_15 |= V_23 -> V_38 << V_39 ;
F_3 ( V_6 -> V_19 , V_36 , V_15 ) ;
V_15 = F_1 ( V_6 -> V_19 , V_40 ) ;
V_15 &= ~ V_41 ;
V_15 |= V_23 -> V_42 << V_43 ;
F_3 ( V_6 -> V_19 , V_40 , V_15 ) ;
F_3 ( V_6 -> V_19 , V_44 , V_45 ) ;
return F_12 ( V_6 ) ;
}
static int F_17 ( struct V_6 * V_13 )
{
struct V_5 * V_6 = F_9 ( V_13 ) ;
T_1 V_15 ;
int V_46 = 0 ;
if ( F_18 ( V_6 -> V_12 -> V_47 , L_3 ) ) {
F_19 ( V_6 -> V_14 , 0x96 ) ;
return 0 ;
}
V_15 = F_1 ( V_6 -> V_19 , V_29 ) ;
if ( V_15 & V_48 ) {
V_15 &= ~ V_48 ;
F_3 ( V_6 -> V_19 , V_29 , V_15 ) ;
V_46 = F_12 ( V_6 ) ;
}
V_15 = F_1 ( V_6 -> V_19 , V_20 ) ;
if ( ! ( V_15 & V_21 ) )
if ( F_16 ( V_6 ) )
return - V_24 ;
return V_46 ;
}
static int F_20 ( struct V_6 * V_13 )
{
struct V_5 * V_6 = F_9 ( V_13 ) ;
T_1 V_15 ;
unsigned long V_16 ;
if ( F_18 ( V_6 -> V_12 -> V_47 , L_4 ) ||
F_18 ( V_6 -> V_12 -> V_47 , L_3 ) )
return 0 ;
V_15 = F_1 ( V_6 -> V_19 , V_29 ) ;
V_15 |= V_48 ;
F_3 ( V_6 -> V_19 , V_29 , V_15 ) ;
V_16 = V_17 + F_13 ( V_49 ) ;
do {
F_14 () ;
V_15 = F_1 ( V_6 -> V_19 , V_20 ) ;
if ( ( V_15 & V_50 ) && ( V_15 & V_51 ) )
break;
} while ( ! F_15 ( V_17 , V_16 ) );
if ( ! ( V_15 & V_50 ) || ! ( V_15 & V_51 ) ) {
F_7 ( V_6 -> V_12 , L_5 ,
V_15 ) ;
return - V_22 ;
}
return 0 ;
}
static int F_21 ( struct V_52 * V_53 )
{
struct V_5 * V_6 ;
struct V_6 * V_54 ;
struct V_55 * V_55 ;
struct V_56 * V_57 ;
struct V_58 * V_59 = V_53 -> V_12 . V_47 ;
struct V_58 * V_60 ;
struct V_52 * V_61 ;
const struct V_62 * V_63 ;
struct V_64 * V_64 ;
V_6 = F_22 ( & V_53 -> V_12 , sizeof( * V_6 ) , V_65 ) ;
if ( ! V_6 )
return - V_66 ;
V_6 -> V_12 = & V_53 -> V_12 ;
F_23 ( & V_6 -> V_67 ) ;
if ( ! F_18 ( V_59 , L_3 ) ) {
V_63 = F_24 ( V_68 , & V_53 -> V_12 ) ;
if ( ! V_63 )
return - V_24 ;
V_6 -> V_9 = (struct V_8 * ) V_63 -> V_3 ;
if ( ! V_6 -> V_9 ) {
F_7 ( & V_53 -> V_12 , L_6 ) ;
return - V_24 ;
}
V_57 = F_25 ( V_53 , V_69 ,
L_7 ) ;
V_6 -> V_19 = F_26 ( & V_53 -> V_12 , V_57 ) ;
if ( F_27 ( V_6 -> V_19 ) )
return F_28 ( V_6 -> V_19 ) ;
V_6 -> V_10 = F_29 ( V_6 -> V_12 , L_8 ) ;
if ( F_27 ( V_6 -> V_10 ) ) {
F_7 ( & V_53 -> V_12 , L_9 ) ;
return - V_24 ;
}
}
V_6 -> V_70 = F_29 ( V_6 -> V_12 , L_10 ) ;
if ( F_27 ( V_6 -> V_70 ) ) {
F_7 ( & V_53 -> V_12 , L_11 ) ;
if ( ! F_18 ( V_59 , L_4 ) )
return F_28 ( V_6 -> V_70 ) ;
}
if ( ! F_18 ( V_59 , L_4 ) ) {
V_6 -> V_71 = F_29 ( V_6 -> V_12 , L_12 ) ;
if ( F_27 ( V_6 -> V_71 ) ) {
F_7 ( & V_53 -> V_12 , L_13 ) ;
return F_28 ( V_6 -> V_71 ) ;
}
} else {
V_6 -> V_71 = F_30 ( - V_72 ) ;
}
if ( F_18 ( V_59 , L_3 ) ) {
V_64 = F_29 ( V_6 -> V_12 , L_14 ) ;
if ( F_27 ( V_64 ) ) {
F_7 ( & V_53 -> V_12 , L_15 ) ;
return F_28 ( V_64 ) ;
}
F_31 ( V_64 , 1500000000 ) ;
V_64 = F_29 ( V_6 -> V_12 , L_16 ) ;
if ( F_27 ( V_64 ) ) {
F_7 ( & V_53 -> V_12 , L_17 ) ;
return F_28 ( V_64 ) ;
}
F_31 ( V_64 , 100000000 ) ;
V_64 = F_29 ( V_6 -> V_12 , L_18 ) ;
if ( F_27 ( V_64 ) ) {
F_7 ( & V_53 -> V_12 , L_19 ) ;
return F_28 ( V_64 ) ;
}
F_31 ( V_64 , 100000000 ) ;
V_6 -> V_73 = F_29 ( V_6 -> V_12 , L_20 ) ;
if ( F_27 ( V_6 -> V_73 ) ) {
F_7 ( & V_53 -> V_12 , L_21 ) ;
return F_28 ( V_6 -> V_73 ) ;
}
} else {
V_6 -> V_73 = F_30 ( - V_72 ) ;
}
V_60 = F_32 ( V_59 , L_22 , 0 ) ;
if ( ! V_60 ) {
F_7 ( & V_53 -> V_12 , L_23 ) ;
return - V_24 ;
}
V_61 = F_33 ( V_60 ) ;
if ( ! V_61 ) {
F_7 ( & V_53 -> V_12 , L_24 ) ;
return - V_24 ;
}
V_6 -> V_14 = & V_61 -> V_12 ;
F_10 ( V_6 -> V_14 , 0 ) ;
F_34 ( V_53 , V_6 ) ;
F_35 ( V_6 -> V_12 ) ;
V_54 = F_36 ( V_6 -> V_12 , NULL , & V_74 ) ;
if ( F_27 ( V_54 ) )
return F_28 ( V_54 ) ;
F_37 ( V_54 , V_6 ) ;
V_55 = F_38 ( V_6 -> V_12 ,
V_75 ) ;
if ( F_27 ( V_55 ) )
return F_28 ( V_55 ) ;
F_39 ( & V_53 -> V_12 ) ;
return 0 ;
}
static int F_40 ( struct V_52 * V_53 )
{
if ( ! F_41 ( & V_53 -> V_12 ) )
F_42 ( & V_53 -> V_12 ) ;
F_43 ( & V_53 -> V_12 ) ;
return 0 ;
}
static int F_44 ( struct V_5 * V_6 )
{
if ( ! F_27 ( V_6 -> V_70 ) && ! V_6 -> V_76 ) {
int V_46 ;
V_46 = F_45 ( V_6 -> V_70 ) ;
if ( V_46 ) {
F_7 ( V_6 -> V_12 , L_25 , V_46 ) ;
return V_46 ;
}
V_6 -> V_76 = true ;
}
return 0 ;
}
static void F_46 ( struct V_5 * V_6 )
{
if ( ! F_27 ( V_6 -> V_70 ) )
F_47 ( V_6 -> V_70 ) ;
V_6 -> V_76 = false ;
}
static int F_48 ( struct V_5 * V_6 )
{
int V_46 = 0 ;
unsigned long V_77 ;
F_49 ( & V_6 -> V_67 , V_77 ) ;
if ( V_6 -> V_78 )
goto V_79;
V_46 = F_44 ( V_6 ) ;
if ( V_46 )
goto V_79;
if ( ! F_27 ( V_6 -> V_71 ) ) {
V_46 = F_45 ( V_6 -> V_71 ) ;
if ( V_46 ) {
F_7 ( V_6 -> V_12 , L_26 , V_46 ) ;
goto V_80;
}
}
if ( ! F_27 ( V_6 -> V_73 ) ) {
V_46 = F_45 ( V_6 -> V_73 ) ;
if ( V_46 ) {
F_7 ( V_6 -> V_12 , L_27 , V_46 ) ;
goto V_81;
}
}
V_6 -> V_78 = true ;
F_50 ( & V_6 -> V_67 , V_77 ) ;
return 0 ;
V_81:
if ( ! F_27 ( V_6 -> V_71 ) )
F_47 ( V_6 -> V_71 ) ;
V_80:
if ( ! F_27 ( V_6 -> V_70 ) )
F_47 ( V_6 -> V_70 ) ;
F_46 ( V_6 ) ;
V_79:
F_50 ( & V_6 -> V_67 , V_77 ) ;
return V_46 ;
}
static void F_51 ( struct V_5 * V_6 )
{
unsigned long V_77 ;
F_49 ( & V_6 -> V_67 , V_77 ) ;
if ( ! V_6 -> V_78 ) {
F_50 ( & V_6 -> V_67 , V_77 ) ;
return;
}
if ( ! F_27 ( V_6 -> V_71 ) )
F_47 ( V_6 -> V_71 ) ;
if ( ! F_18 ( V_6 -> V_12 -> V_47 , L_4 ) )
F_46 ( V_6 ) ;
if ( ! F_27 ( V_6 -> V_73 ) )
F_47 ( V_6 -> V_73 ) ;
V_6 -> V_78 = false ;
F_50 ( & V_6 -> V_67 , V_77 ) ;
}
static int F_52 ( struct V_82 * V_12 )
{
struct V_5 * V_6 = F_53 ( V_12 ) ;
F_51 ( V_6 ) ;
return 0 ;
}
static int F_54 ( struct V_82 * V_12 )
{
struct V_5 * V_6 = F_53 ( V_12 ) ;
int V_46 = 0 ;
V_46 = F_48 ( V_6 ) ;
return V_46 ;
}
static int F_55 ( struct V_82 * V_12 )
{
struct V_5 * V_6 = F_53 ( V_12 ) ;
F_51 ( V_6 ) ;
return 0 ;
}
static int F_56 ( struct V_82 * V_12 )
{
struct V_5 * V_6 = F_53 ( V_12 ) ;
int V_46 ;
V_46 = F_48 ( V_6 ) ;
if ( V_46 )
return V_46 ;
F_43 ( V_12 ) ;
F_57 ( V_12 ) ;
F_35 ( V_12 ) ;
return 0 ;
}
