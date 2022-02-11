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
case V_25 :
return true ;
default:
return false ;
}
}
static bool F_2 ( unsigned int type )
{
switch ( type ) {
case V_2 :
case V_3 :
case V_4 :
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
case V_24 :
case V_25 :
return true ;
default:
return false ;
}
}
static void F_3 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
F_4 ( V_27 , L_1 , V_29 -> V_30 ) ;
F_4 ( V_27 , L_2 , V_29 -> V_29 [ 0 ] ) ;
F_4 ( V_27 , L_3 , V_29 -> V_29 [ 1 ] ) ;
F_4 ( V_27 , L_4 , V_29 -> V_29 [ 2 ] ) ;
F_4 ( V_27 , L_5 , V_29 -> V_29 [ 3 ] ) ;
F_4 ( V_27 , L_6 , V_29 -> V_29 [ 4 ] ) ;
F_4 ( V_27 , L_7 , V_29 -> V_29 [ 5 ] ) ;
F_4 ( V_27 , L_8 , V_29 -> V_29 [ 6 ] ) ;
F_4 ( V_27 , L_9 , V_29 -> V_31 ) ;
}
static int F_5 ( struct V_32 * V_33 ,
unsigned int V_34 )
{
T_1 V_35 ;
V_36:
if ( F_6 ( V_33 , & V_35 , 1 ) != 1 ) {
F_7 ( & V_33 -> V_27 , L_10 , V_37 ) ;
return - V_38 ;
}
switch ( V_34 ) {
case V_39 :
case V_40 :
V_35 &= ~ V_41 ;
break;
case V_42 :
if ( V_35 == V_43 )
goto V_36;
break;
default:
return - V_44 ;
}
if ( V_35 != V_34 ) {
F_7 ( & V_33 -> V_27 , L_11 ) ;
return - V_44 ;
}
return 0 ;
}
static int F_8 ( struct V_32 * V_33 )
{
T_1 V_45 [ 2 ] ;
V_45 [ 0 ] = V_46 ;
V_45 [ 1 ] = V_47 ;
if ( F_9 ( V_33 , V_45 , 2 ) != 2 ) {
F_7 ( & V_33 -> V_27 , L_12 , V_37 ) ;
return - V_38 ;
}
return 0 ;
}
static int F_10 ( struct V_32 * V_33 ,
const T_1 * V_48 , unsigned int V_49 )
{
if ( F_9 ( V_33 , V_48 , V_49 ) != V_49 ) {
F_7 ( & V_33 -> V_27 , L_12 , V_37 ) ;
return - V_38 ;
}
return 0 ;
}
static int F_11 ( struct V_32 * V_33 ,
T_2 V_50 , T_2 V_51 , void * V_35 )
{
struct V_52 V_53 [ 2 ] ;
T_1 V_45 [ 2 ] ;
V_45 [ 0 ] = V_50 & 0xff ;
V_45 [ 1 ] = ( V_50 >> 8 ) & 0xff ;
V_53 [ 0 ] . V_54 = V_33 -> V_54 ;
V_53 [ 0 ] . V_55 = 0 ;
V_53 [ 0 ] . V_51 = 2 ;
V_53 [ 0 ] . V_45 = V_45 ;
V_53 [ 1 ] . V_54 = V_33 -> V_54 ;
V_53 [ 1 ] . V_55 = V_56 ;
V_53 [ 1 ] . V_51 = V_51 ;
V_53 [ 1 ] . V_45 = V_35 ;
if ( F_12 ( V_33 -> V_57 , V_53 , 2 ) != 2 ) {
F_7 ( & V_33 -> V_27 , L_13 , V_37 ) ;
return - V_38 ;
}
return 0 ;
}
static int F_13 ( struct V_32 * V_33 , T_2 V_50 , T_1 * V_35 )
{
return F_11 ( V_33 , V_50 , 1 , V_35 ) ;
}
static int F_14 ( struct V_32 * V_33 , T_2 V_50 , T_1 V_35 )
{
T_1 V_45 [ 3 ] ;
V_45 [ 0 ] = V_50 & 0xff ;
V_45 [ 1 ] = ( V_50 >> 8 ) & 0xff ;
V_45 [ 2 ] = V_35 ;
if ( F_9 ( V_33 , V_45 , 3 ) != 3 ) {
F_7 ( & V_33 -> V_27 , L_12 , V_37 ) ;
return - V_38 ;
}
return 0 ;
}
static int F_15 ( struct V_32 * V_33 ,
T_2 V_50 , T_1 * V_58 )
{
return F_11 ( V_33 , V_50 , V_59 ,
V_58 ) ;
}
static struct V_60 *
F_16 ( struct V_61 * V_48 , T_1 type )
{
struct V_60 * V_62 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_48 -> V_64 . V_65 ; V_63 ++ ) {
V_62 = V_48 -> V_66 + V_63 ;
if ( V_62 -> type == type )
return V_62 ;
}
F_7 ( & V_48 -> V_33 -> V_27 , L_14 ) ;
return NULL ;
}
static int F_17 ( struct V_61 * V_48 ,
struct V_28 * V_29 )
{
struct V_60 * V_62 ;
T_2 V_50 ;
V_62 = F_16 ( V_48 , V_1 ) ;
if ( ! V_62 )
return - V_44 ;
V_50 = V_62 -> V_67 ;
return F_11 ( V_48 -> V_33 , V_50 ,
sizeof( struct V_28 ) , V_29 ) ;
}
static int F_18 ( struct V_61 * V_48 ,
T_1 type , T_1 V_68 , T_1 * V_35 )
{
struct V_60 * V_62 ;
T_2 V_50 ;
V_62 = F_16 ( V_48 , type ) ;
if ( ! V_62 )
return - V_44 ;
V_50 = V_62 -> V_67 ;
return F_11 ( V_48 -> V_33 , V_50 + V_68 , 1 , V_35 ) ;
}
static int F_19 ( struct V_61 * V_48 ,
T_1 type , T_1 V_68 , T_1 V_35 )
{
struct V_60 * V_62 ;
T_2 V_50 ;
V_62 = F_16 ( V_48 , type ) ;
if ( ! V_62 )
return - V_44 ;
V_50 = V_62 -> V_67 ;
return F_14 ( V_48 -> V_33 , V_50 + V_68 , V_35 ) ;
}
static void F_20 ( struct V_61 * V_48 , int V_69 )
{
struct V_70 * V_71 = V_48 -> V_71 ;
struct V_72 * V_72 = V_48 -> V_72 ;
int V_73 = V_71 [ V_69 ] . V_73 ;
int V_74 = 0 ;
int V_75 ;
for ( V_75 = 0 ; V_75 < V_76 ; V_75 ++ ) {
if ( ! V_71 [ V_75 ] . V_73 )
continue;
F_21 ( V_72 , V_75 ) ;
F_22 ( V_72 , V_77 ,
V_71 [ V_75 ] . V_73 != V_78 ) ;
if ( V_71 [ V_75 ] . V_73 != V_78 ) {
V_74 ++ ;
F_23 ( V_72 , V_79 ,
V_71 [ V_75 ] . V_80 ) ;
F_23 ( V_72 , V_81 ,
V_71 [ V_75 ] . V_82 ) ;
F_23 ( V_72 , V_83 ,
V_71 [ V_75 ] . V_84 ) ;
F_23 ( V_72 , V_85 ,
V_71 [ V_75 ] . V_86 ) ;
} else {
V_71 [ V_75 ] . V_73 = 0 ;
}
}
F_24 ( V_72 , V_87 , V_74 > 0 ) ;
if ( V_73 != V_78 ) {
F_23 ( V_72 , V_88 , V_71 [ V_69 ] . V_82 ) ;
F_23 ( V_72 , V_89 , V_71 [ V_69 ] . V_84 ) ;
F_23 ( V_72 ,
V_90 , V_71 [ V_69 ] . V_86 ) ;
}
F_25 ( V_72 ) ;
}
static void F_26 ( struct V_61 * V_48 ,
struct V_28 * V_29 , int V_75 )
{
struct V_70 * V_71 = V_48 -> V_71 ;
struct V_26 * V_27 = & V_48 -> V_33 -> V_27 ;
T_1 V_73 = V_29 -> V_29 [ 0 ] ;
int V_82 ;
int V_84 ;
int V_80 ;
int V_86 ;
if ( ! ( V_73 & V_91 ) ) {
if ( V_73 & V_78 ) {
F_4 ( V_27 , L_15 , V_75 ) ;
V_71 [ V_75 ] . V_73 = V_78 ;
F_20 ( V_48 , V_75 ) ;
}
return;
}
if ( ! ( V_73 & ( V_92 | V_93 ) ) )
return;
V_82 = ( V_29 -> V_29 [ 1 ] << 4 ) | ( ( V_29 -> V_29 [ 3 ] >> 4 ) & 0xf ) ;
V_84 = ( V_29 -> V_29 [ 2 ] << 4 ) | ( ( V_29 -> V_29 [ 3 ] & 0xf ) ) ;
if ( V_48 -> V_94 < 1024 )
V_82 = V_82 >> 2 ;
if ( V_48 -> V_95 < 1024 )
V_84 = V_84 >> 2 ;
V_80 = V_29 -> V_29 [ 4 ] ;
V_86 = V_29 -> V_29 [ 5 ] ;
F_4 ( V_27 , L_16 , V_75 ,
V_73 & V_93 ? L_17 : L_18 ,
V_82 , V_84 , V_80 ) ;
V_71 [ V_75 ] . V_73 = V_73 & V_93 ?
V_93 : V_92 ;
V_71 [ V_75 ] . V_82 = V_82 ;
V_71 [ V_75 ] . V_84 = V_84 ;
V_71 [ V_75 ] . V_80 = V_80 ;
V_71 [ V_75 ] . V_86 = V_86 ;
F_20 ( V_48 , V_75 ) ;
}
static T_3 F_27 ( int V_96 , void * V_97 )
{
struct V_61 * V_48 = V_97 ;
struct V_28 V_29 ;
struct V_60 * V_62 ;
struct V_26 * V_27 = & V_48 -> V_33 -> V_27 ;
int V_75 ;
T_1 V_30 ;
T_1 V_98 ;
T_1 V_99 ;
do {
if ( F_17 ( V_48 , & V_29 ) ) {
F_7 ( V_27 , L_19 ) ;
goto V_100;
}
V_30 = V_29 . V_30 ;
V_62 = F_16 ( V_48 , V_6 ) ;
if ( ! V_62 )
goto V_100;
V_98 = V_62 -> V_98 ;
V_99 = V_98 - V_62 -> V_101 + 1 ;
V_75 = V_30 - V_99 ;
if ( V_30 >= V_99 && V_30 <= V_98 )
F_26 ( V_48 , & V_29 , V_75 ) ;
else
F_3 ( V_27 , & V_29 ) ;
} while ( V_30 != 0xff );
V_100:
return V_102 ;
}
static int F_28 ( struct V_61 * V_48 )
{
const struct V_103 * V_104 = V_48 -> V_104 ;
struct V_60 * V_62 ;
struct V_26 * V_27 = & V_48 -> V_33 -> V_27 ;
int V_105 = 0 ;
int V_63 , V_106 , V_107 ;
if ( ! V_104 -> V_108 ) {
F_4 ( V_27 , L_20 ) ;
return 0 ;
}
for ( V_63 = 0 ; V_63 < V_48 -> V_64 . V_65 ; V_63 ++ ) {
V_62 = V_48 -> V_66 + V_63 ;
if ( ! F_2 ( V_62 -> type ) )
continue;
for ( V_106 = 0 ;
V_106 < ( V_62 -> V_109 + 1 ) * ( V_62 -> V_110 + 1 ) ;
V_106 ++ ) {
V_107 = V_105 + V_106 ;
if ( V_107 > V_104 -> V_111 ) {
F_7 ( V_27 , L_21 ) ;
return - V_44 ;
}
F_19 ( V_48 , V_62 -> type , V_106 ,
V_104 -> V_108 [ V_107 ] ) ;
}
V_105 += ( V_62 -> V_109 + 1 ) * ( V_62 -> V_110 + 1 ) ;
}
return 0 ;
}
static int F_29 ( struct V_61 * V_48 )
{
struct V_26 * V_27 = & V_48 -> V_33 -> V_27 ;
struct V_28 V_29 ;
int V_112 = 10 ;
int error ;
do {
error = F_17 ( V_48 , & V_29 ) ;
if ( error )
return error ;
} while ( V_29 . V_30 != 0xff && -- V_112 );
if ( ! V_112 ) {
F_7 ( V_27 , L_22 ) ;
return - V_113 ;
}
return 0 ;
}
static void F_30 ( struct V_61 * V_48 )
{
const struct V_103 * V_104 = V_48 -> V_104 ;
T_1 V_114 ;
F_19 ( V_48 , V_6 , V_115 ,
V_104 -> V_116 ) ;
F_19 ( V_48 , V_6 , V_117 ,
V_104 -> V_118 ) ;
F_19 ( V_48 , V_6 , V_119 ,
V_104 -> V_120 ) ;
F_19 ( V_48 , V_6 ,
V_121 , V_104 -> V_122 ) ;
F_19 ( V_48 , V_6 ,
V_123 , V_104 -> V_124 ) ;
F_19 ( V_48 , V_6 ,
V_125 , ( V_104 -> V_126 - 1 ) & 0xff ) ;
F_19 ( V_48 , V_6 ,
V_127 , ( V_104 -> V_126 - 1 ) >> 8 ) ;
F_19 ( V_48 , V_6 ,
V_128 , ( V_104 -> V_129 - 1 ) & 0xff ) ;
F_19 ( V_48 , V_6 ,
V_130 , ( V_104 -> V_129 - 1 ) >> 8 ) ;
if ( V_104 -> V_114 ) {
if ( V_104 -> V_114 < V_131 ) {
V_114 = ( V_131 - V_104 -> V_114 ) /
V_132 ;
V_114 = 0xff - V_114 + 1 ;
} else
V_114 = ( V_104 -> V_114 - V_131 ) /
V_132 ;
F_19 ( V_48 , V_22 ,
V_133 , V_114 ) ;
}
}
static int F_31 ( struct V_61 * V_48 )
{
struct V_32 * V_33 = V_48 -> V_33 ;
struct V_134 * V_64 = & V_48 -> V_64 ;
int error ;
T_1 V_35 ;
error = F_13 ( V_33 , V_135 , & V_35 ) ;
if ( error )
return error ;
V_64 -> V_136 = V_35 ;
error = F_13 ( V_33 , V_137 , & V_35 ) ;
if ( error )
return error ;
V_64 -> V_138 = V_35 ;
error = F_13 ( V_33 , V_139 , & V_35 ) ;
if ( error )
return error ;
V_64 -> V_140 = V_35 ;
error = F_13 ( V_33 , V_141 , & V_35 ) ;
if ( error )
return error ;
V_64 -> V_142 = V_35 ;
error = F_13 ( V_33 , V_143 , & V_35 ) ;
if ( error )
return error ;
V_64 -> V_65 = V_35 ;
return 0 ;
}
static int F_32 ( struct V_61 * V_48 )
{
int error ;
int V_63 ;
T_2 V_50 ;
T_1 V_30 = 0 ;
T_1 V_45 [ V_59 ] ;
for ( V_63 = 0 ; V_63 < V_48 -> V_64 . V_65 ; V_63 ++ ) {
struct V_60 * V_62 = V_48 -> V_66 + V_63 ;
V_50 = V_144 + V_59 * V_63 ;
error = F_15 ( V_48 -> V_33 , V_50 , V_45 ) ;
if ( error )
return error ;
V_62 -> type = V_45 [ 0 ] ;
V_62 -> V_67 = ( V_45 [ 2 ] << 8 ) | V_45 [ 1 ] ;
V_62 -> V_109 = V_45 [ 3 ] ;
V_62 -> V_110 = V_45 [ 4 ] ;
V_62 -> V_101 = V_45 [ 5 ] ;
if ( V_62 -> V_101 ) {
V_30 += V_62 -> V_101 *
( V_62 -> V_110 + 1 ) ;
V_62 -> V_98 = V_30 ;
}
}
return 0 ;
}
static int F_33 ( struct V_61 * V_48 )
{
struct V_32 * V_33 = V_48 -> V_33 ;
struct V_134 * V_64 = & V_48 -> V_64 ;
int error ;
T_1 V_35 ;
error = F_31 ( V_48 ) ;
if ( error )
return error ;
V_48 -> V_66 = F_34 ( V_64 -> V_65 ,
sizeof( struct V_60 ) ,
V_145 ) ;
if ( ! V_48 -> V_66 ) {
F_7 ( & V_33 -> V_27 , L_23 ) ;
return - V_146 ;
}
error = F_32 ( V_48 ) ;
if ( error )
return error ;
error = F_28 ( V_48 ) ;
if ( error )
return error ;
F_30 ( V_48 ) ;
F_19 ( V_48 , V_2 ,
V_147 ,
V_148 ) ;
F_35 ( V_149 ) ;
F_19 ( V_48 , V_2 ,
V_150 , 1 ) ;
F_35 ( V_151 ) ;
error = F_13 ( V_33 , V_152 , & V_35 ) ;
if ( error )
return error ;
V_64 -> V_153 = V_35 ;
error = F_13 ( V_33 , V_154 , & V_35 ) ;
if ( error )
return error ;
V_64 -> V_155 = V_35 ;
F_36 ( & V_33 -> V_27 ,
L_24 ,
V_64 -> V_136 , V_64 -> V_138 , V_64 -> V_140 ,
V_64 -> V_142 ) ;
F_36 ( & V_33 -> V_27 ,
L_25 ,
V_64 -> V_153 , V_64 -> V_155 ,
V_64 -> V_65 ) ;
return 0 ;
}
static void F_37 ( struct V_61 * V_48 )
{
unsigned int V_94 = V_48 -> V_104 -> V_126 - 1 ;
unsigned int V_95 = V_48 -> V_104 -> V_129 - 1 ;
if ( V_48 -> V_104 -> V_120 & V_156 ) {
V_48 -> V_94 = V_95 ;
V_48 -> V_95 = V_94 ;
} else {
V_48 -> V_94 = V_94 ;
V_48 -> V_95 = V_95 ;
}
}
static T_4 F_38 ( struct V_26 * V_27 ,
struct V_157 * V_158 , char * V_45 )
{
struct V_61 * V_48 = F_39 ( V_27 ) ;
struct V_60 * V_62 ;
int V_112 = 0 ;
int V_63 , V_106 ;
int error ;
T_1 V_35 ;
for ( V_63 = 0 ; V_63 < V_48 -> V_64 . V_65 ; V_63 ++ ) {
V_62 = V_48 -> V_66 + V_63 ;
V_112 += snprintf ( V_45 + V_112 , V_159 - V_112 ,
L_26 ,
V_63 + 1 , V_62 -> type ) ;
if ( V_112 >= V_159 )
return V_159 - 1 ;
if ( ! F_1 ( V_62 -> type ) ) {
V_112 += snprintf ( V_45 + V_112 , V_159 - V_112 ,
L_27 ) ;
if ( V_112 >= V_159 )
return V_159 - 1 ;
continue;
}
for ( V_106 = 0 ; V_106 < V_62 -> V_109 + 1 ; V_106 ++ ) {
error = F_18 ( V_48 ,
V_62 -> type , V_106 , & V_35 ) ;
if ( error )
return error ;
V_112 += snprintf ( V_45 + V_112 , V_159 - V_112 ,
L_28 , V_106 , V_35 , V_35 ) ;
if ( V_112 >= V_159 )
return V_159 - 1 ;
}
V_112 += snprintf ( V_45 + V_112 , V_159 - V_112 , L_27 ) ;
if ( V_112 >= V_159 )
return V_159 - 1 ;
}
return V_112 ;
}
static int F_40 ( struct V_26 * V_27 , const char * V_160 )
{
struct V_61 * V_48 = F_39 ( V_27 ) ;
struct V_32 * V_33 = V_48 -> V_33 ;
const struct V_161 * V_162 = NULL ;
unsigned int V_49 ;
unsigned int V_163 = 0 ;
int V_164 ;
V_164 = F_41 ( & V_162 , V_160 , V_27 ) ;
if ( V_164 ) {
F_7 ( V_27 , L_29 , V_160 ) ;
return V_164 ;
}
F_19 ( V_48 , V_2 ,
V_150 , V_165 ) ;
F_35 ( V_151 ) ;
if ( V_33 -> V_54 == V_166 )
V_33 -> V_54 = V_167 ;
else
V_33 -> V_54 = V_168 ;
V_164 = F_5 ( V_33 , V_39 ) ;
if ( V_164 )
goto V_169;
F_8 ( V_33 ) ;
while ( V_163 < V_162 -> V_109 ) {
V_164 = F_5 ( V_33 ,
V_40 ) ;
if ( V_164 )
goto V_169;
V_49 = ( ( * ( V_162 -> V_48 + V_163 ) << 8 ) | * ( V_162 -> V_48 + V_163 + 1 ) ) ;
V_49 += 2 ;
F_10 ( V_33 , V_162 -> V_48 + V_163 , V_49 ) ;
V_164 = F_5 ( V_33 ,
V_42 ) ;
if ( V_164 )
goto V_169;
V_163 += V_49 ;
F_4 ( V_27 , L_30 , V_163 , V_162 -> V_109 ) ;
}
V_169:
F_42 ( V_162 ) ;
if ( V_33 -> V_54 == V_167 )
V_33 -> V_54 = V_166 ;
else
V_33 -> V_54 = V_170 ;
return V_164 ;
}
static T_4 F_43 ( struct V_26 * V_27 ,
struct V_157 * V_158 ,
const char * V_45 , T_5 V_112 )
{
struct V_61 * V_48 = F_39 ( V_27 ) ;
int error ;
F_44 ( V_48 -> V_96 ) ;
error = F_40 ( V_27 , V_171 ) ;
if ( error ) {
F_7 ( V_27 , L_31 , error ) ;
V_112 = error ;
} else {
F_4 ( V_27 , L_32 ) ;
F_35 ( V_172 ) ;
F_45 ( V_48 -> V_66 ) ;
V_48 -> V_66 = NULL ;
F_33 ( V_48 ) ;
}
F_46 ( V_48 -> V_96 ) ;
error = F_29 ( V_48 ) ;
if ( error )
return error ;
return V_112 ;
}
static void F_47 ( struct V_61 * V_48 )
{
F_19 ( V_48 ,
V_6 , V_173 , 0x83 ) ;
}
static void F_48 ( struct V_61 * V_48 )
{
F_19 ( V_48 ,
V_6 , V_173 , 0 ) ;
}
static int F_49 ( struct V_72 * V_27 )
{
struct V_61 * V_48 = F_50 ( V_27 ) ;
F_47 ( V_48 ) ;
return 0 ;
}
static void F_51 ( struct V_72 * V_27 )
{
struct V_61 * V_48 = F_50 ( V_27 ) ;
F_48 ( V_48 ) ;
}
static int T_6 F_52 ( struct V_32 * V_33 ,
const struct V_174 * V_75 )
{
const struct V_103 * V_104 = V_33 -> V_27 . V_175 ;
struct V_61 * V_48 ;
struct V_72 * V_72 ;
int error ;
if ( ! V_104 )
return - V_44 ;
V_48 = F_53 ( sizeof( struct V_61 ) , V_145 ) ;
V_72 = F_54 () ;
if ( ! V_48 || ! V_72 ) {
F_7 ( & V_33 -> V_27 , L_23 ) ;
error = - V_146 ;
goto V_176;
}
V_72 -> V_177 = L_33 ;
V_72 -> V_75 . V_178 = V_179 ;
V_72 -> V_27 . V_180 = & V_33 -> V_27 ;
V_72 -> V_181 = F_49 ;
V_72 -> V_182 = F_51 ;
V_48 -> V_33 = V_33 ;
V_48 -> V_72 = V_72 ;
V_48 -> V_104 = V_104 ;
V_48 -> V_96 = V_33 -> V_96 ;
F_37 ( V_48 ) ;
F_55 ( V_183 , V_72 -> V_184 ) ;
F_55 ( V_185 , V_72 -> V_184 ) ;
F_55 ( V_87 , V_72 -> V_186 ) ;
F_56 ( V_72 , V_88 ,
0 , V_48 -> V_94 , 0 , 0 ) ;
F_56 ( V_72 , V_89 ,
0 , V_48 -> V_95 , 0 , 0 ) ;
F_56 ( V_72 , V_90 ,
0 , 255 , 0 , 0 ) ;
F_57 ( V_72 , V_76 ) ;
F_56 ( V_72 , V_79 ,
0 , V_187 , 0 , 0 ) ;
F_56 ( V_72 , V_81 ,
0 , V_48 -> V_94 , 0 , 0 ) ;
F_56 ( V_72 , V_83 ,
0 , V_48 -> V_95 , 0 , 0 ) ;
F_56 ( V_72 , V_85 ,
0 , 255 , 0 , 0 ) ;
F_58 ( V_72 , V_48 ) ;
F_59 ( V_33 , V_48 ) ;
error = F_33 ( V_48 ) ;
if ( error )
goto V_188;
error = F_60 ( V_33 -> V_96 , NULL , F_27 ,
V_104 -> V_189 , V_33 -> V_27 . V_190 -> V_177 , V_48 ) ;
if ( error ) {
F_7 ( & V_33 -> V_27 , L_34 ) ;
goto V_188;
}
error = F_29 ( V_48 ) ;
if ( error )
goto V_191;
error = F_61 ( V_72 ) ;
if ( error )
goto V_191;
error = F_62 ( & V_33 -> V_27 . V_192 , & V_193 ) ;
if ( error )
goto V_194;
return 0 ;
V_194:
F_63 ( V_72 ) ;
V_72 = NULL ;
V_191:
F_64 ( V_33 -> V_96 , V_48 ) ;
V_188:
F_45 ( V_48 -> V_66 ) ;
V_176:
F_65 ( V_72 ) ;
F_45 ( V_48 ) ;
return error ;
}
static int T_7 F_66 ( struct V_32 * V_33 )
{
struct V_61 * V_48 = F_67 ( V_33 ) ;
F_68 ( & V_33 -> V_27 . V_192 , & V_193 ) ;
F_64 ( V_48 -> V_96 , V_48 ) ;
F_63 ( V_48 -> V_72 ) ;
F_45 ( V_48 -> V_66 ) ;
F_45 ( V_48 ) ;
return 0 ;
}
static int F_69 ( struct V_26 * V_27 )
{
struct V_32 * V_33 = F_70 ( V_27 ) ;
struct V_61 * V_48 = F_67 ( V_33 ) ;
struct V_72 * V_72 = V_48 -> V_72 ;
F_71 ( & V_72 -> V_195 ) ;
if ( V_72 -> V_196 )
F_48 ( V_48 ) ;
F_72 ( & V_72 -> V_195 ) ;
return 0 ;
}
static int F_73 ( struct V_26 * V_27 )
{
struct V_32 * V_33 = F_70 ( V_27 ) ;
struct V_61 * V_48 = F_67 ( V_33 ) ;
struct V_72 * V_72 = V_48 -> V_72 ;
F_19 ( V_48 , V_2 ,
V_150 , 1 ) ;
F_35 ( V_151 ) ;
F_71 ( & V_72 -> V_195 ) ;
if ( V_72 -> V_196 )
F_47 ( V_48 ) ;
F_72 ( & V_72 -> V_195 ) ;
return 0 ;
}
