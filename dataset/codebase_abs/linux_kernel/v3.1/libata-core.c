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
V_68 -> V_21 = 1 << 6 ;
if ( V_68 -> V_42 & V_88 )
V_68 -> V_21 |= 1 << 7 ;
} else if ( V_15 -> V_42 & V_115 ) {
V_68 -> V_42 |= V_99 ;
if ( F_29 ( V_98 , V_105 ) ) {
V_68 -> V_21 |= ( V_98 >> 24 ) & 0xf ;
} else if ( F_28 ( V_98 , V_105 ) ) {
if ( ! ( V_15 -> V_42 & V_116 ) )
return - V_111 ;
V_68 -> V_42 |= V_89 ;
V_68 -> V_81 = ( V_105 >> 8 ) & 0xff ;
V_68 -> V_78 = ( V_98 >> 40 ) & 0xff ;
V_68 -> V_77 = ( V_98 >> 32 ) & 0xff ;
V_68 -> V_76 = ( V_98 >> 24 ) & 0xff ;
} else
return - V_111 ;
if ( F_5 ( F_22 ( V_68 , V_15 ) < 0 ) )
return - V_117 ;
V_68 -> V_80 = V_105 & 0xff ;
V_68 -> V_75 = ( V_98 >> 16 ) & 0xff ;
V_68 -> V_74 = ( V_98 >> 8 ) & 0xff ;
V_68 -> V_73 = V_98 & 0xff ;
V_68 -> V_21 |= V_118 ;
} else {
T_1 V_102 , V_101 , V_100 , V_119 ;
if ( ! F_29 ( V_98 , V_105 ) )
return - V_111 ;
if ( F_5 ( F_22 ( V_68 , V_15 ) < 0 ) )
return - V_117 ;
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
V_68 . V_21 |= V_118 ;
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
V_68 . V_21 |= V_118 ;
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
V_180 = - V_117 ;
V_251 = L_68 ;
if ( V_181 == V_137 ) {
if ( ! F_99 ( V_142 ) && ! F_62 ( V_142 ) )
goto V_260;
} else {
if ( F_99 ( V_142 ) )
goto V_260;
}
if ( ! V_254 && ( V_142 [ 2 ] == 0x37c8 || V_142 [ 2 ] == 0x738c ) ) {
V_254 = 1 ;
V_157 = F_100 ( V_15 , V_269 , 0 ) ;
if ( V_157 && V_142 [ 2 ] != 0x738c ) {
V_180 = - V_165 ;
V_251 = L_69 ;
goto V_260;
}
if ( V_142 [ 2 ] == 0x37c8 )
goto V_256;
}
if ( ( V_42 & V_270 ) && V_181 == V_137 ) {
if ( F_101 ( V_142 ) < 4 || ! F_44 ( V_142 ) ) {
V_157 = F_102 ( V_15 , V_142 [ 3 ] , V_142 [ 6 ] ) ;
if ( V_157 ) {
V_180 = - V_165 ;
V_251 = L_70 ;
goto V_260;
}
V_42 &= ~ V_270 ;
goto V_256;
}
}
* V_250 = V_181 ;
return 0 ;
V_260:
if ( F_84 ( V_5 ) )
F_24 ( V_15 , L_71 ,
V_251 , V_157 ) ;
return V_180 ;
}
static int F_103 ( struct V_14 * V_15 )
{
struct V_2 * V_271 = F_9 ( V_15 ) ;
T_1 V_272 , V_273 ;
if ( ! F_104 ( V_271 ) )
return 0 ;
if ( V_15 -> V_48 & V_274 )
V_272 = 1 ;
else
return 0 ;
V_273 = ( 1 << V_272 ) - 1 ;
if ( V_271 -> V_275 <= V_273 )
return 0 ;
V_271 -> V_275 = V_273 ;
if ( V_271 -> V_276 > V_272 ) {
F_57 ( V_15 , L_72 ,
F_38 ( V_272 ) ) ;
return - V_277 ;
}
return 0 ;
}
static inline T_2 F_105 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
if ( F_106 ( V_15 ) & V_278 )
return 0 ;
return ( ( V_5 -> V_33 == V_279 ) && ( ! F_107 ( V_15 -> V_142 ) ) ) ;
}
static int F_108 ( struct V_14 * V_15 ,
char * V_280 , T_5 V_281 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
int V_282 = 0 , V_283 = F_109 ( V_15 -> V_142 ) ;
unsigned int V_157 ;
char * V_284 = L_67 ;
if ( ! F_110 ( V_15 -> V_142 ) ) {
V_280 [ 0 ] = '\0' ;
return 0 ;
}
if ( V_15 -> V_48 & V_285 ) {
snprintf ( V_280 , V_281 , L_73 ) ;
return 0 ;
}
if ( V_5 -> V_42 & V_286 ) {
V_282 = F_111 ( V_5 -> V_287 -> V_288 , V_289 - 1 ) ;
V_15 -> V_42 |= V_290 ;
}
if ( ! ( V_15 -> V_48 & V_291 ) &&
( V_5 -> V_42 & V_292 ) &&
F_112 ( V_15 -> V_142 ) ) {
V_157 = F_100 ( V_15 , V_293 ,
V_294 ) ;
if ( V_157 ) {
F_59 ( V_15 ,
L_74 ,
V_157 ) ;
if ( V_157 != V_162 ) {
V_15 -> V_48 |= V_291 ;
return - V_165 ;
}
} else
V_284 = L_75 ;
}
if ( V_282 >= V_283 )
snprintf ( V_280 , V_281 , L_76 , V_283 , V_284 ) ;
else
snprintf ( V_280 , V_281 , L_77 , V_282 ,
V_283 , V_284 ) ;
return 0 ;
}
int F_113 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_171 * V_172 = & V_15 -> V_3 -> V_173 ;
int V_174 = V_172 -> V_25 . V_42 & V_175 ;
const T_4 * V_142 = V_15 -> V_142 ;
unsigned long V_47 ;
char V_295 [ 7 ] ;
char V_296 [ V_297 + 1 ] ;
char V_298 [ V_299 + 1 ] ;
int V_180 ;
if ( ! F_8 ( V_15 ) && F_114 ( V_5 ) ) {
F_57 ( V_15 , L_78 , V_255 ) ;
return 0 ;
}
if ( F_115 ( V_5 ) )
F_96 ( V_15 , L_59 , V_255 ) ;
V_15 -> V_48 |= F_106 ( V_15 ) ;
F_18 ( V_15 ) ;
if ( V_15 -> V_48 & V_300 ) {
F_57 ( V_15 , L_79 ) ;
F_116 ( V_15 ) ;
return 0 ;
}
if ( ( ! V_301 || ( V_5 -> V_42 & V_302 ) ) &&
V_15 -> V_181 == V_138 ) {
F_24 ( V_15 , L_80 ,
V_301 ? L_81
: L_82 ) ;
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
L_83
L_84 ,
V_255 ,
V_142 [ 49 ] , V_142 [ 82 ] , V_142 [ 83 ] , V_142 [ 84 ] ,
V_142 [ 85 ] , V_142 [ 86 ] , V_142 [ 87 ] , V_142 [ 88 ] ) ;
V_15 -> V_42 &= ~ V_303 ;
V_15 -> V_156 = 0 ;
V_15 -> V_304 = 0 ;
V_15 -> V_305 = 0 ;
V_15 -> V_306 = 0 ;
V_15 -> V_103 = 0 ;
V_15 -> V_104 = 0 ;
V_15 -> V_94 = 0 ;
V_47 = F_61 ( V_142 ) ;
if ( F_115 ( V_5 ) )
F_60 ( V_142 ) ;
F_41 ( V_15 -> V_142 , V_296 , V_307 ,
sizeof( V_296 ) ) ;
F_41 ( V_15 -> V_142 , V_298 , V_308 ,
sizeof( V_298 ) ) ;
if ( V_15 -> V_181 == V_137 ) {
if ( F_62 ( V_142 ) ) {
if ( V_142 [ V_309 ] & 1 )
F_24 ( V_15 ,
L_85 ) ;
snprintf ( V_295 , 7 , L_86 ) ;
} else {
snprintf ( V_295 , 7 , L_87 , F_101 ( V_142 ) ) ;
if ( F_118 ( V_142 ) )
F_24 ( V_15 ,
L_85 ) ;
}
V_15 -> V_305 = F_43 ( V_142 ) ;
if ( ( V_15 -> V_142 [ 47 ] >> 8 ) == 0x80 && ( V_15 -> V_142 [ 59 ] & 0x100 ) ) {
unsigned int V_310 = V_15 -> V_142 [ 47 ] & 0xff ;
unsigned int V_311 = V_15 -> V_142 [ 59 ] & 0xff ;
if ( F_119 ( V_310 ) && F_119 ( V_311 ) )
if ( V_311 <= V_310 )
V_15 -> V_94 = V_311 ;
}
if ( F_44 ( V_142 ) ) {
const char * V_312 ;
char V_313 [ 24 ] ;
V_312 = L_88 ;
V_15 -> V_42 |= V_115 ;
if ( F_45 ( V_142 ) ) {
V_15 -> V_42 |= V_116 ;
V_312 = L_89 ;
if ( V_15 -> V_305 >= ( 1UL << 28 ) &&
F_120 ( V_142 ) )
V_15 -> V_42 |= V_314 ;
}
V_180 = F_108 ( V_15 , V_313 , sizeof( V_313 ) ) ;
if ( V_180 )
return V_180 ;
if ( F_121 ( V_5 ) && V_174 ) {
F_57 ( V_15 , L_90 ,
V_295 , V_298 , V_296 ,
F_36 ( V_47 ) ) ;
F_57 ( V_15 ,
L_91 ,
( unsigned long long ) V_15 -> V_305 ,
V_15 -> V_94 , V_312 , V_313 ) ;
}
} else {
V_15 -> V_306 = V_142 [ 1 ] ;
V_15 -> V_103 = V_142 [ 3 ] ;
V_15 -> V_104 = V_142 [ 6 ] ;
if ( F_48 ( V_142 ) ) {
V_15 -> V_306 = V_142 [ 54 ] ;
V_15 -> V_103 = V_142 [ 55 ] ;
V_15 -> V_104 = V_142 [ 56 ] ;
}
if ( F_121 ( V_5 ) && V_174 ) {
F_57 ( V_15 , L_90 ,
V_295 , V_298 , V_296 ,
F_36 ( V_47 ) ) ;
F_57 ( V_15 ,
L_92 ,
( unsigned long long ) V_15 -> V_305 ,
V_15 -> V_94 , V_15 -> V_306 ,
V_15 -> V_103 , V_15 -> V_104 ) ;
}
}
V_15 -> V_304 = 16 ;
}
else if ( V_15 -> V_181 == V_138 ) {
const char * V_315 = L_67 ;
const char * V_316 = L_67 ;
const char * V_317 = L_67 ;
T_1 V_318 ;
V_180 = F_122 ( V_142 ) ;
if ( ( V_180 < 12 ) || ( V_180 > V_222 ) ) {
if ( F_84 ( V_5 ) )
F_24 ( V_15 , L_93 ) ;
V_180 = - V_117 ;
goto V_319;
}
V_15 -> V_304 = ( unsigned int ) V_180 ;
if ( V_320 &&
( V_5 -> V_42 & V_321 ) && F_123 ( V_142 ) &&
( ! F_4 ( V_5 ) ||
F_124 ( & V_5 -> V_3 , V_322 , & V_318 ) == 0 ) ) {
unsigned int V_157 ;
V_157 = F_100 ( V_15 ,
V_293 , V_323 ) ;
if ( V_157 )
F_59 ( V_15 ,
L_94 ,
V_157 ) ;
else {
V_15 -> V_42 |= V_324 ;
V_316 = L_95 ;
}
}
if ( F_125 ( V_15 -> V_142 ) ) {
V_15 -> V_42 |= V_325 ;
V_315 = L_96 ;
}
if ( V_326 || F_126 ( V_15 -> V_142 ) ) {
V_15 -> V_42 |= V_327 ;
V_317 = L_97 ;
}
if ( F_121 ( V_5 ) && V_174 )
F_57 ( V_15 ,
L_98 ,
V_298 , V_296 ,
F_36 ( V_47 ) ,
V_315 , V_316 ,
V_317 ) ;
}
V_15 -> V_156 = V_328 ;
if ( V_15 -> V_42 & V_116 )
V_15 -> V_156 = V_329 ;
if ( F_105 ( V_15 ) ) {
if ( F_121 ( V_5 ) && V_174 )
F_57 ( V_15 , L_99 ) ;
V_15 -> V_46 &= V_330 ;
V_15 -> V_156 = V_328 ;
}
if ( ( V_15 -> V_181 == V_138 ) &&
( F_127 ( V_142 ) == V_331 ) ) {
V_15 -> V_156 = V_332 ;
V_15 -> V_48 |= V_333 ;
}
if ( V_15 -> V_48 & V_334 )
V_15 -> V_156 = F_128 (unsigned int, ATA_MAX_SECTORS_128,
dev->max_sectors) ;
if ( V_5 -> V_213 -> V_335 )
V_5 -> V_213 -> V_335 ( V_15 ) ;
if ( V_15 -> V_48 & V_336 ) {
if ( V_174 ) {
F_24 ( V_15 ,
L_100 ) ;
F_24 ( V_15 ,
L_101 ) ;
}
}
if ( ( V_15 -> V_48 & V_337 ) && V_174 ) {
F_24 ( V_15 , L_102 ) ;
F_24 ( V_15 , L_103 ) ;
}
return 0 ;
V_319:
if ( F_115 ( V_5 ) )
F_96 ( V_15 , L_104 , V_255 ) ;
return V_180 ;
}
int F_129 ( struct V_4 * V_5 )
{
return V_338 ;
}
int F_130 ( struct V_4 * V_5 )
{
return V_339 ;
}
int F_131 ( struct V_4 * V_5 )
{
return V_340 ;
}
int F_132 ( struct V_4 * V_5 )
{
return V_341 ;
}
int F_133 ( struct V_4 * V_5 )
{
return V_279 ;
}
int F_134 ( struct V_4 * V_5 )
{
unsigned int V_342 [ V_343 ] ;
int V_344 [ V_343 ] ;
int V_180 ;
struct V_14 * V_15 ;
F_135 (dev, &ap->link, ALL)
V_344 [ V_15 -> V_24 ] = V_345 ;
V_256:
F_135 (dev, &ap->link, ALL) {
V_15 -> V_243 = V_346 ;
if ( V_5 -> V_213 -> V_347 )
V_5 -> V_213 -> V_347 ( V_5 , V_15 ) ;
}
V_5 -> V_213 -> V_348 ( V_5 ) ;
F_135 (dev, &ap->link, ALL) {
if ( V_15 -> V_181 != V_141 )
V_342 [ V_15 -> V_24 ] = V_15 -> V_181 ;
else
V_342 [ V_15 -> V_24 ] = V_349 ;
V_15 -> V_181 = V_141 ;
}
F_135 (dev, &ap->link, ALL_REVERSE) {
if ( V_344 [ V_15 -> V_24 ] )
V_15 -> V_181 = V_342 [ V_15 -> V_24 ] ;
if ( ! F_8 ( V_15 ) )
continue;
V_180 = F_94 ( V_15 , & V_15 -> V_181 , V_270 ,
V_15 -> V_142 ) ;
if ( V_180 )
goto V_350;
}
if ( V_5 -> V_213 -> V_351 )
V_5 -> V_33 = V_5 -> V_213 -> V_351 ( V_5 ) ;
F_135 (dev, &ap->link, ENABLED)
if ( F_107 ( V_15 -> V_142 ) )
V_5 -> V_33 = V_279 ;
F_135 (dev, &ap->link, ENABLED) {
V_5 -> V_3 . V_173 . V_25 . V_42 |= V_175 ;
V_180 = F_113 ( V_15 ) ;
V_5 -> V_3 . V_173 . V_25 . V_42 &= ~ V_175 ;
if ( V_180 )
goto V_350;
}
V_180 = F_136 ( & V_5 -> V_3 , & V_15 ) ;
if ( V_180 )
goto V_350;
F_135 (dev, &ap->link, ENABLED)
return 0 ;
return - V_259 ;
V_350:
V_344 [ V_15 -> V_24 ] -- ;
switch ( V_180 ) {
case - V_117 :
V_344 [ V_15 -> V_24 ] = 0 ;
break;
case - V_259 :
V_344 [ V_15 -> V_24 ] = F_111 ( V_344 [ V_15 -> V_24 ] , 1 ) ;
case - V_165 :
if ( V_344 [ V_15 -> V_24 ] == 1 ) {
F_137 ( & V_5 -> V_3 , 0 ) ;
F_138 ( V_15 , V_352 ) ;
}
}
if ( ! V_344 [ V_15 -> V_24 ] )
F_116 ( V_15 ) ;
goto V_256;
}
static void F_139 ( struct V_2 * V_3 )
{
T_1 V_1 , V_353 , V_354 ;
if ( F_124 ( V_3 , V_355 , & V_1 ) )
return;
F_124 ( V_3 , V_356 , & V_353 ) ;
if ( F_140 ( V_3 ) ) {
V_354 = ( V_1 >> 4 ) & 0xf ;
F_141 ( V_3 , L_105 ,
F_38 ( V_354 ) , V_1 , V_353 ) ;
} else {
F_141 ( V_3 , L_106 ,
V_1 , V_353 ) ;
}
}
struct V_14 * F_142 ( struct V_14 * V_240 )
{
struct V_2 * V_3 = V_240 -> V_3 ;
struct V_14 * V_357 = & V_3 -> V_21 [ 1 - V_240 -> V_24 ] ;
if ( ! F_8 ( V_357 ) )
return NULL ;
return V_357 ;
}
int F_137 ( struct V_2 * V_3 , T_1 V_39 )
{
T_1 V_1 , V_135 , V_358 ;
int V_180 , V_359 ;
if ( ! F_104 ( V_3 ) )
return - V_360 ;
V_180 = F_124 ( V_3 , V_355 , & V_1 ) ;
if ( V_180 == 0 && F_1 ( V_1 ) )
V_135 = ( V_1 >> 4 ) & 0xf ;
else
V_135 = V_3 -> V_276 ;
V_358 = V_3 -> V_275 ;
if ( V_358 <= 1 )
return - V_117 ;
V_359 = F_33 ( V_358 ) - 1 ;
V_358 &= ~ ( 1 << V_359 ) ;
if ( V_135 > 1 )
V_358 &= ( 1 << ( V_135 - 1 ) ) - 1 ;
else
V_358 &= 1 ;
if ( ! V_358 )
return - V_117 ;
if ( V_39 ) {
if ( V_358 & ( ( 1 << V_39 ) - 1 ) )
V_358 &= ( 1 << V_39 ) - 1 ;
else {
V_359 = F_143 ( V_358 ) - 1 ;
V_358 = 1 << V_359 ;
}
}
V_3 -> V_275 = V_358 ;
F_144 ( V_3 , L_107 ,
F_38 ( F_33 ( V_358 ) ) ) ;
return 0 ;
}
static int F_145 ( struct V_2 * V_3 , T_1 * V_353 )
{
struct V_2 * V_361 = & V_3 -> V_5 -> V_3 ;
T_1 V_362 , V_272 , V_135 ;
V_362 = V_3 -> V_275 ;
if ( ! F_13 ( V_3 ) && V_361 -> V_276 )
V_362 &= ( 1 << V_361 -> V_276 ) - 1 ;
if ( V_362 == V_363 )
V_272 = 0 ;
else
V_272 = F_33 ( V_362 ) ;
V_135 = ( * V_353 >> 4 ) & 0xf ;
* V_353 = ( * V_353 & ~ 0xf0 ) | ( ( V_272 & 0xf ) << 4 ) ;
return V_135 != V_272 ;
}
static int F_146 ( struct V_2 * V_3 )
{
T_1 V_353 ;
if ( F_124 ( V_3 , V_356 , & V_353 ) )
return 1 ;
return F_145 ( V_3 , & V_353 ) ;
}
int F_147 ( struct V_2 * V_3 )
{
T_1 V_353 ;
int V_180 ;
if ( ( V_180 = F_124 ( V_3 , V_356 , & V_353 ) ) )
return V_180 ;
if ( ! F_145 ( V_3 , & V_353 ) )
return 0 ;
if ( ( V_180 = F_148 ( V_3 , V_356 , V_353 ) ) )
return V_180 ;
return 1 ;
}
static void F_149 ( const struct V_364 * V_365 , struct V_364 * V_366 , int V_367 , int V_368 )
{
V_366 -> V_369 = F_150 ( V_365 -> V_369 * 1000 , V_367 ) ;
V_366 -> V_370 = F_150 ( V_365 -> V_370 * 1000 , V_367 ) ;
V_366 -> V_371 = F_150 ( V_365 -> V_371 * 1000 , V_367 ) ;
V_366 -> V_372 = F_150 ( V_365 -> V_372 * 1000 , V_367 ) ;
V_366 -> V_373 = F_150 ( V_365 -> V_373 * 1000 , V_367 ) ;
V_366 -> V_374 = F_150 ( V_365 -> V_374 * 1000 , V_367 ) ;
V_366 -> V_375 = F_150 ( V_365 -> V_375 * 1000 , V_367 ) ;
V_366 -> V_376 = F_150 ( V_365 -> V_376 * 1000 , V_367 ) ;
V_366 -> V_377 = F_150 ( V_365 -> V_377 * 1000 , V_368 ) ;
}
void F_151 ( const struct V_364 * V_378 , const struct V_364 * V_379 ,
struct V_364 * V_380 , unsigned int V_381 )
{
if ( V_381 & V_382 ) V_380 -> V_369 = V_310 ( V_378 -> V_369 , V_379 -> V_369 ) ;
if ( V_381 & V_383 ) V_380 -> V_370 = V_310 ( V_378 -> V_370 , V_379 -> V_370 ) ;
if ( V_381 & V_384 ) V_380 -> V_371 = V_310 ( V_378 -> V_371 , V_379 -> V_371 ) ;
if ( V_381 & V_385 ) V_380 -> V_372 = V_310 ( V_378 -> V_372 , V_379 -> V_372 ) ;
if ( V_381 & V_386 ) V_380 -> V_373 = V_310 ( V_378 -> V_373 , V_379 -> V_373 ) ;
if ( V_381 & V_387 ) V_380 -> V_374 = V_310 ( V_378 -> V_374 , V_379 -> V_374 ) ;
if ( V_381 & V_388 ) V_380 -> V_375 = V_310 ( V_378 -> V_375 , V_379 -> V_375 ) ;
if ( V_381 & V_389 ) V_380 -> V_376 = V_310 ( V_378 -> V_376 , V_379 -> V_376 ) ;
if ( V_381 & V_390 ) V_380 -> V_377 = V_310 ( V_378 -> V_377 , V_379 -> V_377 ) ;
}
const struct V_364 * F_152 ( T_2 V_133 )
{
const struct V_364 * V_365 = V_364 ;
while ( V_133 > V_365 -> V_7 )
V_365 ++ ;
if ( V_133 == V_365 -> V_7 )
return V_365 ;
return NULL ;
}
int F_153 ( struct V_14 * V_240 , unsigned short V_391 ,
struct V_364 * V_365 , int V_367 , int V_368 )
{
const T_4 * V_142 = V_240 -> V_142 ;
const struct V_364 * V_143 ;
struct V_364 V_147 ;
if ( ! ( V_143 = F_152 ( V_391 ) ) )
return - V_117 ;
memcpy ( V_365 , V_143 , sizeof( * V_143 ) ) ;
if ( V_142 [ V_184 ] & 2 ) {
memset ( & V_147 , 0 , sizeof( V_147 ) ) ;
if ( V_391 >= V_346 && V_391 <= V_392 ) {
if ( V_391 <= V_246 )
V_147 . V_376 = V_147 . V_372 = V_142 [ V_247 ] ;
else if ( ( V_391 <= V_393 ) ||
( V_391 == V_244 && ! F_62 ( V_142 ) ) )
V_147 . V_376 = V_147 . V_372 = V_142 [ V_394 ] ;
} else if ( V_391 >= V_395 && V_391 <= V_396 )
V_147 . V_376 = V_142 [ V_397 ] ;
F_151 ( & V_147 , V_365 , V_365 , V_389 | V_385 ) ;
}
F_149 ( V_365 , V_365 , V_367 , V_368 ) ;
if ( V_391 > V_245 ) {
F_153 ( V_240 , V_240 -> V_243 , & V_147 , V_367 , V_368 ) ;
F_151 ( & V_147 , V_365 , V_365 , V_398 ) ;
}
if ( V_365 -> V_370 + V_365 -> V_371 < V_365 -> V_372 ) {
V_365 -> V_370 += ( V_365 -> V_372 - ( V_365 -> V_370 + V_365 -> V_371 ) ) / 2 ;
V_365 -> V_371 = V_365 -> V_372 - V_365 -> V_370 ;
}
if ( V_365 -> V_373 + V_365 -> V_374 < V_365 -> V_376 ) {
V_365 -> V_373 += ( V_365 -> V_376 - ( V_365 -> V_373 + V_365 -> V_374 ) ) / 2 ;
V_365 -> V_374 = V_365 -> V_376 - V_365 -> V_373 ;
}
if ( V_365 -> V_373 + V_365 -> V_374 > V_365 -> V_376 )
V_365 -> V_376 = V_365 -> V_373 + V_365 -> V_374 ;
return 0 ;
}
T_2 F_154 ( unsigned int V_399 , int V_376 )
{
T_2 V_400 = 0xff , V_401 = 0xff ;
const struct V_127 * V_128 ;
const struct V_364 * V_365 ;
for ( V_128 = V_129 ; V_128 -> V_130 >= 0 ; V_128 ++ )
if ( V_128 -> V_130 == V_399 )
V_400 = V_128 -> V_132 ;
for ( V_365 = F_152 ( V_400 ) ;
V_365 && F_35 ( V_365 -> V_7 ) == V_399 ; V_365 ++ ) {
unsigned short V_402 ;
switch ( V_399 ) {
case V_120 :
case V_122 :
V_402 = V_365 -> V_376 ;
break;
case V_124 :
V_402 = V_365 -> V_377 ;
break;
default:
return 0xff ;
}
if ( V_376 > V_402 )
break;
V_401 = V_365 -> V_7 ;
}
return V_401 ;
}
int F_138 ( struct V_14 * V_15 , unsigned int V_403 )
{
char V_238 [ 32 ] ;
unsigned long V_404 , V_47 ;
unsigned long V_44 , V_45 , V_46 ;
int V_405 , V_126 ;
V_405 = ! ! ( V_403 & V_406 ) ;
V_403 &= ~ V_406 ;
V_47 = V_404 = F_31 ( V_15 -> V_44 ,
V_15 -> V_45 ,
V_15 -> V_46 ) ;
F_16 ( V_47 , & V_44 , & V_45 , & V_46 ) ;
switch ( V_403 ) {
case V_352 :
V_126 = F_33 ( V_44 ) - 1 ;
V_44 &= ~ ( 1 << V_126 ) ;
break;
case V_407 :
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
case V_408 :
V_46 &= V_409 ;
break;
case V_410 :
V_44 &= 1 ;
case V_411 :
V_45 = 0 ;
V_46 = 0 ;
break;
default:
F_70 () ;
}
V_47 &= F_31 ( V_44 , V_45 , V_46 ) ;
if ( ! ( V_47 & V_121 ) || V_47 == V_404 )
return - V_264 ;
if ( ! V_405 ) {
if ( V_47 & ( V_123 | V_125 ) )
snprintf ( V_238 , sizeof( V_238 ) , L_108 ,
F_36 ( V_47 ) ,
F_36 ( V_47 & V_121 ) ) ;
else
snprintf ( V_238 , sizeof( V_238 ) , L_109 ,
F_36 ( V_47 ) ) ;
F_24 ( V_15 , L_110 , V_238 ) ;
}
F_16 ( V_47 , & V_15 -> V_44 , & V_15 -> V_45 ,
& V_15 -> V_46 ) ;
return 0 ;
}
static int F_155 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_171 * V_172 = & V_15 -> V_3 -> V_173 ;
const bool V_412 = V_15 -> V_48 & V_413 ;
const char * V_414 = L_67 ;
int V_415 = 0 ;
unsigned int V_157 = 0 ;
int V_180 ;
V_15 -> V_42 &= ~ V_91 ;
if ( V_15 -> V_399 == V_120 )
V_15 -> V_42 |= V_91 ;
if ( V_412 && V_5 -> V_42 & V_416 && F_107 ( V_15 -> V_142 ) )
V_414 = L_111 ;
else {
if ( V_412 )
F_24 ( V_15 ,
L_112
L_113 ) ;
V_157 = F_156 ( V_15 ) ;
}
if ( V_157 & ~ V_162 )
goto V_350;
V_172 -> V_25 . V_42 |= V_417 ;
V_180 = F_157 ( V_15 , V_141 , 0 ) ;
V_172 -> V_25 . V_42 &= ~ V_417 ;
if ( V_180 )
return V_180 ;
if ( V_15 -> V_399 == V_120 ) {
if ( F_62 ( V_15 -> V_142 ) )
V_415 = 1 ;
if ( F_101 ( V_15 -> V_142 ) == 0 &&
V_15 -> V_243 <= V_246 )
V_415 = 1 ;
if ( ! F_91 ( V_15 -> V_142 ) && V_15 -> V_243 <= V_246 )
V_415 = 1 ;
}
if ( V_15 -> V_399 == V_122 &&
V_15 -> V_418 == V_395 &&
( V_15 -> V_142 [ 63 ] >> 8 ) & 1 )
V_415 = 1 ;
if ( V_15 -> V_133 == F_32 ( F_61 ( V_15 -> V_142 ) ) )
V_415 = 1 ;
if ( V_157 & V_162 ) {
if ( ! V_415 )
goto V_350;
else
V_414 = L_114 ;
}
F_30 ( L_115 ,
V_15 -> V_399 , ( int ) V_15 -> V_133 ) ;
F_57 ( V_15 , L_116 ,
F_36 ( F_34 ( V_15 -> V_133 ) ) ,
V_414 ) ;
return 0 ;
V_350:
F_59 ( V_15 , L_117 , V_157 ) ;
return - V_165 ;
}
int F_158 ( struct V_2 * V_3 , struct V_14 * * V_419 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_14 * V_15 ;
int V_180 = 0 , V_420 = 0 , V_421 = 0 ;
F_135 (dev, link, ENABLED) {
unsigned long V_44 , V_422 ;
unsigned int V_423 ;
V_423 = V_424 ;
if ( V_15 -> V_181 == V_138 )
V_423 = V_425 ;
else if ( F_62 ( V_15 -> V_142 ) )
V_423 = V_426 ;
F_159 ( V_15 ) ;
F_15 ( V_15 ) ;
V_44 = F_31 ( V_15 -> V_44 , 0 , 0 ) ;
V_422 = F_31 ( 0 , V_15 -> V_45 , V_15 -> V_46 ) ;
if ( V_427 & V_423 )
V_422 = F_31 ( 0 , V_15 -> V_45 , V_15 -> V_46 ) ;
else
V_422 = 0 ;
V_15 -> V_243 = F_32 ( V_44 ) ;
V_15 -> V_418 = F_32 ( V_422 ) ;
V_421 = 1 ;
if ( F_160 ( V_15 ) )
V_420 = 1 ;
}
if ( ! V_421 )
goto V_428;
F_135 (dev, link, ENABLED) {
if ( V_15 -> V_243 == 0xff ) {
F_24 ( V_15 , L_118 ) ;
V_180 = - V_117 ;
goto V_428;
}
V_15 -> V_133 = V_15 -> V_243 ;
V_15 -> V_399 = V_120 ;
if ( V_5 -> V_213 -> V_347 )
V_5 -> V_213 -> V_347 ( V_5 , V_15 ) ;
}
F_135 (dev, link, ENABLED) {
if ( ! F_160 ( V_15 ) )
continue;
V_15 -> V_133 = V_15 -> V_418 ;
V_15 -> V_399 = F_35 ( V_15 -> V_418 ) ;
if ( V_5 -> V_213 -> V_429 )
V_5 -> V_213 -> V_429 ( V_5 , V_15 ) ;
}
F_135 (dev, link, ENABLED) {
V_180 = F_155 ( V_15 ) ;
if ( V_180 )
goto V_428;
}
if ( V_420 && ( V_5 -> V_430 -> V_42 & V_431 ) )
V_5 -> V_430 -> V_432 = V_5 ;
V_428:
if ( V_180 )
* V_419 = V_15 ;
return V_180 ;
}
int F_161 ( struct V_2 * V_3 , unsigned long V_433 ,
int (* F_162)( struct V_2 * V_3 ) )
{
unsigned long V_434 = V_435 ;
unsigned long V_436 ;
int V_437 = 0 ;
if ( V_3 -> V_5 -> V_430 -> V_42 & V_438 )
V_436 = F_163 ( V_434 , V_439 ) ;
else
V_436 = F_163 ( V_434 , V_440 ) ;
F_87 ( V_3 == V_3 -> V_5 -> V_12 ) ;
if ( F_164 ( V_436 , V_433 ) )
V_436 = V_433 ;
while ( 1 ) {
unsigned long V_441 = V_435 ;
int V_442 , V_354 ;
V_442 = V_354 = F_162 ( V_3 ) ;
if ( V_442 > 0 )
return 0 ;
if ( V_442 == - V_259 ) {
if ( F_165 ( V_3 ) )
V_442 = 0 ;
else if ( ( V_3 -> V_5 -> V_42 & V_416 ) &&
! F_166 ( V_3 ) &&
F_167 ( V_441 , V_436 ) )
V_442 = 0 ;
}
if ( V_442 )
return V_442 ;
if ( F_164 ( V_441 , V_433 ) )
return - V_443 ;
if ( ! V_437 && F_164 ( V_441 , V_434 + 5 * V_444 ) &&
( V_433 - V_441 > 3 * V_444 ) ) {
F_144 ( V_3 ,
L_119
L_120 , V_354 ) ;
V_437 = 1 ;
}
F_168 ( V_3 -> V_5 , 50 ) ;
}
}
int F_169 ( struct V_2 * V_3 , unsigned long V_433 ,
int (* F_162)( struct V_2 * V_3 ) )
{
F_168 ( V_3 -> V_5 , V_445 ) ;
return F_161 ( V_3 , V_433 , F_162 ) ;
}
int F_170 ( struct V_2 * V_3 , const unsigned long * V_446 ,
unsigned long V_433 )
{
unsigned long V_447 = V_446 [ 0 ] ;
unsigned long V_448 = V_446 [ 1 ] ;
unsigned long V_449 , V_365 ;
T_1 V_450 , V_451 ;
int V_180 ;
V_365 = F_163 ( V_435 , V_446 [ 2 ] ) ;
if ( F_167 ( V_365 , V_433 ) )
V_433 = V_365 ;
if ( ( V_180 = F_124 ( V_3 , V_355 , & V_451 ) ) )
return V_180 ;
V_451 &= 0xf ;
V_450 = V_451 ;
V_449 = V_435 ;
while ( 1 ) {
F_168 ( V_3 -> V_5 , V_447 ) ;
if ( ( V_180 = F_124 ( V_3 , V_355 , & V_451 ) ) )
return V_180 ;
V_451 &= 0xf ;
if ( V_451 == V_450 ) {
if ( V_451 == 1 && F_167 ( V_435 , V_433 ) )
continue;
if ( F_164 ( V_435 ,
F_163 ( V_449 , V_448 ) ) )
return 0 ;
continue;
}
V_450 = V_451 ;
V_449 = V_435 ;
if ( F_164 ( V_435 , V_433 ) )
return - V_452 ;
}
}
int F_171 ( struct V_2 * V_3 , const unsigned long * V_446 ,
unsigned long V_433 )
{
int V_344 = V_453 ;
T_1 V_353 , V_454 ;
int V_180 ;
if ( ( V_180 = F_124 ( V_3 , V_356 , & V_353 ) ) )
return V_180 ;
do {
V_353 = ( V_353 & 0x0f0 ) | 0x300 ;
if ( ( V_180 = F_148 ( V_3 , V_356 , V_353 ) ) )
return V_180 ;
F_168 ( V_3 -> V_5 , 200 ) ;
if ( ( V_180 = F_124 ( V_3 , V_356 , & V_353 ) ) )
return V_180 ;
} while ( ( V_353 & 0xf0f ) != 0x300 && -- V_344 );
if ( ( V_353 & 0xf0f ) != 0x300 ) {
F_144 ( V_3 , L_121 ,
V_353 ) ;
return 0 ;
}
if ( V_344 < V_453 )
F_144 ( V_3 , L_122 ,
V_453 - V_344 ) ;
if ( ( V_180 = F_170 ( V_3 , V_446 , V_433 ) ) )
return V_180 ;
if ( ! ( V_180 = F_124 ( V_3 , V_455 , & V_454 ) ) )
V_180 = F_148 ( V_3 , V_455 , V_454 ) ;
return V_180 != - V_117 ? V_180 : 0 ;
}
int F_172 ( struct V_2 * V_3 , enum V_456 V_457 ,
bool V_458 )
{
struct V_171 * V_172 = & V_3 -> V_173 ;
bool V_459 = false ;
T_1 V_353 ;
int V_180 ;
V_180 = F_124 ( V_3 , V_356 , & V_353 ) ;
if ( V_180 )
return V_180 ;
switch ( V_457 ) {
case V_460 :
V_353 |= ( 0x3 << 8 ) ;
if ( V_458 ) {
V_353 |= ( 0x4 << 12 ) ;
V_459 = true ;
}
break;
case V_461 :
V_353 &= ~ ( 0x1 << 8 ) ;
V_353 |= ( 0x2 << 8 ) ;
break;
case V_462 :
if ( F_173 ( V_3 ) > 0 )
V_353 &= ~ ( 0x3 << 8 ) ;
else {
V_353 &= ~ 0xf ;
V_353 |= ( 0x1 << 2 ) ;
}
break;
default:
F_87 ( 1 ) ;
}
V_180 = F_148 ( V_3 , V_356 , V_353 ) ;
if ( V_180 )
return V_180 ;
if ( V_459 )
F_174 ( 10 ) ;
V_172 -> V_25 . V_454 &= ~ V_463 ;
return F_148 ( V_3 , V_455 , V_463 ) ;
}
int F_175 ( struct V_2 * V_3 , unsigned long V_433 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_171 * V_172 = & V_3 -> V_173 ;
const unsigned long * V_464 = F_176 ( V_172 ) ;
int V_180 ;
if ( V_172 -> V_25 . V_465 & V_466 )
return 0 ;
if ( V_5 -> V_42 & V_416 ) {
V_180 = F_171 ( V_3 , V_464 , V_433 ) ;
if ( V_180 && V_180 != - V_360 )
F_144 ( V_3 ,
L_123 ,
V_180 ) ;
}
if ( F_177 ( V_3 ) )
V_172 -> V_25 . V_465 &= ~ V_467 ;
return 0 ;
}
int F_178 ( struct V_2 * V_3 , const unsigned long * V_464 ,
unsigned long V_433 ,
bool * V_468 , int (* F_162)( struct V_2 * ) )
{
T_1 V_353 ;
int V_180 ;
F_30 ( L_124 ) ;
if ( V_468 )
* V_468 = false ;
if ( F_146 ( V_3 ) ) {
if ( ( V_180 = F_124 ( V_3 , V_356 , & V_353 ) ) )
goto V_428;
V_353 = ( V_353 & 0x0f0 ) | 0x304 ;
if ( ( V_180 = F_148 ( V_3 , V_356 , V_353 ) ) )
goto V_428;
F_147 ( V_3 ) ;
}
if ( ( V_180 = F_124 ( V_3 , V_356 , & V_353 ) ) )
goto V_428;
V_353 = ( V_353 & 0x0f0 ) | 0x301 ;
if ( ( V_180 = F_179 ( V_3 , V_356 , V_353 ) ) )
goto V_428;
F_168 ( V_3 -> V_5 , 1 ) ;
V_180 = F_171 ( V_3 , V_464 , V_433 ) ;
if ( V_180 )
goto V_428;
if ( F_177 ( V_3 ) )
goto V_428;
if ( V_468 )
* V_468 = true ;
if ( F_180 ( V_3 -> V_5 ) && F_13 ( V_3 ) ) {
if ( F_162 ) {
unsigned long V_469 ;
V_469 = F_163 ( V_435 ,
V_470 ) ;
if ( F_164 ( V_469 , V_433 ) )
V_469 = V_433 ;
F_161 ( V_3 , V_469 , F_162 ) ;
}
V_180 = - V_277 ;
goto V_428;
}
V_180 = 0 ;
if ( F_162 )
V_180 = F_161 ( V_3 , V_433 , F_162 ) ;
V_428:
if ( V_180 && V_180 != - V_277 ) {
if ( V_468 )
* V_468 = false ;
F_181 ( V_3 , L_125 , V_180 ) ;
}
F_30 ( L_126 , V_180 ) ;
return V_180 ;
}
int F_182 ( struct V_2 * V_3 , unsigned int * V_181 ,
unsigned long V_433 )
{
const unsigned long * V_464 = F_176 ( & V_3 -> V_173 ) ;
bool V_468 ;
int V_180 ;
V_180 = F_178 ( V_3 , V_464 , V_433 , & V_468 , NULL ) ;
return V_468 ? - V_277 : V_180 ;
}
void F_183 ( struct V_2 * V_3 , unsigned int * V_342 )
{
T_1 V_454 ;
F_30 ( L_124 ) ;
if ( ! F_124 ( V_3 , V_455 , & V_454 ) )
F_148 ( V_3 , V_455 , V_454 ) ;
F_139 ( V_3 ) ;
F_30 ( L_127 ) ;
}
static int F_184 ( struct V_14 * V_15 , unsigned int V_471 ,
const T_4 * V_472 )
{
const T_4 * V_473 = V_15 -> V_142 ;
unsigned char V_474 [ 2 ] [ V_299 + 1 ] ;
unsigned char V_475 [ 2 ] [ V_476 + 1 ] ;
if ( V_15 -> V_181 != V_471 ) {
F_57 ( V_15 , L_128 ,
V_15 -> V_181 , V_471 ) ;
return 0 ;
}
F_41 ( V_473 , V_474 [ 0 ] , V_308 , sizeof( V_474 [ 0 ] ) ) ;
F_41 ( V_472 , V_474 [ 1 ] , V_308 , sizeof( V_474 [ 1 ] ) ) ;
F_41 ( V_473 , V_475 [ 0 ] , V_477 , sizeof( V_475 [ 0 ] ) ) ;
F_41 ( V_472 , V_475 [ 1 ] , V_477 , sizeof( V_475 [ 1 ] ) ) ;
if ( strcmp ( V_474 [ 0 ] , V_474 [ 1 ] ) ) {
F_57 ( V_15 , L_129 ,
V_474 [ 0 ] , V_474 [ 1 ] ) ;
return 0 ;
}
if ( strcmp ( V_475 [ 0 ] , V_475 [ 1 ] ) ) {
F_57 ( V_15 , L_130 ,
V_475 [ 0 ] , V_475 [ 1 ] ) ;
return 0 ;
}
return 1 ;
}
int F_58 ( struct V_14 * V_15 , unsigned int V_478 )
{
unsigned int V_181 = V_15 -> V_181 ;
T_4 * V_142 = ( void * ) V_15 -> V_3 -> V_5 -> V_479 ;
int V_180 ;
V_180 = F_94 ( V_15 , & V_181 , V_478 , V_142 ) ;
if ( V_180 )
return V_180 ;
if ( ! F_184 ( V_15 , V_181 , V_142 ) )
return - V_259 ;
memcpy ( V_15 -> V_142 , V_142 , sizeof( V_142 [ 0 ] ) * V_249 ) ;
return 0 ;
}
int F_157 ( struct V_14 * V_15 , unsigned int V_471 ,
unsigned int V_478 )
{
T_3 V_305 = V_15 -> V_305 ;
T_3 V_183 = V_15 -> V_183 ;
int V_180 ;
if ( ! F_8 ( V_15 ) )
return - V_259 ;
if ( F_185 ( V_471 ) &&
V_471 != V_137 &&
V_471 != V_138 &&
V_471 != V_140 ) {
F_57 ( V_15 , L_131 ,
V_15 -> V_181 , V_471 ) ;
V_180 = - V_259 ;
goto V_350;
}
V_180 = F_58 ( V_15 , V_478 ) ;
if ( V_180 )
goto V_350;
V_180 = F_113 ( V_15 ) ;
if ( V_180 )
goto V_350;
if ( V_15 -> V_181 != V_137 || ! V_305 ||
V_15 -> V_305 == V_305 )
return 0 ;
F_24 ( V_15 , L_132 ,
( unsigned long long ) V_305 ,
( unsigned long long ) V_15 -> V_305 ) ;
if ( V_15 -> V_183 == V_183 &&
V_15 -> V_305 > V_305 && V_15 -> V_305 == V_183 ) {
F_24 ( V_15 ,
L_133
L_134 ) ;
return 0 ;
}
if ( V_15 -> V_183 == V_183 &&
V_15 -> V_305 < V_305 && V_305 == V_183 &&
! ( V_15 -> V_48 & V_182 ) ) {
F_24 ( V_15 ,
L_135
L_136 ) ;
V_15 -> V_42 |= V_178 ;
V_180 = - V_165 ;
} else
V_180 = - V_259 ;
V_15 -> V_183 = V_183 ;
V_15 -> V_305 = V_305 ;
V_350:
F_59 ( V_15 , L_137 , V_180 ) ;
return V_180 ;
}
static int F_186 ( const char * V_480 , const char * V_481 )
{
do {
if ( * V_480 == * V_481 || * V_481 == '?' ) {
if ( ! * V_481 ++ )
return 0 ;
} else {
if ( ! * V_480 || * V_481 != '[' )
break;
while ( * ++ V_481 && * V_481 != ']' && * V_480 != * V_481 ) {
if ( * V_481 == '-' && * ( V_481 - 1 ) != '[' )
if ( * V_480 > * ( V_481 - 1 ) && * V_480 < * ( V_481 + 1 ) ) {
++ V_481 ;
break;
}
}
if ( ! * V_481 || * V_481 == ']' )
return 1 ;
while ( * V_481 && * V_481 ++ != ']' ) ;
}
} while ( * ++ V_480 && * V_481 );
if ( * V_481 == '*' ) {
if ( ! * ++ V_481 )
return 0 ;
while ( * V_480 ) {
if ( F_186 ( V_480 , V_481 ) == 0 )
return 0 ;
++ V_480 ;
}
}
if ( ! * V_480 && ! * V_481 )
return 0 ;
return 1 ;
}
static unsigned long F_106 ( const struct V_14 * V_15 )
{
unsigned char V_482 [ V_299 + 1 ] ;
unsigned char V_483 [ V_297 + 1 ] ;
const struct V_484 * V_485 = V_486 ;
F_41 ( V_15 -> V_142 , V_482 , V_308 , sizeof( V_482 ) ) ;
F_41 ( V_15 -> V_142 , V_483 , V_307 , sizeof( V_483 ) ) ;
while ( V_485 -> V_482 ) {
if ( ! F_186 ( V_482 , V_485 -> V_482 ) ) {
if ( V_485 -> V_483 == NULL )
return V_485 -> V_48 ;
if ( ! F_186 ( V_483 , V_485 -> V_483 ) )
return V_485 -> V_48 ;
}
V_485 ++ ;
}
return 0 ;
}
static int F_187 ( const struct V_14 * V_15 )
{
if ( ( V_15 -> V_3 -> V_5 -> V_42 & V_487 ) &&
( V_15 -> V_42 & V_325 ) )
return 1 ;
return ( V_15 -> V_48 & V_488 ) ? 1 : 0 ;
}
static int F_188 ( struct V_14 * V_15 )
{
if ( V_15 -> V_48 & V_489 )
return F_189 ( V_15 -> V_142 ) ;
return F_190 ( V_15 -> V_142 ) ;
}
static int F_191 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
struct V_14 * V_15 ;
if ( V_5 -> V_33 == V_338 )
return 1 ;
if ( V_5 -> V_33 == V_339 || V_5 -> V_33 == V_279 )
return 0 ;
if ( V_5 -> V_33 == V_490 )
return 0 ;
F_192 (link, ap, EDGE) {
F_135 (dev, link, ENABLED) {
if ( ! F_188 ( V_15 ) )
return 0 ;
}
}
return 1 ;
}
static void F_159 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_491 * V_430 = V_5 -> V_430 ;
unsigned long V_47 ;
V_47 = F_31 ( V_5 -> V_44 ,
V_5 -> V_45 , V_5 -> V_46 ) ;
V_47 &= F_31 ( V_15 -> V_44 ,
V_15 -> V_45 , V_15 -> V_46 ) ;
V_47 &= F_61 ( V_15 -> V_142 ) ;
if ( F_142 ( V_15 ) ) {
V_47 &= ~ ( 0x03 << ( V_120 + 5 ) ) ;
V_47 &= ~ ( 0x03 << ( V_122 + 3 ) ) ;
}
if ( F_187 ( V_15 ) ) {
V_47 &= ~ ( V_123 | V_125 ) ;
F_24 ( V_15 ,
L_138 ) ;
}
if ( ( V_430 -> V_42 & V_431 ) &&
V_430 -> V_432 && V_430 -> V_432 != V_5 ) {
V_47 &= ~ ( V_123 | V_125 ) ;
F_24 ( V_15 ,
L_139 ) ;
}
if ( V_5 -> V_42 & V_242 )
V_47 &= F_92 ( V_15 ) ;
if ( V_5 -> V_213 -> V_492 )
V_47 = V_5 -> V_213 -> V_492 ( V_15 , V_47 ) ;
if ( V_47 & ( 0xF8 << V_124 ) )
if ( F_191 ( V_5 ) ) {
F_24 ( V_15 ,
L_140 ) ;
V_47 &= ~ ( 0xF8 << V_124 ) ;
}
F_16 ( V_47 , & V_15 -> V_44 ,
& V_15 -> V_45 , & V_15 -> V_46 ) ;
}
static unsigned int F_156 ( struct V_14 * V_15 )
{
struct V_67 V_68 ;
unsigned int V_157 ;
F_30 ( L_141 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_493 ;
V_68 . V_72 = V_494 ;
V_68 . V_42 |= V_108 | V_109 | V_261 ;
V_68 . V_92 = V_160 ;
if ( F_90 ( V_15 ) )
V_68 . V_80 = V_15 -> V_133 ;
else if ( F_91 ( V_15 -> V_142 ) )
V_68 . V_80 = 0x01 ;
else
return 0 ;
V_157 = F_53 ( V_15 , & V_68 , NULL , V_161 , NULL , 0 , 0 ) ;
F_30 ( L_142 , V_157 ) ;
return V_157 ;
}
unsigned int F_100 ( struct V_14 * V_15 , T_2 V_495 , T_2 V_72 )
{
struct V_67 V_68 ;
unsigned int V_157 ;
F_30 ( L_143 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_493 ;
V_68 . V_72 = V_495 ;
V_68 . V_42 |= V_108 | V_109 ;
V_68 . V_92 = V_160 ;
V_68 . V_80 = V_72 ;
V_157 = F_53 ( V_15 , & V_68 , NULL , V_161 , NULL , 0 , 0 ) ;
F_30 ( L_142 , V_157 ) ;
return V_157 ;
}
static unsigned int F_102 ( struct V_14 * V_15 ,
T_4 V_103 , T_4 V_104 )
{
struct V_67 V_68 ;
unsigned int V_157 ;
if ( V_104 < 1 || V_104 > 255 || V_103 < 1 || V_103 > 16 )
return V_496 ;
F_30 ( L_144 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_497 ;
V_68 . V_42 |= V_108 | V_109 ;
V_68 . V_92 = V_160 ;
V_68 . V_80 = V_104 ;
V_68 . V_21 |= ( V_103 - 1 ) & 0x0f ;
V_157 = F_53 ( V_15 , & V_68 , NULL , V_161 , NULL , 0 , 0 ) ;
if ( V_157 == V_162 && ( V_68 . V_72 & V_163 ) )
V_157 = 0 ;
F_30 ( L_142 , V_157 ) ;
return V_157 ;
}
void F_193 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
struct V_199 * V_225 = V_193 -> V_225 ;
int V_498 = V_193 -> V_198 ;
F_194 ( V_225 == NULL ) ;
F_195 ( L_145 , V_193 -> V_201 ) ;
if ( V_193 -> V_201 )
F_196 ( V_5 -> V_15 , V_225 , V_193 -> V_499 , V_498 ) ;
V_193 -> V_42 &= ~ V_500 ;
V_193 -> V_225 = NULL ;
}
int F_197 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
if ( ! ( V_193 -> V_15 -> V_48 & V_501 ) &&
F_5 ( V_193 -> V_227 & 15 ) )
return 1 ;
if ( V_5 -> V_213 -> V_502 )
return V_5 -> V_213 -> V_502 ( V_193 ) ;
return 0 ;
}
int F_198 ( struct V_192 * V_193 )
{
struct V_2 * V_3 = V_193 -> V_15 -> V_3 ;
if ( V_193 -> V_68 . V_92 == V_112 ) {
if ( ! F_199 ( V_3 -> V_217 ) )
return 0 ;
} else {
if ( ! F_199 ( V_3 -> V_217 ) && ! V_3 -> V_218 )
return 0 ;
}
return V_503 ;
}
void F_200 ( struct V_192 * V_193 ) { }
void F_74 ( struct V_192 * V_193 , struct V_199 * V_225 ,
unsigned int V_201 )
{
V_193 -> V_225 = V_225 ;
V_193 -> V_201 = V_201 ;
V_193 -> V_504 = V_193 -> V_225 ;
}
static int F_201 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
unsigned int V_201 ;
F_195 ( L_146 , V_5 -> V_31 ) ;
V_201 = F_202 ( V_5 -> V_15 , V_193 -> V_225 , V_193 -> V_201 , V_193 -> V_198 ) ;
if ( V_201 < 1 )
return - 1 ;
F_30 ( L_147 , V_201 ) ;
V_193 -> V_499 = V_193 -> V_201 ;
V_193 -> V_201 = V_201 ;
V_193 -> V_42 |= V_500 ;
return 0 ;
}
void F_98 ( T_4 * V_238 , unsigned int V_505 )
{
#ifdef F_203
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < V_505 ; V_25 ++ )
V_238 [ V_25 ] = F_204 ( V_238 [ V_25 ] ) ;
#endif
}
static struct V_192 * F_205 ( struct V_4 * V_5 )
{
struct V_192 * V_193 = NULL ;
unsigned int V_25 ;
if ( F_5 ( V_5 -> V_210 & V_211 ) )
return NULL ;
for ( V_25 = 0 ; V_25 < V_289 - 1 ; V_25 ++ )
if ( ! F_69 ( V_25 , & V_5 -> V_215 ) ) {
V_193 = F_71 ( V_5 , V_25 ) ;
break;
}
if ( V_193 )
V_193 -> V_107 = V_25 ;
return V_193 ;
}
struct V_192 * F_206 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_192 * V_193 ;
V_193 = F_205 ( V_5 ) ;
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
F_194 ( V_193 == NULL ) ;
V_5 = V_193 -> V_5 ;
V_193 -> V_42 = 0 ;
V_107 = V_193 -> V_107 ;
if ( F_27 ( F_199 ( V_107 ) ) ) {
V_193 -> V_107 = V_221 ;
F_207 ( V_107 , & V_5 -> V_215 ) ;
}
}
void F_208 ( struct V_192 * V_193 )
{
struct V_4 * V_5 ;
struct V_2 * V_3 ;
F_194 ( V_193 == NULL ) ;
F_194 ( ! ( V_193 -> V_42 & V_230 ) ) ;
V_5 = V_193 -> V_5 ;
V_3 = V_193 -> V_15 -> V_3 ;
if ( F_27 ( V_193 -> V_42 & V_500 ) )
F_193 ( V_193 ) ;
if ( V_193 -> V_68 . V_92 == V_112 ) {
V_3 -> V_218 &= ~ ( 1 << V_193 -> V_107 ) ;
if ( ! V_3 -> V_218 )
V_5 -> V_220 -- ;
} else {
V_3 -> V_217 = V_221 ;
V_5 -> V_220 -- ;
}
if ( F_5 ( V_193 -> V_42 & V_506 &&
V_5 -> V_507 == V_3 ) )
V_5 -> V_507 = NULL ;
V_193 -> V_42 &= ~ V_230 ;
V_5 -> V_219 &= ~ ( 1 << V_193 -> V_107 ) ;
V_193 -> V_228 ( V_193 ) ;
}
static void F_209 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
V_193 -> V_234 . V_42 = V_193 -> V_68 . V_42 ;
V_5 -> V_213 -> V_508 ( V_193 ) ;
}
static void F_210 ( struct V_192 * V_193 )
{
struct V_14 * V_15 = V_193 -> V_15 ;
if ( F_211 ( V_193 -> V_68 . V_92 ) )
return;
if ( ( V_15 -> V_45 || V_15 -> V_46 ) && F_212 ( V_193 -> V_68 . V_92 ) )
return;
V_15 -> V_42 &= ~ V_509 ;
}
void F_83 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
if ( V_5 -> V_213 -> V_214 ) {
struct V_14 * V_15 = V_193 -> V_15 ;
struct V_510 * V_511 = & V_15 -> V_3 -> V_512 ;
if ( F_5 ( V_193 -> V_157 ) )
V_193 -> V_42 |= V_233 ;
if ( F_5 ( F_213 ( V_193 -> V_107 ) ) ) {
F_209 ( V_193 ) ;
F_208 ( V_193 ) ;
return;
}
if ( F_5 ( V_193 -> V_42 & V_233 ) ) {
F_209 ( V_193 ) ;
F_214 ( V_193 ) ;
return;
}
F_194 ( V_5 -> V_210 & V_211 ) ;
if ( V_193 -> V_42 & V_223 )
F_209 ( V_193 ) ;
switch ( V_193 -> V_68 . V_71 ) {
case V_493 :
if ( V_193 -> V_68 . V_72 != V_513 &&
V_193 -> V_68 . V_72 != V_514 )
break;
case V_497 :
case V_515 :
V_511 -> V_516 [ V_15 -> V_24 ] |= V_517 ;
F_215 ( V_5 ) ;
break;
case V_518 :
V_15 -> V_42 |= V_519 ;
break;
}
if ( F_5 ( V_15 -> V_42 & V_509 ) )
F_210 ( V_193 ) ;
F_208 ( V_193 ) ;
} else {
if ( V_193 -> V_42 & V_520 )
return;
if ( V_193 -> V_157 || V_193 -> V_42 & V_223 )
F_209 ( V_193 ) ;
F_208 ( V_193 ) ;
}
}
int F_216 ( struct V_4 * V_5 , T_1 V_219 )
{
int V_521 = 0 ;
T_1 V_522 ;
V_522 = V_5 -> V_219 ^ V_219 ;
if ( F_5 ( V_522 & V_219 ) ) {
F_217 ( V_5 , L_148 ,
V_5 -> V_219 , V_219 ) ;
return - V_117 ;
}
while ( V_522 ) {
struct V_192 * V_193 ;
unsigned int V_107 = F_218 ( V_522 ) ;
V_193 = F_219 ( V_5 , V_107 ) ;
if ( V_193 ) {
F_83 ( V_193 ) ;
V_521 ++ ;
}
V_522 &= ~ ( 1 << V_107 ) ;
}
return V_521 ;
}
void F_75 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
struct V_2 * V_3 = V_193 -> V_15 -> V_3 ;
T_2 V_523 = V_193 -> V_68 . V_92 ;
F_194 ( V_5 -> V_213 -> V_214 && F_199 ( V_3 -> V_217 ) ) ;
if ( F_220 ( V_523 ) ) {
F_194 ( V_3 -> V_218 & ( 1 << V_193 -> V_107 ) ) ;
if ( ! V_3 -> V_218 )
V_5 -> V_220 ++ ;
V_3 -> V_218 |= 1 << V_193 -> V_107 ;
} else {
F_194 ( V_3 -> V_218 ) ;
V_5 -> V_220 ++ ;
V_3 -> V_217 = V_193 -> V_107 ;
}
V_193 -> V_42 |= V_230 ;
V_5 -> V_219 |= 1 << V_193 -> V_107 ;
if ( F_194 ( F_221 ( V_523 ) &&
( ! V_193 -> V_225 || ! V_193 -> V_201 || ! V_193 -> V_227 ) ) )
goto V_524;
if ( F_222 ( V_523 ) || ( F_212 ( V_523 ) &&
( V_5 -> V_42 & V_525 ) ) )
if ( F_201 ( V_193 ) )
goto V_524;
if ( F_5 ( V_193 -> V_15 -> V_42 & V_519 ) ) {
V_3 -> V_512 . V_465 |= V_526 ;
F_223 ( & V_3 -> V_512 , L_149 ) ;
F_224 ( V_3 ) ;
return;
}
V_5 -> V_213 -> V_527 ( V_193 ) ;
V_193 -> V_157 |= V_5 -> V_213 -> V_528 ( V_193 ) ;
if ( F_5 ( V_193 -> V_157 ) )
goto V_529;
return;
V_524:
V_193 -> V_157 |= V_212 ;
V_529:
F_83 ( V_193 ) ;
}
int F_104 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
return ( V_5 -> V_42 & V_416 ) && V_5 -> V_213 -> V_530 ;
}
int F_124 ( struct V_2 * V_3 , int V_531 , T_1 * V_532 )
{
if ( F_13 ( V_3 ) ) {
if ( F_104 ( V_3 ) )
return V_3 -> V_5 -> V_213 -> V_530 ( V_3 , V_531 , V_532 ) ;
return - V_360 ;
}
return F_225 ( V_3 , V_531 , V_532 ) ;
}
int F_148 ( struct V_2 * V_3 , int V_531 , T_1 V_532 )
{
if ( F_13 ( V_3 ) ) {
if ( F_104 ( V_3 ) )
return V_3 -> V_5 -> V_213 -> V_533 ( V_3 , V_531 , V_532 ) ;
return - V_360 ;
}
return F_226 ( V_3 , V_531 , V_532 ) ;
}
int F_179 ( struct V_2 * V_3 , int V_531 , T_1 V_532 )
{
if ( F_13 ( V_3 ) ) {
int V_180 ;
if ( F_104 ( V_3 ) ) {
V_180 = V_3 -> V_5 -> V_213 -> V_533 ( V_3 , V_531 , V_532 ) ;
if ( V_180 == 0 )
V_180 = V_3 -> V_5 -> V_213 -> V_530 ( V_3 , V_531 , & V_532 ) ;
return V_180 ;
}
return - V_360 ;
}
return F_226 ( V_3 , V_531 , V_532 ) ;
}
bool F_140 ( struct V_2 * V_3 )
{
T_1 V_1 ;
if ( F_124 ( V_3 , V_355 , & V_1 ) == 0 &&
F_1 ( V_1 ) )
return true ;
return false ;
}
bool F_177 ( struct V_2 * V_3 )
{
T_1 V_1 ;
if ( F_124 ( V_3 , V_355 , & V_1 ) == 0 &&
! F_1 ( V_1 ) )
return true ;
return false ;
}
bool F_165 ( struct V_2 * V_3 )
{
struct V_2 * V_534 = V_3 -> V_5 -> V_12 ;
F_87 ( V_3 == V_534 ) ;
return F_140 ( V_3 ) ||
( V_534 && F_140 ( V_534 ) ) ;
}
bool F_166 ( struct V_2 * V_3 )
{
struct V_2 * V_534 = V_3 -> V_5 -> V_12 ;
F_87 ( V_3 == V_534 ) ;
return F_177 ( V_3 ) &&
( ! V_534 || F_177 ( V_534 ) ) ;
}
static int F_227 ( struct V_491 * V_430 , T_6 V_535 ,
unsigned int V_465 , unsigned int V_536 ,
int V_208 )
{
unsigned long V_42 ;
int V_25 , V_180 ;
for ( V_25 = 0 ; V_25 < V_430 -> V_537 ; V_25 ++ ) {
struct V_4 * V_5 = V_430 -> V_538 [ V_25 ] ;
struct V_2 * V_3 ;
if ( V_5 -> V_210 & V_539 ) {
F_228 ( V_5 ) ;
F_87 ( V_5 -> V_210 & V_539 ) ;
}
F_67 ( V_5 -> V_209 , V_42 ) ;
V_5 -> V_540 = V_535 ;
if ( V_208 ) {
V_180 = 0 ;
V_5 -> V_541 = & V_180 ;
}
V_5 -> V_210 |= V_539 ;
F_192 (link, ap, HOST_FIRST) {
V_3 -> V_512 . V_465 |= V_465 ;
V_3 -> V_512 . V_42 |= V_536 ;
}
F_215 ( V_5 ) ;
F_68 ( V_5 -> V_209 , V_42 ) ;
if ( V_208 ) {
F_228 ( V_5 ) ;
F_87 ( V_5 -> V_210 & V_539 ) ;
if ( V_180 )
return V_180 ;
}
}
return 0 ;
}
int F_229 ( struct V_491 * V_430 , T_6 V_535 )
{
unsigned int V_536 = V_542 ;
int V_180 ;
if ( V_535 . V_543 == V_544 )
V_536 |= V_545 | V_546 ;
V_180 = F_227 ( V_430 , V_535 , 0 , V_536 , 1 ) ;
if ( V_180 == 0 )
V_430 -> V_15 -> V_547 . V_548 = V_535 ;
return V_180 ;
}
void F_230 ( struct V_491 * V_430 )
{
F_227 ( V_430 , V_549 , V_526 ,
V_545 | V_542 , 0 ) ;
V_430 -> V_15 -> V_547 . V_548 = V_549 ;
}
void F_231 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = F_9 ( V_15 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_42 ;
V_3 -> V_275 = V_3 -> V_40 ;
V_3 -> V_276 = 0 ;
F_67 ( V_5 -> V_209 , V_42 ) ;
V_15 -> V_42 &= ~ V_550 ;
V_15 -> V_48 = 0 ;
F_68 ( V_5 -> V_209 , V_42 ) ;
memset ( ( void * ) V_15 + V_551 , 0 ,
V_552 - V_551 ) ;
V_15 -> V_44 = V_363 ;
V_15 -> V_45 = V_363 ;
V_15 -> V_46 = V_363 ;
}
void F_232 ( struct V_4 * V_5 , struct V_2 * V_3 , int V_38 )
{
int V_25 ;
memset ( ( void * ) V_3 + V_553 , 0 ,
V_554 - V_553 ) ;
V_3 -> V_5 = V_5 ;
V_3 -> V_38 = V_38 ;
V_3 -> V_217 = V_221 ;
V_3 -> V_40 = V_363 ;
for ( V_25 = 0 ; V_25 < V_343 ; V_25 ++ ) {
struct V_14 * V_15 = & V_3 -> V_21 [ V_25 ] ;
V_15 -> V_3 = V_3 ;
V_15 -> V_24 = V_15 - V_3 -> V_21 ;
#ifdef F_233
V_15 -> V_555 = V_556 ;
#endif
F_231 ( V_15 ) ;
}
}
int F_234 ( struct V_2 * V_3 )
{
T_2 V_135 ;
int V_180 ;
V_180 = F_124 ( V_3 , V_356 , & V_3 -> V_557 ) ;
if ( V_180 )
return V_180 ;
V_135 = ( V_3 -> V_557 >> 4 ) & 0xf ;
if ( V_135 )
V_3 -> V_40 &= ( 1 << V_135 ) - 1 ;
F_12 ( V_3 ) ;
V_3 -> V_275 = V_3 -> V_40 ;
return 0 ;
}
struct V_4 * F_235 ( struct V_491 * V_430 )
{
struct V_4 * V_5 ;
F_30 ( L_124 ) ;
V_5 = F_236 ( sizeof( * V_5 ) , V_558 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_210 |= V_559 | V_211 ;
V_5 -> V_209 = & V_430 -> V_209 ;
V_5 -> V_31 = - 1 ;
V_5 -> V_430 = V_430 ;
V_5 -> V_15 = V_430 -> V_15 ;
#if F_237 ( V_560 )
V_5 -> V_561 = 0x00FF ;
#elif F_237 ( V_562 )
V_5 -> V_561 = V_563 | V_564 | V_565 | V_566 | V_567 ;
#else
V_5 -> V_561 = V_563 | V_567 | V_566 ;
#endif
F_238 ( & V_5 -> V_568 ) ;
F_239 ( & V_5 -> V_569 , V_570 ) ;
F_240 ( & V_5 -> V_571 , V_572 ) ;
F_241 ( & V_5 -> V_573 ) ;
F_242 ( & V_5 -> V_574 ) ;
F_243 ( & V_5 -> V_575 ) ;
F_244 ( & V_5 -> V_576 ) ;
V_5 -> V_576 . V_577 = V_578 ;
V_5 -> V_576 . V_579 = ( unsigned long ) V_5 ;
V_5 -> V_33 = V_34 ;
F_232 ( V_5 , & V_5 -> V_3 , 0 ) ;
#ifdef F_245
V_5 -> V_580 . V_581 = 1 ;
V_5 -> V_580 . V_582 = 1 ;
#endif
F_246 ( V_5 ) ;
return V_5 ;
}
static void F_247 ( struct V_21 * V_583 , void * V_584 )
{
struct V_491 * V_430 = F_248 ( V_583 ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_430 -> V_537 ; V_25 ++ ) {
struct V_4 * V_5 = V_430 -> V_538 [ V_25 ] ;
if ( ! V_5 )
continue;
if ( V_5 -> V_287 )
F_249 ( V_5 -> V_287 ) ;
F_250 ( V_5 -> V_11 ) ;
F_250 ( V_5 -> V_12 ) ;
F_250 ( V_5 ) ;
V_430 -> V_538 [ V_25 ] = NULL ;
}
F_251 ( V_583 , NULL ) ;
}
struct V_491 * F_252 ( struct V_21 * V_15 , int V_585 )
{
struct V_491 * V_430 ;
T_5 V_586 ;
int V_25 ;
F_30 ( L_124 ) ;
if ( ! F_253 ( V_15 , NULL , V_558 ) )
return NULL ;
V_586 = sizeof( struct V_491 ) + ( V_585 + 1 ) * sizeof( void * ) ;
V_430 = F_254 ( F_247 , V_586 , V_558 ) ;
if ( ! V_430 )
goto V_260;
F_255 ( V_15 , V_430 ) ;
F_251 ( V_15 , V_430 ) ;
F_256 ( & V_430 -> V_209 ) ;
F_238 ( & V_430 -> V_587 ) ;
V_430 -> V_15 = V_15 ;
V_430 -> V_537 = V_585 ;
for ( V_25 = 0 ; V_25 < V_585 ; V_25 ++ ) {
struct V_4 * V_5 ;
V_5 = F_235 ( V_430 ) ;
if ( ! V_5 )
goto V_260;
V_5 -> V_588 = V_25 ;
V_430 -> V_538 [ V_25 ] = V_5 ;
}
F_257 ( V_15 , NULL ) ;
return V_430 ;
V_260:
F_258 ( V_15 , NULL ) ;
return NULL ;
}
struct V_491 * F_259 ( struct V_21 * V_15 ,
const struct V_589 * const * V_590 ,
int V_537 )
{
const struct V_589 * V_591 ;
struct V_491 * V_430 ;
int V_25 , V_592 ;
V_430 = F_252 ( V_15 , V_537 ) ;
if ( ! V_430 )
return NULL ;
for ( V_25 = 0 , V_592 = 0 , V_591 = NULL ; V_25 < V_430 -> V_537 ; V_25 ++ ) {
struct V_4 * V_5 = V_430 -> V_538 [ V_25 ] ;
if ( V_590 [ V_592 ] )
V_591 = V_590 [ V_592 ++ ] ;
V_5 -> V_44 = V_591 -> V_44 ;
V_5 -> V_45 = V_591 -> V_45 ;
V_5 -> V_46 = V_591 -> V_46 ;
V_5 -> V_42 |= V_591 -> V_42 ;
V_5 -> V_3 . V_42 |= V_591 -> V_593 ;
V_5 -> V_213 = V_591 -> V_594 ;
if ( ! V_430 -> V_213 && ( V_591 -> V_594 != & V_595 ) )
V_430 -> V_213 = V_591 -> V_594 ;
}
return V_430 ;
}
int F_260 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
F_87 ( V_5 -> V_12 ) ;
F_87 ( V_5 -> V_42 & V_596 ) ;
V_3 = F_236 ( sizeof( * V_3 ) , V_558 ) ;
if ( ! V_3 )
return - V_597 ;
F_232 ( V_5 , V_3 , 1 ) ;
V_5 -> V_12 = V_3 ;
return 0 ;
}
static void F_261 ( struct V_21 * V_583 , void * V_584 )
{
struct V_491 * V_430 = F_248 ( V_583 ) ;
int V_25 ;
F_87 ( ! ( V_430 -> V_42 & V_598 ) ) ;
for ( V_25 = 0 ; V_25 < V_430 -> V_537 ; V_25 ++ ) {
struct V_4 * V_5 = V_430 -> V_538 [ V_25 ] ;
if ( V_5 -> V_213 -> V_599 )
V_5 -> V_213 -> V_599 ( V_5 ) ;
}
if ( V_430 -> V_213 -> V_600 )
V_430 -> V_213 -> V_600 ( V_430 ) ;
}
static void F_262 ( struct V_601 * V_213 )
{
static F_263 ( V_209 ) ;
const struct V_601 * V_451 ;
void * * V_602 = ( void * * ) V_213 ;
void * * V_603 = ( void * * ) & V_213 -> V_604 ;
void * * V_605 ;
if ( ! V_213 || ! V_213 -> V_604 )
return;
F_264 ( & V_209 ) ;
for ( V_451 = V_213 -> V_604 ; V_451 ; V_451 = V_451 -> V_604 ) {
void * * V_606 = ( void * * ) V_451 ;
for ( V_605 = V_602 ; V_605 < V_603 ; V_605 ++ , V_606 ++ )
if ( ! * V_605 )
* V_605 = * V_606 ;
}
for ( V_605 = V_602 ; V_605 < V_603 ; V_605 ++ )
if ( F_265 ( * V_605 ) )
* V_605 = NULL ;
V_213 -> V_604 = NULL ;
F_266 ( & V_209 ) ;
}
int F_267 ( struct V_491 * V_430 )
{
int V_607 = 0 ;
void * V_608 = NULL ;
int V_25 , V_180 ;
if ( V_430 -> V_42 & V_598 )
return 0 ;
F_262 ( V_430 -> V_213 ) ;
for ( V_25 = 0 ; V_25 < V_430 -> V_537 ; V_25 ++ ) {
struct V_4 * V_5 = V_430 -> V_538 [ V_25 ] ;
F_262 ( V_5 -> V_213 ) ;
if ( ! V_430 -> V_213 && ! F_268 ( V_5 ) )
V_430 -> V_213 = V_5 -> V_213 ;
if ( V_5 -> V_213 -> V_599 )
V_607 = 1 ;
}
if ( V_430 -> V_213 -> V_600 )
V_607 = 1 ;
if ( V_607 ) {
V_608 = F_254 ( F_261 , 0 , V_558 ) ;
if ( ! V_608 )
return - V_597 ;
}
for ( V_25 = 0 ; V_25 < V_430 -> V_537 ; V_25 ++ ) {
struct V_4 * V_5 = V_430 -> V_538 [ V_25 ] ;
if ( V_5 -> V_213 -> V_609 ) {
V_180 = V_5 -> V_213 -> V_609 ( V_5 ) ;
if ( V_180 ) {
if ( V_180 != - V_259 )
F_269 ( V_430 -> V_15 ,
L_150 ,
V_25 , V_180 ) ;
goto V_260;
}
}
F_270 ( V_5 ) ;
}
if ( V_608 )
F_255 ( V_430 -> V_15 , V_608 ) ;
V_430 -> V_42 |= V_598 ;
return 0 ;
V_260:
while ( -- V_25 >= 0 ) {
struct V_4 * V_5 = V_430 -> V_538 [ V_25 ] ;
if ( V_5 -> V_213 -> V_599 )
V_5 -> V_213 -> V_599 ( V_5 ) ;
}
F_271 ( V_608 ) ;
return V_180 ;
}
void F_272 ( struct V_491 * V_430 , struct V_21 * V_15 ,
unsigned long V_42 , struct V_601 * V_213 )
{
F_256 ( & V_430 -> V_209 ) ;
F_238 ( & V_430 -> V_587 ) ;
V_430 -> V_15 = V_15 ;
V_430 -> V_42 = V_42 ;
V_430 -> V_213 = V_213 ;
}
int F_273 ( struct V_4 * V_5 )
{
int V_180 = 0 ;
if ( V_5 -> V_213 -> V_214 ) {
struct V_510 * V_511 = & V_5 -> V_3 . V_512 ;
unsigned long V_42 ;
F_67 ( V_5 -> V_209 , V_42 ) ;
V_511 -> V_610 |= V_611 ;
V_511 -> V_465 |= V_526 ;
V_511 -> V_42 |= V_545 | V_542 ;
V_5 -> V_210 &= ~ V_559 ;
V_5 -> V_210 |= V_612 ;
F_215 ( V_5 ) ;
F_68 ( V_5 -> V_209 , V_42 ) ;
F_228 ( V_5 ) ;
} else {
F_30 ( L_151 , V_5 -> V_31 ) ;
V_180 = F_134 ( V_5 ) ;
F_30 ( L_152 , V_5 -> V_31 ) ;
}
return V_180 ;
}
static void F_274 ( void * V_579 , T_7 V_613 )
{
struct V_4 * V_5 = V_579 ;
if ( ! ( V_5 -> V_430 -> V_42 & V_438 ) && V_5 -> V_588 != 0 )
F_275 ( V_613 ) ;
( void ) F_273 ( V_5 ) ;
F_275 ( V_613 ) ;
F_276 ( V_5 , 1 ) ;
}
int F_277 ( struct V_491 * V_430 , struct V_614 * V_615 )
{
int V_25 , V_180 ;
if ( ! ( V_430 -> V_42 & V_598 ) ) {
F_269 ( V_430 -> V_15 , L_153 ) ;
F_87 ( 1 ) ;
return - V_117 ;
}
for ( V_25 = V_430 -> V_537 ; V_430 -> V_538 [ V_25 ] ; V_25 ++ )
F_250 ( V_430 -> V_538 [ V_25 ] ) ;
for ( V_25 = 0 ; V_25 < V_430 -> V_537 ; V_25 ++ )
V_430 -> V_538 [ V_25 ] -> V_31 = V_616 ++ ;
for ( V_25 = 0 ; V_25 < V_430 -> V_537 ; V_25 ++ ) {
V_180 = F_278 ( V_430 -> V_15 , V_430 -> V_538 [ V_25 ] ) ;
if ( V_180 ) {
goto V_617;
}
}
V_180 = F_279 ( V_430 , V_615 ) ;
if ( V_180 )
goto V_617;
F_280 ( V_430 ) ;
for ( V_25 = 0 ; V_25 < V_430 -> V_537 ; V_25 ++ ) {
struct V_4 * V_5 = V_430 -> V_538 [ V_25 ] ;
unsigned long V_47 ;
if ( V_5 -> V_33 == V_34 && ( V_5 -> V_42 & V_416 ) )
V_5 -> V_33 = V_279 ;
F_234 ( & V_5 -> V_3 ) ;
if ( V_5 -> V_12 )
F_234 ( V_5 -> V_12 ) ;
V_47 = F_31 ( V_5 -> V_44 , V_5 -> V_45 ,
V_5 -> V_46 ) ;
if ( ! F_268 ( V_5 ) ) {
V_589 ( V_5 , L_154 ,
( V_5 -> V_42 & V_416 ) ? 'S' : 'P' ,
F_36 ( V_47 ) ,
V_5 -> V_3 . V_512 . V_280 ) ;
F_281 ( & V_5 -> V_3 . V_512 ) ;
} else
V_589 ( V_5 , L_155 ) ;
}
for ( V_25 = 0 ; V_25 < V_430 -> V_537 ; V_25 ++ ) {
struct V_4 * V_5 = V_430 -> V_538 [ V_25 ] ;
F_282 ( F_274 , V_5 ) ;
}
return 0 ;
V_617:
while ( -- V_25 >= 0 ) {
F_283 ( V_430 -> V_538 [ V_25 ] ) ;
}
return V_180 ;
}
int F_284 ( struct V_491 * V_430 , int V_618 ,
T_8 V_619 , unsigned long V_620 ,
struct V_614 * V_615 )
{
int V_25 , V_180 ;
V_180 = F_267 ( V_430 ) ;
if ( V_180 )
return V_180 ;
if ( ! V_618 ) {
F_87 ( V_619 ) ;
return F_277 ( V_430 , V_615 ) ;
}
V_180 = F_285 ( V_430 -> V_15 , V_618 , V_619 , V_620 ,
F_286 ( V_430 -> V_15 ) , V_430 ) ;
if ( V_180 )
return V_180 ;
for ( V_25 = 0 ; V_25 < V_430 -> V_537 ; V_25 ++ )
F_287 ( V_430 -> V_538 [ V_25 ] , L_156 , V_618 ) ;
V_180 = F_277 ( V_430 , V_615 ) ;
if ( V_180 )
F_288 ( V_430 -> V_15 , V_618 , V_430 ) ;
return V_180 ;
}
static void F_289 ( struct V_4 * V_5 )
{
unsigned long V_42 ;
if ( ! V_5 -> V_213 -> V_214 )
goto V_621;
F_67 ( V_5 -> V_209 , V_42 ) ;
V_5 -> V_210 |= V_622 ;
F_215 ( V_5 ) ;
F_68 ( V_5 -> V_209 , V_42 ) ;
F_228 ( V_5 ) ;
F_87 ( ! ( V_5 -> V_210 & V_623 ) ) ;
F_290 ( & V_5 -> V_569 ) ;
V_621:
if ( V_5 -> V_11 ) {
int V_25 ;
for ( V_25 = 0 ; V_25 < V_624 ; V_25 ++ )
F_291 ( & V_5 -> V_11 [ V_25 ] ) ;
}
F_283 ( V_5 ) ;
F_292 ( V_5 -> V_287 ) ;
}
void F_293 ( struct V_491 * V_430 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_430 -> V_537 ; V_25 ++ )
F_289 ( V_430 -> V_538 [ V_25 ] ) ;
F_294 ( V_430 ) ;
}
void F_295 ( struct V_625 * V_626 )
{
struct V_21 * V_15 = & V_626 -> V_15 ;
struct V_491 * V_430 = F_248 ( V_15 ) ;
F_293 ( V_430 ) ;
}
int F_296 ( struct V_625 * V_626 , const struct V_627 * V_131 )
{
unsigned long V_354 = 0 ;
switch ( V_131 -> V_628 ) {
case 1 : {
T_2 V_629 = 0 ;
F_297 ( V_626 , V_131 -> V_531 , & V_629 ) ;
V_354 = V_629 ;
break;
}
case 2 : {
T_4 V_630 = 0 ;
F_298 ( V_626 , V_131 -> V_531 , & V_630 ) ;
V_354 = V_630 ;
break;
}
case 4 : {
T_1 V_631 = 0 ;
F_299 ( V_626 , V_131 -> V_531 , & V_631 ) ;
V_354 = V_631 ;
break;
}
default:
return - V_117 ;
}
V_354 &= V_131 -> V_358 ;
return ( V_354 == V_131 -> V_532 ) ? 1 : 0 ;
}
void F_300 ( struct V_625 * V_626 , T_6 V_535 )
{
F_301 ( V_626 ) ;
F_302 ( V_626 ) ;
if ( V_535 . V_543 & V_632 )
F_303 ( V_626 , V_633 ) ;
}
int F_304 ( struct V_625 * V_626 )
{
int V_180 ;
F_303 ( V_626 , V_634 ) ;
F_305 ( V_626 ) ;
V_180 = F_306 ( V_626 ) ;
if ( V_180 ) {
F_269 ( & V_626 -> V_15 ,
L_157 , V_180 ) ;
return V_180 ;
}
F_307 ( V_626 ) ;
return 0 ;
}
int F_308 ( struct V_625 * V_626 , T_6 V_535 )
{
struct V_491 * V_430 = F_248 ( & V_626 -> V_15 ) ;
int V_180 = 0 ;
V_180 = F_229 ( V_430 , V_535 ) ;
if ( V_180 )
return V_180 ;
F_300 ( V_626 , V_535 ) ;
return 0 ;
}
int F_309 ( struct V_625 * V_626 )
{
struct V_491 * V_430 = F_248 ( & V_626 -> V_15 ) ;
int V_180 ;
V_180 = F_304 ( V_626 ) ;
if ( V_180 == 0 )
F_230 ( V_430 ) ;
return V_180 ;
}
static int T_9 F_310 ( char * * V_451 ,
struct V_27 * V_635 ,
const char * * V_251 )
{
static struct V_636 V_637 [] V_638 = {
{ L_158 , . V_33 = V_338 } ,
{ L_159 , . V_33 = V_339 } ,
{ L_160 , . V_33 = V_490 } ,
{ L_161 , . V_33 = V_340 } ,
{ L_162 , . V_33 = V_341 } ,
{ L_163 , . V_33 = V_279 } ,
{ L_164 , . V_39 = 1 } ,
{ L_165 , . V_39 = 2 } ,
{ L_166 , . V_49 = V_285 } ,
{ L_167 , . V_50 = V_285 } ,
{ L_168 , . V_49 = V_266 } ,
{ L_169 , . V_47 = 1 << ( V_120 + 0 ) } ,
{ L_170 , . V_47 = 1 << ( V_120 + 1 ) } ,
{ L_171 , . V_47 = 1 << ( V_120 + 2 ) } ,
{ L_172 , . V_47 = 1 << ( V_120 + 3 ) } ,
{ L_173 , . V_47 = 1 << ( V_120 + 4 ) } ,
{ L_174 , . V_47 = 1 << ( V_120 + 5 ) } ,
{ L_175 , . V_47 = 1 << ( V_120 + 6 ) } ,
{ L_176 , . V_47 = 1 << ( V_122 + 0 ) } ,
{ L_177 , . V_47 = 1 << ( V_122 + 1 ) } ,
{ L_178 , . V_47 = 1 << ( V_122 + 2 ) } ,
{ L_179 , . V_47 = 1 << ( V_122 + 3 ) } ,
{ L_180 , . V_47 = 1 << ( V_122 + 4 ) } ,
{ L_181 , . V_47 = 1 << ( V_124 + 0 ) } ,
{ L_182 , . V_47 = 1 << ( V_124 + 0 ) } ,
{ L_183 , . V_47 = 1 << ( V_124 + 0 ) } ,
{ L_184 , . V_47 = 1 << ( V_124 + 1 ) } ,
{ L_185 , . V_47 = 1 << ( V_124 + 1 ) } ,
{ L_186 , . V_47 = 1 << ( V_124 + 1 ) } ,
{ L_187 , . V_47 = 1 << ( V_124 + 2 ) } ,
{ L_188 , . V_47 = 1 << ( V_124 + 2 ) } ,
{ L_189 , . V_47 = 1 << ( V_124 + 2 ) } ,
{ L_190 , . V_47 = 1 << ( V_124 + 3 ) } ,
{ L_191 , . V_47 = 1 << ( V_124 + 3 ) } ,
{ L_192 , . V_47 = 1 << ( V_124 + 3 ) } ,
{ L_193 , . V_47 = 1 << ( V_124 + 4 ) } ,
{ L_194 , . V_47 = 1 << ( V_124 + 4 ) } ,
{ L_195 , . V_47 = 1 << ( V_124 + 4 ) } ,
{ L_196 , . V_47 = 1 << ( V_124 + 5 ) } ,
{ L_197 , . V_47 = 1 << ( V_124 + 5 ) } ,
{ L_198 , . V_47 = 1 << ( V_124 + 5 ) } ,
{ L_199 , . V_47 = 1 << ( V_124 + 6 ) } ,
{ L_200 , . V_47 = 1 << ( V_124 + 6 ) } ,
{ L_201 , . V_47 = 1 << ( V_124 + 6 ) } ,
{ L_202 , . V_47 = 1 << ( V_124 + 7 ) } ,
{ L_203 , . V_41 = V_639 } ,
{ L_204 , . V_41 = V_640 } ,
{ L_205 , . V_41 = V_639 | V_640 } ,
} ;
char * V_434 = * V_451 , * V_147 = * V_451 ;
char * V_142 , * V_532 , * V_641 ;
const struct V_636 * V_642 = NULL ;
int V_643 = 0 , V_25 ;
while ( * V_147 != '\0' && * V_147 != ',' )
V_147 ++ ;
if ( * V_147 == '\0' )
* V_451 = V_147 ;
else
* V_451 = V_147 + 1 ;
* V_147 = '\0' ;
V_147 = strchr ( V_434 , ':' ) ;
if ( ! V_147 ) {
V_532 = F_311 ( V_434 ) ;
goto V_644;
}
* V_147 = '\0' ;
V_142 = F_311 ( V_434 ) ;
V_532 = F_311 ( V_147 + 1 ) ;
V_147 = strchr ( V_142 , '.' ) ;
if ( V_147 ) {
* V_147 ++ = '\0' ;
V_635 -> V_21 = F_312 ( V_147 , & V_641 , 10 ) ;
if ( V_147 == V_641 || * V_641 != '\0' ) {
* V_251 = L_206 ;
return - V_117 ;
}
}
V_635 -> V_30 = F_312 ( V_142 , & V_641 , 10 ) ;
if ( V_147 == V_641 || * V_641 != '\0' ) {
* V_251 = L_207 ;
return - V_117 ;
}
V_644:
for ( V_25 = 0 ; V_25 < F_37 ( V_637 ) ; V_25 ++ ) {
const struct V_636 * V_645 = & V_637 [ V_25 ] ;
if ( strncasecmp ( V_532 , V_645 -> V_35 , strlen ( V_532 ) ) )
continue;
V_643 ++ ;
V_642 = V_645 ;
if ( strcasecmp ( V_532 , V_645 -> V_35 ) == 0 ) {
V_643 = 1 ;
break;
}
}
if ( ! V_643 ) {
* V_251 = L_208 ;
return - V_117 ;
}
if ( V_643 > 1 ) {
* V_251 = L_209 ;
return - V_117 ;
}
V_635 -> V_32 = * V_642 ;
return 0 ;
}
static void T_9 F_313 ( void )
{
int V_646 = 0 , V_647 = 1 ;
int V_648 = - 1 , V_649 = - 1 ;
char * V_147 , * V_451 , * V_23 ;
for ( V_147 = V_650 ; * V_147 ; V_147 ++ )
if ( * V_147 == ',' )
V_647 ++ ;
V_29 = F_236 ( sizeof( V_29 [ 0 ] ) * V_647 , V_558 ) ;
if ( ! V_29 ) {
F_314 ( V_651 L_210
L_211 ) ;
return;
}
for ( V_451 = V_650 ; * V_451 != '\0' ; V_451 = V_23 ) {
const char * V_251 = L_67 ;
struct V_27 V_652 = { . V_30 = - 1 , . V_21 = - 1 } ;
V_23 = V_451 ;
if ( F_310 ( & V_23 , & V_652 , & V_251 ) ) {
F_314 ( V_651 L_212
L_213 ,
V_451 , V_251 ) ;
continue;
}
if ( V_652 . V_30 == - 1 ) {
V_652 . V_30 = V_648 ;
V_652 . V_21 = V_649 ;
}
V_29 [ V_646 ++ ] = V_652 ;
V_648 = V_652 . V_30 ;
V_649 = V_652 . V_21 ;
}
V_26 = V_646 ;
}
static int T_9 F_315 ( void )
{
int V_180 ;
F_313 () ;
V_180 = F_316 () ;
if ( V_180 ) {
F_250 ( V_29 ) ;
return V_180 ;
}
F_317 () ;
V_653 = F_318 () ;
if ( ! V_653 ) {
F_319 () ;
V_180 = - V_597 ;
goto V_260;
}
F_314 ( V_267 L_214 V_654 L_215 ) ;
return 0 ;
V_260:
return V_180 ;
}
static void T_10 F_320 ( void )
{
F_321 ( V_653 ) ;
F_322 () ;
F_319 () ;
F_250 ( V_29 ) ;
}
int F_323 ( void )
{
return F_324 ( & V_655 ) ;
}
void F_168 ( struct V_4 * V_5 , unsigned int V_656 )
{
bool V_657 = V_5 && V_5 -> V_430 -> V_658 == V_659 ;
if ( V_657 )
F_77 ( V_5 ) ;
F_174 ( V_656 ) ;
if ( V_657 )
F_80 ( V_5 ) ;
}
T_1 F_325 ( struct V_4 * V_5 , void T_11 * V_531 , T_1 V_358 , T_1 V_532 ,
unsigned long V_447 , unsigned long V_202 )
{
unsigned long V_433 ;
T_1 V_354 ;
V_354 = F_326 ( V_531 ) ;
V_433 = F_163 ( V_435 , V_202 ) ;
while ( ( V_354 & V_358 ) == V_532 && F_167 ( V_435 , V_433 ) ) {
F_168 ( V_5 , V_447 ) ;
V_354 = F_326 ( V_531 ) ;
}
return V_354 ;
}
static unsigned int F_327 ( struct V_192 * V_193 )
{
return V_212 ;
}
static void F_328 ( struct V_4 * V_5 )
{
}
int F_329 ( const struct V_4 * V_5 , const char * V_660 ,
const char * V_661 , ... )
{
struct V_662 V_663 ;
T_12 args ;
int V_664 ;
va_start ( args , V_661 ) ;
V_663 . V_661 = V_661 ;
V_663 . V_665 = & args ;
V_664 = F_314 ( L_216 , V_660 , V_5 -> V_31 , & V_663 ) ;
va_end ( args ) ;
return V_664 ;
}
int F_330 ( const struct V_2 * V_3 , const char * V_660 ,
const char * V_661 , ... )
{
struct V_662 V_663 ;
T_12 args ;
int V_664 ;
va_start ( args , V_661 ) ;
V_663 . V_661 = V_661 ;
V_663 . V_665 = & args ;
if ( F_4 ( V_3 -> V_5 ) || V_3 -> V_5 -> V_12 )
V_664 = F_314 ( L_217 ,
V_660 , V_3 -> V_5 -> V_31 , V_3 -> V_38 , & V_663 ) ;
else
V_664 = F_314 ( L_216 ,
V_660 , V_3 -> V_5 -> V_31 , & V_663 ) ;
va_end ( args ) ;
return V_664 ;
}
int F_331 ( const struct V_14 * V_15 , const char * V_660 ,
const char * V_661 , ... )
{
struct V_662 V_663 ;
T_12 args ;
int V_664 ;
va_start ( args , V_661 ) ;
V_663 . V_661 = V_661 ;
V_663 . V_665 = & args ;
V_664 = F_314 ( L_217 ,
V_660 , V_15 -> V_3 -> V_5 -> V_31 , V_15 -> V_3 -> V_38 + V_15 -> V_24 ,
& V_663 ) ;
va_end ( args ) ;
return V_664 ;
}
void F_332 ( const struct V_21 * V_15 , const char * V_666 )
{
F_333 ( V_267 , V_15 , L_218 , V_666 ) ;
}
