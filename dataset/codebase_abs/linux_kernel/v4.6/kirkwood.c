static T_1 T_2 F_1 ( void T_3 * V_1 )
{
T_1 V_2 = ( F_2 ( V_1 ) >> V_3 ) &
V_4 ;
return ( V_2 ) ? 166666667 : 200000000 ;
}
static T_1 T_2 F_3 ( void T_3 * V_1 )
{
T_1 V_2 = F_4 ( F_2 ( V_1 ) ) ;
return V_5 [ V_2 ] ;
}
static void T_2 F_5 (
void T_3 * V_1 , int V_6 , int * V_7 , int * div )
{
switch ( V_6 ) {
case V_8 :
{
T_1 V_2 = F_6 ( F_2 ( V_1 ) ) ;
* V_7 = V_9 [ V_2 ] [ 0 ] ;
* div = V_9 [ V_2 ] [ 1 ] ;
break;
}
case V_10 :
{
T_1 V_2 = ( F_2 ( V_1 ) >> V_11 ) &
V_12 ;
* V_7 = V_13 [ V_2 ] [ 0 ] ;
* div = V_13 [ V_2 ] [ 1 ] ;
break;
}
}
}
static T_1 T_2 F_7 ( void T_3 * V_1 )
{
T_1 V_2 = ( F_2 ( V_1 ) >> V_14 ) & V_15 ;
return V_16 [ V_2 ] ;
}
static void T_2 F_8 (
void T_3 * V_1 , int V_6 , int * V_7 , int * div )
{
switch ( V_6 ) {
case V_8 :
{
* V_7 = 1 ;
* div = 2 ;
break;
}
case V_10 :
{
T_1 V_2 = ( F_2 ( V_1 ) >> V_14 ) &
V_15 ;
* V_7 = V_17 [ V_2 ] [ 0 ] ;
* div = V_17 [ V_2 ] [ 1 ] ;
break;
}
}
}
static struct V_18 * F_9 (
struct V_19 * V_20 , void * V_21 )
{
struct V_22 * V_23 = (struct V_22 * ) V_21 ;
int V_24 ;
if ( V_20 -> V_25 < 1 )
return F_10 ( - V_26 ) ;
for ( V_24 = 0 ; V_24 < V_23 -> V_27 ; V_24 ++ ) {
struct V_28 * V_29 =
F_11 ( F_12 ( V_23 -> V_30 [ V_24 ] ) ) ;
if ( V_20 -> args [ 0 ] == V_29 -> V_31 )
return V_23 -> V_30 [ V_24 ] ;
}
return F_10 ( - V_32 ) ;
}
static void T_2 F_13 ( struct V_33 * V_34 ,
const struct V_35 * V_36 )
{
struct V_22 * V_23 ;
void T_3 * V_37 ;
int V_24 ;
V_37 = F_14 ( V_34 , 0 ) ;
if ( F_15 ( ! V_37 ) )
return;
V_23 = F_16 ( sizeof( * V_23 ) , V_38 ) ;
if ( F_15 ( ! V_23 ) )
goto V_39;
V_23 -> V_40 = & V_41 ;
for ( V_24 = 0 ; V_36 [ V_24 ] . V_42 ; )
V_24 ++ ;
V_23 -> V_27 = V_24 ;
V_23 -> V_30 = F_17 ( V_23 -> V_27 , sizeof( struct V_18 * ) ,
V_38 ) ;
if ( F_15 ( ! V_23 -> V_30 ) )
goto V_43;
for ( V_24 = 0 ; V_24 < V_23 -> V_27 ; V_24 ++ ) {
V_23 -> V_30 [ V_24 ] = F_18 ( NULL , V_36 [ V_24 ] . V_42 ,
V_36 [ V_24 ] . V_44 , V_36 [ V_24 ] . V_45 ,
V_36 [ V_24 ] . V_46 , V_37 , V_36 [ V_24 ] . V_31 ,
V_36 [ V_24 ] . V_47 , V_36 [ V_24 ] . V_46 , V_23 -> V_40 ) ;
F_15 ( F_19 ( V_23 -> V_30 [ V_24 ] ) ) ;
}
F_20 ( V_34 , F_9 , V_23 ) ;
return;
V_43:
F_21 ( V_23 ) ;
V_39:
F_22 ( V_37 ) ;
}
static void T_2 F_23 ( struct V_33 * V_34 )
{
struct V_33 * V_48 =
F_24 ( NULL , NULL , L_1 ) ;
if ( F_25 ( V_34 , L_2 ) )
F_26 ( V_34 , & V_49 ) ;
else
F_26 ( V_34 , & V_50 ) ;
if ( V_48 ) {
F_27 ( V_48 , V_51 ) ;
F_13 ( V_48 , V_52 ) ;
}
}
