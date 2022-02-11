static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 , V_7 , & V_5 ) ;
if ( V_6 )
return V_6 ;
V_4 -> V_8 = V_5 & V_9 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = V_4 -> V_8 & V_9 ;
return F_4 ( V_2 , V_7 , V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 , V_10 , & V_5 ) ;
if ( V_6 )
return V_6 ;
V_4 -> V_11 = V_5 & V_12 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = V_4 -> V_11 & V_12 ;
return F_4 ( V_2 , V_10 , V_5 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_8 ( V_2 , V_13 ,
V_14 ) ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_15 )
{
int V_6 ;
V_6 = F_4 ( V_2 , V_13 ,
V_14 | V_15 ) ;
if ( V_6 )
return V_6 ;
return F_7 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 , V_16 , & V_5 ) ;
if ( V_6 )
return V_6 ;
V_4 -> V_17 = V_5 & 0xfff ;
if ( V_5 & V_18 )
V_4 -> V_17 |= 0x1000 ;
V_4 -> V_19 = ! ! ( V_5 & V_20 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = V_4 -> V_17 & 0xfff ;
if ( V_4 -> V_17 & 0x1000 )
V_5 |= V_18 ;
if ( V_4 -> V_19 )
V_5 |= V_20 ;
return F_4 ( V_2 , V_16 , V_5 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_21 [ 3 ] ;
int V_22 ;
for ( V_22 = 0 ; V_22 < 3 ; ++ V_22 ) {
T_1 * V_23 = & V_21 [ V_22 ] ;
int V_6 ;
V_6 = F_2 ( V_2 , V_24 + V_22 , V_23 ) ;
if ( V_6 )
return V_6 ;
}
for ( V_22 = 0 ; V_22 < F_13 ( V_2 ) ; ++ V_22 ) {
unsigned int V_25 = ( V_22 % 4 ) * 4 ;
unsigned int V_26 = V_25 + 2 ;
V_4 -> V_27 [ V_22 ] = ( V_21 [ V_22 / 4 ] >> V_25 ) & 0x3 ;
V_4 -> V_28 [ V_22 ] = ( V_21 [ V_22 / 4 ] >> V_26 ) & 0x3 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_21 [ 3 ] = { 0 } ;
int V_22 ;
for ( V_22 = 0 ; V_22 < F_13 ( V_2 ) ; ++ V_22 ) {
unsigned int V_25 = ( V_22 % 4 ) * 4 ;
unsigned int V_26 = V_25 + 2 ;
V_21 [ V_22 / 4 ] |= ( V_4 -> V_27 [ V_22 ] & 0x3 ) << V_25 ;
V_21 [ V_22 / 4 ] |= ( V_4 -> V_28 [ V_22 ] & 0x3 ) << V_26 ;
}
for ( V_22 = 0 ; V_22 < 3 ; ++ V_22 ) {
T_1 V_23 = V_21 [ V_22 ] ;
int V_6 ;
V_6 = F_4 ( V_2 , V_24 + V_22 , V_23 ) ;
if ( V_6 )
return V_6 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_2 * V_29 )
{
T_1 V_21 [ 2 ] ;
int V_22 ;
for ( V_22 = 0 ; V_22 < 2 ; ++ V_22 ) {
T_1 * V_23 = & V_21 [ V_22 ] ;
int V_6 ;
V_6 = F_2 ( V_2 , V_24 + V_22 , V_23 ) ;
if ( V_6 )
return V_6 ;
}
for ( V_22 = 0 ; V_22 < F_13 ( V_2 ) ; ++ V_22 ) {
unsigned int V_30 = ( V_22 % 8 ) * 2 ;
V_29 [ V_22 ] = ( V_21 [ V_22 / 8 ] >> V_30 ) & 0x3 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , T_2 * V_29 )
{
T_1 V_21 [ 2 ] = { 0 } ;
int V_22 ;
for ( V_22 = 0 ; V_22 < F_13 ( V_2 ) ; ++ V_22 ) {
unsigned int V_30 = ( V_22 % 8 ) * 2 ;
V_21 [ V_22 / 8 ] |= ( V_29 [ V_22 ] & 0x3 ) << V_30 ;
}
for ( V_22 = 0 ; V_22 < 2 ; ++ V_22 ) {
T_1 V_23 = V_21 [ V_22 ] ;
int V_6 ;
V_6 = F_4 ( V_2 , V_24 + V_22 , V_23 ) ;
if ( V_6 )
return V_6 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_6 ;
V_6 = F_6 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_9 ( V_2 , V_31 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_5 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
return F_10 ( V_2 , V_4 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_32 )
{
struct V_3 V_33 ;
int V_6 ;
V_6 = F_5 ( V_2 , V_32 ) ;
if ( V_6 )
return V_6 ;
V_33 . V_11 = V_32 -> V_11 - 1 ;
V_6 = F_17 ( V_2 , & V_33 ) ;
if ( V_6 )
return V_6 ;
if ( V_33 . V_11 != V_32 -> V_11 || ! V_33 . V_19 )
return - V_34 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_6 ;
V_6 = F_7 ( V_2 ) ;
if ( V_6 )
return V_6 ;
if ( ! V_4 -> V_19 ) {
V_6 = F_11 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_9 ( V_2 , V_35 ) ;
if ( V_6 )
return V_6 ;
return F_10 ( V_2 , V_4 ) ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 ;
int V_6 ;
V_6 = F_19 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
if ( V_4 -> V_19 ) {
V_6 = F_12 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_2 ( V_2 , V_13 , & V_5 ) ;
if ( V_6 )
return V_6 ;
V_4 -> V_8 = V_5 & 0x000f ;
V_4 -> V_8 |= ( V_5 & 0x0f00 ) >> 4 ;
}
return 0 ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_6 ;
V_6 = F_19 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
if ( V_4 -> V_19 ) {
V_6 = F_18 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_12 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_1 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
}
return 0 ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_6 ;
V_6 = F_19 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
if ( V_4 -> V_19 ) {
V_6 = F_15 ( V_2 , V_4 -> V_27 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_18 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_15 ( V_2 , V_4 -> V_28 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_1 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_15 = V_36 ;
int V_6 ;
V_6 = F_7 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_11 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
if ( V_4 -> V_19 ) {
V_6 = F_14 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
V_15 |= V_4 -> V_8 & 0x000f ;
V_15 |= ( V_4 -> V_8 & 0x00f0 ) << 8 ;
}
return F_9 ( V_2 , V_15 ) ;
}
int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_6 ;
V_6 = F_7 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_11 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
if ( V_4 -> V_19 ) {
V_6 = F_14 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_6 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_9 ( V_2 ,
V_37 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_3 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
}
return F_9 ( V_2 , V_36 ) ;
}
int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_6 ;
V_6 = F_7 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_11 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
if ( V_4 -> V_19 ) {
V_6 = F_16 ( V_2 , V_4 -> V_28 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_6 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_9 ( V_2 ,
V_37 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_16 ( V_2 , V_4 -> V_27 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_3 ( V_2 , V_4 ) ;
if ( V_6 )
return V_6 ;
}
return F_9 ( V_2 , V_36 ) ;
}
int F_26 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_7 ( V_2 ) ;
if ( V_6 )
return V_6 ;
return F_9 ( V_2 , V_38 ) ;
}
