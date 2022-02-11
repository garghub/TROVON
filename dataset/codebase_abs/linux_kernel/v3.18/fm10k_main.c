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
V_8 = F_10 ( V_10 | V_11 ) ;
if ( F_11 ( ! V_8 ) ) {
V_5 -> V_12 . V_13 ++ ;
return false ;
}
V_9 = F_12 ( V_5 -> V_14 , V_8 , 0 , V_15 , V_16 ) ;
if ( F_13 ( V_5 -> V_14 , V_9 ) ) {
F_14 ( V_8 ) ;
V_7 -> V_8 = NULL ;
V_5 -> V_12 . V_13 ++ ;
return false ;
}
V_7 -> V_9 = V_9 ;
V_7 -> V_8 = V_8 ;
V_7 -> V_17 = 0 ;
return true ;
}
void F_15 ( struct V_4 * V_5 , T_4 V_18 )
{
union V_19 * V_20 ;
struct V_6 * V_7 ;
T_4 V_21 = V_5 -> V_22 ;
if ( ! V_18 )
return;
V_20 = F_16 ( V_5 , V_21 ) ;
V_7 = & V_5 -> V_23 [ V_21 ] ;
V_21 -= V_5 -> V_24 ;
do {
if ( ! F_8 ( V_5 , V_7 ) )
break;
V_20 -> V_25 . V_26 = F_17 ( V_7 -> V_9 + V_7 -> V_17 ) ;
V_20 ++ ;
V_7 ++ ;
V_21 ++ ;
if ( F_11 ( ! V_21 ) ) {
V_20 = F_16 ( V_5 , 0 ) ;
V_7 = V_5 -> V_23 ;
V_21 -= V_5 -> V_24 ;
}
V_20 -> V_25 . V_27 = 0 ;
V_18 -- ;
} while ( V_18 );
V_21 += V_5 -> V_24 ;
if ( V_5 -> V_22 != V_21 ) {
V_5 -> V_22 = V_21 ;
V_5 -> V_28 = V_21 ;
F_18 () ;
F_19 ( V_21 , V_5 -> V_29 ) ;
}
}
static void F_20 ( struct V_4 * V_5 ,
struct V_6 * V_30 )
{
struct V_6 * V_31 ;
T_4 V_32 = V_5 -> V_28 ;
V_31 = & V_5 -> V_23 [ V_32 ] ;
V_32 ++ ;
V_5 -> V_28 = ( V_32 < V_5 -> V_24 ) ? V_32 : 0 ;
memcpy ( V_31 , V_30 , sizeof( struct V_6 ) ) ;
F_21 ( V_5 -> V_14 , V_30 -> V_9 ,
V_30 -> V_17 ,
V_33 ,
V_16 ) ;
}
static bool F_22 ( struct V_6 * V_23 ,
struct V_8 * V_8 ,
unsigned int V_34 )
{
if ( F_11 ( F_23 ( V_8 ) != F_24 () ) )
return false ;
#if ( V_15 < 8192 )
if ( F_11 ( F_25 ( V_8 ) != 1 ) )
return false ;
V_23 -> V_17 ^= V_33 ;
F_26 ( & V_8 -> V_35 ) ;
#else
V_23 -> V_17 += V_34 ;
if ( V_23 -> V_17 > ( V_15 - V_33 ) )
return false ;
F_27 ( V_8 ) ;
#endif
return true ;
}
static bool F_28 ( struct V_4 * V_5 ,
struct V_6 * V_23 ,
union V_19 * V_20 ,
struct V_36 * V_37 )
{
struct V_8 * V_8 = V_23 -> V_8 ;
unsigned int V_38 = F_29 ( V_20 -> V_39 . V_40 ) ;
#if ( V_15 < 8192 )
unsigned int V_34 = V_33 ;
#else
unsigned int V_34 = F_30 ( V_38 , V_41 ) ;
#endif
if ( ( V_38 <= V_42 ) && ! F_31 ( V_37 ) ) {
unsigned char * V_43 = F_32 ( V_8 ) + V_23 -> V_17 ;
memcpy ( F_33 ( V_37 , V_38 ) , V_43 , F_30 ( V_38 , sizeof( long ) ) ) ;
if ( F_9 ( F_23 ( V_8 ) == F_24 () ) )
return true ;
F_34 ( V_8 ) ;
return false ;
}
F_35 ( V_37 , F_36 ( V_37 ) -> V_44 , V_8 ,
V_23 -> V_17 , V_38 , V_34 ) ;
return F_22 ( V_23 , V_8 , V_34 ) ;
}
static struct V_36 * F_37 ( struct V_4 * V_5 ,
union V_19 * V_20 ,
struct V_36 * V_37 )
{
struct V_6 * V_23 ;
struct V_8 * V_8 ;
V_23 = & V_5 -> V_23 [ V_5 -> V_45 ] ;
V_8 = V_23 -> V_8 ;
F_38 ( V_8 ) ;
if ( F_9 ( ! V_37 ) ) {
void * V_46 = F_32 ( V_8 ) +
V_23 -> V_17 ;
F_39 ( V_46 ) ;
#if V_41 < 128
F_39 ( V_46 + V_41 ) ;
#endif
V_37 = F_40 ( V_5 -> V_47 ,
V_42 ) ;
if ( F_11 ( ! V_37 ) ) {
V_5 -> V_12 . V_13 ++ ;
return NULL ;
}
F_38 ( V_37 -> V_48 ) ;
}
F_41 ( V_5 -> V_14 ,
V_23 -> V_9 ,
V_23 -> V_17 ,
V_33 ,
V_16 ) ;
if ( F_28 ( V_5 , V_23 , V_20 , V_37 ) ) {
F_20 ( V_5 , V_23 ) ;
} else {
F_42 ( V_5 -> V_14 , V_23 -> V_9 ,
V_15 , V_16 ) ;
}
V_23 -> V_8 = NULL ;
return V_37 ;
}
static inline void F_43 ( struct V_4 * V_49 ,
union V_19 * V_20 ,
struct V_36 * V_37 )
{
F_44 ( V_37 ) ;
if ( ! ( V_49 -> V_47 -> V_50 & V_51 ) )
return;
if ( F_45 ( V_20 ,
V_52 |
V_53 |
V_54 |
V_55 ) ) {
V_49 -> V_12 . V_56 ++ ;
return;
}
if ( F_45 ( V_20 , V_57 ) )
V_37 -> V_58 = true ;
else if ( ! F_45 ( V_20 , V_59 ) )
return;
V_37 -> V_60 = V_61 ;
}
static inline void F_46 ( struct V_4 * V_49 ,
union V_19 * V_20 ,
struct V_36 * V_37 )
{
T_4 V_62 ;
if ( ! ( V_49 -> V_47 -> V_50 & V_63 ) )
return;
V_62 = F_29 ( V_20 -> V_39 . V_64 ) & V_65 ;
if ( ! V_62 )
return;
F_47 ( V_37 , F_48 ( V_20 -> V_66 . V_67 ) ,
( V_68 & ( 1ul << V_62 ) ) ?
V_69 : V_70 ) ;
}
static void F_49 ( struct V_4 * V_5 ,
union V_19 * V_20 ,
struct V_36 * V_37 )
{
struct V_71 * V_72 = V_5 -> V_73 -> V_72 ;
F_50 ( V_37 ) -> V_74 = V_20 -> V_25 . V_75 ;
if ( F_11 ( V_72 -> V_76 & V_77 ) )
F_51 ( V_72 , F_52 ( V_37 ) ,
F_53 ( V_20 -> V_25 . V_75 ) ) ;
}
static void F_54 ( struct V_4 * V_5 ,
union V_19 * V_20 ,
struct V_36 * V_37 )
{
struct V_78 * V_14 = V_5 -> V_47 ;
struct V_79 * V_80 = F_55 ( V_5 -> V_80 ) ;
if ( V_80 ) {
T_4 V_81 = F_29 ( F_50 ( V_37 ) -> V_82 . V_39 . V_83 ) - 1 ;
V_81 -= V_80 -> V_83 ;
if ( V_81 < V_80 -> V_38 && V_80 -> V_84 [ V_81 ] )
V_14 = V_80 -> V_84 [ V_81 ] ;
else
V_80 = NULL ;
}
V_37 -> V_85 = F_56 ( V_37 , V_14 ) ;
if ( ! V_80 )
return;
F_57 ( F_58 ( V_14 ) , V_37 -> V_86 + V_87 , 1 ,
! ! ( V_20 -> V_39 . V_88 &
F_59 ( V_89 ) ) ) ;
}
static unsigned int F_60 ( struct V_4 * V_5 ,
union V_19 * V_20 ,
struct V_36 * V_37 )
{
unsigned int V_86 = V_37 -> V_86 ;
F_46 ( V_5 , V_20 , V_37 ) ;
F_43 ( V_5 , V_20 , V_37 ) ;
F_49 ( V_5 , V_20 , V_37 ) ;
F_50 ( V_37 ) -> V_82 . V_39 . V_90 = V_20 -> V_39 . V_90 ;
F_61 ( V_37 , V_5 -> V_91 ) ;
F_50 ( V_37 ) -> V_82 . V_66 . V_92 = V_20 -> V_66 . V_92 ;
if ( V_20 -> V_39 . V_90 ) {
T_4 V_93 = F_29 ( V_20 -> V_39 . V_90 ) ;
if ( V_93 != V_5 -> V_93 )
F_62 ( V_37 , F_63 ( V_94 ) , V_93 ) ;
}
F_54 ( V_5 , V_20 , V_37 ) ;
return V_86 ;
}
static bool F_64 ( struct V_4 * V_5 ,
union V_19 * V_20 )
{
T_5 V_95 = V_5 -> V_45 + 1 ;
V_95 = ( V_95 < V_5 -> V_24 ) ? V_95 : 0 ;
V_5 -> V_45 = V_95 ;
F_39 ( F_16 ( V_5 , V_95 ) ) ;
if ( F_9 ( F_45 ( V_20 , V_96 ) ) )
return false ;
return true ;
}
static void F_65 ( struct V_4 * V_5 ,
union V_19 * V_20 ,
struct V_36 * V_37 )
{
struct V_97 * V_98 = & F_36 ( V_37 ) -> V_99 [ 0 ] ;
unsigned char * V_43 ;
unsigned int V_100 ;
V_43 = F_66 ( V_98 ) ;
V_100 = F_67 ( V_43 , V_42 ) ;
F_68 ( V_37 , V_43 , F_30 ( V_100 , sizeof( long ) ) ) ;
F_69 ( V_98 , V_100 ) ;
V_98 -> V_17 += V_100 ;
V_37 -> V_101 -= V_100 ;
V_37 -> V_29 += V_100 ;
}
static bool F_70 ( struct V_4 * V_5 ,
union V_19 * V_20 ,
struct V_36 * V_37 )
{
if ( F_11 ( ( F_45 ( V_20 ,
V_102 ) ) ) ) {
F_71 ( V_37 ) ;
V_5 -> V_12 . V_103 ++ ;
return true ;
}
if ( F_31 ( V_37 ) )
F_65 ( V_5 , V_20 , V_37 ) ;
if ( F_11 ( V_37 -> V_86 < 60 ) ) {
int V_104 = 60 - V_37 -> V_86 ;
if ( F_72 ( V_37 , V_104 ) )
return true ;
F_33 ( V_37 , V_104 ) ;
}
return false ;
}
static void F_73 ( struct V_105 * V_73 ,
struct V_36 * V_37 )
{
F_74 ( & V_73 -> V_106 , V_37 ) ;
}
static bool F_75 ( struct V_105 * V_73 ,
struct V_4 * V_5 ,
int V_107 )
{
struct V_36 * V_37 = V_5 -> V_37 ;
unsigned int V_108 = 0 , V_109 = 0 ;
T_4 V_18 = F_76 ( V_5 ) ;
do {
union V_19 * V_20 ;
if ( V_18 >= V_110 ) {
F_15 ( V_5 , V_18 ) ;
V_18 = 0 ;
}
V_20 = F_16 ( V_5 , V_5 -> V_45 ) ;
if ( ! F_45 ( V_20 , V_111 ) )
break;
F_77 () ;
V_37 = F_37 ( V_5 , V_20 , V_37 ) ;
if ( ! V_37 )
break;
V_18 ++ ;
if ( F_64 ( V_5 , V_20 ) )
continue;
if ( F_70 ( V_5 , V_20 , V_37 ) ) {
V_37 = NULL ;
continue;
}
V_108 += F_60 ( V_5 , V_20 , V_37 ) ;
F_73 ( V_73 , V_37 ) ;
V_37 = NULL ;
V_109 ++ ;
} while ( F_9 ( V_109 < V_107 ) );
V_5 -> V_37 = V_37 ;
F_78 ( & V_5 -> V_112 ) ;
V_5 -> V_113 . V_114 += V_109 ;
V_5 -> V_113 . V_115 += V_108 ;
F_79 ( & V_5 -> V_112 ) ;
V_73 -> V_116 . V_109 += V_109 ;
V_73 -> V_116 . V_108 += V_108 ;
return V_109 < V_107 ;
}
static struct V_117 * F_80 ( struct V_36 * V_37 )
{
struct V_71 * V_72 = F_58 ( V_37 -> V_14 ) ;
struct V_118 * V_119 ;
V_119 = F_81 ( & V_72 -> V_119 ,
struct V_118 , V_120 ) ;
if ( ! V_119 )
return NULL ;
if ( V_119 -> V_121 != F_82 ( V_37 ) -> V_122 )
return NULL ;
return (struct V_117 * ) ( F_83 ( V_37 ) + V_123 ) ;
}
static struct V_117 * F_84 ( struct V_36 * V_37 )
{
struct V_124 * V_125 ;
int V_126 = F_85 ( V_37 ) ;
if ( F_86 ( V_37 ) != F_63 ( V_127 ) )
return NULL ;
V_125 = (struct V_124 * ) ( F_87 ( V_37 ) + V_126 ) ;
if ( V_125 -> V_76 & V_128 )
return NULL ;
if ( V_125 -> V_129 != F_63 ( V_130 ) )
return NULL ;
if ( V_125 -> V_76 & V_131 )
return (struct V_117 * ) ( V_125 + 1 ) ;
return (struct V_117 * ) ( & V_125 -> V_132 ) ;
}
static T_6 F_88 ( struct V_36 * V_37 )
{
struct V_117 * V_133 ;
T_7 V_134 = 0 ;
switch ( F_86 ( V_37 ) ) {
case F_63 ( V_127 ) :
V_134 = F_89 ( V_37 ) -> V_85 ;
break;
case F_63 ( V_135 ) :
V_134 = F_90 ( V_37 ) -> V_136 ;
break;
default:
return 0 ;
}
switch ( V_134 ) {
case V_137 :
V_133 = F_80 ( V_37 ) ;
break;
case V_138 :
V_133 = F_84 ( V_37 ) ;
break;
default:
return 0 ;
}
if ( ! V_133 )
return 0 ;
switch ( V_133 -> V_139 ) {
case F_63 ( V_127 ) :
case F_63 ( V_135 ) :
break;
default:
return 0 ;
}
return V_133 -> V_139 ;
}
static int F_91 ( struct V_4 * V_140 ,
struct V_141 * V_142 )
{
struct V_36 * V_37 = V_142 -> V_37 ;
struct V_143 * V_144 ;
unsigned char * V_145 ;
T_7 V_146 ;
if ( V_37 -> V_60 != V_147 )
return 0 ;
if ( ! F_92 ( V_37 ) )
return 0 ;
if ( V_37 -> V_58 ) {
if ( ! F_88 ( V_37 ) )
goto V_148;
V_145 = F_93 ( V_37 ) ;
} else {
V_145 = F_83 ( V_37 ) ;
}
V_146 = ( V_145 - V_37 -> V_48 ) + ( ( (struct V_149 * ) V_145 ) -> V_150 << 2 ) ;
V_142 -> V_151 |= V_152 ;
V_142 -> V_153 = F_36 ( V_37 ) -> V_153 ;
V_142 -> V_154 += ( V_142 -> V_153 - 1 ) * V_146 ;
V_144 = F_94 ( V_140 , V_140 -> V_22 ) ;
V_144 -> V_146 = V_146 ;
V_144 -> V_155 = F_59 ( F_36 ( V_37 ) -> V_156 ) ;
return 1 ;
V_148:
V_140 -> V_47 -> V_50 &= ~ V_157 ;
if ( ! F_95 () )
F_96 ( V_140 -> V_47 ,
L_3 ) ;
return - 1 ;
}
static void F_97 ( struct V_4 * V_140 ,
struct V_141 * V_142 )
{
struct V_36 * V_37 = V_142 -> V_37 ;
struct V_143 * V_144 ;
union {
struct V_158 * V_159 ;
struct V_160 * V_161 ;
T_7 * V_162 ;
} V_163 ;
T_6 V_85 ;
T_7 V_134 = 0 ;
if ( V_37 -> V_60 != V_147 )
goto V_164;
if ( V_37 -> V_58 ) {
V_85 = F_88 ( V_37 ) ;
if ( ! V_85 ) {
if ( F_98 ( V_37 ) ) {
F_99 ( V_140 -> V_14 ,
L_4 ) ;
V_140 -> V_165 . V_56 ++ ;
}
goto V_164;
}
V_163 . V_162 = F_100 ( V_37 ) ;
} else {
V_85 = F_86 ( V_37 ) ;
V_163 . V_162 = F_87 ( V_37 ) ;
}
switch ( V_85 ) {
case F_63 ( V_127 ) :
V_134 = V_163 . V_159 -> V_85 ;
break;
case F_63 ( V_135 ) :
V_134 = V_163 . V_161 -> V_136 ;
break;
default:
if ( F_11 ( F_95 () ) ) {
F_99 ( V_140 -> V_14 ,
L_5 ,
V_85 ) ;
}
V_140 -> V_165 . V_56 ++ ;
goto V_164;
}
switch ( V_134 ) {
case V_166 :
case V_137 :
break;
case V_138 :
if ( V_37 -> V_58 )
break;
default:
if ( F_11 ( F_95 () ) ) {
F_99 ( V_140 -> V_14 ,
L_6 ,
V_134 ) ;
}
V_140 -> V_165 . V_56 ++ ;
goto V_164;
}
V_142 -> V_151 |= V_152 ;
V_164:
V_144 = F_94 ( V_140 , V_140 -> V_22 ) ;
V_144 -> V_146 = 0 ;
V_144 -> V_155 = 0 ;
}
static T_7 F_101 ( struct V_36 * V_37 , T_5 V_151 )
{
T_5 V_167 = 0 ;
if ( F_11 ( F_36 ( V_37 ) -> V_151 & V_168 ) &&
F_9 ( F_36 ( V_37 ) -> V_151 & V_169 ) )
V_167 |= V_170 ;
V_167 |= F_102 ( V_151 , V_152 ,
V_171 ) ;
return V_167 ;
}
static bool F_103 ( struct V_4 * V_140 ,
struct V_143 * V_144 , T_4 V_21 ,
T_3 V_9 , unsigned int V_38 , T_7 V_167 )
{
if ( ( ++ V_21 & ( V_172 - 1 ) ) == 0 )
V_167 |= V_173 | V_174 ;
V_144 -> V_175 = F_17 ( V_9 ) ;
V_144 -> V_76 = V_167 ;
V_144 -> V_176 = F_59 ( V_38 ) ;
return V_21 == V_140 -> V_24 ;
}
static int F_104 ( struct V_4 * V_140 , T_4 V_38 )
{
F_105 ( V_140 -> V_47 , V_140 -> V_91 ) ;
F_106 () ;
if ( F_9 ( F_76 ( V_140 ) < V_38 ) )
return - V_177 ;
F_107 ( V_140 -> V_47 , V_140 -> V_91 ) ;
++ V_140 -> V_165 . V_178 ;
return 0 ;
}
static inline int F_108 ( struct V_4 * V_140 , T_4 V_38 )
{
if ( F_9 ( F_76 ( V_140 ) >= V_38 ) )
return 0 ;
return F_104 ( V_140 , V_38 ) ;
}
static void F_109 ( struct V_4 * V_140 ,
struct V_141 * V_142 )
{
struct V_36 * V_37 = V_142 -> V_37 ;
struct V_141 * V_179 ;
struct V_143 * V_144 ;
struct V_97 * V_98 ;
unsigned char * V_48 ;
T_3 V_9 ;
unsigned int V_101 , V_38 ;
T_5 V_151 = V_142 -> V_151 ;
T_4 V_21 = V_140 -> V_22 ;
T_7 V_76 = F_101 ( V_37 , V_151 ) ;
V_144 = F_94 ( V_140 , V_21 ) ;
if ( F_110 ( V_37 ) )
V_144 -> V_90 = F_59 ( F_111 ( V_37 ) ) ;
else
V_144 -> V_90 = 0 ;
V_38 = F_112 ( V_37 ) ;
V_48 = V_37 -> V_48 ;
V_9 = F_113 ( V_140 -> V_14 , V_48 , V_38 , V_180 ) ;
V_101 = V_37 -> V_101 ;
V_179 = V_142 ;
for ( V_98 = & F_36 ( V_37 ) -> V_99 [ 0 ] ; ; V_98 ++ ) {
if ( F_13 ( V_140 -> V_14 , V_9 ) )
goto V_181;
F_114 ( V_179 , V_86 , V_38 ) ;
F_115 ( V_179 , V_9 , V_9 ) ;
while ( F_11 ( V_38 > V_182 ) ) {
if ( F_103 ( V_140 , V_144 ++ , V_21 ++ , V_9 ,
V_182 , V_76 ) ) {
V_144 = F_94 ( V_140 , 0 ) ;
V_21 = 0 ;
}
V_9 += V_182 ;
V_38 -= V_182 ;
}
if ( F_9 ( ! V_101 ) )
break;
if ( F_103 ( V_140 , V_144 ++ , V_21 ++ ,
V_9 , V_38 , V_76 ) ) {
V_144 = F_94 ( V_140 , 0 ) ;
V_21 = 0 ;
}
V_38 = F_116 ( V_98 ) ;
V_101 -= V_38 ;
V_9 = F_117 ( V_140 -> V_14 , V_98 , 0 , V_38 ,
V_180 ) ;
V_179 = & V_140 -> V_179 [ V_21 ] ;
}
V_76 |= V_183 ;
if ( F_103 ( V_140 , V_144 , V_21 ++ , V_9 , V_38 , V_76 ) )
V_21 = 0 ;
F_118 ( F_119 ( V_140 ) , V_142 -> V_154 ) ;
F_120 ( V_142 -> V_37 ) ;
F_18 () ;
V_142 -> V_184 = V_144 ;
V_140 -> V_22 = V_21 ;
F_108 ( V_140 , V_185 ) ;
if ( F_121 ( F_119 ( V_140 ) ) || ! V_37 -> V_186 ) {
F_19 ( V_21 , V_140 -> V_29 ) ;
F_122 () ;
}
return;
V_181:
F_123 ( V_140 -> V_14 , L_7 ) ;
for (; ; ) {
V_179 = & V_140 -> V_179 [ V_21 ] ;
F_124 ( V_140 , V_179 ) ;
if ( V_179 == V_142 )
break;
if ( V_21 == 0 )
V_21 = V_140 -> V_24 ;
V_21 -- ;
}
V_140 -> V_22 = V_21 ;
}
T_8 F_125 ( struct V_36 * V_37 ,
struct V_4 * V_140 )
{
struct V_141 * V_142 ;
int V_187 ;
T_5 V_151 = 0 ;
#if V_15 > V_182
unsigned short V_188 ;
#endif
T_4 V_24 = F_126 ( F_112 ( V_37 ) ) ;
#if V_15 > V_182
for ( V_188 = 0 ; V_188 < F_36 ( V_37 ) -> V_44 ; V_188 ++ )
V_24 += F_126 ( F_36 ( V_37 ) -> V_99 [ V_188 ] . V_38 ) ;
#else
V_24 += F_36 ( V_37 ) -> V_44 ;
#endif
if ( F_108 ( V_140 , V_24 + 3 ) ) {
V_140 -> V_165 . V_189 ++ ;
return V_190 ;
}
V_142 = & V_140 -> V_179 [ V_140 -> V_22 ] ;
V_142 -> V_37 = V_37 ;
V_142 -> V_154 = F_127 (unsigned int, skb->len, ETH_ZLEN) ;
V_142 -> V_153 = 1 ;
V_142 -> V_151 = V_151 ;
V_187 = F_91 ( V_140 , V_142 ) ;
if ( V_187 < 0 )
goto V_191;
else if ( ! V_187 )
F_97 ( V_140 , V_142 ) ;
F_109 ( V_140 , V_142 ) ;
return V_192 ;
V_191:
F_71 ( V_142 -> V_37 ) ;
V_142 -> V_37 = NULL ;
return V_192 ;
}
static T_9 F_128 ( struct V_4 * V_49 )
{
return V_49 -> V_113 . V_114 ;
}
static T_9 F_129 ( struct V_4 * V_49 )
{
T_5 V_193 = V_49 -> V_45 ;
T_5 V_29 = V_49 -> V_22 ;
return ( ( V_193 <= V_29 ) ? V_29 : V_29 + V_49 -> V_24 ) - V_193 ;
}
bool F_130 ( struct V_4 * V_140 )
{
T_5 V_194 = F_128 ( V_140 ) ;
T_5 V_195 = V_140 -> V_165 . V_195 ;
T_5 V_196 = F_129 ( V_140 ) ;
F_131 ( V_140 ) ;
if ( ! V_196 || ( V_195 != V_194 ) ) {
V_140 -> V_165 . V_195 = V_194 ;
F_132 ( V_197 , & V_140 -> V_198 ) ;
return false ;
}
return F_133 ( V_197 , & V_140 -> V_198 ) ;
}
void F_134 ( struct V_71 * V_72 )
{
if ( ! F_135 ( V_199 , & V_72 -> V_198 ) ) {
F_96 ( V_72 -> V_47 , L_8 ) ;
V_72 -> V_200 ++ ;
V_72 -> V_76 |= V_201 ;
F_136 ( V_72 ) ;
}
}
static bool F_137 ( struct V_105 * V_73 ,
struct V_4 * V_140 )
{
struct V_71 * V_72 = V_73 -> V_72 ;
struct V_141 * V_179 ;
struct V_143 * V_144 ;
unsigned int V_108 = 0 , V_109 = 0 ;
unsigned int V_107 = V_73 -> V_202 . V_203 ;
unsigned int V_21 = V_140 -> V_45 ;
if ( F_135 ( V_199 , & V_72 -> V_198 ) )
return true ;
V_179 = & V_140 -> V_179 [ V_21 ] ;
V_144 = F_94 ( V_140 , V_21 ) ;
V_21 -= V_140 -> V_24 ;
do {
struct V_143 * V_204 = V_179 -> V_184 ;
if ( ! V_204 )
break;
F_138 () ;
if ( ! ( V_204 -> V_76 & V_205 ) )
break;
V_179 -> V_184 = NULL ;
V_108 += V_179 -> V_154 ;
V_109 += V_179 -> V_153 ;
F_139 ( V_179 -> V_37 ) ;
F_140 ( V_140 -> V_14 ,
F_141 ( V_179 , V_9 ) ,
F_142 ( V_179 , V_86 ) ,
V_180 ) ;
V_179 -> V_37 = NULL ;
F_114 ( V_179 , V_86 , 0 ) ;
while ( V_144 != V_204 ) {
V_179 ++ ;
V_144 ++ ;
V_21 ++ ;
if ( F_11 ( ! V_21 ) ) {
V_21 -= V_140 -> V_24 ;
V_179 = V_140 -> V_179 ;
V_144 = F_94 ( V_140 , 0 ) ;
}
if ( F_142 ( V_179 , V_86 ) ) {
F_42 ( V_140 -> V_14 ,
F_141 ( V_179 , V_9 ) ,
F_142 ( V_179 , V_86 ) ,
V_180 ) ;
F_114 ( V_179 , V_86 , 0 ) ;
}
}
V_179 ++ ;
V_144 ++ ;
V_21 ++ ;
if ( F_11 ( ! V_21 ) ) {
V_21 -= V_140 -> V_24 ;
V_179 = V_140 -> V_179 ;
V_144 = F_94 ( V_140 , 0 ) ;
}
F_39 ( V_144 ) ;
V_107 -- ;
} while ( F_9 ( V_107 ) );
V_21 += V_140 -> V_24 ;
V_140 -> V_45 = V_21 ;
F_78 ( & V_140 -> V_112 ) ;
V_140 -> V_113 . V_115 += V_108 ;
V_140 -> V_113 . V_114 += V_109 ;
F_79 ( & V_140 -> V_112 ) ;
V_73 -> V_202 . V_108 += V_108 ;
V_73 -> V_202 . V_109 += V_109 ;
if ( F_143 ( V_140 ) && F_130 ( V_140 ) ) {
struct V_206 * V_207 = & V_72 -> V_207 ;
F_144 ( V_72 , V_208 , V_140 -> V_47 ,
L_9
L_10
L_11
L_12
L_13 ,
V_140 -> V_91 ,
F_145 ( V_207 , F_146 ( V_140 -> V_209 ) ) ,
F_145 ( V_207 , F_147 ( V_140 -> V_209 ) ) ,
V_140 -> V_22 , V_21 ) ;
F_105 ( V_140 -> V_47 ,
V_140 -> V_91 ) ;
F_148 ( V_72 , V_210 , V_140 -> V_47 ,
L_14 ,
V_72 -> V_200 + 1 ,
V_140 -> V_91 ) ;
F_134 ( V_72 ) ;
return true ;
}
F_149 ( F_119 ( V_140 ) ,
V_109 , V_108 ) ;
#define F_150 min_t(u16, FM10K_MIN_TXD - 1, DESC_NEEDED * 2)
if ( F_11 ( V_109 && F_151 ( V_140 -> V_47 ) &&
( F_76 ( V_140 ) >= F_150 ) ) ) {
F_106 () ;
if ( F_152 ( V_140 -> V_47 ,
V_140 -> V_91 ) &&
! F_135 ( V_199 , & V_72 -> V_198 ) ) {
F_153 ( V_140 -> V_47 ,
V_140 -> V_91 ) ;
++ V_140 -> V_165 . V_178 ;
}
}
return ! ! V_107 ;
}
static void F_154 ( struct V_211 * V_212 )
{
unsigned int V_213 , V_114 ;
if ( ! ( V_212 -> V_214 & V_215 ) )
goto V_216;
V_114 = V_212 -> V_109 ;
if ( ! V_114 )
goto V_216;
V_213 = V_212 -> V_108 / V_114 ;
V_213 += 24 ;
if ( V_213 > 3000 )
V_213 = 3000 ;
if ( ( V_213 > 300 ) && ( V_213 < 1200 ) )
V_213 /= 3 ;
else
V_213 /= 2 ;
V_212 -> V_214 = V_213 | V_215 ;
V_216:
V_212 -> V_108 = 0 ;
V_212 -> V_109 = 0 ;
}
static void F_155 ( struct V_105 * V_73 )
{
T_5 V_214 = V_217 ;
F_154 ( & V_73 -> V_202 ) ;
F_154 ( & V_73 -> V_116 ) ;
V_214 |= ( V_73 -> V_202 . V_214 & V_218 ) ;
V_214 |= ( V_73 -> V_116 . V_214 & V_218 ) << V_219 ;
F_19 ( V_214 , V_73 -> V_214 ) ;
}
static int F_156 ( struct V_220 * V_106 , int V_107 )
{
struct V_105 * V_73 =
F_157 ( V_106 , struct V_105 , V_106 ) ;
struct V_4 * V_49 ;
int V_221 ;
bool V_222 = true ;
F_158 (ring, q_vector->tx)
V_222 &= F_137 ( V_73 , V_49 ) ;
if ( V_73 -> V_116 . V_24 > 1 )
V_221 = F_159 ( V_107 / V_73 -> V_116 . V_24 , 1 ) ;
else
V_221 = V_107 ;
F_158 (ring, q_vector->rx)
V_222 &= F_75 ( V_73 , V_49 ,
V_221 ) ;
if ( ! V_222 )
return V_107 ;
F_160 ( V_106 ) ;
F_155 ( V_73 ) ;
return 0 ;
}
static bool F_161 ( struct V_71 * V_72 )
{
struct V_78 * V_14 = V_72 -> V_47 ;
struct V_223 * V_188 ;
int V_224 , V_21 ;
int V_225 ;
V_225 = F_162 ( V_14 ) ;
if ( V_225 <= 1 )
return false ;
V_188 = & V_72 -> V_226 [ V_227 ] ;
V_188 -> V_228 = V_225 ;
V_188 -> V_229 = ( 1 << F_163 ( V_225 - 1 ) ) - 1 ;
V_224 = V_72 -> V_207 . V_230 . V_231 / V_225 ;
V_224 = 1 << ( F_163 ( V_224 ) - 1 ) ;
V_188 = & V_72 -> V_226 [ V_232 ] ;
V_224 = F_164 ( T_4 , V_224 , V_188 -> V_233 ) ;
V_188 -> V_228 = V_224 ;
V_188 -> V_229 = ( 1 << F_163 ( V_224 - 1 ) ) - 1 ;
for ( V_21 = 0 ; V_21 < V_225 ; V_21 ++ )
F_165 ( V_14 , V_21 , V_224 , V_224 * V_21 ) ;
V_72 -> V_234 = V_224 * V_225 ;
V_72 -> V_235 = V_224 * V_225 ;
return true ;
}
static bool F_166 ( struct V_71 * V_72 )
{
struct V_223 * V_188 ;
T_4 V_224 ;
V_188 = & V_72 -> V_226 [ V_232 ] ;
V_224 = F_164 ( T_4 , V_72 -> V_207 . V_230 . V_231 , V_188 -> V_233 ) ;
V_188 -> V_228 = V_224 ;
V_188 -> V_229 = ( 1 << F_163 ( V_224 - 1 ) ) - 1 ;
V_72 -> V_234 = V_224 ;
V_72 -> V_235 = V_224 ;
return true ;
}
static void F_167 ( struct V_71 * V_72 )
{
V_72 -> V_234 = 1 ;
V_72 -> V_235 = 1 ;
if ( F_161 ( V_72 ) )
return;
F_166 ( V_72 ) ;
}
static int F_168 ( struct V_71 * V_72 ,
unsigned int V_236 , unsigned int V_237 ,
unsigned int V_238 , unsigned int V_239 ,
unsigned int V_240 , unsigned int V_241 )
{
struct V_105 * V_73 ;
struct V_4 * V_49 ;
int V_242 , V_38 ;
V_242 = V_238 + V_240 ;
V_38 = sizeof( struct V_105 ) +
( sizeof( struct V_4 ) * V_242 ) ;
V_73 = F_169 ( V_38 , V_243 ) ;
if ( ! V_73 )
return - V_244 ;
F_170 ( V_72 -> V_47 , & V_73 -> V_106 ,
F_156 , V_245 ) ;
V_72 -> V_73 [ V_237 ] = V_73 ;
V_73 -> V_72 = V_72 ;
V_73 -> V_237 = V_237 ;
V_49 = V_73 -> V_49 ;
V_73 -> V_202 . V_49 = V_49 ;
V_73 -> V_202 . V_203 = V_246 ;
V_73 -> V_202 . V_214 = V_72 -> V_247 ;
V_73 -> V_202 . V_24 = V_238 ;
while ( V_238 ) {
V_49 -> V_14 = & V_72 -> V_248 -> V_14 ;
V_49 -> V_47 = V_72 -> V_47 ;
V_49 -> V_73 = V_73 ;
V_49 -> V_24 = V_72 -> V_249 ;
V_49 -> V_91 = V_239 ;
V_72 -> V_140 [ V_239 ] = V_49 ;
V_238 -- ;
V_239 += V_236 ;
V_49 ++ ;
}
V_73 -> V_116 . V_49 = V_49 ;
V_73 -> V_116 . V_214 = V_72 -> V_250 ;
V_73 -> V_116 . V_24 = V_240 ;
while ( V_240 ) {
V_49 -> V_14 = & V_72 -> V_248 -> V_14 ;
V_49 -> V_47 = V_72 -> V_47 ;
F_171 ( V_49 -> V_80 , V_72 -> V_80 ) ;
V_49 -> V_73 = V_73 ;
V_49 -> V_24 = V_72 -> V_251 ;
V_49 -> V_91 = V_241 ;
V_72 -> V_5 [ V_241 ] = V_49 ;
V_240 -- ;
V_241 += V_236 ;
V_49 ++ ;
}
F_172 ( V_73 ) ;
return 0 ;
}
static void F_173 ( struct V_71 * V_72 , int V_237 )
{
struct V_105 * V_73 = V_72 -> V_73 [ V_237 ] ;
struct V_4 * V_49 ;
F_174 ( V_73 ) ;
F_158 (ring, q_vector->tx)
V_72 -> V_140 [ V_49 -> V_91 ] = NULL ;
F_158 (ring, q_vector->rx)
V_72 -> V_5 [ V_49 -> V_91 ] = NULL ;
V_72 -> V_73 [ V_237 ] = NULL ;
F_175 ( & V_73 -> V_106 ) ;
F_176 ( V_73 , V_252 ) ;
}
static int F_177 ( struct V_71 * V_72 )
{
unsigned int V_253 = V_72 -> V_254 ;
unsigned int V_255 = V_72 -> V_234 ;
unsigned int V_256 = V_72 -> V_235 ;
unsigned int V_241 = 0 , V_239 = 0 , V_237 = 0 ;
int V_257 ;
if ( V_253 >= ( V_255 + V_256 ) ) {
for (; V_255 ; V_237 ++ ) {
V_257 = F_168 ( V_72 , V_253 , V_237 ,
0 , 0 , 1 , V_241 ) ;
if ( V_257 )
goto V_258;
V_255 -- ;
V_241 ++ ;
}
}
for (; V_237 < V_253 ; V_237 ++ ) {
int V_259 = F_178 ( V_255 , V_253 - V_237 ) ;
int V_260 = F_178 ( V_256 , V_253 - V_237 ) ;
V_257 = F_168 ( V_72 , V_253 , V_237 ,
V_260 , V_239 ,
V_259 , V_241 ) ;
if ( V_257 )
goto V_258;
V_255 -= V_259 ;
V_256 -= V_260 ;
V_241 ++ ;
V_239 ++ ;
}
return 0 ;
V_258:
V_72 -> V_235 = 0 ;
V_72 -> V_234 = 0 ;
V_72 -> V_254 = 0 ;
while ( V_237 -- )
F_173 ( V_72 , V_237 ) ;
return - V_244 ;
}
static void F_179 ( struct V_71 * V_72 )
{
int V_237 = V_72 -> V_254 ;
V_72 -> V_235 = 0 ;
V_72 -> V_234 = 0 ;
V_72 -> V_254 = 0 ;
while ( V_237 -- )
F_173 ( V_72 , V_237 ) ;
}
static void F_180 ( struct V_71 * V_72 )
{
F_181 ( V_72 -> V_248 ) ;
F_182 ( V_72 -> V_261 ) ;
V_72 -> V_261 = NULL ;
}
static int F_183 ( struct V_71 * V_72 )
{
struct V_206 * V_207 = & V_72 -> V_207 ;
int V_262 , V_263 ;
V_262 = F_159 ( V_72 -> V_234 , V_72 -> V_235 ) ;
V_262 = F_164 ( T_4 , V_262 , F_184 () ) ;
V_262 += F_185 ( V_207 ) ;
V_262 = F_164 ( int , V_262 , V_207 -> V_230 . V_264 ) ;
V_72 -> V_261 = F_186 ( V_262 , sizeof( struct V_265 ) ,
V_243 ) ;
if ( ! V_72 -> V_261 )
return - V_244 ;
for ( V_263 = 0 ; V_263 < V_262 ; V_263 ++ )
V_72 -> V_261 [ V_263 ] . V_266 = V_263 ;
V_262 = F_187 ( V_72 -> V_248 ,
V_72 -> V_261 ,
F_188 ( V_207 ) ,
V_262 ) ;
if ( V_262 < 0 ) {
F_182 ( V_72 -> V_261 ) ;
V_72 -> V_261 = NULL ;
return - V_244 ;
}
V_72 -> V_254 = V_262 - F_185 ( V_207 ) ;
return 0 ;
}
static bool F_189 ( struct V_71 * V_72 )
{
struct V_78 * V_14 = V_72 -> V_47 ;
int V_267 , V_268 , V_224 , V_21 , V_269 ;
T_4 V_270 = V_72 -> V_226 [ V_227 ] . V_229 + 1 ;
T_7 V_271 = F_162 ( V_14 ) ;
if ( V_271 <= 1 )
return false ;
V_224 = V_72 -> V_226 [ V_232 ] . V_228 ;
for ( V_267 = 0 , V_268 = 0 ; V_267 < V_271 ; V_267 ++ , V_268 += V_224 ) {
V_269 = V_267 ;
for ( V_21 = 0 ; V_21 < V_224 ; V_21 ++ ) {
V_72 -> V_140 [ V_268 + V_21 ] -> V_209 = V_269 ;
V_72 -> V_140 [ V_268 + V_21 ] -> V_272 = V_267 ;
V_72 -> V_5 [ V_268 + V_21 ] -> V_209 = V_269 ;
V_72 -> V_5 [ V_268 + V_21 ] -> V_272 = V_267 ;
V_269 += V_270 ;
}
}
return true ;
}
static void F_190 ( struct V_71 * V_72 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_72 -> V_234 ; V_21 ++ )
V_72 -> V_5 [ V_21 ] -> V_209 = V_21 ;
for ( V_21 = 0 ; V_21 < V_72 -> V_235 ; V_21 ++ )
V_72 -> V_140 [ V_21 ] -> V_209 = V_21 ;
}
static void F_191 ( struct V_71 * V_72 )
{
if ( F_189 ( V_72 ) )
return;
F_190 ( V_72 ) ;
}
static void F_192 ( struct V_71 * V_72 )
{
T_4 V_21 , V_224 = V_72 -> V_226 [ V_232 ] . V_228 ;
T_5 V_273 , V_274 ;
if ( V_72 -> V_47 -> V_275 ) {
for ( V_21 = V_276 ; V_21 -- ; ) {
V_273 = V_72 -> V_273 [ V_21 ] ;
if ( ( ( ( V_273 << 24 ) >> 24 ) < V_224 ) &&
( ( ( V_273 << 16 ) >> 24 ) < V_224 ) &&
( ( ( V_273 << 8 ) >> 24 ) < V_224 ) &&
( ( ( V_273 ) >> 24 ) < V_224 ) )
continue;
goto V_277;
}
return;
}
V_277:
for ( V_21 = V_276 ; V_21 -- ; ) {
V_274 = ( ( V_21 * 0x00040004 ) + 0x00020000 ) * V_224 ;
V_273 = ( V_274 & 0x3F803F80 ) >> 7 ;
V_274 += 0x00010001 * V_224 ;
V_273 |= ( V_274 & 0x3F803F80 ) << 1 ;
V_72 -> V_273 [ V_21 ] = V_273 ;
}
}
int F_193 ( struct V_71 * V_72 )
{
int V_257 ;
F_167 ( V_72 ) ;
V_257 = F_183 ( V_72 ) ;
if ( V_257 ) {
F_123 ( & V_72 -> V_248 -> V_14 ,
L_15 ) ;
return V_257 ;
}
V_257 = F_177 ( V_72 ) ;
if ( V_257 )
return V_257 ;
F_191 ( V_72 ) ;
F_192 ( V_72 ) ;
return 0 ;
}
void F_194 ( struct V_71 * V_72 )
{
F_179 ( V_72 ) ;
F_180 ( V_72 ) ;
}
