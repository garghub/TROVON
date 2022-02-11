int F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 )
{
V_2 -> V_5 = 0 ;
V_2 -> V_6 -> V_7 ( V_2 ) ;
if ( F_2 ( V_2 -> V_8 ,
V_2 -> V_5 , 5 * V_9 ) < 0 ) {
F_3 ( & V_2 -> V_10 , L_1 ) ;
return - 1 ;
}
if ( ! V_2 -> V_5 )
return - 1 ;
V_2 -> V_5 = 0 ;
* V_3 = V_2 -> V_11 & 0xfffe ;
* V_4 = V_2 -> V_12 ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 , T_1 V_13 , T_1 * V_4 )
{
int V_14 = 100 ;
T_1 V_3 ;
if ( F_5 ( V_2 , 0x0010 , V_13 ) < 0 )
return - V_15 ;
while ( V_14 -- > 0 ) {
if ( F_1 ( V_2 , & V_3 , V_4 ) == 0 &&
V_3 == 0xa000 )
return 0 ;
}
return - V_15 ;
}
static int F_6 ( struct V_1 * V_2 )
{
const struct V_16 * V_17 ;
char V_18 [] = L_2 ;
void * V_19 ;
int V_20 , V_21 = 0 ;
T_1 V_22 , V_23 ;
if ( V_2 -> V_24 == NULL ) {
if ( F_7 ( & V_17 , V_18 , V_2 -> V_25 ) ) {
F_3 ( V_2 , L_3 , V_18 ) ;
return - 1 ;
}
if ( V_17 -> V_26 < 16 || memcmp ( V_17 -> V_4 , L_4 , 11 ) ) {
F_3 ( V_2 , L_5 , V_18 ) ;
F_8 ( V_17 ) ;
return - 1 ;
}
V_20 = V_17 -> V_26 - 16 ;
V_19 = F_9 ( V_17 -> V_4 + 16 , V_20 , V_27 ) ;
if ( V_19 == NULL ) {
F_3 ( V_2 , L_6 , V_20 ) ;
F_8 ( V_17 ) ;
return - 1 ;
}
F_8 ( V_17 ) ;
V_2 -> V_28 = V_20 ;
V_2 -> V_24 = V_19 ;
}
if ( F_10 ( V_2 ) < 0 ||
F_11 ( V_2 , V_2 -> V_24 , V_2 -> V_28 ) < 0 ||
F_1 ( V_2 , & V_22 , & V_23 ) < 0 ||
( V_22 & ~ 0x1 ) != 0x5a5a ) {
F_3 ( V_2 , L_7 ) ;
V_21 = - 1 ;
}
return V_21 ;
}
int F_12 ( struct V_1 * V_2 , int V_29 )
{
int V_30 ;
F_13 ( & V_2 -> V_31 ) ;
V_30 = F_6 ( V_2 ) ;
F_14 ( & V_2 -> V_31 ) ;
if ( V_30 < 0 )
return - 1 ;
if ( ! V_29 )
return 0 ;
if ( F_15 ( V_2 ) < 0 )
return - 1 ;
V_2 -> V_32 = 1 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_33 -> V_34 & V_35 ) {
F_17 ( V_2 , 0x1000 , 0x0811 ) ;
F_17 ( V_2 , 0x1000 , 0x0c11 ) ;
}
switch ( V_2 -> V_36 ) {
case V_37 :
F_17 ( V_2 , 0x3c82 , 0x0001 ) ;
F_17 ( V_2 , 0x3c80 , 0x00fe ) ;
break;
case V_38 :
F_17 ( V_2 , 0x3c82 , 0x0000 ) ;
F_17 ( V_2 , 0x3c80 , 0x00df ) ;
break;
case V_39 :
F_17 ( V_2 , 0x3c82 , 0x000d ) ;
F_17 ( V_2 , 0x3c80 , 0x00f2 ) ;
break;
}
return 0 ;
}
int F_18 ( struct V_1 * V_2 )
{
if ( F_6 ( V_2 ) < 0 )
return - 1 ;
return F_16 ( V_2 ) ;
}
static int F_19 ( struct V_40 * V_41 , const struct V_42 * const V_43 )
{
struct V_1 * V_2 = F_20 ( V_41 ) ;
struct V_44 * V_10 = & V_2 -> V_10 ;
struct V_45 * V_46 ;
struct V_47 V_48 ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
F_21 ( V_48 . type , V_43 -> type , sizeof( V_48 . type ) ) ;
V_48 . V_13 = V_43 -> V_13 ;
V_48 . V_49 = V_43 -> V_49 ;
V_46 = F_22 ( V_10 , V_41 , & V_48 , NULL ) ;
if ( V_46 ) {
if ( V_43 -> V_50 )
V_2 -> V_51 = V_46 ;
if ( V_43 -> V_52 )
V_2 -> V_53 = V_46 ;
return 0 ;
}
F_23 ( V_54 L_8 , V_43 -> type ) ;
return - V_55 ;
}
static void F_24 ( struct V_44 * V_10 )
{
struct V_1 * V_2 = F_25 ( V_10 , struct V_1 , V_10 ) ;
F_26 ( V_10 ) ;
if ( V_2 -> V_6 -> V_56 )
V_2 -> V_6 -> V_56 ( V_2 ) ;
if ( V_2 -> V_32 ) {
F_27 ( & V_2 -> V_40 ) ;
V_2 -> V_32 = 0 ;
}
F_28 ( V_2 -> V_24 ) ;
F_29 ( V_2 ) ;
F_28 ( V_2 ) ;
}
int F_30 ( struct V_1 * V_2 , unsigned V_57 )
{
int V_58 , V_30 ;
F_31 ( V_2 -> V_25 , L_9 , V_2 -> V_59 ) ;
V_2 -> V_10 . V_56 = F_24 ;
V_30 = F_32 ( V_2 -> V_25 , & V_2 -> V_10 ) ;
if ( V_30 < 0 )
return V_30 ;
F_13 ( & V_2 -> V_31 ) ;
V_30 = F_16 ( V_2 ) ;
F_14 ( & V_2 -> V_31 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_33 ( V_2 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( ! V_2 -> V_32 &&
V_2 -> V_33 -> V_49 & V_60 ) {
V_30 = F_15 ( V_2 ) ;
if ( V_30 < 0 )
return V_30 ;
V_2 -> V_32 = 1 ;
}
if ( V_2 -> V_32 ) {
if ( V_2 -> V_36 == V_39 ) {
F_17 ( V_2 , 0x3c82 , 0x0009 ) ;
F_34 ( 50 ) ;
F_17 ( V_2 , 0x3c82 , 0x000d ) ;
}
for ( V_58 = 0 ; V_58 < V_57 ; ++ V_58 )
F_19 ( & V_2 -> V_40 , & V_2 -> V_33 -> V_61 [ V_58 ] ) ;
if ( V_2 -> V_62 >= 0 ) {
struct V_63 V_64 = {
. V_13 = V_65 ,
. type = V_2 -> V_62 ,
. V_66 = V_67 ,
} ;
F_35 ( & V_2 -> V_10 , 0 , V_68 ,
V_69 , & V_64 ) ;
}
if ( V_2 -> V_36 == V_38 )
F_36 ( V_2 -> V_51 , V_70 , V_71 ,
0 , 0 , V_2 -> V_72 + 1 ) ;
}
V_30 = F_37 ( V_2 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_2 -> V_33 -> V_49 & V_73 ) {
V_2 -> V_74 = 1 ;
F_38 ( V_2 ) ;
}
return 0 ;
}
int F_39 ( struct V_1 * V_2 )
{
T_2 * V_75 ;
int V_20 , V_21 = 0 , V_58 ;
T_1 V_22 , V_23 ;
V_2 -> V_76 = 0 ;
if ( ! V_2 -> V_77 )
for ( V_58 = 0 ; V_58 < 4 ; ++ V_58 ) {
if ( V_2 -> V_78 [ V_58 ] . V_79 ) {
V_2 -> V_76 = 1 ;
continue;
}
V_2 -> V_78 [ V_58 ] . V_80 = 32767 ;
V_2 -> V_78 [ V_58 ] . V_81 = 32767 ;
V_2 -> V_78 [ V_58 ] . V_82 = 32767 ;
}
if ( F_40 ( V_2 , & V_75 , & V_20 ) < 0 )
return - 1 ;
if ( F_11 ( V_2 , V_75 , V_20 ) < 0 ||
F_1 ( V_2 , & V_22 , & V_23 ) < 0 ) {
F_3 ( & V_2 -> V_10 , L_7 ) ;
V_21 = - 1 ;
goto V_83;
}
V_2 -> V_84 = V_85 ;
V_2 -> V_86 = 0 ;
V_2 -> V_87 = 0 ;
if ( F_41 ( V_2 ) < 0 ) {
F_3 ( & V_2 -> V_10 , L_10 ) ;
V_21 = - 1 ;
goto V_83;
}
V_83:
F_28 ( V_75 ) ;
return V_21 ;
}
static inline void F_42 ( struct V_88 * V_89 , T_2 V_90 )
{
if ( V_89 && V_89 -> V_89 . V_91 [ 0 ] . V_92 < V_93 ) {
T_2 * V_94 = F_43 ( & V_89 -> V_89 , 0 ) ;
V_94 [ V_89 -> V_89 . V_91 [ 0 ] . V_92 ++ ] = V_90 ;
}
}
static struct V_88 * F_44 ( struct V_1 * V_2 , struct V_88 * V_89 )
{
struct V_88 * V_95 = NULL ;
T_3 * V_92 = & V_89 -> V_89 . V_91 [ 0 ] . V_92 ;
int V_58 ;
if ( V_89 ) {
if ( V_89 -> V_96 ) {
if ( * V_92 + 216 < V_93 ) {
for ( V_58 = 0 ; V_58 < 216 ; ++ V_58 )
F_42 ( V_89 , V_2 -> V_97 [ V_58 ] ) ;
* V_92 -= 216 ;
} else
V_89 -> V_96 = 0 ;
}
V_89 -> V_89 . V_98 . V_99 = V_2 -> V_100 ++ ;
F_45 ( & V_89 -> V_89 . V_98 . V_101 ) ;
V_95 = V_89 ;
F_46 ( & V_2 -> V_102 ) ;
F_47 ( & V_89 -> V_103 ) ;
if ( F_48 ( & V_2 -> V_104 ) )
V_89 = NULL ;
else
V_89 = F_49 ( & V_2 -> V_104 , struct V_88 , V_103 ) ;
V_2 -> V_105 = V_89 ;
F_50 ( & V_2 -> V_102 ) ;
F_51 ( & V_95 -> V_89 , V_106 ) ;
return V_89 ;
}
F_46 ( & V_2 -> V_102 ) ;
if ( ! F_48 ( & V_2 -> V_104 ) )
V_89 = V_2 -> V_105 =
F_49 ( & V_2 -> V_104 , struct V_88 , V_103 ) ;
F_50 ( & V_2 -> V_102 ) ;
V_2 -> V_100 ++ ;
return V_89 ;
}
static void F_52 ( struct V_1 * V_2 )
{
int V_107 , V_108 , V_58 , V_109 = ( ( V_2 -> V_110 >> 4 ) + 7 ) >> 3 ;
for ( V_58 = 0 ; V_58 < 16 ; ++ V_58 ) {
V_108 = ( ( ( V_2 -> V_86 - 1 ) << 3 ) + V_58 ) / ( V_2 -> V_110 >> 4 ) ;
V_107 = ( ( ( V_2 -> V_86 - 1 ) << 3 ) + V_58 ) % ( V_2 -> V_110 >> 4 ) ;
if ( V_109 * V_108 + ( V_107 >> 3 ) < sizeof( V_2 -> V_97 ) )
V_2 -> V_97 [ V_109 * V_108 + ( V_107 >> 3 ) ] |=
( V_2 -> V_111 & 1 ) << ( V_107 & 0x7 ) ;
V_2 -> V_111 >>= 1 ;
}
}
void F_53 ( struct V_1 * V_2 , T_2 * V_112 , int V_113 )
{
struct V_88 * V_89 = V_2 -> V_105 ;
int V_58 , V_114 = - 1 , V_115 = - 1 , V_116 = - 1 ;
switch ( V_2 -> V_117 ) {
case V_118 :
V_114 = 0xB0 ;
V_115 = 0xB3 ;
V_116 = 0xB6 ;
break;
case V_119 :
case V_120 :
V_114 = 0xB3 ;
V_115 = 0xB8 ;
V_116 = 0x00 ;
break;
}
for ( V_58 = 0 ; V_58 < V_113 ; ++ V_58 ) {
if ( V_89 && V_89 -> V_89 . V_91 [ 0 ] . V_92 >= V_93 - 3 ) {
F_54 ( & V_2 -> V_10 , L_11 ) ;
V_89 -> V_89 . V_91 [ 0 ] . V_92 = 0 ;
V_89 -> V_121 = 0 ;
V_89 -> V_96 = 0 ;
V_89 = V_2 -> V_105 = NULL ;
}
switch ( V_2 -> V_84 ) {
case V_85 :
switch ( V_112 [ V_58 ] ) {
case 0x00 :
V_2 -> V_84 = V_122 ;
break;
case 0xFF :
V_2 -> V_84 = V_123 ;
break;
default:
F_42 ( V_89 , V_112 [ V_58 ] ) ;
break;
}
break;
case V_122 :
switch ( V_112 [ V_58 ] ) {
case 0x00 :
V_2 -> V_84 = V_124 ;
break;
case 0xFF :
F_42 ( V_89 , 0x00 ) ;
V_2 -> V_84 = V_123 ;
break;
default:
F_42 ( V_89 , 0x00 ) ;
F_42 ( V_89 , V_112 [ V_58 ] ) ;
V_2 -> V_84 = V_85 ;
break;
}
break;
case V_124 :
switch ( V_112 [ V_58 ] ) {
case 0x00 :
F_42 ( V_89 , 0x00 ) ;
break;
case 0x01 :
V_2 -> V_84 = V_125 ;
break;
case 0xFF :
F_42 ( V_89 , 0x00 ) ;
F_42 ( V_89 , 0x00 ) ;
V_2 -> V_84 = V_123 ;
break;
default:
F_42 ( V_89 , 0x00 ) ;
F_42 ( V_89 , 0x00 ) ;
F_42 ( V_89 , V_112 [ V_58 ] ) ;
V_2 -> V_84 = V_85 ;
break;
}
break;
case V_125 :
if ( V_112 [ V_58 ] == 0xF8 && V_2 -> V_76 == 0 ) {
F_42 ( V_89 , 0x00 ) ;
F_42 ( V_89 , 0x00 ) ;
F_42 ( V_89 , 0x01 ) ;
F_42 ( V_89 , 0xF8 ) ;
V_2 -> V_84 = V_85 ;
break;
}
if ( ( V_2 -> V_117 == V_119 ||
V_2 -> V_117 == V_120 ||
V_2 -> V_117 == V_118 ) &&
( V_112 [ V_58 ] == V_114 ||
V_112 [ V_58 ] == V_115 ||
V_112 [ V_58 ] == V_116 ) ) {
if ( V_89 == NULL || V_2 -> V_87 )
V_89 = F_44 ( V_2 , V_89 ) ;
V_2 -> V_87 = V_112 [ V_58 ] == V_116 ;
if ( V_89 && V_2 -> V_87 )
V_89 -> V_121 = V_89 -> V_89 . V_91 [ 0 ] . V_92 ;
}
switch ( V_112 [ V_58 ] ) {
case 0xF5 :
V_2 -> V_86 = 12 ;
V_2 -> V_84 = V_126 ;
break;
case 0xF6 :
V_2 -> V_84 = V_127 ;
break;
case 0xF8 :
V_2 -> V_86 = 0 ;
memset ( V_2 -> V_97 , 0 ,
sizeof( V_2 -> V_97 ) ) ;
V_2 -> V_84 = V_128 ;
break;
case 0xFF :
F_42 ( V_89 , 0x00 ) ;
F_42 ( V_89 , 0x00 ) ;
F_42 ( V_89 , 0x01 ) ;
V_2 -> V_84 = V_123 ;
break;
default:
F_42 ( V_89 , 0x00 ) ;
F_42 ( V_89 , 0x00 ) ;
F_42 ( V_89 , 0x01 ) ;
F_42 ( V_89 , V_112 [ V_58 ] ) ;
V_2 -> V_84 = V_85 ;
break;
}
break;
case V_123 :
switch ( V_112 [ V_58 ] ) {
case 0x00 :
F_42 ( V_89 , 0xFF ) ;
V_2 -> V_84 = V_122 ;
break;
case 0xFF :
F_42 ( V_89 , 0xFF ) ;
break;
case 0xD8 :
if ( V_2 -> V_117 == V_129 )
V_89 = F_44 ( V_2 , V_89 ) ;
default:
F_42 ( V_89 , 0xFF ) ;
F_42 ( V_89 , V_112 [ V_58 ] ) ;
V_2 -> V_84 = V_85 ;
break;
}
break;
case V_127 :
V_2 -> V_86 = V_112 [ V_58 ] << 8 ;
V_2 -> V_84 = V_130 ;
break;
case V_130 :
V_2 -> V_86 |= V_112 [ V_58 ] ;
if ( V_2 -> V_86 > 0 )
V_2 -> V_84 = V_126 ;
else
V_2 -> V_84 = V_85 ;
break;
case V_128 :
if ( V_2 -> V_86 < 204 ) {
if ( V_2 -> V_86 & 1 ) {
V_2 -> V_111 |= V_112 [ V_58 ] ;
F_52 ( V_2 ) ;
} else
V_2 -> V_111 = V_112 [ V_58 ] << 8 ;
} else if ( V_2 -> V_86 == 207 && V_89 ) {
V_89 -> V_96 = V_112 [ V_58 ] ;
}
if ( ++ V_2 -> V_86 == 208 )
V_2 -> V_84 = V_85 ;
break;
case V_126 :
if ( -- V_2 -> V_86 == 0 )
V_2 -> V_84 = V_85 ;
break;
}
}
}
struct V_1 * F_55 ( const struct V_131 * V_132 ,
struct V_133 * V_25 )
{
struct V_1 * V_2 ;
int V_58 ;
V_2 = F_56 ( sizeof( struct V_1 ) , V_27 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_25 = V_25 ;
V_2 -> V_33 = V_132 ;
V_2 -> V_36 = 0 ;
V_2 -> V_62 = - 1 ;
V_2 -> V_72 = 0 ;
V_2 -> V_59 [ 0 ] = 0 ;
F_57 ( & V_2 -> V_31 ) ;
F_58 ( & V_2 -> V_134 ) ;
F_59 ( & V_2 -> V_102 ) ;
V_2 -> V_135 = V_136 ;
memset ( & V_2 -> V_40 , 0 , sizeof( V_2 -> V_40 ) ) ;
V_2 -> V_32 = 0 ;
V_2 -> V_5 = 0 ;
F_58 ( & V_2 -> V_8 ) ;
V_2 -> V_137 = 0 ;
F_60 ( V_2 ) ;
V_2 -> V_138 = 0 ;
V_2 -> V_139 = 0 ;
V_2 -> V_140 = 0 ;
V_2 -> V_117 = V_129 ;
V_2 -> V_141 = 1500000 ;
V_2 -> V_142 = 1 ;
V_2 -> V_143 = 0 ;
V_2 -> V_144 = V_145 ;
V_2 -> V_146 = 0 ;
V_2 -> V_147 = 0 ;
V_2 -> V_148 = 0 ;
V_2 -> V_149 = 0 ;
V_2 -> V_150 = 0 ;
V_2 -> V_151 = 0 ;
V_2 -> V_77 = 0 ;
V_2 -> V_152 = 0 ;
for ( V_58 = 0 ; V_58 < 4 ; ++ V_58 )
V_2 -> V_78 [ V_58 ] . V_79 = 0 ;
for ( V_58 = 0 ; V_58 < 1624 ; ++ V_58 )
V_2 -> V_153 [ V_58 ] = 0 ;
V_2 -> V_154 = NULL ;
V_2 -> V_74 = 0 ;
return V_2 ;
}
void F_60 ( struct V_1 * V_2 )
{
const struct V_131 * V_132 = V_2 -> V_33 ;
if ( V_132 -> V_155 & V_156 ) {
V_2 -> V_157 = V_158 ;
V_2 -> V_159 = V_160 ;
V_2 -> V_110 = 720 ;
V_2 -> V_161 = 480 ;
V_2 -> V_162 = 30000 ;
} else {
V_2 -> V_157 = V_163 ;
V_2 -> V_110 = V_132 -> V_164 ;
V_2 -> V_161 = V_132 -> V_165 ;
V_2 -> V_162 = V_132 -> V_162 ;
}
V_2 -> V_166 = V_132 -> V_167 ;
V_2 -> V_168 = V_132 -> V_169 ;
}
