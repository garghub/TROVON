static inline bool F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
return true ;
case V_8 :
case V_9 :
case V_10 :
case V_11 :
return false ;
default:
return true ;
} ;
}
static T_1 F_2 ( T_1 V_12 )
{
int V_13 ;
for ( V_13 = 0 ; V_12 != 1 ; V_13 ++ )
V_12 >>= 1 ;
return V_12 << V_13 ;
}
static void F_3 ( struct V_14 * V_15 )
{
if ( V_15 -> V_16 == V_17 ) {
T_1 V_18 ;
V_18 = F_2 ( V_15 -> V_18 ) ;
V_15 -> V_19 = ~ ( V_18 - 1 ) ;
V_15 -> V_20 = V_18 ;
}
}
static T_1 F_4 ( T_1 V_21 , T_2 V_22 , T_2 V_23 )
{
if ( ! V_23 )
return 0 ;
return ( V_21 / V_23 ) * V_22 + ( ( V_21 % V_23 ) * V_22 ) / V_23 ;
}
struct V_14 * F_5 ( struct V_24 * V_25 )
{
struct V_14 * V_15 ;
if ( ! V_25 -> V_26 || ! V_25 -> V_27 )
return NULL ;
V_15 = F_6 ( sizeof( struct V_14 ) ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_26 = V_25 -> V_26 ;
V_15 -> V_27 = V_25 -> V_27 ;
V_15 -> V_28 = V_25 -> V_28 ;
V_15 -> V_29 = V_25 -> V_29 ;
V_15 -> V_30 = V_25 -> V_30 ;
V_15 -> V_31 = V_25 -> V_31 ;
V_15 -> V_18 = V_25 -> V_18 ;
V_15 -> V_16 = V_25 -> V_16 ;
V_15 -> V_32 = V_25 -> V_32 ;
V_15 -> V_33 = V_25 -> V_32 ;
F_3 ( V_15 ) ;
V_15 -> V_34 = V_25 -> V_35 ;
V_15 -> V_36 = ( 1 << V_15 -> V_34 ) - 1 ;
V_15 -> V_37 = V_25 -> V_37 ;
V_15 -> V_38 = V_25 -> V_38 ;
if ( ! V_15 -> V_37 )
V_15 -> V_38 = 0 ;
if ( V_15 -> V_38 ) {
if ( ! ( V_15 -> V_37 % V_15 -> V_38 ) )
V_15 -> V_39 = V_15 -> V_37 /
V_15 -> V_38 ;
V_15 -> V_40 = F_4 ( 2 << V_15 -> V_34 ,
V_15 -> V_37 ,
V_15 -> V_38 ) ;
}
if ( V_15 -> V_40 < 0x100 )
V_15 -> V_40 = 0x100 ;
F_7 ( L_1 , V_15 -> V_34 ) ;
F_7 ( L_2 , V_15 -> V_37 ) ;
F_7 ( L_3 , V_15 -> V_38 ) ;
F_7 ( L_4 , V_15 -> V_39 ) ;
F_7 ( L_5 , V_15 -> V_40 ) ;
return V_15 ;
}
static void F_8 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = V_42 -> V_44 ;
V_42 -> V_44 = V_44 -> V_45 ;
if ( ! V_42 -> V_46 )
V_42 -> V_46 = V_44 ;
else
free ( V_44 ) ;
}
static T_1 F_9 ( struct V_41 * V_42 )
{
if ( ! V_42 -> V_47 ) {
if ( ! V_42 -> V_44 )
return 0 ;
F_8 ( V_42 ) ;
if ( ! V_42 -> V_44 )
return 0 ;
V_42 -> V_47 = V_48 ;
}
return V_42 -> V_44 -> V_49 [ -- V_42 -> V_47 ] ;
}
static int F_10 ( struct V_41 * V_42 )
{
struct V_43 * V_44 ;
if ( V_42 -> V_46 ) {
V_44 = V_42 -> V_46 ;
V_42 -> V_46 = NULL ;
} else {
V_44 = malloc ( sizeof( struct V_43 ) ) ;
if ( ! V_44 )
return - V_50 ;
}
V_44 -> V_45 = V_42 -> V_44 ;
V_42 -> V_44 = V_44 ;
V_42 -> V_47 = 0 ;
return 0 ;
}
static int F_11 ( struct V_41 * V_42 , T_1 V_49 )
{
int V_51 ;
if ( ! V_42 -> V_44 || V_42 -> V_47 == V_48 ) {
V_51 = F_10 ( V_42 ) ;
if ( V_51 )
return V_51 ;
}
V_42 -> V_44 -> V_49 [ V_42 -> V_47 ++ ] = V_49 ;
return 0 ;
}
static void F_12 ( struct V_41 * V_42 )
{
while ( V_42 -> V_44 )
F_8 ( V_42 ) ;
V_42 -> V_47 = 0 ;
}
static void F_13 ( struct V_41 * V_42 )
{
F_12 ( V_42 ) ;
F_14 ( & V_42 -> V_44 ) ;
F_14 ( & V_42 -> V_46 ) ;
}
void F_15 ( struct V_14 * V_15 )
{
F_13 ( & V_15 -> V_42 ) ;
free ( V_15 ) ;
}
static int F_16 ( int V_52 )
{
switch ( V_52 ) {
case - V_50 :
return V_53 ;
case - V_54 :
return V_55 ;
case - V_56 :
return V_57 ;
case - V_58 :
return V_59 ;
case - V_60 :
return V_61 ;
case - V_62 :
return V_63 ;
case - V_64 :
return V_65 ;
case - V_66 :
return V_67 ;
case - V_68 :
return V_69 ;
default:
return V_70 ;
}
}
int F_17 ( int V_52 , char * V_71 , T_3 V_72 )
{
if ( V_52 < 1 || V_52 >= V_73 )
V_52 = V_70 ;
F_18 ( V_71 , V_74 [ V_52 ] , V_72 ) ;
return 0 ;
}
static T_1 F_19 ( const struct V_75 * V_76 ,
T_1 V_77 )
{
T_1 V_49 ;
switch ( V_76 -> V_78 ) {
case 1 :
V_49 = ( V_77 & ( T_1 ) 0xffffffffffff0000ULL ) |
V_76 -> V_79 ;
break;
case 2 :
V_49 = ( V_77 & ( T_1 ) 0xffffffff00000000ULL ) |
V_76 -> V_79 ;
break;
case 3 :
V_49 = V_76 -> V_79 ;
if ( V_49 & ( T_1 ) 0x800000000000ULL )
V_49 |= ( T_1 ) 0xffff000000000000ULL ;
break;
case 4 :
V_49 = ( V_77 & ( T_1 ) 0xffff000000000000ULL ) |
V_76 -> V_79 ;
break;
case 6 :
V_49 = V_76 -> V_79 ;
break;
default:
return 0 ;
}
return V_49 ;
}
static inline void F_20 ( struct V_14 * V_15 )
{
V_15 -> V_77 = F_19 ( & V_15 -> V_76 , V_15 -> V_77 ) ;
V_15 -> V_80 = true ;
}
static inline void F_21 ( struct V_14 * V_15 )
{
F_20 ( V_15 ) ;
V_15 -> V_49 = V_15 -> V_77 ;
}
static void F_22 ( struct V_14 * V_15 )
{
F_23 ( & V_15 -> V_76 , V_15 -> V_81 , V_15 -> V_47 ,
V_15 -> V_71 ) ;
}
static int F_24 ( struct V_14 * V_15 )
{
F_7 ( L_6 ) ;
V_15 -> V_2 = V_3 ;
return - V_54 ;
}
static inline void F_25 ( struct V_14 * V_15 )
{
V_15 -> V_82 = 0 ;
}
static inline void F_26 ( struct V_14 * V_15 )
{
V_15 -> V_82 = V_15 -> V_76 . V_79 & V_83 ;
}
static int F_27 ( struct V_14 * V_15 )
{
F_25 ( V_15 ) ;
V_15 -> V_84 = false ;
V_15 -> V_81 = 1 ;
V_15 -> V_85 = 1 ;
F_22 ( V_15 ) ;
if ( V_15 -> V_2 != V_3 ) {
F_7 ( L_7 ) ;
V_15 -> V_2 = V_86 ;
}
return - V_56 ;
}
static int F_28 ( struct V_14 * V_15 )
{
struct V_87 V_88 = { . V_71 = 0 , } ;
int V_89 ;
V_15 -> V_85 = 0 ;
F_7 ( L_8 ) ;
V_89 = V_15 -> V_26 ( & V_88 , V_15 -> V_29 ) ;
if ( V_89 )
return V_89 ;
V_15 -> V_71 = V_88 . V_71 ;
V_15 -> V_90 = V_88 . V_90 ;
if ( ! V_15 -> V_90 ) {
F_7 ( L_9 ) ;
return - V_58 ;
}
if ( ! V_88 . V_91 ) {
V_15 -> V_49 = 0 ;
V_15 -> V_2 = V_3 ;
V_15 -> V_92 = V_88 . V_92 ;
V_15 -> V_93 = 0 ;
V_15 -> V_84 = false ;
V_15 -> V_94 . V_95 = V_88 . V_95 ;
F_7 ( L_10 V_96 L_11 ,
V_15 -> V_92 ) ;
return - V_97 ;
}
return 0 ;
}
static int F_29 ( struct V_14 * V_15 )
{
if ( ! V_15 -> V_98 )
return F_28 ( V_15 ) ;
V_15 -> V_71 = V_15 -> V_98 ;
V_15 -> V_90 = V_15 -> V_99 ;
V_15 -> V_98 = 0 ;
V_15 -> V_99 = 0 ;
return 0 ;
}
static int F_30 ( struct V_14 * V_15 )
{
unsigned char * V_71 = V_15 -> V_100 ;
T_3 V_101 , V_90 , V_22 ;
int V_89 ;
V_101 = V_15 -> V_90 ;
V_90 = V_15 -> V_90 ;
memcpy ( V_71 , V_15 -> V_71 , V_90 ) ;
V_89 = F_28 ( V_15 ) ;
if ( V_89 ) {
V_15 -> V_47 += V_101 ;
return V_89 < 0 ? V_89 : - V_102 ;
}
V_22 = V_103 - V_90 ;
if ( V_22 > V_15 -> V_90 )
V_22 = V_15 -> V_90 ;
memcpy ( V_71 + V_90 , V_15 -> V_71 , V_22 ) ;
V_90 += V_22 ;
V_89 = F_31 ( V_71 , V_90 , & V_15 -> V_76 ) ;
if ( V_89 < ( int ) V_101 ) {
V_15 -> V_98 = V_15 -> V_71 ;
V_15 -> V_99 = V_15 -> V_90 ;
V_15 -> V_71 = V_71 ;
V_15 -> V_90 = V_101 ;
return F_27 ( V_15 ) ;
}
V_15 -> V_98 = V_15 -> V_71 + ( V_89 - V_101 ) ;
V_15 -> V_99 = V_15 -> V_90 - ( V_89 - V_101 ) ;
V_15 -> V_71 = V_71 ;
V_15 -> V_90 = V_89 ;
return V_89 ;
}
static int F_32 ( struct V_14 * V_15 ,
T_4 V_104 , void * V_29 )
{
struct V_105 V_106 ;
const unsigned char * V_71 = V_15 -> V_71 ;
T_3 V_90 = V_15 -> V_90 ;
int V_89 ;
V_106 . V_15 = V_15 ;
V_106 . V_47 = V_15 -> V_47 ;
V_106 . V_81 = V_15 -> V_85 ;
V_106 . V_107 = V_15 -> V_107 ;
V_106 . V_29 = V_29 ;
while ( 1 ) {
do {
V_106 . V_47 += V_106 . V_81 ;
V_71 += V_106 . V_81 ;
V_90 -= V_106 . V_81 ;
if ( ! V_90 )
return V_108 ;
V_89 = F_31 ( V_71 , V_90 , & V_106 . V_76 ) ;
if ( ! V_89 )
return V_108 ;
if ( V_89 < 0 )
return V_89 ;
V_106 . V_81 = V_89 ;
} while ( V_106 . V_76 . type == V_109 );
V_89 = V_104 ( & V_106 ) ;
if ( V_89 )
return 0 ;
V_106 . V_107 = V_106 . V_76 . type ;
}
}
static void F_33 ( T_2 V_110 , int V_34 ,
T_2 * V_111 )
{
T_2 V_112 = 1U << ( 16 - V_34 ) ;
T_2 V_113 = ~ ( V_112 - 1 ) ;
* V_111 |= V_110 & V_113 ;
if ( * V_111 >= V_110 ) {
* V_111 -= V_112 ;
* V_111 &= 0xff ;
}
}
static int F_34 ( struct V_105 * V_106 )
{
struct V_14 * V_15 = V_106 -> V_15 ;
struct V_114 * V_29 = V_106 -> V_29 ;
T_1 V_93 ;
double V_115 ;
unsigned int V_116 ;
T_2 V_110 , V_117 , V_118 , V_119 , V_120 ;
switch ( V_106 -> V_76 . type ) {
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_109 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
return 0 ;
case V_134 :
if ( ! V_29 -> V_84 )
return 0 ;
V_110 = V_106 -> V_76 . V_79 ;
if ( V_15 -> V_34 > 8 && V_29 -> V_135 ) {
V_29 -> V_135 = false ;
F_33 ( V_110 , V_15 -> V_34 ,
& V_29 -> V_111 ) ;
}
if ( V_110 > V_29 -> V_111 )
V_117 = V_110 - V_29 -> V_111 ;
else
V_117 = V_110 + 256 - V_29 -> V_111 ;
V_29 -> V_136 += V_117 << V_15 -> V_34 ;
V_29 -> V_111 = V_110 ;
if ( V_15 -> V_39 ) {
V_93 = V_29 -> V_137 +
V_29 -> V_136 * V_15 -> V_39 ;
} else {
V_93 = V_29 -> V_137 +
F_4 ( V_29 -> V_136 ,
V_15 -> V_37 ,
V_15 -> V_38 ) ;
}
if ( V_93 < V_29 -> V_93 )
return 1 ;
if ( V_106 -> V_107 != V_138 ) {
V_29 -> V_93 = V_93 ;
return 0 ;
}
break;
case V_139 :
if ( V_29 -> V_140 )
return 1 ;
V_93 = V_106 -> V_76 . V_79 |
( V_29 -> V_93 & ( 0xffULL << 56 ) ) ;
if ( V_29 -> V_140 && V_93 < V_29 -> V_93 &&
V_29 -> V_93 - V_93 < V_15 -> V_40 )
return 1 ;
if ( V_93 < V_29 -> V_93 )
V_93 += ( 1ULL << 56 ) ;
if ( V_106 -> V_107 != V_138 ) {
if ( V_29 -> V_140 )
return 1 ;
V_29 -> V_141 = V_93 ;
V_29 -> V_93 = V_93 ;
return 0 ;
}
break;
case V_142 :
if ( V_29 -> V_140 )
return 1 ;
if ( ! V_15 -> V_38 )
return 0 ;
V_118 = V_106 -> V_76 . V_79 ;
V_119 = V_106 -> V_76 . V_78 ;
V_120 = V_118 & V_15 -> V_36 ;
V_29 -> V_111 = ( V_118 >> V_15 -> V_34 ) & 0xff ;
V_29 -> V_137 = V_29 -> V_141 - V_119 ;
if ( V_15 -> V_39 ) {
V_29 -> V_137 -= V_120 * V_15 -> V_39 ;
} else {
V_29 -> V_137 -=
F_4 ( V_120 , V_15 -> V_37 ,
V_15 -> V_38 ) ;
}
V_29 -> V_136 = 0 ;
V_29 -> V_84 = true ;
V_29 -> V_135 = true ;
return 0 ;
case V_138 :
V_29 -> V_143 += V_106 -> V_76 . V_79 ;
return 0 ;
case V_144 :
V_116 = V_106 -> V_76 . V_79 ;
if ( V_29 -> V_116 && V_29 -> V_116 != V_116 )
return 1 ;
V_29 -> V_116 = V_116 ;
V_29 -> V_145 = V_15 -> V_33 / V_116 ;
return 0 ;
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
default:
return 1 ;
}
if ( ! V_29 -> V_116 && V_15 -> V_116 ) {
V_29 -> V_116 = V_15 -> V_116 ;
V_29 -> V_145 = V_15 -> V_145 ;
}
if ( ! V_29 -> V_143 )
return 1 ;
V_115 = ( double ) ( V_93 - V_15 -> V_93 ) / V_29 -> V_143 ;
if ( V_29 -> V_116 && V_115 > V_29 -> V_145 &&
V_115 / V_29 -> V_145 > 1.25 ) {
F_7 ( L_12 V_155 L_11 ,
V_115 , V_29 -> V_145 , V_106 -> V_47 ) ;
return 1 ;
}
V_15 -> V_156 = V_115 ;
V_15 -> V_157 = true ;
if ( V_29 -> V_116 ) {
F_7 ( L_13 V_155 L_11 ,
V_115 , V_29 -> V_145 , V_106 -> V_47 ) ;
} else {
F_7 ( L_14 V_155 L_11 ,
V_115 , V_106 -> V_47 ) ;
}
return 1 ;
}
static void F_35 ( struct V_14 * V_15 ,
bool V_140 )
{
struct V_114 V_29 = {
. V_143 = 0 ,
. V_116 = 0 ,
. V_111 = V_15 -> V_111 ,
. V_137 = V_15 -> V_137 ,
. V_136 = V_15 -> V_136 ,
. V_141 = V_15 -> V_141 ,
. V_93 = V_15 -> V_93 ,
. V_84 = V_15 -> V_84 ,
. V_135 = V_15 -> V_135 ,
. V_140 = V_140 ,
. V_145 = 0 ,
} ;
if ( ! V_140 )
return;
F_32 ( V_15 , F_34 , & V_29 ) ;
}
static int F_36 ( struct V_14 * V_15 )
{
int V_89 ;
V_15 -> V_107 = V_15 -> V_76 . type ;
do {
V_15 -> V_47 += V_15 -> V_85 ;
V_15 -> V_71 += V_15 -> V_85 ;
V_15 -> V_90 -= V_15 -> V_85 ;
if ( ! V_15 -> V_90 ) {
V_89 = F_29 ( V_15 ) ;
if ( V_89 )
return V_89 ;
}
V_89 = F_31 ( V_15 -> V_71 , V_15 -> V_90 ,
& V_15 -> V_76 ) ;
if ( V_89 == V_108 &&
V_15 -> V_90 < V_103 && ! V_15 -> V_98 ) {
V_89 = F_30 ( V_15 ) ;
if ( V_89 < 0 )
return V_89 ;
}
if ( V_89 <= 0 )
return F_27 ( V_15 ) ;
V_15 -> V_81 = V_89 ;
V_15 -> V_85 = V_89 ;
F_22 ( V_15 ) ;
} while ( V_15 -> V_76 . type == V_109 );
return 0 ;
}
static T_1 F_37 ( struct V_14 * V_15 )
{
T_1 V_93 , V_158 ;
V_93 = V_15 -> V_93 + V_15 -> V_159 ;
V_158 = V_93 & V_15 -> V_19 ;
if ( V_15 -> V_160 ) {
if ( V_158 != V_15 -> V_161 )
return 1 ;
} else {
V_93 += 1 ;
V_158 = V_93 & V_15 -> V_19 ;
if ( V_158 != V_15 -> V_161 ) {
V_15 -> V_161 = V_158 ;
V_15 -> V_160 = true ;
}
}
return V_15 -> V_20 - ( V_93 - V_158 ) ;
}
static T_1 F_38 ( struct V_14 * V_15 )
{
switch ( V_15 -> V_16 ) {
case V_162 :
return V_15 -> V_18 - V_15 -> V_163 ;
case V_17 :
return F_37 ( V_15 ) ;
case V_164 :
case V_165 :
default:
return 0 ;
}
}
static void F_39 ( struct V_14 * V_15 )
{
T_1 V_93 , V_158 ;
switch ( V_15 -> V_16 ) {
case V_162 :
V_15 -> V_163 = 0 ;
break;
case V_17 :
V_93 = V_15 -> V_93 + V_15 -> V_159 ;
V_158 = V_93 & V_15 -> V_19 ;
V_15 -> V_161 = V_158 ;
break;
case V_164 :
case V_165 :
default:
break;
}
V_15 -> V_94 . type |= V_166 ;
}
static int F_40 ( struct V_14 * V_15 ,
struct V_167 * V_167 , T_1 V_49 )
{
T_1 V_168 , V_169 = 0 ;
int V_51 ;
if ( ! V_15 -> V_170 )
V_15 -> V_170 = true ;
V_168 = F_38 ( V_15 ) ;
V_51 = V_15 -> V_27 ( V_167 , & V_169 , & V_15 -> V_49 , V_49 ,
V_168 , V_15 -> V_29 ) ;
V_15 -> V_171 += V_169 ;
V_15 -> V_159 += V_169 ;
V_15 -> V_172 += V_169 ;
V_15 -> V_163 += V_169 ;
if ( V_51 ) {
V_15 -> V_173 = 0 ;
V_15 -> V_2 = V_174 ;
F_41 ( L_15 ,
V_15 -> V_49 ) ;
if ( V_51 == - V_62 )
return - V_97 ;
return - V_60 ;
}
if ( V_49 && V_15 -> V_49 == V_49 ) {
V_51 = - V_175 ;
goto V_176;
}
if ( V_168 && V_169 >= V_168 )
F_39 ( V_15 ) ;
if ( V_167 -> V_177 == V_178 ) {
V_15 -> V_94 . type = V_166 ;
V_15 -> V_94 . V_179 = V_15 -> V_49 ;
V_15 -> V_94 . V_180 = 0 ;
V_15 -> V_49 += V_167 -> V_181 ;
V_51 = V_182 ;
goto V_176;
}
if ( V_167 -> V_183 == V_184 ) {
if ( V_167 -> V_177 != V_185 ||
V_167 -> V_186 ) {
V_51 = F_11 ( & V_15 -> V_42 , V_15 -> V_49 +
V_167 -> V_181 ) ;
if ( V_51 )
goto V_176;
}
} else if ( V_167 -> V_183 == V_187 ) {
V_15 -> V_188 = F_9 ( & V_15 -> V_42 ) ;
}
if ( V_167 -> V_177 == V_185 ) {
int V_189 = V_15 -> V_173 ++ ;
V_15 -> V_94 . V_179 = V_15 -> V_49 ;
V_15 -> V_49 += V_167 -> V_181 +
V_167 -> V_186 ;
V_15 -> V_94 . V_180 = V_15 -> V_49 ;
V_51 = V_182 ;
if ( V_189 ) {
if ( V_189 == 1 ) {
V_15 -> V_190 = V_15 -> V_94 . V_180 ;
V_15 -> V_191 = 1 ;
V_15 -> V_192 = 1 ;
} else if ( V_189 > V_193 ||
V_15 -> V_94 . V_180 == V_15 -> V_190 ) {
F_41 ( L_16 ,
V_15 -> V_94 . V_180 ) ;
V_15 -> V_2 = V_5 ;
V_51 = - V_68 ;
goto V_176;
} else if ( ! -- V_15 -> V_192 ) {
V_15 -> V_191 += 1 ;
V_15 -> V_192 = V_15 -> V_191 ;
V_15 -> V_190 = V_15 -> V_94 . V_180 ;
}
}
goto V_194;
}
V_176:
V_15 -> V_173 = 0 ;
V_194:
V_15 -> V_94 . V_195 = V_167 -> V_183 ;
V_15 -> V_94 . V_196 = V_167 -> V_181 ;
memcpy ( V_15 -> V_94 . V_197 , V_167 -> V_71 ,
V_198 ) ;
if ( V_15 -> V_82 & V_83 )
V_15 -> V_94 . V_199 |= V_83 ;
return V_51 ;
}
static bool F_42 ( struct V_14 * V_15 )
{
bool V_89 = false ;
if ( V_15 -> V_200 ) {
V_15 -> V_200 = false ;
V_15 -> V_82 = V_15 -> V_201 ;
V_15 -> V_94 . type = V_202 ;
V_15 -> V_94 . V_179 = V_15 -> V_49 ;
V_15 -> V_94 . V_180 = 0 ;
V_15 -> V_94 . V_199 = V_15 -> V_201 ;
return true ;
}
if ( V_15 -> V_203 ) {
V_15 -> V_203 = false ;
V_15 -> V_94 . type = V_204 ;
V_15 -> V_94 . V_199 |= V_205 ;
V_15 -> V_94 . V_179 = V_15 -> V_49 ;
V_15 -> V_94 . V_180 = 0 ;
V_15 -> V_94 . V_206 = V_15 -> V_207 ;
return true ;
}
if ( V_15 -> V_208 ) {
V_15 -> V_208 = false ;
V_15 -> V_94 . type = V_209 ;
V_15 -> V_94 . V_179 = V_15 -> V_49 ;
V_15 -> V_94 . V_180 = 0 ;
V_15 -> V_94 . V_210 = V_15 -> V_211 ;
V_89 = true ;
}
if ( V_15 -> V_212 ) {
V_15 -> V_212 = false ;
V_15 -> V_94 . type |= V_213 ;
V_15 -> V_94 . type &= ~ V_214 ;
V_15 -> V_94 . V_179 = V_15 -> V_49 ;
V_15 -> V_94 . V_180 = 0 ;
V_15 -> V_94 . V_215 = V_15 -> V_216 ;
V_89 = true ;
}
if ( V_15 -> V_217 ) {
V_15 -> V_217 = false ;
V_15 -> V_94 . type |= V_218 ;
V_15 -> V_94 . type &= ~ V_214 ;
V_15 -> V_94 . V_199 |= V_205 ;
V_15 -> V_94 . V_179 = V_15 -> V_49 ;
V_15 -> V_94 . V_180 = 0 ;
V_89 = true ;
}
return V_89 ;
}
static int F_43 ( struct V_14 * V_15 )
{
struct V_167 V_167 ;
T_1 V_49 ;
int V_51 ;
V_49 = V_15 -> V_77 ;
while ( 1 ) {
V_51 = F_40 ( V_15 , & V_167 , V_49 ) ;
if ( V_51 == V_182 )
return 0 ;
if ( V_51 == - V_175 ) {
if ( F_42 ( V_15 ) )
return 0 ;
return V_51 ;
}
V_15 -> V_200 = false ;
if ( V_51 )
return V_51 ;
if ( V_167 . V_177 == V_219 ) {
F_41 ( L_17 ,
V_15 -> V_49 ) ;
V_15 -> V_2 = V_5 ;
return - V_62 ;
}
if ( V_167 . V_177 == V_220 ) {
F_41 ( L_18 ,
V_15 -> V_49 ) ;
V_15 -> V_2 = V_5 ;
return - V_62 ;
}
F_24 ( V_15 ) ;
}
}
static int F_44 ( struct V_14 * V_15 )
{
struct V_167 V_167 ;
int V_51 ;
V_51 = F_40 ( V_15 , & V_167 , 0 ) ;
if ( V_51 == V_182 &&
V_15 -> V_28 &&
V_15 -> V_2 == V_9 &&
( V_15 -> V_94 . type & V_214 ) &&
V_15 -> V_28 ( V_15 -> V_94 . V_180 , V_15 -> V_29 ) ) {
V_15 -> V_173 = 0 ;
V_15 -> V_221 = false ;
V_15 -> V_160 = false ;
V_15 -> V_2 = V_6 ;
V_15 -> V_94 . V_180 = 0 ;
return 0 ;
}
if ( V_51 == V_182 )
return 0 ;
if ( V_51 )
return V_51 ;
if ( V_167 . V_177 == V_219 ) {
if ( V_15 -> V_2 == V_9 ) {
V_15 -> V_221 = false ;
V_15 -> V_160 = false ;
V_15 -> V_2 = V_6 ;
V_15 -> V_94 . V_179 = V_15 -> V_49 ;
V_15 -> V_94 . V_180 = 0 ;
if ( V_15 -> V_76 . V_78 != 0 )
V_15 -> V_49 = V_15 -> V_77 ;
} else {
V_15 -> V_2 = V_6 ;
V_15 -> V_94 . V_179 = V_15 -> V_49 ;
if ( V_15 -> V_76 . V_78 == 0 ) {
V_15 -> V_94 . V_180 = 0 ;
} else {
V_15 -> V_94 . V_180 = V_15 -> V_77 ;
V_15 -> V_49 = V_15 -> V_77 ;
}
}
return 0 ;
}
if ( V_167 . V_177 == V_220 ) {
T_1 V_180 = V_15 -> V_49 + V_167 . V_181 +
V_167 . V_186 ;
if ( V_15 -> V_28 &&
V_15 -> V_2 == V_9 &&
V_15 -> V_28 ( V_180 , V_15 -> V_29 ) ) {
V_15 -> V_221 = false ;
V_15 -> V_160 = false ;
V_15 -> V_2 = V_6 ;
V_15 -> V_49 = V_180 ;
V_15 -> V_94 . V_179 = V_15 -> V_49 ;
V_15 -> V_94 . V_180 = 0 ;
return 0 ;
}
F_41 ( L_19 ,
V_15 -> V_49 ) ;
V_15 -> V_2 = V_5 ;
return - V_62 ;
}
return F_24 ( V_15 ) ;
}
static int F_45 ( struct V_14 * V_15 )
{
struct V_167 V_167 ;
int V_51 ;
while ( 1 ) {
V_51 = F_40 ( V_15 , & V_167 , 0 ) ;
if ( V_51 == V_182 )
return 0 ;
if ( V_51 )
return V_51 ;
if ( V_167 . V_183 == V_187 ) {
if ( ! V_15 -> V_30 ) {
F_41 ( L_20 ,
V_15 -> V_49 ) ;
V_15 -> V_2 = V_222 ;
return - V_62 ;
}
if ( ! V_15 -> V_188 ) {
F_41 ( L_21 ,
V_15 -> V_49 ) ;
V_15 -> V_2 = V_222 ;
return - V_62 ;
}
if ( ! ( V_15 -> V_223 . V_79 & V_224 ) ) {
F_41 ( L_22 ,
V_15 -> V_49 ) ;
V_15 -> V_2 = V_222 ;
return - V_62 ;
}
V_15 -> V_223 . V_78 -= 1 ;
if ( ! V_15 -> V_223 . V_78 )
V_15 -> V_2 = V_6 ;
V_15 -> V_223 . V_79 <<= 1 ;
V_15 -> V_94 . V_179 = V_15 -> V_49 ;
V_15 -> V_49 = V_15 -> V_188 ;
V_15 -> V_94 . V_180 = V_15 -> V_49 ;
return 0 ;
}
if ( V_167 . V_177 == V_219 ) {
V_51 = F_36 ( V_15 ) ;
if ( V_51 )
return V_51 ;
if ( V_15 -> V_76 . type != V_123 ||
V_15 -> V_76 . V_78 == 0 ) {
F_41 ( L_23 ,
V_15 -> V_49 ) ;
V_15 -> V_2 = V_222 ;
V_15 -> V_85 = 0 ;
return - V_62 ;
}
F_20 ( V_15 ) ;
V_15 -> V_94 . V_179 = V_15 -> V_49 ;
V_15 -> V_94 . V_180 = V_15 -> V_77 ;
V_15 -> V_49 = V_15 -> V_77 ;
return 0 ;
}
if ( V_167 . V_177 == V_220 ) {
V_15 -> V_223 . V_78 -= 1 ;
if ( ! V_15 -> V_223 . V_78 )
V_15 -> V_2 = V_6 ;
if ( V_15 -> V_223 . V_79 & V_224 ) {
V_15 -> V_223 . V_79 <<= 1 ;
V_15 -> V_94 . V_179 = V_15 -> V_49 ;
V_15 -> V_49 += V_167 . V_181 +
V_167 . V_186 ;
V_15 -> V_94 . V_180 = V_15 -> V_49 ;
return 0 ;
}
if ( V_15 -> V_94 . type & V_166 ) {
V_15 -> V_223 . V_79 <<= 1 ;
V_15 -> V_94 . type = V_166 ;
V_15 -> V_94 . V_179 = V_15 -> V_49 ;
V_15 -> V_94 . V_180 = 0 ;
V_15 -> V_49 += V_167 . V_181 ;
return 0 ;
}
V_15 -> V_49 += V_167 . V_181 ;
if ( ! V_15 -> V_223 . V_78 )
return - V_175 ;
V_15 -> V_223 . V_79 <<= 1 ;
continue;
}
return F_24 ( V_15 ) ;
}
}
static int F_46 ( struct V_14 * V_15 , bool * V_225 )
{
unsigned int V_201 ;
int V_51 ;
V_201 = V_15 -> V_76 . V_79 &
( V_83 | V_226 ) ;
V_51 = F_36 ( V_15 ) ;
if ( V_51 )
return V_51 ;
if ( V_15 -> V_76 . type == V_124 ) {
V_15 -> V_201 = V_201 ;
V_15 -> V_200 = true ;
if ( ! ( V_15 -> V_201 & V_226 ) )
* V_225 = true ;
} else {
F_41 ( L_24 ,
V_15 -> V_47 ) ;
F_26 ( V_15 ) ;
}
return 0 ;
}
static void F_47 ( struct V_14 * V_15 )
{
T_1 V_93 ;
V_15 -> V_84 = false ;
if ( V_15 -> V_92 ) {
V_93 = V_15 -> V_76 . V_79 |
( V_15 -> V_92 & ( 0xffULL << 56 ) ) ;
if ( V_93 < V_15 -> V_92 ) {
if ( V_15 -> V_92 - V_93 > ( 1ULL << 55 ) )
V_93 += ( 1ULL << 56 ) ;
} else {
if ( V_93 - V_15 -> V_92 > ( 1ULL << 55 ) )
V_93 -= ( 1ULL << 56 ) ;
}
V_15 -> V_141 = V_93 ;
V_15 -> V_93 = V_93 ;
V_15 -> V_92 = 0 ;
V_15 -> V_159 = 0 ;
} else if ( V_15 -> V_93 ) {
V_93 = V_15 -> V_76 . V_79 |
( V_15 -> V_93 & ( 0xffULL << 56 ) ) ;
V_15 -> V_141 = V_93 ;
if ( V_93 < V_15 -> V_93 &&
V_15 -> V_93 - V_93 < V_15 -> V_40 ) {
F_48 ( L_25 ,
V_93 ) ;
V_93 = V_15 -> V_93 ;
}
if ( V_93 < V_15 -> V_93 ) {
F_48 ( L_26 , V_93 ) ;
V_93 += ( 1ULL << 56 ) ;
V_15 -> V_141 = V_93 ;
}
V_15 -> V_93 = V_93 ;
V_15 -> V_159 = 0 ;
}
if ( V_15 -> V_107 == V_138 ) {
V_15 -> V_227 = V_15 -> V_93 ;
V_15 -> V_143 = 0 ;
V_15 -> V_157 = false ;
F_35 ( V_15 , false ) ;
}
F_48 ( L_27 , V_15 -> V_93 ) ;
}
static int F_49 ( struct V_14 * V_15 )
{
F_7 ( L_28 ) ;
F_25 ( V_15 ) ;
V_15 -> V_84 = false ;
V_15 -> V_116 = 0 ;
V_15 -> V_2 = V_5 ;
V_15 -> V_228 = true ;
return - V_64 ;
}
static void F_50 ( struct V_14 * V_15 )
{
T_2 V_118 = V_15 -> V_76 . V_79 ;
T_2 V_119 = V_15 -> V_76 . V_78 ;
T_2 V_120 = V_118 & V_15 -> V_36 ;
if ( ! V_15 -> V_38 )
return;
V_15 -> V_111 = ( V_118 >> V_15 -> V_34 ) & 0xff ;
V_15 -> V_137 = V_15 -> V_141 - V_119 ;
if ( V_15 -> V_39 ) {
V_15 -> V_137 -= V_120 * V_15 -> V_39 ;
} else {
V_15 -> V_137 -= F_4 ( V_120 ,
V_15 -> V_37 ,
V_15 -> V_38 ) ;
}
V_15 -> V_136 = 0 ;
V_15 -> V_84 = true ;
V_15 -> V_135 = true ;
F_7 ( L_29 V_155 L_30 ,
V_15 -> V_137 , V_15 -> V_111 , V_120 ) ;
}
static void F_51 ( struct V_14 * V_15 )
{
T_1 V_93 ;
T_2 V_110 , V_117 ;
if ( ! V_15 -> V_84 )
return;
V_110 = V_15 -> V_76 . V_79 ;
if ( V_15 -> V_34 > 8 && V_15 -> V_135 ) {
V_15 -> V_135 = false ;
F_33 ( V_110 , V_15 -> V_34 ,
& V_15 -> V_111 ) ;
}
if ( V_110 > V_15 -> V_111 )
V_117 = V_110 - V_15 -> V_111 ;
else
V_117 = V_110 + 256 - V_15 -> V_111 ;
V_15 -> V_136 += V_117 << V_15 -> V_34 ;
if ( V_15 -> V_39 ) {
V_93 = V_15 -> V_137 +
V_15 -> V_136 * V_15 -> V_39 ;
} else {
V_93 = V_15 -> V_137 +
F_4 ( V_15 -> V_136 ,
V_15 -> V_37 ,
V_15 -> V_38 ) ;
}
if ( V_93 < V_15 -> V_93 )
F_7 ( L_31 V_155 L_32 V_155 L_11 ,
V_93 , V_15 -> V_93 ) ;
else
V_15 -> V_93 = V_93 ;
V_15 -> V_159 = 0 ;
V_15 -> V_111 = V_110 ;
if ( V_15 -> V_107 == V_138 ) {
V_15 -> V_227 = V_15 -> V_93 ;
V_15 -> V_143 = 0 ;
V_15 -> V_157 = false ;
F_35 ( V_15 , true ) ;
}
}
static void F_52 ( struct V_14 * V_15 )
{
unsigned int V_116 = V_15 -> V_76 . V_79 & 0xff ;
V_15 -> V_229 = V_15 -> V_76 . V_79 ;
if ( V_15 -> V_116 == V_116 )
return;
V_15 -> V_116 = V_116 ;
V_15 -> V_145 = V_15 -> V_33 / V_116 ;
}
static void F_53 ( struct V_14 * V_15 )
{
T_1 V_93 = V_15 -> V_227 ;
V_15 -> V_230 = true ;
V_15 -> V_143 += V_15 -> V_76 . V_79 ;
if ( ! V_15 -> V_227 )
return;
if ( V_15 -> V_157 )
V_93 += V_15 -> V_143 * V_15 -> V_156 ;
else if ( V_15 -> V_116 )
V_93 += V_15 -> V_143 * V_15 -> V_145 ;
else
return;
if ( V_93 < V_15 -> V_93 )
F_7 ( L_33 V_155 L_32 V_155 L_11 ,
V_93 , V_15 -> V_93 ) ;
else
V_15 -> V_93 = V_93 ;
V_15 -> V_159 = 0 ;
}
static int F_54 ( struct V_14 * V_15 )
{
int V_51 ;
while ( 1 ) {
V_51 = F_36 ( V_15 ) ;
if ( V_51 )
return V_51 ;
switch ( V_15 -> V_76 . type ) {
case V_129 :
return 0 ;
case V_146 :
case V_122 :
case V_123 :
case V_121 :
case V_147 :
case V_154 :
case V_125 :
case V_132 :
case V_133 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
V_15 -> V_84 = false ;
F_7 ( L_34 ) ;
return - V_175 ;
case V_153 :
return F_49 ( V_15 ) ;
case V_139 :
F_47 ( V_15 ) ;
break;
case V_142 :
F_50 ( V_15 ) ;
break;
case V_144 :
F_52 ( V_15 ) ;
break;
case V_127 :
V_15 -> V_231 = V_15 -> V_76 . V_79 ;
break;
case V_126 :
V_15 -> V_232 = V_15 -> V_76 . V_79 & ( V_224 - 1 ) ;
break;
case V_124 :
V_15 -> V_221 = true ;
if ( V_15 -> V_76 . V_78 )
F_20 ( V_15 ) ;
break;
case V_128 :
F_26 ( V_15 ) ;
break;
case V_134 :
F_51 ( V_15 ) ;
if ( V_15 -> V_16 == V_165 )
V_15 -> V_94 . type |= V_166 ;
break;
case V_138 :
case V_130 :
case V_131 :
case V_109 :
default:
break;
}
}
}
static int F_55 ( struct V_14 * V_15 )
{
int V_51 ;
if ( V_15 -> V_82 & V_226 ) {
V_15 -> V_82 = 0 ;
V_15 -> V_94 . V_199 &= ~ V_83 ;
V_15 -> V_94 . V_199 |= V_226 ;
} else {
V_15 -> V_94 . V_199 |= V_233 ;
}
while ( 1 ) {
V_51 = F_36 ( V_15 ) ;
if ( V_51 )
return V_51 ;
switch ( V_15 -> V_76 . type ) {
case V_121 :
case V_124 :
case V_147 :
case V_125 :
case V_139 :
case V_142 :
case V_144 :
case V_128 :
case V_154 :
case V_129 :
case V_132 :
case V_133 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
F_7 ( L_35 ) ;
V_15 -> V_2 = V_222 ;
return - V_62 ;
case V_153 :
return F_49 ( V_15 ) ;
case V_146 :
V_15 -> V_94 . V_179 = V_15 -> V_49 ;
V_15 -> V_94 . V_180 = 0 ;
if ( V_15 -> V_76 . V_78 != 0 ) {
F_21 ( V_15 ) ;
F_7 ( L_36 V_155 L_11 ,
V_15 -> V_49 ) ;
}
V_15 -> V_221 = false ;
V_15 -> V_160 = false ;
return 0 ;
case V_122 :
V_15 -> V_221 = true ;
F_7 ( L_37 V_155 L_11 ,
V_15 -> V_49 ) ;
V_15 -> V_94 . V_179 = 0 ;
if ( V_15 -> V_76 . V_78 == 0 ) {
V_15 -> V_94 . V_180 = 0 ;
} else {
F_21 ( V_15 ) ;
V_15 -> V_94 . V_180 = V_15 -> V_49 ;
}
return 0 ;
case V_123 :
V_15 -> V_94 . V_179 = V_15 -> V_49 ;
if ( V_15 -> V_76 . V_78 == 0 ) {
V_15 -> V_94 . V_180 = 0 ;
} else {
F_21 ( V_15 ) ;
V_15 -> V_94 . V_180 = V_15 -> V_49 ;
}
return 0 ;
case V_126 :
V_15 -> V_232 = V_15 -> V_76 . V_79 & ( V_224 - 1 ) ;
break;
case V_134 :
F_51 ( V_15 ) ;
if ( V_15 -> V_16 == V_165 )
V_15 -> V_94 . type |= V_166 ;
break;
case V_138 :
F_53 ( V_15 ) ;
break;
case V_127 :
V_15 -> V_231 = V_15 -> V_76 . V_79 ;
break;
case V_130 :
case V_131 :
case V_109 :
break;
default:
return F_24 ( V_15 ) ;
}
}
}
static int F_56 ( struct V_14 * V_15 )
{
bool V_225 = false ;
int V_51 ;
while ( 1 ) {
V_51 = F_36 ( V_15 ) ;
if ( V_51 )
return V_51 ;
V_234:
switch ( V_15 -> V_76 . type ) {
case V_121 :
if ( ! V_15 -> V_76 . V_78 )
break;
V_15 -> V_223 = V_15 -> V_76 ;
V_15 -> V_2 = V_7 ;
V_51 = F_45 ( V_15 ) ;
if ( V_51 == - V_175 )
break;
return V_51 ;
case V_146 :
if ( V_15 -> V_76 . V_78 != 0 )
F_20 ( V_15 ) ;
V_15 -> V_2 = V_9 ;
return F_44 ( V_15 ) ;
case V_122 : {
V_15 -> V_221 = true ;
if ( V_15 -> V_76 . V_78 == 0 ) {
F_41 ( L_38 ,
V_15 -> V_47 ) ;
break;
}
F_21 ( V_15 ) ;
V_15 -> V_94 . V_179 = 0 ;
V_15 -> V_94 . V_180 = V_15 -> V_49 ;
return 0 ;
}
case V_153 :
return F_49 ( V_15 ) ;
case V_123 :
if ( V_15 -> V_76 . V_78 != 0 )
F_20 ( V_15 ) ;
V_15 -> V_2 = V_8 ;
return F_44 ( V_15 ) ;
case V_124 :
if ( V_15 -> V_76 . V_78 == 0 ) {
F_41 ( L_39 ,
V_15 -> V_47 ) ;
V_225 = false ;
break;
}
F_20 ( V_15 ) ;
if ( ! V_15 -> V_31 ) {
V_15 -> V_49 = V_15 -> V_77 ;
if ( F_42 ( V_15 ) )
return 0 ;
V_225 = false ;
break;
}
if ( V_15 -> V_208 )
V_225 = true ;
V_51 = F_43 ( V_15 ) ;
if ( V_51 != - V_175 ) {
if ( V_51 )
return V_51 ;
if ( V_225 )
V_15 -> V_2 =
V_11 ;
else
V_15 -> V_2 = V_10 ;
return 0 ;
}
if ( V_225 ) {
V_225 = false ;
break;
}
return F_55 ( V_15 ) ;
case V_147 :
V_15 -> V_221 = false ;
V_15 -> V_160 = false ;
F_25 ( V_15 ) ;
V_15 -> V_84 = false ;
break;
case V_125 :
V_15 -> V_77 = 0 ;
V_15 -> V_80 = true ;
F_12 ( & V_15 -> V_42 ) ;
V_51 = F_54 ( V_15 ) ;
if ( V_51 == - V_175 )
goto V_234;
if ( V_51 )
return V_51 ;
break;
case V_126 :
V_15 -> V_232 = V_15 -> V_76 . V_79 & ( V_224 - 1 ) ;
break;
case V_134 :
F_51 ( V_15 ) ;
if ( V_15 -> V_16 != V_165 )
break;
if ( ! V_15 -> V_170 )
break;
V_15 -> V_170 = false ;
if ( ! V_15 -> V_93 )
break;
V_15 -> V_94 . type = V_166 ;
V_15 -> V_94 . V_179 = V_15 -> V_49 ;
V_15 -> V_94 . V_180 = 0 ;
V_15 -> V_170 = false ;
return 0 ;
case V_139 :
F_47 ( V_15 ) ;
break;
case V_142 :
F_50 ( V_15 ) ;
break;
case V_138 :
F_53 ( V_15 ) ;
break;
case V_144 :
F_52 ( V_15 ) ;
if ( ! V_15 -> V_31 &&
V_15 -> V_116 != V_15 -> V_235 ) {
V_15 -> V_235 = V_15 -> V_116 ;
V_15 -> V_94 . type = V_236 ;
V_15 -> V_94 . V_179 = V_15 -> V_49 ;
V_15 -> V_94 . V_180 = 0 ;
V_15 -> V_94 . V_229 =
V_15 -> V_76 . V_79 ;
return 0 ;
}
break;
case V_127 :
V_15 -> V_231 = V_15 -> V_76 . V_79 ;
break;
case V_128 :
if ( ! V_15 -> V_221 ) {
F_26 ( V_15 ) ;
break;
}
V_51 = F_46 ( V_15 , & V_225 ) ;
if ( V_51 )
return V_51 ;
goto V_234;
case V_154 :
return F_24 ( V_15 ) ;
case V_129 :
case V_130 :
case V_131 :
case V_109 :
break;
case V_133 :
V_15 -> V_207 = V_15 -> V_76 . V_79 ;
V_51 = F_36 ( V_15 ) ;
if ( V_51 )
return V_51 ;
if ( V_15 -> V_76 . type == V_124 ) {
V_15 -> V_203 = true ;
V_225 = true ;
} else {
F_41 ( L_40 ,
V_15 -> V_47 ) ;
}
goto V_234;
case V_132 :
V_15 -> V_94 . type = V_204 ;
V_15 -> V_94 . V_179 = V_15 -> V_49 ;
V_15 -> V_94 . V_180 = 0 ;
V_15 -> V_94 . V_206 = V_15 -> V_76 . V_79 ;
return 0 ;
case V_150 :
V_15 -> V_211 = V_15 -> V_76 . V_79 ;
V_15 -> V_208 = true ;
break;
case V_151 :
if ( V_15 -> V_208 ) {
V_15 -> V_216 =
V_15 -> V_76 . V_79 ;
V_15 -> V_212 = true ;
break;
}
V_15 -> V_94 . type = V_213 ;
V_15 -> V_94 . V_179 = V_15 -> V_49 ;
V_15 -> V_94 . V_180 = 0 ;
V_15 -> V_94 . V_237 = V_15 -> V_76 . V_79 ;
return 0 ;
case V_149 :
V_51 = F_36 ( V_15 ) ;
if ( V_51 )
return V_51 ;
if ( V_15 -> V_76 . type == V_124 ) {
V_15 -> V_217 = true ;
V_225 = true ;
} else {
F_41 ( L_41 ,
V_15 -> V_47 ) ;
}
goto V_234;
case V_148 :
V_15 -> V_94 . type = V_218 ;
V_15 -> V_94 . V_179 = V_15 -> V_49 ;
V_15 -> V_94 . V_180 = 0 ;
return 0 ;
case V_152 :
V_15 -> V_94 . type = V_238 ;
V_15 -> V_94 . V_179 = V_15 -> V_49 ;
V_15 -> V_94 . V_180 = 0 ;
V_15 -> V_94 . V_237 = V_15 -> V_76 . V_79 ;
return 0 ;
default:
return F_24 ( V_15 ) ;
}
}
}
static inline bool F_57 ( struct V_14 * V_15 )
{
return V_15 -> V_76 . V_78 &&
( V_15 -> V_80 || V_15 -> V_76 . V_78 == 3 ||
V_15 -> V_76 . V_78 == 6 ) ;
}
static int F_58 ( struct V_14 * V_15 )
{
int V_51 ;
while ( 1 ) {
V_51 = F_36 ( V_15 ) ;
if ( V_51 )
return V_51 ;
switch ( V_15 -> V_76 . type ) {
case V_146 :
V_15 -> V_160 = false ;
V_239 ;
case V_122 :
case V_123 :
case V_132 :
case V_133 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
F_7 ( L_34 ) ;
return - V_62 ;
case V_124 :
V_15 -> V_221 = true ;
if ( F_57 ( V_15 ) ) {
T_1 V_240 = V_15 -> V_49 ;
F_21 ( V_15 ) ;
if ( V_240 )
F_48 ( L_42 ,
V_15 -> V_49 ) ;
}
break;
case V_134 :
F_51 ( V_15 ) ;
break;
case V_139 :
F_47 ( V_15 ) ;
break;
case V_142 :
F_50 ( V_15 ) ;
break;
case V_138 :
F_53 ( V_15 ) ;
break;
case V_144 :
F_52 ( V_15 ) ;
break;
case V_126 :
V_15 -> V_232 = V_15 -> V_76 . V_79 & ( V_224 - 1 ) ;
break;
case V_127 :
V_15 -> V_231 = V_15 -> V_76 . V_79 ;
break;
case V_128 :
F_26 ( V_15 ) ;
break;
case V_147 :
V_15 -> V_221 = false ;
V_15 -> V_160 = false ;
F_25 ( V_15 ) ;
V_239 ;
case V_121 :
V_15 -> V_84 = false ;
F_7 ( L_34 ) ;
if ( V_15 -> V_49 )
V_15 -> V_2 = V_241 ;
else
V_15 -> V_2 = V_222 ;
return - V_62 ;
case V_154 :
return F_24 ( V_15 ) ;
case V_153 :
return F_49 ( V_15 ) ;
case V_129 :
return 0 ;
case V_125 :
case V_130 :
case V_131 :
case V_109 :
default:
break;
}
}
}
static int F_59 ( struct V_14 * V_15 )
{
int V_51 ;
while ( 1 ) {
V_51 = F_36 ( V_15 ) ;
if ( V_51 )
return V_51 ;
switch ( V_15 -> V_76 . type ) {
case V_146 :
V_15 -> V_160 = false ;
V_239 ;
case V_122 :
case V_123 :
V_15 -> V_221 = V_15 -> V_76 . type != V_146 ;
if ( F_57 ( V_15 ) )
F_21 ( V_15 ) ;
if ( V_15 -> V_49 )
return 0 ;
break;
case V_124 :
if ( F_57 ( V_15 ) )
F_21 ( V_15 ) ;
if ( V_15 -> V_49 )
return 0 ;
break;
case V_134 :
F_51 ( V_15 ) ;
break;
case V_139 :
F_47 ( V_15 ) ;
break;
case V_142 :
F_50 ( V_15 ) ;
break;
case V_138 :
F_53 ( V_15 ) ;
break;
case V_144 :
F_52 ( V_15 ) ;
break;
case V_126 :
V_15 -> V_232 = V_15 -> V_76 . V_79 & ( V_224 - 1 ) ;
break;
case V_127 :
V_15 -> V_231 = V_15 -> V_76 . V_79 ;
break;
case V_128 :
F_26 ( V_15 ) ;
break;
case V_153 :
return F_49 ( V_15 ) ;
case V_154 :
return F_24 ( V_15 ) ;
case V_147 :
V_15 -> V_221 = false ;
V_15 -> V_160 = false ;
F_25 ( V_15 ) ;
V_15 -> V_84 = false ;
break;
case V_125 :
V_15 -> V_77 = 0 ;
V_15 -> V_80 = true ;
F_12 ( & V_15 -> V_42 ) ;
V_51 = F_58 ( V_15 ) ;
if ( V_51 )
return V_51 ;
if ( V_15 -> V_49 ) {
V_15 -> V_94 . type = 0 ;
return 0 ;
}
break;
case V_121 :
case V_129 :
case V_130 :
case V_131 :
case V_109 :
case V_132 :
case V_133 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
default:
break;
}
}
}
static int F_60 ( struct V_14 * V_15 )
{
int V_51 ;
V_15 -> V_200 = false ;
V_15 -> V_203 = false ;
V_15 -> V_208 = false ;
V_15 -> V_212 = false ;
V_15 -> V_217 = false ;
if ( ! V_15 -> V_31 ) {
V_15 -> V_2 = V_6 ;
V_15 -> V_228 = false ;
V_15 -> V_94 . type = 0 ;
return 0 ;
}
F_7 ( L_43 ) ;
V_51 = F_59 ( V_15 ) ;
if ( V_51 )
return V_51 ;
V_15 -> V_2 = V_6 ;
V_15 -> V_228 = false ;
V_15 -> V_94 . V_179 = 0 ;
V_15 -> V_94 . V_180 = V_15 -> V_49 ;
F_48 ( L_42 , V_15 -> V_49 ) ;
return 0 ;
}
static int F_61 ( struct V_14 * V_15 )
{
const unsigned char * V_242 = V_15 -> V_71 + V_15 -> V_90 ;
T_3 V_13 ;
for ( V_13 = V_243 - 1 ; V_13 ; V_13 -- ) {
if ( V_13 > V_15 -> V_90 )
continue;
if ( ! memcmp ( V_242 - V_13 , V_244 , V_13 ) )
return V_13 ;
}
return 0 ;
}
static int F_62 ( struct V_14 * V_15 , int V_245 )
{
T_3 V_246 = V_243 - V_245 ;
const char * V_247 = V_244 ;
if ( V_246 > V_15 -> V_90 ||
memcmp ( V_15 -> V_71 , V_247 + V_245 , V_246 ) )
return 0 ;
return V_246 ;
}
static int F_63 ( struct V_14 * V_15 ,
int V_245 )
{
int V_246 , V_89 ;
V_15 -> V_47 += V_15 -> V_90 ;
V_15 -> V_90 = 0 ;
V_89 = F_29 ( V_15 ) ;
if ( V_89 )
return V_89 ;
V_246 = F_62 ( V_15 , V_245 ) ;
if ( ! V_246 )
return 0 ;
V_15 -> V_47 -= V_245 ;
V_15 -> V_98 = V_15 -> V_71 + V_246 ;
V_15 -> V_99 = V_15 -> V_90 - V_246 ;
memcpy ( V_15 -> V_100 , V_244 , V_243 ) ;
V_15 -> V_71 = V_15 -> V_100 ;
V_15 -> V_90 = V_243 ;
return 0 ;
}
static int F_64 ( struct V_14 * V_15 )
{
unsigned char * V_234 ;
int V_89 ;
F_7 ( L_44 ) ;
while ( 1 ) {
if ( ! V_15 -> V_90 ) {
V_89 = F_29 ( V_15 ) ;
if ( V_89 )
return V_89 ;
}
V_234 = F_65 ( V_15 -> V_71 , V_15 -> V_90 , V_244 ,
V_243 ) ;
if ( ! V_234 ) {
int V_245 ;
V_245 = F_61 ( V_15 ) ;
if ( V_245 ) {
V_89 = F_63 ( V_15 , V_245 ) ;
if ( V_89 )
return V_89 ;
} else {
V_15 -> V_47 += V_15 -> V_90 ;
V_15 -> V_90 = 0 ;
}
continue;
}
V_15 -> V_85 = V_234 - V_15 -> V_71 ;
return F_36 ( V_15 ) ;
}
}
static int F_66 ( struct V_14 * V_15 )
{
int V_51 ;
V_15 -> V_221 = false ;
V_15 -> V_160 = false ;
V_15 -> V_80 = false ;
V_15 -> V_77 = 0 ;
V_15 -> V_49 = 0 ;
F_12 ( & V_15 -> V_42 ) ;
V_51 = F_64 ( V_15 ) ;
if ( V_51 )
return V_51 ;
V_15 -> V_80 = true ;
V_15 -> V_2 = V_4 ;
V_51 = F_58 ( V_15 ) ;
if ( V_51 )
return V_51 ;
if ( V_15 -> V_49 ) {
V_15 -> V_94 . type = 0 ;
V_15 -> V_2 = V_6 ;
} else {
return F_60 ( V_15 ) ;
}
return 0 ;
}
static T_1 F_67 ( struct V_14 * V_15 )
{
T_1 V_248 = V_15 -> V_172 << 1 ;
if ( ! V_15 -> V_116 || ! V_15 -> V_32 )
goto V_176;
V_248 *= V_15 -> V_32 ;
V_248 /= V_15 -> V_116 ;
V_176:
return V_15 -> V_249 + V_248 ;
}
const struct V_250 * F_68 ( struct V_14 * V_15 )
{
int V_51 ;
do {
V_15 -> V_94 . type = V_214 ;
V_15 -> V_94 . V_199 = 0 ;
switch ( V_15 -> V_2 ) {
case V_3 :
V_51 = F_66 ( V_15 ) ;
break;
case V_4 :
V_15 -> V_80 = false ;
V_15 -> V_77 = 0 ;
V_15 -> V_49 = 0 ;
V_239 ;
case V_5 :
V_51 = F_60 ( V_15 ) ;
break;
case V_6 :
V_51 = F_56 ( V_15 ) ;
break;
case V_7 :
V_51 = F_45 ( V_15 ) ;
if ( V_51 == - V_175 )
V_51 = F_56 ( V_15 ) ;
break;
case V_8 :
case V_9 :
V_51 = F_44 ( V_15 ) ;
break;
case V_10 :
V_15 -> V_2 = V_6 ;
V_51 = F_43 ( V_15 ) ;
if ( V_51 == - V_175 )
V_51 = F_55 ( V_15 ) ;
else if ( ! V_51 )
V_15 -> V_2 = V_10 ;
break;
case V_11 :
V_15 -> V_2 = V_6 ;
V_51 = F_43 ( V_15 ) ;
if ( V_51 == - V_175 )
V_51 = F_56 ( V_15 ) ;
break;
default:
V_51 = F_24 ( V_15 ) ;
break;
}
} while ( V_51 == - V_97 );
if ( V_51 ) {
V_15 -> V_94 . V_51 = F_16 ( V_51 ) ;
V_15 -> V_94 . V_179 = V_15 -> V_49 ;
V_15 -> V_249 = V_15 -> V_93 ;
V_15 -> V_172 = V_15 -> V_159 ;
} else {
V_15 -> V_94 . V_51 = 0 ;
if ( V_15 -> V_116 != V_15 -> V_235 && V_15 -> V_94 . type ) {
V_15 -> V_235 = V_15 -> V_116 ;
V_15 -> V_94 . type |= V_236 ;
V_15 -> V_94 . V_229 = V_15 -> V_229 ;
}
if ( F_1 ( V_15 -> V_2 ) ) {
V_15 -> V_249 = V_15 -> V_93 ;
V_15 -> V_172 = V_15 -> V_159 ;
}
}
V_15 -> V_94 . V_93 = V_15 -> V_249 ;
V_15 -> V_94 . V_251 = F_67 ( V_15 ) ;
V_15 -> V_94 . V_232 = V_15 -> V_232 ;
V_15 -> V_94 . V_171 = V_15 -> V_171 ;
return & V_15 -> V_94 ;
}
static bool F_69 ( unsigned char * V_71 , T_3 V_90 )
{
if ( V_90 < V_243 )
return false ;
return F_65 ( V_71 , V_243 , V_244 ,
V_243 ) ;
}
static bool F_70 ( unsigned char * * V_71 , T_3 * V_90 )
{
unsigned char * V_234 ;
V_234 = F_65 ( * V_71 , * V_90 , V_244 , V_243 ) ;
if ( V_234 ) {
* V_90 -= V_234 - * V_71 ;
* V_71 = V_234 ;
return true ;
}
return false ;
}
static bool F_71 ( unsigned char * * V_71 , T_3 * V_90 )
{
unsigned char * V_234 ;
if ( ! * V_90 )
return false ;
V_234 = F_65 ( * V_71 + 1 , * V_90 - 1 , V_244 , V_243 ) ;
if ( V_234 ) {
* V_90 -= V_234 - * V_71 ;
* V_71 = V_234 ;
return true ;
}
return false ;
}
static unsigned char * F_72 ( unsigned char * V_71 , T_3 V_90 )
{
const char * V_22 = V_244 ;
unsigned char * V_252 ;
T_3 V_253 ;
if ( V_90 < V_243 )
return NULL ;
V_253 = V_90 - V_243 + 1 ;
while ( 1 ) {
V_252 = F_73 ( V_71 , V_22 [ 0 ] , V_253 ) ;
if ( ! V_252 )
return NULL ;
if ( ! memcmp ( V_252 + 1 , V_22 + 1 , V_243 - 1 ) )
return V_252 ;
V_253 = V_252 - V_71 ;
if ( ! V_253 )
return NULL ;
}
}
static bool F_74 ( unsigned char * V_71 , T_3 V_90 , T_1 * V_254 )
{
struct V_75 V_76 ;
int V_89 ;
while ( V_90 ) {
V_89 = F_31 ( V_71 , V_90 , & V_76 ) ;
if ( V_89 <= 0 )
return false ;
if ( V_76 . type == V_139 ) {
* V_254 = V_76 . V_79 ;
return true ;
}
if ( V_76 . type == V_129 )
return false ;
V_71 += V_89 ;
V_90 -= V_89 ;
}
return false ;
}
static int F_75 ( T_1 V_255 , T_1 V_256 )
{
const T_1 V_257 = ( 1ULL << 55 ) ;
if ( V_255 == V_256 )
return 0 ;
if ( V_255 < V_256 ) {
if ( V_256 - V_255 < V_257 )
return - 1 ;
else
return 1 ;
} else {
if ( V_255 - V_256 < V_257 )
return 1 ;
else
return - 1 ;
}
}
static unsigned char * F_76 ( unsigned char * V_258 ,
T_3 V_259 ,
unsigned char * V_260 ,
T_3 V_261 )
{
T_1 V_262 , V_263 ;
unsigned char * V_252 ;
T_3 V_90 ;
V_252 = F_72 ( V_258 , V_259 ) ;
if ( ! V_252 )
return V_260 ;
V_90 = V_259 - ( V_252 - V_258 ) ;
if ( ! F_74 ( V_252 , V_90 , & V_262 ) ) {
V_259 -= V_90 ;
V_252 = F_72 ( V_258 , V_259 ) ;
if ( ! V_252 )
return V_260 ;
V_90 = V_259 - ( V_252 - V_258 ) ;
if ( ! F_74 ( V_252 , V_90 , & V_262 ) )
return V_260 ;
}
while ( 1 ) {
if ( F_74 ( V_260 , V_261 , & V_263 ) &&
F_75 ( V_262 , V_263 ) < 0 )
return V_260 ;
if ( ! F_71 ( & V_260 , & V_261 ) )
return V_260 + V_261 ;
}
}
unsigned char * F_77 ( unsigned char * V_258 , T_3 V_259 ,
unsigned char * V_260 , T_3 V_261 ,
bool V_264 )
{
unsigned char * V_265 ;
if ( ! F_70 ( & V_260 , & V_261 ) )
return V_260 + V_261 ;
if ( ! F_70 ( & V_258 , & V_259 ) )
return V_260 ;
if ( V_264 ) {
V_265 = F_76 ( V_258 , V_259 , V_260 , V_261 ) ;
if ( V_265 )
return V_265 ;
}
while ( V_261 < V_259 ) {
if ( ! F_71 ( & V_258 , & V_259 ) )
return V_260 ;
}
if ( V_261 > V_259 ) {
while ( ! F_69 ( V_260 + V_259 , V_261 - V_259 ) ) {
if ( ! F_71 ( & V_258 , & V_259 ) )
return V_260 ;
}
}
while ( 1 ) {
V_265 = F_65 ( V_258 , V_259 , V_260 , V_259 ) ;
if ( V_265 )
return V_260 + V_259 ;
if ( ! F_71 ( & V_258 , & V_259 ) )
return V_260 ;
while ( ! F_69 ( V_260 + V_259 , V_261 - V_259 ) ) {
if ( ! F_71 ( & V_258 , & V_259 ) )
return V_260 ;
}
}
}
