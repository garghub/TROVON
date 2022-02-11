static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
if ( ! ( F_2 ( V_4 , V_6 ) ) ) {
F_3 ( V_2 -> V_7 , L_1 ) ;
return 0 ;
}
V_5 = F_4 ( * ( V_8 * ) & V_4 -> V_9 [ V_4 -> V_5 - 2 ] ) ;
F_5 ( V_4 , V_5 ) ;
return 1 ;
}
static struct V_3 * F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_10 )
{
int V_11 = V_4 -> V_5 ;
int V_12 = V_11 + V_6 ;
int V_13 = F_7 ( V_4 ) ;
int V_14 = F_8 ( V_4 ) ;
int V_15 = 0 ;
V_8 * V_5 ;
if ( ( V_12 ) < V_2 -> V_16 )
V_15 = V_2 -> V_16 - V_12 + 1 ;
else if ( ! ( V_12 % V_2 -> V_16 ) )
V_15 = 1 ;
if ( ! F_9 ( V_4 ) &&
( V_13 + V_14 >= V_15 + V_6 ) ) {
if ( V_13 < V_6 || V_14 < V_15 ) {
V_4 -> V_9 = memmove ( V_4 -> V_17 + V_6 ,
V_4 -> V_9 , V_4 -> V_5 ) ;
F_10 ( V_4 , V_4 -> V_5 ) ;
}
} else {
struct V_3 * V_18 ;
V_18 = F_11 ( V_4 ,
V_6 ,
V_15 ,
V_10 ) ;
F_12 ( V_4 ) ;
if ( ! V_18 )
return NULL ;
V_4 = V_18 ;
}
V_11 += V_15 ;
V_11 &= 0x07ff ;
V_5 = F_13 ( V_4 , V_6 ) ;
* V_5 = F_14 ( V_11 ) ;
if( V_15 )
F_15 ( V_4 , V_15 ) ;
return V_4 ;
}
static void F_16 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_17 ( V_20 ) ;
T_2 V_21 = V_22 | V_23 ;
if ( V_20 -> V_10 & V_24 ) {
V_21 |= V_25 ;
F_18 ( V_2 -> V_7 , L_2 ) ;
} else if ( ! F_19 ( V_20 ) ||
( V_20 -> V_10 & V_26 ) ) {
V_21 |= V_27 ;
F_20 ( V_2 -> V_7 , L_3 ) ;
} else {
F_20 ( V_2 -> V_7 , L_4 ) ;
}
F_21 ( V_2 , V_28 ,
V_29 | V_30 | V_31 ,
V_21 , 0 , NULL , 0 ) ;
}
static int F_22 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
int V_34 = F_23 ( V_2 , 3 ) ;
if ( V_34 )
return V_34 ;
V_2 -> V_7 -> V_35 += V_6 ;
V_2 -> V_36 = V_2 -> V_7 -> V_37 + V_2 -> V_7 -> V_35 ;
V_2 -> V_7 -> V_38 = & V_39 ;
return F_24 ( V_2 , V_33 ) ;
}
