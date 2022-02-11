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
V_70 [ 16 ] = V_68 -> V_83 & 0xff ;
V_70 [ 17 ] = ( V_68 -> V_83 >> 8 ) & 0xff ;
V_70 [ 18 ] = ( V_68 -> V_83 >> 16 ) & 0xff ;
V_70 [ 19 ] = ( V_68 -> V_83 >> 24 ) & 0xff ;
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
T_2 V_84 ;
int V_85 , V_86 , V_87 , V_88 ;
V_86 = ( V_68 -> V_42 & V_89 ) ? 4 : 0 ;
V_87 = ( V_68 -> V_42 & V_90 ) ? 2 : 0 ;
V_88 = ( V_68 -> V_42 & V_91 ) ? 1 : 0 ;
if ( V_15 -> V_42 & V_92 ) {
V_68 -> V_93 = V_94 ;
V_85 = V_15 -> V_95 ? 0 : 8 ;
} else if ( V_87 && ( V_15 -> V_3 -> V_5 -> V_42 & V_96 ) ) {
V_68 -> V_93 = V_94 ;
V_85 = V_15 -> V_95 ? 0 : 8 ;
} else {
V_68 -> V_93 = V_97 ;
V_85 = 16 ;
}
V_84 = V_98 [ V_85 + V_86 + V_87 + V_88 ] ;
if ( V_84 ) {
V_68 -> V_71 = V_84 ;
return 0 ;
}
return - 1 ;
}
T_3 F_23 ( const struct V_67 * V_68 , struct V_14 * V_15 )
{
T_3 V_99 = 0 ;
if ( V_68 -> V_42 & V_100 ) {
if ( V_68 -> V_42 & V_90 ) {
V_99 |= ( T_3 ) V_68 -> V_78 << 40 ;
V_99 |= ( T_3 ) V_68 -> V_77 << 32 ;
V_99 |= ( T_3 ) V_68 -> V_76 << 24 ;
} else
V_99 |= ( V_68 -> V_21 & 0xf ) << 24 ;
V_99 |= V_68 -> V_75 << 16 ;
V_99 |= V_68 -> V_74 << 8 ;
V_99 |= V_68 -> V_73 ;
} else {
T_1 V_101 , V_102 , V_103 ;
V_101 = V_68 -> V_74 | ( V_68 -> V_75 << 8 ) ;
V_102 = V_68 -> V_21 & 0xf ;
V_103 = V_68 -> V_73 ;
if ( ! V_103 ) {
F_24 ( V_15 ,
L_6 ) ;
return V_104 ;
}
V_99 = ( V_101 * V_15 -> V_105 + V_102 ) * V_15 -> V_106 + V_103 - 1 ;
}
return V_99 ;
}
int F_25 ( struct V_67 * V_68 , struct V_14 * V_15 ,
T_3 V_99 , T_1 V_107 , unsigned int V_108 ,
unsigned int V_109 , int V_110 )
{
V_68 -> V_42 |= V_111 | V_112 ;
V_68 -> V_42 |= V_108 ;
if ( F_26 ( V_15 ) && F_27 ( V_109 != V_113 ) ) {
if ( ! F_28 ( V_99 , V_107 ) )
return - V_114 ;
V_68 -> V_93 = V_115 ;
V_68 -> V_42 |= V_100 | V_90 ;
if ( V_68 -> V_42 & V_91 )
V_68 -> V_71 = V_116 ;
else
V_68 -> V_71 = V_117 ;
V_68 -> V_80 = V_109 << 3 ;
V_68 -> V_79 = ( V_107 >> 8 ) & 0xff ;
V_68 -> V_72 = V_107 & 0xff ;
V_68 -> V_78 = ( V_99 >> 40 ) & 0xff ;
V_68 -> V_77 = ( V_99 >> 32 ) & 0xff ;
V_68 -> V_76 = ( V_99 >> 24 ) & 0xff ;
V_68 -> V_75 = ( V_99 >> 16 ) & 0xff ;
V_68 -> V_74 = ( V_99 >> 8 ) & 0xff ;
V_68 -> V_73 = V_99 & 0xff ;
V_68 -> V_21 = V_118 ;
if ( V_68 -> V_42 & V_89 )
V_68 -> V_21 |= 1 << 7 ;
if ( V_15 -> V_42 & V_119 ) {
if ( V_110 == V_120 )
V_68 -> V_81 |= V_121 <<
V_122 ;
}
} else if ( V_15 -> V_42 & V_123 ) {
V_68 -> V_42 |= V_100 ;
if ( F_29 ( V_99 , V_107 ) ) {
V_68 -> V_21 |= ( V_99 >> 24 ) & 0xf ;
} else if ( F_28 ( V_99 , V_107 ) ) {
if ( ! ( V_15 -> V_42 & V_124 ) )
return - V_114 ;
V_68 -> V_42 |= V_90 ;
V_68 -> V_81 = ( V_107 >> 8 ) & 0xff ;
V_68 -> V_78 = ( V_99 >> 40 ) & 0xff ;
V_68 -> V_77 = ( V_99 >> 32 ) & 0xff ;
V_68 -> V_76 = ( V_99 >> 24 ) & 0xff ;
} else
return - V_114 ;
if ( F_5 ( F_22 ( V_68 , V_15 ) < 0 ) )
return - V_125 ;
V_68 -> V_80 = V_107 & 0xff ;
V_68 -> V_75 = ( V_99 >> 16 ) & 0xff ;
V_68 -> V_74 = ( V_99 >> 8 ) & 0xff ;
V_68 -> V_73 = V_99 & 0xff ;
V_68 -> V_21 |= V_118 ;
} else {
T_1 V_103 , V_102 , V_101 , V_126 ;
if ( ! F_29 ( V_99 , V_107 ) )
return - V_114 ;
if ( F_5 ( F_22 ( V_68 , V_15 ) < 0 ) )
return - V_125 ;
V_126 = ( T_1 ) V_99 / V_15 -> V_106 ;
V_101 = V_126 / V_15 -> V_105 ;
V_102 = V_126 % V_15 -> V_105 ;
V_103 = ( T_1 ) V_99 % V_15 -> V_106 + 1 ;
F_30 ( L_7 ,
( T_1 ) V_99 , V_126 , V_101 , V_102 , V_103 ) ;
if ( ( V_101 >> 16 ) || ( V_102 >> 4 ) || ( V_103 >> 8 ) || ( ! V_103 ) )
return - V_114 ;
V_68 -> V_80 = V_107 & 0xff ;
V_68 -> V_73 = V_103 ;
V_68 -> V_74 = V_101 ;
V_68 -> V_75 = V_101 >> 8 ;
V_68 -> V_21 |= V_102 ;
}
return 0 ;
}
unsigned long F_31 ( unsigned long V_44 ,
unsigned long V_45 ,
unsigned long V_46 )
{
return ( ( V_44 << V_127 ) & V_128 ) |
( ( V_45 << V_129 ) & V_130 ) |
( ( V_46 << V_131 ) & V_132 ) ;
}
void F_16 ( unsigned long V_47 , unsigned long * V_44 ,
unsigned long * V_45 , unsigned long * V_46 )
{
if ( V_44 )
* V_44 = ( V_47 & V_128 ) >> V_127 ;
if ( V_45 )
* V_45 = ( V_47 & V_130 ) >> V_129 ;
if ( V_46 )
* V_46 = ( V_47 & V_132 ) >> V_131 ;
}
T_2 F_32 ( unsigned long V_47 )
{
int V_133 = F_33 ( V_47 ) - 1 ;
const struct V_134 * V_135 ;
for ( V_135 = V_136 ; V_135 -> V_137 >= 0 ; V_135 ++ )
if ( V_133 >= V_135 -> V_137 && V_133 < V_135 -> V_137 + V_135 -> V_138 )
return V_135 -> V_139 + V_133 - V_135 -> V_137 ;
return 0xff ;
}
unsigned long F_34 ( T_2 V_140 )
{
const struct V_134 * V_135 ;
for ( V_135 = V_136 ; V_135 -> V_137 >= 0 ; V_135 ++ )
if ( V_140 >= V_135 -> V_139 && V_140 < V_135 -> V_139 + V_135 -> V_138 )
return ( ( 2 << ( V_135 -> V_137 + V_140 - V_135 -> V_139 ) ) - 1 )
& ~ ( ( 1 << V_135 -> V_137 ) - 1 ) ;
return 0 ;
}
int F_35 ( unsigned long V_140 )
{
const struct V_134 * V_135 ;
for ( V_135 = V_136 ; V_135 -> V_137 >= 0 ; V_135 ++ )
if ( V_140 >= V_135 -> V_139 && V_140 < V_135 -> V_139 + V_135 -> V_138 )
return V_135 -> V_137 ;
return - 1 ;
}
const char * F_36 ( unsigned long V_47 )
{
static const char * const V_141 [] = {
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
int V_133 ;
V_133 = F_33 ( V_47 ) - 1 ;
if ( V_133 >= 0 && V_133 < F_37 ( V_141 ) )
return V_141 [ V_133 ] ;
return L_28 ;
}
const char * F_38 ( unsigned int V_142 )
{
static const char * const V_143 [] = {
L_29 ,
L_30 ,
L_31 ,
} ;
if ( V_142 == 0 || ( V_142 - 1 ) >= F_37 ( V_143 ) )
return L_32 ;
return V_143 [ V_142 - 1 ] ;
}
unsigned int F_39 ( const struct V_67 * V_68 )
{
if ( ( V_68 -> V_74 == 0 ) && ( V_68 -> V_75 == 0 ) ) {
F_30 ( L_33 ) ;
return V_144 ;
}
if ( ( V_68 -> V_74 == 0x14 ) && ( V_68 -> V_75 == 0xeb ) ) {
F_30 ( L_34 ) ;
return V_145 ;
}
if ( ( V_68 -> V_74 == 0x69 ) && ( V_68 -> V_75 == 0x96 ) ) {
F_30 ( L_35 ) ;
return V_146 ;
}
if ( ( V_68 -> V_74 == 0x3c ) && ( V_68 -> V_75 == 0xc3 ) ) {
F_30 ( L_36 ) ;
return V_147 ;
}
if ( ( V_68 -> V_74 == 0xcd ) && ( V_68 -> V_75 == 0xab ) ) {
F_30 ( L_37 ) ;
return V_148 ;
}
F_30 ( L_38 ) ;
return V_149 ;
}
void F_40 ( const T_4 * V_150 , unsigned char * V_151 ,
unsigned int V_152 , unsigned int V_153 )
{
unsigned int V_154 ;
F_3 ( V_153 & 1 ) ;
while ( V_153 > 0 ) {
V_154 = V_150 [ V_152 ] >> 8 ;
* V_151 = V_154 ;
V_151 ++ ;
V_154 = V_150 [ V_152 ] & 0xff ;
* V_151 = V_154 ;
V_151 ++ ;
V_152 ++ ;
V_153 -= 2 ;
}
}
void F_41 ( const T_4 * V_150 , unsigned char * V_151 ,
unsigned int V_152 , unsigned int V_153 )
{
unsigned char * V_155 ;
F_40 ( V_150 , V_151 , V_152 , V_153 - 1 ) ;
V_155 = V_151 + F_42 ( V_151 , V_153 - 1 ) ;
while ( V_155 > V_151 && V_155 [ - 1 ] == ' ' )
V_155 -- ;
* V_155 = '\0' ;
}
static T_3 F_43 ( const T_4 * V_150 )
{
if ( F_44 ( V_150 ) ) {
if ( F_45 ( V_150 ) )
return F_46 ( V_150 , V_156 ) ;
else
return F_47 ( V_150 , V_157 ) ;
} else {
if ( F_48 ( V_150 ) )
return V_150 [ V_158 ] * V_150 [ V_159 ] *
V_150 [ V_160 ] ;
else
return V_150 [ V_161 ] * V_150 [ V_162 ] *
V_150 [ V_163 ] ;
}
}
T_3 F_49 ( const struct V_67 * V_68 )
{
T_3 V_106 = 0 ;
V_106 |= ( ( T_3 ) ( V_68 -> V_78 & 0xff ) ) << 40 ;
V_106 |= ( ( T_3 ) ( V_68 -> V_77 & 0xff ) ) << 32 ;
V_106 |= ( ( T_3 ) ( V_68 -> V_76 & 0xff ) ) << 24 ;
V_106 |= ( V_68 -> V_75 & 0xff ) << 16 ;
V_106 |= ( V_68 -> V_74 & 0xff ) << 8 ;
V_106 |= ( V_68 -> V_73 & 0xff ) ;
return V_106 ;
}
T_3 F_50 ( const struct V_67 * V_68 )
{
T_3 V_106 = 0 ;
V_106 |= ( V_68 -> V_21 & 0x0f ) << 24 ;
V_106 |= ( V_68 -> V_75 & 0xff ) << 16 ;
V_106 |= ( V_68 -> V_74 & 0xff ) << 8 ;
V_106 |= ( V_68 -> V_73 & 0xff ) ;
return V_106 ;
}
static int F_51 ( struct V_14 * V_15 , T_3 * V_164 )
{
unsigned int V_165 ;
struct V_67 V_68 ;
int V_87 = F_45 ( V_15 -> V_150 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_42 |= V_112 | V_111 ;
if ( V_87 ) {
V_68 . V_71 = V_166 ;
V_68 . V_42 |= V_90 ;
} else
V_68 . V_71 = V_167 ;
V_68 . V_93 = V_168 ;
V_68 . V_21 |= V_118 ;
V_165 = F_53 ( V_15 , & V_68 , NULL , V_169 , NULL , 0 , 0 ) ;
if ( V_165 ) {
F_24 ( V_15 ,
L_39 ,
V_165 ) ;
if ( V_165 == V_170 && ( V_68 . V_72 & V_171 ) )
return - V_172 ;
return - V_173 ;
}
if ( V_87 )
* V_164 = F_49 ( & V_68 ) + 1 ;
else
* V_164 = F_50 ( & V_68 ) + 1 ;
if ( V_15 -> V_48 & V_174 )
( * V_164 ) -- ;
return 0 ;
}
static int F_54 ( struct V_14 * V_15 , T_3 V_175 )
{
unsigned int V_165 ;
struct V_67 V_68 ;
int V_87 = F_45 ( V_15 -> V_150 ) ;
V_175 -- ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_42 |= V_112 | V_111 ;
if ( V_87 ) {
V_68 . V_71 = V_176 ;
V_68 . V_42 |= V_90 ;
V_68 . V_76 = ( V_175 >> 24 ) & 0xff ;
V_68 . V_77 = ( V_175 >> 32 ) & 0xff ;
V_68 . V_78 = ( V_175 >> 40 ) & 0xff ;
} else {
V_68 . V_71 = V_177 ;
V_68 . V_21 |= ( V_175 >> 24 ) & 0xf ;
}
V_68 . V_93 = V_168 ;
V_68 . V_21 |= V_118 ;
V_68 . V_73 = ( V_175 >> 0 ) & 0xff ;
V_68 . V_74 = ( V_175 >> 8 ) & 0xff ;
V_68 . V_75 = ( V_175 >> 16 ) & 0xff ;
V_165 = F_53 ( V_15 , & V_68 , NULL , V_169 , NULL , 0 , 0 ) ;
if ( V_165 ) {
F_24 ( V_15 ,
L_40 ,
V_165 ) ;
if ( V_165 == V_170 &&
( V_68 . V_72 & ( V_171 | V_178 ) ) )
return - V_172 ;
return - V_173 ;
}
return 0 ;
}
static int F_55 ( struct V_14 * V_15 )
{
struct V_179 * V_180 = & V_15 -> V_3 -> V_181 ;
int V_182 = V_180 -> V_25 . V_42 & V_183 ;
bool V_184 = V_185 || V_15 -> V_42 & V_186 ;
T_3 V_106 = F_43 ( V_15 -> V_150 ) ;
T_3 V_187 ;
int V_188 ;
if ( ( V_15 -> V_110 != V_144 && V_15 -> V_110 != V_148 ) ||
! F_44 ( V_15 -> V_150 ) || ! F_56 ( V_15 -> V_150 ) ||
( V_15 -> V_48 & V_189 ) )
return 0 ;
V_188 = F_51 ( V_15 , & V_187 ) ;
if ( V_188 ) {
if ( V_188 == - V_172 || ! V_184 ) {
F_24 ( V_15 ,
L_41 ) ;
V_15 -> V_48 |= V_189 ;
if ( V_188 == - V_172 )
V_188 = 0 ;
}
return V_188 ;
}
V_15 -> V_190 = V_187 ;
if ( V_187 <= V_106 || ! V_184 ) {
if ( ! V_182 || V_187 == V_106 )
return 0 ;
if ( V_187 > V_106 )
F_57 ( V_15 ,
L_42 ,
( unsigned long long ) V_106 ,
( unsigned long long ) V_187 ) ;
else if ( V_187 < V_106 )
F_24 ( V_15 ,
L_43 ,
( unsigned long long ) V_187 ,
( unsigned long long ) V_106 ) ;
return 0 ;
}
V_188 = F_54 ( V_15 , V_187 ) ;
if ( V_188 == - V_172 ) {
F_24 ( V_15 ,
L_44 ,
( unsigned long long ) V_106 ,
( unsigned long long ) V_187 ) ;
V_15 -> V_48 |= V_189 ;
return 0 ;
} else if ( V_188 )
return V_188 ;
V_188 = F_58 ( V_15 , 0 ) ;
if ( V_188 ) {
F_59 ( V_15 ,
L_45 ) ;
return V_188 ;
}
if ( V_182 ) {
T_3 V_175 = F_43 ( V_15 -> V_150 ) ;
F_57 ( V_15 ,
L_46 ,
( unsigned long long ) V_106 ,
( unsigned long long ) V_175 ,
( unsigned long long ) V_187 ) ;
}
return 0 ;
}
static inline void F_60 ( const T_4 * V_150 )
{
F_30 ( L_47
L_48
L_49
L_50
L_51 ,
V_150 [ 49 ] ,
V_150 [ 53 ] ,
V_150 [ 63 ] ,
V_150 [ 64 ] ,
V_150 [ 75 ] ) ;
F_30 ( L_52
L_53
L_54
L_55
L_56 ,
V_150 [ 80 ] ,
V_150 [ 81 ] ,
V_150 [ 82 ] ,
V_150 [ 83 ] ,
V_150 [ 84 ] ) ;
F_30 ( L_57
L_58 ,
V_150 [ 88 ] ,
V_150 [ 93 ] ) ;
}
unsigned long F_61 ( const T_4 * V_150 )
{
unsigned long V_44 , V_45 , V_46 ;
if ( V_150 [ V_191 ] & ( 1 << 1 ) ) {
V_44 = V_150 [ V_192 ] & 0x03 ;
V_44 <<= 3 ;
V_44 |= 0x7 ;
} else {
T_2 V_7 = ( V_150 [ V_193 ] >> 8 ) & 0xFF ;
if ( V_7 < 5 )
V_44 = ( 2 << V_7 ) - 1 ;
else
V_44 = 1 ;
}
V_45 = V_150 [ V_194 ] & 0x07 ;
if ( F_62 ( V_150 ) ) {
int V_195 = ( V_150 [ V_196 ] >> 0 ) & 0x7 ;
int V_197 = ( V_150 [ V_196 ] >> 3 ) & 0x7 ;
if ( V_195 )
V_44 |= ( 1 << 5 ) ;
if ( V_195 > 1 )
V_44 |= ( 1 << 6 ) ;
if ( V_197 )
V_45 |= ( 1 << 3 ) ;
if ( V_197 > 1 )
V_45 |= ( 1 << 4 ) ;
}
V_46 = 0 ;
if ( V_150 [ V_191 ] & ( 1 << 2 ) )
V_46 = V_150 [ V_198 ] & 0xff ;
return F_31 ( V_44 , V_45 , V_46 ) ;
}
static void F_63 ( struct V_199 * V_200 )
{
struct V_201 * V_202 = V_200 -> V_203 ;
F_64 ( V_202 ) ;
}
unsigned F_65 ( struct V_14 * V_15 ,
struct V_67 * V_68 , const T_2 * V_204 ,
int V_205 , struct V_206 * V_207 ,
unsigned int V_208 , unsigned long V_209 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
T_2 V_71 = V_68 -> V_71 ;
int V_210 = 0 ;
struct V_199 * V_200 ;
unsigned int V_109 , V_211 ;
T_1 V_212 , V_213 ;
int V_214 ;
F_66 ( V_215 ) ;
unsigned long V_42 ;
unsigned int V_165 ;
int V_188 ;
F_67 ( V_5 -> V_216 , V_42 ) ;
if ( V_5 -> V_217 & V_218 ) {
F_68 ( V_5 -> V_216 , V_42 ) ;
return V_219 ;
}
if ( V_5 -> V_220 -> V_221 )
V_109 = V_113 ;
else
V_109 = 0 ;
V_200 = F_69 ( V_5 , V_109 ) ;
V_200 -> V_109 = V_109 ;
V_200 -> V_222 = NULL ;
V_200 -> V_5 = V_5 ;
V_200 -> V_15 = V_15 ;
F_70 ( V_200 ) ;
V_211 = V_3 -> V_223 ;
V_212 = V_3 -> V_224 ;
V_213 = V_5 -> V_225 ;
V_214 = V_5 -> V_226 ;
V_3 -> V_223 = V_227 ;
V_3 -> V_224 = 0 ;
V_5 -> V_225 = 0 ;
V_5 -> V_226 = 0 ;
V_200 -> V_68 = * V_68 ;
if ( V_204 )
memcpy ( V_200 -> V_204 , V_204 , V_228 ) ;
if ( V_68 -> V_93 == V_229 && ( V_15 -> V_42 & V_230 ) &&
V_205 == V_231 )
V_200 -> V_68 . V_72 |= V_232 ;
V_200 -> V_42 |= V_233 ;
V_200 -> V_205 = V_205 ;
if ( V_205 != V_169 ) {
unsigned int V_25 , V_234 = 0 ;
struct V_206 * V_235 ;
F_71 (sgl, sg, n_elem, i)
V_234 += V_235 -> V_236 ;
F_72 ( V_200 , V_207 , V_208 ) ;
V_200 -> V_237 = V_234 ;
}
V_200 -> V_203 = & V_215 ;
V_200 -> V_238 = F_63 ;
F_73 ( V_200 ) ;
F_68 ( V_5 -> V_216 , V_42 ) ;
if ( ! V_209 ) {
if ( V_239 )
V_209 = V_239 * 1000 ;
else {
V_209 = F_74 ( V_15 , V_71 ) ;
V_210 = 1 ;
}
}
if ( V_5 -> V_220 -> V_221 )
F_75 ( V_5 ) ;
V_188 = F_76 ( & V_215 , F_77 ( V_209 ) ) ;
if ( V_5 -> V_220 -> V_221 )
F_78 ( V_5 ) ;
F_79 ( V_5 ) ;
if ( ! V_188 ) {
F_67 ( V_5 -> V_216 , V_42 ) ;
if ( V_200 -> V_42 & V_240 ) {
V_200 -> V_165 |= V_241 ;
if ( V_5 -> V_220 -> V_221 )
F_80 ( V_5 ) ;
else
F_81 ( V_200 ) ;
if ( F_82 ( V_5 ) )
F_24 ( V_15 , L_59 ,
V_71 ) ;
}
F_68 ( V_5 -> V_216 , V_42 ) ;
}
if ( V_5 -> V_220 -> V_242 )
V_5 -> V_220 -> V_242 ( V_200 ) ;
if ( V_200 -> V_42 & V_243 ) {
if ( V_200 -> V_244 . V_71 & ( V_245 | V_246 ) )
V_200 -> V_165 |= V_170 ;
if ( ! V_200 -> V_165 )
V_200 -> V_165 |= V_247 ;
if ( V_200 -> V_165 & ~ V_247 )
V_200 -> V_165 &= ~ V_247 ;
} else if ( V_200 -> V_68 . V_71 == V_248 ) {
V_200 -> V_244 . V_71 |= V_249 ;
}
F_67 ( V_5 -> V_216 , V_42 ) ;
* V_68 = V_200 -> V_244 ;
V_165 = V_200 -> V_165 ;
F_83 ( V_200 ) ;
V_3 -> V_223 = V_211 ;
V_3 -> V_224 = V_212 ;
V_5 -> V_225 = V_213 ;
V_5 -> V_226 = V_214 ;
F_68 ( V_5 -> V_216 , V_42 ) ;
if ( ( V_165 & V_241 ) && V_210 )
F_84 ( V_15 , V_71 ) ;
return V_165 ;
}
unsigned F_53 ( struct V_14 * V_15 ,
struct V_67 * V_68 , const T_2 * V_204 ,
int V_205 , void * V_250 , unsigned int V_234 ,
unsigned long V_209 )
{
struct V_206 * V_251 = NULL , V_235 ;
unsigned int V_208 = 0 ;
if ( V_205 != V_169 ) {
F_85 ( ! V_250 ) ;
F_86 ( & V_235 , V_250 , V_234 ) ;
V_251 = & V_235 ;
V_208 ++ ;
}
return F_65 ( V_15 , V_68 , V_204 , V_205 , V_251 , V_208 ,
V_209 ) ;
}
unsigned int F_87 ( const struct V_14 * V_252 )
{
if ( V_252 -> V_3 -> V_5 -> V_217 & V_253 )
return 0 ;
if ( V_252 -> V_3 -> V_5 -> V_42 & V_254 )
return 0 ;
if ( F_62 ( V_252 -> V_150 )
&& ( V_252 -> V_255 == V_256 || V_252 -> V_255 == V_257 ) )
return 0 ;
if ( V_252 -> V_255 > V_258 )
return 1 ;
if ( F_88 ( V_252 -> V_150 ) )
return 1 ;
return 0 ;
}
static T_1 F_89 ( const struct V_14 * V_252 )
{
if ( V_252 -> V_150 [ V_191 ] & 2 ) {
T_4 V_195 = V_252 -> V_150 [ V_259 ] ;
if ( V_195 ) {
if ( V_195 > 240 )
return 3 << V_127 ;
return 7 << V_127 ;
}
}
return 3 << V_127 ;
}
unsigned int F_90 ( struct V_14 * V_15 ,
struct V_67 * V_68 , T_4 * V_150 )
{
return F_53 ( V_15 , V_68 , NULL , V_231 ,
V_150 , sizeof( V_150 [ 0 ] ) * V_260 , 0 ) ;
}
int F_91 ( struct V_14 * V_15 , unsigned int * V_261 ,
unsigned int V_42 , T_4 * V_150 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
unsigned int V_110 = * V_261 ;
struct V_67 V_68 ;
unsigned int V_165 = 0 ;
const char * V_262 ;
bool V_263 = V_110 == V_147 ;
int V_264 = 1 , V_265 = 0 ;
int V_188 ;
if ( F_92 ( V_5 ) )
F_93 ( V_15 , L_60 , V_266 ) ;
V_267:
F_52 ( V_15 , & V_68 ) ;
switch ( V_110 ) {
case V_147 :
V_110 = V_144 ;
case V_144 :
case V_148 :
V_68 . V_71 = V_268 ;
break;
case V_145 :
V_68 . V_71 = V_269 ;
break;
default:
V_188 = - V_270 ;
V_262 = L_61 ;
goto V_271;
}
V_68 . V_93 = V_94 ;
V_68 . V_42 |= V_111 | V_112 ;
V_68 . V_42 |= V_272 ;
if ( V_5 -> V_220 -> V_273 )
V_165 = V_5 -> V_220 -> V_273 ( V_15 , & V_68 , V_150 ) ;
else
V_165 = F_90 ( V_15 , & V_68 , V_150 ) ;
if ( V_165 ) {
if ( V_165 & V_274 ) {
F_93 ( V_15 , L_62 ) ;
return - V_275 ;
}
if ( V_263 ) {
F_57 ( V_15 ,
L_63 ) ;
* V_261 = V_276 ;
return 0 ;
}
if ( ( V_165 == V_170 ) && ( V_68 . V_72 & V_171 ) ) {
if ( V_264 ) {
V_264 = 0 ;
if ( V_110 == V_144 )
V_110 = V_145 ;
else
V_110 = V_144 ;
goto V_267;
}
F_93 ( V_15 ,
L_64 ) ;
return - V_275 ;
}
V_188 = - V_173 ;
V_262 = L_65 ;
goto V_271;
}
if ( V_15 -> V_48 & V_277 ) {
F_93 ( V_15 , L_66
L_67 ,
V_110 , V_264 , V_265 ) ;
F_94 ( V_278 , L_68 , V_279 ,
16 , 2 , V_150 , V_260 * sizeof( * V_150 ) , true ) ;
}
V_264 = 0 ;
F_95 ( V_150 , V_260 ) ;
V_188 = - V_125 ;
V_262 = L_69 ;
if ( V_110 == V_144 || V_110 == V_148 ) {
if ( ! F_96 ( V_150 ) && ! F_62 ( V_150 ) )
goto V_271;
if ( V_5 -> V_280 -> V_42 & V_281 &&
F_96 ( V_150 ) ) {
F_93 ( V_15 ,
L_70 ) ;
return - V_275 ;
}
} else {
if ( F_96 ( V_150 ) )
goto V_271;
}
if ( ! V_265 && ( V_150 [ 2 ] == 0x37c8 || V_150 [ 2 ] == 0x738c ) ) {
V_265 = 1 ;
V_165 = F_97 ( V_15 , V_282 , 0 ) ;
if ( V_165 && V_150 [ 2 ] != 0x738c ) {
V_188 = - V_173 ;
V_262 = L_71 ;
goto V_271;
}
if ( V_150 [ 2 ] == 0x37c8 )
goto V_267;
}
if ( ( V_42 & V_283 ) &&
( V_110 == V_144 || V_110 == V_148 ) ) {
if ( F_98 ( V_150 ) < 4 || ! F_44 ( V_150 ) ) {
V_165 = F_99 ( V_15 , V_150 [ 3 ] , V_150 [ 6 ] ) ;
if ( V_165 ) {
V_188 = - V_173 ;
V_262 = L_72 ;
goto V_271;
}
V_42 &= ~ V_283 ;
goto V_267;
}
}
* V_261 = V_110 ;
return 0 ;
V_271:
if ( F_82 ( V_5 ) )
F_24 ( V_15 , L_73 ,
V_262 , V_165 ) ;
return V_188 ;
}
unsigned int F_100 ( struct V_14 * V_15 , T_2 log ,
T_2 V_284 , void * V_250 , unsigned int V_106 )
{
unsigned long V_285 = V_15 -> V_3 -> V_5 -> V_42 ;
struct V_67 V_68 ;
unsigned int V_165 ;
bool V_197 = false ;
F_30 ( L_74 , log , V_284 ) ;
if ( V_285 & V_286 )
return V_170 ;
V_267:
F_52 ( V_15 , & V_68 ) ;
if ( V_15 -> V_287 && F_101 ( V_15 -> V_150 ) &&
! ( V_15 -> V_48 & V_288 ) ) {
V_68 . V_71 = V_289 ;
V_68 . V_93 = V_97 ;
V_197 = true ;
} else {
V_68 . V_71 = V_290 ;
V_68 . V_93 = V_94 ;
V_197 = false ;
}
V_68 . V_73 = log ;
V_68 . V_74 = V_284 ;
V_68 . V_80 = V_106 ;
V_68 . V_81 = V_106 >> 8 ;
V_68 . V_42 |= V_111 | V_90 | V_112 ;
V_165 = F_53 ( V_15 , & V_68 , NULL , V_231 ,
V_250 , V_106 * V_291 , 0 ) ;
if ( V_165 && V_197 ) {
V_15 -> V_48 |= V_288 ;
F_24 ( V_15 , L_75 ) ;
goto V_267;
}
F_30 ( L_76 , V_165 ) ;
return V_165 ;
}
static bool F_102 ( struct V_14 * V_15 , T_2 log )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
if ( F_100 ( V_15 , V_292 , 0 , V_5 -> V_293 , 1 ) )
return false ;
return F_103 ( & V_5 -> V_293 [ log * 2 ] ) ? true : false ;
}
static bool F_104 ( struct V_14 * V_15 , T_2 V_284 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
unsigned int V_294 , V_25 ;
if ( ! F_102 ( V_15 , V_295 ) ) {
F_24 ( V_15 , L_77 ) ;
return false ;
}
V_294 = F_100 ( V_15 , V_295 , 0 , V_5 -> V_293 ,
1 ) ;
if ( V_294 ) {
F_57 ( V_15 ,
L_78 ,
V_294 ) ;
return false ;
}
for ( V_25 = 0 ; V_25 < V_5 -> V_293 [ 8 ] ; V_25 ++ ) {
if ( V_5 -> V_293 [ 9 + V_25 ] == V_284 )
return true ;
}
return false ;
}
static int F_105 ( struct V_14 * V_15 )
{
struct V_2 * V_296 = F_9 ( V_15 ) ;
T_1 V_297 , V_298 ;
if ( ! F_106 ( V_296 ) )
return 0 ;
if ( V_15 -> V_48 & V_299 )
V_297 = 1 ;
else
return 0 ;
V_298 = ( 1 << V_297 ) - 1 ;
if ( V_296 -> V_300 <= V_298 )
return 0 ;
V_296 -> V_300 = V_298 ;
if ( V_296 -> V_301 > V_297 ) {
F_57 ( V_15 , L_79 ,
F_38 ( V_297 ) ) ;
return - V_302 ;
}
return 0 ;
}
static inline T_2 F_107 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
if ( F_108 ( V_15 ) & V_303 )
return 0 ;
return ( ( V_5 -> V_33 == V_304 ) && ( ! F_109 ( V_15 -> V_150 ) ) ) ;
}
static void F_110 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
unsigned int V_165 ;
if ( ! F_102 ( V_15 , V_305 ) ) {
F_24 ( V_15 , L_80 ) ;
return;
}
V_165 = F_100 ( V_15 , V_305 ,
0 , V_5 -> V_293 , 1 ) ;
if ( V_165 ) {
F_93 ( V_15 ,
L_81 ,
V_165 ) ;
} else {
T_2 * V_306 = V_15 -> V_307 ;
V_15 -> V_42 |= V_308 ;
memcpy ( V_306 , V_5 -> V_293 , V_309 ) ;
if ( V_15 -> V_48 & V_310 ) {
F_93 ( V_15 , L_82 ) ;
V_306 [ V_311 ] &=
~ V_312 ;
}
}
}
static void F_111 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
unsigned int V_165 ;
if ( ! F_102 ( V_15 , V_313 ) ) {
F_24 ( V_15 ,
L_80 ) ;
return;
}
V_165 = F_100 ( V_15 , V_313 ,
0 , V_5 -> V_293 , 1 ) ;
if ( V_165 ) {
F_93 ( V_15 ,
L_83 ,
V_165 ) ;
} else {
T_2 * V_306 = V_15 -> V_314 ;
memcpy ( V_306 , V_5 -> V_293 , V_315 ) ;
}
}
static void F_112 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
unsigned int V_165 ;
if ( ! ( V_15 -> V_42 & V_316 ) ) {
V_15 -> V_42 &= ~ V_119 ;
return;
}
V_165 = F_100 ( V_15 ,
V_295 ,
V_317 ,
V_5 -> V_293 ,
1 ) ;
if ( V_165 ) {
F_93 ( V_15 ,
L_84 ,
V_165 ) ;
return;
}
if ( V_5 -> V_293 [ V_318 ] & F_113 ( 3 ) ) {
V_15 -> V_42 |= V_119 ;
} else {
V_15 -> V_42 &= ~ V_119 ;
F_93 ( V_15 , L_85 ) ;
}
}
static int F_114 ( struct V_14 * V_15 ,
char * V_319 , T_5 V_320 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
int V_321 = 0 , V_322 = F_115 ( V_15 -> V_150 ) ;
unsigned int V_165 ;
char * V_323 = L_68 ;
if ( ! F_116 ( V_15 -> V_150 ) ) {
V_319 [ 0 ] = '\0' ;
return 0 ;
}
if ( V_15 -> V_48 & V_324 ) {
snprintf ( V_319 , V_320 , L_86 ) ;
return 0 ;
}
if ( V_5 -> V_42 & V_325 ) {
V_321 = F_117 ( V_5 -> V_326 -> V_327 , V_328 - 1 ) ;
V_15 -> V_42 |= V_329 ;
}
if ( ! ( V_15 -> V_48 & V_330 ) &&
( V_5 -> V_42 & V_331 ) &&
F_118 ( V_15 -> V_150 ) ) {
V_165 = F_97 ( V_15 , V_332 ,
V_333 ) ;
if ( V_165 ) {
F_59 ( V_15 ,
L_87 ,
V_165 ) ;
if ( V_165 != V_170 ) {
V_15 -> V_48 |= V_330 ;
return - V_173 ;
}
} else
V_323 = L_88 ;
}
if ( V_321 >= V_322 )
snprintf ( V_319 , V_320 , L_89 , V_322 , V_323 ) ;
else
snprintf ( V_319 , V_320 , L_90 , V_321 ,
V_322 , V_323 ) ;
if ( ( V_5 -> V_42 & V_334 ) ) {
if ( F_119 ( V_15 -> V_150 ) )
F_110 ( V_15 ) ;
if ( F_120 ( V_15 -> V_150 ) )
F_111 ( V_15 ) ;
if ( F_121 ( V_15 -> V_150 ) )
F_112 ( V_15 ) ;
}
return 0 ;
}
static void F_122 ( struct V_14 * V_15 )
{
unsigned int V_165 ;
if ( ! F_123 ( V_15 -> V_150 ) )
return;
if ( F_124 ( V_15 -> V_150 ) )
return;
V_165 = F_97 ( V_15 , V_335 , 0x1 ) ;
if ( V_165 ) {
F_93 ( V_15 ,
L_91 ,
V_165 ) ;
}
}
static void F_125 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
unsigned int V_165 ;
T_2 * V_336 = V_5 -> V_293 ;
V_15 -> V_337 = V_338 ;
V_15 -> V_339 = V_338 ;
V_15 -> V_340 = V_338 ;
if ( V_15 -> V_110 == V_148 )
V_15 -> V_42 |= V_341 ;
else if ( F_126 ( V_15 -> V_150 ) == 0x01 )
V_15 -> V_42 |= V_341 ;
if ( ! ( V_15 -> V_42 & V_341 ) )
return;
if ( ! F_104 ( V_15 , V_342 ) ) {
F_24 ( V_15 ,
L_92 ) ;
return;
}
V_165 = F_100 ( V_15 , V_295 ,
V_342 ,
V_336 , 1 ) ;
if ( ! V_165 ) {
T_3 V_343 , V_344 , V_345 , V_346 ;
V_343 = F_127 ( & V_336 [ 8 ] ) ;
if ( ( V_343 >> 63 ) )
V_15 -> V_347 = ( V_343 & 1 ) ;
V_344 = F_127 ( & V_336 [ 24 ] ) ;
if ( ( V_344 >> 63 ) )
V_15 -> V_337 = ( T_1 ) V_344 ;
V_345 = F_127 ( & V_336 [ 32 ] ) ;
if ( ( V_345 >> 63 ) )
V_15 -> V_339 = ( T_1 ) V_345 ;
V_346 = F_127 ( & V_336 [ 40 ] ) ;
if ( ( V_346 >> 63 ) )
V_15 -> V_340 = ( T_1 ) V_346 ;
}
}
static void F_128 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
T_3 V_348 ;
unsigned int V_294 ;
if ( ! F_129 ( V_15 -> V_150 ) )
return;
if ( ! F_104 ( V_15 , V_349 ) ) {
F_24 ( V_15 ,
L_93 ) ;
return;
}
V_294 = F_100 ( V_15 , V_295 , V_349 ,
V_5 -> V_293 , 1 ) ;
if ( V_294 ) {
F_93 ( V_15 ,
L_94 , V_294 ) ;
return;
}
V_348 = F_127 ( & V_5 -> V_293 [ 40 ] ) ;
if ( ! ( V_348 & ( 1ULL << 63 ) ) ) {
F_93 ( V_15 ,
L_95 ) ;
return;
}
if ( V_348 & ( 1 << 0 ) )
V_15 -> V_42 |= V_350 ;
}
int F_130 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_179 * V_180 = & V_15 -> V_3 -> V_181 ;
int V_182 = V_180 -> V_25 . V_42 & V_183 ;
const T_4 * V_150 = V_15 -> V_150 ;
unsigned long V_47 ;
unsigned int V_165 ;
char V_351 [ 7 ] ;
char V_352 [ V_353 + 1 ] ;
char V_354 [ V_355 + 1 ] ;
int V_188 ;
if ( ! F_8 ( V_15 ) && F_131 ( V_5 ) ) {
F_57 ( V_15 , L_96 , V_266 ) ;
return 0 ;
}
if ( F_132 ( V_5 ) )
F_93 ( V_15 , L_60 , V_266 ) ;
V_15 -> V_48 |= F_108 ( V_15 ) ;
F_18 ( V_15 ) ;
if ( V_15 -> V_48 & V_356 ) {
F_57 ( V_15 , L_97 ) ;
F_133 ( V_15 ) ;
return 0 ;
}
if ( ( ! V_357 || ( V_5 -> V_42 & V_358 ) ) &&
V_15 -> V_110 == V_145 ) {
F_24 ( V_15 , L_98 ,
V_357 ? L_99
: L_100 ) ;
F_133 ( V_15 ) ;
return 0 ;
}
V_188 = F_105 ( V_15 ) ;
if ( V_188 )
return V_188 ;
if ( ( V_15 -> V_48 & V_359 ) &&
( V_150 [ V_360 ] & 0xe ) == 0x2 )
V_15 -> V_48 |= V_361 ;
if ( V_15 -> V_48 & V_361 ) {
F_24 ( V_15 , L_101 ) ;
V_15 -> V_3 -> V_5 -> V_362 = V_363 ;
}
V_188 = F_134 ( V_15 ) ;
if ( V_188 )
return V_188 ;
V_188 = F_55 ( V_15 ) ;
if ( V_188 )
return V_188 ;
if ( F_132 ( V_5 ) )
F_93 ( V_15 ,
L_102
L_103 ,
V_266 ,
V_150 [ 49 ] , V_150 [ 82 ] , V_150 [ 83 ] , V_150 [ 84 ] ,
V_150 [ 85 ] , V_150 [ 86 ] , V_150 [ 87 ] , V_150 [ 88 ] ) ;
V_15 -> V_42 &= ~ V_364 ;
V_15 -> V_164 = 0 ;
V_15 -> V_365 = 0 ;
V_15 -> V_366 = 0 ;
V_15 -> V_367 = 0 ;
V_15 -> V_105 = 0 ;
V_15 -> V_106 = 0 ;
V_15 -> V_95 = 0 ;
V_47 = F_61 ( V_150 ) ;
if ( F_132 ( V_5 ) )
F_60 ( V_150 ) ;
F_41 ( V_15 -> V_150 , V_352 , V_368 ,
sizeof( V_352 ) ) ;
F_41 ( V_15 -> V_150 , V_354 , V_369 ,
sizeof( V_354 ) ) ;
if ( V_15 -> V_110 == V_144 || V_15 -> V_110 == V_148 ) {
if ( F_62 ( V_150 ) ) {
if ( V_150 [ V_370 ] & 1 )
F_24 ( V_15 ,
L_104 ) ;
snprintf ( V_351 , 7 , L_105 ) ;
} else {
snprintf ( V_351 , 7 , L_106 , F_98 ( V_150 ) ) ;
if ( F_135 ( V_150 ) )
F_24 ( V_15 ,
L_104 ) ;
}
V_15 -> V_366 = F_43 ( V_150 ) ;
if ( ( V_15 -> V_150 [ 47 ] >> 8 ) == 0x80 && ( V_15 -> V_150 [ 59 ] & 0x100 ) ) {
unsigned int V_371 = V_15 -> V_150 [ 47 ] & 0xff ;
unsigned int V_372 = V_15 -> V_150 [ 59 ] & 0xff ;
if ( F_136 ( V_371 ) && F_136 ( V_372 ) )
if ( V_372 <= V_371 )
V_15 -> V_95 = V_372 ;
}
if ( F_44 ( V_150 ) ) {
const char * V_373 ;
char V_374 [ 24 ] ;
V_373 = L_107 ;
V_15 -> V_42 |= V_123 ;
if ( F_45 ( V_150 ) ) {
V_15 -> V_42 |= V_124 ;
V_373 = L_108 ;
if ( V_15 -> V_366 >= ( 1UL << 28 ) &&
F_137 ( V_150 ) )
V_15 -> V_42 |= V_375 ;
}
V_188 = F_114 ( V_15 , V_374 , sizeof( V_374 ) ) ;
if ( V_188 )
return V_188 ;
if ( F_138 ( V_5 ) && V_182 ) {
F_57 ( V_15 , L_109 ,
V_351 , V_354 , V_352 ,
F_36 ( V_47 ) ) ;
F_57 ( V_15 ,
L_110 ,
( unsigned long long ) V_15 -> V_366 ,
V_15 -> V_95 , V_373 , V_374 ) ;
}
} else {
V_15 -> V_367 = V_150 [ 1 ] ;
V_15 -> V_105 = V_150 [ 3 ] ;
V_15 -> V_106 = V_150 [ 6 ] ;
if ( F_48 ( V_150 ) ) {
V_15 -> V_367 = V_150 [ 54 ] ;
V_15 -> V_105 = V_150 [ 55 ] ;
V_15 -> V_106 = V_150 [ 56 ] ;
}
if ( F_138 ( V_5 ) && V_182 ) {
F_57 ( V_15 , L_109 ,
V_351 , V_354 , V_352 ,
F_36 ( V_47 ) ) ;
F_57 ( V_15 ,
L_111 ,
( unsigned long long ) V_15 -> V_366 ,
V_15 -> V_95 , V_15 -> V_367 ,
V_15 -> V_105 , V_15 -> V_106 ) ;
}
}
if ( F_139 ( V_15 -> V_150 ) ) {
T_2 * V_376 = V_5 -> V_293 ;
int V_25 , V_377 ;
V_15 -> V_42 |= V_378 ;
V_165 = F_100 ( V_15 ,
V_295 ,
V_317 ,
V_376 ,
1 ) ;
if ( V_165 )
F_93 ( V_15 ,
L_112 ,
V_165 ) ;
else
for ( V_25 = 0 ; V_25 < V_379 ; V_25 ++ ) {
V_377 = V_380 + V_25 ;
V_15 -> V_381 [ V_25 ] = V_376 [ V_377 ] ;
}
}
F_122 ( V_15 ) ;
F_125 ( V_15 ) ;
F_128 ( V_15 ) ;
V_15 -> V_365 = 32 ;
}
else if ( V_15 -> V_110 == V_145 ) {
const char * V_382 = L_68 ;
const char * V_383 = L_68 ;
const char * V_384 = L_68 ;
T_1 V_385 ;
V_188 = F_140 ( V_150 ) ;
if ( ( V_188 < 12 ) || ( V_188 > V_228 ) ) {
if ( F_82 ( V_5 ) )
F_24 ( V_15 , L_113 ) ;
V_188 = - V_125 ;
goto V_386;
}
V_15 -> V_365 = ( unsigned int ) V_188 ;
if ( V_387 &&
( V_5 -> V_42 & V_388 ) && F_141 ( V_150 ) &&
( ! F_4 ( V_5 ) ||
F_142 ( & V_5 -> V_3 , V_389 , & V_385 ) == 0 ) ) {
V_165 = F_97 ( V_15 ,
V_332 , V_390 ) ;
if ( V_165 )
F_59 ( V_15 ,
L_114 ,
V_165 ) ;
else {
V_15 -> V_42 |= V_391 ;
V_383 = L_115 ;
}
}
if ( F_143 ( V_15 -> V_150 ) ) {
V_15 -> V_42 |= V_392 ;
V_382 = L_116 ;
}
if ( V_393 || ( V_15 -> V_48 & V_394 ) || F_144 ( V_15 -> V_150 ) ) {
V_15 -> V_42 |= V_230 ;
V_384 = L_117 ;
}
if ( F_145 ( V_15 -> V_150 ) ) {
V_15 -> V_42 |= V_395 ;
F_146 ( V_15 ) ;
}
if ( F_138 ( V_5 ) && V_182 )
F_57 ( V_15 ,
L_118 ,
V_354 , V_352 ,
F_36 ( V_47 ) ,
V_382 , V_383 ,
V_384 ) ;
}
V_15 -> V_164 = V_396 ;
if ( V_15 -> V_42 & V_124 )
V_15 -> V_164 = V_397 ;
if ( F_107 ( V_15 ) ) {
if ( F_138 ( V_5 ) && V_182 )
F_57 ( V_15 , L_119 ) ;
V_15 -> V_46 &= V_398 ;
V_15 -> V_164 = V_396 ;
}
if ( ( V_15 -> V_110 == V_145 ) &&
( F_147 ( V_150 ) == V_399 ) ) {
V_15 -> V_164 = V_400 ;
V_15 -> V_48 |= V_401 ;
}
if ( V_15 -> V_48 & V_402 )
V_15 -> V_164 = F_148 (unsigned int, ATA_MAX_SECTORS_128,
dev->max_sectors) ;
if ( V_15 -> V_48 & V_403 )
V_15 -> V_164 = F_148 (unsigned int, ATA_MAX_SECTORS_1024,
dev->max_sectors) ;
if ( V_15 -> V_48 & V_404 )
V_15 -> V_164 = V_397 ;
if ( V_5 -> V_220 -> V_405 )
V_5 -> V_220 -> V_405 ( V_15 ) ;
if ( V_15 -> V_48 & V_406 ) {
if ( V_182 ) {
F_24 ( V_15 ,
L_120 ) ;
F_24 ( V_15 ,
L_121 ) ;
}
}
if ( ( V_15 -> V_48 & V_407 ) && V_182 ) {
F_24 ( V_15 , L_122 ) ;
F_24 ( V_15 , L_123 ) ;
}
return 0 ;
V_386:
if ( F_132 ( V_5 ) )
F_93 ( V_15 , L_124 , V_266 ) ;
return V_188 ;
}
int F_149 ( struct V_4 * V_5 )
{
return V_408 ;
}
int F_150 ( struct V_4 * V_5 )
{
return V_409 ;
}
int F_151 ( struct V_4 * V_5 )
{
return V_410 ;
}
int F_152 ( struct V_4 * V_5 )
{
return V_411 ;
}
int F_153 ( struct V_4 * V_5 )
{
return V_304 ;
}
int F_154 ( struct V_4 * V_5 )
{
unsigned int V_412 [ V_413 ] ;
int V_414 [ V_413 ] ;
int V_188 ;
struct V_14 * V_15 ;
F_155 (dev, &ap->link, ALL)
V_414 [ V_15 -> V_24 ] = V_415 ;
V_267:
F_155 (dev, &ap->link, ALL) {
V_15 -> V_255 = V_416 ;
V_15 -> V_287 = 0xff ;
if ( V_5 -> V_220 -> V_417 )
V_5 -> V_220 -> V_417 ( V_5 , V_15 ) ;
}
V_5 -> V_220 -> V_418 ( V_5 ) ;
F_155 (dev, &ap->link, ALL) {
if ( V_15 -> V_110 != V_149 )
V_412 [ V_15 -> V_24 ] = V_15 -> V_110 ;
else
V_412 [ V_15 -> V_24 ] = V_419 ;
V_15 -> V_110 = V_149 ;
}
F_155 (dev, &ap->link, ALL_REVERSE) {
if ( V_414 [ V_15 -> V_24 ] )
V_15 -> V_110 = V_412 [ V_15 -> V_24 ] ;
if ( ! F_8 ( V_15 ) )
continue;
V_188 = F_91 ( V_15 , & V_15 -> V_110 , V_283 ,
V_15 -> V_150 ) ;
if ( V_188 )
goto V_420;
}
if ( V_5 -> V_220 -> V_421 )
V_5 -> V_33 = V_5 -> V_220 -> V_421 ( V_5 ) ;
F_155 (dev, &ap->link, ENABLED)
if ( F_109 ( V_15 -> V_150 ) )
V_5 -> V_33 = V_304 ;
F_155 (dev, &ap->link, ENABLED) {
V_5 -> V_3 . V_181 . V_25 . V_42 |= V_183 ;
V_188 = F_130 ( V_15 ) ;
V_5 -> V_3 . V_181 . V_25 . V_42 &= ~ V_183 ;
if ( V_188 )
goto V_420;
}
V_188 = F_156 ( & V_5 -> V_3 , & V_15 ) ;
if ( V_188 )
goto V_420;
F_155 (dev, &ap->link, ENABLED)
return 0 ;
return - V_270 ;
V_420:
V_414 [ V_15 -> V_24 ] -- ;
switch ( V_188 ) {
case - V_125 :
V_414 [ V_15 -> V_24 ] = 0 ;
break;
case - V_270 :
V_414 [ V_15 -> V_24 ] = F_117 ( V_414 [ V_15 -> V_24 ] , 1 ) ;
case - V_173 :
if ( V_414 [ V_15 -> V_24 ] == 1 ) {
F_157 ( & V_5 -> V_3 , 0 ) ;
F_158 ( V_15 , V_422 ) ;
}
}
if ( ! V_414 [ V_15 -> V_24 ] )
F_133 ( V_15 ) ;
goto V_267;
}
static void F_159 ( struct V_2 * V_3 )
{
T_1 V_1 , V_423 , V_424 ;
if ( F_142 ( V_3 , V_425 , & V_1 ) )
return;
F_142 ( V_3 , V_426 , & V_423 ) ;
if ( F_160 ( V_3 ) ) {
V_424 = ( V_1 >> 4 ) & 0xf ;
F_161 ( V_3 , L_125 ,
F_38 ( V_424 ) , V_1 , V_423 ) ;
} else {
F_161 ( V_3 , L_126 ,
V_1 , V_423 ) ;
}
}
struct V_14 * F_162 ( struct V_14 * V_252 )
{
struct V_2 * V_3 = V_252 -> V_3 ;
struct V_14 * V_427 = & V_3 -> V_21 [ 1 - V_252 -> V_24 ] ;
if ( ! F_8 ( V_427 ) )
return NULL ;
return V_427 ;
}
int F_157 ( struct V_2 * V_3 , T_1 V_39 )
{
T_1 V_1 , V_142 , V_428 ;
int V_188 , V_429 ;
if ( ! F_106 ( V_3 ) )
return - V_430 ;
V_188 = F_142 ( V_3 , V_425 , & V_1 ) ;
if ( V_188 == 0 && F_1 ( V_1 ) )
V_142 = ( V_1 >> 4 ) & 0xf ;
else
V_142 = V_3 -> V_301 ;
V_428 = V_3 -> V_300 ;
if ( V_428 <= 1 )
return - V_125 ;
V_429 = F_33 ( V_428 ) - 1 ;
V_428 &= ~ ( 1 << V_429 ) ;
if ( V_142 > 1 )
V_428 &= ( 1 << ( V_142 - 1 ) ) - 1 ;
else
V_428 &= 1 ;
if ( ! V_428 )
return - V_125 ;
if ( V_39 ) {
if ( V_428 & ( ( 1 << V_39 ) - 1 ) )
V_428 &= ( 1 << V_39 ) - 1 ;
else {
V_429 = F_163 ( V_428 ) - 1 ;
V_428 = 1 << V_429 ;
}
}
V_3 -> V_300 = V_428 ;
F_164 ( V_3 , L_127 ,
F_38 ( F_33 ( V_428 ) ) ) ;
return 0 ;
}
static int F_165 ( struct V_2 * V_3 , T_1 * V_423 )
{
struct V_2 * V_431 = & V_3 -> V_5 -> V_3 ;
T_1 V_432 , V_297 , V_142 ;
V_432 = V_3 -> V_300 ;
if ( ! F_13 ( V_3 ) && V_431 -> V_301 )
V_432 &= ( 1 << V_431 -> V_301 ) - 1 ;
if ( V_432 == V_433 )
V_297 = 0 ;
else
V_297 = F_33 ( V_432 ) ;
V_142 = ( * V_423 >> 4 ) & 0xf ;
* V_423 = ( * V_423 & ~ 0xf0 ) | ( ( V_297 & 0xf ) << 4 ) ;
return V_142 != V_297 ;
}
static int F_166 ( struct V_2 * V_3 )
{
T_1 V_423 ;
if ( F_142 ( V_3 , V_426 , & V_423 ) )
return 1 ;
return F_165 ( V_3 , & V_423 ) ;
}
int F_167 ( struct V_2 * V_3 )
{
T_1 V_423 ;
int V_188 ;
if ( ( V_188 = F_142 ( V_3 , V_426 , & V_423 ) ) )
return V_188 ;
if ( ! F_165 ( V_3 , & V_423 ) )
return 0 ;
if ( ( V_188 = F_168 ( V_3 , V_426 , V_423 ) ) )
return V_188 ;
return 1 ;
}
static void F_169 ( const struct V_434 * V_435 , struct V_434 * V_436 , int V_437 , int V_438 )
{
V_436 -> V_439 = F_170 ( V_435 -> V_439 , V_437 ) ;
V_436 -> V_440 = F_170 ( V_435 -> V_440 , V_437 ) ;
V_436 -> V_441 = F_170 ( V_435 -> V_441 , V_437 ) ;
V_436 -> V_442 = F_170 ( V_435 -> V_442 , V_437 ) ;
V_436 -> V_443 = F_170 ( V_435 -> V_443 , V_437 ) ;
V_436 -> V_444 = F_170 ( V_435 -> V_444 , V_437 ) ;
V_436 -> V_445 = F_170 ( V_435 -> V_445 , V_437 ) ;
V_436 -> V_446 = F_170 ( V_435 -> V_446 , V_437 ) ;
V_436 -> V_447 = F_170 ( V_435 -> V_447 , V_438 ) ;
}
void F_171 ( const struct V_434 * V_448 , const struct V_434 * V_449 ,
struct V_434 * V_450 , unsigned int V_451 )
{
if ( V_451 & V_452 ) V_450 -> V_439 = V_371 ( V_448 -> V_439 , V_449 -> V_439 ) ;
if ( V_451 & V_453 ) V_450 -> V_440 = V_371 ( V_448 -> V_440 , V_449 -> V_440 ) ;
if ( V_451 & V_454 ) V_450 -> V_441 = V_371 ( V_448 -> V_441 , V_449 -> V_441 ) ;
if ( V_451 & V_455 ) V_450 -> V_442 = V_371 ( V_448 -> V_442 , V_449 -> V_442 ) ;
if ( V_451 & V_456 ) V_450 -> V_443 = V_371 ( V_448 -> V_443 , V_449 -> V_443 ) ;
if ( V_451 & V_457 ) V_450 -> V_444 = V_371 ( V_448 -> V_444 , V_449 -> V_444 ) ;
if ( V_451 & V_458 ) V_450 -> V_445 = V_371 ( V_448 -> V_445 , V_449 -> V_445 ) ;
if ( V_451 & V_459 ) V_450 -> V_446 = V_371 ( V_448 -> V_446 , V_449 -> V_446 ) ;
if ( V_451 & V_460 ) V_450 -> V_447 = V_371 ( V_448 -> V_447 , V_449 -> V_447 ) ;
}
const struct V_434 * F_172 ( T_2 V_140 )
{
const struct V_434 * V_435 = V_434 ;
while ( V_140 > V_435 -> V_7 )
V_435 ++ ;
if ( V_140 == V_435 -> V_7 )
return V_435 ;
F_173 ( true , L_128 ,
V_266 , V_140 ) ;
return NULL ;
}
int F_174 ( struct V_14 * V_252 , unsigned short V_461 ,
struct V_434 * V_435 , int V_437 , int V_438 )
{
const T_4 * V_150 = V_252 -> V_150 ;
const struct V_434 * V_151 ;
struct V_434 V_155 ;
if ( ! ( V_151 = F_172 ( V_461 ) ) )
return - V_125 ;
memcpy ( V_435 , V_151 , sizeof( * V_151 ) ) ;
if ( V_150 [ V_191 ] & 2 ) {
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
if ( V_461 >= V_416 && V_461 < V_462 ) {
if ( V_461 <= V_258 )
V_155 . V_446 = V_155 . V_442 = V_150 [ V_259 ] ;
else if ( ( V_461 <= V_463 ) ||
( V_461 == V_256 && ! F_62 ( V_150 ) ) )
V_155 . V_446 = V_155 . V_442 = V_150 [ V_464 ] ;
} else if ( V_461 >= V_465 && V_461 <= V_466 )
V_155 . V_446 = V_150 [ V_467 ] ;
F_171 ( & V_155 , V_435 , V_435 , V_459 | V_455 ) ;
}
F_169 ( V_435 , V_435 , V_437 , V_438 ) ;
if ( V_461 > V_257 ) {
F_174 ( V_252 , V_252 -> V_255 , & V_155 , V_437 , V_438 ) ;
F_171 ( & V_155 , V_435 , V_435 , V_468 ) ;
}
if ( V_435 -> V_440 + V_435 -> V_441 < V_435 -> V_442 ) {
V_435 -> V_440 += ( V_435 -> V_442 - ( V_435 -> V_440 + V_435 -> V_441 ) ) / 2 ;
V_435 -> V_441 = V_435 -> V_442 - V_435 -> V_440 ;
}
if ( V_435 -> V_443 + V_435 -> V_444 < V_435 -> V_446 ) {
V_435 -> V_443 += ( V_435 -> V_446 - ( V_435 -> V_443 + V_435 -> V_444 ) ) / 2 ;
V_435 -> V_444 = V_435 -> V_446 - V_435 -> V_443 ;
}
if ( V_435 -> V_443 + V_435 -> V_444 > V_435 -> V_446 )
V_435 -> V_446 = V_435 -> V_443 + V_435 -> V_444 ;
return 0 ;
}
T_2 F_175 ( unsigned int V_469 , int V_446 )
{
T_2 V_470 = 0xff , V_471 = 0xff ;
const struct V_134 * V_135 ;
const struct V_434 * V_435 ;
for ( V_135 = V_136 ; V_135 -> V_137 >= 0 ; V_135 ++ )
if ( V_135 -> V_137 == V_469 )
V_470 = V_135 -> V_139 ;
for ( V_435 = F_172 ( V_470 ) ;
V_435 && F_35 ( V_435 -> V_7 ) == V_469 ; V_435 ++ ) {
unsigned short V_472 ;
switch ( V_469 ) {
case V_127 :
case V_129 :
V_472 = V_435 -> V_446 ;
break;
case V_131 :
V_472 = V_435 -> V_447 ;
break;
default:
return 0xff ;
}
if ( V_446 > V_472 )
break;
V_471 = V_435 -> V_7 ;
}
return V_471 ;
}
int F_158 ( struct V_14 * V_15 , unsigned int V_473 )
{
char V_250 [ 32 ] ;
unsigned long V_474 , V_47 ;
unsigned long V_44 , V_45 , V_46 ;
int V_475 , V_133 ;
V_475 = ! ! ( V_473 & V_476 ) ;
V_473 &= ~ V_476 ;
V_47 = V_474 = F_31 ( V_15 -> V_44 ,
V_15 -> V_45 ,
V_15 -> V_46 ) ;
F_16 ( V_47 , & V_44 , & V_45 , & V_46 ) ;
switch ( V_473 ) {
case V_422 :
V_133 = F_33 ( V_44 ) - 1 ;
V_44 &= ~ ( 1 << V_133 ) ;
break;
case V_477 :
if ( V_46 ) {
V_133 = F_33 ( V_46 ) - 1 ;
V_46 &= ~ ( 1 << V_133 ) ;
if ( ! V_46 )
return - V_275 ;
} else if ( V_45 ) {
V_133 = F_33 ( V_45 ) - 1 ;
V_45 &= ~ ( 1 << V_133 ) ;
if ( ! V_45 )
return - V_275 ;
}
break;
case V_478 :
V_46 &= V_479 ;
break;
case V_480 :
V_44 &= 1 ;
case V_481 :
V_45 = 0 ;
V_46 = 0 ;
break;
default:
F_176 () ;
}
V_47 &= F_31 ( V_44 , V_45 , V_46 ) ;
if ( ! ( V_47 & V_128 ) || V_47 == V_474 )
return - V_275 ;
if ( ! V_475 ) {
if ( V_47 & ( V_130 | V_132 ) )
snprintf ( V_250 , sizeof( V_250 ) , L_129 ,
F_36 ( V_47 ) ,
F_36 ( V_47 & V_128 ) ) ;
else
snprintf ( V_250 , sizeof( V_250 ) , L_130 ,
F_36 ( V_47 ) ) ;
F_24 ( V_15 , L_131 , V_250 ) ;
}
F_16 ( V_47 , & V_15 -> V_44 , & V_15 -> V_45 ,
& V_15 -> V_46 ) ;
return 0 ;
}
static int F_177 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_179 * V_180 = & V_15 -> V_3 -> V_181 ;
const bool V_482 = V_15 -> V_48 & V_483 ;
const char * V_484 = L_68 ;
int V_485 = 0 ;
unsigned int V_165 = 0 ;
int V_188 ;
V_15 -> V_42 &= ~ V_92 ;
if ( V_15 -> V_469 == V_127 )
V_15 -> V_42 |= V_92 ;
if ( V_482 && V_5 -> V_42 & V_486 && F_109 ( V_15 -> V_150 ) )
V_484 = L_132 ;
else {
if ( V_482 )
F_24 ( V_15 ,
L_133
L_134 ) ;
V_165 = F_178 ( V_15 ) ;
}
if ( V_165 & ~ V_170 )
goto V_420;
V_180 -> V_25 . V_42 |= V_487 ;
V_188 = F_179 ( V_15 , V_149 , 0 ) ;
V_180 -> V_25 . V_42 &= ~ V_487 ;
if ( V_188 )
return V_188 ;
if ( V_15 -> V_469 == V_127 ) {
if ( F_62 ( V_15 -> V_150 ) )
V_485 = 1 ;
if ( F_98 ( V_15 -> V_150 ) == 0 &&
V_15 -> V_255 <= V_258 )
V_485 = 1 ;
if ( ! F_88 ( V_15 -> V_150 ) && V_15 -> V_255 <= V_258 )
V_485 = 1 ;
}
if ( V_15 -> V_469 == V_129 &&
V_15 -> V_287 == V_465 &&
( V_15 -> V_150 [ 63 ] >> 8 ) & 1 )
V_485 = 1 ;
if ( V_15 -> V_140 == F_32 ( F_61 ( V_15 -> V_150 ) ) )
V_485 = 1 ;
if ( V_165 & V_170 ) {
if ( ! V_485 )
goto V_420;
else
V_484 = L_135 ;
}
F_30 ( L_136 ,
V_15 -> V_469 , ( int ) V_15 -> V_140 ) ;
F_57 ( V_15 , L_137 ,
F_36 ( F_34 ( V_15 -> V_140 ) ) ,
V_484 ) ;
return 0 ;
V_420:
F_59 ( V_15 , L_138 , V_165 ) ;
return - V_173 ;
}
int F_180 ( struct V_2 * V_3 , struct V_14 * * V_488 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_14 * V_15 ;
int V_188 = 0 , V_489 = 0 , V_490 = 0 ;
F_155 (dev, link, ENABLED) {
unsigned long V_44 , V_491 ;
unsigned int V_492 ;
V_492 = V_493 ;
if ( V_15 -> V_110 == V_145 )
V_492 = V_494 ;
else if ( F_62 ( V_15 -> V_150 ) )
V_492 = V_495 ;
F_181 ( V_15 ) ;
F_15 ( V_15 ) ;
V_44 = F_31 ( V_15 -> V_44 , 0 , 0 ) ;
if ( V_496 & V_492 )
V_491 = F_31 ( 0 , V_15 -> V_45 ,
V_15 -> V_46 ) ;
else
V_491 = 0 ;
V_15 -> V_255 = F_32 ( V_44 ) ;
V_15 -> V_287 = F_32 ( V_491 ) ;
V_490 = 1 ;
if ( F_182 ( V_15 ) )
V_489 = 1 ;
}
if ( ! V_490 )
goto V_497;
F_155 (dev, link, ENABLED) {
if ( V_15 -> V_255 == 0xff ) {
F_24 ( V_15 , L_139 ) ;
V_188 = - V_125 ;
goto V_497;
}
V_15 -> V_140 = V_15 -> V_255 ;
V_15 -> V_469 = V_127 ;
if ( V_5 -> V_220 -> V_417 )
V_5 -> V_220 -> V_417 ( V_5 , V_15 ) ;
}
F_155 (dev, link, ENABLED) {
if ( ! F_182 ( V_15 ) )
continue;
V_15 -> V_140 = V_15 -> V_287 ;
V_15 -> V_469 = F_35 ( V_15 -> V_287 ) ;
if ( V_5 -> V_220 -> V_498 )
V_5 -> V_220 -> V_498 ( V_5 , V_15 ) ;
}
F_155 (dev, link, ENABLED) {
V_188 = F_177 ( V_15 ) ;
if ( V_188 )
goto V_497;
}
if ( V_489 && ( V_5 -> V_280 -> V_42 & V_499 ) )
V_5 -> V_280 -> V_500 = V_5 ;
V_497:
if ( V_188 )
* V_488 = V_15 ;
return V_188 ;
}
int F_183 ( struct V_2 * V_3 , unsigned long V_501 ,
int (* F_184)( struct V_2 * V_3 ) )
{
unsigned long V_502 = V_503 ;
unsigned long V_504 ;
int V_505 = 0 ;
if ( V_3 -> V_5 -> V_280 -> V_42 & V_506 )
V_504 = F_185 ( V_502 , V_507 ) ;
else
V_504 = F_185 ( V_502 , V_508 ) ;
F_85 ( V_3 == V_3 -> V_5 -> V_12 ) ;
if ( F_186 ( V_504 , V_501 ) )
V_504 = V_501 ;
while ( 1 ) {
unsigned long V_509 = V_503 ;
int V_510 , V_424 ;
V_510 = V_424 = F_184 ( V_3 ) ;
if ( V_510 > 0 )
return 0 ;
if ( V_510 == - V_270 ) {
if ( F_187 ( V_3 ) )
V_510 = 0 ;
else if ( ( V_3 -> V_5 -> V_42 & V_486 ) &&
! F_188 ( V_3 ) &&
F_189 ( V_509 , V_504 ) )
V_510 = 0 ;
}
if ( V_510 )
return V_510 ;
if ( F_186 ( V_509 , V_501 ) )
return - V_511 ;
if ( ! V_505 && F_186 ( V_509 , V_502 + 5 * V_512 ) &&
( V_501 - V_509 > 3 * V_512 ) ) {
F_164 ( V_3 ,
L_140
L_141 , V_424 ) ;
V_505 = 1 ;
}
F_190 ( V_3 -> V_5 , 50 ) ;
}
}
int F_191 ( struct V_2 * V_3 , unsigned long V_501 ,
int (* F_184)( struct V_2 * V_3 ) )
{
F_190 ( V_3 -> V_5 , V_513 ) ;
return F_183 ( V_3 , V_501 , F_184 ) ;
}
int F_192 ( struct V_2 * V_3 , const unsigned long * V_514 ,
unsigned long V_501 )
{
unsigned long V_515 = V_514 [ 0 ] ;
unsigned long V_516 = V_514 [ 1 ] ;
unsigned long V_517 , V_435 ;
T_1 V_518 , V_519 ;
int V_188 ;
V_435 = F_185 ( V_503 , V_514 [ 2 ] ) ;
if ( F_189 ( V_435 , V_501 ) )
V_501 = V_435 ;
if ( ( V_188 = F_142 ( V_3 , V_425 , & V_519 ) ) )
return V_188 ;
V_519 &= 0xf ;
V_518 = V_519 ;
V_517 = V_503 ;
while ( 1 ) {
F_190 ( V_3 -> V_5 , V_515 ) ;
if ( ( V_188 = F_142 ( V_3 , V_425 , & V_519 ) ) )
return V_188 ;
V_519 &= 0xf ;
if ( V_519 == V_518 ) {
if ( V_519 == 1 && F_189 ( V_503 , V_501 ) )
continue;
if ( F_186 ( V_503 ,
F_185 ( V_517 , V_516 ) ) )
return 0 ;
continue;
}
V_518 = V_519 ;
V_517 = V_503 ;
if ( F_186 ( V_503 , V_501 ) )
return - V_520 ;
}
}
int F_193 ( struct V_2 * V_3 , const unsigned long * V_514 ,
unsigned long V_501 )
{
int V_414 = V_521 ;
T_1 V_423 , V_522 ;
int V_188 ;
if ( ( V_188 = F_142 ( V_3 , V_426 , & V_423 ) ) )
return V_188 ;
do {
V_423 = ( V_423 & 0x0f0 ) | 0x300 ;
if ( ( V_188 = F_168 ( V_3 , V_426 , V_423 ) ) )
return V_188 ;
if ( ! ( V_3 -> V_42 & V_523 ) )
F_190 ( V_3 -> V_5 , 200 ) ;
if ( ( V_188 = F_142 ( V_3 , V_426 , & V_423 ) ) )
return V_188 ;
} while ( ( V_423 & 0xf0f ) != 0x300 && -- V_414 );
if ( ( V_423 & 0xf0f ) != 0x300 ) {
F_164 ( V_3 , L_142 ,
V_423 ) ;
return 0 ;
}
if ( V_414 < V_521 )
F_164 ( V_3 , L_143 ,
V_521 - V_414 ) ;
if ( ( V_188 = F_192 ( V_3 , V_514 , V_501 ) ) )
return V_188 ;
if ( ! ( V_188 = F_142 ( V_3 , V_524 , & V_522 ) ) )
V_188 = F_168 ( V_3 , V_524 , V_522 ) ;
return V_188 != - V_125 ? V_188 : 0 ;
}
int F_194 ( struct V_2 * V_3 , enum V_525 V_526 ,
bool V_527 )
{
struct V_179 * V_180 = & V_3 -> V_181 ;
bool V_528 = false ;
T_1 V_423 ;
int V_188 ;
V_188 = F_142 ( V_3 , V_426 , & V_423 ) ;
if ( V_188 )
return V_188 ;
switch ( V_526 ) {
case V_363 :
V_423 |= ( 0x7 << 8 ) ;
if ( V_527 ) {
V_423 |= ( 0x4 << 12 ) ;
V_528 = true ;
}
break;
case V_529 :
V_423 &= ~ ( 0x1 << 8 ) ;
V_423 |= ( 0x6 << 8 ) ;
break;
case V_530 :
if ( F_195 ( V_3 ) > 0 )
V_423 &= ~ ( 0x7 << 8 ) ;
else {
V_423 &= ~ 0xf ;
V_423 |= ( 0x1 << 2 ) ;
}
break;
default:
F_85 ( 1 ) ;
}
V_188 = F_168 ( V_3 , V_426 , V_423 ) ;
if ( V_188 )
return V_188 ;
if ( V_528 )
F_196 ( 10 ) ;
V_180 -> V_25 . V_522 &= ~ V_531 ;
return F_168 ( V_3 , V_524 , V_531 ) ;
}
int F_197 ( struct V_2 * V_3 , unsigned long V_501 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_179 * V_180 = & V_3 -> V_181 ;
const unsigned long * V_532 = F_198 ( V_180 ) ;
int V_188 ;
if ( V_180 -> V_25 . V_533 & V_534 )
return 0 ;
if ( V_5 -> V_42 & V_486 ) {
V_188 = F_193 ( V_3 , V_532 , V_501 ) ;
if ( V_188 && V_188 != - V_430 )
F_164 ( V_3 ,
L_144 ,
V_188 ) ;
}
if ( F_199 ( V_3 ) )
V_180 -> V_25 . V_533 &= ~ V_535 ;
return 0 ;
}
int F_200 ( struct V_2 * V_3 , const unsigned long * V_532 ,
unsigned long V_501 ,
bool * V_536 , int (* F_184)( struct V_2 * ) )
{
T_1 V_423 ;
int V_188 ;
F_30 ( L_145 ) ;
if ( V_536 )
* V_536 = false ;
if ( F_166 ( V_3 ) ) {
if ( ( V_188 = F_142 ( V_3 , V_426 , & V_423 ) ) )
goto V_497;
V_423 = ( V_423 & 0x0f0 ) | 0x304 ;
if ( ( V_188 = F_168 ( V_3 , V_426 , V_423 ) ) )
goto V_497;
F_167 ( V_3 ) ;
}
if ( ( V_188 = F_142 ( V_3 , V_426 , & V_423 ) ) )
goto V_497;
V_423 = ( V_423 & 0x0f0 ) | 0x301 ;
if ( ( V_188 = F_201 ( V_3 , V_426 , V_423 ) ) )
goto V_497;
F_190 ( V_3 -> V_5 , 1 ) ;
V_188 = F_193 ( V_3 , V_532 , V_501 ) ;
if ( V_188 )
goto V_497;
if ( F_199 ( V_3 ) )
goto V_497;
if ( V_536 )
* V_536 = true ;
if ( F_202 ( V_3 -> V_5 ) && F_13 ( V_3 ) ) {
if ( F_184 ) {
unsigned long V_537 ;
V_537 = F_185 ( V_503 ,
V_538 ) ;
if ( F_186 ( V_537 , V_501 ) )
V_537 = V_501 ;
F_183 ( V_3 , V_537 , F_184 ) ;
}
V_188 = - V_302 ;
goto V_497;
}
V_188 = 0 ;
if ( F_184 )
V_188 = F_183 ( V_3 , V_501 , F_184 ) ;
V_497:
if ( V_188 && V_188 != - V_302 ) {
if ( V_536 )
* V_536 = false ;
F_203 ( V_3 , L_146 , V_188 ) ;
}
F_30 ( L_147 , V_188 ) ;
return V_188 ;
}
int F_204 ( struct V_2 * V_3 , unsigned int * V_110 ,
unsigned long V_501 )
{
const unsigned long * V_532 = F_198 ( & V_3 -> V_181 ) ;
bool V_536 ;
int V_188 ;
V_188 = F_200 ( V_3 , V_532 , V_501 , & V_536 , NULL ) ;
return V_536 ? - V_302 : V_188 ;
}
void F_205 ( struct V_2 * V_3 , unsigned int * V_412 )
{
T_1 V_522 ;
F_30 ( L_145 ) ;
if ( ! F_142 ( V_3 , V_524 , & V_522 ) )
F_168 ( V_3 , V_524 , V_522 ) ;
F_159 ( V_3 ) ;
F_30 ( L_148 ) ;
}
static int F_206 ( struct V_14 * V_15 , unsigned int V_539 ,
const T_4 * V_540 )
{
const T_4 * V_541 = V_15 -> V_150 ;
unsigned char V_542 [ 2 ] [ V_355 + 1 ] ;
unsigned char V_543 [ 2 ] [ V_544 + 1 ] ;
if ( V_15 -> V_110 != V_539 ) {
F_57 ( V_15 , L_149 ,
V_15 -> V_110 , V_539 ) ;
return 0 ;
}
F_41 ( V_541 , V_542 [ 0 ] , V_369 , sizeof( V_542 [ 0 ] ) ) ;
F_41 ( V_540 , V_542 [ 1 ] , V_369 , sizeof( V_542 [ 1 ] ) ) ;
F_41 ( V_541 , V_543 [ 0 ] , V_545 , sizeof( V_543 [ 0 ] ) ) ;
F_41 ( V_540 , V_543 [ 1 ] , V_545 , sizeof( V_543 [ 1 ] ) ) ;
if ( strcmp ( V_542 [ 0 ] , V_542 [ 1 ] ) ) {
F_57 ( V_15 , L_150 ,
V_542 [ 0 ] , V_542 [ 1 ] ) ;
return 0 ;
}
if ( strcmp ( V_543 [ 0 ] , V_543 [ 1 ] ) ) {
F_57 ( V_15 , L_151 ,
V_543 [ 0 ] , V_543 [ 1 ] ) ;
return 0 ;
}
return 1 ;
}
int F_58 ( struct V_14 * V_15 , unsigned int V_546 )
{
unsigned int V_110 = V_15 -> V_110 ;
T_4 * V_150 = ( void * ) V_15 -> V_3 -> V_5 -> V_293 ;
int V_188 ;
V_188 = F_91 ( V_15 , & V_110 , V_546 , V_150 ) ;
if ( V_188 )
return V_188 ;
if ( ! F_206 ( V_15 , V_110 , V_150 ) )
return - V_270 ;
memcpy ( V_15 -> V_150 , V_150 , sizeof( V_150 [ 0 ] ) * V_260 ) ;
return 0 ;
}
int F_179 ( struct V_14 * V_15 , unsigned int V_539 ,
unsigned int V_546 )
{
T_3 V_366 = V_15 -> V_366 ;
T_3 V_190 = V_15 -> V_190 ;
int V_188 ;
if ( ! F_8 ( V_15 ) )
return - V_270 ;
if ( F_207 ( V_539 ) &&
V_539 != V_144 &&
V_539 != V_145 &&
V_539 != V_148 &&
V_539 != V_147 ) {
F_57 ( V_15 , L_152 ,
V_15 -> V_110 , V_539 ) ;
V_188 = - V_270 ;
goto V_420;
}
V_188 = F_58 ( V_15 , V_546 ) ;
if ( V_188 )
goto V_420;
V_188 = F_130 ( V_15 ) ;
if ( V_188 )
goto V_420;
if ( V_15 -> V_110 != V_144 || ! V_366 ||
V_15 -> V_366 == V_366 )
return 0 ;
F_24 ( V_15 , L_153 ,
( unsigned long long ) V_366 ,
( unsigned long long ) V_15 -> V_366 ) ;
if ( V_15 -> V_190 == V_190 &&
V_15 -> V_366 > V_366 && V_15 -> V_366 == V_190 ) {
F_24 ( V_15 ,
L_154
L_155 ) ;
return 0 ;
}
if ( V_15 -> V_190 == V_190 &&
V_15 -> V_366 < V_366 && V_366 == V_190 &&
! ( V_15 -> V_48 & V_189 ) ) {
F_24 ( V_15 ,
L_156
L_157 ) ;
V_15 -> V_42 |= V_186 ;
V_188 = - V_173 ;
} else
V_188 = - V_270 ;
V_15 -> V_190 = V_190 ;
V_15 -> V_366 = V_366 ;
V_420:
F_59 ( V_15 , L_158 , V_188 ) ;
return V_188 ;
}
static unsigned long F_108 ( const struct V_14 * V_15 )
{
unsigned char V_547 [ V_355 + 1 ] ;
unsigned char V_548 [ V_353 + 1 ] ;
const struct V_549 * V_550 = V_551 ;
F_41 ( V_15 -> V_150 , V_547 , V_369 , sizeof( V_547 ) ) ;
F_41 ( V_15 -> V_150 , V_548 , V_368 , sizeof( V_548 ) ) ;
while ( V_550 -> V_547 ) {
if ( F_208 ( V_550 -> V_547 , V_547 ) ) {
if ( V_550 -> V_548 == NULL )
return V_550 -> V_48 ;
if ( F_208 ( V_550 -> V_548 , V_548 ) )
return V_550 -> V_48 ;
}
V_550 ++ ;
}
return 0 ;
}
static int F_209 ( const struct V_14 * V_15 )
{
if ( ( V_15 -> V_3 -> V_5 -> V_42 & V_552 ) &&
( V_15 -> V_42 & V_392 ) )
return 1 ;
return ( V_15 -> V_48 & V_553 ) ? 1 : 0 ;
}
static int F_210 ( struct V_14 * V_15 )
{
if ( V_15 -> V_48 & V_554 )
return F_211 ( V_15 -> V_150 ) ;
return F_212 ( V_15 -> V_150 ) ;
}
static int F_213 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
struct V_14 * V_15 ;
if ( V_5 -> V_33 == V_408 )
return 1 ;
if ( V_5 -> V_33 == V_409 || V_5 -> V_33 == V_304 )
return 0 ;
if ( V_5 -> V_33 == V_555 )
return 0 ;
F_214 (link, ap, EDGE) {
F_155 (dev, link, ENABLED) {
if ( ! F_210 ( V_15 ) )
return 0 ;
}
}
return 1 ;
}
static void F_181 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_556 * V_280 = V_5 -> V_280 ;
unsigned long V_47 ;
V_47 = F_31 ( V_5 -> V_44 ,
V_5 -> V_45 , V_5 -> V_46 ) ;
V_47 &= F_31 ( V_15 -> V_44 ,
V_15 -> V_45 , V_15 -> V_46 ) ;
V_47 &= F_61 ( V_15 -> V_150 ) ;
if ( F_162 ( V_15 ) ) {
V_47 &= ~ ( 0x03 << ( V_127 + 5 ) ) ;
V_47 &= ~ ( 0x03 << ( V_129 + 3 ) ) ;
}
if ( F_209 ( V_15 ) ) {
V_47 &= ~ ( V_130 | V_132 ) ;
F_24 ( V_15 ,
L_159 ) ;
}
if ( ( V_280 -> V_42 & V_499 ) &&
V_280 -> V_500 && V_280 -> V_500 != V_5 ) {
V_47 &= ~ ( V_130 | V_132 ) ;
F_24 ( V_15 ,
L_160 ) ;
}
if ( V_5 -> V_42 & V_254 )
V_47 &= F_89 ( V_15 ) ;
if ( V_5 -> V_220 -> V_557 )
V_47 = V_5 -> V_220 -> V_557 ( V_15 , V_47 ) ;
if ( V_47 & ( 0xF8 << V_131 ) )
if ( F_213 ( V_5 ) ) {
F_24 ( V_15 ,
L_161 ) ;
V_47 &= ~ ( 0xF8 << V_131 ) ;
}
F_16 ( V_47 , & V_15 -> V_44 ,
& V_15 -> V_45 , & V_15 -> V_46 ) ;
}
static unsigned int F_178 ( struct V_14 * V_15 )
{
struct V_67 V_68 ;
unsigned int V_165 ;
F_30 ( L_162 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_558 ;
V_68 . V_72 = V_559 ;
V_68 . V_42 |= V_111 | V_112 | V_272 ;
V_68 . V_93 = V_168 ;
if ( F_87 ( V_15 ) )
V_68 . V_80 = V_15 -> V_140 ;
else if ( F_88 ( V_15 -> V_150 ) )
V_68 . V_80 = 0x01 ;
else
return 0 ;
V_165 = F_53 ( V_15 , & V_68 , NULL , V_169 , NULL , 0 , 15000 ) ;
F_30 ( L_76 , V_165 ) ;
return V_165 ;
}
unsigned int F_97 ( struct V_14 * V_15 , T_2 V_560 , T_2 V_72 )
{
struct V_67 V_68 ;
unsigned int V_165 ;
unsigned long V_209 = 0 ;
F_30 ( L_163 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_558 ;
V_68 . V_72 = V_560 ;
V_68 . V_42 |= V_111 | V_112 ;
V_68 . V_93 = V_168 ;
V_68 . V_80 = V_72 ;
if ( V_560 == V_282 )
V_209 = V_239 ?
V_239 * 1000 : V_561 ;
V_165 = F_53 ( V_15 , & V_68 , NULL , V_169 , NULL , 0 , V_209 ) ;
F_30 ( L_76 , V_165 ) ;
return V_165 ;
}
static unsigned int F_99 ( struct V_14 * V_15 ,
T_4 V_105 , T_4 V_106 )
{
struct V_67 V_68 ;
unsigned int V_165 ;
if ( V_106 < 1 || V_106 > 255 || V_105 < 1 || V_105 > 16 )
return V_562 ;
F_30 ( L_164 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_563 ;
V_68 . V_42 |= V_111 | V_112 ;
V_68 . V_93 = V_168 ;
V_68 . V_80 = V_106 ;
V_68 . V_21 |= ( V_105 - 1 ) & 0x0f ;
V_165 = F_53 ( V_15 , & V_68 , NULL , V_169 , NULL , 0 , 0 ) ;
if ( V_165 == V_170 && ( V_68 . V_72 & V_171 ) )
V_165 = 0 ;
F_30 ( L_76 , V_165 ) ;
return V_165 ;
}
int F_215 ( struct V_199 * V_200 )
{
struct V_4 * V_5 = V_200 -> V_5 ;
if ( ! ( V_200 -> V_15 -> V_48 & V_564 ) &&
F_5 ( V_200 -> V_237 & 15 ) )
return 1 ;
if ( V_5 -> V_220 -> V_565 )
return V_5 -> V_220 -> V_565 ( V_200 ) ;
return 0 ;
}
int F_216 ( struct V_199 * V_200 )
{
struct V_2 * V_3 = V_200 -> V_15 -> V_3 ;
if ( F_217 ( V_200 -> V_68 . V_93 ) ) {
if ( ! F_218 ( V_3 -> V_223 ) )
return 0 ;
} else {
if ( ! F_218 ( V_3 -> V_223 ) && ! V_3 -> V_224 )
return 0 ;
}
return V_566 ;
}
void F_219 ( struct V_199 * V_200 ) { }
void F_72 ( struct V_199 * V_200 , struct V_206 * V_235 ,
unsigned int V_208 )
{
V_200 -> V_235 = V_235 ;
V_200 -> V_208 = V_208 ;
V_200 -> V_567 = V_200 -> V_235 ;
}
static void F_220 ( struct V_199 * V_200 )
{
struct V_4 * V_5 = V_200 -> V_5 ;
struct V_206 * V_235 = V_200 -> V_235 ;
int V_568 = V_200 -> V_205 ;
F_221 ( V_235 == NULL ) ;
F_222 ( L_165 , V_200 -> V_208 ) ;
if ( V_200 -> V_208 )
F_223 ( V_5 -> V_15 , V_235 , V_200 -> V_569 , V_568 ) ;
V_200 -> V_42 &= ~ V_570 ;
V_200 -> V_235 = NULL ;
}
static int F_224 ( struct V_199 * V_200 )
{
struct V_4 * V_5 = V_200 -> V_5 ;
unsigned int V_208 ;
F_222 ( L_166 , V_5 -> V_31 ) ;
V_208 = F_225 ( V_5 -> V_15 , V_200 -> V_235 , V_200 -> V_208 , V_200 -> V_205 ) ;
if ( V_208 < 1 )
return - 1 ;
F_30 ( L_167 , V_208 ) ;
V_200 -> V_569 = V_200 -> V_208 ;
V_200 -> V_208 = V_208 ;
V_200 -> V_42 |= V_570 ;
return 0 ;
}
static inline void F_220 ( struct V_199 * V_200 ) {}
static inline int F_224 ( struct V_199 * V_200 ) { return - 1 ; }
void F_95 ( T_4 * V_250 , unsigned int V_571 )
{
#ifdef F_226
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < V_571 ; V_25 ++ )
V_250 [ V_25 ] = F_227 ( V_250 [ V_25 ] ) ;
#endif
}
struct V_199 * F_228 ( struct V_14 * V_15 , int V_109 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_199 * V_200 ;
if ( F_5 ( V_5 -> V_217 & V_218 ) )
return NULL ;
if ( V_5 -> V_42 & V_572 ) {
V_109 = F_229 ( V_5 ) ;
if ( V_109 < 0 )
return NULL ;
}
V_200 = F_69 ( V_5 , V_109 ) ;
V_200 -> V_109 = V_109 ;
V_200 -> V_222 = NULL ;
V_200 -> V_5 = V_5 ;
V_200 -> V_15 = V_15 ;
F_70 ( V_200 ) ;
return V_200 ;
}
void F_83 ( struct V_199 * V_200 )
{
struct V_4 * V_5 ;
unsigned int V_109 ;
F_221 ( V_200 == NULL ) ;
V_5 = V_200 -> V_5 ;
V_200 -> V_42 = 0 ;
V_109 = V_200 -> V_109 ;
if ( F_27 ( F_218 ( V_109 ) ) ) {
V_200 -> V_109 = V_227 ;
if ( V_5 -> V_42 & V_572 )
F_230 ( V_109 , V_5 ) ;
}
}
void F_231 ( struct V_199 * V_200 )
{
struct V_4 * V_5 ;
struct V_2 * V_3 ;
F_221 ( V_200 == NULL ) ;
F_221 ( ! ( V_200 -> V_42 & V_240 ) ) ;
V_5 = V_200 -> V_5 ;
V_3 = V_200 -> V_15 -> V_3 ;
if ( F_27 ( V_200 -> V_42 & V_570 ) )
F_220 ( V_200 ) ;
if ( F_217 ( V_200 -> V_68 . V_93 ) ) {
V_3 -> V_224 &= ~ ( 1 << V_200 -> V_109 ) ;
if ( ! V_3 -> V_224 )
V_5 -> V_226 -- ;
} else {
V_3 -> V_223 = V_227 ;
V_5 -> V_226 -- ;
}
if ( F_5 ( V_200 -> V_42 & V_573 &&
V_5 -> V_574 == V_3 ) )
V_5 -> V_574 = NULL ;
V_200 -> V_42 &= ~ V_240 ;
V_5 -> V_225 &= ~ ( 1 << V_200 -> V_109 ) ;
V_200 -> V_238 ( V_200 ) ;
}
static void F_232 ( struct V_199 * V_200 )
{
struct V_4 * V_5 = V_200 -> V_5 ;
V_200 -> V_244 . V_42 = V_200 -> V_68 . V_42 ;
V_5 -> V_220 -> V_575 ( V_200 ) ;
}
static void F_233 ( struct V_199 * V_200 )
{
struct V_14 * V_15 = V_200 -> V_15 ;
if ( ! F_234 ( V_200 -> V_68 . V_93 ) )
return;
if ( ( V_15 -> V_45 || V_15 -> V_46 ) && F_235 ( V_200 -> V_68 . V_93 ) )
return;
V_15 -> V_42 &= ~ V_576 ;
}
void F_81 ( struct V_199 * V_200 )
{
struct V_4 * V_5 = V_200 -> V_5 ;
F_236 () ;
if ( V_5 -> V_220 -> V_221 ) {
struct V_14 * V_15 = V_200 -> V_15 ;
struct V_577 * V_578 = & V_15 -> V_3 -> V_579 ;
if ( F_5 ( V_200 -> V_165 ) )
V_200 -> V_42 |= V_243 ;
if ( F_5 ( F_237 ( V_200 -> V_109 ) ) ) {
F_232 ( V_200 ) ;
F_238 ( V_200 ) ;
F_231 ( V_200 ) ;
return;
}
if ( F_5 ( V_200 -> V_42 & V_243 ) ) {
F_232 ( V_200 ) ;
F_239 ( V_200 ) ;
F_240 ( V_200 ) ;
return;
}
F_221 ( V_5 -> V_217 & V_218 ) ;
if ( V_200 -> V_42 & V_233 )
F_232 ( V_200 ) ;
F_241 ( V_200 ) ;
switch ( V_200 -> V_68 . V_71 ) {
case V_558 :
if ( V_200 -> V_68 . V_72 != V_580 &&
V_200 -> V_68 . V_72 != V_581 &&
V_200 -> V_68 . V_72 != V_582 &&
V_200 -> V_68 . V_72 != V_583 )
break;
case V_563 :
case V_584 :
V_578 -> V_585 [ V_15 -> V_24 ] |= V_586 ;
F_242 ( V_5 ) ;
break;
case V_587 :
V_15 -> V_42 |= V_588 ;
break;
}
if ( F_5 ( V_15 -> V_42 & V_576 ) )
F_233 ( V_200 ) ;
F_231 ( V_200 ) ;
} else {
if ( V_200 -> V_42 & V_589 )
return;
if ( V_200 -> V_165 || V_200 -> V_42 & V_233 )
F_232 ( V_200 ) ;
F_231 ( V_200 ) ;
}
}
int F_243 ( struct V_4 * V_5 , T_1 V_225 )
{
int V_590 = 0 ;
T_1 V_591 ;
V_591 = V_5 -> V_225 ^ V_225 ;
if ( F_5 ( V_591 & V_225 ) ) {
F_244 ( V_5 , L_168 ,
V_5 -> V_225 , V_225 ) ;
return - V_125 ;
}
while ( V_591 ) {
struct V_199 * V_200 ;
unsigned int V_109 = F_245 ( V_591 ) ;
V_200 = F_246 ( V_5 , V_109 ) ;
if ( V_200 ) {
F_81 ( V_200 ) ;
V_590 ++ ;
}
V_591 &= ~ ( 1 << V_109 ) ;
}
return V_590 ;
}
void F_73 ( struct V_199 * V_200 )
{
struct V_4 * V_5 = V_200 -> V_5 ;
struct V_2 * V_3 = V_200 -> V_15 -> V_3 ;
T_2 V_592 = V_200 -> V_68 . V_93 ;
F_221 ( V_5 -> V_220 -> V_221 && F_218 ( V_3 -> V_223 ) ) ;
if ( F_217 ( V_592 ) ) {
F_221 ( V_3 -> V_224 & ( 1 << V_200 -> V_109 ) ) ;
if ( ! V_3 -> V_224 )
V_5 -> V_226 ++ ;
V_3 -> V_224 |= 1 << V_200 -> V_109 ;
} else {
F_221 ( V_3 -> V_224 ) ;
V_5 -> V_226 ++ ;
V_3 -> V_223 = V_200 -> V_109 ;
}
V_200 -> V_42 |= V_240 ;
V_5 -> V_225 |= 1 << V_200 -> V_109 ;
if ( F_221 ( F_234 ( V_592 ) &&
( ! V_200 -> V_235 || ! V_200 -> V_208 || ! V_200 -> V_237 ) ) )
goto V_593;
if ( F_247 ( V_592 ) || ( F_235 ( V_592 ) &&
( V_5 -> V_42 & V_594 ) ) )
if ( F_224 ( V_200 ) )
goto V_593;
if ( F_5 ( V_200 -> V_15 -> V_42 & V_588 ) ) {
V_3 -> V_579 . V_533 |= V_595 ;
F_248 ( & V_3 -> V_579 , L_169 ) ;
F_249 ( V_3 ) ;
return;
}
V_5 -> V_220 -> V_596 ( V_200 ) ;
F_250 ( V_200 ) ;
V_200 -> V_165 |= V_5 -> V_220 -> V_597 ( V_200 ) ;
if ( F_5 ( V_200 -> V_165 ) )
goto V_294;
return;
V_593:
V_200 -> V_165 |= V_219 ;
V_294:
F_81 ( V_200 ) ;
}
int F_106 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
return ( V_5 -> V_42 & V_486 ) && V_5 -> V_220 -> V_598 ;
}
int F_142 ( struct V_2 * V_3 , int V_599 , T_1 * V_600 )
{
if ( F_13 ( V_3 ) ) {
if ( F_106 ( V_3 ) )
return V_3 -> V_5 -> V_220 -> V_598 ( V_3 , V_599 , V_600 ) ;
return - V_430 ;
}
return F_251 ( V_3 , V_599 , V_600 ) ;
}
int F_168 ( struct V_2 * V_3 , int V_599 , T_1 V_600 )
{
if ( F_13 ( V_3 ) ) {
if ( F_106 ( V_3 ) )
return V_3 -> V_5 -> V_220 -> V_601 ( V_3 , V_599 , V_600 ) ;
return - V_430 ;
}
return F_252 ( V_3 , V_599 , V_600 ) ;
}
int F_201 ( struct V_2 * V_3 , int V_599 , T_1 V_600 )
{
if ( F_13 ( V_3 ) ) {
int V_188 ;
if ( F_106 ( V_3 ) ) {
V_188 = V_3 -> V_5 -> V_220 -> V_601 ( V_3 , V_599 , V_600 ) ;
if ( V_188 == 0 )
V_188 = V_3 -> V_5 -> V_220 -> V_598 ( V_3 , V_599 , & V_600 ) ;
return V_188 ;
}
return - V_430 ;
}
return F_252 ( V_3 , V_599 , V_600 ) ;
}
bool F_160 ( struct V_2 * V_3 )
{
T_1 V_1 ;
if ( F_142 ( V_3 , V_425 , & V_1 ) == 0 &&
F_1 ( V_1 ) )
return true ;
return false ;
}
bool F_199 ( struct V_2 * V_3 )
{
T_1 V_1 ;
if ( F_142 ( V_3 , V_425 , & V_1 ) == 0 &&
! F_1 ( V_1 ) )
return true ;
return false ;
}
bool F_187 ( struct V_2 * V_3 )
{
struct V_2 * V_602 = V_3 -> V_5 -> V_12 ;
F_85 ( V_3 == V_602 ) ;
return F_160 ( V_3 ) ||
( V_602 && F_160 ( V_602 ) ) ;
}
bool F_188 ( struct V_2 * V_3 )
{
struct V_2 * V_602 = V_3 -> V_5 -> V_12 ;
F_85 ( V_3 == V_602 ) ;
return F_199 ( V_3 ) &&
( ! V_602 || F_199 ( V_602 ) ) ;
}
static void F_253 ( struct V_4 * V_5 , T_6 V_603 ,
unsigned int V_533 , unsigned int V_604 ,
bool V_605 )
{
struct V_2 * V_3 ;
unsigned long V_42 ;
if ( V_5 -> V_217 & V_606 ) {
F_254 ( V_5 ) ;
F_85 ( V_5 -> V_217 & V_606 ) ;
}
F_67 ( V_5 -> V_216 , V_42 ) ;
V_5 -> V_607 = V_603 ;
V_5 -> V_217 |= V_606 ;
F_214 (link, ap, HOST_FIRST) {
V_3 -> V_579 . V_533 |= V_533 ;
V_3 -> V_579 . V_42 |= V_604 ;
}
F_242 ( V_5 ) ;
F_68 ( V_5 -> V_216 , V_42 ) ;
if ( ! V_605 ) {
F_254 ( V_5 ) ;
F_85 ( V_5 -> V_217 & V_606 ) ;
}
}
static void F_255 ( struct V_4 * V_5 , T_6 V_603 )
{
F_253 ( V_5 , V_603 , 0 , V_608 , false ) ;
}
static void F_256 ( struct V_4 * V_5 , T_6 V_603 )
{
F_253 ( V_5 , V_603 , 0 , V_608 , true ) ;
}
static int F_257 ( struct V_21 * V_15 )
{
struct V_4 * V_5 = F_258 ( V_15 ) ;
if ( F_259 ( V_15 ) )
return 0 ;
F_255 ( V_5 , V_609 ) ;
return 0 ;
}
static int F_260 ( struct V_21 * V_15 )
{
struct V_4 * V_5 = F_258 ( V_15 ) ;
if ( F_259 ( V_15 ) )
return 0 ;
F_255 ( V_5 , V_610 ) ;
return 0 ;
}
static int F_261 ( struct V_21 * V_15 )
{
F_255 ( F_258 ( V_15 ) , V_611 ) ;
return 0 ;
}
static void F_262 ( struct V_4 * V_5 , T_6 V_603 )
{
F_253 ( V_5 , V_603 , V_595 , V_612 , false ) ;
}
static void F_263 ( struct V_4 * V_5 , T_6 V_603 )
{
F_253 ( V_5 , V_603 , V_595 , V_612 , true ) ;
}
static int F_264 ( struct V_21 * V_15 )
{
F_263 ( F_258 ( V_15 ) , V_613 ) ;
F_265 ( V_15 ) ;
F_266 ( V_15 ) ;
F_267 ( V_15 ) ;
return 0 ;
}
static int F_268 ( struct V_21 * V_15 )
{
struct V_4 * V_5 = F_258 ( V_15 ) ;
struct V_2 * V_3 ;
struct V_14 * V_252 ;
F_214 (link, ap, HOST_FIRST) {
F_155 (adev, link, ENABLED)
if ( V_252 -> V_110 == V_145 &&
! F_269 ( V_252 ) )
return - V_511 ;
}
return 0 ;
}
static int F_270 ( struct V_21 * V_15 )
{
F_255 ( F_258 ( V_15 ) , V_614 ) ;
return 0 ;
}
static int F_271 ( struct V_21 * V_15 )
{
F_262 ( F_258 ( V_15 ) , V_615 ) ;
return 0 ;
}
void F_272 ( struct V_4 * V_5 )
{
F_256 ( V_5 , V_609 ) ;
}
void F_273 ( struct V_4 * V_5 )
{
F_263 ( V_5 , V_613 ) ;
}
int F_274 ( struct V_556 * V_280 , T_6 V_603 )
{
V_280 -> V_15 -> V_616 . V_617 = V_603 ;
return 0 ;
}
void F_275 ( struct V_556 * V_280 )
{
V_280 -> V_15 -> V_616 . V_617 = V_618 ;
}
void F_276 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = F_9 ( V_15 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_42 ;
V_3 -> V_300 = V_3 -> V_40 ;
V_3 -> V_301 = 0 ;
F_67 ( V_5 -> V_216 , V_42 ) ;
V_15 -> V_42 &= ~ V_619 ;
V_15 -> V_48 = 0 ;
F_68 ( V_5 -> V_216 , V_42 ) ;
memset ( ( void * ) V_15 + V_620 , 0 ,
V_621 - V_620 ) ;
V_15 -> V_44 = V_433 ;
V_15 -> V_45 = V_433 ;
V_15 -> V_46 = V_433 ;
}
void F_277 ( struct V_4 * V_5 , struct V_2 * V_3 , int V_38 )
{
int V_25 ;
memset ( ( void * ) V_3 + V_622 , 0 ,
V_623 - V_622 ) ;
V_3 -> V_5 = V_5 ;
V_3 -> V_38 = V_38 ;
V_3 -> V_223 = V_227 ;
V_3 -> V_40 = V_433 ;
for ( V_25 = 0 ; V_25 < V_413 ; V_25 ++ ) {
struct V_14 * V_15 = & V_3 -> V_21 [ V_25 ] ;
V_15 -> V_3 = V_3 ;
V_15 -> V_24 = V_15 - V_3 -> V_21 ;
#ifdef F_278
V_15 -> V_624 = V_625 ;
#endif
F_276 ( V_15 ) ;
}
}
int F_279 ( struct V_2 * V_3 )
{
T_2 V_142 ;
int V_188 ;
V_188 = F_142 ( V_3 , V_426 , & V_3 -> V_626 ) ;
if ( V_188 )
return V_188 ;
V_142 = ( V_3 -> V_626 >> 4 ) & 0xf ;
if ( V_142 )
V_3 -> V_40 &= ( 1 << V_142 ) - 1 ;
F_12 ( V_3 ) ;
V_3 -> V_300 = V_3 -> V_40 ;
return 0 ;
}
struct V_4 * F_280 ( struct V_556 * V_280 )
{
struct V_4 * V_5 ;
F_30 ( L_145 ) ;
V_5 = F_281 ( sizeof( * V_5 ) , V_627 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_217 |= V_628 | V_218 ;
V_5 -> V_216 = & V_280 -> V_216 ;
V_5 -> V_31 = - 1 ;
V_5 -> V_629 = - 1 ;
V_5 -> V_280 = V_280 ;
V_5 -> V_15 = V_280 -> V_15 ;
#if F_282 ( V_630 )
V_5 -> V_631 = 0x00FF ;
#elif F_282 ( V_632 )
V_5 -> V_631 = V_633 | V_634 | V_635 | V_636 | V_637 ;
#else
V_5 -> V_631 = V_633 | V_637 | V_636 ;
#endif
F_283 ( & V_5 -> V_638 ) ;
F_284 ( & V_5 -> V_639 , V_640 ) ;
F_285 ( & V_5 -> V_641 , V_642 ) ;
F_286 ( & V_5 -> V_643 ) ;
F_287 ( & V_5 -> V_644 ) ;
F_288 ( & V_5 -> V_645 ) ;
F_289 ( & V_5 -> V_646 ,
V_647 ,
( unsigned long ) V_5 ) ;
V_5 -> V_33 = V_34 ;
F_277 ( V_5 , & V_5 -> V_3 , 0 ) ;
#ifdef F_290
V_5 -> V_648 . V_649 = 1 ;
V_5 -> V_648 . V_650 = 1 ;
#endif
F_291 ( V_5 ) ;
return V_5 ;
}
static void F_292 ( struct V_21 * V_651 , void * V_652 )
{
struct V_556 * V_280 = F_293 ( V_651 ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_280 -> V_653 ; V_25 ++ ) {
struct V_4 * V_5 = V_280 -> V_654 [ V_25 ] ;
if ( ! V_5 )
continue;
if ( V_5 -> V_326 )
F_294 ( V_5 -> V_326 ) ;
F_295 ( V_5 -> V_11 ) ;
F_295 ( V_5 -> V_12 ) ;
F_295 ( V_5 ) ;
V_280 -> V_654 [ V_25 ] = NULL ;
}
F_296 ( V_651 , NULL ) ;
}
struct V_556 * F_297 ( struct V_21 * V_15 , int V_655 )
{
struct V_556 * V_280 ;
T_5 V_656 ;
int V_25 ;
F_30 ( L_145 ) ;
if ( ! F_298 ( V_15 , NULL , V_627 ) )
return NULL ;
V_656 = sizeof( struct V_556 ) + ( V_655 + 1 ) * sizeof( void * ) ;
V_280 = F_299 ( F_292 , V_656 , V_627 ) ;
if ( ! V_280 )
goto V_271;
F_300 ( V_15 , V_280 ) ;
F_296 ( V_15 , V_280 ) ;
F_301 ( & V_280 -> V_216 ) ;
F_283 ( & V_280 -> V_657 ) ;
V_280 -> V_15 = V_15 ;
V_280 -> V_653 = V_655 ;
for ( V_25 = 0 ; V_25 < V_655 ; V_25 ++ ) {
struct V_4 * V_5 ;
V_5 = F_280 ( V_280 ) ;
if ( ! V_5 )
goto V_271;
V_5 -> V_658 = V_25 ;
V_280 -> V_654 [ V_25 ] = V_5 ;
}
F_302 ( V_15 , NULL ) ;
return V_280 ;
V_271:
F_303 ( V_15 , NULL ) ;
return NULL ;
}
struct V_556 * F_304 ( struct V_21 * V_15 ,
const struct V_659 * const * V_660 ,
int V_653 )
{
const struct V_659 * V_661 ;
struct V_556 * V_280 ;
int V_25 , V_377 ;
V_280 = F_297 ( V_15 , V_653 ) ;
if ( ! V_280 )
return NULL ;
for ( V_25 = 0 , V_377 = 0 , V_661 = NULL ; V_25 < V_280 -> V_653 ; V_25 ++ ) {
struct V_4 * V_5 = V_280 -> V_654 [ V_25 ] ;
if ( V_660 [ V_377 ] )
V_661 = V_660 [ V_377 ++ ] ;
V_5 -> V_44 = V_661 -> V_44 ;
V_5 -> V_45 = V_661 -> V_45 ;
V_5 -> V_46 = V_661 -> V_46 ;
V_5 -> V_42 |= V_661 -> V_42 ;
V_5 -> V_3 . V_42 |= V_661 -> V_662 ;
V_5 -> V_220 = V_661 -> V_663 ;
if ( ! V_280 -> V_220 && ( V_661 -> V_663 != & V_664 ) )
V_280 -> V_220 = V_661 -> V_663 ;
}
return V_280 ;
}
int F_305 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
F_85 ( V_5 -> V_12 ) ;
F_85 ( V_5 -> V_42 & V_665 ) ;
V_3 = F_281 ( sizeof( * V_3 ) , V_627 ) ;
if ( ! V_3 )
return - V_666 ;
F_277 ( V_5 , V_3 , 1 ) ;
V_5 -> V_12 = V_3 ;
return 0 ;
}
static void F_306 ( struct V_21 * V_651 , void * V_652 )
{
struct V_556 * V_280 = F_293 ( V_651 ) ;
int V_25 ;
F_85 ( ! ( V_280 -> V_42 & V_667 ) ) ;
for ( V_25 = 0 ; V_25 < V_280 -> V_653 ; V_25 ++ ) {
struct V_4 * V_5 = V_280 -> V_654 [ V_25 ] ;
if ( V_5 -> V_220 -> V_668 )
V_5 -> V_220 -> V_668 ( V_5 ) ;
}
if ( V_280 -> V_220 -> V_669 )
V_280 -> V_220 -> V_669 ( V_280 ) ;
}
static void F_307 ( struct V_670 * V_220 )
{
static F_308 ( V_216 ) ;
const struct V_670 * V_519 ;
void * * V_671 = ( void * * ) V_220 ;
void * * V_672 = ( void * * ) & V_220 -> V_673 ;
void * * V_674 ;
if ( ! V_220 || ! V_220 -> V_673 )
return;
F_309 ( & V_216 ) ;
for ( V_519 = V_220 -> V_673 ; V_519 ; V_519 = V_519 -> V_673 ) {
void * * V_675 = ( void * * ) V_519 ;
for ( V_674 = V_671 ; V_674 < V_672 ; V_674 ++ , V_675 ++ )
if ( ! * V_674 )
* V_674 = * V_675 ;
}
for ( V_674 = V_671 ; V_674 < V_672 ; V_674 ++ )
if ( F_310 ( * V_674 ) )
* V_674 = NULL ;
V_220 -> V_673 = NULL ;
F_311 ( & V_216 ) ;
}
int F_312 ( struct V_556 * V_280 )
{
int V_676 = 0 ;
void * V_677 = NULL ;
int V_25 , V_188 ;
if ( V_280 -> V_42 & V_667 )
return 0 ;
F_307 ( V_280 -> V_220 ) ;
for ( V_25 = 0 ; V_25 < V_280 -> V_653 ; V_25 ++ ) {
struct V_4 * V_5 = V_280 -> V_654 [ V_25 ] ;
F_307 ( V_5 -> V_220 ) ;
if ( ! V_280 -> V_220 && ! F_313 ( V_5 ) )
V_280 -> V_220 = V_5 -> V_220 ;
if ( V_5 -> V_220 -> V_668 )
V_676 = 1 ;
}
if ( V_280 -> V_220 -> V_669 )
V_676 = 1 ;
if ( V_676 ) {
V_677 = F_299 ( F_306 , 0 , V_627 ) ;
if ( ! V_677 )
return - V_666 ;
}
for ( V_25 = 0 ; V_25 < V_280 -> V_653 ; V_25 ++ ) {
struct V_4 * V_5 = V_280 -> V_654 [ V_25 ] ;
if ( V_5 -> V_220 -> V_678 ) {
V_188 = V_5 -> V_220 -> V_678 ( V_5 ) ;
if ( V_188 ) {
if ( V_188 != - V_270 )
F_314 ( V_280 -> V_15 ,
L_170 ,
V_25 , V_188 ) ;
goto V_271;
}
}
F_315 ( V_5 ) ;
}
if ( V_677 )
F_300 ( V_280 -> V_15 , V_677 ) ;
V_280 -> V_42 |= V_667 ;
return 0 ;
V_271:
while ( -- V_25 >= 0 ) {
struct V_4 * V_5 = V_280 -> V_654 [ V_25 ] ;
if ( V_5 -> V_220 -> V_668 )
V_5 -> V_220 -> V_668 ( V_5 ) ;
}
F_316 ( V_677 ) ;
return V_188 ;
}
void F_317 ( struct V_556 * V_280 , struct V_21 * V_15 ,
struct V_670 * V_220 )
{
F_301 ( & V_280 -> V_216 ) ;
F_283 ( & V_280 -> V_657 ) ;
V_280 -> V_679 = V_328 - 1 ;
V_280 -> V_15 = V_15 ;
V_280 -> V_220 = V_220 ;
}
void F_318 ( struct V_4 * V_5 )
{
struct V_577 * V_578 = & V_5 -> V_3 . V_579 ;
unsigned long V_42 ;
F_67 ( V_5 -> V_216 , V_42 ) ;
V_578 -> V_680 |= V_681 ;
V_578 -> V_533 |= V_595 ;
V_578 -> V_42 |= V_682 | V_683 ;
V_5 -> V_217 &= ~ V_628 ;
V_5 -> V_217 |= V_684 ;
F_242 ( V_5 ) ;
F_68 ( V_5 -> V_216 , V_42 ) ;
}
int F_319 ( struct V_4 * V_5 )
{
int V_188 = 0 ;
if ( V_5 -> V_220 -> V_221 ) {
F_318 ( V_5 ) ;
F_254 ( V_5 ) ;
} else {
F_30 ( L_171 , V_5 -> V_31 ) ;
V_188 = F_154 ( V_5 ) ;
F_30 ( L_172 , V_5 -> V_31 ) ;
}
return V_188 ;
}
static void F_320 ( void * V_685 , T_7 V_686 )
{
struct V_4 * V_5 = V_685 ;
if ( ! ( V_5 -> V_280 -> V_42 & V_506 ) && V_5 -> V_658 != 0 )
F_321 ( V_686 ) ;
( void ) F_319 ( V_5 ) ;
F_321 ( V_686 ) ;
F_322 ( V_5 , 1 ) ;
}
int F_323 ( struct V_556 * V_280 , struct V_687 * V_688 )
{
int V_25 , V_188 ;
V_280 -> V_679 = F_324 ( V_688 -> V_327 , 1 , V_328 - 1 ) ;
if ( ! ( V_280 -> V_42 & V_667 ) ) {
F_314 ( V_280 -> V_15 , L_173 ) ;
F_85 ( 1 ) ;
return - V_125 ;
}
for ( V_25 = V_280 -> V_653 ; V_280 -> V_654 [ V_25 ] ; V_25 ++ )
F_295 ( V_280 -> V_654 [ V_25 ] ) ;
for ( V_25 = 0 ; V_25 < V_280 -> V_653 ; V_25 ++ ) {
V_280 -> V_654 [ V_25 ] -> V_31 = F_325 ( & V_689 ) ;
V_280 -> V_654 [ V_25 ] -> V_629 = V_25 + 1 ;
}
for ( V_25 = 0 ; V_25 < V_280 -> V_653 ; V_25 ++ ) {
V_188 = F_326 ( V_280 -> V_15 , V_280 -> V_654 [ V_25 ] ) ;
if ( V_188 ) {
goto V_690;
}
}
V_188 = F_327 ( V_280 , V_688 ) ;
if ( V_188 )
goto V_690;
for ( V_25 = 0 ; V_25 < V_280 -> V_653 ; V_25 ++ ) {
struct V_4 * V_5 = V_280 -> V_654 [ V_25 ] ;
unsigned long V_47 ;
if ( V_5 -> V_33 == V_34 && ( V_5 -> V_42 & V_486 ) )
V_5 -> V_33 = V_304 ;
F_279 ( & V_5 -> V_3 ) ;
if ( V_5 -> V_12 )
F_279 ( V_5 -> V_12 ) ;
V_47 = F_31 ( V_5 -> V_44 , V_5 -> V_45 ,
V_5 -> V_46 ) ;
if ( ! F_313 ( V_5 ) ) {
V_659 ( V_5 , L_174 ,
( V_5 -> V_42 & V_486 ) ? 'S' : 'P' ,
F_36 ( V_47 ) ,
V_5 -> V_3 . V_579 . V_319 ) ;
F_328 ( & V_5 -> V_3 . V_579 ) ;
} else
V_659 ( V_5 , L_175 ) ;
}
for ( V_25 = 0 ; V_25 < V_280 -> V_653 ; V_25 ++ ) {
struct V_4 * V_5 = V_280 -> V_654 [ V_25 ] ;
F_329 ( F_320 , V_5 ) ;
}
return 0 ;
V_690:
while ( -- V_25 >= 0 ) {
F_330 ( V_280 -> V_654 [ V_25 ] ) ;
}
return V_188 ;
}
int F_331 ( struct V_556 * V_280 , int V_691 ,
T_8 V_692 , unsigned long V_693 ,
struct V_687 * V_688 )
{
int V_25 , V_188 ;
char * V_694 ;
V_188 = F_312 ( V_280 ) ;
if ( V_188 )
return V_188 ;
if ( ! V_691 ) {
F_85 ( V_692 ) ;
return F_323 ( V_280 , V_688 ) ;
}
V_694 = F_332 ( V_280 -> V_15 , V_627 , L_176 ,
F_333 ( V_280 -> V_15 ) ,
F_334 ( V_280 -> V_15 ) ) ;
if ( ! V_694 )
return - V_666 ;
V_188 = F_335 ( V_280 -> V_15 , V_691 , V_692 , V_693 ,
V_694 , V_280 ) ;
if ( V_188 )
return V_188 ;
for ( V_25 = 0 ; V_25 < V_280 -> V_653 ; V_25 ++ )
F_336 ( V_280 -> V_654 [ V_25 ] , L_177 , V_691 ) ;
V_188 = F_323 ( V_280 , V_688 ) ;
if ( V_188 )
F_337 ( V_280 -> V_15 , V_691 , V_280 ) ;
return V_188 ;
}
static void F_338 ( struct V_4 * V_5 )
{
unsigned long V_42 ;
struct V_2 * V_3 ;
struct V_14 * V_15 ;
if ( ! V_5 -> V_220 -> V_221 )
goto V_695;
F_67 ( V_5 -> V_216 , V_42 ) ;
V_5 -> V_217 |= V_696 ;
F_242 ( V_5 ) ;
F_68 ( V_5 -> V_216 , V_42 ) ;
F_254 ( V_5 ) ;
F_85 ( ! ( V_5 -> V_217 & V_697 ) ) ;
F_339 ( & V_5 -> V_639 ) ;
V_695:
F_214 (link, ap, HOST_FIRST) {
F_155 (dev, link, ALL) {
if ( F_269 ( V_15 ) )
F_340 ( V_15 ) ;
}
}
if ( V_5 -> V_11 ) {
int V_25 ;
for ( V_25 = 0 ; V_25 < V_698 ; V_25 ++ )
F_341 ( & V_5 -> V_11 [ V_25 ] ) ;
}
F_342 ( V_5 -> V_326 ) ;
F_330 ( V_5 ) ;
}
void F_343 ( struct V_556 * V_280 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_280 -> V_653 ; V_25 ++ )
F_338 ( V_280 -> V_654 [ V_25 ] ) ;
F_344 ( V_280 ) ;
}
void F_345 ( struct V_699 * V_700 )
{
struct V_556 * V_280 = F_346 ( V_700 ) ;
F_343 ( V_280 ) ;
}
int F_347 ( struct V_699 * V_700 , const struct V_701 * V_138 )
{
unsigned long V_424 = 0 ;
switch ( V_138 -> V_702 ) {
case 1 : {
T_2 V_703 = 0 ;
F_348 ( V_700 , V_138 -> V_599 , & V_703 ) ;
V_424 = V_703 ;
break;
}
case 2 : {
T_4 V_704 = 0 ;
F_349 ( V_700 , V_138 -> V_599 , & V_704 ) ;
V_424 = V_704 ;
break;
}
case 4 : {
T_1 V_705 = 0 ;
F_350 ( V_700 , V_138 -> V_599 , & V_705 ) ;
V_424 = V_705 ;
break;
}
default:
return - V_125 ;
}
V_424 &= V_138 -> V_428 ;
return ( V_424 == V_138 -> V_600 ) ? 1 : 0 ;
}
void F_351 ( struct V_699 * V_700 , T_6 V_603 )
{
F_352 ( V_700 ) ;
F_353 ( V_700 ) ;
if ( V_603 . V_706 & V_707 )
F_354 ( V_700 , V_708 ) ;
}
int F_355 ( struct V_699 * V_700 )
{
int V_188 ;
F_354 ( V_700 , V_709 ) ;
F_356 ( V_700 ) ;
V_188 = F_357 ( V_700 ) ;
if ( V_188 ) {
F_314 ( & V_700 -> V_15 ,
L_178 , V_188 ) ;
return V_188 ;
}
F_358 ( V_700 ) ;
return 0 ;
}
int F_359 ( struct V_699 * V_700 , T_6 V_603 )
{
struct V_556 * V_280 = F_346 ( V_700 ) ;
int V_188 = 0 ;
V_188 = F_274 ( V_280 , V_603 ) ;
if ( V_188 )
return V_188 ;
F_351 ( V_700 , V_603 ) ;
return 0 ;
}
int F_360 ( struct V_699 * V_700 )
{
struct V_556 * V_280 = F_346 ( V_700 ) ;
int V_188 ;
V_188 = F_355 ( V_700 ) ;
if ( V_188 == 0 )
F_275 ( V_280 ) ;
return V_188 ;
}
int F_361 ( struct V_710 * V_700 )
{
struct V_556 * V_280 = F_362 ( V_700 ) ;
F_343 ( V_280 ) ;
return 0 ;
}
static int T_9 F_363 ( char * * V_519 ,
struct V_27 * V_711 ,
const char * * V_262 )
{
static const struct V_712 V_713 [] V_714 = {
{ L_179 , . V_33 = V_408 } ,
{ L_180 , . V_33 = V_409 } ,
{ L_181 , . V_33 = V_555 } ,
{ L_182 , . V_33 = V_410 } ,
{ L_183 , . V_33 = V_411 } ,
{ L_184 , . V_33 = V_304 } ,
{ L_185 , . V_39 = 1 } ,
{ L_186 , . V_39 = 2 } ,
{ L_187 , . V_49 = V_324 } ,
{ L_188 , . V_50 = V_324 } ,
{ L_189 , . V_49 = V_310 } ,
{ L_190 , . V_50 = V_310 } ,
{ L_191 , . V_49 = V_277 } ,
{ L_192 , . V_47 = 1 << ( V_127 + 0 ) } ,
{ L_193 , . V_47 = 1 << ( V_127 + 1 ) } ,
{ L_194 , . V_47 = 1 << ( V_127 + 2 ) } ,
{ L_195 , . V_47 = 1 << ( V_127 + 3 ) } ,
{ L_196 , . V_47 = 1 << ( V_127 + 4 ) } ,
{ L_197 , . V_47 = 1 << ( V_127 + 5 ) } ,
{ L_198 , . V_47 = 1 << ( V_127 + 6 ) } ,
{ L_199 , . V_47 = 1 << ( V_129 + 0 ) } ,
{ L_200 , . V_47 = 1 << ( V_129 + 1 ) } ,
{ L_201 , . V_47 = 1 << ( V_129 + 2 ) } ,
{ L_202 , . V_47 = 1 << ( V_129 + 3 ) } ,
{ L_203 , . V_47 = 1 << ( V_129 + 4 ) } ,
{ L_204 , . V_47 = 1 << ( V_131 + 0 ) } ,
{ L_205 , . V_47 = 1 << ( V_131 + 0 ) } ,
{ L_206 , . V_47 = 1 << ( V_131 + 0 ) } ,
{ L_207 , . V_47 = 1 << ( V_131 + 1 ) } ,
{ L_208 , . V_47 = 1 << ( V_131 + 1 ) } ,
{ L_209 , . V_47 = 1 << ( V_131 + 1 ) } ,
{ L_210 , . V_47 = 1 << ( V_131 + 2 ) } ,
{ L_211 , . V_47 = 1 << ( V_131 + 2 ) } ,
{ L_212 , . V_47 = 1 << ( V_131 + 2 ) } ,
{ L_213 , . V_47 = 1 << ( V_131 + 3 ) } ,
{ L_214 , . V_47 = 1 << ( V_131 + 3 ) } ,
{ L_215 , . V_47 = 1 << ( V_131 + 3 ) } ,
{ L_216 , . V_47 = 1 << ( V_131 + 4 ) } ,
{ L_217 , . V_47 = 1 << ( V_131 + 4 ) } ,
{ L_218 , . V_47 = 1 << ( V_131 + 4 ) } ,
{ L_219 , . V_47 = 1 << ( V_131 + 5 ) } ,
{ L_220 , . V_47 = 1 << ( V_131 + 5 ) } ,
{ L_221 , . V_47 = 1 << ( V_131 + 5 ) } ,
{ L_222 , . V_47 = 1 << ( V_131 + 6 ) } ,
{ L_223 , . V_47 = 1 << ( V_131 + 6 ) } ,
{ L_224 , . V_47 = 1 << ( V_131 + 6 ) } ,
{ L_225 , . V_47 = 1 << ( V_131 + 7 ) } ,
{ L_226 , . V_41 = V_715 } ,
{ L_227 , . V_41 = V_716 } ,
{ L_228 , . V_41 = V_715 | V_716 } ,
{ L_229 , . V_41 = V_717 } ,
{ L_230 , . V_49 = V_394 } ,
{ L_231 , . V_49 = V_356 } ,
} ;
char * V_502 = * V_519 , * V_155 = * V_519 ;
char * V_150 , * V_600 , * V_718 ;
const struct V_712 * V_719 = NULL ;
int V_720 = 0 , V_25 ;
while ( * V_155 != '\0' && * V_155 != ',' )
V_155 ++ ;
if ( * V_155 == '\0' )
* V_519 = V_155 ;
else
* V_519 = V_155 + 1 ;
* V_155 = '\0' ;
V_155 = strchr ( V_502 , ':' ) ;
if ( ! V_155 ) {
V_600 = F_364 ( V_502 ) ;
goto V_721;
}
* V_155 = '\0' ;
V_150 = F_364 ( V_502 ) ;
V_600 = F_364 ( V_155 + 1 ) ;
V_155 = strchr ( V_150 , '.' ) ;
if ( V_155 ) {
* V_155 ++ = '\0' ;
V_711 -> V_21 = F_365 ( V_155 , & V_718 , 10 ) ;
if ( V_155 == V_718 || * V_718 != '\0' ) {
* V_262 = L_232 ;
return - V_125 ;
}
}
V_711 -> V_30 = F_365 ( V_150 , & V_718 , 10 ) ;
if ( V_150 == V_718 || * V_718 != '\0' ) {
* V_262 = L_233 ;
return - V_125 ;
}
V_721:
for ( V_25 = 0 ; V_25 < F_37 ( V_713 ) ; V_25 ++ ) {
const struct V_712 * V_722 = & V_713 [ V_25 ] ;
if ( strncasecmp ( V_600 , V_722 -> V_35 , strlen ( V_600 ) ) )
continue;
V_720 ++ ;
V_719 = V_722 ;
if ( strcasecmp ( V_600 , V_722 -> V_35 ) == 0 ) {
V_720 = 1 ;
break;
}
}
if ( ! V_720 ) {
* V_262 = L_234 ;
return - V_125 ;
}
if ( V_720 > 1 ) {
* V_262 = L_235 ;
return - V_125 ;
}
V_711 -> V_32 = * V_719 ;
return 0 ;
}
static void T_9 F_366 ( void )
{
int V_723 = 0 , V_724 = 1 ;
int V_725 = - 1 , V_726 = - 1 ;
char * V_155 , * V_519 , * V_23 ;
for ( V_155 = V_727 ; * V_155 ; V_155 ++ )
if ( * V_155 == ',' )
V_724 ++ ;
V_29 = F_281 ( sizeof( V_29 [ 0 ] ) * V_724 , V_627 ) ;
if ( ! V_29 ) {
F_367 ( V_728 L_236
L_237 ) ;
return;
}
for ( V_519 = V_727 ; * V_519 != '\0' ; V_519 = V_23 ) {
const char * V_262 = L_68 ;
struct V_27 V_729 = { . V_30 = - 1 , . V_21 = - 1 } ;
V_23 = V_519 ;
if ( F_363 ( & V_23 , & V_729 , & V_262 ) ) {
F_367 ( V_728 L_238
L_239 ,
V_519 , V_262 ) ;
continue;
}
if ( V_729 . V_30 == - 1 ) {
V_729 . V_30 = V_725 ;
V_729 . V_21 = V_726 ;
}
V_29 [ V_723 ++ ] = V_729 ;
V_725 = V_729 . V_30 ;
V_726 = V_729 . V_21 ;
}
V_26 = V_723 ;
}
static int T_9 F_368 ( void )
{
int V_188 ;
F_366 () ;
V_188 = F_369 () ;
if ( V_188 ) {
F_295 ( V_29 ) ;
return V_188 ;
}
F_370 () ;
V_730 = F_371 () ;
if ( ! V_730 ) {
F_372 () ;
V_188 = - V_666 ;
goto V_271;
}
F_367 ( V_278 L_240 V_731 L_241 ) ;
return 0 ;
V_271:
return V_188 ;
}
static void T_10 F_373 ( void )
{
F_374 ( V_730 ) ;
F_375 () ;
F_372 () ;
F_295 ( V_29 ) ;
}
int F_376 ( void )
{
return F_377 ( & V_732 ) ;
}
void F_190 ( struct V_4 * V_5 , unsigned int V_733 )
{
bool V_734 = V_5 && V_5 -> V_280 -> V_735 == V_736 ;
if ( V_734 )
F_75 ( V_5 ) ;
if ( V_733 < 20 ) {
unsigned long V_737 = V_733 * V_738 ;
F_378 ( V_737 , V_737 + 50 ) ;
} else {
F_196 ( V_733 ) ;
}
if ( V_734 )
F_78 ( V_5 ) ;
}
T_1 F_379 ( struct V_4 * V_5 , void T_11 * V_599 , T_1 V_428 , T_1 V_600 ,
unsigned long V_515 , unsigned long V_209 )
{
unsigned long V_501 ;
T_1 V_424 ;
V_424 = F_380 ( V_599 ) ;
V_501 = F_185 ( V_503 , V_209 ) ;
while ( ( V_424 & V_428 ) == V_600 && F_189 ( V_503 , V_501 ) ) {
F_190 ( V_5 , V_515 ) ;
V_424 = F_380 ( V_599 ) ;
}
return V_424 ;
}
bool F_381 ( struct V_2 * V_3 )
{
unsigned long V_739 = V_3 -> V_740 +
F_77 ( V_741 ) ;
if ( V_3 -> V_742 > V_363 )
return true ;
if ( ( V_3 -> V_42 & V_743 ) &&
F_189 ( V_503 , V_739 ) )
return true ;
return false ;
}
static unsigned int F_382 ( struct V_199 * V_200 )
{
return V_219 ;
}
static void F_383 ( struct V_4 * V_5 )
{
}
void F_384 ( const struct V_4 * V_5 , const char * V_744 ,
const char * V_745 , ... )
{
struct V_746 V_747 ;
T_12 args ;
va_start ( args , V_745 ) ;
V_747 . V_745 = V_745 ;
V_747 . V_748 = & args ;
F_367 ( L_242 , V_744 , V_5 -> V_31 , & V_747 ) ;
va_end ( args ) ;
}
void F_385 ( const struct V_2 * V_3 , const char * V_744 ,
const char * V_745 , ... )
{
struct V_746 V_747 ;
T_12 args ;
va_start ( args , V_745 ) ;
V_747 . V_745 = V_745 ;
V_747 . V_748 = & args ;
if ( F_4 ( V_3 -> V_5 ) || V_3 -> V_5 -> V_12 )
F_367 ( L_243 ,
V_744 , V_3 -> V_5 -> V_31 , V_3 -> V_38 , & V_747 ) ;
else
F_367 ( L_242 ,
V_744 , V_3 -> V_5 -> V_31 , & V_747 ) ;
va_end ( args ) ;
}
void F_386 ( const struct V_14 * V_15 , const char * V_744 ,
const char * V_745 , ... )
{
struct V_746 V_747 ;
T_12 args ;
va_start ( args , V_745 ) ;
V_747 . V_745 = V_745 ;
V_747 . V_748 = & args ;
F_367 ( L_243 ,
V_744 , V_15 -> V_3 -> V_5 -> V_31 , V_15 -> V_3 -> V_38 + V_15 -> V_24 ,
& V_747 ) ;
va_end ( args ) ;
}
void F_387 ( const struct V_21 * V_15 , const char * V_749 )
{
F_388 ( V_278 , V_15 , L_244 , V_749 ) ;
}
