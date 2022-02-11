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
return ( F_26 ( V_9 ) != F_27 () ) || V_9 -> V_34 ;
}
static bool F_28 ( struct V_7 * V_22 ,
struct V_9 * V_9 ,
unsigned int T_5 V_35 )
{
if ( F_14 ( F_25 ( V_9 ) ) )
return false ;
#if ( V_14 < 8192 )
if ( F_14 ( F_29 ( V_9 ) != 1 ) )
return false ;
V_22 -> V_16 ^= V_33 ;
#else
V_22 -> V_16 += V_35 ;
if ( V_22 -> V_16 > ( V_14 - V_33 ) )
return false ;
#endif
F_30 ( & V_9 -> V_36 ) ;
return true ;
}
static bool F_31 ( struct V_7 * V_22 ,
union V_18 * V_19 ,
struct V_37 * V_38 )
{
struct V_9 * V_9 = V_22 -> V_9 ;
unsigned int V_39 = F_32 ( V_19 -> V_40 . V_41 ) ;
#if ( V_14 < 8192 )
unsigned int V_35 = V_33 ;
#else
unsigned int V_35 = F_33 ( V_39 , V_42 ) ;
#endif
if ( ( V_39 <= V_43 ) && ! F_34 ( V_38 ) ) {
unsigned char * V_44 = F_35 ( V_9 ) + V_22 -> V_16 ;
memcpy ( F_36 ( V_38 , V_39 ) , V_44 , F_33 ( V_39 , sizeof( long ) ) ) ;
if ( F_12 ( ! F_25 ( V_9 ) ) )
return true ;
F_17 ( V_9 ) ;
return false ;
}
F_37 ( V_38 , F_38 ( V_38 ) -> V_45 , V_9 ,
V_22 -> V_16 , V_39 , V_35 ) ;
return F_28 ( V_22 , V_9 , V_35 ) ;
}
static struct V_37 * F_39 ( struct V_5 * V_6 ,
union V_18 * V_19 ,
struct V_37 * V_38 )
{
struct V_7 * V_22 ;
struct V_9 * V_9 ;
V_22 = & V_6 -> V_22 [ V_6 -> V_46 ] ;
V_9 = V_22 -> V_9 ;
F_40 ( V_9 ) ;
if ( F_12 ( ! V_38 ) ) {
void * V_47 = F_35 ( V_9 ) +
V_22 -> V_16 ;
F_41 ( V_47 ) ;
#if V_42 < 128
F_41 ( V_47 + V_42 ) ;
#endif
V_38 = F_42 ( & V_6 -> V_48 -> V_49 ,
V_43 ) ;
if ( F_14 ( ! V_38 ) ) {
V_6 -> V_11 . V_12 ++ ;
return NULL ;
}
F_40 ( V_38 -> V_50 ) ;
}
F_43 ( V_6 -> V_13 ,
V_22 -> V_10 ,
V_22 -> V_16 ,
V_33 ,
V_15 ) ;
if ( F_31 ( V_22 , V_19 , V_38 ) ) {
F_23 ( V_6 , V_22 ) ;
} else {
F_44 ( V_6 -> V_13 , V_22 -> V_10 ,
V_14 , V_15 ) ;
}
V_22 -> V_9 = NULL ;
return V_38 ;
}
static inline void F_45 ( struct V_5 * V_51 ,
union V_18 * V_19 ,
struct V_37 * V_38 )
{
F_46 ( V_38 ) ;
if ( ! ( V_51 -> V_52 -> V_53 & V_54 ) )
return;
if ( F_47 ( V_19 ,
V_55 |
V_56 |
V_57 |
V_58 ) ) {
V_51 -> V_11 . V_59 ++ ;
return;
}
if ( F_47 ( V_19 , V_60 ) )
V_38 -> V_61 = true ;
else if ( ! F_47 ( V_19 , V_62 ) )
return;
V_38 -> V_63 = V_64 ;
}
static inline void F_48 ( struct V_5 * V_51 ,
union V_18 * V_19 ,
struct V_37 * V_38 )
{
T_4 V_65 ;
if ( ! ( V_51 -> V_52 -> V_53 & V_66 ) )
return;
V_65 = F_32 ( V_19 -> V_40 . V_67 ) & V_68 ;
if ( ! V_65 )
return;
F_49 ( V_38 , F_50 ( V_19 -> V_26 . V_69 ) ,
( V_70 & ( 1ul << V_65 ) ) ?
V_71 : V_72 ) ;
}
static void F_51 ( struct V_5 * V_6 ,
union V_18 * V_19 ,
struct V_37 * V_38 )
{
struct V_73 * V_74 = V_6 -> V_48 -> V_74 ;
F_52 ( V_38 ) -> V_75 = V_19 -> V_24 . V_76 ;
if ( F_14 ( V_74 -> V_77 & V_78 ) )
F_53 ( V_74 , F_54 ( V_38 ) ,
F_55 ( V_19 -> V_24 . V_76 ) ) ;
}
static void F_56 ( struct V_5 * V_6 ,
union V_18 T_5 * V_19 ,
struct V_37 * V_38 )
{
struct V_79 * V_13 = V_6 -> V_52 ;
struct V_80 * V_81 = F_57 ( V_6 -> V_81 ) ;
if ( V_81 ) {
T_4 V_82 = F_32 ( F_52 ( V_38 ) -> V_83 . V_40 . V_84 ) - 1 ;
V_82 -= V_81 -> V_84 ;
if ( V_82 < V_81 -> V_39 && V_81 -> V_85 [ V_82 ] )
V_13 = V_81 -> V_85 [ V_82 ] ;
else
V_81 = NULL ;
}
V_38 -> V_86 = F_58 ( V_38 , V_13 ) ;
if ( ! V_81 )
return;
F_59 ( F_60 ( V_13 ) , V_38 -> V_87 + V_88 , 1 ,
! ! ( V_19 -> V_40 . V_89 &
F_61 ( V_90 ) ) ) ;
}
static unsigned int F_62 ( struct V_5 * V_6 ,
union V_18 * V_19 ,
struct V_37 * V_38 )
{
unsigned int V_87 = V_38 -> V_87 ;
F_48 ( V_6 , V_19 , V_38 ) ;
F_45 ( V_6 , V_19 , V_38 ) ;
F_51 ( V_6 , V_19 , V_38 ) ;
F_52 ( V_38 ) -> V_83 . V_40 . V_91 = V_19 -> V_40 . V_91 ;
F_63 ( V_38 , V_6 -> V_92 ) ;
F_52 ( V_38 ) -> V_83 . V_26 . V_93 = V_19 -> V_26 . V_93 ;
if ( V_19 -> V_40 . V_91 ) {
T_4 V_94 = F_32 ( V_19 -> V_40 . V_91 ) ;
if ( V_94 != V_6 -> V_94 )
F_64 ( V_38 , F_65 ( V_95 ) , V_94 ) ;
}
F_56 ( V_6 , V_19 , V_38 ) ;
return V_87 ;
}
static bool F_66 ( struct V_5 * V_6 ,
union V_18 * V_19 )
{
T_6 V_96 = V_6 -> V_46 + 1 ;
V_96 = ( V_96 < V_6 -> V_23 ) ? V_96 : 0 ;
V_6 -> V_46 = V_96 ;
F_41 ( F_19 ( V_6 , V_96 ) ) ;
if ( F_12 ( F_47 ( V_19 , V_97 ) ) )
return false ;
return true ;
}
static void F_67 ( struct V_37 * V_38 )
{
struct V_98 * V_99 = & F_38 ( V_38 ) -> V_100 [ 0 ] ;
unsigned char * V_44 ;
unsigned int V_101 ;
V_44 = F_68 ( V_99 ) ;
V_101 = F_69 ( V_44 , V_43 ) ;
F_70 ( V_38 , V_44 , F_33 ( V_101 , sizeof( long ) ) ) ;
F_71 ( V_99 , V_101 ) ;
V_99 -> V_16 += V_101 ;
V_38 -> V_102 -= V_101 ;
V_38 -> V_29 += V_101 ;
}
static bool F_72 ( struct V_5 * V_6 ,
union V_18 * V_19 ,
struct V_37 * V_38 )
{
if ( F_14 ( ( F_47 ( V_19 ,
V_103 ) ) ) ) {
F_73 ( V_38 ) ;
V_6 -> V_11 . V_104 ++ ;
return true ;
}
if ( F_34 ( V_38 ) )
F_67 ( V_38 ) ;
if ( F_74 ( V_38 ) )
return true ;
return false ;
}
static void F_75 ( struct V_105 * V_48 ,
struct V_37 * V_38 )
{
F_76 ( & V_48 -> V_49 , V_38 ) ;
}
static bool F_77 ( struct V_105 * V_48 ,
struct V_5 * V_6 ,
int V_106 )
{
struct V_37 * V_38 = V_6 -> V_38 ;
unsigned int V_107 = 0 , V_108 = 0 ;
T_4 V_17 = F_78 ( V_6 ) ;
while ( F_12 ( V_108 < V_106 ) ) {
union V_18 * V_19 ;
if ( V_17 >= V_109 ) {
F_18 ( V_6 , V_17 ) ;
V_17 = 0 ;
}
V_19 = F_19 ( V_6 , V_6 -> V_46 ) ;
if ( ! V_19 -> V_26 . V_27 )
break;
F_79 () ;
V_38 = F_39 ( V_6 , V_19 , V_38 ) ;
if ( ! V_38 )
break;
V_17 ++ ;
if ( F_66 ( V_6 , V_19 ) )
continue;
if ( F_72 ( V_6 , V_19 , V_38 ) ) {
V_38 = NULL ;
continue;
}
V_107 += F_62 ( V_6 , V_19 , V_38 ) ;
F_75 ( V_48 , V_38 ) ;
V_38 = NULL ;
V_108 ++ ;
}
V_6 -> V_38 = V_38 ;
F_80 ( & V_6 -> V_110 ) ;
V_6 -> V_111 . V_112 += V_108 ;
V_6 -> V_111 . V_113 += V_107 ;
F_81 ( & V_6 -> V_110 ) ;
V_48 -> V_114 . V_108 += V_108 ;
V_48 -> V_114 . V_107 += V_107 ;
return V_108 < V_106 ;
}
static struct V_115 * F_82 ( struct V_37 * V_38 )
{
struct V_73 * V_74 = F_60 ( V_38 -> V_13 ) ;
struct V_116 * V_117 ;
V_117 = F_83 ( & V_74 -> V_117 ,
struct V_116 , V_118 ) ;
if ( ! V_117 )
return NULL ;
if ( V_117 -> V_119 != F_84 ( V_38 ) -> V_120 )
return NULL ;
return (struct V_115 * ) ( F_85 ( V_38 ) + V_121 ) ;
}
static struct V_115 * F_86 ( struct V_37 * V_38 )
{
struct V_122 * V_123 ;
int V_124 = F_87 ( V_38 ) ;
if ( F_88 ( V_38 ) != F_65 ( V_125 ) )
return NULL ;
V_123 = (struct V_122 * ) ( F_89 ( V_38 ) + V_124 ) ;
if ( V_123 -> V_77 & V_126 )
return NULL ;
if ( V_123 -> V_77 & V_127 )
return (struct V_115 * ) ( V_123 + 1 ) ;
return (struct V_115 * ) ( & V_123 -> V_128 ) ;
}
T_7 F_90 ( struct V_37 * V_38 )
{
T_8 V_129 = 0 , V_130 = 0 , V_131 ;
struct V_115 * V_132 ;
if ( V_38 -> V_133 != V_134 ||
V_38 -> V_135 != F_65 ( V_136 ) )
return 0 ;
switch ( F_88 ( V_38 ) ) {
case F_65 ( V_125 ) :
V_129 = F_91 ( V_38 ) -> V_86 ;
break;
case F_65 ( V_137 ) :
V_129 = F_92 ( V_38 ) -> V_138 ;
break;
default:
return 0 ;
}
switch ( V_129 ) {
case V_139 :
V_132 = F_82 ( V_38 ) ;
break;
case V_140 :
V_132 = F_86 ( V_38 ) ;
break;
default:
return 0 ;
}
if ( ! V_132 )
return 0 ;
switch ( V_132 -> V_141 ) {
case F_65 ( V_125 ) :
V_130 = F_93 ( V_38 ) -> V_86 ;
break;
case F_65 ( V_137 ) :
V_130 = F_94 ( V_38 ) -> V_138 ;
break;
default:
return 0 ;
}
switch ( V_130 ) {
case V_142 :
V_131 = F_95 ( V_38 ) ;
break;
case V_139 :
V_131 = 8 ;
break;
default:
return 0 ;
}
if ( F_96 ( V_38 ) + V_131 -
F_97 ( V_38 ) > V_143 )
return 0 ;
return V_132 -> V_141 ;
}
static int F_98 ( struct V_5 * V_144 ,
struct V_145 * V_146 )
{
struct V_37 * V_38 = V_146 -> V_38 ;
struct V_147 * V_148 ;
unsigned char * V_149 ;
T_8 V_150 ;
if ( V_38 -> V_63 != V_151 )
return 0 ;
if ( ! F_99 ( V_38 ) )
return 0 ;
if ( V_38 -> V_61 ) {
if ( ! F_90 ( V_38 ) )
goto V_152;
V_149 = F_96 ( V_38 ) ;
} else {
V_149 = F_85 ( V_38 ) ;
}
V_150 = ( V_149 - V_38 -> V_50 ) + ( ( (struct V_153 * ) V_149 ) -> V_154 << 2 ) ;
V_146 -> V_155 |= V_156 ;
V_146 -> V_157 = F_38 ( V_38 ) -> V_157 ;
V_146 -> V_158 += ( V_146 -> V_157 - 1 ) * V_150 ;
V_148 = F_100 ( V_144 , V_144 -> V_21 ) ;
V_148 -> V_150 = V_150 ;
V_148 -> V_159 = F_61 ( F_38 ( V_38 ) -> V_160 ) ;
return 1 ;
V_152:
V_144 -> V_52 -> V_53 &= ~ V_161 ;
if ( ! F_101 () )
F_102 ( V_144 -> V_52 ,
L_4 ) ;
return - 1 ;
}
static void F_103 ( struct V_5 * V_144 ,
struct V_145 * V_146 )
{
struct V_37 * V_38 = V_146 -> V_38 ;
struct V_147 * V_148 ;
union {
struct V_162 * V_163 ;
struct V_164 * V_165 ;
T_8 * V_166 ;
} V_167 ;
T_7 V_86 ;
T_8 V_129 = 0 ;
if ( V_38 -> V_63 != V_151 )
goto V_168;
if ( V_38 -> V_61 ) {
V_86 = F_90 ( V_38 ) ;
if ( ! V_86 ) {
if ( F_104 ( V_38 ) ) {
F_105 ( V_144 -> V_13 ,
L_5 ) ;
V_144 -> V_169 . V_59 ++ ;
}
goto V_168;
}
V_167 . V_166 = F_106 ( V_38 ) ;
} else {
V_86 = F_88 ( V_38 ) ;
V_167 . V_166 = F_89 ( V_38 ) ;
}
switch ( V_86 ) {
case F_65 ( V_125 ) :
V_129 = V_167 . V_163 -> V_86 ;
break;
case F_65 ( V_137 ) :
V_129 = V_167 . V_165 -> V_138 ;
break;
default:
if ( F_14 ( F_101 () ) ) {
F_105 ( V_144 -> V_13 ,
L_6 ,
V_86 ) ;
}
V_144 -> V_169 . V_59 ++ ;
goto V_168;
}
switch ( V_129 ) {
case V_142 :
case V_139 :
break;
case V_140 :
if ( V_38 -> V_61 )
break;
default:
if ( F_14 ( F_101 () ) ) {
F_105 ( V_144 -> V_13 ,
L_7 ,
V_129 ) ;
}
V_144 -> V_169 . V_59 ++ ;
goto V_168;
}
V_146 -> V_155 |= V_156 ;
V_168:
V_148 = F_100 ( V_144 , V_144 -> V_21 ) ;
V_148 -> V_150 = 0 ;
V_148 -> V_159 = 0 ;
}
static T_8 F_107 ( struct V_37 * V_38 , T_6 V_155 )
{
T_6 V_170 = 0 ;
if ( F_14 ( F_38 ( V_38 ) -> V_155 & V_171 ) &&
F_12 ( F_38 ( V_38 ) -> V_155 & V_172 ) )
V_170 |= V_173 ;
V_170 |= F_108 ( V_155 , V_156 ,
V_174 ) ;
return V_170 ;
}
static bool F_109 ( struct V_5 * V_144 ,
struct V_147 * V_148 , T_4 V_20 ,
T_3 V_10 , unsigned int V_39 , T_8 V_170 )
{
if ( ( ++ V_20 & ( V_175 - 1 ) ) == 0 )
V_170 |= V_176 | V_177 ;
V_148 -> V_178 = F_20 ( V_10 ) ;
V_148 -> V_77 = V_170 ;
V_148 -> V_179 = F_61 ( V_39 ) ;
return V_20 == V_144 -> V_23 ;
}
static int F_110 ( struct V_5 * V_144 , T_4 V_39 )
{
F_111 ( V_144 -> V_52 , V_144 -> V_92 ) ;
F_112 () ;
if ( F_12 ( F_78 ( V_144 ) < V_39 ) )
return - V_180 ;
F_113 ( V_144 -> V_52 , V_144 -> V_92 ) ;
++ V_144 -> V_169 . V_181 ;
return 0 ;
}
static inline int F_114 ( struct V_5 * V_144 , T_4 V_39 )
{
if ( F_12 ( F_78 ( V_144 ) >= V_39 ) )
return 0 ;
return F_110 ( V_144 , V_39 ) ;
}
static void F_115 ( struct V_5 * V_144 ,
struct V_145 * V_146 )
{
struct V_37 * V_38 = V_146 -> V_38 ;
struct V_145 * V_182 ;
struct V_147 * V_148 ;
struct V_98 * V_99 ;
unsigned char * V_50 ;
T_3 V_10 ;
unsigned int V_102 , V_39 ;
T_6 V_155 = V_146 -> V_155 ;
T_4 V_20 = V_144 -> V_21 ;
T_8 V_77 = F_107 ( V_38 , V_155 ) ;
V_148 = F_100 ( V_144 , V_20 ) ;
if ( F_116 ( V_38 ) )
V_148 -> V_91 = F_61 ( F_117 ( V_38 ) ) ;
else
V_148 -> V_91 = 0 ;
V_39 = F_118 ( V_38 ) ;
V_50 = V_38 -> V_50 ;
V_10 = F_119 ( V_144 -> V_13 , V_50 , V_39 , V_183 ) ;
V_102 = V_38 -> V_102 ;
V_182 = V_146 ;
for ( V_99 = & F_38 ( V_38 ) -> V_100 [ 0 ] ; ; V_99 ++ ) {
if ( F_16 ( V_144 -> V_13 , V_10 ) )
goto V_184;
F_120 ( V_182 , V_87 , V_39 ) ;
F_121 ( V_182 , V_10 , V_10 ) ;
while ( F_14 ( V_39 > V_185 ) ) {
if ( F_109 ( V_144 , V_148 ++ , V_20 ++ , V_10 ,
V_185 , V_77 ) ) {
V_148 = F_100 ( V_144 , 0 ) ;
V_20 = 0 ;
}
V_10 += V_185 ;
V_39 -= V_185 ;
}
if ( F_12 ( ! V_102 ) )
break;
if ( F_109 ( V_144 , V_148 ++ , V_20 ++ ,
V_10 , V_39 , V_77 ) ) {
V_148 = F_100 ( V_144 , 0 ) ;
V_20 = 0 ;
}
V_39 = F_122 ( V_99 ) ;
V_102 -= V_39 ;
V_10 = F_123 ( V_144 -> V_13 , V_99 , 0 , V_39 ,
V_183 ) ;
V_182 = & V_144 -> V_182 [ V_20 ] ;
}
V_77 |= V_186 ;
if ( F_109 ( V_144 , V_148 , V_20 ++ , V_10 , V_39 , V_77 ) )
V_20 = 0 ;
F_124 ( F_125 ( V_144 ) , V_146 -> V_158 ) ;
F_126 ( V_146 -> V_38 ) ;
F_21 () ;
V_146 -> V_187 = V_148 ;
V_144 -> V_21 = V_20 ;
F_114 ( V_144 , V_188 ) ;
if ( F_127 ( F_125 ( V_144 ) ) || ! V_38 -> V_189 ) {
F_22 ( V_20 , V_144 -> V_29 ) ;
F_128 () ;
}
return;
V_184:
F_129 ( V_144 -> V_13 , L_8 ) ;
for (; ; ) {
V_182 = & V_144 -> V_182 [ V_20 ] ;
F_130 ( V_144 , V_182 ) ;
if ( V_182 == V_146 )
break;
if ( V_20 == 0 )
V_20 = V_144 -> V_23 ;
V_20 -- ;
}
V_144 -> V_21 = V_20 ;
}
T_9 F_131 ( struct V_37 * V_38 ,
struct V_5 * V_144 )
{
struct V_145 * V_146 ;
int V_190 ;
T_6 V_155 = 0 ;
#if V_14 > V_185
unsigned short V_191 ;
#endif
T_4 V_23 = F_132 ( F_118 ( V_38 ) ) ;
#if V_14 > V_185
for ( V_191 = 0 ; V_191 < F_38 ( V_38 ) -> V_45 ; V_191 ++ )
V_23 += F_132 ( F_38 ( V_38 ) -> V_100 [ V_191 ] . V_39 ) ;
#else
V_23 += F_38 ( V_38 ) -> V_45 ;
#endif
if ( F_114 ( V_144 , V_23 + 3 ) ) {
V_144 -> V_169 . V_192 ++ ;
return V_193 ;
}
V_146 = & V_144 -> V_182 [ V_144 -> V_21 ] ;
V_146 -> V_38 = V_38 ;
V_146 -> V_158 = F_133 (unsigned int, skb->len, ETH_ZLEN) ;
V_146 -> V_157 = 1 ;
V_146 -> V_155 = V_155 ;
V_190 = F_98 ( V_144 , V_146 ) ;
if ( V_190 < 0 )
goto V_194;
else if ( ! V_190 )
F_103 ( V_144 , V_146 ) ;
F_115 ( V_144 , V_146 ) ;
return V_195 ;
V_194:
F_73 ( V_146 -> V_38 ) ;
V_146 -> V_38 = NULL ;
return V_195 ;
}
static T_10 F_134 ( struct V_5 * V_51 )
{
return V_51 -> V_111 . V_112 ;
}
static T_10 F_135 ( struct V_5 * V_51 )
{
T_6 V_196 = V_51 -> V_46 ;
T_6 V_29 = V_51 -> V_21 ;
return ( ( V_196 <= V_29 ) ? V_29 : V_29 + V_51 -> V_23 ) - V_196 ;
}
bool F_136 ( struct V_5 * V_144 )
{
T_6 V_197 = F_134 ( V_144 ) ;
T_6 V_198 = V_144 -> V_169 . V_198 ;
T_6 V_199 = F_135 ( V_144 ) ;
F_137 ( V_144 ) ;
if ( ! V_199 || ( V_198 != V_197 ) ) {
V_144 -> V_169 . V_198 = V_197 ;
F_138 ( V_200 , & V_144 -> V_201 ) ;
return false ;
}
return F_139 ( V_200 , & V_144 -> V_201 ) ;
}
void F_140 ( struct V_73 * V_74 )
{
if ( ! F_141 ( V_202 , & V_74 -> V_201 ) ) {
V_74 -> V_203 ++ ;
V_74 -> V_77 |= V_204 ;
F_142 ( V_74 ) ;
}
}
static bool F_143 ( struct V_105 * V_48 ,
struct V_5 * V_144 )
{
struct V_73 * V_74 = V_48 -> V_74 ;
struct V_145 * V_182 ;
struct V_147 * V_148 ;
unsigned int V_107 = 0 , V_108 = 0 ;
unsigned int V_106 = V_48 -> V_205 . V_206 ;
unsigned int V_20 = V_144 -> V_46 ;
if ( F_141 ( V_202 , & V_74 -> V_201 ) )
return true ;
V_182 = & V_144 -> V_182 [ V_20 ] ;
V_148 = F_100 ( V_144 , V_20 ) ;
V_20 -= V_144 -> V_23 ;
do {
struct V_147 * V_207 = V_182 -> V_187 ;
if ( ! V_207 )
break;
F_144 () ;
if ( ! ( V_207 -> V_77 & V_208 ) )
break;
V_182 -> V_187 = NULL ;
V_107 += V_182 -> V_158 ;
V_108 += V_182 -> V_157 ;
F_145 ( V_182 -> V_38 ) ;
F_146 ( V_144 -> V_13 ,
F_147 ( V_182 , V_10 ) ,
F_148 ( V_182 , V_87 ) ,
V_183 ) ;
V_182 -> V_38 = NULL ;
F_120 ( V_182 , V_87 , 0 ) ;
while ( V_148 != V_207 ) {
V_182 ++ ;
V_148 ++ ;
V_20 ++ ;
if ( F_14 ( ! V_20 ) ) {
V_20 -= V_144 -> V_23 ;
V_182 = V_144 -> V_182 ;
V_148 = F_100 ( V_144 , 0 ) ;
}
if ( F_148 ( V_182 , V_87 ) ) {
F_44 ( V_144 -> V_13 ,
F_147 ( V_182 , V_10 ) ,
F_148 ( V_182 , V_87 ) ,
V_183 ) ;
F_120 ( V_182 , V_87 , 0 ) ;
}
}
V_182 ++ ;
V_148 ++ ;
V_20 ++ ;
if ( F_14 ( ! V_20 ) ) {
V_20 -= V_144 -> V_23 ;
V_182 = V_144 -> V_182 ;
V_148 = F_100 ( V_144 , 0 ) ;
}
F_41 ( V_148 ) ;
V_106 -- ;
} while ( F_12 ( V_106 ) );
V_20 += V_144 -> V_23 ;
V_144 -> V_46 = V_20 ;
F_80 ( & V_144 -> V_110 ) ;
V_144 -> V_111 . V_113 += V_107 ;
V_144 -> V_111 . V_112 += V_108 ;
F_81 ( & V_144 -> V_110 ) ;
V_48 -> V_205 . V_107 += V_107 ;
V_48 -> V_205 . V_108 += V_108 ;
if ( F_149 ( V_144 ) && F_136 ( V_144 ) ) {
struct V_209 * V_210 = & V_74 -> V_210 ;
F_150 ( V_74 , V_211 , V_144 -> V_52 ,
L_9
L_10
L_11
L_12
L_13 ,
V_144 -> V_92 ,
F_151 ( V_210 , F_152 ( V_144 -> V_212 ) ) ,
F_151 ( V_210 , F_153 ( V_144 -> V_212 ) ) ,
V_144 -> V_21 , V_20 ) ;
F_111 ( V_144 -> V_52 ,
V_144 -> V_92 ) ;
F_154 ( V_74 , V_213 , V_144 -> V_52 ,
L_14 ,
V_74 -> V_203 + 1 ,
V_144 -> V_92 ) ;
F_140 ( V_74 ) ;
return true ;
}
F_155 ( F_125 ( V_144 ) ,
V_108 , V_107 ) ;
#define F_156 min_t(u16, FM10K_MIN_TXD - 1, DESC_NEEDED * 2)
if ( F_14 ( V_108 && F_157 ( V_144 -> V_52 ) &&
( F_78 ( V_144 ) >= F_156 ) ) ) {
F_112 () ;
if ( F_158 ( V_144 -> V_52 ,
V_144 -> V_92 ) &&
! F_141 ( V_202 , & V_74 -> V_201 ) ) {
F_159 ( V_144 -> V_52 ,
V_144 -> V_92 ) ;
++ V_144 -> V_169 . V_181 ;
}
}
return ! ! V_106 ;
}
static void F_160 ( struct V_214 * V_215 )
{
unsigned int V_216 , V_112 ;
if ( ! ( V_215 -> V_217 & V_218 ) )
goto V_219;
V_112 = V_215 -> V_108 ;
if ( ! V_112 )
goto V_219;
V_216 = V_215 -> V_107 / V_112 ;
V_216 += 24 ;
if ( V_216 > 3000 )
V_216 = 3000 ;
if ( ( V_216 > 300 ) && ( V_216 < 1200 ) )
V_216 /= 3 ;
else
V_216 /= 2 ;
V_215 -> V_217 = V_216 | V_218 ;
V_219:
V_215 -> V_107 = 0 ;
V_215 -> V_108 = 0 ;
}
static void F_161 ( struct V_105 * V_48 )
{
T_6 V_217 = V_220 ;
F_160 ( & V_48 -> V_205 ) ;
F_160 ( & V_48 -> V_114 ) ;
V_217 |= ( V_48 -> V_205 . V_217 & V_221 ) ;
V_217 |= ( V_48 -> V_114 . V_217 & V_221 ) << V_222 ;
F_22 ( V_217 , V_48 -> V_217 ) ;
}
static int F_162 ( struct V_223 * V_49 , int V_106 )
{
struct V_105 * V_48 =
F_163 ( V_49 , struct V_105 , V_49 ) ;
struct V_5 * V_51 ;
int V_224 ;
bool V_225 = true ;
F_164 (ring, q_vector->tx)
V_225 &= F_143 ( V_48 , V_51 ) ;
if ( V_48 -> V_114 . V_23 > 1 )
V_224 = F_165 ( V_106 / V_48 -> V_114 . V_23 , 1 ) ;
else
V_224 = V_106 ;
F_164 (ring, q_vector->rx)
V_225 &= F_77 ( V_48 , V_51 ,
V_224 ) ;
if ( ! V_225 )
return V_106 ;
F_166 ( V_49 ) ;
F_161 ( V_48 ) ;
return 0 ;
}
static bool F_167 ( struct V_73 * V_74 )
{
struct V_79 * V_13 = V_74 -> V_52 ;
struct V_226 * V_191 ;
int V_227 , V_20 ;
int V_228 ;
V_228 = F_168 ( V_13 ) ;
if ( V_228 <= 1 )
return false ;
V_191 = & V_74 -> V_229 [ V_230 ] ;
V_191 -> V_231 = V_228 ;
V_191 -> V_232 = ( 1 << F_169 ( V_228 - 1 ) ) - 1 ;
V_227 = V_74 -> V_210 . V_233 . V_234 / V_228 ;
V_227 = 1 << ( F_169 ( V_227 ) - 1 ) ;
V_191 = & V_74 -> V_229 [ V_235 ] ;
V_227 = F_170 ( T_4 , V_227 , V_191 -> V_236 ) ;
V_191 -> V_231 = V_227 ;
V_191 -> V_232 = ( 1 << F_169 ( V_227 - 1 ) ) - 1 ;
for ( V_20 = 0 ; V_20 < V_228 ; V_20 ++ )
F_171 ( V_13 , V_20 , V_227 , V_227 * V_20 ) ;
V_74 -> V_237 = V_227 * V_228 ;
V_74 -> V_238 = V_227 * V_228 ;
return true ;
}
static bool F_172 ( struct V_73 * V_74 )
{
struct V_226 * V_191 ;
T_4 V_227 ;
V_191 = & V_74 -> V_229 [ V_235 ] ;
V_227 = F_170 ( T_4 , V_74 -> V_210 . V_233 . V_234 , V_191 -> V_236 ) ;
V_191 -> V_231 = V_227 ;
V_191 -> V_232 = ( 1 << F_169 ( V_227 - 1 ) ) - 1 ;
V_74 -> V_237 = V_227 ;
V_74 -> V_238 = V_227 ;
return true ;
}
static void F_173 ( struct V_73 * V_74 )
{
V_74 -> V_237 = 1 ;
V_74 -> V_238 = 1 ;
if ( F_167 ( V_74 ) )
return;
F_172 ( V_74 ) ;
}
static int F_174 ( struct V_73 * V_74 ,
unsigned int V_239 , unsigned int V_240 ,
unsigned int V_241 , unsigned int V_242 ,
unsigned int V_243 , unsigned int V_244 )
{
struct V_105 * V_48 ;
struct V_5 * V_51 ;
int V_245 , V_39 ;
V_245 = V_241 + V_243 ;
V_39 = sizeof( struct V_105 ) +
( sizeof( struct V_5 ) * V_245 ) ;
V_48 = F_175 ( V_39 , V_246 ) ;
if ( ! V_48 )
return - V_247 ;
F_176 ( V_74 -> V_52 , & V_48 -> V_49 ,
F_162 , V_248 ) ;
V_74 -> V_48 [ V_240 ] = V_48 ;
V_48 -> V_74 = V_74 ;
V_48 -> V_240 = V_240 ;
V_51 = V_48 -> V_51 ;
V_48 -> V_205 . V_51 = V_51 ;
V_48 -> V_205 . V_206 = V_249 ;
V_48 -> V_205 . V_217 = V_74 -> V_250 ;
V_48 -> V_205 . V_23 = V_241 ;
while ( V_241 ) {
V_51 -> V_13 = & V_74 -> V_251 -> V_13 ;
V_51 -> V_52 = V_74 -> V_52 ;
V_51 -> V_48 = V_48 ;
V_51 -> V_23 = V_74 -> V_252 ;
V_51 -> V_92 = V_242 ;
V_74 -> V_144 [ V_242 ] = V_51 ;
V_241 -- ;
V_242 += V_239 ;
V_51 ++ ;
}
V_48 -> V_114 . V_51 = V_51 ;
V_48 -> V_114 . V_217 = V_74 -> V_253 ;
V_48 -> V_114 . V_23 = V_243 ;
while ( V_243 ) {
V_51 -> V_13 = & V_74 -> V_251 -> V_13 ;
V_51 -> V_52 = V_74 -> V_52 ;
F_177 ( V_51 -> V_81 , V_74 -> V_81 ) ;
V_51 -> V_48 = V_48 ;
V_51 -> V_23 = V_74 -> V_254 ;
V_51 -> V_92 = V_244 ;
V_74 -> V_6 [ V_244 ] = V_51 ;
V_243 -- ;
V_244 += V_239 ;
V_51 ++ ;
}
F_178 ( V_48 ) ;
return 0 ;
}
static void F_179 ( struct V_73 * V_74 , int V_240 )
{
struct V_105 * V_48 = V_74 -> V_48 [ V_240 ] ;
struct V_5 * V_51 ;
F_180 ( V_48 ) ;
F_164 (ring, q_vector->tx)
V_74 -> V_144 [ V_51 -> V_92 ] = NULL ;
F_164 (ring, q_vector->rx)
V_74 -> V_6 [ V_51 -> V_92 ] = NULL ;
V_74 -> V_48 [ V_240 ] = NULL ;
F_181 ( & V_48 -> V_49 ) ;
F_182 ( V_48 , V_255 ) ;
}
static int F_183 ( struct V_73 * V_74 )
{
unsigned int V_256 = V_74 -> V_257 ;
unsigned int V_258 = V_74 -> V_237 ;
unsigned int V_259 = V_74 -> V_238 ;
unsigned int V_244 = 0 , V_242 = 0 , V_240 = 0 ;
int V_260 ;
if ( V_256 >= ( V_258 + V_259 ) ) {
for (; V_258 ; V_240 ++ ) {
V_260 = F_174 ( V_74 , V_256 , V_240 ,
0 , 0 , 1 , V_244 ) ;
if ( V_260 )
goto V_261;
V_258 -- ;
V_244 ++ ;
}
}
for (; V_240 < V_256 ; V_240 ++ ) {
int V_262 = F_184 ( V_258 , V_256 - V_240 ) ;
int V_263 = F_184 ( V_259 , V_256 - V_240 ) ;
V_260 = F_174 ( V_74 , V_256 , V_240 ,
V_263 , V_242 ,
V_262 , V_244 ) ;
if ( V_260 )
goto V_261;
V_258 -= V_262 ;
V_259 -= V_263 ;
V_244 ++ ;
V_242 ++ ;
}
return 0 ;
V_261:
V_74 -> V_238 = 0 ;
V_74 -> V_237 = 0 ;
V_74 -> V_257 = 0 ;
while ( V_240 -- )
F_179 ( V_74 , V_240 ) ;
return - V_247 ;
}
static void F_185 ( struct V_73 * V_74 )
{
int V_240 = V_74 -> V_257 ;
V_74 -> V_238 = 0 ;
V_74 -> V_237 = 0 ;
V_74 -> V_257 = 0 ;
while ( V_240 -- )
F_179 ( V_74 , V_240 ) ;
}
static void F_186 ( struct V_73 * V_74 )
{
F_187 ( V_74 -> V_251 ) ;
F_188 ( V_74 -> V_264 ) ;
V_74 -> V_264 = NULL ;
}
static int F_189 ( struct V_73 * V_74 )
{
struct V_209 * V_210 = & V_74 -> V_210 ;
int V_265 , V_266 ;
V_265 = F_165 ( V_74 -> V_237 , V_74 -> V_238 ) ;
V_265 = F_170 ( T_4 , V_265 , F_190 () ) ;
V_265 += F_191 ( V_210 ) ;
V_265 = F_170 ( int , V_265 , V_210 -> V_233 . V_267 ) ;
V_74 -> V_264 = F_192 ( V_265 , sizeof( struct V_268 ) ,
V_246 ) ;
if ( ! V_74 -> V_264 )
return - V_247 ;
for ( V_266 = 0 ; V_266 < V_265 ; V_266 ++ )
V_74 -> V_264 [ V_266 ] . V_269 = V_266 ;
V_265 = F_193 ( V_74 -> V_251 ,
V_74 -> V_264 ,
F_194 ( V_210 ) ,
V_265 ) ;
if ( V_265 < 0 ) {
F_188 ( V_74 -> V_264 ) ;
V_74 -> V_264 = NULL ;
return - V_247 ;
}
V_74 -> V_257 = V_265 - F_191 ( V_210 ) ;
return 0 ;
}
static bool F_195 ( struct V_73 * V_74 )
{
struct V_79 * V_13 = V_74 -> V_52 ;
int V_270 , V_271 , V_227 , V_20 , V_272 ;
T_4 V_273 = V_74 -> V_229 [ V_230 ] . V_232 + 1 ;
T_8 V_274 = F_168 ( V_13 ) ;
if ( V_274 <= 1 )
return false ;
V_227 = V_74 -> V_229 [ V_235 ] . V_231 ;
for ( V_270 = 0 , V_271 = 0 ; V_270 < V_274 ; V_270 ++ , V_271 += V_227 ) {
V_272 = V_270 ;
for ( V_20 = 0 ; V_20 < V_227 ; V_20 ++ ) {
V_74 -> V_144 [ V_271 + V_20 ] -> V_212 = V_272 ;
V_74 -> V_144 [ V_271 + V_20 ] -> V_275 = V_270 ;
V_74 -> V_6 [ V_271 + V_20 ] -> V_212 = V_272 ;
V_74 -> V_6 [ V_271 + V_20 ] -> V_275 = V_270 ;
V_272 += V_273 ;
}
}
return true ;
}
static void F_196 ( struct V_73 * V_74 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_74 -> V_237 ; V_20 ++ )
V_74 -> V_6 [ V_20 ] -> V_212 = V_20 ;
for ( V_20 = 0 ; V_20 < V_74 -> V_238 ; V_20 ++ )
V_74 -> V_144 [ V_20 ] -> V_212 = V_20 ;
}
static void F_197 ( struct V_73 * V_74 )
{
if ( F_195 ( V_74 ) )
return;
F_196 ( V_74 ) ;
}
static void F_198 ( struct V_73 * V_74 )
{
T_4 V_20 , V_227 = V_74 -> V_229 [ V_235 ] . V_231 ;
T_6 V_276 , V_277 ;
if ( V_74 -> V_52 -> V_278 ) {
for ( V_20 = V_279 ; V_20 -- ; ) {
V_276 = V_74 -> V_276 [ V_20 ] ;
if ( ( ( ( V_276 << 24 ) >> 24 ) < V_227 ) &&
( ( ( V_276 << 16 ) >> 24 ) < V_227 ) &&
( ( ( V_276 << 8 ) >> 24 ) < V_227 ) &&
( ( ( V_276 ) >> 24 ) < V_227 ) )
continue;
goto V_280;
}
return;
}
V_280:
for ( V_20 = V_279 ; V_20 -- ; ) {
V_277 = ( ( V_20 * 0x00040004 ) + 0x00020000 ) * V_227 ;
V_276 = ( V_277 & 0x3F803F80 ) >> 7 ;
V_277 += 0x00010001 * V_227 ;
V_276 |= ( V_277 & 0x3F803F80 ) << 1 ;
V_74 -> V_276 [ V_20 ] = V_276 ;
}
}
int F_199 ( struct V_73 * V_74 )
{
int V_260 ;
F_173 ( V_74 ) ;
V_260 = F_189 ( V_74 ) ;
if ( V_260 ) {
F_129 ( & V_74 -> V_251 -> V_13 ,
L_15 ) ;
return V_260 ;
}
V_260 = F_183 ( V_74 ) ;
if ( V_260 )
return V_260 ;
F_197 ( V_74 ) ;
F_198 ( V_74 ) ;
return 0 ;
}
void F_200 ( struct V_73 * V_74 )
{
F_185 ( V_74 ) ;
F_186 ( V_74 ) ;
}
