T_1 F_1 ( struct V_1 * V_2 )
{
return 0x6 ;
}
T_2 F_2 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
int * V_7 ,
unsigned char * V_8 )
{
unsigned char * V_9 ;
V_8 [ 0 ] = 0x06 ;
V_9 = & V_4 -> V_10 [ 4 ] ;
F_3 ( & V_8 [ 4 ] , V_9 , 8 ) ;
return 24 ;
}
T_2 F_4 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
int * V_7 )
{
* V_7 = 0 ;
return 24 ;
}
char * F_5 (
struct V_1 * V_2 ,
const char * V_8 ,
T_2 * V_11 ,
char * * V_12 )
{
* V_12 = NULL ;
* V_11 = 24 ;
return ( char * ) & V_8 [ 4 ] ;
}
T_1 F_6 ( struct V_1 * V_2 )
{
return 0x0 ;
}
T_2 F_7 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
int * V_7 )
{
* V_7 = 0 ;
return 24 ;
}
T_2 F_8 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
int * V_7 ,
unsigned char * V_8 )
{
unsigned char * V_9 ;
int V_13 ;
T_2 V_14 = 8 ;
V_9 = & V_4 -> V_10 [ 0 ] ;
for ( V_13 = 0 ; V_13 < 24 ; ) {
if ( ! strncmp ( & V_9 [ V_13 ] , L_1 , 1 ) ) {
V_13 ++ ;
continue;
}
F_3 ( & V_8 [ V_14 ++ ] , & V_9 [ V_13 ] , 1 ) ;
V_13 += 2 ;
}
return 24 ;
}
char * F_9 (
struct V_1 * V_2 ,
const char * V_8 ,
T_2 * V_11 ,
char * * V_12 )
{
* V_12 = NULL ;
* V_11 = 24 ;
return ( char * ) & V_8 [ 8 ] ;
}
T_1 F_10 ( struct V_1 * V_2 )
{
return 0x5 ;
}
T_2 F_11 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
int * V_7 ,
unsigned char * V_8 )
{
T_2 V_14 = 4 , V_15 = 0 ;
T_3 V_16 = 0 ;
F_12 ( & V_4 -> V_17 ) ;
V_8 [ 0 ] = 0x05 ;
V_16 = sprintf ( & V_8 [ V_14 ] , L_2 , V_4 -> V_10 ) ;
V_16 ++ ;
if ( ( * V_7 == 1 ) && ( V_6 -> V_18 ) ) {
V_8 [ 0 ] |= 0x40 ;
V_8 [ V_14 + V_16 ] = 0x2c ; V_14 ++ ;
V_8 [ V_14 + V_16 ] = 0x69 ; V_14 ++ ;
V_8 [ V_14 + V_16 ] = 0x2c ; V_14 ++ ;
V_8 [ V_14 + V_16 ] = 0x30 ; V_14 ++ ;
V_8 [ V_14 + V_16 ] = 0x78 ; V_14 ++ ;
V_16 += 5 ;
V_8 [ V_14 + V_16 ] = V_6 -> V_19 [ 0 ] ; V_14 ++ ;
V_8 [ V_14 + V_16 ] = V_6 -> V_19 [ 1 ] ; V_14 ++ ;
V_8 [ V_14 + V_16 ] = V_6 -> V_19 [ 2 ] ; V_14 ++ ;
V_8 [ V_14 + V_16 ] = V_6 -> V_19 [ 3 ] ; V_14 ++ ;
V_8 [ V_14 + V_16 ] = V_6 -> V_19 [ 4 ] ; V_14 ++ ;
V_8 [ V_14 + V_16 ] = V_6 -> V_19 [ 5 ] ; V_14 ++ ;
V_8 [ V_14 + V_16 ] = '\0' ; V_14 ++ ;
V_16 += 7 ;
}
F_13 ( & V_4 -> V_17 ) ;
V_15 = ( ( - V_16 ) & 3 ) ;
if ( V_15 != 0 )
V_16 += V_15 ;
V_8 [ 2 ] = ( ( V_16 >> 8 ) & 0xff ) ;
V_8 [ 3 ] = ( V_16 & 0xff ) ;
V_16 += 4 ;
return V_16 ;
}
T_2 F_14 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
int * V_7 )
{
T_2 V_16 = 0 , V_15 = 0 ;
F_12 ( & V_4 -> V_17 ) ;
V_16 = strlen ( V_4 -> V_10 ) ;
V_16 ++ ;
if ( V_6 -> V_18 ) {
V_16 += 5 ;
V_16 += 7 ;
* V_7 = 1 ;
} else
* V_7 = 0 ;
F_13 ( & V_4 -> V_17 ) ;
V_15 = ( ( - V_16 ) & 3 ) ;
if ( V_15 != 0 )
V_16 += V_15 ;
V_16 += 4 ;
return V_16 ;
}
char * F_15 (
struct V_1 * V_2 ,
const char * V_8 ,
T_2 * V_11 ,
char * * V_12 )
{
char * V_20 ;
T_2 V_21 , V_15 ;
int V_13 ;
T_3 V_22 ;
T_1 V_7 = ( V_8 [ 0 ] & 0xc0 ) ;
if ( ( V_7 != 0x00 ) && ( V_7 != 0x40 ) ) {
F_16 ( L_3
L_4 , V_7 ) ;
return NULL ;
}
if ( V_11 != NULL ) {
V_22 = ( ( V_8 [ 2 ] >> 8 ) & 0xff ) ;
V_22 |= ( V_8 [ 3 ] & 0xff ) ;
V_21 = strlen ( ( char * ) & V_8 [ 4 ] ) ;
V_21 += 4 ;
V_21 += 1 ;
V_15 = ( ( - V_21 ) & 3 ) ;
if ( V_15 != 0 )
V_21 += V_15 ;
if ( ( V_22 + 4 ) != V_21 ) {
F_17 ( L_5
L_6
L_7 , V_22 + 4 , V_21 ) ;
* V_11 = V_21 ;
} else
* V_11 = ( V_22 + 4 ) ;
}
if ( V_7 == 0x40 ) {
V_20 = strstr ( ( char * ) & V_8 [ 4 ] , L_8 ) ;
if ( ! V_20 ) {
F_16 ( L_9
L_10 ,
( char * ) & V_8 [ 4 ] ) ;
return NULL ;
}
* V_20 = '\0' ;
V_20 += 5 ;
* V_12 = V_20 ;
for ( V_13 = 0 ; V_13 < 12 ; V_13 ++ ) {
if ( isdigit ( * V_20 ) ) {
V_20 ++ ;
continue;
}
* V_20 = tolower ( * V_20 ) ;
V_20 ++ ;
}
}
return ( char * ) & V_8 [ 4 ] ;
}
