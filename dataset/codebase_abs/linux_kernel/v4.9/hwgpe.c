T_1 F_1 ( struct V_1 * V_2 )
{
return ( ( T_1 ) 1 <<
( V_2 -> V_3 -
V_2 -> V_4 -> V_5 ) ) ;
}
T_2
F_2 ( struct V_1 * V_2 , T_1 V_6 )
{
struct V_7 * V_8 ;
T_2 V_9 = V_10 ;
T_1 V_11 ;
T_1 V_12 ;
F_3 () ;
V_8 = V_2 -> V_4 ;
if ( ! V_8 ) {
return ( V_13 ) ;
}
V_9 = F_4 ( & V_11 , & V_8 -> V_14 ) ;
if ( F_5 ( V_9 ) ) {
return ( V_9 ) ;
}
V_12 = F_1 ( V_2 ) ;
switch ( V_6 ) {
case V_15 :
if ( ! ( V_12 & V_8 -> V_11 ) ) {
return ( V_16 ) ;
}
case V_17 :
F_6 ( V_11 , V_12 ) ;
break;
case V_18 :
F_7 ( V_11 , V_12 ) ;
break;
default:
F_8 ( ( V_19 , L_1 , V_6 ) ) ;
return ( V_16 ) ;
}
if ( ! ( V_12 & V_8 -> V_20 ) ) {
V_9 =
F_9 ( V_11 ,
& V_8 -> V_14 ) ;
}
return ( V_9 ) ;
}
T_2 F_10 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
T_2 V_9 ;
T_1 V_12 ;
F_3 () ;
V_8 = V_2 -> V_4 ;
if ( ! V_8 ) {
return ( V_13 ) ;
}
V_12 = F_1 ( V_2 ) ;
V_9 =
F_9 ( V_12 , & V_8 -> V_21 ) ;
return ( V_9 ) ;
}
T_2
F_11 ( struct V_1 * V_2 ,
T_3 * V_22 )
{
T_1 V_23 ;
T_1 V_12 ;
struct V_7 * V_8 ;
T_3 V_24 = 0 ;
T_2 V_9 ;
F_3 () ;
if ( ! V_22 ) {
return ( V_16 ) ;
}
if ( F_12 ( V_2 -> V_25 ) !=
V_26 ) {
V_24 |= V_27 ;
}
V_8 = V_2 -> V_4 ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 & V_8 -> V_28 ) {
V_24 |= V_29 ;
}
if ( V_12 & V_8 -> V_20 ) {
V_24 |= V_30 ;
}
if ( V_12 & V_8 -> V_31 ) {
V_24 |= V_32 ;
}
V_9 = F_4 ( & V_23 , & V_8 -> V_14 ) ;
if ( F_5 ( V_9 ) ) {
return ( V_9 ) ;
}
if ( V_12 & V_23 ) {
V_24 |= V_33 ;
}
V_9 = F_4 ( & V_23 , & V_8 -> V_21 ) ;
if ( F_5 ( V_9 ) ) {
return ( V_9 ) ;
}
if ( V_12 & V_23 ) {
V_24 |= V_34 ;
}
( * V_22 ) = V_24 ;
return ( V_10 ) ;
}
static T_2
F_13 ( T_4 V_11 ,
struct V_7 * V_8 )
{
T_2 V_9 ;
V_8 -> V_11 = V_11 ;
V_9 = F_9 ( V_11 , & V_8 -> V_14 ) ;
return ( V_9 ) ;
}
T_2
F_14 ( struct V_35 * V_36 ,
struct V_37 * V_38 , void * V_39 )
{
T_1 V_40 ;
T_2 V_9 ;
for ( V_40 = 0 ; V_40 < V_38 -> V_41 ; V_40 ++ ) {
V_9 =
F_13 ( 0x00 ,
& V_38 -> V_4 [ V_40 ] ) ;
if ( F_5 ( V_9 ) ) {
return ( V_9 ) ;
}
}
return ( V_10 ) ;
}
T_2
F_15 ( struct V_35 * V_36 ,
struct V_37 * V_38 , void * V_39 )
{
T_1 V_40 ;
T_2 V_9 ;
for ( V_40 = 0 ; V_40 < V_38 -> V_41 ; V_40 ++ ) {
V_9 =
F_9 ( 0xFF ,
& V_38 -> V_4 [ V_40 ] . V_21 ) ;
if ( F_5 ( V_9 ) ) {
return ( V_9 ) ;
}
}
return ( V_10 ) ;
}
T_2
F_16 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
void * V_39 )
{
T_1 V_40 ;
T_2 V_9 ;
struct V_7 * V_8 ;
T_4 V_11 ;
for ( V_40 = 0 ; V_40 < V_38 -> V_41 ; V_40 ++ ) {
V_8 = & V_38 -> V_4 [ V_40 ] ;
if ( ! V_8 -> V_28 ) {
continue;
}
V_11 = V_8 -> V_28 &
~ V_8 -> V_20 ;
V_9 =
F_13 ( V_11 , V_8 ) ;
if ( F_5 ( V_9 ) ) {
return ( V_9 ) ;
}
}
return ( V_10 ) ;
}
static T_2
F_17 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
void * V_39 )
{
T_1 V_40 ;
T_2 V_9 ;
struct V_7 * V_8 ;
for ( V_40 = 0 ; V_40 < V_38 -> V_41 ; V_40 ++ ) {
V_8 = & V_38 -> V_4 [ V_40 ] ;
V_9 =
F_13 ( V_8 -> V_31 ,
V_8 ) ;
if ( F_5 ( V_9 ) ) {
return ( V_9 ) ;
}
}
return ( V_10 ) ;
}
T_2 F_18 ( void )
{
T_2 V_9 ;
F_19 ( V_42 ) ;
V_9 = F_20 ( F_14 , NULL ) ;
V_9 = F_20 ( F_15 , NULL ) ;
F_21 ( V_9 ) ;
}
T_2 F_22 ( void )
{
T_2 V_9 ;
F_19 ( V_43 ) ;
V_9 = F_20 ( F_16 , NULL ) ;
F_21 ( V_9 ) ;
}
T_2 F_23 ( void )
{
T_2 V_9 ;
F_19 ( V_44 ) ;
V_9 = F_20 ( F_17 , NULL ) ;
F_21 ( V_9 ) ;
}
