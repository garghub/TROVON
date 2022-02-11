static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
unsigned long V_10 = 0 ;
if ( F_2 () )
F_3 () ;
F_4 ( & V_9 -> V_11 , V_10 ) ;
if ( V_9 -> V_12 . V_13 == V_4 )
V_9 -> V_12 . V_13 = NULL ;
F_5 ( & V_9 -> V_11 , V_10 ) ;
F_6 ( & V_4 -> V_14 ) ;
V_4 -> V_14 . V_15 = V_16 ;
}
static int
F_7 ( struct V_1 * V_17 , unsigned int * V_18 , unsigned int * V_19 )
{
struct V_5 * V_6 = V_17 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
* V_19 = V_9 -> V_20 * V_9 -> V_21 * 2 ;
if ( 0 == * V_18 )
* V_18 = V_22 ;
if ( * V_18 < 2 )
* V_18 = 2 ;
if ( * V_18 > 32 )
* V_18 = 32 ;
return 0 ;
}
static int
F_8 ( struct V_1 * V_17 , struct V_23 * V_14 ,
enum V_24 V_25 )
{
struct V_5 * V_6 = V_17 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_3 * V_4 = F_9 ( V_14 , struct V_3 , V_14 ) ;
int V_26 = 0 ;
V_4 -> V_14 . V_19 = V_9 -> V_20 * V_9 -> V_21 * 2 ;
if ( 0 != V_4 -> V_14 . V_27 && V_4 -> V_14 . V_28 < V_4 -> V_14 . V_19 )
return - V_29 ;
V_4 -> V_14 . V_30 = V_9 -> V_20 ;
V_4 -> V_14 . V_31 = V_9 -> V_21 ;
V_4 -> V_14 . V_25 = V_25 ;
if ( V_16 == V_4 -> V_14 . V_15 ) {
V_26 = F_10 ( V_17 , & V_4 -> V_14 , NULL ) ;
if ( V_26 < 0 )
goto V_32;
}
V_4 -> V_14 . V_15 = V_33 ;
return 0 ;
V_32:
F_1 ( V_17 , V_4 ) ;
return V_26 ;
}
static void
F_11 ( struct V_1 * V_2 , struct V_23 * V_14 )
{
struct V_3 * V_4 = F_9 ( V_14 ,
struct V_3 ,
V_14 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_34 * V_35 = & V_9 -> V_35 ;
V_4 -> V_14 . V_15 = V_36 ;
F_12 ( & V_4 -> V_14 . V_37 , & V_35 -> V_38 ) ;
}
static void F_13 ( struct V_1 * V_17 , struct V_23 * V_14 )
{
struct V_3 * V_4 = F_9 ( V_14 , struct V_3 , V_14 ) ;
F_1 ( V_17 , V_4 ) ;
}
