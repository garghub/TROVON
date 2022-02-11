static bool F_1 ( struct V_1 * V_1 ,
T_1 * V_2 , int V_3 )
{
if ( V_3 != V_4 )
return false ;
if ( V_2 [ V_5 ] == V_6 ||
V_2 [ V_5 ] == V_7 )
return true ;
return false ;
}
static int F_2 ( struct V_1 * V_1 ,
struct V_8 * V_9 , bool V_10 )
{
T_1 V_11 [ V_12 ] ;
int V_13 ;
T_2 V_14 ;
int error ;
if ( V_10 ) {
V_13 = sizeof( V_11 ) ;
error = F_3 ( V_1 ,
V_15 , sizeof( V_15 ) ,
V_11 , & V_13 ,
2000 , V_16 ,
false ) ;
if ( error || V_13 < V_17 )
return error ? error : - V_18 ;
V_9 -> V_19 = V_11 [ 8 ] ;
V_9 -> V_20 = V_11 [ 10 ] ;
V_9 -> V_21 = V_11 [ 11 ] ;
return 0 ;
}
V_13 = sizeof( V_11 ) ;
error = F_3 ( V_1 ,
V_22 , V_23 ,
V_11 , & V_13 ,
2000 , V_24 , false ) ;
if ( error || V_13 < V_12 )
return error ? error : - V_18 ;
V_14 = F_4 ( & V_11 [ 7 ] ) ;
if ( ( V_14 & V_25 ) !=
V_26 )
return - V_27 ;
V_9 -> V_19 = V_11 [ 19 ] ;
V_9 -> V_20 = V_11 [ 21 ] ;
V_9 -> V_21 = V_11 [ 22 ] ;
return 0 ;
}
int F_5 ( struct V_1 * V_1 , T_1 * V_28 , int V_3 )
{
T_1 V_29 [] = { 0x01 , 0x00 } ;
struct V_8 V_9 ;
T_1 V_11 [ V_4 ] ;
int V_13 ;
bool V_10 ;
int error ;
V_1 -> V_30 = V_31 ;
F_6 ( V_1 , V_32 ) ;
F_7 ( V_1 , NULL , NULL , NULL ) ;
V_13 = V_4 ;
error = F_3 ( V_1 ,
V_29 , sizeof( V_29 ) ,
V_11 , & V_13 ,
300 ,
F_1 ,
false ) ;
if ( error )
return error ;
if ( V_11 [ V_5 ] == V_7 )
V_10 = true ;
else if ( V_11 [ V_5 ] == V_6 )
V_10 = false ;
else
return - V_33 ;
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
error = F_2 ( V_1 , & V_9 , V_10 ) ;
if ( error )
return error ;
if ( V_9 . V_19 == 0x9B && V_9 . V_21 == 0x0B ) {
V_1 -> V_34 = V_35 ;
V_1 -> V_30 = V_10 ? V_36
: V_37 ;
} else if ( V_9 . V_19 == 0x91 &&
V_9 . V_21 == 0x02 ) {
V_1 -> V_34 = V_38 ;
V_1 -> V_30 = V_10 ? V_39
: V_40 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_1 )
{
T_1 V_11 [ V_12 ] ;
int V_13 ;
T_2 V_14 ;
T_1 V_41 ;
int error ;
V_13 = sizeof( V_11 ) ;
error = F_3 ( V_1 ,
V_22 , V_23 ,
V_11 , & V_13 ,
2000 , V_24 , false ) ;
if ( error || V_13 < sizeof( V_11 ) )
return error ? error : - V_18 ;
V_14 = F_4 ( & V_11 [ 7 ] ) ;
if ( ( V_14 & V_25 ) !=
V_26 )
return - V_27 ;
V_1 -> V_42 = ( V_11 [ 67 ] >> V_43 ) &
V_44 ;
V_1 -> V_45 = V_11 [ 9 ] ;
V_1 -> V_46 = V_11 [ 10 ] ;
V_1 -> V_47 = V_11 [ 33 ] ;
V_1 -> V_48 = V_11 [ 34 ] ;
V_1 -> V_49 = F_4 ( & V_11 [ 35 ] ) / 100 ;
V_1 -> V_50 = F_4 ( & V_11 [ 37 ] ) / 100 ;
V_1 -> V_51 = F_4 ( & V_11 [ 39 ] ) ;
V_1 -> V_52 = F_4 ( & V_11 [ 41 ] ) ;
V_1 -> V_53 = F_4 ( & V_11 [ 43 ] ) ;
V_1 -> V_54 = V_11 [ 45 ] & 0x01 ;
V_1 -> V_55 = V_11 [ 46 ] & 0x01 ;
V_1 -> V_56 = ( V_11 [ 70 ] << 3 ) & V_57 ;
memcpy ( & V_1 -> V_58 [ 0 ] , & V_11 [ 51 ] , 5 ) ;
V_1 -> V_58 [ 5 ] = '-' ;
memcpy ( & V_1 -> V_58 [ 6 ] , & V_11 [ 56 ] , 6 ) ;
V_1 -> V_58 [ 12 ] = '-' ;
memcpy ( & V_1 -> V_58 [ 13 ] , & V_11 [ 62 ] , 2 ) ;
V_1 -> V_58 [ 15 ] = '\0' ;
V_41 = V_11 [ 68 ] ;
V_1 -> V_59 =
V_41 ? V_1 -> V_48 : V_1 -> V_47 ;
V_1 -> V_60 = ( V_1 -> V_59 + 3 ) & ~ 3u ;
if ( ! V_1 -> V_47 || ! V_1 -> V_48 ||
! V_1 -> V_49 || ! V_1 -> V_50 ||
! V_1 -> V_51 || ! V_1 -> V_52 || ! V_1 -> V_53 )
return - V_27 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_1 )
{
T_1 V_11 [ V_61 ] ;
int V_13 ;
int error ;
V_13 = sizeof( V_11 ) ;
error = F_3 ( V_1 ,
V_62 , V_63 ,
V_11 , & V_13 ,
500 , V_16 , false ) ;
if ( error || V_13 < V_61 ||
! F_10 ( V_11 ) )
return error ? error : - V_18 ;
V_1 -> V_45 = V_11 [ 8 ] ;
V_1 -> V_46 = V_11 [ 9 ] ;
V_1 -> V_42 = ( V_11 [ 12 ] >> V_43 ) &
V_44 ;
memcpy ( & V_1 -> V_58 [ 0 ] , & V_11 [ 13 ] , 5 ) ;
V_1 -> V_58 [ 5 ] = '-' ;
memcpy ( & V_1 -> V_58 [ 6 ] , & V_11 [ 18 ] , 6 ) ;
V_1 -> V_58 [ 12 ] = '-' ;
memcpy ( & V_1 -> V_58 [ 13 ] , & V_11 [ 24 ] , 2 ) ;
V_1 -> V_58 [ 15 ] = '\0' ;
return 0 ;
}
static int F_11 ( struct V_1 * V_1 , T_1 V_64 )
{
T_1 V_29 [] = { 0x04 , 0x00 , 0x05 , 0x00 , 0x2f , 0x00 , V_64 } ;
T_1 V_11 [ 6 ] ;
int V_13 ;
int error ;
V_13 = sizeof( V_11 ) ;
error = F_3 ( V_1 , V_29 , sizeof( V_29 ) ,
V_11 , & V_13 ,
500 , V_65 , false ) ;
if ( error || ! F_12 ( V_11 , V_64 ) ||
! F_10 ( V_11 )
)
return error < 0 ? error : - V_27 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_1 , bool V_66 )
{
int error ;
F_11 ( V_1 , V_67 ) ;
error = F_14 ( V_1 , V_66 ) ;
F_11 ( V_1 , V_68 ) ;
return error ;
}
static int F_15 ( struct V_1 * V_1 , T_1 V_69 )
{
T_1 V_29 [] = { 0x04 , 0x00 , 0x06 , 0x00 , 0x2f , 0x00 , 0x46 , V_69 } ;
T_1 V_11 [ 6 ] ;
int V_13 ;
int error ;
V_13 = sizeof( V_11 ) ;
error = F_3 ( V_1 , V_29 , sizeof( V_29 ) ,
V_11 , & V_13 ,
500 , V_65 , false ) ;
if ( error || ! F_12 ( V_11 , 0x46 ) )
return error < 0 ? error : - V_27 ;
if ( V_11 [ 5 ] != V_69 )
return - V_33 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_1 ,
struct V_70 * V_71 )
{
struct V_72 {
T_3 V_73 ;
T_3 V_74 ;
T_1 V_75 ;
T_1 V_76 ;
T_1 V_64 ;
T_3 V_77 ;
T_3 V_78 ;
T_3 V_79 ;
} V_80 V_81 ;
T_1 V_11 [ 11 ] ;
int V_13 ;
int error ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
F_17 ( V_82 , & V_81 . V_73 ) ;
F_17 ( sizeof( V_81 ) - 2 ,
& V_81 . V_74 ) ;
V_81 . V_75 = V_83 ;
V_81 . V_64 = V_84 ;
F_17 ( V_71 -> V_77 ,
& V_81 . V_77 ) ;
F_17 ( V_71 -> V_78 ,
& V_81 . V_78 ) ;
F_17 ( V_71 -> V_79 ,
& V_81 . V_79 ) ;
V_13 = sizeof( V_11 ) ;
error = F_3 ( V_1 ,
( T_1 * ) & V_81 , sizeof( V_81 ) ,
V_11 , & V_13 ,
500 , V_65 , false ) ;
if ( error ||
! F_12 ( V_11 , V_84 ) )
return error < 0 ? error : - V_27 ;
V_71 -> V_77 = F_4 ( & V_11 [ 5 ] ) ;
V_71 -> V_78 = F_4 ( & V_11 [ 7 ] ) ;
V_71 -> V_79 = F_4 ( & V_11 [ 9 ] ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_1 ,
struct V_70 * V_71 )
{
T_1 V_29 [] = { 0x04 , 0x00 , 0x05 , 0x00 , 0x2f , 0x00 ,
V_85 } ;
T_1 V_11 [ 11 ] ;
int V_13 ;
int error ;
V_13 = sizeof( V_11 ) ;
error = F_3 ( V_1 , V_29 , sizeof( V_29 ) ,
V_11 , & V_13 ,
500 , V_65 , false ) ;
if ( error ||
! F_12 ( V_11 , V_85 ) )
return error < 0 ? error : - V_27 ;
V_71 -> V_77 = F_4 ( & V_11 [ 5 ] ) ;
V_71 -> V_78 = F_4 ( & V_11 [ 7 ] ) ;
V_71 -> V_79 = F_4 ( & V_11 [ 9 ] ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_1 , T_1 V_30 )
{
T_1 V_86 [] = { 0x04 , 0x00 , 0x05 , 0x00 , 0x2f , 0x00 , 0x00 } ;
if ( V_30 == V_32 )
F_20 ( V_1 , V_86 , sizeof( V_86 ) ) ;
return F_6 ( V_1 , V_30 ) ;
}
static int F_21 ( struct V_1 * V_1 ,
T_1 V_69 , T_2 V_87 , enum V_88 V_89 )
{
struct V_90 * V_91 = & V_1 -> V_92 -> V_91 ;
struct V_70 * V_71 =
& V_1 -> V_70 ;
T_1 V_93 ;
int error ;
if ( V_1 -> V_30 != V_37 )
return 0 ;
if ( F_22 ( V_1 ) == V_94 ) {
F_23 ( V_1 , V_95 ) ;
}
if ( F_24 ( V_1 ) &&
F_22 ( V_1 ) != V_95 )
F_25 ( V_1 , V_96 ) ;
if ( F_22 ( V_1 ) == V_69 ) {
if ( V_69 == V_95 ||
V_69 == V_97 ||
V_69 == V_98 ||
F_26 ( V_1 ) == V_87 ) {
return 0 ;
}
}
if ( V_69 == V_95 ) {
F_11 ( V_1 , V_67 ) ;
error = F_19 ( V_1 , V_99 ) ;
if ( error ) {
F_27 ( V_91 , L_1 , error ) ;
return error ;
}
F_23 ( V_1 , V_95 ) ;
return 0 ;
}
if ( F_22 ( V_1 ) == V_95 ) {
error = F_19 ( V_1 , V_32 ) ;
if ( error ) {
F_27 ( V_91 , L_2 , error ) ;
return error ;
}
}
F_11 ( V_1 , V_67 ) ;
if ( V_69 == V_97 ) {
error = F_15 ( V_1 ,
V_100 ) ;
if ( error ) {
F_27 ( V_91 , L_3 , error ) ;
goto V_101;
}
F_23 ( V_1 , V_97 ) ;
F_18 ( V_1 , V_71 ) ;
} else if ( V_69 == V_98 ) {
error = F_15 ( V_1 ,
V_102 ) ;
if ( error ) {
F_27 ( V_91 , L_4 , error ) ;
goto V_101;
}
F_23 ( V_1 , V_98 ) ;
} else {
if ( V_71 -> V_78 == V_87 ) {
V_93 = V_103 ;
} else if ( V_71 -> V_79 == V_87 ) {
V_93 = V_104 ;
} else {
if ( V_71 -> V_78 == 0 ) {
V_71 -> V_78 = V_87 ;
V_93 = V_103 ;
} else {
V_71 -> V_79 = V_87 ;
V_93 = V_104 ;
}
F_16 ( V_1 ,
V_71 ) ;
}
error = F_15 ( V_1 , V_93 ) ;
if ( error ) {
F_27 ( V_91 , L_5 ,
V_93 , error ) ;
goto V_101;
}
F_25 ( V_1 , V_87 ) ;
F_23 ( V_1 ,
F_28 ( V_87 ) ) ;
}
V_101:
F_11 ( V_1 , V_68 ) ;
return error ;
}
static int F_29 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_30 ( struct V_1 * V_1 ,
T_2 V_105 , T_2 V_106 , T_1 V_107 ,
T_1 * V_108 , int * V_109 )
{
struct V_110 {
struct V_111 V_112 ;
T_3 V_105 ;
T_3 V_113 ;
T_1 V_107 ;
} V_80 V_29 ;
T_1 V_11 [ V_114 + 10 ] ;
int V_13 ;
int error ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
F_17 ( V_82 , & V_29 . V_112 . V_73 ) ;
F_17 ( sizeof( V_29 ) , & V_29 . V_112 . V_74 - 2 ) ;
V_29 . V_112 . V_75 = V_83 ;
V_29 . V_112 . V_64 = V_115 ;
F_17 ( V_105 , & V_29 . V_105 ) ;
F_17 ( V_106 , & V_29 . V_113 ) ;
V_29 . V_107 = V_107 ;
V_13 = sizeof( V_11 ) ;
error = F_3 ( V_1 ,
( T_1 * ) & V_29 , sizeof( V_29 ) ,
V_11 , & V_13 ,
500 , V_65 ,
true ) ;
if ( error || ! F_10 ( V_11 ) ||
V_11 [ 6 ] != V_107 ||
! F_12 ( V_11 , V_115 ) )
return ( error < 0 ) ? error : - V_33 ;
V_106 = F_4 ( & V_11 [ 7 ] ) ;
if ( * V_109 < V_106 ) {
* V_109 = V_106 ;
return - V_116 ;
}
memcpy ( V_108 , & V_11 [ 10 ] , V_106 ) ;
* V_109 = V_106 ;
return 0 ;
}
static T_4 F_31 ( struct V_90 * V_91 ,
struct V_117 * V_118 , char * V_2 )
{
struct V_1 * V_1 = F_32 ( V_91 ) ;
T_1 V_108 [ V_114 ] ;
int V_119 ;
int V_120 = 0 ;
int V_121 ;
int error ;
int V_122 ;
if ( ! F_33 ( V_1 ) )
return - V_123 ;
error = F_34 ( V_1 ) ;
if ( error )
return error ;
V_119 = sizeof( V_108 ) ;
error = F_30 ( V_1 , 0 , V_119 ,
V_124 ,
V_108 , & V_119 ) ;
if ( error )
goto V_125;
V_120 = F_35 ( V_2 , V_126 , L_6 ,
V_108 [ 0 ] ,
V_108 [ 1 ] ,
V_108 [ 2 ] ,
V_108 [ 3 ] ,
V_108 [ 4 ] ,
V_108 [ 5 ]
) ;
V_119 = sizeof( V_108 ) ;
error = F_30 ( V_1 , 0 , V_119 ,
V_127 ,
V_108 , & V_119 ) ;
if ( error )
goto V_125;
for ( V_121 = 0 ; V_121 < V_119 ; V_121 ++ )
V_120 += F_35 ( V_2 + V_120 , V_126 - V_120 , L_7 , V_108 [ V_121 ] ) ;
V_120 += F_35 ( V_2 + V_120 , V_126 - V_120 , L_8 ) ;
V_125:
V_122 = F_36 ( V_1 ) ;
if ( V_122 || error ) {
memset ( V_2 , 0 , V_126 ) ;
return V_122 ? V_122 : error ;
}
return V_120 ;
}
static int F_37 ( struct V_1 * V_1 )
{
struct V_90 * V_91 = & V_1 -> V_92 -> V_91 ;
int error ;
if ( V_1 -> V_34 != V_35 )
return - V_128 ;
switch ( V_1 -> V_30 ) {
case V_36 :
error = F_38 ( V_1 ) ;
if ( error ) {
F_9 ( V_1 ) ;
goto V_101;
}
V_1 -> V_30 = V_37 ;
case V_37 :
error = F_21 ( V_1 ,
V_97 , 0 , V_129 ) ;
if ( error )
F_39 ( V_91 , L_9 ,
V_130 ) ;
error = F_14 ( V_1 , true ) ;
if ( error )
F_39 ( V_91 , L_10 ,
V_130 ) ;
error = F_8 ( V_1 ) ;
if ( error )
goto V_101;
if ( memcmp ( V_1 -> V_58 , V_58 ,
strlen ( V_58 ) ) != 0 ) {
F_27 ( V_91 , L_11 ,
V_130 , V_1 -> V_58 ) ;
error = - V_27 ;
}
break;
default:
error = - V_27 ;
}
V_101:
return error ;
}
