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
if ( F_10 ( F_18 ( V_47 -> V_45 ) ) )
return false ;
V_49 -> V_50 [ V_49 -> V_52 ] = * V_47 ;
V_49 -> V_52 = V_51 ;
return true ;
}
static inline bool F_22 ( struct V_14 * V_15 ,
struct V_46 * V_47 )
{
struct V_48 * V_49 = & V_15 -> V_50 ;
if ( F_10 ( V_49 -> V_54 == V_49 -> V_52 ) ) {
V_15 -> V_21 . V_56 ++ ;
return false ;
}
if ( F_23 ( V_49 -> V_50 [ V_49 -> V_54 ] . V_45 ) != 1 ) {
V_15 -> V_21 . V_57 ++ ;
return false ;
}
* V_47 = V_49 -> V_50 [ V_49 -> V_54 ] ;
V_49 -> V_54 = ( V_49 -> V_54 + 1 ) & ( V_53 - 1 ) ;
V_15 -> V_21 . V_58 ++ ;
F_24 ( V_15 -> V_59 , V_47 -> V_60 ,
F_25 ( V_15 ) ,
V_61 ) ;
return true ;
}
static inline int F_26 ( struct V_14 * V_15 ,
struct V_46 * V_47 )
{
struct V_45 * V_45 ;
if ( F_22 ( V_15 , V_47 ) )
return 0 ;
V_45 = F_27 ( V_15 -> V_62 . V_63 ) ;
if ( F_10 ( ! V_45 ) )
return - V_64 ;
V_47 -> V_60 = F_28 ( V_15 -> V_59 , V_45 , 0 ,
F_25 ( V_15 ) , V_15 -> V_62 . V_65 ) ;
if ( F_10 ( F_29 ( V_15 -> V_59 , V_47 -> V_60 ) ) ) {
F_30 ( V_45 ) ;
return - V_64 ;
}
V_47 -> V_45 = V_45 ;
return 0 ;
}
void F_31 ( struct V_14 * V_15 , struct V_46 * V_47 ,
bool V_66 )
{
if ( F_32 ( V_66 ) && F_21 ( V_15 , V_47 ) )
return;
F_33 ( V_15 -> V_59 , V_47 -> V_60 , F_25 ( V_15 ) ,
V_15 -> V_62 . V_65 ) ;
F_30 ( V_47 -> V_45 ) ;
}
static inline bool F_34 ( struct V_14 * V_15 ,
struct V_67 * V_68 )
{
return V_15 -> V_69 . V_70 && V_68 -> V_71 . V_45 &&
( V_68 -> V_72 + V_15 -> V_69 . V_73 <= F_25 ( V_15 ) ) &&
! F_17 ( V_68 -> V_71 . V_45 ) ;
}
int F_35 ( struct V_14 * V_15 , struct V_74 * V_69 , T_3 V_75 )
{
struct V_67 * V_68 = & V_15 -> V_69 . V_76 [ V_75 ] ;
if ( ! V_68 -> V_71 . V_45 ) {
if ( F_10 ( F_26 ( V_15 , & V_68 -> V_71 ) ) )
return - V_64 ;
V_68 -> V_72 = 0 ;
}
V_69 -> V_9 . V_60 = F_36 ( V_68 -> V_71 . V_60 + V_68 -> V_72 +
V_15 -> V_77 ) ;
return 0 ;
}
static inline void F_37 ( struct V_14 * V_15 ,
struct V_67 * V_68 )
{
F_31 ( V_15 , & V_68 -> V_71 , true ) ;
V_68 -> V_71 . V_45 = NULL ;
}
static inline void F_38 ( struct V_14 * V_15 ,
struct V_67 * V_68 )
{
if ( F_34 ( V_15 , V_68 ) ) {
V_15 -> V_21 . V_70 ++ ;
return;
}
F_37 ( V_15 , V_68 ) ;
}
void F_39 ( struct V_14 * V_15 , T_3 V_75 )
{
struct V_67 * V_68 = & V_15 -> V_69 . V_76 [ V_75 ] ;
if ( V_68 -> V_71 . V_45 )
F_37 ( V_15 , V_68 ) ;
}
static inline int F_40 ( struct V_14 * V_15 )
{
return V_15 -> V_78 >> V_79 ;
}
static inline void F_41 ( struct V_14 * V_15 ,
struct V_80 * V_81 ,
struct V_82 * V_68 ,
T_1 V_83 , T_1 V_84 ,
T_1 V_85 )
{
unsigned int V_86 = F_42 ( V_85 , V_15 -> V_87 ) ;
F_43 ( V_15 -> V_59 ,
V_68 -> V_88 . V_47 [ V_83 ] . V_60 + V_84 ,
V_85 , V_61 ) ;
V_68 -> V_89 [ V_83 ] ++ ;
F_44 ( V_81 , F_45 ( V_81 ) -> V_90 ,
V_68 -> V_88 . V_47 [ V_83 ] . V_45 , V_84 ,
V_85 , V_86 ) ;
}
static inline void
F_46 ( struct V_91 * V_59 ,
struct V_80 * V_81 ,
struct V_82 * V_68 ,
T_1 V_83 , T_1 V_72 ,
T_1 V_92 )
{
T_3 V_93 = F_9 ( T_1 , V_92 , V_94 - V_72 ) ;
struct V_46 * V_47 = & V_68 -> V_88 . V_47 [ V_83 ] ;
unsigned int V_85 ;
V_85 = F_42 ( V_93 , sizeof( long ) ) ;
F_43 ( V_59 , V_47 -> V_60 + V_72 , V_85 ,
V_61 ) ;
F_47 ( V_81 , 0 ,
F_48 ( V_47 -> V_45 ) + V_72 ,
V_85 ) ;
if ( F_10 ( V_72 + V_92 > V_94 ) ) {
V_47 ++ ;
V_93 = V_85 ;
V_85 = F_42 ( V_92 - V_93 , sizeof( long ) ) ;
F_43 ( V_59 , V_47 -> V_60 , V_85 ,
V_61 ) ;
F_47 ( V_81 , V_93 ,
F_48 ( V_47 -> V_45 ) ,
V_85 ) ;
}
}
static inline void F_49 ( struct V_14 * V_15 , T_3 V_75 )
{
struct V_82 * V_68 = & V_15 -> V_95 . V_96 [ V_75 ] ;
struct V_97 * V_98 = & V_15 -> V_99 -> V_100 ;
struct V_101 * V_11 = & V_98 -> V_11 ;
struct V_102 * V_69 ;
T_2 V_103 = F_50 ( sizeof( * V_69 ) , V_104 ) ;
T_3 V_105 ;
while ( ( V_105 = ( V_98 -> V_106 & V_11 -> V_12 ) ) > V_98 -> V_107 ) {
V_98 -> V_108 . V_109 [ V_105 ] . V_110 = V_111 ;
V_98 -> V_108 . V_109 [ V_105 ] . V_103 = 1 ;
F_51 ( V_11 , V_98 -> V_112 , & V_98 -> V_106 ) ;
}
V_69 = F_52 ( V_11 , V_105 ) ;
memcpy ( V_69 , & V_68 -> V_88 . V_69 , sizeof( * V_69 ) ) ;
V_69 -> V_113 . V_114 =
F_53 ( ( V_98 -> V_106 << V_115 ) |
V_116 ) ;
V_98 -> V_108 . V_109 [ V_105 ] . V_110 = V_116 ;
V_98 -> V_108 . V_109 [ V_105 ] . V_103 = V_103 ;
V_98 -> V_106 += V_103 ;
F_54 ( & V_98 -> V_11 , V_98 -> V_106 , V_98 -> V_117 , & V_69 -> V_113 ) ;
}
static int F_55 ( struct V_14 * V_15 ,
struct V_74 * V_69 ,
T_3 V_75 )
{
struct V_82 * V_68 = & V_15 -> V_95 . V_96 [ V_75 ] ;
T_4 V_118 = ( T_4 ) F_56 ( V_15 , V_75 ) << V_119 ;
int V_120 = F_40 ( V_15 ) ;
int V_121 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_122 ; V_41 ++ ) {
struct V_46 * V_47 = & V_68 -> V_88 . V_47 [ V_41 ] ;
V_121 = F_26 ( V_15 , V_47 ) ;
if ( F_10 ( V_121 ) )
goto V_123;
V_68 -> V_88 . V_124 [ V_41 ] = F_36 ( V_47 -> V_60 | V_125 ) ;
F_57 ( V_47 -> V_45 , V_120 ) ;
V_68 -> V_89 [ V_41 ] = 0 ;
}
V_68 -> V_126 = 0 ;
V_69 -> V_9 . V_60 = F_36 ( V_118 ) ;
return 0 ;
V_123:
while ( -- V_41 >= 0 ) {
struct V_46 * V_47 = & V_68 -> V_88 . V_47 [ V_41 ] ;
F_58 ( V_47 -> V_45 , V_120 ) ;
F_31 ( V_15 , V_47 , true ) ;
}
return V_121 ;
}
void F_59 ( struct V_14 * V_15 , struct V_82 * V_68 )
{
int V_120 = F_40 ( V_15 ) ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_122 ; V_41 ++ ) {
struct V_46 * V_47 = & V_68 -> V_88 . V_47 [ V_41 ] ;
F_58 ( V_47 -> V_45 , V_120 - V_68 -> V_89 [ V_41 ] ) ;
F_31 ( V_15 , V_47 , true ) ;
}
}
void F_60 ( struct V_14 * V_15 )
{
struct V_127 * V_11 = & V_15 -> V_11 ;
struct V_74 * V_69 = F_61 ( V_11 , V_11 -> V_54 ) ;
F_62 ( V_128 , & V_15 -> V_129 ) ;
if ( F_10 ( ! F_63 ( V_130 , & V_15 -> V_129 ) ) ) {
F_59 ( V_15 , & V_15 -> V_95 . V_96 [ V_11 -> V_54 ] ) ;
return;
}
F_64 ( V_11 , F_6 ( V_69 -> V_131 . V_132 ) ) ;
F_65 () ;
F_66 ( V_11 ) ;
}
int F_67 ( struct V_14 * V_15 , struct V_74 * V_69 , T_3 V_75 )
{
int V_121 ;
V_121 = F_55 ( V_15 , V_69 , V_75 ) ;
if ( F_10 ( V_121 ) )
return V_121 ;
F_68 ( V_128 , & V_15 -> V_129 ) ;
F_49 ( V_15 , V_75 ) ;
return - V_133 ;
}
void F_69 ( struct V_14 * V_15 , T_3 V_75 )
{
struct V_82 * V_68 = & V_15 -> V_95 . V_96 [ V_75 ] ;
F_59 ( V_15 , V_68 ) ;
}
bool F_70 ( struct V_14 * V_15 )
{
struct V_127 * V_11 = & V_15 -> V_11 ;
if ( F_10 ( F_71 ( V_15 ) ) )
return false ;
while ( ! F_72 ( V_11 ) ) {
struct V_74 * V_69 = F_61 ( V_11 , V_11 -> V_54 ) ;
int V_121 ;
V_121 = V_15 -> V_134 ( V_15 , V_69 , V_11 -> V_54 ) ;
if ( V_121 == - V_133 )
return true ;
if ( F_10 ( V_121 ) ) {
V_15 -> V_21 . V_135 ++ ;
break;
}
F_64 ( V_11 , F_6 ( V_69 -> V_131 . V_132 ) ) ;
}
F_65 () ;
F_66 ( V_11 ) ;
return ! F_72 ( V_11 ) ;
}
static void F_73 ( struct V_80 * V_81 , struct V_13 * V_30 ,
T_1 V_136 )
{
struct V_137 * V_138 = (struct V_137 * ) ( V_81 -> V_9 ) ;
struct V_139 * V_140 ;
struct V_141 * V_142 ;
struct V_143 * V_144 ;
int V_145 = 0 ;
T_5 V_146 ;
T_3 V_147 ;
T_2 V_148 = F_74 ( V_30 ) ;
int V_149 = ( ( V_150 == V_148 ) ||
( V_151 == V_148 ) ) ;
V_81 -> V_152 = V_153 ;
V_146 = F_75 ( V_81 , V_138 -> V_154 , & V_145 ) ;
V_140 = (struct V_139 * ) ( V_81 -> V_9 + V_145 ) ;
V_142 = (struct V_141 * ) ( V_81 -> V_9 + V_145 ) ;
V_147 = V_136 - V_145 ;
if ( V_146 == F_76 ( V_155 ) ) {
V_144 = (struct V_143 * ) ( V_81 -> V_9 + V_145 +
sizeof( struct V_139 ) ) ;
V_142 = NULL ;
F_45 ( V_81 ) -> V_156 = V_157 ;
} else {
V_144 = (struct V_143 * ) ( V_81 -> V_9 + V_145 +
sizeof( struct V_141 ) ) ;
V_140 = NULL ;
F_45 ( V_81 ) -> V_156 = V_158 ;
}
if ( F_77 ( V_30 ) )
V_144 -> V_159 = 1 ;
if ( V_149 ) {
V_144 -> V_160 = 1 ;
V_144 -> V_161 = V_30 -> V_162 ;
V_144 -> V_163 = V_30 -> V_164 ;
}
if ( V_140 ) {
V_140 -> V_165 = V_30 -> V_166 ;
V_140 -> V_147 = F_12 ( V_147 ) ;
V_140 -> V_167 = 0 ;
V_140 -> V_167 = F_78 ( ( unsigned char * ) V_140 ,
V_140 -> V_168 ) ;
} else {
V_142 -> V_169 = V_30 -> V_166 ;
V_142 -> V_170 = F_12 ( V_147 -
sizeof( struct V_141 ) ) ;
}
}
static inline void F_79 ( struct V_13 * V_30 ,
struct V_80 * V_81 )
{
T_2 V_171 = V_30 -> V_35 ;
int V_172 = ( V_171 & V_173 ) ? V_174 :
( V_171 & V_175 ) ? V_176 :
V_177 ;
F_80 ( V_81 , F_5 ( V_30 -> V_36 ) , V_172 ) ;
}
static inline bool F_81 ( struct V_80 * V_81 )
{
T_5 V_178 = ( (struct V_137 * ) V_81 -> V_9 ) -> V_154 ;
return ( V_178 == F_76 ( V_155 ) || V_178 == F_76 ( V_179 ) ) ;
}
static inline void F_82 ( struct V_180 * V_181 ,
struct V_13 * V_30 ,
struct V_14 * V_15 ,
struct V_80 * V_81 ,
bool V_182 )
{
if ( F_10 ( ! ( V_181 -> V_183 & V_184 ) ) )
goto V_185;
if ( V_182 ) {
V_81 -> V_186 = V_187 ;
return;
}
if ( F_81 ( V_81 ) ) {
V_81 -> V_186 = V_188 ;
V_81 -> V_189 = F_83 ( ( V_190 V_191 ) V_30 -> V_31 ) ;
V_15 -> V_21 . V_192 ++ ;
return;
}
if ( F_32 ( ( V_30 -> V_193 & V_194 ) &&
( V_30 -> V_193 & V_195 ) ) ) {
V_81 -> V_186 = V_187 ;
if ( F_84 ( V_30 ) ) {
V_81 -> V_196 = 1 ;
V_81 -> V_197 = 1 ;
V_15 -> V_21 . V_198 ++ ;
}
return;
}
V_185:
V_81 -> V_186 = V_199 ;
V_15 -> V_21 . V_185 ++ ;
}
static inline void F_85 ( struct V_13 * V_30 ,
T_1 V_136 ,
struct V_14 * V_15 ,
struct V_80 * V_81 )
{
struct V_180 * V_181 = V_15 -> V_181 ;
struct V_1 * V_2 = V_15 -> V_2 ;
int V_200 ;
V_200 = F_5 ( V_30 -> V_201 ) >> 24 ;
if ( V_200 > 1 ) {
F_73 ( V_81 , V_30 , V_136 ) ;
F_45 ( V_81 ) -> V_202 = F_50 ( V_136 , V_200 ) ;
V_15 -> V_21 . V_203 += V_200 - 1 ;
V_15 -> V_21 . V_204 ++ ;
V_15 -> V_21 . V_205 += V_136 ;
}
if ( F_10 ( F_1 ( V_2 ) ) )
F_86 ( V_2 , F_87 ( V_30 ) , F_88 ( V_81 ) ) ;
F_89 ( V_81 , V_15 -> V_75 ) ;
if ( F_32 ( V_181 -> V_183 & V_206 ) )
F_79 ( V_30 , V_81 ) ;
if ( F_90 ( V_30 ) )
F_91 ( V_81 , F_76 ( V_207 ) ,
F_6 ( V_30 -> V_208 ) ) ;
V_81 -> V_209 = F_5 ( V_30 -> V_210 ) & V_211 ;
F_82 ( V_181 , V_30 , V_15 , V_81 , ! ! V_200 ) ;
V_81 -> V_212 = F_92 ( V_81 , V_181 ) ;
}
static inline void F_93 ( struct V_14 * V_15 ,
struct V_13 * V_30 ,
T_1 V_136 ,
struct V_80 * V_81 )
{
V_15 -> V_21 . V_203 ++ ;
V_15 -> V_21 . V_213 += V_136 ;
F_85 ( V_30 , V_136 , V_15 , V_81 ) ;
}
static inline void F_94 ( struct V_214 * V_98 )
{
struct V_101 * V_11 = & V_98 -> V_11 ;
struct V_215 * V_69 ;
T_3 V_105 = ( V_98 -> V_106 - 1 ) & V_11 -> V_12 ;
V_69 = F_52 ( V_11 , V_105 ) ;
F_54 ( V_11 , V_98 -> V_106 , V_98 -> V_117 , & V_69 -> V_113 ) ;
}
static inline bool F_95 ( struct V_14 * V_15 ,
struct V_46 * V_71 ,
const struct V_216 * V_217 )
{
struct V_214 * V_98 = & V_15 -> V_218 ;
struct V_101 * V_11 = & V_98 -> V_11 ;
T_3 V_105 = V_98 -> V_106 & V_11 -> V_12 ;
struct V_215 * V_69 = F_52 ( V_11 , V_105 ) ;
struct V_219 * V_220 = & V_69 -> V_113 ;
struct V_221 * V_222 = & V_69 -> V_138 ;
struct V_223 * V_224 ;
T_6 V_225 = V_217 -> V_9 - V_217 -> V_226 ;
T_7 V_227 = V_71 -> V_60 + V_225 ;
unsigned int V_228 = V_217 -> V_229 - V_217 -> V_9 ;
F_96 ( V_69 ) ;
if ( F_10 ( V_228 < V_230 ||
F_97 ( V_15 -> V_99 -> V_231 , V_15 -> V_181 -> V_232 ) < V_228 ) ) {
V_15 -> V_21 . V_233 ++ ;
return false ;
}
if ( F_10 ( ! F_98 ( V_11 , V_98 -> V_39 , V_98 -> V_106 , 1 ) ) ) {
if ( V_98 -> V_108 . V_234 ) {
F_94 ( V_98 ) ;
V_98 -> V_108 . V_234 = false ;
}
V_15 -> V_21 . V_235 ++ ;
return false ;
}
F_24 ( V_98 -> V_59 , V_227 , V_228 , V_236 ) ;
V_220 -> V_237 = 0 ;
V_224 = (struct V_223 * ) V_222 + 1 ;
if ( V_98 -> V_238 != V_239 ) {
memcpy ( V_222 -> V_240 . V_241 , V_217 -> V_9 , V_230 ) ;
V_222 -> V_240 . V_242 = F_12 ( V_230 ) ;
V_228 -= V_230 ;
V_227 += V_230 ;
V_224 ++ ;
}
V_224 -> V_60 = F_36 ( V_227 ) ;
V_224 -> V_243 = F_53 ( V_228 ) ;
V_220 -> V_114 = F_53 ( ( V_98 -> V_106 << 8 ) | V_244 ) ;
V_15 -> V_69 . V_245 = true ;
V_98 -> V_108 . V_71 [ V_105 ] = * V_71 ;
V_98 -> V_106 ++ ;
V_98 -> V_108 . V_234 = true ;
V_15 -> V_21 . V_246 ++ ;
return true ;
}
static inline int F_99 ( struct V_14 * V_15 ,
struct V_46 * V_71 ,
void * V_247 , T_3 * V_77 , T_1 * V_85 )
{
const struct V_248 * V_249 = F_100 ( V_15 -> V_250 ) ;
struct V_216 V_217 ;
T_1 V_251 ;
if ( ! V_249 )
return false ;
V_217 . V_9 = V_247 + * V_77 ;
V_217 . V_229 = V_217 . V_9 + * V_85 ;
V_217 . V_226 = V_247 ;
V_251 = F_101 ( V_249 , & V_217 ) ;
switch ( V_251 ) {
case V_252 :
* V_77 = V_217 . V_9 - V_217 . V_226 ;
* V_85 = V_217 . V_229 - V_217 . V_9 ;
return false ;
case V_253 :
if ( F_10 ( ! F_95 ( V_15 , V_71 , & V_217 ) ) )
F_102 ( V_15 -> V_181 , V_249 , V_251 ) ;
return true ;
default:
F_103 ( V_251 ) ;
case V_254 :
F_102 ( V_15 -> V_181 , V_249 , V_251 ) ;
case V_255 :
V_15 -> V_21 . V_233 ++ ;
return true ;
}
}
static inline
struct V_80 * F_104 ( struct V_14 * V_15 , struct V_13 * V_30 ,
struct V_67 * V_68 , T_1 V_136 )
{
struct V_46 * V_71 = & V_68 -> V_71 ;
struct V_80 * V_81 ;
void * V_247 , * V_9 ;
T_3 V_77 = V_15 -> V_77 ;
bool V_256 ;
T_1 V_257 ;
V_247 = F_48 ( V_71 -> V_45 ) + V_68 -> V_72 ;
V_9 = V_247 + V_77 ;
V_257 = F_105 ( V_77 + V_136 ) ;
F_106 ( V_15 -> V_59 ,
V_71 -> V_60 + V_68 -> V_72 ,
0 , V_257 ,
V_61 ) ;
F_107 ( V_9 ) ;
V_68 -> V_72 += V_257 ;
if ( F_10 ( ( V_30 -> V_26 >> 4 ) != V_258 ) ) {
V_15 -> V_21 . V_259 ++ ;
return NULL ;
}
F_108 () ;
V_256 = F_99 ( V_15 , V_71 , V_247 , & V_77 , & V_136 ) ;
F_109 () ;
if ( V_256 )
return NULL ;
V_81 = F_110 ( V_247 , V_257 ) ;
if ( F_10 ( ! V_81 ) ) {
V_15 -> V_21 . V_135 ++ ;
return NULL ;
}
F_111 ( V_71 -> V_45 ) ;
F_112 ( V_81 , V_77 ) ;
F_113 ( V_81 , V_136 ) ;
return V_81 ;
}
void F_114 ( struct V_14 * V_15 , struct V_13 * V_30 )
{
struct V_67 * V_68 ;
struct V_74 * V_69 ;
T_5 V_260 ;
struct V_80 * V_81 ;
T_3 V_20 ;
T_1 V_136 ;
V_260 = V_30 -> V_20 ;
V_20 = F_6 ( V_260 ) ;
V_69 = F_61 ( & V_15 -> V_11 , V_20 ) ;
V_68 = & V_15 -> V_69 . V_76 [ V_20 ] ;
V_136 = F_5 ( V_30 -> V_18 ) ;
V_81 = F_104 ( V_15 , V_30 , V_68 , V_136 ) ;
if ( ! V_81 ) {
if ( V_15 -> V_69 . V_245 ) {
V_68 -> V_71 . V_45 = NULL ;
V_15 -> V_69 . V_245 = false ;
goto V_261;
}
F_37 ( V_15 , V_68 ) ;
goto V_261;
}
F_93 ( V_15 , V_30 , V_136 , V_81 ) ;
F_115 ( V_15 -> V_7 . V_262 , V_81 ) ;
F_38 ( V_15 , V_68 ) ;
V_261:
F_116 ( & V_15 -> V_11 , V_260 ,
& V_69 -> V_131 . V_132 ) ;
}
void F_117 ( struct V_14 * V_15 , struct V_13 * V_30 )
{
struct V_180 * V_181 = V_15 -> V_181 ;
struct V_263 * V_231 = F_118 ( V_181 ) ;
struct V_264 * V_265 = V_231 -> V_266 ;
struct V_267 * V_268 = V_265 -> V_268 ;
struct V_67 * V_68 ;
struct V_74 * V_69 ;
struct V_80 * V_81 ;
T_5 V_260 ;
T_3 V_20 ;
T_1 V_136 ;
V_260 = V_30 -> V_20 ;
V_20 = F_6 ( V_260 ) ;
V_69 = F_61 ( & V_15 -> V_11 , V_20 ) ;
V_68 = & V_15 -> V_69 . V_76 [ V_20 ] ;
V_136 = F_5 ( V_30 -> V_18 ) ;
V_81 = F_104 ( V_15 , V_30 , V_68 , V_136 ) ;
if ( ! V_81 ) {
if ( V_15 -> V_69 . V_245 ) {
V_68 -> V_71 . V_45 = NULL ;
V_15 -> V_69 . V_245 = false ;
goto V_261;
}
F_37 ( V_15 , V_68 ) ;
goto V_261;
}
F_93 ( V_15 , V_30 , V_136 , V_81 ) ;
if ( V_268 -> V_269 && F_119 ( V_81 ) )
F_120 ( V_81 ) ;
F_115 ( V_15 -> V_7 . V_262 , V_81 ) ;
F_38 ( V_15 , V_68 ) ;
V_261:
F_116 ( & V_15 -> V_11 , V_260 ,
& V_69 -> V_131 . V_132 ) ;
}
static inline void F_121 ( struct V_14 * V_15 ,
struct V_13 * V_30 ,
struct V_82 * V_68 ,
T_1 V_136 ,
struct V_80 * V_81 )
{
T_3 V_270 = F_122 ( V_30 ) ;
T_1 V_271 = V_270 * V_15 -> V_87 ;
T_1 V_272 = V_271 & ( V_94 - 1 ) ;
T_1 V_83 = V_271 >> V_119 ;
T_1 V_273 = V_83 ;
T_3 V_92 = F_9 ( T_3 , V_274 , V_136 ) ;
T_1 V_84 = V_272 + V_92 ;
T_3 V_18 = V_136 - V_92 ;
if ( F_10 ( V_84 >= V_94 ) ) {
V_83 ++ ;
V_84 -= V_94 ;
}
while ( V_18 ) {
T_1 V_275 =
F_9 ( T_1 , V_94 - V_84 , V_18 ) ;
F_41 ( V_15 , V_81 , V_68 , V_83 , V_84 ,
V_275 ) ;
V_18 -= V_275 ;
V_84 = 0 ;
V_83 ++ ;
}
F_46 ( V_15 -> V_59 , V_81 , V_68 , V_273 ,
V_272 , V_92 ) ;
V_81 -> V_52 += V_92 ;
V_81 -> V_85 += V_92 ;
}
void F_123 ( struct V_14 * V_15 , struct V_13 * V_30 )
{
T_3 V_276 = F_13 ( V_30 ) ;
T_3 V_277 = F_6 ( V_30 -> V_277 ) ;
struct V_82 * V_68 = & V_15 -> V_95 . V_96 [ V_277 ] ;
struct V_74 * V_69 = F_61 ( & V_15 -> V_11 , V_277 ) ;
struct V_80 * V_81 ;
T_3 V_136 ;
V_68 -> V_126 += V_276 ;
if ( F_10 ( ( V_30 -> V_26 >> 4 ) != V_258 ) ) {
V_15 -> V_21 . V_259 ++ ;
goto V_278;
}
if ( F_10 ( F_124 ( V_30 ) ) ) {
V_15 -> V_21 . V_279 ++ ;
goto V_278;
}
V_81 = F_125 ( V_15 -> V_7 . V_262 ,
F_42 ( V_274 ,
sizeof( long ) ) ) ;
if ( F_10 ( ! V_81 ) ) {
V_15 -> V_21 . V_135 ++ ;
goto V_278;
}
F_96 ( V_81 -> V_9 ) ;
V_136 = F_126 ( V_30 ) ;
F_121 ( V_15 , V_30 , V_68 , V_136 , V_81 ) ;
F_93 ( V_15 , V_30 , V_136 , V_81 ) ;
F_115 ( V_15 -> V_7 . V_262 , V_81 ) ;
V_278:
if ( F_32 ( V_68 -> V_126 < V_15 -> V_78 ) )
return;
F_59 ( V_15 , V_68 ) ;
F_116 ( & V_15 -> V_11 , V_30 -> V_277 , & V_69 -> V_131 . V_132 ) ;
}
int F_127 ( struct V_6 * V_7 , int V_280 )
{
struct V_14 * V_15 = F_128 ( V_7 , struct V_14 , V_7 ) ;
struct V_214 * V_218 = & V_15 -> V_218 ;
int V_281 = 0 ;
if ( F_10 ( ! F_63 ( V_130 , & V_15 -> V_129 ) ) )
return 0 ;
if ( V_7 -> V_17 )
V_281 += F_15 ( V_15 , V_7 , 0 , V_280 ) ;
for (; V_281 < V_280 ; V_281 ++ ) {
struct V_13 * V_30 = F_129 ( & V_7 -> V_11 ) ;
if ( ! V_30 )
break;
if ( F_130 ( V_30 ) == V_282 ) {
V_281 +=
F_16 ( V_15 , V_7 ,
V_280 - V_281 ) ;
continue;
}
F_131 ( & V_7 -> V_11 ) ;
V_15 -> V_43 ( V_15 , V_30 ) ;
}
if ( V_218 -> V_108 . V_234 ) {
F_94 ( V_218 ) ;
V_218 -> V_108 . V_234 = false ;
}
F_132 ( & V_7 -> V_11 ) ;
F_133 () ;
return V_281 ;
}
bool F_134 ( struct V_6 * V_7 )
{
struct V_214 * V_98 ;
struct V_14 * V_15 ;
T_3 V_283 ;
int V_41 ;
V_98 = F_128 ( V_7 , struct V_214 , V_7 ) ;
if ( F_10 ( ! F_63 ( V_284 , & V_98 -> V_129 ) ) )
return false ;
V_15 = F_128 ( V_98 , struct V_14 , V_218 ) ;
V_283 = V_98 -> V_39 ;
for ( V_41 = 0 ; V_41 < V_285 ; V_41 ++ ) {
struct V_13 * V_30 ;
T_3 V_20 ;
bool V_286 ;
V_30 = F_129 ( & V_7 -> V_11 ) ;
if ( ! V_30 )
break;
F_131 ( & V_7 -> V_11 ) ;
V_20 = F_6 ( V_30 -> V_20 ) ;
do {
struct V_46 * V_71 ;
T_3 V_10 ;
V_286 = ( V_283 == V_20 ) ;
V_10 = V_283 & V_98 -> V_11 . V_12 ;
V_71 = & V_98 -> V_108 . V_71 [ V_10 ] ;
V_283 ++ ;
F_31 ( V_15 , V_71 , true ) ;
} while ( ! V_286 );
}
F_132 ( & V_7 -> V_11 ) ;
F_133 () ;
V_98 -> V_39 = V_283 ;
return ( V_41 == V_285 ) ;
}
void F_135 ( struct V_214 * V_98 )
{
struct V_14 * V_15 = F_128 ( V_98 , struct V_14 , V_218 ) ;
struct V_46 * V_71 ;
T_3 V_10 ;
while ( V_98 -> V_39 != V_98 -> V_106 ) {
V_10 = V_98 -> V_39 & V_98 -> V_11 . V_12 ;
V_71 = & V_98 -> V_108 . V_71 [ V_10 ] ;
V_98 -> V_39 ++ ;
F_31 ( V_15 , V_71 , false ) ;
}
}
static inline void F_136 ( struct V_14 * V_15 ,
struct V_13 * V_30 ,
T_1 V_136 ,
struct V_80 * V_81 )
{
struct V_180 * V_181 = V_15 -> V_181 ;
struct V_1 * V_2 = V_15 -> V_2 ;
char * V_287 ;
T_2 * V_288 ;
T_2 V_289 ;
V_289 = ( F_5 ( V_30 -> V_290 ) >> 28 ) & 3 ;
V_288 = V_81 -> V_9 + V_291 ;
if ( ( ! V_289 ) || V_288 [ 0 ] != 0xff )
V_81 -> V_292 = V_293 ;
else if ( memcmp ( V_288 , V_181 -> V_294 + 4 , V_295 ) == 0 )
V_81 -> V_292 = V_296 ;
else
V_81 -> V_292 = V_297 ;
F_137 ( V_81 , V_298 ) ;
V_81 -> V_212 = * ( ( T_5 * ) ( V_81 -> V_9 ) ) ;
V_81 -> V_186 = V_188 ;
V_81 -> V_189 = F_83 ( ( V_190 V_191 ) V_30 -> V_31 ) ;
if ( F_10 ( F_1 ( V_2 ) ) )
F_86 ( V_2 , F_87 ( V_30 ) , F_88 ( V_81 ) ) ;
F_89 ( V_81 , V_15 -> V_75 ) ;
if ( F_32 ( V_181 -> V_183 & V_206 ) )
F_79 ( V_30 , V_81 ) ;
V_287 = F_138 ( V_81 , V_299 ) ;
memset ( V_287 , 0 , V_299 ) ;
F_139 ( V_81 ) ;
F_137 ( V_81 , V_300 ) ;
V_81 -> V_301 = V_181 ;
V_15 -> V_21 . V_192 ++ ;
V_15 -> V_21 . V_203 ++ ;
V_15 -> V_21 . V_213 += V_136 ;
}
void F_140 ( struct V_14 * V_15 , struct V_13 * V_30 )
{
struct V_67 * V_68 ;
struct V_74 * V_69 ;
T_5 V_260 ;
struct V_80 * V_81 ;
T_3 V_20 ;
T_1 V_136 ;
V_260 = V_30 -> V_20 ;
V_20 = F_6 ( V_260 ) ;
V_69 = F_61 ( & V_15 -> V_11 , V_20 ) ;
V_68 = & V_15 -> V_69 . V_76 [ V_20 ] ;
V_136 = F_5 ( V_30 -> V_18 ) ;
V_81 = F_104 ( V_15 , V_30 , V_68 , V_136 ) ;
if ( ! V_81 )
goto V_302;
F_136 ( V_15 , V_30 , V_136 , V_81 ) ;
F_115 ( V_15 -> V_7 . V_262 , V_81 ) ;
V_302:
F_38 ( V_15 , V_68 ) ;
F_116 ( & V_15 -> V_11 , V_260 ,
& V_69 -> V_131 . V_132 ) ;
}
void F_141 ( struct V_14 * V_15 , struct V_13 * V_30 )
{
struct V_67 * V_68 ;
struct V_74 * V_69 ;
T_5 V_260 ;
struct V_80 * V_81 ;
T_3 V_20 ;
T_1 V_136 ;
V_260 = V_30 -> V_20 ;
V_20 = F_6 ( V_260 ) ;
V_69 = F_61 ( & V_15 -> V_11 , V_20 ) ;
V_68 = & V_15 -> V_69 . V_76 [ V_20 ] ;
V_136 = F_5 ( V_30 -> V_18 ) ;
V_81 = F_104 ( V_15 , V_30 , V_68 , V_136 ) ;
if ( F_10 ( ! V_81 ) ) {
F_37 ( V_15 , V_68 ) ;
goto V_261;
}
V_81 = F_142 ( V_15 -> V_181 , V_81 ) ;
if ( F_10 ( ! V_81 ) ) {
F_37 ( V_15 , V_68 ) ;
goto V_261;
}
F_93 ( V_15 , V_30 , V_136 , V_81 ) ;
F_115 ( V_15 -> V_7 . V_262 , V_81 ) ;
F_38 ( V_15 , V_68 ) ;
V_261:
F_116 ( & V_15 -> V_11 , V_260 ,
& V_69 -> V_131 . V_132 ) ;
}
