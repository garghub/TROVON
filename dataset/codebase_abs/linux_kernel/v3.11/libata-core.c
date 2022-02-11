static bool F_1 ( T_1 V_1 )
{
return ( V_1 & 0xf ) == 0x3 ;
}
struct V_2 * F_2 ( struct V_2 * V_3 , struct V_4 * V_5 ,
enum V_6 V_7 )
{
F_3 ( V_7 != V_8 &&
V_7 != V_9 && V_7 != V_10 ) ;
if ( ! V_3 )
switch ( V_7 ) {
case V_8 :
case V_9 :
if ( F_4 ( V_5 ) )
return V_5 -> V_11 ;
case V_10 :
return & V_5 -> V_3 ;
}
if ( V_3 == & V_5 -> V_3 )
switch ( V_7 ) {
case V_10 :
if ( F_4 ( V_5 ) )
return V_5 -> V_11 ;
case V_9 :
if ( F_5 ( V_5 -> V_12 ) )
return V_5 -> V_12 ;
case V_8 :
return NULL ;
}
if ( F_5 ( V_3 == V_5 -> V_12 ) )
return NULL ;
if ( ++ V_3 < V_5 -> V_11 + V_5 -> V_13 )
return V_3 ;
if ( V_7 == V_9 )
return & V_5 -> V_3 ;
return NULL ;
}
struct V_14 * F_6 ( struct V_14 * V_15 , struct V_2 * V_3 ,
enum V_16 V_7 )
{
F_3 ( V_7 != V_17 && V_7 != V_18 &&
V_7 != V_19 && V_7 != V_20 ) ;
if ( ! V_15 )
switch ( V_7 ) {
case V_17 :
case V_19 :
V_15 = V_3 -> V_21 ;
goto V_22;
case V_18 :
case V_20 :
V_15 = V_3 -> V_21 + F_7 ( V_3 ) - 1 ;
goto V_22;
}
V_23:
switch ( V_7 ) {
case V_17 :
case V_19 :
if ( ++ V_15 < V_3 -> V_21 + F_7 ( V_3 ) )
goto V_22;
return NULL ;
case V_18 :
case V_20 :
if ( -- V_15 >= V_3 -> V_21 )
goto V_22;
return NULL ;
}
V_22:
if ( ( V_7 == V_17 || V_7 == V_18 ) &&
! F_8 ( V_15 ) )
goto V_23;
return V_15 ;
}
struct V_2 * F_9 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
if ( ! V_5 -> V_12 )
return V_15 -> V_3 ;
if ( ! V_15 -> V_24 )
return & V_5 -> V_3 ;
return V_5 -> V_12 ;
}
void F_10 ( struct V_4 * V_5 )
{
int V_25 ;
for ( V_25 = V_26 - 1 ; V_25 >= 0 ; V_25 -- ) {
const struct V_27 * V_28 = & V_29 [ V_25 ] ;
if ( V_28 -> V_30 != - 1 && V_28 -> V_30 != V_5 -> V_31 )
continue;
if ( V_28 -> V_32 . V_33 == V_34 )
continue;
V_5 -> V_33 = V_28 -> V_32 . V_33 ;
F_11 ( V_5 , L_1 , V_28 -> V_32 . V_35 ) ;
return;
}
}
static void F_12 ( struct V_2 * V_3 )
{
bool V_36 = false ;
int V_37 = V_3 -> V_38 ;
int V_25 ;
if ( F_13 ( V_3 ) )
V_37 += 15 ;
for ( V_25 = V_26 - 1 ; V_25 >= 0 ; V_25 -- ) {
const struct V_27 * V_28 = & V_29 [ V_25 ] ;
if ( V_28 -> V_30 != - 1 && V_28 -> V_30 != V_3 -> V_5 -> V_31 )
continue;
if ( V_28 -> V_21 != - 1 && V_28 -> V_21 != V_37 )
continue;
if ( ! V_36 && V_28 -> V_32 . V_39 ) {
V_3 -> V_40 = ( 1 << V_28 -> V_32 . V_39 ) - 1 ;
F_14 ( V_3 , L_2 ,
V_28 -> V_32 . V_35 ) ;
V_36 = true ;
}
if ( V_28 -> V_32 . V_41 ) {
V_3 -> V_42 |= V_28 -> V_32 . V_41 ;
F_14 ( V_3 ,
L_3 ,
V_28 -> V_32 . V_41 , V_3 -> V_42 ) ;
}
}
}
static void F_15 ( struct V_14 * V_15 )
{
int V_24 = V_15 -> V_3 -> V_38 + V_15 -> V_24 ;
int V_43 = V_24 ;
int V_25 ;
if ( F_13 ( V_15 -> V_3 ) )
V_43 += 15 ;
for ( V_25 = V_26 - 1 ; V_25 >= 0 ; V_25 -- ) {
const struct V_27 * V_28 = & V_29 [ V_25 ] ;
unsigned long V_44 , V_45 , V_46 ;
if ( V_28 -> V_30 != - 1 && V_28 -> V_30 != V_15 -> V_3 -> V_5 -> V_31 )
continue;
if ( V_28 -> V_21 != - 1 && V_28 -> V_21 != V_24 &&
V_28 -> V_21 != V_43 )
continue;
if ( ! V_28 -> V_32 . V_47 )
continue;
F_16 ( V_28 -> V_32 . V_47 ,
& V_44 , & V_45 , & V_46 ) ;
if ( V_46 )
V_15 -> V_46 = V_46 ;
else if ( V_45 ) {
V_15 -> V_46 = 0 ;
V_15 -> V_45 = V_45 ;
} else {
V_15 -> V_46 = 0 ;
V_15 -> V_45 = 0 ;
V_15 -> V_44 = V_44 ;
}
F_17 ( V_15 , L_4 ,
V_28 -> V_32 . V_35 ) ;
return;
}
}
static void F_18 ( struct V_14 * V_15 )
{
int V_24 = V_15 -> V_3 -> V_38 + V_15 -> V_24 ;
int V_43 = V_24 ;
int V_25 ;
if ( F_13 ( V_15 -> V_3 ) )
V_43 += 15 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
const struct V_27 * V_28 = & V_29 [ V_25 ] ;
if ( V_28 -> V_30 != - 1 && V_28 -> V_30 != V_15 -> V_3 -> V_5 -> V_31 )
continue;
if ( V_28 -> V_21 != - 1 && V_28 -> V_21 != V_24 &&
V_28 -> V_21 != V_43 )
continue;
if ( ! ( ~ V_15 -> V_48 & V_28 -> V_32 . V_49 ) &&
! ( V_15 -> V_48 & V_28 -> V_32 . V_50 ) )
continue;
V_15 -> V_48 |= V_28 -> V_32 . V_49 ;
V_15 -> V_48 &= ~ V_28 -> V_32 . V_50 ;
F_17 ( V_15 , L_5 ,
V_28 -> V_32 . V_35 ) ;
}
}
int F_19 ( T_2 V_51 )
{
switch ( V_51 ) {
case V_52 :
case V_53 :
return V_54 ;
case V_55 :
case V_56 :
case V_57 :
return V_58 ;
case V_59 :
case V_60 :
return V_61 ;
case V_62 :
case V_63 :
if ( V_64 )
return V_65 ;
default:
return V_66 ;
}
}
void F_20 ( const struct V_67 * V_68 , T_2 V_38 , int V_69 , T_2 * V_70 )
{
V_70 [ 0 ] = 0x27 ;
V_70 [ 1 ] = V_38 & 0xf ;
if ( V_69 )
V_70 [ 1 ] |= ( 1 << 7 ) ;
V_70 [ 2 ] = V_68 -> V_71 ;
V_70 [ 3 ] = V_68 -> V_72 ;
V_70 [ 4 ] = V_68 -> V_73 ;
V_70 [ 5 ] = V_68 -> V_74 ;
V_70 [ 6 ] = V_68 -> V_75 ;
V_70 [ 7 ] = V_68 -> V_21 ;
V_70 [ 8 ] = V_68 -> V_76 ;
V_70 [ 9 ] = V_68 -> V_77 ;
V_70 [ 10 ] = V_68 -> V_78 ;
V_70 [ 11 ] = V_68 -> V_79 ;
V_70 [ 12 ] = V_68 -> V_80 ;
V_70 [ 13 ] = V_68 -> V_81 ;
V_70 [ 14 ] = 0 ;
V_70 [ 15 ] = V_68 -> V_82 ;
V_70 [ 16 ] = 0 ;
V_70 [ 17 ] = 0 ;
V_70 [ 18 ] = 0 ;
V_70 [ 19 ] = 0 ;
}
void F_21 ( const T_2 * V_70 , struct V_67 * V_68 )
{
V_68 -> V_71 = V_70 [ 2 ] ;
V_68 -> V_72 = V_70 [ 3 ] ;
V_68 -> V_73 = V_70 [ 4 ] ;
V_68 -> V_74 = V_70 [ 5 ] ;
V_68 -> V_75 = V_70 [ 6 ] ;
V_68 -> V_21 = V_70 [ 7 ] ;
V_68 -> V_76 = V_70 [ 8 ] ;
V_68 -> V_77 = V_70 [ 9 ] ;
V_68 -> V_78 = V_70 [ 10 ] ;
V_68 -> V_80 = V_70 [ 12 ] ;
V_68 -> V_81 = V_70 [ 13 ] ;
}
static int F_22 ( struct V_67 * V_68 , struct V_14 * V_15 )
{
T_2 V_83 ;
int V_84 , V_85 , V_86 , V_87 ;
V_85 = ( V_68 -> V_42 & V_88 ) ? 4 : 0 ;
V_86 = ( V_68 -> V_42 & V_89 ) ? 2 : 0 ;
V_87 = ( V_68 -> V_42 & V_90 ) ? 1 : 0 ;
if ( V_15 -> V_42 & V_91 ) {
V_68 -> V_92 = V_93 ;
V_84 = V_15 -> V_94 ? 0 : 8 ;
} else if ( V_86 && ( V_15 -> V_3 -> V_5 -> V_42 & V_95 ) ) {
V_68 -> V_92 = V_93 ;
V_84 = V_15 -> V_94 ? 0 : 8 ;
} else {
V_68 -> V_92 = V_96 ;
V_84 = 16 ;
}
V_83 = V_97 [ V_84 + V_85 + V_86 + V_87 ] ;
if ( V_83 ) {
V_68 -> V_71 = V_83 ;
return 0 ;
}
return - 1 ;
}
T_3 F_23 ( struct V_67 * V_68 , struct V_14 * V_15 )
{
T_3 V_98 = 0 ;
if ( V_68 -> V_42 & V_99 ) {
if ( V_68 -> V_42 & V_89 ) {
V_98 |= ( T_3 ) V_68 -> V_78 << 40 ;
V_98 |= ( T_3 ) V_68 -> V_77 << 32 ;
V_98 |= ( T_3 ) V_68 -> V_76 << 24 ;
} else
V_98 |= ( V_68 -> V_21 & 0xf ) << 24 ;
V_98 |= V_68 -> V_75 << 16 ;
V_98 |= V_68 -> V_74 << 8 ;
V_98 |= V_68 -> V_73 ;
} else {
T_1 V_100 , V_101 , V_102 ;
V_100 = V_68 -> V_74 | ( V_68 -> V_75 << 8 ) ;
V_101 = V_68 -> V_21 & 0xf ;
V_102 = V_68 -> V_73 ;
if ( ! V_102 ) {
F_24 ( V_15 ,
L_6 ) ;
V_102 = 1 ;
}
V_98 = ( V_100 * V_15 -> V_103 + V_101 ) * V_15 -> V_104 + V_102 - 1 ;
}
return V_98 ;
}
int F_25 ( struct V_67 * V_68 , struct V_14 * V_15 ,
T_3 V_98 , T_1 V_105 , unsigned int V_106 ,
unsigned int V_107 )
{
V_68 -> V_42 |= V_108 | V_109 ;
V_68 -> V_42 |= V_106 ;
if ( F_26 ( V_15 ) && F_27 ( V_107 != V_110 ) ) {
if ( ! F_28 ( V_98 , V_105 ) )
return - V_111 ;
V_68 -> V_92 = V_112 ;
V_68 -> V_42 |= V_99 | V_89 ;
if ( V_68 -> V_42 & V_90 )
V_68 -> V_71 = V_113 ;
else
V_68 -> V_71 = V_114 ;
V_68 -> V_80 = V_107 << 3 ;
V_68 -> V_79 = ( V_105 >> 8 ) & 0xff ;
V_68 -> V_72 = V_105 & 0xff ;
V_68 -> V_78 = ( V_98 >> 40 ) & 0xff ;
V_68 -> V_77 = ( V_98 >> 32 ) & 0xff ;
V_68 -> V_76 = ( V_98 >> 24 ) & 0xff ;
V_68 -> V_75 = ( V_98 >> 16 ) & 0xff ;
V_68 -> V_74 = ( V_98 >> 8 ) & 0xff ;
V_68 -> V_73 = V_98 & 0xff ;
V_68 -> V_21 = V_115 ;
if ( V_68 -> V_42 & V_88 )
V_68 -> V_21 |= 1 << 7 ;
} else if ( V_15 -> V_42 & V_116 ) {
V_68 -> V_42 |= V_99 ;
if ( F_29 ( V_98 , V_105 ) ) {
V_68 -> V_21 |= ( V_98 >> 24 ) & 0xf ;
} else if ( F_28 ( V_98 , V_105 ) ) {
if ( ! ( V_15 -> V_42 & V_117 ) )
return - V_111 ;
V_68 -> V_42 |= V_89 ;
V_68 -> V_81 = ( V_105 >> 8 ) & 0xff ;
V_68 -> V_78 = ( V_98 >> 40 ) & 0xff ;
V_68 -> V_77 = ( V_98 >> 32 ) & 0xff ;
V_68 -> V_76 = ( V_98 >> 24 ) & 0xff ;
} else
return - V_111 ;
if ( F_5 ( F_22 ( V_68 , V_15 ) < 0 ) )
return - V_118 ;
V_68 -> V_80 = V_105 & 0xff ;
V_68 -> V_75 = ( V_98 >> 16 ) & 0xff ;
V_68 -> V_74 = ( V_98 >> 8 ) & 0xff ;
V_68 -> V_73 = V_98 & 0xff ;
V_68 -> V_21 |= V_115 ;
} else {
T_1 V_102 , V_101 , V_100 , V_119 ;
if ( ! F_29 ( V_98 , V_105 ) )
return - V_111 ;
if ( F_5 ( F_22 ( V_68 , V_15 ) < 0 ) )
return - V_118 ;
V_119 = ( T_1 ) V_98 / V_15 -> V_104 ;
V_100 = V_119 / V_15 -> V_103 ;
V_101 = V_119 % V_15 -> V_103 ;
V_102 = ( T_1 ) V_98 % V_15 -> V_104 + 1 ;
F_30 ( L_7 ,
( T_1 ) V_98 , V_119 , V_100 , V_101 , V_102 ) ;
if ( ( V_100 >> 16 ) || ( V_101 >> 4 ) || ( V_102 >> 8 ) || ( ! V_102 ) )
return - V_111 ;
V_68 -> V_80 = V_105 & 0xff ;
V_68 -> V_73 = V_102 ;
V_68 -> V_74 = V_100 ;
V_68 -> V_75 = V_100 >> 8 ;
V_68 -> V_21 |= V_101 ;
}
return 0 ;
}
unsigned long F_31 ( unsigned long V_44 ,
unsigned long V_45 ,
unsigned long V_46 )
{
return ( ( V_44 << V_120 ) & V_121 ) |
( ( V_45 << V_122 ) & V_123 ) |
( ( V_46 << V_124 ) & V_125 ) ;
}
void F_16 ( unsigned long V_47 , unsigned long * V_44 ,
unsigned long * V_45 , unsigned long * V_46 )
{
if ( V_44 )
* V_44 = ( V_47 & V_121 ) >> V_120 ;
if ( V_45 )
* V_45 = ( V_47 & V_123 ) >> V_122 ;
if ( V_46 )
* V_46 = ( V_47 & V_125 ) >> V_124 ;
}
T_2 F_32 ( unsigned long V_47 )
{
int V_126 = F_33 ( V_47 ) - 1 ;
const struct V_127 * V_128 ;
for ( V_128 = V_129 ; V_128 -> V_130 >= 0 ; V_128 ++ )
if ( V_126 >= V_128 -> V_130 && V_126 < V_128 -> V_130 + V_128 -> V_131 )
return V_128 -> V_132 + V_126 - V_128 -> V_130 ;
return 0xff ;
}
unsigned long F_34 ( T_2 V_133 )
{
const struct V_127 * V_128 ;
for ( V_128 = V_129 ; V_128 -> V_130 >= 0 ; V_128 ++ )
if ( V_133 >= V_128 -> V_132 && V_133 < V_128 -> V_132 + V_128 -> V_131 )
return ( ( 2 << ( V_128 -> V_130 + V_133 - V_128 -> V_132 ) ) - 1 )
& ~ ( ( 1 << V_128 -> V_130 ) - 1 ) ;
return 0 ;
}
int F_35 ( unsigned long V_133 )
{
const struct V_127 * V_128 ;
for ( V_128 = V_129 ; V_128 -> V_130 >= 0 ; V_128 ++ )
if ( V_133 >= V_128 -> V_132 && V_133 < V_128 -> V_132 + V_128 -> V_131 )
return V_128 -> V_130 ;
return - 1 ;
}
const char * F_36 ( unsigned long V_47 )
{
static const char * const V_134 [] = {
L_8 ,
L_9 ,
L_10 ,
L_11 ,
L_12 ,
L_13 ,
L_14 ,
L_15 ,
L_16 ,
L_17 ,
L_18 ,
L_19 ,
L_20 ,
L_21 ,
L_22 ,
L_23 ,
L_24 ,
L_25 ,
L_26 ,
L_27 ,
} ;
int V_126 ;
V_126 = F_33 ( V_47 ) - 1 ;
if ( V_126 >= 0 && V_126 < F_37 ( V_134 ) )
return V_134 [ V_126 ] ;
return L_28 ;
}
const char * F_38 ( unsigned int V_135 )
{
static const char * const V_136 [] = {
L_29 ,
L_30 ,
L_31 ,
} ;
if ( V_135 == 0 || ( V_135 - 1 ) >= F_37 ( V_136 ) )
return L_32 ;
return V_136 [ V_135 - 1 ] ;
}
unsigned int F_39 ( const struct V_67 * V_68 )
{
if ( ( V_68 -> V_74 == 0 ) && ( V_68 -> V_75 == 0 ) ) {
F_30 ( L_33 ) ;
return V_137 ;
}
if ( ( V_68 -> V_74 == 0x14 ) && ( V_68 -> V_75 == 0xeb ) ) {
F_30 ( L_34 ) ;
return V_138 ;
}
if ( ( V_68 -> V_74 == 0x69 ) && ( V_68 -> V_75 == 0x96 ) ) {
F_30 ( L_35 ) ;
return V_139 ;
}
if ( ( V_68 -> V_74 == 0x3c ) && ( V_68 -> V_75 == 0xc3 ) ) {
F_30 ( L_36 ) ;
return V_140 ;
}
F_30 ( L_37 ) ;
return V_141 ;
}
void F_40 ( const T_4 * V_142 , unsigned char * V_143 ,
unsigned int V_144 , unsigned int V_145 )
{
unsigned int V_146 ;
F_3 ( V_145 & 1 ) ;
while ( V_145 > 0 ) {
V_146 = V_142 [ V_144 ] >> 8 ;
* V_143 = V_146 ;
V_143 ++ ;
V_146 = V_142 [ V_144 ] & 0xff ;
* V_143 = V_146 ;
V_143 ++ ;
V_144 ++ ;
V_145 -= 2 ;
}
}
void F_41 ( const T_4 * V_142 , unsigned char * V_143 ,
unsigned int V_144 , unsigned int V_145 )
{
unsigned char * V_147 ;
F_40 ( V_142 , V_143 , V_144 , V_145 - 1 ) ;
V_147 = V_143 + F_42 ( V_143 , V_145 - 1 ) ;
while ( V_147 > V_143 && V_147 [ - 1 ] == ' ' )
V_147 -- ;
* V_147 = '\0' ;
}
static T_3 F_43 ( const T_4 * V_142 )
{
if ( F_44 ( V_142 ) ) {
if ( F_45 ( V_142 ) )
return F_46 ( V_142 , V_148 ) ;
else
return F_47 ( V_142 , V_149 ) ;
} else {
if ( F_48 ( V_142 ) )
return V_142 [ V_150 ] * V_142 [ V_151 ] *
V_142 [ V_152 ] ;
else
return V_142 [ V_153 ] * V_142 [ V_154 ] *
V_142 [ V_155 ] ;
}
}
T_3 F_49 ( const struct V_67 * V_68 )
{
T_3 V_104 = 0 ;
V_104 |= ( ( T_3 ) ( V_68 -> V_78 & 0xff ) ) << 40 ;
V_104 |= ( ( T_3 ) ( V_68 -> V_77 & 0xff ) ) << 32 ;
V_104 |= ( ( T_3 ) ( V_68 -> V_76 & 0xff ) ) << 24 ;
V_104 |= ( V_68 -> V_75 & 0xff ) << 16 ;
V_104 |= ( V_68 -> V_74 & 0xff ) << 8 ;
V_104 |= ( V_68 -> V_73 & 0xff ) ;
return V_104 ;
}
T_3 F_50 ( const struct V_67 * V_68 )
{
T_3 V_104 = 0 ;
V_104 |= ( V_68 -> V_21 & 0x0f ) << 24 ;
V_104 |= ( V_68 -> V_75 & 0xff ) << 16 ;
V_104 |= ( V_68 -> V_74 & 0xff ) << 8 ;
V_104 |= ( V_68 -> V_73 & 0xff ) ;
return V_104 ;
}
static int F_51 ( struct V_14 * V_15 , T_3 * V_156 )
{
unsigned int V_157 ;
struct V_67 V_68 ;
int V_86 = F_45 ( V_15 -> V_142 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_42 |= V_109 | V_108 ;
if ( V_86 ) {
V_68 . V_71 = V_158 ;
V_68 . V_42 |= V_89 ;
} else
V_68 . V_71 = V_159 ;
V_68 . V_92 |= V_160 ;
V_68 . V_21 |= V_115 ;
V_157 = F_53 ( V_15 , & V_68 , NULL , V_161 , NULL , 0 , 0 ) ;
if ( V_157 ) {
F_24 ( V_15 ,
L_38 ,
V_157 ) ;
if ( V_157 == V_162 && ( V_68 . V_72 & V_163 ) )
return - V_164 ;
return - V_165 ;
}
if ( V_86 )
* V_156 = F_49 ( & V_68 ) + 1 ;
else
* V_156 = F_50 ( & V_68 ) + 1 ;
if ( V_15 -> V_48 & V_166 )
( * V_156 ) -- ;
return 0 ;
}
static int F_54 ( struct V_14 * V_15 , T_3 V_167 )
{
unsigned int V_157 ;
struct V_67 V_68 ;
int V_86 = F_45 ( V_15 -> V_142 ) ;
V_167 -- ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_42 |= V_109 | V_108 ;
if ( V_86 ) {
V_68 . V_71 = V_168 ;
V_68 . V_42 |= V_89 ;
V_68 . V_76 = ( V_167 >> 24 ) & 0xff ;
V_68 . V_77 = ( V_167 >> 32 ) & 0xff ;
V_68 . V_78 = ( V_167 >> 40 ) & 0xff ;
} else {
V_68 . V_71 = V_169 ;
V_68 . V_21 |= ( V_167 >> 24 ) & 0xf ;
}
V_68 . V_92 |= V_160 ;
V_68 . V_21 |= V_115 ;
V_68 . V_73 = ( V_167 >> 0 ) & 0xff ;
V_68 . V_74 = ( V_167 >> 8 ) & 0xff ;
V_68 . V_75 = ( V_167 >> 16 ) & 0xff ;
V_157 = F_53 ( V_15 , & V_68 , NULL , V_161 , NULL , 0 , 0 ) ;
if ( V_157 ) {
F_24 ( V_15 ,
L_39 ,
V_157 ) ;
if ( V_157 == V_162 &&
( V_68 . V_72 & ( V_163 | V_170 ) ) )
return - V_164 ;
return - V_165 ;
}
return 0 ;
}
static int F_55 ( struct V_14 * V_15 )
{
struct V_171 * V_172 = & V_15 -> V_3 -> V_173 ;
int V_174 = V_172 -> V_25 . V_42 & V_175 ;
bool V_176 = V_177 || V_15 -> V_42 & V_178 ;
T_3 V_104 = F_43 ( V_15 -> V_142 ) ;
T_3 V_179 ;
int V_180 ;
if ( V_15 -> V_181 != V_137 ||
! F_44 ( V_15 -> V_142 ) || ! F_56 ( V_15 -> V_142 ) ||
( V_15 -> V_48 & V_182 ) )
return 0 ;
V_180 = F_51 ( V_15 , & V_179 ) ;
if ( V_180 ) {
if ( V_180 == - V_164 || ! V_176 ) {
F_24 ( V_15 ,
L_40 ) ;
V_15 -> V_48 |= V_182 ;
if ( V_180 == - V_164 )
V_180 = 0 ;
}
return V_180 ;
}
V_15 -> V_183 = V_179 ;
if ( V_179 <= V_104 || ! V_176 ) {
if ( ! V_174 || V_179 == V_104 )
return 0 ;
if ( V_179 > V_104 )
F_57 ( V_15 ,
L_41 ,
( unsigned long long ) V_104 ,
( unsigned long long ) V_179 ) ;
else if ( V_179 < V_104 )
F_24 ( V_15 ,
L_42 ,
( unsigned long long ) V_179 ,
( unsigned long long ) V_104 ) ;
return 0 ;
}
V_180 = F_54 ( V_15 , V_179 ) ;
if ( V_180 == - V_164 ) {
F_24 ( V_15 ,
L_43 ,
( unsigned long long ) V_104 ,
( unsigned long long ) V_179 ) ;
V_15 -> V_48 |= V_182 ;
return 0 ;
} else if ( V_180 )
return V_180 ;
V_180 = F_58 ( V_15 , 0 ) ;
if ( V_180 ) {
F_59 ( V_15 ,
L_44 ) ;
return V_180 ;
}
if ( V_174 ) {
T_3 V_167 = F_43 ( V_15 -> V_142 ) ;
F_57 ( V_15 ,
L_45 ,
( unsigned long long ) V_104 ,
( unsigned long long ) V_167 ,
( unsigned long long ) V_179 ) ;
}
return 0 ;
}
static inline void F_60 ( const T_4 * V_142 )
{
F_30 ( L_46
L_47
L_48
L_49
L_50 ,
V_142 [ 49 ] ,
V_142 [ 53 ] ,
V_142 [ 63 ] ,
V_142 [ 64 ] ,
V_142 [ 75 ] ) ;
F_30 ( L_51
L_52
L_53
L_54
L_55 ,
V_142 [ 80 ] ,
V_142 [ 81 ] ,
V_142 [ 82 ] ,
V_142 [ 83 ] ,
V_142 [ 84 ] ) ;
F_30 ( L_56
L_57 ,
V_142 [ 88 ] ,
V_142 [ 93 ] ) ;
}
unsigned long F_61 ( const T_4 * V_142 )
{
unsigned long V_44 , V_45 , V_46 ;
if ( V_142 [ V_184 ] & ( 1 << 1 ) ) {
V_44 = V_142 [ V_185 ] & 0x03 ;
V_44 <<= 3 ;
V_44 |= 0x7 ;
} else {
T_2 V_7 = ( V_142 [ V_186 ] >> 8 ) & 0xFF ;
if ( V_7 < 5 )
V_44 = ( 2 << V_7 ) - 1 ;
else
V_44 = 1 ;
}
V_45 = V_142 [ V_187 ] & 0x07 ;
if ( F_62 ( V_142 ) ) {
int V_188 = ( V_142 [ V_189 ] >> 0 ) & 0x7 ;
int V_190 = ( V_142 [ V_189 ] >> 3 ) & 0x7 ;
if ( V_188 )
V_44 |= ( 1 << 5 ) ;
if ( V_188 > 1 )
V_44 |= ( 1 << 6 ) ;
if ( V_190 )
V_45 |= ( 1 << 3 ) ;
if ( V_190 > 1 )
V_45 |= ( 1 << 4 ) ;
}
V_46 = 0 ;
if ( V_142 [ V_184 ] & ( 1 << 2 ) )
V_46 = V_142 [ V_191 ] & 0xff ;
return F_31 ( V_44 , V_45 , V_46 ) ;
}
static void F_63 ( struct V_192 * V_193 )
{
struct V_194 * V_195 = V_193 -> V_196 ;
F_64 ( V_195 ) ;
}
unsigned F_65 ( struct V_14 * V_15 ,
struct V_67 * V_68 , const T_2 * V_197 ,
int V_198 , struct V_199 * V_200 ,
unsigned int V_201 , unsigned long V_202 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
T_2 V_71 = V_68 -> V_71 ;
int V_203 = 0 ;
struct V_192 * V_193 ;
unsigned int V_107 , V_204 ;
T_1 V_205 , V_206 ;
int V_207 ;
F_66 ( V_208 ) ;
unsigned long V_42 ;
unsigned int V_157 ;
int V_180 ;
F_67 ( V_5 -> V_209 , V_42 ) ;
if ( V_5 -> V_210 & V_211 ) {
F_68 ( V_5 -> V_209 , V_42 ) ;
return V_212 ;
}
if ( V_5 -> V_213 -> V_214 )
V_107 = V_110 ;
else
V_107 = 0 ;
if ( F_69 ( V_107 , & V_5 -> V_215 ) )
F_70 () ;
V_193 = F_71 ( V_5 , V_107 ) ;
V_193 -> V_107 = V_107 ;
V_193 -> V_216 = NULL ;
V_193 -> V_5 = V_5 ;
V_193 -> V_15 = V_15 ;
F_72 ( V_193 ) ;
V_204 = V_3 -> V_217 ;
V_205 = V_3 -> V_218 ;
V_206 = V_5 -> V_219 ;
V_207 = V_5 -> V_220 ;
V_3 -> V_217 = V_221 ;
V_3 -> V_218 = 0 ;
V_5 -> V_219 = 0 ;
V_5 -> V_220 = 0 ;
V_193 -> V_68 = * V_68 ;
if ( V_197 )
memcpy ( V_193 -> V_197 , V_197 , V_222 ) ;
if ( V_68 -> V_92 == V_223 && ( V_15 -> V_42 & V_224 ) &&
V_198 == V_225 )
V_193 -> V_68 . V_72 |= V_226 ;
V_193 -> V_42 |= V_227 ;
V_193 -> V_198 = V_198 ;
if ( V_198 != V_161 ) {
unsigned int V_25 , V_228 = 0 ;
struct V_199 * V_229 ;
F_73 (sgl, sg, n_elem, i)
V_228 += V_229 -> V_230 ;
F_74 ( V_193 , V_200 , V_201 ) ;
V_193 -> V_231 = V_228 ;
}
V_193 -> V_196 = & V_208 ;
V_193 -> V_232 = F_63 ;
F_75 ( V_193 ) ;
F_68 ( V_5 -> V_209 , V_42 ) ;
if ( ! V_202 ) {
if ( V_233 )
V_202 = V_233 * 1000 ;
else {
V_202 = F_76 ( V_15 , V_71 ) ;
V_203 = 1 ;
}
}
if ( V_5 -> V_213 -> V_214 )
F_77 ( V_5 ) ;
V_180 = F_78 ( & V_208 , F_79 ( V_202 ) ) ;
if ( V_5 -> V_213 -> V_214 )
F_80 ( V_5 ) ;
F_81 ( V_5 ) ;
if ( ! V_180 ) {
F_67 ( V_5 -> V_209 , V_42 ) ;
if ( V_193 -> V_42 & V_234 ) {
V_193 -> V_157 |= V_235 ;
if ( V_5 -> V_213 -> V_214 )
F_82 ( V_5 ) ;
else
F_83 ( V_193 ) ;
if ( F_84 ( V_5 ) )
F_24 ( V_15 , L_58 ,
V_71 ) ;
}
F_68 ( V_5 -> V_209 , V_42 ) ;
}
if ( V_5 -> V_213 -> V_236 )
V_5 -> V_213 -> V_236 ( V_193 ) ;
if ( V_193 -> V_42 & V_237 ) {
if ( V_193 -> V_238 . V_71 & ( V_239 | V_240 ) )
V_193 -> V_157 |= V_162 ;
if ( ! V_193 -> V_157 )
V_193 -> V_157 |= V_241 ;
if ( V_193 -> V_157 & ~ V_241 )
V_193 -> V_157 &= ~ V_241 ;
}
F_67 ( V_5 -> V_209 , V_42 ) ;
* V_68 = V_193 -> V_238 ;
V_157 = V_193 -> V_157 ;
F_85 ( V_193 ) ;
V_3 -> V_217 = V_204 ;
V_3 -> V_218 = V_205 ;
V_5 -> V_219 = V_206 ;
V_5 -> V_220 = V_207 ;
F_68 ( V_5 -> V_209 , V_42 ) ;
if ( ( V_157 & V_235 ) && V_203 )
F_86 ( V_15 , V_71 ) ;
return V_157 ;
}
unsigned F_53 ( struct V_14 * V_15 ,
struct V_67 * V_68 , const T_2 * V_197 ,
int V_198 , void * V_242 , unsigned int V_228 ,
unsigned long V_202 )
{
struct V_199 * V_243 = NULL , V_229 ;
unsigned int V_201 = 0 ;
if ( V_198 != V_161 ) {
F_87 ( ! V_242 ) ;
F_88 ( & V_229 , V_242 , V_228 ) ;
V_243 = & V_229 ;
V_201 ++ ;
}
return F_65 ( V_15 , V_68 , V_197 , V_198 , V_243 , V_201 ,
V_202 ) ;
}
unsigned int F_89 ( struct V_14 * V_15 , T_2 V_83 )
{
struct V_67 V_68 ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_83 ;
V_68 . V_42 |= V_109 ;
V_68 . V_92 = V_160 ;
return F_53 ( V_15 , & V_68 , NULL , V_161 , NULL , 0 , 0 ) ;
}
unsigned int F_90 ( const struct V_14 * V_244 )
{
if ( V_244 -> V_3 -> V_5 -> V_210 & V_245 )
return 0 ;
if ( V_244 -> V_3 -> V_5 -> V_42 & V_246 )
return 0 ;
if ( F_62 ( V_244 -> V_142 )
&& ( V_244 -> V_247 == V_248 || V_244 -> V_247 == V_249 ) )
return 0 ;
if ( V_244 -> V_247 > V_250 )
return 1 ;
if ( F_91 ( V_244 -> V_142 ) )
return 1 ;
return 0 ;
}
static T_1 F_92 ( const struct V_14 * V_244 )
{
if ( V_244 -> V_142 [ V_184 ] & 2 ) {
T_4 V_188 = V_244 -> V_142 [ V_251 ] ;
if ( V_188 ) {
if ( V_188 > 240 )
return 3 << V_120 ;
return 7 << V_120 ;
}
}
return 3 << V_120 ;
}
unsigned int F_93 ( struct V_14 * V_15 ,
struct V_67 * V_68 , T_4 * V_142 )
{
return F_53 ( V_15 , V_68 , NULL , V_225 ,
V_142 , sizeof( V_142 [ 0 ] ) * V_252 , 0 ) ;
}
int F_94 ( struct V_14 * V_15 , unsigned int * V_253 ,
unsigned int V_42 , T_4 * V_142 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
unsigned int V_181 = * V_253 ;
struct V_67 V_68 ;
unsigned int V_157 = 0 ;
const char * V_254 ;
bool V_255 = V_181 == V_140 ;
int V_256 = 1 , V_257 = 0 ;
int V_180 ;
if ( F_95 ( V_5 ) )
F_96 ( V_15 , L_59 , V_258 ) ;
V_259:
F_52 ( V_15 , & V_68 ) ;
switch ( V_181 ) {
case V_140 :
V_181 = V_137 ;
case V_137 :
V_68 . V_71 = V_260 ;
break;
case V_138 :
V_68 . V_71 = V_261 ;
break;
default:
V_180 = - V_262 ;
V_254 = L_60 ;
goto V_263;
}
V_68 . V_92 = V_93 ;
V_68 . V_42 |= V_108 | V_109 ;
V_68 . V_42 |= V_264 ;
if ( V_5 -> V_213 -> V_265 )
V_157 = V_5 -> V_213 -> V_265 ( V_15 , & V_68 , V_142 ) ;
else
V_157 = F_93 ( V_15 , & V_68 , V_142 ) ;
if ( V_157 ) {
if ( V_157 & V_266 ) {
F_96 ( V_15 , L_61 ) ;
return - V_267 ;
}
if ( V_255 ) {
F_57 ( V_15 ,
L_62 ) ;
* V_253 = V_268 ;
return 0 ;
}
if ( ( V_157 == V_162 ) && ( V_68 . V_72 & V_163 ) ) {
if ( V_256 ) {
V_256 = 0 ;
if ( V_181 == V_137 )
V_181 = V_138 ;
else
V_181 = V_137 ;
goto V_259;
}
F_96 ( V_15 ,
L_63 ) ;
return - V_267 ;
}
V_180 = - V_165 ;
V_254 = L_64 ;
goto V_263;
}
if ( V_15 -> V_48 & V_269 ) {
F_96 ( V_15 , L_65
L_66 ,
V_181 , V_256 , V_257 ) ;
F_97 ( V_270 , L_67 , V_271 ,
16 , 2 , V_142 , V_252 * sizeof( * V_142 ) , true ) ;
}
V_256 = 0 ;
F_98 ( V_142 , V_252 ) ;
V_180 = - V_118 ;
V_254 = L_68 ;
if ( V_181 == V_137 ) {
if ( ! F_99 ( V_142 ) && ! F_62 ( V_142 ) )
goto V_263;
if ( V_5 -> V_272 -> V_42 & V_273 &&
F_99 ( V_142 ) ) {
F_96 ( V_15 ,
L_69 ) ;
return - V_267 ;
}
} else {
if ( F_99 ( V_142 ) )
goto V_263;
}
if ( ! V_257 && ( V_142 [ 2 ] == 0x37c8 || V_142 [ 2 ] == 0x738c ) ) {
V_257 = 1 ;
V_157 = F_100 ( V_15 , V_274 , 0 ) ;
if ( V_157 && V_142 [ 2 ] != 0x738c ) {
V_180 = - V_165 ;
V_254 = L_70 ;
goto V_263;
}
if ( V_142 [ 2 ] == 0x37c8 )
goto V_259;
}
if ( ( V_42 & V_275 ) && V_181 == V_137 ) {
if ( F_101 ( V_142 ) < 4 || ! F_44 ( V_142 ) ) {
V_157 = F_102 ( V_15 , V_142 [ 3 ] , V_142 [ 6 ] ) ;
if ( V_157 ) {
V_180 = - V_165 ;
V_254 = L_71 ;
goto V_263;
}
V_42 &= ~ V_275 ;
goto V_259;
}
}
* V_253 = V_181 ;
return 0 ;
V_263:
if ( F_84 ( V_5 ) )
F_24 ( V_15 , L_72 ,
V_254 , V_157 ) ;
return V_180 ;
}
static int F_103 ( struct V_14 * V_15 )
{
struct V_2 * V_276 = F_9 ( V_15 ) ;
T_1 V_277 , V_278 ;
if ( ! F_104 ( V_276 ) )
return 0 ;
if ( V_15 -> V_48 & V_279 )
V_277 = 1 ;
else
return 0 ;
V_278 = ( 1 << V_277 ) - 1 ;
if ( V_276 -> V_280 <= V_278 )
return 0 ;
V_276 -> V_280 = V_278 ;
if ( V_276 -> V_281 > V_277 ) {
F_57 ( V_15 , L_73 ,
F_38 ( V_277 ) ) ;
return - V_282 ;
}
return 0 ;
}
static inline T_2 F_105 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
if ( F_106 ( V_15 ) & V_283 )
return 0 ;
return ( ( V_5 -> V_33 == V_284 ) && ( ! F_107 ( V_15 -> V_142 ) ) ) ;
}
static int F_108 ( struct V_14 * V_15 ,
char * V_285 , T_5 V_286 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
int V_287 = 0 , V_288 = F_109 ( V_15 -> V_142 ) ;
unsigned int V_157 ;
char * V_289 = L_67 ;
if ( ! F_110 ( V_15 -> V_142 ) ) {
V_285 [ 0 ] = '\0' ;
return 0 ;
}
if ( V_15 -> V_48 & V_290 ) {
snprintf ( V_285 , V_286 , L_74 ) ;
return 0 ;
}
if ( V_5 -> V_42 & V_291 ) {
V_287 = F_111 ( V_5 -> V_292 -> V_293 , V_294 - 1 ) ;
V_15 -> V_42 |= V_295 ;
}
if ( ! ( V_15 -> V_48 & V_296 ) &&
( V_5 -> V_42 & V_297 ) &&
F_112 ( V_15 -> V_142 ) ) {
V_157 = F_100 ( V_15 , V_298 ,
V_299 ) ;
if ( V_157 ) {
F_59 ( V_15 ,
L_75 ,
V_157 ) ;
if ( V_157 != V_162 ) {
V_15 -> V_48 |= V_296 ;
return - V_165 ;
}
} else
V_289 = L_76 ;
}
if ( V_287 >= V_288 )
snprintf ( V_285 , V_286 , L_77 , V_288 , V_289 ) ;
else
snprintf ( V_285 , V_286 , L_78 , V_287 ,
V_288 , V_289 ) ;
return 0 ;
}
int F_113 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_171 * V_172 = & V_15 -> V_3 -> V_173 ;
int V_174 = V_172 -> V_25 . V_42 & V_175 ;
const T_4 * V_142 = V_15 -> V_142 ;
unsigned long V_47 ;
unsigned int V_157 ;
char V_300 [ 7 ] ;
char V_301 [ V_302 + 1 ] ;
char V_303 [ V_304 + 1 ] ;
int V_180 ;
if ( ! F_8 ( V_15 ) && F_114 ( V_5 ) ) {
F_57 ( V_15 , L_79 , V_258 ) ;
return 0 ;
}
if ( F_115 ( V_5 ) )
F_96 ( V_15 , L_59 , V_258 ) ;
V_15 -> V_48 |= F_106 ( V_15 ) ;
F_18 ( V_15 ) ;
if ( V_15 -> V_48 & V_305 ) {
F_57 ( V_15 , L_80 ) ;
F_116 ( V_15 ) ;
return 0 ;
}
if ( ( ! V_306 || ( V_5 -> V_42 & V_307 ) ) &&
V_15 -> V_181 == V_138 ) {
F_24 ( V_15 , L_81 ,
V_306 ? L_82
: L_83 ) ;
F_116 ( V_15 ) ;
return 0 ;
}
V_180 = F_103 ( V_15 ) ;
if ( V_180 )
return V_180 ;
V_180 = F_117 ( V_15 ) ;
if ( V_180 )
return V_180 ;
V_180 = F_55 ( V_15 ) ;
if ( V_180 )
return V_180 ;
if ( F_115 ( V_5 ) )
F_96 ( V_15 ,
L_84
L_85 ,
V_258 ,
V_142 [ 49 ] , V_142 [ 82 ] , V_142 [ 83 ] , V_142 [ 84 ] ,
V_142 [ 85 ] , V_142 [ 86 ] , V_142 [ 87 ] , V_142 [ 88 ] ) ;
V_15 -> V_42 &= ~ V_308 ;
V_15 -> V_156 = 0 ;
V_15 -> V_309 = 0 ;
V_15 -> V_310 = 0 ;
V_15 -> V_311 = 0 ;
V_15 -> V_103 = 0 ;
V_15 -> V_104 = 0 ;
V_15 -> V_94 = 0 ;
V_47 = F_61 ( V_142 ) ;
if ( F_115 ( V_5 ) )
F_60 ( V_142 ) ;
F_41 ( V_15 -> V_142 , V_301 , V_312 ,
sizeof( V_301 ) ) ;
F_41 ( V_15 -> V_142 , V_303 , V_313 ,
sizeof( V_303 ) ) ;
if ( V_15 -> V_181 == V_137 ) {
if ( F_62 ( V_142 ) ) {
if ( V_142 [ V_314 ] & 1 )
F_24 ( V_15 ,
L_86 ) ;
snprintf ( V_300 , 7 , L_87 ) ;
} else {
snprintf ( V_300 , 7 , L_88 , F_101 ( V_142 ) ) ;
if ( F_118 ( V_142 ) )
F_24 ( V_15 ,
L_86 ) ;
}
V_15 -> V_310 = F_43 ( V_142 ) ;
if ( ( V_15 -> V_142 [ 47 ] >> 8 ) == 0x80 && ( V_15 -> V_142 [ 59 ] & 0x100 ) ) {
unsigned int V_315 = V_15 -> V_142 [ 47 ] & 0xff ;
unsigned int V_316 = V_15 -> V_142 [ 59 ] & 0xff ;
if ( F_119 ( V_315 ) && F_119 ( V_316 ) )
if ( V_316 <= V_315 )
V_15 -> V_94 = V_316 ;
}
if ( F_44 ( V_142 ) ) {
const char * V_317 ;
char V_318 [ 24 ] ;
V_317 = L_89 ;
V_15 -> V_42 |= V_116 ;
if ( F_45 ( V_142 ) ) {
V_15 -> V_42 |= V_117 ;
V_317 = L_90 ;
if ( V_15 -> V_310 >= ( 1UL << 28 ) &&
F_120 ( V_142 ) )
V_15 -> V_42 |= V_319 ;
}
V_180 = F_108 ( V_15 , V_318 , sizeof( V_318 ) ) ;
if ( V_180 )
return V_180 ;
if ( F_121 ( V_5 ) && V_174 ) {
F_57 ( V_15 , L_91 ,
V_300 , V_303 , V_301 ,
F_36 ( V_47 ) ) ;
F_57 ( V_15 ,
L_92 ,
( unsigned long long ) V_15 -> V_310 ,
V_15 -> V_94 , V_317 , V_318 ) ;
}
} else {
V_15 -> V_311 = V_142 [ 1 ] ;
V_15 -> V_103 = V_142 [ 3 ] ;
V_15 -> V_104 = V_142 [ 6 ] ;
if ( F_48 ( V_142 ) ) {
V_15 -> V_311 = V_142 [ 54 ] ;
V_15 -> V_103 = V_142 [ 55 ] ;
V_15 -> V_104 = V_142 [ 56 ] ;
}
if ( F_121 ( V_5 ) && V_174 ) {
F_57 ( V_15 , L_91 ,
V_300 , V_303 , V_301 ,
F_36 ( V_47 ) ) ;
F_57 ( V_15 ,
L_93 ,
( unsigned long long ) V_15 -> V_310 ,
V_15 -> V_94 , V_15 -> V_311 ,
V_15 -> V_103 , V_15 -> V_104 ) ;
}
}
if ( F_122 ( V_15 -> V_142 ) ) {
T_2 * V_320 = V_5 -> V_321 ;
int V_25 , V_322 ;
V_15 -> V_42 |= V_323 ;
V_157 = F_123 ( V_15 ,
V_324 ,
V_325 ,
V_320 ,
1 ) ;
if ( V_157 )
F_96 ( V_15 ,
L_94 ,
V_157 ) ;
else
for ( V_25 = 0 ; V_25 < V_326 ; V_25 ++ ) {
V_322 = V_327 + V_25 ;
V_15 -> V_328 [ V_25 ] = V_320 [ V_322 ] ;
}
}
V_15 -> V_309 = 16 ;
}
else if ( V_15 -> V_181 == V_138 ) {
const char * V_329 = L_67 ;
const char * V_330 = L_67 ;
const char * V_331 = L_67 ;
T_1 V_332 ;
V_180 = F_124 ( V_142 ) ;
if ( ( V_180 < 12 ) || ( V_180 > V_222 ) ) {
if ( F_84 ( V_5 ) )
F_24 ( V_15 , L_95 ) ;
V_180 = - V_118 ;
goto V_333;
}
V_15 -> V_309 = ( unsigned int ) V_180 ;
if ( V_334 &&
( V_5 -> V_42 & V_335 ) && F_125 ( V_142 ) &&
( ! F_4 ( V_5 ) ||
F_126 ( & V_5 -> V_3 , V_336 , & V_332 ) == 0 ) ) {
V_157 = F_100 ( V_15 ,
V_298 , V_337 ) ;
if ( V_157 )
F_59 ( V_15 ,
L_96 ,
V_157 ) ;
else {
V_15 -> V_42 |= V_338 ;
V_330 = L_97 ;
}
}
if ( F_127 ( V_15 -> V_142 ) ) {
V_15 -> V_42 |= V_339 ;
V_329 = L_98 ;
}
if ( V_340 || ( V_15 -> V_48 & V_341 ) || F_128 ( V_15 -> V_142 ) ) {
V_15 -> V_42 |= V_224 ;
V_331 = L_99 ;
}
if ( F_129 ( V_15 -> V_142 ) ) {
V_15 -> V_42 |= V_342 ;
F_130 ( V_15 ) ;
}
if ( F_121 ( V_5 ) && V_174 )
F_57 ( V_15 ,
L_100 ,
V_303 , V_301 ,
F_36 ( V_47 ) ,
V_329 , V_330 ,
V_331 ) ;
}
V_15 -> V_156 = V_343 ;
if ( V_15 -> V_42 & V_117 )
V_15 -> V_156 = V_344 ;
if ( F_105 ( V_15 ) ) {
if ( F_121 ( V_5 ) && V_174 )
F_57 ( V_15 , L_101 ) ;
V_15 -> V_46 &= V_345 ;
V_15 -> V_156 = V_343 ;
}
if ( ( V_15 -> V_181 == V_138 ) &&
( F_131 ( V_142 ) == V_346 ) ) {
V_15 -> V_156 = V_347 ;
V_15 -> V_48 |= V_348 ;
}
if ( V_15 -> V_48 & V_349 )
V_15 -> V_156 = F_132 (unsigned int, ATA_MAX_SECTORS_128,
dev->max_sectors) ;
if ( V_15 -> V_48 & V_350 )
V_15 -> V_156 = V_344 ;
if ( V_5 -> V_213 -> V_351 )
V_5 -> V_213 -> V_351 ( V_15 ) ;
if ( V_15 -> V_48 & V_352 ) {
if ( V_174 ) {
F_24 ( V_15 ,
L_102 ) ;
F_24 ( V_15 ,
L_103 ) ;
}
}
if ( ( V_15 -> V_48 & V_353 ) && V_174 ) {
F_24 ( V_15 , L_104 ) ;
F_24 ( V_15 , L_105 ) ;
}
return 0 ;
V_333:
if ( F_115 ( V_5 ) )
F_96 ( V_15 , L_106 , V_258 ) ;
return V_180 ;
}
int F_133 ( struct V_4 * V_5 )
{
return V_354 ;
}
int F_134 ( struct V_4 * V_5 )
{
return V_355 ;
}
int F_135 ( struct V_4 * V_5 )
{
return V_356 ;
}
int F_136 ( struct V_4 * V_5 )
{
return V_357 ;
}
int F_137 ( struct V_4 * V_5 )
{
return V_284 ;
}
int F_138 ( struct V_4 * V_5 )
{
unsigned int V_358 [ V_359 ] ;
int V_360 [ V_359 ] ;
int V_180 ;
struct V_14 * V_15 ;
F_139 (dev, &ap->link, ALL)
V_360 [ V_15 -> V_24 ] = V_361 ;
V_259:
F_139 (dev, &ap->link, ALL) {
V_15 -> V_247 = V_362 ;
V_15 -> V_363 = 0xff ;
if ( V_5 -> V_213 -> V_364 )
V_5 -> V_213 -> V_364 ( V_5 , V_15 ) ;
}
V_5 -> V_213 -> V_365 ( V_5 ) ;
F_139 (dev, &ap->link, ALL) {
if ( V_15 -> V_181 != V_141 )
V_358 [ V_15 -> V_24 ] = V_15 -> V_181 ;
else
V_358 [ V_15 -> V_24 ] = V_366 ;
V_15 -> V_181 = V_141 ;
}
F_139 (dev, &ap->link, ALL_REVERSE) {
if ( V_360 [ V_15 -> V_24 ] )
V_15 -> V_181 = V_358 [ V_15 -> V_24 ] ;
if ( ! F_8 ( V_15 ) )
continue;
V_180 = F_94 ( V_15 , & V_15 -> V_181 , V_275 ,
V_15 -> V_142 ) ;
if ( V_180 )
goto V_367;
}
if ( V_5 -> V_213 -> V_368 )
V_5 -> V_33 = V_5 -> V_213 -> V_368 ( V_5 ) ;
F_139 (dev, &ap->link, ENABLED)
if ( F_107 ( V_15 -> V_142 ) )
V_5 -> V_33 = V_284 ;
F_139 (dev, &ap->link, ENABLED) {
V_5 -> V_3 . V_173 . V_25 . V_42 |= V_175 ;
V_180 = F_113 ( V_15 ) ;
V_5 -> V_3 . V_173 . V_25 . V_42 &= ~ V_175 ;
if ( V_180 )
goto V_367;
}
V_180 = F_140 ( & V_5 -> V_3 , & V_15 ) ;
if ( V_180 )
goto V_367;
F_139 (dev, &ap->link, ENABLED)
return 0 ;
return - V_262 ;
V_367:
V_360 [ V_15 -> V_24 ] -- ;
switch ( V_180 ) {
case - V_118 :
V_360 [ V_15 -> V_24 ] = 0 ;
break;
case - V_262 :
V_360 [ V_15 -> V_24 ] = F_111 ( V_360 [ V_15 -> V_24 ] , 1 ) ;
case - V_165 :
if ( V_360 [ V_15 -> V_24 ] == 1 ) {
F_141 ( & V_5 -> V_3 , 0 ) ;
F_142 ( V_15 , V_369 ) ;
}
}
if ( ! V_360 [ V_15 -> V_24 ] )
F_116 ( V_15 ) ;
goto V_259;
}
static void F_143 ( struct V_2 * V_3 )
{
T_1 V_1 , V_370 , V_371 ;
if ( F_126 ( V_3 , V_372 , & V_1 ) )
return;
F_126 ( V_3 , V_373 , & V_370 ) ;
if ( F_144 ( V_3 ) ) {
V_371 = ( V_1 >> 4 ) & 0xf ;
F_145 ( V_3 , L_107 ,
F_38 ( V_371 ) , V_1 , V_370 ) ;
} else {
F_145 ( V_3 , L_108 ,
V_1 , V_370 ) ;
}
}
struct V_14 * F_146 ( struct V_14 * V_244 )
{
struct V_2 * V_3 = V_244 -> V_3 ;
struct V_14 * V_374 = & V_3 -> V_21 [ 1 - V_244 -> V_24 ] ;
if ( ! F_8 ( V_374 ) )
return NULL ;
return V_374 ;
}
int F_141 ( struct V_2 * V_3 , T_1 V_39 )
{
T_1 V_1 , V_135 , V_375 ;
int V_180 , V_376 ;
if ( ! F_104 ( V_3 ) )
return - V_377 ;
V_180 = F_126 ( V_3 , V_372 , & V_1 ) ;
if ( V_180 == 0 && F_1 ( V_1 ) )
V_135 = ( V_1 >> 4 ) & 0xf ;
else
V_135 = V_3 -> V_281 ;
V_375 = V_3 -> V_280 ;
if ( V_375 <= 1 )
return - V_118 ;
V_376 = F_33 ( V_375 ) - 1 ;
V_375 &= ~ ( 1 << V_376 ) ;
if ( V_135 > 1 )
V_375 &= ( 1 << ( V_135 - 1 ) ) - 1 ;
else
V_375 &= 1 ;
if ( ! V_375 )
return - V_118 ;
if ( V_39 ) {
if ( V_375 & ( ( 1 << V_39 ) - 1 ) )
V_375 &= ( 1 << V_39 ) - 1 ;
else {
V_376 = F_147 ( V_375 ) - 1 ;
V_375 = 1 << V_376 ;
}
}
V_3 -> V_280 = V_375 ;
F_148 ( V_3 , L_109 ,
F_38 ( F_33 ( V_375 ) ) ) ;
return 0 ;
}
static int F_149 ( struct V_2 * V_3 , T_1 * V_370 )
{
struct V_2 * V_378 = & V_3 -> V_5 -> V_3 ;
T_1 V_379 , V_277 , V_135 ;
V_379 = V_3 -> V_280 ;
if ( ! F_13 ( V_3 ) && V_378 -> V_281 )
V_379 &= ( 1 << V_378 -> V_281 ) - 1 ;
if ( V_379 == V_380 )
V_277 = 0 ;
else
V_277 = F_33 ( V_379 ) ;
V_135 = ( * V_370 >> 4 ) & 0xf ;
* V_370 = ( * V_370 & ~ 0xf0 ) | ( ( V_277 & 0xf ) << 4 ) ;
return V_135 != V_277 ;
}
static int F_150 ( struct V_2 * V_3 )
{
T_1 V_370 ;
if ( F_126 ( V_3 , V_373 , & V_370 ) )
return 1 ;
return F_149 ( V_3 , & V_370 ) ;
}
int F_151 ( struct V_2 * V_3 )
{
T_1 V_370 ;
int V_180 ;
if ( ( V_180 = F_126 ( V_3 , V_373 , & V_370 ) ) )
return V_180 ;
if ( ! F_149 ( V_3 , & V_370 ) )
return 0 ;
if ( ( V_180 = F_152 ( V_3 , V_373 , V_370 ) ) )
return V_180 ;
return 1 ;
}
static void F_153 ( const struct V_381 * V_382 , struct V_381 * V_383 , int V_384 , int V_385 )
{
V_383 -> V_386 = F_154 ( V_382 -> V_386 * 1000 , V_384 ) ;
V_383 -> V_387 = F_154 ( V_382 -> V_387 * 1000 , V_384 ) ;
V_383 -> V_388 = F_154 ( V_382 -> V_388 * 1000 , V_384 ) ;
V_383 -> V_389 = F_154 ( V_382 -> V_389 * 1000 , V_384 ) ;
V_383 -> V_390 = F_154 ( V_382 -> V_390 * 1000 , V_384 ) ;
V_383 -> V_391 = F_154 ( V_382 -> V_391 * 1000 , V_384 ) ;
V_383 -> V_392 = F_154 ( V_382 -> V_392 * 1000 , V_384 ) ;
V_383 -> V_393 = F_154 ( V_382 -> V_393 * 1000 , V_384 ) ;
V_383 -> V_394 = F_154 ( V_382 -> V_394 * 1000 , V_385 ) ;
}
void F_155 ( const struct V_381 * V_395 , const struct V_381 * V_396 ,
struct V_381 * V_397 , unsigned int V_398 )
{
if ( V_398 & V_399 ) V_397 -> V_386 = V_315 ( V_395 -> V_386 , V_396 -> V_386 ) ;
if ( V_398 & V_400 ) V_397 -> V_387 = V_315 ( V_395 -> V_387 , V_396 -> V_387 ) ;
if ( V_398 & V_401 ) V_397 -> V_388 = V_315 ( V_395 -> V_388 , V_396 -> V_388 ) ;
if ( V_398 & V_402 ) V_397 -> V_389 = V_315 ( V_395 -> V_389 , V_396 -> V_389 ) ;
if ( V_398 & V_403 ) V_397 -> V_390 = V_315 ( V_395 -> V_390 , V_396 -> V_390 ) ;
if ( V_398 & V_404 ) V_397 -> V_391 = V_315 ( V_395 -> V_391 , V_396 -> V_391 ) ;
if ( V_398 & V_405 ) V_397 -> V_392 = V_315 ( V_395 -> V_392 , V_396 -> V_392 ) ;
if ( V_398 & V_406 ) V_397 -> V_393 = V_315 ( V_395 -> V_393 , V_396 -> V_393 ) ;
if ( V_398 & V_407 ) V_397 -> V_394 = V_315 ( V_395 -> V_394 , V_396 -> V_394 ) ;
}
const struct V_381 * F_156 ( T_2 V_133 )
{
const struct V_381 * V_382 = V_381 ;
while ( V_133 > V_382 -> V_7 )
V_382 ++ ;
if ( V_133 == V_382 -> V_7 )
return V_382 ;
F_157 ( true , L_110 ,
V_258 , V_133 ) ;
return NULL ;
}
int F_158 ( struct V_14 * V_244 , unsigned short V_408 ,
struct V_381 * V_382 , int V_384 , int V_385 )
{
const T_4 * V_142 = V_244 -> V_142 ;
const struct V_381 * V_143 ;
struct V_381 V_147 ;
if ( ! ( V_143 = F_156 ( V_408 ) ) )
return - V_118 ;
memcpy ( V_382 , V_143 , sizeof( * V_143 ) ) ;
if ( V_142 [ V_184 ] & 2 ) {
memset ( & V_147 , 0 , sizeof( V_147 ) ) ;
if ( V_408 >= V_362 && V_408 < V_409 ) {
if ( V_408 <= V_250 )
V_147 . V_393 = V_147 . V_389 = V_142 [ V_251 ] ;
else if ( ( V_408 <= V_410 ) ||
( V_408 == V_248 && ! F_62 ( V_142 ) ) )
V_147 . V_393 = V_147 . V_389 = V_142 [ V_411 ] ;
} else if ( V_408 >= V_412 && V_408 <= V_413 )
V_147 . V_393 = V_142 [ V_414 ] ;
F_155 ( & V_147 , V_382 , V_382 , V_406 | V_402 ) ;
}
F_153 ( V_382 , V_382 , V_384 , V_385 ) ;
if ( V_408 > V_249 ) {
F_158 ( V_244 , V_244 -> V_247 , & V_147 , V_384 , V_385 ) ;
F_155 ( & V_147 , V_382 , V_382 , V_415 ) ;
}
if ( V_382 -> V_387 + V_382 -> V_388 < V_382 -> V_389 ) {
V_382 -> V_387 += ( V_382 -> V_389 - ( V_382 -> V_387 + V_382 -> V_388 ) ) / 2 ;
V_382 -> V_388 = V_382 -> V_389 - V_382 -> V_387 ;
}
if ( V_382 -> V_390 + V_382 -> V_391 < V_382 -> V_393 ) {
V_382 -> V_390 += ( V_382 -> V_393 - ( V_382 -> V_390 + V_382 -> V_391 ) ) / 2 ;
V_382 -> V_391 = V_382 -> V_393 - V_382 -> V_390 ;
}
if ( V_382 -> V_390 + V_382 -> V_391 > V_382 -> V_393 )
V_382 -> V_393 = V_382 -> V_390 + V_382 -> V_391 ;
return 0 ;
}
T_2 F_159 ( unsigned int V_416 , int V_393 )
{
T_2 V_417 = 0xff , V_418 = 0xff ;
const struct V_127 * V_128 ;
const struct V_381 * V_382 ;
for ( V_128 = V_129 ; V_128 -> V_130 >= 0 ; V_128 ++ )
if ( V_128 -> V_130 == V_416 )
V_417 = V_128 -> V_132 ;
for ( V_382 = F_156 ( V_417 ) ;
V_382 && F_35 ( V_382 -> V_7 ) == V_416 ; V_382 ++ ) {
unsigned short V_419 ;
switch ( V_416 ) {
case V_120 :
case V_122 :
V_419 = V_382 -> V_393 ;
break;
case V_124 :
V_419 = V_382 -> V_394 ;
break;
default:
return 0xff ;
}
if ( V_393 > V_419 )
break;
V_418 = V_382 -> V_7 ;
}
return V_418 ;
}
int F_142 ( struct V_14 * V_15 , unsigned int V_420 )
{
char V_242 [ 32 ] ;
unsigned long V_421 , V_47 ;
unsigned long V_44 , V_45 , V_46 ;
int V_422 , V_126 ;
V_422 = ! ! ( V_420 & V_423 ) ;
V_420 &= ~ V_423 ;
V_47 = V_421 = F_31 ( V_15 -> V_44 ,
V_15 -> V_45 ,
V_15 -> V_46 ) ;
F_16 ( V_47 , & V_44 , & V_45 , & V_46 ) ;
switch ( V_420 ) {
case V_369 :
V_126 = F_33 ( V_44 ) - 1 ;
V_44 &= ~ ( 1 << V_126 ) ;
break;
case V_424 :
if ( V_46 ) {
V_126 = F_33 ( V_46 ) - 1 ;
V_46 &= ~ ( 1 << V_126 ) ;
if ( ! V_46 )
return - V_267 ;
} else if ( V_45 ) {
V_126 = F_33 ( V_45 ) - 1 ;
V_45 &= ~ ( 1 << V_126 ) ;
if ( ! V_45 )
return - V_267 ;
}
break;
case V_425 :
V_46 &= V_426 ;
break;
case V_427 :
V_44 &= 1 ;
case V_428 :
V_45 = 0 ;
V_46 = 0 ;
break;
default:
F_70 () ;
}
V_47 &= F_31 ( V_44 , V_45 , V_46 ) ;
if ( ! ( V_47 & V_121 ) || V_47 == V_421 )
return - V_267 ;
if ( ! V_422 ) {
if ( V_47 & ( V_123 | V_125 ) )
snprintf ( V_242 , sizeof( V_242 ) , L_111 ,
F_36 ( V_47 ) ,
F_36 ( V_47 & V_121 ) ) ;
else
snprintf ( V_242 , sizeof( V_242 ) , L_112 ,
F_36 ( V_47 ) ) ;
F_24 ( V_15 , L_113 , V_242 ) ;
}
F_16 ( V_47 , & V_15 -> V_44 , & V_15 -> V_45 ,
& V_15 -> V_46 ) ;
return 0 ;
}
static int F_160 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_171 * V_172 = & V_15 -> V_3 -> V_173 ;
const bool V_429 = V_15 -> V_48 & V_430 ;
const char * V_431 = L_67 ;
int V_432 = 0 ;
unsigned int V_157 = 0 ;
int V_180 ;
V_15 -> V_42 &= ~ V_91 ;
if ( V_15 -> V_416 == V_120 )
V_15 -> V_42 |= V_91 ;
if ( V_429 && V_5 -> V_42 & V_433 && F_107 ( V_15 -> V_142 ) )
V_431 = L_114 ;
else {
if ( V_429 )
F_24 ( V_15 ,
L_115
L_116 ) ;
V_157 = F_161 ( V_15 ) ;
}
if ( V_157 & ~ V_162 )
goto V_367;
V_172 -> V_25 . V_42 |= V_434 ;
V_180 = F_162 ( V_15 , V_141 , 0 ) ;
V_172 -> V_25 . V_42 &= ~ V_434 ;
if ( V_180 )
return V_180 ;
if ( V_15 -> V_416 == V_120 ) {
if ( F_62 ( V_15 -> V_142 ) )
V_432 = 1 ;
if ( F_101 ( V_15 -> V_142 ) == 0 &&
V_15 -> V_247 <= V_250 )
V_432 = 1 ;
if ( ! F_91 ( V_15 -> V_142 ) && V_15 -> V_247 <= V_250 )
V_432 = 1 ;
}
if ( V_15 -> V_416 == V_122 &&
V_15 -> V_363 == V_412 &&
( V_15 -> V_142 [ 63 ] >> 8 ) & 1 )
V_432 = 1 ;
if ( V_15 -> V_133 == F_32 ( F_61 ( V_15 -> V_142 ) ) )
V_432 = 1 ;
if ( V_157 & V_162 ) {
if ( ! V_432 )
goto V_367;
else
V_431 = L_117 ;
}
F_30 ( L_118 ,
V_15 -> V_416 , ( int ) V_15 -> V_133 ) ;
F_57 ( V_15 , L_119 ,
F_36 ( F_34 ( V_15 -> V_133 ) ) ,
V_431 ) ;
return 0 ;
V_367:
F_59 ( V_15 , L_120 , V_157 ) ;
return - V_165 ;
}
int F_163 ( struct V_2 * V_3 , struct V_14 * * V_435 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_14 * V_15 ;
int V_180 = 0 , V_436 = 0 , V_437 = 0 ;
F_139 (dev, link, ENABLED) {
unsigned long V_44 , V_438 ;
unsigned int V_439 ;
V_439 = V_440 ;
if ( V_15 -> V_181 == V_138 )
V_439 = V_441 ;
else if ( F_62 ( V_15 -> V_142 ) )
V_439 = V_442 ;
F_164 ( V_15 ) ;
F_15 ( V_15 ) ;
V_44 = F_31 ( V_15 -> V_44 , 0 , 0 ) ;
if ( V_443 & V_439 )
V_438 = F_31 ( 0 , V_15 -> V_45 ,
V_15 -> V_46 ) ;
else
V_438 = 0 ;
V_15 -> V_247 = F_32 ( V_44 ) ;
V_15 -> V_363 = F_32 ( V_438 ) ;
V_437 = 1 ;
if ( F_165 ( V_15 ) )
V_436 = 1 ;
}
if ( ! V_437 )
goto V_444;
F_139 (dev, link, ENABLED) {
if ( V_15 -> V_247 == 0xff ) {
F_24 ( V_15 , L_121 ) ;
V_180 = - V_118 ;
goto V_444;
}
V_15 -> V_133 = V_15 -> V_247 ;
V_15 -> V_416 = V_120 ;
if ( V_5 -> V_213 -> V_364 )
V_5 -> V_213 -> V_364 ( V_5 , V_15 ) ;
}
F_139 (dev, link, ENABLED) {
if ( ! F_165 ( V_15 ) )
continue;
V_15 -> V_133 = V_15 -> V_363 ;
V_15 -> V_416 = F_35 ( V_15 -> V_363 ) ;
if ( V_5 -> V_213 -> V_445 )
V_5 -> V_213 -> V_445 ( V_5 , V_15 ) ;
}
F_139 (dev, link, ENABLED) {
V_180 = F_160 ( V_15 ) ;
if ( V_180 )
goto V_444;
}
if ( V_436 && ( V_5 -> V_272 -> V_42 & V_446 ) )
V_5 -> V_272 -> V_447 = V_5 ;
V_444:
if ( V_180 )
* V_435 = V_15 ;
return V_180 ;
}
int F_166 ( struct V_2 * V_3 , unsigned long V_448 ,
int (* F_167)( struct V_2 * V_3 ) )
{
unsigned long V_449 = V_450 ;
unsigned long V_451 ;
int V_452 = 0 ;
if ( V_3 -> V_5 -> V_272 -> V_42 & V_453 )
V_451 = F_168 ( V_449 , V_454 ) ;
else
V_451 = F_168 ( V_449 , V_455 ) ;
F_87 ( V_3 == V_3 -> V_5 -> V_12 ) ;
if ( F_169 ( V_451 , V_448 ) )
V_451 = V_448 ;
while ( 1 ) {
unsigned long V_456 = V_450 ;
int V_457 , V_371 ;
V_457 = V_371 = F_167 ( V_3 ) ;
if ( V_457 > 0 )
return 0 ;
if ( V_457 == - V_262 ) {
if ( F_170 ( V_3 ) )
V_457 = 0 ;
else if ( ( V_3 -> V_5 -> V_42 & V_433 ) &&
! F_171 ( V_3 ) &&
F_172 ( V_456 , V_451 ) )
V_457 = 0 ;
}
if ( V_457 )
return V_457 ;
if ( F_169 ( V_456 , V_448 ) )
return - V_458 ;
if ( ! V_452 && F_169 ( V_456 , V_449 + 5 * V_459 ) &&
( V_448 - V_456 > 3 * V_459 ) ) {
F_148 ( V_3 ,
L_122
L_123 , V_371 ) ;
V_452 = 1 ;
}
F_173 ( V_3 -> V_5 , 50 ) ;
}
}
int F_174 ( struct V_2 * V_3 , unsigned long V_448 ,
int (* F_167)( struct V_2 * V_3 ) )
{
F_173 ( V_3 -> V_5 , V_460 ) ;
return F_166 ( V_3 , V_448 , F_167 ) ;
}
int F_175 ( struct V_2 * V_3 , const unsigned long * V_461 ,
unsigned long V_448 )
{
unsigned long V_462 = V_461 [ 0 ] ;
unsigned long V_463 = V_461 [ 1 ] ;
unsigned long V_464 , V_382 ;
T_1 V_465 , V_466 ;
int V_180 ;
V_382 = F_168 ( V_450 , V_461 [ 2 ] ) ;
if ( F_172 ( V_382 , V_448 ) )
V_448 = V_382 ;
if ( ( V_180 = F_126 ( V_3 , V_372 , & V_466 ) ) )
return V_180 ;
V_466 &= 0xf ;
V_465 = V_466 ;
V_464 = V_450 ;
while ( 1 ) {
F_173 ( V_3 -> V_5 , V_462 ) ;
if ( ( V_180 = F_126 ( V_3 , V_372 , & V_466 ) ) )
return V_180 ;
V_466 &= 0xf ;
if ( V_466 == V_465 ) {
if ( V_466 == 1 && F_172 ( V_450 , V_448 ) )
continue;
if ( F_169 ( V_450 ,
F_168 ( V_464 , V_463 ) ) )
return 0 ;
continue;
}
V_465 = V_466 ;
V_464 = V_450 ;
if ( F_169 ( V_450 , V_448 ) )
return - V_467 ;
}
}
int F_176 ( struct V_2 * V_3 , const unsigned long * V_461 ,
unsigned long V_448 )
{
int V_360 = V_468 ;
T_1 V_370 , V_469 ;
int V_180 ;
if ( ( V_180 = F_126 ( V_3 , V_373 , & V_370 ) ) )
return V_180 ;
do {
V_370 = ( V_370 & 0x0f0 ) | 0x300 ;
if ( ( V_180 = F_152 ( V_3 , V_373 , V_370 ) ) )
return V_180 ;
F_173 ( V_3 -> V_5 , 200 ) ;
if ( ( V_180 = F_126 ( V_3 , V_373 , & V_370 ) ) )
return V_180 ;
} while ( ( V_370 & 0xf0f ) != 0x300 && -- V_360 );
if ( ( V_370 & 0xf0f ) != 0x300 ) {
F_148 ( V_3 , L_124 ,
V_370 ) ;
return 0 ;
}
if ( V_360 < V_468 )
F_148 ( V_3 , L_125 ,
V_468 - V_360 ) ;
if ( ( V_180 = F_175 ( V_3 , V_461 , V_448 ) ) )
return V_180 ;
if ( ! ( V_180 = F_126 ( V_3 , V_470 , & V_469 ) ) )
V_180 = F_152 ( V_3 , V_470 , V_469 ) ;
return V_180 != - V_118 ? V_180 : 0 ;
}
int F_177 ( struct V_2 * V_3 , enum V_471 V_472 ,
bool V_473 )
{
struct V_171 * V_172 = & V_3 -> V_173 ;
bool V_474 = false ;
T_1 V_370 ;
int V_180 ;
V_180 = F_126 ( V_3 , V_373 , & V_370 ) ;
if ( V_180 )
return V_180 ;
switch ( V_472 ) {
case V_475 :
V_370 |= ( 0x7 << 8 ) ;
if ( V_473 ) {
V_370 |= ( 0x4 << 12 ) ;
V_474 = true ;
}
break;
case V_476 :
V_370 &= ~ ( 0x1 << 8 ) ;
V_370 |= ( 0x6 << 8 ) ;
break;
case V_477 :
if ( F_178 ( V_3 ) > 0 )
V_370 &= ~ ( 0x7 << 8 ) ;
else {
V_370 &= ~ 0xf ;
V_370 |= ( 0x1 << 2 ) ;
}
break;
default:
F_87 ( 1 ) ;
}
V_180 = F_152 ( V_3 , V_373 , V_370 ) ;
if ( V_180 )
return V_180 ;
if ( V_474 )
F_179 ( 10 ) ;
V_172 -> V_25 . V_469 &= ~ V_478 ;
return F_152 ( V_3 , V_470 , V_478 ) ;
}
int F_180 ( struct V_2 * V_3 , unsigned long V_448 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_171 * V_172 = & V_3 -> V_173 ;
const unsigned long * V_479 = F_181 ( V_172 ) ;
int V_180 ;
if ( V_172 -> V_25 . V_480 & V_481 )
return 0 ;
if ( V_5 -> V_42 & V_433 ) {
V_180 = F_176 ( V_3 , V_479 , V_448 ) ;
if ( V_180 && V_180 != - V_377 )
F_148 ( V_3 ,
L_126 ,
V_180 ) ;
}
if ( F_182 ( V_3 ) )
V_172 -> V_25 . V_480 &= ~ V_482 ;
return 0 ;
}
int F_183 ( struct V_2 * V_3 , const unsigned long * V_479 ,
unsigned long V_448 ,
bool * V_483 , int (* F_167)( struct V_2 * ) )
{
T_1 V_370 ;
int V_180 ;
F_30 ( L_127 ) ;
if ( V_483 )
* V_483 = false ;
if ( F_150 ( V_3 ) ) {
if ( ( V_180 = F_126 ( V_3 , V_373 , & V_370 ) ) )
goto V_444;
V_370 = ( V_370 & 0x0f0 ) | 0x304 ;
if ( ( V_180 = F_152 ( V_3 , V_373 , V_370 ) ) )
goto V_444;
F_151 ( V_3 ) ;
}
if ( ( V_180 = F_126 ( V_3 , V_373 , & V_370 ) ) )
goto V_444;
V_370 = ( V_370 & 0x0f0 ) | 0x301 ;
if ( ( V_180 = F_184 ( V_3 , V_373 , V_370 ) ) )
goto V_444;
F_173 ( V_3 -> V_5 , 1 ) ;
V_180 = F_176 ( V_3 , V_479 , V_448 ) ;
if ( V_180 )
goto V_444;
if ( F_182 ( V_3 ) )
goto V_444;
if ( V_483 )
* V_483 = true ;
if ( F_185 ( V_3 -> V_5 ) && F_13 ( V_3 ) ) {
if ( F_167 ) {
unsigned long V_484 ;
V_484 = F_168 ( V_450 ,
V_485 ) ;
if ( F_169 ( V_484 , V_448 ) )
V_484 = V_448 ;
F_166 ( V_3 , V_484 , F_167 ) ;
}
V_180 = - V_282 ;
goto V_444;
}
V_180 = 0 ;
if ( F_167 )
V_180 = F_166 ( V_3 , V_448 , F_167 ) ;
V_444:
if ( V_180 && V_180 != - V_282 ) {
if ( V_483 )
* V_483 = false ;
F_186 ( V_3 , L_128 , V_180 ) ;
}
F_30 ( L_129 , V_180 ) ;
return V_180 ;
}
int F_187 ( struct V_2 * V_3 , unsigned int * V_181 ,
unsigned long V_448 )
{
const unsigned long * V_479 = F_181 ( & V_3 -> V_173 ) ;
bool V_483 ;
int V_180 ;
V_180 = F_183 ( V_3 , V_479 , V_448 , & V_483 , NULL ) ;
return V_483 ? - V_282 : V_180 ;
}
void F_188 ( struct V_2 * V_3 , unsigned int * V_358 )
{
T_1 V_469 ;
F_30 ( L_127 ) ;
if ( ! F_126 ( V_3 , V_470 , & V_469 ) )
F_152 ( V_3 , V_470 , V_469 ) ;
F_143 ( V_3 ) ;
F_30 ( L_130 ) ;
}
static int F_189 ( struct V_14 * V_15 , unsigned int V_486 ,
const T_4 * V_487 )
{
const T_4 * V_488 = V_15 -> V_142 ;
unsigned char V_489 [ 2 ] [ V_304 + 1 ] ;
unsigned char V_490 [ 2 ] [ V_491 + 1 ] ;
if ( V_15 -> V_181 != V_486 ) {
F_57 ( V_15 , L_131 ,
V_15 -> V_181 , V_486 ) ;
return 0 ;
}
F_41 ( V_488 , V_489 [ 0 ] , V_313 , sizeof( V_489 [ 0 ] ) ) ;
F_41 ( V_487 , V_489 [ 1 ] , V_313 , sizeof( V_489 [ 1 ] ) ) ;
F_41 ( V_488 , V_490 [ 0 ] , V_492 , sizeof( V_490 [ 0 ] ) ) ;
F_41 ( V_487 , V_490 [ 1 ] , V_492 , sizeof( V_490 [ 1 ] ) ) ;
if ( strcmp ( V_489 [ 0 ] , V_489 [ 1 ] ) ) {
F_57 ( V_15 , L_132 ,
V_489 [ 0 ] , V_489 [ 1 ] ) ;
return 0 ;
}
if ( strcmp ( V_490 [ 0 ] , V_490 [ 1 ] ) ) {
F_57 ( V_15 , L_133 ,
V_490 [ 0 ] , V_490 [ 1 ] ) ;
return 0 ;
}
return 1 ;
}
int F_58 ( struct V_14 * V_15 , unsigned int V_493 )
{
unsigned int V_181 = V_15 -> V_181 ;
T_4 * V_142 = ( void * ) V_15 -> V_3 -> V_5 -> V_321 ;
int V_180 ;
V_180 = F_94 ( V_15 , & V_181 , V_493 , V_142 ) ;
if ( V_180 )
return V_180 ;
if ( ! F_189 ( V_15 , V_181 , V_142 ) )
return - V_262 ;
memcpy ( V_15 -> V_142 , V_142 , sizeof( V_142 [ 0 ] ) * V_252 ) ;
return 0 ;
}
int F_162 ( struct V_14 * V_15 , unsigned int V_486 ,
unsigned int V_493 )
{
T_3 V_310 = V_15 -> V_310 ;
T_3 V_183 = V_15 -> V_183 ;
int V_180 ;
if ( ! F_8 ( V_15 ) )
return - V_262 ;
if ( F_190 ( V_486 ) &&
V_486 != V_137 &&
V_486 != V_138 &&
V_486 != V_140 ) {
F_57 ( V_15 , L_134 ,
V_15 -> V_181 , V_486 ) ;
V_180 = - V_262 ;
goto V_367;
}
V_180 = F_58 ( V_15 , V_493 ) ;
if ( V_180 )
goto V_367;
V_180 = F_113 ( V_15 ) ;
if ( V_180 )
goto V_367;
if ( V_15 -> V_181 != V_137 || ! V_310 ||
V_15 -> V_310 == V_310 )
return 0 ;
F_24 ( V_15 , L_135 ,
( unsigned long long ) V_310 ,
( unsigned long long ) V_15 -> V_310 ) ;
if ( V_15 -> V_183 == V_183 &&
V_15 -> V_310 > V_310 && V_15 -> V_310 == V_183 ) {
F_24 ( V_15 ,
L_136
L_137 ) ;
return 0 ;
}
if ( V_15 -> V_183 == V_183 &&
V_15 -> V_310 < V_310 && V_310 == V_183 &&
! ( V_15 -> V_48 & V_182 ) ) {
F_24 ( V_15 ,
L_138
L_139 ) ;
V_15 -> V_42 |= V_178 ;
V_180 = - V_165 ;
} else
V_180 = - V_262 ;
V_15 -> V_183 = V_183 ;
V_15 -> V_310 = V_310 ;
V_367:
F_59 ( V_15 , L_140 , V_180 ) ;
return V_180 ;
}
static int F_191 ( const char * V_494 , const char * V_495 )
{
do {
if ( * V_494 == * V_495 || * V_495 == '?' ) {
if ( ! * V_495 ++ )
return 0 ;
} else {
if ( ! * V_494 || * V_495 != '[' )
break;
while ( * ++ V_495 && * V_495 != ']' && * V_494 != * V_495 ) {
if ( * V_495 == '-' && * ( V_495 - 1 ) != '[' )
if ( * V_494 > * ( V_495 - 1 ) && * V_494 < * ( V_495 + 1 ) ) {
++ V_495 ;
break;
}
}
if ( ! * V_495 || * V_495 == ']' )
return 1 ;
while ( * V_495 && * V_495 ++ != ']' ) ;
}
} while ( * ++ V_494 && * V_495 );
if ( * V_495 == '*' ) {
if ( ! * ++ V_495 )
return 0 ;
while ( * V_494 ) {
if ( F_191 ( V_494 , V_495 ) == 0 )
return 0 ;
++ V_494 ;
}
}
if ( ! * V_494 && ! * V_495 )
return 0 ;
return 1 ;
}
static unsigned long F_106 ( const struct V_14 * V_15 )
{
unsigned char V_496 [ V_304 + 1 ] ;
unsigned char V_497 [ V_302 + 1 ] ;
const struct V_498 * V_499 = V_500 ;
F_41 ( V_15 -> V_142 , V_496 , V_313 , sizeof( V_496 ) ) ;
F_41 ( V_15 -> V_142 , V_497 , V_312 , sizeof( V_497 ) ) ;
while ( V_499 -> V_496 ) {
if ( ! F_191 ( V_496 , V_499 -> V_496 ) ) {
if ( V_499 -> V_497 == NULL )
return V_499 -> V_48 ;
if ( ! F_191 ( V_497 , V_499 -> V_497 ) )
return V_499 -> V_48 ;
}
V_499 ++ ;
}
return 0 ;
}
static int F_192 ( const struct V_14 * V_15 )
{
if ( ( V_15 -> V_3 -> V_5 -> V_42 & V_501 ) &&
( V_15 -> V_42 & V_339 ) )
return 1 ;
return ( V_15 -> V_48 & V_502 ) ? 1 : 0 ;
}
static int F_193 ( struct V_14 * V_15 )
{
if ( V_15 -> V_48 & V_503 )
return F_194 ( V_15 -> V_142 ) ;
return F_195 ( V_15 -> V_142 ) ;
}
static int F_196 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
struct V_14 * V_15 ;
if ( V_5 -> V_33 == V_354 )
return 1 ;
if ( V_5 -> V_33 == V_355 || V_5 -> V_33 == V_284 )
return 0 ;
if ( V_5 -> V_33 == V_504 )
return 0 ;
F_197 (link, ap, EDGE) {
F_139 (dev, link, ENABLED) {
if ( ! F_193 ( V_15 ) )
return 0 ;
}
}
return 1 ;
}
static void F_164 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_505 * V_272 = V_5 -> V_272 ;
unsigned long V_47 ;
V_47 = F_31 ( V_5 -> V_44 ,
V_5 -> V_45 , V_5 -> V_46 ) ;
V_47 &= F_31 ( V_15 -> V_44 ,
V_15 -> V_45 , V_15 -> V_46 ) ;
V_47 &= F_61 ( V_15 -> V_142 ) ;
if ( F_146 ( V_15 ) ) {
V_47 &= ~ ( 0x03 << ( V_120 + 5 ) ) ;
V_47 &= ~ ( 0x03 << ( V_122 + 3 ) ) ;
}
if ( F_192 ( V_15 ) ) {
V_47 &= ~ ( V_123 | V_125 ) ;
F_24 ( V_15 ,
L_141 ) ;
}
if ( ( V_272 -> V_42 & V_446 ) &&
V_272 -> V_447 && V_272 -> V_447 != V_5 ) {
V_47 &= ~ ( V_123 | V_125 ) ;
F_24 ( V_15 ,
L_142 ) ;
}
if ( V_5 -> V_42 & V_246 )
V_47 &= F_92 ( V_15 ) ;
if ( V_5 -> V_213 -> V_506 )
V_47 = V_5 -> V_213 -> V_506 ( V_15 , V_47 ) ;
if ( V_47 & ( 0xF8 << V_124 ) )
if ( F_196 ( V_5 ) ) {
F_24 ( V_15 ,
L_143 ) ;
V_47 &= ~ ( 0xF8 << V_124 ) ;
}
F_16 ( V_47 , & V_15 -> V_44 ,
& V_15 -> V_45 , & V_15 -> V_46 ) ;
}
static unsigned int F_161 ( struct V_14 * V_15 )
{
struct V_67 V_68 ;
unsigned int V_157 ;
F_30 ( L_144 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_507 ;
V_68 . V_72 = V_508 ;
V_68 . V_42 |= V_108 | V_109 | V_264 ;
V_68 . V_92 = V_160 ;
if ( F_90 ( V_15 ) )
V_68 . V_80 = V_15 -> V_133 ;
else if ( F_91 ( V_15 -> V_142 ) )
V_68 . V_80 = 0x01 ;
else
return 0 ;
V_157 = F_53 ( V_15 , & V_68 , NULL , V_161 , NULL , 0 , 0 ) ;
F_30 ( L_145 , V_157 ) ;
return V_157 ;
}
unsigned int F_100 ( struct V_14 * V_15 , T_2 V_509 , T_2 V_72 )
{
struct V_67 V_68 ;
unsigned int V_157 ;
F_30 ( L_146 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_507 ;
V_68 . V_72 = V_509 ;
V_68 . V_42 |= V_108 | V_109 ;
V_68 . V_92 = V_160 ;
V_68 . V_80 = V_72 ;
V_157 = F_53 ( V_15 , & V_68 , NULL , V_161 , NULL , 0 , 0 ) ;
F_30 ( L_145 , V_157 ) ;
return V_157 ;
}
static unsigned int F_102 ( struct V_14 * V_15 ,
T_4 V_103 , T_4 V_104 )
{
struct V_67 V_68 ;
unsigned int V_157 ;
if ( V_104 < 1 || V_104 > 255 || V_103 < 1 || V_103 > 16 )
return V_510 ;
F_30 ( L_147 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_511 ;
V_68 . V_42 |= V_108 | V_109 ;
V_68 . V_92 = V_160 ;
V_68 . V_80 = V_104 ;
V_68 . V_21 |= ( V_103 - 1 ) & 0x0f ;
V_157 = F_53 ( V_15 , & V_68 , NULL , V_161 , NULL , 0 , 0 ) ;
if ( V_157 == V_162 && ( V_68 . V_72 & V_163 ) )
V_157 = 0 ;
F_30 ( L_145 , V_157 ) ;
return V_157 ;
}
void F_198 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
struct V_199 * V_229 = V_193 -> V_229 ;
int V_512 = V_193 -> V_198 ;
F_199 ( V_229 == NULL ) ;
F_200 ( L_148 , V_193 -> V_201 ) ;
if ( V_193 -> V_201 )
F_201 ( V_5 -> V_15 , V_229 , V_193 -> V_513 , V_512 ) ;
V_193 -> V_42 &= ~ V_514 ;
V_193 -> V_229 = NULL ;
}
int F_202 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
if ( ! ( V_193 -> V_15 -> V_48 & V_515 ) &&
F_5 ( V_193 -> V_231 & 15 ) )
return 1 ;
if ( V_5 -> V_213 -> V_516 )
return V_5 -> V_213 -> V_516 ( V_193 ) ;
return 0 ;
}
int F_203 ( struct V_192 * V_193 )
{
struct V_2 * V_3 = V_193 -> V_15 -> V_3 ;
if ( V_193 -> V_68 . V_92 == V_112 ) {
if ( ! F_204 ( V_3 -> V_217 ) )
return 0 ;
} else {
if ( ! F_204 ( V_3 -> V_217 ) && ! V_3 -> V_218 )
return 0 ;
}
return V_517 ;
}
void F_205 ( struct V_192 * V_193 ) { }
void F_74 ( struct V_192 * V_193 , struct V_199 * V_229 ,
unsigned int V_201 )
{
V_193 -> V_229 = V_229 ;
V_193 -> V_201 = V_201 ;
V_193 -> V_518 = V_193 -> V_229 ;
}
static int F_206 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
unsigned int V_201 ;
F_200 ( L_149 , V_5 -> V_31 ) ;
V_201 = F_207 ( V_5 -> V_15 , V_193 -> V_229 , V_193 -> V_201 , V_193 -> V_198 ) ;
if ( V_201 < 1 )
return - 1 ;
F_30 ( L_150 , V_201 ) ;
V_193 -> V_513 = V_193 -> V_201 ;
V_193 -> V_201 = V_201 ;
V_193 -> V_42 |= V_514 ;
return 0 ;
}
void F_98 ( T_4 * V_242 , unsigned int V_519 )
{
#ifdef F_208
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < V_519 ; V_25 ++ )
V_242 [ V_25 ] = F_209 ( V_242 [ V_25 ] ) ;
#endif
}
static struct V_192 * F_210 ( struct V_4 * V_5 )
{
struct V_192 * V_193 = NULL ;
unsigned int V_25 ;
if ( F_5 ( V_5 -> V_210 & V_211 ) )
return NULL ;
for ( V_25 = 0 ; V_25 < V_294 - 1 ; V_25 ++ )
if ( ! F_69 ( V_25 , & V_5 -> V_215 ) ) {
V_193 = F_71 ( V_5 , V_25 ) ;
break;
}
if ( V_193 )
V_193 -> V_107 = V_25 ;
return V_193 ;
}
struct V_192 * F_211 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_192 * V_193 ;
V_193 = F_210 ( V_5 ) ;
if ( V_193 ) {
V_193 -> V_216 = NULL ;
V_193 -> V_5 = V_5 ;
V_193 -> V_15 = V_15 ;
F_72 ( V_193 ) ;
}
return V_193 ;
}
void F_85 ( struct V_192 * V_193 )
{
struct V_4 * V_5 ;
unsigned int V_107 ;
F_199 ( V_193 == NULL ) ;
V_5 = V_193 -> V_5 ;
V_193 -> V_42 = 0 ;
V_107 = V_193 -> V_107 ;
if ( F_27 ( F_204 ( V_107 ) ) ) {
V_193 -> V_107 = V_221 ;
F_212 ( V_107 , & V_5 -> V_215 ) ;
}
}
void F_213 ( struct V_192 * V_193 )
{
struct V_4 * V_5 ;
struct V_2 * V_3 ;
F_199 ( V_193 == NULL ) ;
F_199 ( ! ( V_193 -> V_42 & V_234 ) ) ;
V_5 = V_193 -> V_5 ;
V_3 = V_193 -> V_15 -> V_3 ;
if ( F_27 ( V_193 -> V_42 & V_514 ) )
F_198 ( V_193 ) ;
if ( V_193 -> V_68 . V_92 == V_112 ) {
V_3 -> V_218 &= ~ ( 1 << V_193 -> V_107 ) ;
if ( ! V_3 -> V_218 )
V_5 -> V_220 -- ;
} else {
V_3 -> V_217 = V_221 ;
V_5 -> V_220 -- ;
}
if ( F_5 ( V_193 -> V_42 & V_520 &&
V_5 -> V_521 == V_3 ) )
V_5 -> V_521 = NULL ;
V_193 -> V_42 &= ~ V_234 ;
V_5 -> V_219 &= ~ ( 1 << V_193 -> V_107 ) ;
V_193 -> V_232 ( V_193 ) ;
}
static void F_214 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
V_193 -> V_238 . V_42 = V_193 -> V_68 . V_42 ;
V_5 -> V_213 -> V_522 ( V_193 ) ;
}
static void F_215 ( struct V_192 * V_193 )
{
struct V_14 * V_15 = V_193 -> V_15 ;
if ( F_216 ( V_193 -> V_68 . V_92 ) )
return;
if ( ( V_15 -> V_45 || V_15 -> V_46 ) && F_217 ( V_193 -> V_68 . V_92 ) )
return;
V_15 -> V_42 &= ~ V_523 ;
}
void F_83 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
if ( V_5 -> V_213 -> V_214 ) {
struct V_14 * V_15 = V_193 -> V_15 ;
struct V_524 * V_525 = & V_15 -> V_3 -> V_526 ;
if ( F_5 ( V_193 -> V_157 ) )
V_193 -> V_42 |= V_237 ;
if ( F_5 ( F_218 ( V_193 -> V_107 ) ) ) {
F_214 ( V_193 ) ;
F_213 ( V_193 ) ;
return;
}
if ( F_5 ( V_193 -> V_42 & V_237 ) ) {
F_214 ( V_193 ) ;
F_219 ( V_193 ) ;
return;
}
F_199 ( V_5 -> V_210 & V_211 ) ;
if ( V_193 -> V_42 & V_227 )
F_214 ( V_193 ) ;
switch ( V_193 -> V_68 . V_71 ) {
case V_507 :
if ( V_193 -> V_68 . V_72 != V_527 &&
V_193 -> V_68 . V_72 != V_528 )
break;
case V_511 :
case V_529 :
V_525 -> V_530 [ V_15 -> V_24 ] |= V_531 ;
F_220 ( V_5 ) ;
break;
case V_532 :
V_15 -> V_42 |= V_533 ;
break;
}
if ( F_5 ( V_15 -> V_42 & V_523 ) )
F_215 ( V_193 ) ;
F_213 ( V_193 ) ;
} else {
if ( V_193 -> V_42 & V_534 )
return;
if ( V_193 -> V_157 || V_193 -> V_42 & V_227 )
F_214 ( V_193 ) ;
F_213 ( V_193 ) ;
}
}
int F_221 ( struct V_4 * V_5 , T_1 V_219 )
{
int V_535 = 0 ;
T_1 V_536 ;
V_536 = V_5 -> V_219 ^ V_219 ;
if ( F_5 ( V_536 & V_219 ) ) {
F_222 ( V_5 , L_151 ,
V_5 -> V_219 , V_219 ) ;
return - V_118 ;
}
while ( V_536 ) {
struct V_192 * V_193 ;
unsigned int V_107 = F_223 ( V_536 ) ;
V_193 = F_224 ( V_5 , V_107 ) ;
if ( V_193 ) {
F_83 ( V_193 ) ;
V_535 ++ ;
}
V_536 &= ~ ( 1 << V_107 ) ;
}
return V_535 ;
}
void F_75 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
struct V_2 * V_3 = V_193 -> V_15 -> V_3 ;
T_2 V_537 = V_193 -> V_68 . V_92 ;
F_199 ( V_5 -> V_213 -> V_214 && F_204 ( V_3 -> V_217 ) ) ;
if ( F_225 ( V_537 ) ) {
F_199 ( V_3 -> V_218 & ( 1 << V_193 -> V_107 ) ) ;
if ( ! V_3 -> V_218 )
V_5 -> V_220 ++ ;
V_3 -> V_218 |= 1 << V_193 -> V_107 ;
} else {
F_199 ( V_3 -> V_218 ) ;
V_5 -> V_220 ++ ;
V_3 -> V_217 = V_193 -> V_107 ;
}
V_193 -> V_42 |= V_234 ;
V_5 -> V_219 |= 1 << V_193 -> V_107 ;
if ( F_199 ( F_226 ( V_537 ) &&
( ! V_193 -> V_229 || ! V_193 -> V_201 || ! V_193 -> V_231 ) ) )
goto V_538;
if ( F_227 ( V_537 ) || ( F_217 ( V_537 ) &&
( V_5 -> V_42 & V_539 ) ) )
if ( F_206 ( V_193 ) )
goto V_538;
if ( F_5 ( V_193 -> V_15 -> V_42 & V_533 ) ) {
V_3 -> V_526 . V_480 |= V_540 ;
F_228 ( & V_3 -> V_526 , L_152 ) ;
F_229 ( V_3 ) ;
return;
}
V_5 -> V_213 -> V_541 ( V_193 ) ;
V_193 -> V_157 |= V_5 -> V_213 -> V_542 ( V_193 ) ;
if ( F_5 ( V_193 -> V_157 ) )
goto V_543;
return;
V_538:
V_193 -> V_157 |= V_212 ;
V_543:
F_83 ( V_193 ) ;
}
int F_104 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
return ( V_5 -> V_42 & V_433 ) && V_5 -> V_213 -> V_544 ;
}
int F_126 ( struct V_2 * V_3 , int V_545 , T_1 * V_546 )
{
if ( F_13 ( V_3 ) ) {
if ( F_104 ( V_3 ) )
return V_3 -> V_5 -> V_213 -> V_544 ( V_3 , V_545 , V_546 ) ;
return - V_377 ;
}
return F_230 ( V_3 , V_545 , V_546 ) ;
}
int F_152 ( struct V_2 * V_3 , int V_545 , T_1 V_546 )
{
if ( F_13 ( V_3 ) ) {
if ( F_104 ( V_3 ) )
return V_3 -> V_5 -> V_213 -> V_547 ( V_3 , V_545 , V_546 ) ;
return - V_377 ;
}
return F_231 ( V_3 , V_545 , V_546 ) ;
}
int F_184 ( struct V_2 * V_3 , int V_545 , T_1 V_546 )
{
if ( F_13 ( V_3 ) ) {
int V_180 ;
if ( F_104 ( V_3 ) ) {
V_180 = V_3 -> V_5 -> V_213 -> V_547 ( V_3 , V_545 , V_546 ) ;
if ( V_180 == 0 )
V_180 = V_3 -> V_5 -> V_213 -> V_544 ( V_3 , V_545 , & V_546 ) ;
return V_180 ;
}
return - V_377 ;
}
return F_231 ( V_3 , V_545 , V_546 ) ;
}
bool F_144 ( struct V_2 * V_3 )
{
T_1 V_1 ;
if ( F_126 ( V_3 , V_372 , & V_1 ) == 0 &&
F_1 ( V_1 ) )
return true ;
return false ;
}
bool F_182 ( struct V_2 * V_3 )
{
T_1 V_1 ;
if ( F_126 ( V_3 , V_372 , & V_1 ) == 0 &&
! F_1 ( V_1 ) )
return true ;
return false ;
}
bool F_170 ( struct V_2 * V_3 )
{
struct V_2 * V_548 = V_3 -> V_5 -> V_12 ;
F_87 ( V_3 == V_548 ) ;
return F_144 ( V_3 ) ||
( V_548 && F_144 ( V_548 ) ) ;
}
bool F_171 ( struct V_2 * V_3 )
{
struct V_2 * V_548 = V_3 -> V_5 -> V_12 ;
F_87 ( V_3 == V_548 ) ;
return F_182 ( V_3 ) &&
( ! V_548 || F_182 ( V_548 ) ) ;
}
static int F_232 ( struct V_4 * V_5 , T_6 V_549 ,
unsigned int V_480 , unsigned int V_550 ,
int * V_551 )
{
struct V_2 * V_3 ;
unsigned long V_42 ;
int V_180 = 0 ;
if ( V_5 -> V_210 & V_552 ) {
if ( V_551 ) {
* V_551 = - V_282 ;
return 0 ;
}
F_233 ( V_5 ) ;
F_87 ( V_5 -> V_210 & V_552 ) ;
}
F_67 ( V_5 -> V_209 , V_42 ) ;
V_5 -> V_553 = V_549 ;
if ( V_551 )
V_5 -> V_554 = V_551 ;
else
V_5 -> V_554 = & V_180 ;
V_5 -> V_210 |= V_552 ;
F_197 (link, ap, HOST_FIRST) {
V_3 -> V_526 . V_480 |= V_480 ;
V_3 -> V_526 . V_42 |= V_550 ;
}
F_220 ( V_5 ) ;
F_68 ( V_5 -> V_209 , V_42 ) ;
if ( ! V_551 ) {
F_233 ( V_5 ) ;
F_87 ( V_5 -> V_210 & V_552 ) ;
}
return V_180 ;
}
static int F_234 ( struct V_4 * V_5 , T_6 V_549 , int * V_551 )
{
unsigned int V_550 = V_555 | V_556 |
V_557 ;
return F_232 ( V_5 , V_549 , 0 , V_550 , V_551 ) ;
}
static int F_235 ( struct V_21 * V_15 , T_6 V_549 )
{
struct V_4 * V_5 = F_236 ( V_15 ) ;
return F_234 ( V_5 , V_549 , NULL ) ;
}
static int F_237 ( struct V_21 * V_15 )
{
if ( F_238 ( V_15 ) )
return 0 ;
return F_235 ( V_15 , V_558 ) ;
}
static int F_239 ( struct V_21 * V_15 )
{
if ( F_238 ( V_15 ) )
return 0 ;
return F_235 ( V_15 , V_559 ) ;
}
static int F_240 ( struct V_21 * V_15 )
{
return F_235 ( V_15 , V_560 ) ;
}
static int F_241 ( struct V_4 * V_5 , T_6 V_549 ,
int * V_551 )
{
int V_180 ;
V_180 = F_232 ( V_5 , V_549 , V_540 ,
V_556 | V_555 , V_551 ) ;
return V_180 ;
}
static int F_242 ( struct V_21 * V_15 , T_6 V_549 )
{
struct V_4 * V_5 = F_236 ( V_15 ) ;
return F_241 ( V_5 , V_549 , NULL ) ;
}
static int F_243 ( struct V_21 * V_15 )
{
int V_180 ;
V_180 = F_242 ( V_15 , V_561 ) ;
if ( ! V_180 ) {
F_244 ( V_15 ) ;
F_245 ( V_15 ) ;
F_246 ( V_15 ) ;
}
return V_180 ;
}
static int F_247 ( struct V_21 * V_15 )
{
struct V_4 * V_5 = F_236 ( V_15 ) ;
struct V_2 * V_3 ;
struct V_14 * V_244 ;
F_197 (link, ap, HOST_FIRST) {
F_139 (adev, link, ENABLED)
if ( V_244 -> V_181 == V_138 &&
! F_248 ( V_244 ) )
return - V_458 ;
}
return 0 ;
}
static int F_249 ( struct V_21 * V_15 )
{
return F_235 ( V_15 , V_562 ) ;
}
static int F_250 ( struct V_21 * V_15 )
{
return F_242 ( V_15 , V_563 ) ;
}
int F_251 ( struct V_4 * V_5 , int * V_551 )
{
return F_234 ( V_5 , V_558 , V_551 ) ;
}
int F_252 ( struct V_4 * V_5 , int * V_551 )
{
return F_241 ( V_5 , V_561 , V_551 ) ;
}
int F_253 ( struct V_505 * V_272 , T_6 V_549 )
{
V_272 -> V_15 -> V_564 . V_565 = V_549 ;
return 0 ;
}
void F_254 ( struct V_505 * V_272 )
{
V_272 -> V_15 -> V_564 . V_565 = V_566 ;
}
void F_255 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = F_9 ( V_15 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_42 ;
V_3 -> V_280 = V_3 -> V_40 ;
V_3 -> V_281 = 0 ;
F_67 ( V_5 -> V_209 , V_42 ) ;
V_15 -> V_42 &= ~ V_567 ;
V_15 -> V_48 = 0 ;
F_68 ( V_5 -> V_209 , V_42 ) ;
memset ( ( void * ) V_15 + V_568 , 0 ,
V_569 - V_568 ) ;
V_15 -> V_44 = V_380 ;
V_15 -> V_45 = V_380 ;
V_15 -> V_46 = V_380 ;
}
void F_256 ( struct V_4 * V_5 , struct V_2 * V_3 , int V_38 )
{
int V_25 ;
memset ( ( void * ) V_3 + V_570 , 0 ,
V_571 - V_570 ) ;
V_3 -> V_5 = V_5 ;
V_3 -> V_38 = V_38 ;
V_3 -> V_217 = V_221 ;
V_3 -> V_40 = V_380 ;
for ( V_25 = 0 ; V_25 < V_359 ; V_25 ++ ) {
struct V_14 * V_15 = & V_3 -> V_21 [ V_25 ] ;
V_15 -> V_3 = V_3 ;
V_15 -> V_24 = V_15 - V_3 -> V_21 ;
#ifdef F_257
V_15 -> V_572 = V_573 ;
#endif
F_255 ( V_15 ) ;
}
}
int F_258 ( struct V_2 * V_3 )
{
T_2 V_135 ;
int V_180 ;
V_180 = F_126 ( V_3 , V_373 , & V_3 -> V_574 ) ;
if ( V_180 )
return V_180 ;
V_135 = ( V_3 -> V_574 >> 4 ) & 0xf ;
if ( V_135 )
V_3 -> V_40 &= ( 1 << V_135 ) - 1 ;
F_12 ( V_3 ) ;
V_3 -> V_280 = V_3 -> V_40 ;
return 0 ;
}
struct V_4 * F_259 ( struct V_505 * V_272 )
{
struct V_4 * V_5 ;
F_30 ( L_127 ) ;
V_5 = F_260 ( sizeof( * V_5 ) , V_575 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_210 |= V_576 | V_211 ;
V_5 -> V_209 = & V_272 -> V_209 ;
V_5 -> V_31 = - 1 ;
V_5 -> V_577 = - 1 ;
V_5 -> V_272 = V_272 ;
V_5 -> V_15 = V_272 -> V_15 ;
#if F_261 ( V_578 )
V_5 -> V_579 = 0x00FF ;
#elif F_261 ( V_580 )
V_5 -> V_579 = V_581 | V_582 | V_583 | V_584 | V_585 ;
#else
V_5 -> V_579 = V_581 | V_585 | V_584 ;
#endif
F_262 ( & V_5 -> V_586 ) ;
F_263 ( & V_5 -> V_587 , V_588 ) ;
F_264 ( & V_5 -> V_589 , V_590 ) ;
F_265 ( & V_5 -> V_591 ) ;
F_266 ( & V_5 -> V_592 ) ;
F_267 ( & V_5 -> V_593 ) ;
F_268 ( & V_5 -> V_594 ) ;
V_5 -> V_594 . V_595 = V_596 ;
V_5 -> V_594 . V_597 = ( unsigned long ) V_5 ;
V_5 -> V_33 = V_34 ;
F_256 ( V_5 , & V_5 -> V_3 , 0 ) ;
#ifdef F_269
V_5 -> V_598 . V_599 = 1 ;
V_5 -> V_598 . V_600 = 1 ;
#endif
F_270 ( V_5 ) ;
return V_5 ;
}
static void F_271 ( struct V_21 * V_601 , void * V_602 )
{
struct V_505 * V_272 = F_272 ( V_601 ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_272 -> V_603 ; V_25 ++ ) {
struct V_4 * V_5 = V_272 -> V_604 [ V_25 ] ;
if ( ! V_5 )
continue;
if ( V_5 -> V_292 )
F_273 ( V_5 -> V_292 ) ;
F_274 ( V_5 -> V_11 ) ;
F_274 ( V_5 -> V_12 ) ;
F_274 ( V_5 ) ;
V_272 -> V_604 [ V_25 ] = NULL ;
}
F_275 ( V_601 , NULL ) ;
}
struct V_505 * F_276 ( struct V_21 * V_15 , int V_605 )
{
struct V_505 * V_272 ;
T_5 V_606 ;
int V_25 ;
F_30 ( L_127 ) ;
if ( ! F_277 ( V_15 , NULL , V_575 ) )
return NULL ;
V_606 = sizeof( struct V_505 ) + ( V_605 + 1 ) * sizeof( void * ) ;
V_272 = F_278 ( F_271 , V_606 , V_575 ) ;
if ( ! V_272 )
goto V_263;
F_279 ( V_15 , V_272 ) ;
F_275 ( V_15 , V_272 ) ;
F_280 ( & V_272 -> V_209 ) ;
F_262 ( & V_272 -> V_607 ) ;
V_272 -> V_15 = V_15 ;
V_272 -> V_603 = V_605 ;
for ( V_25 = 0 ; V_25 < V_605 ; V_25 ++ ) {
struct V_4 * V_5 ;
V_5 = F_259 ( V_272 ) ;
if ( ! V_5 )
goto V_263;
V_5 -> V_608 = V_25 ;
V_272 -> V_604 [ V_25 ] = V_5 ;
}
F_281 ( V_15 , NULL ) ;
return V_272 ;
V_263:
F_282 ( V_15 , NULL ) ;
return NULL ;
}
struct V_505 * F_283 ( struct V_21 * V_15 ,
const struct V_609 * const * V_610 ,
int V_603 )
{
const struct V_609 * V_611 ;
struct V_505 * V_272 ;
int V_25 , V_322 ;
V_272 = F_276 ( V_15 , V_603 ) ;
if ( ! V_272 )
return NULL ;
for ( V_25 = 0 , V_322 = 0 , V_611 = NULL ; V_25 < V_272 -> V_603 ; V_25 ++ ) {
struct V_4 * V_5 = V_272 -> V_604 [ V_25 ] ;
if ( V_610 [ V_322 ] )
V_611 = V_610 [ V_322 ++ ] ;
V_5 -> V_44 = V_611 -> V_44 ;
V_5 -> V_45 = V_611 -> V_45 ;
V_5 -> V_46 = V_611 -> V_46 ;
V_5 -> V_42 |= V_611 -> V_42 ;
V_5 -> V_3 . V_42 |= V_611 -> V_612 ;
V_5 -> V_213 = V_611 -> V_613 ;
if ( ! V_272 -> V_213 && ( V_611 -> V_613 != & V_614 ) )
V_272 -> V_213 = V_611 -> V_613 ;
}
return V_272 ;
}
int F_284 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
F_87 ( V_5 -> V_12 ) ;
F_87 ( V_5 -> V_42 & V_615 ) ;
V_3 = F_260 ( sizeof( * V_3 ) , V_575 ) ;
if ( ! V_3 )
return - V_616 ;
F_256 ( V_5 , V_3 , 1 ) ;
V_5 -> V_12 = V_3 ;
return 0 ;
}
static void F_285 ( struct V_21 * V_601 , void * V_602 )
{
struct V_505 * V_272 = F_272 ( V_601 ) ;
int V_25 ;
F_87 ( ! ( V_272 -> V_42 & V_617 ) ) ;
for ( V_25 = 0 ; V_25 < V_272 -> V_603 ; V_25 ++ ) {
struct V_4 * V_5 = V_272 -> V_604 [ V_25 ] ;
if ( V_5 -> V_213 -> V_618 )
V_5 -> V_213 -> V_618 ( V_5 ) ;
}
if ( V_272 -> V_213 -> V_619 )
V_272 -> V_213 -> V_619 ( V_272 ) ;
}
static void F_286 ( struct V_620 * V_213 )
{
static F_287 ( V_209 ) ;
const struct V_620 * V_466 ;
void * * V_621 = ( void * * ) V_213 ;
void * * V_622 = ( void * * ) & V_213 -> V_623 ;
void * * V_624 ;
if ( ! V_213 || ! V_213 -> V_623 )
return;
F_288 ( & V_209 ) ;
for ( V_466 = V_213 -> V_623 ; V_466 ; V_466 = V_466 -> V_623 ) {
void * * V_625 = ( void * * ) V_466 ;
for ( V_624 = V_621 ; V_624 < V_622 ; V_624 ++ , V_625 ++ )
if ( ! * V_624 )
* V_624 = * V_625 ;
}
for ( V_624 = V_621 ; V_624 < V_622 ; V_624 ++ )
if ( F_289 ( * V_624 ) )
* V_624 = NULL ;
V_213 -> V_623 = NULL ;
F_290 ( & V_209 ) ;
}
int F_291 ( struct V_505 * V_272 )
{
int V_626 = 0 ;
void * V_627 = NULL ;
int V_25 , V_180 ;
if ( V_272 -> V_42 & V_617 )
return 0 ;
F_286 ( V_272 -> V_213 ) ;
for ( V_25 = 0 ; V_25 < V_272 -> V_603 ; V_25 ++ ) {
struct V_4 * V_5 = V_272 -> V_604 [ V_25 ] ;
F_286 ( V_5 -> V_213 ) ;
if ( ! V_272 -> V_213 && ! F_292 ( V_5 ) )
V_272 -> V_213 = V_5 -> V_213 ;
if ( V_5 -> V_213 -> V_618 )
V_626 = 1 ;
}
if ( V_272 -> V_213 -> V_619 )
V_626 = 1 ;
if ( V_626 ) {
V_627 = F_278 ( F_285 , 0 , V_575 ) ;
if ( ! V_627 )
return - V_616 ;
}
for ( V_25 = 0 ; V_25 < V_272 -> V_603 ; V_25 ++ ) {
struct V_4 * V_5 = V_272 -> V_604 [ V_25 ] ;
if ( V_5 -> V_213 -> V_628 ) {
V_180 = V_5 -> V_213 -> V_628 ( V_5 ) ;
if ( V_180 ) {
if ( V_180 != - V_262 )
F_293 ( V_272 -> V_15 ,
L_153 ,
V_25 , V_180 ) ;
goto V_263;
}
}
F_294 ( V_5 ) ;
}
if ( V_627 )
F_279 ( V_272 -> V_15 , V_627 ) ;
V_272 -> V_42 |= V_617 ;
return 0 ;
V_263:
while ( -- V_25 >= 0 ) {
struct V_4 * V_5 = V_272 -> V_604 [ V_25 ] ;
if ( V_5 -> V_213 -> V_618 )
V_5 -> V_213 -> V_618 ( V_5 ) ;
}
F_295 ( V_627 ) ;
return V_180 ;
}
void F_296 ( struct V_505 * V_272 , struct V_21 * V_15 ,
struct V_620 * V_213 )
{
F_280 ( & V_272 -> V_209 ) ;
F_262 ( & V_272 -> V_607 ) ;
V_272 -> V_15 = V_15 ;
V_272 -> V_213 = V_213 ;
}
void F_297 ( struct V_4 * V_5 )
{
struct V_524 * V_525 = & V_5 -> V_3 . V_526 ;
unsigned long V_42 ;
F_67 ( V_5 -> V_209 , V_42 ) ;
V_525 -> V_629 |= V_630 ;
V_525 -> V_480 |= V_540 ;
V_525 -> V_42 |= V_556 | V_555 ;
V_5 -> V_210 &= ~ V_576 ;
V_5 -> V_210 |= V_631 ;
F_220 ( V_5 ) ;
F_68 ( V_5 -> V_209 , V_42 ) ;
}
int F_298 ( struct V_4 * V_5 )
{
int V_180 = 0 ;
if ( V_5 -> V_213 -> V_214 ) {
F_297 ( V_5 ) ;
F_233 ( V_5 ) ;
} else {
F_30 ( L_154 , V_5 -> V_31 ) ;
V_180 = F_138 ( V_5 ) ;
F_30 ( L_155 , V_5 -> V_31 ) ;
}
return V_180 ;
}
static void F_299 ( void * V_597 , T_7 V_632 )
{
struct V_4 * V_5 = V_597 ;
if ( ! ( V_5 -> V_272 -> V_42 & V_453 ) && V_5 -> V_608 != 0 )
F_300 ( V_632 ) ;
( void ) F_298 ( V_5 ) ;
F_300 ( V_632 ) ;
F_301 ( V_5 , 1 ) ;
}
int F_302 ( struct V_505 * V_272 , struct V_633 * V_634 )
{
int V_25 , V_180 ;
if ( ! ( V_272 -> V_42 & V_617 ) ) {
F_293 ( V_272 -> V_15 , L_156 ) ;
F_87 ( 1 ) ;
return - V_118 ;
}
for ( V_25 = V_272 -> V_603 ; V_272 -> V_604 [ V_25 ] ; V_25 ++ )
F_274 ( V_272 -> V_604 [ V_25 ] ) ;
for ( V_25 = 0 ; V_25 < V_272 -> V_603 ; V_25 ++ ) {
V_272 -> V_604 [ V_25 ] -> V_31 = F_303 ( & V_635 ) ;
V_272 -> V_604 [ V_25 ] -> V_577 = V_25 + 1 ;
}
for ( V_25 = 0 ; V_25 < V_272 -> V_603 ; V_25 ++ ) {
V_180 = F_304 ( V_272 -> V_15 , V_272 -> V_604 [ V_25 ] ) ;
if ( V_180 ) {
goto V_636;
}
}
V_180 = F_305 ( V_272 , V_634 ) ;
if ( V_180 )
goto V_636;
F_306 ( V_272 ) ;
for ( V_25 = 0 ; V_25 < V_272 -> V_603 ; V_25 ++ ) {
struct V_4 * V_5 = V_272 -> V_604 [ V_25 ] ;
unsigned long V_47 ;
if ( V_5 -> V_33 == V_34 && ( V_5 -> V_42 & V_433 ) )
V_5 -> V_33 = V_284 ;
F_258 ( & V_5 -> V_3 ) ;
if ( V_5 -> V_12 )
F_258 ( V_5 -> V_12 ) ;
V_47 = F_31 ( V_5 -> V_44 , V_5 -> V_45 ,
V_5 -> V_46 ) ;
if ( ! F_292 ( V_5 ) ) {
V_609 ( V_5 , L_157 ,
( V_5 -> V_42 & V_433 ) ? 'S' : 'P' ,
F_36 ( V_47 ) ,
V_5 -> V_3 . V_526 . V_285 ) ;
F_307 ( & V_5 -> V_3 . V_526 ) ;
} else
V_609 ( V_5 , L_158 ) ;
}
for ( V_25 = 0 ; V_25 < V_272 -> V_603 ; V_25 ++ ) {
struct V_4 * V_5 = V_272 -> V_604 [ V_25 ] ;
F_308 ( F_299 , V_5 ) ;
}
return 0 ;
V_636:
while ( -- V_25 >= 0 ) {
F_309 ( V_272 -> V_604 [ V_25 ] ) ;
}
return V_180 ;
}
int F_310 ( struct V_505 * V_272 , int V_637 ,
T_8 V_638 , unsigned long V_639 ,
struct V_633 * V_634 )
{
int V_25 , V_180 ;
V_180 = F_291 ( V_272 ) ;
if ( V_180 )
return V_180 ;
if ( ! V_637 ) {
F_87 ( V_638 ) ;
return F_302 ( V_272 , V_634 ) ;
}
V_180 = F_311 ( V_272 -> V_15 , V_637 , V_638 , V_639 ,
F_312 ( V_272 -> V_15 ) , V_272 ) ;
if ( V_180 )
return V_180 ;
for ( V_25 = 0 ; V_25 < V_272 -> V_603 ; V_25 ++ )
F_313 ( V_272 -> V_604 [ V_25 ] , L_159 , V_637 ) ;
V_180 = F_302 ( V_272 , V_634 ) ;
if ( V_180 )
F_314 ( V_272 -> V_15 , V_637 , V_272 ) ;
return V_180 ;
}
static void F_315 ( struct V_4 * V_5 )
{
unsigned long V_42 ;
if ( ! V_5 -> V_213 -> V_214 )
goto V_640;
F_67 ( V_5 -> V_209 , V_42 ) ;
V_5 -> V_210 |= V_641 ;
F_220 ( V_5 ) ;
F_68 ( V_5 -> V_209 , V_42 ) ;
F_233 ( V_5 ) ;
F_87 ( ! ( V_5 -> V_210 & V_642 ) ) ;
F_316 ( & V_5 -> V_587 ) ;
V_640:
if ( V_5 -> V_11 ) {
int V_25 ;
for ( V_25 = 0 ; V_25 < V_643 ; V_25 ++ )
F_317 ( & V_5 -> V_11 [ V_25 ] ) ;
}
F_309 ( V_5 ) ;
F_318 ( V_5 -> V_292 ) ;
}
void F_319 ( struct V_505 * V_272 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_272 -> V_603 ; V_25 ++ )
F_315 ( V_272 -> V_604 [ V_25 ] ) ;
F_320 ( V_272 ) ;
}
void F_321 ( struct V_644 * V_645 )
{
struct V_505 * V_272 = F_322 ( V_645 ) ;
F_319 ( V_272 ) ;
}
int F_323 ( struct V_644 * V_645 , const struct V_646 * V_131 )
{
unsigned long V_371 = 0 ;
switch ( V_131 -> V_647 ) {
case 1 : {
T_2 V_648 = 0 ;
F_324 ( V_645 , V_131 -> V_545 , & V_648 ) ;
V_371 = V_648 ;
break;
}
case 2 : {
T_4 V_649 = 0 ;
F_325 ( V_645 , V_131 -> V_545 , & V_649 ) ;
V_371 = V_649 ;
break;
}
case 4 : {
T_1 V_650 = 0 ;
F_326 ( V_645 , V_131 -> V_545 , & V_650 ) ;
V_371 = V_650 ;
break;
}
default:
return - V_118 ;
}
V_371 &= V_131 -> V_375 ;
return ( V_371 == V_131 -> V_546 ) ? 1 : 0 ;
}
void F_327 ( struct V_644 * V_645 , T_6 V_549 )
{
F_328 ( V_645 ) ;
F_329 ( V_645 ) ;
if ( V_549 . V_651 & V_652 )
F_330 ( V_645 , V_653 ) ;
}
int F_331 ( struct V_644 * V_645 )
{
int V_180 ;
F_330 ( V_645 , V_654 ) ;
F_332 ( V_645 ) ;
V_180 = F_333 ( V_645 ) ;
if ( V_180 ) {
F_293 ( & V_645 -> V_15 ,
L_160 , V_180 ) ;
return V_180 ;
}
F_334 ( V_645 ) ;
return 0 ;
}
int F_335 ( struct V_644 * V_645 , T_6 V_549 )
{
struct V_505 * V_272 = F_322 ( V_645 ) ;
int V_180 = 0 ;
V_180 = F_253 ( V_272 , V_549 ) ;
if ( V_180 )
return V_180 ;
F_327 ( V_645 , V_549 ) ;
return 0 ;
}
int F_336 ( struct V_644 * V_645 )
{
struct V_505 * V_272 = F_322 ( V_645 ) ;
int V_180 ;
V_180 = F_331 ( V_645 ) ;
if ( V_180 == 0 )
F_254 ( V_272 ) ;
return V_180 ;
}
int F_337 ( struct V_655 * V_645 )
{
struct V_505 * V_272 = F_338 ( V_645 ) ;
F_319 ( V_272 ) ;
return 0 ;
}
static int T_9 F_339 ( char * * V_466 ,
struct V_27 * V_656 ,
const char * * V_254 )
{
static struct V_657 V_658 [] V_659 = {
{ L_161 , . V_33 = V_354 } ,
{ L_162 , . V_33 = V_355 } ,
{ L_163 , . V_33 = V_504 } ,
{ L_164 , . V_33 = V_356 } ,
{ L_165 , . V_33 = V_357 } ,
{ L_166 , . V_33 = V_284 } ,
{ L_167 , . V_39 = 1 } ,
{ L_168 , . V_39 = 2 } ,
{ L_169 , . V_49 = V_290 } ,
{ L_170 , . V_50 = V_290 } ,
{ L_171 , . V_49 = V_269 } ,
{ L_172 , . V_47 = 1 << ( V_120 + 0 ) } ,
{ L_173 , . V_47 = 1 << ( V_120 + 1 ) } ,
{ L_174 , . V_47 = 1 << ( V_120 + 2 ) } ,
{ L_175 , . V_47 = 1 << ( V_120 + 3 ) } ,
{ L_176 , . V_47 = 1 << ( V_120 + 4 ) } ,
{ L_177 , . V_47 = 1 << ( V_120 + 5 ) } ,
{ L_178 , . V_47 = 1 << ( V_120 + 6 ) } ,
{ L_179 , . V_47 = 1 << ( V_122 + 0 ) } ,
{ L_180 , . V_47 = 1 << ( V_122 + 1 ) } ,
{ L_181 , . V_47 = 1 << ( V_122 + 2 ) } ,
{ L_182 , . V_47 = 1 << ( V_122 + 3 ) } ,
{ L_183 , . V_47 = 1 << ( V_122 + 4 ) } ,
{ L_184 , . V_47 = 1 << ( V_124 + 0 ) } ,
{ L_185 , . V_47 = 1 << ( V_124 + 0 ) } ,
{ L_186 , . V_47 = 1 << ( V_124 + 0 ) } ,
{ L_187 , . V_47 = 1 << ( V_124 + 1 ) } ,
{ L_188 , . V_47 = 1 << ( V_124 + 1 ) } ,
{ L_189 , . V_47 = 1 << ( V_124 + 1 ) } ,
{ L_190 , . V_47 = 1 << ( V_124 + 2 ) } ,
{ L_191 , . V_47 = 1 << ( V_124 + 2 ) } ,
{ L_192 , . V_47 = 1 << ( V_124 + 2 ) } ,
{ L_193 , . V_47 = 1 << ( V_124 + 3 ) } ,
{ L_194 , . V_47 = 1 << ( V_124 + 3 ) } ,
{ L_195 , . V_47 = 1 << ( V_124 + 3 ) } ,
{ L_196 , . V_47 = 1 << ( V_124 + 4 ) } ,
{ L_197 , . V_47 = 1 << ( V_124 + 4 ) } ,
{ L_198 , . V_47 = 1 << ( V_124 + 4 ) } ,
{ L_199 , . V_47 = 1 << ( V_124 + 5 ) } ,
{ L_200 , . V_47 = 1 << ( V_124 + 5 ) } ,
{ L_201 , . V_47 = 1 << ( V_124 + 5 ) } ,
{ L_202 , . V_47 = 1 << ( V_124 + 6 ) } ,
{ L_203 , . V_47 = 1 << ( V_124 + 6 ) } ,
{ L_204 , . V_47 = 1 << ( V_124 + 6 ) } ,
{ L_205 , . V_47 = 1 << ( V_124 + 7 ) } ,
{ L_206 , . V_41 = V_660 } ,
{ L_207 , . V_41 = V_661 } ,
{ L_208 , . V_41 = V_660 | V_661 } ,
{ L_209 , . V_41 = V_662 } ,
{ L_210 , . V_49 = V_341 } ,
} ;
char * V_449 = * V_466 , * V_147 = * V_466 ;
char * V_142 , * V_546 , * V_663 ;
const struct V_657 * V_664 = NULL ;
int V_665 = 0 , V_25 ;
while ( * V_147 != '\0' && * V_147 != ',' )
V_147 ++ ;
if ( * V_147 == '\0' )
* V_466 = V_147 ;
else
* V_466 = V_147 + 1 ;
* V_147 = '\0' ;
V_147 = strchr ( V_449 , ':' ) ;
if ( ! V_147 ) {
V_546 = F_340 ( V_449 ) ;
goto V_666;
}
* V_147 = '\0' ;
V_142 = F_340 ( V_449 ) ;
V_546 = F_340 ( V_147 + 1 ) ;
V_147 = strchr ( V_142 , '.' ) ;
if ( V_147 ) {
* V_147 ++ = '\0' ;
V_656 -> V_21 = F_341 ( V_147 , & V_663 , 10 ) ;
if ( V_147 == V_663 || * V_663 != '\0' ) {
* V_254 = L_211 ;
return - V_118 ;
}
}
V_656 -> V_30 = F_341 ( V_142 , & V_663 , 10 ) ;
if ( V_147 == V_663 || * V_663 != '\0' ) {
* V_254 = L_212 ;
return - V_118 ;
}
V_666:
for ( V_25 = 0 ; V_25 < F_37 ( V_658 ) ; V_25 ++ ) {
const struct V_657 * V_667 = & V_658 [ V_25 ] ;
if ( strncasecmp ( V_546 , V_667 -> V_35 , strlen ( V_546 ) ) )
continue;
V_665 ++ ;
V_664 = V_667 ;
if ( strcasecmp ( V_546 , V_667 -> V_35 ) == 0 ) {
V_665 = 1 ;
break;
}
}
if ( ! V_665 ) {
* V_254 = L_213 ;
return - V_118 ;
}
if ( V_665 > 1 ) {
* V_254 = L_214 ;
return - V_118 ;
}
V_656 -> V_32 = * V_664 ;
return 0 ;
}
static void T_9 F_342 ( void )
{
int V_668 = 0 , V_669 = 1 ;
int V_670 = - 1 , V_671 = - 1 ;
char * V_147 , * V_466 , * V_23 ;
for ( V_147 = V_672 ; * V_147 ; V_147 ++ )
if ( * V_147 == ',' )
V_669 ++ ;
V_29 = F_260 ( sizeof( V_29 [ 0 ] ) * V_669 , V_575 ) ;
if ( ! V_29 ) {
F_343 ( V_673 L_215
L_216 ) ;
return;
}
for ( V_466 = V_672 ; * V_466 != '\0' ; V_466 = V_23 ) {
const char * V_254 = L_67 ;
struct V_27 V_674 = { . V_30 = - 1 , . V_21 = - 1 } ;
V_23 = V_466 ;
if ( F_339 ( & V_23 , & V_674 , & V_254 ) ) {
F_343 ( V_673 L_217
L_218 ,
V_466 , V_254 ) ;
continue;
}
if ( V_674 . V_30 == - 1 ) {
V_674 . V_30 = V_670 ;
V_674 . V_21 = V_671 ;
}
V_29 [ V_668 ++ ] = V_674 ;
V_670 = V_674 . V_30 ;
V_671 = V_674 . V_21 ;
}
V_26 = V_668 ;
}
static int T_9 F_344 ( void )
{
int V_180 ;
F_342 () ;
F_345 () ;
V_180 = F_346 () ;
if ( V_180 ) {
F_274 ( V_29 ) ;
return V_180 ;
}
F_347 () ;
V_675 = F_348 () ;
if ( ! V_675 ) {
F_349 () ;
V_180 = - V_616 ;
goto V_263;
}
F_343 ( V_270 L_219 V_676 L_220 ) ;
return 0 ;
V_263:
return V_180 ;
}
static void T_10 F_350 ( void )
{
F_351 ( V_675 ) ;
F_352 () ;
F_349 () ;
F_353 () ;
F_274 ( V_29 ) ;
}
int F_354 ( void )
{
return F_355 ( & V_677 ) ;
}
void F_173 ( struct V_4 * V_5 , unsigned int V_678 )
{
bool V_679 = V_5 && V_5 -> V_272 -> V_680 == V_681 ;
if ( V_679 )
F_77 ( V_5 ) ;
F_179 ( V_678 ) ;
if ( V_679 )
F_80 ( V_5 ) ;
}
T_1 F_356 ( struct V_4 * V_5 , void T_11 * V_545 , T_1 V_375 , T_1 V_546 ,
unsigned long V_462 , unsigned long V_202 )
{
unsigned long V_448 ;
T_1 V_371 ;
V_371 = F_357 ( V_545 ) ;
V_448 = F_168 ( V_450 , V_202 ) ;
while ( ( V_371 & V_375 ) == V_546 && F_172 ( V_450 , V_448 ) ) {
F_173 ( V_5 , V_462 ) ;
V_371 = F_357 ( V_545 ) ;
}
return V_371 ;
}
static unsigned int F_358 ( struct V_192 * V_193 )
{
return V_212 ;
}
static void F_359 ( struct V_4 * V_5 )
{
}
int F_360 ( const struct V_4 * V_5 , const char * V_682 ,
const char * V_683 , ... )
{
struct V_684 V_685 ;
T_12 args ;
int V_686 ;
va_start ( args , V_683 ) ;
V_685 . V_683 = V_683 ;
V_685 . V_687 = & args ;
V_686 = F_343 ( L_221 , V_682 , V_5 -> V_31 , & V_685 ) ;
va_end ( args ) ;
return V_686 ;
}
int F_361 ( const struct V_2 * V_3 , const char * V_682 ,
const char * V_683 , ... )
{
struct V_684 V_685 ;
T_12 args ;
int V_686 ;
va_start ( args , V_683 ) ;
V_685 . V_683 = V_683 ;
V_685 . V_687 = & args ;
if ( F_4 ( V_3 -> V_5 ) || V_3 -> V_5 -> V_12 )
V_686 = F_343 ( L_222 ,
V_682 , V_3 -> V_5 -> V_31 , V_3 -> V_38 , & V_685 ) ;
else
V_686 = F_343 ( L_221 ,
V_682 , V_3 -> V_5 -> V_31 , & V_685 ) ;
va_end ( args ) ;
return V_686 ;
}
int F_362 ( const struct V_14 * V_15 , const char * V_682 ,
const char * V_683 , ... )
{
struct V_684 V_685 ;
T_12 args ;
int V_686 ;
va_start ( args , V_683 ) ;
V_685 . V_683 = V_683 ;
V_685 . V_687 = & args ;
V_686 = F_343 ( L_222 ,
V_682 , V_15 -> V_3 -> V_5 -> V_31 , V_15 -> V_3 -> V_38 + V_15 -> V_24 ,
& V_685 ) ;
va_end ( args ) ;
return V_686 ;
}
void F_363 ( const struct V_21 * V_15 , const char * V_688 )
{
F_364 ( V_270 , V_15 , L_223 , V_688 ) ;
}
