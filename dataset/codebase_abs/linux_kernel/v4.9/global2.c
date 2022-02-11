static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
return F_2 ( V_2 , V_5 , V_3 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
return F_4 ( V_2 , V_5 , V_3 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , T_1 V_6 )
{
return F_6 ( V_2 , V_5 , V_3 , V_6 ) ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 , T_1 V_7 )
{
return F_8 ( V_2 , V_5 , V_3 , V_7 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
int V_8 , int V_9 )
{
T_1 V_4 = ( V_8 << 8 ) | ( V_9 & 0xf ) ;
return F_5 ( V_2 , V_10 , V_4 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_8 , V_9 ;
int V_11 ;
for ( V_8 = 0 ; V_8 < 32 ; ++ V_8 ) {
V_9 = 0xf ;
if ( V_8 < V_12 ) {
V_9 = V_2 -> V_13 -> V_14 [ V_8 ] ;
if ( V_9 == V_15 )
V_9 = 0xf ;
}
V_11 = F_9 ( V_2 , V_8 , V_9 ) ;
if ( V_11 )
break;
}
return V_11 ;
}
static int F_11 ( struct V_1 * V_2 , int V_16 ,
bool V_17 , T_1 V_7 )
{
const T_1 V_18 = F_12 ( F_13 ( V_2 ) ) - 1 ;
T_1 V_4 = ( V_16 << 12 ) | ( V_7 & V_18 ) ;
if ( V_17 )
V_4 |= V_19 ;
return F_5 ( V_2 , V_20 , V_4 ) ;
}
static int F_14 ( struct V_1 * V_2 , int V_21 ,
T_1 V_22 )
{
const T_1 V_18 = F_12 ( F_13 ( V_2 ) ) - 1 ;
T_1 V_4 = ( V_21 << 11 ) | ( V_22 & V_18 ) ;
return F_5 ( V_2 , V_23 , V_4 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
const T_1 V_18 = F_12 ( F_13 ( V_2 ) ) - 1 ;
int V_24 , V_11 ;
for ( V_24 = 0 ; V_24 < 8 ; ++ V_24 ) {
V_11 = F_11 ( V_2 , V_24 , false , V_18 ) ;
if ( V_11 )
return V_11 ;
}
for ( V_24 = 0 ; V_24 < 16 ; ++ V_24 ) {
V_11 = F_14 ( V_2 , V_24 , 0 ) ;
if ( V_11 )
return V_11 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_9 , V_11 ;
for ( V_9 = 0 ; V_9 < F_13 ( V_2 ) ; ++ V_9 ) {
V_11 = F_3 ( V_2 , V_25 ,
V_26 |
( V_9 << 8 ) ) ;
if ( V_11 )
break;
V_11 = F_7 ( V_2 , V_25 ,
V_27 ) ;
if ( V_11 )
break;
}
return V_11 ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned int V_28 , T_2 V_29 )
{
T_1 V_4 = ( V_28 << 8 ) | V_29 ;
return F_5 ( V_2 , V_30 , V_4 ) ;
}
int F_18 ( struct V_1 * V_2 , T_2 * V_31 )
{
int V_24 , V_11 ;
for ( V_24 = 0 ; V_24 < 6 ; V_24 ++ ) {
V_11 = F_17 ( V_2 , V_24 , V_31 [ V_24 ] ) ;
if ( V_11 )
break;
}
return V_11 ;
}
static int F_19 ( struct V_1 * V_2 , int V_28 ,
T_2 V_29 )
{
T_1 V_4 = ( V_28 << 8 ) | ( V_29 & 0x7 ) ;
return F_5 ( V_2 , V_32 , V_4 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_24 , V_11 ;
for ( V_24 = 0 ; V_24 < 16 ; V_24 ++ ) {
V_11 = F_19 ( V_2 , V_24 , 0 ) ;
if ( V_11 )
break;
}
return V_11 ;
}
static int F_21 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , V_33 ,
V_34 |
V_35 ) ;
}
static int F_22 ( struct V_1 * V_2 , T_1 V_36 )
{
int V_11 ;
V_11 = F_3 ( V_2 , V_33 , V_36 ) ;
if ( V_11 )
return V_11 ;
return F_21 ( V_2 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
T_2 V_31 , T_1 * V_29 )
{
T_1 V_36 = V_37 | V_31 ;
int V_11 ;
V_11 = F_21 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_22 ( V_2 , V_36 ) ;
if ( V_11 )
return V_11 ;
return F_1 ( V_2 , V_38 , V_29 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
T_2 V_31 , T_1 V_29 )
{
T_1 V_36 = V_39 | V_31 ;
int V_11 ;
V_11 = F_21 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_3 ( V_2 , V_38 , V_29 ) ;
if ( V_11 )
return V_11 ;
return F_22 ( V_2 , V_36 ) ;
}
int F_25 ( struct V_1 * V_2 ,
struct V_40 * V_41 , T_2 * V_29 )
{
unsigned int V_42 = V_41 -> V_42 ;
unsigned int V_43 = V_41 -> V_43 ;
T_1 V_4 ;
int V_11 ;
V_41 -> V_43 = 0 ;
if ( V_42 & 1 ) {
V_11 = F_23 ( V_2 , V_42 >> 1 , & V_4 ) ;
if ( V_11 )
return V_11 ;
* V_29 ++ = ( V_4 >> 8 ) & 0xff ;
V_42 ++ ;
V_43 -- ;
V_41 -> V_43 ++ ;
}
while ( V_43 >= 2 ) {
V_11 = F_23 ( V_2 , V_42 >> 1 , & V_4 ) ;
if ( V_11 )
return V_11 ;
* V_29 ++ = V_4 & 0xff ;
* V_29 ++ = ( V_4 >> 8 ) & 0xff ;
V_42 += 2 ;
V_43 -= 2 ;
V_41 -> V_43 += 2 ;
}
if ( V_43 ) {
V_11 = F_23 ( V_2 , V_42 >> 1 , & V_4 ) ;
if ( V_11 )
return V_11 ;
* V_29 ++ = V_4 & 0xff ;
V_42 ++ ;
V_43 -- ;
V_41 -> V_43 ++ ;
}
return 0 ;
}
int F_26 ( struct V_1 * V_2 ,
struct V_40 * V_41 , T_2 * V_29 )
{
unsigned int V_42 = V_41 -> V_42 ;
unsigned int V_43 = V_41 -> V_43 ;
T_1 V_4 ;
int V_11 ;
V_11 = F_1 ( V_2 , V_33 , & V_4 ) ;
if ( V_11 )
return V_11 ;
if ( ! ( V_4 & V_44 ) )
return - V_45 ;
V_41 -> V_43 = 0 ;
if ( V_42 & 1 ) {
V_11 = F_23 ( V_2 , V_42 >> 1 , & V_4 ) ;
if ( V_11 )
return V_11 ;
V_4 = ( * V_29 ++ << 8 ) | ( V_4 & 0xff ) ;
V_11 = F_24 ( V_2 , V_42 >> 1 , V_4 ) ;
if ( V_11 )
return V_11 ;
V_42 ++ ;
V_43 -- ;
V_41 -> V_43 ++ ;
}
while ( V_43 >= 2 ) {
V_4 = * V_29 ++ ;
V_4 |= * V_29 ++ << 8 ;
V_11 = F_24 ( V_2 , V_42 >> 1 , V_4 ) ;
if ( V_11 )
return V_11 ;
V_42 += 2 ;
V_43 -= 2 ;
V_41 -> V_43 += 2 ;
}
if ( V_43 ) {
V_11 = F_23 ( V_2 , V_42 >> 1 , & V_4 ) ;
if ( V_11 )
return V_11 ;
V_4 = ( V_4 & 0xff00 ) | * V_29 ++ ;
V_11 = F_24 ( V_2 , V_42 >> 1 , V_4 ) ;
if ( V_11 )
return V_11 ;
V_42 ++ ;
V_43 -- ;
V_41 -> V_43 ++ ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , V_46 ,
V_47 ) ;
}
static int F_28 ( struct V_1 * V_2 , T_1 V_36 )
{
int V_11 ;
V_11 = F_3 ( V_2 , V_46 , V_36 ) ;
if ( V_11 )
return V_11 ;
return F_27 ( V_2 ) ;
}
int F_29 ( struct V_1 * V_2 , int V_31 , int V_3 ,
T_1 * V_4 )
{
T_1 V_36 = V_48 | ( V_31 << 5 ) | V_3 ;
int V_11 ;
V_11 = F_27 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_28 ( V_2 , V_36 ) ;
if ( V_11 )
return V_11 ;
return F_1 ( V_2 , V_49 , V_4 ) ;
}
int F_30 ( struct V_1 * V_2 , int V_31 , int V_3 ,
T_1 V_4 )
{
T_1 V_36 = V_50 | ( V_31 << 5 ) | V_3 ;
int V_11 ;
V_11 = F_27 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_3 ( V_2 , V_49 , V_4 ) ;
if ( V_11 )
return V_11 ;
return F_28 ( V_2 , V_36 ) ;
}
int F_31 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_11 ;
if ( F_32 ( V_2 , V_51 ) ) {
V_11 = F_3 ( V_2 , V_52 , 0xffff ) ;
if ( V_11 )
return V_11 ;
}
if ( F_32 ( V_2 , V_53 ) ) {
V_11 = F_3 ( V_2 , V_54 , 0xffff ) ;
if ( V_11 )
return V_11 ;
}
V_3 = V_55 | ( 0x7 << 4 ) ;
if ( F_32 ( V_2 , V_53 ) ||
F_32 ( V_2 , V_51 ) )
V_3 |= V_56 | 0x7 ;
V_11 = F_3 ( V_2 , V_57 , V_3 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_10 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_15 ( V_2 ) ;
if ( V_11 )
return V_11 ;
if ( F_32 ( V_2 , V_58 ) ) {
V_11 = F_16 ( V_2 ) ;
if ( V_11 )
return V_11 ;
}
if ( F_32 ( V_2 , V_59 ) ) {
V_11 = F_3 ( V_2 , V_60 ,
V_61 ) ;
if ( V_11 )
return V_11 ;
}
if ( F_32 ( V_2 , V_62 ) ) {
V_11 = F_20 ( V_2 ) ;
if ( V_11 )
return V_11 ;
}
return 0 ;
}
