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
int V_10 ;
V_8 [ 0 ] = 0x06 ;
V_9 = & V_4 -> V_11 [ 4 ] ;
V_10 = F_3 ( & V_8 [ 4 ] , V_9 , 8 ) ;
if ( V_10 < 0 )
F_4 ( L_1 ) ;
return 24 ;
}
T_2 F_5 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
int * V_7 )
{
* V_7 = 0 ;
return 24 ;
}
char * F_6 (
struct V_1 * V_2 ,
const char * V_8 ,
T_2 * V_12 ,
char * * V_13 )
{
* V_13 = NULL ;
* V_12 = 24 ;
return ( char * ) & V_8 [ 4 ] ;
}
T_1 F_7 ( struct V_1 * V_2 )
{
return 0x0 ;
}
T_2 F_8 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
int * V_7 )
{
* V_7 = 0 ;
return 24 ;
}
T_2 F_9 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
int * V_7 ,
unsigned char * V_8 )
{
unsigned char * V_9 ;
int V_14 , V_10 ;
T_2 V_15 = 8 ;
V_9 = & V_4 -> V_11 [ 0 ] ;
for ( V_14 = 0 ; V_14 < 24 ; ) {
if ( ! strncmp ( & V_9 [ V_14 ] , L_2 , 1 ) ) {
V_14 ++ ;
continue;
}
V_10 = F_3 ( & V_8 [ V_15 ++ ] , & V_9 [ V_14 ] , 1 ) ;
if ( V_10 < 0 )
F_4 ( L_3 ) ;
V_14 += 2 ;
}
return 24 ;
}
char * F_10 (
struct V_1 * V_2 ,
const char * V_8 ,
T_2 * V_12 ,
char * * V_13 )
{
* V_13 = NULL ;
* V_12 = 24 ;
return ( char * ) & V_8 [ 8 ] ;
}
T_1 F_11 ( struct V_1 * V_2 )
{
return 0x5 ;
}
T_2 F_12 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
int * V_7 ,
unsigned char * V_8 )
{
T_2 V_15 = 4 , V_16 = 0 ;
T_3 V_17 = 0 ;
F_13 ( & V_4 -> V_18 ) ;
V_8 [ 0 ] = 0x05 ;
V_17 = sprintf ( & V_8 [ V_15 ] , L_4 , V_4 -> V_11 ) ;
V_17 ++ ;
if ( ( * V_7 == 1 ) && ( V_6 -> V_19 ) ) {
V_8 [ 0 ] |= 0x40 ;
V_8 [ V_15 + V_17 ] = 0x2c ; V_15 ++ ;
V_8 [ V_15 + V_17 ] = 0x69 ; V_15 ++ ;
V_8 [ V_15 + V_17 ] = 0x2c ; V_15 ++ ;
V_8 [ V_15 + V_17 ] = 0x30 ; V_15 ++ ;
V_8 [ V_15 + V_17 ] = 0x78 ; V_15 ++ ;
V_17 += 5 ;
V_8 [ V_15 + V_17 ] = V_6 -> V_20 [ 0 ] ; V_15 ++ ;
V_8 [ V_15 + V_17 ] = V_6 -> V_20 [ 1 ] ; V_15 ++ ;
V_8 [ V_15 + V_17 ] = V_6 -> V_20 [ 2 ] ; V_15 ++ ;
V_8 [ V_15 + V_17 ] = V_6 -> V_20 [ 3 ] ; V_15 ++ ;
V_8 [ V_15 + V_17 ] = V_6 -> V_20 [ 4 ] ; V_15 ++ ;
V_8 [ V_15 + V_17 ] = V_6 -> V_20 [ 5 ] ; V_15 ++ ;
V_8 [ V_15 + V_17 ] = '\0' ; V_15 ++ ;
V_17 += 7 ;
}
F_14 ( & V_4 -> V_18 ) ;
V_16 = ( ( - V_17 ) & 3 ) ;
if ( V_16 != 0 )
V_17 += V_16 ;
V_8 [ 2 ] = ( ( V_17 >> 8 ) & 0xff ) ;
V_8 [ 3 ] = ( V_17 & 0xff ) ;
V_17 += 4 ;
return V_17 ;
}
T_2 F_15 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
int * V_7 )
{
T_2 V_17 = 0 , V_16 = 0 ;
F_13 ( & V_4 -> V_18 ) ;
V_17 = strlen ( V_4 -> V_11 ) ;
V_17 ++ ;
if ( V_6 -> V_19 ) {
V_17 += 5 ;
V_17 += 7 ;
* V_7 = 1 ;
} else
* V_7 = 0 ;
F_14 ( & V_4 -> V_18 ) ;
V_16 = ( ( - V_17 ) & 3 ) ;
if ( V_16 != 0 )
V_17 += V_16 ;
V_17 += 4 ;
return V_17 ;
}
char * F_16 (
struct V_1 * V_2 ,
const char * V_8 ,
T_2 * V_12 ,
char * * V_13 )
{
char * V_21 ;
T_2 V_22 , V_16 ;
int V_14 ;
T_3 V_23 ;
T_1 V_7 = ( V_8 [ 0 ] & 0xc0 ) ;
if ( ( V_7 != 0x00 ) && ( V_7 != 0x40 ) ) {
F_17 ( L_5
L_6 , V_7 ) ;
return NULL ;
}
if ( V_12 != NULL ) {
V_23 = ( ( V_8 [ 2 ] >> 8 ) & 0xff ) ;
V_23 |= ( V_8 [ 3 ] & 0xff ) ;
V_22 = strlen ( & V_8 [ 4 ] ) ;
V_22 += 4 ;
V_22 += 1 ;
V_16 = ( ( - V_22 ) & 3 ) ;
if ( V_16 != 0 )
V_22 += V_16 ;
if ( ( V_23 + 4 ) != V_22 ) {
F_4 ( L_7
L_8
L_9 , V_23 + 4 , V_22 ) ;
* V_12 = V_22 ;
} else
* V_12 = ( V_23 + 4 ) ;
}
if ( V_7 == 0x40 ) {
V_21 = strstr ( & V_8 [ 4 ] , L_10 ) ;
if ( ! V_21 ) {
F_17 ( L_11
L_12 ,
& V_8 [ 4 ] ) ;
return NULL ;
}
* V_21 = '\0' ;
V_21 += 5 ;
* V_13 = V_21 ;
for ( V_14 = 0 ; V_14 < 12 ; V_14 ++ ) {
if ( isdigit ( * V_21 ) ) {
V_21 ++ ;
continue;
}
* V_21 = tolower ( * V_21 ) ;
V_21 ++ ;
}
}
return ( char * ) & V_8 [ 4 ] ;
}
