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
return V_46 && ! strncmp ( V_45 -> V_48 -> V_48 . V_25 , V_41 -> V_25 , V_46 ) ;
case V_49 :
return V_45 -> V_43 == V_41 -> V_43 ;
case V_50 :
return 1 ;
default:
return 0 ;
}
}
int F_12 ( struct V_44 * V_45 , struct V_51 * V_52 ,
T_2 V_53 , T_2 V_54 )
{
if ( ! F_11 ( V_45 , & V_52 -> V_41 ) )
return 0 ;
if ( V_52 -> V_53 == V_55 ) {
V_52 -> V_53 = V_53 ;
V_52 -> V_54 = V_54 ;
}
else {
V_52 -> V_53 = V_56 ;
V_52 -> V_54 = 0 ;
}
return 0 ;
}
void F_13 ( struct V_57 * V_58 , struct V_44 * V_59 ,
const struct V_60 * V_61 )
{
F_14 ( V_58 , V_61 ) ;
V_58 -> V_6 |= V_62 ;
V_58 -> V_63 = V_59 -> V_48 -> V_48 . V_63 ;
F_15 ( V_58 , V_59 ) ;
F_16 ( V_59 , V_58 ) ;
snprintf ( V_58 -> V_25 , sizeof( V_58 -> V_25 ) , L_1 ,
V_59 -> V_48 -> V_48 . V_25 , F_17 ( V_59 -> V_64 ) ,
V_59 -> V_43 ) ;
}
struct V_57 * F_18 ( struct V_65 * V_66 ,
struct V_67 * V_64 , struct V_68 * V_69 ,
const unsigned short * V_70 )
{
struct V_57 * V_58 = NULL ;
struct V_44 * V_59 ;
F_19 ( ! V_66 ) ;
F_20 ( V_71 L_2 , V_69 -> type ) ;
if ( V_69 -> V_43 == 0 && V_70 )
V_59 = F_21 ( V_64 , V_69 , V_70 ,
NULL ) ;
else
V_59 = F_22 ( V_64 , V_69 ) ;
if ( V_59 == NULL || V_59 -> V_48 == NULL )
goto error;
if ( ! F_23 ( V_59 -> V_48 -> V_48 . V_63 ) )
goto error;
V_58 = F_24 ( V_59 ) ;
if ( F_25 ( V_66 , V_58 ) )
V_58 = NULL ;
F_26 ( V_59 -> V_48 -> V_48 . V_63 ) ;
error:
if ( V_59 && V_58 == NULL )
F_27 ( V_59 ) ;
return V_58 ;
}
struct V_57 * F_28 ( struct V_65 * V_66 ,
struct V_67 * V_64 , const char * V_72 ,
T_3 V_43 , const unsigned short * V_70 )
{
struct V_68 V_69 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
F_4 ( V_69 . type , V_72 , sizeof( V_69 . type ) ) ;
V_69 . V_43 = V_43 ;
return F_18 ( V_66 , V_64 , & V_69 , V_70 ) ;
}
unsigned short F_29 ( struct V_57 * V_58 )
{
struct V_44 * V_59 = F_30 ( V_58 ) ;
return V_59 ? V_59 -> V_43 : V_73 ;
}
const unsigned short * F_31 ( enum V_74 type )
{
static const unsigned short V_75 [] = {
#if F_32 ( V_76 )
0x10 ,
#endif
0x60 ,
V_73
} ;
static const unsigned short V_77 [] = {
0x42 , 0x43 , 0x4a , 0x4b ,
V_73
} ;
static const unsigned short V_78 [] = {
0x42 , 0x43 , 0x4a , 0x4b ,
0x60 , 0x61 , 0x62 , 0x63 , 0x64 ,
V_73
} ;
switch ( type ) {
case V_79 :
return V_75 ;
case V_80 :
return V_77 ;
case V_81 :
return V_78 ;
case V_82 :
return V_78 + 4 ;
}
return NULL ;
}
void F_33 ( struct V_57 * V_58 , struct V_83 * V_84 ,
const struct V_60 * V_61 )
{
F_14 ( V_58 , V_61 ) ;
V_58 -> V_6 |= V_85 ;
V_58 -> V_63 = V_84 -> V_86 . V_48 -> V_63 ;
F_15 ( V_58 , V_84 ) ;
F_34 ( V_84 , V_58 ) ;
F_4 ( V_58 -> V_25 , V_84 -> V_86 . V_48 -> V_25 , sizeof( V_58 -> V_25 ) ) ;
}
struct V_57 * F_35 ( struct V_65 * V_66 ,
struct V_87 * V_88 , struct V_89 * V_69 )
{
struct V_57 * V_58 = NULL ;
struct V_83 * V_84 = NULL ;
F_19 ( ! V_66 ) ;
if ( V_69 -> V_90 [ 0 ] )
F_20 ( V_69 -> V_90 ) ;
V_84 = F_36 ( V_88 , V_69 ) ;
if ( V_84 == NULL || V_84 -> V_86 . V_48 == NULL )
goto error;
if ( ! F_23 ( V_84 -> V_86 . V_48 -> V_63 ) )
goto error;
V_58 = F_37 ( V_84 ) ;
if ( F_25 ( V_66 , V_58 ) )
V_58 = NULL ;
F_26 ( V_84 -> V_86 . V_48 -> V_63 ) ;
error:
if ( V_84 && V_58 == NULL )
F_38 ( V_84 ) ;
return V_58 ;
}
static unsigned int F_39 ( unsigned int V_91 , unsigned int V_21 ,
unsigned int V_22 , unsigned int V_92 )
{
unsigned int V_93 = ~ ( ( 1 << V_92 ) - 1 ) ;
if ( V_92 )
V_91 = ( V_91 + ( 1 << ( V_92 - 1 ) ) ) & V_93 ;
if ( V_91 < V_21 )
V_91 = ( V_21 + ~ V_93 ) & V_93 ;
else if ( V_91 > V_22 )
V_91 = V_22 & V_93 ;
return V_91 ;
}
void F_40 ( T_2 * V_94 , unsigned int V_95 , unsigned int V_96 ,
unsigned int V_97 ,
T_2 * V_98 , unsigned int V_99 , unsigned int V_100 ,
unsigned int V_101 , unsigned int V_102 )
{
* V_94 = F_39 ( * V_94 , V_95 , V_96 , V_97 ) ;
* V_98 = F_39 ( * V_98 , V_99 , V_100 , V_101 ) ;
if ( ! V_102 )
return;
V_97 = F_41 ( * V_94 ) ;
V_101 = F_41 ( * V_98 ) ;
if ( V_97 + V_101 < V_102 ) {
unsigned int V_103 = F_42 ( V_96 ^ ( V_95 - 1 ) ) ;
unsigned int V_104 = F_42 ( V_100 ^ ( V_99 - 1 ) ) ;
do {
if ( V_101 >= V_104 ||
( V_97 <= V_101 && V_97 < V_103 ) ) {
* V_94 = F_39 ( * V_94 , V_95 , V_96 , V_97 + 1 ) ;
V_97 = F_41 ( * V_94 ) ;
} else {
* V_98 = F_39 ( * V_98 , V_99 , V_100 , V_101 + 1 ) ;
V_101 = F_41 ( * V_98 ) ;
}
} while ( V_101 + V_97 < V_102 );
}
}
bool F_43 ( const struct V_105 * V_106 ,
const struct V_105 * V_107 ,
unsigned V_108 )
{
if ( V_106 -> type != V_107 -> type || V_106 -> type != V_109 )
return false ;
if ( V_106 -> V_110 . V_111 == V_107 -> V_110 . V_111 &&
V_106 -> V_110 . V_112 == V_107 -> V_110 . V_112 &&
V_106 -> V_110 . V_113 == V_107 -> V_110 . V_113 &&
V_106 -> V_110 . V_114 == V_107 -> V_110 . V_114 &&
V_106 -> V_110 . V_115 >= V_107 -> V_110 . V_115 - V_108 &&
V_106 -> V_110 . V_115 <= V_107 -> V_110 . V_115 + V_108 &&
V_106 -> V_110 . V_116 == V_107 -> V_110 . V_116 &&
V_106 -> V_110 . V_117 == V_107 -> V_110 . V_117 &&
V_106 -> V_110 . V_118 == V_107 -> V_110 . V_118 &&
V_106 -> V_110 . V_119 == V_107 -> V_110 . V_119 &&
( ! V_106 -> V_110 . V_113 ||
( V_106 -> V_110 . V_120 == V_107 -> V_110 . V_120 &&
V_106 -> V_110 . V_121 == V_107 -> V_110 . V_121 &&
V_106 -> V_110 . V_122 == V_107 -> V_110 . V_122 ) ) )
return true ;
return false ;
}
bool F_44 ( unsigned V_123 , unsigned V_124 , unsigned V_118 ,
T_2 V_114 , struct V_105 * V_125 )
{
int V_126 , V_127 , V_128 , V_129 , V_130 ;
int V_131 , V_132 , V_133 ;
bool V_134 ;
unsigned V_135 ;
if ( V_118 < 4 || V_118 > 7 )
return false ;
if ( V_114 == V_136 )
V_134 = false ;
else if ( V_114 == V_137 )
V_134 = true ;
else
return false ;
if ( V_134 ) {
V_126 = V_138 ;
V_127 = ( V_139 * V_124 + 999999 ) / 1000000 ;
V_127 -= V_118 + V_126 ;
if ( V_127 < V_140 )
V_127 = V_140 ;
} else {
V_126 = V_141 ;
V_127 = ( V_142 * V_124 + 999999 ) / 1000000 - V_118 ;
if ( V_127 < V_143 )
V_127 = V_143 ;
}
V_132 = ( V_123 - V_126 - V_118 - V_127 + 1 ) & ~ 0x1 ;
switch ( V_118 ) {
case 4 :
V_133 = ( V_132 * 4 ) / 3 ;
break;
case 5 :
V_133 = ( V_132 * 16 ) / 9 ;
break;
case 6 :
V_133 = ( V_132 * 16 ) / 10 ;
break;
case 7 :
if ( V_132 == 1024 )
V_133 = ( V_132 * 5 ) / 4 ;
else if ( V_132 == 768 )
V_133 = ( V_132 * 15 ) / 9 ;
else
return false ;
break;
default:
return false ;
}
V_133 = V_133 & ~ 7 ;
if ( V_134 ) {
V_135 = ( V_133 + V_144 ) * V_124 ;
V_135 = ( V_135 / V_145 ) * V_145 ;
V_129 = V_146 ;
V_130 = V_147 ;
V_128 = V_144 - V_129 - V_130 ;
V_131 = V_133 + V_144 ;
} else {
int V_148 ;
unsigned V_149 = V_150 - ( V_151 * 1000 ) / V_124 ;
V_148 = ( V_133 * V_149 + ( 100 - V_149 ) / 2 ) /
( 100 - V_149 ) ;
V_148 = V_148 - V_148 % ( 2 * V_152 ) ;
if ( V_148 * 100 / V_133 < 20 ) {
V_148 = V_133 / 5 ;
V_148 = ( V_148 + 0x7 ) & ~ 0x7 ;
}
V_135 = ( V_133 + V_148 ) * V_124 ;
V_135 = ( V_135 / V_145 ) * V_145 ;
V_129 = V_148 / 2 ;
V_131 = V_133 + V_148 ;
V_130 = ( V_131 * 8 + 50 ) / 100 ;
V_130 = V_130 - V_130 % V_152 ;
V_128 = V_148 - V_130 - V_129 ;
}
V_125 -> V_110 . V_114 = V_114 ;
V_125 -> V_110 . V_111 = V_133 ;
V_125 -> V_110 . V_112 = V_132 ;
V_125 -> V_110 . V_116 = V_128 ;
V_125 -> V_110 . V_117 = V_126 ;
V_125 -> V_110 . V_130 = V_130 ;
V_125 -> V_110 . V_118 = V_118 ;
V_125 -> V_110 . V_153 = V_131 - V_133 - V_128 - V_130 ;
V_125 -> V_110 . V_119 = V_123 - V_132 - V_126 - V_118 ;
V_125 -> V_110 . V_115 = V_135 ;
V_125 -> V_110 . V_154 = V_155 ;
if ( V_134 )
V_125 -> V_110 . V_6 |= V_156 ;
return true ;
}
bool F_45 ( unsigned V_123 ,
unsigned V_124 ,
unsigned V_118 ,
T_2 V_114 ,
struct V_157 V_158 ,
struct V_105 * V_125 )
{
int V_135 ;
int V_126 , V_127 , V_128 , V_130 ;
int V_131 , V_132 , V_133 ;
bool V_159 ;
int V_148 ;
if ( V_118 != 3 )
return false ;
if ( V_114 == V_136 )
V_159 = true ;
else if ( V_114 == V_137 )
V_159 = false ;
else
return false ;
V_126 = V_160 ;
V_127 = ( V_161 * V_124 + 999999 ) / 1000000 - V_118 ;
V_132 = ( V_123 - V_126 - V_118 - V_127 + 1 ) & ~ 0x1 ;
if ( V_158 . V_162 == 0 || V_158 . V_163 == 0 ) {
V_158 . V_162 = 16 ;
V_158 . V_163 = 9 ;
}
V_133 = ( ( V_132 * V_158 . V_162 ) / V_158 . V_163 ) ;
if ( V_159 )
V_148 = ( ( V_133 * V_164 * V_124 ) -
( V_133 * V_165 * 1000 ) +
( V_124 * ( 100 - V_164 ) + V_165 * 1000 ) / 2 ) /
( V_124 * ( 100 - V_164 ) + V_165 * 1000 ) ;
else
V_148 = ( ( V_133 * V_166 * V_124 ) -
( V_133 * V_167 * 1000 ) +
( V_124 * ( 100 - V_166 ) + V_167 * 1000 ) / 2 ) /
( V_124 * ( 100 - V_166 ) + V_167 * 1000 ) ;
V_148 = V_148 - V_148 % ( 2 * V_168 ) ;
V_131 = V_133 + V_148 ;
V_135 = ( V_133 + V_148 ) * V_124 ;
V_135 = V_135 / V_169 * V_169 ;
V_130 = ( V_131 * 8 + 50 ) / 100 ;
V_130 = V_130 - V_130 % V_168 ;
V_128 = V_148 / 2 - V_130 ;
V_125 -> V_110 . V_114 = V_114 ;
V_125 -> V_110 . V_111 = V_133 ;
V_125 -> V_110 . V_112 = V_132 ;
V_125 -> V_110 . V_116 = V_128 ;
V_125 -> V_110 . V_117 = V_126 ;
V_125 -> V_110 . V_130 = V_130 ;
V_125 -> V_110 . V_118 = V_118 ;
V_125 -> V_110 . V_153 = V_131 - V_133 - V_128 - V_130 ;
V_125 -> V_110 . V_119 = V_123 - V_132 - V_126 - V_118 ;
V_125 -> V_110 . V_115 = V_135 ;
V_125 -> V_110 . V_154 = V_170 ;
if ( ! V_159 )
V_125 -> V_110 . V_6 |= V_156 ;
return true ;
}
struct V_157 F_46 ( T_3 V_171 , T_3 V_172 )
{
struct V_157 V_158 = { 16 , 9 } ;
T_2 V_173 ;
T_3 V_174 ;
if ( ! V_171 && ! V_172 )
return V_158 ;
if ( V_171 && V_172 ) {
V_158 . V_162 = V_171 ;
V_158 . V_163 = V_172 ;
return V_158 ;
}
V_174 = V_171 | V_172 ;
if ( V_174 == 79 ) {
V_158 . V_162 = 16 ;
V_158 . V_163 = 9 ;
} else if ( V_174 == 34 ) {
V_158 . V_162 = 4 ;
V_158 . V_162 = 3 ;
} else if ( V_174 == 68 ) {
V_158 . V_162 = 15 ;
V_158 . V_162 = 9 ;
} else {
V_158 . V_162 = V_171 + 99 ;
V_158 . V_163 = 100 ;
}
if ( V_171 )
return V_158 ;
V_173 = V_158 . V_163 ;
V_158 . V_163 = V_158 . V_162 ;
V_158 . V_162 = V_173 ;
return V_158 ;
}
const struct V_175 * F_47 (
const struct V_176 * V_177 ,
T_1 V_111 , T_1 V_112 )
{
int V_31 ;
T_2 error , V_178 = V_179 ;
const struct V_175 * V_180 , * V_181 = NULL ;
if ( ! V_177 )
return V_181 ;
for ( V_31 = 0 , V_180 = V_177 -> V_182 ; V_31 < V_177 -> V_183 ; V_31 ++ , V_180 ++ ) {
error = abs ( V_180 -> V_111 - V_111 ) + abs ( V_180 -> V_112 - V_112 ) ;
if ( error < V_178 ) {
V_178 = error ;
V_181 = V_180 ;
}
if ( ! error )
break;
}
return V_181 ;
}
void F_48 ( struct V_184 * V_185 )
{
struct V_186 V_187 ;
F_49 ( & V_187 ) ;
V_185 -> V_188 = V_187 . V_188 ;
V_185 -> V_189 = V_187 . V_190 / V_191 ;
}
