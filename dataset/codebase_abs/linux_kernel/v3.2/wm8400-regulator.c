static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_4 ;
V_4 = F_3 ( V_3 , V_5 + F_4 ( V_2 ) ) ;
return ( V_4 & V_6 ) != 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return F_6 ( V_3 , V_5 + F_4 ( V_2 ) ,
V_6 , V_6 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return F_6 ( V_3 , V_5 + F_4 ( V_2 ) ,
V_6 , 0 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned V_7 )
{
if ( V_7 > V_8 )
return - V_9 ;
if ( V_7 < 15 )
return 900000 + ( V_7 * 50000 ) ;
else
return 1600000 + ( ( V_7 - 14 ) * 100000 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_4 ;
V_4 = F_3 ( V_3 , V_5 + F_4 ( V_2 ) ) ;
V_4 &= V_8 ;
return V_4 ;
}
static int F_10 ( struct V_1 * V_2 ,
int V_10 , int V_11 , unsigned * V_7 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_4 ;
if ( V_10 < 900000 || V_10 > 3300000 )
return - V_9 ;
if ( V_10 < 1700000 ) {
V_4 = ( V_10 - 850001 ) / 50000 ;
if ( ( V_4 * 50000 ) + 900000 > V_11 )
return - V_9 ;
F_11 ( ( V_4 * 50000 ) + 900000 < V_10 ) ;
} else {
V_4 = ( ( V_10 - 1600001 ) / 100000 ) ;
if ( ( V_4 * 100000 ) + 1700000 > V_11 )
return - V_9 ;
F_11 ( ( V_4 * 100000 ) + 1700000 < V_10 ) ;
V_4 += 0xf ;
}
* V_7 = V_4 ;
return F_6 ( V_3 , V_5 + F_4 ( V_2 ) ,
V_8 , V_4 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_12 = ( F_4 ( V_2 ) - V_13 ) * 2 ;
T_1 V_4 ;
V_4 = F_3 ( V_3 , V_14 + V_12 ) ;
return ( V_4 & V_15 ) != 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_12 = ( F_4 ( V_2 ) - V_13 ) * 2 ;
return F_6 ( V_3 , V_14 + V_12 ,
V_15 , V_15 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_12 = ( F_4 ( V_2 ) - V_13 ) * 2 ;
return F_6 ( V_3 , V_14 + V_12 ,
V_15 , 0 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
unsigned V_7 )
{
if ( V_7 > V_16 )
return - V_9 ;
return 850000 + ( V_7 * 25000 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_4 ;
int V_12 = ( F_4 ( V_2 ) - V_13 ) * 2 ;
V_4 = F_3 ( V_3 , V_14 + V_12 ) ;
V_4 &= V_16 ;
return V_4 ;
}
static int F_17 ( struct V_1 * V_2 ,
int V_10 , int V_11 , unsigned * V_7 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_4 ;
int V_12 = ( F_4 ( V_2 ) - V_13 ) * 2 ;
if ( V_10 < 850000 )
return - V_9 ;
V_4 = ( V_10 - 825001 ) / 25000 ;
if ( 850000 + ( 25000 * V_4 ) > V_11 )
return - V_9 ;
F_11 ( 850000 + ( 25000 * V_4 ) < V_10 ) ;
* V_7 = V_4 ;
return F_6 ( V_3 , V_14 + V_12 ,
V_16 , V_4 ) ;
}
static unsigned int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_12 = ( F_4 ( V_2 ) - V_13 ) * 2 ;
T_1 V_17 [ 2 ] ;
int V_18 ;
V_18 = F_19 ( V_3 , V_14 + V_12 , 2 ,
V_17 ) ;
if ( V_18 != 0 )
return 0 ;
if ( V_17 [ 0 ] & V_19 )
return V_20 ;
if ( ! ( V_17 [ 0 ] & V_21 ) )
return V_22 ;
if ( V_17 [ 1 ] & V_23 )
return V_24 ;
else
return V_25 ;
}
static int F_20 ( struct V_1 * V_2 , unsigned int V_26 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_12 = ( F_4 ( V_2 ) - V_13 ) * 2 ;
int V_18 ;
switch ( V_26 ) {
case V_24 :
V_18 = F_6 ( V_3 , V_27 + V_12 ,
V_23 , V_23 ) ;
if ( V_18 != 0 )
return V_18 ;
return F_6 ( V_3 , V_14 + V_12 ,
V_21 | V_19 ,
V_21 ) ;
case V_25 :
V_18 = F_6 ( V_3 , V_27 + V_12 ,
V_23 , 0 ) ;
if ( V_18 != 0 )
return V_18 ;
return F_6 ( V_3 , V_14 + V_12 ,
V_21 | V_19 ,
V_21 ) ;
case V_22 :
V_18 = F_6 ( V_3 , V_14 + V_12 ,
V_21 , 0 ) ;
if ( V_18 != 0 )
return V_18 ;
return F_6 ( V_3 , V_14 + V_12 ,
V_19 , 0 ) ;
default:
return - V_9 ;
}
}
static unsigned int F_21 ( struct V_1 * V_2 ,
int V_28 , int V_29 ,
int V_30 )
{
return V_25 ;
}
static int T_2 F_22 ( struct V_31 * V_32 )
{
struct V_3 * V_3 = F_23 ( V_32 , struct V_3 , V_33 [ V_32 -> V_34 ] ) ;
struct V_1 * V_35 ;
V_35 = F_24 ( & V_33 [ V_32 -> V_34 ] , & V_32 -> V_2 ,
V_32 -> V_2 . V_36 , V_3 ) ;
if ( F_25 ( V_35 ) )
return F_26 ( V_35 ) ;
F_27 ( V_32 , V_35 ) ;
return 0 ;
}
static int T_3 F_28 ( struct V_31 * V_32 )
{
struct V_1 * V_35 = F_29 ( V_32 ) ;
F_27 ( V_32 , NULL ) ;
F_30 ( V_35 ) ;
return 0 ;
}
int F_31 ( struct V_37 * V_2 , int V_38 ,
struct V_39 * V_40 )
{
struct V_3 * V_3 = F_32 ( V_2 ) ;
if ( V_3 -> V_33 [ V_38 ] . V_41 )
return - V_42 ;
V_40 -> V_43 = V_3 ;
V_3 -> V_33 [ V_38 ] . V_41 = L_1 ;
V_3 -> V_33 [ V_38 ] . V_34 = V_38 ;
V_3 -> V_33 [ V_38 ] . V_2 . V_44 = V_2 ;
V_3 -> V_33 [ V_38 ] . V_2 . V_36 = V_40 ;
return F_33 ( & V_3 -> V_33 [ V_38 ] ) ;
}
static int T_4 F_34 ( void )
{
return F_35 ( & V_45 ) ;
}
static void T_5 F_36 ( void )
{
F_37 ( & V_45 ) ;
}
