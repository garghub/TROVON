int F_1 ( struct V_1 * V_2 ,
const unsigned long * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = & V_5 -> V_6 ;
unsigned int V_7 ;
T_1 * V_8 ;
if ( V_5 -> V_9 -> V_10 & V_11 )
return F_3 ( V_2 , V_3 ) ;
F_4 ( V_6 -> V_12 ) ;
F_4 ( V_6 -> V_13 ) ;
V_7 = ( V_2 -> V_14 - 1 ) * sizeof( V_15 ) ;
if ( V_5 -> V_9 -> V_10 & V_16 )
V_7 += sizeof( V_15 ) ;
V_6 -> V_12 = F_5 ( 2 , sizeof( * V_6 -> V_12 ) , V_17 ) ;
if ( ! V_6 -> V_12 )
return - V_18 ;
V_6 -> V_13 = F_6 ( V_7 + sizeof( V_15 ) , V_17 ) ;
if ( ! V_6 -> V_13 )
return - V_18 ;
V_8 = V_6 -> V_13 + V_7 ;
V_8 [ 0 ] = F_7 ( V_19 ) ;
V_8 [ 1 ] = 0 ;
V_6 -> V_12 [ 0 ] . V_20 = V_8 ;
V_6 -> V_12 [ 0 ] . V_21 = 8 ;
V_6 -> V_12 [ 0 ] . V_22 = 2 ;
V_6 -> V_12 [ 1 ] . V_23 = V_6 -> V_13 ;
V_6 -> V_12 [ 1 ] . V_21 = 8 ;
V_6 -> V_12 [ 1 ] . V_22 = V_7 ;
F_8 ( & V_6 -> V_24 ) ;
F_9 ( & V_6 -> V_12 [ 0 ] , & V_6 -> V_24 ) ;
F_9 ( & V_6 -> V_12 [ 1 ] , & V_6 -> V_24 ) ;
return 0 ;
}
T_2 F_10 ( int V_25 , void * V_26 )
{
struct V_27 * V_28 = V_26 ;
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = & V_5 -> V_6 ;
T_3 V_29 = V_5 -> V_6 . V_30 -> V_31 ;
void * V_13 ;
int V_32 ;
if ( ! V_6 -> V_13 )
return - V_18 ;
if ( ! ( V_5 -> V_9 -> V_10 & V_11 ) &&
V_5 -> V_6 . V_30 -> V_31 > V_33 ) {
V_5 -> V_6 . V_30 -> V_31 = V_33 ;
F_11 ( V_5 -> V_6 . V_30 ) ;
}
V_32 = F_12 ( V_6 -> V_30 , & V_6 -> V_24 ) ;
if ( V_32 )
F_13 ( & V_6 -> V_30 -> V_34 , L_1 , V_32 ) ;
if ( ! ( V_5 -> V_9 -> V_10 & V_11 ) ) {
V_5 -> V_6 . V_30 -> V_31 = V_29 ;
F_11 ( V_5 -> V_6 . V_30 ) ;
}
if ( V_5 -> V_9 -> V_10 & V_16 )
V_13 = V_6 -> V_13 + sizeof( V_15 ) ;
else
V_13 = V_6 -> V_13 ;
F_14 ( V_2 , V_13 ,
V_28 -> V_35 ) ;
F_15 ( V_2 -> V_36 ) ;
return V_37 ;
}
