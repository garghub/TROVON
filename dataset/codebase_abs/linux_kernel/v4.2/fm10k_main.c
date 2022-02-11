static int T_1 F_1 ( void )
{
F_2 ( L_1 , V_1 , V_2 ) ;
F_2 ( L_2 , V_3 ) ;
if ( ! V_4 )
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
V_4 = NULL ;
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
}
static inline void F_51 ( struct V_5 * V_53 ,
union V_18 * V_19 ,
struct V_36 * V_37 )
{
T_4 V_67 ;
if ( ! ( V_53 -> V_54 -> V_55 & V_68 ) )
return;
V_67 = F_34 ( V_19 -> V_40 . V_69 ) & V_70 ;
if ( ! V_67 )
return;
F_52 ( V_37 , F_53 ( V_19 -> V_26 . V_71 ) ,
( V_72 & ( 1ul << V_67 ) ) ?
V_73 : V_74 ) ;
}
static void F_54 ( struct V_5 * V_6 ,
union V_18 * V_19 ,
struct V_36 * V_37 )
{
struct V_75 * V_76 = V_6 -> V_50 -> V_76 ;
F_55 ( V_37 ) -> V_77 = V_19 -> V_24 . V_78 ;
if ( F_14 ( V_76 -> V_79 & V_80 ) )
F_56 ( V_76 , F_57 ( V_37 ) ,
F_58 ( V_19 -> V_24 . V_78 ) ) ;
}
static void F_59 ( struct V_5 * V_6 ,
union V_18 T_5 * V_19 ,
struct V_36 * V_37 )
{
struct V_81 * V_13 = V_6 -> V_54 ;
struct V_82 * V_83 = F_60 ( V_6 -> V_83 ) ;
if ( V_83 ) {
T_4 V_84 = F_34 ( F_55 ( V_37 ) -> V_85 . V_40 . V_86 ) - 1 ;
V_84 -= V_83 -> V_86 ;
if ( V_84 < V_83 -> V_39 && V_83 -> V_87 [ V_84 ] )
V_13 = V_83 -> V_87 [ V_84 ] ;
else
V_83 = NULL ;
}
V_37 -> V_88 = F_61 ( V_37 , V_13 ) ;
if ( ! V_83 )
return;
F_62 ( F_63 ( V_13 ) , V_37 -> V_89 + V_90 , 1 ,
! ! ( V_19 -> V_40 . V_91 &
F_64 ( V_92 ) ) ) ;
}
static unsigned int F_65 ( struct V_5 * V_6 ,
union V_18 * V_19 ,
struct V_36 * V_37 )
{
unsigned int V_89 = V_37 -> V_89 ;
F_51 ( V_6 , V_19 , V_37 ) ;
F_48 ( V_6 , V_19 , V_37 ) ;
F_54 ( V_6 , V_19 , V_37 ) ;
F_55 ( V_37 ) -> V_85 . V_40 . V_93 = V_19 -> V_40 . V_93 ;
F_66 ( V_37 , V_6 -> V_94 ) ;
F_55 ( V_37 ) -> V_85 . V_26 . V_95 = V_19 -> V_26 . V_95 ;
if ( V_19 -> V_40 . V_93 ) {
T_4 V_96 = F_34 ( V_19 -> V_40 . V_93 ) ;
if ( V_96 != V_6 -> V_96 )
F_67 ( V_37 , F_68 ( V_97 ) , V_96 ) ;
}
F_59 ( V_6 , V_19 , V_37 ) ;
return V_89 ;
}
static bool F_69 ( struct V_5 * V_6 ,
union V_18 * V_19 )
{
T_6 V_98 = V_6 -> V_47 + 1 ;
V_98 = ( V_98 < V_6 -> V_23 ) ? V_98 : 0 ;
V_6 -> V_47 = V_98 ;
F_44 ( F_19 ( V_6 , V_98 ) ) ;
if ( F_12 ( F_50 ( V_19 , V_99 ) ) )
return false ;
return true ;
}
static bool F_70 ( struct V_5 * V_6 ,
union V_18 * V_19 ,
struct V_36 * V_37 )
{
if ( F_14 ( ( F_50 ( V_19 ,
V_100 ) ) ) ) {
F_71 ( V_37 ) ;
V_6 -> V_11 . V_101 ++ ;
return true ;
}
if ( F_72 ( V_37 ) )
return true ;
return false ;
}
static void F_73 ( struct V_102 * V_50 ,
struct V_36 * V_37 )
{
F_74 ( & V_50 -> V_51 , V_37 ) ;
}
static bool F_75 ( struct V_102 * V_50 ,
struct V_5 * V_6 ,
int V_103 )
{
struct V_36 * V_37 = V_6 -> V_37 ;
unsigned int V_104 = 0 , V_105 = 0 ;
T_4 V_17 = F_76 ( V_6 ) ;
while ( F_12 ( V_105 < V_103 ) ) {
union V_18 * V_19 ;
if ( V_17 >= V_106 ) {
F_18 ( V_6 , V_17 ) ;
V_17 = 0 ;
}
V_19 = F_19 ( V_6 , V_6 -> V_47 ) ;
if ( ! V_19 -> V_26 . V_27 )
break;
F_77 () ;
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
V_104 += F_65 ( V_6 , V_19 , V_37 ) ;
F_73 ( V_50 , V_37 ) ;
V_37 = NULL ;
V_105 ++ ;
}
V_6 -> V_37 = V_37 ;
F_78 ( & V_6 -> V_107 ) ;
V_6 -> V_108 . V_109 += V_105 ;
V_6 -> V_108 . V_110 += V_104 ;
F_79 ( & V_6 -> V_107 ) ;
V_50 -> V_111 . V_105 += V_105 ;
V_50 -> V_111 . V_104 += V_104 ;
return V_105 < V_103 ;
}
static struct V_112 * F_80 ( struct V_36 * V_37 )
{
struct V_75 * V_76 = F_63 ( V_37 -> V_13 ) ;
struct V_113 * V_114 ;
V_114 = F_81 ( & V_76 -> V_114 ,
struct V_113 , V_115 ) ;
if ( ! V_114 )
return NULL ;
if ( V_114 -> V_116 != F_82 ( V_37 ) -> V_117 )
return NULL ;
return (struct V_112 * ) ( F_83 ( V_37 ) + V_118 ) ;
}
static struct V_112 * F_84 ( struct V_36 * V_37 )
{
struct V_119 * V_120 ;
int V_121 = F_85 ( V_37 ) ;
if ( F_86 ( V_37 ) != F_68 ( V_122 ) )
return NULL ;
V_120 = (struct V_119 * ) ( F_87 ( V_37 ) + V_121 ) ;
if ( V_120 -> V_79 & V_123 )
return NULL ;
if ( V_120 -> V_79 & V_124 )
return (struct V_112 * ) ( V_120 + 1 ) ;
return (struct V_112 * ) ( & V_120 -> V_125 ) ;
}
T_7 F_88 ( struct V_36 * V_37 )
{
T_8 V_126 = 0 , V_127 = 0 , V_128 ;
struct V_112 * V_129 ;
if ( V_37 -> V_130 != V_131 ||
V_37 -> V_132 != F_68 ( V_133 ) )
return 0 ;
switch ( F_86 ( V_37 ) ) {
case F_68 ( V_122 ) :
V_126 = F_89 ( V_37 ) -> V_88 ;
break;
case F_68 ( V_134 ) :
V_126 = F_90 ( V_37 ) -> V_135 ;
break;
default:
return 0 ;
}
switch ( V_126 ) {
case V_136 :
V_129 = F_80 ( V_37 ) ;
break;
case V_137 :
V_129 = F_84 ( V_37 ) ;
break;
default:
return 0 ;
}
if ( ! V_129 )
return 0 ;
switch ( V_129 -> V_138 ) {
case F_68 ( V_122 ) :
V_127 = F_91 ( V_37 ) -> V_88 ;
break;
case F_68 ( V_134 ) :
V_127 = F_92 ( V_37 ) -> V_135 ;
break;
default:
return 0 ;
}
switch ( V_127 ) {
case V_139 :
V_128 = F_93 ( V_37 ) ;
break;
case V_136 :
V_128 = 8 ;
break;
default:
return 0 ;
}
if ( F_94 ( V_37 ) + V_128 -
F_95 ( V_37 ) > V_140 )
return 0 ;
return V_129 -> V_138 ;
}
static int F_96 ( struct V_5 * V_141 ,
struct V_142 * V_143 )
{
struct V_36 * V_37 = V_143 -> V_37 ;
struct V_144 * V_145 ;
unsigned char * V_146 ;
T_8 V_147 ;
if ( V_37 -> V_65 != V_148 )
return 0 ;
if ( ! F_97 ( V_37 ) )
return 0 ;
if ( V_37 -> V_63 ) {
if ( ! F_88 ( V_37 ) )
goto V_149;
V_146 = F_94 ( V_37 ) ;
} else {
V_146 = F_83 ( V_37 ) ;
}
V_147 = ( V_146 - V_37 -> V_52 ) + ( ( (struct V_150 * ) V_146 ) -> V_151 << 2 ) ;
V_143 -> V_152 |= V_153 ;
V_143 -> V_154 = F_41 ( V_37 ) -> V_154 ;
V_143 -> V_155 += ( V_143 -> V_154 - 1 ) * V_147 ;
V_145 = F_98 ( V_141 , V_141 -> V_21 ) ;
V_145 -> V_147 = V_147 ;
V_145 -> V_156 = F_64 ( F_41 ( V_37 ) -> V_157 ) ;
return 1 ;
V_149:
V_141 -> V_54 -> V_55 &= ~ V_158 ;
if ( ! F_99 () )
F_100 ( V_141 -> V_54 ,
L_4 ) ;
return - 1 ;
}
static void F_101 ( struct V_5 * V_141 ,
struct V_142 * V_143 )
{
struct V_36 * V_37 = V_143 -> V_37 ;
struct V_144 * V_145 ;
union {
struct V_159 * V_160 ;
struct V_161 * V_162 ;
T_8 * V_163 ;
} V_164 ;
T_7 V_88 ;
T_8 V_126 = 0 ;
if ( V_37 -> V_65 != V_148 )
goto V_165;
if ( V_37 -> V_63 ) {
V_88 = F_88 ( V_37 ) ;
if ( ! V_88 ) {
if ( F_102 ( V_37 ) ) {
F_103 ( V_141 -> V_13 ,
L_5 ) ;
V_141 -> V_166 . V_61 ++ ;
}
goto V_165;
}
V_164 . V_163 = F_104 ( V_37 ) ;
} else {
V_88 = F_86 ( V_37 ) ;
V_164 . V_163 = F_87 ( V_37 ) ;
}
switch ( V_88 ) {
case F_68 ( V_122 ) :
V_126 = V_164 . V_160 -> V_88 ;
break;
case F_68 ( V_134 ) :
V_126 = V_164 . V_162 -> V_135 ;
break;
default:
if ( F_14 ( F_99 () ) ) {
F_103 ( V_141 -> V_13 ,
L_6 ,
V_88 ) ;
}
V_141 -> V_166 . V_61 ++ ;
goto V_165;
}
switch ( V_126 ) {
case V_139 :
case V_136 :
break;
case V_137 :
if ( V_37 -> V_63 )
break;
default:
if ( F_14 ( F_99 () ) ) {
F_103 ( V_141 -> V_13 ,
L_7 ,
V_126 ) ;
}
V_141 -> V_166 . V_61 ++ ;
goto V_165;
}
V_143 -> V_152 |= V_153 ;
V_165:
V_145 = F_98 ( V_141 , V_141 -> V_21 ) ;
V_145 -> V_147 = 0 ;
V_145 -> V_156 = 0 ;
}
static T_8 F_105 ( struct V_36 * V_37 , T_6 V_152 )
{
T_6 V_167 = 0 ;
if ( F_14 ( F_41 ( V_37 ) -> V_152 & V_168 ) &&
F_12 ( F_41 ( V_37 ) -> V_152 & V_169 ) )
V_167 |= V_170 ;
V_167 |= F_106 ( V_152 , V_153 ,
V_171 ) ;
return V_167 ;
}
static bool F_107 ( struct V_5 * V_141 ,
struct V_144 * V_145 , T_4 V_20 ,
T_3 V_10 , unsigned int V_39 , T_8 V_167 )
{
if ( ( ++ V_20 & ( V_172 - 1 ) ) == 0 )
V_167 |= V_173 | V_174 ;
V_145 -> V_175 = F_20 ( V_10 ) ;
V_145 -> V_79 = V_167 ;
V_145 -> V_176 = F_64 ( V_39 ) ;
return V_20 == V_141 -> V_23 ;
}
static int F_108 ( struct V_5 * V_141 , T_4 V_39 )
{
F_109 ( V_141 -> V_54 , V_141 -> V_94 ) ;
F_110 () ;
if ( F_12 ( F_76 ( V_141 ) < V_39 ) )
return - V_177 ;
F_111 ( V_141 -> V_54 , V_141 -> V_94 ) ;
++ V_141 -> V_166 . V_178 ;
return 0 ;
}
static inline int F_112 ( struct V_5 * V_141 , T_4 V_39 )
{
if ( F_12 ( F_76 ( V_141 ) >= V_39 ) )
return 0 ;
return F_108 ( V_141 , V_39 ) ;
}
static void F_113 ( struct V_5 * V_141 ,
struct V_142 * V_143 )
{
struct V_36 * V_37 = V_143 -> V_37 ;
struct V_142 * V_179 ;
struct V_144 * V_145 ;
struct V_180 * V_181 ;
unsigned char * V_52 ;
T_3 V_10 ;
unsigned int V_182 , V_39 ;
T_6 V_152 = V_143 -> V_152 ;
T_4 V_20 = V_141 -> V_21 ;
T_8 V_79 = F_105 ( V_37 , V_152 ) ;
V_145 = F_98 ( V_141 , V_20 ) ;
if ( F_114 ( V_37 ) )
V_145 -> V_93 = F_64 ( F_115 ( V_37 ) ) ;
else
V_145 -> V_93 = 0 ;
V_39 = F_116 ( V_37 ) ;
V_52 = V_37 -> V_52 ;
V_10 = F_117 ( V_141 -> V_13 , V_52 , V_39 , V_183 ) ;
V_182 = V_37 -> V_182 ;
V_179 = V_143 ;
for ( V_181 = & F_41 ( V_37 ) -> V_184 [ 0 ] ; ; V_181 ++ ) {
if ( F_16 ( V_141 -> V_13 , V_10 ) )
goto V_185;
F_118 ( V_179 , V_89 , V_39 ) ;
F_119 ( V_179 , V_10 , V_10 ) ;
while ( F_14 ( V_39 > V_186 ) ) {
if ( F_107 ( V_141 , V_145 ++ , V_20 ++ , V_10 ,
V_186 , V_79 ) ) {
V_145 = F_98 ( V_141 , 0 ) ;
V_20 = 0 ;
}
V_10 += V_186 ;
V_39 -= V_186 ;
}
if ( F_12 ( ! V_182 ) )
break;
if ( F_107 ( V_141 , V_145 ++ , V_20 ++ ,
V_10 , V_39 , V_79 ) ) {
V_145 = F_98 ( V_141 , 0 ) ;
V_20 = 0 ;
}
V_39 = F_120 ( V_181 ) ;
V_182 -= V_39 ;
V_10 = F_121 ( V_141 -> V_13 , V_181 , 0 , V_39 ,
V_183 ) ;
V_179 = & V_141 -> V_179 [ V_20 ] ;
}
V_79 |= V_187 ;
if ( F_107 ( V_141 , V_145 , V_20 ++ , V_10 , V_39 , V_79 ) )
V_20 = 0 ;
F_122 ( F_123 ( V_141 ) , V_143 -> V_155 ) ;
F_124 ( V_143 -> V_37 ) ;
F_21 () ;
V_143 -> V_188 = V_145 ;
V_141 -> V_21 = V_20 ;
F_112 ( V_141 , V_189 ) ;
if ( F_125 ( F_123 ( V_141 ) ) || ! V_37 -> V_190 ) {
F_22 ( V_20 , V_141 -> V_29 ) ;
F_126 () ;
}
return;
V_185:
F_127 ( V_141 -> V_13 , L_8 ) ;
for (; ; ) {
V_179 = & V_141 -> V_179 [ V_20 ] ;
F_128 ( V_141 , V_179 ) ;
if ( V_179 == V_143 )
break;
if ( V_20 == 0 )
V_20 = V_141 -> V_23 ;
V_20 -- ;
}
V_141 -> V_21 = V_20 ;
}
T_9 F_129 ( struct V_36 * V_37 ,
struct V_5 * V_141 )
{
struct V_142 * V_143 ;
int V_191 ;
T_6 V_152 = 0 ;
#if V_14 > V_186
unsigned short V_192 ;
#endif
T_4 V_23 = F_130 ( F_116 ( V_37 ) ) ;
#if V_14 > V_186
for ( V_192 = 0 ; V_192 < F_41 ( V_37 ) -> V_45 ; V_192 ++ )
V_23 += F_130 ( F_41 ( V_37 ) -> V_184 [ V_192 ] . V_39 ) ;
#else
V_23 += F_41 ( V_37 ) -> V_45 ;
#endif
if ( F_112 ( V_141 , V_23 + 3 ) ) {
V_141 -> V_166 . V_193 ++ ;
return V_194 ;
}
V_143 = & V_141 -> V_179 [ V_141 -> V_21 ] ;
V_143 -> V_37 = V_37 ;
V_143 -> V_155 = F_131 (unsigned int, skb->len, ETH_ZLEN) ;
V_143 -> V_154 = 1 ;
V_143 -> V_152 = V_152 ;
V_191 = F_96 ( V_141 , V_143 ) ;
if ( V_191 < 0 )
goto V_195;
else if ( ! V_191 )
F_101 ( V_141 , V_143 ) ;
F_113 ( V_141 , V_143 ) ;
return V_196 ;
V_195:
F_71 ( V_143 -> V_37 ) ;
V_143 -> V_37 = NULL ;
return V_196 ;
}
static T_10 F_132 ( struct V_5 * V_53 )
{
return V_53 -> V_108 . V_109 ;
}
static T_10 F_133 ( struct V_5 * V_53 )
{
T_6 V_197 = V_53 -> V_47 ;
T_6 V_29 = V_53 -> V_21 ;
return ( ( V_197 <= V_29 ) ? V_29 : V_29 + V_53 -> V_23 ) - V_197 ;
}
bool F_134 ( struct V_5 * V_141 )
{
T_6 V_198 = F_132 ( V_141 ) ;
T_6 V_199 = V_141 -> V_166 . V_199 ;
T_6 V_200 = F_133 ( V_141 ) ;
F_135 ( V_141 ) ;
if ( ! V_200 || ( V_199 != V_198 ) ) {
V_141 -> V_166 . V_199 = V_198 ;
F_136 ( V_201 , & V_141 -> V_202 ) ;
return false ;
}
return F_137 ( V_201 , & V_141 -> V_202 ) ;
}
void F_138 ( struct V_75 * V_76 )
{
if ( ! F_139 ( V_203 , & V_76 -> V_202 ) ) {
V_76 -> V_204 ++ ;
V_76 -> V_79 |= V_205 ;
F_140 ( V_76 ) ;
}
}
static bool F_141 ( struct V_102 * V_50 ,
struct V_5 * V_141 )
{
struct V_75 * V_76 = V_50 -> V_76 ;
struct V_142 * V_179 ;
struct V_144 * V_145 ;
unsigned int V_104 = 0 , V_105 = 0 ;
unsigned int V_103 = V_50 -> V_206 . V_207 ;
unsigned int V_20 = V_141 -> V_47 ;
if ( F_139 ( V_203 , & V_76 -> V_202 ) )
return true ;
V_179 = & V_141 -> V_179 [ V_20 ] ;
V_145 = F_98 ( V_141 , V_20 ) ;
V_20 -= V_141 -> V_23 ;
do {
struct V_144 * V_208 = V_179 -> V_188 ;
if ( ! V_208 )
break;
F_142 () ;
if ( ! ( V_208 -> V_79 & V_209 ) )
break;
V_179 -> V_188 = NULL ;
V_104 += V_179 -> V_155 ;
V_105 += V_179 -> V_154 ;
F_143 ( V_179 -> V_37 ) ;
F_144 ( V_141 -> V_13 ,
F_145 ( V_179 , V_10 ) ,
F_146 ( V_179 , V_89 ) ,
V_183 ) ;
V_179 -> V_37 = NULL ;
F_118 ( V_179 , V_89 , 0 ) ;
while ( V_145 != V_208 ) {
V_179 ++ ;
V_145 ++ ;
V_20 ++ ;
if ( F_14 ( ! V_20 ) ) {
V_20 -= V_141 -> V_23 ;
V_179 = V_141 -> V_179 ;
V_145 = F_98 ( V_141 , 0 ) ;
}
if ( F_146 ( V_179 , V_89 ) ) {
F_47 ( V_141 -> V_13 ,
F_145 ( V_179 , V_10 ) ,
F_146 ( V_179 , V_89 ) ,
V_183 ) ;
F_118 ( V_179 , V_89 , 0 ) ;
}
}
V_179 ++ ;
V_145 ++ ;
V_20 ++ ;
if ( F_14 ( ! V_20 ) ) {
V_20 -= V_141 -> V_23 ;
V_179 = V_141 -> V_179 ;
V_145 = F_98 ( V_141 , 0 ) ;
}
F_44 ( V_145 ) ;
V_103 -- ;
} while ( F_12 ( V_103 ) );
V_20 += V_141 -> V_23 ;
V_141 -> V_47 = V_20 ;
F_78 ( & V_141 -> V_107 ) ;
V_141 -> V_108 . V_110 += V_104 ;
V_141 -> V_108 . V_109 += V_105 ;
F_79 ( & V_141 -> V_107 ) ;
V_50 -> V_206 . V_104 += V_104 ;
V_50 -> V_206 . V_105 += V_105 ;
if ( F_147 ( V_141 ) && F_134 ( V_141 ) ) {
struct V_210 * V_211 = & V_76 -> V_211 ;
F_148 ( V_76 , V_212 , V_141 -> V_54 ,
L_9
L_10
L_11
L_12
L_13 ,
V_141 -> V_94 ,
F_149 ( V_211 , F_150 ( V_141 -> V_213 ) ) ,
F_149 ( V_211 , F_151 ( V_141 -> V_213 ) ) ,
V_141 -> V_21 , V_20 ) ;
F_109 ( V_141 -> V_54 ,
V_141 -> V_94 ) ;
F_152 ( V_76 , V_214 , V_141 -> V_54 ,
L_14 ,
V_76 -> V_204 + 1 ,
V_141 -> V_94 ) ;
F_138 ( V_76 ) ;
return true ;
}
F_153 ( F_123 ( V_141 ) ,
V_105 , V_104 ) ;
#define F_154 min_t(u16, FM10K_MIN_TXD - 1, DESC_NEEDED * 2)
if ( F_14 ( V_105 && F_155 ( V_141 -> V_54 ) &&
( F_76 ( V_141 ) >= F_154 ) ) ) {
F_110 () ;
if ( F_156 ( V_141 -> V_54 ,
V_141 -> V_94 ) &&
! F_139 ( V_203 , & V_76 -> V_202 ) ) {
F_157 ( V_141 -> V_54 ,
V_141 -> V_94 ) ;
++ V_141 -> V_166 . V_178 ;
}
}
return ! ! V_103 ;
}
static void F_158 ( struct V_215 * V_216 )
{
unsigned int V_217 , V_109 ;
if ( ! ( V_216 -> V_218 & V_219 ) )
goto V_220;
V_109 = V_216 -> V_105 ;
if ( ! V_109 )
goto V_220;
V_217 = V_216 -> V_104 / V_109 ;
V_217 += 24 ;
if ( V_217 > 3000 )
V_217 = 3000 ;
if ( ( V_217 > 300 ) && ( V_217 < 1200 ) )
V_217 /= 3 ;
else
V_217 /= 2 ;
V_216 -> V_218 = V_217 | V_219 ;
V_220:
V_216 -> V_104 = 0 ;
V_216 -> V_105 = 0 ;
}
static void F_159 ( struct V_102 * V_50 )
{
T_6 V_218 = V_221 ;
F_158 ( & V_50 -> V_206 ) ;
F_158 ( & V_50 -> V_111 ) ;
V_218 |= ( V_50 -> V_206 . V_218 & V_222 ) ;
V_218 |= ( V_50 -> V_111 . V_218 & V_222 ) << V_223 ;
F_22 ( V_218 , V_50 -> V_218 ) ;
}
static int F_160 ( struct V_224 * V_51 , int V_103 )
{
struct V_102 * V_50 =
F_161 ( V_51 , struct V_102 , V_51 ) ;
struct V_5 * V_53 ;
int V_225 ;
bool V_226 = true ;
F_162 (ring, q_vector->tx)
V_226 &= F_141 ( V_50 , V_53 ) ;
if ( V_50 -> V_111 . V_23 > 1 )
V_225 = F_163 ( V_103 / V_50 -> V_111 . V_23 , 1 ) ;
else
V_225 = V_103 ;
F_162 (ring, q_vector->rx)
V_226 &= F_75 ( V_50 , V_53 ,
V_225 ) ;
if ( ! V_226 )
return V_103 ;
F_164 ( V_51 ) ;
F_159 ( V_50 ) ;
return 0 ;
}
static bool F_165 ( struct V_75 * V_76 )
{
struct V_81 * V_13 = V_76 -> V_54 ;
struct V_227 * V_192 ;
int V_228 , V_20 ;
int V_229 ;
V_229 = F_166 ( V_13 ) ;
if ( V_229 <= 1 )
return false ;
V_192 = & V_76 -> V_230 [ V_231 ] ;
V_192 -> V_232 = V_229 ;
V_192 -> V_233 = ( 1 << F_167 ( V_229 - 1 ) ) - 1 ;
V_228 = V_76 -> V_211 . V_234 . V_235 / V_229 ;
V_228 = 1 << ( F_167 ( V_228 ) - 1 ) ;
V_192 = & V_76 -> V_230 [ V_236 ] ;
V_228 = F_168 ( T_4 , V_228 , V_192 -> V_237 ) ;
V_192 -> V_232 = V_228 ;
V_192 -> V_233 = ( 1 << F_167 ( V_228 - 1 ) ) - 1 ;
for ( V_20 = 0 ; V_20 < V_229 ; V_20 ++ )
F_169 ( V_13 , V_20 , V_228 , V_228 * V_20 ) ;
V_76 -> V_238 = V_228 * V_229 ;
V_76 -> V_239 = V_228 * V_229 ;
return true ;
}
static bool F_170 ( struct V_75 * V_76 )
{
struct V_227 * V_192 ;
T_4 V_228 ;
V_192 = & V_76 -> V_230 [ V_236 ] ;
V_228 = F_168 ( T_4 , V_76 -> V_211 . V_234 . V_235 , V_192 -> V_237 ) ;
V_192 -> V_232 = V_228 ;
V_192 -> V_233 = ( 1 << F_167 ( V_228 - 1 ) ) - 1 ;
V_76 -> V_238 = V_228 ;
V_76 -> V_239 = V_228 ;
return true ;
}
static void F_171 ( struct V_75 * V_76 )
{
V_76 -> V_238 = 1 ;
V_76 -> V_239 = 1 ;
if ( F_165 ( V_76 ) )
return;
F_170 ( V_76 ) ;
}
static int F_172 ( struct V_75 * V_76 ,
unsigned int V_240 , unsigned int V_241 ,
unsigned int V_242 , unsigned int V_243 ,
unsigned int V_244 , unsigned int V_245 )
{
struct V_102 * V_50 ;
struct V_5 * V_53 ;
int V_246 , V_39 ;
V_246 = V_242 + V_244 ;
V_39 = sizeof( struct V_102 ) +
( sizeof( struct V_5 ) * V_246 ) ;
V_50 = F_173 ( V_39 , V_247 ) ;
if ( ! V_50 )
return - V_248 ;
F_174 ( V_76 -> V_54 , & V_50 -> V_51 ,
F_160 , V_249 ) ;
V_76 -> V_50 [ V_241 ] = V_50 ;
V_50 -> V_76 = V_76 ;
V_50 -> V_241 = V_241 ;
V_53 = V_50 -> V_53 ;
V_50 -> V_206 . V_53 = V_53 ;
V_50 -> V_206 . V_207 = V_250 ;
V_50 -> V_206 . V_218 = V_76 -> V_251 ;
V_50 -> V_206 . V_23 = V_242 ;
while ( V_242 ) {
V_53 -> V_13 = & V_76 -> V_252 -> V_13 ;
V_53 -> V_54 = V_76 -> V_54 ;
V_53 -> V_50 = V_50 ;
V_53 -> V_23 = V_76 -> V_253 ;
V_53 -> V_94 = V_243 ;
V_76 -> V_141 [ V_243 ] = V_53 ;
V_242 -- ;
V_243 += V_240 ;
V_53 ++ ;
}
V_50 -> V_111 . V_53 = V_53 ;
V_50 -> V_111 . V_218 = V_76 -> V_254 ;
V_50 -> V_111 . V_23 = V_244 ;
while ( V_244 ) {
V_53 -> V_13 = & V_76 -> V_252 -> V_13 ;
V_53 -> V_54 = V_76 -> V_54 ;
F_175 ( V_53 -> V_83 , V_76 -> V_83 ) ;
V_53 -> V_50 = V_50 ;
V_53 -> V_23 = V_76 -> V_255 ;
V_53 -> V_94 = V_245 ;
V_76 -> V_6 [ V_245 ] = V_53 ;
V_244 -- ;
V_245 += V_240 ;
V_53 ++ ;
}
F_176 ( V_50 ) ;
return 0 ;
}
static void F_177 ( struct V_75 * V_76 , int V_241 )
{
struct V_102 * V_50 = V_76 -> V_50 [ V_241 ] ;
struct V_5 * V_53 ;
F_178 ( V_50 ) ;
F_162 (ring, q_vector->tx)
V_76 -> V_141 [ V_53 -> V_94 ] = NULL ;
F_162 (ring, q_vector->rx)
V_76 -> V_6 [ V_53 -> V_94 ] = NULL ;
V_76 -> V_50 [ V_241 ] = NULL ;
F_179 ( & V_50 -> V_51 ) ;
F_180 ( V_50 , V_256 ) ;
}
static int F_181 ( struct V_75 * V_76 )
{
unsigned int V_257 = V_76 -> V_258 ;
unsigned int V_259 = V_76 -> V_238 ;
unsigned int V_260 = V_76 -> V_239 ;
unsigned int V_245 = 0 , V_243 = 0 , V_241 = 0 ;
int V_261 ;
if ( V_257 >= ( V_259 + V_260 ) ) {
for (; V_259 ; V_241 ++ ) {
V_261 = F_172 ( V_76 , V_257 , V_241 ,
0 , 0 , 1 , V_245 ) ;
if ( V_261 )
goto V_262;
V_259 -- ;
V_245 ++ ;
}
}
for (; V_241 < V_257 ; V_241 ++ ) {
int V_263 = F_182 ( V_259 , V_257 - V_241 ) ;
int V_264 = F_182 ( V_260 , V_257 - V_241 ) ;
V_261 = F_172 ( V_76 , V_257 , V_241 ,
V_264 , V_243 ,
V_263 , V_245 ) ;
if ( V_261 )
goto V_262;
V_259 -= V_263 ;
V_260 -= V_264 ;
V_245 ++ ;
V_243 ++ ;
}
return 0 ;
V_262:
V_76 -> V_239 = 0 ;
V_76 -> V_238 = 0 ;
V_76 -> V_258 = 0 ;
while ( V_241 -- )
F_177 ( V_76 , V_241 ) ;
return - V_248 ;
}
static void F_183 ( struct V_75 * V_76 )
{
int V_241 = V_76 -> V_258 ;
V_76 -> V_239 = 0 ;
V_76 -> V_238 = 0 ;
V_76 -> V_258 = 0 ;
while ( V_241 -- )
F_177 ( V_76 , V_241 ) ;
}
static void F_184 ( struct V_75 * V_76 )
{
F_185 ( V_76 -> V_252 ) ;
F_186 ( V_76 -> V_265 ) ;
V_76 -> V_265 = NULL ;
}
static int F_187 ( struct V_75 * V_76 )
{
struct V_210 * V_211 = & V_76 -> V_211 ;
int V_266 , V_267 ;
V_266 = F_163 ( V_76 -> V_238 , V_76 -> V_239 ) ;
V_266 = F_168 ( T_4 , V_266 , F_188 () ) ;
V_266 += F_189 ( V_211 ) ;
V_266 = F_168 ( int , V_266 , V_211 -> V_234 . V_268 ) ;
V_76 -> V_265 = F_190 ( V_266 , sizeof( struct V_269 ) ,
V_247 ) ;
if ( ! V_76 -> V_265 )
return - V_248 ;
for ( V_267 = 0 ; V_267 < V_266 ; V_267 ++ )
V_76 -> V_265 [ V_267 ] . V_270 = V_267 ;
V_266 = F_191 ( V_76 -> V_252 ,
V_76 -> V_265 ,
F_192 ( V_211 ) ,
V_266 ) ;
if ( V_266 < 0 ) {
F_186 ( V_76 -> V_265 ) ;
V_76 -> V_265 = NULL ;
return - V_248 ;
}
V_76 -> V_258 = V_266 - F_189 ( V_211 ) ;
return 0 ;
}
static bool F_193 ( struct V_75 * V_76 )
{
struct V_81 * V_13 = V_76 -> V_54 ;
int V_271 , V_272 , V_228 , V_20 , V_273 ;
T_4 V_274 = V_76 -> V_230 [ V_231 ] . V_233 + 1 ;
T_8 V_275 = F_166 ( V_13 ) ;
if ( V_275 <= 1 )
return false ;
V_228 = V_76 -> V_230 [ V_236 ] . V_232 ;
for ( V_271 = 0 , V_272 = 0 ; V_271 < V_275 ; V_271 ++ , V_272 += V_228 ) {
V_273 = V_271 ;
for ( V_20 = 0 ; V_20 < V_228 ; V_20 ++ ) {
V_76 -> V_141 [ V_272 + V_20 ] -> V_213 = V_273 ;
V_76 -> V_141 [ V_272 + V_20 ] -> V_276 = V_271 ;
V_76 -> V_6 [ V_272 + V_20 ] -> V_213 = V_273 ;
V_76 -> V_6 [ V_272 + V_20 ] -> V_276 = V_271 ;
V_273 += V_274 ;
}
}
return true ;
}
static void F_194 ( struct V_75 * V_76 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_76 -> V_238 ; V_20 ++ )
V_76 -> V_6 [ V_20 ] -> V_213 = V_20 ;
for ( V_20 = 0 ; V_20 < V_76 -> V_239 ; V_20 ++ )
V_76 -> V_141 [ V_20 ] -> V_213 = V_20 ;
}
static void F_195 ( struct V_75 * V_76 )
{
if ( F_193 ( V_76 ) )
return;
F_194 ( V_76 ) ;
}
static void F_196 ( struct V_75 * V_76 )
{
T_4 V_20 , V_228 = V_76 -> V_230 [ V_236 ] . V_232 ;
T_6 V_277 , V_278 ;
if ( V_76 -> V_54 -> V_279 ) {
for ( V_20 = V_280 ; V_20 -- ; ) {
V_277 = V_76 -> V_277 [ V_20 ] ;
if ( ( ( ( V_277 << 24 ) >> 24 ) < V_228 ) &&
( ( ( V_277 << 16 ) >> 24 ) < V_228 ) &&
( ( ( V_277 << 8 ) >> 24 ) < V_228 ) &&
( ( ( V_277 ) >> 24 ) < V_228 ) )
continue;
goto V_281;
}
return;
}
V_281:
for ( V_20 = V_280 ; V_20 -- ; ) {
V_278 = ( ( V_20 * 0x00040004 ) + 0x00020000 ) * V_228 ;
V_277 = ( V_278 & 0x3F803F80 ) >> 7 ;
V_278 += 0x00010001 * V_228 ;
V_277 |= ( V_278 & 0x3F803F80 ) << 1 ;
V_76 -> V_277 [ V_20 ] = V_277 ;
}
}
int F_197 ( struct V_75 * V_76 )
{
int V_261 ;
F_171 ( V_76 ) ;
V_261 = F_187 ( V_76 ) ;
if ( V_261 ) {
F_127 ( & V_76 -> V_252 -> V_13 ,
L_15 ) ;
return V_261 ;
}
V_261 = F_181 ( V_76 ) ;
if ( V_261 )
return V_261 ;
F_195 ( V_76 ) ;
F_196 ( V_76 ) ;
return 0 ;
}
void F_198 ( struct V_75 * V_76 )
{
F_183 ( V_76 ) ;
F_184 ( V_76 ) ;
}
