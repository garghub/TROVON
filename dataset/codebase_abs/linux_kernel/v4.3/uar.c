int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 V_5 ;
struct V_6 V_7 ;
int V_8 ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_5 . V_9 . V_10 = F_2 ( V_11 ) ;
V_8 = F_3 ( V_2 , & V_5 , sizeof( V_5 ) , & V_7 , sizeof( V_7 ) ) ;
if ( V_8 )
goto V_12;
if ( V_7 . V_9 . V_13 ) {
V_8 = F_4 ( & V_7 . V_9 ) ;
goto V_12;
}
* V_3 = F_5 ( V_7 . V_3 ) & 0xffffff ;
V_12:
return V_8 ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_14 V_5 ;
struct V_15 V_7 ;
int V_8 ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_5 . V_9 . V_10 = F_2 ( V_16 ) ;
V_5 . V_3 = F_7 ( V_3 ) ;
V_8 = F_3 ( V_2 , & V_5 , sizeof( V_5 ) , & V_7 , sizeof( V_7 ) ) ;
if ( V_8 )
goto V_12;
if ( V_7 . V_9 . V_13 )
V_8 = F_4 ( & V_7 . V_9 ) ;
V_12:
return V_8 ;
}
static int F_8 ( int V_17 )
{
int V_18 = V_19 * V_20 ;
if ( V_17 == 0 || V_18 - V_21 )
return 0 ;
return 1 ;
}
int F_9 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
int V_18 = V_19 * V_20 ;
struct V_24 * V_25 ;
T_2 V_26 ;
int V_8 ;
int V_27 ;
V_23 -> V_28 = V_19 ;
V_23 -> V_29 = V_21 ;
F_10 ( & V_23 -> V_30 ) ;
V_23 -> V_31 = F_11 ( V_23 -> V_28 , sizeof( * V_23 -> V_31 ) , V_32 ) ;
if ( ! V_23 -> V_31 )
return - V_33 ;
V_23 -> V_34 = F_11 ( V_18 , sizeof( * V_23 -> V_34 ) , V_32 ) ;
if ( ! V_23 -> V_34 ) {
V_8 = - V_33 ;
goto V_35;
}
V_23 -> V_36 = F_11 ( F_12 ( V_18 ) , sizeof( * V_23 -> V_36 ) ,
V_32 ) ;
if ( ! V_23 -> V_36 ) {
V_8 = - V_33 ;
goto V_37;
}
V_23 -> V_38 = F_11 ( V_18 , sizeof( * V_23 -> V_38 ) , V_32 ) ;
if ( ! V_23 -> V_38 ) {
V_8 = - V_33 ;
goto V_39;
}
for ( V_27 = 0 ; V_27 < V_23 -> V_28 ; V_27 ++ ) {
V_8 = F_1 ( V_2 , & V_23 -> V_31 [ V_27 ] . V_40 ) ;
if ( V_8 )
goto V_41;
V_26 = V_2 -> V_42 + ( ( T_2 ) ( V_23 -> V_31 [ V_27 ] . V_40 ) << V_43 ) ;
V_23 -> V_31 [ V_27 ] . V_44 = F_13 ( V_26 , V_45 ) ;
if ( ! V_23 -> V_31 [ V_27 ] . V_44 ) {
F_6 ( V_2 , V_23 -> V_31 [ V_27 ] . V_40 ) ;
V_8 = - V_33 ;
goto V_41;
}
F_14 ( V_2 , L_1 ,
V_23 -> V_31 [ V_27 ] . V_40 , V_23 -> V_31 [ V_27 ] . V_44 ) ;
}
for ( V_27 = 0 ; V_27 < V_18 ; V_27 ++ ) {
V_25 = & V_23 -> V_34 [ V_27 ] ;
V_25 -> V_46 = ( 1 << F_15 ( V_2 , V_47 ) ) / 2 ;
V_25 -> V_48 = & V_23 -> V_31 [ V_27 / V_20 ] ;
V_25 -> V_49 = V_23 -> V_31 [ V_27 / V_20 ] . V_44 ;
V_25 -> V_50 = NULL ;
V_25 -> V_51 = ( V_27 % V_20 ) *
( 1 << F_15 ( V_2 , V_47 ) ) +
V_52 ;
V_25 -> V_53 = F_8 ( V_27 ) ;
F_16 ( & V_25 -> V_30 ) ;
F_16 ( & V_25 -> V_54 ) ;
V_25 -> V_17 = V_27 ;
}
return 0 ;
V_41:
for ( V_27 -- ; V_27 >= 0 ; V_27 -- ) {
F_17 ( V_23 -> V_31 [ V_27 ] . V_44 ) ;
F_6 ( V_2 , V_23 -> V_31 [ V_27 ] . V_40 ) ;
}
F_18 ( V_23 -> V_38 ) ;
V_39:
F_18 ( V_23 -> V_36 ) ;
V_37:
F_18 ( V_23 -> V_34 ) ;
V_35:
F_18 ( V_23 -> V_31 ) ;
return V_8 ;
}
int F_19 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
int V_27 = V_23 -> V_28 ;
for ( V_27 -- ; V_27 >= 0 ; V_27 -- ) {
F_17 ( V_23 -> V_31 [ V_27 ] . V_44 ) ;
F_6 ( V_2 , V_23 -> V_31 [ V_27 ] . V_40 ) ;
}
F_18 ( V_23 -> V_38 ) ;
F_18 ( V_23 -> V_36 ) ;
F_18 ( V_23 -> V_34 ) ;
F_18 ( V_23 -> V_31 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_55 , struct V_56 * V_48 )
{
T_2 V_57 ;
T_2 V_58 ;
int V_8 ;
V_8 = F_1 ( V_55 , & V_48 -> V_40 ) ;
if ( V_8 ) {
F_21 ( V_55 , L_2 , V_8 ) ;
return V_8 ;
}
V_58 = F_22 ( V_55 -> V_59 , 0 ) ;
V_57 = ( V_58 >> V_43 ) + V_48 -> V_40 ;
V_48 -> V_44 = F_13 ( V_57 << V_43 , V_45 ) ;
if ( ! V_48 -> V_44 ) {
F_21 ( V_55 , L_3 , V_8 ) ;
V_8 = - V_33 ;
goto V_60;
}
if ( V_55 -> V_61 . V_62 )
V_48 -> V_63 = F_23 ( V_55 -> V_61 . V_62 ,
V_48 -> V_40 << V_43 ) ;
return 0 ;
V_60:
F_6 ( V_55 , V_48 -> V_40 ) ;
return V_8 ;
}
void F_24 ( struct V_1 * V_55 , struct V_56 * V_48 )
{
F_25 ( V_48 -> V_63 ) ;
F_17 ( V_48 -> V_44 ) ;
F_6 ( V_55 , V_48 -> V_40 ) ;
}
