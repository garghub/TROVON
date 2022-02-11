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
case V_23 :
* V_5 = 7 ;
V_10 = V_16 ;
break;
case V_24 :
switch ( V_4 -> V_17 ) {
case 0 :
* V_5 = 0 ;
* V_6 = 1333 ;
V_10 = V_25 ;
break;
case 1 :
* V_5 = 0 ;
* V_6 = 1344 ;
V_10 = V_26 ;
}
break;
case V_27 :
* V_5 = V_9 -> V_28 ;
V_10 = V_16 ;
break;
case V_29 :
* V_5 = V_9 -> V_30 -> V_5 ;
* V_6 = V_9 -> V_30 -> V_6 ;
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
int V_31 ;
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
case V_27 :
F_3 ( & V_9 -> V_12 ) ;
for ( V_31 = 0 ; V_31 < F_6 ( V_32 ) ; V_31 ++ )
if ( V_5 == V_32 [ V_31 ] . V_5 &&
V_6 == V_32 [ V_31 ] . V_6 )
break;
if ( V_31 == F_6 ( V_32 ) )
V_10 = - V_11 ;
else
V_9 -> V_30 = & V_32 [ V_31 ] ;
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
V_9 -> V_28 = - 7 ;
V_9 -> V_30 = & V_32 [ 0 ] ;
return 0 ;
}
static int T_1 F_8 ( int V_33 )
{
int V_10 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
V_2 = F_9 ( sizeof( * V_9 ) ) ;
if ( V_2 == NULL ) {
V_10 = - V_34 ;
goto V_35;
}
V_9 = F_2 ( V_2 ) ;
F_10 ( & V_9 -> V_12 ) ;
F_7 ( V_2 ) ;
V_36 [ V_33 ] = V_2 ;
V_2 -> V_37 = V_38 ;
V_2 -> V_39 = V_40 ;
V_2 -> V_41 = F_6 ( V_40 ) ;
V_2 -> V_42 = & V_43 ;
V_2 -> V_44 = V_45 ;
V_10 = F_11 ( V_2 ) ;
if ( V_10 < 0 )
goto V_46;
V_10 = F_12 ( V_2 ) ;
if ( V_10 < 0 )
goto V_47;
V_10 = F_13 ( V_2 , V_40 , 5 ) ;
if ( V_10 < 0 )
goto V_48;
V_10 = F_14 ( V_2 ) ;
if ( V_10 < 0 )
goto V_49;
return 0 ;
V_49:
F_15 ( V_2 ) ;
V_48:
F_16 ( V_2 ) ;
V_47:
F_17 ( V_2 ) ;
V_46:
F_18 ( V_2 ) ;
V_35:
return V_10 ;
}
static int F_19 ( int V_33 )
{
int V_10 ;
struct V_1 * V_2 = V_36 [ V_33 ] ;
F_20 ( V_2 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
V_10 = F_17 ( V_2 ) ;
if ( V_10 )
goto V_35;
F_18 ( V_2 ) ;
V_35:
return V_10 ;
}
static T_2 int F_21 ( void )
{
int V_31 , V_10 ;
if ( V_50 > 10 ) {
V_50 = 1 ;
return - V_11 ;
}
V_36 = F_22 ( V_50 , sizeof( * V_36 ) ,
V_51 ) ;
for ( V_31 = 0 ; V_31 < V_50 ; V_31 ++ ) {
V_10 = F_8 ( V_31 ) ;
if ( V_10 < 0 )
return V_10 ;
}
return 0 ;
}
static T_3 void F_23 ( void )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_50 ; V_31 ++ )
F_19 ( V_31 ) ;
F_24 ( V_36 ) ;
}
