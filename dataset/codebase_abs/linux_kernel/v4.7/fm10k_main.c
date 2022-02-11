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
( F_54 ( V_67 ) & V_72 ) ?
V_73 : V_74 ) ;
}
static void F_55 ( struct V_5 * V_6 ,
union V_18 T_5 * V_19 ,
struct V_35 * V_36 )
{
struct V_75 * V_13 = V_6 -> V_53 ;
struct V_76 * V_77 = F_56 ( V_6 -> V_77 ) ;
if ( V_77 ) {
T_4 V_78 = F_34 ( F_57 ( V_36 ) -> V_79 . V_39 . V_80 ) - 1 ;
V_78 -= V_77 -> V_80 ;
if ( V_78 < V_77 -> V_38 && V_77 -> V_81 [ V_78 ] )
V_13 = V_77 -> V_81 [ V_78 ] ;
else
V_77 = NULL ;
}
V_36 -> V_82 = F_58 ( V_36 , V_13 ) ;
if ( ! V_77 )
return;
F_59 ( F_60 ( V_13 ) , V_36 -> V_83 + V_84 , 1 ,
! ! ( V_19 -> V_39 . V_85 &
F_61 ( V_86 ) ) ) ;
}
static unsigned int F_62 ( struct V_5 * V_6 ,
union V_18 * V_19 ,
struct V_35 * V_36 )
{
unsigned int V_83 = V_36 -> V_83 ;
F_51 ( V_6 , V_19 , V_36 ) ;
F_48 ( V_6 , V_19 , V_36 ) ;
F_57 ( V_36 ) -> V_79 . V_39 . V_87 = V_19 -> V_39 . V_87 ;
F_63 ( V_36 , V_6 -> V_88 ) ;
F_57 ( V_36 ) -> V_79 . V_26 . V_89 = V_19 -> V_26 . V_89 ;
if ( V_19 -> V_39 . V_87 ) {
T_4 V_90 = F_34 ( V_19 -> V_39 . V_87 ) ;
if ( ( V_90 & V_91 ) != V_6 -> V_90 )
F_64 ( V_36 , F_65 ( V_92 ) , V_90 ) ;
else if ( V_90 & V_93 )
F_64 ( V_36 , F_65 ( V_92 ) ,
V_90 & V_93 ) ;
}
F_55 ( V_6 , V_19 , V_36 ) ;
return V_83 ;
}
static bool F_66 ( struct V_5 * V_6 ,
union V_18 * V_19 )
{
T_6 V_94 = V_6 -> V_46 + 1 ;
V_94 = ( V_94 < V_6 -> V_23 ) ? V_94 : 0 ;
V_6 -> V_46 = V_94 ;
F_44 ( F_19 ( V_6 , V_94 ) ) ;
if ( F_12 ( F_50 ( V_19 , V_95 ) ) )
return false ;
return true ;
}
static bool F_67 ( struct V_5 * V_6 ,
union V_18 * V_19 ,
struct V_35 * V_36 )
{
if ( F_14 ( ( F_50 ( V_19 ,
V_96 ) ) ) ) {
#define F_68 ( T_7 , T_8 ) \
((rxd)->w.csum_err & cpu_to_le16(bit))
if ( F_68 ( V_19 , V_97 ) )
V_6 -> V_11 . V_98 ++ ;
if ( F_68 ( V_19 , V_99 ) )
V_6 -> V_11 . V_100 ++ ;
if ( F_68 ( V_19 , V_101 ) )
V_6 -> V_11 . V_102 ++ ;
if ( F_68 ( V_19 , V_103 ) )
V_6 -> V_11 . V_104 ++ ;
if ( F_68 ( V_19 , V_105 ) )
V_6 -> V_11 . V_106 ++ ;
F_69 ( V_36 ) ;
V_6 -> V_11 . V_107 ++ ;
return true ;
}
if ( F_70 ( V_36 ) )
return true ;
return false ;
}
static void F_71 ( struct V_108 * V_49 ,
struct V_35 * V_36 )
{
F_72 ( & V_49 -> V_50 , V_36 ) ;
}
static int F_73 ( struct V_108 * V_49 ,
struct V_5 * V_6 ,
int V_109 )
{
struct V_35 * V_36 = V_6 -> V_36 ;
unsigned int V_110 = 0 , V_111 = 0 ;
T_4 V_17 = F_74 ( V_6 ) ;
while ( F_12 ( V_111 < V_109 ) ) {
union V_18 * V_19 ;
if ( V_17 >= V_112 ) {
F_18 ( V_6 , V_17 ) ;
V_17 = 0 ;
}
V_19 = F_19 ( V_6 , V_6 -> V_46 ) ;
if ( ! V_19 -> V_26 . V_27 )
break;
F_75 () ;
V_36 = F_42 ( V_6 , V_19 , V_36 ) ;
if ( ! V_36 )
break;
V_17 ++ ;
if ( F_66 ( V_6 , V_19 ) )
continue;
if ( F_67 ( V_6 , V_19 , V_36 ) ) {
V_36 = NULL ;
continue;
}
V_110 += F_62 ( V_6 , V_19 , V_36 ) ;
F_71 ( V_49 , V_36 ) ;
V_36 = NULL ;
V_111 ++ ;
}
V_6 -> V_36 = V_36 ;
F_76 ( & V_6 -> V_113 ) ;
V_6 -> V_114 . V_115 += V_111 ;
V_6 -> V_114 . V_116 += V_110 ;
F_77 ( & V_6 -> V_113 ) ;
V_49 -> V_117 . V_111 += V_111 ;
V_49 -> V_117 . V_110 += V_110 ;
return V_111 ;
}
static struct V_118 * F_78 ( struct V_35 * V_36 )
{
struct V_119 * V_120 = F_60 ( V_36 -> V_13 ) ;
struct V_121 * V_122 ;
V_122 = F_79 ( & V_120 -> V_122 ,
struct V_121 , V_123 ) ;
if ( ! V_122 )
return NULL ;
if ( V_122 -> V_124 != F_80 ( V_36 ) -> V_125 )
return NULL ;
return (struct V_118 * ) ( F_81 ( V_36 ) + V_126 ) ;
}
static struct V_118 * F_82 ( struct V_35 * V_36 )
{
struct V_127 * V_128 ;
int V_129 = F_83 ( V_36 ) ;
if ( F_84 ( V_36 ) != F_65 ( V_130 ) )
return NULL ;
V_128 = (struct V_127 * ) ( F_85 ( V_36 ) + V_129 ) ;
if ( V_128 -> V_131 & V_132 )
return NULL ;
if ( V_128 -> V_131 & V_133 )
return (struct V_118 * ) ( V_128 + 1 ) ;
return (struct V_118 * ) ( & V_128 -> V_134 ) ;
}
T_9 F_86 ( struct V_35 * V_36 )
{
T_10 V_135 = 0 , V_136 = 0 , V_137 ;
struct V_118 * V_138 ;
if ( V_36 -> V_139 != V_140 ||
V_36 -> V_141 != F_65 ( V_142 ) )
return 0 ;
switch ( F_84 ( V_36 ) ) {
case F_65 ( V_130 ) :
V_135 = F_87 ( V_36 ) -> V_82 ;
break;
case F_65 ( V_143 ) :
V_135 = F_88 ( V_36 ) -> V_144 ;
break;
default:
return 0 ;
}
switch ( V_135 ) {
case V_145 :
V_138 = F_78 ( V_36 ) ;
break;
case V_146 :
V_138 = F_82 ( V_36 ) ;
break;
default:
return 0 ;
}
if ( ! V_138 )
return 0 ;
switch ( V_138 -> V_147 ) {
case F_65 ( V_130 ) :
V_136 = F_89 ( V_36 ) -> V_82 ;
break;
case F_65 ( V_143 ) :
V_136 = F_90 ( V_36 ) -> V_144 ;
break;
default:
return 0 ;
}
switch ( V_136 ) {
case V_148 :
V_137 = F_91 ( V_36 ) ;
break;
case V_145 :
V_137 = 8 ;
break;
default:
return 0 ;
}
if ( F_92 ( V_36 ) + V_137 -
F_93 ( V_36 ) > V_149 )
return 0 ;
return V_138 -> V_147 ;
}
static int F_94 ( struct V_5 * V_150 ,
struct V_151 * V_152 )
{
struct V_35 * V_36 = V_152 -> V_36 ;
struct V_153 * V_154 ;
unsigned char * V_155 ;
T_10 V_156 ;
if ( V_36 -> V_64 != V_157 )
return 0 ;
if ( ! F_95 ( V_36 ) )
return 0 ;
if ( V_36 -> V_62 ) {
if ( ! F_86 ( V_36 ) )
goto V_158;
V_155 = F_92 ( V_36 ) ;
} else {
V_155 = F_81 ( V_36 ) ;
}
V_156 = ( V_155 - V_36 -> V_51 ) + ( ( (struct V_159 * ) V_155 ) -> V_160 << 2 ) ;
V_152 -> V_161 |= V_162 ;
V_152 -> V_163 = F_41 ( V_36 ) -> V_163 ;
V_152 -> V_164 += ( V_152 -> V_163 - 1 ) * V_156 ;
V_154 = F_96 ( V_150 , V_150 -> V_21 ) ;
V_154 -> V_156 = V_156 ;
V_154 -> V_165 = F_61 ( F_41 ( V_36 ) -> V_166 ) ;
return 1 ;
V_158:
V_150 -> V_53 -> V_54 &= ~ V_167 ;
if ( ! F_97 () )
F_98 ( V_150 -> V_53 ,
L_4 ) ;
return - 1 ;
}
static void F_99 ( struct V_5 * V_150 ,
struct V_151 * V_152 )
{
struct V_35 * V_36 = V_152 -> V_36 ;
struct V_153 * V_154 ;
union {
struct V_168 * V_169 ;
struct V_170 * V_171 ;
T_10 * V_172 ;
} V_173 ;
T_10 * V_174 ;
T_9 V_175 ;
T_9 V_82 ;
T_10 V_135 = 0 ;
if ( V_36 -> V_64 != V_157 )
goto V_176;
if ( V_36 -> V_62 ) {
V_82 = F_86 ( V_36 ) ;
if ( ! V_82 ) {
if ( F_100 ( V_36 ) ) {
F_101 ( V_150 -> V_13 ,
L_5 ) ;
V_150 -> V_177 . V_60 ++ ;
}
goto V_176;
}
V_173 . V_172 = F_102 ( V_36 ) ;
V_174 = F_92 ( V_36 ) ;
} else {
V_82 = F_84 ( V_36 ) ;
V_173 . V_172 = F_85 ( V_36 ) ;
V_174 = F_81 ( V_36 ) ;
}
switch ( V_82 ) {
case F_65 ( V_130 ) :
V_135 = V_173 . V_169 -> V_82 ;
break;
case F_65 ( V_143 ) :
V_135 = V_173 . V_171 -> V_144 ;
if ( F_12 ( ( V_174 - V_173 . V_172 ) ==
sizeof( struct V_170 ) ) )
break;
F_103 ( V_36 , V_173 . V_172 - V_36 -> V_51 +
sizeof( struct V_170 ) ,
& V_135 , & V_175 ) ;
if ( F_14 ( V_175 ) )
V_135 = V_178 ;
break;
default:
break;
}
switch ( V_135 ) {
case V_148 :
case V_145 :
break;
case V_146 :
if ( V_36 -> V_62 )
break;
default:
if ( F_14 ( F_97 () ) ) {
F_101 ( V_150 -> V_13 ,
L_6 ,
V_82 , V_135 ) ;
}
F_100 ( V_36 ) ;
V_150 -> V_177 . V_60 ++ ;
goto V_176;
}
V_152 -> V_161 |= V_162 ;
V_150 -> V_177 . V_66 ++ ;
V_176:
V_154 = F_96 ( V_150 , V_150 -> V_21 ) ;
V_154 -> V_156 = 0 ;
V_154 -> V_165 = 0 ;
}
static T_10 F_104 ( struct V_35 * V_36 , T_6 V_161 )
{
T_6 V_179 = 0 ;
V_179 |= F_105 ( V_161 , V_162 ,
V_180 ) ;
return V_179 ;
}
static bool F_106 ( struct V_5 * V_150 ,
struct V_153 * V_154 , T_4 V_20 ,
T_3 V_10 , unsigned int V_38 , T_10 V_179 )
{
if ( ( ++ V_20 & ( V_181 - 1 ) ) == 0 )
V_179 |= V_182 | V_183 ;
V_154 -> V_184 = F_20 ( V_10 ) ;
V_154 -> V_131 = V_179 ;
V_154 -> V_185 = F_61 ( V_38 ) ;
return V_20 == V_150 -> V_23 ;
}
static int F_107 ( struct V_5 * V_150 , T_4 V_38 )
{
F_108 ( V_150 -> V_53 , V_150 -> V_88 ) ;
F_109 () ;
if ( F_12 ( F_74 ( V_150 ) < V_38 ) )
return - V_186 ;
F_110 ( V_150 -> V_53 , V_150 -> V_88 ) ;
++ V_150 -> V_177 . V_187 ;
return 0 ;
}
static inline int F_111 ( struct V_5 * V_150 , T_4 V_38 )
{
if ( F_12 ( F_74 ( V_150 ) >= V_38 ) )
return 0 ;
return F_107 ( V_150 , V_38 ) ;
}
static void F_112 ( struct V_5 * V_150 ,
struct V_151 * V_152 )
{
struct V_35 * V_36 = V_152 -> V_36 ;
struct V_151 * V_188 ;
struct V_153 * V_154 ;
struct V_189 * V_190 ;
unsigned char * V_51 ;
T_3 V_10 ;
unsigned int V_191 , V_38 ;
T_6 V_161 = V_152 -> V_161 ;
T_4 V_20 = V_150 -> V_21 ;
T_10 V_131 = F_104 ( V_36 , V_161 ) ;
V_154 = F_96 ( V_150 , V_20 ) ;
if ( F_113 ( V_36 ) )
V_154 -> V_87 = F_61 ( F_114 ( V_36 ) ) ;
else
V_154 -> V_87 = 0 ;
V_38 = F_115 ( V_36 ) ;
V_51 = V_36 -> V_51 ;
V_10 = F_116 ( V_150 -> V_13 , V_51 , V_38 , V_192 ) ;
V_191 = V_36 -> V_191 ;
V_188 = V_152 ;
for ( V_190 = & F_41 ( V_36 ) -> V_193 [ 0 ] ; ; V_190 ++ ) {
if ( F_16 ( V_150 -> V_13 , V_10 ) )
goto V_194;
F_117 ( V_188 , V_83 , V_38 ) ;
F_118 ( V_188 , V_10 , V_10 ) ;
while ( F_14 ( V_38 > V_195 ) ) {
if ( F_106 ( V_150 , V_154 ++ , V_20 ++ , V_10 ,
V_195 , V_131 ) ) {
V_154 = F_96 ( V_150 , 0 ) ;
V_20 = 0 ;
}
V_10 += V_195 ;
V_38 -= V_195 ;
}
if ( F_12 ( ! V_191 ) )
break;
if ( F_106 ( V_150 , V_154 ++ , V_20 ++ ,
V_10 , V_38 , V_131 ) ) {
V_154 = F_96 ( V_150 , 0 ) ;
V_20 = 0 ;
}
V_38 = F_119 ( V_190 ) ;
V_191 -= V_38 ;
V_10 = F_120 ( V_150 -> V_13 , V_190 , 0 , V_38 ,
V_192 ) ;
V_188 = & V_150 -> V_188 [ V_20 ] ;
}
V_131 |= V_196 ;
if ( F_106 ( V_150 , V_154 , V_20 ++ , V_10 , V_38 , V_131 ) )
V_20 = 0 ;
F_121 ( F_122 ( V_150 ) , V_152 -> V_164 ) ;
F_123 ( V_152 -> V_36 ) ;
F_21 () ;
V_152 -> V_197 = V_154 ;
V_150 -> V_21 = V_20 ;
F_111 ( V_150 , V_198 ) ;
if ( F_124 ( F_122 ( V_150 ) ) || ! V_36 -> V_199 ) {
F_22 ( V_20 , V_150 -> V_29 ) ;
F_125 () ;
}
return;
V_194:
F_126 ( V_150 -> V_13 , L_7 ) ;
for (; ; ) {
V_188 = & V_150 -> V_188 [ V_20 ] ;
F_127 ( V_150 , V_188 ) ;
if ( V_188 == V_152 )
break;
if ( V_20 == 0 )
V_20 = V_150 -> V_23 ;
V_20 -- ;
}
V_150 -> V_21 = V_20 ;
}
T_11 F_128 ( struct V_35 * V_36 ,
struct V_5 * V_150 )
{
T_4 V_23 = F_129 ( F_115 ( V_36 ) ) ;
struct V_151 * V_152 ;
unsigned short V_200 ;
T_6 V_161 = 0 ;
int V_201 ;
for ( V_200 = 0 ; V_200 < F_41 ( V_36 ) -> V_44 ; V_200 ++ )
V_23 += F_129 ( F_41 ( V_36 ) -> V_193 [ V_200 ] . V_38 ) ;
if ( F_111 ( V_150 , V_23 + 3 ) ) {
V_150 -> V_177 . V_202 ++ ;
return V_203 ;
}
V_152 = & V_150 -> V_188 [ V_150 -> V_21 ] ;
V_152 -> V_36 = V_36 ;
V_152 -> V_164 = F_130 (unsigned int, skb->len, ETH_ZLEN) ;
V_152 -> V_163 = 1 ;
V_152 -> V_161 = V_161 ;
V_201 = F_94 ( V_150 , V_152 ) ;
if ( V_201 < 0 )
goto V_204;
else if ( ! V_201 )
F_99 ( V_150 , V_152 ) ;
F_112 ( V_150 , V_152 ) ;
return V_205 ;
V_204:
F_69 ( V_152 -> V_36 ) ;
V_152 -> V_36 = NULL ;
return V_205 ;
}
static T_12 F_131 ( struct V_5 * V_52 )
{
return V_52 -> V_114 . V_115 ;
}
static T_12 F_132 ( struct V_5 * V_52 )
{
T_6 V_206 = V_52 -> V_46 ;
T_6 V_29 = V_52 -> V_21 ;
return ( ( V_206 <= V_29 ) ? V_29 : V_29 + V_52 -> V_23 ) - V_206 ;
}
bool F_133 ( struct V_5 * V_150 )
{
T_6 V_207 = F_131 ( V_150 ) ;
T_6 V_208 = V_150 -> V_177 . V_208 ;
T_6 V_209 = F_132 ( V_150 ) ;
F_134 ( V_150 ) ;
if ( ! V_209 || ( V_208 != V_207 ) ) {
V_150 -> V_177 . V_208 = V_207 ;
F_135 ( V_210 , & V_150 -> V_211 ) ;
return false ;
}
return F_136 ( V_210 , & V_150 -> V_211 ) ;
}
void F_137 ( struct V_119 * V_120 )
{
if ( ! F_138 ( V_212 , & V_120 -> V_211 ) ) {
V_120 -> V_213 ++ ;
V_120 -> V_131 |= V_214 ;
F_139 ( V_120 ) ;
}
}
static bool F_140 ( struct V_108 * V_49 ,
struct V_5 * V_150 , int V_215 )
{
struct V_119 * V_120 = V_49 -> V_120 ;
struct V_151 * V_188 ;
struct V_153 * V_154 ;
unsigned int V_110 = 0 , V_111 = 0 ;
unsigned int V_109 = V_49 -> V_216 . V_217 ;
unsigned int V_20 = V_150 -> V_46 ;
if ( F_138 ( V_212 , & V_120 -> V_211 ) )
return true ;
V_188 = & V_150 -> V_188 [ V_20 ] ;
V_154 = F_96 ( V_150 , V_20 ) ;
V_20 -= V_150 -> V_23 ;
do {
struct V_153 * V_218 = V_188 -> V_197 ;
if ( ! V_218 )
break;
F_141 () ;
if ( ! ( V_218 -> V_131 & V_219 ) )
break;
V_188 -> V_197 = NULL ;
V_110 += V_188 -> V_164 ;
V_111 += V_188 -> V_163 ;
F_142 ( V_188 -> V_36 , V_215 ) ;
F_143 ( V_150 -> V_13 ,
F_144 ( V_188 , V_10 ) ,
F_145 ( V_188 , V_83 ) ,
V_192 ) ;
V_188 -> V_36 = NULL ;
F_117 ( V_188 , V_83 , 0 ) ;
while ( V_154 != V_218 ) {
V_188 ++ ;
V_154 ++ ;
V_20 ++ ;
if ( F_14 ( ! V_20 ) ) {
V_20 -= V_150 -> V_23 ;
V_188 = V_150 -> V_188 ;
V_154 = F_96 ( V_150 , 0 ) ;
}
if ( F_145 ( V_188 , V_83 ) ) {
F_47 ( V_150 -> V_13 ,
F_144 ( V_188 , V_10 ) ,
F_145 ( V_188 , V_83 ) ,
V_192 ) ;
F_117 ( V_188 , V_83 , 0 ) ;
}
}
V_188 ++ ;
V_154 ++ ;
V_20 ++ ;
if ( F_14 ( ! V_20 ) ) {
V_20 -= V_150 -> V_23 ;
V_188 = V_150 -> V_188 ;
V_154 = F_96 ( V_150 , 0 ) ;
}
F_44 ( V_154 ) ;
V_109 -- ;
} while ( F_12 ( V_109 ) );
V_20 += V_150 -> V_23 ;
V_150 -> V_46 = V_20 ;
F_76 ( & V_150 -> V_113 ) ;
V_150 -> V_114 . V_116 += V_110 ;
V_150 -> V_114 . V_115 += V_111 ;
F_77 ( & V_150 -> V_113 ) ;
V_49 -> V_216 . V_110 += V_110 ;
V_49 -> V_216 . V_111 += V_111 ;
if ( F_146 ( V_150 ) && F_133 ( V_150 ) ) {
struct V_220 * V_221 = & V_120 -> V_221 ;
F_147 ( V_120 , V_222 , V_150 -> V_53 ,
L_8
L_9
L_10
L_11
L_12 ,
V_150 -> V_88 ,
F_148 ( V_221 , F_149 ( V_150 -> V_223 ) ) ,
F_148 ( V_221 , F_150 ( V_150 -> V_223 ) ) ,
V_150 -> V_21 , V_20 ) ;
F_108 ( V_150 -> V_53 ,
V_150 -> V_88 ) ;
F_151 ( V_120 , V_224 , V_150 -> V_53 ,
L_13 ,
V_120 -> V_213 + 1 ,
V_150 -> V_88 ) ;
F_137 ( V_120 ) ;
return true ;
}
F_152 ( F_122 ( V_150 ) ,
V_111 , V_110 ) ;
#define F_153 min_t(u16, FM10K_MIN_TXD - 1, DESC_NEEDED * 2)
if ( F_14 ( V_111 && F_154 ( V_150 -> V_53 ) &&
( F_74 ( V_150 ) >= F_153 ) ) ) {
F_109 () ;
if ( F_155 ( V_150 -> V_53 ,
V_150 -> V_88 ) &&
! F_138 ( V_212 , & V_120 -> V_211 ) ) {
F_156 ( V_150 -> V_53 ,
V_150 -> V_88 ) ;
++ V_150 -> V_177 . V_187 ;
}
}
return ! ! V_109 ;
}
static void F_157 ( struct V_225 * V_226 )
{
unsigned int V_227 , V_115 , V_228 ;
if ( ! F_158 ( V_226 -> V_229 ) )
goto V_230;
V_115 = V_226 -> V_111 ;
if ( ! V_115 )
goto V_230;
V_227 = V_226 -> V_110 / V_115 ;
if ( V_227 <= 360 ) {
V_227 *= 8 ;
V_227 += 376 ;
} else if ( V_227 <= 1152 ) {
V_227 *= 3 ;
V_227 += 2176 ;
} else if ( V_227 <= 1920 ) {
V_227 += 4480 ;
} else {
V_227 = 6656 ;
}
V_228 = F_159 ( V_226 -> V_231 ) + 8 ;
V_227 += F_54 ( V_228 ) - 1 ;
V_227 >>= V_228 ;
V_226 -> V_229 = V_227 | V_232 ;
V_230:
V_226 -> V_110 = 0 ;
V_226 -> V_111 = 0 ;
}
static void F_160 ( struct V_108 * V_49 )
{
T_6 V_229 = V_233 ;
F_157 ( & V_49 -> V_216 ) ;
F_157 ( & V_49 -> V_117 ) ;
V_229 |= ( V_49 -> V_216 . V_229 & V_234 ) ;
V_229 |= ( V_49 -> V_117 . V_229 & V_234 ) << V_235 ;
F_22 ( V_229 , V_49 -> V_229 ) ;
}
static int F_161 ( struct V_236 * V_50 , int V_109 )
{
struct V_108 * V_49 =
F_162 ( V_50 , struct V_108 , V_50 ) ;
struct V_5 * V_52 ;
int V_237 , V_238 = 0 ;
bool V_239 = true ;
F_163 (ring, q_vector->tx) {
if ( ! F_140 ( V_49 , V_52 , V_109 ) )
V_239 = false ;
}
if ( V_109 <= 0 )
return V_109 ;
if ( V_49 -> V_117 . V_23 > 1 )
V_237 = F_164 ( V_109 / V_49 -> V_117 . V_23 , 1 ) ;
else
V_237 = V_109 ;
F_163 (ring, q_vector->rx) {
int V_240 = F_73 ( V_49 , V_52 , V_237 ) ;
V_238 += V_240 ;
if ( V_240 >= V_237 )
V_239 = false ;
}
if ( ! V_239 )
return V_109 ;
F_165 ( V_50 , V_238 ) ;
F_160 ( V_49 ) ;
return 0 ;
}
static bool F_166 ( struct V_119 * V_120 )
{
struct V_75 * V_13 = V_120 -> V_53 ;
struct V_241 * V_200 ;
int V_242 , V_20 ;
int V_243 ;
V_243 = F_167 ( V_13 ) ;
if ( V_243 <= 1 )
return false ;
V_200 = & V_120 -> V_244 [ V_245 ] ;
V_200 -> V_246 = V_243 ;
V_200 -> V_247 = F_54 ( F_168 ( V_243 - 1 ) ) - 1 ;
V_242 = V_120 -> V_221 . V_248 . V_249 / V_243 ;
V_242 = F_54 ( F_168 ( V_242 ) - 1 ) ;
V_200 = & V_120 -> V_244 [ V_250 ] ;
V_242 = F_169 ( T_4 , V_242 , V_200 -> V_251 ) ;
V_200 -> V_246 = V_242 ;
V_200 -> V_247 = F_54 ( F_168 ( V_242 - 1 ) ) - 1 ;
for ( V_20 = 0 ; V_20 < V_243 ; V_20 ++ )
F_170 ( V_13 , V_20 , V_242 , V_242 * V_20 ) ;
V_120 -> V_252 = V_242 * V_243 ;
V_120 -> V_253 = V_242 * V_243 ;
return true ;
}
static bool F_171 ( struct V_119 * V_120 )
{
struct V_241 * V_200 ;
T_4 V_242 ;
V_200 = & V_120 -> V_244 [ V_250 ] ;
V_242 = F_169 ( T_4 , V_120 -> V_221 . V_248 . V_249 , V_200 -> V_251 ) ;
V_200 -> V_246 = V_242 ;
V_200 -> V_247 = F_54 ( F_168 ( V_242 - 1 ) ) - 1 ;
V_120 -> V_252 = V_242 ;
V_120 -> V_253 = V_242 ;
return true ;
}
static void F_172 ( struct V_119 * V_120 )
{
if ( F_166 ( V_120 ) )
return;
F_171 ( V_120 ) ;
}
static void F_173 ( struct V_119 * V_120 )
{
V_120 -> V_253 = 0 ;
V_120 -> V_252 = 0 ;
V_120 -> V_254 = 0 ;
}
static int F_174 ( struct V_119 * V_120 ,
unsigned int V_255 , unsigned int V_256 ,
unsigned int V_257 , unsigned int V_258 ,
unsigned int V_259 , unsigned int V_260 )
{
struct V_108 * V_49 ;
struct V_5 * V_52 ;
int V_261 , V_38 ;
V_261 = V_257 + V_259 ;
V_38 = sizeof( struct V_108 ) +
( sizeof( struct V_5 ) * V_261 ) ;
V_49 = F_175 ( V_38 , V_262 ) ;
if ( ! V_49 )
return - V_263 ;
F_176 ( V_120 -> V_53 , & V_49 -> V_50 ,
F_161 , V_264 ) ;
V_120 -> V_49 [ V_256 ] = V_49 ;
V_49 -> V_120 = V_120 ;
V_49 -> V_256 = V_256 ;
V_52 = V_49 -> V_52 ;
V_49 -> V_216 . V_52 = V_52 ;
V_49 -> V_216 . V_217 = V_265 ;
V_49 -> V_216 . V_229 = V_120 -> V_266 ;
V_49 -> V_216 . V_231 = V_120 -> V_221 . V_248 . V_231 ;
V_49 -> V_216 . V_23 = V_257 ;
while ( V_257 ) {
V_52 -> V_13 = & V_120 -> V_267 -> V_13 ;
V_52 -> V_53 = V_120 -> V_53 ;
V_52 -> V_49 = V_49 ;
V_52 -> V_23 = V_120 -> V_268 ;
V_52 -> V_88 = V_258 ;
V_120 -> V_150 [ V_258 ] = V_52 ;
V_257 -- ;
V_258 += V_255 ;
V_52 ++ ;
}
V_49 -> V_117 . V_52 = V_52 ;
V_49 -> V_117 . V_229 = V_120 -> V_269 ;
V_49 -> V_117 . V_231 = V_120 -> V_221 . V_248 . V_231 ;
V_49 -> V_117 . V_23 = V_259 ;
while ( V_259 ) {
V_52 -> V_13 = & V_120 -> V_267 -> V_13 ;
V_52 -> V_53 = V_120 -> V_53 ;
F_177 ( V_52 -> V_77 , V_120 -> V_77 ) ;
V_52 -> V_49 = V_49 ;
V_52 -> V_23 = V_120 -> V_270 ;
V_52 -> V_88 = V_260 ;
V_120 -> V_6 [ V_260 ] = V_52 ;
V_259 -- ;
V_260 += V_255 ;
V_52 ++ ;
}
F_178 ( V_49 ) ;
return 0 ;
}
static void F_179 ( struct V_119 * V_120 , int V_256 )
{
struct V_108 * V_49 = V_120 -> V_49 [ V_256 ] ;
struct V_5 * V_52 ;
F_180 ( V_49 ) ;
F_163 (ring, q_vector->tx)
V_120 -> V_150 [ V_52 -> V_88 ] = NULL ;
F_163 (ring, q_vector->rx)
V_120 -> V_6 [ V_52 -> V_88 ] = NULL ;
V_120 -> V_49 [ V_256 ] = NULL ;
F_181 ( & V_49 -> V_50 ) ;
F_182 ( V_49 , V_271 ) ;
}
static int F_183 ( struct V_119 * V_120 )
{
unsigned int V_272 = V_120 -> V_254 ;
unsigned int V_273 = V_120 -> V_252 ;
unsigned int V_274 = V_120 -> V_253 ;
unsigned int V_260 = 0 , V_258 = 0 , V_256 = 0 ;
int V_275 ;
if ( V_272 >= ( V_273 + V_274 ) ) {
for (; V_273 ; V_256 ++ ) {
V_275 = F_174 ( V_120 , V_272 , V_256 ,
0 , 0 , 1 , V_260 ) ;
if ( V_275 )
goto V_276;
V_273 -- ;
V_260 ++ ;
}
}
for (; V_256 < V_272 ; V_256 ++ ) {
int V_277 = F_184 ( V_273 , V_272 - V_256 ) ;
int V_278 = F_184 ( V_274 , V_272 - V_256 ) ;
V_275 = F_174 ( V_120 , V_272 , V_256 ,
V_278 , V_258 ,
V_277 , V_260 ) ;
if ( V_275 )
goto V_276;
V_273 -= V_277 ;
V_274 -= V_278 ;
V_260 ++ ;
V_258 ++ ;
}
return 0 ;
V_276:
F_173 ( V_120 ) ;
while ( V_256 -- )
F_179 ( V_120 , V_256 ) ;
return - V_263 ;
}
static void F_185 ( struct V_119 * V_120 )
{
int V_256 = V_120 -> V_254 ;
F_173 ( V_120 ) ;
while ( V_256 -- )
F_179 ( V_120 , V_256 ) ;
}
static void F_186 ( struct V_119 * V_120 )
{
F_187 ( V_120 -> V_267 ) ;
F_188 ( V_120 -> V_279 ) ;
V_120 -> V_279 = NULL ;
}
static int F_189 ( struct V_119 * V_120 )
{
struct V_220 * V_221 = & V_120 -> V_221 ;
int V_280 , V_281 ;
V_280 = F_164 ( V_120 -> V_252 , V_120 -> V_253 ) ;
V_280 = F_169 ( T_4 , V_280 , F_190 () ) ;
V_280 += F_191 ( V_221 ) ;
V_280 = F_169 ( int , V_280 , V_221 -> V_248 . V_282 ) ;
V_120 -> V_279 = F_192 ( V_280 , sizeof( struct V_283 ) ,
V_262 ) ;
if ( ! V_120 -> V_279 )
return - V_263 ;
for ( V_281 = 0 ; V_281 < V_280 ; V_281 ++ )
V_120 -> V_279 [ V_281 ] . V_284 = V_281 ;
V_280 = F_193 ( V_120 -> V_267 ,
V_120 -> V_279 ,
F_194 ( V_221 ) ,
V_280 ) ;
if ( V_280 < 0 ) {
F_188 ( V_120 -> V_279 ) ;
V_120 -> V_279 = NULL ;
return - V_263 ;
}
V_120 -> V_254 = V_280 - F_191 ( V_221 ) ;
return 0 ;
}
static bool F_195 ( struct V_119 * V_120 )
{
struct V_75 * V_13 = V_120 -> V_53 ;
int V_285 , V_286 , V_242 , V_20 , V_287 ;
T_4 V_288 = V_120 -> V_244 [ V_245 ] . V_247 + 1 ;
T_10 V_289 = F_167 ( V_13 ) ;
if ( V_289 <= 1 )
return false ;
V_242 = V_120 -> V_244 [ V_250 ] . V_246 ;
for ( V_285 = 0 , V_286 = 0 ; V_285 < V_289 ; V_285 ++ , V_286 += V_242 ) {
V_287 = V_285 ;
for ( V_20 = 0 ; V_20 < V_242 ; V_20 ++ ) {
V_120 -> V_150 [ V_286 + V_20 ] -> V_223 = V_287 ;
V_120 -> V_150 [ V_286 + V_20 ] -> V_290 = V_285 ;
V_120 -> V_6 [ V_286 + V_20 ] -> V_223 = V_287 ;
V_120 -> V_6 [ V_286 + V_20 ] -> V_290 = V_285 ;
V_287 += V_288 ;
}
}
return true ;
}
static void F_196 ( struct V_119 * V_120 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_120 -> V_252 ; V_20 ++ )
V_120 -> V_6 [ V_20 ] -> V_223 = V_20 ;
for ( V_20 = 0 ; V_20 < V_120 -> V_253 ; V_20 ++ )
V_120 -> V_150 [ V_20 ] -> V_223 = V_20 ;
}
static void F_197 ( struct V_119 * V_120 )
{
if ( F_195 ( V_120 ) )
return;
F_196 ( V_120 ) ;
}
static void F_198 ( struct V_119 * V_120 )
{
T_4 V_20 , V_242 = V_120 -> V_244 [ V_250 ] . V_246 ;
T_6 V_291 ;
if ( F_199 ( V_120 -> V_53 ) ) {
for ( V_20 = V_292 ; V_20 -- ; ) {
V_291 = V_120 -> V_291 [ V_20 ] ;
if ( ( ( ( V_291 << 24 ) >> 24 ) < V_242 ) &&
( ( ( V_291 << 16 ) >> 24 ) < V_242 ) &&
( ( ( V_291 << 8 ) >> 24 ) < V_242 ) &&
( ( ( V_291 ) >> 24 ) < V_242 ) )
continue;
F_126 ( & V_120 -> V_267 -> V_13 ,
L_14 ) ;
goto V_293;
}
return;
}
V_293:
F_200 ( V_120 , NULL ) ;
}
int F_201 ( struct V_119 * V_120 )
{
int V_275 ;
F_172 ( V_120 ) ;
V_275 = F_189 ( V_120 ) ;
if ( V_275 ) {
F_126 ( & V_120 -> V_267 -> V_13 ,
L_15 ) ;
goto V_294;
}
V_275 = F_183 ( V_120 ) ;
if ( V_275 ) {
F_126 ( & V_120 -> V_267 -> V_13 ,
L_16 ) ;
goto V_295;
}
F_197 ( V_120 ) ;
F_198 ( V_120 ) ;
return 0 ;
V_295:
F_186 ( V_120 ) ;
V_294:
F_173 ( V_120 ) ;
return V_275 ;
}
void F_202 ( struct V_119 * V_120 )
{
F_185 ( V_120 ) ;
F_186 ( V_120 ) ;
}
