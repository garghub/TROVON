static inline bool F_1 ( struct V_1 * V_1 )
{
if ( V_1 -> V_2 == V_3 && V_1 -> V_4 == V_5 )
return true ;
if ( V_1 -> V_2 == V_6 &&
V_1 -> V_4 >= V_7 &&
V_1 -> V_4 <= V_8 )
return true ;
return false ;
}
static inline bool F_2 ( struct V_1 * V_1 )
{
if ( V_1 -> V_2 == V_3 && V_1 -> V_4 == V_9 )
return true ;
if ( V_1 -> V_2 == V_6 && V_1 -> V_4 == V_10 )
return true ;
return false ;
}
static T_1 F_3 ( struct V_1 * V_1 , T_2 V_11 , T_3 V_12 ,
T_2 * V_13 )
{
struct V_14 * V_15 = V_1 -> V_15 ;
struct V_16 V_17 [] = {
{
. V_18 = V_15 -> V_18 ,
. V_19 = 0 ,
. V_12 = 1 ,
. V_20 = & V_11 ,
} ,
{
. V_18 = V_15 -> V_18 ,
. V_19 = V_21 ,
. V_12 = V_12 ,
. V_20 = V_13 ,
} ,
} ;
int V_22 ;
V_22 = F_4 ( V_15 -> V_23 , V_17 , F_5 ( V_17 ) ) ;
if ( V_22 != F_5 ( V_17 ) )
return V_22 < 0 ? V_22 : - V_24 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_1 , T_2 V_11 ,
T_3 V_12 , const void * V_13 )
{
struct V_14 * V_15 = V_1 -> V_15 ;
char V_20 [ 32 ] ;
int V_22 ;
if ( V_12 > sizeof( V_20 ) - 1 )
return - V_25 ;
V_20 [ 0 ] = V_11 ;
memcpy ( & V_20 [ 1 ] , V_13 , V_12 ) ;
V_22 = F_7 ( V_15 , V_20 , V_12 + 1 ) ;
if ( V_22 != V_12 + 1 )
return V_22 < 0 ? V_22 : - V_24 ;
return 0 ;
}
static T_2 F_8 ( struct V_14 * V_15 )
{
T_2 V_22 = V_26 ;
if ( F_9 ( V_15 -> V_23 , V_27 ) )
V_22 |= V_28 ;
if ( F_9 ( V_15 -> V_23 , V_29 |
V_30 |
V_31 ) )
V_22 |= V_32 ;
return V_22 ;
}
static int F_10 ( struct V_1 * V_1 )
{
T_2 V_33 [ V_34 ] ;
T_2 V_35 [ 32 ] ;
bool V_36 = ( ( V_1 -> V_15 -> V_18 & 0x0001 ) == 0 ) ;
bool V_37 = false ;
int V_38 = 2 ;
int error ;
V_1 -> V_4 = V_39 ;
error = F_11 ( V_1 , V_40 , V_34 ,
V_33 ) ;
if ( V_1 -> V_37 && ( error == - V_41 || error == - V_42 ) ) {
if ( ! V_36 )
error = F_12 ( V_1 ,
V_43 , V_33 ) ;
V_37 = true ;
}
if ( error != V_34 )
goto error;
do {
V_1 -> V_33 [ V_44 ] = V_33 [ V_44 ] ;
V_1 -> V_33 [ V_45 ] = V_33 [ V_45 ] ;
V_1 -> V_33 [ V_46 ] = V_33 [ V_46 ] ;
if ( V_1 -> V_2 == V_47 ||
V_1 -> V_2 == V_6 ) {
error = V_48 . V_49 ( V_1 ,
V_33 , V_34 ) ;
if ( ! error )
goto V_50;
}
if ( ( V_1 -> V_2 == V_47 ||
V_1 -> V_2 == V_3 ) &&
! V_37 && V_36 ) {
error = V_51 . V_49 ( V_1 ,
V_33 , V_34 ) ;
if ( ! error )
goto V_50;
}
if ( ! V_37 ) {
V_35 [ 0 ] = 0x00 ;
V_35 [ 1 ] = 0x00 ;
error = F_6 ( V_1 , 0 , 2 , V_35 ) ;
if ( error )
goto error;
F_13 ( 50 ) ;
error = F_3 ( V_1 , V_40 ,
V_34 , V_33 ) ;
if ( error )
goto error;
}
} while ( -- V_38 > 0 && ! V_37 );
goto error;
V_50:
if ( V_1 -> V_4 <= V_7 )
return - V_52 ;
return 0 ;
error:
return ( error < 0 ) ? error : - V_52 ;
}
int F_14 ( struct V_1 * V_1 , unsigned int V_53 )
{
int error ;
int V_54 = V_53 / 100 ;
do {
error = F_10 ( V_1 ) ;
if ( ! error && V_1 -> V_4 > V_7 )
return 0 ;
F_13 ( 100 ) ;
} while ( V_54 -- );
return ( error == - V_52 || error == - V_41 ) ? - V_41 : error ;
}
static int F_15 ( struct V_1 * V_1 )
{
int error ;
error = F_14 ( V_1 , 4000 ) ;
if ( error )
return error ;
switch ( V_1 -> V_2 ) {
case V_3 :
V_1 -> V_55 = & V_51 ;
break;
case V_6 :
V_1 -> V_55 = & V_48 ;
break;
default:
return - V_56 ;
}
error = V_1 -> V_55 -> V_57 ( V_1 ) ;
if ( ! error && F_2 ( V_1 ) )
V_1 -> V_58 = true ;
else
V_1 -> V_58 = false ;
return error ;
}
static int F_16 ( struct V_1 * V_1 )
{
struct V_59 * V_60 = & V_1 -> V_15 -> V_60 ;
int error ;
error = F_15 ( V_1 ) ;
if ( error ) {
if ( error != - V_41 && error != - V_56 &&
F_1 ( V_1 ) ) {
F_17 ( V_60 , L_1 ) ;
return 0 ;
}
F_18 ( V_60 , L_2 , error ) ;
return error ;
}
return 0 ;
}
static int F_19 ( struct V_61 * V_62 )
{
struct V_1 * V_1 = F_20 ( V_62 ) ;
struct V_14 * V_15 = V_1 -> V_15 ;
int error ;
error = F_21 ( & V_1 -> V_63 ) ;
if ( error )
return error ;
if ( V_1 -> V_58 ) {
error = V_1 -> V_55 -> V_64 ( V_1 ,
V_65 , 0 ) ;
if ( error ) {
F_17 ( & V_15 -> V_60 ,
L_3 , error ) ;
goto V_66;
}
} else {
error = F_22 ( V_1 ) ;
if ( error || ! V_1 -> V_58 ) {
error = error ? error : - V_52 ;
goto V_66;
}
}
F_23 ( V_15 -> V_67 ) ;
if ( ! F_24 ( & V_15 -> V_60 ) ) {
F_25 ( & V_15 -> V_60 ) ;
F_26 ( & V_15 -> V_60 ) ;
}
V_66:
F_27 ( & V_1 -> V_63 ) ;
return error ;
}
static void F_28 ( struct V_61 * V_62 )
{
struct V_1 * V_1 = F_20 ( V_62 ) ;
struct V_14 * V_15 = V_1 -> V_15 ;
F_29 ( & V_1 -> V_63 ) ;
F_30 ( V_15 -> V_67 ) ;
if ( F_24 ( & V_15 -> V_60 ) )
F_31 ( & V_15 -> V_60 ) ;
F_32 ( & V_15 -> V_60 ) ;
if ( V_1 -> V_58 )
V_1 -> V_55 -> V_64 ( V_1 , V_68 , 0 ) ;
F_27 ( & V_1 -> V_63 ) ;
}
static int F_33 ( struct V_1 * V_1 )
{
struct V_59 * V_60 = & V_1 -> V_15 -> V_60 ;
struct V_61 * V_62 ;
int error ;
if ( ! V_1 -> V_69 || ! V_1 -> V_70 )
return - V_71 ;
V_62 = F_34 ( V_60 ) ;
if ( ! V_62 ) {
F_18 ( V_60 , L_4 ) ;
return - V_25 ;
}
V_62 -> V_72 = V_73 ;
V_62 -> V_74 = V_1 -> V_74 ;
V_62 -> V_75 . V_76 = V_77 ;
V_62 -> V_75 . V_78 = 1 ;
V_62 -> V_75 . V_79 = 0 ;
V_62 -> V_60 . V_80 = & V_1 -> V_15 -> V_60 ;
V_62 -> V_81 = F_19 ;
V_62 -> V_82 = F_28 ;
F_35 ( V_62 , V_1 ) ;
F_36 ( V_83 , V_62 -> V_84 ) ;
F_37 ( V_62 , V_85 , 0 , V_1 -> V_86 , 0 ,
0 ) ;
F_37 ( V_62 , V_87 , 0 , V_1 -> V_88 , 0 ,
0 ) ;
F_37 ( V_62 , V_89 , 0 , V_1 -> V_90 , 0 , 0 ) ;
if ( V_1 -> V_2 > V_6 ) {
F_37 ( V_62 , V_91 , 0 , 255 , 0 , 0 ) ;
F_37 ( V_62 , V_92 , 0 , 255 , 0 , 0 ) ;
F_37 ( V_62 , V_93 ,
- 127 , 127 , 0 , 0 ) ;
}
if ( V_1 -> V_2 >= V_3 ) {
F_37 ( V_62 , V_94 , 0 , 255 , 0 , 0 ) ;
F_37 ( V_62 , V_95 , 0 , 255 , 0 , 0 ) ;
}
F_38 ( V_62 , V_85 ,
V_1 -> V_86 / V_1 -> V_69 ) ;
F_38 ( V_62 , V_87 ,
V_1 -> V_88 / V_1 -> V_70 ) ;
if ( V_1 -> V_96 & V_97 )
F_36 ( V_98 , V_62 -> V_99 ) ;
if ( V_1 -> V_96 & V_100 )
F_36 ( V_101 , V_62 -> V_99 ) ;
if ( V_1 -> V_96 & V_102 )
F_36 ( V_103 , V_62 -> V_99 ) ;
if ( V_1 -> V_96 == V_97 )
F_36 ( V_104 , V_62 -> V_105 ) ;
error = F_39 ( V_62 , V_106 ,
V_107 | V_108 ) ;
if ( error ) {
F_18 ( V_60 , L_5 , error ) ;
return error ;
}
error = F_40 ( V_62 ) ;
if ( error ) {
F_18 ( V_60 , L_6 , error ) ;
return error ;
}
V_1 -> V_62 = V_62 ;
return 0 ;
}
static void F_41 ( struct V_1 * V_1 )
{
struct V_61 * V_62 = V_1 -> V_62 ;
if ( ! V_62 || ! V_62 -> V_109 ) {
if ( ! V_62 || V_1 -> V_58 )
V_1 -> V_55 -> V_64 ( V_1 ,
V_65 , 0 ) ;
if ( V_1 -> V_2 >= V_3 )
F_23 ( V_1 -> V_15 -> V_67 ) ;
}
}
static void F_42 ( struct V_1 * V_1 )
{
struct V_61 * V_62 = V_1 -> V_62 ;
if ( ! V_62 || ! V_62 -> V_109 ) {
if ( V_1 -> V_2 >= V_3 )
F_30 ( V_1 -> V_15 -> V_67 ) ;
if ( ! V_62 || V_1 -> V_58 )
V_1 -> V_55 -> V_64 ( V_1 , V_68 , 0 ) ;
}
}
T_2 F_43 ( T_4 V_110 )
{
T_4 V_111 ;
V_110 = F_44 ( V_110 , 20 , 1000 ) ;
V_111 = V_110 < 100 ? V_110 / 10 : V_110 / 20 + 5 ;
return ( V_111 << 2 ) & V_112 ;
}
T_4 F_45 ( T_2 V_113 )
{
T_2 V_111 = V_113 >> 2 ;
return ( V_111 < 10 ) ? V_111 * 10
: ( V_111 - 5 ) * 20 ;
}
static int F_46 ( struct V_1 * V_1 )
{
int error = 0 ;
V_1 -> V_4 = V_39 ;
V_1 -> V_2 = V_47 ;
F_47 ( & V_1 -> V_63 ) ;
V_1 -> V_114 = V_115 ;
V_1 -> V_116 =
F_45 ( V_1 -> V_114 ) ;
error = V_48 . V_117 ( V_1 ) ;
if ( ! error )
error = V_51 . V_117 ( V_1 ) ;
if ( error )
return error ;
error = F_16 ( V_1 ) ;
if ( error )
return error ;
if ( V_1 -> V_58 )
V_1 -> V_55 -> V_64 ( V_1 , V_68 , 0 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_1 )
{
struct V_59 * V_60 = & V_1 -> V_15 -> V_60 ;
struct V_61 * V_62 = V_1 -> V_62 ;
int error ;
if ( F_24 ( V_60 ) )
F_31 ( V_60 ) ;
if ( V_1 -> V_58 )
V_1 -> V_55 -> V_64 ( V_1 , V_65 , 0 ) ;
error = F_16 ( V_1 ) ;
if ( error )
goto V_66;
if ( ! V_62 && V_1 -> V_58 ) {
error = F_33 ( V_1 ) ;
if ( error ) {
F_18 ( V_60 , L_7 ,
error ) ;
goto V_66;
}
}
V_66:
if ( ! V_62 || ! V_62 -> V_109 ) {
if ( V_1 -> V_58 )
V_1 -> V_55 -> V_64 ( V_1 , V_68 , 0 ) ;
} else if ( ! error && V_1 -> V_58 ) {
F_25 ( V_60 ) ;
F_26 ( V_60 ) ;
}
return error ;
}
static T_5 F_48 ( int V_67 , void * V_118 )
{
struct V_1 * V_1 = V_118 ;
struct V_59 * V_60 = & V_1 -> V_15 -> V_60 ;
F_49 ( V_60 ) ;
if ( F_50 ( V_60 ) )
F_51 ( V_60 , 0 ) ;
if ( V_1 -> V_55 -> V_119 ( V_1 ) ) {
if ( ! V_1 -> V_62 ) {
V_1 -> V_55 -> V_120 ( V_1 ,
NULL , NULL , NULL ) ;
goto V_66;
}
if ( ! V_1 -> V_58 || V_1 -> V_55 -> V_121 ( V_1 ) ) {
if ( ! F_52 ( & V_1 -> V_63 ) ) {
V_1 -> V_55 -> V_120 ( V_1 ,
NULL , NULL , NULL ) ;
goto V_66;
}
F_22 ( V_1 ) ;
F_27 ( & V_1 -> V_63 ) ;
}
}
V_66:
F_53 ( V_60 ) ;
F_54 ( V_60 ) ;
return V_122 ;
}
static T_1 F_55 ( struct V_59 * V_60 ,
struct V_123 * V_124 ,
char * V_20 )
{
struct V_1 * V_1 = F_56 ( V_60 ) ;
T_2 V_125 = V_1 -> V_114 ;
T_4 V_110 ;
int V_12 ;
int error ;
error = F_21 ( & V_1 -> V_63 ) ;
if ( error )
return error ;
V_125 = V_1 -> V_114 ;
V_110 = V_1 -> V_116 ;
F_27 ( & V_1 -> V_63 ) ;
switch ( V_125 ) {
case V_126 :
V_12 = F_57 ( V_20 , V_127 , L_8 , V_128 ) ;
break;
case V_68 :
V_12 = F_57 ( V_20 , V_127 , L_8 , V_129 ) ;
break;
default:
V_12 = F_57 ( V_20 , V_127 , L_9 ,
V_1 -> V_2 == V_6 ?
F_45 ( V_125 ) :
V_110 ) ;
break;
}
return V_12 ;
}
static T_1 F_58 ( struct V_59 * V_60 ,
struct V_123 * V_124 ,
const char * V_20 , T_3 V_130 )
{
struct V_1 * V_1 = F_56 ( V_60 ) ;
T_4 V_110 ;
int error ;
error = F_21 ( & V_1 -> V_63 ) ;
if ( error )
return error ;
if ( F_59 ( V_20 , V_128 ) ) {
V_1 -> V_114 = V_126 ;
} else if ( F_59 ( V_20 , V_129 ) ) {
V_1 -> V_114 = V_68 ;
} else if ( ! F_60 ( V_20 , 10 , & V_110 ) ) {
V_1 -> V_116 = F_61 ( T_4 , V_110 , 1000 ) ;
V_1 -> V_114 =
F_43 ( V_1 -> V_116 ) ;
} else {
V_130 = - V_71 ;
}
F_27 ( & V_1 -> V_63 ) ;
return V_130 ;
}
static void F_62 ( void * V_131 )
{
struct V_1 * V_1 = V_131 ;
F_63 ( & V_1 -> V_15 -> V_60 . V_132 ,
& V_133 ) ;
}
static int F_64 ( struct V_1 * V_1 )
{
struct V_14 * V_15 = V_1 -> V_15 ;
struct V_59 * V_60 = & V_15 -> V_60 ;
int error ;
if ( F_65 ( V_60 ) ) {
error = F_66 ( & V_15 -> V_60 . V_132 ,
& V_133 ) ;
if ( error ) {
F_18 ( V_60 , L_10 ,
error ) ;
return error ;
}
error = F_67 ( V_60 ,
F_62 , V_1 ) ;
if ( error ) {
F_62 ( V_1 ) ;
F_18 ( V_60 , L_11 ,
error ) ;
return error ;
}
}
return 0 ;
}
static inline int F_64 ( struct V_1 * V_1 )
{
return 0 ;
}
static T_1 F_68 ( struct V_59 * V_60 ,
struct V_123 * V_124 ,
char * V_20 )
{
struct V_1 * V_1 = F_56 ( V_60 ) ;
T_2 V_125 ;
T_4 V_110 ;
int error ;
error = F_21 ( & V_1 -> V_63 ) ;
if ( error )
return error ;
V_125 = V_1 -> V_134 ;
V_110 = V_1 -> V_135 ;
F_27 ( & V_1 -> V_63 ) ;
return F_57 ( V_20 , V_127 , L_9 ,
V_1 -> V_2 == V_6 ?
F_45 ( V_125 ) :
V_110 ) ;
}
static T_1 F_69 ( struct V_59 * V_60 ,
struct V_123 * V_124 ,
const char * V_20 , T_3 V_130 )
{
struct V_1 * V_1 = F_56 ( V_60 ) ;
T_4 time ;
int error ;
if ( V_20 == NULL || V_130 == 0 || F_60 ( V_20 , 10 , & time ) ) {
F_18 ( V_60 , L_12 ) ;
return - V_71 ;
}
F_49 ( V_60 ) ;
error = F_21 ( & V_1 -> V_63 ) ;
if ( error )
return error ;
V_1 -> V_135 = F_61 ( T_4 , time , 1000 ) ;
V_1 -> V_134 =
F_43 ( V_1 -> V_135 ) ;
F_27 ( & V_1 -> V_63 ) ;
F_54 ( V_60 ) ;
return V_130 ;
}
static void F_70 ( void * V_131 )
{
struct V_1 * V_1 = V_131 ;
F_63 ( & V_1 -> V_15 -> V_60 . V_132 ,
& V_136 ) ;
}
static int F_71 ( struct V_1 * V_1 )
{
struct V_59 * V_60 = & V_1 -> V_15 -> V_60 ;
int error ;
V_1 -> V_134 = V_137 ;
V_1 -> V_135 =
F_45 ( V_1 -> V_134 ) ;
error = F_66 ( & V_60 -> V_132 , & V_136 ) ;
if ( error ) {
F_18 ( V_60 ,
L_13 , error ) ;
return error ;
}
error = F_67 ( V_60 , F_70 , V_1 ) ;
if ( error ) {
F_70 ( V_1 ) ;
F_18 ( V_60 ,
L_14 ,
error ) ;
return error ;
}
F_32 ( V_60 ) ;
F_72 ( V_60 ) ;
F_73 ( V_60 , V_138 ) ;
return 0 ;
}
static inline int F_71 ( struct V_1 * V_1 )
{
return 0 ;
}
static T_1 F_74 ( struct V_59 * V_60 ,
struct V_123 * V_124 , char * V_20 )
{
int error ;
struct V_1 * V_1 = F_56 ( V_60 ) ;
error = F_21 ( & V_1 -> V_63 ) ;
if ( error )
return error ;
error = F_57 ( V_20 , V_127 , L_15 , V_1 -> V_139 ,
V_1 -> V_140 ) ;
F_27 ( & V_1 -> V_63 ) ;
return error ;
}
static T_1 F_75 ( struct V_59 * V_60 ,
struct V_123 * V_124 , char * V_20 )
{
struct V_1 * V_1 = F_56 ( V_60 ) ;
int V_141 ;
int error ;
error = F_21 ( & V_1 -> V_63 ) ;
if ( error )
return error ;
V_141 = F_57 ( V_20 , V_127 , L_8 , V_1 -> V_142 ) ;
F_27 ( & V_1 -> V_63 ) ;
return V_141 ;
}
static int F_76 ( struct V_1 * V_1 , const char * V_143 )
{
struct V_59 * V_60 = & V_1 -> V_15 -> V_60 ;
const struct V_144 * V_145 ;
int error ;
error = F_77 ( & V_145 , V_143 , V_60 ) ;
if ( error ) {
F_18 ( V_60 , L_16 ,
V_143 , error ) ;
return error ;
}
error = V_1 -> V_55 -> V_146 ( V_1 , V_145 ) ;
if ( error ) {
F_18 ( V_60 , L_17 ,
V_143 ) ;
goto V_147;
}
F_49 ( V_60 ) ;
F_41 ( V_1 ) ;
error = V_1 -> V_55 -> V_148 ( V_1 ) ;
if ( error ) {
F_18 ( V_60 , L_18 , error ) ;
goto V_149;
}
error = V_1 -> V_55 -> V_150 ( V_1 ) ;
if ( error ) {
F_18 ( V_60 , L_19 , error ) ;
goto V_149;
}
error = V_1 -> V_55 -> V_151 ( V_1 , V_145 ) ;
if ( error ) {
F_18 ( V_60 , L_20 , error ) ;
goto V_149;
}
error = V_1 -> V_55 -> V_152 ( V_1 , V_145 ) ;
if ( error ) {
F_18 ( V_60 , L_21 , error ) ;
goto V_149;
}
V_149:
F_42 ( V_1 ) ;
F_78 ( V_60 ) ;
V_147:
F_79 ( V_145 ) ;
return error ;
}
static T_1 F_80 ( struct V_59 * V_60 ,
struct V_123 * V_124 ,
const char * V_20 , T_3 V_130 )
{
struct V_1 * V_1 = F_56 ( V_60 ) ;
char V_143 [ V_153 ] ;
int V_22 , error ;
if ( V_130 >= V_153 ) {
F_18 ( V_60 , L_22 ) ;
return - V_71 ;
}
memcpy ( V_143 , V_20 , V_130 ) ;
if ( V_143 [ V_130 - 1 ] == '\n' )
V_143 [ V_130 - 1 ] = '\0' ;
else
V_143 [ V_130 ] = '\0' ;
if ( V_1 -> V_62 ) {
F_81 ( V_1 -> V_62 ) ;
V_1 -> V_62 = NULL ;
}
error = F_21 ( & V_1 -> V_63 ) ;
if ( error ) {
F_22 ( V_1 ) ;
return error ;
}
error = F_76 ( V_1 , V_143 ) ;
if ( error )
F_18 ( V_60 , L_23 , error ) ;
else
F_82 ( V_60 , L_24 ) ;
V_22 = F_22 ( V_1 ) ;
if ( V_22 ) {
F_18 ( V_60 , L_25 , V_22 ) ;
error = error ? error : V_22 ;
}
F_27 ( & V_1 -> V_63 ) ;
return error ? error : V_130 ;
}
static T_1 F_83 ( struct V_59 * V_60 ,
struct V_123 * V_124 ,
const char * V_20 , T_3 V_130 )
{
struct V_1 * V_1 = F_56 ( V_60 ) ;
int error ;
error = F_21 ( & V_1 -> V_63 ) ;
if ( error )
return error ;
if ( V_1 -> V_58 ) {
F_41 ( V_1 ) ;
error = V_1 -> V_55 -> V_154 ( V_60 , V_124 , V_20 , V_130 ) ;
F_42 ( V_1 ) ;
} else {
error = - V_155 ;
}
F_27 ( & V_1 -> V_63 ) ;
return error < 0 ? error : V_130 ;
}
static T_1 F_84 ( struct V_59 * V_60 ,
struct V_123 * V_124 , char * V_20 )
{
struct V_1 * V_1 = F_56 ( V_60 ) ;
T_1 error ;
error = F_21 ( & V_1 -> V_63 ) ;
if ( error )
return error ;
if ( V_1 -> V_58 ) {
F_41 ( V_1 ) ;
error = V_1 -> V_55 -> V_156 ( V_60 , V_124 , V_20 ) ;
F_42 ( V_1 ) ;
} else {
error = - V_155 ;
}
F_27 ( & V_1 -> V_63 ) ;
return error ;
}
static char * F_85 ( struct V_1 * V_1 )
{
switch ( V_1 -> V_4 ) {
case V_7 :
return L_26 ;
case V_157 :
return L_27 ;
case V_8 :
return L_28 ;
case V_5 :
return L_29 ;
case V_10 :
case V_9 :
return L_30 ;
default:
return L_31 ;
}
}
static T_1 F_86 ( struct V_59 * V_60 ,
struct V_123 * V_124 , char * V_20 )
{
struct V_1 * V_1 = F_56 ( V_60 ) ;
int V_141 ;
int error ;
error = F_21 ( & V_1 -> V_63 ) ;
if ( error )
return error ;
V_141 = F_57 ( V_20 , V_127 , L_32 ,
V_1 -> V_2 , F_85 ( V_1 ) ) ;
F_27 ( & V_1 -> V_63 ) ;
return V_141 ;
}
static void F_87 ( void * V_131 )
{
struct V_1 * V_1 = V_131 ;
F_88 ( & V_1 -> V_15 -> V_60 . V_132 , & V_158 ) ;
}
static int F_89 ( struct V_14 * V_15 ,
const struct V_159 * V_118 )
{
struct V_59 * V_60 = & V_15 -> V_60 ;
struct V_1 * V_1 ;
T_2 V_160 ;
union V_161 V_162 ;
int error ;
V_160 = F_8 ( V_15 ) ;
if ( V_160 == V_26 ) {
F_18 ( V_60 , L_33 ) ;
return - V_24 ;
}
if ( F_90 ( V_15 -> V_23 , V_15 -> V_18 , 0 ,
V_163 , 0 , V_164 , & V_162 ) < 0 )
return - V_56 ;
V_1 = F_91 ( V_60 , sizeof( struct V_1 ) , V_165 ) ;
if ( ! V_1 )
return - V_25 ;
if ( V_160 == V_32 )
V_1 -> V_37 = true ;
V_1 -> V_15 = V_15 ;
F_92 ( V_15 , V_1 ) ;
sprintf ( V_1 -> V_74 , L_34 , V_15 -> V_23 -> V_166 ,
V_15 -> V_18 ) ;
error = F_46 ( V_1 ) ;
if ( error ) {
F_18 ( V_60 , L_35 ) ;
return error ;
}
error = F_93 ( & V_15 -> V_60 . V_132 , & V_158 ) ;
if ( error ) {
F_18 ( V_60 , L_36 , error ) ;
return error ;
}
error = F_67 ( V_60 , F_87 , V_1 ) ;
if ( error ) {
F_87 ( V_1 ) ;
F_18 ( V_60 , L_37 , error ) ;
return error ;
}
error = F_64 ( V_1 ) ;
if ( error ) {
F_18 ( V_60 , L_38 , error ) ;
return error ;
}
error = F_71 ( V_1 ) ;
if ( error ) {
F_18 ( V_60 , L_39 , error ) ;
return error ;
}
error = F_94 ( V_60 , V_15 -> V_67 ,
NULL , F_48 ,
V_167 | V_168 ,
L_40 , V_1 ) ;
if ( error ) {
F_18 ( V_60 , L_41 , error ) ;
return error ;
}
F_30 ( V_15 -> V_67 ) ;
if ( V_1 -> V_58 ) {
error = F_33 ( V_1 ) ;
if ( error ) {
F_18 ( V_60 , L_7 ,
error ) ;
return error ;
}
}
return 0 ;
}
static int T_6 F_95 ( struct V_59 * V_60 )
{
struct V_14 * V_15 = F_96 ( V_60 ) ;
struct V_1 * V_1 = F_97 ( V_15 ) ;
T_2 V_169 ;
int error ;
error = F_21 ( & V_1 -> V_63 ) ;
if ( error )
return error ;
if ( F_24 ( V_60 ) )
F_31 ( V_60 ) ;
F_30 ( V_15 -> V_67 ) ;
if ( V_1 -> V_58 ) {
V_169 = F_50 ( V_60 ) ? V_1 -> V_114
: V_68 ;
error = V_1 -> V_55 -> V_64 ( V_1 , V_169 ,
V_1 -> V_116 ) ;
if ( error )
F_18 ( V_60 , L_42 ,
error ) ;
}
if ( F_50 ( V_60 ) )
V_1 -> V_170 = ( F_98 ( V_15 -> V_67 ) == 0 ) ;
F_27 ( & V_1 -> V_63 ) ;
return 0 ;
}
static int T_6 F_99 ( struct V_59 * V_60 )
{
struct V_14 * V_15 = F_96 ( V_60 ) ;
struct V_1 * V_1 = F_97 ( V_15 ) ;
int error ;
F_29 ( & V_1 -> V_63 ) ;
if ( F_50 ( V_60 ) && V_1 -> V_170 ) {
F_100 ( V_15 -> V_67 ) ;
V_1 -> V_170 = false ;
}
error = F_22 ( V_1 ) ;
if ( error )
F_17 ( V_60 , L_43 , error ) ;
F_23 ( V_15 -> V_67 ) ;
F_27 ( & V_1 -> V_63 ) ;
return 0 ;
}
static int T_6 F_101 ( struct V_59 * V_60 )
{
struct V_1 * V_1 = F_56 ( V_60 ) ;
int error ;
error = V_1 -> V_55 -> V_64 ( V_1 ,
V_1 -> V_134 ,
V_1 -> V_135 ) ;
if ( error )
F_17 ( V_60 , L_44 , error ) ;
return 0 ;
}
static int T_6 F_102 ( struct V_59 * V_60 )
{
struct V_1 * V_1 = F_56 ( V_60 ) ;
int error ;
error = V_1 -> V_55 -> V_64 ( V_1 , V_65 , 0 ) ;
if ( error )
F_17 ( V_60 , L_45 , error ) ;
return 0 ;
}
