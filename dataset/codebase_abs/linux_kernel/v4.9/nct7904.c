static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_4 ;
F_2 ( & V_2 -> V_5 ) ;
if ( V_2 -> V_6 == V_3 )
return 0 ;
V_4 = F_3 ( V_2 -> V_7 , V_8 , V_3 ) ;
if ( V_4 == 0 )
V_2 -> V_6 = V_3 ;
else
V_2 -> V_6 = - 1 ;
return V_4 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned V_9 )
{
struct V_10 * V_7 = V_2 -> V_7 ;
int V_4 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 == 0 )
V_4 = F_7 ( V_7 , V_9 ) ;
F_4 ( V_2 ) ;
return V_4 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned V_9 )
{
struct V_10 * V_7 = V_2 -> V_7 ;
int V_4 , V_11 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 == 0 ) {
V_4 = F_7 ( V_7 , V_9 ) ;
if ( V_4 >= 0 ) {
V_11 = V_4 ;
V_4 = F_7 ( V_7 , V_9 + 1 ) ;
if ( V_4 >= 0 )
V_4 |= V_11 << 8 ;
}
}
F_4 ( V_2 ) ;
return V_4 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned V_9 , T_1 V_12 )
{
struct V_10 * V_7 = V_2 -> V_7 ;
int V_4 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 == 0 )
V_4 = F_3 ( V_7 , V_9 , V_12 ) ;
F_4 ( V_2 ) ;
return V_4 ;
}
static int F_10 ( struct V_13 * V_14 , T_2 V_15 , int V_16 ,
long * V_12 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
unsigned int V_17 , V_18 ;
int V_4 ;
switch( V_15 ) {
case V_19 :
V_4 = F_8 ( V_2 , V_20 ,
V_21 + V_16 * 2 ) ;
if ( V_4 < 0 )
return V_4 ;
V_17 = ( ( V_4 & 0xff00 ) >> 3 ) | ( V_4 & 0x1f ) ;
if ( V_17 == 0x1fff )
V_18 = 0 ;
else
V_18 = 1350000 / V_17 ;
* V_12 = V_18 ;
return 0 ;
default:
return - V_22 ;
}
}
static T_3 F_12 ( const void * V_23 , T_2 V_15 , int V_16 )
{
const struct V_1 * V_2 = V_23 ;
if ( V_15 == V_19 && V_2 -> V_24 & ( 1 << V_16 ) )
return V_25 ;
return 0 ;
}
static int F_13 ( struct V_13 * V_14 , T_2 V_15 , int V_16 ,
long * V_12 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
int V_4 , V_26 , V_27 ;
V_27 = V_28 [ V_16 ] ;
switch( V_15 ) {
case V_29 :
V_4 = F_8 ( V_2 , V_20 ,
V_30 + V_27 * 2 ) ;
if ( V_4 < 0 )
return V_4 ;
V_26 = ( ( V_4 & 0xff00 ) >> 5 ) | ( V_4 & 0x7 ) ;
if ( V_27 < 14 )
V_26 *= 2 ;
else
V_26 *= 6 ;
* V_12 = V_26 ;
return 0 ;
default:
return - V_22 ;
}
}
static T_3 F_14 ( const void * V_23 , T_2 V_15 , int V_16 )
{
const struct V_1 * V_2 = V_23 ;
int V_27 = V_28 [ V_16 ] ;
if ( V_16 > 0 && V_15 == V_29 &&
( V_2 -> V_31 & F_15 ( V_27 ) ) )
return V_25 ;
return 0 ;
}
static int F_16 ( struct V_13 * V_14 , T_2 V_15 , int V_16 ,
long * V_12 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
int V_4 , V_32 ;
switch( V_15 ) {
case V_33 :
if ( V_16 == 0 )
V_4 = F_8 ( V_2 , V_20 , V_34 ) ;
else
V_4 = F_8 ( V_2 , V_20 ,
V_35 + ( V_16 - 1 ) * 2 ) ;
if ( V_4 < 0 )
return V_4 ;
V_32 = ( ( V_4 & 0xff00 ) >> 5 ) | ( V_4 & 0x7 ) ;
* V_12 = F_17 ( V_32 , 10 ) * 125 ;
return 0 ;
default:
return - V_22 ;
}
}
static T_3 F_18 ( const void * V_23 , T_2 V_15 , int V_16 )
{
const struct V_1 * V_2 = V_23 ;
if ( V_15 == V_33 ) {
if ( V_16 == 0 ) {
if ( V_2 -> V_31 & F_15 ( 17 ) )
return V_25 ;
} else {
if ( V_2 -> V_36 & F_15 ( V_16 - 1 ) )
return V_25 ;
}
}
return 0 ;
}
static int F_19 ( struct V_13 * V_14 , T_2 V_15 , int V_16 ,
long * V_12 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
int V_4 ;
switch( V_15 ) {
case V_37 :
V_4 = F_6 ( V_2 , V_38 , V_39 + V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_12 = V_4 ;
return 0 ;
case V_40 :
V_4 = F_6 ( V_2 , V_38 , V_41 + V_16 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_12 = V_4 ? 2 : 1 ;
return 0 ;
default:
return - V_22 ;
}
}
static int F_20 ( struct V_13 * V_14 , T_2 V_15 , int V_16 ,
long V_12 )
{
struct V_1 * V_2 = F_11 ( V_14 ) ;
int V_4 ;
switch( V_15 ) {
case V_37 :
if ( V_12 < 0 || V_12 > 255 )
return - V_42 ;
V_4 = F_9 ( V_2 , V_38 , V_39 + V_16 ,
V_12 ) ;
return V_4 ;
case V_40 :
if ( V_12 < 1 || V_12 > 2 ||
( V_12 == 2 && ! V_2 -> V_43 [ V_16 ] ) )
return - V_42 ;
V_4 = F_9 ( V_2 , V_38 , V_41 + V_16 ,
V_12 == 2 ? V_2 -> V_43 [ V_16 ] : 0 ) ;
return V_4 ;
default:
return - V_22 ;
}
}
static T_3 F_21 ( const void * V_23 , T_2 V_15 , int V_16 )
{
switch( V_15 ) {
case V_37 :
case V_40 :
return V_25 | V_44 ;
default:
return 0 ;
}
}
static int F_22 ( struct V_13 * V_14 , enum V_45 type ,
T_2 V_15 , int V_16 , long * V_12 )
{
switch ( type ) {
case V_46 :
return F_13 ( V_14 , V_15 , V_16 , V_12 ) ;
case V_47 :
return F_10 ( V_14 , V_15 , V_16 , V_12 ) ;
case V_48 :
return F_19 ( V_14 , V_15 , V_16 , V_12 ) ;
case V_49 :
return F_16 ( V_14 , V_15 , V_16 , V_12 ) ;
default:
return - V_22 ;
}
}
static int F_23 ( struct V_13 * V_14 , enum V_45 type ,
T_2 V_15 , int V_16 , long V_12 )
{
switch ( type ) {
case V_48 :
return F_20 ( V_14 , V_15 , V_16 , V_12 ) ;
default:
return - V_22 ;
}
}
static T_3 F_24 ( const void * V_2 ,
enum V_45 type ,
T_2 V_15 , int V_16 )
{
switch ( type ) {
case V_46 :
return F_14 ( V_2 , V_15 , V_16 ) ;
case V_47 :
return F_12 ( V_2 , V_15 , V_16 ) ;
case V_48 :
return F_21 ( V_2 , V_15 , V_16 ) ;
case V_49 :
return F_18 ( V_2 , V_15 , V_16 ) ;
default:
return 0 ;
}
}
static int F_25 ( struct V_10 * V_7 ,
struct V_50 * V_51 )
{
struct V_52 * V_53 = V_7 -> V_53 ;
if ( ! F_26 ( V_53 ,
V_54 |
V_55 ) )
return - V_56 ;
if ( F_7 ( V_7 , V_57 ) != V_58 ||
F_7 ( V_7 , V_59 ) != V_60 ||
( F_7 ( V_7 , V_61 ) & 0xf0 ) != 0x50 ||
( F_7 ( V_7 , V_8 ) & 0xf8 ) != 0x00 )
return - V_56 ;
F_27 ( V_51 -> type , L_1 , V_62 ) ;
return 0 ;
}
static int F_28 ( struct V_10 * V_7 ,
const struct V_63 * V_64 )
{
struct V_1 * V_2 ;
struct V_13 * V_65 ;
struct V_13 * V_14 = & V_7 -> V_14 ;
int V_4 , V_66 ;
T_2 V_67 ;
V_2 = F_29 ( V_14 , sizeof( struct V_1 ) , V_68 ) ;
if ( ! V_2 )
return - V_69 ;
V_2 -> V_7 = V_7 ;
F_30 ( & V_2 -> V_5 ) ;
V_2 -> V_6 = - 1 ;
V_4 = F_8 ( V_2 , V_20 , V_70 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_24 = ( V_4 >> 8 ) | ( ( V_4 & 0xff ) << 8 ) ;
V_67 = 0 ;
V_4 = F_8 ( V_2 , V_20 , V_71 ) ;
if ( V_4 >= 0 )
V_67 = ( V_4 >> 8 ) | ( ( V_4 & 0xff ) << 8 ) ;
V_4 = F_6 ( V_2 , V_20 , V_72 ) ;
if ( V_4 >= 0 )
V_67 |= ( V_4 << 16 ) ;
V_2 -> V_31 = V_67 ;
V_4 = F_8 ( V_2 , V_20 , V_73 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_36 = ( ( V_4 >> 8 ) & 0xf ) | ( ( V_4 & 0xf ) << 4 ) ;
for ( V_66 = 0 ; V_66 < V_74 ; V_66 ++ ) {
V_4 = F_6 ( V_2 , V_38 , V_41 + V_66 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_43 [ V_66 ] = V_4 ;
}
V_65 =
F_31 ( V_14 , V_7 -> V_75 , V_2 ,
& V_76 , NULL ) ;
return F_32 ( V_65 ) ;
}
