static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 * V_4 ,
T_1 V_5 , T_2 * V_6 )
{
struct V_7 V_8 [ 2 ] ;
int V_9 = 0 ;
int V_10 ;
if ( V_3 ) {
V_8 [ V_9 ] . V_11 = V_2 -> V_11 ;
V_8 [ V_9 ] . V_12 = 0 ;
V_8 [ V_9 ] . V_13 = V_3 ;
V_8 [ V_9 ] . V_14 = V_4 ;
V_9 ++ ;
}
if ( V_5 ) {
V_8 [ V_9 ] . V_11 = V_2 -> V_11 ;
V_8 [ V_9 ] . V_12 = V_15 ;
V_8 [ V_9 ] . V_13 = V_5 ;
V_8 [ V_9 ] . V_14 = V_6 ;
V_9 ++ ;
}
V_10 = F_2 ( V_2 -> V_16 , V_8 , V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_10 != V_9 )
return - V_17 ;
return 0 ;
}
static bool F_3 ( struct V_18 * V_19 ,
T_2 * V_14 , int V_20 )
{
int V_9 ;
T_2 V_21 = 0 ;
for ( V_9 = 0 ; V_9 < V_20 - 1 ; V_9 ++ )
V_21 ^= V_14 [ V_9 ] ;
if ( V_21 != V_14 [ V_20 - 1 ] ) {
F_4 ( & V_19 -> V_2 -> V_22 ,
L_1 ,
V_21 , V_14 [ V_20 - 1 ] ) ;
return false ;
}
return true ;
}
static T_3 F_5 ( int V_23 , void * V_24 )
{
struct V_18 * V_19 = V_24 ;
struct V_25 * V_22 = & V_19 -> V_2 -> V_22 ;
T_2 V_26 ;
T_2 V_27 [ 63 ] ;
int V_9 , type , V_28 , V_29 , V_30 ;
int V_31 , V_32 , V_33 , V_34 ;
int error ;
switch ( V_19 -> V_35 ) {
case V_36 :
V_26 = 0xf9 ;
V_31 = 5 ;
V_32 = 4 ;
V_34 = 1 ;
break;
case V_37 :
V_26 = 0x0 ;
V_31 = 3 ;
V_32 = 6 ;
V_34 = 0 ;
break;
default:
goto V_38;
}
memset ( V_27 , 0 , sizeof( V_27 ) ) ;
V_33 = V_32 * V_19 -> V_39 + V_31 + V_34 ;
error = F_1 ( V_19 -> V_2 ,
sizeof( V_26 ) , & V_26 ,
V_33 , V_27 ) ;
if ( error ) {
F_4 ( V_22 , L_2 ,
error ) ;
goto V_38;
}
if ( V_19 -> V_35 == V_36 ) {
if ( V_27 [ 0 ] != 0xaa || V_27 [ 1 ] != 0xaa ||
V_27 [ 2 ] != V_33 ) {
F_4 ( V_22 ,
L_3 ,
V_27 [ 0 ] , V_27 [ 1 ] , V_27 [ 2 ] ) ;
goto V_38;
}
if ( ! F_3 ( V_19 , V_27 , V_33 ) )
goto V_38;
}
for ( V_9 = 0 ; V_9 < V_19 -> V_39 ; V_9 ++ ) {
T_2 * V_14 = & V_27 [ V_9 * V_32 + V_31 ] ;
bool V_40 ;
type = V_14 [ 0 ] >> 6 ;
if ( type == V_41 )
continue;
if ( V_19 -> V_35 == V_36 && type == V_42 )
continue;
V_28 = ( ( V_14 [ 0 ] << 8 ) | V_14 [ 1 ] ) & 0x0fff ;
V_29 = ( ( V_14 [ 2 ] << 8 ) | V_14 [ 3 ] ) & 0x0fff ;
V_30 = ( V_14 [ 2 ] >> 4 ) & 0x0f ;
V_40 = type != V_43 ;
F_6 ( V_19 -> V_44 , V_30 ) ;
F_7 ( V_19 -> V_44 , V_45 , V_40 ) ;
if ( ! V_40 )
continue;
F_8 ( V_19 -> V_44 , V_46 , V_28 ) ;
F_8 ( V_19 -> V_44 , V_47 , V_29 ) ;
}
F_9 ( V_19 -> V_44 , true ) ;
F_10 ( V_19 -> V_44 ) ;
V_38:
return V_48 ;
}
static int F_11 ( struct V_18 * V_19 ,
T_2 V_11 , T_2 V_49 )
{
T_2 V_50 [ 4 ] ;
switch ( V_19 -> V_35 ) {
case V_36 :
V_50 [ 0 ] = V_19 -> V_51 ? 0xf3 : 0xfc ;
V_50 [ 1 ] = V_19 -> V_51 ? V_11 & 0x7f : V_11 & 0x3f ;
V_50 [ 2 ] = V_49 ;
V_50 [ 3 ] = V_50 [ 0 ] ^ V_50 [ 1 ] ^ V_50 [ 2 ] ;
return F_1 ( V_19 -> V_2 , 4 ,
V_50 , 0 , NULL ) ;
case V_37 :
V_50 [ 0 ] = V_11 ;
V_50 [ 1 ] = V_49 ;
return F_1 ( V_19 -> V_2 , 2 ,
V_50 , 0 , NULL ) ;
default:
return - V_52 ;
}
}
static int F_12 ( struct V_18 * V_19 ,
T_2 V_11 )
{
T_2 V_50 [ 2 ] , V_27 [ 2 ] ;
int error ;
switch ( V_19 -> V_35 ) {
case V_36 :
V_50 [ 0 ] = V_19 -> V_51 ? 0xf3 : 0xfc ;
V_50 [ 1 ] = V_19 -> V_51 ? V_11 & 0x7f : V_11 & 0x3f ;
V_50 [ 1 ] |= V_19 -> V_51 ? 0x80 : 0x40 ;
error = F_1 ( V_19 -> V_2 , 2 , V_50 , 2 ,
V_27 ) ;
if ( error )
return error ;
if ( ( V_50 [ 0 ] ^ V_50 [ 1 ] ^ V_27 [ 0 ] ) != V_27 [ 1 ] ) {
F_13 ( & V_19 -> V_2 -> V_22 ,
L_1 ,
V_50 [ 0 ] ^ V_50 [ 1 ] ^ V_27 [ 0 ] ,
V_27 [ 1 ] ) ;
return - V_17 ;
}
break;
case V_37 :
V_50 [ 0 ] = V_11 ;
error = F_1 ( V_19 -> V_2 , 1 ,
V_50 , 1 , V_27 ) ;
if ( error )
return error ;
break;
default:
return - V_52 ;
}
return V_27 [ 0 ] ;
}
static T_4 F_14 ( struct V_25 * V_22 ,
struct V_53 * V_54 ,
char * V_14 )
{
struct V_1 * V_2 = F_15 ( V_22 ) ;
struct V_18 * V_19 = F_16 ( V_2 ) ;
struct V_55 * V_56 =
F_17 ( V_54 , struct V_55 , V_54 ) ;
T_2 * V_57 = ( T_2 * ) V_19 + V_56 -> V_58 ;
int V_59 ;
T_5 V_60 = 0 ;
int error = 0 ;
T_2 V_11 ;
F_18 ( & V_19 -> V_61 ) ;
if ( V_19 -> V_51 ) {
error = - V_17 ;
goto V_38;
}
switch ( V_19 -> V_35 ) {
case V_36 :
V_11 = V_56 -> V_62 ;
break;
case V_37 :
V_11 = V_56 -> V_63 ;
break;
default:
error = - V_64 ;
goto V_38;
}
if ( V_11 != V_65 ) {
V_59 = F_12 ( V_19 , V_11 ) ;
if ( V_59 < 0 ) {
error = V_59 ;
F_13 ( & V_19 -> V_2 -> V_22 ,
L_4 ,
V_54 -> V_56 . V_66 , error ) ;
goto V_38;
}
} else {
V_59 = * V_57 ;
}
if ( V_59 != * V_57 ) {
F_19 ( & V_19 -> V_2 -> V_22 ,
L_5 ,
V_54 -> V_56 . V_66 , V_59 , * V_57 ) ;
* V_57 = V_59 ;
}
V_60 = F_20 ( V_14 , V_67 , L_6 , V_59 ) ;
V_38:
F_21 ( & V_19 -> V_61 ) ;
return error ? : V_60 ;
}
static T_4 F_22 ( struct V_25 * V_22 ,
struct V_53 * V_54 ,
const char * V_14 , T_5 V_60 )
{
struct V_1 * V_2 = F_15 ( V_22 ) ;
struct V_18 * V_19 = F_16 ( V_2 ) ;
struct V_55 * V_56 =
F_17 ( V_54 , struct V_55 , V_54 ) ;
T_2 * V_57 = ( T_2 * ) V_19 + V_56 -> V_58 ;
unsigned int V_59 ;
int error ;
T_2 V_11 ;
F_18 ( & V_19 -> V_61 ) ;
if ( V_19 -> V_51 ) {
error = - V_17 ;
goto V_38;
}
error = F_23 ( V_14 , 0 , & V_59 ) ;
if ( error )
goto V_38;
if ( V_59 < V_56 -> V_68 || V_59 > V_56 -> V_69 ) {
error = - V_70 ;
goto V_38;
}
switch ( V_19 -> V_35 ) {
case V_36 :
V_11 = V_56 -> V_62 ;
break;
case V_37 :
V_11 = V_56 -> V_63 ;
break;
default:
error = - V_64 ;
goto V_38;
}
if ( V_11 != V_65 ) {
error = F_11 ( V_19 , V_11 , V_59 ) ;
if ( error ) {
F_13 ( & V_19 -> V_2 -> V_22 ,
L_7 ,
V_54 -> V_56 . V_66 , error ) ;
goto V_38;
}
}
* V_57 = V_59 ;
V_38:
F_21 ( & V_19 -> V_61 ) ;
return error ? : V_60 ;
}
static int F_24 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_71 = V_72 ;
int V_10 ;
int error ;
F_25 ( V_2 -> V_23 ) ;
if ( ! V_19 -> V_73 ) {
V_19 -> V_74 = V_19 -> V_75 * V_19 -> V_76 *
sizeof( T_1 ) ;
V_19 -> V_73 = F_26 ( V_19 -> V_74 , V_77 ) ;
if ( ! V_19 -> V_73 ) {
error = - V_78 ;
goto V_79;
}
}
if ( V_19 -> V_35 == V_37 )
goto V_80;
error = F_11 ( V_19 , V_81 , 0x03 ) ;
if ( error ) {
F_13 ( & V_2 -> V_22 ,
L_8 , error ) ;
goto V_79;
}
V_19 -> V_51 = true ;
do {
F_27 ( V_82 ) ;
V_10 = F_12 ( V_19 , V_83 ) ;
if ( V_10 == 0x03 )
break;
} while ( -- V_71 > 0 );
if ( V_71 == 0 ) {
F_13 ( & V_2 -> V_22 , L_9 ,
V_72 * V_82 ) ;
error = - V_17 ;
goto V_79;
}
return 0 ;
V_79:
F_28 ( V_19 -> V_73 ) ;
V_19 -> V_73 = NULL ;
V_19 -> V_51 = false ;
F_29 ( V_2 -> V_23 ) ;
return error ;
V_80:
F_13 ( & V_2 -> V_22 , L_10 ) ;
return - V_52 ;
}
static int F_30 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_71 = V_72 ;
struct V_84 * V_85 = & V_19 -> V_85 ;
int V_10 ;
int error ;
error = F_11 ( V_19 , V_83 , 0x1 ) ;
if ( error ) {
F_13 ( & V_2 -> V_22 ,
L_11 , error ) ;
return error ;
}
V_19 -> V_51 = false ;
do {
F_27 ( V_82 ) ;
V_10 = F_12 ( V_19 , V_81 ) ;
if ( V_10 == 0x01 )
break;
} while ( -- V_71 > 0 );
if ( V_71 == 0 ) {
F_13 ( & V_2 -> V_22 , L_12 ,
V_72 * V_82 ) ;
V_19 -> V_51 = true ;
return - V_17 ;
}
F_28 ( V_19 -> V_73 ) ;
V_19 -> V_73 = NULL ;
F_11 ( V_19 , V_85 -> V_86 ,
V_19 -> V_87 ) ;
F_11 ( V_19 , V_85 -> V_88 ,
V_19 -> V_89 ) ;
F_11 ( V_19 , V_85 -> V_90 ,
V_19 -> V_31 ) ;
if ( V_85 -> V_91 )
F_11 ( V_19 , V_85 -> V_91 ,
V_19 -> V_92 ) ;
F_29 ( V_2 -> V_23 ) ;
return 0 ;
}
static int F_31 ( void * V_93 , T_6 * V_94 )
{
struct V_18 * V_19 = V_93 ;
* V_94 = V_19 -> V_51 ;
return 0 ;
}
static int F_32 ( void * V_93 , T_6 V_94 )
{
struct V_18 * V_19 = V_93 ;
int V_95 = 0 ;
if ( V_94 > 1 )
return - V_70 ;
F_18 ( & V_19 -> V_61 ) ;
if ( V_94 != V_19 -> V_51 ) {
V_95 = V_94 ? F_24 ( V_19 ) :
F_30 ( V_19 ) ;
}
F_21 ( & V_19 -> V_61 ) ;
return V_95 ;
}
static T_4 F_33 ( struct V_96 * V_96 ,
char T_7 * V_14 , T_5 V_60 , T_8 * V_97 )
{
struct V_18 * V_19 = V_96 -> V_98 ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_71 = V_99 ;
int V_59 , V_9 , error ;
T_5 V_100 = 0 ;
int V_101 ;
char V_50 [ 3 ] ;
T_2 * V_27 ;
if ( * V_97 < 0 || * V_97 >= V_19 -> V_74 )
return 0 ;
F_18 ( & V_19 -> V_61 ) ;
if ( ! V_19 -> V_51 || ! V_19 -> V_73 ) {
error = - V_17 ;
goto V_38;
}
error = F_11 ( V_19 , 0x08 , 0x01 ) ;
if ( error ) {
F_34 ( & V_2 -> V_22 ,
L_13 , error ) ;
goto V_38;
}
do {
F_35 ( V_102 ) ;
V_59 = F_12 ( V_19 , 0x08 ) ;
if ( V_59 < 1 )
break;
} while ( -- V_71 > 0 );
if ( V_59 < 0 ) {
error = V_59 ;
F_34 ( & V_2 -> V_22 ,
L_14 , error ) ;
goto V_38;
}
if ( V_71 == 0 ) {
F_34 ( & V_2 -> V_22 ,
L_15 ) ;
error = - V_103 ;
goto V_38;
}
V_27 = V_19 -> V_73 ;
V_101 = V_19 -> V_76 * sizeof( T_1 ) ;
V_50 [ 0 ] = 0xf5 ;
V_50 [ 1 ] = 0x0e ;
for ( V_9 = 0 ; V_9 < V_19 -> V_75 ; V_9 ++ ) {
V_50 [ 2 ] = V_9 ;
error = F_1 ( V_19 -> V_2 ,
sizeof( V_50 ) , V_50 ,
V_101 , V_27 ) ;
if ( error )
goto V_38;
V_27 += V_101 ;
}
V_100 = F_36 ( T_5 , V_60 , V_19 -> V_74 - * V_97 ) ;
if ( F_37 ( V_14 , V_19 -> V_73 + * V_97 , V_100 ) ) {
error = - V_104 ;
goto V_38;
}
* V_97 += V_100 ;
V_38:
F_21 ( & V_19 -> V_61 ) ;
return error ? : V_100 ;
}
static void
F_38 ( struct V_18 * V_19 ,
const char * V_105 )
{
V_19 -> V_106 = F_39 ( V_105 , NULL ) ;
if ( ! V_19 -> V_106 )
return;
F_40 ( L_16 , V_107 , V_19 -> V_106 , & V_19 -> V_75 ) ;
F_40 ( L_17 , V_107 , V_19 -> V_106 , & V_19 -> V_76 ) ;
F_41 ( L_18 , V_107 | V_108 ,
V_19 -> V_106 , V_19 , & V_109 ) ;
F_41 ( L_19 , V_107 ,
V_19 -> V_106 , V_19 , & V_110 ) ;
}
static void
F_42 ( struct V_18 * V_19 )
{
F_43 ( V_19 -> V_106 ) ;
F_28 ( V_19 -> V_73 ) ;
}
static inline void
F_38 ( struct V_18 * V_19 ,
const char * V_105 )
{
}
static inline void
F_42 ( struct V_18 * V_19 )
{
}
static int F_44 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
char * V_111 )
{
T_2 V_27 [ V_112 ] ;
char * V_113 ;
int error ;
char * V_114 = V_19 -> V_66 ;
memset ( V_27 , 0 , sizeof( V_27 ) ) ;
error = F_1 ( V_2 , 1 , L_20 ,
V_112 - 1 , V_27 ) ;
if ( error )
return error ;
if ( ! ( strncasecmp ( V_27 + 1 , L_21 , 3 ) ) ) {
V_19 -> V_35 = V_36 ;
V_27 [ V_112 - 1 ] = '\0' ;
if ( V_27 [ V_112 - 2 ] == '$' )
V_27 [ V_112 - 2 ] = '\0' ;
V_113 = strchr ( V_27 , '*' ) ;
if ( V_113 )
* V_113 ++ = '\0' ;
F_45 ( V_114 , V_27 + 1 , V_112 ) ;
F_45 ( V_111 , V_113 ? V_113 : L_22 , V_112 ) ;
} else {
V_19 -> V_35 = V_37 ;
error = F_1 ( V_2 , 1 , L_23 ,
2 , V_27 ) ;
if ( error )
return error ;
F_45 ( V_111 , V_27 , 2 ) ;
error = F_1 ( V_2 , 1 , L_24 ,
1 , V_27 ) ;
if ( error )
return error ;
snprintf ( V_114 , V_112 , L_25 ,
V_27 [ 0 ] >> 4 , V_27 [ 0 ] & 0x0F ) ;
}
return 0 ;
}
static void F_46 ( struct V_25 * V_22 ,
struct V_18 * V_19 )
{
struct V_84 * V_85 = & V_19 -> V_85 ;
T_9 V_59 ;
int error ;
error = F_47 ( V_22 , L_26 , & V_59 ) ;
if ( ! error )
V_85 -> V_86 = V_59 ;
error = F_47 ( V_22 , L_27 , & V_59 ) ;
if ( ! error )
V_85 -> V_88 = V_59 ;
error = F_47 ( V_22 , L_28 , & V_59 ) ;
if ( ! error )
V_85 -> V_90 = V_59 ;
}
static void
F_48 ( struct V_18 * V_19 )
{
struct V_84 * V_85 = & V_19 -> V_85 ;
V_19 -> V_87 = F_12 ( V_19 ,
V_85 -> V_86 ) ;
V_19 -> V_89 = F_12 ( V_19 , V_85 -> V_88 ) ;
V_19 -> V_31 = F_12 ( V_19 , V_85 -> V_90 ) ;
if ( V_85 -> V_91 != V_65 )
V_19 -> V_92 = F_12 ( V_19 ,
V_85 -> V_91 ) ;
V_19 -> V_75 = F_12 ( V_19 , V_85 -> V_115 ) ;
V_19 -> V_76 = F_12 ( V_19 , V_85 -> V_116 ) ;
}
static void
F_49 ( struct V_18 * V_19 )
{
struct V_84 * V_85 = & V_19 -> V_85 ;
switch ( V_19 -> V_35 ) {
case V_36 :
V_85 -> V_86 = V_117 ;
V_85 -> V_91 = V_118 ;
V_85 -> V_88 = V_119 ;
V_85 -> V_90 = V_120 ;
V_85 -> V_115 = V_121 ;
V_85 -> V_116 = V_122 ;
break;
case V_37 :
V_85 -> V_86 = V_123 ;
V_85 -> V_88 = V_124 ;
V_85 -> V_90 = V_125 ;
V_85 -> V_115 = V_126 ;
V_85 -> V_116 = V_127 ;
break;
}
}
static int F_50 ( struct V_1 * V_2 ,
const struct V_128 * V_30 )
{
const struct V_129 * V_130 ;
struct V_18 * V_19 ;
struct V_131 * V_44 ;
unsigned long V_132 ;
int error ;
char V_111 [ V_112 ] ;
F_34 ( & V_2 -> V_22 , L_29 ) ;
V_19 = F_51 ( & V_2 -> V_22 , sizeof( * V_19 ) , V_77 ) ;
if ( ! V_19 ) {
F_13 ( & V_2 -> V_22 , L_30 ) ;
return - V_78 ;
}
V_130 = F_52 ( & V_2 -> V_22 ) ;
if ( ! V_130 )
V_130 = ( const struct V_129 * ) V_30 -> V_133 ;
if ( ! V_130 || ! V_130 -> V_39 ) {
F_13 ( & V_2 -> V_22 , L_31 ) ;
return - V_52 ;
}
V_19 -> V_39 = V_130 -> V_39 ;
V_19 -> V_134 = F_53 ( & V_2 -> V_22 ,
L_32 , V_135 ) ;
if ( F_54 ( V_19 -> V_134 ) ) {
error = F_55 ( V_19 -> V_134 ) ;
F_13 ( & V_2 -> V_22 ,
L_33 , error ) ;
return error ;
}
V_19 -> V_136 = F_53 ( & V_2 -> V_22 ,
L_34 , V_137 ) ;
if ( F_54 ( V_19 -> V_136 ) ) {
error = F_55 ( V_19 -> V_136 ) ;
F_13 ( & V_2 -> V_22 ,
L_35 , error ) ;
return error ;
}
if ( V_19 -> V_136 ) {
F_56 ( 5000 , 6000 ) ;
F_57 ( V_19 -> V_136 , 1 ) ;
}
if ( V_19 -> V_134 ) {
F_56 ( 5000 , 6000 ) ;
F_57 ( V_19 -> V_134 , 0 ) ;
F_35 ( 300 ) ;
}
V_44 = F_58 ( & V_2 -> V_22 ) ;
if ( ! V_44 ) {
F_13 ( & V_2 -> V_22 , L_36 ) ;
return - V_78 ;
}
F_59 ( & V_19 -> V_61 ) ;
V_19 -> V_2 = V_2 ;
V_19 -> V_44 = V_44 ;
V_19 -> V_51 = false ;
error = F_44 ( V_2 , V_19 , V_111 ) ;
if ( error ) {
F_13 ( & V_2 -> V_22 , L_37 ) ;
return error ;
}
F_49 ( V_19 ) ;
F_46 ( & V_2 -> V_22 , V_19 ) ;
F_48 ( V_19 ) ;
F_34 ( & V_2 -> V_22 ,
L_38 ,
V_19 -> V_66 , V_111 , V_19 -> V_75 , V_19 -> V_76 ) ;
V_44 -> V_66 = V_19 -> V_66 ;
V_44 -> V_30 . V_138 = V_139 ;
V_44 -> V_22 . V_140 = & V_2 -> V_22 ;
F_60 ( V_44 , V_46 ,
0 , V_19 -> V_75 * 64 - 1 , 0 , 0 ) ;
F_60 ( V_44 , V_47 ,
0 , V_19 -> V_76 * 64 - 1 , 0 , 0 ) ;
F_61 ( V_44 , true ) ;
error = F_62 ( V_44 , V_19 -> V_39 ,
V_141 ) ;
if ( error ) {
F_13 ( & V_2 -> V_22 , L_39 ) ;
return error ;
}
F_63 ( V_44 , V_19 ) ;
F_64 ( V_2 , V_19 ) ;
V_132 = F_65 ( V_2 -> V_23 ) ;
if ( V_132 == V_142 )
V_132 = V_143 ;
V_132 |= V_144 ;
error = F_66 ( & V_2 -> V_22 , V_2 -> V_23 ,
NULL , F_5 , V_132 ,
V_2 -> V_66 , V_19 ) ;
if ( error ) {
F_13 ( & V_2 -> V_22 , L_40 ) ;
return error ;
}
error = F_67 ( & V_2 -> V_22 . V_145 , & V_146 ) ;
if ( error )
return error ;
error = F_68 ( V_44 ) ;
if ( error )
goto V_147;
F_38 ( V_19 , F_69 ( & V_2 -> V_22 ) ) ;
F_70 ( & V_2 -> V_22 , 1 ) ;
F_34 ( & V_2 -> V_22 ,
L_41 ,
V_2 -> V_23 ,
V_19 -> V_136 ? F_71 ( V_19 -> V_136 ) : - 1 ,
V_19 -> V_134 ? F_71 ( V_19 -> V_134 ) : - 1 ) ;
return 0 ;
V_147:
F_72 ( & V_2 -> V_22 . V_145 , & V_146 ) ;
return error ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_16 ( V_2 ) ;
F_42 ( V_19 ) ;
F_72 ( & V_2 -> V_22 . V_145 , & V_146 ) ;
return 0 ;
}
static int T_10 F_74 ( struct V_25 * V_22 )
{
struct V_1 * V_2 = F_15 ( V_22 ) ;
if ( F_75 ( V_22 ) )
F_76 ( V_2 -> V_23 ) ;
return 0 ;
}
static int T_10 F_77 ( struct V_25 * V_22 )
{
struct V_1 * V_2 = F_15 ( V_22 ) ;
if ( F_75 ( V_22 ) )
F_78 ( V_2 -> V_23 ) ;
return 0 ;
}
