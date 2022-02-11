static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static const T_1 * F_3 ( unsigned long V_4 ,
const struct V_5 * V_6 )
{
for (; V_6 -> V_4 ; ++ V_6 )
if ( V_6 -> V_4 == V_4 )
return V_6 -> V_7 ;
return NULL ;
}
static int F_4 ( struct V_2 * V_3 , int V_8 )
{
return 0 ;
}
static int F_5 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
const T_1 * V_7 ;
T_1 V_11 [ 32 ] ;
int V_12 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_14 * V_15 = F_6 ( V_3 ) ;
struct V_16 * V_17 = & V_15 -> V_17 ;
unsigned long V_4 = V_10 -> V_18 . V_19 ;
F_7 ( V_17 , L_1 ) ;
if ( ( V_10 -> V_18 . V_20 & V_21 ) && V_4 == 74250000 )
V_4 = 74176000 ;
V_7 = F_3 ( V_4 , V_13 -> V_22 ) ;
if ( ! V_7 ) {
F_8 ( V_17 , L_2 ) ;
return - V_23 ;
}
memcpy ( V_11 , V_7 , 32 ) ;
V_12 = F_9 ( V_15 , V_11 , 32 ) ;
if ( V_12 != 32 ) {
F_8 ( V_17 , L_3 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_10 ( struct V_2 * V_3 ,
struct V_25 * V_26 )
{
V_26 -> type = V_27 ;
V_26 -> V_18 . V_28 = 27000000 ;
V_26 -> V_18 . V_29 = 148500000 ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 , int V_30 )
{
struct V_14 * V_15 = F_6 ( V_3 ) ;
struct V_16 * V_17 = & V_15 -> V_17 ;
T_1 V_11 [ 2 ] ;
int V_12 ;
F_7 ( V_17 , L_4 , V_30 ) ;
V_11 [ 0 ] = 0x1f ;
V_11 [ 1 ] = V_30 ? 0x80 : 0x00 ;
V_12 = F_9 ( V_15 , V_11 , 2 ) ;
if ( V_12 != 2 ) {
F_8 ( V_17 , L_5 , V_30 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_12 ( struct V_14 * V_15 ,
const struct V_31 * V_32 )
{
struct V_1 * V_13 ;
V_13 = F_13 ( sizeof( * V_13 ) , V_33 ) ;
if ( ! V_13 )
return - V_34 ;
V_13 -> V_22 = (struct V_5 * ) V_32 -> V_35 ;
F_14 ( & V_13 -> V_3 , V_15 , & V_36 ) ;
F_7 ( & V_15 -> V_17 , L_6 ) ;
return 0 ;
}
static int F_15 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = F_16 ( V_15 ) ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
F_17 ( V_13 ) ;
F_7 ( & V_15 -> V_17 , L_7 ) ;
return 0 ;
}
