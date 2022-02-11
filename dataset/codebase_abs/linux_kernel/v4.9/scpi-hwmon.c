static int F_1 ( void * V_1 , int * V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_5 = V_4 -> V_5 ;
struct V_6 * V_6 = V_5 -> V_6 ;
struct V_7 * V_8 = & V_5 -> V_9 [ V_4 -> V_10 ] ;
T_1 V_11 ;
int V_12 ;
V_12 = V_6 -> V_13 ( V_8 -> V_14 . V_10 , & V_11 ) ;
if ( V_12 )
return V_12 ;
* V_2 = V_11 ;
return 0 ;
}
static T_2
F_2 ( struct V_15 * V_1 , struct V_16 * V_17 , char * V_18 )
{
struct V_5 * V_5 = F_3 ( V_1 ) ;
struct V_6 * V_6 = V_5 -> V_6 ;
struct V_7 * V_8 ;
T_1 V_11 ;
int V_12 ;
V_8 = F_4 ( V_17 , struct V_7 , V_19 ) ;
V_12 = V_6 -> V_13 ( V_8 -> V_14 . V_10 , & V_11 ) ;
if ( V_12 )
return V_12 ;
return sprintf ( V_18 , L_1 , V_11 ) ;
}
static T_2
F_5 ( struct V_15 * V_1 , struct V_16 * V_17 , char * V_18 )
{
struct V_7 * V_8 ;
V_8 = F_4 ( V_17 , struct V_7 , V_20 ) ;
return sprintf ( V_18 , L_2 , V_8 -> V_14 . V_21 ) ;
}
static int F_6 ( struct V_22 * V_23 )
{
T_3 V_24 , V_25 ;
int V_26 = 0 , V_27 = 0 , V_28 = 0 , V_29 = 0 ;
int V_30 = 0 ;
struct V_6 * V_6 ;
struct V_15 * V_31 , * V_1 = & V_23 -> V_1 ;
struct V_5 * V_5 ;
int V_32 , V_12 ;
V_6 = F_7 () ;
if ( ! V_6 )
return - V_33 ;
V_12 = V_6 -> V_34 ( & V_24 ) ;
if ( V_12 )
return V_12 ;
if ( ! V_24 )
return - V_35 ;
V_5 = F_8 ( V_1 , sizeof( * V_5 ) , V_36 ) ;
if ( ! V_5 )
return - V_37 ;
V_5 -> V_9 = F_9 ( V_1 , V_24 ,
sizeof( * V_5 -> V_9 ) , V_36 ) ;
if ( ! V_5 -> V_9 )
return - V_37 ;
V_5 -> V_38 = F_9 ( V_1 , ( V_24 * 2 ) + 1 ,
sizeof( * V_5 -> V_38 ) , V_36 ) ;
if ( ! V_5 -> V_38 )
return - V_37 ;
V_5 -> V_6 = V_6 ;
for ( V_25 = 0 , V_32 = 0 ; V_25 < V_24 ; V_25 ++ ) {
struct V_7 * V_8 = & V_5 -> V_9 [ V_32 ] ;
V_12 = V_6 -> V_39 ( V_25 , & V_8 -> V_14 ) ;
if ( V_12 )
return V_12 ;
switch ( V_8 -> V_14 . V_40 ) {
case V_41 :
snprintf ( V_8 -> V_42 , sizeof( V_8 -> V_42 ) ,
L_3 , V_26 + 1 ) ;
snprintf ( V_8 -> V_43 , sizeof( V_8 -> V_42 ) ,
L_4 , V_26 + 1 ) ;
V_26 ++ ;
break;
case V_44 :
snprintf ( V_8 -> V_42 , sizeof( V_8 -> V_42 ) ,
L_5 , V_27 ) ;
snprintf ( V_8 -> V_43 , sizeof( V_8 -> V_42 ) ,
L_6 , V_27 ) ;
V_27 ++ ;
break;
case V_45 :
snprintf ( V_8 -> V_42 , sizeof( V_8 -> V_42 ) ,
L_7 , V_28 + 1 ) ;
snprintf ( V_8 -> V_43 , sizeof( V_8 -> V_42 ) ,
L_8 , V_28 + 1 ) ;
V_28 ++ ;
break;
case V_46 :
snprintf ( V_8 -> V_42 , sizeof( V_8 -> V_42 ) ,
L_9 , V_29 + 1 ) ;
snprintf ( V_8 -> V_43 , sizeof( V_8 -> V_42 ) ,
L_10 , V_29 + 1 ) ;
V_29 ++ ;
break;
case V_47 :
snprintf ( V_8 -> V_42 , sizeof( V_8 -> V_42 ) ,
L_11 , V_30 + 1 ) ;
snprintf ( V_8 -> V_43 , sizeof( V_8 -> V_42 ) ,
L_12 , V_30 + 1 ) ;
V_30 ++ ;
break;
default:
continue;
}
V_8 -> V_19 . V_17 . V_48 = V_49 ;
V_8 -> V_19 . V_50 = F_2 ;
V_8 -> V_19 . V_17 . V_21 = V_8 -> V_42 ;
V_8 -> V_20 . V_17 . V_48 = V_49 ;
V_8 -> V_20 . V_50 = F_5 ;
V_8 -> V_20 . V_17 . V_21 = V_8 -> V_43 ;
V_5 -> V_38 [ V_32 << 1 ] = & V_8 -> V_19 . V_17 ;
V_5 -> V_38 [ ( V_32 << 1 ) + 1 ] = & V_8 -> V_20 . V_17 ;
F_10 ( V_5 -> V_38 [ V_32 << 1 ] ) ;
F_10 ( V_5 -> V_38 [ ( V_32 << 1 ) + 1 ] ) ;
V_32 ++ ;
}
V_5 -> V_51 . V_38 = V_5 -> V_38 ;
V_5 -> V_52 [ 0 ] = & V_5 -> V_51 ;
F_11 ( V_23 , V_5 ) ;
V_31 = F_12 ( V_1 ,
L_13 , V_5 , V_5 -> V_52 ) ;
if ( F_13 ( V_31 ) )
return F_14 ( V_31 ) ;
F_15 ( & V_5 -> V_53 ) ;
for ( V_25 = 0 ; V_25 < V_24 ; V_25 ++ ) {
struct V_7 * V_8 = & V_5 -> V_9 [ V_25 ] ;
struct V_54 * V_55 ;
struct V_3 * V_4 ;
if ( V_8 -> V_14 . V_40 != V_41 )
continue;
V_4 = F_8 ( V_1 , sizeof( * V_4 ) , V_36 ) ;
if ( ! V_4 )
return - V_37 ;
V_4 -> V_10 = V_25 ;
V_4 -> V_5 = V_5 ;
V_55 = F_16 ( V_1 ,
V_8 -> V_14 . V_10 ,
V_4 ,
& V_56 ) ;
if ( F_13 ( V_55 ) ) {
F_17 ( V_1 , V_4 ) ;
continue;
}
}
return 0 ;
}
