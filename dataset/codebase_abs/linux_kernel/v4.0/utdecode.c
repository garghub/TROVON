char * F_1 ( T_1 V_1 )
{
if ( V_1 >= V_2 ) {
return ( L_1 ) ;
} else if ( V_1 == V_3 ) {
return ( L_2 ) ;
} else if ( V_1 == V_4 ) {
return ( L_3 ) ;
} else if ( V_1 >= V_5 ) {
return ( L_4 ) ;
}
return ( F_2 ( char , V_6 [ V_1 ] ) ) ;
}
char * F_3 ( T_2 V_7 )
{
if ( V_7 > V_8 ) {
return ( L_5 ) ;
}
return ( F_2 ( char , V_9 [ V_7 ] ) ) ;
}
char * F_4 ( T_3 type )
{
if ( type > V_10 ) {
return ( F_2 ( char , V_11 ) ) ;
}
return ( F_2 ( char , V_12 [ type ] ) ) ;
}
char * F_5 ( union V_13 * V_14 )
{
if ( ! V_14 ) {
return ( L_6 ) ;
}
return ( F_4 ( V_14 -> V_15 . type ) ) ;
}
char * F_6 ( void * V_16 )
{
struct V_17 * V_18 = (struct V_17 * ) V_16 ;
if ( ! V_16 ) {
return ( L_7 ) ;
}
if ( ( V_16 == V_19 ) || ( V_16 == V_20 ) ) {
return ( L_8 ) ;
}
if ( F_7 ( V_18 ) != V_21 ) {
return ( L_9 ) ;
}
F_8 ( V_18 -> V_22 . V_23 ) ;
return ( V_18 -> V_22 . V_23 ) ;
}
char * F_9 ( void * V_16 )
{
if ( ! V_16 ) {
return ( L_10 ) ;
}
if ( F_7 ( V_16 ) > V_24 ) {
return ( L_11 ) ;
}
return ( F_2 ( char ,
V_25 [ F_7
( V_16 ) ] ) ) ;
}
const char * F_10 ( union V_13 * V_16 )
{
if ( ! V_16 ) {
return ( L_12 ) ;
}
if ( F_7 ( V_16 ) != V_26 ) {
return ( L_13 ) ;
}
if ( V_16 -> V_15 . type != V_27 ) {
return ( L_14 ) ;
}
if ( V_16 -> V_28 . V_29 > V_30 ) {
return ( L_15 ) ;
}
return ( V_31 [ V_16 -> V_28 . V_29 ] ) ;
}
char * F_11 ( T_2 V_32 )
{
if ( V_32 > V_33 ) {
return ( L_16 ) ;
}
return ( V_34 [ V_32 ] ) ;
}
const char * F_12 ( T_2 V_35 , T_3 type )
{
if ( V_35 <= V_36 ) {
return ( V_37 [ V_35 ] ) ;
}
if ( V_35 <= V_38 ) {
return ( L_17 ) ;
}
if ( V_35 <= 0x83 ) {
switch ( type ) {
case V_39 :
case V_40 :
return ( V_41 [ V_35 - 0x80 ] ) ;
case V_42 :
return ( V_43 [ V_35 - 0x80 ] ) ;
case V_44 :
return ( V_45 [ V_35 - 0x80 ] ) ;
default:
return ( L_18 ) ;
}
}
if ( V_35 <= V_46 ) {
return ( L_19 ) ;
}
return ( L_20 ) ;
}
T_1 F_13 ( T_3 type )
{
if ( type > V_47 ) {
return ( FALSE ) ;
}
return ( TRUE ) ;
}
