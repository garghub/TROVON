static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int * V_5 , unsigned int * V_6 ,
unsigned int V_7 [] , void * V_8 [] )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_12 ;
unsigned long V_13 ;
if ( V_4 )
V_13 = V_4 -> V_4 . V_14 . V_15 ;
else
V_13 = V_12 -> V_16 * V_12 -> V_17 * 2 ;
if ( 0 == * V_5 )
* V_5 = 32 ;
if ( * V_5 < 2 )
* V_5 = 2 ;
if ( * V_5 > 32 )
* V_5 = 32 ;
* V_6 = 1 ;
V_7 [ 0 ] = V_13 ;
return 0 ;
}
static int F_3 ( struct V_18 * V_19 )
{
struct V_9 * V_10 = F_2 ( V_19 -> V_1 ) ;
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_20 * V_21 = F_4 ( V_19 , struct V_20 , V_19 ) ;
unsigned long V_13 ;
V_13 = V_12 -> V_16 * V_12 -> V_17 * 2 ;
if ( F_5 ( V_19 , 0 ) < V_13 ) {
F_6 ( V_22 L_1 ,
V_23 , F_5 ( V_19 , 0 ) , V_13 ) ;
return - V_24 ;
}
F_7 ( & V_21 -> V_19 , 0 , V_13 ) ;
return 0 ;
}
static void
F_8 ( struct V_18 * V_19 )
{
struct V_9 * V_10 = F_2 ( V_19 -> V_1 ) ;
struct V_20 * V_21 = F_4 ( V_19 , struct V_20 , V_19 ) ;
struct V_25 * V_26 = & V_10 -> V_26 ;
unsigned long V_27 = 0 ;
V_21 -> V_28 = F_9 ( V_19 , 0 ) ;
V_21 -> V_29 = F_5 ( V_19 , 0 ) ;
F_10 ( & V_10 -> V_30 , V_27 ) ;
F_11 ( & V_21 -> V_31 , & V_26 -> V_32 ) ;
F_12 ( & V_10 -> V_30 , V_27 ) ;
}
