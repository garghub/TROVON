T_1 *
F_1 ( T_2 * V_1 , const T_1 * V_2 , T_3 V_3 )
{
T_4 * V_4 ;
V_4 = F_2 ( V_1 , V_3 + 1 , 0 ) ;
while ( V_3 > 0 ) {
T_1 V_5 = * V_2 ;
if ( V_5 < 0x80 )
F_3 ( V_4 , V_5 ) ;
else
F_4 ( V_4 , V_6 ) ;
V_2 ++ ;
V_3 -- ;
}
return ( T_1 * ) F_5 ( V_4 ) ;
}
T_1 *
F_6 ( T_2 * V_1 , const T_1 * V_2 , T_3 V_3 )
{
T_4 * V_4 ;
V_4 = F_2 ( V_1 , V_3 + 1 , 0 ) ;
while ( V_3 > 0 ) {
T_1 V_5 = * V_2 ;
if ( V_5 < 0x80 )
F_3 ( V_4 , V_5 ) ;
else {
F_4 ( V_4 , V_5 ) ;
}
V_2 ++ ;
V_3 -- ;
}
return ( T_1 * ) F_5 ( V_4 ) ;
}
T_1 *
F_7 ( T_2 * V_1 , const T_1 * V_2 , T_3 V_3 , const T_5 V_7 [ 0x80 ] )
{
T_4 * V_4 ;
V_4 = F_2 ( V_1 , V_3 + 1 , 0 ) ;
while ( V_3 > 0 ) {
T_1 V_5 = * V_2 ;
if ( V_5 < 0x80 )
F_3 ( V_4 , V_5 ) ;
else
F_4 ( V_4 , V_7 [ V_5 - 0x80 ] ) ;
V_2 ++ ;
V_3 -- ;
}
return ( T_1 * ) F_5 ( V_4 ) ;
}
T_1 *
F_8 ( T_2 * V_1 , const T_1 * V_2 , T_3 V_3 , const T_6 V_8 )
{
T_5 V_9 ;
T_3 V_10 ;
T_4 * V_11 ;
V_11 = F_2 ( V_1 , V_3 + 1 , 0 ) ;
for( V_10 = 0 ; V_10 + 1 < V_3 ; V_10 += 2 ) {
if ( V_8 == V_12 ) {
V_9 = F_9 ( V_2 + V_10 ) ;
} else{
V_9 = F_10 ( V_2 + V_10 ) ;
}
F_4 ( V_11 , V_9 ) ;
}
return ( T_1 * ) F_5 ( V_11 ) ;
}
T_1 *
F_11 ( T_2 * V_1 , const T_1 * V_2 , T_3 V_3 , const T_6 V_8 )
{
T_4 * V_11 ;
T_5 V_13 , V_14 ;
T_7 V_9 ;
T_3 V_10 ;
V_11 = F_2 ( V_1 , V_3 + 1 , 0 ) ;
for( V_10 = 0 ; V_10 + 1 < V_3 ; V_10 += 2 ) {
if ( V_8 == V_12 )
V_13 = F_9 ( V_2 + V_10 ) ;
else
V_13 = F_10 ( V_2 + V_10 ) ;
if ( F_12 ( V_13 ) ) {
V_10 += 2 ;
if ( V_10 + 1 >= V_3 ) {
break;
}
V_14 = V_13 ;
if ( V_8 == V_12 )
V_13 = F_9 ( V_2 + V_10 ) ;
else
V_13 = F_10 ( V_2 + V_10 ) ;
if ( F_13 ( V_13 ) ) {
V_9 = F_14 ( V_14 , V_13 ) ;
F_4 ( V_11 , V_9 ) ;
} else {
;
}
} else {
if ( F_13 ( V_13 ) ) {
;
} else {
F_4 ( V_11 , V_13 ) ;
}
}
}
return ( T_1 * ) F_5 ( V_11 ) ;
}
T_1 *
F_15 ( T_2 * V_1 , const T_1 * V_2 , T_3 V_3 , const T_6 V_8 )
{
T_7 V_9 ;
T_3 V_10 ;
T_4 * V_11 ;
V_11 = F_2 ( V_1 , V_3 + 1 , 0 ) ;
for( V_10 = 0 ; V_10 + 3 < V_3 ; V_10 += 4 ) {
if ( V_8 == V_12 )
V_9 = F_16 ( V_2 + V_10 ) ;
else
V_9 = F_17 ( V_2 + V_10 ) ;
F_4 ( V_11 , V_9 ) ;
}
return ( V_15 * ) F_5 ( V_11 ) ;
}
static T_7
F_18 ( T_1 V_16 )
{
if ( V_16 < F_19 ( V_17 ) )
return V_17 [ V_16 ] ;
return V_6 ;
}
static T_7
F_20 ( T_1 V_16 )
{
switch ( V_16 )
{
case 0x0a : return 0x0c ;
case 0x14 : return '^' ;
case 0x28 : return '{' ;
case 0x29 : return '}' ;
case 0x2f : return '\\' ;
case 0x3c : return '[' ;
case 0x3d : return '~' ;
case 0x3e : return ']' ;
case 0x40 : return '|' ;
case 0x65 : return 0x20ac ;
}
return V_6 ;
}
static T_8
F_21 ( unsigned char V_18 )
{
return ( V_18 == V_19 ) ;
}
static T_8
F_22 ( T_4 * V_11 , T_1 V_20 ,
T_8 V_21 )
{
T_7 V_9 ;
if ( F_21 ( V_20 ) ) {
V_21 = TRUE ;
} else {
if ( V_21 ) {
V_21 = FALSE ;
V_9 = F_20 ( V_20 ) ;
} else {
V_9 = F_18 ( V_20 ) ;
}
F_4 ( V_11 , V_9 ) ;
}
return V_21 ;
}
T_1 *
F_23 ( T_2 * V_1 , const T_1 * V_2 ,
const T_3 V_22 , T_3 V_23 )
{
T_4 * V_11 ;
T_3 V_24 ;
T_1 V_25 , V_26 , V_27 = 0x00 ;
T_8 V_21 = FALSE ;
int V_28 ;
V_11 = F_2 ( V_1 , V_23 + 1 , 0 ) ;
V_28 = V_22 & 0x07 ;
if ( ! V_28 ) {
V_28 = 7 ;
}
for( V_24 = 0 ; V_24 < V_23 ; ) {
V_25 = * V_2 ;
V_2 ++ ;
V_26 = ( ( V_25 & V_29 ) << ( 7 - V_28 ) ) | V_27 ;
V_27 = V_25 >> V_28 ;
if ( V_24 || ( V_28 == 7 ) ) {
V_21 = F_22 ( V_11 , V_26 ,
V_21 ) ;
V_24 ++ ;
}
if ( ( V_28 == 1 ) && ( V_24 < V_23 ) ) {
V_21 = F_22 ( V_11 , V_27 ,
V_21 ) ;
V_24 ++ ;
V_28 = 7 ;
V_27 = 0x00 ;
} else
V_28 -- ;
}
if ( V_21 ) {
F_4 ( V_11 , V_6 ) ;
}
return ( T_1 * ) F_5 ( V_11 ) ;
}
T_1 *
F_24 ( T_2 * V_1 , const T_1 * V_2 ,
const T_3 V_22 , T_3 V_23 )
{
T_4 * V_11 ;
T_3 V_24 ;
T_1 V_25 , V_26 , V_27 = 0x00 ;
int V_28 ;
V_28 = V_22 & 0x07 ;
if ( ! V_28 ) {
V_28 = 7 ;
}
V_11 = F_2 ( V_1 , V_23 + 1 , 0 ) ;
for( V_24 = 0 ; V_24 < V_23 ; ) {
V_25 = * V_2 ;
V_2 ++ ;
V_26 = ( V_25 >> ( 8 - V_28 ) ) | V_27 ;
V_27 = ( V_25 << ( V_28 - 1 ) ) & 0x7f ;
if ( V_24 || ( V_28 == 7 ) ) {
F_3 ( V_11 , V_26 ) ;
V_24 ++ ;
}
if ( ( V_28 == 1 ) && ( V_24 < V_23 ) ) {
F_3 ( V_11 , V_27 ) ;
V_24 ++ ;
V_28 = 7 ;
V_27 = 0x00 ;
} else
V_28 -- ;
}
return ( T_1 * ) F_5 ( V_11 ) ;
}
void
F_25 ( T_1 * V_30 , T_6 V_31 )
{
T_6 V_10 ;
T_1 * V_32 ;
V_32 = V_30 ;
for ( V_10 = 0 ; V_10 < V_31 ; V_10 ++ , V_32 ++ ) {
* V_32 = V_33 [ * V_32 ] ;
}
}
T_1
F_26 ( T_1 V_16 )
{
return V_33 [ V_16 ] ;
}
T_1 *
F_27 ( T_2 * V_1 , const T_1 * V_2 , T_3 V_3 )
{
T_4 * V_4 ;
V_4 = F_2 ( V_1 , V_3 + 1 , 0 ) ;
while ( V_3 > 0 ) {
T_1 V_5 = * V_2 ;
F_4 ( V_4 , V_33 [ V_5 ] ) ;
V_2 ++ ;
V_3 -- ;
}
return ( T_1 * ) F_5 ( V_4 ) ;
}
