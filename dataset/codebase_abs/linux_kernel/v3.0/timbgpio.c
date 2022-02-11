static int F_1 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_4 , bool V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
T_1 V_8 ;
F_3 ( & V_7 -> V_9 ) ;
V_8 = F_4 ( V_7 -> V_10 + V_4 ) ;
if ( V_5 )
V_8 |= ( 1 << V_3 ) ;
else
V_8 &= ~ ( 1 << V_3 ) ;
F_5 ( V_8 , V_7 -> V_10 + V_4 ) ;
F_6 ( & V_7 -> V_9 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_11 )
{
return F_1 ( V_2 , V_11 , V_12 , true ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_11 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
T_1 V_13 ;
V_13 = F_4 ( V_7 -> V_10 + V_14 ) ;
return ( V_13 & ( 1 << V_11 ) ) ? 1 : 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned V_11 , int V_15 )
{
return F_1 ( V_2 , V_11 , V_12 , false ) ;
}
static void F_10 ( struct V_1 * V_2 ,
unsigned V_11 , int V_15 )
{
F_1 ( V_2 , V_11 , V_14 , V_15 != 0 ) ;
}
static int F_11 ( struct V_1 * V_2 , unsigned V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
if ( V_7 -> V_16 <= 0 )
return - V_17 ;
return V_7 -> V_16 + V_4 ;
}
static void F_12 ( struct V_18 * V_19 )
{
struct V_6 * V_7 = F_13 ( V_19 ) ;
int V_4 = V_19 -> V_20 - V_7 -> V_16 ;
unsigned long V_21 ;
F_14 ( & V_7 -> V_9 , V_21 ) ;
V_7 -> V_22 &= ~ ( 1 << V_4 ) ;
F_5 ( V_7 -> V_22 , V_7 -> V_10 + V_23 ) ;
F_15 ( & V_7 -> V_9 , V_21 ) ;
}
static void F_16 ( struct V_18 * V_19 )
{
struct V_6 * V_7 = F_13 ( V_19 ) ;
int V_4 = V_19 -> V_20 - V_7 -> V_16 ;
unsigned long V_21 ;
F_14 ( & V_7 -> V_9 , V_21 ) ;
V_7 -> V_22 |= 1 << V_4 ;
F_5 ( V_7 -> V_22 , V_7 -> V_10 + V_23 ) ;
F_15 ( & V_7 -> V_9 , V_21 ) ;
}
static int F_17 ( struct V_18 * V_19 , unsigned V_24 )
{
struct V_6 * V_7 = F_13 ( V_19 ) ;
int V_4 = V_19 -> V_20 - V_7 -> V_16 ;
unsigned long V_21 ;
T_1 V_25 , V_26 , V_27 = 0 ;
T_1 V_28 ;
int V_29 = 0 ;
if ( V_4 < 0 || V_4 > V_7 -> V_2 . V_30 )
return - V_17 ;
V_28 = F_4 ( V_7 -> V_10 + V_31 ) ;
F_14 ( & V_7 -> V_9 , V_21 ) ;
V_25 = F_4 ( V_7 -> V_10 + V_32 ) ;
V_26 = F_4 ( V_7 -> V_10 + V_33 ) ;
if ( V_28 > 2 )
V_27 = F_4 ( V_7 -> V_10 + V_34 ) ;
if ( V_24 & ( V_35 | V_36 ) ) {
V_27 &= ~ ( 1 << V_4 ) ;
V_26 &= ~ ( 1 << V_4 ) ;
if ( V_24 & V_35 )
V_25 |= 1 << V_4 ;
else
V_25 &= ~ ( 1 << V_4 ) ;
}
if ( ( V_24 & V_37 ) == V_37 ) {
if ( V_28 < 3 ) {
V_29 = - V_17 ;
goto V_38;
}
else {
V_26 |= 1 << V_4 ;
V_27 |= 1 << V_4 ;
}
} else {
V_27 &= ~ ( 1 << V_4 ) ;
V_26 |= 1 << V_4 ;
if ( V_24 & V_39 )
V_25 &= ~ ( 1 << V_4 ) ;
else
V_25 |= 1 << V_4 ;
}
F_5 ( V_25 , V_7 -> V_10 + V_32 ) ;
F_5 ( V_26 , V_7 -> V_10 + V_33 ) ;
if ( V_28 > 2 )
F_5 ( V_27 , V_7 -> V_10 + V_34 ) ;
F_5 ( 1 << V_4 , V_7 -> V_10 + V_40 ) ;
V_38:
F_15 ( & V_7 -> V_9 , V_21 ) ;
return V_29 ;
}
static void F_18 ( unsigned int V_20 , struct V_41 * V_42 )
{
struct V_6 * V_7 = F_19 ( V_20 ) ;
unsigned long V_43 ;
int V_4 ;
V_42 -> V_18 . V_44 -> V_45 ( F_20 ( V_20 ) ) ;
V_43 = F_4 ( V_7 -> V_10 + V_46 ) ;
F_5 ( V_43 , V_7 -> V_10 + V_40 ) ;
F_5 ( 0 , V_7 -> V_10 + V_23 ) ;
F_21 (offset, &ipr, tgpio->gpio.ngpio)
F_22 ( F_11 ( & V_7 -> V_2 , V_4 ) ) ;
F_5 ( V_7 -> V_22 , V_7 -> V_10 + V_23 ) ;
}
static int T_2 F_23 ( struct V_47 * V_48 )
{
int V_49 , V_50 ;
struct V_1 * V_51 ;
struct V_6 * V_7 ;
struct V_52 * V_53 ;
struct V_54 * V_55 = V_48 -> V_56 . V_57 ;
int V_20 = F_24 ( V_48 , 0 ) ;
if ( ! V_55 || V_55 -> V_58 > 32 ) {
V_49 = - V_17 ;
goto V_59;
}
V_53 = F_25 ( V_48 , V_60 , 0 ) ;
if ( ! V_53 ) {
V_49 = - V_17 ;
goto V_59;
}
V_7 = F_26 ( sizeof( * V_7 ) , V_61 ) ;
if ( ! V_7 ) {
V_49 = - V_17 ;
goto V_59;
}
V_7 -> V_16 = V_55 -> V_16 ;
F_27 ( & V_7 -> V_9 ) ;
if ( ! F_28 ( V_53 -> V_62 , F_29 ( V_53 ) ,
V_63 ) ) {
V_49 = - V_64 ;
goto V_65;
}
V_7 -> V_10 = F_30 ( V_53 -> V_62 , F_29 ( V_53 ) ) ;
if ( ! V_7 -> V_10 ) {
V_49 = - V_66 ;
goto V_67;
}
V_51 = & V_7 -> V_2 ;
V_51 -> V_68 = F_31 ( & V_48 -> V_56 ) ;
V_51 -> V_69 = V_70 ;
V_51 -> V_56 = & V_48 -> V_56 ;
V_51 -> V_71 = F_7 ;
V_51 -> V_72 = F_8 ;
V_51 -> V_73 = F_9 ;
V_51 -> V_74 = F_10 ;
V_51 -> V_75 = ( V_20 >= 0 && V_7 -> V_16 > 0 ) ? F_11 : NULL ;
V_51 -> V_76 = NULL ;
V_51 -> V_77 = V_55 -> V_78 ;
V_51 -> V_30 = V_55 -> V_58 ;
V_51 -> V_79 = 0 ;
V_49 = F_32 ( V_51 ) ;
if ( V_49 )
goto V_80;
F_33 ( V_48 , V_7 ) ;
F_5 ( 0x0 , V_7 -> V_10 + V_23 ) ;
if ( V_20 < 0 || V_7 -> V_16 <= 0 )
return 0 ;
for ( V_50 = 0 ; V_50 < V_55 -> V_58 ; V_50 ++ ) {
F_34 ( V_7 -> V_16 + V_50 ,
& V_81 , V_82 , L_1 ) ;
F_35 ( V_7 -> V_16 + V_50 , V_7 ) ;
#ifdef F_36
F_37 ( V_7 -> V_16 + V_50 , V_83 | V_84 ) ;
#endif
}
F_38 ( V_20 , V_7 ) ;
F_39 ( V_20 , F_18 ) ;
return 0 ;
V_80:
F_40 ( V_7 -> V_10 ) ;
V_67:
F_41 ( V_53 -> V_62 , F_29 ( V_53 ) ) ;
V_65:
F_42 ( V_7 ) ;
V_59:
F_43 (KERN_ERR DRIVER_NAMEL_2 , err) ;
return V_49 ;
}
static int T_3 F_44 ( struct V_47 * V_48 )
{
int V_49 ;
struct V_54 * V_55 = V_48 -> V_56 . V_57 ;
struct V_6 * V_7 = F_45 ( V_48 ) ;
struct V_52 * V_53 = F_25 ( V_48 , V_60 , 0 ) ;
int V_20 = F_24 ( V_48 , 0 ) ;
if ( V_20 >= 0 && V_7 -> V_16 > 0 ) {
int V_50 ;
for ( V_50 = 0 ; V_50 < V_55 -> V_58 ; V_50 ++ ) {
F_46 ( V_7 -> V_16 + V_50 , NULL ) ;
F_35 ( V_7 -> V_16 + V_50 , NULL ) ;
}
F_47 ( V_20 , NULL ) ;
F_38 ( V_20 , NULL ) ;
}
V_49 = F_48 ( & V_7 -> V_2 ) ;
if ( V_49 )
F_43 (KERN_ERR DRIVER_NAMEL_3 ) ;
F_40 ( V_7 -> V_10 ) ;
F_41 ( V_53 -> V_62 , F_29 ( V_53 ) ) ;
F_42 ( V_7 ) ;
F_33 ( V_48 , NULL ) ;
return 0 ;
}
static int T_4 F_49 ( void )
{
return F_50 ( & V_85 ) ;
}
static void T_5 F_51 ( void )
{
F_52 ( & V_85 ) ;
}
