static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_7 . V_6 ;
struct V_8 * V_9 = V_6 -> V_9 ;
int V_10 = V_6 -> V_10 ;
T_1 V_11 , V_12 ;
int V_13 ;
V_13 = V_2 -> V_14 -> V_15 ( V_2 , V_4 -> V_14 . line , & V_11 , & V_12 ) ;
if ( V_13 == 0 && V_11 ) {
V_11 = F_2 ( V_11 , V_12 ) ;
if ( V_10 <= V_16 || ( V_4 -> V_14 . log [ 0 ] & 1 ) )
V_12 = V_11 - V_12 ;
return ( V_12 * 100 ) / V_11 ;
}
return F_3 ( V_9 , 0 , V_4 -> V_14 . V_14 , V_4 -> V_14 . line ) * 100 ;
}
static int
F_4 ( struct V_1 * V_2 , int V_17 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_4 ;
int V_10 = V_2 -> V_7 . V_6 -> V_10 ;
T_1 V_11 , V_12 ;
int V_13 ;
V_11 = V_4 -> V_18 . V_19 . V_20 ;
if ( V_4 -> V_18 . V_21 . V_22 ) {
V_11 = 1 ;
if ( V_2 -> V_14 -> V_23 )
V_11 = V_2 -> V_14 -> V_23 ( V_2 , V_4 -> V_14 . line ) ;
V_11 /= V_4 -> V_18 . V_21 . V_22 ;
}
V_12 = ( ( V_11 * V_17 ) + 99 ) / 100 ;
if ( V_10 <= V_16 || ( V_4 -> V_14 . log [ 0 ] & 1 ) )
V_12 = V_11 - V_12 ;
V_13 = V_2 -> V_14 -> V_24 ( V_2 , V_4 -> V_14 . line , V_11 , V_12 ) ;
if ( V_13 == 0 )
V_13 = V_2 -> V_14 -> V_25 ( V_2 , V_4 -> V_14 . line , true ) ;
return V_13 ;
}
int
F_5 ( struct V_1 * V_2 , struct V_26 * V_14 )
{
struct V_5 * V_6 = V_2 -> V_7 . V_6 ;
struct V_27 * V_21 = V_6 -> V_21 ;
struct V_3 * V_4 ;
struct V_28 V_29 = {} ;
T_1 V_11 , V_12 ;
F_6 ( V_21 , & V_29 ) ;
if ( ! F_7 ( V_6 -> V_30 , L_1 , V_14 -> V_31 ) ||
! V_2 -> V_14 -> V_25 || V_29 . type == V_32 ||
V_2 -> V_14 -> V_15 ( V_2 , V_14 -> line , & V_11 , & V_12 ) == - V_33 )
return - V_33 ;
V_4 = F_8 ( sizeof( * V_4 ) , V_34 ) ;
V_2 -> V_4 = & V_4 -> V_18 ;
if ( ! V_4 )
return - V_35 ;
V_4 -> V_18 . type = L_2 ;
V_4 -> V_18 . V_36 = F_1 ;
V_4 -> V_18 . V_37 = F_4 ;
V_4 -> V_14 = * V_14 ;
return 0 ;
}
