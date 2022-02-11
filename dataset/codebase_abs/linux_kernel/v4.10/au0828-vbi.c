static int F_1 ( struct V_1 * V_2 ,
unsigned int * V_3 , unsigned int * V_4 ,
unsigned int V_5 [] , struct V_6 * V_7 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 = V_9 -> V_11 * V_9 -> V_12 * 2 ;
if ( * V_4 )
return V_5 [ 0 ] < V_10 ? - V_13 : 0 ;
* V_4 = 1 ;
V_5 [ 0 ] = V_10 ;
return 0 ;
}
static int F_3 ( struct V_14 * V_15 )
{
struct V_8 * V_9 = F_2 ( V_15 -> V_1 ) ;
unsigned long V_10 ;
V_10 = V_9 -> V_11 * V_9 -> V_12 * 2 ;
if ( F_4 ( V_15 , 0 ) < V_10 ) {
F_5 ( L_1 ,
V_16 , F_4 ( V_15 , 0 ) , V_10 ) ;
return - V_13 ;
}
F_6 ( V_15 , 0 , V_10 ) ;
return 0 ;
}
static void
F_7 ( struct V_14 * V_15 )
{
struct V_8 * V_9 = F_2 ( V_15 -> V_1 ) ;
struct V_17 * V_18 = F_8 ( V_15 ) ;
struct V_19 * V_20 =
F_9 ( V_18 , struct V_19 , V_15 ) ;
struct V_21 * V_22 = & V_9 -> V_22 ;
unsigned long V_23 = 0 ;
V_20 -> V_24 = F_10 ( V_15 , 0 ) ;
V_20 -> V_25 = F_4 ( V_15 , 0 ) ;
F_11 ( & V_9 -> V_26 , V_23 ) ;
F_12 ( & V_20 -> V_27 , & V_22 -> V_28 ) ;
F_13 ( & V_9 -> V_26 , V_23 ) ;
}
