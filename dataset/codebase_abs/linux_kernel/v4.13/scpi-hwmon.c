static void F_1 ( T_1 * V_1 , struct V_2 * V_3 )
{
if ( V_4 [ V_3 -> V_5 . V_6 ] != V_3 -> V_7 ) {
* V_1 *= V_4 [ V_3 -> V_5 . V_6 ] ;
F_2 ( * V_1 , V_3 -> V_7 ) ;
}
}
static int F_3 ( void * V_8 , int * V_9 )
{
struct V_10 * V_11 = V_8 ;
struct V_12 * V_12 = V_11 -> V_12 ;
struct V_13 * V_13 = V_12 -> V_13 ;
struct V_2 * V_3 = & V_12 -> V_14 [ V_11 -> V_15 ] ;
T_1 V_1 ;
int V_16 ;
V_16 = V_13 -> V_17 ( V_3 -> V_5 . V_15 , & V_1 ) ;
if ( V_16 )
return V_16 ;
F_1 ( & V_1 , V_3 ) ;
* V_9 = V_1 ;
return 0 ;
}
static T_2
F_4 ( struct V_18 * V_8 , struct V_19 * V_20 , char * V_21 )
{
struct V_12 * V_12 = F_5 ( V_8 ) ;
struct V_13 * V_13 = V_12 -> V_13 ;
struct V_2 * V_3 ;
T_1 V_1 ;
int V_16 ;
V_3 = F_6 ( V_20 , struct V_2 , V_22 ) ;
V_16 = V_13 -> V_17 ( V_3 -> V_5 . V_15 , & V_1 ) ;
if ( V_16 )
return V_16 ;
F_1 ( & V_1 , V_3 ) ;
return sprintf ( V_21 , L_1 , V_1 ) ;
}
static T_2
F_7 ( struct V_18 * V_8 , struct V_19 * V_20 , char * V_21 )
{
struct V_2 * V_3 ;
V_3 = F_6 ( V_20 , struct V_2 , V_23 ) ;
return sprintf ( V_21 , L_2 , V_3 -> V_5 . V_24 ) ;
}
static int F_8 ( struct V_25 * V_26 )
{
T_3 V_27 , V_28 ;
const T_4 * V_7 ;
int V_29 = 0 , V_30 = 0 , V_31 = 0 , V_32 = 0 ;
int V_33 = 0 ;
struct V_13 * V_13 ;
struct V_18 * V_34 , * V_8 = & V_26 -> V_8 ;
struct V_12 * V_12 ;
const struct V_35 * V_36 ;
int V_37 , V_16 ;
V_13 = F_9 () ;
if ( ! V_13 )
return - V_38 ;
V_16 = V_13 -> V_39 ( & V_27 ) ;
if ( V_16 )
return V_16 ;
if ( ! V_27 )
return - V_40 ;
V_12 = F_10 ( V_8 , sizeof( * V_12 ) , V_41 ) ;
if ( ! V_12 )
return - V_42 ;
V_12 -> V_14 = F_11 ( V_8 , V_27 ,
sizeof( * V_12 -> V_14 ) , V_41 ) ;
if ( ! V_12 -> V_14 )
return - V_42 ;
V_12 -> V_43 = F_11 ( V_8 , ( V_27 * 2 ) + 1 ,
sizeof( * V_12 -> V_43 ) , V_41 ) ;
if ( ! V_12 -> V_43 )
return - V_42 ;
V_12 -> V_13 = V_13 ;
V_36 = F_12 ( V_44 , & V_26 -> V_8 ) ;
if ( ! V_36 ) {
F_13 ( & V_26 -> V_8 , L_3 ) ;
return - V_40 ;
}
V_7 = V_36 -> V_14 ;
for ( V_28 = 0 , V_37 = 0 ; V_28 < V_27 ; V_28 ++ ) {
struct V_2 * V_3 = & V_12 -> V_14 [ V_37 ] ;
V_16 = V_13 -> V_45 ( V_28 , & V_3 -> V_5 ) ;
if ( V_16 )
return V_16 ;
switch ( V_3 -> V_5 . V_6 ) {
case V_46 :
snprintf ( V_3 -> V_47 , sizeof( V_3 -> V_47 ) ,
L_4 , V_29 + 1 ) ;
snprintf ( V_3 -> V_48 , sizeof( V_3 -> V_47 ) ,
L_5 , V_29 + 1 ) ;
V_29 ++ ;
break;
case V_49 :
snprintf ( V_3 -> V_47 , sizeof( V_3 -> V_47 ) ,
L_6 , V_30 ) ;
snprintf ( V_3 -> V_48 , sizeof( V_3 -> V_47 ) ,
L_7 , V_30 ) ;
V_30 ++ ;
break;
case V_50 :
snprintf ( V_3 -> V_47 , sizeof( V_3 -> V_47 ) ,
L_8 , V_31 + 1 ) ;
snprintf ( V_3 -> V_48 , sizeof( V_3 -> V_47 ) ,
L_9 , V_31 + 1 ) ;
V_31 ++ ;
break;
case V_51 :
snprintf ( V_3 -> V_47 , sizeof( V_3 -> V_47 ) ,
L_10 , V_32 + 1 ) ;
snprintf ( V_3 -> V_48 , sizeof( V_3 -> V_47 ) ,
L_11 , V_32 + 1 ) ;
V_32 ++ ;
break;
case V_52 :
snprintf ( V_3 -> V_47 , sizeof( V_3 -> V_47 ) ,
L_12 , V_33 + 1 ) ;
snprintf ( V_3 -> V_48 , sizeof( V_3 -> V_47 ) ,
L_13 , V_33 + 1 ) ;
V_33 ++ ;
break;
default:
continue;
}
V_3 -> V_7 = V_7 [ V_3 -> V_5 . V_6 ] ;
V_3 -> V_22 . V_20 . V_53 = V_54 ;
V_3 -> V_22 . V_55 = F_4 ;
V_3 -> V_22 . V_20 . V_24 = V_3 -> V_47 ;
V_3 -> V_23 . V_20 . V_53 = V_54 ;
V_3 -> V_23 . V_55 = F_7 ;
V_3 -> V_23 . V_20 . V_24 = V_3 -> V_48 ;
V_12 -> V_43 [ V_37 << 1 ] = & V_3 -> V_22 . V_20 ;
V_12 -> V_43 [ ( V_37 << 1 ) + 1 ] = & V_3 -> V_23 . V_20 ;
F_14 ( V_12 -> V_43 [ V_37 << 1 ] ) ;
F_14 ( V_12 -> V_43 [ ( V_37 << 1 ) + 1 ] ) ;
V_37 ++ ;
}
V_12 -> V_56 . V_43 = V_12 -> V_43 ;
V_12 -> V_57 [ 0 ] = & V_12 -> V_56 ;
F_15 ( V_26 , V_12 ) ;
V_34 = F_16 ( V_8 ,
L_14 , V_12 , V_12 -> V_57 ) ;
if ( F_17 ( V_34 ) )
return F_18 ( V_34 ) ;
F_19 ( & V_12 -> V_58 ) ;
for ( V_28 = 0 ; V_28 < V_27 ; V_28 ++ ) {
struct V_2 * V_3 = & V_12 -> V_14 [ V_28 ] ;
struct V_59 * V_60 ;
struct V_10 * V_11 ;
if ( V_3 -> V_5 . V_6 != V_46 )
continue;
V_11 = F_10 ( V_8 , sizeof( * V_11 ) , V_41 ) ;
if ( ! V_11 )
return - V_42 ;
V_11 -> V_15 = V_28 ;
V_11 -> V_12 = V_12 ;
V_60 = F_20 ( V_8 ,
V_3 -> V_5 . V_15 ,
V_11 ,
& V_61 ) ;
if ( F_17 ( V_60 ) ) {
F_21 ( V_8 , V_11 ) ;
continue;
}
}
return 0 ;
}
