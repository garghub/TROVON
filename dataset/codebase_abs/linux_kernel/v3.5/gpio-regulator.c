static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_4 ( V_4 -> V_6 ) ) {
F_5 ( V_4 -> V_6 , V_4 -> V_7 ) ;
V_4 -> V_5 = true ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_4 ( V_4 -> V_6 ) ) {
F_5 ( V_4 -> V_6 , ! V_4 -> V_7 ) ;
V_4 -> V_5 = false ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_8 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_4 -> V_10 ; V_9 ++ )
if ( V_4 -> V_11 [ V_9 ] . V_12 == V_4 -> V_13 )
return V_4 -> V_11 [ V_9 ] . V_14 ;
return - V_15 ;
}
static int F_9 ( struct V_1 * V_2 ,
int V_16 , int V_17 , unsigned * V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_9 , V_19 = 0 , V_13 , V_20 = V_21 ;
for ( V_9 = 0 ; V_9 < V_4 -> V_10 ; V_9 ++ )
if ( V_4 -> V_11 [ V_9 ] . V_14 < V_20 &&
V_4 -> V_11 [ V_9 ] . V_14 >= V_16 &&
V_4 -> V_11 [ V_9 ] . V_14 <= V_17 ) {
V_19 = V_4 -> V_11 [ V_9 ] . V_12 ;
V_20 = V_4 -> V_11 [ V_9 ] . V_14 ;
if ( V_18 )
* V_18 = V_9 ;
}
if ( V_20 == V_21 )
return - V_15 ;
for ( V_9 = 0 ; V_9 < V_4 -> V_22 ; V_9 ++ ) {
V_13 = ( V_19 & ( 1 << V_9 ) ) >> V_9 ;
F_10 ( V_4 -> V_12 [ V_9 ] . V_23 , V_13 ) ;
}
V_4 -> V_13 = V_19 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
int V_24 , int V_25 ,
unsigned * V_18 )
{
return F_9 ( V_2 , V_24 , V_25 , V_18 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_18 >= V_4 -> V_10 )
return - V_15 ;
return V_4 -> V_11 [ V_18 ] . V_14 ;
}
static int F_13 ( struct V_1 * V_2 ,
int V_26 , int V_27 )
{
return F_9 ( V_2 , V_26 , V_27 , NULL ) ;
}
static int T_1 F_14 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = V_29 -> V_2 . V_32 ;
struct V_3 * V_33 ;
struct V_34 V_35 = { } ;
int V_9 , V_36 , V_13 ;
V_33 = F_15 ( & V_29 -> V_2 , sizeof( struct V_3 ) ,
V_37 ) ;
if ( V_33 == NULL ) {
F_16 ( & V_29 -> V_2 , L_1 ) ;
return - V_38 ;
}
V_33 -> V_39 . V_40 = F_17 ( V_31 -> V_41 , V_37 ) ;
if ( V_33 -> V_39 . V_40 == NULL ) {
F_16 ( & V_29 -> V_2 , L_2 ) ;
V_36 = - V_38 ;
goto V_42;
}
V_33 -> V_12 = F_18 ( V_31 -> V_12 ,
V_31 -> V_22 * sizeof( struct V_23 ) ,
V_37 ) ;
if ( V_33 -> V_12 == NULL ) {
F_16 ( & V_29 -> V_2 , L_3 ) ;
V_36 = - V_38 ;
goto V_43;
}
V_33 -> V_11 = F_18 ( V_31 -> V_11 ,
V_31 -> V_10 *
sizeof( struct V_44 ) ,
V_37 ) ;
if ( V_33 -> V_11 == NULL ) {
F_16 ( & V_29 -> V_2 , L_4 ) ;
V_36 = - V_38 ;
goto V_45;
}
V_33 -> V_10 = V_31 -> V_10 ;
V_33 -> V_39 . V_46 = V_47 ;
switch ( V_31 -> type ) {
case V_48 :
V_33 -> V_39 . type = V_48 ;
V_33 -> V_39 . V_49 = & V_50 ;
V_33 -> V_39 . V_51 = V_31 -> V_10 ;
break;
case V_52 :
V_33 -> V_39 . type = V_52 ;
V_33 -> V_39 . V_49 = & V_53 ;
break;
default:
F_16 ( & V_29 -> V_2 , L_5 ) ;
V_36 = - V_15 ;
goto V_45;
break;
}
V_33 -> V_6 = V_31 -> V_6 ;
V_33 -> V_8 = V_31 -> V_8 ;
if ( F_4 ( V_31 -> V_6 ) ) {
V_33 -> V_7 = V_31 -> V_7 ;
V_36 = F_19 ( V_31 -> V_6 , V_31 -> V_41 ) ;
if ( V_36 ) {
F_16 ( & V_29 -> V_2 ,
L_6 ,
V_31 -> V_6 , V_36 ) ;
goto V_54;
}
if ( V_31 -> V_55 ) {
V_33 -> V_5 = true ;
V_36 = F_20 ( V_31 -> V_6 ,
V_31 -> V_7 ) ;
} else {
V_33 -> V_5 = false ;
V_36 = F_20 ( V_31 -> V_6 ,
! V_31 -> V_7 ) ;
}
if ( V_36 ) {
F_16 ( & V_29 -> V_2 ,
L_7 ,
V_31 -> V_6 , V_36 ) ;
goto V_56;
}
} else {
V_33 -> V_5 = true ;
}
V_33 -> V_22 = V_31 -> V_22 ;
V_36 = F_21 ( V_33 -> V_12 , V_33 -> V_22 ) ;
if ( V_36 ) {
F_16 ( & V_29 -> V_2 ,
L_8 , V_36 ) ;
goto V_56;
}
V_13 = 0 ;
for ( V_9 = 0 ; V_9 < V_33 -> V_22 ; V_9 ++ ) {
if ( V_31 -> V_12 [ V_9 ] . V_57 & V_58 )
V_13 |= ( 1 << V_9 ) ;
}
V_33 -> V_13 = V_13 ;
V_35 . V_2 = & V_29 -> V_2 ;
V_35 . V_59 = V_31 -> V_59 ;
V_35 . V_60 = V_33 ;
V_33 -> V_2 = F_22 ( & V_33 -> V_39 , & V_35 ) ;
if ( F_23 ( V_33 -> V_2 ) ) {
V_36 = F_24 ( V_33 -> V_2 ) ;
F_16 ( & V_29 -> V_2 , L_9 , V_36 ) ;
goto V_61;
}
F_25 ( V_29 , V_33 ) ;
return 0 ;
V_61:
F_26 ( V_33 -> V_12 , V_33 -> V_22 ) ;
V_56:
if ( F_4 ( V_31 -> V_6 ) )
F_27 ( V_31 -> V_6 ) ;
V_54:
F_28 ( V_33 -> V_11 ) ;
V_45:
F_28 ( V_33 -> V_12 ) ;
V_43:
F_28 ( V_33 -> V_39 . V_40 ) ;
V_42:
return V_36 ;
}
static int T_2 F_29 ( struct V_28 * V_29 )
{
struct V_3 * V_33 = F_30 ( V_29 ) ;
F_31 ( V_33 -> V_2 ) ;
F_26 ( V_33 -> V_12 , V_33 -> V_22 ) ;
F_28 ( V_33 -> V_11 ) ;
F_28 ( V_33 -> V_12 ) ;
if ( F_4 ( V_33 -> V_6 ) )
F_27 ( V_33 -> V_6 ) ;
F_28 ( V_33 -> V_39 . V_40 ) ;
return 0 ;
}
static int T_3 F_32 ( void )
{
return F_33 ( & V_62 ) ;
}
static void T_4 F_34 ( void )
{
F_35 ( & V_62 ) ;
}
