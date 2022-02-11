static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int * V_5 , unsigned int * V_6 ,
unsigned int V_7 [] , void * V_8 [] )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
unsigned long V_11 ;
if ( V_4 )
V_11 = V_4 -> V_4 . V_12 . V_13 ;
else
V_11 = V_10 -> V_14 * V_10 -> V_15 * 2 ;
if ( 0 == * V_5 )
* V_5 = 32 ;
if ( * V_5 < 2 )
* V_5 = 2 ;
if ( * V_5 > 32 )
* V_5 = 32 ;
* V_6 = 1 ;
V_7 [ 0 ] = V_11 ;
return 0 ;
}
static int F_3 ( struct V_16 * V_17 )
{
struct V_9 * V_10 = F_2 ( V_17 -> V_1 ) ;
struct V_18 * V_19 = F_4 ( V_17 , struct V_18 , V_17 ) ;
unsigned long V_11 ;
V_11 = V_10 -> V_14 * V_10 -> V_15 * 2 ;
if ( F_5 ( V_17 , 0 ) < V_11 ) {
F_6 ( V_20 L_1 ,
V_21 , F_5 ( V_17 , 0 ) , V_11 ) ;
return - V_22 ;
}
F_7 ( & V_19 -> V_17 , 0 , V_11 ) ;
return 0 ;
}
static void
F_8 ( struct V_16 * V_17 )
{
struct V_9 * V_10 = F_2 ( V_17 -> V_1 ) ;
struct V_18 * V_19 = F_4 ( V_17 , struct V_18 , V_17 ) ;
struct V_23 * V_24 = & V_10 -> V_24 ;
unsigned long V_25 = 0 ;
V_19 -> V_26 = F_9 ( V_17 , 0 ) ;
V_19 -> V_27 = F_5 ( V_17 , 0 ) ;
F_10 ( & V_10 -> V_28 , V_25 ) ;
F_11 ( & V_19 -> V_29 , & V_24 -> V_30 ) ;
F_12 ( & V_10 -> V_28 , V_25 ) ;
}
