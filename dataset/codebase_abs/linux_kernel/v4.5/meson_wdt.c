static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = V_6 ;
V_5 |= V_4 -> V_7 -> V_8 ;
while ( 1 ) {
F_3 ( V_5 , V_4 -> V_9 + V_10 ) ;
F_4 ( 5 ) ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 0 , V_4 -> V_9 + V_11 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 ,
unsigned int V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_13 ;
V_13 = F_7 ( V_4 -> V_9 + V_10 ) ;
V_13 &= ~ V_4 -> V_7 -> V_14 ;
V_13 |= F_8 ( V_12 , V_4 -> V_7 -> V_15 ) ;
F_3 ( V_13 , V_4 -> V_9 + V_10 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned int V_12 )
{
V_2 -> V_12 = V_12 ;
F_6 ( V_2 , V_12 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_13 ;
V_13 = F_7 ( V_4 -> V_9 + V_10 ) ;
V_13 &= ~ V_4 -> V_7 -> V_8 ;
F_3 ( V_13 , V_4 -> V_9 + V_10 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_13 ;
F_6 ( V_2 , V_4 -> V_2 . V_12 ) ;
F_5 ( V_2 ) ;
V_13 = F_7 ( V_4 -> V_9 + V_10 ) ;
V_13 |= V_4 -> V_7 -> V_8 ;
F_3 ( V_13 , V_4 -> V_9 + V_10 ) ;
return 0 ;
}
static int F_12 ( struct V_16 * V_17 )
{
struct V_18 * V_19 ;
struct V_3 * V_4 ;
const struct V_20 * V_21 ;
int V_22 ;
V_4 = F_13 ( & V_17 -> V_23 , sizeof( * V_4 ) , V_24 ) ;
if ( ! V_4 )
return - V_25 ;
V_19 = F_14 ( V_17 , V_26 , 0 ) ;
V_4 -> V_9 = F_15 ( & V_17 -> V_23 , V_19 ) ;
if ( F_16 ( V_4 -> V_9 ) )
return F_17 ( V_4 -> V_9 ) ;
V_21 = F_18 ( V_27 , & V_17 -> V_23 ) ;
if ( ! V_21 ) {
F_19 ( & V_17 -> V_23 , L_1 ) ;
return - V_28 ;
}
V_4 -> V_7 = V_21 -> V_7 ;
V_4 -> V_2 . V_29 = & V_17 -> V_23 ;
V_4 -> V_2 . V_30 = & V_31 ;
V_4 -> V_2 . V_32 = & V_33 ;
V_4 -> V_2 . V_34 =
V_4 -> V_7 -> V_14 / V_4 -> V_7 -> V_15 ;
V_4 -> V_2 . V_35 = V_36 ;
V_4 -> V_2 . V_12 = F_20 (unsigned int,
MESON_WDT_TIMEOUT,
meson_wdt->wdt_dev.max_timeout) ;
F_21 ( & V_4 -> V_2 , V_4 ) ;
F_22 ( & V_4 -> V_2 , V_12 , & V_17 -> V_23 ) ;
F_23 ( & V_4 -> V_2 , V_37 ) ;
F_24 ( & V_4 -> V_2 , 128 ) ;
F_10 ( & V_4 -> V_2 ) ;
V_22 = F_25 ( & V_4 -> V_2 ) ;
if ( V_22 )
return V_22 ;
F_26 ( V_17 , V_4 ) ;
F_27 ( & V_17 -> V_23 , L_2 ,
V_4 -> V_2 . V_12 , V_37 ) ;
return 0 ;
}
static int F_28 ( struct V_16 * V_17 )
{
struct V_3 * V_4 = F_29 ( V_17 ) ;
F_30 ( & V_4 -> V_2 ) ;
return 0 ;
}
static void F_31 ( struct V_16 * V_17 )
{
struct V_3 * V_4 = F_29 ( V_17 ) ;
F_10 ( & V_4 -> V_2 ) ;
}
