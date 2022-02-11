static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 , int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned long long V_9 ;
int V_10 , V_11 ;
T_1 V_12 ;
V_9 = F_3 ( V_8 -> V_13 ) / 256 ;
V_9 = V_9 * V_6 ;
F_4 ( V_9 , V_14 ) ;
if ( V_9 == 0 )
V_9 = 1 ;
if ( V_9 > 255 )
V_9 = 0 ;
V_10 = V_9 ;
V_9 = 256 * V_5 ;
F_4 ( V_9 , V_6 ) ;
if ( V_9 > 255 )
V_9 = 255 ;
V_11 = 256 - V_9 ;
V_12 = F_5 ( V_8 -> V_15 + ( V_4 -> V_16 << 2 ) ) ;
V_12 &= ~ 0xFFFF ;
V_12 |= F_6 ( V_10 ) | F_7 ( V_11 ) ;
F_8 ( V_12 , V_8 -> V_15 + ( V_4 -> V_16 << 2 ) ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_12 ;
int V_17 ;
V_17 = F_10 ( V_8 -> V_13 ) ;
if ( V_17 )
return V_17 ;
V_12 = F_5 ( V_8 -> V_15 + ( V_4 -> V_16 << 2 ) ) ;
V_12 |= V_18 ;
F_8 ( V_12 , V_8 -> V_15 + ( V_4 -> V_16 << 2 ) ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_12 ;
V_12 = F_5 ( V_8 -> V_15 + ( V_4 -> V_16 << 2 ) ) ;
V_12 &= ~ V_18 ;
F_8 ( V_12 , V_8 -> V_15 + ( V_4 -> V_16 << 2 ) ) ;
F_12 ( V_8 -> V_13 ) ;
}
static int F_13 ( struct V_19 * V_20 )
{
struct V_7 * V_8 ;
struct V_21 * V_22 ;
int V_17 ;
V_8 = F_14 ( & V_20 -> V_23 , sizeof( * V_8 ) , V_24 ) ;
if ( ! V_8 )
return - V_25 ;
V_22 = F_15 ( V_20 , V_26 , 0 ) ;
if ( ! V_22 )
return - V_27 ;
V_8 -> V_15 = F_16 ( & V_20 -> V_23 , V_22 ) ;
if ( F_17 ( V_8 -> V_15 ) )
return F_18 ( V_8 -> V_15 ) ;
V_8 -> V_13 = F_19 ( & V_20 -> V_23 , NULL ) ;
if ( F_17 ( V_8 -> V_13 ) )
return F_18 ( V_8 -> V_13 ) ;
V_8 -> V_2 . V_23 = & V_20 -> V_23 ;
V_8 -> V_2 . V_28 = & V_29 ;
V_8 -> V_2 . V_30 = 2 ;
V_8 -> V_2 . V_15 = - 1 ;
V_17 = F_20 ( & V_8 -> V_2 ) ;
if ( V_17 < 0 ) {
F_21 ( & V_20 -> V_23 , L_1 , V_17 ) ;
return V_17 ;
}
F_22 ( V_20 , V_8 ) ;
return 0 ;
}
static int F_23 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = F_24 ( V_20 ) ;
unsigned int V_31 ;
for ( V_31 = 0 ; V_31 < V_8 -> V_2 . V_30 ; V_31 ++ )
F_25 ( & V_8 -> V_2 . V_32 [ V_31 ] ) ;
return F_26 ( & V_8 -> V_2 ) ;
}
