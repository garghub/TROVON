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
break;
} while ( ! F_15 ( V_17 , V_16 ) );
if ( ! ( V_15 & V_21 ) ) {
F_7 ( V_6 -> V_12 , L_2 ) ;
return - V_22 ;
}
return 0 ;
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
V_15 = F_1 ( V_6 -> V_19 , V_29 ) ;
if ( V_15 & V_47 ) {
V_15 &= ~ V_47 ;
F_3 ( V_6 -> V_19 , V_29 , V_15 ) ;
V_46 = F_12 ( V_6 ) ;
}
V_15 = F_1 ( V_6 -> V_19 , V_20 ) ;
if ( ! ( V_15 & V_21 ) )
if ( F_16 ( V_6 ) )
return - V_24 ;
return V_46 ;
}
static int F_18 ( struct V_6 * V_13 )
{
struct V_5 * V_6 = F_9 ( V_13 ) ;
T_1 V_15 ;
unsigned long V_16 ;
if ( F_19 ( V_6 -> V_12 -> V_48 , L_3 ) )
return 0 ;
V_15 = F_1 ( V_6 -> V_19 , V_29 ) ;
V_15 |= V_47 ;
F_3 ( V_6 -> V_19 , V_29 , V_15 ) ;
V_16 = V_17 + F_13 ( V_49 ) ;
do {
F_14 () ;
V_15 = F_1 ( V_6 -> V_19 , V_20 ) ;
if ( ( V_15 & V_50 ) && ( V_15 & V_51 ) )
break;
} while ( ! F_15 ( V_17 , V_16 ) );
if ( ! ( V_15 & V_50 ) || ! ( V_15 & V_51 ) ) {
F_7 ( V_6 -> V_12 , L_4 ,
V_15 ) ;
return - V_22 ;
}
return 0 ;
}
static int F_20 ( struct V_52 * V_53 )
{
struct V_5 * V_6 ;
struct V_6 * V_54 ;
struct V_55 * V_55 ;
struct V_56 * V_57 ;
struct V_58 * V_59 = V_53 -> V_12 . V_48 ;
struct V_58 * V_60 ;
struct V_52 * V_61 ;
const struct V_62 * V_63 ;
V_63 = F_21 ( F_22 ( V_64 ) , & V_53 -> V_12 ) ;
if ( ! V_63 )
return - V_24 ;
V_6 = F_23 ( & V_53 -> V_12 , sizeof( * V_6 ) , V_65 ) ;
if ( ! V_6 ) {
F_7 ( & V_53 -> V_12 , L_5 ) ;
return - V_66 ;
}
V_6 -> V_9 = (struct V_8 * ) V_63 -> V_3 ;
if ( ! V_6 -> V_9 ) {
F_7 ( & V_53 -> V_12 , L_6 ) ;
return - V_24 ;
}
V_57 = F_24 ( V_53 , V_67 , L_7 ) ;
V_6 -> V_19 = F_25 ( & V_53 -> V_12 , V_57 ) ;
if ( F_26 ( V_6 -> V_19 ) )
return F_27 ( V_6 -> V_19 ) ;
V_6 -> V_12 = & V_53 -> V_12 ;
if ( ! F_19 ( V_59 , L_3 ) ) {
V_6 -> V_68 = F_28 ( V_6 -> V_12 , L_8 ) ;
if ( F_26 ( V_6 -> V_68 ) ) {
F_7 ( & V_53 -> V_12 , L_9 ) ;
return F_27 ( V_6 -> V_68 ) ;
}
V_6 -> V_69 = F_28 ( V_6 -> V_12 , L_10 ) ;
if ( F_26 ( V_6 -> V_69 ) ) {
F_7 ( & V_53 -> V_12 , L_11 ) ;
return F_27 ( V_6 -> V_69 ) ;
}
} else {
V_6 -> V_68 = F_29 ( - V_70 ) ;
V_6 -> V_69 = F_29 ( - V_70 ) ;
}
V_6 -> V_10 = F_28 ( V_6 -> V_12 , L_12 ) ;
if ( F_26 ( V_6 -> V_10 ) ) {
F_7 ( & V_53 -> V_12 , L_13 ) ;
return - V_24 ;
}
V_60 = F_30 ( V_59 , L_14 , 0 ) ;
if ( ! V_60 ) {
F_7 ( & V_53 -> V_12 , L_15 ) ;
return - V_24 ;
}
V_61 = F_31 ( V_60 ) ;
if ( ! V_61 ) {
F_7 ( & V_53 -> V_12 , L_16 ) ;
return - V_24 ;
}
V_6 -> V_14 = & V_61 -> V_12 ;
F_10 ( V_6 -> V_14 , 0 ) ;
F_32 ( V_53 , V_6 ) ;
F_33 ( V_6 -> V_12 ) ;
V_54 = F_34 ( V_6 -> V_12 , & V_71 , NULL ) ;
if ( F_26 ( V_54 ) )
return F_27 ( V_54 ) ;
F_35 ( V_54 , V_6 ) ;
V_55 = F_36 ( V_6 -> V_12 ,
V_72 ) ;
if ( F_26 ( V_55 ) )
return F_27 ( V_55 ) ;
F_37 ( & V_53 -> V_12 ) ;
return 0 ;
}
static int F_38 ( struct V_52 * V_53 )
{
if ( ! F_39 ( & V_53 -> V_12 ) )
F_40 ( & V_53 -> V_12 ) ;
F_41 ( & V_53 -> V_12 ) ;
return 0 ;
}
static int F_42 ( struct V_73 * V_12 )
{
struct V_5 * V_6 = F_43 ( V_12 ) ;
if ( ! F_26 ( V_6 -> V_68 ) )
F_44 ( V_6 -> V_68 ) ;
if ( ! F_26 ( V_6 -> V_69 ) )
F_44 ( V_6 -> V_69 ) ;
return 0 ;
}
static int F_45 ( struct V_73 * V_12 )
{
T_1 V_46 = 0 ;
struct V_5 * V_6 = F_43 ( V_12 ) ;
if ( ! F_26 ( V_6 -> V_69 ) ) {
V_46 = F_46 ( V_6 -> V_69 ) ;
if ( V_46 ) {
F_7 ( V_6 -> V_12 , L_17 , V_46 ) ;
goto V_74;
}
}
if ( ! F_26 ( V_6 -> V_68 ) ) {
V_46 = F_46 ( V_6 -> V_68 ) ;
if ( V_46 ) {
F_7 ( V_6 -> V_12 , L_18 , V_46 ) ;
goto V_75;
}
}
return 0 ;
V_75:
if ( ! F_26 ( V_6 -> V_69 ) )
F_44 ( V_6 -> V_69 ) ;
V_74:
return V_46 ;
}
