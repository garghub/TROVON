static int F_1 ( struct V_1 * V_2 ,
unsigned int * V_3 , unsigned int * V_4 ,
unsigned int V_5 [] , void * V_6 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_8 -> V_10 ;
unsigned long V_11 = V_10 -> V_12 * V_10 -> V_13 * 2 ;
if ( * V_3 < 2 )
* V_3 = 2 ;
if ( * V_4 ) {
if ( V_5 [ 0 ] < V_11 )
return - V_14 ;
V_11 = V_5 [ 0 ] ;
}
* V_4 = 1 ;
V_5 [ 0 ] = V_11 ;
return 0 ;
}
static int F_3 ( struct V_15 * V_16 )
{
struct V_7 * V_8 = F_2 ( V_16 -> V_1 ) ;
struct V_9 * V_10 = V_8 -> V_10 ;
unsigned long V_11 ;
V_11 = V_10 -> V_12 * V_10 -> V_13 * 2 ;
if ( F_4 ( V_16 , 0 ) < V_11 ) {
F_5 ( V_17 L_1 ,
V_18 , F_4 ( V_16 , 0 ) , V_11 ) ;
return - V_14 ;
}
F_6 ( V_16 , 0 , V_11 ) ;
return 0 ;
}
static void
F_7 ( struct V_15 * V_16 )
{
struct V_19 * V_20 = F_8 ( V_16 ) ;
struct V_7 * V_8 = F_2 ( V_16 -> V_1 ) ;
struct V_21 * V_22 =
F_9 ( V_20 , struct V_21 , V_16 ) ;
struct V_23 * V_24 = & V_8 -> V_24 ;
unsigned long V_25 = 0 ;
V_22 -> V_26 = F_10 ( V_16 , 0 ) ;
V_22 -> V_27 = F_4 ( V_16 , 0 ) ;
F_11 ( & V_8 -> V_28 , V_25 ) ;
F_12 ( & V_22 -> V_29 , & V_24 -> V_30 ) ;
F_13 ( & V_8 -> V_28 , V_25 ) ;
}
