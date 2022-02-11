static void F_1 ( void * V_1 , T_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_1 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( V_4 == V_6 -> V_9 || ! V_8 -> V_10 ||
V_4 -> type == V_11 )
return;
V_6 -> V_12 ++ ;
if ( V_4 -> type == V_13 ) {
V_6 -> V_14 = V_8 -> V_15 ;
if ( V_4 -> V_16 . V_17 )
V_6 -> V_18 = V_19 ;
else
V_6 -> V_18 = V_20 ;
}
}
static void F_3 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
struct V_25 * V_26 )
{
int V_27 , V_28 , V_29 ;
V_24 -> V_29 [ V_30 ] = F_4 ( V_31 ) ;
if ( V_26 ) {
if ( V_26 -> V_32 . V_33 || V_26 -> V_34 . V_35 ) {
switch ( V_26 -> V_36 ) {
case 1 :
V_29 = V_37 ;
break;
case 2 :
V_29 = V_38 ;
break;
default:
V_29 = V_39 ;
break;
}
} else {
V_29 = V_40 ;
}
} else {
V_29 = V_38 ;
}
V_24 -> V_29 [ V_19 ] = F_4 ( V_29 ) ;
for ( V_27 = 0 ; V_27 < V_41 ; V_27 ++ ) {
for ( V_28 = 0 ; V_28 < V_42 ; V_28 ++ ) {
V_24 -> V_43 [ V_27 ] [ V_28 ] =
F_4 ( V_44 ) ;
}
}
if ( V_26 || F_5 ( V_22 -> V_45 -> V_46 ) < 13 ) {
F_6 ( sizeof( V_47 ) !=
sizeof( V_48 ) * V_41 *
V_42 ) ;
memcpy ( V_24 -> V_49 , V_47 ,
sizeof( V_47 ) ) ;
} else {
F_6 ( sizeof( V_50 ) !=
sizeof( V_48 ) * V_41 *
V_42 ) ;
memcpy ( V_24 -> V_49 , V_50 ,
sizeof( V_50 ) ) ;
}
}
static int F_7 ( struct V_21 * V_22 , T_1 V_51 ,
enum V_52 V_53 )
{
struct V_23 V_24 = {
. V_54 = F_4 ( V_19 ) ,
} ;
struct V_25 * V_26 ;
int V_55 = 0 ;
if ( F_5 ( V_22 -> V_45 -> V_46 ) < 13 )
V_24 . V_54 = F_4 ( V_53 ) ;
if ( V_22 -> V_56 -> V_57 )
V_24 . V_54 |= F_4 ( V_58 ) ;
if ( V_53 != V_19 && V_22 -> V_59 == V_53 )
return 0 ;
switch ( V_53 ) {
case V_60 :
if ( F_5 ( V_22 -> V_45 -> V_46 ) >= 13 )
F_3 ( V_22 , & V_24 , NULL ) ;
break;
case V_19 :
if ( V_51 == V_61 ) {
F_8 ( V_22 ,
L_1 ) ;
return - V_62 ;
}
F_9 () ;
V_26 = F_10 ( V_22 -> V_63 [ V_51 ] ) ;
if ( F_11 ( V_26 ) ) {
F_8 ( V_22 , L_2 ) ;
F_12 () ;
return - V_62 ;
}
F_3 ( V_22 , & V_24 , V_26 ) ;
F_12 () ;
break;
case V_20 :
F_3 ( V_22 , & V_24 , NULL ) ;
break;
default:
F_13 ( 1 , L_3 ,
V_53 ) ;
return - V_62 ;
}
V_55 = F_14 ( V_22 , V_64 , V_65 ,
sizeof( V_24 ) , & V_24 ) ;
if ( ! V_55 )
V_22 -> V_59 = V_53 ;
return V_55 ;
}
int F_15 ( struct V_21 * V_22 , struct V_3 * V_66 ,
bool V_67 )
{
enum V_52 V_53 ;
T_1 V_51 = V_61 ;
struct V_7 * V_8 = NULL ;
struct V_5 V_6 = {
. V_9 = V_66 ,
. V_18 = V_60 ,
. V_14 = V_61 ,
} ;
if ( F_16 ( V_68 , & V_22 -> V_69 ) ||
( V_66 && V_66 -> type == V_11 ) )
return 0 ;
F_17 ( V_22 -> V_70 ,
V_71 ,
F_1 ,
& V_6 ) ;
if ( V_66 && ! V_67 )
V_6 . V_12 ++ ;
switch ( V_6 . V_12 ) {
case 0 :
V_53 = V_20 ;
break;
case 1 :
if ( V_67 ) {
V_53 = V_6 . V_18 ;
V_51 = V_6 . V_14 ;
} else {
if ( F_18 ( ! V_66 ) )
return - V_62 ;
if ( V_66 -> type != V_13 ) {
V_53 = V_60 ;
} else if ( V_66 -> V_16 . V_17 &&
V_66 -> V_16 . V_72 ) {
V_8 = F_2 ( V_66 ) ;
V_51 = V_8 -> V_15 ;
V_53 = V_19 ;
} else {
V_53 = V_20 ;
}
}
break;
default:
V_53 = V_60 ;
}
return F_7 ( V_22 , V_51 , V_53 ) ;
}
