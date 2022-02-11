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
F_11 ( V_5 , V_35 ,
L_1 , V_28 -> V_32 . V_36 ) ;
return;
}
}
static void F_12 ( struct V_2 * V_3 )
{
bool V_37 = false ;
int V_38 = V_3 -> V_39 ;
int V_25 ;
if ( F_13 ( V_3 ) )
V_38 += 15 ;
for ( V_25 = V_26 - 1 ; V_25 >= 0 ; V_25 -- ) {
const struct V_27 * V_28 = & V_29 [ V_25 ] ;
if ( V_28 -> V_30 != - 1 && V_28 -> V_30 != V_3 -> V_5 -> V_31 )
continue;
if ( V_28 -> V_21 != - 1 && V_28 -> V_21 != V_38 )
continue;
if ( ! V_37 && V_28 -> V_32 . V_40 ) {
V_3 -> V_41 = ( 1 << V_28 -> V_32 . V_40 ) - 1 ;
F_14 ( V_3 , V_35 ,
L_2 ,
V_28 -> V_32 . V_36 ) ;
V_37 = true ;
}
if ( V_28 -> V_32 . V_42 ) {
V_3 -> V_43 |= V_28 -> V_32 . V_42 ;
F_14 ( V_3 , V_35 ,
L_3 ,
V_28 -> V_32 . V_42 , V_3 -> V_43 ) ;
}
}
}
static void F_15 ( struct V_14 * V_15 )
{
int V_24 = V_15 -> V_3 -> V_39 + V_15 -> V_24 ;
int V_44 = V_24 ;
int V_25 ;
if ( F_13 ( V_15 -> V_3 ) )
V_44 += 15 ;
for ( V_25 = V_26 - 1 ; V_25 >= 0 ; V_25 -- ) {
const struct V_27 * V_28 = & V_29 [ V_25 ] ;
unsigned long V_45 , V_46 , V_47 ;
if ( V_28 -> V_30 != - 1 && V_28 -> V_30 != V_15 -> V_3 -> V_5 -> V_31 )
continue;
if ( V_28 -> V_21 != - 1 && V_28 -> V_21 != V_24 &&
V_28 -> V_21 != V_44 )
continue;
if ( ! V_28 -> V_32 . V_48 )
continue;
F_16 ( V_28 -> V_32 . V_48 ,
& V_45 , & V_46 , & V_47 ) ;
if ( V_47 )
V_15 -> V_47 = V_47 ;
else if ( V_46 ) {
V_15 -> V_47 = 0 ;
V_15 -> V_46 = V_46 ;
} else {
V_15 -> V_47 = 0 ;
V_15 -> V_46 = 0 ;
V_15 -> V_45 = V_45 ;
}
F_17 ( V_15 , V_35 ,
L_4 , V_28 -> V_32 . V_36 ) ;
return;
}
}
static void F_18 ( struct V_14 * V_15 )
{
int V_24 = V_15 -> V_3 -> V_39 + V_15 -> V_24 ;
int V_44 = V_24 ;
int V_25 ;
if ( F_13 ( V_15 -> V_3 ) )
V_44 += 15 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
const struct V_27 * V_28 = & V_29 [ V_25 ] ;
if ( V_28 -> V_30 != - 1 && V_28 -> V_30 != V_15 -> V_3 -> V_5 -> V_31 )
continue;
if ( V_28 -> V_21 != - 1 && V_28 -> V_21 != V_24 &&
V_28 -> V_21 != V_44 )
continue;
if ( ! ( ~ V_15 -> V_49 & V_28 -> V_32 . V_50 ) &&
! ( V_15 -> V_49 & V_28 -> V_32 . V_51 ) )
continue;
V_15 -> V_49 |= V_28 -> V_32 . V_50 ;
V_15 -> V_49 &= ~ V_28 -> V_32 . V_51 ;
F_17 ( V_15 , V_35 ,
L_5 , V_28 -> V_32 . V_36 ) ;
}
}
int F_19 ( T_2 V_52 )
{
switch ( V_52 ) {
case V_53 :
case V_54 :
return V_55 ;
case V_56 :
case V_57 :
case V_58 :
return V_59 ;
case V_60 :
case V_61 :
return V_62 ;
case V_63 :
case V_64 :
if ( V_65 )
return V_66 ;
default:
return V_67 ;
}
}
void F_20 ( const struct V_68 * V_69 , T_2 V_39 , int V_70 , T_2 * V_71 )
{
V_71 [ 0 ] = 0x27 ;
V_71 [ 1 ] = V_39 & 0xf ;
if ( V_70 )
V_71 [ 1 ] |= ( 1 << 7 ) ;
V_71 [ 2 ] = V_69 -> V_72 ;
V_71 [ 3 ] = V_69 -> V_73 ;
V_71 [ 4 ] = V_69 -> V_74 ;
V_71 [ 5 ] = V_69 -> V_75 ;
V_71 [ 6 ] = V_69 -> V_76 ;
V_71 [ 7 ] = V_69 -> V_21 ;
V_71 [ 8 ] = V_69 -> V_77 ;
V_71 [ 9 ] = V_69 -> V_78 ;
V_71 [ 10 ] = V_69 -> V_79 ;
V_71 [ 11 ] = V_69 -> V_80 ;
V_71 [ 12 ] = V_69 -> V_81 ;
V_71 [ 13 ] = V_69 -> V_82 ;
V_71 [ 14 ] = 0 ;
V_71 [ 15 ] = V_69 -> V_83 ;
V_71 [ 16 ] = 0 ;
V_71 [ 17 ] = 0 ;
V_71 [ 18 ] = 0 ;
V_71 [ 19 ] = 0 ;
}
void F_21 ( const T_2 * V_71 , struct V_68 * V_69 )
{
V_69 -> V_72 = V_71 [ 2 ] ;
V_69 -> V_73 = V_71 [ 3 ] ;
V_69 -> V_74 = V_71 [ 4 ] ;
V_69 -> V_75 = V_71 [ 5 ] ;
V_69 -> V_76 = V_71 [ 6 ] ;
V_69 -> V_21 = V_71 [ 7 ] ;
V_69 -> V_77 = V_71 [ 8 ] ;
V_69 -> V_78 = V_71 [ 9 ] ;
V_69 -> V_79 = V_71 [ 10 ] ;
V_69 -> V_81 = V_71 [ 12 ] ;
V_69 -> V_82 = V_71 [ 13 ] ;
}
static int F_22 ( struct V_68 * V_69 , struct V_14 * V_15 )
{
T_2 V_84 ;
int V_85 , V_86 , V_87 , V_88 ;
V_86 = ( V_69 -> V_43 & V_89 ) ? 4 : 0 ;
V_87 = ( V_69 -> V_43 & V_90 ) ? 2 : 0 ;
V_88 = ( V_69 -> V_43 & V_91 ) ? 1 : 0 ;
if ( V_15 -> V_43 & V_92 ) {
V_69 -> V_93 = V_94 ;
V_85 = V_15 -> V_95 ? 0 : 8 ;
} else if ( V_87 && ( V_15 -> V_3 -> V_5 -> V_43 & V_96 ) ) {
V_69 -> V_93 = V_94 ;
V_85 = V_15 -> V_95 ? 0 : 8 ;
} else {
V_69 -> V_93 = V_97 ;
V_85 = 16 ;
}
V_84 = V_98 [ V_85 + V_86 + V_87 + V_88 ] ;
if ( V_84 ) {
V_69 -> V_72 = V_84 ;
return 0 ;
}
return - 1 ;
}
T_3 F_23 ( struct V_68 * V_69 , struct V_14 * V_15 )
{
T_3 V_99 = 0 ;
if ( V_69 -> V_43 & V_100 ) {
if ( V_69 -> V_43 & V_90 ) {
V_99 |= ( T_3 ) V_69 -> V_79 << 40 ;
V_99 |= ( T_3 ) V_69 -> V_78 << 32 ;
V_99 |= ( T_3 ) V_69 -> V_77 << 24 ;
} else
V_99 |= ( V_69 -> V_21 & 0xf ) << 24 ;
V_99 |= V_69 -> V_76 << 16 ;
V_99 |= V_69 -> V_75 << 8 ;
V_99 |= V_69 -> V_74 ;
} else {
T_1 V_101 , V_102 , V_103 ;
V_101 = V_69 -> V_75 | ( V_69 -> V_76 << 8 ) ;
V_102 = V_69 -> V_21 & 0xf ;
V_103 = V_69 -> V_74 ;
if ( ! V_103 ) {
F_17 ( V_15 , V_104 , L_6
L_7 ) ;
V_103 = 1 ;
}
V_99 = ( V_101 * V_15 -> V_105 + V_102 ) * V_15 -> V_106 + V_103 - 1 ;
}
return V_99 ;
}
int F_24 ( struct V_68 * V_69 , struct V_14 * V_15 ,
T_3 V_99 , T_1 V_107 , unsigned int V_108 ,
unsigned int V_109 )
{
V_69 -> V_43 |= V_110 | V_111 ;
V_69 -> V_43 |= V_108 ;
if ( F_25 ( V_15 ) && F_26 ( V_109 != V_112 ) ) {
if ( ! F_27 ( V_99 , V_107 ) )
return - V_113 ;
V_69 -> V_93 = V_114 ;
V_69 -> V_43 |= V_100 | V_90 ;
if ( V_69 -> V_43 & V_91 )
V_69 -> V_72 = V_115 ;
else
V_69 -> V_72 = V_116 ;
V_69 -> V_81 = V_109 << 3 ;
V_69 -> V_80 = ( V_107 >> 8 ) & 0xff ;
V_69 -> V_73 = V_107 & 0xff ;
V_69 -> V_79 = ( V_99 >> 40 ) & 0xff ;
V_69 -> V_78 = ( V_99 >> 32 ) & 0xff ;
V_69 -> V_77 = ( V_99 >> 24 ) & 0xff ;
V_69 -> V_76 = ( V_99 >> 16 ) & 0xff ;
V_69 -> V_75 = ( V_99 >> 8 ) & 0xff ;
V_69 -> V_74 = V_99 & 0xff ;
V_69 -> V_21 = 1 << 6 ;
if ( V_69 -> V_43 & V_89 )
V_69 -> V_21 |= 1 << 7 ;
} else if ( V_15 -> V_43 & V_117 ) {
V_69 -> V_43 |= V_100 ;
if ( F_28 ( V_99 , V_107 ) ) {
V_69 -> V_21 |= ( V_99 >> 24 ) & 0xf ;
} else if ( F_27 ( V_99 , V_107 ) ) {
if ( ! ( V_15 -> V_43 & V_118 ) )
return - V_113 ;
V_69 -> V_43 |= V_90 ;
V_69 -> V_82 = ( V_107 >> 8 ) & 0xff ;
V_69 -> V_79 = ( V_99 >> 40 ) & 0xff ;
V_69 -> V_78 = ( V_99 >> 32 ) & 0xff ;
V_69 -> V_77 = ( V_99 >> 24 ) & 0xff ;
} else
return - V_113 ;
if ( F_5 ( F_22 ( V_69 , V_15 ) < 0 ) )
return - V_119 ;
V_69 -> V_81 = V_107 & 0xff ;
V_69 -> V_76 = ( V_99 >> 16 ) & 0xff ;
V_69 -> V_75 = ( V_99 >> 8 ) & 0xff ;
V_69 -> V_74 = V_99 & 0xff ;
V_69 -> V_21 |= V_120 ;
} else {
T_1 V_103 , V_102 , V_101 , V_121 ;
if ( ! F_28 ( V_99 , V_107 ) )
return - V_113 ;
if ( F_5 ( F_22 ( V_69 , V_15 ) < 0 ) )
return - V_119 ;
V_121 = ( T_1 ) V_99 / V_15 -> V_106 ;
V_101 = V_121 / V_15 -> V_105 ;
V_102 = V_121 % V_15 -> V_105 ;
V_103 = ( T_1 ) V_99 % V_15 -> V_106 + 1 ;
F_29 ( L_8 ,
( T_1 ) V_99 , V_121 , V_101 , V_102 , V_103 ) ;
if ( ( V_101 >> 16 ) || ( V_102 >> 4 ) || ( V_103 >> 8 ) || ( ! V_103 ) )
return - V_113 ;
V_69 -> V_81 = V_107 & 0xff ;
V_69 -> V_74 = V_103 ;
V_69 -> V_75 = V_101 ;
V_69 -> V_76 = V_101 >> 8 ;
V_69 -> V_21 |= V_102 ;
}
return 0 ;
}
unsigned long F_30 ( unsigned long V_45 ,
unsigned long V_46 ,
unsigned long V_47 )
{
return ( ( V_45 << V_122 ) & V_123 ) |
( ( V_46 << V_124 ) & V_125 ) |
( ( V_47 << V_126 ) & V_127 ) ;
}
void F_16 ( unsigned long V_48 , unsigned long * V_45 ,
unsigned long * V_46 , unsigned long * V_47 )
{
if ( V_45 )
* V_45 = ( V_48 & V_123 ) >> V_122 ;
if ( V_46 )
* V_46 = ( V_48 & V_125 ) >> V_124 ;
if ( V_47 )
* V_47 = ( V_48 & V_127 ) >> V_126 ;
}
T_2 F_31 ( unsigned long V_48 )
{
int V_128 = F_32 ( V_48 ) - 1 ;
const struct V_129 * V_130 ;
for ( V_130 = V_131 ; V_130 -> V_132 >= 0 ; V_130 ++ )
if ( V_128 >= V_130 -> V_132 && V_128 < V_130 -> V_132 + V_130 -> V_133 )
return V_130 -> V_134 + V_128 - V_130 -> V_132 ;
return 0xff ;
}
unsigned long F_33 ( T_2 V_135 )
{
const struct V_129 * V_130 ;
for ( V_130 = V_131 ; V_130 -> V_132 >= 0 ; V_130 ++ )
if ( V_135 >= V_130 -> V_134 && V_135 < V_130 -> V_134 + V_130 -> V_133 )
return ( ( 2 << ( V_130 -> V_132 + V_135 - V_130 -> V_134 ) ) - 1 )
& ~ ( ( 1 << V_130 -> V_132 ) - 1 ) ;
return 0 ;
}
int F_34 ( unsigned long V_135 )
{
const struct V_129 * V_130 ;
for ( V_130 = V_131 ; V_130 -> V_132 >= 0 ; V_130 ++ )
if ( V_135 >= V_130 -> V_134 && V_135 < V_130 -> V_134 + V_130 -> V_133 )
return V_130 -> V_132 ;
return - 1 ;
}
const char * F_35 ( unsigned long V_48 )
{
static const char * const V_136 [] = {
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
L_28 ,
} ;
int V_128 ;
V_128 = F_32 ( V_48 ) - 1 ;
if ( V_128 >= 0 && V_128 < F_36 ( V_136 ) )
return V_136 [ V_128 ] ;
return L_29 ;
}
const char * F_37 ( unsigned int V_137 )
{
static const char * const V_138 [] = {
L_30 ,
L_31 ,
L_32 ,
} ;
if ( V_137 == 0 || ( V_137 - 1 ) >= F_36 ( V_138 ) )
return L_33 ;
return V_138 [ V_137 - 1 ] ;
}
unsigned int F_38 ( const struct V_68 * V_69 )
{
if ( ( V_69 -> V_75 == 0 ) && ( V_69 -> V_76 == 0 ) ) {
F_29 ( L_34 ) ;
return V_139 ;
}
if ( ( V_69 -> V_75 == 0x14 ) && ( V_69 -> V_76 == 0xeb ) ) {
F_29 ( L_35 ) ;
return V_140 ;
}
if ( ( V_69 -> V_75 == 0x69 ) && ( V_69 -> V_76 == 0x96 ) ) {
F_29 ( L_36 ) ;
return V_141 ;
}
if ( ( V_69 -> V_75 == 0x3c ) && ( V_69 -> V_76 == 0xc3 ) ) {
F_29 ( L_37 ) ;
return V_142 ;
}
F_29 ( L_38 ) ;
return V_143 ;
}
void F_39 ( const T_4 * V_144 , unsigned char * V_145 ,
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
void F_40 ( const T_4 * V_144 , unsigned char * V_145 ,
unsigned int V_146 , unsigned int V_147 )
{
unsigned char * V_149 ;
F_39 ( V_144 , V_145 , V_146 , V_147 - 1 ) ;
V_149 = V_145 + F_41 ( V_145 , V_147 - 1 ) ;
while ( V_149 > V_145 && V_149 [ - 1 ] == ' ' )
V_149 -- ;
* V_149 = '\0' ;
}
static T_3 F_42 ( const T_4 * V_144 )
{
if ( F_43 ( V_144 ) ) {
if ( F_44 ( V_144 ) )
return F_45 ( V_144 , V_150 ) ;
else
return F_46 ( V_144 , V_151 ) ;
} else {
if ( F_47 ( V_144 ) )
return V_144 [ V_152 ] * V_144 [ V_153 ] *
V_144 [ V_154 ] ;
else
return V_144 [ V_155 ] * V_144 [ V_156 ] *
V_144 [ V_157 ] ;
}
}
T_3 F_48 ( const struct V_68 * V_69 )
{
T_3 V_106 = 0 ;
V_106 |= ( ( T_3 ) ( V_69 -> V_79 & 0xff ) ) << 40 ;
V_106 |= ( ( T_3 ) ( V_69 -> V_78 & 0xff ) ) << 32 ;
V_106 |= ( ( T_3 ) ( V_69 -> V_77 & 0xff ) ) << 24 ;
V_106 |= ( V_69 -> V_76 & 0xff ) << 16 ;
V_106 |= ( V_69 -> V_75 & 0xff ) << 8 ;
V_106 |= ( V_69 -> V_74 & 0xff ) ;
return V_106 ;
}
T_3 F_49 ( const struct V_68 * V_69 )
{
T_3 V_106 = 0 ;
V_106 |= ( V_69 -> V_21 & 0x0f ) << 24 ;
V_106 |= ( V_69 -> V_76 & 0xff ) << 16 ;
V_106 |= ( V_69 -> V_75 & 0xff ) << 8 ;
V_106 |= ( V_69 -> V_74 & 0xff ) ;
return V_106 ;
}
static int F_50 ( struct V_14 * V_15 , T_3 * V_158 )
{
unsigned int V_159 ;
struct V_68 V_69 ;
int V_87 = F_44 ( V_15 -> V_144 ) ;
F_51 ( V_15 , & V_69 ) ;
V_69 . V_43 |= V_111 | V_110 ;
if ( V_87 ) {
V_69 . V_72 = V_160 ;
V_69 . V_43 |= V_90 ;
} else
V_69 . V_72 = V_161 ;
V_69 . V_93 |= V_162 ;
V_69 . V_21 |= V_120 ;
V_159 = F_52 ( V_15 , & V_69 , NULL , V_163 , NULL , 0 , 0 ) ;
if ( V_159 ) {
F_17 ( V_15 , V_104 , L_39
L_40 , V_159 ) ;
if ( V_159 == V_164 && ( V_69 . V_73 & V_165 ) )
return - V_166 ;
return - V_167 ;
}
if ( V_87 )
* V_158 = F_48 ( & V_69 ) + 1 ;
else
* V_158 = F_49 ( & V_69 ) + 1 ;
if ( V_15 -> V_49 & V_168 )
( * V_158 ) -- ;
return 0 ;
}
static int F_53 ( struct V_14 * V_15 , T_3 V_169 )
{
unsigned int V_159 ;
struct V_68 V_69 ;
int V_87 = F_44 ( V_15 -> V_144 ) ;
V_169 -- ;
F_51 ( V_15 , & V_69 ) ;
V_69 . V_43 |= V_111 | V_110 ;
if ( V_87 ) {
V_69 . V_72 = V_170 ;
V_69 . V_43 |= V_90 ;
V_69 . V_77 = ( V_169 >> 24 ) & 0xff ;
V_69 . V_78 = ( V_169 >> 32 ) & 0xff ;
V_69 . V_79 = ( V_169 >> 40 ) & 0xff ;
} else {
V_69 . V_72 = V_171 ;
V_69 . V_21 |= ( V_169 >> 24 ) & 0xf ;
}
V_69 . V_93 |= V_162 ;
V_69 . V_21 |= V_120 ;
V_69 . V_74 = ( V_169 >> 0 ) & 0xff ;
V_69 . V_75 = ( V_169 >> 8 ) & 0xff ;
V_69 . V_76 = ( V_169 >> 16 ) & 0xff ;
V_159 = F_52 ( V_15 , & V_69 , NULL , V_163 , NULL , 0 , 0 ) ;
if ( V_159 ) {
F_17 ( V_15 , V_104 , L_41
L_40 , V_159 ) ;
if ( V_159 == V_164 &&
( V_69 . V_73 & ( V_165 | V_172 ) ) )
return - V_166 ;
return - V_167 ;
}
return 0 ;
}
static int F_54 ( struct V_14 * V_15 )
{
struct V_173 * V_174 = & V_15 -> V_3 -> V_175 ;
int V_176 = V_174 -> V_25 . V_43 & V_177 ;
bool V_178 = V_179 || V_15 -> V_43 & V_180 ;
T_3 V_106 = F_42 ( V_15 -> V_144 ) ;
T_3 V_181 ;
int V_182 ;
if ( V_15 -> V_183 != V_139 ||
! F_43 ( V_15 -> V_144 ) || ! F_55 ( V_15 -> V_144 ) ||
( V_15 -> V_49 & V_184 ) )
return 0 ;
V_182 = F_50 ( V_15 , & V_181 ) ;
if ( V_182 ) {
if ( V_182 == - V_166 || ! V_178 ) {
F_17 ( V_15 , V_104 , L_42
L_43 ) ;
V_15 -> V_49 |= V_184 ;
if ( V_182 == - V_166 )
V_182 = 0 ;
}
return V_182 ;
}
V_15 -> V_185 = V_181 ;
if ( V_181 <= V_106 || ! V_178 ) {
if ( ! V_176 || V_181 == V_106 )
return 0 ;
if ( V_181 > V_106 )
F_17 ( V_15 , V_186 ,
L_44 ,
( unsigned long long ) V_106 ,
( unsigned long long ) V_181 ) ;
else if ( V_181 < V_106 )
F_17 ( V_15 , V_104 ,
L_45
L_46 ,
( unsigned long long ) V_181 ,
( unsigned long long ) V_106 ) ;
return 0 ;
}
V_182 = F_53 ( V_15 , V_181 ) ;
if ( V_182 == - V_166 ) {
F_17 ( V_15 , V_104 , L_47
L_48 ,
( unsigned long long ) V_106 ,
( unsigned long long ) V_181 ) ;
V_15 -> V_49 |= V_184 ;
return 0 ;
} else if ( V_182 )
return V_182 ;
V_182 = F_56 ( V_15 , 0 ) ;
if ( V_182 ) {
F_17 ( V_15 , V_187 , L_49
L_50 ) ;
return V_182 ;
}
if ( V_176 ) {
T_3 V_169 = F_42 ( V_15 -> V_144 ) ;
F_17 ( V_15 , V_186 ,
L_51 ,
( unsigned long long ) V_106 ,
( unsigned long long ) V_169 ,
( unsigned long long ) V_181 ) ;
}
return 0 ;
}
static inline void F_57 ( const T_4 * V_144 )
{
F_29 ( L_52
L_53
L_54
L_55
L_56 ,
V_144 [ 49 ] ,
V_144 [ 53 ] ,
V_144 [ 63 ] ,
V_144 [ 64 ] ,
V_144 [ 75 ] ) ;
F_29 ( L_57
L_58
L_59
L_60
L_61 ,
V_144 [ 80 ] ,
V_144 [ 81 ] ,
V_144 [ 82 ] ,
V_144 [ 83 ] ,
V_144 [ 84 ] ) ;
F_29 ( L_62
L_63 ,
V_144 [ 88 ] ,
V_144 [ 93 ] ) ;
}
unsigned long F_58 ( const T_4 * V_144 )
{
unsigned long V_45 , V_46 , V_47 ;
if ( V_144 [ V_188 ] & ( 1 << 1 ) ) {
V_45 = V_144 [ V_189 ] & 0x03 ;
V_45 <<= 3 ;
V_45 |= 0x7 ;
} else {
T_2 V_7 = ( V_144 [ V_190 ] >> 8 ) & 0xFF ;
if ( V_7 < 5 )
V_45 = ( 2 << V_7 ) - 1 ;
else
V_45 = 1 ;
}
V_46 = V_144 [ V_191 ] & 0x07 ;
if ( F_59 ( V_144 ) ) {
int V_192 = ( V_144 [ V_193 ] >> 0 ) & 0x7 ;
int V_194 = ( V_144 [ V_193 ] >> 3 ) & 0x7 ;
if ( V_192 )
V_45 |= ( 1 << 5 ) ;
if ( V_192 > 1 )
V_45 |= ( 1 << 6 ) ;
if ( V_194 )
V_46 |= ( 1 << 3 ) ;
if ( V_194 > 1 )
V_46 |= ( 1 << 4 ) ;
}
V_47 = 0 ;
if ( V_144 [ V_188 ] & ( 1 << 2 ) )
V_47 = V_144 [ V_195 ] & 0xff ;
return F_30 ( V_45 , V_46 , V_47 ) ;
}
static void F_60 ( struct V_196 * V_197 )
{
struct V_198 * V_199 = V_197 -> V_200 ;
F_61 ( V_199 ) ;
}
unsigned F_62 ( struct V_14 * V_15 ,
struct V_68 * V_69 , const T_2 * V_201 ,
int V_202 , struct V_203 * V_204 ,
unsigned int V_205 , unsigned long V_206 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
T_2 V_72 = V_69 -> V_72 ;
int V_207 = 0 ;
struct V_196 * V_197 ;
unsigned int V_109 , V_208 ;
T_1 V_209 , V_210 ;
int V_211 ;
F_63 ( V_212 ) ;
unsigned long V_43 ;
unsigned int V_159 ;
int V_182 ;
F_64 ( V_5 -> V_213 , V_43 ) ;
if ( V_5 -> V_214 & V_215 ) {
F_65 ( V_5 -> V_213 , V_43 ) ;
return V_216 ;
}
if ( V_5 -> V_217 -> V_218 )
V_109 = V_112 ;
else
V_109 = 0 ;
if ( F_66 ( V_109 , & V_5 -> V_219 ) )
F_67 () ;
V_197 = F_68 ( V_5 , V_109 ) ;
V_197 -> V_109 = V_109 ;
V_197 -> V_220 = NULL ;
V_197 -> V_5 = V_5 ;
V_197 -> V_15 = V_15 ;
F_69 ( V_197 ) ;
V_208 = V_3 -> V_221 ;
V_209 = V_3 -> V_222 ;
V_210 = V_5 -> V_223 ;
V_211 = V_5 -> V_224 ;
V_3 -> V_221 = V_225 ;
V_3 -> V_222 = 0 ;
V_5 -> V_223 = 0 ;
V_5 -> V_224 = 0 ;
V_197 -> V_69 = * V_69 ;
if ( V_201 )
memcpy ( V_197 -> V_201 , V_201 , V_226 ) ;
V_197 -> V_43 |= V_227 ;
V_197 -> V_202 = V_202 ;
if ( V_202 != V_163 ) {
unsigned int V_25 , V_228 = 0 ;
struct V_203 * V_229 ;
F_70 (sgl, sg, n_elem, i)
V_228 += V_229 -> V_230 ;
F_71 ( V_197 , V_204 , V_205 ) ;
V_197 -> V_231 = V_228 ;
}
V_197 -> V_200 = & V_212 ;
V_197 -> V_232 = F_60 ;
F_72 ( V_197 ) ;
F_65 ( V_5 -> V_213 , V_43 ) ;
if ( ! V_206 ) {
if ( V_233 )
V_206 = V_233 * 1000 ;
else {
V_206 = F_73 ( V_15 , V_72 ) ;
V_207 = 1 ;
}
}
if ( V_5 -> V_217 -> V_218 )
F_74 ( V_5 ) ;
V_182 = F_75 ( & V_212 , F_76 ( V_206 ) ) ;
if ( V_5 -> V_217 -> V_218 )
F_77 ( V_5 ) ;
F_78 ( V_5 ) ;
if ( ! V_182 ) {
F_64 ( V_5 -> V_213 , V_43 ) ;
if ( V_197 -> V_43 & V_234 ) {
V_197 -> V_159 |= V_235 ;
if ( V_5 -> V_217 -> V_218 )
F_79 ( V_5 ) ;
else
F_80 ( V_197 ) ;
if ( F_81 ( V_5 ) )
F_17 ( V_15 , V_104 ,
L_64 , V_72 ) ;
}
F_65 ( V_5 -> V_213 , V_43 ) ;
}
if ( V_5 -> V_217 -> V_236 )
V_5 -> V_217 -> V_236 ( V_197 ) ;
if ( V_197 -> V_43 & V_237 ) {
if ( V_197 -> V_238 . V_72 & ( V_239 | V_240 ) )
V_197 -> V_159 |= V_164 ;
if ( ! V_197 -> V_159 )
V_197 -> V_159 |= V_241 ;
if ( V_197 -> V_159 & ~ V_241 )
V_197 -> V_159 &= ~ V_241 ;
}
F_64 ( V_5 -> V_213 , V_43 ) ;
* V_69 = V_197 -> V_238 ;
V_159 = V_197 -> V_159 ;
F_82 ( V_197 ) ;
V_3 -> V_221 = V_208 ;
V_3 -> V_222 = V_209 ;
V_5 -> V_223 = V_210 ;
V_5 -> V_224 = V_211 ;
F_65 ( V_5 -> V_213 , V_43 ) ;
if ( ( V_159 & V_235 ) && V_207 )
F_83 ( V_15 , V_72 ) ;
return V_159 ;
}
unsigned F_52 ( struct V_14 * V_15 ,
struct V_68 * V_69 , const T_2 * V_201 ,
int V_202 , void * V_242 , unsigned int V_228 ,
unsigned long V_206 )
{
struct V_203 * V_243 = NULL , V_229 ;
unsigned int V_205 = 0 ;
if ( V_202 != V_163 ) {
F_84 ( ! V_242 ) ;
F_85 ( & V_229 , V_242 , V_228 ) ;
V_243 = & V_229 ;
V_205 ++ ;
}
return F_62 ( V_15 , V_69 , V_201 , V_202 , V_243 , V_205 ,
V_206 ) ;
}
unsigned int F_86 ( struct V_14 * V_15 , T_2 V_84 )
{
struct V_68 V_69 ;
F_51 ( V_15 , & V_69 ) ;
V_69 . V_72 = V_84 ;
V_69 . V_43 |= V_111 ;
V_69 . V_93 = V_162 ;
return F_52 ( V_15 , & V_69 , NULL , V_163 , NULL , 0 , 0 ) ;
}
unsigned int F_87 ( const struct V_14 * V_244 )
{
if ( V_244 -> V_3 -> V_5 -> V_214 & V_245 )
return 0 ;
if ( V_244 -> V_3 -> V_5 -> V_43 & V_246 )
return 0 ;
if ( F_59 ( V_244 -> V_144 )
&& ( V_244 -> V_247 == V_248 || V_244 -> V_247 == V_249 ) )
return 0 ;
if ( V_244 -> V_247 > V_250 )
return 1 ;
if ( F_88 ( V_244 -> V_144 ) )
return 1 ;
return 0 ;
}
static T_1 F_89 ( const struct V_14 * V_244 )
{
if ( V_244 -> V_144 [ V_188 ] & 2 ) {
T_4 V_192 = V_244 -> V_144 [ V_251 ] ;
if ( V_192 ) {
if ( V_192 > 240 )
return 3 << V_122 ;
return 7 << V_122 ;
}
}
return 3 << V_122 ;
}
unsigned int F_90 ( struct V_14 * V_15 ,
struct V_68 * V_69 , T_4 * V_144 )
{
return F_52 ( V_15 , V_69 , NULL , V_252 ,
V_144 , sizeof( V_144 [ 0 ] ) * V_253 , 0 ) ;
}
int F_91 ( struct V_14 * V_15 , unsigned int * V_254 ,
unsigned int V_43 , T_4 * V_144 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
unsigned int V_183 = * V_254 ;
struct V_68 V_69 ;
unsigned int V_159 = 0 ;
const char * V_255 ;
bool V_256 = V_183 == V_142 ;
int V_257 = 1 , V_258 = 0 ;
int V_182 ;
if ( F_92 ( V_5 ) )
F_17 ( V_15 , V_259 , L_65 , V_260 ) ;
V_261:
F_51 ( V_15 , & V_69 ) ;
switch ( V_183 ) {
case V_142 :
V_183 = V_139 ;
case V_139 :
V_69 . V_72 = V_262 ;
break;
case V_140 :
V_69 . V_72 = V_263 ;
break;
default:
V_182 = - V_264 ;
V_255 = L_66 ;
goto V_265;
}
V_69 . V_93 = V_94 ;
V_69 . V_43 |= V_110 | V_111 ;
V_69 . V_43 |= V_266 ;
if ( V_5 -> V_217 -> V_267 )
V_159 = V_5 -> V_217 -> V_267 ( V_15 , & V_69 , V_144 ) ;
else
V_159 = F_90 ( V_15 , & V_69 , V_144 ) ;
if ( V_159 ) {
if ( V_159 & V_268 ) {
F_17 ( V_15 , V_259 ,
L_67 ) ;
return - V_269 ;
}
if ( V_256 ) {
F_17 ( V_15 , V_186 , L_68
L_69 ) ;
* V_254 = V_270 ;
return 0 ;
}
if ( ( V_159 == V_164 ) && ( V_69 . V_73 & V_165 ) ) {
if ( V_257 ) {
V_257 = 0 ;
if ( V_183 == V_139 )
V_183 = V_140 ;
else
V_183 = V_139 ;
goto V_261;
}
F_17 ( V_15 , V_259 ,
L_70 ) ;
return - V_269 ;
}
V_182 = - V_167 ;
V_255 = L_71 ;
goto V_265;
}
if ( V_15 -> V_49 & V_271 ) {
F_17 ( V_15 , V_259 , L_72
L_73 ,
V_183 , V_257 , V_258 ) ;
F_93 ( V_259 , L_74 , V_272 ,
16 , 2 , V_144 , V_253 * sizeof( * V_144 ) , true ) ;
}
V_257 = 0 ;
F_94 ( V_144 , V_253 ) ;
V_182 = - V_119 ;
V_255 = L_75 ;
if ( V_183 == V_139 ) {
if ( ! F_95 ( V_144 ) && ! F_59 ( V_144 ) )
goto V_265;
} else {
if ( F_95 ( V_144 ) )
goto V_265;
}
if ( ! V_258 && ( V_144 [ 2 ] == 0x37c8 || V_144 [ 2 ] == 0x738c ) ) {
V_258 = 1 ;
V_159 = F_96 ( V_15 , V_273 , 0 ) ;
if ( V_159 && V_144 [ 2 ] != 0x738c ) {
V_182 = - V_167 ;
V_255 = L_76 ;
goto V_265;
}
if ( V_144 [ 2 ] == 0x37c8 )
goto V_261;
}
if ( ( V_43 & V_274 ) && V_183 == V_139 ) {
if ( F_97 ( V_144 ) < 4 || ! F_43 ( V_144 ) ) {
V_159 = F_98 ( V_15 , V_144 [ 3 ] , V_144 [ 6 ] ) ;
if ( V_159 ) {
V_182 = - V_167 ;
V_255 = L_77 ;
goto V_265;
}
V_43 &= ~ V_274 ;
goto V_261;
}
}
* V_254 = V_183 ;
return 0 ;
V_265:
if ( F_81 ( V_5 ) )
F_17 ( V_15 , V_104 , L_78
L_79 , V_255 , V_159 ) ;
return V_182 ;
}
static int F_99 ( struct V_14 * V_15 )
{
struct V_2 * V_275 = F_9 ( V_15 ) ;
T_1 V_276 , V_277 ;
if ( ! F_100 ( V_275 ) )
return 0 ;
if ( V_15 -> V_49 & V_278 )
V_276 = 1 ;
else
return 0 ;
V_277 = ( 1 << V_276 ) - 1 ;
if ( V_275 -> V_279 <= V_277 )
return 0 ;
V_275 -> V_279 = V_277 ;
if ( V_275 -> V_280 > V_276 ) {
F_17 ( V_15 , V_186 ,
L_80 ,
F_37 ( V_276 ) ) ;
return - V_281 ;
}
return 0 ;
}
static inline T_2 F_101 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
if ( F_102 ( V_15 ) & V_282 )
return 0 ;
return ( ( V_5 -> V_33 == V_283 ) && ( ! F_103 ( V_15 -> V_144 ) ) ) ;
}
static int F_104 ( struct V_14 * V_15 ,
char * V_284 , T_5 V_285 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
int V_286 = 0 , V_287 = F_105 ( V_15 -> V_144 ) ;
unsigned int V_159 ;
char * V_288 = L_74 ;
if ( ! F_106 ( V_15 -> V_144 ) ) {
V_284 [ 0 ] = '\0' ;
return 0 ;
}
if ( V_15 -> V_49 & V_289 ) {
snprintf ( V_284 , V_285 , L_81 ) ;
return 0 ;
}
if ( V_5 -> V_43 & V_290 ) {
V_286 = F_107 ( V_5 -> V_291 -> V_292 , V_293 - 1 ) ;
V_15 -> V_43 |= V_294 ;
}
if ( ! ( V_15 -> V_49 & V_295 ) &&
( V_5 -> V_43 & V_296 ) &&
F_108 ( V_15 -> V_144 ) ) {
V_159 = F_96 ( V_15 , V_297 ,
V_298 ) ;
if ( V_159 ) {
F_17 ( V_15 , V_187 , L_82
L_83 , V_159 ) ;
if ( V_159 != V_164 ) {
V_15 -> V_49 |= V_295 ;
return - V_167 ;
}
} else
V_288 = L_84 ;
}
if ( V_286 >= V_287 )
snprintf ( V_284 , V_285 , L_85 , V_287 , V_288 ) ;
else
snprintf ( V_284 , V_285 , L_86 , V_286 ,
V_287 , V_288 ) ;
return 0 ;
}
int F_109 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_173 * V_174 = & V_15 -> V_3 -> V_175 ;
int V_176 = V_174 -> V_25 . V_43 & V_177 ;
const T_4 * V_144 = V_15 -> V_144 ;
unsigned long V_48 ;
char V_299 [ 7 ] ;
char V_300 [ V_301 + 1 ] ;
char V_302 [ V_303 + 1 ] ;
int V_182 ;
if ( ! F_8 ( V_15 ) && F_110 ( V_5 ) ) {
F_17 ( V_15 , V_186 , L_87 ,
V_260 ) ;
return 0 ;
}
if ( F_111 ( V_5 ) )
F_17 ( V_15 , V_259 , L_65 , V_260 ) ;
V_15 -> V_49 |= F_102 ( V_15 ) ;
F_18 ( V_15 ) ;
if ( V_15 -> V_49 & V_304 ) {
F_17 ( V_15 , V_186 ,
L_88 ) ;
F_112 ( V_15 ) ;
return 0 ;
}
if ( ( ! V_305 || ( V_5 -> V_43 & V_306 ) ) &&
V_15 -> V_183 == V_140 ) {
F_17 ( V_15 , V_104 ,
L_89 ,
V_305 ? L_90
: L_91 ) ;
F_112 ( V_15 ) ;
return 0 ;
}
V_182 = F_99 ( V_15 ) ;
if ( V_182 )
return V_182 ;
V_182 = F_113 ( V_15 ) ;
if ( V_182 )
return V_182 ;
V_182 = F_54 ( V_15 ) ;
if ( V_182 )
return V_182 ;
if ( F_111 ( V_5 ) )
F_17 ( V_15 , V_259 ,
L_92
L_93 ,
V_260 ,
V_144 [ 49 ] , V_144 [ 82 ] , V_144 [ 83 ] , V_144 [ 84 ] ,
V_144 [ 85 ] , V_144 [ 86 ] , V_144 [ 87 ] , V_144 [ 88 ] ) ;
V_15 -> V_43 &= ~ V_307 ;
V_15 -> V_158 = 0 ;
V_15 -> V_308 = 0 ;
V_15 -> V_309 = 0 ;
V_15 -> V_310 = 0 ;
V_15 -> V_105 = 0 ;
V_15 -> V_106 = 0 ;
V_15 -> V_95 = 0 ;
V_48 = F_58 ( V_144 ) ;
if ( F_111 ( V_5 ) )
F_57 ( V_144 ) ;
F_40 ( V_15 -> V_144 , V_300 , V_311 ,
sizeof( V_300 ) ) ;
F_40 ( V_15 -> V_144 , V_302 , V_312 ,
sizeof( V_302 ) ) ;
if ( V_15 -> V_183 == V_139 ) {
if ( F_59 ( V_144 ) ) {
if ( V_144 [ V_313 ] & 1 )
F_17 ( V_15 , V_104 ,
L_94
L_95 ) ;
snprintf ( V_299 , 7 , L_96 ) ;
} else {
snprintf ( V_299 , 7 , L_97 , F_97 ( V_144 ) ) ;
if ( F_114 ( V_144 ) )
F_17 ( V_15 , V_104 ,
L_94
L_95 ) ;
}
V_15 -> V_309 = F_42 ( V_144 ) ;
if ( ( V_15 -> V_144 [ 47 ] >> 8 ) == 0x80 && ( V_15 -> V_144 [ 59 ] & 0x100 ) ) {
unsigned int V_314 = V_15 -> V_144 [ 47 ] & 0xff ;
unsigned int V_315 = V_15 -> V_144 [ 59 ] & 0xff ;
if ( F_115 ( V_314 ) && F_115 ( V_315 ) )
if ( V_315 <= V_314 )
V_15 -> V_95 = V_315 ;
}
if ( F_43 ( V_144 ) ) {
const char * V_316 ;
char V_317 [ 24 ] ;
V_316 = L_98 ;
V_15 -> V_43 |= V_117 ;
if ( F_44 ( V_144 ) ) {
V_15 -> V_43 |= V_118 ;
V_316 = L_99 ;
if ( V_15 -> V_309 >= ( 1UL << 28 ) &&
F_116 ( V_144 ) )
V_15 -> V_43 |= V_318 ;
}
V_182 = F_104 ( V_15 , V_317 , sizeof( V_317 ) ) ;
if ( V_182 )
return V_182 ;
if ( F_117 ( V_5 ) && V_176 ) {
F_17 ( V_15 , V_186 ,
L_100 ,
V_299 , V_302 , V_300 ,
F_35 ( V_48 ) ) ;
F_17 ( V_15 , V_186 ,
L_101 ,
( unsigned long long ) V_15 -> V_309 ,
V_15 -> V_95 , V_316 , V_317 ) ;
}
} else {
V_15 -> V_310 = V_144 [ 1 ] ;
V_15 -> V_105 = V_144 [ 3 ] ;
V_15 -> V_106 = V_144 [ 6 ] ;
if ( F_47 ( V_144 ) ) {
V_15 -> V_310 = V_144 [ 54 ] ;
V_15 -> V_105 = V_144 [ 55 ] ;
V_15 -> V_106 = V_144 [ 56 ] ;
}
if ( F_117 ( V_5 ) && V_176 ) {
F_17 ( V_15 , V_186 ,
L_100 ,
V_299 , V_302 , V_300 ,
F_35 ( V_48 ) ) ;
F_17 ( V_15 , V_186 ,
L_102 ,
( unsigned long long ) V_15 -> V_309 ,
V_15 -> V_95 , V_15 -> V_310 ,
V_15 -> V_105 , V_15 -> V_106 ) ;
}
}
V_15 -> V_308 = 16 ;
}
else if ( V_15 -> V_183 == V_140 ) {
const char * V_319 = L_74 ;
const char * V_320 = L_74 ;
const char * V_321 = L_74 ;
T_1 V_322 ;
V_182 = F_118 ( V_144 ) ;
if ( ( V_182 < 12 ) || ( V_182 > V_226 ) ) {
if ( F_81 ( V_5 ) )
F_17 ( V_15 , V_104 ,
L_103 ) ;
V_182 = - V_119 ;
goto V_323;
}
V_15 -> V_308 = ( unsigned int ) V_182 ;
if ( V_324 &&
( V_5 -> V_43 & V_325 ) && F_119 ( V_144 ) &&
( ! F_4 ( V_5 ) ||
F_120 ( & V_5 -> V_3 , V_326 , & V_322 ) == 0 ) ) {
unsigned int V_159 ;
V_159 = F_96 ( V_15 ,
V_297 , V_327 ) ;
if ( V_159 )
F_17 ( V_15 , V_187 ,
L_104
L_105 , V_159 ) ;
else {
V_15 -> V_43 |= V_328 ;
V_320 = L_106 ;
}
}
if ( F_121 ( V_15 -> V_144 ) ) {
V_15 -> V_43 |= V_329 ;
V_319 = L_107 ;
}
if ( V_330 || F_122 ( V_15 -> V_144 ) ) {
V_15 -> V_43 |= V_331 ;
V_321 = L_108 ;
}
if ( F_117 ( V_5 ) && V_176 )
F_17 ( V_15 , V_186 ,
L_109 ,
V_302 , V_300 ,
F_35 ( V_48 ) ,
V_319 , V_320 ,
V_321 ) ;
}
V_15 -> V_158 = V_332 ;
if ( V_15 -> V_43 & V_118 )
V_15 -> V_158 = V_333 ;
if ( F_101 ( V_15 ) ) {
if ( F_117 ( V_5 ) && V_176 )
F_17 ( V_15 , V_186 ,
L_110 ) ;
V_15 -> V_47 &= V_334 ;
V_15 -> V_158 = V_332 ;
}
if ( ( V_15 -> V_183 == V_140 ) &&
( F_123 ( V_144 ) == V_335 ) ) {
V_15 -> V_158 = V_336 ;
V_15 -> V_49 |= V_337 ;
}
if ( V_15 -> V_49 & V_338 )
V_15 -> V_158 = F_124 (unsigned int, ATA_MAX_SECTORS_128,
dev->max_sectors) ;
if ( V_5 -> V_217 -> V_339 )
V_5 -> V_217 -> V_339 ( V_15 ) ;
if ( V_15 -> V_49 & V_340 ) {
if ( V_176 ) {
F_17 ( V_15 , V_104 ,
L_111 ) ;
F_17 ( V_15 , V_104 ,
L_112 ) ;
}
}
if ( ( V_15 -> V_49 & V_341 ) && V_176 ) {
F_17 ( V_15 , V_104 , L_113
L_114 ) ;
F_17 ( V_15 , V_104 , L_115
L_116 ) ;
}
return 0 ;
V_323:
if ( F_111 ( V_5 ) )
F_17 ( V_15 , V_259 ,
L_117 , V_260 ) ;
return V_182 ;
}
int F_125 ( struct V_4 * V_5 )
{
return V_342 ;
}
int F_126 ( struct V_4 * V_5 )
{
return V_343 ;
}
int F_127 ( struct V_4 * V_5 )
{
return V_344 ;
}
int F_128 ( struct V_4 * V_5 )
{
return V_345 ;
}
int F_129 ( struct V_4 * V_5 )
{
return V_283 ;
}
int F_130 ( struct V_4 * V_5 )
{
unsigned int V_346 [ V_347 ] ;
int V_348 [ V_347 ] ;
int V_182 ;
struct V_14 * V_15 ;
F_131 (dev, &ap->link, ALL)
V_348 [ V_15 -> V_24 ] = V_349 ;
V_261:
F_131 (dev, &ap->link, ALL) {
V_15 -> V_247 = V_350 ;
if ( V_5 -> V_217 -> V_351 )
V_5 -> V_217 -> V_351 ( V_5 , V_15 ) ;
}
V_5 -> V_217 -> V_352 ( V_5 ) ;
F_131 (dev, &ap->link, ALL) {
if ( V_15 -> V_183 != V_143 )
V_346 [ V_15 -> V_24 ] = V_15 -> V_183 ;
else
V_346 [ V_15 -> V_24 ] = V_353 ;
V_15 -> V_183 = V_143 ;
}
F_131 (dev, &ap->link, ALL_REVERSE) {
if ( V_348 [ V_15 -> V_24 ] )
V_15 -> V_183 = V_346 [ V_15 -> V_24 ] ;
if ( ! F_8 ( V_15 ) )
continue;
V_182 = F_91 ( V_15 , & V_15 -> V_183 , V_274 ,
V_15 -> V_144 ) ;
if ( V_182 )
goto V_354;
}
if ( V_5 -> V_217 -> V_355 )
V_5 -> V_33 = V_5 -> V_217 -> V_355 ( V_5 ) ;
F_131 (dev, &ap->link, ENABLED)
if ( F_103 ( V_15 -> V_144 ) )
V_5 -> V_33 = V_283 ;
F_131 (dev, &ap->link, ENABLED) {
V_5 -> V_3 . V_175 . V_25 . V_43 |= V_177 ;
V_182 = F_109 ( V_15 ) ;
V_5 -> V_3 . V_175 . V_25 . V_43 &= ~ V_177 ;
if ( V_182 )
goto V_354;
}
V_182 = F_132 ( & V_5 -> V_3 , & V_15 ) ;
if ( V_182 )
goto V_354;
F_131 (dev, &ap->link, ENABLED)
return 0 ;
return - V_264 ;
V_354:
V_348 [ V_15 -> V_24 ] -- ;
switch ( V_182 ) {
case - V_119 :
V_348 [ V_15 -> V_24 ] = 0 ;
break;
case - V_264 :
V_348 [ V_15 -> V_24 ] = F_107 ( V_348 [ V_15 -> V_24 ] , 1 ) ;
case - V_167 :
if ( V_348 [ V_15 -> V_24 ] == 1 ) {
F_133 ( & V_5 -> V_3 , 0 ) ;
F_134 ( V_15 , V_356 ) ;
}
}
if ( ! V_348 [ V_15 -> V_24 ] )
F_112 ( V_15 ) ;
goto V_261;
}
static void F_135 ( struct V_2 * V_3 )
{
T_1 V_1 , V_357 , V_358 ;
if ( F_120 ( V_3 , V_359 , & V_1 ) )
return;
F_120 ( V_3 , V_360 , & V_357 ) ;
if ( F_136 ( V_3 ) ) {
V_358 = ( V_1 >> 4 ) & 0xf ;
F_14 ( V_3 , V_186 ,
L_118 ,
F_37 ( V_358 ) , V_1 , V_357 ) ;
} else {
F_14 ( V_3 , V_186 ,
L_119 ,
V_1 , V_357 ) ;
}
}
struct V_14 * F_137 ( struct V_14 * V_244 )
{
struct V_2 * V_3 = V_244 -> V_3 ;
struct V_14 * V_361 = & V_3 -> V_21 [ 1 - V_244 -> V_24 ] ;
if ( ! F_8 ( V_361 ) )
return NULL ;
return V_361 ;
}
int F_133 ( struct V_2 * V_3 , T_1 V_40 )
{
T_1 V_1 , V_137 , V_362 ;
int V_182 , V_363 ;
if ( ! F_100 ( V_3 ) )
return - V_364 ;
V_182 = F_120 ( V_3 , V_359 , & V_1 ) ;
if ( V_182 == 0 && F_1 ( V_1 ) )
V_137 = ( V_1 >> 4 ) & 0xf ;
else
V_137 = V_3 -> V_280 ;
V_362 = V_3 -> V_279 ;
if ( V_362 <= 1 )
return - V_119 ;
V_363 = F_32 ( V_362 ) - 1 ;
V_362 &= ~ ( 1 << V_363 ) ;
if ( V_137 > 1 )
V_362 &= ( 1 << ( V_137 - 1 ) ) - 1 ;
else
V_362 &= 1 ;
if ( ! V_362 )
return - V_119 ;
if ( V_40 ) {
if ( V_362 & ( ( 1 << V_40 ) - 1 ) )
V_362 &= ( 1 << V_40 ) - 1 ;
else {
V_363 = F_138 ( V_362 ) - 1 ;
V_362 = 1 << V_363 ;
}
}
V_3 -> V_279 = V_362 ;
F_14 ( V_3 , V_104 , L_120 ,
F_37 ( F_32 ( V_362 ) ) ) ;
return 0 ;
}
static int F_139 ( struct V_2 * V_3 , T_1 * V_357 )
{
struct V_2 * V_365 = & V_3 -> V_5 -> V_3 ;
T_1 V_366 , V_276 , V_137 ;
V_366 = V_3 -> V_279 ;
if ( ! F_13 ( V_3 ) && V_365 -> V_280 )
V_366 &= ( 1 << V_365 -> V_280 ) - 1 ;
if ( V_366 == V_367 )
V_276 = 0 ;
else
V_276 = F_32 ( V_366 ) ;
V_137 = ( * V_357 >> 4 ) & 0xf ;
* V_357 = ( * V_357 & ~ 0xf0 ) | ( ( V_276 & 0xf ) << 4 ) ;
return V_137 != V_276 ;
}
static int F_140 ( struct V_2 * V_3 )
{
T_1 V_357 ;
if ( F_120 ( V_3 , V_360 , & V_357 ) )
return 1 ;
return F_139 ( V_3 , & V_357 ) ;
}
int F_141 ( struct V_2 * V_3 )
{
T_1 V_357 ;
int V_182 ;
if ( ( V_182 = F_120 ( V_3 , V_360 , & V_357 ) ) )
return V_182 ;
if ( ! F_139 ( V_3 , & V_357 ) )
return 0 ;
if ( ( V_182 = F_142 ( V_3 , V_360 , V_357 ) ) )
return V_182 ;
return 1 ;
}
static void F_143 ( const struct V_368 * V_369 , struct V_368 * V_370 , int V_371 , int V_372 )
{
V_370 -> V_373 = F_144 ( V_369 -> V_373 * 1000 , V_371 ) ;
V_370 -> V_374 = F_144 ( V_369 -> V_374 * 1000 , V_371 ) ;
V_370 -> V_375 = F_144 ( V_369 -> V_375 * 1000 , V_371 ) ;
V_370 -> V_376 = F_144 ( V_369 -> V_376 * 1000 , V_371 ) ;
V_370 -> V_377 = F_144 ( V_369 -> V_377 * 1000 , V_371 ) ;
V_370 -> V_378 = F_144 ( V_369 -> V_378 * 1000 , V_371 ) ;
V_370 -> V_379 = F_144 ( V_369 -> V_379 * 1000 , V_371 ) ;
V_370 -> V_380 = F_144 ( V_369 -> V_380 * 1000 , V_371 ) ;
V_370 -> V_381 = F_144 ( V_369 -> V_381 * 1000 , V_372 ) ;
}
void F_145 ( const struct V_368 * V_382 , const struct V_368 * V_383 ,
struct V_368 * V_384 , unsigned int V_385 )
{
if ( V_385 & V_386 ) V_384 -> V_373 = V_314 ( V_382 -> V_373 , V_383 -> V_373 ) ;
if ( V_385 & V_387 ) V_384 -> V_374 = V_314 ( V_382 -> V_374 , V_383 -> V_374 ) ;
if ( V_385 & V_388 ) V_384 -> V_375 = V_314 ( V_382 -> V_375 , V_383 -> V_375 ) ;
if ( V_385 & V_389 ) V_384 -> V_376 = V_314 ( V_382 -> V_376 , V_383 -> V_376 ) ;
if ( V_385 & V_390 ) V_384 -> V_377 = V_314 ( V_382 -> V_377 , V_383 -> V_377 ) ;
if ( V_385 & V_391 ) V_384 -> V_378 = V_314 ( V_382 -> V_378 , V_383 -> V_378 ) ;
if ( V_385 & V_392 ) V_384 -> V_379 = V_314 ( V_382 -> V_379 , V_383 -> V_379 ) ;
if ( V_385 & V_393 ) V_384 -> V_380 = V_314 ( V_382 -> V_380 , V_383 -> V_380 ) ;
if ( V_385 & V_394 ) V_384 -> V_381 = V_314 ( V_382 -> V_381 , V_383 -> V_381 ) ;
}
const struct V_368 * F_146 ( T_2 V_135 )
{
const struct V_368 * V_369 = V_368 ;
while ( V_135 > V_369 -> V_7 )
V_369 ++ ;
if ( V_135 == V_369 -> V_7 )
return V_369 ;
return NULL ;
}
int F_147 ( struct V_14 * V_244 , unsigned short V_395 ,
struct V_368 * V_369 , int V_371 , int V_372 )
{
const T_4 * V_144 = V_244 -> V_144 ;
const struct V_368 * V_145 ;
struct V_368 V_149 ;
if ( ! ( V_145 = F_146 ( V_395 ) ) )
return - V_119 ;
memcpy ( V_369 , V_145 , sizeof( * V_145 ) ) ;
if ( V_144 [ V_188 ] & 2 ) {
memset ( & V_149 , 0 , sizeof( V_149 ) ) ;
if ( V_395 >= V_350 && V_395 <= V_396 ) {
if ( V_395 <= V_250 )
V_149 . V_380 = V_149 . V_376 = V_144 [ V_251 ] ;
else if ( ( V_395 <= V_397 ) ||
( V_395 == V_248 && ! F_59 ( V_144 ) ) )
V_149 . V_380 = V_149 . V_376 = V_144 [ V_398 ] ;
} else if ( V_395 >= V_399 && V_395 <= V_400 )
V_149 . V_380 = V_144 [ V_401 ] ;
F_145 ( & V_149 , V_369 , V_369 , V_393 | V_389 ) ;
}
F_143 ( V_369 , V_369 , V_371 , V_372 ) ;
if ( V_395 > V_249 ) {
F_147 ( V_244 , V_244 -> V_247 , & V_149 , V_371 , V_372 ) ;
F_145 ( & V_149 , V_369 , V_369 , V_402 ) ;
}
if ( V_369 -> V_374 + V_369 -> V_375 < V_369 -> V_376 ) {
V_369 -> V_374 += ( V_369 -> V_376 - ( V_369 -> V_374 + V_369 -> V_375 ) ) / 2 ;
V_369 -> V_375 = V_369 -> V_376 - V_369 -> V_374 ;
}
if ( V_369 -> V_377 + V_369 -> V_378 < V_369 -> V_380 ) {
V_369 -> V_377 += ( V_369 -> V_380 - ( V_369 -> V_377 + V_369 -> V_378 ) ) / 2 ;
V_369 -> V_378 = V_369 -> V_380 - V_369 -> V_377 ;
}
if ( V_369 -> V_377 + V_369 -> V_378 > V_369 -> V_380 )
V_369 -> V_380 = V_369 -> V_377 + V_369 -> V_378 ;
return 0 ;
}
T_2 F_148 ( unsigned int V_403 , int V_380 )
{
T_2 V_404 = 0xff , V_405 = 0xff ;
const struct V_129 * V_130 ;
const struct V_368 * V_369 ;
for ( V_130 = V_131 ; V_130 -> V_132 >= 0 ; V_130 ++ )
if ( V_130 -> V_132 == V_403 )
V_404 = V_130 -> V_134 ;
for ( V_369 = F_146 ( V_404 ) ;
V_369 && F_34 ( V_369 -> V_7 ) == V_403 ; V_369 ++ ) {
unsigned short V_406 ;
switch ( V_403 ) {
case V_122 :
case V_124 :
V_406 = V_369 -> V_380 ;
break;
case V_126 :
V_406 = V_369 -> V_381 ;
break;
default:
return 0xff ;
}
if ( V_380 > V_406 )
break;
V_405 = V_369 -> V_7 ;
}
return V_405 ;
}
int F_134 ( struct V_14 * V_15 , unsigned int V_407 )
{
char V_242 [ 32 ] ;
unsigned long V_408 , V_48 ;
unsigned long V_45 , V_46 , V_47 ;
int V_409 , V_128 ;
V_409 = ! ! ( V_407 & V_410 ) ;
V_407 &= ~ V_410 ;
V_48 = V_408 = F_30 ( V_15 -> V_45 ,
V_15 -> V_46 ,
V_15 -> V_47 ) ;
F_16 ( V_48 , & V_45 , & V_46 , & V_47 ) ;
switch ( V_407 ) {
case V_356 :
V_128 = F_32 ( V_45 ) - 1 ;
V_45 &= ~ ( 1 << V_128 ) ;
break;
case V_411 :
if ( V_47 ) {
V_128 = F_32 ( V_47 ) - 1 ;
V_47 &= ~ ( 1 << V_128 ) ;
if ( ! V_47 )
return - V_269 ;
} else if ( V_46 ) {
V_128 = F_32 ( V_46 ) - 1 ;
V_46 &= ~ ( 1 << V_128 ) ;
if ( ! V_46 )
return - V_269 ;
}
break;
case V_412 :
V_47 &= V_413 ;
break;
case V_414 :
V_45 &= 1 ;
case V_415 :
V_46 = 0 ;
V_47 = 0 ;
break;
default:
F_67 () ;
}
V_48 &= F_30 ( V_45 , V_46 , V_47 ) ;
if ( ! ( V_48 & V_123 ) || V_48 == V_408 )
return - V_269 ;
if ( ! V_409 ) {
if ( V_48 & ( V_125 | V_127 ) )
snprintf ( V_242 , sizeof( V_242 ) , L_121 ,
F_35 ( V_48 ) ,
F_35 ( V_48 & V_123 ) ) ;
else
snprintf ( V_242 , sizeof( V_242 ) , L_122 ,
F_35 ( V_48 ) ) ;
F_17 ( V_15 , V_104 ,
L_123 , V_242 ) ;
}
F_16 ( V_48 , & V_15 -> V_45 , & V_15 -> V_46 ,
& V_15 -> V_47 ) ;
return 0 ;
}
static int F_149 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_173 * V_174 = & V_15 -> V_3 -> V_175 ;
const bool V_416 = V_15 -> V_49 & V_417 ;
const char * V_418 = L_74 ;
int V_419 = 0 ;
unsigned int V_159 = 0 ;
int V_182 ;
V_15 -> V_43 &= ~ V_92 ;
if ( V_15 -> V_403 == V_122 )
V_15 -> V_43 |= V_92 ;
if ( V_416 && V_5 -> V_43 & V_420 && F_103 ( V_15 -> V_144 ) )
V_418 = L_124 ;
else {
if ( V_416 )
F_17 ( V_15 , V_104 ,
L_125
L_126 ) ;
V_159 = F_150 ( V_15 ) ;
}
if ( V_159 & ~ V_164 )
goto V_354;
V_174 -> V_25 . V_43 |= V_421 ;
V_182 = F_151 ( V_15 , V_143 , 0 ) ;
V_174 -> V_25 . V_43 &= ~ V_421 ;
if ( V_182 )
return V_182 ;
if ( V_15 -> V_403 == V_122 ) {
if ( F_59 ( V_15 -> V_144 ) )
V_419 = 1 ;
if ( F_97 ( V_15 -> V_144 ) == 0 &&
V_15 -> V_247 <= V_250 )
V_419 = 1 ;
if ( ! F_88 ( V_15 -> V_144 ) && V_15 -> V_247 <= V_250 )
V_419 = 1 ;
}
if ( V_15 -> V_403 == V_124 &&
V_15 -> V_422 == V_399 &&
( V_15 -> V_144 [ 63 ] >> 8 ) & 1 )
V_419 = 1 ;
if ( V_15 -> V_135 == F_31 ( F_58 ( V_15 -> V_144 ) ) )
V_419 = 1 ;
if ( V_159 & V_164 ) {
if ( ! V_419 )
goto V_354;
else
V_418 = L_127 ;
}
F_29 ( L_128 ,
V_15 -> V_403 , ( int ) V_15 -> V_135 ) ;
F_17 ( V_15 , V_186 , L_129 ,
F_35 ( F_33 ( V_15 -> V_135 ) ) ,
V_418 ) ;
return 0 ;
V_354:
F_17 ( V_15 , V_187 , L_130
L_105 , V_159 ) ;
return - V_167 ;
}
int F_152 ( struct V_2 * V_3 , struct V_14 * * V_423 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_14 * V_15 ;
int V_182 = 0 , V_424 = 0 , V_425 = 0 ;
F_131 (dev, link, ENABLED) {
unsigned long V_45 , V_426 ;
unsigned int V_427 ;
V_427 = V_428 ;
if ( V_15 -> V_183 == V_140 )
V_427 = V_429 ;
else if ( F_59 ( V_15 -> V_144 ) )
V_427 = V_430 ;
F_153 ( V_15 ) ;
F_15 ( V_15 ) ;
V_45 = F_30 ( V_15 -> V_45 , 0 , 0 ) ;
V_426 = F_30 ( 0 , V_15 -> V_46 , V_15 -> V_47 ) ;
if ( V_431 & V_427 )
V_426 = F_30 ( 0 , V_15 -> V_46 , V_15 -> V_47 ) ;
else
V_426 = 0 ;
V_15 -> V_247 = F_31 ( V_45 ) ;
V_15 -> V_422 = F_31 ( V_426 ) ;
V_425 = 1 ;
if ( F_154 ( V_15 ) )
V_424 = 1 ;
}
if ( ! V_425 )
goto V_432;
F_131 (dev, link, ENABLED) {
if ( V_15 -> V_247 == 0xff ) {
F_17 ( V_15 , V_104 , L_131 ) ;
V_182 = - V_119 ;
goto V_432;
}
V_15 -> V_135 = V_15 -> V_247 ;
V_15 -> V_403 = V_122 ;
if ( V_5 -> V_217 -> V_351 )
V_5 -> V_217 -> V_351 ( V_5 , V_15 ) ;
}
F_131 (dev, link, ENABLED) {
if ( ! F_154 ( V_15 ) )
continue;
V_15 -> V_135 = V_15 -> V_422 ;
V_15 -> V_403 = F_34 ( V_15 -> V_422 ) ;
if ( V_5 -> V_217 -> V_433 )
V_5 -> V_217 -> V_433 ( V_5 , V_15 ) ;
}
F_131 (dev, link, ENABLED) {
V_182 = F_149 ( V_15 ) ;
if ( V_182 )
goto V_432;
}
if ( V_424 && ( V_5 -> V_434 -> V_43 & V_435 ) )
V_5 -> V_434 -> V_436 = V_5 ;
V_432:
if ( V_182 )
* V_423 = V_15 ;
return V_182 ;
}
int F_155 ( struct V_2 * V_3 , unsigned long V_437 ,
int (* F_156)( struct V_2 * V_3 ) )
{
unsigned long V_438 = V_439 ;
unsigned long V_440 ;
int V_441 = 0 ;
if ( V_3 -> V_5 -> V_434 -> V_43 & V_442 )
V_440 = F_157 ( V_438 , V_443 ) ;
else
V_440 = F_157 ( V_438 , V_444 ) ;
F_84 ( V_3 == V_3 -> V_5 -> V_12 ) ;
if ( F_158 ( V_440 , V_437 ) )
V_440 = V_437 ;
while ( 1 ) {
unsigned long V_445 = V_439 ;
int V_446 , V_358 ;
V_446 = V_358 = F_156 ( V_3 ) ;
if ( V_446 > 0 )
return 0 ;
if ( V_446 == - V_264 ) {
if ( F_159 ( V_3 ) )
V_446 = 0 ;
else if ( ( V_3 -> V_5 -> V_43 & V_420 ) &&
! F_160 ( V_3 ) &&
F_161 ( V_445 , V_440 ) )
V_446 = 0 ;
}
if ( V_446 )
return V_446 ;
if ( F_158 ( V_445 , V_437 ) )
return - V_447 ;
if ( ! V_441 && F_158 ( V_445 , V_438 + 5 * V_448 ) &&
( V_437 - V_445 > 3 * V_448 ) ) {
F_14 ( V_3 , V_104 ,
L_132
L_133 , V_358 ) ;
V_441 = 1 ;
}
F_162 ( V_3 -> V_5 , 50 ) ;
}
}
int F_163 ( struct V_2 * V_3 , unsigned long V_437 ,
int (* F_156)( struct V_2 * V_3 ) )
{
F_162 ( V_3 -> V_5 , V_449 ) ;
return F_155 ( V_3 , V_437 , F_156 ) ;
}
int F_164 ( struct V_2 * V_3 , const unsigned long * V_450 ,
unsigned long V_437 )
{
unsigned long V_451 = V_450 [ 0 ] ;
unsigned long V_452 = V_450 [ 1 ] ;
unsigned long V_453 , V_369 ;
T_1 V_454 , V_455 ;
int V_182 ;
V_369 = F_157 ( V_439 , V_450 [ 2 ] ) ;
if ( F_161 ( V_369 , V_437 ) )
V_437 = V_369 ;
if ( ( V_182 = F_120 ( V_3 , V_359 , & V_455 ) ) )
return V_182 ;
V_455 &= 0xf ;
V_454 = V_455 ;
V_453 = V_439 ;
while ( 1 ) {
F_162 ( V_3 -> V_5 , V_451 ) ;
if ( ( V_182 = F_120 ( V_3 , V_359 , & V_455 ) ) )
return V_182 ;
V_455 &= 0xf ;
if ( V_455 == V_454 ) {
if ( V_455 == 1 && F_161 ( V_439 , V_437 ) )
continue;
if ( F_158 ( V_439 ,
F_157 ( V_453 , V_452 ) ) )
return 0 ;
continue;
}
V_454 = V_455 ;
V_453 = V_439 ;
if ( F_158 ( V_439 , V_437 ) )
return - V_456 ;
}
}
int F_165 ( struct V_2 * V_3 , const unsigned long * V_450 ,
unsigned long V_437 )
{
int V_348 = V_457 ;
T_1 V_357 , V_458 ;
int V_182 ;
if ( ( V_182 = F_120 ( V_3 , V_360 , & V_357 ) ) )
return V_182 ;
do {
V_357 = ( V_357 & 0x0f0 ) | 0x300 ;
if ( ( V_182 = F_142 ( V_3 , V_360 , V_357 ) ) )
return V_182 ;
F_162 ( V_3 -> V_5 , 200 ) ;
if ( ( V_182 = F_120 ( V_3 , V_360 , & V_357 ) ) )
return V_182 ;
} while ( ( V_357 & 0xf0f ) != 0x300 && -- V_348 );
if ( ( V_357 & 0xf0f ) != 0x300 ) {
F_14 ( V_3 , V_187 ,
L_134 ,
V_357 ) ;
return 0 ;
}
if ( V_348 < V_457 )
F_14 ( V_3 , V_104 ,
L_135 ,
V_457 - V_348 ) ;
if ( ( V_182 = F_164 ( V_3 , V_450 , V_437 ) ) )
return V_182 ;
if ( ! ( V_182 = F_120 ( V_3 , V_459 , & V_458 ) ) )
V_182 = F_142 ( V_3 , V_459 , V_458 ) ;
return V_182 != - V_119 ? V_182 : 0 ;
}
int F_166 ( struct V_2 * V_3 , enum V_460 V_461 ,
bool V_462 )
{
struct V_173 * V_174 = & V_3 -> V_175 ;
bool V_463 = false ;
T_1 V_357 ;
int V_182 ;
V_182 = F_120 ( V_3 , V_360 , & V_357 ) ;
if ( V_182 )
return V_182 ;
switch ( V_461 ) {
case V_464 :
V_357 |= ( 0x3 << 8 ) ;
if ( V_462 ) {
V_357 |= ( 0x4 << 12 ) ;
V_463 = true ;
}
break;
case V_465 :
V_357 &= ~ ( 0x1 << 8 ) ;
V_357 |= ( 0x2 << 8 ) ;
break;
case V_466 :
if ( F_167 ( V_3 ) > 0 )
V_357 &= ~ ( 0x3 << 8 ) ;
else {
V_357 &= ~ 0xf ;
V_357 |= ( 0x1 << 2 ) ;
}
break;
default:
F_84 ( 1 ) ;
}
V_182 = F_142 ( V_3 , V_360 , V_357 ) ;
if ( V_182 )
return V_182 ;
if ( V_463 )
F_168 ( 10 ) ;
V_174 -> V_25 . V_458 &= ~ V_467 ;
return F_142 ( V_3 , V_459 , V_467 ) ;
}
int F_169 ( struct V_2 * V_3 , unsigned long V_437 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_173 * V_174 = & V_3 -> V_175 ;
const unsigned long * V_468 = F_170 ( V_174 ) ;
int V_182 ;
if ( V_174 -> V_25 . V_469 & V_470 )
return 0 ;
if ( V_5 -> V_43 & V_420 ) {
V_182 = F_165 ( V_3 , V_468 , V_437 ) ;
if ( V_182 && V_182 != - V_364 )
F_14 ( V_3 , V_104 , L_136
L_137 , V_182 ) ;
}
if ( F_171 ( V_3 ) )
V_174 -> V_25 . V_469 &= ~ V_471 ;
return 0 ;
}
int F_172 ( struct V_2 * V_3 , const unsigned long * V_468 ,
unsigned long V_437 ,
bool * V_472 , int (* F_156)( struct V_2 * ) )
{
T_1 V_357 ;
int V_182 ;
F_29 ( L_138 ) ;
if ( V_472 )
* V_472 = false ;
if ( F_140 ( V_3 ) ) {
if ( ( V_182 = F_120 ( V_3 , V_360 , & V_357 ) ) )
goto V_432;
V_357 = ( V_357 & 0x0f0 ) | 0x304 ;
if ( ( V_182 = F_142 ( V_3 , V_360 , V_357 ) ) )
goto V_432;
F_141 ( V_3 ) ;
}
if ( ( V_182 = F_120 ( V_3 , V_360 , & V_357 ) ) )
goto V_432;
V_357 = ( V_357 & 0x0f0 ) | 0x301 ;
if ( ( V_182 = F_173 ( V_3 , V_360 , V_357 ) ) )
goto V_432;
F_162 ( V_3 -> V_5 , 1 ) ;
V_182 = F_165 ( V_3 , V_468 , V_437 ) ;
if ( V_182 )
goto V_432;
if ( F_171 ( V_3 ) )
goto V_432;
if ( V_472 )
* V_472 = true ;
if ( F_174 ( V_3 -> V_5 ) && F_13 ( V_3 ) ) {
if ( F_156 ) {
unsigned long V_473 ;
V_473 = F_157 ( V_439 ,
V_474 ) ;
if ( F_158 ( V_473 , V_437 ) )
V_473 = V_437 ;
F_155 ( V_3 , V_473 , F_156 ) ;
}
V_182 = - V_281 ;
goto V_432;
}
V_182 = 0 ;
if ( F_156 )
V_182 = F_155 ( V_3 , V_437 , F_156 ) ;
V_432:
if ( V_182 && V_182 != - V_281 ) {
if ( V_472 )
* V_472 = false ;
F_14 ( V_3 , V_187 ,
L_139 , V_182 ) ;
}
F_29 ( L_140 , V_182 ) ;
return V_182 ;
}
int F_175 ( struct V_2 * V_3 , unsigned int * V_183 ,
unsigned long V_437 )
{
const unsigned long * V_468 = F_170 ( & V_3 -> V_175 ) ;
bool V_472 ;
int V_182 ;
V_182 = F_172 ( V_3 , V_468 , V_437 , & V_472 , NULL ) ;
return V_472 ? - V_281 : V_182 ;
}
void F_176 ( struct V_2 * V_3 , unsigned int * V_346 )
{
T_1 V_458 ;
F_29 ( L_138 ) ;
if ( ! F_120 ( V_3 , V_459 , & V_458 ) )
F_142 ( V_3 , V_459 , V_458 ) ;
F_135 ( V_3 ) ;
F_29 ( L_141 ) ;
}
static int F_177 ( struct V_14 * V_15 , unsigned int V_475 ,
const T_4 * V_476 )
{
const T_4 * V_477 = V_15 -> V_144 ;
unsigned char V_478 [ 2 ] [ V_303 + 1 ] ;
unsigned char V_479 [ 2 ] [ V_480 + 1 ] ;
if ( V_15 -> V_183 != V_475 ) {
F_17 ( V_15 , V_186 , L_142 ,
V_15 -> V_183 , V_475 ) ;
return 0 ;
}
F_40 ( V_477 , V_478 [ 0 ] , V_312 , sizeof( V_478 [ 0 ] ) ) ;
F_40 ( V_476 , V_478 [ 1 ] , V_312 , sizeof( V_478 [ 1 ] ) ) ;
F_40 ( V_477 , V_479 [ 0 ] , V_481 , sizeof( V_479 [ 0 ] ) ) ;
F_40 ( V_476 , V_479 [ 1 ] , V_481 , sizeof( V_479 [ 1 ] ) ) ;
if ( strcmp ( V_478 [ 0 ] , V_478 [ 1 ] ) ) {
F_17 ( V_15 , V_186 , L_143
L_144 , V_478 [ 0 ] , V_478 [ 1 ] ) ;
return 0 ;
}
if ( strcmp ( V_479 [ 0 ] , V_479 [ 1 ] ) ) {
F_17 ( V_15 , V_186 , L_145
L_144 , V_479 [ 0 ] , V_479 [ 1 ] ) ;
return 0 ;
}
return 1 ;
}
int F_56 ( struct V_14 * V_15 , unsigned int V_482 )
{
unsigned int V_183 = V_15 -> V_183 ;
T_4 * V_144 = ( void * ) V_15 -> V_3 -> V_5 -> V_483 ;
int V_182 ;
V_182 = F_91 ( V_15 , & V_183 , V_482 , V_144 ) ;
if ( V_182 )
return V_182 ;
if ( ! F_177 ( V_15 , V_183 , V_144 ) )
return - V_264 ;
memcpy ( V_15 -> V_144 , V_144 , sizeof( V_144 [ 0 ] ) * V_253 ) ;
return 0 ;
}
int F_151 ( struct V_14 * V_15 , unsigned int V_475 ,
unsigned int V_482 )
{
T_3 V_309 = V_15 -> V_309 ;
T_3 V_185 = V_15 -> V_185 ;
int V_182 ;
if ( ! F_8 ( V_15 ) )
return - V_264 ;
if ( F_178 ( V_475 ) &&
V_475 != V_139 &&
V_475 != V_140 &&
V_475 != V_142 ) {
F_17 ( V_15 , V_186 , L_146 ,
V_15 -> V_183 , V_475 ) ;
V_182 = - V_264 ;
goto V_354;
}
V_182 = F_56 ( V_15 , V_482 ) ;
if ( V_182 )
goto V_354;
V_182 = F_109 ( V_15 ) ;
if ( V_182 )
goto V_354;
if ( V_15 -> V_183 != V_139 || ! V_309 ||
V_15 -> V_309 == V_309 )
return 0 ;
F_17 ( V_15 , V_104 , L_147 ,
( unsigned long long ) V_309 ,
( unsigned long long ) V_15 -> V_309 ) ;
if ( V_15 -> V_185 == V_185 &&
V_15 -> V_309 > V_309 && V_15 -> V_309 == V_185 ) {
F_17 ( V_15 , V_104 ,
L_148
L_149 ) ;
return 0 ;
}
if ( V_15 -> V_185 == V_185 &&
V_15 -> V_309 < V_309 && V_309 == V_185 &&
! ( V_15 -> V_49 & V_184 ) ) {
F_17 ( V_15 , V_104 ,
L_150
L_151 ) ;
V_15 -> V_43 |= V_180 ;
V_182 = - V_167 ;
} else
V_182 = - V_264 ;
V_15 -> V_185 = V_185 ;
V_15 -> V_309 = V_309 ;
V_354:
F_17 ( V_15 , V_187 , L_152 , V_182 ) ;
return V_182 ;
}
static int F_179 ( const char * V_484 , const char * V_485 )
{
do {
if ( * V_484 == * V_485 || * V_485 == '?' ) {
if ( ! * V_485 ++ )
return 0 ;
} else {
if ( ! * V_484 || * V_485 != '[' )
break;
while ( * ++ V_485 && * V_485 != ']' && * V_484 != * V_485 ) {
if ( * V_485 == '-' && * ( V_485 - 1 ) != '[' )
if ( * V_484 > * ( V_485 - 1 ) && * V_484 < * ( V_485 + 1 ) ) {
++ V_485 ;
break;
}
}
if ( ! * V_485 || * V_485 == ']' )
return 1 ;
while ( * V_485 && * V_485 ++ != ']' ) ;
}
} while ( * ++ V_484 && * V_485 );
if ( * V_485 == '*' ) {
if ( ! * ++ V_485 )
return 0 ;
while ( * V_484 ) {
if ( F_179 ( V_484 , V_485 ) == 0 )
return 0 ;
++ V_484 ;
}
}
if ( ! * V_484 && ! * V_485 )
return 0 ;
return 1 ;
}
static unsigned long F_102 ( const struct V_14 * V_15 )
{
unsigned char V_486 [ V_303 + 1 ] ;
unsigned char V_487 [ V_301 + 1 ] ;
const struct V_488 * V_489 = V_490 ;
F_40 ( V_15 -> V_144 , V_486 , V_312 , sizeof( V_486 ) ) ;
F_40 ( V_15 -> V_144 , V_487 , V_311 , sizeof( V_487 ) ) ;
while ( V_489 -> V_486 ) {
if ( ! F_179 ( V_486 , V_489 -> V_486 ) ) {
if ( V_489 -> V_487 == NULL )
return V_489 -> V_49 ;
if ( ! F_179 ( V_487 , V_489 -> V_487 ) )
return V_489 -> V_49 ;
}
V_489 ++ ;
}
return 0 ;
}
static int F_180 ( const struct V_14 * V_15 )
{
if ( ( V_15 -> V_3 -> V_5 -> V_43 & V_491 ) &&
( V_15 -> V_43 & V_329 ) )
return 1 ;
return ( V_15 -> V_49 & V_492 ) ? 1 : 0 ;
}
static int F_181 ( struct V_14 * V_15 )
{
if ( V_15 -> V_49 & V_493 )
return F_182 ( V_15 -> V_144 ) ;
return F_183 ( V_15 -> V_144 ) ;
}
static int F_184 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
struct V_14 * V_15 ;
if ( V_5 -> V_33 == V_342 )
return 1 ;
if ( V_5 -> V_33 == V_343 || V_5 -> V_33 == V_283 )
return 0 ;
if ( V_5 -> V_33 == V_494 )
return 0 ;
F_185 (link, ap, EDGE) {
F_131 (dev, link, ENABLED) {
if ( ! F_181 ( V_15 ) )
return 0 ;
}
}
return 1 ;
}
static void F_153 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_495 * V_434 = V_5 -> V_434 ;
unsigned long V_48 ;
V_48 = F_30 ( V_5 -> V_45 ,
V_5 -> V_46 , V_5 -> V_47 ) ;
V_48 &= F_30 ( V_15 -> V_45 ,
V_15 -> V_46 , V_15 -> V_47 ) ;
V_48 &= F_58 ( V_15 -> V_144 ) ;
if ( F_137 ( V_15 ) ) {
V_48 &= ~ ( 0x03 << ( V_122 + 5 ) ) ;
V_48 &= ~ ( 0x03 << ( V_124 + 3 ) ) ;
}
if ( F_180 ( V_15 ) ) {
V_48 &= ~ ( V_125 | V_127 ) ;
F_17 ( V_15 , V_104 ,
L_153 ) ;
}
if ( ( V_434 -> V_43 & V_435 ) &&
V_434 -> V_436 && V_434 -> V_436 != V_5 ) {
V_48 &= ~ ( V_125 | V_127 ) ;
F_17 ( V_15 , V_104 , L_154
L_155 ) ;
}
if ( V_5 -> V_43 & V_246 )
V_48 &= F_89 ( V_15 ) ;
if ( V_5 -> V_217 -> V_496 )
V_48 = V_5 -> V_217 -> V_496 ( V_15 , V_48 ) ;
if ( V_48 & ( 0xF8 << V_126 ) )
if ( F_184 ( V_5 ) ) {
F_17 ( V_15 , V_104 ,
L_156 ) ;
V_48 &= ~ ( 0xF8 << V_126 ) ;
}
F_16 ( V_48 , & V_15 -> V_45 ,
& V_15 -> V_46 , & V_15 -> V_47 ) ;
}
static unsigned int F_150 ( struct V_14 * V_15 )
{
struct V_68 V_69 ;
unsigned int V_159 ;
F_29 ( L_157 ) ;
F_51 ( V_15 , & V_69 ) ;
V_69 . V_72 = V_497 ;
V_69 . V_73 = V_498 ;
V_69 . V_43 |= V_110 | V_111 | V_266 ;
V_69 . V_93 = V_162 ;
if ( F_87 ( V_15 ) )
V_69 . V_81 = V_15 -> V_135 ;
else if ( F_88 ( V_15 -> V_144 ) )
V_69 . V_81 = 0x01 ;
else
return 0 ;
V_159 = F_52 ( V_15 , & V_69 , NULL , V_163 , NULL , 0 , 0 ) ;
F_29 ( L_158 , V_159 ) ;
return V_159 ;
}
unsigned int F_96 ( struct V_14 * V_15 , T_2 V_499 , T_2 V_73 )
{
struct V_68 V_69 ;
unsigned int V_159 ;
F_29 ( L_159 ) ;
F_51 ( V_15 , & V_69 ) ;
V_69 . V_72 = V_497 ;
V_69 . V_73 = V_499 ;
V_69 . V_43 |= V_110 | V_111 ;
V_69 . V_93 = V_162 ;
V_69 . V_81 = V_73 ;
V_159 = F_52 ( V_15 , & V_69 , NULL , V_163 , NULL , 0 , 0 ) ;
F_29 ( L_158 , V_159 ) ;
return V_159 ;
}
static unsigned int F_98 ( struct V_14 * V_15 ,
T_4 V_105 , T_4 V_106 )
{
struct V_68 V_69 ;
unsigned int V_159 ;
if ( V_106 < 1 || V_106 > 255 || V_105 < 1 || V_105 > 16 )
return V_500 ;
F_29 ( L_160 ) ;
F_51 ( V_15 , & V_69 ) ;
V_69 . V_72 = V_501 ;
V_69 . V_43 |= V_110 | V_111 ;
V_69 . V_93 = V_162 ;
V_69 . V_81 = V_106 ;
V_69 . V_21 |= ( V_105 - 1 ) & 0x0f ;
V_159 = F_52 ( V_15 , & V_69 , NULL , V_163 , NULL , 0 , 0 ) ;
if ( V_159 == V_164 && ( V_69 . V_73 & V_165 ) )
V_159 = 0 ;
F_29 ( L_158 , V_159 ) ;
return V_159 ;
}
void F_186 ( struct V_196 * V_197 )
{
struct V_4 * V_5 = V_197 -> V_5 ;
struct V_203 * V_229 = V_197 -> V_229 ;
int V_502 = V_197 -> V_202 ;
F_187 ( V_229 == NULL ) ;
F_188 ( L_161 , V_197 -> V_205 ) ;
if ( V_197 -> V_205 )
F_189 ( V_5 -> V_15 , V_229 , V_197 -> V_503 , V_502 ) ;
V_197 -> V_43 &= ~ V_504 ;
V_197 -> V_229 = NULL ;
}
int F_190 ( struct V_196 * V_197 )
{
struct V_4 * V_5 = V_197 -> V_5 ;
if ( ! ( V_197 -> V_15 -> V_49 & V_505 ) &&
F_5 ( V_197 -> V_231 & 15 ) )
return 1 ;
if ( V_5 -> V_217 -> V_506 )
return V_5 -> V_217 -> V_506 ( V_197 ) ;
return 0 ;
}
int F_191 ( struct V_196 * V_197 )
{
struct V_2 * V_3 = V_197 -> V_15 -> V_3 ;
if ( V_197 -> V_69 . V_93 == V_114 ) {
if ( ! F_192 ( V_3 -> V_221 ) )
return 0 ;
} else {
if ( ! F_192 ( V_3 -> V_221 ) && ! V_3 -> V_222 )
return 0 ;
}
return V_507 ;
}
void F_193 ( struct V_196 * V_197 ) { }
void F_71 ( struct V_196 * V_197 , struct V_203 * V_229 ,
unsigned int V_205 )
{
V_197 -> V_229 = V_229 ;
V_197 -> V_205 = V_205 ;
V_197 -> V_508 = V_197 -> V_229 ;
}
static int F_194 ( struct V_196 * V_197 )
{
struct V_4 * V_5 = V_197 -> V_5 ;
unsigned int V_205 ;
F_188 ( L_162 , V_5 -> V_31 ) ;
V_205 = F_195 ( V_5 -> V_15 , V_197 -> V_229 , V_197 -> V_205 , V_197 -> V_202 ) ;
if ( V_205 < 1 )
return - 1 ;
F_29 ( L_163 , V_205 ) ;
V_197 -> V_503 = V_197 -> V_205 ;
V_197 -> V_205 = V_205 ;
V_197 -> V_43 |= V_504 ;
return 0 ;
}
void F_94 ( T_4 * V_242 , unsigned int V_509 )
{
#ifdef F_196
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < V_509 ; V_25 ++ )
V_242 [ V_25 ] = F_197 ( V_242 [ V_25 ] ) ;
#endif
}
static struct V_196 * F_198 ( struct V_4 * V_5 )
{
struct V_196 * V_197 = NULL ;
unsigned int V_25 ;
if ( F_5 ( V_5 -> V_214 & V_215 ) )
return NULL ;
for ( V_25 = 0 ; V_25 < V_293 - 1 ; V_25 ++ )
if ( ! F_66 ( V_25 , & V_5 -> V_219 ) ) {
V_197 = F_68 ( V_5 , V_25 ) ;
break;
}
if ( V_197 )
V_197 -> V_109 = V_25 ;
return V_197 ;
}
struct V_196 * F_199 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_196 * V_197 ;
V_197 = F_198 ( V_5 ) ;
if ( V_197 ) {
V_197 -> V_220 = NULL ;
V_197 -> V_5 = V_5 ;
V_197 -> V_15 = V_15 ;
F_69 ( V_197 ) ;
}
return V_197 ;
}
void F_82 ( struct V_196 * V_197 )
{
struct V_4 * V_5 ;
unsigned int V_109 ;
F_187 ( V_197 == NULL ) ;
V_5 = V_197 -> V_5 ;
V_197 -> V_43 = 0 ;
V_109 = V_197 -> V_109 ;
if ( F_26 ( F_192 ( V_109 ) ) ) {
V_197 -> V_109 = V_225 ;
F_200 ( V_109 , & V_5 -> V_219 ) ;
}
}
void F_201 ( struct V_196 * V_197 )
{
struct V_4 * V_5 ;
struct V_2 * V_3 ;
F_187 ( V_197 == NULL ) ;
F_187 ( ! ( V_197 -> V_43 & V_234 ) ) ;
V_5 = V_197 -> V_5 ;
V_3 = V_197 -> V_15 -> V_3 ;
if ( F_26 ( V_197 -> V_43 & V_504 ) )
F_186 ( V_197 ) ;
if ( V_197 -> V_69 . V_93 == V_114 ) {
V_3 -> V_222 &= ~ ( 1 << V_197 -> V_109 ) ;
if ( ! V_3 -> V_222 )
V_5 -> V_224 -- ;
} else {
V_3 -> V_221 = V_225 ;
V_5 -> V_224 -- ;
}
if ( F_5 ( V_197 -> V_43 & V_510 &&
V_5 -> V_511 == V_3 ) )
V_5 -> V_511 = NULL ;
V_197 -> V_43 &= ~ V_234 ;
V_5 -> V_223 &= ~ ( 1 << V_197 -> V_109 ) ;
V_197 -> V_232 ( V_197 ) ;
}
static void F_202 ( struct V_196 * V_197 )
{
struct V_4 * V_5 = V_197 -> V_5 ;
V_197 -> V_238 . V_43 = V_197 -> V_69 . V_43 ;
V_5 -> V_217 -> V_512 ( V_197 ) ;
}
static void F_203 ( struct V_196 * V_197 )
{
struct V_14 * V_15 = V_197 -> V_15 ;
if ( F_204 ( V_197 -> V_69 . V_93 ) )
return;
if ( ( V_15 -> V_46 || V_15 -> V_47 ) && F_205 ( V_197 -> V_69 . V_93 ) )
return;
V_15 -> V_43 &= ~ V_513 ;
}
void F_80 ( struct V_196 * V_197 )
{
struct V_4 * V_5 = V_197 -> V_5 ;
if ( V_5 -> V_217 -> V_218 ) {
struct V_14 * V_15 = V_197 -> V_15 ;
struct V_514 * V_515 = & V_15 -> V_3 -> V_516 ;
if ( F_5 ( V_197 -> V_159 ) )
V_197 -> V_43 |= V_237 ;
if ( F_5 ( F_206 ( V_197 -> V_109 ) ) ) {
F_202 ( V_197 ) ;
F_201 ( V_197 ) ;
return;
}
if ( F_5 ( V_197 -> V_43 & V_237 ) ) {
F_202 ( V_197 ) ;
F_207 ( V_197 ) ;
return;
}
F_187 ( V_5 -> V_214 & V_215 ) ;
if ( V_197 -> V_43 & V_227 )
F_202 ( V_197 ) ;
switch ( V_197 -> V_69 . V_72 ) {
case V_497 :
if ( V_197 -> V_69 . V_73 != V_517 &&
V_197 -> V_69 . V_73 != V_518 )
break;
case V_501 :
case V_519 :
V_515 -> V_520 [ V_15 -> V_24 ] |= V_521 ;
F_208 ( V_5 ) ;
break;
case V_522 :
V_15 -> V_43 |= V_523 ;
break;
}
if ( F_5 ( V_15 -> V_43 & V_513 ) )
F_203 ( V_197 ) ;
F_201 ( V_197 ) ;
} else {
if ( V_197 -> V_43 & V_524 )
return;
if ( V_197 -> V_159 || V_197 -> V_43 & V_227 )
F_202 ( V_197 ) ;
F_201 ( V_197 ) ;
}
}
int F_209 ( struct V_4 * V_5 , T_1 V_223 )
{
int V_525 = 0 ;
T_1 V_526 ;
V_526 = V_5 -> V_223 ^ V_223 ;
if ( F_5 ( V_526 & V_223 ) ) {
F_11 ( V_5 , V_187 , L_164
L_165 , V_5 -> V_223 , V_223 ) ;
return - V_119 ;
}
while ( V_526 ) {
struct V_196 * V_197 ;
unsigned int V_109 = F_210 ( V_526 ) ;
V_197 = F_211 ( V_5 , V_109 ) ;
if ( V_197 ) {
F_80 ( V_197 ) ;
V_525 ++ ;
}
V_526 &= ~ ( 1 << V_109 ) ;
}
return V_525 ;
}
void F_72 ( struct V_196 * V_197 )
{
struct V_4 * V_5 = V_197 -> V_5 ;
struct V_2 * V_3 = V_197 -> V_15 -> V_3 ;
T_2 V_527 = V_197 -> V_69 . V_93 ;
F_187 ( V_5 -> V_217 -> V_218 && F_192 ( V_3 -> V_221 ) ) ;
if ( F_212 ( V_527 ) ) {
F_187 ( V_3 -> V_222 & ( 1 << V_197 -> V_109 ) ) ;
if ( ! V_3 -> V_222 )
V_5 -> V_224 ++ ;
V_3 -> V_222 |= 1 << V_197 -> V_109 ;
} else {
F_187 ( V_3 -> V_222 ) ;
V_5 -> V_224 ++ ;
V_3 -> V_221 = V_197 -> V_109 ;
}
V_197 -> V_43 |= V_234 ;
V_5 -> V_223 |= 1 << V_197 -> V_109 ;
if ( F_187 ( F_213 ( V_527 ) &&
( ! V_197 -> V_229 || ! V_197 -> V_205 || ! V_197 -> V_231 ) ) )
goto V_528;
if ( F_214 ( V_527 ) || ( F_205 ( V_527 ) &&
( V_5 -> V_43 & V_529 ) ) )
if ( F_194 ( V_197 ) )
goto V_528;
if ( F_5 ( V_197 -> V_15 -> V_43 & V_523 ) ) {
V_3 -> V_516 . V_469 |= V_530 ;
F_215 ( & V_3 -> V_516 , L_166 ) ;
F_216 ( V_3 ) ;
return;
}
V_5 -> V_217 -> V_531 ( V_197 ) ;
V_197 -> V_159 |= V_5 -> V_217 -> V_532 ( V_197 ) ;
if ( F_5 ( V_197 -> V_159 ) )
goto V_533;
return;
V_528:
V_197 -> V_159 |= V_216 ;
V_533:
F_80 ( V_197 ) ;
}
int F_100 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
return ( V_5 -> V_43 & V_420 ) && V_5 -> V_217 -> V_534 ;
}
int F_120 ( struct V_2 * V_3 , int V_535 , T_1 * V_536 )
{
if ( F_13 ( V_3 ) ) {
if ( F_100 ( V_3 ) )
return V_3 -> V_5 -> V_217 -> V_534 ( V_3 , V_535 , V_536 ) ;
return - V_364 ;
}
return F_217 ( V_3 , V_535 , V_536 ) ;
}
int F_142 ( struct V_2 * V_3 , int V_535 , T_1 V_536 )
{
if ( F_13 ( V_3 ) ) {
if ( F_100 ( V_3 ) )
return V_3 -> V_5 -> V_217 -> V_537 ( V_3 , V_535 , V_536 ) ;
return - V_364 ;
}
return F_218 ( V_3 , V_535 , V_536 ) ;
}
int F_173 ( struct V_2 * V_3 , int V_535 , T_1 V_536 )
{
if ( F_13 ( V_3 ) ) {
int V_182 ;
if ( F_100 ( V_3 ) ) {
V_182 = V_3 -> V_5 -> V_217 -> V_537 ( V_3 , V_535 , V_536 ) ;
if ( V_182 == 0 )
V_182 = V_3 -> V_5 -> V_217 -> V_534 ( V_3 , V_535 , & V_536 ) ;
return V_182 ;
}
return - V_364 ;
}
return F_218 ( V_3 , V_535 , V_536 ) ;
}
bool F_136 ( struct V_2 * V_3 )
{
T_1 V_1 ;
if ( F_120 ( V_3 , V_359 , & V_1 ) == 0 &&
F_1 ( V_1 ) )
return true ;
return false ;
}
bool F_171 ( struct V_2 * V_3 )
{
T_1 V_1 ;
if ( F_120 ( V_3 , V_359 , & V_1 ) == 0 &&
! F_1 ( V_1 ) )
return true ;
return false ;
}
bool F_159 ( struct V_2 * V_3 )
{
struct V_2 * V_538 = V_3 -> V_5 -> V_12 ;
F_84 ( V_3 == V_538 ) ;
return F_136 ( V_3 ) ||
( V_538 && F_136 ( V_538 ) ) ;
}
bool F_160 ( struct V_2 * V_3 )
{
struct V_2 * V_538 = V_3 -> V_5 -> V_12 ;
F_84 ( V_3 == V_538 ) ;
return F_171 ( V_3 ) &&
( ! V_538 || F_171 ( V_538 ) ) ;
}
static int F_219 ( struct V_495 * V_434 , T_6 V_539 ,
unsigned int V_469 , unsigned int V_540 ,
int V_212 )
{
unsigned long V_43 ;
int V_25 , V_182 ;
for ( V_25 = 0 ; V_25 < V_434 -> V_541 ; V_25 ++ ) {
struct V_4 * V_5 = V_434 -> V_542 [ V_25 ] ;
struct V_2 * V_3 ;
if ( V_5 -> V_214 & V_543 ) {
F_220 ( V_5 ) ;
F_84 ( V_5 -> V_214 & V_543 ) ;
}
F_64 ( V_5 -> V_213 , V_43 ) ;
V_5 -> V_544 = V_539 ;
if ( V_212 ) {
V_182 = 0 ;
V_5 -> V_545 = & V_182 ;
}
V_5 -> V_214 |= V_543 ;
F_185 (link, ap, HOST_FIRST) {
V_3 -> V_516 . V_469 |= V_469 ;
V_3 -> V_516 . V_43 |= V_540 ;
}
F_208 ( V_5 ) ;
F_65 ( V_5 -> V_213 , V_43 ) ;
if ( V_212 ) {
F_220 ( V_5 ) ;
F_84 ( V_5 -> V_214 & V_543 ) ;
if ( V_182 )
return V_182 ;
}
}
return 0 ;
}
int F_221 ( struct V_495 * V_434 , T_6 V_539 )
{
unsigned int V_540 = V_546 ;
int V_182 ;
if ( V_539 . V_547 == V_548 )
V_540 |= V_549 | V_550 ;
V_182 = F_219 ( V_434 , V_539 , 0 , V_540 , 1 ) ;
if ( V_182 == 0 )
V_434 -> V_15 -> V_551 . V_552 = V_539 ;
return V_182 ;
}
void F_222 ( struct V_495 * V_434 )
{
F_219 ( V_434 , V_553 , V_530 ,
V_549 | V_546 , 0 ) ;
V_434 -> V_15 -> V_551 . V_552 = V_553 ;
}
void F_223 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = F_9 ( V_15 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_43 ;
V_3 -> V_279 = V_3 -> V_41 ;
V_3 -> V_280 = 0 ;
F_64 ( V_5 -> V_213 , V_43 ) ;
V_15 -> V_43 &= ~ V_554 ;
V_15 -> V_49 = 0 ;
F_65 ( V_5 -> V_213 , V_43 ) ;
memset ( ( void * ) V_15 + V_555 , 0 ,
V_556 - V_555 ) ;
V_15 -> V_45 = V_367 ;
V_15 -> V_46 = V_367 ;
V_15 -> V_47 = V_367 ;
}
void F_224 ( struct V_4 * V_5 , struct V_2 * V_3 , int V_39 )
{
int V_25 ;
memset ( ( void * ) V_3 + V_557 , 0 ,
V_558 - V_557 ) ;
V_3 -> V_5 = V_5 ;
V_3 -> V_39 = V_39 ;
V_3 -> V_221 = V_225 ;
V_3 -> V_41 = V_367 ;
for ( V_25 = 0 ; V_25 < V_347 ; V_25 ++ ) {
struct V_14 * V_15 = & V_3 -> V_21 [ V_25 ] ;
V_15 -> V_3 = V_3 ;
V_15 -> V_24 = V_15 - V_3 -> V_21 ;
#ifdef F_225
V_15 -> V_559 = V_560 ;
#endif
F_223 ( V_15 ) ;
}
}
int F_226 ( struct V_2 * V_3 )
{
T_2 V_137 ;
int V_182 ;
V_182 = F_120 ( V_3 , V_360 , & V_3 -> V_561 ) ;
if ( V_182 )
return V_182 ;
V_137 = ( V_3 -> V_561 >> 4 ) & 0xf ;
if ( V_137 )
V_3 -> V_41 &= ( 1 << V_137 ) - 1 ;
F_12 ( V_3 ) ;
V_3 -> V_279 = V_3 -> V_41 ;
return 0 ;
}
struct V_4 * F_227 ( struct V_495 * V_434 )
{
struct V_4 * V_5 ;
F_29 ( L_138 ) ;
V_5 = F_228 ( sizeof( * V_5 ) , V_562 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_214 |= V_563 | V_215 ;
V_5 -> V_213 = & V_434 -> V_213 ;
V_5 -> V_31 = - 1 ;
V_5 -> V_434 = V_434 ;
V_5 -> V_15 = V_434 -> V_15 ;
#if F_229 ( V_564 )
V_5 -> V_565 = 0x00FF ;
#elif F_229 ( V_566 )
V_5 -> V_565 = V_567 | V_568 | V_569 | V_570 | V_571 ;
#else
V_5 -> V_565 = V_567 | V_571 | V_570 ;
#endif
F_230 ( & V_5 -> V_572 ) ;
F_231 ( & V_5 -> V_573 , V_574 ) ;
F_232 ( & V_5 -> V_575 , V_576 ) ;
F_233 ( & V_5 -> V_577 ) ;
F_234 ( & V_5 -> V_578 ) ;
F_235 ( & V_5 -> V_579 ) ;
F_236 ( & V_5 -> V_580 ) ;
V_5 -> V_580 . V_581 = V_582 ;
V_5 -> V_580 . V_583 = ( unsigned long ) V_5 ;
V_5 -> V_33 = V_34 ;
F_224 ( V_5 , & V_5 -> V_3 , 0 ) ;
#ifdef F_237
V_5 -> V_584 . V_585 = 1 ;
V_5 -> V_584 . V_586 = 1 ;
#endif
F_238 ( V_5 ) ;
return V_5 ;
}
static void F_239 ( struct V_21 * V_587 , void * V_588 )
{
struct V_495 * V_434 = F_240 ( V_587 ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_434 -> V_541 ; V_25 ++ ) {
struct V_4 * V_5 = V_434 -> V_542 [ V_25 ] ;
if ( ! V_5 )
continue;
if ( V_5 -> V_291 )
F_241 ( V_5 -> V_291 ) ;
F_242 ( V_5 -> V_11 ) ;
F_242 ( V_5 -> V_12 ) ;
F_242 ( V_5 ) ;
V_434 -> V_542 [ V_25 ] = NULL ;
}
F_243 ( V_587 , NULL ) ;
}
struct V_495 * F_244 ( struct V_21 * V_15 , int V_589 )
{
struct V_495 * V_434 ;
T_5 V_590 ;
int V_25 ;
F_29 ( L_138 ) ;
if ( ! F_245 ( V_15 , NULL , V_562 ) )
return NULL ;
V_590 = sizeof( struct V_495 ) + ( V_589 + 1 ) * sizeof( void * ) ;
V_434 = F_246 ( F_239 , V_590 , V_562 ) ;
if ( ! V_434 )
goto V_265;
F_247 ( V_15 , V_434 ) ;
F_243 ( V_15 , V_434 ) ;
F_248 ( & V_434 -> V_213 ) ;
F_230 ( & V_434 -> V_591 ) ;
V_434 -> V_15 = V_15 ;
V_434 -> V_541 = V_589 ;
for ( V_25 = 0 ; V_25 < V_589 ; V_25 ++ ) {
struct V_4 * V_5 ;
V_5 = F_227 ( V_434 ) ;
if ( ! V_5 )
goto V_265;
V_5 -> V_592 = V_25 ;
V_434 -> V_542 [ V_25 ] = V_5 ;
}
F_249 ( V_15 , NULL ) ;
return V_434 ;
V_265:
F_250 ( V_15 , NULL ) ;
return NULL ;
}
struct V_495 * F_251 ( struct V_21 * V_15 ,
const struct V_593 * const * V_594 ,
int V_541 )
{
const struct V_593 * V_595 ;
struct V_495 * V_434 ;
int V_25 , V_596 ;
V_434 = F_244 ( V_15 , V_541 ) ;
if ( ! V_434 )
return NULL ;
for ( V_25 = 0 , V_596 = 0 , V_595 = NULL ; V_25 < V_434 -> V_541 ; V_25 ++ ) {
struct V_4 * V_5 = V_434 -> V_542 [ V_25 ] ;
if ( V_594 [ V_596 ] )
V_595 = V_594 [ V_596 ++ ] ;
V_5 -> V_45 = V_595 -> V_45 ;
V_5 -> V_46 = V_595 -> V_46 ;
V_5 -> V_47 = V_595 -> V_47 ;
V_5 -> V_43 |= V_595 -> V_43 ;
V_5 -> V_3 . V_43 |= V_595 -> V_597 ;
V_5 -> V_217 = V_595 -> V_598 ;
if ( ! V_434 -> V_217 && ( V_595 -> V_598 != & V_599 ) )
V_434 -> V_217 = V_595 -> V_598 ;
}
return V_434 ;
}
int F_252 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
F_84 ( V_5 -> V_12 ) ;
F_84 ( V_5 -> V_43 & V_600 ) ;
V_3 = F_228 ( sizeof( * V_3 ) , V_562 ) ;
if ( ! V_3 )
return - V_601 ;
F_224 ( V_5 , V_3 , 1 ) ;
V_5 -> V_12 = V_3 ;
return 0 ;
}
static void F_253 ( struct V_21 * V_587 , void * V_588 )
{
struct V_495 * V_434 = F_240 ( V_587 ) ;
int V_25 ;
F_84 ( ! ( V_434 -> V_43 & V_602 ) ) ;
for ( V_25 = 0 ; V_25 < V_434 -> V_541 ; V_25 ++ ) {
struct V_4 * V_5 = V_434 -> V_542 [ V_25 ] ;
if ( V_5 -> V_217 -> V_603 )
V_5 -> V_217 -> V_603 ( V_5 ) ;
}
if ( V_434 -> V_217 -> V_604 )
V_434 -> V_217 -> V_604 ( V_434 ) ;
}
static void F_254 ( struct V_605 * V_217 )
{
static F_255 ( V_213 ) ;
const struct V_605 * V_455 ;
void * * V_606 = ( void * * ) V_217 ;
void * * V_607 = ( void * * ) & V_217 -> V_608 ;
void * * V_609 ;
if ( ! V_217 || ! V_217 -> V_608 )
return;
F_256 ( & V_213 ) ;
for ( V_455 = V_217 -> V_608 ; V_455 ; V_455 = V_455 -> V_608 ) {
void * * V_610 = ( void * * ) V_455 ;
for ( V_609 = V_606 ; V_609 < V_607 ; V_609 ++ , V_610 ++ )
if ( ! * V_609 )
* V_609 = * V_610 ;
}
for ( V_609 = V_606 ; V_609 < V_607 ; V_609 ++ )
if ( F_257 ( * V_609 ) )
* V_609 = NULL ;
V_217 -> V_608 = NULL ;
F_258 ( & V_213 ) ;
}
int F_259 ( struct V_495 * V_434 )
{
int V_611 = 0 ;
void * V_612 = NULL ;
int V_25 , V_182 ;
if ( V_434 -> V_43 & V_602 )
return 0 ;
F_254 ( V_434 -> V_217 ) ;
for ( V_25 = 0 ; V_25 < V_434 -> V_541 ; V_25 ++ ) {
struct V_4 * V_5 = V_434 -> V_542 [ V_25 ] ;
F_254 ( V_5 -> V_217 ) ;
if ( ! V_434 -> V_217 && ! F_260 ( V_5 ) )
V_434 -> V_217 = V_5 -> V_217 ;
if ( V_5 -> V_217 -> V_603 )
V_611 = 1 ;
}
if ( V_434 -> V_217 -> V_604 )
V_611 = 1 ;
if ( V_611 ) {
V_612 = F_246 ( F_253 , 0 , V_562 ) ;
if ( ! V_612 )
return - V_601 ;
}
for ( V_25 = 0 ; V_25 < V_434 -> V_541 ; V_25 ++ ) {
struct V_4 * V_5 = V_434 -> V_542 [ V_25 ] ;
if ( V_5 -> V_217 -> V_613 ) {
V_182 = V_5 -> V_217 -> V_613 ( V_5 ) ;
if ( V_182 ) {
if ( V_182 != - V_264 )
F_261 ( V_187 , V_434 -> V_15 ,
L_167
L_168 , V_25 , V_182 ) ;
goto V_265;
}
}
F_262 ( V_5 ) ;
}
if ( V_612 )
F_247 ( V_434 -> V_15 , V_612 ) ;
V_434 -> V_43 |= V_602 ;
return 0 ;
V_265:
while ( -- V_25 >= 0 ) {
struct V_4 * V_5 = V_434 -> V_542 [ V_25 ] ;
if ( V_5 -> V_217 -> V_603 )
V_5 -> V_217 -> V_603 ( V_5 ) ;
}
F_263 ( V_612 ) ;
return V_182 ;
}
void F_264 ( struct V_495 * V_434 , struct V_21 * V_15 ,
unsigned long V_43 , struct V_605 * V_217 )
{
F_248 ( & V_434 -> V_213 ) ;
F_230 ( & V_434 -> V_591 ) ;
V_434 -> V_15 = V_15 ;
V_434 -> V_43 = V_43 ;
V_434 -> V_217 = V_217 ;
}
int F_265 ( struct V_4 * V_5 )
{
int V_182 = 0 ;
if ( V_5 -> V_217 -> V_218 ) {
struct V_514 * V_515 = & V_5 -> V_3 . V_516 ;
unsigned long V_43 ;
F_64 ( V_5 -> V_213 , V_43 ) ;
V_515 -> V_614 |= V_615 ;
V_515 -> V_469 |= V_530 ;
V_515 -> V_43 |= V_549 | V_546 ;
V_5 -> V_214 &= ~ V_563 ;
V_5 -> V_214 |= V_616 ;
F_208 ( V_5 ) ;
F_65 ( V_5 -> V_213 , V_43 ) ;
F_220 ( V_5 ) ;
} else {
F_29 ( L_169 , V_5 -> V_31 ) ;
V_182 = F_130 ( V_5 ) ;
F_29 ( L_170 , V_5 -> V_31 ) ;
}
return V_182 ;
}
static void F_266 ( void * V_583 , T_7 V_617 )
{
struct V_4 * V_5 = V_583 ;
if ( ! ( V_5 -> V_434 -> V_43 & V_442 ) && V_5 -> V_592 != 0 )
F_267 ( V_617 ) ;
( void ) F_265 ( V_5 ) ;
F_267 ( V_617 ) ;
F_268 ( V_5 , 1 ) ;
}
int F_269 ( struct V_495 * V_434 , struct V_618 * V_619 )
{
int V_25 , V_182 ;
if ( ! ( V_434 -> V_43 & V_602 ) ) {
F_261 ( V_187 , V_434 -> V_15 ,
L_171 ) ;
F_84 ( 1 ) ;
return - V_119 ;
}
for ( V_25 = V_434 -> V_541 ; V_434 -> V_542 [ V_25 ] ; V_25 ++ )
F_242 ( V_434 -> V_542 [ V_25 ] ) ;
for ( V_25 = 0 ; V_25 < V_434 -> V_541 ; V_25 ++ )
V_434 -> V_542 [ V_25 ] -> V_31 = V_620 ++ ;
for ( V_25 = 0 ; V_25 < V_434 -> V_541 ; V_25 ++ ) {
V_182 = F_270 ( V_434 -> V_15 , V_434 -> V_542 [ V_25 ] ) ;
if ( V_182 ) {
goto V_621;
}
}
V_182 = F_271 ( V_434 , V_619 ) ;
if ( V_182 )
goto V_621;
F_272 ( V_434 ) ;
for ( V_25 = 0 ; V_25 < V_434 -> V_541 ; V_25 ++ ) {
struct V_4 * V_5 = V_434 -> V_542 [ V_25 ] ;
unsigned long V_48 ;
if ( V_5 -> V_33 == V_34 && ( V_5 -> V_43 & V_420 ) )
V_5 -> V_33 = V_283 ;
F_226 ( & V_5 -> V_3 ) ;
if ( V_5 -> V_12 )
F_226 ( V_5 -> V_12 ) ;
V_48 = F_30 ( V_5 -> V_45 , V_5 -> V_46 ,
V_5 -> V_47 ) ;
if ( ! F_260 ( V_5 ) ) {
F_11 ( V_5 , V_186 ,
L_172 ,
( V_5 -> V_43 & V_420 ) ? 'S' : 'P' ,
F_35 ( V_48 ) ,
V_5 -> V_3 . V_516 . V_284 ) ;
F_273 ( & V_5 -> V_3 . V_516 ) ;
} else
F_11 ( V_5 , V_186 , L_173 ) ;
}
for ( V_25 = 0 ; V_25 < V_434 -> V_541 ; V_25 ++ ) {
struct V_4 * V_5 = V_434 -> V_542 [ V_25 ] ;
F_274 ( F_266 , V_5 ) ;
}
return 0 ;
V_621:
while ( -- V_25 >= 0 ) {
F_275 ( V_434 -> V_542 [ V_25 ] ) ;
}
return V_182 ;
}
int F_276 ( struct V_495 * V_434 , int V_622 ,
T_8 V_623 , unsigned long V_624 ,
struct V_618 * V_619 )
{
int V_25 , V_182 ;
V_182 = F_259 ( V_434 ) ;
if ( V_182 )
return V_182 ;
if ( ! V_622 ) {
F_84 ( V_623 ) ;
return F_269 ( V_434 , V_619 ) ;
}
V_182 = F_277 ( V_434 -> V_15 , V_622 , V_623 , V_624 ,
F_278 ( V_434 -> V_15 ) , V_434 ) ;
if ( V_182 )
return V_182 ;
for ( V_25 = 0 ; V_25 < V_434 -> V_541 ; V_25 ++ )
F_279 ( V_434 -> V_542 [ V_25 ] , L_174 , V_622 ) ;
V_182 = F_269 ( V_434 , V_619 ) ;
if ( V_182 )
F_280 ( V_434 -> V_15 , V_622 , V_434 ) ;
return V_182 ;
}
static void F_281 ( struct V_4 * V_5 )
{
unsigned long V_43 ;
if ( ! V_5 -> V_217 -> V_218 )
goto V_625;
F_64 ( V_5 -> V_213 , V_43 ) ;
V_5 -> V_214 |= V_626 ;
F_208 ( V_5 ) ;
F_65 ( V_5 -> V_213 , V_43 ) ;
F_220 ( V_5 ) ;
F_84 ( ! ( V_5 -> V_214 & V_627 ) ) ;
F_282 ( & V_5 -> V_573 ) ;
V_625:
if ( V_5 -> V_11 ) {
int V_25 ;
for ( V_25 = 0 ; V_25 < V_628 ; V_25 ++ )
F_283 ( & V_5 -> V_11 [ V_25 ] ) ;
}
F_275 ( V_5 ) ;
F_284 ( V_5 -> V_291 ) ;
}
void F_285 ( struct V_495 * V_434 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_434 -> V_541 ; V_25 ++ )
F_281 ( V_434 -> V_542 [ V_25 ] ) ;
F_286 ( V_434 ) ;
}
void F_287 ( struct V_629 * V_630 )
{
struct V_21 * V_15 = & V_630 -> V_15 ;
struct V_495 * V_434 = F_240 ( V_15 ) ;
F_285 ( V_434 ) ;
}
int F_288 ( struct V_629 * V_630 , const struct V_631 * V_133 )
{
unsigned long V_358 = 0 ;
switch ( V_133 -> V_632 ) {
case 1 : {
T_2 V_633 = 0 ;
F_289 ( V_630 , V_133 -> V_535 , & V_633 ) ;
V_358 = V_633 ;
break;
}
case 2 : {
T_4 V_634 = 0 ;
F_290 ( V_630 , V_133 -> V_535 , & V_634 ) ;
V_358 = V_634 ;
break;
}
case 4 : {
T_1 V_635 = 0 ;
F_291 ( V_630 , V_133 -> V_535 , & V_635 ) ;
V_358 = V_635 ;
break;
}
default:
return - V_119 ;
}
V_358 &= V_133 -> V_362 ;
return ( V_358 == V_133 -> V_536 ) ? 1 : 0 ;
}
void F_292 ( struct V_629 * V_630 , T_6 V_539 )
{
F_293 ( V_630 ) ;
F_294 ( V_630 ) ;
if ( V_539 . V_547 & V_636 )
F_295 ( V_630 , V_637 ) ;
}
int F_296 ( struct V_629 * V_630 )
{
int V_182 ;
F_295 ( V_630 , V_638 ) ;
F_297 ( V_630 ) ;
V_182 = F_298 ( V_630 ) ;
if ( V_182 ) {
F_261 ( V_187 , & V_630 -> V_15 ,
L_175 , V_182 ) ;
return V_182 ;
}
F_299 ( V_630 ) ;
return 0 ;
}
int F_300 ( struct V_629 * V_630 , T_6 V_539 )
{
struct V_495 * V_434 = F_240 ( & V_630 -> V_15 ) ;
int V_182 = 0 ;
V_182 = F_221 ( V_434 , V_539 ) ;
if ( V_182 )
return V_182 ;
F_292 ( V_630 , V_539 ) ;
return 0 ;
}
int F_301 ( struct V_629 * V_630 )
{
struct V_495 * V_434 = F_240 ( & V_630 -> V_15 ) ;
int V_182 ;
V_182 = F_296 ( V_630 ) ;
if ( V_182 == 0 )
F_222 ( V_434 ) ;
return V_182 ;
}
static int T_9 F_302 ( char * * V_455 ,
struct V_27 * V_639 ,
const char * * V_255 )
{
static struct V_640 V_641 [] V_642 = {
{ L_176 , . V_33 = V_342 } ,
{ L_177 , . V_33 = V_343 } ,
{ L_178 , . V_33 = V_494 } ,
{ L_179 , . V_33 = V_344 } ,
{ L_180 , . V_33 = V_345 } ,
{ L_181 , . V_33 = V_283 } ,
{ L_182 , . V_40 = 1 } ,
{ L_183 , . V_40 = 2 } ,
{ L_184 , . V_50 = V_289 } ,
{ L_185 , . V_51 = V_289 } ,
{ L_186 , . V_50 = V_271 } ,
{ L_187 , . V_48 = 1 << ( V_122 + 0 ) } ,
{ L_188 , . V_48 = 1 << ( V_122 + 1 ) } ,
{ L_189 , . V_48 = 1 << ( V_122 + 2 ) } ,
{ L_190 , . V_48 = 1 << ( V_122 + 3 ) } ,
{ L_191 , . V_48 = 1 << ( V_122 + 4 ) } ,
{ L_192 , . V_48 = 1 << ( V_122 + 5 ) } ,
{ L_193 , . V_48 = 1 << ( V_122 + 6 ) } ,
{ L_194 , . V_48 = 1 << ( V_124 + 0 ) } ,
{ L_195 , . V_48 = 1 << ( V_124 + 1 ) } ,
{ L_196 , . V_48 = 1 << ( V_124 + 2 ) } ,
{ L_197 , . V_48 = 1 << ( V_124 + 3 ) } ,
{ L_198 , . V_48 = 1 << ( V_124 + 4 ) } ,
{ L_199 , . V_48 = 1 << ( V_126 + 0 ) } ,
{ L_200 , . V_48 = 1 << ( V_126 + 0 ) } ,
{ L_201 , . V_48 = 1 << ( V_126 + 0 ) } ,
{ L_202 , . V_48 = 1 << ( V_126 + 1 ) } ,
{ L_203 , . V_48 = 1 << ( V_126 + 1 ) } ,
{ L_204 , . V_48 = 1 << ( V_126 + 1 ) } ,
{ L_205 , . V_48 = 1 << ( V_126 + 2 ) } ,
{ L_206 , . V_48 = 1 << ( V_126 + 2 ) } ,
{ L_207 , . V_48 = 1 << ( V_126 + 2 ) } ,
{ L_208 , . V_48 = 1 << ( V_126 + 3 ) } ,
{ L_209 , . V_48 = 1 << ( V_126 + 3 ) } ,
{ L_210 , . V_48 = 1 << ( V_126 + 3 ) } ,
{ L_211 , . V_48 = 1 << ( V_126 + 4 ) } ,
{ L_212 , . V_48 = 1 << ( V_126 + 4 ) } ,
{ L_213 , . V_48 = 1 << ( V_126 + 4 ) } ,
{ L_214 , . V_48 = 1 << ( V_126 + 5 ) } ,
{ L_215 , . V_48 = 1 << ( V_126 + 5 ) } ,
{ L_216 , . V_48 = 1 << ( V_126 + 5 ) } ,
{ L_217 , . V_48 = 1 << ( V_126 + 6 ) } ,
{ L_218 , . V_48 = 1 << ( V_126 + 6 ) } ,
{ L_219 , . V_48 = 1 << ( V_126 + 6 ) } ,
{ L_220 , . V_48 = 1 << ( V_126 + 7 ) } ,
{ L_221 , . V_42 = V_643 } ,
{ L_222 , . V_42 = V_644 } ,
{ L_223 , . V_42 = V_643 | V_644 } ,
} ;
char * V_438 = * V_455 , * V_149 = * V_455 ;
char * V_144 , * V_536 , * V_645 ;
const struct V_640 * V_646 = NULL ;
int V_647 = 0 , V_25 ;
while ( * V_149 != '\0' && * V_149 != ',' )
V_149 ++ ;
if ( * V_149 == '\0' )
* V_455 = V_149 ;
else
* V_455 = V_149 + 1 ;
* V_149 = '\0' ;
V_149 = strchr ( V_438 , ':' ) ;
if ( ! V_149 ) {
V_536 = F_303 ( V_438 ) ;
goto V_648;
}
* V_149 = '\0' ;
V_144 = F_303 ( V_438 ) ;
V_536 = F_303 ( V_149 + 1 ) ;
V_149 = strchr ( V_144 , '.' ) ;
if ( V_149 ) {
* V_149 ++ = '\0' ;
V_639 -> V_21 = F_304 ( V_149 , & V_645 , 10 ) ;
if ( V_149 == V_645 || * V_645 != '\0' ) {
* V_255 = L_224 ;
return - V_119 ;
}
}
V_639 -> V_30 = F_304 ( V_144 , & V_645 , 10 ) ;
if ( V_149 == V_645 || * V_645 != '\0' ) {
* V_255 = L_225 ;
return - V_119 ;
}
V_648:
for ( V_25 = 0 ; V_25 < F_36 ( V_641 ) ; V_25 ++ ) {
const struct V_640 * V_649 = & V_641 [ V_25 ] ;
if ( strncasecmp ( V_536 , V_649 -> V_36 , strlen ( V_536 ) ) )
continue;
V_647 ++ ;
V_646 = V_649 ;
if ( strcasecmp ( V_536 , V_649 -> V_36 ) == 0 ) {
V_647 = 1 ;
break;
}
}
if ( ! V_647 ) {
* V_255 = L_226 ;
return - V_119 ;
}
if ( V_647 > 1 ) {
* V_255 = L_227 ;
return - V_119 ;
}
V_639 -> V_32 = * V_646 ;
return 0 ;
}
static void T_9 F_305 ( void )
{
int V_650 = 0 , V_651 = 1 ;
int V_652 = - 1 , V_653 = - 1 ;
char * V_149 , * V_455 , * V_23 ;
for ( V_149 = V_654 ; * V_149 ; V_149 ++ )
if ( * V_149 == ',' )
V_651 ++ ;
V_29 = F_228 ( sizeof( V_29 [ 0 ] ) * V_651 , V_562 ) ;
if ( ! V_29 ) {
F_306 ( V_104 L_228
L_229 ) ;
return;
}
for ( V_455 = V_654 ; * V_455 != '\0' ; V_455 = V_23 ) {
const char * V_255 = L_74 ;
struct V_27 V_655 = { . V_30 = - 1 , . V_21 = - 1 } ;
V_23 = V_455 ;
if ( F_302 ( & V_23 , & V_655 , & V_255 ) ) {
F_306 ( V_104 L_230
L_231 ,
V_455 , V_255 ) ;
continue;
}
if ( V_655 . V_30 == - 1 ) {
V_655 . V_30 = V_652 ;
V_655 . V_21 = V_653 ;
}
V_29 [ V_650 ++ ] = V_655 ;
V_652 = V_655 . V_30 ;
V_653 = V_655 . V_21 ;
}
V_26 = V_650 ;
}
static int T_9 F_307 ( void )
{
int V_182 ;
F_305 () ;
V_182 = F_308 () ;
if ( V_182 ) {
F_242 ( V_29 ) ;
return V_182 ;
}
F_309 () ;
V_656 = F_310 () ;
if ( ! V_656 ) {
F_311 () ;
V_182 = - V_601 ;
goto V_265;
}
F_306 ( V_259 L_232 V_657 L_233 ) ;
return 0 ;
V_265:
return V_182 ;
}
static void T_10 F_312 ( void )
{
F_313 ( V_656 ) ;
F_314 () ;
F_311 () ;
F_242 ( V_29 ) ;
}
int F_315 ( void )
{
return F_316 ( & V_658 ) ;
}
void F_162 ( struct V_4 * V_5 , unsigned int V_659 )
{
bool V_660 = V_5 && V_5 -> V_434 -> V_661 == V_662 ;
if ( V_660 )
F_74 ( V_5 ) ;
F_168 ( V_659 ) ;
if ( V_660 )
F_77 ( V_5 ) ;
}
T_1 F_317 ( struct V_4 * V_5 , void T_11 * V_535 , T_1 V_362 , T_1 V_536 ,
unsigned long V_451 , unsigned long V_206 )
{
unsigned long V_437 ;
T_1 V_358 ;
V_358 = F_318 ( V_535 ) ;
V_437 = F_157 ( V_439 , V_206 ) ;
while ( ( V_358 & V_362 ) == V_536 && F_161 ( V_439 , V_437 ) ) {
F_162 ( V_5 , V_451 ) ;
V_358 = F_318 ( V_535 ) ;
}
return V_358 ;
}
static unsigned int F_319 ( struct V_196 * V_197 )
{
return V_216 ;
}
static void F_320 ( struct V_4 * V_5 )
{
}
