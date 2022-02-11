T_1 F_1 ( struct V_1 * V_1 , T_2 V_2 , T_3 V_3 ,
T_2 * V_4 )
{
T_1 V_5 ;
T_2 V_6 ;
T_2 V_7 ;
T_2 * V_8 ;
struct V_9 * V_10 = V_1 -> V_10 ;
if ( ! ( V_11 & V_2 ) )
return - V_12 ;
if ( V_13 & V_2 ) {
V_7 = F_2 ( V_2 , V_14 ) ;
V_5 = F_3 ( V_10 , V_7 , V_4 ) ;
goto V_15;
}
V_5 = 0 ;
for ( V_6 = 0 ; V_6 * V_16 < V_3 ; V_6 ++ ) {
V_7 = F_4 ( V_2 , V_6 ) ;
V_7 = F_2 ( V_7 , V_14 ) ;
V_8 = V_4 + V_16 * V_6 ;
V_5 = F_3 ( V_10 , V_7 , V_8 ) ;
if ( V_5 < 0 )
goto V_15;
}
V_15:
return V_5 > 0 ? V_3 : V_5 ;
}
static T_4 F_5 ( struct V_1 * V_1 , T_2 V_17 )
{
T_2 V_2 ;
if ( V_1 -> V_18 ) {
V_2 = V_19 [ V_17 ] . V_2 ;
V_2 = F_2 ( V_2 , V_14 ) ;
} else {
V_2 = V_20 [ V_17 ] . V_2 ;
}
return F_6 ( V_1 -> V_10 , V_2 ) ;
}
static T_4 F_7 ( struct V_1 * V_1 , T_2 V_17 , T_2 V_21 )
{
T_2 V_2 ;
if ( V_1 -> V_18 ) {
V_2 = V_19 [ V_17 ] . V_2 ;
V_2 = F_2 ( V_2 , V_22 ) ;
} else {
V_2 = V_20 [ V_17 ] . V_2 ;
}
return F_8 ( V_1 -> V_10 , V_2 , V_21 ) ;
}
T_1 F_9 ( struct V_1 * V_1 , T_2 V_23 , T_3 V_3 ,
T_2 * V_4 )
{
return F_10 ( V_1 -> V_10 , V_23 , V_3 , V_4 ) ;
}
static T_1 F_11 ( struct V_1 * V_1 , T_2 V_23 ,
T_3 V_3 , const T_2 * V_4 )
{
return F_12 ( V_1 -> V_10 , V_23 , V_3 , V_4 ) ;
}
T_1 F_13 ( struct V_1 * V_1 , T_2 V_17 , T_2 * V_4 )
{
T_2 V_2 ;
T_3 V_3 ;
if ( V_1 -> V_18 ) {
V_2 = V_19 [ V_17 ] . V_2 ;
V_3 = V_19 [ V_17 ] . V_3 ;
return F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
}
V_2 = V_20 [ V_17 ] . V_2 ;
V_3 = V_20 [ V_17 ] . V_3 ;
return F_9 ( V_1 , V_2 , V_3 , V_4 ) ;
}
static int F_14 ( struct V_1 * V_1 , T_2 * V_24 , int V_3 )
{
V_1 -> V_25 = V_26 ;
if ( V_24 [ V_27 ] == V_28 &&
V_24 [ V_29 ] == V_30 &&
( V_24 [ V_31 ] ==
( V_32 | V_33 ) ||
V_24 [ V_31 ] == V_32 ) ) {
V_1 -> V_34 = V_35 ;
V_1 -> V_25 = V_36 ;
} else if ( V_24 [ V_27 ] == V_28 &&
( V_24 [ V_31 ] & V_32 ) ==
V_32 ) {
V_1 -> V_34 = V_35 ;
if ( V_24 [ V_31 ] & V_37 ) {
V_1 -> V_25 = V_38 ;
} else {
if ( ( V_24 [ V_29 ] & V_39 ) ==
V_39 )
V_1 -> V_25 = V_40 ;
else
V_1 -> V_25 = V_36 ;
}
} else if ( ( V_24 [ V_41 ] & V_42 ) &&
( V_24 [ V_43 ] & V_44 ) ) {
if ( F_15 ( V_24 [ V_43 ] ) <=
V_45 ) {
V_1 -> V_34 = V_35 ;
V_1 -> V_25 = V_46 ;
}
} else if ( V_24 [ V_41 ] == 0x0C &&
V_24 [ V_43 ] == 0x08 ) {
V_1 -> V_34 = V_35 ;
V_1 -> V_25 = V_46 ;
} else if ( V_24 [ V_31 ] &
( V_32 | V_37 ) ) {
V_1 -> V_34 = V_35 ;
V_1 -> V_25 = V_38 ;
}
if ( V_1 -> V_34 == V_35 && ( V_1 -> V_25 == V_46 ||
V_1 -> V_25 == V_36 ||
V_1 -> V_25 == V_40 ||
V_1 -> V_25 == V_38 ) )
return 0 ;
return - V_47 ;
}
static int F_16 ( struct V_1 * V_1 )
{
int error ;
int V_48 ;
error = F_17 ( V_1 , 500 ) ;
if ( error )
return error ;
if ( V_1 -> V_25 == V_36 ) {
return 0 ;
}
if ( V_1 -> V_25 != V_46 )
return - V_47 ;
V_1 -> V_49 = false ;
V_1 -> V_25 = V_26 ;
error = F_7 ( V_1 , V_50 , 0x01 ) ;
if ( error )
return - V_51 ;
F_18 ( 25000 , 50000 ) ;
V_48 = 2000 ;
do {
error = F_17 ( V_1 , 500 ) ;
if ( error ) {
if ( error == - V_52 ) {
V_48 -= 500 ;
continue;
}
return error ;
}
if ( ( V_1 -> V_25 == V_36 ) &&
! ( V_1 -> V_53 [ V_31 ] & V_54 ) )
break;
F_19 ( 100 ) ;
V_48 -= 100 ;
} while ( V_48 > 0 );
if ( ( V_1 -> V_25 != V_36 ) ||
( V_1 -> V_53 [ V_31 ] & V_54 ) )
return - V_47 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_1 )
{
int error ;
error = F_11 ( V_1 , 0 , sizeof( V_55 ) ,
V_55 ) ;
if ( error )
return error ;
F_19 ( 2000 ) ;
error = F_17 ( V_1 , 11000 ) ;
if ( error )
return error ;
if ( V_1 -> V_25 != V_40 )
return - V_47 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_1 )
{
int error ;
error = F_11 ( V_1 , 0 , sizeof( V_56 ) ,
V_56 ) ;
if ( error )
return error ;
F_19 ( 100 ) ;
error = F_17 ( V_1 , 500 ) ;
if ( error )
return error ;
if ( V_1 -> V_25 != V_36 )
return - V_47 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_1 )
{
int error ;
error = F_11 ( V_1 , 0 , sizeof( V_57 ) , V_57 ) ;
if ( error )
return error ;
F_19 ( 50 ) ;
error = F_17 ( V_1 , 4000 ) ;
if ( error < 0 )
return error ;
if ( V_1 -> V_25 != V_46 )
return - V_47 ;
return 0 ;
}
static T_5 F_23 ( const T_2 * V_8 , T_3 V_58 )
{
int V_59 ;
T_5 V_60 = 0 ;
for ( V_59 = 0 ; V_59 < V_58 ; V_59 ++ )
V_60 += V_8 [ V_59 ] ;
return V_60 ;
}
static int F_24 ( struct V_1 * V_1 , const struct V_61 * V_62 )
{
struct V_63 * V_64 = & V_1 -> V_10 -> V_64 ;
T_5 V_60 ;
T_5 V_65 ;
if ( V_62 -> V_66 != V_67 ) {
F_25 ( V_64 , L_1 ,
V_62 -> V_66 , V_67 ) ;
return - V_12 ;
}
V_65 = ( V_62 -> V_68 [ 0 ] << 8 ) | V_62 -> V_68 [ 1 ] ;
V_60 = F_23 ( & V_62 -> V_68 [ 2 ] , V_69 - 2 ) ;
if ( V_60 != V_65 ) {
F_25 ( V_64 , L_2 ,
L_3 ,
V_60 , V_65 ) ;
return - V_12 ;
}
V_65 = ( V_62 -> V_68 [ V_69 - 2 ] << 8 ) |
V_62 -> V_68 [ V_69 - 1 ] ;
V_60 = F_23 ( & V_62 -> V_68 [ V_69 ] ,
V_70 ) ;
if ( V_60 != V_65 ) {
F_25 ( V_64 , L_2 ,
L_3 ,
V_60 , V_65 ) ;
return - V_12 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_1 ,
const T_2 * V_8 , T_3 V_3 )
{
int error ;
T_3 V_59 ;
unsigned char V_2 [ V_71 + 1 ] ;
T_3 V_72 ;
for ( V_59 = 0 ; V_59 < V_3 ; V_59 += V_71 ) {
const T_2 * V_73 = & V_8 [ V_59 ] ;
V_72 = ( V_3 - V_59 >= V_71 ) ? V_71 : V_3 - V_59 ;
V_2 [ 0 ] = V_59 ;
memcpy ( & V_2 [ 1 ] , V_73 , V_72 ) ;
error = F_11 ( V_1 , 0 , V_72 + 1 , V_2 ) ;
if ( error )
return error ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_1 ,
T_5 V_74 , const T_2 * V_68 )
{
int V_5 ;
struct V_75 V_76 ;
T_2 V_53 [ V_77 ] ;
int V_78 ;
T_2 V_79 , V_80 ;
V_76 . V_81 = V_82 ;
V_76 . V_83 = V_84 ;
memcpy ( V_76 . V_85 , V_86 , sizeof( V_86 ) ) ;
F_28 ( V_74 , & V_76 . V_87 ) ;
memcpy ( V_76 . V_88 , V_68 , V_89 ) ;
V_76 . V_90 = F_23 (
V_76 . V_88 , V_89 ) ;
V_76 . V_91 = F_23 ( ( T_2 * ) & V_76 ,
sizeof( V_76 ) - 1 ) ;
V_5 = F_26 ( V_1 , ( T_2 * ) & V_76 ,
sizeof( V_76 ) ) ;
if ( V_5 )
return V_5 ;
V_78 = 11 ;
do {
F_18 ( 10000 , 20000 ) ;
V_5 = F_9 ( V_1 , V_92 ,
V_77 , V_53 ) ;
if ( V_5 != V_77 )
return ( V_5 < 0 ) ? V_5 : - V_51 ;
} while ( ( V_53 [ V_31 ] & V_37 ) && -- V_78 );
V_79 = V_53 [ V_31 ] & ~ V_93 ;
V_80 = V_53 [ V_29 ] & ~ V_94 ;
if ( V_79 & V_37 )
V_5 = - V_52 ;
else if ( V_79 != V_32 ||
V_80 != V_39 )
V_5 = - V_51 ;
else
V_5 = 0 ;
return V_5 ;
}
static int F_29 ( struct V_1 * V_1 ,
T_3 V_95 , T_3 V_96 ,
const T_2 * V_97 )
{
int error ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_96 ; V_59 ++ ) {
T_3 V_74 = V_95 + V_59 ;
T_3 V_98 = V_59 * V_89 ;
const T_2 * V_68 = & V_97 [ V_98 ] ;
error = F_27 ( V_1 , V_74 , V_68 ) ;
if ( error )
return error ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_1 ,
const struct V_61 * V_62 )
{
struct V_63 * V_64 = & V_1 -> V_10 -> V_64 ;
int error ;
error = F_29 ( V_1 ,
V_99 , V_100 ,
& V_62 -> V_68 [ V_101 * V_89 ] ) ;
if ( error ) {
F_25 ( V_64 , L_4 , error ) ;
return error ;
}
error = F_29 ( V_1 ,
V_102 , V_101 ,
& V_62 -> V_68 [ 0 ] ) ;
if ( error ) {
F_25 ( V_64 , L_5 , error ) ;
return error ;
}
return 0 ;
}
static T_1 F_31 ( struct V_63 * V_64 ,
struct V_103 * V_104 ,
const char * V_8 , T_3 V_58 )
{
struct V_1 * V_1 = F_32 ( V_64 ) ;
unsigned long V_105 ;
int V_5 ;
V_5 = F_5 ( V_1 , V_106 ) ;
if ( V_5 < 0 ) {
F_25 ( V_64 , L_6 , V_5 ) ;
goto V_15;
}
if ( ( V_5 & V_107 ) != V_107 ) {
F_33 ( V_64 , L_7 ,
V_5 ) ;
V_5 = - V_47 ;
goto V_15;
}
V_5 = F_7 ( V_1 , V_50 ,
V_108 ) ;
if ( V_5 < 0 ) {
F_25 ( V_64 , L_8 ,
V_5 ) ;
goto V_15;
}
V_105 = V_109 + 2 * V_110 ;
do {
F_19 ( 100 ) ;
V_5 = F_5 ( V_1 , V_106 ) ;
if ( V_5 < 0 ) {
F_25 ( V_64 , L_6 , V_5 ) ;
goto V_15;
}
if ( ( V_5 & V_107 ) == V_107 ) {
F_34 ( V_64 , L_9 ) ;
goto V_15;
}
} while ( F_35 ( V_105 ) );
F_25 ( V_64 , L_10 ) ;
V_5 = - V_52 ;
V_15:
return V_5 < 0 ? V_5 : V_58 ;
}
static T_1 F_36 ( struct V_63 * V_64 ,
struct V_103 * V_104 , char * V_8 )
{
struct V_1 * V_1 = F_32 ( V_64 ) ;
int V_111 , V_112 ;
int V_78 ;
int V_5 ;
V_5 = F_5 ( V_1 , V_106 ) ;
if ( V_5 < 0 ) {
F_25 ( V_64 , L_11 , V_5 ) ;
goto V_15;
}
if ( ( V_5 & V_107 ) != V_107 ) {
F_33 ( V_64 , L_12 ,
V_5 ) ;
V_5 = - V_47 ;
goto V_15;
}
V_5 = F_7 ( V_1 , V_50 ,
V_113 ) ;
if ( V_5 < 0 ) {
F_25 ( V_64 , L_13 ,
V_5 ) ;
goto V_15;
}
V_78 = 3 ;
do {
F_18 ( 10000 , 20000 ) ;
V_5 = F_5 ( V_1 , V_106 ) ;
if ( V_5 < 0 ) {
F_25 ( V_64 , L_11 ,
V_5 ) ;
goto V_15;
}
if ( ( V_5 & V_107 ) == V_107 )
break;
} while ( -- V_78 );
if ( V_78 == 0 ) {
F_25 ( V_64 , L_14 ) ;
V_5 = - V_52 ;
goto V_15;
}
V_5 = F_5 ( V_1 , V_114 ) ;
if ( V_5 < 0 ) {
F_25 ( V_64 , L_15 , V_5 ) ;
goto V_15;
}
V_111 = V_5 ;
V_5 = F_5 ( V_1 , V_115 ) ;
if ( V_5 < 0 ) {
F_25 ( V_64 , L_16 , V_5 ) ;
goto V_15;
}
V_112 = V_5 ;
F_34 ( V_64 , L_17 ,
V_111 , V_112 ) ;
V_5 = F_37 ( V_8 , V_116 , L_18 , V_111 , V_112 ) ;
V_15:
return V_5 ;
}
static T_5 F_38 ( T_2 V_117 )
{
switch ( V_117 ) {
case V_118 : return 20 ;
case V_119 : return 20 ;
case V_120 : return 20 ;
default: return F_39 ( V_117 ) + 50 ;
}
}
static int F_40 ( struct V_1 * V_1 , T_2 V_121 ,
T_5 V_122 , enum V_123 V_124 )
{
struct V_125 * V_126 = V_1 -> V_126 ;
T_2 V_127 ;
int V_78 ;
int V_128 ;
int V_129 ;
int V_5 ;
if ( V_1 -> V_25 != V_46 )
return 0 ;
V_78 = V_130 ;
while ( V_78 -- ) {
V_5 = F_5 ( V_1 , V_131 ) ;
if ( V_5 >= 0 )
break;
F_18 ( V_132 , 2 * V_132 ) ;
}
if ( V_5 < 0 )
return V_5 ;
if ( ( V_5 & V_133 ) == V_121 )
return 0 ;
V_128 = ( int ) F_38 ( V_5 & V_133 ) ;
V_127 = V_5 ;
V_127 &= ~ V_133 ;
V_127 |= V_121 & V_133 ;
V_78 = V_130 ;
while ( V_78 -- ) {
V_5 = F_7 ( V_1 , V_131 , V_127 ) ;
if ( ! V_5 )
break;
F_18 ( V_132 , 2 * V_132 ) ;
}
if ( V_1 -> V_49 && V_126 && V_126 -> V_134 &&
( V_124 == V_135 ||
V_124 == V_136 ) ) {
V_129 = 1000 / 120 ;
while ( V_128 > 0 ) {
if ( V_128 > V_129 )
F_19 ( V_129 ) ;
else
F_19 ( V_128 ) ;
V_128 -= V_129 ;
F_41 ( V_1 ) ;
}
} else {
F_19 ( V_128 ) ;
}
return V_5 ;
}
static int F_42 ( struct V_1 * V_1 , bool V_137 )
{
return - V_138 ;
}
static int F_43 ( struct V_1 * V_1 )
{
T_2 V_139 [ V_140 ] ;
int V_5 ;
if ( V_1 -> V_25 != V_46 )
return - V_141 ;
V_5 = F_13 ( V_1 , V_142 , V_139 ) ;
if ( V_5 != V_140 )
return ( V_5 < 0 ) ? V_5 : - V_51 ;
memcpy ( & V_1 -> V_143 [ 0 ] , & V_139 [ 0 ] , 5 ) ;
V_1 -> V_143 [ 5 ] = '-' ;
memcpy ( & V_1 -> V_143 [ 6 ] , & V_139 [ 5 ] , 6 ) ;
V_1 -> V_143 [ 12 ] = '-' ;
memcpy ( & V_1 -> V_143 [ 13 ] , & V_139 [ 11 ] , 2 ) ;
V_1 -> V_143 [ 15 ] = '\0' ;
V_1 -> V_144 = V_139 [ 15 ] ;
V_1 -> V_145 = V_139 [ 16 ] ;
V_1 -> V_146 = V_139 [ 19 ] & V_147 ;
V_1 -> V_34 = V_139 [ 20 ] & 0x0f ;
V_1 -> V_148 = ( ( V_139 [ 21 ] & 0xf0 ) << 4 ) | V_139 [ 22 ] ;
V_1 -> V_149 = ( ( V_139 [ 21 ] & 0x0f ) << 8 ) | V_139 [ 23 ] ;
V_1 -> V_150 =
( ( V_139 [ 24 ] & 0xf0 ) << 4 ) | V_139 [ 25 ] ;
V_1 -> V_151 =
( ( V_139 [ 24 ] & 0x0f ) << 8 ) | V_139 [ 26 ] ;
V_1 -> V_152 = 255 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_1 )
{
T_2 V_153 [ V_71 ] ;
int V_5 ;
V_5 = F_9 ( V_1 , 0 , V_71 , V_153 ) ;
if ( V_5 != V_71 )
return ( V_5 < 0 ) ? V_5 : - V_51 ;
if ( V_153 [ V_31 ] ==
( V_32 | V_33 ) ) {
V_1 -> V_144 = V_153 [ V_154 ] ;
V_1 -> V_145 = V_153 [ V_155 ] ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_1 )
{
struct V_63 * V_64 = & V_1 -> V_10 -> V_64 ;
int error ;
switch ( V_1 -> V_25 ) {
case V_40 :
error = F_21 ( V_1 ) ;
if ( error ) {
F_25 ( V_64 , L_19 , error ) ;
return error ;
}
case V_36 :
F_44 ( V_1 ) ;
error = F_22 ( V_1 ) ;
if ( error ) {
F_25 ( V_64 , L_20 , error ) ;
return error ;
}
case V_46 :
error = F_40 ( V_1 ,
V_118 , 0 , V_156 ) ;
if ( error )
F_25 ( V_64 , L_21 ,
V_157 , error ) ;
error = F_43 ( V_1 ) ;
if ( error < 0 )
return error ;
if ( V_1 -> V_34 != V_35 ) {
F_25 ( V_64 , L_22 ,
V_1 -> V_34 ) ;
return - V_12 ;
}
if ( memcmp ( V_1 -> V_143 , V_143 ,
strlen ( V_143 ) ) != 0 ) {
F_25 ( V_64 , L_23 ,
V_1 -> V_143 ) ;
return - V_12 ;
}
return 0 ;
default:
return - V_51 ;
}
return 0 ;
}
static bool F_46 ( struct V_1 * V_1 )
{
if ( V_1 -> V_34 != V_35 )
return true ;
if ( V_1 -> V_49 )
return true ;
return false ;
}
static int F_47 ( struct V_1 * V_1 ,
struct V_158 * V_68 )
{
struct V_125 * V_126 = V_1 -> V_126 ;
int V_159 ;
int V_59 ;
V_159 = ( V_68 -> V_160 >> 4 ) & 0x0f ;
for ( V_59 = 0 ; V_59 < V_159 ; V_59 ++ ) {
const struct V_161 * V_162 = & V_68 -> V_163 [ V_59 ] ;
int V_164 = V_162 -> V_165 - 1 ;
F_48 ( V_126 , V_164 ) ;
F_49 ( V_126 , V_166 , true ) ;
F_50 ( V_126 , V_167 ,
( ( V_162 -> V_168 & 0xf0 ) << 4 ) | V_162 -> V_169 ) ;
F_50 ( V_126 , V_170 ,
( ( V_162 -> V_168 & 0x0f ) << 8 ) | V_162 -> V_171 ) ;
F_50 ( V_126 , V_172 , V_162 -> V_173 ) ;
}
F_51 ( V_126 ) ;
if ( V_1 -> V_146 & V_174 )
F_52 ( V_126 , V_175 ,
! ! ( V_68 -> V_160 & V_176 ) ) ;
if ( V_1 -> V_146 & V_177 )
F_52 ( V_126 , V_178 ,
! ! ( V_68 -> V_160 & V_179 ) ) ;
if ( V_1 -> V_146 & V_180 )
F_52 ( V_126 , V_181 ,
! ! ( V_68 -> V_160 & V_182 ) ) ;
F_53 ( V_126 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_1 )
{
struct V_63 * V_64 = & V_1 -> V_10 -> V_64 ;
struct V_158 V_68 ;
int V_5 ;
V_5 = F_13 ( V_1 , V_183 , ( T_2 * ) & V_68 ) ;
if ( V_5 != sizeof( V_68 ) ) {
F_25 ( V_64 , L_24 , V_5 ) ;
return - V_12 ;
}
if ( ( V_68 . V_184 & V_42 ) != V_42 ||
( V_68 . V_184 & V_185 ) != V_107 ||
( V_68 . V_160 & V_44 ) != V_44 ) {
F_25 ( V_64 , L_25 ,
V_68 . V_184 , V_68 . V_160 ) ;
return - V_12 ;
}
return F_47 ( V_1 , & V_68 ) ;
}
static int F_41 ( struct V_1 * V_1 )
{
struct V_158 V_68 ;
int V_5 ;
V_5 = F_13 ( V_1 , V_183 , ( T_2 * ) & V_68 ) ;
if ( V_5 != sizeof( V_68 ) )
return - V_12 ;
if ( ( V_68 . V_184 & V_42 ) != V_42 ||
( V_68 . V_184 & V_185 ) != V_107 ||
( V_68 . V_160 & V_44 ) != V_44 )
return - V_12 ;
return F_47 ( V_1 , & V_68 ) ;
}
static int F_55 ( struct V_1 * V_1 ) { return 0 ; }
static int F_56 ( struct V_1 * V_1 ,
const struct V_61 * V_62 ) { return 0 ; }
static int F_57 ( struct V_1 * V_1 ,
T_2 * V_8 , int * V_3 , T_6 V_186 ) { return 0 ; }
