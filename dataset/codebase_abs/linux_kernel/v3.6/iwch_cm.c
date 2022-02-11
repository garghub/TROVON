static void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 , V_3 , V_2 ) ;
if ( F_3 ( & V_2 -> V_4 ) ) {
F_2 ( L_2 , V_3 , V_2 ) ;
F_4 ( & V_2 -> V_4 ) ;
} else
F_5 ( & V_2 -> V_5 ) ;
V_2 -> V_4 . V_6 = V_7 + V_8 * V_9 ;
V_2 -> V_4 . V_10 = ( unsigned long ) V_2 ;
V_2 -> V_4 . V_11 = V_12 ;
F_6 ( & V_2 -> V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_2 ( L_1 , V_3 , V_2 ) ;
if ( ! F_3 ( & V_2 -> V_4 ) ) {
F_8 ( V_13 L_3 ,
V_3 , V_2 , V_2 -> V_5 . V_14 ) ;
F_9 ( 1 ) ;
return;
}
F_4 ( & V_2 -> V_4 ) ;
F_10 ( & V_2 -> V_5 ) ;
}
static int F_11 ( struct V_15 * V_16 , struct V_17 * V_18 , struct V_19 * V_20 )
{
int error = 0 ;
struct V_21 * V_22 ;
V_22 = (struct V_21 * ) V_16 -> V_23 ;
if ( F_12 ( V_22 ) ) {
F_13 ( V_18 ) ;
return - V_24 ;
}
error = F_14 ( V_16 , V_18 , V_20 ) ;
if ( error < 0 )
F_13 ( V_18 ) ;
return error ;
}
int F_15 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
int error = 0 ;
struct V_21 * V_22 ;
V_22 = (struct V_21 * ) V_16 -> V_23 ;
if ( F_12 ( V_22 ) ) {
F_13 ( V_18 ) ;
return - V_24 ;
}
error = F_16 ( V_16 , V_18 ) ;
if ( error < 0 )
F_13 ( V_18 ) ;
return error ;
}
static void F_17 ( struct V_15 * V_16 , T_1 V_25 , struct V_17 * V_18 )
{
struct V_26 * V_27 ;
V_18 = F_18 ( V_18 , sizeof *V_27 , V_28 ) ;
if ( ! V_18 )
return;
V_27 = (struct V_26 * ) F_19 ( V_18 , sizeof( * V_27 ) ) ;
V_27 -> V_29 . V_30 = F_20 ( F_21 ( V_31 ) ) ;
F_22 ( V_27 ) = F_20 ( F_23 ( V_32 , V_25 ) ) ;
V_18 -> V_33 = V_34 ;
F_15 ( V_16 , V_18 ) ;
return;
}
int F_24 ( struct V_1 * V_2 )
{
struct V_35 * V_27 ;
struct V_17 * V_18 = F_18 ( NULL , sizeof( * V_27 ) , V_28 ) ;
if ( ! V_18 )
return - V_36 ;
V_27 = (struct V_35 * ) F_19 ( V_18 , sizeof( * V_27 ) ) ;
V_27 -> V_29 . V_30 = F_20 ( F_21 ( V_31 ) ) ;
V_27 -> V_29 . V_37 = F_20 ( F_25 ( V_2 -> V_25 ) ) ;
F_22 ( V_27 ) = F_20 ( F_23 ( V_38 , V_2 -> V_25 ) ) ;
V_27 -> V_39 = 0 ;
V_27 -> V_40 = 0 ;
V_27 -> V_41 = F_26 ( V_42 ) ;
V_27 -> V_43 = F_27 ( 1ULL << V_44 ) ;
V_27 -> V_45 = F_27 ( 1 << V_44 ) ;
V_18 -> V_33 = V_46 ;
return F_15 ( V_2 -> V_5 . V_16 , V_18 ) ;
}
int F_28 ( struct V_1 * V_2 )
{
struct V_35 * V_27 ;
struct V_17 * V_18 = F_18 ( NULL , sizeof( * V_27 ) , V_28 ) ;
if ( ! V_18 )
return - V_36 ;
V_27 = (struct V_35 * ) F_19 ( V_18 , sizeof( * V_27 ) ) ;
V_27 -> V_29 . V_30 = F_20 ( F_21 ( V_31 ) ) ;
V_27 -> V_29 . V_37 = F_20 ( F_25 ( V_2 -> V_25 ) ) ;
F_22 ( V_27 ) = F_20 ( F_23 ( V_38 , V_2 -> V_25 ) ) ;
V_27 -> V_39 = 0 ;
V_27 -> V_40 = 0 ;
V_27 -> V_41 = F_26 ( V_42 ) ;
V_27 -> V_43 = F_27 ( 1ULL << V_44 ) ;
V_27 -> V_45 = 0 ;
V_18 -> V_33 = V_46 ;
return F_15 ( V_2 -> V_5 . V_16 , V_18 ) ;
}
static void F_29 ( struct V_1 * V_2 , T_2 V_47 )
{
F_2 ( L_4 , V_3 , V_2 , V_47 ) ;
V_2 -> V_48 = F_30 ( V_2 -> V_5 . V_16 ) -> V_49 [ F_31 ( V_47 ) ] - 40 ;
if ( F_32 ( V_47 ) )
V_2 -> V_48 -= 12 ;
if ( V_2 -> V_48 < 128 )
V_2 -> V_48 = 128 ;
F_2 ( L_5 , V_2 -> V_48 ) ;
}
static enum V_50 F_33 ( struct V_51 * V_52 )
{
unsigned long V_53 ;
enum V_50 V_14 ;
F_34 ( & V_52 -> V_54 , V_53 ) ;
V_14 = V_52 -> V_14 ;
F_35 ( & V_52 -> V_54 , V_53 ) ;
return V_14 ;
}
static void F_36 ( struct V_51 * V_52 , enum V_50 V_55 )
{
V_52 -> V_14 = V_55 ;
}
static void F_37 ( struct V_51 * V_52 , enum V_50 V_55 )
{
unsigned long V_53 ;
F_34 ( & V_52 -> V_54 , V_53 ) ;
F_2 ( L_6 , V_3 , V_56 [ V_52 -> V_14 ] , V_56 [ V_55 ] ) ;
F_36 ( V_52 , V_55 ) ;
F_35 ( & V_52 -> V_54 , V_53 ) ;
return;
}
static void * F_38 ( int V_57 , T_3 V_58 )
{
struct V_51 * V_52 ;
V_52 = F_39 ( V_57 , V_58 ) ;
if ( V_52 ) {
F_40 ( & V_52 -> V_59 ) ;
F_41 ( & V_52 -> V_54 ) ;
F_42 ( & V_52 -> V_60 ) ;
}
F_2 ( L_7 , V_3 , V_52 ) ;
return V_52 ;
}
void F_43 ( struct V_59 * V_59 )
{
struct V_1 * V_2 ;
V_2 = F_44 ( F_44 ( V_59 , struct V_51 , V_59 ) ,
struct V_1 , V_5 ) ;
F_2 ( L_8 , V_3 , V_2 , V_56 [ F_33 ( & V_2 -> V_5 ) ] ) ;
if ( F_45 ( V_61 , & V_2 -> V_5 . V_53 ) ) {
F_46 ( V_2 -> V_5 . V_16 , ( void * ) V_2 , V_2 -> V_25 ) ;
F_47 ( V_2 -> V_62 ) ;
F_48 ( V_2 -> V_5 . V_16 , V_2 -> V_63 ) ;
}
F_49 ( V_2 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_2 ( L_9 , V_3 , V_2 , V_2 -> V_25 ) ;
F_51 ( V_61 , & V_2 -> V_5 . V_53 ) ;
F_10 ( & V_2 -> V_5 ) ;
}
static int F_52 ( int V_64 )
{
switch ( V_64 ) {
case V_65 :
return 0 ;
case V_66 :
return - V_67 ;
case V_68 :
return - V_69 ;
case V_70 :
return - V_71 ;
case V_72 :
return - V_36 ;
case V_73 :
return - V_74 ;
default:
return - V_24 ;
}
}
static struct V_17 * F_18 ( struct V_17 * V_18 , int V_75 , T_3 V_58 )
{
if ( V_18 && ! F_53 ( V_18 ) && ! F_54 ( V_18 ) ) {
F_55 ( V_18 , 0 ) ;
F_56 ( V_18 ) ;
} else {
V_18 = F_57 ( V_75 , V_58 ) ;
}
return V_18 ;
}
static struct V_76 * F_58 ( struct V_15 * V_77 , T_4 V_78 ,
T_4 V_79 , T_5 V_80 ,
T_5 V_81 , T_6 V_82 )
{
struct V_76 * V_83 ;
struct V_84 V_85 ;
V_83 = F_59 ( & V_86 , & V_85 , NULL , V_79 , V_78 ,
V_81 , V_80 , V_87 ,
V_82 , 0 ) ;
if ( F_60 ( V_83 ) )
return NULL ;
return V_83 ;
}
static unsigned int F_61 ( const struct V_88 * V_89 , unsigned short V_90 )
{
int V_91 = 0 ;
while ( V_91 < V_89 -> V_92 - 1 && V_89 -> V_49 [ V_91 + 1 ] <= V_90 )
++ V_91 ;
return V_91 ;
}
static void F_62 ( struct V_15 * V_77 , struct V_17 * V_18 )
{
F_2 ( L_10 , V_3 , V_77 ) ;
F_13 ( V_18 ) ;
}
static void F_63 ( struct V_15 * V_77 , struct V_17 * V_18 )
{
F_8 (KERN_ERR MOD L_11 ) ;
F_13 ( V_18 ) ;
}
static void F_64 ( struct V_15 * V_77 , struct V_17 * V_18 )
{
struct V_93 * V_27 = F_65 ( V_18 ) ;
F_2 ( L_10 , V_3 , V_77 ) ;
V_27 -> V_94 = V_95 ;
F_15 ( V_77 , V_18 ) ;
}
static int F_66 ( struct V_1 * V_2 , T_3 V_58 )
{
struct V_96 * V_27 ;
struct V_17 * V_18 ;
F_2 ( L_1 , V_3 , V_2 ) ;
V_18 = F_18 ( NULL , sizeof( * V_27 ) , V_58 ) ;
if ( ! V_18 ) {
F_8 (KERN_ERR MOD L_12 , __func__) ;
return - V_36 ;
}
V_18 -> V_33 = V_46 ;
F_67 ( V_18 , F_62 ) ;
V_27 = (struct V_96 * ) F_19 ( V_18 , sizeof( * V_27 ) ) ;
V_27 -> V_29 . V_30 = F_20 ( F_21 ( V_97 ) ) ;
V_27 -> V_29 . V_37 = F_20 ( F_25 ( V_2 -> V_25 ) ) ;
F_22 ( V_27 ) = F_20 ( F_23 ( V_98 , V_2 -> V_25 ) ) ;
return F_11 ( V_2 -> V_5 . V_16 , V_18 , V_2 -> V_63 ) ;
}
static int F_68 ( struct V_1 * V_2 , struct V_17 * V_18 , T_3 V_58 )
{
struct V_93 * V_27 ;
F_2 ( L_1 , V_3 , V_2 ) ;
V_18 = F_18 ( V_18 , sizeof( * V_27 ) , V_58 ) ;
if ( ! V_18 ) {
F_8 (KERN_ERR MOD L_13 ,
__func__) ;
return - V_36 ;
}
V_18 -> V_33 = V_46 ;
F_67 ( V_18 , F_64 ) ;
V_27 = (struct V_93 * ) F_19 ( V_18 , sizeof( * V_27 ) ) ;
V_27 -> V_29 . V_30 = F_20 ( F_21 ( V_99 ) ) ;
V_27 -> V_29 . V_37 = F_20 ( F_25 ( V_2 -> V_25 ) ) ;
F_22 ( V_27 ) = F_20 ( F_23 ( V_100 , V_2 -> V_25 ) ) ;
V_27 -> V_94 = V_101 ;
return F_11 ( V_2 -> V_5 . V_16 , V_18 , V_2 -> V_63 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_102 * V_27 ;
struct V_17 * V_18 ;
T_1 V_103 , V_104 , V_105 ;
unsigned int V_106 ;
int V_107 ;
F_2 ( L_1 , V_3 , V_2 ) ;
V_18 = F_18 ( NULL , sizeof( * V_27 ) , V_28 ) ;
if ( ! V_18 ) {
F_8 (KERN_ERR MOD L_13 ,
__func__) ;
return - V_36 ;
}
V_106 = F_61 ( F_30 ( V_2 -> V_5 . V_16 ) , F_70 ( V_2 -> V_62 ) ) ;
V_107 = F_71 ( V_108 ) ;
V_103 = F_72 ( 0 ) |
F_73 ( V_109 ) |
F_74 ( 1 ) |
V_110 |
F_75 ( V_107 ) |
F_76 ( V_106 ) |
F_77 ( V_2 -> V_63 -> V_111 ) | F_78 ( V_2 -> V_63 -> V_112 ) ;
V_104 = F_79 ( ( V_2 -> V_82 >> 2 ) & V_113 ) | F_80 ( V_108 >> 10 ) ;
V_105 = V_114 | F_81 ( 0 ) | F_82 ( 1 ) |
F_83 ( V_115 ) ;
V_18 -> V_33 = V_34 ;
F_67 ( V_18 , F_63 ) ;
V_27 = (struct V_102 * ) F_19 ( V_18 , sizeof( * V_27 ) ) ;
V_27 -> V_29 . V_30 = F_20 ( F_21 ( V_31 ) ) ;
F_22 ( V_27 ) = F_20 ( F_23 ( V_116 , V_2 -> V_117 ) ) ;
V_27 -> V_80 = V_2 -> V_5 . V_118 . V_119 ;
V_27 -> V_81 = V_2 -> V_5 . V_120 . V_119 ;
V_27 -> V_78 = V_2 -> V_5 . V_118 . V_121 . V_122 ;
V_27 -> V_79 = V_2 -> V_5 . V_120 . V_121 . V_122 ;
V_27 -> V_103 = F_20 ( V_103 ) ;
V_27 -> V_104 = F_20 ( V_104 ) ;
V_27 -> V_123 = 0 ;
V_27 -> V_105 = F_20 ( V_105 ) ;
return F_11 ( V_2 -> V_5 . V_16 , V_18 , V_2 -> V_63 ) ;
}
static void F_84 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
int V_124 ;
struct V_125 * V_27 ;
struct V_126 * V_127 ;
int V_75 ;
F_2 ( L_14 , V_3 , V_2 , V_2 -> V_128 ) ;
F_85 ( F_54 ( V_18 ) ) ;
V_124 = sizeof( * V_127 ) + V_2 -> V_128 ;
if ( V_18 -> V_10 + V_124 + sizeof( * V_27 ) > F_86 ( V_18 ) ) {
F_13 ( V_18 ) ;
V_18 = F_57 ( V_124 + sizeof( * V_27 ) , V_28 ) ;
if ( ! V_18 ) {
F_87 ( V_2 , - V_36 ) ;
return;
}
}
F_55 ( V_18 , 0 ) ;
F_88 ( V_18 , sizeof( * V_27 ) ) ;
F_19 ( V_18 , V_124 ) ;
V_18 -> V_33 = V_46 ;
V_127 = (struct V_126 * ) V_18 -> V_10 ;
memset ( V_127 , 0 , sizeof( * V_127 ) ) ;
memcpy ( V_127 -> V_129 , V_130 , sizeof( V_127 -> V_129 ) ) ;
V_127 -> V_53 = ( V_131 ? V_132 : 0 ) |
( V_133 ? V_134 : 0 ) ;
V_127 -> V_135 = F_26 ( V_2 -> V_128 ) ;
V_127 -> V_136 = V_137 ;
if ( V_2 -> V_128 )
memcpy ( V_127 -> V_138 , V_2 -> V_139 + sizeof( * V_127 ) , V_2 -> V_128 ) ;
F_56 ( V_18 ) ;
F_67 ( V_18 , F_62 ) ;
F_89 ( V_18 ) ;
V_75 = V_18 -> V_75 ;
V_27 = (struct V_125 * ) F_90 ( V_18 , sizeof( * V_27 ) ) ;
V_27 -> V_30 = F_20 ( F_21 ( V_140 ) | V_141 ) ;
V_27 -> V_37 = F_20 ( F_25 ( V_2 -> V_25 ) ) ;
V_27 -> V_75 = F_20 ( V_75 ) ;
V_27 -> V_142 = F_20 ( F_91 ( V_2 -> V_63 -> V_112 ) |
F_92 ( V_143 >> 15 ) ) ;
V_27 -> V_53 = F_20 ( V_144 ) ;
V_27 -> V_145 = F_20 ( V_2 -> V_146 ) ;
F_85 ( V_2 -> V_147 ) ;
V_2 -> V_147 = V_18 ;
F_11 ( V_2 -> V_5 . V_16 , V_18 , V_2 -> V_63 ) ;
F_1 ( V_2 ) ;
F_37 ( & V_2 -> V_5 , V_148 ) ;
return;
}
static int F_93 ( struct V_1 * V_2 , const void * V_149 , T_6 V_128 )
{
int V_124 ;
struct V_125 * V_27 ;
struct V_126 * V_127 ;
struct V_17 * V_18 ;
F_2 ( L_15 , V_3 , V_2 , V_128 ) ;
V_124 = sizeof( * V_127 ) + V_128 ;
V_18 = F_18 ( NULL , V_124 + sizeof( * V_27 ) , V_28 ) ;
if ( ! V_18 ) {
F_8 (KERN_ERR MOD L_16 , __func__) ;
return - V_36 ;
}
F_88 ( V_18 , sizeof( * V_27 ) ) ;
V_127 = (struct V_126 * ) F_19 ( V_18 , V_124 ) ;
memset ( V_127 , 0 , sizeof( * V_127 ) ) ;
memcpy ( V_127 -> V_129 , V_150 , sizeof( V_127 -> V_129 ) ) ;
V_127 -> V_53 = V_151 ;
V_127 -> V_136 = V_137 ;
V_127 -> V_135 = F_26 ( V_128 ) ;
if ( V_128 )
memcpy ( V_127 -> V_138 , V_149 , V_128 ) ;
F_56 ( V_18 ) ;
V_18 -> V_33 = V_46 ;
F_67 ( V_18 , F_62 ) ;
F_89 ( V_18 ) ;
V_27 = (struct V_125 * ) F_90 ( V_18 , sizeof( * V_27 ) ) ;
V_27 -> V_30 = F_20 ( F_21 ( V_140 ) | V_141 ) ;
V_27 -> V_37 = F_20 ( F_25 ( V_2 -> V_25 ) ) ;
V_27 -> V_75 = F_20 ( V_124 ) ;
V_27 -> V_142 = F_20 ( F_91 ( V_2 -> V_63 -> V_112 ) |
F_92 ( V_143 >> 15 ) ) ;
V_27 -> V_53 = F_20 ( V_144 ) ;
V_27 -> V_145 = F_20 ( V_2 -> V_146 ) ;
F_85 ( V_2 -> V_147 ) ;
V_2 -> V_147 = V_18 ;
return F_11 ( V_2 -> V_5 . V_16 , V_18 , V_2 -> V_63 ) ;
}
static int F_94 ( struct V_1 * V_2 , const void * V_149 , T_6 V_128 )
{
int V_124 ;
struct V_125 * V_27 ;
struct V_126 * V_127 ;
int V_75 ;
struct V_17 * V_18 ;
F_2 ( L_15 , V_3 , V_2 , V_128 ) ;
V_124 = sizeof( * V_127 ) + V_128 ;
V_18 = F_18 ( NULL , V_124 + sizeof( * V_27 ) , V_28 ) ;
if ( ! V_18 ) {
F_8 (KERN_ERR MOD L_16 , __func__) ;
return - V_36 ;
}
V_18 -> V_33 = V_46 ;
F_88 ( V_18 , sizeof( * V_27 ) ) ;
V_127 = (struct V_126 * ) F_19 ( V_18 , V_124 ) ;
memset ( V_127 , 0 , sizeof( * V_127 ) ) ;
memcpy ( V_127 -> V_129 , V_150 , sizeof( V_127 -> V_129 ) ) ;
V_127 -> V_53 = ( V_2 -> V_152 . V_131 ? V_132 : 0 ) |
( V_133 ? V_134 : 0 ) ;
V_127 -> V_136 = V_137 ;
V_127 -> V_135 = F_26 ( V_128 ) ;
if ( V_128 )
memcpy ( V_127 -> V_138 , V_149 , V_128 ) ;
F_56 ( V_18 ) ;
F_67 ( V_18 , F_62 ) ;
F_89 ( V_18 ) ;
V_75 = V_18 -> V_75 ;
V_27 = (struct V_125 * ) F_90 ( V_18 , sizeof( * V_27 ) ) ;
V_27 -> V_30 = F_20 ( F_21 ( V_140 ) | V_141 ) ;
V_27 -> V_37 = F_20 ( F_25 ( V_2 -> V_25 ) ) ;
V_27 -> V_75 = F_20 ( V_75 ) ;
V_27 -> V_142 = F_20 ( F_91 ( V_2 -> V_63 -> V_112 ) |
F_92 ( V_143 >> 15 ) ) ;
V_27 -> V_53 = F_20 ( V_144 ) ;
V_27 -> V_145 = F_20 ( V_2 -> V_146 ) ;
V_2 -> V_147 = V_18 ;
F_37 ( & V_2 -> V_5 , V_153 ) ;
return F_11 ( V_2 -> V_5 . V_16 , V_18 , V_2 -> V_63 ) ;
}
static int F_95 ( struct V_15 * V_16 , struct V_17 * V_18 , void * V_154 )
{
struct V_1 * V_2 = V_154 ;
struct V_155 * V_27 = F_65 ( V_18 ) ;
unsigned int V_156 = F_96 ( V_27 ) ;
F_2 ( L_9 , V_3 , V_2 , V_156 ) ;
F_97 ( V_2 -> V_62 ) ;
V_2 -> V_25 = V_156 ;
F_98 ( V_2 -> V_5 . V_16 , & V_157 , V_2 , V_156 ) ;
V_2 -> V_146 = F_99 ( V_27 -> V_158 ) ;
V_2 -> V_159 = F_99 ( V_27 -> V_160 ) ;
F_29 ( V_2 , F_100 ( V_27 -> V_161 ) ) ;
F_101 ( V_2 -> V_5 . V_16 , V_2 -> V_117 ) ;
F_84 ( V_2 , V_18 ) ;
return 0 ;
}
static void F_102 ( struct V_1 * V_2 , struct V_17 * V_18 , T_3 V_58 )
{
F_2 ( L_1 , __FILE__ , V_2 ) ;
F_37 ( & V_2 -> V_5 , V_162 ) ;
F_68 ( V_2 , V_18 , V_58 ) ;
}
static void F_103 ( struct V_1 * V_2 )
{
struct V_163 V_164 ;
F_2 ( L_1 , V_3 , V_2 ) ;
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
V_164 . V_164 = V_165 ;
if ( V_2 -> V_5 . V_166 ) {
F_2 ( L_17 ,
V_2 , V_2 -> V_5 . V_166 , V_2 -> V_25 ) ;
V_2 -> V_5 . V_166 -> V_167 ( V_2 -> V_5 . V_166 , & V_164 ) ;
V_2 -> V_5 . V_166 -> V_168 ( V_2 -> V_5 . V_166 ) ;
V_2 -> V_5 . V_166 = NULL ;
V_2 -> V_5 . V_169 = NULL ;
}
}
static void F_104 ( struct V_1 * V_2 )
{
struct V_163 V_164 ;
F_2 ( L_1 , V_3 , V_2 ) ;
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
V_164 . V_164 = V_170 ;
if ( V_2 -> V_5 . V_166 ) {
F_2 ( L_18 ,
V_2 , V_2 -> V_5 . V_166 , V_2 -> V_25 ) ;
V_2 -> V_5 . V_166 -> V_167 ( V_2 -> V_5 . V_166 , & V_164 ) ;
}
}
static void F_105 ( struct V_1 * V_2 )
{
struct V_163 V_164 ;
F_2 ( L_1 , V_3 , V_2 ) ;
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
V_164 . V_164 = V_165 ;
V_164 . V_64 = - V_67 ;
if ( V_2 -> V_5 . V_166 ) {
F_2 ( L_19 , V_2 ,
V_2 -> V_5 . V_166 , V_2 -> V_25 ) ;
V_2 -> V_5 . V_166 -> V_167 ( V_2 -> V_5 . V_166 , & V_164 ) ;
V_2 -> V_5 . V_166 -> V_168 ( V_2 -> V_5 . V_166 ) ;
V_2 -> V_5 . V_166 = NULL ;
V_2 -> V_5 . V_169 = NULL ;
}
}
static void F_87 ( struct V_1 * V_2 , int V_64 )
{
struct V_163 V_164 ;
F_2 ( L_20 , V_3 , V_2 , V_64 ) ;
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
V_164 . V_164 = V_171 ;
V_164 . V_64 = V_64 ;
V_164 . V_118 = V_2 -> V_5 . V_118 ;
V_164 . V_120 = V_2 -> V_5 . V_120 ;
if ( ( V_64 == 0 ) || ( V_64 == - V_172 ) ) {
V_164 . V_173 = V_2 -> V_128 ;
V_164 . V_138 = V_2 -> V_139 + sizeof( struct V_126 ) ;
}
if ( V_2 -> V_5 . V_166 ) {
F_2 ( L_21 , V_3 , V_2 ,
V_2 -> V_25 , V_64 ) ;
V_2 -> V_5 . V_166 -> V_167 ( V_2 -> V_5 . V_166 , & V_164 ) ;
}
if ( V_64 < 0 ) {
V_2 -> V_5 . V_166 -> V_168 ( V_2 -> V_5 . V_166 ) ;
V_2 -> V_5 . V_166 = NULL ;
V_2 -> V_5 . V_169 = NULL ;
}
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_163 V_164 ;
F_2 ( L_9 , V_3 , V_2 , V_2 -> V_25 ) ;
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
V_164 . V_164 = V_174 ;
V_164 . V_118 = V_2 -> V_5 . V_118 ;
V_164 . V_120 = V_2 -> V_5 . V_120 ;
V_164 . V_173 = V_2 -> V_128 ;
V_164 . V_138 = V_2 -> V_139 + sizeof( struct V_126 ) ;
V_164 . V_175 = V_2 ;
V_164 . V_176 = V_164 . V_177 = 8 ;
if ( F_33 ( & V_2 -> V_178 -> V_5 ) != V_179 ) {
F_5 ( & V_2 -> V_5 ) ;
V_2 -> V_178 -> V_5 . V_166 -> V_167 (
V_2 -> V_178 -> V_5 . V_166 ,
& V_164 ) ;
}
F_10 ( & V_2 -> V_178 -> V_5 ) ;
V_2 -> V_178 = NULL ;
}
static void F_107 ( struct V_1 * V_2 )
{
struct V_163 V_164 ;
F_2 ( L_1 , V_3 , V_2 ) ;
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
V_164 . V_164 = V_180 ;
V_164 . V_176 = V_164 . V_177 = 8 ;
if ( V_2 -> V_5 . V_166 ) {
F_2 ( L_9 , V_3 , V_2 , V_2 -> V_25 ) ;
V_2 -> V_5 . V_166 -> V_167 ( V_2 -> V_5 . V_166 , & V_164 ) ;
}
}
static int F_108 ( struct V_1 * V_2 , T_1 V_181 )
{
struct V_182 * V_27 ;
struct V_17 * V_18 ;
F_2 ( L_22 , V_3 , V_2 , V_181 ) ;
V_18 = F_18 ( NULL , sizeof( * V_27 ) , V_28 ) ;
if ( ! V_18 ) {
F_8 (KERN_ERR MOD L_23 ) ;
return 0 ;
}
V_27 = (struct V_182 * ) F_19 ( V_18 , sizeof( * V_27 ) ) ;
V_27 -> V_29 . V_30 = F_20 ( F_21 ( V_31 ) ) ;
F_22 ( V_27 ) = F_20 ( F_23 ( V_183 , V_2 -> V_25 ) ) ;
V_27 -> V_184 = F_20 ( F_109 ( V_181 ) | F_110 ( 1 ) ) ;
V_18 -> V_33 = V_185 ;
F_15 ( V_2 -> V_5 . V_16 , V_18 ) ;
return V_181 ;
}
static void F_111 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_126 * V_127 ;
T_2 V_128 ;
struct V_186 V_187 ;
enum V_188 V_43 ;
int V_189 ;
F_2 ( L_1 , V_3 , V_2 ) ;
F_7 ( V_2 ) ;
if ( F_33 ( & V_2 -> V_5 ) != V_148 )
return;
if ( V_2 -> V_190 + V_18 -> V_75 > sizeof( V_2 -> V_139 ) ) {
V_189 = - V_191 ;
goto V_189;
}
F_112 ( V_18 , & ( V_2 -> V_139 [ V_2 -> V_190 ] ) ,
V_18 -> V_75 ) ;
V_2 -> V_190 += V_18 -> V_75 ;
if ( V_2 -> V_190 < sizeof( * V_127 ) )
return;
V_127 = (struct V_126 * ) V_2 -> V_139 ;
if ( V_127 -> V_136 != V_137 ) {
V_189 = - V_192 ;
goto V_189;
}
if ( memcmp ( V_127 -> V_129 , V_150 , sizeof( V_127 -> V_129 ) ) ) {
V_189 = - V_192 ;
goto V_189;
}
V_128 = F_100 ( V_127 -> V_135 ) ;
if ( V_128 > V_193 ) {
V_189 = - V_192 ;
goto V_189;
}
if ( V_2 -> V_190 > ( sizeof( * V_127 ) + V_128 ) ) {
V_189 = - V_192 ;
goto V_189;
}
V_2 -> V_128 = ( T_6 ) V_128 ;
if ( V_2 -> V_190 < ( sizeof( * V_127 ) + V_128 ) )
return;
if ( V_127 -> V_53 & V_151 ) {
V_189 = - V_172 ;
goto V_189;
}
F_37 ( & V_2 -> V_5 , V_194 ) ;
V_2 -> V_152 . V_195 = 1 ;
V_2 -> V_152 . V_131 = ( V_127 -> V_53 & V_132 ) | V_131 ? 1 : 0 ;
V_2 -> V_152 . V_196 = V_133 ;
V_2 -> V_152 . V_197 = V_127 -> V_53 & V_134 ? 1 : 0 ;
V_2 -> V_152 . V_198 = V_137 ;
F_2 ( L_24
L_25 , V_3 ,
V_2 -> V_152 . V_131 , V_2 -> V_152 . V_196 ,
V_2 -> V_152 . V_197 , V_2 -> V_152 . V_198 ) ;
V_187 . V_152 = V_2 -> V_152 ;
V_187 . V_199 = V_2 -> V_176 ;
V_187 . V_200 = V_2 -> V_177 ;
V_187 . V_201 = V_2 ;
V_187 . V_202 = V_203 ;
V_43 = V_204 |
V_205 | V_206 |
V_207 | V_208 ;
V_189 = F_113 ( V_2 -> V_5 . V_169 -> V_209 ,
V_2 -> V_5 . V_169 , V_43 , & V_187 , 1 ) ;
if ( V_189 )
goto V_189;
if ( V_210 && F_114 ( V_2 -> V_5 . V_169 ) == 0 ) {
F_115 ( V_2 ) ;
}
goto V_211;
V_189:
F_102 ( V_2 , V_18 , V_28 ) ;
V_211:
F_87 ( V_2 , V_189 ) ;
return;
}
static void F_116 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_126 * V_127 ;
T_2 V_128 ;
F_2 ( L_1 , V_3 , V_2 ) ;
F_7 ( V_2 ) ;
if ( F_33 ( & V_2 -> V_5 ) != V_212 )
return;
if ( V_2 -> V_190 + V_18 -> V_75 > sizeof( V_2 -> V_139 ) ) {
F_102 ( V_2 , V_18 , V_28 ) ;
return;
}
F_2 ( L_26 , V_3 , __FILE__ , __LINE__ ) ;
F_112 ( V_18 , & ( V_2 -> V_139 [ V_2 -> V_190 ] ) ,
V_18 -> V_75 ) ;
V_2 -> V_190 += V_18 -> V_75 ;
if ( V_2 -> V_190 < sizeof( * V_127 ) )
return;
F_2 ( L_26 , V_3 , __FILE__ , __LINE__ ) ;
V_127 = (struct V_126 * ) V_2 -> V_139 ;
if ( V_127 -> V_136 != V_137 ) {
F_102 ( V_2 , V_18 , V_28 ) ;
return;
}
if ( memcmp ( V_127 -> V_129 , V_130 , sizeof( V_127 -> V_129 ) ) ) {
F_102 ( V_2 , V_18 , V_28 ) ;
return;
}
V_128 = F_100 ( V_127 -> V_135 ) ;
if ( V_128 > V_193 ) {
F_102 ( V_2 , V_18 , V_28 ) ;
return;
}
if ( V_2 -> V_190 > ( sizeof( * V_127 ) + V_128 ) ) {
F_102 ( V_2 , V_18 , V_28 ) ;
return;
}
V_2 -> V_128 = ( T_6 ) V_128 ;
if ( V_2 -> V_190 < ( sizeof( * V_127 ) + V_128 ) )
return;
V_2 -> V_152 . V_195 = 0 ;
V_2 -> V_152 . V_131 = ( V_127 -> V_53 & V_132 ) | V_131 ? 1 : 0 ;
V_2 -> V_152 . V_196 = V_133 ;
V_2 -> V_152 . V_197 = V_127 -> V_53 & V_134 ? 1 : 0 ;
V_2 -> V_152 . V_198 = V_137 ;
F_2 ( L_24
L_25 , V_3 ,
V_2 -> V_152 . V_131 , V_2 -> V_152 . V_196 ,
V_2 -> V_152 . V_197 , V_2 -> V_152 . V_198 ) ;
F_37 ( & V_2 -> V_5 , V_213 ) ;
F_106 ( V_2 ) ;
return;
}
static int F_117 ( struct V_15 * V_16 , struct V_17 * V_18 , void * V_154 )
{
struct V_1 * V_2 = V_154 ;
struct V_214 * V_215 = F_65 ( V_18 ) ;
unsigned int V_216 = F_100 ( V_215 -> V_75 ) ;
F_2 ( L_27 , V_3 , V_2 , V_216 ) ;
F_118 ( V_18 , sizeof( * V_215 ) ) ;
F_55 ( V_18 , V_216 ) ;
V_2 -> V_159 += V_216 ;
F_85 ( V_2 -> V_159 != ( F_99 ( V_215 -> V_217 ) + V_216 ) ) ;
switch ( F_33 ( & V_2 -> V_5 ) ) {
case V_148 :
F_111 ( V_2 , V_18 ) ;
break;
case V_212 :
F_116 ( V_2 , V_18 ) ;
break;
case V_153 :
break;
default:
F_8 (KERN_ERR MOD L_28
L_29 ,
__func__, ep, state_read(&ep->com), ep->hwtid) ;
break;
}
F_108 ( V_2 , V_216 ) ;
return V_218 ;
}
static int F_119 ( struct V_15 * V_16 , struct V_17 * V_18 , void * V_154 )
{
struct V_1 * V_2 = V_154 ;
struct V_219 * V_215 = F_65 ( V_18 ) ;
unsigned int V_181 = F_100 ( V_215 -> V_181 ) ;
unsigned long V_53 ;
int V_220 = 0 ;
F_2 ( L_22 , V_3 , V_2 , V_181 ) ;
if ( V_181 == 0 ) {
F_2 ( L_30 ,
V_3 , V_2 , F_33 ( & V_2 -> V_5 ) ) ;
return V_218 ;
}
F_34 ( & V_2 -> V_5 . V_54 , V_53 ) ;
F_85 ( V_181 != 1 ) ;
F_97 ( V_2 -> V_62 ) ;
if ( ! V_2 -> V_147 ) {
F_2 ( L_31 ,
V_3 , V_2 , V_2 -> V_5 . V_14 ) ;
if ( V_2 -> V_152 . V_195 ) {
F_2 ( L_32 ,
V_3 , V_2 , V_2 -> V_5 . V_14 ) ;
if ( V_210 && V_2 -> V_5 . V_14 == V_194 )
V_220 = 1 ;
} else {
F_2 ( L_33 ,
V_3 , V_2 , V_2 -> V_5 . V_14 ) ;
if ( V_2 -> V_5 . V_14 == V_213 ) {
V_2 -> V_5 . V_221 = 1 ;
F_120 ( & V_2 -> V_5 . V_60 ) ;
}
}
} else {
F_2 ( L_34 ,
V_3 , V_2 , V_2 -> V_5 . V_14 ) ;
F_13 ( V_2 -> V_147 ) ;
V_2 -> V_147 = NULL ;
}
F_35 ( & V_2 -> V_5 . V_54 , V_53 ) ;
if ( V_220 )
F_115 ( V_2 ) ;
return V_218 ;
}
static int F_121 ( struct V_15 * V_16 , struct V_17 * V_18 , void * V_154 )
{
struct V_1 * V_2 = V_154 ;
unsigned long V_53 ;
int V_222 = 0 ;
F_2 ( L_1 , V_3 , V_2 ) ;
F_85 ( ! V_2 ) ;
if ( ! F_122 ( V_223 , & V_2 -> V_5 . V_53 ) ) {
return V_218 ;
}
F_34 ( & V_2 -> V_5 . V_54 , V_53 ) ;
switch ( V_2 -> V_5 . V_14 ) {
case V_162 :
F_103 ( V_2 ) ;
F_36 ( & V_2 -> V_5 , V_179 ) ;
V_222 = 1 ;
break;
default:
F_8 ( V_13 L_35 ,
V_3 , V_2 , V_2 -> V_5 . V_14 ) ;
break;
}
F_35 ( & V_2 -> V_5 . V_54 , V_53 ) ;
if ( V_222 )
F_50 ( V_2 ) ;
return V_218 ;
}
static inline int F_123 ( int V_64 )
{
return V_64 != V_72 && V_64 != V_73 &&
V_64 != V_68 ;
}
static int F_124 ( struct V_15 * V_16 , struct V_17 * V_18 , void * V_154 )
{
struct V_1 * V_2 = V_154 ;
struct V_224 * V_225 = F_65 ( V_18 ) ;
F_2 ( L_36 , V_3 , V_2 , V_225 -> V_64 ,
F_52 ( V_225 -> V_64 ) ) ;
F_87 ( V_2 , F_52 ( V_225 -> V_64 ) ) ;
F_37 ( & V_2 -> V_5 , V_179 ) ;
if ( V_2 -> V_5 . V_16 -> type != V_226 && F_123 ( V_225 -> V_64 ) )
F_17 ( V_2 -> V_5 . V_16 , F_96 ( V_225 ) , NULL ) ;
F_101 ( V_2 -> V_5 . V_16 , V_2 -> V_117 ) ;
F_47 ( V_2 -> V_62 ) ;
F_48 ( V_2 -> V_5 . V_16 , V_2 -> V_63 ) ;
F_10 ( & V_2 -> V_5 ) ;
return V_218 ;
}
static int F_125 ( struct V_227 * V_2 )
{
struct V_17 * V_18 ;
struct V_228 * V_27 ;
F_2 ( L_1 , V_3 , V_2 ) ;
V_18 = F_18 ( NULL , sizeof( * V_27 ) , V_28 ) ;
if ( ! V_18 ) {
F_8 (KERN_ERR MOD L_37 ) ;
return - V_36 ;
}
V_27 = (struct V_228 * ) F_19 ( V_18 , sizeof( * V_27 ) ) ;
V_27 -> V_29 . V_30 = F_20 ( F_21 ( V_31 ) ) ;
F_22 ( V_27 ) = F_20 ( F_23 ( V_229 , V_2 -> V_230 ) ) ;
V_27 -> V_80 = V_2 -> V_5 . V_118 . V_119 ;
V_27 -> V_78 = V_2 -> V_5 . V_118 . V_121 . V_122 ;
V_27 -> V_81 = 0 ;
V_27 -> V_79 = 0 ;
V_27 -> V_231 = 0 ;
V_27 -> V_103 = F_20 ( V_232 | V_110 ) ;
V_27 -> V_104 = F_20 ( F_80 ( V_108 >> 10 ) ) ;
V_27 -> V_233 = F_20 ( F_126 ( V_234 ) ) ;
V_18 -> V_33 = 1 ;
return F_15 ( V_2 -> V_5 . V_16 , V_18 ) ;
}
static int F_127 ( struct V_15 * V_16 , struct V_17 * V_18 , void * V_154 )
{
struct V_227 * V_2 = V_154 ;
struct V_235 * V_225 = F_65 ( V_18 ) ;
F_2 ( L_38 , V_3 , V_2 ,
V_225 -> V_64 , F_52 ( V_225 -> V_64 ) ) ;
V_2 -> V_5 . V_236 = F_52 ( V_225 -> V_64 ) ;
V_2 -> V_5 . V_221 = 1 ;
F_120 ( & V_2 -> V_5 . V_60 ) ;
return V_218 ;
}
static int F_128 ( struct V_227 * V_2 )
{
struct V_17 * V_18 ;
struct V_237 * V_27 ;
F_2 ( L_1 , V_3 , V_2 ) ;
V_18 = F_18 ( NULL , sizeof( * V_27 ) , V_28 ) ;
if ( ! V_18 ) {
F_8 (KERN_ERR MOD L_12 , __func__) ;
return - V_36 ;
}
V_27 = (struct V_237 * ) F_19 ( V_18 , sizeof( * V_27 ) ) ;
V_27 -> V_29 . V_30 = F_20 ( F_21 ( V_31 ) ) ;
V_27 -> V_40 = 0 ;
F_22 ( V_27 ) = F_20 ( F_23 ( V_238 , V_2 -> V_230 ) ) ;
V_18 -> V_33 = 1 ;
return F_15 ( V_2 -> V_5 . V_16 , V_18 ) ;
}
static int F_129 ( struct V_15 * V_16 , struct V_17 * V_18 ,
void * V_154 )
{
struct V_227 * V_2 = V_154 ;
struct V_239 * V_225 = F_65 ( V_18 ) ;
F_2 ( L_1 , V_3 , V_2 ) ;
V_2 -> V_5 . V_236 = F_52 ( V_225 -> V_64 ) ;
V_2 -> V_5 . V_221 = 1 ;
F_120 ( & V_2 -> V_5 . V_60 ) ;
return V_218 ;
}
static void F_130 ( struct V_1 * V_2 , T_4 V_79 , struct V_17 * V_18 )
{
struct V_240 * V_225 ;
unsigned int V_106 ;
T_1 V_103 , V_104 , V_105 ;
int V_107 ;
F_2 ( L_1 , V_3 , V_2 ) ;
F_85 ( F_54 ( V_18 ) ) ;
F_55 ( V_18 , sizeof( * V_225 ) ) ;
F_56 ( V_18 ) ;
V_106 = F_61 ( F_30 ( V_2 -> V_5 . V_16 ) , F_70 ( V_2 -> V_62 ) ) ;
V_107 = F_71 ( V_108 ) ;
V_103 = F_72 ( 0 ) |
F_73 ( V_109 ) |
F_74 ( 1 ) |
V_110 |
F_75 ( V_107 ) |
F_76 ( V_106 ) |
F_77 ( V_2 -> V_63 -> V_111 ) | F_78 ( V_2 -> V_63 -> V_112 ) ;
V_104 = F_79 ( ( V_2 -> V_82 >> 2 ) & V_113 ) | F_80 ( V_108 >> 10 ) ;
V_105 = V_114 | F_81 ( 0 ) | F_82 ( 1 ) |
F_83 ( V_115 ) ;
V_225 = F_65 ( V_18 ) ;
V_225 -> V_29 . V_30 = F_20 ( F_21 ( V_31 ) ) ;
F_22 ( V_225 ) = F_20 ( F_23 ( V_241 , V_2 -> V_25 ) ) ;
V_225 -> V_79 = V_79 ;
V_225 -> V_103 = F_20 ( V_103 ) ;
V_225 -> V_242 = F_20 ( V_104 | V_243 ) ;
V_225 -> V_105 = F_20 ( V_105 ) ;
V_225 -> V_244 = V_225 -> V_105 ;
V_18 -> V_33 = V_34 ;
F_11 ( V_2 -> V_5 . V_16 , V_18 , V_2 -> V_63 ) ;
return;
}
static void F_131 ( struct V_15 * V_16 , T_1 V_25 , T_4 V_79 ,
struct V_17 * V_18 )
{
F_2 ( L_39 , V_3 , V_16 , V_25 ,
V_79 ) ;
F_85 ( F_54 ( V_18 ) ) ;
F_55 ( V_18 , sizeof( struct V_26 ) ) ;
F_56 ( V_18 ) ;
if ( V_16 -> type != V_226 )
F_17 ( V_16 , V_25 , V_18 ) ;
else {
struct V_240 * V_225 ;
V_225 = F_65 ( V_18 ) ;
V_18 -> V_33 = V_34 ;
V_225 -> V_29 . V_30 = F_20 ( F_21 ( V_31 ) ) ;
F_22 ( V_225 ) = F_20 ( F_23 ( V_241 ,
V_25 ) ) ;
V_225 -> V_79 = V_79 ;
V_225 -> V_103 = F_20 ( V_110 ) ;
V_225 -> V_242 = F_20 ( V_245 ) ;
V_225 -> V_105 = 0 ;
V_225 -> V_244 = V_225 -> V_105 ;
F_15 ( V_16 , V_18 ) ;
}
}
static int F_132 ( struct V_15 * V_16 , struct V_17 * V_18 , void * V_154 )
{
struct V_1 * V_246 , * V_178 = V_154 ;
struct V_247 * V_27 = F_65 ( V_18 ) ;
unsigned int V_25 = F_96 ( V_27 ) ;
struct V_248 * V_62 ;
struct V_19 * V_63 ;
struct V_76 * V_83 ;
struct V_249 V_250 ;
F_2 ( L_40 , V_3 , V_178 , V_25 ) ;
if ( F_33 ( & V_178 -> V_5 ) != V_251 ) {
F_8 ( V_13 L_41 ,
V_3 ) ;
goto V_252;
}
V_250 . V_253 = V_27 -> V_254 ;
V_250 . V_255 = F_100 ( V_27 -> V_255 ) ;
if ( V_16 -> V_256 ( V_16 , V_257 , & V_250 ) < 0 || ! V_250 . V_77 ) {
F_8 ( V_13 L_42 ,
V_3 , V_27 -> V_254 ) ;
goto V_252;
}
V_83 = F_58 ( V_16 ,
V_27 -> V_78 ,
V_27 -> V_79 ,
V_27 -> V_80 ,
V_27 -> V_81 , F_133 ( F_99 ( V_27 -> V_258 ) ) ) ;
if ( ! V_83 ) {
F_8 (KERN_ERR MOD L_43 ,
__func__) ;
goto V_252;
}
V_62 = & V_83 -> V_62 ;
V_63 = F_134 ( V_16 , V_62 , NULL , & V_27 -> V_79 ) ;
if ( ! V_63 ) {
F_8 (KERN_ERR MOD L_44 ,
__func__) ;
F_47 ( V_62 ) ;
goto V_252;
}
V_246 = F_38 ( sizeof( * V_246 ) , V_28 ) ;
if ( ! V_246 ) {
F_8 (KERN_ERR MOD L_45 ,
__func__) ;
F_48 ( V_16 , V_63 ) ;
F_47 ( V_62 ) ;
goto V_252;
}
F_37 ( & V_246 -> V_5 , V_259 ) ;
V_246 -> V_5 . V_16 = V_16 ;
V_246 -> V_5 . V_166 = NULL ;
V_246 -> V_5 . V_118 . V_260 = V_261 ;
V_246 -> V_5 . V_118 . V_119 = V_27 -> V_80 ;
V_246 -> V_5 . V_118 . V_121 . V_122 = V_27 -> V_78 ;
V_246 -> V_5 . V_120 . V_260 = V_261 ;
V_246 -> V_5 . V_120 . V_119 = V_27 -> V_81 ;
V_246 -> V_5 . V_120 . V_121 . V_122 = V_27 -> V_79 ;
F_5 ( & V_178 -> V_5 ) ;
V_246 -> V_178 = V_178 ;
V_246 -> V_82 = F_133 ( F_99 ( V_27 -> V_258 ) ) ;
V_246 -> V_63 = V_63 ;
V_246 -> V_62 = V_62 ;
V_246 -> V_25 = V_25 ;
F_135 ( & V_246 -> V_4 ) ;
F_98 ( V_16 , & V_157 , V_246 , V_25 ) ;
F_130 ( V_246 , V_27 -> V_79 , V_18 ) ;
goto V_211;
V_252:
F_131 ( V_16 , V_25 , V_27 -> V_79 , V_18 ) ;
V_211:
return V_218 ;
}
static int F_136 ( struct V_15 * V_16 , struct V_17 * V_18 , void * V_154 )
{
struct V_1 * V_2 = V_154 ;
struct V_262 * V_27 = F_65 ( V_18 ) ;
F_2 ( L_1 , V_3 , V_2 ) ;
V_2 -> V_146 = F_99 ( V_27 -> V_158 ) ;
V_2 -> V_159 = F_99 ( V_27 -> V_160 ) ;
F_29 ( V_2 , F_100 ( V_27 -> V_161 ) ) ;
F_97 ( V_2 -> V_62 ) ;
F_37 ( & V_2 -> V_5 , V_212 ) ;
F_1 ( V_2 ) ;
return V_218 ;
}
static int F_137 ( struct V_15 * V_16 , struct V_17 * V_18 , void * V_154 )
{
struct V_1 * V_2 = V_154 ;
struct V_186 V_187 ;
unsigned long V_53 ;
int V_263 = 1 ;
int V_222 = 0 ;
F_2 ( L_1 , V_3 , V_2 ) ;
F_97 ( V_2 -> V_62 ) ;
F_34 ( & V_2 -> V_5 . V_54 , V_53 ) ;
switch ( V_2 -> V_5 . V_14 ) {
case V_212 :
F_36 ( & V_2 -> V_5 , V_264 ) ;
break;
case V_148 :
F_36 ( & V_2 -> V_5 , V_264 ) ;
F_87 ( V_2 , - V_67 ) ;
break;
case V_213 :
F_36 ( & V_2 -> V_5 , V_264 ) ;
V_2 -> V_5 . V_221 = 1 ;
V_2 -> V_5 . V_236 = - V_67 ;
F_2 ( L_46 , V_2 ) ;
F_120 ( & V_2 -> V_5 . V_60 ) ;
break;
case V_153 :
F_36 ( & V_2 -> V_5 , V_264 ) ;
V_2 -> V_5 . V_221 = 1 ;
V_2 -> V_5 . V_236 = - V_67 ;
F_2 ( L_46 , V_2 ) ;
F_120 ( & V_2 -> V_5 . V_60 ) ;
break;
case V_194 :
F_1 ( V_2 ) ;
F_36 ( & V_2 -> V_5 , V_264 ) ;
V_187 . V_202 = V_265 ;
F_113 ( V_2 -> V_5 . V_169 -> V_209 , V_2 -> V_5 . V_169 ,
V_204 , & V_187 , 1 ) ;
F_104 ( V_2 ) ;
break;
case V_162 :
V_263 = 0 ;
break;
case V_264 :
F_36 ( & V_2 -> V_5 , V_266 ) ;
V_263 = 0 ;
break;
case V_266 :
F_7 ( V_2 ) ;
if ( V_2 -> V_5 . V_166 && V_2 -> V_5 . V_169 ) {
V_187 . V_202 = V_267 ;
F_113 ( V_2 -> V_5 . V_169 -> V_209 , V_2 -> V_5 . V_169 ,
V_204 , & V_187 , 1 ) ;
}
F_103 ( V_2 ) ;
F_36 ( & V_2 -> V_5 , V_179 ) ;
V_222 = 1 ;
V_263 = 0 ;
break;
case V_179 :
V_263 = 0 ;
break;
default:
F_85 ( 1 ) ;
}
F_35 ( & V_2 -> V_5 . V_54 , V_53 ) ;
if ( V_263 )
F_138 ( V_2 , 0 , V_28 ) ;
if ( V_222 )
F_50 ( V_2 ) ;
return V_218 ;
}
static int F_139 ( unsigned int V_64 )
{
return V_64 == V_268 ||
V_64 == V_269 ;
}
static int F_140 ( struct V_15 * V_16 , struct V_17 * V_18 , void * V_154 )
{
struct V_270 * V_27 = F_65 ( V_18 ) ;
struct V_1 * V_2 = V_154 ;
struct V_271 * V_225 ;
struct V_17 * V_272 ;
struct V_186 V_187 ;
int V_273 ;
int V_222 = 0 ;
unsigned long V_53 ;
if ( F_139 ( V_27 -> V_64 ) ) {
F_2 ( L_47 , V_3 , V_2 ,
V_2 -> V_25 ) ;
F_141 ( V_2 -> V_5 . V_16 , V_2 -> V_63 ) ;
return V_218 ;
}
if ( ! F_122 ( V_274 , & V_2 -> V_5 . V_53 ) ) {
return V_218 ;
}
F_34 ( & V_2 -> V_5 . V_54 , V_53 ) ;
F_2 ( L_48 , V_3 , V_2 , V_2 -> V_5 . V_14 ) ;
switch ( V_2 -> V_5 . V_14 ) {
case V_259 :
break;
case V_212 :
F_7 ( V_2 ) ;
break;
case V_148 :
F_7 ( V_2 ) ;
F_87 ( V_2 , - V_67 ) ;
break;
case V_153 :
V_2 -> V_5 . V_221 = 1 ;
V_2 -> V_5 . V_236 = - V_67 ;
F_2 ( L_46 , V_2 ) ;
F_120 ( & V_2 -> V_5 . V_60 ) ;
break;
case V_213 :
V_2 -> V_5 . V_221 = 1 ;
V_2 -> V_5 . V_236 = - V_67 ;
F_2 ( L_46 , V_2 ) ;
F_120 ( & V_2 -> V_5 . V_60 ) ;
break;
case V_266 :
case V_264 :
F_7 ( V_2 ) ;
case V_194 :
if ( V_2 -> V_5 . V_166 && V_2 -> V_5 . V_169 ) {
V_187 . V_202 = V_275 ;
V_273 = F_113 ( V_2 -> V_5 . V_169 -> V_209 ,
V_2 -> V_5 . V_169 , V_204 ,
& V_187 , 1 ) ;
if ( V_273 )
F_8 (KERN_ERR MOD
L_49 ,
__func__) ;
}
F_105 ( V_2 ) ;
break;
case V_162 :
break;
case V_179 :
F_2 ( L_50 , V_3 ) ;
F_35 ( & V_2 -> V_5 . V_54 , V_53 ) ;
return V_218 ;
default:
F_85 ( 1 ) ;
break;
}
F_97 ( V_2 -> V_62 ) ;
if ( V_2 -> V_5 . V_14 != V_162 ) {
F_36 ( & V_2 -> V_5 , V_179 ) ;
V_222 = 1 ;
}
F_35 ( & V_2 -> V_5 . V_54 , V_53 ) ;
V_272 = F_18 ( V_18 , sizeof( * V_225 ) , V_28 ) ;
if ( ! V_272 ) {
F_8 (KERN_ERR MOD L_51 ,
__func__) ;
V_222 = 1 ;
goto V_211;
}
V_272 -> V_33 = V_46 ;
V_225 = (struct V_271 * ) F_19 ( V_272 , sizeof( * V_225 ) ) ;
V_225 -> V_29 . V_30 = F_20 ( F_21 ( V_276 ) ) ;
V_225 -> V_29 . V_37 = F_20 ( F_25 ( V_2 -> V_25 ) ) ;
F_22 ( V_225 ) = F_20 ( F_23 ( V_277 , V_2 -> V_25 ) ) ;
V_225 -> V_94 = V_95 ;
F_15 ( V_2 -> V_5 . V_16 , V_272 ) ;
V_211:
if ( V_222 )
F_50 ( V_2 ) ;
return V_218 ;
}
static int F_142 ( struct V_15 * V_16 , struct V_17 * V_18 , void * V_154 )
{
struct V_1 * V_2 = V_154 ;
struct V_186 V_187 ;
unsigned long V_53 ;
int V_222 = 0 ;
F_2 ( L_1 , V_3 , V_2 ) ;
F_85 ( ! V_2 ) ;
F_34 ( & V_2 -> V_5 . V_54 , V_53 ) ;
switch ( V_2 -> V_5 . V_14 ) {
case V_264 :
F_36 ( & V_2 -> V_5 , V_266 ) ;
break;
case V_266 :
F_7 ( V_2 ) ;
if ( ( V_2 -> V_5 . V_166 ) && ( V_2 -> V_5 . V_169 ) ) {
V_187 . V_202 = V_267 ;
F_113 ( V_2 -> V_5 . V_169 -> V_209 ,
V_2 -> V_5 . V_169 ,
V_204 ,
& V_187 , 1 ) ;
}
F_103 ( V_2 ) ;
F_36 ( & V_2 -> V_5 , V_179 ) ;
V_222 = 1 ;
break;
case V_162 :
case V_179 :
break;
default:
F_85 ( 1 ) ;
break;
}
F_35 ( & V_2 -> V_5 . V_54 , V_53 ) ;
if ( V_222 )
F_50 ( V_2 ) ;
return V_218 ;
}
static int F_143 ( struct V_15 * V_16 , struct V_17 * V_18 , void * V_154 )
{
struct V_1 * V_2 = V_154 ;
if ( F_33 ( & V_2 -> V_5 ) != V_194 )
return V_218 ;
F_2 ( L_1 , V_3 , V_2 ) ;
F_118 ( V_18 , sizeof( struct V_278 ) ) ;
F_2 ( L_52 , V_3 , V_18 -> V_75 ) ;
F_112 ( V_18 , V_2 -> V_5 . V_169 -> V_279 . V_280 ,
V_18 -> V_75 ) ;
V_2 -> V_5 . V_169 -> V_279 . V_281 = V_18 -> V_75 ;
V_2 -> V_5 . V_169 -> V_279 . V_282 = 0 ;
return V_218 ;
}
static int F_144 ( struct V_15 * V_16 , struct V_17 * V_18 , void * V_154 )
{
struct V_283 * V_284 = F_65 ( V_18 ) ;
struct V_1 * V_2 = V_154 ;
F_2 ( L_53 , V_3 , V_2 , V_2 -> V_25 ,
V_284 -> V_64 ) ;
if ( V_284 -> V_64 ) {
struct V_186 V_187 ;
F_8 (KERN_ERR MOD L_54 ,
__func__, ep->hwtid) ;
F_7 ( V_2 ) ;
V_187 . V_202 = V_275 ;
F_113 ( V_2 -> V_5 . V_169 -> V_209 ,
V_2 -> V_5 . V_169 , V_204 ,
& V_187 , 1 ) ;
F_102 ( V_2 , NULL , V_28 ) ;
}
return V_218 ;
}
static void V_12 ( unsigned long V_285 )
{
struct V_1 * V_2 = (struct V_1 * ) V_285 ;
struct V_186 V_187 ;
unsigned long V_53 ;
int abort = 1 ;
F_34 ( & V_2 -> V_5 . V_54 , V_53 ) ;
F_2 ( L_55 , V_3 , V_2 , V_2 -> V_25 ,
V_2 -> V_5 . V_14 ) ;
switch ( V_2 -> V_5 . V_14 ) {
case V_148 :
F_36 ( & V_2 -> V_5 , V_162 ) ;
F_87 ( V_2 , - V_71 ) ;
break;
case V_212 :
F_36 ( & V_2 -> V_5 , V_162 ) ;
break;
case V_264 :
case V_266 :
if ( V_2 -> V_5 . V_166 && V_2 -> V_5 . V_169 ) {
V_187 . V_202 = V_275 ;
F_113 ( V_2 -> V_5 . V_169 -> V_209 ,
V_2 -> V_5 . V_169 , V_204 ,
& V_187 , 1 ) ;
}
F_36 ( & V_2 -> V_5 , V_162 ) ;
break;
default:
F_8 ( V_13 L_56 ,
V_3 , V_2 , V_2 -> V_5 . V_14 ) ;
F_9 ( 1 ) ;
abort = 0 ;
}
F_35 ( & V_2 -> V_5 . V_54 , V_53 ) ;
if ( abort )
F_102 ( V_2 , NULL , V_286 ) ;
F_10 ( & V_2 -> V_5 ) ;
}
int F_145 ( struct V_287 * V_166 , const void * V_149 , T_6 V_288 )
{
int V_189 ;
struct V_1 * V_2 = F_146 ( V_166 ) ;
F_2 ( L_57 , V_3 , V_2 , V_2 -> V_25 ) ;
if ( F_33 ( & V_2 -> V_5 ) == V_179 ) {
F_10 ( & V_2 -> V_5 ) ;
return - V_67 ;
}
F_85 ( F_33 ( & V_2 -> V_5 ) != V_213 ) ;
if ( V_137 == 0 )
F_102 ( V_2 , NULL , V_28 ) ;
else {
V_189 = F_93 ( V_2 , V_149 , V_288 ) ;
V_189 = F_138 ( V_2 , 0 , V_28 ) ;
}
F_10 ( & V_2 -> V_5 ) ;
return 0 ;
}
int F_147 ( struct V_287 * V_166 , struct V_289 * V_290 )
{
int V_189 ;
struct V_186 V_187 ;
enum V_188 V_43 ;
struct V_1 * V_2 = F_146 ( V_166 ) ;
struct V_291 * V_292 = F_148 ( V_166 -> V_293 ) ;
struct V_294 * V_169 = F_149 ( V_292 , V_290 -> V_295 ) ;
F_2 ( L_57 , V_3 , V_2 , V_2 -> V_25 ) ;
if ( F_33 ( & V_2 -> V_5 ) == V_179 ) {
V_189 = - V_67 ;
goto V_189;
}
F_85 ( F_33 ( & V_2 -> V_5 ) != V_213 ) ;
F_85 ( ! V_169 ) ;
if ( ( V_290 -> V_177 > V_169 -> V_209 -> V_279 . V_296 ) ||
( V_290 -> V_176 > V_169 -> V_209 -> V_279 . V_297 ) ) {
F_102 ( V_2 , NULL , V_28 ) ;
V_189 = - V_191 ;
goto V_189;
}
V_166 -> V_298 ( V_166 ) ;
V_2 -> V_5 . V_166 = V_166 ;
V_2 -> V_5 . V_169 = V_169 ;
V_2 -> V_176 = V_290 -> V_176 ;
V_2 -> V_177 = V_290 -> V_177 ;
if ( V_210 && V_2 -> V_176 == 0 )
V_2 -> V_176 = 1 ;
F_2 ( L_58 , V_3 , __LINE__ , V_2 -> V_176 , V_2 -> V_177 ) ;
V_187 . V_152 = V_2 -> V_152 ;
V_187 . V_199 = V_2 -> V_176 ;
V_187 . V_200 = V_2 -> V_177 ;
V_187 . V_201 = V_2 ;
V_187 . V_202 = V_203 ;
V_43 = V_204 |
V_205 |
V_206 |
V_207 |
V_208 ;
V_189 = F_113 ( V_2 -> V_5 . V_169 -> V_209 ,
V_2 -> V_5 . V_169 , V_43 , & V_187 , 1 ) ;
if ( V_189 )
goto V_299;
if ( F_114 ( V_169 ) ) {
F_150 ( V_2 -> V_5 . V_60 , V_2 -> V_5 . V_221 ) ;
V_189 = V_2 -> V_5 . V_236 ;
if ( V_189 )
goto V_299;
}
V_189 = F_94 ( V_2 , V_290 -> V_138 ,
V_290 -> V_173 ) ;
if ( V_189 )
goto V_299;
F_37 ( & V_2 -> V_5 , V_194 ) ;
F_107 ( V_2 ) ;
F_10 ( & V_2 -> V_5 ) ;
return 0 ;
V_299:
V_2 -> V_5 . V_166 = NULL ;
V_2 -> V_5 . V_169 = NULL ;
V_166 -> V_168 ( V_166 ) ;
V_189:
F_10 ( & V_2 -> V_5 ) ;
return V_189 ;
}
static int F_151 ( struct V_287 * V_166 )
{
struct V_300 * V_77 ;
V_77 = F_152 ( & V_86 , V_166 -> V_120 . V_121 . V_122 ) ;
if ( ! V_77 )
return 0 ;
F_153 ( V_77 ) ;
return 1 ;
}
int F_154 ( struct V_287 * V_166 , struct V_289 * V_290 )
{
struct V_291 * V_292 = F_148 ( V_166 -> V_293 ) ;
struct V_1 * V_2 ;
struct V_76 * V_83 ;
int V_189 = 0 ;
if ( F_151 ( V_166 ) ) {
V_189 = - V_301 ;
goto V_211;
}
V_2 = F_38 ( sizeof( * V_2 ) , V_28 ) ;
if ( ! V_2 ) {
F_8 (KERN_ERR MOD L_59 , __func__) ;
V_189 = - V_36 ;
goto V_211;
}
F_135 ( & V_2 -> V_4 ) ;
V_2 -> V_128 = V_290 -> V_173 ;
if ( V_2 -> V_128 )
memcpy ( V_2 -> V_139 + sizeof( struct V_126 ) ,
V_290 -> V_138 , V_2 -> V_128 ) ;
V_2 -> V_176 = V_290 -> V_176 ;
V_2 -> V_177 = V_290 -> V_177 ;
if ( V_210 && V_2 -> V_177 == 0 )
V_2 -> V_177 = 1 ;
V_2 -> V_5 . V_16 = V_292 -> V_22 . V_302 ;
V_166 -> V_298 ( V_166 ) ;
V_2 -> V_5 . V_166 = V_166 ;
V_2 -> V_5 . V_169 = F_149 ( V_292 , V_290 -> V_295 ) ;
F_85 ( ! V_2 -> V_5 . V_169 ) ;
F_2 ( L_60 , V_3 , V_290 -> V_295 ,
V_2 -> V_5 . V_169 , V_166 ) ;
V_2 -> V_117 = F_155 ( V_292 -> V_22 . V_302 , & V_157 , V_2 ) ;
if ( V_2 -> V_117 == - 1 ) {
F_8 (KERN_ERR MOD L_61 , __func__) ;
V_189 = - V_36 ;
goto V_303;
}
V_83 = F_58 ( V_292 -> V_22 . V_302 ,
V_166 -> V_118 . V_121 . V_122 ,
V_166 -> V_120 . V_121 . V_122 ,
V_166 -> V_118 . V_119 ,
V_166 -> V_120 . V_119 , V_304 ) ;
if ( ! V_83 ) {
F_8 (KERN_ERR MOD L_62 , __func__) ;
V_189 = - V_69 ;
goto V_305;
}
V_2 -> V_62 = & V_83 -> V_62 ;
V_2 -> V_63 = F_134 ( V_2 -> V_5 . V_16 , V_2 -> V_62 , NULL ,
& V_166 -> V_120 . V_121 . V_122 ) ;
if ( ! V_2 -> V_63 ) {
F_8 (KERN_ERR MOD L_63 , __func__) ;
V_189 = - V_36 ;
goto V_306;
}
F_37 ( & V_2 -> V_5 , V_259 ) ;
V_2 -> V_82 = V_304 ;
V_2 -> V_5 . V_118 = V_166 -> V_118 ;
V_2 -> V_5 . V_120 = V_166 -> V_120 ;
V_189 = F_69 ( V_2 ) ;
if ( ! V_189 )
goto V_211;
F_48 ( V_292 -> V_22 . V_302 , V_2 -> V_63 ) ;
V_306:
F_47 ( V_2 -> V_62 ) ;
V_305:
F_101 ( V_2 -> V_5 . V_16 , V_2 -> V_117 ) ;
V_303:
V_166 -> V_168 ( V_166 ) ;
F_10 ( & V_2 -> V_5 ) ;
V_211:
return V_189 ;
}
int F_156 ( struct V_287 * V_166 , int V_307 )
{
int V_189 = 0 ;
struct V_291 * V_292 = F_148 ( V_166 -> V_293 ) ;
struct V_227 * V_2 ;
F_157 () ;
V_2 = F_38 ( sizeof( * V_2 ) , V_28 ) ;
if ( ! V_2 ) {
F_8 (KERN_ERR MOD L_59 , __func__) ;
V_189 = - V_36 ;
goto V_308;
}
F_2 ( L_1 , V_3 , V_2 ) ;
V_2 -> V_5 . V_16 = V_292 -> V_22 . V_302 ;
V_166 -> V_298 ( V_166 ) ;
V_2 -> V_5 . V_166 = V_166 ;
V_2 -> V_307 = V_307 ;
V_2 -> V_5 . V_118 = V_166 -> V_118 ;
V_2 -> V_230 = F_158 ( V_292 -> V_22 . V_302 , & V_157 , V_2 ) ;
if ( V_2 -> V_230 == - 1 ) {
F_8 (KERN_ERR MOD L_61 , __func__) ;
V_189 = - V_36 ;
goto V_303;
}
F_37 ( & V_2 -> V_5 , V_251 ) ;
V_189 = F_125 ( V_2 ) ;
if ( V_189 )
goto V_305;
F_150 ( V_2 -> V_5 . V_60 , V_2 -> V_5 . V_221 ) ;
V_189 = V_2 -> V_5 . V_236 ;
if ( ! V_189 ) {
V_166 -> V_175 = V_2 ;
goto V_211;
}
V_305:
F_159 ( V_2 -> V_5 . V_16 , V_2 -> V_230 ) ;
V_303:
V_166 -> V_168 ( V_166 ) ;
F_10 ( & V_2 -> V_5 ) ;
V_308:
V_211:
return V_189 ;
}
int F_160 ( struct V_287 * V_166 )
{
int V_189 ;
struct V_227 * V_2 = F_161 ( V_166 ) ;
F_2 ( L_1 , V_3 , V_2 ) ;
F_157 () ;
F_37 ( & V_2 -> V_5 , V_179 ) ;
V_2 -> V_5 . V_221 = 0 ;
V_2 -> V_5 . V_236 = 0 ;
V_189 = F_128 ( V_2 ) ;
if ( V_189 )
goto V_309;
F_150 ( V_2 -> V_5 . V_60 , V_2 -> V_5 . V_221 ) ;
F_159 ( V_2 -> V_5 . V_16 , V_2 -> V_230 ) ;
V_309:
V_189 = V_2 -> V_5 . V_236 ;
V_166 -> V_168 ( V_166 ) ;
F_10 ( & V_2 -> V_5 ) ;
return V_189 ;
}
int F_138 ( struct V_1 * V_2 , int V_310 , T_3 V_58 )
{
int V_273 = 0 ;
unsigned long V_53 ;
int V_311 = 0 ;
int V_312 = 0 ;
struct V_15 * V_16 ;
struct V_21 * V_22 ;
F_34 ( & V_2 -> V_5 . V_54 , V_53 ) ;
F_2 ( L_64 , V_3 , V_2 ,
V_56 [ V_2 -> V_5 . V_14 ] , V_310 ) ;
V_16 = (struct V_15 * ) V_2 -> V_5 . V_16 ;
V_22 = (struct V_21 * ) V_16 -> V_23 ;
if ( F_12 ( V_22 ) ) {
V_312 = 1 ;
F_103 ( V_2 ) ;
V_2 -> V_5 . V_14 = V_179 ;
}
switch ( V_2 -> V_5 . V_14 ) {
case V_212 :
case V_148 :
case V_213 :
case V_153 :
case V_194 :
V_311 = 1 ;
if ( V_310 )
V_2 -> V_5 . V_14 = V_162 ;
else {
V_2 -> V_5 . V_14 = V_264 ;
F_1 ( V_2 ) ;
}
F_51 ( V_313 , & V_2 -> V_5 . V_53 ) ;
break;
case V_264 :
if ( ! F_122 ( V_313 , & V_2 -> V_5 . V_53 ) ) {
V_311 = 1 ;
if ( V_310 ) {
F_7 ( V_2 ) ;
V_2 -> V_5 . V_14 = V_162 ;
} else
V_2 -> V_5 . V_14 = V_266 ;
}
break;
case V_266 :
case V_162 :
case V_179 :
F_2 ( L_65 ,
V_3 , V_2 , V_2 -> V_5 . V_14 ) ;
break;
default:
F_162 () ;
break;
}
F_35 ( & V_2 -> V_5 . V_54 , V_53 ) ;
if ( V_311 ) {
if ( V_310 )
V_273 = F_68 ( V_2 , NULL , V_58 ) ;
else
V_273 = F_66 ( V_2 , V_58 ) ;
if ( V_273 )
V_312 = 1 ;
}
if ( V_312 )
F_50 ( V_2 ) ;
return V_273 ;
}
int F_163 ( void * V_154 , struct V_248 * V_314 , struct V_248 * V_55 ,
struct V_19 * V_63 )
{
struct V_1 * V_2 = V_154 ;
if ( V_2 -> V_62 != V_314 )
return 0 ;
F_2 ( L_66 , V_3 , V_2 , V_55 ,
V_63 ) ;
F_164 ( V_55 ) ;
F_48 ( V_2 -> V_5 . V_16 , V_2 -> V_63 ) ;
V_2 -> V_63 = V_63 ;
F_47 ( V_314 ) ;
V_2 -> V_62 = V_55 ;
return 1 ;
}
static void F_165 ( struct V_315 * V_316 )
{
struct V_17 * V_18 = NULL ;
void * V_2 ;
struct V_15 * V_16 ;
int V_273 ;
while ( ( V_18 = F_166 ( & V_317 ) ) ) {
V_2 = * ( ( void * * ) ( V_18 -> V_318 ) ) ;
V_16 = * ( (struct V_15 * * ) ( V_18 -> V_318 + sizeof( void * ) ) ) ;
V_273 = V_319 [ F_167 ( F_99 ( ( V_320 T_4 ) V_18 -> V_321 ) ) ] ( V_16 , V_18 , V_2 ) ;
if ( V_273 & V_218 )
F_13 ( V_18 ) ;
F_10 ( (struct V_51 * ) V_2 ) ;
}
}
static int F_168 ( struct V_15 * V_16 , struct V_17 * V_18 , void * V_154 )
{
struct V_51 * V_52 = V_154 ;
F_5 ( V_52 ) ;
* ( ( void * * ) V_18 -> V_318 ) = V_154 ;
* ( (struct V_15 * * ) ( V_18 -> V_318 + sizeof( void * ) ) ) = V_16 ;
F_169 ( & V_317 , V_18 ) ;
F_170 ( V_322 , & V_323 ) ;
return 0 ;
}
static int F_171 ( struct V_15 * V_16 , struct V_17 * V_18 , void * V_154 )
{
struct V_324 * V_225 = F_65 ( V_18 ) ;
if ( V_225 -> V_64 != V_65 ) {
F_8 (KERN_ERR MOD L_67
L_68 , rpl->status, GET_TID(rpl)) ;
}
return V_218 ;
}
int T_7 F_172 ( void )
{
F_173 ( & V_317 ) ;
V_322 = F_174 ( L_69 ) ;
if ( ! V_322 )
return - V_36 ;
return 0 ;
}
void T_8 F_175 ( void )
{
F_176 ( V_322 ) ;
F_177 ( V_322 ) ;
}
