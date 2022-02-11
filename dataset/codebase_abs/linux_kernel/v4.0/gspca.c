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
int V_129 , int V_130 )
{
struct V_128 * V_43 ;
int V_65 , V_131 ;
for ( V_65 = 0 ; V_65 < V_124 -> V_68 . V_69 ; V_65 ++ ) {
V_43 = & V_124 -> V_70 [ V_65 ] ;
V_131 = V_43 -> V_68 . V_132 & V_133 ;
if ( V_131 == V_129
&& V_43 -> V_68 . V_49 != 0
&& F_28 ( & V_43 -> V_68 )
&& ( V_130 < 0 || V_43 -> V_68 . V_52 == V_130 ) )
return V_43 ;
}
return NULL ;
}
static T_4 F_52 ( struct V_1 * V_1 )
{
T_4 V_134 ;
V_134 = V_1 -> V_4 . V_110 ;
if ( ! V_1 -> V_85 . V_135 &&
V_134 < V_1 -> V_4 . V_136 *
V_1 -> V_4 . V_137 )
V_134 = V_134 * 3 / 8 ;
if ( V_1 -> V_20 -> V_138 ) {
struct V_139 V_140 ;
V_1 -> V_20 -> V_138 ( V_1 , & V_140 ) ;
V_134 *= V_140 . V_140 . V_141 . V_142 . V_143 ;
V_134 /= V_140 . V_140 . V_141 . V_142 . V_144 ;
} else {
if ( V_1 -> V_4 . V_136 >= 640
&& V_1 -> V_29 -> V_145 == V_146 )
V_134 *= 15 ;
else
V_134 *= 30 ;
}
F_2 ( V_111 , L_27 , V_134 ) ;
return V_134 ;
}
static int F_53 ( struct V_1 * V_1 ,
struct V_61 * V_62 ,
struct V_147 * V_148 )
{
struct V_128 * V_43 ;
int V_65 , V_89 , V_149 , V_150 , V_151 ;
T_4 V_134 , V_152 ;
V_149 = V_62 -> V_153 ;
if ( V_149 > V_154 )
V_149 = V_154 ;
V_65 = 0 ;
V_152 = 0 ;
for (; ; ) {
V_148 -> V_134 = 2000 * 2000 * 120 ;
V_151 = 0 ;
for ( V_89 = 0 ; V_89 < V_149 ; V_89 ++ ) {
V_43 = F_51 ( & V_62 -> V_155 [ V_89 ] ,
V_156 ,
V_1 -> V_130 ) ;
if ( V_43 == NULL )
continue;
if ( V_43 -> V_68 . V_50 == 0 ) {
F_8 ( L_28 , V_89 ) ;
continue;
}
V_150 = F_19 ( V_43 -> V_68 . V_49 ) ;
V_150 = ( V_150 & 0x07ff ) * ( 1 + ( ( V_150 >> 11 ) & 3 ) ) ;
V_134 = V_150 * 1000 ;
if ( V_1 -> V_29 -> V_145 == V_157
|| V_1 -> V_29 -> V_145 == V_158 )
V_134 *= 8 ;
V_134 /= 1 << ( V_43 -> V_68 . V_50 - 1 ) ;
if ( V_134 <= V_152 )
continue;
if ( V_134 < V_148 -> V_134 ) {
V_148 -> V_134 = V_134 ;
V_148 -> V_124 = V_89 ;
V_151 = 1 ;
}
}
if ( ! V_151 )
break;
F_2 ( V_111 , L_29 ,
V_148 -> V_124 , V_148 -> V_134 ) ;
V_152 = V_148 -> V_134 ;
V_65 ++ ;
V_148 ++ ;
}
if ( V_1 -> V_159 &&
V_1 -> V_29 -> V_145 == V_146 &&
V_152 >= 1000000 &&
V_65 > 1 ) {
F_2 ( V_111 , L_30 ) ;
V_65 -- ;
V_148 -- ;
}
V_134 = F_52 ( V_1 ) ;
V_148 -- ;
while ( V_65 > 1 ) {
V_148 -- ;
if ( V_148 -> V_134 < V_134 )
break;
V_65 -- ;
}
return V_65 ;
}
static int F_54 ( struct V_1 * V_1 ,
struct V_128 * V_43 )
{
struct V_16 * V_16 ;
int V_160 , V_161 , V_65 , V_150 , V_162 , V_163 ;
V_150 = F_19 ( V_43 -> V_68 . V_49 ) ;
if ( ! V_1 -> V_85 . V_164 ) {
if ( V_1 -> V_165 == 0 )
V_150 = ( V_150 & 0x07ff ) * ( 1 + ( ( V_150 >> 11 ) & 3 ) ) ;
else
V_150 = V_1 -> V_165 ;
V_162 = V_1 -> V_85 . V_162 ;
if ( V_162 == 0 )
V_162 = 32 ;
V_163 = V_150 * V_162 ;
F_2 ( V_111 ,
L_31 ,
V_162 , V_150 , V_163 ) ;
V_161 = V_166 ;
} else {
V_162 = 0 ;
V_163 = V_1 -> V_85 . V_167 ;
if ( V_163 == 0 )
V_163 = V_150 ;
F_2 ( V_111 , L_32 , V_163 ) ;
if ( V_1 -> V_85 . V_86 != 0 )
V_161 = V_1 -> V_85 . V_86 ;
else
V_161 = 1 ;
}
for ( V_160 = 0 ; V_160 < V_161 ; V_160 ++ ) {
V_16 = F_20 ( V_162 , V_53 ) ;
if ( ! V_16 ) {
F_8 ( L_33 ) ;
return - V_33 ;
}
V_1 -> V_16 [ V_160 ] = V_16 ;
V_16 -> V_22 = F_21 ( V_1 -> V_29 ,
V_163 ,
V_53 ,
& V_16 -> V_54 ) ;
if ( V_16 -> V_22 == NULL ) {
F_8 ( L_34 ) ;
return - V_33 ;
}
V_16 -> V_29 = V_1 -> V_29 ;
V_16 -> V_17 = V_1 ;
V_16 -> V_60 = V_163 ;
if ( V_162 != 0 ) {
V_16 -> V_168 = F_55 ( V_1 -> V_29 ,
V_43 -> V_68 . V_52 ) ;
V_16 -> V_56 = V_169
| V_57 ;
V_16 -> V_45 = 1 << ( V_43 -> V_68 . V_50 - 1 ) ;
V_16 -> V_170 = F_34 ;
V_16 -> V_77 = V_162 ;
for ( V_65 = 0 ; V_65 < V_162 ; V_65 ++ ) {
V_16 -> V_78 [ V_65 ] . V_119 = V_150 ;
V_16 -> V_78 [ V_65 ] . V_83 = V_150 * V_65 ;
}
} else {
V_16 -> V_168 = F_56 ( V_1 -> V_29 ,
V_43 -> V_68 . V_52 ) ;
V_16 -> V_56 = V_57 ;
V_16 -> V_170 = F_35 ;
}
}
return 0 ;
}
static int F_57 ( struct V_1 * V_1 )
{
struct V_61 * V_62 ;
struct V_128 * V_43 ;
struct V_16 * V_16 ;
struct V_147 V_148 [ V_154 ] ;
int V_160 , V_18 , V_129 , V_124 , V_171 ;
V_1 -> V_96 = NULL ;
V_1 -> V_97 = 0 ;
V_1 -> V_79 = V_80 ;
V_1 -> V_93 = 0 ;
V_1 -> V_125 = 0 ;
V_62 = F_27 ( V_1 -> V_29 , V_1 -> V_66 ) ;
V_1 -> V_124 = V_1 -> V_85 . V_164 ? V_62 -> V_153 : 0 ;
if ( V_1 -> V_20 -> V_172 ) {
V_18 = V_1 -> V_20 -> V_172 ( V_1 ) ;
if ( V_18 < 0 )
return V_18 ;
}
V_129 = V_1 -> V_85 . V_164 ? V_173
: V_156 ;
if ( V_1 -> V_124 != 0 ) {
V_1 -> V_124 -- ;
V_43 = F_51 ( & V_62 -> V_155 [ V_1 -> V_124 ] , V_129 ,
V_1 -> V_130 ) ;
if ( V_43 == NULL ) {
F_8 ( L_35 , V_1 -> V_124 ) ;
return - V_174 ;
}
V_148 [ 0 ] . V_124 = V_1 -> V_124 ;
V_171 = 1 ;
} else {
V_171 = F_53 ( V_1 , V_62 , V_148 ) ;
if ( V_171 <= 0 ) {
F_8 ( L_36 ) ;
return - V_174 ;
}
}
F_30 ( V_1 ) ;
V_1 -> V_124 = V_148 [ -- V_171 ] . V_124 ;
V_124 = - 1 ;
for (; ; ) {
if ( V_124 != V_1 -> V_124 ) {
V_124 = V_1 -> V_124 ;
if ( V_62 -> V_153 > 1 ) {
V_18 = F_49 ( V_1 -> V_29 ,
V_1 -> V_66 ,
V_124 ) ;
if ( V_18 < 0 ) {
if ( V_18 == - V_175 )
goto V_176;
F_8 ( L_37 , V_124 , V_18 ) ;
goto V_177;
}
}
}
if ( ! V_1 -> V_85 . V_178 ) {
F_2 ( V_111 , L_38 , V_124 ) ;
V_18 = F_54 ( V_1 ,
F_51 ( & V_62 -> V_155 [ V_124 ] , V_129 ,
V_1 -> V_130 ) ) ;
if ( V_18 < 0 ) {
F_47 ( V_1 ) ;
goto V_177;
}
}
if ( V_1 -> V_85 . V_164 )
F_58 ( V_1 -> V_29 ,
V_1 -> V_16 [ 0 ] -> V_168 ) ;
V_18 = V_1 -> V_20 -> V_179 ( V_1 ) ;
if ( V_18 < 0 ) {
F_47 ( V_1 ) ;
goto V_177;
}
V_1 -> V_84 = 1 ;
F_59 ( V_1 -> V_180 . V_181 ) ;
if ( V_1 -> V_85 . V_164 && V_1 -> V_85 . V_86 == 0 )
break;
for ( V_160 = 0 ; V_160 < V_123 ; V_160 ++ ) {
V_16 = V_1 -> V_16 [ V_160 ] ;
if ( V_16 == NULL )
break;
V_18 = F_7 ( V_16 , V_53 ) ;
if ( V_18 < 0 )
break;
}
if ( V_18 >= 0 )
break;
F_50 ( V_1 ) ;
if ( V_18 != - V_175 ) {
F_8 ( L_39 ,
V_1 -> V_124 , V_18 ) ;
goto V_177;
}
V_176:
F_6 ( L_40 , V_124 ) ;
F_60 ( 20 ) ;
if ( V_1 -> V_20 -> V_182 ) {
V_18 = V_1 -> V_20 -> V_182 ( V_1 ) ;
if ( V_18 < 0 )
goto V_177;
} else {
if ( V_171 <= 0 ) {
F_8 ( L_36 ) ;
V_18 = - V_174 ;
goto V_177;
}
V_1 -> V_124 = V_148 [ -- V_171 ] . V_124 ;
}
}
V_177:
F_26 ( V_1 ) ;
return V_18 ;
}
static void F_61 ( struct V_1 * V_1 )
{
int V_65 ;
V_65 = V_1 -> V_85 . V_183 - 1 ;
V_1 -> V_184 = V_65 ;
V_1 -> V_4 = V_1 -> V_85 . V_185 [ V_65 ] ;
F_59 ( V_1 -> V_180 . V_181 ) ;
}
static int F_62 ( struct V_1 * V_1 ,
int V_136 , int V_137 )
{
int V_65 ;
for ( V_65 = V_1 -> V_85 . V_183 ; -- V_65 > 0 ; ) {
if ( V_136 >= V_1 -> V_85 . V_185 [ V_65 ] . V_136
&& V_137 >= V_1 -> V_85 . V_185 [ V_65 ] . V_137 )
break;
}
return V_65 ;
}
static int F_63 ( struct V_1 * V_1 ,
int V_186 ,
int V_4 )
{
int V_187 , V_188 ;
V_187 = V_188 = V_186 ;
while ( ( V_187 < V_1 -> V_85 . V_183 ) || V_188 >= 0 ) {
if ( -- V_188 >= 0 ) {
if ( V_1 -> V_85 . V_185 [ V_188 ] . V_189
== V_4 )
return V_188 ;
}
if ( ++ V_187 < V_1 -> V_85 . V_183 ) {
if ( V_1 -> V_85 . V_185 [ V_187 ] . V_189
== V_4 )
return V_187 ;
}
}
return - V_48 ;
}
static int F_64 ( struct V_106 * V_106 , void * V_190 ,
struct V_191 * V_192 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
V_1 -> V_125 = 0 ;
if ( V_1 -> V_20 -> V_193 )
return V_1 -> V_20 -> V_193 ( V_1 , V_192 ) ;
return V_192 -> V_194 . V_195 ? - V_48 : 0 ;
}
static int F_66 ( struct V_106 * V_106 , void * V_190 ,
struct V_196 * V_197 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
V_1 -> V_125 = 0 ;
return V_1 -> V_20 -> V_198 ( V_1 , V_197 ) ;
}
static int F_67 ( struct V_106 * V_106 , void * V_190 ,
const struct V_196 * V_197 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
V_1 -> V_125 = 0 ;
return V_1 -> V_20 -> V_199 ( V_1 , V_197 ) ;
}
static int F_68 ( struct V_106 * V_106 , void * V_190 ,
struct V_200 * V_201 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
int V_65 , V_89 , V_115 ;
T_1 V_202 [ 8 ] ;
V_115 = 0 ;
V_89 = 0 ;
for ( V_65 = V_1 -> V_85 . V_183 ; -- V_65 >= 0 ; ) {
V_202 [ V_115 ] = V_1 -> V_85 . V_185 [ V_65 ] . V_189 ;
V_89 = 0 ;
for (; ; ) {
if ( V_202 [ V_89 ] == V_202 [ V_115 ] )
break;
V_89 ++ ;
}
if ( V_89 == V_115 ) {
if ( V_201 -> V_115 == V_115 )
break;
V_115 ++ ;
if ( V_115 >= F_69 ( V_202 ) )
return - V_48 ;
}
}
if ( V_65 < 0 )
return - V_48 ;
V_201 -> V_189 = V_202 [ V_115 ] ;
if ( V_1 -> V_85 . V_185 [ V_65 ] . V_110 <
V_1 -> V_85 . V_185 [ V_65 ] . V_136 *
V_1 -> V_85 . V_185 [ V_65 ] . V_137 )
V_201 -> V_14 = V_203 ;
V_201 -> V_204 [ 0 ] = V_201 -> V_189 & 0xff ;
V_201 -> V_204 [ 1 ] = ( V_201 -> V_189 >> 8 ) & 0xff ;
V_201 -> V_204 [ 2 ] = ( V_201 -> V_189 >> 16 ) & 0xff ;
V_201 -> V_204 [ 3 ] = V_201 -> V_189 >> 24 ;
V_201 -> V_204 [ 4 ] = '\0' ;
return 0 ;
}
static int F_70 ( struct V_106 * V_106 , void * V_190 ,
struct V_205 * V_206 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
V_206 -> V_206 . V_207 = V_1 -> V_4 ;
V_206 -> V_206 . V_207 . V_190 = 0 ;
return 0 ;
}
static int F_71 ( struct V_1 * V_1 ,
struct V_205 * V_206 )
{
int V_5 , V_6 , V_186 , V_208 ;
V_5 = V_206 -> V_206 . V_207 . V_136 ;
V_6 = V_206 -> V_206 . V_207 . V_137 ;
F_1 ( V_1 , V_51 , L_41 ,
V_206 -> V_206 . V_207 . V_189 , V_5 , V_6 ) ;
V_186 = F_62 ( V_1 , V_5 , V_6 ) ;
if ( V_1 -> V_85 . V_185 [ V_186 ] . V_189
!= V_206 -> V_206 . V_207 . V_189 ) {
V_208 = F_63 ( V_1 , V_186 ,
V_206 -> V_206 . V_207 . V_189 ) ;
if ( V_208 >= 0 )
V_186 = V_208 ;
}
V_206 -> V_206 . V_207 = V_1 -> V_85 . V_185 [ V_186 ] ;
if ( V_1 -> V_20 -> V_209 ) {
V_206 -> V_206 . V_207 . V_136 = V_5 ;
V_206 -> V_206 . V_207 . V_137 = V_6 ;
V_1 -> V_20 -> V_209 ( V_1 , V_206 ) ;
}
V_206 -> V_206 . V_207 . V_190 = 0 ;
return V_186 ;
}
static int F_72 ( struct V_106 * V_106 ,
void * V_190 ,
struct V_205 * V_206 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
int V_18 ;
V_18 = F_71 ( V_1 , V_206 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
}
static int F_73 ( struct V_106 * V_106 , void * V_190 ,
struct V_205 * V_206 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
int V_18 ;
if ( F_74 ( & V_1 -> V_210 ) )
return - V_211 ;
V_18 = F_71 ( V_1 , V_206 ) ;
if ( V_18 < 0 )
goto V_177;
if ( V_1 -> V_114 != 0
&& V_206 -> V_206 . V_207 . V_110 > V_1 -> V_99 ) {
V_18 = - V_48 ;
goto V_177;
}
if ( V_1 -> V_84 ) {
V_18 = - V_212 ;
goto V_177;
}
V_1 -> V_184 = V_18 ;
if ( V_1 -> V_20 -> V_209 )
V_1 -> V_4 = V_206 -> V_206 . V_207 ;
else
V_1 -> V_4 = V_1 -> V_85 . V_185 [ V_18 ] ;
V_18 = 0 ;
V_177:
F_75 ( & V_1 -> V_210 ) ;
return V_18 ;
}
static int F_76 ( struct V_106 * V_106 , void * V_190 ,
struct V_213 * V_214 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
int V_65 ;
T_1 V_115 = 0 ;
if ( V_1 -> V_20 -> V_215 )
return V_1 -> V_20 -> V_215 ( V_1 , V_214 ) ;
for ( V_65 = 0 ; V_65 < V_1 -> V_85 . V_183 ; V_65 ++ ) {
if ( V_214 -> V_216 !=
V_1 -> V_85 . V_185 [ V_65 ] . V_189 )
continue;
if ( V_214 -> V_115 == V_115 ) {
V_214 -> type = V_217 ;
V_214 -> V_218 . V_136 =
V_1 -> V_85 . V_185 [ V_65 ] . V_136 ;
V_214 -> V_218 . V_137 =
V_1 -> V_85 . V_185 [ V_65 ] . V_137 ;
return 0 ;
}
V_115 ++ ;
}
return - V_48 ;
}
static int F_77 ( struct V_106 * V_219 , void * V_190 ,
struct V_220 * V_221 )
{
struct V_1 * V_1 = F_65 ( V_219 ) ;
int V_186 = F_62 ( V_1 , V_221 -> V_136 , V_221 -> V_137 ) ;
T_1 V_65 ;
if ( V_1 -> V_85 . V_222 == NULL ||
V_1 -> V_85 . V_222 [ V_186 ] . V_223 == 0 )
return - V_48 ;
if ( V_221 -> V_216 !=
V_1 -> V_85 . V_185 [ V_186 ] . V_189 )
return - V_48 ;
for ( V_65 = 0 ; V_65 < V_1 -> V_85 . V_222 [ V_186 ] . V_223 ; V_65 ++ ) {
if ( V_221 -> V_115 == V_65 ) {
V_221 -> type = V_217 ;
V_221 -> V_218 . V_144 = 1 ;
V_221 -> V_218 . V_143 =
V_1 -> V_85 . V_222 [ V_186 ] . V_224 [ V_65 ] ;
return 0 ;
}
}
return - V_48 ;
}
static void F_78 ( struct V_225 * V_225 )
{
struct V_1 * V_1 =
F_79 ( V_225 , struct V_1 , V_226 ) ;
F_80 ( V_1 -> V_180 . V_181 ) ;
F_81 ( & V_1 -> V_226 ) ;
F_82 ( V_1 -> V_227 ) ;
F_82 ( V_1 ) ;
}
static int F_83 ( struct V_106 * V_106 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
int V_18 ;
F_2 ( V_111 , L_42 , V_228 -> V_229 ) ;
if ( ! F_84 ( V_1 -> V_230 ) )
return - V_26 ;
V_18 = F_85 ( V_106 ) ;
if ( V_18 )
F_86 ( V_1 -> V_230 ) ;
return V_18 ;
}
static int F_87 ( struct V_106 * V_106 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
F_2 ( V_111 , L_43 , V_228 -> V_229 ) ;
if ( F_74 ( & V_1 -> V_231 ) )
return - V_211 ;
if ( F_74 ( & V_1 -> V_210 ) ) {
F_75 ( & V_1 -> V_231 ) ;
return - V_211 ;
}
if ( V_1 -> V_113 == V_106 ) {
if ( V_1 -> V_84 )
F_50 ( V_1 ) ;
F_45 ( V_1 ) ;
}
F_86 ( V_1 -> V_230 ) ;
F_75 ( & V_1 -> V_210 ) ;
F_75 ( & V_1 -> V_231 ) ;
F_2 ( V_111 , L_44 ) ;
return F_88 ( V_106 ) ;
}
static int F_89 ( struct V_106 * V_106 , void * V_190 ,
struct V_232 * V_233 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
F_90 ( ( char * ) V_233 -> V_234 , V_1 -> V_20 -> V_35 ,
sizeof V_233 -> V_234 ) ;
if ( V_1 -> V_29 -> V_235 != NULL ) {
F_90 ( ( char * ) V_233 -> V_236 , V_1 -> V_29 -> V_235 ,
sizeof V_233 -> V_236 ) ;
} else {
snprintf ( ( char * ) V_233 -> V_236 , sizeof V_233 -> V_236 ,
L_45 ,
F_19 ( V_1 -> V_29 -> V_237 . V_238 ) ,
F_19 ( V_1 -> V_29 -> V_237 . V_239 ) ) ;
}
F_11 ( V_1 -> V_29 , ( char * ) V_233 -> V_240 ,
sizeof( V_233 -> V_240 ) ) ;
V_233 -> V_241 = V_242
| V_243
| V_244 ;
V_233 -> V_245 = V_233 -> V_241 | V_246 ;
return 0 ;
}
static int F_91 ( struct V_106 * V_106 , void * V_190 ,
struct V_247 * V_248 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
if ( V_248 -> V_115 != 0 )
return - V_48 ;
V_248 -> type = V_249 ;
V_248 -> V_19 = V_1 -> V_85 . V_250 ;
F_90 ( V_248 -> V_35 , V_1 -> V_20 -> V_35 ,
sizeof V_248 -> V_35 ) ;
return 0 ;
}
static int F_92 ( struct V_106 * V_106 , void * V_190 , unsigned int * V_65 )
{
* V_65 = 0 ;
return 0 ;
}
static int F_93 ( struct V_106 * V_106 , void * V_190 , unsigned int V_65 )
{
if ( V_65 > 0 )
return - V_48 ;
return ( 0 ) ;
}
static int F_94 ( struct V_106 * V_106 , void * V_190 ,
struct V_251 * V_252 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
int V_65 , V_18 = 0 , V_84 ;
V_65 = V_252 -> V_108 ;
switch ( V_65 ) {
case V_253 :
case V_254 :
case V_255 :
break;
default:
return - V_48 ;
}
if ( F_74 ( & V_1 -> V_210 ) )
return - V_211 ;
if ( V_1 -> V_108 != V_122
&& V_1 -> V_108 != V_253
&& V_1 -> V_108 != V_252 -> V_108 ) {
V_18 = - V_212 ;
goto V_177;
}
if ( V_1 -> V_113 != NULL
&& V_1 -> V_113 != V_106 ) {
V_18 = - V_212 ;
goto V_177;
}
for ( V_65 = 0 ; V_65 < V_1 -> V_114 ; V_65 ++ ) {
if ( V_1 -> V_10 [ V_65 ] . V_12 ) {
V_18 = - V_212 ;
goto V_177;
}
}
V_84 = V_1 -> V_84 ;
if ( V_84 ) {
F_50 ( V_1 ) ;
if ( V_1 -> V_108 == V_253 )
V_84 = 0 ;
}
if ( V_1 -> V_114 != 0 )
F_45 ( V_1 ) ;
if ( V_252 -> V_109 == 0 )
goto V_177;
V_18 = F_42 ( V_1 , V_106 , V_252 -> V_108 , V_252 -> V_109 ) ;
if ( V_18 == 0 ) {
V_252 -> V_109 = V_1 -> V_114 ;
if ( V_84 )
V_18 = F_57 ( V_1 ) ;
}
V_177:
F_75 ( & V_1 -> V_210 ) ;
F_2 ( V_111 , L_46 , V_18 , V_252 -> V_109 ) ;
return V_18 ;
}
static int F_95 ( struct V_106 * V_106 , void * V_190 ,
struct V_256 * V_13 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
struct V_9 * V_10 ;
if ( V_13 -> V_115 >= V_1 -> V_114 )
return - V_48 ;
V_10 = & V_1 -> V_10 [ V_13 -> V_115 ] ;
memcpy ( V_13 , & V_10 -> V_13 , sizeof *V_13 ) ;
return 0 ;
}
static int F_96 ( struct V_106 * V_106 , void * V_190 ,
enum V_257 V_258 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
int V_18 ;
if ( V_258 != V_116 )
return - V_48 ;
if ( F_74 ( & V_1 -> V_210 ) )
return - V_211 ;
if ( V_1 -> V_113 != V_106 ) {
V_18 = - V_212 ;
goto V_177;
}
if ( V_1 -> V_114 == 0
|| ! ( V_1 -> V_10 [ 0 ] . V_13 . V_14 & V_102 ) ) {
V_18 = - V_48 ;
goto V_177;
}
if ( ! V_1 -> V_84 ) {
V_18 = F_57 ( V_1 ) ;
if ( V_18 < 0 )
goto V_177;
}
F_1 ( V_1 , V_111 , L_47 ,
V_1 -> V_4 . V_189 ,
V_1 -> V_4 . V_136 , V_1 -> V_4 . V_137 ) ;
V_18 = 0 ;
V_177:
F_75 ( & V_1 -> V_210 ) ;
return V_18 ;
}
static int F_97 ( struct V_106 * V_106 , void * V_190 ,
enum V_257 V_258 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
int V_65 , V_18 ;
if ( V_258 != V_116 )
return - V_48 ;
if ( F_74 ( & V_1 -> V_210 ) )
return - V_211 ;
if ( ! V_1 -> V_84 ) {
V_18 = 0 ;
goto V_177;
}
if ( V_1 -> V_113 != V_106 ) {
V_18 = - V_212 ;
goto V_177;
}
F_50 ( V_1 ) ;
F_41 ( & V_1 -> V_104 ) ;
for ( V_65 = 0 ; V_65 < V_1 -> V_114 ; V_65 ++ )
V_1 -> V_10 [ V_65 ] . V_13 . V_14 &= ~ V_259 ;
F_40 ( & V_1 -> V_92 , 0 ) ;
F_40 ( & V_1 -> V_91 , 0 ) ;
V_1 -> V_121 = 0 ;
V_18 = 0 ;
V_177:
F_75 ( & V_1 -> V_210 ) ;
return V_18 ;
}
static int F_98 ( struct V_106 * V_106 , void * V_190 ,
struct V_260 * V_261 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
V_1 -> V_125 = 0 ;
return V_1 -> V_20 -> V_262 ( V_1 , V_261 ) ;
}
static int F_99 ( struct V_106 * V_106 , void * V_190 ,
const struct V_260 * V_261 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
V_1 -> V_125 = 0 ;
return V_1 -> V_20 -> V_263 ( V_1 , V_261 ) ;
}
static int F_100 ( struct V_106 * V_219 , void * V_190 ,
struct V_139 * V_140 )
{
struct V_1 * V_1 = F_65 ( V_219 ) ;
V_140 -> V_140 . V_141 . V_264 = V_1 -> V_265 ;
if ( V_1 -> V_20 -> V_138 ) {
V_1 -> V_125 = 0 ;
V_1 -> V_20 -> V_138 ( V_1 , V_140 ) ;
return V_1 -> V_125 ;
}
return 0 ;
}
static int F_101 ( struct V_106 * V_219 , void * V_190 ,
struct V_139 * V_140 )
{
struct V_1 * V_1 = F_65 ( V_219 ) ;
unsigned int V_160 ;
V_160 = V_140 -> V_140 . V_141 . V_264 ;
if ( V_160 == 0 || V_160 >= V_103 )
V_140 -> V_140 . V_141 . V_264 = V_1 -> V_265 ;
else
V_1 -> V_265 = V_160 ;
if ( V_1 -> V_20 -> V_266 ) {
V_1 -> V_125 = 0 ;
V_1 -> V_20 -> V_266 ( V_1 , V_140 ) ;
return V_1 -> V_125 ;
}
return 0 ;
}
static int F_102 ( struct V_106 * V_106 , struct V_7 * V_8 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
struct V_9 * V_10 ;
struct V_267 * V_267 ;
unsigned long V_195 , V_179 , V_268 ;
int V_65 , V_18 ;
V_179 = V_8 -> V_269 ;
V_268 = V_8 -> V_270 - V_8 -> V_269 ;
F_2 ( V_111 , L_48 , ( int ) V_179 , ( int ) V_268 ) ;
if ( F_74 ( & V_1 -> V_210 ) )
return - V_211 ;
if ( V_1 -> V_113 != V_106 ) {
V_18 = - V_48 ;
goto V_177;
}
V_10 = NULL ;
for ( V_65 = 0 ; V_65 < V_1 -> V_114 ; ++ V_65 ) {
if ( V_1 -> V_10 [ V_65 ] . V_13 . V_108 != V_254 ) {
F_2 ( V_111 , L_49 ) ;
break;
}
if ( ( V_1 -> V_10 [ V_65 ] . V_13 . V_120 . V_83 >> V_271 )
== V_8 -> V_272 ) {
V_10 = & V_1 -> V_10 [ V_65 ] ;
break;
}
}
if ( V_10 == NULL ) {
F_2 ( V_111 , L_50 ) ;
V_18 = - V_48 ;
goto V_177;
}
if ( V_268 != V_10 -> V_13 . V_119 ) {
F_2 ( V_111 , L_51 ) ;
V_18 = - V_48 ;
goto V_177;
}
V_8 -> V_273 |= V_274 ;
V_195 = ( unsigned long ) V_10 -> V_71 ;
while ( V_268 > 0 ) {
V_267 = F_103 ( ( void * ) V_195 ) ;
V_18 = F_104 ( V_8 , V_179 , V_267 ) ;
if ( V_18 < 0 )
goto V_177;
V_179 += V_275 ;
V_195 += V_275 ;
V_268 -= V_275 ;
}
V_8 -> V_276 = & V_277 ;
V_8 -> V_11 = V_10 ;
F_3 ( V_8 ) ;
V_18 = 0 ;
V_177:
F_75 ( & V_1 -> V_210 ) ;
return V_18 ;
}
static int F_105 ( struct V_1 * V_1 , struct V_106 * V_106 ,
enum V_107 V_108 )
{
if ( ! V_1 -> V_278 )
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
if ( F_74 ( & V_1 -> V_210 ) )
return - V_211 ;
V_18 = F_105 ( V_1 , V_106 , V_108 ) ;
F_75 ( & V_1 -> V_210 ) ;
return V_18 ;
}
static int F_107 ( struct V_106 * V_106 , void * V_190 ,
struct V_256 * V_13 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
struct V_9 * V_10 ;
int V_65 , V_89 , V_18 ;
F_2 ( V_105 , L_52 ) ;
if ( F_74 ( & V_1 -> V_210 ) )
return - V_211 ;
for (; ; ) {
V_18 = F_105 ( V_1 , V_106 , V_13 -> V_108 ) ;
if ( V_18 < 0 )
goto V_177;
if ( V_18 > 0 )
break;
F_75 ( & V_1 -> V_210 ) ;
if ( V_106 -> V_279 & V_280 )
return - V_281 ;
V_18 = F_108 ( V_1 -> V_104 ,
F_106 ( V_1 , V_106 , V_13 -> V_108 ) ,
F_109 ( 3000 ) ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_18 == 0 )
return - V_174 ;
if ( F_74 ( & V_1 -> V_210 ) )
return - V_211 ;
}
V_65 = V_1 -> V_121 ;
V_89 = V_1 -> V_94 [ V_65 ] ;
V_10 = & V_1 -> V_10 [ V_89 ] ;
V_1 -> V_121 = ( V_65 + 1 ) % V_103 ;
V_10 -> V_13 . V_14 &= ~ V_101 ;
memcpy ( V_13 , & V_10 -> V_13 , sizeof *V_13 ) ;
F_2 ( V_105 , L_53 , V_89 ) ;
V_18 = 0 ;
if ( V_1 -> V_108 == V_255 ) {
if ( F_110 ( ( V_282 V_283 * ) V_10 -> V_13 . V_120 . V_284 ,
V_10 -> V_71 ,
V_10 -> V_13 . V_100 ) ) {
F_6 ( L_54 ) ;
V_18 = - V_285 ;
}
}
V_177:
F_75 ( & V_1 -> V_210 ) ;
if ( V_18 == 0 && V_1 -> V_20 -> V_286 ) {
F_111 ( & V_1 -> V_231 ) ;
V_1 -> V_125 = 0 ;
if ( V_1 -> V_278 )
V_1 -> V_20 -> V_286 ( V_1 ) ;
F_75 ( & V_1 -> V_231 ) ;
}
return V_18 ;
}
static int F_112 ( struct V_106 * V_106 , void * V_190 ,
struct V_256 * V_13 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
struct V_9 * V_10 ;
int V_65 , V_115 , V_18 ;
F_2 ( V_105 , L_55 , V_13 -> V_115 ) ;
if ( F_74 ( & V_1 -> V_210 ) )
return - V_211 ;
V_115 = V_13 -> V_115 ;
if ( ( unsigned ) V_115 >= V_1 -> V_114 ) {
F_2 ( V_105 ,
L_56 , V_115 , V_1 -> V_114 ) ;
V_18 = - V_48 ;
goto V_177;
}
if ( V_13 -> V_108 != V_1 -> V_108 ) {
F_2 ( V_105 , L_57 ) ;
V_18 = - V_48 ;
goto V_177;
}
V_10 = & V_1 -> V_10 [ V_115 ] ;
if ( V_10 -> V_13 . V_14 & V_259 ) {
F_2 ( V_105 , L_58 ) ;
V_18 = - V_48 ;
goto V_177;
}
V_10 -> V_13 . V_14 |= V_102 ;
if ( V_10 -> V_13 . V_108 == V_255 ) {
V_10 -> V_13 . V_120 . V_284 = V_13 -> V_120 . V_284 ;
V_10 -> V_13 . V_119 = V_13 -> V_119 ;
}
V_65 = F_37 ( & V_1 -> V_92 ) ;
V_1 -> V_94 [ V_65 ] = V_115 ;
F_40 ( & V_1 -> V_92 , ( V_65 + 1 ) % V_103 ) ;
V_13 -> V_14 |= V_102 ;
V_13 -> V_14 &= ~ V_101 ;
V_18 = 0 ;
V_177:
F_75 ( & V_1 -> V_210 ) ;
return V_18 ;
}
static int F_113 ( struct V_1 * V_1 ,
struct V_106 * V_106 )
{
struct V_256 V_13 ;
int V_65 , V_18 ;
F_2 ( V_111 , L_59 ) ;
if ( F_74 ( & V_1 -> V_231 ) )
return - V_211 ;
if ( V_1 -> V_114 == 0 ) {
struct V_251 V_252 ;
memset ( & V_252 , 0 , sizeof V_252 ) ;
V_252 . V_109 = V_1 -> V_265 ;
V_252 . type = V_116 ;
V_252 . V_108 = V_253 ;
V_18 = F_94 ( V_106 , V_1 , & V_252 ) ;
if ( V_18 != 0 ) {
F_2 ( V_111 , L_60 , V_18 ) ;
goto V_177;
}
memset ( & V_13 , 0 , sizeof V_13 ) ;
V_13 . type = V_116 ;
V_13 . V_108 = V_253 ;
for ( V_65 = 0 ; V_65 < V_1 -> V_265 ; V_65 ++ ) {
V_13 . V_115 = V_65 ;
V_18 = F_112 ( V_106 , V_1 , & V_13 ) ;
if ( V_18 != 0 ) {
F_2 ( V_111 , L_61 , V_18 ) ;
goto V_177;
}
}
}
V_18 = F_96 ( V_106 , V_1 , V_116 ) ;
if ( V_18 != 0 )
F_2 ( V_111 , L_62 , V_18 ) ;
V_177:
F_75 ( & V_1 -> V_231 ) ;
return V_18 ;
}
static unsigned int F_114 ( struct V_106 * V_106 , T_5 * V_287 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
unsigned long V_288 = F_115 ( V_287 ) ;
int V_18 = 0 ;
F_2 ( V_105 , L_63 ) ;
if ( V_288 & V_289 )
V_18 |= F_116 ( V_106 , V_287 ) ;
if ( V_288 & ( V_290 | V_291 ) ) {
if ( V_1 -> V_108 == V_122 ) {
if ( F_113 ( V_1 , V_106 ) != 0 ) {
V_18 |= V_292 ;
goto V_177;
}
}
F_117 ( V_106 , & V_1 -> V_104 , V_287 ) ;
if ( F_74 ( & V_1 -> V_210 ) != 0 ) {
V_18 |= V_292 ;
goto V_177;
}
if ( V_1 -> V_121 != F_37 ( & V_1 -> V_91 ) )
V_18 |= V_290 | V_291 ;
F_75 ( & V_1 -> V_210 ) ;
}
V_177:
if ( ! V_1 -> V_278 )
V_18 |= V_293 ;
return V_18 ;
}
static T_6 F_118 ( struct V_106 * V_106 , char V_283 * V_71 ,
T_7 V_109 , T_8 * V_294 )
{
struct V_1 * V_1 = F_65 ( V_106 ) ;
struct V_9 * V_10 ;
struct V_256 V_13 ;
struct V_295 V_95 ;
int V_160 , V_18 , V_296 ;
F_2 ( V_105 , L_64 , V_109 ) ;
if ( V_1 -> V_108 == V_122 ) {
V_18 = F_113 ( V_1 , V_106 ) ;
if ( V_18 != 0 )
return V_18 ;
}
V_95 = F_38 ( F_39 () ) ;
V_95 . V_297 -- ;
V_160 = 2 ;
for (; ; ) {
memset ( & V_13 , 0 , sizeof V_13 ) ;
V_13 . type = V_116 ;
V_13 . V_108 = V_253 ;
V_18 = F_107 ( V_106 , V_1 , & V_13 ) ;
if ( V_18 != 0 ) {
F_2 ( V_111 , L_65 , V_18 ) ;
return V_18 ;
}
V_10 = & V_1 -> V_10 [ V_13 . V_115 ] ;
if ( -- V_160 < 0 )
break;
if ( V_10 -> V_13 . V_95 . V_297 >= V_95 . V_297 )
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
V_18 = - V_285 ;
goto V_177;
}
V_18 = V_109 ;
V_177:
V_296 = F_112 ( V_106 , V_1 , & V_13 ) ;
if ( V_296 != 0 )
return V_296 ;
return V_18 ;
}
int F_119 ( struct V_61 * V_62 ,
const struct V_298 * V_36 ,
const struct V_20 * V_20 ,
int V_299 ,
struct V_230 * V_230 )
{
struct V_1 * V_1 ;
struct V_46 * V_29 = F_120 ( V_62 ) ;
int V_18 ;
F_121 ( L_68 V_300 L_69 ,
V_20 -> V_35 , V_36 -> V_238 , V_36 -> V_239 ) ;
if ( V_299 < sizeof *V_1 )
V_299 = sizeof *V_1 ;
V_1 = F_122 ( V_299 , V_53 ) ;
if ( ! V_1 ) {
F_8 ( L_70 ) ;
return - V_33 ;
}
V_1 -> V_227 = F_123 ( V_301 , V_53 ) ;
if ( ! V_1 -> V_227 ) {
F_8 ( L_71 ) ;
V_18 = - V_33 ;
goto V_177;
}
V_1 -> V_29 = V_29 ;
V_1 -> V_66 = V_62 -> V_67 -> V_68 . V_302 ;
V_1 -> V_130 = - 1 ;
if ( V_29 -> V_303 -> V_68 . V_304 != 1 ) {
int V_65 ;
struct V_61 * V_305 ;
for ( V_65 = 0 ; V_65 < V_29 -> V_303 -> V_68 . V_304 ; V_65 ++ ) {
V_305 = V_29 -> V_303 -> V_306 [ V_65 ] ;
if ( V_305 != NULL
&& V_305 -> V_155 != NULL
&& V_305 -> V_155 -> V_68 . V_307 ==
V_308 ) {
V_1 -> V_159 = 1 ;
break;
}
}
}
V_1 -> V_226 . V_309 = F_78 ;
V_18 = F_124 ( & V_62 -> V_29 , & V_1 -> V_226 ) ;
if ( V_18 )
goto V_177;
V_1 -> V_20 = V_20 ;
V_1 -> V_265 = 2 ;
V_1 -> V_81 = - 1 ;
V_1 -> V_180 = V_310 ;
V_1 -> V_180 . V_226 = & V_1 -> V_226 ;
F_125 ( & V_1 -> V_180 , V_1 ) ;
V_1 -> V_230 = V_230 ;
V_1 -> V_278 = 1 ;
F_126 ( & V_1 -> V_231 ) ;
V_1 -> V_180 . V_311 = & V_1 -> V_231 ;
F_126 ( & V_1 -> V_210 ) ;
F_127 ( & V_1 -> V_104 ) ;
V_18 = V_20 -> V_312 ( V_1 , V_36 ) ;
if ( V_18 < 0 )
goto V_177;
V_18 = V_20 -> V_313 ( V_1 ) ;
if ( V_18 < 0 )
goto V_177;
if ( V_20 -> V_314 )
V_18 = V_20 -> V_314 ( V_1 ) ;
if ( V_18 < 0 )
goto V_177;
F_61 ( V_1 ) ;
V_18 = F_9 ( V_1 ) ;
if ( V_18 )
goto V_177;
F_128 ( & V_1 -> V_180 , V_315 ) ;
F_128 ( & V_1 -> V_180 , V_316 ) ;
F_128 ( & V_1 -> V_180 , V_317 ) ;
#ifdef F_129
if ( ! V_1 -> V_20 -> V_198 )
F_130 ( & V_1 -> V_180 , V_318 ) ;
if ( ! V_1 -> V_20 -> V_199 )
F_130 ( & V_1 -> V_180 , V_319 ) ;
#endif
if ( ! V_1 -> V_20 -> V_262 )
F_130 ( & V_1 -> V_180 , V_320 ) ;
if ( ! V_1 -> V_20 -> V_263 )
F_130 ( & V_1 -> V_180 , V_321 ) ;
V_18 = F_131 ( & V_1 -> V_180 ,
V_322 ,
- 1 ) ;
if ( V_18 < 0 ) {
F_8 ( L_72 , V_18 ) ;
goto V_177;
}
F_132 ( V_62 , V_1 ) ;
F_2 ( V_323 , L_73 , F_133 ( & V_1 -> V_180 ) ) ;
F_26 ( V_1 ) ;
return 0 ;
V_177:
#if F_134 ( V_324 )
if ( V_1 -> V_30 )
F_135 ( V_1 -> V_30 ) ;
#endif
F_80 ( V_1 -> V_180 . V_181 ) ;
F_82 ( V_1 -> V_227 ) ;
F_82 ( V_1 ) ;
return V_18 ;
}
int F_136 ( struct V_61 * V_62 ,
const struct V_298 * V_36 ,
const struct V_20 * V_20 ,
int V_299 ,
struct V_230 * V_230 )
{
struct V_46 * V_29 = F_120 ( V_62 ) ;
if ( V_29 -> V_237 . V_325 != 1 ) {
F_8 ( L_74 ,
V_36 -> V_238 , V_36 -> V_239 ) ;
return - V_26 ;
}
if ( V_29 -> V_303 -> V_68 . V_304 != 1
&& V_62 -> V_67 -> V_68 . V_302 != 0 )
return - V_26 ;
return F_119 ( V_62 , V_36 , V_20 , V_299 , V_230 ) ;
}
void F_137 ( struct V_61 * V_62 )
{
struct V_1 * V_1 = F_138 ( V_62 ) ;
#if F_134 ( V_324 )
struct V_30 * V_30 ;
#endif
F_2 ( V_323 , L_75 ,
F_133 ( & V_1 -> V_180 ) ) ;
F_111 ( & V_1 -> V_231 ) ;
V_1 -> V_278 = 0 ;
F_47 ( V_1 ) ;
#if F_134 ( V_324 )
F_30 ( V_1 ) ;
V_30 = V_1 -> V_30 ;
if ( V_30 ) {
V_1 -> V_30 = NULL ;
F_135 ( V_30 ) ;
}
#endif
if ( V_1 -> V_20 -> V_127 && V_1 -> V_84 )
V_1 -> V_20 -> V_127 ( V_1 ) ;
V_1 -> V_84 = 0 ;
V_1 -> V_29 = NULL ;
F_41 ( & V_1 -> V_104 ) ;
F_139 ( & V_1 -> V_226 ) ;
F_140 ( & V_1 -> V_180 ) ;
F_75 ( & V_1 -> V_231 ) ;
F_141 ( & V_1 -> V_226 ) ;
}
int F_142 ( struct V_61 * V_62 , T_9 V_326 )
{
struct V_1 * V_1 = F_138 ( V_62 ) ;
F_30 ( V_1 ) ;
if ( ! V_1 -> V_84 )
return 0 ;
F_111 ( & V_1 -> V_231 ) ;
V_1 -> V_75 = 1 ;
V_1 -> V_125 = 0 ;
if ( V_1 -> V_20 -> V_126 )
V_1 -> V_20 -> V_126 ( V_1 ) ;
F_47 ( V_1 ) ;
F_48 ( V_1 ) ;
if ( V_1 -> V_20 -> V_127 )
V_1 -> V_20 -> V_127 ( V_1 ) ;
F_75 ( & V_1 -> V_231 ) ;
return 0 ;
}
int F_143 ( struct V_61 * V_62 )
{
struct V_1 * V_1 = F_138 ( V_62 ) ;
int V_84 , V_18 = 0 ;
F_111 ( & V_1 -> V_231 ) ;
V_1 -> V_75 = 0 ;
V_1 -> V_125 = 0 ;
V_1 -> V_20 -> V_313 ( V_1 ) ;
V_84 = V_1 -> V_84 ;
V_1 -> V_84 = 0 ;
if ( V_84 )
V_18 = F_57 ( V_1 ) ;
else
F_26 ( V_1 ) ;
F_75 ( & V_1 -> V_231 ) ;
return V_18 ;
}
static int T_10 F_144 ( void )
{
F_121 ( L_76 V_300 L_77 ) ;
return 0 ;
}
static void T_11 F_145 ( void )
{
}
