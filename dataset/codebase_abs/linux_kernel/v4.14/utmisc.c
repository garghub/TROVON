T_1 F_1 ( char * V_1 )
{
if ( ! ( strcmp ( V_1 ,
V_2 ) ) ||
! ( strcmp ( V_1 , V_3 ) ) ) {
return ( TRUE ) ;
}
return ( FALSE ) ;
}
T_1 F_2 ( struct V_4 * V_5 )
{
if ( F_3 ( V_5 -> V_6 , V_7 ) ||
F_3 ( V_5 -> V_6 , V_8 ) ||
F_3 ( V_5 -> V_6 , V_9 ) ||
F_3 ( V_5 -> V_6 , V_10 ) ) {
return ( TRUE ) ;
}
return ( FALSE ) ;
}
T_2 F_4 ( T_2 V_11 )
{
union {
T_2 V_11 ;
T_1 V_12 [ 4 ] ;
} V_13 ;
union {
T_2 V_11 ;
T_1 V_12 [ 4 ] ;
} V_14 ;
F_5 () ;
V_14 . V_11 = V_11 ;
V_13 . V_12 [ 0 ] = V_14 . V_12 [ 3 ] ;
V_13 . V_12 [ 1 ] = V_14 . V_12 [ 2 ] ;
V_13 . V_12 [ 2 ] = V_14 . V_12 [ 1 ] ;
V_13 . V_12 [ 3 ] = V_14 . V_12 [ 0 ] ;
return ( V_13 . V_11 ) ;
}
void F_6 ( T_1 V_15 )
{
if ( V_15 < 2 ) {
V_16 = 32 ;
V_17 = 8 ;
V_18 = 4 ;
} else {
V_16 = 64 ;
V_17 = 16 ;
V_18 = 8 ;
}
}
T_3
F_7 ( union V_19 * V_20 ,
T_4 V_21 ,
union V_22 * * V_23 )
{
union V_22 * V_24 ;
F_5 () ;
if ( ! V_20 ) {
return ( V_25 ) ;
}
V_24 = F_8 ( V_20 , V_21 ) ;
if ( ! V_24 ) {
return ( V_26 ) ;
}
F_9 ( V_23 , V_24 ) ;
return ( V_25 ) ;
}
T_3
F_10 ( union V_19 * V_27 ,
void * V_28 ,
T_5 V_29 , void * V_30 )
{
T_3 V_31 = V_25 ;
union V_22 * V_23 = NULL ;
union V_22 * V_24 ;
union V_19 * V_32 ;
T_2 V_33 ;
F_11 ( V_34 ) ;
V_24 = F_12 ( V_27 , V_28 , 0 ) ;
if ( ! V_24 ) {
F_13 ( V_26 ) ;
}
while ( V_24 ) {
V_33 = V_24 -> V_35 . V_36 ;
V_32 =
V_24 -> V_35 . V_27 -> V_37 . V_38 [ V_33 ] ;
V_24 -> V_35 . V_39 =
& V_24 -> V_35 . V_27 -> V_37 . V_38 [ V_33 ] ;
if ( ( ! V_32 ) ||
( F_14 ( V_32 ) !=
V_40 ) ||
( V_32 -> V_41 . type != V_42 ) ) {
V_31 =
V_29 ( V_43 ,
V_32 , V_24 , V_30 ) ;
if ( F_15 ( V_31 ) ) {
F_13 ( V_31 ) ;
}
V_24 -> V_35 . V_36 ++ ;
while ( V_24 -> V_35 . V_36 >=
V_24 -> V_35 . V_27 -> V_37 . V_44 ) {
F_16 ( V_24 ) ;
V_24 = F_17 ( & V_23 ) ;
if ( ! V_24 ) {
F_13 ( V_25 ) ;
}
V_24 -> V_35 . V_36 ++ ;
}
} else {
V_31 =
V_29 ( V_45 ,
V_32 , V_24 , V_30 ) ;
if ( F_15 ( V_31 ) ) {
F_13 ( V_31 ) ;
}
F_9 ( & V_23 , V_24 ) ;
V_24 =
F_12 ( V_32 ,
V_24 -> V_35 . V_39 ,
0 ) ;
if ( ! V_24 ) {
while ( V_23 ) {
V_24 =
F_17
( & V_23 ) ;
F_16 ( V_24 ) ;
}
F_13 ( V_26 ) ;
}
}
}
F_18 ( ( V_46 , L_1 ) ) ;
F_13 ( V_47 ) ;
}
void
F_19 ( T_1 type ,
struct V_48 * V_49 ,
const char * V_50 )
{
T_3 V_31 ;
struct V_51 V_52 ;
F_5 () ;
if ( ! ( V_53 & V_54 ) ) {
return;
}
V_52 . V_55 = V_56 ;
V_31 = F_20 ( V_49 , & V_52 , TRUE ) ;
if ( F_15 ( V_31 ) ) {
return;
}
switch ( type ) {
case V_57 :
F_21 ( L_2 ) ;
break;
default:
F_21 ( L_3 ) ;
break;
}
F_21 ( L_4 ,
F_22 ( type ) , ( char * ) V_52 . V_58 ) ;
if ( V_50 ) {
F_21 ( L_5 , V_50 ) ;
}
F_21 ( L_6 ) ;
F_23 ( V_52 . V_58 ) ;
}
