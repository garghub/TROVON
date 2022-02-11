T_1 F_1 ( T_2 V_1 , T_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 ;
F_2 () ;
for ( V_3 = 0 , V_4 = 0 ; V_1 ; V_3 ++ ) {
if ( V_1 & 0x0001 ) {
V_2 [ V_4 ] = V_3 ;
V_4 ++ ;
}
V_1 >>= 1 ;
}
return ( V_4 ) ;
}
T_2 F_3 ( T_1 * V_2 , T_1 V_5 )
{
T_3 V_3 ;
T_2 V_1 ;
F_2 () ;
for ( V_3 = 0 , V_1 = 0 ; V_3 < V_5 ; V_3 ++ ) {
V_1 |= ( 0x1 << V_2 [ V_3 ] ) ;
}
return ( V_1 ) ;
}
void
F_4 ( void * V_6 , void * V_7 , T_2 V_8 , T_1 V_9 )
{
T_3 V_3 ;
F_2 () ;
for ( V_3 = 0 ; V_3 < V_8 ; V_3 ++ ) {
switch ( V_9 ) {
case V_10 :
case V_11 :
case V_12 :
case V_13 :
F_5 ( V_6 , V_7 , V_8 ) ;
return;
case V_14 :
case V_15 :
F_6 ( & F_7 ( T_2 , V_6 ) [ V_3 ] ,
& F_7 ( T_2 , V_7 ) [ V_3 ] ) ;
break;
case V_16 :
F_8 ( & F_7 ( T_3 , V_6 ) [ V_3 ] ,
& F_7 ( T_3 , V_7 ) [ V_3 ] ) ;
break;
case V_17 :
F_9 ( & F_7 ( V_18 , V_6 ) [ V_3 ] ,
& F_7 ( V_18 , V_7 ) [ V_3 ] ) ;
break;
default:
return;
}
}
}
void
F_10 ( T_4 V_19 ,
union V_20 * V_21 )
{
T_5 V_22 ;
F_2 () ;
V_22 = ( T_5 )
( V_19 - F_11 ( V_21 ) ) ;
if ( V_21 -> V_23 . V_24 & V_25 ) {
F_6 ( & V_21 -> V_26 . V_22 ,
& V_22 ) ;
} else {
V_21 -> V_23 . V_24 = ( T_1 )
( ( V_21 -> V_23 .
V_24 & ~ V_27 )
| V_22 ) ;
}
}
void
F_12 ( T_1 V_24 ,
T_4 V_19 ,
union V_20 * V_21 )
{
F_2 () ;
V_21 -> V_23 . V_24 = V_24 ;
F_10 ( V_19 , V_21 ) ;
}
static T_2 F_13 ( char * V_6 , char * V_7 )
{
T_2 V_3 ;
F_2 () ;
for ( V_3 = 0 ; V_7 [ V_3 ] ; V_3 ++ ) {
V_6 [ V_3 ] = V_7 [ V_3 ] ;
}
V_6 [ V_3 ] = 0 ;
return ( ( T_2 ) ( V_3 + 1 ) ) ;
}
T_5
F_14 ( T_5 V_22 ,
T_5 V_28 ,
struct V_29 * V_30 ,
union V_20 * V_21 , char * V_31 )
{
T_4 V_19 ;
T_1 * V_32 ;
F_2 () ;
V_19 =
V_22 + sizeof( struct V_33 ) ;
V_32 = F_15 ( T_1 , V_21 , V_28 ) ;
if ( V_19 > ( T_4 ) ( V_28 + 1 ) ) {
V_30 -> V_34 = V_32 [ 0 ] ;
V_30 -> V_31 = V_31 ;
if ( ! V_31 ) {
V_30 -> V_31 =
F_15 ( char , V_30 ,
sizeof( struct V_29 ) ) ;
}
V_19 =
( T_3 )
F_16 ( F_7 ( char , & V_32 [ 1 ] ) ) +
1 ;
V_19 = ( T_3 ) F_17 ( V_19 ) ;
F_18 ( V_30 -> V_31 , 0 , V_19 ) ;
V_30 -> V_35 =
F_13 ( V_30 -> V_31 ,
F_7 ( char ,
& V_32 [ 1 ] ) ) ;
return ( ( T_5 ) V_19 ) ;
}
V_30 -> V_34 = 0 ;
V_30 -> V_35 = 0 ;
V_30 -> V_31 = NULL ;
return ( 0 ) ;
}
T_4
F_19 ( union V_20 * V_21 ,
T_5 V_28 ,
struct V_29 * V_30 )
{
T_1 * V_32 ;
T_4 V_36 ;
F_2 () ;
V_36 = V_28 ;
if ( V_30 -> V_35 ) {
V_32 = F_15 ( T_1 , V_21 , V_28 ) ;
V_32 [ 0 ] = ( T_1 ) V_30 -> V_34 ;
F_20 ( F_7 ( char , & V_32 [ 1 ] ) ,
V_30 -> V_31 ) ;
V_36 +=
( ( T_4 ) V_30 -> V_35 + 1 ) ;
}
return ( V_36 ) ;
}
T_6
F_21 ( struct V_37 * V_38 ,
struct V_39 * V_40 )
{
union V_41 * V_42 ;
T_6 V_43 ;
F_22 ( V_44 ) ;
V_43 = F_23 ( V_38 , V_45 ,
V_46 , & V_42 ) ;
if ( F_24 ( V_43 ) ) {
F_25 ( V_43 ) ;
}
V_43 = F_26 ( V_42 , V_40 ) ;
F_27 ( V_42 ) ;
F_25 ( V_43 ) ;
}
T_6
F_28 ( struct V_37 * V_38 ,
struct V_39 * V_40 )
{
union V_41 * V_42 ;
T_6 V_43 ;
F_22 ( V_47 ) ;
V_43 = F_23 ( V_38 , V_48 ,
V_49 , & V_42 ) ;
if ( F_24 ( V_43 ) ) {
F_25 ( V_43 ) ;
}
V_43 = F_29 ( V_42 , V_40 ) ;
F_27 ( V_42 ) ;
F_25 ( V_43 ) ;
}
T_6
F_30 ( struct V_37 * V_38 ,
struct V_39 * V_40 )
{
union V_41 * V_42 ;
T_6 V_43 ;
F_22 ( V_50 ) ;
V_43 = F_23 ( V_38 , V_51 ,
V_49 , & V_42 ) ;
if ( F_24 ( V_43 ) ) {
F_25 ( V_43 ) ;
}
V_43 = F_29 ( V_42 , V_40 ) ;
F_27 ( V_42 ) ;
F_25 ( V_43 ) ;
}
T_6
F_31 ( struct V_37 * V_38 ,
struct V_39 * V_40 )
{
union V_41 * V_42 ;
T_6 V_43 ;
F_22 ( V_52 ) ;
V_43 = F_23 ( V_38 , V_53 ,
V_49 , & V_42 ) ;
if ( F_24 ( V_43 ) ) {
F_25 ( V_43 ) ;
}
V_43 = F_29 ( V_42 , V_40 ) ;
F_27 ( V_42 ) ;
F_25 ( V_43 ) ;
}
T_6
F_32 ( T_7 V_54 ,
char * V_55 , struct V_39 * V_40 )
{
union V_41 * V_42 ;
T_6 V_43 ;
F_22 ( V_56 ) ;
V_43 =
F_23 ( F_7
( struct V_37 , V_54 ) , V_55 ,
V_49 , & V_42 ) ;
if ( F_24 ( V_43 ) ) {
F_25 ( V_43 ) ;
}
V_43 = F_29 ( V_42 , V_40 ) ;
F_27 ( V_42 ) ;
F_25 ( V_43 ) ;
}
T_6
F_33 ( struct V_37 * V_38 ,
struct V_39 * V_57 )
{
struct V_58 * V_59 ;
union V_41 * args [ 2 ] ;
T_6 V_43 ;
struct V_39 V_60 ;
F_22 ( V_61 ) ;
V_59 = F_34 ( sizeof( struct V_58 ) ) ;
if ( ! V_59 ) {
F_25 ( V_62 ) ;
}
V_59 -> V_63 = V_38 ;
V_59 -> V_64 = V_65 ;
V_59 -> V_66 = args ;
V_59 -> V_67 = V_68 ;
V_60 . V_69 = V_70 ;
V_43 = F_35 ( V_57 -> V_71 , & V_60 ) ;
if ( F_24 ( V_43 ) ) {
goto V_72;
}
args [ 0 ] = F_36 ( V_73 ) ;
if ( ! args [ 0 ] ) {
F_37 ( V_60 . V_71 ) ;
V_43 = V_62 ;
goto V_72;
}
args [ 0 ] -> V_60 . V_69 = ( T_3 ) V_60 . V_69 ;
args [ 0 ] -> V_60 . V_71 = V_60 . V_71 ;
args [ 0 ] -> V_74 . V_67 = V_75 ;
args [ 1 ] = NULL ;
V_43 = F_38 ( V_59 ) ;
F_27 ( args [ 0 ] ) ;
V_72:
F_37 ( V_59 ) ;
F_25 ( V_43 ) ;
}
