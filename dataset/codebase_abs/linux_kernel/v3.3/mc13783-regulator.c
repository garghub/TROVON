static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
int V_7 ;
T_1 V_8 ;
F_2 ( V_4 & ~ V_3 ) ;
V_7 = F_3 ( V_6 , V_9 , & V_8 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_10 =
( V_2 -> V_10 & ~ V_3 ) | V_4 ;
V_2 -> V_10 &= V_11 ;
V_8 = ( V_8 & ~ V_3 ) | V_4 ;
V_8 = ( V_8 & ~ V_11 ) |
V_2 -> V_10 ;
return F_4 ( V_6 , V_9 , V_8 ) ;
}
static int F_5 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_6 ( V_13 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
int V_16 = F_7 ( V_13 ) ;
int V_7 ;
T_1 V_17 = V_15 [ V_16 ] . V_18 ;
F_8 ( F_9 ( V_13 ) , L_1 , V_19 , V_16 ) ;
if ( V_16 == V_20 ||
V_16 == V_21 )
V_17 = 0 ;
F_10 ( V_2 -> V_5 ) ;
V_7 = F_1 ( V_2 , V_15 [ V_16 ] . V_18 ,
V_17 ) ;
F_11 ( V_2 -> V_5 ) ;
return V_7 ;
}
static int F_12 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_6 ( V_13 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
int V_16 = F_7 ( V_13 ) ;
int V_7 ;
T_1 V_22 = 0 ;
F_8 ( F_9 ( V_13 ) , L_1 , V_19 , V_16 ) ;
if ( V_16 == V_20 ||
V_16 == V_21 )
V_22 = V_15 [ V_16 ] . V_18 ;
F_10 ( V_2 -> V_5 ) ;
V_7 = F_1 ( V_2 , V_15 [ V_16 ] . V_18 ,
V_22 ) ;
F_11 ( V_2 -> V_5 ) ;
return V_7 ;
}
static int F_13 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_6 ( V_13 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
int V_7 , V_16 = F_7 ( V_13 ) ;
unsigned int V_4 ;
F_10 ( V_2 -> V_5 ) ;
V_7 = F_3 ( V_2 -> V_5 , V_15 [ V_16 ] . V_23 , & V_4 ) ;
F_11 ( V_2 -> V_5 ) ;
if ( V_7 )
return V_7 ;
V_4 = ( V_4 & ~ V_11 ) |
( V_2 -> V_10 ^ V_11 ) ;
return ( V_4 & V_15 [ V_16 ] . V_18 ) != 0 ;
}
static int T_2 F_14 ( struct V_24 * V_25 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_15 ( V_25 -> V_26 . V_27 ) ;
struct V_28 * V_29 =
F_16 ( & V_25 -> V_26 ) ;
struct V_30 * V_31 ;
int V_32 , V_7 ;
F_8 ( & V_25 -> V_26 , L_2 , V_19 , V_25 -> V_16 ) ;
V_2 = F_17 ( & V_25 -> V_26 , sizeof( * V_2 ) +
V_29 -> V_33 * sizeof( V_2 -> V_34 [ 0 ] ) ,
V_35 ) ;
if ( ! V_2 )
return - V_36 ;
V_2 -> V_15 = V_37 ;
V_2 -> V_5 = V_6 ;
for ( V_32 = 0 ; V_32 < V_29 -> V_33 ; V_32 ++ ) {
V_31 = & V_29 -> V_34 [ V_32 ] ;
V_2 -> V_34 [ V_32 ] = F_18 (
& V_37 [ V_31 -> V_16 ] . V_38 ,
& V_25 -> V_26 , V_31 -> V_31 , V_2 , NULL ) ;
if ( F_19 ( V_2 -> V_34 [ V_32 ] ) ) {
F_20 ( & V_25 -> V_26 , L_3 ,
V_37 [ V_32 ] . V_38 . V_39 ) ;
V_7 = F_21 ( V_2 -> V_34 [ V_32 ] ) ;
goto V_40;
}
}
F_22 ( V_25 , V_2 ) ;
return 0 ;
V_40:
while ( -- V_32 >= 0 )
F_23 ( V_2 -> V_34 [ V_32 ] ) ;
return V_7 ;
}
static int T_3 F_24 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_25 ( V_25 ) ;
struct V_28 * V_29 =
F_16 ( & V_25 -> V_26 ) ;
int V_32 ;
F_22 ( V_25 , NULL ) ;
for ( V_32 = 0 ; V_32 < V_29 -> V_33 ; V_32 ++ )
F_23 ( V_2 -> V_34 [ V_32 ] ) ;
return 0 ;
}
static int T_4 F_26 ( void )
{
return F_27 ( & V_41 ) ;
}
static void T_5 F_28 ( void )
{
F_29 ( & V_41 ) ;
}
