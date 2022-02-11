const union V_1 * F_1 ( const union
V_1
* V_2 )
{
if ( ( V_2 -> V_3 . V_4 & V_5 ) &&
( V_2 -> V_3 . V_4 != V_6 ) ) {
V_2 ++ ;
}
V_2 ++ ;
return ( V_2 ) ;
}
const union V_1 * F_2 ( char * V_7 )
{
const union V_1 * V_2 ;
if ( V_7 [ 0 ] != '_' ) {
return ( NULL ) ;
}
V_2 = V_8 ;
while ( V_2 -> V_3 . V_7 [ 0 ] ) {
if ( F_3 ( V_7 , V_2 -> V_3 . V_7 ) ) {
return ( V_2 ) ;
}
V_2 = F_1 ( V_2 ) ;
}
return ( NULL ) ;
}
void F_4 ( char * V_9 , T_1 V_4 )
{
T_1 V_10 ;
T_1 V_11 ;
T_1 V_12 ;
if ( ! V_4 ) {
F_5 ( V_9 , L_1 ) ;
return;
}
V_12 = 1 ;
V_9 [ 0 ] = 0 ;
V_10 = V_13 ;
for ( V_11 = 0 ; V_11 < V_14 ; V_11 ++ ) {
if ( V_4 & V_10 ) {
F_6 ( V_9 , & V_15 [ V_11 ] [ V_12 ] ) ;
V_12 = 0 ;
}
V_10 <<= 1 ;
}
}
const union V_1 * F_7 ( char * V_7 )
{
const union V_1 * V_2 ;
if ( V_7 [ 0 ] != '_' ) {
return ( NULL ) ;
}
V_2 = V_16 ;
while ( V_2 -> V_3 . V_7 [ 0 ] ) {
if ( F_3 ( V_7 , V_2 -> V_3 . V_7 ) ) {
return ( V_2 ) ;
}
V_2 ++ ;
}
return ( NULL ) ;
}
void
F_8 ( char * V_9 ,
const union V_1 * V_2 ,
T_2 V_17 )
{
T_1 V_18 ;
V_18 = F_9 ( V_9 ,
V_2 -> V_3 . V_19 ) ;
if ( V_17 ) {
printf ( L_2 ) ;
}
printf ( L_3 ,
V_2 -> V_3 . V_7 ,
( V_2 -> V_3 . V_19 & V_20 ) ?
L_4 : L_5 , V_18 , V_18 != 1 ? L_6 : L_5 ) ;
if ( V_18 > 0 ) {
printf ( L_7 , V_9 ) ;
}
if ( V_17 ) {
printf ( L_8 ) ;
}
if ( V_2 -> V_3 . V_4 ) {
F_4 ( V_9 ,
V_2 -> V_3 .
V_4 ) ;
printf ( L_9 , V_9 ) ;
} else {
printf ( L_10 ) ;
}
}
static T_1 F_9 ( char * V_9 , T_3 V_21 )
{
T_3 V_22 ;
T_3 V_23 ;
T_3 V_18 ;
T_1 V_11 ;
* V_9 = 0 ;
V_23 = 2 ;
V_18 = F_10 ( V_21 ) ;
if ( V_18 > V_24 ) {
printf ( L_11
L_12 , V_18 ) ;
return ( V_18 ) ;
}
for ( V_11 = 0 ; V_11 < V_18 ; V_11 ++ ) {
V_22 = F_11 ( V_21 ) ;
if ( ! V_22
|| ( V_22 > V_25 ) ) {
printf ( L_13
L_12 ,
V_22 ) ;
return ( V_18 ) ;
}
strcat ( V_9 ,
V_26 [ V_22 ] + V_23 ) ;
V_23 = 0 ;
}
return ( V_18 ) ;
}
T_1 F_12 ( char * V_9 , T_3 V_27 )
{
T_1 V_11 ;
T_3 V_23 ;
T_1 V_28 ;
* V_9 = 0 ;
V_23 = 1 ;
V_28 = 0 ;
for ( V_11 = 0 ; V_11 < V_29 ; V_11 ++ ) {
if ( V_27 & 1 ) {
strcat ( V_9 , & ( V_30 [ V_11 ] [ V_23 ] ) ) ;
V_23 = 0 ;
V_28 ++ ;
}
V_27 >>= 1 ;
}
return ( V_28 ) ;
}
