int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * const * V_5 )
{
if ( V_4 -> V_6 & V_7 )
return - V_8 ;
if ( V_4 -> V_6 & V_9 )
return - V_10 ;
if ( V_4 -> type == V_11 )
return 0 ;
if ( V_4 -> type == V_12 ||
V_4 -> type == V_13 ||
V_4 -> type == V_14 )
return 0 ;
if ( V_2 -> V_15 < V_4 -> V_16 || V_2 -> V_15 > V_4 -> V_17 )
return - V_18 ;
if ( V_4 -> type == V_19 && V_5 != NULL ) {
if ( V_5 [ V_2 -> V_15 ] == NULL ||
V_5 [ V_2 -> V_15 ] [ 0 ] == '\0' )
return - V_8 ;
}
if ( V_4 -> type == V_20 &&
( V_2 -> V_15 & ~ V_4 -> V_17 ) )
return - V_18 ;
return 0 ;
}
int F_2 ( struct V_3 * V_4 , T_1 V_21 , T_1 V_22 , T_1 V_23 , T_1 V_24 )
{
const char * V_25 ;
F_3 ( V_4 -> V_26 , & V_25 , & V_4 -> type ,
& V_21 , & V_22 , & V_23 , & V_24 , & V_4 -> V_6 ) ;
if ( V_25 == NULL )
return - V_8 ;
V_4 -> V_16 = V_21 ;
V_4 -> V_17 = V_22 ;
V_4 -> V_23 = V_23 ;
V_4 -> V_27 = V_24 ;
V_4 -> V_28 [ 0 ] = V_4 -> V_28 [ 1 ] = 0 ;
F_4 ( V_4 -> V_25 , V_25 , sizeof( V_4 -> V_25 ) ) ;
return 0 ;
}
int F_5 ( struct V_29 * V_30 , struct V_3 * V_4 ,
const char * const * V_5 )
{
int V_31 ;
V_30 -> V_28 = 0 ;
if ( V_5 == NULL )
V_5 = F_6 ( V_30 -> V_26 ) ;
if ( V_5 == NULL ||
( V_4 && ( V_30 -> V_32 < V_4 -> V_16 || V_30 -> V_32 > V_4 -> V_17 ) ) )
return - V_8 ;
for ( V_31 = 0 ; V_31 < V_30 -> V_32 && V_5 [ V_31 ] ; V_31 ++ ) ;
if ( V_5 [ V_31 ] == NULL || V_5 [ V_31 ] [ 0 ] == '\0' )
return - V_8 ;
F_4 ( V_30 -> V_25 , V_5 [ V_30 -> V_32 ] , sizeof( V_30 -> V_25 ) ) ;
return 0 ;
}
int F_7 ( struct V_29 * V_30 , const T_2 * V_33 )
{
const char * const * V_5 = F_6 ( V_30 -> V_26 ) ;
V_30 -> V_28 = 0 ;
if ( V_5 == NULL || V_33 == NULL )
return - V_8 ;
while ( * V_33 != V_34 ) {
if ( * V_33 ++ == V_30 -> V_32 ) {
F_4 ( V_30 -> V_25 , V_5 [ V_30 -> V_32 ] ,
sizeof( V_30 -> V_25 ) ) ;
return 0 ;
}
}
return - V_8 ;
}
T_2 F_8 ( const T_2 * const * V_35 , T_2 V_26 )
{
T_2 V_36 = F_9 ( V_26 ) ;
const T_2 * V_37 ;
if ( V_35 == NULL )
return 0 ;
if ( ( V_26 & V_38 ) == 0 ) {
while ( * V_35 && F_9 ( * * V_35 ) != V_36 )
V_35 ++ ;
if ( * V_35 == NULL )
return 0 ;
V_37 = * V_35 ;
while ( * V_37 && * V_37 != V_26 ) V_37 ++ ;
return * V_37 ? V_26 : 0 ;
}
V_26 &= V_39 ;
V_26 ++ ;
while ( * V_35 && F_9 ( * * V_35 ) < V_36 )
V_35 ++ ;
if ( * V_35 == NULL )
return 0 ;
V_37 = * V_35 ;
while ( * V_37 && * V_37 < V_26 ) V_37 ++ ;
if ( * V_37 )
return * V_37 ;
V_35 ++ ;
if ( * V_35 == NULL )
return 0 ;
return * * V_35 ;
}
int F_10 ( const struct V_40 * V_41 )
{
switch ( V_41 -> type ) {
case V_42 :
return V_41 -> V_43 == 0 ;
default:
return 0 ;
}
}
int F_11 ( struct V_44 * V_45 , const struct V_40 * V_41 )
{
int V_46 ;
if ( V_45 == NULL || V_41 == NULL )
return 0 ;
switch ( V_41 -> type ) {
case V_47 :
if ( V_45 -> V_48 == NULL || V_45 -> V_48 -> V_48 . V_25 == NULL )
return 0 ;
V_46 = strlen ( V_45 -> V_48 -> V_48 . V_25 ) ;
if ( V_46 && V_45 -> V_48 -> V_48 . V_25 [ V_46 - 1 ] == '\'' )
V_46 -- ;
return V_46 && ! strncmp ( V_45 -> V_48 -> V_48 . V_25 , V_41 -> V_25 , V_46 ) ;
case V_49 :
return V_45 -> V_43 == V_41 -> V_43 ;
default:
return 0 ;
}
}
int F_12 ( struct V_44 * V_45 , struct V_50 * V_51 ,
T_2 V_52 , T_2 V_53 )
{
if ( ! F_11 ( V_45 , & V_51 -> V_41 ) )
return 0 ;
if ( V_51 -> V_52 == V_54 ) {
V_51 -> V_52 = V_52 ;
V_51 -> V_53 = V_53 ;
}
else {
V_51 -> V_52 = V_55 ;
V_51 -> V_53 = 0 ;
}
return 0 ;
}
void F_13 ( struct V_56 * V_57 , struct V_44 * V_58 ,
const struct V_59 * V_60 )
{
F_14 ( V_57 , V_60 ) ;
V_57 -> V_6 |= V_61 ;
V_57 -> V_62 = V_58 -> V_48 -> V_48 . V_62 ;
F_15 ( V_57 , V_58 ) ;
F_16 ( V_58 , V_57 ) ;
snprintf ( V_57 -> V_25 , sizeof( V_57 -> V_25 ) , L_1 ,
V_58 -> V_48 -> V_48 . V_25 , F_17 ( V_58 -> V_63 ) ,
V_58 -> V_43 ) ;
}
struct V_56 * F_18 ( struct V_64 * V_65 ,
struct V_66 * V_63 , struct V_67 * V_68 ,
const unsigned short * V_69 )
{
struct V_56 * V_57 = NULL ;
struct V_44 * V_58 ;
F_19 ( ! V_65 ) ;
F_20 ( V_70 L_2 , V_68 -> type ) ;
if ( V_68 -> V_43 == 0 && V_69 )
V_58 = F_21 ( V_63 , V_68 , V_69 ,
NULL ) ;
else
V_58 = F_22 ( V_63 , V_68 ) ;
if ( V_58 == NULL || V_58 -> V_48 == NULL )
goto error;
if ( ! F_23 ( V_58 -> V_48 -> V_48 . V_62 ) )
goto error;
V_57 = F_24 ( V_58 ) ;
if ( F_25 ( V_65 , V_57 ) )
V_57 = NULL ;
F_26 ( V_58 -> V_48 -> V_48 . V_62 ) ;
error:
if ( V_58 && V_57 == NULL )
F_27 ( V_58 ) ;
return V_57 ;
}
struct V_56 * F_28 ( struct V_64 * V_65 ,
struct V_66 * V_63 , const char * V_71 ,
T_3 V_43 , const unsigned short * V_69 )
{
struct V_67 V_68 ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
F_4 ( V_68 . type , V_71 , sizeof( V_68 . type ) ) ;
V_68 . V_43 = V_43 ;
return F_18 ( V_65 , V_63 , & V_68 , V_69 ) ;
}
unsigned short F_29 ( struct V_56 * V_57 )
{
struct V_44 * V_58 = F_30 ( V_57 ) ;
return V_58 ? V_58 -> V_43 : V_72 ;
}
const unsigned short * F_31 ( enum V_73 type )
{
static const unsigned short V_74 [] = {
#if F_32 ( V_75 )
0x10 ,
#endif
0x60 ,
V_72
} ;
static const unsigned short V_76 [] = {
0x42 , 0x43 , 0x4a , 0x4b ,
V_72
} ;
static const unsigned short V_77 [] = {
0x42 , 0x43 , 0x4a , 0x4b ,
0x60 , 0x61 , 0x62 , 0x63 , 0x64 ,
V_72
} ;
switch ( type ) {
case V_78 :
return V_74 ;
case V_79 :
return V_76 ;
case V_80 :
return V_77 ;
case V_81 :
return V_77 + 4 ;
}
return NULL ;
}
void F_33 ( struct V_56 * V_57 , struct V_82 * V_83 ,
const struct V_59 * V_60 )
{
F_14 ( V_57 , V_60 ) ;
V_57 -> V_6 |= V_84 ;
V_57 -> V_62 = V_83 -> V_85 . V_48 -> V_62 ;
F_15 ( V_57 , V_83 ) ;
F_34 ( V_83 , V_57 ) ;
F_4 ( V_57 -> V_25 , V_83 -> V_85 . V_48 -> V_25 , sizeof( V_57 -> V_25 ) ) ;
}
struct V_56 * F_35 ( struct V_64 * V_65 ,
struct V_86 * V_87 , struct V_88 * V_68 )
{
struct V_56 * V_57 = NULL ;
struct V_82 * V_83 = NULL ;
F_19 ( ! V_65 ) ;
if ( V_68 -> V_89 [ 0 ] )
F_20 ( V_68 -> V_89 ) ;
V_83 = F_36 ( V_87 , V_68 ) ;
if ( V_83 == NULL || V_83 -> V_85 . V_48 == NULL )
goto error;
if ( ! F_23 ( V_83 -> V_85 . V_48 -> V_62 ) )
goto error;
V_57 = F_37 ( V_83 ) ;
if ( F_25 ( V_65 , V_57 ) )
V_57 = NULL ;
F_26 ( V_83 -> V_85 . V_48 -> V_62 ) ;
error:
if ( V_83 && V_57 == NULL )
F_38 ( V_83 ) ;
return V_57 ;
}
static unsigned int F_39 ( unsigned int V_90 , unsigned int V_21 ,
unsigned int V_22 , unsigned int V_91 )
{
unsigned int V_92 = ~ ( ( 1 << V_91 ) - 1 ) ;
if ( V_91 )
V_90 = ( V_90 + ( 1 << ( V_91 - 1 ) ) ) & V_92 ;
if ( V_90 < V_21 )
V_90 = ( V_21 + ~ V_92 ) & V_92 ;
else if ( V_90 > V_22 )
V_90 = V_22 & V_92 ;
return V_90 ;
}
void F_40 ( T_2 * V_93 , unsigned int V_94 , unsigned int V_95 ,
unsigned int V_96 ,
T_2 * V_97 , unsigned int V_98 , unsigned int V_99 ,
unsigned int V_100 , unsigned int V_101 )
{
* V_93 = F_39 ( * V_93 , V_94 , V_95 , V_96 ) ;
* V_97 = F_39 ( * V_97 , V_98 , V_99 , V_100 ) ;
if ( ! V_101 )
return;
V_96 = F_41 ( * V_93 ) ;
V_100 = F_41 ( * V_97 ) ;
if ( V_96 + V_100 < V_101 ) {
unsigned int V_102 = F_42 ( V_95 ^ ( V_94 - 1 ) ) ;
unsigned int V_103 = F_42 ( V_99 ^ ( V_98 - 1 ) ) ;
do {
if ( V_100 >= V_103 ||
( V_96 <= V_100 && V_96 < V_102 ) ) {
* V_93 = F_39 ( * V_93 , V_94 , V_95 , V_96 + 1 ) ;
V_96 = F_41 ( * V_93 ) ;
} else {
* V_97 = F_39 ( * V_97 , V_98 , V_99 , V_100 + 1 ) ;
V_100 = F_41 ( * V_97 ) ;
}
} while ( V_100 + V_96 < V_101 );
}
}
int F_43 ( T_2 V_104 , struct V_105 * V_68 )
{
static const struct V_106 {
T_4 V_107 ;
T_4 V_108 ;
const char * V_25 ;
} V_109 [] = {
{ 0 , 0 , L_3 } ,
{ 720 , 480 , L_4 } ,
{ 720 , 576 , L_5 } ,
{ 1280 , 720 , L_6 } ,
{ 1280 , 720 , L_7 } ,
{ 1280 , 720 , L_8 } ,
{ 1280 , 720 , L_9 } ,
{ 1280 , 720 , L_10 } ,
{ 1280 , 720 , L_11 } ,
{ 1920 , 1080 , L_12 } ,
{ 1920 , 1080 , L_13 } ,
{ 1920 , 1080 , L_14 } ,
{ 1920 , 1080 , L_15 } ,
{ 1920 , 1080 , L_16 } ,
{ 1920 , 1080 , L_17 } ,
{ 1920 , 1080 , L_18 } ,
{ 1920 , 1080 , L_19 } ,
{ 1920 , 1080 , L_20 } ,
{ 1920 , 1080 , L_21 } ,
} ;
if ( V_68 == NULL || V_104 >= F_44 ( V_109 ) )
return - V_8 ;
V_68 -> V_104 = V_104 ;
V_68 -> V_107 = V_109 [ V_104 ] . V_107 ;
V_68 -> V_108 = V_109 [ V_104 ] . V_108 ;
F_4 ( V_68 -> V_25 , V_109 [ V_104 ] . V_25 , sizeof( V_68 -> V_25 ) ) ;
return 0 ;
}
bool F_45 ( const struct V_110 * V_111 ,
const struct V_110 * V_112 ,
unsigned V_113 )
{
if ( V_111 -> type != V_112 -> type || V_111 -> type != V_114 )
return false ;
if ( V_111 -> V_115 . V_107 == V_112 -> V_115 . V_107 &&
V_111 -> V_115 . V_108 == V_112 -> V_115 . V_108 &&
V_111 -> V_115 . V_116 == V_112 -> V_115 . V_116 &&
V_111 -> V_115 . V_117 == V_112 -> V_115 . V_117 &&
V_111 -> V_115 . V_118 >= V_112 -> V_115 . V_118 - V_113 &&
V_111 -> V_115 . V_118 <= V_112 -> V_115 . V_118 + V_113 &&
V_111 -> V_115 . V_119 == V_112 -> V_115 . V_119 &&
V_111 -> V_115 . V_120 == V_112 -> V_115 . V_120 &&
V_111 -> V_115 . V_121 == V_112 -> V_115 . V_121 &&
V_111 -> V_115 . V_122 == V_112 -> V_115 . V_122 &&
( ! V_111 -> V_115 . V_116 ||
( V_111 -> V_115 . V_123 == V_112 -> V_115 . V_123 &&
V_111 -> V_115 . V_124 == V_112 -> V_115 . V_124 &&
V_111 -> V_115 . V_125 == V_112 -> V_115 . V_125 ) ) )
return true ;
return false ;
}
bool F_46 ( unsigned V_126 , unsigned V_127 , unsigned V_121 ,
T_2 V_117 , struct V_110 * V_128 )
{
int V_129 , V_130 , V_131 , V_132 , V_133 ;
int V_134 , V_135 , V_136 ;
bool V_137 ;
unsigned V_138 ;
if ( V_121 < 4 || V_121 > 7 )
return false ;
if ( V_117 == V_139 )
V_137 = false ;
else if ( V_117 == V_140 )
V_137 = true ;
else
return false ;
if ( V_137 ) {
V_129 = V_141 ;
V_130 = ( V_142 * V_127 + 999999 ) / 1000000 ;
V_130 -= V_121 + V_129 ;
if ( V_130 < V_143 )
V_130 = V_143 ;
} else {
V_129 = V_144 ;
V_130 = ( V_145 * V_127 + 999999 ) / 1000000 - V_121 ;
if ( V_130 < V_146 )
V_130 = V_146 ;
}
V_135 = ( V_126 - V_129 - V_121 - V_130 + 1 ) & ~ 0x1 ;
switch ( V_121 ) {
case 4 :
V_136 = ( V_135 * 4 ) / 3 ;
break;
case 5 :
V_136 = ( V_135 * 16 ) / 9 ;
break;
case 6 :
V_136 = ( V_135 * 16 ) / 10 ;
break;
case 7 :
if ( V_135 == 1024 )
V_136 = ( V_135 * 5 ) / 4 ;
else if ( V_135 == 768 )
V_136 = ( V_135 * 15 ) / 9 ;
else
return false ;
break;
default:
return false ;
}
V_136 = V_136 & ~ 7 ;
if ( V_137 ) {
V_138 = ( V_136 + V_147 ) * V_127 ;
V_138 = ( V_138 / V_148 ) * V_148 ;
V_132 = V_149 ;
V_133 = V_150 ;
V_131 = V_147 - V_132 - V_133 ;
V_134 = V_136 + V_147 ;
} else {
int V_151 ;
unsigned V_152 = V_153 - ( V_154 * 1000 ) / V_127 ;
V_151 = ( V_136 * V_152 + ( 100 - V_152 ) / 2 ) /
( 100 - V_152 ) ;
V_151 = V_151 - V_151 % ( 2 * V_155 ) ;
if ( V_151 * 100 / V_136 < 20 ) {
V_151 = V_136 / 5 ;
V_151 = ( V_151 + 0x7 ) & ~ 0x7 ;
}
V_138 = ( V_136 + V_151 ) * V_127 ;
V_138 = ( V_138 / V_148 ) * V_148 ;
V_132 = V_151 / 2 ;
V_134 = V_136 + V_151 ;
V_133 = ( V_134 * 8 + 50 ) / 100 ;
V_133 = V_133 - V_133 % V_155 ;
V_131 = V_151 - V_133 - V_132 ;
}
V_128 -> V_115 . V_117 = V_117 ;
V_128 -> V_115 . V_107 = V_136 ;
V_128 -> V_115 . V_108 = V_135 ;
V_128 -> V_115 . V_119 = V_131 ;
V_128 -> V_115 . V_120 = V_129 ;
V_128 -> V_115 . V_133 = V_133 ;
V_128 -> V_115 . V_121 = V_121 ;
V_128 -> V_115 . V_156 = V_134 - V_136 - V_131 - V_133 ;
V_128 -> V_115 . V_122 = V_126 - V_135 - V_129 - V_121 ;
V_128 -> V_115 . V_118 = V_138 ;
V_128 -> V_115 . V_157 = V_158 ;
if ( V_137 )
V_128 -> V_115 . V_6 |= V_159 ;
return true ;
}
bool F_47 ( unsigned V_126 ,
unsigned V_127 ,
unsigned V_121 ,
T_2 V_117 ,
struct V_160 V_161 ,
struct V_110 * V_128 )
{
int V_138 ;
int V_129 , V_130 , V_131 , V_133 ;
int V_134 , V_135 , V_136 ;
bool V_162 ;
int V_151 ;
if ( V_121 != 3 )
return false ;
if ( V_117 == V_139 )
V_162 = true ;
else if ( V_117 == V_140 )
V_162 = false ;
else
return false ;
V_129 = V_163 ;
V_130 = ( V_164 * V_127 + 999999 ) / 1000000 - V_121 ;
V_135 = ( V_126 - V_129 - V_121 - V_130 + 1 ) & ~ 0x1 ;
if ( V_161 . V_165 == 0 || V_161 . V_166 == 0 ) {
V_161 . V_165 = 16 ;
V_161 . V_166 = 9 ;
}
V_136 = ( ( V_135 * V_161 . V_165 ) / V_161 . V_166 ) ;
if ( V_162 )
V_151 = ( ( V_136 * V_167 * V_127 ) -
( V_136 * V_168 * 1000 ) +
( V_127 * ( 100 - V_167 ) + V_168 * 1000 ) / 2 ) /
( V_127 * ( 100 - V_167 ) + V_168 * 1000 ) ;
else
V_151 = ( ( V_136 * V_169 * V_127 ) -
( V_136 * V_170 * 1000 ) +
( V_127 * ( 100 - V_169 ) + V_170 * 1000 ) / 2 ) /
( V_127 * ( 100 - V_169 ) + V_170 * 1000 ) ;
V_151 = V_151 - V_151 % ( 2 * V_171 ) ;
V_134 = V_136 + V_151 ;
V_138 = ( V_136 + V_151 ) * V_127 ;
V_138 = V_138 / V_172 * V_172 ;
V_133 = ( V_134 * 8 + 50 ) / 100 ;
V_133 = V_133 - V_133 % V_171 ;
V_131 = V_151 / 2 - V_133 ;
V_128 -> V_115 . V_117 = V_117 ;
V_128 -> V_115 . V_107 = V_136 ;
V_128 -> V_115 . V_108 = V_135 ;
V_128 -> V_115 . V_119 = V_131 ;
V_128 -> V_115 . V_120 = V_129 ;
V_128 -> V_115 . V_133 = V_133 ;
V_128 -> V_115 . V_121 = V_121 ;
V_128 -> V_115 . V_156 = V_134 - V_136 - V_131 - V_133 ;
V_128 -> V_115 . V_122 = V_126 - V_135 - V_129 - V_121 ;
V_128 -> V_115 . V_118 = V_138 ;
V_128 -> V_115 . V_157 = V_173 ;
if ( ! V_162 )
V_128 -> V_115 . V_6 |= V_159 ;
return true ;
}
struct V_160 F_48 ( T_3 V_174 , T_3 V_175 )
{
struct V_160 V_161 = { 16 , 9 } ;
T_2 V_176 ;
T_3 V_177 ;
if ( ! V_174 && ! V_175 )
return V_161 ;
if ( V_174 && V_175 ) {
V_161 . V_165 = V_174 ;
V_161 . V_166 = V_175 ;
return V_161 ;
}
V_177 = V_174 | V_175 ;
if ( V_177 == 79 ) {
V_161 . V_165 = 16 ;
V_161 . V_166 = 9 ;
} else if ( V_177 == 34 ) {
V_161 . V_165 = 4 ;
V_161 . V_165 = 3 ;
} else if ( V_177 == 68 ) {
V_161 . V_165 = 15 ;
V_161 . V_165 = 9 ;
} else {
V_161 . V_165 = V_174 + 99 ;
V_161 . V_166 = 100 ;
}
if ( V_174 )
return V_161 ;
V_176 = V_161 . V_166 ;
V_161 . V_166 = V_161 . V_165 ;
V_161 . V_165 = V_176 ;
return V_161 ;
}
const struct V_178 * F_49 (
const struct V_179 * V_180 ,
T_1 V_107 , T_1 V_108 )
{
int V_31 ;
T_2 error , V_181 = V_182 ;
const struct V_178 * V_183 , * V_184 = NULL ;
if ( ! V_180 )
return V_184 ;
for ( V_31 = 0 , V_183 = V_180 -> V_185 ; V_31 < V_180 -> V_186 ; V_31 ++ , V_183 ++ ) {
error = abs ( V_183 -> V_107 - V_107 ) + abs ( V_183 -> V_108 - V_108 ) ;
if ( error < V_181 ) {
V_181 = error ;
V_184 = V_183 ;
}
if ( ! error )
break;
}
return V_184 ;
}
void F_50 ( struct V_187 * V_188 )
{
struct V_189 V_190 ;
F_51 ( & V_190 ) ;
V_188 -> V_191 = V_190 . V_191 ;
V_188 -> V_192 = V_190 . V_193 / V_194 ;
}
