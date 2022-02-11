static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_6 ; V_5 ++ )
if ( V_4 -> V_7 [ V_5 ] . V_8 == V_4 -> V_9 )
return V_4 -> V_7 [ V_5 ] . V_10 ;
return - V_11 ;
}
static int F_3 ( struct V_1 * V_2 ,
int V_12 , int V_13 ,
unsigned * V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_15 = 0 , V_9 , V_16 = V_17 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_6 ; V_5 ++ )
if ( V_4 -> V_7 [ V_5 ] . V_10 < V_16 &&
V_4 -> V_7 [ V_5 ] . V_10 >= V_12 &&
V_4 -> V_7 [ V_5 ] . V_10 <= V_13 ) {
V_15 = V_4 -> V_7 [ V_5 ] . V_8 ;
V_16 = V_4 -> V_7 [ V_5 ] . V_10 ;
if ( V_14 )
* V_14 = V_5 ;
}
if ( V_16 == V_17 )
return - V_11 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_18 ; V_5 ++ ) {
V_9 = ( V_15 & ( 1 << V_5 ) ) >> V_5 ;
F_4 ( V_4 -> V_8 [ V_5 ] . V_19 , V_9 ) ;
}
V_4 -> V_9 = V_15 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_14 >= V_4 -> V_6 )
return - V_11 ;
return V_4 -> V_7 [ V_14 ] . V_10 ;
}
static int F_6 ( struct V_1 * V_2 ,
int V_20 , int V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_15 = 0 , V_9 , V_16 = 0 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_6 ; V_5 ++ )
if ( V_4 -> V_7 [ V_5 ] . V_10 > V_16 &&
V_4 -> V_7 [ V_5 ] . V_10 >= V_20 &&
V_4 -> V_7 [ V_5 ] . V_10 <= V_21 ) {
V_15 = V_4 -> V_7 [ V_5 ] . V_8 ;
V_16 = V_4 -> V_7 [ V_5 ] . V_10 ;
}
if ( V_16 == 0 )
return - V_11 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_18 ; V_5 ++ ) {
V_9 = ( V_15 & ( 1 << V_5 ) ) >> V_5 ;
F_4 ( V_4 -> V_8 [ V_5 ] . V_19 , V_9 ) ;
}
V_4 -> V_9 = V_15 ;
return 0 ;
}
static int T_1 F_7 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_2 . V_26 ;
struct V_3 * V_27 ;
struct V_28 V_29 = { } ;
int V_5 , V_30 , V_9 ;
V_27 = F_8 ( & V_23 -> V_2 , sizeof( struct V_3 ) ,
V_31 ) ;
if ( V_27 == NULL ) {
F_9 ( & V_23 -> V_2 , L_1 ) ;
return - V_32 ;
}
V_27 -> V_33 . V_34 = F_10 ( V_25 -> V_35 , V_31 ) ;
if ( V_27 -> V_33 . V_34 == NULL ) {
F_9 ( & V_23 -> V_2 , L_2 ) ;
V_30 = - V_32 ;
goto V_36;
}
V_27 -> V_8 = F_11 ( V_25 -> V_8 ,
V_25 -> V_18 * sizeof( struct V_19 ) ,
V_31 ) ;
if ( V_27 -> V_8 == NULL ) {
F_9 ( & V_23 -> V_2 , L_3 ) ;
V_30 = - V_32 ;
goto V_37;
}
V_27 -> V_7 = F_11 ( V_25 -> V_7 ,
V_25 -> V_6 *
sizeof( struct V_38 ) ,
V_31 ) ;
if ( V_27 -> V_7 == NULL ) {
F_9 ( & V_23 -> V_2 , L_4 ) ;
V_30 = - V_32 ;
goto V_39;
}
V_27 -> V_6 = V_25 -> V_6 ;
V_27 -> V_33 . V_40 = V_41 ;
V_27 -> V_33 . V_42 = V_25 -> V_43 ;
switch ( V_25 -> type ) {
case V_44 :
V_27 -> V_33 . type = V_44 ;
V_27 -> V_33 . V_45 = & V_46 ;
V_27 -> V_33 . V_47 = V_25 -> V_6 ;
break;
case V_48 :
V_27 -> V_33 . type = V_48 ;
V_27 -> V_33 . V_45 = & V_49 ;
break;
default:
F_9 ( & V_23 -> V_2 , L_5 ) ;
V_30 = - V_11 ;
goto V_39;
break;
}
V_27 -> V_18 = V_25 -> V_18 ;
V_30 = F_12 ( V_27 -> V_8 , V_27 -> V_18 ) ;
if ( V_30 ) {
F_9 ( & V_23 -> V_2 ,
L_6 , V_30 ) ;
goto V_50;
}
V_9 = 0 ;
for ( V_5 = 0 ; V_5 < V_27 -> V_18 ; V_5 ++ ) {
if ( V_25 -> V_8 [ V_5 ] . V_51 & V_52 )
V_9 |= ( 1 << V_5 ) ;
}
V_27 -> V_9 = V_9 ;
V_29 . V_2 = & V_23 -> V_2 ;
V_29 . V_53 = V_25 -> V_53 ;
V_29 . V_54 = V_27 ;
if ( V_25 -> V_55 >= 0 )
V_29 . V_56 = V_25 -> V_55 ;
V_29 . V_57 = ! V_25 -> V_58 ;
if ( V_25 -> V_59 ) {
if ( V_25 -> V_58 )
V_29 . V_60 |= V_52 ;
else
V_29 . V_60 |= V_61 ;
} else {
if ( V_25 -> V_58 )
V_29 . V_60 |= V_61 ;
else
V_29 . V_60 |= V_52 ;
}
V_27 -> V_2 = F_13 ( & V_27 -> V_33 , & V_29 ) ;
if ( F_14 ( V_27 -> V_2 ) ) {
V_30 = F_15 ( V_27 -> V_2 ) ;
F_9 ( & V_23 -> V_2 , L_7 , V_30 ) ;
goto V_62;
}
F_16 ( V_23 , V_27 ) ;
return 0 ;
V_62:
F_17 ( V_27 -> V_8 , V_27 -> V_18 ) ;
V_50:
F_18 ( V_27 -> V_7 ) ;
V_39:
F_18 ( V_27 -> V_8 ) ;
V_37:
F_18 ( V_27 -> V_33 . V_34 ) ;
V_36:
return V_30 ;
}
static int T_2 F_19 ( struct V_22 * V_23 )
{
struct V_3 * V_27 = F_20 ( V_23 ) ;
F_21 ( V_27 -> V_2 ) ;
F_17 ( V_27 -> V_8 , V_27 -> V_18 ) ;
F_18 ( V_27 -> V_7 ) ;
F_18 ( V_27 -> V_8 ) ;
F_18 ( V_27 -> V_33 . V_34 ) ;
return 0 ;
}
static int T_3 F_22 ( void )
{
return F_23 ( & V_63 ) ;
}
static void T_4 F_24 ( void )
{
F_25 ( & V_63 ) ;
}
