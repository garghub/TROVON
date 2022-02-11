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
static int F_18 ( struct V_1 * V_2 , T_2 * V_41 )
{
int error ;
T_2 V_4 [ 3 ] ;
error = F_5 ( V_2 , V_42 , V_4 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_9 , error ) ;
return error ;
}
* V_41 = V_4 [ 1 ] ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
bool V_43 , T_2 * V_44 )
{
int error ;
T_2 V_45 ;
T_2 V_4 [ 3 ] ;
error = F_18 ( V_2 , & V_45 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_10 ) ;
return error ;
}
error = F_5 ( V_2 ,
V_43 ? V_46 :
V_47 ,
V_4 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_11 ,
V_43 ? L_12 : L_13 , error ) ;
return error ;
}
if ( V_45 == 0x01 )
* V_44 = V_43 ? V_4 [ 1 ] : V_4 [ 0 ] ;
else
* V_44 = V_4 [ 0 ] ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
T_1 * V_48 , T_2 * V_44 ,
T_2 * V_49 )
{
int error ;
T_2 V_45 ;
T_2 V_4 [ 3 ] ;
error = F_18 ( V_2 , & V_45 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_10 ) ;
return error ;
}
if ( V_45 == 0x01 ) {
error = F_5 ( V_2 , V_50 , V_4 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_14 ,
error ) ;
return error ;
}
* V_48 = F_21 ( ( V_51 * ) V_4 ) ;
error = F_5 ( V_2 , V_52 ,
V_4 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_15 ,
error ) ;
return error ;
}
* V_44 = V_4 [ 1 ] ;
* V_49 = V_4 [ 0 ] & 0x10 ;
} else {
error = F_5 ( V_2 , V_53 , V_4 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_15 ,
error ) ;
return error ;
}
* V_44 = V_4 [ 0 ] ;
* V_48 = V_4 [ 1 ] ;
error = F_5 ( V_2 , V_52 ,
V_4 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_15 ,
error ) ;
return error ;
}
* V_49 = V_4 [ 0 ] & 0x10 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , T_1 * V_54 )
{
int error ;
T_2 V_4 [ 3 ] ;
error = F_5 ( V_2 , V_55 , V_4 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_16 , error ) ;
return error ;
}
* V_54 = F_13 ( ( T_3 * ) V_4 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
bool V_43 , T_1 * V_56 )
{
int error ;
T_2 V_4 [ 3 ] ;
error = F_5 ( V_2 ,
V_43 ? V_57 :
V_58 ,
V_4 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_17 ,
V_43 ? L_12 : L_13 , error ) ;
return error ;
}
* V_56 = F_13 ( ( T_3 * ) V_4 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
unsigned int * V_59 , unsigned int * V_60 )
{
int error ;
T_2 V_4 [ 3 ] ;
error = F_5 ( V_2 , V_61 , V_4 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_18 , error ) ;
return error ;
}
* V_59 = F_13 ( ( T_3 * ) V_4 ) & 0x0fff ;
error = F_5 ( V_2 , V_62 , V_4 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_19 , error ) ;
return error ;
}
* V_60 = F_13 ( ( T_3 * ) V_4 ) & 0x0fff ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
T_2 * V_63 , T_2 * V_64 )
{
int error ;
T_2 V_4 [ 3 ] ;
error = F_5 ( V_2 , V_65 , V_4 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_20 , error ) ;
return error ;
}
* V_63 = V_4 [ 0 ] ;
* V_64 = V_4 [ 1 ] ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
unsigned int * V_66 ,
unsigned int * V_67 )
{
int error ;
T_2 V_4 [ 3 ] ;
error = F_5 ( V_2 , V_68 , V_4 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_21 , error ) ;
return error ;
}
* V_66 = V_4 [ 0 ] ;
* V_67 = V_4 [ 1 ] ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
int * V_69 )
{
int error ;
T_2 V_4 [ 3 ] ;
error = F_5 ( V_2 , V_70 , V_4 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_22 ,
error ) ;
return error ;
}
if ( ( V_4 [ 0 ] >> 4 ) & 0x1 )
* V_69 = 0 ;
else
* V_69 = V_71 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , enum V_72 * V_34 )
{
int error ;
T_1 V_73 ;
T_2 V_4 [ 3 ] ;
error = F_5 ( V_2 , V_74 , V_4 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 ,
L_23 ,
error ) ;
return error ;
}
V_73 = F_13 ( ( T_3 * ) V_4 ) ;
F_29 ( & V_2 -> V_18 , L_24 , V_73 ) ;
* V_34 = ( V_73 & V_75 ) ? V_76 : V_77 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
int error ;
error = F_7 ( V_2 , V_78 ,
V_79 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_25 , error ) ;
return error ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int error ;
error = F_7 ( V_2 , V_80 ,
V_81 ) ;
if ( error ) {
F_6 ( & V_2 -> V_18 , L_26 , error ) ;
return error ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_21 * V_18 = & V_2 -> V_18 ;
int error ;
enum V_72 V_34 ;
T_2 V_4 [ 3 ] ;
T_1 V_82 ;
error = F_28 ( V_2 , & V_34 ) ;
if ( error )
return error ;
if ( V_34 == V_77 ) {
error = F_30 ( V_2 ) ;
if ( error )
return error ;
F_9 ( 30 ) ;
}
error = F_31 ( V_2 ) ;
if ( error )
return error ;
F_9 ( V_34 == V_76 ? 100 : 30 ) ;
error = F_28 ( V_2 , & V_34 ) ;
if ( error )
return error ;
if ( V_34 == V_76 ) {
F_6 ( V_18 , L_27 , V_34 ) ;
return - V_15 ;
}
error = F_31 ( V_2 ) ;
if ( error )
return error ;
F_9 ( 30 ) ;
error = F_5 ( V_2 , V_80 , V_4 ) ;
if ( error ) {
F_6 ( V_18 , L_28 ,
error ) ;
return error ;
}
V_82 = F_13 ( ( T_3 * ) V_4 ) ;
if ( V_82 != V_81 ) {
F_6 ( V_18 , L_29 , V_82 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
const T_2 * V_83 , T_1 V_84 , int V_85 )
{
struct V_21 * V_18 = & V_2 -> V_18 ;
T_2 V_86 [ V_87 + 4 ] ;
T_2 V_4 [ 3 ] ;
T_1 V_88 ;
int V_13 , error ;
V_86 [ 0 ] = V_89 ;
V_86 [ 1 ] = V_90 ;
memcpy ( & V_86 [ 2 ] , V_83 , V_87 ) ;
F_34 ( V_84 , & V_86 [ V_87 + 2 ] ) ;
V_13 = F_35 ( V_2 , V_86 , sizeof( V_86 ) ) ;
if ( V_13 != sizeof( V_86 ) ) {
error = V_13 < 0 ? V_13 : - V_15 ;
F_6 ( V_18 , L_30 , V_85 , error ) ;
return error ;
}
F_9 ( 35 ) ;
error = F_5 ( V_2 , V_74 , V_4 ) ;
if ( error ) {
F_6 ( V_18 , L_31 , error ) ;
return error ;
}
V_88 = F_13 ( ( T_3 * ) V_4 ) ;
if ( V_88 & ( V_91 | V_92 ) ) {
F_6 ( V_18 , L_32 ,
V_88 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_93 * V_93 )
{
struct V_21 * V_18 = & V_2 -> V_18 ;
int error ;
int V_5 ;
T_2 V_94 [ V_95 ] ;
V_5 = F_10 ( V_2 , V_94 , V_95 ) ;
if ( V_5 != V_95 ) {
error = V_5 < 0 ? V_5 : - V_15 ;
F_37 ( V_18 , L_33 ,
error , V_5 ) ;
}
F_38 ( V_93 ) ;
F_39 ( V_2 -> V_96 ) ;
error = F_7 ( V_2 , V_22 , V_23 ) ;
if ( error ) {
F_6 ( V_18 , L_3 , error ) ;
} else if ( ! F_40 ( V_93 ,
F_41 ( 300 ) ) ) {
F_6 ( V_18 , L_34 ) ;
error = - V_97 ;
}
F_42 ( V_2 -> V_96 ) ;
if ( error )
return error ;
V_5 = F_10 ( V_2 , V_94 , V_17 ) ;
if ( V_5 != V_17 ) {
error = V_5 < 0 ? V_5 : - V_15 ;
F_6 ( V_18 , L_35 ,
error , V_5 ) ;
return error ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , T_2 * V_98 )
{
int V_5 ;
V_5 = F_10 ( V_2 , V_98 , V_95 ) ;
if ( V_5 < 0 ) {
F_6 ( & V_2 -> V_18 , L_36 , V_5 ) ;
return V_5 ;
}
if ( V_5 != V_95 ) {
F_6 ( & V_2 -> V_18 ,
L_37 ,
V_5 , V_95 ) ;
return - V_15 ;
}
return 0 ;
}
