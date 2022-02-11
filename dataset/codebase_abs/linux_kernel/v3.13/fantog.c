static void
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = ( void * ) V_2 -> V_6 . V_7 ;
struct V_8 * V_9 = V_8 ( V_5 ) ;
struct V_10 * V_11 = V_10 ( V_5 ) ;
unsigned long V_12 ;
int V_13 ;
F_2 ( & V_2 -> V_14 , V_12 ) ;
if ( V_3 < 0 )
V_3 = V_2 -> V_3 ;
V_2 -> V_3 = V_3 ;
V_13 = ! V_11 -> V_15 ( V_11 , 0 , V_16 , 0xff ) ;
V_11 -> V_17 ( V_11 , 0 , V_16 , 0xff , V_13 ) ;
if ( F_3 ( & V_2 -> V_18 . V_19 ) && V_3 != ( V_13 * 100 ) ) {
T_1 V_20 = ( V_3 * V_2 -> V_21 ) / 100 ;
if ( ! V_13 )
V_20 = V_2 -> V_21 - V_20 ;
V_9 -> V_18 ( V_9 , V_20 * 1000 , & V_2 -> V_18 ) ;
}
F_4 ( & V_2 -> V_14 , V_12 ) ;
}
static void
F_5 ( struct V_22 * V_18 )
{
struct V_1 * V_2 =
F_6 ( V_18 , struct V_1 , V_18 ) ;
F_1 ( V_2 , - 1 ) ;
}
static int
F_7 ( struct V_23 * V_24 )
{
struct V_4 * V_5 = ( void * ) V_24 ;
struct V_1 * V_2 = ( void * ) V_5 -> V_25 ;
return V_2 -> V_3 ;
}
static int
F_8 ( struct V_23 * V_24 , int V_3 )
{
struct V_4 * V_5 = ( void * ) V_24 ;
struct V_1 * V_2 = ( void * ) V_5 -> V_25 ;
if ( V_24 -> V_26 )
V_24 -> V_26 ( V_24 , V_2 -> V_27 . line , false ) ;
F_1 ( V_2 , V_3 ) ;
return 0 ;
}
int
F_9 ( struct V_23 * V_24 , struct V_28 * V_27 )
{
struct V_4 * V_5 = ( void * ) V_24 ;
struct V_1 * V_2 ;
int V_29 ;
if ( V_24 -> V_26 ) {
V_29 = V_24 -> V_26 ( V_24 , V_27 -> line , false ) ;
if ( V_29 )
return V_29 ;
}
V_2 = F_10 ( sizeof( * V_2 ) , V_30 ) ;
V_5 -> V_25 = & V_2 -> V_6 ;
if ( ! V_2 )
return - V_31 ;
V_2 -> V_6 . type = L_1 ;
V_2 -> V_6 . V_15 = F_7 ;
V_2 -> V_6 . V_17 = F_8 ;
F_11 ( & V_2 -> V_18 , F_5 ) ;
V_2 -> V_21 = 100000 ;
V_2 -> V_3 = 100 ;
V_2 -> V_27 = * V_27 ;
F_12 ( & V_2 -> V_14 ) ;
return 0 ;
}
