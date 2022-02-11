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
void F_10 ( struct V_40 * V_41 , struct V_42 * V_43 ,
const struct V_44 * V_45 )
{
F_11 ( V_41 , V_45 ) ;
V_41 -> V_6 |= V_46 ;
V_41 -> V_47 = V_43 -> V_48 -> V_48 . V_47 ;
V_41 -> V_49 = & V_43 -> V_49 ;
F_12 ( V_41 , V_43 ) ;
F_13 ( V_43 , V_41 ) ;
snprintf ( V_41 -> V_25 , sizeof( V_41 -> V_25 ) , L_1 ,
V_43 -> V_48 -> V_48 . V_25 , F_14 ( V_43 -> V_50 ) ,
V_43 -> V_51 ) ;
}
struct V_40 * F_15 ( struct V_52 * V_53 ,
struct V_54 * V_50 , struct V_55 * V_56 ,
const unsigned short * V_57 )
{
struct V_40 * V_41 = NULL ;
struct V_42 * V_43 ;
F_16 ( ! V_53 ) ;
F_17 ( V_58 L_2 , V_56 -> type ) ;
if ( V_56 -> V_51 == 0 && V_57 )
V_43 = F_18 ( V_50 , V_56 , V_57 ,
NULL ) ;
else
V_43 = F_19 ( V_50 , V_56 ) ;
if ( V_43 == NULL || V_43 -> V_48 == NULL )
goto error;
if ( ! F_20 ( V_43 -> V_48 -> V_48 . V_47 ) )
goto error;
V_41 = F_21 ( V_43 ) ;
if ( F_22 ( V_53 , V_41 ) )
V_41 = NULL ;
F_23 ( V_43 -> V_48 -> V_48 . V_47 ) ;
error:
if ( V_43 && V_41 == NULL )
F_24 ( V_43 ) ;
return V_41 ;
}
struct V_40 * F_25 ( struct V_52 * V_53 ,
struct V_54 * V_50 , const char * V_59 ,
T_3 V_51 , const unsigned short * V_57 )
{
struct V_55 V_56 ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
F_4 ( V_56 . type , V_59 , sizeof( V_56 . type ) ) ;
V_56 . V_51 = V_51 ;
return F_15 ( V_53 , V_50 , & V_56 , V_57 ) ;
}
unsigned short F_26 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = F_27 ( V_41 ) ;
return V_43 ? V_43 -> V_51 : V_60 ;
}
const unsigned short * F_28 ( enum V_61 type )
{
static const unsigned short V_62 [] = {
#if F_29 ( V_63 )
0x10 ,
#endif
0x60 ,
V_60
} ;
static const unsigned short V_64 [] = {
0x42 , 0x43 , 0x4a , 0x4b ,
V_60
} ;
static const unsigned short V_65 [] = {
0x42 , 0x43 , 0x4a , 0x4b ,
0x60 , 0x61 , 0x62 , 0x63 , 0x64 ,
V_60
} ;
switch ( type ) {
case V_66 :
return V_62 ;
case V_67 :
return V_64 ;
case V_68 :
return V_65 ;
case V_69 :
return V_65 + 4 ;
}
return NULL ;
}
void F_30 ( struct V_40 * V_41 , struct V_70 * V_71 ,
const struct V_44 * V_45 )
{
F_11 ( V_41 , V_45 ) ;
V_41 -> V_6 |= V_72 ;
V_41 -> V_47 = V_71 -> V_49 . V_48 -> V_47 ;
V_41 -> V_49 = & V_71 -> V_49 ;
F_12 ( V_41 , V_71 ) ;
F_31 ( V_71 , V_41 ) ;
F_4 ( V_41 -> V_25 , V_71 -> V_49 . V_48 -> V_25 , sizeof( V_41 -> V_25 ) ) ;
}
struct V_40 * F_32 ( struct V_52 * V_53 ,
struct V_73 * V_74 , struct V_75 * V_56 )
{
struct V_40 * V_41 = NULL ;
struct V_70 * V_71 = NULL ;
F_16 ( ! V_53 ) ;
if ( V_56 -> V_76 [ 0 ] )
F_17 ( V_56 -> V_76 ) ;
V_71 = F_33 ( V_74 , V_56 ) ;
if ( V_71 == NULL || V_71 -> V_49 . V_48 == NULL )
goto error;
if ( ! F_20 ( V_71 -> V_49 . V_48 -> V_47 ) )
goto error;
V_41 = F_34 ( V_71 ) ;
if ( F_22 ( V_53 , V_41 ) )
V_41 = NULL ;
F_23 ( V_71 -> V_49 . V_48 -> V_47 ) ;
error:
if ( V_71 && V_41 == NULL )
F_35 ( V_71 ) ;
return V_41 ;
}
static unsigned int F_36 ( unsigned int V_77 , unsigned int V_21 ,
unsigned int V_22 , unsigned int V_78 )
{
unsigned int V_79 = ~ ( ( 1 << V_78 ) - 1 ) ;
if ( V_78 )
V_77 = ( V_77 + ( 1 << ( V_78 - 1 ) ) ) & V_79 ;
if ( V_77 < V_21 )
V_77 = ( V_21 + ~ V_79 ) & V_79 ;
else if ( V_77 > V_22 )
V_77 = V_22 & V_79 ;
return V_77 ;
}
void F_37 ( T_2 * V_80 , unsigned int V_81 , unsigned int V_82 ,
unsigned int V_83 ,
T_2 * V_84 , unsigned int V_85 , unsigned int V_86 ,
unsigned int V_87 , unsigned int V_88 )
{
* V_80 = F_36 ( * V_80 , V_81 , V_82 , V_83 ) ;
* V_84 = F_36 ( * V_84 , V_85 , V_86 , V_87 ) ;
if ( ! V_88 )
return;
V_83 = F_38 ( * V_80 ) ;
V_87 = F_38 ( * V_84 ) ;
if ( V_83 + V_87 < V_88 ) {
unsigned int V_89 = F_39 ( V_82 ^ ( V_81 - 1 ) ) ;
unsigned int V_90 = F_39 ( V_86 ^ ( V_85 - 1 ) ) ;
do {
if ( V_87 >= V_90 ||
( V_83 <= V_87 && V_83 < V_89 ) ) {
* V_80 = F_36 ( * V_80 , V_81 , V_82 , V_83 + 1 ) ;
V_83 = F_38 ( * V_80 ) ;
} else {
* V_84 = F_36 ( * V_84 , V_85 , V_86 , V_87 + 1 ) ;
V_87 = F_38 ( * V_84 ) ;
}
} while ( V_87 + V_83 < V_88 );
}
}
bool F_40 ( const struct V_91 * V_92 ,
const struct V_91 * V_93 ,
unsigned V_94 )
{
if ( V_92 -> type != V_93 -> type || V_92 -> type != V_95 )
return false ;
if ( V_92 -> V_96 . V_97 == V_93 -> V_96 . V_97 &&
V_92 -> V_96 . V_98 == V_93 -> V_96 . V_98 &&
V_92 -> V_96 . V_99 == V_93 -> V_96 . V_99 &&
V_92 -> V_96 . V_100 == V_93 -> V_96 . V_100 &&
V_92 -> V_96 . V_101 >= V_93 -> V_96 . V_101 - V_94 &&
V_92 -> V_96 . V_101 <= V_93 -> V_96 . V_101 + V_94 &&
V_92 -> V_96 . V_102 == V_93 -> V_96 . V_102 &&
V_92 -> V_96 . V_103 == V_93 -> V_96 . V_103 &&
V_92 -> V_96 . V_104 == V_93 -> V_96 . V_104 &&
V_92 -> V_96 . V_105 == V_93 -> V_96 . V_105 &&
( ! V_92 -> V_96 . V_99 ||
( V_92 -> V_96 . V_106 == V_93 -> V_96 . V_106 &&
V_92 -> V_96 . V_107 == V_93 -> V_96 . V_107 &&
V_92 -> V_96 . V_108 == V_93 -> V_96 . V_108 ) ) )
return true ;
return false ;
}
bool F_41 ( unsigned V_109 , unsigned V_110 , unsigned V_104 ,
T_2 V_100 , struct V_91 * V_111 )
{
int V_112 , V_113 , V_114 , V_115 , V_116 ;
int V_117 , V_118 , V_119 ;
bool V_120 ;
unsigned V_121 ;
if ( V_104 < 4 || V_104 > 7 )
return false ;
if ( V_100 == V_122 )
V_120 = false ;
else if ( V_100 == V_123 )
V_120 = true ;
else
return false ;
if ( V_120 ) {
V_112 = V_124 ;
V_113 = ( V_125 * V_110 + 999999 ) / 1000000 ;
V_113 -= V_104 + V_112 ;
if ( V_113 < V_126 )
V_113 = V_126 ;
} else {
V_112 = V_127 ;
V_113 = ( V_128 * V_110 + 999999 ) / 1000000 - V_104 ;
if ( V_113 < V_129 )
V_113 = V_129 ;
}
V_118 = ( V_109 - V_112 - V_104 - V_113 + 1 ) & ~ 0x1 ;
switch ( V_104 ) {
case 4 :
V_119 = ( V_118 * 4 ) / 3 ;
break;
case 5 :
V_119 = ( V_118 * 16 ) / 9 ;
break;
case 6 :
V_119 = ( V_118 * 16 ) / 10 ;
break;
case 7 :
if ( V_118 == 1024 )
V_119 = ( V_118 * 5 ) / 4 ;
else if ( V_118 == 768 )
V_119 = ( V_118 * 15 ) / 9 ;
else
return false ;
break;
default:
return false ;
}
V_119 = V_119 & ~ 7 ;
if ( V_120 ) {
V_121 = ( V_119 + V_130 ) * V_110 ;
V_121 = ( V_121 / V_131 ) * V_131 ;
V_115 = V_132 ;
V_116 = V_133 ;
V_114 = V_130 - V_115 - V_116 ;
V_117 = V_119 + V_130 ;
} else {
int V_134 ;
unsigned V_135 = V_136 - ( V_137 * 1000 ) / V_110 ;
V_134 = ( V_119 * V_135 + ( 100 - V_135 ) / 2 ) /
( 100 - V_135 ) ;
V_134 = V_134 - V_134 % ( 2 * V_138 ) ;
if ( V_134 * 100 / V_119 < 20 ) {
V_134 = V_119 / 5 ;
V_134 = ( V_134 + 0x7 ) & ~ 0x7 ;
}
V_121 = ( V_119 + V_134 ) * V_110 ;
V_121 = ( V_121 / V_131 ) * V_131 ;
V_115 = V_134 / 2 ;
V_117 = V_119 + V_134 ;
V_116 = ( V_117 * 8 + 50 ) / 100 ;
V_116 = V_116 - V_116 % V_138 ;
V_114 = V_134 - V_116 - V_115 ;
}
V_111 -> V_96 . V_100 = V_100 ;
V_111 -> V_96 . V_97 = V_119 ;
V_111 -> V_96 . V_98 = V_118 ;
V_111 -> V_96 . V_102 = V_114 ;
V_111 -> V_96 . V_103 = V_112 ;
V_111 -> V_96 . V_116 = V_116 ;
V_111 -> V_96 . V_104 = V_104 ;
V_111 -> V_96 . V_139 = V_117 - V_119 - V_114 - V_116 ;
V_111 -> V_96 . V_105 = V_109 - V_118 - V_112 - V_104 ;
V_111 -> V_96 . V_101 = V_121 ;
V_111 -> V_96 . V_140 = V_141 ;
if ( V_120 )
V_111 -> V_96 . V_6 |= V_142 ;
return true ;
}
bool F_42 ( unsigned V_109 ,
unsigned V_110 ,
unsigned V_104 ,
T_2 V_100 ,
struct V_143 V_144 ,
struct V_91 * V_111 )
{
int V_121 ;
int V_112 , V_113 , V_114 , V_116 ;
int V_117 , V_118 , V_119 ;
bool V_145 ;
int V_134 ;
if ( V_104 != 3 )
return false ;
if ( V_100 == V_122 )
V_145 = true ;
else if ( V_100 == V_123 )
V_145 = false ;
else
return false ;
V_112 = V_146 ;
V_113 = ( V_147 * V_110 + 999999 ) / 1000000 - V_104 ;
V_118 = ( V_109 - V_112 - V_104 - V_113 + 1 ) & ~ 0x1 ;
if ( V_144 . V_148 == 0 || V_144 . V_149 == 0 ) {
V_144 . V_148 = 16 ;
V_144 . V_149 = 9 ;
}
V_119 = ( ( V_118 * V_144 . V_148 ) / V_144 . V_149 ) ;
if ( V_145 )
V_134 = ( ( V_119 * V_150 * V_110 ) -
( V_119 * V_151 * 1000 ) +
( V_110 * ( 100 - V_150 ) + V_151 * 1000 ) / 2 ) /
( V_110 * ( 100 - V_150 ) + V_151 * 1000 ) ;
else
V_134 = ( ( V_119 * V_152 * V_110 ) -
( V_119 * V_153 * 1000 ) +
( V_110 * ( 100 - V_152 ) + V_153 * 1000 ) / 2 ) /
( V_110 * ( 100 - V_152 ) + V_153 * 1000 ) ;
V_134 = V_134 - V_134 % ( 2 * V_154 ) ;
V_117 = V_119 + V_134 ;
V_121 = ( V_119 + V_134 ) * V_110 ;
V_121 = V_121 / V_155 * V_155 ;
V_116 = ( V_117 * 8 + 50 ) / 100 ;
V_116 = V_116 - V_116 % V_154 ;
V_114 = V_134 / 2 - V_116 ;
V_111 -> V_96 . V_100 = V_100 ;
V_111 -> V_96 . V_97 = V_119 ;
V_111 -> V_96 . V_98 = V_118 ;
V_111 -> V_96 . V_102 = V_114 ;
V_111 -> V_96 . V_103 = V_112 ;
V_111 -> V_96 . V_116 = V_116 ;
V_111 -> V_96 . V_104 = V_104 ;
V_111 -> V_96 . V_139 = V_117 - V_119 - V_114 - V_116 ;
V_111 -> V_96 . V_105 = V_109 - V_118 - V_112 - V_104 ;
V_111 -> V_96 . V_101 = V_121 ;
V_111 -> V_96 . V_140 = V_156 ;
if ( ! V_145 )
V_111 -> V_96 . V_6 |= V_142 ;
return true ;
}
struct V_143 F_43 ( T_3 V_157 , T_3 V_158 )
{
struct V_143 V_144 = { 16 , 9 } ;
T_2 V_159 ;
T_3 V_160 ;
if ( ! V_157 && ! V_158 )
return V_144 ;
if ( V_157 && V_158 ) {
V_144 . V_148 = V_157 ;
V_144 . V_149 = V_158 ;
return V_144 ;
}
V_160 = V_157 | V_158 ;
if ( V_160 == 79 ) {
V_144 . V_148 = 16 ;
V_144 . V_149 = 9 ;
} else if ( V_160 == 34 ) {
V_144 . V_148 = 4 ;
V_144 . V_148 = 3 ;
} else if ( V_160 == 68 ) {
V_144 . V_148 = 15 ;
V_144 . V_148 = 9 ;
} else {
V_144 . V_148 = V_157 + 99 ;
V_144 . V_149 = 100 ;
}
if ( V_157 )
return V_144 ;
V_159 = V_144 . V_149 ;
V_144 . V_149 = V_144 . V_148 ;
V_144 . V_148 = V_159 ;
return V_144 ;
}
const struct V_161 * F_44 (
const struct V_162 * V_163 ,
T_1 V_97 , T_1 V_98 )
{
int V_31 ;
T_2 error , V_164 = V_165 ;
const struct V_161 * V_166 , * V_167 = NULL ;
if ( ! V_163 )
return V_167 ;
for ( V_31 = 0 , V_166 = V_163 -> V_168 ; V_31 < V_163 -> V_169 ; V_31 ++ , V_166 ++ ) {
error = abs ( V_166 -> V_97 - V_97 ) + abs ( V_166 -> V_98 - V_98 ) ;
if ( error < V_164 ) {
V_164 = error ;
V_167 = V_166 ;
}
if ( ! error )
break;
}
return V_167 ;
}
void F_45 ( struct V_170 * V_171 )
{
struct V_172 V_173 ;
F_46 ( & V_173 ) ;
V_171 -> V_174 = V_173 . V_174 ;
V_171 -> V_175 = V_173 . V_176 / V_177 ;
}
