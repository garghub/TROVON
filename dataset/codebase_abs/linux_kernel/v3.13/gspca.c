static void F_1 ( struct V_1 * V_1 , int V_2 , char * V_3 ,
T_1 V_4 , int V_5 , int V_6 )
{
if ( ( V_4 >> 24 ) >= '0' && ( V_4 >> 24 ) <= 'z' ) {
F_2 ( V_2 , L_1 ,
V_3 ,
V_4 & 0xff ,
( V_4 >> 8 ) & 0xff ,
( V_4 >> 16 ) & 0xff ,
V_4 >> 24 ,
V_5 , V_6 ) ;
} else {
F_2 ( V_2 , L_2 ,
V_3 ,
V_4 ,
V_5 , V_6 ) ;
}
}
static void F_3 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
V_10 -> V_12 ++ ;
V_10 -> V_13 . V_14 |= V_15 ;
}
static void F_4 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
if ( -- V_10 -> V_12 <= 0 )
V_10 -> V_13 . V_14 &= ~ V_15 ;
}
static void F_5 ( struct V_16 * V_16 )
{
struct V_1 * V_1 = (struct V_1 * ) V_16 -> V_17 ;
int V_18 ;
V_18 = V_16 -> V_19 ;
switch ( V_18 ) {
case 0 :
if ( V_1 -> V_20 -> V_21 ( V_1 ,
V_16 -> V_22 , V_16 -> V_23 ) < 0 ) {
F_6 ( L_3 ) ;
}
break;
case - V_24 :
case - V_25 :
case - V_26 :
case - V_27 :
break;
default:
F_6 ( L_4 , V_16 -> V_19 ) ;
V_16 -> V_19 = 0 ;
V_18 = 0 ;
}
if ( V_18 == 0 ) {
V_18 = F_7 ( V_16 , V_28 ) ;
if ( V_18 < 0 )
F_8 ( L_5 , V_18 ) ;
}
}
static int F_9 ( struct V_1 * V_29 )
{
struct V_30 * V_30 ;
int V_31 = 0 ;
V_29 -> V_30 = NULL ;
if ( V_29 -> V_20 -> V_21 || V_29 -> V_20 -> V_32 ) {
V_30 = F_10 () ;
if ( ! V_30 )
return - V_33 ;
F_11 ( V_29 -> V_29 , V_29 -> V_34 , sizeof( V_29 -> V_34 ) ) ;
F_12 ( V_29 -> V_34 , L_6 , sizeof( V_29 -> V_34 ) ) ;
V_30 -> V_35 = V_29 -> V_20 -> V_35 ;
V_30 -> V_34 = V_29 -> V_34 ;
F_13 ( V_29 -> V_29 , & V_30 -> V_36 ) ;
V_30 -> V_37 [ 0 ] = F_14 ( V_38 ) ;
V_30 -> V_39 [ F_15 ( V_40 ) ] = F_14 ( V_40 ) ;
V_30 -> V_29 . V_41 = & V_29 -> V_29 -> V_29 ;
V_31 = F_16 ( V_30 ) ;
if ( V_31 ) {
F_8 ( L_7 ,
V_31 ) ;
V_30 -> V_29 . V_41 = NULL ;
F_17 ( V_30 ) ;
} else {
V_29 -> V_30 = V_30 ;
}
}
return V_31 ;
}
static int F_18 ( struct V_1 * V_1 ,
struct V_42 * V_43 )
{
unsigned int V_44 ;
int V_45 ;
struct V_16 * V_16 ;
struct V_46 * V_29 ;
void * V_47 = NULL ;
int V_18 = - V_48 ;
V_44 = F_19 ( V_43 -> V_49 ) ;
V_45 = V_43 -> V_50 ;
F_2 ( V_51 , L_8
L_9 ,
V_43 -> V_52 , V_44 , V_45 ) ;
V_29 = V_1 -> V_29 ;
V_16 = F_20 ( 0 , V_53 ) ;
if ( ! V_16 ) {
V_18 = - V_33 ;
goto error;
}
V_47 = F_21 ( V_29 , V_44 ,
V_53 , & V_16 -> V_54 ) ;
if ( ! V_47 ) {
V_18 = - V_33 ;
goto V_55;
}
F_22 ( V_16 , V_29 ,
F_23 ( V_29 , V_43 -> V_52 ) ,
V_47 , V_44 ,
F_5 , ( void * ) V_1 , V_45 ) ;
V_16 -> V_56 |= V_57 ;
V_18 = F_7 ( V_16 , V_53 ) ;
if ( V_18 < 0 ) {
F_6 ( L_10 , V_18 ) ;
goto V_58;
}
V_1 -> V_59 = V_16 ;
return V_18 ;
V_58:
F_24 ( V_29 ,
V_16 -> V_60 ,
V_16 -> V_22 ,
V_16 -> V_54 ) ;
V_55:
F_25 ( V_16 ) ;
error:
return V_18 ;
}
static void F_26 ( struct V_1 * V_1 )
{
struct V_61 * V_62 ;
struct V_63 * V_64 ;
struct V_42 * V_43 ;
int V_65 ;
if ( V_1 -> V_20 -> V_21 ) {
V_62 = F_27 ( V_1 -> V_29 , V_1 -> V_66 ) ;
V_64 = V_62 -> V_67 ;
for ( V_65 = 0 ; V_65 < V_64 -> V_68 . V_69 ; V_65 ++ ) {
V_43 = & V_64 -> V_70 [ V_65 ] . V_68 ;
if ( F_28 ( V_43 ) &&
F_29 ( V_43 ) ) {
F_18 ( V_1 , V_43 ) ;
break;
}
}
}
}
static void F_30 ( struct V_1 * V_1 )
{
struct V_16 * V_16 ;
V_16 = V_1 -> V_59 ;
if ( V_16 ) {
V_1 -> V_59 = NULL ;
F_31 ( V_16 ) ;
F_24 ( V_1 -> V_29 ,
V_16 -> V_60 ,
V_16 -> V_22 ,
V_16 -> V_54 ) ;
F_25 ( V_16 ) ;
}
}
static inline void F_30 ( struct V_1 * V_1 )
{
}
static inline void F_26 ( struct V_1 * V_1 )
{
}
static inline int F_9 ( struct V_1 * V_29 )
{
return 0 ;
}
static void F_32 ( struct V_1 * V_1 ,
struct V_16 * V_16 )
{
T_2 * V_71 ;
int V_65 , V_72 , V_73 ;
T_3 V_74 ;
if ( V_16 -> V_19 != 0 ) {
if ( V_16 -> V_19 == - V_27 )
return;
#ifdef F_33
if ( V_1 -> V_75 )
return;
#endif
F_6 ( L_11 , V_16 -> V_19 ) ;
V_16 -> V_19 = 0 ;
goto V_76;
}
V_74 = V_1 -> V_20 -> V_74 ;
for ( V_65 = 0 ; V_65 < V_16 -> V_77 ; V_65 ++ ) {
V_72 = V_16 -> V_78 [ V_65 ] . V_23 ;
V_73 = V_16 -> V_78 [ V_65 ] . V_19 ;
if ( V_73 ) {
F_8 ( L_12 ,
V_65 , V_72 , V_73 ) ;
V_1 -> V_79 = V_80 ;
continue;
}
if ( V_72 == 0 ) {
if ( V_1 -> V_81 == 0 )
V_1 -> V_81 = 1 ;
continue;
}
F_2 ( V_82 , L_13 ,
V_65 , V_16 -> V_78 [ V_65 ] . V_83 , V_72 ) ;
V_71 = ( T_2 * ) V_16 -> V_22
+ V_16 -> V_78 [ V_65 ] . V_83 ;
V_74 ( V_1 , V_71 , V_72 ) ;
}
V_76:
V_73 = F_7 ( V_16 , V_28 ) ;
if ( V_73 < 0 )
F_8 ( L_14 , V_73 ) ;
}
static void F_34 ( struct V_16 * V_16 )
{
struct V_1 * V_1 = (struct V_1 * ) V_16 -> V_17 ;
F_2 ( V_82 , L_15 ) ;
if ( ! V_1 -> V_84 )
return;
F_32 ( V_1 , V_16 ) ;
}
static void F_35 ( struct V_16 * V_16 )
{
struct V_1 * V_1 = (struct V_1 * ) V_16 -> V_17 ;
int V_73 ;
F_2 ( V_82 , L_16 ) ;
if ( ! V_1 -> V_84 )
return;
switch ( V_16 -> V_19 ) {
case 0 :
break;
case - V_27 :
return;
default:
#ifdef F_33
if ( V_1 -> V_75 )
return;
#endif
F_6 ( L_11 , V_16 -> V_19 ) ;
V_16 -> V_19 = 0 ;
goto V_76;
}
F_2 ( V_82 , L_17 , V_16 -> V_23 ) ;
V_1 -> V_20 -> V_74 ( V_1 ,
V_16 -> V_22 ,
V_16 -> V_23 ) ;
V_76:
if ( V_1 -> V_85 . V_86 != 0 ) {
V_73 = F_7 ( V_16 , V_28 ) ;
if ( V_73 < 0 )
F_8 ( L_14 , V_73 ) ;
}
}
void F_36 ( struct V_1 * V_1 ,
enum V_87 V_88 ,
const T_2 * V_71 ,
int V_72 )
{
struct V_9 * V_10 ;
int V_65 , V_89 ;
F_2 ( V_82 , L_18 , V_88 , V_72 ) ;
if ( V_88 == V_90 ) {
V_65 = F_37 ( & V_1 -> V_91 ) ;
if ( V_65 == F_37 ( & V_1 -> V_92 ) ) {
V_1 -> V_79 = V_80 ;
V_1 -> V_93 ++ ;
return;
}
V_89 = V_1 -> V_94 [ V_65 ] ;
V_10 = & V_1 -> V_10 [ V_89 ] ;
V_10 -> V_13 . V_95 = F_38 ( F_39 () ) ;
V_10 -> V_13 . V_93 = V_1 -> V_93 ++ ;
V_1 -> V_96 = V_10 -> V_71 ;
V_1 -> V_97 = 0 ;
} else {
switch ( V_1 -> V_79 ) {
case V_80 :
if ( V_88 == V_98 ) {
V_1 -> V_79 = V_88 ;
V_1 -> V_96 = NULL ;
V_1 -> V_97 = 0 ;
}
return;
case V_98 :
return;
}
}
if ( V_72 > 0 ) {
if ( V_1 -> V_97 + V_72 > V_1 -> V_99 ) {
F_6 ( L_19 ,
V_1 -> V_97 + V_72 ,
V_1 -> V_99 ) ;
V_88 = V_80 ;
} else {
memcpy ( V_1 -> V_96 + V_1 -> V_97 ,
V_71 , V_72 ) ;
V_1 -> V_97 += V_72 ;
}
}
V_1 -> V_79 = V_88 ;
if ( V_88 == V_98 ) {
V_65 = F_37 ( & V_1 -> V_91 ) ;
V_89 = V_1 -> V_94 [ V_65 ] ;
V_10 = & V_1 -> V_10 [ V_89 ] ;
V_10 -> V_13 . V_100 = V_1 -> V_97 ;
V_10 -> V_13 . V_14 = ( V_10 -> V_13 . V_14
| V_101 )
& ~ V_102 ;
V_65 = ( V_65 + 1 ) % V_103 ;
F_40 ( & V_1 -> V_91 , V_65 ) ;
F_41 ( & V_1 -> V_104 ) ;
F_2 ( V_105 , L_20 ,
V_10 -> V_13 . V_100 ) ;
V_1 -> V_96 = NULL ;
V_1 -> V_97 = 0 ;
}
}
static int F_42 ( struct V_1 * V_1 , struct V_106 * V_106 ,
enum V_107 V_108 , unsigned int V_109 )
{
struct V_9 * V_10 ;
unsigned int V_99 ;
int V_65 ;
V_99 = V_1 -> V_4 . V_110 ;
F_2 ( V_111 , L_21 , V_99 ) ;
V_99 = F_43 ( V_99 ) ;
if ( V_109 >= V_103 )
V_109 = V_103 - 1 ;
V_1 -> V_112 = F_44 ( V_99 * V_109 ) ;
if ( ! V_1 -> V_112 ) {
F_8 ( L_22 ) ;
return - V_33 ;
}
V_1 -> V_113 = V_106 ;
V_1 -> V_108 = V_108 ;
V_1 -> V_99 = V_99 ;
V_1 -> V_114 = V_109 ;
for ( V_65 = 0 ; V_65 < V_109 ; V_65 ++ ) {
V_10 = & V_1 -> V_10 [ V_65 ] ;
V_10 -> V_13 . V_115 = V_65 ;
V_10 -> V_13 . type = V_116 ;
V_10 -> V_13 . V_14 = 0 ;
V_10 -> V_13 . V_117 = V_118 ;
V_10 -> V_13 . V_119 = V_99 ;
V_10 -> V_13 . V_108 = V_108 ;
V_10 -> V_13 . V_93 = 0 ;
V_10 -> V_71 = V_1 -> V_112 + V_65 * V_99 ;
V_10 -> V_13 . V_120 . V_83 = V_65 * V_99 ;
}
F_40 ( & V_1 -> V_92 , 0 ) ;
F_40 ( & V_1 -> V_91 , 0 ) ;
V_1 -> V_121 = 0 ;
return 0 ;
}
static void F_45 ( struct V_1 * V_1 )
{
int V_65 ;
F_2 ( V_111 , L_23 ) ;
if ( V_1 -> V_112 != NULL ) {
F_46 ( V_1 -> V_112 ) ;
V_1 -> V_112 = NULL ;
for ( V_65 = 0 ; V_65 < V_1 -> V_114 ; V_65 ++ )
V_1 -> V_10 [ V_65 ] . V_71 = NULL ;
}
V_1 -> V_114 = 0 ;
V_1 -> V_99 = 0 ;
V_1 -> V_113 = NULL ;
V_1 -> V_108 = V_122 ;
}
static void F_47 ( struct V_1 * V_1 )
{
struct V_16 * V_16 ;
unsigned int V_65 ;
F_2 ( V_111 , L_24 ) ;
for ( V_65 = 0 ; V_65 < V_123 ; V_65 ++ ) {
V_16 = V_1 -> V_16 [ V_65 ] ;
if ( V_16 == NULL )
break;
V_1 -> V_16 [ V_65 ] = NULL ;
F_31 ( V_16 ) ;
F_24 ( V_1 -> V_29 ,
V_16 -> V_60 ,
V_16 -> V_22 ,
V_16 -> V_54 ) ;
F_25 ( V_16 ) ;
}
}
static int F_48 ( struct V_1 * V_1 )
{
int V_18 ;
if ( V_1 -> V_124 == 0 )
return 0 ;
V_18 = F_49 ( V_1 -> V_29 , V_1 -> V_66 , 0 ) ;
if ( V_18 < 0 )
F_8 ( L_25 , V_18 ) ;
return V_18 ;
}
static void F_50 ( struct V_1 * V_1 )
{
V_1 -> V_84 = 0 ;
V_1 -> V_125 = 0 ;
if ( V_1 -> V_20 -> V_126 )
V_1 -> V_20 -> V_126 ( V_1 ) ;
F_47 ( V_1 ) ;
F_30 ( V_1 ) ;
F_48 ( V_1 ) ;
F_26 ( V_1 ) ;
if ( V_1 -> V_20 -> V_127 )
V_1 -> V_20 -> V_127 ( V_1 ) ;
F_2 ( V_111 , L_26 ) ;
}
static struct V_128 * F_51 ( struct V_63 * V_124 ,
int V_129 )
{
struct V_128 * V_43 ;
int V_65 , V_130 ;
for ( V_65 = 0 ; V_65 < V_124 -> V_68 . V_69 ; V_65 ++ ) {
V_43 = & V_124 -> V_70 [ V_65 ] ;
V_130 = V_43 -> V_68 . V_131 & V_132 ;
if ( V_130 == V_129
&& V_43 -> V_68 . V_49 != 0
&& F_28 ( & V_43 -> V_68 ) )
return V_43 ;
}
return NULL ;
}
static T_4 F_52 ( struct V_1 * V_1 )
{
T_4 V_133 ;
V_133 = V_1 -> V_4 . V_110 ;
if ( ! V_1 -> V_85 . V_134 &&
V_133 < V_1 -> V_4 . V_135 *
V_1 -> V_4 . V_136 )
V_133 = V_133 * 3 / 8 ;
if ( V_1 -> V_20 -> V_137 ) {
struct V_138 V_139 ;
V_1 -> V_20 -> V_137 ( V_1 , & V_139 ) ;
V_133 *= V_139 . V_139 . V_140 . V_141 . V_142 ;
V_133 /= V_139 . V_139 . V_140 . V_141 . V_143 ;
} else {
if ( V_1 -> V_4 . V_135 >= 640
&& V_1 -> V_29 -> V_144 == V_145 )
V_133 *= 15 ;
else
V_133 *= 30 ;
}
F_2 ( V_111 , L_27 , V_133 ) ;
return V_133 ;
}
static int F_53 ( struct V_1 * V_1 ,
struct V_61 * V_62 ,
struct V_146 * V_147 )
{
struct V_128 * V_43 ;
int V_65 , V_89 , V_148 , V_149 , V_150 ;
T_4 V_133 , V_151 ;
V_148 = V_62 -> V_152 ;
if ( V_148 > V_153 )
V_148 = V_153 ;
V_65 = 0 ;
V_151 = 0 ;
for (; ; ) {
V_147 -> V_133 = 2000 * 2000 * 120 ;
V_150 = 0 ;
for ( V_89 = 0 ; V_89 < V_148 ; V_89 ++ ) {
V_43 = F_51 ( & V_62 -> V_154 [ V_89 ] ,
V_155 ) ;
if ( V_43 == NULL )
continue;
if ( V_43 -> V_68 . V_50 == 0 ) {
F_8 ( L_28 , V_89 ) ;
continue;
}
V_149 = F_19 ( V_43 -> V_68 . V_49 ) ;
V_149 = ( V_149 & 0x07ff ) * ( 1 + ( ( V_149 >> 11 ) & 3 ) ) ;
V_133 = V_149 * 1000 ;
if ( V_1 -> V_29 -> V_144 == V_156
|| V_1 -> V_29 -> V_144 == V_157 )
V_133 *= 8 ;
V_133 /= 1 << ( V_43 -> V_68 . V_50 - 1 ) ;
if ( V_133 <= V_151 )
continue;
if ( V_133 < V_147 -> V_133 ) {
V_147 -> V_133 = V_133 ;
V_147 -> V_124 = V_89 ;
V_150 = 1 ;
}
}
if ( ! V_150 )
break;
F_2 ( V_111 , L_29 ,
V_147 -> V_124 , V_147 -> V_133 ) ;
V_151 = V_147 -> V_133 ;
V_65 ++ ;
V_147 ++ ;
}
if ( V_1 -> V_158 &&
V_1 -> V_29 -> V_144 == V_145 &&
V_151 >= 1000000 &&
V_65 > 1 ) {
F_2 ( V_111 , L_30 ) ;
V_65 -- ;
V_147 -- ;
}
V_133 = F_52 ( V_1 ) ;
V_147 -- ;
while ( V_65 > 1 ) {
V_147 -- ;
if ( V_147 -> V_133 < V_133 )
break;
V_65 -- ;
}
return V_65 ;
}
static int F_54 ( struct V_1 * V_1 ,
struct V_128 * V_43 )
{
struct V_16 * V_16 ;
int V_159 , V_160 , V_65 , V_149 , V_161 , V_162 ;
V_149 = F_19 ( V_43 -> V_68 . V_49 ) ;
if ( ! V_1 -> V_85 . V_163 ) {
if ( V_1 -> V_164 == 0 )
V_149 = ( V_149 & 0x07ff ) * ( 1 + ( ( V_149 >> 11 ) & 3 ) ) ;
else
V_149 = V_1 -> V_164 ;
V_161 = V_1 -> V_85 . V_161 ;
if ( V_161 == 0 )
V_161 = 32 ;
V_162 = V_149 * V_161 ;
F_2 ( V_111 ,
L_31 ,
V_161 , V_149 , V_162 ) ;
V_160 = V_165 ;
} else {
V_161 = 0 ;
V_162 = V_1 -> V_85 . V_166 ;
if ( V_162 == 0 )
V_162 = V_149 ;
F_2 ( V_111 , L_32 , V_162 ) ;
if ( V_1 -> V_85 . V_86 != 0 )
V_160 = V_1 -> V_85 . V_86 ;
else
V_160 = 1 ;
}
for ( V_159 = 0 ; V_159 < V_160 ; V_159 ++ ) {
V_16 = F_20 ( V_161 , V_53 ) ;
if ( ! V_16 ) {
F_8 ( L_33 ) ;
return - V_33 ;
}
V_1 -> V_16 [ V_159 ] = V_16 ;
V_16 -> V_22 = F_21 ( V_1 -> V_29 ,
V_162 ,
V_53 ,
& V_16 -> V_54 ) ;
if ( V_16 -> V_22 == NULL ) {
F_8 ( L_34 ) ;
return - V_33 ;
}
V_16 -> V_29 = V_1 -> V_29 ;
V_16 -> V_17 = V_1 ;
V_16 -> V_60 = V_162 ;
if ( V_161 != 0 ) {
V_16 -> V_167 = F_55 ( V_1 -> V_29 ,
V_43 -> V_68 . V_52 ) ;
V_16 -> V_56 = V_168
| V_57 ;
V_16 -> V_45 = 1 << ( V_43 -> V_68 . V_50 - 1 ) ;
V_16 -> V_169 = F_34 ;
V_16 -> V_77 = V_161 ;
for ( V_65 = 0 ; V_65 < V_161 ; V_65 ++ ) {
V_16 -> V_78 [ V_65 ] . V_119 = V_149 ;
V_16 -> V_78 [ V_65 ] . V_83 = V_149 * V_65 ;
}
} else {
V_16 -> V_167 = F_56 ( V_1 -> V_29 ,
V_43 -> V_68 . V_52 ) ;
V_16 -> V_56 = V_57 ;
V_16 -> V_169 = F_35 ;
}
}
return 0 ;
}
static int F_57 ( struct V_1 * V_1 )
{
struct V_61 * V_62 ;
struct V_128 * V_43 ;
struct V_16 * V_16 ;
struct V_146 V_147 [ V_153 ] ;
int V_159 , V_18 , V_129 , V_124 , V_170 ;
V_1 -> V_96 = NULL ;
V_1 -> V_97 = 0 ;
V_1 -> V_79 = V_80 ;
V_1 -> V_93 = 0 ;
V_1 -> V_125 = 0 ;
V_62 = F_27 ( V_1 -> V_29 , V_1 -> V_66 ) ;
V_1 -> V_124 = V_1 -> V_85 . V_163 ? V_62 -> V_152 : 0 ;
if ( V_1 -> V_20 -> V_171 ) {
V_18 = V_1 -> V_20 -> V_171 ( V_1 ) ;
if ( V_18 < 0 )
return V_18 ;
}
V_129 = V_1 -> V_85 . V_163 ? V_172
: V_155 ;
if ( V_1 -> V_124 != 0 ) {
V_1 -> V_124 -- ;
V_43 = F_51 ( & V_62 -> V_154 [ V_1 -> V_124 ] , V_129 ) ;
if ( V_43 == NULL ) {
F_8 ( L_35 , V_1 -> V_124 ) ;
return - V_173 ;
}
V_147 [ 0 ] . V_124 = V_1 -> V_124 ;
V_170 = 1 ;
} else {
V_170 = F_53 ( V_1 , V_62 , V_147 ) ;
if ( V_170 <= 0 ) {
F_8 ( L_36 ) ;
return - V_173 ;
}
}
F_30 ( V_1 ) ;
V_1 -> V_124 = V_147 [ -- V_170 ] . V_124 ;
V_124 = - 1 ;
for (; ; ) {
if ( V_124 != V_1 -> V_124 ) {
V_124 = V_1 -> V_124 ;
if ( V_62 -> V_152 > 1 ) {
V_18 = F_49 ( V_1 -> V_29 ,
V_1 -> V_66 ,
V_124 ) ;
if ( V_18 < 0 ) {
if ( V_18 == - V_174 )
goto V_175;
F_8 ( L_37 , V_124 , V_18 ) ;
goto V_176;
}
}
}
if ( ! V_1 -> V_85 . V_177 ) {
F_2 ( V_111 , L_38 , V_124 ) ;
V_18 = F_54 ( V_1 ,
F_51 ( & V_62 -> V_154 [ V_124 ] , V_129 ) ) ;
if ( V_18 < 0 ) {
F_47 ( V_1 ) ;
goto V_176;
}
}
if ( V_1 -> V_85 . V_163 )
F_58 ( V_1 -> V_29 ,
V_1 -> V_16 [ 0 ] -> V_167 ) ;
V_18 = V_1 -> V_20 -> V_178 ( V_1 ) ;
if ( V_18 < 0 ) {
F_47 ( V_1 ) ;
goto V_176;
}
V_1 -> V_84 = 1 ;
F_59 ( V_1 -> V_179 . V_180 ) ;
if ( V_1 -> V_85 . V_163 && V_1 -> V_85 . V_86 == 0 )
break;
for ( V_159 = 0 ; V_159 < V_123 ; V_159 ++ ) {
V_16 = V_1 -> V_16 [ V_159 ] ;
if ( V_16 == NULL )
break;
V_18 = F_7 ( V_16 , V_53 ) ;
if ( V_18 < 0 )
break;
}
if ( V_18 >= 0 )
break;
F_50 ( V_1 ) ;
if ( V_18 != - V_174 ) {
F_8 ( L_39 ,
V_1 -> V_124 , V_18 ) ;
goto V_176;
}
V_175:
F_6 ( L_40 , V_124 ) ;
F_60 ( 20 ) ;
if ( V_1 -> V_20 -> V_181 ) {
V_18 = V_1 -> V_20 -> V_181 ( V_1 ) ;
if ( V_18 < 0 )
goto V_176;
} else {
if ( V_170 <= 0 ) {
F_8 ( L_36 ) ;
V_18 = - V_173 ;
goto V_176;
}
V_1 -> V_124 = V_147 [ -- V_170 ] . V_124 ;
}
}
V_176:
F_26 ( V_1 ) ;
return V_18 ;
}
static void F_61 ( struct V_1 * V_1 )
{
int V_65 ;
V_65 = V_1 -> V_85 . V_182 - 1 ;
V_1 -> V_183 = V_65 ;
V_1 -> V_4 = V_1 -> V_85 . V_184 [ V_65 ] ;
F_59 ( V_1 -> V_179 . V_180 ) ;
}
static int F_62 ( struct V_1 * V_1 ,
int V_135 , int V_136 )
{
int V_65 ;
for ( V_65 = V_1 -> V_85 . V_182 ; -- V_65 > 0 ; ) {
if ( V_135 >= V_1 -> V_85 . V_184 [ V_65 ] . V_135
&& V_136 >= V_1 -> V_85 . V_184 [ V_65 ] . V_136 )
break;
}
return V_65 ;
}
static int F_63 ( struct V_1 * V_1 ,
int V_185 ,
int V_4 )
{
int V_186 , V_187 ;
V_186 = V_187 = V_185 ;
while ( ( V_186 < V_1 -> V_85 . V_182 ) || V_187 >= 0 ) {
if ( -- V_187 >= 0 ) {
if ( V_1 -> V_85 . V_184 [ V_187 ] . V_188
== V_4 )
return V_187 ;
}
if ( ++ V_186 < V_1 -> V_85 . V_182 ) {
if ( V_1 -> V_85 . V_184 [ V_186 ] . V_188
== V_4 )
return V_186 ;
}
}
return - V_48 ;
}
static int F_64 ( struct V_106 * V_106 , void * V_189 ,
struct V_190 * V_191 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
V_1 -> V_125 = 0 ;
if ( V_1 -> V_20 -> V_192 )
return V_1 -> V_20 -> V_192 ( V_1 , V_191 ) ;
return V_191 -> V_193 . V_194 ? - V_48 : 0 ;
}
static int F_66 ( struct V_106 * V_106 , void * V_189 ,
struct V_195 * V_196 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
V_1 -> V_125 = 0 ;
return V_1 -> V_20 -> V_197 ( V_1 , V_196 ) ;
}
static int F_67 ( struct V_106 * V_106 , void * V_189 ,
const struct V_195 * V_196 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
V_1 -> V_125 = 0 ;
return V_1 -> V_20 -> V_198 ( V_1 , V_196 ) ;
}
static int F_68 ( struct V_106 * V_106 , void * V_189 ,
struct V_199 * V_200 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
int V_65 , V_89 , V_115 ;
T_1 V_201 [ 8 ] ;
V_115 = 0 ;
V_89 = 0 ;
for ( V_65 = V_1 -> V_85 . V_182 ; -- V_65 >= 0 ; ) {
V_201 [ V_115 ] = V_1 -> V_85 . V_184 [ V_65 ] . V_188 ;
V_89 = 0 ;
for (; ; ) {
if ( V_201 [ V_89 ] == V_201 [ V_115 ] )
break;
V_89 ++ ;
}
if ( V_89 == V_115 ) {
if ( V_200 -> V_115 == V_115 )
break;
V_115 ++ ;
if ( V_115 >= F_69 ( V_201 ) )
return - V_48 ;
}
}
if ( V_65 < 0 )
return - V_48 ;
V_200 -> V_188 = V_201 [ V_115 ] ;
if ( V_1 -> V_85 . V_184 [ V_65 ] . V_110 <
V_1 -> V_85 . V_184 [ V_65 ] . V_135 *
V_1 -> V_85 . V_184 [ V_65 ] . V_136 )
V_200 -> V_14 = V_202 ;
V_200 -> V_203 [ 0 ] = V_200 -> V_188 & 0xff ;
V_200 -> V_203 [ 1 ] = ( V_200 -> V_188 >> 8 ) & 0xff ;
V_200 -> V_203 [ 2 ] = ( V_200 -> V_188 >> 16 ) & 0xff ;
V_200 -> V_203 [ 3 ] = V_200 -> V_188 >> 24 ;
V_200 -> V_203 [ 4 ] = '\0' ;
return 0 ;
}
static int F_70 ( struct V_106 * V_106 , void * V_189 ,
struct V_204 * V_205 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
V_205 -> V_205 . V_206 = V_1 -> V_4 ;
V_205 -> V_205 . V_206 . V_189 = 0 ;
return 0 ;
}
static int F_71 ( struct V_1 * V_1 ,
struct V_204 * V_205 )
{
int V_5 , V_6 , V_185 , V_207 ;
V_5 = V_205 -> V_205 . V_206 . V_135 ;
V_6 = V_205 -> V_205 . V_206 . V_136 ;
F_1 ( V_1 , V_51 , L_41 ,
V_205 -> V_205 . V_206 . V_188 , V_5 , V_6 ) ;
V_185 = F_62 ( V_1 , V_5 , V_6 ) ;
if ( V_1 -> V_85 . V_184 [ V_185 ] . V_188
!= V_205 -> V_205 . V_206 . V_188 ) {
V_207 = F_63 ( V_1 , V_185 ,
V_205 -> V_205 . V_206 . V_188 ) ;
if ( V_207 >= 0 )
V_185 = V_207 ;
}
V_205 -> V_205 . V_206 = V_1 -> V_85 . V_184 [ V_185 ] ;
if ( V_1 -> V_20 -> V_208 ) {
V_205 -> V_205 . V_206 . V_135 = V_5 ;
V_205 -> V_205 . V_206 . V_136 = V_6 ;
V_1 -> V_20 -> V_208 ( V_1 , V_205 ) ;
}
V_205 -> V_205 . V_206 . V_189 = 0 ;
return V_185 ;
}
static int F_72 ( struct V_106 * V_106 ,
void * V_189 ,
struct V_204 * V_205 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
int V_18 ;
V_18 = F_71 ( V_1 , V_205 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
}
static int F_73 ( struct V_106 * V_106 , void * V_189 ,
struct V_204 * V_205 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
int V_18 ;
if ( F_74 ( & V_1 -> V_209 ) )
return - V_210 ;
V_18 = F_71 ( V_1 , V_205 ) ;
if ( V_18 < 0 )
goto V_176;
if ( V_1 -> V_114 != 0
&& V_205 -> V_205 . V_206 . V_110 > V_1 -> V_99 ) {
V_18 = - V_48 ;
goto V_176;
}
if ( V_1 -> V_84 ) {
V_18 = - V_211 ;
goto V_176;
}
V_1 -> V_183 = V_18 ;
if ( V_1 -> V_20 -> V_208 )
V_1 -> V_4 = V_205 -> V_205 . V_206 ;
else
V_1 -> V_4 = V_1 -> V_85 . V_184 [ V_18 ] ;
V_18 = 0 ;
V_176:
F_75 ( & V_1 -> V_209 ) ;
return V_18 ;
}
static int F_76 ( struct V_106 * V_106 , void * V_189 ,
struct V_212 * V_213 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
int V_65 ;
T_1 V_115 = 0 ;
if ( V_1 -> V_20 -> V_214 )
return V_1 -> V_20 -> V_214 ( V_1 , V_213 ) ;
for ( V_65 = 0 ; V_65 < V_1 -> V_85 . V_182 ; V_65 ++ ) {
if ( V_213 -> V_215 !=
V_1 -> V_85 . V_184 [ V_65 ] . V_188 )
continue;
if ( V_213 -> V_115 == V_115 ) {
V_213 -> type = V_216 ;
V_213 -> V_217 . V_135 =
V_1 -> V_85 . V_184 [ V_65 ] . V_135 ;
V_213 -> V_217 . V_136 =
V_1 -> V_85 . V_184 [ V_65 ] . V_136 ;
return 0 ;
}
V_115 ++ ;
}
return - V_48 ;
}
static int F_77 ( struct V_106 * V_218 , void * V_189 ,
struct V_219 * V_220 )
{
struct V_1 * V_1 = F_65 ( V_218 ) ;
int V_185 = F_62 ( V_1 , V_220 -> V_135 , V_220 -> V_136 ) ;
T_1 V_65 ;
if ( V_1 -> V_85 . V_221 == NULL ||
V_1 -> V_85 . V_221 [ V_185 ] . V_222 == 0 )
return - V_48 ;
if ( V_220 -> V_215 !=
V_1 -> V_85 . V_184 [ V_185 ] . V_188 )
return - V_48 ;
for ( V_65 = 0 ; V_65 < V_1 -> V_85 . V_221 [ V_185 ] . V_222 ; V_65 ++ ) {
if ( V_220 -> V_115 == V_65 ) {
V_220 -> type = V_216 ;
V_220 -> V_217 . V_143 = 1 ;
V_220 -> V_217 . V_142 =
V_1 -> V_85 . V_221 [ V_185 ] . V_223 [ V_65 ] ;
return 0 ;
}
}
return - V_48 ;
}
static void F_78 ( struct V_224 * V_224 )
{
struct V_1 * V_1 =
F_79 ( V_224 , struct V_1 , V_225 ) ;
F_80 ( V_1 -> V_179 . V_180 ) ;
F_81 ( & V_1 -> V_225 ) ;
F_82 ( V_1 -> V_226 ) ;
F_82 ( V_1 ) ;
}
static int F_83 ( struct V_106 * V_106 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
int V_18 ;
F_2 ( V_111 , L_42 , V_227 -> V_228 ) ;
if ( ! F_84 ( V_1 -> V_229 ) )
return - V_26 ;
V_18 = F_85 ( V_106 ) ;
if ( V_18 )
F_86 ( V_1 -> V_229 ) ;
return V_18 ;
}
static int F_87 ( struct V_106 * V_106 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
F_2 ( V_111 , L_43 , V_227 -> V_228 ) ;
if ( F_74 ( & V_1 -> V_230 ) )
return - V_210 ;
if ( F_74 ( & V_1 -> V_209 ) ) {
F_75 ( & V_1 -> V_230 ) ;
return - V_210 ;
}
if ( V_1 -> V_113 == V_106 ) {
if ( V_1 -> V_84 )
F_50 ( V_1 ) ;
F_45 ( V_1 ) ;
}
F_86 ( V_1 -> V_229 ) ;
F_75 ( & V_1 -> V_209 ) ;
F_75 ( & V_1 -> V_230 ) ;
F_2 ( V_111 , L_44 ) ;
return F_88 ( V_106 ) ;
}
static int F_89 ( struct V_106 * V_106 , void * V_189 ,
struct V_231 * V_232 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
F_90 ( ( char * ) V_232 -> V_233 , V_1 -> V_20 -> V_35 ,
sizeof V_232 -> V_233 ) ;
if ( V_1 -> V_29 -> V_234 != NULL ) {
F_90 ( ( char * ) V_232 -> V_235 , V_1 -> V_29 -> V_234 ,
sizeof V_232 -> V_235 ) ;
} else {
snprintf ( ( char * ) V_232 -> V_235 , sizeof V_232 -> V_235 ,
L_45 ,
F_19 ( V_1 -> V_29 -> V_236 . V_237 ) ,
F_19 ( V_1 -> V_29 -> V_236 . V_238 ) ) ;
}
F_11 ( V_1 -> V_29 , ( char * ) V_232 -> V_239 ,
sizeof( V_232 -> V_239 ) ) ;
V_232 -> V_240 = V_241
| V_242
| V_243 ;
V_232 -> V_244 = V_232 -> V_240 | V_245 ;
return 0 ;
}
static int F_91 ( struct V_106 * V_106 , void * V_189 ,
struct V_246 * V_247 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
if ( V_247 -> V_115 != 0 )
return - V_48 ;
V_247 -> type = V_248 ;
V_247 -> V_19 = V_1 -> V_85 . V_249 ;
F_90 ( V_247 -> V_35 , V_1 -> V_20 -> V_35 ,
sizeof V_247 -> V_35 ) ;
return 0 ;
}
static int F_92 ( struct V_106 * V_106 , void * V_189 , unsigned int * V_65 )
{
* V_65 = 0 ;
return 0 ;
}
static int F_93 ( struct V_106 * V_106 , void * V_189 , unsigned int V_65 )
{
if ( V_65 > 0 )
return - V_48 ;
return ( 0 ) ;
}
static int F_94 ( struct V_106 * V_106 , void * V_189 ,
struct V_250 * V_251 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
int V_65 , V_18 = 0 , V_84 ;
V_65 = V_251 -> V_108 ;
switch ( V_65 ) {
case V_252 :
case V_253 :
case V_254 :
break;
default:
return - V_48 ;
}
if ( F_74 ( & V_1 -> V_209 ) )
return - V_210 ;
if ( V_1 -> V_108 != V_122
&& V_1 -> V_108 != V_252
&& V_1 -> V_108 != V_251 -> V_108 ) {
V_18 = - V_211 ;
goto V_176;
}
if ( V_1 -> V_113 != NULL
&& V_1 -> V_113 != V_106 ) {
V_18 = - V_211 ;
goto V_176;
}
for ( V_65 = 0 ; V_65 < V_1 -> V_114 ; V_65 ++ ) {
if ( V_1 -> V_10 [ V_65 ] . V_12 ) {
V_18 = - V_211 ;
goto V_176;
}
}
V_84 = V_1 -> V_84 ;
if ( V_84 ) {
F_50 ( V_1 ) ;
if ( V_1 -> V_108 == V_252 )
V_84 = 0 ;
}
if ( V_1 -> V_114 != 0 )
F_45 ( V_1 ) ;
if ( V_251 -> V_109 == 0 )
goto V_176;
V_18 = F_42 ( V_1 , V_106 , V_251 -> V_108 , V_251 -> V_109 ) ;
if ( V_18 == 0 ) {
V_251 -> V_109 = V_1 -> V_114 ;
if ( V_84 )
V_18 = F_57 ( V_1 ) ;
}
V_176:
F_75 ( & V_1 -> V_209 ) ;
F_2 ( V_111 , L_46 , V_18 , V_251 -> V_109 ) ;
return V_18 ;
}
static int F_95 ( struct V_106 * V_106 , void * V_189 ,
struct V_255 * V_13 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
struct V_9 * V_10 ;
if ( V_13 -> V_115 >= V_1 -> V_114 )
return - V_48 ;
V_10 = & V_1 -> V_10 [ V_13 -> V_115 ] ;
memcpy ( V_13 , & V_10 -> V_13 , sizeof *V_13 ) ;
return 0 ;
}
static int F_96 ( struct V_106 * V_106 , void * V_189 ,
enum V_256 V_257 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
int V_18 ;
if ( V_257 != V_116 )
return - V_48 ;
if ( F_74 ( & V_1 -> V_209 ) )
return - V_210 ;
if ( V_1 -> V_113 != V_106 ) {
V_18 = - V_211 ;
goto V_176;
}
if ( V_1 -> V_114 == 0
|| ! ( V_1 -> V_10 [ 0 ] . V_13 . V_14 & V_102 ) ) {
V_18 = - V_48 ;
goto V_176;
}
if ( ! V_1 -> V_84 ) {
V_18 = F_57 ( V_1 ) ;
if ( V_18 < 0 )
goto V_176;
}
F_1 ( V_1 , V_111 , L_47 ,
V_1 -> V_4 . V_188 ,
V_1 -> V_4 . V_135 , V_1 -> V_4 . V_136 ) ;
V_18 = 0 ;
V_176:
F_75 ( & V_1 -> V_209 ) ;
return V_18 ;
}
static int F_97 ( struct V_106 * V_106 , void * V_189 ,
enum V_256 V_257 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
int V_65 , V_18 ;
if ( V_257 != V_116 )
return - V_48 ;
if ( F_74 ( & V_1 -> V_209 ) )
return - V_210 ;
if ( ! V_1 -> V_84 ) {
V_18 = 0 ;
goto V_176;
}
if ( V_1 -> V_113 != V_106 ) {
V_18 = - V_211 ;
goto V_176;
}
F_50 ( V_1 ) ;
F_41 ( & V_1 -> V_104 ) ;
for ( V_65 = 0 ; V_65 < V_1 -> V_114 ; V_65 ++ )
V_1 -> V_10 [ V_65 ] . V_13 . V_14 &= ~ V_258 ;
F_40 ( & V_1 -> V_92 , 0 ) ;
F_40 ( & V_1 -> V_91 , 0 ) ;
V_1 -> V_121 = 0 ;
V_18 = 0 ;
V_176:
F_75 ( & V_1 -> V_209 ) ;
return V_18 ;
}
static int F_98 ( struct V_106 * V_106 , void * V_189 ,
struct V_259 * V_260 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
V_1 -> V_125 = 0 ;
return V_1 -> V_20 -> V_261 ( V_1 , V_260 ) ;
}
static int F_99 ( struct V_106 * V_106 , void * V_189 ,
const struct V_259 * V_260 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
V_1 -> V_125 = 0 ;
return V_1 -> V_20 -> V_262 ( V_1 , V_260 ) ;
}
static int F_100 ( struct V_106 * V_218 , void * V_189 ,
struct V_138 * V_139 )
{
struct V_1 * V_1 = F_65 ( V_218 ) ;
V_139 -> V_139 . V_140 . V_263 = V_1 -> V_264 ;
if ( V_1 -> V_20 -> V_137 ) {
V_1 -> V_125 = 0 ;
V_1 -> V_20 -> V_137 ( V_1 , V_139 ) ;
return V_1 -> V_125 ;
}
return 0 ;
}
static int F_101 ( struct V_106 * V_218 , void * V_189 ,
struct V_138 * V_139 )
{
struct V_1 * V_1 = F_65 ( V_218 ) ;
int V_159 ;
V_159 = V_139 -> V_139 . V_140 . V_263 ;
if ( V_159 == 0 || V_159 >= V_103 )
V_139 -> V_139 . V_140 . V_263 = V_1 -> V_264 ;
else
V_1 -> V_264 = V_159 ;
if ( V_1 -> V_20 -> V_265 ) {
V_1 -> V_125 = 0 ;
V_1 -> V_20 -> V_265 ( V_1 , V_139 ) ;
return V_1 -> V_125 ;
}
return 0 ;
}
static int F_102 ( struct V_106 * V_106 , struct V_7 * V_8 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
struct V_9 * V_10 ;
struct V_266 * V_266 ;
unsigned long V_194 , V_178 , V_267 ;
int V_65 , V_18 ;
V_178 = V_8 -> V_268 ;
V_267 = V_8 -> V_269 - V_8 -> V_268 ;
F_2 ( V_111 , L_48 , ( int ) V_178 , ( int ) V_267 ) ;
if ( F_74 ( & V_1 -> V_209 ) )
return - V_210 ;
if ( V_1 -> V_113 != V_106 ) {
V_18 = - V_48 ;
goto V_176;
}
V_10 = NULL ;
for ( V_65 = 0 ; V_65 < V_1 -> V_114 ; ++ V_65 ) {
if ( V_1 -> V_10 [ V_65 ] . V_13 . V_108 != V_253 ) {
F_2 ( V_111 , L_49 ) ;
break;
}
if ( ( V_1 -> V_10 [ V_65 ] . V_13 . V_120 . V_83 >> V_270 )
== V_8 -> V_271 ) {
V_10 = & V_1 -> V_10 [ V_65 ] ;
break;
}
}
if ( V_10 == NULL ) {
F_2 ( V_111 , L_50 ) ;
V_18 = - V_48 ;
goto V_176;
}
if ( V_267 != V_10 -> V_13 . V_119 ) {
F_2 ( V_111 , L_51 ) ;
V_18 = - V_48 ;
goto V_176;
}
V_8 -> V_272 |= V_273 ;
V_194 = ( unsigned long ) V_10 -> V_71 ;
while ( V_267 > 0 ) {
V_266 = F_103 ( ( void * ) V_194 ) ;
V_18 = F_104 ( V_8 , V_178 , V_266 ) ;
if ( V_18 < 0 )
goto V_176;
V_178 += V_274 ;
V_194 += V_274 ;
V_267 -= V_274 ;
}
V_8 -> V_275 = & V_276 ;
V_8 -> V_11 = V_10 ;
F_3 ( V_8 ) ;
V_18 = 0 ;
V_176:
F_75 ( & V_1 -> V_209 ) ;
return V_18 ;
}
static int F_105 ( struct V_1 * V_1 , struct V_106 * V_106 ,
enum V_107 V_108 )
{
if ( ! V_1 -> V_277 )
return - V_26 ;
if ( V_1 -> V_113 != V_106 || V_1 -> V_108 != V_108 ||
! V_1 -> V_84 )
return - V_48 ;
return V_1 -> V_121 != F_37 ( & V_1 -> V_91 ) ;
}
static int F_106 ( struct V_1 * V_1 , struct V_106 * V_106 ,
enum V_107 V_108 )
{
int V_18 ;
if ( F_74 ( & V_1 -> V_209 ) )
return - V_210 ;
V_18 = F_105 ( V_1 , V_106 , V_108 ) ;
F_75 ( & V_1 -> V_209 ) ;
return V_18 ;
}
static int F_107 ( struct V_106 * V_106 , void * V_189 ,
struct V_255 * V_13 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
struct V_9 * V_10 ;
int V_65 , V_89 , V_18 ;
F_2 ( V_105 , L_52 ) ;
if ( F_74 ( & V_1 -> V_209 ) )
return - V_210 ;
for (; ; ) {
V_18 = F_105 ( V_1 , V_106 , V_13 -> V_108 ) ;
if ( V_18 < 0 )
goto V_176;
if ( V_18 > 0 )
break;
F_75 ( & V_1 -> V_209 ) ;
if ( V_106 -> V_278 & V_279 )
return - V_280 ;
V_18 = F_108 ( V_1 -> V_104 ,
F_106 ( V_1 , V_106 , V_13 -> V_108 ) ,
F_109 ( 3000 ) ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_18 == 0 )
return - V_173 ;
if ( F_74 ( & V_1 -> V_209 ) )
return - V_210 ;
}
V_65 = V_1 -> V_121 ;
V_89 = V_1 -> V_94 [ V_65 ] ;
V_10 = & V_1 -> V_10 [ V_89 ] ;
V_1 -> V_121 = ( V_65 + 1 ) % V_103 ;
V_10 -> V_13 . V_14 &= ~ V_101 ;
memcpy ( V_13 , & V_10 -> V_13 , sizeof *V_13 ) ;
F_2 ( V_105 , L_53 , V_89 ) ;
V_18 = 0 ;
if ( V_1 -> V_108 == V_254 ) {
if ( F_110 ( ( V_281 V_282 * ) V_10 -> V_13 . V_120 . V_283 ,
V_10 -> V_71 ,
V_10 -> V_13 . V_100 ) ) {
F_6 ( L_54 ) ;
V_18 = - V_284 ;
}
}
V_176:
F_75 ( & V_1 -> V_209 ) ;
if ( V_18 == 0 && V_1 -> V_20 -> V_285 ) {
F_111 ( & V_1 -> V_230 ) ;
V_1 -> V_125 = 0 ;
if ( V_1 -> V_277 )
V_1 -> V_20 -> V_285 ( V_1 ) ;
F_75 ( & V_1 -> V_230 ) ;
}
return V_18 ;
}
static int F_112 ( struct V_106 * V_106 , void * V_189 ,
struct V_255 * V_13 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
struct V_9 * V_10 ;
int V_65 , V_115 , V_18 ;
F_2 ( V_105 , L_55 , V_13 -> V_115 ) ;
if ( F_74 ( & V_1 -> V_209 ) )
return - V_210 ;
V_115 = V_13 -> V_115 ;
if ( ( unsigned ) V_115 >= V_1 -> V_114 ) {
F_2 ( V_105 ,
L_56 , V_115 , V_1 -> V_114 ) ;
V_18 = - V_48 ;
goto V_176;
}
if ( V_13 -> V_108 != V_1 -> V_108 ) {
F_2 ( V_105 , L_57 ) ;
V_18 = - V_48 ;
goto V_176;
}
V_10 = & V_1 -> V_10 [ V_115 ] ;
if ( V_10 -> V_13 . V_14 & V_258 ) {
F_2 ( V_105 , L_58 ) ;
V_18 = - V_48 ;
goto V_176;
}
V_10 -> V_13 . V_14 |= V_102 ;
if ( V_10 -> V_13 . V_108 == V_254 ) {
V_10 -> V_13 . V_120 . V_283 = V_13 -> V_120 . V_283 ;
V_10 -> V_13 . V_119 = V_13 -> V_119 ;
}
V_65 = F_37 ( & V_1 -> V_92 ) ;
V_1 -> V_94 [ V_65 ] = V_115 ;
F_40 ( & V_1 -> V_92 , ( V_65 + 1 ) % V_103 ) ;
V_13 -> V_14 |= V_102 ;
V_13 -> V_14 &= ~ V_101 ;
V_18 = 0 ;
V_176:
F_75 ( & V_1 -> V_209 ) ;
return V_18 ;
}
static int F_113 ( struct V_1 * V_1 ,
struct V_106 * V_106 )
{
struct V_255 V_13 ;
int V_65 , V_18 ;
F_2 ( V_111 , L_59 ) ;
if ( F_74 ( & V_1 -> V_230 ) )
return - V_210 ;
if ( V_1 -> V_114 == 0 ) {
struct V_250 V_251 ;
memset ( & V_251 , 0 , sizeof V_251 ) ;
V_251 . V_109 = V_1 -> V_264 ;
V_251 . type = V_116 ;
V_251 . V_108 = V_252 ;
V_18 = F_94 ( V_106 , V_1 , & V_251 ) ;
if ( V_18 != 0 ) {
F_2 ( V_111 , L_60 , V_18 ) ;
goto V_176;
}
memset ( & V_13 , 0 , sizeof V_13 ) ;
V_13 . type = V_116 ;
V_13 . V_108 = V_252 ;
for ( V_65 = 0 ; V_65 < V_1 -> V_264 ; V_65 ++ ) {
V_13 . V_115 = V_65 ;
V_18 = F_112 ( V_106 , V_1 , & V_13 ) ;
if ( V_18 != 0 ) {
F_2 ( V_111 , L_61 , V_18 ) ;
goto V_176;
}
}
}
V_18 = F_96 ( V_106 , V_1 , V_116 ) ;
if ( V_18 != 0 )
F_2 ( V_111 , L_62 , V_18 ) ;
V_176:
F_75 ( & V_1 -> V_230 ) ;
return V_18 ;
}
static unsigned int F_114 ( struct V_106 * V_106 , T_5 * V_286 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
unsigned long V_287 = F_115 ( V_286 ) ;
int V_18 = 0 ;
F_2 ( V_105 , L_63 ) ;
if ( V_287 & V_288 )
V_18 |= F_116 ( V_106 , V_286 ) ;
if ( V_287 & ( V_289 | V_290 ) ) {
if ( V_1 -> V_108 == V_122 ) {
if ( F_113 ( V_1 , V_106 ) != 0 ) {
V_18 |= V_291 ;
goto V_176;
}
}
F_117 ( V_106 , & V_1 -> V_104 , V_286 ) ;
if ( F_74 ( & V_1 -> V_209 ) != 0 ) {
V_18 |= V_291 ;
goto V_176;
}
if ( V_1 -> V_121 != F_37 ( & V_1 -> V_91 ) )
V_18 |= V_289 | V_290 ;
F_75 ( & V_1 -> V_209 ) ;
}
V_176:
if ( ! V_1 -> V_277 )
V_18 |= V_292 ;
return V_18 ;
}
static T_6 F_118 ( struct V_106 * V_106 , char V_282 * V_71 ,
T_7 V_109 , T_8 * V_293 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
struct V_9 * V_10 ;
struct V_255 V_13 ;
struct V_294 V_95 ;
int V_159 , V_18 , V_295 ;
F_2 ( V_105 , L_64 , V_109 ) ;
if ( V_1 -> V_108 == V_122 ) {
V_18 = F_113 ( V_1 , V_106 ) ;
if ( V_18 != 0 )
return V_18 ;
}
V_95 = F_38 ( F_39 () ) ;
V_95 . V_296 -- ;
V_159 = 2 ;
for (; ; ) {
memset ( & V_13 , 0 , sizeof V_13 ) ;
V_13 . type = V_116 ;
V_13 . V_108 = V_252 ;
V_18 = F_107 ( V_106 , V_1 , & V_13 ) ;
if ( V_18 != 0 ) {
F_2 ( V_111 , L_65 , V_18 ) ;
return V_18 ;
}
V_10 = & V_1 -> V_10 [ V_13 . V_115 ] ;
if ( -- V_159 < 0 )
break;
if ( V_10 -> V_13 . V_95 . V_296 >= V_95 . V_296 )
break;
V_18 = F_112 ( V_106 , V_1 , & V_13 ) ;
if ( V_18 != 0 ) {
F_2 ( V_111 , L_66 , V_18 ) ;
return V_18 ;
}
}
if ( V_109 > V_10 -> V_13 . V_100 )
V_109 = V_10 -> V_13 . V_100 ;
V_18 = F_110 ( V_71 , V_10 -> V_71 , V_109 ) ;
if ( V_18 != 0 ) {
F_6 ( L_67 , V_18 , V_109 ) ;
V_18 = - V_284 ;
goto V_176;
}
V_18 = V_109 ;
V_176:
V_295 = F_112 ( V_106 , V_1 , & V_13 ) ;
if ( V_295 != 0 )
return V_295 ;
return V_18 ;
}
int F_119 ( struct V_61 * V_62 ,
const struct V_297 * V_36 ,
const struct V_20 * V_20 ,
int V_298 ,
struct V_229 * V_229 )
{
struct V_1 * V_1 ;
struct V_46 * V_29 = F_120 ( V_62 ) ;
int V_18 ;
F_121 ( L_68 V_299 L_69 ,
V_20 -> V_35 , V_36 -> V_237 , V_36 -> V_238 ) ;
if ( V_298 < sizeof *V_1 )
V_298 = sizeof *V_1 ;
V_1 = F_122 ( V_298 , V_53 ) ;
if ( ! V_1 ) {
F_8 ( L_70 ) ;
return - V_33 ;
}
V_1 -> V_226 = F_123 ( V_300 , V_53 ) ;
if ( ! V_1 -> V_226 ) {
F_8 ( L_71 ) ;
V_18 = - V_33 ;
goto V_176;
}
V_1 -> V_29 = V_29 ;
V_1 -> V_66 = V_62 -> V_67 -> V_68 . V_301 ;
if ( V_29 -> V_302 -> V_68 . V_303 != 1 ) {
int V_65 ;
struct V_61 * V_304 ;
for ( V_65 = 0 ; V_65 < V_29 -> V_302 -> V_68 . V_303 ; V_65 ++ ) {
V_304 = V_29 -> V_302 -> V_305 [ V_65 ] ;
if ( V_304 != NULL
&& V_304 -> V_154 != NULL
&& V_304 -> V_154 -> V_68 . V_306 ==
V_307 ) {
V_1 -> V_158 = 1 ;
break;
}
}
}
V_1 -> V_225 . V_308 = F_78 ;
V_18 = F_124 ( & V_62 -> V_29 , & V_1 -> V_225 ) ;
if ( V_18 )
goto V_176;
V_1 -> V_20 = V_20 ;
V_1 -> V_264 = 2 ;
V_1 -> V_81 = - 1 ;
V_1 -> V_179 = V_309 ;
V_1 -> V_179 . V_225 = & V_1 -> V_225 ;
F_125 ( & V_1 -> V_179 , V_1 ) ;
F_126 ( V_310 , & V_1 -> V_179 . V_14 ) ;
V_1 -> V_229 = V_229 ;
V_1 -> V_277 = 1 ;
F_127 ( & V_1 -> V_230 ) ;
V_1 -> V_179 . V_311 = & V_1 -> V_230 ;
F_127 ( & V_1 -> V_209 ) ;
F_128 ( & V_1 -> V_104 ) ;
V_18 = V_20 -> V_312 ( V_1 , V_36 ) ;
if ( V_18 < 0 )
goto V_176;
V_18 = V_20 -> V_313 ( V_1 ) ;
if ( V_18 < 0 )
goto V_176;
if ( V_20 -> V_314 )
V_18 = V_20 -> V_314 ( V_1 ) ;
if ( V_18 < 0 )
goto V_176;
F_61 ( V_1 ) ;
V_18 = F_9 ( V_1 ) ;
if ( V_18 )
goto V_176;
F_129 ( & V_1 -> V_179 , V_315 ) ;
F_129 ( & V_1 -> V_179 , V_316 ) ;
F_129 ( & V_1 -> V_179 , V_317 ) ;
#ifdef F_130
if ( ! V_1 -> V_20 -> V_197 )
F_131 ( & V_1 -> V_179 , V_318 ) ;
if ( ! V_1 -> V_20 -> V_198 )
F_131 ( & V_1 -> V_179 , V_319 ) ;
#endif
if ( ! V_1 -> V_20 -> V_261 )
F_131 ( & V_1 -> V_179 , V_320 ) ;
if ( ! V_1 -> V_20 -> V_262 )
F_131 ( & V_1 -> V_179 , V_321 ) ;
V_18 = F_132 ( & V_1 -> V_179 ,
V_322 ,
- 1 ) ;
if ( V_18 < 0 ) {
F_8 ( L_72 , V_18 ) ;
goto V_176;
}
F_133 ( V_62 , V_1 ) ;
F_2 ( V_323 , L_73 , F_134 ( & V_1 -> V_179 ) ) ;
F_26 ( V_1 ) ;
return 0 ;
V_176:
#if F_135 ( V_324 )
if ( V_1 -> V_30 )
F_136 ( V_1 -> V_30 ) ;
#endif
F_80 ( V_1 -> V_179 . V_180 ) ;
F_82 ( V_1 -> V_226 ) ;
F_82 ( V_1 ) ;
return V_18 ;
}
int F_137 ( struct V_61 * V_62 ,
const struct V_297 * V_36 ,
const struct V_20 * V_20 ,
int V_298 ,
struct V_229 * V_229 )
{
struct V_46 * V_29 = F_120 ( V_62 ) ;
if ( V_29 -> V_236 . V_325 != 1 ) {
F_8 ( L_74 ,
V_36 -> V_237 , V_36 -> V_238 ) ;
return - V_26 ;
}
if ( V_29 -> V_302 -> V_68 . V_303 != 1
&& V_62 -> V_67 -> V_68 . V_301 != 0 )
return - V_26 ;
return F_119 ( V_62 , V_36 , V_20 , V_298 , V_229 ) ;
}
void F_138 ( struct V_61 * V_62 )
{
struct V_1 * V_1 = F_139 ( V_62 ) ;
#if F_135 ( V_324 )
struct V_30 * V_30 ;
#endif
F_2 ( V_323 , L_75 ,
F_134 ( & V_1 -> V_179 ) ) ;
F_111 ( & V_1 -> V_230 ) ;
V_1 -> V_277 = 0 ;
F_47 ( V_1 ) ;
#if F_135 ( V_324 )
F_30 ( V_1 ) ;
V_30 = V_1 -> V_30 ;
if ( V_30 ) {
V_1 -> V_30 = NULL ;
F_136 ( V_30 ) ;
}
#endif
if ( V_1 -> V_20 -> V_127 && V_1 -> V_84 )
V_1 -> V_20 -> V_127 ( V_1 ) ;
V_1 -> V_84 = 0 ;
V_1 -> V_29 = NULL ;
F_41 ( & V_1 -> V_104 ) ;
F_140 ( & V_1 -> V_225 ) ;
F_141 ( & V_1 -> V_179 ) ;
F_75 ( & V_1 -> V_230 ) ;
F_142 ( & V_1 -> V_225 ) ;
}
int F_143 ( struct V_61 * V_62 , T_9 V_326 )
{
struct V_1 * V_1 = F_139 ( V_62 ) ;
F_30 ( V_1 ) ;
if ( ! V_1 -> V_84 )
return 0 ;
F_111 ( & V_1 -> V_230 ) ;
V_1 -> V_75 = 1 ;
V_1 -> V_125 = 0 ;
if ( V_1 -> V_20 -> V_126 )
V_1 -> V_20 -> V_126 ( V_1 ) ;
F_47 ( V_1 ) ;
F_48 ( V_1 ) ;
if ( V_1 -> V_20 -> V_127 )
V_1 -> V_20 -> V_127 ( V_1 ) ;
F_75 ( & V_1 -> V_230 ) ;
return 0 ;
}
int F_144 ( struct V_61 * V_62 )
{
struct V_1 * V_1 = F_139 ( V_62 ) ;
int V_84 , V_18 = 0 ;
F_111 ( & V_1 -> V_230 ) ;
V_1 -> V_75 = 0 ;
V_1 -> V_125 = 0 ;
V_1 -> V_20 -> V_313 ( V_1 ) ;
V_84 = V_1 -> V_84 ;
V_1 -> V_84 = 0 ;
if ( V_84 )
V_18 = F_57 ( V_1 ) ;
else
F_26 ( V_1 ) ;
F_75 ( & V_1 -> V_230 ) ;
return V_18 ;
}
static int T_10 F_145 ( void )
{
F_121 ( L_76 V_299 L_77 ) ;
return 0 ;
}
static void T_11 F_146 ( void )
{
}
