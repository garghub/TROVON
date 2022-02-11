static struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 V_4 , bool V_5 )
{
struct V_1 * V_6 = NULL ;
T_2 V_7 = 0 ;
int V_8 ;
static const T_1 V_9 = V_10 + V_11 ;
if ( V_4 ) {
V_6 = F_2 ( V_9 , V_4 ,
0 , & V_8 ,
V_12 ) ;
if ( ! V_6 )
return NULL ;
F_3 ( V_6 , V_10 ) ;
F_4 ( V_6 ) ;
F_5 ( V_6 , V_11 ) ;
V_6 -> V_13 = V_4 ;
V_6 -> V_4 += V_4 ;
V_7 |= ( V_3 -> V_7 & V_14 ) ;
} else {
T_1 V_15 = V_5 ? sizeof( struct V_16 ) : 0 ;
V_6 = F_6 ( V_9 + V_15 , V_12 ) ;
if ( ! V_6 )
return NULL ;
F_3 ( V_6 , V_10 + V_15 ) ;
F_4 ( V_6 ) ;
F_5 ( V_6 , V_11 ) ;
}
V_7 |= ( V_3 -> V_7 & V_17 ) ;
F_7 ( V_6 ) = V_7 ;
F_8 ( V_6 ) = V_18 [ V_7 ] ;
F_9 ( V_6 ) |= V_19 ;
return V_6 ;
}
static struct V_1 * F_10 ( struct V_2 * V_3 , T_1 V_4 )
{
return F_1 ( V_3 , V_4 , false ) ;
}
static int F_11 ( const struct V_1 * V_6 )
{
int V_20 = V_6 -> V_4 ;
if ( F_12 ( F_9 ( V_6 ) & V_19 ) )
V_20 += sizeof( struct V_21 ) ;
if ( F_12 ( F_9 ( V_6 ) & V_22 ) )
V_20 += sizeof( struct V_16 ) ;
#define F_13 256
return V_20 <= F_13 ;
}
static inline unsigned int F_14 ( unsigned int V_23 )
{
V_23 -- ;
return ( 3 * V_23 ) / 2 + ( V_23 & 1 ) + 2 ;
}
static unsigned int F_15 ( const struct V_1 * V_6 )
{
unsigned int V_24 , V_25 ;
if ( F_11 ( V_6 ) )
return F_16 ( V_6 -> V_4 , 8 ) ;
V_24 = F_17 ( V_6 ) / 8 ;
V_25 = F_18 ( V_6 ) -> V_26 ;
if ( F_19 ( V_6 ) != F_20 ( V_6 ) )
V_25 ++ ;
return V_24 + F_14 ( V_25 ) ;
}
static void
F_21 ( struct V_1 * V_6 , struct V_27 * V_28 )
{
struct V_16 * V_29 ;
unsigned int V_7 = F_7 ( V_6 ) ;
unsigned int V_30 = ! ! ( V_28 -> V_31 & V_32 ) ;
unsigned int V_33 = ! ! ( V_28 -> V_31 & V_34 ) ;
V_29 = (struct V_16 * ) F_22 ( V_6 , sizeof( * V_29 ) ) ;
V_29 -> V_35 = F_23 ( F_24 ( V_36 ) |
F_25 ( V_30 ) |
F_26 ( V_33 ) |
F_27 ( 0 ) |
F_28 ( V_7 & 1 ) |
F_29 ( ( ( V_7 >> 1 ) & 1 ) ) |
F_30 ( 0 ) |
F_31 ( 2 ) ) ;
V_29 -> V_37 = 0 ;
V_29 -> V_38 = F_32 ( F_16 ( V_28 -> V_38 , 4 ) ) ;
V_29 -> V_39 = F_23 ( F_16 ( V_28 -> V_40 , 4 ) ) ;
V_29 -> V_4 = F_23 ( V_28 -> V_4 ) ;
V_29 -> V_41 = F_23 ( 0 ) ;
V_29 -> V_42 = F_23 ( 0 ) ;
V_29 -> V_43 = F_23 ( 0 ) ;
V_29 -> V_44 = 0 ;
F_33 ( V_6 , sizeof( * V_29 ) ) ;
}
static void
F_34 ( struct V_2 * V_3 , struct V_1 * V_6 , T_1 V_45 ,
T_1 V_4 , T_1 V_46 , T_1 V_47 )
{
struct V_21 * V_48 ;
const struct V_49 * V_50 = & V_3 -> V_51 . V_52 -> V_50 ;
T_1 V_7 = F_7 ( V_6 ) ;
T_1 V_53 = 0 ;
T_1 V_54 = sizeof( * V_48 ) ;
T_1 V_55 = V_56 ;
T_1 V_57 = 0 ;
T_1 V_58 = F_35 ( V_50 -> V_59 ) ? F_36 ( ! V_7 ) :
V_60 ;
if ( F_9 ( V_6 ) & V_22 ) {
V_55 = V_61 ;
V_57 += sizeof( struct V_16 ) ;
V_54 += sizeof( struct V_16 ) ;
V_7 |= 8 ;
}
if ( F_11 ( V_6 ) )
V_57 += V_45 ;
V_48 = (struct V_21 * ) F_22 ( V_6 ,
V_54 ) ;
V_48 -> V_62 = F_37 ( F_38 ( V_55 ) |
F_39 ( V_47 ) |
F_40 ( V_57 ) ) ;
V_48 -> V_63 = F_37 ( F_41 ( V_3 -> V_64 ) |
F_42 ( V_46 ) ) ;
V_48 -> V_65 = F_23 ( V_4 ) ;
V_53 = F_43 ( V_66 ) |
F_44 ( V_7 ) ;
V_48 -> V_67 = F_23 ( ( V_53 ) | V_58 |
F_45 ( F_46 ( & V_3 -> V_68 ) ? 0 : 1 ) ) ;
}
static void F_47 ( void * V_69 , struct V_1 * V_6 )
{
F_48 ( V_6 ) ;
}
void F_49 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
while ( V_3 -> V_70 && ( ( V_6 = F_46 ( & V_3 -> V_68 ) ) != NULL ) ) {
T_1 V_45 = V_6 -> V_4 ;
T_1 V_4 = V_6 -> V_4 ;
T_1 V_71 ;
T_1 V_47 = 0 ;
T_1 V_72 = 0 ;
T_1 V_73 = 0 ;
if ( F_9 ( V_6 ) & V_22 )
V_73 = sizeof( struct V_16 ) ;
if ( F_11 ( V_6 ) )
V_71 = F_16 ( V_45 + V_73 , 16 ) ;
else
V_71 = F_16 ( ( 8 *
F_15 ( V_6 ) ) +
V_73 , 16 ) ;
if ( F_12 ( F_9 ( V_6 ) & V_19 ) )
V_71 += F_16 (
sizeof( struct V_21 ) , 16 ) ;
if ( ! F_50 ( V_74 , & V_3 -> V_51 . V_31 ) ) {
V_72 = F_51 ( V_3 ) ;
V_3 -> V_70 -= V_72 ;
V_3 -> V_75 += V_72 ;
}
if ( V_3 -> V_70 < V_71 ) {
F_52 ( L_1 ,
V_3 , V_6 -> V_4 , V_6 -> V_13 ,
V_71 , V_3 -> V_70 ) ;
break;
}
F_53 ( V_6 , & V_3 -> V_68 ) ;
F_54 ( V_6 , V_76 , V_3 -> V_77 ) ;
V_6 -> V_78 = ( V_79 V_80 ) ( V_71 + V_72 ) ;
V_3 -> V_70 -= V_71 ;
V_3 -> V_75 += V_71 ;
F_52 ( L_2 ,
V_3 , V_6 -> V_4 , V_6 -> V_13 , V_71 ,
V_3 -> V_70 , V_3 -> V_75 ) ;
if ( F_12 ( F_9 ( V_6 ) & V_19 ) ) {
V_4 += F_8 ( V_6 ) ;
if ( ( V_3 -> V_75 >= ( V_3 -> V_81 / 2 ) ) ||
( ! F_55 ( V_3 -> V_82 ,
V_3 -> V_83 + V_3 -> V_84 ) ) ) {
V_47 = 1 ;
V_3 -> V_75 = 0 ;
}
F_34 ( V_3 , V_6 , V_45 , V_4 , V_71 ,
V_47 ) ;
V_3 -> V_85 += V_4 ;
} else if ( ( F_9 ( V_6 ) & V_86 ) ||
( V_3 -> V_75 >= ( V_3 -> V_81 / 2 ) ) ) {
struct V_87 * V_48 =
(struct V_87 * ) V_6 -> V_88 ;
V_48 -> V_89 . V_90 |= F_23 ( V_91 ) ;
V_3 -> V_75 = 0 ;
}
F_56 ( V_3 , V_6 ) ;
F_57 ( V_6 , V_3 ,
F_47 ) ;
F_52 ( L_3 ,
V_3 , V_3 -> V_64 , V_6 , V_4 ) ;
F_58 ( V_3 -> V_51 . V_52 , V_6 , V_3 -> V_92 ) ;
}
}
static bool F_59 ( struct V_2 * V_3 )
{
F_60 ( & V_3 -> V_93 ) ;
if ( F_55 ( V_3 -> V_82 , V_3 -> V_83 + V_3 -> V_84 ) )
V_3 -> V_94 = true ;
F_61 ( & V_3 -> V_93 ) ;
return V_3 -> V_94 ;
}
static void F_62 ( struct V_2 * V_3 )
{
struct V_95 V_96 ;
struct V_1 * V_6 ;
void (* F_63)( struct V_2 * , struct V_1 * );
F_64 ( & V_96 ) ;
F_60 ( & V_3 -> V_93 ) ;
while ( F_65 ( & V_3 -> V_96 ) ) {
F_66 ( & V_3 -> V_96 , & V_96 ) ;
F_61 ( & V_3 -> V_93 ) ;
while ( ( V_6 = F_67 ( & V_96 ) ) ) {
F_63 = F_68 ( V_6 ) ;
F_63 ( V_3 , V_6 ) ;
}
F_60 ( & V_3 -> V_93 ) ;
}
V_3 -> V_94 = false ;
F_61 ( & V_3 -> V_93 ) ;
}
static int F_69 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
int V_97 = 0 ;
F_70 ( V_3 -> V_98 , F_59 ( V_3 ) ) ;
if ( F_71 ( ( V_3 -> V_51 . V_99 != V_100 ) ||
F_72 ( V_101 ) ) ) {
F_73 ( V_6 ) ;
F_74 ( & V_3 -> V_102 ) ;
V_97 = - 1 ;
F_60 ( & V_3 -> V_93 ) ;
if ( V_3 -> V_94 ) {
F_61 ( & V_3 -> V_93 ) ;
goto V_103;
}
F_61 ( & V_3 -> V_93 ) ;
return V_97 ;
}
V_3 -> V_82 += V_6 -> V_4 +
F_8 ( V_6 ) ;
F_75 ( & V_3 -> V_102 , & V_3 -> V_68 ) ;
F_76 ( & V_3 -> V_68 , V_6 ) ;
F_49 ( V_3 ) ;
V_103:
F_62 ( V_3 ) ;
return V_97 ;
}
static int
F_77 ( struct V_104 * V_105 , struct V_1 * V_6 , T_1 V_106 ,
T_1 V_107 )
{
T_1 V_108 = 0 , V_26 = V_109 ;
T_1 V_110 = ( ( - V_107 ) & 3 ) ;
struct V_111 * V_112 ;
struct V_113 * V_113 ;
unsigned int V_114 ;
if ( V_110 )
V_26 -- ;
V_112 = & V_105 -> V_115 . V_116 [ V_106 / V_117 ] ;
V_114 = ( V_106 % V_117 ) ;
while ( V_107 && ( V_108 < V_26 ) ) {
T_1 V_118 = F_78 ( T_1 , V_107 , V_112 -> V_20 - V_114 ) ;
V_113 = F_79 ( V_112 ) ;
F_80 ( V_113 ) ;
F_81 ( V_6 , V_108 , V_113 , V_112 -> V_119 + V_114 ,
V_118 ) ;
V_6 -> V_13 += V_118 ;
V_6 -> V_4 += V_118 ;
V_6 -> V_120 += V_118 ;
V_107 -= V_118 ;
V_114 = 0 ;
V_112 = F_82 ( V_112 ) ;
V_108 ++ ;
}
if ( V_107 )
return - 1 ;
if ( V_110 ) {
V_113 = F_83 ( V_12 | V_121 ) ;
if ( ! V_113 )
return - 1 ;
F_81 ( V_6 , V_108 , V_113 , 0 , V_110 ) ;
V_6 -> V_13 += V_110 ;
V_6 -> V_4 += V_110 ;
V_6 -> V_120 += V_110 ;
}
return 0 ;
}
static int
F_84 ( struct V_2 * V_3 , struct V_104 * V_105 ,
struct V_122 * V_123 )
{
struct V_124 * V_125 = V_3 -> V_125 ;
struct V_1 * V_6 ;
struct V_126 V_127 ;
struct V_27 V_28 ;
T_1 V_107 = V_105 -> V_115 . V_107 ;
T_1 V_128 = V_125 -> V_129 -> V_130 ;
T_1 V_131 , V_65 , V_132 = 0 ;
bool V_133 = ! ! ( V_105 -> V_115 . V_134 &
V_135 ) ;
bool V_136 = false ;
int V_97 = - 1 ;
while ( V_107 ) {
V_131 = ( V_107 + V_128 - 1 ) / V_128 ;
if ( V_131 > V_3 -> V_137 )
V_131 = V_3 -> V_137 ;
V_65 = V_131 * V_128 ;
if ( V_65 > V_107 )
V_65 = V_107 ;
V_6 = F_1 ( V_3 , 0 , true ) ;
if ( F_71 ( ! V_6 ) )
return - V_138 ;
memset ( V_6 -> V_88 , 0 , V_11 ) ;
F_9 ( V_6 ) |= V_22 ;
F_7 ( V_6 ) |= ( V_3 -> V_7 &
V_14 ) ;
F_8 ( V_6 ) = ( V_131 *
V_18 [ F_7 ( V_6 ) ] ) +
( ( V_131 - 1 ) * V_11 ) ;
memset ( & V_127 , 0 , sizeof( struct V_126 ) ) ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
if ( ! V_132 )
V_28 . V_31 |= V_32 ;
if ( ! ( V_107 - V_65 ) ) {
V_28 . V_31 |= V_34 ;
if ( ! V_133 ) {
V_127 . V_31 = V_139 ;
F_85 ( V_105 , V_125 -> V_140 ) ;
V_105 -> V_141 = V_125 -> V_141 ++ ;
V_136 = true ;
}
}
V_28 . V_40 = V_131 * V_128 ;
V_28 . V_38 = V_128 ;
V_28 . V_4 = V_11 + V_65 ;
F_21 ( V_6 , & V_28 ) ;
V_127 . V_119 = V_132 ;
V_127 . V_142 = V_105 -> V_142 - 1 ;
F_86 ( V_105 , V_125 , & V_127 ,
(struct V_143 * ) V_6 -> V_88 ,
V_136 ) ;
V_97 = F_77 ( V_105 , V_6 , V_132 , V_65 ) ;
if ( F_71 ( V_97 ) ) {
F_73 ( V_6 ) ;
goto V_144;
}
V_97 = F_69 ( V_3 , V_6 ) ;
if ( F_71 ( V_97 ) )
goto V_144;
V_132 += V_65 ;
V_107 -= V_65 ;
V_105 -> V_145 += V_65 ;
V_105 -> V_142 += V_131 ;
}
V_123 -> V_146 = V_147 ;
return 0 ;
V_144:
return V_97 ;
}
static int
F_87 ( struct V_2 * V_3 , struct V_104 * V_105 ,
const struct V_126 * V_127 )
{
struct V_1 * V_6 ;
int V_97 = 0 ;
V_6 = F_10 ( V_3 , 0 ) ;
if ( F_71 ( ! V_6 ) )
return - V_138 ;
memcpy ( V_6 -> V_88 , V_105 -> V_148 , V_11 ) ;
if ( V_127 -> V_20 ) {
F_7 ( V_6 ) |= ( V_3 -> V_7 &
V_14 ) ;
F_8 ( V_6 ) =
V_18 [ F_7 ( V_6 ) ] ;
}
V_97 = F_77 ( V_105 , V_6 , V_127 -> V_119 , V_127 -> V_20 ) ;
if ( V_97 < 0 ) {
F_73 ( V_6 ) ;
return V_97 ;
}
return F_69 ( V_3 , V_6 ) ;
}
static int
F_88 ( struct V_124 * V_125 , struct V_104 * V_105 ,
struct V_122 * V_123 ,
const struct V_126 * V_127 )
{
struct V_2 * V_3 = V_125 -> V_149 ;
T_1 V_107 = V_105 -> V_115 . V_107 ;
T_1 V_110 = ( ( - V_107 ) & 3 ) ;
T_1 V_128 = V_125 -> V_129 -> V_130 ;
if ( ( V_107 > V_128 ) && ( ! V_123 -> V_150 ) &&
( ! V_110 ) && ( ! V_127 -> V_119 ) && V_3 -> V_137 ) {
F_89 ( V_107 - V_127 -> V_20 ,
& V_125 -> V_140 -> V_151 ) ;
return F_84 ( V_3 , V_105 , V_123 ) ;
}
return F_87 ( V_3 , V_105 , V_127 ) ;
}
static int
F_90 ( struct V_124 * V_125 , struct V_104 * V_105 ,
const void * V_152 , T_1 V_153 )
{
struct V_2 * V_3 = V_125 -> V_149 ;
struct V_1 * V_6 ;
T_1 V_110 = ( ( - V_153 ) & 3 ) ;
V_6 = F_10 ( V_3 , V_153 + V_110 ) ;
if ( F_71 ( ! V_6 ) )
return - V_138 ;
memcpy ( V_6 -> V_88 , V_105 -> V_148 , V_11 ) ;
if ( V_153 ) {
T_1 V_154 = 0 ;
F_91 ( V_6 , V_11 , V_152 , V_153 ) ;
if ( V_110 )
F_91 ( V_6 , V_11 + V_153 ,
& V_154 , V_110 ) ;
}
F_8 ( V_6 ) = V_18 [
F_7 ( V_6 ) ] ;
return F_69 ( V_3 , V_6 ) ;
}
int
F_92 ( struct V_124 * V_125 , struct V_104 * V_105 ,
struct V_122 * V_123 , const void * V_155 , T_1 V_156 )
{
if ( V_123 )
return F_88 ( V_125 , V_105 , V_123 , V_155 ) ;
else
return F_90 ( V_125 , V_105 , V_155 , V_156 ) ;
}
int F_93 ( struct V_124 * V_125 )
{
struct V_2 * V_3 = V_125 -> V_149 ;
struct V_157 * V_52 = V_3 -> V_51 . V_52 ;
struct V_158 * V_159 ;
T_1 V_160 ;
V_159 = F_94 ( V_161 ,
V_125 -> V_162 ) ;
if ( ! V_159 )
return - 1 ;
if ( F_95 ( V_159 -> V_163 , 0 , & V_160 ) < 0 )
return - 1 ;
if ( V_160 > V_52 -> V_164 ) {
if ( F_96 (
V_125 , L_4 , V_52 -> V_164 ) )
return - 1 ;
}
return 0 ;
}
static int F_97 ( struct V_2 * V_3 )
{
struct V_124 * V_125 = V_3 -> V_125 ;
struct V_158 * V_159 ;
V_159 = F_94 ( V_165 , V_125 -> V_162 ) ;
if ( ! V_159 ) {
F_98 ( L_5 , V_165 ) ;
return - 1 ;
}
if ( ! strcmp ( V_159 -> V_163 , V_166 ) )
V_3 -> V_7 |= V_17 ;
V_159 = F_94 ( V_167 , V_125 -> V_162 ) ;
if ( ! V_159 ) {
V_3 -> V_7 = 0 ;
F_98 ( L_5 , V_167 ) ;
return - 1 ;
}
if ( ! strcmp ( V_159 -> V_163 , V_166 ) )
V_3 -> V_7 |= V_14 ;
if ( F_99 ( V_3 ) ) {
V_3 -> V_7 = 0 ;
return - 1 ;
}
return 0 ;
}
static int F_100 ( struct V_2 * V_3 )
{
struct V_124 * V_125 = V_3 -> V_125 ;
struct V_168 * V_129 = V_125 -> V_129 ;
struct V_158 * V_159 ;
T_1 V_128 , V_169 ;
T_1 V_170 , V_137 ;
if ( V_125 -> V_171 -> V_172 ) {
V_159 = F_94 ( V_173 ,
V_125 -> V_162 ) ;
if ( ! V_159 ) {
F_98 ( L_5 , V_173 ) ;
return - 1 ;
}
if ( F_95 ( V_159 -> V_163 , 0 , & V_169 ) < 0 )
return - 1 ;
} else {
V_169 = V_125 -> V_140 -> V_174 -> V_175 ;
}
V_128 = V_129 -> V_130 ;
V_170 = V_169 / V_128 ;
V_137 = V_176 /
( V_11 + V_128 +
V_18 [ V_3 -> V_7 ] ) ;
V_3 -> V_137 = F_101 ( V_170 , V_137 ) ;
if ( V_3 -> V_137 <= 1 )
V_3 -> V_137 = 0 ;
return 0 ;
}
static int F_102 ( struct V_2 * V_3 )
{
struct V_124 * V_125 = V_3 -> V_125 ;
struct V_158 * V_159 ;
if ( V_125 -> V_171 -> V_172 ) {
V_159 = F_94 ( V_177 ,
V_125 -> V_162 ) ;
if ( ! V_159 ) {
F_98 ( L_5 , V_177 ) ;
return - 1 ;
}
if ( strcmp ( V_159 -> V_163 , V_178 ) )
return 1 ;
V_159 = F_94 ( V_179 ,
V_125 -> V_162 ) ;
if ( ! V_159 ) {
F_98 ( L_5 , V_179 ) ;
return - 1 ;
}
if ( strcmp ( V_159 -> V_163 , V_178 ) )
return 1 ;
} else {
if ( ! V_125 -> V_140 -> V_174 -> V_180 )
return 1 ;
if ( ! V_125 -> V_140 -> V_174 -> V_181 )
return 1 ;
}
return 0 ;
}
static int F_103 ( struct V_124 * V_125 )
{
struct V_2 * V_3 = V_125 -> V_149 ;
struct V_157 * V_52 = V_3 -> V_51 . V_52 ;
struct V_182 * V_183 = * V_3 -> V_51 . V_52 -> V_50 . V_184 ;
struct V_168 * V_129 = V_125 -> V_129 ;
struct V_158 * V_159 ;
T_2 V_185 ;
if ( V_129 -> V_130 > V_52 -> V_164 )
V_129 -> V_130 = V_52 -> V_164 ;
if ( V_125 -> V_171 -> V_172 ) {
V_159 = F_94 ( V_186 ,
V_125 -> V_162 ) ;
if ( ! V_159 ) {
F_98 ( L_5 , V_186 ) ;
return - 1 ;
}
if ( F_104 ( V_159 -> V_163 , 0 , & V_185 ) < 0 )
return - 1 ;
} else {
V_185 = V_125 -> V_140 -> V_174 -> V_187 ;
}
if ( ! V_185 ) {
int V_97 ;
V_97 = F_102 ( V_3 ) ;
if ( V_97 < 0 ) {
return - 1 ;
} else if ( V_97 > 0 ) {
if ( F_35 ( V_52 -> V_50 . V_59 ) )
goto V_188;
else
goto V_189;
}
if ( F_105 ( V_190 , & V_52 -> V_31 ) ) {
if ( F_100 ( V_3 ) )
return - 1 ;
}
V_188:
if ( F_105 ( V_191 , & V_52 -> V_31 ) ) {
if ( F_106 ( V_3 ,
V_183 -> V_192 . V_193 ) )
return - 1 ;
F_107 ( V_194 , & V_3 -> V_51 . V_31 ) ;
}
}
V_189:
if ( F_97 ( V_3 ) )
return - 1 ;
return 0 ;
}
int
F_108 ( struct V_124 * V_125 , struct V_195 * V_171 ,
T_1 V_20 )
{
struct V_2 * V_3 = V_125 -> V_149 ;
struct V_1 * V_6 ;
T_1 V_196 = 0 ;
T_2 V_110 = ( ( - V_20 ) & 3 ) ;
V_6 = F_10 ( V_3 , V_20 + V_110 ) ;
if ( ! V_6 )
return - V_138 ;
F_91 ( V_6 , 0 , V_171 -> V_197 , V_11 ) ;
F_91 ( V_6 , V_11 , V_171 -> V_198 , V_20 ) ;
if ( V_110 )
F_91 ( V_6 , V_11 + V_20 ,
& V_196 , V_110 ) ;
if ( V_171 -> V_199 ) {
if ( F_103 ( V_125 ) ) {
F_48 ( V_6 ) ;
return - 1 ;
}
F_107 ( V_200 , & V_3 -> V_51 . V_31 ) ;
}
if ( F_69 ( V_3 , V_6 ) )
return - 1 ;
if ( ( ! V_171 -> V_199 ) && ( ! V_171 -> V_201 ) )
F_109 ( & V_125 -> V_202 , 0 ) ;
return 0 ;
}
static void
F_110 ( struct V_1 * V_6 , struct V_111 * V_112 ,
unsigned int V_203 )
{
struct V_204 V_205 ;
const T_2 * V_155 ;
unsigned int V_206 = 0 , V_156 ;
struct V_207 * V_208 = F_111 ( V_6 ) ;
F_112 ( V_6 , V_208 -> V_209 ,
V_208 -> V_209 + V_208 -> V_45 ,
& V_205 ) ;
while ( true ) {
V_156 = F_113 ( V_206 , & V_155 , & V_205 ) ;
if ( ! V_156 ) {
F_114 ( & V_205 ) ;
break;
}
V_206 += F_115 ( V_112 , V_203 , ( void * ) V_155 ,
V_156 , V_206 ) ;
}
}
static struct V_104 * F_116 ( struct V_2 * V_3 )
{
struct V_124 * V_125 = V_3 -> V_125 ;
struct V_182 * V_183 = F_117 ( V_3 -> V_51 . V_52 ) ;
struct V_210 * V_211 ;
struct V_104 * V_105 ;
V_105 = F_118 ( V_125 , V_212 ) ;
if ( ! V_105 ) {
F_98 ( L_6 ) ;
return NULL ;
}
V_211 = F_119 ( V_105 ) ;
V_211 -> V_213 . V_214 = V_183 -> V_192 . V_215 ;
V_211 -> V_216 = true ;
return V_105 ;
}
static int
F_120 ( struct V_104 * V_105 , struct V_217 * V_218 ,
T_1 V_20 )
{
struct V_124 * V_125 = V_105 -> V_125 ;
struct V_2 * V_3 = V_125 -> V_149 ;
struct V_207 * V_208 = F_111 ( V_3 -> V_6 ) ;
if ( V_208 -> V_31 & V_219 ) {
F_98 ( L_7 ) ;
if ( ! V_125 -> V_140 -> V_174 -> V_187 ) {
F_98 ( L_8
L_9
L_10 ) ;
F_121 ( V_105 , V_220 ,
( unsigned char * ) V_218 ) ;
return V_221 ;
}
F_121 ( V_105 , V_220 ,
( unsigned char * ) V_218 ) ;
return V_222 ;
}
if ( V_105 -> V_115 . V_134 & V_223 ) {
struct V_210 * V_211 = F_119 ( V_105 ) ;
struct V_224 * V_225 = F_18 ( V_3 -> V_6 ) ;
T_3 * V_226 = & V_225 -> V_227 [ V_208 -> V_228 ] ;
F_122 ( & V_211 -> V_112 , 1 ) ;
F_123 ( & V_211 -> V_112 , V_226 -> V_113 . V_229 , F_124 ( V_226 ) ,
V_226 -> V_230 ) ;
F_80 ( V_226 -> V_113 . V_229 ) ;
V_105 -> V_115 . V_116 = & V_211 -> V_112 ;
V_105 -> V_115 . V_231 = 1 ;
V_211 -> V_232 = true ;
} else {
struct V_111 * V_112 = & V_105 -> V_115 . V_116 [ 0 ] ;
T_1 V_233 = F_125 ( 1UL , F_16 ( V_208 -> V_45 , V_117 ) ) ;
F_110 ( V_3 -> V_6 , V_112 , V_233 ) ;
}
V_105 -> V_234 += V_208 -> V_45 ;
if ( V_105 -> V_234 == V_105 -> V_115 . V_107 ) {
F_60 ( & V_105 -> V_235 ) ;
V_105 -> V_236 |= V_237 ;
V_105 -> V_238 = V_239 ;
F_61 ( & V_105 -> V_235 ) ;
}
return V_240 ;
}
static int
F_126 ( struct V_104 * V_105 , struct V_217 * V_218 ,
bool V_241 )
{
struct V_124 * V_125 = V_105 -> V_125 ;
int V_242 = 0 , V_243 = V_240 ;
if ( V_241 )
goto V_244;
V_243 = F_120 ( V_105 , V_218 ,
V_105 -> V_245 ) ;
V_244:
if ( V_243 == V_240 ) {
V_242 = F_127 ( V_125 , V_105 ,
( unsigned char * ) V_218 ,
V_218 -> V_246 ) ;
if ( V_242 == V_247 )
return - 1 ;
if ( V_105 -> V_248 || V_242 == V_249 ) {
F_128 ( & V_105 -> V_115 ) ;
return 0 ;
} else if ( V_105 -> V_250 ) {
F_129 ( V_105 ) ;
}
} else if ( V_243 == V_222 ) {
V_105 -> V_238 = V_251 ;
F_130 ( V_105 , V_125 , V_105 -> V_238 ) ;
} else
return - 1 ;
return 0 ;
}
static int
F_131 ( struct V_2 * V_3 , struct V_104 * V_105 )
{
struct V_124 * V_125 = V_3 -> V_125 ;
struct V_207 * V_208 = F_111 ( V_3 -> V_6 ) ;
struct V_217 * V_218 = (struct V_217 * ) V_208 -> V_218 ;
int V_252 ;
bool V_241 = false ;
V_252 = F_132 ( V_125 , V_105 , ( unsigned char * ) V_218 ) ;
if ( V_252 < 0 )
return V_252 ;
if ( V_208 -> V_45 && ( V_208 -> V_45 == V_105 -> V_115 . V_107 ) &&
( V_208 -> V_253 == 1 ) )
V_105 -> V_115 . V_134 |= V_223 ;
V_252 = F_133 ( V_125 , V_105 , V_218 ) ;
if ( V_252 < 0 )
return 0 ;
else if ( V_252 > 0 )
V_241 = true ;
if ( ! V_208 -> V_45 )
return 0 ;
return F_126 ( V_105 , V_218 , V_241 ) ;
}
static int F_134 ( struct V_2 * V_3 )
{
struct V_111 * V_254 ;
struct V_124 * V_125 = V_3 -> V_125 ;
struct V_104 * V_105 = NULL ;
struct V_207 * V_208 = F_111 ( V_3 -> V_6 ) ;
struct V_255 * V_218 = (struct V_255 * ) V_208 -> V_218 ;
T_1 V_106 = F_135 ( V_218 -> V_119 ) ;
T_1 V_13 = V_208 -> V_45 ;
int V_252 , V_233 , V_256 ;
bool V_257 = false ;
if ( V_208 -> V_31 & V_258 ) {
T_1 V_119 = F_135 ( V_218 -> V_119 ) ;
T_1 V_259 ;
T_1 V_260 = F_136 ( V_218 -> V_261 ) ;
bool V_262 = false ;
V_105 = F_137 ( V_125 , V_218 -> V_263 , 0 ) ;
if ( ! V_105 )
return 0 ;
V_259 = V_119 - V_105 -> V_234 ;
F_89 ( V_259 , & V_125 -> V_140 -> V_264 ) ;
V_105 -> V_234 = V_119 ;
V_105 -> V_265 = V_259 ;
V_105 -> V_142 = F_135 ( V_218 -> V_266 ) ;
V_252 = F_138 ( V_125 , ( unsigned char * ) V_218 ,
V_105 , V_260 , & V_262 ) ;
if ( V_252 < 0 )
return V_252 ;
else if ( ! V_262 )
return 0 ;
} else {
V_252 = F_139 ( V_125 , ( unsigned char * ) V_218 , & V_105 ) ;
if ( V_252 < 0 )
return V_252 ;
else if ( ! V_105 )
return 0 ;
}
if ( V_208 -> V_31 & V_219 ) {
F_98 ( L_11
L_12 ,
V_218 -> V_263 , V_218 -> V_119 , V_13 ,
V_218 -> V_266 ) ;
V_257 = true ;
goto V_267;
}
F_52 ( L_13
L_14 ,
V_13 , V_105 -> V_234 ,
V_105 -> V_115 . V_107 ) ;
if ( ! ( V_208 -> V_31 & V_268 ) ) {
V_256 = V_106 / V_117 ;
V_254 = & V_105 -> V_115 . V_116 [ V_256 ] ;
V_233 = F_125 ( 1UL , F_16 ( V_13 , V_117 ) ) ;
F_110 ( V_3 -> V_6 , V_254 , V_233 ) ;
}
V_267:
V_252 = F_140 ( V_105 , V_218 , V_257 ) ;
if ( V_252 < 0 )
return V_252 ;
return 0 ;
}
static int F_141 ( struct V_2 * V_3 , struct V_104 * V_105 )
{
struct V_124 * V_125 = V_3 -> V_125 ;
struct V_207 * V_208 = F_111 ( V_3 -> V_6 ) ;
struct V_269 * V_218 = (struct V_269 * ) V_208 -> V_218 ;
unsigned char * V_270 = NULL ;
T_1 V_260 = V_208 -> V_45 ;
int V_97 ;
V_97 = F_142 ( V_125 , V_105 , V_218 ) ;
if ( V_97 < 0 )
return 0 ;
if ( V_208 -> V_31 & V_219 ) {
if ( ! V_125 -> V_140 -> V_174 -> V_187 ) {
F_98 ( L_8
L_15
L_16 ) ;
V_97 = - 1 ;
goto V_144;
} else {
F_143 ( L_17
L_18
L_19 , V_218 -> V_246 ) ;
V_97 = 0 ;
goto V_144;
}
}
if ( V_260 && V_218 -> V_271 == F_37 ( 0xFFFFFFFF ) ) {
V_270 = F_144 ( V_260 + 1 , V_12 ) ;
if ( ! V_270 ) {
F_98 ( L_20
L_21 ) ;
V_97 = - 1 ;
goto V_144;
}
F_145 ( V_3 -> V_6 , V_208 -> V_209 ,
V_270 , V_260 ) ;
V_270 [ V_260 ] = '\0' ;
V_105 -> V_272 = V_270 ;
V_105 -> V_273 = V_260 ;
F_52 ( L_22
L_23 , V_260 ) ;
F_52 ( L_24 , V_270 ) ;
}
return F_146 ( V_125 , V_105 , V_218 ) ;
V_144:
if ( V_105 )
F_147 ( V_105 , false ) ;
return V_97 ;
}
static int
F_148 ( struct V_2 * V_3 , struct V_104 * V_105 )
{
struct V_124 * V_125 = V_3 -> V_125 ;
struct V_207 * V_208 = F_111 ( V_3 -> V_6 ) ;
struct V_274 * V_218 = (struct V_274 * ) V_208 -> V_218 ;
T_1 V_260 = V_208 -> V_45 ;
int V_252 ;
unsigned char * V_275 = NULL ;
V_252 = F_149 ( V_125 , V_105 , V_218 ) ;
if ( V_252 < 0 )
return V_252 ;
if ( V_208 -> V_31 & V_219 ) {
if ( ! V_125 -> V_140 -> V_174 -> V_187 ) {
F_98 ( L_8
L_25
L_16 ) ;
goto V_276;
} else {
F_143 ( L_26
L_18
L_19 , V_218 -> V_246 ) ;
return 0 ;
}
}
if ( V_260 ) {
V_275 = F_144 ( V_260 , V_12 ) ;
if ( ! V_275 ) {
F_98 ( L_27 ,
V_260 ) ;
return - V_138 ;
}
F_145 ( V_3 -> V_6 , V_208 -> V_209 ,
V_275 , V_260 ) ;
V_275 [ V_260 - 1 ] = '\0' ;
V_105 -> V_277 = V_275 ;
}
return F_150 ( V_125 , V_105 , V_218 ) ;
V_276:
return F_121 ( V_105 , V_278 ,
V_208 -> V_218 ) ;
}
static int F_151 ( struct V_2 * V_3 )
{
struct V_207 * V_208 = F_111 ( V_3 -> V_6 ) ;
struct V_279 * V_218 = (struct V_279 * ) V_208 -> V_218 ;
struct V_124 * V_125 = V_3 -> V_125 ;
struct V_104 * V_105 = NULL ;
T_2 V_55 = ( V_218 -> V_55 & V_280 ) ;
int V_97 = - V_281 ;
switch ( V_55 ) {
case V_282 :
V_105 = F_116 ( V_3 ) ;
if ( ! V_105 )
goto V_276;
V_97 = F_131 ( V_3 , V_105 ) ;
break;
case V_283 :
V_97 = F_134 ( V_3 ) ;
break;
case V_284 :
if ( V_218 -> V_271 == F_37 ( 0xFFFFFFFF ) ) {
V_105 = F_116 ( V_3 ) ;
if ( ! V_105 )
goto V_276;
}
V_97 = F_141 ( V_3 , V_105 ) ;
break;
case V_285 :
V_105 = F_116 ( V_3 ) ;
if ( ! V_105 )
goto V_276;
V_97 = F_152 ( V_125 , V_105 ,
( unsigned char * ) V_218 ) ;
break;
case V_286 :
if ( V_218 -> V_271 != F_37 ( 0xFFFFFFFF ) ) {
V_105 = F_153 ( V_125 , V_218 -> V_263 ) ;
if ( ! V_105 )
goto V_276;
} else {
V_105 = F_116 ( V_3 ) ;
if ( ! V_105 )
goto V_276;
}
V_97 = F_148 ( V_3 , V_105 ) ;
break;
case V_287 :
V_105 = F_116 ( V_3 ) ;
if ( ! V_105 )
goto V_276;
V_97 = F_154 ( V_125 , V_105 , ( unsigned char * ) V_218 ) ;
if ( V_97 > 0 )
F_155 ( & V_125 -> V_288 ,
V_289
* V_290 ) ;
break;
case V_291 :
V_97 = F_156 ( V_125 , ( unsigned char * ) V_218 ) ;
break;
default:
F_98 ( L_28 , V_55 ) ;
F_157 () ;
break;
}
return V_97 ;
V_276:
return F_158 ( V_125 , V_292 ,
( unsigned char * ) V_218 ) ;
return V_97 ;
}
static int F_159 ( struct V_2 * V_3 )
{
struct V_207 * V_208 = F_111 ( V_3 -> V_6 ) ;
struct V_124 * V_125 = V_3 -> V_125 ;
struct V_279 * V_218 = V_208 -> V_218 ;
T_2 V_55 ;
if ( V_208 -> V_31 & V_293 ) {
F_160 ( & V_125 -> V_140 -> V_294 ) ;
goto V_295;
}
if ( V_125 -> V_296 == V_297 )
goto V_295;
V_55 = V_218 -> V_55 & V_280 ;
if ( V_125 -> V_140 -> V_174 -> V_298 &&
( ( ! ( V_55 & V_286 ) ) ||
( ! ( V_55 & V_287 ) ) ) ) {
F_98 ( L_29
L_30 , V_55 ) ;
F_158 ( V_125 , V_278 ,
( unsigned char * ) V_218 ) ;
goto V_295;
}
if ( F_151 ( V_3 ) < 0 )
goto V_295;
return 0 ;
V_295:
return - 1 ;
}
static int F_161 ( struct V_2 * V_3 )
{
struct V_124 * V_125 = V_3 -> V_125 ;
struct V_195 * V_171 = V_125 -> V_171 ;
struct V_207 * V_208 = F_111 ( V_3 -> V_6 ) ;
struct V_299 * V_300 ;
V_300 = (struct V_299 * ) V_171 -> V_48 ;
memcpy ( V_300 , V_208 -> V_218 , sizeof( * V_300 ) ) ;
F_52 ( L_31
L_32 ,
V_300 -> V_31 , V_300 -> V_263 , V_300 -> V_246 ,
V_300 -> V_301 , V_300 -> V_302 , V_208 -> V_45 ) ;
if ( V_171 -> V_303 ) {
V_300 = (struct V_299 * ) V_171 -> V_48 ;
V_171 -> V_172 = ( ! V_300 -> V_304 ) ? 1 : 0 ;
V_171 -> V_305 = F_162 (
V_300 -> V_31 ) ;
V_171 -> V_306 = V_300 -> V_307 ;
V_171 -> V_308 = V_300 -> V_309 ;
memcpy ( V_171 -> V_310 , V_300 -> V_310 , 6 ) ;
V_171 -> V_311 = F_135 ( V_300 -> V_246 ) ;
V_171 -> V_312 = V_300 -> V_263 ;
V_171 -> V_313 = F_135 ( V_300 -> V_301 ) ;
V_171 -> V_302 = F_163 ( V_300 -> V_302 ) ;
V_171 -> V_304 = F_163 ( V_300 -> V_304 ) ;
}
if ( F_164 ( V_125 , V_171 ) < 0 )
return - 1 ;
memset ( V_171 -> V_314 , 0 , V_315 ) ;
F_145 ( V_3 -> V_6 , V_208 -> V_209 , V_171 -> V_314 , V_208 -> V_45 ) ;
return 0 ;
}
static int
F_165 ( struct V_2 * V_3 , struct V_1 * V_6 , int V_316 )
{
struct V_207 * V_208 = F_166 ( V_6 , V_316 ) ;
int V_97 ;
F_111 ( V_6 ) = V_208 ;
V_3 -> V_6 = V_6 ;
if ( ! F_105 ( V_200 , & V_3 -> V_51 . V_31 ) ) {
V_97 = F_161 ( V_3 ) ;
F_107 ( V_317 , & V_3 -> V_51 . V_31 ) ;
} else {
V_97 = F_159 ( V_3 ) ;
}
return V_97 ;
}
static void F_167 ( struct V_1 * V_6 )
{
struct V_224 * V_225 = F_18 ( V_6 ) ;
struct V_318 * V_319 = F_168 ( V_6 ) ;
struct V_207 * V_208 = F_166 ( V_6 , 0 ) ;
T_2 V_108 ;
F_143 ( L_33 ,
V_6 , V_6 -> V_320 , V_6 -> V_88 , V_6 -> V_4 , V_6 -> V_13 ,
V_225 -> V_26 ) ;
F_143 ( L_34 ,
V_6 , V_319 -> V_3 , V_319 -> V_321 , V_319 -> V_322 ) ;
for ( V_108 = 0 ; V_108 < V_319 -> V_321 ; V_108 ++ , V_208 ++ )
F_143 ( L_35
L_36 ,
V_6 , V_108 , V_208 -> V_323 , V_208 -> V_31 , V_208 -> V_324 ,
V_208 -> V_325 , V_208 -> V_227 ) ;
for ( V_108 = 0 ; V_108 < V_225 -> V_26 ; V_108 ++ )
F_143 ( L_37 ,
V_6 , V_108 , V_225 -> V_227 [ V_108 ] . V_230 , V_225 -> V_227 [ V_108 ] . V_326 ) ;
}
static void F_169 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = V_3 -> V_327 ;
struct V_224 * V_225 = F_18 ( V_6 ) ;
T_2 V_108 ;
memset ( V_6 -> V_88 , 0 , V_328 ) ;
for ( V_108 = 0 ; V_108 < V_225 -> V_26 ; V_108 ++ )
F_170 ( F_171 ( & V_225 -> V_227 [ V_108 ] ) ) ;
V_225 -> V_26 = 0 ;
V_6 -> V_13 = 0 ;
V_6 -> V_120 -= V_6 -> V_4 ;
V_6 -> V_4 = 0 ;
}
static void
F_172 ( struct V_2 * V_3 , struct V_1 * V_6 , T_2 V_321 )
{
struct V_1 * V_329 = V_3 -> V_327 ;
struct V_207 * V_330 = F_166 ( V_329 , 0 ) ;
struct V_207 * V_208 = F_166 ( V_6 , V_321 ) ;
struct V_224 * V_331 = F_18 ( V_329 ) ;
struct V_224 * V_225 = F_18 ( V_6 ) ;
unsigned int V_4 = 0 ;
if ( V_208 -> V_31 & V_332 ) {
T_2 V_333 = V_331 -> V_26 ;
V_330 -> V_31 |= V_208 -> V_31 ;
V_330 -> V_324 = V_208 -> V_324 ;
V_330 -> V_218 = V_208 -> V_218 ;
V_330 -> V_334 = V_208 -> V_334 ;
memcpy ( & V_331 -> V_227 [ V_333 ] , & V_225 -> V_227 [ V_208 -> V_333 ] ,
sizeof( T_3 ) ) ;
F_80 ( F_171 ( & V_331 -> V_227 [ V_333 ] ) ) ;
V_331 -> V_26 ++ ;
V_330 -> V_227 ++ ;
V_330 -> V_333 = V_333 ;
V_4 = V_331 -> V_227 [ V_333 ] . V_326 ;
V_329 -> V_4 += V_4 ;
V_329 -> V_13 += V_4 ;
V_329 -> V_120 += V_4 ;
}
if ( V_208 -> V_31 & V_335 ) {
T_2 V_228 = V_331 -> V_26 , V_108 ;
V_330 -> V_31 |= V_208 -> V_31 ;
V_330 -> V_228 = V_228 ;
V_4 = 0 ;
for ( V_108 = 0 ; V_108 < V_208 -> V_253 ; V_228 ++ , V_108 ++ ) {
memcpy ( & V_331 -> V_227 [ V_228 ] ,
& V_225 -> V_227 [ V_208 -> V_228 + V_108 ] ,
sizeof( T_3 ) ) ;
F_80 ( F_171 ( & V_331 -> V_227 [ V_228 ] ) ) ;
V_4 += V_331 -> V_227 [ V_228 ] . V_326 ;
V_331 -> V_26 ++ ;
V_330 -> V_227 ++ ;
}
V_330 -> V_45 = V_208 -> V_45 ;
V_330 -> V_209 = V_330 -> V_334 ;
V_330 -> V_253 = V_208 -> V_253 ;
V_329 -> V_4 += V_4 ;
V_329 -> V_13 += V_4 ;
V_329 -> V_120 += V_4 ;
}
if ( V_208 -> V_31 & V_336 ) {
V_330 -> V_31 |= V_208 -> V_31 ;
if ( V_330 -> V_31 & V_335 )
V_330 -> V_31 &= ~ V_268 ;
V_330 -> V_325 = V_208 -> V_325 ;
V_330 -> V_323 = V_208 -> V_323 ;
}
}
static int F_173 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
struct V_318 * V_319 = F_168 ( V_6 ) ;
struct V_207 * V_208 = F_166 ( V_6 , 0 ) ;
T_2 V_321 = 0 , V_337 = 0 ;
int V_97 = 0 ;
if ( ! V_208 -> V_338 ) {
F_172 ( V_3 , V_6 , 0 ) ;
if ( V_208 -> V_31 & V_336 ) {
struct V_1 * V_329 = V_3 -> V_327 ;
V_97 = F_165 ( V_3 , V_329 , 0 ) ;
F_169 ( V_3 ) ;
if ( V_97 < 0 )
goto V_144;
}
V_321 = 1 ;
}
if ( V_319 -> V_321 )
V_337 = V_319 -> V_321 - 1 ;
for (; V_321 <= V_337 ; V_321 ++ ) {
V_97 = F_165 ( V_3 , V_6 , V_321 ) ;
if ( V_97 < 0 )
goto V_144;
}
if ( ( ! V_319 -> V_338 ) && V_319 -> V_321 )
F_172 ( V_3 , V_6 , V_319 -> V_321 ) ;
V_144:
return V_97 ;
}
static int F_174 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
struct V_318 * V_319 = F_168 ( V_6 ) ;
struct V_207 * V_208 = F_166 ( V_6 , 0 ) ;
int V_97 = - 1 ;
if ( ( V_208 -> V_31 & V_332 ) &&
( V_208 -> V_324 != V_3 -> V_339 ) ) {
F_143 ( L_38 ,
V_3 , V_3 -> V_64 , V_208 -> V_324 , V_3 -> V_339 ) ;
F_167 ( V_6 ) ;
return V_97 ;
}
V_3 -> V_339 += V_319 -> V_322 ;
V_97 = F_173 ( V_3 , V_6 ) ;
V_3 -> V_340 += V_319 -> V_322 ;
if ( V_3 -> V_340 >= ( V_3 -> V_341 / 4 ) )
F_175 ( V_3 ) ;
return V_97 ;
}
static int F_176 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
struct V_49 * V_50 = & V_3 -> V_51 . V_52 -> V_50 ;
int V_97 = - 1 ;
if ( F_12 ( F_9 ( V_6 ) & V_342 ) ) {
if ( F_35 ( V_50 -> V_59 ) )
V_97 = F_174 ( V_3 , V_6 ) ;
else
V_97 = F_173 ( V_3 , V_6 ) ;
}
F_73 ( V_6 ) ;
return V_97 ;
}
static bool F_177 ( struct V_2 * V_3 , struct V_95 * V_343 )
{
F_60 ( & V_3 -> V_343 . V_93 ) ;
if ( F_65 ( & V_3 -> V_343 ) ) {
F_66 ( & V_3 -> V_343 , V_343 ) ;
F_61 ( & V_3 -> V_343 . V_93 ) ;
return true ;
}
F_61 ( & V_3 -> V_343 . V_93 ) ;
return false ;
}
static int F_178 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
struct V_95 V_343 ;
F_64 ( & V_343 ) ;
F_70 ( V_3 -> V_344 , F_177 ( V_3 , & V_343 ) ) ;
if ( F_72 ( V_101 ) )
goto V_144;
while ( ( V_6 = F_67 ( & V_343 ) ) ) {
if ( F_176 ( V_3 , V_6 ) )
goto V_144;
}
return 0 ;
V_144:
F_74 ( & V_343 ) ;
return - 1 ;
}
int F_179 ( struct V_124 * V_125 , struct V_195 * V_171 )
{
struct V_2 * V_3 = V_125 -> V_149 ;
int V_97 = - 1 ;
while ( ! F_180 ( V_317 , & V_3 -> V_51 . V_31 ) ) {
V_97 = F_178 ( V_3 ) ;
if ( V_97 ) {
F_181 ( V_317 , & V_3 -> V_51 . V_31 ) ;
break;
}
}
return V_97 ;
}
void F_182 ( struct V_124 * V_125 )
{
struct V_2 * V_3 = V_125 -> V_149 ;
while ( ! F_183 () ) {
F_184 ( V_125 , V_101 , 0 ) ;
if ( F_178 ( V_3 ) )
return;
}
}
