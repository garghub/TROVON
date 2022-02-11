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
F_23 ( L_8 , V_43 -> type ) ;
return - V_54 ;
}
static void F_24 ( struct V_44 * V_10 )
{
struct V_1 * V_2 = F_25 ( V_10 , struct V_1 , V_10 ) ;
F_26 ( V_10 ) ;
if ( V_2 -> V_6 -> V_55 )
V_2 -> V_6 -> V_55 ( V_2 ) ;
if ( V_2 -> V_32 ) {
F_27 ( & V_2 -> V_40 ) ;
V_2 -> V_32 = 0 ;
}
F_28 ( V_2 -> V_24 ) ;
F_29 ( V_2 ) ;
F_28 ( V_2 ) ;
}
int F_30 ( struct V_1 * V_2 , unsigned V_56 )
{
int V_57 , V_30 ;
F_31 ( V_2 -> V_25 , L_9 , V_2 -> V_58 ) ;
V_2 -> V_10 . V_55 = F_24 ;
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
V_2 -> V_33 -> V_49 & V_59 ) {
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
for ( V_57 = 0 ; V_57 < V_56 ; ++ V_57 )
F_19 ( & V_2 -> V_40 , & V_2 -> V_33 -> V_60 [ V_57 ] ) ;
if ( V_2 -> V_61 >= 0 ) {
struct V_62 V_63 = {
. V_13 = V_64 ,
. type = V_2 -> V_61 ,
. V_65 = V_66 ,
} ;
F_35 ( & V_2 -> V_10 , 0 , V_67 ,
V_68 , & V_63 ) ;
}
if ( V_2 -> V_36 == V_38 )
F_36 ( V_2 -> V_51 , V_69 , V_70 ,
0 , 0 , V_2 -> V_71 + 1 ) ;
}
V_30 = F_37 ( V_2 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_2 -> V_33 -> V_49 & V_72 ) {
V_2 -> V_73 = 1 ;
F_38 ( V_2 ) ;
}
return 0 ;
}
int F_39 ( struct V_1 * V_2 )
{
T_2 * V_74 ;
int V_20 , V_21 = 0 , V_57 , V_75 , V_76 ;
T_1 V_22 , V_23 ;
V_2 -> V_77 = 0 ;
for ( V_57 = 0 ; V_57 < 4 ; V_57 ++ )
V_2 -> V_78 [ V_57 ] . V_79 = 0 ;
switch ( F_40 ( V_2 -> V_80 ) ) {
case V_81 :
memset ( V_2 -> V_82 , 0 , sizeof( V_2 -> V_82 ) ) ;
V_2 -> V_78 [ 0 ] . V_79 = 1 ;
V_2 -> V_77 = 1 ;
break;
case V_83 :
for ( V_76 = 0 ; V_76 < V_2 -> V_84 / 16 ; V_76 ++ ) {
for ( V_75 = 0 ; V_75 < V_2 -> V_85 / 16 ; V_75 ++ ) {
int V_86 = V_76 * V_2 -> V_85 / 16 + V_75 ;
V_2 -> V_78 [ V_2 -> V_82 [ V_86 ] ] . V_79 = 1 ;
}
}
V_2 -> V_77 = 1 ;
break;
}
if ( V_2 -> V_87 )
V_2 -> V_77 = 0 ;
if ( F_41 ( V_2 , & V_74 , & V_20 ) < 0 )
return - 1 ;
if ( F_11 ( V_2 , V_74 , V_20 ) < 0 ||
F_1 ( V_2 , & V_22 , & V_23 ) < 0 ) {
F_3 ( & V_2 -> V_10 , L_7 ) ;
V_21 = - 1 ;
goto V_88;
}
V_2 -> V_89 = V_90 ;
V_2 -> V_91 = 0 ;
V_2 -> V_92 = 0 ;
if ( F_42 ( V_2 ) < 0 ) {
F_3 ( & V_2 -> V_10 , L_10 ) ;
V_21 = - 1 ;
goto V_88;
}
V_88:
F_28 ( V_74 ) ;
return V_21 ;
}
static inline void F_43 ( struct V_93 * V_94 , T_2 V_95 )
{
if ( V_94 && V_94 -> V_94 . V_96 [ 0 ] . V_97 < V_98 ) {
T_2 * V_99 = F_44 ( & V_94 -> V_94 , 0 ) ;
V_99 [ V_94 -> V_94 . V_96 [ 0 ] . V_97 ++ ] = V_95 ;
}
}
static void F_45 ( struct V_1 * V_2 , struct V_93 * V_94 ,
T_3 V_100 )
{
if ( V_100 != V_2 -> V_101 ) {
struct V_102 V_103 = {
. type = V_104 ,
. V_105 . V_106 = {
. V_49 = V_107 ,
. V_108 = V_94 -> V_94 . V_109 . V_110 ,
. V_111 = V_100 ,
} ,
} ;
F_46 ( & V_2 -> V_112 , & V_103 ) ;
V_2 -> V_101 = V_100 ;
}
}
static void F_47 ( struct V_1 * V_2 , struct V_93 * V_94 )
{
T_3 * V_97 = & V_94 -> V_94 . V_96 [ 0 ] . V_97 ;
unsigned V_113 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_3 V_100 = 0 ;
unsigned V_114 = ( V_2 -> V_85 + 7 ) >> 3 ;
unsigned V_75 , V_76 ;
int V_57 ;
for ( V_57 = 0 ; V_57 < 216 ; ++ V_57 )
F_43 ( V_94 , V_2 -> V_115 [ V_57 ] ) ;
for ( V_76 = 0 ; V_76 < V_2 -> V_84 / 16 ; V_76 ++ ) {
for ( V_75 = 0 ; V_75 < V_2 -> V_85 / 16 ; V_75 ++ ) {
if ( ! ( V_2 -> V_115 [ V_76 * V_114 + ( V_75 >> 3 ) ] & ( 1 << ( V_75 & 7 ) ) ) )
continue;
V_113 [ V_2 -> V_82 [ V_76 * ( V_2 -> V_85 / 16 ) + V_75 ] ] ++ ;
}
}
V_100 = ( ( V_113 [ 0 ] > 0 ) << 0 ) |
( ( V_113 [ 1 ] > 0 ) << 1 ) |
( ( V_113 [ 2 ] > 0 ) << 2 ) |
( ( V_113 [ 3 ] > 0 ) << 3 ) ;
* V_97 -= 216 ;
F_45 ( V_2 , V_94 , V_100 ) ;
}
static struct V_93 * F_48 ( struct V_1 * V_2 , struct V_93 * V_94 )
{
T_3 * V_97 = & V_94 -> V_94 . V_96 [ 0 ] . V_97 ;
struct V_93 * V_116 = NULL ;
if ( V_94 == NULL ) {
F_49 ( & V_2 -> V_117 ) ;
if ( ! F_50 ( & V_2 -> V_118 ) )
V_94 = V_2 -> V_119 =
F_51 ( & V_2 -> V_118 , struct V_93 , V_120 ) ;
F_52 ( & V_2 -> V_117 ) ;
V_2 -> V_121 ++ ;
return V_94 ;
}
V_94 -> V_94 . V_109 . V_110 = V_2 -> V_121 ++ ;
if ( V_94 -> V_122 && * V_97 + 216 < V_98 )
F_47 ( V_2 , V_94 ) ;
else
F_45 ( V_2 , V_94 , 0 ) ;
F_53 ( & V_94 -> V_94 . V_109 . V_123 ) ;
V_116 = V_94 ;
F_49 ( & V_2 -> V_117 ) ;
F_54 ( & V_94 -> V_120 ) ;
if ( F_50 ( & V_2 -> V_118 ) )
V_94 = NULL ;
else
V_94 = F_51 ( & V_2 -> V_118 , struct V_93 , V_120 ) ;
V_2 -> V_119 = V_94 ;
F_52 ( & V_2 -> V_117 ) ;
F_55 ( & V_116 -> V_94 , V_124 ) ;
return V_94 ;
}
static void F_56 ( struct V_1 * V_2 )
{
int V_75 , V_76 , V_57 , V_114 = ( ( V_2 -> V_85 >> 4 ) + 7 ) >> 3 ;
for ( V_57 = 0 ; V_57 < 16 ; ++ V_57 ) {
V_76 = ( ( ( V_2 -> V_91 - 1 ) << 3 ) + V_57 ) / ( V_2 -> V_85 >> 4 ) ;
V_75 = ( ( ( V_2 -> V_91 - 1 ) << 3 ) + V_57 ) % ( V_2 -> V_85 >> 4 ) ;
if ( V_114 * V_76 + ( V_75 >> 3 ) < sizeof( V_2 -> V_115 ) )
V_2 -> V_115 [ V_114 * V_76 + ( V_75 >> 3 ) ] |=
( V_2 -> V_125 & 1 ) << ( V_75 & 0x7 ) ;
V_2 -> V_125 >>= 1 ;
}
}
void F_57 ( struct V_1 * V_2 , T_2 * V_126 , int V_127 )
{
struct V_93 * V_94 = V_2 -> V_119 ;
int V_57 , V_128 = - 1 , V_129 = - 1 , V_130 = - 1 ;
switch ( V_2 -> V_131 ) {
case V_132 :
V_128 = 0xB0 ;
V_129 = 0xB3 ;
V_130 = 0xB6 ;
break;
case V_133 :
case V_134 :
V_128 = 0xB3 ;
V_129 = 0xB8 ;
V_130 = 0x00 ;
break;
}
for ( V_57 = 0 ; V_57 < V_127 ; ++ V_57 ) {
if ( V_94 && V_94 -> V_94 . V_96 [ 0 ] . V_97 >= V_98 - 3 ) {
F_58 ( & V_2 -> V_10 , L_11 ) ;
V_94 -> V_94 . V_96 [ 0 ] . V_97 = 0 ;
V_94 -> V_135 = 0 ;
V_94 -> V_122 = 0 ;
V_94 = V_2 -> V_119 = NULL ;
}
switch ( V_2 -> V_89 ) {
case V_90 :
switch ( V_126 [ V_57 ] ) {
case 0x00 :
V_2 -> V_89 = V_136 ;
break;
case 0xFF :
V_2 -> V_89 = V_137 ;
break;
default:
F_43 ( V_94 , V_126 [ V_57 ] ) ;
break;
}
break;
case V_136 :
switch ( V_126 [ V_57 ] ) {
case 0x00 :
V_2 -> V_89 = V_138 ;
break;
case 0xFF :
F_43 ( V_94 , 0x00 ) ;
V_2 -> V_89 = V_137 ;
break;
default:
F_43 ( V_94 , 0x00 ) ;
F_43 ( V_94 , V_126 [ V_57 ] ) ;
V_2 -> V_89 = V_90 ;
break;
}
break;
case V_138 :
switch ( V_126 [ V_57 ] ) {
case 0x00 :
F_43 ( V_94 , 0x00 ) ;
break;
case 0x01 :
V_2 -> V_89 = V_139 ;
break;
case 0xFF :
F_43 ( V_94 , 0x00 ) ;
F_43 ( V_94 , 0x00 ) ;
V_2 -> V_89 = V_137 ;
break;
default:
F_43 ( V_94 , 0x00 ) ;
F_43 ( V_94 , 0x00 ) ;
F_43 ( V_94 , V_126 [ V_57 ] ) ;
V_2 -> V_89 = V_90 ;
break;
}
break;
case V_139 :
if ( V_126 [ V_57 ] == 0xF8 && V_2 -> V_77 == 0 ) {
F_43 ( V_94 , 0x00 ) ;
F_43 ( V_94 , 0x00 ) ;
F_43 ( V_94 , 0x01 ) ;
F_43 ( V_94 , 0xF8 ) ;
V_2 -> V_89 = V_90 ;
break;
}
if ( ( V_2 -> V_131 == V_133 ||
V_2 -> V_131 == V_134 ||
V_2 -> V_131 == V_132 ) &&
( V_126 [ V_57 ] == V_128 ||
V_126 [ V_57 ] == V_129 ||
V_126 [ V_57 ] == V_130 ) ) {
if ( V_94 == NULL || V_2 -> V_92 )
V_94 = F_48 ( V_2 , V_94 ) ;
V_2 -> V_92 = V_126 [ V_57 ] == V_130 ;
if ( V_94 && V_2 -> V_92 )
V_94 -> V_135 = V_94 -> V_94 . V_96 [ 0 ] . V_97 ;
}
switch ( V_126 [ V_57 ] ) {
case 0xF5 :
V_2 -> V_91 = 12 ;
V_2 -> V_89 = V_140 ;
break;
case 0xF6 :
V_2 -> V_89 = V_141 ;
break;
case 0xF8 :
V_2 -> V_91 = 0 ;
memset ( V_2 -> V_115 , 0 ,
sizeof( V_2 -> V_115 ) ) ;
V_2 -> V_89 = V_142 ;
break;
case 0xFF :
F_43 ( V_94 , 0x00 ) ;
F_43 ( V_94 , 0x00 ) ;
F_43 ( V_94 , 0x01 ) ;
V_2 -> V_89 = V_137 ;
break;
default:
F_43 ( V_94 , 0x00 ) ;
F_43 ( V_94 , 0x00 ) ;
F_43 ( V_94 , 0x01 ) ;
F_43 ( V_94 , V_126 [ V_57 ] ) ;
V_2 -> V_89 = V_90 ;
break;
}
break;
case V_137 :
switch ( V_126 [ V_57 ] ) {
case 0x00 :
F_43 ( V_94 , 0xFF ) ;
V_2 -> V_89 = V_136 ;
break;
case 0xFF :
F_43 ( V_94 , 0xFF ) ;
break;
case 0xD8 :
if ( V_2 -> V_131 == V_143 )
V_94 = F_48 ( V_2 , V_94 ) ;
default:
F_43 ( V_94 , 0xFF ) ;
F_43 ( V_94 , V_126 [ V_57 ] ) ;
V_2 -> V_89 = V_90 ;
break;
}
break;
case V_141 :
V_2 -> V_91 = V_126 [ V_57 ] << 8 ;
V_2 -> V_89 = V_144 ;
break;
case V_144 :
V_2 -> V_91 |= V_126 [ V_57 ] ;
if ( V_2 -> V_91 > 0 )
V_2 -> V_89 = V_140 ;
else
V_2 -> V_89 = V_90 ;
break;
case V_142 :
if ( V_2 -> V_91 < 204 ) {
if ( V_2 -> V_91 & 1 ) {
V_2 -> V_125 |= V_126 [ V_57 ] ;
F_56 ( V_2 ) ;
} else
V_2 -> V_125 = V_126 [ V_57 ] << 8 ;
} else if ( V_2 -> V_91 == 207 && V_94 ) {
V_94 -> V_122 = V_126 [ V_57 ] ;
}
if ( ++ V_2 -> V_91 == 208 )
V_2 -> V_89 = V_90 ;
break;
case V_140 :
if ( -- V_2 -> V_91 == 0 )
V_2 -> V_89 = V_90 ;
break;
}
}
}
struct V_1 * F_59 ( const struct V_145 * V_146 ,
struct V_147 * V_25 )
{
struct V_1 * V_2 ;
int V_57 ;
V_2 = F_60 ( sizeof( struct V_1 ) , V_27 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_25 = V_25 ;
V_2 -> V_33 = V_146 ;
V_2 -> V_36 = 0 ;
V_2 -> V_61 = - 1 ;
V_2 -> V_71 = 0 ;
V_2 -> V_58 [ 0 ] = 0 ;
F_61 ( & V_2 -> V_31 ) ;
F_62 ( & V_2 -> V_148 ) ;
F_63 ( & V_2 -> V_117 ) ;
V_2 -> V_149 = V_150 ;
memset ( & V_2 -> V_40 , 0 , sizeof( V_2 -> V_40 ) ) ;
V_2 -> V_32 = 0 ;
V_2 -> V_5 = 0 ;
F_62 ( & V_2 -> V_8 ) ;
V_2 -> V_151 = 0 ;
F_64 ( V_2 ) ;
V_2 -> V_152 = 0 ;
V_2 -> V_153 = 0 ;
V_2 -> V_154 = 0 ;
V_2 -> V_131 = V_143 ;
V_2 -> V_155 = 1500000 ;
V_2 -> V_156 = 1 ;
V_2 -> V_157 = 0 ;
V_2 -> V_158 = V_159 ;
V_2 -> V_160 = 0 ;
V_2 -> V_161 = 0 ;
V_2 -> V_162 = 0 ;
V_2 -> V_163 = 0 ;
V_2 -> V_164 = 0 ;
V_2 -> V_165 = 0 ;
V_2 -> V_87 = 0 ;
V_2 -> V_166 = 0 ;
for ( V_57 = 0 ; V_57 < 4 ; ++ V_57 )
V_2 -> V_78 [ V_57 ] . V_79 = 0 ;
for ( V_57 = 0 ; V_57 < 1624 ; ++ V_57 )
V_2 -> V_82 [ V_57 ] = 0 ;
V_2 -> V_167 = NULL ;
V_2 -> V_73 = 0 ;
return V_2 ;
}
void F_64 ( struct V_1 * V_2 )
{
const struct V_145 * V_146 = V_2 -> V_33 ;
if ( V_146 -> V_168 & V_169 ) {
V_2 -> V_170 = V_171 ;
V_2 -> V_172 = V_173 ;
V_2 -> V_85 = 720 ;
V_2 -> V_84 = 480 ;
V_2 -> V_174 = 30000 ;
} else {
V_2 -> V_170 = V_175 ;
V_2 -> V_85 = V_146 -> V_176 ;
V_2 -> V_84 = V_146 -> V_177 ;
V_2 -> V_174 = V_146 -> V_174 ;
}
V_2 -> V_178 = V_146 -> V_179 ;
V_2 -> V_180 = V_146 -> V_181 ;
}
