static inline T_1 F_1 ( T_2 V_1 , T_2 V_2 , unsigned int V_3 ,
T_2 V_4 )
{
return F_2 ( V_5 |
( ( V_6 ) V_1 << V_7 ) |
( ( V_6 ) V_2 << V_8 ) |
( ( V_6 ) V_3 << V_9 ) |
( ( V_6 ) V_4 << V_10 ) ) ;
}
static void F_3 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
if ( V_14 -> V_15 ) {
if ( V_14 -> V_16 & V_17 )
F_4 ( V_14 -> V_18 ) ;
else
F_5 ( V_14 -> V_15 ) ;
if ( F_6 ( V_14 , V_19 ) )
F_7 ( V_12 -> V_20 ,
F_8 ( V_14 , V_21 ) ,
F_6 ( V_14 , V_19 ) ,
V_22 ) ;
} else if ( F_6 ( V_14 , V_19 ) ) {
F_9 ( V_12 -> V_20 ,
F_8 ( V_14 , V_21 ) ,
F_6 ( V_14 , V_19 ) ,
V_22 ) ;
}
V_14 -> V_23 = NULL ;
V_14 -> V_15 = NULL ;
F_10 ( V_14 , V_19 , 0 ) ;
}
void F_11 ( struct V_11 * V_24 )
{
unsigned long V_25 ;
T_3 V_26 ;
if ( ! V_24 -> V_27 )
return;
for ( V_26 = 0 ; V_26 < V_24 -> V_28 ; V_26 ++ )
F_3 ( V_24 , & V_24 -> V_27 [ V_26 ] ) ;
V_25 = sizeof( struct V_13 ) * V_24 -> V_28 ;
memset ( V_24 -> V_27 , 0 , V_25 ) ;
memset ( V_24 -> V_29 , 0 , V_24 -> V_3 ) ;
V_24 -> V_30 = 0 ;
V_24 -> V_31 = 0 ;
if ( ! V_24 -> V_32 )
return;
F_12 ( F_13 ( V_24 ) ) ;
}
void F_14 ( struct V_11 * V_24 )
{
F_11 ( V_24 ) ;
F_4 ( V_24 -> V_27 ) ;
V_24 -> V_27 = NULL ;
if ( V_24 -> V_29 ) {
F_15 ( V_24 -> V_20 , V_24 -> V_3 ,
V_24 -> V_29 , V_24 -> V_21 ) ;
V_24 -> V_29 = NULL ;
}
}
T_2 F_16 ( struct V_11 * V_12 , bool V_33 )
{
T_2 V_34 , V_35 ;
V_34 = V_12 -> V_31 ;
V_35 = F_17 ( V_12 -> V_35 ) ;
if ( V_34 != V_35 )
return ( V_34 < V_35 ) ?
V_35 - V_34 : ( V_35 + V_12 -> V_28 - V_34 ) ;
return 0 ;
}
static bool F_18 ( struct V_36 * V_37 ,
struct V_11 * V_24 , int V_38 )
{
T_3 V_26 = V_24 -> V_31 ;
struct V_13 * V_39 ;
struct V_40 * V_41 ;
unsigned int V_42 = 0 , V_43 = 0 ;
unsigned int V_44 = V_37 -> V_45 ;
V_39 = & V_24 -> V_27 [ V_26 ] ;
V_41 = F_19 ( V_24 , V_26 ) ;
V_26 -= V_24 -> V_28 ;
do {
struct V_40 * V_46 = V_39 -> V_23 ;
if ( ! V_46 )
break;
F_20 () ;
F_21 ( V_47 , V_24 , V_41 , V_39 ) ;
if ( ! ( V_46 -> V_48 &
F_2 ( V_49 ) ) )
break;
V_39 -> V_23 = NULL ;
V_42 += V_39 -> V_50 ;
V_43 += V_39 -> V_51 ;
F_22 ( V_39 -> V_15 , V_38 ) ;
F_7 ( V_24 -> V_20 ,
F_8 ( V_39 , V_21 ) ,
F_6 ( V_39 , V_19 ) ,
V_22 ) ;
V_39 -> V_15 = NULL ;
F_10 ( V_39 , V_19 , 0 ) ;
while ( V_41 != V_46 ) {
F_21 ( V_52 ,
V_24 , V_41 , V_39 ) ;
V_39 ++ ;
V_41 ++ ;
V_26 ++ ;
if ( F_23 ( ! V_26 ) ) {
V_26 -= V_24 -> V_28 ;
V_39 = V_24 -> V_27 ;
V_41 = F_19 ( V_24 , 0 ) ;
}
if ( F_6 ( V_39 , V_19 ) ) {
F_9 ( V_24 -> V_20 ,
F_8 ( V_39 , V_21 ) ,
F_6 ( V_39 , V_19 ) ,
V_22 ) ;
F_10 ( V_39 , V_19 , 0 ) ;
}
}
V_39 ++ ;
V_41 ++ ;
V_26 ++ ;
if ( F_23 ( ! V_26 ) ) {
V_26 -= V_24 -> V_28 ;
V_39 = V_24 -> V_27 ;
V_41 = F_19 ( V_24 , 0 ) ;
}
F_24 ( V_41 ) ;
V_44 -- ;
} while ( F_25 ( V_44 ) );
V_26 += V_24 -> V_28 ;
V_24 -> V_31 = V_26 ;
F_26 ( & V_24 -> V_53 ) ;
V_24 -> V_54 . V_55 += V_42 ;
V_24 -> V_54 . V_56 += V_43 ;
F_27 ( & V_24 -> V_53 ) ;
V_24 -> V_57 -> V_58 . V_42 += V_42 ;
V_24 -> V_57 -> V_58 . V_43 += V_43 ;
if ( V_24 -> V_59 & V_60 ) {
unsigned int V_61 = F_16 ( V_24 , false ) ;
if ( V_44 &&
( ( V_61 / V_62 ) == 0 ) && ( V_61 > 0 ) &&
! F_28 ( V_63 , V_37 -> V_64 ) &&
( F_29 ( V_24 ) != V_24 -> V_28 ) )
V_24 -> V_65 = true ;
}
F_30 ( F_13 ( V_24 ) ,
V_43 , V_42 ) ;
#define F_31 (DESC_NEEDED * 2)
if ( F_23 ( V_43 && F_32 ( V_24 -> V_32 ) &&
( F_29 ( V_24 ) >= F_31 ) ) ) {
F_33 () ;
if ( F_34 ( V_24 -> V_32 ,
V_24 -> V_66 ) &&
! F_28 ( V_63 , V_37 -> V_64 ) ) {
F_35 ( V_24 -> V_32 ,
V_24 -> V_66 ) ;
++ V_24 -> V_67 . V_68 ;
}
}
return ! ! V_44 ;
}
static void F_36 ( struct V_36 * V_37 ,
struct V_69 * V_57 )
{
T_3 V_59 = V_57 -> V_58 . V_12 [ 0 ] . V_59 ;
T_2 V_70 ;
if ( ! ( V_59 & V_60 ) )
return;
if ( V_57 -> V_71 )
return;
V_70 = V_72 |
V_73 ;
F_37 ( & V_37 -> V_74 -> V_75 ,
F_38 ( V_57 -> V_76 +
V_37 -> V_77 - 1 ) , V_70 ) ;
V_57 -> V_71 = true ;
}
void F_39 ( struct V_36 * V_37 , struct V_69 * V_57 )
{
T_2 V_70 = V_78 |
V_73 |
V_79 |
V_80
;
F_37 ( & V_37 -> V_74 -> V_75 ,
F_38 ( V_57 -> V_76 + V_37 -> V_77 - 1 ) ,
V_70 ) ;
}
static bool F_40 ( struct V_81 * V_82 )
{
enum V_83 V_84 = V_82 -> V_85 ;
struct V_69 * V_86 = V_82 -> V_12 -> V_57 ;
T_2 V_87 = V_82 -> V_88 ;
int V_89 ;
int V_90 ;
if ( V_82 -> V_43 == 0 || ! V_82 -> V_88 )
return false ;
V_90 = ( V_82 -> V_88 << 1 ) * V_91 ;
V_89 = V_82 -> V_42 / V_90 ;
switch ( V_84 ) {
case V_92 :
if ( V_89 > 10 )
V_84 = V_93 ;
break;
case V_93 :
if ( V_89 > 20 )
V_84 = V_94 ;
else if ( V_89 <= 10 )
V_84 = V_92 ;
break;
case V_94 :
case V_95 :
default:
if ( V_89 <= 20 )
V_84 = V_93 ;
break;
}
#define F_41 40000
if ( ( ( ( V_82 -> V_43 * 1000000 ) / V_90 ) > F_41 ) &&
( & V_86 -> V_96 == V_82 ) )
V_84 = V_95 ;
V_82 -> V_85 = V_84 ;
switch ( V_84 ) {
case V_92 :
V_87 = V_97 ;
break;
case V_93 :
V_87 = V_98 ;
break;
case V_94 :
V_87 = V_99 ;
break;
case V_95 :
V_87 = V_100 ;
break;
default:
break;
}
V_82 -> V_42 = 0 ;
V_82 -> V_43 = 0 ;
if ( V_87 != V_82 -> V_88 ) {
V_82 -> V_88 = V_87 ;
return true ;
}
return false ;
}
int F_42 ( struct V_11 * V_24 )
{
struct V_101 * V_20 = V_24 -> V_20 ;
int V_25 ;
if ( ! V_20 )
return - V_102 ;
F_43 ( V_24 -> V_27 ) ;
V_25 = sizeof( struct V_13 ) * V_24 -> V_28 ;
V_24 -> V_27 = F_44 ( V_25 , V_103 ) ;
if ( ! V_24 -> V_27 )
goto V_104;
V_24 -> V_3 = V_24 -> V_28 * sizeof( struct V_40 ) ;
V_24 -> V_3 = F_45 ( V_24 -> V_3 , 4096 ) ;
V_24 -> V_29 = F_46 ( V_20 , V_24 -> V_3 ,
& V_24 -> V_21 , V_103 ) ;
if ( ! V_24 -> V_29 ) {
F_47 ( V_20 , L_1 ,
V_24 -> V_3 ) ;
goto V_104;
}
V_24 -> V_30 = 0 ;
V_24 -> V_31 = 0 ;
return 0 ;
V_104:
F_4 ( V_24 -> V_27 ) ;
V_24 -> V_27 = NULL ;
return - V_102 ;
}
void F_48 ( struct V_11 * V_105 )
{
unsigned long V_25 ;
T_3 V_26 ;
if ( ! V_105 -> V_106 )
return;
if ( V_105 -> V_15 ) {
F_49 ( V_105 -> V_15 ) ;
V_105 -> V_15 = NULL ;
}
for ( V_26 = 0 ; V_26 < V_105 -> V_28 ; V_26 ++ ) {
struct V_107 * V_106 = & V_105 -> V_106 [ V_26 ] ;
if ( ! V_106 -> V_108 )
continue;
F_50 ( V_105 -> V_20 ,
V_106 -> V_21 ,
V_106 -> V_109 ,
V_105 -> V_110 ,
V_111 ) ;
F_51 ( V_105 -> V_20 , V_106 -> V_21 ,
F_52 ( V_105 ) ,
V_111 ,
V_112 ) ;
F_53 ( V_106 -> V_108 , V_106 -> V_113 ) ;
V_106 -> V_108 = NULL ;
V_106 -> V_109 = 0 ;
}
V_25 = sizeof( struct V_107 ) * V_105 -> V_28 ;
memset ( V_105 -> V_106 , 0 , V_25 ) ;
memset ( V_105 -> V_29 , 0 , V_105 -> V_3 ) ;
V_105 -> V_114 = 0 ;
V_105 -> V_31 = 0 ;
V_105 -> V_30 = 0 ;
}
void F_54 ( struct V_11 * V_105 )
{
F_48 ( V_105 ) ;
F_4 ( V_105 -> V_106 ) ;
V_105 -> V_106 = NULL ;
if ( V_105 -> V_29 ) {
F_15 ( V_105 -> V_20 , V_105 -> V_3 ,
V_105 -> V_29 , V_105 -> V_21 ) ;
V_105 -> V_29 = NULL ;
}
}
int F_55 ( struct V_11 * V_105 )
{
struct V_101 * V_20 = V_105 -> V_20 ;
int V_25 ;
F_43 ( V_105 -> V_106 ) ;
V_25 = sizeof( struct V_107 ) * V_105 -> V_28 ;
V_105 -> V_106 = F_44 ( V_25 , V_103 ) ;
if ( ! V_105 -> V_106 )
goto V_104;
F_56 ( & V_105 -> V_53 ) ;
V_105 -> V_3 = V_105 -> V_28 * sizeof( union V_115 ) ;
V_105 -> V_3 = F_45 ( V_105 -> V_3 , 4096 ) ;
V_105 -> V_29 = F_46 ( V_20 , V_105 -> V_3 ,
& V_105 -> V_21 , V_103 ) ;
if ( ! V_105 -> V_29 ) {
F_47 ( V_20 , L_2 ,
V_105 -> V_3 ) ;
goto V_104;
}
V_105 -> V_114 = 0 ;
V_105 -> V_31 = 0 ;
V_105 -> V_30 = 0 ;
return 0 ;
V_104:
F_4 ( V_105 -> V_106 ) ;
V_105 -> V_106 = NULL ;
return - V_102 ;
}
static inline void F_57 ( struct V_11 * V_105 , T_2 V_70 )
{
V_105 -> V_30 = V_70 ;
V_105 -> V_114 = V_70 ;
F_58 () ;
F_59 ( V_70 , V_105 -> V_35 ) ;
}
static inline unsigned int F_60 ( struct V_11 * V_105 )
{
return F_61 ( V_105 ) ? V_116 : 0 ;
}
static bool F_62 ( struct V_11 * V_105 ,
struct V_107 * V_117 )
{
struct V_108 * V_108 = V_117 -> V_108 ;
T_4 V_21 ;
if ( F_25 ( V_108 ) ) {
V_105 -> V_118 . V_119 ++ ;
return true ;
}
V_108 = F_63 ( F_64 ( V_105 ) ) ;
if ( F_23 ( ! V_108 ) ) {
V_105 -> V_118 . V_120 ++ ;
return false ;
}
V_21 = F_65 ( V_105 -> V_20 , V_108 , 0 ,
F_52 ( V_105 ) ,
V_111 ,
V_112 ) ;
if ( F_66 ( V_105 -> V_20 , V_21 ) ) {
F_67 ( V_108 , F_64 ( V_105 ) ) ;
V_105 -> V_118 . V_120 ++ ;
return false ;
}
V_117 -> V_21 = V_21 ;
V_117 -> V_108 = V_108 ;
V_117 -> V_109 = F_60 ( V_105 ) ;
V_117 -> V_113 = 1 ;
return true ;
}
static void F_68 ( struct V_11 * V_105 ,
struct V_121 * V_15 , T_3 V_122 )
{
struct V_69 * V_57 = V_105 -> V_57 ;
if ( ( V_105 -> V_32 -> V_123 & V_124 ) &&
( V_122 & V_125 ) )
F_69 ( V_15 , F_70 ( V_126 ) , V_122 ) ;
F_71 ( & V_57 -> V_127 , V_15 ) ;
}
bool F_72 ( struct V_11 * V_105 , T_3 V_128 )
{
T_3 V_129 = V_105 -> V_30 ;
union V_130 * V_131 ;
struct V_107 * V_117 ;
if ( ! V_105 -> V_32 || ! V_128 )
return false ;
V_131 = F_73 ( V_105 , V_129 ) ;
V_117 = & V_105 -> V_106 [ V_129 ] ;
do {
if ( ! F_62 ( V_105 , V_117 ) )
goto V_132;
F_74 ( V_105 -> V_20 , V_117 -> V_21 ,
V_117 -> V_109 ,
V_105 -> V_110 ,
V_111 ) ;
V_131 -> V_133 . V_134 = F_2 ( V_117 -> V_21 + V_117 -> V_109 ) ;
V_131 ++ ;
V_117 ++ ;
V_129 ++ ;
if ( F_23 ( V_129 == V_105 -> V_28 ) ) {
V_131 = F_73 ( V_105 , 0 ) ;
V_117 = V_105 -> V_106 ;
V_129 = 0 ;
}
V_131 -> V_135 . V_136 . V_137 = 0 ;
V_128 -- ;
} while ( V_128 );
if ( V_105 -> V_30 != V_129 )
F_57 ( V_105 , V_129 ) ;
return false ;
V_132:
if ( V_105 -> V_30 != V_129 )
F_57 ( V_105 , V_129 ) ;
return true ;
}
static inline void F_75 ( struct V_36 * V_37 ,
struct V_121 * V_15 ,
union V_130 * V_131 )
{
struct V_138 V_139 ;
T_2 V_140 , V_141 ;
bool V_142 , V_143 ;
T_5 V_144 ;
V_6 V_145 ;
V_145 = F_76 ( V_131 -> V_135 . V_136 . V_137 ) ;
V_144 = ( V_145 & V_146 ) >> V_147 ;
V_140 = ( V_145 & V_148 ) >>
V_149 ;
V_141 = ( V_145 & V_150 ) >>
V_151 ;
V_139 = F_77 ( V_144 ) ;
V_15 -> V_152 = V_153 ;
F_78 ( V_15 ) ;
if ( ! ( V_37 -> V_32 -> V_123 & V_154 ) )
return;
if ( ! ( V_141 & F_79 ( V_155 ) ) )
return;
if ( ! ( V_139 . V_156 && V_139 . V_157 ) )
return;
V_142 = ( V_139 . V_157 == V_158 ) &&
( V_139 . V_159 == V_160 ) ;
V_143 = ( V_139 . V_157 == V_158 ) &&
( V_139 . V_159 == V_161 ) ;
if ( V_142 &&
( V_140 & ( F_79 ( V_162 ) |
F_79 ( V_163 ) ) ) )
goto V_164;
if ( V_143 &&
V_141 & F_79 ( V_165 ) )
return;
if ( V_140 & F_79 ( V_166 ) )
goto V_164;
if ( V_140 & F_79 ( V_167 ) )
return;
switch ( V_139 . V_168 ) {
case V_169 :
case V_170 :
case V_171 :
V_15 -> V_152 = V_172 ;
default:
break;
}
return;
V_164:
V_37 -> V_74 -> V_173 ++ ;
}
static inline int F_80 ( T_5 V_144 )
{
struct V_138 V_139 = F_77 ( V_144 ) ;
if ( ! V_139 . V_156 )
return V_174 ;
if ( V_139 . V_157 == V_158 &&
V_139 . V_175 == V_176 )
return V_177 ;
else if ( V_139 . V_157 == V_158 &&
V_139 . V_175 == V_178 )
return V_179 ;
else
return V_180 ;
}
static inline void F_81 ( struct V_11 * V_12 ,
union V_130 * V_131 ,
struct V_121 * V_15 ,
T_5 V_181 )
{
T_2 V_182 ;
const T_1 V_183 =
F_2 ( ( V_6 ) V_184 <<
V_185 ) ;
if ( V_12 -> V_32 -> V_123 & V_186 )
return;
if ( ( V_131 -> V_135 . V_136 . V_137 & V_183 ) == V_183 ) {
V_182 = F_82 ( V_131 -> V_135 . V_187 . V_188 . V_189 ) ;
F_83 ( V_15 , V_182 , F_80 ( V_181 ) ) ;
}
}
static inline
void F_84 ( struct V_11 * V_105 ,
union V_130 * V_131 , struct V_121 * V_15 ,
T_5 V_181 )
{
F_81 ( V_105 , V_131 , V_15 , V_181 ) ;
F_75 ( V_105 -> V_37 , V_15 , V_131 ) ;
F_85 ( V_15 , V_105 -> V_66 ) ;
V_15 -> V_190 = F_86 ( V_15 , V_105 -> V_32 ) ;
}
static bool F_87 ( struct V_11 * V_105 , struct V_121 * V_15 )
{
if ( F_88 ( V_15 ) )
return true ;
return false ;
}
static void F_89 ( struct V_11 * V_105 ,
struct V_107 * V_191 )
{
struct V_107 * V_192 ;
T_3 V_193 = V_105 -> V_114 ;
V_192 = & V_105 -> V_106 [ V_193 ] ;
V_193 ++ ;
V_105 -> V_114 = ( V_193 < V_105 -> V_28 ) ? V_193 : 0 ;
V_192 -> V_21 = V_191 -> V_21 ;
V_192 -> V_108 = V_191 -> V_108 ;
V_192 -> V_109 = V_191 -> V_109 ;
V_192 -> V_113 = V_191 -> V_113 ;
}
static inline bool F_90 ( struct V_108 * V_108 )
{
return ( F_91 ( V_108 ) == F_92 () ) &&
! F_93 ( V_108 ) ;
}
static bool F_94 ( struct V_107 * V_194 )
{
unsigned int V_113 = V_194 -> V_113 ;
struct V_108 * V_108 = V_194 -> V_108 ;
if ( F_23 ( ! F_90 ( V_108 ) ) )
return false ;
#if ( V_195 < 8192 )
if ( F_23 ( ( F_95 ( V_108 ) - V_113 ) > 1 ) )
return false ;
#else
#define F_96 \
(SKB_WITH_OVERHEAD(PAGE_SIZE) - I40E_RXBUFFER_2048)
if ( V_194 -> V_109 > F_96 )
return false ;
#endif
if ( F_23 ( ! V_113 ) ) {
F_97 ( V_108 , V_196 ) ;
V_194 -> V_113 = V_196 ;
}
return true ;
}
static void F_98 ( struct V_11 * V_105 ,
struct V_107 * V_194 ,
struct V_121 * V_15 ,
unsigned int V_3 )
{
#if ( V_195 < 8192 )
unsigned int V_197 = F_52 ( V_105 ) / 2 ;
#else
unsigned int V_197 = F_99 ( V_3 + F_60 ( V_105 ) ) ;
#endif
F_100 ( V_15 , F_101 ( V_15 ) -> V_198 , V_194 -> V_108 ,
V_194 -> V_109 , V_3 , V_197 ) ;
#if ( V_195 < 8192 )
V_194 -> V_109 ^= V_197 ;
#else
V_194 -> V_109 += V_197 ;
#endif
}
static struct V_107 * F_102 ( struct V_11 * V_105 ,
const unsigned int V_3 )
{
struct V_107 * V_194 ;
V_194 = & V_105 -> V_106 [ V_105 -> V_31 ] ;
F_103 ( V_194 -> V_108 ) ;
F_50 ( V_105 -> V_20 ,
V_194 -> V_21 ,
V_194 -> V_109 ,
V_3 ,
V_111 ) ;
V_194 -> V_113 -- ;
return V_194 ;
}
static struct V_121 * F_104 ( struct V_11 * V_105 ,
struct V_107 * V_194 ,
unsigned int V_3 )
{
void * V_199 = F_105 ( V_194 -> V_108 ) + V_194 -> V_109 ;
#if ( V_195 < 8192 )
unsigned int V_197 = F_52 ( V_105 ) / 2 ;
#else
unsigned int V_197 = F_99 ( V_3 ) ;
#endif
unsigned int V_200 ;
struct V_121 * V_15 ;
F_24 ( V_199 ) ;
#if V_201 < 128
F_24 ( V_199 + V_201 ) ;
#endif
V_15 = F_106 ( & V_105 -> V_57 -> V_127 ,
V_202 ,
V_203 | V_204 ) ;
if ( F_23 ( ! V_15 ) )
return NULL ;
V_200 = V_3 ;
if ( V_200 > V_202 )
V_200 = F_107 ( V_199 , V_202 ) ;
memcpy ( F_108 ( V_15 , V_200 ) , V_199 , F_45 ( V_200 , sizeof( long ) ) ) ;
V_3 -= V_200 ;
if ( V_3 ) {
F_100 ( V_15 , 0 , V_194 -> V_108 ,
V_194 -> V_109 + V_200 ,
V_3 , V_197 ) ;
#if ( V_195 < 8192 )
V_194 -> V_109 ^= V_197 ;
#else
V_194 -> V_109 += V_197 ;
#endif
} else {
V_194 -> V_113 ++ ;
}
return V_15 ;
}
static struct V_121 * F_109 ( struct V_11 * V_105 ,
struct V_107 * V_194 ,
unsigned int V_3 )
{
void * V_199 = F_105 ( V_194 -> V_108 ) + V_194 -> V_109 ;
#if ( V_195 < 8192 )
unsigned int V_197 = F_52 ( V_105 ) / 2 ;
#else
unsigned int V_197 = F_99 ( sizeof( struct V_205 ) ) +
F_99 ( V_116 + V_3 ) ;
#endif
struct V_121 * V_15 ;
F_24 ( V_199 ) ;
#if V_201 < 128
F_24 ( V_199 + V_201 ) ;
#endif
V_15 = F_110 ( V_199 - V_116 , V_197 ) ;
if ( F_23 ( ! V_15 ) )
return NULL ;
F_111 ( V_15 , V_116 ) ;
F_108 ( V_15 , V_3 ) ;
#if ( V_195 < 8192 )
V_194 -> V_109 ^= V_197 ;
#else
V_194 -> V_109 += V_197 ;
#endif
return V_15 ;
}
static void F_112 ( struct V_11 * V_105 ,
struct V_107 * V_194 )
{
if ( F_94 ( V_194 ) ) {
F_89 ( V_105 , V_194 ) ;
V_105 -> V_118 . V_119 ++ ;
} else {
F_51 ( V_105 -> V_20 , V_194 -> V_21 ,
F_52 ( V_105 ) ,
V_111 , V_112 ) ;
F_53 ( V_194 -> V_108 ,
V_194 -> V_113 ) ;
}
V_194 -> V_108 = NULL ;
}
static bool F_113 ( struct V_11 * V_105 ,
union V_130 * V_131 ,
struct V_121 * V_15 )
{
T_2 V_206 = V_105 -> V_31 + 1 ;
V_206 = ( V_206 < V_105 -> V_28 ) ? V_206 : 0 ;
V_105 -> V_31 = V_206 ;
F_24 ( F_73 ( V_105 , V_206 ) ) ;
#define F_114 BIT(I40E_RX_DESC_STATUS_EOF_SHIFT)
if ( F_25 ( F_115 ( V_131 , F_114 ) ) )
return false ;
V_105 -> V_118 . V_207 ++ ;
return true ;
}
static int F_116 ( struct V_11 * V_105 , int V_44 )
{
unsigned int V_208 = 0 , V_209 = 0 ;
struct V_121 * V_15 = V_105 -> V_15 ;
T_3 V_128 = F_29 ( V_105 ) ;
bool V_210 = false ;
while ( F_25 ( V_209 < V_44 ) ) {
struct V_107 * V_194 ;
union V_130 * V_131 ;
unsigned int V_3 ;
T_3 V_122 ;
T_5 V_181 ;
V_6 V_145 ;
if ( V_128 >= V_211 ) {
V_210 = V_210 ||
F_72 ( V_105 , V_128 ) ;
V_128 = 0 ;
}
V_131 = F_73 ( V_105 , V_105 -> V_31 ) ;
V_145 = F_76 ( V_131 -> V_135 . V_136 . V_137 ) ;
F_117 () ;
V_3 = ( V_145 & V_212 ) >>
V_213 ;
if ( ! V_3 )
break;
F_21 ( V_214 , V_105 , V_131 , V_15 ) ;
V_194 = F_102 ( V_105 , V_3 ) ;
if ( V_15 )
F_98 ( V_105 , V_194 , V_15 , V_3 ) ;
else if ( F_61 ( V_105 ) )
V_15 = F_109 ( V_105 , V_194 , V_3 ) ;
else
V_15 = F_104 ( V_105 , V_194 , V_3 ) ;
if ( ! V_15 ) {
V_105 -> V_118 . V_215 ++ ;
V_194 -> V_113 ++ ;
break;
}
F_112 ( V_105 , V_194 ) ;
V_128 ++ ;
if ( F_113 ( V_105 , V_131 , V_15 ) )
continue;
if ( F_23 ( F_115 ( V_131 , F_79 ( V_149 ) ) ) ) {
F_5 ( V_15 ) ;
V_15 = NULL ;
continue;
}
if ( F_87 ( V_105 , V_15 ) ) {
V_15 = NULL ;
continue;
}
V_208 += V_15 -> V_19 ;
V_145 = F_76 ( V_131 -> V_135 . V_136 . V_137 ) ;
V_181 = ( V_145 & V_146 ) >>
V_147 ;
F_84 ( V_105 , V_131 , V_15 , V_181 ) ;
V_122 = ( V_145 & F_79 ( V_216 ) ) ?
F_118 ( V_131 -> V_135 . V_187 . V_217 . V_218 ) : 0 ;
F_21 ( V_219 , V_105 , V_131 , V_15 ) ;
F_68 ( V_105 , V_15 , V_122 ) ;
V_15 = NULL ;
V_209 ++ ;
}
V_105 -> V_15 = V_15 ;
F_26 ( & V_105 -> V_53 ) ;
V_105 -> V_54 . V_56 += V_209 ;
V_105 -> V_54 . V_55 += V_208 ;
F_27 ( & V_105 -> V_53 ) ;
V_105 -> V_57 -> V_96 . V_43 += V_209 ;
V_105 -> V_57 -> V_96 . V_42 += V_208 ;
return V_210 ? V_44 : V_209 ;
}
static T_2 F_119 ( const int type , const T_3 V_88 )
{
T_2 V_70 ;
V_70 = V_78 |
( type << V_220 ) |
( V_88 << V_221 ) ;
return V_70 ;
}
static inline int F_120 ( struct V_36 * V_37 , int V_222 )
{
struct V_223 * V_224 = V_37 -> V_74 ;
return V_224 -> V_225 [ V_222 ] . V_226 ;
}
static inline int F_121 ( struct V_36 * V_37 , int V_222 )
{
struct V_223 * V_224 = V_37 -> V_74 ;
return V_224 -> V_227 [ V_222 ] . V_228 ;
}
static inline void F_122 ( struct V_36 * V_37 ,
struct V_69 * V_57 )
{
struct V_229 * V_75 = & V_37 -> V_74 -> V_75 ;
bool V_96 = false , V_58 = false ;
T_2 V_230 , V_231 ;
int V_232 ;
int V_222 = V_57 -> V_76 ;
int V_226 , V_228 ;
V_232 = ( V_57 -> V_76 + V_37 -> V_77 ) ;
V_230 = V_231 = F_119 ( V_233 , 0 ) ;
V_226 = F_120 ( V_37 , V_222 ) ;
V_228 = F_121 ( V_37 , V_222 ) ;
if ( V_57 -> V_234 > 0 ||
( ! F_123 ( V_226 ) &&
! F_123 ( V_228 ) ) ) {
goto V_235;
}
if ( F_123 ( V_226 ) ) {
V_96 = F_40 ( & V_57 -> V_96 ) ;
V_230 = F_119 ( V_236 , V_57 -> V_96 . V_88 ) ;
}
if ( F_123 ( V_228 ) ) {
V_58 = F_40 ( & V_57 -> V_58 ) ;
V_231 = F_119 ( V_237 , V_57 -> V_58 . V_88 ) ;
}
if ( V_96 || V_58 ) {
T_3 V_88 = F_124 ( V_57 -> V_58 . V_88 , V_57 -> V_96 . V_88 ) ;
V_57 -> V_58 . V_88 = V_57 -> V_96 . V_88 = V_88 ;
V_231 = F_119 ( V_237 , V_88 ) ;
V_58 = true ;
V_230 = F_119 ( V_236 , V_88 ) ;
V_96 = true ;
}
if ( V_96 ) {
V_230 |= F_79 ( 31 ) ;
F_37 ( V_75 , F_125 ( V_232 - 1 ) , V_230 ) ;
}
V_235:
if ( ! F_28 ( V_63 , V_37 -> V_64 ) )
F_37 ( V_75 , F_125 ( V_232 - 1 ) , V_231 ) ;
if ( V_57 -> V_234 )
V_57 -> V_234 -- ;
else
V_57 -> V_234 = V_91 ;
}
int F_126 ( struct V_238 * V_127 , int V_44 )
{
struct V_69 * V_57 =
F_127 ( V_127 , struct V_69 , V_127 ) ;
struct V_36 * V_37 = V_57 -> V_37 ;
struct V_11 * V_12 ;
bool V_239 = true ;
bool V_65 = false ;
int V_240 ;
int V_241 = 0 ;
if ( F_28 ( V_63 , V_37 -> V_64 ) ) {
F_128 ( V_127 ) ;
return 0 ;
}
F_129 (ring, q_vector->tx) {
if ( ! F_18 ( V_37 , V_12 , V_44 ) ) {
V_239 = false ;
continue;
}
V_65 |= V_12 -> V_65 ;
V_12 -> V_65 = false ;
}
if ( V_44 <= 0 )
goto V_242;
V_240 = F_124 ( V_44 / V_57 -> V_243 , 1 ) ;
F_129 (ring, q_vector->rx) {
int V_244 = F_116 ( V_12 , V_240 ) ;
V_241 += V_244 ;
if ( V_244 >= V_240 )
V_239 = false ;
}
if ( ! V_239 ) {
const T_6 * V_245 = & V_57 -> V_246 ;
int V_247 = F_130 () ;
if ( F_25 ( F_131 ( V_247 , V_245 ) ) ) {
V_242:
if ( V_65 ) {
V_57 -> V_58 . V_12 [ 0 ] . V_67 . V_248 ++ ;
F_36 ( V_37 , V_57 ) ;
}
return V_44 ;
}
}
if ( V_37 -> V_74 -> V_59 & V_60 )
V_57 -> V_71 = false ;
F_132 ( V_127 , V_241 ) ;
if ( ! V_239 )
F_39 ( V_37 , V_57 ) ;
else
F_122 ( V_37 , V_57 ) ;
return F_133 ( V_241 , V_44 - 1 ) ;
}
static inline int F_134 ( struct V_121 * V_15 ,
struct V_11 * V_24 ,
T_2 * V_59 )
{
T_7 V_190 = V_15 -> V_190 ;
T_2 V_16 = 0 ;
if ( V_190 == F_70 ( V_126 ) &&
! ( V_24 -> V_32 -> V_123 & V_249 ) ) {
V_15 -> V_190 = F_135 ( V_15 ) ;
goto V_250;
}
if ( F_136 ( V_15 ) ) {
V_16 |= F_137 ( V_15 ) << V_251 ;
V_16 |= V_252 ;
} else if ( V_190 == F_70 ( V_126 ) ) {
struct V_253 * V_254 , V_255 ;
V_254 = F_138 ( V_15 , V_256 , sizeof( V_255 ) , & V_255 ) ;
if ( ! V_254 )
return - V_257 ;
V_190 = V_254 -> V_258 ;
V_16 |= F_139 ( V_254 -> V_259 ) << V_251 ;
V_16 |= V_260 ;
}
V_250:
* V_59 = V_16 ;
return 0 ;
}
static int F_140 ( struct V_13 * V_261 , T_5 * V_262 ,
V_6 * V_263 )
{
struct V_121 * V_15 = V_261 -> V_15 ;
V_6 V_264 , V_265 , V_266 ;
union {
struct V_267 * V_268 ;
struct V_269 * V_270 ;
unsigned char * V_271 ;
} V_272 ;
union {
struct V_273 * V_274 ;
struct V_275 * V_276 ;
unsigned char * V_271 ;
} V_277 ;
T_2 V_278 , V_279 ;
T_3 V_51 , V_280 ;
int V_104 ;
if ( V_15 -> V_152 != V_281 )
return 0 ;
if ( ! F_141 ( V_15 ) )
return 0 ;
V_104 = F_142 ( V_15 , 0 ) ;
if ( V_104 < 0 )
return V_104 ;
V_272 . V_271 = F_143 ( V_15 ) ;
V_277 . V_271 = F_144 ( V_15 ) ;
if ( V_272 . V_268 -> V_282 == 4 ) {
V_272 . V_268 -> V_283 = 0 ;
V_272 . V_268 -> V_284 = 0 ;
} else {
V_272 . V_270 -> V_285 = 0 ;
}
if ( F_101 ( V_15 ) -> V_286 & ( V_287 |
V_288 |
V_289 |
V_290 |
V_291 |
V_292 ) ) {
if ( ! ( F_101 ( V_15 ) -> V_286 & V_293 ) &&
( F_101 ( V_15 ) -> V_286 & V_292 ) ) {
V_277 . V_276 -> V_19 = 0 ;
V_279 = V_277 . V_271 - V_15 -> V_294 ;
V_278 = V_15 -> V_19 - V_279 ;
F_145 ( & V_277 . V_276 -> V_284 ,
( V_295 V_296 ) F_146 ( V_278 ) ) ;
}
V_272 . V_271 = F_147 ( V_15 ) ;
V_277 . V_271 = F_148 ( V_15 ) ;
if ( V_272 . V_268 -> V_282 == 4 ) {
V_272 . V_268 -> V_283 = 0 ;
V_272 . V_268 -> V_284 = 0 ;
} else {
V_272 . V_270 -> V_285 = 0 ;
}
}
V_279 = V_277 . V_271 - V_15 -> V_294 ;
V_278 = V_15 -> V_19 - V_279 ;
F_145 ( & V_277 . V_274 -> V_284 , ( V_295 V_296 ) F_146 ( V_278 ) ) ;
* V_262 = ( V_277 . V_274 -> V_297 * 4 ) + V_279 ;
V_280 = F_101 ( V_15 ) -> V_280 ;
V_51 = F_101 ( V_15 ) -> V_51 ;
V_261 -> V_51 = V_51 ;
V_261 -> V_50 += ( V_261 -> V_51 - 1 ) * * V_262 ;
V_264 = V_298 ;
V_265 = V_15 -> V_19 - * V_262 ;
V_266 = V_280 ;
* V_263 |= ( V_264 << V_299 ) |
( V_265 << V_300 ) |
( V_266 << V_301 ) ;
return 1 ;
}
static int F_149 ( struct V_121 * V_15 , T_2 * V_16 ,
T_2 * V_1 , T_2 * V_2 ,
struct V_11 * V_24 ,
T_2 * V_302 )
{
union {
struct V_267 * V_268 ;
struct V_269 * V_270 ;
unsigned char * V_271 ;
} V_272 ;
union {
struct V_273 * V_274 ;
struct V_275 * V_276 ;
unsigned char * V_271 ;
} V_277 ;
unsigned char * V_303 ;
T_2 V_304 , V_305 = 0 ;
T_7 V_306 ;
T_5 V_307 = 0 ;
if ( V_15 -> V_152 != V_281 )
return 0 ;
V_272 . V_271 = F_143 ( V_15 ) ;
V_277 . V_271 = F_144 ( V_15 ) ;
V_304 = ( ( V_272 . V_271 - V_15 -> V_294 ) / 2 ) << V_308 ;
if ( V_15 -> V_309 ) {
T_2 V_310 = 0 ;
if ( * V_16 & V_311 ) {
V_310 |= ( * V_16 & V_312 ) ?
V_313 :
V_314 ;
V_307 = V_272 . V_268 -> V_190 ;
} else if ( * V_16 & V_315 ) {
V_310 |= V_316 ;
V_303 = V_272 . V_271 + sizeof( * V_272 . V_270 ) ;
V_307 = V_272 . V_270 -> V_317 ;
if ( V_277 . V_271 != V_303 )
F_150 ( V_15 , V_303 - V_15 -> V_294 ,
& V_307 , & V_306 ) ;
}
switch ( V_307 ) {
case V_318 :
V_310 |= V_319 ;
* V_16 |= V_320 ;
break;
case V_321 :
V_310 |= V_322 ;
* V_16 |= V_320 ;
break;
case V_323 :
case V_324 :
* V_16 |= V_320 ;
V_277 . V_271 = F_147 ( V_15 ) ;
break;
default:
if ( * V_16 & V_312 )
return - 1 ;
F_151 ( V_15 ) ;
return 0 ;
}
V_310 |= ( ( V_277 . V_271 - V_272 . V_271 ) / 4 ) <<
V_325 ;
V_272 . V_271 = F_147 ( V_15 ) ;
V_310 |= ( ( V_272 . V_271 - V_277 . V_271 ) / 2 ) <<
V_326 ;
if ( ( * V_16 & V_312 ) &&
! ( F_101 ( V_15 ) -> V_286 & V_293 ) &&
( F_101 ( V_15 ) -> V_286 & V_292 ) )
V_310 |= V_327 ;
* V_302 |= V_310 ;
V_277 . V_271 = F_148 ( V_15 ) ;
V_307 = 0 ;
* V_16 &= ~ ( V_311 | V_315 ) ;
if ( V_272 . V_268 -> V_282 == 4 )
* V_16 |= V_311 ;
if ( V_272 . V_270 -> V_282 == 6 )
* V_16 |= V_315 ;
}
if ( * V_16 & V_311 ) {
V_307 = V_272 . V_268 -> V_190 ;
V_305 |= ( * V_16 & V_312 ) ?
V_328 :
V_329 ;
} else if ( * V_16 & V_315 ) {
V_305 |= V_330 ;
V_303 = V_272 . V_271 + sizeof( * V_272 . V_270 ) ;
V_307 = V_272 . V_270 -> V_317 ;
if ( V_277 . V_271 != V_303 )
F_150 ( V_15 , V_303 - V_15 -> V_294 ,
& V_307 , & V_306 ) ;
}
V_304 |= ( ( V_277 . V_271 - V_272 . V_271 ) / 4 ) << V_331 ;
switch ( V_307 ) {
case V_332 :
V_305 |= V_333 ;
V_304 |= V_277 . V_274 -> V_297 << V_334 ;
break;
case V_335 :
V_305 |= V_336 ;
V_304 |= ( sizeof( struct V_337 ) >> 2 ) <<
V_334 ;
break;
case V_318 :
V_305 |= V_338 ;
V_304 |= ( sizeof( struct V_275 ) >> 2 ) <<
V_334 ;
break;
default:
if ( * V_16 & V_312 )
return - 1 ;
F_151 ( V_15 ) ;
return 0 ;
}
* V_1 |= V_305 ;
* V_2 |= V_304 ;
return 1 ;
}
static void F_152 ( struct V_11 * V_24 ,
const V_6 V_263 ,
const T_2 V_302 , const T_2 V_339 )
{
struct V_340 * V_341 ;
int V_26 = V_24 -> V_30 ;
if ( ( V_263 == V_342 ) &&
! V_302 && ! V_339 )
return;
V_341 = F_153 ( V_24 , V_26 ) ;
V_26 ++ ;
V_24 -> V_30 = ( V_26 < V_24 -> V_28 ) ? V_26 : 0 ;
V_341 -> V_343 = F_154 ( V_302 ) ;
V_341 -> V_344 = F_155 ( V_339 ) ;
V_341 -> V_345 = F_155 ( 0 ) ;
V_341 -> V_346 = F_2 ( V_263 ) ;
}
bool F_156 ( struct V_121 * V_15 )
{
const struct V_347 * V_348 , * V_349 ;
int V_198 , V_350 ;
V_198 = F_101 ( V_15 ) -> V_198 ;
if ( V_198 < ( V_351 - 1 ) )
return false ;
V_198 -= V_351 - 2 ;
V_348 = & F_101 ( V_15 ) -> V_352 [ 0 ] ;
V_350 = 1 - F_101 ( V_15 ) -> V_280 ;
V_350 += F_157 ( V_348 ++ ) ;
V_350 += F_157 ( V_348 ++ ) ;
V_350 += F_157 ( V_348 ++ ) ;
V_350 += F_157 ( V_348 ++ ) ;
V_350 += F_157 ( V_348 ++ ) ;
V_349 = & F_101 ( V_15 ) -> V_352 [ 0 ] ;
for (; ; ) {
V_350 += F_157 ( V_348 ++ ) ;
if ( V_350 < 0 )
return true ;
if ( ! V_198 -- )
break;
V_350 -= F_157 ( V_349 ++ ) ;
}
return false ;
}
int F_158 ( struct V_11 * V_24 , int V_3 )
{
F_159 ( V_24 -> V_32 , V_24 -> V_66 ) ;
F_33 () ;
if ( F_25 ( F_29 ( V_24 ) < V_3 ) )
return - V_353 ;
F_160 ( V_24 -> V_32 , V_24 -> V_66 ) ;
++ V_24 -> V_67 . V_68 ;
return 0 ;
}
static inline void F_161 ( struct V_11 * V_24 , struct V_121 * V_15 ,
struct V_13 * V_261 , T_2 V_16 ,
const T_5 V_262 , T_2 V_1 , T_2 V_2 )
{
unsigned int V_354 = V_15 -> V_354 ;
unsigned int V_3 = F_162 ( V_15 ) ;
struct V_347 * V_348 ;
struct V_13 * V_27 ;
struct V_40 * V_41 ;
T_3 V_26 = V_24 -> V_30 ;
T_2 V_4 = 0 ;
T_4 V_21 ;
if ( V_16 & V_252 ) {
V_1 |= V_355 ;
V_4 = ( V_16 & V_356 ) >>
V_251 ;
}
V_261 -> V_16 = V_16 ;
V_21 = F_163 ( V_24 -> V_20 , V_15 -> V_294 , V_3 , V_22 ) ;
V_41 = F_19 ( V_24 , V_26 ) ;
V_27 = V_261 ;
for ( V_348 = & F_101 ( V_15 ) -> V_352 [ 0 ] ; ; V_348 ++ ) {
unsigned int V_357 = V_358 ;
if ( F_66 ( V_24 -> V_20 , V_21 ) )
goto V_359;
F_10 ( V_27 , V_19 , V_3 ) ;
F_164 ( V_27 , V_21 , V_21 ) ;
V_357 += - V_21 & ( V_360 - 1 ) ;
V_41 -> V_361 = F_2 ( V_21 ) ;
while ( F_23 ( V_3 > V_362 ) ) {
V_41 -> V_48 =
F_1 ( V_1 , V_2 ,
V_357 , V_4 ) ;
V_41 ++ ;
V_26 ++ ;
if ( V_26 == V_24 -> V_28 ) {
V_41 = F_19 ( V_24 , 0 ) ;
V_26 = 0 ;
}
V_21 += V_357 ;
V_3 -= V_357 ;
V_357 = V_358 ;
V_41 -> V_361 = F_2 ( V_21 ) ;
}
if ( F_25 ( ! V_354 ) )
break;
V_41 -> V_48 = F_1 ( V_1 , V_2 ,
V_3 , V_4 ) ;
V_41 ++ ;
V_26 ++ ;
if ( V_26 == V_24 -> V_28 ) {
V_41 = F_19 ( V_24 , 0 ) ;
V_26 = 0 ;
}
V_3 = F_157 ( V_348 ) ;
V_354 -= V_3 ;
V_21 = F_165 ( V_24 -> V_20 , V_348 , 0 , V_3 ,
V_22 ) ;
V_27 = & V_24 -> V_27 [ V_26 ] ;
}
F_166 ( F_13 ( V_24 ) , V_261 -> V_50 ) ;
V_26 ++ ;
if ( V_26 == V_24 -> V_28 )
V_26 = 0 ;
V_24 -> V_30 = V_26 ;
F_167 ( V_24 , V_363 ) ;
V_1 |= V_364 ;
V_41 -> V_48 =
F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
F_58 () ;
V_261 -> V_23 = V_41 ;
if ( F_168 ( F_13 ( V_24 ) ) || ! V_15 -> V_365 ) {
F_59 ( V_26 , V_24 -> V_35 ) ;
F_169 () ;
}
return;
V_359:
F_47 ( V_24 -> V_20 , L_3 ) ;
for (; ; ) {
V_27 = & V_24 -> V_27 [ V_26 ] ;
F_3 ( V_24 , V_27 ) ;
if ( V_27 == V_261 )
break;
if ( V_26 == 0 )
V_26 = V_24 -> V_28 ;
V_26 -- ;
}
V_24 -> V_30 = V_26 ;
}
static T_8 F_170 ( struct V_121 * V_15 ,
struct V_11 * V_24 )
{
V_6 V_263 = V_342 ;
T_2 V_302 = 0 , V_339 = 0 ;
struct V_13 * V_261 ;
T_2 V_2 = 0 ;
T_2 V_16 = 0 ;
T_7 V_190 ;
T_2 V_1 = 0 ;
T_5 V_262 = 0 ;
int V_366 , V_28 ;
F_24 ( V_15 -> V_294 ) ;
F_21 ( V_367 , V_15 , V_24 ) ;
V_28 = F_171 ( V_15 ) ;
if ( F_172 ( V_15 , V_28 ) ) {
if ( F_173 ( V_15 ) ) {
F_5 ( V_15 ) ;
return V_368 ;
}
V_28 = F_174 ( V_15 -> V_19 ) ;
V_24 -> V_67 . V_369 ++ ;
}
if ( F_167 ( V_24 , V_28 + 4 + 1 ) ) {
V_24 -> V_67 . V_370 ++ ;
return V_371 ;
}
V_261 = & V_24 -> V_27 [ V_24 -> V_30 ] ;
V_261 -> V_15 = V_15 ;
V_261 -> V_50 = V_15 -> V_19 ;
V_261 -> V_51 = 1 ;
if ( F_134 ( V_15 , V_24 , & V_16 ) )
goto V_372;
V_190 = F_135 ( V_15 ) ;
if ( V_190 == F_70 ( V_373 ) )
V_16 |= V_311 ;
else if ( V_190 == F_70 ( V_374 ) )
V_16 |= V_315 ;
V_366 = F_140 ( V_261 , & V_262 , & V_263 ) ;
if ( V_366 < 0 )
goto V_372;
else if ( V_366 )
V_16 |= V_312 ;
V_366 = F_149 ( V_15 , & V_16 , & V_1 , & V_2 ,
V_24 , & V_302 ) ;
if ( V_366 < 0 )
goto V_372;
F_175 ( V_15 ) ;
V_1 |= V_375 ;
F_152 ( V_24 , V_263 ,
V_302 , V_339 ) ;
F_161 ( V_24 , V_15 , V_261 , V_16 , V_262 ,
V_1 , V_2 ) ;
return V_368 ;
V_372:
F_21 ( V_376 , V_261 -> V_15 , V_24 ) ;
F_5 ( V_261 -> V_15 ) ;
V_261 -> V_15 = NULL ;
return V_368 ;
}
T_8 F_176 ( struct V_121 * V_15 , struct V_377 * V_32 )
{
struct V_223 * V_224 = F_177 ( V_32 ) ;
struct V_11 * V_24 = & V_224 -> V_227 [ V_15 -> V_378 ] ;
if ( F_23 ( V_15 -> V_19 < V_379 ) ) {
if ( F_178 ( V_15 , V_379 - V_15 -> V_19 ) )
return V_368 ;
V_15 -> V_19 = V_379 ;
F_179 ( V_15 , V_379 ) ;
}
return F_170 ( V_15 , V_24 ) ;
}
