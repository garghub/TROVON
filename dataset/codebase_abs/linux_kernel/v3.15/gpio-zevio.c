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
T_1 V_9 = F_1 ( V_11 , V_3 , V_12 ) ;
return ( V_9 >> F_8 ( V_3 ) ) & 0x1 ;
}
static void F_9 ( struct V_10 * V_7 , unsigned V_3 , int V_13 )
{
struct V_1 * V_11 = F_7 ( V_7 ) ;
T_1 V_9 ;
F_10 ( & V_11 -> V_14 ) ;
V_9 = F_1 ( V_11 , V_3 , V_15 ) ;
if ( V_13 )
V_9 |= F_11 ( F_8 ( V_3 ) ) ;
else
V_9 &= ~ F_11 ( F_8 ( V_3 ) ) ;
F_4 ( V_11 , V_3 , V_15 , V_9 ) ;
F_12 ( & V_11 -> V_14 ) ;
}
static int F_13 ( struct V_10 * V_7 , unsigned V_3 )
{
struct V_1 * V_11 = F_7 ( V_7 ) ;
T_1 V_9 ;
F_10 ( & V_11 -> V_14 ) ;
V_9 = F_1 ( V_11 , V_3 , V_16 ) ;
V_9 |= F_11 ( F_8 ( V_3 ) ) ;
F_4 ( V_11 , V_3 , V_16 , V_9 ) ;
F_12 ( & V_11 -> V_14 ) ;
return 0 ;
}
static int F_14 ( struct V_10 * V_7 ,
unsigned V_3 , int V_13 )
{
struct V_1 * V_11 = F_7 ( V_7 ) ;
T_1 V_9 ;
F_10 ( & V_11 -> V_14 ) ;
V_9 = F_1 ( V_11 , V_3 , V_15 ) ;
if ( V_13 )
V_9 |= F_11 ( F_8 ( V_3 ) ) ;
else
V_9 &= ~ F_11 ( F_8 ( V_3 ) ) ;
F_4 ( V_11 , V_3 , V_15 , V_9 ) ;
V_9 = F_1 ( V_11 , V_3 , V_16 ) ;
V_9 &= ~ F_11 ( F_8 ( V_3 ) ) ;
F_4 ( V_11 , V_3 , V_16 , V_9 ) ;
F_12 ( & V_11 -> V_14 ) ;
return 0 ;
}
static int F_15 ( struct V_10 * V_7 , unsigned V_3 )
{
return - V_17 ;
}
static int F_16 ( struct V_18 * V_19 )
{
struct V_1 * V_11 ;
int V_20 , V_21 ;
V_11 = F_17 ( & V_19 -> V_22 , sizeof( * V_11 ) , V_23 ) ;
if ( ! V_11 ) {
F_18 ( & V_19 -> V_22 , L_1 ) ;
return - V_24 ;
}
V_11 -> V_7 . V_25 = V_26 ;
V_11 -> V_7 . V_25 . V_22 = & V_19 -> V_22 ;
V_20 = F_19 ( V_19 -> V_22 . V_27 , & ( V_11 -> V_7 ) ) ;
if ( V_20 ) {
F_18 ( & V_19 -> V_22 , L_2 , V_20 ) ;
return V_20 ;
}
F_20 ( & V_11 -> V_14 ) ;
for ( V_21 = 0 ; V_21 < V_11 -> V_7 . V_25 . V_28 ; V_21 += 8 )
F_4 ( V_11 , V_21 , V_29 , 0xFF ) ;
F_21 ( V_11 -> V_7 . V_25 . V_22 , L_3 ) ;
return 0 ;
}
