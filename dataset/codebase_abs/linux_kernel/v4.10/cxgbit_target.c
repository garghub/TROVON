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
T_1 V_7 = F_7 ( V_6 ) ;
T_1 V_49 = 0 ;
T_1 V_50 = sizeof( * V_48 ) ;
T_1 V_51 = V_52 ;
T_1 V_53 = 0 ;
T_1 V_54 = F_35 ( ! V_7 ) ;
if ( F_9 ( V_6 ) & V_22 ) {
V_51 = V_55 ;
V_53 += sizeof( struct V_16 ) ;
V_50 += sizeof( struct V_16 ) ;
V_7 |= 8 ;
}
if ( F_11 ( V_6 ) )
V_53 += V_45 ;
V_48 = (struct V_21 * ) F_22 ( V_6 ,
V_50 ) ;
V_48 -> V_56 = F_36 ( F_37 ( V_51 ) |
F_38 ( V_47 ) |
F_39 ( V_53 ) ) ;
V_48 -> V_57 = F_36 ( F_40 ( V_3 -> V_58 ) |
F_41 ( V_46 ) ) ;
V_48 -> V_59 = F_23 ( V_4 ) ;
V_49 = F_42 ( V_60 ) |
F_43 ( V_7 ) ;
V_48 -> V_61 = F_23 ( ( V_49 ) | V_54 |
F_44 ( F_45 ( & V_3 -> V_62 ) ? 0 : 1 ) ) ;
}
static void F_46 ( void * V_63 , struct V_1 * V_6 )
{
F_47 ( V_6 ) ;
}
void F_48 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
while ( V_3 -> V_64 && ( ( V_6 = F_45 ( & V_3 -> V_62 ) ) != NULL ) ) {
T_1 V_45 = V_6 -> V_4 ;
T_1 V_4 = V_6 -> V_4 ;
T_1 V_65 ;
T_1 V_47 = 0 ;
T_1 V_66 = 0 ;
T_1 V_67 = 0 ;
if ( F_9 ( V_6 ) & V_22 )
V_67 = sizeof( struct V_16 ) ;
if ( F_11 ( V_6 ) )
V_65 = F_16 ( V_45 + V_67 , 16 ) ;
else
V_65 = F_16 ( ( 8 *
F_15 ( V_6 ) ) +
V_67 , 16 ) ;
if ( F_12 ( F_9 ( V_6 ) & V_19 ) )
V_65 += F_16 (
sizeof( struct V_21 ) , 16 ) ;
if ( ! F_49 ( V_68 , & V_3 -> V_69 . V_31 ) ) {
V_66 = F_50 ( V_3 ) ;
V_3 -> V_64 -= V_66 ;
V_3 -> V_70 += V_66 ;
}
if ( V_3 -> V_64 < V_65 ) {
F_51 ( L_1 ,
V_3 , V_6 -> V_4 , V_6 -> V_13 ,
V_65 , V_3 -> V_64 ) ;
break;
}
F_52 ( V_6 , & V_3 -> V_62 ) ;
F_53 ( V_6 , V_71 , V_3 -> V_72 ) ;
V_6 -> V_73 = V_65 + V_66 ;
V_3 -> V_64 -= V_65 ;
V_3 -> V_70 += V_65 ;
F_51 ( L_2 ,
V_3 , V_6 -> V_4 , V_6 -> V_13 , V_65 ,
V_3 -> V_64 , V_3 -> V_70 ) ;
if ( F_12 ( F_9 ( V_6 ) & V_19 ) ) {
V_4 += F_8 ( V_6 ) ;
if ( ( V_3 -> V_70 >= ( V_3 -> V_74 / 2 ) ) ||
( ! F_54 ( V_3 -> V_75 ,
V_3 -> V_76 + V_3 -> V_77 ) ) ) {
V_47 = 1 ;
V_3 -> V_70 = 0 ;
}
F_34 ( V_3 , V_6 , V_45 , V_4 , V_65 ,
V_47 ) ;
V_3 -> V_78 += V_4 ;
} else if ( ( F_9 ( V_6 ) & V_79 ) ||
( V_3 -> V_70 >= ( V_3 -> V_74 / 2 ) ) ) {
struct V_80 * V_48 =
(struct V_80 * ) V_6 -> V_81 ;
V_48 -> V_82 . V_83 |= F_23 ( V_84 ) ;
V_3 -> V_70 = 0 ;
}
F_55 ( V_3 , V_6 ) ;
F_56 ( V_6 , V_3 ,
F_46 ) ;
F_51 ( L_3 ,
V_3 , V_3 -> V_58 , V_6 , V_4 ) ;
F_57 ( V_3 -> V_69 . V_85 , V_6 , V_3 -> V_86 ) ;
}
}
static bool F_58 ( struct V_2 * V_3 )
{
F_59 ( & V_3 -> V_87 ) ;
if ( F_54 ( V_3 -> V_75 , V_3 -> V_76 + V_3 -> V_77 ) )
V_3 -> V_88 = true ;
F_60 ( & V_3 -> V_87 ) ;
return V_3 -> V_88 ;
}
static void F_61 ( struct V_2 * V_3 )
{
struct V_89 V_90 ;
struct V_1 * V_6 ;
void (* F_62)( struct V_2 * , struct V_1 * );
F_63 ( & V_90 ) ;
F_59 ( & V_3 -> V_87 ) ;
while ( F_64 ( & V_3 -> V_90 ) ) {
F_65 ( & V_3 -> V_90 , & V_90 ) ;
F_60 ( & V_3 -> V_87 ) ;
while ( ( V_6 = F_66 ( & V_90 ) ) ) {
F_62 = F_67 ( V_6 ) ;
F_62 ( V_3 , V_6 ) ;
}
F_59 ( & V_3 -> V_87 ) ;
}
V_3 -> V_88 = false ;
F_60 ( & V_3 -> V_87 ) ;
}
static int F_68 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
int V_91 = 0 ;
F_69 ( V_3 -> V_92 , F_58 ( V_3 ) ) ;
if ( F_70 ( ( V_3 -> V_69 . V_93 != V_94 ) ||
F_71 ( V_95 ) ) ) {
F_72 ( V_6 ) ;
F_73 ( & V_3 -> V_96 ) ;
V_91 = - 1 ;
F_59 ( & V_3 -> V_87 ) ;
if ( V_3 -> V_88 ) {
F_60 ( & V_3 -> V_87 ) ;
goto V_97;
}
F_60 ( & V_3 -> V_87 ) ;
return V_91 ;
}
V_3 -> V_75 += V_6 -> V_4 +
F_8 ( V_6 ) ;
F_74 ( & V_3 -> V_96 , & V_3 -> V_62 ) ;
F_75 ( & V_3 -> V_62 , V_6 ) ;
F_48 ( V_3 ) ;
V_97:
F_61 ( V_3 ) ;
return V_91 ;
}
static int
F_76 ( struct V_98 * V_99 , struct V_1 * V_6 , T_1 V_100 ,
T_1 V_101 )
{
T_1 V_102 = 0 , V_26 = V_103 ;
T_1 V_104 = ( ( - V_101 ) & 3 ) ;
struct V_105 * V_106 ;
struct V_107 * V_107 ;
unsigned int V_108 ;
if ( V_104 )
V_26 -- ;
V_106 = & V_99 -> V_109 . V_110 [ V_100 / V_111 ] ;
V_108 = ( V_100 % V_111 ) ;
while ( V_101 && ( V_102 < V_26 ) ) {
T_1 V_112 = F_77 ( T_1 , V_101 , V_106 -> V_20 - V_108 ) ;
V_107 = F_78 ( V_106 ) ;
F_79 ( V_107 ) ;
F_80 ( V_6 , V_102 , V_107 , V_106 -> V_113 + V_108 ,
V_112 ) ;
V_6 -> V_13 += V_112 ;
V_6 -> V_4 += V_112 ;
V_6 -> V_114 += V_112 ;
V_101 -= V_112 ;
V_108 = 0 ;
V_106 = F_81 ( V_106 ) ;
V_102 ++ ;
}
if ( V_101 )
return - 1 ;
if ( V_104 ) {
V_107 = F_82 ( V_12 | V_115 ) ;
if ( ! V_107 )
return - 1 ;
F_80 ( V_6 , V_102 , V_107 , 0 , V_104 ) ;
V_6 -> V_13 += V_104 ;
V_6 -> V_4 += V_104 ;
V_6 -> V_114 += V_104 ;
}
return 0 ;
}
static int
F_83 ( struct V_2 * V_3 , struct V_98 * V_99 ,
struct V_116 * V_117 )
{
struct V_118 * V_119 = V_3 -> V_119 ;
struct V_1 * V_6 ;
struct V_120 V_121 ;
struct V_27 V_28 ;
T_1 V_101 = V_99 -> V_109 . V_101 ;
T_1 V_122 = V_119 -> V_123 -> V_124 ;
T_1 V_125 , V_59 , V_126 = 0 ;
bool V_127 = ! ! ( V_99 -> V_109 . V_128 &
V_129 ) ;
bool V_130 = false ;
int V_91 = - 1 ;
while ( V_101 ) {
V_125 = ( V_101 + V_122 - 1 ) / V_122 ;
if ( V_125 > V_3 -> V_131 )
V_125 = V_3 -> V_131 ;
V_59 = V_125 * V_122 ;
if ( V_59 > V_101 )
V_59 = V_101 ;
V_6 = F_1 ( V_3 , 0 , true ) ;
if ( F_70 ( ! V_6 ) )
return - V_132 ;
memset ( V_6 -> V_81 , 0 , V_11 ) ;
F_9 ( V_6 ) |= V_22 ;
F_7 ( V_6 ) |= ( V_3 -> V_7 &
V_14 ) ;
F_8 ( V_6 ) = ( V_125 *
V_18 [ F_7 ( V_6 ) ] ) +
( ( V_125 - 1 ) * V_11 ) ;
memset ( & V_121 , 0 , sizeof( struct V_120 ) ) ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
if ( ! V_126 )
V_28 . V_31 |= V_32 ;
if ( ! ( V_101 - V_59 ) ) {
V_28 . V_31 |= V_34 ;
if ( ! V_127 ) {
V_121 . V_31 = V_133 ;
F_84 ( V_99 , V_119 -> V_134 ) ;
V_99 -> V_135 = V_119 -> V_135 ++ ;
V_130 = true ;
}
}
V_28 . V_40 = V_125 * V_122 ;
V_28 . V_38 = V_122 ;
V_28 . V_4 = V_11 + V_59 ;
F_21 ( V_6 , & V_28 ) ;
V_121 . V_113 = V_126 ;
V_121 . V_136 = V_99 -> V_136 - 1 ;
F_85 ( V_99 , V_119 , & V_121 ,
(struct V_137 * ) V_6 -> V_81 ,
V_130 ) ;
V_91 = F_76 ( V_99 , V_6 , V_126 , V_59 ) ;
if ( F_70 ( V_91 ) ) {
F_72 ( V_6 ) ;
goto V_138;
}
V_91 = F_68 ( V_3 , V_6 ) ;
if ( F_70 ( V_91 ) )
goto V_138;
V_126 += V_59 ;
V_101 -= V_59 ;
V_99 -> V_139 += V_59 ;
V_99 -> V_136 += V_125 ;
}
V_117 -> V_140 = V_141 ;
return 0 ;
V_138:
return V_91 ;
}
static int
F_86 ( struct V_2 * V_3 , struct V_98 * V_99 ,
const struct V_120 * V_121 )
{
struct V_1 * V_6 ;
int V_91 = 0 ;
V_6 = F_10 ( V_3 , 0 ) ;
if ( F_70 ( ! V_6 ) )
return - V_132 ;
memcpy ( V_6 -> V_81 , V_99 -> V_142 , V_11 ) ;
if ( V_121 -> V_20 ) {
F_7 ( V_6 ) |= ( V_3 -> V_7 &
V_14 ) ;
F_8 ( V_6 ) =
V_18 [ F_7 ( V_6 ) ] ;
}
V_91 = F_76 ( V_99 , V_6 , V_121 -> V_113 , V_121 -> V_20 ) ;
if ( V_91 < 0 ) {
F_72 ( V_6 ) ;
return V_91 ;
}
return F_68 ( V_3 , V_6 ) ;
}
static int
F_87 ( struct V_118 * V_119 , struct V_98 * V_99 ,
struct V_116 * V_117 ,
const struct V_120 * V_121 )
{
struct V_2 * V_3 = V_119 -> V_143 ;
T_1 V_101 = V_99 -> V_109 . V_101 ;
T_1 V_104 = ( ( - V_101 ) & 3 ) ;
T_1 V_122 = V_119 -> V_123 -> V_124 ;
if ( ( V_101 > V_122 ) && ( ! V_117 -> V_144 ) &&
( ! V_104 ) && ( ! V_121 -> V_113 ) && V_3 -> V_131 ) {
F_88 ( V_101 - V_121 -> V_20 ,
& V_119 -> V_134 -> V_145 ) ;
return F_83 ( V_3 , V_99 , V_117 ) ;
}
return F_86 ( V_3 , V_99 , V_121 ) ;
}
static int
F_89 ( struct V_118 * V_119 , struct V_98 * V_99 ,
const void * V_146 , T_1 V_147 )
{
struct V_2 * V_3 = V_119 -> V_143 ;
struct V_1 * V_6 ;
T_1 V_104 = ( ( - V_147 ) & 3 ) ;
V_6 = F_10 ( V_3 , V_147 + V_104 ) ;
if ( F_70 ( ! V_6 ) )
return - V_132 ;
memcpy ( V_6 -> V_81 , V_99 -> V_142 , V_11 ) ;
if ( V_147 ) {
T_1 V_148 = 0 ;
F_90 ( V_6 , V_11 , V_146 , V_147 ) ;
if ( V_104 )
F_90 ( V_6 , V_11 + V_147 ,
& V_148 , V_104 ) ;
}
F_8 ( V_6 ) = V_18 [
F_7 ( V_6 ) ] ;
return F_68 ( V_3 , V_6 ) ;
}
int
F_91 ( struct V_118 * V_119 , struct V_98 * V_99 ,
struct V_116 * V_117 , const void * V_149 , T_1 V_150 )
{
if ( V_117 )
return F_87 ( V_119 , V_99 , V_117 , V_149 ) ;
else
return F_89 ( V_119 , V_99 , V_149 , V_150 ) ;
}
int F_92 ( struct V_118 * V_119 )
{
struct V_2 * V_3 = V_119 -> V_143 ;
struct V_151 * V_85 = V_3 -> V_69 . V_85 ;
struct V_152 * V_153 ;
T_1 V_154 ;
V_153 = F_93 ( V_155 ,
V_119 -> V_156 ) ;
if ( ! V_153 )
return - 1 ;
if ( F_94 ( V_153 -> V_157 , 0 , & V_154 ) < 0 )
return - 1 ;
if ( V_154 > V_85 -> V_158 ) {
if ( F_95 (
V_119 , L_4 , V_85 -> V_158 ) )
return - 1 ;
}
return 0 ;
}
static int F_96 ( struct V_2 * V_3 )
{
struct V_118 * V_119 = V_3 -> V_119 ;
struct V_152 * V_153 ;
V_153 = F_93 ( V_159 , V_119 -> V_156 ) ;
if ( ! V_153 ) {
F_97 ( L_5 , V_159 ) ;
return - 1 ;
}
if ( ! strcmp ( V_153 -> V_157 , V_160 ) )
V_3 -> V_7 |= V_17 ;
V_153 = F_93 ( V_161 , V_119 -> V_156 ) ;
if ( ! V_153 ) {
V_3 -> V_7 = 0 ;
F_97 ( L_5 , V_161 ) ;
return - 1 ;
}
if ( ! strcmp ( V_153 -> V_157 , V_160 ) )
V_3 -> V_7 |= V_14 ;
if ( F_98 ( V_3 ) ) {
V_3 -> V_7 = 0 ;
return - 1 ;
}
return 0 ;
}
static int F_99 ( struct V_2 * V_3 )
{
struct V_118 * V_119 = V_3 -> V_119 ;
struct V_162 * V_123 = V_119 -> V_123 ;
struct V_152 * V_153 ;
T_1 V_122 , V_163 ;
T_1 V_164 , V_131 ;
if ( V_119 -> V_165 -> V_166 ) {
V_153 = F_93 ( V_167 ,
V_119 -> V_156 ) ;
if ( ! V_153 ) {
F_97 ( L_5 , V_167 ) ;
return - 1 ;
}
if ( strcmp ( V_153 -> V_157 , V_168 ) )
return 0 ;
V_153 = F_93 ( V_169 ,
V_119 -> V_156 ) ;
if ( ! V_153 ) {
F_97 ( L_5 , V_169 ) ;
return - 1 ;
}
if ( strcmp ( V_153 -> V_157 , V_168 ) )
return 0 ;
V_153 = F_93 ( V_170 ,
V_119 -> V_156 ) ;
if ( ! V_153 ) {
F_97 ( L_5 , V_170 ) ;
return - 1 ;
}
if ( F_94 ( V_153 -> V_157 , 0 , & V_163 ) < 0 )
return - 1 ;
} else {
if ( ! V_119 -> V_134 -> V_171 -> V_172 )
return 0 ;
if ( ! V_119 -> V_134 -> V_171 -> V_173 )
return 0 ;
V_163 = V_119 -> V_134 -> V_171 -> V_174 ;
}
V_122 = V_123 -> V_124 ;
V_164 = V_163 / V_122 ;
V_131 = V_175 /
( V_11 + V_122 +
V_18 [ V_3 -> V_7 ] ) ;
V_3 -> V_131 = F_100 ( V_164 , V_131 ) ;
if ( V_3 -> V_131 <= 1 )
V_3 -> V_131 = 0 ;
return 0 ;
}
static int F_101 ( struct V_118 * V_119 )
{
struct V_2 * V_3 = V_119 -> V_143 ;
struct V_151 * V_85 = V_3 -> V_69 . V_85 ;
struct V_176 * V_177 = * V_3 -> V_69 . V_85 -> V_178 . V_179 ;
struct V_162 * V_123 = V_119 -> V_123 ;
struct V_152 * V_153 ;
T_2 V_180 ;
if ( V_123 -> V_124 > V_85 -> V_158 )
V_123 -> V_124 = V_85 -> V_158 ;
if ( V_119 -> V_165 -> V_166 ) {
V_153 = F_93 ( V_181 ,
V_119 -> V_156 ) ;
if ( ! V_153 ) {
F_97 ( L_5 , V_181 ) ;
return - 1 ;
}
if ( F_102 ( V_153 -> V_157 , 0 , & V_180 ) < 0 )
return - 1 ;
} else {
V_180 = V_119 -> V_134 -> V_171 -> V_182 ;
}
if ( ! V_180 ) {
if ( F_103 ( V_183 , & V_85 -> V_31 ) ) {
if ( F_99 ( V_3 ) )
return - 1 ;
}
if ( F_103 ( V_184 , & V_85 -> V_31 ) ) {
if ( F_104 ( V_3 ,
V_177 -> V_185 . V_186 ) )
return - 1 ;
F_105 ( V_187 , & V_3 -> V_69 . V_31 ) ;
}
}
if ( F_96 ( V_3 ) )
return - 1 ;
return 0 ;
}
int
F_106 ( struct V_118 * V_119 , struct V_188 * V_165 ,
T_1 V_20 )
{
struct V_2 * V_3 = V_119 -> V_143 ;
struct V_1 * V_6 ;
T_1 V_189 = 0 ;
T_2 V_104 = ( ( - V_20 ) & 3 ) ;
V_6 = F_10 ( V_3 , V_20 + V_104 ) ;
if ( ! V_6 )
return - V_132 ;
F_90 ( V_6 , 0 , V_165 -> V_190 , V_11 ) ;
F_90 ( V_6 , V_11 , V_165 -> V_191 , V_20 ) ;
if ( V_104 )
F_90 ( V_6 , V_11 + V_20 ,
& V_189 , V_104 ) ;
if ( V_165 -> V_192 ) {
if ( F_101 ( V_119 ) ) {
F_47 ( V_6 ) ;
return - 1 ;
}
F_105 ( V_193 , & V_3 -> V_69 . V_31 ) ;
}
if ( F_68 ( V_3 , V_6 ) )
return - 1 ;
if ( ( ! V_165 -> V_192 ) && ( ! V_165 -> V_194 ) )
F_107 ( & V_119 -> V_195 , 0 ) ;
return 0 ;
}
static void
F_108 ( struct V_1 * V_6 , struct V_105 * V_106 ,
unsigned int V_196 )
{
struct V_197 V_198 ;
const T_2 * V_149 ;
unsigned int V_199 = 0 , V_150 ;
struct V_200 * V_201 = F_109 ( V_6 ) ;
F_110 ( V_6 , V_201 -> V_202 ,
V_201 -> V_202 + V_201 -> V_45 ,
& V_198 ) ;
while ( true ) {
V_150 = F_111 ( V_199 , & V_149 , & V_198 ) ;
if ( ! V_150 ) {
F_112 ( & V_198 ) ;
break;
}
V_199 += F_113 ( V_106 , V_196 , ( void * ) V_149 ,
V_150 , V_199 ) ;
}
}
static struct V_98 * F_114 ( struct V_2 * V_3 )
{
struct V_118 * V_119 = V_3 -> V_119 ;
struct V_176 * V_177 = F_115 ( V_3 -> V_69 . V_85 ) ;
struct V_203 * V_204 ;
struct V_98 * V_99 ;
V_99 = F_116 ( V_119 , V_205 ) ;
if ( ! V_99 ) {
F_97 ( L_6 ) ;
return NULL ;
}
V_204 = F_117 ( V_99 ) ;
V_204 -> V_206 . V_207 = V_177 -> V_185 . V_208 ;
V_204 -> V_209 = true ;
return V_99 ;
}
static int
F_118 ( struct V_98 * V_99 , struct V_210 * V_211 ,
T_1 V_20 )
{
struct V_118 * V_119 = V_99 -> V_119 ;
struct V_2 * V_3 = V_119 -> V_143 ;
struct V_200 * V_201 = F_109 ( V_3 -> V_6 ) ;
if ( V_201 -> V_31 & V_212 ) {
F_97 ( L_7 ) ;
if ( ! V_119 -> V_134 -> V_171 -> V_182 ) {
F_97 ( L_8
L_9
L_10 ) ;
F_119 ( V_99 , V_213 ,
( unsigned char * ) V_211 ) ;
return V_214 ;
}
F_119 ( V_99 , V_213 ,
( unsigned char * ) V_211 ) ;
return V_215 ;
}
if ( V_99 -> V_109 . V_128 & V_216 ) {
struct V_203 * V_204 = F_117 ( V_99 ) ;
struct V_217 * V_218 = F_18 ( V_3 -> V_6 ) ;
T_3 * V_219 = & V_218 -> V_220 [ V_201 -> V_221 ] ;
F_120 ( & V_204 -> V_106 , 1 ) ;
F_121 ( & V_204 -> V_106 , V_219 -> V_107 . V_222 , F_122 ( V_219 ) ,
V_219 -> V_223 ) ;
F_79 ( V_219 -> V_107 . V_222 ) ;
V_99 -> V_109 . V_110 = & V_204 -> V_106 ;
V_99 -> V_109 . V_224 = 1 ;
V_204 -> V_225 = true ;
} else {
struct V_105 * V_106 = & V_99 -> V_109 . V_110 [ 0 ] ;
T_1 V_226 = F_123 ( 1UL , F_16 ( V_201 -> V_45 , V_111 ) ) ;
F_108 ( V_3 -> V_6 , V_106 , V_226 ) ;
}
V_99 -> V_227 += V_201 -> V_45 ;
if ( V_99 -> V_227 == V_99 -> V_109 . V_101 ) {
F_59 ( & V_99 -> V_228 ) ;
V_99 -> V_229 |= V_230 ;
V_99 -> V_231 = V_232 ;
F_60 ( & V_99 -> V_228 ) ;
}
return V_233 ;
}
static int
F_124 ( struct V_98 * V_99 , struct V_210 * V_211 ,
bool V_234 )
{
struct V_118 * V_119 = V_99 -> V_119 ;
int V_235 = 0 , V_236 = V_233 ;
if ( V_234 )
goto V_237;
V_236 = F_118 ( V_99 , V_211 ,
V_99 -> V_238 ) ;
V_237:
if ( V_236 == V_233 ) {
V_235 = F_125 ( V_119 , V_99 ,
( unsigned char * ) V_211 ,
V_211 -> V_239 ) ;
if ( V_235 == V_240 )
return - 1 ;
if ( V_99 -> V_241 || V_235 == V_242 ) {
F_126 ( & V_99 -> V_109 ) ;
return 0 ;
} else if ( V_99 -> V_243 ) {
F_127 ( V_99 ) ;
}
} else if ( V_236 == V_215 ) {
V_99 -> V_231 = V_244 ;
F_128 ( V_99 , V_119 , V_99 -> V_231 ) ;
} else
return - 1 ;
return 0 ;
}
static int
F_129 ( struct V_2 * V_3 , struct V_98 * V_99 )
{
struct V_118 * V_119 = V_3 -> V_119 ;
struct V_200 * V_201 = F_109 ( V_3 -> V_6 ) ;
struct V_210 * V_211 = (struct V_210 * ) V_201 -> V_211 ;
int V_245 ;
bool V_234 = false ;
V_245 = F_130 ( V_119 , V_99 , ( unsigned char * ) V_211 ) ;
if ( V_245 < 0 )
return V_245 ;
if ( V_201 -> V_45 && ( V_201 -> V_45 == V_99 -> V_109 . V_101 ) &&
( V_201 -> V_246 == 1 ) )
V_99 -> V_109 . V_128 |= V_216 ;
V_245 = F_131 ( V_119 , V_99 , V_211 ) ;
if ( V_245 < 0 )
return 0 ;
else if ( V_245 > 0 )
V_234 = true ;
if ( ! V_201 -> V_45 )
return 0 ;
return F_124 ( V_99 , V_211 , V_234 ) ;
}
static int F_132 ( struct V_2 * V_3 )
{
struct V_105 * V_247 ;
struct V_118 * V_119 = V_3 -> V_119 ;
struct V_98 * V_99 = NULL ;
struct V_200 * V_201 = F_109 ( V_3 -> V_6 ) ;
struct V_248 * V_211 = (struct V_248 * ) V_201 -> V_211 ;
T_1 V_100 = F_133 ( V_211 -> V_113 ) ;
T_1 V_13 = V_201 -> V_45 ;
int V_245 , V_226 , V_249 ;
bool V_250 = false ;
V_245 = F_134 ( V_119 , ( unsigned char * ) V_211 , & V_99 ) ;
if ( V_245 < 0 )
return V_245 ;
else if ( ! V_99 )
return 0 ;
if ( V_201 -> V_31 & V_212 ) {
F_97 ( L_11
L_12 ,
V_211 -> V_251 , V_211 -> V_113 , V_13 ,
V_211 -> V_252 ) ;
V_250 = true ;
goto V_253;
}
F_51 ( L_13
L_14 ,
V_13 , V_99 -> V_227 ,
V_99 -> V_109 . V_101 ) ;
if ( ! ( V_201 -> V_31 & V_254 ) ) {
V_249 = V_100 / V_111 ;
V_247 = & V_99 -> V_109 . V_110 [ V_249 ] ;
V_226 = F_123 ( 1UL , F_16 ( V_13 , V_111 ) ) ;
F_108 ( V_3 -> V_6 , V_247 , V_226 ) ;
}
V_253:
V_245 = F_135 ( V_99 , V_211 , V_250 ) ;
if ( V_245 < 0 )
return V_245 ;
return 0 ;
}
static int F_136 ( struct V_2 * V_3 , struct V_98 * V_99 )
{
struct V_118 * V_119 = V_3 -> V_119 ;
struct V_200 * V_201 = F_109 ( V_3 -> V_6 ) ;
struct V_255 * V_211 = (struct V_255 * ) V_201 -> V_211 ;
unsigned char * V_256 = NULL ;
T_1 V_257 = V_201 -> V_45 ;
int V_91 ;
V_91 = F_137 ( V_119 , V_99 , V_211 ) ;
if ( V_91 < 0 )
return 0 ;
if ( V_201 -> V_31 & V_212 ) {
if ( ! V_119 -> V_134 -> V_171 -> V_182 ) {
F_97 ( L_8
L_15
L_16 ) ;
V_91 = - 1 ;
goto V_138;
} else {
F_138 ( L_17
L_18
L_19 , V_211 -> V_239 ) ;
V_91 = 0 ;
goto V_138;
}
}
if ( V_257 && V_211 -> V_258 == F_36 ( 0xFFFFFFFF ) ) {
V_256 = F_139 ( V_257 + 1 , V_12 ) ;
if ( ! V_256 ) {
F_97 ( L_20
L_21 ) ;
V_91 = - 1 ;
goto V_138;
}
F_140 ( V_3 -> V_6 , V_201 -> V_202 ,
V_256 , V_257 ) ;
V_256 [ V_257 ] = '\0' ;
V_99 -> V_259 = V_256 ;
V_99 -> V_260 = V_257 ;
F_51 ( L_22
L_23 , V_257 ) ;
F_51 ( L_24 , V_256 ) ;
}
return F_141 ( V_119 , V_99 , V_211 ) ;
V_138:
if ( V_99 )
F_142 ( V_99 , false ) ;
return V_91 ;
}
static int
F_143 ( struct V_2 * V_3 , struct V_98 * V_99 )
{
struct V_118 * V_119 = V_3 -> V_119 ;
struct V_200 * V_201 = F_109 ( V_3 -> V_6 ) ;
struct V_261 * V_211 = (struct V_261 * ) V_201 -> V_211 ;
T_1 V_257 = V_201 -> V_45 ;
int V_245 ;
unsigned char * V_262 = NULL ;
V_245 = F_144 ( V_119 , V_99 , V_211 ) ;
if ( V_245 < 0 )
return V_245 ;
if ( V_201 -> V_31 & V_212 ) {
if ( ! V_119 -> V_134 -> V_171 -> V_182 ) {
F_97 ( L_8
L_25
L_16 ) ;
goto V_263;
} else {
F_138 ( L_26
L_18
L_19 , V_211 -> V_239 ) ;
return 0 ;
}
}
if ( V_257 ) {
V_262 = F_139 ( V_257 , V_12 ) ;
if ( ! V_262 ) {
F_97 ( L_27 ,
V_257 ) ;
return - V_132 ;
}
F_140 ( V_3 -> V_6 , V_201 -> V_202 ,
V_262 , V_257 ) ;
V_262 [ V_257 - 1 ] = '\0' ;
V_99 -> V_264 = V_262 ;
}
return F_145 ( V_119 , V_99 , V_211 ) ;
V_263:
return F_119 ( V_99 , V_265 ,
V_201 -> V_211 ) ;
}
static int F_146 ( struct V_2 * V_3 )
{
struct V_200 * V_201 = F_109 ( V_3 -> V_6 ) ;
struct V_266 * V_211 = (struct V_266 * ) V_201 -> V_211 ;
struct V_118 * V_119 = V_3 -> V_119 ;
struct V_98 * V_99 = NULL ;
T_2 V_51 = ( V_211 -> V_51 & V_267 ) ;
int V_91 = - V_268 ;
switch ( V_51 ) {
case V_269 :
V_99 = F_114 ( V_3 ) ;
if ( ! V_99 )
goto V_263;
V_91 = F_129 ( V_3 , V_99 ) ;
break;
case V_270 :
V_91 = F_132 ( V_3 ) ;
break;
case V_271 :
if ( V_211 -> V_258 == F_36 ( 0xFFFFFFFF ) ) {
V_99 = F_114 ( V_3 ) ;
if ( ! V_99 )
goto V_263;
}
V_91 = F_136 ( V_3 , V_99 ) ;
break;
case V_272 :
V_99 = F_114 ( V_3 ) ;
if ( ! V_99 )
goto V_263;
V_91 = F_147 ( V_119 , V_99 ,
( unsigned char * ) V_211 ) ;
break;
case V_273 :
if ( V_211 -> V_258 != F_36 ( 0xFFFFFFFF ) ) {
V_99 = F_148 ( V_119 , V_211 -> V_251 ) ;
if ( ! V_99 )
goto V_263;
} else {
V_99 = F_114 ( V_3 ) ;
if ( ! V_99 )
goto V_263;
}
V_91 = F_143 ( V_3 , V_99 ) ;
break;
case V_274 :
V_99 = F_114 ( V_3 ) ;
if ( ! V_99 )
goto V_263;
V_91 = F_149 ( V_119 , V_99 , ( unsigned char * ) V_211 ) ;
if ( V_91 > 0 )
F_150 ( & V_119 -> V_275 ,
V_276
* V_277 ) ;
break;
case V_278 :
V_91 = F_151 ( V_119 , ( unsigned char * ) V_211 ) ;
break;
default:
F_97 ( L_28 , V_51 ) ;
F_152 () ;
break;
}
return V_91 ;
V_263:
return F_153 ( V_119 , V_279 ,
( unsigned char * ) V_211 ) ;
return V_91 ;
}
static int F_154 ( struct V_2 * V_3 )
{
struct V_200 * V_201 = F_109 ( V_3 -> V_6 ) ;
struct V_118 * V_119 = V_3 -> V_119 ;
struct V_266 * V_211 = V_201 -> V_211 ;
T_2 V_51 ;
if ( V_201 -> V_31 & V_280 ) {
F_155 ( & V_119 -> V_134 -> V_281 ) ;
goto V_282;
}
if ( V_119 -> V_283 == V_284 )
goto V_282;
V_51 = V_211 -> V_51 & V_267 ;
if ( V_119 -> V_134 -> V_171 -> V_285 &&
( ( ! ( V_51 & V_273 ) ) ||
( ! ( V_51 & V_274 ) ) ) ) {
F_97 ( L_29
L_30 , V_51 ) ;
F_153 ( V_119 , V_265 ,
( unsigned char * ) V_211 ) ;
goto V_282;
}
if ( F_146 ( V_3 ) < 0 )
goto V_282;
return 0 ;
V_282:
return - 1 ;
}
static int F_156 ( struct V_2 * V_3 )
{
struct V_118 * V_119 = V_3 -> V_119 ;
struct V_188 * V_165 = V_119 -> V_165 ;
struct V_200 * V_201 = F_109 ( V_3 -> V_6 ) ;
struct V_286 * V_287 ;
V_287 = (struct V_286 * ) V_165 -> V_48 ;
memcpy ( V_287 , V_201 -> V_211 , sizeof( * V_287 ) ) ;
F_51 ( L_31
L_32 ,
V_287 -> V_31 , V_287 -> V_251 , V_287 -> V_239 ,
V_287 -> V_288 , V_287 -> V_289 , V_201 -> V_45 ) ;
if ( V_165 -> V_290 ) {
V_287 = (struct V_286 * ) V_165 -> V_48 ;
V_165 -> V_166 = ( ! V_287 -> V_291 ) ? 1 : 0 ;
V_165 -> V_292 = F_157 (
V_287 -> V_31 ) ;
V_165 -> V_293 = V_287 -> V_294 ;
V_165 -> V_295 = V_287 -> V_296 ;
memcpy ( V_165 -> V_297 , V_287 -> V_297 , 6 ) ;
V_165 -> V_298 = F_133 ( V_287 -> V_239 ) ;
V_165 -> V_299 = V_287 -> V_251 ;
V_165 -> V_300 = F_133 ( V_287 -> V_288 ) ;
V_165 -> V_289 = F_158 ( V_287 -> V_289 ) ;
V_165 -> V_291 = F_158 ( V_287 -> V_291 ) ;
}
if ( F_159 ( V_119 , V_165 ) < 0 )
return - 1 ;
memset ( V_165 -> V_301 , 0 , V_302 ) ;
F_140 ( V_3 -> V_6 , V_201 -> V_202 , V_165 -> V_301 , V_201 -> V_45 ) ;
return 0 ;
}
static int
F_160 ( struct V_2 * V_3 , struct V_1 * V_6 , int V_303 )
{
struct V_200 * V_201 = F_161 ( V_6 , V_303 ) ;
int V_91 ;
F_109 ( V_6 ) = V_201 ;
V_3 -> V_6 = V_6 ;
if ( ! F_103 ( V_193 , & V_3 -> V_69 . V_31 ) ) {
V_91 = F_156 ( V_3 ) ;
F_105 ( V_304 , & V_3 -> V_69 . V_31 ) ;
} else {
V_91 = F_154 ( V_3 ) ;
}
return V_91 ;
}
static void F_162 ( struct V_1 * V_6 )
{
struct V_217 * V_218 = F_18 ( V_6 ) ;
struct V_305 * V_306 = F_163 ( V_6 ) ;
struct V_200 * V_201 = F_161 ( V_6 , 0 ) ;
T_2 V_102 ;
F_138 ( L_33 ,
V_6 , V_6 -> V_307 , V_6 -> V_81 , V_6 -> V_4 , V_6 -> V_13 ,
V_218 -> V_26 ) ;
F_138 ( L_34 ,
V_6 , V_306 -> V_3 , V_306 -> V_308 , V_306 -> V_309 ) ;
for ( V_102 = 0 ; V_102 < V_306 -> V_308 ; V_102 ++ , V_201 ++ )
F_138 ( L_35
L_36 ,
V_6 , V_102 , V_201 -> V_310 , V_201 -> V_31 , V_201 -> V_311 ,
V_201 -> V_312 , V_201 -> V_220 ) ;
for ( V_102 = 0 ; V_102 < V_218 -> V_26 ; V_102 ++ )
F_138 ( L_37 ,
V_6 , V_102 , V_218 -> V_220 [ V_102 ] . V_223 , V_218 -> V_220 [ V_102 ] . V_313 ) ;
}
static void F_164 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = V_3 -> V_314 ;
struct V_217 * V_218 = F_18 ( V_6 ) ;
T_2 V_102 ;
memset ( V_6 -> V_81 , 0 , V_315 ) ;
for ( V_102 = 0 ; V_102 < V_218 -> V_26 ; V_102 ++ )
F_165 ( F_166 ( & V_218 -> V_220 [ V_102 ] ) ) ;
V_218 -> V_26 = 0 ;
}
static void
F_167 ( struct V_2 * V_3 , struct V_1 * V_6 , T_2 V_308 )
{
struct V_1 * V_316 = V_3 -> V_314 ;
struct V_200 * V_317 = F_161 ( V_316 , 0 ) ;
struct V_200 * V_201 = F_161 ( V_6 , V_308 ) ;
struct V_217 * V_318 = F_18 ( V_316 ) ;
struct V_217 * V_218 = F_18 ( V_6 ) ;
unsigned int V_4 = 0 ;
if ( V_201 -> V_31 & V_319 ) {
V_317 -> V_31 = V_201 -> V_31 ;
V_317 -> V_311 = V_201 -> V_311 ;
V_317 -> V_211 = V_201 -> V_211 ;
V_317 -> V_320 = V_201 -> V_320 ;
memcpy ( & V_318 -> V_220 [ 0 ] , & V_218 -> V_220 [ V_201 -> V_321 ] ,
sizeof( T_3 ) ) ;
F_79 ( F_166 ( & V_318 -> V_220 [ 0 ] ) ) ;
V_318 -> V_26 = 1 ;
V_317 -> V_220 = 1 ;
V_317 -> V_321 = 0 ;
V_4 = V_318 -> V_220 [ 0 ] . V_313 ;
V_316 -> V_4 = V_4 ;
V_316 -> V_13 = V_4 ;
V_316 -> V_114 = V_4 ;
}
if ( V_201 -> V_31 & V_322 ) {
T_2 V_321 = 1 , V_102 ;
V_317 -> V_31 |= V_201 -> V_31 ;
V_4 = 0 ;
for ( V_102 = 0 ; V_102 < V_201 -> V_246 ; V_321 ++ , V_102 ++ ) {
memcpy ( & V_318 -> V_220 [ V_321 ] ,
& V_218 -> V_220 [ V_201 -> V_221 + V_102 ] ,
sizeof( T_3 ) ) ;
F_79 ( F_166 ( & V_318 -> V_220 [ V_321 ] ) ) ;
V_4 += V_318 -> V_220 [ V_321 ] . V_313 ;
V_318 -> V_26 ++ ;
V_317 -> V_220 ++ ;
}
V_317 -> V_45 = V_201 -> V_45 ;
V_317 -> V_202 = V_317 -> V_320 ;
V_317 -> V_246 = V_201 -> V_246 ;
V_317 -> V_221 = 1 ;
V_316 -> V_4 += V_4 ;
V_316 -> V_13 += V_4 ;
V_316 -> V_114 += V_4 ;
}
if ( V_201 -> V_31 & V_323 ) {
V_317 -> V_31 |= V_201 -> V_31 ;
if ( V_317 -> V_31 & V_322 )
V_317 -> V_31 &= ~ V_254 ;
V_317 -> V_312 = V_201 -> V_312 ;
V_317 -> V_310 = V_201 -> V_310 ;
}
}
static int F_168 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
struct V_305 * V_306 = F_163 ( V_6 ) ;
struct V_200 * V_201 = F_161 ( V_6 , 0 ) ;
T_2 V_308 = 0 , V_324 = 0 ;
int V_91 = 0 ;
if ( ! V_201 -> V_325 ) {
F_167 ( V_3 , V_6 , 0 ) ;
if ( V_201 -> V_31 & V_323 ) {
struct V_1 * V_316 = V_3 -> V_314 ;
V_91 = F_160 ( V_3 , V_316 , 0 ) ;
F_164 ( V_3 ) ;
if ( V_91 < 0 )
goto V_138;
}
V_308 = 1 ;
}
if ( V_306 -> V_308 )
V_324 = V_306 -> V_308 - 1 ;
for (; V_308 <= V_324 ; V_308 ++ ) {
V_91 = F_160 ( V_3 , V_6 , V_308 ) ;
if ( V_91 < 0 )
goto V_138;
}
if ( ( ! V_306 -> V_325 ) && V_306 -> V_308 )
F_167 ( V_3 , V_6 , V_306 -> V_308 ) ;
V_138:
return V_91 ;
}
static int F_169 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
struct V_305 * V_306 = F_163 ( V_6 ) ;
struct V_200 * V_201 = F_161 ( V_6 , 0 ) ;
int V_91 = - 1 ;
if ( ( V_201 -> V_31 & V_319 ) &&
( V_201 -> V_311 != V_3 -> V_326 ) ) {
F_138 ( L_38 ,
V_3 , V_3 -> V_58 , V_201 -> V_311 , V_3 -> V_326 ) ;
F_162 ( V_6 ) ;
return V_91 ;
}
V_3 -> V_326 += V_306 -> V_309 ;
V_91 = F_168 ( V_3 , V_6 ) ;
V_3 -> V_327 += V_306 -> V_309 ;
if ( V_3 -> V_327 >= ( V_3 -> V_328 / 4 ) )
F_170 ( V_3 ) ;
return V_91 ;
}
static int F_171 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
int V_91 = - 1 ;
if ( F_12 ( F_9 ( V_6 ) & V_329 ) )
V_91 = F_169 ( V_3 , V_6 ) ;
F_72 ( V_6 ) ;
return V_91 ;
}
static bool F_172 ( struct V_2 * V_3 , struct V_89 * V_330 )
{
F_59 ( & V_3 -> V_330 . V_87 ) ;
if ( F_64 ( & V_3 -> V_330 ) ) {
F_65 ( & V_3 -> V_330 , V_330 ) ;
F_60 ( & V_3 -> V_330 . V_87 ) ;
return true ;
}
F_60 ( & V_3 -> V_330 . V_87 ) ;
return false ;
}
static int F_173 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
struct V_89 V_330 ;
F_63 ( & V_330 ) ;
F_69 ( V_3 -> V_331 , F_172 ( V_3 , & V_330 ) ) ;
if ( F_71 ( V_95 ) )
goto V_138;
while ( ( V_6 = F_66 ( & V_330 ) ) ) {
if ( F_171 ( V_3 , V_6 ) )
goto V_138;
}
return 0 ;
V_138:
F_73 ( & V_330 ) ;
return - 1 ;
}
int F_174 ( struct V_118 * V_119 , struct V_188 * V_165 )
{
struct V_2 * V_3 = V_119 -> V_143 ;
int V_91 = - 1 ;
while ( ! F_175 ( V_304 , & V_3 -> V_69 . V_31 ) ) {
V_91 = F_173 ( V_3 ) ;
if ( V_91 ) {
F_176 ( V_304 , & V_3 -> V_69 . V_31 ) ;
break;
}
}
return V_91 ;
}
void F_177 ( struct V_118 * V_119 )
{
struct V_2 * V_3 = V_119 -> V_143 ;
while ( ! F_178 () ) {
F_179 ( V_119 , V_95 , 0 ) ;
if ( F_173 ( V_3 ) )
return;
}
}
