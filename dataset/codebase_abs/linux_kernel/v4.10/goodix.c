static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 * V_4 , int V_5 )
{
struct V_6 V_7 [ 2 ] ;
T_1 V_8 = F_2 ( V_3 ) ;
int V_9 ;
V_7 [ 0 ] . V_10 = 0 ;
V_7 [ 0 ] . V_11 = V_2 -> V_11 ;
V_7 [ 0 ] . V_5 = 2 ;
V_7 [ 0 ] . V_4 = ( T_2 * ) & V_8 ;
V_7 [ 1 ] . V_10 = V_12 ;
V_7 [ 1 ] . V_11 = V_2 -> V_11 ;
V_7 [ 1 ] . V_5 = V_5 ;
V_7 [ 1 ] . V_4 = V_4 ;
V_9 = F_3 ( V_2 -> V_13 , V_7 , 2 ) ;
return V_9 < 0 ? V_9 : ( V_9 != F_4 ( V_7 ) ? - V_14 : 0 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , const T_2 * V_4 ,
unsigned V_5 )
{
T_2 * V_15 ;
struct V_6 V_16 ;
int V_9 ;
V_15 = F_6 ( V_5 + 2 , V_17 ) ;
if ( ! V_15 )
return - V_18 ;
V_15 [ 0 ] = V_3 >> 8 ;
V_15 [ 1 ] = V_3 & 0xFF ;
memcpy ( & V_15 [ 2 ] , V_4 , V_5 ) ;
V_16 . V_10 = 0 ;
V_16 . V_11 = V_2 -> V_11 ;
V_16 . V_4 = V_15 ;
V_16 . V_5 = V_5 + 2 ;
V_9 = F_3 ( V_2 -> V_13 , & V_16 , 1 ) ;
F_7 ( V_15 ) ;
return V_9 < 0 ? V_9 : ( V_9 != 1 ? - V_14 : 0 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_19 )
{
return F_5 ( V_2 , V_3 , & V_19 , sizeof( V_19 ) ) ;
}
static int F_9 ( T_1 V_20 )
{
switch ( V_20 ) {
case 911 :
case 9271 :
case 9110 :
case 927 :
case 928 :
return V_21 ;
case 912 :
case 967 :
return V_22 ;
default:
return V_23 ;
}
}
static int F_10 ( struct V_24 * V_25 , T_2 * V_26 )
{
int V_27 ;
int error ;
error = F_1 ( V_25 -> V_2 , V_28 , V_26 ,
V_29 + 1 ) ;
if ( error ) {
F_11 ( & V_25 -> V_2 -> V_30 , L_1 , error ) ;
return error ;
}
if ( ! ( V_26 [ 0 ] & 0x80 ) )
return - V_31 ;
V_27 = V_26 [ 0 ] & 0x0f ;
if ( V_27 > V_25 -> V_32 )
return - V_33 ;
if ( V_27 > 1 ) {
V_26 += 1 + V_29 ;
error = F_1 ( V_25 -> V_2 ,
V_28 +
1 + V_29 ,
V_26 ,
V_29 * ( V_27 - 1 ) ) ;
if ( error )
return error ;
}
return V_27 ;
}
static void F_12 ( struct V_24 * V_25 , T_2 * V_34 )
{
int V_20 = V_34 [ 0 ] & 0x0F ;
int V_35 = F_13 ( & V_34 [ 1 ] ) ;
int V_36 = F_13 ( & V_34 [ 3 ] ) ;
int V_37 = F_13 ( & V_34 [ 5 ] ) ;
if ( V_25 -> V_38 )
V_35 = V_25 -> V_39 - V_35 ;
if ( V_25 -> V_40 )
V_36 = V_25 -> V_41 - V_36 ;
if ( V_25 -> V_42 )
F_14 ( V_35 , V_36 ) ;
F_15 ( V_25 -> V_43 , V_20 ) ;
F_16 ( V_25 -> V_43 , V_44 , true ) ;
F_17 ( V_25 -> V_43 , V_45 , V_35 ) ;
F_17 ( V_25 -> V_43 , V_46 , V_36 ) ;
F_17 ( V_25 -> V_43 , V_47 , V_37 ) ;
F_17 ( V_25 -> V_43 , V_48 , V_37 ) ;
}
static void F_18 ( struct V_24 * V_25 )
{
T_2 V_49 [ 1 + V_29 * V_50 ] ;
int V_27 ;
int V_51 ;
V_27 = F_10 ( V_25 , V_49 ) ;
if ( V_27 < 0 )
return;
for ( V_51 = 0 ; V_51 < V_27 ; V_51 ++ )
F_12 ( V_25 ,
& V_49 [ 1 + V_29 * V_51 ] ) ;
F_19 ( V_25 -> V_43 ) ;
F_20 ( V_25 -> V_43 ) ;
}
static T_3 F_21 ( int V_52 , void * V_53 )
{
struct V_24 * V_25 = V_53 ;
F_18 ( V_25 ) ;
if ( F_8 ( V_25 -> V_2 , V_28 , 0 ) < 0 )
F_11 ( & V_25 -> V_2 -> V_30 , L_2 ) ;
return V_54 ;
}
static void F_22 ( struct V_24 * V_25 )
{
F_23 ( & V_25 -> V_2 -> V_30 , V_25 -> V_2 -> V_52 , V_25 ) ;
}
static int F_24 ( struct V_24 * V_25 )
{
return F_25 ( & V_25 -> V_2 -> V_30 , V_25 -> V_2 -> V_52 ,
NULL , F_21 ,
V_25 -> V_55 , V_25 -> V_2 -> V_56 , V_25 ) ;
}
static int F_26 ( struct V_24 * V_25 ,
const struct V_57 * V_58 )
{
int V_51 , V_59 ;
T_2 V_60 = 0 ;
if ( V_58 -> V_61 > V_23 ) {
F_11 ( & V_25 -> V_2 -> V_30 ,
L_3 ) ;
return - V_62 ;
}
V_59 = V_58 -> V_61 - 2 ;
for ( V_51 = 0 ; V_51 < V_59 ; V_51 ++ )
V_60 += V_58 -> V_26 [ V_51 ] ;
V_60 = ( ~ V_60 ) + 1 ;
if ( V_60 != V_58 -> V_26 [ V_59 ] ) {
F_11 ( & V_25 -> V_2 -> V_30 ,
L_4 ) ;
return - V_62 ;
}
if ( V_58 -> V_26 [ V_59 + 1 ] != 1 ) {
F_11 ( & V_25 -> V_2 -> V_30 ,
L_5 ) ;
return - V_62 ;
}
return 0 ;
}
static int F_27 ( struct V_24 * V_25 ,
const struct V_57 * V_58 )
{
int error ;
error = F_26 ( V_25 , V_58 ) ;
if ( error )
return error ;
error = F_5 ( V_25 -> V_2 , V_63 , V_58 -> V_26 ,
V_58 -> V_61 ) ;
if ( error ) {
F_11 ( & V_25 -> V_2 -> V_30 , L_6 ,
error ) ;
return error ;
}
F_28 ( & V_25 -> V_2 -> V_30 , L_7 ) ;
F_29 ( 10000 , 11000 ) ;
return 0 ;
}
static int F_30 ( struct V_24 * V_25 )
{
int error ;
error = F_31 ( V_25 -> V_64 , 0 ) ;
if ( error )
return error ;
F_32 ( 50 ) ;
error = F_33 ( V_25 -> V_64 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_34 ( struct V_24 * V_25 )
{
int error ;
error = F_31 ( V_25 -> V_65 , 0 ) ;
if ( error )
return error ;
F_32 ( 20 ) ;
error = F_31 ( V_25 -> V_64 , V_25 -> V_2 -> V_11 == 0x14 ) ;
if ( error )
return error ;
F_29 ( 100 , 2000 ) ;
error = F_31 ( V_25 -> V_65 , 1 ) ;
if ( error )
return error ;
F_29 ( 6000 , 10000 ) ;
error = F_33 ( V_25 -> V_65 ) ;
if ( error )
return error ;
error = F_30 ( V_25 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_35 ( struct V_24 * V_25 )
{
int error ;
struct V_66 * V_30 ;
struct V_67 * V_68 ;
if ( ! V_25 -> V_2 )
return - V_62 ;
V_30 = & V_25 -> V_2 -> V_30 ;
V_68 = F_36 ( V_30 , V_69 , V_70 ) ;
if ( F_37 ( V_68 ) ) {
error = F_38 ( V_68 ) ;
if ( error != - V_71 )
F_28 ( V_30 , L_8 ,
V_69 , error ) ;
return error ;
}
V_25 -> V_64 = V_68 ;
V_68 = F_36 ( V_30 , V_72 , V_70 ) ;
if ( F_37 ( V_68 ) ) {
error = F_38 ( V_68 ) ;
if ( error != - V_71 )
F_28 ( V_30 , L_8 ,
V_72 , error ) ;
return error ;
}
V_25 -> V_65 = V_68 ;
return 0 ;
}
static void F_39 ( struct V_24 * V_25 )
{
T_2 V_73 [ V_23 ] ;
int error ;
error = F_1 ( V_25 -> V_2 , V_63 ,
V_73 , V_25 -> V_74 ) ;
if ( error ) {
F_40 ( & V_25 -> V_2 -> V_30 ,
L_9 ,
error ) ;
V_25 -> V_39 = V_75 ;
V_25 -> V_41 = V_76 ;
if ( V_25 -> V_42 )
F_14 ( V_25 -> V_39 , V_25 -> V_41 ) ;
V_25 -> V_77 = V_78 ;
V_25 -> V_32 = V_50 ;
return;
}
V_25 -> V_39 = F_13 ( & V_73 [ V_79 ] ) ;
V_25 -> V_41 = F_13 ( & V_73 [ V_79 + 2 ] ) ;
if ( V_25 -> V_42 )
F_14 ( V_25 -> V_39 , V_25 -> V_41 ) ;
V_25 -> V_77 = V_73 [ V_80 ] & 0x03 ;
V_25 -> V_32 = V_73 [ V_81 ] & 0x0f ;
if ( ! V_25 -> V_39 || ! V_25 -> V_41 || ! V_25 -> V_32 ) {
F_11 ( & V_25 -> V_2 -> V_30 ,
L_10 ) ;
V_25 -> V_39 = V_75 ;
V_25 -> V_41 = V_76 ;
if ( V_25 -> V_42 )
F_14 ( V_25 -> V_39 , V_25 -> V_41 ) ;
V_25 -> V_32 = V_50 ;
}
if ( F_41 ( V_82 ) ) {
V_25 -> V_38 = true ;
V_25 -> V_40 = true ;
F_28 ( & V_25 -> V_2 -> V_30 ,
L_11 ) ;
}
}
static int F_42 ( struct V_24 * V_25 )
{
int error ;
T_2 V_4 [ 6 ] ;
char V_83 [ 5 ] ;
error = F_1 ( V_25 -> V_2 , V_84 , V_4 , sizeof( V_4 ) ) ;
if ( error ) {
F_11 ( & V_25 -> V_2 -> V_30 , L_12 , error ) ;
return error ;
}
memcpy ( V_83 , V_4 , 4 ) ;
V_83 [ 4 ] = 0 ;
if ( F_43 ( V_83 , 10 , & V_25 -> V_20 ) )
V_25 -> V_20 = 0x1001 ;
V_25 -> V_85 = F_13 ( & V_4 [ 4 ] ) ;
F_44 ( & V_25 -> V_2 -> V_30 , L_13 , V_25 -> V_20 ,
V_25 -> V_85 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_86 = 0 ;
int error ;
T_2 V_87 ;
while ( V_86 ++ < 2 ) {
error = F_1 ( V_2 , V_63 ,
& V_87 , 1 ) ;
if ( ! error )
return 0 ;
F_11 ( & V_2 -> V_30 , L_14 ,
V_86 , error ) ;
F_32 ( 20 ) ;
}
return error ;
}
static int F_46 ( struct V_24 * V_25 )
{
int error ;
V_25 -> V_43 = F_47 ( & V_25 -> V_2 -> V_30 ) ;
if ( ! V_25 -> V_43 ) {
F_11 ( & V_25 -> V_2 -> V_30 , L_15 ) ;
return - V_18 ;
}
F_48 ( V_25 -> V_43 , V_45 ,
0 , V_25 -> V_39 , 0 , 0 ) ;
F_48 ( V_25 -> V_43 , V_46 ,
0 , V_25 -> V_41 , 0 , 0 ) ;
F_48 ( V_25 -> V_43 , V_48 , 0 , 255 , 0 , 0 ) ;
F_48 ( V_25 -> V_43 , V_47 , 0 , 255 , 0 , 0 ) ;
F_49 ( V_25 -> V_43 , V_25 -> V_32 ,
V_88 | V_89 ) ;
V_25 -> V_43 -> V_56 = L_16 ;
V_25 -> V_43 -> V_90 = L_17 ;
V_25 -> V_43 -> V_20 . V_91 = V_92 ;
V_25 -> V_43 -> V_20 . V_93 = 0x0416 ;
V_25 -> V_43 -> V_20 . V_94 = V_25 -> V_20 ;
V_25 -> V_43 -> V_20 . V_85 = V_25 -> V_85 ;
error = F_50 ( V_25 -> V_43 ) ;
if ( error ) {
F_11 ( & V_25 -> V_2 -> V_30 ,
L_18 , error ) ;
return error ;
}
return 0 ;
}
static int F_51 ( struct V_24 * V_25 )
{
int error ;
V_25 -> V_42 = F_52 ( & V_25 -> V_2 -> V_30 ,
L_19 ) ;
V_25 -> V_38 = F_52 ( & V_25 -> V_2 -> V_30 ,
L_20 ) ;
V_25 -> V_40 = F_52 ( & V_25 -> V_2 -> V_30 ,
L_21 ) ;
F_39 ( V_25 ) ;
error = F_46 ( V_25 ) ;
if ( error )
return error ;
V_25 -> V_55 = V_95 [ V_25 -> V_77 ] | V_96 ;
error = F_24 ( V_25 ) ;
if ( error ) {
F_11 ( & V_25 -> V_2 -> V_30 , L_22 , error ) ;
return error ;
}
return 0 ;
}
static void F_53 ( const struct V_57 * V_58 , void * V_97 )
{
struct V_24 * V_25 = V_97 ;
int error ;
if ( V_58 ) {
error = F_27 ( V_25 , V_58 ) ;
if ( error )
goto V_98;
}
F_51 ( V_25 ) ;
V_98:
F_54 ( V_58 ) ;
F_55 ( & V_25 -> V_99 ) ;
}
static int F_56 ( struct V_1 * V_2 ,
const struct V_100 * V_20 )
{
struct V_24 * V_25 ;
int error ;
F_28 ( & V_2 -> V_30 , L_23 , V_2 -> V_11 ) ;
if ( ! F_57 ( V_2 -> V_13 , V_101 ) ) {
F_11 ( & V_2 -> V_30 , L_24 ) ;
return - V_102 ;
}
V_25 = F_58 ( & V_2 -> V_30 , sizeof( * V_25 ) , V_17 ) ;
if ( ! V_25 )
return - V_18 ;
V_25 -> V_2 = V_2 ;
F_59 ( V_2 , V_25 ) ;
F_60 ( & V_25 -> V_99 ) ;
error = F_35 ( V_25 ) ;
if ( error )
return error ;
if ( V_25 -> V_64 && V_25 -> V_65 ) {
error = F_34 ( V_25 ) ;
if ( error ) {
F_11 ( & V_2 -> V_30 , L_25 ) ;
return error ;
}
}
error = F_45 ( V_2 ) ;
if ( error ) {
F_11 ( & V_2 -> V_30 , L_26 , error ) ;
return error ;
}
error = F_42 ( V_25 ) ;
if ( error ) {
F_11 ( & V_2 -> V_30 , L_27 ) ;
return error ;
}
V_25 -> V_74 = F_9 ( V_25 -> V_20 ) ;
if ( V_25 -> V_64 && V_25 -> V_65 ) {
V_25 -> V_103 = F_61 ( & V_2 -> V_30 , V_17 ,
L_28 , V_25 -> V_20 ) ;
if ( ! V_25 -> V_103 )
return - V_18 ;
error = F_62 ( V_104 , true , V_25 -> V_103 ,
& V_2 -> V_30 , V_17 , V_25 ,
F_53 ) ;
if ( error ) {
F_11 ( & V_2 -> V_30 ,
L_29 ,
error ) ;
return error ;
}
return 0 ;
} else {
error = F_51 ( V_25 ) ;
if ( error )
return error ;
}
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_64 ( V_2 ) ;
if ( V_25 -> V_64 && V_25 -> V_65 )
F_65 ( & V_25 -> V_99 ) ;
return 0 ;
}
static int T_4 F_66 ( struct V_66 * V_30 )
{
struct V_1 * V_2 = F_67 ( V_30 ) ;
struct V_24 * V_25 = F_64 ( V_2 ) ;
int error ;
if ( ! V_25 -> V_64 || ! V_25 -> V_65 )
return 0 ;
F_65 ( & V_25 -> V_99 ) ;
F_22 ( V_25 ) ;
error = F_31 ( V_25 -> V_64 , 0 ) ;
if ( error ) {
F_24 ( V_25 ) ;
return error ;
}
F_29 ( 5000 , 6000 ) ;
error = F_8 ( V_25 -> V_2 , V_105 ,
V_106 ) ;
if ( error ) {
F_11 ( & V_25 -> V_2 -> V_30 , L_30 ) ;
F_33 ( V_25 -> V_64 ) ;
F_24 ( V_25 ) ;
return - V_31 ;
}
F_32 ( 58 ) ;
return 0 ;
}
static int T_4 F_68 ( struct V_66 * V_30 )
{
struct V_1 * V_2 = F_67 ( V_30 ) ;
struct V_24 * V_25 = F_64 ( V_2 ) ;
int error ;
if ( ! V_25 -> V_64 || ! V_25 -> V_65 )
return 0 ;
error = F_31 ( V_25 -> V_64 , 1 ) ;
if ( error )
return error ;
F_29 ( 2000 , 5000 ) ;
error = F_30 ( V_25 ) ;
if ( error )
return error ;
error = F_24 ( V_25 ) ;
if ( error )
return error ;
return 0 ;
}
