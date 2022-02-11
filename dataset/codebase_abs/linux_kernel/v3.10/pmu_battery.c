static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
union V_5 * V_6 )
{
switch ( V_4 ) {
case V_7 :
V_6 -> V_8 = ( ! ! ( V_9 & V_10 ) ) ||
( V_11 == 0 ) ;
break;
default:
return - V_12 ;
}
return 0 ;
}
static char * F_2 ( struct V_13 * V_14 )
{
switch ( V_14 -> V_15 & V_16 ) {
case V_17 :
return V_18 [ 0 ] ;
case V_19 :
return V_18 [ 1 ] ;
case V_20 :
return V_18 [ 2 ] ;
default: break;
}
return V_18 [ 3 ] ;
}
static int F_3 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
union V_5 * V_6 )
{
struct V_21 * V_22 = F_4 ( V_2 ) ;
struct V_13 * V_14 = V_22 -> V_14 ;
switch ( V_4 ) {
case V_23 :
if ( V_14 -> V_15 & V_24 )
V_6 -> V_8 = V_25 ;
else if ( V_9 & V_10 )
V_6 -> V_8 = V_26 ;
else
V_6 -> V_8 = V_27 ;
break;
case V_28 :
V_6 -> V_8 = ! ! ( V_14 -> V_15 & V_29 ) ;
break;
case V_30 :
V_6 -> V_31 = F_2 ( V_14 ) ;
break;
case V_32 :
V_6 -> V_8 = V_14 -> V_33 * 1000 ;
break;
case V_34 :
V_6 -> V_8 = V_14 -> V_35 * 1000 ;
break;
case V_36 :
V_6 -> V_8 = V_14 -> V_37 * 1000 ;
break;
case V_38 :
V_6 -> V_8 = V_14 -> V_39 * 1000 ;
break;
case V_40 :
V_6 -> V_8 = V_14 -> V_41 ;
break;
default:
return - V_12 ;
}
return 0 ;
}
static int T_1 F_5 ( void )
{
int V_42 ;
int V_43 ;
V_44 = F_6 ( L_1 ,
0 , NULL , 0 ) ;
if ( F_7 ( V_44 ) ) {
V_42 = F_8 ( V_44 ) ;
goto V_45;
}
V_42 = F_9 ( & V_44 -> V_46 , & V_47 ) ;
if ( V_42 )
goto V_48;
for ( V_43 = 0 ; V_43 < V_11 ; V_43 ++ ) {
struct V_21 * V_22 = F_10 ( sizeof( * V_22 ) ,
V_49 ) ;
if ( ! V_22 )
break;
sprintf ( V_22 -> V_50 , L_2 , V_43 ) ;
V_22 -> V_51 . V_50 = V_22 -> V_50 ;
V_22 -> V_51 . V_52 = V_53 ;
V_22 -> V_51 . V_54 = F_11 ( V_53 ) ;
V_22 -> V_51 . V_55 = F_3 ;
V_22 -> V_14 = & V_56 [ V_43 ] ;
V_42 = F_9 ( & V_44 -> V_46 , & V_22 -> V_51 ) ;
if ( V_42 ) {
F_12 ( V_22 ) ;
goto V_57;
}
V_58 [ V_43 ] = V_22 ;
}
goto V_59;
V_57:
while ( V_43 -- ) {
if ( ! V_58 [ V_43 ] )
continue;
F_13 ( & V_58 [ V_43 ] -> V_51 ) ;
F_12 ( V_58 [ V_43 ] ) ;
}
F_13 ( & V_47 ) ;
V_48:
F_14 ( V_44 ) ;
V_45:
V_59:
return V_42 ;
}
static void T_2 F_15 ( void )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_60 ; V_43 ++ ) {
if ( ! V_58 [ V_43 ] )
continue;
F_13 ( & V_58 [ V_43 ] -> V_51 ) ;
F_12 ( V_58 [ V_43 ] ) ;
}
F_13 ( & V_47 ) ;
F_14 ( V_44 ) ;
}
