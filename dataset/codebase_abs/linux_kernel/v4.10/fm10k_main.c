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
union V_20 * V_21 ,
struct V_37 * V_38 )
{
struct V_11 * V_11 = V_24 -> V_11 ;
unsigned char * V_39 = F_32 ( V_11 ) + V_24 -> V_18 ;
unsigned int V_40 = F_33 ( V_21 -> V_41 . V_42 ) ;
#if ( V_16 < 8192 )
unsigned int V_36 = V_35 ;
#else
unsigned int V_36 = F_34 ( V_40 , 512 ) ;
#endif
unsigned int V_43 ;
if ( F_13 ( F_35 ( V_38 ) ) )
goto V_44;
if ( F_11 ( V_40 <= V_45 ) ) {
memcpy ( F_36 ( V_38 , V_40 ) , V_39 , F_34 ( V_40 , sizeof( long ) ) ) ;
if ( F_11 ( ! F_24 ( V_11 ) ) )
return true ;
F_16 ( V_11 ) ;
return false ;
}
V_43 = F_37 ( V_39 , V_45 ) ;
memcpy ( F_36 ( V_38 , V_43 ) , V_39 , F_34 ( V_43 , sizeof( long ) ) ) ;
V_39 += V_43 ;
V_40 -= V_43 ;
V_44:
F_38 ( V_38 , F_39 ( V_38 ) -> V_46 , V_11 ,
( unsigned long ) V_39 & ~ V_47 , V_40 , V_36 ) ;
return F_28 ( V_24 , V_11 , V_36 ) ;
}
static struct V_37 * F_40 ( struct V_7 * V_8 ,
union V_20 * V_21 ,
struct V_37 * V_38 )
{
struct V_9 * V_24 ;
struct V_11 * V_11 ;
V_24 = & V_8 -> V_24 [ V_8 -> V_48 ] ;
V_11 = V_24 -> V_11 ;
F_41 ( V_11 ) ;
if ( F_11 ( ! V_38 ) ) {
void * V_49 = F_32 ( V_11 ) +
V_24 -> V_18 ;
F_42 ( V_49 ) ;
#if V_50 < 128
F_42 ( V_49 + V_50 ) ;
#endif
V_38 = F_43 ( & V_8 -> V_51 -> V_52 ,
V_45 ) ;
if ( F_13 ( ! V_38 ) ) {
V_8 -> V_13 . V_14 ++ ;
return NULL ;
}
F_41 ( V_38 -> V_53 ) ;
}
F_44 ( V_8 -> V_15 ,
V_24 -> V_12 ,
V_24 -> V_18 ,
V_35 ,
V_17 ) ;
if ( F_31 ( V_24 , V_21 , V_38 ) ) {
F_22 ( V_8 , V_24 ) ;
} else {
F_45 ( V_8 -> V_15 , V_24 -> V_12 ,
V_16 , V_17 ) ;
}
V_24 -> V_11 = NULL ;
return V_38 ;
}
static inline void F_46 ( struct V_7 * V_54 ,
union V_20 * V_21 ,
struct V_37 * V_38 )
{
F_47 ( V_38 ) ;
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
V_38 -> V_64 = true ;
else if ( ! F_48 ( V_21 , V_65 ) )
return;
V_38 -> V_66 = V_67 ;
V_54 -> V_13 . V_68 ++ ;
}
static inline void F_49 ( struct V_7 * V_54 ,
union V_20 * V_21 ,
struct V_37 * V_38 )
{
T_4 V_69 ;
if ( ! ( V_54 -> V_55 -> V_56 & V_70 ) )
return;
V_69 = F_33 ( V_21 -> V_41 . V_71 ) & V_72 ;
if ( ! V_69 )
return;
F_50 ( V_38 , F_51 ( V_21 -> V_28 . V_73 ) ,
( F_52 ( V_69 ) & V_74 ) ?
V_75 : V_76 ) ;
}
static void F_53 ( struct V_7 * V_8 ,
union V_20 T_5 * V_21 ,
struct V_37 * V_38 )
{
struct V_77 * V_15 = V_8 -> V_55 ;
struct V_78 * V_79 = F_54 ( V_8 -> V_79 ) ;
if ( V_79 ) {
T_4 V_80 = F_33 ( F_55 ( V_38 ) -> V_81 . V_41 . V_82 ) - 1 ;
V_80 -= V_79 -> V_82 ;
if ( V_80 < V_79 -> V_40 && V_79 -> V_83 [ V_80 ] )
V_15 = V_79 -> V_83 [ V_80 ] ;
else
V_79 = NULL ;
}
V_38 -> V_84 = F_56 ( V_38 , V_15 ) ;
if ( ! V_79 )
return;
F_57 ( F_58 ( V_15 ) , V_38 -> V_85 + V_86 , 1 ,
! ! ( V_21 -> V_41 . V_87 &
F_59 ( V_88 ) ) ) ;
}
static unsigned int F_60 ( struct V_7 * V_8 ,
union V_20 * V_21 ,
struct V_37 * V_38 )
{
unsigned int V_85 = V_38 -> V_85 ;
F_49 ( V_8 , V_21 , V_38 ) ;
F_46 ( V_8 , V_21 , V_38 ) ;
F_55 ( V_38 ) -> V_81 . V_41 . V_89 = V_21 -> V_41 . V_89 ;
F_61 ( V_38 , V_8 -> V_90 ) ;
F_55 ( V_38 ) -> V_81 . V_28 . V_91 = V_21 -> V_28 . V_91 ;
if ( V_21 -> V_41 . V_89 ) {
T_4 V_92 = F_33 ( V_21 -> V_41 . V_89 ) ;
if ( ( V_92 & V_93 ) != V_8 -> V_92 )
F_62 ( V_38 , F_63 ( V_94 ) , V_92 ) ;
else if ( V_92 & V_95 )
F_62 ( V_38 , F_63 ( V_94 ) ,
V_92 & V_95 ) ;
}
F_53 ( V_8 , V_21 , V_38 ) ;
return V_85 ;
}
static bool F_64 ( struct V_7 * V_8 ,
union V_20 * V_21 )
{
T_6 V_96 = V_8 -> V_48 + 1 ;
V_96 = ( V_96 < V_8 -> V_25 ) ? V_96 : 0 ;
V_8 -> V_48 = V_96 ;
F_42 ( F_18 ( V_8 , V_96 ) ) ;
if ( F_11 ( F_48 ( V_21 , V_97 ) ) )
return false ;
return true ;
}
static bool F_65 ( struct V_7 * V_8 ,
union V_20 * V_21 ,
struct V_37 * V_38 )
{
if ( F_13 ( ( F_48 ( V_21 ,
V_98 ) ) ) ) {
#define F_66 ( T_7 , T_8 ) \
((rxd)->w.csum_err & cpu_to_le16(bit))
if ( F_66 ( V_21 , V_99 ) )
V_8 -> V_13 . V_100 ++ ;
if ( F_66 ( V_21 , V_101 ) )
V_8 -> V_13 . V_102 ++ ;
if ( F_66 ( V_21 , V_103 ) )
V_8 -> V_13 . V_104 ++ ;
if ( F_66 ( V_21 , V_105 ) )
V_8 -> V_13 . V_106 ++ ;
if ( F_66 ( V_21 , V_107 ) )
V_8 -> V_13 . V_108 ++ ;
F_67 ( V_38 ) ;
V_8 -> V_13 . V_109 ++ ;
return true ;
}
if ( F_68 ( V_38 ) )
return true ;
return false ;
}
static void F_69 ( struct V_110 * V_51 ,
struct V_37 * V_38 )
{
F_70 ( & V_51 -> V_52 , V_38 ) ;
}
static int F_71 ( struct V_110 * V_51 ,
struct V_7 * V_8 ,
int V_111 )
{
struct V_37 * V_38 = V_8 -> V_38 ;
unsigned int V_112 = 0 , V_113 = 0 ;
T_4 V_19 = F_72 ( V_8 ) ;
while ( F_11 ( V_113 < V_111 ) ) {
union V_20 * V_21 ;
if ( V_19 >= V_114 ) {
F_17 ( V_8 , V_19 ) ;
V_19 = 0 ;
}
V_21 = F_18 ( V_8 , V_8 -> V_48 ) ;
if ( ! V_21 -> V_28 . V_29 )
break;
F_73 () ;
V_38 = F_40 ( V_8 , V_21 , V_38 ) ;
if ( ! V_38 )
break;
V_19 ++ ;
if ( F_64 ( V_8 , V_21 ) )
continue;
if ( F_65 ( V_8 , V_21 , V_38 ) ) {
V_38 = NULL ;
continue;
}
V_112 += F_60 ( V_8 , V_21 , V_38 ) ;
F_69 ( V_51 , V_38 ) ;
V_38 = NULL ;
V_113 ++ ;
}
V_8 -> V_38 = V_38 ;
F_74 ( & V_8 -> V_115 ) ;
V_8 -> V_116 . V_117 += V_113 ;
V_8 -> V_116 . V_118 += V_112 ;
F_75 ( & V_8 -> V_115 ) ;
V_51 -> V_119 . V_113 += V_113 ;
V_51 -> V_119 . V_112 += V_112 ;
return V_113 ;
}
static struct V_120 * F_76 ( struct V_37 * V_38 )
{
struct V_121 * V_122 = F_58 ( V_38 -> V_15 ) ;
struct V_123 * V_124 ;
V_124 = F_77 ( & V_122 -> V_124 ,
struct V_123 , V_125 ) ;
if ( ! V_124 )
return NULL ;
if ( V_124 -> V_126 != F_78 ( V_38 ) -> V_127 )
return NULL ;
return (struct V_120 * ) ( F_79 ( V_38 ) + V_128 ) ;
}
static struct V_120 * F_80 ( struct V_37 * V_38 )
{
struct V_129 * V_130 ;
int V_131 = F_81 ( V_38 ) ;
if ( F_82 ( V_38 ) != F_63 ( V_132 ) )
return NULL ;
V_130 = (struct V_129 * ) ( F_83 ( V_38 ) + V_131 ) ;
if ( V_130 -> V_133 & V_134 )
return NULL ;
if ( V_130 -> V_133 & V_135 )
return (struct V_120 * ) ( V_130 + 1 ) ;
return (struct V_120 * ) ( & V_130 -> V_136 ) ;
}
T_9 F_84 ( struct V_37 * V_38 )
{
T_10 V_137 = 0 , V_138 = 0 , V_139 ;
struct V_120 * V_140 ;
if ( V_38 -> V_141 != V_142 ||
V_38 -> V_143 != F_63 ( V_144 ) )
return 0 ;
switch ( F_82 ( V_38 ) ) {
case F_63 ( V_132 ) :
V_137 = F_85 ( V_38 ) -> V_84 ;
break;
case F_63 ( V_145 ) :
V_137 = F_86 ( V_38 ) -> V_146 ;
break;
default:
return 0 ;
}
switch ( V_137 ) {
case V_147 :
V_140 = F_76 ( V_38 ) ;
break;
case V_148 :
V_140 = F_80 ( V_38 ) ;
break;
default:
return 0 ;
}
if ( ! V_140 )
return 0 ;
switch ( V_140 -> V_149 ) {
case F_63 ( V_132 ) :
V_138 = F_87 ( V_38 ) -> V_84 ;
break;
case F_63 ( V_145 ) :
V_138 = F_88 ( V_38 ) -> V_146 ;
break;
default:
return 0 ;
}
switch ( V_138 ) {
case V_150 :
V_139 = F_89 ( V_38 ) ;
break;
case V_147 :
V_139 = 8 ;
break;
default:
return 0 ;
}
if ( F_90 ( V_38 ) + V_139 -
F_91 ( V_38 ) > V_151 )
return 0 ;
return V_140 -> V_149 ;
}
static int F_92 ( struct V_7 * V_152 ,
struct V_153 * V_154 )
{
struct V_37 * V_38 = V_154 -> V_38 ;
struct V_155 * V_156 ;
unsigned char * V_157 ;
T_10 V_158 ;
if ( V_38 -> V_66 != V_159 )
return 0 ;
if ( ! F_93 ( V_38 ) )
return 0 ;
if ( V_38 -> V_64 ) {
if ( ! F_84 ( V_38 ) )
goto V_160;
V_157 = F_90 ( V_38 ) ;
} else {
V_157 = F_79 ( V_38 ) ;
}
V_158 = ( V_157 - V_38 -> V_53 ) + ( ( (struct V_161 * ) V_157 ) -> V_162 << 2 ) ;
V_154 -> V_163 |= V_164 ;
V_154 -> V_165 = F_39 ( V_38 ) -> V_165 ;
V_154 -> V_166 += ( V_154 -> V_165 - 1 ) * V_158 ;
V_156 = F_94 ( V_152 , V_152 -> V_23 ) ;
V_156 -> V_158 = V_158 ;
V_156 -> V_167 = F_59 ( F_39 ( V_38 ) -> V_168 ) ;
return 1 ;
V_160:
V_152 -> V_55 -> V_56 &= ~ V_169 ;
if ( ! F_95 () )
F_96 ( V_152 -> V_55 ,
L_4 ) ;
return - 1 ;
}
static void F_97 ( struct V_7 * V_152 ,
struct V_153 * V_154 )
{
struct V_37 * V_38 = V_154 -> V_38 ;
struct V_155 * V_156 ;
union {
struct V_170 * V_171 ;
struct V_172 * V_173 ;
T_10 * V_174 ;
} V_175 ;
T_10 * V_176 ;
T_9 V_177 ;
T_9 V_84 ;
T_10 V_137 = 0 ;
if ( V_38 -> V_66 != V_159 )
goto V_178;
if ( V_38 -> V_64 ) {
V_84 = F_84 ( V_38 ) ;
if ( ! V_84 ) {
if ( F_98 ( V_38 ) ) {
F_99 ( V_152 -> V_15 ,
L_5 ) ;
V_152 -> V_179 . V_62 ++ ;
}
goto V_178;
}
V_175 . V_174 = F_100 ( V_38 ) ;
V_176 = F_90 ( V_38 ) ;
} else {
V_84 = F_82 ( V_38 ) ;
V_175 . V_174 = F_83 ( V_38 ) ;
V_176 = F_79 ( V_38 ) ;
}
switch ( V_84 ) {
case F_63 ( V_132 ) :
V_137 = V_175 . V_171 -> V_84 ;
break;
case F_63 ( V_145 ) :
V_137 = V_175 . V_173 -> V_146 ;
if ( F_11 ( ( V_176 - V_175 . V_174 ) ==
sizeof( struct V_172 ) ) )
break;
F_101 ( V_38 , V_175 . V_174 - V_38 -> V_53 +
sizeof( struct V_172 ) ,
& V_137 , & V_177 ) ;
if ( F_13 ( V_177 ) )
V_137 = V_180 ;
break;
default:
break;
}
switch ( V_137 ) {
case V_150 :
case V_147 :
break;
case V_148 :
if ( V_38 -> V_64 )
break;
default:
if ( F_13 ( F_95 () ) ) {
F_99 ( V_152 -> V_15 ,
L_6 ,
V_84 , V_137 ) ;
}
F_98 ( V_38 ) ;
V_152 -> V_179 . V_62 ++ ;
goto V_178;
}
V_154 -> V_163 |= V_164 ;
V_152 -> V_179 . V_68 ++ ;
V_178:
V_156 = F_94 ( V_152 , V_152 -> V_23 ) ;
V_156 -> V_158 = 0 ;
V_156 -> V_167 = 0 ;
}
static T_10 F_102 ( struct V_37 * V_38 , T_6 V_163 )
{
T_6 V_181 = 0 ;
V_181 |= F_103 ( V_163 , V_164 ,
V_182 ) ;
return V_181 ;
}
static bool F_104 ( struct V_7 * V_152 ,
struct V_155 * V_156 , T_4 V_22 ,
T_3 V_12 , unsigned int V_40 , T_10 V_181 )
{
if ( ( ++ V_22 & ( V_183 - 1 ) ) == 0 )
V_181 |= V_184 | V_185 ;
V_156 -> V_186 = F_19 ( V_12 ) ;
V_156 -> V_133 = V_181 ;
V_156 -> V_187 = F_59 ( V_40 ) ;
return V_22 == V_152 -> V_25 ;
}
static int F_105 ( struct V_7 * V_152 , T_4 V_40 )
{
F_106 ( V_152 -> V_55 , V_152 -> V_90 ) ;
F_107 () ;
if ( F_11 ( F_72 ( V_152 ) < V_40 ) )
return - V_188 ;
F_108 ( V_152 -> V_55 , V_152 -> V_90 ) ;
++ V_152 -> V_179 . V_189 ;
return 0 ;
}
static inline int F_109 ( struct V_7 * V_152 , T_4 V_40 )
{
if ( F_11 ( F_72 ( V_152 ) >= V_40 ) )
return 0 ;
return F_105 ( V_152 , V_40 ) ;
}
static void F_110 ( struct V_7 * V_152 ,
struct V_153 * V_154 )
{
struct V_37 * V_38 = V_154 -> V_38 ;
struct V_153 * V_190 ;
struct V_155 * V_156 ;
struct V_191 * V_192 ;
unsigned char * V_53 ;
T_3 V_12 ;
unsigned int V_193 , V_40 ;
T_6 V_163 = V_154 -> V_163 ;
T_4 V_22 = V_152 -> V_23 ;
T_10 V_133 = F_102 ( V_38 , V_163 ) ;
V_156 = F_94 ( V_152 , V_22 ) ;
if ( F_111 ( V_38 ) )
V_156 -> V_89 = F_59 ( F_112 ( V_38 ) ) ;
else
V_156 -> V_89 = 0 ;
V_40 = F_113 ( V_38 ) ;
V_53 = V_38 -> V_53 ;
V_12 = F_114 ( V_152 -> V_15 , V_53 , V_40 , V_194 ) ;
V_193 = V_38 -> V_193 ;
V_190 = V_154 ;
for ( V_192 = & F_39 ( V_38 ) -> V_195 [ 0 ] ; ; V_192 ++ ) {
if ( F_15 ( V_152 -> V_15 , V_12 ) )
goto V_196;
F_115 ( V_190 , V_85 , V_40 ) ;
F_116 ( V_190 , V_12 , V_12 ) ;
while ( F_13 ( V_40 > V_197 ) ) {
if ( F_104 ( V_152 , V_156 ++ , V_22 ++ , V_12 ,
V_197 , V_133 ) ) {
V_156 = F_94 ( V_152 , 0 ) ;
V_22 = 0 ;
}
V_12 += V_197 ;
V_40 -= V_197 ;
}
if ( F_11 ( ! V_193 ) )
break;
if ( F_104 ( V_152 , V_156 ++ , V_22 ++ ,
V_12 , V_40 , V_133 ) ) {
V_156 = F_94 ( V_152 , 0 ) ;
V_22 = 0 ;
}
V_40 = F_117 ( V_192 ) ;
V_193 -= V_40 ;
V_12 = F_118 ( V_152 -> V_15 , V_192 , 0 , V_40 ,
V_194 ) ;
V_190 = & V_152 -> V_190 [ V_22 ] ;
}
V_133 |= V_198 ;
if ( F_104 ( V_152 , V_156 , V_22 ++ , V_12 , V_40 , V_133 ) )
V_22 = 0 ;
F_119 ( F_120 ( V_152 ) , V_154 -> V_166 ) ;
F_121 ( V_154 -> V_38 ) ;
F_20 () ;
V_154 -> V_199 = V_156 ;
V_152 -> V_23 = V_22 ;
F_109 ( V_152 , V_200 ) ;
if ( F_122 ( F_120 ( V_152 ) ) || ! V_38 -> V_201 ) {
F_21 ( V_22 , V_152 -> V_31 ) ;
F_123 () ;
}
return;
V_196:
F_124 ( V_152 -> V_15 , L_7 ) ;
for (; ; ) {
V_190 = & V_152 -> V_190 [ V_22 ] ;
F_125 ( V_152 , V_190 ) ;
if ( V_190 == V_154 )
break;
if ( V_22 == 0 )
V_22 = V_152 -> V_25 ;
V_22 -- ;
}
V_152 -> V_23 = V_22 ;
}
T_11 F_126 ( struct V_37 * V_38 ,
struct V_7 * V_152 )
{
T_4 V_25 = F_127 ( F_113 ( V_38 ) ) ;
struct V_153 * V_154 ;
unsigned short V_202 ;
T_6 V_163 = 0 ;
int V_203 ;
for ( V_202 = 0 ; V_202 < F_39 ( V_38 ) -> V_46 ; V_202 ++ )
V_25 += F_127 ( F_39 ( V_38 ) -> V_195 [ V_202 ] . V_40 ) ;
if ( F_109 ( V_152 , V_25 + 3 ) ) {
V_152 -> V_179 . V_204 ++ ;
return V_205 ;
}
V_154 = & V_152 -> V_190 [ V_152 -> V_23 ] ;
V_154 -> V_38 = V_38 ;
V_154 -> V_166 = F_128 (unsigned int, skb->len, ETH_ZLEN) ;
V_154 -> V_165 = 1 ;
V_154 -> V_163 = V_163 ;
V_203 = F_92 ( V_152 , V_154 ) ;
if ( V_203 < 0 )
goto V_206;
else if ( ! V_203 )
F_97 ( V_152 , V_154 ) ;
F_110 ( V_152 , V_154 ) ;
return V_207 ;
V_206:
F_67 ( V_154 -> V_38 ) ;
V_154 -> V_38 = NULL ;
return V_207 ;
}
static T_12 F_129 ( struct V_7 * V_54 )
{
return V_54 -> V_116 . V_117 ;
}
T_12 F_130 ( struct V_7 * V_54 , bool V_208 )
{
struct V_121 * V_122 = V_54 -> V_51 -> V_122 ;
struct V_209 * V_210 = & V_122 -> V_210 ;
T_6 V_211 , V_31 ;
if ( F_11 ( V_208 ) ) {
V_211 = V_54 -> V_48 ;
V_31 = V_54 -> V_23 ;
} else {
V_211 = F_131 ( V_210 , F_132 ( V_54 -> V_212 ) ) ;
V_31 = F_131 ( V_210 , F_133 ( V_54 -> V_212 ) ) ;
}
return ( ( V_211 <= V_31 ) ? V_31 : V_31 + V_54 -> V_25 ) - V_211 ;
}
bool F_134 ( struct V_7 * V_152 )
{
T_6 V_213 = F_129 ( V_152 ) ;
T_6 V_214 = V_152 -> V_179 . V_214 ;
T_6 V_215 = F_130 ( V_152 , true ) ;
F_135 ( V_152 ) ;
if ( ! V_215 || ( V_214 != V_213 ) ) {
V_152 -> V_179 . V_214 = V_213 ;
F_136 ( V_216 , & V_152 -> V_217 ) ;
return false ;
}
return F_137 ( V_216 , & V_152 -> V_217 ) ;
}
void F_138 ( struct V_121 * V_122 )
{
if ( ! F_139 ( V_218 , & V_122 -> V_217 ) ) {
V_122 -> V_219 ++ ;
V_122 -> V_133 |= V_220 ;
F_140 ( V_122 ) ;
}
}
static bool F_141 ( struct V_110 * V_51 ,
struct V_7 * V_152 , int V_221 )
{
struct V_121 * V_122 = V_51 -> V_122 ;
struct V_153 * V_190 ;
struct V_155 * V_156 ;
unsigned int V_112 = 0 , V_113 = 0 ;
unsigned int V_111 = V_51 -> V_222 . V_223 ;
unsigned int V_22 = V_152 -> V_48 ;
if ( F_139 ( V_218 , & V_122 -> V_217 ) )
return true ;
V_190 = & V_152 -> V_190 [ V_22 ] ;
V_156 = F_94 ( V_152 , V_22 ) ;
V_22 -= V_152 -> V_25 ;
do {
struct V_155 * V_224 = V_190 -> V_199 ;
if ( ! V_224 )
break;
F_142 () ;
if ( ! ( V_224 -> V_133 & V_225 ) )
break;
V_190 -> V_199 = NULL ;
V_112 += V_190 -> V_166 ;
V_113 += V_190 -> V_165 ;
F_143 ( V_190 -> V_38 , V_221 ) ;
F_144 ( V_152 -> V_15 ,
F_145 ( V_190 , V_12 ) ,
F_146 ( V_190 , V_85 ) ,
V_194 ) ;
V_190 -> V_38 = NULL ;
F_115 ( V_190 , V_85 , 0 ) ;
while ( V_156 != V_224 ) {
V_190 ++ ;
V_156 ++ ;
V_22 ++ ;
if ( F_13 ( ! V_22 ) ) {
V_22 -= V_152 -> V_25 ;
V_190 = V_152 -> V_190 ;
V_156 = F_94 ( V_152 , 0 ) ;
}
if ( F_146 ( V_190 , V_85 ) ) {
F_45 ( V_152 -> V_15 ,
F_145 ( V_190 , V_12 ) ,
F_146 ( V_190 , V_85 ) ,
V_194 ) ;
F_115 ( V_190 , V_85 , 0 ) ;
}
}
V_190 ++ ;
V_156 ++ ;
V_22 ++ ;
if ( F_13 ( ! V_22 ) ) {
V_22 -= V_152 -> V_25 ;
V_190 = V_152 -> V_190 ;
V_156 = F_94 ( V_152 , 0 ) ;
}
F_42 ( V_156 ) ;
V_111 -- ;
} while ( F_11 ( V_111 ) );
V_22 += V_152 -> V_25 ;
V_152 -> V_48 = V_22 ;
F_74 ( & V_152 -> V_115 ) ;
V_152 -> V_116 . V_118 += V_112 ;
V_152 -> V_116 . V_117 += V_113 ;
F_75 ( & V_152 -> V_115 ) ;
V_51 -> V_222 . V_112 += V_112 ;
V_51 -> V_222 . V_113 += V_113 ;
if ( F_147 ( V_152 ) && F_134 ( V_152 ) ) {
struct V_209 * V_210 = & V_122 -> V_210 ;
F_148 ( V_122 , V_226 , V_152 -> V_55 ,
L_8
L_9
L_10
L_11
L_12 ,
V_152 -> V_90 ,
F_131 ( V_210 , F_132 ( V_152 -> V_212 ) ) ,
F_131 ( V_210 , F_133 ( V_152 -> V_212 ) ) ,
V_152 -> V_23 , V_22 ) ;
F_106 ( V_152 -> V_55 ,
V_152 -> V_90 ) ;
F_149 ( V_122 , V_227 , V_152 -> V_55 ,
L_13 ,
V_122 -> V_219 + 1 ,
V_152 -> V_90 ) ;
F_138 ( V_122 ) ;
return true ;
}
F_150 ( F_120 ( V_152 ) ,
V_113 , V_112 ) ;
#define F_151 min_t(u16, FM10K_MIN_TXD - 1, DESC_NEEDED * 2)
if ( F_13 ( V_113 && F_152 ( V_152 -> V_55 ) &&
( F_72 ( V_152 ) >= F_151 ) ) ) {
F_107 () ;
if ( F_153 ( V_152 -> V_55 ,
V_152 -> V_90 ) &&
! F_139 ( V_218 , & V_122 -> V_217 ) ) {
F_154 ( V_152 -> V_55 ,
V_152 -> V_90 ) ;
++ V_152 -> V_179 . V_189 ;
}
}
return ! ! V_111 ;
}
static void F_155 ( struct V_228 * V_229 )
{
unsigned int V_230 , V_117 , V_231 ;
if ( ! F_156 ( V_229 -> V_232 ) )
goto V_233;
V_117 = V_229 -> V_113 ;
if ( ! V_117 )
goto V_233;
V_230 = V_229 -> V_112 / V_117 ;
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
V_231 = F_157 ( V_229 -> V_234 ) + 8 ;
V_230 += F_52 ( V_231 ) - 1 ;
V_230 >>= V_231 ;
V_229 -> V_232 = V_230 | V_235 ;
V_233:
V_229 -> V_112 = 0 ;
V_229 -> V_113 = 0 ;
}
static void F_158 ( struct V_110 * V_51 )
{
T_6 V_232 = V_236 ;
F_155 ( & V_51 -> V_222 ) ;
F_155 ( & V_51 -> V_119 ) ;
V_232 |= ( V_51 -> V_222 . V_232 & V_237 ) ;
V_232 |= ( V_51 -> V_119 . V_232 & V_237 ) << V_238 ;
F_21 ( V_232 , V_51 -> V_232 ) ;
}
static int F_159 ( struct V_239 * V_52 , int V_111 )
{
struct V_110 * V_51 =
F_160 ( V_52 , struct V_110 , V_52 ) ;
struct V_7 * V_54 ;
int V_240 , V_241 = 0 ;
bool V_242 = true ;
F_161 (ring, q_vector->tx) {
if ( ! F_141 ( V_51 , V_54 , V_111 ) )
V_242 = false ;
}
if ( V_111 <= 0 )
return V_111 ;
if ( V_51 -> V_119 . V_25 > 1 )
V_240 = F_162 ( V_111 / V_51 -> V_119 . V_25 , 1 ) ;
else
V_240 = V_111 ;
F_161 (ring, q_vector->rx) {
int V_243 = F_71 ( V_51 , V_54 , V_240 ) ;
V_241 += V_243 ;
if ( V_243 >= V_240 )
V_242 = false ;
}
if ( ! V_242 )
return V_111 ;
F_163 ( V_52 , V_241 ) ;
F_158 ( V_51 ) ;
return F_164 ( V_241 , V_111 - 1 ) ;
}
static bool F_165 ( struct V_121 * V_122 )
{
struct V_77 * V_15 = V_122 -> V_55 ;
struct V_244 * V_202 ;
int V_245 , V_22 ;
int V_246 ;
V_246 = F_166 ( V_15 ) ;
if ( V_246 <= 1 )
return false ;
V_202 = & V_122 -> V_247 [ V_248 ] ;
V_202 -> V_249 = V_246 ;
V_202 -> V_250 = F_52 ( F_167 ( V_246 - 1 ) ) - 1 ;
V_245 = V_122 -> V_210 . V_251 . V_252 / V_246 ;
V_245 = F_52 ( F_167 ( V_245 ) - 1 ) ;
V_202 = & V_122 -> V_247 [ V_253 ] ;
V_245 = F_168 ( T_4 , V_245 , V_202 -> V_254 ) ;
V_202 -> V_249 = V_245 ;
V_202 -> V_250 = F_52 ( F_167 ( V_245 - 1 ) ) - 1 ;
for ( V_22 = 0 ; V_22 < V_246 ; V_22 ++ )
F_169 ( V_15 , V_22 , V_245 , V_245 * V_22 ) ;
V_122 -> V_255 = V_245 * V_246 ;
V_122 -> V_256 = V_245 * V_246 ;
return true ;
}
static bool F_170 ( struct V_121 * V_122 )
{
struct V_244 * V_202 ;
T_4 V_245 ;
V_202 = & V_122 -> V_247 [ V_253 ] ;
V_245 = F_168 ( T_4 , V_122 -> V_210 . V_251 . V_252 , V_202 -> V_254 ) ;
V_202 -> V_249 = V_245 ;
V_202 -> V_250 = F_52 ( F_167 ( V_245 - 1 ) ) - 1 ;
V_122 -> V_255 = V_245 ;
V_122 -> V_256 = V_245 ;
return true ;
}
static void F_171 ( struct V_121 * V_122 )
{
if ( F_165 ( V_122 ) )
return;
F_170 ( V_122 ) ;
}
static void F_172 ( struct V_121 * V_122 )
{
V_122 -> V_256 = 0 ;
V_122 -> V_255 = 0 ;
V_122 -> V_257 = 0 ;
}
static int F_173 ( struct V_121 * V_122 ,
unsigned int V_258 , unsigned int V_259 ,
unsigned int V_260 , unsigned int V_261 ,
unsigned int V_262 , unsigned int V_263 )
{
struct V_110 * V_51 ;
struct V_7 * V_54 ;
int V_264 , V_40 ;
V_264 = V_260 + V_262 ;
V_40 = sizeof( struct V_110 ) +
( sizeof( struct V_7 ) * V_264 ) ;
V_51 = F_174 ( V_40 , V_265 ) ;
if ( ! V_51 )
return - V_266 ;
F_175 ( V_122 -> V_55 , & V_51 -> V_52 ,
F_159 , V_267 ) ;
V_122 -> V_51 [ V_259 ] = V_51 ;
V_51 -> V_122 = V_122 ;
V_51 -> V_259 = V_259 ;
V_54 = V_51 -> V_54 ;
V_51 -> V_222 . V_54 = V_54 ;
V_51 -> V_222 . V_223 = V_268 ;
V_51 -> V_222 . V_232 = V_122 -> V_269 ;
V_51 -> V_222 . V_234 = V_122 -> V_210 . V_251 . V_234 ;
V_51 -> V_222 . V_25 = V_260 ;
while ( V_260 ) {
V_54 -> V_15 = & V_122 -> V_270 -> V_15 ;
V_54 -> V_55 = V_122 -> V_55 ;
V_54 -> V_51 = V_51 ;
V_54 -> V_25 = V_122 -> V_271 ;
V_54 -> V_90 = V_261 ;
V_122 -> V_152 [ V_261 ] = V_54 ;
V_260 -- ;
V_261 += V_258 ;
V_54 ++ ;
}
V_51 -> V_119 . V_54 = V_54 ;
V_51 -> V_119 . V_232 = V_122 -> V_272 ;
V_51 -> V_119 . V_234 = V_122 -> V_210 . V_251 . V_234 ;
V_51 -> V_119 . V_25 = V_262 ;
while ( V_262 ) {
V_54 -> V_15 = & V_122 -> V_270 -> V_15 ;
V_54 -> V_55 = V_122 -> V_55 ;
F_176 ( V_54 -> V_79 , V_122 -> V_79 ) ;
V_54 -> V_51 = V_51 ;
V_54 -> V_25 = V_122 -> V_273 ;
V_54 -> V_90 = V_263 ;
V_122 -> V_8 [ V_263 ] = V_54 ;
V_262 -- ;
V_263 += V_258 ;
V_54 ++ ;
}
F_177 ( V_51 ) ;
return 0 ;
}
static void F_178 ( struct V_121 * V_122 , int V_259 )
{
struct V_110 * V_51 = V_122 -> V_51 [ V_259 ] ;
struct V_7 * V_54 ;
F_179 ( V_51 ) ;
F_161 (ring, q_vector->tx)
V_122 -> V_152 [ V_54 -> V_90 ] = NULL ;
F_161 (ring, q_vector->rx)
V_122 -> V_8 [ V_54 -> V_90 ] = NULL ;
V_122 -> V_51 [ V_259 ] = NULL ;
F_180 ( & V_51 -> V_52 ) ;
F_181 ( V_51 , V_274 ) ;
}
static int F_182 ( struct V_121 * V_122 )
{
unsigned int V_275 = V_122 -> V_257 ;
unsigned int V_276 = V_122 -> V_255 ;
unsigned int V_277 = V_122 -> V_256 ;
unsigned int V_263 = 0 , V_261 = 0 , V_259 = 0 ;
int V_278 ;
if ( V_275 >= ( V_276 + V_277 ) ) {
for (; V_276 ; V_259 ++ ) {
V_278 = F_173 ( V_122 , V_275 , V_259 ,
0 , 0 , 1 , V_263 ) ;
if ( V_278 )
goto V_279;
V_276 -- ;
V_263 ++ ;
}
}
for (; V_259 < V_275 ; V_259 ++ ) {
int V_280 = F_183 ( V_276 , V_275 - V_259 ) ;
int V_281 = F_183 ( V_277 , V_275 - V_259 ) ;
V_278 = F_173 ( V_122 , V_275 , V_259 ,
V_281 , V_261 ,
V_280 , V_263 ) ;
if ( V_278 )
goto V_279;
V_276 -= V_280 ;
V_277 -= V_281 ;
V_263 ++ ;
V_261 ++ ;
}
return 0 ;
V_279:
F_172 ( V_122 ) ;
while ( V_259 -- )
F_178 ( V_122 , V_259 ) ;
return - V_266 ;
}
static void F_184 ( struct V_121 * V_122 )
{
int V_259 = V_122 -> V_257 ;
F_172 ( V_122 ) ;
while ( V_259 -- )
F_178 ( V_122 , V_259 ) ;
}
static void F_185 ( struct V_121 * V_122 )
{
F_186 ( V_122 -> V_270 ) ;
F_187 ( V_122 -> V_282 ) ;
V_122 -> V_282 = NULL ;
}
static int F_188 ( struct V_121 * V_122 )
{
struct V_209 * V_210 = & V_122 -> V_210 ;
int V_283 , V_284 ;
V_283 = F_162 ( V_122 -> V_255 , V_122 -> V_256 ) ;
V_283 = F_168 ( T_4 , V_283 , F_189 () ) ;
V_283 += F_190 ( V_210 ) ;
V_283 = F_168 ( int , V_283 , V_210 -> V_251 . V_285 ) ;
V_122 -> V_282 = F_191 ( V_283 , sizeof( struct V_286 ) ,
V_265 ) ;
if ( ! V_122 -> V_282 )
return - V_266 ;
for ( V_284 = 0 ; V_284 < V_283 ; V_284 ++ )
V_122 -> V_282 [ V_284 ] . V_287 = V_284 ;
V_283 = F_192 ( V_122 -> V_270 ,
V_122 -> V_282 ,
F_193 ( V_210 ) ,
V_283 ) ;
if ( V_283 < 0 ) {
F_187 ( V_122 -> V_282 ) ;
V_122 -> V_282 = NULL ;
return V_283 ;
}
V_122 -> V_257 = V_283 - F_190 ( V_210 ) ;
return 0 ;
}
static bool F_194 ( struct V_121 * V_122 )
{
struct V_77 * V_15 = V_122 -> V_55 ;
int V_288 , V_289 , V_245 , V_22 , V_290 ;
T_4 V_291 = V_122 -> V_247 [ V_248 ] . V_250 + 1 ;
T_10 V_292 = F_166 ( V_15 ) ;
if ( V_292 <= 1 )
return false ;
V_245 = V_122 -> V_247 [ V_253 ] . V_249 ;
for ( V_288 = 0 , V_289 = 0 ; V_288 < V_292 ; V_288 ++ , V_289 += V_245 ) {
V_290 = V_288 ;
for ( V_22 = 0 ; V_22 < V_245 ; V_22 ++ ) {
V_122 -> V_152 [ V_289 + V_22 ] -> V_212 = V_290 ;
V_122 -> V_152 [ V_289 + V_22 ] -> V_293 = V_288 ;
V_122 -> V_8 [ V_289 + V_22 ] -> V_212 = V_290 ;
V_122 -> V_8 [ V_289 + V_22 ] -> V_293 = V_288 ;
V_290 += V_291 ;
}
}
return true ;
}
static void F_195 ( struct V_121 * V_122 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_122 -> V_255 ; V_22 ++ )
V_122 -> V_8 [ V_22 ] -> V_212 = V_22 ;
for ( V_22 = 0 ; V_22 < V_122 -> V_256 ; V_22 ++ )
V_122 -> V_152 [ V_22 ] -> V_212 = V_22 ;
}
static void F_196 ( struct V_121 * V_122 )
{
if ( F_194 ( V_122 ) )
return;
F_195 ( V_122 ) ;
}
static void F_197 ( struct V_121 * V_122 )
{
T_4 V_22 , V_245 = V_122 -> V_247 [ V_253 ] . V_249 ;
T_6 V_294 ;
if ( F_198 ( V_122 -> V_55 ) ) {
for ( V_22 = V_295 ; V_22 -- ; ) {
V_294 = V_122 -> V_294 [ V_22 ] ;
if ( ( ( ( V_294 << 24 ) >> 24 ) < V_245 ) &&
( ( ( V_294 << 16 ) >> 24 ) < V_245 ) &&
( ( ( V_294 << 8 ) >> 24 ) < V_245 ) &&
( ( ( V_294 ) >> 24 ) < V_245 ) )
continue;
F_124 ( & V_122 -> V_270 -> V_15 ,
L_14 ) ;
goto V_296;
}
return;
}
V_296:
F_199 ( V_122 , NULL ) ;
}
int F_200 ( struct V_121 * V_122 )
{
int V_278 ;
F_171 ( V_122 ) ;
V_278 = F_188 ( V_122 ) ;
if ( V_278 ) {
F_124 ( & V_122 -> V_270 -> V_15 ,
L_15 ) ;
goto V_297;
}
V_278 = F_182 ( V_122 ) ;
if ( V_278 ) {
F_124 ( & V_122 -> V_270 -> V_15 ,
L_16 ) ;
goto V_298;
}
F_196 ( V_122 ) ;
F_197 ( V_122 ) ;
return 0 ;
V_298:
F_185 ( V_122 ) ;
V_297:
F_172 ( V_122 ) ;
return V_278 ;
}
void F_201 ( struct V_121 * V_122 )
{
F_184 ( V_122 ) ;
F_185 ( V_122 ) ;
}
