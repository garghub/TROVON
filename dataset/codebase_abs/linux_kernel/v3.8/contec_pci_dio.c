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
V_2 -> V_19 = V_2 -> V_20 -> V_21 ;
V_18 = F_7 ( V_17 , V_2 -> V_19 ) ;
if ( V_18 )
return V_18 ;
V_2 -> V_11 = F_8 ( V_17 , 0 ) ;
V_18 = F_9 ( V_2 , 2 ) ;
if ( V_18 )
return V_18 ;
V_4 = & V_2 -> V_22 [ 0 ] ;
V_4 -> type = V_23 ;
V_4 -> V_24 = V_25 ;
V_4 -> V_26 = 16 ;
V_4 -> V_27 = 1 ;
V_4 -> V_28 = & V_29 ;
V_4 -> V_30 = F_3 ;
V_4 = & V_2 -> V_22 [ 1 ] ;
V_4 -> type = V_31 ;
V_4 -> V_24 = V_32 ;
V_4 -> V_26 = 16 ;
V_4 -> V_27 = 1 ;
V_4 -> V_28 = & V_29 ;
V_4 -> V_30 = F_1 ;
F_10 ( V_2 -> V_33 , L_1 , V_2 -> V_19 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_6 ( V_2 ) ;
if ( V_17 ) {
if ( V_2 -> V_11 )
F_12 ( V_17 ) ;
}
}
static int F_13 ( struct V_16 * V_2 ,
const struct V_34 * V_35 )
{
return F_14 ( V_2 , & V_36 ) ;
}
static void F_15 ( struct V_16 * V_2 )
{
F_16 ( V_2 ) ;
}
