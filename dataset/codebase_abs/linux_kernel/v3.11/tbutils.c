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
return ( V_13 ) ;
}
T_5 F_9 ( void )
{
if ( V_17 . V_18 >= 3 ) {
return ( TRUE ) ;
}
return ( FALSE ) ;
}
void F_10 ( void )
{
if ( V_19 . V_4 != V_20 -> V_4 ||
V_19 . V_21 != V_20 -> V_21 ) {
F_11 ( ( V_22 ,
L_1
L_2 ) ) ;
F_12 ( 0 , & V_19 ) ;
F_12 ( 0 , V_20 ) ;
F_13 ( ( V_22 ,
L_3
L_4 ) ) ;
V_19 . V_4 = V_20 -> V_4 ;
V_19 . V_21 =
V_20 -> V_21 ;
}
}
struct V_2 * F_14 ( T_3 V_23 )
{
struct V_2 * V_24 ;
struct V_25 * V_26 ;
V_26 = & V_17 . V_27 [ V_23 ] ;
V_24 = F_15 ( V_26 -> V_4 ) ;
if ( ! V_24 ) {
F_13 ( ( V_22 , L_5 ,
V_26 -> V_4 ) ) ;
return ( NULL ) ;
}
F_16 ( V_24 , V_26 -> V_28 , V_26 -> V_4 ) ;
F_17 ( V_26 ) ;
V_26 -> V_28 = V_24 ;
V_26 -> V_29 = V_30 ;
F_18 ( ( V_22 ,
L_6 ,
V_24 -> V_4 ) ) ;
return ( V_24 ) ;
}
void
F_19 ( T_2 V_1 ,
char * V_31 , T_3 V_23 )
{
struct V_2 * V_3 ;
struct V_2 * V_32 ;
struct V_25 * V_26 ;
if ( ! V_1 ) {
F_13 ( ( V_22 ,
L_7 ,
V_31 ) ) ;
return;
}
V_3 = F_2 ( V_1 , sizeof( struct V_2 ) ) ;
if ( ! V_3 ) {
F_13 ( ( V_22 ,
L_8 ,
V_31 , F_4 ( void , V_1 ) ) ) ;
return;
}
if ( V_31 && ! F_20 ( V_3 -> V_31 , V_31 ) ) {
F_11 ( ( V_22 ,
L_9 ,
* F_4 ( T_3 , V_3 -> V_31 ) ,
V_31 ) ) ;
goto V_33;
}
V_26 = & V_17 . V_27 [ V_23 ] ;
V_26 -> V_1 = V_1 ;
V_26 -> V_28 = NULL ;
V_26 -> V_4 = V_3 -> V_4 ;
V_26 -> V_29 = V_34 ;
F_21 ( V_26 -> V_31 . V_35 , V_3 -> V_31 ) ;
V_32 = F_22 ( V_3 , V_26 ) ;
if ( ! V_32 ) {
V_32 = V_3 ;
}
F_12 ( V_26 -> V_1 , V_32 ) ;
if ( V_23 == V_36 ) {
F_23 ( V_32 -> V_37 ) ;
}
if ( V_32 != V_3 ) {
F_17 ( V_26 ) ;
}
V_33:
F_3 ( V_3 , sizeof( struct V_2 ) ) ;
}
static T_2
F_24 ( T_5 * V_6 , T_3 V_38 )
{
T_4 V_39 ;
if ( V_38 == sizeof( T_3 ) ) {
return ( ( T_2 )
( * F_4 ( T_3 , V_6 ) ) ) ;
} else {
F_5 ( & V_39 , V_6 ) ;
#if V_40 == 32
if ( V_39 > V_41 ) {
F_25 ( ( V_22 ,
L_10
L_11 ,
F_26 ( V_39 ) ) ) ;
}
#endif
return ( ( T_2 ) ( V_39 ) ) ;
}
}
T_1 T_6
F_27 ( T_2 V_42 )
{
struct V_43 * V_44 ;
T_3 V_38 ;
T_3 V_8 ;
T_3 V_7 ;
struct V_2 * V_3 ;
T_2 V_1 ;
T_2 V_45 ( V_46 ) ;
T_3 V_4 ;
T_5 * V_6 ;
T_1 V_13 ;
F_28 ( V_47 ) ;
V_44 = F_2 ( V_42 , sizeof( struct V_43 ) ) ;
if ( ! V_44 ) {
F_29 ( V_9 ) ;
}
F_12 ( V_42 ,
F_4 ( struct V_2 ,
V_44 ) ) ;
if ( V_44 -> V_37 > 1 && V_44 -> V_48
&& ! V_49 ) {
V_1 = ( T_2 ) V_44 -> V_48 ;
V_38 = sizeof( T_4 ) ;
V_46 = ( T_2 )
V_44 -> V_50 ;
} else {
V_1 = ( T_2 ) V_44 -> V_50 ;
V_38 = sizeof( T_3 ) ;
}
F_3 ( V_44 , sizeof( struct V_43 ) ) ;
if ( V_38 == sizeof( T_4 ) ) {
if ( F_1 ( V_1 ) == V_11 ) {
V_1 = V_46 ;
V_38 = sizeof( T_3 ) ;
F_30 ( ( V_22 , L_12
L_13 ) ) ;
}
}
V_3 = F_2 ( V_1 , sizeof( struct V_2 ) ) ;
if ( ! V_3 ) {
F_29 ( V_9 ) ;
}
F_12 ( V_1 , V_3 ) ;
V_4 = V_3 -> V_4 ;
F_3 ( V_3 , sizeof( struct V_2 ) ) ;
if ( V_4 < sizeof( struct V_2 ) ) {
F_11 ( ( V_22 ,
L_14 ,
V_4 ) ) ;
F_29 ( V_10 ) ;
}
V_3 = F_2 ( V_1 , V_4 ) ;
if ( ! V_3 ) {
F_29 ( V_9 ) ;
}
V_13 = F_31 ( V_3 , V_4 ) ;
if ( F_32 ( V_13 ) ) {
F_3 ( V_3 , V_4 ) ;
F_29 ( V_13 ) ;
}
V_7 = ( T_3 ) ( ( V_3 -> V_4 - sizeof( struct V_2 ) ) /
V_38 ) ;
V_6 =
F_4 ( T_5 , V_3 ) + sizeof( struct V_2 ) ;
V_17 . V_18 = 2 ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ ) {
if ( V_17 . V_18 >=
V_17 . V_51 ) {
V_13 = F_33 () ;
if ( F_32 ( V_13 ) ) {
F_30 ( ( V_22 ,
L_15 ,
( unsigned ) ( V_7 -
( V_17 .
V_18 -
2 ) ) ) ) ;
break;
}
}
V_17 . V_27 [ V_17 .
V_18 ] . V_1 =
F_24 ( V_6 , V_38 ) ;
V_6 += V_38 ;
V_17 . V_18 ++ ;
}
F_3 ( V_3 , V_4 ) ;
for ( V_8 = 2 ; V_8 < V_17 . V_18 ; V_8 ++ ) {
F_19 ( V_17 . V_27 [ V_8 ] .
V_1 , NULL , V_8 ) ;
if ( F_20
( & V_17 . V_27 [ V_8 ] . V_31 ,
V_52 ) ) {
F_34 ( V_8 ) ;
}
}
F_29 ( V_12 ) ;
}
