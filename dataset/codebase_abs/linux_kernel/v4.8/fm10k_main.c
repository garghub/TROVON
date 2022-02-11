static int T_1 F_1 ( void )
{
F_2 ( L_1 , V_1 , V_2 ) ;
F_2 ( L_2 , V_3 ) ;
V_4 = F_3 ( L_3 , V_5 , 0 ) ;
F_4 () ;
return F_5 () ;
}
static void T_2 F_6 ( void )
{
F_7 () ;
F_8 () ;
F_9 ( V_4 ) ;
}
static bool F_10 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_10 = V_9 -> V_10 ;
T_3 V_11 ;
if ( F_11 ( V_10 ) )
return true ;
V_10 = F_12 () ;
if ( F_13 ( ! V_10 ) ) {
V_7 -> V_12 . V_13 ++ ;
return false ;
}
V_11 = F_14 ( V_7 -> V_14 , V_10 , 0 , V_15 , V_16 ) ;
if ( F_15 ( V_7 -> V_14 , V_11 ) ) {
F_16 ( V_10 ) ;
V_7 -> V_12 . V_13 ++ ;
return false ;
}
V_9 -> V_11 = V_11 ;
V_9 -> V_10 = V_10 ;
V_9 -> V_17 = 0 ;
return true ;
}
void F_17 ( struct V_6 * V_7 , T_4 V_18 )
{
union V_19 * V_20 ;
struct V_8 * V_9 ;
T_4 V_21 = V_7 -> V_22 ;
if ( ! V_18 )
return;
V_20 = F_18 ( V_7 , V_21 ) ;
V_9 = & V_7 -> V_23 [ V_21 ] ;
V_21 -= V_7 -> V_24 ;
do {
if ( ! F_10 ( V_7 , V_9 ) )
break;
V_20 -> V_25 . V_26 = F_19 ( V_9 -> V_11 + V_9 -> V_17 ) ;
V_20 ++ ;
V_9 ++ ;
V_21 ++ ;
if ( F_13 ( ! V_21 ) ) {
V_20 = F_18 ( V_7 , 0 ) ;
V_9 = V_7 -> V_23 ;
V_21 -= V_7 -> V_24 ;
}
V_20 -> V_27 . V_28 = 0 ;
V_18 -- ;
} while ( V_18 );
V_21 += V_7 -> V_24 ;
if ( V_7 -> V_22 != V_21 ) {
V_7 -> V_22 = V_21 ;
V_7 -> V_29 = V_21 ;
F_20 () ;
F_21 ( V_21 , V_7 -> V_30 ) ;
}
}
static void F_22 ( struct V_6 * V_7 ,
struct V_8 * V_31 )
{
struct V_8 * V_32 ;
T_4 V_33 = V_7 -> V_29 ;
V_32 = & V_7 -> V_23 [ V_33 ] ;
V_33 ++ ;
V_7 -> V_29 = ( V_33 < V_7 -> V_24 ) ? V_33 : 0 ;
* V_32 = * V_31 ;
F_23 ( V_7 -> V_14 , V_31 -> V_11 ,
V_31 -> V_17 ,
V_34 ,
V_16 ) ;
}
static inline bool F_24 ( struct V_10 * V_10 )
{
return ( F_25 ( V_10 ) != F_26 () ) || F_27 ( V_10 ) ;
}
static bool F_28 ( struct V_8 * V_23 ,
struct V_10 * V_10 ,
unsigned int T_5 V_35 )
{
if ( F_13 ( F_24 ( V_10 ) ) )
return false ;
#if ( V_15 < 8192 )
if ( F_13 ( F_29 ( V_10 ) != 1 ) )
return false ;
V_23 -> V_17 ^= V_34 ;
#else
V_23 -> V_17 += V_35 ;
if ( V_23 -> V_17 > ( V_15 - V_34 ) )
return false ;
#endif
F_30 ( V_10 ) ;
return true ;
}
static bool F_31 ( struct V_8 * V_23 ,
union V_19 * V_20 ,
struct V_36 * V_37 )
{
struct V_10 * V_10 = V_23 -> V_10 ;
unsigned char * V_38 = F_32 ( V_10 ) + V_23 -> V_17 ;
unsigned int V_39 = F_33 ( V_20 -> V_40 . V_41 ) ;
#if ( V_15 < 8192 )
unsigned int V_35 = V_34 ;
#else
unsigned int V_35 = F_34 ( V_39 , 512 ) ;
#endif
unsigned int V_42 ;
if ( F_13 ( F_35 ( V_37 ) ) )
goto V_43;
if ( F_11 ( V_39 <= V_44 ) ) {
memcpy ( F_36 ( V_37 , V_39 ) , V_38 , F_34 ( V_39 , sizeof( long ) ) ) ;
if ( F_11 ( ! F_24 ( V_10 ) ) )
return true ;
F_16 ( V_10 ) ;
return false ;
}
V_42 = F_37 ( V_38 , V_44 ) ;
memcpy ( F_36 ( V_37 , V_42 ) , V_38 , F_34 ( V_42 , sizeof( long ) ) ) ;
V_38 += V_42 ;
V_39 -= V_42 ;
V_43:
F_38 ( V_37 , F_39 ( V_37 ) -> V_45 , V_10 ,
( unsigned long ) V_38 & ~ V_46 , V_39 , V_35 ) ;
return F_28 ( V_23 , V_10 , V_35 ) ;
}
static struct V_36 * F_40 ( struct V_6 * V_7 ,
union V_19 * V_20 ,
struct V_36 * V_37 )
{
struct V_8 * V_23 ;
struct V_10 * V_10 ;
V_23 = & V_7 -> V_23 [ V_7 -> V_47 ] ;
V_10 = V_23 -> V_10 ;
F_41 ( V_10 ) ;
if ( F_11 ( ! V_37 ) ) {
void * V_48 = F_32 ( V_10 ) +
V_23 -> V_17 ;
F_42 ( V_48 ) ;
#if V_49 < 128
F_42 ( V_48 + V_49 ) ;
#endif
V_37 = F_43 ( & V_7 -> V_50 -> V_51 ,
V_44 ) ;
if ( F_13 ( ! V_37 ) ) {
V_7 -> V_12 . V_13 ++ ;
return NULL ;
}
F_41 ( V_37 -> V_52 ) ;
}
F_44 ( V_7 -> V_14 ,
V_23 -> V_11 ,
V_23 -> V_17 ,
V_34 ,
V_16 ) ;
if ( F_31 ( V_23 , V_20 , V_37 ) ) {
F_22 ( V_7 , V_23 ) ;
} else {
F_45 ( V_7 -> V_14 , V_23 -> V_11 ,
V_15 , V_16 ) ;
}
V_23 -> V_10 = NULL ;
return V_37 ;
}
static inline void F_46 ( struct V_6 * V_53 ,
union V_19 * V_20 ,
struct V_36 * V_37 )
{
F_47 ( V_37 ) ;
if ( ! ( V_53 -> V_54 -> V_55 & V_56 ) )
return;
if ( F_48 ( V_20 ,
V_57 |
V_58 |
V_59 |
V_60 ) ) {
V_53 -> V_12 . V_61 ++ ;
return;
}
if ( F_48 ( V_20 , V_62 ) )
V_37 -> V_63 = true ;
else if ( ! F_48 ( V_20 , V_64 ) )
return;
V_37 -> V_65 = V_66 ;
V_53 -> V_12 . V_67 ++ ;
}
static inline void F_49 ( struct V_6 * V_53 ,
union V_19 * V_20 ,
struct V_36 * V_37 )
{
T_4 V_68 ;
if ( ! ( V_53 -> V_54 -> V_55 & V_69 ) )
return;
V_68 = F_33 ( V_20 -> V_40 . V_70 ) & V_71 ;
if ( ! V_68 )
return;
F_50 ( V_37 , F_51 ( V_20 -> V_27 . V_72 ) ,
( F_52 ( V_68 ) & V_73 ) ?
V_74 : V_75 ) ;
}
static void F_53 ( struct V_6 * V_7 ,
union V_19 T_5 * V_20 ,
struct V_36 * V_37 )
{
struct V_76 * V_14 = V_7 -> V_54 ;
struct V_77 * V_78 = F_54 ( V_7 -> V_78 ) ;
if ( V_78 ) {
T_4 V_79 = F_33 ( F_55 ( V_37 ) -> V_80 . V_40 . V_81 ) - 1 ;
V_79 -= V_78 -> V_81 ;
if ( V_79 < V_78 -> V_39 && V_78 -> V_82 [ V_79 ] )
V_14 = V_78 -> V_82 [ V_79 ] ;
else
V_78 = NULL ;
}
V_37 -> V_83 = F_56 ( V_37 , V_14 ) ;
if ( ! V_78 )
return;
F_57 ( F_58 ( V_14 ) , V_37 -> V_84 + V_85 , 1 ,
! ! ( V_20 -> V_40 . V_86 &
F_59 ( V_87 ) ) ) ;
}
static unsigned int F_60 ( struct V_6 * V_7 ,
union V_19 * V_20 ,
struct V_36 * V_37 )
{
unsigned int V_84 = V_37 -> V_84 ;
F_49 ( V_7 , V_20 , V_37 ) ;
F_46 ( V_7 , V_20 , V_37 ) ;
F_55 ( V_37 ) -> V_80 . V_40 . V_88 = V_20 -> V_40 . V_88 ;
F_61 ( V_37 , V_7 -> V_89 ) ;
F_55 ( V_37 ) -> V_80 . V_27 . V_90 = V_20 -> V_27 . V_90 ;
if ( V_20 -> V_40 . V_88 ) {
T_4 V_91 = F_33 ( V_20 -> V_40 . V_88 ) ;
if ( ( V_91 & V_92 ) != V_7 -> V_91 )
F_62 ( V_37 , F_63 ( V_93 ) , V_91 ) ;
else if ( V_91 & V_94 )
F_62 ( V_37 , F_63 ( V_93 ) ,
V_91 & V_94 ) ;
}
F_53 ( V_7 , V_20 , V_37 ) ;
return V_84 ;
}
static bool F_64 ( struct V_6 * V_7 ,
union V_19 * V_20 )
{
T_6 V_95 = V_7 -> V_47 + 1 ;
V_95 = ( V_95 < V_7 -> V_24 ) ? V_95 : 0 ;
V_7 -> V_47 = V_95 ;
F_42 ( F_18 ( V_7 , V_95 ) ) ;
if ( F_11 ( F_48 ( V_20 , V_96 ) ) )
return false ;
return true ;
}
static bool F_65 ( struct V_6 * V_7 ,
union V_19 * V_20 ,
struct V_36 * V_37 )
{
if ( F_13 ( ( F_48 ( V_20 ,
V_97 ) ) ) ) {
#define F_66 ( T_7 , T_8 ) \
((rxd)->w.csum_err & cpu_to_le16(bit))
if ( F_66 ( V_20 , V_98 ) )
V_7 -> V_12 . V_99 ++ ;
if ( F_66 ( V_20 , V_100 ) )
V_7 -> V_12 . V_101 ++ ;
if ( F_66 ( V_20 , V_102 ) )
V_7 -> V_12 . V_103 ++ ;
if ( F_66 ( V_20 , V_104 ) )
V_7 -> V_12 . V_105 ++ ;
if ( F_66 ( V_20 , V_106 ) )
V_7 -> V_12 . V_107 ++ ;
F_67 ( V_37 ) ;
V_7 -> V_12 . V_108 ++ ;
return true ;
}
if ( F_68 ( V_37 ) )
return true ;
return false ;
}
static void F_69 ( struct V_109 * V_50 ,
struct V_36 * V_37 )
{
F_70 ( & V_50 -> V_51 , V_37 ) ;
}
static int F_71 ( struct V_109 * V_50 ,
struct V_6 * V_7 ,
int V_110 )
{
struct V_36 * V_37 = V_7 -> V_37 ;
unsigned int V_111 = 0 , V_112 = 0 ;
T_4 V_18 = F_72 ( V_7 ) ;
while ( F_11 ( V_112 < V_110 ) ) {
union V_19 * V_20 ;
if ( V_18 >= V_113 ) {
F_17 ( V_7 , V_18 ) ;
V_18 = 0 ;
}
V_20 = F_18 ( V_7 , V_7 -> V_47 ) ;
if ( ! V_20 -> V_27 . V_28 )
break;
F_73 () ;
V_37 = F_40 ( V_7 , V_20 , V_37 ) ;
if ( ! V_37 )
break;
V_18 ++ ;
if ( F_64 ( V_7 , V_20 ) )
continue;
if ( F_65 ( V_7 , V_20 , V_37 ) ) {
V_37 = NULL ;
continue;
}
V_111 += F_60 ( V_7 , V_20 , V_37 ) ;
F_69 ( V_50 , V_37 ) ;
V_37 = NULL ;
V_112 ++ ;
}
V_7 -> V_37 = V_37 ;
F_74 ( & V_7 -> V_114 ) ;
V_7 -> V_115 . V_116 += V_112 ;
V_7 -> V_115 . V_117 += V_111 ;
F_75 ( & V_7 -> V_114 ) ;
V_50 -> V_118 . V_112 += V_112 ;
V_50 -> V_118 . V_111 += V_111 ;
return V_112 ;
}
static struct V_119 * F_76 ( struct V_36 * V_37 )
{
struct V_120 * V_121 = F_58 ( V_37 -> V_14 ) ;
struct V_122 * V_123 ;
V_123 = F_77 ( & V_121 -> V_123 ,
struct V_122 , V_124 ) ;
if ( ! V_123 )
return NULL ;
if ( V_123 -> V_125 != F_78 ( V_37 ) -> V_126 )
return NULL ;
return (struct V_119 * ) ( F_79 ( V_37 ) + V_127 ) ;
}
static struct V_119 * F_80 ( struct V_36 * V_37 )
{
struct V_128 * V_129 ;
int V_130 = F_81 ( V_37 ) ;
if ( F_82 ( V_37 ) != F_63 ( V_131 ) )
return NULL ;
V_129 = (struct V_128 * ) ( F_83 ( V_37 ) + V_130 ) ;
if ( V_129 -> V_132 & V_133 )
return NULL ;
if ( V_129 -> V_132 & V_134 )
return (struct V_119 * ) ( V_129 + 1 ) ;
return (struct V_119 * ) ( & V_129 -> V_135 ) ;
}
T_9 F_84 ( struct V_36 * V_37 )
{
T_10 V_136 = 0 , V_137 = 0 , V_138 ;
struct V_119 * V_139 ;
if ( V_37 -> V_140 != V_141 ||
V_37 -> V_142 != F_63 ( V_143 ) )
return 0 ;
switch ( F_82 ( V_37 ) ) {
case F_63 ( V_131 ) :
V_136 = F_85 ( V_37 ) -> V_83 ;
break;
case F_63 ( V_144 ) :
V_136 = F_86 ( V_37 ) -> V_145 ;
break;
default:
return 0 ;
}
switch ( V_136 ) {
case V_146 :
V_139 = F_76 ( V_37 ) ;
break;
case V_147 :
V_139 = F_80 ( V_37 ) ;
break;
default:
return 0 ;
}
if ( ! V_139 )
return 0 ;
switch ( V_139 -> V_148 ) {
case F_63 ( V_131 ) :
V_137 = F_87 ( V_37 ) -> V_83 ;
break;
case F_63 ( V_144 ) :
V_137 = F_88 ( V_37 ) -> V_145 ;
break;
default:
return 0 ;
}
switch ( V_137 ) {
case V_149 :
V_138 = F_89 ( V_37 ) ;
break;
case V_146 :
V_138 = 8 ;
break;
default:
return 0 ;
}
if ( F_90 ( V_37 ) + V_138 -
F_91 ( V_37 ) > V_150 )
return 0 ;
return V_139 -> V_148 ;
}
static int F_92 ( struct V_6 * V_151 ,
struct V_152 * V_153 )
{
struct V_36 * V_37 = V_153 -> V_37 ;
struct V_154 * V_155 ;
unsigned char * V_156 ;
T_10 V_157 ;
if ( V_37 -> V_65 != V_158 )
return 0 ;
if ( ! F_93 ( V_37 ) )
return 0 ;
if ( V_37 -> V_63 ) {
if ( ! F_84 ( V_37 ) )
goto V_159;
V_156 = F_90 ( V_37 ) ;
} else {
V_156 = F_79 ( V_37 ) ;
}
V_157 = ( V_156 - V_37 -> V_52 ) + ( ( (struct V_160 * ) V_156 ) -> V_161 << 2 ) ;
V_153 -> V_162 |= V_163 ;
V_153 -> V_164 = F_39 ( V_37 ) -> V_164 ;
V_153 -> V_165 += ( V_153 -> V_164 - 1 ) * V_157 ;
V_155 = F_94 ( V_151 , V_151 -> V_22 ) ;
V_155 -> V_157 = V_157 ;
V_155 -> V_166 = F_59 ( F_39 ( V_37 ) -> V_167 ) ;
return 1 ;
V_159:
V_151 -> V_54 -> V_55 &= ~ V_168 ;
if ( ! F_95 () )
F_96 ( V_151 -> V_54 ,
L_4 ) ;
return - 1 ;
}
static void F_97 ( struct V_6 * V_151 ,
struct V_152 * V_153 )
{
struct V_36 * V_37 = V_153 -> V_37 ;
struct V_154 * V_155 ;
union {
struct V_169 * V_170 ;
struct V_171 * V_172 ;
T_10 * V_173 ;
} V_174 ;
T_10 * V_175 ;
T_9 V_176 ;
T_9 V_83 ;
T_10 V_136 = 0 ;
if ( V_37 -> V_65 != V_158 )
goto V_177;
if ( V_37 -> V_63 ) {
V_83 = F_84 ( V_37 ) ;
if ( ! V_83 ) {
if ( F_98 ( V_37 ) ) {
F_99 ( V_151 -> V_14 ,
L_5 ) ;
V_151 -> V_178 . V_61 ++ ;
}
goto V_177;
}
V_174 . V_173 = F_100 ( V_37 ) ;
V_175 = F_90 ( V_37 ) ;
} else {
V_83 = F_82 ( V_37 ) ;
V_174 . V_173 = F_83 ( V_37 ) ;
V_175 = F_79 ( V_37 ) ;
}
switch ( V_83 ) {
case F_63 ( V_131 ) :
V_136 = V_174 . V_170 -> V_83 ;
break;
case F_63 ( V_144 ) :
V_136 = V_174 . V_172 -> V_145 ;
if ( F_11 ( ( V_175 - V_174 . V_173 ) ==
sizeof( struct V_171 ) ) )
break;
F_101 ( V_37 , V_174 . V_173 - V_37 -> V_52 +
sizeof( struct V_171 ) ,
& V_136 , & V_176 ) ;
if ( F_13 ( V_176 ) )
V_136 = V_179 ;
break;
default:
break;
}
switch ( V_136 ) {
case V_149 :
case V_146 :
break;
case V_147 :
if ( V_37 -> V_63 )
break;
default:
if ( F_13 ( F_95 () ) ) {
F_99 ( V_151 -> V_14 ,
L_6 ,
V_83 , V_136 ) ;
}
F_98 ( V_37 ) ;
V_151 -> V_178 . V_61 ++ ;
goto V_177;
}
V_153 -> V_162 |= V_163 ;
V_151 -> V_178 . V_67 ++ ;
V_177:
V_155 = F_94 ( V_151 , V_151 -> V_22 ) ;
V_155 -> V_157 = 0 ;
V_155 -> V_166 = 0 ;
}
static T_10 F_102 ( struct V_36 * V_37 , T_6 V_162 )
{
T_6 V_180 = 0 ;
V_180 |= F_103 ( V_162 , V_163 ,
V_181 ) ;
return V_180 ;
}
static bool F_104 ( struct V_6 * V_151 ,
struct V_154 * V_155 , T_4 V_21 ,
T_3 V_11 , unsigned int V_39 , T_10 V_180 )
{
if ( ( ++ V_21 & ( V_182 - 1 ) ) == 0 )
V_180 |= V_183 | V_184 ;
V_155 -> V_185 = F_19 ( V_11 ) ;
V_155 -> V_132 = V_180 ;
V_155 -> V_186 = F_59 ( V_39 ) ;
return V_21 == V_151 -> V_24 ;
}
static int F_105 ( struct V_6 * V_151 , T_4 V_39 )
{
F_106 ( V_151 -> V_54 , V_151 -> V_89 ) ;
F_107 () ;
if ( F_11 ( F_72 ( V_151 ) < V_39 ) )
return - V_187 ;
F_108 ( V_151 -> V_54 , V_151 -> V_89 ) ;
++ V_151 -> V_178 . V_188 ;
return 0 ;
}
static inline int F_109 ( struct V_6 * V_151 , T_4 V_39 )
{
if ( F_11 ( F_72 ( V_151 ) >= V_39 ) )
return 0 ;
return F_105 ( V_151 , V_39 ) ;
}
static void F_110 ( struct V_6 * V_151 ,
struct V_152 * V_153 )
{
struct V_36 * V_37 = V_153 -> V_37 ;
struct V_152 * V_189 ;
struct V_154 * V_155 ;
struct V_190 * V_191 ;
unsigned char * V_52 ;
T_3 V_11 ;
unsigned int V_192 , V_39 ;
T_6 V_162 = V_153 -> V_162 ;
T_4 V_21 = V_151 -> V_22 ;
T_10 V_132 = F_102 ( V_37 , V_162 ) ;
V_155 = F_94 ( V_151 , V_21 ) ;
if ( F_111 ( V_37 ) )
V_155 -> V_88 = F_59 ( F_112 ( V_37 ) ) ;
else
V_155 -> V_88 = 0 ;
V_39 = F_113 ( V_37 ) ;
V_52 = V_37 -> V_52 ;
V_11 = F_114 ( V_151 -> V_14 , V_52 , V_39 , V_193 ) ;
V_192 = V_37 -> V_192 ;
V_189 = V_153 ;
for ( V_191 = & F_39 ( V_37 ) -> V_194 [ 0 ] ; ; V_191 ++ ) {
if ( F_15 ( V_151 -> V_14 , V_11 ) )
goto V_195;
F_115 ( V_189 , V_84 , V_39 ) ;
F_116 ( V_189 , V_11 , V_11 ) ;
while ( F_13 ( V_39 > V_196 ) ) {
if ( F_104 ( V_151 , V_155 ++ , V_21 ++ , V_11 ,
V_196 , V_132 ) ) {
V_155 = F_94 ( V_151 , 0 ) ;
V_21 = 0 ;
}
V_11 += V_196 ;
V_39 -= V_196 ;
}
if ( F_11 ( ! V_192 ) )
break;
if ( F_104 ( V_151 , V_155 ++ , V_21 ++ ,
V_11 , V_39 , V_132 ) ) {
V_155 = F_94 ( V_151 , 0 ) ;
V_21 = 0 ;
}
V_39 = F_117 ( V_191 ) ;
V_192 -= V_39 ;
V_11 = F_118 ( V_151 -> V_14 , V_191 , 0 , V_39 ,
V_193 ) ;
V_189 = & V_151 -> V_189 [ V_21 ] ;
}
V_132 |= V_197 ;
if ( F_104 ( V_151 , V_155 , V_21 ++ , V_11 , V_39 , V_132 ) )
V_21 = 0 ;
F_119 ( F_120 ( V_151 ) , V_153 -> V_165 ) ;
F_121 ( V_153 -> V_37 ) ;
F_20 () ;
V_153 -> V_198 = V_155 ;
V_151 -> V_22 = V_21 ;
F_109 ( V_151 , V_199 ) ;
if ( F_122 ( F_120 ( V_151 ) ) || ! V_37 -> V_200 ) {
F_21 ( V_21 , V_151 -> V_30 ) ;
F_123 () ;
}
return;
V_195:
F_124 ( V_151 -> V_14 , L_7 ) ;
for (; ; ) {
V_189 = & V_151 -> V_189 [ V_21 ] ;
F_125 ( V_151 , V_189 ) ;
if ( V_189 == V_153 )
break;
if ( V_21 == 0 )
V_21 = V_151 -> V_24 ;
V_21 -- ;
}
V_151 -> V_22 = V_21 ;
}
T_11 F_126 ( struct V_36 * V_37 ,
struct V_6 * V_151 )
{
T_4 V_24 = F_127 ( F_113 ( V_37 ) ) ;
struct V_152 * V_153 ;
unsigned short V_201 ;
T_6 V_162 = 0 ;
int V_202 ;
for ( V_201 = 0 ; V_201 < F_39 ( V_37 ) -> V_45 ; V_201 ++ )
V_24 += F_127 ( F_39 ( V_37 ) -> V_194 [ V_201 ] . V_39 ) ;
if ( F_109 ( V_151 , V_24 + 3 ) ) {
V_151 -> V_178 . V_203 ++ ;
return V_204 ;
}
V_153 = & V_151 -> V_189 [ V_151 -> V_22 ] ;
V_153 -> V_37 = V_37 ;
V_153 -> V_165 = F_128 (unsigned int, skb->len, ETH_ZLEN) ;
V_153 -> V_164 = 1 ;
V_153 -> V_162 = V_162 ;
V_202 = F_92 ( V_151 , V_153 ) ;
if ( V_202 < 0 )
goto V_205;
else if ( ! V_202 )
F_97 ( V_151 , V_153 ) ;
F_110 ( V_151 , V_153 ) ;
return V_206 ;
V_205:
F_67 ( V_153 -> V_37 ) ;
V_153 -> V_37 = NULL ;
return V_206 ;
}
static T_12 F_129 ( struct V_6 * V_53 )
{
return V_53 -> V_115 . V_116 ;
}
T_12 F_130 ( struct V_6 * V_53 )
{
struct V_120 * V_121 = V_53 -> V_50 -> V_121 ;
struct V_207 * V_208 = & V_121 -> V_208 ;
T_6 V_209 = F_131 ( V_208 , F_132 ( V_53 -> V_210 ) ) ;
T_6 V_30 = F_131 ( V_208 , F_133 ( V_53 -> V_210 ) ) ;
return ( ( V_209 <= V_30 ) ? V_30 : V_30 + V_53 -> V_24 ) - V_209 ;
}
bool F_134 ( struct V_6 * V_151 )
{
T_6 V_211 = F_129 ( V_151 ) ;
T_6 V_212 = V_151 -> V_178 . V_212 ;
T_6 V_213 = F_130 ( V_151 ) ;
F_135 ( V_151 ) ;
if ( ! V_213 || ( V_212 != V_211 ) ) {
V_151 -> V_178 . V_212 = V_211 ;
F_136 ( V_214 , & V_151 -> V_215 ) ;
return false ;
}
return F_137 ( V_214 , & V_151 -> V_215 ) ;
}
void F_138 ( struct V_120 * V_121 )
{
if ( ! F_139 ( V_216 , & V_121 -> V_215 ) ) {
V_121 -> V_217 ++ ;
V_121 -> V_132 |= V_218 ;
F_140 ( V_121 ) ;
}
}
static bool F_141 ( struct V_109 * V_50 ,
struct V_6 * V_151 , int V_219 )
{
struct V_120 * V_121 = V_50 -> V_121 ;
struct V_152 * V_189 ;
struct V_154 * V_155 ;
unsigned int V_111 = 0 , V_112 = 0 ;
unsigned int V_110 = V_50 -> V_220 . V_221 ;
unsigned int V_21 = V_151 -> V_47 ;
if ( F_139 ( V_216 , & V_121 -> V_215 ) )
return true ;
V_189 = & V_151 -> V_189 [ V_21 ] ;
V_155 = F_94 ( V_151 , V_21 ) ;
V_21 -= V_151 -> V_24 ;
do {
struct V_154 * V_222 = V_189 -> V_198 ;
if ( ! V_222 )
break;
F_142 () ;
if ( ! ( V_222 -> V_132 & V_223 ) )
break;
V_189 -> V_198 = NULL ;
V_111 += V_189 -> V_165 ;
V_112 += V_189 -> V_164 ;
F_143 ( V_189 -> V_37 , V_219 ) ;
F_144 ( V_151 -> V_14 ,
F_145 ( V_189 , V_11 ) ,
F_146 ( V_189 , V_84 ) ,
V_193 ) ;
V_189 -> V_37 = NULL ;
F_115 ( V_189 , V_84 , 0 ) ;
while ( V_155 != V_222 ) {
V_189 ++ ;
V_155 ++ ;
V_21 ++ ;
if ( F_13 ( ! V_21 ) ) {
V_21 -= V_151 -> V_24 ;
V_189 = V_151 -> V_189 ;
V_155 = F_94 ( V_151 , 0 ) ;
}
if ( F_146 ( V_189 , V_84 ) ) {
F_45 ( V_151 -> V_14 ,
F_145 ( V_189 , V_11 ) ,
F_146 ( V_189 , V_84 ) ,
V_193 ) ;
F_115 ( V_189 , V_84 , 0 ) ;
}
}
V_189 ++ ;
V_155 ++ ;
V_21 ++ ;
if ( F_13 ( ! V_21 ) ) {
V_21 -= V_151 -> V_24 ;
V_189 = V_151 -> V_189 ;
V_155 = F_94 ( V_151 , 0 ) ;
}
F_42 ( V_155 ) ;
V_110 -- ;
} while ( F_11 ( V_110 ) );
V_21 += V_151 -> V_24 ;
V_151 -> V_47 = V_21 ;
F_74 ( & V_151 -> V_114 ) ;
V_151 -> V_115 . V_117 += V_111 ;
V_151 -> V_115 . V_116 += V_112 ;
F_75 ( & V_151 -> V_114 ) ;
V_50 -> V_220 . V_111 += V_111 ;
V_50 -> V_220 . V_112 += V_112 ;
if ( F_147 ( V_151 ) && F_134 ( V_151 ) ) {
struct V_207 * V_208 = & V_121 -> V_208 ;
F_148 ( V_121 , V_224 , V_151 -> V_54 ,
L_8
L_9
L_10
L_11
L_12 ,
V_151 -> V_89 ,
F_131 ( V_208 , F_132 ( V_151 -> V_210 ) ) ,
F_131 ( V_208 , F_133 ( V_151 -> V_210 ) ) ,
V_151 -> V_22 , V_21 ) ;
F_106 ( V_151 -> V_54 ,
V_151 -> V_89 ) ;
F_149 ( V_121 , V_225 , V_151 -> V_54 ,
L_13 ,
V_121 -> V_217 + 1 ,
V_151 -> V_89 ) ;
F_138 ( V_121 ) ;
return true ;
}
F_150 ( F_120 ( V_151 ) ,
V_112 , V_111 ) ;
#define F_151 min_t(u16, FM10K_MIN_TXD - 1, DESC_NEEDED * 2)
if ( F_13 ( V_112 && F_152 ( V_151 -> V_54 ) &&
( F_72 ( V_151 ) >= F_151 ) ) ) {
F_107 () ;
if ( F_153 ( V_151 -> V_54 ,
V_151 -> V_89 ) &&
! F_139 ( V_216 , & V_121 -> V_215 ) ) {
F_154 ( V_151 -> V_54 ,
V_151 -> V_89 ) ;
++ V_151 -> V_178 . V_188 ;
}
}
return ! ! V_110 ;
}
static void F_155 ( struct V_226 * V_227 )
{
unsigned int V_228 , V_116 , V_229 ;
if ( ! F_156 ( V_227 -> V_230 ) )
goto V_231;
V_116 = V_227 -> V_112 ;
if ( ! V_116 )
goto V_231;
V_228 = V_227 -> V_111 / V_116 ;
if ( V_228 <= 360 ) {
V_228 *= 8 ;
V_228 += 376 ;
} else if ( V_228 <= 1152 ) {
V_228 *= 3 ;
V_228 += 2176 ;
} else if ( V_228 <= 1920 ) {
V_228 += 4480 ;
} else {
V_228 = 6656 ;
}
V_229 = F_157 ( V_227 -> V_232 ) + 8 ;
V_228 += F_52 ( V_229 ) - 1 ;
V_228 >>= V_229 ;
V_227 -> V_230 = V_228 | V_233 ;
V_231:
V_227 -> V_111 = 0 ;
V_227 -> V_112 = 0 ;
}
static void F_158 ( struct V_109 * V_50 )
{
T_6 V_230 = V_234 ;
F_155 ( & V_50 -> V_220 ) ;
F_155 ( & V_50 -> V_118 ) ;
V_230 |= ( V_50 -> V_220 . V_230 & V_235 ) ;
V_230 |= ( V_50 -> V_118 . V_230 & V_235 ) << V_236 ;
F_21 ( V_230 , V_50 -> V_230 ) ;
}
static int F_159 ( struct V_237 * V_51 , int V_110 )
{
struct V_109 * V_50 =
F_160 ( V_51 , struct V_109 , V_51 ) ;
struct V_6 * V_53 ;
int V_238 , V_239 = 0 ;
bool V_240 = true ;
F_161 (ring, q_vector->tx) {
if ( ! F_141 ( V_50 , V_53 , V_110 ) )
V_240 = false ;
}
if ( V_110 <= 0 )
return V_110 ;
if ( V_50 -> V_118 . V_24 > 1 )
V_238 = F_162 ( V_110 / V_50 -> V_118 . V_24 , 1 ) ;
else
V_238 = V_110 ;
F_161 (ring, q_vector->rx) {
int V_241 = F_71 ( V_50 , V_53 , V_238 ) ;
V_239 += V_241 ;
if ( V_241 >= V_238 )
V_240 = false ;
}
if ( ! V_240 )
return V_110 ;
F_163 ( V_51 , V_239 ) ;
F_158 ( V_50 ) ;
return 0 ;
}
static bool F_164 ( struct V_120 * V_121 )
{
struct V_76 * V_14 = V_121 -> V_54 ;
struct V_242 * V_201 ;
int V_243 , V_21 ;
int V_244 ;
V_244 = F_165 ( V_14 ) ;
if ( V_244 <= 1 )
return false ;
V_201 = & V_121 -> V_245 [ V_246 ] ;
V_201 -> V_247 = V_244 ;
V_201 -> V_248 = F_52 ( F_166 ( V_244 - 1 ) ) - 1 ;
V_243 = V_121 -> V_208 . V_249 . V_250 / V_244 ;
V_243 = F_52 ( F_166 ( V_243 ) - 1 ) ;
V_201 = & V_121 -> V_245 [ V_251 ] ;
V_243 = F_167 ( T_4 , V_243 , V_201 -> V_252 ) ;
V_201 -> V_247 = V_243 ;
V_201 -> V_248 = F_52 ( F_166 ( V_243 - 1 ) ) - 1 ;
for ( V_21 = 0 ; V_21 < V_244 ; V_21 ++ )
F_168 ( V_14 , V_21 , V_243 , V_243 * V_21 ) ;
V_121 -> V_253 = V_243 * V_244 ;
V_121 -> V_254 = V_243 * V_244 ;
return true ;
}
static bool F_169 ( struct V_120 * V_121 )
{
struct V_242 * V_201 ;
T_4 V_243 ;
V_201 = & V_121 -> V_245 [ V_251 ] ;
V_243 = F_167 ( T_4 , V_121 -> V_208 . V_249 . V_250 , V_201 -> V_252 ) ;
V_201 -> V_247 = V_243 ;
V_201 -> V_248 = F_52 ( F_166 ( V_243 - 1 ) ) - 1 ;
V_121 -> V_253 = V_243 ;
V_121 -> V_254 = V_243 ;
return true ;
}
static void F_170 ( struct V_120 * V_121 )
{
if ( F_164 ( V_121 ) )
return;
F_169 ( V_121 ) ;
}
static void F_171 ( struct V_120 * V_121 )
{
V_121 -> V_254 = 0 ;
V_121 -> V_253 = 0 ;
V_121 -> V_255 = 0 ;
}
static int F_172 ( struct V_120 * V_121 ,
unsigned int V_256 , unsigned int V_257 ,
unsigned int V_258 , unsigned int V_259 ,
unsigned int V_260 , unsigned int V_261 )
{
struct V_109 * V_50 ;
struct V_6 * V_53 ;
int V_262 , V_39 ;
V_262 = V_258 + V_260 ;
V_39 = sizeof( struct V_109 ) +
( sizeof( struct V_6 ) * V_262 ) ;
V_50 = F_173 ( V_39 , V_263 ) ;
if ( ! V_50 )
return - V_264 ;
F_174 ( V_121 -> V_54 , & V_50 -> V_51 ,
F_159 , V_265 ) ;
V_121 -> V_50 [ V_257 ] = V_50 ;
V_50 -> V_121 = V_121 ;
V_50 -> V_257 = V_257 ;
V_53 = V_50 -> V_53 ;
V_50 -> V_220 . V_53 = V_53 ;
V_50 -> V_220 . V_221 = V_266 ;
V_50 -> V_220 . V_230 = V_121 -> V_267 ;
V_50 -> V_220 . V_232 = V_121 -> V_208 . V_249 . V_232 ;
V_50 -> V_220 . V_24 = V_258 ;
while ( V_258 ) {
V_53 -> V_14 = & V_121 -> V_268 -> V_14 ;
V_53 -> V_54 = V_121 -> V_54 ;
V_53 -> V_50 = V_50 ;
V_53 -> V_24 = V_121 -> V_269 ;
V_53 -> V_89 = V_259 ;
V_121 -> V_151 [ V_259 ] = V_53 ;
V_258 -- ;
V_259 += V_256 ;
V_53 ++ ;
}
V_50 -> V_118 . V_53 = V_53 ;
V_50 -> V_118 . V_230 = V_121 -> V_270 ;
V_50 -> V_118 . V_232 = V_121 -> V_208 . V_249 . V_232 ;
V_50 -> V_118 . V_24 = V_260 ;
while ( V_260 ) {
V_53 -> V_14 = & V_121 -> V_268 -> V_14 ;
V_53 -> V_54 = V_121 -> V_54 ;
F_175 ( V_53 -> V_78 , V_121 -> V_78 ) ;
V_53 -> V_50 = V_50 ;
V_53 -> V_24 = V_121 -> V_271 ;
V_53 -> V_89 = V_261 ;
V_121 -> V_7 [ V_261 ] = V_53 ;
V_260 -- ;
V_261 += V_256 ;
V_53 ++ ;
}
F_176 ( V_50 ) ;
return 0 ;
}
static void F_177 ( struct V_120 * V_121 , int V_257 )
{
struct V_109 * V_50 = V_121 -> V_50 [ V_257 ] ;
struct V_6 * V_53 ;
F_178 ( V_50 ) ;
F_161 (ring, q_vector->tx)
V_121 -> V_151 [ V_53 -> V_89 ] = NULL ;
F_161 (ring, q_vector->rx)
V_121 -> V_7 [ V_53 -> V_89 ] = NULL ;
V_121 -> V_50 [ V_257 ] = NULL ;
F_179 ( & V_50 -> V_51 ) ;
F_180 ( V_50 , V_272 ) ;
}
static int F_181 ( struct V_120 * V_121 )
{
unsigned int V_273 = V_121 -> V_255 ;
unsigned int V_274 = V_121 -> V_253 ;
unsigned int V_275 = V_121 -> V_254 ;
unsigned int V_261 = 0 , V_259 = 0 , V_257 = 0 ;
int V_276 ;
if ( V_273 >= ( V_274 + V_275 ) ) {
for (; V_274 ; V_257 ++ ) {
V_276 = F_172 ( V_121 , V_273 , V_257 ,
0 , 0 , 1 , V_261 ) ;
if ( V_276 )
goto V_277;
V_274 -- ;
V_261 ++ ;
}
}
for (; V_257 < V_273 ; V_257 ++ ) {
int V_278 = F_182 ( V_274 , V_273 - V_257 ) ;
int V_279 = F_182 ( V_275 , V_273 - V_257 ) ;
V_276 = F_172 ( V_121 , V_273 , V_257 ,
V_279 , V_259 ,
V_278 , V_261 ) ;
if ( V_276 )
goto V_277;
V_274 -= V_278 ;
V_275 -= V_279 ;
V_261 ++ ;
V_259 ++ ;
}
return 0 ;
V_277:
F_171 ( V_121 ) ;
while ( V_257 -- )
F_177 ( V_121 , V_257 ) ;
return - V_264 ;
}
static void F_183 ( struct V_120 * V_121 )
{
int V_257 = V_121 -> V_255 ;
F_171 ( V_121 ) ;
while ( V_257 -- )
F_177 ( V_121 , V_257 ) ;
}
static void F_184 ( struct V_120 * V_121 )
{
F_185 ( V_121 -> V_268 ) ;
F_186 ( V_121 -> V_280 ) ;
V_121 -> V_280 = NULL ;
}
static int F_187 ( struct V_120 * V_121 )
{
struct V_207 * V_208 = & V_121 -> V_208 ;
int V_281 , V_282 ;
V_281 = F_162 ( V_121 -> V_253 , V_121 -> V_254 ) ;
V_281 = F_167 ( T_4 , V_281 , F_188 () ) ;
V_281 += F_189 ( V_208 ) ;
V_281 = F_167 ( int , V_281 , V_208 -> V_249 . V_283 ) ;
V_121 -> V_280 = F_190 ( V_281 , sizeof( struct V_284 ) ,
V_263 ) ;
if ( ! V_121 -> V_280 )
return - V_264 ;
for ( V_282 = 0 ; V_282 < V_281 ; V_282 ++ )
V_121 -> V_280 [ V_282 ] . V_285 = V_282 ;
V_281 = F_191 ( V_121 -> V_268 ,
V_121 -> V_280 ,
F_192 ( V_208 ) ,
V_281 ) ;
if ( V_281 < 0 ) {
F_186 ( V_121 -> V_280 ) ;
V_121 -> V_280 = NULL ;
return V_281 ;
}
V_121 -> V_255 = V_281 - F_189 ( V_208 ) ;
return 0 ;
}
static bool F_193 ( struct V_120 * V_121 )
{
struct V_76 * V_14 = V_121 -> V_54 ;
int V_286 , V_287 , V_243 , V_21 , V_288 ;
T_4 V_289 = V_121 -> V_245 [ V_246 ] . V_248 + 1 ;
T_10 V_290 = F_165 ( V_14 ) ;
if ( V_290 <= 1 )
return false ;
V_243 = V_121 -> V_245 [ V_251 ] . V_247 ;
for ( V_286 = 0 , V_287 = 0 ; V_286 < V_290 ; V_286 ++ , V_287 += V_243 ) {
V_288 = V_286 ;
for ( V_21 = 0 ; V_21 < V_243 ; V_21 ++ ) {
V_121 -> V_151 [ V_287 + V_21 ] -> V_210 = V_288 ;
V_121 -> V_151 [ V_287 + V_21 ] -> V_291 = V_286 ;
V_121 -> V_7 [ V_287 + V_21 ] -> V_210 = V_288 ;
V_121 -> V_7 [ V_287 + V_21 ] -> V_291 = V_286 ;
V_288 += V_289 ;
}
}
return true ;
}
static void F_194 ( struct V_120 * V_121 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_121 -> V_253 ; V_21 ++ )
V_121 -> V_7 [ V_21 ] -> V_210 = V_21 ;
for ( V_21 = 0 ; V_21 < V_121 -> V_254 ; V_21 ++ )
V_121 -> V_151 [ V_21 ] -> V_210 = V_21 ;
}
static void F_195 ( struct V_120 * V_121 )
{
if ( F_193 ( V_121 ) )
return;
F_194 ( V_121 ) ;
}
static void F_196 ( struct V_120 * V_121 )
{
T_4 V_21 , V_243 = V_121 -> V_245 [ V_251 ] . V_247 ;
T_6 V_292 ;
if ( F_197 ( V_121 -> V_54 ) ) {
for ( V_21 = V_293 ; V_21 -- ; ) {
V_292 = V_121 -> V_292 [ V_21 ] ;
if ( ( ( ( V_292 << 24 ) >> 24 ) < V_243 ) &&
( ( ( V_292 << 16 ) >> 24 ) < V_243 ) &&
( ( ( V_292 << 8 ) >> 24 ) < V_243 ) &&
( ( ( V_292 ) >> 24 ) < V_243 ) )
continue;
F_124 ( & V_121 -> V_268 -> V_14 ,
L_14 ) ;
goto V_294;
}
return;
}
V_294:
F_198 ( V_121 , NULL ) ;
}
int F_199 ( struct V_120 * V_121 )
{
int V_276 ;
F_170 ( V_121 ) ;
V_276 = F_187 ( V_121 ) ;
if ( V_276 ) {
F_124 ( & V_121 -> V_268 -> V_14 ,
L_15 ) ;
goto V_295;
}
V_276 = F_181 ( V_121 ) ;
if ( V_276 ) {
F_124 ( & V_121 -> V_268 -> V_14 ,
L_16 ) ;
goto V_296;
}
F_195 ( V_121 ) ;
F_196 ( V_121 ) ;
return 0 ;
V_296:
F_184 ( V_121 ) ;
V_295:
F_171 ( V_121 ) ;
return V_276 ;
}
void F_200 ( struct V_120 * V_121 )
{
F_183 ( V_121 ) ;
F_184 ( V_121 ) ;
}
