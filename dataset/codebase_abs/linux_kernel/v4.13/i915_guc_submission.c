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
V_7 = F_4 ( V_2 -> V_11 -> V_12 , V_6 , V_5 ) ;
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
F_47 ( & V_2 -> V_99 , V_105 ) ;
}
static void F_61 ( struct V_92 * V_106 )
{
F_62 ( V_106 ) ;
F_58 ( V_106 ) ;
}
static void F_63 ( struct V_92 * V_106 )
{
if ( F_64 ( V_134 ,
& V_106 -> V_135 . V_105 ) )
return;
F_3 ( F_18 ( V_136 , & V_106 -> V_135 . V_105 ) ) ;
F_65 ( & V_106 -> V_135 ) ;
F_66 ( & V_106 -> V_137 , V_138 ) ;
F_67 ( V_106 , true ) ;
F_68 ( & V_106 -> V_137 ) ;
}
static void F_69 ( struct V_139 * V_140 ,
struct V_92 * V_106 )
{
F_3 ( V_106 == F_70 ( V_140 ) ) ;
if ( F_71 ( V_140 ) )
F_72 ( F_70 ( V_140 ) ) ;
F_73 ( V_140 , F_74 ( V_106 ) ) ;
F_63 ( V_106 ) ;
}
static bool F_75 ( struct V_48 * V_49 )
{
struct V_139 * V_140 = V_49 -> V_139 ;
struct V_92 * V_141 = F_70 ( V_140 ) ;
struct V_142 * V_143 ;
bool V_144 = false ;
F_41 ( & V_49 -> V_145 -> V_137 ) ;
V_143 = V_49 -> V_146 ;
F_3 ( F_76 ( & V_49 -> V_147 ) != V_143 ) ;
while ( V_143 ) {
struct V_148 * V_149 = F_77 ( V_143 , F_78 ( * V_149 ) , V_150 ) ;
struct V_92 * V_106 , * V_151 ;
F_79 (rq, rn, &p->requests, priotree.link) {
if ( V_141 && V_106 -> V_51 != V_141 -> V_51 ) {
if ( V_140 != V_49 -> V_139 ) {
F_80 ( & V_149 -> V_152 ,
& V_106 -> V_153 . V_154 ) ;
goto V_155;
}
if ( V_144 )
F_69 ( V_140 , V_141 ) ;
V_140 ++ ;
}
F_81 ( & V_106 -> V_153 . V_154 ) ;
V_106 -> V_153 . V_3 = V_156 ;
F_61 ( V_106 ) ;
F_82 ( V_106 , F_83 ( V_140 , V_49 ) ) ;
V_141 = V_106 ;
V_144 = true ;
}
V_143 = F_84 ( V_143 ) ;
F_85 ( & V_149 -> V_150 , & V_49 -> V_147 ) ;
F_81 ( & V_149 -> V_152 ) ;
if ( V_149 -> V_3 != V_157 )
F_86 ( V_49 -> V_96 -> V_158 , V_149 ) ;
}
V_155:
V_49 -> V_146 = V_143 ;
if ( V_144 )
F_69 ( V_140 , V_141 ) ;
F_44 ( & V_49 -> V_145 -> V_137 ) ;
return V_144 ;
}
static void F_87 ( unsigned long V_159 )
{
struct V_48 * V_49 = (struct V_48 * ) V_159 ;
struct V_139 * V_140 = V_49 -> V_139 ;
struct V_92 * V_106 ;
bool V_144 ;
do {
V_106 = F_70 ( & V_140 [ 0 ] ) ;
while ( V_106 && F_88 ( V_106 ) ) {
F_89 ( V_106 ) ;
F_72 ( V_106 ) ;
V_140 [ 0 ] = V_140 [ 1 ] ;
memset ( & V_140 [ 1 ] , 0 , sizeof( V_140 [ 1 ] ) ) ;
V_106 = F_70 ( & V_140 [ 0 ] ) ;
}
V_144 = false ;
if ( ! F_90 ( & V_140 [ 1 ] ) )
V_144 = F_75 ( V_49 ) ;
} while ( V_144 );
}
struct V_160 * F_91 ( struct V_15 * V_11 , T_2 V_77 )
{
struct V_35 * V_36 = F_21 ( V_11 ) ;
struct V_161 * V_162 ;
struct V_160 * V_75 ;
int V_38 ;
V_162 = F_92 ( V_36 , V_77 ) ;
if ( F_93 ( V_162 ) )
return F_94 ( V_162 ) ;
V_75 = F_95 ( V_162 , & V_36 -> V_163 . V_20 , NULL ) ;
if ( F_93 ( V_75 ) )
goto V_29;
V_38 = F_96 ( V_75 , 0 , V_69 ,
V_164 | V_165 | V_166 ) ;
if ( V_38 ) {
V_75 = F_97 ( V_38 ) ;
goto V_29;
}
return V_75 ;
V_29:
F_98 ( V_162 ) ;
return V_75 ;
}
static bool F_99 ( struct V_15 * V_11 , T_1 V_24 )
{
struct V_35 * V_36 = F_21 ( V_11 ) ;
T_2 V_167 ;
bool V_168 ;
F_3 ( V_24 >= V_9 ) ;
V_167 = F_23 ( F_24 ( V_24 ) ) ;
V_168 = V_167 & V_37 ;
if ( F_18 ( V_24 , V_11 -> V_12 ) == V_168 )
return true ;
F_6 ( L_6 ,
V_24 , V_167 , F_7 ( V_168 ) ) ;
return false ;
}
static int F_100 ( struct V_1 * V_2 , T_1 V_24 )
{
int V_29 ;
F_15 ( V_2 , V_24 ) ;
V_29 = F_19 ( V_2 ) ;
if ( ! V_29 )
V_29 = F_20 ( V_2 ) ;
return V_29 ;
}
static int F_101 ( struct V_15 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_97 ;
bool V_169 = false ;
T_1 V_24 ;
int V_38 ;
F_102 (db_id, guc->doorbell_bitmap, GUC_NUM_DOORBELLS) {
if ( F_99 ( V_11 , V_24 ) )
continue;
if ( F_17 ( V_2 ) ) {
F_27 ( V_2 ) ;
V_169 = true ;
}
V_38 = F_100 ( V_2 , V_24 ) ;
F_103 ( V_38 , L_7 , V_24 , V_38 ) ;
}
if ( V_169 ) {
V_38 = F_2 ( V_2 ) ;
if ( F_104 ( V_38 ) ) {
F_105 ( L_8 , V_38 ) ;
return V_38 ;
}
F_15 ( V_2 , V_2 -> V_8 ) ;
}
{
V_38 = F_19 ( V_2 ) ;
if ( V_38 ) {
F_105 ( L_9 ,
V_2 -> V_14 , V_38 ) ;
return V_38 ;
}
}
for ( V_24 = 0 ; V_24 < V_10 ; ++ V_24 )
F_37 ( ! F_99 ( V_11 , V_24 ) ) ;
return 0 ;
}
static struct V_1 *
F_106 ( struct V_35 * V_36 ,
T_3 V_81 ,
T_3 V_3 ,
struct V_50 * V_51 )
{
struct V_1 * V_2 ;
struct V_15 * V_11 = & V_36 -> V_11 ;
struct V_160 * V_75 ;
void * V_26 ;
int V_38 ;
V_2 = F_107 ( sizeof( * V_2 ) , V_170 ) ;
if ( ! V_2 )
return F_97 ( - V_171 ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_52 = V_51 ;
V_2 -> V_81 = V_81 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_8 = V_9 ;
V_2 -> V_90 = V_112 ;
V_2 -> V_45 = V_172 ;
F_108 ( & V_2 -> V_99 ) ;
V_38 = F_109 ( & V_11 -> V_173 , 0 , V_174 ,
V_170 ) ;
if ( V_38 < 0 )
goto V_175;
V_2 -> V_14 = V_38 ;
V_75 = F_91 ( V_11 , V_112 + V_172 ) ;
if ( F_93 ( V_75 ) ) {
V_38 = F_110 ( V_75 ) ;
goto V_176;
}
V_2 -> V_75 = V_75 ;
V_26 = F_111 ( V_75 -> V_162 , V_177 ) ;
if ( F_93 ( V_26 ) ) {
V_38 = F_110 ( V_26 ) ;
goto V_178;
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
goto V_179;
F_6 ( L_10 ,
V_3 , V_2 , V_2 -> V_81 , V_2 -> V_14 ) ;
F_6 ( L_11 ,
V_2 -> V_8 , V_2 -> V_27 ) ;
return V_2 ;
V_179:
F_112 ( V_2 -> V_75 -> V_162 ) ;
V_178:
F_113 ( & V_2 -> V_75 ) ;
V_176:
F_114 ( & V_11 -> V_173 , V_2 -> V_14 ) ;
V_175:
F_115 ( V_2 ) ;
return F_97 ( V_38 ) ;
}
static void F_116 ( struct V_1 * V_2 )
{
F_27 ( V_2 ) ;
F_39 ( V_2 -> V_11 , V_2 ) ;
F_112 ( V_2 -> V_75 -> V_162 ) ;
F_113 ( & V_2 -> V_75 ) ;
F_114 ( & V_2 -> V_11 -> V_173 , V_2 -> V_14 ) ;
F_115 ( V_2 ) ;
}
static void F_117 ( struct V_180 * V_181 )
{
struct V_182 * V_183 ;
T_2 V_149 , V_184 ;
V_181 -> V_185 = 500000 ;
V_181 -> V_186 = V_187 ;
for ( V_149 = 0 ; V_149 < V_188 ; V_149 ++ ) {
for ( V_184 = V_189 ; V_184 < V_190 ; V_184 ++ ) {
V_183 = & V_181 -> V_183 [ V_149 ] [ V_184 ] ;
V_183 -> V_191 = 1000000 ;
V_183 -> V_192 = 500000 ;
V_183 -> V_193 = 250000 ;
V_183 -> V_194 = 0 ;
}
}
V_181 -> V_195 = 1 ;
}
static int F_118 ( struct V_15 * V_11 )
{
struct V_35 * V_36 = F_21 ( V_11 ) ;
struct V_160 * V_75 ;
struct V_196 * V_196 ;
struct {
struct V_197 V_198 ;
struct V_180 V_181 ;
struct V_199 V_200 ;
T_5 V_201 [ V_202 * V_69 ] ;
} V_203 * V_204 ;
struct V_48 * V_49 ;
enum V_205 V_7 ;
T_2 V_20 ;
F_3 ( V_11 -> V_206 ) ;
V_75 = F_91 ( V_11 , F_119 ( sizeof( * V_204 ) ) ) ;
if ( F_93 ( V_75 ) )
return F_110 ( V_75 ) ;
V_11 -> V_206 = V_75 ;
V_196 = F_120 ( V_75 ) ;
V_204 = F_121 ( V_196 ) ;
F_117 ( & V_204 -> V_181 ) ;
F_122 (engine, dev_priv, id) {
V_204 -> V_200 . V_207 [ V_49 -> V_61 ] . V_208 =
V_49 -> V_209 + V_210 ;
V_204 -> V_200 . V_207 [ V_49 -> V_61 ] . V_211 = 0 ;
}
V_204 -> V_198 . V_212 =
V_36 -> V_49 [ V_213 ] -> V_214 . V_215 ;
F_122 (engine, dev_priv, id)
V_204 -> V_198 . V_216 [ V_49 -> V_61 ] = V_49 -> V_217 ;
V_20 = F_36 ( V_75 ) ;
V_204 -> V_198 . V_218 = V_20 + F_123 ( V_204 , V_181 ) ;
V_204 -> V_198 . V_201 = V_20 + F_123 ( V_204 , V_201 ) ;
V_204 -> V_198 . V_219 = V_20 + F_123 ( V_204 , V_200 ) ;
F_124 ( V_196 ) ;
return 0 ;
}
static void F_125 ( struct V_15 * V_11 )
{
F_113 ( & V_11 -> V_206 ) ;
}
int F_126 ( struct V_35 * V_36 )
{
struct V_15 * V_11 = & V_36 -> V_11 ;
struct V_160 * V_75 ;
void * V_26 ;
int V_38 ;
if ( V_11 -> V_220 )
return 0 ;
V_75 = F_91 ( V_11 ,
F_119 ( sizeof( struct V_19 ) *
V_174 ) ) ;
if ( F_93 ( V_75 ) )
return F_110 ( V_75 ) ;
V_11 -> V_220 = V_75 ;
V_26 = F_111 ( V_11 -> V_220 -> V_162 , V_177 ) ;
if ( F_93 ( V_26 ) ) {
V_38 = F_110 ( V_26 ) ;
goto V_178;
}
V_11 -> V_21 = V_26 ;
V_38 = F_127 ( V_11 ) ;
if ( V_38 < 0 )
goto V_179;
V_38 = F_118 ( V_11 ) ;
if ( V_38 < 0 )
goto V_221;
F_128 ( & V_11 -> V_173 ) ;
return 0 ;
V_221:
F_129 ( V_11 ) ;
V_179:
F_112 ( V_11 -> V_220 -> V_162 ) ;
V_178:
F_113 ( & V_11 -> V_220 ) ;
return V_38 ;
}
void F_130 ( struct V_35 * V_36 )
{
struct V_15 * V_11 = & V_36 -> V_11 ;
F_131 ( & V_11 -> V_173 ) ;
F_125 ( V_11 ) ;
F_129 ( V_11 ) ;
F_112 ( V_11 -> V_220 -> V_162 ) ;
F_113 ( & V_11 -> V_220 ) ;
}
static void F_132 ( struct V_35 * V_36 )
{
struct V_48 * V_49 ;
enum V_205 V_7 ;
int V_222 ;
V_222 = F_133 ( V_223 ) ;
F_122 (engine, dev_priv, id)
F_134 ( F_135 ( V_49 ) , V_222 ) ;
V_222 = V_224 << V_225 |
V_224 << V_226 ;
F_134 ( V_227 , ~ V_222 ) ;
F_134 ( V_228 , ~ V_222 ) ;
F_134 ( V_229 , ~ V_222 ) ;
V_36 -> V_230 . V_231 |= V_232 ;
V_36 -> V_230 . V_231 &= ~ V_233 ;
}
static void F_136 ( struct V_35 * V_36 )
{
struct V_48 * V_49 ;
enum V_205 V_7 ;
int V_222 ;
V_222 = F_137 ( V_234 , V_235 ) ;
V_222 |= F_138 ( V_223 ) ;
F_122 (engine, dev_priv, id)
F_134 ( F_135 ( V_49 ) , V_222 ) ;
F_134 ( V_227 , 0 ) ;
F_134 ( V_228 , 0 ) ;
F_134 ( V_229 , 0 ) ;
V_36 -> V_230 . V_231 |= V_233 ;
V_36 -> V_230 . V_231 &= ~ V_232 ;
}
int F_139 ( struct V_35 * V_36 )
{
struct V_15 * V_11 = & V_36 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_97 ;
struct V_48 * V_49 ;
enum V_205 V_7 ;
int V_29 ;
if ( ! V_2 ) {
V_2 = F_106 ( V_36 ,
F_140 ( V_36 ) -> V_236 ,
V_237 ,
V_36 -> V_238 ) ;
if ( F_93 ( V_2 ) ) {
F_105 ( L_12 ) ;
return F_110 ( V_2 ) ;
}
V_11 -> V_97 = V_2 ;
}
V_29 = F_141 ( V_11 ) ;
if ( V_29 )
goto V_239;
F_54 ( V_2 ) ;
V_29 = F_101 ( V_11 ) ;
if ( V_29 )
goto V_239;
F_132 ( V_36 ) ;
F_122 (engine, dev_priv, id) {
const int V_94 = sizeof( struct V_95 ) ;
struct V_92 * V_106 ;
V_49 -> V_240 . V_241 = F_87 ;
F_142 ( V_242 , & V_49 -> V_243 ) ;
F_41 ( & V_49 -> V_145 -> V_137 ) ;
F_143 (rq, &engine->timeline->requests, link) {
F_45 ( V_2 , V_94 ) ;
F_58 ( V_106 ) ;
}
F_44 ( & V_49 -> V_145 -> V_137 ) ;
}
return 0 ;
V_239:
F_116 ( V_11 -> V_97 ) ;
V_11 -> V_97 = NULL ;
return V_29 ;
}
void F_144 ( struct V_35 * V_36 )
{
struct V_15 * V_11 = & V_36 -> V_11 ;
F_136 ( V_36 ) ;
F_145 ( V_36 ) ;
F_116 ( V_11 -> V_97 ) ;
V_11 -> V_97 = NULL ;
}
int F_146 ( struct V_35 * V_36 )
{
struct V_15 * V_11 = & V_36 -> V_11 ;
struct V_50 * V_51 ;
T_2 V_159 [ 3 ] ;
if ( V_11 -> V_244 . V_245 != V_246 )
return 0 ;
F_147 ( V_36 ) ;
V_51 = V_36 -> V_238 ;
V_159 [ 0 ] = V_247 ;
V_159 [ 1 ] = V_248 ;
V_159 [ 2 ] = F_36 ( V_51 -> V_49 [ V_213 ] . V_64 ) ;
return F_11 ( V_11 , V_159 , F_12 ( V_159 ) ) ;
}
int F_148 ( struct V_35 * V_36 )
{
struct V_15 * V_11 = & V_36 -> V_11 ;
struct V_50 * V_51 ;
T_2 V_159 [ 3 ] ;
if ( V_11 -> V_244 . V_245 != V_246 )
return 0 ;
if ( V_96 . V_249 >= 0 )
F_149 ( V_36 ) ;
V_51 = V_36 -> V_238 ;
V_159 [ 0 ] = V_250 ;
V_159 [ 1 ] = V_251 ;
V_159 [ 2 ] = F_36 ( V_51 -> V_49 [ V_213 ] . V_64 ) ;
return F_11 ( V_11 , V_159 , F_12 ( V_159 ) ) ;
}
