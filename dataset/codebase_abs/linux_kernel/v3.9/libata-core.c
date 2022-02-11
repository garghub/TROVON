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
if ( F_122 ( V_15 -> V_142 ) ) {
T_2 * V_317 = V_5 -> V_318 ;
int V_25 , V_319 ;
V_15 -> V_42 |= V_320 ;
V_157 = F_123 ( V_15 ,
V_321 ,
V_322 ,
V_317 ,
1 ) ;
if ( V_157 )
F_96 ( V_15 ,
L_94 ,
V_157 ) ;
else
for ( V_25 = 0 ; V_25 < V_323 ; V_25 ++ ) {
V_319 = V_324 + V_25 ;
V_15 -> V_325 [ V_25 ] = V_317 [ V_319 ] ;
}
}
V_15 -> V_306 = 16 ;
}
else if ( V_15 -> V_181 == V_138 ) {
const char * V_326 = L_67 ;
const char * V_327 = L_67 ;
const char * V_328 = L_67 ;
T_1 V_329 ;
V_180 = F_124 ( V_142 ) ;
if ( ( V_180 < 12 ) || ( V_180 > V_222 ) ) {
if ( F_84 ( V_5 ) )
F_24 ( V_15 , L_95 ) ;
V_180 = - V_118 ;
goto V_330;
}
V_15 -> V_306 = ( unsigned int ) V_180 ;
if ( V_331 &&
( V_5 -> V_42 & V_332 ) && F_125 ( V_142 ) &&
( ! F_4 ( V_5 ) ||
F_126 ( & V_5 -> V_3 , V_333 , & V_329 ) == 0 ) ) {
V_157 = F_100 ( V_15 ,
V_295 , V_334 ) ;
if ( V_157 )
F_59 ( V_15 ,
L_96 ,
V_157 ) ;
else {
V_15 -> V_42 |= V_335 ;
V_327 = L_97 ;
}
}
if ( F_127 ( V_15 -> V_142 ) ) {
V_15 -> V_42 |= V_336 ;
V_326 = L_98 ;
}
if ( V_337 || F_128 ( V_15 -> V_142 ) ) {
V_15 -> V_42 |= V_338 ;
V_328 = L_99 ;
}
if ( F_129 ( V_15 -> V_142 ) ) {
V_15 -> V_42 |= V_339 ;
F_130 ( V_15 ) ;
}
if ( F_121 ( V_5 ) && V_174 )
F_57 ( V_15 ,
L_100 ,
V_300 , V_298 ,
F_36 ( V_47 ) ,
V_326 , V_327 ,
V_328 ) ;
}
V_15 -> V_156 = V_340 ;
if ( V_15 -> V_42 & V_117 )
V_15 -> V_156 = V_341 ;
if ( F_105 ( V_15 ) ) {
if ( F_121 ( V_5 ) && V_174 )
F_57 ( V_15 , L_101 ) ;
V_15 -> V_46 &= V_342 ;
V_15 -> V_156 = V_340 ;
}
if ( ( V_15 -> V_181 == V_138 ) &&
( F_131 ( V_142 ) == V_343 ) ) {
V_15 -> V_156 = V_344 ;
V_15 -> V_48 |= V_345 ;
}
if ( V_15 -> V_48 & V_346 )
V_15 -> V_156 = F_132 (unsigned int, ATA_MAX_SECTORS_128,
dev->max_sectors) ;
if ( V_15 -> V_48 & V_347 )
V_15 -> V_156 = V_341 ;
if ( V_5 -> V_213 -> V_348 )
V_5 -> V_213 -> V_348 ( V_15 ) ;
if ( V_15 -> V_48 & V_349 ) {
if ( V_174 ) {
F_24 ( V_15 ,
L_102 ) ;
F_24 ( V_15 ,
L_103 ) ;
}
}
if ( ( V_15 -> V_48 & V_350 ) && V_174 ) {
F_24 ( V_15 , L_104 ) ;
F_24 ( V_15 , L_105 ) ;
}
return 0 ;
V_330:
if ( F_115 ( V_5 ) )
F_96 ( V_15 , L_106 , V_255 ) ;
return V_180 ;
}
int F_133 ( struct V_4 * V_5 )
{
return V_351 ;
}
int F_134 ( struct V_4 * V_5 )
{
return V_352 ;
}
int F_135 ( struct V_4 * V_5 )
{
return V_353 ;
}
int F_136 ( struct V_4 * V_5 )
{
return V_354 ;
}
int F_137 ( struct V_4 * V_5 )
{
return V_281 ;
}
int F_138 ( struct V_4 * V_5 )
{
unsigned int V_355 [ V_356 ] ;
int V_357 [ V_356 ] ;
int V_180 ;
struct V_14 * V_15 ;
F_139 (dev, &ap->link, ALL)
V_357 [ V_15 -> V_24 ] = V_358 ;
V_256:
F_139 (dev, &ap->link, ALL) {
V_15 -> V_243 = V_359 ;
V_15 -> V_360 = 0xff ;
if ( V_5 -> V_213 -> V_361 )
V_5 -> V_213 -> V_361 ( V_5 , V_15 ) ;
}
V_5 -> V_213 -> V_362 ( V_5 ) ;
F_139 (dev, &ap->link, ALL) {
if ( V_15 -> V_181 != V_141 )
V_355 [ V_15 -> V_24 ] = V_15 -> V_181 ;
else
V_355 [ V_15 -> V_24 ] = V_363 ;
V_15 -> V_181 = V_141 ;
}
F_139 (dev, &ap->link, ALL_REVERSE) {
if ( V_357 [ V_15 -> V_24 ] )
V_15 -> V_181 = V_355 [ V_15 -> V_24 ] ;
if ( ! F_8 ( V_15 ) )
continue;
V_180 = F_94 ( V_15 , & V_15 -> V_181 , V_272 ,
V_15 -> V_142 ) ;
if ( V_180 )
goto V_364;
}
if ( V_5 -> V_213 -> V_365 )
V_5 -> V_33 = V_5 -> V_213 -> V_365 ( V_5 ) ;
F_139 (dev, &ap->link, ENABLED)
if ( F_107 ( V_15 -> V_142 ) )
V_5 -> V_33 = V_281 ;
F_139 (dev, &ap->link, ENABLED) {
V_5 -> V_3 . V_173 . V_25 . V_42 |= V_175 ;
V_180 = F_113 ( V_15 ) ;
V_5 -> V_3 . V_173 . V_25 . V_42 &= ~ V_175 ;
if ( V_180 )
goto V_364;
}
V_180 = F_140 ( & V_5 -> V_3 , & V_15 ) ;
if ( V_180 )
goto V_364;
F_139 (dev, &ap->link, ENABLED)
return 0 ;
return - V_259 ;
V_364:
V_357 [ V_15 -> V_24 ] -- ;
switch ( V_180 ) {
case - V_118 :
V_357 [ V_15 -> V_24 ] = 0 ;
break;
case - V_259 :
V_357 [ V_15 -> V_24 ] = F_111 ( V_357 [ V_15 -> V_24 ] , 1 ) ;
case - V_165 :
if ( V_357 [ V_15 -> V_24 ] == 1 ) {
F_141 ( & V_5 -> V_3 , 0 ) ;
F_142 ( V_15 , V_366 ) ;
}
}
if ( ! V_357 [ V_15 -> V_24 ] )
F_116 ( V_15 ) ;
goto V_256;
}
static void F_143 ( struct V_2 * V_3 )
{
T_1 V_1 , V_367 , V_368 ;
if ( F_126 ( V_3 , V_369 , & V_1 ) )
return;
F_126 ( V_3 , V_370 , & V_367 ) ;
if ( F_144 ( V_3 ) ) {
V_368 = ( V_1 >> 4 ) & 0xf ;
F_145 ( V_3 , L_107 ,
F_38 ( V_368 ) , V_1 , V_367 ) ;
} else {
F_145 ( V_3 , L_108 ,
V_1 , V_367 ) ;
}
}
struct V_14 * F_146 ( struct V_14 * V_240 )
{
struct V_2 * V_3 = V_240 -> V_3 ;
struct V_14 * V_371 = & V_3 -> V_21 [ 1 - V_240 -> V_24 ] ;
if ( ! F_8 ( V_371 ) )
return NULL ;
return V_371 ;
}
int F_141 ( struct V_2 * V_3 , T_1 V_39 )
{
T_1 V_1 , V_135 , V_372 ;
int V_180 , V_373 ;
if ( ! F_104 ( V_3 ) )
return - V_374 ;
V_180 = F_126 ( V_3 , V_369 , & V_1 ) ;
if ( V_180 == 0 && F_1 ( V_1 ) )
V_135 = ( V_1 >> 4 ) & 0xf ;
else
V_135 = V_3 -> V_278 ;
V_372 = V_3 -> V_277 ;
if ( V_372 <= 1 )
return - V_118 ;
V_373 = F_33 ( V_372 ) - 1 ;
V_372 &= ~ ( 1 << V_373 ) ;
if ( V_135 > 1 )
V_372 &= ( 1 << ( V_135 - 1 ) ) - 1 ;
else
V_372 &= 1 ;
if ( ! V_372 )
return - V_118 ;
if ( V_39 ) {
if ( V_372 & ( ( 1 << V_39 ) - 1 ) )
V_372 &= ( 1 << V_39 ) - 1 ;
else {
V_373 = F_147 ( V_372 ) - 1 ;
V_372 = 1 << V_373 ;
}
}
V_3 -> V_277 = V_372 ;
F_148 ( V_3 , L_109 ,
F_38 ( F_33 ( V_372 ) ) ) ;
return 0 ;
}
static int F_149 ( struct V_2 * V_3 , T_1 * V_367 )
{
struct V_2 * V_375 = & V_3 -> V_5 -> V_3 ;
T_1 V_376 , V_274 , V_135 ;
V_376 = V_3 -> V_277 ;
if ( ! F_13 ( V_3 ) && V_375 -> V_278 )
V_376 &= ( 1 << V_375 -> V_278 ) - 1 ;
if ( V_376 == V_377 )
V_274 = 0 ;
else
V_274 = F_33 ( V_376 ) ;
V_135 = ( * V_367 >> 4 ) & 0xf ;
* V_367 = ( * V_367 & ~ 0xf0 ) | ( ( V_274 & 0xf ) << 4 ) ;
return V_135 != V_274 ;
}
static int F_150 ( struct V_2 * V_3 )
{
T_1 V_367 ;
if ( F_126 ( V_3 , V_370 , & V_367 ) )
return 1 ;
return F_149 ( V_3 , & V_367 ) ;
}
int F_151 ( struct V_2 * V_3 )
{
T_1 V_367 ;
int V_180 ;
if ( ( V_180 = F_126 ( V_3 , V_370 , & V_367 ) ) )
return V_180 ;
if ( ! F_149 ( V_3 , & V_367 ) )
return 0 ;
if ( ( V_180 = F_152 ( V_3 , V_370 , V_367 ) ) )
return V_180 ;
return 1 ;
}
static void F_153 ( const struct V_378 * V_379 , struct V_378 * V_380 , int V_381 , int V_382 )
{
V_380 -> V_383 = F_154 ( V_379 -> V_383 * 1000 , V_381 ) ;
V_380 -> V_384 = F_154 ( V_379 -> V_384 * 1000 , V_381 ) ;
V_380 -> V_385 = F_154 ( V_379 -> V_385 * 1000 , V_381 ) ;
V_380 -> V_386 = F_154 ( V_379 -> V_386 * 1000 , V_381 ) ;
V_380 -> V_387 = F_154 ( V_379 -> V_387 * 1000 , V_381 ) ;
V_380 -> V_388 = F_154 ( V_379 -> V_388 * 1000 , V_381 ) ;
V_380 -> V_389 = F_154 ( V_379 -> V_389 * 1000 , V_381 ) ;
V_380 -> V_390 = F_154 ( V_379 -> V_390 * 1000 , V_381 ) ;
V_380 -> V_391 = F_154 ( V_379 -> V_391 * 1000 , V_382 ) ;
}
void F_155 ( const struct V_378 * V_392 , const struct V_378 * V_393 ,
struct V_378 * V_394 , unsigned int V_395 )
{
if ( V_395 & V_396 ) V_394 -> V_383 = V_312 ( V_392 -> V_383 , V_393 -> V_383 ) ;
if ( V_395 & V_397 ) V_394 -> V_384 = V_312 ( V_392 -> V_384 , V_393 -> V_384 ) ;
if ( V_395 & V_398 ) V_394 -> V_385 = V_312 ( V_392 -> V_385 , V_393 -> V_385 ) ;
if ( V_395 & V_399 ) V_394 -> V_386 = V_312 ( V_392 -> V_386 , V_393 -> V_386 ) ;
if ( V_395 & V_400 ) V_394 -> V_387 = V_312 ( V_392 -> V_387 , V_393 -> V_387 ) ;
if ( V_395 & V_401 ) V_394 -> V_388 = V_312 ( V_392 -> V_388 , V_393 -> V_388 ) ;
if ( V_395 & V_402 ) V_394 -> V_389 = V_312 ( V_392 -> V_389 , V_393 -> V_389 ) ;
if ( V_395 & V_403 ) V_394 -> V_390 = V_312 ( V_392 -> V_390 , V_393 -> V_390 ) ;
if ( V_395 & V_404 ) V_394 -> V_391 = V_312 ( V_392 -> V_391 , V_393 -> V_391 ) ;
}
const struct V_378 * F_156 ( T_2 V_133 )
{
const struct V_378 * V_379 = V_378 ;
while ( V_133 > V_379 -> V_7 )
V_379 ++ ;
if ( V_133 == V_379 -> V_7 )
return V_379 ;
F_157 ( true , L_110 ,
V_255 , V_133 ) ;
return NULL ;
}
int F_158 ( struct V_14 * V_240 , unsigned short V_405 ,
struct V_378 * V_379 , int V_381 , int V_382 )
{
const T_4 * V_142 = V_240 -> V_142 ;
const struct V_378 * V_143 ;
struct V_378 V_147 ;
if ( ! ( V_143 = F_156 ( V_405 ) ) )
return - V_118 ;
memcpy ( V_379 , V_143 , sizeof( * V_143 ) ) ;
if ( V_142 [ V_184 ] & 2 ) {
memset ( & V_147 , 0 , sizeof( V_147 ) ) ;
if ( V_405 >= V_359 && V_405 < V_406 ) {
if ( V_405 <= V_246 )
V_147 . V_390 = V_147 . V_386 = V_142 [ V_247 ] ;
else if ( ( V_405 <= V_407 ) ||
( V_405 == V_244 && ! F_62 ( V_142 ) ) )
V_147 . V_390 = V_147 . V_386 = V_142 [ V_408 ] ;
} else if ( V_405 >= V_409 && V_405 <= V_410 )
V_147 . V_390 = V_142 [ V_411 ] ;
F_155 ( & V_147 , V_379 , V_379 , V_403 | V_399 ) ;
}
F_153 ( V_379 , V_379 , V_381 , V_382 ) ;
if ( V_405 > V_245 ) {
F_158 ( V_240 , V_240 -> V_243 , & V_147 , V_381 , V_382 ) ;
F_155 ( & V_147 , V_379 , V_379 , V_412 ) ;
}
if ( V_379 -> V_384 + V_379 -> V_385 < V_379 -> V_386 ) {
V_379 -> V_384 += ( V_379 -> V_386 - ( V_379 -> V_384 + V_379 -> V_385 ) ) / 2 ;
V_379 -> V_385 = V_379 -> V_386 - V_379 -> V_384 ;
}
if ( V_379 -> V_387 + V_379 -> V_388 < V_379 -> V_390 ) {
V_379 -> V_387 += ( V_379 -> V_390 - ( V_379 -> V_387 + V_379 -> V_388 ) ) / 2 ;
V_379 -> V_388 = V_379 -> V_390 - V_379 -> V_387 ;
}
if ( V_379 -> V_387 + V_379 -> V_388 > V_379 -> V_390 )
V_379 -> V_390 = V_379 -> V_387 + V_379 -> V_388 ;
return 0 ;
}
T_2 F_159 ( unsigned int V_413 , int V_390 )
{
T_2 V_414 = 0xff , V_415 = 0xff ;
const struct V_127 * V_128 ;
const struct V_378 * V_379 ;
for ( V_128 = V_129 ; V_128 -> V_130 >= 0 ; V_128 ++ )
if ( V_128 -> V_130 == V_413 )
V_414 = V_128 -> V_132 ;
for ( V_379 = F_156 ( V_414 ) ;
V_379 && F_35 ( V_379 -> V_7 ) == V_413 ; V_379 ++ ) {
unsigned short V_416 ;
switch ( V_413 ) {
case V_120 :
case V_122 :
V_416 = V_379 -> V_390 ;
break;
case V_124 :
V_416 = V_379 -> V_391 ;
break;
default:
return 0xff ;
}
if ( V_390 > V_416 )
break;
V_415 = V_379 -> V_7 ;
}
return V_415 ;
}
int F_142 ( struct V_14 * V_15 , unsigned int V_417 )
{
char V_238 [ 32 ] ;
unsigned long V_418 , V_47 ;
unsigned long V_44 , V_45 , V_46 ;
int V_419 , V_126 ;
V_419 = ! ! ( V_417 & V_420 ) ;
V_417 &= ~ V_420 ;
V_47 = V_418 = F_31 ( V_15 -> V_44 ,
V_15 -> V_45 ,
V_15 -> V_46 ) ;
F_16 ( V_47 , & V_44 , & V_45 , & V_46 ) ;
switch ( V_417 ) {
case V_366 :
V_126 = F_33 ( V_44 ) - 1 ;
V_44 &= ~ ( 1 << V_126 ) ;
break;
case V_421 :
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
case V_422 :
V_46 &= V_423 ;
break;
case V_424 :
V_44 &= 1 ;
case V_425 :
V_45 = 0 ;
V_46 = 0 ;
break;
default:
F_70 () ;
}
V_47 &= F_31 ( V_44 , V_45 , V_46 ) ;
if ( ! ( V_47 & V_121 ) || V_47 == V_418 )
return - V_264 ;
if ( ! V_419 ) {
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
static int F_160 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_171 * V_172 = & V_15 -> V_3 -> V_173 ;
const bool V_426 = V_15 -> V_48 & V_427 ;
const char * V_428 = L_67 ;
int V_429 = 0 ;
unsigned int V_157 = 0 ;
int V_180 ;
V_15 -> V_42 &= ~ V_91 ;
if ( V_15 -> V_413 == V_120 )
V_15 -> V_42 |= V_91 ;
if ( V_426 && V_5 -> V_42 & V_430 && F_107 ( V_15 -> V_142 ) )
V_428 = L_114 ;
else {
if ( V_426 )
F_24 ( V_15 ,
L_115
L_116 ) ;
V_157 = F_161 ( V_15 ) ;
}
if ( V_157 & ~ V_162 )
goto V_364;
V_172 -> V_25 . V_42 |= V_431 ;
V_180 = F_162 ( V_15 , V_141 , 0 ) ;
V_172 -> V_25 . V_42 &= ~ V_431 ;
if ( V_180 )
return V_180 ;
if ( V_15 -> V_413 == V_120 ) {
if ( F_62 ( V_15 -> V_142 ) )
V_429 = 1 ;
if ( F_101 ( V_15 -> V_142 ) == 0 &&
V_15 -> V_243 <= V_246 )
V_429 = 1 ;
if ( ! F_91 ( V_15 -> V_142 ) && V_15 -> V_243 <= V_246 )
V_429 = 1 ;
}
if ( V_15 -> V_413 == V_122 &&
V_15 -> V_360 == V_409 &&
( V_15 -> V_142 [ 63 ] >> 8 ) & 1 )
V_429 = 1 ;
if ( V_15 -> V_133 == F_32 ( F_61 ( V_15 -> V_142 ) ) )
V_429 = 1 ;
if ( V_157 & V_162 ) {
if ( ! V_429 )
goto V_364;
else
V_428 = L_117 ;
}
F_30 ( L_118 ,
V_15 -> V_413 , ( int ) V_15 -> V_133 ) ;
F_57 ( V_15 , L_119 ,
F_36 ( F_34 ( V_15 -> V_133 ) ) ,
V_428 ) ;
return 0 ;
V_364:
F_59 ( V_15 , L_120 , V_157 ) ;
return - V_165 ;
}
int F_163 ( struct V_2 * V_3 , struct V_14 * * V_432 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_14 * V_15 ;
int V_180 = 0 , V_433 = 0 , V_434 = 0 ;
F_139 (dev, link, ENABLED) {
unsigned long V_44 , V_435 ;
unsigned int V_436 ;
V_436 = V_437 ;
if ( V_15 -> V_181 == V_138 )
V_436 = V_438 ;
else if ( F_62 ( V_15 -> V_142 ) )
V_436 = V_439 ;
F_164 ( V_15 ) ;
F_15 ( V_15 ) ;
V_44 = F_31 ( V_15 -> V_44 , 0 , 0 ) ;
if ( V_440 & V_436 )
V_435 = F_31 ( 0 , V_15 -> V_45 ,
V_15 -> V_46 ) ;
else
V_435 = 0 ;
V_15 -> V_243 = F_32 ( V_44 ) ;
V_15 -> V_360 = F_32 ( V_435 ) ;
V_434 = 1 ;
if ( F_165 ( V_15 ) )
V_433 = 1 ;
}
if ( ! V_434 )
goto V_441;
F_139 (dev, link, ENABLED) {
if ( V_15 -> V_243 == 0xff ) {
F_24 ( V_15 , L_121 ) ;
V_180 = - V_118 ;
goto V_441;
}
V_15 -> V_133 = V_15 -> V_243 ;
V_15 -> V_413 = V_120 ;
if ( V_5 -> V_213 -> V_361 )
V_5 -> V_213 -> V_361 ( V_5 , V_15 ) ;
}
F_139 (dev, link, ENABLED) {
if ( ! F_165 ( V_15 ) )
continue;
V_15 -> V_133 = V_15 -> V_360 ;
V_15 -> V_413 = F_35 ( V_15 -> V_360 ) ;
if ( V_5 -> V_213 -> V_442 )
V_5 -> V_213 -> V_442 ( V_5 , V_15 ) ;
}
F_139 (dev, link, ENABLED) {
V_180 = F_160 ( V_15 ) ;
if ( V_180 )
goto V_441;
}
if ( V_433 && ( V_5 -> V_269 -> V_42 & V_443 ) )
V_5 -> V_269 -> V_444 = V_5 ;
V_441:
if ( V_180 )
* V_432 = V_15 ;
return V_180 ;
}
int F_166 ( struct V_2 * V_3 , unsigned long V_445 ,
int (* F_167)( struct V_2 * V_3 ) )
{
unsigned long V_446 = V_447 ;
unsigned long V_448 ;
int V_449 = 0 ;
if ( V_3 -> V_5 -> V_269 -> V_42 & V_450 )
V_448 = F_168 ( V_446 , V_451 ) ;
else
V_448 = F_168 ( V_446 , V_452 ) ;
F_87 ( V_3 == V_3 -> V_5 -> V_12 ) ;
if ( F_169 ( V_448 , V_445 ) )
V_448 = V_445 ;
while ( 1 ) {
unsigned long V_453 = V_447 ;
int V_454 , V_368 ;
V_454 = V_368 = F_167 ( V_3 ) ;
if ( V_454 > 0 )
return 0 ;
if ( V_454 == - V_259 ) {
if ( F_170 ( V_3 ) )
V_454 = 0 ;
else if ( ( V_3 -> V_5 -> V_42 & V_430 ) &&
! F_171 ( V_3 ) &&
F_172 ( V_453 , V_448 ) )
V_454 = 0 ;
}
if ( V_454 )
return V_454 ;
if ( F_169 ( V_453 , V_445 ) )
return - V_455 ;
if ( ! V_449 && F_169 ( V_453 , V_446 + 5 * V_456 ) &&
( V_445 - V_453 > 3 * V_456 ) ) {
F_148 ( V_3 ,
L_122
L_123 , V_368 ) ;
V_449 = 1 ;
}
F_173 ( V_3 -> V_5 , 50 ) ;
}
}
int F_174 ( struct V_2 * V_3 , unsigned long V_445 ,
int (* F_167)( struct V_2 * V_3 ) )
{
F_173 ( V_3 -> V_5 , V_457 ) ;
return F_166 ( V_3 , V_445 , F_167 ) ;
}
int F_175 ( struct V_2 * V_3 , const unsigned long * V_458 ,
unsigned long V_445 )
{
unsigned long V_459 = V_458 [ 0 ] ;
unsigned long V_460 = V_458 [ 1 ] ;
unsigned long V_461 , V_379 ;
T_1 V_462 , V_463 ;
int V_180 ;
V_379 = F_168 ( V_447 , V_458 [ 2 ] ) ;
if ( F_172 ( V_379 , V_445 ) )
V_445 = V_379 ;
if ( ( V_180 = F_126 ( V_3 , V_369 , & V_463 ) ) )
return V_180 ;
V_463 &= 0xf ;
V_462 = V_463 ;
V_461 = V_447 ;
while ( 1 ) {
F_173 ( V_3 -> V_5 , V_459 ) ;
if ( ( V_180 = F_126 ( V_3 , V_369 , & V_463 ) ) )
return V_180 ;
V_463 &= 0xf ;
if ( V_463 == V_462 ) {
if ( V_463 == 1 && F_172 ( V_447 , V_445 ) )
continue;
if ( F_169 ( V_447 ,
F_168 ( V_461 , V_460 ) ) )
return 0 ;
continue;
}
V_462 = V_463 ;
V_461 = V_447 ;
if ( F_169 ( V_447 , V_445 ) )
return - V_464 ;
}
}
int F_176 ( struct V_2 * V_3 , const unsigned long * V_458 ,
unsigned long V_445 )
{
int V_357 = V_465 ;
T_1 V_367 , V_466 ;
int V_180 ;
if ( ( V_180 = F_126 ( V_3 , V_370 , & V_367 ) ) )
return V_180 ;
do {
V_367 = ( V_367 & 0x0f0 ) | 0x300 ;
if ( ( V_180 = F_152 ( V_3 , V_370 , V_367 ) ) )
return V_180 ;
F_173 ( V_3 -> V_5 , 200 ) ;
if ( ( V_180 = F_126 ( V_3 , V_370 , & V_367 ) ) )
return V_180 ;
} while ( ( V_367 & 0xf0f ) != 0x300 && -- V_357 );
if ( ( V_367 & 0xf0f ) != 0x300 ) {
F_148 ( V_3 , L_124 ,
V_367 ) ;
return 0 ;
}
if ( V_357 < V_465 )
F_148 ( V_3 , L_125 ,
V_465 - V_357 ) ;
if ( ( V_180 = F_175 ( V_3 , V_458 , V_445 ) ) )
return V_180 ;
if ( ! ( V_180 = F_126 ( V_3 , V_467 , & V_466 ) ) )
V_180 = F_152 ( V_3 , V_467 , V_466 ) ;
return V_180 != - V_118 ? V_180 : 0 ;
}
int F_177 ( struct V_2 * V_3 , enum V_468 V_469 ,
bool V_470 )
{
struct V_171 * V_172 = & V_3 -> V_173 ;
bool V_471 = false ;
T_1 V_367 ;
int V_180 ;
V_180 = F_126 ( V_3 , V_370 , & V_367 ) ;
if ( V_180 )
return V_180 ;
switch ( V_469 ) {
case V_472 :
V_367 |= ( 0x7 << 8 ) ;
if ( V_470 ) {
V_367 |= ( 0x4 << 12 ) ;
V_471 = true ;
}
break;
case V_473 :
V_367 &= ~ ( 0x1 << 8 ) ;
V_367 |= ( 0x6 << 8 ) ;
break;
case V_474 :
if ( F_178 ( V_3 ) > 0 )
V_367 &= ~ ( 0x7 << 8 ) ;
else {
V_367 &= ~ 0xf ;
V_367 |= ( 0x1 << 2 ) ;
}
break;
default:
F_87 ( 1 ) ;
}
V_180 = F_152 ( V_3 , V_370 , V_367 ) ;
if ( V_180 )
return V_180 ;
if ( V_471 )
F_179 ( 10 ) ;
V_172 -> V_25 . V_466 &= ~ V_475 ;
return F_152 ( V_3 , V_467 , V_475 ) ;
}
int F_180 ( struct V_2 * V_3 , unsigned long V_445 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_171 * V_172 = & V_3 -> V_173 ;
const unsigned long * V_476 = F_181 ( V_172 ) ;
int V_180 ;
if ( V_172 -> V_25 . V_477 & V_478 )
return 0 ;
if ( V_5 -> V_42 & V_430 ) {
V_180 = F_176 ( V_3 , V_476 , V_445 ) ;
if ( V_180 && V_180 != - V_374 )
F_148 ( V_3 ,
L_126 ,
V_180 ) ;
}
if ( F_182 ( V_3 ) )
V_172 -> V_25 . V_477 &= ~ V_479 ;
return 0 ;
}
int F_183 ( struct V_2 * V_3 , const unsigned long * V_476 ,
unsigned long V_445 ,
bool * V_480 , int (* F_167)( struct V_2 * ) )
{
T_1 V_367 ;
int V_180 ;
F_30 ( L_127 ) ;
if ( V_480 )
* V_480 = false ;
if ( F_150 ( V_3 ) ) {
if ( ( V_180 = F_126 ( V_3 , V_370 , & V_367 ) ) )
goto V_441;
V_367 = ( V_367 & 0x0f0 ) | 0x304 ;
if ( ( V_180 = F_152 ( V_3 , V_370 , V_367 ) ) )
goto V_441;
F_151 ( V_3 ) ;
}
if ( ( V_180 = F_126 ( V_3 , V_370 , & V_367 ) ) )
goto V_441;
V_367 = ( V_367 & 0x0f0 ) | 0x301 ;
if ( ( V_180 = F_184 ( V_3 , V_370 , V_367 ) ) )
goto V_441;
F_173 ( V_3 -> V_5 , 1 ) ;
V_180 = F_176 ( V_3 , V_476 , V_445 ) ;
if ( V_180 )
goto V_441;
if ( F_182 ( V_3 ) )
goto V_441;
if ( V_480 )
* V_480 = true ;
if ( F_185 ( V_3 -> V_5 ) && F_13 ( V_3 ) ) {
if ( F_167 ) {
unsigned long V_481 ;
V_481 = F_168 ( V_447 ,
V_482 ) ;
if ( F_169 ( V_481 , V_445 ) )
V_481 = V_445 ;
F_166 ( V_3 , V_481 , F_167 ) ;
}
V_180 = - V_279 ;
goto V_441;
}
V_180 = 0 ;
if ( F_167 )
V_180 = F_166 ( V_3 , V_445 , F_167 ) ;
V_441:
if ( V_180 && V_180 != - V_279 ) {
if ( V_480 )
* V_480 = false ;
F_186 ( V_3 , L_128 , V_180 ) ;
}
F_30 ( L_129 , V_180 ) ;
return V_180 ;
}
int F_187 ( struct V_2 * V_3 , unsigned int * V_181 ,
unsigned long V_445 )
{
const unsigned long * V_476 = F_181 ( & V_3 -> V_173 ) ;
bool V_480 ;
int V_180 ;
V_180 = F_183 ( V_3 , V_476 , V_445 , & V_480 , NULL ) ;
return V_480 ? - V_279 : V_180 ;
}
void F_188 ( struct V_2 * V_3 , unsigned int * V_355 )
{
T_1 V_466 ;
F_30 ( L_127 ) ;
if ( ! F_126 ( V_3 , V_467 , & V_466 ) )
F_152 ( V_3 , V_467 , V_466 ) ;
F_143 ( V_3 ) ;
F_30 ( L_130 ) ;
}
static int F_189 ( struct V_14 * V_15 , unsigned int V_483 ,
const T_4 * V_484 )
{
const T_4 * V_485 = V_15 -> V_142 ;
unsigned char V_486 [ 2 ] [ V_301 + 1 ] ;
unsigned char V_487 [ 2 ] [ V_488 + 1 ] ;
if ( V_15 -> V_181 != V_483 ) {
F_57 ( V_15 , L_131 ,
V_15 -> V_181 , V_483 ) ;
return 0 ;
}
F_41 ( V_485 , V_486 [ 0 ] , V_310 , sizeof( V_486 [ 0 ] ) ) ;
F_41 ( V_484 , V_486 [ 1 ] , V_310 , sizeof( V_486 [ 1 ] ) ) ;
F_41 ( V_485 , V_487 [ 0 ] , V_489 , sizeof( V_487 [ 0 ] ) ) ;
F_41 ( V_484 , V_487 [ 1 ] , V_489 , sizeof( V_487 [ 1 ] ) ) ;
if ( strcmp ( V_486 [ 0 ] , V_486 [ 1 ] ) ) {
F_57 ( V_15 , L_132 ,
V_486 [ 0 ] , V_486 [ 1 ] ) ;
return 0 ;
}
if ( strcmp ( V_487 [ 0 ] , V_487 [ 1 ] ) ) {
F_57 ( V_15 , L_133 ,
V_487 [ 0 ] , V_487 [ 1 ] ) ;
return 0 ;
}
return 1 ;
}
int F_58 ( struct V_14 * V_15 , unsigned int V_490 )
{
unsigned int V_181 = V_15 -> V_181 ;
T_4 * V_142 = ( void * ) V_15 -> V_3 -> V_5 -> V_318 ;
int V_180 ;
V_180 = F_94 ( V_15 , & V_181 , V_490 , V_142 ) ;
if ( V_180 )
return V_180 ;
if ( ! F_189 ( V_15 , V_181 , V_142 ) )
return - V_259 ;
memcpy ( V_15 -> V_142 , V_142 , sizeof( V_142 [ 0 ] ) * V_249 ) ;
return 0 ;
}
int F_162 ( struct V_14 * V_15 , unsigned int V_483 ,
unsigned int V_490 )
{
T_3 V_307 = V_15 -> V_307 ;
T_3 V_183 = V_15 -> V_183 ;
int V_180 ;
if ( ! F_8 ( V_15 ) )
return - V_259 ;
if ( F_190 ( V_483 ) &&
V_483 != V_137 &&
V_483 != V_138 &&
V_483 != V_140 ) {
F_57 ( V_15 , L_134 ,
V_15 -> V_181 , V_483 ) ;
V_180 = - V_259 ;
goto V_364;
}
V_180 = F_58 ( V_15 , V_490 ) ;
if ( V_180 )
goto V_364;
V_180 = F_113 ( V_15 ) ;
if ( V_180 )
goto V_364;
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
V_364:
F_59 ( V_15 , L_140 , V_180 ) ;
return V_180 ;
}
static int F_191 ( const char * V_491 , const char * V_492 )
{
do {
if ( * V_491 == * V_492 || * V_492 == '?' ) {
if ( ! * V_492 ++ )
return 0 ;
} else {
if ( ! * V_491 || * V_492 != '[' )
break;
while ( * ++ V_492 && * V_492 != ']' && * V_491 != * V_492 ) {
if ( * V_492 == '-' && * ( V_492 - 1 ) != '[' )
if ( * V_491 > * ( V_492 - 1 ) && * V_491 < * ( V_492 + 1 ) ) {
++ V_492 ;
break;
}
}
if ( ! * V_492 || * V_492 == ']' )
return 1 ;
while ( * V_492 && * V_492 ++ != ']' ) ;
}
} while ( * ++ V_491 && * V_492 );
if ( * V_492 == '*' ) {
if ( ! * ++ V_492 )
return 0 ;
while ( * V_491 ) {
if ( F_191 ( V_491 , V_492 ) == 0 )
return 0 ;
++ V_491 ;
}
}
if ( ! * V_491 && ! * V_492 )
return 0 ;
return 1 ;
}
static unsigned long F_106 ( const struct V_14 * V_15 )
{
unsigned char V_493 [ V_301 + 1 ] ;
unsigned char V_494 [ V_299 + 1 ] ;
const struct V_495 * V_496 = V_497 ;
F_41 ( V_15 -> V_142 , V_493 , V_310 , sizeof( V_493 ) ) ;
F_41 ( V_15 -> V_142 , V_494 , V_309 , sizeof( V_494 ) ) ;
while ( V_496 -> V_493 ) {
if ( ! F_191 ( V_493 , V_496 -> V_493 ) ) {
if ( V_496 -> V_494 == NULL )
return V_496 -> V_48 ;
if ( ! F_191 ( V_494 , V_496 -> V_494 ) )
return V_496 -> V_48 ;
}
V_496 ++ ;
}
return 0 ;
}
static int F_192 ( const struct V_14 * V_15 )
{
if ( ( V_15 -> V_3 -> V_5 -> V_42 & V_498 ) &&
( V_15 -> V_42 & V_336 ) )
return 1 ;
return ( V_15 -> V_48 & V_499 ) ? 1 : 0 ;
}
static int F_193 ( struct V_14 * V_15 )
{
if ( V_15 -> V_48 & V_500 )
return F_194 ( V_15 -> V_142 ) ;
return F_195 ( V_15 -> V_142 ) ;
}
static int F_196 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
struct V_14 * V_15 ;
if ( V_5 -> V_33 == V_351 )
return 1 ;
if ( V_5 -> V_33 == V_352 || V_5 -> V_33 == V_281 )
return 0 ;
if ( V_5 -> V_33 == V_501 )
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
struct V_502 * V_269 = V_5 -> V_269 ;
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
if ( ( V_269 -> V_42 & V_443 ) &&
V_269 -> V_444 && V_269 -> V_444 != V_5 ) {
V_47 &= ~ ( V_123 | V_125 ) ;
F_24 ( V_15 ,
L_142 ) ;
}
if ( V_5 -> V_42 & V_242 )
V_47 &= F_92 ( V_15 ) ;
if ( V_5 -> V_213 -> V_503 )
V_47 = V_5 -> V_213 -> V_503 ( V_15 , V_47 ) ;
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
V_68 . V_71 = V_504 ;
V_68 . V_72 = V_505 ;
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
unsigned int F_100 ( struct V_14 * V_15 , T_2 V_506 , T_2 V_72 )
{
struct V_67 V_68 ;
unsigned int V_157 ;
F_30 ( L_146 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_504 ;
V_68 . V_72 = V_506 ;
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
return V_507 ;
F_30 ( L_147 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_508 ;
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
struct V_199 * V_225 = V_193 -> V_225 ;
int V_509 = V_193 -> V_198 ;
F_199 ( V_225 == NULL ) ;
F_200 ( L_148 , V_193 -> V_201 ) ;
if ( V_193 -> V_201 )
F_201 ( V_5 -> V_15 , V_225 , V_193 -> V_510 , V_509 ) ;
V_193 -> V_42 &= ~ V_511 ;
V_193 -> V_225 = NULL ;
}
int F_202 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
if ( ! ( V_193 -> V_15 -> V_48 & V_512 ) &&
F_5 ( V_193 -> V_227 & 15 ) )
return 1 ;
if ( V_5 -> V_213 -> V_513 )
return V_5 -> V_213 -> V_513 ( V_193 ) ;
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
return V_514 ;
}
void F_205 ( struct V_192 * V_193 ) { }
void F_74 ( struct V_192 * V_193 , struct V_199 * V_225 ,
unsigned int V_201 )
{
V_193 -> V_225 = V_225 ;
V_193 -> V_201 = V_201 ;
V_193 -> V_515 = V_193 -> V_225 ;
}
static int F_206 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
unsigned int V_201 ;
F_200 ( L_149 , V_5 -> V_31 ) ;
V_201 = F_207 ( V_5 -> V_15 , V_193 -> V_225 , V_193 -> V_201 , V_193 -> V_198 ) ;
if ( V_201 < 1 )
return - 1 ;
F_30 ( L_150 , V_201 ) ;
V_193 -> V_510 = V_193 -> V_201 ;
V_193 -> V_201 = V_201 ;
V_193 -> V_42 |= V_511 ;
return 0 ;
}
void F_98 ( T_4 * V_238 , unsigned int V_516 )
{
#ifdef F_208
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < V_516 ; V_25 ++ )
V_238 [ V_25 ] = F_209 ( V_238 [ V_25 ] ) ;
#endif
}
static struct V_192 * F_210 ( struct V_4 * V_5 )
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
F_199 ( ! ( V_193 -> V_42 & V_230 ) ) ;
V_5 = V_193 -> V_5 ;
V_3 = V_193 -> V_15 -> V_3 ;
if ( F_27 ( V_193 -> V_42 & V_511 ) )
F_198 ( V_193 ) ;
if ( V_193 -> V_68 . V_92 == V_112 ) {
V_3 -> V_218 &= ~ ( 1 << V_193 -> V_107 ) ;
if ( ! V_3 -> V_218 )
V_5 -> V_220 -- ;
} else {
V_3 -> V_217 = V_221 ;
V_5 -> V_220 -- ;
}
if ( F_5 ( V_193 -> V_42 & V_517 &&
V_5 -> V_518 == V_3 ) )
V_5 -> V_518 = NULL ;
V_193 -> V_42 &= ~ V_230 ;
V_5 -> V_219 &= ~ ( 1 << V_193 -> V_107 ) ;
V_193 -> V_228 ( V_193 ) ;
}
static void F_214 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
V_193 -> V_234 . V_42 = V_193 -> V_68 . V_42 ;
V_5 -> V_213 -> V_519 ( V_193 ) ;
}
static void F_215 ( struct V_192 * V_193 )
{
struct V_14 * V_15 = V_193 -> V_15 ;
if ( F_216 ( V_193 -> V_68 . V_92 ) )
return;
if ( ( V_15 -> V_45 || V_15 -> V_46 ) && F_217 ( V_193 -> V_68 . V_92 ) )
return;
V_15 -> V_42 &= ~ V_520 ;
}
void F_83 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
if ( V_5 -> V_213 -> V_214 ) {
struct V_14 * V_15 = V_193 -> V_15 ;
struct V_521 * V_522 = & V_15 -> V_3 -> V_523 ;
if ( F_5 ( V_193 -> V_157 ) )
V_193 -> V_42 |= V_233 ;
if ( F_5 ( F_218 ( V_193 -> V_107 ) ) ) {
F_214 ( V_193 ) ;
F_213 ( V_193 ) ;
return;
}
if ( F_5 ( V_193 -> V_42 & V_233 ) ) {
F_214 ( V_193 ) ;
F_219 ( V_193 ) ;
return;
}
F_199 ( V_5 -> V_210 & V_211 ) ;
if ( V_193 -> V_42 & V_223 )
F_214 ( V_193 ) ;
switch ( V_193 -> V_68 . V_71 ) {
case V_504 :
if ( V_193 -> V_68 . V_72 != V_524 &&
V_193 -> V_68 . V_72 != V_525 )
break;
case V_508 :
case V_526 :
V_522 -> V_527 [ V_15 -> V_24 ] |= V_528 ;
F_220 ( V_5 ) ;
break;
case V_529 :
V_15 -> V_42 |= V_530 ;
break;
}
if ( F_5 ( V_15 -> V_42 & V_520 ) )
F_215 ( V_193 ) ;
F_213 ( V_193 ) ;
} else {
if ( V_193 -> V_42 & V_531 )
return;
if ( V_193 -> V_157 || V_193 -> V_42 & V_223 )
F_214 ( V_193 ) ;
F_213 ( V_193 ) ;
}
}
int F_221 ( struct V_4 * V_5 , T_1 V_219 )
{
int V_532 = 0 ;
T_1 V_533 ;
V_533 = V_5 -> V_219 ^ V_219 ;
if ( F_5 ( V_533 & V_219 ) ) {
F_222 ( V_5 , L_151 ,
V_5 -> V_219 , V_219 ) ;
return - V_118 ;
}
while ( V_533 ) {
struct V_192 * V_193 ;
unsigned int V_107 = F_223 ( V_533 ) ;
V_193 = F_224 ( V_5 , V_107 ) ;
if ( V_193 ) {
F_83 ( V_193 ) ;
V_532 ++ ;
}
V_533 &= ~ ( 1 << V_107 ) ;
}
return V_532 ;
}
void F_75 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
struct V_2 * V_3 = V_193 -> V_15 -> V_3 ;
T_2 V_534 = V_193 -> V_68 . V_92 ;
F_199 ( V_5 -> V_213 -> V_214 && F_204 ( V_3 -> V_217 ) ) ;
if ( F_225 ( V_534 ) ) {
F_199 ( V_3 -> V_218 & ( 1 << V_193 -> V_107 ) ) ;
if ( ! V_3 -> V_218 )
V_5 -> V_220 ++ ;
V_3 -> V_218 |= 1 << V_193 -> V_107 ;
} else {
F_199 ( V_3 -> V_218 ) ;
V_5 -> V_220 ++ ;
V_3 -> V_217 = V_193 -> V_107 ;
}
V_193 -> V_42 |= V_230 ;
V_5 -> V_219 |= 1 << V_193 -> V_107 ;
if ( F_199 ( F_226 ( V_534 ) &&
( ! V_193 -> V_225 || ! V_193 -> V_201 || ! V_193 -> V_227 ) ) )
goto V_535;
if ( F_227 ( V_534 ) || ( F_217 ( V_534 ) &&
( V_5 -> V_42 & V_536 ) ) )
if ( F_206 ( V_193 ) )
goto V_535;
if ( F_5 ( V_193 -> V_15 -> V_42 & V_530 ) ) {
V_3 -> V_523 . V_477 |= V_537 ;
F_228 ( & V_3 -> V_523 , L_152 ) ;
F_229 ( V_3 ) ;
return;
}
V_5 -> V_213 -> V_538 ( V_193 ) ;
V_193 -> V_157 |= V_5 -> V_213 -> V_539 ( V_193 ) ;
if ( F_5 ( V_193 -> V_157 ) )
goto V_540;
return;
V_535:
V_193 -> V_157 |= V_212 ;
V_540:
F_83 ( V_193 ) ;
}
int F_104 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
return ( V_5 -> V_42 & V_430 ) && V_5 -> V_213 -> V_541 ;
}
int F_126 ( struct V_2 * V_3 , int V_542 , T_1 * V_543 )
{
if ( F_13 ( V_3 ) ) {
if ( F_104 ( V_3 ) )
return V_3 -> V_5 -> V_213 -> V_541 ( V_3 , V_542 , V_543 ) ;
return - V_374 ;
}
return F_230 ( V_3 , V_542 , V_543 ) ;
}
int F_152 ( struct V_2 * V_3 , int V_542 , T_1 V_543 )
{
if ( F_13 ( V_3 ) ) {
if ( F_104 ( V_3 ) )
return V_3 -> V_5 -> V_213 -> V_544 ( V_3 , V_542 , V_543 ) ;
return - V_374 ;
}
return F_231 ( V_3 , V_542 , V_543 ) ;
}
int F_184 ( struct V_2 * V_3 , int V_542 , T_1 V_543 )
{
if ( F_13 ( V_3 ) ) {
int V_180 ;
if ( F_104 ( V_3 ) ) {
V_180 = V_3 -> V_5 -> V_213 -> V_544 ( V_3 , V_542 , V_543 ) ;
if ( V_180 == 0 )
V_180 = V_3 -> V_5 -> V_213 -> V_541 ( V_3 , V_542 , & V_543 ) ;
return V_180 ;
}
return - V_374 ;
}
return F_231 ( V_3 , V_542 , V_543 ) ;
}
bool F_144 ( struct V_2 * V_3 )
{
T_1 V_1 ;
if ( F_126 ( V_3 , V_369 , & V_1 ) == 0 &&
F_1 ( V_1 ) )
return true ;
return false ;
}
bool F_182 ( struct V_2 * V_3 )
{
T_1 V_1 ;
if ( F_126 ( V_3 , V_369 , & V_1 ) == 0 &&
! F_1 ( V_1 ) )
return true ;
return false ;
}
bool F_170 ( struct V_2 * V_3 )
{
struct V_2 * V_545 = V_3 -> V_5 -> V_12 ;
F_87 ( V_3 == V_545 ) ;
return F_144 ( V_3 ) ||
( V_545 && F_144 ( V_545 ) ) ;
}
bool F_171 ( struct V_2 * V_3 )
{
struct V_2 * V_545 = V_3 -> V_5 -> V_12 ;
F_87 ( V_3 == V_545 ) ;
return F_182 ( V_3 ) &&
( ! V_545 || F_182 ( V_545 ) ) ;
}
static int F_232 ( struct V_4 * V_5 , T_6 V_546 ,
unsigned int V_477 , unsigned int V_547 ,
int * V_548 )
{
struct V_2 * V_3 ;
unsigned long V_42 ;
int V_180 = 0 ;
if ( V_5 -> V_210 & V_549 ) {
if ( V_548 ) {
* V_548 = - V_279 ;
return 0 ;
}
F_233 ( V_5 ) ;
F_87 ( V_5 -> V_210 & V_549 ) ;
}
F_67 ( V_5 -> V_209 , V_42 ) ;
V_5 -> V_550 = V_546 ;
if ( V_548 )
V_5 -> V_551 = V_548 ;
else
V_5 -> V_551 = & V_180 ;
V_5 -> V_210 |= V_549 ;
F_197 (link, ap, HOST_FIRST) {
V_3 -> V_523 . V_477 |= V_477 ;
V_3 -> V_523 . V_42 |= V_547 ;
}
F_220 ( V_5 ) ;
F_68 ( V_5 -> V_209 , V_42 ) ;
if ( ! V_548 ) {
F_233 ( V_5 ) ;
F_87 ( V_5 -> V_210 & V_549 ) ;
}
return V_180 ;
}
static int F_234 ( struct V_4 * V_5 , T_6 V_546 , int * V_548 )
{
unsigned int V_547 = V_552 | V_553 |
V_554 ;
return F_232 ( V_5 , V_546 , 0 , V_547 , V_548 ) ;
}
static int F_235 ( struct V_21 * V_15 , T_6 V_546 )
{
struct V_4 * V_5 = F_236 ( V_15 ) ;
return F_234 ( V_5 , V_546 , NULL ) ;
}
static int F_237 ( struct V_21 * V_15 )
{
if ( F_238 ( V_15 ) )
return 0 ;
return F_235 ( V_15 , V_555 ) ;
}
static int F_239 ( struct V_21 * V_15 )
{
if ( F_238 ( V_15 ) )
return 0 ;
return F_235 ( V_15 , V_556 ) ;
}
static int F_240 ( struct V_21 * V_15 )
{
return F_235 ( V_15 , V_557 ) ;
}
static int F_241 ( struct V_4 * V_5 , T_6 V_546 ,
int * V_548 )
{
int V_180 ;
V_180 = F_232 ( V_5 , V_546 , V_537 ,
V_553 | V_552 , V_548 ) ;
return V_180 ;
}
static int F_242 ( struct V_21 * V_15 , T_6 V_546 )
{
struct V_4 * V_5 = F_236 ( V_15 ) ;
return F_241 ( V_5 , V_546 , NULL ) ;
}
static int F_243 ( struct V_21 * V_15 )
{
int V_180 ;
V_180 = F_242 ( V_15 , V_558 ) ;
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
struct V_14 * V_240 ;
F_197 (link, ap, HOST_FIRST) {
F_139 (adev, link, ENABLED)
if ( V_240 -> V_181 == V_138 &&
! F_248 ( V_240 ) )
return - V_455 ;
}
return F_249 ( V_15 ) ;
}
static int F_250 ( struct V_21 * V_15 )
{
return F_235 ( V_15 , V_559 ) ;
}
static int F_251 ( struct V_21 * V_15 )
{
return F_242 ( V_15 , V_560 ) ;
}
int F_252 ( struct V_4 * V_5 , int * V_548 )
{
return F_234 ( V_5 , V_555 , V_548 ) ;
}
int F_253 ( struct V_4 * V_5 , int * V_548 )
{
return F_241 ( V_5 , V_558 , V_548 ) ;
}
int F_254 ( struct V_502 * V_269 , T_6 V_546 )
{
V_269 -> V_15 -> V_561 . V_562 = V_546 ;
return 0 ;
}
void F_255 ( struct V_502 * V_269 )
{
V_269 -> V_15 -> V_561 . V_562 = V_563 ;
}
void F_256 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = F_9 ( V_15 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_42 ;
V_3 -> V_277 = V_3 -> V_40 ;
V_3 -> V_278 = 0 ;
F_67 ( V_5 -> V_209 , V_42 ) ;
V_15 -> V_42 &= ~ V_564 ;
V_15 -> V_48 = 0 ;
F_68 ( V_5 -> V_209 , V_42 ) ;
memset ( ( void * ) V_15 + V_565 , 0 ,
V_566 - V_565 ) ;
V_15 -> V_44 = V_377 ;
V_15 -> V_45 = V_377 ;
V_15 -> V_46 = V_377 ;
}
void F_257 ( struct V_4 * V_5 , struct V_2 * V_3 , int V_38 )
{
int V_25 ;
memset ( ( void * ) V_3 + V_567 , 0 ,
V_568 - V_567 ) ;
V_3 -> V_5 = V_5 ;
V_3 -> V_38 = V_38 ;
V_3 -> V_217 = V_221 ;
V_3 -> V_40 = V_377 ;
for ( V_25 = 0 ; V_25 < V_356 ; V_25 ++ ) {
struct V_14 * V_15 = & V_3 -> V_21 [ V_25 ] ;
V_15 -> V_3 = V_3 ;
V_15 -> V_24 = V_15 - V_3 -> V_21 ;
#ifdef F_258
V_15 -> V_569 = V_570 ;
#endif
F_256 ( V_15 ) ;
}
}
int F_259 ( struct V_2 * V_3 )
{
T_2 V_135 ;
int V_180 ;
V_180 = F_126 ( V_3 , V_370 , & V_3 -> V_571 ) ;
if ( V_180 )
return V_180 ;
V_135 = ( V_3 -> V_571 >> 4 ) & 0xf ;
if ( V_135 )
V_3 -> V_40 &= ( 1 << V_135 ) - 1 ;
F_12 ( V_3 ) ;
V_3 -> V_277 = V_3 -> V_40 ;
return 0 ;
}
struct V_4 * F_260 ( struct V_502 * V_269 )
{
struct V_4 * V_5 ;
F_30 ( L_127 ) ;
V_5 = F_261 ( sizeof( * V_5 ) , V_572 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_210 |= V_573 | V_211 ;
V_5 -> V_209 = & V_269 -> V_209 ;
V_5 -> V_31 = - 1 ;
V_5 -> V_269 = V_269 ;
V_5 -> V_15 = V_269 -> V_15 ;
#if F_262 ( V_574 )
V_5 -> V_575 = 0x00FF ;
#elif F_262 ( V_576 )
V_5 -> V_575 = V_577 | V_578 | V_579 | V_580 | V_581 ;
#else
V_5 -> V_575 = V_577 | V_581 | V_580 ;
#endif
F_263 ( & V_5 -> V_582 ) ;
F_264 ( & V_5 -> V_583 , V_584 ) ;
F_265 ( & V_5 -> V_585 , V_586 ) ;
F_266 ( & V_5 -> V_587 ) ;
F_267 ( & V_5 -> V_588 ) ;
F_268 ( & V_5 -> V_589 ) ;
F_269 ( & V_5 -> V_590 ) ;
V_5 -> V_590 . V_591 = V_592 ;
V_5 -> V_590 . V_593 = ( unsigned long ) V_5 ;
V_5 -> V_33 = V_34 ;
F_257 ( V_5 , & V_5 -> V_3 , 0 ) ;
#ifdef F_270
V_5 -> V_594 . V_595 = 1 ;
V_5 -> V_594 . V_596 = 1 ;
#endif
F_271 ( V_5 ) ;
return V_5 ;
}
static void F_272 ( struct V_21 * V_597 , void * V_598 )
{
struct V_502 * V_269 = F_273 ( V_597 ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_269 -> V_599 ; V_25 ++ ) {
struct V_4 * V_5 = V_269 -> V_600 [ V_25 ] ;
if ( ! V_5 )
continue;
if ( V_5 -> V_289 )
F_274 ( V_5 -> V_289 ) ;
F_275 ( V_5 -> V_11 ) ;
F_275 ( V_5 -> V_12 ) ;
F_275 ( V_5 ) ;
V_269 -> V_600 [ V_25 ] = NULL ;
}
F_276 ( V_597 , NULL ) ;
}
struct V_502 * F_277 ( struct V_21 * V_15 , int V_601 )
{
struct V_502 * V_269 ;
T_5 V_602 ;
int V_25 ;
F_30 ( L_127 ) ;
if ( ! F_278 ( V_15 , NULL , V_572 ) )
return NULL ;
V_602 = sizeof( struct V_502 ) + ( V_601 + 1 ) * sizeof( void * ) ;
V_269 = F_279 ( F_272 , V_602 , V_572 ) ;
if ( ! V_269 )
goto V_260;
F_280 ( V_15 , V_269 ) ;
F_276 ( V_15 , V_269 ) ;
F_281 ( & V_269 -> V_209 ) ;
F_263 ( & V_269 -> V_603 ) ;
V_269 -> V_15 = V_15 ;
V_269 -> V_599 = V_601 ;
for ( V_25 = 0 ; V_25 < V_601 ; V_25 ++ ) {
struct V_4 * V_5 ;
V_5 = F_260 ( V_269 ) ;
if ( ! V_5 )
goto V_260;
V_5 -> V_604 = V_25 ;
V_269 -> V_600 [ V_25 ] = V_5 ;
}
F_282 ( V_15 , NULL ) ;
return V_269 ;
V_260:
F_283 ( V_15 , NULL ) ;
return NULL ;
}
struct V_502 * F_284 ( struct V_21 * V_15 ,
const struct V_605 * const * V_606 ,
int V_599 )
{
const struct V_605 * V_607 ;
struct V_502 * V_269 ;
int V_25 , V_319 ;
V_269 = F_277 ( V_15 , V_599 ) ;
if ( ! V_269 )
return NULL ;
for ( V_25 = 0 , V_319 = 0 , V_607 = NULL ; V_25 < V_269 -> V_599 ; V_25 ++ ) {
struct V_4 * V_5 = V_269 -> V_600 [ V_25 ] ;
if ( V_606 [ V_319 ] )
V_607 = V_606 [ V_319 ++ ] ;
V_5 -> V_44 = V_607 -> V_44 ;
V_5 -> V_45 = V_607 -> V_45 ;
V_5 -> V_46 = V_607 -> V_46 ;
V_5 -> V_42 |= V_607 -> V_42 ;
V_5 -> V_3 . V_42 |= V_607 -> V_608 ;
V_5 -> V_213 = V_607 -> V_609 ;
if ( ! V_269 -> V_213 && ( V_607 -> V_609 != & V_610 ) )
V_269 -> V_213 = V_607 -> V_609 ;
}
return V_269 ;
}
int F_285 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
F_87 ( V_5 -> V_12 ) ;
F_87 ( V_5 -> V_42 & V_611 ) ;
V_3 = F_261 ( sizeof( * V_3 ) , V_572 ) ;
if ( ! V_3 )
return - V_612 ;
F_257 ( V_5 , V_3 , 1 ) ;
V_5 -> V_12 = V_3 ;
return 0 ;
}
static void F_286 ( struct V_21 * V_597 , void * V_598 )
{
struct V_502 * V_269 = F_273 ( V_597 ) ;
int V_25 ;
F_87 ( ! ( V_269 -> V_42 & V_613 ) ) ;
for ( V_25 = 0 ; V_25 < V_269 -> V_599 ; V_25 ++ ) {
struct V_4 * V_5 = V_269 -> V_600 [ V_25 ] ;
if ( V_5 -> V_213 -> V_614 )
V_5 -> V_213 -> V_614 ( V_5 ) ;
}
if ( V_269 -> V_213 -> V_615 )
V_269 -> V_213 -> V_615 ( V_269 ) ;
}
static void F_287 ( struct V_616 * V_213 )
{
static F_288 ( V_209 ) ;
const struct V_616 * V_463 ;
void * * V_617 = ( void * * ) V_213 ;
void * * V_618 = ( void * * ) & V_213 -> V_619 ;
void * * V_620 ;
if ( ! V_213 || ! V_213 -> V_619 )
return;
F_289 ( & V_209 ) ;
for ( V_463 = V_213 -> V_619 ; V_463 ; V_463 = V_463 -> V_619 ) {
void * * V_621 = ( void * * ) V_463 ;
for ( V_620 = V_617 ; V_620 < V_618 ; V_620 ++ , V_621 ++ )
if ( ! * V_620 )
* V_620 = * V_621 ;
}
for ( V_620 = V_617 ; V_620 < V_618 ; V_620 ++ )
if ( F_290 ( * V_620 ) )
* V_620 = NULL ;
V_213 -> V_619 = NULL ;
F_291 ( & V_209 ) ;
}
int F_292 ( struct V_502 * V_269 )
{
int V_622 = 0 ;
void * V_623 = NULL ;
int V_25 , V_180 ;
if ( V_269 -> V_42 & V_613 )
return 0 ;
F_287 ( V_269 -> V_213 ) ;
for ( V_25 = 0 ; V_25 < V_269 -> V_599 ; V_25 ++ ) {
struct V_4 * V_5 = V_269 -> V_600 [ V_25 ] ;
F_287 ( V_5 -> V_213 ) ;
if ( ! V_269 -> V_213 && ! F_293 ( V_5 ) )
V_269 -> V_213 = V_5 -> V_213 ;
if ( V_5 -> V_213 -> V_614 )
V_622 = 1 ;
}
if ( V_269 -> V_213 -> V_615 )
V_622 = 1 ;
if ( V_622 ) {
V_623 = F_279 ( F_286 , 0 , V_572 ) ;
if ( ! V_623 )
return - V_612 ;
}
for ( V_25 = 0 ; V_25 < V_269 -> V_599 ; V_25 ++ ) {
struct V_4 * V_5 = V_269 -> V_600 [ V_25 ] ;
if ( V_5 -> V_213 -> V_624 ) {
V_180 = V_5 -> V_213 -> V_624 ( V_5 ) ;
if ( V_180 ) {
if ( V_180 != - V_259 )
F_294 ( V_269 -> V_15 ,
L_153 ,
V_25 , V_180 ) ;
goto V_260;
}
}
F_295 ( V_5 ) ;
}
if ( V_623 )
F_280 ( V_269 -> V_15 , V_623 ) ;
V_269 -> V_42 |= V_613 ;
return 0 ;
V_260:
while ( -- V_25 >= 0 ) {
struct V_4 * V_5 = V_269 -> V_600 [ V_25 ] ;
if ( V_5 -> V_213 -> V_614 )
V_5 -> V_213 -> V_614 ( V_5 ) ;
}
F_296 ( V_623 ) ;
return V_180 ;
}
void F_297 ( struct V_502 * V_269 , struct V_21 * V_15 ,
struct V_616 * V_213 )
{
F_281 ( & V_269 -> V_209 ) ;
F_263 ( & V_269 -> V_603 ) ;
V_269 -> V_15 = V_15 ;
V_269 -> V_213 = V_213 ;
}
void F_298 ( struct V_4 * V_5 )
{
struct V_521 * V_522 = & V_5 -> V_3 . V_523 ;
unsigned long V_42 ;
F_67 ( V_5 -> V_209 , V_42 ) ;
V_522 -> V_625 |= V_626 ;
V_522 -> V_477 |= V_537 ;
V_522 -> V_42 |= V_553 | V_552 ;
V_5 -> V_210 &= ~ V_573 ;
V_5 -> V_210 |= V_627 ;
F_220 ( V_5 ) ;
F_68 ( V_5 -> V_209 , V_42 ) ;
}
int F_299 ( struct V_4 * V_5 )
{
int V_180 = 0 ;
if ( V_5 -> V_213 -> V_214 ) {
F_298 ( V_5 ) ;
F_233 ( V_5 ) ;
} else {
F_30 ( L_154 , V_5 -> V_31 ) ;
V_180 = F_138 ( V_5 ) ;
F_30 ( L_155 , V_5 -> V_31 ) ;
}
return V_180 ;
}
static void F_300 ( void * V_593 , T_7 V_628 )
{
struct V_4 * V_5 = V_593 ;
if ( ! ( V_5 -> V_269 -> V_42 & V_450 ) && V_5 -> V_604 != 0 )
F_301 ( V_628 ) ;
( void ) F_299 ( V_5 ) ;
F_301 ( V_628 ) ;
F_302 ( V_5 , 1 ) ;
}
int F_303 ( struct V_502 * V_269 , struct V_629 * V_630 )
{
int V_25 , V_180 ;
if ( ! ( V_269 -> V_42 & V_613 ) ) {
F_294 ( V_269 -> V_15 , L_156 ) ;
F_87 ( 1 ) ;
return - V_118 ;
}
for ( V_25 = V_269 -> V_599 ; V_269 -> V_600 [ V_25 ] ; V_25 ++ )
F_275 ( V_269 -> V_600 [ V_25 ] ) ;
for ( V_25 = 0 ; V_25 < V_269 -> V_599 ; V_25 ++ )
V_269 -> V_600 [ V_25 ] -> V_31 = F_304 ( & V_631 ) ;
for ( V_25 = 0 ; V_25 < V_269 -> V_599 ; V_25 ++ ) {
V_180 = F_305 ( V_269 -> V_15 , V_269 -> V_600 [ V_25 ] ) ;
if ( V_180 ) {
goto V_632;
}
}
V_180 = F_306 ( V_269 , V_630 ) ;
if ( V_180 )
goto V_632;
for ( V_25 = 0 ; V_25 < V_269 -> V_599 ; V_25 ++ ) {
struct V_4 * V_5 = V_269 -> V_600 [ V_25 ] ;
unsigned long V_47 ;
if ( V_5 -> V_33 == V_34 && ( V_5 -> V_42 & V_430 ) )
V_5 -> V_33 = V_281 ;
F_259 ( & V_5 -> V_3 ) ;
if ( V_5 -> V_12 )
F_259 ( V_5 -> V_12 ) ;
V_47 = F_31 ( V_5 -> V_44 , V_5 -> V_45 ,
V_5 -> V_46 ) ;
if ( ! F_293 ( V_5 ) ) {
V_605 ( V_5 , L_157 ,
( V_5 -> V_42 & V_430 ) ? 'S' : 'P' ,
F_36 ( V_47 ) ,
V_5 -> V_3 . V_523 . V_282 ) ;
F_307 ( & V_5 -> V_3 . V_523 ) ;
} else
V_605 ( V_5 , L_158 ) ;
}
for ( V_25 = 0 ; V_25 < V_269 -> V_599 ; V_25 ++ ) {
struct V_4 * V_5 = V_269 -> V_600 [ V_25 ] ;
F_308 ( F_300 , V_5 ) ;
}
return 0 ;
V_632:
while ( -- V_25 >= 0 ) {
F_309 ( V_269 -> V_600 [ V_25 ] ) ;
}
return V_180 ;
}
int F_310 ( struct V_502 * V_269 , int V_633 ,
T_8 V_634 , unsigned long V_635 ,
struct V_629 * V_630 )
{
int V_25 , V_180 ;
V_180 = F_292 ( V_269 ) ;
if ( V_180 )
return V_180 ;
if ( ! V_633 ) {
F_87 ( V_634 ) ;
return F_303 ( V_269 , V_630 ) ;
}
V_180 = F_311 ( V_269 -> V_15 , V_633 , V_634 , V_635 ,
F_312 ( V_269 -> V_15 ) , V_269 ) ;
if ( V_180 )
return V_180 ;
for ( V_25 = 0 ; V_25 < V_269 -> V_599 ; V_25 ++ )
F_313 ( V_269 -> V_600 [ V_25 ] , L_159 , V_633 ) ;
V_180 = F_303 ( V_269 , V_630 ) ;
if ( V_180 )
F_314 ( V_269 -> V_15 , V_633 , V_269 ) ;
return V_180 ;
}
static void F_315 ( struct V_4 * V_5 )
{
unsigned long V_42 ;
if ( ! V_5 -> V_213 -> V_214 )
goto V_636;
F_67 ( V_5 -> V_209 , V_42 ) ;
V_5 -> V_210 |= V_637 ;
F_220 ( V_5 ) ;
F_68 ( V_5 -> V_209 , V_42 ) ;
F_233 ( V_5 ) ;
F_87 ( ! ( V_5 -> V_210 & V_638 ) ) ;
F_316 ( & V_5 -> V_583 ) ;
V_636:
if ( V_5 -> V_11 ) {
int V_25 ;
for ( V_25 = 0 ; V_25 < V_639 ; V_25 ++ )
F_317 ( & V_5 -> V_11 [ V_25 ] ) ;
}
F_309 ( V_5 ) ;
F_318 ( V_5 -> V_289 ) ;
}
void F_319 ( struct V_502 * V_269 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_269 -> V_599 ; V_25 ++ )
F_315 ( V_269 -> V_600 [ V_25 ] ) ;
F_320 ( V_269 ) ;
}
void F_321 ( struct V_640 * V_641 )
{
struct V_502 * V_269 = F_322 ( V_641 ) ;
F_319 ( V_269 ) ;
}
int F_323 ( struct V_640 * V_641 , const struct V_642 * V_131 )
{
unsigned long V_368 = 0 ;
switch ( V_131 -> V_643 ) {
case 1 : {
T_2 V_644 = 0 ;
F_324 ( V_641 , V_131 -> V_542 , & V_644 ) ;
V_368 = V_644 ;
break;
}
case 2 : {
T_4 V_645 = 0 ;
F_325 ( V_641 , V_131 -> V_542 , & V_645 ) ;
V_368 = V_645 ;
break;
}
case 4 : {
T_1 V_646 = 0 ;
F_326 ( V_641 , V_131 -> V_542 , & V_646 ) ;
V_368 = V_646 ;
break;
}
default:
return - V_118 ;
}
V_368 &= V_131 -> V_372 ;
return ( V_368 == V_131 -> V_543 ) ? 1 : 0 ;
}
void F_327 ( struct V_640 * V_641 , T_6 V_546 )
{
F_328 ( V_641 ) ;
F_329 ( V_641 ) ;
if ( V_546 . V_647 & V_648 )
F_330 ( V_641 , V_649 ) ;
}
int F_331 ( struct V_640 * V_641 )
{
int V_180 ;
F_330 ( V_641 , V_650 ) ;
F_332 ( V_641 ) ;
V_180 = F_333 ( V_641 ) ;
if ( V_180 ) {
F_294 ( & V_641 -> V_15 ,
L_160 , V_180 ) ;
return V_180 ;
}
F_334 ( V_641 ) ;
return 0 ;
}
int F_335 ( struct V_640 * V_641 , T_6 V_546 )
{
struct V_502 * V_269 = F_322 ( V_641 ) ;
int V_180 = 0 ;
V_180 = F_254 ( V_269 , V_546 ) ;
if ( V_180 )
return V_180 ;
F_327 ( V_641 , V_546 ) ;
return 0 ;
}
int F_336 ( struct V_640 * V_641 )
{
struct V_502 * V_269 = F_322 ( V_641 ) ;
int V_180 ;
V_180 = F_331 ( V_641 ) ;
if ( V_180 == 0 )
F_255 ( V_269 ) ;
return V_180 ;
}
int F_337 ( struct V_651 * V_641 )
{
struct V_502 * V_269 = F_338 ( V_641 ) ;
F_319 ( V_269 ) ;
return 0 ;
}
static int T_9 F_339 ( char * * V_463 ,
struct V_27 * V_652 ,
const char * * V_251 )
{
static struct V_653 V_654 [] V_655 = {
{ L_161 , . V_33 = V_351 } ,
{ L_162 , . V_33 = V_352 } ,
{ L_163 , . V_33 = V_501 } ,
{ L_164 , . V_33 = V_353 } ,
{ L_165 , . V_33 = V_354 } ,
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
{ L_206 , . V_41 = V_656 } ,
{ L_207 , . V_41 = V_657 } ,
{ L_208 , . V_41 = V_656 | V_657 } ,
{ L_209 , . V_41 = V_658 } ,
} ;
char * V_446 = * V_463 , * V_147 = * V_463 ;
char * V_142 , * V_543 , * V_659 ;
const struct V_653 * V_660 = NULL ;
int V_661 = 0 , V_25 ;
while ( * V_147 != '\0' && * V_147 != ',' )
V_147 ++ ;
if ( * V_147 == '\0' )
* V_463 = V_147 ;
else
* V_463 = V_147 + 1 ;
* V_147 = '\0' ;
V_147 = strchr ( V_446 , ':' ) ;
if ( ! V_147 ) {
V_543 = F_340 ( V_446 ) ;
goto V_662;
}
* V_147 = '\0' ;
V_142 = F_340 ( V_446 ) ;
V_543 = F_340 ( V_147 + 1 ) ;
V_147 = strchr ( V_142 , '.' ) ;
if ( V_147 ) {
* V_147 ++ = '\0' ;
V_652 -> V_21 = F_341 ( V_147 , & V_659 , 10 ) ;
if ( V_147 == V_659 || * V_659 != '\0' ) {
* V_251 = L_210 ;
return - V_118 ;
}
}
V_652 -> V_30 = F_341 ( V_142 , & V_659 , 10 ) ;
if ( V_147 == V_659 || * V_659 != '\0' ) {
* V_251 = L_211 ;
return - V_118 ;
}
V_662:
for ( V_25 = 0 ; V_25 < F_37 ( V_654 ) ; V_25 ++ ) {
const struct V_653 * V_663 = & V_654 [ V_25 ] ;
if ( strncasecmp ( V_543 , V_663 -> V_35 , strlen ( V_543 ) ) )
continue;
V_661 ++ ;
V_660 = V_663 ;
if ( strcasecmp ( V_543 , V_663 -> V_35 ) == 0 ) {
V_661 = 1 ;
break;
}
}
if ( ! V_661 ) {
* V_251 = L_212 ;
return - V_118 ;
}
if ( V_661 > 1 ) {
* V_251 = L_213 ;
return - V_118 ;
}
V_652 -> V_32 = * V_660 ;
return 0 ;
}
static void T_9 F_342 ( void )
{
int V_664 = 0 , V_665 = 1 ;
int V_666 = - 1 , V_667 = - 1 ;
char * V_147 , * V_463 , * V_23 ;
for ( V_147 = V_668 ; * V_147 ; V_147 ++ )
if ( * V_147 == ',' )
V_665 ++ ;
V_29 = F_261 ( sizeof( V_29 [ 0 ] ) * V_665 , V_572 ) ;
if ( ! V_29 ) {
F_343 ( V_669 L_214
L_215 ) ;
return;
}
for ( V_463 = V_668 ; * V_463 != '\0' ; V_463 = V_23 ) {
const char * V_251 = L_67 ;
struct V_27 V_670 = { . V_30 = - 1 , . V_21 = - 1 } ;
V_23 = V_463 ;
if ( F_339 ( & V_23 , & V_670 , & V_251 ) ) {
F_343 ( V_669 L_216
L_217 ,
V_463 , V_251 ) ;
continue;
}
if ( V_670 . V_30 == - 1 ) {
V_670 . V_30 = V_666 ;
V_670 . V_21 = V_667 ;
}
V_29 [ V_664 ++ ] = V_670 ;
V_666 = V_670 . V_30 ;
V_667 = V_670 . V_21 ;
}
V_26 = V_664 ;
}
static int T_9 F_344 ( void )
{
int V_180 ;
F_342 () ;
F_345 () ;
V_180 = F_346 () ;
if ( V_180 ) {
F_275 ( V_29 ) ;
return V_180 ;
}
F_347 () ;
V_671 = F_348 () ;
if ( ! V_671 ) {
F_349 () ;
V_180 = - V_612 ;
goto V_260;
}
F_343 ( V_267 L_218 V_672 L_219 ) ;
return 0 ;
V_260:
return V_180 ;
}
static void T_10 F_350 ( void )
{
F_351 ( V_671 ) ;
F_352 () ;
F_349 () ;
F_353 () ;
F_275 ( V_29 ) ;
}
int F_354 ( void )
{
return F_355 ( & V_673 ) ;
}
void F_173 ( struct V_4 * V_5 , unsigned int V_674 )
{
bool V_675 = V_5 && V_5 -> V_269 -> V_676 == V_677 ;
if ( V_675 )
F_77 ( V_5 ) ;
F_179 ( V_674 ) ;
if ( V_675 )
F_80 ( V_5 ) ;
}
T_1 F_356 ( struct V_4 * V_5 , void T_11 * V_542 , T_1 V_372 , T_1 V_543 ,
unsigned long V_459 , unsigned long V_202 )
{
unsigned long V_445 ;
T_1 V_368 ;
V_368 = F_357 ( V_542 ) ;
V_445 = F_168 ( V_447 , V_202 ) ;
while ( ( V_368 & V_372 ) == V_543 && F_172 ( V_447 , V_445 ) ) {
F_173 ( V_5 , V_459 ) ;
V_368 = F_357 ( V_542 ) ;
}
return V_368 ;
}
static unsigned int F_358 ( struct V_192 * V_193 )
{
return V_212 ;
}
static void F_359 ( struct V_4 * V_5 )
{
}
int F_360 ( const struct V_4 * V_5 , const char * V_678 ,
const char * V_679 , ... )
{
struct V_680 V_681 ;
T_12 args ;
int V_682 ;
va_start ( args , V_679 ) ;
V_681 . V_679 = V_679 ;
V_681 . V_683 = & args ;
V_682 = F_343 ( L_220 , V_678 , V_5 -> V_31 , & V_681 ) ;
va_end ( args ) ;
return V_682 ;
}
int F_361 ( const struct V_2 * V_3 , const char * V_678 ,
const char * V_679 , ... )
{
struct V_680 V_681 ;
T_12 args ;
int V_682 ;
va_start ( args , V_679 ) ;
V_681 . V_679 = V_679 ;
V_681 . V_683 = & args ;
if ( F_4 ( V_3 -> V_5 ) || V_3 -> V_5 -> V_12 )
V_682 = F_343 ( L_221 ,
V_678 , V_3 -> V_5 -> V_31 , V_3 -> V_38 , & V_681 ) ;
else
V_682 = F_343 ( L_220 ,
V_678 , V_3 -> V_5 -> V_31 , & V_681 ) ;
va_end ( args ) ;
return V_682 ;
}
int F_362 ( const struct V_14 * V_15 , const char * V_678 ,
const char * V_679 , ... )
{
struct V_680 V_681 ;
T_12 args ;
int V_682 ;
va_start ( args , V_679 ) ;
V_681 . V_679 = V_679 ;
V_681 . V_683 = & args ;
V_682 = F_343 ( L_221 ,
V_678 , V_15 -> V_3 -> V_5 -> V_31 , V_15 -> V_3 -> V_38 + V_15 -> V_24 ,
& V_681 ) ;
va_end ( args ) ;
return V_682 ;
}
void F_363 ( const struct V_21 * V_15 , const char * V_684 )
{
F_364 ( V_267 , V_15 , L_222 , V_684 ) ;
}
