void F_1 ( struct V_1 * V_1 , int error )
{
struct V_2 * V_3 ;
V_3 = V_1 -> V_4 ;
V_3 -> V_5 . error = error ;
F_2 ( V_3 ) ;
V_3 -> V_5 . V_6 = 1 ;
F_3 ( & V_3 -> V_7 ) ;
F_4 ( V_1 ) ;
if ( V_3 -> V_8 )
F_5 ( V_3 ) ;
}
static void F_6 ( struct V_9 * V_10 ) __releases( T_1 )
{
unsigned long V_11 = 0 ;
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_2 * V_3 = V_13 -> V_3 ;
F_7 ( & V_3 -> V_14 -> V_15 , V_11 ) ;
V_3 -> V_16 += V_10 -> V_17 . V_18 >> 9 ;
F_8 ( & V_10 -> V_19 . V_20 ) ;
if ( F_9 ( & V_3 -> V_21 ) )
F_3 ( & V_3 -> V_22 ) ;
if ( F_10 ( V_23 , & V_10 -> V_11 ) )
F_11 ( V_3 , V_24 ) ;
F_12 ( & V_3 -> V_14 -> V_15 , V_11 ) ;
F_13 ( & V_13 -> V_25 -> V_26 , & V_10 -> V_19 ) ;
F_5 ( V_3 ) ;
}
void F_14 ( struct V_9 * V_10 ) __releases( T_1 )
{
unsigned long V_11 = 0 ;
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_2 * V_3 = V_13 -> V_3 ;
struct V_27 V_17 ;
int V_28 ;
T_2 V_29 ;
int V_30 ;
V_17 = V_10 -> V_17 ;
V_30 = V_10 -> V_11 & V_31 ;
V_29 = V_10 -> V_29 ;
V_10 -> V_11 &= ~ V_31 ;
F_7 ( & V_3 -> V_14 -> V_15 , V_11 ) ;
V_3 -> V_32 += V_10 -> V_17 . V_18 >> 9 ;
F_15 ( & V_10 -> V_19 . V_20 , & V_3 -> V_33 ) ;
V_28 = F_9 ( V_29 == V_34 ? & V_3 -> V_35 : & V_3 -> V_36 ) ;
if ( V_10 -> V_11 & V_37 )
F_11 ( V_3 , V_38 ) ;
F_12 ( & V_3 -> V_14 -> V_15 , V_11 ) ;
if ( V_29 == V_34 )
F_16 ( V_3 , V_17 . V_39 ) ;
if ( V_28 )
F_3 ( & V_3 -> V_22 ) ;
if ( V_30 )
F_17 ( V_3 , & V_17 ) ;
F_18 ( V_13 -> V_25 ) ;
F_5 ( V_3 ) ;
}
void F_19 ( struct V_1 * V_1 , int error )
{
struct V_9 * V_10 = V_1 -> V_4 ;
struct V_2 * V_3 = V_10 -> V_13 -> V_3 ;
int V_40 = F_20 ( V_1 , V_41 ) ;
int V_42 = F_21 ( V_1 ) == V_43 ;
int V_44 = ! ! ( V_1 -> V_45 & V_46 ) ;
if ( error && F_22 ( & V_47 ) )
F_23 ( V_3 , L_1 ,
V_42 ? ( V_44 ? L_2 : L_3 )
: L_4 , error ,
( unsigned long long ) V_10 -> V_17 . V_39 ) ;
if ( ! error && ! V_40 ) {
if ( F_22 ( & V_47 ) )
F_23 ( V_3 , L_5 ,
V_42 ? L_3 : L_4 ,
( unsigned long long ) V_10 -> V_17 . V_39 ) ;
error = - V_48 ;
}
if ( error )
F_24 ( V_23 , & V_10 -> V_11 ) ;
F_4 ( V_1 ) ;
if ( F_25 ( & V_10 -> V_49 ) ) {
if ( V_42 )
F_14 ( V_10 ) ;
else
F_6 ( V_10 ) ;
}
}
void F_26 ( struct V_1 * V_1 , int error )
{
unsigned long V_11 ;
struct V_50 * V_51 = V_1 -> V_4 ;
struct V_2 * V_3 = V_51 -> V_3 ;
struct V_52 V_53 ;
enum V_54 V_55 ;
int V_40 = F_20 ( V_1 , V_41 ) ;
if ( ! error && ! V_40 ) {
F_23 ( V_3 , L_6 ,
F_21 ( V_1 ) == V_43 ? L_3 : L_4 ) ;
error = - V_48 ;
}
if ( F_27 ( V_51 -> V_56 & V_57 ) ) {
if ( F_22 ( & V_47 ) )
F_28 ( V_3 , L_7 ) ;
if ( ! error )
F_29 ( L_8 ) ;
}
if ( F_27 ( error ) ) {
if ( V_1 -> V_45 & V_46 )
V_55 = ( error == - V_58 )
? V_59
: V_60 ;
else
V_55 = ( F_21 ( V_1 ) == V_43 )
? V_61
: ( F_30 ( V_1 ) == V_62 )
? V_63
: V_64 ;
} else
V_55 = V_65 ;
F_4 ( V_51 -> V_66 ) ;
V_51 -> V_66 = F_31 ( error ) ;
F_7 ( & V_3 -> V_14 -> V_15 , V_11 ) ;
F_32 ( V_51 , V_55 , & V_53 ) ;
F_12 ( & V_3 -> V_14 -> V_15 , V_11 ) ;
F_5 ( V_3 ) ;
if ( V_53 . V_1 )
F_33 ( V_3 , & V_53 ) ;
}
void F_34 ( struct V_67 * V_68 , struct V_9 * V_10 , void * V_69 )
{
struct V_70 V_71 ;
struct V_72 V_73 ;
struct V_74 * V_74 = V_10 -> V_75 ;
struct V_74 * V_76 ;
unsigned V_77 ;
V_71 . V_68 = V_68 ;
V_71 . V_11 = 0 ;
F_35 ( & V_73 , 1 ) ;
F_36 ( & V_71 ) ;
while ( ( V_76 = F_37 ( V_74 ) ) ) {
F_38 ( & V_73 , V_74 , V_78 , 0 ) ;
F_39 ( & V_71 , & V_73 , V_73 . V_79 ) ;
V_74 = V_76 ;
}
V_77 = V_10 -> V_17 . V_18 & ( V_78 - 1 ) ;
F_38 ( & V_73 , V_74 , V_77 ? : V_78 , 0 ) ;
F_39 ( & V_71 , & V_73 , V_73 . V_79 ) ;
F_40 ( & V_71 , V_69 ) ;
}
void F_41 ( struct V_67 * V_68 , struct V_1 * V_1 , void * V_69 )
{
struct V_70 V_71 ;
struct V_72 V_73 ;
struct V_80 V_81 ;
struct V_82 V_83 ;
V_71 . V_68 = V_68 ;
V_71 . V_11 = 0 ;
F_35 ( & V_73 , 1 ) ;
F_36 ( & V_71 ) ;
F_42 (bvec, bio, iter) {
F_38 ( & V_73 , V_81 . V_84 , V_81 . V_85 , V_81 . V_86 ) ;
F_39 ( & V_71 , & V_73 , V_73 . V_79 ) ;
}
F_40 ( & V_71 , V_69 ) ;
}
static int F_43 ( struct V_87 * V_19 , int V_88 )
{
struct V_9 * V_10 = F_44 ( V_19 , struct V_9 , V_19 ) ;
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_2 * V_3 = V_13 -> V_3 ;
int V_89 ;
void * V_69 ;
int V_90 = 0 ;
if ( F_27 ( V_88 ) )
goto V_91;
if ( F_27 ( ( V_10 -> V_11 & V_37 ) != 0 ) )
goto V_91;
V_89 = F_45 ( V_13 -> V_25 -> V_92 ) ;
V_69 = F_46 ( V_89 , V_93 ) ;
if ( V_69 ) {
T_3 V_39 = V_10 -> V_17 . V_39 ;
unsigned int V_18 = V_10 -> V_17 . V_18 ;
F_34 ( V_13 -> V_25 -> V_92 , V_10 , V_69 ) ;
F_47 ( V_3 , V_10 ) ;
V_10 = NULL ;
F_48 ( V_3 ) ;
V_90 = F_49 ( V_13 , V_39 , V_18 ,
V_69 , V_89 ,
V_94 ) ;
F_50 ( V_69 ) ;
} else {
F_51 ( V_3 , L_9 ) ;
V_90 = - V_95 ;
}
V_91:
if ( V_10 )
F_47 ( V_3 , V_10 ) ;
if ( F_27 ( V_90 ) )
F_51 ( V_3 , L_10 ) ;
return V_90 ;
}
static int F_52 ( struct V_12 * V_13 , T_3 V_39 , int V_18 )
{
struct V_2 * V_3 = V_13 -> V_3 ;
struct V_9 * V_10 ;
if ( ! F_53 ( V_3 ) )
return - V_48 ;
V_10 = F_54 ( V_13 , V_34 , V_39 ,
V_18 , true , V_96 ) ;
if ( ! V_10 )
goto V_97;
V_10 -> V_19 . V_98 = F_43 ;
F_55 ( & V_3 -> V_14 -> V_15 ) ;
F_56 ( & V_10 -> V_19 . V_20 , & V_3 -> V_21 ) ;
F_57 ( & V_3 -> V_14 -> V_15 ) ;
F_58 ( V_18 >> 9 , & V_3 -> V_99 ) ;
if ( F_59 ( V_3 , V_10 , V_62 , V_100 ) == 0 )
return 0 ;
F_55 ( & V_3 -> V_14 -> V_15 ) ;
F_8 ( & V_10 -> V_19 . V_20 ) ;
F_57 ( & V_3 -> V_14 -> V_15 ) ;
F_47 ( V_3 , V_10 ) ;
V_97:
F_5 ( V_3 ) ;
return - V_101 ;
}
int F_60 ( struct V_87 * V_19 , int V_88 )
{
struct V_2 * V_3 =
F_44 ( V_19 , struct V_2 , V_102 ) ;
switch ( V_3 -> V_103 . V_104 ) {
case V_105 :
F_61 ( V_3 , V_88 ) ;
break;
case V_106 :
F_62 ( V_3 , V_88 ) ;
break;
}
return 0 ;
}
void F_63 ( unsigned long V_107 )
{
struct V_2 * V_3 = (struct V_2 * ) V_107 ;
F_64 (
& F_65 ( V_3 ) -> V_25 -> V_26 ,
& V_3 -> V_102 ) ;
}
static void F_66 ( struct V_108 * V_109 , int V_110 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_109 -> V_18 ; V_17 ++ )
V_109 -> V_111 [ V_17 ] = V_110 ;
}
static int F_67 ( struct V_108 * V_109 , int V_110 )
{
int V_112 ;
V_112 = V_109 -> V_111 [ V_109 -> V_113 ] ;
V_109 -> V_111 [ V_109 -> V_113 ++ ] = V_110 ;
if ( V_109 -> V_113 >= V_109 -> V_18 )
V_109 -> V_113 = 0 ;
return V_112 ;
}
static void F_68 ( struct V_108 * V_109 , int V_110 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_109 -> V_18 ; V_17 ++ )
V_109 -> V_111 [ V_17 ] += V_110 ;
}
struct V_108 * F_69 ( int V_114 )
{
struct V_108 * V_109 ;
V_109 = F_70 ( sizeof( struct V_108 ) + sizeof( int ) * V_114 , V_93 ) ;
if ( ! V_109 )
return NULL ;
V_109 -> V_113 = 0 ;
V_109 -> V_18 = V_114 ;
V_109 -> V_115 = 0 ;
return V_109 ;
}
static int F_71 ( struct V_2 * V_3 , unsigned int V_116 )
{
struct V_117 * V_118 ;
unsigned int V_119 ;
int V_120 ;
int V_121 ;
int V_122 ;
int V_123 ;
int V_124 ;
int V_125 ;
struct V_108 * V_126 ;
V_118 = F_72 ( V_3 -> V_8 -> V_117 ) ;
V_126 = F_72 ( V_3 -> V_127 ) ;
V_123 = V_126 -> V_18 ;
if ( V_3 -> V_128 + V_116 == 0 ) {
V_119 = ( ( V_118 -> V_129 * 2 * V_130 ) / V_131 ) * V_123 ;
} else {
V_119 = V_118 -> V_132 ? V_118 -> V_132 :
V_116 * V_118 -> V_133 * V_131 / ( V_130 * 10 ) ;
}
V_121 = V_119 - V_3 -> V_128 - V_126 -> V_115 ;
V_122 = V_121 / V_123 ;
F_68 ( V_126 , V_122 ) ;
V_126 -> V_115 += V_122 * V_123 ;
V_124 = F_67 ( V_126 , 0 ) ;
V_126 -> V_115 -= V_124 ;
V_120 = V_116 + V_124 ;
if ( V_120 < 0 )
V_120 = 0 ;
V_125 = ( V_118 -> V_134 * 2 * V_130 ) / V_131 ;
if ( V_120 > V_125 )
V_120 = V_125 ;
return V_120 ;
}
static int F_73 ( struct V_2 * V_3 )
{
unsigned int V_116 ;
int V_135 , V_136 ;
V_116 = F_74 ( & V_3 -> V_137 , 0 ) ;
V_3 -> V_128 -= V_116 ;
F_75 () ;
V_136 = F_76 ( V_3 ) / 2 ;
if ( F_72 ( V_3 -> V_127 ) -> V_18 ) {
V_135 = F_71 ( V_3 , V_116 ) >> ( V_138 - 9 ) ;
V_3 -> V_139 = V_135 * V_131 * ( V_140 / 1024 ) / V_130 ;
} else {
V_3 -> V_139 = F_72 ( V_3 -> V_8 -> V_117 ) -> V_129 ;
V_135 = V_130 * V_3 -> V_139 / ( ( V_140 / 1024 ) * V_131 ) ;
}
F_77 () ;
if ( V_136 - V_3 -> V_128 / 8 < V_135 )
V_135 = V_136 - V_3 -> V_128 / 8 ;
return V_135 ;
}
static int F_62 ( struct V_2 * const V_3 , int V_88 )
{
struct V_12 * const V_13 = F_65 ( V_3 ) ;
struct V_141 * const V_25 = V_13 ? V_13 -> V_25 : NULL ;
unsigned long V_142 ;
T_3 V_39 ;
const T_3 V_143 = F_78 ( V_3 -> V_144 ) ;
int V_145 ;
int V_135 , V_146 , V_18 ;
int V_147 , V_148 = 0 ;
int V_17 = 0 ;
if ( F_27 ( V_88 ) )
return 0 ;
if ( V_3 -> V_149 == 0 ) {
F_79 ( V_3 ) ;
return 0 ;
}
if ( ! F_53 ( V_3 ) ) {
F_51 ( V_3 , L_11 ) ;
return 0 ;
}
V_145 = F_80 ( V_3 -> V_150 ) << 9 ;
V_135 = F_73 ( V_3 ) ;
if ( V_135 <= 0 )
goto V_148;
for ( V_17 = 0 ; V_17 < V_135 ; V_17 ++ ) {
F_81 ( & V_25 -> V_107 . V_151 ) ;
if ( V_25 -> V_107 . V_152 ) {
struct V_153 * V_154 = V_25 -> V_107 . V_152 -> V_154 ;
int V_155 = V_154 -> V_156 ;
int V_157 = V_154 -> V_158 ;
if ( V_155 > V_157 / 2 ) {
V_148 = 1 ;
if ( V_154 -> V_159 )
F_24 ( V_160 , & V_154 -> V_159 -> V_11 ) ;
}
} else
V_148 = 1 ;
F_82 ( & V_25 -> V_107 . V_151 ) ;
if ( V_148 )
goto V_148;
V_161:
V_18 = V_140 ;
V_142 = F_83 ( V_3 , V_3 -> V_162 ) ;
if ( V_142 == V_163 ) {
V_3 -> V_162 = F_84 ( V_3 ) ;
F_5 ( V_3 ) ;
return 0 ;
}
V_39 = F_85 ( V_142 ) ;
if ( F_86 ( V_3 , V_39 ) ) {
V_3 -> V_162 = V_142 ;
goto V_148;
}
V_3 -> V_162 = V_142 + 1 ;
if ( F_27 ( F_87 ( V_3 , V_142 ) == 0 ) ) {
F_16 ( V_3 , V_39 ) ;
goto V_161;
}
#if V_164 > V_140
V_147 = 1 ;
V_146 = V_17 ;
while ( V_17 < V_135 ) {
if ( V_18 + V_140 > V_145 )
break;
if ( V_39 & ( ( 1 << ( V_147 + 3 ) ) - 1 ) )
break;
if ( ( ( V_142 + 1 ) & V_165 ) == 0 )
break;
if ( F_87 ( V_3 , V_142 + 1 ) != 1 )
break;
V_142 ++ ;
V_18 += V_140 ;
if ( ( V_140 << V_147 ) <= V_18 )
V_147 ++ ;
V_17 ++ ;
}
if ( V_18 > V_140 )
V_3 -> V_162 = V_142 + 1 ;
#endif
if ( V_39 + ( V_18 >> 9 ) > V_143 )
V_18 = ( V_143 - V_39 ) << 9 ;
if ( V_3 -> V_166 ) {
switch ( F_52 ( V_13 , V_39 , V_18 ) ) {
case - V_48 :
F_5 ( V_3 ) ;
return - V_48 ;
case - V_101 :
F_16 ( V_3 , V_39 ) ;
V_3 -> V_162 = F_88 ( V_39 ) ;
V_17 = V_146 ;
goto V_148;
case 0 :
break;
default:
F_89 () ;
}
} else {
int V_90 ;
F_48 ( V_3 ) ;
V_90 = F_90 ( V_13 , V_167 ,
V_39 , V_18 , V_34 ) ;
if ( V_90 ) {
F_51 ( V_3 , L_12 ) ;
F_91 ( V_3 ) ;
F_5 ( V_3 ) ;
return V_90 ;
}
}
}
if ( V_3 -> V_162 >= F_84 ( V_3 ) ) {
F_5 ( V_3 ) ;
return 0 ;
}
V_148:
V_3 -> V_128 += ( V_17 << ( V_138 - 9 ) ) ;
F_92 ( & V_3 -> V_168 , V_169 + V_130 ) ;
F_5 ( V_3 ) ;
return 0 ;
}
static int F_61 ( struct V_2 * V_3 , int V_88 )
{
int V_135 , V_17 , V_18 ;
T_3 V_39 ;
const T_3 V_143 = F_78 ( V_3 -> V_144 ) ;
bool V_170 = false ;
if ( F_27 ( V_88 ) )
return 1 ;
V_135 = F_73 ( V_3 ) ;
V_39 = V_3 -> V_171 ;
for ( V_17 = 0 ; V_17 < V_135 ; V_17 ++ ) {
if ( V_39 >= V_143 )
return 1 ;
V_170 = V_17 > 0
&& F_93 ( V_3 )
&& V_39 >= V_3 -> V_172 ;
if ( V_170 )
break;
V_18 = V_140 ;
if ( F_86 ( V_3 , V_39 ) ) {
V_3 -> V_171 = V_39 ;
goto V_148;
}
if ( V_39 + ( V_18 >> 9 ) > V_143 )
V_18 = ( V_143 - V_39 ) << 9 ;
F_48 ( V_3 ) ;
if ( F_94 ( F_65 ( V_3 ) , V_39 , V_18 ) ) {
F_91 ( V_3 ) ;
return 0 ;
}
V_39 += V_173 ;
}
V_3 -> V_171 = V_39 ;
V_148:
V_3 -> V_128 += ( V_17 << ( V_138 - 9 ) ) ;
if ( V_17 == 0 || ! V_170 )
F_92 ( & V_3 -> V_168 , V_169 + V_130 ) ;
return 1 ;
}
int F_95 ( struct V_87 * V_19 , int V_88 )
{
struct V_174 * V_175 =
F_44 ( V_19 , struct V_174 , V_19 ) ;
struct V_2 * V_3 = V_175 -> V_3 ;
F_50 ( V_175 ) ;
F_96 ( V_3 ) ;
F_79 ( V_3 ) ;
return 0 ;
}
static int F_97 ( struct V_87 * V_19 , int V_88 )
{
struct V_174 * V_175 =
F_44 ( V_19 , struct V_174 , V_19 ) ;
struct V_2 * V_3 = V_175 -> V_3 ;
F_50 ( V_175 ) ;
F_79 ( V_3 ) ;
return 0 ;
}
static void F_98 ( struct V_2 * V_3 )
{
struct V_141 * V_25 = F_65 ( V_3 ) -> V_25 ;
F_99 ( V_176 , & V_25 -> V_11 ) ;
F_100 ( V_25 ) ;
F_101 ( V_25 -> V_177 ,
F_10 ( V_176 , & V_25 -> V_11 ) || V_3 -> V_103 . V_104 < V_178 ) ;
}
int F_79 ( struct V_2 * V_3 )
{
unsigned long V_179 , V_180 , V_181 ;
unsigned long V_182 ;
union V_183 V_184 , V_185 ;
struct V_174 * V_175 ;
char * V_186 = NULL ;
int V_187 = 0 ;
if ( F_102 ( V_3 ) ) {
F_103 ( V_131 / 10 ) ;
V_175 = F_46 ( sizeof( struct V_174 ) , V_188 ) ;
if ( V_175 ) {
V_175 -> V_19 . V_98 = F_97 ;
V_175 -> V_3 = V_3 ;
F_13 ( & F_65 ( V_3 ) -> V_25 -> V_26 ,
& V_175 -> V_19 ) ;
return 1 ;
}
F_51 ( V_3 , L_13 ) ;
}
V_180 = ( V_169 - V_3 -> V_189 - V_3 -> V_190 ) / V_131 ;
if ( V_180 <= 0 )
V_180 = 1 ;
V_179 = V_3 -> V_149 ;
if ( V_3 -> V_103 . V_104 == V_105 || V_3 -> V_103 . V_104 == V_191 )
V_179 -= V_3 -> V_192 ;
V_181 = F_104 ( V_179 / V_180 ) ;
V_3 -> V_190 /= V_131 ;
if ( ! F_53 ( V_3 ) )
goto V_91;
F_98 ( V_3 ) ;
F_55 ( & V_3 -> V_14 -> V_15 ) ;
V_184 = F_105 ( V_3 ) ;
V_187 = ( V_184 . V_104 == V_105 || V_184 . V_104 == V_191 ) ;
if ( V_184 . V_104 <= V_178 )
goto V_193;
V_185 = V_184 ;
V_185 . V_104 = V_178 ;
F_106 ( V_3 , L_14 ,
V_187 ? L_15 : L_16 ,
V_180 + V_3 -> V_190 , V_3 -> V_190 , V_181 ) ;
V_182 = F_107 ( V_3 ) ;
if ( V_184 . V_104 == V_105 || V_184 . V_104 == V_191 ) {
if ( V_182 ) {
F_108 ( V_3 , L_17 ,
V_182 , F_104 ( 1 ) ) ;
V_186 = L_18 ;
}
} else {
F_109 ( V_3 , ( V_182 - V_3 -> V_194 ) == 0 ) ;
if ( V_184 . V_104 == V_106 || V_184 . V_104 == V_195 )
V_186 = L_19 ;
if ( V_3 -> V_166 && V_3 -> V_149 ) {
const unsigned long V_196 = V_3 -> V_197 ;
const unsigned long V_198 = V_3 -> V_149 ;
const int V_199 =
( V_198 == 0 ) ? 0 :
( V_198 < 100000 ) ? ( ( V_196 * 100 ) / V_198 ) : ( V_196 / ( V_198 / 100 ) ) ;
F_106 ( V_3 , L_20
L_21 ,
V_199 ,
F_104 ( V_3 -> V_197 ) ,
F_104 ( V_3 -> V_149 - V_3 -> V_197 ) ,
F_104 ( V_3 -> V_149 ) ) ;
}
}
if ( V_3 -> V_194 ) {
F_106 ( V_3 , L_22 , V_3 -> V_194 ) ;
if ( V_184 . V_104 == V_106 || V_184 . V_104 == V_195 ) {
V_185 . V_200 = V_201 ;
V_185 . V_202 = V_203 ;
} else {
V_185 . V_200 = V_203 ;
V_185 . V_202 = V_201 ;
}
} else {
V_185 . V_200 = V_203 ;
V_185 . V_202 = V_203 ;
if ( V_184 . V_104 == V_106 || V_184 . V_104 == V_195 ) {
if ( V_3 -> V_204 ) {
int V_17 ;
for ( V_17 = V_205 ; V_17 <= V_206 ; V_17 ++ )
F_110 ( V_3 , V_17 , V_3 -> V_204 [ V_17 ] ) ;
F_111 ( V_3 , V_205 , V_3 -> V_8 -> V_207 . V_208 [ V_209 ] ) ;
F_110 ( V_3 , V_209 , V_3 -> V_204 [ V_209 ] ) ;
} else {
F_51 ( V_3 , L_23 ) ;
}
}
if ( ! ( V_184 . V_104 == V_105 || V_184 . V_104 == V_191 ) ) {
F_112 ( V_3 , 0UL ) ;
F_113 ( V_3 , L_24 ) ;
if ( V_3 -> V_204 ) {
int V_17 ;
for ( V_17 = V_209 ; V_17 <= V_206 ; V_17 ++ )
V_3 -> V_204 [ V_17 ] = V_3 -> V_8 -> V_207 . V_208 [ V_17 ] ;
}
}
}
F_114 ( V_3 , V_185 , V_210 , NULL ) ;
V_193:
F_57 ( & V_3 -> V_14 -> V_15 ) ;
F_5 ( V_3 ) ;
V_91:
V_3 -> V_149 = 0 ;
V_3 -> V_194 = 0 ;
V_3 -> V_190 = 0 ;
if ( V_187 && V_3 -> V_192 == 0 )
V_3 -> V_211 = 0 ;
F_115 ( V_3 ) ;
if ( V_186 )
F_116 ( V_3 , V_186 ) ;
return 1 ;
}
static void F_117 ( struct V_2 * V_3 , struct V_9 * V_10 )
{
if ( F_118 ( V_10 ) ) {
int V_17 = ( V_10 -> V_17 . V_18 + V_78 - 1 ) >> V_212 ;
F_58 ( V_17 , & V_3 -> V_213 ) ;
F_119 ( V_17 , & V_3 -> V_214 ) ;
F_55 ( & V_3 -> V_14 -> V_15 ) ;
F_56 ( & V_10 -> V_19 . V_20 , & V_3 -> V_215 ) ;
F_57 ( & V_3 -> V_14 -> V_15 ) ;
F_3 ( & V_216 ) ;
} else
F_47 ( V_3 , V_10 ) ;
}
int F_120 ( struct V_87 * V_19 , int V_88 )
{
struct V_9 * V_10 = F_44 ( V_19 , struct V_9 , V_19 ) ;
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_2 * V_3 = V_13 -> V_3 ;
int V_90 ;
if ( F_27 ( V_88 ) ) {
F_47 ( V_3 , V_10 ) ;
F_121 ( V_3 ) ;
return 0 ;
}
if ( F_122 ( ( V_10 -> V_11 & V_37 ) == 0 ) ) {
V_90 = F_123 ( V_13 , V_217 , V_10 ) ;
} else {
if ( F_22 ( & V_47 ) )
F_51 ( V_3 , L_25 ,
( unsigned long long ) V_10 -> V_17 . V_39 ) ;
V_90 = F_124 ( V_13 , V_218 , V_10 ) ;
}
F_121 ( V_3 ) ;
F_117 ( V_3 , V_10 ) ;
if ( F_27 ( V_90 ) )
F_51 ( V_3 , L_26 ) ;
return V_90 ;
}
int F_125 ( struct V_87 * V_19 , int V_88 )
{
struct V_9 * V_10 = F_44 ( V_19 , struct V_9 , V_19 ) ;
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_2 * V_3 = V_13 -> V_3 ;
int V_90 ;
if ( F_27 ( V_88 ) ) {
F_47 ( V_3 , V_10 ) ;
F_121 ( V_3 ) ;
return 0 ;
}
if ( F_126 ( V_3 , V_219 ) ) {
F_16 ( V_3 , V_10 -> V_17 . V_39 ) ;
F_5 ( V_3 ) ;
}
if ( V_3 -> V_103 . V_104 == V_220 ) {
V_90 = F_124 ( V_13 , V_221 , V_10 ) ;
} else if ( F_122 ( ( V_10 -> V_11 & V_37 ) == 0 ) ) {
if ( F_122 ( V_3 -> V_103 . V_202 >= V_201 ) ) {
F_48 ( V_3 ) ;
V_90 = F_123 ( V_13 , V_222 , V_10 ) ;
} else {
if ( F_22 ( & V_47 ) )
F_51 ( V_3 , L_27
L_28 ) ;
V_90 = 0 ;
}
} else {
if ( F_22 ( & V_47 ) )
F_51 ( V_3 , L_29 ,
( unsigned long long ) V_10 -> V_17 . V_39 ) ;
V_90 = F_124 ( V_13 , V_223 , V_10 ) ;
F_127 ( V_3 , V_10 -> V_17 . V_39 , V_10 -> V_17 . V_18 ) ;
}
F_121 ( V_3 ) ;
F_117 ( V_3 , V_10 ) ;
if ( F_27 ( V_90 ) )
F_51 ( V_3 , L_26 ) ;
return V_90 ;
}
int F_128 ( struct V_87 * V_19 , int V_88 )
{
struct V_9 * V_10 = F_44 ( V_19 , struct V_9 , V_19 ) ;
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_2 * V_3 = V_13 -> V_3 ;
struct V_224 * V_225 ;
int V_89 ;
void * V_69 = NULL ;
int V_90 , V_226 = 0 ;
if ( F_27 ( V_88 ) ) {
F_47 ( V_3 , V_10 ) ;
F_121 ( V_3 ) ;
return 0 ;
}
if ( F_53 ( V_3 ) ) {
F_16 ( V_3 , V_10 -> V_17 . V_39 ) ;
F_5 ( V_3 ) ;
}
V_225 = V_10 -> V_69 ;
if ( F_122 ( ( V_10 -> V_11 & V_37 ) == 0 ) ) {
if ( V_13 -> V_25 -> V_92 ) {
V_89 = F_45 ( V_13 -> V_25 -> V_92 ) ;
F_109 ( V_3 , V_89 == V_225 -> V_89 ) ;
V_69 = F_46 ( V_89 , V_93 ) ;
}
if ( V_69 ) {
F_34 ( V_13 -> V_25 -> V_92 , V_10 , V_69 ) ;
V_226 = ! memcmp ( V_69 , V_225 -> V_69 , V_89 ) ;
F_50 ( V_69 ) ;
}
if ( V_226 ) {
F_129 ( V_3 , V_10 -> V_17 . V_39 , V_10 -> V_17 . V_18 ) ;
V_3 -> V_197 += V_10 -> V_17 . V_18 >> V_138 ;
V_90 = F_124 ( V_13 , V_227 , V_10 ) ;
} else {
F_48 ( V_3 ) ;
V_10 -> V_29 = V_34 ;
V_10 -> V_11 &= ~ V_228 ;
F_50 ( V_225 ) ;
V_90 = F_123 ( V_13 , V_222 , V_10 ) ;
}
} else {
V_90 = F_124 ( V_13 , V_223 , V_10 ) ;
if ( F_22 ( & V_47 ) )
F_51 ( V_3 , L_30 ) ;
}
F_121 ( V_3 ) ;
F_117 ( V_3 , V_10 ) ;
if ( F_27 ( V_90 ) )
F_51 ( V_3 , L_31 ) ;
return V_90 ;
}
int F_130 ( struct V_87 * V_19 , int V_88 )
{
struct V_9 * V_10 = F_44 ( V_19 , struct V_9 , V_19 ) ;
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_2 * V_3 = V_13 -> V_3 ;
T_3 V_39 = V_10 -> V_17 . V_39 ;
unsigned int V_18 = V_10 -> V_17 . V_18 ;
int V_89 ;
void * V_69 ;
int V_90 = 0 ;
if ( F_27 ( V_88 ) )
goto V_91;
V_89 = F_45 ( V_13 -> V_25 -> V_229 ) ;
V_69 = F_46 ( V_89 , V_93 ) ;
if ( ! V_69 ) {
V_90 = 1 ;
goto V_91;
}
if ( F_122 ( ! ( V_10 -> V_11 & V_37 ) ) )
F_34 ( V_13 -> V_25 -> V_229 , V_10 , V_69 ) ;
else
memset ( V_69 , 0 , V_89 ) ;
F_47 ( V_3 , V_10 ) ;
V_10 = NULL ;
F_48 ( V_3 ) ;
V_90 = F_49 ( V_13 , V_39 , V_18 , V_69 , V_89 , V_230 ) ;
if ( V_90 )
F_91 ( V_3 ) ;
F_50 ( V_69 ) ;
V_91:
if ( V_10 )
F_47 ( V_3 , V_10 ) ;
F_121 ( V_3 ) ;
return V_90 ;
}
void F_131 ( struct V_2 * V_3 , T_3 V_39 , int V_18 )
{
if ( V_3 -> V_231 + V_3 -> V_232 == V_39 ) {
V_3 -> V_232 += V_18 >> 9 ;
} else {
V_3 -> V_231 = V_39 ;
V_3 -> V_232 = V_18 >> 9 ;
}
F_132 ( V_3 , V_39 , V_18 ) ;
}
int F_133 ( struct V_87 * V_19 , int V_88 )
{
struct V_9 * V_10 = F_44 ( V_19 , struct V_9 , V_19 ) ;
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_2 * V_3 = V_13 -> V_3 ;
struct V_224 * V_225 ;
void * V_69 ;
T_3 V_39 = V_10 -> V_17 . V_39 ;
unsigned int V_18 = V_10 -> V_17 . V_18 ;
int V_89 ;
int V_90 , V_226 = 0 ;
bool V_170 = false ;
if ( F_27 ( V_88 ) ) {
F_47 ( V_3 , V_10 ) ;
F_121 ( V_3 ) ;
return 0 ;
}
if ( F_53 ( V_3 ) ) {
F_16 ( V_3 , V_10 -> V_17 . V_39 ) ;
F_5 ( V_3 ) ;
}
V_225 = V_10 -> V_69 ;
if ( F_122 ( ( V_10 -> V_11 & V_37 ) == 0 ) ) {
V_89 = F_45 ( V_13 -> V_25 -> V_229 ) ;
V_69 = F_46 ( V_89 , V_93 ) ;
if ( V_69 ) {
F_34 ( V_13 -> V_25 -> V_229 , V_10 , V_69 ) ;
F_109 ( V_3 , V_89 == V_225 -> V_89 ) ;
V_226 = ! memcmp ( V_69 , V_225 -> V_69 , V_89 ) ;
F_50 ( V_69 ) ;
}
}
F_47 ( V_3 , V_10 ) ;
if ( ! V_226 )
F_131 ( V_3 , V_39 , V_18 ) ;
else
F_96 ( V_3 ) ;
V_90 = F_134 ( V_13 , V_233 , V_39 , V_18 ,
V_226 ? V_234 : V_235 ) ;
F_121 ( V_3 ) ;
-- V_3 -> V_192 ;
if ( ( V_3 -> V_192 & 0x200 ) == 0x200 )
F_135 ( V_3 , V_3 -> V_192 ) ;
V_170 = F_93 ( V_3 ) &&
( V_39 + ( V_18 >> 9 ) ) >= V_3 -> V_172 ;
if ( V_3 -> V_192 == 0 || V_170 ) {
F_96 ( V_3 ) ;
F_79 ( V_3 ) ;
}
return V_90 ;
}
static int F_136 ( struct V_141 * V_25 )
{
struct V_236 * V_237 ;
struct V_238 * V_153 ;
V_153 = & V_25 -> V_107 ;
V_237 = F_137 ( V_25 , V_153 ) ;
if ( ! V_237 )
return - V_48 ;
V_237 -> V_239 = V_25 -> V_240 . V_241 ;
V_237 -> V_242 = 0 ;
V_25 -> V_240 . V_243 = 0 ;
return F_138 ( V_25 , V_153 , V_244 , sizeof( * V_237 ) , NULL , 0 ) ;
}
int F_139 ( struct V_87 * V_19 , int V_88 )
{
struct V_2 * V_3 =
F_44 ( V_19 , struct V_2 , V_245 ) ;
struct V_238 * V_153 ;
if ( V_88 )
return 0 ;
V_153 = & F_65 ( V_3 ) -> V_25 -> V_107 ;
if ( ! F_140 ( F_65 ( V_3 ) , V_153 ) )
return - V_48 ;
return F_141 ( F_65 ( V_3 ) , V_153 , V_246 , 0 , NULL , 0 ) ;
}
static void F_142 ( struct V_141 * V_25 , unsigned int V_247 )
{
if ( ! V_25 -> V_240 . V_248 ) {
V_25 -> V_240 . V_248 = true ;
V_25 -> V_240 . V_241 = V_247 ;
V_25 -> V_240 . V_243 = 0 ;
}
}
static void F_143 ( struct V_141 * V_25 , unsigned int V_247 )
{
if ( ! V_25 -> V_240 . V_248 )
return;
if ( V_25 -> V_240 . V_241 != V_247 ) {
if ( V_25 -> V_240 . V_243 )
F_136 ( V_25 ) ;
V_25 -> V_240 . V_241 = V_247 ;
}
}
int F_144 ( struct V_87 * V_19 , int V_88 )
{
struct V_50 * V_51 = F_44 ( V_19 , struct V_50 , V_19 ) ;
struct V_2 * V_3 = V_51 -> V_3 ;
struct V_12 * const V_13 = F_65 ( V_3 ) ;
struct V_141 * const V_25 = V_13 -> V_25 ;
int V_90 ;
if ( F_27 ( V_88 ) ) {
F_145 ( V_51 , V_249 ) ;
return 0 ;
}
V_51 -> V_250 = V_169 ;
F_143 ( V_25 , V_51 -> V_247 ) ;
V_90 = F_146 ( V_13 , V_51 ) ;
F_145 ( V_51 , V_251 ) ;
return V_90 ;
}
int F_147 ( struct V_87 * V_19 , int V_88 )
{
struct V_50 * V_51 = F_44 ( V_19 , struct V_50 , V_19 ) ;
struct V_2 * V_3 = V_51 -> V_3 ;
struct V_12 * const V_13 = F_65 ( V_3 ) ;
struct V_141 * V_25 = V_13 -> V_25 ;
int V_90 ;
if ( F_27 ( V_88 ) ) {
F_145 ( V_51 , V_249 ) ;
return 0 ;
}
V_51 -> V_250 = V_169 ;
F_142 ( V_25 , V_51 -> V_247 ) ;
F_143 ( V_25 , V_51 -> V_247 ) ;
V_25 -> V_240 . V_243 ++ ;
V_90 = F_148 ( V_13 , V_51 ) ;
F_145 ( V_51 , V_90 ? V_252 : V_253 ) ;
return V_90 ;
}
int F_149 ( struct V_87 * V_19 , int V_88 )
{
struct V_50 * V_51 = F_44 ( V_19 , struct V_50 , V_19 ) ;
struct V_2 * V_3 = V_51 -> V_3 ;
struct V_12 * const V_13 = F_65 ( V_3 ) ;
struct V_141 * V_25 = V_13 -> V_25 ;
int V_90 ;
if ( F_27 ( V_88 ) ) {
F_145 ( V_51 , V_249 ) ;
return 0 ;
}
V_51 -> V_250 = V_169 ;
F_143 ( V_25 , V_51 -> V_247 ) ;
V_90 = F_90 ( V_13 , V_254 , V_51 -> V_17 . V_39 , V_51 -> V_17 . V_18 ,
( unsigned long ) V_51 ) ;
F_145 ( V_51 , V_90 ? V_252 : V_253 ) ;
return V_90 ;
}
int F_150 ( struct V_87 * V_19 , int V_88 )
{
struct V_50 * V_51 = F_44 ( V_19 , struct V_50 , V_19 ) ;
struct V_2 * V_3 = V_51 -> V_3 ;
if ( F_21 ( V_51 -> V_255 ) == V_43 && V_51 -> V_56 & V_256 )
F_151 ( V_3 , & V_51 -> V_17 ) ;
F_152 ( V_51 , V_51 -> V_255 ) ;
V_51 -> V_66 -> V_257 = V_3 -> V_8 -> V_258 ;
F_153 ( V_51 -> V_66 ) ;
return 0 ;
}
static int F_154 ( struct V_2 * V_3 )
{
struct V_2 * V_259 = V_3 ;
int V_260 ;
while ( 1 ) {
if ( ! V_259 -> V_8 || V_259 -> V_103 . V_200 == V_261 )
return 1 ;
F_75 () ;
V_260 = F_72 ( V_259 -> V_8 -> V_117 ) -> V_260 ;
F_77 () ;
if ( V_260 == - 1 )
return 1 ;
V_259 = F_155 ( V_260 ) ;
if ( ! V_259 )
return 1 ;
if ( ( V_259 -> V_103 . V_104 >= V_262 &&
V_259 -> V_103 . V_104 <= V_195 ) ||
V_259 -> V_103 . V_263 || V_259 -> V_103 . V_264 ||
V_259 -> V_103 . V_265 )
return 0 ;
}
}
static int F_156 ( struct V_2 * V_3 )
{
struct V_2 * V_259 ;
int V_17 , V_266 = 0 ;
F_75 () ;
F_157 (&drbd_devices, odev, i) {
if ( V_259 -> V_103 . V_104 == V_267 && V_259 -> V_103 . V_200 == V_261 )
continue;
if ( ! F_154 ( V_259 ) )
V_266 |= ( F_158 ( F_159 ( V_259 , V_263 , 1 ) , V_268 , NULL )
!= V_269 ) ;
}
F_77 () ;
return V_266 ;
}
static int F_160 ( struct V_2 * V_3 )
{
struct V_2 * V_259 ;
int V_17 , V_266 = 0 ;
F_75 () ;
F_157 (&drbd_devices, odev, i) {
if ( V_259 -> V_103 . V_104 == V_267 && V_259 -> V_103 . V_200 == V_261 )
continue;
if ( V_259 -> V_103 . V_263 ) {
if ( F_154 ( V_259 ) )
V_266 |= ( F_158 ( F_159 ( V_259 , V_263 , 0 ) ,
V_268 , NULL )
!= V_269 ) ;
}
}
F_77 () ;
return V_266 ;
}
void F_161 ( struct V_2 * V_3 )
{
F_162 ( & V_270 ) ;
F_160 ( V_3 ) ;
F_163 ( & V_270 ) ;
}
void F_164 ( struct V_2 * V_3 )
{
F_162 ( & V_270 ) ;
F_156 ( V_3 ) ;
F_163 ( & V_270 ) ;
}
enum V_271 F_165 ( struct V_2 * V_3 , int V_272 )
{
struct V_2 * V_259 ;
int V_260 ;
if ( V_272 == - 1 )
return V_273 ;
if ( V_272 < - 1 || V_272 > V_274 )
return V_275 ;
V_259 = F_155 ( V_272 ) ;
while ( 1 ) {
if ( V_259 == V_3 )
return V_276 ;
if ( ! V_259 || ! V_259 -> V_8 || V_259 -> V_103 . V_200 == V_261 )
return V_273 ;
F_75 () ;
V_260 = F_72 ( V_259 -> V_8 -> V_117 ) -> V_260 ;
F_77 () ;
if ( V_260 == - 1 )
return V_273 ;
V_259 = F_155 ( V_260 ) ;
}
}
void F_166 ( struct V_2 * V_3 )
{
int V_277 ;
do {
V_277 = F_156 ( V_3 ) ;
V_277 |= F_160 ( V_3 ) ;
} while ( V_277 );
}
void F_167 ( struct V_2 * V_3 )
{
struct V_108 * V_126 ;
F_168 ( & V_3 -> V_137 , 0 ) ;
F_168 ( & V_3 -> V_99 , 0 ) ;
V_3 -> V_128 = 0 ;
F_75 () ;
V_126 = F_72 ( V_3 -> V_127 ) ;
V_126 -> V_115 = 0 ;
F_66 ( V_126 , 0 ) ;
F_77 () ;
}
void F_169 ( unsigned long V_107 )
{
struct V_2 * V_3 = (struct V_2 * ) V_107 ;
F_170 ( V_3 , V_278 ) ;
}
static void F_171 ( struct V_2 * V_3 )
{
if ( F_172 ( & V_3 -> V_279 ) || F_172 ( & V_3 -> V_280 ) ) {
F_23 ( V_3 , L_32 ) ;
V_3 -> V_281 . V_282 = V_169 + V_131 / 10 ;
F_173 ( & V_3 -> V_281 ) ;
return;
}
F_174 ( V_3 , V_262 ) ;
F_99 ( V_283 , & V_3 -> V_11 ) ;
}
static bool F_175 ( struct V_141 * V_25 , struct V_2 * V_3 )
{
bool V_284 ;
F_75 () ;
V_284 = F_72 ( V_25 -> V_285 ) -> V_284 ;
F_77 () ;
return V_25 -> V_286 >= 89 &&
V_25 -> V_92 &&
( V_284 == 0
|| F_10 ( V_287 , & V_3 -> V_11 ) ) ;
}
void F_174 ( struct V_2 * V_3 , enum V_288 V_289 )
{
struct V_12 * V_13 = F_65 ( V_3 ) ;
struct V_141 * V_25 = V_13 ? V_13 -> V_25 : NULL ;
union V_183 V_185 ;
int V_290 ;
if ( V_3 -> V_103 . V_104 >= V_262 && V_3 -> V_103 . V_104 < V_220 ) {
F_51 ( V_3 , L_33 ) ;
return;
}
if ( ! F_10 ( V_291 , & V_3 -> V_11 ) ) {
if ( V_289 == V_106 ) {
V_290 = F_116 ( V_3 , L_34 ) ;
V_290 = ( V_290 >> 8 ) & 0xff ;
if ( V_290 > 0 ) {
F_106 ( V_3 , L_35
L_36 , V_290 ) ;
F_176 ( V_25 , F_177 ( V_104 , V_292 ) , V_268 ) ;
return;
}
} else {
V_290 = F_116 ( V_3 , L_37 ) ;
V_290 = ( V_290 >> 8 ) & 0xff ;
if ( V_290 > 0 ) {
if ( V_290 == 3 ) {
F_106 ( V_3 , L_38
L_39 , V_290 ) ;
} else {
F_106 ( V_3 , L_38
L_36 , V_290 ) ;
F_176 ( V_25 ,
F_177 ( V_104 , V_292 ) , V_268 ) ;
return;
}
}
}
}
if ( V_293 == V_25 -> V_294 . V_295 ) {
if ( ! F_178 ( V_3 -> V_296 ) ) {
F_24 ( V_291 , & V_3 -> V_11 ) ;
V_3 -> V_281 . V_282 = V_169 + V_131 / 5 ;
F_173 ( & V_3 -> V_281 ) ;
return;
}
} else {
F_81 ( V_3 -> V_296 ) ;
}
F_99 ( V_291 , & V_3 -> V_11 ) ;
F_55 ( & V_3 -> V_14 -> V_15 ) ;
F_179 ( & V_270 ) ;
if ( V_3 -> V_103 . V_104 < V_178
|| ! F_126 ( V_3 , V_297 ) ) {
F_180 ( & V_270 ) ;
F_57 ( & V_3 -> V_14 -> V_15 ) ;
F_82 ( V_3 -> V_296 ) ;
return;
}
V_185 = F_105 ( V_3 ) ;
V_185 . V_263 = ! F_154 ( V_3 ) ;
V_185 . V_104 = V_289 ;
if ( V_289 == V_106 )
V_185 . V_200 = V_201 ;
else
V_185 . V_202 = V_201 ;
V_290 = F_158 ( V_3 , V_185 , V_210 , NULL ) ;
V_185 = F_105 ( V_3 ) ;
if ( V_185 . V_104 < V_178 )
V_290 = V_298 ;
if ( V_290 == V_299 ) {
unsigned long V_300 = F_107 ( V_3 ) ;
unsigned long V_301 = V_169 ;
int V_17 ;
V_3 -> V_194 = 0 ;
V_3 -> V_190 = 0 ;
V_3 -> V_197 = 0 ;
V_3 -> V_302 = 0 ;
V_3 -> V_303 = 0 ;
V_3 -> V_149 = V_300 ;
V_3 -> V_189 = V_301 ;
for ( V_17 = 0 ; V_17 < V_304 ; V_17 ++ ) {
V_3 -> V_305 [ V_17 ] = V_300 ;
V_3 -> V_306 [ V_17 ] = V_301 ;
}
F_156 ( V_3 ) ;
F_181 ( & V_3 -> V_307 ) ;
F_182 ( V_3 -> V_308 ) ;
V_3 -> V_309 = 0 ;
V_3 -> V_310 = V_311 ;
F_183 ( & V_3 -> V_307 ) ;
}
F_180 ( & V_270 ) ;
F_57 ( & V_3 -> V_14 -> V_15 ) ;
if ( V_290 == V_299 ) {
F_3 ( & V_3 -> V_312 ) ;
V_3 -> V_313 = V_169 - V_131 ;
F_106 ( V_3 , L_40 ,
F_184 ( V_185 . V_104 ) ,
( unsigned long ) V_3 -> V_149 << ( V_138 - 10 ) ,
( unsigned long ) V_3 -> V_149 ) ;
if ( V_289 == V_106 ) {
V_3 -> V_162 = 0 ;
V_3 -> V_166 = F_175 ( V_25 , V_3 ) ;
} else {
V_3 -> V_166 = 0 ;
}
if ( V_289 == V_262 && V_25 -> V_286 < 96 )
F_185 ( V_13 ) ;
if ( V_25 -> V_286 < 95 && V_3 -> V_149 == 0 ) {
if ( V_289 == V_262 ) {
struct V_285 * V_314 ;
int V_315 ;
F_75 () ;
V_314 = F_72 ( V_25 -> V_285 ) ;
V_315 = V_314 -> V_316 * V_131 + V_314 -> V_317 * V_131 / 9 ;
F_77 () ;
F_103 ( V_315 ) ;
}
F_79 ( V_3 ) ;
}
F_167 ( V_3 ) ;
if ( V_185 . V_104 == V_106 )
F_92 ( & V_3 -> V_168 , V_169 ) ;
F_115 ( V_3 ) ;
}
F_5 ( V_3 ) ;
F_82 ( V_3 -> V_296 ) ;
}
static void F_186 ( struct V_2 * V_3 , bool V_318 )
{
struct V_319 V_320 = { . V_321 = V_322 , } ;
V_3 -> V_313 = V_169 ;
if ( ! F_53 ( V_3 ) )
return;
F_187 ( V_3 , 0 ) ;
if ( V_318 && F_188 ( V_3 -> V_103 . V_104 ) )
F_79 ( V_3 ) ;
F_189 ( V_3 , & V_320 ) ;
V_3 -> V_313 = V_169 ;
F_5 ( V_3 ) ;
}
static void F_190 ( struct V_2 * V_3 )
{
F_191 ( V_3 -> V_308 ) ;
V_3 -> V_308 = NULL ;
F_191 ( V_3 -> V_323 ) ;
V_3 -> V_323 = NULL ;
F_192 (local,
drbd_free_ldev(device->ldev);
device->ldev = NULL;) ;
F_99 ( V_324 , & V_3 -> V_11 ) ;
F_3 ( & V_3 -> V_7 ) ;
}
static void F_193 ( struct V_2 * V_3 )
{
F_109 ( V_3 , V_3 -> V_103 . V_200 == V_219 ) ;
if ( V_3 -> V_325 && V_3 -> V_8 ) {
if ( F_194 ( V_3 , V_326 ,
L_41 , V_327 ) ) {
if ( F_10 ( V_328 , & V_3 -> V_11 ) ) {
F_195 ( V_3 , V_329 ) ;
F_115 ( V_3 ) ;
}
}
}
F_196 ( V_3 , F_177 ( V_200 , V_261 ) ) ;
}
static int F_197 ( struct V_2 * V_3 )
{
F_23 ( V_3 , L_42 ) ;
F_115 ( V_3 ) ;
return 0 ;
}
void F_198 (
struct V_330 * V_331 ,
unsigned int * V_332 ,
void * V_98 ,
const char * V_333 , const unsigned int line )
{
unsigned int V_17 = * V_332 % V_334 ;
struct V_330 * V_335 = V_331 + V_17 ;
V_335 -> V_336 = V_169 ;
V_335 -> V_337 = V_98 ;
V_335 -> V_338 = V_333 ;
V_335 -> line = line ;
V_335 -> V_332 = * V_332 ;
V_17 = ( V_17 + 1 ) % V_334 ;
V_335 = V_331 + V_17 ;
memset ( V_335 , 0 , sizeof( * V_335 ) ) ;
++ ( * V_332 ) ;
}
static void F_199 ( struct V_2 * V_3 , const unsigned long V_339 )
{
if ( F_200 ( V_340 , V_339 ) )
F_197 ( V_3 ) ;
if ( F_200 ( V_341 , V_339 ) ||
F_200 ( V_342 , V_339 ) )
F_186 ( V_3 , F_200 ( V_341 , V_339 ) ) ;
if ( F_200 ( V_343 , V_339 ) )
F_193 ( V_3 ) ;
if ( F_200 ( V_344 , V_339 ) )
F_190 ( V_3 ) ;
if ( F_200 ( V_278 , V_339 ) )
F_171 ( V_3 ) ;
}
static unsigned long F_201 ( unsigned long * V_11 )
{
unsigned long V_345 , V_346 ;
do {
V_345 = * V_11 ;
V_346 = V_345 & ~ V_347 ;
} while ( F_202 ( V_11 , V_345 , V_346 ) != V_345 );
return V_345 & V_347 ;
}
static void F_203 ( struct V_141 * V_25 )
{
struct V_12 * V_13 ;
int V_348 ;
F_75 () ;
F_157 (&connection->peer_devices, peer_device, vnr) {
struct V_2 * V_3 = V_13 -> V_3 ;
unsigned long V_339 = F_201 ( & V_3 -> V_11 ) ;
if ( ! V_339 )
continue;
F_204 ( & V_3 -> V_349 ) ;
F_77 () ;
F_199 ( V_3 , V_339 ) ;
F_205 ( & V_3 -> V_349 , V_350 ) ;
F_75 () ;
}
F_77 () ;
}
static bool F_206 ( struct V_351 * V_352 , struct V_353 * V_354 )
{
F_55 ( & V_352 -> V_355 ) ;
F_207 ( & V_352 -> V_356 , V_354 ) ;
F_57 ( & V_352 -> V_355 ) ;
return ! F_9 ( V_354 ) ;
}
static bool F_208 ( struct V_351 * V_352 , struct V_353 * V_354 )
{
F_55 ( & V_352 -> V_355 ) ;
if ( ! F_9 ( & V_352 -> V_356 ) )
F_209 ( V_352 -> V_356 . V_357 , V_354 ) ;
F_57 ( & V_352 -> V_355 ) ;
return ! F_9 ( V_354 ) ;
}
static void F_210 ( struct V_141 * V_25 , struct V_353 * V_354 )
{
F_211 ( V_358 ) ;
struct V_285 * V_314 ;
int V_359 , V_360 ;
F_208 ( & V_25 -> V_26 , V_354 ) ;
if ( ! F_9 ( V_354 ) )
return;
F_75 () ;
V_314 = F_72 ( V_25 -> V_285 ) ;
V_359 = V_314 ? V_314 -> V_361 : 0 ;
F_77 () ;
if ( V_359 ) {
F_81 ( & V_25 -> V_107 . V_151 ) ;
if ( V_25 -> V_107 . V_152 )
F_212 ( V_25 -> V_107 . V_152 ) ;
F_82 ( & V_25 -> V_107 . V_151 ) ;
}
for (; ; ) {
int V_362 ;
F_213 ( & V_25 -> V_26 . V_363 , & V_358 , V_364 ) ;
F_55 ( & V_25 -> V_14 -> V_15 ) ;
F_181 ( & V_25 -> V_26 . V_355 ) ;
if ( ! F_9 ( & V_25 -> V_26 . V_356 ) )
F_207 ( & V_25 -> V_26 . V_356 , V_354 ) ;
F_183 ( & V_25 -> V_26 . V_355 ) ;
if ( ! F_9 ( V_354 ) || F_214 ( V_293 ) ) {
F_57 ( & V_25 -> V_14 -> V_15 ) ;
break;
}
V_362 =
F_172 ( & V_25 -> V_365 ) !=
V_25 -> V_240 . V_241 ;
F_57 ( & V_25 -> V_14 -> V_15 ) ;
if ( V_362 )
F_143 ( V_25 ,
V_25 -> V_240 . V_241 + 1 ) ;
if ( F_10 ( V_366 , & V_25 -> V_11 ) )
break;
if ( F_215 ( & V_25 -> V_294 ) != V_367 )
break;
F_216 () ;
}
F_217 ( & V_25 -> V_26 . V_363 , & V_358 ) ;
F_75 () ;
V_314 = F_72 ( V_25 -> V_285 ) ;
V_360 = V_314 ? V_314 -> V_361 : 0 ;
F_77 () ;
F_81 ( & V_25 -> V_107 . V_151 ) ;
if ( V_25 -> V_107 . V_152 ) {
if ( V_360 )
F_218 ( V_25 -> V_107 . V_152 ) ;
else if ( ! V_359 )
F_212 ( V_25 -> V_107 . V_152 ) ;
}
F_82 ( & V_25 -> V_107 . V_151 ) ;
}
int F_219 ( struct V_368 * V_369 )
{
struct V_141 * V_25 = V_369 -> V_25 ;
struct V_87 * V_19 = NULL ;
struct V_12 * V_13 ;
F_220 ( V_354 ) ;
int V_348 ;
while ( F_215 ( V_369 ) == V_367 ) {
F_221 ( V_369 ) ;
if ( F_9 ( & V_354 ) ) {
F_222 ( V_25 , F_210 ) ;
F_210 ( V_25 , & V_354 ) ;
}
if ( F_223 ( V_366 , & V_25 -> V_11 ) ) {
F_222 ( V_25 , F_203 ) ;
F_203 ( V_25 ) ;
}
if ( F_214 ( V_293 ) ) {
F_224 ( V_293 ) ;
if ( F_215 ( V_369 ) == V_367 ) {
F_23 ( V_25 , L_43 ) ;
continue;
}
break;
}
if ( F_215 ( V_369 ) != V_367 )
break;
while ( ! F_9 ( & V_354 ) ) {
V_19 = F_225 ( & V_354 , struct V_87 , V_20 ) ;
F_226 ( & V_19 -> V_20 ) ;
F_222 ( V_25 , V_19 -> V_98 ) ;
if ( V_19 -> V_98 ( V_19 , V_25 -> V_370 < V_371 ) == 0 )
continue;
if ( V_25 -> V_370 >= V_371 )
F_176 ( V_25 , F_177 ( V_104 , V_372 ) , V_268 ) ;
}
}
do {
if ( F_223 ( V_366 , & V_25 -> V_11 ) ) {
F_222 ( V_25 , F_203 ) ;
F_203 ( V_25 ) ;
}
while ( ! F_9 ( & V_354 ) ) {
V_19 = F_225 ( & V_354 , struct V_87 , V_20 ) ;
F_226 ( & V_19 -> V_20 ) ;
F_222 ( V_25 , V_19 -> V_98 ) ;
V_19 -> V_98 ( V_19 , 1 ) ;
}
F_206 ( & V_25 -> V_26 , & V_354 ) ;
} while ( ! F_9 ( & V_354 ) || F_10 ( V_366 , & V_25 -> V_11 ) );
F_75 () ;
F_157 (&connection->peer_devices, peer_device, vnr) {
struct V_2 * V_3 = V_13 -> V_3 ;
F_109 ( V_3 , V_3 -> V_103 . V_200 == V_261 && V_3 -> V_103 . V_104 == V_267 ) ;
F_204 ( & V_3 -> V_349 ) ;
F_77 () ;
F_227 ( V_3 ) ;
F_205 ( & V_3 -> V_349 , V_350 ) ;
F_75 () ;
}
F_77 () ;
return 0 ;
}
