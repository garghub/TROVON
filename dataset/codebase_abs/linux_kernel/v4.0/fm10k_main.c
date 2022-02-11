static int T_1 F_1 ( void )
{
F_2 ( L_1 , V_1 , V_2 ) ;
F_2 ( L_2 , V_3 ) ;
F_3 () ;
return F_4 () ;
}
static void T_2 F_5 ( void )
{
F_6 () ;
F_7 () ;
}
static bool F_8 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_8 = V_7 -> V_8 ;
T_3 V_9 ;
if ( F_9 ( V_8 ) )
return true ;
V_8 = F_10 () ;
if ( F_11 ( ! V_8 ) ) {
V_5 -> V_10 . V_11 ++ ;
return false ;
}
V_9 = F_12 ( V_5 -> V_12 , V_8 , 0 , V_13 , V_14 ) ;
if ( F_13 ( V_5 -> V_12 , V_9 ) ) {
F_14 ( V_8 ) ;
V_5 -> V_10 . V_11 ++ ;
return false ;
}
V_7 -> V_9 = V_9 ;
V_7 -> V_8 = V_8 ;
V_7 -> V_15 = 0 ;
return true ;
}
void F_15 ( struct V_4 * V_5 , T_4 V_16 )
{
union V_17 * V_18 ;
struct V_6 * V_7 ;
T_4 V_19 = V_5 -> V_20 ;
if ( ! V_16 )
return;
V_18 = F_16 ( V_5 , V_19 ) ;
V_7 = & V_5 -> V_21 [ V_19 ] ;
V_19 -= V_5 -> V_22 ;
do {
if ( ! F_8 ( V_5 , V_7 ) )
break;
V_18 -> V_23 . V_24 = F_17 ( V_7 -> V_9 + V_7 -> V_15 ) ;
V_18 ++ ;
V_7 ++ ;
V_19 ++ ;
if ( F_11 ( ! V_19 ) ) {
V_18 = F_16 ( V_5 , 0 ) ;
V_7 = V_5 -> V_21 ;
V_19 -= V_5 -> V_22 ;
}
V_18 -> V_25 . V_26 = 0 ;
V_16 -- ;
} while ( V_16 );
V_19 += V_5 -> V_22 ;
if ( V_5 -> V_20 != V_19 ) {
V_5 -> V_20 = V_19 ;
V_5 -> V_27 = V_19 ;
F_18 () ;
F_19 ( V_19 , V_5 -> V_28 ) ;
}
}
static void F_20 ( struct V_4 * V_5 ,
struct V_6 * V_29 )
{
struct V_6 * V_30 ;
T_4 V_31 = V_5 -> V_27 ;
V_30 = & V_5 -> V_21 [ V_31 ] ;
V_31 ++ ;
V_5 -> V_27 = ( V_31 < V_5 -> V_22 ) ? V_31 : 0 ;
* V_30 = * V_29 ;
F_21 ( V_5 -> V_12 , V_29 -> V_9 ,
V_29 -> V_15 ,
V_32 ,
V_14 ) ;
}
static inline bool F_22 ( struct V_8 * V_8 )
{
return ( F_23 ( V_8 ) != F_24 () ) || V_8 -> V_33 ;
}
static bool F_25 ( struct V_6 * V_21 ,
struct V_8 * V_8 ,
unsigned int V_34 )
{
if ( F_11 ( F_22 ( V_8 ) ) )
return false ;
#if ( V_13 < 8192 )
if ( F_11 ( F_26 ( V_8 ) != 1 ) )
return false ;
V_21 -> V_15 ^= V_32 ;
#else
V_21 -> V_15 += V_34 ;
if ( V_21 -> V_15 > ( V_13 - V_32 ) )
return false ;
#endif
F_27 ( & V_8 -> V_35 ) ;
return true ;
}
static bool F_28 ( struct V_4 * V_5 ,
struct V_6 * V_21 ,
union V_17 * V_18 ,
struct V_36 * V_37 )
{
struct V_8 * V_8 = V_21 -> V_8 ;
unsigned int V_38 = F_29 ( V_18 -> V_39 . V_40 ) ;
#if ( V_13 < 8192 )
unsigned int V_34 = V_32 ;
#else
unsigned int V_34 = F_30 ( V_38 , V_41 ) ;
#endif
if ( ( V_38 <= V_42 ) && ! F_31 ( V_37 ) ) {
unsigned char * V_43 = F_32 ( V_8 ) + V_21 -> V_15 ;
memcpy ( F_33 ( V_37 , V_38 ) , V_43 , F_30 ( V_38 , sizeof( long ) ) ) ;
if ( F_9 ( ! F_22 ( V_8 ) ) )
return true ;
F_14 ( V_8 ) ;
return false ;
}
F_34 ( V_37 , F_35 ( V_37 ) -> V_44 , V_8 ,
V_21 -> V_15 , V_38 , V_34 ) ;
return F_25 ( V_21 , V_8 , V_34 ) ;
}
static struct V_36 * F_36 ( struct V_4 * V_5 ,
union V_17 * V_18 ,
struct V_36 * V_37 )
{
struct V_6 * V_21 ;
struct V_8 * V_8 ;
V_21 = & V_5 -> V_21 [ V_5 -> V_45 ] ;
V_8 = V_21 -> V_8 ;
F_37 ( V_8 ) ;
if ( F_9 ( ! V_37 ) ) {
void * V_46 = F_32 ( V_8 ) +
V_21 -> V_15 ;
F_38 ( V_46 ) ;
#if V_41 < 128
F_38 ( V_46 + V_41 ) ;
#endif
V_37 = F_39 ( & V_5 -> V_47 -> V_48 ,
V_42 ) ;
if ( F_11 ( ! V_37 ) ) {
V_5 -> V_10 . V_11 ++ ;
return NULL ;
}
F_37 ( V_37 -> V_49 ) ;
}
F_40 ( V_5 -> V_12 ,
V_21 -> V_9 ,
V_21 -> V_15 ,
V_32 ,
V_14 ) ;
if ( F_28 ( V_5 , V_21 , V_18 , V_37 ) ) {
F_20 ( V_5 , V_21 ) ;
} else {
F_41 ( V_5 -> V_12 , V_21 -> V_9 ,
V_13 , V_14 ) ;
}
V_21 -> V_8 = NULL ;
return V_37 ;
}
static inline void F_42 ( struct V_4 * V_50 ,
union V_17 * V_18 ,
struct V_36 * V_37 )
{
F_43 ( V_37 ) ;
if ( ! ( V_50 -> V_51 -> V_52 & V_53 ) )
return;
if ( F_44 ( V_18 ,
V_54 |
V_55 |
V_56 |
V_57 ) ) {
V_50 -> V_10 . V_58 ++ ;
return;
}
if ( F_44 ( V_18 , V_59 ) )
V_37 -> V_60 = true ;
else if ( ! F_44 ( V_18 , V_61 ) )
return;
V_37 -> V_62 = V_63 ;
}
static inline void F_45 ( struct V_4 * V_50 ,
union V_17 * V_18 ,
struct V_36 * V_37 )
{
T_4 V_64 ;
if ( ! ( V_50 -> V_51 -> V_52 & V_65 ) )
return;
V_64 = F_29 ( V_18 -> V_39 . V_66 ) & V_67 ;
if ( ! V_64 )
return;
F_46 ( V_37 , F_47 ( V_18 -> V_25 . V_68 ) ,
( V_69 & ( 1ul << V_64 ) ) ?
V_70 : V_71 ) ;
}
static void F_48 ( struct V_4 * V_5 ,
union V_17 * V_18 ,
struct V_36 * V_37 )
{
struct V_72 * V_73 = V_5 -> V_47 -> V_73 ;
F_49 ( V_37 ) -> V_74 = V_18 -> V_23 . V_75 ;
if ( F_11 ( V_73 -> V_76 & V_77 ) )
F_50 ( V_73 , F_51 ( V_37 ) ,
F_52 ( V_18 -> V_23 . V_75 ) ) ;
}
static void F_53 ( struct V_4 * V_5 ,
union V_17 * V_18 ,
struct V_36 * V_37 )
{
struct V_78 * V_12 = V_5 -> V_51 ;
struct V_79 * V_80 = F_54 ( V_5 -> V_80 ) ;
if ( V_80 ) {
T_4 V_81 = F_29 ( F_49 ( V_37 ) -> V_82 . V_39 . V_83 ) - 1 ;
V_81 -= V_80 -> V_83 ;
if ( V_81 < V_80 -> V_38 && V_80 -> V_84 [ V_81 ] )
V_12 = V_80 -> V_84 [ V_81 ] ;
else
V_80 = NULL ;
}
V_37 -> V_85 = F_55 ( V_37 , V_12 ) ;
if ( ! V_80 )
return;
F_56 ( F_57 ( V_12 ) , V_37 -> V_86 + V_87 , 1 ,
! ! ( V_18 -> V_39 . V_88 &
F_58 ( V_89 ) ) ) ;
}
static unsigned int F_59 ( struct V_4 * V_5 ,
union V_17 * V_18 ,
struct V_36 * V_37 )
{
unsigned int V_86 = V_37 -> V_86 ;
F_45 ( V_5 , V_18 , V_37 ) ;
F_42 ( V_5 , V_18 , V_37 ) ;
F_48 ( V_5 , V_18 , V_37 ) ;
F_49 ( V_37 ) -> V_82 . V_39 . V_90 = V_18 -> V_39 . V_90 ;
F_60 ( V_37 , V_5 -> V_91 ) ;
F_49 ( V_37 ) -> V_82 . V_25 . V_92 = V_18 -> V_25 . V_92 ;
if ( V_18 -> V_39 . V_90 ) {
T_4 V_93 = F_29 ( V_18 -> V_39 . V_90 ) ;
if ( V_93 != V_5 -> V_93 )
F_61 ( V_37 , F_62 ( V_94 ) , V_93 ) ;
}
F_53 ( V_5 , V_18 , V_37 ) ;
return V_86 ;
}
static bool F_63 ( struct V_4 * V_5 ,
union V_17 * V_18 )
{
T_5 V_95 = V_5 -> V_45 + 1 ;
V_95 = ( V_95 < V_5 -> V_22 ) ? V_95 : 0 ;
V_5 -> V_45 = V_95 ;
F_38 ( F_16 ( V_5 , V_95 ) ) ;
if ( F_9 ( F_44 ( V_18 , V_96 ) ) )
return false ;
return true ;
}
static void F_64 ( struct V_4 * V_5 ,
union V_17 * V_18 ,
struct V_36 * V_37 )
{
struct V_97 * V_98 = & F_35 ( V_37 ) -> V_99 [ 0 ] ;
unsigned char * V_43 ;
unsigned int V_100 ;
V_43 = F_65 ( V_98 ) ;
V_100 = F_66 ( V_43 , V_42 ) ;
F_67 ( V_37 , V_43 , F_30 ( V_100 , sizeof( long ) ) ) ;
F_68 ( V_98 , V_100 ) ;
V_98 -> V_15 += V_100 ;
V_37 -> V_101 -= V_100 ;
V_37 -> V_28 += V_100 ;
}
static bool F_69 ( struct V_4 * V_5 ,
union V_17 * V_18 ,
struct V_36 * V_37 )
{
if ( F_11 ( ( F_44 ( V_18 ,
V_102 ) ) ) ) {
F_70 ( V_37 ) ;
V_5 -> V_10 . V_103 ++ ;
return true ;
}
if ( F_31 ( V_37 ) )
F_64 ( V_5 , V_18 , V_37 ) ;
if ( F_71 ( V_37 ) )
return true ;
return false ;
}
static void F_72 ( struct V_104 * V_47 ,
struct V_36 * V_37 )
{
F_73 ( & V_47 -> V_48 , V_37 ) ;
}
static bool F_74 ( struct V_104 * V_47 ,
struct V_4 * V_5 ,
int V_105 )
{
struct V_36 * V_37 = V_5 -> V_37 ;
unsigned int V_106 = 0 , V_107 = 0 ;
T_4 V_16 = F_75 ( V_5 ) ;
do {
union V_17 * V_18 ;
if ( V_16 >= V_108 ) {
F_15 ( V_5 , V_16 ) ;
V_16 = 0 ;
}
V_18 = F_16 ( V_5 , V_5 -> V_45 ) ;
if ( ! V_18 -> V_25 . V_26 )
break;
F_76 () ;
V_37 = F_36 ( V_5 , V_18 , V_37 ) ;
if ( ! V_37 )
break;
V_16 ++ ;
if ( F_63 ( V_5 , V_18 ) )
continue;
if ( F_69 ( V_5 , V_18 , V_37 ) ) {
V_37 = NULL ;
continue;
}
V_106 += F_59 ( V_5 , V_18 , V_37 ) ;
F_72 ( V_47 , V_37 ) ;
V_37 = NULL ;
V_107 ++ ;
} while ( F_9 ( V_107 < V_105 ) );
V_5 -> V_37 = V_37 ;
F_77 ( & V_5 -> V_109 ) ;
V_5 -> V_110 . V_111 += V_107 ;
V_5 -> V_110 . V_112 += V_106 ;
F_78 ( & V_5 -> V_109 ) ;
V_47 -> V_113 . V_107 += V_107 ;
V_47 -> V_113 . V_106 += V_106 ;
return V_107 < V_105 ;
}
static struct V_114 * F_79 ( struct V_36 * V_37 )
{
struct V_72 * V_73 = F_57 ( V_37 -> V_12 ) ;
struct V_115 * V_116 ;
V_116 = F_80 ( & V_73 -> V_116 ,
struct V_115 , V_117 ) ;
if ( ! V_116 )
return NULL ;
if ( V_116 -> V_118 != F_81 ( V_37 ) -> V_119 )
return NULL ;
return (struct V_114 * ) ( F_82 ( V_37 ) + V_120 ) ;
}
static struct V_114 * F_83 ( struct V_36 * V_37 )
{
struct V_121 * V_122 ;
int V_123 = F_84 ( V_37 ) ;
if ( F_85 ( V_37 ) != F_62 ( V_124 ) )
return NULL ;
V_122 = (struct V_121 * ) ( F_86 ( V_37 ) + V_123 ) ;
if ( V_122 -> V_76 & V_125 )
return NULL ;
if ( V_122 -> V_126 != F_62 ( V_127 ) )
return NULL ;
if ( V_122 -> V_76 & V_128 )
return (struct V_114 * ) ( V_122 + 1 ) ;
return (struct V_114 * ) ( & V_122 -> V_129 ) ;
}
static T_6 F_87 ( struct V_36 * V_37 )
{
struct V_114 * V_130 ;
T_7 V_131 = 0 ;
#define F_88 164
if ( F_89 ( V_37 ) - F_90 ( V_37 ) >
F_88 )
return 0 ;
switch ( F_85 ( V_37 ) ) {
case F_62 ( V_124 ) :
V_131 = F_91 ( V_37 ) -> V_85 ;
break;
case F_62 ( V_132 ) :
V_131 = F_92 ( V_37 ) -> V_133 ;
break;
default:
return 0 ;
}
switch ( V_131 ) {
case V_134 :
V_130 = F_79 ( V_37 ) ;
break;
case V_135 :
V_130 = F_83 ( V_37 ) ;
break;
default:
return 0 ;
}
if ( ! V_130 )
return 0 ;
switch ( V_130 -> V_136 ) {
case F_62 ( V_124 ) :
case F_62 ( V_132 ) :
break;
default:
return 0 ;
}
return V_130 -> V_136 ;
}
static int F_93 ( struct V_4 * V_137 ,
struct V_138 * V_139 )
{
struct V_36 * V_37 = V_139 -> V_37 ;
struct V_140 * V_141 ;
unsigned char * V_142 ;
T_7 V_143 ;
if ( V_37 -> V_62 != V_144 )
return 0 ;
if ( ! F_94 ( V_37 ) )
return 0 ;
if ( V_37 -> V_60 ) {
if ( ! F_87 ( V_37 ) )
goto V_145;
V_142 = F_89 ( V_37 ) ;
} else {
V_142 = F_82 ( V_37 ) ;
}
V_143 = ( V_142 - V_37 -> V_49 ) + ( ( (struct V_146 * ) V_142 ) -> V_147 << 2 ) ;
V_139 -> V_148 |= V_149 ;
V_139 -> V_150 = F_35 ( V_37 ) -> V_150 ;
V_139 -> V_151 += ( V_139 -> V_150 - 1 ) * V_143 ;
V_141 = F_95 ( V_137 , V_137 -> V_20 ) ;
V_141 -> V_143 = V_143 ;
V_141 -> V_152 = F_58 ( F_35 ( V_37 ) -> V_153 ) ;
return 1 ;
V_145:
V_137 -> V_51 -> V_52 &= ~ V_154 ;
if ( ! F_96 () )
F_97 ( V_137 -> V_51 ,
L_3 ) ;
return - 1 ;
}
static void F_98 ( struct V_4 * V_137 ,
struct V_138 * V_139 )
{
struct V_36 * V_37 = V_139 -> V_37 ;
struct V_140 * V_141 ;
union {
struct V_155 * V_156 ;
struct V_157 * V_158 ;
T_7 * V_159 ;
} V_160 ;
T_6 V_85 ;
T_7 V_131 = 0 ;
if ( V_37 -> V_62 != V_144 )
goto V_161;
if ( V_37 -> V_60 ) {
V_85 = F_87 ( V_37 ) ;
if ( ! V_85 ) {
if ( F_99 ( V_37 ) ) {
F_100 ( V_137 -> V_12 ,
L_4 ) ;
V_137 -> V_162 . V_58 ++ ;
}
goto V_161;
}
V_160 . V_159 = F_101 ( V_37 ) ;
} else {
V_85 = F_85 ( V_37 ) ;
V_160 . V_159 = F_86 ( V_37 ) ;
}
switch ( V_85 ) {
case F_62 ( V_124 ) :
V_131 = V_160 . V_156 -> V_85 ;
break;
case F_62 ( V_132 ) :
V_131 = V_160 . V_158 -> V_133 ;
break;
default:
if ( F_11 ( F_96 () ) ) {
F_100 ( V_137 -> V_12 ,
L_5 ,
V_85 ) ;
}
V_137 -> V_162 . V_58 ++ ;
goto V_161;
}
switch ( V_131 ) {
case V_163 :
case V_134 :
break;
case V_135 :
if ( V_37 -> V_60 )
break;
default:
if ( F_11 ( F_96 () ) ) {
F_100 ( V_137 -> V_12 ,
L_6 ,
V_131 ) ;
}
V_137 -> V_162 . V_58 ++ ;
goto V_161;
}
V_139 -> V_148 |= V_149 ;
V_161:
V_141 = F_95 ( V_137 , V_137 -> V_20 ) ;
V_141 -> V_143 = 0 ;
V_141 -> V_152 = 0 ;
}
static T_7 F_102 ( struct V_36 * V_37 , T_5 V_148 )
{
T_5 V_164 = 0 ;
if ( F_11 ( F_35 ( V_37 ) -> V_148 & V_165 ) &&
F_9 ( F_35 ( V_37 ) -> V_148 & V_166 ) )
V_164 |= V_167 ;
V_164 |= F_103 ( V_148 , V_149 ,
V_168 ) ;
return V_164 ;
}
static bool F_104 ( struct V_4 * V_137 ,
struct V_140 * V_141 , T_4 V_19 ,
T_3 V_9 , unsigned int V_38 , T_7 V_164 )
{
if ( ( ++ V_19 & ( V_169 - 1 ) ) == 0 )
V_164 |= V_170 | V_171 ;
V_141 -> V_172 = F_17 ( V_9 ) ;
V_141 -> V_76 = V_164 ;
V_141 -> V_173 = F_58 ( V_38 ) ;
return V_19 == V_137 -> V_22 ;
}
static int F_105 ( struct V_4 * V_137 , T_4 V_38 )
{
F_106 ( V_137 -> V_51 , V_137 -> V_91 ) ;
F_107 () ;
if ( F_9 ( F_75 ( V_137 ) < V_38 ) )
return - V_174 ;
F_108 ( V_137 -> V_51 , V_137 -> V_91 ) ;
++ V_137 -> V_162 . V_175 ;
return 0 ;
}
static inline int F_109 ( struct V_4 * V_137 , T_4 V_38 )
{
if ( F_9 ( F_75 ( V_137 ) >= V_38 ) )
return 0 ;
return F_105 ( V_137 , V_38 ) ;
}
static void F_110 ( struct V_4 * V_137 ,
struct V_138 * V_139 )
{
struct V_36 * V_37 = V_139 -> V_37 ;
struct V_138 * V_176 ;
struct V_140 * V_141 ;
struct V_97 * V_98 ;
unsigned char * V_49 ;
T_3 V_9 ;
unsigned int V_101 , V_38 ;
T_5 V_148 = V_139 -> V_148 ;
T_4 V_19 = V_137 -> V_20 ;
T_7 V_76 = F_102 ( V_37 , V_148 ) ;
V_141 = F_95 ( V_137 , V_19 ) ;
if ( F_111 ( V_37 ) )
V_141 -> V_90 = F_58 ( F_112 ( V_37 ) ) ;
else
V_141 -> V_90 = 0 ;
V_38 = F_113 ( V_37 ) ;
V_49 = V_37 -> V_49 ;
V_9 = F_114 ( V_137 -> V_12 , V_49 , V_38 , V_177 ) ;
V_101 = V_37 -> V_101 ;
V_176 = V_139 ;
for ( V_98 = & F_35 ( V_37 ) -> V_99 [ 0 ] ; ; V_98 ++ ) {
if ( F_13 ( V_137 -> V_12 , V_9 ) )
goto V_178;
F_115 ( V_176 , V_86 , V_38 ) ;
F_116 ( V_176 , V_9 , V_9 ) ;
while ( F_11 ( V_38 > V_179 ) ) {
if ( F_104 ( V_137 , V_141 ++ , V_19 ++ , V_9 ,
V_179 , V_76 ) ) {
V_141 = F_95 ( V_137 , 0 ) ;
V_19 = 0 ;
}
V_9 += V_179 ;
V_38 -= V_179 ;
}
if ( F_9 ( ! V_101 ) )
break;
if ( F_104 ( V_137 , V_141 ++ , V_19 ++ ,
V_9 , V_38 , V_76 ) ) {
V_141 = F_95 ( V_137 , 0 ) ;
V_19 = 0 ;
}
V_38 = F_117 ( V_98 ) ;
V_101 -= V_38 ;
V_9 = F_118 ( V_137 -> V_12 , V_98 , 0 , V_38 ,
V_177 ) ;
V_176 = & V_137 -> V_176 [ V_19 ] ;
}
V_76 |= V_180 ;
if ( F_104 ( V_137 , V_141 , V_19 ++ , V_9 , V_38 , V_76 ) )
V_19 = 0 ;
F_119 ( F_120 ( V_137 ) , V_139 -> V_151 ) ;
F_121 ( V_139 -> V_37 ) ;
F_18 () ;
V_139 -> V_181 = V_141 ;
V_137 -> V_20 = V_19 ;
F_109 ( V_137 , V_182 ) ;
if ( F_122 ( F_120 ( V_137 ) ) || ! V_37 -> V_183 ) {
F_19 ( V_19 , V_137 -> V_28 ) ;
F_123 () ;
}
return;
V_178:
F_124 ( V_137 -> V_12 , L_7 ) ;
for (; ; ) {
V_176 = & V_137 -> V_176 [ V_19 ] ;
F_125 ( V_137 , V_176 ) ;
if ( V_176 == V_139 )
break;
if ( V_19 == 0 )
V_19 = V_137 -> V_22 ;
V_19 -- ;
}
V_137 -> V_20 = V_19 ;
}
T_8 F_126 ( struct V_36 * V_37 ,
struct V_4 * V_137 )
{
struct V_138 * V_139 ;
int V_184 ;
T_5 V_148 = 0 ;
#if V_13 > V_179
unsigned short V_185 ;
#endif
T_4 V_22 = F_127 ( F_113 ( V_37 ) ) ;
#if V_13 > V_179
for ( V_185 = 0 ; V_185 < F_35 ( V_37 ) -> V_44 ; V_185 ++ )
V_22 += F_127 ( F_35 ( V_37 ) -> V_99 [ V_185 ] . V_38 ) ;
#else
V_22 += F_35 ( V_37 ) -> V_44 ;
#endif
if ( F_109 ( V_137 , V_22 + 3 ) ) {
V_137 -> V_162 . V_186 ++ ;
return V_187 ;
}
V_139 = & V_137 -> V_176 [ V_137 -> V_20 ] ;
V_139 -> V_37 = V_37 ;
V_139 -> V_151 = F_128 (unsigned int, skb->len, ETH_ZLEN) ;
V_139 -> V_150 = 1 ;
V_139 -> V_148 = V_148 ;
V_184 = F_93 ( V_137 , V_139 ) ;
if ( V_184 < 0 )
goto V_188;
else if ( ! V_184 )
F_98 ( V_137 , V_139 ) ;
F_110 ( V_137 , V_139 ) ;
return V_189 ;
V_188:
F_70 ( V_139 -> V_37 ) ;
V_139 -> V_37 = NULL ;
return V_189 ;
}
static T_9 F_129 ( struct V_4 * V_50 )
{
return V_50 -> V_110 . V_111 ;
}
static T_9 F_130 ( struct V_4 * V_50 )
{
T_5 V_190 = V_50 -> V_45 ;
T_5 V_28 = V_50 -> V_20 ;
return ( ( V_190 <= V_28 ) ? V_28 : V_28 + V_50 -> V_22 ) - V_190 ;
}
bool F_131 ( struct V_4 * V_137 )
{
T_5 V_191 = F_129 ( V_137 ) ;
T_5 V_192 = V_137 -> V_162 . V_192 ;
T_5 V_193 = F_130 ( V_137 ) ;
F_132 ( V_137 ) ;
if ( ! V_193 || ( V_192 != V_191 ) ) {
V_137 -> V_162 . V_192 = V_191 ;
F_133 ( V_194 , & V_137 -> V_195 ) ;
return false ;
}
return F_134 ( V_194 , & V_137 -> V_195 ) ;
}
void F_135 ( struct V_72 * V_73 )
{
if ( ! F_136 ( V_196 , & V_73 -> V_195 ) ) {
F_97 ( V_73 -> V_51 , L_8 ) ;
V_73 -> V_197 ++ ;
V_73 -> V_76 |= V_198 ;
F_137 ( V_73 ) ;
}
}
static bool F_138 ( struct V_104 * V_47 ,
struct V_4 * V_137 )
{
struct V_72 * V_73 = V_47 -> V_73 ;
struct V_138 * V_176 ;
struct V_140 * V_141 ;
unsigned int V_106 = 0 , V_107 = 0 ;
unsigned int V_105 = V_47 -> V_199 . V_200 ;
unsigned int V_19 = V_137 -> V_45 ;
if ( F_136 ( V_196 , & V_73 -> V_195 ) )
return true ;
V_176 = & V_137 -> V_176 [ V_19 ] ;
V_141 = F_95 ( V_137 , V_19 ) ;
V_19 -= V_137 -> V_22 ;
do {
struct V_140 * V_201 = V_176 -> V_181 ;
if ( ! V_201 )
break;
F_139 () ;
if ( ! ( V_201 -> V_76 & V_202 ) )
break;
V_176 -> V_181 = NULL ;
V_106 += V_176 -> V_151 ;
V_107 += V_176 -> V_150 ;
F_140 ( V_176 -> V_37 ) ;
F_141 ( V_137 -> V_12 ,
F_142 ( V_176 , V_9 ) ,
F_143 ( V_176 , V_86 ) ,
V_177 ) ;
V_176 -> V_37 = NULL ;
F_115 ( V_176 , V_86 , 0 ) ;
while ( V_141 != V_201 ) {
V_176 ++ ;
V_141 ++ ;
V_19 ++ ;
if ( F_11 ( ! V_19 ) ) {
V_19 -= V_137 -> V_22 ;
V_176 = V_137 -> V_176 ;
V_141 = F_95 ( V_137 , 0 ) ;
}
if ( F_143 ( V_176 , V_86 ) ) {
F_41 ( V_137 -> V_12 ,
F_142 ( V_176 , V_9 ) ,
F_143 ( V_176 , V_86 ) ,
V_177 ) ;
F_115 ( V_176 , V_86 , 0 ) ;
}
}
V_176 ++ ;
V_141 ++ ;
V_19 ++ ;
if ( F_11 ( ! V_19 ) ) {
V_19 -= V_137 -> V_22 ;
V_176 = V_137 -> V_176 ;
V_141 = F_95 ( V_137 , 0 ) ;
}
F_38 ( V_141 ) ;
V_105 -- ;
} while ( F_9 ( V_105 ) );
V_19 += V_137 -> V_22 ;
V_137 -> V_45 = V_19 ;
F_77 ( & V_137 -> V_109 ) ;
V_137 -> V_110 . V_112 += V_106 ;
V_137 -> V_110 . V_111 += V_107 ;
F_78 ( & V_137 -> V_109 ) ;
V_47 -> V_199 . V_106 += V_106 ;
V_47 -> V_199 . V_107 += V_107 ;
if ( F_144 ( V_137 ) && F_131 ( V_137 ) ) {
struct V_203 * V_204 = & V_73 -> V_204 ;
F_145 ( V_73 , V_205 , V_137 -> V_51 ,
L_9
L_10
L_11
L_12
L_13 ,
V_137 -> V_91 ,
F_146 ( V_204 , F_147 ( V_137 -> V_206 ) ) ,
F_146 ( V_204 , F_148 ( V_137 -> V_206 ) ) ,
V_137 -> V_20 , V_19 ) ;
F_106 ( V_137 -> V_51 ,
V_137 -> V_91 ) ;
F_149 ( V_73 , V_207 , V_137 -> V_51 ,
L_14 ,
V_73 -> V_197 + 1 ,
V_137 -> V_91 ) ;
F_135 ( V_73 ) ;
return true ;
}
F_150 ( F_120 ( V_137 ) ,
V_107 , V_106 ) ;
#define F_151 min_t(u16, FM10K_MIN_TXD - 1, DESC_NEEDED * 2)
if ( F_11 ( V_107 && F_152 ( V_137 -> V_51 ) &&
( F_75 ( V_137 ) >= F_151 ) ) ) {
F_107 () ;
if ( F_153 ( V_137 -> V_51 ,
V_137 -> V_91 ) &&
! F_136 ( V_196 , & V_73 -> V_195 ) ) {
F_154 ( V_137 -> V_51 ,
V_137 -> V_91 ) ;
++ V_137 -> V_162 . V_175 ;
}
}
return ! ! V_105 ;
}
static void F_155 ( struct V_208 * V_209 )
{
unsigned int V_210 , V_111 ;
if ( ! ( V_209 -> V_211 & V_212 ) )
goto V_213;
V_111 = V_209 -> V_107 ;
if ( ! V_111 )
goto V_213;
V_210 = V_209 -> V_106 / V_111 ;
V_210 += 24 ;
if ( V_210 > 3000 )
V_210 = 3000 ;
if ( ( V_210 > 300 ) && ( V_210 < 1200 ) )
V_210 /= 3 ;
else
V_210 /= 2 ;
V_209 -> V_211 = V_210 | V_212 ;
V_213:
V_209 -> V_106 = 0 ;
V_209 -> V_107 = 0 ;
}
static void F_156 ( struct V_104 * V_47 )
{
T_5 V_211 = V_214 ;
F_155 ( & V_47 -> V_199 ) ;
F_155 ( & V_47 -> V_113 ) ;
V_211 |= ( V_47 -> V_199 . V_211 & V_215 ) ;
V_211 |= ( V_47 -> V_113 . V_211 & V_215 ) << V_216 ;
F_19 ( V_211 , V_47 -> V_211 ) ;
}
static int F_157 ( struct V_217 * V_48 , int V_105 )
{
struct V_104 * V_47 =
F_158 ( V_48 , struct V_104 , V_48 ) ;
struct V_4 * V_50 ;
int V_218 ;
bool V_219 = true ;
F_159 (ring, q_vector->tx)
V_219 &= F_138 ( V_47 , V_50 ) ;
if ( V_47 -> V_113 . V_22 > 1 )
V_218 = F_160 ( V_105 / V_47 -> V_113 . V_22 , 1 ) ;
else
V_218 = V_105 ;
F_159 (ring, q_vector->rx)
V_219 &= F_74 ( V_47 , V_50 ,
V_218 ) ;
if ( ! V_219 )
return V_105 ;
F_161 ( V_48 ) ;
F_156 ( V_47 ) ;
return 0 ;
}
static bool F_162 ( struct V_72 * V_73 )
{
struct V_78 * V_12 = V_73 -> V_51 ;
struct V_220 * V_185 ;
int V_221 , V_19 ;
int V_222 ;
V_222 = F_163 ( V_12 ) ;
if ( V_222 <= 1 )
return false ;
V_185 = & V_73 -> V_223 [ V_224 ] ;
V_185 -> V_225 = V_222 ;
V_185 -> V_226 = ( 1 << F_164 ( V_222 - 1 ) ) - 1 ;
V_221 = V_73 -> V_204 . V_227 . V_228 / V_222 ;
V_221 = 1 << ( F_164 ( V_221 ) - 1 ) ;
V_185 = & V_73 -> V_223 [ V_229 ] ;
V_221 = F_165 ( T_4 , V_221 , V_185 -> V_230 ) ;
V_185 -> V_225 = V_221 ;
V_185 -> V_226 = ( 1 << F_164 ( V_221 - 1 ) ) - 1 ;
for ( V_19 = 0 ; V_19 < V_222 ; V_19 ++ )
F_166 ( V_12 , V_19 , V_221 , V_221 * V_19 ) ;
V_73 -> V_231 = V_221 * V_222 ;
V_73 -> V_232 = V_221 * V_222 ;
return true ;
}
static bool F_167 ( struct V_72 * V_73 )
{
struct V_220 * V_185 ;
T_4 V_221 ;
V_185 = & V_73 -> V_223 [ V_229 ] ;
V_221 = F_165 ( T_4 , V_73 -> V_204 . V_227 . V_228 , V_185 -> V_230 ) ;
V_185 -> V_225 = V_221 ;
V_185 -> V_226 = ( 1 << F_164 ( V_221 - 1 ) ) - 1 ;
V_73 -> V_231 = V_221 ;
V_73 -> V_232 = V_221 ;
return true ;
}
static void F_168 ( struct V_72 * V_73 )
{
V_73 -> V_231 = 1 ;
V_73 -> V_232 = 1 ;
if ( F_162 ( V_73 ) )
return;
F_167 ( V_73 ) ;
}
static int F_169 ( struct V_72 * V_73 ,
unsigned int V_233 , unsigned int V_234 ,
unsigned int V_235 , unsigned int V_236 ,
unsigned int V_237 , unsigned int V_238 )
{
struct V_104 * V_47 ;
struct V_4 * V_50 ;
int V_239 , V_38 ;
V_239 = V_235 + V_237 ;
V_38 = sizeof( struct V_104 ) +
( sizeof( struct V_4 ) * V_239 ) ;
V_47 = F_170 ( V_38 , V_240 ) ;
if ( ! V_47 )
return - V_241 ;
F_171 ( V_73 -> V_51 , & V_47 -> V_48 ,
F_157 , V_242 ) ;
V_73 -> V_47 [ V_234 ] = V_47 ;
V_47 -> V_73 = V_73 ;
V_47 -> V_234 = V_234 ;
V_50 = V_47 -> V_50 ;
V_47 -> V_199 . V_50 = V_50 ;
V_47 -> V_199 . V_200 = V_243 ;
V_47 -> V_199 . V_211 = V_73 -> V_244 ;
V_47 -> V_199 . V_22 = V_235 ;
while ( V_235 ) {
V_50 -> V_12 = & V_73 -> V_245 -> V_12 ;
V_50 -> V_51 = V_73 -> V_51 ;
V_50 -> V_47 = V_47 ;
V_50 -> V_22 = V_73 -> V_246 ;
V_50 -> V_91 = V_236 ;
V_73 -> V_137 [ V_236 ] = V_50 ;
V_235 -- ;
V_236 += V_233 ;
V_50 ++ ;
}
V_47 -> V_113 . V_50 = V_50 ;
V_47 -> V_113 . V_211 = V_73 -> V_247 ;
V_47 -> V_113 . V_22 = V_237 ;
while ( V_237 ) {
V_50 -> V_12 = & V_73 -> V_245 -> V_12 ;
V_50 -> V_51 = V_73 -> V_51 ;
F_172 ( V_50 -> V_80 , V_73 -> V_80 ) ;
V_50 -> V_47 = V_47 ;
V_50 -> V_22 = V_73 -> V_248 ;
V_50 -> V_91 = V_238 ;
V_73 -> V_5 [ V_238 ] = V_50 ;
V_237 -- ;
V_238 += V_233 ;
V_50 ++ ;
}
F_173 ( V_47 ) ;
return 0 ;
}
static void F_174 ( struct V_72 * V_73 , int V_234 )
{
struct V_104 * V_47 = V_73 -> V_47 [ V_234 ] ;
struct V_4 * V_50 ;
F_175 ( V_47 ) ;
F_159 (ring, q_vector->tx)
V_73 -> V_137 [ V_50 -> V_91 ] = NULL ;
F_159 (ring, q_vector->rx)
V_73 -> V_5 [ V_50 -> V_91 ] = NULL ;
V_73 -> V_47 [ V_234 ] = NULL ;
F_176 ( & V_47 -> V_48 ) ;
F_177 ( V_47 , V_249 ) ;
}
static int F_178 ( struct V_72 * V_73 )
{
unsigned int V_250 = V_73 -> V_251 ;
unsigned int V_252 = V_73 -> V_231 ;
unsigned int V_253 = V_73 -> V_232 ;
unsigned int V_238 = 0 , V_236 = 0 , V_234 = 0 ;
int V_254 ;
if ( V_250 >= ( V_252 + V_253 ) ) {
for (; V_252 ; V_234 ++ ) {
V_254 = F_169 ( V_73 , V_250 , V_234 ,
0 , 0 , 1 , V_238 ) ;
if ( V_254 )
goto V_255;
V_252 -- ;
V_238 ++ ;
}
}
for (; V_234 < V_250 ; V_234 ++ ) {
int V_256 = F_179 ( V_252 , V_250 - V_234 ) ;
int V_257 = F_179 ( V_253 , V_250 - V_234 ) ;
V_254 = F_169 ( V_73 , V_250 , V_234 ,
V_257 , V_236 ,
V_256 , V_238 ) ;
if ( V_254 )
goto V_255;
V_252 -= V_256 ;
V_253 -= V_257 ;
V_238 ++ ;
V_236 ++ ;
}
return 0 ;
V_255:
V_73 -> V_232 = 0 ;
V_73 -> V_231 = 0 ;
V_73 -> V_251 = 0 ;
while ( V_234 -- )
F_174 ( V_73 , V_234 ) ;
return - V_241 ;
}
static void F_180 ( struct V_72 * V_73 )
{
int V_234 = V_73 -> V_251 ;
V_73 -> V_232 = 0 ;
V_73 -> V_231 = 0 ;
V_73 -> V_251 = 0 ;
while ( V_234 -- )
F_174 ( V_73 , V_234 ) ;
}
static void F_181 ( struct V_72 * V_73 )
{
F_182 ( V_73 -> V_245 ) ;
F_183 ( V_73 -> V_258 ) ;
V_73 -> V_258 = NULL ;
}
static int F_184 ( struct V_72 * V_73 )
{
struct V_203 * V_204 = & V_73 -> V_204 ;
int V_259 , V_260 ;
V_259 = F_160 ( V_73 -> V_231 , V_73 -> V_232 ) ;
V_259 = F_165 ( T_4 , V_259 , F_185 () ) ;
V_259 += F_186 ( V_204 ) ;
V_259 = F_165 ( int , V_259 , V_204 -> V_227 . V_261 ) ;
V_73 -> V_258 = F_187 ( V_259 , sizeof( struct V_262 ) ,
V_240 ) ;
if ( ! V_73 -> V_258 )
return - V_241 ;
for ( V_260 = 0 ; V_260 < V_259 ; V_260 ++ )
V_73 -> V_258 [ V_260 ] . V_263 = V_260 ;
V_259 = F_188 ( V_73 -> V_245 ,
V_73 -> V_258 ,
F_189 ( V_204 ) ,
V_259 ) ;
if ( V_259 < 0 ) {
F_183 ( V_73 -> V_258 ) ;
V_73 -> V_258 = NULL ;
return - V_241 ;
}
V_73 -> V_251 = V_259 - F_186 ( V_204 ) ;
return 0 ;
}
static bool F_190 ( struct V_72 * V_73 )
{
struct V_78 * V_12 = V_73 -> V_51 ;
int V_264 , V_265 , V_221 , V_19 , V_266 ;
T_4 V_267 = V_73 -> V_223 [ V_224 ] . V_226 + 1 ;
T_7 V_268 = F_163 ( V_12 ) ;
if ( V_268 <= 1 )
return false ;
V_221 = V_73 -> V_223 [ V_229 ] . V_225 ;
for ( V_264 = 0 , V_265 = 0 ; V_264 < V_268 ; V_264 ++ , V_265 += V_221 ) {
V_266 = V_264 ;
for ( V_19 = 0 ; V_19 < V_221 ; V_19 ++ ) {
V_73 -> V_137 [ V_265 + V_19 ] -> V_206 = V_266 ;
V_73 -> V_137 [ V_265 + V_19 ] -> V_269 = V_264 ;
V_73 -> V_5 [ V_265 + V_19 ] -> V_206 = V_266 ;
V_73 -> V_5 [ V_265 + V_19 ] -> V_269 = V_264 ;
V_266 += V_267 ;
}
}
return true ;
}
static void F_191 ( struct V_72 * V_73 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_73 -> V_231 ; V_19 ++ )
V_73 -> V_5 [ V_19 ] -> V_206 = V_19 ;
for ( V_19 = 0 ; V_19 < V_73 -> V_232 ; V_19 ++ )
V_73 -> V_137 [ V_19 ] -> V_206 = V_19 ;
}
static void F_192 ( struct V_72 * V_73 )
{
if ( F_190 ( V_73 ) )
return;
F_191 ( V_73 ) ;
}
static void F_193 ( struct V_72 * V_73 )
{
T_4 V_19 , V_221 = V_73 -> V_223 [ V_229 ] . V_225 ;
T_5 V_270 , V_271 ;
if ( V_73 -> V_51 -> V_272 ) {
for ( V_19 = V_273 ; V_19 -- ; ) {
V_270 = V_73 -> V_270 [ V_19 ] ;
if ( ( ( ( V_270 << 24 ) >> 24 ) < V_221 ) &&
( ( ( V_270 << 16 ) >> 24 ) < V_221 ) &&
( ( ( V_270 << 8 ) >> 24 ) < V_221 ) &&
( ( ( V_270 ) >> 24 ) < V_221 ) )
continue;
goto V_274;
}
return;
}
V_274:
for ( V_19 = V_273 ; V_19 -- ; ) {
V_271 = ( ( V_19 * 0x00040004 ) + 0x00020000 ) * V_221 ;
V_270 = ( V_271 & 0x3F803F80 ) >> 7 ;
V_271 += 0x00010001 * V_221 ;
V_270 |= ( V_271 & 0x3F803F80 ) << 1 ;
V_73 -> V_270 [ V_19 ] = V_270 ;
}
}
int F_194 ( struct V_72 * V_73 )
{
int V_254 ;
F_168 ( V_73 ) ;
V_254 = F_184 ( V_73 ) ;
if ( V_254 ) {
F_124 ( & V_73 -> V_245 -> V_12 ,
L_15 ) ;
return V_254 ;
}
V_254 = F_178 ( V_73 ) ;
if ( V_254 )
return V_254 ;
F_192 ( V_73 ) ;
F_193 ( V_73 ) ;
return 0 ;
}
void F_195 ( struct V_72 * V_73 )
{
F_180 ( V_73 ) ;
F_181 ( V_73 ) ;
}
