static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_8 = V_7 [ 0 ] ;
unsigned int V_9 = V_7 [ 1 ] ;
if ( V_8 ) {
V_4 -> V_10 &= ~ V_8 ;
V_4 -> V_10 |= ( V_9 & V_8 ) ;
F_2 ( V_4 -> V_10 , V_2 -> V_11 + V_12 ) ;
}
V_7 [ 1 ] = V_4 -> V_10 ;
return V_6 -> V_13 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 1 ] = F_4 ( V_2 -> V_11 + V_14 ) ;
return V_6 -> V_13 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned long V_15 )
{
struct V_16 * V_17 = F_6 ( V_2 ) ;
struct V_3 * V_4 ;
int V_18 ;
V_18 = F_7 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_2 -> V_11 = F_8 ( V_17 , 0 ) ;
V_18 = F_9 ( V_2 , 2 ) ;
if ( V_18 )
return V_18 ;
V_4 = & V_2 -> V_19 [ 0 ] ;
V_4 -> type = V_20 ;
V_4 -> V_21 = V_22 ;
V_4 -> V_23 = 16 ;
V_4 -> V_24 = 1 ;
V_4 -> V_25 = & V_26 ;
V_4 -> V_27 = F_3 ;
V_4 = & V_2 -> V_19 [ 1 ] ;
V_4 -> type = V_28 ;
V_4 -> V_21 = V_29 ;
V_4 -> V_23 = 16 ;
V_4 -> V_24 = 1 ;
V_4 -> V_25 = & V_26 ;
V_4 -> V_27 = F_1 ;
F_10 ( V_2 -> V_30 , L_1 , V_2 -> V_31 ) ;
return 0 ;
}
static int F_11 ( struct V_16 * V_2 ,
const struct V_32 * V_33 )
{
return F_12 ( V_2 , & V_34 ,
V_33 -> V_35 ) ;
}
