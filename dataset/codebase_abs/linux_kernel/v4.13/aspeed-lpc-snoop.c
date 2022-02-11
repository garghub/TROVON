static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( ! F_2 ( V_2 ) )
return;
if ( F_3 ( V_2 ) )
F_4 ( V_2 ) ;
F_5 ( V_2 , V_3 ) ;
}
static T_2 F_6 ( int V_4 , void * V_5 )
{
struct V_6 * V_7 = V_5 ;
T_3 V_8 , V_9 ;
if ( F_7 ( V_7 -> V_10 , V_11 , & V_8 ) )
return V_12 ;
V_8 &= ( V_13 | V_14 ) ;
if ( ! V_8 )
return V_12 ;
F_8 ( V_7 -> V_10 , V_11 , V_8 ) ;
F_7 ( V_7 -> V_10 , V_15 , & V_9 ) ;
if ( V_8 & V_13 ) {
T_1 V_3 = ( V_9 & V_16 ) >> V_17 ;
F_1 ( & V_7 -> V_18 [ 0 ] , V_3 ) ;
}
if ( V_8 & V_14 ) {
T_1 V_3 = ( V_9 & V_19 ) >> V_20 ;
F_1 ( & V_7 -> V_18 [ 1 ] , V_3 ) ;
}
return V_21 ;
}
static int F_9 ( struct V_6 * V_7 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 = & V_23 -> V_25 ;
int V_26 ;
V_7 -> V_4 = F_10 ( V_23 , 0 ) ;
if ( ! V_7 -> V_4 )
return - V_27 ;
V_26 = F_11 ( V_25 , V_7 -> V_4 ,
F_6 , V_28 ,
V_29 , V_7 ) ;
if ( V_26 < 0 ) {
F_12 ( V_25 , L_1 , V_7 -> V_4 ) ;
V_7 -> V_4 = 0 ;
return V_26 ;
}
return 0 ;
}
static int F_13 ( struct V_6 * V_7 ,
int V_30 , T_4 V_31 )
{
int V_26 = 0 ;
T_3 V_32 , V_33 , V_34 , V_35 ;
V_26 = F_14 ( & V_7 -> V_18 [ V_30 ] ,
V_36 , V_37 ) ;
if ( V_26 )
return V_26 ;
switch ( V_30 ) {
case 0 :
V_32 = V_38 | V_39 ;
V_33 = V_40 ;
V_34 = V_41 ;
V_35 = V_42 ;
break;
case 1 :
V_32 = V_43 | V_44 ;
V_33 = V_45 ;
V_34 = V_46 ;
V_35 = V_47 ;
break;
default:
return - V_48 ;
}
F_15 ( V_7 -> V_10 , V_49 , V_32 , V_32 ) ;
F_15 ( V_7 -> V_10 , V_50 , V_33 ,
V_31 << V_34 ) ;
F_15 ( V_7 -> V_10 , V_51 , V_35 , V_35 ) ;
return V_26 ;
}
static void F_16 ( struct V_6 * V_7 ,
int V_30 )
{
switch ( V_30 ) {
case 0 :
F_15 ( V_7 -> V_10 , V_49 ,
V_38 | V_39 ,
0 ) ;
break;
case 1 :
F_15 ( V_7 -> V_10 , V_49 ,
V_43 | V_44 ,
0 ) ;
break;
default:
return;
}
F_17 ( & V_7 -> V_18 [ V_30 ] ) ;
}
static int F_18 ( struct V_22 * V_23 )
{
struct V_6 * V_7 ;
struct V_24 * V_25 ;
T_3 V_52 ;
int V_26 ;
V_25 = & V_23 -> V_25 ;
V_7 = F_19 ( V_25 , sizeof( * V_7 ) , V_37 ) ;
if ( ! V_7 )
return - V_53 ;
V_7 -> V_10 = F_20 (
V_23 -> V_25 . V_54 -> V_55 ) ;
if ( F_21 ( V_7 -> V_10 ) ) {
F_22 ( V_25 , L_2 ) ;
return - V_27 ;
}
F_23 ( & V_23 -> V_25 , V_7 ) ;
V_26 = F_24 ( V_25 -> V_55 , L_3 , 0 , & V_52 ) ;
if ( V_26 ) {
F_22 ( V_25 , L_4 ) ;
return - V_27 ;
}
V_26 = F_9 ( V_7 , V_23 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_13 ( V_7 , 0 , V_52 ) ;
if ( V_26 )
return V_26 ;
if ( F_24 ( V_25 -> V_55 , L_3 ,
1 , & V_52 ) == 0 ) {
V_26 = F_13 ( V_7 , 1 , V_52 ) ;
if ( V_26 )
F_16 ( V_7 , 0 ) ;
}
return V_26 ;
}
static int F_25 ( struct V_22 * V_23 )
{
struct V_6 * V_7 = F_26 ( & V_23 -> V_25 ) ;
F_16 ( V_7 , 0 ) ;
F_16 ( V_7 , 1 ) ;
return 0 ;
}
