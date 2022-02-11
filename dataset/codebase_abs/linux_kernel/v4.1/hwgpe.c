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
T_2 V_9 ;
T_1 V_10 ;
T_1 V_11 ;
F_3 () ;
V_8 = V_2 -> V_4 ;
if ( ! V_8 ) {
return ( V_12 ) ;
}
V_9 = F_4 ( & V_10 , & V_8 -> V_13 ) ;
if ( F_5 ( V_9 ) ) {
return ( V_9 ) ;
}
V_11 = F_1 ( V_2 ) ;
switch ( V_6 ) {
case V_14 :
if ( ! ( V_11 & V_8 -> V_10 ) ) {
return ( V_15 ) ;
}
case V_16 :
F_6 ( V_10 , V_11 ) ;
break;
case V_17 :
F_7 ( V_10 , V_11 ) ;
break;
default:
F_8 ( ( V_18 , L_1 , V_6 ) ) ;
return ( V_15 ) ;
}
V_9 = F_9 ( V_10 , & V_8 -> V_13 ) ;
return ( V_9 ) ;
}
T_2 F_10 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
T_2 V_9 ;
T_1 V_11 ;
F_3 () ;
V_8 = V_2 -> V_4 ;
if ( ! V_8 ) {
return ( V_12 ) ;
}
V_11 = F_1 ( V_2 ) ;
V_9 = F_9 ( V_11 ,
& V_8 -> V_19 ) ;
return ( V_9 ) ;
}
T_2
F_11 ( struct V_1 * V_2 ,
T_3 * V_20 )
{
T_1 V_21 ;
T_1 V_11 ;
struct V_7 * V_8 ;
T_3 V_22 = 0 ;
T_2 V_9 ;
F_3 () ;
if ( ! V_20 ) {
return ( V_15 ) ;
}
if ( F_12 ( V_2 -> V_23 ) !=
V_24 ) {
V_22 |= V_25 ;
}
V_8 = V_2 -> V_4 ;
V_11 = F_1 ( V_2 ) ;
if ( V_11 & V_8 -> V_26 ) {
V_22 |= V_27 ;
}
if ( V_11 & V_8 -> V_28 ) {
V_22 |= V_29 ;
}
V_9 = F_4 ( & V_21 , & V_8 -> V_13 ) ;
if ( F_5 ( V_9 ) ) {
return ( V_9 ) ;
}
if ( V_11 & V_21 ) {
V_22 |= V_30 ;
}
V_9 = F_4 ( & V_21 , & V_8 -> V_19 ) ;
if ( F_5 ( V_9 ) ) {
return ( V_9 ) ;
}
if ( V_11 & V_21 ) {
V_22 |= V_31 ;
}
( * V_20 ) = V_22 ;
return ( V_32 ) ;
}
static T_2
F_13 ( T_4 V_10 ,
struct V_7 * V_8 )
{
T_2 V_9 ;
V_8 -> V_10 = V_10 ;
V_9 = F_9 ( V_10 , & V_8 -> V_13 ) ;
return ( V_9 ) ;
}
T_2
F_14 ( struct V_33 * V_34 ,
struct V_35 * V_36 , void * V_37 )
{
T_1 V_38 ;
T_2 V_9 ;
for ( V_38 = 0 ; V_38 < V_36 -> V_39 ; V_38 ++ ) {
V_9 =
F_13 ( 0x00 ,
& V_36 -> V_4 [ V_38 ] ) ;
if ( F_5 ( V_9 ) ) {
return ( V_9 ) ;
}
}
return ( V_32 ) ;
}
T_2
F_15 ( struct V_33 * V_34 ,
struct V_35 * V_36 , void * V_37 )
{
T_1 V_38 ;
T_2 V_9 ;
for ( V_38 = 0 ; V_38 < V_36 -> V_39 ; V_38 ++ ) {
V_9 =
F_9 ( 0xFF ,
& V_36 -> V_4 [ V_38 ] . V_19 ) ;
if ( F_5 ( V_9 ) ) {
return ( V_9 ) ;
}
}
return ( V_32 ) ;
}
T_2
F_16 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
void * V_37 )
{
T_1 V_38 ;
T_2 V_9 ;
struct V_7 * V_8 ;
for ( V_38 = 0 ; V_38 < V_36 -> V_39 ; V_38 ++ ) {
V_8 = & V_36 -> V_4 [ V_38 ] ;
if ( ! V_8 -> V_26 ) {
continue;
}
V_9 =
F_13 ( V_8 -> V_26 ,
V_8 ) ;
if ( F_5 ( V_9 ) ) {
return ( V_9 ) ;
}
}
return ( V_32 ) ;
}
static T_2
F_17 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
void * V_37 )
{
T_1 V_38 ;
T_2 V_9 ;
struct V_7 * V_8 ;
for ( V_38 = 0 ; V_38 < V_36 -> V_39 ; V_38 ++ ) {
V_8 = & V_36 -> V_4 [ V_38 ] ;
V_9 =
F_13 ( V_8 -> V_28 ,
V_8 ) ;
if ( F_5 ( V_9 ) ) {
return ( V_9 ) ;
}
}
return ( V_32 ) ;
}
T_2 F_18 ( void )
{
T_2 V_9 ;
F_19 ( V_40 ) ;
V_9 = F_20 ( F_14 , NULL ) ;
V_9 = F_20 ( F_15 , NULL ) ;
F_21 ( V_9 ) ;
}
T_2 F_22 ( void )
{
T_2 V_9 ;
F_19 ( V_41 ) ;
V_9 = F_20 ( F_16 , NULL ) ;
F_21 ( V_9 ) ;
}
T_2 F_23 ( void )
{
T_2 V_9 ;
F_19 ( V_42 ) ;
V_9 = F_20 ( F_17 , NULL ) ;
F_21 ( V_9 ) ;
}
