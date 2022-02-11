static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 , struct V_4 , V_6 ) ;
struct V_7 V_8 = {
. V_9 = & V_2 -> V_10 ,
. V_11 = V_3 ,
. V_12 = 2
} ;
V_2 -> V_10 = 0 ;
return F_3 ( V_5 , & V_8 , 1 ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_13 , T_1 V_14 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 , struct V_4 , V_6 ) ;
V_2 -> V_15 = F_5 ( F_6 ( 15 ) | ( V_13 << 12 ) | V_14 ) ;
return F_7 ( V_5 , & V_2 -> V_15 , sizeof( V_2 -> V_15 ) ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_13 , T_1 * V_14 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 , struct V_4 , V_6 ) ;
int V_16 ;
V_2 -> V_15 = F_5 ( ( V_17 << 11 ) | F_6 ( V_13 ) ) ;
V_16 = F_7 ( V_5 , & V_2 -> V_15 , sizeof( V_2 -> V_15 ) ) ;
if ( V_16 )
return V_16 ;
V_16 = F_1 ( V_2 , & V_2 -> V_15 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_1 ( V_2 , & V_2 -> V_15 ) ;
if ( V_16 )
return V_16 ;
* V_14 = F_9 ( V_2 -> V_15 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_18 , T_1 V_14 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 , struct V_4 , V_6 ) ;
V_2 -> V_15 = F_5 ( ( V_18 << 11 ) | V_14 ) ;
return F_7 ( V_5 , & V_2 -> V_15 , sizeof( V_2 -> V_15 ) ) ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_18 , T_1 * V_14 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 , struct V_4 , V_6 ) ;
int V_16 ;
V_2 -> V_15 = F_5 ( ( V_19 << 11 ) |
V_20 | ( V_18 << 2 ) ) ;
V_16 = F_7 ( V_5 , & V_2 -> V_15 , sizeof( V_2 -> V_15 ) ) ;
if ( V_16 )
return V_16 ;
V_16 = F_1 ( V_2 , & V_2 -> V_15 ) ;
if ( V_16 )
return V_16 ;
* V_14 = F_9 ( V_2 -> V_15 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_2 * V_14 )
{
int V_16 ;
V_16 = F_10 ( V_2 , V_21 ,
V_22 | V_2 -> V_23 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_1 ( V_2 , & V_2 -> V_15 ) ;
if ( V_16 )
return V_16 ;
* V_14 = ( T_2 ) F_9 ( V_2 -> V_15 ) ;
return 0 ;
}
static int F_13 ( struct V_4 * V_5 )
{
const struct V_24 * V_25 = F_14 ( V_5 ) ;
return F_15 ( & V_5 -> V_6 , V_25 -> V_26 , & V_27 ) ;
}
static int F_16 ( struct V_4 * V_5 )
{
return F_17 ( & V_5 -> V_6 ) ;
}
