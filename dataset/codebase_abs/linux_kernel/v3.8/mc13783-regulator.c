static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
int V_7 ;
T_1 V_8 ;
F_2 ( V_4 & ~ V_3 ) ;
F_3 ( V_2 -> V_5 ) ;
V_7 = F_4 ( V_6 , V_9 , & V_8 ) ;
if ( V_7 )
goto V_10;
V_2 -> V_11 =
( V_2 -> V_11 & ~ V_3 ) | V_4 ;
V_2 -> V_11 &= V_12 ;
V_8 = ( V_8 & ~ V_3 ) | V_4 ;
V_8 = ( V_8 & ~ V_12 ) |
V_2 -> V_11 ;
V_7 = F_5 ( V_6 , V_9 , V_8 ) ;
V_10:
F_6 ( V_2 -> V_5 ) ;
return V_7 ;
}
static int F_7 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_8 ( V_14 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
int V_17 = F_9 ( V_14 ) ;
T_1 V_18 = V_16 [ V_17 ] . V_19 ;
F_10 ( F_11 ( V_14 ) , L_1 , V_20 , V_17 ) ;
if ( V_17 == V_21 ||
V_17 == V_22 )
V_18 = 0 ;
return F_1 ( V_2 , V_16 [ V_17 ] . V_19 ,
V_18 ) ;
}
static int F_12 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_8 ( V_14 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
int V_17 = F_9 ( V_14 ) ;
T_1 V_23 = 0 ;
F_10 ( F_11 ( V_14 ) , L_1 , V_20 , V_17 ) ;
if ( V_17 == V_21 ||
V_17 == V_22 )
V_23 = V_16 [ V_17 ] . V_19 ;
return F_1 ( V_2 , V_16 [ V_17 ] . V_19 ,
V_23 ) ;
}
static int F_13 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_8 ( V_14 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
int V_7 , V_17 = F_9 ( V_14 ) ;
unsigned int V_4 ;
F_3 ( V_2 -> V_5 ) ;
V_7 = F_4 ( V_2 -> V_5 , V_16 [ V_17 ] . V_24 , & V_4 ) ;
F_6 ( V_2 -> V_5 ) ;
if ( V_7 )
return V_7 ;
V_4 = ( V_4 & ~ V_12 ) |
( V_2 -> V_11 ^ V_12 ) ;
return ( V_4 & V_16 [ V_17 ] . V_19 ) != 0 ;
}
static int F_14 ( struct V_25 * V_26 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_15 ( V_26 -> V_27 . V_28 ) ;
struct V_29 * V_30 =
F_16 ( & V_26 -> V_27 ) ;
struct V_31 * V_32 ;
struct V_33 V_34 = { } ;
int V_35 , V_7 ;
F_10 ( & V_26 -> V_27 , L_2 , V_20 , V_26 -> V_17 ) ;
if ( ! V_30 )
return - V_36 ;
V_2 = F_17 ( & V_26 -> V_27 , sizeof( * V_2 ) +
V_30 -> V_37 * sizeof( V_2 -> V_38 [ 0 ] ) ,
V_39 ) ;
if ( ! V_2 )
return - V_40 ;
V_2 -> V_16 = V_41 ;
V_2 -> V_5 = V_6 ;
for ( V_35 = 0 ; V_35 < V_30 -> V_37 ; V_35 ++ ) {
struct V_42 * V_43 ;
V_32 = & V_30 -> V_38 [ V_35 ] ;
V_43 = & V_41 [ V_32 -> V_17 ] . V_43 ;
V_34 . V_27 = & V_26 -> V_27 ;
V_34 . V_32 = V_32 -> V_32 ;
V_34 . V_44 = V_2 ;
V_2 -> V_38 [ V_35 ] = F_18 ( V_43 , & V_34 ) ;
if ( F_19 ( V_2 -> V_38 [ V_35 ] ) ) {
F_20 ( & V_26 -> V_27 , L_3 ,
V_41 [ V_35 ] . V_43 . V_45 ) ;
V_7 = F_21 ( V_2 -> V_38 [ V_35 ] ) ;
goto V_46;
}
}
F_22 ( V_26 , V_2 ) ;
return 0 ;
V_46:
while ( -- V_35 >= 0 )
F_23 ( V_2 -> V_38 [ V_35 ] ) ;
return V_7 ;
}
static int F_24 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_25 ( V_26 ) ;
struct V_29 * V_30 =
F_16 ( & V_26 -> V_27 ) ;
int V_35 ;
F_22 ( V_26 , NULL ) ;
for ( V_35 = 0 ; V_35 < V_30 -> V_37 ; V_35 ++ )
F_23 ( V_2 -> V_38 [ V_35 ] ) ;
return 0 ;
}
static int T_2 F_26 ( void )
{
return F_27 ( & V_47 ) ;
}
static void T_3 F_28 ( void )
{
F_29 ( & V_47 ) ;
}
