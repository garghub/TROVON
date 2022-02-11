static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
if ( F_2 ( V_4 , V_7 ) )
F_3 ( V_4 -> V_8 , V_2 -> V_9 + V_10 ) ;
V_7 [ 1 ] = V_4 -> V_8 ;
return V_6 -> V_11 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 1 ] = F_5 ( V_2 -> V_9 + V_12 ) ;
return V_6 -> V_11 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned long V_13 )
{
struct V_14 * V_15 = F_7 ( V_2 ) ;
struct V_3 * V_4 ;
int V_16 ;
V_16 = F_8 ( V_2 ) ;
if ( V_16 )
return V_16 ;
V_2 -> V_9 = F_9 ( V_15 , 0 ) ;
V_16 = F_10 ( V_2 , 2 ) ;
if ( V_16 )
return V_16 ;
V_4 = & V_2 -> V_17 [ 0 ] ;
V_4 -> type = V_18 ;
V_4 -> V_19 = V_20 ;
V_4 -> V_21 = 16 ;
V_4 -> V_22 = 1 ;
V_4 -> V_23 = & V_24 ;
V_4 -> V_25 = F_4 ;
V_4 = & V_2 -> V_17 [ 1 ] ;
V_4 -> type = V_26 ;
V_4 -> V_19 = V_27 ;
V_4 -> V_21 = 16 ;
V_4 -> V_22 = 1 ;
V_4 -> V_23 = & V_24 ;
V_4 -> V_25 = F_1 ;
F_11 ( V_2 -> V_28 , L_1 , V_2 -> V_29 ) ;
return 0 ;
}
static int F_12 ( struct V_14 * V_2 ,
const struct V_30 * V_31 )
{
return F_13 ( V_2 , & V_32 ,
V_31 -> V_33 ) ;
}
