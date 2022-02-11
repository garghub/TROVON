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
struct V_16 * V_17 = F_3 ( V_15 ) ;
V_13 -> V_18 = ( V_13 -> V_18 & ~ V_19 ) ;
V_13 -> V_20 = ( V_13 -> V_18 & ~ V_19 ) | ( 1 << V_21 ) ;
V_13 -> V_22 [ 0 ] = ( V_13 -> V_18 & ~ V_19 ) | ( 2 << V_21 ) ;
V_13 -> V_22 [ 1 ] = ( V_13 -> V_18 & ~ V_19 ) | 3 << V_21 ;
V_13 -> V_23 = ( V_13 -> V_18 & ~ V_19 ) | 4 << V_21 ;
V_13 -> V_24 = ( V_13 -> V_18 & ~ V_19 ) | 8 << V_21 ;
V_13 -> V_25 [ 0 ] = ( V_13 -> V_18 & ~ V_19 ) | 0xc << V_21 ;
V_13 -> V_25 [ 1 ] = ( V_13 -> V_18 & ~ V_19 ) | 0xd << V_21 ;
V_10 . V_6 = V_6 ;
V_10 . V_26 = V_13 ;
F_4 ( & V_17 -> V_27 ) ;
F_5 ( & V_8 ) ;
F_6 ( & V_10 , & V_8 ) ;
V_11 = F_7 ( V_17 -> V_28 , & V_8 ) ;
if ( V_11 )
goto V_29;
V_29:
F_8 ( & V_17 -> V_27 ) ;
return V_11 ? V_11 : V_6 ;
}
static int T_3 F_9 ( struct V_30 * V_31 )
{
struct V_16 * V_17 ;
struct V_14 * V_15 ;
int V_11 = 0 ;
V_15 = F_10 ( sizeof( * V_17 ) ) ;
if ( V_15 == NULL ) {
V_11 = - V_32 ;
goto V_29;
}
F_11 ( V_31 , V_15 ) ;
V_17 = F_3 ( V_15 ) ;
F_12 ( & V_17 -> V_27 ) ;
V_17 -> V_28 = V_31 ;
V_15 -> V_2 . V_33 = & V_31 -> V_2 ;
V_15 -> V_34 = & V_35 ;
V_15 -> V_36 = V_37 ;
V_11 = F_13 ( V_15 ) ;
if ( V_11 )
goto V_38;
V_31 -> V_39 = 2000000 ;
V_31 -> V_40 = V_41 ;
V_31 -> V_42 = 16 ;
F_14 ( V_31 ) ;
return 0 ;
V_38:
F_15 ( V_15 ) ;
V_29:
return V_11 ;
}
static int T_4 F_16 ( struct V_30 * V_31 )
{
F_17 ( F_18 ( V_31 ) ) ;
F_15 ( F_18 ( V_31 ) ) ;
return 0 ;
}
static T_5 int F_19 ( void )
{
return F_20 ( & V_43 ) ;
}
static T_6 void F_21 ( void )
{
F_22 ( & V_43 ) ;
}
