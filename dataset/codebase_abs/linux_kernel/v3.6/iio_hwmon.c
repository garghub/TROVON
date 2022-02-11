static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
long V_6 ;
int V_7 , V_8 , V_9 , V_10 ;
struct V_11 * V_12 = F_2 ( V_4 ) ;
struct V_13 * V_14 = F_3 ( V_2 ) ;
V_8 = F_4 ( & V_14 -> V_15 [ V_12 -> V_16 ] ,
& V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_5 ( & V_14 -> V_15 [ V_12 -> V_16 ] ,
& V_9 , & V_10 ) ;
if ( V_8 < 0 )
return V_8 ;
switch ( V_8 ) {
case V_17 :
V_6 = V_7 * V_9 ;
break;
case V_18 :
V_6 = ( V_19 ) V_7 * ( V_19 ) V_9 +
F_6 ( ( V_19 ) V_7 * ( V_19 ) V_10 , 1000000LL ) ;
break;
case V_20 :
V_6 = ( V_19 ) V_7 * ( V_19 ) V_9 +
F_6 ( ( V_19 ) V_7 * ( V_19 ) V_10 , 1000000000LL ) ;
break;
default:
return - V_21 ;
}
return sprintf ( V_5 , L_1 , V_6 ) ;
}
static void F_7 ( struct V_13 * V_22 )
{
int V_23 ;
struct V_11 * V_24 ;
for ( V_23 = 0 ; V_23 < V_22 -> V_25 ; V_23 ++ )
if ( V_22 -> V_26 [ V_23 ] ) {
V_24 = F_2 (
F_8 ( V_22 -> V_26 [ V_23 ] ,
struct V_3 ,
V_4 ) ) ;
F_9 ( V_24 ) ;
}
}
static int T_2 F_10 ( struct V_27 * V_28 )
{
struct V_13 * V_22 ;
struct V_11 * V_24 ;
int V_8 , V_23 ;
int V_29 = 1 , V_30 = 1 , V_31 = 1 ;
enum V_32 type ;
V_22 = F_11 ( sizeof( * V_22 ) , V_33 ) ;
if ( V_22 == NULL ) {
V_8 = - V_34 ;
goto V_35;
}
V_22 -> V_15 = F_12 ( F_13 ( & V_28 -> V_2 ) ) ;
if ( F_14 ( V_22 -> V_15 ) ) {
V_8 = F_15 ( V_22 -> V_15 ) ;
goto V_36;
}
while ( V_22 -> V_15 [ V_22 -> V_25 ] . V_37 )
V_22 -> V_25 ++ ;
V_22 -> V_26 = F_11 ( sizeof( V_22 -> V_26 ) * ( V_22 -> V_25 + 1 ) ,
V_33 ) ;
if ( V_22 -> V_26 == NULL ) {
V_8 = - V_34 ;
goto V_38;
}
for ( V_23 = 0 ; V_23 < V_22 -> V_25 ; V_23 ++ ) {
V_24 = F_11 ( sizeof( * V_24 ) , V_33 ) ;
if ( V_24 == NULL ) {
V_8 = - V_34 ;
goto V_39;
}
F_16 ( & V_24 -> V_40 . V_4 ) ;
V_8 = F_17 ( & V_22 -> V_15 [ V_23 ] , & type ) ;
if ( V_8 < 0 ) {
F_9 ( V_24 ) ;
goto V_39;
}
switch ( type ) {
case V_41 :
V_24 -> V_40 . V_4 . V_42 = F_18 ( V_33 ,
L_2 ,
V_29 ++ ) ;
break;
case V_43 :
V_24 -> V_40 . V_4 . V_42 = F_18 ( V_33 ,
L_3 ,
V_30 ++ ) ;
break;
case V_44 :
V_24 -> V_40 . V_4 . V_42 = F_18 ( V_33 ,
L_4 ,
V_31 ++ ) ;
break;
default:
V_8 = - V_21 ;
F_9 ( V_24 ) ;
goto V_39;
}
if ( V_24 -> V_40 . V_4 . V_42 == NULL ) {
F_9 ( V_24 ) ;
V_8 = - V_34 ;
goto V_39;
}
V_24 -> V_40 . V_45 = F_1 ;
V_24 -> V_40 . V_4 . V_46 = V_47 ;
V_24 -> V_16 = V_23 ;
V_22 -> V_26 [ V_23 ] = & V_24 -> V_40 . V_4 ;
}
V_22 -> V_48 . V_26 = V_22 -> V_26 ;
F_19 ( V_28 , V_22 ) ;
V_8 = F_20 ( & V_28 -> V_2 . V_49 , & V_22 -> V_48 ) ;
if ( V_8 < 0 )
goto V_39;
V_22 -> V_50 = F_21 ( & V_28 -> V_2 ) ;
if ( F_14 ( V_22 -> V_50 ) ) {
V_8 = F_15 ( V_22 -> V_50 ) ;
goto V_51;
}
return 0 ;
V_51:
F_22 ( & V_28 -> V_2 . V_49 , & V_22 -> V_48 ) ;
V_39:
F_7 ( V_22 ) ;
F_9 ( V_22 -> V_26 ) ;
V_38:
F_23 ( V_22 -> V_15 ) ;
V_36:
F_9 ( V_22 ) ;
V_35:
return V_8 ;
}
static int T_3 F_24 ( struct V_27 * V_28 )
{
struct V_13 * V_22 = F_25 ( V_28 ) ;
F_26 ( V_22 -> V_50 ) ;
F_22 ( & V_28 -> V_2 . V_49 , & V_22 -> V_48 ) ;
F_7 ( V_22 ) ;
F_9 ( V_22 -> V_26 ) ;
F_23 ( V_22 -> V_15 ) ;
return 0 ;
}
static int F_27 ( void )
{
return F_28 ( & V_52 ) ;
}
static void F_29 ( void )
{
F_30 ( & V_52 ) ;
}
