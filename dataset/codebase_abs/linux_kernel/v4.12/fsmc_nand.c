static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_3 >= V_7 -> V_8 . V_9 )
return - V_10 ;
V_5 -> V_11 = ( V_3 * 16 ) + 2 ;
V_5 -> V_12 = 3 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_3 >= V_7 -> V_8 . V_9 )
return - V_10 ;
V_5 -> V_11 = ( V_3 * 16 ) + 8 ;
if ( V_3 < V_7 -> V_8 . V_9 - 1 )
V_5 -> V_12 = 8 ;
else
V_5 -> V_12 = V_2 -> V_13 - V_5 -> V_11 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_3 >= V_7 -> V_8 . V_9 )
return - V_10 ;
V_5 -> V_12 = V_7 -> V_8 . V_14 ;
if ( ! V_3 && V_2 -> V_15 <= 512 )
V_5 -> V_11 = 0 ;
else
V_5 -> V_11 = ( V_3 * 16 ) + 2 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_3 >= V_7 -> V_8 . V_9 )
return - V_10 ;
V_5 -> V_11 = ( V_3 * 16 ) + 15 ;
if ( V_3 < V_7 -> V_8 . V_9 - 1 )
V_5 -> V_12 = 3 ;
else
V_5 -> V_12 = V_2 -> V_13 - V_5 -> V_11 ;
return 0 ;
}
static inline struct V_16 * F_6 ( struct V_1 * V_2 )
{
return F_7 ( F_2 ( V_2 ) , struct V_16 , V_17 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_18 , unsigned int V_19 )
{
struct V_6 * V_20 = F_2 ( V_2 ) ;
struct V_16 * V_21 = F_6 ( V_2 ) ;
void T_1 * V_22 = V_21 -> V_23 ;
unsigned int V_24 = V_21 -> V_24 ;
if ( V_19 & V_25 ) {
T_2 V_26 ;
if ( V_19 & V_27 ) {
V_20 -> V_28 = V_21 -> V_29 ;
V_20 -> V_30 = V_21 -> V_29 ;
} else if ( V_19 & V_31 ) {
V_20 -> V_28 = V_21 -> V_32 ;
V_20 -> V_30 = V_21 -> V_32 ;
} else {
V_20 -> V_28 = V_21 -> V_33 ;
V_20 -> V_30 = V_21 -> V_33 ;
}
V_26 = F_9 ( F_10 ( V_22 , V_24 , V_34 ) ) ;
if ( V_19 & V_35 )
V_26 |= V_36 ;
else
V_26 &= ~ V_36 ;
F_11 ( V_26 , F_10 ( V_22 , V_24 , V_34 ) ) ;
}
F_12 () ;
if ( V_18 != V_37 )
F_13 ( V_18 , V_20 -> V_30 ) ;
}
static void F_14 ( void T_1 * V_22 , T_3 V_24 ,
T_3 V_38 , struct V_39 * V_40 )
{
T_3 V_41 = V_42 | V_36 | V_43 ;
T_3 V_44 , V_45 , V_46 , V_47 , V_48 , V_49 ;
struct V_39 * V_50 ;
struct V_39 V_51 = {
. V_44 = V_52 ,
. V_45 = V_53 ,
. V_46 = V_54 ,
. V_47 = V_55 ,
. V_48 = V_56 ,
. V_49 = V_57 ,
} ;
if ( V_40 )
V_50 = V_40 ;
else
V_50 = & V_51 ;
V_44 = ( V_50 -> V_44 & V_58 ) << V_59 ;
V_45 = ( V_50 -> V_45 & V_60 ) << V_61 ;
V_46 = ( V_50 -> V_46 & V_62 ) << V_63 ;
V_47 = ( V_50 -> V_47 & V_64 ) << V_65 ;
V_48 = ( V_50 -> V_48 & V_66 ) << V_67 ;
V_49 = ( V_50 -> V_49 & V_68 ) << V_69 ;
if ( V_38 )
F_11 ( V_41 | V_70 ,
F_10 ( V_22 , V_24 , V_34 ) ) ;
else
F_11 ( V_41 | V_71 ,
F_10 ( V_22 , V_24 , V_34 ) ) ;
F_11 ( F_9 ( F_10 ( V_22 , V_24 , V_34 ) ) | V_44 | V_45 ,
F_10 ( V_22 , V_24 , V_34 ) ) ;
F_11 ( V_46 | V_47 | V_48 | V_49 ,
F_10 ( V_22 , V_24 , V_72 ) ) ;
F_11 ( V_46 | V_47 | V_48 | V_49 ,
F_10 ( V_22 , V_24 , V_73 ) ) ;
}
static void F_15 ( struct V_1 * V_2 , int V_74 )
{
struct V_16 * V_21 = F_6 ( V_2 ) ;
void T_1 * V_22 = V_21 -> V_23 ;
T_3 V_24 = V_21 -> V_24 ;
F_11 ( F_9 ( F_10 ( V_22 , V_24 , V_34 ) ) & ~ V_75 ,
F_10 ( V_22 , V_24 , V_34 ) ) ;
F_11 ( F_9 ( F_10 ( V_22 , V_24 , V_34 ) ) & ~ V_76 ,
F_10 ( V_22 , V_24 , V_34 ) ) ;
F_11 ( F_9 ( F_10 ( V_22 , V_24 , V_34 ) ) | V_76 ,
F_10 ( V_22 , V_24 , V_34 ) ) ;
}
static int F_16 ( struct V_1 * V_2 , const T_4 * V_77 ,
T_4 * V_8 )
{
struct V_16 * V_21 = F_6 ( V_2 ) ;
void T_1 * V_22 = V_21 -> V_23 ;
T_3 V_24 = V_21 -> V_24 ;
T_3 V_78 ;
unsigned long V_79 = V_80 + V_81 ;
do {
if ( F_17 ( F_10 ( V_22 , V_24 , V_82 ) ) & V_83 )
break;
else
F_18 () ;
} while ( ! F_19 ( V_80 , V_79 ) );
if ( F_19 ( V_80 , V_79 ) ) {
F_20 ( V_21 -> V_84 , L_1 ) ;
return - V_85 ;
}
V_78 = F_17 ( F_10 ( V_22 , V_24 , V_86 ) ) ;
V_8 [ 0 ] = ( T_4 ) ( V_78 >> 0 ) ;
V_8 [ 1 ] = ( T_4 ) ( V_78 >> 8 ) ;
V_8 [ 2 ] = ( T_4 ) ( V_78 >> 16 ) ;
V_8 [ 3 ] = ( T_4 ) ( V_78 >> 24 ) ;
V_78 = F_17 ( F_10 ( V_22 , V_24 , V_87 ) ) ;
V_8 [ 4 ] = ( T_4 ) ( V_78 >> 0 ) ;
V_8 [ 5 ] = ( T_4 ) ( V_78 >> 8 ) ;
V_8 [ 6 ] = ( T_4 ) ( V_78 >> 16 ) ;
V_8 [ 7 ] = ( T_4 ) ( V_78 >> 24 ) ;
V_78 = F_17 ( F_10 ( V_22 , V_24 , V_88 ) ) ;
V_8 [ 8 ] = ( T_4 ) ( V_78 >> 0 ) ;
V_8 [ 9 ] = ( T_4 ) ( V_78 >> 8 ) ;
V_8 [ 10 ] = ( T_4 ) ( V_78 >> 16 ) ;
V_8 [ 11 ] = ( T_4 ) ( V_78 >> 24 ) ;
V_78 = F_17 ( F_10 ( V_22 , V_24 , V_82 ) ) ;
V_8 [ 12 ] = ( T_4 ) ( V_78 >> 16 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , const T_4 * V_77 ,
T_4 * V_8 )
{
struct V_16 * V_21 = F_6 ( V_2 ) ;
void T_1 * V_22 = V_21 -> V_23 ;
T_3 V_24 = V_21 -> V_24 ;
T_3 V_78 ;
V_78 = F_17 ( F_10 ( V_22 , V_24 , V_86 ) ) ;
V_8 [ 0 ] = ( T_4 ) ( V_78 >> 0 ) ;
V_8 [ 1 ] = ( T_4 ) ( V_78 >> 8 ) ;
V_8 [ 2 ] = ( T_4 ) ( V_78 >> 16 ) ;
return 0 ;
}
static int F_22 ( T_4 * V_89 , int V_90 , int V_91 )
{
int V_92 , V_93 = 0 ;
for ( V_92 = 0 ; V_92 < V_90 ; V_92 ++ ) {
V_93 += F_23 ( ~ V_89 [ V_92 ] ) ;
if ( V_93 > V_91 )
break;
}
return V_93 ;
}
static void F_24 ( void * V_94 )
{
struct V_16 * V_21 = V_94 ;
F_25 ( & V_21 -> V_95 ) ;
}
static int F_26 ( struct V_16 * V_21 , void * V_96 , int V_97 ,
enum V_98 V_99 )
{
struct V_100 * V_101 ;
struct V_102 * V_103 ;
struct V_104 * V_105 ;
T_5 V_106 , V_107 , V_108 ;
T_6 V_109 ;
unsigned long V_110 = V_111 | V_112 ;
int V_113 ;
unsigned long V_114 ;
if ( V_99 == V_115 )
V_101 = V_21 -> V_116 ;
else if ( V_99 == V_117 )
V_101 = V_21 -> V_118 ;
else
return - V_119 ;
V_103 = V_101 -> V_120 ;
V_108 = F_27 ( V_103 -> V_84 , V_96 , V_97 , V_99 ) ;
if ( V_99 == V_115 ) {
V_107 = V_108 ;
V_106 = V_21 -> V_121 ;
} else {
V_107 = V_21 -> V_121 ;
V_106 = V_108 ;
}
V_105 = V_103 -> V_122 ( V_101 , V_106 , V_107 ,
V_97 , V_110 ) ;
if ( ! V_105 ) {
F_20 ( V_21 -> V_84 , L_2 ) ;
V_113 = - V_123 ;
goto V_124;
}
V_105 -> V_125 = F_24 ;
V_105 -> V_126 = V_21 ;
V_109 = V_105 -> V_127 ( V_105 ) ;
V_113 = F_28 ( V_109 ) ;
if ( V_113 ) {
F_20 ( V_21 -> V_84 , L_3 , V_109 ) ;
goto V_124;
}
F_29 ( V_101 ) ;
V_114 =
F_30 ( & V_21 -> V_95 ,
F_31 ( 3000 ) ) ;
if ( V_114 == 0 ) {
F_32 ( V_101 ) ;
F_20 ( V_21 -> V_84 , L_4 ) ;
V_113 = - V_85 ;
goto V_124;
}
V_113 = 0 ;
V_124:
F_33 ( V_103 -> V_84 , V_108 , V_97 , V_99 ) ;
return V_113 ;
}
static void F_34 ( struct V_1 * V_2 , const T_4 * V_128 , int V_97 )
{
int V_129 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( F_35 ( ( T_3 ) V_128 , sizeof( T_3 ) ) &&
F_35 ( V_97 , sizeof( T_3 ) ) ) {
T_3 * V_130 = ( T_3 * ) V_128 ;
V_97 = V_97 >> 2 ;
for ( V_129 = 0 ; V_129 < V_97 ; V_129 ++ )
F_11 ( V_130 [ V_129 ] , V_7 -> V_30 ) ;
} else {
for ( V_129 = 0 ; V_129 < V_97 ; V_129 ++ )
F_13 ( V_128 [ V_129 ] , V_7 -> V_30 ) ;
}
}
static void F_36 ( struct V_1 * V_2 , T_4 * V_128 , int V_97 )
{
int V_129 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( F_35 ( ( T_3 ) V_128 , sizeof( T_3 ) ) &&
F_35 ( V_97 , sizeof( T_3 ) ) ) {
T_3 * V_130 = ( T_3 * ) V_128 ;
V_97 = V_97 >> 2 ;
for ( V_129 = 0 ; V_129 < V_97 ; V_129 ++ )
V_130 [ V_129 ] = F_17 ( V_7 -> V_28 ) ;
} else {
for ( V_129 = 0 ; V_129 < V_97 ; V_129 ++ )
V_128 [ V_129 ] = F_37 ( V_7 -> V_28 ) ;
}
}
static void F_38 ( struct V_1 * V_2 , T_4 * V_128 , int V_97 )
{
struct V_16 * V_21 = F_6 ( V_2 ) ;
F_26 ( V_21 , V_128 , V_97 , V_117 ) ;
}
static void F_39 ( struct V_1 * V_2 , const T_4 * V_128 ,
int V_97 )
{
struct V_16 * V_21 = F_6 ( V_2 ) ;
F_26 ( V_21 , ( void * ) V_128 , V_97 , V_115 ) ;
}
static int F_40 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_4 * V_128 , int V_131 , int V_132 )
{
int V_129 , V_133 , V_134 , V_135 , V_136 = V_7 -> V_8 . V_90 ;
int V_137 = V_7 -> V_8 . V_14 ;
int V_138 = V_7 -> V_8 . V_9 ;
T_4 * V_130 = V_128 ;
T_4 * V_139 = V_7 -> V_140 -> V_141 ;
T_4 * V_142 = V_7 -> V_140 -> V_143 ;
int V_144 , V_97 , V_145 = 0 ;
T_7 V_146 [ 7 ] ;
T_4 * V_147 = ( T_4 * ) & V_146 [ 0 ] ;
unsigned int V_148 = 0 ;
for ( V_129 = 0 , V_134 = 0 ; V_134 < V_138 ; V_134 ++ , V_129 += V_137 , V_130 += V_136 ) {
V_7 -> V_149 ( V_2 , V_150 , V_134 * V_136 , V_132 ) ;
V_7 -> V_8 . V_151 ( V_2 , V_152 ) ;
V_7 -> V_153 ( V_2 , V_130 , V_136 ) ;
for ( V_133 = 0 ; V_133 < V_137 ; ) {
struct V_4 V_5 ;
int V_113 ;
V_113 = F_41 ( V_2 , V_145 ++ , & V_5 ) ;
if ( V_113 )
return V_113 ;
V_144 = V_5 . V_11 ;
V_97 = V_5 . V_12 ;
if ( V_7 -> V_154 & V_155 )
V_97 = F_42 ( V_97 , 2 ) ;
V_7 -> V_149 ( V_2 , V_156 , V_144 , V_132 ) ;
V_7 -> V_153 ( V_2 , V_147 + V_133 , V_97 ) ;
V_133 += V_97 ;
}
memcpy ( & V_142 [ V_129 ] , V_147 , V_7 -> V_8 . V_14 ) ;
V_7 -> V_8 . V_157 ( V_2 , V_130 , & V_139 [ V_129 ] ) ;
V_135 = V_7 -> V_8 . V_158 ( V_2 , V_130 , & V_142 [ V_129 ] , & V_139 [ V_129 ] ) ;
if ( V_135 < 0 ) {
V_2 -> V_159 . V_160 ++ ;
} else {
V_2 -> V_159 . V_161 += V_135 ;
V_148 = F_43 (unsigned int, max_bitflips, stat) ;
}
}
return V_148 ;
}
static int F_44 ( struct V_1 * V_2 , T_4 * V_162 ,
T_4 * V_163 , T_4 * V_164 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_16 * V_21 = F_6 ( V_2 ) ;
void T_1 * V_22 = V_21 -> V_23 ;
unsigned int V_24 = V_21 -> V_24 ;
T_3 V_165 [ 8 ] ;
T_3 V_166 , V_129 ;
T_3 V_167 , V_168 , V_169 , V_170 ;
V_166 = ( F_17 ( F_10 ( V_22 , V_24 , V_82 ) ) >> 10 ) & 0xF ;
if ( F_45 ( V_166 == 0 ) )
return 0 ;
if ( F_46 ( V_166 > 8 ) ) {
int V_171 = F_22 ( V_163 , V_7 -> V_8 . V_14 , 8 ) ;
int V_172 = F_22 ( V_162 , V_7 -> V_8 . V_90 , 8 ) ;
if ( ( V_171 + V_172 ) <= 8 ) {
if ( V_172 )
memset ( V_162 , 0xff , V_7 -> V_8 . V_90 ) ;
return V_172 ;
}
return - V_173 ;
}
V_167 = F_17 ( F_10 ( V_22 , V_24 , V_86 ) ) ;
V_168 = F_17 ( F_10 ( V_22 , V_24 , V_87 ) ) ;
V_169 = F_17 ( F_10 ( V_22 , V_24 , V_88 ) ) ;
V_170 = F_17 ( F_10 ( V_22 , V_24 , V_82 ) ) ;
V_165 [ 0 ] = ( V_167 >> 0 ) & 0x1FFF ;
V_165 [ 1 ] = ( V_167 >> 13 ) & 0x1FFF ;
V_165 [ 2 ] = ( ( ( V_168 >> 0 ) & 0x7F ) << 6 ) | ( ( V_167 >> 26 ) & 0x3F ) ;
V_165 [ 3 ] = ( V_168 >> 7 ) & 0x1FFF ;
V_165 [ 4 ] = ( ( ( V_169 >> 0 ) & 0x1 ) << 12 ) | ( ( V_168 >> 20 ) & 0xFFF ) ;
V_165 [ 5 ] = ( V_169 >> 1 ) & 0x1FFF ;
V_165 [ 6 ] = ( V_169 >> 14 ) & 0x1FFF ;
V_165 [ 7 ] = ( ( ( V_170 >> 16 ) & 0xFF ) << 5 ) | ( ( V_169 >> 27 ) & 0x1F ) ;
V_129 = 0 ;
while ( V_166 -- ) {
F_47 ( 0 , ( unsigned long * ) & V_165 [ V_129 ] ) ;
F_47 ( 1 , ( unsigned long * ) & V_165 [ V_129 ] ) ;
if ( V_165 [ V_129 ] < V_7 -> V_8 . V_90 * 8 ) {
F_47 ( V_165 [ V_129 ] , ( unsigned long * ) V_162 ) ;
V_129 ++ ;
}
}
return V_129 ;
}
static bool F_48 ( struct V_100 * V_101 , void * V_174 )
{
V_101 -> V_175 = V_174 ;
return true ;
}
static int F_49 ( struct V_176 * V_177 ,
struct V_16 * V_21 ,
struct V_6 * V_17 )
{
struct V_178 * V_179 = V_177 -> V_84 . V_180 ;
T_2 V_181 ;
int V_113 ;
V_17 -> V_154 = 0 ;
if ( ! F_50 ( V_179 , L_5 , & V_181 ) ) {
if ( V_181 == 2 ) {
V_17 -> V_154 |= V_155 ;
} else if ( V_181 != 1 ) {
F_20 ( & V_177 -> V_84 , L_6 , V_181 ) ;
return - V_119 ;
}
}
if ( F_51 ( V_179 , L_7 , NULL ) )
V_17 -> V_154 |= V_182 ;
V_21 -> V_183 = F_52 ( & V_177 -> V_84 ,
sizeof( * V_21 -> V_183 ) , V_184 ) ;
if ( ! V_21 -> V_183 )
return - V_185 ;
V_113 = F_53 ( V_179 , L_8 , ( V_186 * ) V_21 -> V_183 ,
sizeof( * V_21 -> V_183 ) ) ;
if ( V_113 ) {
F_54 ( & V_177 -> V_84 , L_9 ) ;
V_21 -> V_183 = NULL ;
}
V_21 -> V_24 = 0 ;
if ( ! F_50 ( V_179 , L_10 , & V_181 ) ) {
if ( V_181 > 3 ) {
F_20 ( & V_177 -> V_84 , L_11 , V_181 ) ;
return - V_119 ;
}
V_21 -> V_24 = V_181 ;
}
return 0 ;
}
static int T_8 F_55 ( struct V_176 * V_177 )
{
struct V_16 * V_21 ;
struct V_1 * V_2 ;
struct V_6 * V_17 ;
struct V_187 * V_188 ;
T_9 V_189 ;
int V_113 = 0 ;
T_2 V_190 ;
int V_129 ;
V_21 = F_52 ( & V_177 -> V_84 , sizeof( * V_21 ) , V_184 ) ;
if ( ! V_21 )
return - V_185 ;
V_17 = & V_21 -> V_17 ;
V_113 = F_49 ( V_177 , V_21 , V_17 ) ;
if ( V_113 )
return V_113 ;
V_188 = F_56 ( V_177 , V_191 , L_12 ) ;
V_21 -> V_33 = F_57 ( & V_177 -> V_84 , V_188 ) ;
if ( F_58 ( V_21 -> V_33 ) )
return F_59 ( V_21 -> V_33 ) ;
V_21 -> V_121 = ( T_5 ) V_188 -> V_192 ;
V_188 = F_56 ( V_177 , V_191 , L_13 ) ;
V_21 -> V_32 = F_57 ( & V_177 -> V_84 , V_188 ) ;
if ( F_58 ( V_21 -> V_32 ) )
return F_59 ( V_21 -> V_32 ) ;
V_188 = F_56 ( V_177 , V_191 , L_14 ) ;
V_21 -> V_29 = F_57 ( & V_177 -> V_84 , V_188 ) ;
if ( F_58 ( V_21 -> V_29 ) )
return F_59 ( V_21 -> V_29 ) ;
V_188 = F_56 ( V_177 , V_191 , L_15 ) ;
V_21 -> V_23 = F_57 ( & V_177 -> V_84 , V_188 ) ;
if ( F_58 ( V_21 -> V_23 ) )
return F_59 ( V_21 -> V_23 ) ;
V_21 -> V_193 = F_60 ( & V_177 -> V_84 , NULL ) ;
if ( F_58 ( V_21 -> V_193 ) ) {
F_20 ( & V_177 -> V_84 , L_16 ) ;
return F_59 ( V_21 -> V_193 ) ;
}
V_113 = F_61 ( V_21 -> V_193 ) ;
if ( V_113 )
return V_113 ;
for ( V_190 = 0 , V_129 = 0 ; V_129 < 4 ; V_129 ++ )
V_190 |= ( F_9 ( V_21 -> V_23 + F_62 ( V_188 ) - 0x20 + 4 * V_129 ) & 255 ) << ( V_129 * 8 ) ;
V_21 -> V_190 = V_190 ;
F_54 ( & V_177 -> V_84 , L_17
L_18 ,
F_63 ( V_190 ) , F_64 ( V_190 ) ,
F_65 ( V_190 ) , F_66 ( V_190 ) ) ;
V_21 -> V_84 = & V_177 -> V_84 ;
if ( V_21 -> V_74 == V_194 )
F_67 ( & V_21 -> V_95 ) ;
V_2 = F_68 ( & V_21 -> V_17 ) ;
F_69 ( V_17 , V_21 ) ;
F_70 ( V_17 , V_177 -> V_84 . V_180 ) ;
V_2 -> V_84 . V_195 = & V_177 -> V_84 ;
V_17 -> V_28 = V_21 -> V_33 ;
V_17 -> V_30 = V_21 -> V_33 ;
V_17 -> V_196 = F_8 ;
V_17 -> V_197 = 30 ;
V_17 -> V_8 . V_74 = V_198 ;
V_17 -> V_8 . V_151 = F_15 ;
V_17 -> V_8 . V_90 = 512 ;
V_17 -> V_199 = 7 ;
switch ( V_21 -> V_74 ) {
case V_194 :
F_71 ( V_189 ) ;
F_72 ( V_200 , V_189 ) ;
V_21 -> V_118 = F_73 ( V_189 , F_48 , NULL ) ;
if ( ! V_21 -> V_118 ) {
F_20 ( & V_177 -> V_84 , L_19 ) ;
goto V_201;
}
V_21 -> V_116 = F_73 ( V_189 , F_48 , NULL ) ;
if ( ! V_21 -> V_116 ) {
F_20 ( & V_177 -> V_84 , L_20 ) ;
goto V_202;
}
V_17 -> V_153 = F_38 ;
V_17 -> V_203 = F_39 ;
break;
default:
case V_204 :
V_17 -> V_153 = F_36 ;
V_17 -> V_203 = F_34 ;
break;
}
F_14 ( V_21 -> V_23 , V_21 -> V_24 ,
V_17 -> V_154 & V_155 ,
V_21 -> V_183 ) ;
if ( F_65 ( V_21 -> V_190 ) >= 8 ) {
V_17 -> V_8 . V_205 = F_40 ;
V_17 -> V_8 . V_157 = F_16 ;
V_17 -> V_8 . V_158 = F_44 ;
V_17 -> V_8 . V_14 = 13 ;
V_17 -> V_8 . V_206 = 8 ;
}
V_113 = F_74 ( V_2 , 1 , NULL ) ;
if ( V_113 ) {
F_20 ( & V_177 -> V_84 , L_21 ) ;
goto V_207;
}
if ( F_65 ( V_21 -> V_190 ) >= 8 ) {
switch ( V_2 -> V_13 ) {
case 16 :
case 64 :
case 128 :
case 224 :
case 256 :
break;
default:
F_75 ( & V_177 -> V_84 , L_22 ,
V_2 -> V_13 ) ;
V_113 = - V_119 ;
goto V_208;
}
F_76 ( V_2 , & V_209 ) ;
} else {
switch ( V_17 -> V_8 . V_74 ) {
case V_198 :
F_54 ( & V_177 -> V_84 , L_23 ) ;
V_17 -> V_8 . V_157 = F_21 ;
V_17 -> V_8 . V_158 = V_210 ;
V_17 -> V_8 . V_14 = 3 ;
V_17 -> V_8 . V_206 = 1 ;
break;
case V_211 :
if ( V_17 -> V_8 . V_212 == V_213 ) {
F_54 ( & V_177 -> V_84 , L_24 ) ;
break;
}
default:
F_20 ( & V_177 -> V_84 , L_25 ) ;
goto V_208;
}
if ( V_17 -> V_8 . V_74 == V_198 ) {
switch ( V_2 -> V_13 ) {
case 16 :
case 64 :
case 128 :
F_76 ( V_2 ,
& V_214 ) ;
break;
default:
F_75 ( & V_177 -> V_84 ,
L_22 ,
V_2 -> V_13 ) ;
V_113 = - V_119 ;
goto V_208;
}
}
}
V_113 = F_77 ( V_2 ) ;
if ( V_113 )
goto V_208;
V_2 -> V_215 = L_26 ;
V_113 = F_78 ( V_2 , NULL , 0 ) ;
if ( V_113 )
goto V_208;
F_79 ( V_177 , V_21 ) ;
F_54 ( & V_177 -> V_84 , L_27 ) ;
return 0 ;
V_208:
V_207:
if ( V_21 -> V_74 == V_194 )
F_80 ( V_21 -> V_116 ) ;
V_202:
if ( V_21 -> V_74 == V_194 )
F_80 ( V_21 -> V_118 ) ;
V_201:
F_81 ( V_21 -> V_193 ) ;
return V_113 ;
}
static int F_82 ( struct V_176 * V_177 )
{
struct V_16 * V_21 = F_83 ( V_177 ) ;
if ( V_21 ) {
F_84 ( F_68 ( & V_21 -> V_17 ) ) ;
if ( V_21 -> V_74 == V_194 ) {
F_80 ( V_21 -> V_116 ) ;
F_80 ( V_21 -> V_118 ) ;
}
F_81 ( V_21 -> V_193 ) ;
}
return 0 ;
}
static int F_85 ( struct V_120 * V_84 )
{
struct V_16 * V_21 = F_86 ( V_84 ) ;
if ( V_21 )
F_81 ( V_21 -> V_193 ) ;
return 0 ;
}
static int F_87 ( struct V_120 * V_84 )
{
struct V_16 * V_21 = F_86 ( V_84 ) ;
if ( V_21 ) {
F_61 ( V_21 -> V_193 ) ;
F_14 ( V_21 -> V_23 , V_21 -> V_24 ,
V_21 -> V_17 . V_154 & V_155 ,
V_21 -> V_183 ) ;
}
return 0 ;
}
