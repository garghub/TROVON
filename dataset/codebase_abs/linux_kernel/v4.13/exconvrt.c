T_1
F_1 ( union V_1 * V_2 ,
union V_1 * * V_3 , T_2 V_4 )
{
union V_1 * V_5 ;
T_3 * V_6 ;
T_4 V_7 ;
T_2 V_8 ;
T_2 V_9 ;
T_1 V_10 ;
F_2 ( V_11 , V_2 ) ;
switch ( V_2 -> V_12 . type ) {
case V_13 :
* V_3 = V_2 ;
F_3 ( V_14 ) ;
case V_15 :
case V_16 :
V_6 = V_2 -> V_17 . V_6 ;
V_9 = V_2 -> V_17 . V_18 ;
break;
default:
F_3 ( V_19 ) ;
}
V_7 = 0 ;
switch ( V_2 -> V_12 . type ) {
case V_16 :
V_10 = F_4 ( F_5 ( char , V_6 ) ,
( V_20 |
V_4 ) , & V_7 ) ;
if ( F_6 ( V_10 ) ) {
F_3 ( V_10 ) ;
}
break;
case V_15 :
if ( ! V_9 ) {
F_3 ( V_21 ) ;
}
if ( V_9 > V_20 ) {
V_9 = V_20 ;
}
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ ) {
V_7 |= ( ( ( T_4 ) V_6 [ V_8 ] ) << ( V_8 * 8 ) ) ;
}
break;
default:
break;
}
V_5 = F_7 ( V_7 ) ;
if ( ! V_5 ) {
F_3 ( V_22 ) ;
}
F_8 ( ( V_23 , L_1 ,
F_9 ( V_7 ) ) ) ;
( void ) F_10 ( V_5 ) ;
* V_3 = V_5 ;
F_3 ( V_14 ) ;
}
T_1
F_11 ( union V_1 * V_2 ,
union V_1 * * V_3 )
{
union V_1 * V_5 ;
T_3 * V_24 ;
F_2 ( V_25 , V_2 ) ;
switch ( V_2 -> V_12 . type ) {
case V_15 :
* V_3 = V_2 ;
F_3 ( V_14 ) ;
case V_13 :
V_5 =
F_12 ( V_20 ) ;
if ( ! V_5 ) {
F_3 ( V_22 ) ;
}
V_24 = V_5 -> V_17 . V_6 ;
memcpy ( V_24 , & V_2 -> integer . V_26 ,
V_20 ) ;
break;
case V_16 :
V_5 = F_12 ( ( V_27 )
V_2 -> string .
V_18 + 1 ) ;
if ( ! V_5 ) {
F_3 ( V_22 ) ;
}
V_24 = V_5 -> V_17 . V_6 ;
strncpy ( ( char * ) V_24 , ( char * ) V_2 -> string . V_6 ,
V_2 -> string . V_18 ) ;
break;
default:
F_3 ( V_19 ) ;
}
V_5 -> V_12 . V_4 |= V_28 ;
* V_3 = V_5 ;
F_3 ( V_14 ) ;
}
static T_2
F_13 ( T_4 integer , T_5 V_29 , T_3 * string , T_3 V_30 )
{
T_4 V_31 ;
T_2 V_8 ;
T_2 V_32 ;
T_2 V_33 = 0 ;
T_2 V_34 ;
T_2 V_35 ;
T_2 V_36 ;
T_3 V_37 ;
F_14 () ;
switch ( V_29 ) {
case 10 :
switch ( V_30 ) {
case 1 :
V_35 = V_38 ;
break;
case 4 :
V_35 = V_39 ;
break;
case 8 :
default:
V_35 = V_40 ;
break;
}
V_37 = TRUE ;
V_36 = 0 ;
for ( V_8 = V_35 ; V_8 > 0 ; V_8 -- ) {
V_31 = integer ;
for ( V_32 = 0 ; V_32 < V_8 ; V_32 ++ ) {
( void ) F_15 ( V_31 , 10 , & V_31 ,
& V_36 ) ;
}
if ( V_36 != 0 ) {
V_37 = FALSE ;
}
if ( ! V_37 ) {
string [ V_33 ] = ( T_3 ) ( V_41 + V_36 ) ;
V_33 ++ ;
}
}
break;
case 16 :
V_34 = F_16 ( V_30 ) ;
for ( V_8 = 0 , V_32 = ( V_34 - 1 ) ; V_8 < V_34 ; V_8 ++ , V_32 -- ) {
string [ V_33 ] = ( T_3 )
F_17 ( integer , F_18 ( V_32 ) ) ;
V_33 ++ ;
}
break;
default:
return ( 0 ) ;
}
if ( ! V_33 ) {
string [ 0 ] = V_41 ;
V_33 = 1 ;
}
string [ V_33 ] = 0 ;
return ( ( T_2 ) V_33 ) ;
}
T_1
F_19 ( union V_1 * V_2 ,
union V_1 * * V_3 , T_2 type )
{
union V_1 * V_5 ;
T_3 * V_24 ;
T_2 V_8 ;
T_2 V_42 = 0 ;
T_5 V_29 = 16 ;
T_3 V_43 = ',' ;
F_2 ( V_44 , V_2 ) ;
switch ( V_2 -> V_12 . type ) {
case V_16 :
* V_3 = V_2 ;
F_3 ( V_14 ) ;
case V_13 :
switch ( type ) {
case V_45 :
V_42 = V_46 ;
V_29 = 10 ;
break;
default:
V_42 = F_16 ( V_20 ) ;
break;
}
V_5 =
F_20 ( ( V_27 ) V_42 ) ;
if ( ! V_5 ) {
F_3 ( V_22 ) ;
}
V_24 = V_5 -> V_17 . V_6 ;
V_42 =
F_13 ( V_2 -> integer . V_26 , V_29 ,
V_24 ,
V_20 ) ;
V_5 -> string . V_18 = V_42 ;
V_24 [ V_42 ] = 0 ;
break;
case V_15 :
switch ( type ) {
case V_45 :
V_29 = 10 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_17 . V_18 ; V_8 ++ ) {
if ( V_2 -> V_17 . V_6 [ V_8 ] >= 100 ) {
V_42 += 4 ;
} else if ( V_2 -> V_17 . V_6 [ V_8 ] >= 10 ) {
V_42 += 3 ;
} else {
V_42 += 2 ;
}
}
break;
case V_47 :
V_43 = ' ' ;
V_42 = ( V_2 -> V_17 . V_18 * 3 ) ;
break;
case V_48 :
V_42 = ( V_2 -> V_17 . V_18 * 3 ) ;
break;
default:
F_3 ( V_49 ) ;
}
if ( V_42 ) {
V_42 -- ;
}
V_5 =
F_20 ( ( V_27 ) V_42 ) ;
if ( ! V_5 ) {
F_3 ( V_22 ) ;
}
V_24 = V_5 -> V_17 . V_6 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_17 . V_18 ; V_8 ++ ) {
V_24 += F_13 ( ( T_4 ) V_2 ->
V_17 . V_6 [ V_8 ] ,
V_29 , V_24 , 1 ) ;
* V_24 ++ = V_43 ;
}
if ( V_2 -> V_17 . V_18 ) {
V_24 -- ;
}
* V_24 = 0 ;
break;
default:
F_3 ( V_19 ) ;
}
* V_3 = V_5 ;
F_3 ( V_14 ) ;
}
T_1
F_21 ( T_6 V_50 ,
union V_1 * V_51 ,
union V_1 * * V_3 ,
struct V_52 * V_53 )
{
T_1 V_10 = V_14 ;
F_22 ( V_54 ) ;
* V_3 = V_51 ;
switch ( F_23 ( V_53 -> V_55 -> V_56 ) ) {
case V_57 :
case V_58 :
switch ( V_50 ) {
case V_59 :
break;
default:
if ( V_50 != V_51 -> V_12 . type ) {
F_8 ( ( V_60 ,
L_2 ,
F_24
( V_51 ) ,
F_25
( V_50 ) ) ) ;
V_10 = V_19 ;
}
}
break;
case V_61 :
case V_62 :
switch ( V_50 ) {
case V_13 :
case V_63 :
case V_64 :
case V_65 :
V_10 =
F_1 ( V_51 , V_3 ,
V_66 ) ;
break;
case V_16 :
V_10 =
F_19 ( V_51 , V_3 ,
V_47 ) ;
break;
case V_15 :
V_10 =
F_11 ( V_51 , V_3 ) ;
break;
default:
F_26 ( ( V_67 ,
L_3 ,
V_50 ) ) ;
V_10 = V_68 ;
break;
}
break;
case V_69 :
break;
default:
F_26 ( ( V_67 ,
L_4 ,
F_23 ( V_53 -> V_55 ->
V_56 ) ,
V_53 -> V_70 ,
F_25 ( V_50 ) ) ) ;
V_10 = V_68 ;
}
if ( V_10 == V_19 ) {
V_10 = V_14 ;
}
F_3 ( V_10 ) ;
}
