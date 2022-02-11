static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
int V_6 ;
int V_7 ;
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_10 * V_11 = F_3 ( V_2 ) ;
V_7 = F_4 ( & V_11 -> V_12 [ V_9 -> V_13 ] ,
& V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
return sprintf ( V_5 , L_1 , V_6 ) ;
}
static void F_5 ( struct V_10 * V_14 )
{
int V_15 ;
struct V_8 * V_16 ;
for ( V_15 = 0 ; V_15 < V_14 -> V_17 ; V_15 ++ )
if ( V_14 -> V_18 [ V_15 ] ) {
V_16 = F_2 (
F_6 ( V_14 -> V_18 [ V_15 ] ,
struct V_3 ,
V_4 ) ) ;
F_7 ( V_16 ) ;
}
}
static int T_2 F_8 ( struct V_19 * V_20 )
{
struct V_10 * V_14 ;
struct V_8 * V_16 ;
int V_7 , V_15 ;
int V_21 = 1 , V_22 = 1 , V_23 = 1 ;
enum V_24 type ;
V_14 = F_9 ( sizeof( * V_14 ) , V_25 ) ;
if ( V_14 == NULL ) {
V_7 = - V_26 ;
goto V_27;
}
V_14 -> V_12 = F_10 ( F_11 ( & V_20 -> V_2 ) ) ;
if ( F_12 ( V_14 -> V_12 ) ) {
V_7 = F_13 ( V_14 -> V_12 ) ;
goto V_28;
}
while ( V_14 -> V_12 [ V_14 -> V_17 ] . V_29 )
V_14 -> V_17 ++ ;
V_14 -> V_18 = F_9 ( sizeof( V_14 -> V_18 ) * ( V_14 -> V_17 + 1 ) ,
V_25 ) ;
if ( V_14 -> V_18 == NULL ) {
V_7 = - V_26 ;
goto V_30;
}
for ( V_15 = 0 ; V_15 < V_14 -> V_17 ; V_15 ++ ) {
V_16 = F_9 ( sizeof( * V_16 ) , V_25 ) ;
if ( V_16 == NULL ) {
V_7 = - V_26 ;
goto V_31;
}
F_14 ( & V_16 -> V_32 . V_4 ) ;
V_7 = F_15 ( & V_14 -> V_12 [ V_15 ] , & type ) ;
if ( V_7 < 0 ) {
F_7 ( V_16 ) ;
goto V_31;
}
switch ( type ) {
case V_33 :
V_16 -> V_32 . V_4 . V_34 = F_16 ( V_25 ,
L_2 ,
V_21 ++ ) ;
break;
case V_35 :
V_16 -> V_32 . V_4 . V_34 = F_16 ( V_25 ,
L_3 ,
V_22 ++ ) ;
break;
case V_36 :
V_16 -> V_32 . V_4 . V_34 = F_16 ( V_25 ,
L_4 ,
V_23 ++ ) ;
break;
default:
V_7 = - V_37 ;
F_7 ( V_16 ) ;
goto V_31;
}
if ( V_16 -> V_32 . V_4 . V_34 == NULL ) {
F_7 ( V_16 ) ;
V_7 = - V_26 ;
goto V_31;
}
V_16 -> V_32 . V_38 = F_1 ;
V_16 -> V_32 . V_4 . V_39 = V_40 ;
V_16 -> V_13 = V_15 ;
V_14 -> V_18 [ V_15 ] = & V_16 -> V_32 . V_4 ;
}
V_14 -> V_41 . V_18 = V_14 -> V_18 ;
F_17 ( V_20 , V_14 ) ;
V_7 = F_18 ( & V_20 -> V_2 . V_42 , & V_14 -> V_41 ) ;
if ( V_7 < 0 )
goto V_31;
V_14 -> V_43 = F_19 ( & V_20 -> V_2 ) ;
if ( F_12 ( V_14 -> V_43 ) ) {
V_7 = F_13 ( V_14 -> V_43 ) ;
goto V_44;
}
return 0 ;
V_44:
F_20 ( & V_20 -> V_2 . V_42 , & V_14 -> V_41 ) ;
V_31:
F_5 ( V_14 ) ;
F_7 ( V_14 -> V_18 ) ;
V_30:
F_21 ( V_14 -> V_12 ) ;
V_28:
F_7 ( V_14 ) ;
V_27:
return V_7 ;
}
static int T_3 F_22 ( struct V_19 * V_20 )
{
struct V_10 * V_14 = F_23 ( V_20 ) ;
F_24 ( V_14 -> V_43 ) ;
F_20 ( & V_20 -> V_2 . V_42 , & V_14 -> V_41 ) ;
F_5 ( V_14 ) ;
F_7 ( V_14 -> V_18 ) ;
F_21 ( V_14 -> V_12 ) ;
return 0 ;
}
