static int T_1 F_1 ( void )
{
F_2 ( L_1 , V_1 , V_2 ) ;
F_2 ( L_2 , V_3 ) ;
V_4 = F_3 ( L_3 , V_5 , 0 ,
V_6 ) ;
F_4 () ;
return F_5 () ;
}
static void T_2 F_6 ( void )
{
F_7 () ;
F_8 () ;
F_9 ( V_4 ) ;
}
static bool F_10 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_11 = V_10 -> V_11 ;
T_3 V_12 ;
if ( F_11 ( V_11 ) )
return true ;
V_11 = F_12 () ;
if ( F_13 ( ! V_11 ) ) {
V_8 -> V_13 . V_14 ++ ;
return false ;
}
V_12 = F_14 ( V_8 -> V_15 , V_11 , 0 , V_16 , V_17 ) ;
if ( F_15 ( V_8 -> V_15 , V_12 ) ) {
F_16 ( V_11 ) ;
V_8 -> V_13 . V_14 ++ ;
return false ;
}
V_10 -> V_12 = V_12 ;
V_10 -> V_11 = V_11 ;
V_10 -> V_18 = 0 ;
return true ;
}
void F_17 ( struct V_7 * V_8 , T_4 V_19 )
{
union V_20 * V_21 ;
struct V_9 * V_10 ;
T_4 V_22 = V_8 -> V_23 ;
if ( ! V_19 )
return;
V_21 = F_18 ( V_8 , V_22 ) ;
V_10 = & V_8 -> V_24 [ V_22 ] ;
V_22 -= V_8 -> V_25 ;
do {
if ( ! F_10 ( V_8 , V_10 ) )
break;
V_21 -> V_26 . V_27 = F_19 ( V_10 -> V_12 + V_10 -> V_18 ) ;
V_21 ++ ;
V_10 ++ ;
V_22 ++ ;
if ( F_13 ( ! V_22 ) ) {
V_21 = F_18 ( V_8 , 0 ) ;
V_10 = V_8 -> V_24 ;
V_22 -= V_8 -> V_25 ;
}
V_21 -> V_28 . V_29 = 0 ;
V_19 -- ;
} while ( V_19 );
V_22 += V_8 -> V_25 ;
if ( V_8 -> V_23 != V_22 ) {
V_8 -> V_23 = V_22 ;
V_8 -> V_30 = V_22 ;
F_20 () ;
F_21 ( V_22 , V_8 -> V_31 ) ;
}
}
static void F_22 ( struct V_7 * V_8 ,
struct V_9 * V_32 )
{
struct V_9 * V_33 ;
T_4 V_34 = V_8 -> V_30 ;
V_33 = & V_8 -> V_24 [ V_34 ] ;
V_34 ++ ;
V_8 -> V_30 = ( V_34 < V_8 -> V_25 ) ? V_34 : 0 ;
* V_33 = * V_32 ;
F_23 ( V_8 -> V_15 , V_32 -> V_12 ,
V_32 -> V_18 ,
V_35 ,
V_17 ) ;
}
static inline bool F_24 ( struct V_11 * V_11 )
{
return ( F_25 ( V_11 ) != F_26 () ) || F_27 ( V_11 ) ;
}
static bool F_28 ( struct V_9 * V_24 ,
struct V_11 * V_11 ,
unsigned int T_5 V_36 )
{
if ( F_13 ( F_24 ( V_11 ) ) )
return false ;
#if ( V_16 < 8192 )
if ( F_13 ( F_29 ( V_11 ) != 1 ) )
return false ;
V_24 -> V_18 ^= V_35 ;
#else
V_24 -> V_18 += V_36 ;
if ( V_24 -> V_18 > ( V_16 - V_35 ) )
return false ;
#endif
F_30 ( V_11 ) ;
return true ;
}
static bool F_31 ( struct V_9 * V_24 ,
unsigned int V_37 ,
union V_20 * V_21 ,
struct V_38 * V_39 )
{
struct V_11 * V_11 = V_24 -> V_11 ;
unsigned char * V_40 = F_32 ( V_11 ) + V_24 -> V_18 ;
#if ( V_16 < 8192 )
unsigned int V_36 = V_35 ;
#else
unsigned int V_36 = F_33 ( V_37 , 512 ) ;
#endif
unsigned int V_41 ;
if ( F_13 ( F_34 ( V_39 ) ) )
goto V_42;
if ( F_11 ( V_37 <= V_43 ) ) {
memcpy ( F_35 ( V_39 , V_37 ) , V_40 , F_33 ( V_37 , sizeof( long ) ) ) ;
if ( F_11 ( ! F_24 ( V_11 ) ) )
return true ;
F_16 ( V_11 ) ;
return false ;
}
V_41 = F_36 ( V_40 , V_43 ) ;
memcpy ( F_35 ( V_39 , V_41 ) , V_40 , F_33 ( V_41 , sizeof( long ) ) ) ;
V_40 += V_41 ;
V_37 -= V_41 ;
V_42:
F_37 ( V_39 , F_38 ( V_39 ) -> V_44 , V_11 ,
( unsigned long ) V_40 & ~ V_45 , V_37 , V_36 ) ;
return F_28 ( V_24 , V_11 , V_36 ) ;
}
static struct V_38 * F_39 ( struct V_7 * V_8 ,
union V_20 * V_21 ,
struct V_38 * V_39 )
{
unsigned int V_37 = F_40 ( V_21 -> V_46 . V_47 ) ;
struct V_9 * V_24 ;
struct V_11 * V_11 ;
V_24 = & V_8 -> V_24 [ V_8 -> V_48 ] ;
V_11 = V_24 -> V_11 ;
F_41 ( V_11 ) ;
if ( F_11 ( ! V_39 ) ) {
void * V_49 = F_32 ( V_11 ) +
V_24 -> V_18 ;
F_42 ( V_49 ) ;
#if V_50 < 128
F_42 ( V_49 + V_50 ) ;
#endif
V_39 = F_43 ( & V_8 -> V_51 -> V_52 ,
V_43 ) ;
if ( F_13 ( ! V_39 ) ) {
V_8 -> V_13 . V_14 ++ ;
return NULL ;
}
F_41 ( V_39 -> V_53 ) ;
}
F_44 ( V_8 -> V_15 ,
V_24 -> V_12 ,
V_24 -> V_18 ,
V_37 ,
V_17 ) ;
if ( F_31 ( V_24 , V_37 , V_21 , V_39 ) ) {
F_22 ( V_8 , V_24 ) ;
} else {
F_45 ( V_8 -> V_15 , V_24 -> V_12 ,
V_16 , V_17 ) ;
}
V_24 -> V_11 = NULL ;
return V_39 ;
}
static inline void F_46 ( struct V_7 * V_54 ,
union V_20 * V_21 ,
struct V_38 * V_39 )
{
F_47 ( V_39 ) ;
if ( ! ( V_54 -> V_55 -> V_56 & V_57 ) )
return;
if ( F_48 ( V_21 ,
V_58 |
V_59 |
V_60 |
V_61 ) ) {
V_54 -> V_13 . V_62 ++ ;
return;
}
if ( F_48 ( V_21 , V_63 ) )
V_39 -> V_64 = true ;
else if ( ! F_48 ( V_21 , V_65 ) )
return;
V_39 -> V_66 = V_67 ;
V_54 -> V_13 . V_68 ++ ;
}
static inline void F_49 ( struct V_7 * V_54 ,
union V_20 * V_21 ,
struct V_38 * V_39 )
{
T_4 V_69 ;
if ( ! ( V_54 -> V_55 -> V_56 & V_70 ) )
return;
V_69 = F_40 ( V_21 -> V_46 . V_71 ) & V_72 ;
if ( ! V_69 )
return;
F_50 ( V_39 , F_51 ( V_21 -> V_28 . V_73 ) ,
( F_52 ( V_69 ) & V_74 ) ?
V_75 : V_76 ) ;
}
static void F_53 ( struct V_7 * V_8 ,
union V_20 T_5 * V_21 ,
struct V_38 * V_39 )
{
struct V_77 * V_15 = V_8 -> V_55 ;
struct V_78 * V_79 = F_54 ( V_8 -> V_79 ) ;
if ( V_79 ) {
T_4 V_80 = F_40 ( F_55 ( V_39 ) -> V_81 . V_46 . V_82 ) - 1 ;
V_80 -= V_79 -> V_82 ;
if ( V_80 < V_79 -> V_37 && V_79 -> V_83 [ V_80 ] )
V_15 = V_79 -> V_83 [ V_80 ] ;
else
V_79 = NULL ;
}
V_39 -> V_84 = F_56 ( V_39 , V_15 ) ;
if ( ! V_79 )
return;
F_57 ( F_58 ( V_15 ) , V_39 -> V_85 + V_86 , 1 ,
! ! ( V_21 -> V_46 . V_87 &
F_59 ( V_88 ) ) ) ;
}
static unsigned int F_60 ( struct V_7 * V_8 ,
union V_20 * V_21 ,
struct V_38 * V_39 )
{
unsigned int V_85 = V_39 -> V_85 ;
F_49 ( V_8 , V_21 , V_39 ) ;
F_46 ( V_8 , V_21 , V_39 ) ;
F_55 ( V_39 ) -> V_89 = V_21 -> V_26 . V_90 ;
F_55 ( V_39 ) -> V_81 . V_46 . V_91 = V_21 -> V_46 . V_91 ;
F_61 ( V_39 , V_8 -> V_92 ) ;
F_55 ( V_39 ) -> V_81 . V_28 . V_93 = V_21 -> V_28 . V_93 ;
if ( V_21 -> V_46 . V_91 ) {
T_4 V_94 = F_40 ( V_21 -> V_46 . V_91 ) ;
if ( ( V_94 & V_95 ) != V_8 -> V_94 )
F_62 ( V_39 , F_63 ( V_96 ) , V_94 ) ;
else if ( V_94 & V_97 )
F_62 ( V_39 , F_63 ( V_96 ) ,
V_94 & V_97 ) ;
}
F_53 ( V_8 , V_21 , V_39 ) ;
return V_85 ;
}
static bool F_64 ( struct V_7 * V_8 ,
union V_20 * V_21 )
{
T_6 V_98 = V_8 -> V_48 + 1 ;
V_98 = ( V_98 < V_8 -> V_25 ) ? V_98 : 0 ;
V_8 -> V_48 = V_98 ;
F_42 ( F_18 ( V_8 , V_98 ) ) ;
if ( F_11 ( F_48 ( V_21 , V_99 ) ) )
return false ;
return true ;
}
static bool F_65 ( struct V_7 * V_8 ,
union V_20 * V_21 ,
struct V_38 * V_39 )
{
if ( F_13 ( ( F_48 ( V_21 ,
V_100 ) ) ) ) {
#define F_66 ( T_7 , T_8 ) \
((rxd)->w.csum_err & cpu_to_le16(bit))
if ( F_66 ( V_21 , V_101 ) )
V_8 -> V_13 . V_102 ++ ;
if ( F_66 ( V_21 , V_103 ) )
V_8 -> V_13 . V_104 ++ ;
if ( F_66 ( V_21 , V_105 ) )
V_8 -> V_13 . V_106 ++ ;
if ( F_66 ( V_21 , V_107 ) )
V_8 -> V_13 . V_108 ++ ;
if ( F_66 ( V_21 , V_109 ) )
V_8 -> V_13 . V_110 ++ ;
F_67 ( V_39 ) ;
V_8 -> V_13 . V_111 ++ ;
return true ;
}
if ( F_68 ( V_39 ) )
return true ;
return false ;
}
static void F_69 ( struct V_112 * V_51 ,
struct V_38 * V_39 )
{
F_70 ( & V_51 -> V_52 , V_39 ) ;
}
static int F_71 ( struct V_112 * V_51 ,
struct V_7 * V_8 ,
int V_113 )
{
struct V_38 * V_39 = V_8 -> V_39 ;
unsigned int V_114 = 0 , V_115 = 0 ;
T_4 V_19 = F_72 ( V_8 ) ;
while ( F_11 ( V_115 < V_113 ) ) {
union V_20 * V_21 ;
if ( V_19 >= V_116 ) {
F_17 ( V_8 , V_19 ) ;
V_19 = 0 ;
}
V_21 = F_18 ( V_8 , V_8 -> V_48 ) ;
if ( ! V_21 -> V_28 . V_29 )
break;
F_73 () ;
V_39 = F_39 ( V_8 , V_21 , V_39 ) ;
if ( ! V_39 )
break;
V_19 ++ ;
if ( F_64 ( V_8 , V_21 ) )
continue;
if ( F_65 ( V_8 , V_21 , V_39 ) ) {
V_39 = NULL ;
continue;
}
V_114 += F_60 ( V_8 , V_21 , V_39 ) ;
F_69 ( V_51 , V_39 ) ;
V_39 = NULL ;
V_115 ++ ;
}
V_8 -> V_39 = V_39 ;
F_74 ( & V_8 -> V_117 ) ;
V_8 -> V_118 . V_119 += V_115 ;
V_8 -> V_118 . V_120 += V_114 ;
F_75 ( & V_8 -> V_117 ) ;
V_51 -> V_121 . V_115 += V_115 ;
V_51 -> V_121 . V_114 += V_114 ;
return V_115 ;
}
static struct V_122 * F_76 ( struct V_38 * V_39 )
{
struct V_123 * V_124 = F_58 ( V_39 -> V_15 ) ;
struct V_125 * V_126 ;
V_126 = F_77 ( & V_124 -> V_126 ,
struct V_125 , V_127 ) ;
if ( ! V_126 )
return NULL ;
if ( V_126 -> V_128 != F_78 ( V_39 ) -> V_129 )
return NULL ;
return (struct V_122 * ) ( F_79 ( V_39 ) + V_130 ) ;
}
static struct V_122 * F_80 ( struct V_38 * V_39 )
{
struct V_131 * V_132 ;
int V_133 = F_81 ( V_39 ) ;
if ( F_82 ( V_39 ) != F_63 ( V_134 ) )
return NULL ;
V_132 = (struct V_131 * ) ( F_83 ( V_39 ) + V_133 ) ;
if ( V_132 -> V_135 & V_136 )
return NULL ;
if ( V_132 -> V_135 & V_137 )
return (struct V_122 * ) ( V_132 + 1 ) ;
return (struct V_122 * ) ( & V_132 -> V_138 ) ;
}
T_9 F_84 ( struct V_38 * V_39 )
{
T_10 V_139 = 0 , V_140 = 0 , V_141 ;
struct V_122 * V_142 ;
if ( V_39 -> V_143 != V_144 ||
V_39 -> V_145 != F_63 ( V_146 ) )
return 0 ;
switch ( F_82 ( V_39 ) ) {
case F_63 ( V_134 ) :
V_139 = F_85 ( V_39 ) -> V_84 ;
break;
case F_63 ( V_147 ) :
V_139 = F_86 ( V_39 ) -> V_148 ;
break;
default:
return 0 ;
}
switch ( V_139 ) {
case V_149 :
V_142 = F_76 ( V_39 ) ;
break;
case V_150 :
V_142 = F_80 ( V_39 ) ;
break;
default:
return 0 ;
}
if ( ! V_142 )
return 0 ;
switch ( V_142 -> V_151 ) {
case F_63 ( V_134 ) :
V_140 = F_87 ( V_39 ) -> V_84 ;
break;
case F_63 ( V_147 ) :
V_140 = F_88 ( V_39 ) -> V_148 ;
break;
default:
return 0 ;
}
switch ( V_140 ) {
case V_152 :
V_141 = F_89 ( V_39 ) ;
break;
case V_149 :
V_141 = 8 ;
break;
default:
return 0 ;
}
if ( F_90 ( V_39 ) + V_141 -
F_91 ( V_39 ) > V_153 )
return 0 ;
return V_142 -> V_151 ;
}
static int F_92 ( struct V_7 * V_154 ,
struct V_155 * V_156 )
{
struct V_38 * V_39 = V_156 -> V_39 ;
struct V_157 * V_158 ;
unsigned char * V_159 ;
T_10 V_160 ;
if ( V_39 -> V_66 != V_161 )
return 0 ;
if ( ! F_93 ( V_39 ) )
return 0 ;
if ( V_39 -> V_64 ) {
if ( ! F_84 ( V_39 ) )
goto V_162;
V_159 = F_90 ( V_39 ) ;
} else {
V_159 = F_79 ( V_39 ) ;
}
V_160 = ( V_159 - V_39 -> V_53 ) + ( ( (struct V_163 * ) V_159 ) -> V_164 << 2 ) ;
V_156 -> V_165 |= V_166 ;
V_156 -> V_167 = F_38 ( V_39 ) -> V_167 ;
V_156 -> V_168 += ( V_156 -> V_167 - 1 ) * V_160 ;
V_158 = F_94 ( V_154 , V_154 -> V_23 ) ;
V_158 -> V_160 = V_160 ;
V_158 -> V_169 = F_59 ( F_38 ( V_39 ) -> V_170 ) ;
return 1 ;
V_162:
V_154 -> V_55 -> V_56 &= ~ V_171 ;
if ( ! F_95 () )
F_96 ( V_154 -> V_55 ,
L_4 ) ;
return - 1 ;
}
static void F_97 ( struct V_7 * V_154 ,
struct V_155 * V_156 )
{
struct V_38 * V_39 = V_156 -> V_39 ;
struct V_157 * V_158 ;
union {
struct V_172 * V_173 ;
struct V_174 * V_175 ;
T_10 * V_176 ;
} V_177 ;
T_10 * V_178 ;
T_9 V_179 ;
T_9 V_84 ;
T_10 V_139 = 0 ;
if ( V_39 -> V_66 != V_161 )
goto V_180;
if ( V_39 -> V_64 ) {
V_84 = F_84 ( V_39 ) ;
if ( ! V_84 ) {
if ( F_98 ( V_39 ) ) {
F_99 ( V_154 -> V_15 ,
L_5 ) ;
V_154 -> V_181 . V_62 ++ ;
}
goto V_180;
}
V_177 . V_176 = F_100 ( V_39 ) ;
V_178 = F_90 ( V_39 ) ;
} else {
V_84 = F_82 ( V_39 ) ;
V_177 . V_176 = F_83 ( V_39 ) ;
V_178 = F_79 ( V_39 ) ;
}
switch ( V_84 ) {
case F_63 ( V_134 ) :
V_139 = V_177 . V_173 -> V_84 ;
break;
case F_63 ( V_147 ) :
V_139 = V_177 . V_175 -> V_148 ;
if ( F_11 ( ( V_178 - V_177 . V_176 ) ==
sizeof( struct V_174 ) ) )
break;
F_101 ( V_39 , V_177 . V_176 - V_39 -> V_53 +
sizeof( struct V_174 ) ,
& V_139 , & V_179 ) ;
if ( F_13 ( V_179 ) )
V_139 = V_182 ;
break;
default:
break;
}
switch ( V_139 ) {
case V_152 :
case V_149 :
break;
case V_150 :
if ( V_39 -> V_64 )
break;
default:
if ( F_13 ( F_95 () ) ) {
F_99 ( V_154 -> V_15 ,
L_6 ,
V_84 , V_139 ) ;
}
F_98 ( V_39 ) ;
V_154 -> V_181 . V_62 ++ ;
goto V_180;
}
V_156 -> V_165 |= V_166 ;
V_154 -> V_181 . V_68 ++ ;
V_180:
V_158 = F_94 ( V_154 , V_154 -> V_23 ) ;
V_158 -> V_160 = 0 ;
V_158 -> V_169 = 0 ;
}
static T_10 F_102 ( struct V_38 * V_39 , T_6 V_165 )
{
T_6 V_183 = 0 ;
V_183 |= F_103 ( V_165 , V_166 ,
V_184 ) ;
return V_183 ;
}
static bool F_104 ( struct V_7 * V_154 ,
struct V_157 * V_158 , T_4 V_22 ,
T_3 V_12 , unsigned int V_37 , T_10 V_183 )
{
if ( ( ++ V_22 & ( V_185 - 1 ) ) == 0 )
V_183 |= V_186 | V_187 ;
V_158 -> V_188 = F_19 ( V_12 ) ;
V_158 -> V_135 = V_183 ;
V_158 -> V_189 = F_59 ( V_37 ) ;
return V_22 == V_154 -> V_25 ;
}
static int F_105 ( struct V_7 * V_154 , T_4 V_37 )
{
F_106 ( V_154 -> V_55 , V_154 -> V_92 ) ;
F_107 () ;
if ( F_11 ( F_72 ( V_154 ) < V_37 ) )
return - V_190 ;
F_108 ( V_154 -> V_55 , V_154 -> V_92 ) ;
++ V_154 -> V_181 . V_191 ;
return 0 ;
}
static inline int F_109 ( struct V_7 * V_154 , T_4 V_37 )
{
if ( F_11 ( F_72 ( V_154 ) >= V_37 ) )
return 0 ;
return F_105 ( V_154 , V_37 ) ;
}
static void F_110 ( struct V_7 * V_154 ,
struct V_155 * V_156 )
{
struct V_38 * V_39 = V_156 -> V_39 ;
struct V_155 * V_192 ;
struct V_157 * V_158 ;
struct V_193 * V_194 ;
unsigned char * V_53 ;
T_3 V_12 ;
unsigned int V_195 , V_37 ;
T_6 V_165 = V_156 -> V_165 ;
T_4 V_22 = V_154 -> V_23 ;
T_10 V_135 = F_102 ( V_39 , V_165 ) ;
V_158 = F_94 ( V_154 , V_22 ) ;
if ( F_111 ( V_39 ) )
V_158 -> V_91 = F_59 ( F_112 ( V_39 ) ) ;
else
V_158 -> V_91 = 0 ;
V_37 = F_113 ( V_39 ) ;
V_53 = V_39 -> V_53 ;
V_12 = F_114 ( V_154 -> V_15 , V_53 , V_37 , V_196 ) ;
V_195 = V_39 -> V_195 ;
V_192 = V_156 ;
for ( V_194 = & F_38 ( V_39 ) -> V_197 [ 0 ] ; ; V_194 ++ ) {
if ( F_15 ( V_154 -> V_15 , V_12 ) )
goto V_198;
F_115 ( V_192 , V_85 , V_37 ) ;
F_116 ( V_192 , V_12 , V_12 ) ;
while ( F_13 ( V_37 > V_199 ) ) {
if ( F_104 ( V_154 , V_158 ++ , V_22 ++ , V_12 ,
V_199 , V_135 ) ) {
V_158 = F_94 ( V_154 , 0 ) ;
V_22 = 0 ;
}
V_12 += V_199 ;
V_37 -= V_199 ;
}
if ( F_11 ( ! V_195 ) )
break;
if ( F_104 ( V_154 , V_158 ++ , V_22 ++ ,
V_12 , V_37 , V_135 ) ) {
V_158 = F_94 ( V_154 , 0 ) ;
V_22 = 0 ;
}
V_37 = F_117 ( V_194 ) ;
V_195 -= V_37 ;
V_12 = F_118 ( V_154 -> V_15 , V_194 , 0 , V_37 ,
V_196 ) ;
V_192 = & V_154 -> V_192 [ V_22 ] ;
}
V_135 |= V_200 ;
if ( F_104 ( V_154 , V_158 , V_22 ++ , V_12 , V_37 , V_135 ) )
V_22 = 0 ;
F_119 ( F_120 ( V_154 ) , V_156 -> V_168 ) ;
F_121 ( V_156 -> V_39 ) ;
F_20 () ;
V_156 -> V_201 = V_158 ;
V_154 -> V_23 = V_22 ;
F_109 ( V_154 , V_202 ) ;
if ( F_122 ( F_120 ( V_154 ) ) || ! V_39 -> V_203 ) {
F_21 ( V_22 , V_154 -> V_31 ) ;
F_123 () ;
}
return;
V_198:
F_124 ( V_154 -> V_15 , L_7 ) ;
for (; ; ) {
V_192 = & V_154 -> V_192 [ V_22 ] ;
F_125 ( V_154 , V_192 ) ;
if ( V_192 == V_156 )
break;
if ( V_22 == 0 )
V_22 = V_154 -> V_25 ;
V_22 -- ;
}
V_154 -> V_23 = V_22 ;
}
T_11 F_126 ( struct V_38 * V_39 ,
struct V_7 * V_154 )
{
T_4 V_25 = F_127 ( F_113 ( V_39 ) ) ;
struct V_155 * V_156 ;
unsigned short V_204 ;
T_6 V_165 = 0 ;
int V_205 ;
for ( V_204 = 0 ; V_204 < F_38 ( V_39 ) -> V_44 ; V_204 ++ )
V_25 += F_127 ( F_38 ( V_39 ) -> V_197 [ V_204 ] . V_37 ) ;
if ( F_109 ( V_154 , V_25 + 3 ) ) {
V_154 -> V_181 . V_206 ++ ;
return V_207 ;
}
V_156 = & V_154 -> V_192 [ V_154 -> V_23 ] ;
V_156 -> V_39 = V_39 ;
V_156 -> V_168 = F_128 (unsigned int, skb->len, ETH_ZLEN) ;
V_156 -> V_167 = 1 ;
V_156 -> V_165 = V_165 ;
V_205 = F_92 ( V_154 , V_156 ) ;
if ( V_205 < 0 )
goto V_208;
else if ( ! V_205 )
F_97 ( V_154 , V_156 ) ;
F_110 ( V_154 , V_156 ) ;
return V_209 ;
V_208:
F_67 ( V_156 -> V_39 ) ;
V_156 -> V_39 = NULL ;
return V_209 ;
}
static T_12 F_129 ( struct V_7 * V_54 )
{
return V_54 -> V_118 . V_119 ;
}
T_12 F_130 ( struct V_7 * V_54 , bool V_210 )
{
struct V_123 * V_124 = V_54 -> V_51 -> V_124 ;
struct V_211 * V_212 = & V_124 -> V_212 ;
T_6 V_213 , V_31 ;
if ( F_11 ( V_210 ) ) {
V_213 = V_54 -> V_48 ;
V_31 = V_54 -> V_23 ;
} else {
V_213 = F_131 ( V_212 , F_132 ( V_54 -> V_214 ) ) ;
V_31 = F_131 ( V_212 , F_133 ( V_54 -> V_214 ) ) ;
}
return ( ( V_213 <= V_31 ) ? V_31 : V_31 + V_54 -> V_25 ) - V_213 ;
}
bool F_134 ( struct V_7 * V_154 )
{
T_6 V_215 = F_129 ( V_154 ) ;
T_6 V_216 = V_154 -> V_181 . V_216 ;
T_6 V_217 = F_130 ( V_154 , true ) ;
F_135 ( V_154 ) ;
if ( ! V_217 || ( V_216 != V_215 ) ) {
V_154 -> V_181 . V_216 = V_215 ;
F_136 ( V_218 , V_154 -> V_219 ) ;
return false ;
}
return F_137 ( V_218 , V_154 -> V_219 ) ;
}
void F_138 ( struct V_123 * V_124 )
{
if ( ! F_139 ( V_220 , V_124 -> V_219 ) ) {
V_124 -> V_221 ++ ;
F_140 ( V_222 , V_124 -> V_135 ) ;
F_141 ( V_124 ) ;
}
}
static bool F_142 ( struct V_112 * V_51 ,
struct V_7 * V_154 , int V_223 )
{
struct V_123 * V_124 = V_51 -> V_124 ;
struct V_155 * V_192 ;
struct V_157 * V_158 ;
unsigned int V_114 = 0 , V_115 = 0 ;
unsigned int V_113 = V_51 -> V_224 . V_225 ;
unsigned int V_22 = V_154 -> V_48 ;
if ( F_139 ( V_220 , V_124 -> V_219 ) )
return true ;
V_192 = & V_154 -> V_192 [ V_22 ] ;
V_158 = F_94 ( V_154 , V_22 ) ;
V_22 -= V_154 -> V_25 ;
do {
struct V_157 * V_226 = V_192 -> V_201 ;
if ( ! V_226 )
break;
F_143 () ;
if ( ! ( V_226 -> V_135 & V_227 ) )
break;
V_192 -> V_201 = NULL ;
V_114 += V_192 -> V_168 ;
V_115 += V_192 -> V_167 ;
F_144 ( V_192 -> V_39 , V_223 ) ;
F_145 ( V_154 -> V_15 ,
F_146 ( V_192 , V_12 ) ,
F_147 ( V_192 , V_85 ) ,
V_196 ) ;
V_192 -> V_39 = NULL ;
F_115 ( V_192 , V_85 , 0 ) ;
while ( V_158 != V_226 ) {
V_192 ++ ;
V_158 ++ ;
V_22 ++ ;
if ( F_13 ( ! V_22 ) ) {
V_22 -= V_154 -> V_25 ;
V_192 = V_154 -> V_192 ;
V_158 = F_94 ( V_154 , 0 ) ;
}
if ( F_147 ( V_192 , V_85 ) ) {
F_45 ( V_154 -> V_15 ,
F_146 ( V_192 , V_12 ) ,
F_147 ( V_192 , V_85 ) ,
V_196 ) ;
F_115 ( V_192 , V_85 , 0 ) ;
}
}
V_192 ++ ;
V_158 ++ ;
V_22 ++ ;
if ( F_13 ( ! V_22 ) ) {
V_22 -= V_154 -> V_25 ;
V_192 = V_154 -> V_192 ;
V_158 = F_94 ( V_154 , 0 ) ;
}
F_42 ( V_158 ) ;
V_113 -- ;
} while ( F_11 ( V_113 ) );
V_22 += V_154 -> V_25 ;
V_154 -> V_48 = V_22 ;
F_74 ( & V_154 -> V_117 ) ;
V_154 -> V_118 . V_120 += V_114 ;
V_154 -> V_118 . V_119 += V_115 ;
F_75 ( & V_154 -> V_117 ) ;
V_51 -> V_224 . V_114 += V_114 ;
V_51 -> V_224 . V_115 += V_115 ;
if ( F_148 ( V_154 ) && F_134 ( V_154 ) ) {
struct V_211 * V_212 = & V_124 -> V_212 ;
F_149 ( V_124 , V_228 , V_154 -> V_55 ,
L_8
L_9
L_10
L_11
L_12 ,
V_154 -> V_92 ,
F_131 ( V_212 , F_132 ( V_154 -> V_214 ) ) ,
F_131 ( V_212 , F_133 ( V_154 -> V_214 ) ) ,
V_154 -> V_23 , V_22 ) ;
F_106 ( V_154 -> V_55 ,
V_154 -> V_92 ) ;
F_150 ( V_124 , V_229 , V_154 -> V_55 ,
L_13 ,
V_124 -> V_221 + 1 ,
V_154 -> V_92 ) ;
F_138 ( V_124 ) ;
return true ;
}
F_151 ( F_120 ( V_154 ) ,
V_115 , V_114 ) ;
#define F_152 min_t(u16, FM10K_MIN_TXD - 1, DESC_NEEDED * 2)
if ( F_13 ( V_115 && F_153 ( V_154 -> V_55 ) &&
( F_72 ( V_154 ) >= F_152 ) ) ) {
F_107 () ;
if ( F_154 ( V_154 -> V_55 ,
V_154 -> V_92 ) &&
! F_139 ( V_220 , V_124 -> V_219 ) ) {
F_155 ( V_154 -> V_55 ,
V_154 -> V_92 ) ;
++ V_154 -> V_181 . V_191 ;
}
}
return ! ! V_113 ;
}
static void F_156 ( struct V_230 * V_231 )
{
unsigned int V_232 , V_119 , V_233 ;
if ( ! F_157 ( V_231 -> V_234 ) )
goto V_235;
V_119 = V_231 -> V_115 ;
if ( ! V_119 )
goto V_235;
V_232 = V_231 -> V_114 / V_119 ;
if ( V_232 <= 360 ) {
V_232 *= 8 ;
V_232 += 376 ;
} else if ( V_232 <= 1152 ) {
V_232 *= 3 ;
V_232 += 2176 ;
} else if ( V_232 <= 1920 ) {
V_232 += 4480 ;
} else {
V_232 = 6656 ;
}
V_233 = F_158 ( V_231 -> V_236 ) + 8 ;
V_232 += F_52 ( V_233 ) - 1 ;
V_232 >>= V_233 ;
V_231 -> V_234 = V_232 | V_237 ;
V_235:
V_231 -> V_114 = 0 ;
V_231 -> V_115 = 0 ;
}
static void F_159 ( struct V_112 * V_51 )
{
T_6 V_234 = V_238 ;
F_156 ( & V_51 -> V_224 ) ;
F_156 ( & V_51 -> V_121 ) ;
V_234 |= ( V_51 -> V_224 . V_234 & V_239 ) ;
V_234 |= ( V_51 -> V_121 . V_234 & V_239 ) << V_240 ;
F_21 ( V_234 , V_51 -> V_234 ) ;
}
static int F_160 ( struct V_241 * V_52 , int V_113 )
{
struct V_112 * V_51 =
F_161 ( V_52 , struct V_112 , V_52 ) ;
struct V_7 * V_54 ;
int V_242 , V_243 = 0 ;
bool V_244 = true ;
F_162 (ring, q_vector->tx) {
if ( ! F_142 ( V_51 , V_54 , V_113 ) )
V_244 = false ;
}
if ( V_113 <= 0 )
return V_113 ;
if ( V_51 -> V_121 . V_25 > 1 )
V_242 = F_163 ( V_113 / V_51 -> V_121 . V_25 , 1 ) ;
else
V_242 = V_113 ;
F_162 (ring, q_vector->rx) {
int V_245 = F_71 ( V_51 , V_54 , V_242 ) ;
V_243 += V_245 ;
if ( V_245 >= V_242 )
V_244 = false ;
}
if ( ! V_244 )
return V_113 ;
F_164 ( V_52 , V_243 ) ;
F_159 ( V_51 ) ;
return F_165 ( V_243 , V_113 - 1 ) ;
}
static bool F_166 ( struct V_123 * V_124 )
{
struct V_77 * V_15 = V_124 -> V_55 ;
struct V_246 * V_204 ;
int V_247 , V_22 ;
int V_248 ;
V_248 = F_167 ( V_15 ) ;
if ( V_248 <= 1 )
return false ;
V_204 = & V_124 -> V_249 [ V_250 ] ;
V_204 -> V_251 = V_248 ;
V_204 -> V_252 = F_52 ( F_168 ( V_248 - 1 ) ) - 1 ;
V_247 = V_124 -> V_212 . V_253 . V_254 / V_248 ;
V_247 = F_52 ( F_168 ( V_247 ) - 1 ) ;
V_204 = & V_124 -> V_249 [ V_255 ] ;
V_247 = F_169 ( T_4 , V_247 , V_204 -> V_256 ) ;
V_204 -> V_251 = V_247 ;
V_204 -> V_252 = F_52 ( F_168 ( V_247 - 1 ) ) - 1 ;
for ( V_22 = 0 ; V_22 < V_248 ; V_22 ++ )
F_170 ( V_15 , V_22 , V_247 , V_247 * V_22 ) ;
V_124 -> V_257 = V_247 * V_248 ;
V_124 -> V_258 = V_247 * V_248 ;
return true ;
}
static bool F_171 ( struct V_123 * V_124 )
{
struct V_246 * V_204 ;
T_4 V_247 ;
V_204 = & V_124 -> V_249 [ V_255 ] ;
V_247 = F_169 ( T_4 , V_124 -> V_212 . V_253 . V_254 , V_204 -> V_256 ) ;
V_204 -> V_251 = V_247 ;
V_204 -> V_252 = F_52 ( F_168 ( V_247 - 1 ) ) - 1 ;
V_124 -> V_257 = V_247 ;
V_124 -> V_258 = V_247 ;
return true ;
}
static void F_172 ( struct V_123 * V_124 )
{
if ( F_166 ( V_124 ) )
return;
F_171 ( V_124 ) ;
}
static void F_173 ( struct V_123 * V_124 )
{
V_124 -> V_258 = 0 ;
V_124 -> V_257 = 0 ;
V_124 -> V_259 = 0 ;
}
static int F_174 ( struct V_123 * V_124 ,
unsigned int V_260 , unsigned int V_261 ,
unsigned int V_262 , unsigned int V_263 ,
unsigned int V_264 , unsigned int V_265 )
{
struct V_112 * V_51 ;
struct V_7 * V_54 ;
int V_266 , V_37 ;
V_266 = V_262 + V_264 ;
V_37 = sizeof( struct V_112 ) +
( sizeof( struct V_7 ) * V_266 ) ;
V_51 = F_175 ( V_37 , V_267 ) ;
if ( ! V_51 )
return - V_268 ;
F_176 ( V_124 -> V_55 , & V_51 -> V_52 ,
F_160 , V_269 ) ;
V_124 -> V_51 [ V_261 ] = V_51 ;
V_51 -> V_124 = V_124 ;
V_51 -> V_261 = V_261 ;
V_54 = V_51 -> V_54 ;
V_51 -> V_224 . V_54 = V_54 ;
V_51 -> V_224 . V_225 = V_270 ;
V_51 -> V_224 . V_234 = V_124 -> V_271 ;
V_51 -> V_224 . V_236 = V_124 -> V_212 . V_253 . V_236 ;
V_51 -> V_224 . V_25 = V_262 ;
while ( V_262 ) {
V_54 -> V_15 = & V_124 -> V_272 -> V_15 ;
V_54 -> V_55 = V_124 -> V_55 ;
V_54 -> V_51 = V_51 ;
V_54 -> V_25 = V_124 -> V_273 ;
V_54 -> V_92 = V_263 ;
V_124 -> V_154 [ V_263 ] = V_54 ;
V_262 -- ;
V_263 += V_260 ;
V_54 ++ ;
}
V_51 -> V_121 . V_54 = V_54 ;
V_51 -> V_121 . V_234 = V_124 -> V_274 ;
V_51 -> V_121 . V_236 = V_124 -> V_212 . V_253 . V_236 ;
V_51 -> V_121 . V_25 = V_264 ;
while ( V_264 ) {
V_54 -> V_15 = & V_124 -> V_272 -> V_15 ;
V_54 -> V_55 = V_124 -> V_55 ;
F_177 ( V_54 -> V_79 , V_124 -> V_79 ) ;
V_54 -> V_51 = V_51 ;
V_54 -> V_25 = V_124 -> V_275 ;
V_54 -> V_92 = V_265 ;
V_124 -> V_8 [ V_265 ] = V_54 ;
V_264 -- ;
V_265 += V_260 ;
V_54 ++ ;
}
F_178 ( V_51 ) ;
return 0 ;
}
static void F_179 ( struct V_123 * V_124 , int V_261 )
{
struct V_112 * V_51 = V_124 -> V_51 [ V_261 ] ;
struct V_7 * V_54 ;
F_180 ( V_51 ) ;
F_162 (ring, q_vector->tx)
V_124 -> V_154 [ V_54 -> V_92 ] = NULL ;
F_162 (ring, q_vector->rx)
V_124 -> V_8 [ V_54 -> V_92 ] = NULL ;
V_124 -> V_51 [ V_261 ] = NULL ;
F_181 ( & V_51 -> V_52 ) ;
F_182 ( V_51 , V_276 ) ;
}
static int F_183 ( struct V_123 * V_124 )
{
unsigned int V_277 = V_124 -> V_259 ;
unsigned int V_278 = V_124 -> V_257 ;
unsigned int V_279 = V_124 -> V_258 ;
unsigned int V_265 = 0 , V_263 = 0 , V_261 = 0 ;
int V_280 ;
if ( V_277 >= ( V_278 + V_279 ) ) {
for (; V_278 ; V_261 ++ ) {
V_280 = F_174 ( V_124 , V_277 , V_261 ,
0 , 0 , 1 , V_265 ) ;
if ( V_280 )
goto V_281;
V_278 -- ;
V_265 ++ ;
}
}
for (; V_261 < V_277 ; V_261 ++ ) {
int V_282 = F_184 ( V_278 , V_277 - V_261 ) ;
int V_283 = F_184 ( V_279 , V_277 - V_261 ) ;
V_280 = F_174 ( V_124 , V_277 , V_261 ,
V_283 , V_263 ,
V_282 , V_265 ) ;
if ( V_280 )
goto V_281;
V_278 -= V_282 ;
V_279 -= V_283 ;
V_265 ++ ;
V_263 ++ ;
}
return 0 ;
V_281:
F_173 ( V_124 ) ;
while ( V_261 -- )
F_179 ( V_124 , V_261 ) ;
return - V_268 ;
}
static void F_185 ( struct V_123 * V_124 )
{
int V_261 = V_124 -> V_259 ;
F_173 ( V_124 ) ;
while ( V_261 -- )
F_179 ( V_124 , V_261 ) ;
}
static void F_186 ( struct V_123 * V_124 )
{
F_187 ( V_124 -> V_272 ) ;
F_188 ( V_124 -> V_284 ) ;
V_124 -> V_284 = NULL ;
}
static int F_189 ( struct V_123 * V_124 )
{
struct V_211 * V_212 = & V_124 -> V_212 ;
int V_285 , V_286 ;
V_285 = F_163 ( V_124 -> V_257 , V_124 -> V_258 ) ;
V_285 = F_169 ( T_4 , V_285 , F_190 () ) ;
V_285 += F_191 ( V_212 ) ;
V_285 = F_169 ( int , V_285 , V_212 -> V_253 . V_287 ) ;
V_124 -> V_284 = F_192 ( V_285 , sizeof( struct V_288 ) ,
V_267 ) ;
if ( ! V_124 -> V_284 )
return - V_268 ;
for ( V_286 = 0 ; V_286 < V_285 ; V_286 ++ )
V_124 -> V_284 [ V_286 ] . V_289 = V_286 ;
V_285 = F_193 ( V_124 -> V_272 ,
V_124 -> V_284 ,
F_194 ( V_212 ) ,
V_285 ) ;
if ( V_285 < 0 ) {
F_188 ( V_124 -> V_284 ) ;
V_124 -> V_284 = NULL ;
return V_285 ;
}
V_124 -> V_259 = V_285 - F_191 ( V_212 ) ;
return 0 ;
}
static bool F_195 ( struct V_123 * V_124 )
{
struct V_77 * V_15 = V_124 -> V_55 ;
int V_290 , V_291 , V_247 , V_22 , V_292 ;
T_4 V_293 = V_124 -> V_249 [ V_250 ] . V_252 + 1 ;
T_10 V_294 = F_167 ( V_15 ) ;
if ( V_294 <= 1 )
return false ;
V_247 = V_124 -> V_249 [ V_255 ] . V_251 ;
for ( V_290 = 0 , V_291 = 0 ; V_290 < V_294 ; V_290 ++ , V_291 += V_247 ) {
V_292 = V_290 ;
for ( V_22 = 0 ; V_22 < V_247 ; V_22 ++ ) {
V_124 -> V_154 [ V_291 + V_22 ] -> V_214 = V_292 ;
V_124 -> V_154 [ V_291 + V_22 ] -> V_295 = V_290 ;
V_124 -> V_8 [ V_291 + V_22 ] -> V_214 = V_292 ;
V_124 -> V_8 [ V_291 + V_22 ] -> V_295 = V_290 ;
V_292 += V_293 ;
}
}
return true ;
}
static void F_196 ( struct V_123 * V_124 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_124 -> V_257 ; V_22 ++ )
V_124 -> V_8 [ V_22 ] -> V_214 = V_22 ;
for ( V_22 = 0 ; V_22 < V_124 -> V_258 ; V_22 ++ )
V_124 -> V_154 [ V_22 ] -> V_214 = V_22 ;
}
static void F_197 ( struct V_123 * V_124 )
{
if ( F_195 ( V_124 ) )
return;
F_196 ( V_124 ) ;
}
static void F_198 ( struct V_123 * V_124 )
{
T_4 V_22 , V_247 = V_124 -> V_249 [ V_255 ] . V_251 ;
T_6 V_296 ;
if ( F_199 ( V_124 -> V_55 ) ) {
for ( V_22 = V_297 ; V_22 -- ; ) {
V_296 = V_124 -> V_296 [ V_22 ] ;
if ( ( ( ( V_296 << 24 ) >> 24 ) < V_247 ) &&
( ( ( V_296 << 16 ) >> 24 ) < V_247 ) &&
( ( ( V_296 << 8 ) >> 24 ) < V_247 ) &&
( ( ( V_296 ) >> 24 ) < V_247 ) )
continue;
F_124 ( & V_124 -> V_272 -> V_15 ,
L_14 ) ;
goto V_298;
}
return;
}
V_298:
F_200 ( V_124 , NULL ) ;
}
int F_201 ( struct V_123 * V_124 )
{
int V_280 ;
F_172 ( V_124 ) ;
V_280 = F_189 ( V_124 ) ;
if ( V_280 ) {
F_124 ( & V_124 -> V_272 -> V_15 ,
L_15 ) ;
goto V_299;
}
V_280 = F_183 ( V_124 ) ;
if ( V_280 ) {
F_124 ( & V_124 -> V_272 -> V_15 ,
L_16 ) ;
goto V_300;
}
F_197 ( V_124 ) ;
F_198 ( V_124 ) ;
return 0 ;
V_300:
F_186 ( V_124 ) ;
V_299:
F_173 ( V_124 ) ;
return V_280 ;
}
void F_202 ( struct V_123 * V_124 )
{
F_185 ( V_124 ) ;
F_186 ( V_124 ) ;
}
