static T_1 F_1 ( T_1 V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_1 != 1 ; V_2 ++ )
V_1 >>= 1 ;
return V_1 << V_2 ;
}
static void F_2 ( struct V_3 * V_4 )
{
if ( V_4 -> V_5 == V_6 ) {
T_1 V_7 ;
V_7 = F_1 ( V_4 -> V_7 ) ;
V_4 -> V_8 = ~ ( V_7 - 1 ) ;
V_4 -> V_9 = V_7 ;
}
}
static T_1 F_3 ( T_1 V_10 , T_2 V_11 , T_2 V_12 )
{
if ( ! V_12 )
return 0 ;
return ( V_10 / V_12 ) * V_11 + ( ( V_10 % V_12 ) * V_11 ) / V_12 ;
}
struct V_3 * F_4 ( struct V_13 * V_14 )
{
struct V_3 * V_4 ;
if ( ! V_14 -> V_15 || ! V_14 -> V_16 )
return NULL ;
V_4 = F_5 ( sizeof( struct V_3 ) ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_15 = V_14 -> V_15 ;
V_4 -> V_16 = V_14 -> V_16 ;
V_4 -> V_17 = V_14 -> V_17 ;
V_4 -> V_18 = V_14 -> V_18 ;
V_4 -> V_19 = V_14 -> V_19 ;
V_4 -> V_7 = V_14 -> V_7 ;
V_4 -> V_5 = V_14 -> V_5 ;
V_4 -> V_20 = V_14 -> V_20 ;
V_4 -> V_21 = V_14 -> V_20 ;
F_2 ( V_4 ) ;
V_4 -> V_22 = V_14 -> V_23 ;
V_4 -> V_24 = ( 1 << V_4 -> V_22 ) - 1 ;
V_4 -> V_25 = V_14 -> V_25 ;
V_4 -> V_26 = V_14 -> V_26 ;
if ( ! V_4 -> V_25 )
V_4 -> V_26 = 0 ;
if ( V_4 -> V_26 ) {
if ( ! ( V_4 -> V_25 % V_4 -> V_26 ) )
V_4 -> V_27 = V_4 -> V_25 /
V_4 -> V_26 ;
V_4 -> V_28 = F_3 ( 2 << V_4 -> V_22 ,
V_4 -> V_25 ,
V_4 -> V_26 ) ;
}
if ( V_4 -> V_28 < 0x100 )
V_4 -> V_28 = 0x100 ;
F_6 ( L_1 , V_4 -> V_22 ) ;
F_6 ( L_2 , V_4 -> V_25 ) ;
F_6 ( L_3 , V_4 -> V_26 ) ;
F_6 ( L_4 , V_4 -> V_27 ) ;
F_6 ( L_5 , V_4 -> V_28 ) ;
return V_4 ;
}
static void F_7 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_32 ;
V_30 -> V_32 = V_32 -> V_33 ;
if ( ! V_30 -> V_34 )
V_30 -> V_34 = V_32 ;
else
free ( V_32 ) ;
}
static T_1 F_8 ( struct V_29 * V_30 )
{
if ( ! V_30 -> V_35 ) {
if ( ! V_30 -> V_32 )
return 0 ;
F_7 ( V_30 ) ;
if ( ! V_30 -> V_32 )
return 0 ;
V_30 -> V_35 = V_36 ;
}
return V_30 -> V_32 -> V_37 [ -- V_30 -> V_35 ] ;
}
static int F_9 ( struct V_29 * V_30 )
{
struct V_31 * V_32 ;
if ( V_30 -> V_34 ) {
V_32 = V_30 -> V_34 ;
V_30 -> V_34 = NULL ;
} else {
V_32 = malloc ( sizeof( struct V_31 ) ) ;
if ( ! V_32 )
return - V_38 ;
}
V_32 -> V_33 = V_30 -> V_32 ;
V_30 -> V_32 = V_32 ;
V_30 -> V_35 = 0 ;
return 0 ;
}
static int F_10 ( struct V_29 * V_30 , T_1 V_37 )
{
int V_39 ;
if ( ! V_30 -> V_32 || V_30 -> V_35 == V_36 ) {
V_39 = F_9 ( V_30 ) ;
if ( V_39 )
return V_39 ;
}
V_30 -> V_32 -> V_37 [ V_30 -> V_35 ++ ] = V_37 ;
return 0 ;
}
static void F_11 ( struct V_29 * V_30 )
{
while ( V_30 -> V_32 )
F_7 ( V_30 ) ;
V_30 -> V_35 = 0 ;
}
static void F_12 ( struct V_29 * V_30 )
{
F_11 ( V_30 ) ;
F_13 ( & V_30 -> V_32 ) ;
F_13 ( & V_30 -> V_34 ) ;
}
void F_14 ( struct V_3 * V_4 )
{
F_12 ( & V_4 -> V_30 ) ;
free ( V_4 ) ;
}
static int F_15 ( int V_40 )
{
switch ( V_40 ) {
case - V_38 :
return V_41 ;
case - V_42 :
return V_43 ;
case - V_44 :
return V_45 ;
case - V_46 :
return V_47 ;
case - V_48 :
return V_49 ;
case - V_50 :
return V_51 ;
case - V_52 :
return V_53 ;
case - V_54 :
return V_55 ;
case - V_56 :
return V_57 ;
default:
return V_58 ;
}
}
int F_16 ( int V_40 , char * V_59 , T_3 V_60 )
{
if ( V_40 < 1 || V_40 >= V_61 )
V_40 = V_58 ;
F_17 ( V_59 , V_62 [ V_40 ] , V_60 ) ;
return 0 ;
}
static T_1 F_18 ( const struct V_63 * V_64 ,
T_1 V_65 )
{
T_1 V_37 ;
switch ( V_64 -> V_66 ) {
case 1 :
V_37 = ( V_65 & ( T_1 ) 0xffffffffffff0000ULL ) |
V_64 -> V_67 ;
break;
case 2 :
V_37 = ( V_65 & ( T_1 ) 0xffffffff00000000ULL ) |
V_64 -> V_67 ;
break;
case 3 :
V_37 = V_64 -> V_67 ;
if ( V_37 & ( T_1 ) 0x800000000000ULL )
V_37 |= ( T_1 ) 0xffff000000000000ULL ;
break;
case 4 :
V_37 = ( V_65 & ( T_1 ) 0xffff000000000000ULL ) |
V_64 -> V_67 ;
break;
case 6 :
V_37 = V_64 -> V_67 ;
break;
default:
return 0 ;
}
return V_37 ;
}
static inline void F_19 ( struct V_3 * V_4 )
{
V_4 -> V_65 = F_18 ( & V_4 -> V_64 , V_4 -> V_65 ) ;
}
static inline void F_20 ( struct V_3 * V_4 )
{
F_19 ( V_4 ) ;
V_4 -> V_37 = V_4 -> V_65 ;
}
static void F_21 ( struct V_3 * V_4 )
{
F_22 ( & V_4 -> V_64 , V_4 -> V_68 , V_4 -> V_35 ,
V_4 -> V_59 ) ;
}
static int F_23 ( struct V_3 * V_4 )
{
F_6 ( L_6 ) ;
V_4 -> V_69 = V_70 ;
return - V_42 ;
}
static inline void F_24 ( struct V_3 * V_4 )
{
V_4 -> V_71 = 0 ;
}
static inline void F_25 ( struct V_3 * V_4 )
{
V_4 -> V_71 = V_4 -> V_64 . V_67 & V_72 ;
}
static int F_26 ( struct V_3 * V_4 )
{
F_24 ( V_4 ) ;
V_4 -> V_73 = false ;
V_4 -> V_68 = 1 ;
V_4 -> V_74 = 1 ;
F_21 ( V_4 ) ;
if ( V_4 -> V_69 != V_70 ) {
F_6 ( L_7 ) ;
V_4 -> V_69 = V_75 ;
}
return - V_44 ;
}
static int F_27 ( struct V_3 * V_4 )
{
struct V_76 V_77 = { . V_59 = 0 , } ;
int V_78 ;
V_4 -> V_74 = 0 ;
F_6 ( L_8 ) ;
V_78 = V_4 -> V_15 ( & V_77 , V_4 -> V_18 ) ;
if ( V_78 )
return V_78 ;
V_4 -> V_59 = V_77 . V_59 ;
V_4 -> V_79 = V_77 . V_79 ;
if ( ! V_4 -> V_79 ) {
F_6 ( L_9 ) ;
return - V_46 ;
}
if ( ! V_77 . V_80 ) {
V_4 -> V_37 = 0 ;
V_4 -> V_69 = V_70 ;
V_4 -> V_81 = V_77 . V_81 ;
V_4 -> V_82 = 0 ;
V_4 -> V_73 = false ;
V_4 -> V_83 . V_84 = V_77 . V_84 ;
F_6 ( L_10 V_85 L_11 ,
V_4 -> V_81 ) ;
return - V_86 ;
}
return 0 ;
}
static int F_28 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_87 )
return F_27 ( V_4 ) ;
V_4 -> V_59 = V_4 -> V_87 ;
V_4 -> V_79 = V_4 -> V_88 ;
V_4 -> V_87 = 0 ;
V_4 -> V_88 = 0 ;
return 0 ;
}
static int F_29 ( struct V_3 * V_4 )
{
unsigned char * V_59 = V_4 -> V_89 ;
T_3 V_90 , V_79 , V_11 ;
int V_78 ;
V_90 = V_4 -> V_79 ;
V_79 = V_4 -> V_79 ;
memcpy ( V_59 , V_4 -> V_59 , V_79 ) ;
V_78 = F_27 ( V_4 ) ;
if ( V_78 ) {
V_4 -> V_35 += V_90 ;
return V_78 < 0 ? V_78 : - V_91 ;
}
V_11 = V_92 - V_79 ;
if ( V_11 > V_4 -> V_79 )
V_11 = V_4 -> V_79 ;
memcpy ( V_59 + V_79 , V_4 -> V_59 , V_11 ) ;
V_79 += V_11 ;
V_78 = F_30 ( V_59 , V_79 , & V_4 -> V_64 ) ;
if ( V_78 < ( int ) V_90 ) {
V_4 -> V_87 = V_4 -> V_59 ;
V_4 -> V_88 = V_4 -> V_79 ;
V_4 -> V_59 = V_59 ;
V_4 -> V_79 = V_90 ;
return F_26 ( V_4 ) ;
}
V_4 -> V_87 = V_4 -> V_59 + ( V_78 - V_90 ) ;
V_4 -> V_88 = V_4 -> V_79 - ( V_78 - V_90 ) ;
V_4 -> V_59 = V_59 ;
V_4 -> V_79 = V_78 ;
return V_78 ;
}
static int F_31 ( struct V_3 * V_4 ,
T_4 V_93 , void * V_18 )
{
struct V_94 V_95 ;
const unsigned char * V_59 = V_4 -> V_59 ;
T_3 V_79 = V_4 -> V_79 ;
int V_78 ;
V_95 . V_4 = V_4 ;
V_95 . V_35 = V_4 -> V_35 ;
V_95 . V_68 = V_4 -> V_74 ;
V_95 . V_96 = V_4 -> V_96 ;
V_95 . V_18 = V_18 ;
while ( 1 ) {
do {
V_95 . V_35 += V_95 . V_68 ;
V_59 += V_95 . V_68 ;
V_79 -= V_95 . V_68 ;
if ( ! V_79 )
return V_97 ;
V_78 = F_30 ( V_59 , V_79 , & V_95 . V_64 ) ;
if ( ! V_78 )
return V_97 ;
if ( V_78 < 0 )
return V_78 ;
V_95 . V_68 = V_78 ;
} while ( V_95 . V_64 . type == V_98 );
V_78 = V_93 ( & V_95 ) ;
if ( V_78 )
return 0 ;
V_95 . V_96 = V_95 . V_64 . type ;
}
}
static void F_32 ( T_2 V_99 , int V_22 ,
T_2 * V_100 )
{
T_2 V_101 = 1U << ( 16 - V_22 ) ;
T_2 V_102 = ~ ( V_101 - 1 ) ;
* V_100 |= V_99 & V_102 ;
if ( * V_100 >= V_99 ) {
* V_100 -= V_101 ;
* V_100 &= 0xff ;
}
}
static int F_33 ( struct V_94 * V_95 )
{
struct V_3 * V_4 = V_95 -> V_4 ;
struct V_103 * V_18 = V_95 -> V_18 ;
T_1 V_82 ;
double V_104 ;
unsigned int V_105 ;
T_2 V_99 , V_106 , V_107 , V_108 , V_109 ;
switch ( V_95 -> V_64 . type ) {
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_98 :
case V_119 :
case V_120 :
return 0 ;
case V_121 :
if ( ! V_18 -> V_73 )
return 0 ;
V_99 = V_95 -> V_64 . V_67 ;
if ( V_4 -> V_22 > 8 && V_18 -> V_122 ) {
V_18 -> V_122 = false ;
F_32 ( V_99 , V_4 -> V_22 ,
& V_18 -> V_100 ) ;
}
if ( V_99 > V_18 -> V_100 )
V_106 = V_99 - V_18 -> V_100 ;
else
V_106 = V_99 + 256 - V_18 -> V_100 ;
V_18 -> V_123 += V_106 << V_4 -> V_22 ;
V_18 -> V_100 = V_99 ;
if ( V_4 -> V_27 ) {
V_82 = V_18 -> V_124 +
V_18 -> V_123 * V_4 -> V_27 ;
} else {
V_82 = V_18 -> V_124 +
F_3 ( V_18 -> V_123 ,
V_4 -> V_25 ,
V_4 -> V_26 ) ;
}
if ( V_82 < V_18 -> V_82 )
return 1 ;
if ( V_95 -> V_96 != V_125 ) {
V_18 -> V_82 = V_82 ;
return 0 ;
}
break;
case V_126 :
V_82 = V_95 -> V_64 . V_67 |
( V_18 -> V_82 & ( 0xffULL << 56 ) ) ;
if ( V_18 -> V_127 && V_82 < V_18 -> V_82 &&
V_18 -> V_82 - V_82 < V_4 -> V_28 )
return 1 ;
if ( V_82 < V_18 -> V_82 )
V_82 += ( 1ULL << 56 ) ;
if ( V_95 -> V_96 != V_125 ) {
if ( V_18 -> V_127 )
return 1 ;
V_18 -> V_128 = V_82 ;
V_18 -> V_82 = V_82 ;
return 0 ;
}
break;
case V_129 :
if ( V_18 -> V_127 )
return 1 ;
if ( ! V_4 -> V_26 )
return 0 ;
V_107 = V_95 -> V_64 . V_67 ;
V_108 = V_95 -> V_64 . V_66 ;
V_109 = V_107 & V_4 -> V_24 ;
V_18 -> V_100 = ( V_107 >> V_4 -> V_22 ) & 0xff ;
V_18 -> V_124 = V_18 -> V_128 - V_108 ;
if ( V_4 -> V_27 ) {
V_18 -> V_124 -= V_109 * V_4 -> V_27 ;
} else {
V_18 -> V_124 -=
F_3 ( V_109 , V_4 -> V_25 ,
V_4 -> V_26 ) ;
}
V_18 -> V_123 = 0 ;
V_18 -> V_73 = true ;
V_18 -> V_122 = true ;
return 0 ;
case V_125 :
V_18 -> V_130 += V_95 -> V_64 . V_67 ;
return 0 ;
case V_131 :
V_105 = V_95 -> V_64 . V_67 ;
if ( V_18 -> V_105 && V_18 -> V_105 != V_105 )
return 1 ;
V_18 -> V_105 = V_105 ;
V_18 -> V_132 = V_4 -> V_21 / V_105 ;
return 0 ;
case V_133 :
case V_134 :
case V_135 :
case V_136 :
default:
return 1 ;
}
if ( ! V_18 -> V_105 && V_4 -> V_105 ) {
V_18 -> V_105 = V_4 -> V_105 ;
V_18 -> V_132 = V_4 -> V_132 ;
}
if ( ! V_18 -> V_130 )
return 1 ;
V_104 = ( double ) ( V_82 - V_4 -> V_82 ) / V_18 -> V_130 ;
if ( V_18 -> V_105 && V_104 > V_18 -> V_132 &&
V_104 / V_18 -> V_132 > 1.25 ) {
F_6 ( L_12 V_137 L_11 ,
V_104 , V_18 -> V_132 , V_95 -> V_35 ) ;
return 1 ;
}
V_4 -> V_138 = V_104 ;
V_4 -> V_139 = true ;
if ( V_18 -> V_105 ) {
F_6 ( L_13 V_137 L_11 ,
V_104 , V_18 -> V_132 , V_95 -> V_35 ) ;
} else {
F_6 ( L_14 V_137 L_11 ,
V_104 , V_95 -> V_35 ) ;
}
return 1 ;
}
static void F_34 ( struct V_3 * V_4 ,
bool V_127 )
{
struct V_103 V_18 = {
. V_130 = 0 ,
. V_105 = 0 ,
. V_100 = V_4 -> V_100 ,
. V_124 = V_4 -> V_124 ,
. V_123 = V_4 -> V_123 ,
. V_128 = V_4 -> V_128 ,
. V_82 = V_4 -> V_82 ,
. V_73 = V_4 -> V_73 ,
. V_122 = V_4 -> V_122 ,
. V_127 = V_127 ,
. V_132 = 0 ,
} ;
F_31 ( V_4 , F_33 , & V_18 ) ;
}
static int F_35 ( struct V_3 * V_4 )
{
int V_78 ;
V_4 -> V_96 = V_4 -> V_64 . type ;
do {
V_4 -> V_35 += V_4 -> V_74 ;
V_4 -> V_59 += V_4 -> V_74 ;
V_4 -> V_79 -= V_4 -> V_74 ;
if ( ! V_4 -> V_79 ) {
V_78 = F_28 ( V_4 ) ;
if ( V_78 )
return V_78 ;
}
V_78 = F_30 ( V_4 -> V_59 , V_4 -> V_79 ,
& V_4 -> V_64 ) ;
if ( V_78 == V_97 &&
V_4 -> V_79 < V_92 && ! V_4 -> V_87 ) {
V_78 = F_29 ( V_4 ) ;
if ( V_78 < 0 )
return V_78 ;
}
if ( V_78 <= 0 )
return F_26 ( V_4 ) ;
V_4 -> V_68 = V_78 ;
V_4 -> V_74 = V_78 ;
F_21 ( V_4 ) ;
} while ( V_4 -> V_64 . type == V_98 );
return 0 ;
}
static T_1 F_36 ( struct V_3 * V_4 )
{
T_1 V_82 , V_140 ;
V_82 = V_4 -> V_82 + V_4 -> V_141 ;
V_140 = V_82 & V_4 -> V_8 ;
if ( V_4 -> V_142 ) {
if ( V_140 != V_4 -> V_143 )
return 1 ;
} else {
V_82 += 1 ;
V_140 = V_82 & V_4 -> V_8 ;
if ( V_140 != V_4 -> V_143 ) {
V_4 -> V_143 = V_140 ;
V_4 -> V_142 = true ;
}
}
return V_4 -> V_9 - ( V_82 - V_140 ) ;
}
static T_1 F_37 ( struct V_3 * V_4 )
{
switch ( V_4 -> V_5 ) {
case V_144 :
return V_4 -> V_7 - V_4 -> V_145 ;
case V_6 :
return F_36 ( V_4 ) ;
case V_146 :
case V_147 :
default:
return 0 ;
}
}
static void F_38 ( struct V_3 * V_4 )
{
T_1 V_82 , V_140 ;
switch ( V_4 -> V_5 ) {
case V_144 :
V_4 -> V_145 = 0 ;
break;
case V_6 :
V_82 = V_4 -> V_82 + V_4 -> V_141 ;
V_140 = V_82 & V_4 -> V_8 ;
V_4 -> V_143 = V_140 ;
break;
case V_146 :
case V_147 :
default:
break;
}
V_4 -> V_83 . type |= V_148 ;
}
static int F_39 ( struct V_3 * V_4 ,
struct V_149 * V_149 , T_1 V_37 )
{
T_1 V_150 , V_151 = 0 ;
int V_39 ;
if ( ! V_4 -> V_152 )
V_4 -> V_152 = true ;
V_150 = F_37 ( V_4 ) ;
V_39 = V_4 -> V_16 ( V_149 , & V_151 , & V_4 -> V_37 , V_37 ,
V_150 , V_4 -> V_18 ) ;
V_4 -> V_153 += V_151 ;
V_4 -> V_141 += V_151 ;
V_4 -> V_145 += V_151 ;
if ( V_39 ) {
V_4 -> V_154 = 0 ;
V_4 -> V_69 = V_155 ;
F_40 ( L_15 ,
V_4 -> V_37 ) ;
if ( V_39 == - V_50 )
return - V_86 ;
return - V_48 ;
}
if ( V_37 && V_4 -> V_37 == V_37 ) {
V_39 = - V_156 ;
goto V_157;
}
if ( V_150 && V_151 >= V_150 )
F_38 ( V_4 ) ;
if ( V_149 -> V_158 == V_159 ) {
V_4 -> V_83 . type = V_148 ;
V_4 -> V_83 . V_160 = V_4 -> V_37 ;
V_4 -> V_83 . V_161 = 0 ;
V_4 -> V_37 += V_149 -> V_162 ;
V_39 = V_163 ;
goto V_157;
}
if ( V_149 -> V_164 == V_165 ) {
if ( V_149 -> V_158 != V_166 ||
V_149 -> V_167 ) {
V_39 = F_10 ( & V_4 -> V_30 , V_4 -> V_37 +
V_149 -> V_162 ) ;
if ( V_39 )
goto V_157;
}
} else if ( V_149 -> V_164 == V_168 ) {
V_4 -> V_169 = F_8 ( & V_4 -> V_30 ) ;
}
if ( V_149 -> V_158 == V_166 ) {
int V_170 = V_4 -> V_154 ++ ;
V_4 -> V_83 . V_160 = V_4 -> V_37 ;
V_4 -> V_37 += V_149 -> V_162 +
V_149 -> V_167 ;
V_4 -> V_83 . V_161 = V_4 -> V_37 ;
V_39 = V_163 ;
if ( V_170 ) {
if ( V_170 == 1 ) {
V_4 -> V_171 = V_4 -> V_83 . V_161 ;
V_4 -> V_172 = 1 ;
V_4 -> V_173 = 1 ;
} else if ( V_170 > V_174 ||
V_4 -> V_83 . V_161 == V_4 -> V_171 ) {
F_40 ( L_16 ,
V_4 -> V_83 . V_161 ) ;
V_4 -> V_69 = V_175 ;
V_39 = - V_56 ;
goto V_157;
} else if ( ! -- V_4 -> V_173 ) {
V_4 -> V_172 += 1 ;
V_4 -> V_173 = V_4 -> V_172 ;
V_4 -> V_171 = V_4 -> V_83 . V_161 ;
}
}
goto V_176;
}
V_157:
V_4 -> V_154 = 0 ;
V_176:
V_4 -> V_83 . V_177 = V_149 -> V_164 ;
V_4 -> V_83 . V_178 = V_149 -> V_162 ;
if ( V_4 -> V_71 & V_72 )
V_4 -> V_83 . V_179 |= V_72 ;
return V_39 ;
}
static int F_41 ( struct V_3 * V_4 )
{
struct V_149 V_149 ;
T_1 V_37 ;
int V_39 ;
V_37 = V_4 -> V_65 ;
while ( 1 ) {
V_39 = F_39 ( V_4 , & V_149 , V_37 ) ;
if ( V_39 == V_163 )
return 0 ;
if ( V_39 == - V_156 ) {
if ( V_4 -> V_180 ) {
V_4 -> V_180 = false ;
V_4 -> V_71 = V_4 -> V_181 ;
V_4 -> V_83 . type = V_182 ;
V_4 -> V_83 . V_160 = V_4 -> V_37 ;
V_4 -> V_83 . V_161 = 0 ;
V_4 -> V_83 . V_179 = V_4 -> V_181 ;
return 0 ;
}
return V_39 ;
}
V_4 -> V_180 = false ;
if ( V_39 )
return V_39 ;
if ( V_149 . V_158 == V_183 ) {
F_40 ( L_17 ,
V_4 -> V_37 ) ;
V_4 -> V_69 = V_175 ;
return - V_50 ;
}
if ( V_149 . V_158 == V_184 ) {
F_40 ( L_18 ,
V_4 -> V_37 ) ;
V_4 -> V_69 = V_175 ;
return - V_50 ;
}
F_23 ( V_4 ) ;
}
}
static int F_42 ( struct V_3 * V_4 )
{
struct V_149 V_149 ;
int V_39 ;
V_39 = F_39 ( V_4 , & V_149 , 0 ) ;
if ( V_39 == V_163 &&
V_4 -> V_17 &&
V_4 -> V_69 == V_185 &&
( V_4 -> V_83 . type & V_186 ) &&
V_4 -> V_17 ( V_4 -> V_83 . V_161 , V_4 -> V_18 ) ) {
V_4 -> V_154 = 0 ;
V_4 -> V_187 = false ;
V_4 -> V_142 = false ;
V_4 -> V_69 = V_188 ;
V_4 -> V_83 . V_161 = 0 ;
return 0 ;
}
if ( V_39 == V_163 )
return 0 ;
if ( V_39 )
return V_39 ;
if ( V_149 . V_158 == V_183 ) {
if ( V_4 -> V_69 == V_185 ) {
V_4 -> V_187 = false ;
V_4 -> V_142 = false ;
V_4 -> V_69 = V_188 ;
V_4 -> V_83 . V_160 = V_4 -> V_37 ;
V_4 -> V_83 . V_161 = 0 ;
if ( V_4 -> V_64 . V_66 != 0 )
V_4 -> V_37 = V_4 -> V_65 ;
} else {
V_4 -> V_69 = V_188 ;
V_4 -> V_83 . V_160 = V_4 -> V_37 ;
if ( V_4 -> V_64 . V_66 == 0 ) {
V_4 -> V_83 . V_161 = 0 ;
} else {
V_4 -> V_83 . V_161 = V_4 -> V_65 ;
V_4 -> V_37 = V_4 -> V_65 ;
}
}
return 0 ;
}
if ( V_149 . V_158 == V_184 ) {
T_1 V_161 = V_4 -> V_37 + V_149 . V_162 +
V_149 . V_167 ;
if ( V_4 -> V_17 &&
V_4 -> V_69 == V_185 &&
V_4 -> V_17 ( V_161 , V_4 -> V_18 ) ) {
V_4 -> V_187 = false ;
V_4 -> V_142 = false ;
V_4 -> V_69 = V_188 ;
V_4 -> V_37 = V_161 ;
V_4 -> V_83 . V_160 = V_4 -> V_37 ;
V_4 -> V_83 . V_161 = 0 ;
return 0 ;
}
F_40 ( L_19 ,
V_4 -> V_37 ) ;
V_4 -> V_69 = V_175 ;
return - V_50 ;
}
return F_23 ( V_4 ) ;
}
static int F_43 ( struct V_3 * V_4 )
{
struct V_149 V_149 ;
int V_39 ;
while ( 1 ) {
V_39 = F_39 ( V_4 , & V_149 , 0 ) ;
if ( V_39 == V_163 )
return 0 ;
if ( V_39 )
return V_39 ;
if ( V_149 . V_164 == V_168 ) {
if ( ! V_4 -> V_19 ) {
F_40 ( L_20 ,
V_4 -> V_37 ) ;
V_4 -> V_69 = V_189 ;
return - V_50 ;
}
if ( ! V_4 -> V_169 ) {
F_40 ( L_21 ,
V_4 -> V_37 ) ;
V_4 -> V_69 = V_189 ;
return - V_50 ;
}
if ( ! ( V_4 -> V_190 . V_67 & V_191 ) ) {
F_40 ( L_22 ,
V_4 -> V_37 ) ;
V_4 -> V_69 = V_189 ;
return - V_50 ;
}
V_4 -> V_190 . V_66 -= 1 ;
if ( ! V_4 -> V_190 . V_66 )
V_4 -> V_69 = V_188 ;
V_4 -> V_190 . V_67 <<= 1 ;
V_4 -> V_83 . V_160 = V_4 -> V_37 ;
V_4 -> V_37 = V_4 -> V_169 ;
V_4 -> V_83 . V_161 = V_4 -> V_37 ;
return 0 ;
}
if ( V_149 . V_158 == V_183 ) {
V_39 = F_35 ( V_4 ) ;
if ( V_39 )
return V_39 ;
if ( V_4 -> V_64 . type != V_112 ||
V_4 -> V_64 . V_66 == 0 ) {
F_40 ( L_23 ,
V_4 -> V_37 ) ;
V_4 -> V_69 = V_189 ;
V_4 -> V_74 = 0 ;
return - V_50 ;
}
F_19 ( V_4 ) ;
V_4 -> V_83 . V_160 = V_4 -> V_37 ;
V_4 -> V_83 . V_161 = V_4 -> V_65 ;
V_4 -> V_37 = V_4 -> V_65 ;
return 0 ;
}
if ( V_149 . V_158 == V_184 ) {
V_4 -> V_190 . V_66 -= 1 ;
if ( ! V_4 -> V_190 . V_66 )
V_4 -> V_69 = V_188 ;
if ( V_4 -> V_190 . V_67 & V_191 ) {
V_4 -> V_190 . V_67 <<= 1 ;
V_4 -> V_83 . V_160 = V_4 -> V_37 ;
V_4 -> V_37 += V_149 . V_162 +
V_149 . V_167 ;
V_4 -> V_83 . V_161 = V_4 -> V_37 ;
return 0 ;
}
if ( V_4 -> V_83 . type & V_148 ) {
V_4 -> V_190 . V_67 <<= 1 ;
V_4 -> V_83 . type = V_148 ;
V_4 -> V_83 . V_160 = V_4 -> V_37 ;
V_4 -> V_83 . V_161 = 0 ;
V_4 -> V_37 += V_149 . V_162 ;
return 0 ;
}
V_4 -> V_37 += V_149 . V_162 ;
if ( ! V_4 -> V_190 . V_66 )
return - V_156 ;
V_4 -> V_190 . V_67 <<= 1 ;
continue;
}
return F_23 ( V_4 ) ;
}
}
static int F_44 ( struct V_3 * V_4 , bool * V_192 )
{
unsigned int V_181 ;
int V_39 ;
V_181 = V_4 -> V_64 . V_67 &
( V_72 | V_193 ) ;
V_39 = F_35 ( V_4 ) ;
if ( V_39 )
return V_39 ;
if ( V_4 -> V_64 . type == V_113 ) {
V_4 -> V_181 = V_181 ;
V_4 -> V_180 = true ;
if ( ! ( V_4 -> V_181 & V_193 ) )
* V_192 = true ;
} else {
F_40 ( L_24 ,
V_4 -> V_35 ) ;
F_25 ( V_4 ) ;
}
return 0 ;
}
static void F_45 ( struct V_3 * V_4 )
{
T_1 V_82 ;
V_4 -> V_73 = false ;
if ( V_4 -> V_81 ) {
V_82 = V_4 -> V_64 . V_67 |
( V_4 -> V_81 & ( 0xffULL << 56 ) ) ;
if ( V_82 < V_4 -> V_81 ) {
if ( V_4 -> V_81 - V_82 > ( 1ULL << 55 ) )
V_82 += ( 1ULL << 56 ) ;
} else {
if ( V_82 - V_4 -> V_81 > ( 1ULL << 55 ) )
V_82 -= ( 1ULL << 56 ) ;
}
V_4 -> V_128 = V_82 ;
V_4 -> V_82 = V_82 ;
V_4 -> V_81 = 0 ;
V_4 -> V_141 = 0 ;
} else if ( V_4 -> V_82 ) {
V_82 = V_4 -> V_64 . V_67 |
( V_4 -> V_82 & ( 0xffULL << 56 ) ) ;
V_4 -> V_128 = V_82 ;
if ( V_82 < V_4 -> V_82 &&
V_4 -> V_82 - V_82 < V_4 -> V_28 ) {
F_46 ( L_25 ,
V_82 ) ;
V_82 = V_4 -> V_82 ;
}
if ( V_82 < V_4 -> V_82 ) {
F_46 ( L_26 , V_82 ) ;
V_82 += ( 1ULL << 56 ) ;
V_4 -> V_128 = V_82 ;
}
V_4 -> V_82 = V_82 ;
V_4 -> V_141 = 0 ;
}
if ( V_4 -> V_96 == V_125 ) {
V_4 -> V_194 = V_4 -> V_82 ;
V_4 -> V_130 = 0 ;
V_4 -> V_139 = false ;
F_34 ( V_4 , false ) ;
}
F_46 ( L_27 , V_4 -> V_82 ) ;
}
static int F_47 ( struct V_3 * V_4 )
{
F_6 ( L_28 ) ;
F_24 ( V_4 ) ;
V_4 -> V_73 = false ;
V_4 -> V_105 = 0 ;
V_4 -> V_69 = V_175 ;
V_4 -> V_195 = true ;
return - V_52 ;
}
static void F_48 ( struct V_3 * V_4 )
{
T_2 V_107 = V_4 -> V_64 . V_67 ;
T_2 V_108 = V_4 -> V_64 . V_66 ;
T_2 V_109 = V_107 & V_4 -> V_24 ;
if ( ! V_4 -> V_26 )
return;
V_4 -> V_100 = ( V_107 >> V_4 -> V_22 ) & 0xff ;
V_4 -> V_124 = V_4 -> V_128 - V_108 ;
if ( V_4 -> V_27 ) {
V_4 -> V_124 -= V_109 * V_4 -> V_27 ;
} else {
V_4 -> V_124 -= F_3 ( V_109 ,
V_4 -> V_25 ,
V_4 -> V_26 ) ;
}
V_4 -> V_123 = 0 ;
V_4 -> V_73 = true ;
V_4 -> V_122 = true ;
F_6 ( L_29 V_137 L_30 ,
V_4 -> V_124 , V_4 -> V_100 , V_109 ) ;
}
static void F_49 ( struct V_3 * V_4 )
{
T_1 V_82 ;
T_2 V_99 , V_106 ;
if ( ! V_4 -> V_73 )
return;
V_99 = V_4 -> V_64 . V_67 ;
if ( V_4 -> V_22 > 8 && V_4 -> V_122 ) {
V_4 -> V_122 = false ;
F_32 ( V_99 , V_4 -> V_22 ,
& V_4 -> V_100 ) ;
}
if ( V_99 > V_4 -> V_100 )
V_106 = V_99 - V_4 -> V_100 ;
else
V_106 = V_99 + 256 - V_4 -> V_100 ;
V_4 -> V_123 += V_106 << V_4 -> V_22 ;
if ( V_4 -> V_27 ) {
V_82 = V_4 -> V_124 +
V_4 -> V_123 * V_4 -> V_27 ;
} else {
V_82 = V_4 -> V_124 +
F_3 ( V_4 -> V_123 ,
V_4 -> V_25 ,
V_4 -> V_26 ) ;
}
if ( V_82 < V_4 -> V_82 )
F_6 ( L_31 V_137 L_32 V_137 L_11 ,
V_82 , V_4 -> V_82 ) ;
else
V_4 -> V_82 = V_82 ;
V_4 -> V_141 = 0 ;
V_4 -> V_100 = V_99 ;
if ( V_4 -> V_96 == V_125 ) {
V_4 -> V_194 = V_4 -> V_82 ;
V_4 -> V_130 = 0 ;
V_4 -> V_139 = false ;
F_34 ( V_4 , true ) ;
}
}
static void F_50 ( struct V_3 * V_4 )
{
unsigned int V_105 = V_4 -> V_64 . V_67 ;
if ( V_4 -> V_105 == V_105 )
return;
V_4 -> V_105 = V_105 ;
V_4 -> V_132 = V_4 -> V_21 / V_105 ;
}
static void F_51 ( struct V_3 * V_4 )
{
T_1 V_82 = V_4 -> V_194 ;
V_4 -> V_196 = true ;
V_4 -> V_130 += V_4 -> V_64 . V_67 ;
if ( ! V_4 -> V_194 )
return;
if ( V_4 -> V_139 )
V_82 += V_4 -> V_130 * V_4 -> V_138 ;
else if ( V_4 -> V_105 )
V_82 += V_4 -> V_130 * V_4 -> V_132 ;
else
return;
if ( V_82 < V_4 -> V_82 )
F_6 ( L_33 V_137 L_32 V_137 L_11 ,
V_82 , V_4 -> V_82 ) ;
else
V_4 -> V_82 = V_82 ;
V_4 -> V_141 = 0 ;
}
static int F_52 ( struct V_3 * V_4 )
{
int V_39 ;
while ( 1 ) {
V_39 = F_35 ( V_4 ) ;
if ( V_39 )
return V_39 ;
switch ( V_4 -> V_64 . type ) {
case V_118 :
return 0 ;
case V_133 :
case V_111 :
case V_112 :
case V_110 :
case V_134 :
case V_136 :
case V_114 :
V_4 -> V_73 = false ;
F_6 ( L_34 ) ;
return - V_156 ;
case V_135 :
return F_47 ( V_4 ) ;
case V_126 :
F_45 ( V_4 ) ;
break;
case V_129 :
F_48 ( V_4 ) ;
break;
case V_131 :
F_50 ( V_4 ) ;
break;
case V_116 :
V_4 -> V_197 = V_4 -> V_64 . V_67 ;
break;
case V_115 :
V_4 -> V_198 = V_4 -> V_64 . V_67 & ( V_191 - 1 ) ;
break;
case V_113 :
V_4 -> V_187 = true ;
F_19 ( V_4 ) ;
break;
case V_117 :
F_25 ( V_4 ) ;
break;
case V_121 :
F_49 ( V_4 ) ;
if ( V_4 -> V_5 == V_147 )
V_4 -> V_83 . type |= V_148 ;
break;
case V_125 :
case V_119 :
case V_120 :
case V_98 :
default:
break;
}
}
}
static int F_53 ( struct V_3 * V_4 )
{
int V_39 ;
if ( V_4 -> V_71 & V_193 ) {
V_4 -> V_71 = 0 ;
V_4 -> V_83 . V_179 &= ~ V_72 ;
V_4 -> V_83 . V_179 |= V_193 ;
} else {
V_4 -> V_83 . V_179 |= V_199 ;
}
while ( 1 ) {
V_39 = F_35 ( V_4 ) ;
if ( V_39 )
return V_39 ;
switch ( V_4 -> V_64 . type ) {
case V_110 :
case V_113 :
case V_134 :
case V_114 :
case V_126 :
case V_129 :
case V_131 :
case V_117 :
case V_136 :
case V_118 :
F_6 ( L_35 ) ;
V_4 -> V_69 = V_189 ;
return - V_50 ;
case V_135 :
return F_47 ( V_4 ) ;
case V_133 :
V_4 -> V_83 . V_160 = V_4 -> V_37 ;
V_4 -> V_83 . V_161 = 0 ;
if ( V_4 -> V_64 . V_66 != 0 ) {
F_20 ( V_4 ) ;
F_6 ( L_36 V_137 L_11 ,
V_4 -> V_37 ) ;
}
V_4 -> V_187 = false ;
V_4 -> V_142 = false ;
return 0 ;
case V_111 :
V_4 -> V_187 = true ;
F_6 ( L_37 V_137 L_11 ,
V_4 -> V_37 ) ;
V_4 -> V_83 . V_160 = 0 ;
if ( V_4 -> V_64 . V_66 == 0 ) {
V_4 -> V_83 . V_161 = 0 ;
} else {
F_20 ( V_4 ) ;
V_4 -> V_83 . V_161 = V_4 -> V_37 ;
}
return 0 ;
case V_112 :
V_4 -> V_83 . V_160 = V_4 -> V_37 ;
if ( V_4 -> V_64 . V_66 == 0 ) {
V_4 -> V_83 . V_161 = 0 ;
} else {
F_20 ( V_4 ) ;
V_4 -> V_83 . V_161 = V_4 -> V_37 ;
}
return 0 ;
case V_115 :
V_4 -> V_198 = V_4 -> V_64 . V_67 & ( V_191 - 1 ) ;
break;
case V_121 :
F_49 ( V_4 ) ;
if ( V_4 -> V_5 == V_147 )
V_4 -> V_83 . type |= V_148 ;
break;
case V_125 :
F_51 ( V_4 ) ;
break;
case V_116 :
V_4 -> V_197 = V_4 -> V_64 . V_67 ;
break;
case V_119 :
case V_120 :
case V_98 :
break;
default:
return F_23 ( V_4 ) ;
}
}
}
static int F_54 ( struct V_3 * V_4 )
{
bool V_192 = false ;
int V_39 ;
while ( 1 ) {
V_39 = F_35 ( V_4 ) ;
if ( V_39 )
return V_39 ;
V_200:
switch ( V_4 -> V_64 . type ) {
case V_110 :
if ( ! V_4 -> V_64 . V_66 )
break;
V_4 -> V_190 = V_4 -> V_64 ;
V_4 -> V_69 = V_201 ;
V_39 = F_43 ( V_4 ) ;
if ( V_39 == - V_156 )
break;
return V_39 ;
case V_133 :
if ( V_4 -> V_64 . V_66 != 0 )
F_19 ( V_4 ) ;
V_4 -> V_69 = V_185 ;
return F_42 ( V_4 ) ;
case V_111 : {
V_4 -> V_187 = true ;
if ( V_4 -> V_64 . V_66 == 0 ) {
F_40 ( L_38 ,
V_4 -> V_35 ) ;
break;
}
F_20 ( V_4 ) ;
V_4 -> V_83 . V_160 = 0 ;
V_4 -> V_83 . V_161 = V_4 -> V_37 ;
return 0 ;
}
case V_135 :
return F_47 ( V_4 ) ;
case V_112 :
if ( V_4 -> V_64 . V_66 != 0 )
F_19 ( V_4 ) ;
V_4 -> V_69 = V_202 ;
return F_42 ( V_4 ) ;
case V_113 :
if ( V_4 -> V_64 . V_66 == 0 ) {
F_40 ( L_39 ,
V_4 -> V_35 ) ;
V_192 = false ;
break;
}
F_19 ( V_4 ) ;
V_39 = F_41 ( V_4 ) ;
if ( V_39 != - V_156 ) {
if ( V_39 )
return V_39 ;
if ( V_192 )
V_4 -> V_69 =
V_203 ;
else
V_4 -> V_69 = V_204 ;
return 0 ;
}
if ( V_192 ) {
V_192 = false ;
break;
}
return F_53 ( V_4 ) ;
case V_134 :
V_4 -> V_187 = false ;
V_4 -> V_142 = false ;
F_24 ( V_4 ) ;
V_4 -> V_73 = false ;
break;
case V_114 :
F_11 ( & V_4 -> V_30 ) ;
V_39 = F_52 ( V_4 ) ;
if ( V_39 == - V_156 )
goto V_200;
if ( V_39 )
return V_39 ;
break;
case V_115 :
V_4 -> V_198 = V_4 -> V_64 . V_67 & ( V_191 - 1 ) ;
break;
case V_121 :
F_49 ( V_4 ) ;
if ( V_4 -> V_5 != V_147 )
break;
if ( ! V_4 -> V_152 )
break;
V_4 -> V_152 = false ;
if ( ! V_4 -> V_82 )
break;
V_4 -> V_83 . type = V_148 ;
V_4 -> V_83 . V_160 = V_4 -> V_37 ;
V_4 -> V_83 . V_161 = 0 ;
V_4 -> V_152 = false ;
return 0 ;
case V_126 :
F_45 ( V_4 ) ;
break;
case V_129 :
F_48 ( V_4 ) ;
break;
case V_125 :
F_51 ( V_4 ) ;
break;
case V_131 :
F_50 ( V_4 ) ;
break;
case V_116 :
V_4 -> V_197 = V_4 -> V_64 . V_67 ;
break;
case V_117 :
if ( ! V_4 -> V_187 ) {
F_25 ( V_4 ) ;
break;
}
V_39 = F_44 ( V_4 , & V_192 ) ;
if ( V_39 )
return V_39 ;
goto V_200;
case V_136 :
return F_23 ( V_4 ) ;
case V_118 :
case V_119 :
case V_120 :
case V_98 :
break;
default:
return F_23 ( V_4 ) ;
}
}
}
static inline bool F_55 ( struct V_3 * V_4 )
{
return V_4 -> V_65 || V_4 -> V_64 . V_66 == 0 ||
V_4 -> V_64 . V_66 == 3 || V_4 -> V_64 . V_66 == 6 ;
}
static int F_56 ( struct V_3 * V_4 )
{
int V_39 ;
while ( 1 ) {
V_39 = F_35 ( V_4 ) ;
if ( V_39 )
return V_39 ;
switch ( V_4 -> V_64 . type ) {
case V_133 :
V_4 -> V_142 = false ;
case V_111 :
case V_112 :
F_6 ( L_34 ) ;
return - V_50 ;
case V_113 :
V_4 -> V_187 = true ;
if ( F_55 ( V_4 ) ) {
T_1 V_205 = V_4 -> V_37 ;
F_20 ( V_4 ) ;
if ( V_205 )
F_46 ( L_40 ,
V_4 -> V_37 ) ;
}
break;
case V_121 :
F_49 ( V_4 ) ;
break;
case V_126 :
F_45 ( V_4 ) ;
break;
case V_129 :
F_48 ( V_4 ) ;
break;
case V_125 :
F_51 ( V_4 ) ;
break;
case V_131 :
F_50 ( V_4 ) ;
break;
case V_115 :
V_4 -> V_198 = V_4 -> V_64 . V_67 & ( V_191 - 1 ) ;
break;
case V_116 :
V_4 -> V_197 = V_4 -> V_64 . V_67 ;
break;
case V_117 :
F_25 ( V_4 ) ;
break;
case V_134 :
V_4 -> V_187 = false ;
V_4 -> V_142 = false ;
F_24 ( V_4 ) ;
case V_110 :
V_4 -> V_73 = false ;
F_6 ( L_34 ) ;
if ( V_4 -> V_37 )
V_4 -> V_69 = V_206 ;
else
V_4 -> V_69 = V_189 ;
return - V_50 ;
case V_136 :
return F_23 ( V_4 ) ;
case V_135 :
return F_47 ( V_4 ) ;
case V_118 :
return 0 ;
case V_114 :
case V_119 :
case V_120 :
case V_98 :
default:
break;
}
}
}
static int F_57 ( struct V_3 * V_4 )
{
int V_39 ;
while ( 1 ) {
V_39 = F_35 ( V_4 ) ;
if ( V_39 )
return V_39 ;
switch ( V_4 -> V_64 . type ) {
case V_133 :
V_4 -> V_142 = false ;
case V_111 :
case V_112 :
V_4 -> V_187 = V_4 -> V_64 . type != V_133 ;
if ( F_55 ( V_4 ) )
F_20 ( V_4 ) ;
if ( V_4 -> V_37 )
return 0 ;
break;
case V_113 :
if ( V_4 -> V_195 ) {
if ( F_55 ( V_4 ) )
F_20 ( V_4 ) ;
if ( V_4 -> V_37 )
return 0 ;
}
if ( V_4 -> V_64 . V_66 )
F_19 ( V_4 ) ;
break;
case V_121 :
F_49 ( V_4 ) ;
break;
case V_126 :
F_45 ( V_4 ) ;
break;
case V_129 :
F_48 ( V_4 ) ;
break;
case V_125 :
F_51 ( V_4 ) ;
break;
case V_131 :
F_50 ( V_4 ) ;
break;
case V_115 :
V_4 -> V_198 = V_4 -> V_64 . V_67 & ( V_191 - 1 ) ;
break;
case V_116 :
V_4 -> V_197 = V_4 -> V_64 . V_67 ;
break;
case V_117 :
F_25 ( V_4 ) ;
break;
case V_135 :
return F_47 ( V_4 ) ;
case V_136 :
return F_23 ( V_4 ) ;
case V_134 :
V_4 -> V_187 = false ;
V_4 -> V_142 = false ;
F_24 ( V_4 ) ;
V_4 -> V_73 = false ;
break;
case V_114 :
V_39 = F_56 ( V_4 ) ;
if ( V_39 )
return V_39 ;
if ( V_4 -> V_37 ) {
V_4 -> V_83 . type = 0 ;
return 0 ;
}
break;
case V_110 :
case V_118 :
case V_119 :
case V_120 :
case V_98 :
default:
break;
}
}
}
static int F_58 ( struct V_3 * V_4 )
{
int V_39 ;
F_6 ( L_41 ) ;
V_39 = F_57 ( V_4 ) ;
if ( V_39 )
return V_39 ;
V_4 -> V_69 = V_188 ;
V_4 -> V_195 = false ;
V_4 -> V_83 . V_160 = 0 ;
V_4 -> V_83 . V_161 = V_4 -> V_37 ;
F_46 ( L_40 , V_4 -> V_37 ) ;
return 0 ;
}
static int F_59 ( struct V_3 * V_4 )
{
const unsigned char * V_207 = V_4 -> V_59 + V_4 -> V_79 ;
T_3 V_2 ;
for ( V_2 = V_208 - 1 ; V_2 ; V_2 -- ) {
if ( V_2 > V_4 -> V_79 )
continue;
if ( ! memcmp ( V_207 - V_2 , V_209 , V_2 ) )
return V_2 ;
}
return 0 ;
}
static int F_60 ( struct V_3 * V_4 , int V_210 )
{
T_3 V_211 = V_208 - V_210 ;
const char * V_212 = V_209 ;
if ( V_211 > V_4 -> V_79 ||
memcmp ( V_4 -> V_59 , V_212 + V_210 , V_211 ) )
return 0 ;
return V_211 ;
}
static int F_61 ( struct V_3 * V_4 ,
int V_210 )
{
int V_211 , V_78 ;
V_4 -> V_35 += V_4 -> V_79 ;
V_4 -> V_79 = 0 ;
V_78 = F_28 ( V_4 ) ;
if ( V_78 )
return V_78 ;
V_211 = F_60 ( V_4 , V_210 ) ;
if ( ! V_211 )
return 0 ;
V_4 -> V_35 -= V_210 ;
V_4 -> V_87 = V_4 -> V_59 + V_211 ;
V_4 -> V_88 = V_4 -> V_79 - V_211 ;
memcpy ( V_4 -> V_89 , V_209 , V_208 ) ;
V_4 -> V_59 = V_4 -> V_89 ;
V_4 -> V_79 = V_208 ;
return 0 ;
}
static int F_62 ( struct V_3 * V_4 )
{
unsigned char * V_200 ;
int V_78 ;
F_6 ( L_42 ) ;
while ( 1 ) {
if ( ! V_4 -> V_79 ) {
V_78 = F_28 ( V_4 ) ;
if ( V_78 )
return V_78 ;
}
V_200 = F_63 ( V_4 -> V_59 , V_4 -> V_79 , V_209 ,
V_208 ) ;
if ( ! V_200 ) {
int V_210 ;
V_210 = F_59 ( V_4 ) ;
if ( V_210 ) {
V_78 = F_61 ( V_4 , V_210 ) ;
if ( V_78 )
return V_78 ;
} else {
V_4 -> V_35 += V_4 -> V_79 ;
V_4 -> V_79 = 0 ;
}
continue;
}
V_4 -> V_74 = V_200 - V_4 -> V_59 ;
return F_35 ( V_4 ) ;
}
}
static int F_64 ( struct V_3 * V_4 )
{
int V_39 ;
V_4 -> V_187 = false ;
V_4 -> V_142 = false ;
V_4 -> V_65 = 0 ;
V_4 -> V_37 = 0 ;
F_11 ( & V_4 -> V_30 ) ;
V_39 = F_62 ( V_4 ) ;
if ( V_39 )
return V_39 ;
V_4 -> V_69 = V_213 ;
V_39 = F_56 ( V_4 ) ;
if ( V_39 )
return V_39 ;
if ( V_4 -> V_37 ) {
V_4 -> V_83 . type = 0 ;
V_4 -> V_69 = V_188 ;
} else {
return F_58 ( V_4 ) ;
}
return 0 ;
}
static T_1 F_65 ( struct V_3 * V_4 )
{
T_1 V_214 = V_4 -> V_141 << 1 ;
if ( ! V_4 -> V_105 || ! V_4 -> V_20 )
goto V_157;
V_214 *= V_4 -> V_20 ;
V_214 /= V_4 -> V_105 ;
V_157:
return V_4 -> V_82 + V_214 ;
}
const struct V_215 * F_66 ( struct V_3 * V_4 )
{
int V_39 ;
do {
V_4 -> V_83 . type = V_186 ;
V_4 -> V_83 . V_179 = 0 ;
switch ( V_4 -> V_69 ) {
case V_70 :
V_39 = F_64 ( V_4 ) ;
break;
case V_213 :
V_4 -> V_65 = 0 ;
case V_175 :
V_39 = F_58 ( V_4 ) ;
break;
case V_188 :
V_39 = F_54 ( V_4 ) ;
break;
case V_201 :
V_39 = F_43 ( V_4 ) ;
if ( V_39 == - V_156 )
V_39 = F_54 ( V_4 ) ;
break;
case V_202 :
case V_185 :
V_39 = F_42 ( V_4 ) ;
break;
case V_204 :
V_4 -> V_69 = V_188 ;
V_39 = F_41 ( V_4 ) ;
if ( V_39 == - V_156 )
V_39 = F_53 ( V_4 ) ;
else if ( ! V_39 )
V_4 -> V_69 = V_204 ;
break;
case V_203 :
V_4 -> V_69 = V_188 ;
V_39 = F_41 ( V_4 ) ;
if ( V_39 == - V_156 )
V_39 = F_54 ( V_4 ) ;
break;
default:
V_39 = F_23 ( V_4 ) ;
break;
}
} while ( V_39 == - V_86 );
V_4 -> V_83 . V_39 = V_39 ? F_15 ( V_39 ) : 0 ;
V_4 -> V_83 . V_82 = V_4 -> V_82 ;
V_4 -> V_83 . V_216 = F_65 ( V_4 ) ;
V_4 -> V_83 . V_198 = V_4 -> V_198 ;
V_4 -> V_83 . V_153 = V_4 -> V_153 ;
if ( V_39 )
V_4 -> V_83 . V_160 = V_4 -> V_37 ;
return & V_4 -> V_83 ;
}
static bool F_67 ( unsigned char * V_59 , T_3 V_79 )
{
if ( V_79 < V_208 )
return false ;
return F_63 ( V_59 , V_208 , V_209 ,
V_208 ) ;
}
static bool F_68 ( unsigned char * * V_59 , T_3 * V_79 )
{
unsigned char * V_200 ;
V_200 = F_63 ( * V_59 , * V_79 , V_209 , V_208 ) ;
if ( V_200 ) {
* V_79 -= V_200 - * V_59 ;
* V_59 = V_200 ;
return true ;
}
return false ;
}
static bool F_69 ( unsigned char * * V_59 , T_3 * V_79 )
{
unsigned char * V_200 ;
if ( ! * V_79 )
return false ;
V_200 = F_63 ( * V_59 + 1 , * V_79 - 1 , V_209 , V_208 ) ;
if ( V_200 ) {
* V_79 -= V_200 - * V_59 ;
* V_59 = V_200 ;
return true ;
}
return false ;
}
static unsigned char * F_70 ( unsigned char * V_59 , T_3 V_79 )
{
const char * V_11 = V_209 ;
unsigned char * V_217 ;
T_3 V_218 ;
if ( V_79 < V_208 )
return NULL ;
V_218 = V_79 - V_208 + 1 ;
while ( 1 ) {
V_217 = F_71 ( V_59 , V_11 [ 0 ] , V_218 ) ;
if ( ! V_217 )
return NULL ;
if ( ! memcmp ( V_217 + 1 , V_11 + 1 , V_208 - 1 ) )
return V_217 ;
V_218 = V_217 - V_59 ;
if ( ! V_218 )
return NULL ;
}
}
static bool F_72 ( unsigned char * V_59 , T_3 V_79 , T_1 * V_219 )
{
struct V_63 V_64 ;
int V_78 ;
while ( V_79 ) {
V_78 = F_30 ( V_59 , V_79 , & V_64 ) ;
if ( V_78 <= 0 )
return false ;
if ( V_64 . type == V_126 ) {
* V_219 = V_64 . V_67 ;
return true ;
}
if ( V_64 . type == V_118 )
return false ;
V_59 += V_78 ;
V_79 -= V_78 ;
}
return false ;
}
static int F_73 ( T_1 V_220 , T_1 V_221 )
{
const T_1 V_222 = ( 1ULL << 55 ) ;
if ( V_220 == V_221 )
return 0 ;
if ( V_220 < V_221 ) {
if ( V_221 - V_220 < V_222 )
return - 1 ;
else
return 1 ;
} else {
if ( V_220 - V_221 < V_222 )
return 1 ;
else
return - 1 ;
}
}
static unsigned char * F_74 ( unsigned char * V_223 ,
T_3 V_224 ,
unsigned char * V_225 ,
T_3 V_226 )
{
T_1 V_227 , V_228 ;
unsigned char * V_217 ;
T_3 V_79 ;
V_217 = F_70 ( V_223 , V_224 ) ;
if ( ! V_217 )
return V_225 ;
V_79 = V_224 - ( V_217 - V_223 ) ;
if ( ! F_72 ( V_217 , V_79 , & V_227 ) ) {
V_224 -= V_79 ;
V_217 = F_70 ( V_223 , V_224 ) ;
if ( ! V_217 )
return V_225 ;
V_79 = V_224 - ( V_217 - V_223 ) ;
if ( ! F_72 ( V_217 , V_79 , & V_227 ) )
return V_225 ;
}
while ( 1 ) {
if ( F_72 ( V_225 , V_226 , & V_228 ) &&
F_73 ( V_227 , V_228 ) < 0 )
return V_225 ;
if ( ! F_69 ( & V_225 , & V_226 ) )
return V_225 + V_226 ;
}
}
unsigned char * F_75 ( unsigned char * V_223 , T_3 V_224 ,
unsigned char * V_225 , T_3 V_226 ,
bool V_229 )
{
unsigned char * V_230 ;
if ( ! F_68 ( & V_225 , & V_226 ) )
return V_225 + V_226 ;
if ( ! F_68 ( & V_223 , & V_224 ) )
return V_225 ;
if ( V_229 ) {
V_230 = F_74 ( V_223 , V_224 , V_225 , V_226 ) ;
if ( V_230 )
return V_230 ;
}
while ( V_226 < V_224 ) {
if ( ! F_69 ( & V_223 , & V_224 ) )
return V_225 ;
}
if ( V_226 > V_224 ) {
while ( ! F_67 ( V_225 + V_224 , V_226 - V_224 ) ) {
if ( ! F_69 ( & V_223 , & V_224 ) )
return V_225 ;
}
}
while ( 1 ) {
V_230 = F_63 ( V_223 , V_224 , V_225 , V_224 ) ;
if ( V_230 )
return V_225 + V_224 ;
if ( ! F_69 ( & V_223 , & V_224 ) )
return V_225 ;
while ( ! F_67 ( V_225 + V_224 , V_226 - V_224 ) ) {
if ( ! F_69 ( & V_223 , & V_224 ) )
return V_225 ;
}
}
}
