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
F_31 ( & V_9 -> V_35 ) ;
return true ;
}
static bool F_32 ( struct V_7 * V_22 ,
union V_18 * V_19 ,
struct V_36 * V_37 )
{
struct V_9 * V_9 = V_22 -> V_9 ;
unsigned char * V_38 = F_33 ( V_9 ) + V_22 -> V_16 ;
unsigned int V_39 = F_34 ( V_19 -> V_40 . V_41 ) ;
#if ( V_14 < 8192 )
unsigned int V_34 = V_33 ;
#else
unsigned int V_34 = F_35 ( V_39 ) ;
#endif
unsigned int V_42 ;
if ( F_14 ( F_36 ( V_37 ) ) )
goto V_43;
if ( F_12 ( V_39 <= V_44 ) ) {
memcpy ( F_37 ( V_37 , V_39 ) , V_38 , F_38 ( V_39 , sizeof( long ) ) ) ;
if ( F_12 ( ! F_25 ( V_9 ) ) )
return true ;
F_17 ( V_9 ) ;
return false ;
}
V_42 = F_39 ( V_38 , V_44 ) ;
memcpy ( F_37 ( V_37 , V_42 ) , V_38 , F_38 ( V_42 , sizeof( long ) ) ) ;
V_38 += V_42 ;
V_39 -= V_42 ;
V_43:
F_40 ( V_37 , F_41 ( V_37 ) -> V_45 , V_9 ,
( unsigned long ) V_38 & ~ V_46 , V_39 , V_34 ) ;
return F_29 ( V_22 , V_9 , V_34 ) ;
}
static struct V_36 * F_42 ( struct V_5 * V_6 ,
union V_18 * V_19 ,
struct V_36 * V_37 )
{
struct V_7 * V_22 ;
struct V_9 * V_9 ;
V_22 = & V_6 -> V_22 [ V_6 -> V_47 ] ;
V_9 = V_22 -> V_9 ;
F_43 ( V_9 ) ;
if ( F_12 ( ! V_37 ) ) {
void * V_48 = F_33 ( V_9 ) +
V_22 -> V_16 ;
F_44 ( V_48 ) ;
#if V_49 < 128
F_44 ( V_48 + V_49 ) ;
#endif
V_37 = F_45 ( & V_6 -> V_50 -> V_51 ,
V_44 ) ;
if ( F_14 ( ! V_37 ) ) {
V_6 -> V_11 . V_12 ++ ;
return NULL ;
}
F_43 ( V_37 -> V_52 ) ;
}
F_46 ( V_6 -> V_13 ,
V_22 -> V_10 ,
V_22 -> V_16 ,
V_33 ,
V_15 ) ;
if ( F_32 ( V_22 , V_19 , V_37 ) ) {
F_23 ( V_6 , V_22 ) ;
} else {
F_47 ( V_6 -> V_13 , V_22 -> V_10 ,
V_14 , V_15 ) ;
}
V_22 -> V_9 = NULL ;
return V_37 ;
}
static inline void F_48 ( struct V_5 * V_53 ,
union V_18 * V_19 ,
struct V_36 * V_37 )
{
F_49 ( V_37 ) ;
if ( ! ( V_53 -> V_54 -> V_55 & V_56 ) )
return;
if ( F_50 ( V_19 ,
V_57 |
V_58 |
V_59 |
V_60 ) ) {
V_53 -> V_11 . V_61 ++ ;
return;
}
if ( F_50 ( V_19 , V_62 ) )
V_37 -> V_63 = true ;
else if ( ! F_50 ( V_19 , V_64 ) )
return;
V_37 -> V_65 = V_66 ;
V_53 -> V_11 . V_67 ++ ;
}
static inline void F_51 ( struct V_5 * V_53 ,
union V_18 * V_19 ,
struct V_36 * V_37 )
{
T_4 V_68 ;
if ( ! ( V_53 -> V_54 -> V_55 & V_69 ) )
return;
V_68 = F_34 ( V_19 -> V_40 . V_70 ) & V_71 ;
if ( ! V_68 )
return;
F_52 ( V_37 , F_53 ( V_19 -> V_26 . V_72 ) ,
( V_73 & ( 1ul << V_68 ) ) ?
V_74 : V_75 ) ;
}
static void F_54 ( struct V_5 * V_6 ,
union V_18 * V_19 ,
struct V_36 * V_37 )
{
struct V_76 * V_77 = V_6 -> V_50 -> V_77 ;
F_55 ( V_37 ) -> V_78 = V_19 -> V_24 . V_79 ;
if ( F_14 ( V_77 -> V_80 & V_81 ) )
F_56 ( V_77 , F_57 ( V_37 ) ,
F_58 ( V_19 -> V_24 . V_79 ) ) ;
}
static void F_59 ( struct V_5 * V_6 ,
union V_18 T_5 * V_19 ,
struct V_36 * V_37 )
{
struct V_82 * V_13 = V_6 -> V_54 ;
struct V_83 * V_84 = F_60 ( V_6 -> V_84 ) ;
if ( V_84 ) {
T_4 V_85 = F_34 ( F_55 ( V_37 ) -> V_86 . V_40 . V_87 ) - 1 ;
V_85 -= V_84 -> V_87 ;
if ( V_85 < V_84 -> V_39 && V_84 -> V_88 [ V_85 ] )
V_13 = V_84 -> V_88 [ V_85 ] ;
else
V_84 = NULL ;
}
V_37 -> V_89 = F_61 ( V_37 , V_13 ) ;
if ( ! V_84 )
return;
F_62 ( F_63 ( V_13 ) , V_37 -> V_90 + V_91 , 1 ,
! ! ( V_19 -> V_40 . V_92 &
F_64 ( V_93 ) ) ) ;
}
static unsigned int F_65 ( struct V_5 * V_6 ,
union V_18 * V_19 ,
struct V_36 * V_37 )
{
unsigned int V_90 = V_37 -> V_90 ;
F_51 ( V_6 , V_19 , V_37 ) ;
F_48 ( V_6 , V_19 , V_37 ) ;
F_54 ( V_6 , V_19 , V_37 ) ;
F_55 ( V_37 ) -> V_86 . V_40 . V_94 = V_19 -> V_40 . V_94 ;
F_66 ( V_37 , V_6 -> V_95 ) ;
F_55 ( V_37 ) -> V_86 . V_26 . V_96 = V_19 -> V_26 . V_96 ;
if ( V_19 -> V_40 . V_94 ) {
T_4 V_97 = F_34 ( V_19 -> V_40 . V_94 ) ;
if ( ( V_97 & V_98 ) != V_6 -> V_97 )
F_67 ( V_37 , F_68 ( V_99 ) , V_97 ) ;
else if ( V_97 & V_100 )
F_67 ( V_37 , F_68 ( V_99 ) ,
V_97 & V_100 ) ;
}
F_59 ( V_6 , V_19 , V_37 ) ;
return V_90 ;
}
static bool F_69 ( struct V_5 * V_6 ,
union V_18 * V_19 )
{
T_6 V_101 = V_6 -> V_47 + 1 ;
V_101 = ( V_101 < V_6 -> V_23 ) ? V_101 : 0 ;
V_6 -> V_47 = V_101 ;
F_44 ( F_19 ( V_6 , V_101 ) ) ;
if ( F_12 ( F_50 ( V_19 , V_102 ) ) )
return false ;
return true ;
}
static bool F_70 ( struct V_5 * V_6 ,
union V_18 * V_19 ,
struct V_36 * V_37 )
{
if ( F_14 ( ( F_50 ( V_19 ,
V_103 ) ) ) ) {
#define F_71 ( T_7 , T_8 ) \
((rxd)->w.csum_err & cpu_to_le16(bit))
if ( F_71 ( V_19 , V_104 ) )
V_6 -> V_11 . V_105 ++ ;
if ( F_71 ( V_19 , V_106 ) )
V_6 -> V_11 . V_107 ++ ;
if ( F_71 ( V_19 , V_108 ) )
V_6 -> V_11 . V_109 ++ ;
if ( F_71 ( V_19 , V_110 ) )
V_6 -> V_11 . V_111 ++ ;
if ( F_71 ( V_19 , V_112 ) )
V_6 -> V_11 . V_113 ++ ;
F_72 ( V_37 ) ;
V_6 -> V_11 . V_114 ++ ;
return true ;
}
if ( F_73 ( V_37 ) )
return true ;
return false ;
}
static void F_74 ( struct V_115 * V_50 ,
struct V_36 * V_37 )
{
F_75 ( & V_50 -> V_51 , V_37 ) ;
}
static int F_76 ( struct V_115 * V_50 ,
struct V_5 * V_6 ,
int V_116 )
{
struct V_36 * V_37 = V_6 -> V_37 ;
unsigned int V_117 = 0 , V_118 = 0 ;
T_4 V_17 = F_77 ( V_6 ) ;
while ( F_12 ( V_118 < V_116 ) ) {
union V_18 * V_19 ;
if ( V_17 >= V_119 ) {
F_18 ( V_6 , V_17 ) ;
V_17 = 0 ;
}
V_19 = F_19 ( V_6 , V_6 -> V_47 ) ;
if ( ! V_19 -> V_26 . V_27 )
break;
F_78 () ;
V_37 = F_42 ( V_6 , V_19 , V_37 ) ;
if ( ! V_37 )
break;
V_17 ++ ;
if ( F_69 ( V_6 , V_19 ) )
continue;
if ( F_70 ( V_6 , V_19 , V_37 ) ) {
V_37 = NULL ;
continue;
}
V_117 += F_65 ( V_6 , V_19 , V_37 ) ;
F_74 ( V_50 , V_37 ) ;
V_37 = NULL ;
V_118 ++ ;
}
V_6 -> V_37 = V_37 ;
F_79 ( & V_6 -> V_120 ) ;
V_6 -> V_121 . V_122 += V_118 ;
V_6 -> V_121 . V_123 += V_117 ;
F_80 ( & V_6 -> V_120 ) ;
V_50 -> V_124 . V_118 += V_118 ;
V_50 -> V_124 . V_117 += V_117 ;
return V_118 ;
}
static struct V_125 * F_81 ( struct V_36 * V_37 )
{
struct V_76 * V_77 = F_63 ( V_37 -> V_13 ) ;
struct V_126 * V_127 ;
V_127 = F_82 ( & V_77 -> V_127 ,
struct V_126 , V_128 ) ;
if ( ! V_127 )
return NULL ;
if ( V_127 -> V_129 != F_83 ( V_37 ) -> V_130 )
return NULL ;
return (struct V_125 * ) ( F_84 ( V_37 ) + V_131 ) ;
}
static struct V_125 * F_85 ( struct V_36 * V_37 )
{
struct V_132 * V_133 ;
int V_134 = F_86 ( V_37 ) ;
if ( F_87 ( V_37 ) != F_68 ( V_135 ) )
return NULL ;
V_133 = (struct V_132 * ) ( F_88 ( V_37 ) + V_134 ) ;
if ( V_133 -> V_80 & V_136 )
return NULL ;
if ( V_133 -> V_80 & V_137 )
return (struct V_125 * ) ( V_133 + 1 ) ;
return (struct V_125 * ) ( & V_133 -> V_138 ) ;
}
T_9 F_89 ( struct V_36 * V_37 )
{
T_10 V_139 = 0 , V_140 = 0 , V_141 ;
struct V_125 * V_142 ;
if ( V_37 -> V_143 != V_144 ||
V_37 -> V_145 != F_68 ( V_146 ) )
return 0 ;
switch ( F_87 ( V_37 ) ) {
case F_68 ( V_135 ) :
V_139 = F_90 ( V_37 ) -> V_89 ;
break;
case F_68 ( V_147 ) :
V_139 = F_91 ( V_37 ) -> V_148 ;
break;
default:
return 0 ;
}
switch ( V_139 ) {
case V_149 :
V_142 = F_81 ( V_37 ) ;
break;
case V_150 :
V_142 = F_85 ( V_37 ) ;
break;
default:
return 0 ;
}
if ( ! V_142 )
return 0 ;
switch ( V_142 -> V_151 ) {
case F_68 ( V_135 ) :
V_140 = F_92 ( V_37 ) -> V_89 ;
break;
case F_68 ( V_147 ) :
V_140 = F_93 ( V_37 ) -> V_148 ;
break;
default:
return 0 ;
}
switch ( V_140 ) {
case V_152 :
V_141 = F_94 ( V_37 ) ;
break;
case V_149 :
V_141 = 8 ;
break;
default:
return 0 ;
}
if ( F_95 ( V_37 ) + V_141 -
F_96 ( V_37 ) > V_153 )
return 0 ;
return V_142 -> V_151 ;
}
static int F_97 ( struct V_5 * V_154 ,
struct V_155 * V_156 )
{
struct V_36 * V_37 = V_156 -> V_37 ;
struct V_157 * V_158 ;
unsigned char * V_159 ;
T_10 V_160 ;
if ( V_37 -> V_65 != V_161 )
return 0 ;
if ( ! F_98 ( V_37 ) )
return 0 ;
if ( V_37 -> V_63 ) {
if ( ! F_89 ( V_37 ) )
goto V_162;
V_159 = F_95 ( V_37 ) ;
} else {
V_159 = F_84 ( V_37 ) ;
}
V_160 = ( V_159 - V_37 -> V_52 ) + ( ( (struct V_163 * ) V_159 ) -> V_164 << 2 ) ;
V_156 -> V_165 |= V_166 ;
V_156 -> V_167 = F_41 ( V_37 ) -> V_167 ;
V_156 -> V_168 += ( V_156 -> V_167 - 1 ) * V_160 ;
V_158 = F_99 ( V_154 , V_154 -> V_21 ) ;
V_158 -> V_160 = V_160 ;
V_158 -> V_169 = F_64 ( F_41 ( V_37 ) -> V_170 ) ;
return 1 ;
V_162:
V_154 -> V_54 -> V_55 &= ~ V_171 ;
if ( ! F_100 () )
F_101 ( V_154 -> V_54 ,
L_4 ) ;
return - 1 ;
}
static void F_102 ( struct V_5 * V_154 ,
struct V_155 * V_156 )
{
struct V_36 * V_37 = V_156 -> V_37 ;
struct V_157 * V_158 ;
union {
struct V_172 * V_173 ;
struct V_174 * V_175 ;
T_10 * V_176 ;
} V_177 ;
T_9 V_89 ;
T_10 V_139 = 0 ;
if ( V_37 -> V_65 != V_161 )
goto V_178;
if ( V_37 -> V_63 ) {
V_89 = F_89 ( V_37 ) ;
if ( ! V_89 ) {
if ( F_103 ( V_37 ) ) {
F_104 ( V_154 -> V_13 ,
L_5 ) ;
V_154 -> V_179 . V_61 ++ ;
}
goto V_178;
}
V_177 . V_176 = F_105 ( V_37 ) ;
} else {
V_89 = F_87 ( V_37 ) ;
V_177 . V_176 = F_88 ( V_37 ) ;
}
switch ( V_89 ) {
case F_68 ( V_135 ) :
V_139 = V_177 . V_173 -> V_89 ;
break;
case F_68 ( V_147 ) :
V_139 = V_177 . V_175 -> V_148 ;
break;
default:
if ( F_14 ( F_100 () ) ) {
F_104 ( V_154 -> V_13 ,
L_6 ,
V_89 ) ;
}
V_154 -> V_179 . V_61 ++ ;
goto V_178;
}
switch ( V_139 ) {
case V_152 :
case V_149 :
break;
case V_150 :
if ( V_37 -> V_63 )
break;
default:
if ( F_14 ( F_100 () ) ) {
F_104 ( V_154 -> V_13 ,
L_7 ,
V_139 ) ;
}
V_154 -> V_179 . V_61 ++ ;
goto V_178;
}
V_156 -> V_165 |= V_166 ;
V_154 -> V_179 . V_67 ++ ;
V_178:
V_158 = F_99 ( V_154 , V_154 -> V_21 ) ;
V_158 -> V_160 = 0 ;
V_158 -> V_169 = 0 ;
}
static T_10 F_106 ( struct V_36 * V_37 , T_6 V_165 )
{
T_6 V_180 = 0 ;
if ( F_14 ( F_41 ( V_37 ) -> V_165 & V_181 ) &&
F_12 ( F_41 ( V_37 ) -> V_165 & V_182 ) )
V_180 |= V_183 ;
V_180 |= F_107 ( V_165 , V_166 ,
V_184 ) ;
return V_180 ;
}
static bool F_108 ( struct V_5 * V_154 ,
struct V_157 * V_158 , T_4 V_20 ,
T_3 V_10 , unsigned int V_39 , T_10 V_180 )
{
if ( ( ++ V_20 & ( V_185 - 1 ) ) == 0 )
V_180 |= V_186 | V_187 ;
V_158 -> V_188 = F_20 ( V_10 ) ;
V_158 -> V_80 = V_180 ;
V_158 -> V_189 = F_64 ( V_39 ) ;
return V_20 == V_154 -> V_23 ;
}
static int F_109 ( struct V_5 * V_154 , T_4 V_39 )
{
F_110 ( V_154 -> V_54 , V_154 -> V_95 ) ;
F_111 () ;
if ( F_12 ( F_77 ( V_154 ) < V_39 ) )
return - V_190 ;
F_112 ( V_154 -> V_54 , V_154 -> V_95 ) ;
++ V_154 -> V_179 . V_191 ;
return 0 ;
}
static inline int F_113 ( struct V_5 * V_154 , T_4 V_39 )
{
if ( F_12 ( F_77 ( V_154 ) >= V_39 ) )
return 0 ;
return F_109 ( V_154 , V_39 ) ;
}
static void F_114 ( struct V_5 * V_154 ,
struct V_155 * V_156 )
{
struct V_36 * V_37 = V_156 -> V_37 ;
struct V_155 * V_192 ;
struct V_157 * V_158 ;
struct V_193 * V_194 ;
unsigned char * V_52 ;
T_3 V_10 ;
unsigned int V_195 , V_39 ;
T_6 V_165 = V_156 -> V_165 ;
T_4 V_20 = V_154 -> V_21 ;
T_10 V_80 = F_106 ( V_37 , V_165 ) ;
V_158 = F_99 ( V_154 , V_20 ) ;
if ( F_115 ( V_37 ) )
V_158 -> V_94 = F_64 ( F_116 ( V_37 ) ) ;
else
V_158 -> V_94 = 0 ;
V_39 = F_117 ( V_37 ) ;
V_52 = V_37 -> V_52 ;
V_10 = F_118 ( V_154 -> V_13 , V_52 , V_39 , V_196 ) ;
V_195 = V_37 -> V_195 ;
V_192 = V_156 ;
for ( V_194 = & F_41 ( V_37 ) -> V_197 [ 0 ] ; ; V_194 ++ ) {
if ( F_16 ( V_154 -> V_13 , V_10 ) )
goto V_198;
F_119 ( V_192 , V_90 , V_39 ) ;
F_120 ( V_192 , V_10 , V_10 ) ;
while ( F_14 ( V_39 > V_199 ) ) {
if ( F_108 ( V_154 , V_158 ++ , V_20 ++ , V_10 ,
V_199 , V_80 ) ) {
V_158 = F_99 ( V_154 , 0 ) ;
V_20 = 0 ;
}
V_10 += V_199 ;
V_39 -= V_199 ;
}
if ( F_12 ( ! V_195 ) )
break;
if ( F_108 ( V_154 , V_158 ++ , V_20 ++ ,
V_10 , V_39 , V_80 ) ) {
V_158 = F_99 ( V_154 , 0 ) ;
V_20 = 0 ;
}
V_39 = F_121 ( V_194 ) ;
V_195 -= V_39 ;
V_10 = F_122 ( V_154 -> V_13 , V_194 , 0 , V_39 ,
V_196 ) ;
V_192 = & V_154 -> V_192 [ V_20 ] ;
}
V_80 |= V_200 ;
if ( F_108 ( V_154 , V_158 , V_20 ++ , V_10 , V_39 , V_80 ) )
V_20 = 0 ;
F_123 ( F_124 ( V_154 ) , V_156 -> V_168 ) ;
F_125 ( V_156 -> V_37 ) ;
F_21 () ;
V_156 -> V_201 = V_158 ;
V_154 -> V_21 = V_20 ;
F_113 ( V_154 , V_202 ) ;
if ( F_126 ( F_124 ( V_154 ) ) || ! V_37 -> V_203 ) {
F_22 ( V_20 , V_154 -> V_29 ) ;
F_127 () ;
}
return;
V_198:
F_128 ( V_154 -> V_13 , L_8 ) ;
for (; ; ) {
V_192 = & V_154 -> V_192 [ V_20 ] ;
F_129 ( V_154 , V_192 ) ;
if ( V_192 == V_156 )
break;
if ( V_20 == 0 )
V_20 = V_154 -> V_23 ;
V_20 -- ;
}
V_154 -> V_21 = V_20 ;
}
T_11 F_130 ( struct V_36 * V_37 ,
struct V_5 * V_154 )
{
T_4 V_23 = F_131 ( F_117 ( V_37 ) ) ;
struct V_155 * V_156 ;
unsigned short V_204 ;
T_6 V_165 = 0 ;
int V_205 ;
for ( V_204 = 0 ; V_204 < F_41 ( V_37 ) -> V_45 ; V_204 ++ )
V_23 += F_131 ( F_41 ( V_37 ) -> V_197 [ V_204 ] . V_39 ) ;
if ( F_113 ( V_154 , V_23 + 3 ) ) {
V_154 -> V_179 . V_206 ++ ;
return V_207 ;
}
V_156 = & V_154 -> V_192 [ V_154 -> V_21 ] ;
V_156 -> V_37 = V_37 ;
V_156 -> V_168 = F_132 (unsigned int, skb->len, ETH_ZLEN) ;
V_156 -> V_167 = 1 ;
V_156 -> V_165 = V_165 ;
V_205 = F_97 ( V_154 , V_156 ) ;
if ( V_205 < 0 )
goto V_208;
else if ( ! V_205 )
F_102 ( V_154 , V_156 ) ;
F_114 ( V_154 , V_156 ) ;
return V_209 ;
V_208:
F_72 ( V_156 -> V_37 ) ;
V_156 -> V_37 = NULL ;
return V_209 ;
}
static T_12 F_133 ( struct V_5 * V_53 )
{
return V_53 -> V_121 . V_122 ;
}
static T_12 F_134 ( struct V_5 * V_53 )
{
T_6 V_210 = V_53 -> V_47 ;
T_6 V_29 = V_53 -> V_21 ;
return ( ( V_210 <= V_29 ) ? V_29 : V_29 + V_53 -> V_23 ) - V_210 ;
}
bool F_135 ( struct V_5 * V_154 )
{
T_6 V_211 = F_133 ( V_154 ) ;
T_6 V_212 = V_154 -> V_179 . V_212 ;
T_6 V_213 = F_134 ( V_154 ) ;
F_136 ( V_154 ) ;
if ( ! V_213 || ( V_212 != V_211 ) ) {
V_154 -> V_179 . V_212 = V_211 ;
F_137 ( V_214 , & V_154 -> V_215 ) ;
return false ;
}
return F_138 ( V_214 , & V_154 -> V_215 ) ;
}
void F_139 ( struct V_76 * V_77 )
{
if ( ! F_140 ( V_216 , & V_77 -> V_215 ) ) {
V_77 -> V_217 ++ ;
V_77 -> V_80 |= V_218 ;
F_141 ( V_77 ) ;
}
}
static bool F_142 ( struct V_115 * V_50 ,
struct V_5 * V_154 )
{
struct V_76 * V_77 = V_50 -> V_77 ;
struct V_155 * V_192 ;
struct V_157 * V_158 ;
unsigned int V_117 = 0 , V_118 = 0 ;
unsigned int V_116 = V_50 -> V_219 . V_220 ;
unsigned int V_20 = V_154 -> V_47 ;
if ( F_140 ( V_216 , & V_77 -> V_215 ) )
return true ;
V_192 = & V_154 -> V_192 [ V_20 ] ;
V_158 = F_99 ( V_154 , V_20 ) ;
V_20 -= V_154 -> V_23 ;
do {
struct V_157 * V_221 = V_192 -> V_201 ;
if ( ! V_221 )
break;
F_143 () ;
if ( ! ( V_221 -> V_80 & V_222 ) )
break;
V_192 -> V_201 = NULL ;
V_117 += V_192 -> V_168 ;
V_118 += V_192 -> V_167 ;
F_144 ( V_192 -> V_37 ) ;
F_145 ( V_154 -> V_13 ,
F_146 ( V_192 , V_10 ) ,
F_147 ( V_192 , V_90 ) ,
V_196 ) ;
V_192 -> V_37 = NULL ;
F_119 ( V_192 , V_90 , 0 ) ;
while ( V_158 != V_221 ) {
V_192 ++ ;
V_158 ++ ;
V_20 ++ ;
if ( F_14 ( ! V_20 ) ) {
V_20 -= V_154 -> V_23 ;
V_192 = V_154 -> V_192 ;
V_158 = F_99 ( V_154 , 0 ) ;
}
if ( F_147 ( V_192 , V_90 ) ) {
F_47 ( V_154 -> V_13 ,
F_146 ( V_192 , V_10 ) ,
F_147 ( V_192 , V_90 ) ,
V_196 ) ;
F_119 ( V_192 , V_90 , 0 ) ;
}
}
V_192 ++ ;
V_158 ++ ;
V_20 ++ ;
if ( F_14 ( ! V_20 ) ) {
V_20 -= V_154 -> V_23 ;
V_192 = V_154 -> V_192 ;
V_158 = F_99 ( V_154 , 0 ) ;
}
F_44 ( V_158 ) ;
V_116 -- ;
} while ( F_12 ( V_116 ) );
V_20 += V_154 -> V_23 ;
V_154 -> V_47 = V_20 ;
F_79 ( & V_154 -> V_120 ) ;
V_154 -> V_121 . V_123 += V_117 ;
V_154 -> V_121 . V_122 += V_118 ;
F_80 ( & V_154 -> V_120 ) ;
V_50 -> V_219 . V_117 += V_117 ;
V_50 -> V_219 . V_118 += V_118 ;
if ( F_148 ( V_154 ) && F_135 ( V_154 ) ) {
struct V_223 * V_224 = & V_77 -> V_224 ;
F_149 ( V_77 , V_225 , V_154 -> V_54 ,
L_9
L_10
L_11
L_12
L_13 ,
V_154 -> V_95 ,
F_150 ( V_224 , F_151 ( V_154 -> V_226 ) ) ,
F_150 ( V_224 , F_152 ( V_154 -> V_226 ) ) ,
V_154 -> V_21 , V_20 ) ;
F_110 ( V_154 -> V_54 ,
V_154 -> V_95 ) ;
F_153 ( V_77 , V_227 , V_154 -> V_54 ,
L_14 ,
V_77 -> V_217 + 1 ,
V_154 -> V_95 ) ;
F_139 ( V_77 ) ;
return true ;
}
F_154 ( F_124 ( V_154 ) ,
V_118 , V_117 ) ;
#define F_155 min_t(u16, FM10K_MIN_TXD - 1, DESC_NEEDED * 2)
if ( F_14 ( V_118 && F_156 ( V_154 -> V_54 ) &&
( F_77 ( V_154 ) >= F_155 ) ) ) {
F_111 () ;
if ( F_157 ( V_154 -> V_54 ,
V_154 -> V_95 ) &&
! F_140 ( V_216 , & V_77 -> V_215 ) ) {
F_158 ( V_154 -> V_54 ,
V_154 -> V_95 ) ;
++ V_154 -> V_179 . V_191 ;
}
}
return ! ! V_116 ;
}
static void F_159 ( struct V_228 * V_229 )
{
unsigned int V_230 , V_122 , V_231 ;
if ( ! F_160 ( V_229 -> V_232 ) )
goto V_233;
V_122 = V_229 -> V_118 ;
if ( ! V_122 )
goto V_233;
V_230 = V_229 -> V_117 / V_122 ;
if ( V_230 <= 360 ) {
V_230 *= 8 ;
V_230 += 376 ;
} else if ( V_230 <= 1152 ) {
V_230 *= 3 ;
V_230 += 2176 ;
} else if ( V_230 <= 1920 ) {
V_230 += 4480 ;
} else {
V_230 = 6656 ;
}
V_231 = F_161 ( V_229 -> V_234 ) + 8 ;
V_230 += ( 1 << V_231 ) - 1 ;
V_230 >>= V_231 ;
V_229 -> V_232 = V_230 | V_235 ;
V_233:
V_229 -> V_117 = 0 ;
V_229 -> V_118 = 0 ;
}
static void F_162 ( struct V_115 * V_50 )
{
T_6 V_232 = V_236 ;
F_159 ( & V_50 -> V_219 ) ;
F_159 ( & V_50 -> V_124 ) ;
V_232 |= ( V_50 -> V_219 . V_232 & V_237 ) ;
V_232 |= ( V_50 -> V_124 . V_232 & V_237 ) << V_238 ;
F_22 ( V_232 , V_50 -> V_232 ) ;
}
static int F_163 ( struct V_239 * V_51 , int V_116 )
{
struct V_115 * V_50 =
F_164 ( V_51 , struct V_115 , V_51 ) ;
struct V_5 * V_53 ;
int V_240 , V_241 = 0 ;
bool V_242 = true ;
F_165 (ring, q_vector->tx)
V_242 &= F_142 ( V_50 , V_53 ) ;
if ( V_116 <= 0 )
return V_116 ;
if ( V_50 -> V_124 . V_23 > 1 )
V_240 = F_166 ( V_116 / V_50 -> V_124 . V_23 , 1 ) ;
else
V_240 = V_116 ;
F_165 (ring, q_vector->rx) {
int V_243 = F_76 ( V_50 , V_53 , V_240 ) ;
V_241 += V_243 ;
V_242 &= ! ! ( V_243 < V_240 ) ;
}
if ( ! V_242 )
return V_116 ;
F_167 ( V_51 , V_241 ) ;
F_162 ( V_50 ) ;
return 0 ;
}
static bool F_168 ( struct V_76 * V_77 )
{
struct V_82 * V_13 = V_77 -> V_54 ;
struct V_244 * V_204 ;
int V_245 , V_20 ;
int V_246 ;
V_246 = F_169 ( V_13 ) ;
if ( V_246 <= 1 )
return false ;
V_204 = & V_77 -> V_247 [ V_248 ] ;
V_204 -> V_249 = V_246 ;
V_204 -> V_250 = ( 1 << F_170 ( V_246 - 1 ) ) - 1 ;
V_245 = V_77 -> V_224 . V_251 . V_252 / V_246 ;
V_245 = 1 << ( F_170 ( V_245 ) - 1 ) ;
V_204 = & V_77 -> V_247 [ V_253 ] ;
V_245 = F_171 ( T_4 , V_245 , V_204 -> V_254 ) ;
V_204 -> V_249 = V_245 ;
V_204 -> V_250 = ( 1 << F_170 ( V_245 - 1 ) ) - 1 ;
for ( V_20 = 0 ; V_20 < V_246 ; V_20 ++ )
F_172 ( V_13 , V_20 , V_245 , V_245 * V_20 ) ;
V_77 -> V_255 = V_245 * V_246 ;
V_77 -> V_256 = V_245 * V_246 ;
return true ;
}
static bool F_173 ( struct V_76 * V_77 )
{
struct V_244 * V_204 ;
T_4 V_245 ;
V_204 = & V_77 -> V_247 [ V_253 ] ;
V_245 = F_171 ( T_4 , V_77 -> V_224 . V_251 . V_252 , V_204 -> V_254 ) ;
V_204 -> V_249 = V_245 ;
V_204 -> V_250 = ( 1 << F_170 ( V_245 - 1 ) ) - 1 ;
V_77 -> V_255 = V_245 ;
V_77 -> V_256 = V_245 ;
return true ;
}
static void F_174 ( struct V_76 * V_77 )
{
V_77 -> V_255 = 1 ;
V_77 -> V_256 = 1 ;
if ( F_168 ( V_77 ) )
return;
F_173 ( V_77 ) ;
}
static int F_175 ( struct V_76 * V_77 ,
unsigned int V_257 , unsigned int V_258 ,
unsigned int V_259 , unsigned int V_260 ,
unsigned int V_261 , unsigned int V_262 )
{
struct V_115 * V_50 ;
struct V_5 * V_53 ;
int V_263 , V_39 ;
V_263 = V_259 + V_261 ;
V_39 = sizeof( struct V_115 ) +
( sizeof( struct V_5 ) * V_263 ) ;
V_50 = F_176 ( V_39 , V_264 ) ;
if ( ! V_50 )
return - V_265 ;
F_177 ( V_77 -> V_54 , & V_50 -> V_51 ,
F_163 , V_266 ) ;
V_77 -> V_50 [ V_258 ] = V_50 ;
V_50 -> V_77 = V_77 ;
V_50 -> V_258 = V_258 ;
V_53 = V_50 -> V_53 ;
V_50 -> V_219 . V_53 = V_53 ;
V_50 -> V_219 . V_220 = V_267 ;
V_50 -> V_219 . V_232 = V_77 -> V_268 ;
V_50 -> V_219 . V_234 = V_77 -> V_224 . V_251 . V_234 ;
V_50 -> V_219 . V_23 = V_259 ;
while ( V_259 ) {
V_53 -> V_13 = & V_77 -> V_269 -> V_13 ;
V_53 -> V_54 = V_77 -> V_54 ;
V_53 -> V_50 = V_50 ;
V_53 -> V_23 = V_77 -> V_270 ;
V_53 -> V_95 = V_260 ;
V_77 -> V_154 [ V_260 ] = V_53 ;
V_259 -- ;
V_260 += V_257 ;
V_53 ++ ;
}
V_50 -> V_124 . V_53 = V_53 ;
V_50 -> V_124 . V_232 = V_77 -> V_271 ;
V_50 -> V_124 . V_234 = V_77 -> V_224 . V_251 . V_234 ;
V_50 -> V_124 . V_23 = V_261 ;
while ( V_261 ) {
V_53 -> V_13 = & V_77 -> V_269 -> V_13 ;
V_53 -> V_54 = V_77 -> V_54 ;
F_178 ( V_53 -> V_84 , V_77 -> V_84 ) ;
V_53 -> V_50 = V_50 ;
V_53 -> V_23 = V_77 -> V_272 ;
V_53 -> V_95 = V_262 ;
V_77 -> V_6 [ V_262 ] = V_53 ;
V_261 -- ;
V_262 += V_257 ;
V_53 ++ ;
}
F_179 ( V_50 ) ;
return 0 ;
}
static void F_180 ( struct V_76 * V_77 , int V_258 )
{
struct V_115 * V_50 = V_77 -> V_50 [ V_258 ] ;
struct V_5 * V_53 ;
F_181 ( V_50 ) ;
F_165 (ring, q_vector->tx)
V_77 -> V_154 [ V_53 -> V_95 ] = NULL ;
F_165 (ring, q_vector->rx)
V_77 -> V_6 [ V_53 -> V_95 ] = NULL ;
V_77 -> V_50 [ V_258 ] = NULL ;
F_182 ( & V_50 -> V_51 ) ;
F_183 ( V_50 , V_273 ) ;
}
static int F_184 ( struct V_76 * V_77 )
{
unsigned int V_274 = V_77 -> V_275 ;
unsigned int V_276 = V_77 -> V_255 ;
unsigned int V_277 = V_77 -> V_256 ;
unsigned int V_262 = 0 , V_260 = 0 , V_258 = 0 ;
int V_278 ;
if ( V_274 >= ( V_276 + V_277 ) ) {
for (; V_276 ; V_258 ++ ) {
V_278 = F_175 ( V_77 , V_274 , V_258 ,
0 , 0 , 1 , V_262 ) ;
if ( V_278 )
goto V_279;
V_276 -- ;
V_262 ++ ;
}
}
for (; V_258 < V_274 ; V_258 ++ ) {
int V_280 = F_185 ( V_276 , V_274 - V_258 ) ;
int V_281 = F_185 ( V_277 , V_274 - V_258 ) ;
V_278 = F_175 ( V_77 , V_274 , V_258 ,
V_281 , V_260 ,
V_280 , V_262 ) ;
if ( V_278 )
goto V_279;
V_276 -= V_280 ;
V_277 -= V_281 ;
V_262 ++ ;
V_260 ++ ;
}
return 0 ;
V_279:
V_77 -> V_256 = 0 ;
V_77 -> V_255 = 0 ;
V_77 -> V_275 = 0 ;
while ( V_258 -- )
F_180 ( V_77 , V_258 ) ;
return - V_265 ;
}
static void F_186 ( struct V_76 * V_77 )
{
int V_258 = V_77 -> V_275 ;
V_77 -> V_256 = 0 ;
V_77 -> V_255 = 0 ;
V_77 -> V_275 = 0 ;
while ( V_258 -- )
F_180 ( V_77 , V_258 ) ;
}
static void F_187 ( struct V_76 * V_77 )
{
F_188 ( V_77 -> V_269 ) ;
F_189 ( V_77 -> V_282 ) ;
V_77 -> V_282 = NULL ;
}
static int F_190 ( struct V_76 * V_77 )
{
struct V_223 * V_224 = & V_77 -> V_224 ;
int V_283 , V_284 ;
V_283 = F_166 ( V_77 -> V_255 , V_77 -> V_256 ) ;
V_283 = F_171 ( T_4 , V_283 , F_191 () ) ;
V_283 += F_192 ( V_224 ) ;
V_283 = F_171 ( int , V_283 , V_224 -> V_251 . V_285 ) ;
V_77 -> V_282 = F_193 ( V_283 , sizeof( struct V_286 ) ,
V_264 ) ;
if ( ! V_77 -> V_282 )
return - V_265 ;
for ( V_284 = 0 ; V_284 < V_283 ; V_284 ++ )
V_77 -> V_282 [ V_284 ] . V_287 = V_284 ;
V_283 = F_194 ( V_77 -> V_269 ,
V_77 -> V_282 ,
F_195 ( V_224 ) ,
V_283 ) ;
if ( V_283 < 0 ) {
F_189 ( V_77 -> V_282 ) ;
V_77 -> V_282 = NULL ;
return - V_265 ;
}
V_77 -> V_275 = V_283 - F_192 ( V_224 ) ;
return 0 ;
}
static bool F_196 ( struct V_76 * V_77 )
{
struct V_82 * V_13 = V_77 -> V_54 ;
int V_288 , V_289 , V_245 , V_20 , V_290 ;
T_4 V_291 = V_77 -> V_247 [ V_248 ] . V_250 + 1 ;
T_10 V_292 = F_169 ( V_13 ) ;
if ( V_292 <= 1 )
return false ;
V_245 = V_77 -> V_247 [ V_253 ] . V_249 ;
for ( V_288 = 0 , V_289 = 0 ; V_288 < V_292 ; V_288 ++ , V_289 += V_245 ) {
V_290 = V_288 ;
for ( V_20 = 0 ; V_20 < V_245 ; V_20 ++ ) {
V_77 -> V_154 [ V_289 + V_20 ] -> V_226 = V_290 ;
V_77 -> V_154 [ V_289 + V_20 ] -> V_293 = V_288 ;
V_77 -> V_6 [ V_289 + V_20 ] -> V_226 = V_290 ;
V_77 -> V_6 [ V_289 + V_20 ] -> V_293 = V_288 ;
V_290 += V_291 ;
}
}
return true ;
}
static void F_197 ( struct V_76 * V_77 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_77 -> V_255 ; V_20 ++ )
V_77 -> V_6 [ V_20 ] -> V_226 = V_20 ;
for ( V_20 = 0 ; V_20 < V_77 -> V_256 ; V_20 ++ )
V_77 -> V_154 [ V_20 ] -> V_226 = V_20 ;
}
static void F_198 ( struct V_76 * V_77 )
{
if ( F_196 ( V_77 ) )
return;
F_197 ( V_77 ) ;
}
static void F_199 ( struct V_76 * V_77 )
{
T_4 V_20 , V_245 = V_77 -> V_247 [ V_253 ] . V_249 ;
T_6 V_294 , V_295 ;
if ( V_77 -> V_54 -> V_296 != V_297 ) {
for ( V_20 = V_298 ; V_20 -- ; ) {
V_294 = V_77 -> V_294 [ V_20 ] ;
if ( ( ( ( V_294 << 24 ) >> 24 ) < V_245 ) &&
( ( ( V_294 << 16 ) >> 24 ) < V_245 ) &&
( ( ( V_294 << 8 ) >> 24 ) < V_245 ) &&
( ( ( V_294 ) >> 24 ) < V_245 ) )
continue;
goto V_299;
}
return;
}
V_299:
for ( V_20 = V_298 ; V_20 -- ; ) {
V_295 = ( ( V_20 * 0x00040004 ) + 0x00020000 ) * V_245 ;
V_294 = ( V_295 & 0x3F803F80 ) >> 7 ;
V_295 += 0x00010001 * V_245 ;
V_294 |= ( V_295 & 0x3F803F80 ) << 1 ;
V_77 -> V_294 [ V_20 ] = V_294 ;
}
}
int F_200 ( struct V_76 * V_77 )
{
int V_278 ;
F_174 ( V_77 ) ;
V_278 = F_190 ( V_77 ) ;
if ( V_278 ) {
F_128 ( & V_77 -> V_269 -> V_13 ,
L_15 ) ;
return V_278 ;
}
V_278 = F_184 ( V_77 ) ;
if ( V_278 ) {
F_187 ( V_77 ) ;
return V_278 ;
}
F_198 ( V_77 ) ;
F_199 ( V_77 ) ;
return 0 ;
}
void F_201 ( struct V_76 * V_77 )
{
F_186 ( V_77 ) ;
F_187 ( V_77 ) ;
}
