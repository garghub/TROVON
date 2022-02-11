static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 * V_4 , T_1 V_5 )
{
T_3 V_6 [] = {
F_2 ( V_3 ) ,
} ;
struct V_7 V_8 [] = {
{
. V_9 = V_2 -> V_9 ,
. V_10 = V_2 -> V_10 & V_11 ,
. V_5 = sizeof( V_6 ) ,
. V_6 = ( T_2 * ) V_6 ,
} ,
{
. V_9 = V_2 -> V_9 ,
. V_10 = ( V_2 -> V_10 & V_11 ) | V_12 ,
. V_5 = V_5 ,
. V_6 = V_4 ,
}
} ;
int V_13 ;
V_13 = F_3 ( V_2 -> V_14 , V_8 , F_4 ( V_8 ) ) ;
return V_13 == F_4 ( V_8 ) ? 0 : ( V_13 < 0 ? V_13 : - V_15 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
int V_16 ;
V_16 = F_1 ( V_2 , V_3 , V_4 , V_17 ) ;
if ( V_16 < 0 ) {
F_6 ( & V_2 -> V_18 , L_1 , V_3 ) ;
return V_16 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_19 )
{
T_3 V_6 [] = {
F_2 ( V_3 ) ,
F_2 ( V_19 ) ,
} ;
struct V_7 V_20 = {
. V_9 = V_2 -> V_9 ,
. V_10 = V_2 -> V_10 & V_11 ,
. V_5 = sizeof( V_6 ) ,
. V_6 = ( T_2 * ) V_6 ,
} ;
int V_13 ;
V_13 = F_3 ( V_2 -> V_14 , & V_20 , 1 ) ;
if ( V_13 != 1 ) {
if ( V_13 >= 0 )
V_13 = - V_15 ;
F_6 ( & V_2 -> V_18 , L_2 ,
V_3 , V_13 ) ;
return V_13 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_21 * V_18 = & V_2 -> V_18 ;
int error ;
T_2 V_4 [ 256 ] ;
error = F_7 ( V_2 , V_22 , V_23 ) ;
if ( error ) {
F_6 ( V_18 , L_3 , error ) ;
return error ;
}
F_9 ( 100 ) ;
error = F_10 ( V_2 , V_4 , V_17 ) ;
if ( error < 0 ) {
F_6 ( V_18 , L_4 , error ) ;
return error ;
}
error = F_1 ( V_2 , V_24 ,
V_4 , V_25 ) ;
if ( error ) {
F_6 ( V_18 , L_5 , error ) ;
return error ;
}
error = F_1 ( V_2 , V_26 ,
V_4 , V_27 ) ;
if ( error ) {
F_6 ( V_18 , L_6 , error ) ;
return error ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , bool V_28 )
{
return F_7 ( V_2 , V_22 ,
V_28 ? V_29 : V_30 ) ;
}
static int F_12 ( struct V_1 * V_2 , bool V_31 )
{
T_2 V_4 [ 2 ] ;
T_1 V_3 ;
int error ;
error = F_5 ( V_2 , V_32 , V_4 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 ,
L_7 ,
error ) ;
return error ;
}
V_3 = F_13 ( ( T_3 * ) V_4 ) ;
if ( V_31 )
V_3 &= ~ V_33 ;
else
V_3 |= V_33 ;
error = F_7 ( V_2 , V_32 , V_3 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 ,
L_8 ,
error ) ;
return error ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_2 V_34 )
{
return F_7 ( V_2 , V_35 , V_34 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , V_36 , 1 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_2 * V_4 )
{
return F_1 ( V_2 , V_36 , V_4 , 1 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
bool V_37 , T_2 * V_38 )
{
int error ;
T_2 V_4 [ 3 ] ;
error = F_5 ( V_2 ,
V_37 ? V_39 :
V_40 ,
V_4 ) ;
if ( error )
return error ;
* V_38 = F_13 ( ( T_3 * ) V_4 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
bool V_41 , T_2 * V_42 )
{
int error ;
T_2 V_4 [ 3 ] ;
error = F_5 ( V_2 ,
V_41 ? V_43 :
V_44 ,
V_4 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_9 ,
V_41 ? L_10 : L_11 , error ) ;
return error ;
}
* V_42 = V_4 [ 0 ] ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
T_2 * V_45 , T_2 * V_42 )
{
int error ;
T_2 V_4 [ 3 ] ;
error = F_5 ( V_2 , V_46 , V_4 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_12 , error ) ;
return error ;
}
* V_42 = V_4 [ 0 ] ;
* V_45 = V_4 [ 1 ] ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , T_1 * V_47 )
{
int error ;
T_2 V_4 [ 3 ] ;
error = F_5 ( V_2 , V_48 , V_4 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_13 , error ) ;
return error ;
}
* V_47 = F_13 ( ( T_3 * ) V_4 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
bool V_41 , T_1 * V_49 )
{
int error ;
T_2 V_4 [ 3 ] ;
error = F_5 ( V_2 ,
V_41 ? V_50 :
V_51 ,
V_4 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_14 ,
V_41 ? L_10 : L_11 , error ) ;
return error ;
}
* V_49 = F_13 ( ( T_3 * ) V_4 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
unsigned int * V_52 , unsigned int * V_53 )
{
int error ;
T_2 V_4 [ 3 ] ;
error = F_5 ( V_2 , V_54 , V_4 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_15 , error ) ;
return error ;
}
* V_52 = F_13 ( ( T_3 * ) V_4 ) & 0x0fff ;
error = F_5 ( V_2 , V_55 , V_4 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_16 , error ) ;
return error ;
}
* V_53 = F_13 ( ( T_3 * ) V_4 ) & 0x0fff ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
T_2 * V_56 , T_2 * V_57 )
{
int error ;
T_2 V_4 [ 3 ] ;
error = F_5 ( V_2 , V_58 , V_4 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_17 , error ) ;
return error ;
}
* V_56 = V_4 [ 0 ] ;
* V_57 = V_4 [ 1 ] ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
unsigned int * V_59 ,
unsigned int * V_60 )
{
int error ;
T_2 V_4 [ 3 ] ;
error = F_5 ( V_2 , V_61 , V_4 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_18 , error ) ;
return error ;
}
* V_59 = V_4 [ 0 ] ;
* V_60 = V_4 [ 1 ] ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
int * V_62 )
{
int error ;
T_2 V_4 [ 3 ] ;
error = F_5 ( V_2 , V_63 , V_4 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_19 ,
error ) ;
return error ;
}
if ( ( V_4 [ 0 ] >> 4 ) & 0x1 )
* V_62 = 0 ;
else
* V_62 = V_64 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , enum V_65 * V_34 )
{
int error ;
T_1 V_66 ;
T_2 V_4 [ 3 ] ;
error = F_5 ( V_2 , V_67 , V_4 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 ,
L_20 ,
error ) ;
return error ;
}
V_66 = F_13 ( ( T_3 * ) V_4 ) ;
F_27 ( & V_2 -> V_18 , L_21 , V_66 ) ;
* V_34 = ( V_66 & V_68 ) ? V_69 : V_70 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int error ;
error = F_7 ( V_2 , V_71 ,
V_72 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_22 , error ) ;
return error ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int error ;
error = F_7 ( V_2 , V_73 ,
V_74 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_23 , error ) ;
return error ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_21 * V_18 = & V_2 -> V_18 ;
int error ;
enum V_65 V_34 ;
T_2 V_4 [ 3 ] ;
T_1 V_75 ;
error = F_26 ( V_2 , & V_34 ) ;
if ( error )
return error ;
if ( V_34 == V_70 ) {
error = F_28 ( V_2 ) ;
if ( error )
return error ;
F_9 ( 30 ) ;
}
error = F_29 ( V_2 ) ;
if ( error )
return error ;
F_9 ( V_34 == V_69 ? 100 : 30 ) ;
error = F_26 ( V_2 , & V_34 ) ;
if ( error )
return error ;
if ( V_34 == V_69 ) {
F_6 ( V_18 , L_24 , V_34 ) ;
return - V_15 ;
}
error = F_29 ( V_2 ) ;
if ( error )
return error ;
F_9 ( 30 ) ;
error = F_5 ( V_2 , V_73 , V_4 ) ;
if ( error ) {
F_6 ( V_18 , L_25 ,
error ) ;
return error ;
}
V_75 = F_13 ( ( T_3 * ) V_4 ) ;
if ( V_75 != V_74 ) {
F_6 ( V_18 , L_26 , V_75 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
const T_2 * V_76 , T_1 V_77 , int V_78 )
{
struct V_21 * V_18 = & V_2 -> V_18 ;
T_2 V_79 [ V_80 + 4 ] ;
T_2 V_4 [ 3 ] ;
T_1 V_81 ;
int V_13 , error ;
V_79 [ 0 ] = V_82 ;
V_79 [ 1 ] = V_83 ;
memcpy ( & V_79 [ 2 ] , V_76 , V_80 ) ;
F_32 ( V_77 , & V_79 [ V_80 + 2 ] ) ;
V_13 = F_33 ( V_2 , V_79 , sizeof( V_79 ) ) ;
if ( V_13 != sizeof( V_79 ) ) {
error = V_13 < 0 ? V_13 : - V_15 ;
F_6 ( V_18 , L_27 , V_78 , error ) ;
return error ;
}
F_9 ( 20 ) ;
error = F_5 ( V_2 , V_67 , V_4 ) ;
if ( error ) {
F_6 ( V_18 , L_28 , error ) ;
return error ;
}
V_81 = F_13 ( ( T_3 * ) V_4 ) ;
if ( V_81 & ( V_84 | V_85 ) ) {
F_6 ( V_18 , L_29 ,
V_81 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_86 * V_86 )
{
struct V_21 * V_18 = & V_2 -> V_18 ;
int error ;
int V_5 ;
T_2 V_87 [ V_88 ] ;
V_5 = F_10 ( V_2 , V_87 , V_88 ) ;
if ( V_5 != V_88 ) {
error = V_5 < 0 ? V_5 : - V_15 ;
F_35 ( V_18 , L_30 ,
error , V_5 ) ;
}
F_36 ( V_86 ) ;
F_37 ( V_2 -> V_89 ) ;
error = F_7 ( V_2 , V_22 , V_23 ) ;
if ( error ) {
F_6 ( V_18 , L_3 , error ) ;
} else if ( ! F_38 ( V_86 ,
F_39 ( 300 ) ) ) {
F_6 ( V_18 , L_31 ) ;
error = - V_90 ;
}
F_40 ( V_2 -> V_89 ) ;
if ( error )
return error ;
V_5 = F_10 ( V_2 , V_87 , V_17 ) ;
if ( V_5 != V_17 ) {
error = V_5 < 0 ? V_5 : - V_15 ;
F_6 ( V_18 , L_32 ,
error , V_5 ) ;
return error ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , T_2 * V_91 )
{
int V_5 ;
V_5 = F_10 ( V_2 , V_91 , V_88 ) ;
if ( V_5 < 0 ) {
F_6 ( & V_2 -> V_18 , L_33 , V_5 ) ;
return V_5 ;
}
if ( V_5 != V_88 ) {
F_6 ( & V_2 -> V_18 ,
L_34 ,
V_5 , V_88 ) ;
return - V_15 ;
}
return 0 ;
}
