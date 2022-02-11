static int F_1 ( unsigned int V_1 )
{
int V_2 = 0 ;
if ( V_1 > 63 )
return - V_3 ;
if ( V_1 <= 24 )
V_2 = V_1 * 25000 + 900000 ;
else if ( V_1 <= 52 )
V_2 = ( V_1 - 24 ) * 50000 + 1500000 ;
else if ( V_1 < 56 )
V_2 = ( V_1 - 52 ) * 100000 + 2900000 ;
else
V_2 = 3300000 ;
return V_2 ;
}
static int F_2 ( int V_2 , unsigned int * V_1 )
{
if ( ( V_2 < 0 ) && ( V_2 > 3300000 ) )
return - V_3 ;
if ( V_2 <= 1500000 )
* V_1 = F_3 ( V_2 - 900000 , 25000 ) ;
else if ( V_2 <= 2900000 )
* V_1 = 24 + F_3 ( V_2 - 1500000 , 50000 ) ;
else if ( V_2 < 3300000 )
* V_1 = 52 + F_3 ( V_2 - 2900000 , 100000 ) ;
else
* V_1 = 56 ;
return 0 ;
}
static int F_4 ( unsigned int V_1 )
{
int V_2 = 0 ;
if ( V_1 > 31 )
return - V_3 ;
if ( V_1 <= 8 )
V_2 = V_1 * 50000 + 1500000 ;
else if ( V_1 <= 13 )
V_2 = ( V_1 - 8 ) * 100000 + 1900000 ;
else
V_2 = ( V_1 - 13 ) * 50000 + 2400000 ;
return V_2 ;
}
static int F_5 ( int V_2 , unsigned int * V_1 )
{
if ( ( V_2 < 0 ) && ( V_2 > 3300000 ) )
return - V_3 ;
if ( V_2 <= 1900000 )
* V_1 = F_3 ( V_2 - 1500000 , 50000 ) ;
else if ( V_2 <= 2400000 )
* V_1 = 8 + F_3 ( V_2 - 1900000 , 100000 ) ;
else
* V_1 = 13 + F_3 ( V_2 - 2400000 , 50000 ) ;
return 0 ;
}
static int F_6 ( struct V_4 * V_5 )
{
int V_6 ;
struct V_7 * V_8 = F_7 ( V_5 ) ;
unsigned int V_9 , V_10 = F_8 ( V_5 ) ;
if ( V_10 < V_11 || V_10 > V_12 )
return - V_3 ;
V_6 = F_9 ( V_8 , V_13 , & V_9 ) ;
if ( V_6 )
return V_6 ;
return ( V_9 & V_8 -> V_14 [ V_10 ] -> V_15 ) ? 1 : 0 ;
}
static int F_10 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_7 ( V_5 ) ;
unsigned int V_10 = F_8 ( V_5 ) ;
if ( V_10 < V_11 || V_10 > V_12 )
return - V_3 ;
return F_11 ( V_8 , V_13 ,
V_8 -> V_14 [ V_10 ] -> V_15 ,
V_8 -> V_14 [ V_10 ] -> V_15 ,
V_16 ) ;
}
static int F_12 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_7 ( V_5 ) ;
unsigned int V_10 = F_8 ( V_5 ) ;
if ( V_10 < V_11 || V_10 > V_12 )
return - V_3 ;
return F_13 ( V_8 , V_13 ,
V_8 -> V_14 [ V_10 ] -> V_15 , V_16 ) ;
}
static int F_14 ( struct V_4 * V_5 )
{
int V_6 ;
struct V_7 * V_8 = F_7 ( V_5 ) ;
unsigned int V_17 , V_10 = F_8 ( V_5 ) ;
if ( V_10 < V_11 || V_10 > V_12 )
return - V_3 ;
V_6 = F_9 ( V_8 , V_8 -> V_14 [ V_10 ] -> V_18 , & V_17 ) ;
if ( V_6 )
return V_6 ;
V_17 &= V_8 -> V_14 [ V_10 ] -> V_19 ;
return V_17 ;
}
static int F_15 ( struct V_4 * V_5 ,
unsigned V_17 )
{
struct V_7 * V_8 = F_7 ( V_5 ) ;
int V_20 = F_8 ( V_5 ) ;
if ( V_20 != V_21 )
return - V_3 ;
if ( V_17 >= V_8 -> V_14 [ V_20 ] -> V_22 )
return - V_3 ;
return F_11 ( V_8 , V_8 -> V_14 [ V_20 ] -> V_18 ,
V_8 -> V_14 [ V_20 ] -> V_19 ,
V_17 , V_23 ) ;
}
static int F_16 ( struct V_4 * V_5 ,
int V_24 , int V_25 , unsigned * V_17 )
{
int V_6 ;
struct V_7 * V_8 = F_7 ( V_5 ) ;
unsigned int V_10 = F_8 ( V_5 ) ;
if ( V_10 == V_21 )
return - V_3 ;
if ( V_10 < V_11 || V_10 > V_12 )
return - V_3 ;
if ( V_24 < V_8 -> V_14 [ V_10 ] -> V_24
|| V_24 > V_8 -> V_14 [ V_10 ] -> V_25 )
return - V_3 ;
if ( V_25 < V_8 -> V_14 [ V_10 ] -> V_24
|| V_25 > V_8 -> V_14 [ V_10 ] -> V_25 )
return - V_3 ;
V_6 = V_8 -> V_14 [ V_10 ] -> F_17 ( V_24 , V_17 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_11 ( V_8 , V_8 -> V_14 [ V_10 ] -> V_18 ,
V_8 -> V_14 [ V_10 ] -> V_19 ,
* V_17 , V_23 ) ;
switch ( V_10 ) {
case V_11 ... V_26 :
V_6 = F_11 ( V_8 , V_27 ,
V_28 , V_28 ,
V_23 ) ;
break;
}
return V_6 ;
}
static int F_18 ( struct V_4 * V_5 ,
unsigned V_17 )
{
struct V_7 * V_8 = F_7 ( V_5 ) ;
unsigned int V_10 = F_8 ( V_5 ) ;
if ( V_10 < V_11 || V_10 > V_12 )
return - V_3 ;
if ( V_17 >= V_8 -> V_14 [ V_10 ] -> V_22 )
return - V_3 ;
if ( V_8 -> V_14 [ V_10 ] -> V_29 )
return V_8 -> V_14 [ V_10 ] -> V_29 [ V_17 ] ;
return V_8 -> V_14 [ V_10 ] -> F_19 ( V_17 ) ;
}
static int T_1 F_20 ( struct V_30 * V_31 )
{
struct V_4 * V_32 ;
struct V_7 * V_8 ;
struct V_33 * V_14 = & V_34 [ V_31 -> V_35 ] ;
V_8 = F_21 ( V_31 -> V_5 . V_36 ) ;
V_8 -> V_14 [ V_31 -> V_35 ] = V_14 ;
V_32 = F_22 ( & V_37 [ V_31 -> V_35 ] , & V_31 -> V_5 ,
V_31 -> V_5 . V_38 , V_8 , NULL ) ;
if ( F_23 ( V_32 ) )
return F_24 ( V_32 ) ;
F_25 ( V_31 , V_32 ) ;
return 0 ;
}
static int T_2 F_26 ( struct V_30 * V_31 )
{
struct V_4 * V_32 = F_27 ( V_31 ) ;
F_25 ( V_31 , NULL ) ;
F_28 ( V_32 ) ;
return 0 ;
}
static int T_3 F_29 ( void )
{
return F_30 ( & V_39 ) ;
}
static void T_4 F_31 ( void )
{
F_32 ( & V_39 ) ;
}
