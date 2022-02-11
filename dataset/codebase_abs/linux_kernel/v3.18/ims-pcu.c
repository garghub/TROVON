static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < 32 ; V_8 ++ ) {
unsigned short V_9 = V_5 -> V_10 [ V_8 ] ;
if ( V_9 != V_11 )
F_2 ( V_7 , V_9 , V_3 & ( 1UL << V_8 ) ) ;
}
F_3 ( V_7 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
const unsigned short * V_10 ,
T_2 V_12 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
struct V_6 * V_7 ;
int V_8 ;
int error ;
V_7 = F_5 () ;
if ( ! V_7 ) {
F_6 ( V_2 -> V_13 ,
L_1 ) ;
return - V_14 ;
}
snprintf ( V_5 -> V_15 , sizeof( V_5 -> V_15 ) ,
L_2 , V_2 -> V_16 ) ;
F_7 ( V_2 -> V_17 , V_5 -> V_18 , sizeof( V_5 -> V_18 ) ) ;
F_8 ( V_5 -> V_18 , L_3 , sizeof( V_5 -> V_18 ) ) ;
memcpy ( V_5 -> V_10 , V_10 , sizeof( * V_10 ) * V_12 ) ;
V_7 -> V_15 = V_5 -> V_15 ;
V_7 -> V_18 = V_5 -> V_18 ;
F_9 ( V_2 -> V_17 , & V_7 -> V_19 ) ;
V_7 -> V_13 . V_20 = & V_2 -> V_21 -> V_13 ;
V_7 -> V_9 = V_5 -> V_10 ;
V_7 -> V_22 = F_10 ( V_5 -> V_10 ) ;
V_7 -> V_23 = sizeof( V_5 -> V_10 [ 0 ] ) ;
F_11 ( V_24 , V_7 -> V_25 ) ;
for ( V_8 = 0 ; V_8 < V_26 ; V_8 ++ )
F_11 ( V_5 -> V_10 [ V_8 ] , V_7 -> V_27 ) ;
F_12 ( V_11 , V_7 -> V_27 ) ;
error = F_13 ( V_7 ) ;
if ( error ) {
F_6 ( V_2 -> V_13 ,
L_4 ,
error ) ;
F_14 ( V_7 ) ;
return error ;
}
V_5 -> V_7 = V_7 ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
F_16 ( V_5 -> V_7 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_28 * V_29 = V_2 -> V_29 ;
struct V_6 * V_7 = V_29 -> V_7 ;
int V_30 , V_31 ;
V_30 = ! ! ( V_3 & ( 1 << 14 ) ) - ! ! ( V_3 & ( 1 << 13 ) ) ;
V_31 = ! ! ( V_3 & ( 1 << 12 ) ) - ! ! ( V_3 & ( 1 << 11 ) ) ;
F_18 ( V_7 , V_32 , V_30 ) ;
F_18 ( V_7 , V_33 , V_31 ) ;
F_2 ( V_7 , V_34 , V_3 & ( 1 << 7 ) ) ;
F_2 ( V_7 , V_35 , V_3 & ( 1 << 8 ) ) ;
F_2 ( V_7 , V_36 , V_3 & ( 1 << 9 ) ) ;
F_2 ( V_7 , V_37 , V_3 & ( 1 << 10 ) ) ;
F_2 ( V_7 , V_38 , V_3 & ( 1 << 15 ) ) ;
F_2 ( V_7 , V_39 , V_3 & ( 1 << 16 ) ) ;
F_3 ( V_7 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_28 * V_29 ;
struct V_6 * V_7 ;
int error ;
V_29 = F_20 ( sizeof( struct V_28 ) , V_40 ) ;
V_7 = F_5 () ;
if ( ! V_29 || ! V_7 ) {
F_6 ( V_2 -> V_13 ,
L_5 ) ;
error = - V_14 ;
goto V_41;
}
V_29 -> V_7 = V_7 ;
snprintf ( V_29 -> V_15 , sizeof( V_29 -> V_15 ) ,
L_6 , V_2 -> V_16 ) ;
F_7 ( V_2 -> V_17 , V_29 -> V_18 , sizeof( V_29 -> V_18 ) ) ;
F_8 ( V_29 -> V_18 , L_7 , sizeof( V_29 -> V_18 ) ) ;
V_7 -> V_15 = V_29 -> V_15 ;
V_7 -> V_18 = V_29 -> V_18 ;
F_9 ( V_2 -> V_17 , & V_7 -> V_19 ) ;
V_7 -> V_13 . V_20 = & V_2 -> V_21 -> V_13 ;
F_11 ( V_24 , V_7 -> V_25 ) ;
F_11 ( V_34 , V_7 -> V_27 ) ;
F_11 ( V_35 , V_7 -> V_27 ) ;
F_11 ( V_36 , V_7 -> V_27 ) ;
F_11 ( V_37 , V_7 -> V_27 ) ;
F_11 ( V_38 , V_7 -> V_27 ) ;
F_11 ( V_39 , V_7 -> V_27 ) ;
F_11 ( V_42 , V_7 -> V_25 ) ;
F_21 ( V_7 , V_32 , - 1 , 1 , 0 , 0 ) ;
F_21 ( V_7 , V_33 , - 1 , 1 , 0 , 0 ) ;
error = F_13 ( V_7 ) ;
if ( error ) {
F_6 ( V_2 -> V_13 ,
L_8 ,
error ) ;
goto V_41;
}
V_2 -> V_29 = V_29 ;
return 0 ;
V_41:
F_14 ( V_7 ) ;
F_22 ( V_29 ) ;
return - V_14 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_29 ;
F_16 ( V_29 -> V_7 ) ;
F_22 ( V_29 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_1 V_3 = F_25 ( & V_2 -> V_43 [ 3 ] ) ;
F_1 ( V_2 , V_3 & ~ V_44 ) ;
if ( V_2 -> V_29 )
F_17 ( V_2 , V_3 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_43 [ 0 ] ) {
case V_45 :
if ( F_27 ( V_2 -> V_46 ) )
F_24 ( V_2 ) ;
break;
default:
if ( V_2 -> V_43 [ 0 ] == V_2 -> V_47 &&
V_2 -> V_43 [ 1 ] == V_2 -> V_48 - 1 ) {
memcpy ( V_2 -> V_49 , V_2 -> V_43 , V_2 -> V_50 ) ;
V_2 -> V_51 = V_2 -> V_50 ;
F_28 ( & V_2 -> V_52 ) ;
}
break;
}
}
static void F_29 ( struct V_1 * V_2 , struct V_53 * V_53 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_53 -> V_54 ; V_8 ++ ) {
T_3 V_3 = V_2 -> V_55 [ V_8 ] ;
if ( ! V_2 -> V_56 && V_3 != V_57 )
continue;
if ( V_2 -> V_58 ) {
V_2 -> V_58 = false ;
V_2 -> V_43 [ V_2 -> V_50 ++ ] = V_3 ;
V_2 -> V_59 += V_3 ;
continue;
}
switch ( V_3 ) {
case V_57 :
if ( V_2 -> V_56 )
F_30 ( V_2 -> V_13 ,
L_9 ,
V_2 -> V_50 ) ;
V_2 -> V_56 = true ;
V_2 -> V_58 = false ;
V_2 -> V_50 = 0 ;
V_2 -> V_59 = 0 ;
break;
case V_60 :
V_2 -> V_58 = true ;
break;
case V_61 :
if ( V_2 -> V_50 < V_62 ) {
F_30 ( V_2 -> V_13 ,
L_10 ,
V_2 -> V_50 ) ;
} else if ( V_2 -> V_59 != 0 ) {
F_30 ( V_2 -> V_13 ,
L_11 ,
V_2 -> V_50 ) ;
} else {
F_26 ( V_2 ) ;
}
V_2 -> V_56 = false ;
V_2 -> V_58 = false ;
V_2 -> V_50 = 0 ;
break;
default:
V_2 -> V_43 [ V_2 -> V_50 ++ ] = V_3 ;
V_2 -> V_59 += V_3 ;
break;
}
}
}
static bool F_31 ( T_3 V_63 )
{
return V_63 == V_57 ||
V_63 == V_61 ||
V_63 == V_60 ;
}
static int F_32 ( struct V_1 * V_2 ,
T_3 V_64 , int V_65 , int V_66 )
{
int error ;
error = F_33 ( V_2 -> V_17 ,
F_34 ( V_2 -> V_17 ,
V_2 -> V_67 -> V_68 ) ,
V_2 -> V_69 , V_66 ,
NULL , V_70 ) ;
if ( error < 0 ) {
F_35 ( V_2 -> V_13 ,
L_12 ,
V_64 , V_65 , error ) ;
return error ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
T_3 V_64 , const T_3 * V_3 , int V_66 )
{
int V_71 = 0 ;
int V_65 = 0 ;
int V_72 ;
int V_8 ;
int error ;
T_3 V_73 = 0 ;
T_3 V_48 ;
V_2 -> V_69 [ V_71 ++ ] = V_57 ;
V_2 -> V_69 [ V_71 ++ ] = V_64 ;
V_73 += V_64 ;
V_48 = V_2 -> V_48 ++ ;
if ( V_48 == 0xff )
V_48 = V_2 -> V_48 ++ ;
if ( F_31 ( V_48 ) )
V_2 -> V_69 [ V_71 ++ ] = V_60 ;
V_2 -> V_69 [ V_71 ++ ] = V_48 ;
V_73 += V_48 ;
for ( V_8 = 0 ; V_8 < V_66 ; V_8 ++ ) {
V_72 = F_31 ( V_3 [ V_8 ] ) ? 2 : 1 ;
if ( V_71 + V_72 >= V_2 -> V_74 ) {
error = F_32 ( V_2 , V_64 ,
++ V_65 , V_71 ) ;
if ( error )
return error ;
V_71 = 0 ;
}
if ( V_72 == 2 )
V_2 -> V_69 [ V_71 ++ ] = V_60 ;
V_2 -> V_69 [ V_71 ++ ] = V_3 [ V_8 ] ;
V_73 += V_3 [ V_8 ] ;
}
V_73 = 1 + ~ V_73 ;
V_72 = F_31 ( V_73 ) ? 3 : 2 ;
if ( V_71 + V_72 >= V_2 -> V_74 ) {
error = F_32 ( V_2 , V_64 , ++ V_65 , V_71 ) ;
if ( error )
return error ;
V_71 = 0 ;
}
if ( V_72 == 3 )
V_2 -> V_69 [ V_71 ++ ] = V_60 ;
V_2 -> V_69 [ V_71 ++ ] = V_73 ;
V_2 -> V_69 [ V_71 ++ ] = V_61 ;
return F_32 ( V_2 , V_64 , ++ V_65 , V_71 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
T_3 V_64 , const void * V_3 , T_2 V_66 ,
T_3 V_47 , int V_75 )
{
int error ;
V_2 -> V_47 = V_47 ;
F_38 ( & V_2 -> V_52 ) ;
error = F_36 ( V_2 , V_64 , V_3 , V_66 ) ;
if ( error )
return error ;
if ( V_47 &&
! F_39 ( & V_2 -> V_52 ,
F_40 ( V_75 ) ) ) {
F_35 ( V_2 -> V_13 , L_13 , V_64 ) ;
return - V_76 ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
T_3 V_64 , const void * V_3 , T_2 V_66 ,
T_3 V_47 , int V_75 )
{
int error ;
V_2 -> V_49 [ 0 ] = V_64 ;
if ( V_3 )
memcpy ( & V_2 -> V_49 [ 1 ] , V_3 , V_66 ) ;
error = F_37 ( V_2 ,
V_77 , V_2 -> V_49 , V_66 + 1 ,
V_47 ? V_78 : 0 ,
V_75 ) ;
if ( error ) {
F_6 ( V_2 -> V_13 ,
L_14 ,
V_2 -> V_49 [ 0 ] , error ) ;
return error ;
}
if ( V_47 && V_2 -> V_49 [ 2 ] != V_47 ) {
F_6 ( V_2 -> V_13 ,
L_15 ,
V_2 -> V_49 [ 2 ] , V_47 ) ;
return - V_79 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int error ;
error = F_43 ( V_2 , V_80 ) ;
if ( error ) {
F_6 ( V_2 -> V_13 ,
L_16 , error ) ;
return error ;
}
memcpy ( V_2 -> V_81 ,
& V_2 -> V_49 [ V_82 ] ,
sizeof( V_2 -> V_81 ) ) ;
memcpy ( V_2 -> V_83 ,
& V_2 -> V_49 [ V_84 ] ,
sizeof( V_2 -> V_83 ) ) ;
memcpy ( V_2 -> V_85 ,
& V_2 -> V_49 [ V_86 ] ,
sizeof( V_2 -> V_85 ) ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int error ;
memcpy ( & V_2 -> V_49 [ V_82 ] ,
V_2 -> V_81 , sizeof( V_2 -> V_81 ) ) ;
memcpy ( & V_2 -> V_49 [ V_84 ] ,
V_2 -> V_83 , sizeof( V_2 -> V_83 ) ) ;
memcpy ( & V_2 -> V_49 [ V_86 ] ,
V_2 -> V_85 , sizeof( V_2 -> V_85 ) ) ;
error = F_45 ( V_2 , V_87 ,
& V_2 -> V_49 [ V_88 ] ,
V_89 ) ;
if ( error ) {
F_6 ( V_2 -> V_13 ,
L_17 ,
error ) ;
return error ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
int error ;
error = F_45 ( V_2 , V_90 , NULL , 0 ) ;
if ( error ) {
F_6 ( V_2 -> V_13 ,
L_18 ,
error ) ;
return error ;
}
return 0 ;
}
static unsigned int F_47 ( const struct V_91 * V_92 )
{
const struct V_93 * V_94 = ( const struct V_93 * ) V_92 -> V_3 ;
unsigned int V_71 = 0 ;
while ( V_94 ) {
V_71 ++ ;
V_94 = F_48 ( V_94 ) ;
}
return V_71 ;
}
static int F_49 ( struct V_1 * V_2 ,
T_1 V_95 , T_3 V_66 , const T_3 * V_3 )
{
struct V_96 * V_97 ;
int error ;
V_97 = ( void * ) & V_2 -> V_49 [ 1 ] ;
F_50 ( V_95 , & V_97 -> V_95 ) ;
V_97 -> V_66 = V_66 ;
error = F_51 ( V_2 , V_98 , NULL , 5 ,
V_99 ) ;
if ( error ) {
F_6 ( V_2 -> V_13 ,
L_19 ,
V_95 , V_66 , error ) ;
return error ;
}
V_97 = ( void * ) & V_2 -> V_49 [ V_100 ] ;
if ( F_52 ( & V_97 -> V_95 ) != V_95 ||
V_97 -> V_66 != V_66 ) {
F_6 ( V_2 -> V_13 ,
L_20 ,
V_95 , F_52 ( & V_97 -> V_95 ) ,
V_66 , V_97 -> V_66 ) ;
return - V_79 ;
}
if ( memcmp ( V_97 -> V_3 , V_3 , V_66 ) ) {
F_6 ( V_2 -> V_13 ,
L_21 ,
V_95 , V_66 ) ;
return - V_79 ;
}
return 0 ;
}
static int F_53 ( struct V_1 * V_2 ,
const struct V_91 * V_92 ,
unsigned int V_101 )
{
const struct V_93 * V_94 = ( const struct V_93 * ) V_92 -> V_3 ;
struct V_96 * V_97 ;
unsigned int V_71 = 0 ;
T_1 V_95 ;
T_3 V_66 ;
int error ;
error = F_51 ( V_2 , V_102 , NULL , 0 , 2000 ) ;
if ( error ) {
F_6 ( V_2 -> V_13 ,
L_22 ,
error ) ;
return error ;
}
while ( V_94 ) {
V_95 = F_54 ( V_94 -> V_95 ) / 2 ;
V_66 = F_55 ( V_94 -> V_66 ) ;
V_97 = ( void * ) & V_2 -> V_49 [ 1 ] ;
F_50 ( V_95 , & V_97 -> V_95 ) ;
V_97 -> V_66 = V_66 ;
memcpy ( V_97 -> V_3 , V_94 -> V_3 , V_66 ) ;
error = F_51 ( V_2 , V_103 ,
NULL , V_66 + 5 ,
V_99 ) ;
if ( error ) {
F_6 ( V_2 -> V_13 ,
L_23 ,
V_95 , V_66 , error ) ;
return error ;
}
if ( V_95 >= V_2 -> V_104 && V_95 < V_2 -> V_105 ) {
error = F_49 ( V_2 , V_95 , V_66 , V_94 -> V_3 ) ;
if ( error )
return error ;
}
V_71 ++ ;
V_2 -> V_106 = ( V_71 * 100 ) / V_101 ;
V_94 = F_48 ( V_94 ) ;
}
error = F_51 ( V_2 , V_107 ,
NULL , 0 , 2000 ) ;
if ( error )
F_6 ( V_2 -> V_13 ,
L_24 ,
error ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
const struct V_91 * V_92 )
{
unsigned int V_101 ;
int V_108 ;
F_57 ( V_2 -> V_13 , L_25 ,
V_109 , V_92 -> V_110 ) ;
V_101 = F_47 ( V_92 ) ;
V_108 = F_53 ( V_2 , V_92 , V_101 ) ;
if ( V_108 )
goto V_111;
V_108 = F_51 ( V_2 , V_112 , NULL , 0 , 0 ) ;
if ( V_108 )
F_6 ( V_2 -> V_13 ,
L_26 ,
V_108 ) ;
V_111:
V_2 -> V_106 = V_108 ;
F_58 ( & V_2 -> V_13 -> V_113 , NULL , L_27 ) ;
return V_108 ;
}
static void F_59 ( const struct V_91 * V_92 ,
void * V_114 )
{
struct V_1 * V_2 = V_114 ;
int error ;
if ( ! V_92 ) {
F_6 ( V_2 -> V_13 , L_28 ,
V_109 ) ;
goto V_111;
}
error = F_60 ( V_92 ) ;
if ( error ) {
F_6 ( V_2 -> V_13 , L_29 ,
V_109 ) ;
goto V_111;
}
F_61 ( & V_2 -> V_115 ) ;
F_56 ( V_2 , V_92 ) ;
F_62 ( & V_2 -> V_115 ) ;
F_63 ( V_92 ) ;
V_111:
F_28 ( & V_2 -> V_116 ) ;
}
static void F_64 ( struct V_117 * V_118 )
{
struct V_119 * V_120 =
F_65 ( V_118 , struct V_119 , V_118 ) ;
struct V_1 * V_2 =
F_65 ( V_120 , struct V_1 , V_120 ) ;
int V_121 = V_120 -> V_121 ;
T_4 V_122 = F_66 ( V_121 ) ;
int error ;
F_61 ( & V_2 -> V_115 ) ;
error = F_45 ( V_2 , V_123 ,
& V_122 , sizeof( V_122 ) ) ;
if ( error && error != - V_124 )
F_30 ( V_2 -> V_13 ,
L_30 ,
V_121 , error ) ;
F_62 ( & V_2 -> V_115 ) ;
}
static void F_67 ( struct V_125 * V_126 ,
enum V_127 V_128 )
{
struct V_119 * V_120 =
F_65 ( V_126 , struct V_119 , V_126 ) ;
V_120 -> V_121 = V_128 ;
F_68 ( & V_120 -> V_118 ) ;
}
static enum V_127
F_69 ( struct V_125 * V_126 )
{
struct V_119 * V_120 =
F_65 ( V_126 , struct V_119 , V_126 ) ;
struct V_1 * V_2 =
F_65 ( V_120 , struct V_1 , V_120 ) ;
int V_129 ;
int error ;
F_61 ( & V_2 -> V_115 ) ;
error = F_43 ( V_2 , V_130 ) ;
if ( error ) {
F_30 ( V_2 -> V_13 ,
L_31 ,
error ) ;
V_129 = V_131 ;
} else {
V_129 =
F_70 ( & V_2 -> V_49 [ V_88 ] ) ;
}
F_62 ( & V_2 -> V_115 ) ;
return V_129 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_119 * V_120 = & V_2 -> V_120 ;
int error ;
F_72 ( & V_120 -> V_118 , F_64 ) ;
snprintf ( V_120 -> V_15 , sizeof( V_120 -> V_15 ) ,
L_32 , V_2 -> V_16 ) ;
V_120 -> V_126 . V_15 = V_120 -> V_15 ;
V_120 -> V_126 . V_132 = V_133 ;
V_120 -> V_126 . V_134 = F_69 ;
V_120 -> V_126 . V_135 = F_67 ;
error = F_73 ( V_2 -> V_13 , & V_120 -> V_126 ) ;
if ( error ) {
F_6 ( V_2 -> V_13 ,
L_33 ,
error ) ;
return error ;
}
return 0 ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_119 * V_120 = & V_2 -> V_120 ;
F_75 ( & V_120 -> V_126 ) ;
F_76 ( & V_120 -> V_118 ) ;
}
static T_5 F_77 ( struct V_136 * V_13 ,
struct V_137 * V_138 ,
char * V_139 )
{
struct V_140 * V_141 = F_78 ( V_13 ) ;
struct V_1 * V_2 = F_79 ( V_141 ) ;
struct V_142 * V_143 =
F_65 ( V_138 , struct V_142 , V_138 ) ;
char * V_144 = ( char * ) V_2 + V_143 -> V_145 ;
return F_80 ( V_139 , V_146 , L_34 , V_143 -> V_147 , V_144 ) ;
}
static T_5 F_81 ( struct V_136 * V_13 ,
struct V_137 * V_138 ,
const char * V_139 , T_2 V_71 )
{
struct V_140 * V_141 = F_78 ( V_13 ) ;
struct V_1 * V_2 = F_79 ( V_141 ) ;
struct V_142 * V_143 =
F_65 ( V_138 , struct V_142 , V_138 ) ;
char * V_144 = ( char * ) V_2 + V_143 -> V_145 ;
T_2 V_148 ;
int error ;
if ( V_71 > V_143 -> V_147 )
return - V_79 ;
V_148 = F_82 ( V_139 , V_143 -> V_147 ) ;
if ( V_148 > V_143 -> V_147 )
return - V_79 ;
error = F_83 ( & V_2 -> V_115 ) ;
if ( error )
return error ;
memset ( V_144 , 0 , V_143 -> V_147 ) ;
memcpy ( V_144 , V_139 , V_148 ) ;
error = F_44 ( V_2 ) ;
F_42 ( V_2 ) ;
F_62 ( & V_2 -> V_115 ) ;
return error < 0 ? error : V_71 ;
}
static T_5 F_84 ( struct V_136 * V_13 ,
struct V_137 * V_138 ,
const char * V_139 , T_2 V_71 )
{
static const T_3 V_149 = 1 ;
struct V_140 * V_141 = F_78 ( V_13 ) ;
struct V_1 * V_2 = F_79 ( V_141 ) ;
int V_128 ;
int error ;
error = F_85 ( V_139 , 0 , & V_128 ) ;
if ( error )
return error ;
if ( V_128 != 1 )
return - V_79 ;
F_57 ( V_2 -> V_13 , L_35 ) ;
error = F_45 ( V_2 , V_150 , & V_149 , 1 ) ;
if ( error ) {
F_57 ( V_2 -> V_13 ,
L_36 ,
error ) ;
return error ;
}
return V_71 ;
}
static T_5 F_86 ( struct V_136 * V_13 ,
struct V_137 * V_138 ,
const char * V_139 , T_2 V_71 )
{
struct V_140 * V_141 = F_78 ( V_13 ) ;
struct V_1 * V_2 = F_79 ( V_141 ) ;
const struct V_91 * V_92 = NULL ;
int V_128 ;
int error ;
error = F_85 ( V_139 , 0 , & V_128 ) ;
if ( error )
return error ;
if ( V_128 != 1 )
return - V_79 ;
error = F_83 ( & V_2 -> V_115 ) ;
if ( error )
return error ;
error = F_87 ( & V_92 , V_109 , V_2 -> V_13 ) ;
if ( error ) {
F_6 ( V_2 -> V_13 , L_37 ,
V_109 , error ) ;
goto V_111;
}
if ( V_2 -> V_151 )
error = F_56 ( V_2 , V_92 ) ;
else
error = F_46 ( V_2 ) ;
F_63 ( V_92 ) ;
V_111:
F_62 ( & V_2 -> V_115 ) ;
return error ? : V_71 ;
}
static T_5
F_88 ( struct V_136 * V_13 ,
struct V_137 * V_138 ,
char * V_139 )
{
struct V_140 * V_141 = F_78 ( V_13 ) ;
struct V_1 * V_2 = F_79 ( V_141 ) ;
return F_80 ( V_139 , V_146 , L_38 , V_2 -> V_106 ) ;
}
static T_6 F_89 ( struct V_152 * V_113 ,
struct V_153 * V_143 , int V_154 )
{
struct V_136 * V_13 = F_65 ( V_113 , struct V_136 , V_113 ) ;
struct V_140 * V_141 = F_78 ( V_13 ) ;
struct V_1 * V_2 = F_79 ( V_141 ) ;
T_6 V_155 = V_143 -> V_155 ;
if ( V_2 -> V_151 ) {
if ( V_143 != & V_156 . V_143 &&
V_143 != & V_157 . V_143 &&
V_143 != & V_158 . V_143 ) {
V_155 = 0 ;
}
} else {
if ( V_143 == & V_156 . V_143 )
V_155 = 0 ;
}
return V_155 ;
}
static int F_90 ( struct V_1 * V_2 , T_3 V_95 , T_3 * V_3 )
{
int error ;
T_7 V_159 ;
error = F_45 ( V_2 , V_160 ,
& V_95 , sizeof( V_95 ) ) ;
if ( error )
return error ;
V_159 = ( T_7 ) F_70 ( V_2 -> V_49 + V_161 ) ;
if ( V_159 < 0 )
return - V_162 ;
* V_3 = V_2 -> V_49 [ V_161 ] ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 , T_3 V_95 , T_3 V_3 )
{
T_3 V_163 [] = { V_95 , V_3 } ;
int error ;
T_7 V_159 ;
error = F_45 ( V_2 , V_164 ,
& V_163 , sizeof( V_163 ) ) ;
if ( error )
return error ;
V_159 = ( T_7 ) F_70 ( V_2 -> V_49 + V_161 ) ;
if ( V_159 < 0 )
return - V_162 ;
return 0 ;
}
static T_5 F_92 ( struct V_136 * V_13 ,
struct V_137 * V_138 ,
char * V_139 )
{
struct V_140 * V_141 = F_78 ( V_13 ) ;
struct V_1 * V_2 = F_79 ( V_141 ) ;
int error ;
T_3 V_3 ;
F_61 ( & V_2 -> V_115 ) ;
error = F_90 ( V_2 , V_2 -> V_165 , & V_3 ) ;
F_62 ( & V_2 -> V_115 ) ;
if ( error )
return error ;
return F_80 ( V_139 , V_146 , L_39 , V_3 ) ;
}
static T_5 F_93 ( struct V_136 * V_13 ,
struct V_137 * V_138 ,
const char * V_139 , T_2 V_71 )
{
struct V_140 * V_141 = F_78 ( V_13 ) ;
struct V_1 * V_2 = F_79 ( V_141 ) ;
int error ;
T_3 V_128 ;
error = F_94 ( V_139 , 0 , & V_128 ) ;
if ( error )
return error ;
F_61 ( & V_2 -> V_115 ) ;
error = F_91 ( V_2 , V_2 -> V_165 , V_128 ) ;
F_62 ( & V_2 -> V_115 ) ;
return error ? : V_71 ;
}
static T_5 F_95 ( struct V_136 * V_13 ,
struct V_137 * V_138 ,
char * V_139 )
{
struct V_140 * V_141 = F_78 ( V_13 ) ;
struct V_1 * V_2 = F_79 ( V_141 ) ;
int error ;
F_61 ( & V_2 -> V_115 ) ;
error = F_80 ( V_139 , V_146 , L_39 , V_2 -> V_165 ) ;
F_62 ( & V_2 -> V_115 ) ;
return error ;
}
static T_5 F_96 ( struct V_136 * V_13 ,
struct V_137 * V_138 ,
const char * V_139 , T_2 V_71 )
{
struct V_140 * V_141 = F_78 ( V_13 ) ;
struct V_1 * V_2 = F_79 ( V_141 ) ;
int error ;
T_3 V_128 ;
error = F_94 ( V_139 , 0 , & V_128 ) ;
if ( error )
return error ;
F_61 ( & V_2 -> V_115 ) ;
V_2 -> V_165 = V_128 ;
F_62 ( & V_2 -> V_115 ) ;
return V_71 ;
}
static T_5 F_97 ( struct V_136 * V_13 ,
struct V_137 * V_138 ,
char * V_139 )
{
struct V_140 * V_141 = F_78 ( V_13 ) ;
struct V_1 * V_2 = F_79 ( V_141 ) ;
struct V_166 * V_143 =
F_65 ( V_138 , struct V_166 , V_138 ) ;
int error ;
T_3 V_3 ;
F_61 ( & V_2 -> V_115 ) ;
error = F_90 ( V_2 , V_143 -> V_95 , & V_3 ) ;
F_62 ( & V_2 -> V_115 ) ;
if ( error )
return error ;
return F_80 ( V_139 , V_146 , L_38 , ! ! ( V_3 & ( 1 << V_143 -> V_167 ) ) ) ;
}
static T_5 F_98 ( struct V_136 * V_13 ,
struct V_137 * V_138 ,
const char * V_139 , T_2 V_71 )
{
struct V_140 * V_141 = F_78 ( V_13 ) ;
struct V_1 * V_2 = F_79 ( V_141 ) ;
struct V_166 * V_143 =
F_65 ( V_138 , struct V_166 , V_138 ) ;
int error ;
int V_128 ;
T_3 V_3 ;
error = F_85 ( V_139 , 0 , & V_128 ) ;
if ( error )
return error ;
if ( V_128 > 1 )
return - V_79 ;
F_61 ( & V_2 -> V_115 ) ;
error = F_90 ( V_2 , V_143 -> V_95 , & V_3 ) ;
if ( ! error ) {
if ( V_128 )
V_3 |= 1U << V_143 -> V_167 ;
else
V_3 &= ~ ( 1U << V_143 -> V_167 ) ;
error = F_91 ( V_2 , V_143 -> V_95 , V_3 ) ;
}
F_62 ( & V_2 -> V_115 ) ;
return error ? : V_71 ;
}
static void F_99 ( struct V_53 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_114 ;
int V_108 , V_168 ;
V_168 = V_53 -> V_168 ;
switch ( V_168 ) {
case 0 :
break;
case - V_169 :
case - V_170 :
case - V_171 :
F_35 ( V_2 -> V_13 , L_40 ,
V_172 , V_168 ) ;
return;
default:
F_35 ( V_2 -> V_13 , L_41 ,
V_172 , V_168 ) ;
goto exit;
}
F_35 ( V_2 -> V_13 , L_42 , V_172 ,
V_53 -> V_54 , V_53 -> V_54 , V_2 -> V_55 ) ;
if ( V_53 == V_2 -> V_173 )
F_29 ( V_2 , V_53 ) ;
exit:
V_108 = F_100 ( V_53 , V_174 ) ;
if ( V_108 && V_108 != - V_124 )
F_6 ( V_2 -> V_13 , L_43 ,
V_172 , V_108 ) ;
}
static int F_101 ( struct V_1 * V_2 )
{
int error ;
V_2 -> V_55 = F_102 ( V_2 -> V_17 , V_2 -> V_175 ,
V_40 , & V_2 -> V_176 ) ;
if ( ! V_2 -> V_55 ) {
F_6 ( V_2 -> V_13 ,
L_44 ) ;
return - V_14 ;
}
V_2 -> V_173 = F_103 ( 0 , V_40 ) ;
if ( ! V_2 -> V_173 ) {
F_6 ( V_2 -> V_13 , L_45 ) ;
error = - V_14 ;
goto V_177;
}
V_2 -> V_173 -> V_178 |= V_179 ;
V_2 -> V_173 -> V_180 = V_2 -> V_176 ;
F_104 ( V_2 -> V_173 , V_2 -> V_17 ,
F_105 ( V_2 -> V_17 ,
V_2 -> V_181 -> V_68 ) ,
V_2 -> V_55 , V_2 -> V_175 ,
F_99 , V_2 ) ;
V_2 -> V_69 = F_106 ( V_2 -> V_74 , V_40 ) ;
if ( ! V_2 -> V_69 ) {
F_6 ( V_2 -> V_13 , L_46 ) ;
error = - V_14 ;
goto V_182;
}
V_2 -> V_183 = F_102 ( V_2 -> V_17 , V_2 -> V_184 ,
V_40 , & V_2 -> V_185 ) ;
if ( ! V_2 -> V_183 ) {
F_6 ( V_2 -> V_13 ,
L_44 ) ;
error = - V_14 ;
goto V_186;
}
V_2 -> V_187 = F_103 ( 0 , V_40 ) ;
if ( ! V_2 -> V_187 ) {
F_6 ( V_2 -> V_13 , L_45 ) ;
error = - V_14 ;
goto V_188;
}
V_2 -> V_187 -> V_178 |= V_179 ;
V_2 -> V_187 -> V_180 = V_2 -> V_185 ;
F_107 ( V_2 -> V_187 , V_2 -> V_17 ,
F_108 ( V_2 -> V_17 ,
V_2 -> V_189 -> V_68 ) ,
V_2 -> V_183 , V_2 -> V_184 ,
F_99 , V_2 , V_2 -> V_189 -> V_190 ) ;
return 0 ;
V_188:
F_109 ( V_2 -> V_17 , V_2 -> V_184 ,
V_2 -> V_183 , V_2 -> V_185 ) ;
V_186:
F_22 ( V_2 -> V_69 ) ;
V_182:
F_110 ( V_2 -> V_173 ) ;
V_177:
F_109 ( V_2 -> V_17 , V_2 -> V_175 ,
V_2 -> V_55 , V_2 -> V_176 ) ;
return error ;
}
static void F_111 ( struct V_1 * V_2 )
{
F_112 ( V_2 -> V_173 ) ;
F_110 ( V_2 -> V_173 ) ;
F_109 ( V_2 -> V_17 , V_2 -> V_74 ,
V_2 -> V_55 , V_2 -> V_176 ) ;
F_22 ( V_2 -> V_69 ) ;
F_112 ( V_2 -> V_187 ) ;
F_110 ( V_2 -> V_187 ) ;
F_109 ( V_2 -> V_17 , V_2 -> V_184 ,
V_2 -> V_183 , V_2 -> V_185 ) ;
}
static const struct V_191 *
F_113 ( struct V_140 * V_141 )
{
const void * V_139 = V_141 -> V_192 -> V_193 ;
T_2 V_194 = V_141 -> V_192 -> V_195 ;
struct V_191 * V_196 ;
if ( ! V_139 ) {
F_6 ( & V_141 -> V_13 , L_47 ) ;
return NULL ;
}
if ( ! V_194 ) {
F_6 ( & V_141 -> V_13 , L_48 ) ;
return NULL ;
}
while ( V_194 > 0 ) {
V_196 = (struct V_191 * ) V_139 ;
if ( V_196 -> V_197 == V_198 &&
V_196 -> V_199 == V_200 ) {
F_35 ( & V_141 -> V_13 , L_49 ) ;
return V_196 ;
}
V_194 -= V_196 -> V_201 ;
V_139 += V_196 -> V_201 ;
}
F_6 ( & V_141 -> V_13 , L_50 ) ;
return NULL ;
}
static int F_114 ( struct V_140 * V_141 , struct V_1 * V_2 )
{
const struct V_191 * V_196 ;
struct V_202 * V_203 ;
V_196 = F_113 ( V_141 ) ;
if ( ! V_196 )
return - V_79 ;
V_2 -> V_21 = F_115 ( V_2 -> V_17 ,
V_196 -> V_204 ) ;
V_203 = V_2 -> V_21 -> V_205 ;
V_2 -> V_189 = & V_203 -> V_206 [ 0 ] . V_207 ;
V_2 -> V_184 = F_116 ( V_2 -> V_189 ) ;
V_2 -> V_208 = F_115 ( V_2 -> V_17 ,
V_196 -> V_209 ) ;
V_203 = V_2 -> V_208 -> V_205 ;
if ( V_203 -> V_207 . V_210 != 2 ) {
F_6 ( V_2 -> V_13 ,
L_51 ,
V_203 -> V_207 . V_210 ) ;
return - V_79 ;
}
V_2 -> V_67 = & V_203 -> V_206 [ 0 ] . V_207 ;
if ( ! F_117 ( V_2 -> V_67 ) ) {
F_6 ( V_2 -> V_13 ,
L_52 ) ;
return - V_79 ;
}
V_2 -> V_74 = F_116 ( V_2 -> V_67 ) ;
if ( V_2 -> V_74 < 8 ) {
F_6 ( V_2 -> V_13 ,
L_53 ,
V_2 -> V_74 ) ;
return - V_79 ;
}
V_2 -> V_181 = & V_203 -> V_206 [ 1 ] . V_207 ;
if ( ! F_118 ( V_2 -> V_181 ) ) {
F_6 ( V_2 -> V_13 ,
L_54 ) ;
return - V_79 ;
}
V_2 -> V_175 = F_116 ( V_2 -> V_181 ) ;
if ( V_2 -> V_175 < 8 ) {
F_6 ( V_2 -> V_13 ,
L_55 ,
V_2 -> V_175 ) ;
return - V_79 ;
}
return 0 ;
}
static int F_119 ( struct V_1 * V_2 )
{
int error ;
error = F_100 ( V_2 -> V_187 , V_40 ) ;
if ( error ) {
F_6 ( V_2 -> V_13 ,
L_56 ,
error ) ;
return - V_162 ;
}
error = F_100 ( V_2 -> V_173 , V_40 ) ;
if ( error ) {
F_6 ( V_2 -> V_13 ,
L_57 ,
error ) ;
F_112 ( V_2 -> V_187 ) ;
return - V_162 ;
}
return 0 ;
}
static void F_120 ( struct V_1 * V_2 )
{
F_112 ( V_2 -> V_173 ) ;
F_112 ( V_2 -> V_187 ) ;
}
static int F_121 ( struct V_1 * V_2 )
{
struct V_202 * V_211 = V_2 -> V_21 -> V_205 ;
struct V_212 * line = ( void * ) V_2 -> V_49 ;
int error ;
memset ( line , 0 , sizeof( * line ) ) ;
line -> V_213 = F_122 ( 57600 ) ;
line -> V_214 = 8 ;
error = F_123 ( V_2 -> V_17 , F_124 ( V_2 -> V_17 , 0 ) ,
V_215 ,
V_216 | V_217 ,
0 , V_211 -> V_207 . V_218 ,
line , sizeof( struct V_212 ) ,
5000 ) ;
if ( error < 0 ) {
F_6 ( V_2 -> V_13 , L_58 ,
error ) ;
return error ;
}
error = F_123 ( V_2 -> V_17 , F_124 ( V_2 -> V_17 , 0 ) ,
V_219 ,
V_216 | V_217 ,
0x03 , V_211 -> V_207 . V_218 ,
NULL , 0 , 5000 ) ;
if ( error < 0 ) {
F_6 ( V_2 -> V_13 , L_59 ,
error ) ;
return error ;
}
return 0 ;
}
static int F_125 ( struct V_1 * V_2 )
{
int error ;
error = F_42 ( V_2 ) ;
if ( error )
return error ;
error = F_43 ( V_2 , V_220 ) ;
if ( error ) {
F_6 ( V_2 -> V_13 ,
L_60 , error ) ;
return error ;
}
snprintf ( V_2 -> V_221 , sizeof( V_2 -> V_221 ) ,
L_61 ,
V_2 -> V_49 [ 2 ] , V_2 -> V_49 [ 3 ] , V_2 -> V_49 [ 4 ] , V_2 -> V_49 [ 5 ] ,
V_2 -> V_49 [ 6 ] , V_2 -> V_49 [ 7 ] ) ;
error = F_43 ( V_2 , V_222 ) ;
if ( error ) {
F_6 ( V_2 -> V_13 ,
L_62 , error ) ;
return error ;
}
snprintf ( V_2 -> V_223 , sizeof( V_2 -> V_223 ) ,
L_61 ,
V_2 -> V_49 [ 2 ] , V_2 -> V_49 [ 3 ] , V_2 -> V_49 [ 4 ] , V_2 -> V_49 [ 5 ] ,
V_2 -> V_49 [ 6 ] , V_2 -> V_49 [ 7 ] ) ;
error = F_43 ( V_2 , V_224 ) ;
if ( error ) {
F_6 ( V_2 -> V_13 ,
L_63 , error ) ;
return error ;
}
snprintf ( V_2 -> V_225 , sizeof( V_2 -> V_225 ) ,
L_64 , V_2 -> V_49 [ V_88 ] ) ;
F_35 ( V_2 -> V_13 ,
L_65 ,
V_2 -> V_81 ,
V_2 -> V_83 ,
V_2 -> V_85 ,
V_2 -> V_221 ,
V_2 -> V_223 ,
V_2 -> V_225 ) ;
return 0 ;
}
static int F_126 ( struct V_1 * V_2 , T_3 * V_226 )
{
int error ;
error = F_43 ( V_2 , V_227 ) ;
if ( error ) {
F_6 ( V_2 -> V_13 ,
L_66 , error ) ;
return error ;
}
* V_226 = V_2 -> V_49 [ V_88 ] ;
F_35 ( V_2 -> V_13 , L_67 , * V_226 ) ;
return 0 ;
}
static int F_127 ( struct V_1 * V_2 )
{
static T_8 V_16 = F_128 ( 0 ) ;
const struct V_228 * V_229 ;
int error ;
error = F_125 ( V_2 ) ;
if ( error ) {
return error ;
}
error = F_126 ( V_2 , & V_2 -> V_226 ) ;
if ( error ) {
F_6 ( V_2 -> V_13 ,
L_68 , error ) ;
return 0 ;
}
if ( V_2 -> V_226 >= F_10 ( V_228 ) ||
! V_228 [ V_2 -> V_226 ] . V_10 ) {
F_6 ( V_2 -> V_13 , L_69 , V_2 -> V_226 ) ;
return 0 ;
}
V_2 -> V_16 = F_129 ( & V_16 ) - 1 ;
if ( V_2 -> V_226 != V_230 ) {
error = F_130 ( & V_2 -> V_13 -> V_113 ,
& V_231 ) ;
if ( error )
return error ;
}
error = F_71 ( V_2 ) ;
if ( error )
return error ;
V_229 = & V_228 [ V_2 -> V_226 ] ;
error = F_4 ( V_2 , V_229 -> V_10 , V_229 -> V_12 ) ;
if ( error )
goto V_232;
if ( V_229 -> V_233 ) {
error = F_19 ( V_2 ) ;
if ( error )
goto V_234;
}
V_2 -> V_46 = true ;
return 0 ;
V_234:
F_15 ( V_2 ) ;
V_232:
F_74 ( V_2 ) ;
return error ;
}
static void F_131 ( struct V_1 * V_2 )
{
if ( V_2 -> V_46 ) {
V_2 -> V_46 = false ;
F_132 () ;
if ( V_2 -> V_29 )
F_23 ( V_2 ) ;
F_15 ( V_2 ) ;
F_74 ( V_2 ) ;
if ( V_2 -> V_226 != V_230 )
F_133 ( & V_2 -> V_13 -> V_113 ,
& V_231 ) ;
}
}
static int F_134 ( struct V_1 * V_2 )
{
int error ;
error = F_51 ( V_2 , V_235 , NULL , 0 ,
V_99 ) ;
if ( error ) {
F_6 ( V_2 -> V_13 , L_70 ) ;
return error ;
}
V_2 -> V_104 =
F_52 ( & V_2 -> V_49 [ V_88 + 11 ] ) ;
V_2 -> V_105 =
F_52 ( & V_2 -> V_49 [ V_88 + 15 ] ) ;
F_57 ( V_2 -> V_13 ,
L_71 ,
V_2 -> V_104 , V_2 -> V_105 ) ;
error = F_135 ( V_236 , true ,
V_109 ,
V_2 -> V_13 , V_40 , V_2 ,
F_59 ) ;
if ( error ) {
F_28 ( & V_2 -> V_116 ) ;
}
return 0 ;
}
static void F_136 ( struct V_1 * V_2 )
{
F_137 ( & V_2 -> V_116 ) ;
}
static int F_138 ( struct V_140 * V_141 ,
const struct V_237 * V_19 )
{
struct V_238 * V_17 = F_139 ( V_141 ) ;
struct V_1 * V_2 ;
int error ;
V_2 = F_20 ( sizeof( struct V_1 ) , V_40 ) ;
if ( ! V_2 )
return - V_14 ;
V_2 -> V_13 = & V_141 -> V_13 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_151 = V_19 -> V_239 == V_240 ;
F_140 ( & V_2 -> V_115 ) ;
F_38 ( & V_2 -> V_52 ) ;
F_38 ( & V_2 -> V_116 ) ;
error = F_114 ( V_141 , V_2 ) ;
if ( error )
goto V_41;
error = F_141 ( & V_241 ,
V_2 -> V_208 , V_2 ) ;
if ( error ) {
F_6 ( & V_141 -> V_13 ,
L_72 ,
error ) ;
goto V_41;
}
F_142 ( V_2 -> V_21 , V_2 ) ;
F_142 ( V_2 -> V_208 , V_2 ) ;
error = F_101 ( V_2 ) ;
if ( error )
goto V_242;
error = F_119 ( V_2 ) ;
if ( error )
goto V_243;
error = F_121 ( V_2 ) ;
if ( error )
goto V_244;
error = F_130 ( & V_141 -> V_13 . V_113 , & V_245 ) ;
if ( error )
goto V_244;
error = V_2 -> V_151 ?
F_134 ( V_2 ) :
F_127 ( V_2 ) ;
if ( error )
goto V_246;
return 0 ;
V_246:
F_133 ( & V_141 -> V_13 . V_113 , & V_245 ) ;
V_244:
F_120 ( V_2 ) ;
V_243:
F_111 ( V_2 ) ;
V_242:
F_143 ( & V_241 , V_2 -> V_208 ) ;
V_41:
F_22 ( V_2 ) ;
return error ;
}
static void F_144 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = F_79 ( V_141 ) ;
struct V_202 * V_203 = V_141 -> V_205 ;
F_142 ( V_141 , NULL ) ;
if ( V_203 -> V_207 . V_247 != V_248 )
return;
F_133 ( & V_141 -> V_13 . V_113 , & V_245 ) ;
F_120 ( V_2 ) ;
if ( V_2 -> V_151 )
F_136 ( V_2 ) ;
else
F_131 ( V_2 ) ;
F_111 ( V_2 ) ;
F_22 ( V_2 ) ;
}
static int F_145 ( struct V_140 * V_141 ,
T_9 V_249 )
{
struct V_1 * V_2 = F_79 ( V_141 ) ;
struct V_202 * V_203 = V_141 -> V_205 ;
if ( V_203 -> V_207 . V_247 == V_248 )
F_120 ( V_2 ) ;
return 0 ;
}
static int F_146 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = F_79 ( V_141 ) ;
struct V_202 * V_203 = V_141 -> V_205 ;
int V_108 = 0 ;
if ( V_203 -> V_207 . V_247 == V_248 ) {
V_108 = F_119 ( V_2 ) ;
if ( V_108 == 0 )
V_108 = F_121 ( V_2 ) ;
}
return V_108 ;
}
