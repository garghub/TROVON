static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 [ V_4 ] = { 0x55 , 0x55 , 0x55 , 0x55 , 0x55 } ;
T_1 V_5 [ V_4 ] = { 0 , 0 , 0 , 0 , 0 } ;
int V_6 , error ;
V_6 = F_2 ( V_2 ,
V_7 , V_5 ) ;
if ( V_6 != V_4 ) {
F_3 ( & V_2 -> V_8 , L_1 , V_6 ) ;
error = V_6 < 0 ? V_6 : - V_9 ;
return error ;
}
if ( memcmp ( V_5 , V_3 , V_4 ) ) {
F_3 ( & V_2 -> V_8 , L_2 ,
V_4 , V_5 ) ;
return - V_10 ;
}
error = F_4 ( V_2 , V_11 ) ;
if ( error ) {
F_3 ( & V_2 -> V_8 , L_3 , error ) ;
return error ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_12 )
{
T_1 V_13 [ 4 ] = { 0x00 , 0x07 , 0x00 , V_12 } ;
return F_6 ( V_2 , V_14 ,
sizeof( V_13 ) , V_13 ) ;
}
static int F_7 ( struct V_1 * V_2 , bool V_15 )
{
if ( V_15 )
return F_4 ( V_2 , V_16 ) ;
else
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , bool V_17 )
{
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_13 [ 4 ] = { 0x00 , 0x08 , 0x00 , 0x01 } ;
return F_6 ( V_2 , V_14 ,
sizeof( V_13 ) , V_13 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 * V_18 )
{
int error ;
error = F_2 ( V_2 ,
V_19 , V_18 ) ;
if ( error < 0 )
return error ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
bool V_20 , T_1 * V_21 )
{
int error ;
T_1 V_18 [ 3 ] ;
error = F_2 ( V_2 ,
V_20 ?
V_22 :
V_23 ,
V_18 ) ;
if ( error < 0 )
return error ;
* V_21 = F_12 ( ( V_24 * ) V_18 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
bool V_25 , T_1 * V_26 )
{
int error ;
T_1 V_18 [ 3 ] ;
error = F_2 ( V_2 ,
V_25 ? V_27 :
V_28 ,
V_18 ) ;
if ( error < 0 ) {
F_3 ( & V_2 -> V_8 , L_4 ,
V_25 ? L_5 : L_6 , error ) ;
return error ;
}
* V_26 = V_18 [ 2 ] ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
T_2 * V_29 , T_1 * V_26 )
{
int error ;
T_1 V_18 [ 3 ] ;
error = F_2 ( V_2 ,
V_30 , V_18 ) ;
if ( error < 0 ) {
F_3 ( & V_2 -> V_8 , L_7 , error ) ;
return error ;
}
* V_26 = V_18 [ 0 ] ;
* V_29 = V_18 [ 1 ] ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_2 * V_31 )
{
int error ;
T_1 V_18 [ 3 ] ;
error = F_2 ( V_2 ,
V_32 , V_18 ) ;
if ( error < 0 ) {
F_3 ( & V_2 -> V_8 , L_8 , error ) ;
return error ;
}
* V_31 = F_12 ( ( V_24 * ) V_18 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
bool V_25 , T_2 * V_33 )
{
int error ;
T_1 V_18 [ 3 ] ;
error = F_2 ( V_2 ,
V_25 ? V_34 :
V_35 ,
V_18 ) ;
if ( error < 0 ) {
F_3 ( & V_2 -> V_8 , L_9 ,
V_25 ? L_5 : L_6 , error ) ;
return error ;
}
* V_33 = F_12 ( ( V_24 * ) V_18 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned int * V_36 , unsigned int * V_37 )
{
int V_38 ;
int error ;
T_1 V_18 [ 3 ] ;
V_38 = F_2 ( V_2 , V_39 , V_18 ) ;
if ( V_38 != 3 ) {
error = V_38 < 0 ? V_38 : - V_9 ;
F_3 ( & V_2 -> V_8 , L_10 , error ) ;
return error ;
}
* V_36 = ( 0x0f & V_18 [ 0 ] ) << 8 | V_18 [ 1 ] ;
* V_37 = ( 0xf0 & V_18 [ 0 ] ) << 4 | V_18 [ 2 ] ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
T_1 * V_40 , T_1 * V_41 )
{
int V_38 ;
int error ;
T_1 V_18 [ 3 ] ;
V_38 = F_2 ( V_2 , V_42 , V_18 ) ;
if ( V_38 != 3 ) {
error = V_38 < 0 ? V_38 : - V_9 ;
F_3 ( & V_2 -> V_8 , L_11 , error ) ;
return error ;
}
* V_40 = V_18 [ 1 ] & 0x0F ;
* V_41 = ( V_18 [ 1 ] & 0xF0 ) >> 4 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
unsigned int * V_43 ,
unsigned int * V_44 )
{
int V_38 ;
int error ;
T_1 V_18 [ 3 ] ;
V_38 = F_2 ( V_2 , V_45 , V_18 ) ;
if ( V_38 != 3 ) {
error = V_38 < 0 ? V_38 : - V_9 ;
F_3 ( & V_2 -> V_8 , L_12 , error ) ;
return error ;
}
* V_43 = V_18 [ 1 ] ;
* V_44 = V_18 [ 2 ] ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
int * V_46 )
{
* V_46 = V_47 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
enum V_48 * V_12 )
{
int error ;
T_2 V_49 ;
T_1 V_18 [ 3 ] ;
error = F_2 ( V_2 , V_50 , V_18 ) ;
if ( error < 0 ) {
F_3 ( & V_2 -> V_8 , L_13 ,
error ) ;
return error ;
}
V_49 = F_12 ( ( V_24 * ) V_18 ) ;
F_22 ( & V_2 -> V_8 , L_14 , V_49 ) ;
* V_12 = ( V_49 & V_51 ) ? V_52 : V_53 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int error ;
error = F_4 ( V_2 , V_54 ) ;
if ( error ) {
F_3 ( & V_2 -> V_8 , L_15 , error ) ;
return error ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int error ;
T_1 V_13 [ 4 ] = { 0x00 , 0x0B , 0x00 , 0x5A } ;
error = F_6 ( V_2 , V_14 ,
sizeof( V_13 ) , V_13 ) ;
if ( error ) {
F_3 ( & V_2 -> V_8 , L_16 , error ) ;
return error ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_55 * V_8 = & V_2 -> V_8 ;
int V_6 ;
int error ;
enum V_48 V_12 ;
T_1 V_18 [ 3 ] ;
T_1 V_13 [ 4 ] = { 0x0F , 0x78 , 0x00 , 0x06 } ;
T_2 V_56 ;
error = F_21 ( V_2 , & V_12 ) ;
if ( error )
return error ;
if ( V_12 == V_53 ) {
error = F_24 ( V_2 ) ;
if ( error )
return error ;
if ( F_4 ( V_2 ,
V_57 ) < 0 ) {
F_3 ( V_8 , L_17 ) ;
return - V_9 ;
}
error = F_6 ( V_2 , V_14 ,
sizeof( V_13 ) , V_13 ) ;
if ( error ) {
F_3 ( V_8 , L_18 ,
error ) ;
return error ;
}
V_6 = F_2 ( V_2 ,
V_58 ,
V_18 ) ;
if ( V_6 < sizeof( T_2 ) ) {
error = V_6 < 0 ? V_6 : - V_9 ;
F_3 ( V_8 , L_19 ,
error ) ;
return error ;
}
V_56 = F_12 ( ( V_24 * ) V_18 ) ;
if ( V_56 != V_59 ) {
F_3 ( V_8 , L_20 , V_56 ) ;
return - V_9 ;
}
F_26 ( 30 ) ;
}
error = F_24 ( V_2 ) ;
if ( error )
return error ;
error = F_23 ( V_2 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
const T_1 * V_60 , T_2 V_61 , int V_62 )
{
struct V_55 * V_8 = & V_2 -> V_8 ;
int error ;
T_2 V_63 ;
T_1 V_18 [ 3 ] ;
error = F_6 ( V_2 ,
V_64 ,
V_65 / 2 ,
V_60 ) ;
if ( error ) {
F_3 ( V_8 , L_21 ,
V_62 , 1 , error ) ;
return error ;
}
error = F_6 ( V_2 ,
V_64 ,
V_65 / 2 ,
V_60 + V_65 / 2 ) ;
if ( error ) {
F_3 ( V_8 , L_21 ,
V_62 , 2 , error ) ;
return error ;
}
F_28 ( 8000 , 10000 ) ;
error = F_2 ( V_2 ,
V_50 , V_18 ) ;
if ( error < 0 ) {
F_3 ( V_8 , L_22 ,
error ) ;
return error ;
}
V_63 = F_12 ( ( V_24 * ) V_18 ) ;
if ( V_63 & ( V_66 | V_67 ) ) {
F_3 ( V_8 , L_23 ,
V_63 ) ;
return - V_9 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , T_1 * V_68 )
{
int V_6 ;
V_6 = F_2 ( V_2 ,
V_69 ,
& V_68 [ V_70 ] ) ;
if ( V_6 < 0 ) {
F_3 ( & V_2 -> V_8 , L_24 , V_6 ) ;
return V_6 ;
}
if ( V_6 != V_71 ) {
F_3 ( & V_2 -> V_8 ,
L_25 ,
V_6 , V_71 ) ;
return - V_9 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_72 * V_73 )
{
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , T_1 * V_74 )
{
* V_74 = 0 ;
return 0 ;
}
