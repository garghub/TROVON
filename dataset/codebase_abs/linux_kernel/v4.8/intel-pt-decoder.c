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
V_4 -> V_7 = V_14 -> V_7 ;
V_4 -> V_5 = V_14 -> V_5 ;
V_4 -> V_19 = V_14 -> V_19 ;
V_4 -> V_20 = V_14 -> V_19 ;
F_2 ( V_4 ) ;
V_4 -> V_21 = V_14 -> V_22 ;
V_4 -> V_23 = ( 1 << V_4 -> V_21 ) - 1 ;
V_4 -> V_24 = V_14 -> V_24 ;
V_4 -> V_25 = V_14 -> V_25 ;
if ( ! V_4 -> V_24 )
V_4 -> V_25 = 0 ;
if ( V_4 -> V_25 ) {
if ( ! ( V_4 -> V_24 % V_4 -> V_25 ) )
V_4 -> V_26 = V_4 -> V_24 /
V_4 -> V_25 ;
V_4 -> V_27 = F_3 ( 2 << V_4 -> V_21 ,
V_4 -> V_24 ,
V_4 -> V_25 ) ;
}
if ( V_4 -> V_27 < 0x100 )
V_4 -> V_27 = 0x100 ;
F_6 ( L_1 , V_4 -> V_21 ) ;
F_6 ( L_2 , V_4 -> V_24 ) ;
F_6 ( L_3 , V_4 -> V_25 ) ;
F_6 ( L_4 , V_4 -> V_26 ) ;
F_6 ( L_5 , V_4 -> V_27 ) ;
return V_4 ;
}
static void F_7 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = V_29 -> V_31 ;
V_29 -> V_31 = V_31 -> V_32 ;
if ( ! V_29 -> V_33 )
V_29 -> V_33 = V_31 ;
else
free ( V_31 ) ;
}
static T_1 F_8 ( struct V_28 * V_29 )
{
if ( ! V_29 -> V_34 ) {
if ( ! V_29 -> V_31 )
return 0 ;
F_7 ( V_29 ) ;
if ( ! V_29 -> V_31 )
return 0 ;
V_29 -> V_34 = V_35 ;
}
return V_29 -> V_31 -> V_36 [ -- V_29 -> V_34 ] ;
}
static int F_9 ( struct V_28 * V_29 )
{
struct V_30 * V_31 ;
if ( V_29 -> V_33 ) {
V_31 = V_29 -> V_33 ;
V_29 -> V_33 = NULL ;
} else {
V_31 = malloc ( sizeof( struct V_30 ) ) ;
if ( ! V_31 )
return - V_37 ;
}
V_31 -> V_32 = V_29 -> V_31 ;
V_29 -> V_31 = V_31 ;
V_29 -> V_34 = 0 ;
return 0 ;
}
static int F_10 ( struct V_28 * V_29 , T_1 V_36 )
{
int V_38 ;
if ( ! V_29 -> V_31 || V_29 -> V_34 == V_35 ) {
V_38 = F_9 ( V_29 ) ;
if ( V_38 )
return V_38 ;
}
V_29 -> V_31 -> V_36 [ V_29 -> V_34 ++ ] = V_36 ;
return 0 ;
}
static void F_11 ( struct V_28 * V_29 )
{
while ( V_29 -> V_31 )
F_7 ( V_29 ) ;
V_29 -> V_34 = 0 ;
}
static void F_12 ( struct V_28 * V_29 )
{
F_11 ( V_29 ) ;
F_13 ( & V_29 -> V_31 ) ;
F_13 ( & V_29 -> V_33 ) ;
}
void F_14 ( struct V_3 * V_4 )
{
F_12 ( & V_4 -> V_29 ) ;
free ( V_4 ) ;
}
static int F_15 ( int V_39 )
{
switch ( V_39 ) {
case - V_37 :
return V_40 ;
case - V_41 :
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
default:
return V_57 ;
}
}
int F_16 ( int V_39 , char * V_58 , T_3 V_59 )
{
if ( V_39 < 1 || V_39 >= V_60 )
V_39 = V_57 ;
F_17 ( V_58 , V_61 [ V_39 ] , V_59 ) ;
return 0 ;
}
static T_1 F_18 ( const struct V_62 * V_63 ,
T_1 V_64 )
{
T_1 V_36 ;
switch ( V_63 -> V_65 ) {
case 1 :
V_36 = ( V_64 & ( T_1 ) 0xffffffffffff0000ULL ) |
V_63 -> V_66 ;
break;
case 2 :
V_36 = ( V_64 & ( T_1 ) 0xffffffff00000000ULL ) |
V_63 -> V_66 ;
break;
case 3 :
V_36 = V_63 -> V_66 ;
if ( V_36 & ( T_1 ) 0x800000000000ULL )
V_36 |= ( T_1 ) 0xffff000000000000ULL ;
break;
case 4 :
V_36 = ( V_64 & ( T_1 ) 0xffff000000000000ULL ) |
V_63 -> V_66 ;
break;
case 6 :
V_36 = V_63 -> V_66 ;
break;
default:
return 0 ;
}
return V_36 ;
}
static inline void F_19 ( struct V_3 * V_4 )
{
V_4 -> V_64 = F_18 ( & V_4 -> V_63 , V_4 -> V_64 ) ;
}
static inline void F_20 ( struct V_3 * V_4 )
{
F_19 ( V_4 ) ;
V_4 -> V_36 = V_4 -> V_64 ;
}
static void F_21 ( struct V_3 * V_4 )
{
F_22 ( & V_4 -> V_63 , V_4 -> V_67 , V_4 -> V_34 ,
V_4 -> V_58 ) ;
}
static int F_23 ( struct V_3 * V_4 )
{
F_6 ( L_6 ) ;
V_4 -> V_68 = V_69 ;
return - V_41 ;
}
static inline void F_24 ( struct V_3 * V_4 )
{
V_4 -> V_70 = 0 ;
}
static inline void F_25 ( struct V_3 * V_4 )
{
V_4 -> V_70 = V_4 -> V_63 . V_66 & V_71 ;
}
static int F_26 ( struct V_3 * V_4 )
{
F_24 ( V_4 ) ;
V_4 -> V_72 = false ;
V_4 -> V_67 = 1 ;
V_4 -> V_73 = 1 ;
F_21 ( V_4 ) ;
if ( V_4 -> V_68 != V_69 ) {
F_6 ( L_7 ) ;
V_4 -> V_68 = V_74 ;
}
return - V_43 ;
}
static int F_27 ( struct V_3 * V_4 )
{
struct V_75 V_76 = { . V_58 = 0 , } ;
int V_77 ;
V_4 -> V_73 = 0 ;
F_6 ( L_8 ) ;
V_77 = V_4 -> V_15 ( & V_76 , V_4 -> V_17 ) ;
if ( V_77 )
return V_77 ;
V_4 -> V_58 = V_76 . V_58 ;
V_4 -> V_78 = V_76 . V_78 ;
if ( ! V_4 -> V_78 ) {
F_6 ( L_9 ) ;
return - V_45 ;
}
if ( ! V_76 . V_79 ) {
V_4 -> V_36 = 0 ;
V_4 -> V_68 = V_69 ;
V_4 -> V_80 = V_76 . V_80 ;
V_4 -> V_81 = 0 ;
V_4 -> V_72 = false ;
V_4 -> V_82 . V_83 = V_76 . V_83 ;
F_6 ( L_10 V_84 L_11 ,
V_4 -> V_80 ) ;
return - V_85 ;
}
return 0 ;
}
static int F_28 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_86 )
return F_27 ( V_4 ) ;
V_4 -> V_58 = V_4 -> V_86 ;
V_4 -> V_78 = V_4 -> V_87 ;
V_4 -> V_86 = 0 ;
V_4 -> V_87 = 0 ;
return 0 ;
}
static int F_29 ( struct V_3 * V_4 )
{
unsigned char * V_58 = V_4 -> V_88 ;
T_3 V_89 , V_78 , V_11 ;
int V_77 ;
V_89 = V_4 -> V_78 ;
V_78 = V_4 -> V_78 ;
memcpy ( V_58 , V_4 -> V_58 , V_78 ) ;
V_77 = F_27 ( V_4 ) ;
if ( V_77 ) {
V_4 -> V_34 += V_89 ;
return V_77 < 0 ? V_77 : - V_90 ;
}
V_11 = V_91 - V_78 ;
if ( V_11 > V_4 -> V_78 )
V_11 = V_4 -> V_78 ;
memcpy ( V_58 + V_78 , V_4 -> V_58 , V_11 ) ;
V_78 += V_11 ;
V_77 = F_30 ( V_58 , V_78 , & V_4 -> V_63 ) ;
if ( V_77 < ( int ) V_89 ) {
V_4 -> V_86 = V_4 -> V_58 ;
V_4 -> V_87 = V_4 -> V_78 ;
V_4 -> V_58 = V_58 ;
V_4 -> V_78 = V_89 ;
return F_26 ( V_4 ) ;
}
V_4 -> V_86 = V_4 -> V_58 + ( V_77 - V_89 ) ;
V_4 -> V_87 = V_4 -> V_78 - ( V_77 - V_89 ) ;
V_4 -> V_58 = V_58 ;
V_4 -> V_78 = V_77 ;
return V_77 ;
}
static int F_31 ( struct V_3 * V_4 ,
T_4 V_92 , void * V_17 )
{
struct V_93 V_94 ;
const unsigned char * V_58 = V_4 -> V_58 ;
T_3 V_78 = V_4 -> V_78 ;
int V_77 ;
V_94 . V_4 = V_4 ;
V_94 . V_34 = V_4 -> V_34 ;
V_94 . V_67 = V_4 -> V_73 ;
V_94 . V_95 = V_4 -> V_95 ;
V_94 . V_17 = V_17 ;
while ( 1 ) {
do {
V_94 . V_34 += V_94 . V_67 ;
V_58 += V_94 . V_67 ;
V_78 -= V_94 . V_67 ;
if ( ! V_78 )
return V_96 ;
V_77 = F_30 ( V_58 , V_78 , & V_94 . V_63 ) ;
if ( ! V_77 )
return V_96 ;
if ( V_77 < 0 )
return V_77 ;
V_94 . V_67 = V_77 ;
} while ( V_94 . V_63 . type == V_97 );
V_77 = V_92 ( & V_94 ) ;
if ( V_77 )
return 0 ;
V_94 . V_95 = V_94 . V_63 . type ;
}
}
static int F_32 ( struct V_93 * V_94 )
{
struct V_3 * V_4 = V_94 -> V_4 ;
struct V_98 * V_17 = V_94 -> V_17 ;
T_1 V_81 ;
double V_99 ;
unsigned int V_100 ;
T_2 V_101 , V_102 , V_103 , V_104 , V_105 ;
switch ( V_94 -> V_63 . type ) {
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_97 :
case V_115 :
case V_116 :
return 0 ;
case V_117 :
if ( ! V_17 -> V_72 )
return 0 ;
V_101 = V_94 -> V_63 . V_66 ;
if ( V_101 > V_17 -> V_118 )
V_102 = V_101 - V_17 -> V_118 ;
else
V_102 = V_101 + 256 - V_17 -> V_118 ;
V_17 -> V_119 += V_102 << V_4 -> V_21 ;
V_17 -> V_118 = V_101 ;
if ( V_4 -> V_26 ) {
V_81 = V_17 -> V_120 +
V_17 -> V_119 * V_4 -> V_26 ;
} else {
V_81 = V_17 -> V_120 +
F_3 ( V_17 -> V_119 ,
V_4 -> V_24 ,
V_4 -> V_25 ) ;
}
if ( V_81 < V_17 -> V_81 )
return 1 ;
if ( V_94 -> V_95 != V_121 ) {
V_17 -> V_81 = V_81 ;
return 0 ;
}
break;
case V_122 :
V_81 = V_94 -> V_63 . V_66 |
( V_17 -> V_81 & ( 0xffULL << 56 ) ) ;
if ( V_17 -> V_123 && V_81 < V_17 -> V_81 &&
V_17 -> V_81 - V_81 < V_4 -> V_27 )
return 1 ;
if ( V_81 < V_17 -> V_81 )
V_81 += ( 1ULL << 56 ) ;
if ( V_94 -> V_95 != V_121 ) {
if ( V_17 -> V_123 )
return 1 ;
V_17 -> V_124 = V_81 ;
V_17 -> V_81 = V_81 ;
return 0 ;
}
break;
case V_125 :
if ( V_17 -> V_123 )
return 1 ;
if ( ! V_4 -> V_25 )
return 0 ;
V_103 = V_94 -> V_63 . V_66 ;
V_104 = V_94 -> V_63 . V_65 ;
V_105 = V_103 & V_4 -> V_23 ;
V_17 -> V_118 = ( V_103 >> V_4 -> V_21 ) & 0xff ;
V_17 -> V_120 = V_17 -> V_124 - V_104 ;
if ( V_4 -> V_26 ) {
V_17 -> V_120 -= V_105 * V_4 -> V_26 ;
} else {
V_17 -> V_120 -=
F_3 ( V_105 , V_4 -> V_24 ,
V_4 -> V_25 ) ;
}
V_17 -> V_119 = 0 ;
V_17 -> V_72 = true ;
return 0 ;
case V_121 :
V_17 -> V_126 += V_94 -> V_63 . V_66 ;
return 0 ;
case V_127 :
V_100 = V_94 -> V_63 . V_66 ;
if ( V_17 -> V_100 && V_17 -> V_100 != V_100 )
return 1 ;
V_17 -> V_100 = V_100 ;
V_17 -> V_128 = V_4 -> V_20 / V_100 ;
return 0 ;
case V_129 :
case V_130 :
case V_131 :
case V_132 :
default:
return 1 ;
}
if ( ! V_17 -> V_100 && V_4 -> V_100 ) {
V_17 -> V_100 = V_4 -> V_100 ;
V_17 -> V_128 = V_4 -> V_128 ;
}
if ( ! V_17 -> V_126 )
return 1 ;
V_99 = ( double ) ( V_81 - V_4 -> V_81 ) / V_17 -> V_126 ;
if ( V_17 -> V_100 && V_99 > V_17 -> V_128 &&
V_99 / V_17 -> V_128 > 1.25 ) {
F_6 ( L_12 V_133 L_11 ,
V_99 , V_17 -> V_128 , V_94 -> V_34 ) ;
return 1 ;
}
V_4 -> V_134 = V_99 ;
V_4 -> V_135 = true ;
if ( V_17 -> V_100 ) {
F_6 ( L_13 V_133 L_11 ,
V_99 , V_17 -> V_128 , V_94 -> V_34 ) ;
} else {
F_6 ( L_14 V_133 L_11 ,
V_99 , V_94 -> V_34 ) ;
}
return 1 ;
}
static void F_33 ( struct V_3 * V_4 ,
bool V_123 )
{
struct V_98 V_17 = {
. V_126 = 0 ,
. V_100 = 0 ,
. V_118 = V_4 -> V_118 ,
. V_120 = V_4 -> V_120 ,
. V_119 = V_4 -> V_119 ,
. V_124 = V_4 -> V_124 ,
. V_81 = V_4 -> V_81 ,
. V_72 = V_4 -> V_72 ,
. V_123 = V_123 ,
. V_128 = 0 ,
} ;
F_31 ( V_4 , F_32 , & V_17 ) ;
}
static int F_34 ( struct V_3 * V_4 )
{
int V_77 ;
V_4 -> V_95 = V_4 -> V_63 . type ;
do {
V_4 -> V_34 += V_4 -> V_73 ;
V_4 -> V_58 += V_4 -> V_73 ;
V_4 -> V_78 -= V_4 -> V_73 ;
if ( ! V_4 -> V_78 ) {
V_77 = F_28 ( V_4 ) ;
if ( V_77 )
return V_77 ;
}
V_77 = F_30 ( V_4 -> V_58 , V_4 -> V_78 ,
& V_4 -> V_63 ) ;
if ( V_77 == V_96 &&
V_4 -> V_78 < V_91 && ! V_4 -> V_86 ) {
V_77 = F_29 ( V_4 ) ;
if ( V_77 < 0 )
return V_77 ;
}
if ( V_77 <= 0 )
return F_26 ( V_4 ) ;
V_4 -> V_67 = V_77 ;
V_4 -> V_73 = V_77 ;
F_21 ( V_4 ) ;
} while ( V_4 -> V_63 . type == V_97 );
return 0 ;
}
static T_1 F_35 ( struct V_3 * V_4 )
{
T_1 V_81 , V_136 ;
V_81 = V_4 -> V_81 + V_4 -> V_137 ;
V_136 = V_81 & V_4 -> V_8 ;
if ( V_4 -> V_138 ) {
if ( V_136 != V_4 -> V_139 )
return 1 ;
} else {
V_81 += 1 ;
V_136 = V_81 & V_4 -> V_8 ;
if ( V_136 != V_4 -> V_139 ) {
V_4 -> V_139 = V_136 ;
V_4 -> V_138 = true ;
}
}
return V_4 -> V_9 - ( V_81 - V_136 ) ;
}
static T_1 F_36 ( struct V_3 * V_4 )
{
switch ( V_4 -> V_5 ) {
case V_140 :
return V_4 -> V_7 - V_4 -> V_141 ;
case V_6 :
return F_35 ( V_4 ) ;
case V_142 :
case V_143 :
default:
return 0 ;
}
}
static void F_37 ( struct V_3 * V_4 )
{
T_1 V_81 , V_136 ;
switch ( V_4 -> V_5 ) {
case V_140 :
V_4 -> V_141 = 0 ;
break;
case V_6 :
V_81 = V_4 -> V_81 + V_4 -> V_137 ;
V_136 = V_81 & V_4 -> V_8 ;
V_4 -> V_139 = V_136 ;
break;
case V_142 :
case V_143 :
default:
break;
}
V_4 -> V_82 . type |= V_144 ;
}
static int F_38 ( struct V_3 * V_4 ,
struct V_145 * V_145 , T_1 V_36 )
{
T_1 V_146 , V_147 = 0 ;
int V_38 ;
if ( ! V_4 -> V_148 )
V_4 -> V_148 = true ;
V_146 = F_36 ( V_4 ) ;
V_38 = V_4 -> V_16 ( V_145 , & V_147 , & V_4 -> V_36 , V_36 ,
V_146 , V_4 -> V_17 ) ;
V_4 -> V_149 += V_147 ;
V_4 -> V_137 += V_147 ;
V_4 -> V_141 += V_147 ;
if ( V_38 ) {
V_4 -> V_150 = 0 ;
V_4 -> V_68 = V_151 ;
F_39 ( L_15 ,
V_4 -> V_36 ) ;
if ( V_38 == - V_49 )
return - V_85 ;
return - V_47 ;
}
if ( V_36 && V_4 -> V_36 == V_36 ) {
V_38 = - V_152 ;
goto V_153;
}
if ( V_146 && V_147 >= V_146 )
F_37 ( V_4 ) ;
if ( V_145 -> V_154 == V_155 ) {
V_4 -> V_82 . type = V_144 ;
V_4 -> V_82 . V_156 = V_4 -> V_36 ;
V_4 -> V_82 . V_157 = 0 ;
V_4 -> V_36 += V_145 -> V_158 ;
V_38 = V_159 ;
goto V_153;
}
if ( V_145 -> V_160 == V_161 ) {
if ( V_145 -> V_154 != V_162 ||
V_145 -> V_163 ) {
V_38 = F_10 ( & V_4 -> V_29 , V_4 -> V_36 +
V_145 -> V_158 ) ;
if ( V_38 )
goto V_153;
}
} else if ( V_145 -> V_160 == V_164 ) {
V_4 -> V_165 = F_8 ( & V_4 -> V_29 ) ;
}
if ( V_145 -> V_154 == V_162 ) {
int V_166 = V_4 -> V_150 ++ ;
V_4 -> V_82 . V_156 = V_4 -> V_36 ;
V_4 -> V_36 += V_145 -> V_158 +
V_145 -> V_163 ;
V_4 -> V_82 . V_157 = V_4 -> V_36 ;
V_38 = V_159 ;
if ( V_166 ) {
if ( V_166 == 1 ) {
V_4 -> V_167 = V_4 -> V_82 . V_157 ;
V_4 -> V_168 = 1 ;
V_4 -> V_169 = 1 ;
} else if ( V_166 > V_170 ||
V_4 -> V_82 . V_157 == V_4 -> V_167 ) {
F_39 ( L_16 ,
V_4 -> V_82 . V_157 ) ;
V_4 -> V_68 = V_171 ;
V_38 = - V_55 ;
goto V_153;
} else if ( ! -- V_4 -> V_169 ) {
V_4 -> V_168 += 1 ;
V_4 -> V_169 = V_4 -> V_168 ;
V_4 -> V_167 = V_4 -> V_82 . V_157 ;
}
}
goto V_172;
}
V_153:
V_4 -> V_150 = 0 ;
V_172:
V_4 -> V_82 . V_173 = V_145 -> V_160 ;
V_4 -> V_82 . V_174 = V_145 -> V_158 ;
if ( V_4 -> V_70 & V_71 )
V_4 -> V_82 . V_175 |= V_71 ;
return V_38 ;
}
static int F_40 ( struct V_3 * V_4 )
{
struct V_145 V_145 ;
T_1 V_36 ;
int V_38 ;
V_36 = V_4 -> V_64 ;
while ( 1 ) {
V_38 = F_38 ( V_4 , & V_145 , V_36 ) ;
if ( V_38 == V_159 )
return 0 ;
if ( V_38 == - V_152 ) {
if ( V_4 -> V_176 ) {
V_4 -> V_176 = false ;
V_4 -> V_70 = V_4 -> V_177 ;
V_4 -> V_82 . type = V_178 ;
V_4 -> V_82 . V_156 = V_4 -> V_36 ;
V_4 -> V_82 . V_157 = 0 ;
V_4 -> V_82 . V_175 = V_4 -> V_177 ;
return 0 ;
}
return V_38 ;
}
V_4 -> V_176 = false ;
if ( V_38 )
return V_38 ;
if ( V_145 . V_154 == V_179 ) {
F_39 ( L_17 ,
V_4 -> V_36 ) ;
V_4 -> V_68 = V_171 ;
return - V_49 ;
}
if ( V_145 . V_154 == V_180 ) {
F_39 ( L_18 ,
V_4 -> V_36 ) ;
V_4 -> V_68 = V_171 ;
return - V_49 ;
}
F_23 ( V_4 ) ;
}
}
static int F_41 ( struct V_3 * V_4 )
{
struct V_145 V_145 ;
int V_38 ;
V_38 = F_38 ( V_4 , & V_145 , 0 ) ;
if ( V_38 == V_159 )
return 0 ;
if ( V_38 )
return V_38 ;
if ( V_145 . V_154 == V_179 ) {
if ( V_4 -> V_68 == V_181 ) {
V_4 -> V_182 = false ;
V_4 -> V_138 = false ;
V_4 -> V_68 = V_183 ;
V_4 -> V_82 . V_156 = V_4 -> V_36 ;
V_4 -> V_82 . V_157 = 0 ;
if ( V_4 -> V_63 . V_65 != 0 )
V_4 -> V_36 = V_4 -> V_64 ;
} else {
V_4 -> V_68 = V_183 ;
V_4 -> V_82 . V_156 = V_4 -> V_36 ;
if ( V_4 -> V_63 . V_65 == 0 ) {
V_4 -> V_82 . V_157 = 0 ;
} else {
V_4 -> V_82 . V_157 = V_4 -> V_64 ;
V_4 -> V_36 = V_4 -> V_64 ;
}
}
return 0 ;
}
if ( V_145 . V_154 == V_180 ) {
F_39 ( L_19 ,
V_4 -> V_36 ) ;
V_4 -> V_68 = V_171 ;
return - V_49 ;
}
return F_23 ( V_4 ) ;
}
static int F_42 ( struct V_3 * V_4 )
{
struct V_145 V_145 ;
int V_38 ;
while ( 1 ) {
V_38 = F_38 ( V_4 , & V_145 , 0 ) ;
if ( V_38 == V_159 )
return 0 ;
if ( V_38 )
return V_38 ;
if ( V_145 . V_160 == V_164 ) {
if ( ! V_4 -> V_18 ) {
F_39 ( L_20 ,
V_4 -> V_36 ) ;
V_4 -> V_68 = V_184 ;
return - V_49 ;
}
if ( ! V_4 -> V_165 ) {
F_39 ( L_21 ,
V_4 -> V_36 ) ;
V_4 -> V_68 = V_184 ;
return - V_49 ;
}
if ( ! ( V_4 -> V_185 . V_66 & V_186 ) ) {
F_39 ( L_22 ,
V_4 -> V_36 ) ;
V_4 -> V_68 = V_184 ;
return - V_49 ;
}
V_4 -> V_185 . V_65 -= 1 ;
if ( ! V_4 -> V_185 . V_65 )
V_4 -> V_68 = V_183 ;
V_4 -> V_185 . V_66 <<= 1 ;
V_4 -> V_82 . V_156 = V_4 -> V_36 ;
V_4 -> V_36 = V_4 -> V_165 ;
V_4 -> V_82 . V_157 = V_4 -> V_36 ;
return 0 ;
}
if ( V_145 . V_154 == V_179 ) {
V_38 = F_34 ( V_4 ) ;
if ( V_38 )
return V_38 ;
if ( V_4 -> V_63 . type != V_108 ||
V_4 -> V_63 . V_65 == 0 ) {
F_39 ( L_23 ,
V_4 -> V_36 ) ;
V_4 -> V_68 = V_184 ;
V_4 -> V_73 = 0 ;
return - V_49 ;
}
F_19 ( V_4 ) ;
V_4 -> V_82 . V_156 = V_4 -> V_36 ;
V_4 -> V_82 . V_157 = V_4 -> V_64 ;
V_4 -> V_36 = V_4 -> V_64 ;
return 0 ;
}
if ( V_145 . V_154 == V_180 ) {
V_4 -> V_185 . V_65 -= 1 ;
if ( ! V_4 -> V_185 . V_65 )
V_4 -> V_68 = V_183 ;
if ( V_4 -> V_185 . V_66 & V_186 ) {
V_4 -> V_185 . V_66 <<= 1 ;
V_4 -> V_82 . V_156 = V_4 -> V_36 ;
V_4 -> V_36 += V_145 . V_158 +
V_145 . V_163 ;
V_4 -> V_82 . V_157 = V_4 -> V_36 ;
return 0 ;
}
if ( V_4 -> V_82 . type & V_144 ) {
V_4 -> V_185 . V_66 <<= 1 ;
V_4 -> V_82 . type = V_144 ;
V_4 -> V_82 . V_156 = V_4 -> V_36 ;
V_4 -> V_82 . V_157 = 0 ;
V_4 -> V_36 += V_145 . V_158 ;
return 0 ;
}
V_4 -> V_36 += V_145 . V_158 ;
if ( ! V_4 -> V_185 . V_65 )
return - V_152 ;
V_4 -> V_185 . V_66 <<= 1 ;
continue;
}
return F_23 ( V_4 ) ;
}
}
static int F_43 ( struct V_3 * V_4 , bool * V_187 )
{
unsigned int V_177 ;
int V_38 ;
V_177 = V_4 -> V_63 . V_66 &
( V_71 | V_188 ) ;
V_38 = F_34 ( V_4 ) ;
if ( V_38 )
return V_38 ;
if ( V_4 -> V_63 . type == V_109 ) {
V_4 -> V_177 = V_177 ;
V_4 -> V_176 = true ;
if ( ! ( V_4 -> V_177 & V_188 ) )
* V_187 = true ;
} else {
F_39 ( L_24 ,
V_4 -> V_34 ) ;
F_25 ( V_4 ) ;
}
return 0 ;
}
static void F_44 ( struct V_3 * V_4 )
{
T_1 V_81 ;
V_4 -> V_72 = false ;
if ( V_4 -> V_80 ) {
V_81 = V_4 -> V_63 . V_66 |
( V_4 -> V_80 & ( 0xffULL << 56 ) ) ;
if ( V_81 < V_4 -> V_80 ) {
if ( V_4 -> V_80 - V_81 > ( 1ULL << 55 ) )
V_81 += ( 1ULL << 56 ) ;
} else {
if ( V_81 - V_4 -> V_80 > ( 1ULL << 55 ) )
V_81 -= ( 1ULL << 56 ) ;
}
V_4 -> V_124 = V_81 ;
V_4 -> V_81 = V_81 ;
V_4 -> V_80 = 0 ;
V_4 -> V_137 = 0 ;
} else if ( V_4 -> V_81 ) {
V_81 = V_4 -> V_63 . V_66 |
( V_4 -> V_81 & ( 0xffULL << 56 ) ) ;
V_4 -> V_124 = V_81 ;
if ( V_81 < V_4 -> V_81 &&
V_4 -> V_81 - V_81 < V_4 -> V_27 ) {
F_45 ( L_25 ,
V_81 ) ;
V_81 = V_4 -> V_81 ;
}
if ( V_81 < V_4 -> V_81 ) {
F_45 ( L_26 , V_81 ) ;
V_81 += ( 1ULL << 56 ) ;
V_4 -> V_124 = V_81 ;
}
V_4 -> V_81 = V_81 ;
V_4 -> V_137 = 0 ;
}
if ( V_4 -> V_95 == V_121 ) {
V_4 -> V_189 = V_4 -> V_81 ;
V_4 -> V_126 = 0 ;
V_4 -> V_135 = false ;
F_33 ( V_4 , false ) ;
}
F_45 ( L_27 , V_4 -> V_81 ) ;
}
static int F_46 ( struct V_3 * V_4 )
{
F_6 ( L_28 ) ;
F_24 ( V_4 ) ;
V_4 -> V_72 = false ;
V_4 -> V_100 = 0 ;
V_4 -> V_68 = V_171 ;
V_4 -> V_190 = true ;
return - V_51 ;
}
static void F_47 ( struct V_3 * V_4 )
{
T_2 V_103 = V_4 -> V_63 . V_66 ;
T_2 V_104 = V_4 -> V_63 . V_65 ;
T_2 V_105 = V_103 & V_4 -> V_23 ;
if ( ! V_4 -> V_25 )
return;
V_4 -> V_118 = ( V_103 >> V_4 -> V_21 ) & 0xff ;
V_4 -> V_120 = V_4 -> V_124 - V_104 ;
if ( V_4 -> V_26 ) {
V_4 -> V_120 -= V_105 * V_4 -> V_26 ;
} else {
V_4 -> V_120 -= F_3 ( V_105 ,
V_4 -> V_24 ,
V_4 -> V_25 ) ;
}
V_4 -> V_119 = 0 ;
V_4 -> V_72 = true ;
F_6 ( L_29 V_133 L_30 ,
V_4 -> V_120 , V_4 -> V_118 , V_105 ) ;
}
static void F_48 ( struct V_3 * V_4 )
{
T_1 V_81 ;
T_2 V_101 , V_102 ;
if ( ! V_4 -> V_72 )
return;
V_101 = V_4 -> V_63 . V_66 ;
if ( V_101 > V_4 -> V_118 )
V_102 = V_101 - V_4 -> V_118 ;
else
V_102 = V_101 + 256 - V_4 -> V_118 ;
V_4 -> V_119 += V_102 << V_4 -> V_21 ;
if ( V_4 -> V_26 ) {
V_81 = V_4 -> V_120 +
V_4 -> V_119 * V_4 -> V_26 ;
} else {
V_81 = V_4 -> V_120 +
F_3 ( V_4 -> V_119 ,
V_4 -> V_24 ,
V_4 -> V_25 ) ;
}
if ( V_81 < V_4 -> V_81 )
F_6 ( L_31 V_133 L_32 V_133 L_11 ,
V_81 , V_4 -> V_81 ) ;
else
V_4 -> V_81 = V_81 ;
V_4 -> V_137 = 0 ;
V_4 -> V_118 = V_101 ;
if ( V_4 -> V_95 == V_121 ) {
V_4 -> V_189 = V_4 -> V_81 ;
V_4 -> V_126 = 0 ;
V_4 -> V_135 = false ;
F_33 ( V_4 , true ) ;
}
}
static void F_49 ( struct V_3 * V_4 )
{
unsigned int V_100 = V_4 -> V_63 . V_66 ;
if ( V_4 -> V_100 == V_100 )
return;
V_4 -> V_100 = V_100 ;
V_4 -> V_128 = V_4 -> V_20 / V_100 ;
}
static void F_50 ( struct V_3 * V_4 )
{
T_1 V_81 = V_4 -> V_189 ;
V_4 -> V_191 = true ;
V_4 -> V_126 += V_4 -> V_63 . V_66 ;
if ( ! V_4 -> V_189 )
return;
if ( V_4 -> V_135 )
V_81 += V_4 -> V_126 * V_4 -> V_134 ;
else if ( V_4 -> V_100 )
V_81 += V_4 -> V_126 * V_4 -> V_128 ;
else
return;
if ( V_81 < V_4 -> V_81 )
F_6 ( L_33 V_133 L_32 V_133 L_11 ,
V_81 , V_4 -> V_81 ) ;
else
V_4 -> V_81 = V_81 ;
}
static int F_51 ( struct V_3 * V_4 )
{
int V_38 ;
while ( 1 ) {
V_38 = F_34 ( V_4 ) ;
if ( V_38 )
return V_38 ;
switch ( V_4 -> V_63 . type ) {
case V_114 :
return 0 ;
case V_129 :
case V_107 :
case V_108 :
case V_106 :
case V_130 :
case V_132 :
case V_110 :
V_4 -> V_72 = false ;
F_6 ( L_34 ) ;
return - V_152 ;
case V_131 :
return F_46 ( V_4 ) ;
case V_122 :
F_44 ( V_4 ) ;
break;
case V_125 :
F_47 ( V_4 ) ;
break;
case V_127 :
F_49 ( V_4 ) ;
break;
case V_112 :
V_4 -> V_192 = V_4 -> V_63 . V_66 ;
break;
case V_111 :
V_4 -> V_193 = V_4 -> V_63 . V_66 & ( V_186 - 1 ) ;
break;
case V_109 :
V_4 -> V_182 = true ;
F_19 ( V_4 ) ;
break;
case V_113 :
F_25 ( V_4 ) ;
break;
case V_117 :
F_48 ( V_4 ) ;
if ( V_4 -> V_5 == V_143 )
V_4 -> V_82 . type |= V_144 ;
break;
case V_121 :
case V_115 :
case V_116 :
case V_97 :
default:
break;
}
}
}
static int F_52 ( struct V_3 * V_4 )
{
int V_38 ;
if ( V_4 -> V_70 & V_188 ) {
V_4 -> V_70 = 0 ;
V_4 -> V_82 . V_175 &= ~ V_71 ;
V_4 -> V_82 . V_175 |= V_188 ;
} else {
V_4 -> V_82 . V_175 |= V_194 ;
}
while ( 1 ) {
V_38 = F_34 ( V_4 ) ;
if ( V_38 )
return V_38 ;
switch ( V_4 -> V_63 . type ) {
case V_106 :
case V_109 :
case V_130 :
case V_110 :
case V_122 :
case V_125 :
case V_127 :
case V_113 :
case V_132 :
case V_114 :
F_6 ( L_35 ) ;
V_4 -> V_68 = V_184 ;
return - V_49 ;
case V_131 :
return F_46 ( V_4 ) ;
case V_129 :
V_4 -> V_82 . V_156 = V_4 -> V_36 ;
V_4 -> V_82 . V_157 = 0 ;
if ( V_4 -> V_63 . V_65 != 0 ) {
F_20 ( V_4 ) ;
F_6 ( L_36 V_133 L_11 ,
V_4 -> V_36 ) ;
}
V_4 -> V_182 = false ;
V_4 -> V_138 = false ;
return 0 ;
case V_107 :
V_4 -> V_182 = true ;
F_6 ( L_37 V_133 L_11 ,
V_4 -> V_36 ) ;
V_4 -> V_82 . V_156 = 0 ;
if ( V_4 -> V_63 . V_65 == 0 ) {
V_4 -> V_82 . V_157 = 0 ;
} else {
F_20 ( V_4 ) ;
V_4 -> V_82 . V_157 = V_4 -> V_36 ;
}
return 0 ;
case V_108 :
V_4 -> V_82 . V_156 = V_4 -> V_36 ;
if ( V_4 -> V_63 . V_65 == 0 ) {
V_4 -> V_82 . V_157 = 0 ;
} else {
F_20 ( V_4 ) ;
V_4 -> V_82 . V_157 = V_4 -> V_36 ;
}
return 0 ;
case V_111 :
V_4 -> V_193 = V_4 -> V_63 . V_66 & ( V_186 - 1 ) ;
break;
case V_117 :
F_48 ( V_4 ) ;
if ( V_4 -> V_5 == V_143 )
V_4 -> V_82 . type |= V_144 ;
break;
case V_121 :
F_50 ( V_4 ) ;
break;
case V_112 :
V_4 -> V_192 = V_4 -> V_63 . V_66 ;
break;
case V_115 :
case V_116 :
case V_97 :
break;
default:
return F_23 ( V_4 ) ;
}
}
}
static int F_53 ( struct V_3 * V_4 )
{
bool V_187 = false ;
int V_38 ;
while ( 1 ) {
V_38 = F_34 ( V_4 ) ;
if ( V_38 )
return V_38 ;
V_195:
switch ( V_4 -> V_63 . type ) {
case V_106 :
if ( ! V_4 -> V_63 . V_65 )
break;
V_4 -> V_185 = V_4 -> V_63 ;
V_4 -> V_68 = V_196 ;
V_38 = F_42 ( V_4 ) ;
if ( V_38 == - V_152 )
break;
return V_38 ;
case V_129 :
if ( V_4 -> V_63 . V_65 != 0 )
F_19 ( V_4 ) ;
V_4 -> V_68 = V_181 ;
return F_41 ( V_4 ) ;
case V_107 : {
V_4 -> V_182 = true ;
if ( V_4 -> V_63 . V_65 == 0 ) {
F_39 ( L_38 ,
V_4 -> V_34 ) ;
break;
}
F_20 ( V_4 ) ;
V_4 -> V_82 . V_156 = 0 ;
V_4 -> V_82 . V_157 = V_4 -> V_36 ;
return 0 ;
}
case V_131 :
return F_46 ( V_4 ) ;
case V_108 :
if ( V_4 -> V_63 . V_65 != 0 )
F_19 ( V_4 ) ;
V_4 -> V_68 = V_197 ;
return F_41 ( V_4 ) ;
case V_109 :
if ( V_4 -> V_63 . V_65 == 0 ) {
F_39 ( L_39 ,
V_4 -> V_34 ) ;
V_187 = false ;
break;
}
F_19 ( V_4 ) ;
V_38 = F_40 ( V_4 ) ;
if ( V_38 != - V_152 ) {
if ( V_38 )
return V_38 ;
if ( V_187 )
V_4 -> V_68 =
V_198 ;
else
V_4 -> V_68 = V_199 ;
return 0 ;
}
if ( V_187 ) {
V_187 = false ;
break;
}
return F_52 ( V_4 ) ;
case V_130 :
V_4 -> V_182 = false ;
V_4 -> V_138 = false ;
F_24 ( V_4 ) ;
V_4 -> V_72 = false ;
break;
case V_110 :
F_11 ( & V_4 -> V_29 ) ;
V_38 = F_51 ( V_4 ) ;
if ( V_38 == - V_152 )
goto V_195;
if ( V_38 )
return V_38 ;
break;
case V_111 :
V_4 -> V_193 = V_4 -> V_63 . V_66 & ( V_186 - 1 ) ;
break;
case V_117 :
F_48 ( V_4 ) ;
if ( V_4 -> V_5 != V_143 )
break;
if ( ! V_4 -> V_148 )
break;
V_4 -> V_148 = false ;
if ( ! V_4 -> V_81 )
break;
V_4 -> V_82 . type = V_144 ;
V_4 -> V_82 . V_156 = V_4 -> V_36 ;
V_4 -> V_82 . V_157 = 0 ;
V_4 -> V_148 = false ;
return 0 ;
case V_122 :
F_44 ( V_4 ) ;
break;
case V_125 :
F_47 ( V_4 ) ;
break;
case V_121 :
F_50 ( V_4 ) ;
break;
case V_127 :
F_49 ( V_4 ) ;
break;
case V_112 :
V_4 -> V_192 = V_4 -> V_63 . V_66 ;
break;
case V_113 :
if ( ! V_4 -> V_182 ) {
F_25 ( V_4 ) ;
break;
}
V_38 = F_43 ( V_4 , & V_187 ) ;
if ( V_38 )
return V_38 ;
goto V_195;
case V_132 :
return F_23 ( V_4 ) ;
case V_114 :
case V_115 :
case V_116 :
case V_97 :
break;
default:
return F_23 ( V_4 ) ;
}
}
}
static inline bool F_54 ( struct V_3 * V_4 )
{
return V_4 -> V_64 || V_4 -> V_63 . V_65 == 0 ||
V_4 -> V_63 . V_65 == 3 || V_4 -> V_63 . V_65 == 6 ;
}
static int F_55 ( struct V_3 * V_4 )
{
int V_38 ;
while ( 1 ) {
V_38 = F_34 ( V_4 ) ;
if ( V_38 )
return V_38 ;
switch ( V_4 -> V_63 . type ) {
case V_129 :
V_4 -> V_138 = false ;
case V_107 :
case V_108 :
F_6 ( L_34 ) ;
return - V_49 ;
case V_109 :
V_4 -> V_182 = true ;
if ( F_54 ( V_4 ) ) {
T_1 V_200 = V_4 -> V_36 ;
F_20 ( V_4 ) ;
if ( V_200 )
F_45 ( L_40 ,
V_4 -> V_36 ) ;
}
break;
case V_117 :
F_48 ( V_4 ) ;
break;
case V_122 :
F_44 ( V_4 ) ;
break;
case V_125 :
F_47 ( V_4 ) ;
break;
case V_121 :
F_50 ( V_4 ) ;
break;
case V_127 :
F_49 ( V_4 ) ;
break;
case V_111 :
V_4 -> V_193 = V_4 -> V_63 . V_66 & ( V_186 - 1 ) ;
break;
case V_112 :
V_4 -> V_192 = V_4 -> V_63 . V_66 ;
break;
case V_113 :
F_25 ( V_4 ) ;
break;
case V_130 :
V_4 -> V_182 = false ;
V_4 -> V_138 = false ;
F_24 ( V_4 ) ;
case V_106 :
V_4 -> V_72 = false ;
F_6 ( L_34 ) ;
if ( V_4 -> V_36 )
V_4 -> V_68 = V_201 ;
else
V_4 -> V_68 = V_184 ;
return - V_49 ;
case V_132 :
return F_23 ( V_4 ) ;
case V_131 :
return F_46 ( V_4 ) ;
case V_114 :
return 0 ;
case V_110 :
case V_115 :
case V_116 :
case V_97 :
default:
break;
}
}
}
static int F_56 ( struct V_3 * V_4 )
{
int V_38 ;
while ( 1 ) {
V_38 = F_34 ( V_4 ) ;
if ( V_38 )
return V_38 ;
switch ( V_4 -> V_63 . type ) {
case V_129 :
V_4 -> V_138 = false ;
case V_107 :
case V_108 :
V_4 -> V_182 = V_4 -> V_63 . type != V_129 ;
if ( F_54 ( V_4 ) )
F_20 ( V_4 ) ;
if ( V_4 -> V_36 )
return 0 ;
break;
case V_109 :
if ( V_4 -> V_190 ) {
if ( F_54 ( V_4 ) )
F_20 ( V_4 ) ;
if ( V_4 -> V_36 )
return 0 ;
}
if ( V_4 -> V_63 . V_65 )
F_19 ( V_4 ) ;
break;
case V_117 :
F_48 ( V_4 ) ;
break;
case V_122 :
F_44 ( V_4 ) ;
break;
case V_125 :
F_47 ( V_4 ) ;
break;
case V_121 :
F_50 ( V_4 ) ;
break;
case V_127 :
F_49 ( V_4 ) ;
break;
case V_111 :
V_4 -> V_193 = V_4 -> V_63 . V_66 & ( V_186 - 1 ) ;
break;
case V_112 :
V_4 -> V_192 = V_4 -> V_63 . V_66 ;
break;
case V_113 :
F_25 ( V_4 ) ;
break;
case V_131 :
return F_46 ( V_4 ) ;
case V_132 :
return F_23 ( V_4 ) ;
case V_130 :
V_4 -> V_182 = false ;
V_4 -> V_138 = false ;
F_24 ( V_4 ) ;
V_4 -> V_72 = false ;
break;
case V_110 :
V_38 = F_55 ( V_4 ) ;
if ( V_38 )
return V_38 ;
if ( V_4 -> V_36 ) {
V_4 -> V_82 . type = 0 ;
return 0 ;
}
break;
case V_106 :
case V_114 :
case V_115 :
case V_116 :
case V_97 :
default:
break;
}
}
}
static int F_57 ( struct V_3 * V_4 )
{
int V_38 ;
F_6 ( L_41 ) ;
V_38 = F_56 ( V_4 ) ;
if ( V_38 )
return V_38 ;
V_4 -> V_68 = V_183 ;
V_4 -> V_190 = false ;
V_4 -> V_82 . V_156 = 0 ;
V_4 -> V_82 . V_157 = V_4 -> V_36 ;
F_45 ( L_40 , V_4 -> V_36 ) ;
return 0 ;
}
static int F_58 ( struct V_3 * V_4 )
{
const unsigned char * V_202 = V_4 -> V_58 + V_4 -> V_78 ;
T_3 V_2 ;
for ( V_2 = V_203 - 1 ; V_2 ; V_2 -- ) {
if ( V_2 > V_4 -> V_78 )
continue;
if ( ! memcmp ( V_202 - V_2 , V_204 , V_2 ) )
return V_2 ;
}
return 0 ;
}
static int F_59 ( struct V_3 * V_4 , int V_205 )
{
T_3 V_206 = V_203 - V_205 ;
const char * V_207 = V_204 ;
if ( V_206 > V_4 -> V_78 ||
memcmp ( V_4 -> V_58 , V_207 + V_205 , V_206 ) )
return 0 ;
return V_206 ;
}
static int F_60 ( struct V_3 * V_4 ,
int V_205 )
{
int V_206 , V_77 ;
V_4 -> V_34 += V_4 -> V_78 ;
V_4 -> V_78 = 0 ;
V_77 = F_28 ( V_4 ) ;
if ( V_77 )
return V_77 ;
V_206 = F_59 ( V_4 , V_205 ) ;
if ( ! V_206 )
return 0 ;
V_4 -> V_34 -= V_205 ;
V_4 -> V_86 = V_4 -> V_58 + V_206 ;
V_4 -> V_87 = V_4 -> V_78 - V_206 ;
memcpy ( V_4 -> V_88 , V_204 , V_203 ) ;
V_4 -> V_58 = V_4 -> V_88 ;
V_4 -> V_78 = V_203 ;
return 0 ;
}
static int F_61 ( struct V_3 * V_4 )
{
unsigned char * V_195 ;
int V_77 ;
F_6 ( L_42 ) ;
while ( 1 ) {
if ( ! V_4 -> V_78 ) {
V_77 = F_28 ( V_4 ) ;
if ( V_77 )
return V_77 ;
}
V_195 = F_62 ( V_4 -> V_58 , V_4 -> V_78 , V_204 ,
V_203 ) ;
if ( ! V_195 ) {
int V_205 ;
V_205 = F_58 ( V_4 ) ;
if ( V_205 ) {
V_77 = F_60 ( V_4 , V_205 ) ;
if ( V_77 )
return V_77 ;
} else {
V_4 -> V_34 += V_4 -> V_78 ;
V_4 -> V_78 = 0 ;
}
continue;
}
V_4 -> V_73 = V_195 - V_4 -> V_58 ;
return F_34 ( V_4 ) ;
}
}
static int F_63 ( struct V_3 * V_4 )
{
int V_38 ;
V_4 -> V_182 = false ;
V_4 -> V_138 = false ;
V_4 -> V_64 = 0 ;
V_4 -> V_36 = 0 ;
F_11 ( & V_4 -> V_29 ) ;
V_38 = F_61 ( V_4 ) ;
if ( V_38 )
return V_38 ;
V_4 -> V_68 = V_208 ;
V_38 = F_55 ( V_4 ) ;
if ( V_38 )
return V_38 ;
if ( V_4 -> V_36 ) {
V_4 -> V_82 . type = 0 ;
V_4 -> V_68 = V_183 ;
} else {
return F_57 ( V_4 ) ;
}
return 0 ;
}
static T_1 F_64 ( struct V_3 * V_4 )
{
T_1 V_209 = V_4 -> V_137 << 1 ;
if ( ! V_4 -> V_100 || ! V_4 -> V_19 )
goto V_153;
V_209 *= V_4 -> V_19 ;
V_209 /= V_4 -> V_100 ;
V_153:
return V_4 -> V_81 + V_209 ;
}
const struct V_210 * F_65 ( struct V_3 * V_4 )
{
int V_38 ;
do {
V_4 -> V_82 . type = V_211 ;
V_4 -> V_82 . V_175 = 0 ;
switch ( V_4 -> V_68 ) {
case V_69 :
V_38 = F_63 ( V_4 ) ;
break;
case V_208 :
V_4 -> V_64 = 0 ;
case V_171 :
V_38 = F_57 ( V_4 ) ;
break;
case V_183 :
V_38 = F_53 ( V_4 ) ;
break;
case V_196 :
V_38 = F_42 ( V_4 ) ;
if ( V_38 == - V_152 )
V_38 = F_53 ( V_4 ) ;
break;
case V_197 :
case V_181 :
V_38 = F_41 ( V_4 ) ;
break;
case V_199 :
V_4 -> V_68 = V_183 ;
V_38 = F_40 ( V_4 ) ;
if ( V_38 == - V_152 )
V_38 = F_52 ( V_4 ) ;
else if ( ! V_38 )
V_4 -> V_68 = V_199 ;
break;
case V_198 :
V_4 -> V_68 = V_183 ;
V_38 = F_40 ( V_4 ) ;
if ( V_38 == - V_152 )
V_38 = F_53 ( V_4 ) ;
break;
default:
V_38 = F_23 ( V_4 ) ;
break;
}
} while ( V_38 == - V_85 );
V_4 -> V_82 . V_38 = V_38 ? F_15 ( V_38 ) : 0 ;
V_4 -> V_82 . V_81 = V_4 -> V_81 ;
V_4 -> V_82 . V_212 = F_64 ( V_4 ) ;
V_4 -> V_82 . V_193 = V_4 -> V_193 ;
V_4 -> V_82 . V_149 = V_4 -> V_149 ;
if ( V_38 )
V_4 -> V_82 . V_156 = V_4 -> V_36 ;
return & V_4 -> V_82 ;
}
static bool F_66 ( unsigned char * V_58 , T_3 V_78 )
{
if ( V_78 < V_203 )
return false ;
return F_62 ( V_58 , V_203 , V_204 ,
V_203 ) ;
}
static bool F_67 ( unsigned char * * V_58 , T_3 * V_78 )
{
unsigned char * V_195 ;
V_195 = F_62 ( * V_58 , * V_78 , V_204 , V_203 ) ;
if ( V_195 ) {
* V_78 -= V_195 - * V_58 ;
* V_58 = V_195 ;
return true ;
}
return false ;
}
static bool F_68 ( unsigned char * * V_58 , T_3 * V_78 )
{
unsigned char * V_195 ;
if ( ! * V_78 )
return false ;
V_195 = F_62 ( * V_58 + 1 , * V_78 - 1 , V_204 , V_203 ) ;
if ( V_195 ) {
* V_78 -= V_195 - * V_58 ;
* V_58 = V_195 ;
return true ;
}
return false ;
}
static unsigned char * F_69 ( unsigned char * V_58 , T_3 V_78 )
{
const char * V_11 = V_204 ;
unsigned char * V_213 ;
T_3 V_214 ;
if ( V_78 < V_203 )
return NULL ;
V_214 = V_78 - V_203 + 1 ;
while ( 1 ) {
V_213 = F_70 ( V_58 , V_11 [ 0 ] , V_214 ) ;
if ( ! V_213 )
return NULL ;
if ( ! memcmp ( V_213 + 1 , V_11 + 1 , V_203 - 1 ) )
return V_213 ;
V_214 = V_213 - V_58 ;
if ( ! V_214 )
return NULL ;
}
}
static bool F_71 ( unsigned char * V_58 , T_3 V_78 , T_1 * V_215 )
{
struct V_62 V_63 ;
int V_77 ;
while ( V_78 ) {
V_77 = F_30 ( V_58 , V_78 , & V_63 ) ;
if ( V_77 <= 0 )
return false ;
if ( V_63 . type == V_122 ) {
* V_215 = V_63 . V_66 ;
return true ;
}
if ( V_63 . type == V_114 )
return false ;
V_58 += V_77 ;
V_78 -= V_77 ;
}
return false ;
}
static int F_72 ( T_1 V_216 , T_1 V_217 )
{
const T_1 V_218 = ( 1ULL << 55 ) ;
if ( V_216 == V_217 )
return 0 ;
if ( V_216 < V_217 ) {
if ( V_217 - V_216 < V_218 )
return - 1 ;
else
return 1 ;
} else {
if ( V_216 - V_217 < V_218 )
return 1 ;
else
return - 1 ;
}
}
static unsigned char * F_73 ( unsigned char * V_219 ,
T_3 V_220 ,
unsigned char * V_221 ,
T_3 V_222 )
{
T_1 V_223 , V_224 ;
unsigned char * V_213 ;
T_3 V_78 ;
V_213 = F_69 ( V_219 , V_220 ) ;
if ( ! V_213 )
return V_221 ;
V_78 = V_220 - ( V_213 - V_219 ) ;
if ( ! F_71 ( V_213 , V_78 , & V_223 ) ) {
V_220 -= V_78 ;
V_213 = F_69 ( V_219 , V_220 ) ;
if ( ! V_213 )
return V_221 ;
V_78 = V_220 - ( V_213 - V_219 ) ;
if ( ! F_71 ( V_213 , V_78 , & V_223 ) )
return V_221 ;
}
while ( 1 ) {
if ( F_71 ( V_221 , V_222 , & V_224 ) &&
F_72 ( V_223 , V_224 ) < 0 )
return V_221 ;
if ( ! F_68 ( & V_221 , & V_222 ) )
return V_221 + V_222 ;
}
}
unsigned char * F_74 ( unsigned char * V_219 , T_3 V_220 ,
unsigned char * V_221 , T_3 V_222 ,
bool V_225 )
{
unsigned char * V_226 ;
if ( ! F_67 ( & V_221 , & V_222 ) )
return V_221 + V_222 ;
if ( ! F_67 ( & V_219 , & V_220 ) )
return V_221 ;
if ( V_225 ) {
V_226 = F_73 ( V_219 , V_220 , V_221 , V_222 ) ;
if ( V_226 )
return V_226 ;
}
while ( V_222 < V_220 ) {
if ( ! F_68 ( & V_219 , & V_220 ) )
return V_221 ;
}
if ( V_222 > V_220 ) {
while ( ! F_66 ( V_221 + V_220 , V_222 - V_220 ) ) {
if ( ! F_68 ( & V_219 , & V_220 ) )
return V_221 ;
}
}
while ( 1 ) {
V_226 = F_62 ( V_219 , V_220 , V_221 , V_220 ) ;
if ( V_226 )
return V_221 + V_220 ;
if ( ! F_68 ( & V_219 , & V_220 ) )
return V_221 ;
while ( ! F_66 ( V_221 + V_220 , V_222 - V_220 ) ) {
if ( ! F_68 ( & V_219 , & V_220 ) )
return V_221 ;
}
}
}
