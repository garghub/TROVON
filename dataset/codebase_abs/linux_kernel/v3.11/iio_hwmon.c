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
static T_1 F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
const char * V_14 = L_2 ;
if ( V_2 -> V_15 && V_2 -> V_15 -> V_14 )
V_14 = V_2 -> V_15 -> V_14 ;
return sprintf ( V_5 , L_3 , V_14 ) ;
}
static int F_6 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = & V_17 -> V_2 ;
struct V_10 * V_18 ;
struct V_8 * V_19 ;
int V_7 , V_20 ;
int V_21 = 1 , V_22 = 1 , V_23 = 1 ;
enum V_24 type ;
struct V_25 * V_12 ;
V_12 = F_7 ( V_2 ) ;
if ( F_8 ( V_12 ) )
return F_9 ( V_12 ) ;
V_18 = F_10 ( V_2 , sizeof( * V_18 ) , V_26 ) ;
if ( V_18 == NULL ) {
V_7 = - V_27 ;
goto V_28;
}
V_18 -> V_12 = V_12 ;
while ( V_18 -> V_12 [ V_18 -> V_29 ] . V_30 )
V_18 -> V_29 ++ ;
V_18 -> V_31 = F_10 ( V_2 ,
sizeof( * V_18 -> V_31 ) * ( V_18 -> V_29 + 2 ) ,
V_26 ) ;
if ( V_18 -> V_31 == NULL ) {
V_7 = - V_27 ;
goto V_28;
}
for ( V_20 = 0 ; V_20 < V_18 -> V_29 ; V_20 ++ ) {
V_19 = F_10 ( V_2 , sizeof( * V_19 ) , V_26 ) ;
if ( V_19 == NULL ) {
V_7 = - V_27 ;
goto V_28;
}
F_11 ( & V_19 -> V_32 . V_4 ) ;
V_7 = F_12 ( & V_18 -> V_12 [ V_20 ] , & type ) ;
if ( V_7 < 0 )
goto V_28;
switch ( type ) {
case V_33 :
V_19 -> V_32 . V_4 . V_14 = F_13 ( V_26 ,
L_4 ,
V_21 ++ ) ;
break;
case V_34 :
V_19 -> V_32 . V_4 . V_14 = F_13 ( V_26 ,
L_5 ,
V_22 ++ ) ;
break;
case V_35 :
V_19 -> V_32 . V_4 . V_14 = F_13 ( V_26 ,
L_6 ,
V_23 ++ ) ;
break;
default:
V_7 = - V_36 ;
goto V_28;
}
if ( V_19 -> V_32 . V_4 . V_14 == NULL ) {
V_7 = - V_27 ;
goto V_28;
}
V_19 -> V_32 . V_37 = F_1 ;
V_19 -> V_32 . V_4 . V_38 = V_39 ;
V_19 -> V_13 = V_20 ;
V_18 -> V_31 [ V_20 ] = & V_19 -> V_32 . V_4 ;
}
V_18 -> V_31 [ V_18 -> V_29 ] = & V_40 . V_4 ;
V_18 -> V_41 . V_31 = V_18 -> V_31 ;
F_14 ( V_17 , V_18 ) ;
V_7 = F_15 ( & V_2 -> V_42 , & V_18 -> V_41 ) ;
if ( V_7 < 0 )
goto V_28;
V_18 -> V_43 = F_16 ( V_2 ) ;
if ( F_8 ( V_18 -> V_43 ) ) {
V_7 = F_9 ( V_18 -> V_43 ) ;
goto V_44;
}
return 0 ;
V_44:
F_17 ( & V_2 -> V_42 , & V_18 -> V_41 ) ;
V_28:
F_18 ( V_12 ) ;
return V_7 ;
}
static int F_19 ( struct V_16 * V_17 )
{
struct V_10 * V_18 = F_20 ( V_17 ) ;
F_21 ( V_18 -> V_43 ) ;
F_17 ( & V_17 -> V_2 . V_42 , & V_18 -> V_41 ) ;
F_18 ( V_18 -> V_12 ) ;
return 0 ;
}
