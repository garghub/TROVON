static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = F_2 ( V_4 -> V_7 ) ;
F_3 ( V_6 -> V_8 -> V_9 , 1 ) ;
return V_10 ;
}
static void F_4 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = F_5 ( V_12 , struct V_5 ,
V_13 ) ;
struct V_14 * V_7 = F_6 ( V_6 ) ;
struct V_15 * V_16 = V_7 -> V_17 ;
T_2 V_18 ;
T_3 * V_19 ;
int V_20 ;
V_19 = F_7 ( V_16 -> V_21 -> V_22 ( V_16 ) ,
V_23 ) ;
if ( V_19 == NULL )
return;
if ( F_8 ( V_6 -> V_8 -> V_24 ) ) {
V_20 = V_6 -> V_25 -> V_26 ( V_6 -> V_27 , 1 , V_19 ) ;
if ( V_20 )
goto V_28;
if ( ! F_9 ( V_6 -> V_8 -> V_24 ) ) {
F_10 ( V_6 ) ;
goto V_28;
}
V_20 = V_6 -> V_25 -> V_26 ( V_6 -> V_27 ,
V_6 -> V_29 -> V_30 - 1 , V_19 + 2 ) ;
if ( V_20 )
goto V_28;
} else {
V_20 = V_6 -> V_25 -> V_26 ( V_6 -> V_27 ,
V_6 -> V_29 -> V_30 , V_19 ) ;
if ( V_20 )
goto V_28;
}
V_18 = F_11 () ;
if ( V_16 -> V_31 )
* ( ( T_2 * ) ( V_19 + V_16 -> V_21 -> V_22 ( V_16 ) -
sizeof( T_2 ) ) ) = V_18 ;
V_16 -> V_21 -> V_32 ( V_7 -> V_17 , V_19 , V_18 ) ;
V_28:
F_3 ( V_6 -> V_8 -> V_9 , 0 ) ;
F_12 ( V_7 -> V_33 ) ;
F_13 ( V_19 ) ;
}
int F_14 ( struct V_14 * V_7 )
{
struct V_5 * V_6 = F_2 ( V_7 ) ;
int V_20 ;
V_7 -> V_17 = F_15 ( V_7 ) ;
if ( ! V_7 -> V_17 ) {
V_20 = - V_34 ;
goto V_35;
}
V_7 -> V_17 -> V_21 = & V_36 ;
V_7 -> V_37 = F_16 ( & F_1 ,
& F_1 ,
0 ,
V_7 ,
L_1 ,
V_7 -> V_38 ,
V_7 -> V_39 ) ;
if ( V_7 -> V_37 == NULL ) {
V_20 = - V_34 ;
goto V_40;
}
V_7 -> V_41 = & V_42 ;
V_7 -> V_17 -> V_31 = true ;
F_17 ( & V_6 -> V_13 , & F_4 ) ;
V_7 -> V_43 |= V_44 ;
return 0 ;
V_40:
F_18 ( V_7 -> V_17 ) ;
V_35:
return V_20 ;
}
void F_19 ( struct V_14 * V_7 )
{
F_20 ( V_7 -> V_37 ) ;
F_18 ( V_7 -> V_17 ) ;
}
