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
F_30 ( L_37 ) ;
return V_142 ;
}
void F_40 ( const T_4 * V_143 , unsigned char * V_144 ,
unsigned int V_145 , unsigned int V_146 )
{
unsigned int V_147 ;
F_3 ( V_146 & 1 ) ;
while ( V_146 > 0 ) {
V_147 = V_143 [ V_145 ] >> 8 ;
* V_144 = V_147 ;
V_144 ++ ;
V_147 = V_143 [ V_145 ] & 0xff ;
* V_144 = V_147 ;
V_144 ++ ;
V_145 ++ ;
V_146 -= 2 ;
}
}
void F_41 ( const T_4 * V_143 , unsigned char * V_144 ,
unsigned int V_145 , unsigned int V_146 )
{
unsigned char * V_148 ;
F_40 ( V_143 , V_144 , V_145 , V_146 - 1 ) ;
V_148 = V_144 + F_42 ( V_144 , V_146 - 1 ) ;
while ( V_148 > V_144 && V_148 [ - 1 ] == ' ' )
V_148 -- ;
* V_148 = '\0' ;
}
static T_3 F_43 ( const T_4 * V_143 )
{
if ( F_44 ( V_143 ) ) {
if ( F_45 ( V_143 ) )
return F_46 ( V_143 , V_149 ) ;
else
return F_47 ( V_143 , V_150 ) ;
} else {
if ( F_48 ( V_143 ) )
return V_143 [ V_151 ] * V_143 [ V_152 ] *
V_143 [ V_153 ] ;
else
return V_143 [ V_154 ] * V_143 [ V_155 ] *
V_143 [ V_156 ] ;
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
static int F_51 ( struct V_14 * V_15 , T_3 * V_157 )
{
unsigned int V_158 ;
struct V_67 V_68 ;
int V_87 = F_45 ( V_15 -> V_143 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_42 |= V_110 | V_109 ;
if ( V_87 ) {
V_68 . V_71 = V_159 ;
V_68 . V_42 |= V_90 ;
} else
V_68 . V_71 = V_160 ;
V_68 . V_93 |= V_161 ;
V_68 . V_21 |= V_116 ;
V_158 = F_53 ( V_15 , & V_68 , NULL , V_162 , NULL , 0 , 0 ) ;
if ( V_158 ) {
F_24 ( V_15 ,
L_38 ,
V_158 ) ;
if ( V_158 == V_163 && ( V_68 . V_72 & V_164 ) )
return - V_165 ;
return - V_166 ;
}
if ( V_87 )
* V_157 = F_49 ( & V_68 ) + 1 ;
else
* V_157 = F_50 ( & V_68 ) + 1 ;
if ( V_15 -> V_48 & V_167 )
( * V_157 ) -- ;
return 0 ;
}
static int F_54 ( struct V_14 * V_15 , T_3 V_168 )
{
unsigned int V_158 ;
struct V_67 V_68 ;
int V_87 = F_45 ( V_15 -> V_143 ) ;
V_168 -- ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_42 |= V_110 | V_109 ;
if ( V_87 ) {
V_68 . V_71 = V_169 ;
V_68 . V_42 |= V_90 ;
V_68 . V_76 = ( V_168 >> 24 ) & 0xff ;
V_68 . V_77 = ( V_168 >> 32 ) & 0xff ;
V_68 . V_78 = ( V_168 >> 40 ) & 0xff ;
} else {
V_68 . V_71 = V_170 ;
V_68 . V_21 |= ( V_168 >> 24 ) & 0xf ;
}
V_68 . V_93 |= V_161 ;
V_68 . V_21 |= V_116 ;
V_68 . V_73 = ( V_168 >> 0 ) & 0xff ;
V_68 . V_74 = ( V_168 >> 8 ) & 0xff ;
V_68 . V_75 = ( V_168 >> 16 ) & 0xff ;
V_158 = F_53 ( V_15 , & V_68 , NULL , V_162 , NULL , 0 , 0 ) ;
if ( V_158 ) {
F_24 ( V_15 ,
L_39 ,
V_158 ) ;
if ( V_158 == V_163 &&
( V_68 . V_72 & ( V_164 | V_171 ) ) )
return - V_165 ;
return - V_166 ;
}
return 0 ;
}
static int F_55 ( struct V_14 * V_15 )
{
struct V_172 * V_173 = & V_15 -> V_3 -> V_174 ;
int V_175 = V_173 -> V_25 . V_42 & V_176 ;
bool V_177 = V_178 || V_15 -> V_42 & V_179 ;
T_3 V_105 = F_43 ( V_15 -> V_143 ) ;
T_3 V_180 ;
int V_181 ;
if ( V_15 -> V_182 != V_138 ||
! F_44 ( V_15 -> V_143 ) || ! F_56 ( V_15 -> V_143 ) ||
( V_15 -> V_48 & V_183 ) )
return 0 ;
V_181 = F_51 ( V_15 , & V_180 ) ;
if ( V_181 ) {
if ( V_181 == - V_165 || ! V_177 ) {
F_24 ( V_15 ,
L_40 ) ;
V_15 -> V_48 |= V_183 ;
if ( V_181 == - V_165 )
V_181 = 0 ;
}
return V_181 ;
}
V_15 -> V_184 = V_180 ;
if ( V_180 <= V_105 || ! V_177 ) {
if ( ! V_175 || V_180 == V_105 )
return 0 ;
if ( V_180 > V_105 )
F_57 ( V_15 ,
L_41 ,
( unsigned long long ) V_105 ,
( unsigned long long ) V_180 ) ;
else if ( V_180 < V_105 )
F_24 ( V_15 ,
L_42 ,
( unsigned long long ) V_180 ,
( unsigned long long ) V_105 ) ;
return 0 ;
}
V_181 = F_54 ( V_15 , V_180 ) ;
if ( V_181 == - V_165 ) {
F_24 ( V_15 ,
L_43 ,
( unsigned long long ) V_105 ,
( unsigned long long ) V_180 ) ;
V_15 -> V_48 |= V_183 ;
return 0 ;
} else if ( V_181 )
return V_181 ;
V_181 = F_58 ( V_15 , 0 ) ;
if ( V_181 ) {
F_59 ( V_15 ,
L_44 ) ;
return V_181 ;
}
if ( V_175 ) {
T_3 V_168 = F_43 ( V_15 -> V_143 ) ;
F_57 ( V_15 ,
L_45 ,
( unsigned long long ) V_105 ,
( unsigned long long ) V_168 ,
( unsigned long long ) V_180 ) ;
}
return 0 ;
}
static inline void F_60 ( const T_4 * V_143 )
{
F_30 ( L_46
L_47
L_48
L_49
L_50 ,
V_143 [ 49 ] ,
V_143 [ 53 ] ,
V_143 [ 63 ] ,
V_143 [ 64 ] ,
V_143 [ 75 ] ) ;
F_30 ( L_51
L_52
L_53
L_54
L_55 ,
V_143 [ 80 ] ,
V_143 [ 81 ] ,
V_143 [ 82 ] ,
V_143 [ 83 ] ,
V_143 [ 84 ] ) ;
F_30 ( L_56
L_57 ,
V_143 [ 88 ] ,
V_143 [ 93 ] ) ;
}
unsigned long F_61 ( const T_4 * V_143 )
{
unsigned long V_44 , V_45 , V_46 ;
if ( V_143 [ V_185 ] & ( 1 << 1 ) ) {
V_44 = V_143 [ V_186 ] & 0x03 ;
V_44 <<= 3 ;
V_44 |= 0x7 ;
} else {
T_2 V_7 = ( V_143 [ V_187 ] >> 8 ) & 0xFF ;
if ( V_7 < 5 )
V_44 = ( 2 << V_7 ) - 1 ;
else
V_44 = 1 ;
}
V_45 = V_143 [ V_188 ] & 0x07 ;
if ( F_62 ( V_143 ) ) {
int V_189 = ( V_143 [ V_190 ] >> 0 ) & 0x7 ;
int V_191 = ( V_143 [ V_190 ] >> 3 ) & 0x7 ;
if ( V_189 )
V_44 |= ( 1 << 5 ) ;
if ( V_189 > 1 )
V_44 |= ( 1 << 6 ) ;
if ( V_191 )
V_45 |= ( 1 << 3 ) ;
if ( V_191 > 1 )
V_45 |= ( 1 << 4 ) ;
}
V_46 = 0 ;
if ( V_143 [ V_185 ] & ( 1 << 2 ) )
V_46 = V_143 [ V_192 ] & 0xff ;
return F_31 ( V_44 , V_45 , V_46 ) ;
}
static void F_63 ( struct V_193 * V_194 )
{
struct V_195 * V_196 = V_194 -> V_197 ;
F_64 ( V_196 ) ;
}
unsigned F_65 ( struct V_14 * V_15 ,
struct V_67 * V_68 , const T_2 * V_198 ,
int V_199 , struct V_200 * V_201 ,
unsigned int V_202 , unsigned long V_203 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_4 * V_5 = V_3 -> V_5 ;
T_2 V_71 = V_68 -> V_71 ;
int V_204 = 0 ;
struct V_193 * V_194 ;
unsigned int V_108 , V_205 ;
T_1 V_206 , V_207 ;
int V_208 ;
F_66 ( V_209 ) ;
unsigned long V_42 ;
unsigned int V_158 ;
int V_181 ;
F_67 ( V_5 -> V_210 , V_42 ) ;
if ( V_5 -> V_211 & V_212 ) {
F_68 ( V_5 -> V_210 , V_42 ) ;
return V_213 ;
}
if ( V_5 -> V_214 -> V_215 )
V_108 = V_111 ;
else
V_108 = 0 ;
if ( F_69 ( V_108 , & V_5 -> V_216 ) )
F_70 () ;
V_194 = F_71 ( V_5 , V_108 ) ;
V_194 -> V_108 = V_108 ;
V_194 -> V_217 = NULL ;
V_194 -> V_5 = V_5 ;
V_194 -> V_15 = V_15 ;
F_72 ( V_194 ) ;
V_205 = V_3 -> V_218 ;
V_206 = V_3 -> V_219 ;
V_207 = V_5 -> V_220 ;
V_208 = V_5 -> V_221 ;
V_3 -> V_218 = V_222 ;
V_3 -> V_219 = 0 ;
V_5 -> V_220 = 0 ;
V_5 -> V_221 = 0 ;
V_194 -> V_68 = * V_68 ;
if ( V_198 )
memcpy ( V_194 -> V_198 , V_198 , V_223 ) ;
if ( V_68 -> V_93 == V_224 && ( V_15 -> V_42 & V_225 ) &&
V_199 == V_226 )
V_194 -> V_68 . V_72 |= V_227 ;
V_194 -> V_42 |= V_228 ;
V_194 -> V_199 = V_199 ;
if ( V_199 != V_162 ) {
unsigned int V_25 , V_229 = 0 ;
struct V_200 * V_230 ;
F_73 (sgl, sg, n_elem, i)
V_229 += V_230 -> V_231 ;
F_74 ( V_194 , V_201 , V_202 ) ;
V_194 -> V_232 = V_229 ;
}
V_194 -> V_197 = & V_209 ;
V_194 -> V_233 = F_63 ;
F_75 ( V_194 ) ;
F_68 ( V_5 -> V_210 , V_42 ) ;
if ( ! V_203 ) {
if ( V_234 )
V_203 = V_234 * 1000 ;
else {
V_203 = F_76 ( V_15 , V_71 ) ;
V_204 = 1 ;
}
}
if ( V_5 -> V_214 -> V_215 )
F_77 ( V_5 ) ;
V_181 = F_78 ( & V_209 , F_79 ( V_203 ) ) ;
if ( V_5 -> V_214 -> V_215 )
F_80 ( V_5 ) ;
F_81 ( V_5 ) ;
if ( ! V_181 ) {
F_67 ( V_5 -> V_210 , V_42 ) ;
if ( V_194 -> V_42 & V_235 ) {
V_194 -> V_158 |= V_236 ;
if ( V_5 -> V_214 -> V_215 )
F_82 ( V_5 ) ;
else
F_83 ( V_194 ) ;
if ( F_84 ( V_5 ) )
F_24 ( V_15 , L_58 ,
V_71 ) ;
}
F_68 ( V_5 -> V_210 , V_42 ) ;
}
if ( V_5 -> V_214 -> V_237 )
V_5 -> V_214 -> V_237 ( V_194 ) ;
if ( V_194 -> V_42 & V_238 ) {
if ( V_194 -> V_239 . V_71 & ( V_240 | V_241 ) )
V_194 -> V_158 |= V_163 ;
if ( ! V_194 -> V_158 )
V_194 -> V_158 |= V_242 ;
if ( V_194 -> V_158 & ~ V_242 )
V_194 -> V_158 &= ~ V_242 ;
}
F_67 ( V_5 -> V_210 , V_42 ) ;
* V_68 = V_194 -> V_239 ;
V_158 = V_194 -> V_158 ;
F_85 ( V_194 ) ;
V_3 -> V_218 = V_205 ;
V_3 -> V_219 = V_206 ;
V_5 -> V_220 = V_207 ;
V_5 -> V_221 = V_208 ;
F_68 ( V_5 -> V_210 , V_42 ) ;
if ( ( V_158 & V_236 ) && V_204 )
F_86 ( V_15 , V_71 ) ;
return V_158 ;
}
unsigned F_53 ( struct V_14 * V_15 ,
struct V_67 * V_68 , const T_2 * V_198 ,
int V_199 , void * V_243 , unsigned int V_229 ,
unsigned long V_203 )
{
struct V_200 * V_244 = NULL , V_230 ;
unsigned int V_202 = 0 ;
if ( V_199 != V_162 ) {
F_87 ( ! V_243 ) ;
F_88 ( & V_230 , V_243 , V_229 ) ;
V_244 = & V_230 ;
V_202 ++ ;
}
return F_65 ( V_15 , V_68 , V_198 , V_199 , V_244 , V_202 ,
V_203 ) ;
}
unsigned int F_89 ( struct V_14 * V_15 , T_2 V_84 )
{
struct V_67 V_68 ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_84 ;
V_68 . V_42 |= V_110 ;
V_68 . V_93 = V_161 ;
return F_53 ( V_15 , & V_68 , NULL , V_162 , NULL , 0 , 0 ) ;
}
unsigned int F_90 ( const struct V_14 * V_245 )
{
if ( V_245 -> V_3 -> V_5 -> V_211 & V_246 )
return 0 ;
if ( V_245 -> V_3 -> V_5 -> V_42 & V_247 )
return 0 ;
if ( F_62 ( V_245 -> V_143 )
&& ( V_245 -> V_248 == V_249 || V_245 -> V_248 == V_250 ) )
return 0 ;
if ( V_245 -> V_248 > V_251 )
return 1 ;
if ( F_91 ( V_245 -> V_143 ) )
return 1 ;
return 0 ;
}
static T_1 F_92 ( const struct V_14 * V_245 )
{
if ( V_245 -> V_143 [ V_185 ] & 2 ) {
T_4 V_189 = V_245 -> V_143 [ V_252 ] ;
if ( V_189 ) {
if ( V_189 > 240 )
return 3 << V_121 ;
return 7 << V_121 ;
}
}
return 3 << V_121 ;
}
unsigned int F_93 ( struct V_14 * V_15 ,
struct V_67 * V_68 , T_4 * V_143 )
{
return F_53 ( V_15 , V_68 , NULL , V_226 ,
V_143 , sizeof( V_143 [ 0 ] ) * V_253 , 0 ) ;
}
int F_94 ( struct V_14 * V_15 , unsigned int * V_254 ,
unsigned int V_42 , T_4 * V_143 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
unsigned int V_182 = * V_254 ;
struct V_67 V_68 ;
unsigned int V_158 = 0 ;
const char * V_255 ;
bool V_256 = V_182 == V_141 ;
int V_257 = 1 , V_258 = 0 ;
int V_181 ;
if ( F_95 ( V_5 ) )
F_96 ( V_15 , L_59 , V_259 ) ;
V_260:
F_52 ( V_15 , & V_68 ) ;
switch ( V_182 ) {
case V_141 :
V_182 = V_138 ;
case V_138 :
V_68 . V_71 = V_261 ;
break;
case V_139 :
V_68 . V_71 = V_262 ;
break;
default:
V_181 = - V_263 ;
V_255 = L_60 ;
goto V_264;
}
V_68 . V_93 = V_94 ;
V_68 . V_42 |= V_109 | V_110 ;
V_68 . V_42 |= V_265 ;
if ( V_5 -> V_214 -> V_266 )
V_158 = V_5 -> V_214 -> V_266 ( V_15 , & V_68 , V_143 ) ;
else
V_158 = F_93 ( V_15 , & V_68 , V_143 ) ;
if ( V_158 ) {
if ( V_158 & V_267 ) {
F_96 ( V_15 , L_61 ) ;
return - V_268 ;
}
if ( V_256 ) {
F_57 ( V_15 ,
L_62 ) ;
* V_254 = V_269 ;
return 0 ;
}
if ( ( V_158 == V_163 ) && ( V_68 . V_72 & V_164 ) ) {
if ( V_257 ) {
V_257 = 0 ;
if ( V_182 == V_138 )
V_182 = V_139 ;
else
V_182 = V_138 ;
goto V_260;
}
F_96 ( V_15 ,
L_63 ) ;
return - V_268 ;
}
V_181 = - V_166 ;
V_255 = L_64 ;
goto V_264;
}
if ( V_15 -> V_48 & V_270 ) {
F_96 ( V_15 , L_65
L_66 ,
V_182 , V_257 , V_258 ) ;
F_97 ( V_271 , L_67 , V_272 ,
16 , 2 , V_143 , V_253 * sizeof( * V_143 ) , true ) ;
}
V_257 = 0 ;
F_98 ( V_143 , V_253 ) ;
V_181 = - V_119 ;
V_255 = L_68 ;
if ( V_182 == V_138 ) {
if ( ! F_99 ( V_143 ) && ! F_62 ( V_143 ) )
goto V_264;
if ( V_5 -> V_273 -> V_42 & V_274 &&
F_99 ( V_143 ) ) {
F_96 ( V_15 ,
L_69 ) ;
return - V_268 ;
}
} else {
if ( F_99 ( V_143 ) )
goto V_264;
}
if ( ! V_258 && ( V_143 [ 2 ] == 0x37c8 || V_143 [ 2 ] == 0x738c ) ) {
V_258 = 1 ;
V_158 = F_100 ( V_15 , V_275 , 0 ) ;
if ( V_158 && V_143 [ 2 ] != 0x738c ) {
V_181 = - V_166 ;
V_255 = L_70 ;
goto V_264;
}
if ( V_143 [ 2 ] == 0x37c8 )
goto V_260;
}
if ( ( V_42 & V_276 ) && V_182 == V_138 ) {
if ( F_101 ( V_143 ) < 4 || ! F_44 ( V_143 ) ) {
V_158 = F_102 ( V_15 , V_143 [ 3 ] , V_143 [ 6 ] ) ;
if ( V_158 ) {
V_181 = - V_166 ;
V_255 = L_71 ;
goto V_264;
}
V_42 &= ~ V_276 ;
goto V_260;
}
}
* V_254 = V_182 ;
return 0 ;
V_264:
if ( F_84 ( V_5 ) )
F_24 ( V_15 , L_72 ,
V_255 , V_158 ) ;
return V_181 ;
}
static int F_103 ( struct V_14 * V_15 )
{
struct V_2 * V_277 = F_9 ( V_15 ) ;
T_1 V_278 , V_279 ;
if ( ! F_104 ( V_277 ) )
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
F_57 ( V_15 , L_73 ,
F_38 ( V_278 ) ) ;
return - V_283 ;
}
return 0 ;
}
static inline T_2 F_105 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
if ( F_106 ( V_15 ) & V_284 )
return 0 ;
return ( ( V_5 -> V_33 == V_285 ) && ( ! F_107 ( V_15 -> V_143 ) ) ) ;
}
static int F_108 ( struct V_14 * V_15 ,
char * V_286 , T_5 V_287 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
int V_288 = 0 , V_289 = F_109 ( V_15 -> V_143 ) ;
unsigned int V_158 ;
char * V_290 = L_67 ;
if ( ! F_110 ( V_15 -> V_143 ) ) {
V_286 [ 0 ] = '\0' ;
return 0 ;
}
if ( V_15 -> V_48 & V_291 ) {
snprintf ( V_286 , V_287 , L_74 ) ;
return 0 ;
}
if ( V_5 -> V_42 & V_292 ) {
V_288 = F_111 ( V_5 -> V_293 -> V_294 , V_295 - 1 ) ;
V_15 -> V_42 |= V_296 ;
}
if ( ! ( V_15 -> V_48 & V_297 ) &&
( V_5 -> V_42 & V_298 ) &&
F_112 ( V_15 -> V_143 ) ) {
V_158 = F_100 ( V_15 , V_299 ,
V_300 ) ;
if ( V_158 ) {
F_59 ( V_15 ,
L_75 ,
V_158 ) ;
if ( V_158 != V_163 ) {
V_15 -> V_48 |= V_297 ;
return - V_166 ;
}
} else
V_290 = L_76 ;
}
if ( V_288 >= V_289 )
snprintf ( V_286 , V_287 , L_77 , V_289 , V_290 ) ;
else
snprintf ( V_286 , V_287 , L_78 , V_288 ,
V_289 , V_290 ) ;
if ( ( V_5 -> V_42 & V_301 ) &&
F_113 ( V_15 -> V_143 ) ) {
V_158 = F_114 ( V_15 , V_302 ,
0 , V_5 -> V_303 , 1 ) ;
if ( V_158 ) {
F_96 ( V_15 ,
L_79 ,
V_158 ) ;
} else {
V_15 -> V_42 |= V_304 ;
memcpy ( V_15 -> V_305 , V_5 -> V_303 ,
V_306 ) ;
}
}
return 0 ;
}
int F_115 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_172 * V_173 = & V_15 -> V_3 -> V_174 ;
int V_175 = V_173 -> V_25 . V_42 & V_176 ;
const T_4 * V_143 = V_15 -> V_143 ;
unsigned long V_47 ;
unsigned int V_158 ;
char V_307 [ 7 ] ;
char V_308 [ V_309 + 1 ] ;
char V_310 [ V_311 + 1 ] ;
int V_181 ;
if ( ! F_8 ( V_15 ) && F_116 ( V_5 ) ) {
F_57 ( V_15 , L_80 , V_259 ) ;
return 0 ;
}
if ( F_117 ( V_5 ) )
F_96 ( V_15 , L_59 , V_259 ) ;
V_15 -> V_48 |= F_106 ( V_15 ) ;
F_18 ( V_15 ) ;
if ( V_15 -> V_48 & V_312 ) {
F_57 ( V_15 , L_81 ) ;
F_118 ( V_15 ) ;
return 0 ;
}
if ( ( ! V_313 || ( V_5 -> V_42 & V_314 ) ) &&
V_15 -> V_182 == V_139 ) {
F_24 ( V_15 , L_82 ,
V_313 ? L_83
: L_84 ) ;
F_118 ( V_15 ) ;
return 0 ;
}
V_181 = F_103 ( V_15 ) ;
if ( V_181 )
return V_181 ;
V_181 = F_119 ( V_15 ) ;
if ( V_181 )
return V_181 ;
V_181 = F_55 ( V_15 ) ;
if ( V_181 )
return V_181 ;
if ( F_117 ( V_5 ) )
F_96 ( V_15 ,
L_85
L_86 ,
V_259 ,
V_143 [ 49 ] , V_143 [ 82 ] , V_143 [ 83 ] , V_143 [ 84 ] ,
V_143 [ 85 ] , V_143 [ 86 ] , V_143 [ 87 ] , V_143 [ 88 ] ) ;
V_15 -> V_42 &= ~ V_315 ;
V_15 -> V_157 = 0 ;
V_15 -> V_316 = 0 ;
V_15 -> V_317 = 0 ;
V_15 -> V_318 = 0 ;
V_15 -> V_104 = 0 ;
V_15 -> V_105 = 0 ;
V_15 -> V_95 = 0 ;
V_47 = F_61 ( V_143 ) ;
if ( F_117 ( V_5 ) )
F_60 ( V_143 ) ;
F_41 ( V_15 -> V_143 , V_308 , V_319 ,
sizeof( V_308 ) ) ;
F_41 ( V_15 -> V_143 , V_310 , V_320 ,
sizeof( V_310 ) ) ;
if ( V_15 -> V_182 == V_138 ) {
if ( F_62 ( V_143 ) ) {
if ( V_143 [ V_321 ] & 1 )
F_24 ( V_15 ,
L_87 ) ;
snprintf ( V_307 , 7 , L_88 ) ;
} else {
snprintf ( V_307 , 7 , L_89 , F_101 ( V_143 ) ) ;
if ( F_120 ( V_143 ) )
F_24 ( V_15 ,
L_87 ) ;
}
V_15 -> V_317 = F_43 ( V_143 ) ;
if ( ( V_15 -> V_143 [ 47 ] >> 8 ) == 0x80 && ( V_15 -> V_143 [ 59 ] & 0x100 ) ) {
unsigned int V_322 = V_15 -> V_143 [ 47 ] & 0xff ;
unsigned int V_323 = V_15 -> V_143 [ 59 ] & 0xff ;
if ( F_121 ( V_322 ) && F_121 ( V_323 ) )
if ( V_323 <= V_322 )
V_15 -> V_95 = V_323 ;
}
if ( F_44 ( V_143 ) ) {
const char * V_324 ;
char V_325 [ 24 ] ;
V_324 = L_90 ;
V_15 -> V_42 |= V_117 ;
if ( F_45 ( V_143 ) ) {
V_15 -> V_42 |= V_118 ;
V_324 = L_91 ;
if ( V_15 -> V_317 >= ( 1UL << 28 ) &&
F_122 ( V_143 ) )
V_15 -> V_42 |= V_326 ;
}
V_181 = F_108 ( V_15 , V_325 , sizeof( V_325 ) ) ;
if ( V_181 )
return V_181 ;
if ( F_123 ( V_5 ) && V_175 ) {
F_57 ( V_15 , L_92 ,
V_307 , V_310 , V_308 ,
F_36 ( V_47 ) ) ;
F_57 ( V_15 ,
L_93 ,
( unsigned long long ) V_15 -> V_317 ,
V_15 -> V_95 , V_324 , V_325 ) ;
}
} else {
V_15 -> V_318 = V_143 [ 1 ] ;
V_15 -> V_104 = V_143 [ 3 ] ;
V_15 -> V_105 = V_143 [ 6 ] ;
if ( F_48 ( V_143 ) ) {
V_15 -> V_318 = V_143 [ 54 ] ;
V_15 -> V_104 = V_143 [ 55 ] ;
V_15 -> V_105 = V_143 [ 56 ] ;
}
if ( F_123 ( V_5 ) && V_175 ) {
F_57 ( V_15 , L_92 ,
V_307 , V_310 , V_308 ,
F_36 ( V_47 ) ) ;
F_57 ( V_15 ,
L_94 ,
( unsigned long long ) V_15 -> V_317 ,
V_15 -> V_95 , V_15 -> V_318 ,
V_15 -> V_104 , V_15 -> V_105 ) ;
}
}
if ( F_124 ( V_15 -> V_143 ) ) {
T_2 * V_327 = V_5 -> V_303 ;
int V_25 , V_328 ;
V_15 -> V_42 |= V_329 ;
V_158 = F_114 ( V_15 ,
V_330 ,
V_331 ,
V_327 ,
1 ) ;
if ( V_158 )
F_96 ( V_15 ,
L_95 ,
V_158 ) ;
else
for ( V_25 = 0 ; V_25 < V_332 ; V_25 ++ ) {
V_328 = V_333 + V_25 ;
V_15 -> V_334 [ V_25 ] = V_327 [ V_328 ] ;
}
}
V_15 -> V_316 = 16 ;
}
else if ( V_15 -> V_182 == V_139 ) {
const char * V_335 = L_67 ;
const char * V_336 = L_67 ;
const char * V_337 = L_67 ;
T_1 V_338 ;
V_181 = F_125 ( V_143 ) ;
if ( ( V_181 < 12 ) || ( V_181 > V_223 ) ) {
if ( F_84 ( V_5 ) )
F_24 ( V_15 , L_96 ) ;
V_181 = - V_119 ;
goto V_339;
}
V_15 -> V_316 = ( unsigned int ) V_181 ;
if ( V_340 &&
( V_5 -> V_42 & V_341 ) && F_126 ( V_143 ) &&
( ! F_4 ( V_5 ) ||
F_127 ( & V_5 -> V_3 , V_342 , & V_338 ) == 0 ) ) {
V_158 = F_100 ( V_15 ,
V_299 , V_343 ) ;
if ( V_158 )
F_59 ( V_15 ,
L_97 ,
V_158 ) ;
else {
V_15 -> V_42 |= V_344 ;
V_336 = L_98 ;
}
}
if ( F_128 ( V_15 -> V_143 ) ) {
V_15 -> V_42 |= V_345 ;
V_335 = L_99 ;
}
if ( V_346 || ( V_15 -> V_48 & V_347 ) || F_129 ( V_15 -> V_143 ) ) {
V_15 -> V_42 |= V_225 ;
V_337 = L_100 ;
}
if ( F_130 ( V_15 -> V_143 ) ) {
V_15 -> V_42 |= V_348 ;
F_131 ( V_15 ) ;
}
if ( F_123 ( V_5 ) && V_175 )
F_57 ( V_15 ,
L_101 ,
V_310 , V_308 ,
F_36 ( V_47 ) ,
V_335 , V_336 ,
V_337 ) ;
}
V_15 -> V_157 = V_349 ;
if ( V_15 -> V_42 & V_118 )
V_15 -> V_157 = V_350 ;
if ( F_105 ( V_15 ) ) {
if ( F_123 ( V_5 ) && V_175 )
F_57 ( V_15 , L_102 ) ;
V_15 -> V_46 &= V_351 ;
V_15 -> V_157 = V_349 ;
}
if ( ( V_15 -> V_182 == V_139 ) &&
( F_132 ( V_143 ) == V_352 ) ) {
V_15 -> V_157 = V_353 ;
V_15 -> V_48 |= V_354 ;
}
if ( V_15 -> V_48 & V_355 )
V_15 -> V_157 = F_133 (unsigned int, ATA_MAX_SECTORS_128,
dev->max_sectors) ;
if ( V_15 -> V_48 & V_356 )
V_15 -> V_157 = V_350 ;
if ( V_5 -> V_214 -> V_357 )
V_5 -> V_214 -> V_357 ( V_15 ) ;
if ( V_15 -> V_48 & V_358 ) {
if ( V_175 ) {
F_24 ( V_15 ,
L_103 ) ;
F_24 ( V_15 ,
L_104 ) ;
}
}
if ( ( V_15 -> V_48 & V_359 ) && V_175 ) {
F_24 ( V_15 , L_105 ) ;
F_24 ( V_15 , L_106 ) ;
}
return 0 ;
V_339:
if ( F_117 ( V_5 ) )
F_96 ( V_15 , L_107 , V_259 ) ;
return V_181 ;
}
int F_134 ( struct V_4 * V_5 )
{
return V_360 ;
}
int F_135 ( struct V_4 * V_5 )
{
return V_361 ;
}
int F_136 ( struct V_4 * V_5 )
{
return V_362 ;
}
int F_137 ( struct V_4 * V_5 )
{
return V_363 ;
}
int F_138 ( struct V_4 * V_5 )
{
return V_285 ;
}
int F_139 ( struct V_4 * V_5 )
{
unsigned int V_364 [ V_365 ] ;
int V_366 [ V_365 ] ;
int V_181 ;
struct V_14 * V_15 ;
F_140 (dev, &ap->link, ALL)
V_366 [ V_15 -> V_24 ] = V_367 ;
V_260:
F_140 (dev, &ap->link, ALL) {
V_15 -> V_248 = V_368 ;
V_15 -> V_369 = 0xff ;
if ( V_5 -> V_214 -> V_370 )
V_5 -> V_214 -> V_370 ( V_5 , V_15 ) ;
}
V_5 -> V_214 -> V_371 ( V_5 ) ;
F_140 (dev, &ap->link, ALL) {
if ( V_15 -> V_182 != V_142 )
V_364 [ V_15 -> V_24 ] = V_15 -> V_182 ;
else
V_364 [ V_15 -> V_24 ] = V_372 ;
V_15 -> V_182 = V_142 ;
}
F_140 (dev, &ap->link, ALL_REVERSE) {
if ( V_366 [ V_15 -> V_24 ] )
V_15 -> V_182 = V_364 [ V_15 -> V_24 ] ;
if ( ! F_8 ( V_15 ) )
continue;
V_181 = F_94 ( V_15 , & V_15 -> V_182 , V_276 ,
V_15 -> V_143 ) ;
if ( V_181 )
goto V_373;
}
if ( V_5 -> V_214 -> V_374 )
V_5 -> V_33 = V_5 -> V_214 -> V_374 ( V_5 ) ;
F_140 (dev, &ap->link, ENABLED)
if ( F_107 ( V_15 -> V_143 ) )
V_5 -> V_33 = V_285 ;
F_140 (dev, &ap->link, ENABLED) {
V_5 -> V_3 . V_174 . V_25 . V_42 |= V_176 ;
V_181 = F_115 ( V_15 ) ;
V_5 -> V_3 . V_174 . V_25 . V_42 &= ~ V_176 ;
if ( V_181 )
goto V_373;
}
V_181 = F_141 ( & V_5 -> V_3 , & V_15 ) ;
if ( V_181 )
goto V_373;
F_140 (dev, &ap->link, ENABLED)
return 0 ;
return - V_263 ;
V_373:
V_366 [ V_15 -> V_24 ] -- ;
switch ( V_181 ) {
case - V_119 :
V_366 [ V_15 -> V_24 ] = 0 ;
break;
case - V_263 :
V_366 [ V_15 -> V_24 ] = F_111 ( V_366 [ V_15 -> V_24 ] , 1 ) ;
case - V_166 :
if ( V_366 [ V_15 -> V_24 ] == 1 ) {
F_142 ( & V_5 -> V_3 , 0 ) ;
F_143 ( V_15 , V_375 ) ;
}
}
if ( ! V_366 [ V_15 -> V_24 ] )
F_118 ( V_15 ) ;
goto V_260;
}
static void F_144 ( struct V_2 * V_3 )
{
T_1 V_1 , V_376 , V_377 ;
if ( F_127 ( V_3 , V_378 , & V_1 ) )
return;
F_127 ( V_3 , V_379 , & V_376 ) ;
if ( F_145 ( V_3 ) ) {
V_377 = ( V_1 >> 4 ) & 0xf ;
F_146 ( V_3 , L_108 ,
F_38 ( V_377 ) , V_1 , V_376 ) ;
} else {
F_146 ( V_3 , L_109 ,
V_1 , V_376 ) ;
}
}
struct V_14 * F_147 ( struct V_14 * V_245 )
{
struct V_2 * V_3 = V_245 -> V_3 ;
struct V_14 * V_380 = & V_3 -> V_21 [ 1 - V_245 -> V_24 ] ;
if ( ! F_8 ( V_380 ) )
return NULL ;
return V_380 ;
}
int F_142 ( struct V_2 * V_3 , T_1 V_39 )
{
T_1 V_1 , V_136 , V_381 ;
int V_181 , V_382 ;
if ( ! F_104 ( V_3 ) )
return - V_383 ;
V_181 = F_127 ( V_3 , V_378 , & V_1 ) ;
if ( V_181 == 0 && F_1 ( V_1 ) )
V_136 = ( V_1 >> 4 ) & 0xf ;
else
V_136 = V_3 -> V_282 ;
V_381 = V_3 -> V_281 ;
if ( V_381 <= 1 )
return - V_119 ;
V_382 = F_33 ( V_381 ) - 1 ;
V_381 &= ~ ( 1 << V_382 ) ;
if ( V_136 > 1 )
V_381 &= ( 1 << ( V_136 - 1 ) ) - 1 ;
else
V_381 &= 1 ;
if ( ! V_381 )
return - V_119 ;
if ( V_39 ) {
if ( V_381 & ( ( 1 << V_39 ) - 1 ) )
V_381 &= ( 1 << V_39 ) - 1 ;
else {
V_382 = F_148 ( V_381 ) - 1 ;
V_381 = 1 << V_382 ;
}
}
V_3 -> V_281 = V_381 ;
F_149 ( V_3 , L_110 ,
F_38 ( F_33 ( V_381 ) ) ) ;
return 0 ;
}
static int F_150 ( struct V_2 * V_3 , T_1 * V_376 )
{
struct V_2 * V_384 = & V_3 -> V_5 -> V_3 ;
T_1 V_385 , V_278 , V_136 ;
V_385 = V_3 -> V_281 ;
if ( ! F_13 ( V_3 ) && V_384 -> V_282 )
V_385 &= ( 1 << V_384 -> V_282 ) - 1 ;
if ( V_385 == V_386 )
V_278 = 0 ;
else
V_278 = F_33 ( V_385 ) ;
V_136 = ( * V_376 >> 4 ) & 0xf ;
* V_376 = ( * V_376 & ~ 0xf0 ) | ( ( V_278 & 0xf ) << 4 ) ;
return V_136 != V_278 ;
}
static int F_151 ( struct V_2 * V_3 )
{
T_1 V_376 ;
if ( F_127 ( V_3 , V_379 , & V_376 ) )
return 1 ;
return F_150 ( V_3 , & V_376 ) ;
}
int F_152 ( struct V_2 * V_3 )
{
T_1 V_376 ;
int V_181 ;
if ( ( V_181 = F_127 ( V_3 , V_379 , & V_376 ) ) )
return V_181 ;
if ( ! F_150 ( V_3 , & V_376 ) )
return 0 ;
if ( ( V_181 = F_153 ( V_3 , V_379 , V_376 ) ) )
return V_181 ;
return 1 ;
}
static void F_154 ( const struct V_387 * V_388 , struct V_387 * V_389 , int V_390 , int V_391 )
{
V_389 -> V_392 = F_155 ( V_388 -> V_392 * 1000 , V_390 ) ;
V_389 -> V_393 = F_155 ( V_388 -> V_393 * 1000 , V_390 ) ;
V_389 -> V_394 = F_155 ( V_388 -> V_394 * 1000 , V_390 ) ;
V_389 -> V_395 = F_155 ( V_388 -> V_395 * 1000 , V_390 ) ;
V_389 -> V_396 = F_155 ( V_388 -> V_396 * 1000 , V_390 ) ;
V_389 -> V_397 = F_155 ( V_388 -> V_397 * 1000 , V_390 ) ;
V_389 -> V_398 = F_155 ( V_388 -> V_398 * 1000 , V_390 ) ;
V_389 -> V_399 = F_155 ( V_388 -> V_399 * 1000 , V_390 ) ;
V_389 -> V_400 = F_155 ( V_388 -> V_400 * 1000 , V_391 ) ;
}
void F_156 ( const struct V_387 * V_401 , const struct V_387 * V_402 ,
struct V_387 * V_403 , unsigned int V_404 )
{
if ( V_404 & V_405 ) V_403 -> V_392 = V_322 ( V_401 -> V_392 , V_402 -> V_392 ) ;
if ( V_404 & V_406 ) V_403 -> V_393 = V_322 ( V_401 -> V_393 , V_402 -> V_393 ) ;
if ( V_404 & V_407 ) V_403 -> V_394 = V_322 ( V_401 -> V_394 , V_402 -> V_394 ) ;
if ( V_404 & V_408 ) V_403 -> V_395 = V_322 ( V_401 -> V_395 , V_402 -> V_395 ) ;
if ( V_404 & V_409 ) V_403 -> V_396 = V_322 ( V_401 -> V_396 , V_402 -> V_396 ) ;
if ( V_404 & V_410 ) V_403 -> V_397 = V_322 ( V_401 -> V_397 , V_402 -> V_397 ) ;
if ( V_404 & V_411 ) V_403 -> V_398 = V_322 ( V_401 -> V_398 , V_402 -> V_398 ) ;
if ( V_404 & V_412 ) V_403 -> V_399 = V_322 ( V_401 -> V_399 , V_402 -> V_399 ) ;
if ( V_404 & V_413 ) V_403 -> V_400 = V_322 ( V_401 -> V_400 , V_402 -> V_400 ) ;
}
const struct V_387 * F_157 ( T_2 V_134 )
{
const struct V_387 * V_388 = V_387 ;
while ( V_134 > V_388 -> V_7 )
V_388 ++ ;
if ( V_134 == V_388 -> V_7 )
return V_388 ;
F_158 ( true , L_111 ,
V_259 , V_134 ) ;
return NULL ;
}
int F_159 ( struct V_14 * V_245 , unsigned short V_414 ,
struct V_387 * V_388 , int V_390 , int V_391 )
{
const T_4 * V_143 = V_245 -> V_143 ;
const struct V_387 * V_144 ;
struct V_387 V_148 ;
if ( ! ( V_144 = F_157 ( V_414 ) ) )
return - V_119 ;
memcpy ( V_388 , V_144 , sizeof( * V_144 ) ) ;
if ( V_143 [ V_185 ] & 2 ) {
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
if ( V_414 >= V_368 && V_414 < V_415 ) {
if ( V_414 <= V_251 )
V_148 . V_399 = V_148 . V_395 = V_143 [ V_252 ] ;
else if ( ( V_414 <= V_416 ) ||
( V_414 == V_249 && ! F_62 ( V_143 ) ) )
V_148 . V_399 = V_148 . V_395 = V_143 [ V_417 ] ;
} else if ( V_414 >= V_418 && V_414 <= V_419 )
V_148 . V_399 = V_143 [ V_420 ] ;
F_156 ( & V_148 , V_388 , V_388 , V_412 | V_408 ) ;
}
F_154 ( V_388 , V_388 , V_390 , V_391 ) ;
if ( V_414 > V_250 ) {
F_159 ( V_245 , V_245 -> V_248 , & V_148 , V_390 , V_391 ) ;
F_156 ( & V_148 , V_388 , V_388 , V_421 ) ;
}
if ( V_388 -> V_393 + V_388 -> V_394 < V_388 -> V_395 ) {
V_388 -> V_393 += ( V_388 -> V_395 - ( V_388 -> V_393 + V_388 -> V_394 ) ) / 2 ;
V_388 -> V_394 = V_388 -> V_395 - V_388 -> V_393 ;
}
if ( V_388 -> V_396 + V_388 -> V_397 < V_388 -> V_399 ) {
V_388 -> V_396 += ( V_388 -> V_399 - ( V_388 -> V_396 + V_388 -> V_397 ) ) / 2 ;
V_388 -> V_397 = V_388 -> V_399 - V_388 -> V_396 ;
}
if ( V_388 -> V_396 + V_388 -> V_397 > V_388 -> V_399 )
V_388 -> V_399 = V_388 -> V_396 + V_388 -> V_397 ;
return 0 ;
}
T_2 F_160 ( unsigned int V_422 , int V_399 )
{
T_2 V_423 = 0xff , V_424 = 0xff ;
const struct V_128 * V_129 ;
const struct V_387 * V_388 ;
for ( V_129 = V_130 ; V_129 -> V_131 >= 0 ; V_129 ++ )
if ( V_129 -> V_131 == V_422 )
V_423 = V_129 -> V_133 ;
for ( V_388 = F_157 ( V_423 ) ;
V_388 && F_35 ( V_388 -> V_7 ) == V_422 ; V_388 ++ ) {
unsigned short V_425 ;
switch ( V_422 ) {
case V_121 :
case V_123 :
V_425 = V_388 -> V_399 ;
break;
case V_125 :
V_425 = V_388 -> V_400 ;
break;
default:
return 0xff ;
}
if ( V_399 > V_425 )
break;
V_424 = V_388 -> V_7 ;
}
return V_424 ;
}
int F_143 ( struct V_14 * V_15 , unsigned int V_426 )
{
char V_243 [ 32 ] ;
unsigned long V_427 , V_47 ;
unsigned long V_44 , V_45 , V_46 ;
int V_428 , V_127 ;
V_428 = ! ! ( V_426 & V_429 ) ;
V_426 &= ~ V_429 ;
V_47 = V_427 = F_31 ( V_15 -> V_44 ,
V_15 -> V_45 ,
V_15 -> V_46 ) ;
F_16 ( V_47 , & V_44 , & V_45 , & V_46 ) ;
switch ( V_426 ) {
case V_375 :
V_127 = F_33 ( V_44 ) - 1 ;
V_44 &= ~ ( 1 << V_127 ) ;
break;
case V_430 :
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
case V_431 :
V_46 &= V_432 ;
break;
case V_433 :
V_44 &= 1 ;
case V_434 :
V_45 = 0 ;
V_46 = 0 ;
break;
default:
F_70 () ;
}
V_47 &= F_31 ( V_44 , V_45 , V_46 ) ;
if ( ! ( V_47 & V_122 ) || V_47 == V_427 )
return - V_268 ;
if ( ! V_428 ) {
if ( V_47 & ( V_124 | V_126 ) )
snprintf ( V_243 , sizeof( V_243 ) , L_112 ,
F_36 ( V_47 ) ,
F_36 ( V_47 & V_122 ) ) ;
else
snprintf ( V_243 , sizeof( V_243 ) , L_113 ,
F_36 ( V_47 ) ) ;
F_24 ( V_15 , L_114 , V_243 ) ;
}
F_16 ( V_47 , & V_15 -> V_44 , & V_15 -> V_45 ,
& V_15 -> V_46 ) ;
return 0 ;
}
static int F_161 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_172 * V_173 = & V_15 -> V_3 -> V_174 ;
const bool V_435 = V_15 -> V_48 & V_436 ;
const char * V_437 = L_67 ;
int V_438 = 0 ;
unsigned int V_158 = 0 ;
int V_181 ;
V_15 -> V_42 &= ~ V_92 ;
if ( V_15 -> V_422 == V_121 )
V_15 -> V_42 |= V_92 ;
if ( V_435 && V_5 -> V_42 & V_439 && F_107 ( V_15 -> V_143 ) )
V_437 = L_115 ;
else {
if ( V_435 )
F_24 ( V_15 ,
L_116
L_117 ) ;
V_158 = F_162 ( V_15 ) ;
}
if ( V_158 & ~ V_163 )
goto V_373;
V_173 -> V_25 . V_42 |= V_440 ;
V_181 = F_163 ( V_15 , V_142 , 0 ) ;
V_173 -> V_25 . V_42 &= ~ V_440 ;
if ( V_181 )
return V_181 ;
if ( V_15 -> V_422 == V_121 ) {
if ( F_62 ( V_15 -> V_143 ) )
V_438 = 1 ;
if ( F_101 ( V_15 -> V_143 ) == 0 &&
V_15 -> V_248 <= V_251 )
V_438 = 1 ;
if ( ! F_91 ( V_15 -> V_143 ) && V_15 -> V_248 <= V_251 )
V_438 = 1 ;
}
if ( V_15 -> V_422 == V_123 &&
V_15 -> V_369 == V_418 &&
( V_15 -> V_143 [ 63 ] >> 8 ) & 1 )
V_438 = 1 ;
if ( V_15 -> V_134 == F_32 ( F_61 ( V_15 -> V_143 ) ) )
V_438 = 1 ;
if ( V_158 & V_163 ) {
if ( ! V_438 )
goto V_373;
else
V_437 = L_118 ;
}
F_30 ( L_119 ,
V_15 -> V_422 , ( int ) V_15 -> V_134 ) ;
F_57 ( V_15 , L_120 ,
F_36 ( F_34 ( V_15 -> V_134 ) ) ,
V_437 ) ;
return 0 ;
V_373:
F_59 ( V_15 , L_121 , V_158 ) ;
return - V_166 ;
}
int F_164 ( struct V_2 * V_3 , struct V_14 * * V_441 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_14 * V_15 ;
int V_181 = 0 , V_442 = 0 , V_443 = 0 ;
F_140 (dev, link, ENABLED) {
unsigned long V_44 , V_444 ;
unsigned int V_445 ;
V_445 = V_446 ;
if ( V_15 -> V_182 == V_139 )
V_445 = V_447 ;
else if ( F_62 ( V_15 -> V_143 ) )
V_445 = V_448 ;
F_165 ( V_15 ) ;
F_15 ( V_15 ) ;
V_44 = F_31 ( V_15 -> V_44 , 0 , 0 ) ;
if ( V_449 & V_445 )
V_444 = F_31 ( 0 , V_15 -> V_45 ,
V_15 -> V_46 ) ;
else
V_444 = 0 ;
V_15 -> V_248 = F_32 ( V_44 ) ;
V_15 -> V_369 = F_32 ( V_444 ) ;
V_443 = 1 ;
if ( F_166 ( V_15 ) )
V_442 = 1 ;
}
if ( ! V_443 )
goto V_450;
F_140 (dev, link, ENABLED) {
if ( V_15 -> V_248 == 0xff ) {
F_24 ( V_15 , L_122 ) ;
V_181 = - V_119 ;
goto V_450;
}
V_15 -> V_134 = V_15 -> V_248 ;
V_15 -> V_422 = V_121 ;
if ( V_5 -> V_214 -> V_370 )
V_5 -> V_214 -> V_370 ( V_5 , V_15 ) ;
}
F_140 (dev, link, ENABLED) {
if ( ! F_166 ( V_15 ) )
continue;
V_15 -> V_134 = V_15 -> V_369 ;
V_15 -> V_422 = F_35 ( V_15 -> V_369 ) ;
if ( V_5 -> V_214 -> V_451 )
V_5 -> V_214 -> V_451 ( V_5 , V_15 ) ;
}
F_140 (dev, link, ENABLED) {
V_181 = F_161 ( V_15 ) ;
if ( V_181 )
goto V_450;
}
if ( V_442 && ( V_5 -> V_273 -> V_42 & V_452 ) )
V_5 -> V_273 -> V_453 = V_5 ;
V_450:
if ( V_181 )
* V_441 = V_15 ;
return V_181 ;
}
int F_167 ( struct V_2 * V_3 , unsigned long V_454 ,
int (* F_168)( struct V_2 * V_3 ) )
{
unsigned long V_455 = V_456 ;
unsigned long V_457 ;
int V_458 = 0 ;
if ( V_3 -> V_5 -> V_273 -> V_42 & V_459 )
V_457 = F_169 ( V_455 , V_460 ) ;
else
V_457 = F_169 ( V_455 , V_461 ) ;
F_87 ( V_3 == V_3 -> V_5 -> V_12 ) ;
if ( F_170 ( V_457 , V_454 ) )
V_457 = V_454 ;
while ( 1 ) {
unsigned long V_462 = V_456 ;
int V_463 , V_377 ;
V_463 = V_377 = F_168 ( V_3 ) ;
if ( V_463 > 0 )
return 0 ;
if ( V_463 == - V_263 ) {
if ( F_171 ( V_3 ) )
V_463 = 0 ;
else if ( ( V_3 -> V_5 -> V_42 & V_439 ) &&
! F_172 ( V_3 ) &&
F_173 ( V_462 , V_457 ) )
V_463 = 0 ;
}
if ( V_463 )
return V_463 ;
if ( F_170 ( V_462 , V_454 ) )
return - V_464 ;
if ( ! V_458 && F_170 ( V_462 , V_455 + 5 * V_465 ) &&
( V_454 - V_462 > 3 * V_465 ) ) {
F_149 ( V_3 ,
L_123
L_124 , V_377 ) ;
V_458 = 1 ;
}
F_174 ( V_3 -> V_5 , 50 ) ;
}
}
int F_175 ( struct V_2 * V_3 , unsigned long V_454 ,
int (* F_168)( struct V_2 * V_3 ) )
{
F_174 ( V_3 -> V_5 , V_466 ) ;
return F_167 ( V_3 , V_454 , F_168 ) ;
}
int F_176 ( struct V_2 * V_3 , const unsigned long * V_467 ,
unsigned long V_454 )
{
unsigned long V_468 = V_467 [ 0 ] ;
unsigned long V_469 = V_467 [ 1 ] ;
unsigned long V_470 , V_388 ;
T_1 V_471 , V_472 ;
int V_181 ;
V_388 = F_169 ( V_456 , V_467 [ 2 ] ) ;
if ( F_173 ( V_388 , V_454 ) )
V_454 = V_388 ;
if ( ( V_181 = F_127 ( V_3 , V_378 , & V_472 ) ) )
return V_181 ;
V_472 &= 0xf ;
V_471 = V_472 ;
V_470 = V_456 ;
while ( 1 ) {
F_174 ( V_3 -> V_5 , V_468 ) ;
if ( ( V_181 = F_127 ( V_3 , V_378 , & V_472 ) ) )
return V_181 ;
V_472 &= 0xf ;
if ( V_472 == V_471 ) {
if ( V_472 == 1 && F_173 ( V_456 , V_454 ) )
continue;
if ( F_170 ( V_456 ,
F_169 ( V_470 , V_469 ) ) )
return 0 ;
continue;
}
V_471 = V_472 ;
V_470 = V_456 ;
if ( F_170 ( V_456 , V_454 ) )
return - V_473 ;
}
}
int F_177 ( struct V_2 * V_3 , const unsigned long * V_467 ,
unsigned long V_454 )
{
int V_366 = V_474 ;
T_1 V_376 , V_475 ;
int V_181 ;
if ( ( V_181 = F_127 ( V_3 , V_379 , & V_376 ) ) )
return V_181 ;
do {
V_376 = ( V_376 & 0x0f0 ) | 0x300 ;
if ( ( V_181 = F_153 ( V_3 , V_379 , V_376 ) ) )
return V_181 ;
F_174 ( V_3 -> V_5 , 200 ) ;
if ( ( V_181 = F_127 ( V_3 , V_379 , & V_376 ) ) )
return V_181 ;
} while ( ( V_376 & 0xf0f ) != 0x300 && -- V_366 );
if ( ( V_376 & 0xf0f ) != 0x300 ) {
F_149 ( V_3 , L_125 ,
V_376 ) ;
return 0 ;
}
if ( V_366 < V_474 )
F_149 ( V_3 , L_126 ,
V_474 - V_366 ) ;
if ( ( V_181 = F_176 ( V_3 , V_467 , V_454 ) ) )
return V_181 ;
if ( ! ( V_181 = F_127 ( V_3 , V_476 , & V_475 ) ) )
V_181 = F_153 ( V_3 , V_476 , V_475 ) ;
return V_181 != - V_119 ? V_181 : 0 ;
}
int F_178 ( struct V_2 * V_3 , enum V_477 V_478 ,
bool V_479 )
{
struct V_172 * V_173 = & V_3 -> V_174 ;
bool V_480 = false ;
T_1 V_376 ;
int V_181 ;
V_181 = F_127 ( V_3 , V_379 , & V_376 ) ;
if ( V_181 )
return V_181 ;
switch ( V_478 ) {
case V_481 :
V_376 |= ( 0x7 << 8 ) ;
if ( V_479 ) {
V_376 |= ( 0x4 << 12 ) ;
V_480 = true ;
}
break;
case V_482 :
V_376 &= ~ ( 0x1 << 8 ) ;
V_376 |= ( 0x6 << 8 ) ;
break;
case V_483 :
if ( F_179 ( V_3 ) > 0 )
V_376 &= ~ ( 0x7 << 8 ) ;
else {
V_376 &= ~ 0xf ;
V_376 |= ( 0x1 << 2 ) ;
}
break;
default:
F_87 ( 1 ) ;
}
V_181 = F_153 ( V_3 , V_379 , V_376 ) ;
if ( V_181 )
return V_181 ;
if ( V_480 )
F_180 ( 10 ) ;
V_173 -> V_25 . V_475 &= ~ V_484 ;
return F_153 ( V_3 , V_476 , V_484 ) ;
}
int F_181 ( struct V_2 * V_3 , unsigned long V_454 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_172 * V_173 = & V_3 -> V_174 ;
const unsigned long * V_485 = F_182 ( V_173 ) ;
int V_181 ;
if ( V_173 -> V_25 . V_486 & V_487 )
return 0 ;
if ( V_5 -> V_42 & V_439 ) {
V_181 = F_177 ( V_3 , V_485 , V_454 ) ;
if ( V_181 && V_181 != - V_383 )
F_149 ( V_3 ,
L_127 ,
V_181 ) ;
}
if ( F_183 ( V_3 ) )
V_173 -> V_25 . V_486 &= ~ V_488 ;
return 0 ;
}
int F_184 ( struct V_2 * V_3 , const unsigned long * V_485 ,
unsigned long V_454 ,
bool * V_489 , int (* F_168)( struct V_2 * ) )
{
T_1 V_376 ;
int V_181 ;
F_30 ( L_128 ) ;
if ( V_489 )
* V_489 = false ;
if ( F_151 ( V_3 ) ) {
if ( ( V_181 = F_127 ( V_3 , V_379 , & V_376 ) ) )
goto V_450;
V_376 = ( V_376 & 0x0f0 ) | 0x304 ;
if ( ( V_181 = F_153 ( V_3 , V_379 , V_376 ) ) )
goto V_450;
F_152 ( V_3 ) ;
}
if ( ( V_181 = F_127 ( V_3 , V_379 , & V_376 ) ) )
goto V_450;
V_376 = ( V_376 & 0x0f0 ) | 0x301 ;
if ( ( V_181 = F_185 ( V_3 , V_379 , V_376 ) ) )
goto V_450;
F_174 ( V_3 -> V_5 , 1 ) ;
V_181 = F_177 ( V_3 , V_485 , V_454 ) ;
if ( V_181 )
goto V_450;
if ( F_183 ( V_3 ) )
goto V_450;
if ( V_489 )
* V_489 = true ;
if ( F_186 ( V_3 -> V_5 ) && F_13 ( V_3 ) ) {
if ( F_168 ) {
unsigned long V_490 ;
V_490 = F_169 ( V_456 ,
V_491 ) ;
if ( F_170 ( V_490 , V_454 ) )
V_490 = V_454 ;
F_167 ( V_3 , V_490 , F_168 ) ;
}
V_181 = - V_283 ;
goto V_450;
}
V_181 = 0 ;
if ( F_168 )
V_181 = F_167 ( V_3 , V_454 , F_168 ) ;
V_450:
if ( V_181 && V_181 != - V_283 ) {
if ( V_489 )
* V_489 = false ;
F_187 ( V_3 , L_129 , V_181 ) ;
}
F_30 ( L_130 , V_181 ) ;
return V_181 ;
}
int F_188 ( struct V_2 * V_3 , unsigned int * V_182 ,
unsigned long V_454 )
{
const unsigned long * V_485 = F_182 ( & V_3 -> V_174 ) ;
bool V_489 ;
int V_181 ;
V_181 = F_184 ( V_3 , V_485 , V_454 , & V_489 , NULL ) ;
return V_489 ? - V_283 : V_181 ;
}
void F_189 ( struct V_2 * V_3 , unsigned int * V_364 )
{
T_1 V_475 ;
F_30 ( L_128 ) ;
if ( ! F_127 ( V_3 , V_476 , & V_475 ) )
F_153 ( V_3 , V_476 , V_475 ) ;
F_144 ( V_3 ) ;
F_30 ( L_131 ) ;
}
static int F_190 ( struct V_14 * V_15 , unsigned int V_492 ,
const T_4 * V_493 )
{
const T_4 * V_494 = V_15 -> V_143 ;
unsigned char V_495 [ 2 ] [ V_311 + 1 ] ;
unsigned char V_496 [ 2 ] [ V_497 + 1 ] ;
if ( V_15 -> V_182 != V_492 ) {
F_57 ( V_15 , L_132 ,
V_15 -> V_182 , V_492 ) ;
return 0 ;
}
F_41 ( V_494 , V_495 [ 0 ] , V_320 , sizeof( V_495 [ 0 ] ) ) ;
F_41 ( V_493 , V_495 [ 1 ] , V_320 , sizeof( V_495 [ 1 ] ) ) ;
F_41 ( V_494 , V_496 [ 0 ] , V_498 , sizeof( V_496 [ 0 ] ) ) ;
F_41 ( V_493 , V_496 [ 1 ] , V_498 , sizeof( V_496 [ 1 ] ) ) ;
if ( strcmp ( V_495 [ 0 ] , V_495 [ 1 ] ) ) {
F_57 ( V_15 , L_133 ,
V_495 [ 0 ] , V_495 [ 1 ] ) ;
return 0 ;
}
if ( strcmp ( V_496 [ 0 ] , V_496 [ 1 ] ) ) {
F_57 ( V_15 , L_134 ,
V_496 [ 0 ] , V_496 [ 1 ] ) ;
return 0 ;
}
return 1 ;
}
int F_58 ( struct V_14 * V_15 , unsigned int V_499 )
{
unsigned int V_182 = V_15 -> V_182 ;
T_4 * V_143 = ( void * ) V_15 -> V_3 -> V_5 -> V_303 ;
int V_181 ;
V_181 = F_94 ( V_15 , & V_182 , V_499 , V_143 ) ;
if ( V_181 )
return V_181 ;
if ( ! F_190 ( V_15 , V_182 , V_143 ) )
return - V_263 ;
memcpy ( V_15 -> V_143 , V_143 , sizeof( V_143 [ 0 ] ) * V_253 ) ;
return 0 ;
}
int F_163 ( struct V_14 * V_15 , unsigned int V_492 ,
unsigned int V_499 )
{
T_3 V_317 = V_15 -> V_317 ;
T_3 V_184 = V_15 -> V_184 ;
int V_181 ;
if ( ! F_8 ( V_15 ) )
return - V_263 ;
if ( F_191 ( V_492 ) &&
V_492 != V_138 &&
V_492 != V_139 &&
V_492 != V_141 ) {
F_57 ( V_15 , L_135 ,
V_15 -> V_182 , V_492 ) ;
V_181 = - V_263 ;
goto V_373;
}
V_181 = F_58 ( V_15 , V_499 ) ;
if ( V_181 )
goto V_373;
V_181 = F_115 ( V_15 ) ;
if ( V_181 )
goto V_373;
if ( V_15 -> V_182 != V_138 || ! V_317 ||
V_15 -> V_317 == V_317 )
return 0 ;
F_24 ( V_15 , L_136 ,
( unsigned long long ) V_317 ,
( unsigned long long ) V_15 -> V_317 ) ;
if ( V_15 -> V_184 == V_184 &&
V_15 -> V_317 > V_317 && V_15 -> V_317 == V_184 ) {
F_24 ( V_15 ,
L_137
L_138 ) ;
return 0 ;
}
if ( V_15 -> V_184 == V_184 &&
V_15 -> V_317 < V_317 && V_317 == V_184 &&
! ( V_15 -> V_48 & V_183 ) ) {
F_24 ( V_15 ,
L_139
L_140 ) ;
V_15 -> V_42 |= V_179 ;
V_181 = - V_166 ;
} else
V_181 = - V_263 ;
V_15 -> V_184 = V_184 ;
V_15 -> V_317 = V_317 ;
V_373:
F_59 ( V_15 , L_141 , V_181 ) ;
return V_181 ;
}
static int F_192 ( const char * V_500 , const char * V_501 )
{
do {
if ( * V_500 == * V_501 || * V_501 == '?' ) {
if ( ! * V_501 ++ )
return 0 ;
} else {
if ( ! * V_500 || * V_501 != '[' )
break;
while ( * ++ V_501 && * V_501 != ']' && * V_500 != * V_501 ) {
if ( * V_501 == '-' && * ( V_501 - 1 ) != '[' )
if ( * V_500 > * ( V_501 - 1 ) && * V_500 < * ( V_501 + 1 ) ) {
++ V_501 ;
break;
}
}
if ( ! * V_501 || * V_501 == ']' )
return 1 ;
while ( * V_501 && * V_501 ++ != ']' ) ;
}
} while ( * ++ V_500 && * V_501 );
if ( * V_501 == '*' ) {
if ( ! * ++ V_501 )
return 0 ;
while ( * V_500 ) {
if ( F_192 ( V_500 , V_501 ) == 0 )
return 0 ;
++ V_500 ;
}
}
if ( ! * V_500 && ! * V_501 )
return 0 ;
return 1 ;
}
static unsigned long F_106 ( const struct V_14 * V_15 )
{
unsigned char V_502 [ V_311 + 1 ] ;
unsigned char V_503 [ V_309 + 1 ] ;
const struct V_504 * V_505 = V_506 ;
F_41 ( V_15 -> V_143 , V_502 , V_320 , sizeof( V_502 ) ) ;
F_41 ( V_15 -> V_143 , V_503 , V_319 , sizeof( V_503 ) ) ;
while ( V_505 -> V_502 ) {
if ( ! F_192 ( V_502 , V_505 -> V_502 ) ) {
if ( V_505 -> V_503 == NULL )
return V_505 -> V_48 ;
if ( ! F_192 ( V_503 , V_505 -> V_503 ) )
return V_505 -> V_48 ;
}
V_505 ++ ;
}
return 0 ;
}
static int F_193 ( const struct V_14 * V_15 )
{
if ( ( V_15 -> V_3 -> V_5 -> V_42 & V_507 ) &&
( V_15 -> V_42 & V_345 ) )
return 1 ;
return ( V_15 -> V_48 & V_508 ) ? 1 : 0 ;
}
static int F_194 ( struct V_14 * V_15 )
{
if ( V_15 -> V_48 & V_509 )
return F_195 ( V_15 -> V_143 ) ;
return F_196 ( V_15 -> V_143 ) ;
}
static int F_197 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
struct V_14 * V_15 ;
if ( V_5 -> V_33 == V_360 )
return 1 ;
if ( V_5 -> V_33 == V_361 || V_5 -> V_33 == V_285 )
return 0 ;
if ( V_5 -> V_33 == V_510 )
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
struct V_511 * V_273 = V_5 -> V_273 ;
unsigned long V_47 ;
V_47 = F_31 ( V_5 -> V_44 ,
V_5 -> V_45 , V_5 -> V_46 ) ;
V_47 &= F_31 ( V_15 -> V_44 ,
V_15 -> V_45 , V_15 -> V_46 ) ;
V_47 &= F_61 ( V_15 -> V_143 ) ;
if ( F_147 ( V_15 ) ) {
V_47 &= ~ ( 0x03 << ( V_121 + 5 ) ) ;
V_47 &= ~ ( 0x03 << ( V_123 + 3 ) ) ;
}
if ( F_193 ( V_15 ) ) {
V_47 &= ~ ( V_124 | V_126 ) ;
F_24 ( V_15 ,
L_142 ) ;
}
if ( ( V_273 -> V_42 & V_452 ) &&
V_273 -> V_453 && V_273 -> V_453 != V_5 ) {
V_47 &= ~ ( V_124 | V_126 ) ;
F_24 ( V_15 ,
L_143 ) ;
}
if ( V_5 -> V_42 & V_247 )
V_47 &= F_92 ( V_15 ) ;
if ( V_5 -> V_214 -> V_512 )
V_47 = V_5 -> V_214 -> V_512 ( V_15 , V_47 ) ;
if ( V_47 & ( 0xF8 << V_125 ) )
if ( F_197 ( V_5 ) ) {
F_24 ( V_15 ,
L_144 ) ;
V_47 &= ~ ( 0xF8 << V_125 ) ;
}
F_16 ( V_47 , & V_15 -> V_44 ,
& V_15 -> V_45 , & V_15 -> V_46 ) ;
}
static unsigned int F_162 ( struct V_14 * V_15 )
{
struct V_67 V_68 ;
unsigned int V_158 ;
F_30 ( L_145 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_513 ;
V_68 . V_72 = V_514 ;
V_68 . V_42 |= V_109 | V_110 | V_265 ;
V_68 . V_93 = V_161 ;
if ( F_90 ( V_15 ) )
V_68 . V_80 = V_15 -> V_134 ;
else if ( F_91 ( V_15 -> V_143 ) )
V_68 . V_80 = 0x01 ;
else
return 0 ;
V_158 = F_53 ( V_15 , & V_68 , NULL , V_162 , NULL , 0 , 0 ) ;
F_30 ( L_146 , V_158 ) ;
return V_158 ;
}
unsigned int F_100 ( struct V_14 * V_15 , T_2 V_515 , T_2 V_72 )
{
struct V_67 V_68 ;
unsigned int V_158 ;
F_30 ( L_147 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_513 ;
V_68 . V_72 = V_515 ;
V_68 . V_42 |= V_109 | V_110 ;
V_68 . V_93 = V_161 ;
V_68 . V_80 = V_72 ;
V_158 = F_53 ( V_15 , & V_68 , NULL , V_162 , NULL , 0 , 0 ) ;
F_30 ( L_146 , V_158 ) ;
return V_158 ;
}
static unsigned int F_102 ( struct V_14 * V_15 ,
T_4 V_104 , T_4 V_105 )
{
struct V_67 V_68 ;
unsigned int V_158 ;
if ( V_105 < 1 || V_105 > 255 || V_104 < 1 || V_104 > 16 )
return V_516 ;
F_30 ( L_148 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_517 ;
V_68 . V_42 |= V_109 | V_110 ;
V_68 . V_93 = V_161 ;
V_68 . V_80 = V_105 ;
V_68 . V_21 |= ( V_104 - 1 ) & 0x0f ;
V_158 = F_53 ( V_15 , & V_68 , NULL , V_162 , NULL , 0 , 0 ) ;
if ( V_158 == V_163 && ( V_68 . V_72 & V_164 ) )
V_158 = 0 ;
F_30 ( L_146 , V_158 ) ;
return V_158 ;
}
void F_199 ( struct V_193 * V_194 )
{
struct V_4 * V_5 = V_194 -> V_5 ;
struct V_200 * V_230 = V_194 -> V_230 ;
int V_518 = V_194 -> V_199 ;
F_200 ( V_230 == NULL ) ;
F_201 ( L_149 , V_194 -> V_202 ) ;
if ( V_194 -> V_202 )
F_202 ( V_5 -> V_15 , V_230 , V_194 -> V_519 , V_518 ) ;
V_194 -> V_42 &= ~ V_520 ;
V_194 -> V_230 = NULL ;
}
int F_203 ( struct V_193 * V_194 )
{
struct V_4 * V_5 = V_194 -> V_5 ;
if ( ! ( V_194 -> V_15 -> V_48 & V_521 ) &&
F_5 ( V_194 -> V_232 & 15 ) )
return 1 ;
if ( V_5 -> V_214 -> V_522 )
return V_5 -> V_214 -> V_522 ( V_194 ) ;
return 0 ;
}
int F_204 ( struct V_193 * V_194 )
{
struct V_2 * V_3 = V_194 -> V_15 -> V_3 ;
if ( V_194 -> V_68 . V_93 == V_113 ) {
if ( ! F_205 ( V_3 -> V_218 ) )
return 0 ;
} else {
if ( ! F_205 ( V_3 -> V_218 ) && ! V_3 -> V_219 )
return 0 ;
}
return V_523 ;
}
void F_206 ( struct V_193 * V_194 ) { }
void F_74 ( struct V_193 * V_194 , struct V_200 * V_230 ,
unsigned int V_202 )
{
V_194 -> V_230 = V_230 ;
V_194 -> V_202 = V_202 ;
V_194 -> V_524 = V_194 -> V_230 ;
}
static int F_207 ( struct V_193 * V_194 )
{
struct V_4 * V_5 = V_194 -> V_5 ;
unsigned int V_202 ;
F_201 ( L_150 , V_5 -> V_31 ) ;
V_202 = F_208 ( V_5 -> V_15 , V_194 -> V_230 , V_194 -> V_202 , V_194 -> V_199 ) ;
if ( V_202 < 1 )
return - 1 ;
F_30 ( L_151 , V_202 ) ;
V_194 -> V_519 = V_194 -> V_202 ;
V_194 -> V_202 = V_202 ;
V_194 -> V_42 |= V_520 ;
return 0 ;
}
void F_98 ( T_4 * V_243 , unsigned int V_525 )
{
#ifdef F_209
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < V_525 ; V_25 ++ )
V_243 [ V_25 ] = F_210 ( V_243 [ V_25 ] ) ;
#endif
}
static struct V_193 * F_211 ( struct V_4 * V_5 )
{
struct V_193 * V_194 = NULL ;
unsigned int V_25 ;
if ( F_5 ( V_5 -> V_211 & V_212 ) )
return NULL ;
for ( V_25 = 0 ; V_25 < V_295 - 1 ; V_25 ++ )
if ( ! F_69 ( V_25 , & V_5 -> V_216 ) ) {
V_194 = F_71 ( V_5 , V_25 ) ;
break;
}
if ( V_194 )
V_194 -> V_108 = V_25 ;
return V_194 ;
}
struct V_193 * F_212 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_193 * V_194 ;
V_194 = F_211 ( V_5 ) ;
if ( V_194 ) {
V_194 -> V_217 = NULL ;
V_194 -> V_5 = V_5 ;
V_194 -> V_15 = V_15 ;
F_72 ( V_194 ) ;
}
return V_194 ;
}
void F_85 ( struct V_193 * V_194 )
{
struct V_4 * V_5 ;
unsigned int V_108 ;
F_200 ( V_194 == NULL ) ;
V_5 = V_194 -> V_5 ;
V_194 -> V_42 = 0 ;
V_108 = V_194 -> V_108 ;
if ( F_27 ( F_205 ( V_108 ) ) ) {
V_194 -> V_108 = V_222 ;
F_213 ( V_108 , & V_5 -> V_216 ) ;
}
}
void F_214 ( struct V_193 * V_194 )
{
struct V_4 * V_5 ;
struct V_2 * V_3 ;
F_200 ( V_194 == NULL ) ;
F_200 ( ! ( V_194 -> V_42 & V_235 ) ) ;
V_5 = V_194 -> V_5 ;
V_3 = V_194 -> V_15 -> V_3 ;
if ( F_27 ( V_194 -> V_42 & V_520 ) )
F_199 ( V_194 ) ;
if ( V_194 -> V_68 . V_93 == V_113 ) {
V_3 -> V_219 &= ~ ( 1 << V_194 -> V_108 ) ;
if ( ! V_3 -> V_219 )
V_5 -> V_221 -- ;
} else {
V_3 -> V_218 = V_222 ;
V_5 -> V_221 -- ;
}
if ( F_5 ( V_194 -> V_42 & V_526 &&
V_5 -> V_527 == V_3 ) )
V_5 -> V_527 = NULL ;
V_194 -> V_42 &= ~ V_235 ;
V_5 -> V_220 &= ~ ( 1 << V_194 -> V_108 ) ;
V_194 -> V_233 ( V_194 ) ;
}
static void F_215 ( struct V_193 * V_194 )
{
struct V_4 * V_5 = V_194 -> V_5 ;
V_194 -> V_239 . V_42 = V_194 -> V_68 . V_42 ;
V_5 -> V_214 -> V_528 ( V_194 ) ;
}
static void F_216 ( struct V_193 * V_194 )
{
struct V_14 * V_15 = V_194 -> V_15 ;
if ( F_217 ( V_194 -> V_68 . V_93 ) )
return;
if ( ( V_15 -> V_45 || V_15 -> V_46 ) && F_218 ( V_194 -> V_68 . V_93 ) )
return;
V_15 -> V_42 &= ~ V_529 ;
}
void F_83 ( struct V_193 * V_194 )
{
struct V_4 * V_5 = V_194 -> V_5 ;
if ( V_5 -> V_214 -> V_215 ) {
struct V_14 * V_15 = V_194 -> V_15 ;
struct V_530 * V_531 = & V_15 -> V_3 -> V_532 ;
if ( F_5 ( V_194 -> V_158 ) )
V_194 -> V_42 |= V_238 ;
if ( F_5 ( F_219 ( V_194 -> V_108 ) ) ) {
F_215 ( V_194 ) ;
F_214 ( V_194 ) ;
return;
}
if ( F_5 ( V_194 -> V_42 & V_238 ) ) {
F_215 ( V_194 ) ;
F_220 ( V_194 ) ;
return;
}
F_200 ( V_5 -> V_211 & V_212 ) ;
if ( V_194 -> V_42 & V_228 )
F_215 ( V_194 ) ;
switch ( V_194 -> V_68 . V_71 ) {
case V_513 :
if ( V_194 -> V_68 . V_72 != V_533 &&
V_194 -> V_68 . V_72 != V_534 )
break;
case V_517 :
case V_535 :
V_531 -> V_536 [ V_15 -> V_24 ] |= V_537 ;
F_221 ( V_5 ) ;
break;
case V_538 :
V_15 -> V_42 |= V_539 ;
break;
}
if ( F_5 ( V_15 -> V_42 & V_529 ) )
F_216 ( V_194 ) ;
F_214 ( V_194 ) ;
} else {
if ( V_194 -> V_42 & V_540 )
return;
if ( V_194 -> V_158 || V_194 -> V_42 & V_228 )
F_215 ( V_194 ) ;
F_214 ( V_194 ) ;
}
}
int F_222 ( struct V_4 * V_5 , T_1 V_220 )
{
int V_541 = 0 ;
T_1 V_542 ;
V_542 = V_5 -> V_220 ^ V_220 ;
if ( F_5 ( V_542 & V_220 ) ) {
F_223 ( V_5 , L_152 ,
V_5 -> V_220 , V_220 ) ;
return - V_119 ;
}
while ( V_542 ) {
struct V_193 * V_194 ;
unsigned int V_108 = F_224 ( V_542 ) ;
V_194 = F_225 ( V_5 , V_108 ) ;
if ( V_194 ) {
F_83 ( V_194 ) ;
V_541 ++ ;
}
V_542 &= ~ ( 1 << V_108 ) ;
}
return V_541 ;
}
void F_75 ( struct V_193 * V_194 )
{
struct V_4 * V_5 = V_194 -> V_5 ;
struct V_2 * V_3 = V_194 -> V_15 -> V_3 ;
T_2 V_543 = V_194 -> V_68 . V_93 ;
F_200 ( V_5 -> V_214 -> V_215 && F_205 ( V_3 -> V_218 ) ) ;
if ( F_226 ( V_543 ) ) {
F_200 ( V_3 -> V_219 & ( 1 << V_194 -> V_108 ) ) ;
if ( ! V_3 -> V_219 )
V_5 -> V_221 ++ ;
V_3 -> V_219 |= 1 << V_194 -> V_108 ;
} else {
F_200 ( V_3 -> V_219 ) ;
V_5 -> V_221 ++ ;
V_3 -> V_218 = V_194 -> V_108 ;
}
V_194 -> V_42 |= V_235 ;
V_5 -> V_220 |= 1 << V_194 -> V_108 ;
if ( F_200 ( F_227 ( V_543 ) &&
( ! V_194 -> V_230 || ! V_194 -> V_202 || ! V_194 -> V_232 ) ) )
goto V_544;
if ( F_228 ( V_543 ) || ( F_218 ( V_543 ) &&
( V_5 -> V_42 & V_545 ) ) )
if ( F_207 ( V_194 ) )
goto V_544;
if ( F_5 ( V_194 -> V_15 -> V_42 & V_539 ) ) {
V_3 -> V_532 . V_486 |= V_546 ;
F_229 ( & V_3 -> V_532 , L_153 ) ;
F_230 ( V_3 ) ;
return;
}
V_5 -> V_214 -> V_547 ( V_194 ) ;
V_194 -> V_158 |= V_5 -> V_214 -> V_548 ( V_194 ) ;
if ( F_5 ( V_194 -> V_158 ) )
goto V_549;
return;
V_544:
V_194 -> V_158 |= V_213 ;
V_549:
F_83 ( V_194 ) ;
}
int F_104 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
return ( V_5 -> V_42 & V_439 ) && V_5 -> V_214 -> V_550 ;
}
int F_127 ( struct V_2 * V_3 , int V_551 , T_1 * V_552 )
{
if ( F_13 ( V_3 ) ) {
if ( F_104 ( V_3 ) )
return V_3 -> V_5 -> V_214 -> V_550 ( V_3 , V_551 , V_552 ) ;
return - V_383 ;
}
return F_231 ( V_3 , V_551 , V_552 ) ;
}
int F_153 ( struct V_2 * V_3 , int V_551 , T_1 V_552 )
{
if ( F_13 ( V_3 ) ) {
if ( F_104 ( V_3 ) )
return V_3 -> V_5 -> V_214 -> V_553 ( V_3 , V_551 , V_552 ) ;
return - V_383 ;
}
return F_232 ( V_3 , V_551 , V_552 ) ;
}
int F_185 ( struct V_2 * V_3 , int V_551 , T_1 V_552 )
{
if ( F_13 ( V_3 ) ) {
int V_181 ;
if ( F_104 ( V_3 ) ) {
V_181 = V_3 -> V_5 -> V_214 -> V_553 ( V_3 , V_551 , V_552 ) ;
if ( V_181 == 0 )
V_181 = V_3 -> V_5 -> V_214 -> V_550 ( V_3 , V_551 , & V_552 ) ;
return V_181 ;
}
return - V_383 ;
}
return F_232 ( V_3 , V_551 , V_552 ) ;
}
bool F_145 ( struct V_2 * V_3 )
{
T_1 V_1 ;
if ( F_127 ( V_3 , V_378 , & V_1 ) == 0 &&
F_1 ( V_1 ) )
return true ;
return false ;
}
bool F_183 ( struct V_2 * V_3 )
{
T_1 V_1 ;
if ( F_127 ( V_3 , V_378 , & V_1 ) == 0 &&
! F_1 ( V_1 ) )
return true ;
return false ;
}
bool F_171 ( struct V_2 * V_3 )
{
struct V_2 * V_554 = V_3 -> V_5 -> V_12 ;
F_87 ( V_3 == V_554 ) ;
return F_145 ( V_3 ) ||
( V_554 && F_145 ( V_554 ) ) ;
}
bool F_172 ( struct V_2 * V_3 )
{
struct V_2 * V_554 = V_3 -> V_5 -> V_12 ;
F_87 ( V_3 == V_554 ) ;
return F_183 ( V_3 ) &&
( ! V_554 || F_183 ( V_554 ) ) ;
}
static int F_233 ( struct V_4 * V_5 , T_6 V_555 ,
unsigned int V_486 , unsigned int V_556 ,
int * V_557 )
{
struct V_2 * V_3 ;
unsigned long V_42 ;
int V_181 = 0 ;
if ( V_5 -> V_211 & V_558 ) {
if ( V_557 ) {
* V_557 = - V_283 ;
return 0 ;
}
F_234 ( V_5 ) ;
F_87 ( V_5 -> V_211 & V_558 ) ;
}
F_67 ( V_5 -> V_210 , V_42 ) ;
V_5 -> V_559 = V_555 ;
if ( V_557 )
V_5 -> V_560 = V_557 ;
else
V_5 -> V_560 = & V_181 ;
V_5 -> V_211 |= V_558 ;
F_198 (link, ap, HOST_FIRST) {
V_3 -> V_532 . V_486 |= V_486 ;
V_3 -> V_532 . V_42 |= V_556 ;
}
F_221 ( V_5 ) ;
F_68 ( V_5 -> V_210 , V_42 ) ;
if ( ! V_557 ) {
F_234 ( V_5 ) ;
F_87 ( V_5 -> V_211 & V_558 ) ;
}
return V_181 ;
}
static int F_235 ( struct V_4 * V_5 , T_6 V_555 , int * V_557 )
{
unsigned int V_556 = V_561 | V_562 |
V_563 ;
return F_233 ( V_5 , V_555 , 0 , V_556 , V_557 ) ;
}
static int F_236 ( struct V_21 * V_15 , T_6 V_555 )
{
struct V_4 * V_5 = F_237 ( V_15 ) ;
return F_235 ( V_5 , V_555 , NULL ) ;
}
static int F_238 ( struct V_21 * V_15 )
{
if ( F_239 ( V_15 ) )
return 0 ;
return F_236 ( V_15 , V_564 ) ;
}
static int F_240 ( struct V_21 * V_15 )
{
if ( F_239 ( V_15 ) )
return 0 ;
return F_236 ( V_15 , V_565 ) ;
}
static int F_241 ( struct V_21 * V_15 )
{
return F_236 ( V_15 , V_566 ) ;
}
static int F_242 ( struct V_4 * V_5 , T_6 V_555 ,
int * V_557 )
{
int V_181 ;
V_181 = F_233 ( V_5 , V_555 , V_546 ,
V_562 | V_561 , V_557 ) ;
return V_181 ;
}
static int F_243 ( struct V_21 * V_15 , T_6 V_555 )
{
struct V_4 * V_5 = F_237 ( V_15 ) ;
return F_242 ( V_5 , V_555 , NULL ) ;
}
static int F_244 ( struct V_21 * V_15 )
{
int V_181 ;
V_181 = F_243 ( V_15 , V_567 ) ;
if ( ! V_181 ) {
F_245 ( V_15 ) ;
F_246 ( V_15 ) ;
F_247 ( V_15 ) ;
}
return V_181 ;
}
static int F_248 ( struct V_21 * V_15 )
{
struct V_4 * V_5 = F_237 ( V_15 ) ;
struct V_2 * V_3 ;
struct V_14 * V_245 ;
F_198 (link, ap, HOST_FIRST) {
F_140 (adev, link, ENABLED)
if ( V_245 -> V_182 == V_139 &&
! F_249 ( V_245 ) )
return - V_464 ;
}
return 0 ;
}
static int F_250 ( struct V_21 * V_15 )
{
return F_236 ( V_15 , V_568 ) ;
}
static int F_251 ( struct V_21 * V_15 )
{
return F_243 ( V_15 , V_569 ) ;
}
int F_252 ( struct V_4 * V_5 , int * V_557 )
{
return F_235 ( V_5 , V_564 , V_557 ) ;
}
int F_253 ( struct V_4 * V_5 , int * V_557 )
{
return F_242 ( V_5 , V_567 , V_557 ) ;
}
int F_254 ( struct V_511 * V_273 , T_6 V_555 )
{
V_273 -> V_15 -> V_570 . V_571 = V_555 ;
return 0 ;
}
void F_255 ( struct V_511 * V_273 )
{
V_273 -> V_15 -> V_570 . V_571 = V_572 ;
}
void F_256 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = F_9 ( V_15 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_42 ;
V_3 -> V_281 = V_3 -> V_40 ;
V_3 -> V_282 = 0 ;
F_67 ( V_5 -> V_210 , V_42 ) ;
V_15 -> V_42 &= ~ V_573 ;
V_15 -> V_48 = 0 ;
F_68 ( V_5 -> V_210 , V_42 ) ;
memset ( ( void * ) V_15 + V_574 , 0 ,
V_575 - V_574 ) ;
V_15 -> V_44 = V_386 ;
V_15 -> V_45 = V_386 ;
V_15 -> V_46 = V_386 ;
}
void F_257 ( struct V_4 * V_5 , struct V_2 * V_3 , int V_38 )
{
int V_25 ;
memset ( ( void * ) V_3 + V_576 , 0 ,
V_577 - V_576 ) ;
V_3 -> V_5 = V_5 ;
V_3 -> V_38 = V_38 ;
V_3 -> V_218 = V_222 ;
V_3 -> V_40 = V_386 ;
for ( V_25 = 0 ; V_25 < V_365 ; V_25 ++ ) {
struct V_14 * V_15 = & V_3 -> V_21 [ V_25 ] ;
V_15 -> V_3 = V_3 ;
V_15 -> V_24 = V_15 - V_3 -> V_21 ;
#ifdef F_258
V_15 -> V_578 = V_579 ;
#endif
F_256 ( V_15 ) ;
}
}
int F_259 ( struct V_2 * V_3 )
{
T_2 V_136 ;
int V_181 ;
V_181 = F_127 ( V_3 , V_379 , & V_3 -> V_580 ) ;
if ( V_181 )
return V_181 ;
V_136 = ( V_3 -> V_580 >> 4 ) & 0xf ;
if ( V_136 )
V_3 -> V_40 &= ( 1 << V_136 ) - 1 ;
F_12 ( V_3 ) ;
V_3 -> V_281 = V_3 -> V_40 ;
return 0 ;
}
struct V_4 * F_260 ( struct V_511 * V_273 )
{
struct V_4 * V_5 ;
F_30 ( L_128 ) ;
V_5 = F_261 ( sizeof( * V_5 ) , V_581 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_211 |= V_582 | V_212 ;
V_5 -> V_210 = & V_273 -> V_210 ;
V_5 -> V_31 = - 1 ;
V_5 -> V_583 = - 1 ;
V_5 -> V_273 = V_273 ;
V_5 -> V_15 = V_273 -> V_15 ;
#if F_262 ( V_584 )
V_5 -> V_585 = 0x00FF ;
#elif F_262 ( V_586 )
V_5 -> V_585 = V_587 | V_588 | V_589 | V_590 | V_591 ;
#else
V_5 -> V_585 = V_587 | V_591 | V_590 ;
#endif
F_263 ( & V_5 -> V_592 ) ;
F_264 ( & V_5 -> V_593 , V_594 ) ;
F_265 ( & V_5 -> V_595 , V_596 ) ;
F_266 ( & V_5 -> V_597 ) ;
F_267 ( & V_5 -> V_598 ) ;
F_268 ( & V_5 -> V_599 ) ;
F_269 ( & V_5 -> V_600 ) ;
V_5 -> V_600 . V_601 = V_602 ;
V_5 -> V_600 . V_603 = ( unsigned long ) V_5 ;
V_5 -> V_33 = V_34 ;
F_257 ( V_5 , & V_5 -> V_3 , 0 ) ;
#ifdef F_270
V_5 -> V_604 . V_605 = 1 ;
V_5 -> V_604 . V_606 = 1 ;
#endif
F_271 ( V_5 ) ;
return V_5 ;
}
static void F_272 ( struct V_21 * V_607 , void * V_608 )
{
struct V_511 * V_273 = F_273 ( V_607 ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_273 -> V_609 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_610 [ V_25 ] ;
if ( ! V_5 )
continue;
if ( V_5 -> V_293 )
F_274 ( V_5 -> V_293 ) ;
F_275 ( V_5 -> V_11 ) ;
F_275 ( V_5 -> V_12 ) ;
F_275 ( V_5 ) ;
V_273 -> V_610 [ V_25 ] = NULL ;
}
F_276 ( V_607 , NULL ) ;
}
struct V_511 * F_277 ( struct V_21 * V_15 , int V_611 )
{
struct V_511 * V_273 ;
T_5 V_612 ;
int V_25 ;
F_30 ( L_128 ) ;
if ( ! F_278 ( V_15 , NULL , V_581 ) )
return NULL ;
V_612 = sizeof( struct V_511 ) + ( V_611 + 1 ) * sizeof( void * ) ;
V_273 = F_279 ( F_272 , V_612 , V_581 ) ;
if ( ! V_273 )
goto V_264;
F_280 ( V_15 , V_273 ) ;
F_276 ( V_15 , V_273 ) ;
F_281 ( & V_273 -> V_210 ) ;
F_263 ( & V_273 -> V_613 ) ;
V_273 -> V_15 = V_15 ;
V_273 -> V_609 = V_611 ;
for ( V_25 = 0 ; V_25 < V_611 ; V_25 ++ ) {
struct V_4 * V_5 ;
V_5 = F_260 ( V_273 ) ;
if ( ! V_5 )
goto V_264;
V_5 -> V_614 = V_25 ;
V_273 -> V_610 [ V_25 ] = V_5 ;
}
F_282 ( V_15 , NULL ) ;
return V_273 ;
V_264:
F_283 ( V_15 , NULL ) ;
return NULL ;
}
struct V_511 * F_284 ( struct V_21 * V_15 ,
const struct V_615 * const * V_616 ,
int V_609 )
{
const struct V_615 * V_617 ;
struct V_511 * V_273 ;
int V_25 , V_328 ;
V_273 = F_277 ( V_15 , V_609 ) ;
if ( ! V_273 )
return NULL ;
for ( V_25 = 0 , V_328 = 0 , V_617 = NULL ; V_25 < V_273 -> V_609 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_610 [ V_25 ] ;
if ( V_616 [ V_328 ] )
V_617 = V_616 [ V_328 ++ ] ;
V_5 -> V_44 = V_617 -> V_44 ;
V_5 -> V_45 = V_617 -> V_45 ;
V_5 -> V_46 = V_617 -> V_46 ;
V_5 -> V_42 |= V_617 -> V_42 ;
V_5 -> V_3 . V_42 |= V_617 -> V_618 ;
V_5 -> V_214 = V_617 -> V_619 ;
if ( ! V_273 -> V_214 && ( V_617 -> V_619 != & V_620 ) )
V_273 -> V_214 = V_617 -> V_619 ;
}
return V_273 ;
}
int F_285 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
F_87 ( V_5 -> V_12 ) ;
F_87 ( V_5 -> V_42 & V_621 ) ;
V_3 = F_261 ( sizeof( * V_3 ) , V_581 ) ;
if ( ! V_3 )
return - V_622 ;
F_257 ( V_5 , V_3 , 1 ) ;
V_5 -> V_12 = V_3 ;
return 0 ;
}
static void F_286 ( struct V_21 * V_607 , void * V_608 )
{
struct V_511 * V_273 = F_273 ( V_607 ) ;
int V_25 ;
F_87 ( ! ( V_273 -> V_42 & V_623 ) ) ;
for ( V_25 = 0 ; V_25 < V_273 -> V_609 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_610 [ V_25 ] ;
if ( V_5 -> V_214 -> V_624 )
V_5 -> V_214 -> V_624 ( V_5 ) ;
}
if ( V_273 -> V_214 -> V_625 )
V_273 -> V_214 -> V_625 ( V_273 ) ;
}
static void F_287 ( struct V_626 * V_214 )
{
static F_288 ( V_210 ) ;
const struct V_626 * V_472 ;
void * * V_627 = ( void * * ) V_214 ;
void * * V_628 = ( void * * ) & V_214 -> V_629 ;
void * * V_630 ;
if ( ! V_214 || ! V_214 -> V_629 )
return;
F_289 ( & V_210 ) ;
for ( V_472 = V_214 -> V_629 ; V_472 ; V_472 = V_472 -> V_629 ) {
void * * V_631 = ( void * * ) V_472 ;
for ( V_630 = V_627 ; V_630 < V_628 ; V_630 ++ , V_631 ++ )
if ( ! * V_630 )
* V_630 = * V_631 ;
}
for ( V_630 = V_627 ; V_630 < V_628 ; V_630 ++ )
if ( F_290 ( * V_630 ) )
* V_630 = NULL ;
V_214 -> V_629 = NULL ;
F_291 ( & V_210 ) ;
}
int F_292 ( struct V_511 * V_273 )
{
int V_632 = 0 ;
void * V_633 = NULL ;
int V_25 , V_181 ;
if ( V_273 -> V_42 & V_623 )
return 0 ;
F_287 ( V_273 -> V_214 ) ;
for ( V_25 = 0 ; V_25 < V_273 -> V_609 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_610 [ V_25 ] ;
F_287 ( V_5 -> V_214 ) ;
if ( ! V_273 -> V_214 && ! F_293 ( V_5 ) )
V_273 -> V_214 = V_5 -> V_214 ;
if ( V_5 -> V_214 -> V_624 )
V_632 = 1 ;
}
if ( V_273 -> V_214 -> V_625 )
V_632 = 1 ;
if ( V_632 ) {
V_633 = F_279 ( F_286 , 0 , V_581 ) ;
if ( ! V_633 )
return - V_622 ;
}
for ( V_25 = 0 ; V_25 < V_273 -> V_609 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_610 [ V_25 ] ;
if ( V_5 -> V_214 -> V_634 ) {
V_181 = V_5 -> V_214 -> V_634 ( V_5 ) ;
if ( V_181 ) {
if ( V_181 != - V_263 )
F_294 ( V_273 -> V_15 ,
L_154 ,
V_25 , V_181 ) ;
goto V_264;
}
}
F_295 ( V_5 ) ;
}
if ( V_633 )
F_280 ( V_273 -> V_15 , V_633 ) ;
V_273 -> V_42 |= V_623 ;
return 0 ;
V_264:
while ( -- V_25 >= 0 ) {
struct V_4 * V_5 = V_273 -> V_610 [ V_25 ] ;
if ( V_5 -> V_214 -> V_624 )
V_5 -> V_214 -> V_624 ( V_5 ) ;
}
F_296 ( V_633 ) ;
return V_181 ;
}
void F_297 ( struct V_511 * V_273 , struct V_21 * V_15 ,
struct V_626 * V_214 )
{
F_281 ( & V_273 -> V_210 ) ;
F_263 ( & V_273 -> V_613 ) ;
V_273 -> V_15 = V_15 ;
V_273 -> V_214 = V_214 ;
}
void F_298 ( struct V_4 * V_5 )
{
struct V_530 * V_531 = & V_5 -> V_3 . V_532 ;
unsigned long V_42 ;
F_67 ( V_5 -> V_210 , V_42 ) ;
V_531 -> V_635 |= V_636 ;
V_531 -> V_486 |= V_546 ;
V_531 -> V_42 |= V_562 | V_561 ;
V_5 -> V_211 &= ~ V_582 ;
V_5 -> V_211 |= V_637 ;
F_221 ( V_5 ) ;
F_68 ( V_5 -> V_210 , V_42 ) ;
}
int F_299 ( struct V_4 * V_5 )
{
int V_181 = 0 ;
if ( V_5 -> V_214 -> V_215 ) {
F_298 ( V_5 ) ;
F_234 ( V_5 ) ;
} else {
F_30 ( L_155 , V_5 -> V_31 ) ;
V_181 = F_139 ( V_5 ) ;
F_30 ( L_156 , V_5 -> V_31 ) ;
}
return V_181 ;
}
static void F_300 ( void * V_603 , T_7 V_638 )
{
struct V_4 * V_5 = V_603 ;
if ( ! ( V_5 -> V_273 -> V_42 & V_459 ) && V_5 -> V_614 != 0 )
F_301 ( V_638 ) ;
( void ) F_299 ( V_5 ) ;
F_301 ( V_638 ) ;
F_302 ( V_5 , 1 ) ;
}
int F_303 ( struct V_511 * V_273 , struct V_639 * V_640 )
{
int V_25 , V_181 ;
if ( ! ( V_273 -> V_42 & V_623 ) ) {
F_294 ( V_273 -> V_15 , L_157 ) ;
F_87 ( 1 ) ;
return - V_119 ;
}
for ( V_25 = V_273 -> V_609 ; V_273 -> V_610 [ V_25 ] ; V_25 ++ )
F_275 ( V_273 -> V_610 [ V_25 ] ) ;
for ( V_25 = 0 ; V_25 < V_273 -> V_609 ; V_25 ++ ) {
V_273 -> V_610 [ V_25 ] -> V_31 = F_304 ( & V_641 ) ;
V_273 -> V_610 [ V_25 ] -> V_583 = V_25 + 1 ;
}
for ( V_25 = 0 ; V_25 < V_273 -> V_609 ; V_25 ++ ) {
V_181 = F_305 ( V_273 -> V_15 , V_273 -> V_610 [ V_25 ] ) ;
if ( V_181 ) {
goto V_642;
}
}
V_181 = F_306 ( V_273 , V_640 ) ;
if ( V_181 )
goto V_642;
for ( V_25 = 0 ; V_25 < V_273 -> V_609 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_610 [ V_25 ] ;
unsigned long V_47 ;
if ( V_5 -> V_33 == V_34 && ( V_5 -> V_42 & V_439 ) )
V_5 -> V_33 = V_285 ;
F_259 ( & V_5 -> V_3 ) ;
if ( V_5 -> V_12 )
F_259 ( V_5 -> V_12 ) ;
V_47 = F_31 ( V_5 -> V_44 , V_5 -> V_45 ,
V_5 -> V_46 ) ;
if ( ! F_293 ( V_5 ) ) {
V_615 ( V_5 , L_158 ,
( V_5 -> V_42 & V_439 ) ? 'S' : 'P' ,
F_36 ( V_47 ) ,
V_5 -> V_3 . V_532 . V_286 ) ;
F_307 ( & V_5 -> V_3 . V_532 ) ;
} else
V_615 ( V_5 , L_159 ) ;
}
for ( V_25 = 0 ; V_25 < V_273 -> V_609 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_610 [ V_25 ] ;
F_308 ( F_300 , V_5 ) ;
}
return 0 ;
V_642:
while ( -- V_25 >= 0 ) {
F_309 ( V_273 -> V_610 [ V_25 ] ) ;
}
return V_181 ;
}
int F_310 ( struct V_511 * V_273 , int V_643 ,
T_8 V_644 , unsigned long V_645 ,
struct V_639 * V_640 )
{
int V_25 , V_181 ;
V_181 = F_292 ( V_273 ) ;
if ( V_181 )
return V_181 ;
if ( ! V_643 ) {
F_87 ( V_644 ) ;
return F_303 ( V_273 , V_640 ) ;
}
V_181 = F_311 ( V_273 -> V_15 , V_643 , V_644 , V_645 ,
F_312 ( V_273 -> V_15 ) , V_273 ) ;
if ( V_181 )
return V_181 ;
for ( V_25 = 0 ; V_25 < V_273 -> V_609 ; V_25 ++ )
F_313 ( V_273 -> V_610 [ V_25 ] , L_160 , V_643 ) ;
V_181 = F_303 ( V_273 , V_640 ) ;
if ( V_181 )
F_314 ( V_273 -> V_15 , V_643 , V_273 ) ;
return V_181 ;
}
static void F_315 ( struct V_4 * V_5 )
{
unsigned long V_42 ;
if ( ! V_5 -> V_214 -> V_215 )
goto V_646;
F_67 ( V_5 -> V_210 , V_42 ) ;
V_5 -> V_211 |= V_647 ;
F_221 ( V_5 ) ;
F_68 ( V_5 -> V_210 , V_42 ) ;
F_234 ( V_5 ) ;
F_87 ( ! ( V_5 -> V_211 & V_648 ) ) ;
F_316 ( & V_5 -> V_593 ) ;
V_646:
if ( V_5 -> V_11 ) {
int V_25 ;
for ( V_25 = 0 ; V_25 < V_649 ; V_25 ++ )
F_317 ( & V_5 -> V_11 [ V_25 ] ) ;
}
F_309 ( V_5 ) ;
F_318 ( V_5 -> V_293 ) ;
}
void F_319 ( struct V_511 * V_273 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_273 -> V_609 ; V_25 ++ )
F_315 ( V_273 -> V_610 [ V_25 ] ) ;
F_320 ( V_273 ) ;
}
void F_321 ( struct V_650 * V_651 )
{
struct V_511 * V_273 = F_322 ( V_651 ) ;
F_319 ( V_273 ) ;
}
int F_323 ( struct V_650 * V_651 , const struct V_652 * V_132 )
{
unsigned long V_377 = 0 ;
switch ( V_132 -> V_653 ) {
case 1 : {
T_2 V_654 = 0 ;
F_324 ( V_651 , V_132 -> V_551 , & V_654 ) ;
V_377 = V_654 ;
break;
}
case 2 : {
T_4 V_655 = 0 ;
F_325 ( V_651 , V_132 -> V_551 , & V_655 ) ;
V_377 = V_655 ;
break;
}
case 4 : {
T_1 V_656 = 0 ;
F_326 ( V_651 , V_132 -> V_551 , & V_656 ) ;
V_377 = V_656 ;
break;
}
default:
return - V_119 ;
}
V_377 &= V_132 -> V_381 ;
return ( V_377 == V_132 -> V_552 ) ? 1 : 0 ;
}
void F_327 ( struct V_650 * V_651 , T_6 V_555 )
{
F_328 ( V_651 ) ;
F_329 ( V_651 ) ;
if ( V_555 . V_657 & V_658 )
F_330 ( V_651 , V_659 ) ;
}
int F_331 ( struct V_650 * V_651 )
{
int V_181 ;
F_330 ( V_651 , V_660 ) ;
F_332 ( V_651 ) ;
V_181 = F_333 ( V_651 ) ;
if ( V_181 ) {
F_294 ( & V_651 -> V_15 ,
L_161 , V_181 ) ;
return V_181 ;
}
F_334 ( V_651 ) ;
return 0 ;
}
int F_335 ( struct V_650 * V_651 , T_6 V_555 )
{
struct V_511 * V_273 = F_322 ( V_651 ) ;
int V_181 = 0 ;
V_181 = F_254 ( V_273 , V_555 ) ;
if ( V_181 )
return V_181 ;
F_327 ( V_651 , V_555 ) ;
return 0 ;
}
int F_336 ( struct V_650 * V_651 )
{
struct V_511 * V_273 = F_322 ( V_651 ) ;
int V_181 ;
V_181 = F_331 ( V_651 ) ;
if ( V_181 == 0 )
F_255 ( V_273 ) ;
return V_181 ;
}
int F_337 ( struct V_661 * V_651 )
{
struct V_511 * V_273 = F_338 ( V_651 ) ;
F_319 ( V_273 ) ;
return 0 ;
}
static int T_9 F_339 ( char * * V_472 ,
struct V_27 * V_662 ,
const char * * V_255 )
{
static struct V_663 V_664 [] V_665 = {
{ L_162 , . V_33 = V_360 } ,
{ L_163 , . V_33 = V_361 } ,
{ L_164 , . V_33 = V_510 } ,
{ L_165 , . V_33 = V_362 } ,
{ L_166 , . V_33 = V_363 } ,
{ L_167 , . V_33 = V_285 } ,
{ L_168 , . V_39 = 1 } ,
{ L_169 , . V_39 = 2 } ,
{ L_170 , . V_49 = V_291 } ,
{ L_171 , . V_50 = V_291 } ,
{ L_172 , . V_49 = V_270 } ,
{ L_173 , . V_47 = 1 << ( V_121 + 0 ) } ,
{ L_174 , . V_47 = 1 << ( V_121 + 1 ) } ,
{ L_175 , . V_47 = 1 << ( V_121 + 2 ) } ,
{ L_176 , . V_47 = 1 << ( V_121 + 3 ) } ,
{ L_177 , . V_47 = 1 << ( V_121 + 4 ) } ,
{ L_178 , . V_47 = 1 << ( V_121 + 5 ) } ,
{ L_179 , . V_47 = 1 << ( V_121 + 6 ) } ,
{ L_180 , . V_47 = 1 << ( V_123 + 0 ) } ,
{ L_181 , . V_47 = 1 << ( V_123 + 1 ) } ,
{ L_182 , . V_47 = 1 << ( V_123 + 2 ) } ,
{ L_183 , . V_47 = 1 << ( V_123 + 3 ) } ,
{ L_184 , . V_47 = 1 << ( V_123 + 4 ) } ,
{ L_185 , . V_47 = 1 << ( V_125 + 0 ) } ,
{ L_186 , . V_47 = 1 << ( V_125 + 0 ) } ,
{ L_187 , . V_47 = 1 << ( V_125 + 0 ) } ,
{ L_188 , . V_47 = 1 << ( V_125 + 1 ) } ,
{ L_189 , . V_47 = 1 << ( V_125 + 1 ) } ,
{ L_190 , . V_47 = 1 << ( V_125 + 1 ) } ,
{ L_191 , . V_47 = 1 << ( V_125 + 2 ) } ,
{ L_192 , . V_47 = 1 << ( V_125 + 2 ) } ,
{ L_193 , . V_47 = 1 << ( V_125 + 2 ) } ,
{ L_194 , . V_47 = 1 << ( V_125 + 3 ) } ,
{ L_195 , . V_47 = 1 << ( V_125 + 3 ) } ,
{ L_196 , . V_47 = 1 << ( V_125 + 3 ) } ,
{ L_197 , . V_47 = 1 << ( V_125 + 4 ) } ,
{ L_198 , . V_47 = 1 << ( V_125 + 4 ) } ,
{ L_199 , . V_47 = 1 << ( V_125 + 4 ) } ,
{ L_200 , . V_47 = 1 << ( V_125 + 5 ) } ,
{ L_201 , . V_47 = 1 << ( V_125 + 5 ) } ,
{ L_202 , . V_47 = 1 << ( V_125 + 5 ) } ,
{ L_203 , . V_47 = 1 << ( V_125 + 6 ) } ,
{ L_204 , . V_47 = 1 << ( V_125 + 6 ) } ,
{ L_205 , . V_47 = 1 << ( V_125 + 6 ) } ,
{ L_206 , . V_47 = 1 << ( V_125 + 7 ) } ,
{ L_207 , . V_41 = V_666 } ,
{ L_208 , . V_41 = V_667 } ,
{ L_209 , . V_41 = V_666 | V_667 } ,
{ L_210 , . V_41 = V_668 } ,
{ L_211 , . V_49 = V_347 } ,
} ;
char * V_455 = * V_472 , * V_148 = * V_472 ;
char * V_143 , * V_552 , * V_669 ;
const struct V_663 * V_670 = NULL ;
int V_671 = 0 , V_25 ;
while ( * V_148 != '\0' && * V_148 != ',' )
V_148 ++ ;
if ( * V_148 == '\0' )
* V_472 = V_148 ;
else
* V_472 = V_148 + 1 ;
* V_148 = '\0' ;
V_148 = strchr ( V_455 , ':' ) ;
if ( ! V_148 ) {
V_552 = F_340 ( V_455 ) ;
goto V_672;
}
* V_148 = '\0' ;
V_143 = F_340 ( V_455 ) ;
V_552 = F_340 ( V_148 + 1 ) ;
V_148 = strchr ( V_143 , '.' ) ;
if ( V_148 ) {
* V_148 ++ = '\0' ;
V_662 -> V_21 = F_341 ( V_148 , & V_669 , 10 ) ;
if ( V_148 == V_669 || * V_669 != '\0' ) {
* V_255 = L_212 ;
return - V_119 ;
}
}
V_662 -> V_30 = F_341 ( V_143 , & V_669 , 10 ) ;
if ( V_148 == V_669 || * V_669 != '\0' ) {
* V_255 = L_213 ;
return - V_119 ;
}
V_672:
for ( V_25 = 0 ; V_25 < F_37 ( V_664 ) ; V_25 ++ ) {
const struct V_663 * V_673 = & V_664 [ V_25 ] ;
if ( strncasecmp ( V_552 , V_673 -> V_35 , strlen ( V_552 ) ) )
continue;
V_671 ++ ;
V_670 = V_673 ;
if ( strcasecmp ( V_552 , V_673 -> V_35 ) == 0 ) {
V_671 = 1 ;
break;
}
}
if ( ! V_671 ) {
* V_255 = L_214 ;
return - V_119 ;
}
if ( V_671 > 1 ) {
* V_255 = L_215 ;
return - V_119 ;
}
V_662 -> V_32 = * V_670 ;
return 0 ;
}
static void T_9 F_342 ( void )
{
int V_674 = 0 , V_675 = 1 ;
int V_676 = - 1 , V_677 = - 1 ;
char * V_148 , * V_472 , * V_23 ;
for ( V_148 = V_678 ; * V_148 ; V_148 ++ )
if ( * V_148 == ',' )
V_675 ++ ;
V_29 = F_261 ( sizeof( V_29 [ 0 ] ) * V_675 , V_581 ) ;
if ( ! V_29 ) {
F_343 ( V_679 L_216
L_217 ) ;
return;
}
for ( V_472 = V_678 ; * V_472 != '\0' ; V_472 = V_23 ) {
const char * V_255 = L_67 ;
struct V_27 V_680 = { . V_30 = - 1 , . V_21 = - 1 } ;
V_23 = V_472 ;
if ( F_339 ( & V_23 , & V_680 , & V_255 ) ) {
F_343 ( V_679 L_218
L_219 ,
V_472 , V_255 ) ;
continue;
}
if ( V_680 . V_30 == - 1 ) {
V_680 . V_30 = V_676 ;
V_680 . V_21 = V_677 ;
}
V_29 [ V_674 ++ ] = V_680 ;
V_676 = V_680 . V_30 ;
V_677 = V_680 . V_21 ;
}
V_26 = V_674 ;
}
static int T_9 F_344 ( void )
{
int V_181 ;
F_342 () ;
V_181 = F_345 () ;
if ( V_181 ) {
F_275 ( V_29 ) ;
return V_181 ;
}
F_346 () ;
V_681 = F_347 () ;
if ( ! V_681 ) {
F_348 () ;
V_181 = - V_622 ;
goto V_264;
}
F_343 ( V_271 L_220 V_682 L_221 ) ;
return 0 ;
V_264:
return V_181 ;
}
static void T_10 F_349 ( void )
{
F_350 ( V_681 ) ;
F_351 () ;
F_348 () ;
F_275 ( V_29 ) ;
}
int F_352 ( void )
{
return F_353 ( & V_683 ) ;
}
void F_174 ( struct V_4 * V_5 , unsigned int V_684 )
{
bool V_685 = V_5 && V_5 -> V_273 -> V_686 == V_687 ;
if ( V_685 )
F_77 ( V_5 ) ;
F_180 ( V_684 ) ;
if ( V_685 )
F_80 ( V_5 ) ;
}
T_1 F_354 ( struct V_4 * V_5 , void T_11 * V_551 , T_1 V_381 , T_1 V_552 ,
unsigned long V_468 , unsigned long V_203 )
{
unsigned long V_454 ;
T_1 V_377 ;
V_377 = F_355 ( V_551 ) ;
V_454 = F_169 ( V_456 , V_203 ) ;
while ( ( V_377 & V_381 ) == V_552 && F_173 ( V_456 , V_454 ) ) {
F_174 ( V_5 , V_468 ) ;
V_377 = F_355 ( V_551 ) ;
}
return V_377 ;
}
static unsigned int F_356 ( struct V_193 * V_194 )
{
return V_213 ;
}
static void F_357 ( struct V_4 * V_5 )
{
}
int F_358 ( const struct V_4 * V_5 , const char * V_688 ,
const char * V_689 , ... )
{
struct V_690 V_691 ;
T_12 args ;
int V_692 ;
va_start ( args , V_689 ) ;
V_691 . V_689 = V_689 ;
V_691 . V_693 = & args ;
V_692 = F_343 ( L_222 , V_688 , V_5 -> V_31 , & V_691 ) ;
va_end ( args ) ;
return V_692 ;
}
int F_359 ( const struct V_2 * V_3 , const char * V_688 ,
const char * V_689 , ... )
{
struct V_690 V_691 ;
T_12 args ;
int V_692 ;
va_start ( args , V_689 ) ;
V_691 . V_689 = V_689 ;
V_691 . V_693 = & args ;
if ( F_4 ( V_3 -> V_5 ) || V_3 -> V_5 -> V_12 )
V_692 = F_343 ( L_223 ,
V_688 , V_3 -> V_5 -> V_31 , V_3 -> V_38 , & V_691 ) ;
else
V_692 = F_343 ( L_222 ,
V_688 , V_3 -> V_5 -> V_31 , & V_691 ) ;
va_end ( args ) ;
return V_692 ;
}
int F_360 ( const struct V_14 * V_15 , const char * V_688 ,
const char * V_689 , ... )
{
struct V_690 V_691 ;
T_12 args ;
int V_692 ;
va_start ( args , V_689 ) ;
V_691 . V_689 = V_689 ;
V_691 . V_693 = & args ;
V_692 = F_343 ( L_223 ,
V_688 , V_15 -> V_3 -> V_5 -> V_31 , V_15 -> V_3 -> V_38 + V_15 -> V_24 ,
& V_691 ) ;
va_end ( args ) ;
return V_692 ;
}
void F_361 ( const struct V_21 * V_15 , const char * V_694 )
{
F_362 ( V_271 , V_15 , L_224 , V_694 ) ;
}
