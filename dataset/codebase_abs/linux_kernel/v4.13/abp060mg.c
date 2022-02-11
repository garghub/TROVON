static int F_1 ( struct V_1 * V_2 , int * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_6 [ 2 ] ;
T_2 V_7 ;
int V_8 ;
V_6 [ 0 ] = 0 ;
V_8 = F_2 ( V_5 , ( V_9 * ) & V_6 , V_2 -> V_10 ) ;
if ( V_8 < 0 )
return V_8 ;
F_3 ( V_11 ) ;
V_8 = F_4 ( V_5 , ( V_9 * ) & V_6 , sizeof( V_6 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_7 = F_5 ( V_6 [ 0 ] ) ;
if ( V_7 & V_12 )
return - V_13 ;
if ( V_7 < V_14 || V_7 > V_15 )
return - V_13 ;
* V_3 = V_7 ;
return V_16 ;
}
static int F_6 ( struct V_17 * V_18 ,
struct V_19 const * V_20 , int * V_3 ,
int * V_21 , long V_22 )
{
struct V_1 * V_2 = F_7 ( V_18 ) ;
int V_8 ;
F_8 ( & V_2 -> V_23 ) ;
switch ( V_22 ) {
case V_24 :
V_8 = F_1 ( V_2 , V_3 ) ;
break;
case V_25 :
* V_3 = V_2 -> V_26 ;
V_8 = V_16 ;
break;
case V_27 :
* V_3 = V_2 -> V_28 ;
* V_21 = V_29 * 1000 ;
V_8 = V_30 ;
break;
default:
V_8 = - V_31 ;
break;
}
F_9 ( & V_2 -> V_23 ) ;
return V_8 ;
}
static void F_10 ( struct V_17 * V_18 , unsigned long V_32 )
{
struct V_1 * V_2 = F_7 ( V_18 ) ;
struct V_33 * V_34 = & V_33 [ V_32 ] ;
V_2 -> V_28 = V_34 -> V_35 - V_34 -> V_36 ;
V_2 -> V_26 = - V_14 ;
if ( V_34 -> V_36 < 0 )
V_2 -> V_26 -= V_29 >> 1 ;
}
static int F_11 ( struct V_4 * V_5 ,
const struct V_37 * V_32 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 ;
unsigned long V_38 = V_32 -> V_39 ;
V_18 = F_12 ( & V_5 -> V_40 , sizeof( * V_2 ) ) ;
if ( ! V_18 )
return - V_41 ;
V_2 = F_7 ( V_18 ) ;
F_13 ( V_5 , V_2 ) ;
V_2 -> V_5 = V_5 ;
if ( ! F_14 ( V_5 -> V_42 , V_43 ) )
V_2 -> V_10 = 1 ;
F_10 ( V_18 , V_38 ) ;
V_18 -> V_40 . V_44 = & V_5 -> V_40 ;
V_18 -> V_45 = F_15 ( & V_5 -> V_40 ) ;
V_18 -> V_46 = V_47 ;
V_18 -> V_48 = & V_49 ;
V_18 -> V_50 = V_51 ;
V_18 -> V_52 = F_16 ( V_51 ) ;
F_17 ( & V_2 -> V_23 ) ;
return F_18 ( & V_5 -> V_40 , V_18 ) ;
}
