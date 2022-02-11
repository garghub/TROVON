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
T_1 V_14 ;
int V_15 ;
struct V_5 * V_6 = F_9 ( V_13 ) ;
if ( ! V_6 -> V_16 ) {
F_10 ( V_6 -> V_17 , 0 ) ;
return 0 ;
}
V_14 = V_18 << V_19 ;
V_15 = F_11 ( V_6 -> V_16 , V_6 -> V_20 ,
V_21 , V_14 ) ;
return V_15 ;
}
static int F_12 ( struct V_6 * V_13 )
{
T_1 V_14 ;
T_1 V_22 ;
int V_15 ;
unsigned long V_7 ;
struct V_5 * V_6 = F_9 ( V_13 ) ;
if ( ! V_6 -> V_16 ) {
F_10 ( V_6 -> V_17 , 1 ) ;
return 0 ;
}
V_7 = F_6 ( V_6 -> V_10 ) ;
if ( ! V_7 ) {
F_7 ( V_6 -> V_12 , L_2 ) ;
return - V_23 ;
}
V_7 = V_7 / 1000000 ;
V_22 = V_24 |
V_25 ;
V_14 = V_26 << V_19 ;
V_14 |= V_7 << V_27 ;
V_15 = F_11 ( V_6 -> V_16 , V_6 -> V_20 ,
V_22 , V_14 ) ;
return V_15 ;
}
static int F_13 ( struct V_5 * V_6 )
{
T_1 V_14 ;
unsigned long V_28 ;
V_28 = V_29 + F_14 ( V_30 ) ;
do {
F_15 () ;
V_14 = F_1 ( V_6 -> V_31 , V_32 ) ;
if ( V_14 & V_33 )
return 0 ;
} while ( ! F_16 ( V_29 , V_28 ) );
F_7 ( V_6 -> V_12 , L_3 ) ;
return - V_34 ;
}
static int F_17 ( struct V_5 * V_6 )
{
T_1 V_14 ;
struct V_4 * V_35 ;
V_35 = F_5 ( V_6 ) ;
if ( ! V_35 )
return - V_23 ;
V_14 = F_1 ( V_6 -> V_31 , V_36 ) ;
V_14 &= ~ V_37 ;
V_14 |= V_35 -> V_38 << V_39 ;
F_3 ( V_6 -> V_31 , V_36 , V_14 ) ;
V_14 = F_1 ( V_6 -> V_31 , V_40 ) ;
V_14 &= ~ V_41 ;
V_14 |= V_35 -> V_42 << V_43 ;
F_3 ( V_6 -> V_31 , V_40 , V_14 ) ;
V_14 = F_1 ( V_6 -> V_31 , V_36 ) ;
V_14 &= ~ V_44 ;
V_14 |= V_35 -> V_45 << V_46 ;
F_3 ( V_6 -> V_31 , V_36 , V_14 ) ;
V_14 = F_1 ( V_6 -> V_31 , V_47 ) ;
V_14 &= ~ V_48 ;
V_14 |= V_35 -> V_49 << V_50 ;
F_3 ( V_6 -> V_31 , V_47 , V_14 ) ;
V_14 = F_1 ( V_6 -> V_31 , V_51 ) ;
V_14 &= ~ V_52 ;
V_14 |= V_35 -> V_53 << V_54 ;
F_3 ( V_6 -> V_31 , V_51 , V_14 ) ;
F_3 ( V_6 -> V_31 , V_55 , V_56 ) ;
return F_13 ( V_6 ) ;
}
static int F_18 ( struct V_6 * V_13 )
{
struct V_5 * V_6 = F_9 ( V_13 ) ;
T_1 V_14 ;
int V_15 = 0 ;
F_19 ( V_6 ) ;
if ( F_20 ( V_6 -> V_12 -> V_57 , L_4 ) ) {
if ( ! V_6 -> V_58 ) {
F_21 ( V_6 -> V_17 , 0x96 ) ;
return 0 ;
}
V_14 = 0x96 << V_59 ;
V_15 = F_11 ( V_6 -> V_58 , V_6 -> V_60 ,
V_61 , V_14 ) ;
return V_15 ;
}
V_14 = F_1 ( V_6 -> V_31 , V_40 ) ;
if ( V_14 & V_62 ) {
V_14 &= ~ V_62 ;
F_3 ( V_6 -> V_31 , V_40 , V_14 ) ;
V_15 = F_13 ( V_6 ) ;
}
V_14 = F_1 ( V_6 -> V_31 , V_32 ) ;
if ( ( V_14 & V_33 ) && F_20 ( V_6 -> V_12 -> V_57 ,
L_5 ) )
return V_15 ;
V_15 = F_17 ( V_6 ) ;
if ( V_15 ) {
F_22 ( V_6 ) ;
return - V_23 ;
}
return V_15 ;
}
static int F_23 ( struct V_6 * V_13 )
{
struct V_5 * V_6 = F_9 ( V_13 ) ;
T_1 V_14 ;
unsigned long V_28 ;
if ( F_20 ( V_6 -> V_12 -> V_57 , L_5 ) &&
! V_6 -> V_63 )
return 0 ;
if ( ! F_20 ( V_6 -> V_12 -> V_57 , L_4 ) ) {
V_14 = F_1 ( V_6 -> V_31 , V_40 ) ;
V_14 |= V_62 ;
F_3 ( V_6 -> V_31 , V_40 , V_14 ) ;
V_28 = V_29 + F_14 ( V_64 ) ;
do {
F_15 () ;
V_14 = F_1 ( V_6 -> V_31 , V_32 ) ;
if ( ( V_14 & V_65 ) && ( V_14 & V_66 ) )
break;
} while ( ! F_16 ( V_29 , V_28 ) );
if ( ! ( V_14 & V_65 ) || ! ( V_14 & V_66 ) ) {
F_7 ( V_6 -> V_12 , L_6 ,
V_14 ) ;
return - V_34 ;
}
}
if ( F_20 ( V_6 -> V_12 -> V_57 , L_5 ) ) {
F_11 ( V_6 -> V_63 , V_6 -> V_67 ,
V_68 , V_68 ) ;
F_11 ( V_6 -> V_63 , V_6 -> V_67 ,
V_68 , 0 ) ;
}
F_22 ( V_6 ) ;
return 0 ;
}
static int F_24 ( struct V_5 * V_6 )
{
struct V_69 * V_69 ;
struct V_70 * V_12 = V_6 -> V_12 ;
struct V_71 * V_72 = V_12 -> V_57 ;
V_6 -> V_73 = F_25 ( V_12 , L_7 ) ;
if ( F_26 ( V_6 -> V_73 ) ) {
F_7 ( V_12 , L_8 ) ;
if ( ! F_20 ( V_72 , L_5 ) )
return F_27 ( V_6 -> V_73 ) ;
}
if ( ! F_20 ( V_72 , L_5 ) ) {
V_6 -> V_74 = F_25 ( V_12 , L_9 ) ;
if ( F_26 ( V_6 -> V_74 ) ) {
F_7 ( V_12 , L_10 ) ;
return F_27 ( V_6 -> V_74 ) ;
}
} else {
V_6 -> V_74 = F_28 ( - V_75 ) ;
}
if ( ! F_20 ( V_72 , L_4 ) ||
V_6 -> V_16 ) {
V_6 -> V_10 = F_25 ( V_12 , L_11 ) ;
if ( F_26 ( V_6 -> V_10 ) ) {
F_7 ( V_12 , L_12 ) ;
return - V_23 ;
}
}
if ( F_20 ( V_72 , L_4 ) ) {
V_69 = F_25 ( V_12 , L_13 ) ;
if ( F_26 ( V_69 ) ) {
F_7 ( V_12 , L_14 ) ;
return F_27 ( V_69 ) ;
}
F_29 ( V_69 , 1500000000 ) ;
V_69 = F_25 ( V_12 , L_15 ) ;
if ( F_26 ( V_69 ) ) {
F_7 ( V_12 , L_16 ) ;
return F_27 ( V_69 ) ;
}
F_29 ( V_69 , 100000000 ) ;
V_69 = F_25 ( V_12 , L_17 ) ;
if ( F_26 ( V_69 ) ) {
F_7 ( V_12 , L_18 ) ;
return F_27 ( V_69 ) ;
}
F_29 ( V_69 , 100000000 ) ;
V_6 -> V_76 = F_25 ( V_12 , L_19 ) ;
if ( F_26 ( V_6 -> V_76 ) ) {
F_7 ( V_12 , L_20 ) ;
return F_27 ( V_6 -> V_76 ) ;
}
} else {
V_6 -> V_76 = F_28 ( - V_75 ) ;
}
return 0 ;
}
static int F_30 ( struct V_5 * V_6 )
{
struct V_70 * V_12 = V_6 -> V_12 ;
struct V_71 * V_72 = V_12 -> V_57 ;
struct V_71 * V_77 ;
struct V_78 * V_79 ;
V_6 -> V_16 = F_31 ( V_72 ,
L_21 ) ;
if ( F_26 ( V_6 -> V_16 ) ) {
F_32 ( V_12 ,
L_22 ) ;
V_6 -> V_16 = NULL ;
} else {
if ( F_33 ( V_72 ,
L_21 , 1 ,
& V_6 -> V_20 ) ) {
F_7 ( V_12 , L_23 ) ;
return - V_23 ;
}
}
if ( ! V_6 -> V_16 ) {
V_77 = F_34 ( V_72 , L_24 , 0 ) ;
if ( ! V_77 ) {
F_7 ( V_12 , L_25 ) ;
return - V_23 ;
}
V_79 = F_35 ( V_77 ) ;
if ( ! V_79 ) {
F_7 ( V_12 , L_26 ) ;
return - V_23 ;
}
V_6 -> V_17 = & V_79 -> V_12 ;
}
if ( F_20 ( V_72 , L_4 ) ) {
V_6 -> V_58 = F_31 ( V_72 ,
L_27 ) ;
if ( F_26 ( V_6 -> V_58 ) ) {
F_32 ( V_12 ,
L_28 ) ;
V_6 -> V_58 = NULL ;
} else {
if ( F_33 ( V_72 ,
L_27 , 1 ,
& V_6 -> V_60 ) ) {
F_7 ( V_12 ,
L_29 ) ;
return - V_23 ;
}
}
}
if ( F_20 ( V_72 , L_5 ) ) {
V_6 -> V_63 = F_31 ( V_72 ,
L_30 ) ;
if ( F_26 ( V_6 -> V_63 ) ) {
F_36 ( V_12 ,
L_31 ) ;
V_6 -> V_63 = NULL ;
} else {
if ( F_33 ( V_72 ,
L_30 , 1 ,
& V_6 -> V_67 ) ) {
F_7 ( V_12 ,
L_32 ) ;
return - V_23 ;
}
}
}
return 0 ;
}
static int F_37 ( struct V_5 * V_6 )
{
struct V_80 * V_81 ;
const struct V_82 * V_83 ;
struct V_70 * V_12 = V_6 -> V_12 ;
struct V_71 * V_72 = V_12 -> V_57 ;
struct V_78 * V_84 = F_38 ( V_12 ) ;
if ( F_20 ( V_72 , L_4 ) )
return 0 ;
V_83 = F_39 ( V_85 , V_12 ) ;
if ( ! V_83 )
return - V_23 ;
V_6 -> V_9 = (struct V_8 * ) V_83 -> V_3 ;
if ( ! V_6 -> V_9 ) {
F_7 ( V_12 , L_33 ) ;
return - V_23 ;
}
V_81 = F_40 ( V_84 , V_86 ,
L_34 ) ;
V_6 -> V_31 = F_41 ( V_12 , V_81 ) ;
if ( F_26 ( V_6 -> V_31 ) )
return F_27 ( V_6 -> V_31 ) ;
return 0 ;
}
static int F_42 ( struct V_78 * V_84 )
{
struct V_5 * V_6 ;
struct V_6 * V_87 ;
struct V_88 * V_88 ;
struct V_71 * V_72 = V_84 -> V_12 . V_57 ;
struct V_70 * V_12 = & V_84 -> V_12 ;
int V_15 ;
V_6 = F_43 ( V_12 , sizeof( * V_6 ) , V_89 ) ;
if ( ! V_6 )
return - V_90 ;
V_6 -> V_12 = V_12 ;
V_15 = F_37 ( V_6 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_30 ( V_6 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_24 ( V_6 ) ;
if ( V_15 )
return V_15 ;
F_44 ( V_84 , V_6 ) ;
F_45 ( V_12 ) ;
if ( F_20 ( V_72 , L_5 ) ) {
if ( ! F_26 ( V_6 -> V_73 ) ) {
F_46 ( V_6 -> V_73 ) ;
V_6 -> V_91 = true ;
}
}
V_87 = F_47 ( V_12 , NULL , & V_92 ) ;
if ( F_26 ( V_87 ) )
return F_27 ( V_87 ) ;
F_48 ( V_87 , V_6 ) ;
F_8 ( V_87 ) ;
V_88 = F_49 ( V_12 , V_93 ) ;
if ( F_26 ( V_88 ) )
return F_27 ( V_88 ) ;
return 0 ;
}
static int F_50 ( struct V_78 * V_84 )
{
F_51 ( & V_84 -> V_12 ) ;
return 0 ;
}
static int F_19 ( struct V_5 * V_6 )
{
int V_15 = 0 ;
if ( ! F_26 ( V_6 -> V_73 ) ) {
V_15 = F_46 ( V_6 -> V_73 ) ;
if ( V_15 ) {
F_7 ( V_6 -> V_12 , L_35 , V_15 ) ;
return V_15 ;
}
}
if ( ! F_26 ( V_6 -> V_74 ) ) {
V_15 = F_46 ( V_6 -> V_74 ) ;
if ( V_15 ) {
F_7 ( V_6 -> V_12 , L_36 , V_15 ) ;
goto V_94;
}
}
if ( ! F_26 ( V_6 -> V_76 ) ) {
V_15 = F_46 ( V_6 -> V_76 ) ;
if ( V_15 ) {
F_7 ( V_6 -> V_12 , L_37 , V_15 ) ;
goto V_95;
}
}
return 0 ;
V_95:
if ( ! F_26 ( V_6 -> V_74 ) )
F_52 ( V_6 -> V_74 ) ;
V_94:
if ( ! F_26 ( V_6 -> V_73 ) )
F_52 ( V_6 -> V_73 ) ;
return V_15 ;
}
static void F_22 ( struct V_5 * V_6 )
{
if ( ! F_26 ( V_6 -> V_74 ) )
F_52 ( V_6 -> V_74 ) ;
if ( ! F_26 ( V_6 -> V_73 ) ) {
F_52 ( V_6 -> V_73 ) ;
if ( V_6 -> V_91 ) {
F_52 ( V_6 -> V_73 ) ;
V_6 -> V_91 = false ;
}
}
if ( ! F_26 ( V_6 -> V_76 ) )
F_52 ( V_6 -> V_76 ) ;
}
