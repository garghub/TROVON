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
if ( ! V_15 || V_68 -> V_42 & V_100 ) {
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
V_195 = F_69 ( V_5 , V_108 ) ;
V_195 -> V_108 = V_108 ;
V_195 -> V_217 = NULL ;
V_195 -> V_5 = V_5 ;
V_195 -> V_15 = V_15 ;
F_70 ( V_195 ) ;
V_206 = V_3 -> V_218 ;
V_207 = V_3 -> V_219 ;
V_208 = V_5 -> V_220 ;
V_209 = V_5 -> V_221 ;
V_3 -> V_218 = V_222 ;
V_3 -> V_219 = 0 ;
V_5 -> V_220 = 0 ;
V_5 -> V_221 = 0 ;
V_195 -> V_68 = * V_68 ;
if ( V_199 )
memcpy ( V_195 -> V_199 , V_199 , V_223 ) ;
if ( V_68 -> V_93 == V_224 && ( V_15 -> V_42 & V_225 ) &&
V_200 == V_226 )
V_195 -> V_68 . V_72 |= V_227 ;
V_195 -> V_42 |= V_228 ;
V_195 -> V_200 = V_200 ;
if ( V_200 != V_163 ) {
unsigned int V_25 , V_229 = 0 ;
struct V_201 * V_230 ;
F_71 (sgl, sg, n_elem, i)
V_229 += V_230 -> V_231 ;
F_72 ( V_195 , V_202 , V_203 ) ;
V_195 -> V_232 = V_229 ;
}
V_195 -> V_198 = & V_210 ;
V_195 -> V_233 = F_63 ;
F_73 ( V_195 ) ;
F_68 ( V_5 -> V_211 , V_42 ) ;
if ( ! V_204 ) {
if ( V_234 )
V_204 = V_234 * 1000 ;
else {
V_204 = F_74 ( V_15 , V_71 ) ;
V_205 = 1 ;
}
}
if ( V_5 -> V_215 -> V_216 )
F_75 ( V_5 ) ;
V_182 = F_76 ( & V_210 , F_77 ( V_204 ) ) ;
if ( V_5 -> V_215 -> V_216 )
F_78 ( V_5 ) ;
F_79 ( V_5 ) ;
if ( ! V_182 ) {
F_67 ( V_5 -> V_211 , V_42 ) ;
if ( V_195 -> V_42 & V_235 ) {
V_195 -> V_159 |= V_236 ;
if ( V_5 -> V_215 -> V_216 )
F_80 ( V_5 ) ;
else
F_81 ( V_195 ) ;
if ( F_82 ( V_5 ) )
F_24 ( V_15 , L_59 ,
V_71 ) ;
}
F_68 ( V_5 -> V_211 , V_42 ) ;
}
if ( V_5 -> V_215 -> V_237 )
V_5 -> V_215 -> V_237 ( V_195 ) ;
if ( V_195 -> V_42 & V_238 ) {
if ( V_195 -> V_239 . V_71 & ( V_240 | V_241 ) )
V_195 -> V_159 |= V_164 ;
if ( ! V_195 -> V_159 )
V_195 -> V_159 |= V_242 ;
if ( V_195 -> V_159 & ~ V_242 )
V_195 -> V_159 &= ~ V_242 ;
}
F_67 ( V_5 -> V_211 , V_42 ) ;
* V_68 = V_195 -> V_239 ;
V_159 = V_195 -> V_159 ;
F_83 ( V_195 ) ;
V_3 -> V_218 = V_206 ;
V_3 -> V_219 = V_207 ;
V_5 -> V_220 = V_208 ;
V_5 -> V_221 = V_209 ;
F_68 ( V_5 -> V_211 , V_42 ) ;
if ( ( V_159 & V_236 ) && V_205 )
F_84 ( V_15 , V_71 ) ;
return V_159 ;
}
unsigned F_53 ( struct V_14 * V_15 ,
struct V_67 * V_68 , const T_2 * V_199 ,
int V_200 , void * V_243 , unsigned int V_229 ,
unsigned long V_204 )
{
struct V_201 * V_244 = NULL , V_230 ;
unsigned int V_203 = 0 ;
if ( V_200 != V_163 ) {
F_85 ( ! V_243 ) ;
F_86 ( & V_230 , V_243 , V_229 ) ;
V_244 = & V_230 ;
V_203 ++ ;
}
return F_65 ( V_15 , V_68 , V_199 , V_200 , V_244 , V_203 ,
V_204 ) ;
}
unsigned int F_87 ( const struct V_14 * V_245 )
{
if ( V_245 -> V_3 -> V_5 -> V_212 & V_246 )
return 0 ;
if ( V_245 -> V_3 -> V_5 -> V_42 & V_247 )
return 0 ;
if ( F_62 ( V_245 -> V_144 )
&& ( V_245 -> V_248 == V_249 || V_245 -> V_248 == V_250 ) )
return 0 ;
if ( V_245 -> V_248 > V_251 )
return 1 ;
if ( F_88 ( V_245 -> V_144 ) )
return 1 ;
return 0 ;
}
static T_1 F_89 ( const struct V_14 * V_245 )
{
if ( V_245 -> V_144 [ V_186 ] & 2 ) {
T_4 V_190 = V_245 -> V_144 [ V_252 ] ;
if ( V_190 ) {
if ( V_190 > 240 )
return 3 << V_121 ;
return 7 << V_121 ;
}
}
return 3 << V_121 ;
}
unsigned int F_90 ( struct V_14 * V_15 ,
struct V_67 * V_68 , T_4 * V_144 )
{
return F_53 ( V_15 , V_68 , NULL , V_226 ,
V_144 , sizeof( V_144 [ 0 ] ) * V_253 , 0 ) ;
}
int F_91 ( struct V_14 * V_15 , unsigned int * V_254 ,
unsigned int V_42 , T_4 * V_144 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
unsigned int V_183 = * V_254 ;
struct V_67 V_68 ;
unsigned int V_159 = 0 ;
const char * V_255 ;
bool V_256 = V_183 == V_141 ;
int V_257 = 1 , V_258 = 0 ;
int V_182 ;
if ( F_92 ( V_5 ) )
F_93 ( V_15 , L_60 , V_259 ) ;
V_260:
F_52 ( V_15 , & V_68 ) ;
switch ( V_183 ) {
case V_141 :
V_183 = V_138 ;
case V_138 :
case V_142 :
V_68 . V_71 = V_261 ;
break;
case V_139 :
V_68 . V_71 = V_262 ;
break;
default:
V_182 = - V_263 ;
V_255 = L_61 ;
goto V_264;
}
V_68 . V_93 = V_94 ;
V_68 . V_42 |= V_109 | V_110 ;
V_68 . V_42 |= V_265 ;
if ( V_5 -> V_215 -> V_266 )
V_159 = V_5 -> V_215 -> V_266 ( V_15 , & V_68 , V_144 ) ;
else
V_159 = F_90 ( V_15 , & V_68 , V_144 ) ;
if ( V_159 ) {
if ( V_159 & V_267 ) {
F_93 ( V_15 , L_62 ) ;
return - V_268 ;
}
if ( V_256 ) {
F_57 ( V_15 ,
L_63 ) ;
* V_254 = V_269 ;
return 0 ;
}
if ( ( V_159 == V_164 ) && ( V_68 . V_72 & V_165 ) ) {
if ( V_257 ) {
V_257 = 0 ;
if ( V_183 == V_138 )
V_183 = V_139 ;
else
V_183 = V_138 ;
goto V_260;
}
F_93 ( V_15 ,
L_64 ) ;
return - V_268 ;
}
V_182 = - V_167 ;
V_255 = L_65 ;
goto V_264;
}
if ( V_15 -> V_48 & V_270 ) {
F_93 ( V_15 , L_66
L_67 ,
V_183 , V_257 , V_258 ) ;
F_94 ( V_271 , L_68 , V_272 ,
16 , 2 , V_144 , V_253 * sizeof( * V_144 ) , true ) ;
}
V_257 = 0 ;
F_95 ( V_144 , V_253 ) ;
V_182 = - V_119 ;
V_255 = L_69 ;
if ( V_183 == V_138 || V_183 == V_142 ) {
if ( ! F_96 ( V_144 ) && ! F_62 ( V_144 ) )
goto V_264;
if ( V_5 -> V_273 -> V_42 & V_274 &&
F_96 ( V_144 ) ) {
F_93 ( V_15 ,
L_70 ) ;
return - V_268 ;
}
} else {
if ( F_96 ( V_144 ) )
goto V_264;
}
if ( ! V_258 && ( V_144 [ 2 ] == 0x37c8 || V_144 [ 2 ] == 0x738c ) ) {
V_258 = 1 ;
V_159 = F_97 ( V_15 , V_275 , 0 ) ;
if ( V_159 && V_144 [ 2 ] != 0x738c ) {
V_182 = - V_167 ;
V_255 = L_71 ;
goto V_264;
}
if ( V_144 [ 2 ] == 0x37c8 )
goto V_260;
}
if ( ( V_42 & V_276 ) &&
( V_183 == V_138 || V_183 == V_142 ) ) {
if ( F_98 ( V_144 ) < 4 || ! F_44 ( V_144 ) ) {
V_159 = F_99 ( V_15 , V_144 [ 3 ] , V_144 [ 6 ] ) ;
if ( V_159 ) {
V_182 = - V_167 ;
V_255 = L_72 ;
goto V_264;
}
V_42 &= ~ V_276 ;
goto V_260;
}
}
* V_254 = V_183 ;
return 0 ;
V_264:
if ( F_82 ( V_5 ) )
F_24 ( V_15 , L_73 ,
V_255 , V_159 ) ;
return V_182 ;
}
static int F_100 ( struct V_14 * V_15 )
{
struct V_2 * V_277 = F_9 ( V_15 ) ;
T_1 V_278 , V_279 ;
if ( ! F_101 ( V_277 ) )
return 0 ;
if ( V_15 -> V_48 & V_280 )
V_278 = 1 ;
else
return 0 ;
V_279 = ( 1 << V_278 ) - 1 ;
if ( V_277 -> V_281 <= V_279 )
return 0 ;
V_277 -> V_281 = V_279 ;
if ( V_277 -> V_282 > V_278 ) {
F_57 ( V_15 , L_74 ,
F_38 ( V_278 ) ) ;
return - V_283 ;
}
return 0 ;
}
static inline T_2 F_102 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
if ( F_103 ( V_15 ) & V_284 )
return 0 ;
return ( ( V_5 -> V_33 == V_285 ) && ( ! F_104 ( V_15 -> V_144 ) ) ) ;
}
static int F_105 ( struct V_14 * V_15 ,
char * V_286 , T_5 V_287 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
int V_288 = 0 , V_289 = F_106 ( V_15 -> V_144 ) ;
unsigned int V_159 ;
char * V_290 = L_68 ;
if ( ! F_107 ( V_15 -> V_144 ) ) {
V_286 [ 0 ] = '\0' ;
return 0 ;
}
if ( V_15 -> V_48 & V_291 ) {
snprintf ( V_286 , V_287 , L_75 ) ;
return 0 ;
}
if ( V_5 -> V_42 & V_292 ) {
V_288 = F_108 ( V_5 -> V_293 -> V_294 , V_295 - 1 ) ;
V_15 -> V_42 |= V_296 ;
}
if ( ! ( V_15 -> V_48 & V_297 ) &&
( V_5 -> V_42 & V_298 ) &&
F_109 ( V_15 -> V_144 ) ) {
V_159 = F_97 ( V_15 , V_299 ,
V_300 ) ;
if ( V_159 ) {
F_59 ( V_15 ,
L_76 ,
V_159 ) ;
if ( V_159 != V_164 ) {
V_15 -> V_48 |= V_297 ;
return - V_167 ;
}
} else
V_290 = L_77 ;
}
if ( V_288 >= V_289 )
snprintf ( V_286 , V_287 , L_78 , V_289 , V_290 ) ;
else
snprintf ( V_286 , V_287 , L_79 , V_288 ,
V_289 , V_290 ) ;
if ( ( V_5 -> V_42 & V_301 ) &&
F_110 ( V_15 -> V_144 ) ) {
V_159 = F_111 ( V_15 , V_302 ,
0 , V_5 -> V_303 , 1 ) ;
if ( V_159 ) {
F_93 ( V_15 ,
L_80 ,
V_159 ) ;
} else {
T_2 * V_304 = V_15 -> V_305 ;
V_15 -> V_42 |= V_306 ;
memcpy ( V_304 , V_5 -> V_303 , V_307 ) ;
if ( V_15 -> V_48 & V_308 ) {
F_93 ( V_15 , L_81 ) ;
V_304 [ V_309 ] &=
~ V_310 ;
}
}
}
return 0 ;
}
static void F_112 ( struct V_14 * V_15 )
{
unsigned int V_159 ;
if ( ! F_113 ( V_15 -> V_144 ) )
return;
if ( F_114 ( V_15 -> V_144 ) )
return;
V_159 = F_97 ( V_15 , V_311 , 0x1 ) ;
if ( V_159 ) {
F_93 ( V_15 ,
L_82 ,
V_159 ) ;
}
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
F_57 ( V_15 , L_83 , V_259 ) ;
return 0 ;
}
if ( F_117 ( V_5 ) )
F_93 ( V_15 , L_60 , V_259 ) ;
V_15 -> V_48 |= F_103 ( V_15 ) ;
F_18 ( V_15 ) ;
if ( V_15 -> V_48 & V_317 ) {
F_57 ( V_15 , L_84 ) ;
F_118 ( V_15 ) ;
return 0 ;
}
if ( ( ! V_318 || ( V_5 -> V_42 & V_319 ) ) &&
V_15 -> V_183 == V_139 ) {
F_24 ( V_15 , L_85 ,
V_318 ? L_86
: L_87 ) ;
F_118 ( V_15 ) ;
return 0 ;
}
V_182 = F_100 ( V_15 ) ;
if ( V_182 )
return V_182 ;
if ( ( V_15 -> V_48 & V_320 ) &&
( V_144 [ V_321 ] & 0xe ) == 0x2 )
V_15 -> V_48 |= V_322 ;
if ( V_15 -> V_48 & V_322 ) {
F_24 ( V_15 , L_88 ) ;
V_15 -> V_3 -> V_5 -> V_323 = V_324 ;
}
V_182 = F_119 ( V_15 ) ;
if ( V_182 )
return V_182 ;
V_182 = F_55 ( V_15 ) ;
if ( V_182 )
return V_182 ;
if ( F_117 ( V_5 ) )
F_93 ( V_15 ,
L_89
L_90 ,
V_259 ,
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
L_91 ) ;
snprintf ( V_312 , 7 , L_92 ) ;
} else {
snprintf ( V_312 , 7 , L_93 , F_98 ( V_144 ) ) ;
if ( F_120 ( V_144 ) )
F_24 ( V_15 ,
L_91 ) ;
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
V_334 = L_94 ;
V_15 -> V_42 |= V_117 ;
if ( F_45 ( V_144 ) ) {
V_15 -> V_42 |= V_118 ;
V_334 = L_95 ;
if ( V_15 -> V_327 >= ( 1UL << 28 ) &&
F_122 ( V_144 ) )
V_15 -> V_42 |= V_336 ;
}
V_182 = F_105 ( V_15 , V_335 , sizeof( V_335 ) ) ;
if ( V_182 )
return V_182 ;
if ( F_123 ( V_5 ) && V_176 ) {
F_57 ( V_15 , L_96 ,
V_312 , V_315 , V_313 ,
F_36 ( V_47 ) ) ;
F_57 ( V_15 ,
L_97 ,
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
F_57 ( V_15 , L_96 ,
V_312 , V_315 , V_313 ,
F_36 ( V_47 ) ) ;
F_57 ( V_15 ,
L_98 ,
( unsigned long long ) V_15 -> V_327 ,
V_15 -> V_95 , V_15 -> V_328 ,
V_15 -> V_104 , V_15 -> V_105 ) ;
}
}
if ( F_124 ( V_15 -> V_144 ) ) {
T_2 * V_337 = V_5 -> V_303 ;
int V_25 , V_338 ;
V_15 -> V_42 |= V_339 ;
V_159 = F_111 ( V_15 ,
V_340 ,
V_341 ,
V_337 ,
1 ) ;
if ( V_159 )
F_93 ( V_15 ,
L_99 ,
V_159 ) ;
else
for ( V_25 = 0 ; V_25 < V_342 ; V_25 ++ ) {
V_338 = V_343 + V_25 ;
V_15 -> V_344 [ V_25 ] = V_337 [ V_338 ] ;
}
}
F_112 ( V_15 ) ;
V_15 -> V_326 = 16 ;
}
else if ( V_15 -> V_183 == V_139 ) {
const char * V_345 = L_68 ;
const char * V_346 = L_68 ;
const char * V_347 = L_68 ;
T_1 V_348 ;
V_182 = F_125 ( V_144 ) ;
if ( ( V_182 < 12 ) || ( V_182 > V_223 ) ) {
if ( F_82 ( V_5 ) )
F_24 ( V_15 , L_100 ) ;
V_182 = - V_119 ;
goto V_349;
}
V_15 -> V_326 = ( unsigned int ) V_182 ;
if ( V_350 &&
( V_5 -> V_42 & V_351 ) && F_126 ( V_144 ) &&
( ! F_4 ( V_5 ) ||
F_127 ( & V_5 -> V_3 , V_352 , & V_348 ) == 0 ) ) {
V_159 = F_97 ( V_15 ,
V_299 , V_353 ) ;
if ( V_159 )
F_59 ( V_15 ,
L_101 ,
V_159 ) ;
else {
V_15 -> V_42 |= V_354 ;
V_346 = L_102 ;
}
}
if ( F_128 ( V_15 -> V_144 ) ) {
V_15 -> V_42 |= V_355 ;
V_345 = L_103 ;
}
if ( V_356 || ( V_15 -> V_48 & V_357 ) || F_129 ( V_15 -> V_144 ) ) {
V_15 -> V_42 |= V_225 ;
V_347 = L_104 ;
}
if ( F_130 ( V_15 -> V_144 ) ) {
V_15 -> V_42 |= V_358 ;
F_131 ( V_15 ) ;
}
if ( F_123 ( V_5 ) && V_176 )
F_57 ( V_15 ,
L_105 ,
V_315 , V_313 ,
F_36 ( V_47 ) ,
V_345 , V_346 ,
V_347 ) ;
}
V_15 -> V_158 = V_359 ;
if ( V_15 -> V_42 & V_118 )
V_15 -> V_158 = V_360 ;
if ( F_102 ( V_15 ) ) {
if ( F_123 ( V_5 ) && V_176 )
F_57 ( V_15 , L_106 ) ;
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
L_107 ) ;
F_24 ( V_15 ,
L_108 ) ;
}
}
if ( ( V_15 -> V_48 & V_369 ) && V_176 ) {
F_24 ( V_15 , L_109 ) ;
F_24 ( V_15 , L_110 ) ;
}
return 0 ;
V_349:
if ( F_117 ( V_5 ) )
F_93 ( V_15 , L_111 , V_259 ) ;
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
return V_285 ;
}
int F_139 ( struct V_4 * V_5 )
{
unsigned int V_374 [ V_375 ] ;
int V_376 [ V_375 ] ;
int V_182 ;
struct V_14 * V_15 ;
F_140 (dev, &ap->link, ALL)
V_376 [ V_15 -> V_24 ] = V_377 ;
V_260:
F_140 (dev, &ap->link, ALL) {
V_15 -> V_248 = V_378 ;
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
V_182 = F_91 ( V_15 , & V_15 -> V_183 , V_276 ,
V_15 -> V_144 ) ;
if ( V_182 )
goto V_383;
}
if ( V_5 -> V_215 -> V_384 )
V_5 -> V_33 = V_5 -> V_215 -> V_384 ( V_5 ) ;
F_140 (dev, &ap->link, ENABLED)
if ( F_104 ( V_15 -> V_144 ) )
V_5 -> V_33 = V_285 ;
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
return - V_263 ;
V_383:
V_376 [ V_15 -> V_24 ] -- ;
switch ( V_182 ) {
case - V_119 :
V_376 [ V_15 -> V_24 ] = 0 ;
break;
case - V_263 :
V_376 [ V_15 -> V_24 ] = F_108 ( V_376 [ V_15 -> V_24 ] , 1 ) ;
case - V_167 :
if ( V_376 [ V_15 -> V_24 ] == 1 ) {
F_142 ( & V_5 -> V_3 , 0 ) ;
F_143 ( V_15 , V_385 ) ;
}
}
if ( ! V_376 [ V_15 -> V_24 ] )
F_118 ( V_15 ) ;
goto V_260;
}
static void F_144 ( struct V_2 * V_3 )
{
T_1 V_1 , V_386 , V_387 ;
if ( F_127 ( V_3 , V_388 , & V_1 ) )
return;
F_127 ( V_3 , V_389 , & V_386 ) ;
if ( F_145 ( V_3 ) ) {
V_387 = ( V_1 >> 4 ) & 0xf ;
F_146 ( V_3 , L_112 ,
F_38 ( V_387 ) , V_1 , V_386 ) ;
} else {
F_146 ( V_3 , L_113 ,
V_1 , V_386 ) ;
}
}
struct V_14 * F_147 ( struct V_14 * V_245 )
{
struct V_2 * V_3 = V_245 -> V_3 ;
struct V_14 * V_390 = & V_3 -> V_21 [ 1 - V_245 -> V_24 ] ;
if ( ! F_8 ( V_390 ) )
return NULL ;
return V_390 ;
}
int F_142 ( struct V_2 * V_3 , T_1 V_39 )
{
T_1 V_1 , V_136 , V_391 ;
int V_182 , V_392 ;
if ( ! F_101 ( V_3 ) )
return - V_393 ;
V_182 = F_127 ( V_3 , V_388 , & V_1 ) ;
if ( V_182 == 0 && F_1 ( V_1 ) )
V_136 = ( V_1 >> 4 ) & 0xf ;
else
V_136 = V_3 -> V_282 ;
V_391 = V_3 -> V_281 ;
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
V_3 -> V_281 = V_391 ;
F_149 ( V_3 , L_114 ,
F_38 ( F_33 ( V_391 ) ) ) ;
return 0 ;
}
static int F_150 ( struct V_2 * V_3 , T_1 * V_386 )
{
struct V_2 * V_394 = & V_3 -> V_5 -> V_3 ;
T_1 V_395 , V_278 , V_136 ;
V_395 = V_3 -> V_281 ;
if ( ! F_13 ( V_3 ) && V_394 -> V_282 )
V_395 &= ( 1 << V_394 -> V_282 ) - 1 ;
if ( V_395 == V_396 )
V_278 = 0 ;
else
V_278 = F_33 ( V_395 ) ;
V_136 = ( * V_386 >> 4 ) & 0xf ;
* V_386 = ( * V_386 & ~ 0xf0 ) | ( ( V_278 & 0xf ) << 4 ) ;
return V_136 != V_278 ;
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
F_158 ( true , L_115 ,
V_259 , V_134 ) ;
return NULL ;
}
int F_159 ( struct V_14 * V_245 , unsigned short V_424 ,
struct V_397 * V_398 , int V_400 , int V_401 )
{
const T_4 * V_144 = V_245 -> V_144 ;
const struct V_397 * V_145 ;
struct V_397 V_149 ;
if ( ! ( V_145 = F_157 ( V_424 ) ) )
return - V_119 ;
memcpy ( V_398 , V_145 , sizeof( * V_145 ) ) ;
if ( V_144 [ V_186 ] & 2 ) {
memset ( & V_149 , 0 , sizeof( V_149 ) ) ;
if ( V_424 >= V_378 && V_424 < V_425 ) {
if ( V_424 <= V_251 )
V_149 . V_409 = V_149 . V_405 = V_144 [ V_252 ] ;
else if ( ( V_424 <= V_426 ) ||
( V_424 == V_249 && ! F_62 ( V_144 ) ) )
V_149 . V_409 = V_149 . V_405 = V_144 [ V_427 ] ;
} else if ( V_424 >= V_428 && V_424 <= V_429 )
V_149 . V_409 = V_144 [ V_430 ] ;
F_156 ( & V_149 , V_398 , V_398 , V_422 | V_418 ) ;
}
F_154 ( V_398 , V_398 , V_400 , V_401 ) ;
if ( V_424 > V_250 ) {
F_159 ( V_245 , V_245 -> V_248 , & V_149 , V_400 , V_401 ) ;
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
char V_243 [ 32 ] ;
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
return - V_268 ;
} else if ( V_45 ) {
V_127 = F_33 ( V_45 ) - 1 ;
V_45 &= ~ ( 1 << V_127 ) ;
if ( ! V_45 )
return - V_268 ;
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
F_161 () ;
}
V_47 &= F_31 ( V_44 , V_45 , V_46 ) ;
if ( ! ( V_47 & V_122 ) || V_47 == V_437 )
return - V_268 ;
if ( ! V_438 ) {
if ( V_47 & ( V_124 | V_126 ) )
snprintf ( V_243 , sizeof( V_243 ) , L_116 ,
F_36 ( V_47 ) ,
F_36 ( V_47 & V_122 ) ) ;
else
snprintf ( V_243 , sizeof( V_243 ) , L_117 ,
F_36 ( V_47 ) ) ;
F_24 ( V_15 , L_118 , V_243 ) ;
}
F_16 ( V_47 , & V_15 -> V_44 , & V_15 -> V_45 ,
& V_15 -> V_46 ) ;
return 0 ;
}
static int F_162 ( struct V_14 * V_15 )
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
if ( V_445 && V_5 -> V_42 & V_449 && F_104 ( V_15 -> V_144 ) )
V_447 = L_119 ;
else {
if ( V_445 )
F_24 ( V_15 ,
L_120
L_121 ) ;
V_159 = F_163 ( V_15 ) ;
}
if ( V_159 & ~ V_164 )
goto V_383;
V_174 -> V_25 . V_42 |= V_450 ;
V_182 = F_164 ( V_15 , V_143 , 0 ) ;
V_174 -> V_25 . V_42 &= ~ V_450 ;
if ( V_182 )
return V_182 ;
if ( V_15 -> V_432 == V_121 ) {
if ( F_62 ( V_15 -> V_144 ) )
V_448 = 1 ;
if ( F_98 ( V_15 -> V_144 ) == 0 &&
V_15 -> V_248 <= V_251 )
V_448 = 1 ;
if ( ! F_88 ( V_15 -> V_144 ) && V_15 -> V_248 <= V_251 )
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
V_447 = L_122 ;
}
F_30 ( L_123 ,
V_15 -> V_432 , ( int ) V_15 -> V_134 ) ;
F_57 ( V_15 , L_124 ,
F_36 ( F_34 ( V_15 -> V_134 ) ) ,
V_447 ) ;
return 0 ;
V_383:
F_59 ( V_15 , L_125 , V_159 ) ;
return - V_167 ;
}
int F_165 ( struct V_2 * V_3 , struct V_14 * * V_451 )
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
F_166 ( V_15 ) ;
F_15 ( V_15 ) ;
V_44 = F_31 ( V_15 -> V_44 , 0 , 0 ) ;
if ( V_459 & V_455 )
V_454 = F_31 ( 0 , V_15 -> V_45 ,
V_15 -> V_46 ) ;
else
V_454 = 0 ;
V_15 -> V_248 = F_32 ( V_44 ) ;
V_15 -> V_379 = F_32 ( V_454 ) ;
V_453 = 1 ;
if ( F_167 ( V_15 ) )
V_452 = 1 ;
}
if ( ! V_453 )
goto V_460;
F_140 (dev, link, ENABLED) {
if ( V_15 -> V_248 == 0xff ) {
F_24 ( V_15 , L_126 ) ;
V_182 = - V_119 ;
goto V_460;
}
V_15 -> V_134 = V_15 -> V_248 ;
V_15 -> V_432 = V_121 ;
if ( V_5 -> V_215 -> V_380 )
V_5 -> V_215 -> V_380 ( V_5 , V_15 ) ;
}
F_140 (dev, link, ENABLED) {
if ( ! F_167 ( V_15 ) )
continue;
V_15 -> V_134 = V_15 -> V_379 ;
V_15 -> V_432 = F_35 ( V_15 -> V_379 ) ;
if ( V_5 -> V_215 -> V_461 )
V_5 -> V_215 -> V_461 ( V_5 , V_15 ) ;
}
F_140 (dev, link, ENABLED) {
V_182 = F_162 ( V_15 ) ;
if ( V_182 )
goto V_460;
}
if ( V_452 && ( V_5 -> V_273 -> V_42 & V_462 ) )
V_5 -> V_273 -> V_463 = V_5 ;
V_460:
if ( V_182 )
* V_451 = V_15 ;
return V_182 ;
}
int F_168 ( struct V_2 * V_3 , unsigned long V_464 ,
int (* F_169)( struct V_2 * V_3 ) )
{
unsigned long V_465 = V_466 ;
unsigned long V_467 ;
int V_468 = 0 ;
if ( V_3 -> V_5 -> V_273 -> V_42 & V_469 )
V_467 = F_170 ( V_465 , V_470 ) ;
else
V_467 = F_170 ( V_465 , V_471 ) ;
F_85 ( V_3 == V_3 -> V_5 -> V_12 ) ;
if ( F_171 ( V_467 , V_464 ) )
V_467 = V_464 ;
while ( 1 ) {
unsigned long V_472 = V_466 ;
int V_473 , V_387 ;
V_473 = V_387 = F_169 ( V_3 ) ;
if ( V_473 > 0 )
return 0 ;
if ( V_473 == - V_263 ) {
if ( F_172 ( V_3 ) )
V_473 = 0 ;
else if ( ( V_3 -> V_5 -> V_42 & V_449 ) &&
! F_173 ( V_3 ) &&
F_174 ( V_472 , V_467 ) )
V_473 = 0 ;
}
if ( V_473 )
return V_473 ;
if ( F_171 ( V_472 , V_464 ) )
return - V_474 ;
if ( ! V_468 && F_171 ( V_472 , V_465 + 5 * V_475 ) &&
( V_464 - V_472 > 3 * V_475 ) ) {
F_149 ( V_3 ,
L_127
L_128 , V_387 ) ;
V_468 = 1 ;
}
F_175 ( V_3 -> V_5 , 50 ) ;
}
}
int F_176 ( struct V_2 * V_3 , unsigned long V_464 ,
int (* F_169)( struct V_2 * V_3 ) )
{
F_175 ( V_3 -> V_5 , V_476 ) ;
return F_168 ( V_3 , V_464 , F_169 ) ;
}
int F_177 ( struct V_2 * V_3 , const unsigned long * V_477 ,
unsigned long V_464 )
{
unsigned long V_478 = V_477 [ 0 ] ;
unsigned long V_479 = V_477 [ 1 ] ;
unsigned long V_480 , V_398 ;
T_1 V_481 , V_482 ;
int V_182 ;
V_398 = F_170 ( V_466 , V_477 [ 2 ] ) ;
if ( F_174 ( V_398 , V_464 ) )
V_464 = V_398 ;
if ( ( V_182 = F_127 ( V_3 , V_388 , & V_482 ) ) )
return V_182 ;
V_482 &= 0xf ;
V_481 = V_482 ;
V_480 = V_466 ;
while ( 1 ) {
F_175 ( V_3 -> V_5 , V_478 ) ;
if ( ( V_182 = F_127 ( V_3 , V_388 , & V_482 ) ) )
return V_182 ;
V_482 &= 0xf ;
if ( V_482 == V_481 ) {
if ( V_482 == 1 && F_174 ( V_466 , V_464 ) )
continue;
if ( F_171 ( V_466 ,
F_170 ( V_480 , V_479 ) ) )
return 0 ;
continue;
}
V_481 = V_482 ;
V_480 = V_466 ;
if ( F_171 ( V_466 , V_464 ) )
return - V_483 ;
}
}
int F_178 ( struct V_2 * V_3 , const unsigned long * V_477 ,
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
F_175 ( V_3 -> V_5 , 200 ) ;
if ( ( V_182 = F_127 ( V_3 , V_389 , & V_386 ) ) )
return V_182 ;
} while ( ( V_386 & 0xf0f ) != 0x300 && -- V_376 );
if ( ( V_386 & 0xf0f ) != 0x300 ) {
F_149 ( V_3 , L_129 ,
V_386 ) ;
return 0 ;
}
if ( V_376 < V_484 )
F_149 ( V_3 , L_130 ,
V_484 - V_376 ) ;
if ( ( V_182 = F_177 ( V_3 , V_477 , V_464 ) ) )
return V_182 ;
if ( ! ( V_182 = F_127 ( V_3 , V_486 , & V_485 ) ) )
V_182 = F_153 ( V_3 , V_486 , V_485 ) ;
return V_182 != - V_119 ? V_182 : 0 ;
}
int F_179 ( struct V_2 * V_3 , enum V_487 V_488 ,
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
if ( F_180 ( V_3 ) > 0 )
V_386 &= ~ ( 0x7 << 8 ) ;
else {
V_386 &= ~ 0xf ;
V_386 |= ( 0x1 << 2 ) ;
}
break;
default:
F_85 ( 1 ) ;
}
V_182 = F_153 ( V_3 , V_389 , V_386 ) ;
if ( V_182 )
return V_182 ;
if ( V_490 )
F_181 ( 10 ) ;
V_174 -> V_25 . V_485 &= ~ V_493 ;
return F_153 ( V_3 , V_486 , V_493 ) ;
}
int F_182 ( struct V_2 * V_3 , unsigned long V_464 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_173 * V_174 = & V_3 -> V_175 ;
const unsigned long * V_494 = F_183 ( V_174 ) ;
int V_182 ;
if ( V_174 -> V_25 . V_495 & V_496 )
return 0 ;
if ( V_5 -> V_42 & V_449 ) {
V_182 = F_178 ( V_3 , V_494 , V_464 ) ;
if ( V_182 && V_182 != - V_393 )
F_149 ( V_3 ,
L_131 ,
V_182 ) ;
}
if ( F_184 ( V_3 ) )
V_174 -> V_25 . V_495 &= ~ V_497 ;
return 0 ;
}
int F_185 ( struct V_2 * V_3 , const unsigned long * V_494 ,
unsigned long V_464 ,
bool * V_498 , int (* F_169)( struct V_2 * ) )
{
T_1 V_386 ;
int V_182 ;
F_30 ( L_132 ) ;
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
if ( ( V_182 = F_186 ( V_3 , V_389 , V_386 ) ) )
goto V_460;
F_175 ( V_3 -> V_5 , 1 ) ;
V_182 = F_178 ( V_3 , V_494 , V_464 ) ;
if ( V_182 )
goto V_460;
if ( F_184 ( V_3 ) )
goto V_460;
if ( V_498 )
* V_498 = true ;
if ( F_187 ( V_3 -> V_5 ) && F_13 ( V_3 ) ) {
if ( F_169 ) {
unsigned long V_499 ;
V_499 = F_170 ( V_466 ,
V_500 ) ;
if ( F_171 ( V_499 , V_464 ) )
V_499 = V_464 ;
F_168 ( V_3 , V_499 , F_169 ) ;
}
V_182 = - V_283 ;
goto V_460;
}
V_182 = 0 ;
if ( F_169 )
V_182 = F_168 ( V_3 , V_464 , F_169 ) ;
V_460:
if ( V_182 && V_182 != - V_283 ) {
if ( V_498 )
* V_498 = false ;
F_188 ( V_3 , L_133 , V_182 ) ;
}
F_30 ( L_134 , V_182 ) ;
return V_182 ;
}
int F_189 ( struct V_2 * V_3 , unsigned int * V_183 ,
unsigned long V_464 )
{
const unsigned long * V_494 = F_183 ( & V_3 -> V_175 ) ;
bool V_498 ;
int V_182 ;
V_182 = F_185 ( V_3 , V_494 , V_464 , & V_498 , NULL ) ;
return V_498 ? - V_283 : V_182 ;
}
void F_190 ( struct V_2 * V_3 , unsigned int * V_374 )
{
T_1 V_485 ;
F_30 ( L_132 ) ;
if ( ! F_127 ( V_3 , V_486 , & V_485 ) )
F_153 ( V_3 , V_486 , V_485 ) ;
F_144 ( V_3 ) ;
F_30 ( L_135 ) ;
}
static int F_191 ( struct V_14 * V_15 , unsigned int V_501 ,
const T_4 * V_502 )
{
const T_4 * V_503 = V_15 -> V_144 ;
unsigned char V_504 [ 2 ] [ V_316 + 1 ] ;
unsigned char V_505 [ 2 ] [ V_506 + 1 ] ;
if ( V_15 -> V_183 != V_501 ) {
F_57 ( V_15 , L_136 ,
V_15 -> V_183 , V_501 ) ;
return 0 ;
}
F_41 ( V_503 , V_504 [ 0 ] , V_330 , sizeof( V_504 [ 0 ] ) ) ;
F_41 ( V_502 , V_504 [ 1 ] , V_330 , sizeof( V_504 [ 1 ] ) ) ;
F_41 ( V_503 , V_505 [ 0 ] , V_507 , sizeof( V_505 [ 0 ] ) ) ;
F_41 ( V_502 , V_505 [ 1 ] , V_507 , sizeof( V_505 [ 1 ] ) ) ;
if ( strcmp ( V_504 [ 0 ] , V_504 [ 1 ] ) ) {
F_57 ( V_15 , L_137 ,
V_504 [ 0 ] , V_504 [ 1 ] ) ;
return 0 ;
}
if ( strcmp ( V_505 [ 0 ] , V_505 [ 1 ] ) ) {
F_57 ( V_15 , L_138 ,
V_505 [ 0 ] , V_505 [ 1 ] ) ;
return 0 ;
}
return 1 ;
}
int F_58 ( struct V_14 * V_15 , unsigned int V_508 )
{
unsigned int V_183 = V_15 -> V_183 ;
T_4 * V_144 = ( void * ) V_15 -> V_3 -> V_5 -> V_303 ;
int V_182 ;
V_182 = F_91 ( V_15 , & V_183 , V_508 , V_144 ) ;
if ( V_182 )
return V_182 ;
if ( ! F_191 ( V_15 , V_183 , V_144 ) )
return - V_263 ;
memcpy ( V_15 -> V_144 , V_144 , sizeof( V_144 [ 0 ] ) * V_253 ) ;
return 0 ;
}
int F_164 ( struct V_14 * V_15 , unsigned int V_501 ,
unsigned int V_508 )
{
T_3 V_327 = V_15 -> V_327 ;
T_3 V_185 = V_15 -> V_185 ;
int V_182 ;
if ( ! F_8 ( V_15 ) )
return - V_263 ;
if ( F_192 ( V_501 ) &&
V_501 != V_138 &&
V_501 != V_139 &&
V_501 != V_142 &&
V_501 != V_141 ) {
F_57 ( V_15 , L_139 ,
V_15 -> V_183 , V_501 ) ;
V_182 = - V_263 ;
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
F_24 ( V_15 , L_140 ,
( unsigned long long ) V_327 ,
( unsigned long long ) V_15 -> V_327 ) ;
if ( V_15 -> V_185 == V_185 &&
V_15 -> V_327 > V_327 && V_15 -> V_327 == V_185 ) {
F_24 ( V_15 ,
L_141
L_142 ) ;
return 0 ;
}
if ( V_15 -> V_185 == V_185 &&
V_15 -> V_327 < V_327 && V_327 == V_185 &&
! ( V_15 -> V_48 & V_184 ) ) {
F_24 ( V_15 ,
L_143
L_144 ) ;
V_15 -> V_42 |= V_180 ;
V_182 = - V_167 ;
} else
V_182 = - V_263 ;
V_15 -> V_185 = V_185 ;
V_15 -> V_327 = V_327 ;
V_383:
F_59 ( V_15 , L_145 , V_182 ) ;
return V_182 ;
}
static unsigned long F_103 ( const struct V_14 * V_15 )
{
unsigned char V_509 [ V_316 + 1 ] ;
unsigned char V_510 [ V_314 + 1 ] ;
const struct V_511 * V_512 = V_513 ;
F_41 ( V_15 -> V_144 , V_509 , V_330 , sizeof( V_509 ) ) ;
F_41 ( V_15 -> V_144 , V_510 , V_329 , sizeof( V_510 ) ) ;
while ( V_512 -> V_509 ) {
if ( F_193 ( V_512 -> V_509 , V_509 ) ) {
if ( V_512 -> V_510 == NULL )
return V_512 -> V_48 ;
if ( F_193 ( V_512 -> V_510 , V_510 ) )
return V_512 -> V_48 ;
}
V_512 ++ ;
}
return 0 ;
}
static int F_194 ( const struct V_14 * V_15 )
{
if ( ( V_15 -> V_3 -> V_5 -> V_42 & V_514 ) &&
( V_15 -> V_42 & V_355 ) )
return 1 ;
return ( V_15 -> V_48 & V_515 ) ? 1 : 0 ;
}
static int F_195 ( struct V_14 * V_15 )
{
if ( V_15 -> V_48 & V_516 )
return F_196 ( V_15 -> V_144 ) ;
return F_197 ( V_15 -> V_144 ) ;
}
static int F_198 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
struct V_14 * V_15 ;
if ( V_5 -> V_33 == V_370 )
return 1 ;
if ( V_5 -> V_33 == V_371 || V_5 -> V_33 == V_285 )
return 0 ;
if ( V_5 -> V_33 == V_517 )
return 0 ;
F_199 (link, ap, EDGE) {
F_140 (dev, link, ENABLED) {
if ( ! F_195 ( V_15 ) )
return 0 ;
}
}
return 1 ;
}
static void F_166 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_518 * V_273 = V_5 -> V_273 ;
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
if ( F_194 ( V_15 ) ) {
V_47 &= ~ ( V_124 | V_126 ) ;
F_24 ( V_15 ,
L_146 ) ;
}
if ( ( V_273 -> V_42 & V_462 ) &&
V_273 -> V_463 && V_273 -> V_463 != V_5 ) {
V_47 &= ~ ( V_124 | V_126 ) ;
F_24 ( V_15 ,
L_147 ) ;
}
if ( V_5 -> V_42 & V_247 )
V_47 &= F_89 ( V_15 ) ;
if ( V_5 -> V_215 -> V_519 )
V_47 = V_5 -> V_215 -> V_519 ( V_15 , V_47 ) ;
if ( V_47 & ( 0xF8 << V_125 ) )
if ( F_198 ( V_5 ) ) {
F_24 ( V_15 ,
L_148 ) ;
V_47 &= ~ ( 0xF8 << V_125 ) ;
}
F_16 ( V_47 , & V_15 -> V_44 ,
& V_15 -> V_45 , & V_15 -> V_46 ) ;
}
static unsigned int F_163 ( struct V_14 * V_15 )
{
struct V_67 V_68 ;
unsigned int V_159 ;
F_30 ( L_149 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_520 ;
V_68 . V_72 = V_521 ;
V_68 . V_42 |= V_109 | V_110 | V_265 ;
V_68 . V_93 = V_162 ;
if ( F_87 ( V_15 ) )
V_68 . V_80 = V_15 -> V_134 ;
else if ( F_88 ( V_15 -> V_144 ) )
V_68 . V_80 = 0x01 ;
else
return 0 ;
V_159 = F_53 ( V_15 , & V_68 , NULL , V_163 , NULL , 0 , 0 ) ;
F_30 ( L_150 , V_159 ) ;
return V_159 ;
}
unsigned int F_97 ( struct V_14 * V_15 , T_2 V_522 , T_2 V_72 )
{
struct V_67 V_68 ;
unsigned int V_159 ;
F_30 ( L_151 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_520 ;
V_68 . V_72 = V_522 ;
V_68 . V_42 |= V_109 | V_110 ;
V_68 . V_93 = V_162 ;
V_68 . V_80 = V_72 ;
V_159 = F_53 ( V_15 , & V_68 , NULL , V_163 , NULL , 0 , 0 ) ;
F_30 ( L_150 , V_159 ) ;
return V_159 ;
}
static unsigned int F_99 ( struct V_14 * V_15 ,
T_4 V_104 , T_4 V_105 )
{
struct V_67 V_68 ;
unsigned int V_159 ;
if ( V_105 < 1 || V_105 > 255 || V_104 < 1 || V_104 > 16 )
return V_523 ;
F_30 ( L_152 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_524 ;
V_68 . V_42 |= V_109 | V_110 ;
V_68 . V_93 = V_162 ;
V_68 . V_80 = V_105 ;
V_68 . V_21 |= ( V_104 - 1 ) & 0x0f ;
V_159 = F_53 ( V_15 , & V_68 , NULL , V_163 , NULL , 0 , 0 ) ;
if ( V_159 == V_164 && ( V_68 . V_72 & V_165 ) )
V_159 = 0 ;
F_30 ( L_150 , V_159 ) ;
return V_159 ;
}
void F_200 ( struct V_194 * V_195 )
{
struct V_4 * V_5 = V_195 -> V_5 ;
struct V_201 * V_230 = V_195 -> V_230 ;
int V_525 = V_195 -> V_200 ;
F_201 ( V_230 == NULL ) ;
F_202 ( L_153 , V_195 -> V_203 ) ;
if ( V_195 -> V_203 )
F_203 ( V_5 -> V_15 , V_230 , V_195 -> V_526 , V_525 ) ;
V_195 -> V_42 &= ~ V_527 ;
V_195 -> V_230 = NULL ;
}
int F_204 ( struct V_194 * V_195 )
{
struct V_4 * V_5 = V_195 -> V_5 ;
if ( ! ( V_195 -> V_15 -> V_48 & V_528 ) &&
F_5 ( V_195 -> V_232 & 15 ) )
return 1 ;
if ( V_5 -> V_215 -> V_529 )
return V_5 -> V_215 -> V_529 ( V_195 ) ;
return 0 ;
}
int F_205 ( struct V_194 * V_195 )
{
struct V_2 * V_3 = V_195 -> V_15 -> V_3 ;
if ( V_195 -> V_68 . V_93 == V_113 ) {
if ( ! F_206 ( V_3 -> V_218 ) )
return 0 ;
} else {
if ( ! F_206 ( V_3 -> V_218 ) && ! V_3 -> V_219 )
return 0 ;
}
return V_530 ;
}
void F_207 ( struct V_194 * V_195 ) { }
void F_72 ( struct V_194 * V_195 , struct V_201 * V_230 ,
unsigned int V_203 )
{
V_195 -> V_230 = V_230 ;
V_195 -> V_203 = V_203 ;
V_195 -> V_531 = V_195 -> V_230 ;
}
static int F_208 ( struct V_194 * V_195 )
{
struct V_4 * V_5 = V_195 -> V_5 ;
unsigned int V_203 ;
F_202 ( L_154 , V_5 -> V_31 ) ;
V_203 = F_209 ( V_5 -> V_15 , V_195 -> V_230 , V_195 -> V_203 , V_195 -> V_200 ) ;
if ( V_203 < 1 )
return - 1 ;
F_30 ( L_155 , V_203 ) ;
V_195 -> V_526 = V_195 -> V_203 ;
V_195 -> V_203 = V_203 ;
V_195 -> V_42 |= V_527 ;
return 0 ;
}
void F_95 ( T_4 * V_243 , unsigned int V_532 )
{
#ifdef F_210
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < V_532 ; V_25 ++ )
V_243 [ V_25 ] = F_211 ( V_243 [ V_25 ] ) ;
#endif
}
struct V_194 * F_212 ( struct V_14 * V_15 , int V_108 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_194 * V_195 ;
if ( F_5 ( V_5 -> V_212 & V_213 ) )
return NULL ;
if ( V_5 -> V_42 & V_533 ) {
V_108 = F_213 ( V_5 ) ;
if ( V_108 < 0 )
return NULL ;
}
V_195 = F_69 ( V_5 , V_108 ) ;
V_195 -> V_108 = V_108 ;
V_195 -> V_217 = NULL ;
V_195 -> V_5 = V_5 ;
V_195 -> V_15 = V_15 ;
F_70 ( V_195 ) ;
return V_195 ;
}
void F_83 ( struct V_194 * V_195 )
{
struct V_4 * V_5 ;
unsigned int V_108 ;
F_201 ( V_195 == NULL ) ;
V_5 = V_195 -> V_5 ;
V_195 -> V_42 = 0 ;
V_108 = V_195 -> V_108 ;
if ( F_27 ( F_206 ( V_108 ) ) ) {
V_195 -> V_108 = V_222 ;
if ( V_5 -> V_42 & V_533 )
F_214 ( V_108 , V_5 ) ;
}
}
void F_215 ( struct V_194 * V_195 )
{
struct V_4 * V_5 ;
struct V_2 * V_3 ;
F_201 ( V_195 == NULL ) ;
F_201 ( ! ( V_195 -> V_42 & V_235 ) ) ;
V_5 = V_195 -> V_5 ;
V_3 = V_195 -> V_15 -> V_3 ;
if ( F_27 ( V_195 -> V_42 & V_527 ) )
F_200 ( V_195 ) ;
if ( V_195 -> V_68 . V_93 == V_113 ) {
V_3 -> V_219 &= ~ ( 1 << V_195 -> V_108 ) ;
if ( ! V_3 -> V_219 )
V_5 -> V_221 -- ;
} else {
V_3 -> V_218 = V_222 ;
V_5 -> V_221 -- ;
}
if ( F_5 ( V_195 -> V_42 & V_534 &&
V_5 -> V_535 == V_3 ) )
V_5 -> V_535 = NULL ;
V_195 -> V_42 &= ~ V_235 ;
V_5 -> V_220 &= ~ ( 1 << V_195 -> V_108 ) ;
V_195 -> V_233 ( V_195 ) ;
}
static void F_216 ( struct V_194 * V_195 )
{
struct V_4 * V_5 = V_195 -> V_5 ;
V_195 -> V_239 . V_42 = V_195 -> V_68 . V_42 ;
V_5 -> V_215 -> V_536 ( V_195 ) ;
}
static void F_217 ( struct V_194 * V_195 )
{
struct V_14 * V_15 = V_195 -> V_15 ;
if ( F_218 ( V_195 -> V_68 . V_93 ) )
return;
if ( ( V_15 -> V_45 || V_15 -> V_46 ) && F_219 ( V_195 -> V_68 . V_93 ) )
return;
V_15 -> V_42 &= ~ V_537 ;
}
void F_81 ( struct V_194 * V_195 )
{
struct V_4 * V_5 = V_195 -> V_5 ;
if ( V_5 -> V_215 -> V_216 ) {
struct V_14 * V_15 = V_195 -> V_15 ;
struct V_538 * V_539 = & V_15 -> V_3 -> V_540 ;
if ( F_5 ( V_195 -> V_159 ) )
V_195 -> V_42 |= V_238 ;
if ( F_5 ( F_220 ( V_195 -> V_108 ) ) ) {
F_216 ( V_195 ) ;
F_221 ( V_195 ) ;
F_215 ( V_195 ) ;
return;
}
if ( F_5 ( V_195 -> V_42 & V_238 ) ) {
F_216 ( V_195 ) ;
F_222 ( V_195 ) ;
F_223 ( V_195 ) ;
return;
}
F_201 ( V_5 -> V_212 & V_213 ) ;
if ( V_195 -> V_42 & V_228 )
F_216 ( V_195 ) ;
F_224 ( V_195 ) ;
switch ( V_195 -> V_68 . V_71 ) {
case V_520 :
if ( V_195 -> V_68 . V_72 != V_541 &&
V_195 -> V_68 . V_72 != V_542 )
break;
case V_524 :
case V_543 :
V_539 -> V_544 [ V_15 -> V_24 ] |= V_545 ;
F_225 ( V_5 ) ;
break;
case V_546 :
V_15 -> V_42 |= V_547 ;
break;
}
if ( F_5 ( V_15 -> V_42 & V_537 ) )
F_217 ( V_195 ) ;
F_215 ( V_195 ) ;
} else {
if ( V_195 -> V_42 & V_548 )
return;
if ( V_195 -> V_159 || V_195 -> V_42 & V_228 )
F_216 ( V_195 ) ;
F_215 ( V_195 ) ;
}
}
int F_226 ( struct V_4 * V_5 , T_1 V_220 )
{
int V_549 = 0 ;
T_1 V_550 ;
V_550 = V_5 -> V_220 ^ V_220 ;
if ( F_5 ( V_550 & V_220 ) ) {
F_227 ( V_5 , L_156 ,
V_5 -> V_220 , V_220 ) ;
return - V_119 ;
}
while ( V_550 ) {
struct V_194 * V_195 ;
unsigned int V_108 = F_228 ( V_550 ) ;
V_195 = F_229 ( V_5 , V_108 ) ;
if ( V_195 ) {
F_81 ( V_195 ) ;
V_549 ++ ;
}
V_550 &= ~ ( 1 << V_108 ) ;
}
return V_549 ;
}
void F_73 ( struct V_194 * V_195 )
{
struct V_4 * V_5 = V_195 -> V_5 ;
struct V_2 * V_3 = V_195 -> V_15 -> V_3 ;
T_2 V_551 = V_195 -> V_68 . V_93 ;
F_201 ( V_5 -> V_215 -> V_216 && F_206 ( V_3 -> V_218 ) ) ;
if ( F_230 ( V_551 ) ) {
F_201 ( V_3 -> V_219 & ( 1 << V_195 -> V_108 ) ) ;
if ( ! V_3 -> V_219 )
V_5 -> V_221 ++ ;
V_3 -> V_219 |= 1 << V_195 -> V_108 ;
} else {
F_201 ( V_3 -> V_219 ) ;
V_5 -> V_221 ++ ;
V_3 -> V_218 = V_195 -> V_108 ;
}
V_195 -> V_42 |= V_235 ;
V_5 -> V_220 |= 1 << V_195 -> V_108 ;
if ( F_201 ( F_231 ( V_551 ) &&
( ! V_195 -> V_230 || ! V_195 -> V_203 || ! V_195 -> V_232 ) ) )
goto V_552;
if ( F_232 ( V_551 ) || ( F_219 ( V_551 ) &&
( V_5 -> V_42 & V_553 ) ) )
if ( F_208 ( V_195 ) )
goto V_552;
if ( F_5 ( V_195 -> V_15 -> V_42 & V_547 ) ) {
V_3 -> V_540 . V_495 |= V_554 ;
F_233 ( & V_3 -> V_540 , L_157 ) ;
F_234 ( V_3 ) ;
return;
}
V_5 -> V_215 -> V_555 ( V_195 ) ;
F_235 ( V_195 ) ;
V_195 -> V_159 |= V_5 -> V_215 -> V_556 ( V_195 ) ;
if ( F_5 ( V_195 -> V_159 ) )
goto V_557;
return;
V_552:
V_195 -> V_159 |= V_214 ;
V_557:
F_81 ( V_195 ) ;
}
int F_101 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
return ( V_5 -> V_42 & V_449 ) && V_5 -> V_215 -> V_558 ;
}
int F_127 ( struct V_2 * V_3 , int V_559 , T_1 * V_560 )
{
if ( F_13 ( V_3 ) ) {
if ( F_101 ( V_3 ) )
return V_3 -> V_5 -> V_215 -> V_558 ( V_3 , V_559 , V_560 ) ;
return - V_393 ;
}
return F_236 ( V_3 , V_559 , V_560 ) ;
}
int F_153 ( struct V_2 * V_3 , int V_559 , T_1 V_560 )
{
if ( F_13 ( V_3 ) ) {
if ( F_101 ( V_3 ) )
return V_3 -> V_5 -> V_215 -> V_561 ( V_3 , V_559 , V_560 ) ;
return - V_393 ;
}
return F_237 ( V_3 , V_559 , V_560 ) ;
}
int F_186 ( struct V_2 * V_3 , int V_559 , T_1 V_560 )
{
if ( F_13 ( V_3 ) ) {
int V_182 ;
if ( F_101 ( V_3 ) ) {
V_182 = V_3 -> V_5 -> V_215 -> V_561 ( V_3 , V_559 , V_560 ) ;
if ( V_182 == 0 )
V_182 = V_3 -> V_5 -> V_215 -> V_558 ( V_3 , V_559 , & V_560 ) ;
return V_182 ;
}
return - V_393 ;
}
return F_237 ( V_3 , V_559 , V_560 ) ;
}
bool F_145 ( struct V_2 * V_3 )
{
T_1 V_1 ;
if ( F_127 ( V_3 , V_388 , & V_1 ) == 0 &&
F_1 ( V_1 ) )
return true ;
return false ;
}
bool F_184 ( struct V_2 * V_3 )
{
T_1 V_1 ;
if ( F_127 ( V_3 , V_388 , & V_1 ) == 0 &&
! F_1 ( V_1 ) )
return true ;
return false ;
}
bool F_172 ( struct V_2 * V_3 )
{
struct V_2 * V_562 = V_3 -> V_5 -> V_12 ;
F_85 ( V_3 == V_562 ) ;
return F_145 ( V_3 ) ||
( V_562 && F_145 ( V_562 ) ) ;
}
bool F_173 ( struct V_2 * V_3 )
{
struct V_2 * V_562 = V_3 -> V_5 -> V_12 ;
F_85 ( V_3 == V_562 ) ;
return F_184 ( V_3 ) &&
( ! V_562 || F_184 ( V_562 ) ) ;
}
static void F_238 ( struct V_4 * V_5 , T_6 V_563 ,
unsigned int V_495 , unsigned int V_564 ,
bool V_565 )
{
struct V_2 * V_3 ;
unsigned long V_42 ;
if ( V_5 -> V_212 & V_566 ) {
F_239 ( V_5 ) ;
F_85 ( V_5 -> V_212 & V_566 ) ;
}
F_67 ( V_5 -> V_211 , V_42 ) ;
V_5 -> V_567 = V_563 ;
V_5 -> V_212 |= V_566 ;
F_199 (link, ap, HOST_FIRST) {
V_3 -> V_540 . V_495 |= V_495 ;
V_3 -> V_540 . V_42 |= V_564 ;
}
F_225 ( V_5 ) ;
F_68 ( V_5 -> V_211 , V_42 ) ;
if ( ! V_565 ) {
F_239 ( V_5 ) ;
F_85 ( V_5 -> V_212 & V_566 ) ;
}
}
static void F_240 ( struct V_4 * V_5 , T_6 V_563 )
{
F_238 ( V_5 , V_563 , 0 , V_568 , false ) ;
}
static void F_241 ( struct V_4 * V_5 , T_6 V_563 )
{
F_238 ( V_5 , V_563 , 0 , V_568 , true ) ;
}
static int F_242 ( struct V_21 * V_15 )
{
struct V_4 * V_5 = F_243 ( V_15 ) ;
if ( F_244 ( V_15 ) )
return 0 ;
F_240 ( V_5 , V_569 ) ;
return 0 ;
}
static int F_245 ( struct V_21 * V_15 )
{
struct V_4 * V_5 = F_243 ( V_15 ) ;
if ( F_244 ( V_15 ) )
return 0 ;
F_240 ( V_5 , V_570 ) ;
return 0 ;
}
static int F_246 ( struct V_21 * V_15 )
{
F_240 ( F_243 ( V_15 ) , V_571 ) ;
return 0 ;
}
static void F_247 ( struct V_4 * V_5 , T_6 V_563 )
{
F_238 ( V_5 , V_563 , V_554 , V_572 , false ) ;
}
static void F_248 ( struct V_4 * V_5 , T_6 V_563 )
{
F_238 ( V_5 , V_563 , V_554 , V_572 , true ) ;
}
static int F_249 ( struct V_21 * V_15 )
{
F_248 ( F_243 ( V_15 ) , V_573 ) ;
F_250 ( V_15 ) ;
F_251 ( V_15 ) ;
F_252 ( V_15 ) ;
return 0 ;
}
static int F_253 ( struct V_21 * V_15 )
{
struct V_4 * V_5 = F_243 ( V_15 ) ;
struct V_2 * V_3 ;
struct V_14 * V_245 ;
F_199 (link, ap, HOST_FIRST) {
F_140 (adev, link, ENABLED)
if ( V_245 -> V_183 == V_139 &&
! F_254 ( V_245 ) )
return - V_474 ;
}
return 0 ;
}
static int F_255 ( struct V_21 * V_15 )
{
F_240 ( F_243 ( V_15 ) , V_574 ) ;
return 0 ;
}
static int F_256 ( struct V_21 * V_15 )
{
F_247 ( F_243 ( V_15 ) , V_575 ) ;
return 0 ;
}
void F_257 ( struct V_4 * V_5 )
{
F_241 ( V_5 , V_569 ) ;
}
void F_258 ( struct V_4 * V_5 )
{
F_248 ( V_5 , V_573 ) ;
}
int F_259 ( struct V_518 * V_273 , T_6 V_563 )
{
V_273 -> V_15 -> V_576 . V_577 = V_563 ;
return 0 ;
}
void F_260 ( struct V_518 * V_273 )
{
V_273 -> V_15 -> V_576 . V_577 = V_578 ;
}
void F_261 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = F_9 ( V_15 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_42 ;
V_3 -> V_281 = V_3 -> V_40 ;
V_3 -> V_282 = 0 ;
F_67 ( V_5 -> V_211 , V_42 ) ;
V_15 -> V_42 &= ~ V_579 ;
V_15 -> V_48 = 0 ;
F_68 ( V_5 -> V_211 , V_42 ) ;
memset ( ( void * ) V_15 + V_580 , 0 ,
V_581 - V_580 ) ;
V_15 -> V_44 = V_396 ;
V_15 -> V_45 = V_396 ;
V_15 -> V_46 = V_396 ;
}
void F_262 ( struct V_4 * V_5 , struct V_2 * V_3 , int V_38 )
{
int V_25 ;
memset ( ( void * ) V_3 + V_582 , 0 ,
V_583 - V_582 ) ;
V_3 -> V_5 = V_5 ;
V_3 -> V_38 = V_38 ;
V_3 -> V_218 = V_222 ;
V_3 -> V_40 = V_396 ;
for ( V_25 = 0 ; V_25 < V_375 ; V_25 ++ ) {
struct V_14 * V_15 = & V_3 -> V_21 [ V_25 ] ;
V_15 -> V_3 = V_3 ;
V_15 -> V_24 = V_15 - V_3 -> V_21 ;
#ifdef F_263
V_15 -> V_584 = V_585 ;
#endif
F_261 ( V_15 ) ;
}
}
int F_264 ( struct V_2 * V_3 )
{
T_2 V_136 ;
int V_182 ;
V_182 = F_127 ( V_3 , V_389 , & V_3 -> V_586 ) ;
if ( V_182 )
return V_182 ;
V_136 = ( V_3 -> V_586 >> 4 ) & 0xf ;
if ( V_136 )
V_3 -> V_40 &= ( 1 << V_136 ) - 1 ;
F_12 ( V_3 ) ;
V_3 -> V_281 = V_3 -> V_40 ;
return 0 ;
}
struct V_4 * F_265 ( struct V_518 * V_273 )
{
struct V_4 * V_5 ;
F_30 ( L_132 ) ;
V_5 = F_266 ( sizeof( * V_5 ) , V_587 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_212 |= V_588 | V_213 ;
V_5 -> V_211 = & V_273 -> V_211 ;
V_5 -> V_31 = - 1 ;
V_5 -> V_589 = - 1 ;
V_5 -> V_273 = V_273 ;
V_5 -> V_15 = V_273 -> V_15 ;
#if F_267 ( V_590 )
V_5 -> V_591 = 0x00FF ;
#elif F_267 ( V_592 )
V_5 -> V_591 = V_593 | V_594 | V_595 | V_596 | V_597 ;
#else
V_5 -> V_591 = V_593 | V_597 | V_596 ;
#endif
F_268 ( & V_5 -> V_598 ) ;
F_269 ( & V_5 -> V_599 , V_600 ) ;
F_270 ( & V_5 -> V_601 , V_602 ) ;
F_271 ( & V_5 -> V_603 ) ;
F_272 ( & V_5 -> V_604 ) ;
F_273 ( & V_5 -> V_605 ) ;
F_274 ( & V_5 -> V_606 ) ;
V_5 -> V_606 . V_607 = V_608 ;
V_5 -> V_606 . V_609 = ( unsigned long ) V_5 ;
V_5 -> V_33 = V_34 ;
F_262 ( V_5 , & V_5 -> V_3 , 0 ) ;
#ifdef F_275
V_5 -> V_610 . V_611 = 1 ;
V_5 -> V_610 . V_612 = 1 ;
#endif
F_276 ( V_5 ) ;
return V_5 ;
}
static void F_277 ( struct V_21 * V_613 , void * V_614 )
{
struct V_518 * V_273 = F_278 ( V_613 ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_273 -> V_615 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_616 [ V_25 ] ;
if ( ! V_5 )
continue;
if ( V_5 -> V_293 )
F_279 ( V_5 -> V_293 ) ;
F_280 ( V_5 -> V_11 ) ;
F_280 ( V_5 -> V_12 ) ;
F_280 ( V_5 ) ;
V_273 -> V_616 [ V_25 ] = NULL ;
}
F_281 ( V_613 , NULL ) ;
}
struct V_518 * F_282 ( struct V_21 * V_15 , int V_617 )
{
struct V_518 * V_273 ;
T_5 V_618 ;
int V_25 ;
F_30 ( L_132 ) ;
if ( ! F_283 ( V_15 , NULL , V_587 ) )
return NULL ;
V_618 = sizeof( struct V_518 ) + ( V_617 + 1 ) * sizeof( void * ) ;
V_273 = F_284 ( F_277 , V_618 , V_587 ) ;
if ( ! V_273 )
goto V_264;
F_285 ( V_15 , V_273 ) ;
F_281 ( V_15 , V_273 ) ;
F_286 ( & V_273 -> V_211 ) ;
F_268 ( & V_273 -> V_619 ) ;
V_273 -> V_15 = V_15 ;
V_273 -> V_615 = V_617 ;
for ( V_25 = 0 ; V_25 < V_617 ; V_25 ++ ) {
struct V_4 * V_5 ;
V_5 = F_265 ( V_273 ) ;
if ( ! V_5 )
goto V_264;
V_5 -> V_620 = V_25 ;
V_273 -> V_616 [ V_25 ] = V_5 ;
}
F_287 ( V_15 , NULL ) ;
return V_273 ;
V_264:
F_288 ( V_15 , NULL ) ;
return NULL ;
}
struct V_518 * F_289 ( struct V_21 * V_15 ,
const struct V_621 * const * V_622 ,
int V_615 )
{
const struct V_621 * V_623 ;
struct V_518 * V_273 ;
int V_25 , V_338 ;
V_273 = F_282 ( V_15 , V_615 ) ;
if ( ! V_273 )
return NULL ;
for ( V_25 = 0 , V_338 = 0 , V_623 = NULL ; V_25 < V_273 -> V_615 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_616 [ V_25 ] ;
if ( V_622 [ V_338 ] )
V_623 = V_622 [ V_338 ++ ] ;
V_5 -> V_44 = V_623 -> V_44 ;
V_5 -> V_45 = V_623 -> V_45 ;
V_5 -> V_46 = V_623 -> V_46 ;
V_5 -> V_42 |= V_623 -> V_42 ;
V_5 -> V_3 . V_42 |= V_623 -> V_624 ;
V_5 -> V_215 = V_623 -> V_625 ;
if ( ! V_273 -> V_215 && ( V_623 -> V_625 != & V_626 ) )
V_273 -> V_215 = V_623 -> V_625 ;
}
return V_273 ;
}
int F_290 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
F_85 ( V_5 -> V_12 ) ;
F_85 ( V_5 -> V_42 & V_627 ) ;
V_3 = F_266 ( sizeof( * V_3 ) , V_587 ) ;
if ( ! V_3 )
return - V_628 ;
F_262 ( V_5 , V_3 , 1 ) ;
V_5 -> V_12 = V_3 ;
return 0 ;
}
static void F_291 ( struct V_21 * V_613 , void * V_614 )
{
struct V_518 * V_273 = F_278 ( V_613 ) ;
int V_25 ;
F_85 ( ! ( V_273 -> V_42 & V_629 ) ) ;
for ( V_25 = 0 ; V_25 < V_273 -> V_615 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_616 [ V_25 ] ;
if ( V_5 -> V_215 -> V_630 )
V_5 -> V_215 -> V_630 ( V_5 ) ;
}
if ( V_273 -> V_215 -> V_631 )
V_273 -> V_215 -> V_631 ( V_273 ) ;
}
static void F_292 ( struct V_632 * V_215 )
{
static F_293 ( V_211 ) ;
const struct V_632 * V_482 ;
void * * V_633 = ( void * * ) V_215 ;
void * * V_634 = ( void * * ) & V_215 -> V_635 ;
void * * V_636 ;
if ( ! V_215 || ! V_215 -> V_635 )
return;
F_294 ( & V_211 ) ;
for ( V_482 = V_215 -> V_635 ; V_482 ; V_482 = V_482 -> V_635 ) {
void * * V_637 = ( void * * ) V_482 ;
for ( V_636 = V_633 ; V_636 < V_634 ; V_636 ++ , V_637 ++ )
if ( ! * V_636 )
* V_636 = * V_637 ;
}
for ( V_636 = V_633 ; V_636 < V_634 ; V_636 ++ )
if ( F_295 ( * V_636 ) )
* V_636 = NULL ;
V_215 -> V_635 = NULL ;
F_296 ( & V_211 ) ;
}
int F_297 ( struct V_518 * V_273 )
{
int V_638 = 0 ;
void * V_639 = NULL ;
int V_25 , V_182 ;
if ( V_273 -> V_42 & V_629 )
return 0 ;
F_292 ( V_273 -> V_215 ) ;
for ( V_25 = 0 ; V_25 < V_273 -> V_615 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_616 [ V_25 ] ;
F_292 ( V_5 -> V_215 ) ;
if ( ! V_273 -> V_215 && ! F_298 ( V_5 ) )
V_273 -> V_215 = V_5 -> V_215 ;
if ( V_5 -> V_215 -> V_630 )
V_638 = 1 ;
}
if ( V_273 -> V_215 -> V_631 )
V_638 = 1 ;
if ( V_638 ) {
V_639 = F_284 ( F_291 , 0 , V_587 ) ;
if ( ! V_639 )
return - V_628 ;
}
for ( V_25 = 0 ; V_25 < V_273 -> V_615 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_616 [ V_25 ] ;
if ( V_5 -> V_215 -> V_640 ) {
V_182 = V_5 -> V_215 -> V_640 ( V_5 ) ;
if ( V_182 ) {
if ( V_182 != - V_263 )
F_299 ( V_273 -> V_15 ,
L_158 ,
V_25 , V_182 ) ;
goto V_264;
}
}
F_300 ( V_5 ) ;
}
if ( V_639 )
F_285 ( V_273 -> V_15 , V_639 ) ;
V_273 -> V_42 |= V_629 ;
return 0 ;
V_264:
while ( -- V_25 >= 0 ) {
struct V_4 * V_5 = V_273 -> V_616 [ V_25 ] ;
if ( V_5 -> V_215 -> V_630 )
V_5 -> V_215 -> V_630 ( V_5 ) ;
}
F_301 ( V_639 ) ;
return V_182 ;
}
void F_302 ( struct V_518 * V_273 , struct V_21 * V_15 ,
struct V_632 * V_215 )
{
F_286 ( & V_273 -> V_211 ) ;
F_268 ( & V_273 -> V_619 ) ;
V_273 -> V_641 = V_295 - 1 ;
V_273 -> V_15 = V_15 ;
V_273 -> V_215 = V_215 ;
}
void F_303 ( struct V_4 * V_5 )
{
struct V_538 * V_539 = & V_5 -> V_3 . V_540 ;
unsigned long V_42 ;
F_67 ( V_5 -> V_211 , V_42 ) ;
V_539 -> V_642 |= V_643 ;
V_539 -> V_495 |= V_554 ;
V_539 -> V_42 |= V_644 | V_645 ;
V_5 -> V_212 &= ~ V_588 ;
V_5 -> V_212 |= V_646 ;
F_225 ( V_5 ) ;
F_68 ( V_5 -> V_211 , V_42 ) ;
}
int F_304 ( struct V_4 * V_5 )
{
int V_182 = 0 ;
if ( V_5 -> V_215 -> V_216 ) {
F_303 ( V_5 ) ;
F_239 ( V_5 ) ;
} else {
F_30 ( L_159 , V_5 -> V_31 ) ;
V_182 = F_139 ( V_5 ) ;
F_30 ( L_160 , V_5 -> V_31 ) ;
}
return V_182 ;
}
static void F_305 ( void * V_609 , T_7 V_647 )
{
struct V_4 * V_5 = V_609 ;
if ( ! ( V_5 -> V_273 -> V_42 & V_469 ) && V_5 -> V_620 != 0 )
F_306 ( V_647 ) ;
( void ) F_304 ( V_5 ) ;
F_306 ( V_647 ) ;
F_307 ( V_5 , 1 ) ;
}
int F_308 ( struct V_518 * V_273 , struct V_648 * V_649 )
{
int V_25 , V_182 ;
V_273 -> V_641 = F_309 ( V_649 -> V_294 , 1 , V_295 - 1 ) ;
if ( ! ( V_273 -> V_42 & V_629 ) ) {
F_299 ( V_273 -> V_15 , L_161 ) ;
F_85 ( 1 ) ;
return - V_119 ;
}
for ( V_25 = V_273 -> V_615 ; V_273 -> V_616 [ V_25 ] ; V_25 ++ )
F_280 ( V_273 -> V_616 [ V_25 ] ) ;
for ( V_25 = 0 ; V_25 < V_273 -> V_615 ; V_25 ++ ) {
V_273 -> V_616 [ V_25 ] -> V_31 = F_310 ( & V_650 ) ;
V_273 -> V_616 [ V_25 ] -> V_589 = V_25 + 1 ;
}
for ( V_25 = 0 ; V_25 < V_273 -> V_615 ; V_25 ++ ) {
V_182 = F_311 ( V_273 -> V_15 , V_273 -> V_616 [ V_25 ] ) ;
if ( V_182 ) {
goto V_651;
}
}
V_182 = F_312 ( V_273 , V_649 ) ;
if ( V_182 )
goto V_651;
for ( V_25 = 0 ; V_25 < V_273 -> V_615 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_616 [ V_25 ] ;
unsigned long V_47 ;
if ( V_5 -> V_33 == V_34 && ( V_5 -> V_42 & V_449 ) )
V_5 -> V_33 = V_285 ;
F_264 ( & V_5 -> V_3 ) ;
if ( V_5 -> V_12 )
F_264 ( V_5 -> V_12 ) ;
V_47 = F_31 ( V_5 -> V_44 , V_5 -> V_45 ,
V_5 -> V_46 ) ;
if ( ! F_298 ( V_5 ) ) {
V_621 ( V_5 , L_162 ,
( V_5 -> V_42 & V_449 ) ? 'S' : 'P' ,
F_36 ( V_47 ) ,
V_5 -> V_3 . V_540 . V_286 ) ;
F_313 ( & V_5 -> V_3 . V_540 ) ;
} else
V_621 ( V_5 , L_163 ) ;
}
for ( V_25 = 0 ; V_25 < V_273 -> V_615 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_616 [ V_25 ] ;
F_314 ( F_305 , V_5 ) ;
}
return 0 ;
V_651:
while ( -- V_25 >= 0 ) {
F_315 ( V_273 -> V_616 [ V_25 ] ) ;
}
return V_182 ;
}
int F_316 ( struct V_518 * V_273 , int V_652 ,
T_8 V_653 , unsigned long V_654 ,
struct V_648 * V_649 )
{
int V_25 , V_182 ;
V_182 = F_297 ( V_273 ) ;
if ( V_182 )
return V_182 ;
if ( ! V_652 ) {
F_85 ( V_653 ) ;
return F_308 ( V_273 , V_649 ) ;
}
V_182 = F_317 ( V_273 -> V_15 , V_652 , V_653 , V_654 ,
F_318 ( V_273 -> V_15 ) , V_273 ) ;
if ( V_182 )
return V_182 ;
for ( V_25 = 0 ; V_25 < V_273 -> V_615 ; V_25 ++ )
F_319 ( V_273 -> V_616 [ V_25 ] , L_164 , V_652 ) ;
V_182 = F_308 ( V_273 , V_649 ) ;
if ( V_182 )
F_320 ( V_273 -> V_15 , V_652 , V_273 ) ;
return V_182 ;
}
static void F_321 ( struct V_4 * V_5 )
{
unsigned long V_42 ;
struct V_2 * V_3 ;
struct V_14 * V_15 ;
if ( ! V_5 -> V_215 -> V_216 )
goto V_655;
F_67 ( V_5 -> V_211 , V_42 ) ;
V_5 -> V_212 |= V_656 ;
F_225 ( V_5 ) ;
F_68 ( V_5 -> V_211 , V_42 ) ;
F_239 ( V_5 ) ;
F_85 ( ! ( V_5 -> V_212 & V_657 ) ) ;
F_322 ( & V_5 -> V_599 ) ;
V_655:
F_199 (link, ap, HOST_FIRST) {
F_140 (dev, link, ALL) {
if ( F_254 ( V_15 ) )
F_323 ( V_15 ) ;
}
}
if ( V_5 -> V_11 ) {
int V_25 ;
for ( V_25 = 0 ; V_25 < V_658 ; V_25 ++ )
F_324 ( & V_5 -> V_11 [ V_25 ] ) ;
}
F_325 ( V_5 -> V_293 ) ;
F_315 ( V_5 ) ;
}
void F_326 ( struct V_518 * V_273 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_273 -> V_615 ; V_25 ++ )
F_321 ( V_273 -> V_616 [ V_25 ] ) ;
F_327 ( V_273 ) ;
}
void F_328 ( struct V_659 * V_660 )
{
struct V_518 * V_273 = F_329 ( V_660 ) ;
F_326 ( V_273 ) ;
}
int F_330 ( struct V_659 * V_660 , const struct V_661 * V_132 )
{
unsigned long V_387 = 0 ;
switch ( V_132 -> V_662 ) {
case 1 : {
T_2 V_663 = 0 ;
F_331 ( V_660 , V_132 -> V_559 , & V_663 ) ;
V_387 = V_663 ;
break;
}
case 2 : {
T_4 V_664 = 0 ;
F_332 ( V_660 , V_132 -> V_559 , & V_664 ) ;
V_387 = V_664 ;
break;
}
case 4 : {
T_1 V_665 = 0 ;
F_333 ( V_660 , V_132 -> V_559 , & V_665 ) ;
V_387 = V_665 ;
break;
}
default:
return - V_119 ;
}
V_387 &= V_132 -> V_391 ;
return ( V_387 == V_132 -> V_560 ) ? 1 : 0 ;
}
void F_334 ( struct V_659 * V_660 , T_6 V_563 )
{
F_335 ( V_660 ) ;
F_336 ( V_660 ) ;
if ( V_563 . V_666 & V_667 )
F_337 ( V_660 , V_668 ) ;
}
int F_338 ( struct V_659 * V_660 )
{
int V_182 ;
F_337 ( V_660 , V_669 ) ;
F_339 ( V_660 ) ;
V_182 = F_340 ( V_660 ) ;
if ( V_182 ) {
F_299 ( & V_660 -> V_15 ,
L_165 , V_182 ) ;
return V_182 ;
}
F_341 ( V_660 ) ;
return 0 ;
}
int F_342 ( struct V_659 * V_660 , T_6 V_563 )
{
struct V_518 * V_273 = F_329 ( V_660 ) ;
int V_182 = 0 ;
V_182 = F_259 ( V_273 , V_563 ) ;
if ( V_182 )
return V_182 ;
F_334 ( V_660 , V_563 ) ;
return 0 ;
}
int F_343 ( struct V_659 * V_660 )
{
struct V_518 * V_273 = F_329 ( V_660 ) ;
int V_182 ;
V_182 = F_338 ( V_660 ) ;
if ( V_182 == 0 )
F_260 ( V_273 ) ;
return V_182 ;
}
int F_344 ( struct V_670 * V_660 )
{
struct V_518 * V_273 = F_345 ( V_660 ) ;
F_326 ( V_273 ) ;
return 0 ;
}
static int T_9 F_346 ( char * * V_482 ,
struct V_27 * V_671 ,
const char * * V_255 )
{
static struct V_672 V_673 [] V_674 = {
{ L_166 , . V_33 = V_370 } ,
{ L_167 , . V_33 = V_371 } ,
{ L_168 , . V_33 = V_517 } ,
{ L_169 , . V_33 = V_372 } ,
{ L_170 , . V_33 = V_373 } ,
{ L_171 , . V_33 = V_285 } ,
{ L_172 , . V_39 = 1 } ,
{ L_173 , . V_39 = 2 } ,
{ L_174 , . V_49 = V_291 } ,
{ L_175 , . V_50 = V_291 } ,
{ L_176 , . V_49 = V_270 } ,
{ L_177 , . V_47 = 1 << ( V_121 + 0 ) } ,
{ L_178 , . V_47 = 1 << ( V_121 + 1 ) } ,
{ L_179 , . V_47 = 1 << ( V_121 + 2 ) } ,
{ L_180 , . V_47 = 1 << ( V_121 + 3 ) } ,
{ L_181 , . V_47 = 1 << ( V_121 + 4 ) } ,
{ L_182 , . V_47 = 1 << ( V_121 + 5 ) } ,
{ L_183 , . V_47 = 1 << ( V_121 + 6 ) } ,
{ L_184 , . V_47 = 1 << ( V_123 + 0 ) } ,
{ L_185 , . V_47 = 1 << ( V_123 + 1 ) } ,
{ L_186 , . V_47 = 1 << ( V_123 + 2 ) } ,
{ L_187 , . V_47 = 1 << ( V_123 + 3 ) } ,
{ L_188 , . V_47 = 1 << ( V_123 + 4 ) } ,
{ L_189 , . V_47 = 1 << ( V_125 + 0 ) } ,
{ L_190 , . V_47 = 1 << ( V_125 + 0 ) } ,
{ L_191 , . V_47 = 1 << ( V_125 + 0 ) } ,
{ L_192 , . V_47 = 1 << ( V_125 + 1 ) } ,
{ L_193 , . V_47 = 1 << ( V_125 + 1 ) } ,
{ L_194 , . V_47 = 1 << ( V_125 + 1 ) } ,
{ L_195 , . V_47 = 1 << ( V_125 + 2 ) } ,
{ L_196 , . V_47 = 1 << ( V_125 + 2 ) } ,
{ L_197 , . V_47 = 1 << ( V_125 + 2 ) } ,
{ L_198 , . V_47 = 1 << ( V_125 + 3 ) } ,
{ L_199 , . V_47 = 1 << ( V_125 + 3 ) } ,
{ L_200 , . V_47 = 1 << ( V_125 + 3 ) } ,
{ L_201 , . V_47 = 1 << ( V_125 + 4 ) } ,
{ L_202 , . V_47 = 1 << ( V_125 + 4 ) } ,
{ L_203 , . V_47 = 1 << ( V_125 + 4 ) } ,
{ L_204 , . V_47 = 1 << ( V_125 + 5 ) } ,
{ L_205 , . V_47 = 1 << ( V_125 + 5 ) } ,
{ L_206 , . V_47 = 1 << ( V_125 + 5 ) } ,
{ L_207 , . V_47 = 1 << ( V_125 + 6 ) } ,
{ L_208 , . V_47 = 1 << ( V_125 + 6 ) } ,
{ L_209 , . V_47 = 1 << ( V_125 + 6 ) } ,
{ L_210 , . V_47 = 1 << ( V_125 + 7 ) } ,
{ L_211 , . V_41 = V_675 } ,
{ L_212 , . V_41 = V_676 } ,
{ L_213 , . V_41 = V_675 | V_676 } ,
{ L_214 , . V_41 = V_677 } ,
{ L_215 , . V_49 = V_357 } ,
{ L_216 , . V_49 = V_317 } ,
} ;
char * V_465 = * V_482 , * V_149 = * V_482 ;
char * V_144 , * V_560 , * V_678 ;
const struct V_672 * V_679 = NULL ;
int V_680 = 0 , V_25 ;
while ( * V_149 != '\0' && * V_149 != ',' )
V_149 ++ ;
if ( * V_149 == '\0' )
* V_482 = V_149 ;
else
* V_482 = V_149 + 1 ;
* V_149 = '\0' ;
V_149 = strchr ( V_465 , ':' ) ;
if ( ! V_149 ) {
V_560 = F_347 ( V_465 ) ;
goto V_681;
}
* V_149 = '\0' ;
V_144 = F_347 ( V_465 ) ;
V_560 = F_347 ( V_149 + 1 ) ;
V_149 = strchr ( V_144 , '.' ) ;
if ( V_149 ) {
* V_149 ++ = '\0' ;
V_671 -> V_21 = F_348 ( V_149 , & V_678 , 10 ) ;
if ( V_149 == V_678 || * V_678 != '\0' ) {
* V_255 = L_217 ;
return - V_119 ;
}
}
V_671 -> V_30 = F_348 ( V_144 , & V_678 , 10 ) ;
if ( V_149 == V_678 || * V_678 != '\0' ) {
* V_255 = L_218 ;
return - V_119 ;
}
V_681:
for ( V_25 = 0 ; V_25 < F_37 ( V_673 ) ; V_25 ++ ) {
const struct V_672 * V_682 = & V_673 [ V_25 ] ;
if ( strncasecmp ( V_560 , V_682 -> V_35 , strlen ( V_560 ) ) )
continue;
V_680 ++ ;
V_679 = V_682 ;
if ( strcasecmp ( V_560 , V_682 -> V_35 ) == 0 ) {
V_680 = 1 ;
break;
}
}
if ( ! V_680 ) {
* V_255 = L_219 ;
return - V_119 ;
}
if ( V_680 > 1 ) {
* V_255 = L_220 ;
return - V_119 ;
}
V_671 -> V_32 = * V_679 ;
return 0 ;
}
static void T_9 F_349 ( void )
{
int V_683 = 0 , V_684 = 1 ;
int V_685 = - 1 , V_686 = - 1 ;
char * V_149 , * V_482 , * V_23 ;
for ( V_149 = V_687 ; * V_149 ; V_149 ++ )
if ( * V_149 == ',' )
V_684 ++ ;
V_29 = F_266 ( sizeof( V_29 [ 0 ] ) * V_684 , V_587 ) ;
if ( ! V_29 ) {
F_350 ( V_688 L_221
L_222 ) ;
return;
}
for ( V_482 = V_687 ; * V_482 != '\0' ; V_482 = V_23 ) {
const char * V_255 = L_68 ;
struct V_27 V_689 = { . V_30 = - 1 , . V_21 = - 1 } ;
V_23 = V_482 ;
if ( F_346 ( & V_23 , & V_689 , & V_255 ) ) {
F_350 ( V_688 L_223
L_224 ,
V_482 , V_255 ) ;
continue;
}
if ( V_689 . V_30 == - 1 ) {
V_689 . V_30 = V_685 ;
V_689 . V_21 = V_686 ;
}
V_29 [ V_683 ++ ] = V_689 ;
V_685 = V_689 . V_30 ;
V_686 = V_689 . V_21 ;
}
V_26 = V_683 ;
}
static int T_9 F_351 ( void )
{
int V_182 ;
F_349 () ;
V_182 = F_352 () ;
if ( V_182 ) {
F_280 ( V_29 ) ;
return V_182 ;
}
F_353 () ;
V_690 = F_354 () ;
if ( ! V_690 ) {
F_355 () ;
V_182 = - V_628 ;
goto V_264;
}
F_350 ( V_271 L_225 V_691 L_226 ) ;
return 0 ;
V_264:
return V_182 ;
}
static void T_10 F_356 ( void )
{
F_357 ( V_690 ) ;
F_358 () ;
F_355 () ;
F_280 ( V_29 ) ;
}
int F_359 ( void )
{
return F_360 ( & V_692 ) ;
}
void F_175 ( struct V_4 * V_5 , unsigned int V_693 )
{
bool V_694 = V_5 && V_5 -> V_273 -> V_695 == V_696 ;
if ( V_694 )
F_75 ( V_5 ) ;
F_181 ( V_693 ) ;
if ( V_694 )
F_78 ( V_5 ) ;
}
T_1 F_361 ( struct V_4 * V_5 , void T_11 * V_559 , T_1 V_391 , T_1 V_560 ,
unsigned long V_478 , unsigned long V_204 )
{
unsigned long V_464 ;
T_1 V_387 ;
V_387 = F_362 ( V_559 ) ;
V_464 = F_170 ( V_466 , V_204 ) ;
while ( ( V_387 & V_391 ) == V_560 && F_174 ( V_466 , V_464 ) ) {
F_175 ( V_5 , V_478 ) ;
V_387 = F_362 ( V_559 ) ;
}
return V_387 ;
}
bool F_363 ( struct V_2 * V_3 )
{
unsigned long V_697 = V_3 -> V_698 +
F_77 ( V_699 ) ;
if ( V_3 -> V_700 > V_324 )
return true ;
if ( ( V_3 -> V_42 & V_701 ) &&
F_174 ( V_466 , V_697 ) )
return true ;
return false ;
}
static unsigned int F_364 ( struct V_194 * V_195 )
{
return V_214 ;
}
static void F_365 ( struct V_4 * V_5 )
{
}
void F_366 ( const struct V_4 * V_5 , const char * V_702 ,
const char * V_703 , ... )
{
struct V_704 V_705 ;
T_12 args ;
va_start ( args , V_703 ) ;
V_705 . V_703 = V_703 ;
V_705 . V_706 = & args ;
F_350 ( L_227 , V_702 , V_5 -> V_31 , & V_705 ) ;
va_end ( args ) ;
}
void F_367 ( const struct V_2 * V_3 , const char * V_702 ,
const char * V_703 , ... )
{
struct V_704 V_705 ;
T_12 args ;
va_start ( args , V_703 ) ;
V_705 . V_703 = V_703 ;
V_705 . V_706 = & args ;
if ( F_4 ( V_3 -> V_5 ) || V_3 -> V_5 -> V_12 )
F_350 ( L_228 ,
V_702 , V_3 -> V_5 -> V_31 , V_3 -> V_38 , & V_705 ) ;
else
F_350 ( L_227 ,
V_702 , V_3 -> V_5 -> V_31 , & V_705 ) ;
va_end ( args ) ;
}
void F_368 ( const struct V_14 * V_15 , const char * V_702 ,
const char * V_703 , ... )
{
struct V_704 V_705 ;
T_12 args ;
va_start ( args , V_703 ) ;
V_705 . V_703 = V_703 ;
V_705 . V_706 = & args ;
F_350 ( L_228 ,
V_702 , V_15 -> V_3 -> V_5 -> V_31 , V_15 -> V_3 -> V_38 + V_15 -> V_24 ,
& V_705 ) ;
va_end ( args ) ;
}
void F_369 ( const struct V_21 * V_15 , const char * V_707 )
{
F_370 ( V_271 , V_15 , L_229 , V_707 ) ;
}
