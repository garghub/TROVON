BOOL
F_1 ( unsigned int V_1 , unsigned int V_2 )
{
BOOL V_3 ;
V_3 = FALSE ;
if ( ( V_2 > V_4 ) ||
( V_2 == 0 ) )
{
V_3 = FALSE ;
goto exit;
}
V_3 = V_5 [ V_2 ] . V_3 ;
exit:
return ( V_3 ) ;
}
BOOL
F_2 (
unsigned int V_6 ,
T_1 V_7
)
{
if ( V_6 >= V_8 ) {
return ( FALSE ) ;
}
memcpy ( V_7 , V_9 [ V_6 ] . V_10 , V_4 ) ;
return ( TRUE ) ;
}
void F_3 ( void * V_11 )
{
T_2 V_12 = ( T_2 ) V_11 ;
BOOL V_13 = FALSE ;
unsigned int V_14 ;
for ( V_14 = 1 ; V_14 <= V_4 ; V_14 ++ )
V_5 [ V_14 ] . V_3 = FALSE ;
switch ( V_12 -> V_15 ) {
case V_16 :
case V_17 :
case V_18 :
case V_19 :
V_13 = FALSE ;
break;
case V_20 :
case V_21 :
default :
V_13 = TRUE ;
break;
}
if ( ( V_12 -> V_22 != 0 ) ||
( V_12 -> V_23 == TRUE ) ) {
if ( V_13 == TRUE ) {
for ( V_14 = 0 ; V_14 < V_4 ; V_14 ++ ) {
V_5 [ V_14 + 1 ] . V_3 = TRUE ;
}
for ( V_14 = 0 ; V_14 < V_24 ; V_14 ++ ) {
}
} else {
for ( V_14 = 0 ; V_14 < V_24 ; V_14 ++ ) {
V_5 [ V_14 + 1 ] . V_3 = TRUE ;
}
}
} else if ( V_12 -> V_25 <= V_8 ) {
if ( V_13 == TRUE ) {
for ( V_14 = 0 ; V_14 < V_4 ; V_14 ++ ) {
if ( V_9 [ V_12 -> V_25 ] . V_10 [ V_14 ] != 0 ) {
V_5 [ V_14 + 1 ] . V_3 = TRUE ;
}
}
} else {
for ( V_14 = 0 ; V_14 < V_24 ; V_14 ++ ) {
if ( V_9 [ V_12 -> V_25 ] . V_10 [ V_14 ] != 0 ) {
V_5 [ V_14 + 1 ] . V_3 = TRUE ;
}
}
}
}
F_4 ( V_26 , V_27 L_1 , V_12 -> V_25 , V_9 [ V_12 -> V_25 ] . V_28 [ 0 ] , V_9 [ V_12 -> V_25 ] . V_28 [ 1 ] ) ;
for ( V_14 = 0 ; V_14 < V_4 ; V_14 ++ ) {
F_4 ( V_29 , V_27 L_2 , V_5 [ V_14 ] . V_30 , V_5 [ V_14 + 1 ] . V_3 ) ;
}
}
T_3 F_5 ( T_3 V_30 )
{
T_3 V_14 ;
T_3 V_31 = 0 ;
for ( V_14 = 1 ; V_14 <= V_4 ; V_14 ++ ) {
if ( V_5 [ V_14 ] . V_30 == V_30 )
V_31 = V_14 ;
}
return V_31 ;
}
