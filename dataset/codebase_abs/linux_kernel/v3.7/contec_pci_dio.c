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
struct V_15 * V_16 )
{
struct V_3 * V_4 ;
int V_17 ;
F_6 ( V_2 , & V_16 -> V_2 ) ;
V_2 -> V_18 = V_2 -> V_19 -> V_20 ;
V_17 = F_7 ( V_16 , V_2 -> V_18 ) ;
if ( V_17 )
return V_17 ;
V_2 -> V_11 = F_8 ( V_16 , 0 ) ;
V_17 = F_9 ( V_2 , 2 ) ;
if ( V_17 )
return V_17 ;
V_4 = & V_2 -> V_21 [ 0 ] ;
V_4 -> type = V_22 ;
V_4 -> V_23 = V_24 ;
V_4 -> V_25 = 16 ;
V_4 -> V_26 = 1 ;
V_4 -> V_27 = & V_28 ;
V_4 -> V_29 = F_3 ;
V_4 = & V_2 -> V_21 [ 1 ] ;
V_4 -> type = V_30 ;
V_4 -> V_23 = V_31 ;
V_4 -> V_25 = 16 ;
V_4 -> V_26 = 1 ;
V_4 -> V_27 = & V_28 ;
V_4 -> V_29 = F_1 ;
F_10 ( V_2 -> V_32 , L_1 , V_2 -> V_18 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_12 ( V_2 ) ;
if ( V_16 ) {
if ( V_2 -> V_11 )
F_13 ( V_16 ) ;
}
}
static int T_1 F_14 ( struct V_15 * V_2 ,
const struct V_33 * V_34 )
{
return F_15 ( V_2 , & V_35 ) ;
}
static void T_2 F_16 ( struct V_15 * V_2 )
{
F_17 ( V_2 ) ;
}
