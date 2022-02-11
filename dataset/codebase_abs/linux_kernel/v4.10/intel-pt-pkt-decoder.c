const char * F_1 ( enum V_1 type )
{
return V_2 [ type ] ;
}
static int F_2 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
T_2 V_7 ;
int V_8 ;
if ( V_4 < 8 )
return V_9 ;
V_7 = F_3 ( * ( T_2 * ) V_3 ) ;
for ( V_8 = 47 ; V_8 ; V_8 -- ) {
if ( V_7 & V_10 )
break;
V_7 <<= 1 ;
}
V_6 -> type = V_11 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_7 = V_7 << 1 ;
return 8 ;
}
static int F_4 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
T_2 V_7 = 0 ;
if ( V_4 < 8 )
return V_9 ;
V_6 -> type = V_12 ;
F_5 ( & V_7 , V_3 + 2 , 6 ) ;
V_6 -> V_7 = V_7 >> 1 ;
if ( V_7 & 1 )
V_6 -> V_7 |= V_13 ;
return 8 ;
}
static int F_6 ( struct V_5 * V_6 )
{
V_6 -> type = V_14 ;
return 2 ;
}
static int F_7 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
if ( V_4 < 4 )
return V_9 ;
V_6 -> type = V_15 ;
V_6 -> V_7 = V_3 [ 2 ] ;
return 4 ;
}
static int F_8 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
unsigned int V_8 = ( 52 - 5 ) >> 3 ;
if ( V_8 < 1 || V_8 > 7 )
return V_16 ;
if ( V_4 < V_8 + 2 )
return V_9 ;
V_6 -> type = V_17 ;
V_6 -> V_8 = V_8 ;
F_5 ( & V_6 -> V_7 , V_3 + 2 , V_8 ) ;
return V_8 + 2 ;
}
static int F_9 ( struct V_5 * V_6 )
{
V_6 -> type = V_18 ;
return 2 ;
}
static int F_10 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
int V_19 ;
if ( V_4 < 16 )
return V_9 ;
for ( V_19 = 2 ; V_19 < 16 ; V_19 += 2 ) {
if ( V_3 [ V_19 ] != 2 || V_3 [ V_19 + 1 ] != 0x82 )
return V_16 ;
}
V_6 -> type = V_20 ;
return 16 ;
}
static int F_11 ( struct V_5 * V_6 )
{
V_6 -> type = V_21 ;
return 2 ;
}
static int F_12 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
if ( V_4 < 7 )
return V_9 ;
V_6 -> type = V_22 ;
V_6 -> V_7 = V_3 [ 2 ] | ( V_3 [ 3 ] << 8 ) ;
V_6 -> V_8 = V_3 [ 5 ] | ( ( V_3 [ 6 ] & F_13 ( 0 ) ) << 8 ) ;
return 7 ;
}
static int F_14 ( struct V_5 * V_6 )
{
V_6 -> type = V_23 ;
return 1 ;
}
static int F_15 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
if ( V_4 < 11 )
return V_9 ;
V_6 -> type = V_24 ;
F_5 ( & V_6 -> V_7 , V_3 + 3 , 8 ) ;
return 11
;
}
static int F_16 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
if ( V_4 < 3 )
return V_9 ;
switch ( V_3 [ 2 ] ) {
case 0x88 :
return F_15 ( V_3 , V_4 , V_6 ) ;
default:
return V_16 ;
}
}
static int F_17 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
if ( V_4 < 2 )
return V_9 ;
switch ( V_3 [ 1 ] ) {
case 0xa3 :
return F_2 ( V_3 , V_4 , V_6 ) ;
case 0x43 :
return F_4 ( V_3 , V_4 , V_6 ) ;
case 0x83 :
return F_6 ( V_6 ) ;
case 0x03 :
return F_7 ( V_3 , V_4 , V_6 ) ;
case 0xc8 :
return F_8 ( V_3 , V_4 , V_6 ) ;
case 0xf3 :
return F_9 ( V_6 ) ;
case 0x82 :
return F_10 ( V_3 , V_4 , V_6 ) ;
case 0x23 :
return F_11 ( V_6 ) ;
case 0x73 :
return F_12 ( V_3 , V_4 , V_6 ) ;
case 0xC3 :
return F_16 ( V_3 , V_4 , V_6 ) ;
default:
return V_16 ;
}
}
static int F_18 ( unsigned int V_25 ,
struct V_5 * V_6 )
{
int V_8 ;
for ( V_8 = 6 ; V_8 ; V_8 -- ) {
if ( V_25 & F_13 ( 7 ) )
break;
V_25 <<= 1 ;
}
V_6 -> type = V_11 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_7 = ( T_2 ) V_25 << 57 ;
return 1 ;
}
static int F_19 ( unsigned int V_25 , const unsigned char * V_3 ,
T_1 V_4 , struct V_5 * V_6 )
{
unsigned int V_26 = 1 , V_27 ;
T_2 V_7 = V_25 >> 3 ;
V_25 >>= 2 ;
V_4 -= 1 ;
for ( V_27 = 5 ; V_25 & 1 ; V_27 += 7 ) {
if ( V_26 > 9 )
return V_16 ;
if ( V_4 < V_26 )
return V_9 ;
V_25 = V_3 [ V_26 ++ ] ;
V_7 |= ( V_25 >> 1 ) << V_27 ;
}
V_6 -> type = V_28 ;
V_6 -> V_7 = V_7 ;
return V_26 ;
}
static int F_20 ( enum V_1 type , unsigned int V_25 ,
const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
int V_29 ;
V_6 -> V_8 = V_25 >> 5 ;
switch ( V_6 -> V_8 ) {
case 0 :
V_29 = 0 ;
break;
case 1 :
if ( V_4 < 3 )
return V_9 ;
V_29 = 2 ;
V_6 -> V_7 = F_21 ( * ( V_30 * ) ( V_3 + 1 ) ) ;
break;
case 2 :
if ( V_4 < 5 )
return V_9 ;
V_29 = 4 ;
V_6 -> V_7 = F_22 ( * ( V_31 * ) ( V_3 + 1 ) ) ;
break;
case 3 :
case 4 :
if ( V_4 < 7 )
return V_9 ;
V_29 = 6 ;
F_5 ( & V_6 -> V_7 , V_3 + 1 , 6 ) ;
break;
case 6 :
if ( V_4 < 9 )
return V_9 ;
V_29 = 8 ;
V_6 -> V_7 = F_3 ( * ( T_2 * ) ( V_3 + 1 ) ) ;
break;
default:
return V_16 ;
}
V_6 -> type = type ;
return V_29 + 1 ;
}
static int F_23 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
if ( V_4 < 2 )
return V_9 ;
switch ( V_3 [ 1 ] >> 5 ) {
case 0 :
V_6 -> type = V_32 ;
switch ( V_3 [ 1 ] & 3 ) {
case 0 :
V_6 -> V_7 = 16 ;
break;
case 1 :
V_6 -> V_7 = 64 ;
break;
case 2 :
V_6 -> V_7 = 32 ;
break;
default:
return V_16 ;
}
break;
case 1 :
V_6 -> type = V_33 ;
if ( ( V_3 [ 1 ] & 3 ) == 3 )
return V_16 ;
V_6 -> V_7 = V_3 [ 1 ] & 3 ;
break;
default:
return V_16 ;
}
return 2 ;
}
static int F_24 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
if ( V_4 < 8 )
return V_9 ;
V_6 -> type = V_34 ;
F_5 ( & V_6 -> V_7 , V_3 + 1 , 7 ) ;
return 8 ;
}
static int F_25 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
if ( V_4 < 2 )
return V_9 ;
V_6 -> type = V_35 ;
V_6 -> V_7 = V_3 [ 1 ] ;
return 2 ;
}
static int F_26 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
unsigned int V_25 ;
memset ( V_6 , 0 , sizeof( struct V_5 ) ) ;
if ( ! V_4 )
return V_9 ;
V_25 = V_3 [ 0 ] ;
if ( ! ( V_25 & F_13 ( 0 ) ) ) {
if ( V_25 == 0 )
return F_14 ( V_6 ) ;
if ( V_25 == 2 )
return F_17 ( V_3 , V_4 , V_6 ) ;
return F_18 ( V_25 , V_6 ) ;
}
if ( ( V_25 & 2 ) )
return F_19 ( V_25 , V_3 , V_4 , V_6 ) ;
switch ( V_25 & 0x1f ) {
case 0x0D :
return F_20 ( V_36 , V_25 , V_3 , V_4 , V_6 ) ;
case 0x11 :
return F_20 ( V_37 , V_25 , V_3 , V_4 ,
V_6 ) ;
case 0x01 :
return F_20 ( V_38 , V_25 , V_3 , V_4 ,
V_6 ) ;
case 0x1D :
return F_20 ( V_39 , V_25 , V_3 , V_4 , V_6 ) ;
case 0x19 :
switch ( V_25 ) {
case 0x99 :
return F_23 ( V_3 , V_4 , V_6 ) ;
case 0x19 :
return F_24 ( V_3 , V_4 , V_6 ) ;
case 0x59 :
return F_25 ( V_3 , V_4 , V_6 ) ;
default:
return V_16 ;
}
default:
return V_16 ;
}
}
int F_27 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
int V_40 ;
V_40 = F_26 ( V_3 , V_4 , V_6 ) ;
if ( V_40 > 0 ) {
while ( V_40 < 8 && V_4 > ( T_1 ) V_40 && ! V_3 [ V_40 ] )
V_40 += 1 ;
}
return V_40 ;
}
int F_28 ( const struct V_5 * V_6 , char * V_3 ,
T_1 V_41 )
{
int V_40 , V_19 , V_42 ;
unsigned long long V_7 = V_6 -> V_7 ;
const char * V_43 = F_1 ( V_6 -> type ) ;
switch ( V_6 -> type ) {
case V_44 :
case V_23 :
case V_20 :
case V_21 :
case V_14 :
case V_18 :
return snprintf ( V_3 , V_41 , L_1 , V_43 ) ;
case V_11 : {
T_1 V_45 = V_41 ;
V_40 = snprintf ( V_3 , V_45 , L_2 , V_43 ) ;
if ( V_40 < 0 )
return V_40 ;
V_3 += V_40 ;
V_45 -= V_40 ;
for ( V_19 = 0 ; V_19 < V_6 -> V_8 ; V_19 ++ ) {
if ( V_7 & V_10 )
V_40 = snprintf ( V_3 , V_45 , L_3 ) ;
else
V_40 = snprintf ( V_3 , V_45 , L_4 ) ;
if ( V_40 < 0 )
return V_40 ;
V_3 += V_40 ;
V_45 -= V_40 ;
V_7 <<= 1 ;
}
V_40 = snprintf ( V_3 , V_45 , L_5 , V_6 -> V_8 ) ;
if ( V_40 < 0 )
return V_40 ;
V_45 -= V_40 ;
return V_41 - V_45 ;
}
case V_38 :
case V_37 :
case V_36 :
case V_39 :
if ( ! ( V_6 -> V_8 ) )
return snprintf ( V_3 , V_41 , L_6 , V_43 ) ;
case V_28 :
case V_17 :
case V_35 :
case V_24 :
case V_15 :
case V_34 :
return snprintf ( V_3 , V_41 , L_7 , V_43 , V_7 ) ;
case V_22 :
return snprintf ( V_3 , V_41 , L_8 , V_43 ,
( unsigned ) V_7 , V_6 -> V_8 ) ;
case V_32 :
return snprintf ( V_3 , V_41 , L_9 , V_43 , V_7 ) ;
case V_33 :
return snprintf ( V_3 , V_41 , L_10 ,
V_43 , ( unsigned ) ( V_7 >> 1 ) & 1 ,
( unsigned ) V_7 & 1 ) ;
case V_12 :
V_42 = V_6 -> V_7 & V_13 ? 1 : 0 ;
V_7 &= ~ V_13 ;
V_40 = snprintf ( V_3 , V_41 , L_11 ,
V_43 , V_7 , V_42 ) ;
return V_40 ;
default:
break;
}
return snprintf ( V_3 , V_41 , L_12 ,
V_43 , V_7 , V_6 -> V_8 ) ;
}
