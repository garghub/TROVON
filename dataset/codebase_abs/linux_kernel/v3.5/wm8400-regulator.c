static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 )
{
if ( V_3 > V_4 )
return - V_5 ;
if ( V_3 < 15 )
return 900000 + ( V_3 * 50000 ) ;
else
return 1600000 + ( ( V_3 - 14 ) * 100000 ) ;
}
static int F_2 ( struct V_1 * V_2 ,
int V_6 , int V_7 )
{
T_1 V_8 ;
if ( V_6 < 900000 || V_6 > 3300000 )
return - V_5 ;
if ( V_6 < 1700000 ) {
V_8 = F_3 ( V_6 - 900000 , 50000 ) ;
if ( ( V_8 * 50000 ) + 900000 > V_7 )
return - V_5 ;
F_4 ( ( V_8 * 50000 ) + 900000 < V_6 ) ;
} else {
V_8 = F_3 ( V_6 - 1700000 , 100000 ) ;
if ( ( V_8 * 100000 ) + 1700000 > V_7 )
return - V_5 ;
F_4 ( ( V_8 * 100000 ) + 1700000 < V_6 ) ;
V_8 += 0xf ;
}
return V_8 ;
}
static unsigned int F_5 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
int V_10 = ( F_7 ( V_2 ) - V_11 ) * 2 ;
T_1 V_12 [ 2 ] ;
int V_13 ;
V_13 = F_8 ( V_9 , V_14 + V_10 , 2 ,
V_12 ) ;
if ( V_13 != 0 )
return 0 ;
if ( V_12 [ 0 ] & V_15 )
return V_16 ;
if ( ! ( V_12 [ 0 ] & V_17 ) )
return V_18 ;
if ( V_12 [ 1 ] & V_19 )
return V_20 ;
else
return V_21 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_22 )
{
struct V_9 * V_9 = F_6 ( V_2 ) ;
int V_10 = ( F_7 ( V_2 ) - V_11 ) * 2 ;
int V_13 ;
switch ( V_22 ) {
case V_20 :
V_13 = F_10 ( V_9 , V_23 + V_10 ,
V_19 , V_19 ) ;
if ( V_13 != 0 )
return V_13 ;
return F_10 ( V_9 , V_14 + V_10 ,
V_17 | V_15 ,
V_17 ) ;
case V_21 :
V_13 = F_10 ( V_9 , V_23 + V_10 ,
V_19 , 0 ) ;
if ( V_13 != 0 )
return V_13 ;
return F_10 ( V_9 , V_14 + V_10 ,
V_17 | V_15 ,
V_17 ) ;
case V_18 :
V_13 = F_10 ( V_9 , V_14 + V_10 ,
V_17 , 0 ) ;
if ( V_13 != 0 )
return V_13 ;
return F_10 ( V_9 , V_14 + V_10 ,
V_15 , 0 ) ;
default:
return - V_5 ;
}
}
static unsigned int F_11 ( struct V_1 * V_2 ,
int V_24 , int V_25 ,
int V_26 )
{
return V_21 ;
}
static int T_2 F_12 ( struct V_27 * V_28 )
{
struct V_9 * V_9 = F_13 ( V_28 , struct V_9 , V_29 [ V_28 -> V_30 ] ) ;
struct V_31 V_32 = { } ;
struct V_1 * V_33 ;
V_32 . V_2 = & V_28 -> V_2 ;
V_32 . V_34 = V_28 -> V_2 . V_35 ;
V_32 . V_36 = V_9 ;
V_32 . V_37 = V_9 -> V_37 ;
V_33 = F_14 ( & V_29 [ V_28 -> V_30 ] , & V_32 ) ;
if ( F_15 ( V_33 ) )
return F_16 ( V_33 ) ;
F_17 ( V_28 , V_33 ) ;
return 0 ;
}
static int T_3 F_18 ( struct V_27 * V_28 )
{
struct V_1 * V_33 = F_19 ( V_28 ) ;
F_17 ( V_28 , NULL ) ;
F_20 ( V_33 ) ;
return 0 ;
}
int F_21 ( struct V_38 * V_2 , int V_39 ,
struct V_40 * V_41 )
{
struct V_9 * V_9 = F_22 ( V_2 ) ;
if ( V_9 -> V_29 [ V_39 ] . V_42 )
return - V_43 ;
V_41 -> V_36 = V_9 ;
V_9 -> V_29 [ V_39 ] . V_42 = L_1 ;
V_9 -> V_29 [ V_39 ] . V_30 = V_39 ;
V_9 -> V_29 [ V_39 ] . V_2 . V_44 = V_2 ;
V_9 -> V_29 [ V_39 ] . V_2 . V_35 = V_41 ;
return F_23 ( & V_9 -> V_29 [ V_39 ] ) ;
}
static int T_4 F_24 ( void )
{
return F_25 ( & V_45 ) ;
}
static void T_5 F_26 ( void )
{
F_27 ( & V_45 ) ;
}
