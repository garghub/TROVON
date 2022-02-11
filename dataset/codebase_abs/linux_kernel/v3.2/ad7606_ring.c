int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
T_1 * V_8 ;
V_8 = F_2 ( V_5 -> V_9 -> V_10 ( V_5 ) ,
V_11 ) ;
if ( V_8 == NULL ) {
V_7 = - V_12 ;
goto V_13;
}
V_7 = V_5 -> V_9 -> V_14 ( V_5 , ( V_15 * ) V_8 ) ;
if ( V_7 )
goto V_16;
V_7 = V_8 [ V_3 ] ;
V_16:
F_3 ( V_8 ) ;
V_13:
return V_7 ;
}
static T_2 F_4 ( int V_17 , void * V_18 )
{
struct V_19 * V_20 = V_18 ;
struct V_21 * V_22 = F_5 ( V_20 -> V_2 ) ;
F_6 ( V_22 -> V_23 -> V_24 , 1 ) ;
return V_25 ;
}
static void F_7 ( struct V_26 * V_27 )
{
struct V_21 * V_22 = F_8 ( V_27 , struct V_21 ,
V_28 ) ;
struct V_1 * V_2 = F_9 ( V_22 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_3 V_29 ;
T_4 * V_30 ;
int V_7 ;
V_30 = F_10 ( V_5 -> V_9 -> V_10 ( V_5 ) ,
V_11 ) ;
if ( V_30 == NULL )
return;
if ( F_11 ( V_22 -> V_23 -> V_31 ) ) {
V_7 = V_22 -> V_32 -> V_33 ( V_22 -> V_34 , 1 , V_30 ) ;
if ( V_7 )
goto V_35;
if ( ! F_12 ( V_22 -> V_23 -> V_31 ) ) {
F_13 ( V_22 ) ;
goto V_35;
}
V_7 = V_22 -> V_32 -> V_33 ( V_22 -> V_34 ,
V_22 -> V_36 -> V_37 - 1 , V_30 + 2 ) ;
if ( V_7 )
goto V_35;
} else {
V_7 = V_22 -> V_32 -> V_33 ( V_22 -> V_34 ,
V_22 -> V_36 -> V_37 , V_30 ) ;
if ( V_7 )
goto V_35;
}
V_29 = F_14 () ;
if ( V_5 -> V_38 )
* ( ( T_3 * ) ( V_30 + V_5 -> V_9 -> V_10 ( V_5 ) -
sizeof( T_3 ) ) ) = V_29 ;
V_5 -> V_9 -> V_39 ( V_2 -> V_6 , V_30 , V_29 ) ;
V_35:
F_6 ( V_22 -> V_23 -> V_24 , 0 ) ;
F_15 ( V_2 -> V_40 ) ;
F_3 ( V_30 ) ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_5 ( V_2 ) ;
int V_7 ;
V_2 -> V_6 = F_17 ( V_2 ) ;
if ( ! V_2 -> V_6 ) {
V_7 = - V_12 ;
goto V_13;
}
V_2 -> V_6 -> V_9 = & V_41 ;
V_2 -> V_6 -> V_42 =
V_22 -> V_36 -> V_43 [ 0 ] . V_44 . V_45 / 8 ;
V_2 -> V_46 = F_18 ( & F_4 ,
& F_4 ,
0 ,
V_2 ,
L_1 ,
V_2 -> V_47 ,
V_2 -> V_48 ) ;
if ( V_2 -> V_46 == NULL ) {
V_7 = - V_12 ;
goto V_49;
}
V_2 -> V_6 -> V_50 = & V_51 ;
V_2 -> V_6 -> V_38 = true ;
F_19 ( & V_22 -> V_28 , & F_7 ) ;
V_2 -> V_52 |= V_53 ;
return 0 ;
V_49:
F_20 ( V_2 -> V_6 ) ;
V_13:
return V_7 ;
}
void F_21 ( struct V_1 * V_2 )
{
F_22 ( V_2 -> V_46 ) ;
F_20 ( V_2 -> V_6 ) ;
}
