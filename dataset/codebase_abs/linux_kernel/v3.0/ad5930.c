static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_6 )
{
struct V_7 V_8 ;
struct V_9 V_10 ;
int V_11 ;
struct V_12 * V_13 = (struct V_12 * ) V_5 ;
struct V_14 * V_15 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_15 -> V_18 ;
V_13 -> V_19 = ( V_13 -> V_19 & ~ V_20 ) ;
V_13 -> V_21 = ( V_13 -> V_19 & ~ V_20 ) | ( 1 << V_22 ) ;
V_13 -> V_23 [ 0 ] = ( V_13 -> V_19 & ~ V_20 ) | ( 2 << V_22 ) ;
V_13 -> V_23 [ 1 ] = ( V_13 -> V_19 & ~ V_20 ) | 3 << V_22 ;
V_13 -> V_24 = ( V_13 -> V_19 & ~ V_20 ) | 4 << V_22 ;
V_13 -> V_25 = ( V_13 -> V_19 & ~ V_20 ) | 8 << V_22 ;
V_13 -> V_26 [ 0 ] = ( V_13 -> V_19 & ~ V_20 ) | 0xc << V_22 ;
V_13 -> V_26 [ 1 ] = ( V_13 -> V_19 & ~ V_20 ) | 0xd << V_22 ;
V_10 . V_6 = V_6 ;
V_10 . V_27 = V_13 ;
F_3 ( & V_17 -> V_28 ) ;
F_4 ( & V_8 ) ;
F_5 ( & V_10 , & V_8 ) ;
V_11 = F_6 ( V_17 -> V_29 , & V_8 ) ;
if ( V_11 )
goto V_30;
V_30:
F_7 ( & V_17 -> V_28 ) ;
return V_11 ? V_11 : V_6 ;
}
static int T_3 F_8 ( struct V_31 * V_32 )
{
struct V_16 * V_17 ;
int V_11 = 0 ;
V_17 = F_9 ( sizeof( * V_17 ) , V_33 ) ;
if ( V_17 == NULL ) {
V_11 = - V_34 ;
goto V_30;
}
F_10 ( V_32 , V_17 ) ;
F_11 ( & V_17 -> V_28 ) ;
V_17 -> V_29 = V_32 ;
V_17 -> V_15 = F_12 ( 0 ) ;
if ( V_17 -> V_15 == NULL ) {
V_11 = - V_34 ;
goto V_35;
}
V_17 -> V_15 -> V_2 . V_36 = & V_32 -> V_2 ;
V_17 -> V_15 -> V_18 = ( void * ) ( V_17 ) ;
V_17 -> V_15 -> V_37 = & V_38 ;
V_17 -> V_15 -> V_39 = V_40 ;
V_11 = F_13 ( V_17 -> V_15 ) ;
if ( V_11 )
goto V_41;
V_32 -> V_42 = 2000000 ;
V_32 -> V_43 = V_44 ;
V_32 -> V_45 = 16 ;
F_14 ( V_32 ) ;
return 0 ;
V_41:
F_15 ( V_17 -> V_15 ) ;
V_35:
F_16 ( V_17 ) ;
V_30:
return V_11 ;
}
static int T_4 F_17 ( struct V_31 * V_32 )
{
struct V_16 * V_17 = F_18 ( V_32 ) ;
F_19 ( V_17 -> V_15 ) ;
F_16 ( V_17 ) ;
return 0 ;
}
static T_5 int F_20 ( void )
{
return F_21 ( & V_46 ) ;
}
static T_6 void F_22 ( void )
{
F_23 ( & V_46 ) ;
}
