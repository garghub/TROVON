static int F_1 (
struct V_1 * V_2 ,
int * V_3 ,
unsigned char * V_4 )
{
int V_5 ;
V_5 = F_2 ( & V_4 [ 4 ] , & V_2 -> V_6 [ 4 ] , 8 ) ;
if ( V_5 ) {
F_3 ( L_1 , V_7 ) ;
return V_5 ;
}
return 24 ;
}
static int F_4 (
struct V_1 * V_8 ,
int * V_3 ,
unsigned char * V_4 )
{
unsigned char * V_9 ;
int V_10 , V_5 ;
T_1 V_11 = 8 ;
V_9 = & V_8 -> V_6 [ 0 ] ;
for ( V_10 = 0 ; V_10 < 24 ; ) {
if ( ! strncmp ( & V_9 [ V_10 ] , L_2 , 1 ) ) {
V_10 ++ ;
continue;
}
V_5 = F_2 ( & V_4 [ V_11 ++ ] , & V_9 [ V_10 ] , 1 ) ;
if ( V_5 < 0 ) {
F_3 ( L_1 , V_7 ) ;
return V_5 ;
}
V_10 += 2 ;
}
return 24 ;
}
static int F_5 (
struct V_1 * V_2 ,
int * V_3 ,
unsigned char * V_4 )
{
int V_5 ;
V_5 = F_2 ( & V_4 [ 8 ] , V_2 -> V_6 , 8 ) ;
if ( V_5 ) {
F_3 ( L_1 , V_7 ) ;
return V_5 ;
}
return 24 ;
}
static int F_6 (
struct V_1 * V_2 ,
int * V_3 ,
unsigned char * V_4 )
{
const char * V_12 ;
unsigned V_13 , V_14 , V_15 ;
int V_16 ;
V_12 = V_2 -> V_6 ;
if ( strncasecmp ( V_12 , L_3 , 2 ) == 0 )
V_12 += 2 ;
V_13 = strlen ( V_12 ) ;
if ( V_13 % 2 )
return - V_17 ;
V_14 = F_7 ( V_13 / 2 , 16U ) ;
V_15 = 16 - V_14 ;
memset ( V_4 + 8 , 0 , V_15 ) ;
V_16 = F_2 ( V_4 + 8 + V_15 , V_12 , V_14 ) ;
if ( V_16 < 0 ) {
F_3 ( L_4 , V_7 , V_16 ) ;
return V_16 ;
}
return 24 ;
}
static int F_8 (
struct V_1 * V_8 ,
struct V_18 * V_19 ,
int * V_3 ,
unsigned char * V_4 )
{
T_1 V_11 = 4 , V_20 = 0 ;
T_2 V_13 = 0 ;
F_9 ( & V_8 -> V_21 ) ;
V_13 = sprintf ( & V_4 [ V_11 ] , L_5 , V_8 -> V_6 ) ;
V_13 ++ ;
if ( ( * V_3 == 1 ) && ( V_19 -> V_22 ) ) {
V_4 [ 0 ] |= 0x40 ;
V_4 [ V_11 + V_13 ] = 0x2c ; V_11 ++ ;
V_4 [ V_11 + V_13 ] = 0x69 ; V_11 ++ ;
V_4 [ V_11 + V_13 ] = 0x2c ; V_11 ++ ;
V_4 [ V_11 + V_13 ] = 0x30 ; V_11 ++ ;
V_4 [ V_11 + V_13 ] = 0x78 ; V_11 ++ ;
V_13 += 5 ;
V_4 [ V_11 + V_13 ] = V_19 -> V_23 [ 0 ] ; V_11 ++ ;
V_4 [ V_11 + V_13 ] = V_19 -> V_23 [ 1 ] ; V_11 ++ ;
V_4 [ V_11 + V_13 ] = V_19 -> V_23 [ 2 ] ; V_11 ++ ;
V_4 [ V_11 + V_13 ] = V_19 -> V_23 [ 3 ] ; V_11 ++ ;
V_4 [ V_11 + V_13 ] = V_19 -> V_23 [ 4 ] ; V_11 ++ ;
V_4 [ V_11 + V_13 ] = V_19 -> V_23 [ 5 ] ; V_11 ++ ;
V_4 [ V_11 + V_13 ] = '\0' ; V_11 ++ ;
V_13 += 7 ;
}
F_10 ( & V_8 -> V_21 ) ;
V_20 = ( ( - V_13 ) & 3 ) ;
if ( V_20 != 0 )
V_13 += V_20 ;
V_4 [ 2 ] = ( ( V_13 >> 8 ) & 0xff ) ;
V_4 [ 3 ] = ( V_13 & 0xff ) ;
V_13 += 4 ;
return V_13 ;
}
static int F_11 (
struct V_1 * V_8 ,
struct V_18 * V_19 ,
int * V_3 )
{
T_1 V_13 = 0 , V_20 = 0 ;
F_9 ( & V_8 -> V_21 ) ;
V_13 = strlen ( V_8 -> V_6 ) ;
V_13 ++ ;
if ( V_19 -> V_22 ) {
V_13 += 5 ;
V_13 += 7 ;
* V_3 = 1 ;
} else
* V_3 = 0 ;
F_10 ( & V_8 -> V_21 ) ;
V_20 = ( ( - V_13 ) & 3 ) ;
if ( V_20 != 0 )
V_13 += V_20 ;
V_13 += 4 ;
return V_13 ;
}
static char * F_12 (
struct V_24 * V_25 ,
const char * V_4 ,
T_1 * V_26 ,
char * * V_27 )
{
char * V_12 ;
T_1 V_28 , V_20 ;
int V_10 ;
T_2 V_29 ;
T_3 V_3 = ( V_4 [ 0 ] & 0xc0 ) ;
if ( ( V_3 != 0x00 ) && ( V_3 != 0x40 ) ) {
F_13 ( L_6
L_7 , V_3 ) ;
return NULL ;
}
if ( V_26 ) {
V_29 = ( V_4 [ 2 ] << 8 ) | V_4 [ 3 ] ;
V_28 = strlen ( & V_4 [ 4 ] ) ;
V_28 += 4 ;
V_28 += 1 ;
V_20 = ( ( - V_28 ) & 3 ) ;
if ( V_20 != 0 )
V_28 += V_20 ;
if ( ( V_29 + 4 ) != V_28 ) {
F_3 ( L_8
L_9
L_10 , V_29 + 4 , V_28 ) ;
* V_26 = V_28 ;
} else
* V_26 = ( V_29 + 4 ) ;
}
if ( V_3 == 0x40 ) {
V_12 = strstr ( & V_4 [ 4 ] , L_11 ) ;
if ( ! V_12 ) {
F_13 ( L_12
L_13 ,
& V_4 [ 4 ] ) ;
return NULL ;
}
* V_12 = '\0' ;
V_12 += 5 ;
* V_27 = V_12 ;
for ( V_10 = 0 ; V_10 < 12 ; V_10 ++ ) {
if ( isdigit ( * V_12 ) ) {
V_12 ++ ;
continue;
}
* V_12 = tolower ( * V_12 ) ;
V_12 ++ ;
}
}
return ( char * ) & V_4 [ 4 ] ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_18 * V_19 , int * V_3 )
{
switch ( V_2 -> V_25 -> V_30 ) {
case V_31 :
case V_32 :
case V_33 :
case V_34 :
break;
case V_35 :
return F_11 ( V_2 , V_19 , V_3 ) ;
default:
F_13 ( L_14 , V_2 -> V_25 -> V_30 ) ;
return - V_17 ;
}
* V_3 = 0 ;
return 24 ;
}
int F_15 ( struct V_1 * V_2 ,
struct V_18 * V_19 , int * V_3 ,
unsigned char * V_4 )
{
switch ( V_2 -> V_25 -> V_30 ) {
case V_34 :
return F_1 ( V_2 , V_3 , V_4 ) ;
case V_32 :
return F_5 ( V_2 , V_3 , V_4 ) ;
case V_33 :
return F_6 ( V_2 , V_3 , V_4 ) ;
case V_31 :
return F_4 ( V_2 , V_3 , V_4 ) ;
case V_35 :
return F_8 ( V_2 , V_19 , V_3 ,
V_4 ) ;
default:
F_13 ( L_14 , V_2 -> V_25 -> V_30 ) ;
return - V_17 ;
}
}
const char * F_16 ( struct V_24 * V_36 ,
const char * V_4 , T_1 * V_26 , char * * V_27 )
{
T_1 V_37 ;
switch ( V_36 -> V_30 ) {
case V_34 :
V_37 = 4 ;
break;
case V_32 :
case V_33 :
case V_31 :
V_37 = 8 ;
break;
case V_35 :
return F_12 ( V_36 , V_4 , V_26 ,
V_27 ) ;
default:
F_13 ( L_14 , V_36 -> V_30 ) ;
return NULL ;
}
* V_27 = NULL ;
* V_26 = 24 ;
return V_4 + V_37 ;
}
