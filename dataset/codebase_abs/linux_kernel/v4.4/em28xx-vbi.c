static int F_1 ( struct V_1 * V_2 , const void * V_3 ,
unsigned int * V_4 , unsigned int * V_5 ,
unsigned int V_6 [] , void * V_7 [] )
{
const struct V_8 * V_9 = V_3 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_13 ;
unsigned long V_14 ;
if ( V_9 )
V_14 = V_9 -> V_9 . V_15 . V_16 ;
else
V_14 = V_13 -> V_17 * V_13 -> V_18 * 2 ;
if ( 0 == * V_4 )
* V_4 = 32 ;
if ( * V_4 < 2 )
* V_4 = 2 ;
if ( * V_4 > 32 )
* V_4 = 32 ;
* V_5 = 1 ;
V_6 [ 0 ] = V_14 ;
return 0 ;
}
static int F_3 ( struct V_19 * V_20 )
{
struct V_10 * V_11 = F_2 ( V_20 -> V_1 ) ;
struct V_12 * V_13 = V_11 -> V_13 ;
unsigned long V_14 ;
V_14 = V_13 -> V_17 * V_13 -> V_18 * 2 ;
if ( F_4 ( V_20 , 0 ) < V_14 ) {
F_5 ( V_21 L_1 ,
V_22 , F_4 ( V_20 , 0 ) , V_14 ) ;
return - V_23 ;
}
F_6 ( V_20 , 0 , V_14 ) ;
return 0 ;
}
static void
F_7 ( struct V_19 * V_20 )
{
struct V_24 * V_25 = F_8 ( V_20 ) ;
struct V_10 * V_11 = F_2 ( V_20 -> V_1 ) ;
struct V_26 * V_27 =
F_9 ( V_25 , struct V_26 , V_20 ) ;
struct V_28 * V_29 = & V_11 -> V_29 ;
unsigned long V_30 = 0 ;
V_27 -> V_31 = F_10 ( V_20 , 0 ) ;
V_27 -> V_32 = F_4 ( V_20 , 0 ) ;
F_11 ( & V_11 -> V_33 , V_30 ) ;
F_12 ( & V_27 -> V_34 , & V_29 -> V_35 ) ;
F_13 ( & V_11 -> V_33 , V_30 ) ;
}
