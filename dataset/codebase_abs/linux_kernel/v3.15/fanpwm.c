static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
struct V_5 * V_6 = ( void * ) V_4 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
int V_10 = F_2 ( V_2 ) -> V_10 ;
T_1 V_11 , V_12 ;
int V_13 ;
V_13 = V_2 -> V_14 ( V_2 , V_6 -> V_15 . line , & V_11 , & V_12 ) ;
if ( V_13 == 0 && V_11 ) {
V_11 = F_3 ( V_11 , V_12 ) ;
if ( V_10 <= V_16 || ( V_6 -> V_15 . log [ 0 ] & 1 ) )
V_12 = V_11 - V_12 ;
return ( V_12 * 100 ) / V_11 ;
}
return V_9 -> V_17 ( V_9 , 0 , V_6 -> V_15 . V_15 , V_6 -> V_15 . line ) * 100 ;
}
static int
F_4 ( struct V_1 * V_2 , int V_18 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
struct V_5 * V_6 = ( void * ) V_4 -> V_7 ;
int V_10 = F_2 ( V_2 ) -> V_10 ;
T_1 V_11 , V_12 ;
int V_13 ;
V_11 = V_6 -> V_19 . V_20 . V_21 ;
if ( V_6 -> V_19 . V_22 . V_23 ) {
V_11 = 1 ;
if ( V_2 -> V_24 )
V_11 = V_2 -> V_24 ( V_2 , V_6 -> V_15 . line ) ;
V_11 /= V_6 -> V_19 . V_22 . V_23 ;
}
V_12 = ( ( V_11 * V_18 ) + 99 ) / 100 ;
if ( V_10 <= V_16 || ( V_6 -> V_15 . log [ 0 ] & 1 ) )
V_12 = V_11 - V_12 ;
V_13 = V_2 -> V_25 ( V_2 , V_6 -> V_15 . line , V_11 , V_12 ) ;
if ( V_13 == 0 )
V_13 = V_2 -> V_26 ( V_2 , V_6 -> V_15 . line , true ) ;
return V_13 ;
}
int
F_5 ( struct V_1 * V_2 , struct V_27 * V_15 )
{
struct V_28 * V_29 = F_2 ( V_2 ) ;
struct V_3 * V_4 = ( void * ) V_2 ;
struct V_5 * V_6 ;
T_1 V_11 , V_12 ;
if ( ! F_6 ( V_29 -> V_30 , L_1 , V_15 -> V_31 ) ||
! V_2 -> V_26 ||
V_2 -> V_14 ( V_2 , V_15 -> line , & V_11 , & V_12 ) == - V_32 )
return - V_32 ;
V_6 = F_7 ( sizeof( * V_6 ) , V_33 ) ;
V_4 -> V_7 = & V_6 -> V_19 ;
if ( ! V_6 )
return - V_34 ;
V_6 -> V_19 . type = L_2 ;
V_6 -> V_19 . V_17 = F_1 ;
V_6 -> V_19 . V_35 = F_4 ;
V_6 -> V_15 = * V_15 ;
return 0 ;
}
