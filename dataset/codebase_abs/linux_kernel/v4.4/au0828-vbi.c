static int F_1 ( struct V_1 * V_2 , const void * V_3 ,
unsigned int * V_4 , unsigned int * V_5 ,
unsigned int V_6 [] , void * V_7 [] )
{
const struct V_8 * V_9 = V_3 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
unsigned long V_12 = V_11 -> V_13 * V_11 -> V_14 * 2 ;
unsigned long V_15 ;
V_15 = V_9 ? ( V_9 -> V_9 . V_16 . V_17 *
( V_9 -> V_9 . V_16 . V_18 [ 0 ] + V_9 -> V_9 . V_16 . V_18 [ 1 ] ) ) : V_12 ;
if ( V_15 < V_12 )
return - V_19 ;
* V_5 = 1 ;
V_6 [ 0 ] = V_15 ;
return 0 ;
}
static int F_3 ( struct V_20 * V_21 )
{
struct V_10 * V_11 = F_2 ( V_21 -> V_1 ) ;
unsigned long V_15 ;
V_15 = V_11 -> V_13 * V_11 -> V_14 * 2 ;
if ( F_4 ( V_21 , 0 ) < V_15 ) {
F_5 ( L_1 ,
V_22 , F_4 ( V_21 , 0 ) , V_15 ) ;
return - V_19 ;
}
F_6 ( V_21 , 0 , V_15 ) ;
return 0 ;
}
static void
F_7 ( struct V_20 * V_21 )
{
struct V_10 * V_11 = F_2 ( V_21 -> V_1 ) ;
struct V_23 * V_24 = F_8 ( V_21 ) ;
struct V_25 * V_26 =
F_9 ( V_24 , struct V_25 , V_21 ) ;
struct V_27 * V_28 = & V_11 -> V_28 ;
unsigned long V_29 = 0 ;
V_26 -> V_30 = F_10 ( V_21 , 0 ) ;
V_26 -> V_31 = F_4 ( V_21 , 0 ) ;
F_11 ( & V_11 -> V_32 , V_29 ) ;
F_12 ( & V_26 -> V_33 , & V_28 -> V_34 ) ;
F_13 ( & V_11 -> V_32 , V_29 ) ;
}
