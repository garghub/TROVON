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
struct V_23 * V_24 )
{
int V_25 , V_26 , V_27 ;
V_22 -> V_27 [ V_28 ] = F_4 ( V_29 ) ;
if ( V_24 ) {
if ( V_24 -> V_30 . V_31 || V_24 -> V_32 . V_33 ) {
switch ( V_24 -> V_34 ) {
case 1 :
V_27 = V_35 ;
break;
case 2 :
V_27 = V_36 ;
break;
default:
V_27 = V_37 ;
break;
}
} else {
V_27 = V_38 ;
}
} else {
V_27 = V_36 ;
}
V_22 -> V_27 [ V_19 ] = F_4 ( V_27 ) ;
for ( V_25 = 0 ; V_25 < V_39 ; V_25 ++ ) {
for ( V_26 = 0 ; V_26 < V_40 ; V_26 ++ ) {
V_22 -> V_41 [ V_25 ] [ V_26 ] =
F_4 ( V_42 ) ;
}
}
F_5 ( sizeof( V_43 ) !=
sizeof( V_44 ) * V_39 * V_40 ) ;
memcpy ( V_22 -> V_45 , V_43 ,
sizeof( V_43 ) ) ;
}
static int F_6 ( struct V_46 * V_47 , T_1 V_48 ,
enum V_49 V_50 )
{
struct V_21 V_22 = {
. V_51 = V_50 ,
} ;
struct V_23 * V_24 ;
int V_52 = 0 ;
if ( V_50 != V_19 && V_47 -> V_53 == V_50 )
return 0 ;
switch ( V_50 ) {
case V_54 :
break;
case V_19 :
if ( V_48 == V_55 ) {
F_7 ( V_47 ,
L_1 ) ;
return - V_56 ;
}
F_8 () ;
V_24 = F_9 ( V_47 -> V_57 [ V_48 ] ) ;
if ( F_10 ( V_24 ) ) {
F_7 ( V_47 , L_2 ) ;
F_11 () ;
return - V_56 ;
}
F_3 ( & V_22 , V_24 ) ;
F_11 () ;
break;
case V_20 :
F_3 ( & V_22 , NULL ) ;
break;
default:
F_12 ( 1 , L_3 ,
V_50 ) ;
return - V_56 ;
}
V_52 = F_13 ( V_47 , V_58 , V_59 ,
sizeof( V_22 ) , & V_22 ) ;
if ( ! V_52 )
V_47 -> V_53 = V_50 ;
return V_52 ;
}
int F_14 ( struct V_46 * V_47 , struct V_3 * V_60 ,
bool V_61 )
{
enum V_49 V_50 ;
T_1 V_48 = V_55 ;
struct V_7 * V_8 = NULL ;
struct V_5 V_6 = {
. V_9 = V_60 ,
. V_18 = V_54 ,
. V_14 = V_55 ,
} ;
if ( F_15 ( V_62 , & V_47 -> V_63 ) ||
( V_60 && V_60 -> type == V_11 ) )
return 0 ;
F_16 ( V_47 -> V_64 ,
V_65 ,
F_1 ,
& V_6 ) ;
if ( V_60 && ! V_61 )
V_6 . V_12 ++ ;
switch ( V_6 . V_12 ) {
case 0 :
V_50 = V_20 ;
break;
case 1 :
if ( V_61 ) {
V_50 = V_6 . V_18 ;
V_48 = V_6 . V_14 ;
} else {
if ( F_17 ( ! V_60 ) )
return - V_56 ;
if ( V_60 -> type != V_13 ) {
V_50 = V_54 ;
} else if ( V_60 -> V_16 . V_17 &&
V_60 -> V_16 . V_66 ) {
V_8 = F_2 ( V_60 ) ;
V_48 = V_8 -> V_15 ;
V_50 = V_19 ;
} else {
V_50 = V_20 ;
}
}
break;
default:
V_50 = V_54 ;
}
return F_6 ( V_47 , V_48 , V_50 ) ;
}
