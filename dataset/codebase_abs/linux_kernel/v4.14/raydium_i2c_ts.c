static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , const void * V_4 , T_2 V_5 )
{
T_1 * V_6 ;
int V_7 = 0 ;
int V_8 ;
V_6 = F_2 ( V_5 + 1 , V_9 ) ;
if ( ! V_6 )
return - V_10 ;
V_6 [ 0 ] = V_3 ;
memcpy ( V_6 + 1 , V_4 , V_5 ) ;
do {
V_8 = F_3 ( V_2 , V_6 , V_5 + 1 ) ;
if ( F_4 ( V_8 == V_5 + 1 ) )
break;
F_5 ( 20 ) ;
} while ( ++ V_7 < V_11 );
F_6 ( V_6 ) ;
if ( F_7 ( V_8 != V_5 + 1 ) ) {
if ( V_8 >= 0 )
V_8 = - V_12 ;
F_8 ( & V_2 -> V_13 , L_1 , V_14 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
T_1 V_3 , void * V_4 , T_2 V_5 )
{
struct V_15 V_16 [] = {
{
. V_3 = V_2 -> V_3 ,
. V_5 = 1 ,
. V_6 = & V_3 ,
} ,
{
. V_3 = V_2 -> V_3 ,
. V_17 = V_18 ,
. V_5 = V_5 ,
. V_6 = V_4 ,
}
} ;
int V_8 ;
V_8 = F_10 ( V_2 -> V_19 , V_16 , F_11 ( V_16 ) ) ;
if ( F_7 ( V_8 != F_11 ( V_16 ) ) )
return V_8 < 0 ? V_8 : - V_12 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
T_3 V_3 , void * V_4 , T_2 V_5 )
{
T_4 V_20 ;
T_2 V_21 ;
int error ;
while ( V_5 ) {
V_21 = F_13 ( T_2 , V_5 , V_22 ) ;
V_20 = F_14 ( V_3 ) ;
error = F_1 ( V_2 , V_23 ,
& V_20 , sizeof( V_20 ) ) ;
if ( ! error )
error = F_9 ( V_2 , V_3 & 0xff ,
V_4 , V_21 ) ;
if ( error )
return error ;
V_5 -= V_21 ;
V_4 += V_21 ;
V_3 += V_21 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
T_3 V_3 , const void * V_4 , T_2 V_5 )
{
T_4 V_20 = F_14 ( V_3 ) ;
int error ;
error = F_1 ( V_2 , V_23 ,
& V_20 , sizeof( V_20 ) ) ;
if ( ! error )
error = F_1 ( V_2 , V_3 & 0xff , V_4 , V_5 ) ;
return error ;
}
static int F_16 ( struct V_1 * V_2 )
{
const T_1 V_24 = 0x01 ;
int error ;
error = F_15 ( V_2 , V_25 ,
& V_24 , sizeof( V_24 ) ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 , L_2 , error ) ;
return error ;
}
F_5 ( V_26 ) ;
return 0 ;
}
static int F_17 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_29 V_30 ;
T_5 V_31 ;
int error , V_32 ;
for ( V_32 = 0 ; V_32 < V_11 ; V_32 ++ ) {
error = F_9 ( V_2 , V_33 ,
& V_30 , sizeof( V_30 ) ) ;
if ( error )
continue;
if ( V_28 -> V_34 && V_28 -> V_35 != V_30 . V_35 ) {
F_18 ( & V_2 -> V_13 ,
L_3 ,
V_28 -> V_35 , V_30 . V_35 ) ;
} else {
V_28 -> V_35 = V_30 . V_35 ;
V_28 -> V_36 = V_28 -> V_35 - V_37 ;
}
V_28 -> V_38 = V_30 . V_39 ;
V_28 -> V_40 = F_19 ( V_30 . V_40 ) ;
F_20 ( & V_2 -> V_13 ,
L_4 ,
V_28 -> V_40 , V_28 -> V_36 , V_28 -> V_38 ) ;
error = F_9 ( V_2 , V_41 ,
& V_31 ,
sizeof( V_31 ) ) ;
if ( error )
continue;
error = F_12 ( V_2 ,
F_19 ( V_31 ) ,
& V_28 -> V_42 , sizeof( V_28 -> V_42 ) ) ;
if ( error )
continue;
return 0 ;
}
F_8 ( & V_2 -> V_13 , L_5 , error ) ;
return error ;
}
static int F_21 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
static const T_1 V_43 = 0x62 ;
static const T_1 V_44 = 0x66 ;
T_1 V_6 [ 4 ] ;
int error ;
error = F_9 ( V_2 , V_45 , V_6 , sizeof( V_6 ) ) ;
if ( ! error ) {
if ( V_6 [ 0 ] == V_43 )
V_28 -> V_46 = V_47 ;
else if ( V_6 [ 0 ] == V_44 )
V_28 -> V_46 = V_48 ;
return 0 ;
}
return error ;
}
static int F_22 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
int error , V_32 ;
for ( V_32 = 0 ; V_32 < V_11 ; V_32 ++ ) {
F_5 ( V_49 ) ;
error = F_21 ( V_28 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 ,
L_6 , error ) ;
continue;
}
if ( V_28 -> V_46 == V_47 ||
V_28 -> V_46 == V_48 ) {
break;
}
}
if ( error )
V_28 -> V_46 = V_47 ;
if ( V_28 -> V_46 == V_47 ) {
V_28 -> V_42 . V_50 = F_23 ( 0xffffffffUL ) ;
V_28 -> V_42 . V_51 = 0xff ;
V_28 -> V_42 . V_52 = 0xff ;
} else {
F_17 ( V_28 ) ;
}
return error ;
}
static int F_24 ( struct V_1 * V_2 ,
enum V_53 V_54 )
{
static const T_1 V_55 [] = { 0xFF , 0x39 , 0x30 , 0x30 , 0x54 } ;
T_1 V_56 [ sizeof( V_55 ) ] ;
T_1 V_57 ;
int error ;
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ ) {
switch ( V_54 ) {
case V_59 :
return 0 ;
case V_60 :
error = F_9 ( V_2 , V_61 ,
& V_56 [ 0 ] , 1 ) ;
if ( ! error && V_56 [ 0 ] == V_62 )
return 0 ;
break;
case V_63 :
error = F_9 ( V_2 , V_61 ,
V_56 , sizeof( V_56 ) ) ;
if ( ! error && ! memcmp ( V_56 , V_55 , sizeof( V_55 ) ) )
return 0 ;
break;
default:
F_8 ( & V_2 -> V_13 , L_7 ,
V_14 , V_54 ) ;
return - V_64 ;
}
F_5 ( 20 ) ;
}
return - V_65 ;
}
static int F_25 ( struct V_1 * V_2 ,
const void * V_4 , T_2 V_5 ,
enum V_53 V_54 )
{
int error ;
error = F_1 ( V_2 , V_66 , V_4 , V_5 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 , L_8 ,
error ) ;
return error ;
}
error = F_1 ( V_2 , V_67 , NULL , 0 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 , L_9 , error ) ;
return error ;
}
error = F_24 ( V_2 , V_54 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 , L_10 , error ) ;
return error ;
}
return 0 ;
}
static bool F_26 ( struct V_1 * V_2 )
{
static const T_1 V_68 [ 7 ] [ 6 ] = {
{ 0x08 , 0x0C , 0x09 , 0x00 , 0x50 , 0xD7 } ,
{ 0x08 , 0x04 , 0x09 , 0x00 , 0x50 , 0xA5 } ,
{ 0x08 , 0x04 , 0x09 , 0x00 , 0x50 , 0x00 } ,
{ 0x08 , 0x04 , 0x09 , 0x00 , 0x50 , 0xA5 } ,
{ 0x08 , 0x0C , 0x09 , 0x00 , 0x50 , 0x00 } ,
{ 0x06 , 0x01 , 0x00 , 0x00 , 0x00 , 0x00 } ,
{ 0x02 , 0xA2 , 0x00 , 0x00 , 0x00 , 0x00 } ,
} ;
int V_69 ;
int error ;
for ( V_69 = 0 ; V_69 < 7 ; V_69 ++ ) {
error = F_25 ( V_2 , V_68 [ V_69 ] , sizeof( V_68 [ V_69 ] ) ,
V_60 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 ,
L_11 ,
V_69 , error ) ;
return error ;
}
}
return 0 ;
}
static bool F_27 ( struct V_1 * V_2 )
{
static const T_1 V_68 [ 5 ] [ 11 ] = {
{ 0 , 0x09 , 0x71 , 0x0C , 0x09 , 0x00 , 0x50 , 0xD7 , 0 , 0 , 0 } ,
{ 0 , 0x09 , 0x71 , 0x04 , 0x09 , 0x00 , 0x50 , 0xA5 , 0 , 0 , 0 } ,
{ 0 , 0x09 , 0x71 , 0x04 , 0x09 , 0x00 , 0x50 , 0x00 , 0 , 0 , 0 } ,
{ 0 , 0x09 , 0x71 , 0x04 , 0x09 , 0x00 , 0x50 , 0xA5 , 0 , 0 , 0 } ,
{ 0 , 0x09 , 0x71 , 0x0C , 0x09 , 0x00 , 0x50 , 0x00 , 0 , 0 , 0 } ,
} ;
int V_69 ;
int error ;
for ( V_69 = 0 ; V_69 < 5 ; V_69 ++ ) {
error = F_25 ( V_2 , V_68 [ V_69 ] , sizeof( V_68 [ V_69 ] ) ,
V_59 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 ,
L_12 ,
V_69 , error ) ;
return error ;
}
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
static const T_1 V_68 [] = { 0x09 , 0x00 , 0x09 , 0x00 , 0x50 , 0x10 , 0x00 } ;
int error ;
error = F_25 ( V_2 , V_68 , sizeof( V_68 ) ,
V_63 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 , L_13 , error ) ;
return error ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
static const T_1 V_70 [] = { 0x00 , 0x01 , 0x52 } ;
int error ;
error = F_25 ( V_2 , V_70 , sizeof( V_70 ) ,
V_59 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 , L_14 , error ) ;
return error ;
}
F_5 ( V_49 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
static const T_1 V_71 [] = { 0x05 , 0x00 } ;
int error ;
error = F_25 ( V_2 , V_71 , sizeof( V_71 ) ,
V_59 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 , L_15 , error ) ;
return error ;
}
F_5 ( V_49 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
T_2 V_72 , T_6 V_73 )
{
T_1 V_74 [] = { 0x00 , 0x05 , 0x6D , 0x00 , 0x00 , 0x00 , 0x00 } ;
int error ;
F_32 ( V_72 , & V_74 [ 3 ] ) ;
F_32 ( V_73 , & V_74 [ 5 ] ) ;
error = F_25 ( V_2 ,
V_74 , sizeof( V_74 ) ,
V_59 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 , L_16 ,
error ) ;
return error ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
static const T_1 V_68 [] = { 0x0A , 0xAA } ;
int error ;
error = F_25 ( V_2 , V_68 , sizeof( V_68 ) ,
V_60 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 , L_17 ,
error ) ;
return error ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
T_6 V_75 , const void * V_4 , T_2 V_5 )
{
T_1 V_6 [ V_76 ] ;
T_2 V_21 ;
int error ;
int V_69 ;
F_35 ( ( V_77 % V_78 ) != 0 ) ;
for ( V_69 = 0 ; V_69 < V_77 / V_78 ; V_69 ++ ) {
V_6 [ V_79 ] = V_80 ;
V_6 [ V_81 ] = V_75 ? 0xff : 0 ;
V_6 [ V_82 ] = V_69 + 1 ;
V_21 = F_13 ( T_2 , V_5 , V_78 ) ;
memcpy ( & V_6 [ V_83 ] , V_4 , V_21 ) ;
if ( V_5 < V_78 )
memset ( & V_6 [ V_83 + V_21 ] , 0xff ,
V_78 - V_21 ) ;
error = F_25 ( V_2 , V_6 , V_76 ,
V_60 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 ,
L_18 ,
V_75 , V_69 , error ) ;
return error ;
}
V_4 += V_21 ;
V_5 -= V_21 ;
}
return error ;
}
static T_6 F_36 ( const T_1 * V_6 , T_6 V_5 )
{
T_6 V_73 = 0 ;
T_6 V_69 ;
for ( V_69 = 0 ; V_69 < V_5 ; V_69 ++ )
V_73 += V_6 [ V_69 ] ;
return V_73 ;
}
static int F_37 ( struct V_27 * V_28 ,
const struct V_84 * V_85 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
const void * V_4 ;
T_2 V_86 ;
T_2 V_5 ;
int V_87 ;
int V_69 ;
int error ;
T_6 V_88 ;
if ( V_85 -> V_89 == 0 || V_85 -> V_89 > V_90 ) {
F_8 ( & V_2 -> V_13 , L_19 ) ;
return - V_64 ;
}
error = F_21 ( V_28 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 , L_20 , error ) ;
return error ;
}
if ( V_28 -> V_46 == V_48 ) {
for ( V_69 = 0 ; V_69 < V_11 ; V_69 ++ ) {
error = F_29 ( V_2 ) ;
if ( ! error ) {
error = F_21 ( V_28 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 ,
L_21 ,
error ) ;
return error ;
}
if ( V_28 -> V_46 == V_47 )
break;
}
}
if ( V_28 -> V_46 == V_48 ) {
F_8 ( & V_2 -> V_13 ,
L_22 ,
error ) ;
return - V_12 ;
}
}
error = F_33 ( V_2 ) ;
if ( error )
return error ;
error = F_28 ( V_2 ) ;
if ( error )
return error ;
error = F_26 ( V_2 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 , L_23 , error ) ;
return error ;
}
F_5 ( V_49 ) ;
V_4 = V_85 -> V_4 ;
V_86 = V_85 -> V_89 ;
V_87 = 0 ;
while ( V_86 ) {
V_5 = F_13 ( T_2 , V_86 , V_77 ) ;
error = F_34 ( V_2 , V_87 ++ , V_4 , V_5 ) ;
if ( error )
return error ;
F_5 ( 20 ) ;
V_4 += V_5 ;
V_86 -= V_5 ;
}
error = F_30 ( V_2 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 ,
L_24 , error ) ;
return error ;
}
F_20 ( & V_2 -> V_13 , L_25 ) ;
F_5 ( V_49 ) ;
error = F_21 ( V_28 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 ,
L_26 ,
error ) ;
return error ;
}
if ( V_28 -> V_46 != V_48 ) {
F_8 ( & V_2 -> V_13 ,
L_27 ,
error ) ;
return - V_64 ;
}
error = F_27 ( V_2 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 , L_28 , error ) ;
return error ;
}
V_88 = F_36 ( V_85 -> V_4 , V_85 -> V_89 ) ;
error = F_31 ( V_2 , V_85 -> V_89 , V_88 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_38 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
const struct V_84 * V_85 = NULL ;
const char * V_91 = L_29 ;
int error ;
error = F_39 ( & V_85 , V_91 , & V_2 -> V_13 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 , L_30 , V_91 ) ;
return error ;
}
F_40 ( V_2 -> V_92 ) ;
error = F_37 ( V_28 , V_85 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 , L_31 , error ) ;
V_28 -> V_46 = V_47 ;
goto V_93;
}
error = F_22 ( V_28 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 ,
L_32 ,
error ) ;
V_28 -> V_46 = V_47 ;
goto V_93;
}
V_28 -> V_46 = V_48 ;
V_93:
F_41 ( V_2 -> V_92 ) ;
F_5 ( 100 ) ;
F_42 ( V_85 ) ;
return error ;
}
static void F_43 ( struct V_27 * V_28 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_28 -> V_36 / V_28 -> V_38 ; V_69 ++ ) {
T_1 * V_94 = & V_28 -> V_34 [ V_28 -> V_38 * V_69 ] ;
bool V_54 = V_94 [ V_95 ] ;
T_1 V_96 , V_97 ;
F_44 ( V_28 -> V_98 , V_69 ) ;
F_45 ( V_28 -> V_98 , V_99 , V_54 ) ;
if ( ! V_54 )
continue;
F_46 ( V_28 -> V_98 , V_100 ,
F_47 ( & V_94 [ V_101 ] ) ) ;
F_46 ( V_28 -> V_98 , V_102 ,
F_47 ( & V_94 [ V_103 ] ) ) ;
F_46 ( V_28 -> V_98 , V_104 ,
V_94 [ V_105 ] ) ;
V_96 = V_94 [ V_106 ] ;
V_97 = V_94 [ V_107 ] ;
F_46 ( V_28 -> V_98 , V_108 , F_48 ( V_96 , V_97 ) ) ;
F_46 ( V_28 -> V_98 , V_109 , F_49 ( V_96 , V_97 ) ) ;
}
F_50 ( V_28 -> V_98 ) ;
F_51 ( V_28 -> V_98 ) ;
}
static T_7 F_52 ( int V_92 , void * V_110 )
{
struct V_27 * V_28 = V_110 ;
int error ;
T_6 V_111 ;
T_6 V_112 ;
if ( V_28 -> V_46 != V_48 )
goto V_113;
error = F_12 ( V_28 -> V_2 , V_28 -> V_40 ,
V_28 -> V_34 , V_28 -> V_35 ) ;
if ( error )
goto V_113;
V_111 = F_47 ( & V_28 -> V_34 [ V_28 -> V_36 ] ) ;
V_112 = F_36 ( V_28 -> V_34 , V_28 -> V_36 ) ;
if ( F_7 ( V_111 != V_112 ) ) {
F_18 ( & V_28 -> V_2 -> V_13 ,
L_33 ,
V_14 , V_112 , V_111 ) ;
goto V_113;
}
F_43 ( V_28 ) ;
V_113:
return V_114 ;
}
static T_8 F_53 ( struct V_115 * V_13 ,
struct V_116 * V_117 , char * V_6 )
{
struct V_1 * V_2 = F_54 ( V_13 ) ;
struct V_27 * V_28 = F_55 ( V_2 ) ;
return sprintf ( V_6 , L_34 , V_28 -> V_42 . V_51 , V_28 -> V_42 . V_52 ) ;
}
static T_8 F_56 ( struct V_115 * V_13 ,
struct V_116 * V_117 , char * V_6 )
{
struct V_1 * V_2 = F_54 ( V_13 ) ;
struct V_27 * V_28 = F_55 ( V_2 ) ;
return sprintf ( V_6 , L_35 , F_19 ( V_28 -> V_42 . V_50 ) ) ;
}
static T_8 F_57 ( struct V_115 * V_13 ,
struct V_116 * V_117 ,
char * V_6 )
{
struct V_1 * V_2 = F_54 ( V_13 ) ;
struct V_27 * V_28 = F_55 ( V_2 ) ;
return sprintf ( V_6 , L_36 ,
V_28 -> V_46 == V_48 ?
L_37 : L_38 ) ;
}
static T_8 F_58 ( struct V_115 * V_13 ,
struct V_116 * V_117 ,
const char * V_6 , T_2 V_118 )
{
struct V_1 * V_2 = F_54 ( V_13 ) ;
struct V_27 * V_28 = F_55 ( V_2 ) ;
int error ;
error = F_59 ( & V_28 -> V_119 ) ;
if ( error )
return error ;
error = F_38 ( V_28 ) ;
F_60 ( & V_28 -> V_119 ) ;
return error ? : V_118 ;
}
static T_8 F_61 ( struct V_115 * V_13 ,
struct V_116 * V_117 ,
const char * V_6 , T_2 V_118 )
{
struct V_1 * V_2 = F_54 ( V_13 ) ;
struct V_27 * V_28 = F_55 ( V_2 ) ;
static const T_1 V_70 [] = { 0x00 , 0x01 , 0x9E } ;
int error ;
error = F_59 ( & V_28 -> V_119 ) ;
if ( error )
return error ;
error = F_25 ( V_2 , V_70 , sizeof( V_70 ) ,
V_60 ) ;
if ( error )
F_8 ( & V_2 -> V_13 , L_39 , error ) ;
F_60 ( & V_28 -> V_119 ) ;
return error ? : V_118 ;
}
static void F_62 ( void * V_120 )
{
struct V_27 * V_28 = V_120 ;
F_63 ( & V_28 -> V_2 -> V_13 . V_121 , & V_122 ) ;
}
static int F_64 ( struct V_27 * V_28 )
{
int error ;
if ( ! V_28 -> V_123 )
return 0 ;
F_65 ( V_28 -> V_123 , 1 ) ;
error = F_66 ( V_28 -> V_124 ) ;
if ( error ) {
F_8 ( & V_28 -> V_2 -> V_13 ,
L_40 , error ) ;
goto V_125;
}
error = F_66 ( V_28 -> V_126 ) ;
if ( error ) {
F_67 ( V_28 -> V_124 ) ;
F_8 ( & V_28 -> V_2 -> V_13 ,
L_41 , error ) ;
goto V_125;
}
F_68 ( V_127 ) ;
V_125:
F_65 ( V_28 -> V_123 , 0 ) ;
if ( error )
return error ;
F_5 ( V_26 ) ;
return 0 ;
}
static void F_69 ( void * V_120 )
{
struct V_27 * V_28 = V_120 ;
if ( V_28 -> V_123 ) {
F_65 ( V_28 -> V_123 , 1 ) ;
F_67 ( V_28 -> V_126 ) ;
F_67 ( V_28 -> V_124 ) ;
}
}
static int F_70 ( struct V_1 * V_2 ,
const struct V_128 * V_129 )
{
union V_130 V_131 ;
struct V_27 * V_28 ;
int error ;
if ( ! F_71 ( V_2 -> V_19 , V_132 ) ) {
F_8 ( & V_2 -> V_13 ,
L_42 ) ;
return - V_133 ;
}
V_28 = F_72 ( & V_2 -> V_13 , sizeof( * V_28 ) , V_9 ) ;
if ( ! V_28 )
return - V_10 ;
F_73 ( & V_28 -> V_119 ) ;
V_28 -> V_2 = V_2 ;
F_74 ( V_2 , V_28 ) ;
V_28 -> V_124 = F_75 ( & V_2 -> V_13 , L_43 ) ;
if ( F_76 ( V_28 -> V_124 ) ) {
error = F_77 ( V_28 -> V_124 ) ;
if ( error != - V_134 )
F_8 ( & V_2 -> V_13 ,
L_44 , error ) ;
return error ;
}
V_28 -> V_126 = F_75 ( & V_2 -> V_13 , L_45 ) ;
if ( F_76 ( V_28 -> V_126 ) ) {
error = F_77 ( V_28 -> V_126 ) ;
if ( error != - V_134 )
F_8 ( & V_2 -> V_13 ,
L_46 , error ) ;
return error ;
}
V_28 -> V_123 = F_78 ( & V_2 -> V_13 , L_47 ,
V_135 ) ;
if ( F_76 ( V_28 -> V_123 ) ) {
error = F_77 ( V_28 -> V_123 ) ;
if ( error != - V_134 )
F_8 ( & V_2 -> V_13 ,
L_48 , error ) ;
return error ;
}
error = F_64 ( V_28 ) ;
if ( error )
return error ;
error = F_79 ( & V_2 -> V_13 , F_69 , V_28 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 ,
L_49 , error ) ;
F_69 ( V_28 ) ;
return error ;
}
if ( F_80 ( V_2 -> V_19 , V_2 -> V_3 , 0 ,
V_136 , 0 , V_137 , & V_131 ) < 0 ) {
F_8 ( & V_2 -> V_13 , L_50 ) ;
return - V_133 ;
}
error = F_22 ( V_28 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 , L_51 , error ) ;
return error ;
}
V_28 -> V_34 = F_81 ( & V_2 -> V_13 ,
V_28 -> V_35 , V_9 ) ;
if ( ! V_28 -> V_34 )
return - V_10 ;
V_28 -> V_98 = F_82 ( & V_2 -> V_13 ) ;
if ( ! V_28 -> V_98 ) {
F_8 ( & V_2 -> V_13 , L_52 ) ;
return - V_10 ;
}
V_28 -> V_98 -> V_138 = L_53 ;
V_28 -> V_98 -> V_129 . V_139 = V_140 ;
F_83 ( V_28 -> V_98 , V_100 ,
0 , F_84 ( V_28 -> V_42 . V_141 ) , 0 , 0 ) ;
F_83 ( V_28 -> V_98 , V_102 ,
0 , F_84 ( V_28 -> V_42 . V_142 ) , 0 , 0 ) ;
F_85 ( V_28 -> V_98 , V_100 , V_28 -> V_42 . V_143 ) ;
F_85 ( V_28 -> V_98 , V_102 , V_28 -> V_42 . V_144 ) ;
F_83 ( V_28 -> V_98 , V_108 , 0 , 255 , 0 , 0 ) ;
F_83 ( V_28 -> V_98 , V_104 , 0 , 255 , 0 , 0 ) ;
error = F_86 ( V_28 -> V_98 , V_145 ,
V_146 | V_147 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 ,
L_54 , error ) ;
return error ;
}
error = F_87 ( V_28 -> V_98 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 ,
L_55 , error ) ;
return error ;
}
error = F_88 ( & V_2 -> V_13 , V_2 -> V_92 ,
NULL , F_52 ,
V_148 , V_2 -> V_138 , V_28 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 , L_56 ) ;
return error ;
}
error = F_89 ( & V_2 -> V_13 . V_121 ,
& V_122 ) ;
if ( error ) {
F_8 ( & V_2 -> V_13 , L_57 ,
error ) ;
return error ;
}
error = F_79 ( & V_2 -> V_13 ,
F_62 , V_28 ) ;
if ( error ) {
F_62 ( V_28 ) ;
F_8 ( & V_2 -> V_13 ,
L_58 , error ) ;
return error ;
}
return 0 ;
}
static void T_9 F_90 ( struct V_1 * V_2 )
{
static const T_1 V_149 [] = { 0x5A , 0xff , 0x00 , 0x0f } ;
int error ;
error = F_1 ( V_2 , V_150 ,
V_149 , sizeof( V_149 ) ) ;
if ( error )
F_8 ( & V_2 -> V_13 ,
L_59 , error ) ;
}
static int T_9 F_91 ( struct V_115 * V_13 )
{
struct V_1 * V_2 = F_54 ( V_13 ) ;
struct V_27 * V_28 = F_55 ( V_2 ) ;
if ( V_28 -> V_46 != V_48 )
return - V_151 ;
F_40 ( V_2 -> V_92 ) ;
if ( F_92 ( V_13 ) ) {
F_90 ( V_2 ) ;
V_28 -> V_152 = ( F_93 ( V_2 -> V_92 ) == 0 ) ;
} else {
F_69 ( V_28 ) ;
}
return 0 ;
}
static int T_9 F_94 ( struct V_115 * V_13 )
{
struct V_1 * V_2 = F_54 ( V_13 ) ;
struct V_27 * V_28 = F_55 ( V_2 ) ;
if ( F_92 ( V_13 ) ) {
if ( V_28 -> V_152 )
F_95 ( V_2 -> V_92 ) ;
F_16 ( V_2 ) ;
} else {
F_64 ( V_28 ) ;
F_22 ( V_28 ) ;
}
F_41 ( V_2 -> V_92 ) ;
return 0 ;
}
