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
V_15 -> V_42 |= V_115 ;
if ( F_45 ( V_142 ) ) {
V_15 -> V_42 |= V_116 ;
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
V_15 -> V_306 = 16 ;
}
else if ( V_15 -> V_181 == V_138 ) {
const char * V_317 = L_67 ;
const char * V_318 = L_67 ;
const char * V_319 = L_67 ;
T_1 V_320 ;
V_180 = F_122 ( V_142 ) ;
if ( ( V_180 < 12 ) || ( V_180 > V_222 ) ) {
if ( F_84 ( V_5 ) )
F_24 ( V_15 , L_94 ) ;
V_180 = - V_117 ;
goto V_321;
}
V_15 -> V_306 = ( unsigned int ) V_180 ;
if ( V_322 &&
( V_5 -> V_42 & V_323 ) && F_123 ( V_142 ) &&
( ! F_4 ( V_5 ) ||
F_124 ( & V_5 -> V_3 , V_324 , & V_320 ) == 0 ) ) {
unsigned int V_157 ;
V_157 = F_100 ( V_15 ,
V_295 , V_325 ) ;
if ( V_157 )
F_59 ( V_15 ,
L_95 ,
V_157 ) ;
else {
V_15 -> V_42 |= V_326 ;
V_318 = L_96 ;
}
}
if ( F_125 ( V_15 -> V_142 ) ) {
V_15 -> V_42 |= V_327 ;
V_317 = L_97 ;
}
if ( V_328 || F_126 ( V_15 -> V_142 ) ) {
V_15 -> V_42 |= V_329 ;
V_319 = L_98 ;
}
if ( F_127 ( V_15 -> V_142 ) )
V_15 -> V_42 |= V_330 ;
if ( F_121 ( V_5 ) && V_174 )
F_57 ( V_15 ,
L_99 ,
V_300 , V_298 ,
F_36 ( V_47 ) ,
V_317 , V_318 ,
V_319 ) ;
}
V_15 -> V_156 = V_331 ;
if ( V_15 -> V_42 & V_116 )
V_15 -> V_156 = V_332 ;
if ( F_105 ( V_15 ) ) {
if ( F_121 ( V_5 ) && V_174 )
F_57 ( V_15 , L_100 ) ;
V_15 -> V_46 &= V_333 ;
V_15 -> V_156 = V_331 ;
}
if ( ( V_15 -> V_181 == V_138 ) &&
( F_128 ( V_142 ) == V_334 ) ) {
V_15 -> V_156 = V_335 ;
V_15 -> V_48 |= V_336 ;
}
if ( V_15 -> V_48 & V_337 )
V_15 -> V_156 = F_129 (unsigned int, ATA_MAX_SECTORS_128,
dev->max_sectors) ;
if ( V_5 -> V_213 -> V_338 )
V_5 -> V_213 -> V_338 ( V_15 ) ;
if ( V_15 -> V_48 & V_339 ) {
if ( V_174 ) {
F_24 ( V_15 ,
L_101 ) ;
F_24 ( V_15 ,
L_102 ) ;
}
}
if ( ( V_15 -> V_48 & V_340 ) && V_174 ) {
F_24 ( V_15 , L_103 ) ;
F_24 ( V_15 , L_104 ) ;
}
return 0 ;
V_321:
if ( F_115 ( V_5 ) )
F_96 ( V_15 , L_105 , V_255 ) ;
return V_180 ;
}
int F_130 ( struct V_4 * V_5 )
{
return V_341 ;
}
int F_131 ( struct V_4 * V_5 )
{
return V_342 ;
}
int F_132 ( struct V_4 * V_5 )
{
return V_343 ;
}
int F_133 ( struct V_4 * V_5 )
{
return V_344 ;
}
int F_134 ( struct V_4 * V_5 )
{
return V_281 ;
}
int F_135 ( struct V_4 * V_5 )
{
unsigned int V_345 [ V_346 ] ;
int V_347 [ V_346 ] ;
int V_180 ;
struct V_14 * V_15 ;
F_136 (dev, &ap->link, ALL)
V_347 [ V_15 -> V_24 ] = V_348 ;
V_256:
F_136 (dev, &ap->link, ALL) {
V_15 -> V_243 = V_349 ;
if ( V_5 -> V_213 -> V_350 )
V_5 -> V_213 -> V_350 ( V_5 , V_15 ) ;
}
V_5 -> V_213 -> V_351 ( V_5 ) ;
F_136 (dev, &ap->link, ALL) {
if ( V_15 -> V_181 != V_141 )
V_345 [ V_15 -> V_24 ] = V_15 -> V_181 ;
else
V_345 [ V_15 -> V_24 ] = V_352 ;
V_15 -> V_181 = V_141 ;
}
F_136 (dev, &ap->link, ALL_REVERSE) {
if ( V_347 [ V_15 -> V_24 ] )
V_15 -> V_181 = V_345 [ V_15 -> V_24 ] ;
if ( ! F_8 ( V_15 ) )
continue;
V_180 = F_94 ( V_15 , & V_15 -> V_181 , V_272 ,
V_15 -> V_142 ) ;
if ( V_180 )
goto V_353;
}
if ( V_5 -> V_213 -> V_354 )
V_5 -> V_33 = V_5 -> V_213 -> V_354 ( V_5 ) ;
F_136 (dev, &ap->link, ENABLED)
if ( F_107 ( V_15 -> V_142 ) )
V_5 -> V_33 = V_281 ;
F_136 (dev, &ap->link, ENABLED) {
V_5 -> V_3 . V_173 . V_25 . V_42 |= V_175 ;
V_180 = F_113 ( V_15 ) ;
V_5 -> V_3 . V_173 . V_25 . V_42 &= ~ V_175 ;
if ( V_180 )
goto V_353;
}
V_180 = F_137 ( & V_5 -> V_3 , & V_15 ) ;
if ( V_180 )
goto V_353;
F_136 (dev, &ap->link, ENABLED)
return 0 ;
return - V_259 ;
V_353:
V_347 [ V_15 -> V_24 ] -- ;
switch ( V_180 ) {
case - V_117 :
V_347 [ V_15 -> V_24 ] = 0 ;
break;
case - V_259 :
V_347 [ V_15 -> V_24 ] = F_111 ( V_347 [ V_15 -> V_24 ] , 1 ) ;
case - V_165 :
if ( V_347 [ V_15 -> V_24 ] == 1 ) {
F_138 ( & V_5 -> V_3 , 0 ) ;
F_139 ( V_15 , V_355 ) ;
}
}
if ( ! V_347 [ V_15 -> V_24 ] )
F_116 ( V_15 ) ;
goto V_256;
}
static void F_140 ( struct V_2 * V_3 )
{
T_1 V_1 , V_356 , V_357 ;
if ( F_124 ( V_3 , V_358 , & V_1 ) )
return;
F_124 ( V_3 , V_359 , & V_356 ) ;
if ( F_141 ( V_3 ) ) {
V_357 = ( V_1 >> 4 ) & 0xf ;
F_142 ( V_3 , L_106 ,
F_38 ( V_357 ) , V_1 , V_356 ) ;
} else {
F_142 ( V_3 , L_107 ,
V_1 , V_356 ) ;
}
}
struct V_14 * F_143 ( struct V_14 * V_240 )
{
struct V_2 * V_3 = V_240 -> V_3 ;
struct V_14 * V_360 = & V_3 -> V_21 [ 1 - V_240 -> V_24 ] ;
if ( ! F_8 ( V_360 ) )
return NULL ;
return V_360 ;
}
int F_138 ( struct V_2 * V_3 , T_1 V_39 )
{
T_1 V_1 , V_135 , V_361 ;
int V_180 , V_362 ;
if ( ! F_104 ( V_3 ) )
return - V_363 ;
V_180 = F_124 ( V_3 , V_358 , & V_1 ) ;
if ( V_180 == 0 && F_1 ( V_1 ) )
V_135 = ( V_1 >> 4 ) & 0xf ;
else
V_135 = V_3 -> V_278 ;
V_361 = V_3 -> V_277 ;
if ( V_361 <= 1 )
return - V_117 ;
V_362 = F_33 ( V_361 ) - 1 ;
V_361 &= ~ ( 1 << V_362 ) ;
if ( V_135 > 1 )
V_361 &= ( 1 << ( V_135 - 1 ) ) - 1 ;
else
V_361 &= 1 ;
if ( ! V_361 )
return - V_117 ;
if ( V_39 ) {
if ( V_361 & ( ( 1 << V_39 ) - 1 ) )
V_361 &= ( 1 << V_39 ) - 1 ;
else {
V_362 = F_144 ( V_361 ) - 1 ;
V_361 = 1 << V_362 ;
}
}
V_3 -> V_277 = V_361 ;
F_145 ( V_3 , L_108 ,
F_38 ( F_33 ( V_361 ) ) ) ;
return 0 ;
}
static int F_146 ( struct V_2 * V_3 , T_1 * V_356 )
{
struct V_2 * V_364 = & V_3 -> V_5 -> V_3 ;
T_1 V_365 , V_274 , V_135 ;
V_365 = V_3 -> V_277 ;
if ( ! F_13 ( V_3 ) && V_364 -> V_278 )
V_365 &= ( 1 << V_364 -> V_278 ) - 1 ;
if ( V_365 == V_366 )
V_274 = 0 ;
else
V_274 = F_33 ( V_365 ) ;
V_135 = ( * V_356 >> 4 ) & 0xf ;
* V_356 = ( * V_356 & ~ 0xf0 ) | ( ( V_274 & 0xf ) << 4 ) ;
return V_135 != V_274 ;
}
static int F_147 ( struct V_2 * V_3 )
{
T_1 V_356 ;
if ( F_124 ( V_3 , V_359 , & V_356 ) )
return 1 ;
return F_146 ( V_3 , & V_356 ) ;
}
int F_148 ( struct V_2 * V_3 )
{
T_1 V_356 ;
int V_180 ;
if ( ( V_180 = F_124 ( V_3 , V_359 , & V_356 ) ) )
return V_180 ;
if ( ! F_146 ( V_3 , & V_356 ) )
return 0 ;
if ( ( V_180 = F_149 ( V_3 , V_359 , V_356 ) ) )
return V_180 ;
return 1 ;
}
static void F_150 ( const struct V_367 * V_368 , struct V_367 * V_369 , int V_370 , int V_371 )
{
V_369 -> V_372 = F_151 ( V_368 -> V_372 * 1000 , V_370 ) ;
V_369 -> V_373 = F_151 ( V_368 -> V_373 * 1000 , V_370 ) ;
V_369 -> V_374 = F_151 ( V_368 -> V_374 * 1000 , V_370 ) ;
V_369 -> V_375 = F_151 ( V_368 -> V_375 * 1000 , V_370 ) ;
V_369 -> V_376 = F_151 ( V_368 -> V_376 * 1000 , V_370 ) ;
V_369 -> V_377 = F_151 ( V_368 -> V_377 * 1000 , V_370 ) ;
V_369 -> V_378 = F_151 ( V_368 -> V_378 * 1000 , V_370 ) ;
V_369 -> V_379 = F_151 ( V_368 -> V_379 * 1000 , V_370 ) ;
V_369 -> V_380 = F_151 ( V_368 -> V_380 * 1000 , V_371 ) ;
}
void F_152 ( const struct V_367 * V_381 , const struct V_367 * V_382 ,
struct V_367 * V_383 , unsigned int V_384 )
{
if ( V_384 & V_385 ) V_383 -> V_372 = V_312 ( V_381 -> V_372 , V_382 -> V_372 ) ;
if ( V_384 & V_386 ) V_383 -> V_373 = V_312 ( V_381 -> V_373 , V_382 -> V_373 ) ;
if ( V_384 & V_387 ) V_383 -> V_374 = V_312 ( V_381 -> V_374 , V_382 -> V_374 ) ;
if ( V_384 & V_388 ) V_383 -> V_375 = V_312 ( V_381 -> V_375 , V_382 -> V_375 ) ;
if ( V_384 & V_389 ) V_383 -> V_376 = V_312 ( V_381 -> V_376 , V_382 -> V_376 ) ;
if ( V_384 & V_390 ) V_383 -> V_377 = V_312 ( V_381 -> V_377 , V_382 -> V_377 ) ;
if ( V_384 & V_391 ) V_383 -> V_378 = V_312 ( V_381 -> V_378 , V_382 -> V_378 ) ;
if ( V_384 & V_392 ) V_383 -> V_379 = V_312 ( V_381 -> V_379 , V_382 -> V_379 ) ;
if ( V_384 & V_393 ) V_383 -> V_380 = V_312 ( V_381 -> V_380 , V_382 -> V_380 ) ;
}
const struct V_367 * F_153 ( T_2 V_133 )
{
const struct V_367 * V_368 = V_367 ;
while ( V_133 > V_368 -> V_7 )
V_368 ++ ;
if ( V_133 == V_368 -> V_7 )
return V_368 ;
return NULL ;
}
int F_154 ( struct V_14 * V_240 , unsigned short V_394 ,
struct V_367 * V_368 , int V_370 , int V_371 )
{
const T_4 * V_142 = V_240 -> V_142 ;
const struct V_367 * V_143 ;
struct V_367 V_147 ;
if ( ! ( V_143 = F_153 ( V_394 ) ) )
return - V_117 ;
memcpy ( V_368 , V_143 , sizeof( * V_143 ) ) ;
if ( V_142 [ V_184 ] & 2 ) {
memset ( & V_147 , 0 , sizeof( V_147 ) ) ;
if ( V_394 >= V_349 && V_394 < V_395 ) {
if ( V_394 <= V_246 )
V_147 . V_379 = V_147 . V_375 = V_142 [ V_247 ] ;
else if ( ( V_394 <= V_396 ) ||
( V_394 == V_244 && ! F_62 ( V_142 ) ) )
V_147 . V_379 = V_147 . V_375 = V_142 [ V_397 ] ;
} else if ( V_394 >= V_398 && V_394 <= V_399 )
V_147 . V_379 = V_142 [ V_400 ] ;
F_152 ( & V_147 , V_368 , V_368 , V_392 | V_388 ) ;
}
F_150 ( V_368 , V_368 , V_370 , V_371 ) ;
if ( V_394 > V_245 ) {
F_154 ( V_240 , V_240 -> V_243 , & V_147 , V_370 , V_371 ) ;
F_152 ( & V_147 , V_368 , V_368 , V_401 ) ;
}
if ( V_368 -> V_373 + V_368 -> V_374 < V_368 -> V_375 ) {
V_368 -> V_373 += ( V_368 -> V_375 - ( V_368 -> V_373 + V_368 -> V_374 ) ) / 2 ;
V_368 -> V_374 = V_368 -> V_375 - V_368 -> V_373 ;
}
if ( V_368 -> V_376 + V_368 -> V_377 < V_368 -> V_379 ) {
V_368 -> V_376 += ( V_368 -> V_379 - ( V_368 -> V_376 + V_368 -> V_377 ) ) / 2 ;
V_368 -> V_377 = V_368 -> V_379 - V_368 -> V_376 ;
}
if ( V_368 -> V_376 + V_368 -> V_377 > V_368 -> V_379 )
V_368 -> V_379 = V_368 -> V_376 + V_368 -> V_377 ;
return 0 ;
}
T_2 F_155 ( unsigned int V_402 , int V_379 )
{
T_2 V_403 = 0xff , V_404 = 0xff ;
const struct V_127 * V_128 ;
const struct V_367 * V_368 ;
for ( V_128 = V_129 ; V_128 -> V_130 >= 0 ; V_128 ++ )
if ( V_128 -> V_130 == V_402 )
V_403 = V_128 -> V_132 ;
for ( V_368 = F_153 ( V_403 ) ;
V_368 && F_35 ( V_368 -> V_7 ) == V_402 ; V_368 ++ ) {
unsigned short V_405 ;
switch ( V_402 ) {
case V_120 :
case V_122 :
V_405 = V_368 -> V_379 ;
break;
case V_124 :
V_405 = V_368 -> V_380 ;
break;
default:
return 0xff ;
}
if ( V_379 > V_405 )
break;
V_404 = V_368 -> V_7 ;
}
return V_404 ;
}
int F_139 ( struct V_14 * V_15 , unsigned int V_406 )
{
char V_238 [ 32 ] ;
unsigned long V_407 , V_47 ;
unsigned long V_44 , V_45 , V_46 ;
int V_408 , V_126 ;
V_408 = ! ! ( V_406 & V_409 ) ;
V_406 &= ~ V_409 ;
V_47 = V_407 = F_31 ( V_15 -> V_44 ,
V_15 -> V_45 ,
V_15 -> V_46 ) ;
F_16 ( V_47 , & V_44 , & V_45 , & V_46 ) ;
switch ( V_406 ) {
case V_355 :
V_126 = F_33 ( V_44 ) - 1 ;
V_44 &= ~ ( 1 << V_126 ) ;
break;
case V_410 :
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
case V_411 :
V_46 &= V_412 ;
break;
case V_413 :
V_44 &= 1 ;
case V_414 :
V_45 = 0 ;
V_46 = 0 ;
break;
default:
F_70 () ;
}
V_47 &= F_31 ( V_44 , V_45 , V_46 ) ;
if ( ! ( V_47 & V_121 ) || V_47 == V_407 )
return - V_264 ;
if ( ! V_408 ) {
if ( V_47 & ( V_123 | V_125 ) )
snprintf ( V_238 , sizeof( V_238 ) , L_109 ,
F_36 ( V_47 ) ,
F_36 ( V_47 & V_121 ) ) ;
else
snprintf ( V_238 , sizeof( V_238 ) , L_110 ,
F_36 ( V_47 ) ) ;
F_24 ( V_15 , L_111 , V_238 ) ;
}
F_16 ( V_47 , & V_15 -> V_44 , & V_15 -> V_45 ,
& V_15 -> V_46 ) ;
return 0 ;
}
static int F_156 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_171 * V_172 = & V_15 -> V_3 -> V_173 ;
const bool V_415 = V_15 -> V_48 & V_416 ;
const char * V_417 = L_67 ;
int V_418 = 0 ;
unsigned int V_157 = 0 ;
int V_180 ;
V_15 -> V_42 &= ~ V_91 ;
if ( V_15 -> V_402 == V_120 )
V_15 -> V_42 |= V_91 ;
if ( V_415 && V_5 -> V_42 & V_419 && F_107 ( V_15 -> V_142 ) )
V_417 = L_112 ;
else {
if ( V_415 )
F_24 ( V_15 ,
L_113
L_114 ) ;
V_157 = F_157 ( V_15 ) ;
}
if ( V_157 & ~ V_162 )
goto V_353;
V_172 -> V_25 . V_42 |= V_420 ;
V_180 = F_158 ( V_15 , V_141 , 0 ) ;
V_172 -> V_25 . V_42 &= ~ V_420 ;
if ( V_180 )
return V_180 ;
if ( V_15 -> V_402 == V_120 ) {
if ( F_62 ( V_15 -> V_142 ) )
V_418 = 1 ;
if ( F_101 ( V_15 -> V_142 ) == 0 &&
V_15 -> V_243 <= V_246 )
V_418 = 1 ;
if ( ! F_91 ( V_15 -> V_142 ) && V_15 -> V_243 <= V_246 )
V_418 = 1 ;
}
if ( V_15 -> V_402 == V_122 &&
V_15 -> V_421 == V_398 &&
( V_15 -> V_142 [ 63 ] >> 8 ) & 1 )
V_418 = 1 ;
if ( V_15 -> V_133 == F_32 ( F_61 ( V_15 -> V_142 ) ) )
V_418 = 1 ;
if ( V_157 & V_162 ) {
if ( ! V_418 )
goto V_353;
else
V_417 = L_115 ;
}
F_30 ( L_116 ,
V_15 -> V_402 , ( int ) V_15 -> V_133 ) ;
F_57 ( V_15 , L_117 ,
F_36 ( F_34 ( V_15 -> V_133 ) ) ,
V_417 ) ;
return 0 ;
V_353:
F_59 ( V_15 , L_118 , V_157 ) ;
return - V_165 ;
}
int F_159 ( struct V_2 * V_3 , struct V_14 * * V_422 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_14 * V_15 ;
int V_180 = 0 , V_423 = 0 , V_424 = 0 ;
F_136 (dev, link, ENABLED) {
unsigned long V_44 , V_425 ;
unsigned int V_426 ;
V_426 = V_427 ;
if ( V_15 -> V_181 == V_138 )
V_426 = V_428 ;
else if ( F_62 ( V_15 -> V_142 ) )
V_426 = V_429 ;
F_160 ( V_15 ) ;
F_15 ( V_15 ) ;
V_44 = F_31 ( V_15 -> V_44 , 0 , 0 ) ;
if ( V_430 & V_426 )
V_425 = F_31 ( 0 , V_15 -> V_45 ,
V_15 -> V_46 ) ;
else
V_425 = 0 ;
V_15 -> V_243 = F_32 ( V_44 ) ;
V_15 -> V_421 = F_32 ( V_425 ) ;
V_424 = 1 ;
if ( F_161 ( V_15 ) )
V_423 = 1 ;
}
if ( ! V_424 )
goto V_431;
F_136 (dev, link, ENABLED) {
if ( V_15 -> V_243 == 0xff ) {
F_24 ( V_15 , L_119 ) ;
V_180 = - V_117 ;
goto V_431;
}
V_15 -> V_133 = V_15 -> V_243 ;
V_15 -> V_402 = V_120 ;
if ( V_5 -> V_213 -> V_350 )
V_5 -> V_213 -> V_350 ( V_5 , V_15 ) ;
}
F_136 (dev, link, ENABLED) {
if ( ! F_161 ( V_15 ) )
continue;
V_15 -> V_133 = V_15 -> V_421 ;
V_15 -> V_402 = F_35 ( V_15 -> V_421 ) ;
if ( V_5 -> V_213 -> V_432 )
V_5 -> V_213 -> V_432 ( V_5 , V_15 ) ;
}
F_136 (dev, link, ENABLED) {
V_180 = F_156 ( V_15 ) ;
if ( V_180 )
goto V_431;
}
if ( V_423 && ( V_5 -> V_269 -> V_42 & V_433 ) )
V_5 -> V_269 -> V_434 = V_5 ;
V_431:
if ( V_180 )
* V_422 = V_15 ;
return V_180 ;
}
int F_162 ( struct V_2 * V_3 , unsigned long V_435 ,
int (* F_163)( struct V_2 * V_3 ) )
{
unsigned long V_436 = V_437 ;
unsigned long V_438 ;
int V_439 = 0 ;
if ( V_3 -> V_5 -> V_269 -> V_42 & V_440 )
V_438 = F_164 ( V_436 , V_441 ) ;
else
V_438 = F_164 ( V_436 , V_442 ) ;
F_87 ( V_3 == V_3 -> V_5 -> V_12 ) ;
if ( F_165 ( V_438 , V_435 ) )
V_438 = V_435 ;
while ( 1 ) {
unsigned long V_443 = V_437 ;
int V_444 , V_357 ;
V_444 = V_357 = F_163 ( V_3 ) ;
if ( V_444 > 0 )
return 0 ;
if ( V_444 == - V_259 ) {
if ( F_166 ( V_3 ) )
V_444 = 0 ;
else if ( ( V_3 -> V_5 -> V_42 & V_419 ) &&
! F_167 ( V_3 ) &&
F_168 ( V_443 , V_438 ) )
V_444 = 0 ;
}
if ( V_444 )
return V_444 ;
if ( F_165 ( V_443 , V_435 ) )
return - V_445 ;
if ( ! V_439 && F_165 ( V_443 , V_436 + 5 * V_446 ) &&
( V_435 - V_443 > 3 * V_446 ) ) {
F_145 ( V_3 ,
L_120
L_121 , V_357 ) ;
V_439 = 1 ;
}
F_169 ( V_3 -> V_5 , 50 ) ;
}
}
int F_170 ( struct V_2 * V_3 , unsigned long V_435 ,
int (* F_163)( struct V_2 * V_3 ) )
{
F_169 ( V_3 -> V_5 , V_447 ) ;
return F_162 ( V_3 , V_435 , F_163 ) ;
}
int F_171 ( struct V_2 * V_3 , const unsigned long * V_448 ,
unsigned long V_435 )
{
unsigned long V_449 = V_448 [ 0 ] ;
unsigned long V_450 = V_448 [ 1 ] ;
unsigned long V_451 , V_368 ;
T_1 V_452 , V_453 ;
int V_180 ;
V_368 = F_164 ( V_437 , V_448 [ 2 ] ) ;
if ( F_168 ( V_368 , V_435 ) )
V_435 = V_368 ;
if ( ( V_180 = F_124 ( V_3 , V_358 , & V_453 ) ) )
return V_180 ;
V_453 &= 0xf ;
V_452 = V_453 ;
V_451 = V_437 ;
while ( 1 ) {
F_169 ( V_3 -> V_5 , V_449 ) ;
if ( ( V_180 = F_124 ( V_3 , V_358 , & V_453 ) ) )
return V_180 ;
V_453 &= 0xf ;
if ( V_453 == V_452 ) {
if ( V_453 == 1 && F_168 ( V_437 , V_435 ) )
continue;
if ( F_165 ( V_437 ,
F_164 ( V_451 , V_450 ) ) )
return 0 ;
continue;
}
V_452 = V_453 ;
V_451 = V_437 ;
if ( F_165 ( V_437 , V_435 ) )
return - V_454 ;
}
}
int F_172 ( struct V_2 * V_3 , const unsigned long * V_448 ,
unsigned long V_435 )
{
int V_347 = V_455 ;
T_1 V_356 , V_456 ;
int V_180 ;
if ( ( V_180 = F_124 ( V_3 , V_359 , & V_356 ) ) )
return V_180 ;
do {
V_356 = ( V_356 & 0x0f0 ) | 0x300 ;
if ( ( V_180 = F_149 ( V_3 , V_359 , V_356 ) ) )
return V_180 ;
F_169 ( V_3 -> V_5 , 200 ) ;
if ( ( V_180 = F_124 ( V_3 , V_359 , & V_356 ) ) )
return V_180 ;
} while ( ( V_356 & 0xf0f ) != 0x300 && -- V_347 );
if ( ( V_356 & 0xf0f ) != 0x300 ) {
F_145 ( V_3 , L_122 ,
V_356 ) ;
return 0 ;
}
if ( V_347 < V_455 )
F_145 ( V_3 , L_123 ,
V_455 - V_347 ) ;
if ( ( V_180 = F_171 ( V_3 , V_448 , V_435 ) ) )
return V_180 ;
if ( ! ( V_180 = F_124 ( V_3 , V_457 , & V_456 ) ) )
V_180 = F_149 ( V_3 , V_457 , V_456 ) ;
return V_180 != - V_117 ? V_180 : 0 ;
}
int F_173 ( struct V_2 * V_3 , enum V_458 V_459 ,
bool V_460 )
{
struct V_171 * V_172 = & V_3 -> V_173 ;
bool V_461 = false ;
T_1 V_356 ;
int V_180 ;
V_180 = F_124 ( V_3 , V_359 , & V_356 ) ;
if ( V_180 )
return V_180 ;
switch ( V_459 ) {
case V_462 :
V_356 |= ( 0x3 << 8 ) ;
if ( V_460 ) {
V_356 |= ( 0x4 << 12 ) ;
V_461 = true ;
}
break;
case V_463 :
V_356 &= ~ ( 0x1 << 8 ) ;
V_356 |= ( 0x2 << 8 ) ;
break;
case V_464 :
if ( F_174 ( V_3 ) > 0 )
V_356 &= ~ ( 0x3 << 8 ) ;
else {
V_356 &= ~ 0xf ;
V_356 |= ( 0x1 << 2 ) ;
}
break;
default:
F_87 ( 1 ) ;
}
V_180 = F_149 ( V_3 , V_359 , V_356 ) ;
if ( V_180 )
return V_180 ;
if ( V_461 )
F_175 ( 10 ) ;
V_172 -> V_25 . V_456 &= ~ V_465 ;
return F_149 ( V_3 , V_457 , V_465 ) ;
}
int F_176 ( struct V_2 * V_3 , unsigned long V_435 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_171 * V_172 = & V_3 -> V_173 ;
const unsigned long * V_466 = F_177 ( V_172 ) ;
int V_180 ;
if ( V_172 -> V_25 . V_467 & V_468 )
return 0 ;
if ( V_5 -> V_42 & V_419 ) {
V_180 = F_172 ( V_3 , V_466 , V_435 ) ;
if ( V_180 && V_180 != - V_363 )
F_145 ( V_3 ,
L_124 ,
V_180 ) ;
}
if ( F_178 ( V_3 ) )
V_172 -> V_25 . V_467 &= ~ V_469 ;
return 0 ;
}
int F_179 ( struct V_2 * V_3 , const unsigned long * V_466 ,
unsigned long V_435 ,
bool * V_470 , int (* F_163)( struct V_2 * ) )
{
T_1 V_356 ;
int V_180 ;
F_30 ( L_125 ) ;
if ( V_470 )
* V_470 = false ;
if ( F_147 ( V_3 ) ) {
if ( ( V_180 = F_124 ( V_3 , V_359 , & V_356 ) ) )
goto V_431;
V_356 = ( V_356 & 0x0f0 ) | 0x304 ;
if ( ( V_180 = F_149 ( V_3 , V_359 , V_356 ) ) )
goto V_431;
F_148 ( V_3 ) ;
}
if ( ( V_180 = F_124 ( V_3 , V_359 , & V_356 ) ) )
goto V_431;
V_356 = ( V_356 & 0x0f0 ) | 0x301 ;
if ( ( V_180 = F_180 ( V_3 , V_359 , V_356 ) ) )
goto V_431;
F_169 ( V_3 -> V_5 , 1 ) ;
V_180 = F_172 ( V_3 , V_466 , V_435 ) ;
if ( V_180 )
goto V_431;
if ( F_178 ( V_3 ) )
goto V_431;
if ( V_470 )
* V_470 = true ;
if ( F_181 ( V_3 -> V_5 ) && F_13 ( V_3 ) ) {
if ( F_163 ) {
unsigned long V_471 ;
V_471 = F_164 ( V_437 ,
V_472 ) ;
if ( F_165 ( V_471 , V_435 ) )
V_471 = V_435 ;
F_162 ( V_3 , V_471 , F_163 ) ;
}
V_180 = - V_279 ;
goto V_431;
}
V_180 = 0 ;
if ( F_163 )
V_180 = F_162 ( V_3 , V_435 , F_163 ) ;
V_431:
if ( V_180 && V_180 != - V_279 ) {
if ( V_470 )
* V_470 = false ;
F_182 ( V_3 , L_126 , V_180 ) ;
}
F_30 ( L_127 , V_180 ) ;
return V_180 ;
}
int F_183 ( struct V_2 * V_3 , unsigned int * V_181 ,
unsigned long V_435 )
{
const unsigned long * V_466 = F_177 ( & V_3 -> V_173 ) ;
bool V_470 ;
int V_180 ;
V_180 = F_179 ( V_3 , V_466 , V_435 , & V_470 , NULL ) ;
return V_470 ? - V_279 : V_180 ;
}
void F_184 ( struct V_2 * V_3 , unsigned int * V_345 )
{
T_1 V_456 ;
F_30 ( L_125 ) ;
if ( ! F_124 ( V_3 , V_457 , & V_456 ) )
F_149 ( V_3 , V_457 , V_456 ) ;
F_140 ( V_3 ) ;
F_30 ( L_128 ) ;
}
static int F_185 ( struct V_14 * V_15 , unsigned int V_473 ,
const T_4 * V_474 )
{
const T_4 * V_475 = V_15 -> V_142 ;
unsigned char V_476 [ 2 ] [ V_301 + 1 ] ;
unsigned char V_477 [ 2 ] [ V_478 + 1 ] ;
if ( V_15 -> V_181 != V_473 ) {
F_57 ( V_15 , L_129 ,
V_15 -> V_181 , V_473 ) ;
return 0 ;
}
F_41 ( V_475 , V_476 [ 0 ] , V_310 , sizeof( V_476 [ 0 ] ) ) ;
F_41 ( V_474 , V_476 [ 1 ] , V_310 , sizeof( V_476 [ 1 ] ) ) ;
F_41 ( V_475 , V_477 [ 0 ] , V_479 , sizeof( V_477 [ 0 ] ) ) ;
F_41 ( V_474 , V_477 [ 1 ] , V_479 , sizeof( V_477 [ 1 ] ) ) ;
if ( strcmp ( V_476 [ 0 ] , V_476 [ 1 ] ) ) {
F_57 ( V_15 , L_130 ,
V_476 [ 0 ] , V_476 [ 1 ] ) ;
return 0 ;
}
if ( strcmp ( V_477 [ 0 ] , V_477 [ 1 ] ) ) {
F_57 ( V_15 , L_131 ,
V_477 [ 0 ] , V_477 [ 1 ] ) ;
return 0 ;
}
return 1 ;
}
int F_58 ( struct V_14 * V_15 , unsigned int V_480 )
{
unsigned int V_181 = V_15 -> V_181 ;
T_4 * V_142 = ( void * ) V_15 -> V_3 -> V_5 -> V_481 ;
int V_180 ;
V_180 = F_94 ( V_15 , & V_181 , V_480 , V_142 ) ;
if ( V_180 )
return V_180 ;
if ( ! F_185 ( V_15 , V_181 , V_142 ) )
return - V_259 ;
memcpy ( V_15 -> V_142 , V_142 , sizeof( V_142 [ 0 ] ) * V_249 ) ;
return 0 ;
}
int F_158 ( struct V_14 * V_15 , unsigned int V_473 ,
unsigned int V_480 )
{
T_3 V_307 = V_15 -> V_307 ;
T_3 V_183 = V_15 -> V_183 ;
int V_180 ;
if ( ! F_8 ( V_15 ) )
return - V_259 ;
if ( F_186 ( V_473 ) &&
V_473 != V_137 &&
V_473 != V_138 &&
V_473 != V_140 ) {
F_57 ( V_15 , L_132 ,
V_15 -> V_181 , V_473 ) ;
V_180 = - V_259 ;
goto V_353;
}
V_180 = F_58 ( V_15 , V_480 ) ;
if ( V_180 )
goto V_353;
V_180 = F_113 ( V_15 ) ;
if ( V_180 )
goto V_353;
if ( V_15 -> V_181 != V_137 || ! V_307 ||
V_15 -> V_307 == V_307 )
return 0 ;
F_24 ( V_15 , L_133 ,
( unsigned long long ) V_307 ,
( unsigned long long ) V_15 -> V_307 ) ;
if ( V_15 -> V_183 == V_183 &&
V_15 -> V_307 > V_307 && V_15 -> V_307 == V_183 ) {
F_24 ( V_15 ,
L_134
L_135 ) ;
return 0 ;
}
if ( V_15 -> V_183 == V_183 &&
V_15 -> V_307 < V_307 && V_307 == V_183 &&
! ( V_15 -> V_48 & V_182 ) ) {
F_24 ( V_15 ,
L_136
L_137 ) ;
V_15 -> V_42 |= V_178 ;
V_180 = - V_165 ;
} else
V_180 = - V_259 ;
V_15 -> V_183 = V_183 ;
V_15 -> V_307 = V_307 ;
V_353:
F_59 ( V_15 , L_138 , V_180 ) ;
return V_180 ;
}
static int F_187 ( const char * V_482 , const char * V_483 )
{
do {
if ( * V_482 == * V_483 || * V_483 == '?' ) {
if ( ! * V_483 ++ )
return 0 ;
} else {
if ( ! * V_482 || * V_483 != '[' )
break;
while ( * ++ V_483 && * V_483 != ']' && * V_482 != * V_483 ) {
if ( * V_483 == '-' && * ( V_483 - 1 ) != '[' )
if ( * V_482 > * ( V_483 - 1 ) && * V_482 < * ( V_483 + 1 ) ) {
++ V_483 ;
break;
}
}
if ( ! * V_483 || * V_483 == ']' )
return 1 ;
while ( * V_483 && * V_483 ++ != ']' ) ;
}
} while ( * ++ V_482 && * V_483 );
if ( * V_483 == '*' ) {
if ( ! * ++ V_483 )
return 0 ;
while ( * V_482 ) {
if ( F_187 ( V_482 , V_483 ) == 0 )
return 0 ;
++ V_482 ;
}
}
if ( ! * V_482 && ! * V_483 )
return 0 ;
return 1 ;
}
static unsigned long F_106 ( const struct V_14 * V_15 )
{
unsigned char V_484 [ V_301 + 1 ] ;
unsigned char V_485 [ V_299 + 1 ] ;
const struct V_486 * V_487 = V_488 ;
F_41 ( V_15 -> V_142 , V_484 , V_310 , sizeof( V_484 ) ) ;
F_41 ( V_15 -> V_142 , V_485 , V_309 , sizeof( V_485 ) ) ;
while ( V_487 -> V_484 ) {
if ( ! F_187 ( V_484 , V_487 -> V_484 ) ) {
if ( V_487 -> V_485 == NULL )
return V_487 -> V_48 ;
if ( ! F_187 ( V_485 , V_487 -> V_485 ) )
return V_487 -> V_48 ;
}
V_487 ++ ;
}
return 0 ;
}
static int F_188 ( const struct V_14 * V_15 )
{
if ( ( V_15 -> V_3 -> V_5 -> V_42 & V_489 ) &&
( V_15 -> V_42 & V_327 ) )
return 1 ;
return ( V_15 -> V_48 & V_490 ) ? 1 : 0 ;
}
static int F_189 ( struct V_14 * V_15 )
{
if ( V_15 -> V_48 & V_491 )
return F_190 ( V_15 -> V_142 ) ;
return F_191 ( V_15 -> V_142 ) ;
}
static int F_192 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
struct V_14 * V_15 ;
if ( V_5 -> V_33 == V_341 )
return 1 ;
if ( V_5 -> V_33 == V_342 || V_5 -> V_33 == V_281 )
return 0 ;
if ( V_5 -> V_33 == V_492 )
return 0 ;
F_193 (link, ap, EDGE) {
F_136 (dev, link, ENABLED) {
if ( ! F_189 ( V_15 ) )
return 0 ;
}
}
return 1 ;
}
static void F_160 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_493 * V_269 = V_5 -> V_269 ;
unsigned long V_47 ;
V_47 = F_31 ( V_5 -> V_44 ,
V_5 -> V_45 , V_5 -> V_46 ) ;
V_47 &= F_31 ( V_15 -> V_44 ,
V_15 -> V_45 , V_15 -> V_46 ) ;
V_47 &= F_61 ( V_15 -> V_142 ) ;
if ( F_143 ( V_15 ) ) {
V_47 &= ~ ( 0x03 << ( V_120 + 5 ) ) ;
V_47 &= ~ ( 0x03 << ( V_122 + 3 ) ) ;
}
if ( F_188 ( V_15 ) ) {
V_47 &= ~ ( V_123 | V_125 ) ;
F_24 ( V_15 ,
L_139 ) ;
}
if ( ( V_269 -> V_42 & V_433 ) &&
V_269 -> V_434 && V_269 -> V_434 != V_5 ) {
V_47 &= ~ ( V_123 | V_125 ) ;
F_24 ( V_15 ,
L_140 ) ;
}
if ( V_5 -> V_42 & V_242 )
V_47 &= F_92 ( V_15 ) ;
if ( V_5 -> V_213 -> V_494 )
V_47 = V_5 -> V_213 -> V_494 ( V_15 , V_47 ) ;
if ( V_47 & ( 0xF8 << V_124 ) )
if ( F_192 ( V_5 ) ) {
F_24 ( V_15 ,
L_141 ) ;
V_47 &= ~ ( 0xF8 << V_124 ) ;
}
F_16 ( V_47 , & V_15 -> V_44 ,
& V_15 -> V_45 , & V_15 -> V_46 ) ;
}
static unsigned int F_157 ( struct V_14 * V_15 )
{
struct V_67 V_68 ;
unsigned int V_157 ;
F_30 ( L_142 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_495 ;
V_68 . V_72 = V_496 ;
V_68 . V_42 |= V_108 | V_109 | V_261 ;
V_68 . V_92 = V_160 ;
if ( F_90 ( V_15 ) )
V_68 . V_80 = V_15 -> V_133 ;
else if ( F_91 ( V_15 -> V_142 ) )
V_68 . V_80 = 0x01 ;
else
return 0 ;
V_157 = F_53 ( V_15 , & V_68 , NULL , V_161 , NULL , 0 , 0 ) ;
F_30 ( L_143 , V_157 ) ;
return V_157 ;
}
unsigned int F_100 ( struct V_14 * V_15 , T_2 V_497 , T_2 V_72 )
{
struct V_67 V_68 ;
unsigned int V_157 ;
F_30 ( L_144 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_495 ;
V_68 . V_72 = V_497 ;
V_68 . V_42 |= V_108 | V_109 ;
V_68 . V_92 = V_160 ;
V_68 . V_80 = V_72 ;
V_157 = F_53 ( V_15 , & V_68 , NULL , V_161 , NULL , 0 , 0 ) ;
F_30 ( L_143 , V_157 ) ;
return V_157 ;
}
static unsigned int F_102 ( struct V_14 * V_15 ,
T_4 V_103 , T_4 V_104 )
{
struct V_67 V_68 ;
unsigned int V_157 ;
if ( V_104 < 1 || V_104 > 255 || V_103 < 1 || V_103 > 16 )
return V_498 ;
F_30 ( L_145 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_499 ;
V_68 . V_42 |= V_108 | V_109 ;
V_68 . V_92 = V_160 ;
V_68 . V_80 = V_104 ;
V_68 . V_21 |= ( V_103 - 1 ) & 0x0f ;
V_157 = F_53 ( V_15 , & V_68 , NULL , V_161 , NULL , 0 , 0 ) ;
if ( V_157 == V_162 && ( V_68 . V_72 & V_163 ) )
V_157 = 0 ;
F_30 ( L_143 , V_157 ) ;
return V_157 ;
}
void F_194 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
struct V_199 * V_225 = V_193 -> V_225 ;
int V_500 = V_193 -> V_198 ;
F_195 ( V_225 == NULL ) ;
F_196 ( L_146 , V_193 -> V_201 ) ;
if ( V_193 -> V_201 )
F_197 ( V_5 -> V_15 , V_225 , V_193 -> V_501 , V_500 ) ;
V_193 -> V_42 &= ~ V_502 ;
V_193 -> V_225 = NULL ;
}
int F_198 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
if ( ! ( V_193 -> V_15 -> V_48 & V_503 ) &&
F_5 ( V_193 -> V_227 & 15 ) )
return 1 ;
if ( V_5 -> V_213 -> V_504 )
return V_5 -> V_213 -> V_504 ( V_193 ) ;
return 0 ;
}
int F_199 ( struct V_192 * V_193 )
{
struct V_2 * V_3 = V_193 -> V_15 -> V_3 ;
if ( V_193 -> V_68 . V_92 == V_112 ) {
if ( ! F_200 ( V_3 -> V_217 ) )
return 0 ;
} else {
if ( ! F_200 ( V_3 -> V_217 ) && ! V_3 -> V_218 )
return 0 ;
}
return V_505 ;
}
void F_201 ( struct V_192 * V_193 ) { }
void F_74 ( struct V_192 * V_193 , struct V_199 * V_225 ,
unsigned int V_201 )
{
V_193 -> V_225 = V_225 ;
V_193 -> V_201 = V_201 ;
V_193 -> V_506 = V_193 -> V_225 ;
}
static int F_202 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
unsigned int V_201 ;
F_196 ( L_147 , V_5 -> V_31 ) ;
V_201 = F_203 ( V_5 -> V_15 , V_193 -> V_225 , V_193 -> V_201 , V_193 -> V_198 ) ;
if ( V_201 < 1 )
return - 1 ;
F_30 ( L_148 , V_201 ) ;
V_193 -> V_501 = V_193 -> V_201 ;
V_193 -> V_201 = V_201 ;
V_193 -> V_42 |= V_502 ;
return 0 ;
}
void F_98 ( T_4 * V_238 , unsigned int V_507 )
{
#ifdef F_204
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < V_507 ; V_25 ++ )
V_238 [ V_25 ] = F_205 ( V_238 [ V_25 ] ) ;
#endif
}
static struct V_192 * F_206 ( struct V_4 * V_5 )
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
struct V_192 * F_207 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_192 * V_193 ;
V_193 = F_206 ( V_5 ) ;
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
F_195 ( V_193 == NULL ) ;
V_5 = V_193 -> V_5 ;
V_193 -> V_42 = 0 ;
V_107 = V_193 -> V_107 ;
if ( F_27 ( F_200 ( V_107 ) ) ) {
V_193 -> V_107 = V_221 ;
F_208 ( V_107 , & V_5 -> V_215 ) ;
}
}
void F_209 ( struct V_192 * V_193 )
{
struct V_4 * V_5 ;
struct V_2 * V_3 ;
F_195 ( V_193 == NULL ) ;
F_195 ( ! ( V_193 -> V_42 & V_230 ) ) ;
V_5 = V_193 -> V_5 ;
V_3 = V_193 -> V_15 -> V_3 ;
if ( F_27 ( V_193 -> V_42 & V_502 ) )
F_194 ( V_193 ) ;
if ( V_193 -> V_68 . V_92 == V_112 ) {
V_3 -> V_218 &= ~ ( 1 << V_193 -> V_107 ) ;
if ( ! V_3 -> V_218 )
V_5 -> V_220 -- ;
} else {
V_3 -> V_217 = V_221 ;
V_5 -> V_220 -- ;
}
if ( F_5 ( V_193 -> V_42 & V_508 &&
V_5 -> V_509 == V_3 ) )
V_5 -> V_509 = NULL ;
V_193 -> V_42 &= ~ V_230 ;
V_5 -> V_219 &= ~ ( 1 << V_193 -> V_107 ) ;
V_193 -> V_228 ( V_193 ) ;
}
static void F_210 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
V_193 -> V_234 . V_42 = V_193 -> V_68 . V_42 ;
V_5 -> V_213 -> V_510 ( V_193 ) ;
}
static void F_211 ( struct V_192 * V_193 )
{
struct V_14 * V_15 = V_193 -> V_15 ;
if ( F_212 ( V_193 -> V_68 . V_92 ) )
return;
if ( ( V_15 -> V_45 || V_15 -> V_46 ) && F_213 ( V_193 -> V_68 . V_92 ) )
return;
V_15 -> V_42 &= ~ V_511 ;
}
void F_83 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
if ( V_5 -> V_213 -> V_214 ) {
struct V_14 * V_15 = V_193 -> V_15 ;
struct V_512 * V_513 = & V_15 -> V_3 -> V_514 ;
if ( F_5 ( V_193 -> V_157 ) )
V_193 -> V_42 |= V_233 ;
if ( F_5 ( F_214 ( V_193 -> V_107 ) ) ) {
F_210 ( V_193 ) ;
F_209 ( V_193 ) ;
return;
}
if ( F_5 ( V_193 -> V_42 & V_233 ) ) {
F_210 ( V_193 ) ;
F_215 ( V_193 ) ;
return;
}
F_195 ( V_5 -> V_210 & V_211 ) ;
if ( V_193 -> V_42 & V_223 )
F_210 ( V_193 ) ;
switch ( V_193 -> V_68 . V_71 ) {
case V_495 :
if ( V_193 -> V_68 . V_72 != V_515 &&
V_193 -> V_68 . V_72 != V_516 )
break;
case V_499 :
case V_517 :
V_513 -> V_518 [ V_15 -> V_24 ] |= V_519 ;
F_216 ( V_5 ) ;
break;
case V_520 :
V_15 -> V_42 |= V_521 ;
break;
}
if ( F_5 ( V_15 -> V_42 & V_511 ) )
F_211 ( V_193 ) ;
F_209 ( V_193 ) ;
} else {
if ( V_193 -> V_42 & V_522 )
return;
if ( V_193 -> V_157 || V_193 -> V_42 & V_223 )
F_210 ( V_193 ) ;
F_209 ( V_193 ) ;
}
}
int F_217 ( struct V_4 * V_5 , T_1 V_219 )
{
int V_523 = 0 ;
T_1 V_524 ;
V_524 = V_5 -> V_219 ^ V_219 ;
if ( F_5 ( V_524 & V_219 ) ) {
F_218 ( V_5 , L_149 ,
V_5 -> V_219 , V_219 ) ;
return - V_117 ;
}
while ( V_524 ) {
struct V_192 * V_193 ;
unsigned int V_107 = F_219 ( V_524 ) ;
V_193 = F_220 ( V_5 , V_107 ) ;
if ( V_193 ) {
F_83 ( V_193 ) ;
V_523 ++ ;
}
V_524 &= ~ ( 1 << V_107 ) ;
}
return V_523 ;
}
void F_75 ( struct V_192 * V_193 )
{
struct V_4 * V_5 = V_193 -> V_5 ;
struct V_2 * V_3 = V_193 -> V_15 -> V_3 ;
T_2 V_525 = V_193 -> V_68 . V_92 ;
F_195 ( V_5 -> V_213 -> V_214 && F_200 ( V_3 -> V_217 ) ) ;
if ( F_221 ( V_525 ) ) {
F_195 ( V_3 -> V_218 & ( 1 << V_193 -> V_107 ) ) ;
if ( ! V_3 -> V_218 )
V_5 -> V_220 ++ ;
V_3 -> V_218 |= 1 << V_193 -> V_107 ;
} else {
F_195 ( V_3 -> V_218 ) ;
V_5 -> V_220 ++ ;
V_3 -> V_217 = V_193 -> V_107 ;
}
V_193 -> V_42 |= V_230 ;
V_5 -> V_219 |= 1 << V_193 -> V_107 ;
if ( F_195 ( F_222 ( V_525 ) &&
( ! V_193 -> V_225 || ! V_193 -> V_201 || ! V_193 -> V_227 ) ) )
goto V_526;
if ( F_223 ( V_525 ) || ( F_213 ( V_525 ) &&
( V_5 -> V_42 & V_527 ) ) )
if ( F_202 ( V_193 ) )
goto V_526;
if ( F_5 ( V_193 -> V_15 -> V_42 & V_521 ) ) {
V_3 -> V_514 . V_467 |= V_528 ;
F_224 ( & V_3 -> V_514 , L_150 ) ;
F_225 ( V_3 ) ;
return;
}
V_5 -> V_213 -> V_529 ( V_193 ) ;
V_193 -> V_157 |= V_5 -> V_213 -> V_530 ( V_193 ) ;
if ( F_5 ( V_193 -> V_157 ) )
goto V_531;
return;
V_526:
V_193 -> V_157 |= V_212 ;
V_531:
F_83 ( V_193 ) ;
}
int F_104 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
return ( V_5 -> V_42 & V_419 ) && V_5 -> V_213 -> V_532 ;
}
int F_124 ( struct V_2 * V_3 , int V_533 , T_1 * V_534 )
{
if ( F_13 ( V_3 ) ) {
if ( F_104 ( V_3 ) )
return V_3 -> V_5 -> V_213 -> V_532 ( V_3 , V_533 , V_534 ) ;
return - V_363 ;
}
return F_226 ( V_3 , V_533 , V_534 ) ;
}
int F_149 ( struct V_2 * V_3 , int V_533 , T_1 V_534 )
{
if ( F_13 ( V_3 ) ) {
if ( F_104 ( V_3 ) )
return V_3 -> V_5 -> V_213 -> V_535 ( V_3 , V_533 , V_534 ) ;
return - V_363 ;
}
return F_227 ( V_3 , V_533 , V_534 ) ;
}
int F_180 ( struct V_2 * V_3 , int V_533 , T_1 V_534 )
{
if ( F_13 ( V_3 ) ) {
int V_180 ;
if ( F_104 ( V_3 ) ) {
V_180 = V_3 -> V_5 -> V_213 -> V_535 ( V_3 , V_533 , V_534 ) ;
if ( V_180 == 0 )
V_180 = V_3 -> V_5 -> V_213 -> V_532 ( V_3 , V_533 , & V_534 ) ;
return V_180 ;
}
return - V_363 ;
}
return F_227 ( V_3 , V_533 , V_534 ) ;
}
bool F_141 ( struct V_2 * V_3 )
{
T_1 V_1 ;
if ( F_124 ( V_3 , V_358 , & V_1 ) == 0 &&
F_1 ( V_1 ) )
return true ;
return false ;
}
bool F_178 ( struct V_2 * V_3 )
{
T_1 V_1 ;
if ( F_124 ( V_3 , V_358 , & V_1 ) == 0 &&
! F_1 ( V_1 ) )
return true ;
return false ;
}
bool F_166 ( struct V_2 * V_3 )
{
struct V_2 * V_536 = V_3 -> V_5 -> V_12 ;
F_87 ( V_3 == V_536 ) ;
return F_141 ( V_3 ) ||
( V_536 && F_141 ( V_536 ) ) ;
}
bool F_167 ( struct V_2 * V_3 )
{
struct V_2 * V_536 = V_3 -> V_5 -> V_12 ;
F_87 ( V_3 == V_536 ) ;
return F_178 ( V_3 ) &&
( ! V_536 || F_178 ( V_536 ) ) ;
}
static int F_228 ( struct V_4 * V_5 , T_6 V_537 ,
unsigned int V_467 , unsigned int V_538 ,
int V_208 )
{
struct V_2 * V_3 ;
unsigned long V_42 ;
int V_180 ;
if ( V_5 -> V_210 & V_539 ) {
F_229 ( V_5 ) ;
F_87 ( V_5 -> V_210 & V_539 ) ;
}
F_67 ( V_5 -> V_209 , V_42 ) ;
V_5 -> V_540 = V_537 ;
if ( V_208 ) {
V_180 = 0 ;
V_5 -> V_541 = & V_180 ;
}
V_5 -> V_210 |= V_539 ;
F_193 (link, ap, HOST_FIRST) {
V_3 -> V_514 . V_467 |= V_467 ;
V_3 -> V_514 . V_42 |= V_538 ;
}
F_216 ( V_5 ) ;
F_68 ( V_5 -> V_209 , V_42 ) ;
if ( V_208 ) {
F_229 ( V_5 ) ;
F_87 ( V_5 -> V_210 & V_539 ) ;
}
return V_180 ;
}
static int F_230 ( struct V_21 * V_15 , T_6 V_537 )
{
struct V_4 * V_5 = F_231 ( V_15 ) ;
unsigned int V_538 = V_542 ;
int V_180 ;
if ( V_537 . V_543 == V_544 )
V_538 |= V_545 | V_546 ;
V_180 = F_228 ( V_5 , V_537 , 0 , V_538 , 1 ) ;
return V_180 ;
}
static int F_232 ( struct V_21 * V_15 )
{
if ( F_233 ( V_15 ) )
return 0 ;
return F_230 ( V_15 , V_547 ) ;
}
static int F_234 ( struct V_21 * V_15 )
{
if ( F_233 ( V_15 ) )
F_235 ( V_15 ) ;
return F_230 ( V_15 , V_548 ) ;
}
static int F_236 ( struct V_21 * V_15 )
{
if ( F_233 ( V_15 ) )
return 0 ;
return F_230 ( V_15 , V_549 ) ;
}
static int F_237 ( struct V_21 * V_15 )
{
struct V_4 * V_5 = F_231 ( V_15 ) ;
int V_180 ;
V_180 = F_228 ( V_5 , V_550 , V_528 ,
V_545 | V_542 , 1 ) ;
return V_180 ;
}
static int F_238 ( struct V_21 * V_15 )
{
int V_180 ;
V_180 = F_237 ( V_15 ) ;
if ( ! V_180 ) {
F_239 ( V_15 ) ;
F_240 ( V_15 ) ;
F_241 ( V_15 ) ;
}
return V_180 ;
}
static int F_242 ( struct V_21 * V_15 )
{
return F_243 ( V_15 ) ;
}
int F_244 ( struct V_493 * V_269 , T_6 V_537 )
{
V_269 -> V_15 -> V_551 . V_552 = V_537 ;
return 0 ;
}
void F_245 ( struct V_493 * V_269 )
{
V_269 -> V_15 -> V_551 . V_552 = V_550 ;
}
void F_246 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = F_9 ( V_15 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_42 ;
V_3 -> V_277 = V_3 -> V_40 ;
V_3 -> V_278 = 0 ;
F_67 ( V_5 -> V_209 , V_42 ) ;
V_15 -> V_42 &= ~ V_553 ;
V_15 -> V_48 = 0 ;
F_68 ( V_5 -> V_209 , V_42 ) ;
memset ( ( void * ) V_15 + V_554 , 0 ,
V_555 - V_554 ) ;
V_15 -> V_44 = V_366 ;
V_15 -> V_45 = V_366 ;
V_15 -> V_46 = V_366 ;
}
void F_247 ( struct V_4 * V_5 , struct V_2 * V_3 , int V_38 )
{
int V_25 ;
memset ( ( void * ) V_3 + V_556 , 0 ,
V_557 - V_556 ) ;
V_3 -> V_5 = V_5 ;
V_3 -> V_38 = V_38 ;
V_3 -> V_217 = V_221 ;
V_3 -> V_40 = V_366 ;
for ( V_25 = 0 ; V_25 < V_346 ; V_25 ++ ) {
struct V_14 * V_15 = & V_3 -> V_21 [ V_25 ] ;
V_15 -> V_3 = V_3 ;
V_15 -> V_24 = V_15 - V_3 -> V_21 ;
#ifdef F_248
V_15 -> V_558 = V_559 ;
#endif
F_246 ( V_15 ) ;
}
}
int F_249 ( struct V_2 * V_3 )
{
T_2 V_135 ;
int V_180 ;
V_180 = F_124 ( V_3 , V_359 , & V_3 -> V_560 ) ;
if ( V_180 )
return V_180 ;
V_135 = ( V_3 -> V_560 >> 4 ) & 0xf ;
if ( V_135 )
V_3 -> V_40 &= ( 1 << V_135 ) - 1 ;
F_12 ( V_3 ) ;
V_3 -> V_277 = V_3 -> V_40 ;
return 0 ;
}
struct V_4 * F_250 ( struct V_493 * V_269 )
{
struct V_4 * V_5 ;
F_30 ( L_125 ) ;
V_5 = F_251 ( sizeof( * V_5 ) , V_561 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_210 |= V_562 | V_211 ;
V_5 -> V_209 = & V_269 -> V_209 ;
V_5 -> V_31 = - 1 ;
V_5 -> V_269 = V_269 ;
V_5 -> V_15 = V_269 -> V_15 ;
#if F_252 ( V_563 )
V_5 -> V_564 = 0x00FF ;
#elif F_252 ( V_565 )
V_5 -> V_564 = V_566 | V_567 | V_568 | V_569 | V_570 ;
#else
V_5 -> V_564 = V_566 | V_570 | V_569 ;
#endif
F_253 ( & V_5 -> V_571 ) ;
F_254 ( & V_5 -> V_572 , V_573 ) ;
F_255 ( & V_5 -> V_574 , V_575 ) ;
F_256 ( & V_5 -> V_576 ) ;
F_257 ( & V_5 -> V_577 ) ;
F_258 ( & V_5 -> V_578 ) ;
F_259 ( & V_5 -> V_579 ) ;
V_5 -> V_579 . V_580 = V_581 ;
V_5 -> V_579 . V_582 = ( unsigned long ) V_5 ;
V_5 -> V_33 = V_34 ;
F_247 ( V_5 , & V_5 -> V_3 , 0 ) ;
#ifdef F_260
V_5 -> V_583 . V_584 = 1 ;
V_5 -> V_583 . V_585 = 1 ;
#endif
F_261 ( V_5 ) ;
return V_5 ;
}
static void F_262 ( struct V_21 * V_586 , void * V_587 )
{
struct V_493 * V_269 = F_263 ( V_586 ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_269 -> V_588 ; V_25 ++ ) {
struct V_4 * V_5 = V_269 -> V_589 [ V_25 ] ;
if ( ! V_5 )
continue;
if ( V_5 -> V_289 )
F_264 ( V_5 -> V_289 ) ;
F_265 ( V_5 -> V_11 ) ;
F_265 ( V_5 -> V_12 ) ;
F_265 ( V_5 ) ;
V_269 -> V_589 [ V_25 ] = NULL ;
}
F_266 ( V_586 , NULL ) ;
}
struct V_493 * F_267 ( struct V_21 * V_15 , int V_590 )
{
struct V_493 * V_269 ;
T_5 V_591 ;
int V_25 ;
F_30 ( L_125 ) ;
if ( ! F_268 ( V_15 , NULL , V_561 ) )
return NULL ;
V_591 = sizeof( struct V_493 ) + ( V_590 + 1 ) * sizeof( void * ) ;
V_269 = F_269 ( F_262 , V_591 , V_561 ) ;
if ( ! V_269 )
goto V_260;
F_270 ( V_15 , V_269 ) ;
F_266 ( V_15 , V_269 ) ;
F_271 ( & V_269 -> V_209 ) ;
F_253 ( & V_269 -> V_592 ) ;
V_269 -> V_15 = V_15 ;
V_269 -> V_588 = V_590 ;
for ( V_25 = 0 ; V_25 < V_590 ; V_25 ++ ) {
struct V_4 * V_5 ;
V_5 = F_250 ( V_269 ) ;
if ( ! V_5 )
goto V_260;
V_5 -> V_593 = V_25 ;
V_269 -> V_589 [ V_25 ] = V_5 ;
}
F_272 ( V_15 , NULL ) ;
return V_269 ;
V_260:
F_273 ( V_15 , NULL ) ;
return NULL ;
}
struct V_493 * F_274 ( struct V_21 * V_15 ,
const struct V_594 * const * V_595 ,
int V_588 )
{
const struct V_594 * V_596 ;
struct V_493 * V_269 ;
int V_25 , V_597 ;
V_269 = F_267 ( V_15 , V_588 ) ;
if ( ! V_269 )
return NULL ;
for ( V_25 = 0 , V_597 = 0 , V_596 = NULL ; V_25 < V_269 -> V_588 ; V_25 ++ ) {
struct V_4 * V_5 = V_269 -> V_589 [ V_25 ] ;
if ( V_595 [ V_597 ] )
V_596 = V_595 [ V_597 ++ ] ;
V_5 -> V_44 = V_596 -> V_44 ;
V_5 -> V_45 = V_596 -> V_45 ;
V_5 -> V_46 = V_596 -> V_46 ;
V_5 -> V_42 |= V_596 -> V_42 ;
V_5 -> V_3 . V_42 |= V_596 -> V_598 ;
V_5 -> V_213 = V_596 -> V_599 ;
if ( ! V_269 -> V_213 && ( V_596 -> V_599 != & V_600 ) )
V_269 -> V_213 = V_596 -> V_599 ;
}
return V_269 ;
}
int F_275 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
F_87 ( V_5 -> V_12 ) ;
F_87 ( V_5 -> V_42 & V_601 ) ;
V_3 = F_251 ( sizeof( * V_3 ) , V_561 ) ;
if ( ! V_3 )
return - V_602 ;
F_247 ( V_5 , V_3 , 1 ) ;
V_5 -> V_12 = V_3 ;
return 0 ;
}
static void F_276 ( struct V_21 * V_586 , void * V_587 )
{
struct V_493 * V_269 = F_263 ( V_586 ) ;
int V_25 ;
F_87 ( ! ( V_269 -> V_42 & V_603 ) ) ;
for ( V_25 = 0 ; V_25 < V_269 -> V_588 ; V_25 ++ ) {
struct V_4 * V_5 = V_269 -> V_589 [ V_25 ] ;
if ( V_5 -> V_213 -> V_604 )
V_5 -> V_213 -> V_604 ( V_5 ) ;
}
if ( V_269 -> V_213 -> V_605 )
V_269 -> V_213 -> V_605 ( V_269 ) ;
}
static void F_277 ( struct V_606 * V_213 )
{
static F_278 ( V_209 ) ;
const struct V_606 * V_453 ;
void * * V_607 = ( void * * ) V_213 ;
void * * V_608 = ( void * * ) & V_213 -> V_609 ;
void * * V_610 ;
if ( ! V_213 || ! V_213 -> V_609 )
return;
F_279 ( & V_209 ) ;
for ( V_453 = V_213 -> V_609 ; V_453 ; V_453 = V_453 -> V_609 ) {
void * * V_611 = ( void * * ) V_453 ;
for ( V_610 = V_607 ; V_610 < V_608 ; V_610 ++ , V_611 ++ )
if ( ! * V_610 )
* V_610 = * V_611 ;
}
for ( V_610 = V_607 ; V_610 < V_608 ; V_610 ++ )
if ( F_280 ( * V_610 ) )
* V_610 = NULL ;
V_213 -> V_609 = NULL ;
F_281 ( & V_209 ) ;
}
int F_282 ( struct V_493 * V_269 )
{
int V_612 = 0 ;
void * V_613 = NULL ;
int V_25 , V_180 ;
if ( V_269 -> V_42 & V_603 )
return 0 ;
F_277 ( V_269 -> V_213 ) ;
for ( V_25 = 0 ; V_25 < V_269 -> V_588 ; V_25 ++ ) {
struct V_4 * V_5 = V_269 -> V_589 [ V_25 ] ;
F_277 ( V_5 -> V_213 ) ;
if ( ! V_269 -> V_213 && ! F_283 ( V_5 ) )
V_269 -> V_213 = V_5 -> V_213 ;
if ( V_5 -> V_213 -> V_604 )
V_612 = 1 ;
}
if ( V_269 -> V_213 -> V_605 )
V_612 = 1 ;
if ( V_612 ) {
V_613 = F_269 ( F_276 , 0 , V_561 ) ;
if ( ! V_613 )
return - V_602 ;
}
for ( V_25 = 0 ; V_25 < V_269 -> V_588 ; V_25 ++ ) {
struct V_4 * V_5 = V_269 -> V_589 [ V_25 ] ;
if ( V_5 -> V_213 -> V_614 ) {
V_180 = V_5 -> V_213 -> V_614 ( V_5 ) ;
if ( V_180 ) {
if ( V_180 != - V_259 )
F_284 ( V_269 -> V_15 ,
L_151 ,
V_25 , V_180 ) ;
goto V_260;
}
}
F_285 ( V_5 ) ;
}
if ( V_613 )
F_270 ( V_269 -> V_15 , V_613 ) ;
V_269 -> V_42 |= V_603 ;
return 0 ;
V_260:
while ( -- V_25 >= 0 ) {
struct V_4 * V_5 = V_269 -> V_589 [ V_25 ] ;
if ( V_5 -> V_213 -> V_604 )
V_5 -> V_213 -> V_604 ( V_5 ) ;
}
F_286 ( V_613 ) ;
return V_180 ;
}
void F_287 ( struct V_493 * V_269 , struct V_21 * V_15 ,
unsigned long V_42 , struct V_606 * V_213 )
{
F_271 ( & V_269 -> V_209 ) ;
F_253 ( & V_269 -> V_592 ) ;
V_269 -> V_15 = V_15 ;
V_269 -> V_42 = V_42 ;
V_269 -> V_213 = V_213 ;
}
void F_288 ( struct V_4 * V_5 )
{
struct V_512 * V_513 = & V_5 -> V_3 . V_514 ;
unsigned long V_42 ;
F_67 ( V_5 -> V_209 , V_42 ) ;
V_513 -> V_615 |= V_616 ;
V_513 -> V_467 |= V_528 ;
V_513 -> V_42 |= V_545 | V_542 ;
V_5 -> V_210 &= ~ V_562 ;
V_5 -> V_210 |= V_617 ;
F_216 ( V_5 ) ;
F_68 ( V_5 -> V_209 , V_42 ) ;
}
int F_289 ( struct V_4 * V_5 )
{
int V_180 = 0 ;
if ( V_5 -> V_213 -> V_214 ) {
F_288 ( V_5 ) ;
F_229 ( V_5 ) ;
} else {
F_30 ( L_152 , V_5 -> V_31 ) ;
V_180 = F_135 ( V_5 ) ;
F_30 ( L_153 , V_5 -> V_31 ) ;
}
return V_180 ;
}
static void F_290 ( void * V_582 , T_7 V_618 )
{
struct V_4 * V_5 = V_582 ;
if ( ! ( V_5 -> V_269 -> V_42 & V_440 ) && V_5 -> V_593 != 0 )
F_291 ( V_618 ) ;
( void ) F_289 ( V_5 ) ;
F_291 ( V_618 ) ;
F_292 ( V_5 , 1 ) ;
}
int F_293 ( struct V_493 * V_269 , struct V_619 * V_620 )
{
int V_25 , V_180 ;
if ( ! ( V_269 -> V_42 & V_603 ) ) {
F_284 ( V_269 -> V_15 , L_154 ) ;
F_87 ( 1 ) ;
return - V_117 ;
}
for ( V_25 = V_269 -> V_588 ; V_269 -> V_589 [ V_25 ] ; V_25 ++ )
F_265 ( V_269 -> V_589 [ V_25 ] ) ;
for ( V_25 = 0 ; V_25 < V_269 -> V_588 ; V_25 ++ )
V_269 -> V_589 [ V_25 ] -> V_31 = F_294 ( & V_621 ) ;
for ( V_25 = 0 ; V_25 < V_269 -> V_588 ; V_25 ++ ) {
V_180 = F_295 ( V_269 -> V_15 , V_269 -> V_589 [ V_25 ] ) ;
if ( V_180 ) {
goto V_622;
}
}
V_180 = F_296 ( V_269 , V_620 ) ;
if ( V_180 )
goto V_622;
for ( V_25 = 0 ; V_25 < V_269 -> V_588 ; V_25 ++ ) {
struct V_4 * V_5 = V_269 -> V_589 [ V_25 ] ;
unsigned long V_47 ;
if ( V_5 -> V_33 == V_34 && ( V_5 -> V_42 & V_419 ) )
V_5 -> V_33 = V_281 ;
F_249 ( & V_5 -> V_3 ) ;
if ( V_5 -> V_12 )
F_249 ( V_5 -> V_12 ) ;
V_47 = F_31 ( V_5 -> V_44 , V_5 -> V_45 ,
V_5 -> V_46 ) ;
if ( ! F_283 ( V_5 ) ) {
V_594 ( V_5 , L_155 ,
( V_5 -> V_42 & V_419 ) ? 'S' : 'P' ,
F_36 ( V_47 ) ,
V_5 -> V_3 . V_514 . V_282 ) ;
F_297 ( & V_5 -> V_3 . V_514 ) ;
} else
V_594 ( V_5 , L_156 ) ;
}
for ( V_25 = 0 ; V_25 < V_269 -> V_588 ; V_25 ++ ) {
struct V_4 * V_5 = V_269 -> V_589 [ V_25 ] ;
F_298 ( F_290 , V_5 ) ;
}
return 0 ;
V_622:
while ( -- V_25 >= 0 ) {
F_299 ( V_269 -> V_589 [ V_25 ] ) ;
}
return V_180 ;
}
int F_300 ( struct V_493 * V_269 , int V_623 ,
T_8 V_624 , unsigned long V_625 ,
struct V_619 * V_620 )
{
int V_25 , V_180 ;
V_180 = F_282 ( V_269 ) ;
if ( V_180 )
return V_180 ;
if ( ! V_623 ) {
F_87 ( V_624 ) ;
return F_293 ( V_269 , V_620 ) ;
}
V_180 = F_301 ( V_269 -> V_15 , V_623 , V_624 , V_625 ,
F_302 ( V_269 -> V_15 ) , V_269 ) ;
if ( V_180 )
return V_180 ;
for ( V_25 = 0 ; V_25 < V_269 -> V_588 ; V_25 ++ )
F_303 ( V_269 -> V_589 [ V_25 ] , L_157 , V_623 ) ;
V_180 = F_293 ( V_269 , V_620 ) ;
if ( V_180 )
F_304 ( V_269 -> V_15 , V_623 , V_269 ) ;
return V_180 ;
}
static void F_305 ( struct V_4 * V_5 )
{
unsigned long V_42 ;
if ( ! V_5 -> V_213 -> V_214 )
goto V_626;
F_67 ( V_5 -> V_209 , V_42 ) ;
V_5 -> V_210 |= V_627 ;
F_216 ( V_5 ) ;
F_68 ( V_5 -> V_209 , V_42 ) ;
F_229 ( V_5 ) ;
F_87 ( ! ( V_5 -> V_210 & V_628 ) ) ;
F_306 ( & V_5 -> V_572 ) ;
V_626:
if ( V_5 -> V_11 ) {
int V_25 ;
for ( V_25 = 0 ; V_25 < V_629 ; V_25 ++ )
F_307 ( & V_5 -> V_11 [ V_25 ] ) ;
}
F_299 ( V_5 ) ;
F_308 ( V_5 -> V_289 ) ;
}
void F_309 ( struct V_493 * V_269 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_269 -> V_588 ; V_25 ++ )
F_305 ( V_269 -> V_589 [ V_25 ] ) ;
F_310 ( V_269 ) ;
}
void F_311 ( struct V_630 * V_631 )
{
struct V_21 * V_15 = & V_631 -> V_15 ;
struct V_493 * V_269 = F_263 ( V_15 ) ;
F_309 ( V_269 ) ;
}
int F_312 ( struct V_630 * V_631 , const struct V_632 * V_131 )
{
unsigned long V_357 = 0 ;
switch ( V_131 -> V_633 ) {
case 1 : {
T_2 V_634 = 0 ;
F_313 ( V_631 , V_131 -> V_533 , & V_634 ) ;
V_357 = V_634 ;
break;
}
case 2 : {
T_4 V_635 = 0 ;
F_314 ( V_631 , V_131 -> V_533 , & V_635 ) ;
V_357 = V_635 ;
break;
}
case 4 : {
T_1 V_636 = 0 ;
F_315 ( V_631 , V_131 -> V_533 , & V_636 ) ;
V_357 = V_636 ;
break;
}
default:
return - V_117 ;
}
V_357 &= V_131 -> V_361 ;
return ( V_357 == V_131 -> V_534 ) ? 1 : 0 ;
}
void F_316 ( struct V_630 * V_631 , T_6 V_537 )
{
F_317 ( V_631 ) ;
F_318 ( V_631 ) ;
if ( V_537 . V_543 & V_637 )
F_319 ( V_631 , V_638 ) ;
}
int F_320 ( struct V_630 * V_631 )
{
int V_180 ;
F_319 ( V_631 , V_639 ) ;
F_321 ( V_631 ) ;
V_180 = F_322 ( V_631 ) ;
if ( V_180 ) {
F_284 ( & V_631 -> V_15 ,
L_158 , V_180 ) ;
return V_180 ;
}
F_323 ( V_631 ) ;
return 0 ;
}
int F_324 ( struct V_630 * V_631 , T_6 V_537 )
{
struct V_493 * V_269 = F_263 ( & V_631 -> V_15 ) ;
int V_180 = 0 ;
V_180 = F_244 ( V_269 , V_537 ) ;
if ( V_180 )
return V_180 ;
F_316 ( V_631 , V_537 ) ;
return 0 ;
}
int F_325 ( struct V_630 * V_631 )
{
struct V_493 * V_269 = F_263 ( & V_631 -> V_15 ) ;
int V_180 ;
V_180 = F_320 ( V_631 ) ;
if ( V_180 == 0 )
F_245 ( V_269 ) ;
return V_180 ;
}
static int T_9 F_326 ( char * * V_453 ,
struct V_27 * V_640 ,
const char * * V_251 )
{
static struct V_641 V_642 [] V_643 = {
{ L_159 , . V_33 = V_341 } ,
{ L_160 , . V_33 = V_342 } ,
{ L_161 , . V_33 = V_492 } ,
{ L_162 , . V_33 = V_343 } ,
{ L_163 , . V_33 = V_344 } ,
{ L_164 , . V_33 = V_281 } ,
{ L_165 , . V_39 = 1 } ,
{ L_166 , . V_39 = 2 } ,
{ L_167 , . V_49 = V_287 } ,
{ L_168 , . V_50 = V_287 } ,
{ L_169 , . V_49 = V_266 } ,
{ L_170 , . V_47 = 1 << ( V_120 + 0 ) } ,
{ L_171 , . V_47 = 1 << ( V_120 + 1 ) } ,
{ L_172 , . V_47 = 1 << ( V_120 + 2 ) } ,
{ L_173 , . V_47 = 1 << ( V_120 + 3 ) } ,
{ L_174 , . V_47 = 1 << ( V_120 + 4 ) } ,
{ L_175 , . V_47 = 1 << ( V_120 + 5 ) } ,
{ L_176 , . V_47 = 1 << ( V_120 + 6 ) } ,
{ L_177 , . V_47 = 1 << ( V_122 + 0 ) } ,
{ L_178 , . V_47 = 1 << ( V_122 + 1 ) } ,
{ L_179 , . V_47 = 1 << ( V_122 + 2 ) } ,
{ L_180 , . V_47 = 1 << ( V_122 + 3 ) } ,
{ L_181 , . V_47 = 1 << ( V_122 + 4 ) } ,
{ L_182 , . V_47 = 1 << ( V_124 + 0 ) } ,
{ L_183 , . V_47 = 1 << ( V_124 + 0 ) } ,
{ L_184 , . V_47 = 1 << ( V_124 + 0 ) } ,
{ L_185 , . V_47 = 1 << ( V_124 + 1 ) } ,
{ L_186 , . V_47 = 1 << ( V_124 + 1 ) } ,
{ L_187 , . V_47 = 1 << ( V_124 + 1 ) } ,
{ L_188 , . V_47 = 1 << ( V_124 + 2 ) } ,
{ L_189 , . V_47 = 1 << ( V_124 + 2 ) } ,
{ L_190 , . V_47 = 1 << ( V_124 + 2 ) } ,
{ L_191 , . V_47 = 1 << ( V_124 + 3 ) } ,
{ L_192 , . V_47 = 1 << ( V_124 + 3 ) } ,
{ L_193 , . V_47 = 1 << ( V_124 + 3 ) } ,
{ L_194 , . V_47 = 1 << ( V_124 + 4 ) } ,
{ L_195 , . V_47 = 1 << ( V_124 + 4 ) } ,
{ L_196 , . V_47 = 1 << ( V_124 + 4 ) } ,
{ L_197 , . V_47 = 1 << ( V_124 + 5 ) } ,
{ L_198 , . V_47 = 1 << ( V_124 + 5 ) } ,
{ L_199 , . V_47 = 1 << ( V_124 + 5 ) } ,
{ L_200 , . V_47 = 1 << ( V_124 + 6 ) } ,
{ L_201 , . V_47 = 1 << ( V_124 + 6 ) } ,
{ L_202 , . V_47 = 1 << ( V_124 + 6 ) } ,
{ L_203 , . V_47 = 1 << ( V_124 + 7 ) } ,
{ L_204 , . V_41 = V_644 } ,
{ L_205 , . V_41 = V_645 } ,
{ L_206 , . V_41 = V_644 | V_645 } ,
} ;
char * V_436 = * V_453 , * V_147 = * V_453 ;
char * V_142 , * V_534 , * V_646 ;
const struct V_641 * V_647 = NULL ;
int V_648 = 0 , V_25 ;
while ( * V_147 != '\0' && * V_147 != ',' )
V_147 ++ ;
if ( * V_147 == '\0' )
* V_453 = V_147 ;
else
* V_453 = V_147 + 1 ;
* V_147 = '\0' ;
V_147 = strchr ( V_436 , ':' ) ;
if ( ! V_147 ) {
V_534 = F_327 ( V_436 ) ;
goto V_649;
}
* V_147 = '\0' ;
V_142 = F_327 ( V_436 ) ;
V_534 = F_327 ( V_147 + 1 ) ;
V_147 = strchr ( V_142 , '.' ) ;
if ( V_147 ) {
* V_147 ++ = '\0' ;
V_640 -> V_21 = F_328 ( V_147 , & V_646 , 10 ) ;
if ( V_147 == V_646 || * V_646 != '\0' ) {
* V_251 = L_207 ;
return - V_117 ;
}
}
V_640 -> V_30 = F_328 ( V_142 , & V_646 , 10 ) ;
if ( V_147 == V_646 || * V_646 != '\0' ) {
* V_251 = L_208 ;
return - V_117 ;
}
V_649:
for ( V_25 = 0 ; V_25 < F_37 ( V_642 ) ; V_25 ++ ) {
const struct V_641 * V_650 = & V_642 [ V_25 ] ;
if ( strncasecmp ( V_534 , V_650 -> V_35 , strlen ( V_534 ) ) )
continue;
V_648 ++ ;
V_647 = V_650 ;
if ( strcasecmp ( V_534 , V_650 -> V_35 ) == 0 ) {
V_648 = 1 ;
break;
}
}
if ( ! V_648 ) {
* V_251 = L_209 ;
return - V_117 ;
}
if ( V_648 > 1 ) {
* V_251 = L_210 ;
return - V_117 ;
}
V_640 -> V_32 = * V_647 ;
return 0 ;
}
static void T_9 F_329 ( void )
{
int V_651 = 0 , V_652 = 1 ;
int V_653 = - 1 , V_654 = - 1 ;
char * V_147 , * V_453 , * V_23 ;
for ( V_147 = V_655 ; * V_147 ; V_147 ++ )
if ( * V_147 == ',' )
V_652 ++ ;
V_29 = F_251 ( sizeof( V_29 [ 0 ] ) * V_652 , V_561 ) ;
if ( ! V_29 ) {
F_330 ( V_656 L_211
L_212 ) ;
return;
}
for ( V_453 = V_655 ; * V_453 != '\0' ; V_453 = V_23 ) {
const char * V_251 = L_67 ;
struct V_27 V_657 = { . V_30 = - 1 , . V_21 = - 1 } ;
V_23 = V_453 ;
if ( F_326 ( & V_23 , & V_657 , & V_251 ) ) {
F_330 ( V_656 L_213
L_214 ,
V_453 , V_251 ) ;
continue;
}
if ( V_657 . V_30 == - 1 ) {
V_657 . V_30 = V_653 ;
V_657 . V_21 = V_654 ;
}
V_29 [ V_651 ++ ] = V_657 ;
V_653 = V_657 . V_30 ;
V_654 = V_657 . V_21 ;
}
V_26 = V_651 ;
}
static int T_9 F_331 ( void )
{
int V_180 ;
F_329 () ;
F_332 () ;
V_180 = F_333 () ;
if ( V_180 ) {
F_265 ( V_29 ) ;
return V_180 ;
}
F_334 () ;
V_658 = F_335 () ;
if ( ! V_658 ) {
F_336 () ;
V_180 = - V_602 ;
goto V_260;
}
F_330 ( V_267 L_215 V_659 L_216 ) ;
return 0 ;
V_260:
return V_180 ;
}
static void T_10 F_337 ( void )
{
F_338 ( V_658 ) ;
F_339 () ;
F_336 () ;
F_340 () ;
F_265 ( V_29 ) ;
}
int F_341 ( void )
{
return F_342 ( & V_660 ) ;
}
void F_169 ( struct V_4 * V_5 , unsigned int V_661 )
{
bool V_662 = V_5 && V_5 -> V_269 -> V_663 == V_664 ;
if ( V_662 )
F_77 ( V_5 ) ;
F_175 ( V_661 ) ;
if ( V_662 )
F_80 ( V_5 ) ;
}
T_1 F_343 ( struct V_4 * V_5 , void T_11 * V_533 , T_1 V_361 , T_1 V_534 ,
unsigned long V_449 , unsigned long V_202 )
{
unsigned long V_435 ;
T_1 V_357 ;
V_357 = F_344 ( V_533 ) ;
V_435 = F_164 ( V_437 , V_202 ) ;
while ( ( V_357 & V_361 ) == V_534 && F_168 ( V_437 , V_435 ) ) {
F_169 ( V_5 , V_449 ) ;
V_357 = F_344 ( V_533 ) ;
}
return V_357 ;
}
static unsigned int F_345 ( struct V_192 * V_193 )
{
return V_212 ;
}
static void F_346 ( struct V_4 * V_5 )
{
}
int F_347 ( const struct V_4 * V_5 , const char * V_665 ,
const char * V_666 , ... )
{
struct V_667 V_668 ;
T_12 args ;
int V_669 ;
va_start ( args , V_666 ) ;
V_668 . V_666 = V_666 ;
V_668 . V_670 = & args ;
V_669 = F_330 ( L_217 , V_665 , V_5 -> V_31 , & V_668 ) ;
va_end ( args ) ;
return V_669 ;
}
int F_348 ( const struct V_2 * V_3 , const char * V_665 ,
const char * V_666 , ... )
{
struct V_667 V_668 ;
T_12 args ;
int V_669 ;
va_start ( args , V_666 ) ;
V_668 . V_666 = V_666 ;
V_668 . V_670 = & args ;
if ( F_4 ( V_3 -> V_5 ) || V_3 -> V_5 -> V_12 )
V_669 = F_330 ( L_218 ,
V_665 , V_3 -> V_5 -> V_31 , V_3 -> V_38 , & V_668 ) ;
else
V_669 = F_330 ( L_217 ,
V_665 , V_3 -> V_5 -> V_31 , & V_668 ) ;
va_end ( args ) ;
return V_669 ;
}
int F_349 ( const struct V_14 * V_15 , const char * V_665 ,
const char * V_666 , ... )
{
struct V_667 V_668 ;
T_12 args ;
int V_669 ;
va_start ( args , V_666 ) ;
V_668 . V_666 = V_666 ;
V_668 . V_670 = & args ;
V_669 = F_330 ( L_218 ,
V_665 , V_15 -> V_3 -> V_5 -> V_31 , V_15 -> V_3 -> V_38 + V_15 -> V_24 ,
& V_668 ) ;
va_end ( args ) ;
return V_669 ;
}
void F_350 ( const struct V_21 * V_15 , const char * V_671 )
{
F_351 ( V_267 , V_15 , L_219 , V_671 ) ;
}
