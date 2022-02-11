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
T_2 * V_304 = V_15 -> V_305 ;
V_15 -> V_42 |= V_306 ;
memcpy ( V_304 , V_5 -> V_303 , V_307 ) ;
if ( V_15 -> V_48 & V_308 ) {
F_96 ( V_15 , L_80 ) ;
V_304 [ V_309 ] &=
~ V_310 ;
}
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
char V_311 [ 7 ] ;
char V_312 [ V_313 + 1 ] ;
char V_314 [ V_315 + 1 ] ;
int V_181 ;
if ( ! F_8 ( V_15 ) && F_116 ( V_5 ) ) {
F_57 ( V_15 , L_81 , V_259 ) ;
return 0 ;
}
if ( F_117 ( V_5 ) )
F_96 ( V_15 , L_59 , V_259 ) ;
V_15 -> V_48 |= F_106 ( V_15 ) ;
F_18 ( V_15 ) ;
if ( V_15 -> V_48 & V_316 ) {
F_57 ( V_15 , L_82 ) ;
F_118 ( V_15 ) ;
return 0 ;
}
if ( ( ! V_317 || ( V_5 -> V_42 & V_318 ) ) &&
V_15 -> V_182 == V_139 ) {
F_24 ( V_15 , L_83 ,
V_317 ? L_84
: L_85 ) ;
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
L_86
L_87 ,
V_259 ,
V_143 [ 49 ] , V_143 [ 82 ] , V_143 [ 83 ] , V_143 [ 84 ] ,
V_143 [ 85 ] , V_143 [ 86 ] , V_143 [ 87 ] , V_143 [ 88 ] ) ;
V_15 -> V_42 &= ~ V_319 ;
V_15 -> V_157 = 0 ;
V_15 -> V_320 = 0 ;
V_15 -> V_321 = 0 ;
V_15 -> V_322 = 0 ;
V_15 -> V_104 = 0 ;
V_15 -> V_105 = 0 ;
V_15 -> V_95 = 0 ;
V_47 = F_61 ( V_143 ) ;
if ( F_117 ( V_5 ) )
F_60 ( V_143 ) ;
F_41 ( V_15 -> V_143 , V_312 , V_323 ,
sizeof( V_312 ) ) ;
F_41 ( V_15 -> V_143 , V_314 , V_324 ,
sizeof( V_314 ) ) ;
if ( V_15 -> V_182 == V_138 ) {
if ( F_62 ( V_143 ) ) {
if ( V_143 [ V_325 ] & 1 )
F_24 ( V_15 ,
L_88 ) ;
snprintf ( V_311 , 7 , L_89 ) ;
} else {
snprintf ( V_311 , 7 , L_90 , F_101 ( V_143 ) ) ;
if ( F_120 ( V_143 ) )
F_24 ( V_15 ,
L_88 ) ;
}
V_15 -> V_321 = F_43 ( V_143 ) ;
if ( ( V_15 -> V_143 [ 47 ] >> 8 ) == 0x80 && ( V_15 -> V_143 [ 59 ] & 0x100 ) ) {
unsigned int V_326 = V_15 -> V_143 [ 47 ] & 0xff ;
unsigned int V_327 = V_15 -> V_143 [ 59 ] & 0xff ;
if ( F_121 ( V_326 ) && F_121 ( V_327 ) )
if ( V_327 <= V_326 )
V_15 -> V_95 = V_327 ;
}
if ( F_44 ( V_143 ) ) {
const char * V_328 ;
char V_329 [ 24 ] ;
V_328 = L_91 ;
V_15 -> V_42 |= V_117 ;
if ( F_45 ( V_143 ) ) {
V_15 -> V_42 |= V_118 ;
V_328 = L_92 ;
if ( V_15 -> V_321 >= ( 1UL << 28 ) &&
F_122 ( V_143 ) )
V_15 -> V_42 |= V_330 ;
}
V_181 = F_108 ( V_15 , V_329 , sizeof( V_329 ) ) ;
if ( V_181 )
return V_181 ;
if ( F_123 ( V_5 ) && V_175 ) {
F_57 ( V_15 , L_93 ,
V_311 , V_314 , V_312 ,
F_36 ( V_47 ) ) ;
F_57 ( V_15 ,
L_94 ,
( unsigned long long ) V_15 -> V_321 ,
V_15 -> V_95 , V_328 , V_329 ) ;
}
} else {
V_15 -> V_322 = V_143 [ 1 ] ;
V_15 -> V_104 = V_143 [ 3 ] ;
V_15 -> V_105 = V_143 [ 6 ] ;
if ( F_48 ( V_143 ) ) {
V_15 -> V_322 = V_143 [ 54 ] ;
V_15 -> V_104 = V_143 [ 55 ] ;
V_15 -> V_105 = V_143 [ 56 ] ;
}
if ( F_123 ( V_5 ) && V_175 ) {
F_57 ( V_15 , L_93 ,
V_311 , V_314 , V_312 ,
F_36 ( V_47 ) ) ;
F_57 ( V_15 ,
L_95 ,
( unsigned long long ) V_15 -> V_321 ,
V_15 -> V_95 , V_15 -> V_322 ,
V_15 -> V_104 , V_15 -> V_105 ) ;
}
}
if ( F_124 ( V_15 -> V_143 ) ) {
T_2 * V_331 = V_5 -> V_303 ;
int V_25 , V_332 ;
V_15 -> V_42 |= V_333 ;
V_158 = F_114 ( V_15 ,
V_334 ,
V_335 ,
V_331 ,
1 ) ;
if ( V_158 )
F_96 ( V_15 ,
L_96 ,
V_158 ) ;
else
for ( V_25 = 0 ; V_25 < V_336 ; V_25 ++ ) {
V_332 = V_337 + V_25 ;
V_15 -> V_338 [ V_25 ] = V_331 [ V_332 ] ;
}
}
V_15 -> V_320 = 16 ;
}
else if ( V_15 -> V_182 == V_139 ) {
const char * V_339 = L_67 ;
const char * V_340 = L_67 ;
const char * V_341 = L_67 ;
T_1 V_342 ;
V_181 = F_125 ( V_143 ) ;
if ( ( V_181 < 12 ) || ( V_181 > V_223 ) ) {
if ( F_84 ( V_5 ) )
F_24 ( V_15 , L_97 ) ;
V_181 = - V_119 ;
goto V_343;
}
V_15 -> V_320 = ( unsigned int ) V_181 ;
if ( V_344 &&
( V_5 -> V_42 & V_345 ) && F_126 ( V_143 ) &&
( ! F_4 ( V_5 ) ||
F_127 ( & V_5 -> V_3 , V_346 , & V_342 ) == 0 ) ) {
V_158 = F_100 ( V_15 ,
V_299 , V_347 ) ;
if ( V_158 )
F_59 ( V_15 ,
L_98 ,
V_158 ) ;
else {
V_15 -> V_42 |= V_348 ;
V_340 = L_99 ;
}
}
if ( F_128 ( V_15 -> V_143 ) ) {
V_15 -> V_42 |= V_349 ;
V_339 = L_100 ;
}
if ( V_350 || ( V_15 -> V_48 & V_351 ) || F_129 ( V_15 -> V_143 ) ) {
V_15 -> V_42 |= V_225 ;
V_341 = L_101 ;
}
if ( F_130 ( V_15 -> V_143 ) ) {
V_15 -> V_42 |= V_352 ;
F_131 ( V_15 ) ;
}
if ( F_123 ( V_5 ) && V_175 )
F_57 ( V_15 ,
L_102 ,
V_314 , V_312 ,
F_36 ( V_47 ) ,
V_339 , V_340 ,
V_341 ) ;
}
V_15 -> V_157 = V_353 ;
if ( V_15 -> V_42 & V_118 )
V_15 -> V_157 = V_354 ;
if ( F_105 ( V_15 ) ) {
if ( F_123 ( V_5 ) && V_175 )
F_57 ( V_15 , L_103 ) ;
V_15 -> V_46 &= V_355 ;
V_15 -> V_157 = V_353 ;
}
if ( ( V_15 -> V_182 == V_139 ) &&
( F_132 ( V_143 ) == V_356 ) ) {
V_15 -> V_157 = V_357 ;
V_15 -> V_48 |= V_358 ;
}
if ( V_15 -> V_48 & V_359 )
V_15 -> V_157 = F_133 (unsigned int, ATA_MAX_SECTORS_128,
dev->max_sectors) ;
if ( V_15 -> V_48 & V_360 )
V_15 -> V_157 = V_354 ;
if ( V_5 -> V_214 -> V_361 )
V_5 -> V_214 -> V_361 ( V_15 ) ;
if ( V_15 -> V_48 & V_362 ) {
if ( V_175 ) {
F_24 ( V_15 ,
L_104 ) ;
F_24 ( V_15 ,
L_105 ) ;
}
}
if ( ( V_15 -> V_48 & V_363 ) && V_175 ) {
F_24 ( V_15 , L_106 ) ;
F_24 ( V_15 , L_107 ) ;
}
return 0 ;
V_343:
if ( F_117 ( V_5 ) )
F_96 ( V_15 , L_108 , V_259 ) ;
return V_181 ;
}
int F_134 ( struct V_4 * V_5 )
{
return V_364 ;
}
int F_135 ( struct V_4 * V_5 )
{
return V_365 ;
}
int F_136 ( struct V_4 * V_5 )
{
return V_366 ;
}
int F_137 ( struct V_4 * V_5 )
{
return V_367 ;
}
int F_138 ( struct V_4 * V_5 )
{
return V_285 ;
}
int F_139 ( struct V_4 * V_5 )
{
unsigned int V_368 [ V_369 ] ;
int V_370 [ V_369 ] ;
int V_181 ;
struct V_14 * V_15 ;
F_140 (dev, &ap->link, ALL)
V_370 [ V_15 -> V_24 ] = V_371 ;
V_260:
F_140 (dev, &ap->link, ALL) {
V_15 -> V_248 = V_372 ;
V_15 -> V_373 = 0xff ;
if ( V_5 -> V_214 -> V_374 )
V_5 -> V_214 -> V_374 ( V_5 , V_15 ) ;
}
V_5 -> V_214 -> V_375 ( V_5 ) ;
F_140 (dev, &ap->link, ALL) {
if ( V_15 -> V_182 != V_142 )
V_368 [ V_15 -> V_24 ] = V_15 -> V_182 ;
else
V_368 [ V_15 -> V_24 ] = V_376 ;
V_15 -> V_182 = V_142 ;
}
F_140 (dev, &ap->link, ALL_REVERSE) {
if ( V_370 [ V_15 -> V_24 ] )
V_15 -> V_182 = V_368 [ V_15 -> V_24 ] ;
if ( ! F_8 ( V_15 ) )
continue;
V_181 = F_94 ( V_15 , & V_15 -> V_182 , V_276 ,
V_15 -> V_143 ) ;
if ( V_181 )
goto V_377;
}
if ( V_5 -> V_214 -> V_378 )
V_5 -> V_33 = V_5 -> V_214 -> V_378 ( V_5 ) ;
F_140 (dev, &ap->link, ENABLED)
if ( F_107 ( V_15 -> V_143 ) )
V_5 -> V_33 = V_285 ;
F_140 (dev, &ap->link, ENABLED) {
V_5 -> V_3 . V_174 . V_25 . V_42 |= V_176 ;
V_181 = F_115 ( V_15 ) ;
V_5 -> V_3 . V_174 . V_25 . V_42 &= ~ V_176 ;
if ( V_181 )
goto V_377;
}
V_181 = F_141 ( & V_5 -> V_3 , & V_15 ) ;
if ( V_181 )
goto V_377;
F_140 (dev, &ap->link, ENABLED)
return 0 ;
return - V_263 ;
V_377:
V_370 [ V_15 -> V_24 ] -- ;
switch ( V_181 ) {
case - V_119 :
V_370 [ V_15 -> V_24 ] = 0 ;
break;
case - V_263 :
V_370 [ V_15 -> V_24 ] = F_111 ( V_370 [ V_15 -> V_24 ] , 1 ) ;
case - V_166 :
if ( V_370 [ V_15 -> V_24 ] == 1 ) {
F_142 ( & V_5 -> V_3 , 0 ) ;
F_143 ( V_15 , V_379 ) ;
}
}
if ( ! V_370 [ V_15 -> V_24 ] )
F_118 ( V_15 ) ;
goto V_260;
}
static void F_144 ( struct V_2 * V_3 )
{
T_1 V_1 , V_380 , V_381 ;
if ( F_127 ( V_3 , V_382 , & V_1 ) )
return;
F_127 ( V_3 , V_383 , & V_380 ) ;
if ( F_145 ( V_3 ) ) {
V_381 = ( V_1 >> 4 ) & 0xf ;
F_146 ( V_3 , L_109 ,
F_38 ( V_381 ) , V_1 , V_380 ) ;
} else {
F_146 ( V_3 , L_110 ,
V_1 , V_380 ) ;
}
}
struct V_14 * F_147 ( struct V_14 * V_245 )
{
struct V_2 * V_3 = V_245 -> V_3 ;
struct V_14 * V_384 = & V_3 -> V_21 [ 1 - V_245 -> V_24 ] ;
if ( ! F_8 ( V_384 ) )
return NULL ;
return V_384 ;
}
int F_142 ( struct V_2 * V_3 , T_1 V_39 )
{
T_1 V_1 , V_136 , V_385 ;
int V_181 , V_386 ;
if ( ! F_104 ( V_3 ) )
return - V_387 ;
V_181 = F_127 ( V_3 , V_382 , & V_1 ) ;
if ( V_181 == 0 && F_1 ( V_1 ) )
V_136 = ( V_1 >> 4 ) & 0xf ;
else
V_136 = V_3 -> V_282 ;
V_385 = V_3 -> V_281 ;
if ( V_385 <= 1 )
return - V_119 ;
V_386 = F_33 ( V_385 ) - 1 ;
V_385 &= ~ ( 1 << V_386 ) ;
if ( V_136 > 1 )
V_385 &= ( 1 << ( V_136 - 1 ) ) - 1 ;
else
V_385 &= 1 ;
if ( ! V_385 )
return - V_119 ;
if ( V_39 ) {
if ( V_385 & ( ( 1 << V_39 ) - 1 ) )
V_385 &= ( 1 << V_39 ) - 1 ;
else {
V_386 = F_148 ( V_385 ) - 1 ;
V_385 = 1 << V_386 ;
}
}
V_3 -> V_281 = V_385 ;
F_149 ( V_3 , L_111 ,
F_38 ( F_33 ( V_385 ) ) ) ;
return 0 ;
}
static int F_150 ( struct V_2 * V_3 , T_1 * V_380 )
{
struct V_2 * V_388 = & V_3 -> V_5 -> V_3 ;
T_1 V_389 , V_278 , V_136 ;
V_389 = V_3 -> V_281 ;
if ( ! F_13 ( V_3 ) && V_388 -> V_282 )
V_389 &= ( 1 << V_388 -> V_282 ) - 1 ;
if ( V_389 == V_390 )
V_278 = 0 ;
else
V_278 = F_33 ( V_389 ) ;
V_136 = ( * V_380 >> 4 ) & 0xf ;
* V_380 = ( * V_380 & ~ 0xf0 ) | ( ( V_278 & 0xf ) << 4 ) ;
return V_136 != V_278 ;
}
static int F_151 ( struct V_2 * V_3 )
{
T_1 V_380 ;
if ( F_127 ( V_3 , V_383 , & V_380 ) )
return 1 ;
return F_150 ( V_3 , & V_380 ) ;
}
int F_152 ( struct V_2 * V_3 )
{
T_1 V_380 ;
int V_181 ;
if ( ( V_181 = F_127 ( V_3 , V_383 , & V_380 ) ) )
return V_181 ;
if ( ! F_150 ( V_3 , & V_380 ) )
return 0 ;
if ( ( V_181 = F_153 ( V_3 , V_383 , V_380 ) ) )
return V_181 ;
return 1 ;
}
static void F_154 ( const struct V_391 * V_392 , struct V_391 * V_393 , int V_394 , int V_395 )
{
V_393 -> V_396 = F_155 ( V_392 -> V_396 * 1000 , V_394 ) ;
V_393 -> V_397 = F_155 ( V_392 -> V_397 * 1000 , V_394 ) ;
V_393 -> V_398 = F_155 ( V_392 -> V_398 * 1000 , V_394 ) ;
V_393 -> V_399 = F_155 ( V_392 -> V_399 * 1000 , V_394 ) ;
V_393 -> V_400 = F_155 ( V_392 -> V_400 * 1000 , V_394 ) ;
V_393 -> V_401 = F_155 ( V_392 -> V_401 * 1000 , V_394 ) ;
V_393 -> V_402 = F_155 ( V_392 -> V_402 * 1000 , V_394 ) ;
V_393 -> V_403 = F_155 ( V_392 -> V_403 * 1000 , V_394 ) ;
V_393 -> V_404 = F_155 ( V_392 -> V_404 * 1000 , V_395 ) ;
}
void F_156 ( const struct V_391 * V_405 , const struct V_391 * V_406 ,
struct V_391 * V_407 , unsigned int V_408 )
{
if ( V_408 & V_409 ) V_407 -> V_396 = V_326 ( V_405 -> V_396 , V_406 -> V_396 ) ;
if ( V_408 & V_410 ) V_407 -> V_397 = V_326 ( V_405 -> V_397 , V_406 -> V_397 ) ;
if ( V_408 & V_411 ) V_407 -> V_398 = V_326 ( V_405 -> V_398 , V_406 -> V_398 ) ;
if ( V_408 & V_412 ) V_407 -> V_399 = V_326 ( V_405 -> V_399 , V_406 -> V_399 ) ;
if ( V_408 & V_413 ) V_407 -> V_400 = V_326 ( V_405 -> V_400 , V_406 -> V_400 ) ;
if ( V_408 & V_414 ) V_407 -> V_401 = V_326 ( V_405 -> V_401 , V_406 -> V_401 ) ;
if ( V_408 & V_415 ) V_407 -> V_402 = V_326 ( V_405 -> V_402 , V_406 -> V_402 ) ;
if ( V_408 & V_416 ) V_407 -> V_403 = V_326 ( V_405 -> V_403 , V_406 -> V_403 ) ;
if ( V_408 & V_417 ) V_407 -> V_404 = V_326 ( V_405 -> V_404 , V_406 -> V_404 ) ;
}
const struct V_391 * F_157 ( T_2 V_134 )
{
const struct V_391 * V_392 = V_391 ;
while ( V_134 > V_392 -> V_7 )
V_392 ++ ;
if ( V_134 == V_392 -> V_7 )
return V_392 ;
F_158 ( true , L_112 ,
V_259 , V_134 ) ;
return NULL ;
}
int F_159 ( struct V_14 * V_245 , unsigned short V_418 ,
struct V_391 * V_392 , int V_394 , int V_395 )
{
const T_4 * V_143 = V_245 -> V_143 ;
const struct V_391 * V_144 ;
struct V_391 V_148 ;
if ( ! ( V_144 = F_157 ( V_418 ) ) )
return - V_119 ;
memcpy ( V_392 , V_144 , sizeof( * V_144 ) ) ;
if ( V_143 [ V_185 ] & 2 ) {
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
if ( V_418 >= V_372 && V_418 < V_419 ) {
if ( V_418 <= V_251 )
V_148 . V_403 = V_148 . V_399 = V_143 [ V_252 ] ;
else if ( ( V_418 <= V_420 ) ||
( V_418 == V_249 && ! F_62 ( V_143 ) ) )
V_148 . V_403 = V_148 . V_399 = V_143 [ V_421 ] ;
} else if ( V_418 >= V_422 && V_418 <= V_423 )
V_148 . V_403 = V_143 [ V_424 ] ;
F_156 ( & V_148 , V_392 , V_392 , V_416 | V_412 ) ;
}
F_154 ( V_392 , V_392 , V_394 , V_395 ) ;
if ( V_418 > V_250 ) {
F_159 ( V_245 , V_245 -> V_248 , & V_148 , V_394 , V_395 ) ;
F_156 ( & V_148 , V_392 , V_392 , V_425 ) ;
}
if ( V_392 -> V_397 + V_392 -> V_398 < V_392 -> V_399 ) {
V_392 -> V_397 += ( V_392 -> V_399 - ( V_392 -> V_397 + V_392 -> V_398 ) ) / 2 ;
V_392 -> V_398 = V_392 -> V_399 - V_392 -> V_397 ;
}
if ( V_392 -> V_400 + V_392 -> V_401 < V_392 -> V_403 ) {
V_392 -> V_400 += ( V_392 -> V_403 - ( V_392 -> V_400 + V_392 -> V_401 ) ) / 2 ;
V_392 -> V_401 = V_392 -> V_403 - V_392 -> V_400 ;
}
if ( V_392 -> V_400 + V_392 -> V_401 > V_392 -> V_403 )
V_392 -> V_403 = V_392 -> V_400 + V_392 -> V_401 ;
return 0 ;
}
T_2 F_160 ( unsigned int V_426 , int V_403 )
{
T_2 V_427 = 0xff , V_428 = 0xff ;
const struct V_128 * V_129 ;
const struct V_391 * V_392 ;
for ( V_129 = V_130 ; V_129 -> V_131 >= 0 ; V_129 ++ )
if ( V_129 -> V_131 == V_426 )
V_427 = V_129 -> V_133 ;
for ( V_392 = F_157 ( V_427 ) ;
V_392 && F_35 ( V_392 -> V_7 ) == V_426 ; V_392 ++ ) {
unsigned short V_429 ;
switch ( V_426 ) {
case V_121 :
case V_123 :
V_429 = V_392 -> V_403 ;
break;
case V_125 :
V_429 = V_392 -> V_404 ;
break;
default:
return 0xff ;
}
if ( V_403 > V_429 )
break;
V_428 = V_392 -> V_7 ;
}
return V_428 ;
}
int F_143 ( struct V_14 * V_15 , unsigned int V_430 )
{
char V_243 [ 32 ] ;
unsigned long V_431 , V_47 ;
unsigned long V_44 , V_45 , V_46 ;
int V_432 , V_127 ;
V_432 = ! ! ( V_430 & V_433 ) ;
V_430 &= ~ V_433 ;
V_47 = V_431 = F_31 ( V_15 -> V_44 ,
V_15 -> V_45 ,
V_15 -> V_46 ) ;
F_16 ( V_47 , & V_44 , & V_45 , & V_46 ) ;
switch ( V_430 ) {
case V_379 :
V_127 = F_33 ( V_44 ) - 1 ;
V_44 &= ~ ( 1 << V_127 ) ;
break;
case V_434 :
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
case V_435 :
V_46 &= V_436 ;
break;
case V_437 :
V_44 &= 1 ;
case V_438 :
V_45 = 0 ;
V_46 = 0 ;
break;
default:
F_70 () ;
}
V_47 &= F_31 ( V_44 , V_45 , V_46 ) ;
if ( ! ( V_47 & V_122 ) || V_47 == V_431 )
return - V_268 ;
if ( ! V_432 ) {
if ( V_47 & ( V_124 | V_126 ) )
snprintf ( V_243 , sizeof( V_243 ) , L_113 ,
F_36 ( V_47 ) ,
F_36 ( V_47 & V_122 ) ) ;
else
snprintf ( V_243 , sizeof( V_243 ) , L_114 ,
F_36 ( V_47 ) ) ;
F_24 ( V_15 , L_115 , V_243 ) ;
}
F_16 ( V_47 , & V_15 -> V_44 , & V_15 -> V_45 ,
& V_15 -> V_46 ) ;
return 0 ;
}
static int F_161 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_172 * V_173 = & V_15 -> V_3 -> V_174 ;
const bool V_439 = V_15 -> V_48 & V_440 ;
const char * V_441 = L_67 ;
int V_442 = 0 ;
unsigned int V_158 = 0 ;
int V_181 ;
V_15 -> V_42 &= ~ V_92 ;
if ( V_15 -> V_426 == V_121 )
V_15 -> V_42 |= V_92 ;
if ( V_439 && V_5 -> V_42 & V_443 && F_107 ( V_15 -> V_143 ) )
V_441 = L_116 ;
else {
if ( V_439 )
F_24 ( V_15 ,
L_117
L_118 ) ;
V_158 = F_162 ( V_15 ) ;
}
if ( V_158 & ~ V_163 )
goto V_377;
V_173 -> V_25 . V_42 |= V_444 ;
V_181 = F_163 ( V_15 , V_142 , 0 ) ;
V_173 -> V_25 . V_42 &= ~ V_444 ;
if ( V_181 )
return V_181 ;
if ( V_15 -> V_426 == V_121 ) {
if ( F_62 ( V_15 -> V_143 ) )
V_442 = 1 ;
if ( F_101 ( V_15 -> V_143 ) == 0 &&
V_15 -> V_248 <= V_251 )
V_442 = 1 ;
if ( ! F_91 ( V_15 -> V_143 ) && V_15 -> V_248 <= V_251 )
V_442 = 1 ;
}
if ( V_15 -> V_426 == V_123 &&
V_15 -> V_373 == V_422 &&
( V_15 -> V_143 [ 63 ] >> 8 ) & 1 )
V_442 = 1 ;
if ( V_15 -> V_134 == F_32 ( F_61 ( V_15 -> V_143 ) ) )
V_442 = 1 ;
if ( V_158 & V_163 ) {
if ( ! V_442 )
goto V_377;
else
V_441 = L_119 ;
}
F_30 ( L_120 ,
V_15 -> V_426 , ( int ) V_15 -> V_134 ) ;
F_57 ( V_15 , L_121 ,
F_36 ( F_34 ( V_15 -> V_134 ) ) ,
V_441 ) ;
return 0 ;
V_377:
F_59 ( V_15 , L_122 , V_158 ) ;
return - V_166 ;
}
int F_164 ( struct V_2 * V_3 , struct V_14 * * V_445 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_14 * V_15 ;
int V_181 = 0 , V_446 = 0 , V_447 = 0 ;
F_140 (dev, link, ENABLED) {
unsigned long V_44 , V_448 ;
unsigned int V_449 ;
V_449 = V_450 ;
if ( V_15 -> V_182 == V_139 )
V_449 = V_451 ;
else if ( F_62 ( V_15 -> V_143 ) )
V_449 = V_452 ;
F_165 ( V_15 ) ;
F_15 ( V_15 ) ;
V_44 = F_31 ( V_15 -> V_44 , 0 , 0 ) ;
if ( V_453 & V_449 )
V_448 = F_31 ( 0 , V_15 -> V_45 ,
V_15 -> V_46 ) ;
else
V_448 = 0 ;
V_15 -> V_248 = F_32 ( V_44 ) ;
V_15 -> V_373 = F_32 ( V_448 ) ;
V_447 = 1 ;
if ( F_166 ( V_15 ) )
V_446 = 1 ;
}
if ( ! V_447 )
goto V_454;
F_140 (dev, link, ENABLED) {
if ( V_15 -> V_248 == 0xff ) {
F_24 ( V_15 , L_123 ) ;
V_181 = - V_119 ;
goto V_454;
}
V_15 -> V_134 = V_15 -> V_248 ;
V_15 -> V_426 = V_121 ;
if ( V_5 -> V_214 -> V_374 )
V_5 -> V_214 -> V_374 ( V_5 , V_15 ) ;
}
F_140 (dev, link, ENABLED) {
if ( ! F_166 ( V_15 ) )
continue;
V_15 -> V_134 = V_15 -> V_373 ;
V_15 -> V_426 = F_35 ( V_15 -> V_373 ) ;
if ( V_5 -> V_214 -> V_455 )
V_5 -> V_214 -> V_455 ( V_5 , V_15 ) ;
}
F_140 (dev, link, ENABLED) {
V_181 = F_161 ( V_15 ) ;
if ( V_181 )
goto V_454;
}
if ( V_446 && ( V_5 -> V_273 -> V_42 & V_456 ) )
V_5 -> V_273 -> V_457 = V_5 ;
V_454:
if ( V_181 )
* V_445 = V_15 ;
return V_181 ;
}
int F_167 ( struct V_2 * V_3 , unsigned long V_458 ,
int (* F_168)( struct V_2 * V_3 ) )
{
unsigned long V_459 = V_460 ;
unsigned long V_461 ;
int V_462 = 0 ;
if ( V_3 -> V_5 -> V_273 -> V_42 & V_463 )
V_461 = F_169 ( V_459 , V_464 ) ;
else
V_461 = F_169 ( V_459 , V_465 ) ;
F_87 ( V_3 == V_3 -> V_5 -> V_12 ) ;
if ( F_170 ( V_461 , V_458 ) )
V_461 = V_458 ;
while ( 1 ) {
unsigned long V_466 = V_460 ;
int V_467 , V_381 ;
V_467 = V_381 = F_168 ( V_3 ) ;
if ( V_467 > 0 )
return 0 ;
if ( V_467 == - V_263 ) {
if ( F_171 ( V_3 ) )
V_467 = 0 ;
else if ( ( V_3 -> V_5 -> V_42 & V_443 ) &&
! F_172 ( V_3 ) &&
F_173 ( V_466 , V_461 ) )
V_467 = 0 ;
}
if ( V_467 )
return V_467 ;
if ( F_170 ( V_466 , V_458 ) )
return - V_468 ;
if ( ! V_462 && F_170 ( V_466 , V_459 + 5 * V_469 ) &&
( V_458 - V_466 > 3 * V_469 ) ) {
F_149 ( V_3 ,
L_124
L_125 , V_381 ) ;
V_462 = 1 ;
}
F_174 ( V_3 -> V_5 , 50 ) ;
}
}
int F_175 ( struct V_2 * V_3 , unsigned long V_458 ,
int (* F_168)( struct V_2 * V_3 ) )
{
F_174 ( V_3 -> V_5 , V_470 ) ;
return F_167 ( V_3 , V_458 , F_168 ) ;
}
int F_176 ( struct V_2 * V_3 , const unsigned long * V_471 ,
unsigned long V_458 )
{
unsigned long V_472 = V_471 [ 0 ] ;
unsigned long V_473 = V_471 [ 1 ] ;
unsigned long V_474 , V_392 ;
T_1 V_475 , V_476 ;
int V_181 ;
V_392 = F_169 ( V_460 , V_471 [ 2 ] ) ;
if ( F_173 ( V_392 , V_458 ) )
V_458 = V_392 ;
if ( ( V_181 = F_127 ( V_3 , V_382 , & V_476 ) ) )
return V_181 ;
V_476 &= 0xf ;
V_475 = V_476 ;
V_474 = V_460 ;
while ( 1 ) {
F_174 ( V_3 -> V_5 , V_472 ) ;
if ( ( V_181 = F_127 ( V_3 , V_382 , & V_476 ) ) )
return V_181 ;
V_476 &= 0xf ;
if ( V_476 == V_475 ) {
if ( V_476 == 1 && F_173 ( V_460 , V_458 ) )
continue;
if ( F_170 ( V_460 ,
F_169 ( V_474 , V_473 ) ) )
return 0 ;
continue;
}
V_475 = V_476 ;
V_474 = V_460 ;
if ( F_170 ( V_460 , V_458 ) )
return - V_477 ;
}
}
int F_177 ( struct V_2 * V_3 , const unsigned long * V_471 ,
unsigned long V_458 )
{
int V_370 = V_478 ;
T_1 V_380 , V_479 ;
int V_181 ;
if ( ( V_181 = F_127 ( V_3 , V_383 , & V_380 ) ) )
return V_181 ;
do {
V_380 = ( V_380 & 0x0f0 ) | 0x300 ;
if ( ( V_181 = F_153 ( V_3 , V_383 , V_380 ) ) )
return V_181 ;
F_174 ( V_3 -> V_5 , 200 ) ;
if ( ( V_181 = F_127 ( V_3 , V_383 , & V_380 ) ) )
return V_181 ;
} while ( ( V_380 & 0xf0f ) != 0x300 && -- V_370 );
if ( ( V_380 & 0xf0f ) != 0x300 ) {
F_149 ( V_3 , L_126 ,
V_380 ) ;
return 0 ;
}
if ( V_370 < V_478 )
F_149 ( V_3 , L_127 ,
V_478 - V_370 ) ;
if ( ( V_181 = F_176 ( V_3 , V_471 , V_458 ) ) )
return V_181 ;
if ( ! ( V_181 = F_127 ( V_3 , V_480 , & V_479 ) ) )
V_181 = F_153 ( V_3 , V_480 , V_479 ) ;
return V_181 != - V_119 ? V_181 : 0 ;
}
int F_178 ( struct V_2 * V_3 , enum V_481 V_482 ,
bool V_483 )
{
struct V_172 * V_173 = & V_3 -> V_174 ;
bool V_484 = false ;
T_1 V_380 ;
int V_181 ;
V_181 = F_127 ( V_3 , V_383 , & V_380 ) ;
if ( V_181 )
return V_181 ;
switch ( V_482 ) {
case V_485 :
V_380 |= ( 0x7 << 8 ) ;
if ( V_483 ) {
V_380 |= ( 0x4 << 12 ) ;
V_484 = true ;
}
break;
case V_486 :
V_380 &= ~ ( 0x1 << 8 ) ;
V_380 |= ( 0x6 << 8 ) ;
break;
case V_487 :
if ( F_179 ( V_3 ) > 0 )
V_380 &= ~ ( 0x7 << 8 ) ;
else {
V_380 &= ~ 0xf ;
V_380 |= ( 0x1 << 2 ) ;
}
break;
default:
F_87 ( 1 ) ;
}
V_181 = F_153 ( V_3 , V_383 , V_380 ) ;
if ( V_181 )
return V_181 ;
if ( V_484 )
F_180 ( 10 ) ;
V_173 -> V_25 . V_479 &= ~ V_488 ;
return F_153 ( V_3 , V_480 , V_488 ) ;
}
int F_181 ( struct V_2 * V_3 , unsigned long V_458 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_172 * V_173 = & V_3 -> V_174 ;
const unsigned long * V_489 = F_182 ( V_173 ) ;
int V_181 ;
if ( V_173 -> V_25 . V_490 & V_491 )
return 0 ;
if ( V_5 -> V_42 & V_443 ) {
V_181 = F_177 ( V_3 , V_489 , V_458 ) ;
if ( V_181 && V_181 != - V_387 )
F_149 ( V_3 ,
L_128 ,
V_181 ) ;
}
if ( F_183 ( V_3 ) )
V_173 -> V_25 . V_490 &= ~ V_492 ;
return 0 ;
}
int F_184 ( struct V_2 * V_3 , const unsigned long * V_489 ,
unsigned long V_458 ,
bool * V_493 , int (* F_168)( struct V_2 * ) )
{
T_1 V_380 ;
int V_181 ;
F_30 ( L_129 ) ;
if ( V_493 )
* V_493 = false ;
if ( F_151 ( V_3 ) ) {
if ( ( V_181 = F_127 ( V_3 , V_383 , & V_380 ) ) )
goto V_454;
V_380 = ( V_380 & 0x0f0 ) | 0x304 ;
if ( ( V_181 = F_153 ( V_3 , V_383 , V_380 ) ) )
goto V_454;
F_152 ( V_3 ) ;
}
if ( ( V_181 = F_127 ( V_3 , V_383 , & V_380 ) ) )
goto V_454;
V_380 = ( V_380 & 0x0f0 ) | 0x301 ;
if ( ( V_181 = F_185 ( V_3 , V_383 , V_380 ) ) )
goto V_454;
F_174 ( V_3 -> V_5 , 1 ) ;
V_181 = F_177 ( V_3 , V_489 , V_458 ) ;
if ( V_181 )
goto V_454;
if ( F_183 ( V_3 ) )
goto V_454;
if ( V_493 )
* V_493 = true ;
if ( F_186 ( V_3 -> V_5 ) && F_13 ( V_3 ) ) {
if ( F_168 ) {
unsigned long V_494 ;
V_494 = F_169 ( V_460 ,
V_495 ) ;
if ( F_170 ( V_494 , V_458 ) )
V_494 = V_458 ;
F_167 ( V_3 , V_494 , F_168 ) ;
}
V_181 = - V_283 ;
goto V_454;
}
V_181 = 0 ;
if ( F_168 )
V_181 = F_167 ( V_3 , V_458 , F_168 ) ;
V_454:
if ( V_181 && V_181 != - V_283 ) {
if ( V_493 )
* V_493 = false ;
F_187 ( V_3 , L_130 , V_181 ) ;
}
F_30 ( L_131 , V_181 ) ;
return V_181 ;
}
int F_188 ( struct V_2 * V_3 , unsigned int * V_182 ,
unsigned long V_458 )
{
const unsigned long * V_489 = F_182 ( & V_3 -> V_174 ) ;
bool V_493 ;
int V_181 ;
V_181 = F_184 ( V_3 , V_489 , V_458 , & V_493 , NULL ) ;
return V_493 ? - V_283 : V_181 ;
}
void F_189 ( struct V_2 * V_3 , unsigned int * V_368 )
{
T_1 V_479 ;
F_30 ( L_129 ) ;
if ( ! F_127 ( V_3 , V_480 , & V_479 ) )
F_153 ( V_3 , V_480 , V_479 ) ;
F_144 ( V_3 ) ;
F_30 ( L_132 ) ;
}
static int F_190 ( struct V_14 * V_15 , unsigned int V_496 ,
const T_4 * V_497 )
{
const T_4 * V_498 = V_15 -> V_143 ;
unsigned char V_499 [ 2 ] [ V_315 + 1 ] ;
unsigned char V_500 [ 2 ] [ V_501 + 1 ] ;
if ( V_15 -> V_182 != V_496 ) {
F_57 ( V_15 , L_133 ,
V_15 -> V_182 , V_496 ) ;
return 0 ;
}
F_41 ( V_498 , V_499 [ 0 ] , V_324 , sizeof( V_499 [ 0 ] ) ) ;
F_41 ( V_497 , V_499 [ 1 ] , V_324 , sizeof( V_499 [ 1 ] ) ) ;
F_41 ( V_498 , V_500 [ 0 ] , V_502 , sizeof( V_500 [ 0 ] ) ) ;
F_41 ( V_497 , V_500 [ 1 ] , V_502 , sizeof( V_500 [ 1 ] ) ) ;
if ( strcmp ( V_499 [ 0 ] , V_499 [ 1 ] ) ) {
F_57 ( V_15 , L_134 ,
V_499 [ 0 ] , V_499 [ 1 ] ) ;
return 0 ;
}
if ( strcmp ( V_500 [ 0 ] , V_500 [ 1 ] ) ) {
F_57 ( V_15 , L_135 ,
V_500 [ 0 ] , V_500 [ 1 ] ) ;
return 0 ;
}
return 1 ;
}
int F_58 ( struct V_14 * V_15 , unsigned int V_503 )
{
unsigned int V_182 = V_15 -> V_182 ;
T_4 * V_143 = ( void * ) V_15 -> V_3 -> V_5 -> V_303 ;
int V_181 ;
V_181 = F_94 ( V_15 , & V_182 , V_503 , V_143 ) ;
if ( V_181 )
return V_181 ;
if ( ! F_190 ( V_15 , V_182 , V_143 ) )
return - V_263 ;
memcpy ( V_15 -> V_143 , V_143 , sizeof( V_143 [ 0 ] ) * V_253 ) ;
return 0 ;
}
int F_163 ( struct V_14 * V_15 , unsigned int V_496 ,
unsigned int V_503 )
{
T_3 V_321 = V_15 -> V_321 ;
T_3 V_184 = V_15 -> V_184 ;
int V_181 ;
if ( ! F_8 ( V_15 ) )
return - V_263 ;
if ( F_191 ( V_496 ) &&
V_496 != V_138 &&
V_496 != V_139 &&
V_496 != V_141 ) {
F_57 ( V_15 , L_136 ,
V_15 -> V_182 , V_496 ) ;
V_181 = - V_263 ;
goto V_377;
}
V_181 = F_58 ( V_15 , V_503 ) ;
if ( V_181 )
goto V_377;
V_181 = F_115 ( V_15 ) ;
if ( V_181 )
goto V_377;
if ( V_15 -> V_182 != V_138 || ! V_321 ||
V_15 -> V_321 == V_321 )
return 0 ;
F_24 ( V_15 , L_137 ,
( unsigned long long ) V_321 ,
( unsigned long long ) V_15 -> V_321 ) ;
if ( V_15 -> V_184 == V_184 &&
V_15 -> V_321 > V_321 && V_15 -> V_321 == V_184 ) {
F_24 ( V_15 ,
L_138
L_139 ) ;
return 0 ;
}
if ( V_15 -> V_184 == V_184 &&
V_15 -> V_321 < V_321 && V_321 == V_184 &&
! ( V_15 -> V_48 & V_183 ) ) {
F_24 ( V_15 ,
L_140
L_141 ) ;
V_15 -> V_42 |= V_179 ;
V_181 = - V_166 ;
} else
V_181 = - V_263 ;
V_15 -> V_184 = V_184 ;
V_15 -> V_321 = V_321 ;
V_377:
F_59 ( V_15 , L_142 , V_181 ) ;
return V_181 ;
}
static int F_192 ( const char * V_504 , const char * V_505 )
{
do {
if ( * V_504 == * V_505 || * V_505 == '?' ) {
if ( ! * V_505 ++ )
return 0 ;
} else {
if ( ! * V_504 || * V_505 != '[' )
break;
while ( * ++ V_505 && * V_505 != ']' && * V_504 != * V_505 ) {
if ( * V_505 == '-' && * ( V_505 - 1 ) != '[' )
if ( * V_504 > * ( V_505 - 1 ) && * V_504 < * ( V_505 + 1 ) ) {
++ V_505 ;
break;
}
}
if ( ! * V_505 || * V_505 == ']' )
return 1 ;
while ( * V_505 && * V_505 ++ != ']' ) ;
}
} while ( * ++ V_504 && * V_505 );
if ( * V_505 == '*' ) {
if ( ! * ++ V_505 )
return 0 ;
while ( * V_504 ) {
if ( F_192 ( V_504 , V_505 ) == 0 )
return 0 ;
++ V_504 ;
}
}
if ( ! * V_504 && ! * V_505 )
return 0 ;
return 1 ;
}
static unsigned long F_106 ( const struct V_14 * V_15 )
{
unsigned char V_506 [ V_315 + 1 ] ;
unsigned char V_507 [ V_313 + 1 ] ;
const struct V_508 * V_509 = V_510 ;
F_41 ( V_15 -> V_143 , V_506 , V_324 , sizeof( V_506 ) ) ;
F_41 ( V_15 -> V_143 , V_507 , V_323 , sizeof( V_507 ) ) ;
while ( V_509 -> V_506 ) {
if ( ! F_192 ( V_506 , V_509 -> V_506 ) ) {
if ( V_509 -> V_507 == NULL )
return V_509 -> V_48 ;
if ( ! F_192 ( V_507 , V_509 -> V_507 ) )
return V_509 -> V_48 ;
}
V_509 ++ ;
}
return 0 ;
}
static int F_193 ( const struct V_14 * V_15 )
{
if ( ( V_15 -> V_3 -> V_5 -> V_42 & V_511 ) &&
( V_15 -> V_42 & V_349 ) )
return 1 ;
return ( V_15 -> V_48 & V_512 ) ? 1 : 0 ;
}
static int F_194 ( struct V_14 * V_15 )
{
if ( V_15 -> V_48 & V_513 )
return F_195 ( V_15 -> V_143 ) ;
return F_196 ( V_15 -> V_143 ) ;
}
static int F_197 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
struct V_14 * V_15 ;
if ( V_5 -> V_33 == V_364 )
return 1 ;
if ( V_5 -> V_33 == V_365 || V_5 -> V_33 == V_285 )
return 0 ;
if ( V_5 -> V_33 == V_514 )
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
struct V_515 * V_273 = V_5 -> V_273 ;
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
L_143 ) ;
}
if ( ( V_273 -> V_42 & V_456 ) &&
V_273 -> V_457 && V_273 -> V_457 != V_5 ) {
V_47 &= ~ ( V_124 | V_126 ) ;
F_24 ( V_15 ,
L_144 ) ;
}
if ( V_5 -> V_42 & V_247 )
V_47 &= F_92 ( V_15 ) ;
if ( V_5 -> V_214 -> V_516 )
V_47 = V_5 -> V_214 -> V_516 ( V_15 , V_47 ) ;
if ( V_47 & ( 0xF8 << V_125 ) )
if ( F_197 ( V_5 ) ) {
F_24 ( V_15 ,
L_145 ) ;
V_47 &= ~ ( 0xF8 << V_125 ) ;
}
F_16 ( V_47 , & V_15 -> V_44 ,
& V_15 -> V_45 , & V_15 -> V_46 ) ;
}
static unsigned int F_162 ( struct V_14 * V_15 )
{
struct V_67 V_68 ;
unsigned int V_158 ;
F_30 ( L_146 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_517 ;
V_68 . V_72 = V_518 ;
V_68 . V_42 |= V_109 | V_110 | V_265 ;
V_68 . V_93 = V_161 ;
if ( F_90 ( V_15 ) )
V_68 . V_80 = V_15 -> V_134 ;
else if ( F_91 ( V_15 -> V_143 ) )
V_68 . V_80 = 0x01 ;
else
return 0 ;
V_158 = F_53 ( V_15 , & V_68 , NULL , V_162 , NULL , 0 , 0 ) ;
F_30 ( L_147 , V_158 ) ;
return V_158 ;
}
unsigned int F_100 ( struct V_14 * V_15 , T_2 V_519 , T_2 V_72 )
{
struct V_67 V_68 ;
unsigned int V_158 ;
F_30 ( L_148 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_517 ;
V_68 . V_72 = V_519 ;
V_68 . V_42 |= V_109 | V_110 ;
V_68 . V_93 = V_161 ;
V_68 . V_80 = V_72 ;
V_158 = F_53 ( V_15 , & V_68 , NULL , V_162 , NULL , 0 , 0 ) ;
F_30 ( L_147 , V_158 ) ;
return V_158 ;
}
static unsigned int F_102 ( struct V_14 * V_15 ,
T_4 V_104 , T_4 V_105 )
{
struct V_67 V_68 ;
unsigned int V_158 ;
if ( V_105 < 1 || V_105 > 255 || V_104 < 1 || V_104 > 16 )
return V_520 ;
F_30 ( L_149 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_521 ;
V_68 . V_42 |= V_109 | V_110 ;
V_68 . V_93 = V_161 ;
V_68 . V_80 = V_105 ;
V_68 . V_21 |= ( V_104 - 1 ) & 0x0f ;
V_158 = F_53 ( V_15 , & V_68 , NULL , V_162 , NULL , 0 , 0 ) ;
if ( V_158 == V_163 && ( V_68 . V_72 & V_164 ) )
V_158 = 0 ;
F_30 ( L_147 , V_158 ) ;
return V_158 ;
}
void F_199 ( struct V_193 * V_194 )
{
struct V_4 * V_5 = V_194 -> V_5 ;
struct V_200 * V_230 = V_194 -> V_230 ;
int V_522 = V_194 -> V_199 ;
F_200 ( V_230 == NULL ) ;
F_201 ( L_150 , V_194 -> V_202 ) ;
if ( V_194 -> V_202 )
F_202 ( V_5 -> V_15 , V_230 , V_194 -> V_523 , V_522 ) ;
V_194 -> V_42 &= ~ V_524 ;
V_194 -> V_230 = NULL ;
}
int F_203 ( struct V_193 * V_194 )
{
struct V_4 * V_5 = V_194 -> V_5 ;
if ( ! ( V_194 -> V_15 -> V_48 & V_525 ) &&
F_5 ( V_194 -> V_232 & 15 ) )
return 1 ;
if ( V_5 -> V_214 -> V_526 )
return V_5 -> V_214 -> V_526 ( V_194 ) ;
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
return V_527 ;
}
void F_206 ( struct V_193 * V_194 ) { }
void F_74 ( struct V_193 * V_194 , struct V_200 * V_230 ,
unsigned int V_202 )
{
V_194 -> V_230 = V_230 ;
V_194 -> V_202 = V_202 ;
V_194 -> V_528 = V_194 -> V_230 ;
}
static int F_207 ( struct V_193 * V_194 )
{
struct V_4 * V_5 = V_194 -> V_5 ;
unsigned int V_202 ;
F_201 ( L_151 , V_5 -> V_31 ) ;
V_202 = F_208 ( V_5 -> V_15 , V_194 -> V_230 , V_194 -> V_202 , V_194 -> V_199 ) ;
if ( V_202 < 1 )
return - 1 ;
F_30 ( L_152 , V_202 ) ;
V_194 -> V_523 = V_194 -> V_202 ;
V_194 -> V_202 = V_202 ;
V_194 -> V_42 |= V_524 ;
return 0 ;
}
void F_98 ( T_4 * V_243 , unsigned int V_529 )
{
#ifdef F_209
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < V_529 ; V_25 ++ )
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
if ( F_27 ( V_194 -> V_42 & V_524 ) )
F_199 ( V_194 ) ;
if ( V_194 -> V_68 . V_93 == V_113 ) {
V_3 -> V_219 &= ~ ( 1 << V_194 -> V_108 ) ;
if ( ! V_3 -> V_219 )
V_5 -> V_221 -- ;
} else {
V_3 -> V_218 = V_222 ;
V_5 -> V_221 -- ;
}
if ( F_5 ( V_194 -> V_42 & V_530 &&
V_5 -> V_531 == V_3 ) )
V_5 -> V_531 = NULL ;
V_194 -> V_42 &= ~ V_235 ;
V_5 -> V_220 &= ~ ( 1 << V_194 -> V_108 ) ;
V_194 -> V_233 ( V_194 ) ;
}
static void F_215 ( struct V_193 * V_194 )
{
struct V_4 * V_5 = V_194 -> V_5 ;
V_194 -> V_239 . V_42 = V_194 -> V_68 . V_42 ;
V_5 -> V_214 -> V_532 ( V_194 ) ;
}
static void F_216 ( struct V_193 * V_194 )
{
struct V_14 * V_15 = V_194 -> V_15 ;
if ( F_217 ( V_194 -> V_68 . V_93 ) )
return;
if ( ( V_15 -> V_45 || V_15 -> V_46 ) && F_218 ( V_194 -> V_68 . V_93 ) )
return;
V_15 -> V_42 &= ~ V_533 ;
}
void F_83 ( struct V_193 * V_194 )
{
struct V_4 * V_5 = V_194 -> V_5 ;
if ( V_5 -> V_214 -> V_215 ) {
struct V_14 * V_15 = V_194 -> V_15 ;
struct V_534 * V_535 = & V_15 -> V_3 -> V_536 ;
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
case V_517 :
if ( V_194 -> V_68 . V_72 != V_537 &&
V_194 -> V_68 . V_72 != V_538 )
break;
case V_521 :
case V_539 :
V_535 -> V_540 [ V_15 -> V_24 ] |= V_541 ;
F_221 ( V_5 ) ;
break;
case V_542 :
V_15 -> V_42 |= V_543 ;
break;
}
if ( F_5 ( V_15 -> V_42 & V_533 ) )
F_216 ( V_194 ) ;
F_214 ( V_194 ) ;
} else {
if ( V_194 -> V_42 & V_544 )
return;
if ( V_194 -> V_158 || V_194 -> V_42 & V_228 )
F_215 ( V_194 ) ;
F_214 ( V_194 ) ;
}
}
int F_222 ( struct V_4 * V_5 , T_1 V_220 )
{
int V_545 = 0 ;
T_1 V_546 ;
V_546 = V_5 -> V_220 ^ V_220 ;
if ( F_5 ( V_546 & V_220 ) ) {
F_223 ( V_5 , L_153 ,
V_5 -> V_220 , V_220 ) ;
return - V_119 ;
}
while ( V_546 ) {
struct V_193 * V_194 ;
unsigned int V_108 = F_224 ( V_546 ) ;
V_194 = F_225 ( V_5 , V_108 ) ;
if ( V_194 ) {
F_83 ( V_194 ) ;
V_545 ++ ;
}
V_546 &= ~ ( 1 << V_108 ) ;
}
return V_545 ;
}
void F_75 ( struct V_193 * V_194 )
{
struct V_4 * V_5 = V_194 -> V_5 ;
struct V_2 * V_3 = V_194 -> V_15 -> V_3 ;
T_2 V_547 = V_194 -> V_68 . V_93 ;
F_200 ( V_5 -> V_214 -> V_215 && F_205 ( V_3 -> V_218 ) ) ;
if ( F_226 ( V_547 ) ) {
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
if ( F_200 ( F_227 ( V_547 ) &&
( ! V_194 -> V_230 || ! V_194 -> V_202 || ! V_194 -> V_232 ) ) )
goto V_548;
if ( F_228 ( V_547 ) || ( F_218 ( V_547 ) &&
( V_5 -> V_42 & V_549 ) ) )
if ( F_207 ( V_194 ) )
goto V_548;
if ( F_5 ( V_194 -> V_15 -> V_42 & V_543 ) ) {
V_3 -> V_536 . V_490 |= V_550 ;
F_229 ( & V_3 -> V_536 , L_154 ) ;
F_230 ( V_3 ) ;
return;
}
V_5 -> V_214 -> V_551 ( V_194 ) ;
V_194 -> V_158 |= V_5 -> V_214 -> V_552 ( V_194 ) ;
if ( F_5 ( V_194 -> V_158 ) )
goto V_553;
return;
V_548:
V_194 -> V_158 |= V_213 ;
V_553:
F_83 ( V_194 ) ;
}
int F_104 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
return ( V_5 -> V_42 & V_443 ) && V_5 -> V_214 -> V_554 ;
}
int F_127 ( struct V_2 * V_3 , int V_555 , T_1 * V_556 )
{
if ( F_13 ( V_3 ) ) {
if ( F_104 ( V_3 ) )
return V_3 -> V_5 -> V_214 -> V_554 ( V_3 , V_555 , V_556 ) ;
return - V_387 ;
}
return F_231 ( V_3 , V_555 , V_556 ) ;
}
int F_153 ( struct V_2 * V_3 , int V_555 , T_1 V_556 )
{
if ( F_13 ( V_3 ) ) {
if ( F_104 ( V_3 ) )
return V_3 -> V_5 -> V_214 -> V_557 ( V_3 , V_555 , V_556 ) ;
return - V_387 ;
}
return F_232 ( V_3 , V_555 , V_556 ) ;
}
int F_185 ( struct V_2 * V_3 , int V_555 , T_1 V_556 )
{
if ( F_13 ( V_3 ) ) {
int V_181 ;
if ( F_104 ( V_3 ) ) {
V_181 = V_3 -> V_5 -> V_214 -> V_557 ( V_3 , V_555 , V_556 ) ;
if ( V_181 == 0 )
V_181 = V_3 -> V_5 -> V_214 -> V_554 ( V_3 , V_555 , & V_556 ) ;
return V_181 ;
}
return - V_387 ;
}
return F_232 ( V_3 , V_555 , V_556 ) ;
}
bool F_145 ( struct V_2 * V_3 )
{
T_1 V_1 ;
if ( F_127 ( V_3 , V_382 , & V_1 ) == 0 &&
F_1 ( V_1 ) )
return true ;
return false ;
}
bool F_183 ( struct V_2 * V_3 )
{
T_1 V_1 ;
if ( F_127 ( V_3 , V_382 , & V_1 ) == 0 &&
! F_1 ( V_1 ) )
return true ;
return false ;
}
bool F_171 ( struct V_2 * V_3 )
{
struct V_2 * V_558 = V_3 -> V_5 -> V_12 ;
F_87 ( V_3 == V_558 ) ;
return F_145 ( V_3 ) ||
( V_558 && F_145 ( V_558 ) ) ;
}
bool F_172 ( struct V_2 * V_3 )
{
struct V_2 * V_558 = V_3 -> V_5 -> V_12 ;
F_87 ( V_3 == V_558 ) ;
return F_183 ( V_3 ) &&
( ! V_558 || F_183 ( V_558 ) ) ;
}
static int F_233 ( struct V_4 * V_5 , T_6 V_559 ,
unsigned int V_490 , unsigned int V_560 ,
int * V_561 )
{
struct V_2 * V_3 ;
unsigned long V_42 ;
int V_181 = 0 ;
if ( V_5 -> V_211 & V_562 ) {
if ( V_561 ) {
* V_561 = - V_283 ;
return 0 ;
}
F_234 ( V_5 ) ;
F_87 ( V_5 -> V_211 & V_562 ) ;
}
F_67 ( V_5 -> V_210 , V_42 ) ;
V_5 -> V_563 = V_559 ;
if ( V_561 )
V_5 -> V_564 = V_561 ;
else
V_5 -> V_564 = & V_181 ;
V_5 -> V_211 |= V_562 ;
F_198 (link, ap, HOST_FIRST) {
V_3 -> V_536 . V_490 |= V_490 ;
V_3 -> V_536 . V_42 |= V_560 ;
}
F_221 ( V_5 ) ;
F_68 ( V_5 -> V_210 , V_42 ) ;
if ( ! V_561 ) {
F_234 ( V_5 ) ;
F_87 ( V_5 -> V_211 & V_562 ) ;
}
return V_181 ;
}
static int F_235 ( struct V_4 * V_5 , T_6 V_559 , int * V_561 )
{
unsigned int V_560 = V_565 | V_566 |
V_567 ;
return F_233 ( V_5 , V_559 , 0 , V_560 , V_561 ) ;
}
static int F_236 ( struct V_21 * V_15 , T_6 V_559 )
{
struct V_4 * V_5 = F_237 ( V_15 ) ;
return F_235 ( V_5 , V_559 , NULL ) ;
}
static int F_238 ( struct V_21 * V_15 )
{
if ( F_239 ( V_15 ) )
return 0 ;
return F_236 ( V_15 , V_568 ) ;
}
static int F_240 ( struct V_21 * V_15 )
{
if ( F_239 ( V_15 ) )
return 0 ;
return F_236 ( V_15 , V_569 ) ;
}
static int F_241 ( struct V_21 * V_15 )
{
return F_236 ( V_15 , V_570 ) ;
}
static int F_242 ( struct V_4 * V_5 , T_6 V_559 ,
int * V_561 )
{
int V_181 ;
V_181 = F_233 ( V_5 , V_559 , V_550 ,
V_566 | V_565 , V_561 ) ;
return V_181 ;
}
static int F_243 ( struct V_21 * V_15 , T_6 V_559 )
{
struct V_4 * V_5 = F_237 ( V_15 ) ;
return F_242 ( V_5 , V_559 , NULL ) ;
}
static int F_244 ( struct V_21 * V_15 )
{
int V_181 ;
V_181 = F_243 ( V_15 , V_571 ) ;
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
return - V_468 ;
}
return 0 ;
}
static int F_250 ( struct V_21 * V_15 )
{
return F_236 ( V_15 , V_572 ) ;
}
static int F_251 ( struct V_21 * V_15 )
{
return F_243 ( V_15 , V_573 ) ;
}
int F_252 ( struct V_4 * V_5 , int * V_561 )
{
return F_235 ( V_5 , V_568 , V_561 ) ;
}
int F_253 ( struct V_4 * V_5 , int * V_561 )
{
return F_242 ( V_5 , V_571 , V_561 ) ;
}
int F_254 ( struct V_515 * V_273 , T_6 V_559 )
{
V_273 -> V_15 -> V_574 . V_575 = V_559 ;
return 0 ;
}
void F_255 ( struct V_515 * V_273 )
{
V_273 -> V_15 -> V_574 . V_575 = V_576 ;
}
void F_256 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = F_9 ( V_15 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_42 ;
V_3 -> V_281 = V_3 -> V_40 ;
V_3 -> V_282 = 0 ;
F_67 ( V_5 -> V_210 , V_42 ) ;
V_15 -> V_42 &= ~ V_577 ;
V_15 -> V_48 = 0 ;
F_68 ( V_5 -> V_210 , V_42 ) ;
memset ( ( void * ) V_15 + V_578 , 0 ,
V_579 - V_578 ) ;
V_15 -> V_44 = V_390 ;
V_15 -> V_45 = V_390 ;
V_15 -> V_46 = V_390 ;
}
void F_257 ( struct V_4 * V_5 , struct V_2 * V_3 , int V_38 )
{
int V_25 ;
memset ( ( void * ) V_3 + V_580 , 0 ,
V_581 - V_580 ) ;
V_3 -> V_5 = V_5 ;
V_3 -> V_38 = V_38 ;
V_3 -> V_218 = V_222 ;
V_3 -> V_40 = V_390 ;
for ( V_25 = 0 ; V_25 < V_369 ; V_25 ++ ) {
struct V_14 * V_15 = & V_3 -> V_21 [ V_25 ] ;
V_15 -> V_3 = V_3 ;
V_15 -> V_24 = V_15 - V_3 -> V_21 ;
#ifdef F_258
V_15 -> V_582 = V_583 ;
#endif
F_256 ( V_15 ) ;
}
}
int F_259 ( struct V_2 * V_3 )
{
T_2 V_136 ;
int V_181 ;
V_181 = F_127 ( V_3 , V_383 , & V_3 -> V_584 ) ;
if ( V_181 )
return V_181 ;
V_136 = ( V_3 -> V_584 >> 4 ) & 0xf ;
if ( V_136 )
V_3 -> V_40 &= ( 1 << V_136 ) - 1 ;
F_12 ( V_3 ) ;
V_3 -> V_281 = V_3 -> V_40 ;
return 0 ;
}
struct V_4 * F_260 ( struct V_515 * V_273 )
{
struct V_4 * V_5 ;
F_30 ( L_129 ) ;
V_5 = F_261 ( sizeof( * V_5 ) , V_585 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_211 |= V_586 | V_212 ;
V_5 -> V_210 = & V_273 -> V_210 ;
V_5 -> V_31 = - 1 ;
V_5 -> V_587 = - 1 ;
V_5 -> V_273 = V_273 ;
V_5 -> V_15 = V_273 -> V_15 ;
#if F_262 ( V_588 )
V_5 -> V_589 = 0x00FF ;
#elif F_262 ( V_590 )
V_5 -> V_589 = V_591 | V_592 | V_593 | V_594 | V_595 ;
#else
V_5 -> V_589 = V_591 | V_595 | V_594 ;
#endif
F_263 ( & V_5 -> V_596 ) ;
F_264 ( & V_5 -> V_597 , V_598 ) ;
F_265 ( & V_5 -> V_599 , V_600 ) ;
F_266 ( & V_5 -> V_601 ) ;
F_267 ( & V_5 -> V_602 ) ;
F_268 ( & V_5 -> V_603 ) ;
F_269 ( & V_5 -> V_604 ) ;
V_5 -> V_604 . V_605 = V_606 ;
V_5 -> V_604 . V_607 = ( unsigned long ) V_5 ;
V_5 -> V_33 = V_34 ;
F_257 ( V_5 , & V_5 -> V_3 , 0 ) ;
#ifdef F_270
V_5 -> V_608 . V_609 = 1 ;
V_5 -> V_608 . V_610 = 1 ;
#endif
F_271 ( V_5 ) ;
return V_5 ;
}
static void F_272 ( struct V_21 * V_611 , void * V_612 )
{
struct V_515 * V_273 = F_273 ( V_611 ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_273 -> V_613 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_614 [ V_25 ] ;
if ( ! V_5 )
continue;
if ( V_5 -> V_293 )
F_274 ( V_5 -> V_293 ) ;
F_275 ( V_5 -> V_11 ) ;
F_275 ( V_5 -> V_12 ) ;
F_275 ( V_5 ) ;
V_273 -> V_614 [ V_25 ] = NULL ;
}
F_276 ( V_611 , NULL ) ;
}
struct V_515 * F_277 ( struct V_21 * V_15 , int V_615 )
{
struct V_515 * V_273 ;
T_5 V_616 ;
int V_25 ;
F_30 ( L_129 ) ;
if ( ! F_278 ( V_15 , NULL , V_585 ) )
return NULL ;
V_616 = sizeof( struct V_515 ) + ( V_615 + 1 ) * sizeof( void * ) ;
V_273 = F_279 ( F_272 , V_616 , V_585 ) ;
if ( ! V_273 )
goto V_264;
F_280 ( V_15 , V_273 ) ;
F_276 ( V_15 , V_273 ) ;
F_281 ( & V_273 -> V_210 ) ;
F_263 ( & V_273 -> V_617 ) ;
V_273 -> V_15 = V_15 ;
V_273 -> V_613 = V_615 ;
for ( V_25 = 0 ; V_25 < V_615 ; V_25 ++ ) {
struct V_4 * V_5 ;
V_5 = F_260 ( V_273 ) ;
if ( ! V_5 )
goto V_264;
V_5 -> V_618 = V_25 ;
V_273 -> V_614 [ V_25 ] = V_5 ;
}
F_282 ( V_15 , NULL ) ;
return V_273 ;
V_264:
F_283 ( V_15 , NULL ) ;
return NULL ;
}
struct V_515 * F_284 ( struct V_21 * V_15 ,
const struct V_619 * const * V_620 ,
int V_613 )
{
const struct V_619 * V_621 ;
struct V_515 * V_273 ;
int V_25 , V_332 ;
V_273 = F_277 ( V_15 , V_613 ) ;
if ( ! V_273 )
return NULL ;
for ( V_25 = 0 , V_332 = 0 , V_621 = NULL ; V_25 < V_273 -> V_613 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_614 [ V_25 ] ;
if ( V_620 [ V_332 ] )
V_621 = V_620 [ V_332 ++ ] ;
V_5 -> V_44 = V_621 -> V_44 ;
V_5 -> V_45 = V_621 -> V_45 ;
V_5 -> V_46 = V_621 -> V_46 ;
V_5 -> V_42 |= V_621 -> V_42 ;
V_5 -> V_3 . V_42 |= V_621 -> V_622 ;
V_5 -> V_214 = V_621 -> V_623 ;
if ( ! V_273 -> V_214 && ( V_621 -> V_623 != & V_624 ) )
V_273 -> V_214 = V_621 -> V_623 ;
}
return V_273 ;
}
int F_285 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
F_87 ( V_5 -> V_12 ) ;
F_87 ( V_5 -> V_42 & V_625 ) ;
V_3 = F_261 ( sizeof( * V_3 ) , V_585 ) ;
if ( ! V_3 )
return - V_626 ;
F_257 ( V_5 , V_3 , 1 ) ;
V_5 -> V_12 = V_3 ;
return 0 ;
}
static void F_286 ( struct V_21 * V_611 , void * V_612 )
{
struct V_515 * V_273 = F_273 ( V_611 ) ;
int V_25 ;
F_87 ( ! ( V_273 -> V_42 & V_627 ) ) ;
for ( V_25 = 0 ; V_25 < V_273 -> V_613 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_614 [ V_25 ] ;
if ( V_5 -> V_214 -> V_628 )
V_5 -> V_214 -> V_628 ( V_5 ) ;
}
if ( V_273 -> V_214 -> V_629 )
V_273 -> V_214 -> V_629 ( V_273 ) ;
}
static void F_287 ( struct V_630 * V_214 )
{
static F_288 ( V_210 ) ;
const struct V_630 * V_476 ;
void * * V_631 = ( void * * ) V_214 ;
void * * V_632 = ( void * * ) & V_214 -> V_633 ;
void * * V_634 ;
if ( ! V_214 || ! V_214 -> V_633 )
return;
F_289 ( & V_210 ) ;
for ( V_476 = V_214 -> V_633 ; V_476 ; V_476 = V_476 -> V_633 ) {
void * * V_635 = ( void * * ) V_476 ;
for ( V_634 = V_631 ; V_634 < V_632 ; V_634 ++ , V_635 ++ )
if ( ! * V_634 )
* V_634 = * V_635 ;
}
for ( V_634 = V_631 ; V_634 < V_632 ; V_634 ++ )
if ( F_290 ( * V_634 ) )
* V_634 = NULL ;
V_214 -> V_633 = NULL ;
F_291 ( & V_210 ) ;
}
int F_292 ( struct V_515 * V_273 )
{
int V_636 = 0 ;
void * V_637 = NULL ;
int V_25 , V_181 ;
if ( V_273 -> V_42 & V_627 )
return 0 ;
F_287 ( V_273 -> V_214 ) ;
for ( V_25 = 0 ; V_25 < V_273 -> V_613 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_614 [ V_25 ] ;
F_287 ( V_5 -> V_214 ) ;
if ( ! V_273 -> V_214 && ! F_293 ( V_5 ) )
V_273 -> V_214 = V_5 -> V_214 ;
if ( V_5 -> V_214 -> V_628 )
V_636 = 1 ;
}
if ( V_273 -> V_214 -> V_629 )
V_636 = 1 ;
if ( V_636 ) {
V_637 = F_279 ( F_286 , 0 , V_585 ) ;
if ( ! V_637 )
return - V_626 ;
}
for ( V_25 = 0 ; V_25 < V_273 -> V_613 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_614 [ V_25 ] ;
if ( V_5 -> V_214 -> V_638 ) {
V_181 = V_5 -> V_214 -> V_638 ( V_5 ) ;
if ( V_181 ) {
if ( V_181 != - V_263 )
F_294 ( V_273 -> V_15 ,
L_155 ,
V_25 , V_181 ) ;
goto V_264;
}
}
F_295 ( V_5 ) ;
}
if ( V_637 )
F_280 ( V_273 -> V_15 , V_637 ) ;
V_273 -> V_42 |= V_627 ;
return 0 ;
V_264:
while ( -- V_25 >= 0 ) {
struct V_4 * V_5 = V_273 -> V_614 [ V_25 ] ;
if ( V_5 -> V_214 -> V_628 )
V_5 -> V_214 -> V_628 ( V_5 ) ;
}
F_296 ( V_637 ) ;
return V_181 ;
}
void F_297 ( struct V_515 * V_273 , struct V_21 * V_15 ,
struct V_630 * V_214 )
{
F_281 ( & V_273 -> V_210 ) ;
F_263 ( & V_273 -> V_617 ) ;
V_273 -> V_15 = V_15 ;
V_273 -> V_214 = V_214 ;
}
void F_298 ( struct V_4 * V_5 )
{
struct V_534 * V_535 = & V_5 -> V_3 . V_536 ;
unsigned long V_42 ;
F_67 ( V_5 -> V_210 , V_42 ) ;
V_535 -> V_639 |= V_640 ;
V_535 -> V_490 |= V_550 ;
V_535 -> V_42 |= V_566 | V_565 ;
V_5 -> V_211 &= ~ V_586 ;
V_5 -> V_211 |= V_641 ;
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
F_30 ( L_156 , V_5 -> V_31 ) ;
V_181 = F_139 ( V_5 ) ;
F_30 ( L_157 , V_5 -> V_31 ) ;
}
return V_181 ;
}
static void F_300 ( void * V_607 , T_7 V_642 )
{
struct V_4 * V_5 = V_607 ;
if ( ! ( V_5 -> V_273 -> V_42 & V_463 ) && V_5 -> V_618 != 0 )
F_301 ( V_642 ) ;
( void ) F_299 ( V_5 ) ;
F_301 ( V_642 ) ;
F_302 ( V_5 , 1 ) ;
}
int F_303 ( struct V_515 * V_273 , struct V_643 * V_644 )
{
int V_25 , V_181 ;
if ( ! ( V_273 -> V_42 & V_627 ) ) {
F_294 ( V_273 -> V_15 , L_158 ) ;
F_87 ( 1 ) ;
return - V_119 ;
}
for ( V_25 = V_273 -> V_613 ; V_273 -> V_614 [ V_25 ] ; V_25 ++ )
F_275 ( V_273 -> V_614 [ V_25 ] ) ;
for ( V_25 = 0 ; V_25 < V_273 -> V_613 ; V_25 ++ ) {
V_273 -> V_614 [ V_25 ] -> V_31 = F_304 ( & V_645 ) ;
V_273 -> V_614 [ V_25 ] -> V_587 = V_25 + 1 ;
}
for ( V_25 = 0 ; V_25 < V_273 -> V_613 ; V_25 ++ ) {
V_181 = F_305 ( V_273 -> V_15 , V_273 -> V_614 [ V_25 ] ) ;
if ( V_181 ) {
goto V_646;
}
}
V_181 = F_306 ( V_273 , V_644 ) ;
if ( V_181 )
goto V_646;
for ( V_25 = 0 ; V_25 < V_273 -> V_613 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_614 [ V_25 ] ;
unsigned long V_47 ;
if ( V_5 -> V_33 == V_34 && ( V_5 -> V_42 & V_443 ) )
V_5 -> V_33 = V_285 ;
F_259 ( & V_5 -> V_3 ) ;
if ( V_5 -> V_12 )
F_259 ( V_5 -> V_12 ) ;
V_47 = F_31 ( V_5 -> V_44 , V_5 -> V_45 ,
V_5 -> V_46 ) ;
if ( ! F_293 ( V_5 ) ) {
V_619 ( V_5 , L_159 ,
( V_5 -> V_42 & V_443 ) ? 'S' : 'P' ,
F_36 ( V_47 ) ,
V_5 -> V_3 . V_536 . V_286 ) ;
F_307 ( & V_5 -> V_3 . V_536 ) ;
} else
V_619 ( V_5 , L_160 ) ;
}
for ( V_25 = 0 ; V_25 < V_273 -> V_613 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_614 [ V_25 ] ;
F_308 ( F_300 , V_5 ) ;
}
return 0 ;
V_646:
while ( -- V_25 >= 0 ) {
F_309 ( V_273 -> V_614 [ V_25 ] ) ;
}
return V_181 ;
}
int F_310 ( struct V_515 * V_273 , int V_647 ,
T_8 V_648 , unsigned long V_649 ,
struct V_643 * V_644 )
{
int V_25 , V_181 ;
V_181 = F_292 ( V_273 ) ;
if ( V_181 )
return V_181 ;
if ( ! V_647 ) {
F_87 ( V_648 ) ;
return F_303 ( V_273 , V_644 ) ;
}
V_181 = F_311 ( V_273 -> V_15 , V_647 , V_648 , V_649 ,
F_312 ( V_273 -> V_15 ) , V_273 ) ;
if ( V_181 )
return V_181 ;
for ( V_25 = 0 ; V_25 < V_273 -> V_613 ; V_25 ++ )
F_313 ( V_273 -> V_614 [ V_25 ] , L_161 , V_647 ) ;
V_181 = F_303 ( V_273 , V_644 ) ;
if ( V_181 )
F_314 ( V_273 -> V_15 , V_647 , V_273 ) ;
return V_181 ;
}
static void F_315 ( struct V_4 * V_5 )
{
unsigned long V_42 ;
if ( ! V_5 -> V_214 -> V_215 )
goto V_650;
F_67 ( V_5 -> V_210 , V_42 ) ;
V_5 -> V_211 |= V_651 ;
F_221 ( V_5 ) ;
F_68 ( V_5 -> V_210 , V_42 ) ;
F_234 ( V_5 ) ;
F_87 ( ! ( V_5 -> V_211 & V_652 ) ) ;
F_316 ( & V_5 -> V_597 ) ;
V_650:
if ( V_5 -> V_11 ) {
int V_25 ;
for ( V_25 = 0 ; V_25 < V_653 ; V_25 ++ )
F_317 ( & V_5 -> V_11 [ V_25 ] ) ;
}
F_318 ( V_5 -> V_293 ) ;
F_309 ( V_5 ) ;
}
void F_319 ( struct V_515 * V_273 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_273 -> V_613 ; V_25 ++ )
F_315 ( V_273 -> V_614 [ V_25 ] ) ;
F_320 ( V_273 ) ;
}
void F_321 ( struct V_654 * V_655 )
{
struct V_515 * V_273 = F_322 ( V_655 ) ;
F_319 ( V_273 ) ;
}
int F_323 ( struct V_654 * V_655 , const struct V_656 * V_132 )
{
unsigned long V_381 = 0 ;
switch ( V_132 -> V_657 ) {
case 1 : {
T_2 V_658 = 0 ;
F_324 ( V_655 , V_132 -> V_555 , & V_658 ) ;
V_381 = V_658 ;
break;
}
case 2 : {
T_4 V_659 = 0 ;
F_325 ( V_655 , V_132 -> V_555 , & V_659 ) ;
V_381 = V_659 ;
break;
}
case 4 : {
T_1 V_660 = 0 ;
F_326 ( V_655 , V_132 -> V_555 , & V_660 ) ;
V_381 = V_660 ;
break;
}
default:
return - V_119 ;
}
V_381 &= V_132 -> V_385 ;
return ( V_381 == V_132 -> V_556 ) ? 1 : 0 ;
}
void F_327 ( struct V_654 * V_655 , T_6 V_559 )
{
F_328 ( V_655 ) ;
F_329 ( V_655 ) ;
if ( V_559 . V_661 & V_662 )
F_330 ( V_655 , V_663 ) ;
}
int F_331 ( struct V_654 * V_655 )
{
int V_181 ;
F_330 ( V_655 , V_664 ) ;
F_332 ( V_655 ) ;
V_181 = F_333 ( V_655 ) ;
if ( V_181 ) {
F_294 ( & V_655 -> V_15 ,
L_162 , V_181 ) ;
return V_181 ;
}
F_334 ( V_655 ) ;
return 0 ;
}
int F_335 ( struct V_654 * V_655 , T_6 V_559 )
{
struct V_515 * V_273 = F_322 ( V_655 ) ;
int V_181 = 0 ;
V_181 = F_254 ( V_273 , V_559 ) ;
if ( V_181 )
return V_181 ;
F_327 ( V_655 , V_559 ) ;
return 0 ;
}
int F_336 ( struct V_654 * V_655 )
{
struct V_515 * V_273 = F_322 ( V_655 ) ;
int V_181 ;
V_181 = F_331 ( V_655 ) ;
if ( V_181 == 0 )
F_255 ( V_273 ) ;
return V_181 ;
}
int F_337 ( struct V_665 * V_655 )
{
struct V_515 * V_273 = F_338 ( V_655 ) ;
F_319 ( V_273 ) ;
return 0 ;
}
static int T_9 F_339 ( char * * V_476 ,
struct V_27 * V_666 ,
const char * * V_255 )
{
static struct V_667 V_668 [] V_669 = {
{ L_163 , . V_33 = V_364 } ,
{ L_164 , . V_33 = V_365 } ,
{ L_165 , . V_33 = V_514 } ,
{ L_166 , . V_33 = V_366 } ,
{ L_167 , . V_33 = V_367 } ,
{ L_168 , . V_33 = V_285 } ,
{ L_169 , . V_39 = 1 } ,
{ L_170 , . V_39 = 2 } ,
{ L_171 , . V_49 = V_291 } ,
{ L_172 , . V_50 = V_291 } ,
{ L_173 , . V_49 = V_270 } ,
{ L_174 , . V_47 = 1 << ( V_121 + 0 ) } ,
{ L_175 , . V_47 = 1 << ( V_121 + 1 ) } ,
{ L_176 , . V_47 = 1 << ( V_121 + 2 ) } ,
{ L_177 , . V_47 = 1 << ( V_121 + 3 ) } ,
{ L_178 , . V_47 = 1 << ( V_121 + 4 ) } ,
{ L_179 , . V_47 = 1 << ( V_121 + 5 ) } ,
{ L_180 , . V_47 = 1 << ( V_121 + 6 ) } ,
{ L_181 , . V_47 = 1 << ( V_123 + 0 ) } ,
{ L_182 , . V_47 = 1 << ( V_123 + 1 ) } ,
{ L_183 , . V_47 = 1 << ( V_123 + 2 ) } ,
{ L_184 , . V_47 = 1 << ( V_123 + 3 ) } ,
{ L_185 , . V_47 = 1 << ( V_123 + 4 ) } ,
{ L_186 , . V_47 = 1 << ( V_125 + 0 ) } ,
{ L_187 , . V_47 = 1 << ( V_125 + 0 ) } ,
{ L_188 , . V_47 = 1 << ( V_125 + 0 ) } ,
{ L_189 , . V_47 = 1 << ( V_125 + 1 ) } ,
{ L_190 , . V_47 = 1 << ( V_125 + 1 ) } ,
{ L_191 , . V_47 = 1 << ( V_125 + 1 ) } ,
{ L_192 , . V_47 = 1 << ( V_125 + 2 ) } ,
{ L_193 , . V_47 = 1 << ( V_125 + 2 ) } ,
{ L_194 , . V_47 = 1 << ( V_125 + 2 ) } ,
{ L_195 , . V_47 = 1 << ( V_125 + 3 ) } ,
{ L_196 , . V_47 = 1 << ( V_125 + 3 ) } ,
{ L_197 , . V_47 = 1 << ( V_125 + 3 ) } ,
{ L_198 , . V_47 = 1 << ( V_125 + 4 ) } ,
{ L_199 , . V_47 = 1 << ( V_125 + 4 ) } ,
{ L_200 , . V_47 = 1 << ( V_125 + 4 ) } ,
{ L_201 , . V_47 = 1 << ( V_125 + 5 ) } ,
{ L_202 , . V_47 = 1 << ( V_125 + 5 ) } ,
{ L_203 , . V_47 = 1 << ( V_125 + 5 ) } ,
{ L_204 , . V_47 = 1 << ( V_125 + 6 ) } ,
{ L_205 , . V_47 = 1 << ( V_125 + 6 ) } ,
{ L_206 , . V_47 = 1 << ( V_125 + 6 ) } ,
{ L_207 , . V_47 = 1 << ( V_125 + 7 ) } ,
{ L_208 , . V_41 = V_670 } ,
{ L_209 , . V_41 = V_671 } ,
{ L_210 , . V_41 = V_670 | V_671 } ,
{ L_211 , . V_41 = V_672 } ,
{ L_212 , . V_49 = V_351 } ,
{ L_213 , . V_49 = V_316 } ,
} ;
char * V_459 = * V_476 , * V_148 = * V_476 ;
char * V_143 , * V_556 , * V_673 ;
const struct V_667 * V_674 = NULL ;
int V_675 = 0 , V_25 ;
while ( * V_148 != '\0' && * V_148 != ',' )
V_148 ++ ;
if ( * V_148 == '\0' )
* V_476 = V_148 ;
else
* V_476 = V_148 + 1 ;
* V_148 = '\0' ;
V_148 = strchr ( V_459 , ':' ) ;
if ( ! V_148 ) {
V_556 = F_340 ( V_459 ) ;
goto V_676;
}
* V_148 = '\0' ;
V_143 = F_340 ( V_459 ) ;
V_556 = F_340 ( V_148 + 1 ) ;
V_148 = strchr ( V_143 , '.' ) ;
if ( V_148 ) {
* V_148 ++ = '\0' ;
V_666 -> V_21 = F_341 ( V_148 , & V_673 , 10 ) ;
if ( V_148 == V_673 || * V_673 != '\0' ) {
* V_255 = L_214 ;
return - V_119 ;
}
}
V_666 -> V_30 = F_341 ( V_143 , & V_673 , 10 ) ;
if ( V_148 == V_673 || * V_673 != '\0' ) {
* V_255 = L_215 ;
return - V_119 ;
}
V_676:
for ( V_25 = 0 ; V_25 < F_37 ( V_668 ) ; V_25 ++ ) {
const struct V_667 * V_677 = & V_668 [ V_25 ] ;
if ( strncasecmp ( V_556 , V_677 -> V_35 , strlen ( V_556 ) ) )
continue;
V_675 ++ ;
V_674 = V_677 ;
if ( strcasecmp ( V_556 , V_677 -> V_35 ) == 0 ) {
V_675 = 1 ;
break;
}
}
if ( ! V_675 ) {
* V_255 = L_216 ;
return - V_119 ;
}
if ( V_675 > 1 ) {
* V_255 = L_217 ;
return - V_119 ;
}
V_666 -> V_32 = * V_674 ;
return 0 ;
}
static void T_9 F_342 ( void )
{
int V_678 = 0 , V_679 = 1 ;
int V_680 = - 1 , V_681 = - 1 ;
char * V_148 , * V_476 , * V_23 ;
for ( V_148 = V_682 ; * V_148 ; V_148 ++ )
if ( * V_148 == ',' )
V_679 ++ ;
V_29 = F_261 ( sizeof( V_29 [ 0 ] ) * V_679 , V_585 ) ;
if ( ! V_29 ) {
F_343 ( V_683 L_218
L_219 ) ;
return;
}
for ( V_476 = V_682 ; * V_476 != '\0' ; V_476 = V_23 ) {
const char * V_255 = L_67 ;
struct V_27 V_684 = { . V_30 = - 1 , . V_21 = - 1 } ;
V_23 = V_476 ;
if ( F_339 ( & V_23 , & V_684 , & V_255 ) ) {
F_343 ( V_683 L_220
L_221 ,
V_476 , V_255 ) ;
continue;
}
if ( V_684 . V_30 == - 1 ) {
V_684 . V_30 = V_680 ;
V_684 . V_21 = V_681 ;
}
V_29 [ V_678 ++ ] = V_684 ;
V_680 = V_684 . V_30 ;
V_681 = V_684 . V_21 ;
}
V_26 = V_678 ;
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
V_685 = F_347 () ;
if ( ! V_685 ) {
F_348 () ;
V_181 = - V_626 ;
goto V_264;
}
F_343 ( V_271 L_222 V_686 L_223 ) ;
return 0 ;
V_264:
return V_181 ;
}
static void T_10 F_349 ( void )
{
F_350 ( V_685 ) ;
F_351 () ;
F_348 () ;
F_275 ( V_29 ) ;
}
int F_352 ( void )
{
return F_353 ( & V_687 ) ;
}
void F_174 ( struct V_4 * V_5 , unsigned int V_688 )
{
bool V_689 = V_5 && V_5 -> V_273 -> V_690 == V_691 ;
if ( V_689 )
F_77 ( V_5 ) ;
F_180 ( V_688 ) ;
if ( V_689 )
F_80 ( V_5 ) ;
}
T_1 F_354 ( struct V_4 * V_5 , void T_11 * V_555 , T_1 V_385 , T_1 V_556 ,
unsigned long V_472 , unsigned long V_203 )
{
unsigned long V_458 ;
T_1 V_381 ;
V_381 = F_355 ( V_555 ) ;
V_458 = F_169 ( V_460 , V_203 ) ;
while ( ( V_381 & V_385 ) == V_556 && F_173 ( V_460 , V_458 ) ) {
F_174 ( V_5 , V_472 ) ;
V_381 = F_355 ( V_555 ) ;
}
return V_381 ;
}
static unsigned int F_356 ( struct V_193 * V_194 )
{
return V_213 ;
}
static void F_357 ( struct V_4 * V_5 )
{
}
int F_358 ( const struct V_4 * V_5 , const char * V_692 ,
const char * V_693 , ... )
{
struct V_694 V_695 ;
T_12 args ;
int V_696 ;
va_start ( args , V_693 ) ;
V_695 . V_693 = V_693 ;
V_695 . V_697 = & args ;
V_696 = F_343 ( L_224 , V_692 , V_5 -> V_31 , & V_695 ) ;
va_end ( args ) ;
return V_696 ;
}
int F_359 ( const struct V_2 * V_3 , const char * V_692 ,
const char * V_693 , ... )
{
struct V_694 V_695 ;
T_12 args ;
int V_696 ;
va_start ( args , V_693 ) ;
V_695 . V_693 = V_693 ;
V_695 . V_697 = & args ;
if ( F_4 ( V_3 -> V_5 ) || V_3 -> V_5 -> V_12 )
V_696 = F_343 ( L_225 ,
V_692 , V_3 -> V_5 -> V_31 , V_3 -> V_38 , & V_695 ) ;
else
V_696 = F_343 ( L_224 ,
V_692 , V_3 -> V_5 -> V_31 , & V_695 ) ;
va_end ( args ) ;
return V_696 ;
}
int F_360 ( const struct V_14 * V_15 , const char * V_692 ,
const char * V_693 , ... )
{
struct V_694 V_695 ;
T_12 args ;
int V_696 ;
va_start ( args , V_693 ) ;
V_695 . V_693 = V_693 ;
V_695 . V_697 = & args ;
V_696 = F_343 ( L_225 ,
V_692 , V_15 -> V_3 -> V_5 -> V_31 , V_15 -> V_3 -> V_38 + V_15 -> V_24 ,
& V_695 ) ;
va_end ( args ) ;
return V_696 ;
}
void F_361 ( const struct V_21 * V_15 , const char * V_698 )
{
F_362 ( V_271 , V_15 , L_226 , V_698 ) ;
}
