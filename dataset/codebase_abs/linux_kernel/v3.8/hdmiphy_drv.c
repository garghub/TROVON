static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static unsigned long F_3 ( T_1 V_4 )
{
static const unsigned long V_5 [] = {
[ V_6 ] = 27000000 ,
[ V_7 ] = 27000000 ,
[ V_8 ] = 74176000 ,
[ V_9 ] = 74250000 ,
[ V_10 ] = 74250000 ,
[ V_11 ] = 74250000 ,
[ V_12 ] = 74250000 ,
[ V_13 ] = 74250000 ,
[ V_14 ] = 74250000 ,
[ V_15 ] = 148500000 ,
[ V_16 ] = 148500000 ,
} ;
if ( V_4 < F_4 ( V_5 ) )
return V_5 [ V_4 ] ;
else
return 0 ;
}
static const T_2 * F_5 ( T_1 V_4 , const struct V_17 * V_18 )
{
unsigned long V_5 ;
V_5 = F_3 ( V_4 ) ;
if ( ! V_5 )
return NULL ;
for (; V_18 -> V_5 ; ++ V_18 )
if ( V_18 -> V_5 == V_5 )
return V_18 -> V_19 ;
return NULL ;
}
static int F_6 ( struct V_2 * V_3 , int V_20 )
{
return 0 ;
}
static int F_7 ( struct V_2 * V_3 ,
struct V_21 * V_4 )
{
const T_2 * V_19 ;
T_2 V_22 [ 32 ] ;
int V_23 ;
struct V_1 * V_24 = F_1 ( V_3 ) ;
struct V_25 * V_26 = F_8 ( V_3 ) ;
struct V_27 * V_28 = & V_26 -> V_28 ;
F_9 ( V_28 , L_1 , V_4 -> V_4 ) ;
V_19 = F_5 ( V_4 -> V_4 , V_24 -> V_29 ) ;
if ( ! V_19 ) {
F_10 ( V_28 , L_2 ) ;
return - V_30 ;
}
memcpy ( V_22 , V_19 , 32 ) ;
V_23 = F_11 ( V_26 , V_22 , 32 ) ;
if ( V_23 != 32 ) {
F_10 ( V_28 , L_3 ) ;
return - V_31 ;
}
return 0 ;
}
static int F_12 ( struct V_2 * V_3 , int V_32 )
{
struct V_25 * V_26 = F_8 ( V_3 ) ;
struct V_27 * V_28 = & V_26 -> V_28 ;
T_2 V_22 [ 2 ] ;
int V_23 ;
F_9 ( V_28 , L_4 , V_32 ) ;
V_22 [ 0 ] = 0x1f ;
V_22 [ 1 ] = V_32 ? 0x80 : 0x00 ;
V_23 = F_11 ( V_26 , V_22 , 2 ) ;
if ( V_23 != 2 ) {
F_10 ( V_28 , L_5 , V_32 ) ;
return - V_31 ;
}
return 0 ;
}
static int F_13 ( struct V_25 * V_26 ,
const struct V_33 * V_34 )
{
struct V_1 * V_24 ;
V_24 = F_14 ( sizeof *V_24 , V_35 ) ;
if ( ! V_24 )
return - V_36 ;
V_24 -> V_29 = (struct V_17 * ) V_34 -> V_37 ;
F_15 ( & V_24 -> V_3 , V_26 , & V_38 ) ;
F_9 ( & V_26 -> V_28 , L_6 ) ;
return 0 ;
}
static int F_16 ( struct V_25 * V_26 )
{
struct V_2 * V_3 = F_17 ( V_26 ) ;
struct V_1 * V_24 = F_1 ( V_3 ) ;
F_18 ( V_24 ) ;
F_9 ( & V_26 -> V_28 , L_7 ) ;
return 0 ;
}
