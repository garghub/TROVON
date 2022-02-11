static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
T_3 V_8 ;
V_8 = V_7 -> V_9 ;
F_1 ( V_2 , V_10 , V_8 ) ;
V_8 = V_7 -> V_11 ;
F_1 ( V_2 , V_12 , V_8 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
void * V_7 )
{
struct V_13 * V_14 = (struct V_13 * ) V_7 ;
V_14 -> V_15 |= V_16 ;
V_14 ++ ;
V_14 -> V_15 |= V_17 | V_16 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_13 * V_18 ,
T_3 V_19 , T_3 V_20 , T_4 V_21 ,
struct V_13 * V_22 )
{
struct V_13 * V_23 = V_18 + 1 ;
V_18 -> V_24 = V_23 -> V_24 = V_21 ;
V_18 -> V_8 = V_19 ;
V_23 -> V_8 = V_20 ;
V_18 -> V_15 = V_23 -> V_15 = V_25 ;
if ( V_2 -> V_26 ) {
V_18 -> V_15 |= V_27 ;
V_23 -> V_15 |= V_27 ;
}
if ( V_22 ) {
T_3 V_8 = V_2 -> V_28 +
( ( V_29 ) V_18 - ( V_29 ) V_2 -> V_30 ) ;
V_23 = V_22 + 1 ;
V_22 -> V_31 = V_8 ;
V_23 -> V_31 = V_8 + F_6 ( V_2 ) ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_32 ;
F_8 ( V_33 , V_2 -> V_5 + V_34 ) ;
V_32 = F_9 ( V_2 -> V_5 + V_35 ) ;
F_8 ( V_32 , V_2 -> V_5 + V_35 ) ;
if ( V_2 -> V_26 ) {
V_32 = V_36 ;
V_32 = ( V_32 & ~ V_37 ) |
( V_38 << V_39 ) ;
F_8 ( V_32 , V_2 -> V_5 + V_40 ) ;
}
V_32 = F_9 ( V_2 -> V_5 + V_41 ) ;
if ( V_2 -> V_26 ) {
V_32 = ( V_32 & ~ V_42 ) |
( V_38 << V_43 ) ;
V_32 = ( V_32 & ~ V_44 ) |
( V_38 << V_45 ) ;
}
F_8 ( V_32 , V_2 -> V_5 + V_41 ) ;
V_32 = F_9 ( V_2 -> V_5 + V_46 ) ;
V_32 = F_9 ( V_2 -> V_5 + V_47 ) ;
V_2 -> V_48 = true ;
}
static T_5 F_10 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_11 ( V_50 -> V_2 ) ;
struct V_6 * V_7 , * V_51 ;
T_5 V_52 ;
V_51 = F_12 ( V_50 ) ;
F_13 ( & V_2 -> V_53 ) ;
V_52 = F_14 ( V_50 ) ;
if ( ! F_15 ( & V_2 -> V_54 ) ) {
V_7 = F_16 ( & V_2 -> V_54 ,
struct V_6 , V_55 ) ;
if ( ! F_15 ( & V_7 -> V_56 ) )
V_7 = F_16 ( & V_7 -> V_56 ,
struct V_6 , V_55 ) ;
V_7 -> V_57 -> V_31 = V_51 -> V_9 ;
V_7 -> V_57 -> V_15 &= ~ V_16 ;
V_7 -> V_58 -> V_31 = V_51 -> V_11 ;
V_7 -> V_58 -> V_15 &= ~ V_16 ;
}
F_17 ( & V_51 -> V_55 , & V_2 -> V_54 ) ;
F_18 ( & V_2 -> V_53 ) ;
return V_52 ;
}
static struct V_6 *
F_19 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
F_13 ( & V_2 -> V_53 ) ;
V_7 = F_20 ( & V_2 -> V_59 ,
struct V_6 , V_55 ) ;
F_21 ( & V_7 -> V_55 ) ;
F_18 ( & V_2 -> V_53 ) ;
F_22 ( & V_7 -> V_56 ) ;
memset ( ( void * ) V_7 -> V_57 , 0 , F_6 ( V_2 ) ) ;
memset ( ( void * ) V_7 -> V_58 , 0 , F_6 ( V_2 ) ) ;
return V_7 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_6 * V_18 )
{
struct V_6 * V_60 , * V_61 ;
V_2 -> V_62 ++ ;
F_17 ( & V_18 -> V_55 , & V_2 -> V_59 ) ;
F_24 (child, next, &sdesc->tx_list, node) {
V_2 -> V_62 ++ ;
F_25 ( & V_60 -> V_55 , & V_2 -> V_59 ) ;
}
}
static void F_26 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_6 * V_7 , * V_61 ;
F_24 (desc, next, list, node)
F_23 ( V_2 , V_7 ) ;
}
static int F_27 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_11 ( V_66 ) ;
struct V_6 * V_7 ;
int V_67 ;
V_2 -> V_68 = F_28 ( sizeof( * V_7 ) * V_69 ,
V_70 ) ;
if ( ! V_2 -> V_68 )
return - V_71 ;
V_2 -> V_48 = true ;
V_2 -> V_62 = V_69 ;
F_22 ( & V_2 -> V_59 ) ;
for ( V_67 = 0 ; V_67 < V_69 ; V_67 ++ ) {
V_7 = V_2 -> V_68 + V_67 ;
F_29 ( & V_7 -> V_72 , & V_2 -> V_73 ) ;
V_7 -> V_72 . V_74 = F_10 ;
F_17 ( & V_7 -> V_55 , & V_2 -> V_59 ) ;
}
V_2 -> V_30 = F_30 ( V_2 -> V_75 ,
( 2 * V_2 -> V_76 * V_69 ) ,
& V_2 -> V_28 , V_70 ) ;
if ( ! V_2 -> V_30 )
return - V_71 ;
for ( V_67 = 0 ; V_67 < V_69 ; V_67 ++ ) {
V_7 = V_2 -> V_68 + V_67 ;
V_7 -> V_57 = (struct V_13 * ) ( V_2 -> V_30 +
( V_67 * F_6 ( V_2 ) * 2 ) ) ;
V_7 -> V_58 = (struct V_13 * ) ( V_7 -> V_57 + 1 ) ;
V_7 -> V_9 = V_2 -> V_28 +
( V_67 * F_6 ( V_2 ) * 2 ) ;
V_7 -> V_11 = V_7 -> V_9 + F_6 ( V_2 ) ;
}
return V_69 ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_8 ( V_77 , V_2 -> V_5 + V_78 ) ;
V_2 -> V_48 = false ;
F_8 ( V_79 , V_2 -> V_5 + V_80 ) ;
}
static void F_32 ( struct V_1 * V_2 , T_1 V_81 )
{
T_1 V_32 ;
if ( V_81 & V_82 )
V_32 = F_9 ( V_2 -> V_5 + V_47 ) ;
if ( V_81 & V_83 )
V_32 = F_9 ( V_2 -> V_5 + V_46 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
T_1 V_32 ;
V_32 = F_9 ( V_2 -> V_5 + V_84 ) ;
V_32 |= V_85 ;
F_8 ( V_32 , V_2 -> V_5 + V_84 ) ;
V_32 = F_9 ( V_2 -> V_5 + V_41 ) ;
V_32 = ( V_32 & ~ V_86 ) |
( V_2 -> V_87 << V_88 ) ;
V_32 = ( V_32 & ~ V_89 ) |
( V_2 -> V_90 << V_91 ) ;
F_8 ( V_32 , V_2 -> V_5 + V_41 ) ;
}
static int F_34 ( struct V_65 * V_66 ,
struct V_92 * V_93 )
{
struct V_1 * V_2 = F_11 ( V_66 ) ;
V_2 -> V_87 = V_93 -> V_94 ;
V_2 -> V_90 = V_93 -> V_95 ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
if ( ! V_2 -> V_48 )
return;
F_33 ( V_2 ) ;
V_7 = F_36 ( & V_2 -> V_54 ,
struct V_6 , V_55 ) ;
if ( ! V_7 )
return;
F_37 ( & V_2 -> V_54 , & V_2 -> V_96 ) ;
F_3 ( V_2 , V_7 ) ;
F_31 ( V_2 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_6 * V_7 , * V_61 ;
F_24 (desc, next, &chan->done_list, node) {
T_6 V_97 ;
void * V_98 ;
F_21 ( & V_7 -> V_55 ) ;
V_97 = V_7 -> V_72 . V_97 ;
V_98 = V_7 -> V_72 . V_98 ;
if ( V_97 ) {
F_39 ( & V_2 -> V_53 ) ;
V_97 ( V_98 ) ;
F_40 ( & V_2 -> V_53 ) ;
}
F_23 ( V_2 , V_7 ) ;
}
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
V_7 = F_36 ( & V_2 -> V_96 ,
struct V_6 , V_55 ) ;
if ( ! V_7 )
return;
F_21 ( & V_7 -> V_55 ) ;
F_42 ( & V_7 -> V_72 ) ;
F_17 ( & V_7 -> V_55 , & V_2 -> V_99 ) ;
}
static void F_43 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_11 ( V_66 ) ;
F_13 ( & V_2 -> V_53 ) ;
F_35 ( V_2 ) ;
F_18 ( & V_2 -> V_53 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_26 ( V_2 , & V_2 -> V_96 ) ;
F_26 ( V_2 , & V_2 -> V_54 ) ;
F_26 ( V_2 , & V_2 -> V_99 ) ;
}
static void F_45 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_11 ( V_66 ) ;
F_13 ( & V_2 -> V_53 ) ;
F_44 ( V_2 ) ;
F_18 ( & V_2 -> V_53 ) ;
F_46 ( V_2 -> V_75 ,
( 2 * F_6 ( V_2 ) * V_69 ) ,
V_2 -> V_30 , V_2 -> V_28 ) ;
F_47 ( V_2 -> V_68 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_8 ( V_33 , V_2 -> V_5 + V_34 ) ;
F_41 ( V_2 ) ;
F_38 ( V_2 ) ;
F_44 ( V_2 ) ;
F_7 ( V_2 ) ;
}
static T_7 F_49 ( int V_100 , void * V_101 )
{
struct V_1 * V_2 = (struct V_1 * ) V_101 ;
T_1 V_102 , V_103 , V_81 ;
T_7 V_104 = V_105 ;
V_102 = F_9 ( V_2 -> V_5 + V_35 ) ;
V_103 = F_9 ( V_2 -> V_5 + V_106 ) ;
V_81 = V_102 & ~ V_103 ;
F_8 ( V_102 , V_2 -> V_5 + V_35 ) ;
if ( V_81 & V_107 ) {
F_50 ( & V_2 -> V_108 ) ;
V_104 = V_109 ;
}
if ( V_81 & V_110 )
V_2 -> V_48 = true ;
if ( V_81 & V_111 ) {
V_2 -> V_112 = true ;
F_50 ( & V_2 -> V_108 ) ;
F_51 ( V_2 -> V_75 , L_1 , V_2 ) ;
V_104 = V_109 ;
}
if ( V_81 & V_113 ) {
F_32 ( V_2 , V_81 ) ;
F_52 ( V_2 -> V_75 , L_2 , V_2 ) ;
V_104 = V_109 ;
}
return V_104 ;
}
static void F_53 ( unsigned long V_101 )
{
struct V_1 * V_2 = (struct V_1 * ) V_101 ;
T_1 V_114 ;
F_40 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_112 ) {
F_48 ( V_2 ) ;
V_2 -> V_112 = false ;
goto V_115;
}
V_114 = F_9 ( V_2 -> V_5 + V_47 ) ;
while ( V_114 ) {
F_41 ( V_2 ) ;
F_38 ( V_2 ) ;
V_114 -- ;
}
if ( V_2 -> V_48 )
F_35 ( V_2 ) ;
V_115:
F_39 ( & V_2 -> V_53 ) ;
}
static int F_54 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_11 ( V_66 ) ;
F_13 ( & V_2 -> V_53 ) ;
F_8 ( V_33 , V_2 -> V_5 + V_34 ) ;
F_44 ( V_2 ) ;
F_18 ( & V_2 -> V_53 ) ;
return 0 ;
}
static struct V_49 * F_55 (
struct V_65 * V_66 , T_3 V_116 ,
T_3 V_117 , T_4 V_21 , T_8 V_118 )
{
struct V_1 * V_2 ;
struct V_6 * V_51 , * V_119 = NULL ;
void * V_7 = NULL , * V_22 = NULL ;
T_4 V_120 ;
T_1 V_121 ;
V_2 = F_11 ( V_66 ) ;
V_121 = F_56 ( V_21 , V_122 ) ;
F_13 ( & V_2 -> V_53 ) ;
if ( V_121 > V_2 -> V_62 ) {
F_18 ( & V_2 -> V_53 ) ;
F_57 ( V_2 -> V_75 , L_3 , V_2 ) ;
return NULL ;
}
V_2 -> V_62 = V_2 -> V_62 - V_121 ;
F_18 ( & V_2 -> V_53 ) ;
do {
V_51 = F_19 ( V_2 ) ;
V_120 = F_58 ( T_4 , V_21 , V_122 ) ;
V_7 = (struct V_13 * ) V_51 -> V_57 ;
F_5 ( V_2 , V_7 , V_117 ,
V_116 , V_120 , V_22 ) ;
V_22 = V_7 ;
V_21 -= V_120 ;
V_117 += V_120 ;
V_116 += V_120 ;
if ( ! V_119 )
V_119 = V_51 ;
else
F_17 ( & V_51 -> V_55 , & V_119 -> V_56 ) ;
} while ( V_21 );
F_4 ( V_2 , V_7 ) ;
F_59 ( & V_119 -> V_72 ) ;
V_119 -> V_72 . V_118 = V_118 ;
return & V_119 -> V_72 ;
}
static struct V_49 * F_60 (
struct V_65 * V_66 , struct V_123 * V_124 ,
unsigned int V_125 , struct V_123 * V_126 ,
unsigned int V_127 , unsigned long V_118 )
{
struct V_6 * V_51 , * V_119 = NULL ;
struct V_1 * V_2 = F_11 ( V_66 ) ;
void * V_7 = NULL , * V_22 = NULL ;
T_4 V_21 , V_128 , V_129 ;
T_3 V_116 , V_117 ;
T_1 V_121 = 0 , V_67 ;
struct V_123 * V_130 ;
F_61 (src_sg, sg, src_sg_len, i)
V_121 += F_56 ( F_62 ( V_130 ) ,
V_122 ) ;
F_13 ( & V_2 -> V_53 ) ;
if ( V_121 > V_2 -> V_62 ) {
F_18 ( & V_2 -> V_53 ) ;
F_57 ( V_2 -> V_75 , L_3 , V_2 ) ;
return NULL ;
}
V_2 -> V_62 = V_2 -> V_62 - V_121 ;
F_18 ( & V_2 -> V_53 ) ;
V_128 = F_62 ( V_124 ) ;
V_129 = F_62 ( V_126 ) ;
while ( true ) {
V_51 = F_19 ( V_2 ) ;
V_7 = (struct V_13 * ) V_51 -> V_57 ;
V_21 = F_58 ( T_4 , V_129 , V_128 ) ;
V_21 = F_58 ( T_4 , V_21 , V_122 ) ;
if ( V_21 == 0 )
goto V_131;
V_116 = F_63 ( V_124 ) + F_62 ( V_124 ) -
V_128 ;
V_117 = F_63 ( V_126 ) + F_62 ( V_126 ) -
V_129 ;
F_5 ( V_2 , V_7 , V_117 , V_116 ,
V_21 , V_22 ) ;
V_22 = V_7 ;
V_128 -= V_21 ;
V_129 -= V_21 ;
if ( ! V_119 )
V_119 = V_51 ;
else
F_17 ( & V_51 -> V_55 , & V_119 -> V_56 ) ;
V_131:
if ( V_128 == 0 ) {
if ( V_125 == 0 )
break;
V_124 = F_64 ( V_124 ) ;
if ( V_124 == NULL )
break;
V_125 -- ;
V_128 = F_62 ( V_124 ) ;
}
if ( V_129 == 0 ) {
if ( V_127 == 0 )
break;
V_126 = F_64 ( V_126 ) ;
if ( V_126 == NULL )
break;
V_127 -- ;
V_129 = F_62 ( V_126 ) ;
}
}
F_4 ( V_2 , V_7 ) ;
V_119 -> V_72 . V_118 = V_118 ;
return & V_119 -> V_72 ;
}
static void F_65 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_66 ( V_2 -> V_132 -> V_75 , V_2 -> V_100 , V_2 ) ;
F_67 ( & V_2 -> V_108 ) ;
F_21 ( & V_2 -> V_73 . V_133 ) ;
F_68 ( V_2 -> V_134 ) ;
F_68 ( V_2 -> V_135 ) ;
}
static int F_69 ( struct V_136 * V_132 ,
struct V_137 * V_138 )
{
struct V_1 * V_2 ;
struct V_139 * V_140 ;
struct V_133 * V_55 = V_138 -> V_75 . V_141 ;
int V_112 ;
V_2 = F_70 ( V_132 -> V_75 , sizeof( * V_2 ) , V_70 ) ;
if ( ! V_2 )
return - V_71 ;
V_2 -> V_75 = V_132 -> V_75 ;
V_2 -> V_132 = V_132 ;
V_140 = F_71 ( V_138 , V_142 , 0 ) ;
V_2 -> V_5 = F_72 ( & V_138 -> V_75 , V_140 ) ;
if ( F_73 ( V_2 -> V_5 ) )
return F_74 ( V_2 -> V_5 ) ;
V_2 -> V_143 = V_144 ;
V_2 -> V_90 = V_145 ;
V_2 -> V_87 = V_146 ;
V_112 = F_75 ( V_55 , L_4 , & V_2 -> V_143 ) ;
if ( V_112 < 0 ) {
F_51 ( & V_138 -> V_75 , L_5 ) ;
return V_112 ;
}
if ( V_2 -> V_143 != V_144 &&
V_2 -> V_143 != V_147 ) {
F_51 ( V_132 -> V_75 , L_6 ) ;
return - V_148 ;
}
V_2 -> V_26 = F_76 ( V_55 , L_7 ) ;
V_132 -> V_2 = V_2 ;
F_77 ( & V_2 -> V_108 , F_53 , ( T_8 ) V_2 ) ;
F_78 ( & V_2 -> V_53 ) ;
F_22 ( & V_2 -> V_96 ) ;
F_22 ( & V_2 -> V_54 ) ;
F_22 ( & V_2 -> V_99 ) ;
F_22 ( & V_2 -> V_59 ) ;
F_79 ( & V_2 -> V_73 ) ;
V_2 -> V_73 . V_149 = & V_132 -> V_73 ;
F_17 ( & V_2 -> V_73 . V_133 , & V_132 -> V_73 . V_150 ) ;
F_7 ( V_2 ) ;
V_2 -> V_100 = F_80 ( V_138 , 0 ) ;
if ( V_2 -> V_100 < 0 )
return - V_151 ;
V_112 = F_81 ( & V_138 -> V_75 , V_2 -> V_100 , F_49 , 0 ,
L_8 , V_2 ) ;
if ( V_112 )
return V_112 ;
V_2 -> V_135 = F_82 ( & V_138 -> V_75 , L_9 ) ;
if ( F_73 ( V_2 -> V_135 ) ) {
F_51 ( & V_138 -> V_75 , L_10 ) ;
return F_74 ( V_2 -> V_135 ) ;
}
V_2 -> V_134 = F_82 ( & V_138 -> V_75 , L_11 ) ;
if ( F_73 ( V_2 -> V_134 ) ) {
F_51 ( & V_138 -> V_75 , L_12 ) ;
return F_74 ( V_2 -> V_134 ) ;
}
V_112 = F_83 ( V_2 -> V_135 ) ;
if ( V_112 ) {
F_51 ( & V_138 -> V_75 , L_13 ) ;
return V_112 ;
}
V_112 = F_83 ( V_2 -> V_134 ) ;
if ( V_112 ) {
F_68 ( V_2 -> V_135 ) ;
F_51 ( & V_138 -> V_75 , L_14 ) ;
return V_112 ;
}
V_2 -> V_76 = sizeof( struct V_13 ) ;
V_2 -> V_48 = true ;
return 0 ;
}
static struct V_65 * F_84 ( struct V_152 * V_153 ,
struct V_154 * V_155 )
{
struct V_136 * V_132 = V_155 -> V_156 ;
return F_85 ( & V_132 -> V_2 -> V_73 ) ;
}
static int F_86 ( struct V_137 * V_138 )
{
struct V_136 * V_132 ;
struct V_157 * V_158 ;
int V_104 ;
V_132 = F_70 ( & V_138 -> V_75 , sizeof( * V_132 ) , V_70 ) ;
if ( ! V_132 )
return - V_71 ;
V_132 -> V_75 = & V_138 -> V_75 ;
F_22 ( & V_132 -> V_73 . V_150 ) ;
F_87 ( & V_138 -> V_75 , F_88 ( 44 ) ) ;
F_89 ( V_159 , V_132 -> V_73 . V_160 ) ;
F_89 ( V_161 , V_132 -> V_73 . V_160 ) ;
V_158 = & V_132 -> V_73 ;
V_158 -> V_162 = F_60 ;
V_158 -> V_163 = F_55 ;
V_158 -> V_164 = F_54 ;
V_158 -> V_165 = F_43 ;
V_158 -> V_166 = F_27 ;
V_158 -> V_167 = F_45 ;
V_158 -> V_168 = V_169 ;
V_158 -> V_170 = F_34 ;
V_158 -> V_75 = & V_138 -> V_75 ;
F_90 ( V_138 , V_132 ) ;
V_104 = F_69 ( V_132 , V_138 ) ;
if ( V_104 ) {
F_51 ( & V_138 -> V_75 , L_15 ) ;
goto V_171;
}
V_158 -> V_172 = F_91 ( V_132 -> V_2 -> V_143 / 8 ) ;
V_158 -> V_173 = F_91 ( V_132 -> V_2 -> V_143 / 8 ) ;
F_92 ( & V_132 -> V_73 ) ;
V_104 = F_93 ( V_138 -> V_75 . V_141 ,
F_84 , V_132 ) ;
if ( V_104 ) {
F_51 ( & V_138 -> V_75 , L_16 ) ;
F_94 ( & V_132 -> V_73 ) ;
goto V_171;
}
F_52 ( & V_138 -> V_75 , L_17 ) ;
return 0 ;
V_171:
F_65 ( V_132 -> V_2 ) ;
return V_104 ;
}
static int F_95 ( struct V_137 * V_138 )
{
struct V_136 * V_132 = F_96 ( V_138 ) ;
F_97 ( V_138 -> V_75 . V_141 ) ;
F_94 ( & V_132 -> V_73 ) ;
F_65 ( V_132 -> V_2 ) ;
return 0 ;
}
