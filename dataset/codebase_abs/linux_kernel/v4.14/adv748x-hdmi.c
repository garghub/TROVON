static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_5 = V_6 ;
V_4 -> V_7 = V_2 -> V_8 . V_9 . V_10 ?
V_11 : V_12 ;
V_4 -> V_13 = V_14 ;
V_4 -> V_15 = V_2 -> V_8 . V_9 . V_15 ;
V_4 -> V_16 = V_2 -> V_8 . V_9 . V_16 ;
}
static void F_2 ( struct V_17 * V_8 )
{
F_3 ( V_8 , & V_18 ,
250000 , NULL , NULL ) ;
}
static bool F_4 ( struct V_19 * V_20 )
{
int V_21 ;
V_21 = F_5 ( V_20 , V_22 ) ;
return ( V_21 & V_23 ) &&
( V_21 & V_24 ) ;
}
static int F_6 ( struct V_19 * V_20 )
{
int V_25 , V_26 ;
V_25 = F_5 ( V_20 , V_27 ) ;
V_26 = F_5 ( V_20 , V_28 ) ;
if ( V_25 < 0 || V_26 < 0 )
return - V_29 ;
return ( ( V_25 << 1 ) | ( V_26 >> 7 ) ) * 1000000 + ( V_26 & 0x7f ) * 1000000 / 128 ;
}
static void F_7 ( struct V_19 * V_20 , int V_30 )
{
T_1 V_31 , V_32 ;
V_31 = V_33 ;
V_31 |= ( V_30 & 0x300 ) >> 8 ;
V_32 = V_30 & 0xff ;
F_8 ( V_20 , V_34 , V_31 ) ;
F_8 ( V_20 , V_35 , V_32 ) ;
V_31 |= ( V_30 & 0x300 ) >> 6 ;
F_8 ( V_20 , V_34 , V_31 ) ;
F_8 ( V_20 , V_36 , V_32 ) ;
}
static int F_9 ( struct V_19 * V_20 ,
const struct V_17 * V_8 )
{
const struct V_37 * V_38 =
V_37 ;
unsigned int V_39 ;
for ( V_39 = 0 ; V_39 < F_10 ( V_37 ) ; V_39 ++ ) {
if ( ! F_11 ( V_8 , & V_38 [ V_39 ] . V_8 , 250000 ,
false ) )
continue;
}
if ( V_39 >= F_10 ( V_37 ) )
return - V_40 ;
switch ( V_38 [ V_39 ] . V_41 ) {
case 0x53 :
F_7 ( V_20 , - 40 ) ;
break;
case 0x54 :
case 0x5e :
F_7 ( V_20 , - 44 ) ;
break;
default:
F_7 ( V_20 , 0 ) ;
break;
}
F_12 ( V_20 , V_42 , V_38 [ V_39 ] . V_41 ) ;
F_13 ( V_20 , V_43 , V_44 ,
V_38 [ V_39 ] . V_45 << V_46 ) ;
return 0 ;
}
static int F_14 ( struct V_47 * V_48 ,
struct V_17 * V_8 )
{
struct V_1 * V_2 = F_15 ( V_48 ) ;
struct V_19 * V_20 = F_16 ( V_2 ) ;
int V_49 ;
if ( ! V_8 )
return - V_40 ;
if ( F_11 ( & V_2 -> V_8 , V_8 , 0 , false ) )
return 0 ;
if ( ! F_17 ( V_8 , & V_18 ,
NULL , NULL ) )
return - V_50 ;
F_2 ( V_8 ) ;
F_18 ( & V_20 -> V_51 ) ;
V_49 = F_9 ( V_20 , V_8 ) ;
if ( V_49 )
goto error;
V_2 -> V_8 = * V_8 ;
F_19 ( V_20 , V_52 , V_53 ,
V_8 -> V_9 . V_10 ?
V_53 : 0 ) ;
F_20 ( & V_20 -> V_51 ) ;
return 0 ;
error:
F_20 ( & V_20 -> V_51 ) ;
return V_49 ;
}
static int F_21 ( struct V_47 * V_48 ,
struct V_17 * V_8 )
{
struct V_1 * V_2 = F_15 ( V_48 ) ;
struct V_19 * V_20 = F_16 ( V_2 ) ;
F_18 ( & V_20 -> V_51 ) ;
* V_8 = V_2 -> V_8 ;
F_20 ( & V_20 -> V_51 ) ;
return 0 ;
}
static int F_22 ( struct V_47 * V_48 ,
struct V_17 * V_8 )
{
struct V_1 * V_2 = F_15 ( V_48 ) ;
struct V_19 * V_20 = F_16 ( V_2 ) ;
struct V_54 * V_9 = & V_8 -> V_9 ;
int V_55 ;
int V_56 ;
if ( ! V_8 )
return - V_40 ;
memset ( V_8 , 0 , sizeof( struct V_17 ) ) ;
if ( ! F_4 ( V_20 ) )
return - V_57 ;
V_55 = F_6 ( V_20 ) ;
if ( V_55 < 0 )
return - V_29 ;
V_8 -> type = V_58 ;
V_9 -> V_55 = V_55 ;
V_9 -> V_10 = F_5 ( V_20 , V_59 ) &
V_60 ?
V_61 : V_62 ;
V_9 -> V_15 = F_23 ( V_20 , V_22 ,
V_63 ) ;
V_9 -> V_16 = F_23 ( V_20 , V_64 ,
V_65 ) ;
V_9 -> V_66 = F_23 ( V_20 , V_67 ,
V_68 ) ;
V_9 -> V_69 = F_23 ( V_20 , V_70 ,
V_71 ) ;
V_9 -> V_72 = F_23 ( V_20 , V_73 ,
V_74 ) ;
V_9 -> V_75 = F_23 ( V_20 , V_76 ,
V_77 ) / 2 ;
V_9 -> V_78 = F_23 ( V_20 , V_79 ,
V_80 ) / 2 ;
V_9 -> V_81 = F_23 ( V_20 , V_82 ,
V_83 ) / 2 ;
V_56 = F_5 ( V_20 , 0x05 ) ;
V_9 -> V_84 = ( V_56 & F_24 ( 4 ) ? V_85 : 0 ) |
( V_56 & F_24 ( 5 ) ? V_86 : 0 ) ;
if ( V_9 -> V_10 == V_61 ) {
V_9 -> V_16 += F_23 ( V_20 , 0x0b , 0x1fff ) ;
V_9 -> V_87 = F_23 ( V_20 , 0x2c , 0x3fff ) / 2 ;
V_9 -> V_88 = F_23 ( V_20 , 0x30 , 0x3fff ) / 2 ;
V_9 -> V_89 = F_23 ( V_20 , 0x34 , 0x3fff ) / 2 ;
}
F_2 ( V_8 ) ;
V_2 -> V_8 = * V_8 ;
return 0 ;
}
static int F_25 ( struct V_47 * V_48 , T_2 * V_90 )
{
struct V_1 * V_2 = F_15 ( V_48 ) ;
struct V_19 * V_20 = F_16 ( V_2 ) ;
F_18 ( & V_20 -> V_51 ) ;
* V_90 = F_4 ( V_20 ) ? 0 : V_91 ;
F_20 ( & V_20 -> V_51 ) ;
return 0 ;
}
static int F_26 ( struct V_47 * V_48 , int V_92 )
{
struct V_1 * V_2 = F_15 ( V_48 ) ;
struct V_19 * V_20 = F_16 ( V_2 ) ;
int V_49 ;
F_18 ( & V_20 -> V_51 ) ;
V_49 = F_27 ( V_20 , V_92 ) ;
if ( V_49 )
goto V_93;
if ( F_4 ( V_20 ) )
F_28 ( V_20 , L_1 ) ;
else
F_28 ( V_20 , L_2 ) ;
V_93:
F_20 ( & V_20 -> V_51 ) ;
return V_49 ;
}
static int F_29 ( struct V_47 * V_48 ,
struct V_94 * V_95 )
{
V_95 -> V_96 = 1 ;
V_95 -> V_97 = 1 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_47 * V_98 ;
struct V_17 V_8 ;
struct V_54 * V_9 = & V_8 . V_9 ;
unsigned int V_99 ;
V_98 = F_31 ( & V_2 -> V_100 [ V_101 ] ) ;
if ( ! V_98 )
return - V_57 ;
F_22 ( & V_2 -> V_48 , & V_8 ) ;
V_99 = F_32 ( V_9 -> V_55 ,
F_33 ( V_9 ) *
F_34 ( V_9 ) ) ;
return F_35 ( V_98 , V_9 -> V_15 * V_9 -> V_16 * V_99 ) ;
}
static int F_36 ( struct V_47 * V_48 ,
struct V_102 * V_103 ,
struct V_104 * V_5 )
{
if ( V_5 -> V_105 != 0 )
return - V_40 ;
V_5 -> V_5 = V_6 ;
return 0 ;
}
static int F_37 ( struct V_47 * V_48 ,
struct V_102 * V_103 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 = F_15 ( V_48 ) ;
struct V_3 * V_108 ;
if ( V_107 -> V_109 != V_101 )
return - V_40 ;
if ( V_107 -> V_110 == V_111 ) {
V_108 = F_38 ( V_48 , V_103 , V_107 -> V_109 ) ;
V_107 -> V_112 = * V_108 ;
} else {
F_1 ( V_2 , & V_107 -> V_112 ) ;
F_30 ( V_2 ) ;
}
return 0 ;
}
static int F_39 ( struct V_47 * V_48 ,
struct V_102 * V_103 ,
struct V_106 * V_107 )
{
struct V_3 * V_108 ;
if ( V_107 -> V_109 != V_101 )
return - V_40 ;
if ( V_107 -> V_110 == V_113 )
return F_37 ( V_48 , V_103 , V_107 ) ;
V_108 = F_38 ( V_48 , V_103 , V_107 -> V_109 ) ;
* V_108 = V_107 -> V_112 ;
return 0 ;
}
static int F_40 ( struct V_47 * V_48 , struct V_114 * V_115 )
{
struct V_1 * V_2 = F_15 ( V_48 ) ;
memset ( V_115 -> V_116 , 0 , sizeof( V_115 -> V_116 ) ) ;
if ( ! V_2 -> V_115 . V_117 )
return - V_29 ;
if ( V_115 -> V_118 == 0 && V_115 -> V_119 == 0 ) {
V_115 -> V_119 = V_2 -> V_115 . V_119 ;
return 0 ;
}
if ( V_115 -> V_118 >= V_2 -> V_115 . V_119 )
return - V_40 ;
if ( V_115 -> V_118 + V_115 -> V_119 > V_2 -> V_115 . V_119 )
V_115 -> V_119 = V_2 -> V_115 . V_119 - V_115 -> V_118 ;
memcpy ( V_115 -> V_115 , V_2 -> V_115 . V_115 + V_115 -> V_118 * 128 ,
V_115 -> V_119 * 128 ) ;
return 0 ;
}
static inline int F_41 ( struct V_1 * V_2 ,
unsigned int V_120 , const T_1 * V_21 )
{
struct V_19 * V_20 = F_16 ( V_2 ) ;
int V_121 = 0 ;
int V_39 = 0 ;
int V_122 = 0 ;
F_28 ( V_20 , L_3 ,
V_123 , V_120 ) ;
while ( ! V_121 && V_39 < V_120 ) {
V_122 = ( V_120 - V_39 ) > V_124 ?
V_124 :
( V_120 - V_39 ) ;
V_121 = F_42 ( V_20 , V_125 ,
V_39 , V_21 + V_39 , V_122 ) ;
V_39 += V_122 ;
}
return V_121 ;
}
static int F_43 ( struct V_47 * V_48 , struct V_114 * V_115 )
{
struct V_1 * V_2 = F_15 ( V_48 ) ;
struct V_19 * V_20 = F_16 ( V_2 ) ;
int V_121 ;
memset ( V_115 -> V_116 , 0 , sizeof( V_115 -> V_116 ) ) ;
if ( V_115 -> V_118 != 0 )
return - V_40 ;
if ( V_115 -> V_119 == 0 ) {
V_2 -> V_115 . V_119 = 0 ;
V_2 -> V_115 . V_117 = 0 ;
V_2 -> V_126 . V_96 = 16 ;
V_2 -> V_126 . V_97 = 9 ;
F_44 ( V_20 , V_127 ,
V_115 -> V_119 << V_128 ) ;
F_44 ( V_20 , V_129 , 0 ) ;
return 0 ;
}
if ( V_115 -> V_119 > 4 ) {
V_115 -> V_119 = 4 ;
return - V_130 ;
}
memcpy ( V_2 -> V_115 . V_115 , V_115 -> V_115 , 128 * V_115 -> V_119 ) ;
V_2 -> V_115 . V_119 = V_115 -> V_119 ;
V_2 -> V_115 . V_117 = true ;
V_2 -> V_126 = F_45 ( V_115 -> V_115 [ 0x15 ] ,
V_115 -> V_115 [ 0x16 ] ) ;
V_121 = F_41 ( V_2 , 128 * V_115 -> V_119 ,
V_2 -> V_115 . V_115 ) ;
if ( V_121 < 0 ) {
F_46 ( V_48 , L_4 , V_121 , V_115 -> V_109 ) ;
return V_121 ;
}
F_44 ( V_20 , V_127 ,
V_115 -> V_119 << V_128 ) ;
F_44 ( V_20 , V_129 ,
V_131 ) ;
return 0 ;
}
static bool F_47 ( const struct V_17 * V_8 ,
void * V_132 )
{
const struct V_37 * V_38 =
V_37 ;
unsigned int V_39 ;
for ( V_39 = 0 ; V_38 [ V_39 ] . V_8 . V_9 . V_15 ; V_39 ++ )
if ( F_11 ( V_8 , & V_38 [ V_39 ] . V_8 , 0 , false ) )
return true ;
return false ;
}
static int F_48 ( struct V_47 * V_48 ,
struct V_133 * V_8 )
{
return F_49 ( V_8 , & V_18 ,
F_47 , NULL ) ;
}
static int F_50 ( struct V_47 * V_48 ,
struct V_134 * V_135 )
{
* V_135 = V_18 ;
return 0 ;
}
static int F_51 ( struct V_136 * V_137 )
{
struct V_1 * V_2 = F_52 ( V_137 ) ;
struct V_19 * V_20 = F_16 ( V_2 ) ;
int V_49 ;
T_1 V_138 ;
V_49 = F_19 ( V_20 , V_139 ,
V_140 ,
V_140 ) ;
if ( V_49 < 0 )
return V_49 ;
switch ( V_137 -> V_141 ) {
case V_142 :
V_49 = F_8 ( V_20 , V_143 , V_137 -> V_21 ) ;
break;
case V_144 :
V_49 = F_8 ( V_20 , V_145 , V_137 -> V_21 ) ;
break;
case V_146 :
V_49 = F_8 ( V_20 , V_147 , V_137 -> V_21 ) ;
break;
case V_148 :
V_49 = F_8 ( V_20 , V_149 , V_137 -> V_21 ) ;
break;
case V_150 :
V_138 = V_137 -> V_21 ;
if ( V_138 ) {
V_138 -- ;
V_138 |= V_151 ;
}
V_49 = F_8 ( V_20 , V_152 , V_138 ) ;
break;
default:
return - V_40 ;
}
return V_49 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = F_16 ( V_2 ) ;
F_54 ( & V_2 -> V_153 , 5 ) ;
V_2 -> V_153 . V_154 = & V_20 -> V_51 ;
F_55 ( & V_2 -> V_153 , & V_155 ,
V_142 , V_156 ,
V_157 , 1 , V_158 ) ;
F_55 ( & V_2 -> V_153 , & V_155 ,
V_146 , V_159 ,
V_160 , 1 , V_161 ) ;
F_55 ( & V_2 -> V_153 , & V_155 ,
V_148 , V_162 ,
V_163 , 1 , V_164 ) ;
F_55 ( & V_2 -> V_153 , & V_155 ,
V_144 , V_165 ,
V_166 , 1 , V_167 ) ;
F_56 ( & V_2 -> V_153 , & V_155 ,
V_150 ,
F_10 ( V_168 ) - 1 ,
0 , 0 , V_168 ) ;
V_2 -> V_48 . V_169 = & V_2 -> V_153 ;
if ( V_2 -> V_153 . error ) {
F_57 ( & V_2 -> V_153 ) ;
return V_2 -> V_153 . error ;
}
return F_58 ( & V_2 -> V_153 ) ;
}
int F_59 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = F_16 ( V_2 ) ;
static const struct V_17 V_170 =
V_171 ;
int V_49 ;
V_2 -> V_8 = V_170 ;
V_2 -> V_126 . V_96 = 16 ;
V_2 -> V_126 . V_97 = 9 ;
F_60 ( & V_2 -> V_48 , V_20 , & V_172 ,
V_173 , L_5 ) ;
V_2 -> V_100 [ V_174 ] . V_175 = V_176 ;
V_2 -> V_100 [ V_101 ] . V_175 = V_177 ;
V_49 = F_61 ( & V_2 -> V_48 . V_178 ,
V_179 , V_2 -> V_100 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_53 ( V_2 ) ;
if ( V_49 )
goto V_180;
return 0 ;
V_180:
F_62 ( & V_2 -> V_48 . V_178 ) ;
return V_49 ;
}
void F_63 ( struct V_1 * V_2 )
{
F_64 ( & V_2 -> V_48 ) ;
F_62 ( & V_2 -> V_48 . V_178 ) ;
F_57 ( & V_2 -> V_153 ) ;
}
