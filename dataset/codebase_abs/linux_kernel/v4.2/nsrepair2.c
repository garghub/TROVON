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
V_10 = F_5 ( V_2 , V_16 , 0 , 2 , 1 ,
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
F_16 ( struct V_1 * V_2 ,
union V_6 * * V_7 )
{
union V_6 * V_16 = * V_7 ;
union V_6 * * V_49 ;
T_3 V_50 ;
union V_6 * V_51 ;
T_1 V_10 ;
T_2 V_52 ;
T_3 V_21 ;
F_7 ( V_53 ) ;
V_50 = V_16 -> V_45 . V_47 - 1 ;
V_21 = 0 ;
while ( V_21 < V_50 ) {
V_49 = & V_16 -> V_45 . V_46 [ V_21 + 1 ] ;
V_52 = FALSE ;
if ( ( * V_49 ) -> V_45 . V_47 == 0 ) {
F_8 ( ( V_30 , V_2 -> V_31 ,
V_2 -> V_32 ,
L_4 ,
V_21 ) ) ;
V_52 = TRUE ;
goto V_54;
}
V_51 = ( * V_49 ) -> V_45 . V_46 [ 1 ] ;
if ( ( T_3 ) V_51 -> integer . V_55 == 0 ) {
F_8 ( ( V_30 , V_2 -> V_31 ,
V_2 -> V_32 ,
L_5 ,
V_21 ) ) ;
V_52 = TRUE ;
}
V_54:
if ( V_52 ) {
F_17 ( V_16 , V_21 + 1 ) ;
V_50 -- ;
} else {
V_21 ++ ;
}
}
V_51 = V_16 -> V_45 . V_46 [ 0 ] ;
V_51 -> integer . V_55 = V_50 ;
V_10 = F_5 ( V_2 , V_16 , 1 , 4 , 1 ,
V_17 , L_6 ) ;
if ( F_15 ( V_10 ) ) {
return ( V_10 ) ;
}
return ( V_28 ) ;
}
static T_1
F_14 ( struct V_1 * V_2 ,
union V_6 * * V_7 )
{
union V_6 * V_16 = * V_7 ;
union V_6 * V_56 ;
char * V_57 ;
char * V_58 ;
F_7 ( V_59 ) ;
if ( V_16 -> V_23 . type != V_43 ) {
return ( V_28 ) ;
}
if ( V_16 -> string . V_26 == 0 ) {
F_8 ( ( V_30 , V_2 -> V_31 ,
V_2 -> V_32 ,
L_7 ) ) ;
V_2 -> V_38 |= V_39 ;
return ( V_28 ) ;
}
V_56 = F_18 ( V_16 -> string . V_26 ) ;
if ( ! V_56 ) {
return ( V_34 ) ;
}
V_57 = V_16 -> string . V_35 ;
if ( * V_57 == '*' ) {
V_57 ++ ;
V_56 -> string . V_26 -- ;
F_11 ( ( V_37 ,
L_8 ,
V_2 -> V_31 ) ) ;
}
for ( V_58 = V_56 -> string . V_35 ; * V_57 ; V_58 ++ , V_57 ++ ) {
* V_58 = ( char ) toupper ( ( int ) * V_57 ) ;
}
F_12 ( V_16 ) ;
* V_7 = V_56 ;
return ( V_28 ) ;
}
static T_1
F_19 ( struct V_1 * V_2 ,
union V_6 * * V_7 )
{
union V_6 * V_60 = * V_7 ;
union V_6 * * V_61 ;
union V_6 * * V_62 ;
union V_6 * V_51 ;
union V_6 * V_63 ;
T_3 V_64 ;
T_3 V_65 ;
V_61 = V_60 -> V_45 . V_46 ;
V_64 = V_60 -> V_45 . V_47 ;
for ( V_65 = 0 ; V_65 < V_64 ; V_65 ++ , V_61 ++ ) {
V_63 = * V_61 ;
V_62 = V_63 -> V_45 . V_46 ;
if ( V_63 -> V_45 . V_47 < 4 ) {
continue;
}
V_51 = V_62 [ 3 ] ;
if ( ! V_51 || ( V_51 -> V_23 . type != V_66 ) ) {
V_62 [ 3 ] = V_62 [ 2 ] ;
V_62 [ 2 ] = V_51 ;
V_2 -> V_38 |= V_39 ;
F_8 ( ( V_30 ,
V_2 -> V_31 ,
V_2 -> V_32 ,
L_9 ,
V_65 ) ) ;
}
}
return ( V_28 ) ;
}
static T_1
F_20 ( struct V_1 * V_2 ,
union V_6 * * V_7 )
{
union V_6 * V_16 = * V_7 ;
union V_6 * * V_49 ;
T_3 V_50 ;
union V_6 * * V_46 ;
union V_6 * V_51 ;
T_3 V_67 ;
T_1 V_10 ;
T_3 V_21 ;
V_10 = F_5 ( V_2 , V_16 , 0 , 6 , 0 ,
V_68 ,
L_10 ) ;
if ( F_15 ( V_10 ) ) {
return ( V_10 ) ;
}
V_67 = V_69 ;
V_49 = V_16 -> V_45 . V_46 ;
V_50 = V_16 -> V_45 . V_47 ;
for ( V_21 = 0 ; V_21 < V_50 ; V_21 ++ ) {
V_46 = ( * V_49 ) -> V_45 . V_46 ;
V_51 = V_46 [ 1 ] ;
if ( ( T_3 ) V_51 -> integer . V_55 > V_67 ) {
F_8 ( ( V_30 , V_2 -> V_31 ,
V_2 -> V_32 ,
L_11 ,
V_21 - 1 , V_21 ) ) ;
}
V_67 = ( T_3 ) V_51 -> integer . V_55 ;
V_49 ++ ;
}
return ( V_28 ) ;
}
static T_1
F_21 ( struct V_1 * V_2 ,
union V_6 * * V_7 )
{
union V_6 * V_16 = * V_7 ;
T_1 V_10 ;
struct V_3 * V_4 ;
V_10 = F_22 ( V_2 -> V_4 , L_12 ,
V_70 , & V_4 ) ;
if ( F_23 ( V_10 ) ) {
return ( V_28 ) ;
}
V_10 = F_5 ( V_2 , V_16 , 0 , 5 , 1 ,
V_68 ,
L_13 ) ;
return ( V_10 ) ;
}
static T_1
F_5 ( struct V_1 * V_2 ,
union V_6 * V_16 ,
T_3 V_71 ,
T_3 V_72 ,
T_3 V_73 ,
T_2 V_74 , char * V_75 )
{
T_3 V_50 ;
union V_6 * * V_49 ;
union V_6 * * V_46 ;
union V_6 * V_51 ;
T_3 V_21 ;
T_3 V_67 ;
F_7 ( V_76 ) ;
if ( V_16 -> V_23 . type != V_44 ) {
return ( V_33 ) ;
}
V_50 = V_16 -> V_45 . V_47 ;
if ( ! V_50 || V_71 >= V_50 ) {
return ( V_77 ) ;
}
V_49 = & V_16 -> V_45 . V_46 [ V_71 ] ;
V_50 -= V_71 ;
V_67 = 0 ;
if ( V_74 == V_68 ) {
V_67 = V_69 ;
}
for ( V_21 = 0 ; V_21 < V_50 ; V_21 ++ ) {
if ( ( * V_49 ) -> V_23 . type != V_44 ) {
return ( V_33 ) ;
}
if ( ( * V_49 ) -> V_45 . V_47 < V_72 ) {
return ( V_77 ) ;
}
V_46 = ( * V_49 ) -> V_45 . V_46 ;
V_51 = V_46 [ V_73 ] ;
if ( V_51 -> V_23 . type != V_66 ) {
return ( V_33 ) ;
}
if ( ( ( V_74 == V_17 ) &&
( V_51 -> integer . V_55 < V_67 ) ) ||
( ( V_74 == V_68 ) &&
( V_51 -> integer . V_55 > V_67 ) ) ) {
F_24 ( & V_16 -> V_45 .
V_46 [ V_71 ] ,
V_50 , V_73 ,
V_74 ) ;
V_2 -> V_38 |= V_39 ;
F_11 ( ( V_37 ,
L_14 ,
V_2 -> V_31 , V_75 ) ) ;
return ( V_28 ) ;
}
V_67 = ( T_3 ) V_51 -> integer . V_55 ;
V_49 ++ ;
}
return ( V_28 ) ;
}
static void
F_24 ( union V_6 * * V_46 ,
T_3 V_47 , T_3 V_65 , T_2 V_74 )
{
union V_6 * V_78 ;
union V_6 * V_79 ;
union V_6 * V_80 ;
T_3 V_21 ;
T_3 V_81 ;
for ( V_21 = 1 ; V_21 < V_47 ; V_21 ++ ) {
for ( V_81 = ( V_47 - 1 ) ; V_81 >= V_21 ; V_81 -- ) {
V_78 = V_46 [ V_81 - 1 ] -> V_45 . V_46 [ V_65 ] ;
V_79 = V_46 [ V_81 ] -> V_45 . V_46 [ V_65 ] ;
if ( ( ( V_74 == V_17 ) &&
( V_78 -> integer . V_55 >
V_79 -> integer . V_55 ) )
|| ( ( V_74 == V_68 )
&& ( V_78 -> integer . V_55 <
V_79 -> integer . V_55 ) ) ) {
V_80 = V_46 [ V_81 - 1 ] ;
V_46 [ V_81 - 1 ] = V_46 [ V_81 ] ;
V_46 [ V_81 ] = V_80 ;
}
}
}
}
static void
F_17 ( union V_6 * V_51 , T_3 V_65 )
{
union V_6 * * V_57 ;
union V_6 * * V_58 ;
T_3 V_47 ;
T_3 V_82 ;
T_3 V_21 ;
F_7 ( V_83 ) ;
V_47 = V_51 -> V_45 . V_47 ;
V_82 = V_47 - 1 ;
V_57 = V_51 -> V_45 . V_46 ;
V_58 = V_57 ;
for ( V_21 = 0 ; V_21 < V_47 ; V_21 ++ ) {
if ( V_21 == V_65 ) {
F_12 ( * V_57 ) ;
F_12 ( * V_57 ) ;
} else {
* V_58 = * V_57 ;
V_58 ++ ;
}
V_57 ++ ;
}
* V_58 = NULL ;
V_51 -> V_45 . V_47 = V_82 ;
}
