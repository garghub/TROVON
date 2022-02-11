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
if ( V_26 ) {
F_5 ( sizeof( V_45 ) !=
sizeof( V_46 ) * V_41 *
V_42 ) ;
memcpy ( V_24 -> V_47 , V_45 ,
sizeof( V_45 ) ) ;
} else {
F_5 ( sizeof( V_48 ) !=
sizeof( V_46 ) * V_41 *
V_42 ) ;
memcpy ( V_24 -> V_47 , V_48 ,
sizeof( V_48 ) ) ;
}
}
static int F_6 ( struct V_21 * V_22 , T_1 V_49 ,
enum V_50 V_51 )
{
struct V_23 V_24 = {
. V_52 = F_4 ( V_19 ) ,
} ;
struct V_25 * V_26 ;
int V_53 = 0 ;
if ( V_22 -> V_54 -> V_55 )
V_24 . V_52 |= F_4 ( V_56 ) ;
if ( V_51 != V_19 && V_22 -> V_57 == V_51 )
return 0 ;
switch ( V_51 ) {
case V_58 :
F_3 ( V_22 , & V_24 , NULL ) ;
break;
case V_19 :
if ( V_49 == V_59 ) {
F_7 ( V_22 ,
L_1 ) ;
return - V_60 ;
}
F_8 () ;
V_26 = F_9 ( V_22 -> V_61 [ V_49 ] ) ;
if ( F_10 ( V_26 ) ) {
F_7 ( V_22 , L_2 ) ;
F_11 () ;
return - V_60 ;
}
F_3 ( V_22 , & V_24 , V_26 ) ;
F_11 () ;
break;
case V_20 :
F_3 ( V_22 , & V_24 , NULL ) ;
break;
default:
F_12 ( 1 , L_3 ,
V_51 ) ;
return - V_60 ;
}
V_53 = F_13 ( V_22 , V_62 , V_63 ,
sizeof( V_24 ) , & V_24 ) ;
if ( ! V_53 )
V_22 -> V_57 = V_51 ;
return V_53 ;
}
int F_14 ( struct V_21 * V_22 , struct V_3 * V_64 ,
bool V_65 )
{
enum V_50 V_51 ;
T_1 V_49 = V_59 ;
struct V_7 * V_8 = NULL ;
struct V_5 V_6 = {
. V_9 = V_64 ,
. V_18 = V_58 ,
. V_14 = V_59 ,
} ;
if ( F_15 ( V_66 , & V_22 -> V_67 ) ||
( V_64 && V_64 -> type == V_11 ) )
return 0 ;
F_16 ( V_22 -> V_68 ,
V_69 ,
F_1 ,
& V_6 ) ;
if ( V_64 && ! V_65 )
V_6 . V_12 ++ ;
switch ( V_6 . V_12 ) {
case 0 :
V_51 = V_20 ;
break;
case 1 :
if ( V_65 ) {
V_51 = V_6 . V_18 ;
V_49 = V_6 . V_14 ;
} else {
if ( F_17 ( ! V_64 ) )
return - V_60 ;
if ( V_64 -> type != V_13 ) {
V_51 = V_58 ;
} else if ( V_64 -> V_16 . V_17 &&
V_64 -> V_16 . V_70 ) {
V_8 = F_2 ( V_64 ) ;
V_49 = V_8 -> V_15 ;
V_51 = V_19 ;
} else {
V_51 = V_20 ;
}
}
break;
default:
V_51 = V_58 ;
}
return F_6 ( V_22 , V_49 , V_51 ) ;
}
