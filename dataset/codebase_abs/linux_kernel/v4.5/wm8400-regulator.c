static unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 = ( F_3 ( V_2 ) - V_5 ) * 2 ;
T_1 V_6 [ 2 ] ;
int V_7 ;
V_7 = F_4 ( V_3 , V_8 + V_4 , 2 ,
V_6 ) ;
if ( V_7 != 0 )
return 0 ;
if ( V_6 [ 0 ] & V_9 )
return V_10 ;
if ( ! ( V_6 [ 0 ] & V_11 ) )
return V_12 ;
if ( V_6 [ 1 ] & V_13 )
return V_14 ;
else
return V_15 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_16 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 = ( F_3 ( V_2 ) - V_5 ) * 2 ;
int V_7 ;
switch ( V_16 ) {
case V_14 :
V_7 = F_6 ( V_3 , V_17 + V_4 ,
V_13 , V_13 ) ;
if ( V_7 != 0 )
return V_7 ;
return F_6 ( V_3 , V_8 + V_4 ,
V_11 | V_9 ,
V_11 ) ;
case V_15 :
V_7 = F_6 ( V_3 , V_17 + V_4 ,
V_13 , 0 ) ;
if ( V_7 != 0 )
return V_7 ;
return F_6 ( V_3 , V_8 + V_4 ,
V_11 | V_9 ,
V_11 ) ;
case V_12 :
return F_6 ( V_3 , V_8 + V_4 ,
V_11 | V_9 , 0 ) ;
default:
return - V_18 ;
}
}
static unsigned int F_7 ( struct V_1 * V_2 ,
int V_19 , int V_20 ,
int V_21 )
{
return V_15 ;
}
static int F_8 ( struct V_22 * V_23 )
{
struct V_3 * V_3 = F_9 ( V_23 , struct V_3 , V_24 [ V_23 -> V_25 ] ) ;
struct V_26 V_27 = { } ;
struct V_1 * V_28 ;
V_27 . V_2 = & V_23 -> V_2 ;
V_27 . V_29 = F_10 ( & V_23 -> V_2 ) ;
V_27 . V_30 = V_3 ;
V_27 . V_31 = V_3 -> V_31 ;
V_28 = F_11 ( & V_23 -> V_2 , & V_24 [ V_23 -> V_25 ] ,
& V_27 ) ;
if ( F_12 ( V_28 ) )
return F_13 ( V_28 ) ;
F_14 ( V_23 , V_28 ) ;
return 0 ;
}
int F_15 ( struct V_32 * V_2 , int V_33 ,
struct V_34 * V_35 )
{
struct V_3 * V_3 = F_16 ( V_2 ) ;
if ( V_3 -> V_24 [ V_33 ] . V_36 )
return - V_37 ;
V_35 -> V_30 = V_3 ;
V_3 -> V_24 [ V_33 ] . V_36 = L_1 ;
V_3 -> V_24 [ V_33 ] . V_25 = V_33 ;
V_3 -> V_24 [ V_33 ] . V_2 . V_38 = V_2 ;
V_3 -> V_24 [ V_33 ] . V_2 . V_39 = V_35 ;
return F_17 ( & V_3 -> V_24 [ V_33 ] ) ;
}
static int T_2 F_18 ( void )
{
return F_19 ( & V_40 ) ;
}
static void T_3 F_20 ( void )
{
F_21 ( & V_40 ) ;
}
