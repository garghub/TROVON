T_1 F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> type ) {
case V_3 :
case V_4 :
case V_5 :
return ( TRUE ) ;
default:
return ( FALSE ) ;
}
}
T_2
F_2 ( struct V_1 * V_2 ,
T_3 V_6 )
{
union V_7 * V_8 ;
union V_7 * V_9 = NULL ;
union V_10 * V_11 ;
T_2 V_12 = V_13 ;
F_3 ( V_14 ) ;
F_4 ( ( V_15 ,
L_1 ,
F_5 ( V_2 ) , V_2 , V_6 ,
F_6 ( V_6 ) ) ) ;
V_8 = F_7 ( V_2 ) ;
if ( V_8 ) {
switch ( V_2 -> type ) {
case V_3 :
case V_5 :
case V_4 :
if ( V_6 <= V_16 ) {
V_9 =
V_8 -> V_17 . V_18 ;
} else {
V_9 =
V_8 -> V_17 . V_19 ;
}
break;
default:
return ( V_20 ) ;
}
}
if ( ( V_21 . V_22 &&
( V_6 <= V_16 ) ) ||
( V_23 . V_22 &&
( V_6 > V_16 ) ) || V_9 ) {
V_11 = F_8 () ;
if ( ! V_11 ) {
return ( V_24 ) ;
}
if ( ! V_9 ) {
F_4 ( ( V_15 ,
L_2
L_3 ,
F_5 ( V_2 ) ,
V_6 , V_2 ) ) ;
}
V_11 -> V_25 . V_26 =
V_27 ;
V_11 -> V_28 . V_2 = V_2 ;
V_11 -> V_28 . V_29 = ( V_30 ) V_6 ;
V_11 -> V_28 . V_9 = V_9 ;
V_12 =
F_9 ( V_31 , V_32 ,
V_11 ) ;
if ( F_10 ( V_12 ) ) {
F_11 ( V_11 ) ;
}
} else {
F_4 ( ( V_15 ,
L_4 ,
F_5 ( V_2 ) , V_6 ,
V_2 ) ) ;
}
return ( V_12 ) ;
}
static void T_4 V_32 ( void * V_33 )
{
union V_10 * V_11 =
(union V_10 * ) V_33 ;
T_5 V_34 = NULL ;
void * V_35 = NULL ;
union V_7 * V_9 ;
F_12 () ;
if ( V_11 -> V_28 . V_29 <= V_16 ) {
if ( V_21 . V_22 ) {
V_34 = V_21 . V_22 ;
V_35 = V_21 . V_33 ;
}
} else {
if ( V_23 . V_22 ) {
V_34 = V_23 . V_22 ;
V_35 = V_23 . V_33 ;
}
}
if ( V_34 ) {
V_34 ( V_11 -> V_28 . V_2 ,
V_11 -> V_28 . V_29 , V_35 ) ;
}
V_9 = V_11 -> V_28 . V_9 ;
if ( V_9 ) {
struct V_36 * V_37 ;
V_37 = & V_9 -> V_28 ;
while ( V_37 ) {
V_37 -> V_22 ( V_11 -> V_28 . V_2 ,
V_11 -> V_28 . V_29 ,
V_37 -> V_33 ) ;
V_37 = V_37 -> V_38 ;
}
}
F_11 ( V_11 ) ;
}
void F_13 ( void )
{
T_3 V_39 ;
T_2 V_12 ;
F_14 ( V_40 ) ;
if ( V_41 ) {
for ( V_39 = 0 ; V_39 < V_42 ; V_39 ++ ) {
V_12 = F_15 ( V_39 , 0 ) ;
if ( F_10 ( V_12 ) ) {
F_16 ( ( V_43 ,
L_5 ,
( T_3 ) V_39 ) ) ;
}
}
V_12 = F_17 ( V_44 , NULL ) ;
V_12 = F_18 () ;
if ( F_10 ( V_12 ) ) {
F_16 ( ( V_43 , L_6 ) ) ;
}
V_12 = F_19 () ;
if ( F_10 ( V_12 ) ) {
F_16 ( ( V_43 ,
L_7 ) ) ;
}
}
V_12 = F_17 ( V_45 , NULL ) ;
if ( V_46 == V_47 ) {
V_12 = F_20 () ;
if ( F_10 ( V_12 ) ) {
F_21 ( ( V_43 , L_8 ) ) ;
}
}
V_48 ;
}
