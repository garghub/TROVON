static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static struct V_1 * F_3 ( struct V_5 * V_6 , T_1 V_7 )
{
struct V_1 * V_3 ;
T_1 V_8 ;
T_1 V_9 ;
V_8 = sizeof( struct V_10 ) * V_11 ;
if ( ! ( ( V_7 >= V_6 -> V_12 ) &&
( V_7 < ( V_6 -> V_12 + V_8 ) ) ) ) {
return NULL ;
}
V_9 = ( V_7 - V_6 -> V_12 ) / sizeof( struct V_10 ) ;
F_4 ( V_9 >= V_11 ) ;
V_3 = V_6 -> V_13 [ V_9 ] ;
V_6 -> V_13 [ V_9 ] = NULL ;
F_5 ( V_6 -> V_14 . V_15 ) ;
return V_3 ;
}
static void F_6 ( T_1 V_16 , void * T_2 * V_17 )
{
F_7 ( V_16 , V_17 ) ;
}
static T_1 F_8 ( void * T_2 * V_17 )
{
return F_9 ( V_17 ) ;
}
static T_1 F_10 ( T_1 V_16 )
{
return V_16 & ( ( 1 << ( V_18 + 1 ) ) - 1 ) ;
}
static T_1 F_11 ( struct V_5 * V_6 , unsigned V_19 )
{
T_1 V_7 ;
V_7 = F_8 ( V_6 -> V_20 + F_12 ( V_19 ) ) ;
V_7 &= ~ 0x1f ;
return V_7 ;
}
static T_3 F_13 ( int V_21 , void * V_22 )
{
struct V_5 * V_6 = V_22 ;
T_4 V_23 = V_6 -> V_23 ;
T_4 V_24 = V_6 -> V_24 ;
struct V_1 * V_3 ;
int V_25 ;
for ( V_25 = F_14 ( V_23 ) ; V_25 < V_24 ;
V_25 ++ ) {
T_1 V_16 ;
T_1 V_26 ;
V_16 = F_8 ( V_6 -> V_20 + F_15 ( V_25 ) ) ;
if ( V_25 == F_14 ( V_23 ) && V_16 ) {
T_1 V_27 ;
V_27 = 1 << F_16 ( V_23 ) ;
V_27 -- ;
V_16 &= ~ V_27 ;
}
if ( V_16 )
F_17 () ;
while ( V_16 ) {
T_1 V_7 , V_28 ;
F_18 ( V_6 -> V_29 ) ;
V_26 = F_19 ( V_16 ) ;
V_16 &= ~ ( 1 << V_26 ) ;
V_26 += 32 * V_25 ;
V_7 = F_11 ( V_6 , V_26 ) ;
V_3 = F_3 ( V_6 , V_7 ) ;
if ( F_18 ( ! V_3 ) ) {
F_20 ( L_1 , V_30 ,
V_26 , V_7 ) ;
continue;
}
if ( V_3 -> V_7 -> V_31 & V_32 )
V_28 = 0 ;
else
V_28 = F_10 ( V_3 -> V_7 -> V_33 ) ;
V_3 -> V_34 = F_10 ( V_3 -> V_7 -> V_35 ) - V_28 ;
F_21 ( & V_3 -> V_36 ) ;
F_22 ( & V_3 -> V_36 , NULL ) ;
}
}
return V_37 ;
}
static T_5 F_23 ( struct V_38 * V_39 )
{
T_5 V_40 ;
V_40 = F_24 ( V_39 ) ;
return V_40 ;
}
static int F_25 ( struct V_2 * V_4 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_3 -> V_6 ;
int error ;
error = F_26 ( V_6 -> V_14 . V_15 ) ;
if ( error < 0 ) {
F_27 ( V_6 -> V_14 . V_15 , L_2 ,
V_30 , error ) ;
F_28 ( V_6 -> V_14 . V_15 ) ;
return error ;
}
F_29 ( V_4 ) ;
F_30 ( & V_3 -> V_36 , V_4 ) ;
V_3 -> V_36 . V_41 = F_23 ;
if ( ! V_3 -> V_42 )
F_6 ( V_3 -> V_26 , V_3 -> V_43 + V_44 ) ;
F_31 ( V_6 -> V_14 . V_15 ) ;
F_32 ( V_6 -> V_14 . V_15 ) ;
return 0 ;
}
static void F_33 ( struct V_2 * V_4 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_3 -> V_6 ;
int error ;
error = F_26 ( V_6 -> V_14 . V_15 ) ;
if ( error < 0 ) {
F_28 ( V_6 -> V_14 . V_15 ) ;
return;
}
F_18 ( ! F_34 ( & V_6 -> V_45 ) ) ;
F_31 ( V_6 -> V_14 . V_15 ) ;
F_32 ( V_6 -> V_14 . V_15 ) ;
}
static enum V_46 F_35 ( struct V_2 * V_4 ,
T_5 V_40 , struct V_47 * V_48 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
enum V_46 V_49 ;
V_49 = F_36 ( V_4 , V_40 , V_48 ) ;
F_37 ( V_48 , V_3 -> V_34 ) ;
return V_49 ;
}
static void F_38 ( struct V_1 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_1 V_9 ;
T_1 V_50 ;
T_1 V_51 ;
V_3 -> V_34 = 0 ;
V_51 = V_52 ;
if ( ! V_3 -> V_42 ) {
V_51 |= V_53 ;
V_51 |= V_54 ;
V_51 |= V_3 -> V_55 ;
}
F_6 ( V_51 , V_3 -> V_43 ) ;
F_39 () ;
F_40 ( V_6 -> V_14 . V_15 ) ;
V_50 = F_41 ( V_3 -> V_50 ) ;
V_9 = ( V_50 - V_6 -> V_12 ) / sizeof( struct V_10 ) ;
F_18 ( V_6 -> V_13 [ V_9 ] ) ;
V_6 -> V_13 [ V_9 ] = V_3 ;
V_51 = ( sizeof( struct V_10 ) - 24 ) / 4 ;
V_51 |= V_50 ;
F_6 ( V_51 , V_6 -> V_20 + F_12 ( V_3 -> V_26 ) ) ;
}
static void F_42 ( struct V_5 * V_6 )
{
struct V_1 * V_3 , * V_56 ;
F_43 (c, _c, &cdd->pending, node) {
F_38 ( V_3 ) ;
F_44 ( & V_3 -> V_57 ) ;
}
}
static void F_45 ( struct V_2 * V_4 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_3 -> V_6 ;
unsigned long V_58 ;
int error ;
error = F_40 ( V_6 -> V_14 . V_15 ) ;
if ( ( error != - V_59 ) && error < 0 ) {
F_28 ( V_6 -> V_14 . V_15 ) ;
F_27 ( V_6 -> V_14 . V_15 , L_3 ,
error ) ;
return;
}
F_46 ( & V_6 -> V_60 , V_58 ) ;
F_47 ( & V_3 -> V_57 , & V_6 -> V_45 ) ;
if ( ! V_6 -> V_29 )
F_42 ( V_6 ) ;
F_48 ( & V_6 -> V_60 , V_58 ) ;
F_31 ( V_6 -> V_14 . V_15 ) ;
F_32 ( V_6 -> V_14 . V_15 ) ;
}
static T_1 F_49 ( T_1 V_61 )
{
T_1 V_51 ;
V_51 = V_62 << V_63 ;
V_51 |= V_61 ;
return V_51 ;
}
static T_1 F_50 ( struct V_1 * V_3 )
{
T_1 V_51 ;
V_51 = 0 ;
return V_51 ;
}
static T_1 F_51 ( struct V_1 * V_3 )
{
T_1 V_51 ;
V_51 = V_64 ;
V_51 |= V_3 -> V_55 ;
return V_51 ;
}
static T_1 F_52 ( T_1 V_61 )
{
T_1 V_51 ;
V_51 = V_61 ;
return V_51 ;
}
static T_1 F_53 ( T_1 V_61 )
{
T_1 V_51 ;
V_51 = V_65 ;
V_51 |= V_61 ;
return V_51 ;
}
static T_1 F_54 ( T_1 V_66 )
{
T_1 V_51 ;
V_51 = V_66 ;
return V_51 ;
}
static T_1 F_55 ( void )
{
T_1 V_51 ;
V_51 = 0 ;
return V_51 ;
}
static struct V_38 * F_56 (
struct V_2 * V_4 , struct V_67 * V_68 , unsigned V_69 ,
enum V_70 V_71 , unsigned long V_72 , void * V_73 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_10 * V_74 ;
struct V_67 * V_75 ;
unsigned int V_25 ;
V_74 = V_3 -> V_7 ;
F_57 (sgl, sg, sg_len, i) {
T_1 V_66 ;
T_1 V_28 ;
V_66 = F_41 ( F_58 ( V_75 ) ) ;
V_28 = F_59 ( V_75 ) ;
V_74 -> V_33 = F_49 ( V_28 ) ;
V_74 -> V_76 = F_50 ( V_3 ) ;
V_74 -> V_31 = F_51 ( V_3 ) ;
V_74 -> V_77 = F_52 ( V_28 ) ;
V_74 -> V_78 = F_54 ( V_66 ) ;
V_74 -> V_79 = F_55 () ;
V_74 -> V_35 = F_53 ( V_28 ) ;
V_74 -> V_80 = F_54 ( V_66 ) ;
V_74 ++ ;
}
return & V_3 -> V_36 ;
}
static void F_60 ( struct V_10 * V_74 )
{
V_74 -> V_33 = V_81 << V_63 ;
}
static int F_61 ( struct V_1 * V_3 )
{
struct V_82 V_83 ;
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_10 * V_84 ;
T_1 V_51 ;
T_1 V_50 ;
T_1 V_85 ;
V_84 = V_6 -> V_86 ;
V_84 += V_6 -> V_87 ;
V_85 = V_6 -> V_12 ;
V_85 += V_6 -> V_87 * sizeof( struct V_10 ) ;
if ( ! V_3 -> V_88 ) {
F_60 ( V_84 ) ;
F_39 () ;
V_51 = ( sizeof( struct V_10 ) - 24 ) / 4 ;
V_51 |= V_85 ;
F_6 ( V_51 , V_6 -> V_20 +
F_12 ( V_6 -> V_89 . V_90 ) ) ;
V_51 = V_52 ;
if ( ! V_3 -> V_42 ) {
V_51 |= V_53 ;
V_51 |= V_54 ;
V_51 |= V_6 -> V_89 . V_91 ;
}
V_51 |= V_92 ;
F_6 ( V_51 , V_3 -> V_43 ) ;
V_3 -> V_88 = 1 ;
V_3 -> V_93 = 500 ;
}
if ( ! V_3 -> V_94 || ! V_3 -> V_95 ) {
V_50 = F_11 ( V_6 , V_6 -> V_89 . V_91 ) ;
if ( ! V_50 && V_3 -> V_42 )
V_50 = F_11 ( V_6 , V_3 -> V_55 ) ;
if ( V_50 == V_3 -> V_50 ) {
V_3 -> V_95 = 1 ;
} else if ( V_50 == V_85 ) {
T_1 V_33 ;
F_17 () ;
V_33 = V_84 -> V_33 ;
F_18 ( ( V_33 >> V_63 ) != V_81 ) ;
F_18 ( ! V_3 -> V_42 && ! ( V_33 & V_96 ) ) ;
F_18 ( ( V_33 & 0x1f ) != V_3 -> V_97 ) ;
V_3 -> V_94 = 1 ;
} else if ( V_50 ) {
F_62 ( 1 ) ;
}
}
V_3 -> V_93 -- ;
if ( ! V_3 -> V_94 && V_3 -> V_93 ) {
F_63 ( 1 ) ;
return - V_98 ;
}
F_18 ( ! V_3 -> V_93 ) ;
if ( ! V_3 -> V_95 ) {
V_50 = F_11 ( V_6 , V_3 -> V_26 ) ;
if ( ! V_50 )
V_50 = F_11 ( V_6 , V_3 -> V_55 ) ;
F_18 ( ! V_50 ) ;
}
V_3 -> V_88 = 0 ;
V_3 -> V_94 = 0 ;
V_3 -> V_95 = 0 ;
F_6 ( 0 , V_3 -> V_43 ) ;
V_83 . V_99 = V_100 ;
F_21 ( & V_3 -> V_36 ) ;
F_22 ( & V_3 -> V_36 , & V_83 ) ;
return 0 ;
}
static int F_64 ( struct V_2 * V_4 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_3 -> V_6 ;
T_1 V_9 ;
T_1 V_50 ;
int V_49 ;
V_50 = F_41 ( V_3 -> V_50 ) ;
V_9 = ( V_50 - V_6 -> V_12 ) / sizeof( struct V_10 ) ;
if ( ! V_6 -> V_13 [ V_9 ] )
return 0 ;
V_49 = F_61 ( V_3 ) ;
if ( V_49 )
return V_49 ;
F_18 ( ! V_6 -> V_13 [ V_9 ] ) ;
V_6 -> V_13 [ V_9 ] = NULL ;
F_5 ( V_6 -> V_14 . V_15 ) ;
return 0 ;
}
static int F_65 ( struct V_101 * V_15 , struct V_5 * V_6 )
{
struct V_1 * V_102 , * V_103 ;
int V_25 ;
T_1 V_104 = V_6 -> V_104 ;
V_104 *= 2 ;
V_103 = F_66 ( V_15 , V_104 , sizeof( * V_103 ) , V_105 ) ;
if ( ! V_103 )
return - V_106 ;
for ( V_25 = 0 ; V_25 < V_104 ; V_25 ++ ) {
V_102 = & V_103 [ V_25 ] ;
V_102 -> V_6 = V_6 ;
if ( V_25 & 1 ) {
V_102 -> V_43 = V_6 -> V_107 + F_67 ( V_25 >> 1 ) ;
V_102 -> V_42 = 1 ;
} else {
V_102 -> V_43 = V_6 -> V_107 + F_68 ( V_25 >> 1 ) ;
V_102 -> V_42 = 0 ;
}
V_102 -> V_97 = V_25 >> 1 ;
V_102 -> V_7 = & V_6 -> V_86 [ V_25 ] ;
V_102 -> V_50 = V_6 -> V_12 ;
V_102 -> V_50 += V_25 * sizeof( struct V_10 ) ;
V_102 -> V_4 . V_101 = & V_6 -> V_14 ;
F_47 ( & V_102 -> V_4 . V_108 , & V_6 -> V_14 . V_109 ) ;
}
V_6 -> V_87 = V_104 ;
return 0 ;
}
static void F_69 ( struct V_101 * V_15 , struct V_5 * V_6 )
{
unsigned int V_110 ;
int V_25 ;
V_110 = V_11 * sizeof( struct V_10 ) ;
for ( V_25 = 0 ; V_25 < V_111 ; V_25 ++ ) {
F_6 ( 0 , V_6 -> V_20 + F_70 ( V_25 ) ) ;
F_6 ( 0 , V_6 -> V_20 + F_71 ( V_25 ) ) ;
F_72 ( V_15 , V_110 , V_6 -> V_86 ,
V_6 -> V_12 ) ;
}
}
static void F_73 ( struct V_5 * V_6 )
{
F_6 ( 0 , V_6 -> V_112 + V_113 ) ;
}
static void F_74 ( struct V_101 * V_15 , struct V_5 * V_6 )
{
F_73 ( V_6 ) ;
F_69 ( V_15 , V_6 ) ;
F_6 ( 0 , V_6 -> V_20 + V_114 ) ;
F_6 ( 0 , V_6 -> V_20 + V_114 ) ;
F_72 ( V_15 , V_115 , V_6 -> V_116 ,
V_6 -> V_117 ) ;
}
static int F_75 ( struct V_101 * V_15 , struct V_5 * V_6 )
{
unsigned int V_118 ;
unsigned int V_110 ;
int V_25 ;
T_1 V_51 ;
T_1 V_119 ;
F_76 ( sizeof( struct V_10 ) &
( sizeof( struct V_10 ) - 1 ) ) ;
F_76 ( sizeof( struct V_10 ) < 32 ) ;
F_76 ( V_11 < 32 ) ;
V_118 = sizeof( struct V_10 ) ;
V_110 = V_11 * V_118 ;
V_119 = 0 ;
for ( V_25 = 0 ; V_25 < V_111 ; V_25 ++ ) {
V_51 = V_119 << V_120 ;
V_51 |= ( F_77 ( V_118 ) - 5 ) << V_121 ;
V_51 |= F_77 ( V_11 ) - 5 ;
F_76 ( V_111 != 1 ) ;
V_6 -> V_86 = F_78 ( V_15 , V_110 ,
& V_6 -> V_12 , V_105 ) ;
if ( ! V_6 -> V_86 )
return - V_106 ;
F_6 ( V_6 -> V_12 , V_6 -> V_20 + F_70 ( V_25 ) ) ;
F_6 ( V_51 , V_6 -> V_20 + F_71 ( V_25 ) ) ;
V_119 += V_11 ;
}
return 0 ;
}
static void F_79 ( struct V_5 * V_6 )
{
unsigned V_122 ;
unsigned V_123 ;
T_1 V_51 ;
V_123 = 0 ;
F_6 ( 0 , V_6 -> V_112 + V_113 ) ;
for ( V_122 = 0 ; V_122 < V_6 -> V_104 ; V_122 += 2 ) {
V_51 = F_80 ( V_122 ) ;
V_51 |= F_81 ( V_122 ) | V_124 ;
V_51 |= F_82 ( V_122 + 1 ) ;
V_51 |= F_83 ( V_122 + 1 ) | V_125 ;
F_6 ( V_51 , V_6 -> V_112 + F_84 ( V_123 ) ) ;
V_123 ++ ;
}
V_51 = V_6 -> V_104 * 2 - 1 ;
V_51 |= V_126 ;
F_6 ( V_51 , V_6 -> V_112 + V_113 ) ;
}
static int F_85 ( struct V_101 * V_15 , struct V_5 * V_6 )
{
int V_49 ;
F_76 ( V_115 > ( ( 1 << 14 ) - 1 ) ) ;
V_6 -> V_116 = F_78 ( V_15 , V_115 ,
& V_6 -> V_117 , V_105 ) ;
if ( ! V_6 -> V_116 )
return - V_106 ;
F_6 ( V_6 -> V_117 , V_6 -> V_20 + V_114 ) ;
F_6 ( V_127 , V_6 -> V_20 + V_128 ) ;
F_6 ( 0 , V_6 -> V_20 + V_129 ) ;
V_49 = F_75 ( V_15 , V_6 ) ;
if ( V_49 )
goto V_130;
F_6 ( V_6 -> V_89 . V_90 , V_6 -> V_107 + V_131 ) ;
F_79 ( V_6 ) ;
return 0 ;
V_130:
F_74 ( V_15 , V_6 ) ;
return V_49 ;
}
static bool F_86 ( struct V_2 * V_4 , void * V_132 )
{
struct V_1 * V_102 ;
struct V_5 * V_6 ;
const struct V_133 * V_134 ;
T_1 * V_135 = V_132 ;
if ( V_4 -> V_101 -> V_15 -> V_136 != & V_137 . V_136 )
return false ;
V_102 = F_1 ( V_4 ) ;
if ( V_102 -> V_97 != V_135 [ V_138 ] )
return false ;
if ( V_102 -> V_42 && ! V_135 [ V_139 ] )
return false ;
V_6 = V_102 -> V_6 ;
if ( V_102 -> V_42 )
V_134 = V_6 -> V_140 ;
else
V_134 = V_6 -> V_141 ;
F_76 ( F_87 ( V_142 ) !=
F_87 ( V_143 ) ) ;
if ( F_18 ( V_102 -> V_97 > F_87 ( V_142 ) ) )
return false ;
V_102 -> V_26 = V_134 [ V_102 -> V_97 ] . V_90 ;
V_102 -> V_55 = V_134 [ V_102 -> V_97 ] . V_91 ;
return true ;
}
static struct V_2 * F_88 ( struct V_144 * V_145 ,
struct V_146 * V_147 )
{
int V_148 = V_145 -> V_149 ;
struct V_150 * V_151 = V_147 -> V_152 ;
if ( ! V_151 || ! V_151 -> V_153 )
return NULL ;
if ( V_148 != 2 )
return NULL ;
return F_89 ( V_151 -> V_154 , V_151 -> V_153 ,
& V_145 -> args [ 0 ] ) ;
}
static const struct V_155 * F_90 ( struct V_101 * V_15 )
{
const struct V_156 * V_157 ;
V_157 = F_91 ( V_158 , V_15 -> V_159 ) ;
if ( ! V_157 )
return NULL ;
return V_157 -> V_22 ;
}
static int F_92 ( struct V_160 * V_161 )
{
struct V_5 * V_6 ;
struct V_101 * V_15 = & V_161 -> V_15 ;
const struct V_155 * V_162 ;
struct V_163 * V_17 ;
int V_164 ;
int V_21 ;
int V_49 ;
V_162 = F_90 ( V_15 ) ;
if ( ! V_162 )
return - V_165 ;
V_6 = F_93 ( & V_161 -> V_15 , sizeof( * V_6 ) , V_105 ) ;
if ( ! V_6 )
return - V_106 ;
F_94 ( V_166 , V_6 -> V_14 . V_167 ) ;
V_6 -> V_14 . V_168 = F_25 ;
V_6 -> V_14 . V_169 = F_33 ;
V_6 -> V_14 . V_170 = F_35 ;
V_6 -> V_14 . V_171 = F_45 ;
V_6 -> V_14 . V_172 = F_56 ;
V_6 -> V_14 . V_173 = F_64 ;
V_6 -> V_14 . V_174 = F_95 ( V_175 ) | F_95 ( V_176 ) ;
V_6 -> V_14 . V_177 = V_178 ;
V_6 -> V_14 . V_179 = V_178 ;
V_6 -> V_14 . V_180 = V_181 ;
V_6 -> V_14 . V_15 = V_15 ;
F_96 ( & V_6 -> V_14 . V_109 ) ;
V_182 . V_154 = V_6 -> V_14 . V_167 ;
V_164 = F_97 ( V_15 -> V_159 ,
L_4 , L_5 ) ;
if ( V_164 < 0 )
return V_164 ;
V_17 = F_98 ( V_161 , V_183 , V_164 ) ;
V_6 -> V_107 = F_99 ( V_15 , V_17 ) ;
if ( F_100 ( V_6 -> V_107 ) )
return F_101 ( V_6 -> V_107 ) ;
V_17 = F_98 ( V_161 , V_183 , V_164 + 1 ) ;
V_6 -> V_112 = F_99 ( V_15 , V_17 ) ;
if ( F_100 ( V_6 -> V_112 ) )
return F_101 ( V_6 -> V_112 ) ;
V_17 = F_98 ( V_161 , V_183 , V_164 + 2 ) ;
V_6 -> V_20 = F_99 ( V_15 , V_17 ) ;
if ( F_100 ( V_6 -> V_20 ) )
return F_101 ( V_6 -> V_20 ) ;
F_102 ( & V_6 -> V_60 ) ;
F_96 ( & V_6 -> V_45 ) ;
F_103 ( V_161 , V_6 ) ;
F_104 ( V_15 ) ;
F_105 ( V_15 , 100 ) ;
F_106 ( V_15 ) ;
V_49 = F_26 ( V_15 ) ;
if ( V_49 < 0 )
goto V_184;
V_6 -> V_141 = V_162 -> V_141 ;
V_6 -> V_140 = V_162 -> V_140 ;
V_6 -> V_89 = V_162 -> V_89 ;
V_6 -> V_24 = V_162 -> V_24 ;
V_6 -> V_23 = V_162 -> V_23 ;
V_49 = F_107 ( V_15 -> V_159 ,
L_6 , & V_6 -> V_104 ) ;
if ( V_49 )
goto V_185;
V_49 = F_85 ( V_15 , V_6 ) ;
if ( V_49 )
goto V_186;
V_49 = F_65 ( V_15 , V_6 ) ;
if ( V_49 )
goto V_187;
V_21 = F_108 ( V_15 -> V_159 , 0 ) ;
if ( ! V_21 ) {
V_49 = - V_165 ;
goto V_187;
}
V_49 = F_109 ( & V_161 -> V_15 , V_21 , F_13 , V_188 ,
F_110 ( V_15 ) , V_6 ) ;
if ( V_49 )
goto V_187;
V_6 -> V_21 = V_21 ;
V_49 = F_111 ( & V_6 -> V_14 ) ;
if ( V_49 )
goto V_187;
V_49 = F_112 ( V_15 -> V_159 ,
F_88 , & V_182 ) ;
if ( V_49 )
goto V_189;
F_31 ( V_15 ) ;
F_32 ( V_15 ) ;
return 0 ;
V_189:
F_113 ( & V_6 -> V_14 ) ;
V_187:
F_74 ( V_15 , V_6 ) ;
V_186:
F_114 ( V_15 ) ;
V_185:
V_184:
F_115 ( V_15 ) ;
F_116 ( V_15 ) ;
return V_49 ;
}
static int F_117 ( struct V_160 * V_161 )
{
struct V_5 * V_6 = F_118 ( V_161 ) ;
int error ;
error = F_26 ( & V_161 -> V_15 ) ;
if ( error < 0 )
F_27 ( & V_161 -> V_15 , L_7 ,
V_30 , error ) ;
F_119 ( V_161 -> V_15 . V_159 ) ;
F_113 ( & V_6 -> V_14 ) ;
F_120 ( & V_161 -> V_15 , V_6 -> V_21 , V_6 ) ;
F_74 ( & V_161 -> V_15 , V_6 ) ;
F_114 ( & V_161 -> V_15 ) ;
F_115 ( & V_161 -> V_15 ) ;
F_116 ( & V_161 -> V_15 ) ;
return 0 ;
}
static int T_6 F_121 ( struct V_101 * V_15 )
{
struct V_5 * V_6 = F_122 ( V_15 ) ;
V_6 -> V_190 = F_8 ( V_6 -> V_107 + V_131 ) ;
F_73 ( V_6 ) ;
return 0 ;
}
static int T_6 F_123 ( struct V_101 * V_15 )
{
struct V_5 * V_6 = F_122 ( V_15 ) ;
struct V_1 * V_3 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_111 ; V_25 ++ )
F_6 ( V_6 -> V_12 , V_6 -> V_20 + F_70 ( V_25 ) ) ;
F_124 (c, &cdd->ddev.channels, chan.device_node)
if ( ! V_3 -> V_42 )
F_6 ( V_3 -> V_26 , V_3 -> V_43 + V_44 ) ;
F_79 ( V_6 ) ;
F_6 ( V_6 -> V_190 , V_6 -> V_107 + V_131 ) ;
F_6 ( V_6 -> V_117 , V_6 -> V_20 + V_114 ) ;
F_6 ( V_115 , V_6 -> V_20 + V_128 ) ;
F_6 ( 0 , V_6 -> V_20 + V_129 ) ;
return 0 ;
}
static int T_6 F_125 ( struct V_101 * V_15 )
{
struct V_5 * V_6 = F_122 ( V_15 ) ;
unsigned long V_58 ;
F_46 ( & V_6 -> V_60 , V_58 ) ;
V_6 -> V_29 = true ;
F_18 ( ! F_34 ( & V_6 -> V_45 ) ) ;
F_48 ( & V_6 -> V_60 , V_58 ) ;
return 0 ;
}
static int T_6 F_126 ( struct V_101 * V_15 )
{
struct V_5 * V_6 = F_122 ( V_15 ) ;
unsigned long V_58 ;
F_46 ( & V_6 -> V_60 , V_58 ) ;
V_6 -> V_29 = false ;
F_42 ( V_6 ) ;
F_48 ( & V_6 -> V_60 , V_58 ) ;
return 0 ;
}
