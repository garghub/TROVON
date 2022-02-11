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
V_4 -> V_19 = ( T_1 ) 1 << 47 ;
V_4 -> V_20 = ~ ( ( ( T_1 ) 1 << 48 ) - 1 ) ;
V_4 -> V_7 = V_14 -> V_7 ;
V_4 -> V_5 = V_14 -> V_5 ;
V_4 -> V_21 = V_14 -> V_21 ;
V_4 -> V_22 = V_14 -> V_21 ;
F_2 ( V_4 ) ;
V_4 -> V_23 = V_14 -> V_24 ;
V_4 -> V_25 = ( 1 << V_4 -> V_23 ) - 1 ;
V_4 -> V_26 = V_14 -> V_26 ;
V_4 -> V_27 = V_14 -> V_27 ;
if ( ! V_4 -> V_26 )
V_4 -> V_27 = 0 ;
if ( V_4 -> V_27 ) {
if ( ! ( V_4 -> V_26 % V_4 -> V_27 ) )
V_4 -> V_28 = V_4 -> V_26 /
V_4 -> V_27 ;
V_4 -> V_29 = F_3 ( 2 << V_4 -> V_23 ,
V_4 -> V_26 ,
V_4 -> V_27 ) ;
}
if ( V_4 -> V_29 < 0x100 )
V_4 -> V_29 = 0x100 ;
F_6 ( L_1 , V_4 -> V_23 ) ;
F_6 ( L_2 , V_4 -> V_26 ) ;
F_6 ( L_3 , V_4 -> V_27 ) ;
F_6 ( L_4 , V_4 -> V_28 ) ;
F_6 ( L_5 , V_4 -> V_29 ) ;
return V_4 ;
}
static void F_7 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
V_31 -> V_33 = V_33 -> V_34 ;
if ( ! V_31 -> V_35 )
V_31 -> V_35 = V_33 ;
else
free ( V_33 ) ;
}
static T_1 F_8 ( struct V_30 * V_31 )
{
if ( ! V_31 -> V_36 ) {
if ( ! V_31 -> V_33 )
return 0 ;
F_7 ( V_31 ) ;
if ( ! V_31 -> V_33 )
return 0 ;
V_31 -> V_36 = V_37 ;
}
return V_31 -> V_33 -> V_38 [ -- V_31 -> V_36 ] ;
}
static int F_9 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
if ( V_31 -> V_35 ) {
V_33 = V_31 -> V_35 ;
V_31 -> V_35 = NULL ;
} else {
V_33 = malloc ( sizeof( struct V_32 ) ) ;
if ( ! V_33 )
return - V_39 ;
}
V_33 -> V_34 = V_31 -> V_33 ;
V_31 -> V_33 = V_33 ;
V_31 -> V_36 = 0 ;
return 0 ;
}
static int F_10 ( struct V_30 * V_31 , T_1 V_38 )
{
int V_40 ;
if ( ! V_31 -> V_33 || V_31 -> V_36 == V_37 ) {
V_40 = F_9 ( V_31 ) ;
if ( V_40 )
return V_40 ;
}
V_31 -> V_33 -> V_38 [ V_31 -> V_36 ++ ] = V_38 ;
return 0 ;
}
static void F_11 ( struct V_30 * V_31 )
{
while ( V_31 -> V_33 )
F_7 ( V_31 ) ;
V_31 -> V_36 = 0 ;
}
static void F_12 ( struct V_30 * V_31 )
{
F_11 ( V_31 ) ;
F_13 ( & V_31 -> V_33 ) ;
F_13 ( & V_31 -> V_35 ) ;
}
void F_14 ( struct V_3 * V_4 )
{
F_12 ( & V_4 -> V_31 ) ;
free ( V_4 ) ;
}
static int F_15 ( int V_41 )
{
switch ( V_41 ) {
case - V_39 :
return V_42 ;
case - V_43 :
return V_44 ;
case - V_45 :
return V_46 ;
case - V_47 :
return V_48 ;
case - V_49 :
return V_50 ;
case - V_51 :
return V_52 ;
case - V_53 :
return V_54 ;
case - V_55 :
return V_56 ;
case - V_57 :
return V_58 ;
default:
return V_59 ;
}
}
int F_16 ( int V_41 , char * V_60 , T_3 V_61 )
{
if ( V_41 < 1 || V_41 > V_62 )
V_41 = V_59 ;
F_17 ( V_60 , V_63 [ V_41 ] , V_61 ) ;
return 0 ;
}
static T_1 F_18 ( struct V_3 * V_4 ,
const struct V_64 * V_65 ,
T_1 V_66 )
{
T_1 V_38 ;
switch ( V_65 -> V_67 ) {
case 2 :
V_38 = ( V_66 & ( T_1 ) 0xffffffffffff0000ULL ) |
V_65 -> V_68 ;
break;
case 4 :
V_38 = ( V_66 & ( T_1 ) 0xffffffff00000000ULL ) |
V_65 -> V_68 ;
break;
case 6 :
V_38 = V_65 -> V_68 ;
break;
default:
return 0 ;
}
if ( V_38 & V_4 -> V_19 )
return V_38 | V_4 -> V_20 ;
return V_38 ;
}
static inline void F_19 ( struct V_3 * V_4 )
{
V_4 -> V_66 = F_18 ( V_4 , & V_4 -> V_65 ,
V_4 -> V_66 ) ;
}
static inline void F_20 ( struct V_3 * V_4 )
{
F_19 ( V_4 ) ;
V_4 -> V_38 = V_4 -> V_66 ;
}
static void F_21 ( struct V_3 * V_4 )
{
F_22 ( & V_4 -> V_65 , V_4 -> V_69 , V_4 -> V_36 ,
V_4 -> V_60 ) ;
}
static int F_23 ( struct V_3 * V_4 )
{
F_6 ( L_6 ) ;
V_4 -> V_70 = V_71 ;
return - V_43 ;
}
static inline void F_24 ( struct V_3 * V_4 )
{
V_4 -> V_72 = 0 ;
}
static inline void F_25 ( struct V_3 * V_4 )
{
V_4 -> V_72 = V_4 -> V_65 . V_68 & V_73 ;
}
static int F_26 ( struct V_3 * V_4 )
{
F_24 ( V_4 ) ;
V_4 -> V_74 = false ;
V_4 -> V_69 = 1 ;
V_4 -> V_75 = 1 ;
F_21 ( V_4 ) ;
if ( V_4 -> V_70 != V_71 ) {
F_6 ( L_7 ) ;
V_4 -> V_70 = V_76 ;
}
return - V_45 ;
}
static int F_27 ( struct V_3 * V_4 )
{
struct V_77 V_78 = { . V_60 = 0 , } ;
int V_79 ;
V_4 -> V_75 = 0 ;
F_6 ( L_8 ) ;
V_79 = V_4 -> V_15 ( & V_78 , V_4 -> V_17 ) ;
if ( V_79 )
return V_79 ;
V_4 -> V_60 = V_78 . V_60 ;
V_4 -> V_80 = V_78 . V_80 ;
if ( ! V_4 -> V_80 ) {
F_6 ( L_9 ) ;
return - V_47 ;
}
if ( ! V_78 . V_81 ) {
V_4 -> V_38 = 0 ;
V_4 -> V_70 = V_71 ;
V_4 -> V_82 = V_78 . V_82 ;
V_4 -> V_83 = 0 ;
V_4 -> V_74 = false ;
V_4 -> V_84 . V_85 = V_78 . V_85 ;
F_6 ( L_10 V_86 L_11 ,
V_4 -> V_82 ) ;
return - V_87 ;
}
return 0 ;
}
static int F_28 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_88 )
return F_27 ( V_4 ) ;
V_4 -> V_60 = V_4 -> V_88 ;
V_4 -> V_80 = V_4 -> V_89 ;
V_4 -> V_88 = 0 ;
V_4 -> V_89 = 0 ;
return 0 ;
}
static int F_29 ( struct V_3 * V_4 )
{
unsigned char * V_60 = V_4 -> V_90 ;
T_3 V_91 , V_80 , V_11 ;
int V_79 ;
V_91 = V_4 -> V_80 ;
V_80 = V_4 -> V_80 ;
memcpy ( V_60 , V_4 -> V_60 , V_80 ) ;
V_79 = F_27 ( V_4 ) ;
if ( V_79 ) {
V_4 -> V_36 += V_91 ;
return V_79 < 0 ? V_79 : - V_92 ;
}
V_11 = V_93 - V_80 ;
if ( V_11 > V_4 -> V_80 )
V_11 = V_4 -> V_80 ;
memcpy ( V_60 + V_80 , V_4 -> V_60 , V_11 ) ;
V_80 += V_11 ;
V_79 = F_30 ( V_60 , V_80 , & V_4 -> V_65 ) ;
if ( V_79 < ( int ) V_91 ) {
V_4 -> V_88 = V_4 -> V_60 ;
V_4 -> V_89 = V_4 -> V_80 ;
V_4 -> V_60 = V_60 ;
V_4 -> V_80 = V_91 ;
return F_26 ( V_4 ) ;
}
V_4 -> V_88 = V_4 -> V_60 + ( V_79 - V_91 ) ;
V_4 -> V_89 = V_4 -> V_80 - ( V_79 - V_91 ) ;
V_4 -> V_60 = V_60 ;
V_4 -> V_80 = V_79 ;
return V_79 ;
}
static int F_31 ( struct V_3 * V_4 ,
T_4 V_94 , void * V_17 )
{
struct V_95 V_96 ;
const unsigned char * V_60 = V_4 -> V_60 ;
T_3 V_80 = V_4 -> V_80 ;
int V_79 ;
V_96 . V_4 = V_4 ;
V_96 . V_36 = V_4 -> V_36 ;
V_96 . V_69 = V_4 -> V_75 ;
V_96 . V_97 = V_4 -> V_97 ;
V_96 . V_17 = V_17 ;
while ( 1 ) {
do {
V_96 . V_36 += V_96 . V_69 ;
V_60 += V_96 . V_69 ;
V_80 -= V_96 . V_69 ;
if ( ! V_80 )
return V_98 ;
V_79 = F_30 ( V_60 , V_80 , & V_96 . V_65 ) ;
if ( ! V_79 )
return V_98 ;
if ( V_79 < 0 )
return V_79 ;
V_96 . V_69 = V_79 ;
} while ( V_96 . V_65 . type == V_99 );
V_79 = V_94 ( & V_96 ) ;
if ( V_79 )
return 0 ;
V_96 . V_97 = V_96 . V_65 . type ;
}
}
static int F_32 ( struct V_95 * V_96 )
{
struct V_3 * V_4 = V_96 -> V_4 ;
struct V_100 * V_17 = V_96 -> V_17 ;
T_1 V_83 ;
double V_101 ;
unsigned int V_102 ;
T_2 V_103 , V_104 , V_105 , V_106 , V_107 ;
switch ( V_96 -> V_65 . type ) {
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_99 :
case V_117 :
case V_118 :
return 0 ;
case V_119 :
if ( ! V_17 -> V_74 )
return 0 ;
V_103 = V_96 -> V_65 . V_68 ;
if ( V_103 > V_17 -> V_120 )
V_104 = V_103 - V_17 -> V_120 ;
else
V_104 = V_103 + 256 - V_17 -> V_120 ;
V_17 -> V_121 += V_104 << V_4 -> V_23 ;
V_17 -> V_120 = V_103 ;
if ( V_4 -> V_28 ) {
V_83 = V_17 -> V_122 +
V_17 -> V_121 * V_4 -> V_28 ;
} else {
V_83 = V_17 -> V_122 +
F_3 ( V_17 -> V_121 ,
V_4 -> V_26 ,
V_4 -> V_27 ) ;
}
if ( V_83 < V_17 -> V_83 )
return 1 ;
if ( V_96 -> V_97 != V_123 ) {
V_17 -> V_83 = V_83 ;
return 0 ;
}
break;
case V_124 :
V_83 = V_96 -> V_65 . V_68 |
( V_17 -> V_83 & ( 0xffULL << 56 ) ) ;
if ( V_17 -> V_125 && V_83 < V_17 -> V_83 &&
V_17 -> V_83 - V_83 < V_4 -> V_29 )
return 1 ;
while ( V_83 < V_17 -> V_83 )
V_83 += ( 1ULL << 56 ) ;
if ( V_96 -> V_97 != V_123 ) {
if ( V_17 -> V_125 )
return 1 ;
V_17 -> V_126 = V_83 ;
V_17 -> V_83 = V_83 ;
return 0 ;
}
break;
case V_127 :
if ( V_17 -> V_125 )
return 1 ;
if ( ! V_4 -> V_27 )
return 0 ;
V_105 = V_96 -> V_65 . V_68 ;
V_106 = V_96 -> V_65 . V_67 ;
V_107 = V_105 & V_4 -> V_25 ;
V_17 -> V_120 = ( V_105 >> V_4 -> V_23 ) & 0xff ;
V_17 -> V_122 = V_17 -> V_126 - V_106 ;
if ( V_4 -> V_28 ) {
V_17 -> V_122 -= V_107 * V_4 -> V_28 ;
} else {
V_17 -> V_122 -=
F_3 ( V_107 , V_4 -> V_26 ,
V_4 -> V_27 ) ;
}
V_17 -> V_121 = 0 ;
V_17 -> V_74 = true ;
return 0 ;
case V_123 :
V_17 -> V_128 += V_96 -> V_65 . V_68 ;
return 0 ;
case V_129 :
V_102 = V_96 -> V_65 . V_68 ;
if ( V_17 -> V_102 && V_17 -> V_102 != V_102 )
return 1 ;
V_17 -> V_102 = V_102 ;
V_17 -> V_130 = V_4 -> V_22 / V_102 ;
return 0 ;
case V_131 :
case V_132 :
case V_133 :
case V_134 :
default:
return 1 ;
}
if ( ! V_17 -> V_102 && V_4 -> V_102 ) {
V_17 -> V_102 = V_4 -> V_102 ;
V_17 -> V_130 = V_4 -> V_130 ;
}
if ( ! V_17 -> V_128 )
return 1 ;
V_101 = ( double ) ( V_83 - V_4 -> V_83 ) / V_17 -> V_128 ;
if ( V_17 -> V_102 && V_101 > V_17 -> V_130 &&
V_101 / V_17 -> V_130 > 1.25 ) {
F_6 ( L_12 V_135 L_11 ,
V_101 , V_17 -> V_130 , V_96 -> V_36 ) ;
return 1 ;
}
V_4 -> V_136 = V_101 ;
V_4 -> V_137 = true ;
if ( V_17 -> V_102 ) {
F_6 ( L_13 V_135 L_11 ,
V_101 , V_17 -> V_130 , V_96 -> V_36 ) ;
} else {
F_6 ( L_14 V_135 L_11 ,
V_101 , V_96 -> V_36 ) ;
}
return 1 ;
}
static void F_33 ( struct V_3 * V_4 ,
bool V_125 )
{
struct V_100 V_17 = {
. V_128 = 0 ,
. V_102 = 0 ,
. V_120 = V_4 -> V_120 ,
. V_122 = V_4 -> V_122 ,
. V_121 = V_4 -> V_121 ,
. V_126 = V_4 -> V_126 ,
. V_83 = V_4 -> V_83 ,
. V_74 = V_4 -> V_74 ,
. V_125 = V_125 ,
. V_130 = 0 ,
} ;
F_31 ( V_4 , F_32 , & V_17 ) ;
}
static int F_34 ( struct V_3 * V_4 )
{
int V_79 ;
V_4 -> V_97 = V_4 -> V_65 . type ;
do {
V_4 -> V_36 += V_4 -> V_75 ;
V_4 -> V_60 += V_4 -> V_75 ;
V_4 -> V_80 -= V_4 -> V_75 ;
if ( ! V_4 -> V_80 ) {
V_79 = F_28 ( V_4 ) ;
if ( V_79 )
return V_79 ;
}
V_79 = F_30 ( V_4 -> V_60 , V_4 -> V_80 ,
& V_4 -> V_65 ) ;
if ( V_79 == V_98 &&
V_4 -> V_80 < V_93 && ! V_4 -> V_88 ) {
V_79 = F_29 ( V_4 ) ;
if ( V_79 < 0 )
return V_79 ;
}
if ( V_79 <= 0 )
return F_26 ( V_4 ) ;
V_4 -> V_69 = V_79 ;
V_4 -> V_75 = V_79 ;
F_21 ( V_4 ) ;
} while ( V_4 -> V_65 . type == V_99 );
return 0 ;
}
static T_1 F_35 ( struct V_3 * V_4 )
{
T_1 V_83 , V_138 ;
V_83 = V_4 -> V_83 + V_4 -> V_139 ;
V_138 = V_83 & V_4 -> V_8 ;
if ( V_4 -> V_140 ) {
if ( V_138 != V_4 -> V_141 )
return 1 ;
} else {
V_83 += 1 ;
V_138 = V_83 & V_4 -> V_8 ;
if ( V_138 != V_4 -> V_141 ) {
V_4 -> V_141 = V_138 ;
V_4 -> V_140 = true ;
}
}
return V_4 -> V_9 - ( V_83 - V_138 ) ;
}
static T_1 F_36 ( struct V_3 * V_4 )
{
switch ( V_4 -> V_5 ) {
case V_142 :
return V_4 -> V_7 - V_4 -> V_143 ;
case V_6 :
return F_35 ( V_4 ) ;
case V_144 :
case V_145 :
default:
return 0 ;
}
}
static void F_37 ( struct V_3 * V_4 )
{
T_1 V_83 , V_138 ;
switch ( V_4 -> V_5 ) {
case V_142 :
V_4 -> V_143 = 0 ;
break;
case V_6 :
V_83 = V_4 -> V_83 + V_4 -> V_139 ;
V_138 = V_83 & V_4 -> V_8 ;
V_4 -> V_141 = V_138 ;
break;
case V_144 :
case V_145 :
default:
break;
}
V_4 -> V_84 . type |= V_146 ;
}
static int F_38 ( struct V_3 * V_4 ,
struct V_147 * V_147 , T_1 V_38 )
{
T_1 V_148 , V_149 = 0 ;
int V_40 ;
if ( ! V_4 -> V_150 )
V_4 -> V_150 = true ;
V_148 = F_36 ( V_4 ) ;
V_40 = V_4 -> V_16 ( V_147 , & V_149 , & V_4 -> V_38 , V_38 ,
V_148 , V_4 -> V_17 ) ;
V_4 -> V_151 += V_149 ;
V_4 -> V_139 += V_149 ;
V_4 -> V_143 += V_149 ;
if ( V_40 ) {
V_4 -> V_152 = 0 ;
V_4 -> V_70 = V_153 ;
F_39 ( L_15 ,
V_4 -> V_38 ) ;
if ( V_40 == - V_51 )
return - V_87 ;
return - V_49 ;
}
if ( V_38 && V_4 -> V_38 == V_38 ) {
V_40 = - V_154 ;
goto V_155;
}
if ( V_148 && V_149 >= V_148 )
F_37 ( V_4 ) ;
if ( V_147 -> V_156 == V_157 ) {
V_4 -> V_84 . type = V_146 ;
V_4 -> V_84 . V_158 = V_4 -> V_38 ;
V_4 -> V_84 . V_159 = 0 ;
V_4 -> V_38 += V_147 -> V_160 ;
V_40 = V_161 ;
goto V_155;
}
if ( V_147 -> V_162 == V_163 ) {
if ( V_147 -> V_156 != V_164 ||
V_147 -> V_165 ) {
V_40 = F_10 ( & V_4 -> V_31 , V_4 -> V_38 +
V_147 -> V_160 ) ;
if ( V_40 )
goto V_155;
}
} else if ( V_147 -> V_162 == V_166 ) {
V_4 -> V_167 = F_8 ( & V_4 -> V_31 ) ;
}
if ( V_147 -> V_156 == V_164 ) {
int V_168 = V_4 -> V_152 ++ ;
V_4 -> V_84 . V_158 = V_4 -> V_38 ;
V_4 -> V_38 += V_147 -> V_160 +
V_147 -> V_165 ;
V_4 -> V_84 . V_159 = V_4 -> V_38 ;
V_40 = V_161 ;
if ( V_168 ) {
if ( V_168 == 1 ) {
V_4 -> V_169 = V_4 -> V_84 . V_159 ;
V_4 -> V_170 = 1 ;
V_4 -> V_171 = 1 ;
} else if ( V_168 > V_172 ||
V_4 -> V_84 . V_159 == V_4 -> V_169 ) {
F_39 ( L_16 ,
V_4 -> V_84 . V_159 ) ;
V_4 -> V_70 = V_173 ;
V_40 = - V_57 ;
goto V_155;
} else if ( ! -- V_4 -> V_171 ) {
V_4 -> V_170 += 1 ;
V_4 -> V_171 = V_4 -> V_170 ;
V_4 -> V_169 = V_4 -> V_84 . V_159 ;
}
}
goto V_174;
}
V_155:
V_4 -> V_152 = 0 ;
V_174:
V_4 -> V_84 . V_175 = V_147 -> V_162 ;
V_4 -> V_84 . V_176 = V_147 -> V_160 ;
if ( V_4 -> V_72 & V_73 )
V_4 -> V_84 . V_177 |= V_73 ;
return V_40 ;
}
static int F_40 ( struct V_3 * V_4 )
{
struct V_147 V_147 ;
T_1 V_38 ;
int V_40 ;
V_38 = V_4 -> V_66 ;
while ( 1 ) {
V_40 = F_38 ( V_4 , & V_147 , V_38 ) ;
if ( V_40 == V_161 )
return 0 ;
if ( V_40 == - V_154 ) {
if ( V_4 -> V_178 ) {
V_4 -> V_178 = false ;
V_4 -> V_72 = V_4 -> V_179 ;
V_4 -> V_84 . type = V_180 ;
V_4 -> V_84 . V_158 = V_4 -> V_38 ;
V_4 -> V_84 . V_159 = 0 ;
V_4 -> V_84 . V_177 = V_4 -> V_179 ;
return 0 ;
}
return V_40 ;
}
V_4 -> V_178 = false ;
if ( V_40 )
return V_40 ;
if ( V_147 . V_156 == V_181 ) {
F_39 ( L_17 ,
V_4 -> V_38 ) ;
V_4 -> V_70 = V_173 ;
return - V_51 ;
}
if ( V_147 . V_156 == V_182 ) {
F_39 ( L_18 ,
V_4 -> V_38 ) ;
V_4 -> V_70 = V_173 ;
return - V_51 ;
}
F_23 ( V_4 ) ;
}
}
static int F_41 ( struct V_3 * V_4 )
{
struct V_147 V_147 ;
int V_40 ;
V_40 = F_38 ( V_4 , & V_147 , 0 ) ;
if ( V_40 == V_161 )
return 0 ;
if ( V_40 )
return V_40 ;
if ( V_147 . V_156 == V_181 ) {
if ( V_4 -> V_70 == V_183 ) {
V_4 -> V_184 = false ;
V_4 -> V_140 = false ;
V_4 -> V_70 = V_185 ;
V_4 -> V_84 . V_158 = V_4 -> V_38 ;
V_4 -> V_84 . V_159 = 0 ;
if ( V_4 -> V_65 . V_67 != 0 )
V_4 -> V_38 = V_4 -> V_66 ;
} else {
V_4 -> V_70 = V_185 ;
V_4 -> V_84 . V_158 = V_4 -> V_38 ;
if ( V_4 -> V_65 . V_67 == 0 ) {
V_4 -> V_84 . V_159 = 0 ;
} else {
V_4 -> V_84 . V_159 = V_4 -> V_66 ;
V_4 -> V_38 = V_4 -> V_66 ;
}
}
return 0 ;
}
if ( V_147 . V_156 == V_182 ) {
F_39 ( L_19 ,
V_4 -> V_38 ) ;
V_4 -> V_70 = V_173 ;
return - V_51 ;
}
return F_23 ( V_4 ) ;
}
static int F_42 ( struct V_3 * V_4 )
{
struct V_147 V_147 ;
int V_40 ;
while ( 1 ) {
V_40 = F_38 ( V_4 , & V_147 , 0 ) ;
if ( V_40 == V_161 )
return 0 ;
if ( V_40 )
return V_40 ;
if ( V_147 . V_162 == V_166 ) {
if ( ! V_4 -> V_18 ) {
F_39 ( L_20 ,
V_4 -> V_38 ) ;
V_4 -> V_70 = V_186 ;
return - V_51 ;
}
if ( ! V_4 -> V_167 ) {
F_39 ( L_21 ,
V_4 -> V_38 ) ;
V_4 -> V_70 = V_186 ;
return - V_51 ;
}
if ( ! ( V_4 -> V_187 . V_68 & V_188 ) ) {
F_39 ( L_22 ,
V_4 -> V_38 ) ;
V_4 -> V_70 = V_186 ;
return - V_51 ;
}
V_4 -> V_187 . V_67 -= 1 ;
if ( ! V_4 -> V_187 . V_67 )
V_4 -> V_70 = V_185 ;
V_4 -> V_187 . V_68 <<= 1 ;
V_4 -> V_84 . V_158 = V_4 -> V_38 ;
V_4 -> V_38 = V_4 -> V_167 ;
V_4 -> V_84 . V_159 = V_4 -> V_38 ;
return 0 ;
}
if ( V_147 . V_156 == V_181 ) {
V_40 = F_34 ( V_4 ) ;
if ( V_40 )
return V_40 ;
if ( V_4 -> V_65 . type != V_110 ||
V_4 -> V_65 . V_67 == 0 ) {
F_39 ( L_23 ,
V_4 -> V_38 ) ;
V_4 -> V_70 = V_186 ;
V_4 -> V_75 = 0 ;
return - V_51 ;
}
F_19 ( V_4 ) ;
V_4 -> V_84 . V_158 = V_4 -> V_38 ;
V_4 -> V_84 . V_159 = V_4 -> V_66 ;
V_4 -> V_38 = V_4 -> V_66 ;
return 0 ;
}
if ( V_147 . V_156 == V_182 ) {
V_4 -> V_187 . V_67 -= 1 ;
if ( ! V_4 -> V_187 . V_67 )
V_4 -> V_70 = V_185 ;
if ( V_4 -> V_187 . V_68 & V_188 ) {
V_4 -> V_187 . V_68 <<= 1 ;
V_4 -> V_84 . V_158 = V_4 -> V_38 ;
V_4 -> V_38 += V_147 . V_160 +
V_147 . V_165 ;
V_4 -> V_84 . V_159 = V_4 -> V_38 ;
return 0 ;
}
if ( V_4 -> V_84 . type & V_146 ) {
V_4 -> V_187 . V_68 <<= 1 ;
V_4 -> V_84 . type = V_146 ;
V_4 -> V_84 . V_158 = V_4 -> V_38 ;
V_4 -> V_84 . V_159 = 0 ;
V_4 -> V_38 += V_147 . V_160 ;
return 0 ;
}
V_4 -> V_38 += V_147 . V_160 ;
if ( ! V_4 -> V_187 . V_67 )
return - V_154 ;
V_4 -> V_187 . V_68 <<= 1 ;
continue;
}
return F_23 ( V_4 ) ;
}
}
static int F_43 ( struct V_3 * V_4 , bool * V_189 )
{
unsigned int V_179 ;
int V_40 ;
V_179 = V_4 -> V_65 . V_68 &
( V_73 | V_190 ) ;
V_40 = F_34 ( V_4 ) ;
if ( V_40 )
return V_40 ;
if ( V_4 -> V_65 . type == V_111 ) {
V_4 -> V_179 = V_179 ;
V_4 -> V_178 = true ;
if ( ! ( V_4 -> V_179 & V_190 ) )
* V_189 = true ;
} else {
F_39 ( L_24 ,
V_4 -> V_36 ) ;
F_25 ( V_4 ) ;
}
return 0 ;
}
static void F_44 ( struct V_3 * V_4 )
{
T_1 V_83 ;
V_4 -> V_74 = false ;
if ( V_4 -> V_82 ) {
V_83 = V_4 -> V_65 . V_68 |
( V_4 -> V_82 & ( 0xffULL << 56 ) ) ;
if ( V_83 < V_4 -> V_82 ) {
if ( V_4 -> V_82 - V_83 > ( 1ULL << 55 ) )
V_83 += ( 1ULL << 56 ) ;
} else {
if ( V_83 - V_4 -> V_82 > ( 1ULL << 55 ) )
V_83 -= ( 1ULL << 56 ) ;
}
V_4 -> V_126 = V_83 ;
V_4 -> V_83 = V_83 ;
V_4 -> V_82 = 0 ;
V_4 -> V_139 = 0 ;
} else if ( V_4 -> V_83 ) {
V_83 = V_4 -> V_65 . V_68 |
( V_4 -> V_83 & ( 0xffULL << 56 ) ) ;
V_4 -> V_126 = V_83 ;
if ( V_83 < V_4 -> V_83 &&
V_4 -> V_83 - V_83 < V_4 -> V_29 ) {
F_45 ( L_25 ,
V_83 ) ;
V_83 = V_4 -> V_83 ;
}
while ( V_83 < V_4 -> V_83 ) {
F_45 ( L_26 , V_83 ) ;
V_83 += ( 1ULL << 56 ) ;
V_4 -> V_126 = V_83 ;
}
V_4 -> V_83 = V_83 ;
V_4 -> V_139 = 0 ;
}
if ( V_4 -> V_97 == V_123 ) {
V_4 -> V_191 = V_4 -> V_83 ;
V_4 -> V_128 = 0 ;
V_4 -> V_137 = false ;
F_33 ( V_4 , false ) ;
}
F_45 ( L_27 , V_4 -> V_83 ) ;
}
static int F_46 ( struct V_3 * V_4 )
{
F_6 ( L_28 ) ;
F_24 ( V_4 ) ;
V_4 -> V_74 = false ;
V_4 -> V_102 = 0 ;
V_4 -> V_70 = V_173 ;
V_4 -> V_192 = true ;
return - V_53 ;
}
static void F_47 ( struct V_3 * V_4 )
{
T_2 V_105 = V_4 -> V_65 . V_68 ;
T_2 V_106 = V_4 -> V_65 . V_67 ;
T_2 V_107 = V_105 & V_4 -> V_25 ;
if ( ! V_4 -> V_27 )
return;
V_4 -> V_120 = ( V_105 >> V_4 -> V_23 ) & 0xff ;
V_4 -> V_122 = V_4 -> V_126 - V_106 ;
if ( V_4 -> V_28 ) {
V_4 -> V_122 -= V_107 * V_4 -> V_28 ;
} else {
V_4 -> V_122 -= F_3 ( V_107 ,
V_4 -> V_26 ,
V_4 -> V_27 ) ;
}
V_4 -> V_121 = 0 ;
V_4 -> V_74 = true ;
F_6 ( L_29 V_135 L_30 ,
V_4 -> V_122 , V_4 -> V_120 , V_107 ) ;
}
static void F_48 ( struct V_3 * V_4 )
{
T_1 V_83 ;
T_2 V_103 , V_104 ;
if ( ! V_4 -> V_74 )
return;
V_103 = V_4 -> V_65 . V_68 ;
if ( V_103 > V_4 -> V_120 )
V_104 = V_103 - V_4 -> V_120 ;
else
V_104 = V_103 + 256 - V_4 -> V_120 ;
V_4 -> V_121 += V_104 << V_4 -> V_23 ;
if ( V_4 -> V_28 ) {
V_83 = V_4 -> V_122 +
V_4 -> V_121 * V_4 -> V_28 ;
} else {
V_83 = V_4 -> V_122 +
F_3 ( V_4 -> V_121 ,
V_4 -> V_26 ,
V_4 -> V_27 ) ;
}
if ( V_83 < V_4 -> V_83 )
F_6 ( L_31 V_135 L_32 V_135 L_11 ,
V_83 , V_4 -> V_83 ) ;
else
V_4 -> V_83 = V_83 ;
V_4 -> V_139 = 0 ;
V_4 -> V_120 = V_103 ;
if ( V_4 -> V_97 == V_123 ) {
V_4 -> V_191 = V_4 -> V_83 ;
V_4 -> V_128 = 0 ;
V_4 -> V_137 = false ;
F_33 ( V_4 , true ) ;
}
}
static void F_49 ( struct V_3 * V_4 )
{
unsigned int V_102 = V_4 -> V_65 . V_68 ;
if ( V_4 -> V_102 == V_102 )
return;
V_4 -> V_102 = V_102 ;
V_4 -> V_130 = V_4 -> V_22 / V_102 ;
}
static void F_50 ( struct V_3 * V_4 )
{
T_1 V_83 = V_4 -> V_191 ;
V_4 -> V_193 = true ;
V_4 -> V_128 += V_4 -> V_65 . V_68 ;
if ( ! V_4 -> V_191 )
return;
if ( V_4 -> V_137 )
V_83 += V_4 -> V_128 * V_4 -> V_136 ;
else if ( V_4 -> V_102 )
V_83 += V_4 -> V_128 * V_4 -> V_130 ;
else
return;
if ( V_83 < V_4 -> V_83 )
F_6 ( L_33 V_135 L_32 V_135 L_11 ,
V_83 , V_4 -> V_83 ) ;
else
V_4 -> V_83 = V_83 ;
}
static int F_51 ( struct V_3 * V_4 )
{
int V_40 ;
while ( 1 ) {
V_40 = F_34 ( V_4 ) ;
if ( V_40 )
return V_40 ;
switch ( V_4 -> V_65 . type ) {
case V_116 :
return 0 ;
case V_131 :
case V_109 :
case V_110 :
case V_108 :
case V_132 :
case V_134 :
case V_112 :
V_4 -> V_74 = false ;
F_6 ( L_34 ) ;
return - V_154 ;
case V_133 :
return F_46 ( V_4 ) ;
case V_124 :
F_44 ( V_4 ) ;
break;
case V_127 :
F_47 ( V_4 ) ;
break;
case V_129 :
F_49 ( V_4 ) ;
break;
case V_114 :
V_4 -> V_194 = V_4 -> V_65 . V_68 ;
break;
case V_113 :
V_4 -> V_195 = V_4 -> V_65 . V_68 & ( V_188 - 1 ) ;
break;
case V_111 :
V_4 -> V_184 = true ;
F_19 ( V_4 ) ;
break;
case V_115 :
F_25 ( V_4 ) ;
break;
case V_119 :
F_48 ( V_4 ) ;
if ( V_4 -> V_5 == V_145 )
V_4 -> V_84 . type |= V_146 ;
break;
case V_123 :
case V_117 :
case V_118 :
case V_99 :
default:
break;
}
}
}
static int F_52 ( struct V_3 * V_4 )
{
int V_40 ;
if ( V_4 -> V_72 & V_190 ) {
V_4 -> V_72 = 0 ;
V_4 -> V_84 . V_177 &= ~ V_73 ;
V_4 -> V_84 . V_177 |= V_190 ;
} else {
V_4 -> V_84 . V_177 |= V_196 ;
}
while ( 1 ) {
V_40 = F_34 ( V_4 ) ;
if ( V_40 )
return V_40 ;
switch ( V_4 -> V_65 . type ) {
case V_108 :
case V_111 :
case V_132 :
case V_112 :
case V_124 :
case V_127 :
case V_129 :
case V_115 :
case V_134 :
case V_116 :
F_6 ( L_35 ) ;
V_4 -> V_70 = V_186 ;
return - V_51 ;
case V_133 :
return F_46 ( V_4 ) ;
case V_131 :
V_4 -> V_84 . V_158 = V_4 -> V_38 ;
V_4 -> V_84 . V_159 = 0 ;
if ( V_4 -> V_65 . V_67 != 0 ) {
F_20 ( V_4 ) ;
F_6 ( L_36 V_135 L_11 ,
V_4 -> V_38 ) ;
}
V_4 -> V_184 = false ;
V_4 -> V_140 = false ;
return 0 ;
case V_109 :
V_4 -> V_184 = true ;
F_6 ( L_37 V_135 L_11 ,
V_4 -> V_38 ) ;
V_4 -> V_84 . V_158 = 0 ;
if ( V_4 -> V_65 . V_67 == 0 ) {
V_4 -> V_84 . V_159 = 0 ;
} else {
F_20 ( V_4 ) ;
V_4 -> V_84 . V_159 = V_4 -> V_38 ;
}
return 0 ;
case V_110 :
V_4 -> V_84 . V_158 = V_4 -> V_38 ;
if ( V_4 -> V_65 . V_67 == 0 ) {
V_4 -> V_84 . V_159 = 0 ;
} else {
F_20 ( V_4 ) ;
V_4 -> V_84 . V_159 = V_4 -> V_38 ;
}
return 0 ;
case V_113 :
V_4 -> V_195 = V_4 -> V_65 . V_68 & ( V_188 - 1 ) ;
break;
case V_119 :
F_48 ( V_4 ) ;
if ( V_4 -> V_5 == V_145 )
V_4 -> V_84 . type |= V_146 ;
break;
case V_123 :
F_50 ( V_4 ) ;
break;
case V_114 :
V_4 -> V_194 = V_4 -> V_65 . V_68 ;
break;
case V_117 :
case V_118 :
case V_99 :
break;
default:
return F_23 ( V_4 ) ;
}
}
}
static int F_53 ( struct V_3 * V_4 )
{
bool V_189 = false ;
int V_40 ;
while ( 1 ) {
V_40 = F_34 ( V_4 ) ;
if ( V_40 )
return V_40 ;
V_197:
switch ( V_4 -> V_65 . type ) {
case V_108 :
if ( ! V_4 -> V_65 . V_67 )
break;
V_4 -> V_187 = V_4 -> V_65 ;
V_4 -> V_70 = V_198 ;
V_40 = F_42 ( V_4 ) ;
if ( V_40 == - V_154 )
break;
return V_40 ;
case V_131 :
if ( V_4 -> V_65 . V_67 != 0 )
F_19 ( V_4 ) ;
V_4 -> V_70 = V_183 ;
return F_41 ( V_4 ) ;
case V_109 : {
V_4 -> V_184 = true ;
if ( V_4 -> V_65 . V_67 == 0 ) {
F_39 ( L_38 ,
V_4 -> V_36 ) ;
break;
}
F_20 ( V_4 ) ;
V_4 -> V_84 . V_158 = 0 ;
V_4 -> V_84 . V_159 = V_4 -> V_38 ;
return 0 ;
}
case V_133 :
return F_46 ( V_4 ) ;
case V_110 :
if ( V_4 -> V_65 . V_67 != 0 )
F_19 ( V_4 ) ;
V_4 -> V_70 = V_199 ;
return F_41 ( V_4 ) ;
case V_111 :
if ( V_4 -> V_65 . V_67 == 0 ) {
F_39 ( L_39 ,
V_4 -> V_36 ) ;
V_189 = false ;
break;
}
F_19 ( V_4 ) ;
V_40 = F_40 ( V_4 ) ;
if ( V_40 != - V_154 ) {
if ( V_40 )
return V_40 ;
if ( V_189 )
V_4 -> V_70 =
V_200 ;
else
V_4 -> V_70 = V_201 ;
return 0 ;
}
if ( V_189 ) {
V_189 = false ;
break;
}
return F_52 ( V_4 ) ;
case V_132 :
V_4 -> V_184 = false ;
V_4 -> V_140 = false ;
F_24 ( V_4 ) ;
V_4 -> V_74 = false ;
break;
case V_112 :
F_11 ( & V_4 -> V_31 ) ;
V_40 = F_51 ( V_4 ) ;
if ( V_40 == - V_154 )
goto V_197;
if ( V_40 )
return V_40 ;
break;
case V_113 :
V_4 -> V_195 = V_4 -> V_65 . V_68 & ( V_188 - 1 ) ;
break;
case V_119 :
F_48 ( V_4 ) ;
if ( V_4 -> V_5 != V_145 )
break;
if ( ! V_4 -> V_150 )
break;
V_4 -> V_150 = false ;
if ( ! V_4 -> V_83 )
break;
V_4 -> V_84 . type = V_146 ;
V_4 -> V_84 . V_158 = V_4 -> V_38 ;
V_4 -> V_84 . V_159 = 0 ;
V_4 -> V_150 = false ;
return 0 ;
case V_124 :
F_44 ( V_4 ) ;
break;
case V_127 :
F_47 ( V_4 ) ;
break;
case V_123 :
F_50 ( V_4 ) ;
break;
case V_129 :
F_49 ( V_4 ) ;
break;
case V_114 :
V_4 -> V_194 = V_4 -> V_65 . V_68 ;
break;
case V_115 :
if ( ! V_4 -> V_184 ) {
F_25 ( V_4 ) ;
break;
}
V_40 = F_43 ( V_4 , & V_189 ) ;
if ( V_40 )
return V_40 ;
goto V_197;
case V_134 :
return F_23 ( V_4 ) ;
case V_116 :
case V_117 :
case V_118 :
case V_99 :
break;
default:
return F_23 ( V_4 ) ;
}
}
}
static int F_54 ( struct V_3 * V_4 )
{
int V_40 ;
while ( 1 ) {
V_40 = F_34 ( V_4 ) ;
if ( V_40 )
return V_40 ;
switch ( V_4 -> V_65 . type ) {
case V_131 :
V_4 -> V_140 = false ;
case V_109 :
case V_110 :
F_6 ( L_34 ) ;
return - V_51 ;
case V_111 :
V_4 -> V_184 = true ;
if ( V_4 -> V_66 || V_4 -> V_65 . V_67 == 6 ||
V_4 -> V_65 . V_67 == 0 ) {
T_1 V_202 = V_4 -> V_38 ;
F_20 ( V_4 ) ;
if ( V_202 )
F_45 ( L_40 ,
V_4 -> V_38 ) ;
}
break;
case V_119 :
F_48 ( V_4 ) ;
break;
case V_124 :
F_44 ( V_4 ) ;
break;
case V_127 :
F_47 ( V_4 ) ;
break;
case V_123 :
F_50 ( V_4 ) ;
break;
case V_129 :
F_49 ( V_4 ) ;
break;
case V_113 :
V_4 -> V_195 = V_4 -> V_65 . V_68 & ( V_188 - 1 ) ;
break;
case V_114 :
V_4 -> V_194 = V_4 -> V_65 . V_68 ;
break;
case V_115 :
F_25 ( V_4 ) ;
break;
case V_132 :
V_4 -> V_184 = false ;
V_4 -> V_140 = false ;
F_24 ( V_4 ) ;
case V_108 :
V_4 -> V_74 = false ;
F_6 ( L_34 ) ;
if ( V_4 -> V_38 )
V_4 -> V_70 = V_203 ;
else
V_4 -> V_70 = V_186 ;
return - V_51 ;
case V_134 :
return F_23 ( V_4 ) ;
case V_133 :
return F_46 ( V_4 ) ;
case V_116 :
return 0 ;
case V_112 :
case V_117 :
case V_118 :
case V_99 :
default:
break;
}
}
}
static int F_55 ( struct V_3 * V_4 )
{
int V_40 ;
while ( 1 ) {
V_40 = F_34 ( V_4 ) ;
if ( V_40 )
return V_40 ;
switch ( V_4 -> V_65 . type ) {
case V_131 :
V_4 -> V_140 = false ;
case V_109 :
case V_110 :
V_4 -> V_184 = V_4 -> V_65 . type != V_131 ;
if ( V_4 -> V_66 || V_4 -> V_65 . V_67 == 6 ||
V_4 -> V_65 . V_67 == 0 )
F_20 ( V_4 ) ;
if ( V_4 -> V_38 )
return 0 ;
break;
case V_111 :
if ( V_4 -> V_192 ) {
if ( V_4 -> V_66 ||
V_4 -> V_65 . V_67 == 6 ||
V_4 -> V_65 . V_67 == 0 )
F_20 ( V_4 ) ;
if ( V_4 -> V_38 )
return 0 ;
}
if ( V_4 -> V_65 . V_67 )
F_19 ( V_4 ) ;
break;
case V_119 :
F_48 ( V_4 ) ;
break;
case V_124 :
F_44 ( V_4 ) ;
break;
case V_127 :
F_47 ( V_4 ) ;
break;
case V_123 :
F_50 ( V_4 ) ;
break;
case V_129 :
F_49 ( V_4 ) ;
break;
case V_113 :
V_4 -> V_195 = V_4 -> V_65 . V_68 & ( V_188 - 1 ) ;
break;
case V_114 :
V_4 -> V_194 = V_4 -> V_65 . V_68 ;
break;
case V_115 :
F_25 ( V_4 ) ;
break;
case V_133 :
return F_46 ( V_4 ) ;
case V_134 :
return F_23 ( V_4 ) ;
case V_132 :
V_4 -> V_184 = false ;
V_4 -> V_140 = false ;
F_24 ( V_4 ) ;
V_4 -> V_74 = false ;
break;
case V_112 :
V_40 = F_54 ( V_4 ) ;
if ( V_40 )
return V_40 ;
if ( V_4 -> V_38 ) {
V_4 -> V_84 . type = 0 ;
return 0 ;
}
break;
case V_108 :
case V_116 :
case V_117 :
case V_118 :
case V_99 :
default:
break;
}
}
}
static int F_56 ( struct V_3 * V_4 )
{
int V_40 ;
F_6 ( L_41 ) ;
V_40 = F_55 ( V_4 ) ;
if ( V_40 )
return V_40 ;
V_4 -> V_70 = V_185 ;
V_4 -> V_192 = false ;
V_4 -> V_84 . V_158 = 0 ;
V_4 -> V_84 . V_159 = V_4 -> V_38 ;
F_45 ( L_40 , V_4 -> V_38 ) ;
return 0 ;
}
static int F_57 ( struct V_3 * V_4 )
{
const unsigned char * V_204 = V_4 -> V_60 + V_4 -> V_80 ;
T_3 V_2 ;
for ( V_2 = V_205 - 1 ; V_2 ; V_2 -- ) {
if ( V_2 > V_4 -> V_80 )
continue;
if ( ! memcmp ( V_204 - V_2 , V_206 , V_2 ) )
return V_2 ;
}
return 0 ;
}
static int F_58 ( struct V_3 * V_4 , int V_207 )
{
T_3 V_208 = V_205 - V_207 ;
const char * V_209 = V_206 ;
if ( V_208 > V_4 -> V_80 ||
memcmp ( V_4 -> V_60 , V_209 + V_207 , V_208 ) )
return 0 ;
return V_208 ;
}
static int F_59 ( struct V_3 * V_4 ,
int V_207 )
{
int V_208 , V_79 ;
V_4 -> V_36 += V_4 -> V_80 ;
V_4 -> V_80 = 0 ;
V_79 = F_28 ( V_4 ) ;
if ( V_79 )
return V_79 ;
V_208 = F_58 ( V_4 , V_207 ) ;
if ( ! V_208 )
return 0 ;
V_4 -> V_36 -= V_207 ;
V_4 -> V_88 = V_4 -> V_60 + V_208 ;
V_4 -> V_89 = V_4 -> V_80 - V_208 ;
memcpy ( V_4 -> V_90 , V_206 , V_205 ) ;
V_4 -> V_60 = V_4 -> V_90 ;
V_4 -> V_80 = V_205 ;
return 0 ;
}
static int F_60 ( struct V_3 * V_4 )
{
unsigned char * V_197 ;
int V_79 ;
F_6 ( L_42 ) ;
while ( 1 ) {
if ( ! V_4 -> V_80 ) {
V_79 = F_28 ( V_4 ) ;
if ( V_79 )
return V_79 ;
}
V_197 = F_61 ( V_4 -> V_60 , V_4 -> V_80 , V_206 ,
V_205 ) ;
if ( ! V_197 ) {
int V_207 ;
V_207 = F_57 ( V_4 ) ;
if ( V_207 ) {
V_79 = F_59 ( V_4 , V_207 ) ;
if ( V_79 )
return V_79 ;
} else {
V_4 -> V_36 += V_4 -> V_80 ;
V_4 -> V_80 = 0 ;
}
continue;
}
V_4 -> V_75 = V_197 - V_4 -> V_60 ;
return F_34 ( V_4 ) ;
}
}
static int F_62 ( struct V_3 * V_4 )
{
int V_40 ;
V_4 -> V_184 = false ;
V_4 -> V_140 = false ;
V_4 -> V_66 = 0 ;
V_4 -> V_38 = 0 ;
F_11 ( & V_4 -> V_31 ) ;
V_40 = F_60 ( V_4 ) ;
if ( V_40 )
return V_40 ;
V_4 -> V_70 = V_210 ;
V_40 = F_54 ( V_4 ) ;
if ( V_40 )
return V_40 ;
if ( V_4 -> V_38 ) {
V_4 -> V_84 . type = 0 ;
V_4 -> V_70 = V_185 ;
} else {
return F_56 ( V_4 ) ;
}
return 0 ;
}
static T_1 F_63 ( struct V_3 * V_4 )
{
T_1 V_211 = V_4 -> V_139 << 1 ;
if ( ! V_4 -> V_102 || ! V_4 -> V_21 )
goto V_155;
V_211 *= V_4 -> V_21 ;
V_211 /= V_4 -> V_102 ;
V_155:
return V_4 -> V_83 + V_211 ;
}
const struct V_212 * F_64 ( struct V_3 * V_4 )
{
int V_40 ;
do {
V_4 -> V_84 . type = V_213 ;
V_4 -> V_84 . V_177 = 0 ;
switch ( V_4 -> V_70 ) {
case V_71 :
V_40 = F_62 ( V_4 ) ;
break;
case V_210 :
V_4 -> V_66 = 0 ;
case V_173 :
V_40 = F_56 ( V_4 ) ;
break;
case V_185 :
V_40 = F_53 ( V_4 ) ;
break;
case V_198 :
V_40 = F_42 ( V_4 ) ;
if ( V_40 == - V_154 )
V_40 = F_53 ( V_4 ) ;
break;
case V_199 :
case V_183 :
V_40 = F_41 ( V_4 ) ;
break;
case V_201 :
V_4 -> V_70 = V_185 ;
V_40 = F_40 ( V_4 ) ;
if ( V_40 == - V_154 )
V_40 = F_52 ( V_4 ) ;
else if ( ! V_40 )
V_4 -> V_70 = V_201 ;
break;
case V_200 :
V_4 -> V_70 = V_185 ;
V_40 = F_40 ( V_4 ) ;
if ( V_40 == - V_154 )
V_40 = F_53 ( V_4 ) ;
break;
default:
V_40 = F_23 ( V_4 ) ;
break;
}
} while ( V_40 == - V_87 );
V_4 -> V_84 . V_40 = V_40 ? F_15 ( V_40 ) : 0 ;
V_4 -> V_84 . V_83 = V_4 -> V_83 ;
V_4 -> V_84 . V_214 = F_63 ( V_4 ) ;
V_4 -> V_84 . V_195 = V_4 -> V_195 ;
V_4 -> V_84 . V_151 = V_4 -> V_151 ;
if ( V_40 )
V_4 -> V_84 . V_158 = V_4 -> V_38 ;
return & V_4 -> V_84 ;
}
static bool F_65 ( unsigned char * V_60 , T_3 V_80 )
{
if ( V_80 < V_205 )
return false ;
return F_61 ( V_60 , V_205 , V_206 ,
V_205 ) ;
}
static bool F_66 ( unsigned char * * V_60 , T_3 * V_80 )
{
unsigned char * V_197 ;
V_197 = F_61 ( * V_60 , * V_80 , V_206 , V_205 ) ;
if ( V_197 ) {
* V_80 -= V_197 - * V_60 ;
* V_60 = V_197 ;
return true ;
}
return false ;
}
static bool F_67 ( unsigned char * * V_60 , T_3 * V_80 )
{
unsigned char * V_197 ;
if ( ! * V_80 )
return false ;
V_197 = F_61 ( * V_60 + 1 , * V_80 - 1 , V_206 , V_205 ) ;
if ( V_197 ) {
* V_80 -= V_197 - * V_60 ;
* V_60 = V_197 ;
return true ;
}
return false ;
}
static unsigned char * F_68 ( unsigned char * V_60 , T_3 V_80 )
{
const char * V_11 = V_206 ;
unsigned char * V_215 ;
T_3 V_216 ;
if ( V_80 < V_205 )
return NULL ;
V_216 = V_80 - V_205 + 1 ;
while ( 1 ) {
V_215 = F_69 ( V_60 , V_11 [ 0 ] , V_216 ) ;
if ( ! V_215 )
return NULL ;
if ( ! memcmp ( V_215 + 1 , V_11 + 1 , V_205 - 1 ) )
return V_215 ;
V_216 = V_215 - V_60 ;
if ( ! V_216 )
return NULL ;
}
}
static bool F_70 ( unsigned char * V_60 , T_3 V_80 , T_1 * V_217 )
{
struct V_64 V_65 ;
int V_79 ;
while ( V_80 ) {
V_79 = F_30 ( V_60 , V_80 , & V_65 ) ;
if ( V_79 <= 0 )
return false ;
if ( V_65 . type == V_124 ) {
* V_217 = V_65 . V_68 ;
return true ;
}
if ( V_65 . type == V_116 )
return false ;
V_60 += V_79 ;
V_80 -= V_79 ;
}
return false ;
}
static int F_71 ( T_1 V_218 , T_1 V_219 )
{
const T_1 V_220 = ( 1ULL << 55 ) ;
if ( V_218 == V_219 )
return 0 ;
if ( V_218 < V_219 ) {
if ( V_219 - V_218 < V_220 )
return - 1 ;
else
return 1 ;
} else {
if ( V_218 - V_219 < V_220 )
return 1 ;
else
return - 1 ;
}
}
static unsigned char * F_72 ( unsigned char * V_221 ,
T_3 V_222 ,
unsigned char * V_223 ,
T_3 V_224 )
{
T_1 V_225 , V_226 ;
unsigned char * V_215 ;
T_3 V_80 ;
V_215 = F_68 ( V_221 , V_222 ) ;
if ( ! V_215 )
return V_223 ;
V_80 = V_222 - ( V_215 - V_221 ) ;
if ( ! F_70 ( V_215 , V_80 , & V_225 ) ) {
V_222 -= V_80 ;
V_215 = F_68 ( V_221 , V_222 ) ;
if ( ! V_215 )
return V_223 ;
V_80 = V_222 - ( V_215 - V_221 ) ;
if ( ! F_70 ( V_215 , V_80 , & V_225 ) )
return V_223 ;
}
while ( 1 ) {
if ( F_70 ( V_223 , V_224 , & V_226 ) &&
F_71 ( V_225 , V_226 ) < 0 )
return V_223 ;
if ( ! F_67 ( & V_223 , & V_224 ) )
return V_223 + V_224 ;
}
}
unsigned char * F_73 ( unsigned char * V_221 , T_3 V_222 ,
unsigned char * V_223 , T_3 V_224 ,
bool V_227 )
{
unsigned char * V_228 ;
if ( ! F_66 ( & V_223 , & V_224 ) )
return V_223 + V_224 ;
if ( ! F_66 ( & V_221 , & V_222 ) )
return V_223 ;
if ( V_227 ) {
V_228 = F_72 ( V_221 , V_222 , V_223 , V_224 ) ;
if ( V_228 )
return V_228 ;
}
while ( V_224 < V_222 ) {
if ( ! F_67 ( & V_221 , & V_222 ) )
return V_223 ;
}
if ( V_224 > V_222 ) {
while ( ! F_65 ( V_223 + V_222 , V_224 - V_222 ) ) {
if ( ! F_67 ( & V_221 , & V_222 ) )
return V_223 ;
}
}
while ( 1 ) {
V_228 = F_61 ( V_221 , V_222 , V_223 , V_222 ) ;
if ( V_228 )
return V_223 + V_222 ;
if ( ! F_67 ( & V_221 , & V_222 ) )
return V_223 ;
while ( ! F_65 ( V_223 + V_222 , V_224 - V_222 ) ) {
if ( ! F_67 ( & V_221 , & V_222 ) )
return V_223 ;
}
}
}
