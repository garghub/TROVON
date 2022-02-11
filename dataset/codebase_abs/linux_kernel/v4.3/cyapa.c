bool F_1 ( struct V_1 * V_1 )
{
if ( V_1 -> V_2 == V_3 && V_1 -> V_4 == V_5 )
return true ;
if ( V_1 -> V_2 == V_6 && V_1 -> V_4 == V_7 )
return true ;
return false ;
}
bool F_2 ( struct V_1 * V_1 )
{
if ( V_1 -> V_2 == V_3 && V_1 -> V_4 == V_8 )
return true ;
if ( V_1 -> V_2 == V_6 && V_1 -> V_4 == V_9 )
return true ;
return false ;
}
static bool F_3 ( struct V_1 * V_1 )
{
if ( F_1 ( V_1 ) )
return true ;
if ( V_1 -> V_2 == V_10 &&
V_1 -> V_4 >= V_11 &&
V_1 -> V_4 <= V_12 )
return true ;
return false ;
}
static inline bool F_4 ( struct V_1 * V_1 )
{
if ( F_2 ( V_1 ) )
return true ;
if ( V_1 -> V_2 == V_10 && V_1 -> V_4 == V_13 )
return true ;
return false ;
}
static T_1 F_5 ( struct V_1 * V_1 , T_2 V_14 , T_3 V_15 ,
T_2 * V_16 )
{
struct V_17 * V_18 = V_1 -> V_18 ;
struct V_19 V_20 [] = {
{
. V_21 = V_18 -> V_21 ,
. V_22 = 0 ,
. V_15 = 1 ,
. V_23 = & V_14 ,
} ,
{
. V_21 = V_18 -> V_21 ,
. V_22 = V_24 ,
. V_15 = V_15 ,
. V_23 = V_16 ,
} ,
} ;
int V_25 ;
V_25 = F_6 ( V_18 -> V_26 , V_20 , F_7 ( V_20 ) ) ;
if ( V_25 != F_7 ( V_20 ) )
return V_25 < 0 ? V_25 : - V_27 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_1 , T_2 V_14 ,
T_3 V_15 , const void * V_16 )
{
struct V_17 * V_18 = V_1 -> V_18 ;
char V_23 [ 32 ] ;
int V_25 ;
if ( V_15 > sizeof( V_23 ) - 1 )
return - V_28 ;
V_23 [ 0 ] = V_14 ;
memcpy ( & V_23 [ 1 ] , V_16 , V_15 ) ;
V_25 = F_9 ( V_18 , V_23 , V_15 + 1 ) ;
if ( V_25 != V_15 + 1 )
return V_25 < 0 ? V_25 : - V_27 ;
return 0 ;
}
static T_2 F_10 ( struct V_17 * V_18 )
{
T_2 V_25 = V_29 ;
if ( F_11 ( V_18 -> V_26 , V_30 ) )
V_25 |= V_31 ;
if ( F_11 ( V_18 -> V_26 , V_32 |
V_33 |
V_34 ) )
V_25 |= V_35 ;
return V_25 ;
}
static int F_12 ( struct V_1 * V_1 )
{
T_2 V_36 [ V_37 ] ;
T_2 V_38 [ 32 ] ;
bool V_39 = ( ( V_1 -> V_18 -> V_21 & 0x0001 ) == 0 ) ;
bool V_40 = false ;
int V_41 = 2 ;
int error ;
V_1 -> V_4 = V_42 ;
error = F_13 ( V_1 , V_43 , V_37 ,
V_36 ) ;
if ( V_1 -> V_40 && ( error == - V_44 || error == - V_45 ) ) {
if ( ! V_39 )
error = F_14 ( V_1 ,
V_46 , V_36 ) ;
V_40 = true ;
}
if ( error != V_37 )
goto error;
do {
V_1 -> V_36 [ V_47 ] = V_36 [ V_47 ] ;
V_1 -> V_36 [ V_48 ] = V_36 [ V_48 ] ;
V_1 -> V_36 [ V_49 ] = V_36 [ V_49 ] ;
if ( V_1 -> V_2 == V_50 ||
V_1 -> V_2 == V_10 ) {
error = V_51 . V_52 ( V_1 ,
V_36 , V_37 ) ;
if ( ! error )
goto V_53;
}
if ( V_1 -> V_2 == V_50 ||
V_1 -> V_2 == V_3 ||
V_1 -> V_2 == V_6 ) {
error = F_15 ( V_1 ,
V_36 , V_37 ) ;
if ( ! error )
goto V_53;
}
if ( ( V_1 -> V_2 == V_50 ||
V_1 -> V_2 == V_6 ) &&
! V_40 && V_39 ) {
error = V_54 . V_52 ( V_1 ,
V_36 , V_37 ) ;
if ( ! error )
goto V_53;
}
if ( ! V_40 ) {
V_38 [ 0 ] = 0x00 ;
V_38 [ 1 ] = 0x00 ;
error = F_8 ( V_1 , 0 , 2 , V_38 ) ;
if ( error )
goto error;
F_16 ( 50 ) ;
error = F_5 ( V_1 , V_43 ,
V_37 , V_36 ) ;
if ( error )
goto error;
}
} while ( -- V_41 > 0 && ! V_40 );
goto error;
V_53:
if ( V_1 -> V_4 <= V_11 )
return - V_55 ;
return 0 ;
error:
return ( error < 0 ) ? error : - V_55 ;
}
int F_17 ( struct V_1 * V_1 , unsigned int V_56 )
{
int error ;
int V_57 = V_56 / 100 ;
do {
error = F_12 ( V_1 ) ;
if ( ! error && V_1 -> V_4 > V_11 )
return 0 ;
F_16 ( 100 ) ;
} while ( V_57 -- );
return ( error == - V_55 || error == - V_44 ) ? - V_44 : error ;
}
static int F_18 ( struct V_1 * V_1 )
{
int error ;
error = F_17 ( V_1 , 4000 ) ;
if ( error )
return error ;
switch ( V_1 -> V_2 ) {
case V_3 :
V_1 -> V_58 = & V_59 ;
break;
case V_6 :
V_1 -> V_58 = & V_54 ;
break;
case V_10 :
V_1 -> V_58 = & V_51 ;
break;
default:
return - V_60 ;
}
error = V_1 -> V_58 -> V_61 ( V_1 ) ;
if ( ! error && F_4 ( V_1 ) )
V_1 -> V_62 = true ;
else
V_1 -> V_62 = false ;
return error ;
}
static int F_19 ( struct V_1 * V_1 )
{
struct V_63 * V_64 = & V_1 -> V_18 -> V_64 ;
int error ;
error = F_18 ( V_1 ) ;
if ( error ) {
if ( error != - V_44 && error != - V_60 &&
F_3 ( V_1 ) ) {
F_20 ( V_64 , L_1 ) ;
return 0 ;
}
F_21 ( V_64 , L_2 , error ) ;
return error ;
}
return 0 ;
}
static int F_22 ( struct V_65 * V_66 )
{
struct V_1 * V_1 = F_23 ( V_66 ) ;
struct V_17 * V_18 = V_1 -> V_18 ;
struct V_63 * V_64 = & V_18 -> V_64 ;
int error ;
error = F_24 ( & V_1 -> V_67 ) ;
if ( error )
return error ;
if ( V_1 -> V_62 ) {
error = V_1 -> V_58 -> V_68 ( V_1 ,
V_69 , 0 , false ) ;
if ( error ) {
F_20 ( V_64 , L_3 , error ) ;
goto V_70;
}
} else {
error = F_25 ( V_1 ) ;
if ( error || ! V_1 -> V_62 ) {
error = error ? error : - V_55 ;
goto V_70;
}
}
F_26 ( V_18 -> V_71 ) ;
if ( ! F_27 ( V_64 ) ) {
F_28 ( V_64 ) ;
F_29 ( V_64 ) ;
}
F_30 ( V_64 ) ;
F_31 ( V_64 ) ;
F_32 ( V_64 ) ;
V_70:
F_33 ( & V_1 -> V_67 ) ;
return error ;
}
static void F_34 ( struct V_65 * V_66 )
{
struct V_1 * V_1 = F_23 ( V_66 ) ;
struct V_17 * V_18 = V_1 -> V_18 ;
struct V_63 * V_64 = & V_1 -> V_18 -> V_64 ;
F_35 ( & V_1 -> V_67 ) ;
F_36 ( V_18 -> V_71 ) ;
if ( F_27 ( V_64 ) )
F_37 ( V_64 ) ;
F_38 ( V_64 ) ;
if ( V_1 -> V_62 )
V_1 -> V_58 -> V_68 ( V_1 , V_72 , 0 , false ) ;
F_33 ( & V_1 -> V_67 ) ;
}
static int F_39 ( struct V_1 * V_1 )
{
struct V_63 * V_64 = & V_1 -> V_18 -> V_64 ;
struct V_65 * V_66 ;
int error ;
if ( ! V_1 -> V_73 || ! V_1 -> V_74 )
return - V_75 ;
V_66 = F_40 ( V_64 ) ;
if ( ! V_66 ) {
F_21 ( V_64 , L_4 ) ;
return - V_28 ;
}
V_66 -> V_76 = V_77 ;
V_66 -> V_78 = V_1 -> V_78 ;
V_66 -> V_79 . V_80 = V_81 ;
V_66 -> V_79 . V_82 = 1 ;
V_66 -> V_79 . V_83 = 0 ;
V_66 -> V_64 . V_84 = & V_1 -> V_18 -> V_64 ;
V_66 -> V_85 = F_22 ;
V_66 -> V_86 = F_34 ;
F_41 ( V_66 , V_1 ) ;
F_42 ( V_87 , V_66 -> V_88 ) ;
F_43 ( V_66 , V_89 , 0 , V_1 -> V_90 , 0 ,
0 ) ;
F_43 ( V_66 , V_91 , 0 , V_1 -> V_92 , 0 ,
0 ) ;
F_43 ( V_66 , V_93 , 0 , V_1 -> V_94 , 0 , 0 ) ;
if ( V_1 -> V_2 > V_10 ) {
F_43 ( V_66 , V_95 , 0 , 255 , 0 , 0 ) ;
F_43 ( V_66 , V_96 , 0 , 255 , 0 , 0 ) ;
F_43 ( V_66 , V_97 ,
- 127 , 127 , 0 , 0 ) ;
}
if ( V_1 -> V_2 >= V_6 ) {
F_43 ( V_66 , V_98 , 0 , 255 , 0 , 0 ) ;
F_43 ( V_66 , V_99 , 0 , 255 , 0 , 0 ) ;
F_43 ( V_66 , V_100 , 0 , 1 , 0 , 0 ) ;
}
F_44 ( V_66 , V_89 ,
V_1 -> V_90 / V_1 -> V_73 ) ;
F_44 ( V_66 , V_91 ,
V_1 -> V_92 / V_1 -> V_74 ) ;
if ( V_1 -> V_101 & V_102 )
F_42 ( V_103 , V_66 -> V_104 ) ;
if ( V_1 -> V_101 & V_105 )
F_42 ( V_106 , V_66 -> V_104 ) ;
if ( V_1 -> V_101 & V_107 )
F_42 ( V_108 , V_66 -> V_104 ) ;
if ( V_1 -> V_101 == V_102 )
F_42 ( V_109 , V_66 -> V_110 ) ;
error = F_45 ( V_66 , V_111 ,
V_112 | V_113 ) ;
if ( error ) {
F_21 ( V_64 , L_5 , error ) ;
return error ;
}
error = F_46 ( V_66 ) ;
if ( error ) {
F_21 ( V_64 , L_6 , error ) ;
return error ;
}
V_1 -> V_66 = V_66 ;
return 0 ;
}
static void F_47 ( struct V_1 * V_1 )
{
struct V_65 * V_66 = V_1 -> V_66 ;
if ( ! V_66 || ! V_66 -> V_114 ) {
if ( ! V_66 || V_1 -> V_62 )
V_1 -> V_58 -> V_68 ( V_1 ,
V_69 , 0 , false ) ;
if ( V_1 -> V_2 >= V_6 )
F_26 ( V_1 -> V_18 -> V_71 ) ;
}
}
static void F_48 ( struct V_1 * V_1 )
{
struct V_65 * V_66 = V_1 -> V_66 ;
if ( ! V_66 || ! V_66 -> V_114 ) {
if ( V_1 -> V_2 >= V_6 )
F_36 ( V_1 -> V_18 -> V_71 ) ;
if ( ! V_66 || V_1 -> V_62 )
V_1 -> V_58 -> V_68 ( V_1 ,
V_72 , 0 , false ) ;
}
}
T_2 F_49 ( T_4 V_115 )
{
T_4 V_116 ;
V_115 = F_50 ( V_115 , 20 , 1000 ) ;
V_116 = V_115 < 100 ? V_115 / 10 : V_115 / 20 + 5 ;
return ( V_116 << 2 ) & V_117 ;
}
T_4 F_51 ( T_2 V_118 )
{
T_2 V_116 = V_118 >> 2 ;
return ( V_116 < 10 ) ? V_116 * 10
: ( V_116 - 5 ) * 20 ;
}
static int F_52 ( struct V_1 * V_1 )
{
int error = 0 ;
V_1 -> V_4 = V_42 ;
V_1 -> V_2 = V_50 ;
F_53 ( & V_1 -> V_67 ) ;
V_1 -> V_119 = V_120 ;
V_1 -> V_121 =
F_51 ( V_1 -> V_119 ) ;
error = V_51 . V_122 ( V_1 ) ;
if ( ! error )
error = V_54 . V_122 ( V_1 ) ;
if ( ! error )
error = V_59 . V_122 ( V_1 ) ;
if ( error )
return error ;
error = F_19 ( V_1 ) ;
if ( error )
return error ;
if ( V_1 -> V_62 )
V_1 -> V_58 -> V_68 ( V_1 , V_72 , 0 , false ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_1 )
{
struct V_63 * V_64 = & V_1 -> V_18 -> V_64 ;
struct V_65 * V_66 = V_1 -> V_66 ;
int error ;
if ( F_27 ( V_64 ) )
F_37 ( V_64 ) ;
if ( V_1 -> V_62 )
V_1 -> V_58 -> V_68 ( V_1 ,
V_69 , 0 , false ) ;
error = F_19 ( V_1 ) ;
if ( error )
goto V_70;
if ( ! V_66 && V_1 -> V_62 ) {
error = F_39 ( V_1 ) ;
if ( error ) {
F_21 ( V_64 , L_7 ,
error ) ;
goto V_70;
}
}
V_70:
if ( ! V_66 || ! V_66 -> V_114 ) {
if ( V_1 -> V_62 )
V_1 -> V_58 -> V_68 ( V_1 ,
V_72 , 0 , false ) ;
} else if ( ! error && V_1 -> V_62 ) {
F_28 ( V_64 ) ;
F_29 ( V_64 ) ;
F_30 ( V_64 ) ;
F_31 ( V_64 ) ;
F_32 ( V_64 ) ;
}
return error ;
}
static T_5 F_54 ( int V_71 , void * V_123 )
{
struct V_1 * V_1 = V_123 ;
struct V_63 * V_64 = & V_1 -> V_18 -> V_64 ;
int error ;
if ( F_55 ( V_64 ) )
F_56 ( V_64 , 0 ) ;
if ( V_1 -> V_58 -> V_124 ( V_1 ) ) {
if ( ! V_1 -> V_66 ) {
V_1 -> V_58 -> V_125 ( V_1 ,
NULL , NULL , NULL ) ;
goto V_70;
}
if ( V_1 -> V_62 ) {
error = V_1 -> V_58 -> V_126 ( V_1 ) ;
F_30 ( V_64 ) ;
F_31 ( V_64 ) ;
F_32 ( V_64 ) ;
}
if ( ! V_1 -> V_62 || error ) {
if ( ! F_57 ( & V_1 -> V_67 ) ) {
V_1 -> V_58 -> V_125 ( V_1 ,
NULL , NULL , NULL ) ;
goto V_70;
}
F_25 ( V_1 ) ;
F_33 ( & V_1 -> V_67 ) ;
}
}
V_70:
return V_127 ;
}
static T_1 F_58 ( struct V_63 * V_64 ,
struct V_128 * V_129 ,
char * V_23 )
{
struct V_1 * V_1 = F_59 ( V_64 ) ;
T_2 V_130 = V_1 -> V_119 ;
T_4 V_115 ;
int V_15 ;
int error ;
error = F_24 ( & V_1 -> V_67 ) ;
if ( error )
return error ;
V_130 = V_1 -> V_119 ;
V_115 = V_1 -> V_121 ;
F_33 ( & V_1 -> V_67 ) ;
switch ( V_130 ) {
case V_131 :
V_15 = F_60 ( V_23 , V_132 , L_8 , V_133 ) ;
break;
case V_72 :
V_15 = F_60 ( V_23 , V_132 , L_8 , V_134 ) ;
break;
default:
V_15 = F_60 ( V_23 , V_132 , L_9 ,
V_1 -> V_2 == V_10 ?
F_51 ( V_130 ) :
V_115 ) ;
break;
}
return V_15 ;
}
static T_1 F_61 ( struct V_63 * V_64 ,
struct V_128 * V_129 ,
const char * V_23 , T_3 V_135 )
{
struct V_1 * V_1 = F_59 ( V_64 ) ;
T_4 V_115 ;
int error ;
error = F_24 ( & V_1 -> V_67 ) ;
if ( error )
return error ;
if ( F_62 ( V_23 , V_133 ) ) {
V_1 -> V_119 = V_131 ;
} else if ( F_62 ( V_23 , V_134 ) ) {
V_1 -> V_119 = V_72 ;
} else if ( ! F_63 ( V_23 , 10 , & V_115 ) ) {
V_1 -> V_121 = F_64 ( T_4 , V_115 , 1000 ) ;
V_1 -> V_119 =
F_49 ( V_1 -> V_121 ) ;
} else {
V_135 = - V_75 ;
}
F_33 ( & V_1 -> V_67 ) ;
return V_135 ;
}
static void F_65 ( void * V_136 )
{
struct V_1 * V_1 = V_136 ;
F_66 ( & V_1 -> V_18 -> V_64 . V_137 ,
& V_138 ) ;
}
static int F_67 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = V_1 -> V_18 ;
struct V_63 * V_64 = & V_18 -> V_64 ;
int error ;
if ( F_68 ( V_64 ) ) {
error = F_69 ( & V_18 -> V_64 . V_137 ,
& V_138 ) ;
if ( error ) {
F_21 ( V_64 , L_10 ,
error ) ;
return error ;
}
error = F_70 ( V_64 ,
F_65 , V_1 ) ;
if ( error ) {
F_65 ( V_1 ) ;
F_21 ( V_64 , L_11 ,
error ) ;
return error ;
}
}
return 0 ;
}
static inline int F_67 ( struct V_1 * V_1 )
{
return 0 ;
}
static T_1 F_71 ( struct V_63 * V_64 ,
struct V_128 * V_129 ,
char * V_23 )
{
struct V_1 * V_1 = F_59 ( V_64 ) ;
T_2 V_130 ;
T_4 V_115 ;
int error ;
error = F_24 ( & V_1 -> V_67 ) ;
if ( error )
return error ;
V_130 = V_1 -> V_139 ;
V_115 = V_1 -> V_140 ;
F_33 ( & V_1 -> V_67 ) ;
return F_60 ( V_23 , V_132 , L_9 ,
V_1 -> V_2 == V_10 ?
F_51 ( V_130 ) :
V_115 ) ;
}
static T_1 F_72 ( struct V_63 * V_64 ,
struct V_128 * V_129 ,
const char * V_23 , T_3 V_135 )
{
struct V_1 * V_1 = F_59 ( V_64 ) ;
T_4 time ;
int error ;
if ( V_23 == NULL || V_135 == 0 || F_63 ( V_23 , 10 , & time ) ) {
F_21 ( V_64 , L_12 ) ;
return - V_75 ;
}
F_30 ( V_64 ) ;
error = F_24 ( & V_1 -> V_67 ) ;
if ( error )
return error ;
V_1 -> V_140 = F_64 ( T_4 , time , 1000 ) ;
V_1 -> V_139 =
F_49 ( V_1 -> V_140 ) ;
F_33 ( & V_1 -> V_67 ) ;
F_32 ( V_64 ) ;
return V_135 ;
}
static void F_73 ( void * V_136 )
{
struct V_1 * V_1 = V_136 ;
F_66 ( & V_1 -> V_18 -> V_64 . V_137 ,
& V_141 ) ;
}
static int F_74 ( struct V_1 * V_1 )
{
struct V_63 * V_64 = & V_1 -> V_18 -> V_64 ;
int error ;
V_1 -> V_139 = V_142 ;
V_1 -> V_140 =
F_51 ( V_1 -> V_139 ) ;
error = F_69 ( & V_64 -> V_137 , & V_141 ) ;
if ( error ) {
F_21 ( V_64 ,
L_13 , error ) ;
return error ;
}
error = F_70 ( V_64 , F_73 , V_1 ) ;
if ( error ) {
F_73 ( V_1 ) ;
F_21 ( V_64 ,
L_14 ,
error ) ;
return error ;
}
F_38 ( V_64 ) ;
F_75 ( V_64 ) ;
F_76 ( V_64 , V_143 ) ;
return 0 ;
}
static inline int F_74 ( struct V_1 * V_1 )
{
return 0 ;
}
static T_1 F_77 ( struct V_63 * V_64 ,
struct V_128 * V_129 , char * V_23 )
{
int error ;
struct V_1 * V_1 = F_59 ( V_64 ) ;
error = F_24 ( & V_1 -> V_67 ) ;
if ( error )
return error ;
error = F_60 ( V_23 , V_132 , L_15 , V_1 -> V_144 ,
V_1 -> V_145 ) ;
F_33 ( & V_1 -> V_67 ) ;
return error ;
}
static T_1 F_78 ( struct V_63 * V_64 ,
struct V_128 * V_129 , char * V_23 )
{
struct V_1 * V_1 = F_59 ( V_64 ) ;
int V_146 ;
int error ;
error = F_24 ( & V_1 -> V_67 ) ;
if ( error )
return error ;
V_146 = F_60 ( V_23 , V_132 , L_8 , V_1 -> V_147 ) ;
F_33 ( & V_1 -> V_67 ) ;
return V_146 ;
}
static int F_79 ( struct V_1 * V_1 , const char * V_148 )
{
struct V_63 * V_64 = & V_1 -> V_18 -> V_64 ;
const struct V_149 * V_150 ;
int error ;
error = F_80 ( & V_150 , V_148 , V_64 ) ;
if ( error ) {
F_21 ( V_64 , L_16 ,
V_148 , error ) ;
return error ;
}
error = V_1 -> V_58 -> V_151 ( V_1 , V_150 ) ;
if ( error ) {
F_21 ( V_64 , L_17 ,
V_148 ) ;
goto V_152;
}
F_30 ( V_64 ) ;
F_47 ( V_1 ) ;
error = V_1 -> V_58 -> V_153 ( V_1 ) ;
if ( error ) {
F_21 ( V_64 , L_18 , error ) ;
goto V_154;
}
error = V_1 -> V_58 -> V_155 ( V_1 ) ;
if ( error ) {
F_21 ( V_64 , L_19 , error ) ;
goto V_154;
}
error = V_1 -> V_58 -> V_156 ( V_1 , V_150 ) ;
if ( error ) {
F_21 ( V_64 , L_20 , error ) ;
goto V_154;
}
error = V_1 -> V_58 -> V_157 ( V_1 , V_150 ) ;
if ( error ) {
F_21 ( V_64 , L_21 , error ) ;
goto V_154;
}
V_154:
F_48 ( V_1 ) ;
F_81 ( V_64 ) ;
V_152:
F_82 ( V_150 ) ;
return error ;
}
static T_1 F_83 ( struct V_63 * V_64 ,
struct V_128 * V_129 ,
const char * V_23 , T_3 V_135 )
{
struct V_1 * V_1 = F_59 ( V_64 ) ;
char V_148 [ V_158 ] ;
int V_25 , error ;
if ( V_135 >= V_158 ) {
F_21 ( V_64 , L_22 ) ;
return - V_75 ;
}
memcpy ( V_148 , V_23 , V_135 ) ;
if ( V_148 [ V_135 - 1 ] == '\n' )
V_148 [ V_135 - 1 ] = '\0' ;
else
V_148 [ V_135 ] = '\0' ;
if ( V_1 -> V_66 ) {
F_84 ( V_1 -> V_66 ) ;
V_1 -> V_66 = NULL ;
}
error = F_24 ( & V_1 -> V_67 ) ;
if ( error ) {
F_25 ( V_1 ) ;
return error ;
}
error = F_79 ( V_1 , V_148 ) ;
if ( error )
F_21 ( V_64 , L_23 , error ) ;
else
F_85 ( V_64 , L_24 ) ;
V_25 = F_25 ( V_1 ) ;
if ( V_25 ) {
F_21 ( V_64 , L_25 , V_25 ) ;
error = error ? error : V_25 ;
}
F_33 ( & V_1 -> V_67 ) ;
return error ? error : V_135 ;
}
static T_1 F_86 ( struct V_63 * V_64 ,
struct V_128 * V_129 ,
const char * V_23 , T_3 V_135 )
{
struct V_1 * V_1 = F_59 ( V_64 ) ;
int error ;
error = F_24 ( & V_1 -> V_67 ) ;
if ( error )
return error ;
if ( V_1 -> V_62 ) {
F_47 ( V_1 ) ;
error = V_1 -> V_58 -> V_159 ( V_64 , V_129 , V_23 , V_135 ) ;
F_48 ( V_1 ) ;
} else {
error = - V_160 ;
}
F_33 ( & V_1 -> V_67 ) ;
return error < 0 ? error : V_135 ;
}
static T_1 F_87 ( struct V_63 * V_64 ,
struct V_128 * V_129 , char * V_23 )
{
struct V_1 * V_1 = F_59 ( V_64 ) ;
T_1 error ;
error = F_24 ( & V_1 -> V_67 ) ;
if ( error )
return error ;
if ( V_1 -> V_62 ) {
F_47 ( V_1 ) ;
error = V_1 -> V_58 -> V_161 ( V_64 , V_129 , V_23 ) ;
F_48 ( V_1 ) ;
} else {
error = - V_160 ;
}
F_33 ( & V_1 -> V_67 ) ;
return error ;
}
static char * F_88 ( struct V_1 * V_1 )
{
switch ( V_1 -> V_4 ) {
case V_11 :
return L_26 ;
case V_162 :
return L_27 ;
case V_12 :
return L_28 ;
case V_7 :
case V_5 :
return L_29 ;
case V_13 :
case V_9 :
case V_8 :
return L_30 ;
default:
return L_31 ;
}
}
static T_1 F_89 ( struct V_63 * V_64 ,
struct V_128 * V_129 , char * V_23 )
{
struct V_1 * V_1 = F_59 ( V_64 ) ;
int V_146 ;
int error ;
error = F_24 ( & V_1 -> V_67 ) ;
if ( error )
return error ;
V_146 = F_60 ( V_23 , V_132 , L_32 ,
V_1 -> V_2 , F_88 ( V_1 ) ) ;
F_33 ( & V_1 -> V_67 ) ;
return V_146 ;
}
static void F_90 ( void * V_136 )
{
struct V_1 * V_1 = V_136 ;
F_91 ( & V_1 -> V_18 -> V_64 . V_137 , & V_163 ) ;
}
static void F_92 ( void * V_136 )
{
struct V_1 * V_1 = V_136 ;
F_93 ( V_1 -> V_164 ) ;
}
static int F_94 ( struct V_17 * V_18 ,
const struct V_165 * V_123 )
{
struct V_63 * V_64 = & V_18 -> V_64 ;
struct V_1 * V_1 ;
T_2 V_166 ;
union V_167 V_168 ;
int error ;
V_166 = F_10 ( V_18 ) ;
if ( V_166 == V_29 ) {
F_21 ( V_64 , L_33 ) ;
return - V_27 ;
}
if ( F_95 ( V_18 -> V_26 , V_18 -> V_21 , 0 ,
V_169 , 0 , V_170 , & V_168 ) < 0 )
return - V_60 ;
V_1 = F_96 ( V_64 , sizeof( struct V_1 ) , V_171 ) ;
if ( ! V_1 )
return - V_28 ;
if ( V_166 == V_35 )
V_1 -> V_40 = true ;
V_1 -> V_18 = V_18 ;
F_97 ( V_18 , V_1 ) ;
sprintf ( V_1 -> V_78 , L_34 , V_18 -> V_26 -> V_172 ,
V_18 -> V_21 ) ;
V_1 -> V_164 = F_98 ( V_64 , L_35 ) ;
if ( F_99 ( V_1 -> V_164 ) ) {
error = F_100 ( V_1 -> V_164 ) ;
F_21 ( V_64 , L_36 , error ) ;
return error ;
}
error = F_101 ( V_1 -> V_164 ) ;
if ( error ) {
F_21 ( V_64 , L_37 , error ) ;
return error ;
}
error = F_70 ( V_64 , F_92 , V_1 ) ;
if ( error ) {
F_92 ( V_1 ) ;
F_21 ( V_64 , L_38 ,
error ) ;
return error ;
}
error = F_52 ( V_1 ) ;
if ( error ) {
F_21 ( V_64 , L_39 ) ;
return error ;
}
error = F_102 ( & V_18 -> V_64 . V_137 , & V_163 ) ;
if ( error ) {
F_21 ( V_64 , L_40 , error ) ;
return error ;
}
error = F_70 ( V_64 , F_90 , V_1 ) ;
if ( error ) {
F_90 ( V_1 ) ;
F_21 ( V_64 , L_41 , error ) ;
return error ;
}
error = F_67 ( V_1 ) ;
if ( error ) {
F_21 ( V_64 , L_42 , error ) ;
return error ;
}
error = F_74 ( V_1 ) ;
if ( error ) {
F_21 ( V_64 , L_43 , error ) ;
return error ;
}
error = F_103 ( V_64 , V_18 -> V_71 ,
NULL , F_54 ,
V_173 | V_174 ,
L_44 , V_1 ) ;
if ( error ) {
F_21 ( V_64 , L_45 , error ) ;
return error ;
}
F_36 ( V_18 -> V_71 ) ;
if ( V_1 -> V_62 ) {
error = F_39 ( V_1 ) ;
if ( error ) {
F_21 ( V_64 , L_7 ,
error ) ;
return error ;
}
}
return 0 ;
}
static int T_6 F_104 ( struct V_63 * V_64 )
{
struct V_17 * V_18 = F_105 ( V_64 ) ;
struct V_1 * V_1 = F_106 ( V_18 ) ;
T_2 V_175 ;
int error ;
error = F_24 ( & V_1 -> V_67 ) ;
if ( error )
return error ;
if ( F_27 ( V_64 ) )
F_37 ( V_64 ) ;
F_36 ( V_18 -> V_71 ) ;
if ( V_1 -> V_62 ) {
V_175 = F_55 ( V_64 ) ? V_1 -> V_119
: V_72 ;
error = V_1 -> V_58 -> V_68 ( V_1 , V_175 ,
V_1 -> V_121 , true ) ;
if ( error )
F_21 ( V_64 , L_46 ,
error ) ;
}
if ( V_1 -> V_176 != V_72 )
V_1 -> V_58 -> V_177 ( V_1 , false ) ;
if ( F_55 ( V_64 ) )
V_1 -> V_178 = ( F_107 ( V_18 -> V_71 ) == 0 ) ;
F_33 ( & V_1 -> V_67 ) ;
return 0 ;
}
static int T_6 F_108 ( struct V_63 * V_64 )
{
struct V_17 * V_18 = F_105 ( V_64 ) ;
struct V_1 * V_1 = F_106 ( V_18 ) ;
int error ;
F_35 ( & V_1 -> V_67 ) ;
if ( F_55 ( V_64 ) && V_1 -> V_178 ) {
F_109 ( V_18 -> V_71 ) ;
V_1 -> V_178 = false ;
}
error = F_25 ( V_1 ) ;
if ( error )
F_20 ( V_64 , L_47 , error ) ;
F_26 ( V_18 -> V_71 ) ;
F_33 ( & V_1 -> V_67 ) ;
return 0 ;
}
static int T_6 F_110 ( struct V_63 * V_64 )
{
struct V_1 * V_1 = F_59 ( V_64 ) ;
int error ;
error = V_1 -> V_58 -> V_68 ( V_1 ,
V_1 -> V_139 ,
V_1 -> V_140 ,
false ) ;
if ( error )
F_20 ( V_64 , L_48 , error ) ;
return 0 ;
}
static int T_6 F_111 ( struct V_63 * V_64 )
{
struct V_1 * V_1 = F_59 ( V_64 ) ;
int error ;
error = V_1 -> V_58 -> V_68 ( V_1 ,
V_69 , 0 , false ) ;
if ( error )
F_20 ( V_64 , L_49 , error ) ;
return 0 ;
}
