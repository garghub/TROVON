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
T_3 F_23 ( struct V_67 * V_68 , struct V_14 * V_15 )
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
V_103 = 1 ;
}
V_99 = ( V_101 * V_15 -> V_104 + V_102 ) * V_15 -> V_105 + V_103 - 1 ;
}
return V_99 ;
}
int F_25 ( struct V_67 * V_68 , struct V_14 * V_15 ,
T_3 V_99 , T_1 V_106 , unsigned int V_107 ,
unsigned int V_108 )
{
V_68 -> V_42 |= V_109 | V_110 ;
V_68 -> V_42 |= V_107 ;
if ( F_26 ( V_15 ) && F_27 ( V_108 != V_111 ) ) {
if ( ! F_28 ( V_99 , V_106 ) )
return - V_112 ;
V_68 -> V_93 = V_113 ;
V_68 -> V_42 |= V_100 | V_90 ;
if ( V_68 -> V_42 & V_91 )
V_68 -> V_71 = V_114 ;
else
V_68 -> V_71 = V_115 ;
V_68 -> V_80 = V_108 << 3 ;
V_68 -> V_79 = ( V_106 >> 8 ) & 0xff ;
V_68 -> V_72 = V_106 & 0xff ;
V_68 -> V_78 = ( V_99 >> 40 ) & 0xff ;
V_68 -> V_77 = ( V_99 >> 32 ) & 0xff ;
V_68 -> V_76 = ( V_99 >> 24 ) & 0xff ;
V_68 -> V_75 = ( V_99 >> 16 ) & 0xff ;
V_68 -> V_74 = ( V_99 >> 8 ) & 0xff ;
V_68 -> V_73 = V_99 & 0xff ;
V_68 -> V_21 = V_116 ;
if ( V_68 -> V_42 & V_89 )
V_68 -> V_21 |= 1 << 7 ;
} else if ( V_15 -> V_42 & V_117 ) {
V_68 -> V_42 |= V_100 ;
if ( F_29 ( V_99 , V_106 ) ) {
V_68 -> V_21 |= ( V_99 >> 24 ) & 0xf ;
} else if ( F_28 ( V_99 , V_106 ) ) {
if ( ! ( V_15 -> V_42 & V_118 ) )
return - V_112 ;
V_68 -> V_42 |= V_90 ;
V_68 -> V_81 = ( V_106 >> 8 ) & 0xff ;
V_68 -> V_78 = ( V_99 >> 40 ) & 0xff ;
V_68 -> V_77 = ( V_99 >> 32 ) & 0xff ;
V_68 -> V_76 = ( V_99 >> 24 ) & 0xff ;
} else
return - V_112 ;
if ( F_5 ( F_22 ( V_68 , V_15 ) < 0 ) )
return - V_119 ;
V_68 -> V_80 = V_106 & 0xff ;
V_68 -> V_75 = ( V_99 >> 16 ) & 0xff ;
V_68 -> V_74 = ( V_99 >> 8 ) & 0xff ;
V_68 -> V_73 = V_99 & 0xff ;
V_68 -> V_21 |= V_116 ;
} else {
T_1 V_103 , V_102 , V_101 , V_120 ;
if ( ! F_29 ( V_99 , V_106 ) )
return - V_112 ;
if ( F_5 ( F_22 ( V_68 , V_15 ) < 0 ) )
return - V_119 ;
V_120 = ( T_1 ) V_99 / V_15 -> V_105 ;
V_101 = V_120 / V_15 -> V_104 ;
V_102 = V_120 % V_15 -> V_104 ;
V_103 = ( T_1 ) V_99 % V_15 -> V_105 + 1 ;
F_30 ( L_7 ,
( T_1 ) V_99 , V_120 , V_101 , V_102 , V_103 ) ;
if ( ( V_101 >> 16 ) || ( V_102 >> 4 ) || ( V_103 >> 8 ) || ( ! V_103 ) )
return - V_112 ;
V_68 -> V_80 = V_106 & 0xff ;
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
return ( ( V_44 << V_121 ) & V_122 ) |
( ( V_45 << V_123 ) & V_124 ) |
( ( V_46 << V_125 ) & V_126 ) ;
}
void F_16 ( unsigned long V_47 , unsigned long * V_44 ,
unsigned long * V_45 , unsigned long * V_46 )
{
if ( V_44 )
* V_44 = ( V_47 & V_122 ) >> V_121 ;
if ( V_45 )
* V_45 = ( V_47 & V_124 ) >> V_123 ;
if ( V_46 )
* V_46 = ( V_47 & V_126 ) >> V_125 ;
}
T_2 F_32 ( unsigned long V_47 )
{
int V_127 = F_33 ( V_47 ) - 1 ;
const struct V_128 * V_129 ;
for ( V_129 = V_130 ; V_129 -> V_131 >= 0 ; V_129 ++ )
if ( V_127 >= V_129 -> V_131 && V_127 < V_129 -> V_131 + V_129 -> V_132 )
return V_129 -> V_133 + V_127 - V_129 -> V_131 ;
return 0xff ;
}
unsigned long F_34 ( T_2 V_134 )
{
const struct V_128 * V_129 ;
for ( V_129 = V_130 ; V_129 -> V_131 >= 0 ; V_129 ++ )
if ( V_134 >= V_129 -> V_133 && V_134 < V_129 -> V_133 + V_129 -> V_132 )
return ( ( 2 << ( V_129 -> V_131 + V_134 - V_129 -> V_133 ) ) - 1 )
& ~ ( ( 1 << V_129 -> V_131 ) - 1 ) ;
return 0 ;
}
int F_35 ( unsigned long V_134 )
{
const struct V_128 * V_129 ;
for ( V_129 = V_130 ; V_129 -> V_131 >= 0 ; V_129 ++ )
if ( V_134 >= V_129 -> V_133 && V_134 < V_129 -> V_133 + V_129 -> V_132 )
return V_129 -> V_131 ;
return - 1 ;
}
const char * F_36 ( unsigned long V_47 )
{
static const char * const V_135 [] = {
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
int V_127 ;
V_127 = F_33 ( V_47 ) - 1 ;
if ( V_127 >= 0 && V_127 < F_37 ( V_135 ) )
return V_135 [ V_127 ] ;
return L_28 ;
}
const char * F_38 ( unsigned int V_136 )
{
static const char * const V_137 [] = {
L_29 ,
L_30 ,
L_31 ,
} ;
if ( V_136 == 0 || ( V_136 - 1 ) >= F_37 ( V_137 ) )
return L_32 ;
return V_137 [ V_136 - 1 ] ;
}
unsigned int F_39 ( const struct V_67 * V_68 )
{
if ( ( V_68 -> V_74 == 0 ) && ( V_68 -> V_75 == 0 ) ) {
F_30 ( L_33 ) ;
return V_138 ;
}
if ( ( V_68 -> V_74 == 0x14 ) && ( V_68 -> V_75 == 0xeb ) ) {
F_30 ( L_34 ) ;
return V_139 ;
}
if ( ( V_68 -> V_74 == 0x69 ) && ( V_68 -> V_75 == 0x96 ) ) {
F_30 ( L_35 ) ;
return V_140 ;
}
if ( ( V_68 -> V_74 == 0x3c ) && ( V_68 -> V_75 == 0xc3 ) ) {
F_30 ( L_36 ) ;
return V_141 ;
}
if ( ( V_68 -> V_74 == 0xcd ) && ( V_68 -> V_75 == 0xab ) ) {
F_30 ( L_37 ) ;
return V_142 ;
}
F_30 ( L_38 ) ;
return V_143 ;
}
void F_40 ( const T_4 * V_144 , unsigned char * V_145 ,
unsigned int V_146 , unsigned int V_147 )
{
unsigned int V_148 ;
F_3 ( V_147 & 1 ) ;
while ( V_147 > 0 ) {
V_148 = V_144 [ V_146 ] >> 8 ;
* V_145 = V_148 ;
V_145 ++ ;
V_148 = V_144 [ V_146 ] & 0xff ;
* V_145 = V_148 ;
V_145 ++ ;
V_146 ++ ;
V_147 -= 2 ;
}
}
void F_41 ( const T_4 * V_144 , unsigned char * V_145 ,
unsigned int V_146 , unsigned int V_147 )
{
unsigned char * V_149 ;
F_40 ( V_144 , V_145 , V_146 , V_147 - 1 ) ;
V_149 = V_145 + F_42 ( V_145 , V_147 - 1 ) ;
while ( V_149 > V_145 && V_149 [ - 1 ] == ' ' )
V_149 -- ;
* V_149 = '\0' ;
}
static T_3 F_43 ( const T_4 * V_144 )
{
if ( F_44 ( V_144 ) ) {
if ( F_45 ( V_144 ) )
return F_46 ( V_144 , V_150 ) ;
else
return F_47 ( V_144 , V_151 ) ;
} else {
if ( F_48 ( V_144 ) )
return V_144 [ V_152 ] * V_144 [ V_153 ] *
V_144 [ V_154 ] ;
else
return V_144 [ V_155 ] * V_144 [ V_156 ] *
V_144 [ V_157 ] ;
}
}
T_3 F_49 ( const struct V_67 * V_68 )
{
T_3 V_105 = 0 ;
V_105 |= ( ( T_3 ) ( V_68 -> V_78 & 0xff ) ) << 40 ;
V_105 |= ( ( T_3 ) ( V_68 -> V_77 & 0xff ) ) << 32 ;
V_105 |= ( ( T_3 ) ( V_68 -> V_76 & 0xff ) ) << 24 ;
V_105 |= ( V_68 -> V_75 & 0xff ) << 16 ;
V_105 |= ( V_68 -> V_74 & 0xff ) << 8 ;
V_105 |= ( V_68 -> V_73 & 0xff ) ;
return V_105 ;
}
T_3 F_50 ( const struct V_67 * V_68 )
{
T_3 V_105 = 0 ;
V_105 |= ( V_68 -> V_21 & 0x0f ) << 24 ;
V_105 |= ( V_68 -> V_75 & 0xff ) << 16 ;
V_105 |= ( V_68 -> V_74 & 0xff ) << 8 ;
V_105 |= ( V_68 -> V_73 & 0xff ) ;
return V_105 ;
}
static int F_51 ( struct V_14 * V_15 , T_3 * V_158 )
{
unsigned int V_159 ;
struct V_67 V_68 ;
int V_87 = F_45 ( V_15 -> V_144 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_42 |= V_110 | V_109 ;
if ( V_87 ) {
V_68 . V_71 = V_160 ;
V_68 . V_42 |= V_90 ;
} else
V_68 . V_71 = V_161 ;
V_68 . V_93 |= V_162 ;
V_68 . V_21 |= V_116 ;
V_159 = F_53 ( V_15 , & V_68 , NULL , V_163 , NULL , 0 , 0 ) ;
if ( V_159 ) {
F_24 ( V_15 ,
L_39 ,
V_159 ) ;
if ( V_159 == V_164 && ( V_68 . V_72 & V_165 ) )
return - V_166 ;
return - V_167 ;
}
if ( V_87 )
* V_158 = F_49 ( & V_68 ) + 1 ;
else
* V_158 = F_50 ( & V_68 ) + 1 ;
if ( V_15 -> V_48 & V_168 )
( * V_158 ) -- ;
return 0 ;
}
static int F_54 ( struct V_14 * V_15 , T_3 V_169 )
{
unsigned int V_159 ;
struct V_67 V_68 ;
int V_87 = F_45 ( V_15 -> V_144 ) ;
V_169 -- ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_42 |= V_110 | V_109 ;
if ( V_87 ) {
V_68 . V_71 = V_170 ;
V_68 . V_42 |= V_90 ;
V_68 . V_76 = ( V_169 >> 24 ) & 0xff ;
V_68 . V_77 = ( V_169 >> 32 ) & 0xff ;
V_68 . V_78 = ( V_169 >> 40 ) & 0xff ;
} else {
V_68 . V_71 = V_171 ;
V_68 . V_21 |= ( V_169 >> 24 ) & 0xf ;
}
V_68 . V_93 |= V_162 ;
V_68 . V_21 |= V_116 ;
V_68 . V_73 = ( V_169 >> 0 ) & 0xff ;
V_68 . V_74 = ( V_169 >> 8 ) & 0xff ;
V_68 . V_75 = ( V_169 >> 16 ) & 0xff ;
V_159 = F_53 ( V_15 , & V_68 , NULL , V_163 , NULL , 0 , 0 ) ;
if ( V_159 ) {
F_24 ( V_15 ,
L_40 ,
V_159 ) ;
if ( V_159 == V_164 &&
( V_68 . V_72 & ( V_165 | V_172 ) ) )
return - V_166 ;
return - V_167 ;
}
return 0 ;
}
static int F_55 ( struct V_14 * V_15 )
{
struct V_173 * V_174 = & V_15 -> V_3 -> V_175 ;
int V_176 = V_174 -> V_25 . V_42 & V_177 ;
bool V_178 = V_179 || V_15 -> V_42 & V_180 ;
T_3 V_105 = F_43 ( V_15 -> V_144 ) ;
T_3 V_181 ;
int V_182 ;
if ( ( V_15 -> V_183 != V_138 && V_15 -> V_183 != V_142 ) ||
! F_44 ( V_15 -> V_144 ) || ! F_56 ( V_15 -> V_144 ) ||
( V_15 -> V_48 & V_184 ) )
return 0 ;
V_182 = F_51 ( V_15 , & V_181 ) ;
if ( V_182 ) {
if ( V_182 == - V_166 || ! V_178 ) {
F_24 ( V_15 ,
L_41 ) ;
V_15 -> V_48 |= V_184 ;
if ( V_182 == - V_166 )
V_182 = 0 ;
}
return V_182 ;
}
V_15 -> V_185 = V_181 ;
if ( V_181 <= V_105 || ! V_178 ) {
if ( ! V_176 || V_181 == V_105 )
return 0 ;
if ( V_181 > V_105 )
F_57 ( V_15 ,
L_42 ,
( unsigned long long ) V_105 ,
( unsigned long long ) V_181 ) ;
else if ( V_181 < V_105 )
F_24 ( V_15 ,
L_43 ,
( unsigned long long ) V_181 ,
( unsigned long long ) V_105 ) ;
return 0 ;
}
V_182 = F_54 ( V_15 , V_181 ) ;
if ( V_182 == - V_166 ) {
F_24 ( V_15 ,
L_44 ,
( unsigned long long ) V_105 ,
( unsigned long long ) V_181 ) ;
V_15 -> V_48 |= V_184 ;
return 0 ;
} else if ( V_182 )
return V_182 ;
V_182 = F_58 ( V_15 , 0 ) ;
if ( V_182 ) {
F_59 ( V_15 ,
L_45 ) ;
return V_182 ;
}
if ( V_176 ) {
T_3 V_169 = F_43 ( V_15 -> V_144 ) ;
F_57 ( V_15 ,
L_46 ,
( unsigned long long ) V_105 ,
( unsigned long long ) V_169 ,
( unsigned long long ) V_181 ) ;
}
return 0 ;
}
static inline void F_60 ( const T_4 * V_144 )
{
F_30 ( L_47
L_48
L_49
L_50
L_51 ,
V_144 [ 49 ] ,
V_144 [ 53 ] ,
V_144 [ 63 ] ,
V_144 [ 64 ] ,
V_144 [ 75 ] ) ;
F_30 ( L_52
L_53
L_54
L_55
L_56 ,
V_144 [ 80 ] ,
V_144 [ 81 ] ,
V_144 [ 82 ] ,
V_144 [ 83 ] ,
V_144 [ 84 ] ) ;
F_30 ( L_57
L_58 ,
V_144 [ 88 ] ,
V_144 [ 93 ] ) ;
}
unsigned long F_61 ( const T_4 * V_144 )
{
unsigned long V_44 , V_45 , V_46 ;
if ( V_144 [ V_186 ] & ( 1 << 1 ) ) {
V_44 = V_144 [ V_187 ] & 0x03 ;
V_44 <<= 3 ;
V_44 |= 0x7 ;
} else {
T_2 V_7 = ( V_144 [ V_188 ] >> 8 ) & 0xFF ;
if ( V_7 < 5 )
V_44 = ( 2 << V_7 ) - 1 ;
else
V_44 = 1 ;
}
V_45 = V_144 [ V_189 ] & 0x07 ;
if ( F_62 ( V_144 ) ) {
int V_190 = ( V_144 [ V_191 ] >> 0 ) & 0x7 ;
int V_192 = ( V_144 [ V_191 ] >> 3 ) & 0x7 ;
if ( V_190 )
V_44 |= ( 1 << 5 ) ;
if ( V_190 > 1 )
V_44 |= ( 1 << 6 ) ;
if ( V_192 )
V_45 |= ( 1 << 3 ) ;
if ( V_192 > 1 )
V_45 |= ( 1 << 4 ) ;
}
V_46 = 0 ;
if ( V_144 [ V_186 ] & ( 1 << 2 ) )
V_46 = V_144 [ V_193 ] & 0xff ;
return F_31 ( V_44 , V_45 , V_46 ) ;
}
static void F_63 ( struct V_194 * V_195 )
{
struct V_196 * V_197 = V_195 -> V_198 ;
F_64 ( V_197 ) ;
}
unsigned F_65 ( struct V_14 * V_15 ,
struct V_67 * V_68 , const T_2 * V_199 ,
int V_200 , struct V_201 * V_202 ,
unsigned int V_203 , unsigned long V_204 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
T_2 V_71 = V_68 -> V_71 ;
int V_205 = 0 ;
struct V_194 * V_195 ;
unsigned int V_108 , V_206 ;
T_1 V_207 , V_208 ;
int V_209 ;
F_66 ( V_210 ) ;
unsigned long V_42 ;
unsigned int V_159 ;
int V_182 ;
F_67 ( V_5 -> V_211 , V_42 ) ;
if ( V_5 -> V_212 & V_213 ) {
F_68 ( V_5 -> V_211 , V_42 ) ;
return V_214 ;
}
if ( V_5 -> V_215 -> V_216 )
V_108 = V_111 ;
else
V_108 = 0 ;
if ( F_69 ( V_108 , & V_5 -> V_217 ) )
F_70 () ;
V_195 = F_71 ( V_5 , V_108 ) ;
V_195 -> V_108 = V_108 ;
V_195 -> V_218 = NULL ;
V_195 -> V_5 = V_5 ;
V_195 -> V_15 = V_15 ;
F_72 ( V_195 ) ;
V_206 = V_3 -> V_219 ;
V_207 = V_3 -> V_220 ;
V_208 = V_5 -> V_221 ;
V_209 = V_5 -> V_222 ;
V_3 -> V_219 = V_223 ;
V_3 -> V_220 = 0 ;
V_5 -> V_221 = 0 ;
V_5 -> V_222 = 0 ;
V_195 -> V_68 = * V_68 ;
if ( V_199 )
memcpy ( V_195 -> V_199 , V_199 , V_224 ) ;
if ( V_68 -> V_93 == V_225 && ( V_15 -> V_42 & V_226 ) &&
V_200 == V_227 )
V_195 -> V_68 . V_72 |= V_228 ;
V_195 -> V_42 |= V_229 ;
V_195 -> V_200 = V_200 ;
if ( V_200 != V_163 ) {
unsigned int V_25 , V_230 = 0 ;
struct V_201 * V_231 ;
F_73 (sgl, sg, n_elem, i)
V_230 += V_231 -> V_232 ;
F_74 ( V_195 , V_202 , V_203 ) ;
V_195 -> V_233 = V_230 ;
}
V_195 -> V_198 = & V_210 ;
V_195 -> V_234 = F_63 ;
F_75 ( V_195 ) ;
F_68 ( V_5 -> V_211 , V_42 ) ;
if ( ! V_204 ) {
if ( V_235 )
V_204 = V_235 * 1000 ;
else {
V_204 = F_76 ( V_15 , V_71 ) ;
V_205 = 1 ;
}
}
if ( V_5 -> V_215 -> V_216 )
F_77 ( V_5 ) ;
V_182 = F_78 ( & V_210 , F_79 ( V_204 ) ) ;
if ( V_5 -> V_215 -> V_216 )
F_80 ( V_5 ) ;
F_81 ( V_5 ) ;
if ( ! V_182 ) {
F_67 ( V_5 -> V_211 , V_42 ) ;
if ( V_195 -> V_42 & V_236 ) {
V_195 -> V_159 |= V_237 ;
if ( V_5 -> V_215 -> V_216 )
F_82 ( V_5 ) ;
else
F_83 ( V_195 ) ;
if ( F_84 ( V_5 ) )
F_24 ( V_15 , L_59 ,
V_71 ) ;
}
F_68 ( V_5 -> V_211 , V_42 ) ;
}
if ( V_5 -> V_215 -> V_238 )
V_5 -> V_215 -> V_238 ( V_195 ) ;
if ( V_195 -> V_42 & V_239 ) {
if ( V_195 -> V_240 . V_71 & ( V_241 | V_242 ) )
V_195 -> V_159 |= V_164 ;
if ( ! V_195 -> V_159 )
V_195 -> V_159 |= V_243 ;
if ( V_195 -> V_159 & ~ V_243 )
V_195 -> V_159 &= ~ V_243 ;
}
F_67 ( V_5 -> V_211 , V_42 ) ;
* V_68 = V_195 -> V_240 ;
V_159 = V_195 -> V_159 ;
F_85 ( V_195 ) ;
V_3 -> V_219 = V_206 ;
V_3 -> V_220 = V_207 ;
V_5 -> V_221 = V_208 ;
V_5 -> V_222 = V_209 ;
F_68 ( V_5 -> V_211 , V_42 ) ;
if ( ( V_159 & V_237 ) && V_205 )
F_86 ( V_15 , V_71 ) ;
return V_159 ;
}
unsigned F_53 ( struct V_14 * V_15 ,
struct V_67 * V_68 , const T_2 * V_199 ,
int V_200 , void * V_244 , unsigned int V_230 ,
unsigned long V_204 )
{
struct V_201 * V_245 = NULL , V_231 ;
unsigned int V_203 = 0 ;
if ( V_200 != V_163 ) {
F_87 ( ! V_244 ) ;
F_88 ( & V_231 , V_244 , V_230 ) ;
V_245 = & V_231 ;
V_203 ++ ;
}
return F_65 ( V_15 , V_68 , V_199 , V_200 , V_245 , V_203 ,
V_204 ) ;
}
unsigned int F_89 ( struct V_14 * V_15 , T_2 V_84 )
{
struct V_67 V_68 ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_84 ;
V_68 . V_42 |= V_110 ;
V_68 . V_93 = V_162 ;
return F_53 ( V_15 , & V_68 , NULL , V_163 , NULL , 0 , 0 ) ;
}
unsigned int F_90 ( const struct V_14 * V_246 )
{
if ( V_246 -> V_3 -> V_5 -> V_212 & V_247 )
return 0 ;
if ( V_246 -> V_3 -> V_5 -> V_42 & V_248 )
return 0 ;
if ( F_62 ( V_246 -> V_144 )
&& ( V_246 -> V_249 == V_250 || V_246 -> V_249 == V_251 ) )
return 0 ;
if ( V_246 -> V_249 > V_252 )
return 1 ;
if ( F_91 ( V_246 -> V_144 ) )
return 1 ;
return 0 ;
}
static T_1 F_92 ( const struct V_14 * V_246 )
{
if ( V_246 -> V_144 [ V_186 ] & 2 ) {
T_4 V_190 = V_246 -> V_144 [ V_253 ] ;
if ( V_190 ) {
if ( V_190 > 240 )
return 3 << V_121 ;
return 7 << V_121 ;
}
}
return 3 << V_121 ;
}
unsigned int F_93 ( struct V_14 * V_15 ,
struct V_67 * V_68 , T_4 * V_144 )
{
return F_53 ( V_15 , V_68 , NULL , V_227 ,
V_144 , sizeof( V_144 [ 0 ] ) * V_254 , 0 ) ;
}
int F_94 ( struct V_14 * V_15 , unsigned int * V_255 ,
unsigned int V_42 , T_4 * V_144 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
unsigned int V_183 = * V_255 ;
struct V_67 V_68 ;
unsigned int V_159 = 0 ;
const char * V_256 ;
bool V_257 = V_183 == V_141 ;
int V_258 = 1 , V_259 = 0 ;
int V_182 ;
if ( F_95 ( V_5 ) )
F_96 ( V_15 , L_60 , V_260 ) ;
V_261:
F_52 ( V_15 , & V_68 ) ;
switch ( V_183 ) {
case V_141 :
V_183 = V_138 ;
case V_138 :
case V_142 :
V_68 . V_71 = V_262 ;
break;
case V_139 :
V_68 . V_71 = V_263 ;
break;
default:
V_182 = - V_264 ;
V_256 = L_61 ;
goto V_265;
}
V_68 . V_93 = V_94 ;
V_68 . V_42 |= V_109 | V_110 ;
V_68 . V_42 |= V_266 ;
if ( V_5 -> V_215 -> V_267 )
V_159 = V_5 -> V_215 -> V_267 ( V_15 , & V_68 , V_144 ) ;
else
V_159 = F_93 ( V_15 , & V_68 , V_144 ) ;
if ( V_159 ) {
if ( V_159 & V_268 ) {
F_96 ( V_15 , L_62 ) ;
return - V_269 ;
}
if ( V_257 ) {
F_57 ( V_15 ,
L_63 ) ;
* V_255 = V_270 ;
return 0 ;
}
if ( ( V_159 == V_164 ) && ( V_68 . V_72 & V_165 ) ) {
if ( V_258 ) {
V_258 = 0 ;
if ( V_183 == V_138 )
V_183 = V_139 ;
else
V_183 = V_138 ;
goto V_261;
}
F_96 ( V_15 ,
L_64 ) ;
return - V_269 ;
}
V_182 = - V_167 ;
V_256 = L_65 ;
goto V_265;
}
if ( V_15 -> V_48 & V_271 ) {
F_96 ( V_15 , L_66
L_67 ,
V_183 , V_258 , V_259 ) ;
F_97 ( V_272 , L_68 , V_273 ,
16 , 2 , V_144 , V_254 * sizeof( * V_144 ) , true ) ;
}
V_258 = 0 ;
F_98 ( V_144 , V_254 ) ;
V_182 = - V_119 ;
V_256 = L_69 ;
if ( V_183 == V_138 || V_183 == V_142 ) {
if ( ! F_99 ( V_144 ) && ! F_62 ( V_144 ) )
goto V_265;
if ( V_5 -> V_274 -> V_42 & V_275 &&
F_99 ( V_144 ) ) {
F_96 ( V_15 ,
L_70 ) ;
return - V_269 ;
}
} else {
if ( F_99 ( V_144 ) )
goto V_265;
}
if ( ! V_259 && ( V_144 [ 2 ] == 0x37c8 || V_144 [ 2 ] == 0x738c ) ) {
V_259 = 1 ;
V_159 = F_100 ( V_15 , V_276 , 0 ) ;
if ( V_159 && V_144 [ 2 ] != 0x738c ) {
V_182 = - V_167 ;
V_256 = L_71 ;
goto V_265;
}
if ( V_144 [ 2 ] == 0x37c8 )
goto V_261;
}
if ( ( V_42 & V_277 ) &&
( V_183 == V_138 || V_183 == V_142 ) ) {
if ( F_101 ( V_144 ) < 4 || ! F_44 ( V_144 ) ) {
V_159 = F_102 ( V_15 , V_144 [ 3 ] , V_144 [ 6 ] ) ;
if ( V_159 ) {
V_182 = - V_167 ;
V_256 = L_72 ;
goto V_265;
}
V_42 &= ~ V_277 ;
goto V_261;
}
}
* V_255 = V_183 ;
return 0 ;
V_265:
if ( F_84 ( V_5 ) )
F_24 ( V_15 , L_73 ,
V_256 , V_159 ) ;
return V_182 ;
}
static int F_103 ( struct V_14 * V_15 )
{
struct V_2 * V_278 = F_9 ( V_15 ) ;
T_1 V_279 , V_280 ;
if ( ! F_104 ( V_278 ) )
return 0 ;
if ( V_15 -> V_48 & V_281 )
V_279 = 1 ;
else
return 0 ;
V_280 = ( 1 << V_279 ) - 1 ;
if ( V_278 -> V_282 <= V_280 )
return 0 ;
V_278 -> V_282 = V_280 ;
if ( V_278 -> V_283 > V_279 ) {
F_57 ( V_15 , L_74 ,
F_38 ( V_279 ) ) ;
return - V_284 ;
}
return 0 ;
}
static inline T_2 F_105 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
if ( F_106 ( V_15 ) & V_285 )
return 0 ;
return ( ( V_5 -> V_33 == V_286 ) && ( ! F_107 ( V_15 -> V_144 ) ) ) ;
}
static int F_108 ( struct V_14 * V_15 ,
char * V_287 , T_5 V_288 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
int V_289 = 0 , V_290 = F_109 ( V_15 -> V_144 ) ;
unsigned int V_159 ;
char * V_291 = L_68 ;
if ( ! F_110 ( V_15 -> V_144 ) ) {
V_287 [ 0 ] = '\0' ;
return 0 ;
}
if ( V_15 -> V_48 & V_292 ) {
snprintf ( V_287 , V_288 , L_75 ) ;
return 0 ;
}
if ( V_5 -> V_42 & V_293 ) {
V_289 = F_111 ( V_5 -> V_294 -> V_295 , V_296 - 1 ) ;
V_15 -> V_42 |= V_297 ;
}
if ( ! ( V_15 -> V_48 & V_298 ) &&
( V_5 -> V_42 & V_299 ) &&
F_112 ( V_15 -> V_144 ) ) {
V_159 = F_100 ( V_15 , V_300 ,
V_301 ) ;
if ( V_159 ) {
F_59 ( V_15 ,
L_76 ,
V_159 ) ;
if ( V_159 != V_164 ) {
V_15 -> V_48 |= V_298 ;
return - V_167 ;
}
} else
V_291 = L_77 ;
}
if ( V_289 >= V_290 )
snprintf ( V_287 , V_288 , L_78 , V_290 , V_291 ) ;
else
snprintf ( V_287 , V_288 , L_79 , V_289 ,
V_290 , V_291 ) ;
if ( ( V_5 -> V_42 & V_302 ) &&
F_113 ( V_15 -> V_144 ) ) {
V_159 = F_114 ( V_15 , V_303 ,
0 , V_5 -> V_304 , 1 ) ;
if ( V_159 ) {
F_96 ( V_15 ,
L_80 ,
V_159 ) ;
} else {
T_2 * V_305 = V_15 -> V_306 ;
V_15 -> V_42 |= V_307 ;
memcpy ( V_305 , V_5 -> V_304 , V_308 ) ;
if ( V_15 -> V_48 & V_309 ) {
F_96 ( V_15 , L_81 ) ;
V_305 [ V_310 ] &=
~ V_311 ;
}
}
}
return 0 ;
}
int F_115 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_173 * V_174 = & V_15 -> V_3 -> V_175 ;
int V_176 = V_174 -> V_25 . V_42 & V_177 ;
const T_4 * V_144 = V_15 -> V_144 ;
unsigned long V_47 ;
unsigned int V_159 ;
char V_312 [ 7 ] ;
char V_313 [ V_314 + 1 ] ;
char V_315 [ V_316 + 1 ] ;
int V_182 ;
if ( ! F_8 ( V_15 ) && F_116 ( V_5 ) ) {
F_57 ( V_15 , L_82 , V_260 ) ;
return 0 ;
}
if ( F_117 ( V_5 ) )
F_96 ( V_15 , L_60 , V_260 ) ;
V_15 -> V_48 |= F_106 ( V_15 ) ;
F_18 ( V_15 ) ;
if ( V_15 -> V_48 & V_317 ) {
F_57 ( V_15 , L_83 ) ;
F_118 ( V_15 ) ;
return 0 ;
}
if ( ( ! V_318 || ( V_5 -> V_42 & V_319 ) ) &&
V_15 -> V_183 == V_139 ) {
F_24 ( V_15 , L_84 ,
V_318 ? L_85
: L_86 ) ;
F_118 ( V_15 ) ;
return 0 ;
}
V_182 = F_103 ( V_15 ) ;
if ( V_182 )
return V_182 ;
if ( ( V_15 -> V_48 & V_320 ) &&
( V_144 [ V_321 ] & 0xe ) == 0x2 )
V_15 -> V_48 |= V_322 ;
if ( V_15 -> V_48 & V_322 ) {
F_24 ( V_15 , L_87 ) ;
V_15 -> V_3 -> V_5 -> V_323 = V_324 ;
}
V_182 = F_119 ( V_15 ) ;
if ( V_182 )
return V_182 ;
V_182 = F_55 ( V_15 ) ;
if ( V_182 )
return V_182 ;
if ( F_117 ( V_5 ) )
F_96 ( V_15 ,
L_88
L_89 ,
V_260 ,
V_144 [ 49 ] , V_144 [ 82 ] , V_144 [ 83 ] , V_144 [ 84 ] ,
V_144 [ 85 ] , V_144 [ 86 ] , V_144 [ 87 ] , V_144 [ 88 ] ) ;
V_15 -> V_42 &= ~ V_325 ;
V_15 -> V_158 = 0 ;
V_15 -> V_326 = 0 ;
V_15 -> V_327 = 0 ;
V_15 -> V_328 = 0 ;
V_15 -> V_104 = 0 ;
V_15 -> V_105 = 0 ;
V_15 -> V_95 = 0 ;
V_47 = F_61 ( V_144 ) ;
if ( F_117 ( V_5 ) )
F_60 ( V_144 ) ;
F_41 ( V_15 -> V_144 , V_313 , V_329 ,
sizeof( V_313 ) ) ;
F_41 ( V_15 -> V_144 , V_315 , V_330 ,
sizeof( V_315 ) ) ;
if ( V_15 -> V_183 == V_138 || V_15 -> V_183 == V_142 ) {
if ( F_62 ( V_144 ) ) {
if ( V_144 [ V_331 ] & 1 )
F_24 ( V_15 ,
L_90 ) ;
snprintf ( V_312 , 7 , L_91 ) ;
} else {
snprintf ( V_312 , 7 , L_92 , F_101 ( V_144 ) ) ;
if ( F_120 ( V_144 ) )
F_24 ( V_15 ,
L_90 ) ;
}
V_15 -> V_327 = F_43 ( V_144 ) ;
if ( ( V_15 -> V_144 [ 47 ] >> 8 ) == 0x80 && ( V_15 -> V_144 [ 59 ] & 0x100 ) ) {
unsigned int V_332 = V_15 -> V_144 [ 47 ] & 0xff ;
unsigned int V_333 = V_15 -> V_144 [ 59 ] & 0xff ;
if ( F_121 ( V_332 ) && F_121 ( V_333 ) )
if ( V_333 <= V_332 )
V_15 -> V_95 = V_333 ;
}
if ( F_44 ( V_144 ) ) {
const char * V_334 ;
char V_335 [ 24 ] ;
V_334 = L_93 ;
V_15 -> V_42 |= V_117 ;
if ( F_45 ( V_144 ) ) {
V_15 -> V_42 |= V_118 ;
V_334 = L_94 ;
if ( V_15 -> V_327 >= ( 1UL << 28 ) &&
F_122 ( V_144 ) )
V_15 -> V_42 |= V_336 ;
}
V_182 = F_108 ( V_15 , V_335 , sizeof( V_335 ) ) ;
if ( V_182 )
return V_182 ;
if ( F_123 ( V_5 ) && V_176 ) {
F_57 ( V_15 , L_95 ,
V_312 , V_315 , V_313 ,
F_36 ( V_47 ) ) ;
F_57 ( V_15 ,
L_96 ,
( unsigned long long ) V_15 -> V_327 ,
V_15 -> V_95 , V_334 , V_335 ) ;
}
} else {
V_15 -> V_328 = V_144 [ 1 ] ;
V_15 -> V_104 = V_144 [ 3 ] ;
V_15 -> V_105 = V_144 [ 6 ] ;
if ( F_48 ( V_144 ) ) {
V_15 -> V_328 = V_144 [ 54 ] ;
V_15 -> V_104 = V_144 [ 55 ] ;
V_15 -> V_105 = V_144 [ 56 ] ;
}
if ( F_123 ( V_5 ) && V_176 ) {
F_57 ( V_15 , L_95 ,
V_312 , V_315 , V_313 ,
F_36 ( V_47 ) ) ;
F_57 ( V_15 ,
L_97 ,
( unsigned long long ) V_15 -> V_327 ,
V_15 -> V_95 , V_15 -> V_328 ,
V_15 -> V_104 , V_15 -> V_105 ) ;
}
}
if ( F_124 ( V_15 -> V_144 ) ) {
T_2 * V_337 = V_5 -> V_304 ;
int V_25 , V_338 ;
V_15 -> V_42 |= V_339 ;
V_159 = F_114 ( V_15 ,
V_340 ,
V_341 ,
V_337 ,
1 ) ;
if ( V_159 )
F_96 ( V_15 ,
L_98 ,
V_159 ) ;
else
for ( V_25 = 0 ; V_25 < V_342 ; V_25 ++ ) {
V_338 = V_343 + V_25 ;
V_15 -> V_344 [ V_25 ] = V_337 [ V_338 ] ;
}
}
V_15 -> V_326 = 16 ;
}
else if ( V_15 -> V_183 == V_139 ) {
const char * V_345 = L_68 ;
const char * V_346 = L_68 ;
const char * V_347 = L_68 ;
T_1 V_348 ;
V_182 = F_125 ( V_144 ) ;
if ( ( V_182 < 12 ) || ( V_182 > V_224 ) ) {
if ( F_84 ( V_5 ) )
F_24 ( V_15 , L_99 ) ;
V_182 = - V_119 ;
goto V_349;
}
V_15 -> V_326 = ( unsigned int ) V_182 ;
if ( V_350 &&
( V_5 -> V_42 & V_351 ) && F_126 ( V_144 ) &&
( ! F_4 ( V_5 ) ||
F_127 ( & V_5 -> V_3 , V_352 , & V_348 ) == 0 ) ) {
V_159 = F_100 ( V_15 ,
V_300 , V_353 ) ;
if ( V_159 )
F_59 ( V_15 ,
L_100 ,
V_159 ) ;
else {
V_15 -> V_42 |= V_354 ;
V_346 = L_101 ;
}
}
if ( F_128 ( V_15 -> V_144 ) ) {
V_15 -> V_42 |= V_355 ;
V_345 = L_102 ;
}
if ( V_356 || ( V_15 -> V_48 & V_357 ) || F_129 ( V_15 -> V_144 ) ) {
V_15 -> V_42 |= V_226 ;
V_347 = L_103 ;
}
if ( F_130 ( V_15 -> V_144 ) ) {
V_15 -> V_42 |= V_358 ;
F_131 ( V_15 ) ;
}
if ( F_123 ( V_5 ) && V_176 )
F_57 ( V_15 ,
L_104 ,
V_315 , V_313 ,
F_36 ( V_47 ) ,
V_345 , V_346 ,
V_347 ) ;
}
V_15 -> V_158 = V_359 ;
if ( V_15 -> V_42 & V_118 )
V_15 -> V_158 = V_360 ;
if ( F_105 ( V_15 ) ) {
if ( F_123 ( V_5 ) && V_176 )
F_57 ( V_15 , L_105 ) ;
V_15 -> V_46 &= V_361 ;
V_15 -> V_158 = V_359 ;
}
if ( ( V_15 -> V_183 == V_139 ) &&
( F_132 ( V_144 ) == V_362 ) ) {
V_15 -> V_158 = V_363 ;
V_15 -> V_48 |= V_364 ;
}
if ( V_15 -> V_48 & V_365 )
V_15 -> V_158 = F_133 (unsigned int, ATA_MAX_SECTORS_128,
dev->max_sectors) ;
if ( V_15 -> V_48 & V_366 )
V_15 -> V_158 = V_360 ;
if ( V_5 -> V_215 -> V_367 )
V_5 -> V_215 -> V_367 ( V_15 ) ;
if ( V_15 -> V_48 & V_368 ) {
if ( V_176 ) {
F_24 ( V_15 ,
L_106 ) ;
F_24 ( V_15 ,
L_107 ) ;
}
}
if ( ( V_15 -> V_48 & V_369 ) && V_176 ) {
F_24 ( V_15 , L_108 ) ;
F_24 ( V_15 , L_109 ) ;
}
return 0 ;
V_349:
if ( F_117 ( V_5 ) )
F_96 ( V_15 , L_110 , V_260 ) ;
return V_182 ;
}
int F_134 ( struct V_4 * V_5 )
{
return V_370 ;
}
int F_135 ( struct V_4 * V_5 )
{
return V_371 ;
}
int F_136 ( struct V_4 * V_5 )
{
return V_372 ;
}
int F_137 ( struct V_4 * V_5 )
{
return V_373 ;
}
int F_138 ( struct V_4 * V_5 )
{
return V_286 ;
}
int F_139 ( struct V_4 * V_5 )
{
unsigned int V_374 [ V_375 ] ;
int V_376 [ V_375 ] ;
int V_182 ;
struct V_14 * V_15 ;
F_140 (dev, &ap->link, ALL)
V_376 [ V_15 -> V_24 ] = V_377 ;
V_261:
F_140 (dev, &ap->link, ALL) {
V_15 -> V_249 = V_378 ;
V_15 -> V_379 = 0xff ;
if ( V_5 -> V_215 -> V_380 )
V_5 -> V_215 -> V_380 ( V_5 , V_15 ) ;
}
V_5 -> V_215 -> V_381 ( V_5 ) ;
F_140 (dev, &ap->link, ALL) {
if ( V_15 -> V_183 != V_143 )
V_374 [ V_15 -> V_24 ] = V_15 -> V_183 ;
else
V_374 [ V_15 -> V_24 ] = V_382 ;
V_15 -> V_183 = V_143 ;
}
F_140 (dev, &ap->link, ALL_REVERSE) {
if ( V_376 [ V_15 -> V_24 ] )
V_15 -> V_183 = V_374 [ V_15 -> V_24 ] ;
if ( ! F_8 ( V_15 ) )
continue;
V_182 = F_94 ( V_15 , & V_15 -> V_183 , V_277 ,
V_15 -> V_144 ) ;
if ( V_182 )
goto V_383;
}
if ( V_5 -> V_215 -> V_384 )
V_5 -> V_33 = V_5 -> V_215 -> V_384 ( V_5 ) ;
F_140 (dev, &ap->link, ENABLED)
if ( F_107 ( V_15 -> V_144 ) )
V_5 -> V_33 = V_286 ;
F_140 (dev, &ap->link, ENABLED) {
V_5 -> V_3 . V_175 . V_25 . V_42 |= V_177 ;
V_182 = F_115 ( V_15 ) ;
V_5 -> V_3 . V_175 . V_25 . V_42 &= ~ V_177 ;
if ( V_182 )
goto V_383;
}
V_182 = F_141 ( & V_5 -> V_3 , & V_15 ) ;
if ( V_182 )
goto V_383;
F_140 (dev, &ap->link, ENABLED)
return 0 ;
return - V_264 ;
V_383:
V_376 [ V_15 -> V_24 ] -- ;
switch ( V_182 ) {
case - V_119 :
V_376 [ V_15 -> V_24 ] = 0 ;
break;
case - V_264 :
V_376 [ V_15 -> V_24 ] = F_111 ( V_376 [ V_15 -> V_24 ] , 1 ) ;
case - V_167 :
if ( V_376 [ V_15 -> V_24 ] == 1 ) {
F_142 ( & V_5 -> V_3 , 0 ) ;
F_143 ( V_15 , V_385 ) ;
}
}
if ( ! V_376 [ V_15 -> V_24 ] )
F_118 ( V_15 ) ;
goto V_261;
}
static void F_144 ( struct V_2 * V_3 )
{
T_1 V_1 , V_386 , V_387 ;
if ( F_127 ( V_3 , V_388 , & V_1 ) )
return;
F_127 ( V_3 , V_389 , & V_386 ) ;
if ( F_145 ( V_3 ) ) {
V_387 = ( V_1 >> 4 ) & 0xf ;
F_146 ( V_3 , L_111 ,
F_38 ( V_387 ) , V_1 , V_386 ) ;
} else {
F_146 ( V_3 , L_112 ,
V_1 , V_386 ) ;
}
}
struct V_14 * F_147 ( struct V_14 * V_246 )
{
struct V_2 * V_3 = V_246 -> V_3 ;
struct V_14 * V_390 = & V_3 -> V_21 [ 1 - V_246 -> V_24 ] ;
if ( ! F_8 ( V_390 ) )
return NULL ;
return V_390 ;
}
int F_142 ( struct V_2 * V_3 , T_1 V_39 )
{
T_1 V_1 , V_136 , V_391 ;
int V_182 , V_392 ;
if ( ! F_104 ( V_3 ) )
return - V_393 ;
V_182 = F_127 ( V_3 , V_388 , & V_1 ) ;
if ( V_182 == 0 && F_1 ( V_1 ) )
V_136 = ( V_1 >> 4 ) & 0xf ;
else
V_136 = V_3 -> V_283 ;
V_391 = V_3 -> V_282 ;
if ( V_391 <= 1 )
return - V_119 ;
V_392 = F_33 ( V_391 ) - 1 ;
V_391 &= ~ ( 1 << V_392 ) ;
if ( V_136 > 1 )
V_391 &= ( 1 << ( V_136 - 1 ) ) - 1 ;
else
V_391 &= 1 ;
if ( ! V_391 )
return - V_119 ;
if ( V_39 ) {
if ( V_391 & ( ( 1 << V_39 ) - 1 ) )
V_391 &= ( 1 << V_39 ) - 1 ;
else {
V_392 = F_148 ( V_391 ) - 1 ;
V_391 = 1 << V_392 ;
}
}
V_3 -> V_282 = V_391 ;
F_149 ( V_3 , L_113 ,
F_38 ( F_33 ( V_391 ) ) ) ;
return 0 ;
}
static int F_150 ( struct V_2 * V_3 , T_1 * V_386 )
{
struct V_2 * V_394 = & V_3 -> V_5 -> V_3 ;
T_1 V_395 , V_279 , V_136 ;
V_395 = V_3 -> V_282 ;
if ( ! F_13 ( V_3 ) && V_394 -> V_283 )
V_395 &= ( 1 << V_394 -> V_283 ) - 1 ;
if ( V_395 == V_396 )
V_279 = 0 ;
else
V_279 = F_33 ( V_395 ) ;
V_136 = ( * V_386 >> 4 ) & 0xf ;
* V_386 = ( * V_386 & ~ 0xf0 ) | ( ( V_279 & 0xf ) << 4 ) ;
return V_136 != V_279 ;
}
static int F_151 ( struct V_2 * V_3 )
{
T_1 V_386 ;
if ( F_127 ( V_3 , V_389 , & V_386 ) )
return 1 ;
return F_150 ( V_3 , & V_386 ) ;
}
int F_152 ( struct V_2 * V_3 )
{
T_1 V_386 ;
int V_182 ;
if ( ( V_182 = F_127 ( V_3 , V_389 , & V_386 ) ) )
return V_182 ;
if ( ! F_150 ( V_3 , & V_386 ) )
return 0 ;
if ( ( V_182 = F_153 ( V_3 , V_389 , V_386 ) ) )
return V_182 ;
return 1 ;
}
static void F_154 ( const struct V_397 * V_398 , struct V_397 * V_399 , int V_400 , int V_401 )
{
V_399 -> V_402 = F_155 ( V_398 -> V_402 * 1000 , V_400 ) ;
V_399 -> V_403 = F_155 ( V_398 -> V_403 * 1000 , V_400 ) ;
V_399 -> V_404 = F_155 ( V_398 -> V_404 * 1000 , V_400 ) ;
V_399 -> V_405 = F_155 ( V_398 -> V_405 * 1000 , V_400 ) ;
V_399 -> V_406 = F_155 ( V_398 -> V_406 * 1000 , V_400 ) ;
V_399 -> V_407 = F_155 ( V_398 -> V_407 * 1000 , V_400 ) ;
V_399 -> V_408 = F_155 ( V_398 -> V_408 * 1000 , V_400 ) ;
V_399 -> V_409 = F_155 ( V_398 -> V_409 * 1000 , V_400 ) ;
V_399 -> V_410 = F_155 ( V_398 -> V_410 * 1000 , V_401 ) ;
}
void F_156 ( const struct V_397 * V_411 , const struct V_397 * V_412 ,
struct V_397 * V_413 , unsigned int V_414 )
{
if ( V_414 & V_415 ) V_413 -> V_402 = V_332 ( V_411 -> V_402 , V_412 -> V_402 ) ;
if ( V_414 & V_416 ) V_413 -> V_403 = V_332 ( V_411 -> V_403 , V_412 -> V_403 ) ;
if ( V_414 & V_417 ) V_413 -> V_404 = V_332 ( V_411 -> V_404 , V_412 -> V_404 ) ;
if ( V_414 & V_418 ) V_413 -> V_405 = V_332 ( V_411 -> V_405 , V_412 -> V_405 ) ;
if ( V_414 & V_419 ) V_413 -> V_406 = V_332 ( V_411 -> V_406 , V_412 -> V_406 ) ;
if ( V_414 & V_420 ) V_413 -> V_407 = V_332 ( V_411 -> V_407 , V_412 -> V_407 ) ;
if ( V_414 & V_421 ) V_413 -> V_408 = V_332 ( V_411 -> V_408 , V_412 -> V_408 ) ;
if ( V_414 & V_422 ) V_413 -> V_409 = V_332 ( V_411 -> V_409 , V_412 -> V_409 ) ;
if ( V_414 & V_423 ) V_413 -> V_410 = V_332 ( V_411 -> V_410 , V_412 -> V_410 ) ;
}
const struct V_397 * F_157 ( T_2 V_134 )
{
const struct V_397 * V_398 = V_397 ;
while ( V_134 > V_398 -> V_7 )
V_398 ++ ;
if ( V_134 == V_398 -> V_7 )
return V_398 ;
F_158 ( true , L_114 ,
V_260 , V_134 ) ;
return NULL ;
}
int F_159 ( struct V_14 * V_246 , unsigned short V_424 ,
struct V_397 * V_398 , int V_400 , int V_401 )
{
const T_4 * V_144 = V_246 -> V_144 ;
const struct V_397 * V_145 ;
struct V_397 V_149 ;
if ( ! ( V_145 = F_157 ( V_424 ) ) )
return - V_119 ;
memcpy ( V_398 , V_145 , sizeof( * V_145 ) ) ;
if ( V_144 [ V_186 ] & 2 ) {
memset ( & V_149 , 0 , sizeof( V_149 ) ) ;
if ( V_424 >= V_378 && V_424 < V_425 ) {
if ( V_424 <= V_252 )
V_149 . V_409 = V_149 . V_405 = V_144 [ V_253 ] ;
else if ( ( V_424 <= V_426 ) ||
( V_424 == V_250 && ! F_62 ( V_144 ) ) )
V_149 . V_409 = V_149 . V_405 = V_144 [ V_427 ] ;
} else if ( V_424 >= V_428 && V_424 <= V_429 )
V_149 . V_409 = V_144 [ V_430 ] ;
F_156 ( & V_149 , V_398 , V_398 , V_422 | V_418 ) ;
}
F_154 ( V_398 , V_398 , V_400 , V_401 ) ;
if ( V_424 > V_251 ) {
F_159 ( V_246 , V_246 -> V_249 , & V_149 , V_400 , V_401 ) ;
F_156 ( & V_149 , V_398 , V_398 , V_431 ) ;
}
if ( V_398 -> V_403 + V_398 -> V_404 < V_398 -> V_405 ) {
V_398 -> V_403 += ( V_398 -> V_405 - ( V_398 -> V_403 + V_398 -> V_404 ) ) / 2 ;
V_398 -> V_404 = V_398 -> V_405 - V_398 -> V_403 ;
}
if ( V_398 -> V_406 + V_398 -> V_407 < V_398 -> V_409 ) {
V_398 -> V_406 += ( V_398 -> V_409 - ( V_398 -> V_406 + V_398 -> V_407 ) ) / 2 ;
V_398 -> V_407 = V_398 -> V_409 - V_398 -> V_406 ;
}
if ( V_398 -> V_406 + V_398 -> V_407 > V_398 -> V_409 )
V_398 -> V_409 = V_398 -> V_406 + V_398 -> V_407 ;
return 0 ;
}
T_2 F_160 ( unsigned int V_432 , int V_409 )
{
T_2 V_433 = 0xff , V_434 = 0xff ;
const struct V_128 * V_129 ;
const struct V_397 * V_398 ;
for ( V_129 = V_130 ; V_129 -> V_131 >= 0 ; V_129 ++ )
if ( V_129 -> V_131 == V_432 )
V_433 = V_129 -> V_133 ;
for ( V_398 = F_157 ( V_433 ) ;
V_398 && F_35 ( V_398 -> V_7 ) == V_432 ; V_398 ++ ) {
unsigned short V_435 ;
switch ( V_432 ) {
case V_121 :
case V_123 :
V_435 = V_398 -> V_409 ;
break;
case V_125 :
V_435 = V_398 -> V_410 ;
break;
default:
return 0xff ;
}
if ( V_409 > V_435 )
break;
V_434 = V_398 -> V_7 ;
}
return V_434 ;
}
int F_143 ( struct V_14 * V_15 , unsigned int V_436 )
{
char V_244 [ 32 ] ;
unsigned long V_437 , V_47 ;
unsigned long V_44 , V_45 , V_46 ;
int V_438 , V_127 ;
V_438 = ! ! ( V_436 & V_439 ) ;
V_436 &= ~ V_439 ;
V_47 = V_437 = F_31 ( V_15 -> V_44 ,
V_15 -> V_45 ,
V_15 -> V_46 ) ;
F_16 ( V_47 , & V_44 , & V_45 , & V_46 ) ;
switch ( V_436 ) {
case V_385 :
V_127 = F_33 ( V_44 ) - 1 ;
V_44 &= ~ ( 1 << V_127 ) ;
break;
case V_440 :
if ( V_46 ) {
V_127 = F_33 ( V_46 ) - 1 ;
V_46 &= ~ ( 1 << V_127 ) ;
if ( ! V_46 )
return - V_269 ;
} else if ( V_45 ) {
V_127 = F_33 ( V_45 ) - 1 ;
V_45 &= ~ ( 1 << V_127 ) ;
if ( ! V_45 )
return - V_269 ;
}
break;
case V_441 :
V_46 &= V_442 ;
break;
case V_443 :
V_44 &= 1 ;
case V_444 :
V_45 = 0 ;
V_46 = 0 ;
break;
default:
F_70 () ;
}
V_47 &= F_31 ( V_44 , V_45 , V_46 ) ;
if ( ! ( V_47 & V_122 ) || V_47 == V_437 )
return - V_269 ;
if ( ! V_438 ) {
if ( V_47 & ( V_124 | V_126 ) )
snprintf ( V_244 , sizeof( V_244 ) , L_115 ,
F_36 ( V_47 ) ,
F_36 ( V_47 & V_122 ) ) ;
else
snprintf ( V_244 , sizeof( V_244 ) , L_116 ,
F_36 ( V_47 ) ) ;
F_24 ( V_15 , L_117 , V_244 ) ;
}
F_16 ( V_47 , & V_15 -> V_44 , & V_15 -> V_45 ,
& V_15 -> V_46 ) ;
return 0 ;
}
static int F_161 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_173 * V_174 = & V_15 -> V_3 -> V_175 ;
const bool V_445 = V_15 -> V_48 & V_446 ;
const char * V_447 = L_68 ;
int V_448 = 0 ;
unsigned int V_159 = 0 ;
int V_182 ;
V_15 -> V_42 &= ~ V_92 ;
if ( V_15 -> V_432 == V_121 )
V_15 -> V_42 |= V_92 ;
if ( V_445 && V_5 -> V_42 & V_449 && F_107 ( V_15 -> V_144 ) )
V_447 = L_118 ;
else {
if ( V_445 )
F_24 ( V_15 ,
L_119
L_120 ) ;
V_159 = F_162 ( V_15 ) ;
}
if ( V_159 & ~ V_164 )
goto V_383;
V_174 -> V_25 . V_42 |= V_450 ;
V_182 = F_163 ( V_15 , V_143 , 0 ) ;
V_174 -> V_25 . V_42 &= ~ V_450 ;
if ( V_182 )
return V_182 ;
if ( V_15 -> V_432 == V_121 ) {
if ( F_62 ( V_15 -> V_144 ) )
V_448 = 1 ;
if ( F_101 ( V_15 -> V_144 ) == 0 &&
V_15 -> V_249 <= V_252 )
V_448 = 1 ;
if ( ! F_91 ( V_15 -> V_144 ) && V_15 -> V_249 <= V_252 )
V_448 = 1 ;
}
if ( V_15 -> V_432 == V_123 &&
V_15 -> V_379 == V_428 &&
( V_15 -> V_144 [ 63 ] >> 8 ) & 1 )
V_448 = 1 ;
if ( V_15 -> V_134 == F_32 ( F_61 ( V_15 -> V_144 ) ) )
V_448 = 1 ;
if ( V_159 & V_164 ) {
if ( ! V_448 )
goto V_383;
else
V_447 = L_121 ;
}
F_30 ( L_122 ,
V_15 -> V_432 , ( int ) V_15 -> V_134 ) ;
F_57 ( V_15 , L_123 ,
F_36 ( F_34 ( V_15 -> V_134 ) ) ,
V_447 ) ;
return 0 ;
V_383:
F_59 ( V_15 , L_124 , V_159 ) ;
return - V_167 ;
}
int F_164 ( struct V_2 * V_3 , struct V_14 * * V_451 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_14 * V_15 ;
int V_182 = 0 , V_452 = 0 , V_453 = 0 ;
F_140 (dev, link, ENABLED) {
unsigned long V_44 , V_454 ;
unsigned int V_455 ;
V_455 = V_456 ;
if ( V_15 -> V_183 == V_139 )
V_455 = V_457 ;
else if ( F_62 ( V_15 -> V_144 ) )
V_455 = V_458 ;
F_165 ( V_15 ) ;
F_15 ( V_15 ) ;
V_44 = F_31 ( V_15 -> V_44 , 0 , 0 ) ;
if ( V_459 & V_455 )
V_454 = F_31 ( 0 , V_15 -> V_45 ,
V_15 -> V_46 ) ;
else
V_454 = 0 ;
V_15 -> V_249 = F_32 ( V_44 ) ;
V_15 -> V_379 = F_32 ( V_454 ) ;
V_453 = 1 ;
if ( F_166 ( V_15 ) )
V_452 = 1 ;
}
if ( ! V_453 )
goto V_460;
F_140 (dev, link, ENABLED) {
if ( V_15 -> V_249 == 0xff ) {
F_24 ( V_15 , L_125 ) ;
V_182 = - V_119 ;
goto V_460;
}
V_15 -> V_134 = V_15 -> V_249 ;
V_15 -> V_432 = V_121 ;
if ( V_5 -> V_215 -> V_380 )
V_5 -> V_215 -> V_380 ( V_5 , V_15 ) ;
}
F_140 (dev, link, ENABLED) {
if ( ! F_166 ( V_15 ) )
continue;
V_15 -> V_134 = V_15 -> V_379 ;
V_15 -> V_432 = F_35 ( V_15 -> V_379 ) ;
if ( V_5 -> V_215 -> V_461 )
V_5 -> V_215 -> V_461 ( V_5 , V_15 ) ;
}
F_140 (dev, link, ENABLED) {
V_182 = F_161 ( V_15 ) ;
if ( V_182 )
goto V_460;
}
if ( V_452 && ( V_5 -> V_274 -> V_42 & V_462 ) )
V_5 -> V_274 -> V_463 = V_5 ;
V_460:
if ( V_182 )
* V_451 = V_15 ;
return V_182 ;
}
int F_167 ( struct V_2 * V_3 , unsigned long V_464 ,
int (* F_168)( struct V_2 * V_3 ) )
{
unsigned long V_465 = V_466 ;
unsigned long V_467 ;
int V_468 = 0 ;
if ( V_3 -> V_5 -> V_274 -> V_42 & V_469 )
V_467 = F_169 ( V_465 , V_470 ) ;
else
V_467 = F_169 ( V_465 , V_471 ) ;
F_87 ( V_3 == V_3 -> V_5 -> V_12 ) ;
if ( F_170 ( V_467 , V_464 ) )
V_467 = V_464 ;
while ( 1 ) {
unsigned long V_472 = V_466 ;
int V_473 , V_387 ;
V_473 = V_387 = F_168 ( V_3 ) ;
if ( V_473 > 0 )
return 0 ;
if ( V_473 == - V_264 ) {
if ( F_171 ( V_3 ) )
V_473 = 0 ;
else if ( ( V_3 -> V_5 -> V_42 & V_449 ) &&
! F_172 ( V_3 ) &&
F_173 ( V_472 , V_467 ) )
V_473 = 0 ;
}
if ( V_473 )
return V_473 ;
if ( F_170 ( V_472 , V_464 ) )
return - V_474 ;
if ( ! V_468 && F_170 ( V_472 , V_465 + 5 * V_475 ) &&
( V_464 - V_472 > 3 * V_475 ) ) {
F_149 ( V_3 ,
L_126
L_127 , V_387 ) ;
V_468 = 1 ;
}
F_174 ( V_3 -> V_5 , 50 ) ;
}
}
int F_175 ( struct V_2 * V_3 , unsigned long V_464 ,
int (* F_168)( struct V_2 * V_3 ) )
{
F_174 ( V_3 -> V_5 , V_476 ) ;
return F_167 ( V_3 , V_464 , F_168 ) ;
}
int F_176 ( struct V_2 * V_3 , const unsigned long * V_477 ,
unsigned long V_464 )
{
unsigned long V_478 = V_477 [ 0 ] ;
unsigned long V_479 = V_477 [ 1 ] ;
unsigned long V_480 , V_398 ;
T_1 V_481 , V_482 ;
int V_182 ;
V_398 = F_169 ( V_466 , V_477 [ 2 ] ) ;
if ( F_173 ( V_398 , V_464 ) )
V_464 = V_398 ;
if ( ( V_182 = F_127 ( V_3 , V_388 , & V_482 ) ) )
return V_182 ;
V_482 &= 0xf ;
V_481 = V_482 ;
V_480 = V_466 ;
while ( 1 ) {
F_174 ( V_3 -> V_5 , V_478 ) ;
if ( ( V_182 = F_127 ( V_3 , V_388 , & V_482 ) ) )
return V_182 ;
V_482 &= 0xf ;
if ( V_482 == V_481 ) {
if ( V_482 == 1 && F_173 ( V_466 , V_464 ) )
continue;
if ( F_170 ( V_466 ,
F_169 ( V_480 , V_479 ) ) )
return 0 ;
continue;
}
V_481 = V_482 ;
V_480 = V_466 ;
if ( F_170 ( V_466 , V_464 ) )
return - V_483 ;
}
}
int F_177 ( struct V_2 * V_3 , const unsigned long * V_477 ,
unsigned long V_464 )
{
int V_376 = V_484 ;
T_1 V_386 , V_485 ;
int V_182 ;
if ( ( V_182 = F_127 ( V_3 , V_389 , & V_386 ) ) )
return V_182 ;
do {
V_386 = ( V_386 & 0x0f0 ) | 0x300 ;
if ( ( V_182 = F_153 ( V_3 , V_389 , V_386 ) ) )
return V_182 ;
F_174 ( V_3 -> V_5 , 200 ) ;
if ( ( V_182 = F_127 ( V_3 , V_389 , & V_386 ) ) )
return V_182 ;
} while ( ( V_386 & 0xf0f ) != 0x300 && -- V_376 );
if ( ( V_386 & 0xf0f ) != 0x300 ) {
F_149 ( V_3 , L_128 ,
V_386 ) ;
return 0 ;
}
if ( V_376 < V_484 )
F_149 ( V_3 , L_129 ,
V_484 - V_376 ) ;
if ( ( V_182 = F_176 ( V_3 , V_477 , V_464 ) ) )
return V_182 ;
if ( ! ( V_182 = F_127 ( V_3 , V_486 , & V_485 ) ) )
V_182 = F_153 ( V_3 , V_486 , V_485 ) ;
return V_182 != - V_119 ? V_182 : 0 ;
}
int F_178 ( struct V_2 * V_3 , enum V_487 V_488 ,
bool V_489 )
{
struct V_173 * V_174 = & V_3 -> V_175 ;
bool V_490 = false ;
T_1 V_386 ;
int V_182 ;
V_182 = F_127 ( V_3 , V_389 , & V_386 ) ;
if ( V_182 )
return V_182 ;
switch ( V_488 ) {
case V_324 :
V_386 |= ( 0x7 << 8 ) ;
if ( V_489 ) {
V_386 |= ( 0x4 << 12 ) ;
V_490 = true ;
}
break;
case V_491 :
V_386 &= ~ ( 0x1 << 8 ) ;
V_386 |= ( 0x6 << 8 ) ;
break;
case V_492 :
if ( F_179 ( V_3 ) > 0 )
V_386 &= ~ ( 0x7 << 8 ) ;
else {
V_386 &= ~ 0xf ;
V_386 |= ( 0x1 << 2 ) ;
}
break;
default:
F_87 ( 1 ) ;
}
V_182 = F_153 ( V_3 , V_389 , V_386 ) ;
if ( V_182 )
return V_182 ;
if ( V_490 )
F_180 ( 10 ) ;
V_174 -> V_25 . V_485 &= ~ V_493 ;
return F_153 ( V_3 , V_486 , V_493 ) ;
}
int F_181 ( struct V_2 * V_3 , unsigned long V_464 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_173 * V_174 = & V_3 -> V_175 ;
const unsigned long * V_494 = F_182 ( V_174 ) ;
int V_182 ;
if ( V_174 -> V_25 . V_495 & V_496 )
return 0 ;
if ( V_5 -> V_42 & V_449 ) {
V_182 = F_177 ( V_3 , V_494 , V_464 ) ;
if ( V_182 && V_182 != - V_393 )
F_149 ( V_3 ,
L_130 ,
V_182 ) ;
}
if ( F_183 ( V_3 ) )
V_174 -> V_25 . V_495 &= ~ V_497 ;
return 0 ;
}
int F_184 ( struct V_2 * V_3 , const unsigned long * V_494 ,
unsigned long V_464 ,
bool * V_498 , int (* F_168)( struct V_2 * ) )
{
T_1 V_386 ;
int V_182 ;
F_30 ( L_131 ) ;
if ( V_498 )
* V_498 = false ;
if ( F_151 ( V_3 ) ) {
if ( ( V_182 = F_127 ( V_3 , V_389 , & V_386 ) ) )
goto V_460;
V_386 = ( V_386 & 0x0f0 ) | 0x304 ;
if ( ( V_182 = F_153 ( V_3 , V_389 , V_386 ) ) )
goto V_460;
F_152 ( V_3 ) ;
}
if ( ( V_182 = F_127 ( V_3 , V_389 , & V_386 ) ) )
goto V_460;
V_386 = ( V_386 & 0x0f0 ) | 0x301 ;
if ( ( V_182 = F_185 ( V_3 , V_389 , V_386 ) ) )
goto V_460;
F_174 ( V_3 -> V_5 , 1 ) ;
V_182 = F_177 ( V_3 , V_494 , V_464 ) ;
if ( V_182 )
goto V_460;
if ( F_183 ( V_3 ) )
goto V_460;
if ( V_498 )
* V_498 = true ;
if ( F_186 ( V_3 -> V_5 ) && F_13 ( V_3 ) ) {
if ( F_168 ) {
unsigned long V_499 ;
V_499 = F_169 ( V_466 ,
V_500 ) ;
if ( F_170 ( V_499 , V_464 ) )
V_499 = V_464 ;
F_167 ( V_3 , V_499 , F_168 ) ;
}
V_182 = - V_284 ;
goto V_460;
}
V_182 = 0 ;
if ( F_168 )
V_182 = F_167 ( V_3 , V_464 , F_168 ) ;
V_460:
if ( V_182 && V_182 != - V_284 ) {
if ( V_498 )
* V_498 = false ;
F_187 ( V_3 , L_132 , V_182 ) ;
}
F_30 ( L_133 , V_182 ) ;
return V_182 ;
}
int F_188 ( struct V_2 * V_3 , unsigned int * V_183 ,
unsigned long V_464 )
{
const unsigned long * V_494 = F_182 ( & V_3 -> V_175 ) ;
bool V_498 ;
int V_182 ;
V_182 = F_184 ( V_3 , V_494 , V_464 , & V_498 , NULL ) ;
return V_498 ? - V_284 : V_182 ;
}
void F_189 ( struct V_2 * V_3 , unsigned int * V_374 )
{
T_1 V_485 ;
F_30 ( L_131 ) ;
if ( ! F_127 ( V_3 , V_486 , & V_485 ) )
F_153 ( V_3 , V_486 , V_485 ) ;
F_144 ( V_3 ) ;
F_30 ( L_134 ) ;
}
static int F_190 ( struct V_14 * V_15 , unsigned int V_501 ,
const T_4 * V_502 )
{
const T_4 * V_503 = V_15 -> V_144 ;
unsigned char V_504 [ 2 ] [ V_316 + 1 ] ;
unsigned char V_505 [ 2 ] [ V_506 + 1 ] ;
if ( V_15 -> V_183 != V_501 ) {
F_57 ( V_15 , L_135 ,
V_15 -> V_183 , V_501 ) ;
return 0 ;
}
F_41 ( V_503 , V_504 [ 0 ] , V_330 , sizeof( V_504 [ 0 ] ) ) ;
F_41 ( V_502 , V_504 [ 1 ] , V_330 , sizeof( V_504 [ 1 ] ) ) ;
F_41 ( V_503 , V_505 [ 0 ] , V_507 , sizeof( V_505 [ 0 ] ) ) ;
F_41 ( V_502 , V_505 [ 1 ] , V_507 , sizeof( V_505 [ 1 ] ) ) ;
if ( strcmp ( V_504 [ 0 ] , V_504 [ 1 ] ) ) {
F_57 ( V_15 , L_136 ,
V_504 [ 0 ] , V_504 [ 1 ] ) ;
return 0 ;
}
if ( strcmp ( V_505 [ 0 ] , V_505 [ 1 ] ) ) {
F_57 ( V_15 , L_137 ,
V_505 [ 0 ] , V_505 [ 1 ] ) ;
return 0 ;
}
return 1 ;
}
int F_58 ( struct V_14 * V_15 , unsigned int V_508 )
{
unsigned int V_183 = V_15 -> V_183 ;
T_4 * V_144 = ( void * ) V_15 -> V_3 -> V_5 -> V_304 ;
int V_182 ;
V_182 = F_94 ( V_15 , & V_183 , V_508 , V_144 ) ;
if ( V_182 )
return V_182 ;
if ( ! F_190 ( V_15 , V_183 , V_144 ) )
return - V_264 ;
memcpy ( V_15 -> V_144 , V_144 , sizeof( V_144 [ 0 ] ) * V_254 ) ;
return 0 ;
}
int F_163 ( struct V_14 * V_15 , unsigned int V_501 ,
unsigned int V_508 )
{
T_3 V_327 = V_15 -> V_327 ;
T_3 V_185 = V_15 -> V_185 ;
int V_182 ;
if ( ! F_8 ( V_15 ) )
return - V_264 ;
if ( F_191 ( V_501 ) &&
V_501 != V_138 &&
V_501 != V_139 &&
V_501 != V_142 &&
V_501 != V_141 ) {
F_57 ( V_15 , L_138 ,
V_15 -> V_183 , V_501 ) ;
V_182 = - V_264 ;
goto V_383;
}
V_182 = F_58 ( V_15 , V_508 ) ;
if ( V_182 )
goto V_383;
V_182 = F_115 ( V_15 ) ;
if ( V_182 )
goto V_383;
if ( V_15 -> V_183 != V_138 || ! V_327 ||
V_15 -> V_327 == V_327 )
return 0 ;
F_24 ( V_15 , L_139 ,
( unsigned long long ) V_327 ,
( unsigned long long ) V_15 -> V_327 ) ;
if ( V_15 -> V_185 == V_185 &&
V_15 -> V_327 > V_327 && V_15 -> V_327 == V_185 ) {
F_24 ( V_15 ,
L_140
L_141 ) ;
return 0 ;
}
if ( V_15 -> V_185 == V_185 &&
V_15 -> V_327 < V_327 && V_327 == V_185 &&
! ( V_15 -> V_48 & V_184 ) ) {
F_24 ( V_15 ,
L_142
L_143 ) ;
V_15 -> V_42 |= V_180 ;
V_182 = - V_167 ;
} else
V_182 = - V_264 ;
V_15 -> V_185 = V_185 ;
V_15 -> V_327 = V_327 ;
V_383:
F_59 ( V_15 , L_144 , V_182 ) ;
return V_182 ;
}
static unsigned long F_106 ( const struct V_14 * V_15 )
{
unsigned char V_509 [ V_316 + 1 ] ;
unsigned char V_510 [ V_314 + 1 ] ;
const struct V_511 * V_512 = V_513 ;
F_41 ( V_15 -> V_144 , V_509 , V_330 , sizeof( V_509 ) ) ;
F_41 ( V_15 -> V_144 , V_510 , V_329 , sizeof( V_510 ) ) ;
while ( V_512 -> V_509 ) {
if ( F_192 ( V_512 -> V_509 , V_509 ) ) {
if ( V_512 -> V_510 == NULL )
return V_512 -> V_48 ;
if ( F_192 ( V_512 -> V_510 , V_510 ) )
return V_512 -> V_48 ;
}
V_512 ++ ;
}
return 0 ;
}
static int F_193 ( const struct V_14 * V_15 )
{
if ( ( V_15 -> V_3 -> V_5 -> V_42 & V_514 ) &&
( V_15 -> V_42 & V_355 ) )
return 1 ;
return ( V_15 -> V_48 & V_515 ) ? 1 : 0 ;
}
static int F_194 ( struct V_14 * V_15 )
{
if ( V_15 -> V_48 & V_516 )
return F_195 ( V_15 -> V_144 ) ;
return F_196 ( V_15 -> V_144 ) ;
}
static int F_197 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
struct V_14 * V_15 ;
if ( V_5 -> V_33 == V_370 )
return 1 ;
if ( V_5 -> V_33 == V_371 || V_5 -> V_33 == V_286 )
return 0 ;
if ( V_5 -> V_33 == V_517 )
return 0 ;
F_198 (link, ap, EDGE) {
F_140 (dev, link, ENABLED) {
if ( ! F_194 ( V_15 ) )
return 0 ;
}
}
return 1 ;
}
static void F_165 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_518 * V_274 = V_5 -> V_274 ;
unsigned long V_47 ;
V_47 = F_31 ( V_5 -> V_44 ,
V_5 -> V_45 , V_5 -> V_46 ) ;
V_47 &= F_31 ( V_15 -> V_44 ,
V_15 -> V_45 , V_15 -> V_46 ) ;
V_47 &= F_61 ( V_15 -> V_144 ) ;
if ( F_147 ( V_15 ) ) {
V_47 &= ~ ( 0x03 << ( V_121 + 5 ) ) ;
V_47 &= ~ ( 0x03 << ( V_123 + 3 ) ) ;
}
if ( F_193 ( V_15 ) ) {
V_47 &= ~ ( V_124 | V_126 ) ;
F_24 ( V_15 ,
L_145 ) ;
}
if ( ( V_274 -> V_42 & V_462 ) &&
V_274 -> V_463 && V_274 -> V_463 != V_5 ) {
V_47 &= ~ ( V_124 | V_126 ) ;
F_24 ( V_15 ,
L_146 ) ;
}
if ( V_5 -> V_42 & V_248 )
V_47 &= F_92 ( V_15 ) ;
if ( V_5 -> V_215 -> V_519 )
V_47 = V_5 -> V_215 -> V_519 ( V_15 , V_47 ) ;
if ( V_47 & ( 0xF8 << V_125 ) )
if ( F_197 ( V_5 ) ) {
F_24 ( V_15 ,
L_147 ) ;
V_47 &= ~ ( 0xF8 << V_125 ) ;
}
F_16 ( V_47 , & V_15 -> V_44 ,
& V_15 -> V_45 , & V_15 -> V_46 ) ;
}
static unsigned int F_162 ( struct V_14 * V_15 )
{
struct V_67 V_68 ;
unsigned int V_159 ;
F_30 ( L_148 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_520 ;
V_68 . V_72 = V_521 ;
V_68 . V_42 |= V_109 | V_110 | V_266 ;
V_68 . V_93 = V_162 ;
if ( F_90 ( V_15 ) )
V_68 . V_80 = V_15 -> V_134 ;
else if ( F_91 ( V_15 -> V_144 ) )
V_68 . V_80 = 0x01 ;
else
return 0 ;
V_159 = F_53 ( V_15 , & V_68 , NULL , V_163 , NULL , 0 , 0 ) ;
F_30 ( L_149 , V_159 ) ;
return V_159 ;
}
unsigned int F_100 ( struct V_14 * V_15 , T_2 V_522 , T_2 V_72 )
{
struct V_67 V_68 ;
unsigned int V_159 ;
F_30 ( L_150 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_520 ;
V_68 . V_72 = V_522 ;
V_68 . V_42 |= V_109 | V_110 ;
V_68 . V_93 = V_162 ;
V_68 . V_80 = V_72 ;
V_159 = F_53 ( V_15 , & V_68 , NULL , V_163 , NULL , 0 , 0 ) ;
F_30 ( L_149 , V_159 ) ;
return V_159 ;
}
static unsigned int F_102 ( struct V_14 * V_15 ,
T_4 V_104 , T_4 V_105 )
{
struct V_67 V_68 ;
unsigned int V_159 ;
if ( V_105 < 1 || V_105 > 255 || V_104 < 1 || V_104 > 16 )
return V_523 ;
F_30 ( L_151 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_524 ;
V_68 . V_42 |= V_109 | V_110 ;
V_68 . V_93 = V_162 ;
V_68 . V_80 = V_105 ;
V_68 . V_21 |= ( V_104 - 1 ) & 0x0f ;
V_159 = F_53 ( V_15 , & V_68 , NULL , V_163 , NULL , 0 , 0 ) ;
if ( V_159 == V_164 && ( V_68 . V_72 & V_165 ) )
V_159 = 0 ;
F_30 ( L_149 , V_159 ) ;
return V_159 ;
}
void F_199 ( struct V_194 * V_195 )
{
struct V_4 * V_5 = V_195 -> V_5 ;
struct V_201 * V_231 = V_195 -> V_231 ;
int V_525 = V_195 -> V_200 ;
F_200 ( V_231 == NULL ) ;
F_201 ( L_152 , V_195 -> V_203 ) ;
if ( V_195 -> V_203 )
F_202 ( V_5 -> V_15 , V_231 , V_195 -> V_526 , V_525 ) ;
V_195 -> V_42 &= ~ V_527 ;
V_195 -> V_231 = NULL ;
}
int F_203 ( struct V_194 * V_195 )
{
struct V_4 * V_5 = V_195 -> V_5 ;
if ( ! ( V_195 -> V_15 -> V_48 & V_528 ) &&
F_5 ( V_195 -> V_233 & 15 ) )
return 1 ;
if ( V_5 -> V_215 -> V_529 )
return V_5 -> V_215 -> V_529 ( V_195 ) ;
return 0 ;
}
int F_204 ( struct V_194 * V_195 )
{
struct V_2 * V_3 = V_195 -> V_15 -> V_3 ;
if ( V_195 -> V_68 . V_93 == V_113 ) {
if ( ! F_205 ( V_3 -> V_219 ) )
return 0 ;
} else {
if ( ! F_205 ( V_3 -> V_219 ) && ! V_3 -> V_220 )
return 0 ;
}
return V_530 ;
}
void F_206 ( struct V_194 * V_195 ) { }
void F_74 ( struct V_194 * V_195 , struct V_201 * V_231 ,
unsigned int V_203 )
{
V_195 -> V_231 = V_231 ;
V_195 -> V_203 = V_203 ;
V_195 -> V_531 = V_195 -> V_231 ;
}
static int F_207 ( struct V_194 * V_195 )
{
struct V_4 * V_5 = V_195 -> V_5 ;
unsigned int V_203 ;
F_201 ( L_153 , V_5 -> V_31 ) ;
V_203 = F_208 ( V_5 -> V_15 , V_195 -> V_231 , V_195 -> V_203 , V_195 -> V_200 ) ;
if ( V_203 < 1 )
return - 1 ;
F_30 ( L_154 , V_203 ) ;
V_195 -> V_526 = V_195 -> V_203 ;
V_195 -> V_203 = V_203 ;
V_195 -> V_42 |= V_527 ;
return 0 ;
}
void F_98 ( T_4 * V_244 , unsigned int V_532 )
{
#ifdef F_209
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < V_532 ; V_25 ++ )
V_244 [ V_25 ] = F_210 ( V_244 [ V_25 ] ) ;
#endif
}
static struct V_194 * F_211 ( struct V_4 * V_5 )
{
struct V_194 * V_195 = NULL ;
unsigned int V_533 = V_5 -> V_274 -> V_534 ;
unsigned int V_25 , V_108 ;
if ( F_5 ( V_5 -> V_212 & V_213 ) )
return NULL ;
for ( V_25 = 0 , V_108 = V_5 -> V_535 + 1 ; V_25 < V_533 ; V_25 ++ , V_108 ++ ) {
if ( V_5 -> V_42 & V_536 )
V_108 = V_25 ;
else
V_108 = V_108 < V_533 ? V_108 : 0 ;
if ( V_108 == V_111 )
continue;
if ( ! F_69 ( V_108 , & V_5 -> V_217 ) ) {
V_195 = F_71 ( V_5 , V_108 ) ;
V_195 -> V_108 = V_108 ;
V_5 -> V_535 = V_108 ;
break;
}
}
return V_195 ;
}
struct V_194 * F_212 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_194 * V_195 ;
V_195 = F_211 ( V_5 ) ;
if ( V_195 ) {
V_195 -> V_218 = NULL ;
V_195 -> V_5 = V_5 ;
V_195 -> V_15 = V_15 ;
F_72 ( V_195 ) ;
}
return V_195 ;
}
void F_85 ( struct V_194 * V_195 )
{
struct V_4 * V_5 ;
unsigned int V_108 ;
F_200 ( V_195 == NULL ) ;
V_5 = V_195 -> V_5 ;
V_195 -> V_42 = 0 ;
V_108 = V_195 -> V_108 ;
if ( F_27 ( F_205 ( V_108 ) ) ) {
V_195 -> V_108 = V_223 ;
F_213 ( V_108 , & V_5 -> V_217 ) ;
}
}
void F_214 ( struct V_194 * V_195 )
{
struct V_4 * V_5 ;
struct V_2 * V_3 ;
F_200 ( V_195 == NULL ) ;
F_200 ( ! ( V_195 -> V_42 & V_236 ) ) ;
V_5 = V_195 -> V_5 ;
V_3 = V_195 -> V_15 -> V_3 ;
if ( F_27 ( V_195 -> V_42 & V_527 ) )
F_199 ( V_195 ) ;
if ( V_195 -> V_68 . V_93 == V_113 ) {
V_3 -> V_220 &= ~ ( 1 << V_195 -> V_108 ) ;
if ( ! V_3 -> V_220 )
V_5 -> V_222 -- ;
} else {
V_3 -> V_219 = V_223 ;
V_5 -> V_222 -- ;
}
if ( F_5 ( V_195 -> V_42 & V_537 &&
V_5 -> V_538 == V_3 ) )
V_5 -> V_538 = NULL ;
V_195 -> V_42 &= ~ V_236 ;
V_5 -> V_221 &= ~ ( 1 << V_195 -> V_108 ) ;
V_195 -> V_234 ( V_195 ) ;
}
static void F_215 ( struct V_194 * V_195 )
{
struct V_4 * V_5 = V_195 -> V_5 ;
V_195 -> V_240 . V_42 = V_195 -> V_68 . V_42 ;
V_5 -> V_215 -> V_539 ( V_195 ) ;
}
static void F_216 ( struct V_194 * V_195 )
{
struct V_14 * V_15 = V_195 -> V_15 ;
if ( F_217 ( V_195 -> V_68 . V_93 ) )
return;
if ( ( V_15 -> V_45 || V_15 -> V_46 ) && F_218 ( V_195 -> V_68 . V_93 ) )
return;
V_15 -> V_42 &= ~ V_540 ;
}
void F_83 ( struct V_194 * V_195 )
{
struct V_4 * V_5 = V_195 -> V_5 ;
if ( V_5 -> V_215 -> V_216 ) {
struct V_14 * V_15 = V_195 -> V_15 ;
struct V_541 * V_542 = & V_15 -> V_3 -> V_543 ;
if ( F_5 ( V_195 -> V_159 ) )
V_195 -> V_42 |= V_239 ;
if ( F_5 ( F_219 ( V_195 -> V_108 ) ) ) {
F_215 ( V_195 ) ;
F_214 ( V_195 ) ;
return;
}
if ( F_5 ( V_195 -> V_42 & V_239 ) ) {
F_215 ( V_195 ) ;
F_220 ( V_195 ) ;
return;
}
F_200 ( V_5 -> V_212 & V_213 ) ;
if ( V_195 -> V_42 & V_229 )
F_215 ( V_195 ) ;
switch ( V_195 -> V_68 . V_71 ) {
case V_520 :
if ( V_195 -> V_68 . V_72 != V_544 &&
V_195 -> V_68 . V_72 != V_545 )
break;
case V_524 :
case V_546 :
V_542 -> V_547 [ V_15 -> V_24 ] |= V_548 ;
F_221 ( V_5 ) ;
break;
case V_549 :
V_15 -> V_42 |= V_550 ;
break;
}
if ( F_5 ( V_15 -> V_42 & V_540 ) )
F_216 ( V_195 ) ;
F_214 ( V_195 ) ;
} else {
if ( V_195 -> V_42 & V_551 )
return;
if ( V_195 -> V_159 || V_195 -> V_42 & V_229 )
F_215 ( V_195 ) ;
F_214 ( V_195 ) ;
}
}
int F_222 ( struct V_4 * V_5 , T_1 V_221 )
{
int V_552 = 0 ;
T_1 V_553 ;
V_553 = V_5 -> V_221 ^ V_221 ;
if ( F_5 ( V_553 & V_221 ) ) {
F_223 ( V_5 , L_155 ,
V_5 -> V_221 , V_221 ) ;
return - V_119 ;
}
while ( V_553 ) {
struct V_194 * V_195 ;
unsigned int V_108 = F_224 ( V_553 ) ;
V_195 = F_225 ( V_5 , V_108 ) ;
if ( V_195 ) {
F_83 ( V_195 ) ;
V_552 ++ ;
}
V_553 &= ~ ( 1 << V_108 ) ;
}
return V_552 ;
}
void F_75 ( struct V_194 * V_195 )
{
struct V_4 * V_5 = V_195 -> V_5 ;
struct V_2 * V_3 = V_195 -> V_15 -> V_3 ;
T_2 V_554 = V_195 -> V_68 . V_93 ;
F_200 ( V_5 -> V_215 -> V_216 && F_205 ( V_3 -> V_219 ) ) ;
if ( F_226 ( V_554 ) ) {
F_200 ( V_3 -> V_220 & ( 1 << V_195 -> V_108 ) ) ;
if ( ! V_3 -> V_220 )
V_5 -> V_222 ++ ;
V_3 -> V_220 |= 1 << V_195 -> V_108 ;
} else {
F_200 ( V_3 -> V_220 ) ;
V_5 -> V_222 ++ ;
V_3 -> V_219 = V_195 -> V_108 ;
}
V_195 -> V_42 |= V_236 ;
V_5 -> V_221 |= 1 << V_195 -> V_108 ;
if ( F_200 ( F_227 ( V_554 ) &&
( ! V_195 -> V_231 || ! V_195 -> V_203 || ! V_195 -> V_233 ) ) )
goto V_555;
if ( F_228 ( V_554 ) || ( F_218 ( V_554 ) &&
( V_5 -> V_42 & V_556 ) ) )
if ( F_207 ( V_195 ) )
goto V_555;
if ( F_5 ( V_195 -> V_15 -> V_42 & V_550 ) ) {
V_3 -> V_543 . V_495 |= V_557 ;
F_229 ( & V_3 -> V_543 , L_156 ) ;
F_230 ( V_3 ) ;
return;
}
V_5 -> V_215 -> V_558 ( V_195 ) ;
V_195 -> V_159 |= V_5 -> V_215 -> V_559 ( V_195 ) ;
if ( F_5 ( V_195 -> V_159 ) )
goto V_560;
return;
V_555:
V_195 -> V_159 |= V_214 ;
V_560:
F_83 ( V_195 ) ;
}
int F_104 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
return ( V_5 -> V_42 & V_449 ) && V_5 -> V_215 -> V_561 ;
}
int F_127 ( struct V_2 * V_3 , int V_562 , T_1 * V_563 )
{
if ( F_13 ( V_3 ) ) {
if ( F_104 ( V_3 ) )
return V_3 -> V_5 -> V_215 -> V_561 ( V_3 , V_562 , V_563 ) ;
return - V_393 ;
}
return F_231 ( V_3 , V_562 , V_563 ) ;
}
int F_153 ( struct V_2 * V_3 , int V_562 , T_1 V_563 )
{
if ( F_13 ( V_3 ) ) {
if ( F_104 ( V_3 ) )
return V_3 -> V_5 -> V_215 -> V_564 ( V_3 , V_562 , V_563 ) ;
return - V_393 ;
}
return F_232 ( V_3 , V_562 , V_563 ) ;
}
int F_185 ( struct V_2 * V_3 , int V_562 , T_1 V_563 )
{
if ( F_13 ( V_3 ) ) {
int V_182 ;
if ( F_104 ( V_3 ) ) {
V_182 = V_3 -> V_5 -> V_215 -> V_564 ( V_3 , V_562 , V_563 ) ;
if ( V_182 == 0 )
V_182 = V_3 -> V_5 -> V_215 -> V_561 ( V_3 , V_562 , & V_563 ) ;
return V_182 ;
}
return - V_393 ;
}
return F_232 ( V_3 , V_562 , V_563 ) ;
}
bool F_145 ( struct V_2 * V_3 )
{
T_1 V_1 ;
if ( F_127 ( V_3 , V_388 , & V_1 ) == 0 &&
F_1 ( V_1 ) )
return true ;
return false ;
}
bool F_183 ( struct V_2 * V_3 )
{
T_1 V_1 ;
if ( F_127 ( V_3 , V_388 , & V_1 ) == 0 &&
! F_1 ( V_1 ) )
return true ;
return false ;
}
bool F_171 ( struct V_2 * V_3 )
{
struct V_2 * V_565 = V_3 -> V_5 -> V_12 ;
F_87 ( V_3 == V_565 ) ;
return F_145 ( V_3 ) ||
( V_565 && F_145 ( V_565 ) ) ;
}
bool F_172 ( struct V_2 * V_3 )
{
struct V_2 * V_565 = V_3 -> V_5 -> V_12 ;
F_87 ( V_3 == V_565 ) ;
return F_183 ( V_3 ) &&
( ! V_565 || F_183 ( V_565 ) ) ;
}
static void F_233 ( struct V_4 * V_5 , T_6 V_566 ,
unsigned int V_495 , unsigned int V_567 ,
bool V_568 )
{
struct V_2 * V_3 ;
unsigned long V_42 ;
if ( V_5 -> V_212 & V_569 ) {
F_234 ( V_5 ) ;
F_87 ( V_5 -> V_212 & V_569 ) ;
}
F_67 ( V_5 -> V_211 , V_42 ) ;
V_5 -> V_570 = V_566 ;
V_5 -> V_212 |= V_569 ;
F_198 (link, ap, HOST_FIRST) {
V_3 -> V_543 . V_495 |= V_495 ;
V_3 -> V_543 . V_42 |= V_567 ;
}
F_221 ( V_5 ) ;
F_68 ( V_5 -> V_211 , V_42 ) ;
if ( ! V_568 ) {
F_234 ( V_5 ) ;
F_87 ( V_5 -> V_212 & V_569 ) ;
}
}
static void F_235 ( struct V_4 * V_5 , T_6 V_566 )
{
F_233 ( V_5 , V_566 , 0 , V_571 , false ) ;
}
static void F_236 ( struct V_4 * V_5 , T_6 V_566 )
{
F_233 ( V_5 , V_566 , 0 , V_571 , true ) ;
}
static int F_237 ( struct V_21 * V_15 )
{
struct V_4 * V_5 = F_238 ( V_15 ) ;
if ( F_239 ( V_15 ) )
return 0 ;
F_235 ( V_5 , V_572 ) ;
return 0 ;
}
static int F_240 ( struct V_21 * V_15 )
{
struct V_4 * V_5 = F_238 ( V_15 ) ;
if ( F_239 ( V_15 ) )
return 0 ;
F_235 ( V_5 , V_573 ) ;
return 0 ;
}
static int F_241 ( struct V_21 * V_15 )
{
F_235 ( F_238 ( V_15 ) , V_574 ) ;
return 0 ;
}
static void F_242 ( struct V_4 * V_5 , T_6 V_566 )
{
F_233 ( V_5 , V_566 , V_557 , V_575 , false ) ;
}
static void F_243 ( struct V_4 * V_5 , T_6 V_566 )
{
F_233 ( V_5 , V_566 , V_557 , V_575 , true ) ;
}
static int F_244 ( struct V_21 * V_15 )
{
F_243 ( F_238 ( V_15 ) , V_576 ) ;
F_245 ( V_15 ) ;
F_246 ( V_15 ) ;
F_247 ( V_15 ) ;
return 0 ;
}
static int F_248 ( struct V_21 * V_15 )
{
struct V_4 * V_5 = F_238 ( V_15 ) ;
struct V_2 * V_3 ;
struct V_14 * V_246 ;
F_198 (link, ap, HOST_FIRST) {
F_140 (adev, link, ENABLED)
if ( V_246 -> V_183 == V_139 &&
! F_249 ( V_246 ) )
return - V_474 ;
}
return 0 ;
}
static int F_250 ( struct V_21 * V_15 )
{
F_235 ( F_238 ( V_15 ) , V_577 ) ;
return 0 ;
}
static int F_251 ( struct V_21 * V_15 )
{
F_242 ( F_238 ( V_15 ) , V_578 ) ;
return 0 ;
}
void F_252 ( struct V_4 * V_5 )
{
F_236 ( V_5 , V_572 ) ;
}
void F_253 ( struct V_4 * V_5 )
{
F_243 ( V_5 , V_576 ) ;
}
int F_254 ( struct V_518 * V_274 , T_6 V_566 )
{
V_274 -> V_15 -> V_579 . V_580 = V_566 ;
return 0 ;
}
void F_255 ( struct V_518 * V_274 )
{
V_274 -> V_15 -> V_579 . V_580 = V_581 ;
}
void F_256 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = F_9 ( V_15 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_42 ;
V_3 -> V_282 = V_3 -> V_40 ;
V_3 -> V_283 = 0 ;
F_67 ( V_5 -> V_211 , V_42 ) ;
V_15 -> V_42 &= ~ V_582 ;
V_15 -> V_48 = 0 ;
F_68 ( V_5 -> V_211 , V_42 ) ;
memset ( ( void * ) V_15 + V_583 , 0 ,
V_584 - V_583 ) ;
V_15 -> V_44 = V_396 ;
V_15 -> V_45 = V_396 ;
V_15 -> V_46 = V_396 ;
}
void F_257 ( struct V_4 * V_5 , struct V_2 * V_3 , int V_38 )
{
int V_25 ;
memset ( ( void * ) V_3 + V_585 , 0 ,
V_586 - V_585 ) ;
V_3 -> V_5 = V_5 ;
V_3 -> V_38 = V_38 ;
V_3 -> V_219 = V_223 ;
V_3 -> V_40 = V_396 ;
for ( V_25 = 0 ; V_25 < V_375 ; V_25 ++ ) {
struct V_14 * V_15 = & V_3 -> V_21 [ V_25 ] ;
V_15 -> V_3 = V_3 ;
V_15 -> V_24 = V_15 - V_3 -> V_21 ;
#ifdef F_258
V_15 -> V_587 = V_588 ;
#endif
F_256 ( V_15 ) ;
}
}
int F_259 ( struct V_2 * V_3 )
{
T_2 V_136 ;
int V_182 ;
V_182 = F_127 ( V_3 , V_389 , & V_3 -> V_589 ) ;
if ( V_182 )
return V_182 ;
V_136 = ( V_3 -> V_589 >> 4 ) & 0xf ;
if ( V_136 )
V_3 -> V_40 &= ( 1 << V_136 ) - 1 ;
F_12 ( V_3 ) ;
V_3 -> V_282 = V_3 -> V_40 ;
return 0 ;
}
struct V_4 * F_260 ( struct V_518 * V_274 )
{
struct V_4 * V_5 ;
F_30 ( L_131 ) ;
V_5 = F_261 ( sizeof( * V_5 ) , V_590 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_212 |= V_591 | V_213 ;
V_5 -> V_211 = & V_274 -> V_211 ;
V_5 -> V_31 = - 1 ;
V_5 -> V_592 = - 1 ;
V_5 -> V_274 = V_274 ;
V_5 -> V_15 = V_274 -> V_15 ;
#if F_262 ( V_593 )
V_5 -> V_594 = 0x00FF ;
#elif F_262 ( V_595 )
V_5 -> V_594 = V_596 | V_597 | V_598 | V_599 | V_600 ;
#else
V_5 -> V_594 = V_596 | V_600 | V_599 ;
#endif
F_263 ( & V_5 -> V_601 ) ;
F_264 ( & V_5 -> V_602 , V_603 ) ;
F_265 ( & V_5 -> V_604 , V_605 ) ;
F_266 ( & V_5 -> V_606 ) ;
F_267 ( & V_5 -> V_607 ) ;
F_268 ( & V_5 -> V_608 ) ;
F_269 ( & V_5 -> V_609 ) ;
V_5 -> V_609 . V_610 = V_611 ;
V_5 -> V_609 . V_612 = ( unsigned long ) V_5 ;
V_5 -> V_33 = V_34 ;
F_257 ( V_5 , & V_5 -> V_3 , 0 ) ;
#ifdef F_270
V_5 -> V_613 . V_614 = 1 ;
V_5 -> V_613 . V_615 = 1 ;
#endif
F_271 ( V_5 ) ;
return V_5 ;
}
static void F_272 ( struct V_21 * V_616 , void * V_617 )
{
struct V_518 * V_274 = F_273 ( V_616 ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_274 -> V_618 ; V_25 ++ ) {
struct V_4 * V_5 = V_274 -> V_619 [ V_25 ] ;
if ( ! V_5 )
continue;
if ( V_5 -> V_294 )
F_274 ( V_5 -> V_294 ) ;
F_275 ( V_5 -> V_11 ) ;
F_275 ( V_5 -> V_12 ) ;
F_275 ( V_5 ) ;
V_274 -> V_619 [ V_25 ] = NULL ;
}
F_276 ( V_616 , NULL ) ;
}
struct V_518 * F_277 ( struct V_21 * V_15 , int V_620 )
{
struct V_518 * V_274 ;
T_5 V_621 ;
int V_25 ;
F_30 ( L_131 ) ;
if ( ! F_278 ( V_15 , NULL , V_590 ) )
return NULL ;
V_621 = sizeof( struct V_518 ) + ( V_620 + 1 ) * sizeof( void * ) ;
V_274 = F_279 ( F_272 , V_621 , V_590 ) ;
if ( ! V_274 )
goto V_265;
F_280 ( V_15 , V_274 ) ;
F_276 ( V_15 , V_274 ) ;
F_281 ( & V_274 -> V_211 ) ;
F_263 ( & V_274 -> V_622 ) ;
V_274 -> V_15 = V_15 ;
V_274 -> V_618 = V_620 ;
for ( V_25 = 0 ; V_25 < V_620 ; V_25 ++ ) {
struct V_4 * V_5 ;
V_5 = F_260 ( V_274 ) ;
if ( ! V_5 )
goto V_265;
V_5 -> V_623 = V_25 ;
V_274 -> V_619 [ V_25 ] = V_5 ;
}
F_282 ( V_15 , NULL ) ;
return V_274 ;
V_265:
F_283 ( V_15 , NULL ) ;
return NULL ;
}
struct V_518 * F_284 ( struct V_21 * V_15 ,
const struct V_624 * const * V_625 ,
int V_618 )
{
const struct V_624 * V_626 ;
struct V_518 * V_274 ;
int V_25 , V_338 ;
V_274 = F_277 ( V_15 , V_618 ) ;
if ( ! V_274 )
return NULL ;
for ( V_25 = 0 , V_338 = 0 , V_626 = NULL ; V_25 < V_274 -> V_618 ; V_25 ++ ) {
struct V_4 * V_5 = V_274 -> V_619 [ V_25 ] ;
if ( V_625 [ V_338 ] )
V_626 = V_625 [ V_338 ++ ] ;
V_5 -> V_44 = V_626 -> V_44 ;
V_5 -> V_45 = V_626 -> V_45 ;
V_5 -> V_46 = V_626 -> V_46 ;
V_5 -> V_42 |= V_626 -> V_42 ;
V_5 -> V_3 . V_42 |= V_626 -> V_627 ;
V_5 -> V_215 = V_626 -> V_628 ;
if ( ! V_274 -> V_215 && ( V_626 -> V_628 != & V_629 ) )
V_274 -> V_215 = V_626 -> V_628 ;
}
return V_274 ;
}
int F_285 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
F_87 ( V_5 -> V_12 ) ;
F_87 ( V_5 -> V_42 & V_630 ) ;
V_3 = F_261 ( sizeof( * V_3 ) , V_590 ) ;
if ( ! V_3 )
return - V_631 ;
F_257 ( V_5 , V_3 , 1 ) ;
V_5 -> V_12 = V_3 ;
return 0 ;
}
static void F_286 ( struct V_21 * V_616 , void * V_617 )
{
struct V_518 * V_274 = F_273 ( V_616 ) ;
int V_25 ;
F_87 ( ! ( V_274 -> V_42 & V_632 ) ) ;
for ( V_25 = 0 ; V_25 < V_274 -> V_618 ; V_25 ++ ) {
struct V_4 * V_5 = V_274 -> V_619 [ V_25 ] ;
if ( V_5 -> V_215 -> V_633 )
V_5 -> V_215 -> V_633 ( V_5 ) ;
}
if ( V_274 -> V_215 -> V_634 )
V_274 -> V_215 -> V_634 ( V_274 ) ;
}
static void F_287 ( struct V_635 * V_215 )
{
static F_288 ( V_211 ) ;
const struct V_635 * V_482 ;
void * * V_636 = ( void * * ) V_215 ;
void * * V_637 = ( void * * ) & V_215 -> V_638 ;
void * * V_639 ;
if ( ! V_215 || ! V_215 -> V_638 )
return;
F_289 ( & V_211 ) ;
for ( V_482 = V_215 -> V_638 ; V_482 ; V_482 = V_482 -> V_638 ) {
void * * V_640 = ( void * * ) V_482 ;
for ( V_639 = V_636 ; V_639 < V_637 ; V_639 ++ , V_640 ++ )
if ( ! * V_639 )
* V_639 = * V_640 ;
}
for ( V_639 = V_636 ; V_639 < V_637 ; V_639 ++ )
if ( F_290 ( * V_639 ) )
* V_639 = NULL ;
V_215 -> V_638 = NULL ;
F_291 ( & V_211 ) ;
}
int F_292 ( struct V_518 * V_274 )
{
int V_641 = 0 ;
void * V_642 = NULL ;
int V_25 , V_182 ;
if ( V_274 -> V_42 & V_632 )
return 0 ;
F_287 ( V_274 -> V_215 ) ;
for ( V_25 = 0 ; V_25 < V_274 -> V_618 ; V_25 ++ ) {
struct V_4 * V_5 = V_274 -> V_619 [ V_25 ] ;
F_287 ( V_5 -> V_215 ) ;
if ( ! V_274 -> V_215 && ! F_293 ( V_5 ) )
V_274 -> V_215 = V_5 -> V_215 ;
if ( V_5 -> V_215 -> V_633 )
V_641 = 1 ;
}
if ( V_274 -> V_215 -> V_634 )
V_641 = 1 ;
if ( V_641 ) {
V_642 = F_279 ( F_286 , 0 , V_590 ) ;
if ( ! V_642 )
return - V_631 ;
}
for ( V_25 = 0 ; V_25 < V_274 -> V_618 ; V_25 ++ ) {
struct V_4 * V_5 = V_274 -> V_619 [ V_25 ] ;
if ( V_5 -> V_215 -> V_643 ) {
V_182 = V_5 -> V_215 -> V_643 ( V_5 ) ;
if ( V_182 ) {
if ( V_182 != - V_264 )
F_294 ( V_274 -> V_15 ,
L_157 ,
V_25 , V_182 ) ;
goto V_265;
}
}
F_295 ( V_5 ) ;
}
if ( V_642 )
F_280 ( V_274 -> V_15 , V_642 ) ;
V_274 -> V_42 |= V_632 ;
return 0 ;
V_265:
while ( -- V_25 >= 0 ) {
struct V_4 * V_5 = V_274 -> V_619 [ V_25 ] ;
if ( V_5 -> V_215 -> V_633 )
V_5 -> V_215 -> V_633 ( V_5 ) ;
}
F_296 ( V_642 ) ;
return V_182 ;
}
void F_297 ( struct V_518 * V_274 , struct V_21 * V_15 ,
struct V_635 * V_215 )
{
F_281 ( & V_274 -> V_211 ) ;
F_263 ( & V_274 -> V_622 ) ;
V_274 -> V_534 = V_296 - 1 ;
V_274 -> V_15 = V_15 ;
V_274 -> V_215 = V_215 ;
}
void F_298 ( struct V_4 * V_5 )
{
struct V_541 * V_542 = & V_5 -> V_3 . V_543 ;
unsigned long V_42 ;
F_67 ( V_5 -> V_211 , V_42 ) ;
V_542 -> V_644 |= V_645 ;
V_542 -> V_495 |= V_557 ;
V_542 -> V_42 |= V_646 | V_647 ;
V_5 -> V_212 &= ~ V_591 ;
V_5 -> V_212 |= V_648 ;
F_221 ( V_5 ) ;
F_68 ( V_5 -> V_211 , V_42 ) ;
}
int F_299 ( struct V_4 * V_5 )
{
int V_182 = 0 ;
if ( V_5 -> V_215 -> V_216 ) {
F_298 ( V_5 ) ;
F_234 ( V_5 ) ;
} else {
F_30 ( L_158 , V_5 -> V_31 ) ;
V_182 = F_139 ( V_5 ) ;
F_30 ( L_159 , V_5 -> V_31 ) ;
}
return V_182 ;
}
static void F_300 ( void * V_612 , T_7 V_649 )
{
struct V_4 * V_5 = V_612 ;
if ( ! ( V_5 -> V_274 -> V_42 & V_469 ) && V_5 -> V_623 != 0 )
F_301 ( V_649 ) ;
( void ) F_299 ( V_5 ) ;
F_301 ( V_649 ) ;
F_302 ( V_5 , 1 ) ;
}
int F_303 ( struct V_518 * V_274 , struct V_650 * V_651 )
{
int V_25 , V_182 ;
V_274 -> V_534 = F_304 ( V_651 -> V_295 , 1 , V_296 - 1 ) ;
if ( ! ( V_274 -> V_42 & V_632 ) ) {
F_294 ( V_274 -> V_15 , L_160 ) ;
F_87 ( 1 ) ;
return - V_119 ;
}
for ( V_25 = V_274 -> V_618 ; V_274 -> V_619 [ V_25 ] ; V_25 ++ )
F_275 ( V_274 -> V_619 [ V_25 ] ) ;
for ( V_25 = 0 ; V_25 < V_274 -> V_618 ; V_25 ++ ) {
V_274 -> V_619 [ V_25 ] -> V_31 = F_305 ( & V_652 ) ;
V_274 -> V_619 [ V_25 ] -> V_592 = V_25 + 1 ;
}
for ( V_25 = 0 ; V_25 < V_274 -> V_618 ; V_25 ++ ) {
V_182 = F_306 ( V_274 -> V_15 , V_274 -> V_619 [ V_25 ] ) ;
if ( V_182 ) {
goto V_653;
}
}
V_182 = F_307 ( V_274 , V_651 ) ;
if ( V_182 )
goto V_653;
for ( V_25 = 0 ; V_25 < V_274 -> V_618 ; V_25 ++ ) {
struct V_4 * V_5 = V_274 -> V_619 [ V_25 ] ;
unsigned long V_47 ;
if ( V_5 -> V_33 == V_34 && ( V_5 -> V_42 & V_449 ) )
V_5 -> V_33 = V_286 ;
F_259 ( & V_5 -> V_3 ) ;
if ( V_5 -> V_12 )
F_259 ( V_5 -> V_12 ) ;
V_47 = F_31 ( V_5 -> V_44 , V_5 -> V_45 ,
V_5 -> V_46 ) ;
if ( ! F_293 ( V_5 ) ) {
V_624 ( V_5 , L_161 ,
( V_5 -> V_42 & V_449 ) ? 'S' : 'P' ,
F_36 ( V_47 ) ,
V_5 -> V_3 . V_543 . V_287 ) ;
F_308 ( & V_5 -> V_3 . V_543 ) ;
} else
V_624 ( V_5 , L_162 ) ;
}
for ( V_25 = 0 ; V_25 < V_274 -> V_618 ; V_25 ++ ) {
struct V_4 * V_5 = V_274 -> V_619 [ V_25 ] ;
F_309 ( F_300 , V_5 ) ;
}
return 0 ;
V_653:
while ( -- V_25 >= 0 ) {
F_310 ( V_274 -> V_619 [ V_25 ] ) ;
}
return V_182 ;
}
int F_311 ( struct V_518 * V_274 , int V_654 ,
T_8 V_655 , unsigned long V_656 ,
struct V_650 * V_651 )
{
int V_25 , V_182 ;
V_182 = F_292 ( V_274 ) ;
if ( V_182 )
return V_182 ;
if ( ! V_654 ) {
F_87 ( V_655 ) ;
return F_303 ( V_274 , V_651 ) ;
}
V_182 = F_312 ( V_274 -> V_15 , V_654 , V_655 , V_656 ,
F_313 ( V_274 -> V_15 ) , V_274 ) ;
if ( V_182 )
return V_182 ;
for ( V_25 = 0 ; V_25 < V_274 -> V_618 ; V_25 ++ )
F_314 ( V_274 -> V_619 [ V_25 ] , L_163 , V_654 ) ;
V_182 = F_303 ( V_274 , V_651 ) ;
if ( V_182 )
F_315 ( V_274 -> V_15 , V_654 , V_274 ) ;
return V_182 ;
}
static void F_316 ( struct V_4 * V_5 )
{
unsigned long V_42 ;
struct V_2 * V_3 ;
struct V_14 * V_15 ;
if ( ! V_5 -> V_215 -> V_216 )
goto V_657;
F_67 ( V_5 -> V_211 , V_42 ) ;
V_5 -> V_212 |= V_658 ;
F_221 ( V_5 ) ;
F_68 ( V_5 -> V_211 , V_42 ) ;
F_234 ( V_5 ) ;
F_87 ( ! ( V_5 -> V_212 & V_659 ) ) ;
F_317 ( & V_5 -> V_602 ) ;
V_657:
F_198 (link, ap, HOST_FIRST) {
F_140 (dev, link, ALL) {
if ( F_249 ( V_15 ) )
F_318 ( V_15 ) ;
}
}
if ( V_5 -> V_11 ) {
int V_25 ;
for ( V_25 = 0 ; V_25 < V_660 ; V_25 ++ )
F_319 ( & V_5 -> V_11 [ V_25 ] ) ;
}
F_320 ( V_5 -> V_294 ) ;
F_310 ( V_5 ) ;
}
void F_321 ( struct V_518 * V_274 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_274 -> V_618 ; V_25 ++ )
F_316 ( V_274 -> V_619 [ V_25 ] ) ;
F_322 ( V_274 ) ;
}
void F_323 ( struct V_661 * V_662 )
{
struct V_518 * V_274 = F_324 ( V_662 ) ;
F_321 ( V_274 ) ;
}
int F_325 ( struct V_661 * V_662 , const struct V_663 * V_132 )
{
unsigned long V_387 = 0 ;
switch ( V_132 -> V_664 ) {
case 1 : {
T_2 V_665 = 0 ;
F_326 ( V_662 , V_132 -> V_562 , & V_665 ) ;
V_387 = V_665 ;
break;
}
case 2 : {
T_4 V_666 = 0 ;
F_327 ( V_662 , V_132 -> V_562 , & V_666 ) ;
V_387 = V_666 ;
break;
}
case 4 : {
T_1 V_667 = 0 ;
F_328 ( V_662 , V_132 -> V_562 , & V_667 ) ;
V_387 = V_667 ;
break;
}
default:
return - V_119 ;
}
V_387 &= V_132 -> V_391 ;
return ( V_387 == V_132 -> V_563 ) ? 1 : 0 ;
}
void F_329 ( struct V_661 * V_662 , T_6 V_566 )
{
F_330 ( V_662 ) ;
F_331 ( V_662 ) ;
if ( V_566 . V_668 & V_669 )
F_332 ( V_662 , V_670 ) ;
}
int F_333 ( struct V_661 * V_662 )
{
int V_182 ;
F_332 ( V_662 , V_671 ) ;
F_334 ( V_662 ) ;
V_182 = F_335 ( V_662 ) ;
if ( V_182 ) {
F_294 ( & V_662 -> V_15 ,
L_164 , V_182 ) ;
return V_182 ;
}
F_336 ( V_662 ) ;
return 0 ;
}
int F_337 ( struct V_661 * V_662 , T_6 V_566 )
{
struct V_518 * V_274 = F_324 ( V_662 ) ;
int V_182 = 0 ;
V_182 = F_254 ( V_274 , V_566 ) ;
if ( V_182 )
return V_182 ;
F_329 ( V_662 , V_566 ) ;
return 0 ;
}
int F_338 ( struct V_661 * V_662 )
{
struct V_518 * V_274 = F_324 ( V_662 ) ;
int V_182 ;
V_182 = F_333 ( V_662 ) ;
if ( V_182 == 0 )
F_255 ( V_274 ) ;
return V_182 ;
}
int F_339 ( struct V_672 * V_662 )
{
struct V_518 * V_274 = F_340 ( V_662 ) ;
F_321 ( V_274 ) ;
return 0 ;
}
static int T_9 F_341 ( char * * V_482 ,
struct V_27 * V_673 ,
const char * * V_256 )
{
static struct V_674 V_675 [] V_676 = {
{ L_165 , . V_33 = V_370 } ,
{ L_166 , . V_33 = V_371 } ,
{ L_167 , . V_33 = V_517 } ,
{ L_168 , . V_33 = V_372 } ,
{ L_169 , . V_33 = V_373 } ,
{ L_170 , . V_33 = V_286 } ,
{ L_171 , . V_39 = 1 } ,
{ L_172 , . V_39 = 2 } ,
{ L_173 , . V_49 = V_292 } ,
{ L_174 , . V_50 = V_292 } ,
{ L_175 , . V_49 = V_271 } ,
{ L_176 , . V_47 = 1 << ( V_121 + 0 ) } ,
{ L_177 , . V_47 = 1 << ( V_121 + 1 ) } ,
{ L_178 , . V_47 = 1 << ( V_121 + 2 ) } ,
{ L_179 , . V_47 = 1 << ( V_121 + 3 ) } ,
{ L_180 , . V_47 = 1 << ( V_121 + 4 ) } ,
{ L_181 , . V_47 = 1 << ( V_121 + 5 ) } ,
{ L_182 , . V_47 = 1 << ( V_121 + 6 ) } ,
{ L_183 , . V_47 = 1 << ( V_123 + 0 ) } ,
{ L_184 , . V_47 = 1 << ( V_123 + 1 ) } ,
{ L_185 , . V_47 = 1 << ( V_123 + 2 ) } ,
{ L_186 , . V_47 = 1 << ( V_123 + 3 ) } ,
{ L_187 , . V_47 = 1 << ( V_123 + 4 ) } ,
{ L_188 , . V_47 = 1 << ( V_125 + 0 ) } ,
{ L_189 , . V_47 = 1 << ( V_125 + 0 ) } ,
{ L_190 , . V_47 = 1 << ( V_125 + 0 ) } ,
{ L_191 , . V_47 = 1 << ( V_125 + 1 ) } ,
{ L_192 , . V_47 = 1 << ( V_125 + 1 ) } ,
{ L_193 , . V_47 = 1 << ( V_125 + 1 ) } ,
{ L_194 , . V_47 = 1 << ( V_125 + 2 ) } ,
{ L_195 , . V_47 = 1 << ( V_125 + 2 ) } ,
{ L_196 , . V_47 = 1 << ( V_125 + 2 ) } ,
{ L_197 , . V_47 = 1 << ( V_125 + 3 ) } ,
{ L_198 , . V_47 = 1 << ( V_125 + 3 ) } ,
{ L_199 , . V_47 = 1 << ( V_125 + 3 ) } ,
{ L_200 , . V_47 = 1 << ( V_125 + 4 ) } ,
{ L_201 , . V_47 = 1 << ( V_125 + 4 ) } ,
{ L_202 , . V_47 = 1 << ( V_125 + 4 ) } ,
{ L_203 , . V_47 = 1 << ( V_125 + 5 ) } ,
{ L_204 , . V_47 = 1 << ( V_125 + 5 ) } ,
{ L_205 , . V_47 = 1 << ( V_125 + 5 ) } ,
{ L_206 , . V_47 = 1 << ( V_125 + 6 ) } ,
{ L_207 , . V_47 = 1 << ( V_125 + 6 ) } ,
{ L_208 , . V_47 = 1 << ( V_125 + 6 ) } ,
{ L_209 , . V_47 = 1 << ( V_125 + 7 ) } ,
{ L_210 , . V_41 = V_677 } ,
{ L_211 , . V_41 = V_678 } ,
{ L_212 , . V_41 = V_677 | V_678 } ,
{ L_213 , . V_41 = V_679 } ,
{ L_214 , . V_49 = V_357 } ,
{ L_215 , . V_49 = V_317 } ,
} ;
char * V_465 = * V_482 , * V_149 = * V_482 ;
char * V_144 , * V_563 , * V_680 ;
const struct V_674 * V_681 = NULL ;
int V_682 = 0 , V_25 ;
while ( * V_149 != '\0' && * V_149 != ',' )
V_149 ++ ;
if ( * V_149 == '\0' )
* V_482 = V_149 ;
else
* V_482 = V_149 + 1 ;
* V_149 = '\0' ;
V_149 = strchr ( V_465 , ':' ) ;
if ( ! V_149 ) {
V_563 = F_342 ( V_465 ) ;
goto V_683;
}
* V_149 = '\0' ;
V_144 = F_342 ( V_465 ) ;
V_563 = F_342 ( V_149 + 1 ) ;
V_149 = strchr ( V_144 , '.' ) ;
if ( V_149 ) {
* V_149 ++ = '\0' ;
V_673 -> V_21 = F_343 ( V_149 , & V_680 , 10 ) ;
if ( V_149 == V_680 || * V_680 != '\0' ) {
* V_256 = L_216 ;
return - V_119 ;
}
}
V_673 -> V_30 = F_343 ( V_144 , & V_680 , 10 ) ;
if ( V_149 == V_680 || * V_680 != '\0' ) {
* V_256 = L_217 ;
return - V_119 ;
}
V_683:
for ( V_25 = 0 ; V_25 < F_37 ( V_675 ) ; V_25 ++ ) {
const struct V_674 * V_684 = & V_675 [ V_25 ] ;
if ( strncasecmp ( V_563 , V_684 -> V_35 , strlen ( V_563 ) ) )
continue;
V_682 ++ ;
V_681 = V_684 ;
if ( strcasecmp ( V_563 , V_684 -> V_35 ) == 0 ) {
V_682 = 1 ;
break;
}
}
if ( ! V_682 ) {
* V_256 = L_218 ;
return - V_119 ;
}
if ( V_682 > 1 ) {
* V_256 = L_219 ;
return - V_119 ;
}
V_673 -> V_32 = * V_681 ;
return 0 ;
}
static void T_9 F_344 ( void )
{
int V_685 = 0 , V_686 = 1 ;
int V_687 = - 1 , V_688 = - 1 ;
char * V_149 , * V_482 , * V_23 ;
for ( V_149 = V_689 ; * V_149 ; V_149 ++ )
if ( * V_149 == ',' )
V_686 ++ ;
V_29 = F_261 ( sizeof( V_29 [ 0 ] ) * V_686 , V_590 ) ;
if ( ! V_29 ) {
F_345 ( V_690 L_220
L_221 ) ;
return;
}
for ( V_482 = V_689 ; * V_482 != '\0' ; V_482 = V_23 ) {
const char * V_256 = L_68 ;
struct V_27 V_691 = { . V_30 = - 1 , . V_21 = - 1 } ;
V_23 = V_482 ;
if ( F_341 ( & V_23 , & V_691 , & V_256 ) ) {
F_345 ( V_690 L_222
L_223 ,
V_482 , V_256 ) ;
continue;
}
if ( V_691 . V_30 == - 1 ) {
V_691 . V_30 = V_687 ;
V_691 . V_21 = V_688 ;
}
V_29 [ V_685 ++ ] = V_691 ;
V_687 = V_691 . V_30 ;
V_688 = V_691 . V_21 ;
}
V_26 = V_685 ;
}
static int T_9 F_346 ( void )
{
int V_182 ;
F_344 () ;
V_182 = F_347 () ;
if ( V_182 ) {
F_275 ( V_29 ) ;
return V_182 ;
}
F_348 () ;
V_692 = F_349 () ;
if ( ! V_692 ) {
F_350 () ;
V_182 = - V_631 ;
goto V_265;
}
F_345 ( V_272 L_224 V_693 L_225 ) ;
return 0 ;
V_265:
return V_182 ;
}
static void T_10 F_351 ( void )
{
F_352 ( V_692 ) ;
F_353 () ;
F_350 () ;
F_275 ( V_29 ) ;
}
int F_354 ( void )
{
return F_355 ( & V_694 ) ;
}
void F_174 ( struct V_4 * V_5 , unsigned int V_695 )
{
bool V_696 = V_5 && V_5 -> V_274 -> V_697 == V_698 ;
if ( V_696 )
F_77 ( V_5 ) ;
F_180 ( V_695 ) ;
if ( V_696 )
F_80 ( V_5 ) ;
}
T_1 F_356 ( struct V_4 * V_5 , void T_11 * V_562 , T_1 V_391 , T_1 V_563 ,
unsigned long V_478 , unsigned long V_204 )
{
unsigned long V_464 ;
T_1 V_387 ;
V_387 = F_357 ( V_562 ) ;
V_464 = F_169 ( V_466 , V_204 ) ;
while ( ( V_387 & V_391 ) == V_563 && F_173 ( V_466 , V_464 ) ) {
F_174 ( V_5 , V_478 ) ;
V_387 = F_357 ( V_562 ) ;
}
return V_387 ;
}
static unsigned int F_358 ( struct V_194 * V_195 )
{
return V_214 ;
}
static void F_359 ( struct V_4 * V_5 )
{
}
void F_360 ( const struct V_4 * V_5 , const char * V_699 ,
const char * V_700 , ... )
{
struct V_701 V_702 ;
T_12 args ;
va_start ( args , V_700 ) ;
V_702 . V_700 = V_700 ;
V_702 . V_703 = & args ;
F_345 ( L_226 , V_699 , V_5 -> V_31 , & V_702 ) ;
va_end ( args ) ;
}
void F_361 ( const struct V_2 * V_3 , const char * V_699 ,
const char * V_700 , ... )
{
struct V_701 V_702 ;
T_12 args ;
va_start ( args , V_700 ) ;
V_702 . V_700 = V_700 ;
V_702 . V_703 = & args ;
if ( F_4 ( V_3 -> V_5 ) || V_3 -> V_5 -> V_12 )
F_345 ( L_227 ,
V_699 , V_3 -> V_5 -> V_31 , V_3 -> V_38 , & V_702 ) ;
else
F_345 ( L_226 ,
V_699 , V_3 -> V_5 -> V_31 , & V_702 ) ;
va_end ( args ) ;
}
void F_362 ( const struct V_14 * V_15 , const char * V_699 ,
const char * V_700 , ... )
{
struct V_701 V_702 ;
T_12 args ;
va_start ( args , V_700 ) ;
V_702 . V_700 = V_700 ;
V_702 . V_703 = & args ;
F_345 ( L_227 ,
V_699 , V_15 -> V_3 -> V_5 -> V_31 , V_15 -> V_3 -> V_38 + V_15 -> V_24 ,
& V_702 ) ;
va_end ( args ) ;
}
void F_363 ( const struct V_21 * V_15 , const char * V_704 )
{
F_364 ( V_272 , V_15 , L_228 , V_704 ) ;
}
