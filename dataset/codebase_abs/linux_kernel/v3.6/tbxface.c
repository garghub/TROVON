T_1 F_1 ( T_2 V_1 )
{
V_2 . V_3 = V_1 ;
V_2 . V_4 = V_5 ;
return ( F_2 () ) ;
}
T_1 T_3
F_3 ( struct V_6 * V_7 ,
T_2 V_1 , T_4 V_8 )
{
T_5 V_9 ;
T_1 V_10 ;
F_4 ( F_3 ) ;
if ( ! V_7 ) {
V_10 = F_1 ( V_1 ) ;
if ( F_5 ( V_10 ) ) {
F_6 ( V_10 ) ;
}
} else {
F_7 ( V_7 , 0 ,
( V_11 ) V_1 *
sizeof( struct V_6 ) ) ;
V_2 . V_12 = V_7 ;
V_2 . V_3 = V_1 ;
V_2 . V_4 = V_13 ;
if ( V_8 ) {
V_2 . V_4 |=
V_5 ;
}
}
V_9 = F_8 () ;
if ( ! V_9 ) {
F_6 ( V_14 ) ;
}
V_10 = F_9 ( V_9 ) ;
F_6 ( V_10 ) ;
}
T_1 F_10 ( void )
{
struct V_6 * V_12 ;
V_11 V_15 ;
V_11 V_16 ;
F_4 ( F_10 ) ;
if ( V_2 . V_4 & V_17 ) {
F_6 ( V_18 ) ;
}
V_16 = ( V_11 )
V_2 . V_19 *
sizeof( struct V_6 ) ;
V_15 = V_16 +
( V_20 * sizeof( struct V_6 ) ) ;
V_12 = F_11 ( V_15 ) ;
if ( ! V_12 ) {
F_6 ( V_21 ) ;
}
F_12 ( V_12 , V_2 . V_12 , V_16 ) ;
V_2 . V_12 = V_12 ;
V_2 . V_3 =
V_2 . V_19 +
V_20 ;
V_2 . V_4 =
V_17 | V_5 ;
F_6 ( V_22 ) ;
}
T_1
F_13 ( char * V_23 ,
T_2 V_24 , struct V_25 * V_26 )
{
T_2 V_27 ;
T_2 V_28 ;
struct V_25 * V_29 ;
if ( ! V_23 || ! V_26 ) {
return ( V_30 ) ;
}
for ( V_27 = 0 , V_28 = 0 ; V_27 < V_2 . V_19 ;
V_27 ++ ) {
if ( ! F_14
( & ( V_2 . V_12 [ V_27 ] . V_23 ) ,
V_23 ) ) {
continue;
}
if ( ++ V_28 < V_24 ) {
continue;
}
if ( ! V_2 . V_12 [ V_27 ] . V_31 ) {
if ( ( V_2 . V_12 [ V_27 ] . V_4 &
V_32 ) ==
V_33 ) {
V_29 =
F_15 ( V_2 .
V_12 [ V_27 ] . V_34 ,
sizeof( struct
V_25 ) ) ;
if ( ! V_29 ) {
return V_21 ;
}
F_12 ( V_26 , V_29 ,
sizeof( struct V_25 ) ) ;
F_16 ( V_29 ,
sizeof( struct
V_25 ) ) ;
} else {
return V_14 ;
}
} else {
F_12 ( V_26 ,
V_2 . V_12 [ V_27 ] . V_31 ,
sizeof( struct V_25 ) ) ;
}
return ( V_22 ) ;
}
return ( V_14 ) ;
}
T_1 F_17 ( T_6 V_35 )
{
int V_27 ;
T_1 V_10 = V_36 ;
F_4 ( F_17 ) ;
for ( V_27 = 0 ; V_27 < V_2 . V_19 ; ++ V_27 ) {
if ( V_35 != V_2 . V_12 [ V_27 ] . V_37 ) {
continue;
}
F_18 ( V_27 ) ;
V_10 = F_19 ( V_27 ) ;
F_20 ( V_27 , FALSE ) ;
break;
}
F_6 ( V_10 ) ;
}
T_1
F_21 ( char * V_23 ,
T_2 V_24 , struct V_25 * * V_38 ,
V_11 * V_39 )
{
T_2 V_27 ;
T_2 V_28 ;
T_1 V_10 ;
if ( ! V_23 || ! V_38 ) {
return ( V_30 ) ;
}
for ( V_27 = 0 , V_28 = 0 ; V_27 < V_2 . V_19 ;
V_27 ++ ) {
if ( ! F_14
( & ( V_2 . V_12 [ V_27 ] . V_23 ) ,
V_23 ) ) {
continue;
}
if ( ++ V_28 < V_24 ) {
continue;
}
V_10 =
F_22 ( & V_2 . V_12 [ V_27 ] ) ;
if ( F_23 ( V_10 ) ) {
* V_38 = V_2 . V_12 [ V_27 ] . V_31 ;
* V_39 = V_2 . V_12 [ V_27 ] . V_40 ;
}
if ( ! V_41 ) {
V_2 . V_12 [ V_27 ] . V_31 = NULL ;
}
return ( V_10 ) ;
}
return ( V_14 ) ;
}
T_1
F_24 ( char * V_23 ,
T_2 V_24 , struct V_25 * * V_38 )
{
V_11 V_39 ;
return F_21 ( V_23 ,
V_24 , V_38 , & V_39 ) ;
}
T_1
F_25 ( T_2 V_42 , struct V_25 * * V_43 )
{
T_1 V_10 ;
F_4 ( F_25 ) ;
if ( ! V_43 ) {
F_6 ( V_30 ) ;
}
( void ) F_26 ( V_44 ) ;
if ( V_42 >= V_2 . V_19 ) {
( void ) F_27 ( V_44 ) ;
F_6 ( V_30 ) ;
}
if ( ! V_2 . V_12 [ V_42 ] . V_31 ) {
V_10 =
F_22 ( & V_2 .
V_12 [ V_42 ] ) ;
if ( F_5 ( V_10 ) ) {
( void ) F_27 ( V_44 ) ;
F_6 ( V_10 ) ;
}
}
* V_43 = V_2 . V_12 [ V_42 ] . V_31 ;
( void ) F_27 ( V_44 ) ;
F_6 ( V_22 ) ;
}
T_1
F_28 ( T_7 V_45 , void * V_46 )
{
T_1 V_10 ;
F_4 ( F_28 ) ;
if ( ! V_45 ) {
F_6 ( V_30 ) ;
}
V_10 = F_26 ( V_47 ) ;
if ( F_5 ( V_10 ) ) {
F_6 ( V_10 ) ;
}
if ( V_48 ) {
V_10 = V_49 ;
goto V_50;
}
V_48 = V_45 ;
V_51 = V_46 ;
V_50:
( void ) F_27 ( V_47 ) ;
F_6 ( V_10 ) ;
}
T_1 F_29 ( T_7 V_45 )
{
T_1 V_10 ;
F_4 ( F_29 ) ;
V_10 = F_26 ( V_47 ) ;
if ( F_5 ( V_10 ) ) {
F_6 ( V_10 ) ;
}
if ( ! V_45 || V_45 != V_48 ) {
V_10 = V_30 ;
goto V_50;
}
V_48 = NULL ;
V_50:
( void ) F_27 ( V_47 ) ;
F_6 ( V_10 ) ;
}
