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
if ( ( V_15 -> V_48 & V_319 ) &&
( V_143 [ V_320 ] & 0xe ) == 0x2 )
V_15 -> V_48 |= V_321 ;
if ( V_15 -> V_48 & V_321 ) {
F_24 ( V_15 , L_86 ) ;
V_15 -> V_3 -> V_5 -> V_322 = V_323 ;
}
V_181 = F_119 ( V_15 ) ;
if ( V_181 )
return V_181 ;
V_181 = F_55 ( V_15 ) ;
if ( V_181 )
return V_181 ;
if ( F_117 ( V_5 ) )
F_96 ( V_15 ,
L_87
L_88 ,
V_259 ,
V_143 [ 49 ] , V_143 [ 82 ] , V_143 [ 83 ] , V_143 [ 84 ] ,
V_143 [ 85 ] , V_143 [ 86 ] , V_143 [ 87 ] , V_143 [ 88 ] ) ;
V_15 -> V_42 &= ~ V_324 ;
V_15 -> V_157 = 0 ;
V_15 -> V_325 = 0 ;
V_15 -> V_326 = 0 ;
V_15 -> V_327 = 0 ;
V_15 -> V_104 = 0 ;
V_15 -> V_105 = 0 ;
V_15 -> V_95 = 0 ;
V_47 = F_61 ( V_143 ) ;
if ( F_117 ( V_5 ) )
F_60 ( V_143 ) ;
F_41 ( V_15 -> V_143 , V_312 , V_328 ,
sizeof( V_312 ) ) ;
F_41 ( V_15 -> V_143 , V_314 , V_329 ,
sizeof( V_314 ) ) ;
if ( V_15 -> V_182 == V_138 ) {
if ( F_62 ( V_143 ) ) {
if ( V_143 [ V_330 ] & 1 )
F_24 ( V_15 ,
L_89 ) ;
snprintf ( V_311 , 7 , L_90 ) ;
} else {
snprintf ( V_311 , 7 , L_91 , F_101 ( V_143 ) ) ;
if ( F_120 ( V_143 ) )
F_24 ( V_15 ,
L_89 ) ;
}
V_15 -> V_326 = F_43 ( V_143 ) ;
if ( ( V_15 -> V_143 [ 47 ] >> 8 ) == 0x80 && ( V_15 -> V_143 [ 59 ] & 0x100 ) ) {
unsigned int V_331 = V_15 -> V_143 [ 47 ] & 0xff ;
unsigned int V_332 = V_15 -> V_143 [ 59 ] & 0xff ;
if ( F_121 ( V_331 ) && F_121 ( V_332 ) )
if ( V_332 <= V_331 )
V_15 -> V_95 = V_332 ;
}
if ( F_44 ( V_143 ) ) {
const char * V_333 ;
char V_334 [ 24 ] ;
V_333 = L_92 ;
V_15 -> V_42 |= V_117 ;
if ( F_45 ( V_143 ) ) {
V_15 -> V_42 |= V_118 ;
V_333 = L_93 ;
if ( V_15 -> V_326 >= ( 1UL << 28 ) &&
F_122 ( V_143 ) )
V_15 -> V_42 |= V_335 ;
}
V_181 = F_108 ( V_15 , V_334 , sizeof( V_334 ) ) ;
if ( V_181 )
return V_181 ;
if ( F_123 ( V_5 ) && V_175 ) {
F_57 ( V_15 , L_94 ,
V_311 , V_314 , V_312 ,
F_36 ( V_47 ) ) ;
F_57 ( V_15 ,
L_95 ,
( unsigned long long ) V_15 -> V_326 ,
V_15 -> V_95 , V_333 , V_334 ) ;
}
} else {
V_15 -> V_327 = V_143 [ 1 ] ;
V_15 -> V_104 = V_143 [ 3 ] ;
V_15 -> V_105 = V_143 [ 6 ] ;
if ( F_48 ( V_143 ) ) {
V_15 -> V_327 = V_143 [ 54 ] ;
V_15 -> V_104 = V_143 [ 55 ] ;
V_15 -> V_105 = V_143 [ 56 ] ;
}
if ( F_123 ( V_5 ) && V_175 ) {
F_57 ( V_15 , L_94 ,
V_311 , V_314 , V_312 ,
F_36 ( V_47 ) ) ;
F_57 ( V_15 ,
L_96 ,
( unsigned long long ) V_15 -> V_326 ,
V_15 -> V_95 , V_15 -> V_327 ,
V_15 -> V_104 , V_15 -> V_105 ) ;
}
}
if ( F_124 ( V_15 -> V_143 ) ) {
T_2 * V_336 = V_5 -> V_303 ;
int V_25 , V_337 ;
V_15 -> V_42 |= V_338 ;
V_158 = F_114 ( V_15 ,
V_339 ,
V_340 ,
V_336 ,
1 ) ;
if ( V_158 )
F_96 ( V_15 ,
L_97 ,
V_158 ) ;
else
for ( V_25 = 0 ; V_25 < V_341 ; V_25 ++ ) {
V_337 = V_342 + V_25 ;
V_15 -> V_343 [ V_25 ] = V_336 [ V_337 ] ;
}
}
V_15 -> V_325 = 16 ;
}
else if ( V_15 -> V_182 == V_139 ) {
const char * V_344 = L_67 ;
const char * V_345 = L_67 ;
const char * V_346 = L_67 ;
T_1 V_347 ;
V_181 = F_125 ( V_143 ) ;
if ( ( V_181 < 12 ) || ( V_181 > V_223 ) ) {
if ( F_84 ( V_5 ) )
F_24 ( V_15 , L_98 ) ;
V_181 = - V_119 ;
goto V_348;
}
V_15 -> V_325 = ( unsigned int ) V_181 ;
if ( V_349 &&
( V_5 -> V_42 & V_350 ) && F_126 ( V_143 ) &&
( ! F_4 ( V_5 ) ||
F_127 ( & V_5 -> V_3 , V_351 , & V_347 ) == 0 ) ) {
V_158 = F_100 ( V_15 ,
V_299 , V_352 ) ;
if ( V_158 )
F_59 ( V_15 ,
L_99 ,
V_158 ) ;
else {
V_15 -> V_42 |= V_353 ;
V_345 = L_100 ;
}
}
if ( F_128 ( V_15 -> V_143 ) ) {
V_15 -> V_42 |= V_354 ;
V_344 = L_101 ;
}
if ( V_355 || ( V_15 -> V_48 & V_356 ) || F_129 ( V_15 -> V_143 ) ) {
V_15 -> V_42 |= V_225 ;
V_346 = L_102 ;
}
if ( F_130 ( V_15 -> V_143 ) ) {
V_15 -> V_42 |= V_357 ;
F_131 ( V_15 ) ;
}
if ( F_123 ( V_5 ) && V_175 )
F_57 ( V_15 ,
L_103 ,
V_314 , V_312 ,
F_36 ( V_47 ) ,
V_344 , V_345 ,
V_346 ) ;
}
V_15 -> V_157 = V_358 ;
if ( V_15 -> V_42 & V_118 )
V_15 -> V_157 = V_359 ;
if ( F_105 ( V_15 ) ) {
if ( F_123 ( V_5 ) && V_175 )
F_57 ( V_15 , L_104 ) ;
V_15 -> V_46 &= V_360 ;
V_15 -> V_157 = V_358 ;
}
if ( ( V_15 -> V_182 == V_139 ) &&
( F_132 ( V_143 ) == V_361 ) ) {
V_15 -> V_157 = V_362 ;
V_15 -> V_48 |= V_363 ;
}
if ( V_15 -> V_48 & V_364 )
V_15 -> V_157 = F_133 (unsigned int, ATA_MAX_SECTORS_128,
dev->max_sectors) ;
if ( V_15 -> V_48 & V_365 )
V_15 -> V_157 = V_359 ;
if ( V_5 -> V_214 -> V_366 )
V_5 -> V_214 -> V_366 ( V_15 ) ;
if ( V_15 -> V_48 & V_367 ) {
if ( V_175 ) {
F_24 ( V_15 ,
L_105 ) ;
F_24 ( V_15 ,
L_106 ) ;
}
}
if ( ( V_15 -> V_48 & V_368 ) && V_175 ) {
F_24 ( V_15 , L_107 ) ;
F_24 ( V_15 , L_108 ) ;
}
return 0 ;
V_348:
if ( F_117 ( V_5 ) )
F_96 ( V_15 , L_109 , V_259 ) ;
return V_181 ;
}
int F_134 ( struct V_4 * V_5 )
{
return V_369 ;
}
int F_135 ( struct V_4 * V_5 )
{
return V_370 ;
}
int F_136 ( struct V_4 * V_5 )
{
return V_371 ;
}
int F_137 ( struct V_4 * V_5 )
{
return V_372 ;
}
int F_138 ( struct V_4 * V_5 )
{
return V_285 ;
}
int F_139 ( struct V_4 * V_5 )
{
unsigned int V_373 [ V_374 ] ;
int V_375 [ V_374 ] ;
int V_181 ;
struct V_14 * V_15 ;
F_140 (dev, &ap->link, ALL)
V_375 [ V_15 -> V_24 ] = V_376 ;
V_260:
F_140 (dev, &ap->link, ALL) {
V_15 -> V_248 = V_377 ;
V_15 -> V_378 = 0xff ;
if ( V_5 -> V_214 -> V_379 )
V_5 -> V_214 -> V_379 ( V_5 , V_15 ) ;
}
V_5 -> V_214 -> V_380 ( V_5 ) ;
F_140 (dev, &ap->link, ALL) {
if ( V_15 -> V_182 != V_142 )
V_373 [ V_15 -> V_24 ] = V_15 -> V_182 ;
else
V_373 [ V_15 -> V_24 ] = V_381 ;
V_15 -> V_182 = V_142 ;
}
F_140 (dev, &ap->link, ALL_REVERSE) {
if ( V_375 [ V_15 -> V_24 ] )
V_15 -> V_182 = V_373 [ V_15 -> V_24 ] ;
if ( ! F_8 ( V_15 ) )
continue;
V_181 = F_94 ( V_15 , & V_15 -> V_182 , V_276 ,
V_15 -> V_143 ) ;
if ( V_181 )
goto V_382;
}
if ( V_5 -> V_214 -> V_383 )
V_5 -> V_33 = V_5 -> V_214 -> V_383 ( V_5 ) ;
F_140 (dev, &ap->link, ENABLED)
if ( F_107 ( V_15 -> V_143 ) )
V_5 -> V_33 = V_285 ;
F_140 (dev, &ap->link, ENABLED) {
V_5 -> V_3 . V_174 . V_25 . V_42 |= V_176 ;
V_181 = F_115 ( V_15 ) ;
V_5 -> V_3 . V_174 . V_25 . V_42 &= ~ V_176 ;
if ( V_181 )
goto V_382;
}
V_181 = F_141 ( & V_5 -> V_3 , & V_15 ) ;
if ( V_181 )
goto V_382;
F_140 (dev, &ap->link, ENABLED)
return 0 ;
return - V_263 ;
V_382:
V_375 [ V_15 -> V_24 ] -- ;
switch ( V_181 ) {
case - V_119 :
V_375 [ V_15 -> V_24 ] = 0 ;
break;
case - V_263 :
V_375 [ V_15 -> V_24 ] = F_111 ( V_375 [ V_15 -> V_24 ] , 1 ) ;
case - V_166 :
if ( V_375 [ V_15 -> V_24 ] == 1 ) {
F_142 ( & V_5 -> V_3 , 0 ) ;
F_143 ( V_15 , V_384 ) ;
}
}
if ( ! V_375 [ V_15 -> V_24 ] )
F_118 ( V_15 ) ;
goto V_260;
}
static void F_144 ( struct V_2 * V_3 )
{
T_1 V_1 , V_385 , V_386 ;
if ( F_127 ( V_3 , V_387 , & V_1 ) )
return;
F_127 ( V_3 , V_388 , & V_385 ) ;
if ( F_145 ( V_3 ) ) {
V_386 = ( V_1 >> 4 ) & 0xf ;
F_146 ( V_3 , L_110 ,
F_38 ( V_386 ) , V_1 , V_385 ) ;
} else {
F_146 ( V_3 , L_111 ,
V_1 , V_385 ) ;
}
}
struct V_14 * F_147 ( struct V_14 * V_245 )
{
struct V_2 * V_3 = V_245 -> V_3 ;
struct V_14 * V_389 = & V_3 -> V_21 [ 1 - V_245 -> V_24 ] ;
if ( ! F_8 ( V_389 ) )
return NULL ;
return V_389 ;
}
int F_142 ( struct V_2 * V_3 , T_1 V_39 )
{
T_1 V_1 , V_136 , V_390 ;
int V_181 , V_391 ;
if ( ! F_104 ( V_3 ) )
return - V_392 ;
V_181 = F_127 ( V_3 , V_387 , & V_1 ) ;
if ( V_181 == 0 && F_1 ( V_1 ) )
V_136 = ( V_1 >> 4 ) & 0xf ;
else
V_136 = V_3 -> V_282 ;
V_390 = V_3 -> V_281 ;
if ( V_390 <= 1 )
return - V_119 ;
V_391 = F_33 ( V_390 ) - 1 ;
V_390 &= ~ ( 1 << V_391 ) ;
if ( V_136 > 1 )
V_390 &= ( 1 << ( V_136 - 1 ) ) - 1 ;
else
V_390 &= 1 ;
if ( ! V_390 )
return - V_119 ;
if ( V_39 ) {
if ( V_390 & ( ( 1 << V_39 ) - 1 ) )
V_390 &= ( 1 << V_39 ) - 1 ;
else {
V_391 = F_148 ( V_390 ) - 1 ;
V_390 = 1 << V_391 ;
}
}
V_3 -> V_281 = V_390 ;
F_149 ( V_3 , L_112 ,
F_38 ( F_33 ( V_390 ) ) ) ;
return 0 ;
}
static int F_150 ( struct V_2 * V_3 , T_1 * V_385 )
{
struct V_2 * V_393 = & V_3 -> V_5 -> V_3 ;
T_1 V_394 , V_278 , V_136 ;
V_394 = V_3 -> V_281 ;
if ( ! F_13 ( V_3 ) && V_393 -> V_282 )
V_394 &= ( 1 << V_393 -> V_282 ) - 1 ;
if ( V_394 == V_395 )
V_278 = 0 ;
else
V_278 = F_33 ( V_394 ) ;
V_136 = ( * V_385 >> 4 ) & 0xf ;
* V_385 = ( * V_385 & ~ 0xf0 ) | ( ( V_278 & 0xf ) << 4 ) ;
return V_136 != V_278 ;
}
static int F_151 ( struct V_2 * V_3 )
{
T_1 V_385 ;
if ( F_127 ( V_3 , V_388 , & V_385 ) )
return 1 ;
return F_150 ( V_3 , & V_385 ) ;
}
int F_152 ( struct V_2 * V_3 )
{
T_1 V_385 ;
int V_181 ;
if ( ( V_181 = F_127 ( V_3 , V_388 , & V_385 ) ) )
return V_181 ;
if ( ! F_150 ( V_3 , & V_385 ) )
return 0 ;
if ( ( V_181 = F_153 ( V_3 , V_388 , V_385 ) ) )
return V_181 ;
return 1 ;
}
static void F_154 ( const struct V_396 * V_397 , struct V_396 * V_398 , int V_399 , int V_400 )
{
V_398 -> V_401 = F_155 ( V_397 -> V_401 * 1000 , V_399 ) ;
V_398 -> V_402 = F_155 ( V_397 -> V_402 * 1000 , V_399 ) ;
V_398 -> V_403 = F_155 ( V_397 -> V_403 * 1000 , V_399 ) ;
V_398 -> V_404 = F_155 ( V_397 -> V_404 * 1000 , V_399 ) ;
V_398 -> V_405 = F_155 ( V_397 -> V_405 * 1000 , V_399 ) ;
V_398 -> V_406 = F_155 ( V_397 -> V_406 * 1000 , V_399 ) ;
V_398 -> V_407 = F_155 ( V_397 -> V_407 * 1000 , V_399 ) ;
V_398 -> V_408 = F_155 ( V_397 -> V_408 * 1000 , V_399 ) ;
V_398 -> V_409 = F_155 ( V_397 -> V_409 * 1000 , V_400 ) ;
}
void F_156 ( const struct V_396 * V_410 , const struct V_396 * V_411 ,
struct V_396 * V_412 , unsigned int V_413 )
{
if ( V_413 & V_414 ) V_412 -> V_401 = V_331 ( V_410 -> V_401 , V_411 -> V_401 ) ;
if ( V_413 & V_415 ) V_412 -> V_402 = V_331 ( V_410 -> V_402 , V_411 -> V_402 ) ;
if ( V_413 & V_416 ) V_412 -> V_403 = V_331 ( V_410 -> V_403 , V_411 -> V_403 ) ;
if ( V_413 & V_417 ) V_412 -> V_404 = V_331 ( V_410 -> V_404 , V_411 -> V_404 ) ;
if ( V_413 & V_418 ) V_412 -> V_405 = V_331 ( V_410 -> V_405 , V_411 -> V_405 ) ;
if ( V_413 & V_419 ) V_412 -> V_406 = V_331 ( V_410 -> V_406 , V_411 -> V_406 ) ;
if ( V_413 & V_420 ) V_412 -> V_407 = V_331 ( V_410 -> V_407 , V_411 -> V_407 ) ;
if ( V_413 & V_421 ) V_412 -> V_408 = V_331 ( V_410 -> V_408 , V_411 -> V_408 ) ;
if ( V_413 & V_422 ) V_412 -> V_409 = V_331 ( V_410 -> V_409 , V_411 -> V_409 ) ;
}
const struct V_396 * F_157 ( T_2 V_134 )
{
const struct V_396 * V_397 = V_396 ;
while ( V_134 > V_397 -> V_7 )
V_397 ++ ;
if ( V_134 == V_397 -> V_7 )
return V_397 ;
F_158 ( true , L_113 ,
V_259 , V_134 ) ;
return NULL ;
}
int F_159 ( struct V_14 * V_245 , unsigned short V_423 ,
struct V_396 * V_397 , int V_399 , int V_400 )
{
const T_4 * V_143 = V_245 -> V_143 ;
const struct V_396 * V_144 ;
struct V_396 V_148 ;
if ( ! ( V_144 = F_157 ( V_423 ) ) )
return - V_119 ;
memcpy ( V_397 , V_144 , sizeof( * V_144 ) ) ;
if ( V_143 [ V_185 ] & 2 ) {
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
if ( V_423 >= V_377 && V_423 < V_424 ) {
if ( V_423 <= V_251 )
V_148 . V_408 = V_148 . V_404 = V_143 [ V_252 ] ;
else if ( ( V_423 <= V_425 ) ||
( V_423 == V_249 && ! F_62 ( V_143 ) ) )
V_148 . V_408 = V_148 . V_404 = V_143 [ V_426 ] ;
} else if ( V_423 >= V_427 && V_423 <= V_428 )
V_148 . V_408 = V_143 [ V_429 ] ;
F_156 ( & V_148 , V_397 , V_397 , V_421 | V_417 ) ;
}
F_154 ( V_397 , V_397 , V_399 , V_400 ) ;
if ( V_423 > V_250 ) {
F_159 ( V_245 , V_245 -> V_248 , & V_148 , V_399 , V_400 ) ;
F_156 ( & V_148 , V_397 , V_397 , V_430 ) ;
}
if ( V_397 -> V_402 + V_397 -> V_403 < V_397 -> V_404 ) {
V_397 -> V_402 += ( V_397 -> V_404 - ( V_397 -> V_402 + V_397 -> V_403 ) ) / 2 ;
V_397 -> V_403 = V_397 -> V_404 - V_397 -> V_402 ;
}
if ( V_397 -> V_405 + V_397 -> V_406 < V_397 -> V_408 ) {
V_397 -> V_405 += ( V_397 -> V_408 - ( V_397 -> V_405 + V_397 -> V_406 ) ) / 2 ;
V_397 -> V_406 = V_397 -> V_408 - V_397 -> V_405 ;
}
if ( V_397 -> V_405 + V_397 -> V_406 > V_397 -> V_408 )
V_397 -> V_408 = V_397 -> V_405 + V_397 -> V_406 ;
return 0 ;
}
T_2 F_160 ( unsigned int V_431 , int V_408 )
{
T_2 V_432 = 0xff , V_433 = 0xff ;
const struct V_128 * V_129 ;
const struct V_396 * V_397 ;
for ( V_129 = V_130 ; V_129 -> V_131 >= 0 ; V_129 ++ )
if ( V_129 -> V_131 == V_431 )
V_432 = V_129 -> V_133 ;
for ( V_397 = F_157 ( V_432 ) ;
V_397 && F_35 ( V_397 -> V_7 ) == V_431 ; V_397 ++ ) {
unsigned short V_434 ;
switch ( V_431 ) {
case V_121 :
case V_123 :
V_434 = V_397 -> V_408 ;
break;
case V_125 :
V_434 = V_397 -> V_409 ;
break;
default:
return 0xff ;
}
if ( V_408 > V_434 )
break;
V_433 = V_397 -> V_7 ;
}
return V_433 ;
}
int F_143 ( struct V_14 * V_15 , unsigned int V_435 )
{
char V_243 [ 32 ] ;
unsigned long V_436 , V_47 ;
unsigned long V_44 , V_45 , V_46 ;
int V_437 , V_127 ;
V_437 = ! ! ( V_435 & V_438 ) ;
V_435 &= ~ V_438 ;
V_47 = V_436 = F_31 ( V_15 -> V_44 ,
V_15 -> V_45 ,
V_15 -> V_46 ) ;
F_16 ( V_47 , & V_44 , & V_45 , & V_46 ) ;
switch ( V_435 ) {
case V_384 :
V_127 = F_33 ( V_44 ) - 1 ;
V_44 &= ~ ( 1 << V_127 ) ;
break;
case V_439 :
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
case V_440 :
V_46 &= V_441 ;
break;
case V_442 :
V_44 &= 1 ;
case V_443 :
V_45 = 0 ;
V_46 = 0 ;
break;
default:
F_70 () ;
}
V_47 &= F_31 ( V_44 , V_45 , V_46 ) ;
if ( ! ( V_47 & V_122 ) || V_47 == V_436 )
return - V_268 ;
if ( ! V_437 ) {
if ( V_47 & ( V_124 | V_126 ) )
snprintf ( V_243 , sizeof( V_243 ) , L_114 ,
F_36 ( V_47 ) ,
F_36 ( V_47 & V_122 ) ) ;
else
snprintf ( V_243 , sizeof( V_243 ) , L_115 ,
F_36 ( V_47 ) ) ;
F_24 ( V_15 , L_116 , V_243 ) ;
}
F_16 ( V_47 , & V_15 -> V_44 , & V_15 -> V_45 ,
& V_15 -> V_46 ) ;
return 0 ;
}
static int F_161 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = V_15 -> V_3 -> V_5 ;
struct V_172 * V_173 = & V_15 -> V_3 -> V_174 ;
const bool V_444 = V_15 -> V_48 & V_445 ;
const char * V_446 = L_67 ;
int V_447 = 0 ;
unsigned int V_158 = 0 ;
int V_181 ;
V_15 -> V_42 &= ~ V_92 ;
if ( V_15 -> V_431 == V_121 )
V_15 -> V_42 |= V_92 ;
if ( V_444 && V_5 -> V_42 & V_448 && F_107 ( V_15 -> V_143 ) )
V_446 = L_117 ;
else {
if ( V_444 )
F_24 ( V_15 ,
L_118
L_119 ) ;
V_158 = F_162 ( V_15 ) ;
}
if ( V_158 & ~ V_163 )
goto V_382;
V_173 -> V_25 . V_42 |= V_449 ;
V_181 = F_163 ( V_15 , V_142 , 0 ) ;
V_173 -> V_25 . V_42 &= ~ V_449 ;
if ( V_181 )
return V_181 ;
if ( V_15 -> V_431 == V_121 ) {
if ( F_62 ( V_15 -> V_143 ) )
V_447 = 1 ;
if ( F_101 ( V_15 -> V_143 ) == 0 &&
V_15 -> V_248 <= V_251 )
V_447 = 1 ;
if ( ! F_91 ( V_15 -> V_143 ) && V_15 -> V_248 <= V_251 )
V_447 = 1 ;
}
if ( V_15 -> V_431 == V_123 &&
V_15 -> V_378 == V_427 &&
( V_15 -> V_143 [ 63 ] >> 8 ) & 1 )
V_447 = 1 ;
if ( V_15 -> V_134 == F_32 ( F_61 ( V_15 -> V_143 ) ) )
V_447 = 1 ;
if ( V_158 & V_163 ) {
if ( ! V_447 )
goto V_382;
else
V_446 = L_120 ;
}
F_30 ( L_121 ,
V_15 -> V_431 , ( int ) V_15 -> V_134 ) ;
F_57 ( V_15 , L_122 ,
F_36 ( F_34 ( V_15 -> V_134 ) ) ,
V_446 ) ;
return 0 ;
V_382:
F_59 ( V_15 , L_123 , V_158 ) ;
return - V_166 ;
}
int F_164 ( struct V_2 * V_3 , struct V_14 * * V_450 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_14 * V_15 ;
int V_181 = 0 , V_451 = 0 , V_452 = 0 ;
F_140 (dev, link, ENABLED) {
unsigned long V_44 , V_453 ;
unsigned int V_454 ;
V_454 = V_455 ;
if ( V_15 -> V_182 == V_139 )
V_454 = V_456 ;
else if ( F_62 ( V_15 -> V_143 ) )
V_454 = V_457 ;
F_165 ( V_15 ) ;
F_15 ( V_15 ) ;
V_44 = F_31 ( V_15 -> V_44 , 0 , 0 ) ;
if ( V_458 & V_454 )
V_453 = F_31 ( 0 , V_15 -> V_45 ,
V_15 -> V_46 ) ;
else
V_453 = 0 ;
V_15 -> V_248 = F_32 ( V_44 ) ;
V_15 -> V_378 = F_32 ( V_453 ) ;
V_452 = 1 ;
if ( F_166 ( V_15 ) )
V_451 = 1 ;
}
if ( ! V_452 )
goto V_459;
F_140 (dev, link, ENABLED) {
if ( V_15 -> V_248 == 0xff ) {
F_24 ( V_15 , L_124 ) ;
V_181 = - V_119 ;
goto V_459;
}
V_15 -> V_134 = V_15 -> V_248 ;
V_15 -> V_431 = V_121 ;
if ( V_5 -> V_214 -> V_379 )
V_5 -> V_214 -> V_379 ( V_5 , V_15 ) ;
}
F_140 (dev, link, ENABLED) {
if ( ! F_166 ( V_15 ) )
continue;
V_15 -> V_134 = V_15 -> V_378 ;
V_15 -> V_431 = F_35 ( V_15 -> V_378 ) ;
if ( V_5 -> V_214 -> V_460 )
V_5 -> V_214 -> V_460 ( V_5 , V_15 ) ;
}
F_140 (dev, link, ENABLED) {
V_181 = F_161 ( V_15 ) ;
if ( V_181 )
goto V_459;
}
if ( V_451 && ( V_5 -> V_273 -> V_42 & V_461 ) )
V_5 -> V_273 -> V_462 = V_5 ;
V_459:
if ( V_181 )
* V_450 = V_15 ;
return V_181 ;
}
int F_167 ( struct V_2 * V_3 , unsigned long V_463 ,
int (* F_168)( struct V_2 * V_3 ) )
{
unsigned long V_464 = V_465 ;
unsigned long V_466 ;
int V_467 = 0 ;
if ( V_3 -> V_5 -> V_273 -> V_42 & V_468 )
V_466 = F_169 ( V_464 , V_469 ) ;
else
V_466 = F_169 ( V_464 , V_470 ) ;
F_87 ( V_3 == V_3 -> V_5 -> V_12 ) ;
if ( F_170 ( V_466 , V_463 ) )
V_466 = V_463 ;
while ( 1 ) {
unsigned long V_471 = V_465 ;
int V_472 , V_386 ;
V_472 = V_386 = F_168 ( V_3 ) ;
if ( V_472 > 0 )
return 0 ;
if ( V_472 == - V_263 ) {
if ( F_171 ( V_3 ) )
V_472 = 0 ;
else if ( ( V_3 -> V_5 -> V_42 & V_448 ) &&
! F_172 ( V_3 ) &&
F_173 ( V_471 , V_466 ) )
V_472 = 0 ;
}
if ( V_472 )
return V_472 ;
if ( F_170 ( V_471 , V_463 ) )
return - V_473 ;
if ( ! V_467 && F_170 ( V_471 , V_464 + 5 * V_474 ) &&
( V_463 - V_471 > 3 * V_474 ) ) {
F_149 ( V_3 ,
L_125
L_126 , V_386 ) ;
V_467 = 1 ;
}
F_174 ( V_3 -> V_5 , 50 ) ;
}
}
int F_175 ( struct V_2 * V_3 , unsigned long V_463 ,
int (* F_168)( struct V_2 * V_3 ) )
{
F_174 ( V_3 -> V_5 , V_475 ) ;
return F_167 ( V_3 , V_463 , F_168 ) ;
}
int F_176 ( struct V_2 * V_3 , const unsigned long * V_476 ,
unsigned long V_463 )
{
unsigned long V_477 = V_476 [ 0 ] ;
unsigned long V_478 = V_476 [ 1 ] ;
unsigned long V_479 , V_397 ;
T_1 V_480 , V_481 ;
int V_181 ;
V_397 = F_169 ( V_465 , V_476 [ 2 ] ) ;
if ( F_173 ( V_397 , V_463 ) )
V_463 = V_397 ;
if ( ( V_181 = F_127 ( V_3 , V_387 , & V_481 ) ) )
return V_181 ;
V_481 &= 0xf ;
V_480 = V_481 ;
V_479 = V_465 ;
while ( 1 ) {
F_174 ( V_3 -> V_5 , V_477 ) ;
if ( ( V_181 = F_127 ( V_3 , V_387 , & V_481 ) ) )
return V_181 ;
V_481 &= 0xf ;
if ( V_481 == V_480 ) {
if ( V_481 == 1 && F_173 ( V_465 , V_463 ) )
continue;
if ( F_170 ( V_465 ,
F_169 ( V_479 , V_478 ) ) )
return 0 ;
continue;
}
V_480 = V_481 ;
V_479 = V_465 ;
if ( F_170 ( V_465 , V_463 ) )
return - V_482 ;
}
}
int F_177 ( struct V_2 * V_3 , const unsigned long * V_476 ,
unsigned long V_463 )
{
int V_375 = V_483 ;
T_1 V_385 , V_484 ;
int V_181 ;
if ( ( V_181 = F_127 ( V_3 , V_388 , & V_385 ) ) )
return V_181 ;
do {
V_385 = ( V_385 & 0x0f0 ) | 0x300 ;
if ( ( V_181 = F_153 ( V_3 , V_388 , V_385 ) ) )
return V_181 ;
F_174 ( V_3 -> V_5 , 200 ) ;
if ( ( V_181 = F_127 ( V_3 , V_388 , & V_385 ) ) )
return V_181 ;
} while ( ( V_385 & 0xf0f ) != 0x300 && -- V_375 );
if ( ( V_385 & 0xf0f ) != 0x300 ) {
F_149 ( V_3 , L_127 ,
V_385 ) ;
return 0 ;
}
if ( V_375 < V_483 )
F_149 ( V_3 , L_128 ,
V_483 - V_375 ) ;
if ( ( V_181 = F_176 ( V_3 , V_476 , V_463 ) ) )
return V_181 ;
if ( ! ( V_181 = F_127 ( V_3 , V_485 , & V_484 ) ) )
V_181 = F_153 ( V_3 , V_485 , V_484 ) ;
return V_181 != - V_119 ? V_181 : 0 ;
}
int F_178 ( struct V_2 * V_3 , enum V_486 V_487 ,
bool V_488 )
{
struct V_172 * V_173 = & V_3 -> V_174 ;
bool V_489 = false ;
T_1 V_385 ;
int V_181 ;
V_181 = F_127 ( V_3 , V_388 , & V_385 ) ;
if ( V_181 )
return V_181 ;
switch ( V_487 ) {
case V_323 :
V_385 |= ( 0x7 << 8 ) ;
if ( V_488 ) {
V_385 |= ( 0x4 << 12 ) ;
V_489 = true ;
}
break;
case V_490 :
V_385 &= ~ ( 0x1 << 8 ) ;
V_385 |= ( 0x6 << 8 ) ;
break;
case V_491 :
if ( F_179 ( V_3 ) > 0 )
V_385 &= ~ ( 0x7 << 8 ) ;
else {
V_385 &= ~ 0xf ;
V_385 |= ( 0x1 << 2 ) ;
}
break;
default:
F_87 ( 1 ) ;
}
V_181 = F_153 ( V_3 , V_388 , V_385 ) ;
if ( V_181 )
return V_181 ;
if ( V_489 )
F_180 ( 10 ) ;
V_173 -> V_25 . V_484 &= ~ V_492 ;
return F_153 ( V_3 , V_485 , V_492 ) ;
}
int F_181 ( struct V_2 * V_3 , unsigned long V_463 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_172 * V_173 = & V_3 -> V_174 ;
const unsigned long * V_493 = F_182 ( V_173 ) ;
int V_181 ;
if ( V_173 -> V_25 . V_494 & V_495 )
return 0 ;
if ( V_5 -> V_42 & V_448 ) {
V_181 = F_177 ( V_3 , V_493 , V_463 ) ;
if ( V_181 && V_181 != - V_392 )
F_149 ( V_3 ,
L_129 ,
V_181 ) ;
}
if ( F_183 ( V_3 ) )
V_173 -> V_25 . V_494 &= ~ V_496 ;
return 0 ;
}
int F_184 ( struct V_2 * V_3 , const unsigned long * V_493 ,
unsigned long V_463 ,
bool * V_497 , int (* F_168)( struct V_2 * ) )
{
T_1 V_385 ;
int V_181 ;
F_30 ( L_130 ) ;
if ( V_497 )
* V_497 = false ;
if ( F_151 ( V_3 ) ) {
if ( ( V_181 = F_127 ( V_3 , V_388 , & V_385 ) ) )
goto V_459;
V_385 = ( V_385 & 0x0f0 ) | 0x304 ;
if ( ( V_181 = F_153 ( V_3 , V_388 , V_385 ) ) )
goto V_459;
F_152 ( V_3 ) ;
}
if ( ( V_181 = F_127 ( V_3 , V_388 , & V_385 ) ) )
goto V_459;
V_385 = ( V_385 & 0x0f0 ) | 0x301 ;
if ( ( V_181 = F_185 ( V_3 , V_388 , V_385 ) ) )
goto V_459;
F_174 ( V_3 -> V_5 , 1 ) ;
V_181 = F_177 ( V_3 , V_493 , V_463 ) ;
if ( V_181 )
goto V_459;
if ( F_183 ( V_3 ) )
goto V_459;
if ( V_497 )
* V_497 = true ;
if ( F_186 ( V_3 -> V_5 ) && F_13 ( V_3 ) ) {
if ( F_168 ) {
unsigned long V_498 ;
V_498 = F_169 ( V_465 ,
V_499 ) ;
if ( F_170 ( V_498 , V_463 ) )
V_498 = V_463 ;
F_167 ( V_3 , V_498 , F_168 ) ;
}
V_181 = - V_283 ;
goto V_459;
}
V_181 = 0 ;
if ( F_168 )
V_181 = F_167 ( V_3 , V_463 , F_168 ) ;
V_459:
if ( V_181 && V_181 != - V_283 ) {
if ( V_497 )
* V_497 = false ;
F_187 ( V_3 , L_131 , V_181 ) ;
}
F_30 ( L_132 , V_181 ) ;
return V_181 ;
}
int F_188 ( struct V_2 * V_3 , unsigned int * V_182 ,
unsigned long V_463 )
{
const unsigned long * V_493 = F_182 ( & V_3 -> V_174 ) ;
bool V_497 ;
int V_181 ;
V_181 = F_184 ( V_3 , V_493 , V_463 , & V_497 , NULL ) ;
return V_497 ? - V_283 : V_181 ;
}
void F_189 ( struct V_2 * V_3 , unsigned int * V_373 )
{
T_1 V_484 ;
F_30 ( L_130 ) ;
if ( ! F_127 ( V_3 , V_485 , & V_484 ) )
F_153 ( V_3 , V_485 , V_484 ) ;
F_144 ( V_3 ) ;
F_30 ( L_133 ) ;
}
static int F_190 ( struct V_14 * V_15 , unsigned int V_500 ,
const T_4 * V_501 )
{
const T_4 * V_502 = V_15 -> V_143 ;
unsigned char V_503 [ 2 ] [ V_315 + 1 ] ;
unsigned char V_504 [ 2 ] [ V_505 + 1 ] ;
if ( V_15 -> V_182 != V_500 ) {
F_57 ( V_15 , L_134 ,
V_15 -> V_182 , V_500 ) ;
return 0 ;
}
F_41 ( V_502 , V_503 [ 0 ] , V_329 , sizeof( V_503 [ 0 ] ) ) ;
F_41 ( V_501 , V_503 [ 1 ] , V_329 , sizeof( V_503 [ 1 ] ) ) ;
F_41 ( V_502 , V_504 [ 0 ] , V_506 , sizeof( V_504 [ 0 ] ) ) ;
F_41 ( V_501 , V_504 [ 1 ] , V_506 , sizeof( V_504 [ 1 ] ) ) ;
if ( strcmp ( V_503 [ 0 ] , V_503 [ 1 ] ) ) {
F_57 ( V_15 , L_135 ,
V_503 [ 0 ] , V_503 [ 1 ] ) ;
return 0 ;
}
if ( strcmp ( V_504 [ 0 ] , V_504 [ 1 ] ) ) {
F_57 ( V_15 , L_136 ,
V_504 [ 0 ] , V_504 [ 1 ] ) ;
return 0 ;
}
return 1 ;
}
int F_58 ( struct V_14 * V_15 , unsigned int V_507 )
{
unsigned int V_182 = V_15 -> V_182 ;
T_4 * V_143 = ( void * ) V_15 -> V_3 -> V_5 -> V_303 ;
int V_181 ;
V_181 = F_94 ( V_15 , & V_182 , V_507 , V_143 ) ;
if ( V_181 )
return V_181 ;
if ( ! F_190 ( V_15 , V_182 , V_143 ) )
return - V_263 ;
memcpy ( V_15 -> V_143 , V_143 , sizeof( V_143 [ 0 ] ) * V_253 ) ;
return 0 ;
}
int F_163 ( struct V_14 * V_15 , unsigned int V_500 ,
unsigned int V_507 )
{
T_3 V_326 = V_15 -> V_326 ;
T_3 V_184 = V_15 -> V_184 ;
int V_181 ;
if ( ! F_8 ( V_15 ) )
return - V_263 ;
if ( F_191 ( V_500 ) &&
V_500 != V_138 &&
V_500 != V_139 &&
V_500 != V_141 ) {
F_57 ( V_15 , L_137 ,
V_15 -> V_182 , V_500 ) ;
V_181 = - V_263 ;
goto V_382;
}
V_181 = F_58 ( V_15 , V_507 ) ;
if ( V_181 )
goto V_382;
V_181 = F_115 ( V_15 ) ;
if ( V_181 )
goto V_382;
if ( V_15 -> V_182 != V_138 || ! V_326 ||
V_15 -> V_326 == V_326 )
return 0 ;
F_24 ( V_15 , L_138 ,
( unsigned long long ) V_326 ,
( unsigned long long ) V_15 -> V_326 ) ;
if ( V_15 -> V_184 == V_184 &&
V_15 -> V_326 > V_326 && V_15 -> V_326 == V_184 ) {
F_24 ( V_15 ,
L_139
L_140 ) ;
return 0 ;
}
if ( V_15 -> V_184 == V_184 &&
V_15 -> V_326 < V_326 && V_326 == V_184 &&
! ( V_15 -> V_48 & V_183 ) ) {
F_24 ( V_15 ,
L_141
L_142 ) ;
V_15 -> V_42 |= V_179 ;
V_181 = - V_166 ;
} else
V_181 = - V_263 ;
V_15 -> V_184 = V_184 ;
V_15 -> V_326 = V_326 ;
V_382:
F_59 ( V_15 , L_143 , V_181 ) ;
return V_181 ;
}
static int F_192 ( const char * V_508 , const char * V_509 )
{
do {
if ( * V_508 == * V_509 || * V_509 == '?' ) {
if ( ! * V_509 ++ )
return 0 ;
} else {
if ( ! * V_508 || * V_509 != '[' )
break;
while ( * ++ V_509 && * V_509 != ']' && * V_508 != * V_509 ) {
if ( * V_509 == '-' && * ( V_509 - 1 ) != '[' )
if ( * V_508 > * ( V_509 - 1 ) && * V_508 < * ( V_509 + 1 ) ) {
++ V_509 ;
break;
}
}
if ( ! * V_509 || * V_509 == ']' )
return 1 ;
while ( * V_509 && * V_509 ++ != ']' ) ;
}
} while ( * ++ V_508 && * V_509 );
if ( * V_509 == '*' ) {
if ( ! * ++ V_509 )
return 0 ;
while ( * V_508 ) {
if ( F_192 ( V_508 , V_509 ) == 0 )
return 0 ;
++ V_508 ;
}
}
if ( ! * V_508 && ! * V_509 )
return 0 ;
return 1 ;
}
static unsigned long F_106 ( const struct V_14 * V_15 )
{
unsigned char V_510 [ V_315 + 1 ] ;
unsigned char V_511 [ V_313 + 1 ] ;
const struct V_512 * V_513 = V_514 ;
F_41 ( V_15 -> V_143 , V_510 , V_329 , sizeof( V_510 ) ) ;
F_41 ( V_15 -> V_143 , V_511 , V_328 , sizeof( V_511 ) ) ;
while ( V_513 -> V_510 ) {
if ( ! F_192 ( V_510 , V_513 -> V_510 ) ) {
if ( V_513 -> V_511 == NULL )
return V_513 -> V_48 ;
if ( ! F_192 ( V_511 , V_513 -> V_511 ) )
return V_513 -> V_48 ;
}
V_513 ++ ;
}
return 0 ;
}
static int F_193 ( const struct V_14 * V_15 )
{
if ( ( V_15 -> V_3 -> V_5 -> V_42 & V_515 ) &&
( V_15 -> V_42 & V_354 ) )
return 1 ;
return ( V_15 -> V_48 & V_516 ) ? 1 : 0 ;
}
static int F_194 ( struct V_14 * V_15 )
{
if ( V_15 -> V_48 & V_517 )
return F_195 ( V_15 -> V_143 ) ;
return F_196 ( V_15 -> V_143 ) ;
}
static int F_197 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
struct V_14 * V_15 ;
if ( V_5 -> V_33 == V_369 )
return 1 ;
if ( V_5 -> V_33 == V_370 || V_5 -> V_33 == V_285 )
return 0 ;
if ( V_5 -> V_33 == V_518 )
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
struct V_519 * V_273 = V_5 -> V_273 ;
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
L_144 ) ;
}
if ( ( V_273 -> V_42 & V_461 ) &&
V_273 -> V_462 && V_273 -> V_462 != V_5 ) {
V_47 &= ~ ( V_124 | V_126 ) ;
F_24 ( V_15 ,
L_145 ) ;
}
if ( V_5 -> V_42 & V_247 )
V_47 &= F_92 ( V_15 ) ;
if ( V_5 -> V_214 -> V_520 )
V_47 = V_5 -> V_214 -> V_520 ( V_15 , V_47 ) ;
if ( V_47 & ( 0xF8 << V_125 ) )
if ( F_197 ( V_5 ) ) {
F_24 ( V_15 ,
L_146 ) ;
V_47 &= ~ ( 0xF8 << V_125 ) ;
}
F_16 ( V_47 , & V_15 -> V_44 ,
& V_15 -> V_45 , & V_15 -> V_46 ) ;
}
static unsigned int F_162 ( struct V_14 * V_15 )
{
struct V_67 V_68 ;
unsigned int V_158 ;
F_30 ( L_147 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_521 ;
V_68 . V_72 = V_522 ;
V_68 . V_42 |= V_109 | V_110 | V_265 ;
V_68 . V_93 = V_161 ;
if ( F_90 ( V_15 ) )
V_68 . V_80 = V_15 -> V_134 ;
else if ( F_91 ( V_15 -> V_143 ) )
V_68 . V_80 = 0x01 ;
else
return 0 ;
V_158 = F_53 ( V_15 , & V_68 , NULL , V_162 , NULL , 0 , 0 ) ;
F_30 ( L_148 , V_158 ) ;
return V_158 ;
}
unsigned int F_100 ( struct V_14 * V_15 , T_2 V_523 , T_2 V_72 )
{
struct V_67 V_68 ;
unsigned int V_158 ;
F_30 ( L_149 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_521 ;
V_68 . V_72 = V_523 ;
V_68 . V_42 |= V_109 | V_110 ;
V_68 . V_93 = V_161 ;
V_68 . V_80 = V_72 ;
V_158 = F_53 ( V_15 , & V_68 , NULL , V_162 , NULL , 0 , 0 ) ;
F_30 ( L_148 , V_158 ) ;
return V_158 ;
}
static unsigned int F_102 ( struct V_14 * V_15 ,
T_4 V_104 , T_4 V_105 )
{
struct V_67 V_68 ;
unsigned int V_158 ;
if ( V_105 < 1 || V_105 > 255 || V_104 < 1 || V_104 > 16 )
return V_524 ;
F_30 ( L_150 ) ;
F_52 ( V_15 , & V_68 ) ;
V_68 . V_71 = V_525 ;
V_68 . V_42 |= V_109 | V_110 ;
V_68 . V_93 = V_161 ;
V_68 . V_80 = V_105 ;
V_68 . V_21 |= ( V_104 - 1 ) & 0x0f ;
V_158 = F_53 ( V_15 , & V_68 , NULL , V_162 , NULL , 0 , 0 ) ;
if ( V_158 == V_163 && ( V_68 . V_72 & V_164 ) )
V_158 = 0 ;
F_30 ( L_148 , V_158 ) ;
return V_158 ;
}
void F_199 ( struct V_193 * V_194 )
{
struct V_4 * V_5 = V_194 -> V_5 ;
struct V_200 * V_230 = V_194 -> V_230 ;
int V_526 = V_194 -> V_199 ;
F_200 ( V_230 == NULL ) ;
F_201 ( L_151 , V_194 -> V_202 ) ;
if ( V_194 -> V_202 )
F_202 ( V_5 -> V_15 , V_230 , V_194 -> V_527 , V_526 ) ;
V_194 -> V_42 &= ~ V_528 ;
V_194 -> V_230 = NULL ;
}
int F_203 ( struct V_193 * V_194 )
{
struct V_4 * V_5 = V_194 -> V_5 ;
if ( ! ( V_194 -> V_15 -> V_48 & V_529 ) &&
F_5 ( V_194 -> V_232 & 15 ) )
return 1 ;
if ( V_5 -> V_214 -> V_530 )
return V_5 -> V_214 -> V_530 ( V_194 ) ;
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
return V_531 ;
}
void F_206 ( struct V_193 * V_194 ) { }
void F_74 ( struct V_193 * V_194 , struct V_200 * V_230 ,
unsigned int V_202 )
{
V_194 -> V_230 = V_230 ;
V_194 -> V_202 = V_202 ;
V_194 -> V_532 = V_194 -> V_230 ;
}
static int F_207 ( struct V_193 * V_194 )
{
struct V_4 * V_5 = V_194 -> V_5 ;
unsigned int V_202 ;
F_201 ( L_152 , V_5 -> V_31 ) ;
V_202 = F_208 ( V_5 -> V_15 , V_194 -> V_230 , V_194 -> V_202 , V_194 -> V_199 ) ;
if ( V_202 < 1 )
return - 1 ;
F_30 ( L_153 , V_202 ) ;
V_194 -> V_527 = V_194 -> V_202 ;
V_194 -> V_202 = V_202 ;
V_194 -> V_42 |= V_528 ;
return 0 ;
}
void F_98 ( T_4 * V_243 , unsigned int V_533 )
{
#ifdef F_209
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < V_533 ; V_25 ++ )
V_243 [ V_25 ] = F_210 ( V_243 [ V_25 ] ) ;
#endif
}
static struct V_193 * F_211 ( struct V_4 * V_5 )
{
struct V_193 * V_194 = NULL ;
unsigned int V_25 , V_108 ;
if ( F_5 ( V_5 -> V_211 & V_212 ) )
return NULL ;
for ( V_25 = 0 ; V_25 < V_295 ; V_25 ++ ) {
V_108 = ( V_25 + V_5 -> V_534 + 1 ) % V_295 ;
if ( V_108 == V_111 )
continue;
if ( ! F_69 ( V_108 , & V_5 -> V_216 ) ) {
V_194 = F_71 ( V_5 , V_108 ) ;
V_194 -> V_108 = V_108 ;
V_5 -> V_534 = V_108 ;
break;
}
}
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
if ( F_27 ( V_194 -> V_42 & V_528 ) )
F_199 ( V_194 ) ;
if ( V_194 -> V_68 . V_93 == V_113 ) {
V_3 -> V_219 &= ~ ( 1 << V_194 -> V_108 ) ;
if ( ! V_3 -> V_219 )
V_5 -> V_221 -- ;
} else {
V_3 -> V_218 = V_222 ;
V_5 -> V_221 -- ;
}
if ( F_5 ( V_194 -> V_42 & V_535 &&
V_5 -> V_536 == V_3 ) )
V_5 -> V_536 = NULL ;
V_194 -> V_42 &= ~ V_235 ;
V_5 -> V_220 &= ~ ( 1 << V_194 -> V_108 ) ;
V_194 -> V_233 ( V_194 ) ;
}
static void F_215 ( struct V_193 * V_194 )
{
struct V_4 * V_5 = V_194 -> V_5 ;
V_194 -> V_239 . V_42 = V_194 -> V_68 . V_42 ;
V_5 -> V_214 -> V_537 ( V_194 ) ;
}
static void F_216 ( struct V_193 * V_194 )
{
struct V_14 * V_15 = V_194 -> V_15 ;
if ( F_217 ( V_194 -> V_68 . V_93 ) )
return;
if ( ( V_15 -> V_45 || V_15 -> V_46 ) && F_218 ( V_194 -> V_68 . V_93 ) )
return;
V_15 -> V_42 &= ~ V_538 ;
}
void F_83 ( struct V_193 * V_194 )
{
struct V_4 * V_5 = V_194 -> V_5 ;
if ( V_5 -> V_214 -> V_215 ) {
struct V_14 * V_15 = V_194 -> V_15 ;
struct V_539 * V_540 = & V_15 -> V_3 -> V_541 ;
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
case V_521 :
if ( V_194 -> V_68 . V_72 != V_542 &&
V_194 -> V_68 . V_72 != V_543 )
break;
case V_525 :
case V_544 :
V_540 -> V_545 [ V_15 -> V_24 ] |= V_546 ;
F_221 ( V_5 ) ;
break;
case V_547 :
V_15 -> V_42 |= V_548 ;
break;
}
if ( F_5 ( V_15 -> V_42 & V_538 ) )
F_216 ( V_194 ) ;
F_214 ( V_194 ) ;
} else {
if ( V_194 -> V_42 & V_549 )
return;
if ( V_194 -> V_158 || V_194 -> V_42 & V_228 )
F_215 ( V_194 ) ;
F_214 ( V_194 ) ;
}
}
int F_222 ( struct V_4 * V_5 , T_1 V_220 )
{
int V_550 = 0 ;
T_1 V_551 ;
V_551 = V_5 -> V_220 ^ V_220 ;
if ( F_5 ( V_551 & V_220 ) ) {
F_223 ( V_5 , L_154 ,
V_5 -> V_220 , V_220 ) ;
return - V_119 ;
}
while ( V_551 ) {
struct V_193 * V_194 ;
unsigned int V_108 = F_224 ( V_551 ) ;
V_194 = F_225 ( V_5 , V_108 ) ;
if ( V_194 ) {
F_83 ( V_194 ) ;
V_550 ++ ;
}
V_551 &= ~ ( 1 << V_108 ) ;
}
return V_550 ;
}
void F_75 ( struct V_193 * V_194 )
{
struct V_4 * V_5 = V_194 -> V_5 ;
struct V_2 * V_3 = V_194 -> V_15 -> V_3 ;
T_2 V_552 = V_194 -> V_68 . V_93 ;
F_200 ( V_5 -> V_214 -> V_215 && F_205 ( V_3 -> V_218 ) ) ;
if ( F_226 ( V_552 ) ) {
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
if ( F_200 ( F_227 ( V_552 ) &&
( ! V_194 -> V_230 || ! V_194 -> V_202 || ! V_194 -> V_232 ) ) )
goto V_553;
if ( F_228 ( V_552 ) || ( F_218 ( V_552 ) &&
( V_5 -> V_42 & V_554 ) ) )
if ( F_207 ( V_194 ) )
goto V_553;
if ( F_5 ( V_194 -> V_15 -> V_42 & V_548 ) ) {
V_3 -> V_541 . V_494 |= V_555 ;
F_229 ( & V_3 -> V_541 , L_155 ) ;
F_230 ( V_3 ) ;
return;
}
V_5 -> V_214 -> V_556 ( V_194 ) ;
V_194 -> V_158 |= V_5 -> V_214 -> V_557 ( V_194 ) ;
if ( F_5 ( V_194 -> V_158 ) )
goto V_558;
return;
V_553:
V_194 -> V_158 |= V_213 ;
V_558:
F_83 ( V_194 ) ;
}
int F_104 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
return ( V_5 -> V_42 & V_448 ) && V_5 -> V_214 -> V_559 ;
}
int F_127 ( struct V_2 * V_3 , int V_560 , T_1 * V_561 )
{
if ( F_13 ( V_3 ) ) {
if ( F_104 ( V_3 ) )
return V_3 -> V_5 -> V_214 -> V_559 ( V_3 , V_560 , V_561 ) ;
return - V_392 ;
}
return F_231 ( V_3 , V_560 , V_561 ) ;
}
int F_153 ( struct V_2 * V_3 , int V_560 , T_1 V_561 )
{
if ( F_13 ( V_3 ) ) {
if ( F_104 ( V_3 ) )
return V_3 -> V_5 -> V_214 -> V_562 ( V_3 , V_560 , V_561 ) ;
return - V_392 ;
}
return F_232 ( V_3 , V_560 , V_561 ) ;
}
int F_185 ( struct V_2 * V_3 , int V_560 , T_1 V_561 )
{
if ( F_13 ( V_3 ) ) {
int V_181 ;
if ( F_104 ( V_3 ) ) {
V_181 = V_3 -> V_5 -> V_214 -> V_562 ( V_3 , V_560 , V_561 ) ;
if ( V_181 == 0 )
V_181 = V_3 -> V_5 -> V_214 -> V_559 ( V_3 , V_560 , & V_561 ) ;
return V_181 ;
}
return - V_392 ;
}
return F_232 ( V_3 , V_560 , V_561 ) ;
}
bool F_145 ( struct V_2 * V_3 )
{
T_1 V_1 ;
if ( F_127 ( V_3 , V_387 , & V_1 ) == 0 &&
F_1 ( V_1 ) )
return true ;
return false ;
}
bool F_183 ( struct V_2 * V_3 )
{
T_1 V_1 ;
if ( F_127 ( V_3 , V_387 , & V_1 ) == 0 &&
! F_1 ( V_1 ) )
return true ;
return false ;
}
bool F_171 ( struct V_2 * V_3 )
{
struct V_2 * V_563 = V_3 -> V_5 -> V_12 ;
F_87 ( V_3 == V_563 ) ;
return F_145 ( V_3 ) ||
( V_563 && F_145 ( V_563 ) ) ;
}
bool F_172 ( struct V_2 * V_3 )
{
struct V_2 * V_563 = V_3 -> V_5 -> V_12 ;
F_87 ( V_3 == V_563 ) ;
return F_183 ( V_3 ) &&
( ! V_563 || F_183 ( V_563 ) ) ;
}
static void F_233 ( struct V_4 * V_5 , T_6 V_564 ,
unsigned int V_494 , unsigned int V_565 ,
bool V_566 )
{
struct V_2 * V_3 ;
unsigned long V_42 ;
if ( V_5 -> V_211 & V_567 ) {
F_234 ( V_5 ) ;
F_87 ( V_5 -> V_211 & V_567 ) ;
}
F_67 ( V_5 -> V_210 , V_42 ) ;
V_5 -> V_568 = V_564 ;
V_5 -> V_211 |= V_567 ;
F_198 (link, ap, HOST_FIRST) {
V_3 -> V_541 . V_494 |= V_494 ;
V_3 -> V_541 . V_42 |= V_565 ;
}
F_221 ( V_5 ) ;
F_68 ( V_5 -> V_210 , V_42 ) ;
if ( ! V_566 ) {
F_234 ( V_5 ) ;
F_87 ( V_5 -> V_211 & V_567 ) ;
}
}
static void F_235 ( struct V_4 * V_5 , T_6 V_564 )
{
F_233 ( V_5 , V_564 , 0 , V_569 , false ) ;
}
static void F_236 ( struct V_4 * V_5 , T_6 V_564 )
{
F_233 ( V_5 , V_564 , 0 , V_569 , true ) ;
}
static int F_237 ( struct V_21 * V_15 )
{
struct V_4 * V_5 = F_238 ( V_15 ) ;
if ( F_239 ( V_15 ) )
return 0 ;
F_235 ( V_5 , V_570 ) ;
return 0 ;
}
static int F_240 ( struct V_21 * V_15 )
{
struct V_4 * V_5 = F_238 ( V_15 ) ;
if ( F_239 ( V_15 ) )
return 0 ;
F_235 ( V_5 , V_571 ) ;
return 0 ;
}
static int F_241 ( struct V_21 * V_15 )
{
F_235 ( F_238 ( V_15 ) , V_572 ) ;
return 0 ;
}
static void F_242 ( struct V_4 * V_5 , T_6 V_564 )
{
F_233 ( V_5 , V_564 , V_555 , V_573 , false ) ;
}
static void F_243 ( struct V_4 * V_5 , T_6 V_564 )
{
F_233 ( V_5 , V_564 , V_555 , V_573 , true ) ;
}
static int F_244 ( struct V_21 * V_15 )
{
F_243 ( F_238 ( V_15 ) , V_574 ) ;
F_245 ( V_15 ) ;
F_246 ( V_15 ) ;
F_247 ( V_15 ) ;
return 0 ;
}
static int F_248 ( struct V_21 * V_15 )
{
struct V_4 * V_5 = F_238 ( V_15 ) ;
struct V_2 * V_3 ;
struct V_14 * V_245 ;
F_198 (link, ap, HOST_FIRST) {
F_140 (adev, link, ENABLED)
if ( V_245 -> V_182 == V_139 &&
! F_249 ( V_245 ) )
return - V_473 ;
}
return 0 ;
}
static int F_250 ( struct V_21 * V_15 )
{
F_235 ( F_238 ( V_15 ) , V_575 ) ;
return 0 ;
}
static int F_251 ( struct V_21 * V_15 )
{
F_242 ( F_238 ( V_15 ) , V_576 ) ;
return 0 ;
}
void F_252 ( struct V_4 * V_5 )
{
F_236 ( V_5 , V_570 ) ;
}
void F_253 ( struct V_4 * V_5 )
{
F_243 ( V_5 , V_574 ) ;
}
int F_254 ( struct V_519 * V_273 , T_6 V_564 )
{
V_273 -> V_15 -> V_577 . V_578 = V_564 ;
return 0 ;
}
void F_255 ( struct V_519 * V_273 )
{
V_273 -> V_15 -> V_577 . V_578 = V_579 ;
}
void F_256 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = F_9 ( V_15 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_42 ;
V_3 -> V_281 = V_3 -> V_40 ;
V_3 -> V_282 = 0 ;
F_67 ( V_5 -> V_210 , V_42 ) ;
V_15 -> V_42 &= ~ V_580 ;
V_15 -> V_48 = 0 ;
F_68 ( V_5 -> V_210 , V_42 ) ;
memset ( ( void * ) V_15 + V_581 , 0 ,
V_582 - V_581 ) ;
V_15 -> V_44 = V_395 ;
V_15 -> V_45 = V_395 ;
V_15 -> V_46 = V_395 ;
}
void F_257 ( struct V_4 * V_5 , struct V_2 * V_3 , int V_38 )
{
int V_25 ;
memset ( ( void * ) V_3 + V_583 , 0 ,
V_584 - V_583 ) ;
V_3 -> V_5 = V_5 ;
V_3 -> V_38 = V_38 ;
V_3 -> V_218 = V_222 ;
V_3 -> V_40 = V_395 ;
for ( V_25 = 0 ; V_25 < V_374 ; V_25 ++ ) {
struct V_14 * V_15 = & V_3 -> V_21 [ V_25 ] ;
V_15 -> V_3 = V_3 ;
V_15 -> V_24 = V_15 - V_3 -> V_21 ;
#ifdef F_258
V_15 -> V_585 = V_586 ;
#endif
F_256 ( V_15 ) ;
}
}
int F_259 ( struct V_2 * V_3 )
{
T_2 V_136 ;
int V_181 ;
V_181 = F_127 ( V_3 , V_388 , & V_3 -> V_587 ) ;
if ( V_181 )
return V_181 ;
V_136 = ( V_3 -> V_587 >> 4 ) & 0xf ;
if ( V_136 )
V_3 -> V_40 &= ( 1 << V_136 ) - 1 ;
F_12 ( V_3 ) ;
V_3 -> V_281 = V_3 -> V_40 ;
return 0 ;
}
struct V_4 * F_260 ( struct V_519 * V_273 )
{
struct V_4 * V_5 ;
F_30 ( L_130 ) ;
V_5 = F_261 ( sizeof( * V_5 ) , V_588 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_211 |= V_589 | V_212 ;
V_5 -> V_210 = & V_273 -> V_210 ;
V_5 -> V_31 = - 1 ;
V_5 -> V_590 = - 1 ;
V_5 -> V_273 = V_273 ;
V_5 -> V_15 = V_273 -> V_15 ;
#if F_262 ( V_591 )
V_5 -> V_592 = 0x00FF ;
#elif F_262 ( V_593 )
V_5 -> V_592 = V_594 | V_595 | V_596 | V_597 | V_598 ;
#else
V_5 -> V_592 = V_594 | V_598 | V_597 ;
#endif
F_263 ( & V_5 -> V_599 ) ;
F_264 ( & V_5 -> V_600 , V_601 ) ;
F_265 ( & V_5 -> V_602 , V_603 ) ;
F_266 ( & V_5 -> V_604 ) ;
F_267 ( & V_5 -> V_605 ) ;
F_268 ( & V_5 -> V_606 ) ;
F_269 ( & V_5 -> V_607 ) ;
V_5 -> V_607 . V_608 = V_609 ;
V_5 -> V_607 . V_610 = ( unsigned long ) V_5 ;
V_5 -> V_33 = V_34 ;
F_257 ( V_5 , & V_5 -> V_3 , 0 ) ;
#ifdef F_270
V_5 -> V_611 . V_612 = 1 ;
V_5 -> V_611 . V_613 = 1 ;
#endif
F_271 ( V_5 ) ;
return V_5 ;
}
static void F_272 ( struct V_21 * V_614 , void * V_615 )
{
struct V_519 * V_273 = F_273 ( V_614 ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_273 -> V_616 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_617 [ V_25 ] ;
if ( ! V_5 )
continue;
if ( V_5 -> V_293 )
F_274 ( V_5 -> V_293 ) ;
F_275 ( V_5 -> V_11 ) ;
F_275 ( V_5 -> V_12 ) ;
F_275 ( V_5 ) ;
V_273 -> V_617 [ V_25 ] = NULL ;
}
F_276 ( V_614 , NULL ) ;
}
struct V_519 * F_277 ( struct V_21 * V_15 , int V_618 )
{
struct V_519 * V_273 ;
T_5 V_619 ;
int V_25 ;
F_30 ( L_130 ) ;
if ( ! F_278 ( V_15 , NULL , V_588 ) )
return NULL ;
V_619 = sizeof( struct V_519 ) + ( V_618 + 1 ) * sizeof( void * ) ;
V_273 = F_279 ( F_272 , V_619 , V_588 ) ;
if ( ! V_273 )
goto V_264;
F_280 ( V_15 , V_273 ) ;
F_276 ( V_15 , V_273 ) ;
F_281 ( & V_273 -> V_210 ) ;
F_263 ( & V_273 -> V_620 ) ;
V_273 -> V_15 = V_15 ;
V_273 -> V_616 = V_618 ;
for ( V_25 = 0 ; V_25 < V_618 ; V_25 ++ ) {
struct V_4 * V_5 ;
V_5 = F_260 ( V_273 ) ;
if ( ! V_5 )
goto V_264;
V_5 -> V_621 = V_25 ;
V_273 -> V_617 [ V_25 ] = V_5 ;
}
F_282 ( V_15 , NULL ) ;
return V_273 ;
V_264:
F_283 ( V_15 , NULL ) ;
return NULL ;
}
struct V_519 * F_284 ( struct V_21 * V_15 ,
const struct V_622 * const * V_623 ,
int V_616 )
{
const struct V_622 * V_624 ;
struct V_519 * V_273 ;
int V_25 , V_337 ;
V_273 = F_277 ( V_15 , V_616 ) ;
if ( ! V_273 )
return NULL ;
for ( V_25 = 0 , V_337 = 0 , V_624 = NULL ; V_25 < V_273 -> V_616 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_617 [ V_25 ] ;
if ( V_623 [ V_337 ] )
V_624 = V_623 [ V_337 ++ ] ;
V_5 -> V_44 = V_624 -> V_44 ;
V_5 -> V_45 = V_624 -> V_45 ;
V_5 -> V_46 = V_624 -> V_46 ;
V_5 -> V_42 |= V_624 -> V_42 ;
V_5 -> V_3 . V_42 |= V_624 -> V_625 ;
V_5 -> V_214 = V_624 -> V_626 ;
if ( ! V_273 -> V_214 && ( V_624 -> V_626 != & V_627 ) )
V_273 -> V_214 = V_624 -> V_626 ;
}
return V_273 ;
}
int F_285 ( struct V_4 * V_5 )
{
struct V_2 * V_3 ;
F_87 ( V_5 -> V_12 ) ;
F_87 ( V_5 -> V_42 & V_628 ) ;
V_3 = F_261 ( sizeof( * V_3 ) , V_588 ) ;
if ( ! V_3 )
return - V_629 ;
F_257 ( V_5 , V_3 , 1 ) ;
V_5 -> V_12 = V_3 ;
return 0 ;
}
static void F_286 ( struct V_21 * V_614 , void * V_615 )
{
struct V_519 * V_273 = F_273 ( V_614 ) ;
int V_25 ;
F_87 ( ! ( V_273 -> V_42 & V_630 ) ) ;
for ( V_25 = 0 ; V_25 < V_273 -> V_616 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_617 [ V_25 ] ;
if ( V_5 -> V_214 -> V_631 )
V_5 -> V_214 -> V_631 ( V_5 ) ;
}
if ( V_273 -> V_214 -> V_632 )
V_273 -> V_214 -> V_632 ( V_273 ) ;
}
static void F_287 ( struct V_633 * V_214 )
{
static F_288 ( V_210 ) ;
const struct V_633 * V_481 ;
void * * V_634 = ( void * * ) V_214 ;
void * * V_635 = ( void * * ) & V_214 -> V_636 ;
void * * V_637 ;
if ( ! V_214 || ! V_214 -> V_636 )
return;
F_289 ( & V_210 ) ;
for ( V_481 = V_214 -> V_636 ; V_481 ; V_481 = V_481 -> V_636 ) {
void * * V_638 = ( void * * ) V_481 ;
for ( V_637 = V_634 ; V_637 < V_635 ; V_637 ++ , V_638 ++ )
if ( ! * V_637 )
* V_637 = * V_638 ;
}
for ( V_637 = V_634 ; V_637 < V_635 ; V_637 ++ )
if ( F_290 ( * V_637 ) )
* V_637 = NULL ;
V_214 -> V_636 = NULL ;
F_291 ( & V_210 ) ;
}
int F_292 ( struct V_519 * V_273 )
{
int V_639 = 0 ;
void * V_640 = NULL ;
int V_25 , V_181 ;
if ( V_273 -> V_42 & V_630 )
return 0 ;
F_287 ( V_273 -> V_214 ) ;
for ( V_25 = 0 ; V_25 < V_273 -> V_616 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_617 [ V_25 ] ;
F_287 ( V_5 -> V_214 ) ;
if ( ! V_273 -> V_214 && ! F_293 ( V_5 ) )
V_273 -> V_214 = V_5 -> V_214 ;
if ( V_5 -> V_214 -> V_631 )
V_639 = 1 ;
}
if ( V_273 -> V_214 -> V_632 )
V_639 = 1 ;
if ( V_639 ) {
V_640 = F_279 ( F_286 , 0 , V_588 ) ;
if ( ! V_640 )
return - V_629 ;
}
for ( V_25 = 0 ; V_25 < V_273 -> V_616 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_617 [ V_25 ] ;
if ( V_5 -> V_214 -> V_641 ) {
V_181 = V_5 -> V_214 -> V_641 ( V_5 ) ;
if ( V_181 ) {
if ( V_181 != - V_263 )
F_294 ( V_273 -> V_15 ,
L_156 ,
V_25 , V_181 ) ;
goto V_264;
}
}
F_295 ( V_5 ) ;
}
if ( V_640 )
F_280 ( V_273 -> V_15 , V_640 ) ;
V_273 -> V_42 |= V_630 ;
return 0 ;
V_264:
while ( -- V_25 >= 0 ) {
struct V_4 * V_5 = V_273 -> V_617 [ V_25 ] ;
if ( V_5 -> V_214 -> V_631 )
V_5 -> V_214 -> V_631 ( V_5 ) ;
}
F_296 ( V_640 ) ;
return V_181 ;
}
void F_297 ( struct V_519 * V_273 , struct V_21 * V_15 ,
struct V_633 * V_214 )
{
F_281 ( & V_273 -> V_210 ) ;
F_263 ( & V_273 -> V_620 ) ;
V_273 -> V_15 = V_15 ;
V_273 -> V_214 = V_214 ;
}
void F_298 ( struct V_4 * V_5 )
{
struct V_539 * V_540 = & V_5 -> V_3 . V_541 ;
unsigned long V_42 ;
F_67 ( V_5 -> V_210 , V_42 ) ;
V_540 -> V_642 |= V_643 ;
V_540 -> V_494 |= V_555 ;
V_540 -> V_42 |= V_644 | V_645 ;
V_5 -> V_211 &= ~ V_589 ;
V_5 -> V_211 |= V_646 ;
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
F_30 ( L_157 , V_5 -> V_31 ) ;
V_181 = F_139 ( V_5 ) ;
F_30 ( L_158 , V_5 -> V_31 ) ;
}
return V_181 ;
}
static void F_300 ( void * V_610 , T_7 V_647 )
{
struct V_4 * V_5 = V_610 ;
if ( ! ( V_5 -> V_273 -> V_42 & V_468 ) && V_5 -> V_621 != 0 )
F_301 ( V_647 ) ;
( void ) F_299 ( V_5 ) ;
F_301 ( V_647 ) ;
F_302 ( V_5 , 1 ) ;
}
int F_303 ( struct V_519 * V_273 , struct V_648 * V_649 )
{
int V_25 , V_181 ;
if ( ! ( V_273 -> V_42 & V_630 ) ) {
F_294 ( V_273 -> V_15 , L_159 ) ;
F_87 ( 1 ) ;
return - V_119 ;
}
for ( V_25 = V_273 -> V_616 ; V_273 -> V_617 [ V_25 ] ; V_25 ++ )
F_275 ( V_273 -> V_617 [ V_25 ] ) ;
for ( V_25 = 0 ; V_25 < V_273 -> V_616 ; V_25 ++ ) {
V_273 -> V_617 [ V_25 ] -> V_31 = F_304 ( & V_650 ) ;
V_273 -> V_617 [ V_25 ] -> V_590 = V_25 + 1 ;
}
for ( V_25 = 0 ; V_25 < V_273 -> V_616 ; V_25 ++ ) {
V_181 = F_305 ( V_273 -> V_15 , V_273 -> V_617 [ V_25 ] ) ;
if ( V_181 ) {
goto V_651;
}
}
V_181 = F_306 ( V_273 , V_649 ) ;
if ( V_181 )
goto V_651;
for ( V_25 = 0 ; V_25 < V_273 -> V_616 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_617 [ V_25 ] ;
unsigned long V_47 ;
if ( V_5 -> V_33 == V_34 && ( V_5 -> V_42 & V_448 ) )
V_5 -> V_33 = V_285 ;
F_259 ( & V_5 -> V_3 ) ;
if ( V_5 -> V_12 )
F_259 ( V_5 -> V_12 ) ;
V_47 = F_31 ( V_5 -> V_44 , V_5 -> V_45 ,
V_5 -> V_46 ) ;
if ( ! F_293 ( V_5 ) ) {
V_622 ( V_5 , L_160 ,
( V_5 -> V_42 & V_448 ) ? 'S' : 'P' ,
F_36 ( V_47 ) ,
V_5 -> V_3 . V_541 . V_286 ) ;
F_307 ( & V_5 -> V_3 . V_541 ) ;
} else
V_622 ( V_5 , L_161 ) ;
}
for ( V_25 = 0 ; V_25 < V_273 -> V_616 ; V_25 ++ ) {
struct V_4 * V_5 = V_273 -> V_617 [ V_25 ] ;
F_308 ( F_300 , V_5 ) ;
}
return 0 ;
V_651:
while ( -- V_25 >= 0 ) {
F_309 ( V_273 -> V_617 [ V_25 ] ) ;
}
return V_181 ;
}
int F_310 ( struct V_519 * V_273 , int V_652 ,
T_8 V_653 , unsigned long V_654 ,
struct V_648 * V_649 )
{
int V_25 , V_181 ;
V_181 = F_292 ( V_273 ) ;
if ( V_181 )
return V_181 ;
if ( ! V_652 ) {
F_87 ( V_653 ) ;
return F_303 ( V_273 , V_649 ) ;
}
V_181 = F_311 ( V_273 -> V_15 , V_652 , V_653 , V_654 ,
F_312 ( V_273 -> V_15 ) , V_273 ) ;
if ( V_181 )
return V_181 ;
for ( V_25 = 0 ; V_25 < V_273 -> V_616 ; V_25 ++ )
F_313 ( V_273 -> V_617 [ V_25 ] , L_162 , V_652 ) ;
V_181 = F_303 ( V_273 , V_649 ) ;
if ( V_181 )
F_314 ( V_273 -> V_15 , V_652 , V_273 ) ;
return V_181 ;
}
static void F_315 ( struct V_4 * V_5 )
{
unsigned long V_42 ;
struct V_2 * V_3 ;
struct V_14 * V_15 ;
if ( ! V_5 -> V_214 -> V_215 )
goto V_655;
F_67 ( V_5 -> V_210 , V_42 ) ;
V_5 -> V_211 |= V_656 ;
F_221 ( V_5 ) ;
F_68 ( V_5 -> V_210 , V_42 ) ;
F_234 ( V_5 ) ;
F_87 ( ! ( V_5 -> V_211 & V_657 ) ) ;
F_316 ( & V_5 -> V_600 ) ;
V_655:
F_198 (link, ap, HOST_FIRST) {
F_140 (dev, link, ALL) {
if ( F_249 ( V_15 ) )
F_317 ( V_15 ) ;
}
}
if ( V_5 -> V_11 ) {
int V_25 ;
for ( V_25 = 0 ; V_25 < V_658 ; V_25 ++ )
F_318 ( & V_5 -> V_11 [ V_25 ] ) ;
}
F_319 ( V_5 -> V_293 ) ;
F_309 ( V_5 ) ;
}
void F_320 ( struct V_519 * V_273 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_273 -> V_616 ; V_25 ++ )
F_315 ( V_273 -> V_617 [ V_25 ] ) ;
F_321 ( V_273 ) ;
}
void F_322 ( struct V_659 * V_660 )
{
struct V_519 * V_273 = F_323 ( V_660 ) ;
F_320 ( V_273 ) ;
}
int F_324 ( struct V_659 * V_660 , const struct V_661 * V_132 )
{
unsigned long V_386 = 0 ;
switch ( V_132 -> V_662 ) {
case 1 : {
T_2 V_663 = 0 ;
F_325 ( V_660 , V_132 -> V_560 , & V_663 ) ;
V_386 = V_663 ;
break;
}
case 2 : {
T_4 V_664 = 0 ;
F_326 ( V_660 , V_132 -> V_560 , & V_664 ) ;
V_386 = V_664 ;
break;
}
case 4 : {
T_1 V_665 = 0 ;
F_327 ( V_660 , V_132 -> V_560 , & V_665 ) ;
V_386 = V_665 ;
break;
}
default:
return - V_119 ;
}
V_386 &= V_132 -> V_390 ;
return ( V_386 == V_132 -> V_561 ) ? 1 : 0 ;
}
void F_328 ( struct V_659 * V_660 , T_6 V_564 )
{
F_329 ( V_660 ) ;
F_330 ( V_660 ) ;
if ( V_564 . V_666 & V_667 )
F_331 ( V_660 , V_668 ) ;
}
int F_332 ( struct V_659 * V_660 )
{
int V_181 ;
F_331 ( V_660 , V_669 ) ;
F_333 ( V_660 ) ;
V_181 = F_334 ( V_660 ) ;
if ( V_181 ) {
F_294 ( & V_660 -> V_15 ,
L_163 , V_181 ) ;
return V_181 ;
}
F_335 ( V_660 ) ;
return 0 ;
}
int F_336 ( struct V_659 * V_660 , T_6 V_564 )
{
struct V_519 * V_273 = F_323 ( V_660 ) ;
int V_181 = 0 ;
V_181 = F_254 ( V_273 , V_564 ) ;
if ( V_181 )
return V_181 ;
F_328 ( V_660 , V_564 ) ;
return 0 ;
}
int F_337 ( struct V_659 * V_660 )
{
struct V_519 * V_273 = F_323 ( V_660 ) ;
int V_181 ;
V_181 = F_332 ( V_660 ) ;
if ( V_181 == 0 )
F_255 ( V_273 ) ;
return V_181 ;
}
int F_338 ( struct V_670 * V_660 )
{
struct V_519 * V_273 = F_339 ( V_660 ) ;
F_320 ( V_273 ) ;
return 0 ;
}
static int T_9 F_340 ( char * * V_481 ,
struct V_27 * V_671 ,
const char * * V_255 )
{
static struct V_672 V_673 [] V_674 = {
{ L_164 , . V_33 = V_369 } ,
{ L_165 , . V_33 = V_370 } ,
{ L_166 , . V_33 = V_518 } ,
{ L_167 , . V_33 = V_371 } ,
{ L_168 , . V_33 = V_372 } ,
{ L_169 , . V_33 = V_285 } ,
{ L_170 , . V_39 = 1 } ,
{ L_171 , . V_39 = 2 } ,
{ L_172 , . V_49 = V_291 } ,
{ L_173 , . V_50 = V_291 } ,
{ L_174 , . V_49 = V_270 } ,
{ L_175 , . V_47 = 1 << ( V_121 + 0 ) } ,
{ L_176 , . V_47 = 1 << ( V_121 + 1 ) } ,
{ L_177 , . V_47 = 1 << ( V_121 + 2 ) } ,
{ L_178 , . V_47 = 1 << ( V_121 + 3 ) } ,
{ L_179 , . V_47 = 1 << ( V_121 + 4 ) } ,
{ L_180 , . V_47 = 1 << ( V_121 + 5 ) } ,
{ L_181 , . V_47 = 1 << ( V_121 + 6 ) } ,
{ L_182 , . V_47 = 1 << ( V_123 + 0 ) } ,
{ L_183 , . V_47 = 1 << ( V_123 + 1 ) } ,
{ L_184 , . V_47 = 1 << ( V_123 + 2 ) } ,
{ L_185 , . V_47 = 1 << ( V_123 + 3 ) } ,
{ L_186 , . V_47 = 1 << ( V_123 + 4 ) } ,
{ L_187 , . V_47 = 1 << ( V_125 + 0 ) } ,
{ L_188 , . V_47 = 1 << ( V_125 + 0 ) } ,
{ L_189 , . V_47 = 1 << ( V_125 + 0 ) } ,
{ L_190 , . V_47 = 1 << ( V_125 + 1 ) } ,
{ L_191 , . V_47 = 1 << ( V_125 + 1 ) } ,
{ L_192 , . V_47 = 1 << ( V_125 + 1 ) } ,
{ L_193 , . V_47 = 1 << ( V_125 + 2 ) } ,
{ L_194 , . V_47 = 1 << ( V_125 + 2 ) } ,
{ L_195 , . V_47 = 1 << ( V_125 + 2 ) } ,
{ L_196 , . V_47 = 1 << ( V_125 + 3 ) } ,
{ L_197 , . V_47 = 1 << ( V_125 + 3 ) } ,
{ L_198 , . V_47 = 1 << ( V_125 + 3 ) } ,
{ L_199 , . V_47 = 1 << ( V_125 + 4 ) } ,
{ L_200 , . V_47 = 1 << ( V_125 + 4 ) } ,
{ L_201 , . V_47 = 1 << ( V_125 + 4 ) } ,
{ L_202 , . V_47 = 1 << ( V_125 + 5 ) } ,
{ L_203 , . V_47 = 1 << ( V_125 + 5 ) } ,
{ L_204 , . V_47 = 1 << ( V_125 + 5 ) } ,
{ L_205 , . V_47 = 1 << ( V_125 + 6 ) } ,
{ L_206 , . V_47 = 1 << ( V_125 + 6 ) } ,
{ L_207 , . V_47 = 1 << ( V_125 + 6 ) } ,
{ L_208 , . V_47 = 1 << ( V_125 + 7 ) } ,
{ L_209 , . V_41 = V_675 } ,
{ L_210 , . V_41 = V_676 } ,
{ L_211 , . V_41 = V_675 | V_676 } ,
{ L_212 , . V_41 = V_677 } ,
{ L_213 , . V_49 = V_356 } ,
{ L_214 , . V_49 = V_316 } ,
} ;
char * V_464 = * V_481 , * V_148 = * V_481 ;
char * V_143 , * V_561 , * V_678 ;
const struct V_672 * V_679 = NULL ;
int V_680 = 0 , V_25 ;
while ( * V_148 != '\0' && * V_148 != ',' )
V_148 ++ ;
if ( * V_148 == '\0' )
* V_481 = V_148 ;
else
* V_481 = V_148 + 1 ;
* V_148 = '\0' ;
V_148 = strchr ( V_464 , ':' ) ;
if ( ! V_148 ) {
V_561 = F_341 ( V_464 ) ;
goto V_681;
}
* V_148 = '\0' ;
V_143 = F_341 ( V_464 ) ;
V_561 = F_341 ( V_148 + 1 ) ;
V_148 = strchr ( V_143 , '.' ) ;
if ( V_148 ) {
* V_148 ++ = '\0' ;
V_671 -> V_21 = F_342 ( V_148 , & V_678 , 10 ) ;
if ( V_148 == V_678 || * V_678 != '\0' ) {
* V_255 = L_215 ;
return - V_119 ;
}
}
V_671 -> V_30 = F_342 ( V_143 , & V_678 , 10 ) ;
if ( V_148 == V_678 || * V_678 != '\0' ) {
* V_255 = L_216 ;
return - V_119 ;
}
V_681:
for ( V_25 = 0 ; V_25 < F_37 ( V_673 ) ; V_25 ++ ) {
const struct V_672 * V_682 = & V_673 [ V_25 ] ;
if ( strncasecmp ( V_561 , V_682 -> V_35 , strlen ( V_561 ) ) )
continue;
V_680 ++ ;
V_679 = V_682 ;
if ( strcasecmp ( V_561 , V_682 -> V_35 ) == 0 ) {
V_680 = 1 ;
break;
}
}
if ( ! V_680 ) {
* V_255 = L_217 ;
return - V_119 ;
}
if ( V_680 > 1 ) {
* V_255 = L_218 ;
return - V_119 ;
}
V_671 -> V_32 = * V_679 ;
return 0 ;
}
static void T_9 F_343 ( void )
{
int V_683 = 0 , V_684 = 1 ;
int V_685 = - 1 , V_686 = - 1 ;
char * V_148 , * V_481 , * V_23 ;
for ( V_148 = V_687 ; * V_148 ; V_148 ++ )
if ( * V_148 == ',' )
V_684 ++ ;
V_29 = F_261 ( sizeof( V_29 [ 0 ] ) * V_684 , V_588 ) ;
if ( ! V_29 ) {
F_344 ( V_688 L_219
L_220 ) ;
return;
}
for ( V_481 = V_687 ; * V_481 != '\0' ; V_481 = V_23 ) {
const char * V_255 = L_67 ;
struct V_27 V_689 = { . V_30 = - 1 , . V_21 = - 1 } ;
V_23 = V_481 ;
if ( F_340 ( & V_23 , & V_689 , & V_255 ) ) {
F_344 ( V_688 L_221
L_222 ,
V_481 , V_255 ) ;
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
static int T_9 F_345 ( void )
{
int V_181 ;
F_343 () ;
V_181 = F_346 () ;
if ( V_181 ) {
F_275 ( V_29 ) ;
return V_181 ;
}
F_347 () ;
V_690 = F_348 () ;
if ( ! V_690 ) {
F_349 () ;
V_181 = - V_629 ;
goto V_264;
}
F_344 ( V_271 L_223 V_691 L_224 ) ;
return 0 ;
V_264:
return V_181 ;
}
static void T_10 F_350 ( void )
{
F_351 ( V_690 ) ;
F_352 () ;
F_349 () ;
F_275 ( V_29 ) ;
}
int F_353 ( void )
{
return F_354 ( & V_692 ) ;
}
void F_174 ( struct V_4 * V_5 , unsigned int V_693 )
{
bool V_694 = V_5 && V_5 -> V_273 -> V_695 == V_696 ;
if ( V_694 )
F_77 ( V_5 ) ;
F_180 ( V_693 ) ;
if ( V_694 )
F_80 ( V_5 ) ;
}
T_1 F_355 ( struct V_4 * V_5 , void T_11 * V_560 , T_1 V_390 , T_1 V_561 ,
unsigned long V_477 , unsigned long V_203 )
{
unsigned long V_463 ;
T_1 V_386 ;
V_386 = F_356 ( V_560 ) ;
V_463 = F_169 ( V_465 , V_203 ) ;
while ( ( V_386 & V_390 ) == V_561 && F_173 ( V_465 , V_463 ) ) {
F_174 ( V_5 , V_477 ) ;
V_386 = F_356 ( V_560 ) ;
}
return V_386 ;
}
static unsigned int F_357 ( struct V_193 * V_194 )
{
return V_213 ;
}
static void F_358 ( struct V_4 * V_5 )
{
}
int F_359 ( const struct V_4 * V_5 , const char * V_697 ,
const char * V_698 , ... )
{
struct V_699 V_700 ;
T_12 args ;
int V_701 ;
va_start ( args , V_698 ) ;
V_700 . V_698 = V_698 ;
V_700 . V_702 = & args ;
V_701 = F_344 ( L_225 , V_697 , V_5 -> V_31 , & V_700 ) ;
va_end ( args ) ;
return V_701 ;
}
int F_360 ( const struct V_2 * V_3 , const char * V_697 ,
const char * V_698 , ... )
{
struct V_699 V_700 ;
T_12 args ;
int V_701 ;
va_start ( args , V_698 ) ;
V_700 . V_698 = V_698 ;
V_700 . V_702 = & args ;
if ( F_4 ( V_3 -> V_5 ) || V_3 -> V_5 -> V_12 )
V_701 = F_344 ( L_226 ,
V_697 , V_3 -> V_5 -> V_31 , V_3 -> V_38 , & V_700 ) ;
else
V_701 = F_344 ( L_225 ,
V_697 , V_3 -> V_5 -> V_31 , & V_700 ) ;
va_end ( args ) ;
return V_701 ;
}
int F_361 ( const struct V_14 * V_15 , const char * V_697 ,
const char * V_698 , ... )
{
struct V_699 V_700 ;
T_12 args ;
int V_701 ;
va_start ( args , V_698 ) ;
V_700 . V_698 = V_698 ;
V_700 . V_702 = & args ;
V_701 = F_344 ( L_226 ,
V_697 , V_15 -> V_3 -> V_5 -> V_31 , V_15 -> V_3 -> V_38 + V_15 -> V_24 ,
& V_700 ) ;
va_end ( args ) ;
return V_701 ;
}
void F_362 ( const struct V_21 * V_15 , const char * V_703 )
{
F_363 ( V_271 , V_15 , L_227 , V_703 ) ;
}
