static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int * V_5 , unsigned int * V_6 ,
unsigned int V_7 [] , void * V_8 [] )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
unsigned long V_11 = V_10 -> V_12 * V_10 -> V_13 * 2 ;
unsigned long V_14 ;
V_14 = V_4 ? ( V_4 -> V_4 . V_15 . V_16 *
( V_4 -> V_4 . V_15 . V_17 [ 0 ] + V_4 -> V_4 . V_15 . V_17 [ 1 ] ) ) : V_11 ;
if ( V_14 < V_11 )
return - V_18 ;
* V_6 = 1 ;
V_7 [ 0 ] = V_14 ;
return 0 ;
}
static int F_3 ( struct V_19 * V_20 )
{
struct V_9 * V_10 = F_2 ( V_20 -> V_1 ) ;
struct V_21 * V_22 = F_4 ( V_20 , struct V_21 , V_20 ) ;
unsigned long V_14 ;
V_14 = V_10 -> V_12 * V_10 -> V_13 * 2 ;
if ( F_5 ( V_20 , 0 ) < V_14 ) {
F_6 ( L_1 ,
V_23 , F_5 ( V_20 , 0 ) , V_14 ) ;
return - V_18 ;
}
F_7 ( & V_22 -> V_20 , 0 , V_14 ) ;
return 0 ;
}
static void
F_8 ( struct V_19 * V_20 )
{
struct V_9 * V_10 = F_2 ( V_20 -> V_1 ) ;
struct V_21 * V_22 = F_4 ( V_20 , struct V_21 , V_20 ) ;
struct V_24 * V_25 = & V_10 -> V_25 ;
unsigned long V_26 = 0 ;
V_22 -> V_27 = F_9 ( V_20 , 0 ) ;
V_22 -> V_28 = F_5 ( V_20 , 0 ) ;
F_10 ( & V_10 -> V_29 , V_26 ) ;
F_11 ( & V_22 -> V_30 , & V_25 -> V_31 ) ;
F_12 ( & V_10 -> V_29 , V_26 ) ;
}
