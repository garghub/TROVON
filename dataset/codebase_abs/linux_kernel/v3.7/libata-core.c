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
V_193 -> V_42 |= V_223 ;
V_193 -> V_198 = V_198 ;
if ( V_198 != V_161 ) {
unsigned int V_25 , V_224 = 0 ;
struct V_199 * V_225 ;
F_73 (sgl, sg, n_elem, i)
V_224 += V_225 -> V_226 ;
F_74 ( V_193 , V_200 , V_201 ) ;
V_193 -> V_227 = V_224 ;
}
V_193 -> V_196 = & V_208 ;
V_193 -> V_228 = F_63 ;
F_75 ( V_193 ) ;
F_68 ( V_5 -> V_209 , V_42 ) ;
if ( ! V_202 ) {
if ( V_229 )
V_202 = V_229 * 1000 ;
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
if ( V_193 -> V_42 & V_230 ) {
V_193 -> V_157 |= V_231 ;
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
if ( V_5 -> V_213 -> V_232 )
V_5 -> V_213 -> V_232 ( V_193 ) ;
if ( V_193 -> V_42 & V_233 ) {
if ( V_193 -> V_234 . V_71 & ( V_235 | V_236 ) )
V_193 -> V_157 |= V_162 ;
if ( ! V_193 -> V_157 )
V_193 -> V_157 |= V_237 ;
if ( V_193 -> V_157 & ~ V_237 )
V_193 -> V_157 &= ~ V_237 ;
}
F_67 ( V_5 -> V_209 , V_42 ) ;
* V_68 = V_193 -> V_234 ;
V_157 = V_193 -> V_157 ;
F_85 ( V_193 ) ;
V_3 -> V_217 = V_204 ;
V_3 -> V_218 = V_205 ;
V_5 -> V_219 = V_206 ;
V_5 -> V_220 = V_207 ;
F_68 ( V_5 -> V_209 , V_42 ) ;
if ( ( V_157 & V_231 ) && V_203 )
F_86 ( V_15 , V_71 ) ;
return V_157 ;
}
unsigned F_53 ( struct V_14 * V_15 ,
struct V_67 * V_68 , const T_2 * V_197 ,
int V_198 , void * V_238 , unsigned int V_224 ,
unsigned long V_202 )
{
struct V_199 * V_239 = NULL , V_225 ;
unsigned int V_201 = 0 ;
if ( V_198 != V_161 ) {
F_87 ( ! V_238 ) ;
F_88 ( & V_225 , V_238 , V_224 ) ;
V_239 = & V_225 ;
V_201 ++ ;
}
return F_65 ( V_15 , V_68 , V_197 , V_198 , V_239 , V_201 ,
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
unsigned int F_90 ( const struct V_14 * V_240 )
{
if ( V_240 -> V_3 -> V_5 -> V_210 & V_241 )
return 0 ;
if ( V_240 -> V_3 -> V_5 -> V_42 & V_242 )
return 0 ;
if ( F_62 ( V_240 -> V_142 )
&& ( V_240 -> V_243 == V_244 || V_240 -> V_243 == V_245 ) )
return 0 ;
if ( V_240 -> V_243 > V_246 )
return 1 ;
if ( F_91 ( V_240 -> V_142 ) )
return 1 ;
return 0 ;
}
static T_1 F_92 ( const struct V_14 * V_240 )
{
if ( V_240 -> V_142 [ V_184 ] & 2 ) {
T_4 V_188 = V_240 -> V_142 [ V_247 ] ;
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
return F_53 ( V_15 , V_68 , NULL , V_248 ,
V_142 , sizeof( V_142 [ 0 ] ) * V_249 , 0 ) ;
}
int F_94 ( struct V_14 * V_15 , unsigned int * V_250 ,
unsigned int V_42 , T_4 * V_142 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
unsigned int V_181 = * V_250 ;
struct V_67 V_68 ;
unsigned int V_157 = 0 ;
const char * V_251 ;
bool V_252 = V_181 == V_140 ;
int V_253 = 1 , V_254 = 0 ;
int V_180 ;
if ( F_95 ( V_5 ) )
F_96 ( V_15 , L_59 , V_255 ) ;
V_256:
F_52 ( V_15 , & V_68 ) ;
switch ( V_181 ) {
case V_140 :
V_181 = V_137 ;
case V_137 :
V_68 . V_71 = V_257 ;
break;
case V_138 :
V_68 . V_71 = V_258 ;
break;
default:
V_180 = - V_259 ;
V_251 = L_60 ;
goto V_260;
}
V_68 . V_92 = V_93 ;
V_68 . V_42 |= V_108 | V_109 ;
V_68 . V_42 |= V_261 ;
if ( V_5 -> V_213 -> V_262 )
V_157 = V_5 -> V_213 -> V_262 ( V_15 , & V_68 , V_142 ) ;
else
V_157 = F_93 ( V_15 , & V_68 , V_142 ) ;
if ( V_157 ) {
if ( V_157 & V_263 ) {
F_96 ( V_15 , L_61 ) ;
return - V_264 ;
}
if ( V_252 ) {
F_57 ( V_15 ,
L_62 ) ;
* V_250 = V_265 ;
return 0 ;
}
if ( ( V_157 == V_162 ) && ( V_68 . V_72 & V_163 ) ) {
if ( V_253 ) {
V_253 = 0 ;
if ( V_181 == V_137 )
V_181 = V_138 ;
else
V_181 = V_137 ;
goto V_256;
}
F_96 ( V_15 ,
L_63 ) ;
return - V_264 ;
}
V_180 = - V_165 ;
V_251 = L_64 ;
goto V_260;
}
if ( V_15 -> V_48 & V_266 ) {
F_96 ( V_15 , L_65
L_66 ,
V_181 , V_253 , V_254 ) ;
F_97 ( V_267 , L_67 , V_268 ,
16 , 2 , V_142 , V_249 * sizeof( * V_142 ) , true ) ;
}
V_253 = 0 ;
F_98 ( V_142 , V_249 ) ;
V_180 = - V_118 ;
V_251 = L_68 ;
if ( V_181 == V_137 ) {
if ( ! F_99 ( V_142 ) && ! F_62 ( V_142 ) )
goto V_260;
if ( V_5 -> V_269 -> V_42 & V_270 &&
F_99 ( V_142 ) ) {
F_96 ( V_15 ,
L_69 ) ;
return - V_264 ;
}
} else {
if ( F_99 ( V_142 ) )
goto V_260;
}
if ( ! V_254 && ( V_142 [ 2 ] == 0x37c8 || V_142 [ 2 ] == 0x738c ) ) {
V_254 = 1 ;
V_157 = F_100 ( V_15 , V_271 , 0 ) ;
if ( V_157 && V_142 [ 2 ] != 0x738c ) {
V_180 = - V_165 ;
V_251 = L_70 ;
goto V_260;
}
if ( V_142 [ 2 ] == 0x37c8 )
goto V_256;
}
if ( ( V_42 & V_272 ) && V_181 == V_137 ) {
if ( F_101 ( V_142 ) < 4 || ! F_44 ( V_142 ) ) {
V_157 = F_102 ( V_15 , V_142 [ 3 ] , V_142 [ 6 ] ) ;
if ( V_157 ) {
V_180 = - V_165 ;
V_251 = L_71 ;
goto V_260;
}
V_42 &= ~ V_272 ;
goto V_256;
}
}
* V_250 = V_181 ;
return 0 ;
V_260:
if ( F_84 ( V_5 ) )
F_24 ( V_15 , L_72 ,
V_251 , V_157 ) ;
return V_180 ;
}
static int F_103 ( struct V_14 * V_15 )
{
struct V_2 * V_273 = F_9 ( V_15 ) ;
T_1 V_274 , V_275 ;
if ( ! F_104 ( V_273 ) )
return 0 ;
if ( V_15 -> V_48 & V_276 )
V_274 = 1 ;
else
return 0 ;
V_275 = ( 1 << V_274 ) - 1 ;
if ( V_273 -> V_277 <= V_275 )
return 0 ;
V_273 -> V_277 = V_275 ;
if ( V_273 -> V_278 > V_274 ) {
F_57 ( V_15 , L_73 ,
F_38 ( V_274 ) ) ;
return - V_279 ;
}
return 0 ;
}
static inline T_2 F_105 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
if ( F_106 ( V_15 ) & V_280 )
return 0 ;
return ( ( V_5 -> V_33 == V_281 ) && ( ! F_107 ( V_15 -> V_142 ) ) ) ;
}
static int F_108 ( struct V_14 * V_15 ,
char * V_282 , T_5 V_283 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
int V_284 = 0 , V_285 = F_109 ( V_15 -> V_142 ) ;
unsigned int V_157 ;
char * V_286 = L_67 ;
if ( ! F_110 ( V_15 -> V_142 ) ) {
V_282 [ 0 ] = '\0' ;
return 0 ;
}
if ( V_15 -> V_48 & V_287 ) {
snprintf ( V_282 , V_283 , L_74 ) ;
return 0 ;
}
if ( V_5 -> V_42 & V_288 ) {
V_284 = F_111 ( V_5 -> V_289 -> V_290 , V_291 - 1 ) ;
V_15 -> V_42 |= V_292 ;
}
if ( ! ( V_15 -> V_48 & V_293 ) &&
( V_5 -> V_42 & V_294 ) &&
F_112 ( V_15 -> V_142 ) ) {
V_157 = F_100 ( V_15 , V_295 ,
V_296 ) ;
if ( V_157 ) {
F_59 ( V_15 ,
L_75 ,
V_157 ) ;
if ( V_157 != V_162 ) {
V_15 -> V_48 |= V_293 ;
return - V_165 ;
}
} else
V_286 = L_76 ;
}
if ( V_284 >= V_285 )
snprintf ( V_282 , V_283 , L_77 , V_285 , V_286 ) ;
else
snprintf ( V_282 , V_283 , L_78 , V_284 ,
V_285 , V_286 ) ;
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
char V_297 [ 7 ] ;
char V_298 [ V_299 + 1 ] ;
char V_300 [ V_301 + 1 ] ;
int V_180 ;
if ( ! F_8 ( V_15 ) && F_114 ( V_5 ) ) {
F_57 ( V_15 , L_79 , V_255 ) ;
return 0 ;
}
if ( F_115 ( V_5 ) )
F_96 ( V_15 , L_59 , V_255 ) ;
V_15 -> V_48 |= F_106 ( V_15 ) ;
F_18 ( V_15 ) ;
if ( V_15 -> V_48 & V_302 ) {
F_57 ( V_15 , L_80 ) ;
F_116 ( V_15 ) ;
return 0 ;
}
if ( ( ! V_303 || ( V_5 -> V_42 & V_304 ) ) &&
V_15 -> V_181 == V_138 ) {
F_24 ( V_15 , L_81 ,
V_303 ? L_82
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
V_255 ,
V_142 [ 49 ] , V_142 [ 82 ] , V_142 [ 83 ] , V_142 [ 84 ] ,
V_142 [ 85 ] , V_142 [ 86 ] , V_142 [ 87 ] , V_142 [ 88 ] ) ;
V_15 -> V_42 &= ~ V_305 ;
V_15 -> V_156 = 0 ;
V_15 -> V_306 = 0 ;
V_15 -> V_307 = 0 ;
V_15 -> V_308 = 0 ;
V_15 -> V_103 = 0 ;
V_15 -> V_104 = 0 ;
V_15 -> V_94 = 0 ;
V_47 = F_61 ( V_142 ) ;
if ( F_115 ( V_5 ) )
F_60 ( V_142 ) ;
F_41 ( V_15 -> V_142 , V_298 , V_309 ,
sizeof( V_298 ) ) ;
F_41 ( V_15 -> V_142 , V_300 , V_310 ,
sizeof( V_300 ) ) ;
if ( V_15 -> V_181 == V_137 ) {
if ( F_62 ( V_142 ) ) {
if ( V_142 [ V_311 ] & 1 )
F_24 ( V_15 ,
L_86 ) ;
snprintf ( V_297 , 7 , L_87 ) ;
} else {
snprintf ( V_297 , 7 , L_88 , F_101 ( V_142 ) ) ;
if ( F_118 ( V_142 ) )
F_24 ( V_15 ,
L_86 ) ;
}
V_15 -> V_307 = F_43 ( V_142 ) ;
if ( ( V_15 -> V_142 [ 47 ] >> 8 ) == 0x80 && ( V_15 -> V_142 [ 59 ] & 0x100 ) ) {
unsigned int V_312 = V_15 -> V_142 [ 47 ] & 0xff ;
unsigned int V_313 = V_15 -> V_142 [ 59 ] & 0xff ;
if ( F_119 ( V_312 ) && F_119 ( V_313 ) )
if ( V_313 <= V_312 )
V_15 -> V_94 = V_313 ;
}
if ( F_44 ( V_142 ) ) {
const char * V_314 ;
char V_315 [ 24 ] ;
V_314 = L_89 ;
V_15 -> V_42 |= V_116 ;
if ( F_45 ( V_142 ) ) {
V_15 -> V_42 |= V_117 ;
V_314 = L_90 ;
if ( V_15 -> V_307 >= ( 1UL << 28 ) &&
F_120 ( V_142 ) )
V_15 -> V_42 |= V_316 ;
}
V_180 = F_108 ( V_15 , V_315 , sizeof( V_315 ) ) ;
if ( V_180 )
return V_180 ;
if ( F_121 ( V_5 ) && V_174 ) {
F_57 ( V_15 , L_91 ,
V_297 , V_300 , V_298 ,
F_36 ( V_47 ) ) ;
F_57 ( V_15 ,
L_92 ,
( unsigned long long ) V_15 -> V_307 ,
V_15 -> V_94 , V_314 , V_315 ) ;
}
} else {
V_15 -> V_308 = V_142 [ 1 ] ;
V_15 -> V_103 = V_142 [ 3 ] ;
V_15 -> V_104 = V_142 [ 6 ] ;
if ( F_48 ( V_142 ) ) {
V_15 -> V_308 = V_142 [ 54 ] ;
V_15 -> V_103 = V_142 [ 55 ] ;
V_15 -> V_104 = V_142 [ 56 ] ;
}
if ( F_121 ( V_5 ) && V_174 ) {
F_57 ( V_15 , L_91 ,
V_297 , V_300 , V_298 ,
F_36 ( V_47 ) ) ;
F_57 ( V_15 ,
L_93 ,
( unsigned long long ) V_15 -> V_307 ,
V_15 -> V_94 , V_15 -> V_308 ,
V_15 -> V_103 , V_15 -> V_104 ) ;
}
}
if ( F_122 ( V_15 -> V_142 ) )
V_15 -> V_42 |= V_317 ;
if ( F_110 ( V_15 -> V_142 ) ) {
V_157 = F_123 ( V_15 ,
V_318 ,
V_319 ,
V_15 -> V_320 ,
1 ) ;
if ( V_157 )
F_96 ( V_15 ,
L_94 ,
V_157 ) ;
}
V_15 -> V_306 = 16 ;
}
else if ( V_15 -> V_181 == V_138 ) {
const char * V_321 = L_67 ;
const char * V_322 = L_67 ;
const char * V_323 = L_67 ;
T_1 V_324 ;
V_180 = F_124 ( V_142 ) ;
if ( ( V_180 < 12 ) || ( V_180 > V_222 ) ) {
if ( F_84 ( V_5 ) )
F_24 ( V_15 , L_95 ) ;
V_180 = - V_118 ;
goto V_325;
}
V_15 -> V_306 = ( unsigned int ) V_180 ;
if ( V_326 &&
( V_5 -> V_42 & V_327 ) && F_125 ( V_142 ) &&
( ! F_4 ( V_5 ) ||
F_126 ( & V_5 -> V_3 , V_328 , & V_324 ) == 0 ) ) {
V_157 = F_100 ( V_15 ,
V_295 , V_329 ) ;
if ( V_157 )
F_59 ( V_15 ,
L_96 ,
V_157 ) ;
else {
V_15 -> V_42 |= V_330 ;
V_322 = L_97 ;
}
}
if ( F_127 ( V_15 -> V_142 ) ) {
V_15 -> V_42 |= V_331 ;
V_321 = L_98 ;
}
if ( V_332 || F_128 ( V_15 -> V_142 ) ) {
V_15 -> V_42 |= V_333 ;
V_323 = L_99 ;
}
if ( F_129 ( V_15 -> V_142 ) )
V_15 -> V_42 |= V_334 ;
if ( F_121 ( V_5 ) && V_174 )
F_57 ( V_15 ,
L_100 ,
V_300 , V_298 ,
F_36 ( V_47 ) ,
V_321 , V_322 ,
V_323 ) ;
}
V_15 -> V_156 = V_335 ;
if ( V_15 -> V_42 & V_117 )
V_15 -> V_156 = V_336 ;
if ( F_105 ( V_15 ) ) {
if ( F_121 ( V_5 ) && V_174 )
F_57 ( V_15 , L_101 ) ;
V_15 -> V_46 &= V_337 ;
V_15 -> V_156 = V_335 ;
}
if ( ( V_15 -> V_181 == V_138 ) &&
( F_130 ( V_142 ) == V_338 ) ) {
V_15 -> V_156 = V_339 ;
V_15 -> V_48 |= V_340 ;
}
if ( V_15 -> V_48 & V_341 )
V_15 -> V_156 = F_131 (unsigned int, ATA_MAX_SECTORS_128,
dev->max_sectors) ;
if ( V_5 -> V_213 -> V_342 )
V_5 -> V_213 -> V_342 ( V_15 ) ;
if ( V_15 -> V_48 & V_343 ) {
if ( V_174 ) {
F_24 ( V_15 ,
L_102 ) ;
F_24 ( V_15 ,
L_103 ) ;
}
}
if ( ( V_15 -> V_48 & V_344 ) && V_174 ) {
F_24 ( V_15 , L_104 ) ;
F_24 ( V_15 , L_105 ) ;
}
return 0 ;
V_325:
if ( F_115 ( V_5 ) )
F_96 ( V_15 , L_106 , V_255 ) ;
return V_180 ;
}
int F_132 ( struct V_4 * V_5 )
{
return V_345 ;
}
int F_133 ( struct V_4 * V_5 )
{
return V_346 ;
}
int F_134 ( struct V_4 * V_5 )
{
return V_347 ;
}
int F_135 ( struct V_4 * V_5 )
{
return V_348 ;
}
int F_136 ( struct V_4 * V_5 )
{
return V_281 ;
}
int F_137 ( struct V_4 * V_5 )
{
unsigned int V_349 [ V_350 ] ;
int V_351 [ V_350 ] ;
int V_180 ;
struct V_14 * V_15 ;
F_138 (dev, &ap->link, ALL)
V_351 [ V_15 -> V_24 ] = V_352 ;
V_256:
F_138 (dev, &ap->link, ALL) {
V_15 -> V_243 = V_353 ;
if ( V_5 -> V_213 -> V_354 )
V_5 -> V_213 -> V_354 ( V_5 , V_15 ) ;
}
V_5 -> V_213 -> V_355 ( V_5 ) ;
F_138 (dev, &ap->link, ALL) {
if ( V_15 -> V_181 != V_141 )
V_349 [ V_15 -> V_24 ] = V_15 -> V_181 ;
else
V_349 [ V_15 -> V_24 ] = V_356 ;
V_15 -> V_181 = V_141 ;
}
F_138 (dev, &ap->link, ALL_REVERSE) {
if ( V_351 [ V_15 -> V_24 ] )
V_15 -> V_181 = V_349 [ V_15 -> V_24 ] ;
if ( ! F_8 ( V_15 ) )
continue;
V_180 = F_94 ( V_15 , & V_15 -> V_181 , V_272 ,
V_15 -> V_142 ) ;
if ( V_180 )
goto V_357;
}
if ( V_5 -> V_213 -> V_358 )
V_5 -> V_33 = V_5 -> V_213 -> V_358 ( V_5 ) ;
F_138 (dev, &ap->link, ENABLED)
if ( F_107 ( V_15 -> V_142 ) )
V_5 -> V_33 = V_281 ;
F_138 (dev, &ap->link, ENABLED) {
V_5 -> V_3 . V_173 . V_25 . V_42 |= V_175 ;
V_180 = F_113 ( V_15 ) ;
V_5 -> V_3 . V_173 . V_25 . V_42 &= ~ V_175 ;
if ( V_180 )
goto V_357;
}
V_180 = F_139 ( & V_5 -> V_3 , & V_15 ) ;
if ( V_180 )
goto V_357;
F_138 (dev, &ap->link, ENABLED)
return 0 ;
return - V_259 ;
V_357:
V_351 [ V_15 -> V_24 ] -- ;
switch ( V_180 ) {
case - V_118 :
V_351 [ V_15 -> V_24 ] = 0 ;
break;
case - V_259 :
V_351 [ V_15 -> V_24 ] = F_111 ( V_351 [ V_15 -> V_24 ] , 1 ) ;
case - V_165 :
if ( V_351 [ V_15 -> V_24 ] == 1 ) {
F_140 ( & V_5 -> V_3 , 0 ) ;
F_141 ( V_15 , V_359 ) ;
}
}
if ( ! V_351 [ V_15 -> V_24 ] )
F_116 ( V_15 ) ;
goto V_256;
}
static void F_142 ( struct V_2 * V_3 )
{
T_1 V_1 , V_360 , V_361 ;
if ( F_126 ( V_3 , V_362 , & V_1 ) )
return;
F_126 ( V_3 , V_363 , & V_360 ) ;
if ( F_143 ( V_3 ) ) {
V_361 = ( V_1 >> 4 ) & 0xf ;
F_144 ( V_3 , L_107 ,
F_38 ( V_361 ) , V_1 , V_360 ) ;
} else {
F_144 ( V_3 , L_108 ,
V_1 , V_360 ) ;
}
}
struct V_14 * F_145 ( struct V_14 * V_240 )
{
struct V_2 * V_3 = V_240 -> V_3 ;
struct V_14 * V_364 = & V_3 -> V_21 [ 1 - V_240 -> V_24 ] ;
if ( ! F_8 ( V_364 ) )
return NULL ;
return V_364 ;
}
int F_140 ( struct V_2 * V_3 , T_1 V_39 )
{
T_1 V_1 , V_135 , V_365 ;
int V_180 , V_366 ;
if ( ! F_104 ( V_3 ) )
return - V_367 ;
V_180 = F_126 ( V_3 , V_362 , & V_1 ) ;
if ( V_180 == 0 && F_1 ( V_1 ) )
V_135 = ( V_1 >> 4 ) & 0xf ;
else
V_135 = V_3 -> V_278 ;
V_365 = V_3 -> V_277 ;
if ( V_365 <= 1 )
return - V_118 ;
V_366 = F_33 ( V_365 ) - 1 ;
V_365 &= ~ ( 1 << V_366 ) ;
if ( V_135 > 1 )
V_365 &= ( 1 << ( V_135 - 1 ) ) - 1 ;
else
V_365 &= 1 ;
if ( ! V_365 )
return - V_118 ;
if ( V_39 ) {
if ( V_365 & ( ( 1 << V_39 ) - 1 ) )
V_365 &= ( 1 << V_39 ) - 1 ;
else {
V_366 = F_146 ( V_365 ) - 1 ;
V_365 = 1 << V_366 ;
}
}
V_3 -> V_277 = V_365 ;
F_147 ( V_3 , L_109 ,
F_38 ( F_33 ( V_365 ) ) ) ;
return 0 ;
}
static int F_148 ( struct V_2 * V_3 , T_1 * V_360 )
{
struct V_2 * V_368 = & V_3 -> V_5 -> V_3 ;
T_1 V_369 , V_274 , V_135 ;
V_369 = V_3 -> V_277 ;
if ( ! F_13 ( V_3 ) && V_368 -> V_278 )
V_369 &= ( 1 << V_368 -> V_278 ) - 1 ;
if ( V_369 == V_370 )
V_274 = 0 ;
else
V_274 = F_33 ( V_369 ) ;
V_135 = ( * V_360 >> 4 ) & 0xf ;
* V_360 = ( * V_360 & ~ 0xf0 ) | ( ( V_274 & 0xf ) << 4 ) ;
return V_135 != V_274 ;
}
static int F_149 ( struct V_2 * V_3 )
{
T_1 V_360 ;
if ( F_126 ( V_3 , V_363 , & V_360 ) )
return 1 ;
return F_148 ( V_3 , & V_360 ) ;
}
int F_150 ( struct V_2 * V_3 )
{
T_1 V_360 ;
int V_180 ;
if ( ( V_180 = F_126 ( V_3 , V_363 , & V_360 ) ) )
return V_180 ;
if ( ! F_148 ( V_3 , & V_360 ) )
return 0 ;
if ( ( V_180 = F_151 ( V_3 , V_363 , V_360 ) ) )
return V_180 ;
return 1 ;
}
static void F_152 ( const struct V_371 * V_372 , struct V_371 * V_373 , int V_374 , int V_375 )
{
V_373 -> V_376 = F_153 ( V_372 -> V_376 * 1000 , V_374 ) ;
V_373 -> V_377 = F_153 ( V_372 -> V_377 * 1000 , V_374 ) ;
V_373 -> V_378 = F_153 ( V_372 -> V_378 * 1000 , V_374 ) ;
V_373 -> V_379 = F_153 ( V_372 -> V_379 * 1000 , V_374 ) ;
V_373 -> V_380 = F_153 ( V_372 -> V_380 * 1000 , V_374 ) ;
V_373 -> V_381 = F_153 ( V_372 -> V_381 * 1000 , V_374 ) ;
V_373 -> V_382 = F_153 ( V_372 -> V_382 * 1000 , V_374 ) ;
V_373 -> V_383 = F_153 ( V_372 -> V_383 * 1000 , V_374 ) ;
V_373 -> V_384 = F_153 ( V_372 -> V_384 * 1000 , V_375 ) ;
}
void F_154 ( const struct V_371 * V_385 , const struct V_371 * V_386 ,
struct V_371 * V_387 , unsigned int V_388 )
{
if ( V_388 & V_389 ) V_387 -> V_376 = V_312 ( V_385 -> V_376 , V_386 -> V_376 ) ;
if ( V_388 & V_390 ) V_387 -> V_377 = V_312 ( V_385 -> V_377 , V_386 -> V_377 ) ;
if ( V_388 & V_391 ) V_387 -> V_378 = V_312 ( V_385 -> V_378 , V_386 -> V_378 ) ;
if ( V_388 & V_392 ) V_387 -> V_379 = V_312 ( V_385 -> V_379 , V_386 -> V_379 ) ;
if ( V_388 & V_393 ) V_387 -> V_380 = V_312 ( V_385 -> V_380 , V_386 -> V_380 ) ;
if ( V_388 & V_394 ) V_387 -> V_381 = V_312 ( V_385 -> V_381 , V_386 -> V_381 ) ;
if ( V_388 & V_395 ) V_387 -> V_382 = V_312 ( V_385 -> V_382 , V_386 -> V_382 ) ;
if ( V_388 & V_396 ) V_387 -> V_383 = V_312 ( V_385 -> V_383 , V_386 -> V_383 ) ;
if ( V_388 & V_397 ) V_387 -> V_384 = V_312 ( V_385 -> V_384 , V_386 -> V_384 ) ;
}
const struct V_371 * F_155 ( T_2 V_133 )
{
const struct V_371 * V_372 = V_371 ;
while ( V_133 > V_372 -> V_7 )
V_372 ++ ;
if ( V_133 == V_372 -> V_7 )
return V_372 ;
F_156 ( true , L_110 ,
V_255 , V_133 ) ;
return NULL ;
}
int F_157 ( struct V_14 * V_240 , unsigned short V_398 ,
struct V_371 * V_372 , int V_374 , int V_375 )
{
const T_4 * V_142 = V_240 -> V_142 ;
const struct V_371 * V_143 ;
struct V_371 V_147 ;
if ( ! ( V_143 = F_155 ( V_398 ) ) )
return - V_118 ;
memcpy ( V_372 , V_143 , sizeof( * V_143 ) ) ;
if ( V_142 [ V_184 ] & 2 ) {
memset ( & V_147 , 0 , sizeof( V_147 ) ) ;
if ( V_398 >= V_353 && V_398 < V_399 ) {
if ( V_398 <= V_246 )
V_147 . V_383 = V_147 . V_379 = V_142 [ V_247 ] ;
else if ( ( V_398 <= V_400 ) ||
( V_398 == V_244 && ! F_62 ( V_142 ) ) )
V_147 . V_383 = V_147 . V_379 = V_142 [ V_401 ] ;
} else if ( V_398 >= V_402 && V_398 <= V_403 )
V_147 . V_383 = V_142 [ V_404 ] ;
F_154 ( & V_147 , V_372 , V_372 , V_396 | V_392 ) ;
}
F_152 ( V_372 , V_372 , V_374 , V_375 ) ;
if ( V_398 > V_245 ) {
F_157 ( V_240 , V_240 -> V_243 , & V_147 , V_374 , V_375 ) ;
F_154 ( & V_147 , V_372 , V_372 , V_405 ) ;
}
if ( V_372 -> V_377 + V_372 -> V_378 < V_372 -> V_379 ) {
V_372 -> V_377 += ( V_372 -> V_379 - ( V_372 -> V_377 + V_372 -> V_378 ) ) / 2 ;
V_372 -> V_378 = V_372 -> V_379 - V_372 -> V_377 ;
}
if ( V_372 -> V_380 + V_372 -> V_381 < V_372 -> V_383 ) {
V_372 -> V_380 += ( V_372 -> V_383 - ( V_372 -> V_380 + V_372 -> V_381 ) ) / 2 ;
V_372 -> V_381 = V_372 -> V_383 - V_372 -> V_380 ;
}
if ( V_372 -> V_380 + V_372 -> V_381 > V_372 -> V_383 )
V_372 -> V_383 = V_372 -> V_380 + V_372 -> V_381 ;
return 0 ;
}
T_2 F_158 ( unsigned int V_406 , int V_383 )
{
T_2 V_407 = 0xff , V_408 = 0xff ;
const struct V_127 * V_128 ;
const struct V_371 * V_372 ;
for ( V_128 = V_129 ; V_128 -> V_130 >= 0 ; V_128 ++ )
if ( V_128 -> V_130 == V_406 )
V_407 = V_128 -> V_132 ;
for ( V_372 = F_155 ( V_407 ) ;
V_372 && F_35 ( V_372 -> V_7 ) == V_406 ; V_372 ++ ) {
unsigned short V_409 ;
switch ( V_406 ) {
case V_120 :
case V_122 :
V_409 = V_372 -> V_383 ;
break;
case V_124 :
V_409 = V_372 -> V_384 ;
break;
default:
return 0xff ;
}
if ( V_383 > V_409 )
break;
V_408 = V_372 -> V_7 ;
}
return V_408 ;
}
int F_141 ( struct V_14 * V_15 , unsigned int V_410 )
{
char V_238 [ 32 ] ;
unsigned long V_411 , V_47 ;
unsigned long V_44 , V_45 , V_46 ;
int V_412 , V_126 ;
V_412 = ! ! ( V_410 & V_413 ) ;
V_410 &= ~ V_413 ;
V_47 = V_411 = F_31 ( V_15 -> V_44 ,
V_15 -> V_45 ,
V_15 -> V_46 ) ;
F_16 ( V_47 , & V_44 , & V_45 , & V_46 ) ;
switch ( V_410 ) {
case V_359 :
V_126 = F_33 ( V_44 ) - 1 ;
V_44 &= ~ ( 1 << V_126 ) ;
break;
case V_414 :
if ( V_46 ) {
V_126 = F_33 ( V_46 ) - 1 ;
V_46 &= ~ ( 1 << V_126 ) ;
if ( ! V_46 )
return - V_264 ;
} else if ( V_45 ) {
V_126 = F_33 ( V_45 ) - 1 ;
V_45 &= ~ ( 1 << V_126 ) ;
if ( ! V_45 )
return - V_264 ;
}
break;
case V_415 :
V_46 &= V_416 ;
break;
case V_417 :
V_44 &= 1 ;
case V_418 :
V_45 = 0 ;
V_46 = 0 ;
break;
default:
F_70 () ;
}
V_47 &= F_31 ( V_44 , V_45 , V_46 ) ;
if ( ! ( V_47 & V_121 ) || V_47 == V_411 )
return - V_264 ;
if ( ! V_412 ) {
if ( V_47 & ( V_123 | V_125 ) )
snprintf ( V_238 , sizeof( V_238 ) , L_111 ,
F_36 ( V_47 ) ,
F_36 ( V_47 & V_121 ) ) ;
else
snprintf ( V_238 , sizeof( V_238 ) , L_112 ,
F_36 ( V_47 ) ) ;
F_24 ( V_15 , L_113 , V_238 ) ;
}
F_16 ( V_47 , & V_15 -> V_44 , & V_15 -> V_45 ,
& V_15 -> V_46 ) ;
return 0 ;
}
static int F_159 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_171 * V_172 = & V_15 -> V_3 -> V_173 ;
const bool V_419 = V_15 -> V_48 & V_420 ;
const char * V_421 = L_67 ;
int V_422 = 0 ;
unsigned int V_157 = 0 ;
int V_180 ;
V_15 -> V_42 &= ~ V_91 ;
if ( V_15 -> V_406 == V_120 )
V_15 -> V_42 |= V_91 ;
if ( V_419 && V_5 -> V_42 & V_423 && F_107 ( V_15 -> V_142 ) )
V_421 = L_114 ;
else {
if ( V_419 )
F_24 ( V_15 ,
L_115
L_116 ) ;
V_157 = F_160 ( V_15 ) ;
}
if ( V_157 & ~ V_162 )
goto V_357;
V_172 -> V_25 . V_42 |= V_424 ;
V_180 = F_161 ( V_15 , V_141 , 0 ) ;
V_172 -> V_25 . V_42 &= ~ V_424 ;
if ( V_180 )
return V_180 ;
if ( V_15 -> V_406 == V_120 ) {
if ( F_62 ( V_15 -> V_142 ) )
V_422 = 1 ;
if ( F_101 ( V_15 -> V_142 ) == 0 &&
V_15 -> V_243 <= V_246 )
V_422 = 1 ;
if ( ! F_91 ( V_15 -> V_142 ) && V_15 -> V_243 <= V_246 )
V_422 = 1 ;
}
if ( V_15 -> V_406 == V_122 &&
V_15 -> V_425 == V_402 &&
( V_15 -> V_142 [ 63 ] >> 8 ) & 1 )
V_422 = 1 ;
if ( V_15 -> V_133 == F_32 ( F_61 ( V_15 -> V_142 ) ) )
V_422 = 1 ;
if ( V_157 & V_162 ) {
if ( ! V_422 )
goto V_357;
else
V_421 = L_117 ;
}
F_30 ( L_118 ,
V_15 -> V_406 , ( int ) V_15 -> V_133 ) ;
F_57 ( V_15 , L_119 ,
F_36 ( F_34 ( V_15 -> V_133 ) ) ,
V_421 ) ;
return 0 ;
V_357:
F_59 ( V_15 , L_120 , V_157 ) ;
return - V_165 ;
}
int F_162 ( struct V_2 * V_3 , struct V_14 * * V_426 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_14 * V_15 ;
int V_180 = 0 , V_427 = 0 , V_428 = 0 ;
F_138 (dev, link, ENABLED) {
unsigned long V_44 , V_429 ;
unsigned int V_430 ;
V_430 = V_431 ;
if ( V_15 -> V_181 == V_138 )
V_430 = V_432 ;
else if ( F_62 ( V_15 -> V_142 ) )
V_430 = V_433 ;
F_163 ( V_15 ) ;
F_15 ( V_15 ) ;
V_44 = F_31 ( V_15 -> V_44 , 0 , 0 ) ;
if ( V_434 & V_430 )
V_429 = F_31 ( 0 , V_15 -> V_45 ,
V_15 -> V_46 ) ;
else
V_429 = 0 ;
V_15 -> V_243 = F_32 ( V_44 ) ;
V_15 -> V_425 = F_32 ( V_429 ) ;
V_428 = 1 ;
if ( F_164 ( V_15 ) )
V_427 = 1 ;
}
if ( ! V_428 )
goto V_435;
F_138 (dev, link, ENABLED) {
if ( V_15 -> V_243 == 0xff ) {
F_24 ( V_15 , L_121 ) ;
V_180 = - V_118 ;
goto V_435;
}
V_15 -> V_133 = V_15 -> V_243 ;
V_15 -> V_406 = V_120 ;
if ( V_5 -> V_213 -> V_354 )
V_5 -> V_213 -> V_354 ( V_5 , V_15 ) ;
}
F_138 (dev, link, ENABLED) {
if ( ! F_164 ( V_15 ) )
continue;
V_15 -> V_133 = V_15 -> V_425 ;
V_15 -> V_406 = F_35 ( V_15 -> V_425 ) ;
if ( V_5 -> V_213 -> V_436 )
V_5 -> V_213 -> V_436 ( V_5 , V_15 ) ;
}
F_138 (dev, link, ENABLED) {
V_180 = F_159 ( V_15 ) ;
if ( V_180 )
goto V_435;
}
if ( V_427 && ( V_5 -> V_269 -> V_42 & V_437 ) )
V_5 -> V_269 -> V_438 = V_5 ;
V_435:
if ( V_180 )
* V_426 = V_15 ;
return V_180 ;
}
int F_165 ( struct V_2 * V_3 , unsigned long V_439 ,
int (* F_166)( struct V_2 * V_3 ) )
{
unsigned long V_440 = V_441 ;
unsigned long V_442 ;
int V_443 = 0 ;
if ( V_3 -> V_5 -> V_269 -> V_42 & V_444 )
V_442 = F_167 ( V_440 , V_445 ) ;
else
V_442 = F_167 ( V_440 , V_446 ) ;
F_87 ( V_3 == V_3 -> V_5 -> V_12 ) ;
if ( F_168 ( V_442 , V_439 ) )
V_442 = V_439 ;
while ( 1 ) {
unsigned long V_447 = V_441 ;
int V_448 , V_361 ;
V_448 = V_361 = F_166 ( V_3 ) ;
if ( V_448 > 0 )
return 0 ;
if ( V_448 == - V_259 ) {
if ( F_169 ( V_3 ) )
V_448 = 0 ;
else if ( ( V_3 -> V_5 -> V_42 & V_423 ) &&
! F_170 ( V_3 ) &&
F_171 ( V_447 , V_442 ) )
V_448 = 0 ;
}
if ( V_448 )
return V_448 ;
if ( F_168 ( V_447 , V_439 ) )
return - V_449 ;
if ( ! V_443 && F_168 ( V_447 , V_440 + 5 * V_450 ) &&
( V_439 - V_447 > 3 * V_450 ) ) {
F_147 ( V_3 ,
L_122
L_123 , V_361 ) ;
V_443 = 1 ;
}
F_172 ( V_3 -> V_5 , 50 ) ;
}
}
int F_173 ( struct V_2 * V_3 , unsigned long V_439 ,
int (* F_166)( struct V_2 * V_3 ) )
{
F_172 ( V_3 -> V_5 , V_451 ) ;
return F_165 ( V_3 , V_439 , F_166 ) ;
}
int F_174 ( struct V_2 * V_3 , const unsigned long * V_452 ,
unsigned long V_439 )
{
unsigned long V_453 = V_452 [ 0 ] ;
unsigned long V_454 = V_452 [ 1 ] ;
unsigned long V_455 , V_372 ;
T_1 V_456 , V_457 ;
int V_180 ;
V_372 = F_167 ( V_441 , V_452 [ 2 ] ) ;
if ( F_171 ( V_372 , V_439 ) )
V_439 = V_372 ;
if ( ( V_180 = F_126 ( V_3 , V_362 , & V_457 ) ) )
return V_180 ;
V_457 &= 0xf ;
V_456 = V_457 ;
V_455 = V_441 ;
while ( 1 ) {
F_172 ( V_3 -> V_5 , V_453 ) ;
if ( ( V_180 = F_126 ( V_3 , V_362 , & V_457 ) ) )
return V_180 ;
V_457 &= 0xf ;
if ( V_457 == V_456 ) {
if ( V_457 == 1 && F_171 ( V_441 , V_439 ) )
continue;
if ( F_168 ( V_441 ,
F_167 ( V_455 , V_454 ) ) )
return 0 ;
continue;
}
V_456 = V_457 ;
V_455 = V_441 ;
if ( F_168 ( V_441 , V_439 ) )
return - V_458 ;
}
}
int F_175 ( struct V_2 * V_3 , const unsigned long * V_452 ,
unsigned long V_439 )
{
int V_351 = V_459 ;
T_1 V_360 , V_460 ;
int V_180 ;
if ( ( V_180 = F_126 ( V_3 , V_363 , & V_360 ) ) )
return V_180 ;
do {
V_360 = ( V_360 & 0x0f0 ) | 0x300 ;
if ( ( V_180 = F_151 ( V_3 , V_363 , V_360 ) ) )
return V_180 ;
F_172 ( V_3 -> V_5 , 200 ) ;
if ( ( V_180 = F_126 ( V_3 , V_363 , & V_360 ) ) )
return V_180 ;
} while ( ( V_360 & 0xf0f ) != 0x300 && -- V_351 );
if ( ( V_360 & 0xf0f ) != 0x300 ) {
F_147 ( V_3 , L_124 ,
V_360 ) ;
return 0 ;
}
if ( V_351 < V_459 )
F_147 ( V_3 , L_125 ,
V_459 - V_351 ) ;
if ( ( V_180 = F_174 ( V_3 , V_452 , V_439 ) ) )
return V_180 ;
if ( ! ( V_180 = F_126 ( V_3 , V_461 , & V_460 ) ) )
V_180 = F_151 ( V_3 , V_461 , V_460 ) ;
return V_180 != - V_118 ? V_180 : 0 ;
}
int F_176 ( struct V_2 * V_3 , enum V_462 V_463 ,
bool V_464 )
{
struct V_171 * V_172 = & V_3 -> V_173 ;
bool V_465 = false ;
T_1 V_360 ;
int V_180 ;
V_180 = F_126 ( V_3 , V_363 , & V_360 ) ;
if ( V_180 )
return V_180 ;
switch ( V_463 ) {
case V_466 :
V_360 |= ( 0x7 << 8 ) ;
if ( V_464 ) {
V_360 |= ( 0x4 << 12 ) ;
V_465 = true ;
}
break;
case V_467 :
V_360 &= ~ ( 0x1 << 8 ) ;
V_360 |= ( 0x6 << 8 ) ;
break;
case V_468 :
if ( F_177 ( V_3 ) > 0 )
V_360 &= ~ ( 0x7 << 8 ) ;
else {
V_360 &= ~ 0xf ;
V_360 |= ( 0x1 << 2 ) ;
}
break;
default:
F_87 ( 1 ) ;
}
V_180 = F_151 ( V_3 , V_363 , V_360 ) ;
if ( V_180 )
return V_180 ;
if ( V_465 )
F_178 ( 10 ) ;
V_172 -> V_25 . V_460 &= ~ V_469 ;
return F_151 ( V_3 , V_461 , V_469 ) ;
}
int F_179 ( struct V_2 * V_3 , unsigned long V_439 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_171 * V_172 = & V_3 -> V_173 ;
const unsigned long * V_470 = F_180 ( V_172 ) ;
int V_180 ;
if ( V_172 -> V_25 . V_471 & V_472 )
return 0 ;
if ( V_5 -> V_42 & V_423 ) {
V_180 = F_175 ( V_3 , V_470 , V_439 ) ;
if ( V_180 && V_180 != - V_367 )
F_147 ( V_3 ,
L_126 ,
V_180 ) ;
}
if ( F_181 ( V_3 ) )
V_172 -> V_25 . V_471 &= ~ V_473 ;
return 0 ;
}
int F_182 ( struct V_2 * V_3 , const unsigned long * V_470 ,
unsigned long V_439 ,
bool * V_474 , int (* F_166)( struct V_2 * ) )
{
T_1 V_360 ;
int V_180 ;
F_30 ( L_127 ) ;
if ( V_474 )
* V_474 = false ;
if ( F_149 ( V_3 ) ) {
if ( ( V_180 = F_126 ( V_3 , V_363 , & V_360 ) ) )
goto V_435;
V_360 = ( V_360 & 0x0f0 ) | 0x304 ;
if ( ( V_180 = F_151 ( V_3 , V_363 , V_360 ) ) )
goto V_435;
F_150 ( V_3 ) ;
}
if ( ( V_180 = F_126 ( V_3 , V_363 , & V_360 ) ) )
goto V_435;
V_360 = ( V_360 & 0x0f0 ) | 0x301 ;
if ( ( V_180 = F_183 ( V_3 , V_363 , V_360 ) ) )
goto V_435;
F_172 ( V_3 -> V_5 , 1 ) ;
V_180 = F_175 ( V_3 , V_470 , V_439 ) ;
if ( V_180 )
goto V_435;
if ( F_181 ( V_3 ) )
goto V_435;
if ( V_474 )
* V_474 = true ;
if ( F_184 ( V_3 -> V_5 ) && F_13 ( V_3 ) ) {
if ( F_166 ) {
unsigned long V_475 ;
V_475 = F_167 ( V_441 ,
V_476 ) ;
if ( F_168 ( V_475 , V_439 ) )
V_475 = V_439 ;
F_165 ( V_3 , V_475 , F_166 ) ;
}
V_180 = - V_279 ;
goto V_435;
}
V_180 = 0 ;
if ( F_166 )
V_180 = F_165 ( V_3 , V_439 , F_166 ) ;
V_435:
if ( V_180 && V_180 != - V_279 ) {
if ( V_474 )
* V_474 = false ;
F_185 ( V_3 , L_128 , V_180 ) ;
}
F_30 ( L_129 , V_180 ) ;
return V_180 ;
}
int F_186 ( struct V_2 * V_3 , unsigned int * V_181 ,
unsigned long V_439 )
{
const unsigned long * V_470 = F_180 ( & V_3 -> V_173 ) ;
bool V_474 ;
int V_180 ;
V_180 = F_182 ( V_3 , V_470 , V_439 , & V_474 , NULL ) ;
return V_474 ? - V_279 : V_180 ;
}
void F_187 ( struct V_2 * V_3 , unsigned int * V_349 )
{
T_1 V_460 ;
F_30 ( L_127 ) ;
if ( ! F_126 ( V_3 , V_461 , & V_460 ) )
F_151 ( V_3 , V_461 , V_460 ) ;
F_142 ( V_3 ) ;
F_30 ( L_130 ) ;
}
static int F_188 ( struct V_14 * V_15 , unsigned int V_477 ,
const T_4 * V_478 )
{
const T_4 * V_479 = V_15 -> V_142 ;
unsigned char V_480 [ 2 ] [ V_301 + 1 ] ;
unsigned char V_481 [ 2 ] [ V_482 + 1 ] ;
if ( V_15 -> V_181 != V_477 ) {
F_57 ( V_15 , L_131 ,
V_15 -> V_181 , V_477 ) ;
return 0 ;
}
F_41 ( V_479 , V_480 [ 0 ] , V_310 , sizeof( V_480 [ 0 ] ) ) ;
F_41 ( V_478 , V_480 [ 1 ] , V_310 , sizeof( V_480 [ 1 ] ) ) ;
F_41 ( V_479 , V_481 [ 0 ] , V_483 , sizeof( V_481 [ 0 ] ) ) ;
F_41 ( V_478 , V_481 [ 1 ] , V_483 , sizeof( V_481 [ 1 ] ) ) ;
if ( strcmp ( V_480 [ 0 ] , V_480 [ 1 ] ) ) {
F_57 ( V_15 , L_132 ,
V_480 [ 0 ] , V_480 [ 1 ] ) ;
return 0 ;
}
if ( strcmp ( V_481 [ 0 ] , V_481 [ 1 ] ) ) {
F_57 ( V_15 , L_133 ,
V_481 [ 0 ] , V_481 [ 1 ] ) ;
return 0 ;
}
return 1 ;
}
int F_58 ( struct V_14 * V_15 , unsigned int V_484 )
{
unsigned int V_181 = V_15 -> V_181 ;
T_4 * V_142 = ( void * ) V_15 -> V_3 -> V_5 -> V_485 ;
int V_180 ;
V_180 = F_94 ( V_15 , & V_181 , V_484 , V_142 ) ;
if ( V_180 )
return V_180 ;
if ( ! F_188 ( V_15 , V_181 , V_142 ) )
return - V_259 ;
memcpy ( V_15 -> V_142 , V_142 , sizeof( V_142 [ 0 ] ) * V_249 ) ;
return 0 ;
}
int F_161 ( struct V_14 * V_15 , unsigned int V_477 ,
unsigned int V_484 )
{
T_3 V_307 = V_15 -> V_307 ;
T_3 V_183 = V_15 -> V_183 ;
int V_180 ;
if ( ! F_8 ( V_15 ) )
return - V_259 ;
if ( F_189 ( V_477 ) &&
V_477 != V_137 &&
V_477 != V_138 &&
V_477 != V_140 ) {
F_57 ( V_15 , L_134 ,
V_15 -> V_181 , V_477 ) ;
V_180 = - V_259 ;
goto V_357;
}
V_180 = F_58 ( V_15 , V_484 ) ;
if ( V_180 )
goto V_357;
V_180 = F_113 ( V_15 ) ;
if ( V_180 )
goto V_357;
if ( V_15 -> V_181 != V_137 || ! V_307 ||
V_15 -> V_307 == V_307 )
return 0 ;
F_24 ( V_15 , L_135 ,
( unsigned long long ) V_307 ,
( unsigned long long ) V_15 -> V_307 ) ;
if ( V_15 -> V_183 == V_183 &&
V_15 -> V_307 > V_307 && V_15 -> V_307 == V_183 ) {
F_24 ( V_15 ,
L_136
L_137 ) ;
return 0 ;
}
if ( V_15 -> V_183 == V_183 &&
V_15 -> V_307 < V_307 && V_307 == V_183 &&
! ( V_15 -> V_48 & V_182 ) ) {
F_24 ( V_15 ,
L_138
L_139 ) ;
V_15 -> V_42 |= V_178 ;
V_180 = - V_165 ;
} else
V_180 = - V_259 ;
V_15 -> V_183 = V_183 ;
V_15 -> V_307 = V_307 ;
V_357:
F_59 ( V_15 , L_140 , V_180 ) ;
return V_180 ;
}
static int F_190 ( const char * V_486 , const char * V_487 )
{
do {
if ( * V_486 == * V_487 || * V_487 == '?' ) {
if ( ! * V_487 ++ )
return 0 ;
} else {
if ( ! * V_486 || * V_487 != '[' )
break;
while ( * ++ V_487 && * V_487 != ']' && * V_486 != * V_487 ) {
if ( * V_487 == '-' && * ( V_487 - 1 ) != '[' )
if ( * V_486 > * ( V_487 - 1 ) && * V_486 < * ( V_487 + 1 ) ) {
++ V_487 ;
break;
}
}
if ( ! * V_487 || * V_487 == ']' )
return 1 ;
while ( * V_487 && * V_487 ++ != ']' ) ;
}
} while ( * ++ V_486 && * V_487 );
if ( * V_487 == '*' ) {
if ( ! * ++ V_487 )
return 0 ;
while ( * V_486 ) {
if ( F_190 ( V_486 , V_487 ) == 0 )
return 0 ;
++ V_486 ;
}
}
if ( ! * V_486 && ! * V_487 )
return 0 ;
return 1 ;
}
static unsigned long F_106 ( const struct V_14 * V_15 )
{
unsigned char V_488 [ V_301 + 1 ] ;
unsigned char V_489 [ V_299 + 1 ] ;
const struct V_490 * V_491 = V_492 ;
F_41 ( V_15 -> V_142 , V_488 , V_310 , sizeof( V_488 ) ) ;
F_41 ( V_15 -> V_142 , V_489 , V_309 , sizeof( V_489 ) ) ;
while ( V_491 -> V_488 ) {
if ( ! F_190 ( V_488 , V_491 -> V_488 ) ) {
if ( V_491 -> V_489 == NULL )
return V_491 -> V_48 ;
if ( ! F_190 ( V_489 , V_491 -> V_489 ) )
return V_491 -> V_48 ;
}
V_491 ++ ;
}
return 0 ;
}
static int F_191 ( const struct V_14 * V_15 )
{
if ( ( V_15 -> V_3 -> V_5 -> V_42 & V_493 ) &&
( V_15 -> V_42 & V_331 ) )
return 1 ;
return ( V_15 -> V_48 & V_494 ) ? 1 : 0 ;
}
static int F_192 ( struct V_14 * V_15 )
{
if ( V_15 -> V_48 & V_495 )
return F_193 ( V_15 -> V_142 ) ;
return F_194 ( V_15 -> V_142 ) ;
}
static int F_195 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
struct V_14 * V_15 ;
if ( V_5 -> V_33 == V_345 )
return 1 ;
if ( V_5 -> V_33 == V_346 || V_5 -> V_33 == V_281 )
return 0 ;
if ( V_5 -> V_33 == V_496 )
return 0 ;
F_196 (link, ap, EDGE) {
F_138 (dev, link, ENABLED) {
if ( ! F_192 ( V_15 ) )
return 0 ;
}
}
return 1 ;
}
static void F_163 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_497 * V_269 = V_5 -> V_269 ;
unsigned long V_47 ;
V_47 = F_31 ( V_5 -> V_44 ,
V_5 -> V_45 , V_5 -> V_46 ) ;
V_47 &= F_31 ( V_15 -> V_44 ,
V_15 -> V_45 , V_15 -> V_46 ) ;
V_47 &= F_61 ( V_15 -> V_142 ) ;
if ( F_145 ( V_15 ) ) {
V_47 &= ~ ( 0x03 << ( V_120 + 5 ) ) ;
V_47 &= ~ ( 0x03 << ( V_122 + 3 ) ) ;
}
if ( F_191 ( V_15 ) ) {
V_47 &= ~ ( V_123 | V_125 ) ;
F_24 ( V_15 ,
L_141 ) ;
}
if ( ( V_269 -> V_42 & V_437 ) &&
V_269 -> V_438 && V_269 -> V_438 != V_5 ) {
V_47 &= ~ ( V_123 | V_125 ) ;
F_24 ( V_15 ,
L_142 ) ;
}
if ( V_5 -> V_42 & V_242 )
V_47 &= F_92 ( V_15 ) ;
if ( V_5 -> V_213 -> V_498 )
V_47 = V_5 -> V_213 -> V_498 ( V_15 , V_47 ) ;
if ( V_47 & ( 0xF8 << V_124 ) )
if ( F_195 ( V_5 ) ) {
F_24 ( V_15 ,
L_143 ) ;
V_47 &= ~ ( 0xF8 << V_124 ) ;
}
F_16 ( V_47 , & V_15 -> V_44 ,
& V_15 -> V_45 , & V_15 -> V_46 ) ;
}
static unsigned int F_160 ( struct V_14 * V_15 )
{
struct V_67 V_68 ;
unsigned int V_157 ;
F_30 ( L_144 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_499 ;
V_68 . V_72 = V_500 ;
V_68 . V_42 |= V_108 | V_109 | V_261 ;
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
unsigned int F_100 ( struct V_14 * V_15 , T_2 V_501 , T_2 V_72 )
{
struct V_67 V_68 ;
unsigned int V_157 ;
F_30 ( L_146 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_499 ;
V_68 . V_72 = V_501 ;
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
return V_502 ;
F_30 ( L_147 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_503 ;
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
void F_197 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
struct V_199 * V_225 = V_193 -> V_225 ;
int V_504 = V_193 -> V_198 ;
F_198 ( V_225 == NULL ) ;
F_199 ( L_148 , V_193 -> V_201 ) ;
if ( V_193 -> V_201 )
F_200 ( V_5 -> V_15 , V_225 , V_193 -> V_505 , V_504 ) ;
V_193 -> V_42 &= ~ V_506 ;
V_193 -> V_225 = NULL ;
}
int F_201 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
if ( ! ( V_193 -> V_15 -> V_48 & V_507 ) &&
F_5 ( V_193 -> V_227 & 15 ) )
return 1 ;
if ( V_5 -> V_213 -> V_508 )
return V_5 -> V_213 -> V_508 ( V_193 ) ;
return 0 ;
}
int F_202 ( struct V_192 * V_193 )
{
struct V_2 * V_3 = V_193 -> V_15 -> V_3 ;
if ( V_193 -> V_68 . V_92 == V_112 ) {
if ( ! F_203 ( V_3 -> V_217 ) )
return 0 ;
} else {
if ( ! F_203 ( V_3 -> V_217 ) && ! V_3 -> V_218 )
return 0 ;
}
return V_509 ;
}
void F_204 ( struct V_192 * V_193 ) { }
void F_74 ( struct V_192 * V_193 , struct V_199 * V_225 ,
unsigned int V_201 )
{
V_193 -> V_225 = V_225 ;
V_193 -> V_201 = V_201 ;
V_193 -> V_510 = V_193 -> V_225 ;
}
static int F_205 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
unsigned int V_201 ;
F_199 ( L_149 , V_5 -> V_31 ) ;
V_201 = F_206 ( V_5 -> V_15 , V_193 -> V_225 , V_193 -> V_201 , V_193 -> V_198 ) ;
if ( V_201 < 1 )
return - 1 ;
F_30 ( L_150 , V_201 ) ;
V_193 -> V_505 = V_193 -> V_201 ;
V_193 -> V_201 = V_201 ;
V_193 -> V_42 |= V_506 ;
return 0 ;
}
void F_98 ( T_4 * V_238 , unsigned int V_511 )
{
#ifdef F_207
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < V_511 ; V_25 ++ )
V_238 [ V_25 ] = F_208 ( V_238 [ V_25 ] ) ;
#endif
}
static struct V_192 * F_209 ( struct V_4 * V_5 )
{
struct V_192 * V_193 = NULL ;
unsigned int V_25 ;
if ( F_5 ( V_5 -> V_210 & V_211 ) )
return NULL ;
for ( V_25 = 0 ; V_25 < V_291 - 1 ; V_25 ++ )
if ( ! F_69 ( V_25 , & V_5 -> V_215 ) ) {
V_193 = F_71 ( V_5 , V_25 ) ;
break;
}
if ( V_193 )
V_193 -> V_107 = V_25 ;
return V_193 ;
}
struct V_192 * F_210 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_192 * V_193 ;
V_193 = F_209 ( V_5 ) ;
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
F_198 ( V_193 == NULL ) ;
V_5 = V_193 -> V_5 ;
V_193 -> V_42 = 0 ;
V_107 = V_193 -> V_107 ;
if ( F_27 ( F_203 ( V_107 ) ) ) {
V_193 -> V_107 = V_221 ;
F_211 ( V_107 , & V_5 -> V_215 ) ;
}
}
void F_212 ( struct V_192 * V_193 )
{
struct V_4 * V_5 ;
struct V_2 * V_3 ;
F_198 ( V_193 == NULL ) ;
F_198 ( ! ( V_193 -> V_42 & V_230 ) ) ;
V_5 = V_193 -> V_5 ;
V_3 = V_193 -> V_15 -> V_3 ;
if ( F_27 ( V_193 -> V_42 & V_506 ) )
F_197 ( V_193 ) ;
if ( V_193 -> V_68 . V_92 == V_112 ) {
V_3 -> V_218 &= ~ ( 1 << V_193 -> V_107 ) ;
if ( ! V_3 -> V_218 )
V_5 -> V_220 -- ;
} else {
V_3 -> V_217 = V_221 ;
V_5 -> V_220 -- ;
}
if ( F_5 ( V_193 -> V_42 & V_512 &&
V_5 -> V_513 == V_3 ) )
V_5 -> V_513 = NULL ;
V_193 -> V_42 &= ~ V_230 ;
V_5 -> V_219 &= ~ ( 1 << V_193 -> V_107 ) ;
V_193 -> V_228 ( V_193 ) ;
}
static void F_213 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
V_193 -> V_234 . V_42 = V_193 -> V_68 . V_42 ;
V_5 -> V_213 -> V_514 ( V_193 ) ;
}
static void F_214 ( struct V_192 * V_193 )
{
struct V_14 * V_15 = V_193 -> V_15 ;
if ( F_215 ( V_193 -> V_68 . V_92 ) )
return;
if ( ( V_15 -> V_45 || V_15 -> V_46 ) && F_216 ( V_193 -> V_68 . V_92 ) )
return;
V_15 -> V_42 &= ~ V_515 ;
}
void F_83 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
if ( V_5 -> V_213 -> V_214 ) {
struct V_14 * V_15 = V_193 -> V_15 ;
struct V_516 * V_517 = & V_15 -> V_3 -> V_518 ;
if ( F_5 ( V_193 -> V_157 ) )
V_193 -> V_42 |= V_233 ;
if ( F_5 ( F_217 ( V_193 -> V_107 ) ) ) {
F_213 ( V_193 ) ;
F_212 ( V_193 ) ;
return;
}
if ( F_5 ( V_193 -> V_42 & V_233 ) ) {
F_213 ( V_193 ) ;
F_218 ( V_193 ) ;
return;
}
F_198 ( V_5 -> V_210 & V_211 ) ;
if ( V_193 -> V_42 & V_223 )
F_213 ( V_193 ) ;
switch ( V_193 -> V_68 . V_71 ) {
case V_499 :
if ( V_193 -> V_68 . V_72 != V_519 &&
V_193 -> V_68 . V_72 != V_520 )
break;
case V_503 :
case V_521 :
V_517 -> V_522 [ V_15 -> V_24 ] |= V_523 ;
F_219 ( V_5 ) ;
break;
case V_524 :
V_15 -> V_42 |= V_525 ;
break;
}
if ( F_5 ( V_15 -> V_42 & V_515 ) )
F_214 ( V_193 ) ;
F_212 ( V_193 ) ;
} else {
if ( V_193 -> V_42 & V_526 )
return;
if ( V_193 -> V_157 || V_193 -> V_42 & V_223 )
F_213 ( V_193 ) ;
F_212 ( V_193 ) ;
}
}
int F_220 ( struct V_4 * V_5 , T_1 V_219 )
{
int V_527 = 0 ;
T_1 V_528 ;
V_528 = V_5 -> V_219 ^ V_219 ;
if ( F_5 ( V_528 & V_219 ) ) {
F_221 ( V_5 , L_151 ,
V_5 -> V_219 , V_219 ) ;
return - V_118 ;
}
while ( V_528 ) {
struct V_192 * V_193 ;
unsigned int V_107 = F_222 ( V_528 ) ;
V_193 = F_223 ( V_5 , V_107 ) ;
if ( V_193 ) {
F_83 ( V_193 ) ;
V_527 ++ ;
}
V_528 &= ~ ( 1 << V_107 ) ;
}
return V_527 ;
}
void F_75 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
struct V_2 * V_3 = V_193 -> V_15 -> V_3 ;
T_2 V_529 = V_193 -> V_68 . V_92 ;
F_198 ( V_5 -> V_213 -> V_214 && F_203 ( V_3 -> V_217 ) ) ;
if ( F_224 ( V_529 ) ) {
F_198 ( V_3 -> V_218 & ( 1 << V_193 -> V_107 ) ) ;
if ( ! V_3 -> V_218 )
V_5 -> V_220 ++ ;
V_3 -> V_218 |= 1 << V_193 -> V_107 ;
} else {
F_198 ( V_3 -> V_218 ) ;
V_5 -> V_220 ++ ;
V_3 -> V_217 = V_193 -> V_107 ;
}
V_193 -> V_42 |= V_230 ;
V_5 -> V_219 |= 1 << V_193 -> V_107 ;
if ( F_198 ( F_225 ( V_529 ) &&
( ! V_193 -> V_225 || ! V_193 -> V_201 || ! V_193 -> V_227 ) ) )
goto V_530;
if ( F_226 ( V_529 ) || ( F_216 ( V_529 ) &&
( V_5 -> V_42 & V_531 ) ) )
if ( F_205 ( V_193 ) )
goto V_530;
if ( F_5 ( V_193 -> V_15 -> V_42 & V_525 ) ) {
V_3 -> V_518 . V_471 |= V_532 ;
F_227 ( & V_3 -> V_518 , L_152 ) ;
F_228 ( V_3 ) ;
return;
}
V_5 -> V_213 -> V_533 ( V_193 ) ;
V_193 -> V_157 |= V_5 -> V_213 -> V_534 ( V_193 ) ;
if ( F_5 ( V_193 -> V_157 ) )
goto V_535;
return;
V_530:
V_193 -> V_157 |= V_212 ;
V_535:
F_83 ( V_193 ) ;
}
int F_104 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
return ( V_5 -> V_42 & V_423 ) && V_5 -> V_213 -> V_536 ;
}
int F_126 ( struct V_2 * V_3 , int V_537 , T_1 * V_538 )
{
if ( F_13 ( V_3 ) ) {
if ( F_104 ( V_3 ) )
return V_3 -> V_5 -> V_213 -> V_536 ( V_3 , V_537 , V_538 ) ;
return - V_367 ;
}
return F_229 ( V_3 , V_537 , V_538 ) ;
}
int F_151 ( struct V_2 * V_3 , int V_537 , T_1 V_538 )
{
if ( F_13 ( V_3 ) ) {
if ( F_104 ( V_3 ) )
return V_3 -> V_5 -> V_213 -> V_539 ( V_3 , V_537 , V_538 ) ;
return - V_367 ;
}
return F_230 ( V_3 , V_537 , V_538 ) ;
}
int F_183 ( struct V_2 * V_3 , int V_537 , T_1 V_538 )
{
if ( F_13 ( V_3 ) ) {
int V_180 ;
if ( F_104 ( V_3 ) ) {
V_180 = V_3 -> V_5 -> V_213 -> V_539 ( V_3 , V_537 , V_538 ) ;
if ( V_180 == 0 )
V_180 = V_3 -> V_5 -> V_213 -> V_536 ( V_3 , V_537 , & V_538 ) ;
return V_180 ;
}
return - V_367 ;
}
return F_230 ( V_3 , V_537 , V_538 ) ;
}
bool F_143 ( struct V_2 * V_3 )
{
T_1 V_1 ;
if ( F_126 ( V_3 , V_362 , & V_1 ) == 0 &&
F_1 ( V_1 ) )
return true ;
return false ;
}
bool F_181 ( struct V_2 * V_3 )
{
T_1 V_1 ;
if ( F_126 ( V_3 , V_362 , & V_1 ) == 0 &&
! F_1 ( V_1 ) )
return true ;
return false ;
}
bool F_169 ( struct V_2 * V_3 )
{
struct V_2 * V_540 = V_3 -> V_5 -> V_12 ;
F_87 ( V_3 == V_540 ) ;
return F_143 ( V_3 ) ||
( V_540 && F_143 ( V_540 ) ) ;
}
bool F_170 ( struct V_2 * V_3 )
{
struct V_2 * V_540 = V_3 -> V_5 -> V_12 ;
F_87 ( V_3 == V_540 ) ;
return F_181 ( V_3 ) &&
( ! V_540 || F_181 ( V_540 ) ) ;
}
static int F_231 ( struct V_4 * V_5 , T_6 V_541 ,
unsigned int V_471 , unsigned int V_542 ,
int * V_543 )
{
struct V_2 * V_3 ;
unsigned long V_42 ;
int V_180 = 0 ;
if ( V_5 -> V_210 & V_544 ) {
if ( V_543 ) {
* V_543 = - V_279 ;
return 0 ;
}
F_232 ( V_5 ) ;
F_87 ( V_5 -> V_210 & V_544 ) ;
}
F_67 ( V_5 -> V_209 , V_42 ) ;
V_5 -> V_545 = V_541 ;
if ( V_543 )
V_5 -> V_546 = V_543 ;
else
V_5 -> V_546 = & V_180 ;
V_5 -> V_210 |= V_544 ;
F_196 (link, ap, HOST_FIRST) {
V_3 -> V_518 . V_471 |= V_471 ;
V_3 -> V_518 . V_42 |= V_542 ;
}
F_219 ( V_5 ) ;
F_68 ( V_5 -> V_209 , V_42 ) ;
if ( ! V_543 ) {
F_232 ( V_5 ) ;
F_87 ( V_5 -> V_210 & V_544 ) ;
}
return V_180 ;
}
static int F_233 ( struct V_4 * V_5 , T_6 V_541 , int * V_543 )
{
unsigned int V_542 = V_547 ;
int V_180 ;
if ( V_541 . V_548 == V_549 )
V_542 |= V_550 | V_551 ;
V_180 = F_231 ( V_5 , V_541 , 0 , V_542 , V_543 ) ;
return V_180 ;
}
static int F_234 ( struct V_21 * V_15 , T_6 V_541 )
{
struct V_4 * V_5 = F_235 ( V_15 ) ;
return F_233 ( V_5 , V_541 , NULL ) ;
}
static int F_236 ( struct V_21 * V_15 )
{
if ( F_237 ( V_15 ) )
return 0 ;
return F_234 ( V_15 , V_552 ) ;
}
static int F_238 ( struct V_21 * V_15 )
{
if ( F_237 ( V_15 ) )
F_239 ( V_15 ) ;
return F_234 ( V_15 , V_553 ) ;
}
static int F_240 ( struct V_21 * V_15 )
{
if ( F_237 ( V_15 ) )
return 0 ;
return F_234 ( V_15 , V_554 ) ;
}
static int F_241 ( struct V_4 * V_5 , int * V_543 )
{
int V_180 ;
V_180 = F_231 ( V_5 , V_555 , V_532 ,
V_550 | V_547 , V_543 ) ;
return V_180 ;
}
static int F_242 ( struct V_21 * V_15 )
{
struct V_4 * V_5 = F_235 ( V_15 ) ;
return F_241 ( V_5 , NULL ) ;
}
static int F_243 ( struct V_21 * V_15 )
{
int V_180 ;
V_180 = F_242 ( V_15 ) ;
if ( ! V_180 ) {
F_244 ( V_15 ) ;
F_245 ( V_15 ) ;
F_246 ( V_15 ) ;
}
return V_180 ;
}
static int F_247 ( struct V_21 * V_15 )
{
return F_248 ( V_15 ) ;
}
int F_249 ( struct V_4 * V_5 , int * V_543 )
{
return F_233 ( V_5 , V_552 , V_543 ) ;
}
int F_250 ( struct V_4 * V_5 , int * V_543 )
{
return F_241 ( V_5 , V_543 ) ;
}
int F_251 ( struct V_497 * V_269 , T_6 V_541 )
{
V_269 -> V_15 -> V_556 . V_557 = V_541 ;
return 0 ;
}
void F_252 ( struct V_497 * V_269 )
{
V_269 -> V_15 -> V_556 . V_557 = V_555 ;
}
void F_253 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = F_9 ( V_15 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_42 ;
V_3 -> V_277 = V_3 -> V_40 ;
V_3 -> V_278 = 0 ;
F_67 ( V_5 -> V_209 , V_42 ) ;
V_15 -> V_42 &= ~ V_558 ;
V_15 -> V_48 = 0 ;
F_68 ( V_5 -> V_209 , V_42 ) ;
memset ( ( void * ) V_15 + V_559 , 0 ,
V_560 - V_559 ) ;
V_15 -> V_44 = V_370 ;
V_15 -> V_45 = V_370 ;
V_15 -> V_46 = V_370 ;
}
void F_254 ( struct V_4 * V_5 , struct V_2 * V_3 , int V_38 )
{
int V_25 ;
memset ( ( void * ) V_3 + V_561 , 0 ,
V_562 - V_561 ) ;
V_3 -> V_5 = V_5 ;
V_3 -> V_38 = V_38 ;
V_3 -> V_217 = V_221 ;
V_3 -> V_40 = V_370 ;
for ( V_25 = 0 ; V_25 < V_350 ; V_25 ++ ) {
struct V_14 * V_15 = & V_3 -> V_21 [ V_25 ] ;
V_15 -> V_3 = V_3 ;
V_15 -> V_24 = V_15 - V_3 -> V_21 ;
#ifdef F_255
V_15 -> V_563 = V_564 ;
#endif
F_253 ( V_15 ) ;
}
}
int F_256 ( struct V_2 * V_3 )
{
T_2 V_135 ;
int V_180 ;
V_180 = F_126 ( V_3 , V_363 , & V_3 -> V_565 ) ;
if ( V_180 )
return V_180 ;
V_135 = ( V_3 -> V_565 >> 4 ) & 0xf ;
if ( V_135 )
V_3 -> V_40 &= ( 1 << V_135 ) - 1 ;
F_12 ( V_3 ) ;
V_3 -> V_277 = V_3 -> V_40 ;
return 0 ;
}
struct V_4 * F_257 ( struct V_497 * V_269 )
{
struct V_4 * V_5 ;
F_30 ( L_127 ) ;
V_5 = F_258 ( sizeof( * V_5 ) , V_566 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_210 |= V_567 | V_211 ;
V_5 -> V_209 = & V_269 -> V_209 ;
V_5 -> V_31 = - 1 ;
V_5 -> V_269 = V_269 ;
V_5 -> V_15 = V_269 -> V_15 ;
#if F_259 ( V_568 )
V_5 -> V_569 = 0x00FF ;
#elif F_259 ( V_570 )
V_5 -> V_569 = V_571 | V_572 | V_573 | V_574 | V_575 ;
#else
V_5 -> V_569 = V_571 | V_575 | V_574 ;
#endif
F_260 ( & V_5 -> V_576 ) ;
F_261 ( & V_5 -> V_577 , V_578 ) ;
F_262 ( & V_5 -> V_579 , V_580 ) ;
F_263 ( & V_5 -> V_581 ) ;
F_264 ( & V_5 -> V_582 ) ;
F_265 ( & V_5 -> V_583 ) ;
F_266 ( & V_5 -> V_584 ) ;
V_5 -> V_584 . V_585 = V_586 ;
V_5 -> V_584 . V_587 = ( unsigned long ) V_5 ;
V_5 -> V_33 = V_34 ;
F_254 ( V_5 , & V_5 -> V_3 , 0 ) ;
#ifdef F_267
V_5 -> V_588 . V_589 = 1 ;
V_5 -> V_588 . V_590 = 1 ;
#endif
F_268 ( V_5 ) ;
return V_5 ;
}
static void F_269 ( struct V_21 * V_591 , void * V_592 )
{
struct V_497 * V_269 = F_270 ( V_591 ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_269 -> V_593 ; V_25 ++ ) {
struct V_4 * V_5 = V_269 -> V_594 [ V_25 ] ;
if ( ! V_5 )
continue;
if ( V_5 -> V_289 )
F_271 ( V_5 -> V_289 ) ;
F_272 ( V_5 -> V_11 ) ;
F_272 ( V_5 -> V_12 ) ;
F_272 ( V_5 ) ;
V_269 -> V_594 [ V_25 ] = NULL ;
}
F_273 ( V_591 , NULL ) ;
}
struct V_497 * F_274 ( struct V_21 * V_15 , int V_595 )
{
struct V_497 * V_269 ;
T_5 V_596 ;
int V_25 ;
F_30 ( L_127 ) ;
if ( ! F_275 ( V_15 , NULL , V_566 ) )
return NULL ;
V_596 = sizeof( struct V_497 ) + ( V_595 + 1 ) * sizeof( void * ) ;
V_269 = F_276 ( F_269 , V_596 , V_566 ) ;
if ( ! V_269 )
goto V_260;
F_277 ( V_15 , V_269 ) ;
F_273 ( V_15 , V_269 ) ;
F_278 ( & V_269 -> V_209 ) ;
F_260 ( & V_269 -> V_597 ) ;
V_269 -> V_15 = V_15 ;
V_269 -> V_593 = V_595 ;
for ( V_25 = 0 ; V_25 < V_595 ; V_25 ++ ) {
struct V_4 * V_5 ;
V_5 = F_257 ( V_269 ) ;
if ( ! V_5 )
goto V_260;
V_5 -> V_598 = V_25 ;
V_269 -> V_594 [ V_25 ] = V_5 ;
}
F_279 ( V_15 , NULL ) ;
return V_269 ;
V_260:
F_280 ( V_15 , NULL ) ;
return NULL ;
}
struct V_497 * F_281 ( struct V_21 * V_15 ,
const struct V_599 * const * V_600 ,
int V_593 )
{
const struct V_599 * V_601 ;
struct V_497 * V_269 ;
int V_25 , V_602 ;
V_269 = F_274 ( V_15 , V_593 ) ;
if ( ! V_269 )
return NULL ;
for ( V_25 = 0 , V_602 = 0 , V_601 = NULL ; V_25 < V_269 -> V_593 ; V_25 ++ ) {
struct V_4 * V_5 = V_269 -> V_594 [ V_25 ] ;
if ( V_600 [ V_602 ] )
V_601 = V_600 [ V_602 ++ ] ;
V_5 -> V_44 = V_601 -> V_44 ;
V_5 -> V_45 = V_601 -> V_45 ;
V_5 -> V_46 = V_601 -> V_46 ;
V_5 -> V_42 |= V_601 -> V_42 ;
V_5 -> V_3 . V_42 |= V_601 -> V_603 ;
V_5 -> V_213 = V_601 -> V_604 ;
if ( ! V_269 -> V_213 && ( V_601 -> V_604 != & V_605 ) )
V_269 -> V_213 = V_601 -> V_604 ;
}
return V_269 ;
}
int F_282 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
F_87 ( V_5 -> V_12 ) ;
F_87 ( V_5 -> V_42 & V_606 ) ;
V_3 = F_258 ( sizeof( * V_3 ) , V_566 ) ;
if ( ! V_3 )
return - V_607 ;
F_254 ( V_5 , V_3 , 1 ) ;
V_5 -> V_12 = V_3 ;
return 0 ;
}
static void F_283 ( struct V_21 * V_591 , void * V_592 )
{
struct V_497 * V_269 = F_270 ( V_591 ) ;
int V_25 ;
F_87 ( ! ( V_269 -> V_42 & V_608 ) ) ;
for ( V_25 = 0 ; V_25 < V_269 -> V_593 ; V_25 ++ ) {
struct V_4 * V_5 = V_269 -> V_594 [ V_25 ] ;
if ( V_5 -> V_213 -> V_609 )
V_5 -> V_213 -> V_609 ( V_5 ) ;
}
if ( V_269 -> V_213 -> V_610 )
V_269 -> V_213 -> V_610 ( V_269 ) ;
}
static void F_284 ( struct V_611 * V_213 )
{
static F_285 ( V_209 ) ;
const struct V_611 * V_457 ;
void * * V_612 = ( void * * ) V_213 ;
void * * V_613 = ( void * * ) & V_213 -> V_614 ;
void * * V_615 ;
if ( ! V_213 || ! V_213 -> V_614 )
return;
F_286 ( & V_209 ) ;
for ( V_457 = V_213 -> V_614 ; V_457 ; V_457 = V_457 -> V_614 ) {
void * * V_616 = ( void * * ) V_457 ;
for ( V_615 = V_612 ; V_615 < V_613 ; V_615 ++ , V_616 ++ )
if ( ! * V_615 )
* V_615 = * V_616 ;
}
for ( V_615 = V_612 ; V_615 < V_613 ; V_615 ++ )
if ( F_287 ( * V_615 ) )
* V_615 = NULL ;
V_213 -> V_614 = NULL ;
F_288 ( & V_209 ) ;
}
int F_289 ( struct V_497 * V_269 )
{
int V_617 = 0 ;
void * V_618 = NULL ;
int V_25 , V_180 ;
if ( V_269 -> V_42 & V_608 )
return 0 ;
F_284 ( V_269 -> V_213 ) ;
for ( V_25 = 0 ; V_25 < V_269 -> V_593 ; V_25 ++ ) {
struct V_4 * V_5 = V_269 -> V_594 [ V_25 ] ;
F_284 ( V_5 -> V_213 ) ;
if ( ! V_269 -> V_213 && ! F_290 ( V_5 ) )
V_269 -> V_213 = V_5 -> V_213 ;
if ( V_5 -> V_213 -> V_609 )
V_617 = 1 ;
}
if ( V_269 -> V_213 -> V_610 )
V_617 = 1 ;
if ( V_617 ) {
V_618 = F_276 ( F_283 , 0 , V_566 ) ;
if ( ! V_618 )
return - V_607 ;
}
for ( V_25 = 0 ; V_25 < V_269 -> V_593 ; V_25 ++ ) {
struct V_4 * V_5 = V_269 -> V_594 [ V_25 ] ;
if ( V_5 -> V_213 -> V_619 ) {
V_180 = V_5 -> V_213 -> V_619 ( V_5 ) ;
if ( V_180 ) {
if ( V_180 != - V_259 )
F_291 ( V_269 -> V_15 ,
L_153 ,
V_25 , V_180 ) ;
goto V_260;
}
}
F_292 ( V_5 ) ;
}
if ( V_618 )
F_277 ( V_269 -> V_15 , V_618 ) ;
V_269 -> V_42 |= V_608 ;
return 0 ;
V_260:
while ( -- V_25 >= 0 ) {
struct V_4 * V_5 = V_269 -> V_594 [ V_25 ] ;
if ( V_5 -> V_213 -> V_609 )
V_5 -> V_213 -> V_609 ( V_5 ) ;
}
F_293 ( V_618 ) ;
return V_180 ;
}
void F_294 ( struct V_497 * V_269 , struct V_21 * V_15 ,
struct V_611 * V_213 )
{
F_278 ( & V_269 -> V_209 ) ;
F_260 ( & V_269 -> V_597 ) ;
V_269 -> V_15 = V_15 ;
V_269 -> V_213 = V_213 ;
}
void F_295 ( struct V_4 * V_5 )
{
struct V_516 * V_517 = & V_5 -> V_3 . V_518 ;
unsigned long V_42 ;
F_67 ( V_5 -> V_209 , V_42 ) ;
V_517 -> V_620 |= V_621 ;
V_517 -> V_471 |= V_532 ;
V_517 -> V_42 |= V_550 | V_547 ;
V_5 -> V_210 &= ~ V_567 ;
V_5 -> V_210 |= V_622 ;
F_219 ( V_5 ) ;
F_68 ( V_5 -> V_209 , V_42 ) ;
}
int F_296 ( struct V_4 * V_5 )
{
int V_180 = 0 ;
if ( V_5 -> V_213 -> V_214 ) {
F_295 ( V_5 ) ;
F_232 ( V_5 ) ;
} else {
F_30 ( L_154 , V_5 -> V_31 ) ;
V_180 = F_137 ( V_5 ) ;
F_30 ( L_155 , V_5 -> V_31 ) ;
}
return V_180 ;
}
static void F_297 ( void * V_587 , T_7 V_623 )
{
struct V_4 * V_5 = V_587 ;
if ( ! ( V_5 -> V_269 -> V_42 & V_444 ) && V_5 -> V_598 != 0 )
F_298 ( V_623 ) ;
( void ) F_296 ( V_5 ) ;
F_298 ( V_623 ) ;
F_299 ( V_5 , 1 ) ;
}
int F_300 ( struct V_497 * V_269 , struct V_624 * V_625 )
{
int V_25 , V_180 ;
if ( ! ( V_269 -> V_42 & V_608 ) ) {
F_291 ( V_269 -> V_15 , L_156 ) ;
F_87 ( 1 ) ;
return - V_118 ;
}
for ( V_25 = V_269 -> V_593 ; V_269 -> V_594 [ V_25 ] ; V_25 ++ )
F_272 ( V_269 -> V_594 [ V_25 ] ) ;
for ( V_25 = 0 ; V_25 < V_269 -> V_593 ; V_25 ++ )
V_269 -> V_594 [ V_25 ] -> V_31 = F_301 ( & V_626 ) ;
for ( V_25 = 0 ; V_25 < V_269 -> V_593 ; V_25 ++ ) {
V_180 = F_302 ( V_269 -> V_15 , V_269 -> V_594 [ V_25 ] ) ;
if ( V_180 ) {
goto V_627;
}
}
V_180 = F_303 ( V_269 , V_625 ) ;
if ( V_180 )
goto V_627;
for ( V_25 = 0 ; V_25 < V_269 -> V_593 ; V_25 ++ ) {
struct V_4 * V_5 = V_269 -> V_594 [ V_25 ] ;
unsigned long V_47 ;
if ( V_5 -> V_33 == V_34 && ( V_5 -> V_42 & V_423 ) )
V_5 -> V_33 = V_281 ;
F_256 ( & V_5 -> V_3 ) ;
if ( V_5 -> V_12 )
F_256 ( V_5 -> V_12 ) ;
V_47 = F_31 ( V_5 -> V_44 , V_5 -> V_45 ,
V_5 -> V_46 ) ;
if ( ! F_290 ( V_5 ) ) {
V_599 ( V_5 , L_157 ,
( V_5 -> V_42 & V_423 ) ? 'S' : 'P' ,
F_36 ( V_47 ) ,
V_5 -> V_3 . V_518 . V_282 ) ;
F_304 ( & V_5 -> V_3 . V_518 ) ;
} else
V_599 ( V_5 , L_158 ) ;
}
for ( V_25 = 0 ; V_25 < V_269 -> V_593 ; V_25 ++ ) {
struct V_4 * V_5 = V_269 -> V_594 [ V_25 ] ;
F_305 ( F_297 , V_5 ) ;
}
return 0 ;
V_627:
while ( -- V_25 >= 0 ) {
F_306 ( V_269 -> V_594 [ V_25 ] ) ;
}
return V_180 ;
}
int F_307 ( struct V_497 * V_269 , int V_628 ,
T_8 V_629 , unsigned long V_630 ,
struct V_624 * V_625 )
{
int V_25 , V_180 ;
V_180 = F_289 ( V_269 ) ;
if ( V_180 )
return V_180 ;
if ( ! V_628 ) {
F_87 ( V_629 ) ;
return F_300 ( V_269 , V_625 ) ;
}
V_180 = F_308 ( V_269 -> V_15 , V_628 , V_629 , V_630 ,
F_309 ( V_269 -> V_15 ) , V_269 ) ;
if ( V_180 )
return V_180 ;
for ( V_25 = 0 ; V_25 < V_269 -> V_593 ; V_25 ++ )
F_310 ( V_269 -> V_594 [ V_25 ] , L_159 , V_628 ) ;
V_180 = F_300 ( V_269 , V_625 ) ;
if ( V_180 )
F_311 ( V_269 -> V_15 , V_628 , V_269 ) ;
return V_180 ;
}
static void F_312 ( struct V_4 * V_5 )
{
unsigned long V_42 ;
if ( ! V_5 -> V_213 -> V_214 )
goto V_631;
F_67 ( V_5 -> V_209 , V_42 ) ;
V_5 -> V_210 |= V_632 ;
F_219 ( V_5 ) ;
F_68 ( V_5 -> V_209 , V_42 ) ;
F_232 ( V_5 ) ;
F_87 ( ! ( V_5 -> V_210 & V_633 ) ) ;
F_313 ( & V_5 -> V_577 ) ;
V_631:
if ( V_5 -> V_11 ) {
int V_25 ;
for ( V_25 = 0 ; V_25 < V_634 ; V_25 ++ )
F_314 ( & V_5 -> V_11 [ V_25 ] ) ;
}
F_306 ( V_5 ) ;
F_315 ( V_5 -> V_289 ) ;
}
void F_316 ( struct V_497 * V_269 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_269 -> V_593 ; V_25 ++ )
F_312 ( V_269 -> V_594 [ V_25 ] ) ;
F_317 ( V_269 ) ;
}
void F_318 ( struct V_635 * V_636 )
{
struct V_21 * V_15 = & V_636 -> V_15 ;
struct V_497 * V_269 = F_270 ( V_15 ) ;
F_316 ( V_269 ) ;
}
int F_319 ( struct V_635 * V_636 , const struct V_637 * V_131 )
{
unsigned long V_361 = 0 ;
switch ( V_131 -> V_638 ) {
case 1 : {
T_2 V_639 = 0 ;
F_320 ( V_636 , V_131 -> V_537 , & V_639 ) ;
V_361 = V_639 ;
break;
}
case 2 : {
T_4 V_640 = 0 ;
F_321 ( V_636 , V_131 -> V_537 , & V_640 ) ;
V_361 = V_640 ;
break;
}
case 4 : {
T_1 V_641 = 0 ;
F_322 ( V_636 , V_131 -> V_537 , & V_641 ) ;
V_361 = V_641 ;
break;
}
default:
return - V_118 ;
}
V_361 &= V_131 -> V_365 ;
return ( V_361 == V_131 -> V_538 ) ? 1 : 0 ;
}
void F_323 ( struct V_635 * V_636 , T_6 V_541 )
{
F_324 ( V_636 ) ;
F_325 ( V_636 ) ;
if ( V_541 . V_548 & V_642 )
F_326 ( V_636 , V_643 ) ;
}
int F_327 ( struct V_635 * V_636 )
{
int V_180 ;
F_326 ( V_636 , V_644 ) ;
F_328 ( V_636 ) ;
V_180 = F_329 ( V_636 ) ;
if ( V_180 ) {
F_291 ( & V_636 -> V_15 ,
L_160 , V_180 ) ;
return V_180 ;
}
F_330 ( V_636 ) ;
return 0 ;
}
int F_331 ( struct V_635 * V_636 , T_6 V_541 )
{
struct V_497 * V_269 = F_270 ( & V_636 -> V_15 ) ;
int V_180 = 0 ;
V_180 = F_251 ( V_269 , V_541 ) ;
if ( V_180 )
return V_180 ;
F_323 ( V_636 , V_541 ) ;
return 0 ;
}
int F_332 ( struct V_635 * V_636 )
{
struct V_497 * V_269 = F_270 ( & V_636 -> V_15 ) ;
int V_180 ;
V_180 = F_327 ( V_636 ) ;
if ( V_180 == 0 )
F_252 ( V_269 ) ;
return V_180 ;
}
static int T_9 F_333 ( char * * V_457 ,
struct V_27 * V_645 ,
const char * * V_251 )
{
static struct V_646 V_647 [] V_648 = {
{ L_161 , . V_33 = V_345 } ,
{ L_162 , . V_33 = V_346 } ,
{ L_163 , . V_33 = V_496 } ,
{ L_164 , . V_33 = V_347 } ,
{ L_165 , . V_33 = V_348 } ,
{ L_166 , . V_33 = V_281 } ,
{ L_167 , . V_39 = 1 } ,
{ L_168 , . V_39 = 2 } ,
{ L_169 , . V_49 = V_287 } ,
{ L_170 , . V_50 = V_287 } ,
{ L_171 , . V_49 = V_266 } ,
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
{ L_206 , . V_41 = V_649 } ,
{ L_207 , . V_41 = V_650 } ,
{ L_208 , . V_41 = V_649 | V_650 } ,
{ L_209 , . V_41 = V_651 } ,
} ;
char * V_440 = * V_457 , * V_147 = * V_457 ;
char * V_142 , * V_538 , * V_652 ;
const struct V_646 * V_653 = NULL ;
int V_654 = 0 , V_25 ;
while ( * V_147 != '\0' && * V_147 != ',' )
V_147 ++ ;
if ( * V_147 == '\0' )
* V_457 = V_147 ;
else
* V_457 = V_147 + 1 ;
* V_147 = '\0' ;
V_147 = strchr ( V_440 , ':' ) ;
if ( ! V_147 ) {
V_538 = F_334 ( V_440 ) ;
goto V_655;
}
* V_147 = '\0' ;
V_142 = F_334 ( V_440 ) ;
V_538 = F_334 ( V_147 + 1 ) ;
V_147 = strchr ( V_142 , '.' ) ;
if ( V_147 ) {
* V_147 ++ = '\0' ;
V_645 -> V_21 = F_335 ( V_147 , & V_652 , 10 ) ;
if ( V_147 == V_652 || * V_652 != '\0' ) {
* V_251 = L_210 ;
return - V_118 ;
}
}
V_645 -> V_30 = F_335 ( V_142 , & V_652 , 10 ) ;
if ( V_147 == V_652 || * V_652 != '\0' ) {
* V_251 = L_211 ;
return - V_118 ;
}
V_655:
for ( V_25 = 0 ; V_25 < F_37 ( V_647 ) ; V_25 ++ ) {
const struct V_646 * V_656 = & V_647 [ V_25 ] ;
if ( strncasecmp ( V_538 , V_656 -> V_35 , strlen ( V_538 ) ) )
continue;
V_654 ++ ;
V_653 = V_656 ;
if ( strcasecmp ( V_538 , V_656 -> V_35 ) == 0 ) {
V_654 = 1 ;
break;
}
}
if ( ! V_654 ) {
* V_251 = L_212 ;
return - V_118 ;
}
if ( V_654 > 1 ) {
* V_251 = L_213 ;
return - V_118 ;
}
V_645 -> V_32 = * V_653 ;
return 0 ;
}
static void T_9 F_336 ( void )
{
int V_657 = 0 , V_658 = 1 ;
int V_659 = - 1 , V_660 = - 1 ;
char * V_147 , * V_457 , * V_23 ;
for ( V_147 = V_661 ; * V_147 ; V_147 ++ )
if ( * V_147 == ',' )
V_658 ++ ;
V_29 = F_258 ( sizeof( V_29 [ 0 ] ) * V_658 , V_566 ) ;
if ( ! V_29 ) {
F_337 ( V_662 L_214
L_215 ) ;
return;
}
for ( V_457 = V_661 ; * V_457 != '\0' ; V_457 = V_23 ) {
const char * V_251 = L_67 ;
struct V_27 V_663 = { . V_30 = - 1 , . V_21 = - 1 } ;
V_23 = V_457 ;
if ( F_333 ( & V_23 , & V_663 , & V_251 ) ) {
F_337 ( V_662 L_216
L_217 ,
V_457 , V_251 ) ;
continue;
}
if ( V_663 . V_30 == - 1 ) {
V_663 . V_30 = V_659 ;
V_663 . V_21 = V_660 ;
}
V_29 [ V_657 ++ ] = V_663 ;
V_659 = V_663 . V_30 ;
V_660 = V_663 . V_21 ;
}
V_26 = V_657 ;
}
static int T_9 F_338 ( void )
{
int V_180 ;
F_336 () ;
F_339 () ;
V_180 = F_340 () ;
if ( V_180 ) {
F_272 ( V_29 ) ;
return V_180 ;
}
F_341 () ;
V_664 = F_342 () ;
if ( ! V_664 ) {
F_343 () ;
V_180 = - V_607 ;
goto V_260;
}
F_337 ( V_267 L_218 V_665 L_219 ) ;
return 0 ;
V_260:
return V_180 ;
}
static void T_10 F_344 ( void )
{
F_345 ( V_664 ) ;
F_346 () ;
F_343 () ;
F_347 () ;
F_272 ( V_29 ) ;
}
int F_348 ( void )
{
return F_349 ( & V_666 ) ;
}
void F_172 ( struct V_4 * V_5 , unsigned int V_667 )
{
bool V_668 = V_5 && V_5 -> V_269 -> V_669 == V_670 ;
if ( V_668 )
F_77 ( V_5 ) ;
F_178 ( V_667 ) ;
if ( V_668 )
F_80 ( V_5 ) ;
}
T_1 F_350 ( struct V_4 * V_5 , void T_11 * V_537 , T_1 V_365 , T_1 V_538 ,
unsigned long V_453 , unsigned long V_202 )
{
unsigned long V_439 ;
T_1 V_361 ;
V_361 = F_351 ( V_537 ) ;
V_439 = F_167 ( V_441 , V_202 ) ;
while ( ( V_361 & V_365 ) == V_538 && F_171 ( V_441 , V_439 ) ) {
F_172 ( V_5 , V_453 ) ;
V_361 = F_351 ( V_537 ) ;
}
return V_361 ;
}
static unsigned int F_352 ( struct V_192 * V_193 )
{
return V_212 ;
}
static void F_353 ( struct V_4 * V_5 )
{
}
int F_354 ( const struct V_4 * V_5 , const char * V_671 ,
const char * V_672 , ... )
{
struct V_673 V_674 ;
T_12 args ;
int V_675 ;
va_start ( args , V_672 ) ;
V_674 . V_672 = V_672 ;
V_674 . V_676 = & args ;
V_675 = F_337 ( L_220 , V_671 , V_5 -> V_31 , & V_674 ) ;
va_end ( args ) ;
return V_675 ;
}
int F_355 ( const struct V_2 * V_3 , const char * V_671 ,
const char * V_672 , ... )
{
struct V_673 V_674 ;
T_12 args ;
int V_675 ;
va_start ( args , V_672 ) ;
V_674 . V_672 = V_672 ;
V_674 . V_676 = & args ;
if ( F_4 ( V_3 -> V_5 ) || V_3 -> V_5 -> V_12 )
V_675 = F_337 ( L_221 ,
V_671 , V_3 -> V_5 -> V_31 , V_3 -> V_38 , & V_674 ) ;
else
V_675 = F_337 ( L_220 ,
V_671 , V_3 -> V_5 -> V_31 , & V_674 ) ;
va_end ( args ) ;
return V_675 ;
}
int F_356 ( const struct V_14 * V_15 , const char * V_671 ,
const char * V_672 , ... )
{
struct V_673 V_674 ;
T_12 args ;
int V_675 ;
va_start ( args , V_672 ) ;
V_674 . V_672 = V_672 ;
V_674 . V_676 = & args ;
V_675 = F_337 ( L_221 ,
V_671 , V_15 -> V_3 -> V_5 -> V_31 , V_15 -> V_3 -> V_38 + V_15 -> V_24 ,
& V_674 ) ;
va_end ( args ) ;
return V_675 ;
}
void F_357 ( const struct V_21 * V_15 , const char * V_677 )
{
F_358 ( V_267 , V_15 , L_222 , V_677 ) ;
}
