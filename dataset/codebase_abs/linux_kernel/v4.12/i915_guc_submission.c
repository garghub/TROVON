static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 <= V_4 ;
}
static int F_2 ( struct V_1 * V_2 )
{
unsigned long V_5 ;
unsigned long V_6 ;
T_1 V_7 ;
F_3 ( V_2 -> V_8 != V_9 ) ;
V_5 = 0 ;
V_6 = V_10 / 2 ;
if ( F_1 ( V_2 ) ) {
V_5 = V_6 ;
V_6 += V_5 ;
}
V_7 = F_4 ( V_2 -> V_11 -> V_12 , V_5 , V_6 ) ;
if ( V_7 == V_6 )
return - V_13 ;
F_5 ( V_7 , V_2 -> V_11 -> V_12 ) ;
V_2 -> V_8 = V_7 ;
F_6 ( L_1 ,
V_2 -> V_14 , F_7 ( F_1 ( V_2 ) ) ,
V_7 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_8 == V_9 ) ;
F_9 ( V_2 -> V_8 , V_2 -> V_11 -> V_12 ) ;
V_2 -> V_8 = V_9 ;
}
static int F_10 ( struct V_15 * V_11 , T_2 V_14 )
{
T_2 V_16 [] = {
V_17 ,
V_14
} ;
return F_11 ( V_11 , V_16 , F_12 ( V_16 ) ) ;
}
static int F_13 ( struct V_15 * V_11 , T_2 V_14 )
{
T_2 V_16 [] = {
V_18 ,
V_14
} ;
return F_11 ( V_11 , V_16 , F_12 ( V_16 ) ) ;
}
static struct V_19 * F_14 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_11 -> V_21 ;
return & V_20 [ V_2 -> V_14 ] ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_22 )
{
struct V_19 * V_23 ;
V_23 = F_14 ( V_2 ) ;
V_23 -> V_24 = V_22 ;
}
static struct V_25 * F_16 ( struct V_1 * V_2 )
{
return V_2 -> V_26 + V_2 -> V_27 ;
}
static bool F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 == V_9 )
return false ;
return F_18 ( V_2 -> V_8 , V_2 -> V_11 -> V_12 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_25 * V_28 ;
int V_29 ;
V_28 = F_16 ( V_2 ) ;
V_28 -> V_30 = V_31 ;
V_28 -> V_32 = V_2 -> V_33 ;
V_29 = F_10 ( V_2 -> V_11 , V_2 -> V_14 ) ;
if ( V_29 ) {
V_28 -> V_30 = V_34 ;
V_28 -> V_32 = 0 ;
}
return V_29 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_21 ( V_2 -> V_11 ) ;
struct V_25 * V_28 ;
T_1 V_24 = V_2 -> V_8 ;
F_3 ( V_24 >= V_9 ) ;
V_28 = F_16 ( V_2 ) ;
V_28 -> V_30 = V_34 ;
V_28 -> V_32 = 0 ;
if ( F_22 ( ! ( F_23 ( F_24 ( V_24 ) ) & V_37 ) , 10 ) )
F_25 ( true , L_2 ) ;
return F_13 ( V_2 -> V_11 , V_2 -> V_14 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_38 ;
V_38 = F_2 ( V_2 ) ;
if ( V_38 )
return V_38 ;
F_15 ( V_2 , V_2 -> V_8 ) ;
V_38 = F_19 ( V_2 ) ;
if ( V_38 )
goto V_29;
return 0 ;
V_29:
F_15 ( V_2 , V_9 ) ;
F_8 ( V_2 ) ;
return V_38 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_29 ;
F_3 ( ! F_17 ( V_2 ) ) ;
V_29 = F_20 ( V_2 ) ;
if ( V_29 )
return V_29 ;
F_15 ( V_2 , V_9 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static unsigned long F_28 ( struct V_15 * V_11 )
{
unsigned long V_5 ;
V_5 = F_29 ( V_11 -> V_39 ) ;
V_11 -> V_39 += F_30 () ;
F_6 ( L_3 ,
V_5 , V_11 -> V_39 , F_30 () ) ;
return V_5 ;
}
static inline struct V_40 *
F_31 ( struct V_1 * V_2 )
{
return V_2 -> V_26 + V_2 -> V_41 ;
}
static void F_32 ( struct V_15 * V_11 ,
struct V_1 * V_2 )
{
struct V_40 * V_23 ;
V_23 = memset ( F_31 ( V_2 ) , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_42 = 0 ;
V_23 -> V_43 = 0 ;
V_23 -> V_14 = V_2 -> V_14 ;
V_23 -> V_44 = V_2 -> V_45 ;
V_23 -> V_46 = V_47 ;
V_23 -> V_3 = V_2 -> V_3 ;
}
static void F_33 ( struct V_15 * V_11 ,
struct V_1 * V_2 )
{
struct V_35 * V_36 = F_21 ( V_11 ) ;
struct V_48 * V_49 ;
struct V_50 * V_51 = V_2 -> V_52 ;
struct V_19 * V_23 ;
unsigned int V_53 ;
T_2 V_54 ;
V_23 = F_14 ( V_2 ) ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_55 = V_56 | V_57 ;
V_23 -> V_14 = V_2 -> V_14 ;
V_23 -> V_3 = V_2 -> V_3 ;
V_23 -> V_24 = V_2 -> V_8 ;
F_34 (engine, dev_priv, client->engines, tmp) {
struct V_58 * V_59 = & V_51 -> V_49 [ V_49 -> V_7 ] ;
T_3 V_60 = V_49 -> V_61 ;
struct V_62 * V_63 = & V_23 -> V_63 [ V_60 ] ;
if ( ! V_59 -> V_64 )
break;
V_63 -> V_65 = F_35 ( V_59 -> V_66 ) ;
V_63 -> V_67 =
F_36 ( V_59 -> V_64 ) + V_68 * V_69 ;
V_63 -> V_70 = ( V_2 -> V_14 << V_71 ) |
( V_60 << V_72 ) ;
V_63 -> V_73 = F_36 ( V_59 -> V_74 -> V_75 ) ;
V_63 -> V_76 = V_63 -> V_73 + V_59 -> V_74 -> V_77 - 1 ;
V_63 -> V_78 = V_63 -> V_73 ;
V_63 -> V_79 = 0 ;
V_23 -> V_80 |= ( 1 << V_60 ) ;
}
F_6 ( L_4 ,
V_2 -> V_81 , V_23 -> V_80 ) ;
F_37 ( V_23 -> V_80 == 0 ) ;
V_54 = F_36 ( V_2 -> V_75 ) ;
V_23 -> V_82 = F_38 ( V_2 -> V_75 -> V_83 -> V_84 ) +
V_2 -> V_27 ;
V_23 -> V_85 = ( V_86 ) F_16 ( V_2 ) ;
V_23 -> V_87 = V_54 + V_2 -> V_27 ;
V_23 -> V_88 = V_54 + V_2 -> V_41 ;
V_23 -> V_89 = V_54 + V_2 -> V_90 ;
V_23 -> V_45 = V_2 -> V_45 ;
V_23 -> V_91 = ( V_86 ) V_2 ;
}
static void F_39 ( struct V_15 * V_11 ,
struct V_1 * V_2 )
{
struct V_19 * V_23 ;
V_23 = F_14 ( V_2 ) ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
}
int F_40 ( struct V_92 * V_93 )
{
const T_4 V_94 = sizeof( struct V_95 ) ;
struct V_1 * V_2 = V_93 -> V_96 -> V_11 . V_97 ;
struct V_40 * V_23 = F_31 ( V_2 ) ;
T_2 V_98 ;
int V_38 ;
F_41 ( & V_2 -> V_99 ) ;
V_98 = F_42 ( V_2 -> V_100 , V_23 -> V_101 , V_2 -> V_45 ) ;
V_98 -= V_2 -> V_102 ;
if ( F_43 ( V_98 >= V_94 ) ) {
V_2 -> V_102 += V_94 ;
V_38 = 0 ;
} else {
V_2 -> V_103 ++ ;
V_38 = - V_104 ;
}
F_44 ( & V_2 -> V_99 ) ;
return V_38 ;
}
static void F_45 ( struct V_1 * V_2 , int V_77 )
{
unsigned long V_105 ;
F_46 ( & V_2 -> V_99 , V_105 ) ;
V_2 -> V_102 += V_77 ;
F_47 ( & V_2 -> V_99 , V_105 ) ;
}
void F_48 ( struct V_92 * V_93 )
{
const int V_94 = sizeof( struct V_95 ) ;
struct V_1 * V_2 = V_93 -> V_96 -> V_11 . V_97 ;
F_3 ( F_49 ( V_2 -> V_102 ) < V_94 ) ;
F_45 ( V_2 , - V_94 ) ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_92 * V_106 )
{
const T_4 V_94 = sizeof( struct V_95 ) ;
const T_2 V_107 = V_94 / sizeof( T_2 ) - 1 ;
struct V_48 * V_49 = V_106 -> V_49 ;
struct V_40 * V_23 = F_31 ( V_2 ) ;
struct V_95 * V_108 ;
T_2 V_98 , V_109 , V_110 ;
V_98 = F_42 ( V_2 -> V_100 , V_23 -> V_101 , V_2 -> V_45 ) ;
F_3 ( V_98 < V_94 ) ;
V_109 = F_51 ( V_106 -> V_74 , V_106 -> V_109 ) >> 3 ;
F_3 ( V_109 > V_111 ) ;
F_52 ( V_94 != 16 ) ;
F_3 ( V_2 -> V_102 < V_94 ) ;
V_110 = V_2 -> V_100 ;
F_3 ( V_110 & ( V_94 - 1 ) ) ;
V_2 -> V_100 += V_94 ;
V_2 -> V_100 &= V_2 -> V_45 - 1 ;
V_2 -> V_102 -= V_94 ;
V_108 = V_2 -> V_26 + V_110 + V_112 ;
V_108 -> V_113 = V_114 |
( V_107 << V_115 ) |
( V_49 -> V_61 << V_116 ) |
V_117 ;
V_108 -> V_65 = ( T_2 ) F_53 ( V_106 -> V_51 , V_49 ) ;
V_108 -> V_118 = V_109 << V_119 ;
V_108 -> V_120 = V_106 -> V_121 ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_40 * V_23 = F_31 ( V_2 ) ;
V_23 -> V_101 = 0 ;
V_23 -> V_109 = 0 ;
V_2 -> V_100 = 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_40 * V_23 = F_31 ( V_2 ) ;
union V_122 V_123 , V_124 , V_125 ;
union V_122 * V_126 ;
int V_127 = 2 , V_38 = - V_104 ;
V_23 -> V_109 = V_2 -> V_100 ;
V_123 . V_30 = V_31 ;
V_123 . V_32 = V_2 -> V_33 ;
V_124 . V_30 = V_31 ;
V_124 . V_32 = V_2 -> V_33 + 1 ;
if ( V_124 . V_32 == 0 )
V_124 . V_32 = 1 ;
V_126 = (union V_122 * ) F_16 ( V_2 ) ;
while ( V_127 -- ) {
V_125 . V_128 = F_56 ( ( V_129 * ) V_126 ,
V_123 . V_128 , V_124 . V_128 ) ;
if ( V_125 . V_128 == V_123 . V_128 ) {
V_2 -> V_33 = V_124 . V_32 ;
V_38 = 0 ;
break;
}
if ( V_125 . V_30 == V_34 )
break;
F_57 ( L_5 ,
V_123 . V_32 , V_125 . V_32 ) ;
V_123 . V_32 = V_125 . V_32 ;
V_124 . V_32 = V_125 . V_32 + 1 ;
if ( V_124 . V_32 == 0 )
V_124 . V_32 = 1 ;
}
return V_38 ;
}
static void F_58 ( struct V_92 * V_106 )
{
struct V_35 * V_36 = V_106 -> V_96 ;
struct V_48 * V_49 = V_106 -> V_49 ;
unsigned int V_130 = V_49 -> V_7 ;
struct V_15 * V_11 = & V_106 -> V_96 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_97 ;
unsigned long V_105 ;
int V_131 ;
if ( F_59 ( V_106 -> V_74 -> V_75 ) )
F_60 ( V_132 ) ;
F_46 ( & V_2 -> V_99 , V_105 ) ;
F_50 ( V_2 , V_106 ) ;
V_131 = F_55 ( V_2 ) ;
V_2 -> V_133 [ V_130 ] += 1 ;
V_2 -> V_134 = V_131 ;
if ( V_131 )
V_2 -> V_135 += 1 ;
V_11 -> V_133 [ V_130 ] += 1 ;
V_11 -> V_136 [ V_130 ] = V_106 -> V_121 ;
F_47 ( & V_2 -> V_99 , V_105 ) ;
}
static void F_61 ( struct V_92 * V_106 )
{
F_62 ( V_106 ) ;
F_58 ( V_106 ) ;
}
static void F_63 ( struct V_92 * V_106 )
{
if ( F_64 ( V_137 ,
& V_106 -> V_138 . V_105 ) )
return;
F_3 ( F_18 ( V_139 , & V_106 -> V_138 . V_105 ) ) ;
F_65 ( & V_106 -> V_138 ) ;
F_66 ( & V_106 -> V_140 , V_141 ) ;
F_67 ( V_106 ) ;
F_68 ( & V_106 -> V_140 ) ;
}
static bool F_69 ( struct V_48 * V_49 )
{
struct V_142 * V_143 = V_49 -> V_142 ;
struct V_92 * V_144 = V_143 [ 0 ] . V_93 ;
struct V_145 * V_146 ;
bool V_147 = false ;
F_41 ( & V_49 -> V_148 -> V_140 ) ;
V_146 = V_49 -> V_149 ;
while ( V_146 ) {
struct V_92 * V_106 =
F_70 ( V_146 , F_71 ( * V_106 ) , V_150 . V_151 ) ;
if ( V_144 && V_106 -> V_51 != V_144 -> V_51 ) {
if ( V_143 != V_49 -> V_142 )
break;
F_72 ( & V_143 -> V_93 , V_144 ) ;
F_63 ( V_144 ) ;
V_143 ++ ;
}
V_146 = F_73 ( V_146 ) ;
F_74 ( & V_106 -> V_150 . V_151 , & V_49 -> V_152 ) ;
F_75 ( & V_106 -> V_150 . V_151 ) ;
V_106 -> V_150 . V_3 = V_153 ;
F_61 ( V_106 ) ;
F_76 ( V_106 , V_143 - V_49 -> V_142 ) ;
V_144 = V_106 ;
V_147 = true ;
}
if ( V_147 ) {
F_72 ( & V_143 -> V_93 , V_144 ) ;
F_63 ( V_144 ) ;
V_49 -> V_149 = V_146 ;
}
F_44 ( & V_49 -> V_148 -> V_140 ) ;
return V_147 ;
}
static void F_77 ( unsigned long V_154 )
{
struct V_48 * V_49 = (struct V_48 * ) V_154 ;
struct V_142 * V_143 = V_49 -> V_142 ;
struct V_92 * V_106 ;
bool V_147 ;
do {
V_106 = V_143 [ 0 ] . V_93 ;
while ( V_106 && F_78 ( V_106 ) ) {
F_79 ( V_106 ) ;
F_80 ( V_106 ) ;
V_143 [ 0 ] . V_93 = V_143 [ 1 ] . V_93 ;
V_143 [ 1 ] . V_93 = NULL ;
V_106 = V_143 [ 0 ] . V_93 ;
}
V_147 = false ;
if ( ! V_143 [ 1 ] . V_93 )
V_147 = F_69 ( V_49 ) ;
} while ( V_147 );
}
struct V_155 * F_81 ( struct V_15 * V_11 , T_2 V_77 )
{
struct V_35 * V_36 = F_21 ( V_11 ) ;
struct V_156 * V_157 ;
struct V_155 * V_75 ;
int V_38 ;
V_157 = F_82 ( V_36 , V_77 ) ;
if ( F_83 ( V_157 ) )
return F_84 ( V_157 ) ;
V_75 = F_85 ( V_157 , & V_36 -> V_158 . V_20 , NULL ) ;
if ( F_83 ( V_75 ) )
goto V_29;
V_38 = F_86 ( V_75 , 0 , V_69 ,
V_159 | V_160 | V_161 ) ;
if ( V_38 ) {
V_75 = F_87 ( V_38 ) ;
goto V_29;
}
return V_75 ;
V_29:
F_88 ( V_157 ) ;
return V_75 ;
}
static bool F_89 ( struct V_15 * V_11 , T_1 V_24 )
{
struct V_35 * V_36 = F_21 ( V_11 ) ;
T_2 V_162 ;
bool V_163 ;
F_3 ( V_24 >= V_9 ) ;
V_162 = F_23 ( F_24 ( V_24 ) ) ;
V_163 = V_162 & V_37 ;
if ( F_18 ( V_24 , V_11 -> V_12 ) == V_163 )
return true ;
F_6 ( L_6 ,
V_24 , V_162 , F_7 ( V_163 ) ) ;
return false ;
}
static int F_90 ( struct V_1 * V_2 , T_1 V_24 )
{
int V_29 ;
F_15 ( V_2 , V_24 ) ;
V_29 = F_19 ( V_2 ) ;
if ( ! V_29 )
V_29 = F_20 ( V_2 ) ;
return V_29 ;
}
static int F_91 ( struct V_15 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_97 ;
bool V_164 = false ;
T_1 V_24 ;
int V_38 ;
F_92 (db_id, guc->doorbell_bitmap, GUC_NUM_DOORBELLS) {
if ( F_89 ( V_11 , V_24 ) )
continue;
if ( F_17 ( V_2 ) ) {
F_27 ( V_2 ) ;
V_164 = true ;
}
V_38 = F_90 ( V_2 , V_24 ) ;
F_93 ( V_38 , L_7 , V_24 , V_38 ) ;
}
if ( V_164 ) {
V_38 = F_2 ( V_2 ) ;
if ( F_94 ( V_38 ) ) {
F_95 ( L_8 , V_38 ) ;
return V_38 ;
}
F_15 ( V_2 , V_2 -> V_8 ) ;
}
{
V_38 = F_19 ( V_2 ) ;
if ( V_38 ) {
F_95 ( L_9 ,
V_2 -> V_14 , V_38 ) ;
return V_38 ;
}
}
for ( V_24 = 0 ; V_24 < V_10 ; ++ V_24 )
F_37 ( ! F_89 ( V_11 , V_24 ) ) ;
return 0 ;
}
static struct V_1 *
F_96 ( struct V_35 * V_36 ,
T_3 V_81 ,
T_3 V_3 ,
struct V_50 * V_51 )
{
struct V_1 * V_2 ;
struct V_15 * V_11 = & V_36 -> V_11 ;
struct V_155 * V_75 ;
void * V_26 ;
int V_38 ;
V_2 = F_97 ( sizeof( * V_2 ) , V_165 ) ;
if ( ! V_2 )
return F_87 ( - V_166 ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_52 = V_51 ;
V_2 -> V_81 = V_81 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_8 = V_9 ;
V_2 -> V_90 = V_112 ;
V_2 -> V_45 = V_167 ;
F_98 ( & V_2 -> V_99 ) ;
V_38 = F_99 ( & V_11 -> V_168 , 0 , V_169 ,
V_165 ) ;
if ( V_38 < 0 )
goto V_170;
V_2 -> V_14 = V_38 ;
V_75 = F_81 ( V_11 , V_112 + V_167 ) ;
if ( F_83 ( V_75 ) ) {
V_38 = F_100 ( V_75 ) ;
goto V_171;
}
V_2 -> V_75 = V_75 ;
V_26 = F_101 ( V_75 -> V_157 , V_172 ) ;
if ( F_83 ( V_26 ) ) {
V_38 = F_100 ( V_26 ) ;
goto V_173;
}
V_2 -> V_26 = V_26 ;
V_2 -> V_27 = F_28 ( V_11 ) ;
if ( V_2 -> V_27 >= ( V_112 / 2 ) )
V_2 -> V_41 = 0 ;
else
V_2 -> V_41 = ( V_112 / 2 ) ;
F_32 ( V_11 , V_2 ) ;
F_33 ( V_11 , V_2 ) ;
V_38 = F_26 ( V_2 ) ;
if ( V_38 )
goto V_174;
F_6 ( L_10 ,
V_3 , V_2 , V_2 -> V_81 , V_2 -> V_14 ) ;
F_6 ( L_11 ,
V_2 -> V_8 , V_2 -> V_27 ) ;
return V_2 ;
V_174:
F_102 ( V_2 -> V_75 -> V_157 ) ;
V_173:
F_103 ( & V_2 -> V_75 ) ;
V_171:
F_104 ( & V_11 -> V_168 , V_2 -> V_14 ) ;
V_170:
F_105 ( V_2 ) ;
return F_87 ( V_38 ) ;
}
static void F_106 ( struct V_1 * V_2 )
{
F_27 ( V_2 ) ;
F_39 ( V_2 -> V_11 , V_2 ) ;
F_102 ( V_2 -> V_75 -> V_157 ) ;
F_103 ( & V_2 -> V_75 ) ;
F_104 ( & V_2 -> V_11 -> V_168 , V_2 -> V_14 ) ;
F_105 ( V_2 ) ;
}
static void F_107 ( struct V_175 * V_176 )
{
struct V_177 * V_178 ;
T_2 V_179 , V_180 ;
V_176 -> V_181 = 500000 ;
V_176 -> V_182 = V_183 ;
for ( V_179 = 0 ; V_179 < V_184 ; V_179 ++ ) {
for ( V_180 = V_185 ; V_180 < V_186 ; V_180 ++ ) {
V_178 = & V_176 -> V_178 [ V_179 ] [ V_180 ] ;
V_178 -> V_187 = 1000000 ;
V_178 -> V_188 = 500000 ;
V_178 -> V_189 = 250000 ;
V_178 -> V_190 = 0 ;
}
}
V_176 -> V_191 = 1 ;
}
static int F_108 ( struct V_15 * V_11 )
{
struct V_35 * V_36 = F_21 ( V_11 ) ;
struct V_155 * V_75 ;
struct V_192 * V_192 ;
struct {
struct V_193 V_194 ;
struct V_175 V_176 ;
struct V_195 V_196 ;
T_5 V_197 [ V_198 * V_69 ] ;
} V_199 * V_200 ;
struct V_48 * V_49 ;
enum V_201 V_7 ;
T_2 V_20 ;
F_3 ( V_11 -> V_202 ) ;
V_75 = F_81 ( V_11 , F_109 ( sizeof( * V_200 ) ) ) ;
if ( F_83 ( V_75 ) )
return F_100 ( V_75 ) ;
V_11 -> V_202 = V_75 ;
V_192 = F_110 ( V_75 ) ;
V_200 = F_111 ( V_192 ) ;
F_107 ( & V_200 -> V_176 ) ;
F_112 (engine, dev_priv, id) {
V_200 -> V_196 . V_203 [ V_49 -> V_61 ] . V_204 =
V_49 -> V_205 + V_206 ;
V_200 -> V_196 . V_203 [ V_49 -> V_61 ] . V_207 = 0 ;
}
V_200 -> V_194 . V_208 =
V_36 -> V_49 [ V_209 ] -> V_210 . V_211 ;
F_112 (engine, dev_priv, id)
V_200 -> V_194 . V_212 [ V_49 -> V_61 ] =
F_113 ( V_49 ) ;
V_20 = F_36 ( V_75 ) ;
V_200 -> V_194 . V_213 = V_20 + F_114 ( V_200 , V_176 ) ;
V_200 -> V_194 . V_197 = V_20 + F_114 ( V_200 , V_197 ) ;
V_200 -> V_194 . V_214 = V_20 + F_114 ( V_200 , V_196 ) ;
F_115 ( V_192 ) ;
return 0 ;
}
static void F_116 ( struct V_15 * V_11 )
{
F_103 ( & V_11 -> V_202 ) ;
}
int F_117 ( struct V_35 * V_36 )
{
struct V_15 * V_11 = & V_36 -> V_11 ;
struct V_155 * V_75 ;
void * V_26 ;
int V_38 ;
if ( V_11 -> V_215 )
return 0 ;
V_75 = F_81 ( V_11 ,
F_109 ( sizeof( struct V_19 ) *
V_169 ) ) ;
if ( F_83 ( V_75 ) )
return F_100 ( V_75 ) ;
V_11 -> V_215 = V_75 ;
V_26 = F_101 ( V_11 -> V_215 -> V_157 , V_172 ) ;
if ( F_83 ( V_26 ) ) {
V_38 = F_100 ( V_26 ) ;
goto V_173;
}
V_11 -> V_21 = V_26 ;
V_38 = F_118 ( V_11 ) ;
if ( V_38 < 0 )
goto V_174;
V_38 = F_108 ( V_11 ) ;
if ( V_38 < 0 )
goto V_216;
F_119 ( & V_11 -> V_168 ) ;
return 0 ;
V_216:
F_120 ( V_11 ) ;
V_174:
F_102 ( V_11 -> V_215 -> V_157 ) ;
V_173:
F_103 ( & V_11 -> V_215 ) ;
return V_38 ;
}
void F_121 ( struct V_35 * V_36 )
{
struct V_15 * V_11 = & V_36 -> V_11 ;
F_122 ( & V_11 -> V_168 ) ;
F_116 ( V_11 ) ;
F_120 ( V_11 ) ;
F_102 ( V_11 -> V_215 -> V_157 ) ;
F_103 ( & V_11 -> V_215 ) ;
}
static void F_123 ( struct V_35 * V_36 )
{
struct V_48 * V_49 ;
enum V_201 V_7 ;
int V_217 ;
V_217 = F_124 ( V_218 ) ;
F_112 (engine, dev_priv, id)
F_125 ( F_126 ( V_49 ) , V_217 ) ;
V_217 = V_219 << V_220 |
V_219 << V_221 ;
F_125 ( V_222 , ~ V_217 ) ;
F_125 ( V_223 , ~ V_217 ) ;
F_125 ( V_224 , ~ V_217 ) ;
V_36 -> V_225 . V_226 |= V_227 ;
V_36 -> V_225 . V_226 &= ~ V_228 ;
}
static void F_127 ( struct V_35 * V_36 )
{
struct V_48 * V_49 ;
enum V_201 V_7 ;
int V_217 ;
V_217 = F_128 ( V_229 , V_230 ) ;
V_217 |= F_129 ( V_218 ) ;
F_112 (engine, dev_priv, id)
F_125 ( F_126 ( V_49 ) , V_217 ) ;
F_125 ( V_222 , 0 ) ;
F_125 ( V_223 , 0 ) ;
F_125 ( V_224 , 0 ) ;
V_36 -> V_225 . V_226 |= V_228 ;
V_36 -> V_225 . V_226 &= ~ V_227 ;
}
int F_130 ( struct V_35 * V_36 )
{
struct V_15 * V_11 = & V_36 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_97 ;
struct V_48 * V_49 ;
enum V_201 V_7 ;
int V_29 ;
if ( ! V_2 ) {
V_2 = F_96 ( V_36 ,
F_131 ( V_36 ) -> V_231 ,
V_232 ,
V_36 -> V_233 ) ;
if ( F_83 ( V_2 ) ) {
F_95 ( L_12 ) ;
return F_100 ( V_2 ) ;
}
V_11 -> V_97 = V_2 ;
}
V_29 = F_132 ( V_11 ) ;
if ( V_29 )
goto V_234;
F_54 ( V_2 ) ;
V_29 = F_91 ( V_11 ) ;
if ( V_29 )
goto V_234;
F_123 ( V_36 ) ;
F_112 (engine, dev_priv, id) {
const int V_94 = sizeof( struct V_95 ) ;
struct V_92 * V_106 ;
V_49 -> V_235 . V_236 = F_77 ;
F_133 ( V_237 , & V_49 -> V_238 ) ;
F_41 ( & V_49 -> V_148 -> V_140 ) ;
F_134 (rq, &engine->timeline->requests, link) {
F_45 ( V_2 , V_94 ) ;
F_58 ( V_106 ) ;
}
F_44 ( & V_49 -> V_148 -> V_140 ) ;
}
return 0 ;
V_234:
F_106 ( V_11 -> V_97 ) ;
V_11 -> V_97 = NULL ;
return V_29 ;
}
void F_135 ( struct V_35 * V_36 )
{
struct V_15 * V_11 = & V_36 -> V_11 ;
F_127 ( V_36 ) ;
F_136 ( V_36 ) ;
F_106 ( V_11 -> V_97 ) ;
V_11 -> V_97 = NULL ;
}
int F_137 ( struct V_35 * V_36 )
{
struct V_15 * V_11 = & V_36 -> V_11 ;
struct V_50 * V_51 ;
T_2 V_154 [ 3 ] ;
if ( V_11 -> V_239 . V_240 != V_241 )
return 0 ;
F_138 ( V_36 ) ;
V_51 = V_36 -> V_233 ;
V_154 [ 0 ] = V_242 ;
V_154 [ 1 ] = V_243 ;
V_154 [ 2 ] = F_36 ( V_51 -> V_49 [ V_209 ] . V_64 ) ;
return F_11 ( V_11 , V_154 , F_12 ( V_154 ) ) ;
}
int F_139 ( struct V_35 * V_36 )
{
struct V_15 * V_11 = & V_36 -> V_11 ;
struct V_50 * V_51 ;
T_2 V_154 [ 3 ] ;
if ( V_11 -> V_239 . V_240 != V_241 )
return 0 ;
if ( V_96 . V_244 >= 0 )
F_140 ( V_36 ) ;
V_51 = V_36 -> V_233 ;
V_154 [ 0 ] = V_245 ;
V_154 [ 1 ] = V_246 ;
V_154 [ 2 ] = F_36 ( V_51 -> V_49 [ V_209 ] . V_64 ) ;
return F_11 ( V_11 , V_154 , F_12 ( V_154 ) ) ;
}
