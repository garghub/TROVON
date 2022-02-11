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
unsigned long V_27 ;
int V_28 ;
int error ;
V_27 = V_29 + F_11 ( V_30 ) ;
do {
error = F_1 ( V_25 -> V_2 , V_31 ,
V_26 , V_32 + 1 ) ;
if ( error ) {
F_12 ( & V_25 -> V_2 -> V_33 , L_1 ,
error ) ;
return error ;
}
if ( V_26 [ 0 ] & V_34 ) {
V_28 = V_26 [ 0 ] & 0x0f ;
if ( V_28 > V_25 -> V_35 )
return - V_36 ;
if ( V_28 > 1 ) {
V_26 += 1 + V_32 ;
error = F_1 ( V_25 -> V_2 ,
V_31 +
1 + V_32 ,
V_26 ,
V_32 *
( V_28 - 1 ) ) ;
if ( error )
return error ;
}
return V_28 ;
}
F_13 ( 1000 , 2000 ) ;
} while ( F_14 ( V_29 , V_27 ) );
return 0 ;
}
static void F_15 ( struct V_24 * V_25 , T_2 * V_37 )
{
int V_20 = V_37 [ 0 ] & 0x0F ;
int V_38 = F_16 ( & V_37 [ 1 ] ) ;
int V_39 = F_16 ( & V_37 [ 3 ] ) ;
int V_40 = F_16 ( & V_37 [ 5 ] ) ;
if ( V_25 -> V_41 )
V_38 = V_25 -> V_42 - V_38 ;
if ( V_25 -> V_43 )
V_39 = V_25 -> V_44 - V_39 ;
if ( V_25 -> V_45 )
F_17 ( V_38 , V_39 ) ;
F_18 ( V_25 -> V_46 , V_20 ) ;
F_19 ( V_25 -> V_46 , V_47 , true ) ;
F_20 ( V_25 -> V_46 , V_48 , V_38 ) ;
F_20 ( V_25 -> V_46 , V_49 , V_39 ) ;
F_20 ( V_25 -> V_46 , V_50 , V_40 ) ;
F_20 ( V_25 -> V_46 , V_51 , V_40 ) ;
}
static void F_21 ( struct V_24 * V_25 )
{
T_2 V_52 [ 1 + V_32 * V_53 ] ;
int V_28 ;
int V_54 ;
V_28 = F_10 ( V_25 , V_52 ) ;
if ( V_28 < 0 )
return;
F_22 ( V_25 -> V_46 , V_55 , V_52 [ 0 ] & F_23 ( 4 ) ) ;
for ( V_54 = 0 ; V_54 < V_28 ; V_54 ++ )
F_15 ( V_25 ,
& V_52 [ 1 + V_32 * V_54 ] ) ;
F_24 ( V_25 -> V_46 ) ;
F_25 ( V_25 -> V_46 ) ;
}
static T_3 F_26 ( int V_56 , void * V_57 )
{
struct V_24 * V_25 = V_57 ;
F_21 ( V_25 ) ;
if ( F_8 ( V_25 -> V_2 , V_31 , 0 ) < 0 )
F_12 ( & V_25 -> V_2 -> V_33 , L_2 ) ;
return V_58 ;
}
static void F_27 ( struct V_24 * V_25 )
{
F_28 ( & V_25 -> V_2 -> V_33 , V_25 -> V_2 -> V_56 , V_25 ) ;
}
static int F_29 ( struct V_24 * V_25 )
{
return F_30 ( & V_25 -> V_2 -> V_33 , V_25 -> V_2 -> V_56 ,
NULL , F_26 ,
V_25 -> V_59 , V_25 -> V_2 -> V_60 , V_25 ) ;
}
static int F_31 ( struct V_24 * V_25 ,
const struct V_61 * V_62 )
{
int V_54 , V_63 ;
T_2 V_64 = 0 ;
if ( V_62 -> V_65 > V_23 ) {
F_12 ( & V_25 -> V_2 -> V_33 ,
L_3 ) ;
return - V_66 ;
}
V_63 = V_62 -> V_65 - 2 ;
for ( V_54 = 0 ; V_54 < V_63 ; V_54 ++ )
V_64 += V_62 -> V_26 [ V_54 ] ;
V_64 = ( ~ V_64 ) + 1 ;
if ( V_64 != V_62 -> V_26 [ V_63 ] ) {
F_12 ( & V_25 -> V_2 -> V_33 ,
L_4 ) ;
return - V_66 ;
}
if ( V_62 -> V_26 [ V_63 + 1 ] != 1 ) {
F_12 ( & V_25 -> V_2 -> V_33 ,
L_5 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_32 ( struct V_24 * V_25 ,
const struct V_61 * V_62 )
{
int error ;
error = F_31 ( V_25 , V_62 ) ;
if ( error )
return error ;
error = F_5 ( V_25 -> V_2 , V_67 , V_62 -> V_26 ,
V_62 -> V_65 ) ;
if ( error ) {
F_12 ( & V_25 -> V_2 -> V_33 , L_6 ,
error ) ;
return error ;
}
F_33 ( & V_25 -> V_2 -> V_33 , L_7 ) ;
F_13 ( 10000 , 11000 ) ;
return 0 ;
}
static int F_34 ( struct V_24 * V_25 )
{
int error ;
error = F_35 ( V_25 -> V_68 , 0 ) ;
if ( error )
return error ;
F_36 ( 50 ) ;
error = F_37 ( V_25 -> V_68 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_38 ( struct V_24 * V_25 )
{
int error ;
error = F_35 ( V_25 -> V_69 , 0 ) ;
if ( error )
return error ;
F_36 ( 20 ) ;
error = F_35 ( V_25 -> V_68 , V_25 -> V_2 -> V_11 == 0x14 ) ;
if ( error )
return error ;
F_13 ( 100 , 2000 ) ;
error = F_35 ( V_25 -> V_69 , 1 ) ;
if ( error )
return error ;
F_13 ( 6000 , 10000 ) ;
error = F_37 ( V_25 -> V_69 ) ;
if ( error )
return error ;
error = F_34 ( V_25 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_39 ( struct V_24 * V_25 )
{
int error ;
struct V_70 * V_33 ;
struct V_71 * V_72 ;
if ( ! V_25 -> V_2 )
return - V_66 ;
V_33 = & V_25 -> V_2 -> V_33 ;
V_72 = F_40 ( V_33 , V_73 , V_74 ) ;
if ( F_41 ( V_72 ) ) {
error = F_42 ( V_72 ) ;
if ( error != - V_75 )
F_33 ( V_33 , L_8 ,
V_73 , error ) ;
return error ;
}
V_25 -> V_68 = V_72 ;
V_72 = F_40 ( V_33 , V_76 , V_74 ) ;
if ( F_41 ( V_72 ) ) {
error = F_42 ( V_72 ) ;
if ( error != - V_75 )
F_33 ( V_33 , L_8 ,
V_76 , error ) ;
return error ;
}
V_25 -> V_69 = V_72 ;
return 0 ;
}
static void F_43 ( struct V_24 * V_25 )
{
T_2 V_77 [ V_23 ] ;
int error ;
error = F_1 ( V_25 -> V_2 , V_67 ,
V_77 , V_25 -> V_78 ) ;
if ( error ) {
F_44 ( & V_25 -> V_2 -> V_33 ,
L_9 ,
error ) ;
V_25 -> V_42 = V_79 ;
V_25 -> V_44 = V_80 ;
if ( V_25 -> V_45 )
F_17 ( V_25 -> V_42 , V_25 -> V_44 ) ;
V_25 -> V_81 = V_82 ;
V_25 -> V_35 = V_53 ;
return;
}
V_25 -> V_42 = F_16 ( & V_77 [ V_83 ] ) ;
V_25 -> V_44 = F_16 ( & V_77 [ V_83 + 2 ] ) ;
if ( V_25 -> V_45 )
F_17 ( V_25 -> V_42 , V_25 -> V_44 ) ;
V_25 -> V_81 = V_77 [ V_84 ] & 0x03 ;
V_25 -> V_35 = V_77 [ V_85 ] & 0x0f ;
if ( ! V_25 -> V_42 || ! V_25 -> V_44 || ! V_25 -> V_35 ) {
F_12 ( & V_25 -> V_2 -> V_33 ,
L_10 ) ;
V_25 -> V_42 = V_79 ;
V_25 -> V_44 = V_80 ;
if ( V_25 -> V_45 )
F_17 ( V_25 -> V_42 , V_25 -> V_44 ) ;
V_25 -> V_35 = V_53 ;
}
if ( F_45 ( V_86 ) ) {
V_25 -> V_41 = true ;
V_25 -> V_43 = true ;
F_33 ( & V_25 -> V_2 -> V_33 ,
L_11 ) ;
}
}
static int F_46 ( struct V_24 * V_25 )
{
int error ;
T_2 V_4 [ 6 ] ;
char V_87 [ 5 ] ;
error = F_1 ( V_25 -> V_2 , V_88 , V_4 , sizeof( V_4 ) ) ;
if ( error ) {
F_12 ( & V_25 -> V_2 -> V_33 , L_12 , error ) ;
return error ;
}
memcpy ( V_87 , V_4 , 4 ) ;
V_87 [ 4 ] = 0 ;
if ( F_47 ( V_87 , 10 , & V_25 -> V_20 ) )
V_25 -> V_20 = 0x1001 ;
V_25 -> V_89 = F_16 ( & V_4 [ 4 ] ) ;
F_48 ( & V_25 -> V_2 -> V_33 , L_13 , V_25 -> V_20 ,
V_25 -> V_89 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_90 = 0 ;
int error ;
T_2 V_91 ;
while ( V_90 ++ < 2 ) {
error = F_1 ( V_2 , V_67 ,
& V_91 , 1 ) ;
if ( ! error )
return 0 ;
F_12 ( & V_2 -> V_33 , L_14 ,
V_90 , error ) ;
F_36 ( 20 ) ;
}
return error ;
}
static int F_50 ( struct V_24 * V_25 )
{
int error ;
V_25 -> V_46 = F_51 ( & V_25 -> V_2 -> V_33 ) ;
if ( ! V_25 -> V_46 ) {
F_12 ( & V_25 -> V_2 -> V_33 , L_15 ) ;
return - V_18 ;
}
F_52 ( V_25 -> V_46 , V_48 ,
0 , V_25 -> V_42 , 0 , 0 ) ;
F_52 ( V_25 -> V_46 , V_49 ,
0 , V_25 -> V_44 , 0 , 0 ) ;
F_52 ( V_25 -> V_46 , V_51 , 0 , 255 , 0 , 0 ) ;
F_52 ( V_25 -> V_46 , V_50 , 0 , 255 , 0 , 0 ) ;
F_53 ( V_25 -> V_46 , V_25 -> V_35 ,
V_92 | V_93 ) ;
V_25 -> V_46 -> V_60 = L_16 ;
V_25 -> V_46 -> V_94 = L_17 ;
V_25 -> V_46 -> V_20 . V_95 = V_96 ;
V_25 -> V_46 -> V_20 . V_97 = 0x0416 ;
V_25 -> V_46 -> V_20 . V_98 = V_25 -> V_20 ;
V_25 -> V_46 -> V_20 . V_89 = V_25 -> V_89 ;
F_54 ( V_25 -> V_46 , V_99 , V_55 ) ;
error = F_55 ( V_25 -> V_46 ) ;
if ( error ) {
F_12 ( & V_25 -> V_2 -> V_33 ,
L_18 , error ) ;
return error ;
}
return 0 ;
}
static int F_56 ( struct V_24 * V_25 )
{
int error ;
V_25 -> V_45 = F_57 ( & V_25 -> V_2 -> V_33 ,
L_19 ) ;
V_25 -> V_41 = F_57 ( & V_25 -> V_2 -> V_33 ,
L_20 ) ;
V_25 -> V_43 = F_57 ( & V_25 -> V_2 -> V_33 ,
L_21 ) ;
F_43 ( V_25 ) ;
error = F_50 ( V_25 ) ;
if ( error )
return error ;
V_25 -> V_59 = V_100 [ V_25 -> V_81 ] | V_101 ;
error = F_29 ( V_25 ) ;
if ( error ) {
F_12 ( & V_25 -> V_2 -> V_33 , L_22 , error ) ;
return error ;
}
return 0 ;
}
static void F_58 ( const struct V_61 * V_62 , void * V_102 )
{
struct V_24 * V_25 = V_102 ;
int error ;
if ( V_62 ) {
error = F_32 ( V_25 , V_62 ) ;
if ( error )
goto V_103;
}
F_56 ( V_25 ) ;
V_103:
F_59 ( V_62 ) ;
F_60 ( & V_25 -> V_104 ) ;
}
static int F_61 ( struct V_1 * V_2 ,
const struct V_105 * V_20 )
{
struct V_24 * V_25 ;
int error ;
F_33 ( & V_2 -> V_33 , L_23 , V_2 -> V_11 ) ;
if ( ! F_62 ( V_2 -> V_13 , V_106 ) ) {
F_12 ( & V_2 -> V_33 , L_24 ) ;
return - V_107 ;
}
V_25 = F_63 ( & V_2 -> V_33 , sizeof( * V_25 ) , V_17 ) ;
if ( ! V_25 )
return - V_18 ;
V_25 -> V_2 = V_2 ;
F_64 ( V_2 , V_25 ) ;
F_65 ( & V_25 -> V_104 ) ;
error = F_39 ( V_25 ) ;
if ( error )
return error ;
if ( V_25 -> V_68 && V_25 -> V_69 ) {
error = F_38 ( V_25 ) ;
if ( error ) {
F_12 ( & V_2 -> V_33 , L_25 ) ;
return error ;
}
}
error = F_49 ( V_2 ) ;
if ( error ) {
F_12 ( & V_2 -> V_33 , L_26 , error ) ;
return error ;
}
error = F_46 ( V_25 ) ;
if ( error ) {
F_12 ( & V_2 -> V_33 , L_27 ) ;
return error ;
}
V_25 -> V_78 = F_9 ( V_25 -> V_20 ) ;
if ( V_25 -> V_68 && V_25 -> V_69 ) {
V_25 -> V_108 = F_66 ( & V_2 -> V_33 , V_17 ,
L_28 , V_25 -> V_20 ) ;
if ( ! V_25 -> V_108 )
return - V_18 ;
error = F_67 ( V_109 , true , V_25 -> V_108 ,
& V_2 -> V_33 , V_17 , V_25 ,
F_58 ) ;
if ( error ) {
F_12 ( & V_2 -> V_33 ,
L_29 ,
error ) ;
return error ;
}
return 0 ;
} else {
error = F_56 ( V_25 ) ;
if ( error )
return error ;
}
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_69 ( V_2 ) ;
if ( V_25 -> V_68 && V_25 -> V_69 )
F_70 ( & V_25 -> V_104 ) ;
return 0 ;
}
static int T_4 F_71 ( struct V_70 * V_33 )
{
struct V_1 * V_2 = F_72 ( V_33 ) ;
struct V_24 * V_25 = F_69 ( V_2 ) ;
int error ;
if ( ! V_25 -> V_68 || ! V_25 -> V_69 )
return 0 ;
F_70 ( & V_25 -> V_104 ) ;
F_27 ( V_25 ) ;
error = F_35 ( V_25 -> V_68 , 0 ) ;
if ( error ) {
F_29 ( V_25 ) ;
return error ;
}
F_13 ( 5000 , 6000 ) ;
error = F_8 ( V_25 -> V_2 , V_110 ,
V_111 ) ;
if ( error ) {
F_12 ( & V_25 -> V_2 -> V_33 , L_30 ) ;
F_37 ( V_25 -> V_68 ) ;
F_29 ( V_25 ) ;
return - V_112 ;
}
F_36 ( 58 ) ;
return 0 ;
}
static int T_4 F_73 ( struct V_70 * V_33 )
{
struct V_1 * V_2 = F_72 ( V_33 ) ;
struct V_24 * V_25 = F_69 ( V_2 ) ;
int error ;
if ( ! V_25 -> V_68 || ! V_25 -> V_69 )
return 0 ;
error = F_35 ( V_25 -> V_68 , 1 ) ;
if ( error )
return error ;
F_13 ( 2000 , 5000 ) ;
error = F_34 ( V_25 ) ;
if ( error )
return error ;
error = F_29 ( V_25 ) ;
if ( error )
return error ;
return 0 ;
}
