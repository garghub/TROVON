static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 == V_5 ;
}
static inline void F_2 ( struct V_6 * V_7 , T_1 V_8 ,
void * V_9 )
{
T_1 V_10 = V_8 & V_7 -> V_11 . V_12 ;
memcpy ( V_9 , F_3 ( & V_7 -> V_11 , V_10 ) , sizeof( struct V_13 ) ) ;
}
static inline void F_4 ( struct V_14 * V_15 ,
struct V_6 * V_7 , T_1 V_8 )
{
F_2 ( V_7 , V_8 , & V_7 -> V_16 ) ;
V_7 -> V_17 = F_5 ( V_7 -> V_16 . V_18 ) ;
V_7 -> V_19 = F_6 ( V_7 -> V_16 . V_20 ) ;
V_15 -> V_21 . V_22 ++ ;
}
static inline void F_7 ( struct V_6 * V_7 , T_1 V_8 )
{
F_2 ( V_7 , V_8 , V_7 -> V_23 ) ;
V_7 -> V_24 = 0 ;
}
static inline void F_8 ( struct V_6 * V_7 , T_1 V_8 , int V_25 )
{
T_2 V_26 = ( V_8 >> V_7 -> V_11 . V_27 ) & 1 ;
T_1 V_28 = 1 << V_7 -> V_11 . V_27 ;
T_1 V_10 = V_8 & V_7 -> V_11 . V_12 ;
T_1 V_29 = F_9 ( T_1 , V_28 , V_10 + V_25 ) ;
for (; V_10 < V_29 ; V_10 ++ , V_25 -- ) {
struct V_13 * V_30 = F_3 ( & V_7 -> V_11 , V_10 ) ;
V_30 -> V_26 = V_26 ;
}
if ( F_10 ( V_10 == V_28 ) ) {
V_26 = ! V_26 ;
for ( V_10 = 0 ; V_10 < V_25 ; V_10 ++ ) {
struct V_13 * V_30 = F_3 ( & V_7 -> V_11 , V_10 ) ;
V_30 -> V_26 = V_26 ;
}
}
}
static inline void F_11 ( struct V_14 * V_15 ,
struct V_6 * V_7 , T_1 V_8 )
{
V_7 -> V_16 . V_18 = V_7 -> V_23 [ V_7 -> V_24 ] . V_18 ;
V_7 -> V_16 . V_31 = V_7 -> V_23 [ V_7 -> V_24 ] . V_32 ;
V_7 -> V_16 . V_26 &= 0xf0 ;
V_7 -> V_16 . V_26 |= 0x01 & ( V_8 >> V_7 -> V_11 . V_27 ) ;
V_7 -> V_16 . V_20 = F_12 ( V_7 -> V_19 ) ;
if ( V_15 -> V_33 == V_34 )
V_7 -> V_19 +=
F_13 ( & V_7 -> V_16 ) ;
else
V_7 -> V_19 =
( V_7 -> V_19 + 1 ) & V_15 -> V_11 . V_12 ;
}
static inline void F_14 ( struct V_14 * V_15 ,
struct V_6 * V_7 , T_1 V_8 )
{
F_11 ( V_15 , V_7 , V_8 ) ;
V_7 -> V_16 . V_35 = 0 ;
V_7 -> V_16 . V_36 = 0 ;
}
static inline T_1 F_15 ( struct V_14 * V_15 ,
struct V_6 * V_7 ,
int V_37 ,
int V_38 )
{
T_1 V_8 = V_7 -> V_11 . V_39 + V_37 ;
T_1 V_40 ;
T_1 V_41 ;
V_40 = F_9 ( T_1 , V_7 -> V_17 , V_38 ) ;
for ( V_41 = V_37 ; V_41 < V_40 ;
V_41 ++ , V_7 -> V_24 ++ , V_8 ++ ) {
if ( V_7 -> V_24 == V_42 )
F_7 ( V_7 , V_8 ) ;
F_14 ( V_15 , V_7 , V_8 ) ;
V_15 -> V_43 ( V_15 , & V_7 -> V_16 ) ;
}
F_8 ( V_7 , V_7 -> V_11 . V_39 , V_8 - V_7 -> V_11 . V_39 ) ;
V_7 -> V_11 . V_39 = V_8 ;
V_7 -> V_17 -= V_40 ;
V_15 -> V_21 . V_44 += V_40 ;
return V_40 ;
}
static inline T_1 F_16 ( struct V_14 * V_15 ,
struct V_6 * V_7 ,
int V_38 )
{
F_4 ( V_15 , V_7 , V_7 -> V_11 . V_39 ) ;
F_7 ( V_7 , V_7 -> V_11 . V_39 + 1 ) ;
F_11 ( V_15 , V_7 , V_7 -> V_11 . V_39 ) ;
V_15 -> V_43 ( V_15 , & V_7 -> V_16 ) ;
V_7 -> V_24 ++ ;
return F_15 ( V_15 , V_7 , 1 , V_38 ) - 1 ;
}
static inline bool F_17 ( struct V_45 * V_45 )
{
return F_18 ( V_45 ) || F_19 ( V_45 ) != F_20 () ;
}
static inline bool F_21 ( struct V_14 * V_15 ,
struct V_46 * V_47 )
{
struct V_48 * V_49 = & V_15 -> V_50 ;
T_1 V_51 = ( V_49 -> V_52 + 1 ) & ( V_53 - 1 ) ;
if ( V_51 == V_49 -> V_54 ) {
V_15 -> V_21 . V_55 ++ ;
return false ;
}
if ( F_10 ( F_17 ( V_47 -> V_45 ) ) ) {
V_15 -> V_21 . V_56 ++ ;
return false ;
}
V_49 -> V_50 [ V_49 -> V_52 ] = * V_47 ;
V_49 -> V_52 = V_51 ;
return true ;
}
static inline bool F_22 ( struct V_14 * V_15 ,
struct V_46 * V_47 )
{
struct V_48 * V_49 = & V_15 -> V_50 ;
if ( F_10 ( V_49 -> V_54 == V_49 -> V_52 ) ) {
V_15 -> V_21 . V_57 ++ ;
return false ;
}
if ( F_23 ( V_49 -> V_50 [ V_49 -> V_54 ] . V_45 ) != 1 ) {
V_15 -> V_21 . V_58 ++ ;
return false ;
}
* V_47 = V_49 -> V_50 [ V_49 -> V_54 ] ;
V_49 -> V_54 = ( V_49 -> V_54 + 1 ) & ( V_53 - 1 ) ;
V_15 -> V_21 . V_59 ++ ;
F_24 ( V_15 -> V_60 , V_47 -> V_61 ,
F_25 ( V_15 ) ,
V_62 ) ;
return true ;
}
static inline int F_26 ( struct V_14 * V_15 ,
struct V_46 * V_47 )
{
if ( F_22 ( V_15 , V_47 ) )
return 0 ;
V_47 -> V_45 = F_27 ( V_15 -> V_63 . V_64 ) ;
if ( F_10 ( ! V_47 -> V_45 ) )
return - V_65 ;
V_47 -> V_61 = F_28 ( V_15 -> V_60 , V_47 -> V_45 , 0 ,
F_25 ( V_15 ) , V_15 -> V_63 . V_66 ) ;
if ( F_10 ( F_29 ( V_15 -> V_60 , V_47 -> V_61 ) ) ) {
F_30 ( V_47 -> V_45 ) ;
V_47 -> V_45 = NULL ;
return - V_65 ;
}
return 0 ;
}
void F_31 ( struct V_14 * V_15 , struct V_46 * V_47 ,
bool V_67 )
{
if ( F_32 ( V_67 ) && F_21 ( V_15 , V_47 ) )
return;
F_33 ( V_15 -> V_60 , V_47 -> V_61 , F_25 ( V_15 ) ,
V_15 -> V_63 . V_66 ) ;
F_30 ( V_47 -> V_45 ) ;
}
static inline bool F_34 ( struct V_14 * V_15 ,
struct V_68 * V_69 )
{
return V_15 -> V_70 . V_71 && V_69 -> V_72 . V_45 &&
( V_69 -> V_73 + V_15 -> V_70 . V_74 <= F_25 ( V_15 ) ) &&
! F_17 ( V_69 -> V_72 . V_45 ) ;
}
static int F_35 ( struct V_14 * V_15 , struct V_75 * V_70 , T_3 V_76 )
{
struct V_68 * V_69 = & V_15 -> V_70 . V_77 [ V_76 ] ;
if ( ! V_69 -> V_72 . V_45 ) {
if ( F_10 ( F_26 ( V_15 , & V_69 -> V_72 ) ) )
return - V_65 ;
V_69 -> V_73 = 0 ;
}
V_70 -> V_9 . V_61 = F_36 ( V_69 -> V_72 . V_61 + V_69 -> V_73 + V_15 -> V_63 . V_78 ) ;
return 0 ;
}
static inline void F_37 ( struct V_14 * V_15 ,
struct V_68 * V_69 )
{
F_31 ( V_15 , & V_69 -> V_72 , true ) ;
V_69 -> V_72 . V_45 = NULL ;
}
static inline void F_38 ( struct V_14 * V_15 ,
struct V_68 * V_69 )
{
if ( F_34 ( V_15 , V_69 ) ) {
V_15 -> V_21 . V_71 ++ ;
return;
}
F_37 ( V_15 , V_69 ) ;
}
void F_39 ( struct V_14 * V_15 , T_3 V_76 )
{
struct V_68 * V_69 = & V_15 -> V_70 . V_77 [ V_76 ] ;
if ( V_69 -> V_72 . V_45 )
F_37 ( V_15 , V_69 ) ;
}
static inline int F_40 ( struct V_14 * V_15 )
{
return V_15 -> V_79 . V_80 >> V_81 ;
}
static inline void F_41 ( struct V_14 * V_15 ,
struct V_82 * V_83 ,
struct V_84 * V_69 ,
T_1 V_85 , T_1 V_86 ,
T_1 V_87 )
{
unsigned int V_88 = F_42 ( V_87 , F_43 ( V_15 -> V_79 . V_89 ) ) ;
F_44 ( V_15 -> V_60 ,
V_69 -> V_90 . V_47 [ V_85 ] . V_61 + V_86 ,
V_87 , V_62 ) ;
V_69 -> V_91 [ V_85 ] ++ ;
F_45 ( V_83 , F_46 ( V_83 ) -> V_92 ,
V_69 -> V_90 . V_47 [ V_85 ] . V_45 , V_86 ,
V_87 , V_88 ) ;
}
static inline void
F_47 ( struct V_93 * V_60 ,
struct V_82 * V_83 ,
struct V_84 * V_69 ,
T_1 V_85 , T_1 V_73 ,
T_1 V_94 )
{
T_3 V_95 = F_9 ( T_1 , V_94 , V_96 - V_73 ) ;
struct V_46 * V_47 = & V_69 -> V_90 . V_47 [ V_85 ] ;
unsigned int V_87 ;
V_87 = F_42 ( V_95 , sizeof( long ) ) ;
F_44 ( V_60 , V_47 -> V_61 + V_73 , V_87 ,
V_62 ) ;
F_48 ( V_83 , 0 ,
F_49 ( V_47 -> V_45 ) + V_73 ,
V_87 ) ;
if ( F_10 ( V_73 + V_94 > V_96 ) ) {
V_47 ++ ;
V_95 = V_87 ;
V_87 = F_42 ( V_94 - V_95 , sizeof( long ) ) ;
F_44 ( V_60 , V_47 -> V_61 , V_87 ,
V_62 ) ;
F_48 ( V_83 , V_95 ,
F_49 ( V_47 -> V_45 ) ,
V_87 ) ;
}
}
static inline void F_50 ( struct V_14 * V_15 , T_3 V_76 )
{
struct V_84 * V_69 = & V_15 -> V_79 . V_97 [ V_76 ] ;
struct V_98 * V_99 = & V_15 -> V_100 -> V_101 ;
struct V_102 * V_11 = & V_99 -> V_11 ;
struct V_103 * V_70 ;
T_2 V_104 = F_51 ( sizeof( * V_70 ) , V_105 ) ;
T_3 V_106 ;
while ( ( V_106 = ( V_99 -> V_107 & V_11 -> V_12 ) ) > V_99 -> V_108 ) {
V_99 -> V_109 . V_110 [ V_106 ] . V_111 = V_112 ;
F_52 ( V_11 , V_99 -> V_113 , & V_99 -> V_107 ) ;
}
V_70 = F_53 ( V_11 , V_106 ) ;
memcpy ( V_70 , & V_69 -> V_90 . V_70 , sizeof( * V_70 ) ) ;
V_70 -> V_114 . V_115 =
F_54 ( ( V_99 -> V_107 << V_116 ) |
V_117 ) ;
V_99 -> V_109 . V_110 [ V_106 ] . V_111 = V_117 ;
V_99 -> V_107 += V_104 ;
F_55 ( & V_99 -> V_11 , V_99 -> V_107 , V_99 -> V_118 , & V_70 -> V_114 ) ;
}
static int F_56 ( struct V_14 * V_15 ,
T_3 V_76 )
{
struct V_84 * V_69 = & V_15 -> V_79 . V_97 [ V_76 ] ;
int V_119 = F_40 ( V_15 ) ;
struct V_46 * V_47 = & V_69 -> V_90 . V_47 [ 0 ] ;
int V_120 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_121 ; V_41 ++ , V_47 ++ ) {
V_120 = F_26 ( V_15 , V_47 ) ;
if ( F_10 ( V_120 ) )
goto V_122;
V_69 -> V_90 . V_123 [ V_41 ] = F_36 ( V_47 -> V_61 | V_124 ) ;
F_57 ( V_47 -> V_45 , V_119 ) ;
}
memset ( V_69 -> V_91 , 0 , sizeof( * V_69 -> V_91 ) * V_121 ) ;
V_69 -> V_125 = 0 ;
return 0 ;
V_122:
while ( -- V_41 >= 0 ) {
V_47 -- ;
F_58 ( V_47 -> V_45 , V_119 ) ;
F_31 ( V_15 , V_47 , true ) ;
}
return V_120 ;
}
void F_59 ( struct V_14 * V_15 , struct V_84 * V_69 )
{
int V_119 = F_40 ( V_15 ) ;
struct V_46 * V_47 = & V_69 -> V_90 . V_47 [ 0 ] ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_121 ; V_41 ++ , V_47 ++ ) {
F_58 ( V_47 -> V_45 , V_119 - V_69 -> V_91 [ V_41 ] ) ;
F_31 ( V_15 , V_47 , true ) ;
}
}
static void F_60 ( struct V_14 * V_15 )
{
struct V_126 * V_11 = & V_15 -> V_11 ;
struct V_75 * V_70 = F_61 ( V_11 , V_11 -> V_54 ) ;
V_15 -> V_79 . V_127 = false ;
F_62 ( V_11 , F_6 ( V_70 -> V_128 . V_129 ) ) ;
F_63 () ;
F_64 ( V_11 ) ;
}
static int F_65 ( struct V_14 * V_15 , T_3 V_76 )
{
int V_120 ;
V_120 = F_56 ( V_15 , V_76 ) ;
if ( F_10 ( V_120 ) ) {
V_15 -> V_21 . V_130 ++ ;
return V_120 ;
}
V_15 -> V_79 . V_127 = true ;
F_50 ( V_15 , V_76 ) ;
return 0 ;
}
void F_66 ( struct V_14 * V_15 , T_3 V_76 )
{
struct V_84 * V_69 = & V_15 -> V_79 . V_97 [ V_76 ] ;
F_59 ( V_15 , V_69 ) ;
}
bool F_67 ( struct V_14 * V_15 )
{
struct V_126 * V_11 = & V_15 -> V_11 ;
int V_120 ;
if ( F_10 ( ! F_68 ( V_15 -> V_131 , V_132 ) ) )
return false ;
if ( F_69 ( V_11 ) )
return false ;
do {
struct V_75 * V_70 = F_61 ( V_11 , V_11 -> V_54 ) ;
V_120 = F_35 ( V_15 , V_70 , V_11 -> V_54 ) ;
if ( F_10 ( V_120 ) ) {
V_15 -> V_21 . V_130 ++ ;
break;
}
F_62 ( V_11 , F_6 ( V_70 -> V_128 . V_129 ) ) ;
} while ( ! F_69 ( V_11 ) );
F_63 () ;
F_64 ( V_11 ) ;
return ! ! V_120 ;
}
static inline void F_70 ( struct V_6 * V_7 ,
struct V_98 * V_99 ,
struct V_14 * V_15 ,
struct V_13 * V_30 )
{
struct V_102 * V_11 = & V_99 -> V_11 ;
T_3 V_10 = F_6 ( V_30 -> V_20 ) & V_11 -> V_12 ;
struct V_133 * V_134 = & V_99 -> V_109 . V_110 [ V_10 ] ;
F_71 ( & V_7 -> V_11 ) ;
if ( F_10 ( ( V_30 -> V_26 >> 4 ) != V_135 ) ) {
F_72 ( true , L_1 ,
V_30 -> V_26 ) ;
return;
}
if ( F_32 ( V_134 -> V_111 == V_117 ) ) {
F_60 ( V_15 ) ;
return;
}
if ( F_10 ( V_134 -> V_111 != V_112 ) )
F_72 ( true ,
L_2 ,
V_134 -> V_111 ) ;
}
static void F_73 ( struct V_6 * V_7 , struct V_14 * V_15 )
{
struct V_98 * V_99 = F_74 ( V_7 , struct V_98 , V_7 ) ;
struct V_13 * V_30 ;
if ( F_10 ( ! F_68 ( V_99 -> V_131 , V_136 ) ) )
return;
V_30 = F_75 ( & V_7 -> V_11 ) ;
if ( F_32 ( ! V_30 ) )
return;
F_70 ( V_7 , V_99 , V_15 , V_30 ) ;
F_76 ( & V_7 -> V_11 ) ;
}
bool F_77 ( struct V_14 * V_15 )
{
struct V_126 * V_11 = & V_15 -> V_11 ;
if ( F_10 ( ! F_68 ( V_15 -> V_131 , V_132 ) ) )
return false ;
F_73 ( & V_15 -> V_100 -> V_101 . V_7 , V_15 ) ;
if ( F_69 ( V_11 ) )
return false ;
if ( ! V_15 -> V_79 . V_127 )
F_65 ( V_15 , V_11 -> V_54 ) ;
return true ;
}
static void F_78 ( struct V_82 * V_83 , struct V_13 * V_30 ,
T_1 V_137 )
{
struct V_138 * V_139 = (struct V_138 * ) ( V_83 -> V_9 ) ;
struct V_140 * V_141 ;
int V_142 = 0 ;
T_4 V_143 ;
T_3 V_144 ;
void * V_145 ;
T_2 V_146 = F_79 ( V_30 ) ;
T_2 V_147 = ( V_146 == V_148 ) ||
( V_146 == V_149 ) ;
V_83 -> V_150 = V_151 ;
V_143 = F_80 ( V_83 , V_139 -> V_152 , & V_142 ) ;
V_144 = V_137 - V_142 ;
V_145 = V_83 -> V_9 + V_142 ;
if ( V_143 == F_81 ( V_153 ) ) {
struct V_154 * V_155 = V_145 ;
V_141 = V_145 + sizeof( struct V_154 ) ;
F_46 ( V_83 ) -> V_156 = V_157 ;
V_155 -> V_158 = V_30 -> V_159 ;
V_155 -> V_144 = F_12 ( V_144 ) ;
V_155 -> V_160 = 0 ;
V_155 -> V_160 = F_82 ( ( unsigned char * ) V_155 ,
V_155 -> V_161 ) ;
} else {
struct V_162 * V_163 = V_145 ;
V_141 = V_145 + sizeof( struct V_162 ) ;
F_46 ( V_83 ) -> V_156 = V_164 ;
V_163 -> V_165 = V_30 -> V_159 ;
V_163 -> V_166 = F_12 ( V_144 -
sizeof( struct V_162 ) ) ;
}
V_141 -> V_167 = F_83 ( V_30 ) ;
if ( V_147 ) {
V_141 -> V_168 = 1 ;
V_141 -> V_169 = V_30 -> V_170 ;
V_141 -> V_171 = V_30 -> V_172 ;
}
}
static inline void F_84 ( struct V_13 * V_30 ,
struct V_82 * V_83 )
{
T_2 V_173 = V_30 -> V_35 ;
int V_174 = ( V_173 & V_175 ) ? V_176 :
( V_173 & V_177 ) ? V_178 :
V_179 ;
F_85 ( V_83 , F_5 ( V_30 -> V_36 ) , V_174 ) ;
}
static inline bool F_86 ( struct V_82 * V_83 )
{
T_4 V_180 = ( (struct V_138 * ) V_83 -> V_9 ) -> V_152 ;
return ( V_180 == F_81 ( V_153 ) || V_180 == F_81 ( V_181 ) ) ;
}
static inline void F_87 ( struct V_182 * V_183 ,
struct V_13 * V_30 ,
struct V_14 * V_15 ,
struct V_82 * V_83 ,
bool V_184 )
{
if ( F_10 ( ! ( V_183 -> V_185 & V_186 ) ) )
goto V_187;
if ( V_184 ) {
V_83 -> V_188 = V_189 ;
V_15 -> V_21 . V_190 ++ ;
return;
}
if ( F_86 ( V_83 ) ) {
V_83 -> V_188 = V_191 ;
V_83 -> V_192 = F_88 ( ( V_193 V_194 ) V_30 -> V_31 ) ;
V_15 -> V_21 . V_195 ++ ;
return;
}
if ( F_32 ( ( V_30 -> V_196 & V_197 ) &&
( V_30 -> V_196 & V_198 ) ) ) {
V_83 -> V_188 = V_189 ;
if ( F_89 ( V_30 ) ) {
V_83 -> V_199 = 1 ;
V_83 -> V_200 = 1 ;
V_15 -> V_21 . V_201 ++ ;
return;
}
V_15 -> V_21 . V_190 ++ ;
return;
}
V_187:
V_83 -> V_188 = V_202 ;
V_15 -> V_21 . V_187 ++ ;
}
static inline void F_90 ( struct V_13 * V_30 ,
T_1 V_137 ,
struct V_14 * V_15 ,
struct V_82 * V_83 )
{
struct V_182 * V_183 = V_15 -> V_183 ;
struct V_1 * V_2 = V_15 -> V_2 ;
int V_203 ;
V_203 = F_5 ( V_30 -> V_204 ) >> 24 ;
if ( V_203 > 1 ) {
F_78 ( V_83 , V_30 , V_137 ) ;
F_46 ( V_83 ) -> V_205 = F_51 ( V_137 , V_203 ) ;
V_15 -> V_21 . V_206 += V_203 - 1 ;
V_15 -> V_21 . V_207 ++ ;
V_15 -> V_21 . V_208 += V_137 ;
}
if ( F_10 ( F_1 ( V_2 ) ) )
F_91 ( V_2 , F_92 ( V_30 ) , F_93 ( V_83 ) ) ;
F_94 ( V_83 , V_15 -> V_76 ) ;
if ( F_32 ( V_183 -> V_185 & V_209 ) )
F_84 ( V_30 , V_83 ) ;
if ( F_95 ( V_30 ) )
F_96 ( V_83 , F_81 ( V_210 ) ,
F_6 ( V_30 -> V_211 ) ) ;
V_83 -> V_212 = F_5 ( V_30 -> V_213 ) & V_214 ;
F_87 ( V_183 , V_30 , V_15 , V_83 , ! ! V_203 ) ;
V_83 -> V_215 = F_97 ( V_83 , V_183 ) ;
}
static inline void F_98 ( struct V_14 * V_15 ,
struct V_13 * V_30 ,
T_1 V_137 ,
struct V_82 * V_83 )
{
V_15 -> V_21 . V_206 ++ ;
V_15 -> V_21 . V_216 += V_137 ;
F_90 ( V_30 , V_137 , V_15 , V_83 ) ;
}
static inline void F_99 ( struct V_217 * V_99 )
{
struct V_102 * V_11 = & V_99 -> V_11 ;
struct V_218 * V_70 ;
T_3 V_106 = ( V_99 -> V_107 - 1 ) & V_11 -> V_12 ;
V_70 = F_53 ( V_11 , V_106 ) ;
F_55 ( V_11 , V_99 -> V_107 , V_99 -> V_118 , & V_70 -> V_114 ) ;
}
static inline bool F_100 ( struct V_14 * V_15 ,
struct V_46 * V_72 ,
const struct V_219 * V_220 )
{
struct V_217 * V_99 = & V_15 -> V_221 ;
struct V_102 * V_11 = & V_99 -> V_11 ;
T_3 V_106 = V_99 -> V_107 & V_11 -> V_12 ;
struct V_218 * V_70 = F_53 ( V_11 , V_106 ) ;
struct V_222 * V_223 = & V_70 -> V_114 ;
struct V_224 * V_225 = & V_70 -> V_139 ;
struct V_226 * V_227 ;
T_5 V_228 = V_220 -> V_9 - V_220 -> V_229 ;
T_6 V_230 = V_72 -> V_61 + V_228 ;
unsigned int V_231 = V_220 -> V_232 - V_220 -> V_9 ;
F_101 ( V_70 ) ;
if ( F_10 ( V_231 < V_233 ||
F_102 ( V_15 -> V_100 -> V_234 , V_15 -> V_183 -> V_235 ) < V_231 ) ) {
V_15 -> V_21 . V_236 ++ ;
return false ;
}
if ( F_10 ( ! F_103 ( V_11 , V_99 -> V_39 , V_99 -> V_107 , 1 ) ) ) {
if ( V_99 -> V_109 . V_237 ) {
F_99 ( V_99 ) ;
V_99 -> V_109 . V_237 = false ;
}
V_15 -> V_21 . V_238 ++ ;
return false ;
}
F_24 ( V_99 -> V_60 , V_230 , V_231 , V_239 ) ;
V_223 -> V_240 = 0 ;
V_227 = (struct V_226 * ) V_225 + 1 ;
if ( V_99 -> V_241 != V_242 ) {
memcpy ( V_225 -> V_243 . V_244 , V_220 -> V_9 , V_233 ) ;
V_225 -> V_243 . V_245 = F_12 ( V_233 ) ;
V_231 -= V_233 ;
V_230 += V_233 ;
V_227 ++ ;
}
V_227 -> V_61 = F_36 ( V_230 ) ;
V_227 -> V_246 = F_54 ( V_231 ) ;
V_223 -> V_115 = F_54 ( ( V_99 -> V_107 << 8 ) | V_247 ) ;
V_15 -> V_70 . V_248 = true ;
V_99 -> V_109 . V_72 [ V_106 ] = * V_72 ;
V_99 -> V_107 ++ ;
V_99 -> V_109 . V_237 = true ;
V_15 -> V_21 . V_249 ++ ;
return true ;
}
static inline int F_104 ( struct V_14 * V_15 ,
struct V_46 * V_72 ,
void * V_250 , T_3 * V_251 , T_1 * V_87 )
{
const struct V_252 * V_253 = F_105 ( V_15 -> V_254 ) ;
struct V_219 V_220 ;
T_1 V_255 ;
if ( ! V_253 )
return false ;
V_220 . V_9 = V_250 + * V_251 ;
V_220 . V_232 = V_220 . V_9 + * V_87 ;
V_220 . V_229 = V_250 ;
V_255 = F_106 ( V_253 , & V_220 ) ;
switch ( V_255 ) {
case V_256 :
* V_251 = V_220 . V_9 - V_220 . V_229 ;
* V_87 = V_220 . V_232 - V_220 . V_9 ;
return false ;
case V_257 :
if ( F_10 ( ! F_100 ( V_15 , V_72 , & V_220 ) ) )
F_107 ( V_15 -> V_183 , V_253 , V_255 ) ;
return true ;
default:
F_108 ( V_255 ) ;
case V_258 :
F_107 ( V_15 -> V_183 , V_253 , V_255 ) ;
case V_259 :
V_15 -> V_21 . V_236 ++ ;
return true ;
}
}
static inline
struct V_82 * F_109 ( struct V_14 * V_15 , struct V_13 * V_30 ,
struct V_68 * V_69 , T_1 V_137 )
{
struct V_46 * V_72 = & V_69 -> V_72 ;
T_3 V_251 = V_15 -> V_63 . V_78 ;
struct V_82 * V_83 ;
void * V_250 , * V_9 ;
bool V_260 ;
T_1 V_261 ;
V_250 = F_49 ( V_72 -> V_45 ) + V_69 -> V_73 ;
V_9 = V_250 + V_251 ;
V_261 = F_110 ( V_251 + V_137 ) ;
F_111 ( V_15 -> V_60 ,
V_72 -> V_61 + V_69 -> V_73 ,
0 , V_261 ,
V_62 ) ;
F_112 ( V_9 ) ;
V_69 -> V_73 += V_261 ;
if ( F_10 ( ( V_30 -> V_26 >> 4 ) != V_262 ) ) {
V_15 -> V_21 . V_263 ++ ;
return NULL ;
}
F_113 () ;
V_260 = F_104 ( V_15 , V_72 , V_250 , & V_251 , & V_137 ) ;
F_114 () ;
if ( V_260 )
return NULL ;
V_83 = F_115 ( V_250 , V_261 ) ;
if ( F_10 ( ! V_83 ) ) {
V_15 -> V_21 . V_130 ++ ;
return NULL ;
}
F_116 ( V_72 -> V_45 ) ;
F_117 ( V_83 , V_251 ) ;
F_118 ( V_83 , V_137 ) ;
return V_83 ;
}
void F_119 ( struct V_14 * V_15 , struct V_13 * V_30 )
{
struct V_68 * V_69 ;
struct V_75 * V_70 ;
T_4 V_264 ;
struct V_82 * V_83 ;
T_3 V_20 ;
T_1 V_137 ;
V_264 = V_30 -> V_20 ;
V_20 = F_6 ( V_264 ) ;
V_70 = F_61 ( & V_15 -> V_11 , V_20 ) ;
V_69 = & V_15 -> V_70 . V_77 [ V_20 ] ;
V_137 = F_5 ( V_30 -> V_18 ) ;
V_83 = F_109 ( V_15 , V_30 , V_69 , V_137 ) ;
if ( ! V_83 ) {
if ( V_15 -> V_70 . V_248 ) {
V_69 -> V_72 . V_45 = NULL ;
V_15 -> V_70 . V_248 = false ;
goto V_265;
}
F_37 ( V_15 , V_69 ) ;
goto V_265;
}
F_98 ( V_15 , V_30 , V_137 , V_83 ) ;
F_120 ( V_15 -> V_7 . V_266 , V_83 ) ;
F_38 ( V_15 , V_69 ) ;
V_265:
F_121 ( & V_15 -> V_11 , V_264 ,
& V_70 -> V_128 . V_129 ) ;
}
void F_122 ( struct V_14 * V_15 , struct V_13 * V_30 )
{
struct V_182 * V_183 = V_15 -> V_183 ;
struct V_267 * V_234 = F_123 ( V_183 ) ;
struct V_268 * V_269 = V_234 -> V_270 ;
struct V_271 * V_272 = V_269 -> V_272 ;
struct V_68 * V_69 ;
struct V_75 * V_70 ;
struct V_82 * V_83 ;
T_4 V_264 ;
T_3 V_20 ;
T_1 V_137 ;
V_264 = V_30 -> V_20 ;
V_20 = F_6 ( V_264 ) ;
V_70 = F_61 ( & V_15 -> V_11 , V_20 ) ;
V_69 = & V_15 -> V_70 . V_77 [ V_20 ] ;
V_137 = F_5 ( V_30 -> V_18 ) ;
V_83 = F_109 ( V_15 , V_30 , V_69 , V_137 ) ;
if ( ! V_83 ) {
if ( V_15 -> V_70 . V_248 ) {
V_69 -> V_72 . V_45 = NULL ;
V_15 -> V_70 . V_248 = false ;
goto V_265;
}
F_37 ( V_15 , V_69 ) ;
goto V_265;
}
F_98 ( V_15 , V_30 , V_137 , V_83 ) ;
if ( V_272 -> V_273 && F_124 ( V_83 ) )
F_125 ( V_83 ) ;
F_120 ( V_15 -> V_7 . V_266 , V_83 ) ;
F_38 ( V_15 , V_69 ) ;
V_265:
F_121 ( & V_15 -> V_11 , V_264 ,
& V_70 -> V_128 . V_129 ) ;
}
static inline void F_126 ( struct V_14 * V_15 ,
struct V_13 * V_30 ,
struct V_84 * V_69 ,
T_1 V_137 ,
struct V_82 * V_83 )
{
T_3 V_274 = F_127 ( V_30 ) ;
T_1 V_275 = V_274 << V_15 -> V_79 . V_89 ;
T_1 V_276 = V_275 & ( V_96 - 1 ) ;
T_1 V_85 = V_275 >> V_277 ;
T_1 V_278 = V_85 ;
T_3 V_94 = F_9 ( T_3 , V_279 , V_137 ) ;
T_1 V_86 = V_276 + V_94 ;
T_3 V_18 = V_137 - V_94 ;
if ( F_10 ( V_86 >= V_96 ) ) {
V_85 ++ ;
V_86 -= V_96 ;
}
while ( V_18 ) {
T_1 V_280 =
F_9 ( T_1 , V_96 - V_86 , V_18 ) ;
F_41 ( V_15 , V_83 , V_69 , V_85 , V_86 ,
V_280 ) ;
V_18 -= V_280 ;
V_86 = 0 ;
V_85 ++ ;
}
F_47 ( V_15 -> V_60 , V_83 , V_69 , V_278 ,
V_276 , V_94 ) ;
V_83 -> V_52 += V_94 ;
V_83 -> V_87 += V_94 ;
}
void F_128 ( struct V_14 * V_15 , struct V_13 * V_30 )
{
T_3 V_281 = F_13 ( V_30 ) ;
T_3 V_282 = F_6 ( V_30 -> V_282 ) ;
struct V_84 * V_69 = & V_15 -> V_79 . V_97 [ V_282 ] ;
struct V_75 * V_70 = F_61 ( & V_15 -> V_11 , V_282 ) ;
struct V_82 * V_83 ;
T_3 V_137 ;
V_69 -> V_125 += V_281 ;
if ( F_10 ( ( V_30 -> V_26 >> 4 ) != V_262 ) ) {
V_15 -> V_21 . V_263 ++ ;
goto V_283;
}
if ( F_10 ( F_129 ( V_30 ) ) ) {
V_15 -> V_21 . V_284 ++ ;
goto V_283;
}
V_83 = F_130 ( V_15 -> V_7 . V_266 ,
F_42 ( V_279 ,
sizeof( long ) ) ) ;
if ( F_10 ( ! V_83 ) ) {
V_15 -> V_21 . V_130 ++ ;
goto V_283;
}
F_101 ( V_83 -> V_9 ) ;
V_137 = F_131 ( V_30 ) ;
F_126 ( V_15 , V_30 , V_69 , V_137 , V_83 ) ;
F_98 ( V_15 , V_30 , V_137 , V_83 ) ;
F_120 ( V_15 -> V_7 . V_266 , V_83 ) ;
V_283:
if ( F_32 ( V_69 -> V_125 < V_15 -> V_79 . V_80 ) )
return;
F_59 ( V_15 , V_69 ) ;
F_121 ( & V_15 -> V_11 , V_30 -> V_282 , & V_70 -> V_128 . V_129 ) ;
}
int F_132 ( struct V_6 * V_7 , int V_285 )
{
struct V_14 * V_15 = F_74 ( V_7 , struct V_14 , V_7 ) ;
struct V_217 * V_221 ;
struct V_13 * V_30 ;
int V_286 = 0 ;
if ( F_10 ( ! F_68 ( V_15 -> V_131 , V_132 ) ) )
return 0 ;
if ( V_7 -> V_17 )
V_286 += F_15 ( V_15 , V_7 , 0 , V_285 ) ;
V_30 = F_75 ( & V_7 -> V_11 ) ;
if ( ! V_30 )
return 0 ;
V_221 = & V_15 -> V_221 ;
do {
if ( F_133 ( V_30 ) == V_287 ) {
V_286 +=
F_16 ( V_15 , V_7 ,
V_285 - V_286 ) ;
continue;
}
F_71 ( & V_7 -> V_11 ) ;
V_15 -> V_43 ( V_15 , V_30 ) ;
} while ( ( ++ V_286 < V_285 ) && ( V_30 = F_75 ( & V_7 -> V_11 ) ) );
if ( V_221 -> V_109 . V_237 ) {
F_99 ( V_221 ) ;
V_221 -> V_109 . V_237 = false ;
}
F_76 ( & V_7 -> V_11 ) ;
F_134 () ;
return V_286 ;
}
bool F_135 ( struct V_6 * V_7 )
{
struct V_217 * V_99 ;
struct V_13 * V_30 ;
struct V_14 * V_15 ;
T_3 V_288 ;
int V_41 ;
V_99 = F_74 ( V_7 , struct V_217 , V_7 ) ;
if ( F_10 ( ! F_68 ( V_99 -> V_131 , V_136 ) ) )
return false ;
V_30 = F_75 ( & V_7 -> V_11 ) ;
if ( ! V_30 )
return false ;
V_15 = F_74 ( V_99 , struct V_14 , V_221 ) ;
V_288 = V_99 -> V_39 ;
V_41 = 0 ;
do {
T_3 V_20 ;
bool V_289 ;
F_71 ( & V_7 -> V_11 ) ;
V_20 = F_6 ( V_30 -> V_20 ) ;
do {
struct V_46 * V_72 ;
T_3 V_10 ;
V_289 = ( V_288 == V_20 ) ;
V_10 = V_288 & V_99 -> V_11 . V_12 ;
V_72 = & V_99 -> V_109 . V_72 [ V_10 ] ;
V_288 ++ ;
F_31 ( V_15 , V_72 , true ) ;
} while ( ! V_289 );
} while ( ( ++ V_41 < V_290 ) && ( V_30 = F_75 ( & V_7 -> V_11 ) ) );
F_76 ( & V_7 -> V_11 ) ;
F_134 () ;
V_99 -> V_39 = V_288 ;
return ( V_41 == V_290 ) ;
}
void F_136 ( struct V_217 * V_99 )
{
struct V_14 * V_15 = F_74 ( V_99 , struct V_14 , V_221 ) ;
struct V_46 * V_72 ;
T_3 V_10 ;
while ( V_99 -> V_39 != V_99 -> V_107 ) {
V_10 = V_99 -> V_39 & V_99 -> V_11 . V_12 ;
V_72 = & V_99 -> V_109 . V_72 [ V_10 ] ;
V_99 -> V_39 ++ ;
F_31 ( V_15 , V_72 , false ) ;
}
}
static inline void F_137 ( struct V_14 * V_15 ,
struct V_13 * V_30 ,
T_1 V_137 ,
struct V_82 * V_83 )
{
struct V_182 * V_183 = V_15 -> V_183 ;
struct V_1 * V_2 = V_15 -> V_2 ;
char * V_291 ;
T_2 * V_292 ;
T_2 V_293 ;
V_293 = ( F_5 ( V_30 -> V_294 ) >> 28 ) & 3 ;
V_292 = V_83 -> V_9 + V_295 ;
if ( ( ! V_293 ) || V_292 [ 0 ] != 0xff )
V_83 -> V_296 = V_297 ;
else if ( memcmp ( V_292 , V_183 -> V_298 + 4 , V_299 ) == 0 )
V_83 -> V_296 = V_300 ;
else
V_83 -> V_296 = V_301 ;
F_138 ( V_83 , V_302 ) ;
V_83 -> V_215 = * ( ( T_4 * ) ( V_83 -> V_9 ) ) ;
V_83 -> V_188 = V_191 ;
V_83 -> V_192 = F_88 ( ( V_193 V_194 ) V_30 -> V_31 ) ;
if ( F_10 ( F_1 ( V_2 ) ) )
F_91 ( V_2 , F_92 ( V_30 ) , F_93 ( V_83 ) ) ;
F_94 ( V_83 , V_15 -> V_76 ) ;
if ( F_32 ( V_183 -> V_185 & V_209 ) )
F_84 ( V_30 , V_83 ) ;
V_291 = F_139 ( V_83 , V_303 ) ;
memset ( V_291 , 0 , V_303 ) ;
F_140 ( V_83 ) ;
F_138 ( V_83 , V_304 ) ;
V_83 -> V_305 = V_183 ;
V_15 -> V_21 . V_195 ++ ;
V_15 -> V_21 . V_206 ++ ;
V_15 -> V_21 . V_216 += V_137 ;
}
void F_141 ( struct V_14 * V_15 , struct V_13 * V_30 )
{
struct V_68 * V_69 ;
struct V_75 * V_70 ;
T_4 V_264 ;
struct V_82 * V_83 ;
T_3 V_20 ;
T_1 V_137 ;
V_264 = V_30 -> V_20 ;
V_20 = F_6 ( V_264 ) ;
V_70 = F_61 ( & V_15 -> V_11 , V_20 ) ;
V_69 = & V_15 -> V_70 . V_77 [ V_20 ] ;
V_137 = F_5 ( V_30 -> V_18 ) ;
V_83 = F_109 ( V_15 , V_30 , V_69 , V_137 ) ;
if ( ! V_83 )
goto V_306;
F_137 ( V_15 , V_30 , V_137 , V_83 ) ;
F_120 ( V_15 -> V_7 . V_266 , V_83 ) ;
V_306:
F_38 ( V_15 , V_69 ) ;
F_121 ( & V_15 -> V_11 , V_264 ,
& V_70 -> V_128 . V_129 ) ;
}
void F_142 ( struct V_14 * V_15 , struct V_13 * V_30 )
{
struct V_68 * V_69 ;
struct V_75 * V_70 ;
T_4 V_264 ;
struct V_82 * V_83 ;
T_3 V_20 ;
T_1 V_137 ;
V_264 = V_30 -> V_20 ;
V_20 = F_6 ( V_264 ) ;
V_70 = F_61 ( & V_15 -> V_11 , V_20 ) ;
V_69 = & V_15 -> V_70 . V_77 [ V_20 ] ;
V_137 = F_5 ( V_30 -> V_18 ) ;
V_83 = F_109 ( V_15 , V_30 , V_69 , V_137 ) ;
if ( F_10 ( ! V_83 ) ) {
F_37 ( V_15 , V_69 ) ;
goto V_265;
}
V_83 = F_143 ( V_15 -> V_183 , V_83 ) ;
if ( F_10 ( ! V_83 ) ) {
F_37 ( V_15 , V_69 ) ;
goto V_265;
}
F_98 ( V_15 , V_30 , V_137 , V_83 ) ;
F_120 ( V_15 -> V_7 . V_266 , V_83 ) ;
F_38 ( V_15 , V_69 ) ;
V_265:
F_121 ( & V_15 -> V_11 , V_264 ,
& V_70 -> V_128 . V_129 ) ;
}
