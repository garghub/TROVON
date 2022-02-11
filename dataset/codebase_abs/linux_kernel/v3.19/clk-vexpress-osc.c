static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 ;
F_3 ( V_5 -> V_7 , 0 , & V_6 ) ;
return V_6 ;
}
static long F_4 ( struct V_1 * V_2 , unsigned long V_6 ,
unsigned long * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( F_5 ( V_5 -> V_8 && V_6 < V_5 -> V_8 ) )
V_6 = V_5 -> V_8 ;
if ( F_5 ( V_5 -> V_9 && V_6 > V_5 -> V_9 ) )
V_6 = V_5 -> V_9 ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned long V_6 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_7 ( V_5 -> V_7 , 0 , V_6 ) ;
}
static int F_8 ( struct V_10 * V_11 )
{
struct V_12 V_13 ;
struct V_4 * V_5 ;
struct V_14 * V_14 ;
T_1 V_15 [ 2 ] ;
V_5 = F_9 ( & V_11 -> V_16 , sizeof( * V_5 ) , V_17 ) ;
if ( ! V_5 )
return - V_18 ;
V_5 -> V_7 = F_10 ( & V_11 -> V_16 ) ;
if ( F_11 ( V_5 -> V_7 ) )
return F_12 ( V_5 -> V_7 ) ;
if ( F_13 ( V_11 -> V_16 . V_19 , L_1 , V_15 ,
F_14 ( V_15 ) ) == 0 ) {
V_5 -> V_8 = V_15 [ 0 ] ;
V_5 -> V_9 = V_15 [ 1 ] ;
}
if ( F_15 ( V_11 -> V_16 . V_19 , L_2 ,
& V_13 . V_20 ) != 0 )
V_13 . V_20 = F_16 ( & V_11 -> V_16 ) ;
V_13 . V_21 = & V_22 ;
V_13 . V_23 = V_24 ;
V_13 . V_25 = 0 ;
V_5 -> V_2 . V_13 = & V_13 ;
V_14 = F_17 ( NULL , & V_5 -> V_2 ) ;
if ( F_11 ( V_14 ) )
return F_12 ( V_14 ) ;
F_18 ( V_11 -> V_16 . V_19 , V_26 , V_14 ) ;
F_19 ( & V_11 -> V_16 , L_3 , V_13 . V_20 ) ;
return 0 ;
}
static int T_2 F_20 ( void )
{
return F_21 ( & V_27 ) ;
}
