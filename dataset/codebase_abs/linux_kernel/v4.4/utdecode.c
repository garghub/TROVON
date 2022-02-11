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
F_6 ( V_15 ) ;
if ( ! V_14 ) {
F_7 ( ( V_16 , L_6 ) ) ;
F_8 ( L_7 ) ;
}
if ( ( F_9 ( V_14 ) != V_17 ) &&
( F_9 ( V_14 ) != V_18 ) ) {
F_7 ( ( V_16 ,
L_8 ,
F_9 ( V_14 ) ,
F_10 ( V_14 ) ,
V_14 ) ) ;
F_8 ( L_9 ) ;
}
F_8 ( F_4 ( V_14 -> V_19 . type ) ) ;
}
char * F_11 ( void * V_20 )
{
struct V_21 * V_22 = (struct V_21 * ) V_20 ;
if ( ! V_20 ) {
return ( L_10 ) ;
}
if ( ( V_20 == V_23 ) || ( V_20 == V_24 ) ) {
return ( L_11 ) ;
}
if ( F_9 ( V_22 ) != V_18 ) {
return ( L_12 ) ;
}
F_12 ( V_22 -> V_25 . V_26 ) ;
return ( V_22 -> V_25 . V_26 ) ;
}
char * F_10 ( void * V_20 )
{
if ( ! V_20 ) {
return ( L_13 ) ;
}
if ( F_9 ( V_20 ) > V_27 ) {
return ( L_14 ) ;
}
return ( F_2 ( char ,
V_28 [ F_9
( V_20 ) ] ) ) ;
}
const char * F_13 ( union V_13 * V_20 )
{
if ( ! V_20 ) {
return ( L_15 ) ;
}
if ( F_9 ( V_20 ) != V_17 ) {
return ( L_16 ) ;
}
if ( V_20 -> V_19 . type != V_29 ) {
return ( L_17 ) ;
}
if ( V_20 -> V_30 . V_31 > V_32 ) {
return ( L_18 ) ;
}
return ( V_33 [ V_20 -> V_30 . V_31 ] ) ;
}
char * F_14 ( T_2 V_34 )
{
if ( V_34 > V_35 ) {
return ( L_19 ) ;
}
return ( V_36 [ V_34 ] ) ;
}
const char * F_15 ( T_2 V_37 , T_3 type )
{
if ( V_37 <= V_38 ) {
return ( V_39 [ V_37 ] ) ;
}
if ( V_37 <= V_40 ) {
return ( L_20 ) ;
}
if ( V_37 <= 0x83 ) {
switch ( type ) {
case V_41 :
case V_42 :
return ( V_43 [ V_37 - 0x80 ] ) ;
case V_44 :
return ( V_45 [ V_37 - 0x80 ] ) ;
case V_46 :
return ( V_47 [ V_37 - 0x80 ] ) ;
default:
return ( L_21 ) ;
}
}
if ( V_37 <= V_48 ) {
return ( L_22 ) ;
}
return ( L_23 ) ;
}
T_1 F_16 ( T_3 type )
{
if ( type > V_49 ) {
return ( FALSE ) ;
}
return ( TRUE ) ;
}
