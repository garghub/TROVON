static T_1
F_1 ( T_2 V_1 )
{
struct V_2 * V_3 ;
T_3 V_4 ;
T_4 V_5 ;
T_5 * V_6 ;
T_3 V_7 ;
int V_8 ;
V_3 = F_2 ( V_1 , sizeof( struct V_2 ) ) ;
if ( ! V_3 )
return V_9 ;
V_4 = V_3 -> V_4 ;
F_3 ( V_3 , sizeof( struct V_2 ) ) ;
if ( V_4 < sizeof( struct V_2 ) )
return V_10 ;
V_3 = F_2 ( V_1 , V_4 ) ;
if ( ! V_3 )
return V_9 ;
V_7 =
( T_3 ) ( ( V_3 -> V_4 -
sizeof( struct V_2 ) ) / sizeof( T_4 ) ) ;
V_6 =
F_4 ( T_5 , V_3 ) + sizeof( struct V_2 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ ) {
F_5 ( & V_5 , V_6 ) ;
if ( ! V_5 ) {
break;
}
V_6 += sizeof( T_4 ) ;
}
F_3 ( V_3 , V_4 ) ;
if ( V_8 < V_7 )
return V_11 ;
else
return V_12 ;
}
T_1 F_6 ( void )
{
T_1 V_13 ;
if ( V_14 ) {
V_15 = NULL ;
return ( V_12 ) ;
}
V_13 = F_7 ( V_16 ,
F_8 ( struct
V_2 ,
& V_15 ) ) ;
return V_13 ;
}
T_5 F_9 ( void )
{
if ( V_17 . V_18 >= 3 ) {
return ( TRUE ) ;
}
return ( FALSE ) ;
}
static void F_10 ( char * string , T_6 V_4 )
{
while ( V_4 && * string ) {
if ( ! F_11 ( * string ) ) {
* string = '?' ;
}
string ++ ;
V_4 -- ;
}
}
static void
F_12 ( struct V_2 * V_19 ,
struct V_2 * V_20 )
{
F_13 ( V_19 , V_20 , sizeof( struct V_2 ) ) ;
F_10 ( V_19 -> V_21 , V_22 ) ;
F_10 ( V_19 -> V_23 , V_24 ) ;
F_10 ( V_19 -> V_25 , V_26 ) ;
F_10 ( V_19 -> V_27 , V_22 ) ;
}
void
F_14 ( T_2 V_1 ,
struct V_2 * V_20 )
{
struct V_2 V_28 ;
if ( F_15 ( V_20 -> V_21 , V_29 ) ) {
F_16 ( ( V_30 , L_1 ,
V_20 -> V_21 , F_4 ( void , V_1 ) ,
V_20 -> V_4 ) ) ;
} else if ( F_15 ( V_20 -> V_21 , V_31 ) ) {
F_13 ( V_28 . V_23 ,
F_4 ( struct V_32 ,
V_20 ) -> V_23 , V_24 ) ;
F_10 ( V_28 . V_23 , V_24 ) ;
F_16 ( ( V_30 , L_2 ,
F_4 ( void , V_1 ) ,
( F_4 ( struct V_32 , V_20 ) ->
V_33 >
0 ) ? F_4 ( struct V_32 ,
V_20 ) -> V_4 : 20 ,
F_4 ( struct V_32 ,
V_20 ) -> V_33 ,
V_28 . V_23 ) ) ;
} else {
F_12 ( & V_28 , V_20 ) ;
F_16 ( ( V_30 ,
L_3 ,
V_28 . V_21 , F_4 ( void , V_1 ) ,
V_28 . V_4 , V_28 . V_33 ,
V_28 . V_23 , V_28 . V_25 ,
V_28 . V_34 ,
V_28 . V_27 ,
V_28 . V_35 ) ) ;
}
}
T_1 F_17 ( struct V_2 * V_3 , T_3 V_4 )
{
T_5 V_36 ;
V_36 = F_18 ( F_4 ( T_5 , V_3 ) , V_4 ) ;
if ( V_36 ) {
F_19 ( ( V_30 ,
L_4
L_5 ,
V_3 -> V_21 , V_3 -> V_36 ,
( T_5 ) ( V_3 -> V_36 - V_36 ) ) ) ;
#if ( V_37 )
return ( V_38 ) ;
#endif
}
return ( V_12 ) ;
}
T_5 F_18 ( T_5 * V_39 , T_3 V_4 )
{
T_5 V_40 = 0 ;
T_5 * V_41 = V_39 + V_4 ;
while ( V_39 < V_41 ) {
V_40 = ( T_5 ) ( V_40 + * ( V_39 ++ ) ) ;
}
return ( V_40 ) ;
}
void F_20 ( void )
{
if ( V_42 . V_4 != V_43 -> V_4 ||
V_42 . V_36 != V_43 -> V_36 ) {
F_21 ( ( V_30 ,
L_6
L_7 ) ) ;
F_14 ( 0 , & V_42 ) ;
F_14 ( 0 , V_43 ) ;
F_22 ( ( V_30 ,
L_8
L_9 ) ) ;
V_42 . V_4 = V_43 -> V_4 ;
V_42 . V_36 =
V_43 -> V_36 ;
}
}
struct V_2 * F_23 ( T_3 V_44 )
{
struct V_2 * V_45 ;
struct V_46 * V_47 ;
V_47 = & V_17 . V_48 [ V_44 ] ;
V_45 = F_24 ( V_47 -> V_4 ) ;
if ( ! V_45 ) {
F_22 ( ( V_30 , L_10 ,
V_47 -> V_4 ) ) ;
return ( NULL ) ;
}
F_13 ( V_45 , V_47 -> V_49 , V_47 -> V_4 ) ;
F_25 ( V_47 ) ;
V_47 -> V_49 = V_45 ;
V_47 -> V_50 = V_51 ;
F_16 ( ( V_30 ,
L_11 ,
V_45 -> V_4 ) ) ;
return ( V_45 ) ;
}
void
F_26 ( T_2 V_1 ,
char * V_21 , T_3 V_44 )
{
struct V_2 * V_3 ;
struct V_2 * V_52 ;
struct V_46 * V_47 ;
if ( ! V_1 ) {
F_22 ( ( V_30 ,
L_12 ,
V_21 ) ) ;
return;
}
V_3 = F_2 ( V_1 , sizeof( struct V_2 ) ) ;
if ( ! V_3 ) {
F_22 ( ( V_30 ,
L_13 ,
V_21 , F_4 ( void , V_1 ) ) ) ;
return;
}
if ( V_21 && ! F_15 ( V_3 -> V_21 , V_21 ) ) {
F_21 ( ( V_30 ,
L_14 ,
* F_4 ( T_3 , V_3 -> V_21 ) ,
V_21 ) ) ;
goto V_53;
}
V_47 = & V_17 . V_48 [ V_44 ] ;
V_47 -> V_1 = V_1 ;
V_47 -> V_49 = NULL ;
V_47 -> V_4 = V_3 -> V_4 ;
V_47 -> V_50 = V_54 ;
F_27 ( V_47 -> V_21 . V_55 , V_3 -> V_21 ) ;
V_52 = F_28 ( V_3 , V_47 ) ;
if ( ! V_52 ) {
V_52 = V_3 ;
}
F_14 ( V_47 -> V_1 , V_52 ) ;
if ( V_44 == V_56 ) {
F_29 ( V_52 -> V_33 ) ;
}
if ( V_52 != V_3 ) {
F_25 ( V_47 ) ;
}
V_53:
F_3 ( V_3 , sizeof( struct V_2 ) ) ;
}
static T_2
F_30 ( T_5 * V_6 , T_3 V_57 )
{
T_4 V_58 ;
if ( V_57 == sizeof( T_3 ) ) {
return ( ( T_2 )
( * F_4 ( T_3 , V_6 ) ) ) ;
} else {
F_5 ( & V_58 , V_6 ) ;
#if V_59 == 32
if ( V_58 > V_60 ) {
F_19 ( ( V_30 ,
L_15
L_16 ,
F_31 ( V_58 ) ) ) ;
}
#endif
return ( ( T_2 ) ( V_58 ) ) ;
}
}
T_1 T_7
F_32 ( T_2 V_61 )
{
struct V_32 * V_62 ;
T_3 V_57 ;
T_3 V_8 ;
T_3 V_7 ;
struct V_2 * V_3 ;
T_2 V_1 ;
T_2 V_63 ( V_64 ) ;
T_3 V_4 ;
T_5 * V_6 ;
T_1 V_13 ;
F_33 ( V_65 ) ;
V_62 = F_2 ( V_61 , sizeof( struct V_32 ) ) ;
if ( ! V_62 ) {
F_34 ( V_9 ) ;
}
F_14 ( V_61 ,
F_4 ( struct V_2 ,
V_62 ) ) ;
if ( V_62 -> V_33 > 1 && V_62 -> V_66
&& ! V_67 ) {
V_1 = ( T_2 ) V_62 -> V_66 ;
V_57 = sizeof( T_4 ) ;
V_64 = ( T_2 )
V_62 -> V_68 ;
} else {
V_1 = ( T_2 ) V_62 -> V_68 ;
V_57 = sizeof( T_3 ) ;
}
F_3 ( V_62 , sizeof( struct V_32 ) ) ;
if ( V_57 == sizeof( T_4 ) ) {
if ( F_1 ( V_1 ) == V_11 ) {
V_1 = V_64 ;
V_57 = sizeof( T_3 ) ;
F_35 ( ( V_30 , L_17
L_18 ) ) ;
}
}
V_3 = F_2 ( V_1 , sizeof( struct V_2 ) ) ;
if ( ! V_3 ) {
F_34 ( V_9 ) ;
}
F_14 ( V_1 , V_3 ) ;
V_4 = V_3 -> V_4 ;
F_3 ( V_3 , sizeof( struct V_2 ) ) ;
if ( V_4 < sizeof( struct V_2 ) ) {
F_21 ( ( V_30 ,
L_19 ,
V_4 ) ) ;
F_34 ( V_10 ) ;
}
V_3 = F_2 ( V_1 , V_4 ) ;
if ( ! V_3 ) {
F_34 ( V_9 ) ;
}
V_13 = F_17 ( V_3 , V_4 ) ;
if ( F_36 ( V_13 ) ) {
F_3 ( V_3 , V_4 ) ;
F_34 ( V_13 ) ;
}
V_7 = ( T_3 ) ( ( V_3 -> V_4 - sizeof( struct V_2 ) ) /
V_57 ) ;
V_6 =
F_4 ( T_5 , V_3 ) + sizeof( struct V_2 ) ;
V_17 . V_18 = 2 ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ ) {
if ( V_17 . V_18 >=
V_17 . V_69 ) {
V_13 = F_37 () ;
if ( F_36 ( V_13 ) ) {
F_35 ( ( V_30 ,
L_20 ,
( unsigned ) ( V_7 -
( V_17 .
V_18 -
2 ) ) ) ) ;
break;
}
}
V_17 . V_48 [ V_17 .
V_18 ] . V_1 =
F_30 ( V_6 , V_57 ) ;
V_6 += V_57 ;
V_17 . V_18 ++ ;
}
F_3 ( V_3 , V_4 ) ;
for ( V_8 = 2 ; V_8 < V_17 . V_18 ; V_8 ++ ) {
F_26 ( V_17 . V_48 [ V_8 ] .
V_1 , NULL , V_8 ) ;
if ( F_15
( & V_17 . V_48 [ V_8 ] . V_21 ,
V_70 ) ) {
F_38 ( V_8 ) ;
}
}
F_34 ( V_12 ) ;
}
