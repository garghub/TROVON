static T_1 F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 + 1 ;
}
static T_1 F_2 ( const struct V_1 * V_2 )
{
return V_2 -> V_4 + 1 ;
}
static bool F_3 ( unsigned int type )
{
switch ( type ) {
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
case V_26 :
case V_27 :
case V_28 :
return true ;
default:
return false ;
}
}
static bool F_4 ( unsigned int type )
{
switch ( type ) {
case V_5 :
case V_6 :
case V_7 :
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
case V_27 :
case V_28 :
return true ;
default:
return false ;
}
}
static void F_5 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
F_6 ( V_30 , L_1 ,
V_32 -> V_33 , 7 , V_32 -> V_32 ) ;
}
static int F_7 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
unsigned int V_38 )
{
struct V_29 * V_30 = & V_35 -> V_39 -> V_30 ;
unsigned long V_40 = F_8 ( V_38 ) ;
long V_41 ;
V_41 = F_9 ( V_37 , V_40 ) ;
if ( V_41 < 0 ) {
return V_41 ;
} else if ( V_41 == 0 ) {
F_10 ( V_30 , L_2 ) ;
return - V_42 ;
}
return 0 ;
}
static int F_11 ( struct V_34 * V_35 ,
T_2 * V_43 , unsigned int V_44 )
{
int V_41 ;
struct V_45 V_46 ;
V_46 . V_47 = V_35 -> V_48 ;
V_46 . V_49 = V_35 -> V_39 -> V_49 & V_50 ;
V_46 . V_49 |= V_51 ;
V_46 . V_52 = V_44 ;
V_46 . V_53 = V_43 ;
V_41 = F_12 ( V_35 -> V_39 -> V_54 , & V_46 , 1 ) ;
if ( V_41 == 1 ) {
V_41 = 0 ;
} else {
V_41 = V_41 < 0 ? V_41 : - V_55 ;
F_10 ( & V_35 -> V_39 -> V_30 , L_3 ,
V_56 , V_41 ) ;
}
return V_41 ;
}
static int F_13 ( struct V_34 * V_35 ,
const T_2 * const V_43 , unsigned int V_44 )
{
int V_41 ;
struct V_45 V_46 ;
V_46 . V_47 = V_35 -> V_48 ;
V_46 . V_49 = V_35 -> V_39 -> V_49 & V_50 ;
V_46 . V_52 = V_44 ;
V_46 . V_53 = ( T_2 * ) V_43 ;
V_41 = F_12 ( V_35 -> V_39 -> V_54 , & V_46 , 1 ) ;
if ( V_41 == 1 ) {
V_41 = 0 ;
} else {
V_41 = V_41 < 0 ? V_41 : - V_55 ;
F_10 ( & V_35 -> V_39 -> V_30 , L_4 ,
V_56 , V_41 ) ;
}
return V_41 ;
}
static int F_14 ( struct V_34 * V_35 )
{
T_2 V_57 = V_35 -> V_39 -> V_47 ;
T_2 V_58 ;
switch ( V_57 ) {
case 0x4a :
case 0x4b :
case 0x4c :
case 0x4d :
case 0x5a :
case 0x5b :
V_58 = V_57 - 0x26 ;
break;
default:
F_10 ( & V_35 -> V_39 -> V_30 ,
L_5 ,
V_57 ) ;
return - V_59 ;
}
V_35 -> V_48 = V_58 ;
return 0 ;
}
static T_2 F_15 ( struct V_34 * V_35 , T_2 V_43 )
{
struct V_29 * V_30 = & V_35 -> V_39 -> V_30 ;
T_2 V_53 [ 3 ] ;
if ( V_43 & V_60 ) {
if ( F_11 ( V_35 , & V_53 [ 0 ] , 3 ) != 0 ) {
F_10 ( V_30 , L_6 , V_56 ) ;
return V_43 ;
}
F_6 ( V_30 , L_7 , V_53 [ 1 ] , V_53 [ 2 ] ) ;
return V_53 [ 0 ] ;
} else {
F_6 ( V_30 , L_8 , V_43 & V_61 ) ;
return V_43 ;
}
}
static int F_16 ( struct V_34 * V_35 , unsigned int V_62 )
{
struct V_29 * V_30 = & V_35 -> V_39 -> V_30 ;
T_2 V_43 ;
int V_41 ;
V_63:
if ( V_62 != V_64 ) {
V_41 = F_7 ( V_35 , & V_35 -> V_65 ,
V_66 ) ;
if ( V_41 ) {
F_10 ( V_30 , L_9 , V_41 ) ;
return V_41 ;
}
}
V_41 = F_11 ( V_35 , & V_43 , 1 ) ;
if ( V_41 )
return V_41 ;
if ( V_62 == V_64 )
V_43 = F_15 ( V_35 , V_43 ) ;
switch ( V_62 ) {
case V_64 :
case V_67 :
V_43 &= ~ V_68 ;
break;
case V_69 :
if ( V_43 == V_70 ) {
goto V_63;
} else if ( V_43 == V_71 ) {
F_10 ( V_30 , L_10 ) ;
return - V_59 ;
}
break;
default:
return - V_59 ;
}
if ( V_43 != V_62 ) {
F_10 ( V_30 , L_11 ,
V_43 , V_62 ) ;
return - V_59 ;
}
return 0 ;
}
static int F_17 ( struct V_34 * V_35 )
{
int V_41 ;
T_2 V_53 [ 2 ] ;
V_53 [ 0 ] = V_72 ;
V_53 [ 1 ] = V_73 ;
V_41 = F_13 ( V_35 , V_53 , 2 ) ;
if ( V_41 )
return V_41 ;
return 0 ;
}
static int F_18 ( struct V_74 * V_39 ,
T_3 V_75 , T_3 V_52 , void * V_43 )
{
struct V_45 V_76 [ 2 ] ;
T_2 V_53 [ 2 ] ;
int V_41 ;
V_53 [ 0 ] = V_75 & 0xff ;
V_53 [ 1 ] = ( V_75 >> 8 ) & 0xff ;
V_76 [ 0 ] . V_47 = V_39 -> V_47 ;
V_76 [ 0 ] . V_49 = 0 ;
V_76 [ 0 ] . V_52 = 2 ;
V_76 [ 0 ] . V_53 = V_53 ;
V_76 [ 1 ] . V_47 = V_39 -> V_47 ;
V_76 [ 1 ] . V_49 = V_51 ;
V_76 [ 1 ] . V_52 = V_52 ;
V_76 [ 1 ] . V_53 = V_43 ;
V_41 = F_12 ( V_39 -> V_54 , V_76 , 2 ) ;
if ( V_41 == 2 ) {
V_41 = 0 ;
} else {
if ( V_41 >= 0 )
V_41 = - V_55 ;
F_10 ( & V_39 -> V_30 , L_12 ,
V_56 , V_41 ) ;
}
return V_41 ;
}
static int F_19 ( struct V_74 * V_39 , T_3 V_75 , T_3 V_52 ,
const void * V_43 )
{
T_2 * V_53 ;
T_1 V_44 ;
int V_41 ;
V_44 = V_52 + 2 ;
V_53 = F_20 ( V_44 , V_77 ) ;
if ( ! V_53 )
return - V_78 ;
V_53 [ 0 ] = V_75 & 0xff ;
V_53 [ 1 ] = ( V_75 >> 8 ) & 0xff ;
memcpy ( & V_53 [ 2 ] , V_43 , V_52 ) ;
V_41 = F_21 ( V_39 , V_53 , V_44 ) ;
if ( V_41 == V_44 ) {
V_41 = 0 ;
} else {
if ( V_41 >= 0 )
V_41 = - V_55 ;
F_10 ( & V_39 -> V_30 , L_4 ,
V_56 , V_41 ) ;
}
F_22 ( V_53 ) ;
return V_41 ;
}
static int F_23 ( struct V_74 * V_39 , T_3 V_75 , T_2 V_43 )
{
return F_19 ( V_39 , V_75 , 1 , & V_43 ) ;
}
static struct V_1 *
F_24 ( struct V_34 * V_35 , T_2 type )
{
struct V_1 * V_79 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < V_35 -> V_81 . V_82 ; V_80 ++ ) {
V_79 = V_35 -> V_83 + V_80 ;
if ( V_79 -> type == type )
return V_79 ;
}
F_10 ( & V_35 -> V_39 -> V_30 , L_13 , type ) ;
return NULL ;
}
static int F_25 ( struct V_34 * V_35 ,
struct V_31 * V_32 )
{
struct V_1 * V_79 ;
T_3 V_75 ;
V_79 = F_24 ( V_35 , V_84 ) ;
if ( ! V_79 )
return - V_59 ;
V_75 = V_79 -> V_85 ;
return F_18 ( V_35 -> V_39 , V_75 ,
sizeof( struct V_31 ) , V_32 ) ;
}
static int F_26 ( struct V_34 * V_35 ,
T_2 type , T_2 V_86 , T_2 V_43 )
{
struct V_1 * V_79 ;
T_3 V_75 ;
V_79 = F_24 ( V_35 , type ) ;
if ( ! V_79 || V_86 >= F_1 ( V_79 ) )
return - V_59 ;
V_75 = V_79 -> V_85 ;
return F_23 ( V_35 -> V_39 , V_75 + V_86 , V_43 ) ;
}
static void F_27 ( struct V_34 * V_35 , struct V_31 * V_32 )
{
struct V_87 * V_88 = V_35 -> V_87 ;
const struct V_89 * V_90 = V_35 -> V_90 ;
bool V_91 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < V_90 -> V_92 ; V_80 ++ ) {
if ( V_90 -> V_93 [ V_80 ] == V_94 )
continue;
V_91 = ! ( V_32 -> V_32 [ 0 ] & ( 1 << V_80 ) ) ;
F_28 ( V_88 , V_90 -> V_93 [ V_80 ] , V_91 ) ;
}
}
static void F_29 ( struct V_87 * V_87 )
{
F_30 ( V_87 , false ) ;
F_31 ( V_87 ) ;
}
static void F_32 ( struct V_34 * V_35 ,
struct V_31 * V_32 , int V_95 )
{
struct V_29 * V_30 = & V_35 -> V_39 -> V_30 ;
T_2 V_96 = V_32 -> V_32 [ 0 ] ;
struct V_87 * V_87 = V_35 -> V_87 ;
int V_97 ;
int V_98 ;
int V_99 ;
int V_100 ;
V_97 = ( V_32 -> V_32 [ 1 ] << 4 ) | ( ( V_32 -> V_32 [ 3 ] >> 4 ) & 0xf ) ;
V_98 = ( V_32 -> V_32 [ 2 ] << 4 ) | ( ( V_32 -> V_32 [ 3 ] & 0xf ) ) ;
if ( V_35 -> V_101 < 1024 )
V_97 >>= 2 ;
if ( V_35 -> V_102 < 1024 )
V_98 >>= 2 ;
V_99 = V_32 -> V_32 [ 4 ] ;
V_100 = V_32 -> V_32 [ 5 ] ;
F_6 ( V_30 ,
L_14 ,
V_95 ,
( V_96 & V_103 ) ? 'D' : '.' ,
( V_96 & V_104 ) ? 'P' : '.' ,
( V_96 & V_105 ) ? 'R' : '.' ,
( V_96 & V_106 ) ? 'M' : '.' ,
( V_96 & V_107 ) ? 'V' : '.' ,
( V_96 & V_108 ) ? 'A' : '.' ,
( V_96 & V_109 ) ? 'S' : '.' ,
( V_96 & V_110 ) ? 'U' : '.' ,
V_97 , V_98 , V_99 , V_100 ) ;
F_33 ( V_87 , V_95 ) ;
if ( V_96 & V_103 ) {
if ( V_96 & V_105 ) {
F_34 ( V_87 ,
V_111 , 0 ) ;
F_29 ( V_87 ) ;
}
F_34 ( V_87 , V_111 , 1 ) ;
F_35 ( V_87 , V_112 , V_97 ) ;
F_35 ( V_87 , V_113 , V_98 ) ;
F_35 ( V_87 , V_114 , V_100 ) ;
F_35 ( V_87 , V_115 , V_99 ) ;
} else {
F_34 ( V_87 , V_111 , 0 ) ;
}
}
static T_3 F_36 ( const T_2 * V_116 )
{
return V_116 [ 0 ] | ( V_116 [ 1 ] << 8 ) | ( V_116 [ 2 ] << 16 ) ;
}
static bool F_37 ( struct V_34 * V_35 , struct V_31 * V_46 )
{
T_2 V_95 = V_46 -> V_33 ;
return ( V_95 >= V_35 -> V_117 && V_95 <= V_35 -> V_118 ) ;
}
static T_4 F_38 ( struct V_34 * V_35 )
{
struct V_31 V_32 ;
const T_2 * V_119 = & V_32 . V_32 [ 0 ] ;
struct V_29 * V_30 = & V_35 -> V_39 -> V_30 ;
T_2 V_33 ;
bool V_120 = false ;
T_5 V_121 ;
do {
if ( F_25 ( V_35 , & V_32 ) ) {
F_10 ( V_30 , L_15 ) ;
return V_122 ;
}
V_33 = V_32 . V_33 ;
if ( V_33 == V_35 -> V_123 ) {
T_2 V_96 = V_119 [ 0 ] ;
V_121 = F_36 ( & V_119 [ 1 ] ) ;
if ( V_121 != V_35 -> V_124 ) {
V_35 -> V_124 = V_121 ;
F_39 ( & V_35 -> V_125 ) ;
}
F_6 ( V_30 , L_16 ,
V_96 , V_35 -> V_124 ) ;
if ( V_96 & V_126 )
F_39 ( & V_35 -> V_127 ) ;
} else if ( F_37 ( V_35 , & V_32 ) ) {
int V_95 = V_33 - V_35 -> V_117 ;
F_32 ( V_35 , & V_32 , V_95 ) ;
V_120 = true ;
} else if ( V_32 . V_33 == V_35 -> V_128 ) {
F_27 ( V_35 , & V_32 ) ;
V_120 = true ;
} else {
F_5 ( V_30 , & V_32 ) ;
}
} while ( V_33 != 0xff );
if ( V_120 )
F_29 ( V_35 -> V_87 ) ;
return V_129 ;
}
static T_4 F_40 ( int V_130 , void * V_131 )
{
struct V_34 * V_35 = V_131 ;
if ( V_35 -> V_132 ) {
F_39 ( & V_35 -> V_65 ) ;
return V_129 ;
}
return F_38 ( V_35 ) ;
}
static int F_41 ( struct V_34 * V_35 , T_3 V_133 ,
T_2 V_134 , bool V_135 )
{
T_3 V_75 ;
T_2 V_136 ;
int V_137 = 0 ;
int V_41 ;
V_75 = V_35 -> V_138 + V_133 ;
V_41 = F_23 ( V_35 -> V_39 , V_75 , V_134 ) ;
if ( V_41 )
return V_41 ;
if ( ! V_135 )
return 0 ;
do {
F_42 ( 20 ) ;
V_41 = F_18 ( V_35 -> V_39 , V_75 , 1 , & V_136 ) ;
if ( V_41 )
return V_41 ;
} while ( V_136 != 0 && V_137 ++ <= 100 );
if ( V_137 > 100 ) {
F_10 ( & V_35 -> V_39 -> V_30 , L_17 ) ;
return - V_55 ;
}
return 0 ;
}
static int F_43 ( struct V_34 * V_35 )
{
struct V_29 * V_30 = & V_35 -> V_39 -> V_30 ;
int V_41 = 0 ;
F_44 ( V_30 , L_18 ) ;
F_45 ( & V_35 -> V_127 ) ;
V_41 = F_41 ( V_35 , V_139 , V_140 , false ) ;
if ( V_41 )
return V_41 ;
V_41 = F_7 ( V_35 , & V_35 -> V_127 ,
V_141 ) ;
if ( V_41 )
return V_41 ;
return 0 ;
}
static void F_46 ( struct V_34 * V_35 , T_2 V_142 , T_2 V_134 )
{
V_35 -> V_124 = 0 ;
F_45 ( & V_35 -> V_125 ) ;
F_41 ( V_35 , V_142 , V_134 , true ) ;
F_7 ( V_35 , & V_35 -> V_125 , V_143 ) ;
}
static int F_47 ( struct V_34 * V_35 )
{
const struct V_89 * V_90 = V_35 -> V_90 ;
struct V_1 * V_79 ;
struct V_29 * V_30 = & V_35 -> V_39 -> V_30 ;
int V_144 = 0 ;
int V_80 , V_145 ;
int V_41 ;
if ( ! V_90 -> V_146 ) {
F_6 ( V_30 , L_19 ) ;
return 0 ;
}
F_46 ( V_35 , V_147 , 1 ) ;
if ( V_35 -> V_124 == V_90 -> V_124 ) {
F_44 ( V_30 , L_20 , V_35 -> V_124 ) ;
return 0 ;
}
F_44 ( V_30 , L_21 ,
V_35 -> V_124 , V_90 -> V_124 ) ;
for ( V_80 = 0 ; V_80 < V_35 -> V_81 . V_82 ; V_80 ++ ) {
V_79 = V_35 -> V_83 + V_80 ;
if ( ! F_4 ( V_79 -> type ) )
continue;
V_145 = F_1 ( V_79 ) * F_2 ( V_79 ) ;
if ( V_144 + V_145 > V_90 -> V_148 ) {
F_10 ( V_30 , L_22 ) ;
return - V_59 ;
}
V_41 = F_19 ( V_35 -> V_39 , V_79 -> V_85 ,
V_145 , & V_90 -> V_146 [ V_144 ] ) ;
if ( V_41 )
return V_41 ;
V_144 += V_145 ;
}
F_46 ( V_35 , V_149 , V_150 ) ;
V_41 = F_43 ( V_35 ) ;
if ( V_41 )
return V_41 ;
F_44 ( V_30 , L_23 ) ;
return 0 ;
}
static int F_48 ( struct V_34 * V_35 )
{
struct V_29 * V_30 = & V_35 -> V_39 -> V_30 ;
struct V_31 V_32 ;
int V_44 = 10 ;
int error ;
do {
error = F_25 ( V_35 , & V_32 ) ;
if ( error )
return error ;
} while ( V_32 . V_33 != 0xff && -- V_44 );
if ( ! V_44 ) {
F_10 ( V_30 , L_24 ) ;
return - V_151 ;
}
return 0 ;
}
static int F_49 ( struct V_34 * V_35 )
{
struct V_74 * V_39 = V_35 -> V_39 ;
struct V_152 * V_81 = & V_35 -> V_81 ;
int error ;
error = F_18 ( V_39 , V_153 , sizeof( * V_81 ) , V_81 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_50 ( struct V_34 * V_35 )
{
struct V_74 * V_39 = V_35 -> V_39 ;
T_1 V_154 ;
int error ;
int V_80 ;
T_2 V_33 ;
V_154 = V_35 -> V_81 . V_82 * sizeof( struct V_1 ) ;
error = F_18 ( V_39 , V_155 , V_154 ,
V_35 -> V_83 ) ;
if ( error )
return error ;
V_33 = 1 ;
for ( V_80 = 0 ; V_80 < V_35 -> V_81 . V_82 ; V_80 ++ ) {
struct V_1 * V_79 = V_35 -> V_83 + V_80 ;
T_2 V_156 , V_157 ;
F_51 ( & V_79 -> V_85 ) ;
if ( V_79 -> V_158 ) {
V_156 = V_33 ;
V_33 += V_79 -> V_158 *
F_2 ( V_79 ) ;
V_157 = V_33 - 1 ;
} else {
V_156 = 0 ;
V_157 = 0 ;
}
F_6 ( & V_35 -> V_39 -> V_30 ,
L_25 ,
V_79 -> type , V_79 -> V_85 ,
F_1 ( V_79 ) , F_2 ( V_79 ) ,
V_156 , V_157 ) ;
switch ( V_79 -> type ) {
case V_5 :
V_35 -> V_123 = V_156 ;
V_35 -> V_138 = V_79 -> V_85 ;
break;
case V_9 :
V_35 -> V_117 = V_156 ;
V_35 -> V_118 = V_157 ;
break;
case V_23 :
V_35 -> V_128 = V_156 ;
break;
}
}
return 0 ;
}
static void F_52 ( struct V_34 * V_35 )
{
F_22 ( V_35 -> V_83 ) ;
V_35 -> V_83 = NULL ;
V_35 -> V_123 = 0 ;
V_35 -> V_117 = 0 ;
V_35 -> V_118 = 0 ;
V_35 -> V_128 = 0 ;
}
static int F_53 ( struct V_34 * V_35 )
{
struct V_74 * V_39 = V_35 -> V_39 ;
int error ;
struct V_159 V_160 ;
unsigned char V_161 ;
struct V_1 * V_79 ;
V_79 = F_24 ( V_35 , V_9 ) ;
if ( ! V_79 )
return - V_59 ;
error = F_18 ( V_39 ,
V_79 -> V_85 + V_162 ,
sizeof( V_160 ) , & V_160 ) ;
if ( error )
return error ;
F_51 ( & V_160 . V_97 ) ;
F_51 ( & V_160 . V_98 ) ;
error = F_18 ( V_39 ,
V_79 -> V_85 + V_163 ,
1 , & V_161 ) ;
if ( error )
return error ;
if ( V_160 . V_97 == 0 )
V_160 . V_97 = 1023 ;
if ( V_160 . V_98 == 0 )
V_160 . V_98 = 1023 ;
if ( V_161 & V_164 ) {
V_35 -> V_101 = V_160 . V_98 ;
V_35 -> V_102 = V_160 . V_97 ;
} else {
V_35 -> V_101 = V_160 . V_97 ;
V_35 -> V_102 = V_160 . V_98 ;
}
F_6 ( & V_39 -> V_30 ,
L_26 , V_35 -> V_101 , V_35 -> V_102 ) ;
return 0 ;
}
static int F_54 ( struct V_34 * V_35 )
{
struct V_74 * V_39 = V_35 -> V_39 ;
struct V_152 * V_81 = & V_35 -> V_81 ;
int error ;
error = F_49 ( V_35 ) ;
if ( error )
return error ;
V_35 -> V_83 = F_55 ( V_81 -> V_82 ,
sizeof( struct V_1 ) ,
V_77 ) ;
if ( ! V_35 -> V_83 ) {
F_10 ( & V_39 -> V_30 , L_27 ) ;
return - V_78 ;
}
error = F_50 ( V_35 ) ;
if ( error ) {
F_10 ( & V_39 -> V_30 , L_28 , error ) ;
goto V_165;
}
error = F_47 ( V_35 ) ;
if ( error ) {
F_10 ( & V_39 -> V_30 , L_29 ,
error ) ;
goto V_165;
}
error = F_53 ( V_35 ) ;
if ( error ) {
F_10 ( & V_39 -> V_30 , L_30 ) ;
goto V_165;
}
F_44 ( & V_39 -> V_30 ,
L_31 ,
V_81 -> V_166 , V_81 -> V_167 , V_81 -> V_168 >> 4 ,
V_81 -> V_168 & 0xf , V_81 -> V_169 , V_81 -> V_82 ) ;
return 0 ;
V_165:
F_52 ( V_35 ) ;
return error ;
}
static T_6 F_56 ( struct V_29 * V_30 ,
struct V_170 * V_171 , char * V_53 )
{
struct V_34 * V_35 = F_57 ( V_30 ) ;
struct V_152 * V_81 = & V_35 -> V_81 ;
return F_58 ( V_53 , V_172 , L_32 ,
V_81 -> V_168 >> 4 , V_81 -> V_168 & 0xf , V_81 -> V_169 ) ;
}
static T_6 F_59 ( struct V_29 * V_30 ,
struct V_170 * V_171 , char * V_53 )
{
struct V_34 * V_35 = F_57 ( V_30 ) ;
struct V_152 * V_81 = & V_35 -> V_81 ;
return F_58 ( V_53 , V_172 , L_33 ,
V_81 -> V_166 , V_81 -> V_167 ) ;
}
static T_6 F_60 ( char * V_53 , int V_44 ,
struct V_1 * V_79 , int V_173 ,
const T_2 * V_43 )
{
int V_80 ;
if ( F_2 ( V_79 ) > 1 )
V_44 += F_58 ( V_53 + V_44 , V_172 - V_44 ,
L_34 , V_173 ) ;
for ( V_80 = 0 ; V_80 < F_1 ( V_79 ) ; V_80 ++ )
V_44 += F_58 ( V_53 + V_44 , V_172 - V_44 ,
L_35 , V_80 , V_43 [ V_80 ] , V_43 [ V_80 ] ) ;
V_44 += F_58 ( V_53 + V_44 , V_172 - V_44 , L_36 ) ;
return V_44 ;
}
static T_6 F_61 ( struct V_29 * V_30 ,
struct V_170 * V_171 , char * V_53 )
{
struct V_34 * V_35 = F_57 ( V_30 ) ;
struct V_1 * V_79 ;
int V_44 = 0 ;
int V_80 , V_174 ;
int error ;
T_2 * V_175 ;
V_175 = F_20 ( 256 , V_77 ) ;
if ( ! V_175 )
return - V_78 ;
error = 0 ;
for ( V_80 = 0 ; V_80 < V_35 -> V_81 . V_82 ; V_80 ++ ) {
V_79 = V_35 -> V_83 + V_80 ;
if ( ! F_3 ( V_79 -> type ) )
continue;
V_44 += F_58 ( V_53 + V_44 , V_172 - V_44 ,
L_37 , V_79 -> type ) ;
for ( V_174 = 0 ; V_174 < F_2 ( V_79 ) ; V_174 ++ ) {
T_3 V_145 = F_1 ( V_79 ) ;
T_3 V_47 = V_79 -> V_85 + V_174 * V_145 ;
error = F_18 ( V_35 -> V_39 , V_47 , V_145 , V_175 ) ;
if ( error )
goto V_176;
V_44 = F_60 ( V_53 , V_44 , V_79 , V_174 , V_175 ) ;
}
}
V_176:
F_22 ( V_175 ) ;
return error ? : V_44 ;
}
static int F_62 ( struct V_29 * V_30 ,
const struct V_177 * V_178 )
{
unsigned int V_179 = 0 ;
char V_180 ;
while ( V_179 < V_178 -> V_145 ) {
V_180 = * ( V_178 -> V_35 + V_179 ) ;
if ( V_180 < '0' || ( V_180 > '9' && V_180 < 'A' ) || V_180 > 'F' )
return 0 ;
V_179 ++ ;
}
F_10 ( V_30 , L_38 ) ;
return - V_59 ;
}
static int F_63 ( struct V_29 * V_30 , const char * V_181 )
{
struct V_34 * V_35 = F_57 ( V_30 ) ;
const struct V_177 * V_178 = NULL ;
unsigned int V_182 ;
unsigned int V_179 = 0 ;
unsigned int V_183 = 0 ;
unsigned int V_184 = 0 ;
int V_41 ;
V_41 = F_64 ( & V_178 , V_181 , V_30 ) ;
if ( V_41 ) {
F_10 ( V_30 , L_39 , V_181 ) ;
return V_41 ;
}
V_41 = F_62 ( V_30 , V_178 ) ;
if ( V_41 )
goto V_185;
V_41 = F_14 ( V_35 ) ;
if ( V_41 )
goto V_185;
V_35 -> V_132 = true ;
V_41 = F_41 ( V_35 , V_139 , V_186 , false ) ;
if ( V_41 )
goto V_185;
F_42 ( V_187 ) ;
F_45 ( & V_35 -> V_65 ) ;
V_41 = F_16 ( V_35 , V_64 ) ;
if ( V_41 )
goto V_188;
F_17 ( V_35 ) ;
while ( V_179 < V_178 -> V_145 ) {
V_41 = F_16 ( V_35 , V_67 ) ;
if ( V_41 )
goto V_188;
V_182 = ( ( * ( V_178 -> V_35 + V_179 ) << 8 ) | * ( V_178 -> V_35 + V_179 + 1 ) ) ;
V_182 += 2 ;
V_41 = F_13 ( V_35 , V_178 -> V_35 + V_179 , V_182 ) ;
if ( V_41 )
goto V_188;
V_41 = F_16 ( V_35 , V_69 ) ;
if ( V_41 ) {
V_183 ++ ;
F_42 ( V_183 * 20 ) ;
if ( V_183 > 20 ) {
F_10 ( V_30 , L_40 ) ;
goto V_188;
}
} else {
V_183 = 0 ;
V_179 += V_182 ;
V_184 ++ ;
}
if ( V_184 % 50 == 0 )
F_6 ( V_30 , L_41 ,
V_184 , V_179 , V_178 -> V_145 ) ;
}
V_41 = F_7 ( V_35 , & V_35 -> V_65 ,
V_189 ) ;
if ( V_41 )
goto V_188;
F_6 ( V_30 , L_42 , V_184 , V_179 ) ;
F_7 ( V_35 , & V_35 -> V_65 , V_189 ) ;
V_35 -> V_132 = false ;
V_188:
V_188 ( V_35 -> V_130 ) ;
V_185:
V_185 ( V_178 ) ;
return V_41 ;
}
static T_6 F_65 ( struct V_29 * V_30 ,
struct V_170 * V_171 ,
const char * V_53 , T_1 V_44 )
{
struct V_34 * V_35 = F_57 ( V_30 ) ;
int error ;
error = F_63 ( V_30 , V_190 ) ;
if ( error ) {
F_10 ( V_30 , L_43 , error ) ;
V_44 = error ;
} else {
F_44 ( V_30 , L_44 ) ;
F_52 ( V_35 ) ;
F_54 ( V_35 ) ;
F_66 ( V_35 -> V_130 ) ;
error = F_48 ( V_35 ) ;
if ( error )
return error ;
}
return V_44 ;
}
static void F_67 ( struct V_34 * V_35 )
{
F_26 ( V_35 ,
V_9 , V_191 , 0x83 ) ;
}
static void F_68 ( struct V_34 * V_35 )
{
F_26 ( V_35 ,
V_9 , V_191 , 0 ) ;
}
static int F_69 ( struct V_87 * V_30 )
{
struct V_34 * V_35 = F_70 ( V_30 ) ;
F_67 ( V_35 ) ;
return 0 ;
}
static void F_71 ( struct V_87 * V_30 )
{
struct V_34 * V_35 = F_70 ( V_30 ) ;
F_68 ( V_35 ) ;
}
static int F_72 ( struct V_74 * V_39 ,
const struct V_192 * V_95 )
{
const struct V_89 * V_90 = F_73 ( & V_39 -> V_30 ) ;
struct V_34 * V_35 ;
struct V_87 * V_87 ;
int error ;
unsigned int V_193 ;
unsigned int V_194 = 0 ;
int V_80 ;
if ( ! V_90 )
return - V_59 ;
V_35 = F_74 ( sizeof( struct V_34 ) , V_77 ) ;
V_87 = F_75 () ;
if ( ! V_35 || ! V_87 ) {
F_10 ( & V_39 -> V_30 , L_27 ) ;
error = - V_78 ;
goto V_195;
}
V_87 -> V_196 = L_45 ;
snprintf ( V_35 -> V_197 , sizeof( V_35 -> V_197 ) , L_46 ,
V_39 -> V_54 -> V_198 , V_39 -> V_47 ) ;
V_87 -> V_197 = V_35 -> V_197 ;
V_87 -> V_95 . V_199 = V_200 ;
V_87 -> V_30 . V_201 = & V_39 -> V_30 ;
V_87 -> V_202 = F_69 ;
V_87 -> V_203 = F_71 ;
V_35 -> V_39 = V_39 ;
V_35 -> V_87 = V_87 ;
V_35 -> V_90 = V_90 ;
V_35 -> V_130 = V_39 -> V_130 ;
F_76 ( & V_35 -> V_65 ) ;
F_76 ( & V_35 -> V_127 ) ;
F_76 ( & V_35 -> V_125 ) ;
error = F_54 ( V_35 ) ;
if ( error )
goto V_195;
F_77 ( V_204 , V_87 -> V_205 ) ;
F_77 ( V_206 , V_87 -> V_205 ) ;
F_77 ( V_207 , V_87 -> V_208 ) ;
if ( V_90 -> V_92 ) {
F_77 ( V_209 , V_87 -> V_210 ) ;
for ( V_80 = 0 ; V_80 < V_90 -> V_92 ; V_80 ++ )
if ( V_90 -> V_93 [ V_80 ] != V_94 )
F_78 ( V_87 , V_206 ,
V_90 -> V_93 [ V_80 ] ) ;
V_194 |= V_211 ;
F_79 ( V_87 , V_212 , V_213 ) ;
F_79 ( V_87 , V_214 , V_213 ) ;
F_79 ( V_87 , V_112 ,
V_213 ) ;
F_79 ( V_87 , V_113 ,
V_213 ) ;
V_87 -> V_196 = L_47 ;
}
F_80 ( V_87 , V_212 ,
0 , V_35 -> V_101 , 0 , 0 ) ;
F_80 ( V_87 , V_214 ,
0 , V_35 -> V_102 , 0 , 0 ) ;
F_80 ( V_87 , V_215 ,
0 , 255 , 0 , 0 ) ;
V_193 = V_35 -> V_118 - V_35 -> V_117 + 1 ;
error = F_81 ( V_87 , V_193 , V_194 ) ;
if ( error )
goto V_216;
F_80 ( V_87 , V_115 ,
0 , V_217 , 0 , 0 ) ;
F_80 ( V_87 , V_112 ,
0 , V_35 -> V_101 , 0 , 0 ) ;
F_80 ( V_87 , V_113 ,
0 , V_35 -> V_102 , 0 , 0 ) ;
F_80 ( V_87 , V_114 ,
0 , 255 , 0 , 0 ) ;
F_82 ( V_87 , V_35 ) ;
F_83 ( V_39 , V_35 ) ;
error = F_84 ( V_39 -> V_130 , NULL , F_40 ,
V_90 -> V_218 | V_219 ,
V_39 -> V_196 , V_35 ) ;
if ( error ) {
F_10 ( & V_39 -> V_30 , L_48 ) ;
goto V_216;
}
error = F_48 ( V_35 ) ;
if ( error )
goto V_220;
error = F_85 ( V_87 ) ;
if ( error ) {
F_10 ( & V_39 -> V_30 , L_49 ,
error ) ;
goto V_220;
}
error = F_86 ( & V_39 -> V_30 . V_221 , & V_222 ) ;
if ( error ) {
F_10 ( & V_39 -> V_30 , L_50 ,
error ) ;
goto V_223;
}
return 0 ;
V_223:
F_87 ( V_87 ) ;
V_87 = NULL ;
V_220:
F_88 ( V_39 -> V_130 , V_35 ) ;
V_216:
F_22 ( V_35 -> V_83 ) ;
V_195:
F_89 ( V_87 ) ;
F_22 ( V_35 ) ;
return error ;
}
static int F_90 ( struct V_74 * V_39 )
{
struct V_34 * V_35 = F_91 ( V_39 ) ;
F_92 ( & V_39 -> V_30 . V_221 , & V_222 ) ;
F_88 ( V_35 -> V_130 , V_35 ) ;
F_87 ( V_35 -> V_87 ) ;
F_22 ( V_35 -> V_83 ) ;
F_22 ( V_35 ) ;
return 0 ;
}
static int F_93 ( struct V_29 * V_30 )
{
struct V_74 * V_39 = F_94 ( V_30 ) ;
struct V_34 * V_35 = F_91 ( V_39 ) ;
struct V_87 * V_87 = V_35 -> V_87 ;
F_95 ( & V_87 -> V_224 ) ;
if ( V_87 -> V_225 )
F_68 ( V_35 ) ;
F_96 ( & V_87 -> V_224 ) ;
return 0 ;
}
static int F_97 ( struct V_29 * V_30 )
{
struct V_74 * V_39 = F_94 ( V_30 ) ;
struct V_34 * V_35 = F_91 ( V_39 ) ;
struct V_87 * V_87 = V_35 -> V_87 ;
F_43 ( V_35 ) ;
F_95 ( & V_87 -> V_224 ) ;
if ( V_87 -> V_225 )
F_67 ( V_35 ) ;
F_96 ( & V_87 -> V_224 ) ;
return 0 ;
}
