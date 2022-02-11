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
V_7 -> V_8 = NULL ;
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
V_18 -> V_23 . V_25 = 0 ;
V_16 -- ;
} while ( V_16 );
V_19 += V_5 -> V_22 ;
if ( V_5 -> V_20 != V_19 ) {
V_5 -> V_20 = V_19 ;
V_5 -> V_26 = V_19 ;
F_18 () ;
F_19 ( V_19 , V_5 -> V_27 ) ;
}
}
static void F_20 ( struct V_4 * V_5 ,
struct V_6 * V_28 )
{
struct V_6 * V_29 ;
T_4 V_30 = V_5 -> V_26 ;
V_29 = & V_5 -> V_21 [ V_30 ] ;
V_30 ++ ;
V_5 -> V_26 = ( V_30 < V_5 -> V_22 ) ? V_30 : 0 ;
memcpy ( V_29 , V_28 , sizeof( struct V_6 ) ) ;
F_21 ( V_5 -> V_12 , V_28 -> V_9 ,
V_28 -> V_15 ,
V_31 ,
V_14 ) ;
}
static bool F_22 ( struct V_6 * V_21 ,
struct V_8 * V_8 ,
unsigned int V_32 )
{
if ( F_11 ( F_23 ( V_8 ) != F_24 () ) )
return false ;
#if ( V_13 < 8192 )
if ( F_11 ( F_25 ( V_8 ) != 1 ) )
return false ;
V_21 -> V_15 ^= V_31 ;
F_26 ( & V_8 -> V_33 ) ;
#else
V_21 -> V_15 += V_32 ;
if ( V_21 -> V_15 > ( V_13 - V_31 ) )
return false ;
F_27 ( V_8 ) ;
#endif
return true ;
}
static bool F_28 ( struct V_4 * V_5 ,
struct V_6 * V_21 ,
union V_17 * V_18 ,
struct V_34 * V_35 )
{
struct V_8 * V_8 = V_21 -> V_8 ;
unsigned int V_36 = F_29 ( V_18 -> V_37 . V_38 ) ;
#if ( V_13 < 8192 )
unsigned int V_32 = V_31 ;
#else
unsigned int V_32 = F_30 ( V_36 , V_39 ) ;
#endif
if ( ( V_36 <= V_40 ) && ! F_31 ( V_35 ) ) {
unsigned char * V_41 = F_32 ( V_8 ) + V_21 -> V_15 ;
memcpy ( F_33 ( V_35 , V_36 ) , V_41 , F_30 ( V_36 , sizeof( long ) ) ) ;
if ( F_9 ( F_23 ( V_8 ) == F_24 () ) )
return true ;
F_34 ( V_8 ) ;
return false ;
}
F_35 ( V_35 , F_36 ( V_35 ) -> V_42 , V_8 ,
V_21 -> V_15 , V_36 , V_32 ) ;
return F_22 ( V_21 , V_8 , V_32 ) ;
}
static struct V_34 * F_37 ( struct V_4 * V_5 ,
union V_17 * V_18 ,
struct V_34 * V_35 )
{
struct V_6 * V_21 ;
struct V_8 * V_8 ;
V_21 = & V_5 -> V_21 [ V_5 -> V_43 ] ;
V_8 = V_21 -> V_8 ;
F_38 ( V_8 ) ;
if ( F_9 ( ! V_35 ) ) {
void * V_44 = F_32 ( V_8 ) +
V_21 -> V_15 ;
F_39 ( V_44 ) ;
#if V_39 < 128
F_39 ( V_44 + V_39 ) ;
#endif
V_35 = F_40 ( & V_5 -> V_45 -> V_46 ,
V_40 ) ;
if ( F_11 ( ! V_35 ) ) {
V_5 -> V_10 . V_11 ++ ;
return NULL ;
}
F_38 ( V_35 -> V_47 ) ;
}
F_41 ( V_5 -> V_12 ,
V_21 -> V_9 ,
V_21 -> V_15 ,
V_31 ,
V_14 ) ;
if ( F_28 ( V_5 , V_21 , V_18 , V_35 ) ) {
F_20 ( V_5 , V_21 ) ;
} else {
F_42 ( V_5 -> V_12 , V_21 -> V_9 ,
V_13 , V_14 ) ;
}
V_21 -> V_8 = NULL ;
return V_35 ;
}
static inline void F_43 ( struct V_4 * V_48 ,
union V_17 * V_18 ,
struct V_34 * V_35 )
{
F_44 ( V_35 ) ;
if ( ! ( V_48 -> V_49 -> V_50 & V_51 ) )
return;
if ( F_45 ( V_18 ,
V_52 |
V_53 |
V_54 |
V_55 ) ) {
V_48 -> V_10 . V_56 ++ ;
return;
}
if ( F_45 ( V_18 , V_57 ) )
V_35 -> V_58 = true ;
else if ( ! F_45 ( V_18 , V_59 ) )
return;
V_35 -> V_60 = V_61 ;
}
static inline void F_46 ( struct V_4 * V_48 ,
union V_17 * V_18 ,
struct V_34 * V_35 )
{
T_4 V_62 ;
if ( ! ( V_48 -> V_49 -> V_50 & V_63 ) )
return;
V_62 = F_29 ( V_18 -> V_37 . V_64 ) & V_65 ;
if ( ! V_62 )
return;
F_47 ( V_35 , F_48 ( V_18 -> V_66 . V_67 ) ,
( V_68 & ( 1ul << V_62 ) ) ?
V_69 : V_70 ) ;
}
static void F_49 ( struct V_4 * V_5 ,
union V_17 * V_18 ,
struct V_34 * V_35 )
{
struct V_71 * V_72 = V_5 -> V_45 -> V_72 ;
F_50 ( V_35 ) -> V_73 = V_18 -> V_23 . V_74 ;
if ( F_11 ( V_72 -> V_75 & V_76 ) )
F_51 ( V_72 , F_52 ( V_35 ) ,
F_53 ( V_18 -> V_23 . V_74 ) ) ;
}
static void F_54 ( struct V_4 * V_5 ,
union V_17 * V_18 ,
struct V_34 * V_35 )
{
struct V_77 * V_12 = V_5 -> V_49 ;
struct V_78 * V_79 = F_55 ( V_5 -> V_79 ) ;
if ( V_79 ) {
T_4 V_80 = F_29 ( F_50 ( V_35 ) -> V_81 . V_37 . V_82 ) - 1 ;
V_80 -= V_79 -> V_82 ;
if ( V_80 < V_79 -> V_36 && V_79 -> V_83 [ V_80 ] )
V_12 = V_79 -> V_83 [ V_80 ] ;
else
V_79 = NULL ;
}
V_35 -> V_84 = F_56 ( V_35 , V_12 ) ;
if ( ! V_79 )
return;
F_57 ( F_58 ( V_12 ) , V_35 -> V_85 + V_86 , 1 ,
! ! ( V_18 -> V_37 . V_87 &
F_59 ( V_88 ) ) ) ;
}
static unsigned int F_60 ( struct V_4 * V_5 ,
union V_17 * V_18 ,
struct V_34 * V_35 )
{
unsigned int V_85 = V_35 -> V_85 ;
F_46 ( V_5 , V_18 , V_35 ) ;
F_43 ( V_5 , V_18 , V_35 ) ;
F_49 ( V_5 , V_18 , V_35 ) ;
F_50 ( V_35 ) -> V_81 . V_37 . V_89 = V_18 -> V_37 . V_89 ;
F_61 ( V_35 , V_5 -> V_90 ) ;
F_50 ( V_35 ) -> V_81 . V_66 . V_91 = V_18 -> V_66 . V_91 ;
if ( V_18 -> V_37 . V_89 ) {
T_4 V_92 = F_29 ( V_18 -> V_37 . V_89 ) ;
if ( V_92 != V_5 -> V_92 )
F_62 ( V_35 , F_63 ( V_93 ) , V_92 ) ;
}
F_54 ( V_5 , V_18 , V_35 ) ;
return V_85 ;
}
static bool F_64 ( struct V_4 * V_5 ,
union V_17 * V_18 )
{
T_5 V_94 = V_5 -> V_43 + 1 ;
V_94 = ( V_94 < V_5 -> V_22 ) ? V_94 : 0 ;
V_5 -> V_43 = V_94 ;
F_39 ( F_16 ( V_5 , V_94 ) ) ;
if ( F_9 ( F_45 ( V_18 , V_95 ) ) )
return false ;
return true ;
}
static void F_65 ( struct V_4 * V_5 ,
union V_17 * V_18 ,
struct V_34 * V_35 )
{
struct V_96 * V_97 = & F_36 ( V_35 ) -> V_98 [ 0 ] ;
unsigned char * V_41 ;
unsigned int V_99 ;
V_41 = F_66 ( V_97 ) ;
V_99 = F_67 ( V_41 , V_40 ) ;
F_68 ( V_35 , V_41 , F_30 ( V_99 , sizeof( long ) ) ) ;
F_69 ( V_97 , V_99 ) ;
V_97 -> V_15 += V_99 ;
V_35 -> V_100 -= V_99 ;
V_35 -> V_27 += V_99 ;
}
static bool F_70 ( struct V_4 * V_5 ,
union V_17 * V_18 ,
struct V_34 * V_35 )
{
if ( F_11 ( ( F_45 ( V_18 ,
V_101 ) ) ) ) {
F_71 ( V_35 ) ;
V_5 -> V_10 . V_102 ++ ;
return true ;
}
if ( F_31 ( V_35 ) )
F_65 ( V_5 , V_18 , V_35 ) ;
if ( F_72 ( V_35 ) )
return true ;
return false ;
}
static void F_73 ( struct V_103 * V_45 ,
struct V_34 * V_35 )
{
F_74 ( & V_45 -> V_46 , V_35 ) ;
}
static bool F_75 ( struct V_103 * V_45 ,
struct V_4 * V_5 ,
int V_104 )
{
struct V_34 * V_35 = V_5 -> V_35 ;
unsigned int V_105 = 0 , V_106 = 0 ;
T_4 V_16 = F_76 ( V_5 ) ;
do {
union V_17 * V_18 ;
if ( V_16 >= V_107 ) {
F_15 ( V_5 , V_16 ) ;
V_16 = 0 ;
}
V_18 = F_16 ( V_5 , V_5 -> V_43 ) ;
if ( ! V_18 -> V_66 . V_108 )
break;
F_77 () ;
V_35 = F_37 ( V_5 , V_18 , V_35 ) ;
if ( ! V_35 )
break;
V_16 ++ ;
if ( F_64 ( V_5 , V_18 ) )
continue;
if ( F_70 ( V_5 , V_18 , V_35 ) ) {
V_35 = NULL ;
continue;
}
V_105 += F_60 ( V_5 , V_18 , V_35 ) ;
F_73 ( V_45 , V_35 ) ;
V_35 = NULL ;
V_106 ++ ;
} while ( F_9 ( V_106 < V_104 ) );
V_5 -> V_35 = V_35 ;
F_78 ( & V_5 -> V_109 ) ;
V_5 -> V_110 . V_111 += V_106 ;
V_5 -> V_110 . V_112 += V_105 ;
F_79 ( & V_5 -> V_109 ) ;
V_45 -> V_113 . V_106 += V_106 ;
V_45 -> V_113 . V_105 += V_105 ;
return V_106 < V_104 ;
}
static struct V_114 * F_80 ( struct V_34 * V_35 )
{
struct V_71 * V_72 = F_58 ( V_35 -> V_12 ) ;
struct V_115 * V_116 ;
V_116 = F_81 ( & V_72 -> V_116 ,
struct V_115 , V_117 ) ;
if ( ! V_116 )
return NULL ;
if ( V_116 -> V_118 != F_82 ( V_35 ) -> V_119 )
return NULL ;
return (struct V_114 * ) ( F_83 ( V_35 ) + V_120 ) ;
}
static struct V_114 * F_84 ( struct V_34 * V_35 )
{
struct V_121 * V_122 ;
int V_123 = F_85 ( V_35 ) ;
if ( F_86 ( V_35 ) != F_63 ( V_124 ) )
return NULL ;
V_122 = (struct V_121 * ) ( F_87 ( V_35 ) + V_123 ) ;
if ( V_122 -> V_75 & V_125 )
return NULL ;
if ( V_122 -> V_126 != F_63 ( V_127 ) )
return NULL ;
if ( V_122 -> V_75 & V_128 )
return (struct V_114 * ) ( V_122 + 1 ) ;
return (struct V_114 * ) ( & V_122 -> V_129 ) ;
}
static T_6 F_88 ( struct V_34 * V_35 )
{
struct V_114 * V_130 ;
T_7 V_131 = 0 ;
switch ( F_86 ( V_35 ) ) {
case F_63 ( V_124 ) :
V_131 = F_89 ( V_35 ) -> V_84 ;
break;
case F_63 ( V_132 ) :
V_131 = F_90 ( V_35 ) -> V_133 ;
break;
default:
return 0 ;
}
switch ( V_131 ) {
case V_134 :
V_130 = F_80 ( V_35 ) ;
break;
case V_135 :
V_130 = F_84 ( V_35 ) ;
break;
default:
return 0 ;
}
if ( ! V_130 )
return 0 ;
switch ( V_130 -> V_136 ) {
case F_63 ( V_124 ) :
case F_63 ( V_132 ) :
break;
default:
return 0 ;
}
return V_130 -> V_136 ;
}
static int F_91 ( struct V_4 * V_137 ,
struct V_138 * V_139 )
{
struct V_34 * V_35 = V_139 -> V_35 ;
struct V_140 * V_141 ;
unsigned char * V_142 ;
T_7 V_143 ;
if ( V_35 -> V_60 != V_144 )
return 0 ;
if ( ! F_92 ( V_35 ) )
return 0 ;
if ( V_35 -> V_58 ) {
if ( ! F_88 ( V_35 ) )
goto V_145;
V_142 = F_93 ( V_35 ) ;
} else {
V_142 = F_83 ( V_35 ) ;
}
V_143 = ( V_142 - V_35 -> V_47 ) + ( ( (struct V_146 * ) V_142 ) -> V_147 << 2 ) ;
V_139 -> V_148 |= V_149 ;
V_139 -> V_150 = F_36 ( V_35 ) -> V_150 ;
V_139 -> V_151 += ( V_139 -> V_150 - 1 ) * V_143 ;
V_141 = F_94 ( V_137 , V_137 -> V_20 ) ;
V_141 -> V_143 = V_143 ;
V_141 -> V_152 = F_59 ( F_36 ( V_35 ) -> V_153 ) ;
return 1 ;
V_145:
V_137 -> V_49 -> V_50 &= ~ V_154 ;
if ( ! F_95 () )
F_96 ( V_137 -> V_49 ,
L_3 ) ;
return - 1 ;
}
static void F_97 ( struct V_4 * V_137 ,
struct V_138 * V_139 )
{
struct V_34 * V_35 = V_139 -> V_35 ;
struct V_140 * V_141 ;
union {
struct V_155 * V_156 ;
struct V_157 * V_158 ;
T_7 * V_159 ;
} V_160 ;
T_6 V_84 ;
T_7 V_131 = 0 ;
if ( V_35 -> V_60 != V_144 )
goto V_161;
if ( V_35 -> V_58 ) {
V_84 = F_88 ( V_35 ) ;
if ( ! V_84 ) {
if ( F_98 ( V_35 ) ) {
F_99 ( V_137 -> V_12 ,
L_4 ) ;
V_137 -> V_162 . V_56 ++ ;
}
goto V_161;
}
V_160 . V_159 = F_100 ( V_35 ) ;
} else {
V_84 = F_86 ( V_35 ) ;
V_160 . V_159 = F_87 ( V_35 ) ;
}
switch ( V_84 ) {
case F_63 ( V_124 ) :
V_131 = V_160 . V_156 -> V_84 ;
break;
case F_63 ( V_132 ) :
V_131 = V_160 . V_158 -> V_133 ;
break;
default:
if ( F_11 ( F_95 () ) ) {
F_99 ( V_137 -> V_12 ,
L_5 ,
V_84 ) ;
}
V_137 -> V_162 . V_56 ++ ;
goto V_161;
}
switch ( V_131 ) {
case V_163 :
case V_134 :
break;
case V_135 :
if ( V_35 -> V_58 )
break;
default:
if ( F_11 ( F_95 () ) ) {
F_99 ( V_137 -> V_12 ,
L_6 ,
V_131 ) ;
}
V_137 -> V_162 . V_56 ++ ;
goto V_161;
}
V_139 -> V_148 |= V_149 ;
V_161:
V_141 = F_94 ( V_137 , V_137 -> V_20 ) ;
V_141 -> V_143 = 0 ;
V_141 -> V_152 = 0 ;
}
static T_7 F_101 ( struct V_34 * V_35 , T_5 V_148 )
{
T_5 V_164 = 0 ;
if ( F_11 ( F_36 ( V_35 ) -> V_148 & V_165 ) &&
F_9 ( F_36 ( V_35 ) -> V_148 & V_166 ) )
V_164 |= V_167 ;
V_164 |= F_102 ( V_148 , V_149 ,
V_168 ) ;
return V_164 ;
}
static bool F_103 ( struct V_4 * V_137 ,
struct V_140 * V_141 , T_4 V_19 ,
T_3 V_9 , unsigned int V_36 , T_7 V_164 )
{
if ( ( ++ V_19 & ( V_169 - 1 ) ) == 0 )
V_164 |= V_170 | V_171 ;
V_141 -> V_172 = F_17 ( V_9 ) ;
V_141 -> V_75 = V_164 ;
V_141 -> V_173 = F_59 ( V_36 ) ;
return V_19 == V_137 -> V_22 ;
}
static int F_104 ( struct V_4 * V_137 , T_4 V_36 )
{
F_105 ( V_137 -> V_49 , V_137 -> V_90 ) ;
F_106 () ;
if ( F_9 ( F_76 ( V_137 ) < V_36 ) )
return - V_174 ;
F_107 ( V_137 -> V_49 , V_137 -> V_90 ) ;
++ V_137 -> V_162 . V_175 ;
return 0 ;
}
static inline int F_108 ( struct V_4 * V_137 , T_4 V_36 )
{
if ( F_9 ( F_76 ( V_137 ) >= V_36 ) )
return 0 ;
return F_104 ( V_137 , V_36 ) ;
}
static void F_109 ( struct V_4 * V_137 ,
struct V_138 * V_139 )
{
struct V_34 * V_35 = V_139 -> V_35 ;
struct V_138 * V_176 ;
struct V_140 * V_141 ;
struct V_96 * V_97 ;
unsigned char * V_47 ;
T_3 V_9 ;
unsigned int V_100 , V_36 ;
T_5 V_148 = V_139 -> V_148 ;
T_4 V_19 = V_137 -> V_20 ;
T_7 V_75 = F_101 ( V_35 , V_148 ) ;
V_141 = F_94 ( V_137 , V_19 ) ;
if ( F_110 ( V_35 ) )
V_141 -> V_89 = F_59 ( F_111 ( V_35 ) ) ;
else
V_141 -> V_89 = 0 ;
V_36 = F_112 ( V_35 ) ;
V_47 = V_35 -> V_47 ;
V_9 = F_113 ( V_137 -> V_12 , V_47 , V_36 , V_177 ) ;
V_100 = V_35 -> V_100 ;
V_176 = V_139 ;
for ( V_97 = & F_36 ( V_35 ) -> V_98 [ 0 ] ; ; V_97 ++ ) {
if ( F_13 ( V_137 -> V_12 , V_9 ) )
goto V_178;
F_114 ( V_176 , V_85 , V_36 ) ;
F_115 ( V_176 , V_9 , V_9 ) ;
while ( F_11 ( V_36 > V_179 ) ) {
if ( F_103 ( V_137 , V_141 ++ , V_19 ++ , V_9 ,
V_179 , V_75 ) ) {
V_141 = F_94 ( V_137 , 0 ) ;
V_19 = 0 ;
}
V_9 += V_179 ;
V_36 -= V_179 ;
}
if ( F_9 ( ! V_100 ) )
break;
if ( F_103 ( V_137 , V_141 ++ , V_19 ++ ,
V_9 , V_36 , V_75 ) ) {
V_141 = F_94 ( V_137 , 0 ) ;
V_19 = 0 ;
}
V_36 = F_116 ( V_97 ) ;
V_100 -= V_36 ;
V_9 = F_117 ( V_137 -> V_12 , V_97 , 0 , V_36 ,
V_177 ) ;
V_176 = & V_137 -> V_176 [ V_19 ] ;
}
V_75 |= V_180 ;
if ( F_103 ( V_137 , V_141 , V_19 ++ , V_9 , V_36 , V_75 ) )
V_19 = 0 ;
F_118 ( F_119 ( V_137 ) , V_139 -> V_151 ) ;
F_120 ( V_139 -> V_35 ) ;
F_18 () ;
V_139 -> V_181 = V_141 ;
V_137 -> V_20 = V_19 ;
F_108 ( V_137 , V_182 ) ;
if ( F_121 ( F_119 ( V_137 ) ) || ! V_35 -> V_183 ) {
F_19 ( V_19 , V_137 -> V_27 ) ;
F_122 () ;
}
return;
V_178:
F_123 ( V_137 -> V_12 , L_7 ) ;
for (; ; ) {
V_176 = & V_137 -> V_176 [ V_19 ] ;
F_124 ( V_137 , V_176 ) ;
if ( V_176 == V_139 )
break;
if ( V_19 == 0 )
V_19 = V_137 -> V_22 ;
V_19 -- ;
}
V_137 -> V_20 = V_19 ;
}
T_8 F_125 ( struct V_34 * V_35 ,
struct V_4 * V_137 )
{
struct V_138 * V_139 ;
int V_184 ;
T_5 V_148 = 0 ;
#if V_13 > V_179
unsigned short V_185 ;
#endif
T_4 V_22 = F_126 ( F_112 ( V_35 ) ) ;
#if V_13 > V_179
for ( V_185 = 0 ; V_185 < F_36 ( V_35 ) -> V_42 ; V_185 ++ )
V_22 += F_126 ( F_36 ( V_35 ) -> V_98 [ V_185 ] . V_36 ) ;
#else
V_22 += F_36 ( V_35 ) -> V_42 ;
#endif
if ( F_108 ( V_137 , V_22 + 3 ) ) {
V_137 -> V_162 . V_186 ++ ;
return V_187 ;
}
V_139 = & V_137 -> V_176 [ V_137 -> V_20 ] ;
V_139 -> V_35 = V_35 ;
V_139 -> V_151 = F_127 (unsigned int, skb->len, ETH_ZLEN) ;
V_139 -> V_150 = 1 ;
V_139 -> V_148 = V_148 ;
V_184 = F_91 ( V_137 , V_139 ) ;
if ( V_184 < 0 )
goto V_188;
else if ( ! V_184 )
F_97 ( V_137 , V_139 ) ;
F_109 ( V_137 , V_139 ) ;
return V_189 ;
V_188:
F_71 ( V_139 -> V_35 ) ;
V_139 -> V_35 = NULL ;
return V_189 ;
}
static T_9 F_128 ( struct V_4 * V_48 )
{
return V_48 -> V_110 . V_111 ;
}
static T_9 F_129 ( struct V_4 * V_48 )
{
T_5 V_190 = V_48 -> V_43 ;
T_5 V_27 = V_48 -> V_20 ;
return ( ( V_190 <= V_27 ) ? V_27 : V_27 + V_48 -> V_22 ) - V_190 ;
}
bool F_130 ( struct V_4 * V_137 )
{
T_5 V_191 = F_128 ( V_137 ) ;
T_5 V_192 = V_137 -> V_162 . V_192 ;
T_5 V_193 = F_129 ( V_137 ) ;
F_131 ( V_137 ) ;
if ( ! V_193 || ( V_192 != V_191 ) ) {
V_137 -> V_162 . V_192 = V_191 ;
F_132 ( V_194 , & V_137 -> V_195 ) ;
return false ;
}
return F_133 ( V_194 , & V_137 -> V_195 ) ;
}
void F_134 ( struct V_71 * V_72 )
{
if ( ! F_135 ( V_196 , & V_72 -> V_195 ) ) {
F_96 ( V_72 -> V_49 , L_8 ) ;
V_72 -> V_197 ++ ;
V_72 -> V_75 |= V_198 ;
F_136 ( V_72 ) ;
}
}
static bool F_137 ( struct V_103 * V_45 ,
struct V_4 * V_137 )
{
struct V_71 * V_72 = V_45 -> V_72 ;
struct V_138 * V_176 ;
struct V_140 * V_141 ;
unsigned int V_105 = 0 , V_106 = 0 ;
unsigned int V_104 = V_45 -> V_199 . V_200 ;
unsigned int V_19 = V_137 -> V_43 ;
if ( F_135 ( V_196 , & V_72 -> V_195 ) )
return true ;
V_176 = & V_137 -> V_176 [ V_19 ] ;
V_141 = F_94 ( V_137 , V_19 ) ;
V_19 -= V_137 -> V_22 ;
do {
struct V_140 * V_201 = V_176 -> V_181 ;
if ( ! V_201 )
break;
F_138 () ;
if ( ! ( V_201 -> V_75 & V_202 ) )
break;
V_176 -> V_181 = NULL ;
V_105 += V_176 -> V_151 ;
V_106 += V_176 -> V_150 ;
F_139 ( V_176 -> V_35 ) ;
F_140 ( V_137 -> V_12 ,
F_141 ( V_176 , V_9 ) ,
F_142 ( V_176 , V_85 ) ,
V_177 ) ;
V_176 -> V_35 = NULL ;
F_114 ( V_176 , V_85 , 0 ) ;
while ( V_141 != V_201 ) {
V_176 ++ ;
V_141 ++ ;
V_19 ++ ;
if ( F_11 ( ! V_19 ) ) {
V_19 -= V_137 -> V_22 ;
V_176 = V_137 -> V_176 ;
V_141 = F_94 ( V_137 , 0 ) ;
}
if ( F_142 ( V_176 , V_85 ) ) {
F_42 ( V_137 -> V_12 ,
F_141 ( V_176 , V_9 ) ,
F_142 ( V_176 , V_85 ) ,
V_177 ) ;
F_114 ( V_176 , V_85 , 0 ) ;
}
}
V_176 ++ ;
V_141 ++ ;
V_19 ++ ;
if ( F_11 ( ! V_19 ) ) {
V_19 -= V_137 -> V_22 ;
V_176 = V_137 -> V_176 ;
V_141 = F_94 ( V_137 , 0 ) ;
}
F_39 ( V_141 ) ;
V_104 -- ;
} while ( F_9 ( V_104 ) );
V_19 += V_137 -> V_22 ;
V_137 -> V_43 = V_19 ;
F_78 ( & V_137 -> V_109 ) ;
V_137 -> V_110 . V_112 += V_105 ;
V_137 -> V_110 . V_111 += V_106 ;
F_79 ( & V_137 -> V_109 ) ;
V_45 -> V_199 . V_105 += V_105 ;
V_45 -> V_199 . V_106 += V_106 ;
if ( F_143 ( V_137 ) && F_130 ( V_137 ) ) {
struct V_203 * V_204 = & V_72 -> V_204 ;
F_144 ( V_72 , V_205 , V_137 -> V_49 ,
L_9
L_10
L_11
L_12
L_13 ,
V_137 -> V_90 ,
F_145 ( V_204 , F_146 ( V_137 -> V_206 ) ) ,
F_145 ( V_204 , F_147 ( V_137 -> V_206 ) ) ,
V_137 -> V_20 , V_19 ) ;
F_105 ( V_137 -> V_49 ,
V_137 -> V_90 ) ;
F_148 ( V_72 , V_207 , V_137 -> V_49 ,
L_14 ,
V_72 -> V_197 + 1 ,
V_137 -> V_90 ) ;
F_134 ( V_72 ) ;
return true ;
}
F_149 ( F_119 ( V_137 ) ,
V_106 , V_105 ) ;
#define F_150 min_t(u16, FM10K_MIN_TXD - 1, DESC_NEEDED * 2)
if ( F_11 ( V_106 && F_151 ( V_137 -> V_49 ) &&
( F_76 ( V_137 ) >= F_150 ) ) ) {
F_106 () ;
if ( F_152 ( V_137 -> V_49 ,
V_137 -> V_90 ) &&
! F_135 ( V_196 , & V_72 -> V_195 ) ) {
F_153 ( V_137 -> V_49 ,
V_137 -> V_90 ) ;
++ V_137 -> V_162 . V_175 ;
}
}
return ! ! V_104 ;
}
static void F_154 ( struct V_208 * V_209 )
{
unsigned int V_210 , V_111 ;
if ( ! ( V_209 -> V_211 & V_212 ) )
goto V_213;
V_111 = V_209 -> V_106 ;
if ( ! V_111 )
goto V_213;
V_210 = V_209 -> V_105 / V_111 ;
V_210 += 24 ;
if ( V_210 > 3000 )
V_210 = 3000 ;
if ( ( V_210 > 300 ) && ( V_210 < 1200 ) )
V_210 /= 3 ;
else
V_210 /= 2 ;
V_209 -> V_211 = V_210 | V_212 ;
V_213:
V_209 -> V_105 = 0 ;
V_209 -> V_106 = 0 ;
}
static void F_155 ( struct V_103 * V_45 )
{
T_5 V_211 = V_214 ;
F_154 ( & V_45 -> V_199 ) ;
F_154 ( & V_45 -> V_113 ) ;
V_211 |= ( V_45 -> V_199 . V_211 & V_215 ) ;
V_211 |= ( V_45 -> V_113 . V_211 & V_215 ) << V_216 ;
F_19 ( V_211 , V_45 -> V_211 ) ;
}
static int F_156 ( struct V_217 * V_46 , int V_104 )
{
struct V_103 * V_45 =
F_157 ( V_46 , struct V_103 , V_46 ) ;
struct V_4 * V_48 ;
int V_218 ;
bool V_219 = true ;
F_158 (ring, q_vector->tx)
V_219 &= F_137 ( V_45 , V_48 ) ;
if ( V_45 -> V_113 . V_22 > 1 )
V_218 = F_159 ( V_104 / V_45 -> V_113 . V_22 , 1 ) ;
else
V_218 = V_104 ;
F_158 (ring, q_vector->rx)
V_219 &= F_75 ( V_45 , V_48 ,
V_218 ) ;
if ( ! V_219 )
return V_104 ;
F_160 ( V_46 ) ;
F_155 ( V_45 ) ;
return 0 ;
}
static bool F_161 ( struct V_71 * V_72 )
{
struct V_77 * V_12 = V_72 -> V_49 ;
struct V_220 * V_185 ;
int V_221 , V_19 ;
int V_222 ;
V_222 = F_162 ( V_12 ) ;
if ( V_222 <= 1 )
return false ;
V_185 = & V_72 -> V_223 [ V_224 ] ;
V_185 -> V_225 = V_222 ;
V_185 -> V_226 = ( 1 << F_163 ( V_222 - 1 ) ) - 1 ;
V_221 = V_72 -> V_204 . V_227 . V_228 / V_222 ;
V_221 = 1 << ( F_163 ( V_221 ) - 1 ) ;
V_185 = & V_72 -> V_223 [ V_229 ] ;
V_221 = F_164 ( T_4 , V_221 , V_185 -> V_230 ) ;
V_185 -> V_225 = V_221 ;
V_185 -> V_226 = ( 1 << F_163 ( V_221 - 1 ) ) - 1 ;
for ( V_19 = 0 ; V_19 < V_222 ; V_19 ++ )
F_165 ( V_12 , V_19 , V_221 , V_221 * V_19 ) ;
V_72 -> V_231 = V_221 * V_222 ;
V_72 -> V_232 = V_221 * V_222 ;
return true ;
}
static bool F_166 ( struct V_71 * V_72 )
{
struct V_220 * V_185 ;
T_4 V_221 ;
V_185 = & V_72 -> V_223 [ V_229 ] ;
V_221 = F_164 ( T_4 , V_72 -> V_204 . V_227 . V_228 , V_185 -> V_230 ) ;
V_185 -> V_225 = V_221 ;
V_185 -> V_226 = ( 1 << F_163 ( V_221 - 1 ) ) - 1 ;
V_72 -> V_231 = V_221 ;
V_72 -> V_232 = V_221 ;
return true ;
}
static void F_167 ( struct V_71 * V_72 )
{
V_72 -> V_231 = 1 ;
V_72 -> V_232 = 1 ;
if ( F_161 ( V_72 ) )
return;
F_166 ( V_72 ) ;
}
static int F_168 ( struct V_71 * V_72 ,
unsigned int V_233 , unsigned int V_234 ,
unsigned int V_235 , unsigned int V_236 ,
unsigned int V_237 , unsigned int V_238 )
{
struct V_103 * V_45 ;
struct V_4 * V_48 ;
int V_239 , V_36 ;
V_239 = V_235 + V_237 ;
V_36 = sizeof( struct V_103 ) +
( sizeof( struct V_4 ) * V_239 ) ;
V_45 = F_169 ( V_36 , V_240 ) ;
if ( ! V_45 )
return - V_241 ;
F_170 ( V_72 -> V_49 , & V_45 -> V_46 ,
F_156 , V_242 ) ;
V_72 -> V_45 [ V_234 ] = V_45 ;
V_45 -> V_72 = V_72 ;
V_45 -> V_234 = V_234 ;
V_48 = V_45 -> V_48 ;
V_45 -> V_199 . V_48 = V_48 ;
V_45 -> V_199 . V_200 = V_243 ;
V_45 -> V_199 . V_211 = V_72 -> V_244 ;
V_45 -> V_199 . V_22 = V_235 ;
while ( V_235 ) {
V_48 -> V_12 = & V_72 -> V_245 -> V_12 ;
V_48 -> V_49 = V_72 -> V_49 ;
V_48 -> V_45 = V_45 ;
V_48 -> V_22 = V_72 -> V_246 ;
V_48 -> V_90 = V_236 ;
V_72 -> V_137 [ V_236 ] = V_48 ;
V_235 -- ;
V_236 += V_233 ;
V_48 ++ ;
}
V_45 -> V_113 . V_48 = V_48 ;
V_45 -> V_113 . V_211 = V_72 -> V_247 ;
V_45 -> V_113 . V_22 = V_237 ;
while ( V_237 ) {
V_48 -> V_12 = & V_72 -> V_245 -> V_12 ;
V_48 -> V_49 = V_72 -> V_49 ;
F_171 ( V_48 -> V_79 , V_72 -> V_79 ) ;
V_48 -> V_45 = V_45 ;
V_48 -> V_22 = V_72 -> V_248 ;
V_48 -> V_90 = V_238 ;
V_72 -> V_5 [ V_238 ] = V_48 ;
V_237 -- ;
V_238 += V_233 ;
V_48 ++ ;
}
F_172 ( V_45 ) ;
return 0 ;
}
static void F_173 ( struct V_71 * V_72 , int V_234 )
{
struct V_103 * V_45 = V_72 -> V_45 [ V_234 ] ;
struct V_4 * V_48 ;
F_174 ( V_45 ) ;
F_158 (ring, q_vector->tx)
V_72 -> V_137 [ V_48 -> V_90 ] = NULL ;
F_158 (ring, q_vector->rx)
V_72 -> V_5 [ V_48 -> V_90 ] = NULL ;
V_72 -> V_45 [ V_234 ] = NULL ;
F_175 ( & V_45 -> V_46 ) ;
F_176 ( V_45 , V_249 ) ;
}
static int F_177 ( struct V_71 * V_72 )
{
unsigned int V_250 = V_72 -> V_251 ;
unsigned int V_252 = V_72 -> V_231 ;
unsigned int V_253 = V_72 -> V_232 ;
unsigned int V_238 = 0 , V_236 = 0 , V_234 = 0 ;
int V_254 ;
if ( V_250 >= ( V_252 + V_253 ) ) {
for (; V_252 ; V_234 ++ ) {
V_254 = F_168 ( V_72 , V_250 , V_234 ,
0 , 0 , 1 , V_238 ) ;
if ( V_254 )
goto V_255;
V_252 -- ;
V_238 ++ ;
}
}
for (; V_234 < V_250 ; V_234 ++ ) {
int V_256 = F_178 ( V_252 , V_250 - V_234 ) ;
int V_257 = F_178 ( V_253 , V_250 - V_234 ) ;
V_254 = F_168 ( V_72 , V_250 , V_234 ,
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
V_72 -> V_232 = 0 ;
V_72 -> V_231 = 0 ;
V_72 -> V_251 = 0 ;
while ( V_234 -- )
F_173 ( V_72 , V_234 ) ;
return - V_241 ;
}
static void F_179 ( struct V_71 * V_72 )
{
int V_234 = V_72 -> V_251 ;
V_72 -> V_232 = 0 ;
V_72 -> V_231 = 0 ;
V_72 -> V_251 = 0 ;
while ( V_234 -- )
F_173 ( V_72 , V_234 ) ;
}
static void F_180 ( struct V_71 * V_72 )
{
F_181 ( V_72 -> V_245 ) ;
F_182 ( V_72 -> V_258 ) ;
V_72 -> V_258 = NULL ;
}
static int F_183 ( struct V_71 * V_72 )
{
struct V_203 * V_204 = & V_72 -> V_204 ;
int V_259 , V_260 ;
V_259 = F_159 ( V_72 -> V_231 , V_72 -> V_232 ) ;
V_259 = F_164 ( T_4 , V_259 , F_184 () ) ;
V_259 += F_185 ( V_204 ) ;
V_259 = F_164 ( int , V_259 , V_204 -> V_227 . V_261 ) ;
V_72 -> V_258 = F_186 ( V_259 , sizeof( struct V_262 ) ,
V_240 ) ;
if ( ! V_72 -> V_258 )
return - V_241 ;
for ( V_260 = 0 ; V_260 < V_259 ; V_260 ++ )
V_72 -> V_258 [ V_260 ] . V_263 = V_260 ;
V_259 = F_187 ( V_72 -> V_245 ,
V_72 -> V_258 ,
F_188 ( V_204 ) ,
V_259 ) ;
if ( V_259 < 0 ) {
F_182 ( V_72 -> V_258 ) ;
V_72 -> V_258 = NULL ;
return - V_241 ;
}
V_72 -> V_251 = V_259 - F_185 ( V_204 ) ;
return 0 ;
}
static bool F_189 ( struct V_71 * V_72 )
{
struct V_77 * V_12 = V_72 -> V_49 ;
int V_264 , V_265 , V_221 , V_19 , V_266 ;
T_4 V_267 = V_72 -> V_223 [ V_224 ] . V_226 + 1 ;
T_7 V_268 = F_162 ( V_12 ) ;
if ( V_268 <= 1 )
return false ;
V_221 = V_72 -> V_223 [ V_229 ] . V_225 ;
for ( V_264 = 0 , V_265 = 0 ; V_264 < V_268 ; V_264 ++ , V_265 += V_221 ) {
V_266 = V_264 ;
for ( V_19 = 0 ; V_19 < V_221 ; V_19 ++ ) {
V_72 -> V_137 [ V_265 + V_19 ] -> V_206 = V_266 ;
V_72 -> V_137 [ V_265 + V_19 ] -> V_269 = V_264 ;
V_72 -> V_5 [ V_265 + V_19 ] -> V_206 = V_266 ;
V_72 -> V_5 [ V_265 + V_19 ] -> V_269 = V_264 ;
V_266 += V_267 ;
}
}
return true ;
}
static void F_190 ( struct V_71 * V_72 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_72 -> V_231 ; V_19 ++ )
V_72 -> V_5 [ V_19 ] -> V_206 = V_19 ;
for ( V_19 = 0 ; V_19 < V_72 -> V_232 ; V_19 ++ )
V_72 -> V_137 [ V_19 ] -> V_206 = V_19 ;
}
static void F_191 ( struct V_71 * V_72 )
{
if ( F_189 ( V_72 ) )
return;
F_190 ( V_72 ) ;
}
static void F_192 ( struct V_71 * V_72 )
{
T_4 V_19 , V_221 = V_72 -> V_223 [ V_229 ] . V_225 ;
T_5 V_270 , V_271 ;
if ( V_72 -> V_49 -> V_272 ) {
for ( V_19 = V_273 ; V_19 -- ; ) {
V_270 = V_72 -> V_270 [ V_19 ] ;
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
V_72 -> V_270 [ V_19 ] = V_270 ;
}
}
int F_193 ( struct V_71 * V_72 )
{
int V_254 ;
F_167 ( V_72 ) ;
V_254 = F_183 ( V_72 ) ;
if ( V_254 ) {
F_123 ( & V_72 -> V_245 -> V_12 ,
L_15 ) ;
return V_254 ;
}
V_254 = F_177 ( V_72 ) ;
if ( V_254 )
return V_254 ;
F_191 ( V_72 ) ;
F_192 ( V_72 ) ;
return 0 ;
}
void F_194 ( struct V_71 * V_72 )
{
F_179 ( V_72 ) ;
F_180 ( V_72 ) ;
}
