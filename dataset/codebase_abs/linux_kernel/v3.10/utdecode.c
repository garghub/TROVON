char F_1 ( T_1 integer , T_2 V_1 )
{
return ( V_2 [ ( integer >> V_1 ) & 0xF ] ) ;
}
char * F_2 ( T_3 V_3 )
{
if ( V_3 >= V_4 ) {
return ( L_1 ) ;
} else if ( V_3 == V_5 ) {
return ( L_2 ) ;
} else if ( V_3 == V_6 ) {
return ( L_3 ) ;
} else if ( V_3 >= V_7 ) {
return ( L_4 ) ;
}
return ( F_3 ( char , V_8 [ V_3 ] ) ) ;
}
char * F_4 ( T_2 V_9 )
{
if ( V_9 > V_10 ) {
return ( L_5 ) ;
}
return ( F_3 ( char , V_11 [ V_9 ] ) ) ;
}
char * F_5 ( T_4 type )
{
if ( type > V_12 ) {
return ( F_3 ( char , V_13 ) ) ;
}
return ( F_3 ( char , V_14 [ type ] ) ) ;
}
char * F_6 ( union V_15 * V_16 )
{
if ( ! V_16 ) {
return ( L_6 ) ;
}
return ( F_5 ( V_16 -> V_17 . type ) ) ;
}
char * F_7 ( void * V_18 )
{
struct V_19 * V_20 = (struct V_19 * ) V_18 ;
if ( ! V_18 ) {
return ( L_7 ) ;
}
if ( ( V_18 == V_21 ) || ( V_18 == V_22 ) ) {
return ( L_8 ) ;
}
if ( F_8 ( V_20 ) != V_23 ) {
return ( L_9 ) ;
}
F_9 ( V_20 -> V_24 . V_25 ) ;
return ( V_20 -> V_24 . V_25 ) ;
}
char * F_10 ( void * V_18 )
{
if ( ! V_18 ) {
return ( L_10 ) ;
}
if ( F_8 ( V_18 ) > V_26 ) {
return ( L_11 ) ;
}
return ( F_3 ( char ,
V_27 [ F_8
( V_18 ) ] ) ) ;
}
const char * F_11 ( union V_15 * V_18 )
{
if ( ! V_18 ) {
return ( L_12 ) ;
}
if ( F_8 ( V_18 ) != V_28 ) {
return ( L_13 ) ;
}
if ( V_18 -> V_17 . type != V_29 ) {
return ( L_14 ) ;
}
if ( V_18 -> V_30 . V_31 > V_32 ) {
return ( L_15 ) ;
}
return ( V_33 [ V_18 -> V_30 . V_31 ] ) ;
}
char * F_12 ( T_2 V_34 )
{
if ( V_34 > V_35 ) {
return ( L_16 ) ;
}
return ( V_36 [ V_34 ] ) ;
}
const char * F_13 ( T_2 V_37 )
{
if ( V_37 <= V_38 ) {
return ( V_39 [ V_37 ] ) ;
} else if ( V_37 <= V_40 ) {
return ( L_17 ) ;
} else if ( V_37 <= V_41 ) {
return ( L_18 ) ;
} else {
return ( L_19 ) ;
}
}
T_3 F_14 ( T_4 type )
{
if ( type > V_42 ) {
return ( FALSE ) ;
}
return ( TRUE ) ;
}
