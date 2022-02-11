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
static int F_5 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = & V_15 -> V_2 ;
struct V_10 * V_16 ;
struct V_8 * V_17 ;
int V_7 , V_18 ;
int V_19 = 1 , V_20 = 1 , V_21 = 1 , V_22 = 1 ;
enum V_23 type ;
struct V_24 * V_12 ;
const char * V_25 = L_2 ;
if ( V_2 -> V_26 && V_2 -> V_26 -> V_25 )
V_25 = V_2 -> V_26 -> V_25 ;
V_12 = F_6 ( V_2 ) ;
if ( F_7 ( V_12 ) )
return F_8 ( V_12 ) ;
V_16 = F_9 ( V_2 , sizeof( * V_16 ) , V_27 ) ;
if ( V_16 == NULL ) {
V_7 = - V_28 ;
goto V_29;
}
V_16 -> V_12 = V_12 ;
while ( V_16 -> V_12 [ V_16 -> V_30 ] . V_31 )
V_16 -> V_30 ++ ;
V_16 -> V_32 = F_9 ( V_2 ,
sizeof( * V_16 -> V_32 ) * ( V_16 -> V_30 + 1 ) ,
V_27 ) ;
if ( V_16 -> V_32 == NULL ) {
V_7 = - V_28 ;
goto V_29;
}
for ( V_18 = 0 ; V_18 < V_16 -> V_30 ; V_18 ++ ) {
V_17 = F_9 ( V_2 , sizeof( * V_17 ) , V_27 ) ;
if ( V_17 == NULL ) {
V_7 = - V_28 ;
goto V_29;
}
F_10 ( & V_17 -> V_33 . V_4 ) ;
V_7 = F_11 ( & V_16 -> V_12 [ V_18 ] , & type ) ;
if ( V_7 < 0 )
goto V_29;
switch ( type ) {
case V_34 :
V_17 -> V_33 . V_4 . V_25 = F_12 ( V_27 ,
L_3 ,
V_19 ++ ) ;
break;
case V_35 :
V_17 -> V_33 . V_4 . V_25 = F_12 ( V_27 ,
L_4 ,
V_20 ++ ) ;
break;
case V_36 :
V_17 -> V_33 . V_4 . V_25 = F_12 ( V_27 ,
L_5 ,
V_21 ++ ) ;
break;
case V_37 :
V_17 -> V_33 . V_4 . V_25 = F_12 ( V_27 ,
L_6 ,
V_22 ++ ) ;
break;
default:
V_7 = - V_38 ;
goto V_29;
}
if ( V_17 -> V_33 . V_4 . V_25 == NULL ) {
V_7 = - V_28 ;
goto V_29;
}
V_17 -> V_33 . V_39 = F_1 ;
V_17 -> V_33 . V_4 . V_40 = V_41 ;
V_17 -> V_13 = V_18 ;
V_16 -> V_32 [ V_18 ] = & V_17 -> V_33 . V_4 ;
}
V_16 -> V_42 . V_32 = V_16 -> V_32 ;
V_16 -> V_43 [ 0 ] = & V_16 -> V_42 ;
V_16 -> V_44 = F_13 ( V_2 , V_25 , V_16 ,
V_16 -> V_43 ) ;
if ( F_7 ( V_16 -> V_44 ) ) {
V_7 = F_8 ( V_16 -> V_44 ) ;
goto V_29;
}
F_14 ( V_15 , V_16 ) ;
return 0 ;
V_29:
F_15 ( V_12 ) ;
return V_7 ;
}
static int F_16 ( struct V_14 * V_15 )
{
struct V_10 * V_16 = F_17 ( V_15 ) ;
F_18 ( V_16 -> V_44 ) ;
F_15 ( V_16 -> V_12 ) ;
return 0 ;
}
