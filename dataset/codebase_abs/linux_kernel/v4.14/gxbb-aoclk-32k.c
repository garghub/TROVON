static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
T_1 V_7 , V_8 ;
F_3 ( V_5 -> V_9 , V_10 , & V_7 ) ;
F_3 ( V_5 -> V_9 , V_11 , & V_8 ) ;
if ( V_8 & V_12 )
return V_3 ;
if ( V_7 & V_13 ) {
unsigned long V_14 , V_15 , V_16 , V_17 , V_18 , V_19 , V_20 ;
V_6 = F_4 ( V_21 , V_7 ) + 1 ;
V_14 = F_4 ( V_22 , V_7 ) + 1 ;
V_15 = F_4 ( V_23 , V_8 ) + 1 ;
V_16 = F_4 ( V_24 , V_8 ) + 1 ;
V_17 = F_5 ( V_3 , V_6 ) ;
V_18 = F_5 ( V_3 , V_14 ) ;
V_19 = F_5 ( 100000000 * V_15 , V_17 * ( V_15 + V_16 ) ) ;
V_20 = F_5 ( 100000000 * V_16 , V_18 * ( V_15 + V_16 ) ) ;
return F_6 ( 100000000 , V_19 + V_20 ) ;
}
V_6 = F_4 ( V_21 , V_7 ) + 1 ;
return F_5 ( V_3 , V_6 ) ;
}
static const struct V_25 * F_7 ( unsigned long V_26 ,
unsigned long V_27 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < F_8 ( V_29 ) ; ++ V_28 )
if ( V_29 [ V_28 ] . V_3 == V_27 &&
V_29 [ V_28 ] . V_30 == V_26 )
return & V_29 [ V_28 ] ;
return NULL ;
}
static long F_9 ( struct V_1 * V_2 , unsigned long V_26 ,
unsigned long * V_27 )
{
const struct V_25 * V_31 = F_7 ( V_26 ,
* V_27 ) ;
if ( ! V_31 )
return V_29 [ 0 ] . V_30 ;
return V_31 -> V_30 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned long V_26 ,
unsigned long V_3 )
{
const struct V_25 * V_31 = F_7 ( V_26 ,
V_3 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_32 = 0 ;
if ( ! V_31 )
return - V_33 ;
F_11 ( V_5 -> V_9 , V_10 ,
V_34 | V_35 , 0 ) ;
V_32 = F_12 ( V_21 , V_31 -> V_6 - 1 ) ;
if ( V_31 -> V_36 )
V_32 |= V_13 |
F_12 ( V_22 , V_31 -> V_14 - 1 ) ;
F_13 ( V_5 -> V_9 , V_10 , V_32 ) ;
V_32 = F_12 ( V_23 , V_31 -> V_15 - 1 ) ;
if ( V_31 -> V_36 )
V_32 |= F_12 ( V_24 , V_31 -> V_16 - 1 ) ;
F_13 ( V_5 -> V_9 , V_11 , V_32 ) ;
F_11 ( V_5 -> V_9 , V_10 ,
V_34 , V_34 ) ;
F_14 ( 200 ) ;
F_11 ( V_5 -> V_9 , V_10 ,
V_35 , V_35 ) ;
F_11 ( V_5 -> V_9 , V_37 ,
V_38 , V_38 ) ;
F_11 ( V_5 -> V_9 ,
V_39 ,
V_40 ,
F_12 ( V_40 , 4 ) ) ;
return 0 ;
}
