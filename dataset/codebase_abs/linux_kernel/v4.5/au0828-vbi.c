static int F_1 ( struct V_1 * V_2 ,
unsigned int * V_3 , unsigned int * V_4 ,
unsigned int V_5 [] , void * V_6 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned long V_9 = V_8 -> V_10 * V_8 -> V_11 * 2 ;
if ( * V_4 )
return V_5 [ 0 ] < V_9 ? - V_12 : 0 ;
* V_4 = 1 ;
V_5 [ 0 ] = V_9 ;
return 0 ;
}
static int F_3 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = F_2 ( V_14 -> V_1 ) ;
unsigned long V_9 ;
V_9 = V_8 -> V_10 * V_8 -> V_11 * 2 ;
if ( F_4 ( V_14 , 0 ) < V_9 ) {
F_5 ( L_1 ,
V_15 , F_4 ( V_14 , 0 ) , V_9 ) ;
return - V_12 ;
}
F_6 ( V_14 , 0 , V_9 ) ;
return 0 ;
}
static void
F_7 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = F_2 ( V_14 -> V_1 ) ;
struct V_16 * V_17 = F_8 ( V_14 ) ;
struct V_18 * V_19 =
F_9 ( V_17 , struct V_18 , V_14 ) ;
struct V_20 * V_21 = & V_8 -> V_21 ;
unsigned long V_22 = 0 ;
V_19 -> V_23 = F_10 ( V_14 , 0 ) ;
V_19 -> V_24 = F_4 ( V_14 , 0 ) ;
F_11 ( & V_8 -> V_25 , V_22 ) ;
F_12 ( & V_19 -> V_26 , & V_21 -> V_27 ) ;
F_13 ( & V_8 -> V_25 , V_22 ) ;
}
