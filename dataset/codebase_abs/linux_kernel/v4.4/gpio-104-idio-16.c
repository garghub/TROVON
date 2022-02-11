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
static struct V_6 * F_4 ( struct V_1 * V_7 )
{
return F_5 ( V_7 , struct V_6 , V_2 ) ;
}
static int F_6 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_6 * const V_8 = F_4 ( V_2 ) ;
const unsigned V_9 = 1U << ( V_3 - 16 ) ;
if ( V_3 < 16 )
return - V_10 ;
if ( V_3 < 24 )
return ! ! ( F_7 ( V_8 -> V_11 + 1 ) & V_9 ) ;
return ! ! ( F_7 ( V_8 -> V_11 + 5 ) & ( V_9 >> 8 ) ) ;
}
static void F_8 ( struct V_1 * V_2 , unsigned V_3 , int V_4 )
{
struct V_6 * const V_8 = F_4 ( V_2 ) ;
const unsigned V_9 = 1U << V_3 ;
unsigned long V_12 ;
if ( V_3 > 15 )
return;
F_9 ( & V_8 -> V_13 , V_12 ) ;
if ( V_4 )
V_8 -> V_14 |= V_9 ;
else
V_8 -> V_14 &= ~ V_9 ;
if ( V_3 > 7 )
F_10 ( V_8 -> V_14 >> 8 , V_8 -> V_11 + 4 ) ;
else
F_10 ( V_8 -> V_14 , V_8 -> V_11 ) ;
F_11 ( & V_8 -> V_13 , V_12 ) ;
}
static int T_1 F_12 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_16 -> V_18 ;
struct V_6 * V_8 ;
int V_19 ;
const unsigned V_20 = V_21 ;
const unsigned V_22 = 8 ;
const char * const V_23 = F_13 ( V_18 ) ;
V_8 = F_14 ( V_18 , sizeof( * V_8 ) , V_24 ) ;
if ( ! V_8 )
return - V_25 ;
if ( ! F_15 ( V_20 , V_22 , V_23 ) ) {
F_16 ( V_18 , L_1 ,
V_23 , V_20 , V_20 + V_22 ) ;
V_19 = - V_26 ;
goto V_27;
}
V_8 -> V_2 . V_28 = V_23 ;
V_8 -> V_2 . V_18 = V_18 ;
V_8 -> V_2 . V_29 = V_30 ;
V_8 -> V_2 . V_11 = - 1 ;
V_8 -> V_2 . V_31 = 32 ;
V_8 -> V_2 . V_32 = F_1 ;
V_8 -> V_2 . V_33 = F_2 ;
V_8 -> V_2 . V_34 = F_3 ;
V_8 -> V_2 . V_35 = F_6 ;
V_8 -> V_2 . V_5 = F_8 ;
V_8 -> V_11 = V_20 ;
V_8 -> V_36 = V_22 ;
V_8 -> V_14 = 0xFFFF ;
F_17 ( & V_8 -> V_13 ) ;
F_18 ( V_18 , V_8 ) ;
V_19 = F_19 ( & V_8 -> V_2 ) ;
if ( V_19 ) {
F_16 ( V_18 , L_2 , V_19 ) ;
goto V_37;
}
return 0 ;
V_37:
F_20 ( V_20 , V_22 ) ;
V_27:
return V_19 ;
}
static int F_21 ( struct V_15 * V_16 )
{
struct V_6 * const V_8 = F_22 ( V_16 ) ;
F_23 ( & V_8 -> V_2 ) ;
F_20 ( V_8 -> V_11 , V_8 -> V_36 ) ;
return 0 ;
}
static void T_2 F_24 ( void )
{
F_25 ( V_38 ) ;
F_26 ( & V_39 ) ;
}
static int T_1 F_27 ( void )
{
int V_19 ;
V_38 = F_28 ( V_39 . V_40 . V_41 , - 1 ) ;
if ( ! V_38 )
return - V_25 ;
V_19 = F_29 ( V_38 ) ;
if ( V_19 )
goto V_42;
V_19 = F_30 ( & V_39 , F_12 ) ;
if ( V_19 )
goto V_43;
return 0 ;
V_43:
F_31 ( V_38 ) ;
V_42:
F_32 ( V_38 ) ;
return V_19 ;
}
