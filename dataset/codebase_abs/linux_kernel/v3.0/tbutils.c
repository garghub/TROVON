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
V_13 = F_7 ( V_14 ,
F_8 ( struct
V_2 ,
& V_15 ) ) ;
return V_13 ;
}
T_5 F_9 ( void )
{
if ( V_16 . V_17 >= 3 ) {
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
F_12 ( struct V_2 * V_18 ,
struct V_2 * V_19 )
{
F_13 ( V_18 , V_19 , sizeof( struct V_2 ) ) ;
F_10 ( V_18 -> V_20 , V_21 ) ;
F_10 ( V_18 -> V_22 , V_23 ) ;
F_10 ( V_18 -> V_24 , V_25 ) ;
F_10 ( V_18 -> V_26 , V_21 ) ;
}
void
F_14 ( T_2 V_1 ,
struct V_2 * V_19 )
{
struct V_2 V_27 ;
if ( F_15 ( V_19 -> V_20 , V_28 ) ) {
F_16 ( ( V_29 , L_1 ,
V_19 -> V_20 , F_4 ( void , V_1 ) ,
V_19 -> V_4 ) ) ;
} else if ( F_15 ( V_19 -> V_20 , V_30 ) ) {
F_13 ( V_27 . V_22 ,
F_4 ( struct V_31 ,
V_19 ) -> V_22 , V_23 ) ;
F_10 ( V_27 . V_22 , V_23 ) ;
F_16 ( ( V_29 , L_2 ,
F_4 ( void , V_1 ) ,
( F_4 ( struct V_31 , V_19 ) ->
V_32 >
0 ) ? F_4 ( struct V_31 ,
V_19 ) -> V_4 : 20 ,
F_4 ( struct V_31 ,
V_19 ) -> V_32 ,
V_27 . V_22 ) ) ;
} else {
F_12 ( & V_27 , V_19 ) ;
F_16 ( ( V_29 ,
L_3 ,
V_27 . V_20 , F_4 ( void , V_1 ) ,
V_27 . V_4 , V_27 . V_32 ,
V_27 . V_22 , V_27 . V_24 ,
V_27 . V_33 ,
V_27 . V_26 ,
V_27 . V_34 ) ) ;
}
}
T_1 F_17 ( struct V_2 * V_3 , T_3 V_4 )
{
T_5 V_35 ;
V_35 = F_18 ( F_4 ( T_5 , V_3 ) , V_4 ) ;
if ( V_35 ) {
F_19 ( ( V_29 ,
L_4 ,
V_3 -> V_20 , V_3 -> V_35 ,
( T_5 ) ( V_3 -> V_35 - V_35 ) ) ) ;
#if ( V_36 )
return ( V_37 ) ;
#endif
}
return ( V_12 ) ;
}
T_5 F_18 ( T_5 * V_38 , T_3 V_4 )
{
T_5 V_39 = 0 ;
T_5 * V_40 = V_38 + V_4 ;
while ( V_38 < V_40 ) {
V_39 = ( T_5 ) ( V_39 + * ( V_38 ++ ) ) ;
}
return V_39 ;
}
void F_20 ( void )
{
if ( V_41 . V_4 != V_42 -> V_4 ||
V_41 . V_35 != V_42 -> V_35 ) {
F_21 ( ( V_29 ,
L_5 ) ) ;
F_14 ( 0 , & V_41 ) ;
F_14 ( 0 , V_42 ) ;
F_21 ( ( V_29 ,
L_6
L_7 ) ) ;
V_41 . V_4 = V_42 -> V_4 ;
V_41 . V_35 =
V_42 -> V_35 ;
}
}
struct V_2 * F_22 ( T_3 V_43 )
{
struct V_2 * V_44 ;
struct V_45 * V_46 ;
V_46 = & V_16 . V_47 [ V_43 ] ;
V_44 = F_23 ( V_46 -> V_4 ) ;
if ( ! V_44 ) {
F_21 ( ( V_29 , L_8 ,
V_46 -> V_4 ) ) ;
return ( NULL ) ;
}
F_13 ( V_44 , V_46 -> V_48 , V_46 -> V_4 ) ;
F_24 ( V_46 ) ;
V_46 -> V_48 = V_44 ;
V_46 -> V_49 = V_50 ;
F_16 ( ( V_29 ,
L_9 ,
V_44 -> V_4 ) ) ;
return ( V_44 ) ;
}
void
F_25 ( T_2 V_1 ,
char * V_20 , T_3 V_43 )
{
T_5 V_49 ;
T_1 V_13 ;
struct V_2 * V_51 ;
struct V_2 * V_52 ;
struct V_2 * V_53 = NULL ;
if ( ! V_1 ) {
F_21 ( ( V_29 ,
L_10 ,
V_20 ) ) ;
return;
}
V_52 =
F_2 ( V_1 , sizeof( struct V_2 ) ) ;
if ( ! V_52 ) {
return;
}
if ( V_20 && ! F_15 ( V_52 -> V_20 , V_20 ) ) {
F_21 ( ( V_29 ,
L_11 ,
* F_4 ( T_3 , V_52 -> V_20 ) ,
V_20 ) ) ;
goto V_54;
}
V_13 = F_26 ( V_52 , & V_53 ) ;
if ( F_27 ( V_13 ) && V_53 ) {
F_16 ( ( V_29 ,
L_12 ,
V_52 -> V_20 , F_4 ( void ,
V_1 ) ) ) ;
V_16 . V_47 [ V_43 ] . V_48 =
V_53 ;
V_1 = F_28 ( V_53 ) ;
V_51 = V_53 ;
V_49 = V_55 ;
} else {
V_51 = V_52 ;
V_49 = V_56 ;
}
V_16 . V_47 [ V_43 ] . V_1 = V_1 ;
V_16 . V_47 [ V_43 ] . V_4 =
V_51 -> V_4 ;
V_16 . V_47 [ V_43 ] . V_49 = V_49 ;
F_29 ( &
( V_16 . V_47 [ V_43 ] .
V_20 ) , V_51 -> V_20 ) ;
F_14 ( V_1 , V_51 ) ;
if ( V_43 == V_57 ) {
F_30 ( V_51 -> V_32 ) ;
}
V_54:
F_3 ( V_52 , sizeof( struct V_2 ) ) ;
}
static T_2
F_31 ( T_5 * V_6 , T_3 V_58 )
{
T_4 V_59 ;
if ( V_58 == sizeof( T_3 ) ) {
return ( ( T_2 )
( * F_4 ( T_3 , V_6 ) ) ) ;
} else {
F_5 ( & V_59 , V_6 ) ;
#if V_60 == 32
if ( V_59 > V_61 ) {
F_19 ( ( V_29 ,
L_13
L_14 ,
F_32 ( V_59 ) ) ) ;
}
#endif
return ( ( T_2 ) ( V_59 ) ) ;
}
}
T_1 T_7
F_33 ( T_2 V_62 )
{
struct V_31 * V_63 ;
T_3 V_58 ;
T_3 V_8 ;
T_3 V_7 ;
struct V_2 * V_3 ;
T_2 V_1 ;
T_2 V_64 ( V_65 ) ;
T_3 V_4 ;
T_5 * V_6 ;
T_1 V_13 ;
F_34 ( V_66 ) ;
V_63 = F_2 ( V_62 , sizeof( struct V_31 ) ) ;
if ( ! V_63 ) {
F_35 ( V_9 ) ;
}
F_14 ( V_62 ,
F_4 ( struct V_2 ,
V_63 ) ) ;
if ( V_63 -> V_32 > 1 && V_63 -> V_67
&& ! V_68 ) {
V_1 = ( T_2 ) V_63 -> V_67 ;
V_58 = sizeof( T_4 ) ;
V_65 = ( T_2 )
V_63 -> V_69 ;
} else {
V_1 = ( T_2 ) V_63 -> V_69 ;
V_58 = sizeof( T_3 ) ;
}
F_3 ( V_63 , sizeof( struct V_31 ) ) ;
if ( V_58 == sizeof( T_4 ) ) {
if ( F_1 ( V_1 ) == V_11 ) {
V_1 = V_65 ;
V_58 = sizeof( T_3 ) ;
F_19 ( ( V_29 , L_15
L_16 ) ) ;
}
}
V_3 = F_2 ( V_1 , sizeof( struct V_2 ) ) ;
if ( ! V_3 ) {
F_35 ( V_9 ) ;
}
F_14 ( V_1 , V_3 ) ;
V_4 = V_3 -> V_4 ;
F_3 ( V_3 , sizeof( struct V_2 ) ) ;
if ( V_4 < sizeof( struct V_2 ) ) {
F_21 ( ( V_29 , L_17 ,
V_4 ) ) ;
F_35 ( V_10 ) ;
}
V_3 = F_2 ( V_1 , V_4 ) ;
if ( ! V_3 ) {
F_35 ( V_9 ) ;
}
V_13 = F_17 ( V_3 , V_4 ) ;
if ( F_36 ( V_13 ) ) {
F_3 ( V_3 , V_4 ) ;
F_35 ( V_13 ) ;
}
V_7 = ( T_3 ) ( ( V_3 -> V_4 - sizeof( struct V_2 ) ) /
V_58 ) ;
V_6 =
F_4 ( T_5 , V_3 ) + sizeof( struct V_2 ) ;
V_16 . V_17 = 2 ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ ) {
if ( V_16 . V_17 >=
V_16 . V_70 ) {
V_13 = F_37 () ;
if ( F_36 ( V_13 ) ) {
F_19 ( ( V_29 ,
L_18 ,
( unsigned ) ( V_7 -
( V_16 .
V_17 -
2 ) ) ) ) ;
break;
}
}
V_16 . V_47 [ V_16 .
V_17 ] . V_1 =
F_31 ( V_6 , V_58 ) ;
V_6 += V_58 ;
V_16 . V_17 ++ ;
}
F_3 ( V_3 , V_4 ) ;
for ( V_8 = 2 ; V_8 < V_16 . V_17 ; V_8 ++ ) {
F_25 ( V_16 . V_47 [ V_8 ] .
V_1 , NULL , V_8 ) ;
if ( F_15
( & V_16 . V_47 [ V_8 ] . V_20 ,
V_71 ) ) {
F_38 ( V_8 ) ;
}
}
F_35 ( V_12 ) ;
}
