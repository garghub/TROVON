static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return ( F_3 ( V_5 -> V_6 + V_7 ) >> V_3 ) & 1 ;
}
static void F_4 ( struct V_1 * V_2 , unsigned int V_3 , int V_8 )
{
unsigned long V_9 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_10 * V_11 =
F_5 ( V_5 , struct V_10 , V_12 ) ;
F_6 ( & V_11 -> V_13 , V_9 ) ;
if ( V_8 )
V_11 -> V_14 |= 1 << V_3 ;
else
V_11 -> V_14 &= ~ ( 1 << V_3 ) ;
F_7 ( V_5 -> V_6 + V_7 , V_11 -> V_14 ) ;
F_8 ( & V_11 -> V_13 , V_9 ) ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned long V_9 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_10 * V_11 =
F_5 ( V_5 , struct V_10 , V_12 ) ;
F_6 ( & V_11 -> V_13 , V_9 ) ;
V_11 -> V_15 |= ( 1 << V_3 ) ;
F_7 ( V_5 -> V_6 + V_16 , V_11 -> V_15 ) ;
F_8 ( & V_11 -> V_13 , V_9 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_3 , int V_8 )
{
unsigned long V_9 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_10 * V_11 =
F_5 ( V_5 , struct V_10 , V_12 ) ;
F_6 ( & V_11 -> V_13 , V_9 ) ;
if ( V_8 )
V_11 -> V_14 |= 1 << V_3 ;
else
V_11 -> V_14 &= ~ ( 1 << V_3 ) ;
F_7 ( V_5 -> V_6 + V_7 , V_11 -> V_14 ) ;
V_11 -> V_15 &= ( ~ ( 1 << V_3 ) ) ;
F_7 ( V_5 -> V_6 + V_16 , V_11 -> V_15 ) ;
F_8 ( & V_11 -> V_13 , V_9 ) ;
return 0 ;
}
static void F_11 ( struct V_4 * V_5 )
{
struct V_10 * V_11 =
F_5 ( V_5 , struct V_10 , V_12 ) ;
F_7 ( V_5 -> V_6 + V_7 , V_11 -> V_14 ) ;
F_7 ( V_5 -> V_6 + V_16 , V_11 -> V_15 ) ;
}
static int F_12 ( struct V_17 * V_18 )
{
struct V_10 * V_11 ;
int V_19 = 0 ;
const T_1 * V_20 ;
V_11 = F_13 ( sizeof( * V_11 ) , V_21 ) ;
if ( ! V_11 )
return - V_22 ;
V_20 = F_14 ( V_18 , L_1 , NULL ) ;
if ( V_20 )
V_11 -> V_14 = F_15 ( V_20 ) ;
V_11 -> V_15 = 0xFFFFFFFF ;
V_20 = F_14 ( V_18 , L_2 , NULL ) ;
if ( V_20 )
V_11 -> V_15 = F_15 ( V_20 ) ;
V_11 -> V_12 . V_2 . V_23 = 32 ;
V_20 = F_14 ( V_18 , L_3 , NULL ) ;
if ( ! V_20 )
V_20 = F_14 ( V_18 -> V_24 ,
L_3 , NULL ) ;
if ( V_20 )
V_11 -> V_12 . V_2 . V_23 = F_15 ( V_20 ) ;
F_16 ( & V_11 -> V_13 ) ;
V_11 -> V_12 . V_2 . V_25 = F_9 ;
V_11 -> V_12 . V_2 . V_26 = F_10 ;
V_11 -> V_12 . V_2 . V_27 = F_1 ;
V_11 -> V_12 . V_2 . V_28 = F_4 ;
V_11 -> V_12 . V_29 = F_11 ;
V_19 = F_17 ( V_18 , & V_11 -> V_12 ) ;
if ( V_19 ) {
F_18 ( V_11 ) ;
F_19 ( L_4 ,
V_18 -> V_30 , V_19 ) ;
return V_19 ;
}
return 0 ;
}
static int T_2 F_20 ( void )
{
struct V_17 * V_18 ;
F_21 (np, xgpio_of_match)
F_12 ( V_18 ) ;
return 0 ;
}
