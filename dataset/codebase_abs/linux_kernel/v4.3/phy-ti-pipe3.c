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
F_18 ( V_6 ) ;
if ( F_19 ( V_6 -> V_12 -> V_47 , L_3 ) ) {
F_20 ( V_6 -> V_14 , 0x96 ) ;
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
static int F_21 ( struct V_6 * V_13 )
{
struct V_5 * V_6 = F_9 ( V_13 ) ;
T_1 V_15 ;
unsigned long V_16 ;
if ( F_19 ( V_6 -> V_12 -> V_47 , L_4 ) &&
! V_6 -> V_49 )
return 0 ;
if ( ! F_19 ( V_6 -> V_12 -> V_47 , L_3 ) ) {
V_15 = F_1 ( V_6 -> V_19 , V_29 ) ;
V_15 |= V_48 ;
F_3 ( V_6 -> V_19 , V_29 , V_15 ) ;
V_16 = V_17 + F_13 ( V_50 ) ;
do {
F_14 () ;
V_15 = F_1 ( V_6 -> V_19 , V_20 ) ;
if ( ( V_15 & V_51 ) && ( V_15 & V_52 ) )
break;
} while ( ! F_15 ( V_17 , V_16 ) );
if ( ! ( V_15 & V_51 ) || ! ( V_15 & V_52 ) ) {
F_7 ( V_6 -> V_12 , L_5 ,
V_15 ) ;
return - V_22 ;
}
}
if ( F_19 ( V_6 -> V_12 -> V_47 , L_4 ) ) {
F_22 ( V_6 -> V_49 , V_6 -> V_53 ,
V_54 , V_54 ) ;
F_22 ( V_6 -> V_49 , V_6 -> V_53 ,
V_54 , 0 ) ;
}
F_23 ( V_6 ) ;
return 0 ;
}
static int F_24 ( struct V_55 * V_56 )
{
struct V_5 * V_6 ;
struct V_6 * V_57 ;
struct V_58 * V_58 ;
struct V_59 * V_60 ;
struct V_61 * V_62 = V_56 -> V_12 . V_47 ;
struct V_61 * V_63 ;
struct V_55 * V_64 ;
const struct V_65 * V_66 ;
struct V_67 * V_67 ;
V_6 = F_25 ( & V_56 -> V_12 , sizeof( * V_6 ) , V_68 ) ;
if ( ! V_6 )
return - V_69 ;
V_6 -> V_12 = & V_56 -> V_12 ;
if ( ! F_19 ( V_62 , L_3 ) ) {
V_66 = F_26 ( V_70 , & V_56 -> V_12 ) ;
if ( ! V_66 )
return - V_24 ;
V_6 -> V_9 = (struct V_8 * ) V_66 -> V_3 ;
if ( ! V_6 -> V_9 ) {
F_7 ( & V_56 -> V_12 , L_6 ) ;
return - V_24 ;
}
V_60 = F_27 ( V_56 , V_71 ,
L_7 ) ;
V_6 -> V_19 = F_28 ( & V_56 -> V_12 , V_60 ) ;
if ( F_29 ( V_6 -> V_19 ) )
return F_30 ( V_6 -> V_19 ) ;
V_6 -> V_10 = F_31 ( V_6 -> V_12 , L_8 ) ;
if ( F_29 ( V_6 -> V_10 ) ) {
F_7 ( & V_56 -> V_12 , L_9 ) ;
return - V_24 ;
}
}
V_6 -> V_72 = F_31 ( V_6 -> V_12 , L_10 ) ;
if ( F_29 ( V_6 -> V_72 ) ) {
F_7 ( & V_56 -> V_12 , L_11 ) ;
if ( ! F_19 ( V_62 , L_4 ) )
return F_30 ( V_6 -> V_72 ) ;
}
if ( ! F_19 ( V_62 , L_4 ) ) {
V_6 -> V_73 = F_31 ( V_6 -> V_12 , L_12 ) ;
if ( F_29 ( V_6 -> V_73 ) ) {
F_7 ( & V_56 -> V_12 , L_13 ) ;
return F_30 ( V_6 -> V_73 ) ;
}
} else {
V_6 -> V_73 = F_32 ( - V_74 ) ;
V_6 -> V_49 = F_33 ( V_62 ,
L_14 ) ;
if ( F_29 ( V_6 -> V_49 ) ) {
F_34 ( & V_56 -> V_12 ,
L_15 ) ;
V_6 -> V_49 = NULL ;
} else {
if ( F_35 ( V_62 ,
L_14 , 1 ,
& V_6 -> V_53 ) ) {
F_7 ( & V_56 -> V_12 ,
L_16 ) ;
return - V_24 ;
}
}
}
if ( F_19 ( V_62 , L_3 ) ) {
V_67 = F_31 ( V_6 -> V_12 , L_17 ) ;
if ( F_29 ( V_67 ) ) {
F_7 ( & V_56 -> V_12 , L_18 ) ;
return F_30 ( V_67 ) ;
}
F_36 ( V_67 , 1500000000 ) ;
V_67 = F_31 ( V_6 -> V_12 , L_19 ) ;
if ( F_29 ( V_67 ) ) {
F_7 ( & V_56 -> V_12 , L_20 ) ;
return F_30 ( V_67 ) ;
}
F_36 ( V_67 , 100000000 ) ;
V_67 = F_31 ( V_6 -> V_12 , L_21 ) ;
if ( F_29 ( V_67 ) ) {
F_7 ( & V_56 -> V_12 , L_22 ) ;
return F_30 ( V_67 ) ;
}
F_36 ( V_67 , 100000000 ) ;
V_6 -> V_75 = F_31 ( V_6 -> V_12 , L_23 ) ;
if ( F_29 ( V_6 -> V_75 ) ) {
F_7 ( & V_56 -> V_12 , L_24 ) ;
return F_30 ( V_6 -> V_75 ) ;
}
} else {
V_6 -> V_75 = F_32 ( - V_74 ) ;
}
V_63 = F_37 ( V_62 , L_25 , 0 ) ;
if ( ! V_63 ) {
F_7 ( & V_56 -> V_12 , L_26 ) ;
return - V_24 ;
}
V_64 = F_38 ( V_63 ) ;
if ( ! V_64 ) {
F_7 ( & V_56 -> V_12 , L_27 ) ;
return - V_24 ;
}
V_6 -> V_14 = & V_64 -> V_12 ;
F_10 ( V_6 -> V_14 , 0 ) ;
F_39 ( V_56 , V_6 ) ;
F_40 ( V_6 -> V_12 ) ;
if ( F_19 ( V_62 , L_4 ) ) {
if ( ! F_29 ( V_6 -> V_72 ) ) {
F_41 ( V_6 -> V_72 ) ;
V_6 -> V_76 = true ;
}
}
V_57 = F_42 ( V_6 -> V_12 , NULL , & V_77 ) ;
if ( F_29 ( V_57 ) )
return F_30 ( V_57 ) ;
F_43 ( V_57 , V_6 ) ;
V_58 = F_44 ( V_6 -> V_12 ,
V_78 ) ;
if ( F_29 ( V_58 ) )
return F_30 ( V_58 ) ;
return 0 ;
}
static int F_45 ( struct V_55 * V_56 )
{
F_46 ( & V_56 -> V_12 ) ;
return 0 ;
}
static int F_18 ( struct V_5 * V_6 )
{
int V_46 = 0 ;
if ( ! F_29 ( V_6 -> V_72 ) ) {
V_46 = F_41 ( V_6 -> V_72 ) ;
if ( V_46 ) {
F_7 ( V_6 -> V_12 , L_28 , V_46 ) ;
return V_46 ;
}
}
if ( ! F_29 ( V_6 -> V_73 ) ) {
V_46 = F_41 ( V_6 -> V_73 ) ;
if ( V_46 ) {
F_7 ( V_6 -> V_12 , L_29 , V_46 ) ;
goto V_79;
}
}
if ( ! F_29 ( V_6 -> V_75 ) ) {
V_46 = F_41 ( V_6 -> V_75 ) ;
if ( V_46 ) {
F_7 ( V_6 -> V_12 , L_30 , V_46 ) ;
goto V_80;
}
}
return 0 ;
V_80:
if ( ! F_29 ( V_6 -> V_73 ) )
F_47 ( V_6 -> V_73 ) ;
V_79:
if ( ! F_29 ( V_6 -> V_72 ) )
F_47 ( V_6 -> V_72 ) ;
return V_46 ;
}
static void F_23 ( struct V_5 * V_6 )
{
if ( ! F_29 ( V_6 -> V_73 ) )
F_47 ( V_6 -> V_73 ) ;
if ( ! F_29 ( V_6 -> V_72 ) ) {
F_47 ( V_6 -> V_72 ) ;
if ( V_6 -> V_76 ) {
F_47 ( V_6 -> V_72 ) ;
V_6 -> V_76 = false ;
}
}
if ( ! F_29 ( V_6 -> V_75 ) )
F_47 ( V_6 -> V_75 ) ;
}
