static T_1 F_1 ( struct V_1 * V_1 , T_2 V_2 , T_3 V_3 ,
T_2 * V_4 )
{
return F_2 ( V_1 -> V_5 , V_2 , V_3 , V_4 ) ;
}
static T_1 F_3 ( struct V_1 * V_1 , T_2 V_2 ,
T_3 V_3 , const T_2 * V_4 )
{
return F_4 ( V_1 -> V_5 , V_2 , V_3 , V_4 ) ;
}
static T_1 F_5 ( struct V_1 * V_1 , T_2 V_6 , T_3 V_3 ,
T_2 * V_4 )
{
T_1 V_7 ;
T_2 V_8 ;
T_2 V_9 ;
T_2 * V_10 ;
struct V_11 * V_5 = V_1 -> V_5 ;
if ( ! ( V_12 & V_6 ) )
return - V_13 ;
if ( V_14 & V_6 ) {
V_9 = F_6 ( V_6 , V_15 ) ;
V_7 = F_7 ( V_5 , V_9 , V_4 ) ;
goto V_16;
}
V_7 = 0 ;
for ( V_8 = 0 ; V_8 * V_17 < V_3 ; V_8 ++ ) {
V_9 = F_8 ( V_6 , V_8 ) ;
V_9 = F_6 ( V_9 , V_15 ) ;
V_10 = V_4 + V_17 * V_8 ;
V_7 = F_7 ( V_5 , V_9 , V_10 ) ;
if ( V_7 < 0 )
goto V_16;
}
V_16:
return V_7 > 0 ? V_3 : V_7 ;
}
static T_4 F_9 ( struct V_1 * V_1 , T_2 V_18 )
{
T_2 V_6 ;
if ( V_1 -> V_19 ) {
V_6 = V_20 [ V_18 ] . V_6 ;
V_6 = F_6 ( V_6 , V_15 ) ;
} else {
V_6 = V_21 [ V_18 ] . V_6 ;
}
return F_10 ( V_1 -> V_5 , V_6 ) ;
}
static T_4 F_11 ( struct V_1 * V_1 , T_2 V_18 , T_2 V_22 )
{
T_2 V_6 ;
if ( V_1 -> V_19 ) {
V_6 = V_20 [ V_18 ] . V_6 ;
V_6 = F_6 ( V_6 , V_23 ) ;
} else {
V_6 = V_21 [ V_18 ] . V_6 ;
}
return F_12 ( V_1 -> V_5 , V_6 , V_22 ) ;
}
static T_1 F_13 ( struct V_1 * V_1 , T_2 V_18 , T_2 * V_4 )
{
T_2 V_6 ;
T_3 V_3 ;
if ( V_1 -> V_19 ) {
V_6 = V_20 [ V_18 ] . V_6 ;
V_3 = V_20 [ V_18 ] . V_3 ;
return F_5 ( V_1 , V_6 , V_3 , V_4 ) ;
} else {
V_6 = V_21 [ V_18 ] . V_6 ;
V_3 = V_21 [ V_18 ] . V_3 ;
return F_1 ( V_1 , V_6 , V_3 , V_4 ) ;
}
}
static int F_14 ( struct V_1 * V_1 )
{
T_2 V_24 [ V_25 ] ;
int error ;
V_1 -> V_26 = V_27 ;
error = F_1 ( V_1 , V_28 , V_25 ,
V_24 ) ;
if ( V_1 -> V_19 && ( error == - V_29 || error == - V_30 ) )
error = F_13 ( V_1 , V_31 , V_24 ) ;
if ( error != V_25 )
goto error;
if ( ( V_24 [ V_32 ] & V_33 ) == V_33 ) {
switch ( V_24 [ V_32 ] & V_34 ) {
case V_35 :
case V_36 :
V_1 -> V_26 = V_37 ;
break;
default:
error = - V_38 ;
goto error;
}
} else {
if ( V_24 [ V_39 ] & V_40 )
V_1 -> V_26 = V_41 ;
else if ( V_24 [ V_42 ] & V_43 )
V_1 -> V_26 = V_44 ;
else
V_1 -> V_26 = V_45 ;
}
return 0 ;
error:
return ( error < 0 ) ? error : - V_38 ;
}
static int F_15 ( struct V_1 * V_1 , unsigned int V_46 )
{
int error ;
int V_47 = V_46 / 100 ;
error = F_14 ( V_1 ) ;
while ( ( error || V_1 -> V_26 >= V_41 ) && V_47 -- ) {
F_16 ( 100 ) ;
error = F_14 ( V_1 ) ;
}
return ( error == - V_38 || error == - V_29 ) ? - V_29 : error ;
}
static int F_17 ( struct V_1 * V_1 )
{
int error ;
error = F_3 ( V_1 , 0 , sizeof( V_48 ) ,
V_48 ) ;
if ( error )
return error ;
F_16 ( 100 ) ;
error = F_15 ( V_1 , 500 ) ;
if ( error )
return error ;
if ( V_1 -> V_26 != V_45 )
return - V_38 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_1 )
{
int error ;
error = F_3 ( V_1 , 0 , sizeof( V_49 ) , V_49 ) ;
if ( error )
return error ;
F_19 ( 50000 , 100000 ) ;
error = F_15 ( V_1 , 2000 ) ;
if ( error < 0 )
return error ;
if ( V_1 -> V_26 != V_37 )
return - V_38 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_1 , T_2 V_50 )
{
struct V_51 * V_52 = & V_1 -> V_5 -> V_52 ;
int V_7 ;
T_2 V_53 ;
if ( V_1 -> V_26 != V_37 )
return 0 ;
V_7 = F_9 ( V_1 , V_54 ) ;
if ( V_7 < 0 )
return V_7 ;
V_53 = V_7 & ~ V_55 ;
V_53 |= V_50 & V_55 ;
V_7 = F_11 ( V_1 , V_54 , V_53 ) ;
if ( V_7 < 0 ) {
F_21 ( V_52 , L_1 ,
V_50 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_1 )
{
T_2 V_56 [ V_57 ] ;
int V_7 ;
if ( V_1 -> V_26 != V_37 )
return - V_58 ;
V_7 = F_13 ( V_1 , V_59 , V_56 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_7 != V_57 )
return - V_60 ;
memcpy ( & V_1 -> V_61 [ 0 ] , & V_56 [ 0 ] , 5 ) ;
V_1 -> V_61 [ 5 ] = '-' ;
memcpy ( & V_1 -> V_61 [ 6 ] , & V_56 [ 5 ] , 6 ) ;
V_1 -> V_61 [ 12 ] = '-' ;
memcpy ( & V_1 -> V_61 [ 13 ] , & V_56 [ 11 ] , 2 ) ;
V_1 -> V_61 [ 15 ] = '\0' ;
V_1 -> V_62 = V_56 [ 19 ] & V_63 ;
V_1 -> V_64 = V_56 [ 20 ] & 0x0f ;
V_1 -> V_65 = ( ( V_56 [ 21 ] & 0xf0 ) << 4 ) | V_56 [ 22 ] ;
V_1 -> V_66 = ( ( V_56 [ 21 ] & 0x0f ) << 8 ) | V_56 [ 23 ] ;
V_1 -> V_67 =
( ( V_56 [ 24 ] & 0xf0 ) << 4 ) | V_56 [ 25 ] ;
V_1 -> V_68 =
( ( V_56 [ 24 ] & 0x0f ) << 8 ) | V_56 [ 26 ] ;
return 0 ;
}
static int F_23 ( struct V_1 * V_1 )
{
struct V_51 * V_52 = & V_1 -> V_5 -> V_52 ;
static const char V_69 [] = L_2 ;
int error ;
error = F_15 ( V_1 , 2000 ) ;
if ( error )
return error ;
switch ( V_1 -> V_26 ) {
case V_44 :
error = F_17 ( V_1 ) ;
if ( error )
return error ;
case V_45 :
error = F_18 ( V_1 ) ;
if ( error )
return error ;
case V_37 :
error = F_22 ( V_1 ) ;
if ( error )
return error ;
if ( V_1 -> V_64 != V_70 ) {
F_21 ( V_52 , L_3 ,
V_1 -> V_64 ) ;
return - V_13 ;
}
if ( memcmp ( V_1 -> V_61 , V_69 ,
sizeof( V_69 ) - 1 ) != 0 ) {
F_21 ( V_52 , L_4 ,
V_1 -> V_61 ) ;
return - V_13 ;
}
return 0 ;
default:
return - V_60 ;
}
return 0 ;
}
static T_5 F_24 ( int V_71 , void * V_72 )
{
struct V_1 * V_1 = V_72 ;
struct V_51 * V_52 = & V_1 -> V_5 -> V_52 ;
struct V_73 * V_74 = V_1 -> V_74 ;
struct V_75 V_76 ;
int V_77 ;
int V_7 ;
int V_78 ;
if ( F_25 ( V_52 ) )
F_26 ( V_52 , 0 ) ;
V_7 = F_13 ( V_1 , V_79 , ( T_2 * ) & V_76 ) ;
if ( V_7 != sizeof( V_76 ) )
goto V_16;
if ( ( V_76 . V_80 & V_33 ) != V_33 ||
( V_76 . V_80 & V_34 ) != V_35 ||
( V_76 . V_81 & V_82 ) != V_82 ) {
goto V_16;
}
V_78 = ( V_76 . V_81 >> 4 ) & 0x0f ;
for ( V_77 = 0 ; V_77 < V_78 ; V_77 ++ ) {
const struct V_83 * V_84 = & V_76 . V_85 [ V_77 ] ;
int V_86 = V_84 -> V_87 - 1 ;
F_27 ( V_74 , V_86 ) ;
F_28 ( V_74 , V_88 , true ) ;
F_29 ( V_74 , V_89 ,
( ( V_84 -> V_90 & 0xf0 ) << 4 ) | V_84 -> V_91 ) ;
F_29 ( V_74 , V_92 ,
( ( V_84 -> V_90 & 0x0f ) << 8 ) | V_84 -> V_93 ) ;
F_29 ( V_74 , V_94 , V_84 -> V_95 ) ;
}
F_30 ( V_74 ) ;
if ( V_1 -> V_62 & V_96 )
F_31 ( V_74 , V_97 ,
V_76 . V_81 & V_98 ) ;
if ( V_1 -> V_62 & V_99 )
F_31 ( V_74 , V_100 ,
V_76 . V_81 & V_101 ) ;
if ( V_1 -> V_62 & V_102 )
F_31 ( V_74 , V_103 ,
V_76 . V_81 & V_104 ) ;
F_32 ( V_74 ) ;
V_16:
return V_105 ;
}
static T_2 F_33 ( struct V_11 * V_5 )
{
T_2 V_7 = V_106 ;
if ( F_34 ( V_5 -> V_107 , V_108 ) )
V_7 |= V_109 ;
if ( F_34 ( V_5 -> V_107 , V_110 |
V_111 |
V_112 ) )
V_7 |= V_113 ;
return V_7 ;
}
static int F_35 ( struct V_73 * V_74 )
{
struct V_1 * V_1 = F_36 ( V_74 ) ;
struct V_11 * V_5 = V_1 -> V_5 ;
int error ;
error = F_20 ( V_1 , V_114 ) ;
if ( error ) {
F_21 ( & V_5 -> V_52 , L_5 , error ) ;
return error ;
}
F_37 ( V_5 -> V_71 ) ;
return 0 ;
}
static void F_38 ( struct V_73 * V_74 )
{
struct V_1 * V_1 = F_36 ( V_74 ) ;
F_39 ( V_1 -> V_5 -> V_71 ) ;
F_20 ( V_1 , V_115 ) ;
}
static int F_40 ( struct V_1 * V_1 )
{
struct V_51 * V_52 = & V_1 -> V_5 -> V_52 ;
struct V_73 * V_74 ;
int error ;
if ( ! V_1 -> V_67 || ! V_1 -> V_68 )
return - V_13 ;
V_74 = F_41 ( V_52 ) ;
if ( ! V_74 ) {
F_21 ( V_52 , L_6 ) ;
return - V_116 ;
}
V_74 -> V_117 = V_118 ;
V_74 -> V_119 = V_1 -> V_119 ;
V_74 -> V_87 . V_120 = V_121 ;
V_74 -> V_87 . V_122 = 1 ;
V_74 -> V_87 . V_123 = 0 ;
V_74 -> V_52 . V_124 = & V_1 -> V_5 -> V_52 ;
V_74 -> V_125 = F_35 ;
V_74 -> V_126 = F_38 ;
F_42 ( V_74 , V_1 ) ;
F_43 ( V_127 , V_74 -> V_128 ) ;
F_44 ( V_74 , V_89 , 0 , V_1 -> V_65 , 0 ,
0 ) ;
F_44 ( V_74 , V_92 , 0 , V_1 -> V_66 , 0 ,
0 ) ;
F_44 ( V_74 , V_94 , 0 , 255 , 0 , 0 ) ;
F_45 ( V_74 , V_89 ,
V_1 -> V_65 / V_1 -> V_67 ) ;
F_45 ( V_74 , V_92 ,
V_1 -> V_66 / V_1 -> V_68 ) ;
if ( V_1 -> V_62 & V_96 )
F_43 ( V_97 , V_74 -> V_129 ) ;
if ( V_1 -> V_62 & V_99 )
F_43 ( V_100 , V_74 -> V_129 ) ;
if ( V_1 -> V_62 & V_102 )
F_43 ( V_103 , V_74 -> V_129 ) ;
if ( V_1 -> V_62 == V_96 )
F_43 ( V_130 , V_74 -> V_131 ) ;
error = F_46 ( V_74 , V_132 ,
V_133 | V_134 ) ;
if ( error ) {
F_21 ( V_52 , L_7 , error ) ;
return error ;
}
V_1 -> V_74 = V_74 ;
return 0 ;
}
static int F_47 ( struct V_11 * V_5 ,
const struct V_135 * V_72 )
{
struct V_51 * V_52 = & V_5 -> V_52 ;
struct V_1 * V_1 ;
T_2 V_136 ;
int error ;
V_136 = F_33 ( V_5 ) ;
if ( V_136 == V_106 ) {
F_21 ( V_52 , L_8 ) ;
return - V_60 ;
}
V_1 = F_48 ( V_52 , sizeof( struct V_1 ) , V_137 ) ;
if ( ! V_1 )
return - V_116 ;
V_1 -> V_64 = V_70 ;
V_1 -> V_5 = V_5 ;
F_49 ( V_5 , V_1 ) ;
sprintf ( V_1 -> V_119 , L_9 , V_5 -> V_107 -> V_138 ,
V_5 -> V_139 ) ;
if ( V_136 == V_113 )
V_1 -> V_19 = true ;
V_1 -> V_26 = V_27 ;
error = F_23 ( V_1 ) ;
if ( error ) {
F_21 ( V_52 , L_10 , error ) ;
return error ;
}
error = F_20 ( V_1 , V_115 ) ;
if ( error ) {
F_21 ( V_52 , L_11 , error ) ;
return error ;
}
error = F_40 ( V_1 ) ;
if ( error )
return error ;
error = F_50 ( V_52 , V_5 -> V_71 ,
NULL , F_24 ,
V_140 | V_141 ,
L_12 , V_1 ) ;
if ( error ) {
F_21 ( V_52 , L_13 , error ) ;
return error ;
}
F_39 ( V_5 -> V_71 ) ;
error = F_51 ( V_1 -> V_74 ) ;
if ( error ) {
F_21 ( V_52 , L_14 , error ) ;
return error ;
}
return 0 ;
}
static int T_6 F_52 ( struct V_51 * V_52 )
{
struct V_11 * V_5 = F_53 ( V_52 ) ;
struct V_1 * V_1 = F_54 ( V_5 ) ;
struct V_73 * V_74 = V_1 -> V_74 ;
T_2 V_50 ;
int error ;
error = F_55 ( & V_74 -> V_142 ) ;
if ( error )
return error ;
F_39 ( V_5 -> V_71 ) ;
V_50 = F_25 ( V_52 ) ? V_143
: V_115 ;
error = F_20 ( V_1 , V_50 ) ;
if ( error )
F_21 ( V_52 , L_15 ,
V_50 , error ) ;
if ( F_25 ( V_52 ) )
V_1 -> V_144 = ( F_56 ( V_5 -> V_71 ) == 0 ) ;
F_57 ( & V_74 -> V_142 ) ;
return 0 ;
}
static int T_6 F_58 ( struct V_51 * V_52 )
{
struct V_11 * V_5 = F_53 ( V_52 ) ;
struct V_1 * V_1 = F_54 ( V_5 ) ;
struct V_73 * V_74 = V_1 -> V_74 ;
T_2 V_50 ;
int error ;
F_59 ( & V_74 -> V_142 ) ;
if ( F_25 ( V_52 ) && V_1 -> V_144 )
F_60 ( V_5 -> V_71 ) ;
V_50 = V_74 -> V_145 ? V_114 : V_115 ;
error = F_20 ( V_1 , V_114 ) ;
if ( error )
F_61 ( V_52 , L_15 ,
V_50 , error ) ;
F_37 ( V_5 -> V_71 ) ;
F_57 ( & V_74 -> V_142 ) ;
return 0 ;
}
