static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 ,
int * V_6 ,
long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_10 = - V_11 ;
F_3 ( & V_9 -> V_12 ) ;
switch ( V_7 ) {
case 0 :
switch ( V_4 -> type ) {
case V_13 :
if ( V_4 -> V_14 ) {
* V_5 = V_9 -> V_15 ;
V_10 = V_16 ;
} else if ( V_4 -> V_17 ) {
if ( V_4 -> V_18 == 1 )
* V_5 = V_9 -> V_19 [ 0 ] ;
else
* V_5 = V_9 -> V_19 [ 1 ] ;
V_10 = V_16 ;
} else {
* V_5 = V_9 -> V_20 ;
V_10 = V_16 ;
}
break;
case V_21 :
* V_5 = V_9 -> V_22 ;
V_10 = V_16 ;
break;
default:
break;
}
break;
case ( 1 << V_23 ) :
* V_5 = 7 ;
V_10 = V_16 ;
break;
case ( 1 << V_24 ) :
* V_5 = 0 ;
* V_6 = 1333 ;
V_10 = V_25 ;
break;
case ( 1 << V_26 ) :
* V_5 = 0 ;
* V_6 = 1344 ;
V_10 = V_27 ;
break;
case ( 1 << V_28 ) :
* V_5 = V_9 -> V_29 ;
V_10 = V_16 ;
break;
case ( 1 << V_30 ) :
* V_5 = V_9 -> V_31 -> V_5 ;
* V_6 = V_9 -> V_31 -> V_6 ;
V_10 = V_25 ;
break;
default:
break;
}
F_4 ( & V_9 -> V_12 ) ;
return V_10 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int V_5 ,
int V_6 ,
long V_7 )
{
int V_32 ;
int V_10 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
switch ( V_7 ) {
case 0 :
if ( V_4 -> V_14 == 0 )
return - V_11 ;
F_3 ( & V_9 -> V_12 ) ;
V_9 -> V_15 = V_5 ;
F_4 ( & V_9 -> V_12 ) ;
return 0 ;
case ( 1 << V_28 ) :
F_3 ( & V_9 -> V_12 ) ;
for ( V_32 = 0 ; V_32 < F_6 ( V_33 ) ; V_32 ++ )
if ( V_5 == V_33 [ V_32 ] . V_5 &&
V_6 == V_33 [ V_32 ] . V_6 )
break;
if ( V_32 == F_6 ( V_33 ) )
V_10 = - V_11 ;
else
V_9 -> V_31 = & V_33 [ V_32 ] ;
F_4 ( & V_9 -> V_12 ) ;
return V_10 ;
default:
return - V_11 ;
}
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_9 -> V_15 = 0 ;
V_9 -> V_20 = 73 ;
V_9 -> V_19 [ 0 ] = 33 ;
V_9 -> V_19 [ 1 ] = - 34 ;
V_9 -> V_22 = 34 ;
V_9 -> V_29 = - 7 ;
V_9 -> V_31 = & V_33 [ 0 ] ;
return 0 ;
}
static int T_1 F_8 ( int V_34 )
{
int V_10 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
V_2 = F_9 ( sizeof( * V_9 ) ) ;
if ( V_2 == NULL ) {
V_10 = - V_35 ;
goto V_36;
}
V_9 = F_2 ( V_2 ) ;
F_10 ( & V_9 -> V_12 ) ;
F_7 ( V_2 ) ;
V_37 [ V_34 ] = V_2 ;
V_2 -> V_38 = V_39 ;
V_2 -> V_40 = V_41 ;
V_2 -> V_42 = F_6 ( V_41 ) ;
V_2 -> V_43 = & V_44 ;
V_2 -> V_45 = V_46 ;
V_10 = F_11 ( V_2 ) ;
if ( V_10 < 0 )
goto V_47;
V_10 = F_12 ( V_2 ) ;
if ( V_10 < 0 )
goto V_48;
V_10 = F_13 ( V_2 , V_41 , 5 ) ;
if ( V_10 < 0 )
goto V_49;
V_10 = F_14 ( V_2 ) ;
if ( V_10 < 0 )
goto V_50;
return 0 ;
V_50:
F_15 ( V_2 ) ;
V_49:
F_16 ( V_2 ) ;
V_48:
F_17 ( V_2 ) ;
V_47:
F_18 ( V_2 ) ;
V_36:
return V_10 ;
}
static int F_19 ( int V_34 )
{
int V_10 ;
struct V_1 * V_2 = V_37 [ V_34 ] ;
F_20 ( V_2 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
V_10 = F_17 ( V_2 ) ;
if ( V_10 )
goto V_36;
F_18 ( V_2 ) ;
V_36:
return V_10 ;
}
static T_2 int F_21 ( void )
{
int V_32 , V_10 ;
if ( V_51 > 10 ) {
V_51 = 1 ;
return - V_11 ;
}
V_37 = F_22 ( sizeof( * V_37 ) * V_51 , V_52 ) ;
for ( V_32 = 0 ; V_32 < V_51 ; V_32 ++ ) {
V_10 = F_8 ( V_32 ) ;
if ( V_10 < 0 )
return V_10 ;
}
return 0 ;
}
static T_3 void F_23 ( void )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_51 ; V_32 ++ )
F_19 ( V_32 ) ;
F_24 ( V_37 ) ;
}
