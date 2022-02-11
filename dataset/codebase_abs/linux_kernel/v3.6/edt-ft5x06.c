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
T_2 V_26 = 0xf9 ;
T_2 V_27 [ 26 ] ;
int V_9 , type , V_28 , V_29 , V_30 ;
int error ;
memset ( V_27 , 0 , sizeof( V_27 ) ) ;
error = F_1 ( V_19 -> V_2 ,
sizeof( V_26 ) , & V_26 ,
sizeof( V_27 ) , V_27 ) ;
if ( error ) {
F_4 ( V_22 , L_2 ,
error ) ;
goto V_31;
}
if ( V_27 [ 0 ] != 0xaa || V_27 [ 1 ] != 0xaa || V_27 [ 2 ] != 26 ) {
F_4 ( V_22 , L_3 ,
V_27 [ 0 ] , V_27 [ 1 ] , V_27 [ 2 ] ) ;
goto V_31;
}
if ( ! F_3 ( V_19 , V_27 , 26 ) )
goto V_31;
for ( V_9 = 0 ; V_9 < V_32 ; V_9 ++ ) {
T_2 * V_14 = & V_27 [ V_9 * 4 + 5 ] ;
bool V_33 ;
type = V_14 [ 0 ] >> 6 ;
if ( type == V_34 )
continue;
V_28 = ( ( V_14 [ 0 ] << 8 ) | V_14 [ 1 ] ) & 0x0fff ;
V_29 = ( ( V_14 [ 2 ] << 8 ) | V_14 [ 3 ] ) & 0x0fff ;
V_30 = ( V_14 [ 2 ] >> 4 ) & 0x0f ;
V_33 = ( type != V_35 ) ;
F_6 ( V_19 -> V_36 , V_30 ) ;
F_7 ( V_19 -> V_36 , V_37 , V_33 ) ;
if ( ! V_33 )
continue;
F_8 ( V_19 -> V_36 , V_38 , V_28 ) ;
F_8 ( V_19 -> V_36 , V_39 , V_29 ) ;
}
F_9 ( V_19 -> V_36 , true ) ;
F_10 ( V_19 -> V_36 ) ;
V_31:
return V_40 ;
}
static int F_11 ( struct V_18 * V_19 ,
T_2 V_11 , T_2 V_41 )
{
T_2 V_42 [ 4 ] ;
V_42 [ 0 ] = V_19 -> V_43 ? 0xf3 : 0xfc ;
V_42 [ 1 ] = V_19 -> V_43 ? V_11 & 0x7f : V_11 & 0x3f ;
V_42 [ 2 ] = V_41 ;
V_42 [ 3 ] = V_42 [ 0 ] ^ V_42 [ 1 ] ^ V_42 [ 2 ] ;
return F_1 ( V_19 -> V_2 , 4 , V_42 , 0 , NULL ) ;
}
static int F_12 ( struct V_18 * V_19 ,
T_2 V_11 )
{
T_2 V_42 [ 2 ] , V_27 [ 2 ] ;
int error ;
V_42 [ 0 ] = V_19 -> V_43 ? 0xf3 : 0xfc ;
V_42 [ 1 ] = V_19 -> V_43 ? V_11 & 0x7f : V_11 & 0x3f ;
V_42 [ 1 ] |= V_19 -> V_43 ? 0x80 : 0x40 ;
error = F_1 ( V_19 -> V_2 , 2 , V_42 , 2 , V_27 ) ;
if ( error )
return error ;
if ( ( V_42 [ 0 ] ^ V_42 [ 1 ] ^ V_27 [ 0 ] ) != V_27 [ 1 ] ) {
F_13 ( & V_19 -> V_2 -> V_22 ,
L_1 ,
V_42 [ 0 ] ^ V_42 [ 1 ] ^ V_27 [ 0 ] , V_27 [ 1 ] ) ;
return - V_17 ;
}
return V_27 [ 0 ] ;
}
static T_4 F_14 ( struct V_25 * V_22 ,
struct V_44 * V_45 ,
char * V_14 )
{
struct V_1 * V_2 = F_15 ( V_22 ) ;
struct V_18 * V_19 = F_16 ( V_2 ) ;
struct V_46 * V_47 =
F_17 ( V_45 , struct V_46 , V_45 ) ;
T_2 * V_48 = ( T_2 * ) ( ( char * ) V_19 + V_47 -> V_49 ) ;
int V_50 ;
T_5 V_51 = 0 ;
int error = 0 ;
F_18 ( & V_19 -> V_52 ) ;
if ( V_19 -> V_43 ) {
error = - V_17 ;
goto V_31;
}
V_50 = F_12 ( V_19 , V_47 -> V_11 ) ;
if ( V_50 < 0 ) {
error = V_50 ;
F_13 ( & V_19 -> V_2 -> V_22 ,
L_4 ,
V_45 -> V_47 . V_53 , error ) ;
goto V_31;
}
if ( V_50 != * V_48 ) {
F_19 ( & V_19 -> V_2 -> V_22 ,
L_5 ,
V_45 -> V_47 . V_53 , V_50 , * V_48 ) ;
* V_48 = V_50 ;
}
V_51 = F_20 ( V_14 , V_54 , L_6 , V_50 ) ;
V_31:
F_21 ( & V_19 -> V_52 ) ;
return error ? : V_51 ;
}
static T_4 F_22 ( struct V_25 * V_22 ,
struct V_44 * V_45 ,
const char * V_14 , T_5 V_51 )
{
struct V_1 * V_2 = F_15 ( V_22 ) ;
struct V_18 * V_19 = F_16 ( V_2 ) ;
struct V_46 * V_47 =
F_17 ( V_45 , struct V_46 , V_45 ) ;
T_2 * V_48 = ( T_2 * ) ( ( char * ) V_19 + V_47 -> V_49 ) ;
unsigned int V_50 ;
int error ;
F_18 ( & V_19 -> V_52 ) ;
if ( V_19 -> V_43 ) {
error = - V_17 ;
goto V_31;
}
error = F_23 ( V_14 , 0 , & V_50 ) ;
if ( error )
goto V_31;
if ( V_50 < V_47 -> V_55 || V_50 > V_47 -> V_56 ) {
error = - V_57 ;
goto V_31;
}
error = F_11 ( V_19 , V_47 -> V_11 , V_50 ) ;
if ( error ) {
F_13 ( & V_19 -> V_2 -> V_22 ,
L_7 ,
V_45 -> V_47 . V_53 , error ) ;
goto V_31;
}
* V_48 = V_50 ;
V_31:
F_21 ( & V_19 -> V_52 ) ;
return error ? : V_51 ;
}
static int F_24 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_58 = V_59 ;
int V_10 ;
int error ;
F_25 ( V_2 -> V_23 ) ;
if ( ! V_19 -> V_60 ) {
V_19 -> V_61 = V_19 -> V_62 * V_19 -> V_63 *
sizeof( T_1 ) ;
V_19 -> V_60 = F_26 ( V_19 -> V_61 , V_64 ) ;
if ( ! V_19 -> V_60 ) {
error = - V_65 ;
goto V_66;
}
}
error = F_11 ( V_19 , V_67 , 0x03 ) ;
if ( error ) {
F_13 ( & V_2 -> V_22 ,
L_8 , error ) ;
goto V_66;
}
V_19 -> V_43 = true ;
do {
F_27 ( V_68 ) ;
V_10 = F_12 ( V_19 , V_69 ) ;
if ( V_10 == 0x03 )
break;
} while ( -- V_58 > 0 );
if ( V_58 == 0 ) {
F_13 ( & V_2 -> V_22 , L_9 ,
V_59 * V_68 ) ;
error = - V_17 ;
goto V_66;
}
return 0 ;
V_66:
F_28 ( V_19 -> V_60 ) ;
V_19 -> V_60 = NULL ;
V_19 -> V_43 = false ;
F_29 ( V_2 -> V_23 ) ;
return error ;
}
static int F_30 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
int V_58 = V_59 ;
int V_10 ;
int error ;
error = F_11 ( V_19 , V_69 , 0x1 ) ;
if ( error ) {
F_13 ( & V_2 -> V_22 ,
L_10 , error ) ;
return error ;
}
V_19 -> V_43 = false ;
do {
F_27 ( V_68 ) ;
V_10 = F_12 ( V_19 , V_67 ) ;
if ( V_10 == 0x01 )
break;
} while ( -- V_58 > 0 );
if ( V_58 == 0 ) {
F_13 ( & V_2 -> V_22 , L_11 ,
V_59 * V_68 ) ;
V_19 -> V_43 = true ;
return - V_17 ;
}
if ( V_19 -> V_60 )
F_28 ( V_19 -> V_60 ) ;
V_19 -> V_60 = NULL ;
F_11 ( V_19 , V_70 ,
V_19 -> V_71 ) ;
F_11 ( V_19 , V_72 ,
V_19 -> V_73 ) ;
F_11 ( V_19 , V_74 ,
V_19 -> V_75 ) ;
F_11 ( V_19 , V_76 ,
V_19 -> V_77 ) ;
F_29 ( V_2 -> V_23 ) ;
return 0 ;
}
static int F_31 ( void * V_78 , T_6 * V_79 )
{
struct V_18 * V_19 = V_78 ;
* V_79 = V_19 -> V_43 ;
return 0 ;
}
static int F_32 ( void * V_78 , T_6 V_79 )
{
struct V_18 * V_19 = V_78 ;
int V_80 = 0 ;
if ( V_79 > 1 )
return - V_57 ;
F_18 ( & V_19 -> V_52 ) ;
if ( V_79 != V_19 -> V_43 ) {
V_80 = V_79 ? F_24 ( V_19 ) :
F_30 ( V_19 ) ;
}
F_21 ( & V_19 -> V_52 ) ;
return V_80 ;
}
static int F_33 ( struct V_81 * V_81 ,
struct V_82 * V_82 )
{
V_82 -> V_83 = V_81 -> V_84 ;
return 0 ;
}
static T_4 F_34 ( struct V_82 * V_82 ,
char T_7 * V_14 , T_5 V_51 , T_8 * V_85 )
{
struct V_18 * V_19 = V_82 -> V_83 ;
struct V_1 * V_2 = V_19 -> V_2 ;
int V_58 = V_86 ;
int V_50 , V_9 , error ;
T_5 V_87 = 0 ;
int V_88 ;
char V_42 [ 3 ] ;
T_2 * V_27 ;
if ( * V_85 < 0 || * V_85 >= V_19 -> V_61 )
return 0 ;
F_18 ( & V_19 -> V_52 ) ;
if ( ! V_19 -> V_43 || ! V_19 -> V_60 ) {
error = - V_17 ;
goto V_31;
}
error = F_11 ( V_19 , 0x08 , 0x01 ) ;
if ( error ) {
F_35 ( & V_2 -> V_22 ,
L_12 , error ) ;
goto V_31;
}
do {
F_36 ( V_89 ) ;
V_50 = F_12 ( V_19 , 0x08 ) ;
if ( V_50 < 1 )
break;
} while ( -- V_58 > 0 );
if ( V_50 < 0 ) {
error = V_50 ;
F_35 ( & V_2 -> V_22 ,
L_13 , error ) ;
goto V_31;
}
if ( V_58 == 0 ) {
F_35 ( & V_2 -> V_22 ,
L_14 ) ;
error = - V_90 ;
goto V_31;
}
V_27 = V_19 -> V_60 ;
V_88 = V_19 -> V_63 * sizeof( T_1 ) ;
V_42 [ 0 ] = 0xf5 ;
V_42 [ 1 ] = 0x0e ;
for ( V_9 = 0 ; V_9 < V_19 -> V_62 ; V_9 ++ ) {
V_42 [ 2 ] = V_9 ;
error = F_1 ( V_19 -> V_2 ,
sizeof( V_42 ) , V_42 ,
V_88 , V_27 ) ;
if ( error )
goto V_31;
V_27 += V_88 ;
}
V_87 = F_37 ( T_5 , V_51 , V_19 -> V_61 - * V_85 ) ;
if ( F_38 ( V_14 , V_19 -> V_60 + * V_85 , V_87 ) ) {
error = - V_91 ;
goto V_31;
}
* V_85 += V_87 ;
V_31:
F_21 ( & V_19 -> V_52 ) ;
return error ? : V_87 ;
}
static void T_9
F_39 ( struct V_18 * V_19 ,
const char * V_92 )
{
V_19 -> V_93 = F_40 ( V_92 , NULL ) ;
if ( ! V_19 -> V_93 )
return;
F_41 ( L_15 , V_94 , V_19 -> V_93 , & V_19 -> V_62 ) ;
F_41 ( L_16 , V_94 , V_19 -> V_93 , & V_19 -> V_63 ) ;
F_42 ( L_17 , V_94 | V_95 ,
V_19 -> V_93 , V_19 , & V_96 ) ;
F_42 ( L_18 , V_94 ,
V_19 -> V_93 , V_19 , & V_97 ) ;
}
static void T_10
F_43 ( struct V_18 * V_19 )
{
if ( V_19 -> V_93 )
F_44 ( V_19 -> V_93 ) ;
F_28 ( V_19 -> V_60 ) ;
}
static inline void
F_39 ( struct V_18 * V_19 ,
const char * V_92 )
{
}
static inline void
F_43 ( struct V_18 * V_19 )
{
}
static int T_9 F_45 ( struct V_1 * V_2 ,
int V_98 )
{
int error ;
if ( F_46 ( V_98 ) ) {
error = F_47 ( V_98 , V_99 ,
L_19 ) ;
if ( error ) {
F_13 ( & V_2 -> V_22 ,
L_20 ,
V_98 , error ) ;
return error ;
}
F_27 ( 50 ) ;
F_48 ( V_98 , 1 ) ;
F_27 ( 100 ) ;
}
return 0 ;
}
static int T_9 F_49 ( struct V_1 * V_2 ,
char * V_100 ,
char * V_101 )
{
T_2 V_27 [ V_102 ] ;
char * V_103 ;
int error ;
error = F_1 ( V_2 , 1 , L_21 ,
V_102 - 1 , V_27 ) ;
if ( error )
return error ;
V_27 [ V_102 - 1 ] = '\0' ;
if ( V_27 [ V_102 - 2 ] == '$' )
V_27 [ V_102 - 2 ] = '\0' ;
V_103 = strchr ( V_27 , '*' ) ;
if ( V_103 )
* V_103 ++ = '\0' ;
F_50 ( V_100 , V_27 + 1 , V_102 ) ;
F_50 ( V_101 , V_103 ? V_103 : L_22 , V_102 ) ;
return 0 ;
}
static void T_9
F_51 ( struct V_18 * V_19 ,
const struct V_104 * V_105 )
{
if ( ! V_105 -> V_106 )
return;
F_52 ( V_71 , V_70 ) ;
F_52 ( V_73 , V_72 ) ;
F_52 ( V_75 , V_74 ) ;
F_52 ( V_77 , V_76 ) ;
}
static void T_9
F_53 ( struct V_18 * V_19 )
{
V_19 -> V_71 = F_12 ( V_19 ,
V_70 ) ;
V_19 -> V_73 = F_12 ( V_19 , V_72 ) ;
V_19 -> V_75 = F_12 ( V_19 , V_74 ) ;
V_19 -> V_77 = F_12 ( V_19 ,
V_76 ) ;
V_19 -> V_62 = F_12 ( V_19 , V_107 ) ;
V_19 -> V_63 = F_12 ( V_19 , V_108 ) ;
}
static int T_9 F_54 ( struct V_1 * V_2 ,
const struct V_109 * V_30 )
{
const struct V_104 * V_105 =
V_2 -> V_22 . V_110 ;
struct V_18 * V_19 ;
struct V_111 * V_36 ;
int error ;
char V_101 [ V_102 ] ;
F_35 ( & V_2 -> V_22 , L_23 ) ;
if ( ! V_105 ) {
F_13 ( & V_2 -> V_22 , L_24 ) ;
return - V_112 ;
}
error = F_45 ( V_2 , V_105 -> V_98 ) ;
if ( error )
return error ;
if ( F_46 ( V_105 -> V_113 ) ) {
error = F_47 ( V_105 -> V_113 ,
V_114 , L_25 ) ;
if ( error ) {
F_13 ( & V_2 -> V_22 ,
L_26 ,
V_105 -> V_113 , error ) ;
return error ;
}
}
V_19 = F_26 ( sizeof( * V_19 ) , V_64 ) ;
V_36 = F_55 () ;
if ( ! V_19 || ! V_36 ) {
F_13 ( & V_2 -> V_22 , L_27 ) ;
error = - V_65 ;
goto V_115;
}
F_56 ( & V_19 -> V_52 ) ;
V_19 -> V_2 = V_2 ;
V_19 -> V_36 = V_36 ;
V_19 -> V_43 = false ;
error = F_49 ( V_2 , V_19 -> V_53 , V_101 ) ;
if ( error ) {
F_13 ( & V_2 -> V_22 , L_28 ) ;
goto V_115;
}
F_51 ( V_19 , V_105 ) ;
F_53 ( V_19 ) ;
F_35 ( & V_2 -> V_22 ,
L_29 ,
V_19 -> V_53 , V_101 , V_19 -> V_62 , V_19 -> V_63 ) ;
V_36 -> V_53 = V_19 -> V_53 ;
V_36 -> V_30 . V_116 = V_117 ;
V_36 -> V_22 . V_118 = & V_2 -> V_22 ;
F_57 ( V_119 , V_36 -> V_120 ) ;
F_57 ( V_121 , V_36 -> V_120 ) ;
F_57 ( V_122 , V_36 -> V_120 ) ;
F_57 ( V_123 , V_36 -> V_124 ) ;
F_58 ( V_36 , V_125 , 0 , V_19 -> V_62 * 64 - 1 , 0 , 0 ) ;
F_58 ( V_36 , V_126 , 0 , V_19 -> V_63 * 64 - 1 , 0 , 0 ) ;
F_58 ( V_36 , V_38 ,
0 , V_19 -> V_62 * 64 - 1 , 0 , 0 ) ;
F_58 ( V_36 , V_39 ,
0 , V_19 -> V_63 * 64 - 1 , 0 , 0 ) ;
error = F_59 ( V_36 , V_32 ) ;
if ( error ) {
F_13 ( & V_2 -> V_22 , L_30 ) ;
goto V_115;
}
F_60 ( V_36 , V_19 ) ;
F_61 ( V_2 , V_19 ) ;
error = F_62 ( V_2 -> V_23 , NULL , F_5 ,
V_127 | V_128 ,
V_2 -> V_53 , V_19 ) ;
if ( error ) {
F_13 ( & V_2 -> V_22 , L_31 ) ;
goto V_115;
}
error = F_63 ( & V_2 -> V_22 . V_129 , & V_130 ) ;
if ( error )
goto V_131;
error = F_64 ( V_36 ) ;
if ( error )
goto V_132;
F_39 ( V_19 , F_65 ( & V_2 -> V_22 ) ) ;
F_66 ( & V_2 -> V_22 , 1 ) ;
F_35 ( & V_2 -> V_22 ,
L_32 ,
V_105 -> V_113 , V_105 -> V_98 ) ;
return 0 ;
V_132:
F_67 ( & V_2 -> V_22 . V_129 , & V_130 ) ;
V_131:
F_68 ( V_2 -> V_23 , V_19 ) ;
V_115:
F_69 ( V_36 ) ;
F_28 ( V_19 ) ;
if ( F_46 ( V_105 -> V_113 ) )
F_70 ( V_105 -> V_113 ) ;
return error ;
}
static int T_10 F_71 ( struct V_1 * V_2 )
{
const struct V_104 * V_105 =
F_72 ( & V_2 -> V_22 ) ;
struct V_18 * V_19 = F_16 ( V_2 ) ;
F_43 ( V_19 ) ;
F_67 ( & V_2 -> V_22 . V_129 , & V_130 ) ;
F_68 ( V_2 -> V_23 , V_19 ) ;
F_73 ( V_19 -> V_36 ) ;
if ( F_46 ( V_105 -> V_113 ) )
F_70 ( V_105 -> V_113 ) ;
if ( F_46 ( V_105 -> V_98 ) )
F_70 ( V_105 -> V_98 ) ;
F_28 ( V_19 ) ;
return 0 ;
}
static int F_74 ( struct V_25 * V_22 )
{
struct V_1 * V_2 = F_15 ( V_22 ) ;
if ( F_75 ( V_22 ) )
F_76 ( V_2 -> V_23 ) ;
return 0 ;
}
static int F_77 ( struct V_25 * V_22 )
{
struct V_1 * V_2 = F_15 ( V_22 ) ;
if ( F_75 ( V_22 ) )
F_78 ( V_2 -> V_23 ) ;
return 0 ;
}
