T_1 F_1 ( int V_1 , T_2 * V_2 )
{
T_2 V_3 ;
if ( ! isxdigit ( V_1 ) ) {
return ( V_4 ) ;
}
if ( V_1 <= 0x39 ) {
V_3 = ( T_2 ) ( V_1 - 0x30 ) ;
} else {
V_3 = ( T_2 ) ( toupper ( V_1 ) - 0x37 ) ;
}
* V_2 = V_3 ;
return ( V_5 ) ;
}
static T_1 F_2 ( char * V_6 , T_2 * V_2 )
{
T_2 V_7 ;
T_2 V_8 ;
T_1 V_9 ;
V_9 = F_1 ( V_6 [ 0 ] , & V_7 ) ;
if ( F_3 ( V_9 ) ) {
return ( V_9 ) ;
}
V_9 = F_1 ( V_6 [ 1 ] , & V_8 ) ;
if ( F_3 ( V_9 ) ) {
return ( V_9 ) ;
}
* V_2 = ( T_2 ) ( ( V_7 << 4 ) | V_8 ) ;
return ( V_5 ) ;
}
static T_1
F_4 ( char * string , union V_10 * V_11 )
{
T_3 V_12 ;
T_3 V_13 ;
T_3 V_14 ;
T_2 * V_15 ;
T_1 V_9 ;
for ( V_12 = 0 , V_14 = 0 ; string [ V_12 ] ; ) {
V_12 += 2 ;
V_14 ++ ;
while ( string [ V_12 ] && ( ( string [ V_12 ] == ',' ) || ( string [ V_12 ] == ' ' ) ) ) {
V_12 ++ ;
}
}
V_15 = F_5 ( V_14 ) ;
if ( ! V_15 ) {
return ( V_16 ) ;
}
for ( V_12 = 0 , V_13 = 0 ; string [ V_12 ] ; ) {
V_9 = F_2 ( & string [ V_12 ] , & V_15 [ V_13 ] ) ;
if ( F_3 ( V_9 ) ) {
F_6 ( V_15 ) ;
return ( V_9 ) ;
}
V_13 ++ ;
V_12 += 2 ;
while ( string [ V_12 ] && ( ( string [ V_12 ] == ',' ) || ( string [ V_12 ] == ' ' ) ) ) {
V_12 ++ ;
}
}
V_11 -> type = V_17 ;
V_11 -> V_15 . V_18 = V_15 ;
V_11 -> V_15 . V_14 = V_14 ;
return ( V_5 ) ;
}
T_1 F_7 ( char * string , union V_10 * V_11 )
{
char * V_19 ;
char * V_20 ;
T_3 V_12 ;
T_4 type ;
union V_10 * V_21 ;
T_1 V_9 ;
V_21 =
F_8 ( V_22 *
sizeof( union V_10 ) ) ;
V_19 = string ;
for ( V_12 = 0 ; V_12 < ( V_22 - 1 ) ; V_12 ++ ) {
V_19 = F_9 ( V_19 , & V_20 , & type ) ;
if ( ! V_19 ) {
break;
}
V_9 = F_10 ( type , V_19 , & V_21 [ V_12 ] ) ;
if ( F_3 ( V_9 ) ) {
F_11 ( V_12 + 1 , V_21 ) ;
F_6 ( V_21 ) ;
return ( V_9 ) ;
}
V_19 = V_20 ;
}
V_11 -> type = V_23 ;
V_11 -> V_24 . V_25 = V_12 ;
V_11 -> V_24 . V_21 = V_21 ;
return ( V_5 ) ;
}
T_1
F_10 ( T_4 type ,
char * string , union V_10 * V_11 )
{
T_1 V_9 = V_5 ;
switch ( type ) {
case V_26 :
V_11 -> type = V_26 ;
V_11 -> string . V_18 = string ;
V_11 -> string . V_14 = ( T_3 ) strlen ( string ) ;
break;
case V_17 :
V_9 = F_4 ( string , V_11 ) ;
break;
case V_23 :
V_9 = F_7 ( string , V_11 ) ;
break;
default:
V_11 -> type = V_27 ;
V_9 = F_12 ( string , 16 , & V_11 -> integer . V_3 ) ;
break;
}
return ( V_9 ) ;
}
T_2 * F_13 ( struct V_28 * V_29 )
{
T_3 * V_15 ;
T_3 V_30 ;
V_15 = F_8 ( V_31 ) ;
if ( ! V_15 ) {
return ( NULL ) ;
}
V_30 = 0 ;
F_14 ( & V_30 , V_29 -> V_32 ) ;
F_15 ( & V_30 , V_29 -> V_33 ) ;
F_16 ( & V_30 , V_29 -> V_34 ) ;
F_17 ( & V_30 , V_29 -> V_35 ) ;
F_18 ( & V_30 , V_29 -> V_36 ) ;
F_19 ( & V_15 [ 0 ] , & V_30 ) ;
V_30 = 0 ;
F_20 ( & V_30 , V_29 -> V_37 ) ;
F_21 ( & V_30 , V_29 -> V_38 ) ;
F_19 ( & V_15 [ 1 ] , & V_30 ) ;
V_30 = 0 ;
F_22 ( & V_30 , V_29 -> V_39 ) ;
F_23 ( & V_30 , V_29 -> V_40 ) ;
F_24 ( & V_30 , V_29 -> V_41 ) ;
F_25 ( & V_30 , V_29 -> V_42 ) ;
F_26 ( & V_30 , V_29 -> V_43 ) ;
F_27 ( & V_30 , V_29 -> V_44 ) ;
F_28 ( & V_30 , V_29 -> V_45 ) ;
F_29 ( & V_30 , V_29 -> V_46 ) ;
F_30 ( & V_30 , V_29 -> V_47 ) ;
F_31 ( & V_30 , V_29 -> V_48 ) ;
F_32 ( & V_30 , V_29 -> V_49 ) ;
F_19 ( & V_15 [ 2 ] , & V_30 ) ;
V_30 = 0 ;
F_33 ( & V_30 , V_29 -> V_50 ) ;
F_34 ( & V_30 , V_29 -> V_51 ) ;
F_35 ( & V_30 , V_29 -> V_52 ) ;
F_36 ( & V_30 , V_29 -> V_53 ) ;
F_37 ( & V_30 , V_29 -> V_54 ) ;
F_38 ( & V_30 , V_29 -> V_55 ) ;
F_39 ( & V_30 , V_29 -> V_56 ) ;
F_19 ( & V_15 [ 3 ] , & V_30 ) ;
if ( V_29 -> V_32 >= 2 ) {
V_30 = 0 ;
F_40 ( & V_30 , V_29 -> V_57 ) ;
F_41 ( & V_30 , V_29 -> V_58 ) ;
F_19 ( & V_15 [ 4 ] , & V_30 ) ;
}
return ( F_42 ( T_2 , V_15 ) ) ;
}
void F_43 ( union V_10 * V_59 )
{
union V_10 * V_60 ;
struct V_28 * V_29 ;
T_2 * V_61 ;
T_1 V_9 ;
if ( V_59 -> type != V_23 ) {
return;
}
V_60 = & V_59 -> V_24 . V_21 [ 0 ] ;
if ( V_60 -> type != V_17 ) {
return;
}
V_9 = F_44 ( V_60 -> V_15 . V_18 ,
V_60 -> V_15 . V_14 , & V_29 ) ;
if ( F_3 ( V_9 ) ) {
return;
}
V_61 = F_13 ( V_29 ) ;
if ( ! V_61 ) {
return;
}
if ( memcmp ( V_61 , V_60 -> V_15 . V_18 ,
V_60 -> V_15 . V_14 ) ) {
F_45
( L_1 ) ;
F_46 ( V_61 ,
V_60 -> V_15 . V_14 , V_62 ,
0 ) ;
}
F_45 ( V_63 , L_2 , V_29 -> V_32 ) ;
F_45 ( V_63 , L_3 ,
V_29 -> V_33 ) ;
F_45 ( V_63 , L_4 , V_29 -> V_34 ) ;
F_45 ( V_63 , L_5 , V_29 -> V_35 ) ;
F_45 ( V_63 , L_6 , V_29 -> V_36 ) ;
F_45 ( V_63 , L_7 , V_29 -> V_37 ) ;
F_45 ( V_63 , L_8 , V_29 -> V_38 ) ;
F_45 ( V_63 , L_9 ,
V_29 -> V_39 ) ;
F_45 ( V_63 , L_10 , V_29 -> V_40 ) ;
F_45 ( V_63 , L_11 , V_29 -> V_41 ) ;
F_45 ( V_63 , L_12 , V_29 -> V_42 ) ;
F_45 ( V_63 , L_13 ,
V_29 -> V_43 ) ;
F_45 ( V_63 , L_14 ,
V_29 -> V_44 ) ;
F_45 ( V_63 , L_15 , V_29 -> V_45 ) ;
F_45 ( V_63 , L_16 ,
V_29 -> V_46 ) ;
F_45 ( V_63 , L_17 ,
V_29 -> V_47 ) ;
F_45 ( V_63 , L_18 ,
V_29 -> V_48 ) ;
F_45 ( V_63 , L_19 , V_29 -> V_49 ) ;
F_45 ( V_63 , L_20 , V_29 -> V_50 ) ;
F_45 ( V_63 , L_21 ,
V_29 -> V_51 ) ;
F_45 ( V_63 , L_22 ,
V_29 -> V_52 ) ;
F_45 ( V_63 , L_23 ,
V_29 -> V_53 ) ;
F_45 ( V_63 , L_24 , V_29 -> V_54 ) ;
F_45 ( V_63 , L_25 , V_29 -> V_55 ) ;
F_45 ( V_63 , L_26 , V_29 -> V_56 ) ;
if ( V_60 -> V_15 . V_14 > 16 ) {
F_45 ( V_63 , L_27 ,
V_29 -> V_57 ) ;
F_45 ( V_63 , L_28 ,
V_29 -> V_58 ) ;
}
F_6 ( V_29 ) ;
F_6 ( V_61 ) ;
}
