T_1
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 ,
union V_6 * * V_7 )
{
const struct V_8 * V_9 ;
T_1 V_10 ;
V_9 = F_2 ( V_4 ) ;
if ( ! V_9 ) {
return ( V_5 ) ;
}
V_10 = V_9 -> V_11 ( V_2 , V_7 ) ;
return ( V_10 ) ;
}
static const struct V_8 * F_2 ( struct
V_3
* V_4 )
{
const struct V_8 * V_12 ;
V_12 = V_13 ;
while ( V_12 -> V_11 ) {
if ( F_3 ( V_4 -> V_14 . V_15 , V_12 -> V_14 ) ) {
return ( V_12 ) ;
}
V_12 ++ ;
}
return ( NULL ) ;
}
static T_1
F_4 ( struct V_1 * V_2 ,
union V_6 * * V_7 )
{
union V_6 * V_16 = * V_7 ;
T_1 V_10 ;
V_10 = F_5 ( V_2 , V_16 , 2 , 1 ,
V_17 ,
L_1 ) ;
return ( V_10 ) ;
}
static T_1
F_6 ( struct V_1 * V_2 ,
union V_6 * * V_7 )
{
union V_6 * V_16 = * V_7 ;
union V_6 * V_18 ;
T_2 * V_19 ;
T_3 * V_20 ;
T_3 V_21 ;
F_7 ( V_22 ) ;
switch ( V_16 -> V_23 . type ) {
case V_24 :
if ( V_16 -> V_25 . V_26 >= V_27 ) {
return ( V_28 ) ;
}
if ( V_16 -> V_25 . V_26 != V_29 ) {
F_8 ( ( V_30 , V_2 -> V_31 ,
V_2 -> V_32 ,
L_2 ,
V_16 -> V_25 . V_26 ,
V_27 ) ) ;
return ( V_33 ) ;
}
V_18 =
F_9 ( V_27 ) ;
if ( ! V_18 ) {
return ( V_34 ) ;
}
V_19 = V_16 -> V_25 . V_35 ;
V_20 =
F_10 ( T_3 , V_18 -> V_25 . V_35 ) ;
for ( V_21 = 0 ; V_21 < V_36 ; V_21 ++ ) {
* V_20 = ( T_3 ) * V_19 ;
V_20 ++ ;
V_19 ++ ;
}
F_11 ( ( V_37 ,
L_3 ,
V_2 -> V_31 ) ) ;
break;
default:
return ( V_33 ) ;
}
F_12 ( V_16 ) ;
* V_7 = V_18 ;
V_2 -> V_38 |= V_39 ;
return ( V_28 ) ;
}
static T_1
F_13 ( struct V_1 * V_2 ,
union V_6 * * V_7 )
{
T_1 V_10 ;
union V_6 * V_16 = * V_7 ;
union V_6 * * V_40 ;
union V_6 * V_41 ;
T_4 V_42 ;
T_3 V_21 ;
if ( V_16 -> V_23 . type == V_43 ) {
V_10 = F_14 ( V_2 , V_7 ) ;
return ( V_10 ) ;
}
if ( V_16 -> V_23 . type != V_44 ) {
return ( V_28 ) ;
}
V_40 = V_16 -> V_45 . V_46 ;
for ( V_21 = 0 ; V_21 < V_16 -> V_45 . V_47 ; V_21 ++ ) {
V_41 = * V_40 ;
V_42 = V_41 -> V_23 . V_48 ;
V_10 = F_14 ( V_2 , V_40 ) ;
if ( F_15 ( V_10 ) ) {
return ( V_10 ) ;
}
if ( V_41 != * V_40 ) {
( * V_40 ) -> V_23 . V_48 =
V_42 ;
F_12 ( V_41 ) ;
}
V_40 ++ ;
}
return ( V_28 ) ;
}
static T_1
F_14 ( struct V_1 * V_2 ,
union V_6 * * V_7 )
{
union V_6 * V_16 = * V_7 ;
union V_6 * V_49 ;
char * V_50 ;
char * V_51 ;
F_7 ( V_52 ) ;
if ( V_16 -> V_23 . type != V_43 ) {
return ( V_28 ) ;
}
if ( V_16 -> string . V_26 == 0 ) {
F_8 ( ( V_30 , V_2 -> V_31 , V_2 -> V_32 ,
L_4 ) ) ;
V_2 -> V_38 |= V_39 ;
return ( V_28 ) ;
}
V_49 = F_16 ( V_16 -> string . V_26 ) ;
if ( ! V_49 ) {
return ( V_34 ) ;
}
V_50 = V_16 -> string . V_35 ;
if ( * V_50 == '*' ) {
V_50 ++ ;
V_49 -> string . V_26 -- ;
F_11 ( ( V_37 ,
L_5 ,
V_2 -> V_31 ) ) ;
}
for ( V_51 = V_49 -> string . V_35 ; * V_50 ; V_51 ++ , V_50 ++ ) {
* V_51 = ( char ) F_17 ( * V_50 ) ;
}
F_12 ( V_16 ) ;
* V_7 = V_49 ;
return ( V_28 ) ;
}
static T_1
F_18 ( struct V_1 * V_2 ,
union V_6 * * V_7 )
{
union V_6 * V_16 = * V_7 ;
T_1 V_10 ;
struct V_3 * V_4 ;
V_10 =
F_19 ( V_2 -> V_4 , L_6 , V_53 , & V_4 ) ;
if ( F_20 ( V_10 ) ) {
return ( V_28 ) ;
}
V_10 = F_5 ( V_2 , V_16 , 5 , 1 ,
V_54 ,
L_7 ) ;
return ( V_10 ) ;
}
static T_1
F_21 ( struct V_1 * V_2 ,
union V_6 * * V_7 )
{
union V_6 * V_16 = * V_7 ;
union V_6 * * V_55 ;
T_3 V_56 ;
union V_6 * * V_46 ;
union V_6 * V_57 ;
T_3 V_58 ;
T_1 V_10 ;
T_3 V_21 ;
V_10 = F_5 ( V_2 , V_16 , 6 , 0 ,
V_54 ,
L_8 ) ;
if ( F_15 ( V_10 ) ) {
return ( V_10 ) ;
}
V_58 = V_59 ;
V_55 = V_16 -> V_45 . V_46 ;
V_56 = V_16 -> V_45 . V_47 ;
for ( V_21 = 0 ; V_21 < V_56 ; V_21 ++ ) {
V_46 = ( * V_55 ) -> V_45 . V_46 ;
V_57 = V_46 [ 1 ] ;
if ( ( T_3 ) V_57 -> integer . V_60 > V_58 ) {
F_8 ( ( V_30 , V_2 -> V_31 ,
V_2 -> V_32 ,
L_9 ,
V_21 - 1 , V_21 ) ) ;
}
V_58 = ( T_3 ) V_57 -> integer . V_60 ;
V_55 ++ ;
}
return ( V_28 ) ;
}
static T_1
F_5 ( struct V_1 * V_2 ,
union V_6 * V_16 ,
T_3 V_61 ,
T_3 V_62 ,
T_2 V_63 , char * V_64 )
{
T_3 V_56 ;
union V_6 * * V_55 ;
union V_6 * * V_46 ;
union V_6 * V_57 ;
T_3 V_21 ;
T_3 V_58 ;
F_7 ( V_65 ) ;
if ( V_16 -> V_23 . type != V_44 ) {
return ( V_33 ) ;
}
V_55 = V_16 -> V_45 . V_46 ;
V_56 = V_16 -> V_45 . V_47 ;
if ( ! V_56 ) {
return ( V_66 ) ;
}
V_58 = 0 ;
if ( V_63 == V_54 ) {
V_58 = V_59 ;
}
for ( V_21 = 0 ; V_21 < V_56 ; V_21 ++ ) {
if ( ( * V_55 ) -> V_23 . type != V_44 ) {
return ( V_33 ) ;
}
if ( ( * V_55 ) -> V_45 . V_47 < V_61 ) {
return ( V_66 ) ;
}
V_46 = ( * V_55 ) -> V_45 . V_46 ;
V_57 = V_46 [ V_62 ] ;
if ( V_57 -> V_23 . type != V_67 ) {
return ( V_33 ) ;
}
if ( ( ( V_63 == V_17 ) &&
( V_57 -> integer . V_60 < V_58 ) ) ||
( ( V_63 == V_54 ) &&
( V_57 -> integer . V_60 > V_58 ) ) ) {
F_22 ( V_16 -> V_45 . V_46 ,
V_56 , V_62 ,
V_63 ) ;
V_2 -> V_38 |= V_39 ;
F_11 ( ( V_37 ,
L_10 ,
V_2 -> V_31 , V_64 ) ) ;
return ( V_28 ) ;
}
V_58 = ( T_3 ) V_57 -> integer . V_60 ;
V_55 ++ ;
}
return ( V_28 ) ;
}
static void
F_22 ( union V_6 * * V_46 ,
T_3 V_47 , T_3 V_68 , T_2 V_63 )
{
union V_6 * V_69 ;
union V_6 * V_70 ;
union V_6 * V_71 ;
T_3 V_21 ;
T_3 V_72 ;
for ( V_21 = 1 ; V_21 < V_47 ; V_21 ++ ) {
for ( V_72 = ( V_47 - 1 ) ; V_72 >= V_21 ; V_72 -- ) {
V_69 = V_46 [ V_72 - 1 ] -> V_45 . V_46 [ V_68 ] ;
V_70 = V_46 [ V_72 ] -> V_45 . V_46 [ V_68 ] ;
if ( ( ( V_63 == V_17 ) &&
( V_69 -> integer . V_60 >
V_70 -> integer . V_60 ) )
|| ( ( V_63 == V_54 )
&& ( V_69 -> integer . V_60 <
V_70 -> integer . V_60 ) ) ) {
V_71 = V_46 [ V_72 - 1 ] ;
V_46 [ V_72 - 1 ] = V_46 [ V_72 ] ;
V_46 [ V_72 ] = V_71 ;
}
}
}
}
