static int F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 = V_5 ;
switch ( V_3 ) {
case 1 ... 13750 :
V_4 = V_6 ;
break;
case 13751 ... 27500 :
V_4 = V_7 ;
break;
case 27501 ... 55000 :
V_4 = V_8 ;
break;
case 55001 ... 100000 :
break;
default:
F_2 ( L_1 ,
V_2 -> V_9 -> V_10 , V_3 ) ;
}
return F_3 ( V_2 -> V_11 , V_2 -> V_9 -> V_12 ,
V_13 , V_4 << 6 ) ;
}
static int F_4 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 , * V_20 ;
struct V_21 * V_22 ;
struct V_23 V_24 ;
unsigned int V_25 ;
V_19 = V_15 -> V_26 -> V_27 ;
V_20 = F_5 ( V_19 , L_2 ) ;
if ( ! V_20 ) {
F_6 ( V_15 -> V_26 , L_3 ) ;
return - V_28 ;
}
V_17 -> V_29 = F_7 ( V_30 ) ;
V_22 = F_8 ( V_15 -> V_26 , sizeof( * V_22 ) *
V_17 -> V_29 , V_31 ) ;
if ( ! V_22 ) {
F_6 ( V_15 -> V_26 ,
L_4 ) ;
return - V_32 ;
}
for ( V_25 = 0 ; V_25 < V_17 -> V_29 ; V_25 ++ ) {
V_24 . V_10 = V_30 [ V_25 ] . V_10 ;
V_24 . V_33 = NULL ;
V_24 . V_27 = NULL ;
V_23 ( V_15 -> V_26 , V_20 , & V_24 , 1 ) ;
V_22 [ V_25 ] . V_34 = V_24 . V_33 ;
}
V_17 -> V_30 = V_22 ;
return 0 ;
}
static int F_4 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
return 0 ;
}
static T_1 int F_9 ( struct V_35 * V_36 )
{
struct V_14 * V_15 = F_10 ( V_36 -> V_26 . V_37 ) ;
struct V_16 * V_17 = F_11 ( V_15 -> V_26 ) ;
struct V_1 * * V_2 ;
struct V_38 * V_39 ;
int V_25 , V_40 ;
int V_41 = 0 ;
struct V_42 V_43 = { } ;
F_12 ( & V_36 -> V_26 , L_5 , V_44 ) ;
if ( ! V_17 ) {
F_6 ( & V_36 -> V_26 , L_6 ) ;
return - V_45 ;
}
if ( V_15 -> V_26 -> V_27 ) {
V_41 = F_4 ( V_15 , V_17 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_17 -> V_29 != V_46 ) {
F_6 ( & V_36 -> V_26 ,
L_7 ) ;
return - V_28 ;
}
V_39 = F_8 ( & V_36 -> V_26 , sizeof( struct V_38 ) ,
V_31 ) ;
if ( ! V_39 )
return - V_32 ;
V_40 = sizeof( struct V_1 * ) * V_46 ;
V_39 -> V_2 = F_8 ( & V_36 -> V_26 , V_40 , V_31 ) ;
if ( ! V_39 -> V_2 )
return - V_32 ;
V_2 = V_39 -> V_2 ;
V_43 . V_26 = & V_36 -> V_26 ;
V_43 . V_11 = V_15 -> V_11 ;
F_13 ( V_36 , V_39 ) ;
for ( V_25 = 0 ; V_25 < V_46 ; V_25 ++ ) {
V_43 . V_33 = V_17 -> V_30 [ V_25 ] . V_34 ;
V_2 [ V_25 ] = F_14 ( & V_30 [ V_25 ] , & V_43 ) ;
if ( F_15 ( V_2 [ V_25 ] ) ) {
V_41 = F_16 ( V_2 [ V_25 ] ) ;
F_6 ( & V_36 -> V_26 ,
L_8 , V_25 ) ;
V_2 [ V_25 ] = NULL ;
goto V_47;
}
}
return 0 ;
V_47:
while ( -- V_25 >= 0 )
F_17 ( V_2 [ V_25 ] ) ;
return V_41 ;
}
static int T_2 F_18 ( struct V_35 * V_36 )
{
struct V_38 * V_39 = F_19 ( V_36 ) ;
struct V_1 * * V_2 = V_39 -> V_2 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_46 ; V_25 ++ )
if ( V_2 [ V_25 ] )
F_17 ( V_2 [ V_25 ] ) ;
return 0 ;
}
static int T_3 F_20 ( void )
{
return F_21 ( & V_48 ) ;
}
static void T_4 F_22 ( void )
{
F_23 ( & V_48 ) ;
}
