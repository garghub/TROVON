static int F_1 ( struct V_1 * V_2 )
{
unsigned V_3 = V_2 -> V_4 ;
if ( V_3 >= V_5 )
return - V_6 ;
V_7 &= ~ V_8 [ V_3 ] . V_9 ;
V_7 |= V_8 [ V_3 ] . V_10 ;
V_11 = V_8 [ V_3 ] . V_12 ;
F_2 ( V_8 [ V_3 ] . V_13 , V_14 ) ;
V_2 -> V_15 . V_16 = V_8 [ V_3 ] . V_16 ;
return F_3 ( V_2 ,
V_8 [ V_3 ] . V_17 , V_8 [ V_3 ] . V_18 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned V_3 = V_2 -> V_4 ;
if ( V_3 >= V_5 )
return;
F_5 ( V_2 ,
V_8 [ V_3 ] . V_17 , V_8 [ V_3 ] . V_18 ) ;
}
static int F_6 (
struct V_1 * V_2 , const T_1 * V_19 )
{
unsigned V_20 ;
unsigned V_3 = V_2 -> V_4 ;
if ( V_3 >= V_5 )
return - V_6 ;
switch ( V_3 ) {
case 0 :
V_20 = V_21 ;
break;
case 1 :
V_20 = V_22 ;
break;
default:
return - V_6 ;
}
if ( V_19 -> V_23 & V_24 )
V_25 = V_20 ;
else
V_11 = V_20 ;
return 0 ;
}
static void F_7 (
struct V_1 * V_2 , struct V_26 * V_19 )
{
unsigned long V_27 = V_28 ;
unsigned V_3 = V_2 -> V_4 ;
if ( V_3 >= V_5 )
return;
memset ( V_19 , 0 , sizeof( struct V_26 ) ) ;
switch ( V_3 ) {
case 0 :
V_19 -> V_29 = ( V_27 & V_30 ) ? 1 : 0 ;
V_19 -> V_31 = ! ( V_27 & V_32 ) ? 1 : 0 ;
break;
case 1 :
V_19 -> V_29 = ( V_27 & V_33 ) ? 1 : 0 ;
V_19 -> V_31 = ! ( V_27 & V_34 ) ? 1 : 0 ;
break;
default:
return;
}
V_19 -> V_35 = 1 ;
V_19 -> V_36 = 1 ;
V_19 -> V_37 = 0 ;
V_19 -> V_38 = 1 ;
V_19 -> V_39 = 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned V_3 = V_2 -> V_4 ;
if ( V_3 >= V_5 )
return;
F_9 ( V_2 ,
V_8 [ V_3 ] . V_17 , V_8 [ V_3 ] . V_18 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
unsigned V_3 = V_2 -> V_4 ;
if ( V_3 >= V_5 )
return;
F_11 ( V_2 ,
V_8 [ V_3 ] . V_17 , V_8 [ V_3 ] . V_18 ) ;
}
int F_12 ( struct V_40 * V_41 )
{
int V_42 = - V_43 ;
if ( F_13 () )
V_42 = F_14 (
V_41 , & V_44 , 0 , 2 ) ;
return V_42 ;
}
