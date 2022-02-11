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
int V_16 , int V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_9 , V_18 , V_13 ;
V_18 = - 1 ;
for ( V_9 = 0 ; V_9 < V_4 -> V_10 ; V_9 ++ )
if ( V_4 -> V_11 [ V_9 ] . V_14 >= V_16 &&
V_4 -> V_11 [ V_9 ] . V_14 <= V_17 )
V_18 = V_4 -> V_11 [ V_9 ] . V_12 ;
if ( V_18 < 0 )
return - V_15 ;
for ( V_9 = 0 ; V_9 < V_4 -> V_19 ; V_9 ++ ) {
V_13 = ( V_18 & ( 1 << V_9 ) ) >> V_9 ;
F_10 ( V_4 -> V_12 [ V_9 ] . V_20 , V_13 ) ;
}
V_4 -> V_13 = V_18 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
int V_21 , int V_22 ,
unsigned * V_23 )
{
return F_9 ( V_2 , V_21 , V_22 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned V_23 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_23 >= V_4 -> V_10 )
return - V_15 ;
return V_4 -> V_11 [ V_23 ] . V_14 ;
}
static int F_13 ( struct V_1 * V_2 ,
int V_24 , int V_25 )
{
return F_9 ( V_2 , V_24 , V_25 ) ;
}
static int T_1 F_14 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_2 . V_30 ;
struct V_3 * V_31 ;
int V_9 , V_32 , V_13 ;
V_31 = F_15 ( sizeof( struct V_3 ) , V_33 ) ;
if ( V_31 == NULL ) {
F_16 ( & V_27 -> V_2 , L_1 ) ;
return - V_34 ;
}
V_31 -> V_35 . V_36 = F_17 ( V_29 -> V_37 , V_33 ) ;
if ( V_31 -> V_35 . V_36 == NULL ) {
F_16 ( & V_27 -> V_2 , L_2 ) ;
V_32 = - V_34 ;
goto V_38;
}
V_31 -> V_12 = F_18 ( V_29 -> V_12 ,
V_29 -> V_19 * sizeof( struct V_20 ) ,
V_33 ) ;
if ( V_31 -> V_12 == NULL ) {
F_16 ( & V_27 -> V_2 , L_3 ) ;
V_32 = - V_34 ;
goto V_39;
}
V_31 -> V_11 = F_18 ( V_29 -> V_11 ,
V_29 -> V_10 *
sizeof( struct V_40 ) ,
V_33 ) ;
if ( V_31 -> V_11 == NULL ) {
F_16 ( & V_27 -> V_2 , L_4 ) ;
V_32 = - V_34 ;
goto V_41;
}
V_31 -> V_10 = V_29 -> V_10 ;
V_31 -> V_35 . V_42 = V_43 ;
switch ( V_29 -> type ) {
case V_44 :
V_31 -> V_35 . type = V_44 ;
V_31 -> V_35 . V_45 = & V_46 ;
V_31 -> V_35 . V_47 = V_29 -> V_10 ;
break;
case V_48 :
V_31 -> V_35 . type = V_48 ;
V_31 -> V_35 . V_45 = & V_49 ;
break;
default:
F_16 ( & V_27 -> V_2 , L_5 ) ;
V_32 = - V_15 ;
goto V_41;
break;
}
V_31 -> V_6 = V_29 -> V_6 ;
V_31 -> V_8 = V_29 -> V_8 ;
if ( F_4 ( V_29 -> V_6 ) ) {
V_31 -> V_7 = V_29 -> V_7 ;
V_32 = F_19 ( V_29 -> V_6 , V_29 -> V_37 ) ;
if ( V_32 ) {
F_16 ( & V_27 -> V_2 ,
L_6 ,
V_29 -> V_6 , V_32 ) ;
goto V_50;
}
if ( V_29 -> V_51 ) {
V_31 -> V_5 = true ;
V_32 = F_20 ( V_29 -> V_6 ,
V_29 -> V_7 ) ;
} else {
V_31 -> V_5 = false ;
V_32 = F_20 ( V_29 -> V_6 ,
! V_29 -> V_7 ) ;
}
if ( V_32 ) {
F_16 ( & V_27 -> V_2 ,
L_7 ,
V_29 -> V_6 , V_32 ) ;
goto V_52;
}
} else {
V_31 -> V_5 = true ;
}
V_31 -> V_19 = V_29 -> V_19 ;
V_32 = F_21 ( V_31 -> V_12 , V_31 -> V_19 ) ;
if ( V_32 ) {
F_16 ( & V_27 -> V_2 ,
L_8 , V_32 ) ;
goto V_52;
}
V_13 = 0 ;
for ( V_9 = 0 ; V_9 < V_31 -> V_19 ; V_9 ++ ) {
if ( V_29 -> V_12 [ V_9 ] . V_53 & V_54 )
V_13 |= ( 1 << V_9 ) ;
}
V_31 -> V_13 = V_13 ;
V_31 -> V_2 = F_22 ( & V_31 -> V_35 , & V_27 -> V_2 ,
V_29 -> V_55 , V_31 , NULL ) ;
if ( F_23 ( V_31 -> V_2 ) ) {
V_32 = F_24 ( V_31 -> V_2 ) ;
F_16 ( & V_27 -> V_2 , L_9 , V_32 ) ;
goto V_56;
}
F_25 ( V_27 , V_31 ) ;
return 0 ;
V_56:
F_26 ( V_31 -> V_12 , V_31 -> V_19 ) ;
V_52:
if ( F_4 ( V_29 -> V_6 ) )
F_27 ( V_29 -> V_6 ) ;
V_50:
F_28 ( V_31 -> V_11 ) ;
V_41:
F_28 ( V_31 -> V_12 ) ;
V_39:
F_28 ( V_31 -> V_35 . V_36 ) ;
V_38:
F_28 ( V_31 ) ;
return V_32 ;
}
static int T_2 F_29 ( struct V_26 * V_27 )
{
struct V_3 * V_31 = F_30 ( V_27 ) ;
F_31 ( V_31 -> V_2 ) ;
F_26 ( V_31 -> V_12 , V_31 -> V_19 ) ;
F_28 ( V_31 -> V_11 ) ;
F_28 ( V_31 -> V_12 ) ;
if ( F_4 ( V_31 -> V_6 ) )
F_27 ( V_31 -> V_6 ) ;
F_28 ( V_31 -> V_35 . V_36 ) ;
F_28 ( V_31 ) ;
return 0 ;
}
static int T_3 F_32 ( void )
{
return F_33 ( & V_57 ) ;
}
static void T_4 F_34 ( void )
{
F_35 ( & V_57 ) ;
}
