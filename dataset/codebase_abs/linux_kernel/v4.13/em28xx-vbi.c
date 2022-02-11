static int F_1 ( struct V_1 * V_2 ,
unsigned int * V_3 , unsigned int * V_4 ,
unsigned int V_5 [] , struct V_6 * V_7 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
unsigned long V_12 = V_11 -> V_13 * V_11 -> V_14 * 2 ;
if ( * V_3 < 2 )
* V_3 = 2 ;
if ( * V_4 ) {
if ( V_5 [ 0 ] < V_12 )
return - V_15 ;
V_12 = V_5 [ 0 ] ;
}
* V_4 = 1 ;
V_5 [ 0 ] = V_12 ;
return 0 ;
}
static int F_3 ( struct V_16 * V_17 )
{
struct V_8 * V_9 = F_2 ( V_17 -> V_1 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
unsigned long V_12 ;
V_12 = V_11 -> V_13 * V_11 -> V_14 * 2 ;
if ( F_4 ( V_17 , 0 ) < V_12 ) {
F_5 ( & V_9 -> V_18 -> V_9 ,
L_1 ,
V_19 , F_4 ( V_17 , 0 ) , V_12 ) ;
return - V_15 ;
}
F_6 ( V_17 , 0 , V_12 ) ;
return 0 ;
}
static void
F_7 ( struct V_16 * V_17 )
{
struct V_20 * V_21 = F_8 ( V_17 ) ;
struct V_8 * V_9 = F_2 ( V_17 -> V_1 ) ;
struct V_22 * V_23 =
F_9 ( V_21 , struct V_22 , V_17 ) ;
struct V_24 * V_25 = & V_9 -> V_25 ;
unsigned long V_26 = 0 ;
V_23 -> V_27 = F_10 ( V_17 , 0 ) ;
V_23 -> V_28 = F_4 ( V_17 , 0 ) ;
F_11 ( & V_9 -> V_29 , V_26 ) ;
F_12 ( & V_23 -> V_30 , & V_25 -> V_31 ) ;
F_13 ( & V_9 -> V_29 , V_26 ) ;
}
