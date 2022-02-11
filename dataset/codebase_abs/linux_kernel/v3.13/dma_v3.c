static void F_1 ( struct V_1 * V_2 [ 2 ] ,
T_1 V_3 , T_2 V_4 , int V_5 )
{
struct V_1 * V_6 = V_2 [ V_7 >> V_5 & 1 ] ;
V_6 -> V_8 [ V_9 [ V_5 ] ] = V_3 + V_4 ;
}
static T_1 F_2 ( struct V_1 * V_2 [ 2 ] , int V_5 )
{
struct V_1 * V_6 = V_2 [ V_10 >> V_5 & 1 ] ;
return V_6 -> V_8 [ V_11 [ V_5 ] ] ;
}
static T_1 F_3 ( struct V_1 * V_12 [ 3 ] , int V_5 )
{
struct V_1 * V_6 = V_12 [ V_13 [ V_5 ] ] ;
return V_6 -> V_8 [ V_14 [ V_5 ] ] ;
}
static void F_4 ( struct V_1 * V_2 [ 2 ] ,
T_1 V_3 , T_2 V_4 , T_3 V_15 , int V_5 )
{
struct V_16 * V_17 = (struct V_16 * ) V_2 [ 0 ] ;
struct V_1 * V_6 = V_2 [ V_10 >> V_5 & 1 ] ;
V_6 -> V_8 [ V_11 [ V_5 ] ] = V_3 + V_4 ;
V_17 -> V_15 [ V_5 ] = V_15 ;
}
static bool F_5 ( struct V_18 * V_19 )
{
switch ( V_19 -> V_20 ) {
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
return true ;
default:
return false ;
}
}
static bool F_6 ( struct V_18 * V_19 )
{
switch ( V_19 -> V_20 ) {
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
return true ;
default:
return false ;
}
}
static bool F_7 ( struct V_18 * V_19 )
{
switch ( V_19 -> V_20 ) {
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
return true ;
default:
return false ;
}
}
static bool F_8 ( struct V_18 * V_19 )
{
switch ( V_19 -> V_20 ) {
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
return true ;
default:
return false ;
}
}
static bool F_9 ( struct V_18 * V_19 )
{
return F_5 ( V_19 ) || F_6 ( V_19 ) || F_7 ( V_19 ) ||
F_8 ( V_19 ) ;
}
static bool F_10 ( struct V_18 * V_19 )
{
switch ( V_19 -> V_20 ) {
case V_61 :
case V_62 :
case V_63 :
case V_64 :
return true ;
default:
return false ;
}
}
static bool F_11 ( struct V_18 * V_19 )
{
switch ( V_19 -> V_20 ) {
case V_63 :
case V_64 :
return true ;
default:
return false ;
}
}
static void F_12 ( struct V_1 * V_12 [ 3 ] ,
T_1 V_3 , T_2 V_4 , T_3 V_15 , unsigned V_5 )
{
struct V_16 * V_17 = (struct V_16 * ) V_12 [ 0 ] ;
struct V_65 * V_66 =
(struct V_65 * ) V_12 [ 1 ] ;
struct V_1 * V_6 = V_12 [ V_13 [ V_5 ] ] ;
V_6 -> V_8 [ V_14 [ V_5 ] ] = V_3 + V_4 ;
if ( V_5 < 8 )
V_17 -> V_15 [ V_5 ] = V_15 ;
else
V_66 -> V_15 [ V_5 - 8 ] = V_15 ;
}
static struct V_67 *
F_13 ( struct V_68 * V_20 , unsigned int V_69 )
{
struct V_67 * V_70 ;
T_4 V_71 = V_72 | V_73 ;
V_70 = F_14 ( V_74 , V_71 ) ;
if ( ! V_70 )
return NULL ;
V_70 -> V_69 = V_69 ;
V_70 -> V_75 = F_15 ( V_20 -> V_76 [ V_69 ] ,
V_71 , & V_70 -> V_77 ) ;
if ( ! V_70 -> V_75 ) {
F_16 ( V_74 , V_70 ) ;
return NULL ;
}
return V_70 ;
}
static void F_17 ( struct V_68 * V_20 , struct V_67 * V_70 )
{
if ( ! V_70 )
return;
F_18 ( V_20 -> V_76 [ V_70 -> V_69 ] , V_70 -> V_75 , V_70 -> V_77 ) ;
F_16 ( V_74 , V_70 ) ;
}
static bool F_19 ( struct V_78 * V_12 )
{
struct V_79 * V_75 = V_12 -> V_75 ;
if ( V_75 -> V_80 . V_81 == V_82 ||
V_75 -> V_80 . V_81 == V_83 ) {
struct V_84 * V_85 = V_12 -> V_85 ;
if ( F_20 ( V_85 -> V_80 . V_86 ) > 5 )
return true ;
} else if ( V_75 -> V_80 . V_81 == V_87 ||
V_75 -> V_80 . V_81 == V_88 ) {
struct V_16 * V_17 = V_12 -> V_17 ;
if ( F_20 ( V_17 -> V_80 . V_86 ) > 3 )
return true ;
}
return false ;
}
static T_5 F_21 ( struct V_89 * V_90 )
{
T_5 V_91 ;
T_5 V_92 ;
V_92 = * V_90 -> V_92 ;
V_91 = F_22 ( V_92 ) ;
F_23 ( F_24 ( V_90 ) , L_1 , V_93 ,
( unsigned long long ) V_91 ) ;
return V_91 ;
}
static bool F_25 ( struct V_89 * V_90 ,
T_5 * V_91 )
{
* V_91 = F_21 ( V_90 ) ;
if ( * V_91 == V_90 -> V_94 )
return false ;
F_26 ( V_95 , & V_90 -> V_96 ) ;
F_27 ( & V_90 -> V_97 , V_98 + V_99 ) ;
return true ;
}
static void
F_28 ( struct V_100 * V_101 , struct V_78 * V_12 )
{
struct V_79 * V_75 = V_12 -> V_75 ;
switch ( V_75 -> V_80 . V_81 ) {
case V_88 :
case V_102 :
{
struct V_16 * V_17 = V_12 -> V_17 ;
if ( ! V_17 -> V_103 . V_104 )
return;
if ( V_17 -> V_103 . V_105 )
* V_12 -> V_106 |= V_107 ;
if ( V_17 -> V_103 . V_108 )
* V_12 -> V_106 |= V_109 ;
return;
}
default:
return;
}
}
static void F_29 ( struct V_100 * V_101 , T_1 V_91 )
{
struct V_89 * V_90 = & V_101 -> V_110 ;
struct V_68 * V_20 = V_90 -> V_20 ;
struct V_78 * V_12 ;
bool V_111 = false ;
int V_5 = V_101 -> V_112 , V_113 ;
T_6 V_114 ;
F_23 ( F_24 ( V_90 ) , L_2 ,
V_93 , V_101 -> V_115 , V_101 -> V_112 , V_101 -> V_116 ) ;
if ( ! V_91 )
return;
V_114 = F_30 ( V_101 ) ;
for ( V_113 = 0 ; V_113 < V_114 && ! V_111 ; V_113 ++ ) {
struct V_117 * V_118 ;
F_31 () ;
F_32 ( F_33 ( V_101 , V_5 + V_113 + 1 ) ) ;
V_12 = F_33 ( V_101 , V_5 + V_113 ) ;
F_34 ( V_101 , V_12 ) ;
if ( V_20 -> V_119 & V_120 )
F_28 ( V_101 , V_12 ) ;
V_118 = & V_12 -> V_121 ;
if ( V_118 -> V_122 ) {
F_35 ( V_118 ) ;
F_36 ( V_118 ) ;
if ( V_118 -> V_123 ) {
V_118 -> V_123 ( V_118 -> V_124 ) ;
V_118 -> V_123 = NULL ;
}
}
if ( V_118 -> V_125 == V_91 )
V_111 = true ;
if ( F_19 ( V_12 ) ) {
F_37 ( V_113 + 1 >= V_114 ) ;
V_113 ++ ;
}
if ( V_12 -> V_70 ) {
F_17 ( V_20 , V_12 -> V_70 ) ;
V_12 -> V_70 = NULL ;
}
}
F_38 () ;
V_101 -> V_112 = V_5 + V_113 ;
F_37 ( V_114 && ! V_111 ) ;
V_90 -> V_94 = V_91 ;
if ( V_114 - V_113 == 0 ) {
F_23 ( F_24 ( V_90 ) , L_3 ,
V_93 ) ;
F_26 ( V_126 , & V_90 -> V_96 ) ;
F_27 ( & V_90 -> V_97 , V_98 + V_127 ) ;
}
F_39 ( F_40 ( ( 5 * ( V_114 - V_113 ) ) , V_128 ) ,
V_90 -> V_20 -> V_129 + V_130 ) ;
}
static void F_41 ( struct V_100 * V_101 )
{
struct V_89 * V_90 = & V_101 -> V_110 ;
T_5 V_91 ;
F_42 ( & V_90 -> V_131 ) ;
if ( F_25 ( V_90 , & V_91 ) )
F_29 ( V_101 , V_91 ) ;
if ( F_43 ( * V_90 -> V_92 ) ) {
T_2 V_132 = F_44 ( V_90 -> V_129 + V_133 ) ;
if ( V_132 & V_134 ) {
F_27 ( & V_90 -> V_97 , V_98 + V_127 ) ;
F_45 ( V_101 ) ;
}
}
F_46 ( & V_90 -> V_131 ) ;
}
static void F_47 ( unsigned long V_135 )
{
struct V_100 * V_101 = F_48 ( ( void * ) V_135 ) ;
F_41 ( V_101 ) ;
F_39 ( V_136 , V_101 -> V_110 . V_129 + V_137 ) ;
}
static void F_49 ( struct V_100 * V_101 )
{
struct V_89 * V_90 = & V_101 -> V_110 ;
T_5 V_91 ;
F_50 ( V_90 , 0 ) ;
if ( F_25 ( V_90 , & V_91 ) )
F_29 ( V_101 , V_91 ) ;
F_51 ( V_101 ) ;
}
static void F_45 ( struct V_100 * V_101 )
{
struct V_89 * V_90 = & V_101 -> V_110 ;
struct V_18 * V_19 = F_52 ( V_90 ) ;
struct V_79 * V_75 ;
T_5 V_91 ;
struct V_78 * V_12 ;
T_2 V_138 = 0 ;
T_2 V_139 ;
T_2 V_132 ;
if ( F_25 ( V_90 , & V_91 ) )
F_29 ( V_101 , V_91 ) ;
V_132 = F_44 ( V_90 -> V_129 + V_133 ) ;
F_53 ( V_19 , V_140 , & V_139 ) ;
F_23 ( F_24 ( V_90 ) , L_4 ,
V_93 , V_132 , V_139 ) ;
V_12 = F_33 ( V_101 , V_101 -> V_112 ) ;
V_75 = V_12 -> V_75 ;
F_34 ( V_101 , V_12 ) ;
switch ( V_75 -> V_80 . V_81 ) {
case V_83 :
if ( V_132 & V_141 ) {
* V_12 -> V_106 |= V_107 ;
V_138 |= V_141 ;
}
break;
case V_88 :
case V_102 :
if ( V_132 & V_141 ) {
* V_12 -> V_106 |= V_107 ;
V_138 |= V_141 ;
}
if ( V_132 & V_142 ) {
* V_12 -> V_106 |= V_109 ;
V_138 |= V_142 ;
}
break;
}
if ( V_132 ^ V_138 || V_132 == 0 ) {
F_54 ( F_24 ( V_90 ) , L_5 ,
V_93 , V_132 , V_138 ) ;
F_55 () ;
}
F_56 ( V_132 , V_90 -> V_129 + V_133 ) ;
F_57 ( V_19 , V_140 , V_139 ) ;
* V_90 -> V_92 = V_12 -> V_121 . V_125 ;
F_42 ( & V_101 -> V_143 ) ;
F_49 ( V_101 ) ;
F_46 ( & V_101 -> V_143 ) ;
}
static void F_58 ( struct V_100 * V_101 )
{
struct V_89 * V_90 = & V_101 -> V_110 ;
if ( F_30 ( V_101 ) ) {
F_27 ( & V_90 -> V_97 , V_98 + V_99 ) ;
return;
}
if ( F_59 ( V_144 , & V_90 -> V_96 ) )
F_27 ( & V_90 -> V_97 , V_98 + V_127 ) ;
else if ( V_101 -> V_145 > F_60 () ) {
F_61 ( V_101 , V_101 -> V_145 - 1 ) ;
if ( V_101 -> V_145 > F_60 () )
F_27 ( & V_90 -> V_97 , V_98 + V_127 ) ;
}
}
static void F_62 ( unsigned long V_135 )
{
struct V_100 * V_101 = F_48 ( ( void * ) V_135 ) ;
struct V_89 * V_90 = & V_101 -> V_110 ;
T_1 V_91 ;
T_5 V_146 ;
V_146 = F_63 ( V_90 ) ;
if ( F_43 ( V_146 ) ) {
T_2 V_132 ;
V_132 = F_44 ( V_90 -> V_129 + V_133 ) ;
F_54 ( F_24 ( V_90 ) , L_6 ,
V_93 , V_132 ) ;
if ( F_64 ( V_147 , & V_90 -> V_96 ) )
F_37 ( F_65 ( V_132 ) ) ;
else
return;
}
F_42 ( & V_90 -> V_131 ) ;
if ( F_66 ( V_90 , & V_91 ) )
F_29 ( V_101 , V_91 ) ;
else if ( F_64 ( V_95 , & V_90 -> V_96 ) ) {
F_42 ( & V_101 -> V_143 ) ;
F_49 ( V_101 ) ;
F_46 ( & V_101 -> V_143 ) ;
F_46 ( & V_90 -> V_131 ) ;
return;
} else {
F_67 ( V_95 , & V_90 -> V_96 ) ;
F_27 ( & V_90 -> V_97 , V_98 + V_99 ) ;
}
if ( F_30 ( V_101 ) )
F_27 ( & V_90 -> V_97 , V_98 + V_99 ) ;
else {
F_42 ( & V_101 -> V_143 ) ;
F_58 ( V_101 ) ;
F_46 ( & V_101 -> V_143 ) ;
}
F_46 ( & V_90 -> V_131 ) ;
}
static enum V_148
F_68 ( struct V_149 * V_150 , T_7 V_122 ,
struct V_151 * V_152 )
{
struct V_100 * V_101 = F_48 ( V_150 ) ;
enum V_148 V_153 ;
V_153 = F_69 ( V_150 , V_122 , V_152 ) ;
if ( V_153 == V_154 )
return V_153 ;
F_41 ( V_101 ) ;
return F_69 ( V_150 , V_122 , V_152 ) ;
}
static struct V_117 *
F_70 ( struct V_149 * V_150 , enum V_155 * V_106 ,
T_1 V_156 , T_1 * V_157 , unsigned int V_86 ,
T_8 V_158 , unsigned long V_71 )
{
struct V_100 * V_101 = F_48 ( V_150 ) ;
struct V_78 * V_159 ;
struct V_78 * V_12 ;
struct V_78 * V_160 ;
T_8 V_161 = V_158 ;
struct V_84 * V_85 ;
struct V_162 * V_163 = NULL ;
struct V_79 * V_75 ;
int V_164 , V_165 , V_5 , V_113 ;
T_2 V_4 = 0 ;
T_3 V_81 = V_106 ? V_83 : V_82 ;
F_37 ( V_86 < 2 ) ;
V_164 = F_71 ( V_101 , V_158 ) ;
if ( V_86 > 5 ) {
V_165 = 1 ;
V_164 *= 2 ;
} else
V_165 = 0 ;
if ( F_72 ( V_164 ) && F_73 ( V_101 , V_164 + 1 ) == 0 )
V_5 = V_101 -> V_115 ;
else
return NULL ;
V_113 = 0 ;
do {
struct V_1 * V_2 [ 2 ] ;
T_8 V_166 = F_74 ( T_8 , V_158 , 1 << V_101 -> V_167 ) ;
int V_168 ;
V_12 = F_33 ( V_101 , V_5 + V_113 ) ;
V_85 = V_12 -> V_85 ;
V_160 = F_33 ( V_101 , V_5 + V_113 + 1 ) ;
V_163 = V_160 -> V_163 ;
V_2 [ 0 ] = (struct V_1 * ) V_85 ;
V_2 [ 1 ] = (struct V_1 * ) V_163 ;
for ( V_168 = 0 ; V_168 < V_86 ; V_168 ++ )
F_1 ( V_2 , V_157 [ V_168 ] , V_4 , V_168 ) ;
V_85 -> V_169 = V_166 ;
V_85 -> V_170 = V_156 + V_4 ;
V_85 -> V_171 = 0 ;
V_85 -> V_80 . V_81 = V_81 ;
V_85 -> V_80 . V_86 = F_75 ( V_86 ) ;
V_158 -= V_166 ;
V_4 += V_166 ;
F_34 ( V_101 , V_12 ) ;
} while ( ( V_113 += 1 + V_165 ) < V_164 );
V_12 -> V_121 . V_71 = V_71 ;
V_12 -> V_158 = V_161 ;
if ( V_106 )
V_12 -> V_106 = V_106 ;
V_85 -> V_80 . V_172 = ! ! ( V_71 & V_173 ) ;
V_159 = F_33 ( V_101 , V_5 + V_113 ) ;
V_159 -> V_121 . V_71 = V_71 & V_174 ;
V_75 = V_159 -> V_75 ;
V_75 -> V_171 = 0 ;
V_75 -> V_80 . null = 1 ;
V_75 -> V_80 . V_175 = ! ! ( V_71 & V_174 ) ;
V_75 -> V_80 . V_176 = 1 ;
V_75 -> V_169 = V_177 ;
F_34 ( V_101 , V_159 ) ;
return & V_159 -> V_121 ;
}
static struct V_117 *
F_76 ( struct V_149 * V_90 , T_1 V_156 , T_1 * V_157 ,
unsigned int V_86 , T_8 V_158 , unsigned long V_71 )
{
return F_70 ( V_90 , NULL , V_156 , V_157 , V_86 , V_158 , V_71 ) ;
}
struct V_117 *
F_77 ( struct V_149 * V_90 , T_1 * V_157 ,
unsigned int V_86 , T_8 V_158 ,
enum V_155 * V_106 , unsigned long V_71 )
{
* V_106 = 0 ;
return F_70 ( V_90 , V_106 , V_157 [ 0 ] , & V_157 [ 1 ] ,
V_86 - 1 , V_158 , V_71 ) ;
}
static void
F_78 ( struct V_100 * V_101 , struct V_78 * V_12 , struct V_78 * V_160 )
{
struct V_20 * V_178 = F_24 ( & V_101 -> V_110 ) ;
struct V_16 * V_17 = V_12 -> V_17 ;
struct V_179 * V_180 = V_160 ? V_160 -> V_180 : NULL ;
struct V_1 * V_2 [] = { ( void * ) V_17 , ( void * ) V_180 } ;
int V_86 = F_20 ( V_17 -> V_80 . V_86 ) ;
int V_113 ;
F_23 ( V_178 , L_7
L_8
L_9 ,
F_79 ( V_12 ) , ( unsigned long long ) V_12 -> V_121 . V_125 ,
( unsigned long long ) ( V_180 ? V_180 -> V_181 : V_17 -> V_181 ) ,
V_12 -> V_121 . V_71 , V_17 -> V_169 , V_17 -> V_171 , V_17 -> V_80 . V_81 , V_17 -> V_80 . V_175 ,
V_17 -> V_80 . V_176 ,
V_17 -> V_80 . V_182 ? L_10 : L_11 , V_17 -> V_80 . V_183 ? L_10 : L_12 ,
V_17 -> V_80 . V_86 ) ;
for ( V_113 = 0 ; V_113 < V_86 ; V_113 ++ )
F_23 ( V_178 , L_13 , V_113 ,
( unsigned long long ) F_2 ( V_2 , V_113 ) , V_17 -> V_15 [ V_113 ] ) ;
F_23 ( V_178 , L_14 , V_17 -> V_184 ) ;
F_23 ( V_178 , L_15 , V_17 -> V_185 ) ;
F_23 ( V_178 , L_16 , V_17 -> V_181 ) ;
}
static void F_80 ( struct V_100 * V_101 ,
struct V_78 * V_12 )
{
struct V_20 * V_178 = F_24 ( & V_101 -> V_110 ) ;
struct V_16 * V_17 = V_12 -> V_17 ;
struct V_1 * V_2 [] = { ( void * ) V_17 ,
( void * ) V_17 ,
( void * ) V_17 } ;
int V_86 = F_81 ( V_17 -> V_80 . V_86 ) ;
int V_113 ;
if ( V_12 -> V_70 ) {
V_2 [ 1 ] = ( void * ) V_12 -> V_70 -> V_75 ;
V_2 [ 2 ] = ( void * ) V_12 -> V_70 -> V_75 + 64 ;
}
F_23 ( V_178 , L_7
L_17
L_9 ,
F_79 ( V_12 ) , ( unsigned long long ) V_12 -> V_121 . V_125 ,
( unsigned long long ) V_17 -> V_181 ,
V_12 -> V_121 . V_71 , V_17 -> V_169 , V_17 -> V_171 ,
V_17 -> V_80 . V_81 , V_17 -> V_80 . V_175 ,
V_17 -> V_80 . V_176 ,
V_17 -> V_80 . V_182 ? L_10 : L_11 , V_17 -> V_80 . V_183 ? L_10 : L_12 ,
V_17 -> V_80 . V_86 ) ;
for ( V_113 = 0 ; V_113 < V_86 ; V_113 ++ ) {
F_23 ( V_178 , L_13 , V_113 ,
( unsigned long long ) F_3 ( V_2 , V_113 ) ,
V_17 -> V_15 [ V_113 ] ) ;
}
F_23 ( V_178 , L_14 , V_17 -> V_184 ) ;
F_23 ( V_178 , L_15 , V_17 -> V_185 ) ;
}
static struct V_117 *
F_82 ( struct V_149 * V_150 , enum V_155 * V_106 ,
const T_1 * V_186 , const T_1 * V_157 ,
unsigned int V_86 , const unsigned char * V_187 ,
T_8 V_158 , unsigned long V_71 )
{
struct V_100 * V_101 = F_48 ( V_150 ) ;
struct V_89 * V_90 = & V_101 -> V_110 ;
struct V_68 * V_20 = V_90 -> V_20 ;
struct V_78 * V_159 ;
struct V_78 * V_12 ;
struct V_78 * V_160 ;
T_8 V_161 = V_158 ;
struct V_16 * V_17 ;
struct V_179 * V_180 = NULL ;
struct V_79 * V_75 ;
T_2 V_4 = 0 ;
T_3 V_81 = V_106 ? V_88 : V_87 ;
int V_113 , V_168 , V_5 , V_165 , V_164 ;
int V_188 = ( V_20 -> V_189 < V_190 ) ? 1 : 0 ;
F_23 ( F_24 ( V_90 ) , L_18 , V_93 ) ;
F_37 ( V_86 + F_83 ( V_71 ) < 2 ) ;
V_164 = F_71 ( V_101 , V_158 ) ;
if ( V_86 + F_84 ( V_71 ) > 3 ||
( F_83 ( V_71 ) && ! F_84 ( V_71 ) ) ) {
V_165 = 1 ;
V_164 *= 2 ;
} else
V_165 = 0 ;
if ( F_72 ( V_164 ) &&
F_73 ( V_101 , V_164 + V_188 ) == 0 )
V_5 = V_101 -> V_115 ;
else
return NULL ;
V_113 = 0 ;
do {
struct V_1 * V_2 [ 2 ] ;
T_8 V_166 = F_74 ( T_8 , V_158 , 1 << V_101 -> V_167 ) ;
V_12 = F_33 ( V_101 , V_5 + V_113 ) ;
V_17 = V_12 -> V_17 ;
V_160 = F_33 ( V_101 , V_5 + V_113 + V_165 ) ;
V_180 = V_160 -> V_180 ;
V_2 [ 0 ] = (struct V_1 * ) V_17 ;
V_2 [ 1 ] = (struct V_1 * ) V_180 ;
for ( V_168 = 0 ; V_168 < V_86 ; V_168 ++ )
F_4 ( V_2 , V_157 [ V_168 ] , V_4 , V_187 [ V_168 ] , V_168 ) ;
if ( F_84 ( V_71 ) )
F_4 ( V_2 , V_186 [ 1 ] , V_4 , 1 , V_168 ++ ) ;
else if ( F_83 ( V_71 ) ) {
F_4 ( V_2 , V_186 [ 0 ] , V_4 , 0 , V_168 ++ ) ;
F_4 ( V_2 , V_186 [ 1 ] , V_4 , 1 , V_168 ++ ) ;
F_4 ( V_2 , V_186 [ 1 ] , V_4 , 0 , V_168 ++ ) ;
}
V_17 -> V_169 = V_166 ;
V_17 -> V_184 = V_186 [ 0 ] + V_4 ;
V_17 -> V_185 = V_186 [ 1 ] + V_4 ;
V_17 -> V_171 = 0 ;
V_17 -> V_80 . V_81 = V_81 ;
if ( V_20 -> V_119 & V_120 )
V_17 -> V_80 . V_191 = V_106 ? 1 : 0 ;
V_17 -> V_80 . V_86 = F_75 ( V_168 ) ;
V_17 -> V_80 . V_182 = ! ! ( V_71 & V_192 ) ;
V_17 -> V_80 . V_183 = ! ! ( V_71 & V_193 ) ;
V_158 -= V_166 ;
V_4 += V_166 ;
} while ( ( V_113 += 1 + V_165 ) < V_164 );
V_12 -> V_121 . V_71 = V_71 ;
V_12 -> V_158 = V_161 ;
if ( V_106 )
V_12 -> V_106 = V_106 ;
V_17 -> V_80 . V_172 = ! ! ( V_71 & V_173 ) ;
F_78 ( V_101 , V_12 , V_160 ) ;
if ( ! V_188 ) {
V_17 -> V_80 . V_175 = ! ! ( V_71 & V_174 ) ;
V_17 -> V_80 . V_176 = 1 ;
V_159 = V_12 ;
} else {
V_159 = F_33 ( V_101 , V_5 + V_113 ) ;
V_159 -> V_121 . V_71 = V_71 & V_174 ;
V_75 = V_159 -> V_75 ;
V_75 -> V_171 = 0 ;
V_75 -> V_80 . null = 1 ;
V_75 -> V_80 . V_175 = ! ! ( V_71 & V_174 ) ;
V_75 -> V_80 . V_176 = 1 ;
V_75 -> V_169 = V_177 ;
F_34 ( V_101 , V_159 ) ;
}
return & V_159 -> V_121 ;
}
static struct V_117 *
F_85 ( struct V_149 * V_150 , enum V_155 * V_106 ,
const T_1 * V_186 , const T_1 * V_157 ,
unsigned int V_86 , const unsigned char * V_187 ,
T_8 V_158 , unsigned long V_71 )
{
struct V_100 * V_101 = F_48 ( V_150 ) ;
struct V_89 * V_90 = & V_101 -> V_110 ;
struct V_68 * V_20 = V_90 -> V_20 ;
struct V_78 * V_12 ;
T_8 V_161 = V_158 ;
struct V_16 * V_17 ;
T_2 V_4 = 0 ;
T_3 V_81 ;
int V_113 , V_168 , V_5 , V_164 ;
V_81 = V_106 ? V_102 : V_194 ;
F_23 ( F_24 ( V_90 ) , L_18 , V_93 ) ;
V_164 = F_71 ( V_101 , V_158 ) ;
if ( V_164 && F_73 ( V_101 , V_164 ) == 0 )
V_5 = V_101 -> V_115 ;
else
return NULL ;
V_113 = 0 ;
do {
struct V_1 * V_2 [ 4 ] ;
T_8 V_166 = F_74 ( T_8 , V_158 , 1 << V_101 -> V_167 ) ;
V_12 = F_33 ( V_101 , V_5 + V_113 ) ;
V_17 = V_12 -> V_17 ;
V_2 [ 0 ] = (struct V_1 * ) V_17 ;
V_12 -> V_70 = F_13 ( V_20 , ( V_86 - 2 ) >> 3 ) ;
if ( ! V_12 -> V_70 ) {
F_54 ( F_24 ( V_90 ) ,
L_19 , V_93 ) ;
return NULL ;
}
V_17 -> V_195 = V_12 -> V_70 -> V_77 ;
V_12 -> V_70 -> V_196 = V_12 ;
V_2 [ 1 ] = (struct V_1 * ) V_12 -> V_70 -> V_75 ;
V_2 [ 2 ] = ( void * ) V_2 [ 1 ] + 64 ;
for ( V_168 = 0 ; V_168 < V_86 ; V_168 ++ )
F_12 ( V_2 , V_157 [ V_168 ] , V_4 , V_187 [ V_168 ] , V_168 ) ;
if ( F_84 ( V_71 ) )
F_12 ( V_2 , V_186 [ 1 ] , V_4 , 1 , V_168 ++ ) ;
else if ( F_83 ( V_71 ) ) {
F_12 ( V_2 , V_186 [ 0 ] , V_4 , 0 , V_168 ++ ) ;
F_12 ( V_2 , V_186 [ 1 ] , V_4 , 1 , V_168 ++ ) ;
F_12 ( V_2 , V_186 [ 1 ] , V_4 , 0 , V_168 ++ ) ;
}
V_17 -> V_169 = V_166 ;
V_17 -> V_184 = V_186 [ 0 ] + V_4 ;
V_17 -> V_185 = V_186 [ 1 ] + V_4 ;
V_17 -> V_171 = 0 ;
V_17 -> V_80 . V_81 = V_81 ;
V_17 -> V_80 . V_86 = F_86 ( V_168 ) ;
if ( V_20 -> V_119 & V_120 )
V_17 -> V_80 . V_191 = V_106 ? 1 : 0 ;
V_17 -> V_80 . V_182 = ! ! ( V_71 & V_192 ) ;
V_17 -> V_80 . V_183 = ! ! ( V_71 & V_193 ) ;
V_158 -= V_166 ;
V_4 += V_166 ;
} while ( ++ V_113 < V_164 );
V_12 -> V_121 . V_71 = V_71 ;
V_12 -> V_158 = V_161 ;
if ( V_106 )
V_12 -> V_106 = V_106 ;
V_17 -> V_80 . V_172 = ! ! ( V_71 & V_173 ) ;
V_17 -> V_80 . V_175 = ! ! ( V_71 & V_174 ) ;
V_17 -> V_80 . V_176 = 1 ;
F_80 ( V_101 , V_12 ) ;
return & V_12 -> V_121 ;
}
static int F_87 ( unsigned int V_86 , unsigned long V_71 )
{
if ( F_84 ( V_71 ) )
return V_86 + 1 ;
else if ( F_83 ( V_71 ) )
return V_86 + 3 ;
else
return V_86 ;
}
static struct V_117 *
F_88 ( struct V_149 * V_90 , T_1 * V_186 , T_1 * V_157 ,
unsigned int V_86 , const unsigned char * V_187 , T_8 V_158 ,
unsigned long V_71 )
{
if ( V_71 & V_192 )
V_186 [ 0 ] = V_186 [ 1 ] ;
if ( V_71 & V_193 )
V_186 [ 1 ] = V_186 [ 0 ] ;
if ( ( V_71 & V_192 ) && V_86 == 1 ) {
T_1 V_197 [ 2 ] ;
unsigned char V_198 [ 2 ] ;
F_37 ( V_71 & V_193 ) ;
V_197 [ 0 ] = V_157 [ 0 ] ;
V_197 [ 1 ] = V_157 [ 0 ] ;
V_198 [ 0 ] = V_187 [ 0 ] ;
V_198 [ 1 ] = 0 ;
return F_87 ( V_86 , V_71 ) > 8 ?
F_85 ( V_90 , NULL , V_186 , V_197 ,
2 , V_198 , V_158 ,
V_71 ) :
F_82 ( V_90 , NULL , V_186 , V_197 , 2 ,
V_198 , V_158 , V_71 ) ;
} else {
return F_87 ( V_86 , V_71 ) > 8 ?
F_85 ( V_90 , NULL , V_186 , V_157 , V_86 ,
V_187 , V_158 , V_71 ) :
F_82 ( V_90 , NULL , V_186 , V_157 , V_86 ,
V_187 , V_158 , V_71 ) ;
}
}
struct V_117 *
F_89 ( struct V_149 * V_90 , T_1 * V_17 , T_1 * V_157 ,
unsigned int V_86 , const unsigned char * V_187 , T_8 V_158 ,
enum V_155 * V_199 , unsigned long V_71 )
{
if ( V_71 & V_192 )
V_17 [ 0 ] = V_17 [ 1 ] ;
if ( V_71 & V_193 )
V_17 [ 1 ] = V_17 [ 0 ] ;
* V_199 = 0 ;
return F_87 ( V_86 , V_71 ) > 8 ?
F_85 ( V_90 , V_199 , V_17 , V_157 , V_86 , V_187 , V_158 ,
V_71 ) :
F_82 ( V_90 , V_199 , V_17 , V_157 , V_86 , V_187 , V_158 ,
V_71 ) ;
}
static struct V_117 *
F_90 ( struct V_149 * V_90 , T_1 V_186 , T_1 * V_157 ,
unsigned int V_86 , T_8 V_158 , unsigned long V_71 )
{
unsigned char V_187 [ V_86 ] ;
T_1 V_17 [ 2 ] ;
memset ( V_187 , 0 , V_86 ) ;
V_17 [ 0 ] = V_186 ;
V_71 |= V_193 ;
V_17 [ 1 ] = V_186 ;
return F_87 ( V_86 , V_71 ) > 8 ?
F_85 ( V_90 , NULL , V_17 , V_157 , V_86 , V_187 , V_158 ,
V_71 ) :
F_82 ( V_90 , NULL , V_17 , V_157 , V_86 , V_187 , V_158 ,
V_71 ) ;
}
struct V_117 *
F_91 ( struct V_149 * V_90 , T_1 * V_157 ,
unsigned int V_86 , T_8 V_158 ,
enum V_155 * V_106 , unsigned long V_71 )
{
unsigned char V_187 [ V_86 ] ;
T_1 V_17 [ 2 ] ;
* V_106 = 0 ;
memset ( V_187 , 0 , V_86 ) ;
V_17 [ 0 ] = V_157 [ 0 ] ;
V_71 |= V_193 ;
V_17 [ 1 ] = V_17 [ 0 ] ;
return F_87 ( V_86 , V_71 ) > 8 ?
F_85 ( V_90 , V_106 , V_17 , & V_157 [ 1 ] , V_86 - 1 ,
V_187 , V_158 , V_71 ) :
F_82 ( V_90 , V_106 , V_17 , & V_157 [ 1 ] , V_86 - 1 ,
V_187 , V_158 , V_71 ) ;
}
static struct V_117 *
F_92 ( struct V_149 * V_150 , unsigned long V_71 )
{
struct V_100 * V_101 = F_48 ( V_150 ) ;
struct V_78 * V_12 ;
struct V_79 * V_75 ;
if ( F_73 ( V_101 , 1 ) == 0 )
V_12 = F_33 ( V_101 , V_101 -> V_115 ) ;
else
return NULL ;
V_75 = V_12 -> V_75 ;
V_75 -> V_171 = 0 ;
V_75 -> V_80 . null = 1 ;
V_75 -> V_80 . V_175 = 1 ;
V_75 -> V_80 . V_172 = ! ! ( V_71 & V_173 ) ;
V_75 -> V_80 . V_176 = 1 ;
V_75 -> V_169 = V_177 ;
V_75 -> V_200 = 0 ;
V_75 -> V_170 = 0 ;
V_12 -> V_121 . V_71 = V_71 ;
V_12 -> V_158 = 1 ;
F_34 ( V_101 , V_12 ) ;
return & V_12 -> V_121 ;
}
static void F_93 ( void * V_201 )
{
struct V_92 * V_202 = V_201 ;
F_94 ( V_202 ) ;
}
static int F_95 ( struct V_68 * V_20 )
{
int V_113 , V_203 ;
struct V_204 * V_156 ;
struct V_204 * V_205 [ V_206 ] ;
struct V_204 * V_207 [ V_206 + 1 ] ;
T_1 V_208 [ V_206 + 1 ] ;
T_1 V_209 ;
struct V_117 * V_118 ;
struct V_149 * V_149 ;
T_7 V_122 ;
T_3 V_210 = 0 ;
T_2 V_211 ;
T_2 V_212 ;
int V_213 = 0 ;
struct V_92 V_202 ;
unsigned long V_214 ;
struct V_20 * V_178 = & V_20 -> V_19 -> V_178 ;
struct V_215 * V_77 = & V_20 -> V_216 ;
T_3 V_81 = 0 ;
F_23 ( V_178 , L_18 , V_93 ) ;
if ( ! F_96 ( V_217 , V_77 -> V_218 ) )
return 0 ;
for ( V_203 = 0 ; V_203 < V_206 ; V_203 ++ ) {
V_205 [ V_203 ] = F_97 ( V_219 ) ;
if ( ! V_205 [ V_203 ] ) {
while ( V_203 -- )
F_98 ( V_205 [ V_203 ] ) ;
return - V_220 ;
}
}
V_156 = F_97 ( V_219 ) ;
if ( ! V_156 ) {
while ( V_203 -- )
F_98 ( V_205 [ V_203 ] ) ;
return - V_220 ;
}
for ( V_203 = 0 ; V_203 < V_206 ; V_203 ++ ) {
T_3 * V_221 = F_99 ( V_205 [ V_203 ] ) ;
for ( V_113 = 0 ; V_113 < V_222 ; V_113 ++ )
V_221 [ V_113 ] = ( 1 << V_203 ) ;
}
for ( V_203 = 0 ; V_203 < V_206 ; V_203 ++ )
V_210 ^= ( T_3 ) ( 1 << V_203 ) ;
V_211 = ( V_210 << 24 ) | ( V_210 << 16 ) |
( V_210 << 8 ) | V_210 ;
memset ( F_99 ( V_156 ) , 0 , V_222 ) ;
V_149 = F_100 ( V_77 -> V_223 . V_181 , struct V_149 ,
V_224 ) ;
if ( V_77 -> V_225 ( V_149 ) < 1 ) {
V_213 = - V_226 ;
goto V_227;
}
V_81 = V_82 ;
V_209 = F_101 ( V_178 , V_156 , 0 , V_222 , V_228 ) ;
for ( V_113 = 0 ; V_113 < V_206 ; V_113 ++ )
V_208 [ V_113 ] = F_101 ( V_178 , V_205 [ V_113 ] , 0 , V_222 ,
V_229 ) ;
V_118 = V_77 -> V_230 ( V_149 , V_209 , V_208 ,
V_206 , V_222 ,
V_174 ) ;
if ( ! V_118 ) {
F_54 ( V_178 , L_20 ) ;
V_213 = - V_226 ;
goto V_231;
}
F_102 ( V_118 ) ;
F_103 ( & V_202 ) ;
V_118 -> V_123 = F_93 ;
V_118 -> V_124 = & V_202 ;
V_122 = V_118 -> V_232 ( V_118 ) ;
if ( V_122 < 0 ) {
F_54 ( V_178 , L_21 ) ;
V_213 = - V_226 ;
goto V_231;
}
V_77 -> V_233 ( V_149 ) ;
V_214 = F_104 ( & V_202 , F_105 ( 3000 ) ) ;
if ( V_77 -> V_234 ( V_149 , V_122 , NULL ) != V_154 ) {
F_54 ( V_178 , L_22 ) ;
V_213 = - V_226 ;
goto V_231;
}
F_106 ( V_178 , V_209 , V_222 , V_228 ) ;
for ( V_113 = 0 ; V_113 < V_206 ; V_113 ++ )
F_106 ( V_178 , V_208 [ V_113 ] , V_222 , V_229 ) ;
F_107 ( V_178 , V_209 , V_222 , V_228 ) ;
for ( V_113 = 0 ; V_113 < ( V_222 / sizeof( T_2 ) ) ; V_113 ++ ) {
T_2 * V_221 = F_99 ( V_156 ) ;
if ( V_221 [ V_113 ] != V_211 ) {
F_54 ( V_178 , L_23 ) ;
V_213 = - V_226 ;
goto V_235;
}
}
F_108 ( V_178 , V_209 , V_222 , V_228 ) ;
if ( ! F_96 ( V_236 , V_149 -> V_20 -> V_218 ) )
goto V_235;
V_81 = V_83 ;
for ( V_113 = 0 ; V_113 < V_206 ; V_113 ++ )
V_207 [ V_113 ] = V_205 [ V_113 ] ;
V_207 [ V_113 ] = V_156 ;
V_212 = 1 ;
for ( V_113 = 0 ; V_113 < V_206 + 1 ; V_113 ++ )
V_208 [ V_113 ] = F_101 ( V_178 , V_207 [ V_113 ] , 0 , V_222 ,
V_229 ) ;
V_118 = V_77 -> V_237 ( V_149 , V_208 ,
V_206 + 1 , V_222 ,
& V_212 , V_174 ) ;
if ( ! V_118 ) {
F_54 ( V_178 , L_24 ) ;
V_213 = - V_226 ;
goto V_231;
}
F_102 ( V_118 ) ;
F_103 ( & V_202 ) ;
V_118 -> V_123 = F_93 ;
V_118 -> V_124 = & V_202 ;
V_122 = V_118 -> V_232 ( V_118 ) ;
if ( V_122 < 0 ) {
F_54 ( V_178 , L_25 ) ;
V_213 = - V_226 ;
goto V_231;
}
V_77 -> V_233 ( V_149 ) ;
V_214 = F_104 ( & V_202 , F_105 ( 3000 ) ) ;
if ( V_77 -> V_234 ( V_149 , V_122 , NULL ) != V_154 ) {
F_54 ( V_178 , L_26 ) ;
V_213 = - V_226 ;
goto V_231;
}
for ( V_113 = 0 ; V_113 < V_206 + 1 ; V_113 ++ )
F_106 ( V_178 , V_208 [ V_113 ] , V_222 , V_229 ) ;
if ( V_212 != 0 ) {
F_54 ( V_178 , L_27 ) ;
V_213 = - V_226 ;
goto V_235;
}
memset ( F_99 ( V_156 ) , 0 , V_222 ) ;
V_81 = V_83 ;
V_212 = 0 ;
for ( V_113 = 0 ; V_113 < V_206 + 1 ; V_113 ++ )
V_208 [ V_113 ] = F_101 ( V_178 , V_207 [ V_113 ] , 0 , V_222 ,
V_229 ) ;
V_118 = V_77 -> V_237 ( V_149 , V_208 ,
V_206 + 1 , V_222 ,
& V_212 , V_174 ) ;
if ( ! V_118 ) {
F_54 ( V_178 , L_28 ) ;
V_213 = - V_226 ;
goto V_231;
}
F_102 ( V_118 ) ;
F_103 ( & V_202 ) ;
V_118 -> V_123 = F_93 ;
V_118 -> V_124 = & V_202 ;
V_122 = V_118 -> V_232 ( V_118 ) ;
if ( V_122 < 0 ) {
F_54 ( V_178 , L_29 ) ;
V_213 = - V_226 ;
goto V_231;
}
V_77 -> V_233 ( V_149 ) ;
V_214 = F_104 ( & V_202 , F_105 ( 3000 ) ) ;
if ( V_77 -> V_234 ( V_149 , V_122 , NULL ) != V_154 ) {
F_54 ( V_178 , L_30 ) ;
V_213 = - V_226 ;
goto V_231;
}
if ( V_212 != V_107 ) {
F_54 ( V_178 , L_27 ) ;
V_213 = - V_226 ;
goto V_231;
}
for ( V_113 = 0 ; V_113 < V_206 + 1 ; V_113 ++ )
F_106 ( V_178 , V_208 [ V_113 ] , V_222 , V_229 ) ;
goto V_235;
V_231:
if ( V_81 == V_82 ) {
F_106 ( V_178 , V_209 , V_222 , V_228 ) ;
for ( V_113 = 0 ; V_113 < V_206 ; V_113 ++ )
F_106 ( V_178 , V_208 [ V_113 ] , V_222 ,
V_229 ) ;
} else if ( V_81 == V_83 ) {
for ( V_113 = 0 ; V_113 < V_206 + 1 ; V_113 ++ )
F_106 ( V_178 , V_208 [ V_113 ] , V_222 ,
V_229 ) ;
}
V_235:
V_77 -> V_238 ( V_149 ) ;
V_227:
V_203 = V_206 ;
while ( V_203 -- )
F_98 ( V_205 [ V_203 ] ) ;
F_98 ( V_156 ) ;
return V_213 ;
}
static int F_109 ( struct V_68 * V_20 )
{
int V_239 = F_110 ( V_20 ) ;
if ( V_239 )
return V_239 ;
V_239 = F_95 ( V_20 ) ;
if ( V_239 )
return V_239 ;
return 0 ;
}
static int F_111 ( struct V_68 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_19 ;
int V_240 = V_19 -> V_240 , V_113 ;
if ( ! F_10 ( V_19 ) )
return 0 ;
switch ( V_20 -> V_241 ) {
case V_242 :
for ( V_113 = 0 ; V_113 < V_20 -> V_216 . V_243 ; V_113 ++ ) {
struct V_244 * V_245 = & V_20 -> V_246 [ V_113 ] ;
struct V_89 * V_90 ;
V_90 = F_112 ( V_20 , V_113 ) ;
F_113 ( & V_19 -> V_178 , V_245 -> V_247 , V_90 ) ;
}
F_114 ( V_19 ) ;
break;
case V_248 :
F_115 ( V_19 ) ;
case V_249 :
F_113 ( & V_19 -> V_178 , V_240 , V_20 ) ;
break;
default:
return 0 ;
}
V_20 -> V_241 = V_250 ;
return F_116 ( V_20 ) ;
}
static int F_117 ( struct V_89 * V_90 )
{
struct V_68 * V_20 = V_90 -> V_20 ;
struct V_18 * V_19 = V_20 -> V_19 ;
T_2 V_132 ;
T_6 V_251 ;
int V_213 ;
F_50 ( V_90 , F_105 ( 100 ) ) ;
V_132 = F_44 ( V_90 -> V_129 + V_133 ) ;
F_56 ( V_132 , V_90 -> V_129 + V_133 ) ;
if ( V_20 -> V_189 < V_190 ) {
V_213 = F_53 ( V_19 ,
V_140 , & V_132 ) ;
if ( V_213 ) {
F_54 ( & V_19 -> V_178 ,
L_31 ) ;
return V_213 ;
}
F_57 ( V_19 ,
V_140 , V_132 ) ;
F_118 ( V_19 , V_252 , & V_251 ) ;
if ( V_251 == V_253 ) {
F_57 ( V_19 ,
V_254 ,
0x10 ) ;
}
}
V_213 = F_119 ( V_90 , F_105 ( 200 ) ) ;
if ( ! V_213 )
V_213 = F_111 ( V_20 ) ;
if ( V_213 )
F_54 ( & V_19 -> V_178 , L_32 , V_213 ) ;
return V_213 ;
}
static void F_120 ( struct V_68 * V_20 )
{
struct V_215 * V_77 ;
struct V_149 * V_150 ;
struct V_89 * V_90 ;
T_2 V_255 ;
V_77 = & V_20 -> V_216 ;
if ( V_20 -> V_119 & V_120 ) {
F_121 (c, &dma->channels, device_node) {
V_90 = F_122 ( V_150 ) ;
V_255 = F_44 ( V_90 -> V_129 +
V_256 ) ;
V_255 |= V_141 |
V_142 ;
F_56 ( V_255 , V_90 -> V_129 +
V_256 ) ;
}
}
}
int F_123 ( struct V_68 * V_20 , int V_257 )
{
struct V_18 * V_19 = V_20 -> V_19 ;
int V_258 = F_124 ( V_19 ) ;
struct V_215 * V_77 ;
struct V_149 * V_150 ;
struct V_89 * V_90 ;
bool V_259 = false ;
int V_213 ;
V_20 -> V_260 = V_261 ;
V_20 -> V_262 = F_117 ;
V_20 -> V_263 = F_109 ;
V_20 -> V_264 = F_120 ;
V_77 = & V_20 -> V_216 ;
V_77 -> V_265 = V_266 ;
V_77 -> V_233 = V_267 ;
V_77 -> V_225 = V_268 ;
V_77 -> V_238 = V_269 ;
F_125 ( V_270 , V_77 -> V_218 ) ;
V_77 -> V_271 = F_92 ;
V_20 -> V_119 = F_44 ( V_20 -> V_129 + V_272 ) ;
if ( F_9 ( V_19 ) || F_11 ( V_19 ) )
V_20 -> V_119 &= ~ ( V_273 | V_274 | V_275 ) ;
if ( V_258 && ( V_20 -> V_119 & ( V_273 | V_274 ) ) )
V_20 -> V_119 &= ~ ( V_273 | V_274 ) ;
if ( V_20 -> V_119 & V_273 ) {
V_259 = true ;
V_77 -> V_276 = 8 ;
F_125 ( V_217 , V_77 -> V_218 ) ;
V_77 -> V_230 = F_76 ;
F_125 ( V_236 , V_77 -> V_218 ) ;
V_77 -> V_237 = F_77 ;
}
if ( V_20 -> V_119 & V_274 ) {
V_259 = true ;
V_77 -> V_277 = F_88 ;
V_77 -> V_278 = F_89 ;
F_125 ( V_279 , V_77 -> V_218 ) ;
F_125 ( V_280 , V_77 -> V_218 ) ;
if ( V_20 -> V_119 & V_275 ) {
F_126 ( V_77 , 16 , 0 ) ;
} else {
F_126 ( V_77 , 8 , 0 ) ;
}
if ( ! ( V_20 -> V_119 & V_273 ) ) {
V_77 -> V_230 = F_90 ;
V_77 -> V_237 = F_91 ;
F_125 ( V_217 , V_77 -> V_218 ) ;
F_125 ( V_236 , V_77 -> V_218 ) ;
if ( V_20 -> V_119 & V_275 ) {
V_77 -> V_276 = 16 ;
} else {
V_77 -> V_276 = 8 ;
}
}
}
V_77 -> V_234 = F_68 ;
V_20 -> V_281 = F_47 ;
V_20 -> V_282 = F_62 ;
if ( V_20 -> V_119 & V_275 ) {
char V_283 [ 14 ] ;
int V_113 ;
for ( V_113 = 0 ; V_113 < V_284 ; V_113 ++ ) {
snprintf ( V_283 , 14 , L_33 , V_113 ) ;
V_20 -> V_76 [ V_113 ] = F_127 ( V_283 ,
& V_19 -> V_178 ,
V_285 * ( V_113 + 1 ) , 64 , 0 ) ;
if ( ! V_20 -> V_76 [ V_113 ] )
return - V_220 ;
}
}
V_213 = F_128 ( V_20 ) ;
if ( V_213 )
return V_213 ;
F_129 ( 262144 ) ;
F_121 (c, &dma->channels, device_node) {
V_90 = F_122 ( V_150 ) ;
F_56 ( V_286 ,
V_90 -> V_129 + V_287 ) ;
}
V_213 = F_130 ( V_20 ) ;
if ( V_213 )
return V_213 ;
F_131 ( V_20 , & V_288 ) ;
if ( V_257 )
V_20 -> V_257 = F_132 ( V_19 , V_20 -> V_129 ) ;
return 0 ;
}
