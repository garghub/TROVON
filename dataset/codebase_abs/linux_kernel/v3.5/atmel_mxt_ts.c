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
F_4 ( V_27 , L_1 ,
V_29 -> V_30 , V_29 -> V_29 [ 0 ] , V_29 -> V_29 [ 1 ] ,
V_29 -> V_29 [ 2 ] , V_29 -> V_29 [ 3 ] , V_29 -> V_29 [ 4 ] ,
V_29 -> V_29 [ 5 ] , V_29 -> V_29 [ 6 ] ) ;
}
static int F_5 ( struct V_31 * V_32 ,
unsigned int V_33 )
{
T_1 V_34 ;
V_35:
if ( F_6 ( V_32 , & V_34 , 1 ) != 1 ) {
F_7 ( & V_32 -> V_27 , L_2 , V_36 ) ;
return - V_37 ;
}
switch ( V_33 ) {
case V_38 :
case V_39 :
V_34 &= ~ V_40 ;
break;
case V_41 :
if ( V_34 == V_42 )
goto V_35;
break;
default:
return - V_43 ;
}
if ( V_34 != V_33 ) {
F_7 ( & V_32 -> V_27 , L_3 ) ;
return - V_43 ;
}
return 0 ;
}
static int F_8 ( struct V_31 * V_32 )
{
T_1 V_44 [ 2 ] ;
V_44 [ 0 ] = V_45 ;
V_44 [ 1 ] = V_46 ;
if ( F_9 ( V_32 , V_44 , 2 ) != 2 ) {
F_7 ( & V_32 -> V_27 , L_4 , V_36 ) ;
return - V_37 ;
}
return 0 ;
}
static int F_10 ( struct V_31 * V_32 ,
const T_1 * V_47 , unsigned int V_48 )
{
if ( F_9 ( V_32 , V_47 , V_48 ) != V_48 ) {
F_7 ( & V_32 -> V_27 , L_4 , V_36 ) ;
return - V_37 ;
}
return 0 ;
}
static int F_11 ( struct V_31 * V_32 ,
T_2 V_49 , T_2 V_50 , void * V_34 )
{
struct V_51 V_52 [ 2 ] ;
T_1 V_44 [ 2 ] ;
V_44 [ 0 ] = V_49 & 0xff ;
V_44 [ 1 ] = ( V_49 >> 8 ) & 0xff ;
V_52 [ 0 ] . V_53 = V_32 -> V_53 ;
V_52 [ 0 ] . V_54 = 0 ;
V_52 [ 0 ] . V_50 = 2 ;
V_52 [ 0 ] . V_44 = V_44 ;
V_52 [ 1 ] . V_53 = V_32 -> V_53 ;
V_52 [ 1 ] . V_54 = V_55 ;
V_52 [ 1 ] . V_50 = V_50 ;
V_52 [ 1 ] . V_44 = V_34 ;
if ( F_12 ( V_32 -> V_56 , V_52 , 2 ) != 2 ) {
F_7 ( & V_32 -> V_27 , L_5 , V_36 ) ;
return - V_37 ;
}
return 0 ;
}
static int F_13 ( struct V_31 * V_32 , T_2 V_49 , T_1 * V_34 )
{
return F_11 ( V_32 , V_49 , 1 , V_34 ) ;
}
static int F_14 ( struct V_31 * V_32 , T_2 V_49 , T_1 V_34 )
{
T_1 V_44 [ 3 ] ;
V_44 [ 0 ] = V_49 & 0xff ;
V_44 [ 1 ] = ( V_49 >> 8 ) & 0xff ;
V_44 [ 2 ] = V_34 ;
if ( F_9 ( V_32 , V_44 , 3 ) != 3 ) {
F_7 ( & V_32 -> V_27 , L_4 , V_36 ) ;
return - V_37 ;
}
return 0 ;
}
static int F_15 ( struct V_31 * V_32 ,
T_2 V_49 , T_1 * V_57 )
{
return F_11 ( V_32 , V_49 , V_58 ,
V_57 ) ;
}
static struct V_59 *
F_16 ( struct V_60 * V_47 , T_1 type )
{
struct V_59 * V_61 ;
int V_62 ;
for ( V_62 = 0 ; V_62 < V_47 -> V_63 . V_64 ; V_62 ++ ) {
V_61 = V_47 -> V_65 + V_62 ;
if ( V_61 -> type == type )
return V_61 ;
}
F_7 ( & V_47 -> V_32 -> V_27 , L_6 ) ;
return NULL ;
}
static int F_17 ( struct V_60 * V_47 ,
struct V_28 * V_29 )
{
struct V_59 * V_61 ;
T_2 V_49 ;
V_61 = F_16 ( V_47 , V_1 ) ;
if ( ! V_61 )
return - V_43 ;
V_49 = V_61 -> V_66 ;
return F_11 ( V_47 -> V_32 , V_49 ,
sizeof( struct V_28 ) , V_29 ) ;
}
static int F_18 ( struct V_60 * V_47 ,
T_1 type , T_1 V_67 , T_1 * V_34 )
{
struct V_59 * V_61 ;
T_2 V_49 ;
V_61 = F_16 ( V_47 , type ) ;
if ( ! V_61 )
return - V_43 ;
V_49 = V_61 -> V_66 ;
return F_11 ( V_47 -> V_32 , V_49 + V_67 , 1 , V_34 ) ;
}
static int F_19 ( struct V_60 * V_47 ,
T_1 type , T_1 V_67 , T_1 V_34 )
{
struct V_59 * V_61 ;
T_2 V_49 ;
V_61 = F_16 ( V_47 , type ) ;
if ( ! V_61 || V_67 >= V_61 -> V_68 + 1 )
return - V_43 ;
V_49 = V_61 -> V_66 ;
return F_14 ( V_47 -> V_32 , V_49 + V_67 , V_34 ) ;
}
static void F_20 ( struct V_60 * V_47 , int V_69 )
{
struct V_70 * V_71 = V_47 -> V_71 ;
struct V_72 * V_72 = V_47 -> V_72 ;
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
static void F_26 ( struct V_60 * V_47 ,
struct V_28 * V_29 , int V_75 )
{
struct V_70 * V_71 = V_47 -> V_71 ;
struct V_26 * V_27 = & V_47 -> V_32 -> V_27 ;
T_1 V_73 = V_29 -> V_29 [ 0 ] ;
int V_82 ;
int V_84 ;
int V_80 ;
int V_86 ;
if ( ! ( V_73 & V_91 ) ) {
if ( V_73 & V_78 ) {
F_4 ( V_27 , L_7 , V_75 ) ;
V_71 [ V_75 ] . V_73 = V_78 ;
F_20 ( V_47 , V_75 ) ;
}
return;
}
if ( ! ( V_73 & ( V_92 | V_93 ) ) )
return;
V_82 = ( V_29 -> V_29 [ 1 ] << 4 ) | ( ( V_29 -> V_29 [ 3 ] >> 4 ) & 0xf ) ;
V_84 = ( V_29 -> V_29 [ 2 ] << 4 ) | ( ( V_29 -> V_29 [ 3 ] & 0xf ) ) ;
if ( V_47 -> V_94 < 1024 )
V_82 = V_82 >> 2 ;
if ( V_47 -> V_95 < 1024 )
V_84 = V_84 >> 2 ;
V_80 = V_29 -> V_29 [ 4 ] ;
V_86 = V_29 -> V_29 [ 5 ] ;
F_4 ( V_27 , L_8 , V_75 ,
V_73 & V_93 ? L_9 : L_10 ,
V_82 , V_84 , V_80 ) ;
V_71 [ V_75 ] . V_73 = V_73 & V_93 ?
V_93 : V_92 ;
V_71 [ V_75 ] . V_82 = V_82 ;
V_71 [ V_75 ] . V_84 = V_84 ;
V_71 [ V_75 ] . V_80 = V_80 ;
V_71 [ V_75 ] . V_86 = V_86 ;
F_20 ( V_47 , V_75 ) ;
}
static T_3 F_27 ( int V_96 , void * V_97 )
{
struct V_60 * V_47 = V_97 ;
struct V_28 V_29 ;
struct V_59 * V_61 ;
struct V_26 * V_27 = & V_47 -> V_32 -> V_27 ;
int V_75 ;
T_1 V_30 ;
T_1 V_98 ;
T_1 V_99 ;
do {
if ( F_17 ( V_47 , & V_29 ) ) {
F_7 ( V_27 , L_11 ) ;
goto V_100;
}
V_30 = V_29 . V_30 ;
V_61 = F_16 ( V_47 , V_6 ) ;
if ( ! V_61 )
goto V_100;
V_98 = V_61 -> V_98 ;
V_99 = V_98 - V_61 -> V_101 + 1 ;
V_75 = V_30 - V_99 ;
if ( V_30 >= V_99 && V_30 <= V_98 )
F_26 ( V_47 , & V_29 , V_75 ) ;
else
F_3 ( V_27 , & V_29 ) ;
} while ( V_30 != 0xff );
V_100:
return V_102 ;
}
static int F_28 ( struct V_60 * V_47 )
{
const struct V_103 * V_104 = V_47 -> V_104 ;
struct V_59 * V_61 ;
struct V_26 * V_27 = & V_47 -> V_32 -> V_27 ;
int V_105 = 0 ;
int V_62 , V_106 , V_107 ;
if ( ! V_104 -> V_108 ) {
F_4 ( V_27 , L_12 ) ;
return 0 ;
}
for ( V_62 = 0 ; V_62 < V_47 -> V_63 . V_64 ; V_62 ++ ) {
V_61 = V_47 -> V_65 + V_62 ;
if ( ! F_2 ( V_61 -> type ) )
continue;
for ( V_106 = 0 ;
V_106 < ( V_61 -> V_68 + 1 ) * ( V_61 -> V_109 + 1 ) ;
V_106 ++ ) {
V_107 = V_105 + V_106 ;
if ( V_107 > V_104 -> V_110 ) {
F_7 ( V_27 , L_13 ) ;
return - V_43 ;
}
F_19 ( V_47 , V_61 -> type , V_106 ,
V_104 -> V_108 [ V_107 ] ) ;
}
V_105 += ( V_61 -> V_68 + 1 ) * ( V_61 -> V_109 + 1 ) ;
}
return 0 ;
}
static int F_29 ( struct V_60 * V_47 )
{
struct V_26 * V_27 = & V_47 -> V_32 -> V_27 ;
struct V_28 V_29 ;
int V_111 = 10 ;
int error ;
do {
error = F_17 ( V_47 , & V_29 ) ;
if ( error )
return error ;
} while ( V_29 . V_30 != 0xff && -- V_111 );
if ( ! V_111 ) {
F_7 ( V_27 , L_14 ) ;
return - V_112 ;
}
return 0 ;
}
static void F_30 ( struct V_60 * V_47 )
{
const struct V_103 * V_104 = V_47 -> V_104 ;
T_1 V_113 ;
F_19 ( V_47 , V_6 , V_114 ,
V_104 -> V_115 ) ;
F_19 ( V_47 , V_6 , V_116 ,
V_104 -> V_117 ) ;
F_19 ( V_47 , V_6 , V_118 ,
V_104 -> V_119 ) ;
F_19 ( V_47 , V_6 ,
V_120 , V_104 -> V_121 ) ;
F_19 ( V_47 , V_6 ,
V_122 , V_104 -> V_123 ) ;
F_19 ( V_47 , V_6 ,
V_124 , ( V_104 -> V_125 - 1 ) & 0xff ) ;
F_19 ( V_47 , V_6 ,
V_126 , ( V_104 -> V_125 - 1 ) >> 8 ) ;
F_19 ( V_47 , V_6 ,
V_127 , ( V_104 -> V_128 - 1 ) & 0xff ) ;
F_19 ( V_47 , V_6 ,
V_129 , ( V_104 -> V_128 - 1 ) >> 8 ) ;
if ( V_104 -> V_113 ) {
if ( V_104 -> V_113 < V_130 ) {
V_113 = ( V_130 - V_104 -> V_113 ) /
V_131 ;
V_113 = 0xff - V_113 + 1 ;
} else
V_113 = ( V_104 -> V_113 - V_130 ) /
V_131 ;
F_19 ( V_47 , V_22 ,
V_132 , V_113 ) ;
}
}
static int F_31 ( struct V_60 * V_47 )
{
struct V_31 * V_32 = V_47 -> V_32 ;
struct V_133 * V_63 = & V_47 -> V_63 ;
int error ;
T_1 V_34 ;
error = F_13 ( V_32 , V_134 , & V_34 ) ;
if ( error )
return error ;
V_63 -> V_135 = V_34 ;
error = F_13 ( V_32 , V_136 , & V_34 ) ;
if ( error )
return error ;
V_63 -> V_137 = V_34 ;
error = F_13 ( V_32 , V_138 , & V_34 ) ;
if ( error )
return error ;
V_63 -> V_139 = V_34 ;
error = F_13 ( V_32 , V_140 , & V_34 ) ;
if ( error )
return error ;
V_63 -> V_141 = V_34 ;
error = F_13 ( V_32 , V_142 , & V_34 ) ;
if ( error )
return error ;
V_63 -> V_64 = V_34 ;
return 0 ;
}
static int F_32 ( struct V_60 * V_47 )
{
int error ;
int V_62 ;
T_2 V_49 ;
T_1 V_30 = 0 ;
T_1 V_44 [ V_58 ] ;
for ( V_62 = 0 ; V_62 < V_47 -> V_63 . V_64 ; V_62 ++ ) {
struct V_59 * V_61 = V_47 -> V_65 + V_62 ;
V_49 = V_143 + V_58 * V_62 ;
error = F_15 ( V_47 -> V_32 , V_49 , V_44 ) ;
if ( error )
return error ;
V_61 -> type = V_44 [ 0 ] ;
V_61 -> V_66 = ( V_44 [ 2 ] << 8 ) | V_44 [ 1 ] ;
V_61 -> V_68 = V_44 [ 3 ] ;
V_61 -> V_109 = V_44 [ 4 ] ;
V_61 -> V_101 = V_44 [ 5 ] ;
if ( V_61 -> V_101 ) {
V_30 += V_61 -> V_101 *
( V_61 -> V_109 + 1 ) ;
V_61 -> V_98 = V_30 ;
}
}
return 0 ;
}
static int F_33 ( struct V_60 * V_47 )
{
struct V_31 * V_32 = V_47 -> V_32 ;
struct V_133 * V_63 = & V_47 -> V_63 ;
int error ;
T_1 V_34 ;
error = F_31 ( V_47 ) ;
if ( error )
return error ;
V_47 -> V_65 = F_34 ( V_63 -> V_64 ,
sizeof( struct V_59 ) ,
V_144 ) ;
if ( ! V_47 -> V_65 ) {
F_7 ( & V_32 -> V_27 , L_15 ) ;
return - V_145 ;
}
error = F_32 ( V_47 ) ;
if ( error )
return error ;
error = F_28 ( V_47 ) ;
if ( error )
return error ;
F_30 ( V_47 ) ;
F_19 ( V_47 , V_2 ,
V_146 ,
V_147 ) ;
F_35 ( V_148 ) ;
F_19 ( V_47 , V_2 ,
V_149 , 1 ) ;
F_35 ( V_150 ) ;
error = F_13 ( V_32 , V_151 , & V_34 ) ;
if ( error )
return error ;
V_63 -> V_152 = V_34 ;
error = F_13 ( V_32 , V_153 , & V_34 ) ;
if ( error )
return error ;
V_63 -> V_154 = V_34 ;
F_36 ( & V_32 -> V_27 ,
L_16 ,
V_63 -> V_135 , V_63 -> V_137 , V_63 -> V_139 ,
V_63 -> V_141 ) ;
F_36 ( & V_32 -> V_27 ,
L_17 ,
V_63 -> V_152 , V_63 -> V_154 ,
V_63 -> V_64 ) ;
return 0 ;
}
static void F_37 ( struct V_60 * V_47 )
{
unsigned int V_94 = V_47 -> V_104 -> V_125 - 1 ;
unsigned int V_95 = V_47 -> V_104 -> V_128 - 1 ;
if ( V_47 -> V_104 -> V_119 & V_155 ) {
V_47 -> V_94 = V_95 ;
V_47 -> V_95 = V_94 ;
} else {
V_47 -> V_94 = V_94 ;
V_47 -> V_95 = V_95 ;
}
}
static T_4 F_38 ( struct V_26 * V_27 ,
struct V_156 * V_157 , char * V_44 )
{
struct V_60 * V_47 = F_39 ( V_27 ) ;
struct V_59 * V_61 ;
int V_111 = 0 ;
int V_62 , V_106 ;
int error ;
T_1 V_34 ;
for ( V_62 = 0 ; V_62 < V_47 -> V_63 . V_64 ; V_62 ++ ) {
V_61 = V_47 -> V_65 + V_62 ;
V_111 += snprintf ( V_44 + V_111 , V_158 - V_111 ,
L_18 ,
V_62 + 1 , V_61 -> type ) ;
if ( V_111 >= V_158 )
return V_158 - 1 ;
if ( ! F_1 ( V_61 -> type ) ) {
V_111 += snprintf ( V_44 + V_111 , V_158 - V_111 ,
L_19 ) ;
if ( V_111 >= V_158 )
return V_158 - 1 ;
continue;
}
for ( V_106 = 0 ; V_106 < V_61 -> V_68 + 1 ; V_106 ++ ) {
error = F_18 ( V_47 ,
V_61 -> type , V_106 , & V_34 ) ;
if ( error )
return error ;
V_111 += snprintf ( V_44 + V_111 , V_158 - V_111 ,
L_20 , V_106 , V_34 , V_34 ) ;
if ( V_111 >= V_158 )
return V_158 - 1 ;
}
V_111 += snprintf ( V_44 + V_111 , V_158 - V_111 , L_19 ) ;
if ( V_111 >= V_158 )
return V_158 - 1 ;
}
return V_111 ;
}
static int F_40 ( struct V_26 * V_27 , const char * V_159 )
{
struct V_60 * V_47 = F_39 ( V_27 ) ;
struct V_31 * V_32 = V_47 -> V_32 ;
const struct V_160 * V_161 = NULL ;
unsigned int V_48 ;
unsigned int V_162 = 0 ;
int V_163 ;
V_163 = F_41 ( & V_161 , V_159 , V_27 ) ;
if ( V_163 ) {
F_7 ( V_27 , L_21 , V_159 ) ;
return V_163 ;
}
F_19 ( V_47 , V_2 ,
V_149 , V_164 ) ;
F_35 ( V_150 ) ;
if ( V_32 -> V_53 == V_165 )
V_32 -> V_53 = V_166 ;
else
V_32 -> V_53 = V_167 ;
V_163 = F_5 ( V_32 , V_38 ) ;
if ( V_163 )
goto V_168;
F_8 ( V_32 ) ;
while ( V_162 < V_161 -> V_68 ) {
V_163 = F_5 ( V_32 ,
V_39 ) ;
if ( V_163 )
goto V_168;
V_48 = ( ( * ( V_161 -> V_47 + V_162 ) << 8 ) | * ( V_161 -> V_47 + V_162 + 1 ) ) ;
V_48 += 2 ;
F_10 ( V_32 , V_161 -> V_47 + V_162 , V_48 ) ;
V_163 = F_5 ( V_32 ,
V_41 ) ;
if ( V_163 )
goto V_168;
V_162 += V_48 ;
F_4 ( V_27 , L_22 , V_162 , V_161 -> V_68 ) ;
}
V_168:
F_42 ( V_161 ) ;
if ( V_32 -> V_53 == V_166 )
V_32 -> V_53 = V_165 ;
else
V_32 -> V_53 = V_169 ;
return V_163 ;
}
static T_4 F_43 ( struct V_26 * V_27 ,
struct V_156 * V_157 ,
const char * V_44 , T_5 V_111 )
{
struct V_60 * V_47 = F_39 ( V_27 ) ;
int error ;
F_44 ( V_47 -> V_96 ) ;
error = F_40 ( V_27 , V_170 ) ;
if ( error ) {
F_7 ( V_27 , L_23 , error ) ;
V_111 = error ;
} else {
F_4 ( V_27 , L_24 ) ;
F_35 ( V_171 ) ;
F_45 ( V_47 -> V_65 ) ;
V_47 -> V_65 = NULL ;
F_33 ( V_47 ) ;
}
F_46 ( V_47 -> V_96 ) ;
error = F_29 ( V_47 ) ;
if ( error )
return error ;
return V_111 ;
}
static void F_47 ( struct V_60 * V_47 )
{
F_19 ( V_47 ,
V_6 , V_172 , 0x83 ) ;
}
static void F_48 ( struct V_60 * V_47 )
{
F_19 ( V_47 ,
V_6 , V_172 , 0 ) ;
}
static int F_49 ( struct V_72 * V_27 )
{
struct V_60 * V_47 = F_50 ( V_27 ) ;
F_47 ( V_47 ) ;
return 0 ;
}
static void F_51 ( struct V_72 * V_27 )
{
struct V_60 * V_47 = F_50 ( V_27 ) ;
F_48 ( V_47 ) ;
}
static int T_6 F_52 ( struct V_31 * V_32 ,
const struct V_173 * V_75 )
{
const struct V_103 * V_104 = V_32 -> V_27 . V_174 ;
struct V_60 * V_47 ;
struct V_72 * V_72 ;
int error ;
if ( ! V_104 )
return - V_43 ;
V_47 = F_53 ( sizeof( struct V_60 ) , V_144 ) ;
V_72 = F_54 () ;
if ( ! V_47 || ! V_72 ) {
F_7 ( & V_32 -> V_27 , L_15 ) ;
error = - V_145 ;
goto V_175;
}
V_72 -> V_176 = L_25 ;
V_72 -> V_75 . V_177 = V_178 ;
V_72 -> V_27 . V_179 = & V_32 -> V_27 ;
V_72 -> V_180 = F_49 ;
V_72 -> V_181 = F_51 ;
V_47 -> V_32 = V_32 ;
V_47 -> V_72 = V_72 ;
V_47 -> V_104 = V_104 ;
V_47 -> V_96 = V_32 -> V_96 ;
F_37 ( V_47 ) ;
F_55 ( V_182 , V_72 -> V_183 ) ;
F_55 ( V_184 , V_72 -> V_183 ) ;
F_55 ( V_87 , V_72 -> V_185 ) ;
F_56 ( V_72 , V_88 ,
0 , V_47 -> V_94 , 0 , 0 ) ;
F_56 ( V_72 , V_89 ,
0 , V_47 -> V_95 , 0 , 0 ) ;
F_56 ( V_72 , V_90 ,
0 , 255 , 0 , 0 ) ;
F_57 ( V_72 , V_76 ) ;
F_56 ( V_72 , V_79 ,
0 , V_186 , 0 , 0 ) ;
F_56 ( V_72 , V_81 ,
0 , V_47 -> V_94 , 0 , 0 ) ;
F_56 ( V_72 , V_83 ,
0 , V_47 -> V_95 , 0 , 0 ) ;
F_56 ( V_72 , V_85 ,
0 , 255 , 0 , 0 ) ;
F_58 ( V_72 , V_47 ) ;
F_59 ( V_32 , V_47 ) ;
error = F_33 ( V_47 ) ;
if ( error )
goto V_187;
error = F_60 ( V_32 -> V_96 , NULL , F_27 ,
V_104 -> V_188 | V_189 ,
V_32 -> V_27 . V_190 -> V_176 , V_47 ) ;
if ( error ) {
F_7 ( & V_32 -> V_27 , L_26 ) ;
goto V_187;
}
error = F_29 ( V_47 ) ;
if ( error )
goto V_191;
error = F_61 ( V_72 ) ;
if ( error )
goto V_191;
error = F_62 ( & V_32 -> V_27 . V_192 , & V_193 ) ;
if ( error )
goto V_194;
return 0 ;
V_194:
F_63 ( V_72 ) ;
V_72 = NULL ;
V_191:
F_64 ( V_32 -> V_96 , V_47 ) ;
V_187:
F_45 ( V_47 -> V_65 ) ;
V_175:
F_65 ( V_72 ) ;
F_45 ( V_47 ) ;
return error ;
}
static int T_7 F_66 ( struct V_31 * V_32 )
{
struct V_60 * V_47 = F_67 ( V_32 ) ;
F_68 ( & V_32 -> V_27 . V_192 , & V_193 ) ;
F_64 ( V_47 -> V_96 , V_47 ) ;
F_63 ( V_47 -> V_72 ) ;
F_45 ( V_47 -> V_65 ) ;
F_45 ( V_47 ) ;
return 0 ;
}
static int F_69 ( struct V_26 * V_27 )
{
struct V_31 * V_32 = F_70 ( V_27 ) ;
struct V_60 * V_47 = F_67 ( V_32 ) ;
struct V_72 * V_72 = V_47 -> V_72 ;
F_71 ( & V_72 -> V_195 ) ;
if ( V_72 -> V_196 )
F_48 ( V_47 ) ;
F_72 ( & V_72 -> V_195 ) ;
return 0 ;
}
static int F_73 ( struct V_26 * V_27 )
{
struct V_31 * V_32 = F_70 ( V_27 ) ;
struct V_60 * V_47 = F_67 ( V_32 ) ;
struct V_72 * V_72 = V_47 -> V_72 ;
F_19 ( V_47 , V_2 ,
V_149 , 1 ) ;
F_35 ( V_150 ) ;
F_71 ( & V_72 -> V_195 ) ;
if ( V_72 -> V_196 )
F_47 ( V_47 ) ;
F_72 ( & V_72 -> V_195 ) ;
return 0 ;
}
