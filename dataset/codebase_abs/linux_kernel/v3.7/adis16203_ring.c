static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 V_9 [ V_10 + 1 ] ;
int V_11 ;
int V_12 ;
F_3 ( & V_7 -> V_13 ) ;
F_4 ( & V_5 ) ;
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
for ( V_12 = 0 ; V_12 <= V_10 ; V_12 ++ ) {
V_9 [ V_12 ] . V_14 = 8 ;
V_9 [ V_12 ] . V_15 = 1 ;
V_9 [ V_12 ] . V_16 = 2 ;
V_9 [ V_12 ] . V_17 = 20 ;
V_9 [ V_12 ] . V_18 = V_7 -> V_19 + 2 * V_12 ;
if ( V_12 < 1 )
V_7 -> V_19 [ 2 * V_12 ] = F_5 ( V_20 + 2 * V_12 ) ;
else
V_7 -> V_19 [ 2 * V_12 ] = F_5 ( V_20 + 2 * V_12 + 6 ) ;
V_7 -> V_19 [ 2 * V_12 + 1 ] = 0 ;
if ( V_12 >= 1 )
V_9 [ V_12 ] . V_21 = V_3 + 2 * ( V_12 - 1 ) ;
F_6 ( & V_9 [ V_12 ] , & V_5 ) ;
}
V_11 = F_7 ( V_7 -> V_22 , & V_5 ) ;
if ( V_11 )
F_8 ( & V_7 -> V_22 -> V_23 , L_1 ) ;
F_9 ( & V_7 -> V_13 ) ;
return V_11 ;
}
static T_2 F_10 ( int V_24 , void * V_25 )
{
struct V_26 * V_27 = V_25 ;
struct V_1 * V_2 = V_27 -> V_2 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_12 = 0 ;
T_3 * V_28 ;
V_28 = F_11 ( V_2 -> V_29 , V_30 ) ;
if ( V_28 == NULL ) {
F_8 ( & V_7 -> V_22 -> V_23 , L_2 ) ;
goto V_31;
}
if ( ! F_12 ( V_2 -> V_32 , V_2 -> V_33 ) &&
F_1 ( V_2 , V_7 -> V_3 ) >= 0 )
for (; V_12 < F_13 ( V_2 -> V_32 ,
V_2 -> V_33 ) ; V_12 ++ )
V_28 [ V_12 ] = F_14 ( ( V_34 * ) & ( V_7 -> V_3 [ V_12 * 2 ] ) ) ;
if ( V_2 -> V_35 )
* ( ( V_36 * ) ( V_28 + ( ( V_12 + 3 ) / 4 ) * 4 ) ) = V_27 -> V_37 ;
F_15 ( V_2 -> V_38 , ( T_1 * ) V_28 ) ;
F_16 ( V_28 ) ;
V_31:
F_17 ( V_2 -> V_39 ) ;
return V_40 ;
}
void F_18 ( struct V_1 * V_2 )
{
F_19 ( V_2 -> V_41 ) ;
F_20 ( V_2 -> V_38 ) ;
}
int F_21 ( struct V_1 * V_2 )
{
int V_11 = 0 ;
struct V_42 * V_43 ;
V_43 = F_22 ( V_2 ) ;
if ( ! V_43 ) {
V_11 = - V_44 ;
return V_11 ;
}
V_2 -> V_38 = V_43 ;
V_43 -> V_35 = true ;
V_2 -> V_45 = & V_46 ;
V_2 -> V_41 = F_23 ( & V_47 ,
& F_10 ,
V_48 ,
V_2 ,
L_3 ,
V_2 -> V_49 ) ;
if ( V_2 -> V_41 == NULL ) {
V_11 = - V_44 ;
goto V_50;
}
V_2 -> V_51 |= V_52 ;
return 0 ;
V_50:
F_20 ( V_2 -> V_38 ) ;
return V_11 ;
}
