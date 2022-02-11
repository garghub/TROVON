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
static void
F_6 ( struct V_22 * V_23 ,
struct V_5 * V_5 )
{
struct V_24 * V_25 ;
F_7 (pos, &scpi_sensors->thermal_zones) {
struct V_3 * V_4 ;
V_4 = F_8 ( V_25 , struct V_3 , V_26 ) ;
F_9 ( & V_23 -> V_1 , V_4 -> V_27 ) ;
}
}
static int F_10 ( struct V_22 * V_23 )
{
T_3 V_28 , V_29 ;
int V_30 = 0 , V_31 = 0 , V_32 = 0 , V_33 = 0 ;
struct V_6 * V_6 ;
struct V_15 * V_34 , * V_1 = & V_23 -> V_1 ;
struct V_5 * V_5 ;
int V_12 , V_35 ;
V_6 = F_11 () ;
if ( ! V_6 )
return - V_36 ;
V_12 = V_6 -> V_37 ( & V_28 ) ;
if ( V_12 )
return V_12 ;
if ( ! V_28 )
return - V_38 ;
V_5 = F_12 ( V_1 , sizeof( * V_5 ) , V_39 ) ;
if ( ! V_5 )
return - V_40 ;
V_5 -> V_9 = F_13 ( V_1 , V_28 ,
sizeof( * V_5 -> V_9 ) , V_39 ) ;
if ( ! V_5 -> V_9 )
return - V_40 ;
V_5 -> V_41 = F_13 ( V_1 , ( V_28 * 2 ) + 1 ,
sizeof( * V_5 -> V_41 ) , V_39 ) ;
if ( ! V_5 -> V_41 )
return - V_40 ;
V_5 -> V_6 = V_6 ;
for ( V_29 = 0 , V_35 = 0 ; V_29 < V_28 ; V_29 ++ ) {
struct V_7 * V_8 = & V_5 -> V_9 [ V_35 ] ;
V_12 = V_6 -> V_42 ( V_29 , & V_8 -> V_14 ) ;
if ( V_12 )
return V_12 ;
switch ( V_8 -> V_14 . V_43 ) {
case V_44 :
snprintf ( V_8 -> V_45 , sizeof( V_8 -> V_45 ) ,
L_3 , V_30 + 1 ) ;
snprintf ( V_8 -> V_46 , sizeof( V_8 -> V_45 ) ,
L_4 , V_30 + 1 ) ;
V_30 ++ ;
break;
case V_47 :
snprintf ( V_8 -> V_45 , sizeof( V_8 -> V_45 ) ,
L_5 , V_31 ) ;
snprintf ( V_8 -> V_46 , sizeof( V_8 -> V_45 ) ,
L_6 , V_31 ) ;
V_31 ++ ;
break;
case V_48 :
snprintf ( V_8 -> V_45 , sizeof( V_8 -> V_45 ) ,
L_7 , V_32 + 1 ) ;
snprintf ( V_8 -> V_46 , sizeof( V_8 -> V_45 ) ,
L_8 , V_32 + 1 ) ;
V_32 ++ ;
break;
case V_49 :
snprintf ( V_8 -> V_45 , sizeof( V_8 -> V_45 ) ,
L_9 , V_33 + 1 ) ;
snprintf ( V_8 -> V_46 , sizeof( V_8 -> V_45 ) ,
L_10 , V_33 + 1 ) ;
V_33 ++ ;
break;
default:
continue;
}
V_8 -> V_19 . V_17 . V_50 = V_51 ;
V_8 -> V_19 . V_52 = F_2 ;
V_8 -> V_19 . V_17 . V_21 = V_8 -> V_45 ;
V_8 -> V_20 . V_17 . V_50 = V_51 ;
V_8 -> V_20 . V_52 = F_5 ;
V_8 -> V_20 . V_17 . V_21 = V_8 -> V_46 ;
V_5 -> V_41 [ V_35 << 1 ] = & V_8 -> V_19 . V_17 ;
V_5 -> V_41 [ ( V_35 << 1 ) + 1 ] = & V_8 -> V_20 . V_17 ;
F_14 ( V_5 -> V_41 [ V_35 << 1 ] ) ;
F_14 ( V_5 -> V_41 [ ( V_35 << 1 ) + 1 ] ) ;
V_35 ++ ;
}
V_5 -> V_53 . V_41 = V_5 -> V_41 ;
V_5 -> V_54 [ 0 ] = & V_5 -> V_53 ;
F_15 ( V_23 , V_5 ) ;
V_34 = F_16 ( V_1 ,
L_11 , V_5 , V_5 -> V_54 ) ;
if ( F_17 ( V_34 ) )
return F_18 ( V_34 ) ;
F_19 ( & V_5 -> V_55 ) ;
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ ) {
struct V_7 * V_8 = & V_5 -> V_9 [ V_29 ] ;
struct V_3 * V_4 ;
if ( V_8 -> V_14 . V_43 != V_44 )
continue;
V_4 = F_12 ( V_1 , sizeof( * V_4 ) , V_39 ) ;
if ( ! V_4 ) {
V_12 = - V_40 ;
goto V_56;
}
V_4 -> V_10 = V_29 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_27 = F_20 ( V_1 ,
V_8 -> V_14 . V_10 , V_4 , & V_57 ) ;
if ( F_17 ( V_4 -> V_27 ) ) {
F_21 ( V_1 , V_4 ) ;
continue;
}
F_22 ( & V_4 -> V_26 , & V_5 -> V_55 ) ;
}
return 0 ;
V_56:
F_6 ( V_23 , V_5 ) ;
return V_12 ;
}
static int F_23 ( struct V_22 * V_23 )
{
struct V_5 * V_5 = F_24 ( V_23 ) ;
F_6 ( V_23 , V_5 ) ;
return 0 ;
}
