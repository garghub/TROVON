static int T_1 F_1 ( void )
{
F_2 ( L_1 , V_1 , V_2 ) ;
F_2 ( L_2 , V_3 ) ;
V_4 = F_3 ( L_3 ) ;
F_4 () ;
return F_5 () ;
}
static void T_2 F_6 ( void )
{
F_7 () ;
F_8 () ;
F_9 ( V_4 ) ;
F_10 ( V_4 ) ;
}
static bool F_11 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_9 = V_8 -> V_9 ;
T_3 V_10 ;
if ( F_12 ( V_9 ) )
return true ;
V_9 = F_13 () ;
if ( F_14 ( ! V_9 ) ) {
V_6 -> V_11 . V_12 ++ ;
return false ;
}
V_10 = F_15 ( V_6 -> V_13 , V_9 , 0 , V_14 , V_15 ) ;
if ( F_16 ( V_6 -> V_13 , V_10 ) ) {
F_17 ( V_9 ) ;
V_6 -> V_11 . V_12 ++ ;
return false ;
}
V_8 -> V_10 = V_10 ;
V_8 -> V_9 = V_9 ;
V_8 -> V_16 = 0 ;
return true ;
}
void F_18 ( struct V_5 * V_6 , T_4 V_17 )
{
union V_18 * V_19 ;
struct V_7 * V_8 ;
T_4 V_20 = V_6 -> V_21 ;
if ( ! V_17 )
return;
V_19 = F_19 ( V_6 , V_20 ) ;
V_8 = & V_6 -> V_22 [ V_20 ] ;
V_20 -= V_6 -> V_23 ;
do {
if ( ! F_11 ( V_6 , V_8 ) )
break;
V_19 -> V_24 . V_25 = F_20 ( V_8 -> V_10 + V_8 -> V_16 ) ;
V_19 ++ ;
V_8 ++ ;
V_20 ++ ;
if ( F_14 ( ! V_20 ) ) {
V_19 = F_19 ( V_6 , 0 ) ;
V_8 = V_6 -> V_22 ;
V_20 -= V_6 -> V_23 ;
}
V_19 -> V_26 . V_27 = 0 ;
V_17 -- ;
} while ( V_17 );
V_20 += V_6 -> V_23 ;
if ( V_6 -> V_21 != V_20 ) {
V_6 -> V_21 = V_20 ;
V_6 -> V_28 = V_20 ;
F_21 () ;
F_22 ( V_20 , V_6 -> V_29 ) ;
}
}
static void F_23 ( struct V_5 * V_6 ,
struct V_7 * V_30 )
{
struct V_7 * V_31 ;
T_4 V_32 = V_6 -> V_28 ;
V_31 = & V_6 -> V_22 [ V_32 ] ;
V_32 ++ ;
V_6 -> V_28 = ( V_32 < V_6 -> V_23 ) ? V_32 : 0 ;
* V_31 = * V_30 ;
F_24 ( V_6 -> V_13 , V_30 -> V_10 ,
V_30 -> V_16 ,
V_33 ,
V_15 ) ;
}
static inline bool F_25 ( struct V_9 * V_9 )
{
return ( F_26 ( V_9 ) != F_27 () ) || F_28 ( V_9 ) ;
}
static bool F_29 ( struct V_7 * V_22 ,
struct V_9 * V_9 ,
unsigned int T_5 V_34 )
{
if ( F_14 ( F_25 ( V_9 ) ) )
return false ;
#if ( V_14 < 8192 )
if ( F_14 ( F_30 ( V_9 ) != 1 ) )
return false ;
V_22 -> V_16 ^= V_33 ;
#else
V_22 -> V_16 += V_34 ;
if ( V_22 -> V_16 > ( V_14 - V_33 ) )
return false ;
#endif
F_31 ( V_9 ) ;
return true ;
}
static bool F_32 ( struct V_7 * V_22 ,
union V_18 * V_19 ,
struct V_35 * V_36 )
{
struct V_9 * V_9 = V_22 -> V_9 ;
unsigned char * V_37 = F_33 ( V_9 ) + V_22 -> V_16 ;
unsigned int V_38 = F_34 ( V_19 -> V_39 . V_40 ) ;
#if ( V_14 < 8192 )
unsigned int V_34 = V_33 ;
#else
unsigned int V_34 = F_35 ( V_38 ) ;
#endif
unsigned int V_41 ;
if ( F_14 ( F_36 ( V_36 ) ) )
goto V_42;
if ( F_12 ( V_38 <= V_43 ) ) {
memcpy ( F_37 ( V_36 , V_38 ) , V_37 , F_38 ( V_38 , sizeof( long ) ) ) ;
if ( F_12 ( ! F_25 ( V_9 ) ) )
return true ;
F_17 ( V_9 ) ;
return false ;
}
V_41 = F_39 ( V_37 , V_43 ) ;
memcpy ( F_37 ( V_36 , V_41 ) , V_37 , F_38 ( V_41 , sizeof( long ) ) ) ;
V_37 += V_41 ;
V_38 -= V_41 ;
V_42:
F_40 ( V_36 , F_41 ( V_36 ) -> V_44 , V_9 ,
( unsigned long ) V_37 & ~ V_45 , V_38 , V_34 ) ;
return F_29 ( V_22 , V_9 , V_34 ) ;
}
static struct V_35 * F_42 ( struct V_5 * V_6 ,
union V_18 * V_19 ,
struct V_35 * V_36 )
{
struct V_7 * V_22 ;
struct V_9 * V_9 ;
V_22 = & V_6 -> V_22 [ V_6 -> V_46 ] ;
V_9 = V_22 -> V_9 ;
F_43 ( V_9 ) ;
if ( F_12 ( ! V_36 ) ) {
void * V_47 = F_33 ( V_9 ) +
V_22 -> V_16 ;
F_44 ( V_47 ) ;
#if V_48 < 128
F_44 ( V_47 + V_48 ) ;
#endif
V_36 = F_45 ( & V_6 -> V_49 -> V_50 ,
V_43 ) ;
if ( F_14 ( ! V_36 ) ) {
V_6 -> V_11 . V_12 ++ ;
return NULL ;
}
F_43 ( V_36 -> V_51 ) ;
}
F_46 ( V_6 -> V_13 ,
V_22 -> V_10 ,
V_22 -> V_16 ,
V_33 ,
V_15 ) ;
if ( F_32 ( V_22 , V_19 , V_36 ) ) {
F_23 ( V_6 , V_22 ) ;
} else {
F_47 ( V_6 -> V_13 , V_22 -> V_10 ,
V_14 , V_15 ) ;
}
V_22 -> V_9 = NULL ;
return V_36 ;
}
static inline void F_48 ( struct V_5 * V_52 ,
union V_18 * V_19 ,
struct V_35 * V_36 )
{
F_49 ( V_36 ) ;
if ( ! ( V_52 -> V_53 -> V_54 & V_55 ) )
return;
if ( F_50 ( V_19 ,
V_56 |
V_57 |
V_58 |
V_59 ) ) {
V_52 -> V_11 . V_60 ++ ;
return;
}
if ( F_50 ( V_19 , V_61 ) )
V_36 -> V_62 = true ;
else if ( ! F_50 ( V_19 , V_63 ) )
return;
V_36 -> V_64 = V_65 ;
V_52 -> V_11 . V_66 ++ ;
}
static inline void F_51 ( struct V_5 * V_52 ,
union V_18 * V_19 ,
struct V_35 * V_36 )
{
T_4 V_67 ;
if ( ! ( V_52 -> V_53 -> V_54 & V_68 ) )
return;
V_67 = F_34 ( V_19 -> V_39 . V_69 ) & V_70 ;
if ( ! V_67 )
return;
F_52 ( V_36 , F_53 ( V_19 -> V_26 . V_71 ) ,
( V_72 & ( 1ul << V_67 ) ) ?
V_73 : V_74 ) ;
}
static void F_54 ( struct V_5 * V_6 ,
union V_18 * V_19 ,
struct V_35 * V_36 )
{
struct V_75 * V_76 = V_6 -> V_49 -> V_76 ;
F_55 ( V_36 ) -> V_77 = V_19 -> V_24 . V_78 ;
if ( F_14 ( V_76 -> V_79 & V_80 ) )
F_56 ( V_76 , F_57 ( V_36 ) ,
F_58 ( V_19 -> V_24 . V_78 ) ) ;
}
static void F_59 ( struct V_5 * V_6 ,
union V_18 T_5 * V_19 ,
struct V_35 * V_36 )
{
struct V_81 * V_13 = V_6 -> V_53 ;
struct V_82 * V_83 = F_60 ( V_6 -> V_83 ) ;
if ( V_83 ) {
T_4 V_84 = F_34 ( F_55 ( V_36 ) -> V_85 . V_39 . V_86 ) - 1 ;
V_84 -= V_83 -> V_86 ;
if ( V_84 < V_83 -> V_38 && V_83 -> V_87 [ V_84 ] )
V_13 = V_83 -> V_87 [ V_84 ] ;
else
V_83 = NULL ;
}
V_36 -> V_88 = F_61 ( V_36 , V_13 ) ;
if ( ! V_83 )
return;
F_62 ( F_63 ( V_13 ) , V_36 -> V_89 + V_90 , 1 ,
! ! ( V_19 -> V_39 . V_91 &
F_64 ( V_92 ) ) ) ;
}
static unsigned int F_65 ( struct V_5 * V_6 ,
union V_18 * V_19 ,
struct V_35 * V_36 )
{
unsigned int V_89 = V_36 -> V_89 ;
F_51 ( V_6 , V_19 , V_36 ) ;
F_48 ( V_6 , V_19 , V_36 ) ;
F_54 ( V_6 , V_19 , V_36 ) ;
F_55 ( V_36 ) -> V_85 . V_39 . V_93 = V_19 -> V_39 . V_93 ;
F_66 ( V_36 , V_6 -> V_94 ) ;
F_55 ( V_36 ) -> V_85 . V_26 . V_95 = V_19 -> V_26 . V_95 ;
if ( V_19 -> V_39 . V_93 ) {
T_4 V_96 = F_34 ( V_19 -> V_39 . V_93 ) ;
if ( ( V_96 & V_97 ) != V_6 -> V_96 )
F_67 ( V_36 , F_68 ( V_98 ) , V_96 ) ;
else if ( V_96 & V_99 )
F_67 ( V_36 , F_68 ( V_98 ) ,
V_96 & V_99 ) ;
}
F_59 ( V_6 , V_19 , V_36 ) ;
return V_89 ;
}
static bool F_69 ( struct V_5 * V_6 ,
union V_18 * V_19 )
{
T_6 V_100 = V_6 -> V_46 + 1 ;
V_100 = ( V_100 < V_6 -> V_23 ) ? V_100 : 0 ;
V_6 -> V_46 = V_100 ;
F_44 ( F_19 ( V_6 , V_100 ) ) ;
if ( F_12 ( F_50 ( V_19 , V_101 ) ) )
return false ;
return true ;
}
static bool F_70 ( struct V_5 * V_6 ,
union V_18 * V_19 ,
struct V_35 * V_36 )
{
if ( F_14 ( ( F_50 ( V_19 ,
V_102 ) ) ) ) {
#define F_71 ( T_7 , T_8 ) \
((rxd)->w.csum_err & cpu_to_le16(bit))
if ( F_71 ( V_19 , V_103 ) )
V_6 -> V_11 . V_104 ++ ;
if ( F_71 ( V_19 , V_105 ) )
V_6 -> V_11 . V_106 ++ ;
if ( F_71 ( V_19 , V_107 ) )
V_6 -> V_11 . V_108 ++ ;
if ( F_71 ( V_19 , V_109 ) )
V_6 -> V_11 . V_110 ++ ;
if ( F_71 ( V_19 , V_111 ) )
V_6 -> V_11 . V_112 ++ ;
F_72 ( V_36 ) ;
V_6 -> V_11 . V_113 ++ ;
return true ;
}
if ( F_73 ( V_36 ) )
return true ;
return false ;
}
static void F_74 ( struct V_114 * V_49 ,
struct V_35 * V_36 )
{
F_75 ( & V_49 -> V_50 , V_36 ) ;
}
static int F_76 ( struct V_114 * V_49 ,
struct V_5 * V_6 ,
int V_115 )
{
struct V_35 * V_36 = V_6 -> V_36 ;
unsigned int V_116 = 0 , V_117 = 0 ;
T_4 V_17 = F_77 ( V_6 ) ;
while ( F_12 ( V_117 < V_115 ) ) {
union V_18 * V_19 ;
if ( V_17 >= V_118 ) {
F_18 ( V_6 , V_17 ) ;
V_17 = 0 ;
}
V_19 = F_19 ( V_6 , V_6 -> V_46 ) ;
if ( ! V_19 -> V_26 . V_27 )
break;
F_78 () ;
V_36 = F_42 ( V_6 , V_19 , V_36 ) ;
if ( ! V_36 )
break;
V_17 ++ ;
if ( F_69 ( V_6 , V_19 ) )
continue;
if ( F_70 ( V_6 , V_19 , V_36 ) ) {
V_36 = NULL ;
continue;
}
V_116 += F_65 ( V_6 , V_19 , V_36 ) ;
F_74 ( V_49 , V_36 ) ;
V_36 = NULL ;
V_117 ++ ;
}
V_6 -> V_36 = V_36 ;
F_79 ( & V_6 -> V_119 ) ;
V_6 -> V_120 . V_121 += V_117 ;
V_6 -> V_120 . V_122 += V_116 ;
F_80 ( & V_6 -> V_119 ) ;
V_49 -> V_123 . V_117 += V_117 ;
V_49 -> V_123 . V_116 += V_116 ;
return V_117 ;
}
static struct V_124 * F_81 ( struct V_35 * V_36 )
{
struct V_75 * V_76 = F_63 ( V_36 -> V_13 ) ;
struct V_125 * V_126 ;
V_126 = F_82 ( & V_76 -> V_126 ,
struct V_125 , V_127 ) ;
if ( ! V_126 )
return NULL ;
if ( V_126 -> V_128 != F_83 ( V_36 ) -> V_129 )
return NULL ;
return (struct V_124 * ) ( F_84 ( V_36 ) + V_130 ) ;
}
static struct V_124 * F_85 ( struct V_35 * V_36 )
{
struct V_131 * V_132 ;
int V_133 = F_86 ( V_36 ) ;
if ( F_87 ( V_36 ) != F_68 ( V_134 ) )
return NULL ;
V_132 = (struct V_131 * ) ( F_88 ( V_36 ) + V_133 ) ;
if ( V_132 -> V_79 & V_135 )
return NULL ;
if ( V_132 -> V_79 & V_136 )
return (struct V_124 * ) ( V_132 + 1 ) ;
return (struct V_124 * ) ( & V_132 -> V_137 ) ;
}
T_9 F_89 ( struct V_35 * V_36 )
{
T_10 V_138 = 0 , V_139 = 0 , V_140 ;
struct V_124 * V_141 ;
if ( V_36 -> V_142 != V_143 ||
V_36 -> V_144 != F_68 ( V_145 ) )
return 0 ;
switch ( F_87 ( V_36 ) ) {
case F_68 ( V_134 ) :
V_138 = F_90 ( V_36 ) -> V_88 ;
break;
case F_68 ( V_146 ) :
V_138 = F_91 ( V_36 ) -> V_147 ;
break;
default:
return 0 ;
}
switch ( V_138 ) {
case V_148 :
V_141 = F_81 ( V_36 ) ;
break;
case V_149 :
V_141 = F_85 ( V_36 ) ;
break;
default:
return 0 ;
}
if ( ! V_141 )
return 0 ;
switch ( V_141 -> V_150 ) {
case F_68 ( V_134 ) :
V_139 = F_92 ( V_36 ) -> V_88 ;
break;
case F_68 ( V_146 ) :
V_139 = F_93 ( V_36 ) -> V_147 ;
break;
default:
return 0 ;
}
switch ( V_139 ) {
case V_151 :
V_140 = F_94 ( V_36 ) ;
break;
case V_148 :
V_140 = 8 ;
break;
default:
return 0 ;
}
if ( F_95 ( V_36 ) + V_140 -
F_96 ( V_36 ) > V_152 )
return 0 ;
return V_141 -> V_150 ;
}
static int F_97 ( struct V_5 * V_153 ,
struct V_154 * V_155 )
{
struct V_35 * V_36 = V_155 -> V_36 ;
struct V_156 * V_157 ;
unsigned char * V_158 ;
T_10 V_159 ;
if ( V_36 -> V_64 != V_160 )
return 0 ;
if ( ! F_98 ( V_36 ) )
return 0 ;
if ( V_36 -> V_62 ) {
if ( ! F_89 ( V_36 ) )
goto V_161;
V_158 = F_95 ( V_36 ) ;
} else {
V_158 = F_84 ( V_36 ) ;
}
V_159 = ( V_158 - V_36 -> V_51 ) + ( ( (struct V_162 * ) V_158 ) -> V_163 << 2 ) ;
V_155 -> V_164 |= V_165 ;
V_155 -> V_166 = F_41 ( V_36 ) -> V_166 ;
V_155 -> V_167 += ( V_155 -> V_166 - 1 ) * V_159 ;
V_157 = F_99 ( V_153 , V_153 -> V_21 ) ;
V_157 -> V_159 = V_159 ;
V_157 -> V_168 = F_64 ( F_41 ( V_36 ) -> V_169 ) ;
return 1 ;
V_161:
V_153 -> V_53 -> V_54 &= ~ V_170 ;
if ( ! F_100 () )
F_101 ( V_153 -> V_53 ,
L_4 ) ;
return - 1 ;
}
static void F_102 ( struct V_5 * V_153 ,
struct V_154 * V_155 )
{
struct V_35 * V_36 = V_155 -> V_36 ;
struct V_156 * V_157 ;
union {
struct V_171 * V_172 ;
struct V_173 * V_174 ;
T_10 * V_175 ;
} V_176 ;
T_9 V_88 ;
T_10 V_138 = 0 ;
if ( V_36 -> V_64 != V_160 )
goto V_177;
if ( V_36 -> V_62 ) {
V_88 = F_89 ( V_36 ) ;
if ( ! V_88 ) {
if ( F_103 ( V_36 ) ) {
F_104 ( V_153 -> V_13 ,
L_5 ) ;
V_153 -> V_178 . V_60 ++ ;
}
goto V_177;
}
V_176 . V_175 = F_105 ( V_36 ) ;
} else {
V_88 = F_87 ( V_36 ) ;
V_176 . V_175 = F_88 ( V_36 ) ;
}
switch ( V_88 ) {
case F_68 ( V_134 ) :
V_138 = V_176 . V_172 -> V_88 ;
break;
case F_68 ( V_146 ) :
V_138 = V_176 . V_174 -> V_147 ;
break;
default:
if ( F_14 ( F_100 () ) ) {
F_104 ( V_153 -> V_13 ,
L_6 ,
V_88 ) ;
}
V_153 -> V_178 . V_60 ++ ;
goto V_177;
}
switch ( V_138 ) {
case V_151 :
case V_148 :
break;
case V_149 :
if ( V_36 -> V_62 )
break;
default:
if ( F_14 ( F_100 () ) ) {
F_104 ( V_153 -> V_13 ,
L_7 ,
V_138 ) ;
}
V_153 -> V_178 . V_60 ++ ;
goto V_177;
}
V_155 -> V_164 |= V_165 ;
V_153 -> V_178 . V_66 ++ ;
V_177:
V_157 = F_99 ( V_153 , V_153 -> V_21 ) ;
V_157 -> V_159 = 0 ;
V_157 -> V_168 = 0 ;
}
static T_10 F_106 ( struct V_35 * V_36 , T_6 V_164 )
{
T_6 V_179 = 0 ;
if ( F_14 ( F_41 ( V_36 ) -> V_164 & V_180 ) &&
F_12 ( F_41 ( V_36 ) -> V_164 & V_181 ) )
V_179 |= V_182 ;
V_179 |= F_107 ( V_164 , V_165 ,
V_183 ) ;
return V_179 ;
}
static bool F_108 ( struct V_5 * V_153 ,
struct V_156 * V_157 , T_4 V_20 ,
T_3 V_10 , unsigned int V_38 , T_10 V_179 )
{
if ( ( ++ V_20 & ( V_184 - 1 ) ) == 0 )
V_179 |= V_185 | V_186 ;
V_157 -> V_187 = F_20 ( V_10 ) ;
V_157 -> V_79 = V_179 ;
V_157 -> V_188 = F_64 ( V_38 ) ;
return V_20 == V_153 -> V_23 ;
}
static int F_109 ( struct V_5 * V_153 , T_4 V_38 )
{
F_110 ( V_153 -> V_53 , V_153 -> V_94 ) ;
F_111 () ;
if ( F_12 ( F_77 ( V_153 ) < V_38 ) )
return - V_189 ;
F_112 ( V_153 -> V_53 , V_153 -> V_94 ) ;
++ V_153 -> V_178 . V_190 ;
return 0 ;
}
static inline int F_113 ( struct V_5 * V_153 , T_4 V_38 )
{
if ( F_12 ( F_77 ( V_153 ) >= V_38 ) )
return 0 ;
return F_109 ( V_153 , V_38 ) ;
}
static void F_114 ( struct V_5 * V_153 ,
struct V_154 * V_155 )
{
struct V_35 * V_36 = V_155 -> V_36 ;
struct V_154 * V_191 ;
struct V_156 * V_157 ;
struct V_192 * V_193 ;
unsigned char * V_51 ;
T_3 V_10 ;
unsigned int V_194 , V_38 ;
T_6 V_164 = V_155 -> V_164 ;
T_4 V_20 = V_153 -> V_21 ;
T_10 V_79 = F_106 ( V_36 , V_164 ) ;
V_157 = F_99 ( V_153 , V_20 ) ;
if ( F_115 ( V_36 ) )
V_157 -> V_93 = F_64 ( F_116 ( V_36 ) ) ;
else
V_157 -> V_93 = 0 ;
V_38 = F_117 ( V_36 ) ;
V_51 = V_36 -> V_51 ;
V_10 = F_118 ( V_153 -> V_13 , V_51 , V_38 , V_195 ) ;
V_194 = V_36 -> V_194 ;
V_191 = V_155 ;
for ( V_193 = & F_41 ( V_36 ) -> V_196 [ 0 ] ; ; V_193 ++ ) {
if ( F_16 ( V_153 -> V_13 , V_10 ) )
goto V_197;
F_119 ( V_191 , V_89 , V_38 ) ;
F_120 ( V_191 , V_10 , V_10 ) ;
while ( F_14 ( V_38 > V_198 ) ) {
if ( F_108 ( V_153 , V_157 ++ , V_20 ++ , V_10 ,
V_198 , V_79 ) ) {
V_157 = F_99 ( V_153 , 0 ) ;
V_20 = 0 ;
}
V_10 += V_198 ;
V_38 -= V_198 ;
}
if ( F_12 ( ! V_194 ) )
break;
if ( F_108 ( V_153 , V_157 ++ , V_20 ++ ,
V_10 , V_38 , V_79 ) ) {
V_157 = F_99 ( V_153 , 0 ) ;
V_20 = 0 ;
}
V_38 = F_121 ( V_193 ) ;
V_194 -= V_38 ;
V_10 = F_122 ( V_153 -> V_13 , V_193 , 0 , V_38 ,
V_195 ) ;
V_191 = & V_153 -> V_191 [ V_20 ] ;
}
V_79 |= V_199 ;
if ( F_108 ( V_153 , V_157 , V_20 ++ , V_10 , V_38 , V_79 ) )
V_20 = 0 ;
F_123 ( F_124 ( V_153 ) , V_155 -> V_167 ) ;
F_125 ( V_155 -> V_36 ) ;
F_21 () ;
V_155 -> V_200 = V_157 ;
V_153 -> V_21 = V_20 ;
F_113 ( V_153 , V_201 ) ;
if ( F_126 ( F_124 ( V_153 ) ) || ! V_36 -> V_202 ) {
F_22 ( V_20 , V_153 -> V_29 ) ;
F_127 () ;
}
return;
V_197:
F_128 ( V_153 -> V_13 , L_8 ) ;
for (; ; ) {
V_191 = & V_153 -> V_191 [ V_20 ] ;
F_129 ( V_153 , V_191 ) ;
if ( V_191 == V_155 )
break;
if ( V_20 == 0 )
V_20 = V_153 -> V_23 ;
V_20 -- ;
}
V_153 -> V_21 = V_20 ;
}
T_11 F_130 ( struct V_35 * V_36 ,
struct V_5 * V_153 )
{
T_4 V_23 = F_131 ( F_117 ( V_36 ) ) ;
struct V_154 * V_155 ;
unsigned short V_203 ;
T_6 V_164 = 0 ;
int V_204 ;
for ( V_203 = 0 ; V_203 < F_41 ( V_36 ) -> V_44 ; V_203 ++ )
V_23 += F_131 ( F_41 ( V_36 ) -> V_196 [ V_203 ] . V_38 ) ;
if ( F_113 ( V_153 , V_23 + 3 ) ) {
V_153 -> V_178 . V_205 ++ ;
return V_206 ;
}
V_155 = & V_153 -> V_191 [ V_153 -> V_21 ] ;
V_155 -> V_36 = V_36 ;
V_155 -> V_167 = F_132 (unsigned int, skb->len, ETH_ZLEN) ;
V_155 -> V_166 = 1 ;
V_155 -> V_164 = V_164 ;
V_204 = F_97 ( V_153 , V_155 ) ;
if ( V_204 < 0 )
goto V_207;
else if ( ! V_204 )
F_102 ( V_153 , V_155 ) ;
F_114 ( V_153 , V_155 ) ;
return V_208 ;
V_207:
F_72 ( V_155 -> V_36 ) ;
V_155 -> V_36 = NULL ;
return V_208 ;
}
static T_12 F_133 ( struct V_5 * V_52 )
{
return V_52 -> V_120 . V_121 ;
}
static T_12 F_134 ( struct V_5 * V_52 )
{
T_6 V_209 = V_52 -> V_46 ;
T_6 V_29 = V_52 -> V_21 ;
return ( ( V_209 <= V_29 ) ? V_29 : V_29 + V_52 -> V_23 ) - V_209 ;
}
bool F_135 ( struct V_5 * V_153 )
{
T_6 V_210 = F_133 ( V_153 ) ;
T_6 V_211 = V_153 -> V_178 . V_211 ;
T_6 V_212 = F_134 ( V_153 ) ;
F_136 ( V_153 ) ;
if ( ! V_212 || ( V_211 != V_210 ) ) {
V_153 -> V_178 . V_211 = V_210 ;
F_137 ( V_213 , & V_153 -> V_214 ) ;
return false ;
}
return F_138 ( V_213 , & V_153 -> V_214 ) ;
}
void F_139 ( struct V_75 * V_76 )
{
if ( ! F_140 ( V_215 , & V_76 -> V_214 ) ) {
V_76 -> V_216 ++ ;
V_76 -> V_79 |= V_217 ;
F_141 ( V_76 ) ;
}
}
static bool F_142 ( struct V_114 * V_49 ,
struct V_5 * V_153 )
{
struct V_75 * V_76 = V_49 -> V_76 ;
struct V_154 * V_191 ;
struct V_156 * V_157 ;
unsigned int V_116 = 0 , V_117 = 0 ;
unsigned int V_115 = V_49 -> V_218 . V_219 ;
unsigned int V_20 = V_153 -> V_46 ;
if ( F_140 ( V_215 , & V_76 -> V_214 ) )
return true ;
V_191 = & V_153 -> V_191 [ V_20 ] ;
V_157 = F_99 ( V_153 , V_20 ) ;
V_20 -= V_153 -> V_23 ;
do {
struct V_156 * V_220 = V_191 -> V_200 ;
if ( ! V_220 )
break;
F_143 () ;
if ( ! ( V_220 -> V_79 & V_221 ) )
break;
V_191 -> V_200 = NULL ;
V_116 += V_191 -> V_167 ;
V_117 += V_191 -> V_166 ;
F_144 ( V_191 -> V_36 ) ;
F_145 ( V_153 -> V_13 ,
F_146 ( V_191 , V_10 ) ,
F_147 ( V_191 , V_89 ) ,
V_195 ) ;
V_191 -> V_36 = NULL ;
F_119 ( V_191 , V_89 , 0 ) ;
while ( V_157 != V_220 ) {
V_191 ++ ;
V_157 ++ ;
V_20 ++ ;
if ( F_14 ( ! V_20 ) ) {
V_20 -= V_153 -> V_23 ;
V_191 = V_153 -> V_191 ;
V_157 = F_99 ( V_153 , 0 ) ;
}
if ( F_147 ( V_191 , V_89 ) ) {
F_47 ( V_153 -> V_13 ,
F_146 ( V_191 , V_10 ) ,
F_147 ( V_191 , V_89 ) ,
V_195 ) ;
F_119 ( V_191 , V_89 , 0 ) ;
}
}
V_191 ++ ;
V_157 ++ ;
V_20 ++ ;
if ( F_14 ( ! V_20 ) ) {
V_20 -= V_153 -> V_23 ;
V_191 = V_153 -> V_191 ;
V_157 = F_99 ( V_153 , 0 ) ;
}
F_44 ( V_157 ) ;
V_115 -- ;
} while ( F_12 ( V_115 ) );
V_20 += V_153 -> V_23 ;
V_153 -> V_46 = V_20 ;
F_79 ( & V_153 -> V_119 ) ;
V_153 -> V_120 . V_122 += V_116 ;
V_153 -> V_120 . V_121 += V_117 ;
F_80 ( & V_153 -> V_119 ) ;
V_49 -> V_218 . V_116 += V_116 ;
V_49 -> V_218 . V_117 += V_117 ;
if ( F_148 ( V_153 ) && F_135 ( V_153 ) ) {
struct V_222 * V_223 = & V_76 -> V_223 ;
F_149 ( V_76 , V_224 , V_153 -> V_53 ,
L_9
L_10
L_11
L_12
L_13 ,
V_153 -> V_94 ,
F_150 ( V_223 , F_151 ( V_153 -> V_225 ) ) ,
F_150 ( V_223 , F_152 ( V_153 -> V_225 ) ) ,
V_153 -> V_21 , V_20 ) ;
F_110 ( V_153 -> V_53 ,
V_153 -> V_94 ) ;
F_153 ( V_76 , V_226 , V_153 -> V_53 ,
L_14 ,
V_76 -> V_216 + 1 ,
V_153 -> V_94 ) ;
F_139 ( V_76 ) ;
return true ;
}
F_154 ( F_124 ( V_153 ) ,
V_117 , V_116 ) ;
#define F_155 min_t(u16, FM10K_MIN_TXD - 1, DESC_NEEDED * 2)
if ( F_14 ( V_117 && F_156 ( V_153 -> V_53 ) &&
( F_77 ( V_153 ) >= F_155 ) ) ) {
F_111 () ;
if ( F_157 ( V_153 -> V_53 ,
V_153 -> V_94 ) &&
! F_140 ( V_215 , & V_76 -> V_214 ) ) {
F_158 ( V_153 -> V_53 ,
V_153 -> V_94 ) ;
++ V_153 -> V_178 . V_190 ;
}
}
return ! ! V_115 ;
}
static void F_159 ( struct V_227 * V_228 )
{
unsigned int V_229 , V_121 , V_230 ;
if ( ! F_160 ( V_228 -> V_231 ) )
goto V_232;
V_121 = V_228 -> V_117 ;
if ( ! V_121 )
goto V_232;
V_229 = V_228 -> V_116 / V_121 ;
if ( V_229 <= 360 ) {
V_229 *= 8 ;
V_229 += 376 ;
} else if ( V_229 <= 1152 ) {
V_229 *= 3 ;
V_229 += 2176 ;
} else if ( V_229 <= 1920 ) {
V_229 += 4480 ;
} else {
V_229 = 6656 ;
}
V_230 = F_161 ( V_228 -> V_233 ) + 8 ;
V_229 += ( 1 << V_230 ) - 1 ;
V_229 >>= V_230 ;
V_228 -> V_231 = V_229 | V_234 ;
V_232:
V_228 -> V_116 = 0 ;
V_228 -> V_117 = 0 ;
}
static void F_162 ( struct V_114 * V_49 )
{
T_6 V_231 = V_235 ;
F_159 ( & V_49 -> V_218 ) ;
F_159 ( & V_49 -> V_123 ) ;
V_231 |= ( V_49 -> V_218 . V_231 & V_236 ) ;
V_231 |= ( V_49 -> V_123 . V_231 & V_236 ) << V_237 ;
F_22 ( V_231 , V_49 -> V_231 ) ;
}
static int F_163 ( struct V_238 * V_50 , int V_115 )
{
struct V_114 * V_49 =
F_164 ( V_50 , struct V_114 , V_50 ) ;
struct V_5 * V_52 ;
int V_239 , V_240 = 0 ;
bool V_241 = true ;
F_165 (ring, q_vector->tx)
V_241 &= F_142 ( V_49 , V_52 ) ;
if ( V_115 <= 0 )
return V_115 ;
if ( V_49 -> V_123 . V_23 > 1 )
V_239 = F_166 ( V_115 / V_49 -> V_123 . V_23 , 1 ) ;
else
V_239 = V_115 ;
F_165 (ring, q_vector->rx) {
int V_242 = F_76 ( V_49 , V_52 , V_239 ) ;
V_240 += V_242 ;
V_241 &= ! ! ( V_242 < V_239 ) ;
}
if ( ! V_241 )
return V_115 ;
F_167 ( V_50 , V_240 ) ;
F_162 ( V_49 ) ;
return 0 ;
}
static bool F_168 ( struct V_75 * V_76 )
{
struct V_81 * V_13 = V_76 -> V_53 ;
struct V_243 * V_203 ;
int V_244 , V_20 ;
int V_245 ;
V_245 = F_169 ( V_13 ) ;
if ( V_245 <= 1 )
return false ;
V_203 = & V_76 -> V_246 [ V_247 ] ;
V_203 -> V_248 = V_245 ;
V_203 -> V_249 = ( 1 << F_170 ( V_245 - 1 ) ) - 1 ;
V_244 = V_76 -> V_223 . V_250 . V_251 / V_245 ;
V_244 = 1 << ( F_170 ( V_244 ) - 1 ) ;
V_203 = & V_76 -> V_246 [ V_252 ] ;
V_244 = F_171 ( T_4 , V_244 , V_203 -> V_253 ) ;
V_203 -> V_248 = V_244 ;
V_203 -> V_249 = ( 1 << F_170 ( V_244 - 1 ) ) - 1 ;
for ( V_20 = 0 ; V_20 < V_245 ; V_20 ++ )
F_172 ( V_13 , V_20 , V_244 , V_244 * V_20 ) ;
V_76 -> V_254 = V_244 * V_245 ;
V_76 -> V_255 = V_244 * V_245 ;
return true ;
}
static bool F_173 ( struct V_75 * V_76 )
{
struct V_243 * V_203 ;
T_4 V_244 ;
V_203 = & V_76 -> V_246 [ V_252 ] ;
V_244 = F_171 ( T_4 , V_76 -> V_223 . V_250 . V_251 , V_203 -> V_253 ) ;
V_203 -> V_248 = V_244 ;
V_203 -> V_249 = ( 1 << F_170 ( V_244 - 1 ) ) - 1 ;
V_76 -> V_254 = V_244 ;
V_76 -> V_255 = V_244 ;
return true ;
}
static void F_174 ( struct V_75 * V_76 )
{
V_76 -> V_254 = 1 ;
V_76 -> V_255 = 1 ;
if ( F_168 ( V_76 ) )
return;
F_173 ( V_76 ) ;
}
static int F_175 ( struct V_75 * V_76 ,
unsigned int V_256 , unsigned int V_257 ,
unsigned int V_258 , unsigned int V_259 ,
unsigned int V_260 , unsigned int V_261 )
{
struct V_114 * V_49 ;
struct V_5 * V_52 ;
int V_262 , V_38 ;
V_262 = V_258 + V_260 ;
V_38 = sizeof( struct V_114 ) +
( sizeof( struct V_5 ) * V_262 ) ;
V_49 = F_176 ( V_38 , V_263 ) ;
if ( ! V_49 )
return - V_264 ;
F_177 ( V_76 -> V_53 , & V_49 -> V_50 ,
F_163 , V_265 ) ;
V_76 -> V_49 [ V_257 ] = V_49 ;
V_49 -> V_76 = V_76 ;
V_49 -> V_257 = V_257 ;
V_52 = V_49 -> V_52 ;
V_49 -> V_218 . V_52 = V_52 ;
V_49 -> V_218 . V_219 = V_266 ;
V_49 -> V_218 . V_231 = V_76 -> V_267 ;
V_49 -> V_218 . V_233 = V_76 -> V_223 . V_250 . V_233 ;
V_49 -> V_218 . V_23 = V_258 ;
while ( V_258 ) {
V_52 -> V_13 = & V_76 -> V_268 -> V_13 ;
V_52 -> V_53 = V_76 -> V_53 ;
V_52 -> V_49 = V_49 ;
V_52 -> V_23 = V_76 -> V_269 ;
V_52 -> V_94 = V_259 ;
V_76 -> V_153 [ V_259 ] = V_52 ;
V_258 -- ;
V_259 += V_256 ;
V_52 ++ ;
}
V_49 -> V_123 . V_52 = V_52 ;
V_49 -> V_123 . V_231 = V_76 -> V_270 ;
V_49 -> V_123 . V_233 = V_76 -> V_223 . V_250 . V_233 ;
V_49 -> V_123 . V_23 = V_260 ;
while ( V_260 ) {
V_52 -> V_13 = & V_76 -> V_268 -> V_13 ;
V_52 -> V_53 = V_76 -> V_53 ;
F_178 ( V_52 -> V_83 , V_76 -> V_83 ) ;
V_52 -> V_49 = V_49 ;
V_52 -> V_23 = V_76 -> V_271 ;
V_52 -> V_94 = V_261 ;
V_76 -> V_6 [ V_261 ] = V_52 ;
V_260 -- ;
V_261 += V_256 ;
V_52 ++ ;
}
F_179 ( V_49 ) ;
return 0 ;
}
static void F_180 ( struct V_75 * V_76 , int V_257 )
{
struct V_114 * V_49 = V_76 -> V_49 [ V_257 ] ;
struct V_5 * V_52 ;
F_181 ( V_49 ) ;
F_165 (ring, q_vector->tx)
V_76 -> V_153 [ V_52 -> V_94 ] = NULL ;
F_165 (ring, q_vector->rx)
V_76 -> V_6 [ V_52 -> V_94 ] = NULL ;
V_76 -> V_49 [ V_257 ] = NULL ;
F_182 ( & V_49 -> V_50 ) ;
F_183 ( V_49 , V_272 ) ;
}
static int F_184 ( struct V_75 * V_76 )
{
unsigned int V_273 = V_76 -> V_274 ;
unsigned int V_275 = V_76 -> V_254 ;
unsigned int V_276 = V_76 -> V_255 ;
unsigned int V_261 = 0 , V_259 = 0 , V_257 = 0 ;
int V_277 ;
if ( V_273 >= ( V_275 + V_276 ) ) {
for (; V_275 ; V_257 ++ ) {
V_277 = F_175 ( V_76 , V_273 , V_257 ,
0 , 0 , 1 , V_261 ) ;
if ( V_277 )
goto V_278;
V_275 -- ;
V_261 ++ ;
}
}
for (; V_257 < V_273 ; V_257 ++ ) {
int V_279 = F_185 ( V_275 , V_273 - V_257 ) ;
int V_280 = F_185 ( V_276 , V_273 - V_257 ) ;
V_277 = F_175 ( V_76 , V_273 , V_257 ,
V_280 , V_259 ,
V_279 , V_261 ) ;
if ( V_277 )
goto V_278;
V_275 -= V_279 ;
V_276 -= V_280 ;
V_261 ++ ;
V_259 ++ ;
}
return 0 ;
V_278:
V_76 -> V_255 = 0 ;
V_76 -> V_254 = 0 ;
V_76 -> V_274 = 0 ;
while ( V_257 -- )
F_180 ( V_76 , V_257 ) ;
return - V_264 ;
}
static void F_186 ( struct V_75 * V_76 )
{
int V_257 = V_76 -> V_274 ;
V_76 -> V_255 = 0 ;
V_76 -> V_254 = 0 ;
V_76 -> V_274 = 0 ;
while ( V_257 -- )
F_180 ( V_76 , V_257 ) ;
}
static void F_187 ( struct V_75 * V_76 )
{
F_188 ( V_76 -> V_268 ) ;
F_189 ( V_76 -> V_281 ) ;
V_76 -> V_281 = NULL ;
}
static int F_190 ( struct V_75 * V_76 )
{
struct V_222 * V_223 = & V_76 -> V_223 ;
int V_282 , V_283 ;
V_282 = F_166 ( V_76 -> V_254 , V_76 -> V_255 ) ;
V_282 = F_171 ( T_4 , V_282 , F_191 () ) ;
V_282 += F_192 ( V_223 ) ;
V_282 = F_171 ( int , V_282 , V_223 -> V_250 . V_284 ) ;
V_76 -> V_281 = F_193 ( V_282 , sizeof( struct V_285 ) ,
V_263 ) ;
if ( ! V_76 -> V_281 )
return - V_264 ;
for ( V_283 = 0 ; V_283 < V_282 ; V_283 ++ )
V_76 -> V_281 [ V_283 ] . V_286 = V_283 ;
V_282 = F_194 ( V_76 -> V_268 ,
V_76 -> V_281 ,
F_195 ( V_223 ) ,
V_282 ) ;
if ( V_282 < 0 ) {
F_189 ( V_76 -> V_281 ) ;
V_76 -> V_281 = NULL ;
return - V_264 ;
}
V_76 -> V_274 = V_282 - F_192 ( V_223 ) ;
return 0 ;
}
static bool F_196 ( struct V_75 * V_76 )
{
struct V_81 * V_13 = V_76 -> V_53 ;
int V_287 , V_288 , V_244 , V_20 , V_289 ;
T_4 V_290 = V_76 -> V_246 [ V_247 ] . V_249 + 1 ;
T_10 V_291 = F_169 ( V_13 ) ;
if ( V_291 <= 1 )
return false ;
V_244 = V_76 -> V_246 [ V_252 ] . V_248 ;
for ( V_287 = 0 , V_288 = 0 ; V_287 < V_291 ; V_287 ++ , V_288 += V_244 ) {
V_289 = V_287 ;
for ( V_20 = 0 ; V_20 < V_244 ; V_20 ++ ) {
V_76 -> V_153 [ V_288 + V_20 ] -> V_225 = V_289 ;
V_76 -> V_153 [ V_288 + V_20 ] -> V_292 = V_287 ;
V_76 -> V_6 [ V_288 + V_20 ] -> V_225 = V_289 ;
V_76 -> V_6 [ V_288 + V_20 ] -> V_292 = V_287 ;
V_289 += V_290 ;
}
}
return true ;
}
static void F_197 ( struct V_75 * V_76 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_76 -> V_254 ; V_20 ++ )
V_76 -> V_6 [ V_20 ] -> V_225 = V_20 ;
for ( V_20 = 0 ; V_20 < V_76 -> V_255 ; V_20 ++ )
V_76 -> V_153 [ V_20 ] -> V_225 = V_20 ;
}
static void F_198 ( struct V_75 * V_76 )
{
if ( F_196 ( V_76 ) )
return;
F_197 ( V_76 ) ;
}
static void F_199 ( struct V_75 * V_76 )
{
T_4 V_20 , V_244 = V_76 -> V_246 [ V_252 ] . V_248 ;
T_6 V_293 , V_294 ;
if ( F_200 ( V_76 -> V_53 ) ) {
for ( V_20 = V_295 ; V_20 -- ; ) {
V_293 = V_76 -> V_293 [ V_20 ] ;
if ( ( ( ( V_293 << 24 ) >> 24 ) < V_244 ) &&
( ( ( V_293 << 16 ) >> 24 ) < V_244 ) &&
( ( ( V_293 << 8 ) >> 24 ) < V_244 ) &&
( ( ( V_293 ) >> 24 ) < V_244 ) )
continue;
F_128 ( & V_76 -> V_268 -> V_13 ,
L_15 ) ;
goto V_296;
}
return;
}
V_296:
for ( V_20 = V_295 ; V_20 -- ; ) {
V_294 = ( ( V_20 * 0x00040004 ) + 0x00020000 ) * V_244 ;
V_293 = ( V_294 & 0x3F803F80 ) >> 7 ;
V_294 += 0x00010001 * V_244 ;
V_293 |= ( V_294 & 0x3F803F80 ) << 1 ;
V_76 -> V_293 [ V_20 ] = V_293 ;
}
}
int F_201 ( struct V_75 * V_76 )
{
int V_277 ;
F_174 ( V_76 ) ;
V_277 = F_190 ( V_76 ) ;
if ( V_277 ) {
F_128 ( & V_76 -> V_268 -> V_13 ,
L_16 ) ;
return V_277 ;
}
V_277 = F_184 ( V_76 ) ;
if ( V_277 ) {
F_187 ( V_76 ) ;
return V_277 ;
}
F_198 ( V_76 ) ;
F_199 ( V_76 ) ;
return 0 ;
}
void F_202 ( struct V_75 * V_76 )
{
F_186 ( V_76 ) ;
F_187 ( V_76 ) ;
}
