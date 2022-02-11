static const struct V_1 * F_1 ( T_1 V_2 )
{
if ( V_2 < 0 || V_2 > V_3 )
return NULL ;
return & V_4 [ V_2 ] ;
}
static int F_2 ( struct V_5 * V_6 , struct V_7 * V_8 ,
struct V_9 * V_10 , T_2 V_11 )
{
const struct V_1 * V_12 ;
if ( ! ( V_6 -> V_13 & V_14 ) || ! V_8 -> V_15 ||
! V_10 -> type )
return 0 ;
if ( ! V_11 )
return 1 ;
V_12 = F_1 ( V_10 -> V_16 & V_17 ) ;
if ( ! V_12 )
return 1 ;
F_3 ( V_8 -> V_15 -> V_18 , V_10 -> type ,
V_12 -> V_19 , V_12 -> V_20 ) ;
return 1 ;
}
static int F_4 ( struct V_5 * V_6 , struct V_21 * V_22 ,
struct V_7 * V_8 , struct V_9 * V_10 ,
unsigned long * * V_23 , int * V_24 )
{
const struct V_1 * V_12 ;
if ( ( V_10 -> V_16 & V_25 ) == V_26 ) {
V_12 = F_1 ( V_10 -> V_16 & V_17 ) ;
if ( ! V_12 )
return - 1 ;
F_5 ( V_22 , V_10 , V_23 , V_24 , V_27 , V_12 -> V_19 ) ;
F_6 ( V_12 -> V_19 , V_22 -> V_18 -> V_28 ) ;
return 1 ;
}
return - 1 ;
}
static int F_7 ( struct V_5 * V_6 , struct V_21 * V_22 ,
struct V_7 * V_8 , struct V_9 * V_10 ,
unsigned long * * V_23 , int * V_24 )
{
if ( V_10 -> type == V_27 )
F_6 ( V_10 -> type , V_22 -> V_18 -> V_29 ) ;
return - 1 ;
}
