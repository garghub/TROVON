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
T_2 V_27 [ 29 ] ;
int V_9 , type , V_28 , V_29 , V_30 ;
int V_31 , V_32 , V_33 ;
int error ;
switch ( V_19 -> V_34 ) {
case V_35 :
V_26 = 0xf9 ;
V_31 = 5 ;
V_32 = 4 ;
V_33 = 26 ;
break;
case V_36 :
V_26 = 0x02 ;
V_31 = 1 ;
V_32 = 6 ;
V_33 = 29 ;
break;
default:
goto V_37;
}
memset ( V_27 , 0 , sizeof( V_27 ) ) ;
error = F_1 ( V_19 -> V_2 ,
sizeof( V_26 ) , & V_26 ,
V_33 , V_27 ) ;
if ( error ) {
F_4 ( V_22 , L_2 ,
error ) ;
goto V_37;
}
if ( V_19 -> V_34 == V_35 ) {
if ( V_27 [ 0 ] != 0xaa || V_27 [ 1 ] != 0xaa ||
V_27 [ 2 ] != V_33 ) {
F_4 ( V_22 ,
L_3 ,
V_27 [ 0 ] , V_27 [ 1 ] , V_27 [ 2 ] ) ;
goto V_37;
}
if ( ! F_3 ( V_19 , V_27 , V_33 ) )
goto V_37;
}
for ( V_9 = 0 ; V_9 < V_38 ; V_9 ++ ) {
T_2 * V_14 = & V_27 [ V_9 * V_32 + V_31 ] ;
bool V_39 ;
type = V_14 [ 0 ] >> 6 ;
if ( type == V_40 )
continue;
if ( V_19 -> V_34 == V_35 && type == V_41 )
continue;
V_28 = ( ( V_14 [ 0 ] << 8 ) | V_14 [ 1 ] ) & 0x0fff ;
V_29 = ( ( V_14 [ 2 ] << 8 ) | V_14 [ 3 ] ) & 0x0fff ;
V_30 = ( V_14 [ 2 ] >> 4 ) & 0x0f ;
V_39 = type != V_42 ;
F_6 ( V_19 -> V_43 , V_30 ) ;
F_7 ( V_19 -> V_43 , V_44 , V_39 ) ;
if ( ! V_39 )
continue;
F_8 ( V_19 -> V_43 , V_45 , V_28 ) ;
F_8 ( V_19 -> V_43 , V_46 , V_29 ) ;
}
F_9 ( V_19 -> V_43 , true ) ;
F_10 ( V_19 -> V_43 ) ;
V_37:
return V_47 ;
}
static int F_11 ( struct V_18 * V_19 ,
T_2 V_11 , T_2 V_48 )
{
T_2 V_49 [ 4 ] ;
switch ( V_19 -> V_34 ) {
case V_35 :
V_49 [ 0 ] = V_19 -> V_50 ? 0xf3 : 0xfc ;
V_49 [ 1 ] = V_19 -> V_50 ? V_11 & 0x7f : V_11 & 0x3f ;
V_49 [ 1 ] = V_19 -> V_50 ? V_11 & 0x7f : V_11 & 0x3f ;
V_49 [ 2 ] = V_48 ;
V_49 [ 3 ] = V_49 [ 0 ] ^ V_49 [ 1 ] ^ V_49 [ 2 ] ;
return F_1 ( V_19 -> V_2 , 4 ,
V_49 , 0 , NULL ) ;
case V_36 :
V_49 [ 0 ] = V_11 ;
V_49 [ 1 ] = V_48 ;
return F_1 ( V_19 -> V_2 , 3 ,
V_49 , 0 , NULL ) ;
default:
return - V_51 ;
}
}
static int F_12 ( struct V_18 * V_19 ,
T_2 V_11 )
{
T_2 V_49 [ 2 ] , V_27 [ 2 ] ;
int error ;
switch ( V_19 -> V_34 ) {
case V_35 :
V_49 [ 0 ] = V_19 -> V_50 ? 0xf3 : 0xfc ;
V_49 [ 1 ] = V_19 -> V_50 ? V_11 & 0x7f : V_11 & 0x3f ;
V_49 [ 1 ] |= V_19 -> V_50 ? 0x80 : 0x40 ;
error = F_1 ( V_19 -> V_2 , 2 , V_49 , 2 ,
V_27 ) ;
if ( error )
return error ;
if ( ( V_49 [ 0 ] ^ V_49 [ 1 ] ^ V_27 [ 0 ] ) != V_27 [ 1 ] ) {
F_13 ( & V_19 -> V_2 -> V_22 ,
L_1 ,
V_49 [ 0 ] ^ V_49 [ 1 ] ^ V_27 [ 0 ] ,
V_27 [ 1 ] ) ;
return - V_17 ;
}
break;
case V_36 :
V_49 [ 0 ] = V_11 ;
error = F_1 ( V_19 -> V_2 , 1 ,
V_49 , 1 , V_27 ) ;
if ( error )
return error ;
break;
default:
return - V_51 ;
}
return V_27 [ 0 ] ;
}
static T_4 F_14 ( struct V_25 * V_22 ,
struct V_52 * V_53 ,
char * V_14 )
{
struct V_1 * V_2 = F_15 ( V_22 ) ;
struct V_18 * V_19 = F_16 ( V_2 ) ;
struct V_54 * V_55 =
F_17 ( V_53 , struct V_54 , V_53 ) ;
T_2 * V_56 = ( T_2 * ) V_19 + V_55 -> V_57 ;
int V_58 ;
T_5 V_59 = 0 ;
int error = 0 ;
T_2 V_11 ;
F_18 ( & V_19 -> V_60 ) ;
if ( V_19 -> V_50 ) {
error = - V_17 ;
goto V_37;
}
switch ( V_19 -> V_34 ) {
case V_35 :
V_11 = V_55 -> V_61 ;
break;
case V_36 :
V_11 = V_55 -> V_62 ;
break;
default:
error = - V_63 ;
goto V_37;
}
if ( V_11 != V_64 ) {
V_58 = F_12 ( V_19 , V_11 ) ;
if ( V_58 < 0 ) {
error = V_58 ;
F_13 ( & V_19 -> V_2 -> V_22 ,
L_4 ,
V_53 -> V_55 . V_65 , error ) ;
goto V_37;
}
} else {
V_58 = * V_56 ;
}
if ( V_58 != * V_56 ) {
F_19 ( & V_19 -> V_2 -> V_22 ,
L_5 ,
V_53 -> V_55 . V_65 , V_58 , * V_56 ) ;
* V_56 = V_58 ;
}
V_59 = F_20 ( V_14 , V_66 , L_6 , V_58 ) ;
V_37:
F_21 ( & V_19 -> V_60 ) ;
return error ? : V_59 ;
}
static T_4 F_22 ( struct V_25 * V_22 ,
struct V_52 * V_53 ,
const char * V_14 , T_5 V_59 )
{
struct V_1 * V_2 = F_15 ( V_22 ) ;
struct V_18 * V_19 = F_16 ( V_2 ) ;
struct V_54 * V_55 =
F_17 ( V_53 , struct V_54 , V_53 ) ;
T_2 * V_56 = ( T_2 * ) V_19 + V_55 -> V_57 ;
unsigned int V_58 ;
int error ;
T_2 V_11 ;
F_18 ( & V_19 -> V_60 ) ;
if ( V_19 -> V_50 ) {
error = - V_17 ;
goto V_37;
}
error = F_23 ( V_14 , 0 , & V_58 ) ;
if ( error )
goto V_37;
if ( V_58 < V_55 -> V_67 || V_58 > V_55 -> V_68 ) {
error = - V_69 ;
goto V_37;
}
switch ( V_19 -> V_34 ) {
case V_35 :
V_11 = V_55 -> V_61 ;
break;
case V_36 :
V_11 = V_55 -> V_62 ;
break;
default:
error = - V_63 ;
goto V_37;
}
if ( V_11 != V_64 ) {
error = F_11 ( V_19 , V_11 , V_58 ) ;
if ( error ) {
F_13 ( & V_19 -> V_2 -> V_22 ,
L_7 ,
V_53 -> V_55 . V_65 , error ) ;
goto V_37;
}
}
* V_56 = V_58 ;
V_37:
F_21 ( & V_19 -> V_60 ) ;
return error ? : V_59 ;
}
static int F_24 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_70 = V_71 ;
int V_10 ;
int error ;
F_25 ( V_2 -> V_23 ) ;
if ( ! V_19 -> V_72 ) {
V_19 -> V_73 = V_19 -> V_74 * V_19 -> V_75 *
sizeof( T_1 ) ;
V_19 -> V_72 = F_26 ( V_19 -> V_73 , V_76 ) ;
if ( ! V_19 -> V_72 ) {
error = - V_77 ;
goto V_78;
}
}
if ( V_19 -> V_34 == V_36 )
goto V_79;
error = F_11 ( V_19 , V_80 , 0x03 ) ;
if ( error ) {
F_13 ( & V_2 -> V_22 ,
L_8 , error ) ;
goto V_78;
}
V_19 -> V_50 = true ;
do {
F_27 ( V_81 ) ;
V_10 = F_12 ( V_19 , V_82 ) ;
if ( V_10 == 0x03 )
break;
} while ( -- V_70 > 0 );
if ( V_70 == 0 ) {
F_13 ( & V_2 -> V_22 , L_9 ,
V_71 * V_81 ) ;
error = - V_17 ;
goto V_78;
}
return 0 ;
V_78:
F_28 ( V_19 -> V_72 ) ;
V_19 -> V_72 = NULL ;
V_19 -> V_50 = false ;
F_29 ( V_2 -> V_23 ) ;
return error ;
V_79:
F_13 ( & V_2 -> V_22 , L_10 ) ;
return - V_51 ;
}
static int F_30 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_70 = V_71 ;
struct V_83 * V_84 = & V_19 -> V_84 ;
int V_10 ;
int error ;
error = F_11 ( V_19 , V_82 , 0x1 ) ;
if ( error ) {
F_13 ( & V_2 -> V_22 ,
L_11 , error ) ;
return error ;
}
V_19 -> V_50 = false ;
do {
F_27 ( V_81 ) ;
V_10 = F_12 ( V_19 , V_80 ) ;
if ( V_10 == 0x01 )
break;
} while ( -- V_70 > 0 );
if ( V_70 == 0 ) {
F_13 ( & V_2 -> V_22 , L_12 ,
V_71 * V_81 ) ;
V_19 -> V_50 = true ;
return - V_17 ;
}
F_28 ( V_19 -> V_72 ) ;
V_19 -> V_72 = NULL ;
F_11 ( V_19 , V_84 -> V_85 ,
V_19 -> V_86 ) ;
F_11 ( V_19 , V_84 -> V_87 ,
V_19 -> V_88 ) ;
F_11 ( V_19 , V_84 -> V_89 ,
V_19 -> V_31 ) ;
if ( V_84 -> V_90 )
F_11 ( V_19 , V_84 -> V_90 ,
V_19 -> V_91 ) ;
F_29 ( V_2 -> V_23 ) ;
return 0 ;
}
static int F_31 ( void * V_92 , T_6 * V_93 )
{
struct V_18 * V_19 = V_92 ;
* V_93 = V_19 -> V_50 ;
return 0 ;
}
static int F_32 ( void * V_92 , T_6 V_93 )
{
struct V_18 * V_19 = V_92 ;
int V_94 = 0 ;
if ( V_93 > 1 )
return - V_69 ;
F_18 ( & V_19 -> V_60 ) ;
if ( V_93 != V_19 -> V_50 ) {
V_94 = V_93 ? F_24 ( V_19 ) :
F_30 ( V_19 ) ;
}
F_21 ( & V_19 -> V_60 ) ;
return V_94 ;
}
static T_4 F_33 ( struct V_95 * V_95 ,
char T_7 * V_14 , T_5 V_59 , T_8 * V_96 )
{
struct V_18 * V_19 = V_95 -> V_97 ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_70 = V_98 ;
int V_58 , V_9 , error ;
T_5 V_99 = 0 ;
int V_100 ;
char V_49 [ 3 ] ;
T_2 * V_27 ;
if ( * V_96 < 0 || * V_96 >= V_19 -> V_73 )
return 0 ;
F_18 ( & V_19 -> V_60 ) ;
if ( ! V_19 -> V_50 || ! V_19 -> V_72 ) {
error = - V_17 ;
goto V_37;
}
error = F_11 ( V_19 , 0x08 , 0x01 ) ;
if ( error ) {
F_34 ( & V_2 -> V_22 ,
L_13 , error ) ;
goto V_37;
}
do {
F_35 ( V_101 ) ;
V_58 = F_12 ( V_19 , 0x08 ) ;
if ( V_58 < 1 )
break;
} while ( -- V_70 > 0 );
if ( V_58 < 0 ) {
error = V_58 ;
F_34 ( & V_2 -> V_22 ,
L_14 , error ) ;
goto V_37;
}
if ( V_70 == 0 ) {
F_34 ( & V_2 -> V_22 ,
L_15 ) ;
error = - V_102 ;
goto V_37;
}
V_27 = V_19 -> V_72 ;
V_100 = V_19 -> V_75 * sizeof( T_1 ) ;
V_49 [ 0 ] = 0xf5 ;
V_49 [ 1 ] = 0x0e ;
for ( V_9 = 0 ; V_9 < V_19 -> V_74 ; V_9 ++ ) {
V_49 [ 2 ] = V_9 ;
error = F_1 ( V_19 -> V_2 ,
sizeof( V_49 ) , V_49 ,
V_100 , V_27 ) ;
if ( error )
goto V_37;
V_27 += V_100 ;
}
V_99 = F_36 ( T_5 , V_59 , V_19 -> V_73 - * V_96 ) ;
if ( F_37 ( V_14 , V_19 -> V_72 + * V_96 , V_99 ) ) {
error = - V_103 ;
goto V_37;
}
* V_96 += V_99 ;
V_37:
F_21 ( & V_19 -> V_60 ) ;
return error ? : V_99 ;
}
static void
F_38 ( struct V_18 * V_19 ,
const char * V_104 )
{
V_19 -> V_105 = F_39 ( V_104 , NULL ) ;
if ( ! V_19 -> V_105 )
return;
F_40 ( L_16 , V_106 , V_19 -> V_105 , & V_19 -> V_74 ) ;
F_40 ( L_17 , V_106 , V_19 -> V_105 , & V_19 -> V_75 ) ;
F_41 ( L_18 , V_106 | V_107 ,
V_19 -> V_105 , V_19 , & V_108 ) ;
F_41 ( L_19 , V_106 ,
V_19 -> V_105 , V_19 , & V_109 ) ;
}
static void
F_42 ( struct V_18 * V_19 )
{
if ( V_19 -> V_105 )
F_43 ( V_19 -> V_105 ) ;
F_28 ( V_19 -> V_72 ) ;
}
static inline void
F_38 ( struct V_18 * V_19 ,
const char * V_104 )
{
}
static inline void
F_42 ( struct V_18 * V_19 )
{
}
static int F_44 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
int error ;
if ( F_45 ( V_19 -> V_110 ) ) {
error = F_46 ( & V_2 -> V_22 ,
V_19 -> V_110 , V_111 ,
L_20 ) ;
if ( error ) {
F_13 ( & V_2 -> V_22 ,
L_21 ,
V_19 -> V_110 , error ) ;
return error ;
}
F_35 ( 5 ) ;
F_47 ( V_19 -> V_110 , 1 ) ;
}
if ( F_45 ( V_19 -> V_112 ) ) {
error = F_46 ( & V_2 -> V_22 ,
V_19 -> V_112 , V_111 ,
L_22 ) ;
if ( error ) {
F_13 ( & V_2 -> V_22 ,
L_23 ,
V_19 -> V_112 , error ) ;
return error ;
}
F_35 ( 5 ) ;
F_47 ( V_19 -> V_112 , 1 ) ;
F_35 ( 300 ) ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
char * V_113 )
{
T_2 V_27 [ V_114 ] ;
char * V_115 ;
int error ;
char * V_116 = V_19 -> V_65 ;
memset ( V_27 , 0 , sizeof( V_27 ) ) ;
error = F_1 ( V_2 , 1 , L_24 ,
V_114 - 1 , V_27 ) ;
if ( error )
return error ;
if ( ! ( F_49 ( V_27 + 1 , L_25 , 3 ) ) ) {
V_19 -> V_34 = V_35 ;
V_27 [ V_114 - 1 ] = '\0' ;
if ( V_27 [ V_114 - 2 ] == '$' )
V_27 [ V_114 - 2 ] = '\0' ;
V_115 = strchr ( V_27 , '*' ) ;
if ( V_115 )
* V_115 ++ = '\0' ;
F_50 ( V_116 , V_27 + 1 , V_114 ) ;
F_50 ( V_113 , V_115 ? V_115 : L_26 , V_114 ) ;
} else {
V_19 -> V_34 = V_36 ;
error = F_1 ( V_2 , 1 , L_27 ,
2 , V_27 ) ;
if ( error )
return error ;
F_50 ( V_113 , V_27 , 2 ) ;
error = F_1 ( V_2 , 1 , L_28 ,
1 , V_27 ) ;
if ( error )
return error ;
snprintf ( V_116 , V_114 , L_29 ,
V_27 [ 0 ] >> 4 , V_27 [ 0 ] & 0x0F ) ;
}
return 0 ;
}
static void F_51 ( struct V_117 * V_118 ,
struct V_18 * V_19 )
{
struct V_83 * V_84 = & V_19 -> V_84 ;
F_52 ( V_86 , V_84 -> V_85 ) ;
F_52 ( V_88 , V_84 -> V_87 ) ;
F_52 ( V_31 , V_84 -> V_89 ) ;
}
static void
F_53 ( struct V_18 * V_19 ,
const struct V_119 * V_120 )
{
struct V_83 * V_84 = & V_19 -> V_84 ;
if ( ! V_120 -> V_121 )
return;
F_54 ( V_86 , V_84 -> V_85 ) ;
F_54 ( V_88 , V_84 -> V_87 ) ;
F_54 ( V_31 , V_84 -> V_89 ) ;
if ( V_84 -> V_90 != V_64 )
F_54 ( V_91 , V_84 -> V_90 ) ;
}
static void
F_55 ( struct V_18 * V_19 )
{
struct V_83 * V_84 = & V_19 -> V_84 ;
V_19 -> V_86 = F_12 ( V_19 ,
V_84 -> V_85 ) ;
V_19 -> V_88 = F_12 ( V_19 , V_84 -> V_87 ) ;
V_19 -> V_31 = F_12 ( V_19 , V_84 -> V_89 ) ;
if ( V_84 -> V_90 != V_64 )
V_19 -> V_91 = F_12 ( V_19 ,
V_84 -> V_90 ) ;
V_19 -> V_74 = F_12 ( V_19 , V_84 -> V_122 ) ;
V_19 -> V_75 = F_12 ( V_19 , V_84 -> V_123 ) ;
}
static void
F_56 ( struct V_18 * V_19 )
{
struct V_83 * V_84 = & V_19 -> V_84 ;
switch ( V_19 -> V_34 ) {
case V_35 :
V_84 -> V_85 = V_124 ;
V_84 -> V_90 = V_125 ;
V_84 -> V_87 = V_126 ;
V_84 -> V_89 = V_127 ;
V_84 -> V_122 = V_128 ;
V_84 -> V_123 = V_129 ;
break;
case V_36 :
V_84 -> V_85 = V_130 ;
V_84 -> V_87 = V_131 ;
V_84 -> V_89 = V_132 ;
V_84 -> V_122 = V_133 ;
V_84 -> V_123 = V_134 ;
break;
}
}
static int F_57 ( struct V_25 * V_22 ,
struct V_18 * V_19 )
{
struct V_117 * V_118 = V_22 -> V_135 ;
V_19 -> V_136 = - V_51 ;
V_19 -> V_112 = F_58 ( V_118 , L_30 , 0 ) ;
V_19 -> V_110 = F_58 ( V_118 , L_31 , 0 ) ;
return 0 ;
}
static inline int F_57 ( struct V_25 * V_22 ,
struct V_18 * V_19 )
{
return - V_63 ;
}
static int F_59 ( struct V_1 * V_2 ,
const struct V_137 * V_30 )
{
const struct V_119 * V_120 =
F_60 ( & V_2 -> V_22 ) ;
struct V_18 * V_19 ;
struct V_138 * V_43 ;
int error ;
char V_113 [ V_114 ] ;
F_34 ( & V_2 -> V_22 , L_32 ) ;
V_19 = F_61 ( & V_2 -> V_22 , sizeof( * V_19 ) , V_76 ) ;
if ( ! V_19 ) {
F_13 ( & V_2 -> V_22 , L_33 ) ;
return - V_77 ;
}
if ( ! V_120 ) {
error = F_57 ( & V_2 -> V_22 , V_19 ) ;
if ( error ) {
F_13 ( & V_2 -> V_22 ,
L_34 ) ;
return error ;
}
} else {
V_19 -> V_112 = V_120 -> V_112 ;
V_19 -> V_136 = V_120 -> V_136 ;
V_19 -> V_110 = - V_51 ;
}
error = F_44 ( V_2 , V_19 ) ;
if ( error )
return error ;
if ( F_45 ( V_19 -> V_136 ) ) {
error = F_46 ( & V_2 -> V_22 , V_19 -> V_136 ,
V_139 , L_35 ) ;
if ( error ) {
F_13 ( & V_2 -> V_22 ,
L_36 ,
V_19 -> V_136 , error ) ;
return error ;
}
}
V_43 = F_62 ( & V_2 -> V_22 ) ;
if ( ! V_43 ) {
F_13 ( & V_2 -> V_22 , L_37 ) ;
return - V_77 ;
}
F_63 ( & V_19 -> V_60 ) ;
V_19 -> V_2 = V_2 ;
V_19 -> V_43 = V_43 ;
V_19 -> V_50 = false ;
error = F_48 ( V_2 , V_19 , V_113 ) ;
if ( error ) {
F_13 ( & V_2 -> V_22 , L_38 ) ;
return error ;
}
F_56 ( V_19 ) ;
if ( ! V_120 )
F_51 ( V_2 -> V_22 . V_135 , V_19 ) ;
else
F_53 ( V_19 , V_120 ) ;
F_55 ( V_19 ) ;
F_34 ( & V_2 -> V_22 ,
L_39 ,
V_19 -> V_65 , V_113 , V_19 -> V_74 , V_19 -> V_75 ) ;
V_43 -> V_65 = V_19 -> V_65 ;
V_43 -> V_30 . V_140 = V_141 ;
V_43 -> V_22 . V_142 = & V_2 -> V_22 ;
F_64 ( V_143 , V_43 -> V_144 ) ;
F_64 ( V_145 , V_43 -> V_144 ) ;
F_64 ( V_146 , V_43 -> V_144 ) ;
F_64 ( V_147 , V_43 -> V_148 ) ;
F_65 ( V_43 , V_149 , 0 , V_19 -> V_74 * 64 - 1 , 0 , 0 ) ;
F_65 ( V_43 , V_150 , 0 , V_19 -> V_75 * 64 - 1 , 0 , 0 ) ;
F_65 ( V_43 , V_45 ,
0 , V_19 -> V_74 * 64 - 1 , 0 , 0 ) ;
F_65 ( V_43 , V_46 ,
0 , V_19 -> V_75 * 64 - 1 , 0 , 0 ) ;
error = F_66 ( V_43 , V_38 , 0 ) ;
if ( error ) {
F_13 ( & V_2 -> V_22 , L_40 ) ;
return error ;
}
F_67 ( V_43 , V_19 ) ;
F_68 ( V_2 , V_19 ) ;
error = F_69 ( & V_2 -> V_22 , V_2 -> V_23 , NULL ,
F_5 ,
V_151 | V_152 ,
V_2 -> V_65 , V_19 ) ;
if ( error ) {
F_13 ( & V_2 -> V_22 , L_41 ) ;
return error ;
}
error = F_70 ( & V_2 -> V_22 . V_153 , & V_154 ) ;
if ( error )
return error ;
error = F_71 ( V_43 ) ;
if ( error )
goto V_155;
F_38 ( V_19 , F_72 ( & V_2 -> V_22 ) ) ;
F_73 ( & V_2 -> V_22 , 1 ) ;
F_34 ( & V_2 -> V_22 ,
L_42 ,
V_2 -> V_23 , V_19 -> V_110 , V_19 -> V_112 ) ;
return 0 ;
V_155:
F_74 ( & V_2 -> V_22 . V_153 , & V_154 ) ;
return error ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_16 ( V_2 ) ;
F_42 ( V_19 ) ;
F_74 ( & V_2 -> V_22 . V_153 , & V_154 ) ;
return 0 ;
}
static int F_76 ( struct V_25 * V_22 )
{
struct V_1 * V_2 = F_15 ( V_22 ) ;
if ( F_77 ( V_22 ) )
F_78 ( V_2 -> V_23 ) ;
return 0 ;
}
static int F_79 ( struct V_25 * V_22 )
{
struct V_1 * V_2 = F_15 ( V_22 ) ;
if ( F_77 ( V_22 ) )
F_80 ( V_2 -> V_23 ) ;
return 0 ;
}
