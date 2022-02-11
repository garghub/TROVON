static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 )
{
if ( V_3 > V_4 )
return - V_5 ;
if ( V_3 < 15 )
return 900000 + ( V_3 * 50000 ) ;
else
return 1700000 + ( ( V_3 - 15 ) * 100000 ) ;
}
static int F_2 ( struct V_1 * V_2 ,
int V_6 , int V_7 )
{
T_1 V_8 ;
int V_9 ;
if ( V_6 < 900000 || V_6 > 3300000 )
return - V_5 ;
if ( V_6 < 1700000 )
V_8 = F_3 ( V_6 - 900000 , 50000 ) ;
else
V_8 = F_3 ( V_6 - 1700000 , 100000 ) + 15 ;
V_9 = F_1 ( V_2 , V_8 ) ;
if ( V_9 < V_6 || V_9 > V_7 )
return - V_5 ;
return V_8 ;
}
static unsigned int F_4 ( struct V_1 * V_2 )
{
struct V_10 * V_10 = F_5 ( V_2 ) ;
int V_11 = ( F_6 ( V_2 ) - V_12 ) * 2 ;
T_1 V_13 [ 2 ] ;
int V_14 ;
V_14 = F_7 ( V_10 , V_15 + V_11 , 2 ,
V_13 ) ;
if ( V_14 != 0 )
return 0 ;
if ( V_13 [ 0 ] & V_16 )
return V_17 ;
if ( ! ( V_13 [ 0 ] & V_18 ) )
return V_19 ;
if ( V_13 [ 1 ] & V_20 )
return V_21 ;
else
return V_22 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_23 )
{
struct V_10 * V_10 = F_5 ( V_2 ) ;
int V_11 = ( F_6 ( V_2 ) - V_12 ) * 2 ;
int V_14 ;
switch ( V_23 ) {
case V_21 :
V_14 = F_9 ( V_10 , V_24 + V_11 ,
V_20 , V_20 ) ;
if ( V_14 != 0 )
return V_14 ;
return F_9 ( V_10 , V_15 + V_11 ,
V_18 | V_16 ,
V_18 ) ;
case V_22 :
V_14 = F_9 ( V_10 , V_24 + V_11 ,
V_20 , 0 ) ;
if ( V_14 != 0 )
return V_14 ;
return F_9 ( V_10 , V_15 + V_11 ,
V_18 | V_16 ,
V_18 ) ;
case V_19 :
return F_9 ( V_10 , V_15 + V_11 ,
V_18 | V_16 , 0 ) ;
default:
return - V_5 ;
}
}
static unsigned int F_10 ( struct V_1 * V_2 ,
int V_25 , int V_26 ,
int V_27 )
{
return V_22 ;
}
static int F_11 ( struct V_28 * V_29 )
{
struct V_10 * V_10 = F_12 ( V_29 , struct V_10 , V_30 [ V_29 -> V_31 ] ) ;
struct V_32 V_33 = { } ;
struct V_1 * V_34 ;
V_33 . V_2 = & V_29 -> V_2 ;
V_33 . V_35 = V_29 -> V_2 . V_36 ;
V_33 . V_37 = V_10 ;
V_33 . V_38 = V_10 -> V_38 ;
V_34 = F_13 ( & V_30 [ V_29 -> V_31 ] , & V_33 ) ;
if ( F_14 ( V_34 ) )
return F_15 ( V_34 ) ;
F_16 ( V_29 , V_34 ) ;
return 0 ;
}
static int F_17 ( struct V_28 * V_29 )
{
struct V_1 * V_34 = F_18 ( V_29 ) ;
F_16 ( V_29 , NULL ) ;
F_19 ( V_34 ) ;
return 0 ;
}
int F_20 ( struct V_39 * V_2 , int V_40 ,
struct V_41 * V_42 )
{
struct V_10 * V_10 = F_21 ( V_2 ) ;
if ( V_10 -> V_30 [ V_40 ] . V_43 )
return - V_44 ;
V_42 -> V_37 = V_10 ;
V_10 -> V_30 [ V_40 ] . V_43 = L_1 ;
V_10 -> V_30 [ V_40 ] . V_31 = V_40 ;
V_10 -> V_30 [ V_40 ] . V_2 . V_45 = V_2 ;
V_10 -> V_30 [ V_40 ] . V_2 . V_36 = V_42 ;
return F_22 ( & V_10 -> V_30 [ V_40 ] ) ;
}
static int T_2 F_23 ( void )
{
return F_24 ( & V_46 ) ;
}
static void T_3 F_25 ( void )
{
F_26 ( & V_46 ) ;
}
