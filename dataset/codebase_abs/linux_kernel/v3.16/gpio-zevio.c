static inline T_1 F_1 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_4 )
{
unsigned V_5 = ( ( V_3 >> 3 ) & 3 ) * V_6 ;
return F_2 ( F_3 ( V_2 -> V_7 . V_8 + V_5 + V_4 ) ) ;
}
static inline void F_4 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_4 , T_1 V_9 )
{
unsigned V_5 = ( ( V_3 >> 3 ) & 3 ) * V_6 ;
F_5 ( V_9 , F_3 ( V_2 -> V_7 . V_8 + V_5 + V_4 ) ) ;
}
static int F_6 ( struct V_10 * V_7 , unsigned V_3 )
{
struct V_1 * V_11 = F_7 ( V_7 ) ;
T_1 V_9 , V_12 ;
F_8 ( & V_11 -> V_13 ) ;
V_12 = F_1 ( V_11 , V_3 , V_14 ) ;
if ( V_12 & F_9 ( F_10 ( V_3 ) ) )
V_9 = F_1 ( V_11 , V_3 , V_15 ) ;
else
V_9 = F_1 ( V_11 , V_3 , V_16 ) ;
F_11 ( & V_11 -> V_13 ) ;
return ( V_9 >> F_10 ( V_3 ) ) & 0x1 ;
}
static void F_12 ( struct V_10 * V_7 , unsigned V_3 , int V_17 )
{
struct V_1 * V_11 = F_7 ( V_7 ) ;
T_1 V_9 ;
F_8 ( & V_11 -> V_13 ) ;
V_9 = F_1 ( V_11 , V_3 , V_16 ) ;
if ( V_17 )
V_9 |= F_9 ( F_10 ( V_3 ) ) ;
else
V_9 &= ~ F_9 ( F_10 ( V_3 ) ) ;
F_4 ( V_11 , V_3 , V_16 , V_9 ) ;
F_11 ( & V_11 -> V_13 ) ;
}
static int F_13 ( struct V_10 * V_7 , unsigned V_3 )
{
struct V_1 * V_11 = F_7 ( V_7 ) ;
T_1 V_9 ;
F_8 ( & V_11 -> V_13 ) ;
V_9 = F_1 ( V_11 , V_3 , V_14 ) ;
V_9 |= F_9 ( F_10 ( V_3 ) ) ;
F_4 ( V_11 , V_3 , V_14 , V_9 ) ;
F_11 ( & V_11 -> V_13 ) ;
return 0 ;
}
static int F_14 ( struct V_10 * V_7 ,
unsigned V_3 , int V_17 )
{
struct V_1 * V_11 = F_7 ( V_7 ) ;
T_1 V_9 ;
F_8 ( & V_11 -> V_13 ) ;
V_9 = F_1 ( V_11 , V_3 , V_16 ) ;
if ( V_17 )
V_9 |= F_9 ( F_10 ( V_3 ) ) ;
else
V_9 &= ~ F_9 ( F_10 ( V_3 ) ) ;
F_4 ( V_11 , V_3 , V_16 , V_9 ) ;
V_9 = F_1 ( V_11 , V_3 , V_14 ) ;
V_9 &= ~ F_9 ( F_10 ( V_3 ) ) ;
F_4 ( V_11 , V_3 , V_14 , V_9 ) ;
F_11 ( & V_11 -> V_13 ) ;
return 0 ;
}
static int F_15 ( struct V_10 * V_7 , unsigned V_3 )
{
return - V_18 ;
}
static int F_16 ( struct V_19 * V_20 )
{
struct V_1 * V_11 ;
int V_21 , V_22 ;
V_11 = F_17 ( & V_20 -> V_23 , sizeof( * V_11 ) , V_24 ) ;
if ( ! V_11 )
return - V_25 ;
V_11 -> V_7 . V_26 = V_27 ;
V_11 -> V_7 . V_26 . V_23 = & V_20 -> V_23 ;
V_21 = F_18 ( V_20 -> V_23 . V_28 , & ( V_11 -> V_7 ) ) ;
if ( V_21 ) {
F_19 ( & V_20 -> V_23 , L_1 , V_21 ) ;
return V_21 ;
}
F_20 ( & V_11 -> V_13 ) ;
for ( V_22 = 0 ; V_22 < V_11 -> V_7 . V_26 . V_29 ; V_22 += 8 )
F_4 ( V_11 , V_22 , V_30 , 0xFF ) ;
F_21 ( V_11 -> V_7 . V_26 . V_23 , L_2 ) ;
return 0 ;
}
