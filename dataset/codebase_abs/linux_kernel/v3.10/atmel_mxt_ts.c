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
static void F_21 ( struct V_61 * V_46 , struct V_27 * V_28 )
{
struct V_71 * V_72 = V_46 -> V_71 ;
bool V_73 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_74 ; V_63 ++ ) {
if ( V_46 -> V_75 -> V_76 [ V_63 ] == V_77 )
continue;
V_73 = ! ( V_28 -> V_28 [ 0 ] & V_78 << V_63 ) ;
F_22 ( V_72 , V_46 -> V_75 -> V_76 [ V_63 ] , V_73 ) ;
}
}
static void F_23 ( struct V_61 * V_46 ,
struct V_27 * V_28 , int V_79 )
{
struct V_25 * V_26 = & V_46 -> V_31 -> V_26 ;
T_1 V_80 = V_28 -> V_28 [ 0 ] ;
struct V_71 * V_71 = V_46 -> V_71 ;
int V_81 ;
int V_82 ;
int V_83 ;
int V_84 ;
V_81 = ( V_28 -> V_28 [ 1 ] << 4 ) | ( ( V_28 -> V_28 [ 3 ] >> 4 ) & 0xf ) ;
V_82 = ( V_28 -> V_28 [ 2 ] << 4 ) | ( ( V_28 -> V_28 [ 3 ] & 0xf ) ) ;
if ( V_46 -> V_85 < 1024 )
V_81 = V_81 >> 2 ;
if ( V_46 -> V_86 < 1024 )
V_82 = V_82 >> 2 ;
V_83 = V_28 -> V_28 [ 4 ] ;
V_84 = V_28 -> V_28 [ 5 ] ;
F_4 ( V_26 ,
L_8 ,
V_79 ,
( V_80 & V_87 ) ? 'D' : '.' ,
( V_80 & V_88 ) ? 'P' : '.' ,
( V_80 & V_89 ) ? 'R' : '.' ,
( V_80 & V_90 ) ? 'M' : '.' ,
( V_80 & V_91 ) ? 'V' : '.' ,
( V_80 & V_92 ) ? 'A' : '.' ,
( V_80 & V_93 ) ? 'S' : '.' ,
( V_80 & V_94 ) ? 'U' : '.' ,
V_81 , V_82 , V_83 , V_84 ) ;
F_24 ( V_71 , V_79 ) ;
F_25 ( V_71 , V_95 ,
V_80 & V_87 ) ;
if ( V_80 & V_87 ) {
F_26 ( V_71 , V_96 , V_81 ) ;
F_26 ( V_71 , V_97 , V_82 ) ;
F_26 ( V_71 , V_98 , V_84 ) ;
F_26 ( V_71 , V_99 , V_83 ) ;
}
}
static unsigned F_27 ( const T_1 * V_100 )
{
return V_100 [ 0 ] | ( V_100 [ 1 ] << 8 ) | ( V_100 [ 2 ] << 16 ) ;
}
static bool F_28 ( struct V_61 * V_46 , struct V_27 * V_101 )
{
T_1 V_79 = V_101 -> V_29 ;
return ( V_79 >= V_46 -> V_102 && V_79 <= V_46 -> V_103 ) ;
}
static T_4 F_29 ( int V_104 , void * V_105 )
{
struct V_61 * V_46 = V_105 ;
struct V_27 V_28 ;
const T_1 * V_106 = & V_28 . V_28 [ 0 ] ;
struct V_25 * V_26 = & V_46 -> V_31 -> V_26 ;
T_1 V_29 ;
bool V_107 = false ;
do {
if ( F_19 ( V_46 , & V_28 ) ) {
F_7 ( V_26 , L_9 ) ;
goto V_108;
}
V_29 = V_28 . V_29 ;
if ( V_29 == V_46 -> V_109 ) {
T_1 V_80 = V_106 [ 0 ] ;
unsigned V_100 = F_27 ( & V_106 [ 1 ] ) ;
F_4 ( V_26 , L_10 ,
V_80 , V_100 ) ;
} else if ( F_28 ( V_46 , & V_28 ) ) {
int V_79 = V_29 - V_46 -> V_102 ;
F_23 ( V_46 , & V_28 , V_79 ) ;
V_107 = true ;
} else if ( V_28 . V_29 == V_46 -> V_110 ) {
F_21 ( V_46 , & V_28 ) ;
V_107 = true ;
} else {
F_3 ( V_26 , & V_28 ) ;
}
} while ( V_29 != 0xff );
if ( V_107 ) {
F_30 ( V_46 -> V_71 , false ) ;
F_31 ( V_46 -> V_71 ) ;
}
V_108:
return V_111 ;
}
static int F_32 ( struct V_61 * V_46 )
{
const struct V_112 * V_75 = V_46 -> V_75 ;
struct V_60 * V_62 ;
struct V_25 * V_26 = & V_46 -> V_31 -> V_26 ;
int V_113 = 0 ;
int V_63 , V_70 ;
int V_52 ;
if ( ! V_75 -> V_114 ) {
F_4 ( V_26 , L_11 ) ;
return 0 ;
}
for ( V_63 = 0 ; V_63 < V_46 -> V_64 . V_65 ; V_63 ++ ) {
V_62 = V_46 -> V_66 + V_63 ;
if ( ! F_2 ( V_62 -> type ) )
continue;
V_70 = ( V_62 -> V_70 + 1 ) * ( V_62 -> V_115 + 1 ) ;
if ( V_113 + V_70 > V_75 -> V_116 ) {
F_7 ( V_26 , L_12 ) ;
return - V_42 ;
}
V_52 = F_14 ( V_46 -> V_31 , V_62 -> V_68 ,
V_70 , & V_75 -> V_114 [ V_113 ] ) ;
if ( V_52 )
return V_52 ;
V_113 += V_70 ;
}
return 0 ;
}
static int F_33 ( struct V_61 * V_46 )
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
return - V_117 ;
}
return 0 ;
}
static void F_34 ( struct V_61 * V_46 )
{
const struct V_112 * V_75 = V_46 -> V_75 ;
T_1 V_118 ;
F_20 ( V_46 , V_5 , V_119 ,
V_75 -> V_120 ) ;
F_20 ( V_46 , V_5 , V_121 ,
V_75 -> V_122 ) ;
F_20 ( V_46 , V_5 , V_123 ,
V_75 -> V_124 ) ;
F_20 ( V_46 , V_5 ,
V_125 , V_75 -> V_126 ) ;
F_20 ( V_46 , V_5 ,
V_127 , V_75 -> V_128 ) ;
F_20 ( V_46 , V_5 ,
V_129 , ( V_75 -> V_130 - 1 ) & 0xff ) ;
F_20 ( V_46 , V_5 ,
V_131 , ( V_75 -> V_130 - 1 ) >> 8 ) ;
F_20 ( V_46 , V_5 ,
V_132 , ( V_75 -> V_133 - 1 ) & 0xff ) ;
F_20 ( V_46 , V_5 ,
V_134 , ( V_75 -> V_133 - 1 ) >> 8 ) ;
if ( V_75 -> V_118 ) {
if ( V_75 -> V_118 < V_135 ) {
V_118 = ( V_135 - V_75 -> V_118 ) /
V_136 ;
V_118 = 0xff - V_118 + 1 ;
} else
V_118 = ( V_75 -> V_118 - V_135 ) /
V_136 ;
F_20 ( V_46 , V_21 ,
V_137 , V_118 ) ;
}
}
static int F_35 ( struct V_61 * V_46 )
{
struct V_30 * V_31 = V_46 -> V_31 ;
struct V_138 * V_64 = & V_46 -> V_64 ;
int error ;
error = F_11 ( V_31 , V_139 , sizeof( * V_64 ) , V_64 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_36 ( struct V_61 * V_46 )
{
struct V_30 * V_31 = V_46 -> V_31 ;
T_3 V_140 ;
int error ;
int V_63 ;
T_1 V_29 ;
V_140 = V_46 -> V_64 . V_65 * sizeof( struct V_60 ) ;
error = F_11 ( V_31 , V_141 , V_140 ,
V_46 -> V_66 ) ;
if ( error )
return error ;
V_29 = 1 ;
for ( V_63 = 0 ; V_63 < V_46 -> V_64 . V_65 ; V_63 ++ ) {
struct V_60 * V_62 = V_46 -> V_66 + V_63 ;
T_1 V_142 , V_143 ;
F_37 ( & V_62 -> V_68 ) ;
if ( V_62 -> V_144 ) {
V_142 = V_29 ;
V_29 += V_62 -> V_144 *
( V_62 -> V_115 + 1 ) ;
V_143 = V_29 - 1 ;
} else {
V_142 = 0 ;
V_143 = 0 ;
}
F_4 ( & V_46 -> V_31 -> V_26 ,
L_14 ,
V_62 -> type , V_62 -> V_68 , V_62 -> V_70 + 1 ,
V_62 -> V_115 + 1 , V_142 , V_143 ) ;
switch ( V_62 -> type ) {
case V_1 :
V_46 -> V_109 = V_142 ;
break;
case V_5 :
V_46 -> V_102 = V_142 ;
V_46 -> V_103 = V_143 ;
break;
case V_19 :
V_46 -> V_110 = V_142 ;
break;
}
}
return 0 ;
}
static void F_38 ( struct V_61 * V_46 )
{
F_16 ( V_46 -> V_66 ) ;
V_46 -> V_66 = NULL ;
V_46 -> V_109 = 0 ;
V_46 -> V_102 = 0 ;
V_46 -> V_103 = 0 ;
V_46 -> V_110 = 0 ;
}
static int F_39 ( struct V_61 * V_46 )
{
struct V_30 * V_31 = V_46 -> V_31 ;
struct V_138 * V_64 = & V_46 -> V_64 ;
int error ;
T_1 V_33 ;
error = F_35 ( V_46 ) ;
if ( error )
return error ;
V_46 -> V_66 = F_40 ( V_64 -> V_65 ,
sizeof( struct V_60 ) ,
V_58 ) ;
if ( ! V_46 -> V_66 ) {
F_7 ( & V_31 -> V_26 , L_15 ) ;
return - V_59 ;
}
error = F_36 ( V_46 ) ;
if ( error )
goto V_145;
error = F_32 ( V_46 ) ;
if ( error )
goto V_145;
F_34 ( V_46 ) ;
F_20 ( V_46 , V_1 ,
V_146 ,
V_147 ) ;
F_41 ( V_148 ) ;
F_20 ( V_46 , V_1 ,
V_149 , 1 ) ;
F_41 ( V_150 ) ;
error = F_13 ( V_31 , V_151 , & V_33 ) ;
if ( error )
goto V_145;
V_64 -> V_152 = V_33 ;
error = F_13 ( V_31 , V_153 , & V_33 ) ;
if ( error )
goto V_145;
V_64 -> V_154 = V_33 ;
F_42 ( & V_31 -> V_26 ,
L_16 ,
V_64 -> V_155 , V_64 -> V_156 , V_64 -> V_157 >> 4 ,
V_64 -> V_157 & 0xf , V_64 -> V_158 ) ;
F_42 ( & V_31 -> V_26 ,
L_17 ,
V_64 -> V_152 , V_64 -> V_154 ,
V_64 -> V_65 ) ;
return 0 ;
V_145:
F_38 ( V_46 ) ;
return error ;
}
static void F_43 ( struct V_61 * V_46 )
{
unsigned int V_85 = V_46 -> V_75 -> V_130 - 1 ;
unsigned int V_86 = V_46 -> V_75 -> V_133 - 1 ;
if ( V_46 -> V_75 -> V_124 & V_159 ) {
V_46 -> V_85 = V_86 ;
V_46 -> V_86 = V_85 ;
} else {
V_46 -> V_85 = V_85 ;
V_46 -> V_86 = V_86 ;
}
}
static T_5 F_44 ( struct V_25 * V_26 ,
struct V_160 * V_161 , char * V_43 )
{
struct V_61 * V_46 = F_45 ( V_26 ) ;
struct V_138 * V_64 = & V_46 -> V_64 ;
return F_46 ( V_43 , V_162 , L_18 ,
V_64 -> V_157 >> 4 , V_64 -> V_157 & 0xf , V_64 -> V_158 ) ;
}
static T_5 F_47 ( struct V_25 * V_26 ,
struct V_160 * V_161 , char * V_43 )
{
struct V_61 * V_46 = F_45 ( V_26 ) ;
struct V_138 * V_64 = & V_46 -> V_64 ;
return F_46 ( V_43 , V_162 , L_19 ,
V_64 -> V_155 , V_64 -> V_156 ) ;
}
static T_5 F_48 ( char * V_43 , int V_57 ,
struct V_60 * V_62 , int V_163 ,
const T_1 * V_33 )
{
int V_63 ;
if ( V_62 -> V_115 > 0 )
V_57 += F_46 ( V_43 + V_57 , V_162 - V_57 ,
L_20 , V_163 ) ;
for ( V_63 = 0 ; V_63 < V_62 -> V_70 + 1 ; V_63 ++ )
V_57 += F_46 ( V_43 + V_57 , V_162 - V_57 ,
L_21 , V_63 , V_33 [ V_63 ] , V_33 [ V_63 ] ) ;
V_57 += F_46 ( V_43 + V_57 , V_162 - V_57 , L_22 ) ;
return V_57 ;
}
static T_5 F_49 ( struct V_25 * V_26 ,
struct V_160 * V_161 , char * V_43 )
{
struct V_61 * V_46 = F_45 ( V_26 ) ;
struct V_60 * V_62 ;
int V_57 = 0 ;
int V_63 , V_164 ;
int error ;
T_1 * V_165 ;
V_165 = F_15 ( 256 , V_58 ) ;
if ( ! V_165 )
return - V_59 ;
error = 0 ;
for ( V_63 = 0 ; V_63 < V_46 -> V_64 . V_65 ; V_63 ++ ) {
V_62 = V_46 -> V_66 + V_63 ;
if ( ! F_1 ( V_62 -> type ) )
continue;
V_57 += F_46 ( V_43 + V_57 , V_162 - V_57 ,
L_23 , V_62 -> type ) ;
for ( V_164 = 0 ; V_164 < V_62 -> V_115 + 1 ; V_164 ++ ) {
T_2 V_70 = V_62 -> V_70 + 1 ;
T_2 V_53 = V_62 -> V_68 + V_164 * V_70 ;
error = F_11 ( V_46 -> V_31 , V_53 , V_70 , V_165 ) ;
if ( error )
goto V_166;
V_57 = F_48 ( V_43 , V_57 , V_62 , V_164 , V_165 ) ;
}
}
V_166:
F_16 ( V_165 ) ;
return error ? : V_57 ;
}
static int F_50 ( struct V_25 * V_26 , const char * V_167 )
{
struct V_61 * V_46 = F_45 ( V_26 ) ;
struct V_30 * V_31 = V_46 -> V_31 ;
const struct V_168 * V_169 = NULL ;
unsigned int V_47 ;
unsigned int V_170 = 0 ;
int V_52 ;
V_52 = F_51 ( & V_169 , V_167 , V_26 ) ;
if ( V_52 ) {
F_7 ( V_26 , L_24 , V_167 ) ;
return V_52 ;
}
F_20 ( V_46 , V_1 ,
V_149 , V_171 ) ;
F_41 ( V_150 ) ;
if ( V_31 -> V_53 == V_172 )
V_31 -> V_53 = V_173 ;
else
V_31 -> V_53 = V_174 ;
V_52 = F_5 ( V_31 , V_37 ) ;
if ( V_52 )
goto V_175;
F_8 ( V_31 ) ;
while ( V_170 < V_169 -> V_70 ) {
V_52 = F_5 ( V_31 ,
V_38 ) ;
if ( V_52 )
goto V_175;
V_47 = ( ( * ( V_169 -> V_46 + V_170 ) << 8 ) | * ( V_169 -> V_46 + V_170 + 1 ) ) ;
V_47 += 2 ;
F_10 ( V_31 , V_169 -> V_46 + V_170 , V_47 ) ;
V_52 = F_5 ( V_31 ,
V_40 ) ;
if ( V_52 )
goto V_175;
V_170 += V_47 ;
F_4 ( V_26 , L_25 , V_170 , V_169 -> V_70 ) ;
}
V_175:
F_52 ( V_169 ) ;
if ( V_31 -> V_53 == V_173 )
V_31 -> V_53 = V_172 ;
else
V_31 -> V_53 = V_176 ;
return V_52 ;
}
static T_5 F_53 ( struct V_25 * V_26 ,
struct V_160 * V_161 ,
const char * V_43 , T_3 V_57 )
{
struct V_61 * V_46 = F_45 ( V_26 ) ;
int error ;
F_54 ( V_46 -> V_104 ) ;
error = F_50 ( V_26 , V_177 ) ;
if ( error ) {
F_7 ( V_26 , L_26 , error ) ;
V_57 = error ;
} else {
F_4 ( V_26 , L_27 ) ;
F_41 ( V_178 ) ;
F_38 ( V_46 ) ;
F_39 ( V_46 ) ;
}
F_55 ( V_46 -> V_104 ) ;
error = F_33 ( V_46 ) ;
if ( error )
return error ;
return V_57 ;
}
static void F_56 ( struct V_61 * V_46 )
{
F_20 ( V_46 ,
V_5 , V_179 , 0x83 ) ;
}
static void F_57 ( struct V_61 * V_46 )
{
F_20 ( V_46 ,
V_5 , V_179 , 0 ) ;
}
static int F_58 ( struct V_71 * V_26 )
{
struct V_61 * V_46 = F_59 ( V_26 ) ;
F_56 ( V_46 ) ;
return 0 ;
}
static void F_60 ( struct V_71 * V_26 )
{
struct V_61 * V_46 = F_59 ( V_26 ) ;
F_57 ( V_46 ) ;
}
static int F_61 ( struct V_30 * V_31 ,
const struct V_180 * V_79 )
{
const struct V_112 * V_75 = V_31 -> V_26 . V_181 ;
struct V_61 * V_46 ;
struct V_71 * V_71 ;
int error ;
unsigned int V_182 ;
if ( ! V_75 )
return - V_42 ;
V_46 = F_62 ( sizeof( struct V_61 ) , V_58 ) ;
V_71 = F_63 () ;
if ( ! V_46 || ! V_71 ) {
F_7 ( & V_31 -> V_26 , L_15 ) ;
error = - V_59 ;
goto V_183;
}
V_46 -> V_184 = V_75 && V_75 -> V_184 ;
V_71 -> V_185 = ( V_46 -> V_184 ) ? L_28 :
L_29 ;
snprintf ( V_46 -> V_186 , sizeof( V_46 -> V_186 ) , L_30 ,
V_31 -> V_56 -> V_187 , V_31 -> V_53 ) ;
V_71 -> V_186 = V_46 -> V_186 ;
V_71 -> V_79 . V_188 = V_189 ;
V_71 -> V_26 . V_190 = & V_31 -> V_26 ;
V_71 -> V_191 = F_58 ;
V_71 -> V_192 = F_60 ;
V_46 -> V_31 = V_31 ;
V_46 -> V_71 = V_71 ;
V_46 -> V_75 = V_75 ;
V_46 -> V_104 = V_31 -> V_104 ;
F_43 ( V_46 ) ;
error = F_39 ( V_46 ) ;
if ( error )
goto V_183;
F_64 ( V_193 , V_71 -> V_194 ) ;
F_64 ( V_195 , V_71 -> V_194 ) ;
F_64 ( V_196 , V_71 -> V_197 ) ;
if ( V_46 -> V_184 ) {
int V_63 ;
F_64 ( V_198 , V_71 -> V_199 ) ;
F_64 ( V_200 , V_71 -> V_199 ) ;
for ( V_63 = 0 ; V_63 < V_74 ; V_63 ++ )
if ( V_75 -> V_76 [ V_63 ] != V_77 )
F_64 ( V_75 -> V_76 [ V_63 ] , V_71 -> V_197 ) ;
F_64 ( V_201 , V_71 -> V_197 ) ;
F_64 ( V_202 , V_71 -> V_197 ) ;
F_64 ( V_203 , V_71 -> V_197 ) ;
F_64 ( V_204 , V_71 -> V_197 ) ;
F_64 ( V_205 , V_71 -> V_197 ) ;
F_65 ( V_71 , V_206 , V_207 ) ;
F_65 ( V_71 , V_208 , V_207 ) ;
F_65 ( V_71 , V_96 ,
V_207 ) ;
F_65 ( V_71 , V_97 ,
V_207 ) ;
}
F_66 ( V_71 , V_206 ,
0 , V_46 -> V_85 , 0 , 0 ) ;
F_66 ( V_71 , V_208 ,
0 , V_46 -> V_86 , 0 , 0 ) ;
F_66 ( V_71 , V_209 ,
0 , 255 , 0 , 0 ) ;
V_182 = V_46 -> V_103 - V_46 -> V_102 + 1 ;
error = F_67 ( V_71 , V_182 , 0 ) ;
if ( error )
goto V_210;
F_66 ( V_71 , V_99 ,
0 , V_211 , 0 , 0 ) ;
F_66 ( V_71 , V_96 ,
0 , V_46 -> V_85 , 0 , 0 ) ;
F_66 ( V_71 , V_97 ,
0 , V_46 -> V_86 , 0 , 0 ) ;
F_66 ( V_71 , V_98 ,
0 , 255 , 0 , 0 ) ;
F_68 ( V_71 , V_46 ) ;
F_69 ( V_31 , V_46 ) ;
error = F_70 ( V_31 -> V_104 , NULL , F_29 ,
V_75 -> V_212 | V_213 ,
V_31 -> V_185 , V_46 ) ;
if ( error ) {
F_7 ( & V_31 -> V_26 , L_31 ) ;
goto V_210;
}
error = F_33 ( V_46 ) ;
if ( error )
goto V_214;
error = F_71 ( V_71 ) ;
if ( error )
goto V_214;
error = F_72 ( & V_31 -> V_26 . V_215 , & V_216 ) ;
if ( error )
goto V_217;
return 0 ;
V_217:
F_73 ( V_71 ) ;
V_71 = NULL ;
V_214:
F_74 ( V_31 -> V_104 , V_46 ) ;
V_210:
F_16 ( V_46 -> V_66 ) ;
V_183:
F_75 ( V_71 ) ;
F_16 ( V_46 ) ;
return error ;
}
static int F_76 ( struct V_30 * V_31 )
{
struct V_61 * V_46 = F_77 ( V_31 ) ;
F_78 ( & V_31 -> V_26 . V_215 , & V_216 ) ;
F_74 ( V_46 -> V_104 , V_46 ) ;
F_73 ( V_46 -> V_71 ) ;
F_16 ( V_46 -> V_66 ) ;
F_16 ( V_46 ) ;
return 0 ;
}
static int F_79 ( struct V_25 * V_26 )
{
struct V_30 * V_31 = F_80 ( V_26 ) ;
struct V_61 * V_46 = F_77 ( V_31 ) ;
struct V_71 * V_71 = V_46 -> V_71 ;
F_81 ( & V_71 -> V_218 ) ;
if ( V_71 -> V_219 )
F_57 ( V_46 ) ;
F_82 ( & V_71 -> V_218 ) ;
return 0 ;
}
static int F_83 ( struct V_25 * V_26 )
{
struct V_30 * V_31 = F_80 ( V_26 ) ;
struct V_61 * V_46 = F_77 ( V_31 ) ;
struct V_71 * V_71 = V_46 -> V_71 ;
F_20 ( V_46 , V_1 ,
V_149 , 1 ) ;
F_41 ( V_150 ) ;
F_81 ( & V_71 -> V_218 ) ;
if ( V_71 -> V_219 )
F_56 ( V_46 ) ;
F_82 ( & V_71 -> V_218 ) ;
return 0 ;
}
