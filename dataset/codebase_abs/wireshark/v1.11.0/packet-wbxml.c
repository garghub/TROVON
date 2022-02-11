static const T_1 *
F_1 ( T_2 V_1 , const T_3 * V_2 )
{
T_4 V_3 = 0 ;
while ( V_2 [ V_3 ] . V_4 ) {
if ( V_2 [ V_3 ] . V_5 == V_1 )
return ( V_2 [ V_3 ] . V_4 ) ;
V_3 ++ ;
}
return ( NULL ) ;
}
static char *
F_2 ( T_5 * V_6 , T_2 V_7 ,
T_6 T_7 V_8 , T_6 T_8 V_8 , T_2 * V_9 )
{
T_2 V_10 = F_3 ( V_6 , V_7 , V_9 ) ;
char * V_11 = F_4 ( F_5 () , L_1 , V_10 ) ;
* V_9 += V_10 ;
return V_11 ;
}
static char *
F_6 ( T_5 * V_6 , T_2 V_7 ,
const char * T_7 V_8 , T_6 T_8 V_8 , T_2 * V_9 )
{
T_2 V_10 = F_3 ( V_6 , V_7 , V_9 ) ;
char * V_11 = F_4 ( F_5 () , L_1 , V_10 ) ;
* V_9 += V_10 ;
return V_11 ;
}
static char *
F_7 ( T_5 * V_6 , T_2 V_7 ,
T_6 T_7 V_8 , T_6 T_8 V_8 , T_2 * V_9 )
{
T_2 V_10 = F_3 ( V_6 , V_7 , V_9 ) ;
char * V_11 = F_4 ( F_5 () , L_1 , V_10 ) ;
* V_9 += V_10 ;
return V_11 ;
}
static char *
F_8 ( T_5 * V_6 , T_2 V_7 ,
const char * T_7 V_8 , T_6 T_8 V_8 , T_2 * V_9 )
{
T_2 V_10 = F_3 ( V_6 , V_7 , V_9 ) ;
char * V_11 = F_4 ( F_5 () , L_1 , V_10 ) ;
* V_9 += V_10 ;
return V_11 ;
}
static char *
F_9 ( T_5 * V_6 , T_2 V_7 , T_2 V_10 )
{
char * V_11 ;
switch ( V_10 ) {
case 4 :
V_11 = F_4 ( F_5 () , L_2
L_3 ,
F_10 ( V_6 , V_7 ) ,
F_10 ( V_6 , V_7 + 1 ) ,
F_10 ( V_6 , V_7 + 2 ) ,
F_10 ( V_6 , V_7 + 3 ) ) ;
break;
case 5 :
V_11 = F_4 ( F_5 () , L_2
L_4 ,
F_10 ( V_6 , V_7 ) ,
F_10 ( V_6 , V_7 + 1 ) ,
F_10 ( V_6 , V_7 + 2 ) ,
F_10 ( V_6 , V_7 + 3 ) ,
F_10 ( V_6 , V_7 + 4 ) ) ;
break;
case 6 :
V_11 = F_4 ( F_5 () , L_2
L_5 ,
F_10 ( V_6 , V_7 ) ,
F_10 ( V_6 , V_7 + 1 ) ,
F_10 ( V_6 , V_7 + 2 ) ,
F_10 ( V_6 , V_7 + 3 ) ,
F_10 ( V_6 , V_7 + 4 ) ,
F_10 ( V_6 , V_7 + 5 ) ) ;
break;
case 7 :
V_11 = F_4 ( F_5 () , L_2
L_6 ,
F_10 ( V_6 , V_7 ) ,
F_10 ( V_6 , V_7 + 1 ) ,
F_10 ( V_6 , V_7 + 2 ) ,
F_10 ( V_6 , V_7 + 3 ) ,
F_10 ( V_6 , V_7 + 4 ) ,
F_10 ( V_6 , V_7 + 5 ) ,
F_10 ( V_6 , V_7 + 6 ) ) ;
break;
default:
V_11 = F_4 ( F_5 () , L_7
L_8 , V_10 ) ;
break;
}
return V_11 ;
}
static char *
F_11 ( T_5 * V_6 , T_2 V_7 , T_2 V_10 )
{
char * V_11 ;
T_9 V_12 ;
T_6 V_13 , V_14 , V_15 , V_16 , V_17 , V_18 ;
T_6 V_19 ;
if ( V_10 == 6 ) {
V_12 = F_10 ( V_6 , V_7 ) & 0x3F ;
V_12 <<= 6 ;
V_19 = F_10 ( V_6 , V_7 + 1 ) ;
V_12 += ( V_19 >> 2 ) ;
V_13 = ( V_19 & 0x03 ) << 2 ;
V_19 = F_10 ( V_6 , V_7 + 2 ) ;
V_13 += ( V_19 >> 6 ) ;
V_14 = ( V_19 & 0x3E ) >> 1 ;
V_15 = ( V_19 & 0x01 ) << 4 ;
V_19 = F_10 ( V_6 , V_7 + 3 ) ;
V_15 += ( V_19 >> 4 ) ;
V_16 = ( V_19 & 0x0F ) << 2 ;
V_19 = F_10 ( V_6 , V_7 + 4 ) ;
V_16 += ( V_19 >> 6 ) ;
V_17 = V_19 & 0x3F ;
V_18 = F_10 ( V_6 , V_7 + 5 ) ;
V_11 = F_4 ( F_5 () , L_9
L_10 ,
V_12 , V_13 , V_14 , V_15 , V_16 , V_17 , V_18 ) ;
} else {
V_11 = F_4 ( F_5 () , L_11
L_8 , V_10 ) ;
}
return V_11 ;
}
static char *
F_12 ( T_5 * V_6 , T_2 V_7 , T_2 V_10 )
{
char * V_11 ;
switch ( V_10 ) {
case 1 :
V_11 = F_4 ( F_5 () , L_12 ,
F_10 ( V_6 , V_7 ) ) ;
break;
case 2 :
V_11 = F_4 ( F_5 () , L_12 ,
F_13 ( V_6 , V_7 ) ) ;
break;
case 3 :
V_11 = F_4 ( F_5 () , L_12 ,
F_14 ( V_6 , V_7 ) ) ;
break;
case 4 :
V_11 = F_4 ( F_5 () , L_12 ,
F_15 ( V_6 , V_7 ) ) ;
break;
default:
V_11 = F_4 ( F_5 () , L_13
L_8 , V_10 ) ;
break;
}
return V_11 ;
}
static char *
F_16 ( T_5 * V_6 , T_2 V_7 ,
T_6 T_7 , T_6 T_8 , T_2 * V_9 )
{
T_2 V_10 = F_3 ( V_6 , V_7 , V_9 ) ;
char * V_11 = NULL ;
switch ( T_8 ) {
case 0 :
switch ( T_7 ) {
case 0x0B :
case 0x0F :
case 0x1A :
case 0x3C :
V_11 = F_12 ( V_6 ,
V_7 + * V_9 , V_10 ) ;
break;
case 0x11 :
V_11 = F_11 ( V_6 ,
V_7 + * V_9 , V_10 ) ;
break;
default:
break;
}
break;
case 1 :
switch ( T_7 ) {
case 0x1C :
case 0x32 :
V_11 = F_12 ( V_6 ,
V_7 + * V_9 , V_10 ) ;
break;
default:
break;
}
break;
case 3 :
switch ( T_7 ) {
case 0x06 :
case 0x0C :
case 0x0D :
case 0x0E :
case 0x11 :
case 0x12 :
case 0x13 :
V_11 = F_12 ( V_6 ,
V_7 + * V_9 , V_10 ) ;
break;
default:
break;
}
break;
default:
break;
}
if ( V_11 == NULL ) {
V_11 = F_4 ( F_5 () , L_14 , V_10 ) ;
}
* V_9 += V_10 ;
return V_11 ;
}
static char *
F_17 ( T_5 * V_6 , T_2 V_7 ,
const char * T_7 , T_6 T_8 V_8 , T_2 * V_9 )
{
T_2 V_10 = F_3 ( V_6 , V_7 , V_9 ) ;
char * V_11 = NULL ;
if ( T_7 && ( ( strcmp ( T_7 , L_15 ) == 0 )
|| ( strcmp ( T_7 , L_16 ) == 0 )
|| ( strcmp ( T_7 , L_17 ) == 0 )
|| ( strcmp ( T_7 , L_18 ) == 0 )
|| ( strcmp ( T_7 , L_19 ) == 0 )
|| ( strcmp ( T_7 , L_20 ) == 0 )
|| ( strcmp ( T_7 , L_21 ) == 0 )
|| ( strcmp ( T_7 , L_22 ) == 0 )
|| ( strcmp ( T_7 , L_23 ) == 0 )
|| ( strcmp ( T_7 , L_24 ) == 0 )
|| ( strcmp ( T_7 , L_25 ) == 0 )
|| ( strcmp ( T_7 , L_26 ) == 0 )
|| ( strcmp ( T_7 , L_27 ) == 0 ) ) )
{
V_11 = F_12 ( V_6 , V_7 + * V_9 , V_10 ) ;
}
else if ( T_7 && ( strcmp ( T_7 , L_28 ) == 0 ) )
{
V_11 = F_11 ( V_6 , V_7 + * V_9 , V_10 ) ;
}
if ( V_11 == NULL ) {
V_11 = F_4 ( F_5 () , L_14 , V_10 ) ;
}
* V_9 += V_10 ;
return V_11 ;
}
static char *
F_18 ( T_5 * V_6 , T_2 V_7 ,
T_6 T_7 , T_6 T_8 , T_2 * V_9 )
{
T_2 V_10 = F_3 ( V_6 , V_7 , V_9 ) ;
char * V_11 = NULL ;
switch ( T_8 ) {
case 0 :
switch ( T_7 ) {
case 0x0B :
case 0x0F :
case 0x1A :
case 0x3C :
V_11 = F_12 ( V_6 ,
V_7 + * V_9 , V_10 ) ;
break;
case 0x11 :
V_11 = F_11 ( V_6 ,
V_7 + * V_9 , V_10 ) ;
break;
default:
break;
}
break;
case 1 :
switch ( T_7 ) {
case 0x1C :
case 0x32 :
V_11 = F_12 ( V_6 ,
V_7 + * V_9 , V_10 ) ;
break;
default:
break;
}
break;
case 3 :
switch ( T_7 ) {
case 0x06 :
case 0x0C :
case 0x0D :
case 0x0E :
case 0x12 :
case 0x13 :
V_11 = F_12 ( V_6 ,
V_7 + * V_9 , V_10 ) ;
break;
default:
break;
}
break;
case 6 :
switch ( T_7 ) {
case 0x1A :
V_11 = F_11 ( V_6 ,
V_7 + * V_9 , V_10 ) ;
break;
default:
break;
}
break;
default:
break;
}
if ( V_11 == NULL ) {
V_11 = F_4 ( F_5 () , L_14 , V_10 ) ;
}
* V_9 += V_10 ;
return V_11 ;
}
static char *
F_19 ( T_5 * V_6 , T_2 V_7 ,
const char * T_7 , T_6 T_8 V_8 , T_2 * V_9 )
{
T_2 V_10 = F_3 ( V_6 , V_7 , V_9 ) ;
char * V_11 = NULL ;
if ( T_7 && ( ( strcmp ( T_7 , L_15 ) == 0 )
|| ( strcmp ( T_7 , L_16 ) == 0 )
|| ( strcmp ( T_7 , L_17 ) == 0 )
|| ( strcmp ( T_7 , L_18 ) == 0 )
|| ( strcmp ( T_7 , L_19 ) == 0 )
|| ( strcmp ( T_7 , L_20 ) == 0 )
|| ( strcmp ( T_7 , L_21 ) == 0 )
|| ( strcmp ( T_7 , L_22 ) == 0 )
|| ( strcmp ( T_7 , L_23 ) == 0 )
|| ( strcmp ( T_7 , L_24 ) == 0 )
|| ( strcmp ( T_7 , L_26 ) == 0 )
|| ( strcmp ( T_7 , L_27 ) == 0 ) ) )
{
V_11 = F_12 ( V_6 , V_7 + * V_9 , V_10 ) ;
}
else
if ( T_7 && ( ( strcmp ( T_7 , L_28 ) == 0 )
|| ( strcmp ( T_7 , L_29 ) == 0 ) ) )
{
V_11 = F_11 ( V_6 , V_7 + * V_9 , V_10 ) ;
}
if ( V_11 == NULL ) {
V_11 = F_4 ( F_5 () , L_14 , V_10 ) ;
}
* V_9 += V_10 ;
return V_11 ;
}
static char *
F_20 ( T_5 * V_6 , T_2 V_7 ,
T_6 T_7 , T_6 T_8 , T_2 * V_9 )
{
T_2 V_10 = F_3 ( V_6 , V_7 , V_9 ) ;
char * V_11 = NULL ;
switch ( T_8 ) {
case 0 :
switch ( T_7 ) {
case 0x0B :
case 0x0F :
case 0x1A :
case 0x3C :
V_11 = F_12 ( V_6 ,
V_7 + * V_9 , V_10 ) ;
break;
case 0x11 :
V_11 = F_11 ( V_6 ,
V_7 + * V_9 , V_10 ) ;
break;
default:
break;
}
break;
case 1 :
switch ( T_7 ) {
case 0x1C :
case 0x32 :
V_11 = F_12 ( V_6 ,
V_7 + * V_9 , V_10 ) ;
break;
default:
break;
}
break;
case 3 :
switch ( T_7 ) {
case 0x06 :
case 0x0C :
case 0x0D :
case 0x0E :
case 0x12 :
case 0x13 :
V_11 = F_12 ( V_6 ,
V_7 + * V_9 , V_10 ) ;
break;
default:
break;
}
break;
case 6 :
switch ( T_7 ) {
case 0x1A :
V_11 = F_11 ( V_6 ,
V_7 + * V_9 , V_10 ) ;
break;
default:
break;
}
break;
case 9 :
switch ( T_7 ) {
case 0x08 :
case 0x0A :
V_11 = F_12 ( V_6 ,
V_7 + * V_9 , V_10 ) ;
break;
default:
break;
}
break;
default:
break;
}
if ( V_11 == NULL ) {
V_11 = F_4 ( F_5 () , L_14 , V_10 ) ;
}
* V_9 += V_10 ;
return V_11 ;
}
static char *
F_21 ( T_5 * V_6 , T_2 V_7 ,
const char * T_7 , T_6 T_8 V_8 , T_2 * V_9 )
{
T_2 V_10 = F_3 ( V_6 , V_7 , V_9 ) ;
char * V_11 = NULL ;
if ( T_7 && ( ( strcmp ( T_7 , L_15 ) == 0 )
|| ( strcmp ( T_7 , L_16 ) == 0 )
|| ( strcmp ( T_7 , L_17 ) == 0 )
|| ( strcmp ( T_7 , L_18 ) == 0 )
|| ( strcmp ( T_7 , L_19 ) == 0 )
|| ( strcmp ( T_7 , L_20 ) == 0 )
|| ( strcmp ( T_7 , L_21 ) == 0 )
|| ( strcmp ( T_7 , L_22 ) == 0 )
|| ( strcmp ( T_7 , L_23 ) == 0 )
|| ( strcmp ( T_7 , L_24 ) == 0 )
|| ( strcmp ( T_7 , L_26 ) == 0 )
|| ( strcmp ( T_7 , L_27 ) == 0 )
|| ( strcmp ( T_7 , L_30 ) == 0 )
|| ( strcmp ( T_7 , L_31 ) == 0 ) ) )
{
V_11 = F_12 ( V_6 , V_7 + * V_9 , V_10 ) ;
}
else
if ( T_7 && ( ( strcmp ( T_7 , L_28 ) == 0 )
|| ( strcmp ( T_7 , L_29 ) == 0 ) ) )
{
V_11 = F_11 ( V_6 , V_7 + * V_9 , V_10 ) ;
}
if ( V_11 == NULL ) {
V_11 = F_4 ( F_5 () , L_14 , V_10 ) ;
}
* V_9 += V_10 ;
return V_11 ;
}
static char *
F_22 ( T_5 * V_6 , T_2 V_7 ,
T_6 T_7 , T_6 T_8 , T_2 * V_9 )
{
T_2 V_10 = F_3 ( V_6 , V_7 , V_9 ) ;
char * V_11 = NULL ;
switch ( T_8 )
{
case 0 :
switch ( T_7 )
{
case 0x0B :
case 0x0F :
case 0x1A :
case 0x3C :
V_11 = F_12 ( V_6 , V_7 + * V_9 , V_10 ) ;
break;
case 0x11 :
V_11 = F_11 ( V_6 , V_7 + * V_9 , V_10 ) ;
break;
default:
break;
}
break;
case 1 :
switch ( T_7 )
{
case 0x1C :
case 0x25 :
case 0x26 :
case 0x27 :
case 0x28 :
case 0x32 :
V_11 = F_12 ( V_6 , V_7 + * V_9 , V_10 ) ;
break;
default:
break;
}
break;
case 3 :
switch ( T_7 )
{
case 0x06 :
case 0x0C :
case 0x0D :
case 0x0E :
case 0x12 :
case 0x13 :
case 0x16 :
case 0x17 :
case 0x18 :
case 0x19 :
case 0x1B :
case 0x1C :
case 0x1F :
case 0x21 :
case 0x24 :
V_11 = F_12 ( V_6 , V_7 + * V_9 , V_10 ) ;
break;
default:
break;
}
break;
case 5 :
switch ( T_7 )
{
case 0x3C :
case 0x3D :
case 0x3E :
V_11 = F_12 ( V_6 , V_7 + * V_9 , V_10 ) ;
break;
default:
break;
}
break;
case 6 :
switch ( T_7 )
{
case 0x1A :
case 0x1C :
V_11 = F_11 ( V_6 , V_7 + * V_9 , V_10 ) ;
break;
default:
break;
}
break;
case 9 :
switch ( T_7 )
{
case 0x08 :
case 0x0A :
case 0x25 :
case 0x28 :
case 0x30 :
case 0x3A :
case 0x3B :
V_11 = F_12 ( V_6 , V_7 + * V_9 , V_10 ) ;
break;
default:
break;
}
break;
case 10 :
switch ( T_7 )
{
case 0x0C :
V_11 = F_12 ( V_6 , V_7 + * V_9 , V_10 ) ;
break;
default:
break;
}
break;
default:
break;
}
if ( V_11 == NULL )
{
V_11 = F_4 ( F_5 () , L_14 , V_10 ) ;
}
* V_9 += V_10 ;
return V_11 ;
}
static char *
F_23 ( T_5 * V_6 , T_2 V_7 ,
const char * T_7 , T_6 T_8 V_8 , T_2 * V_9 )
{
T_2 V_10 = F_3 ( V_6 , V_7 , V_9 ) ;
char * V_11 = NULL ;
if ( T_7 && ( ( strcmp ( T_7 , L_15 ) == 0 )
|| ( strcmp ( T_7 , L_16 ) == 0 )
|| ( strcmp ( T_7 , L_17 ) == 0 )
|| ( strcmp ( T_7 , L_18 ) == 0 )
|| ( strcmp ( T_7 , L_19 ) == 0 )
|| ( strcmp ( T_7 , L_20 ) == 0 )
|| ( strcmp ( T_7 , L_21 ) == 0 )
|| ( strcmp ( T_7 , L_22 ) == 0 )
|| ( strcmp ( T_7 , L_23 ) == 0 )
|| ( strcmp ( T_7 , L_24 ) == 0 )
|| ( strcmp ( T_7 , L_26 ) == 0 )
|| ( strcmp ( T_7 , L_27 ) == 0 )
|| ( strcmp ( T_7 , L_30 ) == 0 )
|| ( strcmp ( T_7 , L_31 ) == 0 )
|| ( strcmp ( T_7 , L_32 ) == 0 )
|| ( strcmp ( T_7 , L_33 ) == 0 )
|| ( strcmp ( T_7 , L_34 ) == 0 )
|| ( strcmp ( T_7 , L_35 ) == 0 )
|| ( strcmp ( T_7 , L_36 ) == 0 )
|| ( strcmp ( T_7 , L_37 ) == 0 )
|| ( strcmp ( T_7 , L_38 ) == 0 )
|| ( strcmp ( T_7 , L_39 ) == 0 )
|| ( strcmp ( T_7 , L_40 ) == 0 )
|| ( strcmp ( T_7 , L_41 ) == 0 )
|| ( strcmp ( T_7 , L_42 ) == 0 )
|| ( strcmp ( T_7 , L_43 ) == 0 )
|| ( strcmp ( T_7 , L_44 ) == 0 )
|| ( strcmp ( T_7 , L_45 ) == 0 )
|| ( strcmp ( T_7 , L_46 ) == 0 )
|| ( strcmp ( T_7 , L_47 ) == 0 )
|| ( strcmp ( T_7 , L_48 ) == 0 )
|| ( strcmp ( T_7 , L_49 ) == 0 )
|| ( strcmp ( T_7 , L_50 ) == 0 ) ) )
{
V_11 = F_12 ( V_6 , V_7 + * V_9 , V_10 ) ;
}
else
if ( T_7 && ( ( strcmp ( T_7 , L_28 ) == 0 )
|| ( strcmp ( T_7 , L_29 ) == 0 ) ) )
{
V_11 = F_11 ( V_6 , V_7 + * V_9 , V_10 ) ;
}
if ( V_11 == NULL ) {
V_11 = F_4 ( F_5 () , L_14 , V_10 ) ;
}
* V_9 += V_10 ;
return V_11 ;
}
static char *
F_24 ( T_5 * V_6 , T_2 V_7 ,
const char * T_7 , T_6 T_8 V_8 , T_2 * V_9 )
{
T_2 V_10 = F_3 ( V_6 , V_7 , V_9 ) ;
char * V_11 = NULL ;
if ( T_7 && ( ( strcmp ( T_7 , L_51 ) == 0 )
|| ( strcmp ( T_7 , L_52 ) == 0 ) ) )
{
V_11 = F_9 ( V_6 , V_7 + * V_9 , V_10 ) ;
}
if ( V_11 == NULL ) {
V_11 = F_4 ( F_5 () , L_14 , V_10 ) ;
}
* V_9 += V_10 ;
return V_11 ;
}
static char *
F_25 ( T_5 * V_6 , T_2 V_7 ,
T_6 T_7 , T_6 T_8 , T_2 * V_9 )
{
T_2 V_10 = F_3 ( V_6 , V_7 , V_9 ) ;
char * V_11 = NULL ;
switch ( T_8 ) {
case 0 :
switch ( T_7 ) {
case 0x0A :
case 0x10 :
V_11 = F_9 ( V_6 ,
V_7 + * V_9 , V_10 ) ;
break;
default:
break;
}
break;
default:
break;
}
if ( V_11 == NULL ) {
V_11 = F_4 ( F_5 () , L_14 , V_10 ) ;
}
* V_9 += V_10 ;
return V_11 ;
}
static char *
F_26 ( T_5 * V_6 , T_2 V_7 ,
const char * T_7 , T_6 T_8 V_8 , T_2 * V_9 )
{
T_2 V_10 = F_3 ( V_6 , V_7 , V_9 ) ;
char * V_11 = NULL ;
if ( T_7 && ( strcmp ( T_7 , L_53 ) == 0 ) )
{
V_11 = F_9 ( V_6 , V_7 + * V_9 , V_10 ) ;
}
if ( V_11 == NULL ) {
V_11 = F_4 ( F_5 () , L_14 , V_10 ) ;
}
* V_9 += V_10 ;
return V_11 ;
}
static char *
F_27 ( T_5 * V_6 , T_2 V_7 ,
T_6 T_7 , T_6 T_8 , T_2 * V_9 )
{
T_2 V_10 = F_3 ( V_6 , V_7 , V_9 ) ;
char * V_11 = NULL ;
switch ( T_8 ) {
case 0 :
switch ( T_7 ) {
case 0x05 :
V_11 = F_9 ( V_6 ,
V_7 + * V_9 , V_10 ) ;
break;
default:
break;
}
break;
default:
break;
}
if ( V_11 == NULL ) {
V_11 = F_4 ( F_5 () , L_14 , V_10 ) ;
}
* V_9 += V_10 ;
return V_11 ;
}
static char *
F_28 ( T_5 * V_6 , T_2 V_5 , T_2 V_20 )
{
char * V_11 = F_4 ( F_5 () , L_54 ,
F_29 ( V_6 , V_20 + V_5 , NULL ) ) ;
return V_11 ;
}
static char *
F_30 ( T_5 * V_6 , T_2 V_5 , T_2 V_20 )
{
char * V_11 = F_4 ( F_5 () , L_55 ,
F_29 ( V_6 , V_20 + V_5 , NULL ) ) ;
return V_11 ;
}
static char *
F_31 ( T_5 * V_6 , T_2 V_5 , T_2 V_20 )
{
char * V_11 = F_4 ( F_5 () , L_56 ,
F_29 ( V_6 , V_20 + V_5 , NULL ) ) ;
return V_11 ;
}
static char *
F_32 ( T_5 * V_6 V_8 , T_2 V_5 , T_2 V_20 V_8 )
{
char * V_11 = F_4 ( F_5 () , L_57 ,
F_33 ( V_5 , & V_21 ,
L_58 ) ) ;
return V_11 ;
}
static char *
F_34 ( T_5 * V_6 V_8 , T_2 V_5 , T_2 V_20 V_8 )
{
char * V_11 = F_4 ( F_5 () , L_57 ,
F_35 ( V_5 , V_22 ,
L_59 ) ) ;
return V_11 ;
}
static char *
F_36 ( T_5 * V_6 V_8 , T_2 V_5 , T_2 V_20 V_8 )
{
char * V_11 = F_4 ( F_5 () , L_57 ,
F_35 ( V_5 , V_23 ,
L_60 ) ) ;
return V_11 ;
}
static const T_10 *
F_37 ( T_5 * V_6 , T_2 V_7 )
{
T_2 V_24 = F_15 ( V_6 , V_7 + 0 ) ;
T_9 V_25 = F_13 ( V_6 , V_7 + 4 ) ;
if ( V_24 == 0xFE050331 && V_25 == 0x2e30 )
{
return & V_26 ;
}
else if ( V_24 == 0xC9050331 && V_25 == 0x2e31 )
{
return & V_27 ;
}
else if ( V_24 == 0xC9080331 && V_25 == 0x2e32 )
{
return & V_28 ;
}
else if ( V_24 == 0xC90B0331 && V_25 == 0x2E33 )
{
return & V_29 ;
}
return & V_28 ;
}
static const T_10 * F_38 ( T_2 V_30 )
{
const T_10 * V_31 = NULL ;
F_39 ( ( L_61 ,
V_30 ) ) ;
if ( V_30 >= 2 ) {
const T_11 * V_32 = V_33 ;
while ( V_32 && V_32 -> V_30 && V_32 -> V_31 ) {
if ( V_32 -> V_30 == V_30 ) {
V_31 = V_32 -> V_31 ;
break;
}
V_32 ++ ;
}
}
return V_31 ;
}
static const T_10 * F_40 (
const char * V_34 , T_5 * V_6 , T_2 V_7 )
{
const T_10 * V_31 = NULL ;
F_39 ( ( L_62 ,
V_34 ) ) ;
if ( V_34 && V_34 [ 0 ] ) {
const T_12 * V_32 = V_35 ;
while ( V_32 && V_32 -> V_34 ) {
if ( F_41 ( V_34 , V_32 -> V_34 ) == 0 ) {
if ( V_32 -> V_36 != NULL ) {
V_31 = V_32 -> V_36 ( V_6 , V_7 ) ;
}
if ( V_31 == NULL ) {
V_31 = V_32 -> V_31 ;
}
break;
}
V_32 ++ ;
}
}
return V_31 ;
}
static const char *
F_42 ( const T_3 * V_37 , T_6 T_8 , T_6 T_7 ) {
const T_1 * V_38 ;
const char * V_39 ;
if ( V_37 ) {
if ( ( V_38 = F_1 ( T_8 , V_37 ) ) ) {
V_39 = F_43 ( T_7 , V_38 ) ;
if ( V_39 ) {
F_39 ( ( L_63 , T_8 , T_7 , V_39 ) ) ;
return V_39 ;
}
F_39 ( ( L_64
V_40 L_65 , T_8 , T_7 ) ) ;
return V_40 ;
}
F_39 ( ( L_64
V_41 L_65 , T_8 , T_7 ) ) ;
return V_41 ;
}
F_39 ( ( L_64
V_42 L_65 , T_8 , T_7 ) ) ;
return V_42 ;
}
static void
F_44 ( T_5 * V_6 , T_13 * V_43 , T_14 * V_44 )
{
F_45 ( V_6 , V_43 , V_44 , NULL ) ;
}
static void
F_46 ( T_5 * V_6 , T_13 * V_43 , T_14 * V_44 )
{
F_45 ( V_6 , V_43 , V_44 , & V_45 ) ;
}
static void
F_45 ( T_5 * V_6 , T_13 * V_43 , T_14 * V_44 ,
const T_10 * V_46 )
{
T_15 * V_47 ;
T_14 * V_48 ;
T_14 * V_49 ;
T_14 * V_50 ;
T_6 V_51 ;
T_16 V_7 = 0 ;
T_2 V_52 ;
T_2 V_53 = 0 ;
T_2 V_54 = 0 ;
T_2 V_55 ;
T_2 V_56 = 0 ;
T_2 V_57 ;
T_2 V_20 ;
T_2 V_58 ;
T_2 V_59 = 0 ;
T_6 V_60 = 0 ;
const T_10 * V_61 = NULL ;
T_17 * V_62 = NULL ;
T_6 V_63 = 0 ;
T_6 V_64 = 0 ;
F_39 ( ( L_66 , V_43 -> V_65 -> V_66 ) ) ;
switch ( V_51 = F_10 ( V_6 , 0 ) ) {
case 0x00 :
break;
case 0x01 :
case 0x02 :
case 0x03 :
break;
default:
F_47 ( V_43 -> V_67 , V_68 , L_67 , V_51 ) ;
V_47 = F_48 ( V_44 , V_69 , V_6 , 0 , - 1 , V_70 ) ;
F_49 ( V_47 , L_68 , V_51 ) ;
return;
}
V_55 = F_3 ( V_6 , 1 , & V_57 ) ;
if ( ! V_55 ) {
V_56 = F_3 ( V_6 , 1 + V_57 , & V_52 ) ;
V_57 += V_52 ;
}
V_7 = 1 + V_57 ;
switch ( V_51 ) {
case 0x00 :
break;
case 0x01 :
case 0x02 :
case 0x03 :
V_53 = F_3 ( V_6 , V_7 , & V_54 ) ;
V_7 += V_54 ;
break;
default:
F_50 () ;
break;
}
F_3 ( V_6 , V_7 , & V_59 ) ;
V_20 = V_7 + V_59 ;
if ( V_55 ) {
V_62 = F_4 ( F_5 () , L_69 ,
F_33 ( V_51 , & V_71 , L_70 ) ,
F_33 ( V_55 , & V_72 , L_70 ) ) ;
} else {
V_52 = F_51 ( V_6 , V_20 + V_56 ) ;
V_62 = F_4 ( F_5 () , L_69 ,
F_33 ( V_51 , & V_71 , L_70 ) ,
F_52 ( V_6 , V_20 + V_56 , V_52 - 1 ) ) ;
}
F_47 ( V_43 -> V_67 , V_68 , L_71 , V_62 ) ;
V_47 = F_48 ( V_44 , V_69 , V_6 , 0 , - 1 , V_70 ) ;
F_49 ( V_47 , L_72 , V_62 ) ;
if ( V_44 ) {
V_48 = F_53 ( V_47 , V_73 ) ;
F_54 ( V_48 , V_74 ,
V_6 , 0 , 1 , V_51 ) ;
if ( V_55 ) {
F_54 ( V_48 , V_75 ,
V_6 , 1 , V_57 , V_55 ) ;
} else {
F_48 ( V_48 , V_76 ,
V_6 , 1 , V_57 , V_77 | V_70 ) ;
}
V_7 = 1 + V_57 ;
if ( V_51 ) {
F_54 ( V_48 , V_78 ,
V_6 , 1 + V_57 , V_54 , V_53 ) ;
V_7 += V_54 ;
}
V_58 = F_3 ( V_6 , V_7 , & V_52 ) ;
V_20 = V_7 + V_52 ;
V_47 = F_55 ( V_48 ,
V_6 , V_7 , V_52 + V_58 , L_73 ,
V_58 ) ;
if ( V_48 && V_58 ) {
V_49 = F_53 ( V_47 ,
V_79 ) ;
F_56 ( V_49 , V_6 ,
V_20 , V_58 ) ;
}
V_7 += V_52 + V_58 ;
if ( V_80 ) {
F_55 ( V_48 , V_6 , V_7 , - 1 ,
L_74
L_75 ) ;
return;
}
V_47 = F_55 ( V_48 , V_6 , V_7 , - 1 ,
L_76 ) ;
V_50 = F_53 ( V_47 , V_81 ) ;
if ( V_48 ) {
if ( V_46 != NULL ) {
V_61 = V_46 ;
F_49 ( V_47 ,
L_77 ,
V_61 -> V_82 ) ;
} else {
V_61 = F_38 ( V_55 ) ;
if ( ! V_61 ) {
V_61 = F_40 (
V_43 -> V_83 , V_6 , V_7 ) ;
if ( ! V_61 ) {
F_55 ( V_50 ,
V_6 , V_7 , - 1 ,
L_78
L_79 ) ;
} else {
F_49 ( V_47 ,
L_80
L_81 ,
V_43 -> V_83 , V_61 -> V_82 ) ;
}
}
}
if ( V_61 && V_84 ) {
F_55 ( V_50 ,
V_6 , V_7 , - 1 ,
L_78
L_82
L_83 ) ;
V_61 = NULL ;
}
F_55 ( V_50 , V_6 ,
V_7 , - 1 ,
L_84
L_85
L_86 ) ;
if ( V_61 ) {
V_52 = F_57 ( V_50 ,
V_6 , V_7 , V_20 , & V_60 , & V_63 ,
& V_64 , V_61 ) ;
} else {
V_52 = F_58 ( V_50 , V_6 , V_7 ,
V_20 , & V_60 , & V_63 , & V_64 ) ;
}
}
return;
}
}
static void
F_56 ( T_14 * V_44 , T_5 * V_6 , T_2 V_20 ,
T_2 V_58 )
{
T_2 V_85 = V_20 ;
T_2 V_52 = 0 ;
T_2 V_86 = V_20 + V_58 ;
F_55 ( V_44 , V_6 , V_85 , V_86 ,
L_87 ) ;
while ( V_85 < V_86 ) {
V_52 = F_51 ( V_6 , V_85 ) ;
F_55 ( V_44 , V_6 , V_85 , V_52 ,
L_88 ,
V_85 - V_20 , V_52 ,
F_52 ( V_6 , V_85 , V_52 - 1 ) ) ;
V_85 += V_52 ;
}
}
static const char * F_59 ( T_6 V_60 ) {
return V_87 + ( 512 - 2 * ( V_60 ) ) ;
}
static T_2
F_57 ( T_14 * V_44 , T_5 * V_6 , T_2 V_7 ,
T_2 V_20 , T_6 * V_60 , T_6 * V_63 , T_6 * V_64 ,
const T_10 * V_31 )
{
T_2 V_88 = F_60 ( V_6 ) ;
T_2 V_85 = V_7 ;
T_2 V_52 ;
T_16 V_89 ;
T_2 V_90 ;
T_2 V_91 ;
T_6 V_19 ;
T_2 V_92 ;
T_6 V_93 = 0 ;
T_6 V_94 = 0 ;
const char * V_95 ;
const char * V_96 ;
T_6 V_97 = FALSE ;
V_95 = NULL ;
F_39 ( ( L_89 , * V_60 , V_7 ) ) ;
while ( V_85 < V_88 ) {
V_19 = F_10 ( V_6 , V_85 ) ;
F_39 ( ( L_90 , * V_60 , V_19 , V_85 , V_88 ) ) ;
if ( ( V_19 & 0x3F ) < 4 ) switch ( V_19 ) {
case 0x00 :
* V_63 = F_10 ( V_6 , V_85 + 1 ) ;
F_55 ( V_44 , V_6 , V_85 , 2 ,
L_91
L_92
L_93 ,
* V_63 ) ;
V_85 += 2 ;
break;
case 0x01 :
if ( V_93 ) {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_95
L_96 ,
* V_60 , * V_63 ,
V_93 , F_59 ( * V_60 ) ,
V_95 ) ;
} else {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_97
L_96 ,
* V_60 , * V_63 , F_59 ( * V_60 ) ,
V_95 ? V_95 : L_98 ) ;
}
( * V_60 ) -- ;
V_85 ++ ;
F_39 ( ( L_99 , * V_60 , V_85 - V_7 ) ) ;
return ( V_85 - V_7 ) ;
case 0x02 :
V_90 = F_3 ( V_6 , V_85 + 1 , & V_52 ) ;
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 ,
L_94
L_100
L_101 ,
* V_60 , * V_63 , F_59 ( * V_60 ) , V_90 ) ;
V_85 += 1 + V_52 ;
break;
case 0x03 :
V_52 = F_51 ( V_6 , V_85 + 1 ) ;
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 ,
L_94
L_102
L_103 ,
* V_60 , * V_63 , F_59 ( * V_60 ) ,
F_52 ( V_6 , V_85 + 1 , V_52 - 1 ) ) ;
V_85 += 1 + V_52 ;
break;
case 0x40 :
case 0x41 :
case 0x42 :
V_52 = F_51 ( V_6 , V_85 + 1 ) ;
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 ,
L_94
L_104
L_105 ,
* V_60 , * V_63 ,
V_19 & 0x0f , F_59 ( * V_60 ) ,
F_42 ( V_31 -> V_98 , 0 , V_19 ) ,
F_52 ( V_6 , V_85 + 1 , V_52 - 1 ) ) ;
V_85 += 1 + V_52 ;
break;
case 0x43 :
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_106
L_107 ,
* V_60 , * V_63 , F_59 ( * V_60 ) ) ;
V_52 = F_61 ( V_44 , V_6 , V_85 ,
V_20 , * V_60 , V_64 , V_31 ) ;
V_85 += V_52 ;
if ( V_85 >= V_88 ) {
F_39 ( ( L_108 , * V_60 , V_85 - V_7 ) ) ;
F_62 ( V_99 ) ;
}
F_55 ( V_44 , V_6 , V_85 - 1 , 1 ,
L_94
L_109
L_110 ,
* V_60 , * V_63 , F_59 ( * V_60 ) ) ;
break;
case 0x80 :
case 0x81 :
case 0x82 :
V_91 = F_3 ( V_6 , V_85 + 1 , & V_52 ) ;
{ char * V_39 ;
if ( V_31 -> V_100 [ V_19 & 0x03 ] )
V_39 = ( V_31 -> V_100 [ V_19 & 0x03 ] ) ( V_6 , V_91 , V_20 ) ;
else
V_39 = F_4 ( F_5 () , L_111 , V_19 & 0x03 ,
F_42 ( V_31 -> V_98 , 0 , V_19 ) ) ;
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 ,
L_94
L_112
L_113 ,
* V_60 , * V_63 , V_19 & 0x0f , F_59 ( * V_60 ) ,
V_39 ) ;
}
V_85 += 1 + V_52 ;
break;
case 0x83 :
V_91 = F_3 ( V_6 , V_85 + 1 , & V_52 ) ;
V_89 = F_51 ( V_6 , V_20 + V_91 ) ;
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 ,
L_94
L_114
L_103 ,
* V_60 , * V_63 , F_59 ( * V_60 ) ,
F_52 ( V_6 , V_20 + V_91 , V_89 - 1 ) ) ;
V_85 += 1 + V_52 ;
break;
case 0xC0 :
case 0xC1 :
case 0xC2 :
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_115
L_116 ,
* V_60 , * V_63 , V_19 & 0x0f , F_59 ( * V_60 ) ,
F_42 ( V_31 -> V_98 , 0 , V_19 ) ) ;
V_85 ++ ;
break;
case 0xC3 :
if ( F_10 ( V_6 , 0 ) ) {
char * V_11 ;
if ( V_93 ) {
if ( V_31 -> V_101 ) {
V_11 = V_31 -> V_101 ( V_6 , V_85 + 1 ,
V_93 , * V_63 , & V_52 ) ;
} else {
V_11 = F_2 ( V_6 , V_85 + 1 ,
V_93 , * V_63 , & V_52 ) ;
}
} else {
if ( V_31 -> V_102 ) {
V_11 = V_31 -> V_102 ( V_6 , V_85 + 1 ,
V_95 , * V_63 , & V_52 ) ;
} else {
V_11 = F_6 ( V_6 , V_85 + 1 ,
V_95 , * V_63 , & V_52 ) ;
}
}
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 ,
L_94
L_117
L_113 ,
* V_60 , * V_63 , F_59 ( * V_60 ) , V_11 ) ;
V_85 += 1 + V_52 ;
} else {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_118
L_119 ,
* V_60 , * V_63 ) ;
V_85 = V_88 ;
F_39 ( ( L_99 , * V_60 , V_85 - V_7 ) ) ;
return ( V_85 - V_7 ) ;
}
break;
} else {
V_92 = 0 ;
if ( ( V_19 & 0x3F ) == 4 ) {
F_39 ( ( L_120 , V_19 , V_85 ) ) ;
V_91 = F_3 ( V_6 , V_85 + 1 , & V_92 ) ;
V_89 = F_51 ( V_6 , V_20 + V_91 ) ;
V_96 = ( T_17 * ) F_63 ( V_6 , V_20 + V_91 , V_89 ) ;
V_94 = 0 ;
} else {
V_94 = V_19 & 0x3F ;
V_96 = F_42 ( V_31 -> V_103 , * V_63 ,
V_94 ) ;
}
if ( V_19 & 0x40 ) {
if ( V_97 ) {
F_39 ( ( L_121 , V_85 ) ) ;
( * V_60 ) ++ ;
V_52 = F_57 ( V_44 , V_6 , V_85 , V_20 ,
V_60 , V_63 , V_64 , V_31 ) ;
V_85 += V_52 ;
} else {
if ( ( V_19 & 0x3F ) == 4 ) {
V_95 = V_96 ;
V_93 = 0 ;
} else {
V_93 = V_94 ;
V_95 = V_96 ;
}
if ( V_19 & 0x80 ) {
if ( V_94 ) {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_122
L_123 ,
* V_60 , * V_63 , V_94 ,
F_59 ( * V_60 ) , V_96 ) ;
V_85 ++ ;
} else {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_124
L_123 ,
* V_60 , * V_63 , F_59 ( * V_60 ) , V_96 ) ;
V_85 += 1 + V_92 ;
}
V_52 = F_61 ( V_44 , V_6 ,
V_85 , V_20 , * V_60 , V_64 , V_31 ) ;
V_85 += V_52 ;
if ( V_85 >= V_88 ) {
F_39 ( ( L_108 ,
* V_60 , V_85 - V_7 ) ) ;
F_62 ( V_99 ) ;
}
F_55 ( V_44 , V_6 , V_85 - 1 , 1 ,
L_94
L_125
L_126 ,
* V_60 , * V_63 , F_59 ( * V_60 ) ) ;
} else {
if ( V_94 ) {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_127
L_128 ,
* V_60 , * V_63 , V_94 ,
F_59 ( * V_60 ) , V_96 ) ;
V_85 ++ ;
} else {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_129
L_128 ,
* V_60 , * V_63 , F_59 ( * V_60 ) ,
V_96 ) ;
V_85 += 1 + V_92 ;
}
}
V_97 = TRUE ;
F_39 ( ( L_130 , V_85 ) ) ;
}
} else {
F_39 ( ( L_131 , V_85 ) ) ;
( * V_60 ) ++ ;
if ( V_19 & 0x80 ) {
if ( V_94 ) {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_132
L_123 ,
* V_60 , * V_63 , V_94 ,
F_59 ( * V_60 ) , V_96 ) ;
V_85 ++ ;
V_52 = F_61 ( V_44 , V_6 ,
V_85 , V_20 , * V_60 , V_64 , V_31 ) ;
V_85 += V_52 ;
if ( V_85 > V_88 ) {
F_39 ( ( L_108 , * V_60 , V_85 - V_7 ) ) ;
F_62 ( V_99 ) ;
}
F_55 ( V_44 , V_6 , V_85 - 1 , 1 ,
L_94
L_133
L_134 ,
* V_60 , * V_63 , F_59 ( * V_60 ) ) ;
} else {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_135
L_123 ,
* V_60 , * V_63 , F_59 ( * V_60 ) , V_96 ) ;
V_85 += 1 + V_92 ;
V_52 = F_61 ( V_44 , V_6 ,
V_85 , V_20 , * V_60 , V_64 , V_31 ) ;
V_85 += V_52 ;
if ( V_85 >= V_88 ) {
F_39 ( ( L_108 , * V_60 , V_85 - V_7 ) ) ;
F_62 ( V_99 ) ;
}
F_55 ( V_44 , V_6 , V_85 - 1 , 1 ,
L_94
L_97
L_134 ,
* V_60 , * V_63 , F_59 ( * V_60 ) ) ;
}
} else {
if ( V_94 ) {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_136
L_137 ,
* V_60 , * V_63 , V_94 ,
F_59 ( * V_60 ) , V_96 ) ;
V_85 ++ ;
} else {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_138
L_137 ,
* V_60 , * V_63 , F_59 ( * V_60 ) ,
V_96 ) ;
V_85 += 1 + V_92 ;
}
}
( * V_60 ) -- ;
}
}
}
F_39 ( ( L_139 , * V_60 , V_85 - V_7 ) ) ;
return ( V_85 - V_7 ) ;
}
static T_2
F_58 ( T_14 * V_44 , T_5 * V_6 , T_2 V_7 ,
T_2 V_20 , T_6 * V_60 ,
T_6 * V_63 , T_6 * V_64 )
{
T_2 V_88 = F_60 ( V_6 ) ;
T_2 V_85 = V_7 ;
T_2 V_52 ;
T_16 V_89 ;
T_2 V_90 ;
T_2 V_91 ;
T_6 V_19 ;
T_2 V_92 ;
T_6 V_93 = 0 ;
T_6 V_94 = 0 ;
const char * V_95 ;
const char * V_96 ;
char * V_104 = NULL ;
char * V_105 = NULL ;
T_6 V_97 = FALSE ;
V_95 = NULL ;
F_39 ( ( L_140 , * V_60 , V_7 ) ) ;
while ( V_85 < V_88 ) {
V_19 = F_10 ( V_6 , V_85 ) ;
F_39 ( ( L_90 , * V_60 , V_19 , V_85 , V_88 ) ) ;
if ( ( V_19 & 0x3F ) < 4 ) switch ( V_19 ) {
case 0x00 :
* V_63 = F_10 ( V_6 , V_85 + 1 ) ;
F_55 ( V_44 , V_6 , V_85 , 2 ,
L_91
L_92
L_93 ,
* V_63 ) ;
V_85 += 2 ;
break;
case 0x01 :
if ( V_93 ) {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_95
L_96 ,
* V_60 , * V_63 , V_93 ,
F_59 ( * V_60 ) ,
V_95 ) ;
} else {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_97
L_96 ,
* V_60 , * V_63 , F_59 ( * V_60 ) ,
V_95 ? V_95 : L_98 ) ;
}
( * V_60 ) -- ;
V_85 ++ ;
F_39 ( ( L_99 ,
* V_60 , V_85 - V_7 ) ) ;
return ( V_85 - V_7 ) ;
case 0x02 :
V_90 = F_3 ( V_6 , V_85 + 1 , & V_52 ) ;
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 ,
L_94
L_100
L_101 ,
* V_60 , * V_63 , F_59 ( * V_60 ) , V_90 ) ;
V_85 += 1 + V_52 ;
break;
case 0x03 :
V_52 = F_51 ( V_6 , V_85 + 1 ) ;
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 ,
L_94
L_102
L_103 ,
* V_60 , * V_63 , F_59 ( * V_60 ) ,
F_52 ( V_6 , V_85 + 1 , V_52 - 1 ) ) ;
V_85 += 1 + V_52 ;
break;
case 0x40 :
case 0x41 :
case 0x42 :
V_52 = F_51 ( V_6 , V_85 + 1 ) ;
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 ,
L_94
L_104
L_141 ,
* V_60 , * V_63 , V_19 & 0x0f , F_59 ( * V_60 ) ,
F_52 ( V_6 , V_85 + 1 , V_52 - 1 ) ) ;
V_85 += 1 + V_52 ;
break;
case 0x43 :
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_106
L_107 ,
* V_60 , * V_63 , F_59 ( * V_60 ) ) ;
V_52 = F_64 ( V_44 , V_6 , V_85 , V_20 ,
* V_60 , V_64 ) ;
V_85 += V_52 ;
if ( V_85 >= V_88 ) {
F_39 ( ( L_108 ,
* V_60 , V_85 - V_7 ) ) ;
F_62 ( V_99 ) ;
}
F_55 ( V_44 , V_6 , V_85 - 1 , 1 ,
L_94
L_109
L_110 ,
* V_60 , * V_63 , F_59 ( * V_60 ) ) ;
break;
case 0x80 :
case 0x81 :
case 0x82 :
V_91 = F_3 ( V_6 , V_85 + 1 , & V_52 ) ;
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 ,
L_94
L_112
L_142 ,
* V_60 , * V_63 , V_19 & 0x0f , F_59 ( * V_60 ) ,
V_91 ) ;
V_85 += 1 + V_52 ;
break;
case 0x83 :
V_91 = F_3 ( V_6 , V_85 + 1 , & V_52 ) ;
V_89 = F_51 ( V_6 , V_20 + V_91 ) ;
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 ,
L_94
L_114
L_103 ,
* V_60 , * V_63 , F_59 ( * V_60 ) ,
F_52 ( V_6 , V_20 + V_91 , V_89 - 1 ) ) ;
V_85 += 1 + V_52 ;
break;
case 0xC0 :
case 0xC1 :
case 0xC2 :
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_115
L_143 ,
* V_60 , * V_63 , V_19 & 0x0f , F_59 ( * V_60 ) ) ;
V_85 ++ ;
break;
case 0xC3 :
if ( F_10 ( V_6 , 0 ) ) {
V_91 = F_3 ( V_6 , V_85 + 1 , & V_52 ) ;
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 + V_91 ,
L_94
L_117
L_144 ,
* V_60 , * V_63 , F_59 ( * V_60 ) , V_91 ) ;
V_85 += 1 + V_52 + V_91 ;
} else {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_118
L_119 ,
* V_60 , * V_63 ) ;
V_85 = V_88 ;
F_39 ( ( L_99 ,
* V_60 , V_85 - V_7 ) ) ;
return ( V_85 - V_7 ) ;
}
break;
} else {
V_92 = 0 ;
if ( ( V_19 & 0x3F ) == 4 ) {
F_39 ( ( L_145
L_146 , V_19 , V_85 ) ) ;
V_91 = F_3 ( V_6 , V_85 + 1 , & V_92 ) ;
V_89 = F_51 ( V_6 , V_20 + V_91 ) ;
V_96 = ( T_17 * ) F_63 ( V_6 , V_20 + V_91 , V_89 ) ;
V_94 = 0 ;
} else {
V_94 = V_19 & 0x3F ;
V_105 = F_4 ( F_5 () , L_147 ,
V_94 ) ;
V_96 = V_105 ;
}
if ( V_19 & 0x40 ) {
if ( V_97 ) {
F_39 ( ( L_121 , V_85 ) ) ;
( * V_60 ) ++ ;
V_52 = F_58 ( V_44 , V_6 , V_85 , V_20 , V_60 ,
V_63 , V_64 ) ;
V_85 += V_52 ;
} else {
if ( ( V_19 & 0x3F ) == 4 ) {
V_95 = V_96 ;
V_93 = 0 ;
} else {
V_93 = V_94 ;
V_104 = F_4 ( F_5 () , L_147 ,
V_94 ) ;
V_95 = V_104 ;
}
if ( V_19 & 0x80 ) {
if ( V_94 ) {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_122
L_123 ,
* V_60 , * V_63 , V_94 ,
F_59 ( * V_60 ) , V_96 ) ;
V_85 ++ ;
} else {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_124
L_123 ,
* V_60 , * V_63 , F_59 ( * V_60 ) ,
V_96 ) ;
V_85 += 1 + V_92 ;
}
V_52 = F_64 ( V_44 , V_6 ,
V_85 , V_20 , * V_60 , V_64 ) ;
V_85 += V_52 ;
if ( V_85 >= V_88 ) {
F_39 ( ( L_148
L_149 ,
* V_60 , V_85 - V_7 ) ) ;
F_62 ( V_99 ) ;
}
F_55 ( V_44 , V_6 , V_85 - 1 , 1 ,
L_94
L_125
L_126 ,
* V_60 , * V_63 , F_59 ( * V_60 ) ) ;
} else {
if ( V_94 ) {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_127
L_128 ,
* V_60 , * V_63 , V_94 ,
F_59 ( * V_60 ) , V_96 ) ;
V_85 ++ ;
} else {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_129
L_128 ,
* V_60 , * V_63 , F_59 ( * V_60 ) ,
V_96 ) ;
V_85 += 1 + V_92 ;
}
}
V_97 = TRUE ;
F_39 ( ( L_150
L_151 , V_85 ) ) ;
}
} else {
F_39 ( ( L_131 , V_85 ) ) ;
( * V_60 ) ++ ;
if ( V_19 & 0x80 ) {
if ( V_94 ) {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_132
L_123 ,
* V_60 , * V_63 , V_94 ,
F_59 ( * V_60 ) , V_96 ) ;
V_85 ++ ;
V_52 = F_64 ( V_44 , V_6 ,
V_85 , V_20 , * V_60 , V_64 ) ;
V_85 += V_52 ;
if ( V_85 >= V_88 ) {
F_39 ( ( L_148
L_149 ,
* V_60 , V_85 - V_7 ) ) ;
F_62 ( V_99 ) ;
}
F_55 ( V_44 , V_6 , V_85 - 1 , 1 ,
L_94
L_133
L_134 ,
* V_60 , * V_63 , F_59 ( * V_60 ) ) ;
} else {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_135
L_123 ,
* V_60 , * V_63 , F_59 ( * V_60 ) ,
V_96 ) ;
V_85 += 1 + V_92 ;
V_52 = F_64 ( V_44 , V_6 ,
V_85 , V_20 , * V_60 , V_64 ) ;
V_85 += V_52 ;
if ( V_85 >= V_88 ) {
F_39 ( ( L_148
L_149 ,
* V_60 , V_85 - V_7 ) ) ;
F_62 ( V_99 ) ;
}
F_55 ( V_44 , V_6 , V_85 - 1 , 1 ,
L_94
L_97
L_134 ,
* V_60 , * V_63 , F_59 ( * V_60 ) ) ;
}
} else {
if ( V_94 ) {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_136
L_137 ,
* V_60 , * V_63 , V_94 ,
F_59 ( * V_60 ) , V_96 ) ;
V_85 ++ ;
} else {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_94
L_138
L_137 ,
* V_60 , * V_63 , F_59 ( * V_60 ) ,
V_96 ) ;
V_85 += 1 + V_92 ;
}
}
( * V_60 ) -- ;
}
}
}
F_39 ( ( L_139 ,
* V_60 , V_85 - V_7 ) ) ;
return ( V_85 - V_7 ) ;
}
static T_2
F_61 ( T_14 * V_44 , T_5 * V_6 ,
T_2 V_7 , T_2 V_20 , T_6 V_60 , T_6 * V_64 ,
const T_10 * V_31 )
{
T_2 V_88 = F_60 ( V_6 ) ;
T_2 V_85 = V_7 ;
T_2 V_52 ;
T_16 V_89 ;
T_2 V_90 ;
T_2 V_91 ;
T_6 V_19 ;
T_6 V_106 = 0 ;
const char * V_107 = NULL ;
F_39 ( ( L_152 ,
V_60 , V_7 ) ) ;
while ( V_85 < V_88 ) {
V_19 = F_10 ( V_6 , V_85 ) ;
F_39 ( ( L_153
L_154 , V_60 , V_19 , V_85 , V_88 ) ) ;
if ( ( V_19 & 0x3F ) < 5 ) switch ( V_19 ) {
case 0x00 :
* V_64 = F_10 ( V_6 , V_85 + 1 ) ;
F_55 ( V_44 , V_6 , V_85 , 2 ,
L_155
L_156 ,
* V_64 ) ;
V_85 += 2 ;
break;
case 0x01 :
V_85 ++ ;
F_39 ( ( L_157 ,
V_60 , V_85 - V_7 ) ) ;
return ( V_85 - V_7 ) ;
case 0x02 :
V_90 = F_3 ( V_6 , V_85 + 1 , & V_52 ) ;
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 ,
L_158
L_100
L_159 ,
V_60 , * V_64 , F_59 ( V_60 ) , V_90 ) ;
V_85 += 1 + V_52 ;
break;
case 0x03 :
V_52 = F_51 ( V_6 , V_85 + 1 ) ;
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 ,
L_158
L_102
L_160 ,
V_60 , * V_64 , F_59 ( V_60 ) ,
F_52 ( V_6 , V_85 + 1 , V_52 - 1 ) ) ;
V_85 += 1 + V_52 ;
break;
case 0x04 :
V_91 = F_3 ( V_6 , V_85 + 1 , & V_52 ) ;
V_89 = F_51 ( V_6 , V_20 + V_91 ) ;
V_106 = 0 ;
V_107 = F_52 ( V_6 ,
V_20 + V_91 , V_89 - 1 ) ;
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 ,
L_158
L_161
L_162 ,
V_60 , * V_64 , F_59 ( V_60 ) ,
V_107 ) ;
V_85 += 1 + V_52 ;
break;
case 0x40 :
case 0x41 :
case 0x42 :
V_52 = F_51 ( V_6 , V_85 + 1 ) ;
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 ,
L_158
L_104
L_163 ,
V_60 , * V_64 , V_19 & 0x0f , F_59 ( V_60 ) ,
F_42 ( V_31 -> V_98 , 0 , V_19 ) ,
F_52 ( V_6 , V_85 + 1 , V_52 - 1 ) ) ;
V_85 += 1 + V_52 ;
break;
case 0x80 :
case 0x81 :
case 0x82 :
V_91 = F_3 ( V_6 , V_85 + 1 , & V_52 ) ;
{ char * V_39 ;
if ( V_31 -> V_100 [ V_19 & 0x03 ] )
V_39 = ( V_31 -> V_100 [ V_19 & 0x03 ] ) ( V_6 , V_91 , V_20 ) ;
else
V_39 = F_4 ( F_5 () , L_111 , V_19 & 0x03 ,
F_42 ( V_31 -> V_98 , 0 , V_19 ) ) ;
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 ,
L_94
L_112
L_164 ,
V_60 , * V_64 , V_19 & 0x0f , F_59 ( V_60 ) ,
V_39 ) ;
}
V_85 += 1 + V_52 ;
break;
case 0x83 :
V_91 = F_3 ( V_6 , V_85 + 1 , & V_52 ) ;
V_89 = F_51 ( V_6 , V_20 + V_91 ) ;
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 ,
L_158
L_114
L_160 ,
V_60 , * V_64 , F_59 ( V_60 ) ,
F_52 ( V_6 , V_20 + V_91 , V_89 - 1 ) ) ;
V_85 += 1 + V_52 ;
break;
case 0xC0 :
case 0xC1 :
case 0xC2 :
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_158
L_115
L_165 ,
V_60 , * V_64 , V_19 & 0x0f , F_59 ( V_60 ) ,
F_42 ( V_31 -> V_98 , 0 , V_19 ) ) ;
V_85 ++ ;
break;
case 0xC3 :
if ( F_10 ( V_6 , 0 ) ) {
char * V_11 ;
if ( V_106 ) {
if ( V_31 -> V_108 ) {
V_11 = V_31 -> V_108 ( V_6 , V_85 + 1 ,
V_106 , * V_64 , & V_52 ) ;
} else {
V_11 = F_7 ( V_6 , V_85 + 1 ,
V_106 , * V_64 , & V_52 ) ;
}
} else {
if ( V_31 -> V_102 ) {
V_11 = V_31 -> V_109 ( V_6 , V_85 + 1 ,
V_107 , * V_64 , & V_52 ) ;
} else {
V_11 = F_8 ( V_6 , V_85 + 1 ,
V_107 , * V_64 , & V_52 ) ;
}
}
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 ,
L_158
L_117
L_166 ,
V_60 , * V_64 , F_59 ( V_60 ) , V_11 ) ;
V_85 += 1 + V_52 ;
} else {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_158
L_118
L_119 ,
V_60 , * V_64 ) ;
V_85 = V_88 ;
F_39 ( ( L_157 ,
V_60 , V_85 - V_7 ) ) ;
return ( V_85 - V_7 ) ;
}
break;
default:
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_158
L_167
L_168 ,
V_60 , * V_64 ,
F_33 ( V_19 , & V_110 , L_70 ) ) ;
V_85 = V_88 ;
break;
} else {
if ( V_19 & 0x80 ) {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_158
L_169
L_166 ,
V_60 , * V_64 , V_19 & 0x7f , F_59 ( V_60 ) ,
F_42 ( V_31 -> V_111 , * V_64 , V_19 ) ) ;
V_85 ++ ;
} else {
V_106 = V_19 & 0x7f ;
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_158
L_170
L_171 ,
V_60 , * V_64 , V_106 , F_59 ( V_60 ) ,
F_42 ( V_31 -> V_112 , * V_64 , V_19 ) ) ;
V_85 ++ ;
}
}
}
F_39 ( ( L_172 ,
V_60 , V_85 - V_7 ) ) ;
return ( V_85 - V_7 ) ;
}
static T_2
F_64 ( T_14 * V_44 , T_5 * V_6 ,
T_2 V_7 , T_2 V_20 , T_6 V_60 , T_6 * V_64 )
{
T_2 V_88 = F_60 ( V_6 ) ;
T_2 V_85 = V_7 ;
T_2 V_52 ;
T_16 V_89 ;
T_2 V_90 ;
T_2 V_91 ;
T_6 V_19 ;
F_39 ( ( L_173 , V_60 , V_7 ) ) ;
while ( V_85 < V_88 ) {
V_19 = F_10 ( V_6 , V_85 ) ;
F_39 ( ( L_153
L_154 , V_60 , V_19 , V_85 , V_88 ) ) ;
if ( ( V_19 & 0x3F ) < 5 ) switch ( V_19 ) {
case 0x00 :
* V_64 = F_10 ( V_6 , V_85 + 1 ) ;
F_55 ( V_44 , V_6 , V_85 , 2 ,
L_155
L_156 ,
* V_64 ) ;
V_85 += 2 ;
break;
case 0x01 :
V_85 ++ ;
F_39 ( ( L_157 ,
V_60 , V_85 - V_7 ) ) ;
return ( V_85 - V_7 ) ;
case 0x02 :
V_90 = F_3 ( V_6 , V_85 + 1 , & V_52 ) ;
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 ,
L_158
L_100
L_159 ,
V_60 , * V_64 , F_59 ( V_60 ) , V_90 ) ;
V_85 += 1 + V_52 ;
break;
case 0x03 :
V_52 = F_51 ( V_6 , V_85 + 1 ) ;
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 ,
L_158
L_102
L_160 ,
V_60 , * V_64 , F_59 ( V_60 ) ,
F_52 ( V_6 , V_85 + 1 , V_52 - 1 ) ) ;
V_85 += 1 + V_52 ;
break;
case 0x04 :
V_91 = F_3 ( V_6 , V_85 + 1 , & V_52 ) ;
V_89 = F_51 ( V_6 , V_20 + V_91 ) ;
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 ,
L_158
L_161
L_162 ,
V_60 , * V_64 , F_59 ( V_60 ) ,
F_52 ( V_6 , V_20 + V_91 , V_89 - 1 ) ) ;
V_85 += 1 + V_52 ;
break;
case 0x40 :
case 0x41 :
case 0x42 :
V_52 = F_51 ( V_6 , V_85 + 1 ) ;
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 ,
L_158
L_104
L_174 ,
V_60 , * V_64 , V_19 & 0x0f , F_59 ( V_60 ) ,
F_52 ( V_6 , V_85 + 1 , V_52 - 1 ) ) ;
V_85 += 1 + V_52 ;
break;
case 0x80 :
case 0x81 :
case 0x82 :
V_91 = F_3 ( V_6 , V_85 + 1 , & V_52 ) ;
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 ,
L_158
L_112
L_175 ,
V_60 , * V_64 , V_19 & 0x0f , F_59 ( V_60 ) ,
V_91 ) ;
V_85 += 1 + V_52 ;
break;
case 0x83 :
V_91 = F_3 ( V_6 , V_85 + 1 , & V_52 ) ;
V_89 = F_51 ( V_6 , V_20 + V_91 ) ;
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 ,
L_158
L_114
L_160 ,
V_60 , * V_64 , F_59 ( V_60 ) ,
F_52 ( V_6 , V_20 + V_91 , V_89 - 1 ) ) ;
V_85 += 1 + V_52 ;
break;
case 0xC0 :
case 0xC1 :
case 0xC2 :
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_158
L_115
L_176 ,
V_60 , * V_64 , V_19 & 0x0f , F_59 ( V_60 ) ) ;
V_85 ++ ;
break;
case 0xC3 :
if ( F_10 ( V_6 , 0 ) ) {
V_91 = F_3 ( V_6 , V_85 + 1 , & V_52 ) ;
F_55 ( V_44 , V_6 , V_85 , 1 + V_52 + V_91 ,
L_158
L_117
L_177 ,
V_60 , * V_64 , F_59 ( V_60 ) , V_91 ) ;
V_85 += 1 + V_52 + V_91 ;
} else {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_158
L_118
L_119 ,
V_60 , * V_64 ) ;
V_85 = V_88 ;
F_39 ( ( L_157 ,
V_60 , V_85 - V_7 ) ) ;
return ( V_85 - V_7 ) ;
}
break;
default:
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_158
L_167
L_168 ,
V_60 , * V_64 ,
F_33 ( V_19 , & V_110 , L_70 ) ) ;
V_85 = V_88 ;
break;
} else {
if ( V_19 & 0x80 ) {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_158
L_169
L_178 ,
V_60 , * V_64 , V_19 & 0x7f , F_59 ( V_60 ) ,
V_19 ) ;
V_85 ++ ;
} else {
F_55 ( V_44 , V_6 , V_85 , 1 ,
L_158
L_170
L_179 ,
V_60 , * V_64 , V_19 & 0x7f , F_59 ( V_60 ) ,
V_19 ) ;
V_85 ++ ;
}
}
}
F_39 ( ( L_172 ,
V_60 , V_85 - V_7 ) ) ;
return ( V_85 - V_7 ) ;
}
void
F_65 ( void )
{
T_18 * V_113 ;
static T_19 V_114 [] = {
{ & V_74 ,
{ L_180 ,
L_181 ,
V_115 , V_116 | V_117 ,
& V_71 , 0x00 ,
L_182 , V_118 }
} ,
{ & V_75 ,
{ L_183 ,
L_184 ,
V_119 , V_116 | V_117 ,
& V_72 , 0x00 ,
L_185 , V_118 }
} ,
{ & V_76 ,
{ L_186 ,
L_187 ,
V_120 , V_121 ,
NULL , 0x00 ,
L_188 , V_118 }
} ,
{ & V_78 ,
{ L_189 ,
L_190 ,
V_119 , V_116 | V_117 ,
& V_122 , 0x00 ,
L_191 , V_118 }
} ,
} ;
static T_4 * V_123 [] = {
& V_73 ,
& V_79 ,
& V_81 ,
} ;
V_69 = F_66 (
L_192 ,
L_193 ,
L_194
) ;
F_67 ( V_69 , V_114 , F_68 ( V_114 ) ) ;
F_69 ( V_123 , F_68 ( V_123 ) ) ;
V_113 = F_70 ( V_69 , NULL ) ;
F_71 ( V_113 ,
L_195 ,
L_196 ,
L_197
L_198
L_199
L_200 ,
& V_84 ) ;
F_71 ( V_113 ,
L_201 ,
L_202 ,
L_203
L_204
L_205
L_206 ,
& V_80 ) ;
F_72 ( L_194 , F_44 , V_69 ) ;
F_72 ( L_207 , F_46 , V_69 ) ;
}
void
F_73 ( void )
{
T_20 V_124 ;
V_124 = F_74 ( L_194 ) ;
F_75 ( L_208 ,
L_209 , V_124 ) ;
F_75 ( L_208 ,
L_210 , V_124 ) ;
F_75 ( L_208 ,
L_211 , V_124 ) ;
F_75 ( L_208 ,
L_212 , V_124 ) ;
F_75 ( L_208 ,
L_213 , V_124 ) ;
F_75 ( L_208 ,
L_214 , V_124 ) ;
F_75 ( L_208 ,
L_215 , V_124 ) ;
F_75 ( L_208 ,
L_216 , V_124 ) ;
F_75 ( L_208 ,
L_217 , V_124 ) ;
F_75 ( L_208 ,
L_218 , V_124 ) ;
F_75 ( L_208 ,
L_219 , V_124 ) ;
F_75 ( L_208 ,
L_220 , V_124 ) ;
F_75 ( L_208 ,
L_221 , V_124 ) ;
F_75 ( L_208 ,
L_222 , V_124 ) ;
F_75 ( L_208 ,
L_223 , V_124 ) ;
F_75 ( L_208 ,
L_224 , V_124 ) ;
F_75 ( L_208 ,
L_225 , V_124 ) ;
F_75 ( L_208 ,
L_226 , V_124 ) ;
F_75 ( L_208 ,
L_227 , V_124 ) ;
F_75 ( L_208 ,
L_228 , V_124 ) ;
F_75 ( L_208 ,
L_229 , V_124 ) ;
F_75 ( L_208 ,
L_230 , V_124 ) ;
F_75 ( L_208 ,
L_231 , V_124 ) ;
F_75 ( L_208 ,
L_232 , V_124 ) ;
F_75 ( L_208 ,
L_233 , V_124 ) ;
}
