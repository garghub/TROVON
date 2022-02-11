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
case V_13 :
switch ( V_4 -> type ) {
case V_14 :
if ( V_4 -> V_15 ) {
* V_5 = V_9 -> V_16 ;
V_10 = V_17 ;
} else if ( V_4 -> V_18 ) {
if ( V_4 -> V_19 == 1 )
* V_5 = V_9 -> V_20 [ 0 ] ;
else
* V_5 = V_9 -> V_20 [ 1 ] ;
V_10 = V_17 ;
} else {
* V_5 = V_9 -> V_21 ;
V_10 = V_17 ;
}
break;
case V_22 :
* V_5 = V_9 -> V_23 ;
V_10 = V_17 ;
break;
default:
break;
}
break;
case V_24 :
switch ( V_4 -> type ) {
case V_25 :
* V_5 = V_9 -> V_26 ;
V_10 = V_17 ;
break;
case V_27 :
switch ( V_4 -> V_28 ) {
case V_29 :
* V_5 = V_9 -> V_30 ;
V_10 = V_17 ;
break;
case V_31 :
* V_5 = V_9 -> V_32 ;
V_10 = V_17 ;
break;
default:
break;
}
break;
default:
break;
}
break;
case V_33 :
* V_5 = 7 ;
V_10 = V_17 ;
break;
case V_34 :
switch ( V_4 -> type ) {
case V_14 :
switch ( V_4 -> V_18 ) {
case 0 :
* V_5 = 0 ;
* V_6 = 1333 ;
V_10 = V_35 ;
break;
case 1 :
* V_5 = 0 ;
* V_6 = 1344 ;
V_10 = V_36 ;
}
break;
default:
break;
}
break;
case V_37 :
* V_5 = V_9 -> V_38 ;
V_10 = V_17 ;
break;
case V_39 :
* V_5 = V_9 -> V_40 -> V_5 ;
* V_6 = V_9 -> V_40 -> V_6 ;
V_10 = V_35 ;
break;
case V_41 :
* V_5 = 3 ;
* V_6 = 33 ;
V_10 = V_36 ;
break;
case V_42 :
switch ( V_4 -> type ) {
case V_25 :
* V_5 = V_9 -> V_43 ;
V_10 = V_17 ;
break;
default:
break;
}
break;
case V_44 :
switch ( V_4 -> type ) {
case V_25 :
* V_5 = V_9 -> V_45 ;
V_10 = V_17 ;
break;
default:
break;
}
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
int V_46 ;
int V_10 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
switch ( V_7 ) {
case V_13 :
switch ( V_4 -> type ) {
case V_14 :
if ( V_4 -> V_15 == 0 )
return - V_11 ;
F_3 ( & V_9 -> V_12 ) ;
V_9 -> V_16 = V_5 ;
F_4 ( & V_9 -> V_12 ) ;
return 0 ;
default:
return - V_11 ;
}
case V_24 :
switch ( V_4 -> type ) {
case V_25 :
F_3 ( & V_9 -> V_12 ) ;
V_9 -> V_26 = V_5 ;
F_4 ( & V_9 -> V_12 ) ;
return 0 ;
case V_27 :
if ( V_5 < 0 )
V_5 = 0 ;
if ( V_5 > 100 )
V_5 = 100 ;
switch ( V_4 -> V_28 ) {
case V_29 :
V_9 -> V_30 = V_5 ;
return 0 ;
case V_31 :
V_9 -> V_32 = V_5 ;
return 0 ;
default:
return - V_11 ;
}
break;
default:
return - V_11 ;
}
case V_39 :
F_3 ( & V_9 -> V_12 ) ;
for ( V_46 = 0 ; V_46 < F_6 ( V_47 ) ; V_46 ++ )
if ( V_5 == V_47 [ V_46 ] . V_5 &&
V_6 == V_47 [ V_46 ] . V_6 )
break;
if ( V_46 == F_6 ( V_47 ) )
V_10 = - V_11 ;
else
V_9 -> V_40 = & V_47 [ V_46 ] ;
F_4 ( & V_9 -> V_12 ) ;
return V_10 ;
case V_37 :
F_3 ( & V_9 -> V_12 ) ;
V_9 -> V_38 = V_5 ;
F_4 ( & V_9 -> V_12 ) ;
return 0 ;
case V_42 :
switch ( V_4 -> type ) {
case V_25 :
F_3 ( & V_9 -> V_12 ) ;
V_9 -> V_43 = V_5 ;
F_4 ( & V_9 -> V_12 ) ;
return 0 ;
default:
return - V_11 ;
}
case V_44 :
switch ( V_4 -> type ) {
case V_25 :
V_9 -> V_45 = V_5 ;
return 0 ;
default:
return - V_11 ;
}
default:
return - V_11 ;
}
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_9 -> V_16 = 0 ;
V_9 -> V_21 = 73 ;
V_9 -> V_20 [ 0 ] = 33 ;
V_9 -> V_20 [ 1 ] = - 34 ;
V_9 -> V_23 = 34 ;
V_9 -> V_38 = - 7 ;
V_9 -> V_40 = & V_47 [ 0 ] ;
V_9 -> V_26 = 47 ;
V_9 -> V_30 = 98 ;
V_9 -> V_32 = 4 ;
return 0 ;
}
static int F_8 ( int V_48 )
{
int V_10 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
V_2 = F_9 ( sizeof( * V_9 ) ) ;
if ( ! V_2 ) {
V_10 = - V_49 ;
goto V_50;
}
V_9 = F_2 ( V_2 ) ;
F_10 ( & V_9 -> V_12 ) ;
F_7 ( V_2 ) ;
V_51 [ V_48 ] = V_2 ;
V_2 -> V_52 = V_53 ;
V_2 -> V_54 = V_55 ;
V_2 -> V_56 = F_6 ( V_55 ) ;
V_2 -> V_57 = & V_58 ;
V_2 -> V_59 = V_60 ;
V_10 = F_11 ( V_2 ) ;
if ( V_10 < 0 )
goto V_61;
V_10 = F_12 ( V_2 ) ;
if ( V_10 < 0 )
goto V_62;
V_10 = F_13 ( V_2 ) ;
if ( V_10 < 0 )
goto V_63;
return 0 ;
V_63:
F_14 ( V_2 ) ;
V_62:
F_15 ( V_2 ) ;
V_61:
F_16 ( V_2 ) ;
V_50:
return V_10 ;
}
static int F_17 ( int V_48 )
{
int V_10 ;
struct V_1 * V_2 = V_51 [ V_48 ] ;
F_18 ( V_2 ) ;
F_14 ( V_2 ) ;
V_10 = F_15 ( V_2 ) ;
if ( V_10 )
goto V_50;
F_16 ( V_2 ) ;
V_50:
return V_10 ;
}
static T_1 int F_19 ( void )
{
int V_46 , V_10 ;
if ( V_64 > 10 ) {
V_64 = 1 ;
return - V_11 ;
}
V_51 = F_20 ( V_64 , sizeof( * V_51 ) ,
V_65 ) ;
for ( V_46 = 0 ; V_46 < V_64 ; V_46 ++ ) {
V_10 = F_8 ( V_46 ) ;
if ( V_10 < 0 )
return V_10 ;
}
return 0 ;
}
static T_2 void F_21 ( void )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_64 ; V_46 ++ )
F_17 ( V_46 ) ;
F_22 ( V_51 ) ;
}
