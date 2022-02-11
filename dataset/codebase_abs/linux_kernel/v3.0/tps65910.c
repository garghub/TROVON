static int F_1 ( struct V_1 * V_1 , T_1 V_2 ,
int V_3 , void * V_4 )
{
struct V_5 * V_6 = V_1 -> V_5 ;
struct V_7 V_8 [ 2 ] ;
int V_9 ;
V_8 [ 0 ] . V_10 = V_6 -> V_10 ;
V_8 [ 0 ] . V_11 = 0 ;
V_8 [ 0 ] . V_12 = 1 ;
V_8 [ 0 ] . V_13 = & V_2 ;
V_8 [ 1 ] . V_10 = V_6 -> V_10 ;
V_8 [ 1 ] . V_11 = V_14 ;
V_8 [ 1 ] . V_12 = V_3 ;
V_8 [ 1 ] . V_13 = V_4 ;
V_9 = F_2 ( V_6 -> V_15 , V_8 , 2 ) ;
if ( V_9 == 2 )
V_9 = 0 ;
else if ( V_9 >= 0 )
V_9 = - V_16 ;
return V_9 ;
}
static int F_3 ( struct V_1 * V_1 , T_1 V_2 ,
int V_3 , void * V_17 )
{
struct V_5 * V_6 = V_1 -> V_5 ;
T_1 V_18 [ V_19 + 1 ] ;
int V_9 ;
if ( V_3 > V_19 )
return - V_20 ;
V_18 [ 0 ] = V_2 ;
memcpy ( & V_18 [ 1 ] , V_17 , V_3 ) ;
V_9 = F_4 ( V_6 , V_18 , V_3 + 1 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 != V_3 + 1 )
return - V_16 ;
return 0 ;
}
int F_5 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_21 )
{
T_1 V_22 ;
int V_23 ;
F_6 ( & V_1 -> V_24 ) ;
V_23 = F_1 ( V_1 , V_2 , 1 , & V_22 ) ;
if ( V_23 ) {
F_7 ( V_1 -> V_25 , L_1 , V_2 ) ;
goto V_26;
}
V_22 |= V_21 ;
V_23 = F_3 ( V_1 , V_2 , 1 , & V_22 ) ;
if ( V_23 )
F_7 ( V_1 -> V_25 , L_2 , V_2 ) ;
V_26:
F_8 ( & V_1 -> V_24 ) ;
return V_23 ;
}
int F_9 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_21 )
{
T_1 V_22 ;
int V_23 ;
F_6 ( & V_1 -> V_24 ) ;
V_23 = F_1 ( V_1 , V_2 , 1 , & V_22 ) ;
if ( V_23 ) {
F_7 ( V_1 -> V_25 , L_1 , V_2 ) ;
goto V_26;
}
V_22 &= V_21 ;
V_23 = F_3 ( V_1 , V_2 , 1 , & V_22 ) ;
if ( V_23 )
F_7 ( V_1 -> V_25 , L_2 , V_2 ) ;
V_26:
F_8 ( & V_1 -> V_24 ) ;
return V_23 ;
}
static int F_10 ( struct V_5 * V_6 ,
const struct V_27 * V_28 )
{
struct V_1 * V_1 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
int V_9 = 0 ;
V_30 = F_11 ( & V_6 -> V_25 ) ;
if ( ! V_30 )
return - V_20 ;
V_32 = F_12 ( sizeof( struct V_31 ) , V_33 ) ;
if ( V_32 == NULL )
return - V_34 ;
V_32 -> V_35 = V_30 -> V_35 ;
V_32 -> V_36 = V_30 -> V_35 ;
V_1 = F_12 ( sizeof( struct V_1 ) , V_33 ) ;
if ( V_1 == NULL )
return - V_34 ;
F_13 ( V_6 , V_1 ) ;
V_1 -> V_25 = & V_6 -> V_25 ;
V_1 -> V_5 = V_6 ;
V_1 -> V_28 = V_28 -> V_37 ;
V_1 -> V_38 = F_1 ;
V_1 -> V_39 = F_3 ;
F_14 ( & V_1 -> V_24 ) ;
V_9 = F_15 ( V_1 -> V_25 , - 1 ,
V_40 , F_16 ( V_40 ) ,
NULL , 0 ) ;
if ( V_9 < 0 )
goto V_23;
F_17 ( V_1 , V_30 -> V_41 ) ;
V_9 = F_18 ( V_1 , V_32 -> V_35 , V_32 ) ;
if ( V_9 < 0 )
goto V_23;
return V_9 ;
V_23:
F_19 ( V_1 -> V_25 ) ;
F_20 ( V_1 ) ;
return V_9 ;
}
static int F_21 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_22 ( V_6 ) ;
F_19 ( V_1 -> V_25 ) ;
F_20 ( V_1 ) ;
return 0 ;
}
static int T_2 F_23 ( void )
{
return F_24 ( & V_42 ) ;
}
static void T_3 F_25 ( void )
{
F_26 ( & V_42 ) ;
}
