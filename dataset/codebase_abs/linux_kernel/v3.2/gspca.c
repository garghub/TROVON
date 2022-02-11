static void F_1 ( char * V_1 , T_1 V_2 , int V_3 , int V_4 )
{
if ( ( V_2 >> 24 ) >= '0' && ( V_2 >> 24 ) <= 'z' ) {
F_2 ( V_5 | V_6 , L_1 ,
V_1 ,
V_2 & 0xff ,
( V_2 >> 8 ) & 0xff ,
( V_2 >> 16 ) & 0xff ,
V_2 >> 24 ,
V_3 , V_4 ) ;
} else {
F_2 ( V_5 | V_6 , L_2 ,
V_1 ,
V_2 ,
V_3 , V_4 ) ;
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
struct V_17 * V_17 = (struct V_17 * ) V_16 -> V_18 ;
int V_19 ;
V_19 = V_16 -> V_20 ;
switch ( V_19 ) {
case 0 :
if ( V_17 -> V_21 -> V_22 ( V_17 ,
V_16 -> V_23 , V_16 -> V_24 ) < 0 ) {
F_2 ( V_25 , L_3 ) ;
}
break;
case - V_26 :
case - V_27 :
case - V_28 :
case - V_29 :
break;
default:
F_2 ( V_25 , L_4 , V_16 -> V_20 ) ;
V_16 -> V_20 = 0 ;
V_19 = 0 ;
}
if ( V_19 == 0 ) {
V_19 = F_6 ( V_16 , V_30 ) ;
if ( V_19 < 0 )
F_7 ( L_5 , V_19 ) ;
}
}
static int F_8 ( struct V_17 * V_31 )
{
struct V_32 * V_32 ;
int V_33 = 0 ;
V_31 -> V_32 = NULL ;
if ( V_31 -> V_21 -> V_22 || V_31 -> V_21 -> V_34 ) {
V_32 = F_9 () ;
if ( ! V_32 )
return - V_35 ;
F_10 ( V_31 -> V_31 , V_31 -> V_36 , sizeof( V_31 -> V_36 ) ) ;
F_11 ( V_31 -> V_36 , L_6 , sizeof( V_31 -> V_36 ) ) ;
V_32 -> V_37 = V_31 -> V_21 -> V_37 ;
V_32 -> V_36 = V_31 -> V_36 ;
F_12 ( V_31 -> V_31 , & V_32 -> V_38 ) ;
V_32 -> V_39 [ 0 ] = F_13 ( V_40 ) ;
V_32 -> V_41 [ F_14 ( V_42 ) ] = F_13 ( V_42 ) ;
V_32 -> V_31 . V_43 = & V_31 -> V_31 -> V_31 ;
V_33 = F_15 ( V_32 ) ;
if ( V_33 ) {
F_7 ( L_7 ,
V_33 ) ;
V_32 -> V_31 . V_43 = NULL ;
F_16 ( V_32 ) ;
} else {
V_31 -> V_32 = V_32 ;
}
}
return V_33 ;
}
static int F_17 ( struct V_17 * V_17 ,
struct V_44 * V_45 )
{
unsigned int V_46 ;
int V_47 ;
struct V_16 * V_16 ;
struct V_48 * V_31 ;
void * V_49 = NULL ;
int V_19 = - V_50 ;
V_46 = F_18 ( V_45 -> V_51 ) ;
V_47 = V_45 -> V_52 ;
F_2 ( V_5 , L_8
L_9 ,
V_45 -> V_53 , V_46 , V_47 ) ;
V_31 = V_17 -> V_31 ;
V_16 = F_19 ( 0 , V_54 ) ;
if ( ! V_16 ) {
V_19 = - V_35 ;
goto error;
}
V_49 = F_20 ( V_31 , V_46 ,
V_54 , & V_16 -> V_55 ) ;
if ( ! V_49 ) {
V_19 = - V_35 ;
goto V_56;
}
F_21 ( V_16 , V_31 ,
F_22 ( V_31 , V_45 -> V_53 ) ,
V_49 , V_46 ,
F_5 , ( void * ) V_17 , V_47 ) ;
V_16 -> V_57 |= V_58 ;
V_19 = F_6 ( V_16 , V_54 ) ;
if ( V_19 < 0 ) {
F_2 ( V_25 , L_10 , V_19 ) ;
goto V_59;
}
V_17 -> V_60 = V_16 ;
return V_19 ;
V_59:
F_23 ( V_31 ,
V_16 -> V_61 ,
V_16 -> V_23 ,
V_16 -> V_55 ) ;
V_56:
F_24 ( V_16 ) ;
error:
return V_19 ;
}
static void F_25 ( struct V_17 * V_17 )
{
struct V_62 * V_63 ;
struct V_64 * V_65 ;
struct V_44 * V_45 ;
int V_66 ;
if ( V_17 -> V_21 -> V_22 ) {
V_63 = F_26 ( V_17 -> V_31 , V_17 -> V_67 ) ;
V_65 = V_63 -> V_68 ;
for ( V_66 = 0 ; V_66 < V_65 -> V_69 . V_70 ; V_66 ++ ) {
V_45 = & V_65 -> V_71 [ V_66 ] . V_69 ;
if ( F_27 ( V_45 ) &&
F_28 ( V_45 ) ) {
F_17 ( V_17 , V_45 ) ;
break;
}
}
}
}
static void F_29 ( struct V_17 * V_17 )
{
struct V_16 * V_16 ;
V_16 = V_17 -> V_60 ;
if ( V_16 ) {
V_17 -> V_60 = NULL ;
F_30 ( V_16 ) ;
F_23 ( V_17 -> V_31 ,
V_16 -> V_61 ,
V_16 -> V_23 ,
V_16 -> V_55 ) ;
F_24 ( V_16 ) ;
}
}
static inline void F_29 ( struct V_17 * V_17 )
{
}
static inline void F_25 ( struct V_17 * V_17 )
{
}
static inline int F_8 ( struct V_17 * V_31 )
{
return 0 ;
}
static void F_31 ( struct V_17 * V_17 ,
struct V_16 * V_16 )
{
T_2 * V_72 ;
int V_66 , V_73 , V_74 ;
T_3 V_75 ;
if ( V_16 -> V_20 != 0 ) {
if ( V_16 -> V_20 == - V_29 )
return;
#ifdef F_32
if ( V_17 -> V_76 )
return;
#endif
F_2 ( V_25 | V_77 , L_11 , V_16 -> V_20 ) ;
V_16 -> V_20 = 0 ;
goto V_78;
}
V_75 = V_17 -> V_21 -> V_75 ;
for ( V_66 = 0 ; V_66 < V_16 -> V_79 ; V_66 ++ ) {
V_73 = V_16 -> V_80 [ V_66 ] . V_24 ;
V_74 = V_16 -> V_80 [ V_66 ] . V_20 ;
if ( V_74 ) {
F_7 ( L_12 ,
V_66 , V_73 , V_74 ) ;
V_17 -> V_81 = V_82 ;
continue;
}
if ( V_73 == 0 ) {
if ( V_17 -> V_83 == 0 )
V_17 -> V_83 = 1 ;
continue;
}
F_2 ( V_77 , L_13 ,
V_66 , V_16 -> V_80 [ V_66 ] . V_84 , V_73 ) ;
V_72 = ( T_2 * ) V_16 -> V_23
+ V_16 -> V_80 [ V_66 ] . V_84 ;
V_75 ( V_17 , V_72 , V_73 ) ;
}
V_78:
V_74 = F_6 ( V_16 , V_30 ) ;
if ( V_74 < 0 )
F_7 ( L_14 , V_74 ) ;
}
static void F_33 ( struct V_16 * V_16 )
{
struct V_17 * V_17 = (struct V_17 * ) V_16 -> V_18 ;
F_2 ( V_77 , L_15 ) ;
if ( ! V_17 -> V_85 )
return;
F_31 ( V_17 , V_16 ) ;
}
static void F_34 ( struct V_16 * V_16 )
{
struct V_17 * V_17 = (struct V_17 * ) V_16 -> V_18 ;
int V_74 ;
F_2 ( V_77 , L_16 ) ;
if ( ! V_17 -> V_85 )
return;
switch ( V_16 -> V_20 ) {
case 0 :
break;
case - V_29 :
return;
default:
#ifdef F_32
if ( V_17 -> V_76 )
return;
#endif
F_2 ( V_25 | V_77 , L_11 , V_16 -> V_20 ) ;
V_16 -> V_20 = 0 ;
goto V_78;
}
F_2 ( V_77 , L_17 , V_16 -> V_24 ) ;
V_17 -> V_21 -> V_75 ( V_17 ,
V_16 -> V_23 ,
V_16 -> V_24 ) ;
V_78:
if ( V_17 -> V_86 . V_87 != 0 ) {
V_74 = F_6 ( V_16 , V_30 ) ;
if ( V_74 < 0 )
F_7 ( L_14 , V_74 ) ;
}
}
void F_35 ( struct V_17 * V_17 ,
enum V_88 V_89 ,
const T_2 * V_72 ,
int V_73 )
{
struct V_9 * V_10 ;
int V_66 , V_90 ;
F_2 ( V_77 , L_18 , V_89 , V_73 ) ;
if ( V_89 == V_91 ) {
V_66 = F_36 ( & V_17 -> V_92 ) ;
if ( V_66 == F_36 ( & V_17 -> V_93 ) ) {
V_17 -> V_81 = V_82 ;
V_17 -> V_94 ++ ;
return;
}
V_90 = V_17 -> V_95 [ V_66 ] ;
V_10 = & V_17 -> V_10 [ V_90 ] ;
V_10 -> V_13 . V_96 = F_37 ( F_38 () ) ;
V_10 -> V_13 . V_94 = V_17 -> V_94 ++ ;
V_17 -> V_97 = V_10 -> V_72 ;
V_17 -> V_98 = 0 ;
} else {
switch ( V_17 -> V_81 ) {
case V_82 :
if ( V_89 == V_99 ) {
V_17 -> V_81 = V_89 ;
V_17 -> V_97 = NULL ;
V_17 -> V_98 = 0 ;
}
return;
case V_99 :
return;
}
}
if ( V_73 > 0 ) {
if ( V_17 -> V_98 + V_73 > V_17 -> V_100 ) {
F_2 ( V_25 | V_77 , L_19 ,
V_17 -> V_98 + V_73 ,
V_17 -> V_100 ) ;
V_89 = V_82 ;
} else {
memcpy ( V_17 -> V_97 + V_17 -> V_98 ,
V_72 , V_73 ) ;
V_17 -> V_98 += V_73 ;
}
}
V_17 -> V_81 = V_89 ;
if ( V_89 == V_99 ) {
V_66 = F_36 ( & V_17 -> V_92 ) ;
V_90 = V_17 -> V_95 [ V_66 ] ;
V_10 = & V_17 -> V_10 [ V_90 ] ;
V_10 -> V_13 . V_101 = V_17 -> V_98 ;
V_10 -> V_13 . V_14 = ( V_10 -> V_13 . V_14
| V_102 )
& ~ V_103 ;
V_66 = ( V_66 + 1 ) % V_104 ;
F_39 ( & V_17 -> V_92 , V_66 ) ;
F_40 ( & V_17 -> V_105 ) ;
F_2 ( V_106 , L_20 ,
V_10 -> V_13 . V_101 ) ;
V_17 -> V_97 = NULL ;
V_17 -> V_98 = 0 ;
}
}
static int F_41 ( struct V_17 * V_17 , struct V_107 * V_107 ,
enum V_108 V_109 , unsigned int V_110 )
{
struct V_9 * V_10 ;
unsigned int V_100 ;
int V_66 ;
V_66 = V_17 -> V_111 ;
V_100 = V_17 -> V_86 . V_112 [ V_66 ] . V_113 ;
F_2 ( V_6 , L_21 , V_100 ) ;
V_100 = F_42 ( V_100 ) ;
if ( V_110 >= V_104 )
V_110 = V_104 - 1 ;
V_17 -> V_114 = F_43 ( V_100 * V_110 ) ;
if ( ! V_17 -> V_114 ) {
F_7 ( L_22 ) ;
return - V_35 ;
}
V_17 -> V_115 = V_107 ;
V_17 -> V_109 = V_109 ;
V_17 -> V_100 = V_100 ;
V_17 -> V_116 = V_110 ;
for ( V_66 = 0 ; V_66 < V_110 ; V_66 ++ ) {
V_10 = & V_17 -> V_10 [ V_66 ] ;
V_10 -> V_13 . V_117 = V_66 ;
V_10 -> V_13 . type = V_118 ;
V_10 -> V_13 . V_14 = 0 ;
V_10 -> V_13 . V_119 = V_120 ;
V_10 -> V_13 . V_121 = V_100 ;
V_10 -> V_13 . V_109 = V_109 ;
V_10 -> V_13 . V_94 = 0 ;
V_10 -> V_72 = V_17 -> V_114 + V_66 * V_100 ;
V_10 -> V_13 . V_122 . V_84 = V_66 * V_100 ;
}
F_39 ( & V_17 -> V_93 , 0 ) ;
F_39 ( & V_17 -> V_92 , 0 ) ;
V_17 -> V_123 = 0 ;
return 0 ;
}
static void F_44 ( struct V_17 * V_17 )
{
int V_66 ;
F_2 ( V_6 , L_23 ) ;
if ( V_17 -> V_114 != NULL ) {
F_45 ( V_17 -> V_114 ) ;
V_17 -> V_114 = NULL ;
for ( V_66 = 0 ; V_66 < V_17 -> V_116 ; V_66 ++ )
V_17 -> V_10 [ V_66 ] . V_72 = NULL ;
}
V_17 -> V_116 = 0 ;
V_17 -> V_100 = 0 ;
V_17 -> V_115 = NULL ;
V_17 -> V_109 = V_124 ;
}
static void F_46 ( struct V_17 * V_17 )
{
struct V_16 * V_16 ;
unsigned int V_66 ;
F_2 ( V_6 , L_24 ) ;
for ( V_66 = 0 ; V_66 < V_125 ; V_66 ++ ) {
V_16 = V_17 -> V_16 [ V_66 ] ;
if ( V_16 == NULL )
break;
V_17 -> V_16 [ V_66 ] = NULL ;
F_30 ( V_16 ) ;
if ( V_16 -> V_23 != NULL )
F_23 ( V_17 -> V_31 ,
V_16 -> V_61 ,
V_16 -> V_23 ,
V_16 -> V_55 ) ;
F_24 ( V_16 ) ;
}
}
static int F_47 ( struct V_17 * V_17 )
{
int V_19 ;
if ( V_17 -> V_126 == 0 )
return 0 ;
V_19 = F_48 ( V_17 -> V_31 , V_17 -> V_67 , 0 ) ;
if ( V_19 < 0 )
F_7 ( L_25 , V_19 ) ;
return V_19 ;
}
static void F_49 ( struct V_17 * V_17 )
{
V_17 -> V_85 = 0 ;
if ( V_17 -> V_127 ) {
if ( V_17 -> V_21 -> V_128 )
V_17 -> V_21 -> V_128 ( V_17 ) ;
F_46 ( V_17 ) ;
F_29 ( V_17 ) ;
F_47 ( V_17 ) ;
F_25 ( V_17 ) ;
}
if ( V_17 -> V_21 -> V_129 )
V_17 -> V_21 -> V_129 ( V_17 ) ;
F_2 ( V_6 , L_26 ) ;
}
static struct V_130 * F_50 ( struct V_64 * V_126 ,
int V_131 )
{
struct V_130 * V_45 ;
int V_66 , V_132 ;
for ( V_66 = 0 ; V_66 < V_126 -> V_69 . V_70 ; V_66 ++ ) {
V_45 = & V_126 -> V_71 [ V_66 ] ;
V_132 = V_45 -> V_69 . V_133 & V_134 ;
if ( V_132 == V_131
&& V_45 -> V_69 . V_51 != 0
&& F_27 ( & V_45 -> V_69 ) )
return V_45 ;
}
return NULL ;
}
static T_4 F_51 ( struct V_17 * V_17 )
{
T_4 V_135 ;
int V_66 ;
V_66 = V_17 -> V_111 ;
V_135 = V_17 -> V_86 . V_112 [ V_66 ] . V_113 ;
if ( V_135 < V_17 -> V_86 . V_112 [ V_66 ] . V_136 *
V_17 -> V_86 . V_112 [ V_66 ] . V_137 )
V_135 /= 3 ;
if ( V_17 -> V_21 -> V_138 ) {
struct V_139 V_140 ;
V_140 . V_140 . V_141 . V_142 . V_143 = 15 ;
V_17 -> V_21 -> V_138 ( V_17 , & V_140 ) ;
V_135 *= V_140 . V_140 . V_141 . V_142 . V_143 ;
} else {
V_135 *= 15 ;
}
F_2 ( V_6 , L_27 , V_135 ) ;
return V_135 ;
}
static int F_52 ( struct V_17 * V_17 ,
struct V_62 * V_63 ,
int V_131 ,
struct V_144 * V_145 )
{
struct V_130 * V_45 ;
int V_66 , V_90 , V_146 , V_147 , V_148 ;
T_4 V_135 , V_149 ;
V_146 = V_63 -> V_150 ;
if ( V_146 > V_151 )
V_146 = V_151 ;
V_66 = 0 ;
V_149 = 0 ;
for (; ; ) {
V_145 -> V_135 = 2000 * 2000 * 120 ;
V_148 = 0 ;
for ( V_90 = 0 ; V_90 < V_146 ; V_90 ++ ) {
V_45 = F_50 ( & V_63 -> V_152 [ V_90 ] , V_131 ) ;
if ( V_45 == NULL )
continue;
V_147 = F_18 ( V_45 -> V_69 . V_51 ) ;
if ( ! V_17 -> V_86 . V_153 )
V_147 = ( V_147 & 0x07ff ) *
( 1 + ( ( V_147 >> 11 ) & 3 ) ) ;
V_135 = V_147 * V_45 -> V_69 . V_52 * 1000 ;
if ( V_17 -> V_31 -> V_154 == V_155
|| V_17 -> V_31 -> V_154 == V_156 )
V_135 *= 8 ;
if ( V_135 <= V_149 )
continue;
if ( V_135 < V_145 -> V_135 ) {
V_145 -> V_135 = V_135 ;
V_145 -> V_126 = V_90 ;
V_148 = 1 ;
}
}
if ( ! V_148 )
break;
F_2 ( V_6 , L_28 ,
V_145 -> V_126 , V_145 -> V_135 ) ;
V_149 = V_145 -> V_135 ;
V_66 ++ ;
V_145 ++ ;
}
V_135 = F_51 ( V_17 ) ;
V_145 -- ;
while ( V_66 > 1 ) {
V_145 -- ;
if ( V_145 -> V_135 < V_135 )
break;
V_66 -- ;
}
return V_66 ;
}
static int F_53 ( struct V_17 * V_17 ,
struct V_130 * V_45 )
{
struct V_16 * V_16 ;
int V_157 , V_158 , V_66 , V_147 , V_159 , V_160 ;
V_147 = F_18 ( V_45 -> V_69 . V_51 ) ;
if ( ! V_17 -> V_86 . V_153 ) {
if ( V_17 -> V_161 == 0 )
V_147 = ( V_147 & 0x07ff ) * ( 1 + ( ( V_147 >> 11 ) & 3 ) ) ;
else
V_147 = V_17 -> V_161 ;
V_159 = V_17 -> V_86 . V_159 ;
if ( V_159 == 0 )
V_159 = 32 ;
V_160 = V_147 * V_159 ;
F_2 ( V_6 ,
L_29 ,
V_159 , V_147 , V_160 ) ;
V_158 = V_162 ;
} else {
V_159 = 0 ;
V_160 = V_17 -> V_86 . V_163 ;
if ( V_160 == 0 )
V_160 = V_147 ;
F_2 ( V_6 , L_30 , V_160 ) ;
if ( V_17 -> V_86 . V_87 != 0 )
V_158 = V_17 -> V_86 . V_87 ;
else
V_158 = 1 ;
}
for ( V_157 = 0 ; V_157 < V_158 ; V_157 ++ ) {
V_16 = F_19 ( V_159 , V_54 ) ;
if ( ! V_16 ) {
F_7 ( L_31 ) ;
return - V_35 ;
}
V_17 -> V_16 [ V_157 ] = V_16 ;
V_16 -> V_23 = F_20 ( V_17 -> V_31 ,
V_160 ,
V_54 ,
& V_16 -> V_55 ) ;
if ( V_16 -> V_23 == NULL ) {
F_7 ( L_32 ) ;
return - V_35 ;
}
V_16 -> V_31 = V_17 -> V_31 ;
V_16 -> V_18 = V_17 ;
V_16 -> V_61 = V_160 ;
if ( V_159 != 0 ) {
V_16 -> V_164 = F_54 ( V_17 -> V_31 ,
V_45 -> V_69 . V_53 ) ;
V_16 -> V_57 = V_165
| V_58 ;
if ( V_17 -> V_31 -> V_154 == V_166 )
V_16 -> V_47 = V_45 -> V_69 . V_52 ;
else
V_16 -> V_47 = 1 << ( V_45 -> V_69 . V_52 - 1 ) ;
V_16 -> V_167 = F_33 ;
V_16 -> V_79 = V_159 ;
for ( V_66 = 0 ; V_66 < V_159 ; V_66 ++ ) {
V_16 -> V_80 [ V_66 ] . V_121 = V_147 ;
V_16 -> V_80 [ V_66 ] . V_84 = V_147 * V_66 ;
}
} else {
V_16 -> V_164 = F_55 ( V_17 -> V_31 ,
V_45 -> V_69 . V_53 ) ;
V_16 -> V_57 = V_58 ;
V_16 -> V_167 = F_34 ;
}
}
return 0 ;
}
static int F_56 ( struct V_17 * V_17 )
{
struct V_62 * V_63 ;
struct V_130 * V_45 ;
struct V_16 * V_16 ;
struct V_144 V_145 [ V_151 ] ;
int V_157 , V_19 , V_131 , V_126 , V_168 ;
if ( F_57 ( & V_17 -> V_169 ) )
return - V_170 ;
if ( ! V_17 -> V_127 ) {
V_19 = - V_28 ;
goto V_171;
}
V_17 -> V_97 = NULL ;
V_17 -> V_98 = 0 ;
V_17 -> V_81 = V_82 ;
V_17 -> V_94 = 0 ;
V_17 -> V_172 = 0 ;
V_63 = F_26 ( V_17 -> V_31 , V_17 -> V_67 ) ;
V_17 -> V_126 = V_17 -> V_86 . V_153 ? V_63 -> V_150 : 0 ;
if ( V_17 -> V_21 -> V_173 ) {
V_19 = V_17 -> V_21 -> V_173 ( V_17 ) ;
if ( V_19 < 0 )
goto V_171;
}
V_131 = V_17 -> V_86 . V_153 ? V_174
: V_175 ;
if ( V_17 -> V_126 != 0 ) {
V_17 -> V_126 -- ;
V_45 = F_50 ( & V_63 -> V_152 [ V_17 -> V_126 ] , V_131 ) ;
if ( V_45 == NULL ) {
F_7 ( L_33 , V_17 -> V_126 ) ;
V_19 = - V_176 ;
goto V_177;
}
V_145 [ 0 ] . V_126 = V_17 -> V_126 ;
V_168 = 1 ;
} else {
V_168 = F_52 ( V_17 , V_63 , V_131 , V_145 ) ;
if ( V_168 <= 0 ) {
F_7 ( L_34 ) ;
V_19 = - V_176 ;
goto V_171;
}
}
F_29 ( V_17 ) ;
V_17 -> V_126 = V_145 [ -- V_168 ] . V_126 ;
V_126 = - 1 ;
for (; ; ) {
if ( V_126 != V_17 -> V_126 ) {
V_126 = V_17 -> V_126 ;
if ( V_17 -> V_146 > 1 ) {
V_19 = F_48 ( V_17 -> V_31 ,
V_17 -> V_67 ,
V_126 ) ;
if ( V_19 < 0 ) {
if ( V_19 == - V_178 )
goto V_179;
F_7 ( L_35 , V_126 , V_19 ) ;
goto V_177;
}
}
}
if ( ! V_17 -> V_86 . V_180 ) {
F_2 ( V_6 , L_36 , V_126 ) ;
V_19 = F_53 ( V_17 ,
F_50 ( & V_63 -> V_152 [ V_126 ] , V_131 ) ) ;
if ( V_19 < 0 ) {
F_46 ( V_17 ) ;
goto V_177;
}
}
if ( V_17 -> V_86 . V_153 )
F_58 ( V_17 -> V_31 ,
V_17 -> V_16 [ 0 ] -> V_164 ) ;
V_19 = V_17 -> V_21 -> V_181 ( V_17 ) ;
if ( V_19 < 0 ) {
F_46 ( V_17 ) ;
goto V_177;
}
V_17 -> V_85 = 1 ;
if ( V_17 -> V_86 . V_153 && V_17 -> V_86 . V_87 == 0 )
break;
for ( V_157 = 0 ; V_157 < V_125 ; V_157 ++ ) {
V_16 = V_17 -> V_16 [ V_157 ] ;
if ( V_16 == NULL )
break;
V_19 = F_6 ( V_16 , V_54 ) ;
if ( V_19 < 0 )
break;
}
if ( V_19 >= 0 )
break;
F_49 ( V_17 ) ;
if ( V_19 != - V_178 ) {
F_7 ( L_37 ,
V_17 -> V_126 , V_19 ) ;
goto V_177;
}
V_179:
F_2 ( V_25 | V_6 ,
L_38 ,
V_126 ) ;
F_59 ( 20 ) ;
if ( V_17 -> V_21 -> V_182 ) {
V_19 = V_17 -> V_21 -> V_182 ( V_17 ) ;
if ( V_19 < 0 )
goto V_177;
} else {
if ( V_168 <= 0 ) {
F_7 ( L_34 ) ;
V_19 = - V_176 ;
goto V_177;
}
V_17 -> V_126 = V_145 [ -- V_168 ] . V_126 ;
}
}
V_177:
F_25 ( V_17 ) ;
V_171:
F_60 ( & V_17 -> V_169 ) ;
return V_19 ;
}
static void F_61 ( struct V_17 * V_17 )
{
struct V_183 * V_184 ;
int V_66 ;
V_66 = V_17 -> V_86 . V_185 - 1 ;
V_17 -> V_111 = V_66 ;
V_17 -> V_136 = V_17 -> V_86 . V_112 [ V_66 ] . V_136 ;
V_17 -> V_137 = V_17 -> V_86 . V_112 [ V_66 ] . V_137 ;
V_17 -> V_2 = V_17 -> V_86 . V_112 [ V_66 ] . V_186 ;
V_184 = V_17 -> V_86 . V_187 ;
if ( V_184 != NULL ) {
for ( V_66 = 0 ;
V_66 < V_17 -> V_21 -> V_188 ;
V_66 ++ , V_184 ++ )
V_184 -> V_189 = V_184 -> V_190 ;
}
}
static int F_62 ( struct V_17 * V_17 ,
int V_136 , int V_137 )
{
int V_66 ;
for ( V_66 = V_17 -> V_86 . V_185 ; -- V_66 > 0 ; ) {
if ( V_136 >= V_17 -> V_86 . V_112 [ V_66 ] . V_136
&& V_137 >= V_17 -> V_86 . V_112 [ V_66 ] . V_137 )
break;
}
return V_66 ;
}
static int F_63 ( struct V_17 * V_17 ,
int V_191 ,
int V_2 )
{
int V_192 , V_193 ;
V_192 = V_193 = V_191 ;
while ( ( V_192 < V_17 -> V_86 . V_185 ) || V_193 >= 0 ) {
if ( -- V_193 >= 0 ) {
if ( V_17 -> V_86 . V_112 [ V_193 ] . V_186
== V_2 )
return V_193 ;
}
if ( ++ V_192 < V_17 -> V_86 . V_185 ) {
if ( V_17 -> V_86 . V_112 [ V_192 ] . V_186
== V_2 )
return V_192 ;
}
}
return - V_50 ;
}
static int F_64 ( struct V_107 * V_107 , void * V_194 ,
struct V_195 * V_196 )
{
int V_19 ;
struct V_17 * V_17 = V_194 ;
if ( ! V_17 -> V_21 -> V_197 )
return - V_50 ;
if ( ! V_17 -> V_21 -> V_198 )
return - V_50 ;
if ( F_57 ( & V_17 -> V_169 ) )
return - V_170 ;
V_17 -> V_172 = 0 ;
if ( V_17 -> V_127 )
V_19 = V_17 -> V_21 -> V_198 ( V_17 , V_196 ) ;
else
V_19 = - V_28 ;
F_60 ( & V_17 -> V_169 ) ;
return V_19 ;
}
static int F_65 ( struct V_107 * V_107 , void * V_194 ,
struct V_195 * V_196 )
{
int V_19 ;
struct V_17 * V_17 = V_194 ;
if ( ! V_17 -> V_21 -> V_197 )
return - V_50 ;
if ( ! V_17 -> V_21 -> V_199 )
return - V_50 ;
if ( F_57 ( & V_17 -> V_169 ) )
return - V_170 ;
V_17 -> V_172 = 0 ;
if ( V_17 -> V_127 )
V_19 = V_17 -> V_21 -> V_199 ( V_17 , V_196 ) ;
else
V_19 = - V_28 ;
F_60 ( & V_17 -> V_169 ) ;
return V_19 ;
}
static int F_66 ( struct V_107 * V_107 , void * V_194 ,
struct V_200 * V_201 )
{
int V_19 ;
struct V_17 * V_17 = V_194 ;
if ( ! V_17 -> V_21 -> V_197 )
return - V_50 ;
if ( F_57 ( & V_17 -> V_169 ) )
return - V_170 ;
V_17 -> V_172 = 0 ;
if ( V_17 -> V_127 )
V_19 = V_17 -> V_21 -> V_197 ( V_17 , V_201 ) ;
else
V_19 = - V_28 ;
F_60 ( & V_17 -> V_169 ) ;
return V_19 ;
}
static int F_67 ( struct V_107 * V_107 , void * V_194 ,
struct V_202 * V_203 )
{
struct V_17 * V_17 = V_194 ;
int V_66 , V_90 , V_117 ;
T_1 V_204 [ 8 ] ;
V_117 = 0 ;
V_90 = 0 ;
for ( V_66 = V_17 -> V_86 . V_185 ; -- V_66 >= 0 ; ) {
V_204 [ V_117 ] = V_17 -> V_86 . V_112 [ V_66 ] . V_186 ;
V_90 = 0 ;
for (; ; ) {
if ( V_204 [ V_90 ] == V_204 [ V_117 ] )
break;
V_90 ++ ;
}
if ( V_90 == V_117 ) {
if ( V_203 -> V_117 == V_117 )
break;
V_117 ++ ;
if ( V_117 >= F_68 ( V_204 ) )
return - V_50 ;
}
}
if ( V_66 < 0 )
return - V_50 ;
V_203 -> V_186 = V_204 [ V_117 ] ;
if ( V_17 -> V_86 . V_112 [ V_66 ] . V_113 <
V_17 -> V_86 . V_112 [ V_66 ] . V_136 *
V_17 -> V_86 . V_112 [ V_66 ] . V_137 )
V_203 -> V_14 = V_205 ;
V_203 -> V_206 [ 0 ] = V_203 -> V_186 & 0xff ;
V_203 -> V_206 [ 1 ] = ( V_203 -> V_186 >> 8 ) & 0xff ;
V_203 -> V_206 [ 2 ] = ( V_203 -> V_186 >> 16 ) & 0xff ;
V_203 -> V_206 [ 3 ] = V_203 -> V_186 >> 24 ;
V_203 -> V_206 [ 4 ] = '\0' ;
return 0 ;
}
static int F_69 ( struct V_107 * V_107 , void * V_194 ,
struct V_207 * V_208 )
{
struct V_17 * V_17 = V_194 ;
int V_191 ;
V_191 = V_17 -> V_111 ;
memcpy ( & V_208 -> V_208 . V_209 , & V_17 -> V_86 . V_112 [ V_191 ] ,
sizeof V_208 -> V_208 . V_209 ) ;
return 0 ;
}
static int F_70 ( struct V_17 * V_17 ,
struct V_207 * V_208 )
{
int V_3 , V_4 , V_191 , V_210 ;
V_3 = V_208 -> V_208 . V_209 . V_136 ;
V_4 = V_208 -> V_208 . V_209 . V_137 ;
#ifdef F_71
if ( V_211 & V_5 )
F_1 ( L_39 , V_208 -> V_208 . V_209 . V_186 , V_3 , V_4 ) ;
#endif
V_191 = F_62 ( V_17 , V_3 , V_4 ) ;
if ( V_17 -> V_86 . V_112 [ V_191 ] . V_186
!= V_208 -> V_208 . V_209 . V_186 ) {
V_210 = F_63 ( V_17 , V_191 ,
V_208 -> V_208 . V_209 . V_186 ) ;
if ( V_210 >= 0 )
V_191 = V_210 ;
}
memcpy ( & V_208 -> V_208 . V_209 , & V_17 -> V_86 . V_112 [ V_191 ] ,
sizeof V_208 -> V_208 . V_209 ) ;
return V_191 ;
}
static int F_72 ( struct V_107 * V_107 ,
void * V_194 ,
struct V_207 * V_208 )
{
struct V_17 * V_17 = V_194 ;
int V_19 ;
V_19 = F_70 ( V_17 , V_208 ) ;
if ( V_19 < 0 )
return V_19 ;
return 0 ;
}
static int F_73 ( struct V_107 * V_107 , void * V_194 ,
struct V_207 * V_208 )
{
struct V_17 * V_17 = V_194 ;
int V_19 ;
if ( F_57 ( & V_17 -> V_212 ) )
return - V_170 ;
V_19 = F_70 ( V_17 , V_208 ) ;
if ( V_19 < 0 )
goto V_177;
if ( V_17 -> V_116 != 0
&& V_208 -> V_208 . V_209 . V_113 > V_17 -> V_100 ) {
V_19 = - V_50 ;
goto V_177;
}
if ( V_19 == V_17 -> V_111 ) {
V_19 = 0 ;
goto V_177;
}
if ( V_17 -> V_85 ) {
V_19 = - V_213 ;
goto V_177;
}
V_17 -> V_136 = V_208 -> V_208 . V_209 . V_136 ;
V_17 -> V_137 = V_208 -> V_208 . V_209 . V_137 ;
V_17 -> V_2 = V_208 -> V_208 . V_209 . V_186 ;
V_17 -> V_111 = V_19 ;
V_19 = 0 ;
V_177:
F_60 ( & V_17 -> V_212 ) ;
return V_19 ;
}
static int F_74 ( struct V_107 * V_107 , void * V_194 ,
struct V_214 * V_215 )
{
struct V_17 * V_17 = V_194 ;
int V_66 ;
T_1 V_117 = 0 ;
for ( V_66 = 0 ; V_66 < V_17 -> V_86 . V_185 ; V_66 ++ ) {
if ( V_215 -> V_216 !=
V_17 -> V_86 . V_112 [ V_66 ] . V_186 )
continue;
if ( V_215 -> V_117 == V_117 ) {
V_215 -> type = V_217 ;
V_215 -> V_218 . V_136 =
V_17 -> V_86 . V_112 [ V_66 ] . V_136 ;
V_215 -> V_218 . V_137 =
V_17 -> V_86 . V_112 [ V_66 ] . V_137 ;
return 0 ;
}
V_117 ++ ;
}
return - V_50 ;
}
static int F_75 ( struct V_107 * V_219 , void * V_194 ,
struct V_220 * V_221 )
{
struct V_17 * V_17 = V_194 ;
int V_191 = F_62 ( V_17 , V_221 -> V_136 , V_221 -> V_137 ) ;
T_1 V_66 ;
if ( V_17 -> V_86 . V_222 == NULL ||
V_17 -> V_86 . V_222 [ V_191 ] . V_223 == 0 )
return - V_50 ;
if ( V_221 -> V_216 !=
V_17 -> V_86 . V_112 [ V_191 ] . V_186 )
return - V_50 ;
for ( V_66 = 0 ; V_66 < V_17 -> V_86 . V_222 [ V_191 ] . V_223 ; V_66 ++ ) {
if ( V_221 -> V_117 == V_66 ) {
V_221 -> type = V_217 ;
V_221 -> V_218 . V_224 = 1 ;
V_221 -> V_218 . V_143 =
V_17 -> V_86 . V_222 [ V_191 ] . V_225 [ V_66 ] ;
return 0 ;
}
}
return - V_50 ;
}
static void F_76 ( struct V_226 * V_227 )
{
struct V_17 * V_17 = F_77 ( V_227 , struct V_17 , V_228 ) ;
F_2 ( V_229 , L_40 ,
F_78 ( & V_17 -> V_228 ) ) ;
F_79 ( V_17 -> V_230 ) ;
F_79 ( V_17 ) ;
}
static int F_80 ( struct V_107 * V_107 )
{
struct V_17 * V_17 ;
F_2 ( V_6 , L_41 , V_231 -> V_232 ) ;
V_17 = (struct V_17 * ) F_81 ( V_107 ) ;
if ( ! V_17 -> V_127 )
return - V_28 ;
if ( ! F_82 ( V_17 -> V_233 ) )
return - V_28 ;
V_107 -> V_234 = V_17 ;
#ifdef F_71
if ( V_211 & V_235 )
V_17 -> V_228 . V_236 |= V_237
| V_238 ;
else
V_17 -> V_228 . V_236 &= ~ ( V_237
| V_238 ) ;
#endif
return 0 ;
}
static int F_83 ( struct V_107 * V_107 )
{
struct V_17 * V_17 = V_107 -> V_234 ;
F_2 ( V_6 , L_42 , V_231 -> V_232 ) ;
if ( F_57 ( & V_17 -> V_212 ) )
return - V_170 ;
if ( V_17 -> V_115 == V_107 ) {
if ( V_17 -> V_85 ) {
F_84 ( & V_17 -> V_169 ) ;
V_17 -> V_172 = 0 ;
F_49 ( V_17 ) ;
F_60 ( & V_17 -> V_169 ) ;
}
F_44 ( V_17 ) ;
}
V_107 -> V_234 = NULL ;
F_85 ( V_17 -> V_233 ) ;
F_60 ( & V_17 -> V_212 ) ;
F_2 ( V_6 , L_43 ) ;
return 0 ;
}
static int F_86 ( struct V_107 * V_107 , void * V_194 ,
struct V_239 * V_240 )
{
struct V_17 * V_17 = V_194 ;
int V_19 ;
if ( F_57 ( & V_17 -> V_169 ) )
return - V_170 ;
if ( ! V_17 -> V_127 ) {
V_19 = - V_28 ;
goto V_177;
}
F_87 ( ( char * ) V_240 -> V_241 , V_17 -> V_21 -> V_37 ,
sizeof V_240 -> V_241 ) ;
if ( V_17 -> V_31 -> V_242 != NULL ) {
F_87 ( ( char * ) V_240 -> V_243 , V_17 -> V_31 -> V_242 ,
sizeof V_240 -> V_243 ) ;
} else {
snprintf ( ( char * ) V_240 -> V_243 , sizeof V_240 -> V_243 ,
L_44 ,
F_18 ( V_17 -> V_31 -> V_244 . V_245 ) ,
F_18 ( V_17 -> V_31 -> V_244 . V_246 ) ) ;
}
F_10 ( V_17 -> V_31 , ( char * ) V_240 -> V_247 ,
sizeof( V_240 -> V_247 ) ) ;
V_240 -> V_248 = V_249
| V_250
| V_251 ;
V_19 = 0 ;
V_177:
F_60 ( & V_17 -> V_169 ) ;
return V_19 ;
}
static int F_88 ( struct V_17 * V_17 ,
int V_38 )
{
const struct V_184 * V_187 ;
int V_66 ;
for ( V_66 = 0 , V_187 = V_17 -> V_21 -> V_187 ;
V_66 < V_17 -> V_21 -> V_188 ;
V_66 ++ , V_187 ++ ) {
if ( V_17 -> V_252 & ( 1 << V_66 ) )
continue;
if ( V_38 == V_187 -> V_253 . V_38 )
return V_66 ;
}
return - 1 ;
}
static int F_89 ( struct V_107 * V_107 , void * V_194 ,
struct V_254 * V_255 )
{
struct V_17 * V_17 = V_194 ;
const struct V_184 * V_187 ;
struct V_183 * V_183 ;
int V_66 , V_256 ;
T_4 V_38 ;
V_38 = V_255 -> V_38 ;
if ( V_38 & V_257 ) {
V_38 &= V_258 ;
V_38 ++ ;
V_256 = - 1 ;
for ( V_66 = 0 ; V_66 < V_17 -> V_21 -> V_188 ; V_66 ++ ) {
if ( V_17 -> V_252 & ( 1 << V_66 ) )
continue;
if ( V_17 -> V_21 -> V_187 [ V_66 ] . V_253 . V_38 < V_38 )
continue;
if ( V_256 >= 0
&& V_17 -> V_21 -> V_187 [ V_66 ] . V_253 . V_38
> V_17 -> V_21 -> V_187 [ V_256 ] . V_253 . V_38 )
continue;
V_256 = V_66 ;
}
} else {
V_256 = F_88 ( V_17 , V_38 ) ;
}
if ( V_256 < 0 )
return - V_50 ;
V_187 = & V_17 -> V_21 -> V_187 [ V_256 ] ;
memcpy ( V_255 , & V_187 -> V_253 , sizeof *V_255 ) ;
if ( V_17 -> V_86 . V_187 != NULL ) {
V_183 = & V_17 -> V_86 . V_187 [ V_256 ] ;
V_255 -> V_259 = V_183 -> V_190 ;
V_255 -> V_260 = V_183 -> V_261 ;
V_255 -> V_262 = V_183 -> V_263 ;
}
if ( V_17 -> V_264 & ( 1 << V_256 ) )
V_255 -> V_14 |= V_265 ;
return 0 ;
}
static int F_90 ( struct V_107 * V_107 , void * V_194 ,
struct V_266 * V_184 )
{
struct V_17 * V_17 = V_194 ;
const struct V_184 * V_187 ;
struct V_183 * V_183 ;
int V_256 , V_19 ;
V_256 = F_88 ( V_17 , V_184 -> V_38 ) ;
if ( V_256 < 0 )
return - V_50 ;
if ( V_17 -> V_264 & ( 1 << V_256 ) )
return - V_50 ;
V_187 = & V_17 -> V_21 -> V_187 [ V_256 ] ;
if ( V_17 -> V_86 . V_187 != NULL ) {
V_183 = & V_17 -> V_86 . V_187 [ V_256 ] ;
if ( V_184 -> V_267 < V_183 -> V_261
|| V_184 -> V_267 > V_183 -> V_263 )
return - V_268 ;
} else {
V_183 = NULL ;
if ( V_184 -> V_267 < V_187 -> V_253 . V_260
|| V_184 -> V_267 > V_187 -> V_253 . V_262 )
return - V_268 ;
}
F_2 ( V_5 , L_45 , V_184 -> V_38 , V_184 -> V_267 ) ;
if ( F_57 ( & V_17 -> V_169 ) )
return - V_170 ;
if ( ! V_17 -> V_127 ) {
V_19 = - V_28 ;
goto V_177;
}
V_17 -> V_172 = 0 ;
if ( V_187 -> V_269 != NULL ) {
V_19 = V_187 -> V_269 ( V_17 , V_184 -> V_267 ) ;
goto V_177;
}
if ( V_183 != NULL ) {
V_183 -> V_189 = V_184 -> V_267 ;
if ( V_187 -> V_270 != NULL
&& V_17 -> V_85 )
V_187 -> V_270 ( V_17 ) ;
}
V_19 = V_17 -> V_172 ;
V_177:
F_60 ( & V_17 -> V_169 ) ;
return V_19 ;
}
static int F_91 ( struct V_107 * V_107 , void * V_194 ,
struct V_266 * V_184 )
{
struct V_17 * V_17 = V_194 ;
const struct V_184 * V_187 ;
int V_256 , V_19 ;
V_256 = F_88 ( V_17 , V_184 -> V_38 ) ;
if ( V_256 < 0 )
return - V_50 ;
V_187 = & V_17 -> V_21 -> V_187 [ V_256 ] ;
if ( F_57 ( & V_17 -> V_169 ) )
return - V_170 ;
if ( ! V_17 -> V_127 ) {
V_19 = - V_28 ;
goto V_177;
}
V_17 -> V_172 = 0 ;
if ( V_187 -> V_271 != NULL ) {
V_19 = V_187 -> V_271 ( V_17 , & V_184 -> V_267 ) ;
goto V_177;
}
if ( V_17 -> V_86 . V_187 != NULL )
V_184 -> V_267 = V_17 -> V_86 . V_187 [ V_256 ] . V_189 ;
V_19 = 0 ;
V_177:
F_60 ( & V_17 -> V_169 ) ;
return V_19 ;
}
static int F_92 ( struct V_107 * V_107 , void * V_194 ,
struct V_272 * V_273 )
{
struct V_17 * V_17 = V_194 ;
if ( ! V_17 -> V_21 -> V_274 )
return - V_50 ;
return V_17 -> V_21 -> V_274 ( V_17 , V_273 ) ;
}
static int F_93 ( struct V_107 * V_107 , void * V_194 ,
struct V_275 * V_276 )
{
struct V_17 * V_17 = V_194 ;
if ( V_276 -> V_117 != 0 )
return - V_50 ;
V_276 -> type = V_277 ;
V_276 -> V_20 = V_17 -> V_86 . V_278 ;
F_87 ( V_276 -> V_37 , V_17 -> V_21 -> V_37 ,
sizeof V_276 -> V_37 ) ;
return 0 ;
}
static int F_94 ( struct V_107 * V_107 , void * V_194 , unsigned int * V_66 )
{
* V_66 = 0 ;
return 0 ;
}
static int F_95 ( struct V_107 * V_107 , void * V_194 , unsigned int V_66 )
{
if ( V_66 > 0 )
return - V_50 ;
return ( 0 ) ;
}
static int F_96 ( struct V_107 * V_107 , void * V_194 ,
struct V_279 * V_280 )
{
struct V_17 * V_17 = V_194 ;
int V_66 , V_19 = 0 , V_85 ;
V_66 = V_280 -> V_109 ;
switch ( V_66 ) {
case V_281 :
case V_282 :
case V_283 :
break;
default:
return - V_50 ;
}
if ( F_57 ( & V_17 -> V_212 ) )
return - V_170 ;
if ( V_17 -> V_109 != V_124
&& V_17 -> V_109 != V_281
&& V_17 -> V_109 != V_280 -> V_109 ) {
V_19 = - V_213 ;
goto V_177;
}
if ( V_17 -> V_115 != NULL
&& V_17 -> V_115 != V_107 ) {
V_19 = - V_213 ;
goto V_177;
}
for ( V_66 = 0 ; V_66 < V_17 -> V_116 ; V_66 ++ ) {
if ( V_17 -> V_10 [ V_66 ] . V_12 ) {
V_19 = - V_213 ;
goto V_177;
}
}
V_85 = V_17 -> V_85 ;
if ( V_85 ) {
F_84 ( & V_17 -> V_169 ) ;
V_17 -> V_172 = 0 ;
F_49 ( V_17 ) ;
F_60 ( & V_17 -> V_169 ) ;
if ( V_17 -> V_109 == V_281 )
V_85 = 0 ;
}
if ( V_17 -> V_116 != 0 )
F_44 ( V_17 ) ;
if ( V_280 -> V_110 == 0 )
goto V_177;
V_19 = F_41 ( V_17 , V_107 , V_280 -> V_109 , V_280 -> V_110 ) ;
if ( V_19 == 0 ) {
V_280 -> V_110 = V_17 -> V_116 ;
if ( V_85 )
V_19 = F_56 ( V_17 ) ;
}
V_177:
F_60 ( & V_17 -> V_212 ) ;
F_2 ( V_6 , L_46 , V_19 , V_280 -> V_110 ) ;
return V_19 ;
}
static int F_97 ( struct V_107 * V_107 , void * V_194 ,
struct V_284 * V_13 )
{
struct V_17 * V_17 = V_194 ;
struct V_9 * V_10 ;
if ( V_13 -> V_117 < 0
|| V_13 -> V_117 >= V_17 -> V_116 )
return - V_50 ;
V_10 = & V_17 -> V_10 [ V_13 -> V_117 ] ;
memcpy ( V_13 , & V_10 -> V_13 , sizeof *V_13 ) ;
return 0 ;
}
static int F_98 ( struct V_107 * V_107 , void * V_194 ,
enum V_285 V_286 )
{
struct V_17 * V_17 = V_194 ;
int V_19 ;
if ( V_286 != V_118 )
return - V_50 ;
if ( F_57 ( & V_17 -> V_212 ) )
return - V_170 ;
if ( V_17 -> V_115 != V_107 ) {
V_19 = - V_213 ;
goto V_177;
}
if ( V_17 -> V_116 == 0
|| ! ( V_17 -> V_10 [ 0 ] . V_13 . V_14 & V_103 ) ) {
V_19 = - V_50 ;
goto V_177;
}
if ( ! V_17 -> V_85 ) {
V_19 = F_56 ( V_17 ) ;
if ( V_19 < 0 )
goto V_177;
}
#ifdef F_71
if ( V_211 & V_6 ) {
F_1 ( L_47 ,
V_17 -> V_2 ,
V_17 -> V_136 ,
V_17 -> V_137 ) ;
}
#endif
V_19 = 0 ;
V_177:
F_60 ( & V_17 -> V_212 ) ;
return V_19 ;
}
static int F_99 ( struct V_107 * V_107 , void * V_194 ,
enum V_285 V_286 )
{
struct V_17 * V_17 = V_194 ;
int V_19 ;
if ( V_286 != V_118 )
return - V_50 ;
if ( F_57 ( & V_17 -> V_212 ) )
return - V_170 ;
if ( ! V_17 -> V_85 ) {
V_19 = 0 ;
goto V_177;
}
if ( V_17 -> V_115 != V_107 ) {
V_19 = - V_213 ;
goto V_177;
}
if ( F_57 ( & V_17 -> V_169 ) ) {
V_19 = - V_170 ;
goto V_177;
}
V_17 -> V_172 = 0 ;
F_49 ( V_17 ) ;
F_60 ( & V_17 -> V_169 ) ;
F_40 ( & V_17 -> V_105 ) ;
F_39 ( & V_17 -> V_93 , 0 ) ;
F_39 ( & V_17 -> V_92 , 0 ) ;
V_17 -> V_123 = 0 ;
V_19 = 0 ;
V_177:
F_60 ( & V_17 -> V_212 ) ;
return V_19 ;
}
static int F_100 ( struct V_107 * V_107 , void * V_194 ,
struct V_287 * V_288 )
{
struct V_17 * V_17 = V_194 ;
int V_19 ;
if ( ! V_17 -> V_21 -> V_289 )
return - V_50 ;
if ( F_57 ( & V_17 -> V_169 ) )
return - V_170 ;
V_17 -> V_172 = 0 ;
if ( V_17 -> V_127 )
V_19 = V_17 -> V_21 -> V_289 ( V_17 , V_288 ) ;
else
V_19 = - V_28 ;
F_60 ( & V_17 -> V_169 ) ;
return V_19 ;
}
static int F_101 ( struct V_107 * V_107 , void * V_194 ,
struct V_287 * V_288 )
{
struct V_17 * V_17 = V_194 ;
int V_19 ;
if ( ! V_17 -> V_21 -> V_290 )
return - V_50 ;
if ( F_57 ( & V_17 -> V_169 ) )
return - V_170 ;
V_17 -> V_172 = 0 ;
if ( V_17 -> V_127 )
V_19 = V_17 -> V_21 -> V_290 ( V_17 , V_288 ) ;
else
V_19 = - V_28 ;
F_60 ( & V_17 -> V_169 ) ;
return V_19 ;
}
static int F_102 ( struct V_107 * V_219 , void * V_194 ,
struct V_139 * V_140 )
{
struct V_17 * V_17 = V_194 ;
V_140 -> V_140 . V_141 . V_291 = V_17 -> V_292 ;
if ( V_17 -> V_21 -> V_138 ) {
int V_19 ;
if ( F_57 ( & V_17 -> V_169 ) )
return - V_170 ;
if ( V_17 -> V_127 ) {
V_17 -> V_172 = 0 ;
V_17 -> V_21 -> V_138 ( V_17 , V_140 ) ;
V_19 = V_17 -> V_172 ;
} else {
V_19 = - V_28 ;
}
F_60 ( & V_17 -> V_169 ) ;
return V_19 ;
}
return 0 ;
}
static int F_103 ( struct V_107 * V_219 , void * V_194 ,
struct V_139 * V_140 )
{
struct V_17 * V_17 = V_194 ;
int V_157 ;
V_157 = V_140 -> V_140 . V_141 . V_291 ;
if ( V_157 == 0 || V_157 >= V_104 )
V_140 -> V_140 . V_141 . V_291 = V_17 -> V_292 ;
else
V_17 -> V_292 = V_157 ;
if ( V_17 -> V_21 -> V_293 ) {
int V_19 ;
if ( F_57 ( & V_17 -> V_169 ) )
return - V_170 ;
if ( V_17 -> V_127 ) {
V_17 -> V_172 = 0 ;
V_17 -> V_21 -> V_293 ( V_17 , V_140 ) ;
V_19 = V_17 -> V_172 ;
} else {
V_19 = - V_28 ;
}
F_60 ( & V_17 -> V_169 ) ;
return V_19 ;
}
return 0 ;
}
static int F_104 ( struct V_107 * V_107 , struct V_7 * V_8 )
{
struct V_17 * V_17 = V_107 -> V_234 ;
struct V_9 * V_10 ;
struct V_294 * V_294 ;
unsigned long V_295 , V_181 , V_296 ;
int V_66 , V_19 ;
V_181 = V_8 -> V_297 ;
V_296 = V_8 -> V_298 - V_8 -> V_297 ;
F_2 ( V_6 , L_48 , ( int ) V_181 , ( int ) V_296 ) ;
if ( F_57 ( & V_17 -> V_212 ) )
return - V_170 ;
if ( ! V_17 -> V_127 ) {
V_19 = - V_28 ;
goto V_177;
}
if ( V_17 -> V_115 != V_107 ) {
V_19 = - V_50 ;
goto V_177;
}
V_10 = NULL ;
for ( V_66 = 0 ; V_66 < V_17 -> V_116 ; ++ V_66 ) {
if ( V_17 -> V_10 [ V_66 ] . V_13 . V_109 != V_282 ) {
F_2 ( V_6 , L_49 ) ;
break;
}
if ( ( V_17 -> V_10 [ V_66 ] . V_13 . V_122 . V_84 >> V_299 )
== V_8 -> V_300 ) {
V_10 = & V_17 -> V_10 [ V_66 ] ;
break;
}
}
if ( V_10 == NULL ) {
F_2 ( V_6 , L_50 ) ;
V_19 = - V_50 ;
goto V_177;
}
if ( V_296 != V_10 -> V_13 . V_121 ) {
F_2 ( V_6 , L_51 ) ;
V_19 = - V_50 ;
goto V_177;
}
V_8 -> V_301 |= V_302 ;
V_295 = ( unsigned long ) V_10 -> V_72 ;
while ( V_296 > 0 ) {
V_294 = F_105 ( ( void * ) V_295 ) ;
V_19 = F_106 ( V_8 , V_181 , V_294 ) ;
if ( V_19 < 0 )
goto V_177;
V_181 += V_303 ;
V_295 += V_303 ;
V_296 -= V_303 ;
}
V_8 -> V_304 = & V_305 ;
V_8 -> V_11 = V_10 ;
F_3 ( V_8 ) ;
V_19 = 0 ;
V_177:
F_60 ( & V_17 -> V_212 ) ;
return V_19 ;
}
static int F_107 ( struct V_17 * V_17 , struct V_107 * V_107 ,
enum V_108 V_109 )
{
if ( ! V_17 -> V_127 )
return - V_28 ;
if ( V_17 -> V_115 != V_107 || V_17 -> V_109 != V_109 ||
! V_17 -> V_85 )
return - V_50 ;
return V_17 -> V_123 != F_36 ( & V_17 -> V_92 ) ;
}
static int F_108 ( struct V_17 * V_17 , struct V_107 * V_107 ,
enum V_108 V_109 )
{
int V_19 ;
if ( F_57 ( & V_17 -> V_212 ) )
return - V_170 ;
V_19 = F_107 ( V_17 , V_107 , V_109 ) ;
F_60 ( & V_17 -> V_212 ) ;
return V_19 ;
}
static int F_109 ( struct V_107 * V_107 , void * V_194 ,
struct V_284 * V_13 )
{
struct V_17 * V_17 = V_194 ;
struct V_9 * V_10 ;
int V_66 , V_90 , V_19 ;
F_2 ( V_106 , L_52 ) ;
if ( F_57 ( & V_17 -> V_212 ) )
return - V_170 ;
for (; ; ) {
V_19 = F_107 ( V_17 , V_107 , V_13 -> V_109 ) ;
if ( V_19 < 0 )
goto V_177;
if ( V_19 > 0 )
break;
F_60 ( & V_17 -> V_212 ) ;
if ( V_107 -> V_306 & V_307 )
return - V_308 ;
V_19 = F_110 ( V_17 -> V_105 ,
F_108 ( V_17 , V_107 , V_13 -> V_109 ) ,
F_111 ( 3000 ) ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_19 == 0 )
return - V_176 ;
if ( F_57 ( & V_17 -> V_212 ) )
return - V_170 ;
}
V_66 = V_17 -> V_123 ;
V_90 = V_17 -> V_95 [ V_66 ] ;
V_10 = & V_17 -> V_10 [ V_90 ] ;
V_17 -> V_123 = ( V_66 + 1 ) % V_104 ;
if ( V_17 -> V_21 -> V_309 ) {
F_84 ( & V_17 -> V_169 ) ;
V_17 -> V_172 = 0 ;
if ( V_17 -> V_127 )
V_17 -> V_21 -> V_309 ( V_17 ) ;
F_60 ( & V_17 -> V_169 ) ;
}
V_10 -> V_13 . V_14 &= ~ V_102 ;
memcpy ( V_13 , & V_10 -> V_13 , sizeof *V_13 ) ;
F_2 ( V_106 , L_53 , V_90 ) ;
V_19 = 0 ;
if ( V_17 -> V_109 == V_283 ) {
if ( F_112 ( ( V_310 V_311 * ) V_10 -> V_13 . V_122 . V_312 ,
V_10 -> V_72 ,
V_10 -> V_13 . V_101 ) ) {
F_2 ( V_25 | V_6 ,
L_54 ) ;
V_19 = - V_313 ;
}
}
V_177:
F_60 ( & V_17 -> V_212 ) ;
return V_19 ;
}
static int F_113 ( struct V_107 * V_107 , void * V_194 ,
struct V_284 * V_13 )
{
struct V_17 * V_17 = V_194 ;
struct V_9 * V_10 ;
int V_66 , V_117 , V_19 ;
F_2 ( V_106 , L_55 , V_13 -> V_117 ) ;
if ( F_57 ( & V_17 -> V_212 ) )
return - V_170 ;
V_117 = V_13 -> V_117 ;
if ( ( unsigned ) V_117 >= V_17 -> V_116 ) {
F_2 ( V_106 ,
L_56 , V_117 , V_17 -> V_116 ) ;
V_19 = - V_50 ;
goto V_177;
}
if ( V_13 -> V_109 != V_17 -> V_109 ) {
F_2 ( V_106 , L_57 ) ;
V_19 = - V_50 ;
goto V_177;
}
V_10 = & V_17 -> V_10 [ V_117 ] ;
if ( V_10 -> V_13 . V_14 & V_314 ) {
F_2 ( V_106 , L_58 ) ;
V_19 = - V_50 ;
goto V_177;
}
V_10 -> V_13 . V_14 |= V_103 ;
if ( V_10 -> V_13 . V_109 == V_283 ) {
V_10 -> V_13 . V_122 . V_312 = V_13 -> V_122 . V_312 ;
V_10 -> V_13 . V_121 = V_13 -> V_121 ;
}
V_66 = F_36 ( & V_17 -> V_93 ) ;
V_17 -> V_95 [ V_66 ] = V_117 ;
F_39 ( & V_17 -> V_93 , ( V_66 + 1 ) % V_104 ) ;
V_13 -> V_14 |= V_103 ;
V_13 -> V_14 &= ~ V_102 ;
V_19 = 0 ;
V_177:
F_60 ( & V_17 -> V_212 ) ;
return V_19 ;
}
static int F_114 ( struct V_17 * V_17 ,
struct V_107 * V_107 )
{
struct V_284 V_13 ;
int V_66 , V_19 ;
F_2 ( V_6 , L_59 ) ;
if ( V_17 -> V_116 == 0 ) {
struct V_279 V_280 ;
memset ( & V_280 , 0 , sizeof V_280 ) ;
V_280 . V_110 = V_17 -> V_292 ;
V_280 . type = V_118 ;
V_280 . V_109 = V_281 ;
V_19 = F_96 ( V_107 , V_17 , & V_280 ) ;
if ( V_19 != 0 ) {
F_2 ( V_6 , L_60 , V_19 ) ;
return V_19 ;
}
memset ( & V_13 , 0 , sizeof V_13 ) ;
V_13 . type = V_118 ;
V_13 . V_109 = V_281 ;
for ( V_66 = 0 ; V_66 < V_17 -> V_292 ; V_66 ++ ) {
V_13 . V_117 = V_66 ;
V_19 = F_113 ( V_107 , V_17 , & V_13 ) ;
if ( V_19 != 0 ) {
F_2 ( V_6 , L_61 , V_19 ) ;
return V_19 ;
}
}
V_17 -> V_109 = V_281 ;
}
V_19 = F_98 ( V_107 , V_17 , V_118 ) ;
if ( V_19 != 0 )
F_2 ( V_6 , L_62 , V_19 ) ;
return V_19 ;
}
static unsigned int F_115 ( struct V_107 * V_107 , T_5 * V_315 )
{
struct V_17 * V_17 = V_107 -> V_234 ;
int V_19 ;
F_2 ( V_106 , L_63 ) ;
F_116 ( V_107 , & V_17 -> V_105 , V_315 ) ;
if ( V_17 -> V_109 == V_124 ) {
V_19 = F_114 ( V_17 , V_107 ) ;
if ( V_19 != 0 )
return V_316 ;
}
if ( F_57 ( & V_17 -> V_212 ) != 0 )
return V_316 ;
if ( V_17 -> V_123 != F_36 ( & V_17 -> V_92 ) )
V_19 = V_317 | V_318 ;
else
V_19 = 0 ;
F_60 ( & V_17 -> V_212 ) ;
if ( ! V_17 -> V_127 )
return V_319 ;
return V_19 ;
}
static T_6 F_117 ( struct V_107 * V_107 , char V_311 * V_72 ,
T_7 V_110 , T_8 * V_320 )
{
struct V_17 * V_17 = V_107 -> V_234 ;
struct V_9 * V_10 ;
struct V_284 V_13 ;
struct V_321 V_96 ;
int V_157 , V_19 , V_322 ;
F_2 ( V_106 , L_64 , V_110 ) ;
if ( ! V_17 -> V_127 )
return - V_28 ;
if ( V_17 -> V_109 == V_124 ) {
V_19 = F_114 ( V_17 , V_107 ) ;
if ( V_19 != 0 )
return V_19 ;
}
V_96 = F_37 ( F_38 () ) ;
V_96 . V_323 -- ;
V_157 = 2 ;
for (; ; ) {
memset ( & V_13 , 0 , sizeof V_13 ) ;
V_13 . type = V_118 ;
V_13 . V_109 = V_281 ;
V_19 = F_109 ( V_107 , V_17 , & V_13 ) ;
if ( V_19 != 0 ) {
F_2 ( V_6 , L_65 , V_19 ) ;
return V_19 ;
}
V_10 = & V_17 -> V_10 [ V_13 . V_117 ] ;
if ( -- V_157 < 0 )
break;
if ( V_10 -> V_13 . V_96 . V_323 >= V_96 . V_323 )
break;
V_19 = F_113 ( V_107 , V_17 , & V_13 ) ;
if ( V_19 != 0 ) {
F_2 ( V_6 , L_66 , V_19 ) ;
return V_19 ;
}
}
if ( V_110 > V_10 -> V_13 . V_101 )
V_110 = V_10 -> V_13 . V_101 ;
V_19 = F_112 ( V_72 , V_10 -> V_72 , V_110 ) ;
if ( V_19 != 0 ) {
F_2 ( V_25 | V_6 ,
L_67 , V_19 , V_110 ) ;
V_19 = - V_313 ;
goto V_177;
}
V_19 = V_110 ;
V_177:
V_322 = F_113 ( V_107 , V_17 , & V_13 ) ;
if ( V_322 != 0 )
return V_322 ;
return V_19 ;
}
static void F_118 ( struct V_17 * V_17 )
{
struct V_183 * V_184 ;
int V_66 ;
for ( V_66 = 0 , V_184 = V_17 -> V_86 . V_187 ;
V_66 < V_17 -> V_21 -> V_188 ;
V_66 ++ , V_184 ++ ) {
V_184 -> V_190 = V_17 -> V_21 -> V_187 [ V_66 ] . V_253 . V_259 ;
V_184 -> V_189 = V_184 -> V_190 ;
V_184 -> V_261 = V_17 -> V_21 -> V_187 [ V_66 ] . V_253 . V_260 ;
V_184 -> V_263 = V_17 -> V_21 -> V_187 [ V_66 ] . V_253 . V_262 ;
}
}
int F_119 ( struct V_62 * V_63 ,
const struct V_324 * V_38 ,
const struct V_21 * V_21 ,
int V_325 ,
struct V_233 * V_233 )
{
struct V_17 * V_17 ;
struct V_48 * V_31 = F_120 ( V_63 ) ;
int V_19 ;
F_121 ( L_68 V_326 L_69 ,
V_21 -> V_37 , V_38 -> V_245 , V_38 -> V_246 ) ;
if ( V_325 < sizeof *V_17 )
V_325 = sizeof *V_17 ;
V_17 = F_122 ( V_325 , V_54 ) ;
if ( ! V_17 ) {
F_7 ( L_70 ) ;
return - V_35 ;
}
V_17 -> V_230 = F_123 ( V_327 , V_54 ) ;
if ( ! V_17 -> V_230 ) {
F_7 ( L_71 ) ;
V_19 = - V_35 ;
goto V_177;
}
V_17 -> V_31 = V_31 ;
V_17 -> V_67 = V_63 -> V_68 -> V_69 . V_328 ;
V_17 -> V_146 = V_63 -> V_150 ;
if ( V_31 -> V_329 -> V_69 . V_330 != 1 ) {
int V_66 ;
struct V_62 * V_331 ;
for ( V_66 = 0 ; V_66 < V_31 -> V_329 -> V_69 . V_330 ; V_66 ++ ) {
V_331 = V_31 -> V_329 -> V_332 [ V_66 ] ;
if ( V_331 != NULL
&& V_331 -> V_152 != NULL
&& V_331 -> V_152 -> V_69 . V_333 ==
V_334 ) {
V_17 -> V_335 = 1 ;
break;
}
}
}
V_17 -> V_21 = V_21 ;
V_17 -> V_292 = 2 ;
V_17 -> V_83 = - 1 ;
V_19 = V_21 -> V_329 ( V_17 , V_38 ) ;
if ( V_19 < 0 )
goto V_177;
if ( V_17 -> V_86 . V_187 != NULL )
F_118 ( V_17 ) ;
V_19 = V_21 -> V_336 ( V_17 ) ;
if ( V_19 < 0 )
goto V_177;
F_61 ( V_17 ) ;
V_19 = F_8 ( V_17 ) ;
if ( V_19 )
goto V_177;
F_124 ( & V_17 -> V_169 ) ;
F_124 ( & V_17 -> V_212 ) ;
F_125 ( & V_17 -> V_105 ) ;
memcpy ( & V_17 -> V_228 , & V_337 , sizeof V_337 ) ;
V_17 -> V_228 . V_43 = & V_63 -> V_31 ;
V_17 -> V_233 = V_233 ;
V_17 -> V_127 = 1 ;
V_19 = F_126 ( & V_17 -> V_228 ,
V_338 ,
- 1 ) ;
if ( V_19 < 0 ) {
F_7 ( L_72 , V_19 ) ;
goto V_177;
}
F_127 ( V_63 , V_17 ) ;
F_2 ( V_229 , L_73 , F_78 ( & V_17 -> V_228 ) ) ;
F_25 ( V_17 ) ;
return 0 ;
V_177:
#if F_128 ( V_339 ) || F_128 ( V_340 )
if ( V_17 -> V_32 )
F_129 ( V_17 -> V_32 ) ;
#endif
F_79 ( V_17 -> V_230 ) ;
F_79 ( V_17 ) ;
return V_19 ;
}
int F_130 ( struct V_62 * V_63 ,
const struct V_324 * V_38 ,
const struct V_21 * V_21 ,
int V_325 ,
struct V_233 * V_233 )
{
struct V_48 * V_31 = F_120 ( V_63 ) ;
if ( V_31 -> V_244 . V_341 != 1 ) {
F_7 ( L_74 ,
V_38 -> V_245 , V_38 -> V_246 ) ;
return - V_28 ;
}
if ( V_31 -> V_329 -> V_69 . V_330 != 1
&& V_63 -> V_68 -> V_69 . V_328 != 0 )
return - V_28 ;
return F_119 ( V_63 , V_38 , V_21 , V_325 , V_233 ) ;
}
void F_131 ( struct V_62 * V_63 )
{
struct V_17 * V_17 = F_132 ( V_63 ) ;
#if F_128 ( V_339 ) || F_128 ( V_340 )
struct V_32 * V_32 ;
#endif
F_2 ( V_229 , L_75 ,
F_78 ( & V_17 -> V_228 ) ) ;
F_84 ( & V_17 -> V_169 ) ;
V_17 -> V_127 = 0 ;
F_40 ( & V_17 -> V_105 ) ;
F_46 ( V_17 ) ;
#if F_128 ( V_339 ) || F_128 ( V_340 )
F_29 ( V_17 ) ;
V_32 = V_17 -> V_32 ;
if ( V_32 ) {
V_17 -> V_32 = NULL ;
F_129 ( V_32 ) ;
}
#endif
V_17 -> V_31 = NULL ;
F_60 ( & V_17 -> V_169 ) ;
F_127 ( V_63 , NULL ) ;
F_133 ( & V_17 -> V_228 ) ;
}
int F_134 ( struct V_62 * V_63 , T_9 V_342 )
{
struct V_17 * V_17 = F_132 ( V_63 ) ;
if ( ! V_17 -> V_85 )
return 0 ;
V_17 -> V_76 = 1 ;
if ( V_17 -> V_21 -> V_128 )
V_17 -> V_21 -> V_128 ( V_17 ) ;
F_46 ( V_17 ) ;
F_29 ( V_17 ) ;
F_47 ( V_17 ) ;
if ( V_17 -> V_21 -> V_129 )
V_17 -> V_21 -> V_129 ( V_17 ) ;
return 0 ;
}
int F_135 ( struct V_62 * V_63 )
{
struct V_17 * V_17 = F_132 ( V_63 ) ;
V_17 -> V_76 = 0 ;
V_17 -> V_21 -> V_336 ( V_17 ) ;
F_25 ( V_17 ) ;
if ( V_17 -> V_85 )
return F_56 ( V_17 ) ;
return 0 ;
}
int F_136 ( struct V_17 * V_17 , int V_343 ,
int V_344 , int V_345 , int V_346 , int V_347 )
{
int V_66 , V_348 , V_349 , V_350 , V_351 , V_352 , V_353 ;
const struct V_184 * V_354 = NULL ;
const struct V_184 * V_355 = NULL ;
const struct V_184 * V_356 = NULL ;
int V_357 = 0 ;
for ( V_66 = 0 ; V_66 < V_17 -> V_21 -> V_188 ; V_66 ++ ) {
if ( V_17 -> V_252 & ( 1 << V_66 ) )
continue;
if ( V_17 -> V_21 -> V_187 [ V_66 ] . V_253 . V_38 == V_358 )
V_354 = & V_17 -> V_21 -> V_187 [ V_66 ] ;
if ( V_17 -> V_21 -> V_187 [ V_66 ] . V_253 . V_38 == V_359 )
V_355 = & V_17 -> V_21 -> V_187 [ V_66 ] ;
if ( V_17 -> V_21 -> V_187 [ V_66 ] . V_253 . V_38 == V_360 )
V_356 = & V_17 -> V_21 -> V_187 [ V_66 ] ;
}
if ( ! V_354 || ! V_355 || ! V_356 ) {
F_2 ( V_25 , L_76
L_77 ) ;
return 0 ;
}
if ( V_354 -> V_271 ( V_17 , & V_349 ) ||
V_355 -> V_271 ( V_17 , & V_351 ) ||
V_356 -> V_271 ( V_17 , & V_353 ) || ! V_353 )
return 0 ;
V_350 = V_349 ;
V_352 = V_351 ;
V_348 = abs ( V_344 - V_343 ) / V_345 ;
F_2 ( V_106 , L_78 ,
V_343 , V_344 , V_348 ) ;
for ( V_66 = 0 ; V_66 < V_348 ; V_66 ++ ) {
if ( V_343 > V_344 ) {
if ( V_349 > V_346 )
V_349 -- ;
else if ( V_351 > V_347 )
V_351 -- ;
else if ( V_349 > V_354 -> V_253 . V_259 )
V_349 -- ;
else if ( V_351 > V_355 -> V_253 . V_260 )
V_351 -- ;
else if ( V_349 > V_354 -> V_253 . V_260 )
V_349 -- ;
else
break;
} else {
if ( V_349 < V_354 -> V_253 . V_259 )
V_349 ++ ;
else if ( V_351 < V_347 )
V_351 ++ ;
else if ( V_349 < V_346 )
V_349 ++ ;
else if ( V_351 < V_355 -> V_253 . V_262 )
V_351 ++ ;
else if ( V_349 < V_354 -> V_253 . V_262 )
V_349 ++ ;
else
break;
}
}
if ( V_349 != V_350 ) {
V_354 -> V_269 ( V_17 , V_349 ) ;
V_357 = 1 ;
}
if ( V_351 != V_352 ) {
V_355 -> V_269 ( V_17 , V_351 ) ;
V_357 = 1 ;
}
return V_357 ;
}
static int T_10 F_137 ( void )
{
F_121 ( L_79 V_326 L_80 ) ;
return 0 ;
}
static void T_11 F_138 ( void )
{
}
