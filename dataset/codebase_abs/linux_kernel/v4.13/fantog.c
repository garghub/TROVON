static void
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
struct V_8 * V_9 = V_5 -> V_10 . V_9 ;
struct V_11 * V_12 = V_9 -> V_13 ;
struct V_14 * V_15 = V_9 -> V_15 ;
unsigned long V_16 ;
int V_17 ;
F_2 ( & V_2 -> V_18 , V_16 ) ;
if ( V_3 < 0 )
V_3 = V_2 -> V_3 ;
V_2 -> V_3 = V_3 ;
V_17 = ! F_3 ( V_15 , 0 , V_19 , 0xff ) ;
F_4 ( V_15 , 0 , V_19 , 0xff , V_17 ) ;
if ( V_3 != ( V_17 * 100 ) ) {
T_1 V_20 = ( V_3 * V_2 -> V_21 ) / 100 ;
if ( ! V_17 )
V_20 = V_2 -> V_21 - V_20 ;
F_5 ( V_12 , V_20 * 1000 , & V_2 -> V_22 ) ;
}
F_6 ( & V_2 -> V_18 , V_16 ) ;
}
static void
F_7 ( struct V_23 * V_22 )
{
struct V_1 * V_2 =
F_8 ( V_22 , struct V_1 , V_22 ) ;
F_1 ( V_2 , - 1 ) ;
}
static int
F_9 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = ( void * ) V_5 -> V_2 ;
return V_2 -> V_3 ;
}
static int
F_10 ( struct V_4 * V_5 , int V_3 )
{
struct V_1 * V_2 = ( void * ) V_5 -> V_2 ;
if ( V_5 -> V_24 -> V_25 )
V_5 -> V_24 -> V_25 ( V_5 , V_2 -> V_24 . line , false ) ;
F_1 ( V_2 , V_3 ) ;
return 0 ;
}
int
F_11 ( struct V_4 * V_5 , struct V_26 * V_24 )
{
struct V_1 * V_2 ;
int V_27 ;
if ( V_5 -> V_24 -> V_25 ) {
V_27 = V_5 -> V_24 -> V_25 ( V_5 , V_24 -> line , false ) ;
if ( V_27 )
return V_27 ;
}
V_2 = F_12 ( sizeof( * V_2 ) , V_28 ) ;
V_5 -> V_2 = & V_2 -> V_6 ;
if ( ! V_2 )
return - V_29 ;
V_2 -> V_6 . type = L_1 ;
V_2 -> V_6 . V_30 = F_9 ;
V_2 -> V_6 . V_31 = F_10 ;
F_13 ( & V_2 -> V_22 , F_7 ) ;
V_2 -> V_21 = 100000 ;
V_2 -> V_3 = 100 ;
V_2 -> V_24 = * V_24 ;
F_14 ( & V_2 -> V_18 ) ;
return 0 ;
}
