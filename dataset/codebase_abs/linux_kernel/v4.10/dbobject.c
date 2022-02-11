void
F_1 ( T_1 V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
if ( ( V_1 & V_6 ) == V_7 ) {
return;
}
if ( V_3 -> V_8 ) {
F_2 ( L_1 ) ;
return;
}
V_5 = V_3 -> V_5 ;
if ( ! V_5 ) {
return;
}
F_2 ( L_2 ) ;
F_3 ( V_3 ) ;
F_2 ( L_2 ) ;
F_4 ( V_3 ) ;
F_2 ( L_2 ) ;
}
void F_5 ( union V_9 * V_10 )
{
T_2 V_11 ;
if ( ! V_10 ) {
F_2 ( L_3 ) ;
return;
}
if ( F_6 ( V_10 ) != V_12 ) {
F_2 ( L_4 , V_10 ,
F_7 ( V_10 ) ) ;
return;
}
F_2 ( L_5 , F_8 ( V_10 ) ) ;
switch ( V_10 -> V_13 . type ) {
case V_14 :
F_2 ( L_6 ,
F_9 ( V_10 -> integer . V_15 ) ) ;
break;
case V_16 :
F_2 ( L_7 ,
V_10 -> string . V_17 ,
V_10 -> string . V_18 ) ;
if ( V_10 -> string . V_17 > 60 ) {
F_2 ( L_8 ) ;
} else {
F_2 ( L_9 ) ;
}
break;
case V_19 :
F_2 ( L_10 , V_10 -> V_20 . V_17 ) ;
for ( V_11 = 0 ; ( V_11 < 8 ) && ( V_11 < V_10 -> V_20 . V_17 ) ; V_11 ++ ) {
F_2 ( L_11 , V_10 -> V_20 . V_18 [ V_11 ] ) ;
}
break;
default:
F_2 ( L_12 , V_10 ) ;
break;
}
}
static void F_10 ( struct V_21 * V_22 )
{
F_2 ( L_13 ,
F_11 ( V_22 ) ) ;
if ( V_22 -> V_23 & V_24 ) {
F_2 ( L_14 ) ;
}
if ( V_22 -> V_23 & V_25 ) {
F_2 ( L_15 ) ;
}
switch ( V_22 -> type ) {
case V_26 :
F_2 ( L_16 ) ;
break;
case V_27 :
F_2 ( L_17 ) ;
break;
default:
F_5 ( F_12
( V_22 ) ) ;
break;
}
}
void
F_13 ( union V_9 * V_10 ,
struct V_2 * V_3 )
{
T_3 type ;
F_2 ( L_18 , V_10 ) ;
if ( ! V_10 ) {
F_2 ( L_19 ) ;
return;
}
switch ( F_6 ( V_10 ) ) {
case V_28 :
F_2 ( L_20 ) ;
break;
case V_29 :
F_10 ( (struct V_21 * ) V_10 ) ;
break;
case V_12 :
type = V_10 -> V_13 . type ;
if ( type > V_30 ) {
F_2 ( L_21 , ( T_2 ) type ) ;
return;
}
switch ( V_10 -> V_13 . type ) {
case V_31 :
F_2 ( L_22 ,
F_14 ( V_10 ) ) ;
switch ( V_10 -> V_32 . V_33 ) {
case V_34 :
F_2 ( L_23 ,
V_10 -> V_32 . V_15 ) ;
if ( V_3 ) {
V_10 = V_3 -> V_35
[ V_10 -> V_32 . V_15 ] . V_36 ;
F_2 ( L_24 , V_10 ) ;
F_5
( V_10 ) ;
}
break;
case V_37 :
F_2 ( L_23 ,
V_10 -> V_32 . V_15 ) ;
if ( V_3 ) {
V_10 = V_3 -> V_38
[ V_10 -> V_32 . V_15 ] . V_36 ;
F_2 ( L_24 , V_10 ) ;
F_5
( V_10 ) ;
}
break;
case V_39 :
switch ( V_10 -> V_32 . V_40 ) {
case V_41 :
F_2 ( L_24 ,
V_10 -> V_32 .
V_36 ) ;
F_5
( V_10 -> V_32 . V_36 ) ;
break;
case V_42 :
F_2 ( L_24 ,
V_10 -> V_32 .
V_43 ) ;
if ( ! V_10 -> V_32 . V_43 ) {
F_2
( L_25 ) ;
} else {
F_5 ( *
( V_10 ->
V_32 .
V_43 ) ) ;
}
break;
default:
F_2
( L_26 ) ;
break;
}
break;
case V_44 :
if ( ! V_10 -> V_32 . V_36 ) {
F_2
( L_27 ) ;
break;
}
switch ( F_6
( V_10 -> V_32 . V_36 ) ) {
case V_29 :
F_10 ( V_10 -> V_32 .
V_36 ) ;
break;
case V_12 :
F_5
( V_10 -> V_32 . V_36 ) ;
break;
default:
break;
}
break;
case V_45 :
F_10 ( V_10 -> V_32 . V_22 ) ;
break;
case V_46 :
case V_47 :
F_2 ( L_2 ) ;
break;
default:
F_2 ( L_28 ,
V_10 -> V_32 . V_33 ) ;
break;
}
break;
default:
F_2 ( L_29 ) ;
F_5 ( V_10 ) ;
break;
}
break;
default:
F_2 ( L_30 ,
F_7 ( V_10 ) ) ;
break;
}
F_2 ( L_2 ) ;
}
void F_3 ( struct V_2 * V_3 )
{
T_2 V_11 ;
union V_9 * V_10 ;
struct V_21 * V_22 ;
T_3 V_48 = FALSE ;
V_10 = V_3 -> V_49 ;
V_22 = V_3 -> V_50 ;
if ( ! V_22 ) {
F_2
( L_31 ) ;
return;
}
if ( V_22 -> type != V_51 ) {
F_2 ( L_1 ) ;
return;
}
for ( V_11 = 0 ; V_11 < V_52 ; V_11 ++ ) {
V_10 = V_3 -> V_35 [ V_11 ] . V_36 ;
if ( V_10 ) {
V_48 = TRUE ;
break;
}
}
if ( V_48 ) {
F_2
( L_32 ,
F_11 ( V_22 ) ) ;
for ( V_11 = 0 ; V_11 < V_52 ; V_11 ++ ) {
V_10 = V_3 -> V_35 [ V_11 ] . V_36 ;
if ( V_10 ) {
F_2 ( L_33 , V_11 ) ;
F_13 ( V_10 ,
V_3 ) ;
}
}
} else {
F_2
( L_34 ,
F_11 ( V_22 ) ) ;
}
}
void F_4 ( struct V_2 * V_3 )
{
T_2 V_11 ;
union V_9 * V_10 ;
struct V_21 * V_22 ;
T_3 V_53 = FALSE ;
V_22 = V_3 -> V_50 ;
V_10 = V_3 -> V_49 ;
if ( ! V_22 ) {
F_2
( L_31 ) ;
return;
}
if ( V_22 -> type != V_51 ) {
F_2 ( L_1 ) ;
return;
}
for ( V_11 = 0 ; V_11 < V_54 ; V_11 ++ ) {
V_10 = V_3 -> V_38 [ V_11 ] . V_36 ;
if ( V_10 ) {
V_53 = TRUE ;
break;
}
}
if ( V_53 ) {
F_2 ( L_35
L_36 ,
F_11 ( V_22 ) ,
V_10 -> V_55 . V_56 ) ;
for ( V_11 = 0 ; V_11 < V_54 ; V_11 ++ ) {
V_10 = V_3 -> V_38 [ V_11 ] . V_36 ;
if ( V_10 ) {
F_2 ( L_37 , V_11 ) ;
F_13 ( V_10 ,
V_3 ) ;
}
}
} else {
F_2
( L_38 ,
F_11 ( V_22 ) ) ;
}
}
