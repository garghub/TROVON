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
V_6 -> V_7 = F_8 ( * ( V_16 * ) ( V_3 + 2 ) ) ;
return 4 ;
}
static int F_9 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
unsigned int V_8 = ( 52 - 5 ) >> 3 ;
if ( V_8 < 1 || V_8 > 7 )
return V_17 ;
if ( V_4 < V_8 + 2 )
return V_9 ;
V_6 -> type = V_18 ;
V_6 -> V_8 = V_8 ;
F_5 ( & V_6 -> V_7 , V_3 + 2 , V_8 ) ;
return V_8 + 2 ;
}
static int F_10 ( struct V_5 * V_6 )
{
V_6 -> type = V_19 ;
return 2 ;
}
static int F_11 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
int V_20 ;
if ( V_4 < 16 )
return V_9 ;
for ( V_20 = 2 ; V_20 < 16 ; V_20 += 2 ) {
if ( V_3 [ V_20 ] != 2 || V_3 [ V_20 + 1 ] != 0x82 )
return V_17 ;
}
V_6 -> type = V_21 ;
return 16 ;
}
static int F_12 ( struct V_5 * V_6 )
{
V_6 -> type = V_22 ;
return 2 ;
}
static int F_13 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
if ( V_4 < 7 )
return V_9 ;
V_6 -> type = V_23 ;
V_6 -> V_7 = V_3 [ 2 ] | ( V_3 [ 3 ] << 8 ) ;
V_6 -> V_8 = V_3 [ 5 ] | ( ( V_3 [ 6 ] & F_14 ( 0 ) ) << 8 ) ;
return 7 ;
}
static int F_15 ( struct V_5 * V_6 )
{
V_6 -> type = V_24 ;
return 1 ;
}
static int F_16 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
if ( V_4 < 11 )
return V_9 ;
V_6 -> type = V_25 ;
F_5 ( & V_6 -> V_7 , V_3 + 3 , 8 ) ;
return 11
;
}
static int F_17 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
if ( V_4 < 3 )
return V_9 ;
switch ( V_3 [ 2 ] ) {
case 0x88 :
return F_16 ( V_3 , V_4 , V_6 ) ;
default:
return V_17 ;
}
}
static int F_18 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
V_6 -> V_8 = ( V_3 [ 1 ] >> 5 ) & 0x3 ;
V_6 -> type = V_3 [ 1 ] & F_14 ( 7 ) ? V_26 :
V_27 ;
switch ( V_6 -> V_8 ) {
case 0 :
if ( V_4 < 6 )
return V_9 ;
V_6 -> V_7 = F_19 ( * ( V_28 * ) ( V_3 + 2 ) ) ;
return 6 ;
case 1 :
if ( V_4 < 10 )
return V_9 ;
V_6 -> V_7 = F_3 ( * ( T_2 * ) ( V_3 + 2 ) ) ;
return 10 ;
default:
return V_17 ;
}
}
static int F_20 ( struct V_5 * V_6 )
{
V_6 -> type = V_29 ;
return 2 ;
}
static int F_21 ( struct V_5 * V_6 )
{
V_6 -> type = V_30 ;
return 2 ;
}
static int F_22 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
if ( V_4 < 10 )
return V_9 ;
V_6 -> type = V_31 ;
V_6 -> V_7 = F_3 ( * ( T_2 * ) ( V_3 + 2 ) ) ;
return 10 ;
}
static int F_23 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
if ( V_4 < 4 )
return V_9 ;
V_6 -> type = V_32 ;
F_5 ( & V_6 -> V_7 , V_3 + 2 , 2 ) ;
return 4 ;
}
static int F_24 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
if ( V_4 < 7 )
return V_9 ;
V_6 -> type = V_33 ;
F_5 ( & V_6 -> V_7 , V_3 + 2 , 5 ) ;
return 7 ;
}
static int F_25 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
if ( V_4 < 2 )
return V_9 ;
if ( ( V_3 [ 1 ] & 0x1f ) == 0x12 )
return F_18 ( V_3 , V_4 , V_6 ) ;
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
return F_9 ( V_3 , V_4 , V_6 ) ;
case 0xf3 :
return F_10 ( V_6 ) ;
case 0x82 :
return F_11 ( V_3 , V_4 , V_6 ) ;
case 0x23 :
return F_12 ( V_6 ) ;
case 0x73 :
return F_13 ( V_3 , V_4 , V_6 ) ;
case 0xC3 :
return F_17 ( V_3 , V_4 , V_6 ) ;
case 0x62 :
return F_20 ( V_6 ) ;
case 0xE2 :
return F_21 ( V_6 ) ;
case 0xC2 :
return F_22 ( V_3 , V_4 , V_6 ) ;
case 0x22 :
return F_23 ( V_3 , V_4 , V_6 ) ;
case 0xA2 :
return F_24 ( V_3 , V_4 , V_6 ) ;
default:
return V_17 ;
}
}
static int F_26 ( unsigned int V_34 ,
struct V_5 * V_6 )
{
int V_8 ;
for ( V_8 = 6 ; V_8 ; V_8 -- ) {
if ( V_34 & F_14 ( 7 ) )
break;
V_34 <<= 1 ;
}
V_6 -> type = V_11 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_7 = ( T_2 ) V_34 << 57 ;
return 1 ;
}
static int F_27 ( unsigned int V_34 , const unsigned char * V_3 ,
T_1 V_4 , struct V_5 * V_6 )
{
unsigned int V_35 = 1 , V_36 ;
T_2 V_7 = V_34 >> 3 ;
V_34 >>= 2 ;
V_4 -= 1 ;
for ( V_36 = 5 ; V_34 & 1 ; V_36 += 7 ) {
if ( V_35 > 9 )
return V_17 ;
if ( V_4 < V_35 )
return V_9 ;
V_34 = V_3 [ V_35 ++ ] ;
V_7 |= ( V_34 >> 1 ) << V_36 ;
}
V_6 -> type = V_37 ;
V_6 -> V_7 = V_7 ;
return V_35 ;
}
static int F_28 ( enum V_1 type , unsigned int V_34 ,
const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
int V_38 ;
V_6 -> V_8 = V_34 >> 5 ;
switch ( V_6 -> V_8 ) {
case 0 :
V_38 = 0 ;
break;
case 1 :
if ( V_4 < 3 )
return V_9 ;
V_38 = 2 ;
V_6 -> V_7 = F_8 ( * ( V_16 * ) ( V_3 + 1 ) ) ;
break;
case 2 :
if ( V_4 < 5 )
return V_9 ;
V_38 = 4 ;
V_6 -> V_7 = F_19 ( * ( V_28 * ) ( V_3 + 1 ) ) ;
break;
case 3 :
case 4 :
if ( V_4 < 7 )
return V_9 ;
V_38 = 6 ;
F_5 ( & V_6 -> V_7 , V_3 + 1 , 6 ) ;
break;
case 6 :
if ( V_4 < 9 )
return V_9 ;
V_38 = 8 ;
V_6 -> V_7 = F_3 ( * ( T_2 * ) ( V_3 + 1 ) ) ;
break;
default:
return V_17 ;
}
V_6 -> type = type ;
return V_38 + 1 ;
}
static int F_29 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
if ( V_4 < 2 )
return V_9 ;
switch ( V_3 [ 1 ] >> 5 ) {
case 0 :
V_6 -> type = V_39 ;
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
return V_17 ;
}
break;
case 1 :
V_6 -> type = V_40 ;
if ( ( V_3 [ 1 ] & 3 ) == 3 )
return V_17 ;
V_6 -> V_7 = V_3 [ 1 ] & 3 ;
break;
default:
return V_17 ;
}
return 2 ;
}
static int F_30 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
if ( V_4 < 8 )
return V_9 ;
V_6 -> type = V_41 ;
F_5 ( & V_6 -> V_7 , V_3 + 1 , 7 ) ;
return 8 ;
}
static int F_31 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
if ( V_4 < 2 )
return V_9 ;
V_6 -> type = V_42 ;
V_6 -> V_7 = V_3 [ 1 ] ;
return 2 ;
}
static int F_32 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
unsigned int V_34 ;
memset ( V_6 , 0 , sizeof( struct V_5 ) ) ;
if ( ! V_4 )
return V_9 ;
V_34 = V_3 [ 0 ] ;
if ( ! ( V_34 & F_14 ( 0 ) ) ) {
if ( V_34 == 0 )
return F_15 ( V_6 ) ;
if ( V_34 == 2 )
return F_25 ( V_3 , V_4 , V_6 ) ;
return F_26 ( V_34 , V_6 ) ;
}
if ( ( V_34 & 2 ) )
return F_27 ( V_34 , V_3 , V_4 , V_6 ) ;
switch ( V_34 & 0x1f ) {
case 0x0D :
return F_28 ( V_43 , V_34 , V_3 , V_4 , V_6 ) ;
case 0x11 :
return F_28 ( V_44 , V_34 , V_3 , V_4 ,
V_6 ) ;
case 0x01 :
return F_28 ( V_45 , V_34 , V_3 , V_4 ,
V_6 ) ;
case 0x1D :
return F_28 ( V_46 , V_34 , V_3 , V_4 , V_6 ) ;
case 0x19 :
switch ( V_34 ) {
case 0x99 :
return F_29 ( V_3 , V_4 , V_6 ) ;
case 0x19 :
return F_30 ( V_3 , V_4 , V_6 ) ;
case 0x59 :
return F_31 ( V_3 , V_4 , V_6 ) ;
default:
return V_17 ;
}
default:
return V_17 ;
}
}
int F_33 ( const unsigned char * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
int V_47 ;
V_47 = F_32 ( V_3 , V_4 , V_6 ) ;
if ( V_47 > 0 ) {
while ( V_47 < 8 && V_4 > ( T_1 ) V_47 && ! V_3 [ V_47 ] )
V_47 += 1 ;
}
return V_47 ;
}
int F_34 ( const struct V_5 * V_6 , char * V_3 ,
T_1 V_48 )
{
int V_47 , V_20 , V_49 ;
unsigned long long V_7 = V_6 -> V_7 ;
const char * V_50 = F_1 ( V_6 -> type ) ;
switch ( V_6 -> type ) {
case V_51 :
case V_24 :
case V_21 :
case V_22 :
case V_14 :
case V_19 :
return snprintf ( V_3 , V_48 , L_1 , V_50 ) ;
case V_11 : {
T_1 V_52 = V_48 ;
V_47 = snprintf ( V_3 , V_52 , L_2 , V_50 ) ;
if ( V_47 < 0 )
return V_47 ;
V_3 += V_47 ;
V_52 -= V_47 ;
for ( V_20 = 0 ; V_20 < V_6 -> V_8 ; V_20 ++ ) {
if ( V_7 & V_10 )
V_47 = snprintf ( V_3 , V_52 , L_3 ) ;
else
V_47 = snprintf ( V_3 , V_52 , L_4 ) ;
if ( V_47 < 0 )
return V_47 ;
V_3 += V_47 ;
V_52 -= V_47 ;
V_7 <<= 1 ;
}
V_47 = snprintf ( V_3 , V_52 , L_5 , V_6 -> V_8 ) ;
if ( V_47 < 0 )
return V_47 ;
V_52 -= V_47 ;
return V_48 - V_52 ;
}
case V_45 :
case V_44 :
case V_43 :
case V_46 :
if ( ! ( V_6 -> V_8 ) )
return snprintf ( V_3 , V_48 , L_6 , V_50 ) ;
V_53 ;
case V_37 :
case V_18 :
case V_42 :
case V_25 :
case V_15 :
case V_41 :
return snprintf ( V_3 , V_48 , L_7 , V_50 , V_7 ) ;
case V_23 :
return snprintf ( V_3 , V_48 , L_8 , V_50 ,
( unsigned ) V_7 , V_6 -> V_8 ) ;
case V_39 :
return snprintf ( V_3 , V_48 , L_9 , V_50 , V_7 ) ;
case V_40 :
return snprintf ( V_3 , V_48 , L_10 ,
V_50 , ( unsigned ) ( V_7 >> 1 ) & 1 ,
( unsigned ) V_7 & 1 ) ;
case V_12 :
V_49 = V_6 -> V_7 & V_13 ? 1 : 0 ;
V_7 &= ~ V_13 ;
V_47 = snprintf ( V_3 , V_48 , L_11 ,
V_50 , V_7 , V_49 ) ;
return V_47 ;
case V_27 :
return snprintf ( V_3 , V_48 , L_12 , V_50 , V_7 ) ;
case V_26 :
return snprintf ( V_3 , V_48 , L_13 , V_50 , V_7 ) ;
case V_29 :
return snprintf ( V_3 , V_48 , L_14 , V_50 ) ;
case V_30 :
return snprintf ( V_3 , V_48 , L_15 , V_50 ) ;
case V_31 :
return snprintf ( V_3 , V_48 , L_16 ,
V_50 , V_7 , ( unsigned int ) ( V_7 & 0xff ) ,
( unsigned int ) ( ( V_7 >> 32 ) & 0x3 ) ) ;
case V_32 :
return snprintf ( V_3 , V_48 , L_17 ,
V_50 , V_7 , ! ! ( V_7 & 0x80 ) ,
( unsigned int ) ( ( V_7 >> 12 ) & 0xf ) ,
( unsigned int ) ( ( V_7 >> 8 ) & 0xf ) ) ;
case V_33 :
return snprintf ( V_3 , V_48 , L_18 ,
V_50 , V_7 ,
( unsigned int ) ( ( V_7 >> 4 ) & 0xf ) ,
( unsigned int ) ( V_7 & 0xf ) ,
( unsigned int ) ( ( V_7 >> 8 ) & 0xf ) ) ;
default:
break;
}
return snprintf ( V_3 , V_48 , L_19 ,
V_50 , V_7 , V_6 -> V_8 ) ;
}
