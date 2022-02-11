static bool F_1 ( unsigned int type )
{
switch ( type ) {
case V_1 :
case V_2 :
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
return true ;
default:
return false ;
}
}
static bool F_2 ( unsigned int type )
{
switch ( type ) {
case V_1 :
case V_2 :
case V_3 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_23 :
case V_24 :
return true ;
default:
return false ;
}
}
static void F_3 ( struct V_25 * V_26 ,
struct V_27 * V_28 )
{
F_4 ( V_26 , L_1 ,
V_28 -> V_29 , 7 , V_28 -> V_28 ) ;
}
static int F_5 ( struct V_30 * V_31 ,
unsigned int V_32 )
{
T_1 V_33 ;
V_34:
if ( F_6 ( V_31 , & V_33 , 1 ) != 1 ) {
F_7 ( & V_31 -> V_26 , L_2 , V_35 ) ;
return - V_36 ;
}
switch ( V_32 ) {
case V_37 :
case V_38 :
V_33 &= ~ V_39 ;
break;
case V_40 :
if ( V_33 == V_41 )
goto V_34;
break;
default:
return - V_42 ;
}
if ( V_33 != V_32 ) {
F_7 ( & V_31 -> V_26 , L_3 ) ;
return - V_42 ;
}
return 0 ;
}
static int F_8 ( struct V_30 * V_31 )
{
T_1 V_43 [ 2 ] ;
V_43 [ 0 ] = V_44 ;
V_43 [ 1 ] = V_45 ;
if ( F_9 ( V_31 , V_43 , 2 ) != 2 ) {
F_7 ( & V_31 -> V_26 , L_4 , V_35 ) ;
return - V_36 ;
}
return 0 ;
}
static int F_10 ( struct V_30 * V_31 ,
const T_1 * V_46 , unsigned int V_47 )
{
if ( F_9 ( V_31 , V_46 , V_47 ) != V_47 ) {
F_7 ( & V_31 -> V_26 , L_4 , V_35 ) ;
return - V_36 ;
}
return 0 ;
}
static int F_11 ( struct V_30 * V_31 ,
T_2 V_48 , T_2 V_49 , void * V_33 )
{
struct V_50 V_51 [ 2 ] ;
T_1 V_43 [ 2 ] ;
int V_52 ;
V_43 [ 0 ] = V_48 & 0xff ;
V_43 [ 1 ] = ( V_48 >> 8 ) & 0xff ;
V_51 [ 0 ] . V_53 = V_31 -> V_53 ;
V_51 [ 0 ] . V_54 = 0 ;
V_51 [ 0 ] . V_49 = 2 ;
V_51 [ 0 ] . V_43 = V_43 ;
V_51 [ 1 ] . V_53 = V_31 -> V_53 ;
V_51 [ 1 ] . V_54 = V_55 ;
V_51 [ 1 ] . V_49 = V_49 ;
V_51 [ 1 ] . V_43 = V_33 ;
V_52 = F_12 ( V_31 -> V_56 , V_51 , 2 ) ;
if ( V_52 == 2 ) {
V_52 = 0 ;
} else {
if ( V_52 >= 0 )
V_52 = - V_36 ;
F_7 ( & V_31 -> V_26 , L_5 ,
V_35 , V_52 ) ;
}
return V_52 ;
}
static int F_13 ( struct V_30 * V_31 , T_2 V_48 , T_1 * V_33 )
{
return F_11 ( V_31 , V_48 , 1 , V_33 ) ;
}
static int F_14 ( struct V_30 * V_31 , T_2 V_48 , T_2 V_49 ,
const void * V_33 )
{
T_1 * V_43 ;
T_3 V_57 ;
int V_52 ;
V_57 = V_49 + 2 ;
V_43 = F_15 ( V_57 , V_58 ) ;
if ( ! V_43 )
return - V_59 ;
V_43 [ 0 ] = V_48 & 0xff ;
V_43 [ 1 ] = ( V_48 >> 8 ) & 0xff ;
memcpy ( & V_43 [ 2 ] , V_33 , V_49 ) ;
V_52 = F_9 ( V_31 , V_43 , V_57 ) ;
if ( V_52 == V_57 ) {
V_52 = 0 ;
} else {
if ( V_52 >= 0 )
V_52 = - V_36 ;
F_7 ( & V_31 -> V_26 , L_6 ,
V_35 , V_52 ) ;
}
F_16 ( V_43 ) ;
return V_52 ;
}
static int F_17 ( struct V_30 * V_31 , T_2 V_48 , T_1 V_33 )
{
return F_14 ( V_31 , V_48 , 1 , & V_33 ) ;
}
static struct V_60 *
F_18 ( struct V_61 * V_46 , T_1 type )
{
struct V_60 * V_62 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_46 -> V_64 . V_65 ; V_63 ++ ) {
V_62 = V_46 -> V_66 + V_63 ;
if ( V_62 -> type == type )
return V_62 ;
}
F_7 ( & V_46 -> V_31 -> V_26 , L_7 ) ;
return NULL ;
}
static int F_19 ( struct V_61 * V_46 ,
struct V_27 * V_28 )
{
struct V_60 * V_62 ;
T_2 V_48 ;
V_62 = F_18 ( V_46 , V_67 ) ;
if ( ! V_62 )
return - V_42 ;
V_48 = V_62 -> V_68 ;
return F_11 ( V_46 -> V_31 , V_48 ,
sizeof( struct V_27 ) , V_28 ) ;
}
static int F_20 ( struct V_61 * V_46 ,
T_1 type , T_1 V_69 , T_1 V_33 )
{
struct V_60 * V_62 ;
T_2 V_48 ;
V_62 = F_18 ( V_46 , type ) ;
if ( ! V_62 || V_69 >= V_62 -> V_70 + 1 )
return - V_42 ;
V_48 = V_62 -> V_68 ;
return F_17 ( V_46 -> V_31 , V_48 + V_69 , V_33 ) ;
}
static void F_21 ( struct V_61 * V_46 ,
struct V_27 * V_28 , int V_71 )
{
struct V_25 * V_26 = & V_46 -> V_31 -> V_26 ;
T_1 V_72 = V_28 -> V_28 [ 0 ] ;
struct V_73 * V_73 = V_46 -> V_73 ;
int V_74 ;
int V_75 ;
int V_76 ;
int V_77 ;
V_74 = ( V_28 -> V_28 [ 1 ] << 4 ) | ( ( V_28 -> V_28 [ 3 ] >> 4 ) & 0xf ) ;
V_75 = ( V_28 -> V_28 [ 2 ] << 4 ) | ( ( V_28 -> V_28 [ 3 ] & 0xf ) ) ;
if ( V_46 -> V_78 < 1024 )
V_74 = V_74 >> 2 ;
if ( V_46 -> V_79 < 1024 )
V_75 = V_75 >> 2 ;
V_76 = V_28 -> V_28 [ 4 ] ;
V_77 = V_28 -> V_28 [ 5 ] ;
F_4 ( V_26 ,
L_8 ,
V_71 ,
( V_72 & V_80 ) ? 'D' : '.' ,
( V_72 & V_81 ) ? 'P' : '.' ,
( V_72 & V_82 ) ? 'R' : '.' ,
( V_72 & V_83 ) ? 'M' : '.' ,
( V_72 & V_84 ) ? 'V' : '.' ,
( V_72 & V_85 ) ? 'A' : '.' ,
( V_72 & V_86 ) ? 'S' : '.' ,
( V_72 & V_87 ) ? 'U' : '.' ,
V_74 , V_75 , V_76 , V_77 ) ;
F_22 ( V_73 , V_71 ) ;
F_23 ( V_73 , V_88 ,
V_72 & V_80 ) ;
if ( V_72 & V_80 ) {
F_24 ( V_73 , V_89 , V_74 ) ;
F_24 ( V_73 , V_90 , V_75 ) ;
F_24 ( V_73 , V_91 , V_77 ) ;
F_24 ( V_73 , V_92 , V_76 ) ;
}
}
static unsigned F_25 ( const T_1 * V_93 )
{
return V_93 [ 0 ] | ( V_93 [ 1 ] << 8 ) | ( V_93 [ 2 ] << 16 ) ;
}
static bool F_26 ( struct V_61 * V_46 , struct V_27 * V_94 )
{
T_1 V_71 = V_94 -> V_29 ;
return ( V_71 >= V_46 -> V_95 && V_71 <= V_46 -> V_96 ) ;
}
static T_4 F_27 ( int V_97 , void * V_98 )
{
struct V_61 * V_46 = V_98 ;
struct V_27 V_28 ;
const T_1 * V_99 = & V_28 . V_28 [ 0 ] ;
struct V_25 * V_26 = & V_46 -> V_31 -> V_26 ;
T_1 V_29 ;
bool V_100 = false ;
do {
if ( F_19 ( V_46 , & V_28 ) ) {
F_7 ( V_26 , L_9 ) ;
goto V_101;
}
V_29 = V_28 . V_29 ;
if ( V_29 == V_46 -> V_102 ) {
T_1 V_72 = V_99 [ 0 ] ;
unsigned V_93 = F_25 ( & V_99 [ 1 ] ) ;
F_4 ( V_26 , L_10 ,
V_72 , V_93 ) ;
} else if ( F_26 ( V_46 , & V_28 ) ) {
int V_71 = V_29 - V_46 -> V_95 ;
F_21 ( V_46 , & V_28 , V_71 ) ;
V_100 = true ;
} else {
F_3 ( V_26 , & V_28 ) ;
}
} while ( V_29 != 0xff );
if ( V_100 ) {
F_28 ( V_46 -> V_73 , false ) ;
F_29 ( V_46 -> V_73 ) ;
}
V_101:
return V_103 ;
}
static int F_30 ( struct V_61 * V_46 )
{
const struct V_104 * V_105 = V_46 -> V_105 ;
struct V_60 * V_62 ;
struct V_25 * V_26 = & V_46 -> V_31 -> V_26 ;
int V_106 = 0 ;
int V_63 , V_70 ;
int V_52 ;
if ( ! V_105 -> V_107 ) {
F_4 ( V_26 , L_11 ) ;
return 0 ;
}
for ( V_63 = 0 ; V_63 < V_46 -> V_64 . V_65 ; V_63 ++ ) {
V_62 = V_46 -> V_66 + V_63 ;
if ( ! F_2 ( V_62 -> type ) )
continue;
V_70 = ( V_62 -> V_70 + 1 ) * ( V_62 -> V_108 + 1 ) ;
if ( V_106 + V_70 > V_105 -> V_109 ) {
F_7 ( V_26 , L_12 ) ;
return - V_42 ;
}
V_52 = F_14 ( V_46 -> V_31 , V_62 -> V_68 ,
V_70 , & V_105 -> V_107 [ V_106 ] ) ;
if ( V_52 )
return V_52 ;
V_106 += V_70 ;
}
return 0 ;
}
static int F_31 ( struct V_61 * V_46 )
{
struct V_25 * V_26 = & V_46 -> V_31 -> V_26 ;
struct V_27 V_28 ;
int V_57 = 10 ;
int error ;
do {
error = F_19 ( V_46 , & V_28 ) ;
if ( error )
return error ;
} while ( V_28 . V_29 != 0xff && -- V_57 );
if ( ! V_57 ) {
F_7 ( V_26 , L_13 ) ;
return - V_110 ;
}
return 0 ;
}
static void F_32 ( struct V_61 * V_46 )
{
const struct V_104 * V_105 = V_46 -> V_105 ;
T_1 V_111 ;
F_20 ( V_46 , V_5 , V_112 ,
V_105 -> V_113 ) ;
F_20 ( V_46 , V_5 , V_114 ,
V_105 -> V_115 ) ;
F_20 ( V_46 , V_5 , V_116 ,
V_105 -> V_117 ) ;
F_20 ( V_46 , V_5 ,
V_118 , V_105 -> V_119 ) ;
F_20 ( V_46 , V_5 ,
V_120 , V_105 -> V_121 ) ;
F_20 ( V_46 , V_5 ,
V_122 , ( V_105 -> V_123 - 1 ) & 0xff ) ;
F_20 ( V_46 , V_5 ,
V_124 , ( V_105 -> V_123 - 1 ) >> 8 ) ;
F_20 ( V_46 , V_5 ,
V_125 , ( V_105 -> V_126 - 1 ) & 0xff ) ;
F_20 ( V_46 , V_5 ,
V_127 , ( V_105 -> V_126 - 1 ) >> 8 ) ;
if ( V_105 -> V_111 ) {
if ( V_105 -> V_111 < V_128 ) {
V_111 = ( V_128 - V_105 -> V_111 ) /
V_129 ;
V_111 = 0xff - V_111 + 1 ;
} else
V_111 = ( V_105 -> V_111 - V_128 ) /
V_129 ;
F_20 ( V_46 , V_21 ,
V_130 , V_111 ) ;
}
}
static int F_33 ( struct V_61 * V_46 )
{
struct V_30 * V_31 = V_46 -> V_31 ;
struct V_131 * V_64 = & V_46 -> V_64 ;
int error ;
error = F_11 ( V_31 , V_132 , sizeof( * V_64 ) , V_64 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_34 ( struct V_61 * V_46 )
{
struct V_30 * V_31 = V_46 -> V_31 ;
T_3 V_133 ;
int error ;
int V_63 ;
T_1 V_29 ;
V_133 = V_46 -> V_64 . V_65 * sizeof( struct V_60 ) ;
error = F_11 ( V_31 , V_134 , V_133 ,
V_46 -> V_66 ) ;
if ( error )
return error ;
V_29 = 1 ;
for ( V_63 = 0 ; V_63 < V_46 -> V_64 . V_65 ; V_63 ++ ) {
struct V_60 * V_62 = V_46 -> V_66 + V_63 ;
T_1 V_135 , V_136 ;
F_35 ( & V_62 -> V_68 ) ;
if ( V_62 -> V_137 ) {
V_135 = V_29 ;
V_29 += V_62 -> V_137 *
( V_62 -> V_108 + 1 ) ;
V_136 = V_29 - 1 ;
} else {
V_135 = 0 ;
V_136 = 0 ;
}
F_4 ( & V_46 -> V_31 -> V_26 ,
L_14 ,
V_62 -> type , V_62 -> V_68 , V_62 -> V_70 + 1 ,
V_62 -> V_108 + 1 , V_135 , V_136 ) ;
switch ( V_62 -> type ) {
case V_1 :
V_46 -> V_102 = V_135 ;
break;
case V_5 :
V_46 -> V_95 = V_135 ;
V_46 -> V_96 = V_136 ;
break;
}
}
return 0 ;
}
static void F_36 ( struct V_61 * V_46 )
{
F_16 ( V_46 -> V_66 ) ;
V_46 -> V_66 = NULL ;
V_46 -> V_102 = 0 ;
V_46 -> V_95 = 0 ;
V_46 -> V_96 = 0 ;
}
static int F_37 ( struct V_61 * V_46 )
{
struct V_30 * V_31 = V_46 -> V_31 ;
struct V_131 * V_64 = & V_46 -> V_64 ;
int error ;
T_1 V_33 ;
error = F_33 ( V_46 ) ;
if ( error )
return error ;
V_46 -> V_66 = F_38 ( V_64 -> V_65 ,
sizeof( struct V_60 ) ,
V_58 ) ;
if ( ! V_46 -> V_66 ) {
F_7 ( & V_31 -> V_26 , L_15 ) ;
return - V_59 ;
}
error = F_34 ( V_46 ) ;
if ( error )
goto V_138;
error = F_30 ( V_46 ) ;
if ( error )
goto V_138;
F_32 ( V_46 ) ;
F_20 ( V_46 , V_1 ,
V_139 ,
V_140 ) ;
F_39 ( V_141 ) ;
F_20 ( V_46 , V_1 ,
V_142 , 1 ) ;
F_39 ( V_143 ) ;
error = F_13 ( V_31 , V_144 , & V_33 ) ;
if ( error )
goto V_138;
V_64 -> V_145 = V_33 ;
error = F_13 ( V_31 , V_146 , & V_33 ) ;
if ( error )
goto V_138;
V_64 -> V_147 = V_33 ;
F_40 ( & V_31 -> V_26 ,
L_16 ,
V_64 -> V_148 , V_64 -> V_149 , V_64 -> V_150 >> 4 ,
V_64 -> V_150 & 0xf , V_64 -> V_151 ) ;
F_40 ( & V_31 -> V_26 ,
L_17 ,
V_64 -> V_145 , V_64 -> V_147 ,
V_64 -> V_65 ) ;
return 0 ;
V_138:
F_36 ( V_46 ) ;
return error ;
}
static void F_41 ( struct V_61 * V_46 )
{
unsigned int V_78 = V_46 -> V_105 -> V_123 - 1 ;
unsigned int V_79 = V_46 -> V_105 -> V_126 - 1 ;
if ( V_46 -> V_105 -> V_117 & V_152 ) {
V_46 -> V_78 = V_79 ;
V_46 -> V_79 = V_78 ;
} else {
V_46 -> V_78 = V_78 ;
V_46 -> V_79 = V_79 ;
}
}
static T_5 F_42 ( struct V_25 * V_26 ,
struct V_153 * V_154 , char * V_43 )
{
struct V_61 * V_46 = F_43 ( V_26 ) ;
struct V_131 * V_64 = & V_46 -> V_64 ;
return F_44 ( V_43 , V_155 , L_18 ,
V_64 -> V_150 >> 4 , V_64 -> V_150 & 0xf , V_64 -> V_151 ) ;
}
static T_5 F_45 ( struct V_25 * V_26 ,
struct V_153 * V_154 , char * V_43 )
{
struct V_61 * V_46 = F_43 ( V_26 ) ;
struct V_131 * V_64 = & V_46 -> V_64 ;
return F_44 ( V_43 , V_155 , L_19 ,
V_64 -> V_148 , V_64 -> V_149 ) ;
}
static T_5 F_46 ( char * V_43 , int V_57 ,
struct V_60 * V_62 , int V_156 ,
const T_1 * V_33 )
{
int V_63 ;
if ( V_62 -> V_108 > 0 )
V_57 += F_44 ( V_43 + V_57 , V_155 - V_57 ,
L_20 , V_156 ) ;
for ( V_63 = 0 ; V_63 < V_62 -> V_70 + 1 ; V_63 ++ )
V_57 += F_44 ( V_43 + V_57 , V_155 - V_57 ,
L_21 , V_63 , V_33 [ V_63 ] , V_33 [ V_63 ] ) ;
V_57 += F_44 ( V_43 + V_57 , V_155 - V_57 , L_22 ) ;
return V_57 ;
}
static T_5 F_47 ( struct V_25 * V_26 ,
struct V_153 * V_154 , char * V_43 )
{
struct V_61 * V_46 = F_43 ( V_26 ) ;
struct V_60 * V_62 ;
int V_57 = 0 ;
int V_63 , V_157 ;
int error ;
T_1 * V_158 ;
V_158 = F_15 ( 256 , V_58 ) ;
if ( ! V_158 )
return - V_59 ;
error = 0 ;
for ( V_63 = 0 ; V_63 < V_46 -> V_64 . V_65 ; V_63 ++ ) {
V_62 = V_46 -> V_66 + V_63 ;
if ( ! F_1 ( V_62 -> type ) )
continue;
V_57 += F_44 ( V_43 + V_57 , V_155 - V_57 ,
L_23 , V_62 -> type ) ;
for ( V_157 = 0 ; V_157 < V_62 -> V_108 + 1 ; V_157 ++ ) {
T_2 V_70 = V_62 -> V_70 + 1 ;
T_2 V_53 = V_62 -> V_68 + V_157 * V_70 ;
error = F_11 ( V_46 -> V_31 , V_53 , V_70 , V_158 ) ;
if ( error )
goto V_159;
V_57 = F_46 ( V_43 , V_57 , V_62 , V_157 , V_158 ) ;
}
}
V_159:
F_16 ( V_158 ) ;
return error ? : V_57 ;
}
static int F_48 ( struct V_25 * V_26 , const char * V_160 )
{
struct V_61 * V_46 = F_43 ( V_26 ) ;
struct V_30 * V_31 = V_46 -> V_31 ;
const struct V_161 * V_162 = NULL ;
unsigned int V_47 ;
unsigned int V_163 = 0 ;
int V_52 ;
V_52 = F_49 ( & V_162 , V_160 , V_26 ) ;
if ( V_52 ) {
F_7 ( V_26 , L_24 , V_160 ) ;
return V_52 ;
}
F_20 ( V_46 , V_1 ,
V_142 , V_164 ) ;
F_39 ( V_143 ) ;
if ( V_31 -> V_53 == V_165 )
V_31 -> V_53 = V_166 ;
else
V_31 -> V_53 = V_167 ;
V_52 = F_5 ( V_31 , V_37 ) ;
if ( V_52 )
goto V_168;
F_8 ( V_31 ) ;
while ( V_163 < V_162 -> V_70 ) {
V_52 = F_5 ( V_31 ,
V_38 ) ;
if ( V_52 )
goto V_168;
V_47 = ( ( * ( V_162 -> V_46 + V_163 ) << 8 ) | * ( V_162 -> V_46 + V_163 + 1 ) ) ;
V_47 += 2 ;
F_10 ( V_31 , V_162 -> V_46 + V_163 , V_47 ) ;
V_52 = F_5 ( V_31 ,
V_40 ) ;
if ( V_52 )
goto V_168;
V_163 += V_47 ;
F_4 ( V_26 , L_25 , V_163 , V_162 -> V_70 ) ;
}
V_168:
F_50 ( V_162 ) ;
if ( V_31 -> V_53 == V_166 )
V_31 -> V_53 = V_165 ;
else
V_31 -> V_53 = V_169 ;
return V_52 ;
}
static T_5 F_51 ( struct V_25 * V_26 ,
struct V_153 * V_154 ,
const char * V_43 , T_3 V_57 )
{
struct V_61 * V_46 = F_43 ( V_26 ) ;
int error ;
F_52 ( V_46 -> V_97 ) ;
error = F_48 ( V_26 , V_170 ) ;
if ( error ) {
F_7 ( V_26 , L_26 , error ) ;
V_57 = error ;
} else {
F_4 ( V_26 , L_27 ) ;
F_39 ( V_171 ) ;
F_36 ( V_46 ) ;
F_37 ( V_46 ) ;
}
F_53 ( V_46 -> V_97 ) ;
error = F_31 ( V_46 ) ;
if ( error )
return error ;
return V_57 ;
}
static void F_54 ( struct V_61 * V_46 )
{
F_20 ( V_46 ,
V_5 , V_172 , 0x83 ) ;
}
static void F_55 ( struct V_61 * V_46 )
{
F_20 ( V_46 ,
V_5 , V_172 , 0 ) ;
}
static int F_56 ( struct V_73 * V_26 )
{
struct V_61 * V_46 = F_57 ( V_26 ) ;
F_54 ( V_46 ) ;
return 0 ;
}
static void F_58 ( struct V_73 * V_26 )
{
struct V_61 * V_46 = F_57 ( V_26 ) ;
F_55 ( V_46 ) ;
}
static int T_6 F_59 ( struct V_30 * V_31 ,
const struct V_173 * V_71 )
{
const struct V_104 * V_105 = V_31 -> V_26 . V_174 ;
struct V_61 * V_46 ;
struct V_73 * V_73 ;
int error ;
unsigned int V_175 ;
if ( ! V_105 )
return - V_42 ;
V_46 = F_60 ( sizeof( struct V_61 ) , V_58 ) ;
V_73 = F_61 () ;
if ( ! V_46 || ! V_73 ) {
F_7 ( & V_31 -> V_26 , L_15 ) ;
error = - V_59 ;
goto V_176;
}
V_73 -> V_177 = L_28 ;
snprintf ( V_46 -> V_178 , sizeof( V_46 -> V_178 ) , L_29 ,
V_31 -> V_56 -> V_179 , V_31 -> V_53 ) ;
V_73 -> V_178 = V_46 -> V_178 ;
V_73 -> V_71 . V_180 = V_181 ;
V_73 -> V_26 . V_182 = & V_31 -> V_26 ;
V_73 -> V_183 = F_56 ;
V_73 -> V_184 = F_58 ;
V_46 -> V_31 = V_31 ;
V_46 -> V_73 = V_73 ;
V_46 -> V_105 = V_105 ;
V_46 -> V_97 = V_31 -> V_97 ;
F_41 ( V_46 ) ;
error = F_37 ( V_46 ) ;
if ( error )
goto V_176;
F_62 ( V_185 , V_73 -> V_186 ) ;
F_62 ( V_187 , V_73 -> V_186 ) ;
F_62 ( V_188 , V_73 -> V_189 ) ;
F_63 ( V_73 , V_190 ,
0 , V_46 -> V_78 , 0 , 0 ) ;
F_63 ( V_73 , V_191 ,
0 , V_46 -> V_79 , 0 , 0 ) ;
F_63 ( V_73 , V_192 ,
0 , 255 , 0 , 0 ) ;
V_175 = V_46 -> V_96 - V_46 -> V_95 + 1 ;
error = F_64 ( V_73 , V_175 , 0 ) ;
if ( error )
goto V_193;
F_63 ( V_73 , V_92 ,
0 , V_194 , 0 , 0 ) ;
F_63 ( V_73 , V_89 ,
0 , V_46 -> V_78 , 0 , 0 ) ;
F_63 ( V_73 , V_90 ,
0 , V_46 -> V_79 , 0 , 0 ) ;
F_63 ( V_73 , V_91 ,
0 , 255 , 0 , 0 ) ;
F_65 ( V_73 , V_46 ) ;
F_66 ( V_31 , V_46 ) ;
error = F_67 ( V_31 -> V_97 , NULL , F_27 ,
V_105 -> V_195 | V_196 ,
V_31 -> V_177 , V_46 ) ;
if ( error ) {
F_7 ( & V_31 -> V_26 , L_30 ) ;
goto V_193;
}
error = F_31 ( V_46 ) ;
if ( error )
goto V_197;
error = F_68 ( V_73 ) ;
if ( error )
goto V_197;
error = F_69 ( & V_31 -> V_26 . V_198 , & V_199 ) ;
if ( error )
goto V_200;
return 0 ;
V_200:
F_70 ( V_73 ) ;
V_73 = NULL ;
V_197:
F_71 ( V_31 -> V_97 , V_46 ) ;
V_193:
F_16 ( V_46 -> V_66 ) ;
V_176:
F_72 ( V_73 ) ;
F_16 ( V_46 ) ;
return error ;
}
static int T_7 F_73 ( struct V_30 * V_31 )
{
struct V_61 * V_46 = F_74 ( V_31 ) ;
F_75 ( & V_31 -> V_26 . V_198 , & V_199 ) ;
F_71 ( V_46 -> V_97 , V_46 ) ;
F_70 ( V_46 -> V_73 ) ;
F_16 ( V_46 -> V_66 ) ;
F_16 ( V_46 ) ;
return 0 ;
}
static int F_76 ( struct V_25 * V_26 )
{
struct V_30 * V_31 = F_77 ( V_26 ) ;
struct V_61 * V_46 = F_74 ( V_31 ) ;
struct V_73 * V_73 = V_46 -> V_73 ;
F_78 ( & V_73 -> V_201 ) ;
if ( V_73 -> V_202 )
F_55 ( V_46 ) ;
F_79 ( & V_73 -> V_201 ) ;
return 0 ;
}
static int F_80 ( struct V_25 * V_26 )
{
struct V_30 * V_31 = F_77 ( V_26 ) ;
struct V_61 * V_46 = F_74 ( V_31 ) ;
struct V_73 * V_73 = V_46 -> V_73 ;
F_20 ( V_46 , V_1 ,
V_142 , 1 ) ;
F_39 ( V_143 ) ;
F_78 ( & V_73 -> V_201 ) ;
if ( V_73 -> V_202 )
F_54 ( V_46 ) ;
F_79 ( & V_73 -> V_201 ) ;
return 0 ;
}
