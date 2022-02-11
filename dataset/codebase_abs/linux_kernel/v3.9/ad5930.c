static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_6 )
{
struct V_7 V_8 ;
int V_9 ;
struct V_10 * V_11 = (struct V_10 * ) V_5 ;
struct V_12 * V_13 = F_2 ( V_2 ) ;
struct V_14 * V_15 = F_3 ( V_13 ) ;
V_11 -> V_16 = ( V_11 -> V_16 & ~ V_17 ) ;
V_11 -> V_18 = ( V_11 -> V_16 & ~ V_17 ) | ( 1 << V_19 ) ;
V_11 -> V_20 [ 0 ] = ( V_11 -> V_16 & ~ V_17 ) | ( 2 << V_19 ) ;
V_11 -> V_20 [ 1 ] = ( V_11 -> V_16 & ~ V_17 ) | 3 << V_19 ;
V_11 -> V_21 = ( V_11 -> V_16 & ~ V_17 ) | 4 << V_19 ;
V_11 -> V_22 = ( V_11 -> V_16 & ~ V_17 ) | 8 << V_19 ;
V_11 -> V_23 [ 0 ] = ( V_11 -> V_16 & ~ V_17 ) | 0xc << V_19 ;
V_11 -> V_23 [ 1 ] = ( V_11 -> V_16 & ~ V_17 ) | 0xd << V_19 ;
V_8 . V_6 = V_6 ;
V_8 . V_24 = V_11 ;
F_4 ( & V_15 -> V_25 ) ;
V_9 = F_5 ( V_15 -> V_26 , & V_8 , 1 ) ;
if ( V_9 )
goto V_27;
V_27:
F_6 ( & V_15 -> V_25 ) ;
return V_9 ? V_9 : V_6 ;
}
static int F_7 ( struct V_28 * V_29 )
{
struct V_14 * V_15 ;
struct V_12 * V_13 ;
int V_9 = 0 ;
V_13 = F_8 ( sizeof( * V_15 ) ) ;
if ( V_13 == NULL ) {
V_9 = - V_30 ;
goto V_27;
}
F_9 ( V_29 , V_13 ) ;
V_15 = F_3 ( V_13 ) ;
F_10 ( & V_15 -> V_25 ) ;
V_15 -> V_26 = V_29 ;
V_13 -> V_2 . V_31 = & V_29 -> V_2 ;
V_13 -> V_32 = & V_33 ;
V_13 -> V_34 = V_35 ;
V_9 = F_11 ( V_13 ) ;
if ( V_9 )
goto V_36;
V_29 -> V_37 = 2000000 ;
V_29 -> V_38 = V_39 ;
V_29 -> V_40 = 16 ;
F_12 ( V_29 ) ;
return 0 ;
V_36:
F_13 ( V_13 ) ;
V_27:
return V_9 ;
}
static int F_14 ( struct V_28 * V_29 )
{
F_15 ( F_16 ( V_29 ) ) ;
F_13 ( F_16 ( V_29 ) ) ;
return 0 ;
}
