static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 = V_8 ;
V_7 |= V_6 -> V_4 -> V_9 ;
while ( 1 ) {
F_3 ( V_7 , V_6 -> V_10 + V_11 ) ;
F_4 ( 5 ) ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( 0 , V_6 -> V_10 + V_12 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 ,
unsigned int V_13 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_14 ;
V_14 = F_7 ( V_6 -> V_10 + V_11 ) ;
V_14 &= ~ V_6 -> V_4 -> V_15 ;
V_14 |= F_8 ( V_13 , V_6 -> V_4 -> V_16 ) ;
F_3 ( V_14 , V_6 -> V_10 + V_11 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned int V_13 )
{
V_2 -> V_13 = V_13 ;
F_6 ( V_2 , V_13 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_14 ;
V_14 = F_7 ( V_6 -> V_10 + V_11 ) ;
V_14 &= ~ V_6 -> V_4 -> V_9 ;
F_3 ( V_14 , V_6 -> V_10 + V_11 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_14 ;
F_6 ( V_2 , V_6 -> V_2 . V_13 ) ;
F_5 ( V_2 ) ;
V_14 = F_7 ( V_6 -> V_10 + V_11 ) ;
V_14 |= V_6 -> V_4 -> V_9 ;
F_3 ( V_14 , V_6 -> V_10 + V_11 ) ;
return 0 ;
}
static int F_12 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
struct V_5 * V_6 ;
const struct V_21 * V_22 ;
int V_23 ;
V_6 = F_13 ( & V_18 -> V_24 , sizeof( * V_6 ) , V_25 ) ;
if ( ! V_6 )
return - V_26 ;
V_20 = F_14 ( V_18 , V_27 , 0 ) ;
V_6 -> V_10 = F_15 ( & V_18 -> V_24 , V_20 ) ;
if ( F_16 ( V_6 -> V_10 ) )
return F_17 ( V_6 -> V_10 ) ;
V_22 = F_18 ( V_28 , & V_18 -> V_24 ) ;
if ( ! V_22 ) {
F_19 ( & V_18 -> V_24 , L_1 ) ;
return - V_29 ;
}
V_6 -> V_4 = V_22 -> V_4 ;
V_6 -> V_2 . V_30 = & V_18 -> V_24 ;
V_6 -> V_2 . V_31 = & V_32 ;
V_6 -> V_2 . V_33 = & V_34 ;
V_6 -> V_2 . V_35 =
V_6 -> V_4 -> V_15 / V_6 -> V_4 -> V_16 ;
V_6 -> V_2 . V_36 = V_37 ;
V_6 -> V_2 . V_13 = F_20 (unsigned int,
MESON_WDT_TIMEOUT,
meson_wdt->wdt_dev.max_timeout) ;
F_21 ( & V_6 -> V_2 , V_6 ) ;
F_22 ( & V_6 -> V_2 , V_13 , & V_18 -> V_24 ) ;
F_23 ( & V_6 -> V_2 , V_38 ) ;
F_24 ( & V_6 -> V_2 , 128 ) ;
F_10 ( & V_6 -> V_2 ) ;
V_23 = F_25 ( & V_6 -> V_2 ) ;
if ( V_23 )
return V_23 ;
F_26 ( V_18 , V_6 ) ;
F_27 ( & V_18 -> V_24 , L_2 ,
V_6 -> V_2 . V_13 , V_38 ) ;
return 0 ;
}
static int F_28 ( struct V_17 * V_18 )
{
struct V_5 * V_6 = F_29 ( V_18 ) ;
F_30 ( & V_6 -> V_2 ) ;
return 0 ;
}
static void F_31 ( struct V_17 * V_18 )
{
struct V_5 * V_6 = F_29 ( V_18 ) ;
F_10 ( & V_6 -> V_2 ) ;
}
