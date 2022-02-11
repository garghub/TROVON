T_1 F_1 ( char * V_1 )
{
if ( ! ( F_2 ( V_1 ,
V_2 ) ) ||
! ( F_2 ( V_1 , V_3 ) ) ) {
return ( TRUE ) ;
}
return ( FALSE ) ;
}
T_1 F_3 ( struct V_4 * V_5 )
{
if ( F_4 ( V_5 -> V_6 , V_7 ) ||
F_4 ( V_5 -> V_6 , V_8 ) ||
F_4 ( V_5 -> V_6 , V_9 ) ) {
return ( TRUE ) ;
}
return ( FALSE ) ;
}
T_2 F_5 ( T_2 V_10 )
{
union {
T_2 V_10 ;
T_1 V_11 [ 4 ] ;
} V_12 ;
union {
T_2 V_10 ;
T_1 V_11 [ 4 ] ;
} V_13 ;
F_6 () ;
V_13 . V_10 = V_10 ;
V_12 . V_11 [ 0 ] = V_13 . V_11 [ 3 ] ;
V_12 . V_11 [ 1 ] = V_13 . V_11 [ 2 ] ;
V_12 . V_11 [ 2 ] = V_13 . V_11 [ 1 ] ;
V_12 . V_11 [ 3 ] = V_13 . V_11 [ 0 ] ;
return ( V_12 . V_10 ) ;
}
void F_7 ( T_1 V_14 )
{
if ( V_14 < 2 ) {
V_15 = 32 ;
V_16 = 8 ;
V_17 = 4 ;
} else {
V_15 = 64 ;
V_16 = 16 ;
V_17 = 8 ;
}
}
T_3
F_8 ( union V_18 * V_19 ,
T_4 V_20 ,
union V_21 * * V_22 )
{
union V_21 * V_23 ;
F_6 () ;
if ( ! V_19 ) {
return ( V_24 ) ;
}
V_23 = F_9 ( V_19 , V_20 ) ;
if ( ! V_23 ) {
return ( V_25 ) ;
}
F_10 ( V_22 , V_23 ) ;
return ( V_24 ) ;
}
T_3
F_11 ( union V_18 * V_26 ,
void * V_27 ,
T_5 V_28 , void * V_29 )
{
T_3 V_30 = V_24 ;
union V_21 * V_22 = NULL ;
union V_21 * V_23 ;
T_2 V_31 ;
union V_18 * V_32 ;
F_12 ( V_33 ) ;
V_23 = F_13 ( V_26 , V_27 , 0 ) ;
if ( ! V_23 ) {
F_14 ( V_25 ) ;
}
while ( V_23 ) {
V_31 = V_23 -> V_34 . V_35 ;
V_32 = (union V_18 * )
V_23 -> V_34 . V_26 -> V_36 . V_37 [ V_31 ] ;
if ( ( ! V_32 ) ||
( F_15 ( V_32 ) !=
V_38 )
|| ( V_32 -> V_39 . type != V_40 ) ) {
V_30 =
V_28 ( V_41 ,
V_32 , V_23 , V_29 ) ;
if ( F_16 ( V_30 ) ) {
F_14 ( V_30 ) ;
}
V_23 -> V_34 . V_35 ++ ;
while ( V_23 -> V_34 . V_35 >=
V_23 -> V_34 . V_26 -> V_36 . V_42 ) {
F_17 ( V_23 ) ;
V_23 = F_18 ( & V_22 ) ;
if ( ! V_23 ) {
F_14 ( V_24 ) ;
}
V_23 -> V_34 . V_35 ++ ;
}
} else {
V_30 =
V_28 ( V_43 ,
V_32 , V_23 , V_29 ) ;
if ( F_16 ( V_30 ) ) {
F_14 ( V_30 ) ;
}
F_10 ( & V_22 , V_23 ) ;
V_23 = F_13 ( V_32 ,
V_23 -> V_34 .
V_44 , 0 ) ;
if ( ! V_23 ) {
while ( V_22 ) {
V_23 =
F_18
( & V_22 ) ;
F_17 ( V_23 ) ;
}
F_14 ( V_25 ) ;
}
}
}
F_14 ( V_45 ) ;
}
void
F_19 ( T_1 type ,
struct V_46 * V_47 ,
char * V_48 )
{
T_3 V_30 ;
struct V_49 V_50 ;
F_6 () ;
if ( ! ( V_51 & V_52 ) ) {
return;
}
V_50 . V_53 = V_54 ;
V_30 = F_20 ( V_47 , & V_50 ) ;
if ( F_16 ( V_30 ) ) {
return;
}
switch ( type ) {
case V_55 :
F_21 ( L_1 ) ;
break;
default:
F_21 ( L_2 ) ;
break;
}
F_21 ( L_3 ,
F_22 ( type ) , ( char * ) V_50 . V_56 ) ;
if ( V_48 ) {
F_21 ( L_4 , V_48 ) ;
}
F_21 ( L_5 ) ;
F_23 ( V_50 . V_56 ) ;
}
