static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( F_3 ( V_2 ) ) ;
return F_4 ( V_4 -> V_5 , V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_7 , T_1 * V_8 )
{
int V_9 ;
struct V_3 * V_4 = F_2 ( F_3 ( V_2 ) ) ;
V_9 = F_6 ( V_4 -> V_5 ,
V_10 + ( V_7 << 1 ) ) ;
if ( V_9 < 0 )
return V_9 ;
* V_8 = V_9 ;
return 0 ;
}
static int F_7 ( struct V_3 * V_4 , T_2 * V_11 )
{
int V_9 ;
T_3 V_12 [ 3 ] ;
V_9 = F_8 ( V_4 -> V_5 , V_13 ,
3 , V_12 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_11 = ( V_12 [ 0 ] << 16 ) | ( V_12 [ 1 ] << 8 ) | V_12 [ 2 ] ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
T_2 * V_14 , T_2 * V_15 )
{
int V_9 ;
struct V_3 * V_4 = F_2 ( F_3 ( V_2 ) ) ;
const struct V_16 * V_17 = V_4 -> V_18 ;
V_9 = F_4 ( V_4 -> V_5 , V_17 -> V_19 ) ;
if ( V_9 < 0 )
return V_9 ;
F_10 ( V_17 -> V_20 , V_17 -> V_20 + ( V_17 -> V_20 / 10UL ) ) ;
V_9 = F_7 ( V_4 , V_14 ) ;
if ( V_9 < 0 )
return V_9 ;
V_17 = V_4 -> V_21 ;
V_9 = F_4 ( V_4 -> V_5 , V_17 -> V_19 ) ;
if ( V_9 < 0 )
return V_9 ;
F_10 ( V_17 -> V_20 , V_17 -> V_20 + ( V_17 -> V_20 / 10UL ) ) ;
return F_7 ( V_4 , V_15 ) ;
}
static int F_11 ( struct V_22 * V_5 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 ;
struct V_25 * V_26 ;
if ( ! F_12 ( V_5 -> V_27 ,
V_28 |
V_29 |
V_30 ) )
return - V_31 ;
V_26 = F_13 ( & V_5 -> V_2 , sizeof( * V_4 ) ) ;
if ( ! V_26 )
return - V_32 ;
V_4 = F_2 ( V_26 ) ;
F_14 ( V_5 , V_26 ) ;
V_4 -> V_33 = F_1 ;
V_4 -> V_34 = F_5 ;
V_4 -> V_35 = F_9 ;
V_4 -> V_5 = V_5 ;
return F_15 ( V_26 , & V_5 -> V_2 , V_24 -> V_36 , V_24 -> V_37 ) ;
}
static int F_16 ( struct V_22 * V_5 )
{
return F_17 ( F_18 ( V_5 ) ) ;
}
