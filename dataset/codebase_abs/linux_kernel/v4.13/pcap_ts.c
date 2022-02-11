static void F_1 ( void * V_1 , T_1 V_2 [ 2 ] )
{
struct V_3 * V_3 = V_1 ;
switch ( V_3 -> V_4 ) {
case V_5 :
if ( V_2 [ 0 ] > V_6 && V_2 [ 0 ] < V_7 )
V_3 -> V_8 = V_2 [ 0 ] ;
V_3 -> V_4 = V_9 ;
F_2 ( & V_3 -> V_10 , 0 ) ;
break;
case V_9 :
V_3 -> V_11 = V_2 [ 0 ] ;
V_3 -> V_12 = V_2 [ 1 ] ;
if ( V_3 -> V_12 <= V_13 || V_3 -> V_12 >= V_14 ||
V_3 -> V_11 <= V_15 || V_3 -> V_11 >= V_16 ) {
F_3 ( V_3 -> V_17 , V_18 , 0 ) ;
F_4 ( V_3 -> V_17 , V_19 , 0 ) ;
V_3 -> V_4 = V_20 ;
F_2 ( & V_3 -> V_10 , 0 ) ;
} else {
F_3 ( V_3 -> V_17 , V_21 , V_3 -> V_12 ) ;
F_3 ( V_3 -> V_17 , V_22 , V_3 -> V_11 ) ;
F_4 ( V_3 -> V_17 , V_19 , 1 ) ;
F_3 ( V_3 -> V_17 , V_18 ,
V_3 -> V_8 ) ;
V_3 -> V_4 = V_5 ;
F_2 ( & V_3 -> V_10 ,
F_5 ( V_23 ) ) ;
}
F_6 ( V_3 -> V_17 ) ;
break;
default:
F_7 ( & V_3 -> V_17 -> V_24 ,
L_1 ,
V_3 -> V_4 ) ;
break;
}
}
static void F_8 ( struct V_25 * V_10 )
{
struct V_26 * V_27 = F_9 ( V_10 ) ;
struct V_3 * V_3 = F_10 ( V_27 , struct V_3 , V_10 ) ;
T_2 V_28 [ 2 ] ;
F_11 ( V_3 -> V_29 ,
V_3 -> V_4 << V_30 ) ;
if ( V_3 -> V_4 == V_20 )
return;
V_28 [ 0 ] = V_31 ;
V_28 [ 1 ] = V_32 ;
F_12 ( V_3 -> V_29 , V_33 , 0 , V_28 ,
F_1 , V_3 ) ;
}
static T_3 F_13 ( int V_34 , void * V_1 )
{
struct V_3 * V_3 = V_1 ;
if ( V_3 -> V_4 == V_20 ) {
V_3 -> V_4 = V_5 ;
F_2 ( & V_3 -> V_10 , 0 ) ;
}
return V_35 ;
}
static int F_14 ( struct V_36 * V_24 )
{
struct V_3 * V_3 = F_15 ( V_24 ) ;
V_3 -> V_4 = V_20 ;
F_2 ( & V_3 -> V_10 , 0 ) ;
return 0 ;
}
static void F_16 ( struct V_36 * V_24 )
{
struct V_3 * V_3 = F_15 ( V_24 ) ;
F_17 ( & V_3 -> V_10 ) ;
V_3 -> V_4 = V_37 ;
F_11 ( V_3 -> V_29 ,
V_3 -> V_4 << V_30 ) ;
}
static int F_18 ( struct V_38 * V_39 )
{
struct V_36 * V_36 ;
struct V_3 * V_3 ;
int V_40 = - V_41 ;
V_3 = F_19 ( sizeof( * V_3 ) , V_42 ) ;
if ( ! V_3 )
return V_40 ;
V_3 -> V_29 = F_20 ( V_39 -> V_24 . V_43 ) ;
F_21 ( V_39 , V_3 ) ;
V_36 = F_22 () ;
if ( ! V_36 )
goto V_44;
F_23 ( & V_3 -> V_10 , F_8 ) ;
V_3 -> V_4 = V_37 ;
F_11 ( V_3 -> V_29 ,
V_3 -> V_4 << V_30 ) ;
V_3 -> V_17 = V_36 ;
F_24 ( V_36 , V_3 ) ;
V_36 -> V_45 = L_2 ;
V_36 -> V_46 = L_3 ;
V_36 -> V_47 . V_48 = V_49 ;
V_36 -> V_47 . V_50 = 0x0001 ;
V_36 -> V_47 . V_51 = 0x0002 ;
V_36 -> V_47 . V_52 = 0x0100 ;
V_36 -> V_24 . V_43 = & V_39 -> V_24 ;
V_36 -> V_53 = F_14 ;
V_36 -> V_54 = F_16 ;
V_36 -> V_55 [ 0 ] = F_25 ( V_56 ) | F_25 ( V_57 ) ;
V_36 -> V_58 [ F_26 ( V_19 ) ] = F_25 ( V_19 ) ;
F_27 ( V_36 , V_21 , V_13 , V_14 , 0 , 0 ) ;
F_27 ( V_36 , V_22 , V_15 , V_16 , 0 , 0 ) ;
F_27 ( V_36 , V_18 , V_6 ,
V_7 , 0 , 0 ) ;
V_40 = F_28 ( V_3 -> V_17 ) ;
if ( V_40 )
goto V_59;
V_40 = F_29 ( F_30 ( V_3 -> V_29 , V_60 ) ,
F_13 , 0 , L_4 , V_3 ) ;
if ( V_40 )
goto V_61;
return 0 ;
V_61:
F_31 ( V_36 ) ;
goto V_44;
V_59:
F_32 ( V_36 ) ;
V_44:
F_33 ( V_3 ) ;
return V_40 ;
}
static int F_34 ( struct V_38 * V_39 )
{
struct V_3 * V_3 = F_35 ( V_39 ) ;
F_36 ( F_30 ( V_3 -> V_29 , V_60 ) , V_3 ) ;
F_17 ( & V_3 -> V_10 ) ;
F_31 ( V_3 -> V_17 ) ;
F_33 ( V_3 ) ;
return 0 ;
}
static int F_37 ( struct V_62 * V_24 )
{
struct V_3 * V_3 = F_20 ( V_24 ) ;
F_11 ( V_3 -> V_29 , V_63 ) ;
return 0 ;
}
static int F_38 ( struct V_62 * V_24 )
{
struct V_3 * V_3 = F_20 ( V_24 ) ;
F_11 ( V_3 -> V_29 ,
V_3 -> V_4 << V_30 ) ;
return 0 ;
}
