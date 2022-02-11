static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 , int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned long long V_9 ;
int V_10 , V_11 ;
T_1 V_12 ;
V_9 = F_3 ( V_8 -> V_13 ) ;
V_10 = F_4 ( V_9 * V_6 ,
( unsigned long long ) V_14 * 256 ) ;
if ( ! V_10 || V_10 > 256 )
return - V_15 ;
if ( V_10 == 256 )
V_10 = 0 ;
V_11 = F_4 ( ( unsigned long long ) ( V_6 - V_5 ) * 256 ,
V_6 ) ;
if ( ! V_11 )
V_11 = 1 ;
if ( V_11 > 255 )
V_11 = 255 ;
V_12 = F_5 ( V_8 -> V_16 + ( V_4 -> V_17 << 2 ) ) ;
V_12 &= ~ 0xFFFF ;
V_12 |= ( V_10 << 8 ) | V_11 ;
F_6 ( V_12 , V_8 -> V_16 + ( V_4 -> V_17 << 2 ) ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_12 ;
int V_18 ;
V_18 = F_8 ( V_8 -> V_13 ) ;
if ( V_18 )
return V_18 ;
V_12 = F_5 ( V_8 -> V_16 + ( V_4 -> V_17 << 2 ) ) ;
V_12 |= V_19 ;
F_6 ( V_12 , V_8 -> V_16 + ( V_4 -> V_17 << 2 ) ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_12 ;
V_12 = F_5 ( V_8 -> V_16 + ( V_4 -> V_17 << 2 ) ) ;
V_12 &= ~ V_19 ;
F_6 ( V_12 , V_8 -> V_16 + ( V_4 -> V_17 << 2 ) ) ;
F_10 ( V_8 -> V_13 ) ;
}
static int F_11 ( struct V_20 * V_21 )
{
struct V_7 * V_8 ;
struct V_22 * V_23 ;
int V_18 ;
V_8 = F_12 ( & V_21 -> V_24 , sizeof( * V_8 ) , V_25 ) ;
if ( ! V_8 )
return - V_26 ;
V_23 = F_13 ( V_21 , V_27 , 0 ) ;
V_8 -> V_16 = F_14 ( & V_21 -> V_24 , V_23 ) ;
if ( F_15 ( V_8 -> V_16 ) )
return F_16 ( V_8 -> V_16 ) ;
V_8 -> V_13 = F_17 ( & V_21 -> V_24 , NULL ) ;
if ( F_15 ( V_8 -> V_13 ) )
return F_16 ( V_8 -> V_13 ) ;
V_8 -> V_2 . V_24 = & V_21 -> V_24 ;
V_8 -> V_2 . V_28 = & V_29 ;
V_8 -> V_2 . V_30 = 1 ;
V_8 -> V_2 . V_16 = - 1 ;
V_18 = F_18 ( & V_8 -> V_2 ) ;
if ( V_18 < 0 ) {
F_19 ( & V_21 -> V_24 , L_1 , V_18 ) ;
return V_18 ;
}
F_20 ( V_21 , V_8 ) ;
return 0 ;
}
static int F_21 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = F_22 ( V_21 ) ;
unsigned int V_31 ;
for ( V_31 = 0 ; V_31 < V_8 -> V_2 . V_30 ; V_31 ++ )
F_23 ( & V_8 -> V_2 . V_32 [ V_31 ] ) ;
return F_24 ( & V_8 -> V_2 ) ;
}
