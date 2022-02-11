void
F_1 (
T_1 V_1
)
{
unsigned char V_2 ;
for ( V_2 = 0 ; V_2 <= V_3 ; V_2 ++ ) {
V_1 -> V_4 [ V_2 ] = 0 ;
V_1 -> V_5 [ V_2 ] = 0 ;
}
}
unsigned char
F_2 (
unsigned char V_6
)
{
unsigned char V_2 ;
V_6 = V_6 & 0x7F ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if ( V_7 [ V_2 ] == V_6 )
return V_2 ;
}
return 0 ;
}
unsigned short
F_3 (
unsigned char V_6
)
{
unsigned short V_2 ;
V_6 = V_6 & 0x7F ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if ( V_7 [ V_2 ] == V_6 )
return V_2 ;
}
return 0 ;
}
void
F_4 (
void * V_8 ,
T_2 V_9 ,
T_2 V_10 ,
bool V_11 ,
unsigned short * V_12 ,
unsigned short * V_13 ,
unsigned short * V_14 ,
unsigned char * V_15 ,
unsigned char * V_16
)
{
struct V_17 * V_18 = V_8 ;
unsigned int V_2 ;
unsigned char V_19 = 0 ;
unsigned char V_6 = 0 ;
unsigned short V_20 = V_18 -> V_21 ;
unsigned int V_22 ;
if ( V_9 == NULL )
return;
* V_14 = 0 ;
V_22 = V_9 -> V_23 ;
F_5 ( L_1 , V_22 ) ;
if ( V_18 -> V_24 != V_25 ) {
if ( V_22 > V_26 )
V_22 = V_26 ;
} else {
if ( V_22 > V_27 )
V_22 = V_27 ;
}
for ( V_2 = 0 ; V_2 < V_22 ; V_2 ++ ) {
V_6 = ( unsigned char ) ( V_9 -> V_28 [ V_2 ] ) ;
if ( F_6 ( V_6 ) && V_11 ) {
F_7 ( ( void * ) V_18 , F_3 ( V_6 ) ) ;
F_5 ( L_2 ,
F_3 ( V_6 ) ) ;
}
V_6 = ( unsigned char ) ( V_9 -> V_28 [ V_2 ] & 0x7F ) ;
if ( V_19 == 0 )
V_19 = V_6 ;
if ( V_6 > V_19 )
V_19 = V_6 ;
* V_14 |= ( 1 << F_3 ( V_6 ) ) ;
}
if ( ( V_10 != NULL ) && ( V_10 -> V_29 == V_30 ) &&
( V_18 -> V_24 != V_25 ) ) {
unsigned int V_31 = V_10 -> V_23 ;
if ( V_31 > V_26 )
V_31 = V_26 ;
for ( V_2 = 0 ; V_2 < V_31 ; V_2 ++ ) {
V_6 = ( unsigned char ) ( V_10 -> V_28 [ V_2 ] ) ;
if ( F_6 ( V_10 -> V_28 [ V_2 ] ) ) {
F_7 ( ( void * ) V_18 , F_3 ( V_6 ) ) ;
F_5 ( L_2 ,
F_3 ( V_6 ) ) ;
}
V_6 = ( unsigned char ) ( V_10 -> V_28 [ V_2 ] & 0x7F ) ;
if ( V_19 == 0 )
V_19 = V_6 ;
if ( V_6 > V_19 )
V_19 = V_6 ;
* V_14 |= ( 1 << F_3 ( V_6 ) ) ;
}
}
if ( ( V_18 -> V_32 == V_33 ) && F_8 ( ( void * ) V_18 ) )
V_18 -> V_32 = V_34 ;
* V_15 = V_18 -> V_35 ;
* V_16 = V_18 -> V_36 ;
* V_13 = F_3 ( V_19 ) ;
if ( ( V_18 -> V_32 == V_37 ) || ( V_18 -> V_32 == V_33 ) )
* V_12 = V_18 -> V_35 ;
else
* V_12 = V_18 -> V_36 ;
if ( V_20 != V_18 -> V_21 )
F_9 ( ( void * ) V_18 , V_18 -> V_24 ) ;
F_5 ( L_3 ) ;
}
void
F_10 (
void * V_8 ,
T_1 V_1
)
{
struct V_17 * V_18 = V_8 ;
unsigned short V_38 = 0 ;
unsigned int V_2 ;
bool V_39 [ V_3 ] = { true , true , true , true , false , false , true , true , true , true , true , true } ;
unsigned long V_40 [ V_3 ] = { 10 , 20 , 55 , 110 , 60 , 90 , 120 , 180 , 240 , 360 , 480 , 540 } ;
unsigned long V_41 = 0 ;
unsigned short V_42 = 0 ;
unsigned long V_43 = 0 ;
if ( V_18 -> V_44 -> V_45 != V_46 )
return;
V_1 -> V_47 ++ ;
if ( V_1 -> V_5 [ V_3 ] > V_1 -> V_4 [ V_3 ] )
V_43 = V_1 -> V_5 [ V_3 ] - V_1 -> V_4 [ V_3 ] ;
if ( ( V_1 -> V_4 [ V_3 ] < V_48 ) &&
( V_43 < V_49 ) &&
( V_1 -> V_47 < V_50 ) ) {
return;
}
if ( V_1 -> V_47 >= V_50 )
V_1 -> V_47 = 0 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if ( V_1 -> V_51 & ( 0x0001 << V_2 ) ) {
if ( V_39 [ V_2 ] )
V_42 = ( unsigned short ) V_2 ;
} else {
V_39 [ V_2 ] = false ;
}
}
for ( V_2 = 0 ; V_2 <= V_1 -> V_52 ; V_2 ++ ) {
if ( ( V_1 -> V_4 [ V_2 ] != 0 ) ||
( V_1 -> V_5 [ V_2 ] != 0 ) ) {
V_40 [ V_2 ] *= V_1 -> V_4 [ V_2 ] ;
if ( V_2 < V_53 )
V_1 -> V_5 [ V_2 ] *= 4 ;
V_40 [ V_2 ] /= ( V_1 -> V_4 [ V_2 ] + V_1 -> V_5 [ V_2 ] ) ;
}
}
V_41 = V_40 [ V_1 -> V_52 ] ;
V_38 = V_1 -> V_52 ;
for ( V_2 = V_1 -> V_52 ; V_2 > 0 ; ) {
V_2 -- ;
if ( ( V_40 [ V_2 ] > V_41 ) && V_39 [ V_2 ] ) {
V_41 = V_40 [ V_2 ] ;
V_38 = ( unsigned short ) V_2 ;
}
}
V_1 -> V_52 = V_38 ;
if ( V_1 -> V_4 [ V_3 ] ) {
if ( V_1 -> V_4 [ V_3 ] >
( V_1 -> V_5 [ V_3 ] * 4 ) ) {
V_1 -> V_52 = V_42 ;
}
} else {
if ( V_1 -> V_5 [ V_3 ] == 0 )
V_1 -> V_52 = V_42 ;
}
V_54 = V_1 -> V_52 ;
F_1 ( V_1 ) ;
}
unsigned char
F_11 (
T_2 V_55 ,
T_2 V_56 ,
unsigned int V_22
)
{
unsigned int V_2 , V_57 , V_58 = 0 ;
if ( ( V_55 == NULL ) || ( V_56 == NULL ) )
return 0 ;
if ( V_55 -> V_23 == 0 )
return 0 ;
for ( V_2 = 0 ; V_2 < V_22 ; V_2 ++ ) {
for ( V_57 = 0 ; V_57 < V_55 -> V_23 ; V_57 ++ ) {
if ( ( V_55 -> V_28 [ V_57 ] & 0x7F ) == V_7 [ V_2 ] ) {
V_56 -> V_28 [ V_58 ++ ] = V_55 -> V_28 [ V_57 ] ;
break;
}
}
}
return ( unsigned char ) V_58 ;
}
