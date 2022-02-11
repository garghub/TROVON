static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
if ( V_3 > 15 )
return 1 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , unsigned V_3 )
{
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned V_3 , int V_4 )
{
V_2 -> V_5 ( V_2 , V_3 , V_4 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_6 * const V_7 = F_5 ( V_2 ) ;
const unsigned V_8 = F_6 ( V_3 - 16 ) ;
if ( V_3 < 16 )
return - V_9 ;
if ( V_3 < 24 )
return ! ! ( F_7 ( V_7 -> V_10 + 1 ) & V_8 ) ;
return ! ! ( F_7 ( V_7 -> V_10 + 5 ) & ( V_8 >> 8 ) ) ;
}
static void F_8 ( struct V_1 * V_2 , unsigned V_3 , int V_4 )
{
struct V_6 * const V_7 = F_5 ( V_2 ) ;
const unsigned V_8 = F_6 ( V_3 ) ;
unsigned long V_11 ;
if ( V_3 > 15 )
return;
F_9 ( & V_7 -> V_12 , V_11 ) ;
if ( V_4 )
V_7 -> V_13 |= V_8 ;
else
V_7 -> V_13 &= ~ V_8 ;
if ( V_3 > 7 )
F_10 ( V_7 -> V_13 >> 8 , V_7 -> V_10 + 4 ) ;
else
F_10 ( V_7 -> V_13 , V_7 -> V_10 ) ;
F_11 ( & V_7 -> V_12 , V_11 ) ;
}
static void F_12 ( struct V_14 * V_15 )
{
}
static void F_13 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_14 ( V_15 ) ;
struct V_6 * const V_7 = F_5 ( V_2 ) ;
const unsigned long V_8 = F_6 ( F_15 ( V_15 ) ) ;
unsigned long V_11 ;
V_7 -> V_16 &= ~ V_8 ;
if ( ! V_7 -> V_16 ) {
F_9 ( & V_7 -> V_12 , V_11 ) ;
F_10 ( 0 , V_7 -> V_10 + 2 ) ;
F_11 ( & V_7 -> V_12 , V_11 ) ;
}
}
static void F_16 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_14 ( V_15 ) ;
struct V_6 * const V_7 = F_5 ( V_2 ) ;
const unsigned long V_8 = F_6 ( F_15 ( V_15 ) ) ;
const unsigned long V_17 = V_7 -> V_16 ;
unsigned long V_11 ;
V_7 -> V_16 |= V_8 ;
if ( ! V_17 ) {
F_9 ( & V_7 -> V_12 , V_11 ) ;
F_7 ( V_7 -> V_10 + 2 ) ;
F_11 ( & V_7 -> V_12 , V_11 ) ;
}
}
static int F_17 ( struct V_14 * V_15 , unsigned V_18 )
{
if ( V_18 != V_19 &&
( V_18 & V_20 ) != V_20 )
return - V_9 ;
return 0 ;
}
static T_1 F_18 ( int V_21 , void * V_22 )
{
struct V_6 * const V_7 = V_22 ;
struct V_1 * const V_2 = & V_7 -> V_2 ;
int V_23 ;
F_19 (gpio, &idio16gpio->irq_mask, chip->ngpio)
F_20 ( F_21 ( V_2 -> V_24 , V_23 ) ) ;
F_22 ( & V_7 -> V_12 ) ;
F_10 ( 0 , V_7 -> V_10 + 1 ) ;
F_23 ( & V_7 -> V_12 ) ;
return V_25 ;
}
static int T_2 F_24 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = & V_27 -> V_29 ;
struct V_6 * V_7 ;
const unsigned V_10 = V_30 ;
const unsigned V_31 = 8 ;
const char * const V_32 = F_25 ( V_29 ) ;
int V_33 ;
const unsigned V_21 = V_34 ;
V_7 = F_26 ( V_29 , sizeof( * V_7 ) , V_35 ) ;
if ( ! V_7 )
return - V_36 ;
if ( ! F_27 ( V_29 , V_10 , V_31 , V_32 ) ) {
F_28 ( V_29 , L_1 ,
V_10 , V_10 + V_31 ) ;
return - V_37 ;
}
V_7 -> V_2 . V_38 = V_32 ;
V_7 -> V_2 . V_39 = V_29 ;
V_7 -> V_2 . V_40 = V_41 ;
V_7 -> V_2 . V_10 = - 1 ;
V_7 -> V_2 . V_42 = 32 ;
V_7 -> V_2 . V_43 = F_1 ;
V_7 -> V_2 . V_44 = F_2 ;
V_7 -> V_2 . V_45 = F_3 ;
V_7 -> V_2 . V_46 = F_4 ;
V_7 -> V_2 . V_5 = F_8 ;
V_7 -> V_10 = V_10 ;
V_7 -> V_21 = V_21 ;
V_7 -> V_13 = 0xFFFF ;
F_29 ( & V_7 -> V_12 ) ;
F_30 ( V_29 , V_7 ) ;
V_33 = F_31 ( & V_7 -> V_2 , V_7 ) ;
if ( V_33 ) {
F_28 ( V_29 , L_2 , V_33 ) ;
return V_33 ;
}
F_10 ( 0 , V_10 + 2 ) ;
F_10 ( 0 , V_10 + 1 ) ;
V_33 = F_32 ( & V_7 -> V_2 , & V_47 , 0 ,
V_48 , V_19 ) ;
if ( V_33 ) {
F_28 ( V_29 , L_3 , V_33 ) ;
goto V_49;
}
V_33 = F_33 ( V_21 , F_18 , 0 , V_32 , V_7 ) ;
if ( V_33 ) {
F_28 ( V_29 , L_4 , V_33 ) ;
goto V_49;
}
return 0 ;
V_49:
F_34 ( & V_7 -> V_2 ) ;
return V_33 ;
}
static int F_35 ( struct V_26 * V_27 )
{
struct V_6 * const V_7 = F_36 ( V_27 ) ;
F_37 ( V_7 -> V_21 , V_7 ) ;
F_34 ( & V_7 -> V_2 ) ;
return 0 ;
}
static void T_3 F_38 ( void )
{
F_39 ( V_50 ) ;
F_40 ( & V_51 ) ;
}
static int T_2 F_41 ( void )
{
int V_33 ;
V_50 = F_42 ( V_51 . V_52 . V_32 , - 1 ) ;
if ( ! V_50 )
return - V_36 ;
V_33 = F_43 ( V_50 ) ;
if ( V_33 )
goto V_53;
V_33 = F_44 ( & V_51 , F_24 ) ;
if ( V_33 )
goto V_54;
return 0 ;
V_54:
F_45 ( V_50 ) ;
V_53:
F_46 ( V_50 ) ;
return V_33 ;
}
