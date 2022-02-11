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
struct V_1 * V_3 ;
int V_23 ;
for ( V_23 = F_14 ( V_24 ) ; V_23 < V_25 ;
V_23 ++ ) {
T_1 V_16 ;
T_1 V_26 ;
V_16 = F_8 ( V_6 -> V_20 + F_15 ( V_23 ) ) ;
if ( V_23 == F_14 ( V_24 ) && V_16 ) {
T_1 V_27 ;
V_27 = 1 << F_16 ( V_24 ) ;
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
V_26 += 32 * V_23 ;
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
static T_4 F_23 ( struct V_38 * V_39 )
{
T_4 V_40 ;
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
T_4 V_40 , struct V_47 * V_48 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
enum V_46 V_49 ;
V_49 = F_36 ( V_4 , V_40 , V_48 ) ;
if ( V_48 && V_49 == V_50 )
V_48 -> V_34 = V_3 -> V_34 ;
return V_49 ;
}
static void F_37 ( struct V_1 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_1 V_9 ;
T_1 V_51 ;
T_1 V_52 ;
V_3 -> V_34 = 0 ;
V_52 = V_53 ;
if ( ! V_3 -> V_42 ) {
V_52 |= V_54 ;
V_52 |= V_55 ;
V_52 |= V_3 -> V_56 ;
}
F_6 ( V_52 , V_3 -> V_43 ) ;
F_38 () ;
F_39 ( V_6 -> V_14 . V_15 ) ;
V_51 = F_40 ( V_3 -> V_51 ) ;
V_9 = ( V_51 - V_6 -> V_12 ) / sizeof( struct V_10 ) ;
F_18 ( V_6 -> V_13 [ V_9 ] ) ;
V_6 -> V_13 [ V_9 ] = V_3 ;
V_52 = ( sizeof( struct V_10 ) - 24 ) / 4 ;
V_52 |= V_51 ;
F_6 ( V_52 , V_6 -> V_20 + F_12 ( V_3 -> V_26 ) ) ;
}
static void F_41 ( struct V_5 * V_6 )
{
struct V_1 * V_3 , * V_57 ;
F_42 (c, _c, &cdd->pending, node) {
F_37 ( V_3 ) ;
F_43 ( & V_3 -> V_58 ) ;
}
}
static void F_44 ( struct V_2 * V_4 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_3 -> V_6 ;
unsigned long V_59 ;
int error ;
error = F_39 ( V_6 -> V_14 . V_15 ) ;
if ( ( error != - V_60 ) && error < 0 ) {
F_28 ( V_6 -> V_14 . V_15 ) ;
F_27 ( V_6 -> V_14 . V_15 , L_3 ,
error ) ;
return;
}
F_45 ( & V_6 -> V_61 , V_59 ) ;
F_46 ( & V_3 -> V_58 , & V_6 -> V_45 ) ;
if ( ! V_6 -> V_29 )
F_41 ( V_6 ) ;
F_47 ( & V_6 -> V_61 , V_59 ) ;
F_31 ( V_6 -> V_14 . V_15 ) ;
F_32 ( V_6 -> V_14 . V_15 ) ;
}
static T_1 F_48 ( T_1 V_62 )
{
T_1 V_52 ;
V_52 = V_63 << V_64 ;
V_52 |= V_62 ;
return V_52 ;
}
static T_1 F_49 ( struct V_1 * V_3 )
{
T_1 V_52 ;
V_52 = 0 ;
return V_52 ;
}
static T_1 F_50 ( struct V_1 * V_3 )
{
T_1 V_52 ;
V_52 = V_65 ;
V_52 |= V_3 -> V_56 ;
return V_52 ;
}
static T_1 F_51 ( T_1 V_62 )
{
T_1 V_52 ;
V_52 = V_62 ;
return V_52 ;
}
static T_1 F_52 ( T_1 V_62 )
{
T_1 V_52 ;
V_52 = V_66 ;
V_52 |= V_62 ;
return V_52 ;
}
static T_1 F_53 ( T_1 V_67 )
{
T_1 V_52 ;
V_52 = V_67 ;
return V_52 ;
}
static T_1 F_54 ( void )
{
T_1 V_52 ;
V_52 = 0 ;
return V_52 ;
}
static struct V_38 * F_55 (
struct V_2 * V_4 , struct V_68 * V_69 , unsigned V_70 ,
enum V_71 V_72 , unsigned long V_73 , void * V_74 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_10 * V_75 ;
struct V_68 * V_76 ;
unsigned int V_23 ;
V_75 = V_3 -> V_7 ;
F_56 (sgl, sg, sg_len, i) {
T_1 V_67 ;
T_1 V_28 ;
V_67 = F_40 ( F_57 ( V_76 ) ) ;
V_28 = F_58 ( V_76 ) ;
V_75 -> V_33 = F_48 ( V_28 ) ;
V_75 -> V_77 = F_49 ( V_3 ) ;
V_75 -> V_31 = F_50 ( V_3 ) ;
V_75 -> V_78 = F_51 ( V_28 ) ;
V_75 -> V_79 = F_53 ( V_67 ) ;
V_75 -> V_80 = F_54 () ;
V_75 -> V_35 = F_52 ( V_28 ) ;
V_75 -> V_81 = F_53 ( V_67 ) ;
V_75 ++ ;
}
return & V_3 -> V_36 ;
}
static void F_59 ( struct V_10 * V_75 )
{
V_75 -> V_33 = V_82 << V_64 ;
}
static int F_60 ( struct V_1 * V_3 )
{
struct V_83 V_84 ;
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_10 * V_85 ;
T_1 V_52 ;
T_1 V_51 ;
T_1 V_86 ;
V_85 = V_6 -> V_87 ;
V_85 += V_6 -> V_88 ;
V_86 = V_6 -> V_12 ;
V_86 += V_6 -> V_88 * sizeof( struct V_10 ) ;
if ( ! V_3 -> V_89 ) {
F_59 ( V_85 ) ;
F_38 () ;
V_52 = ( sizeof( struct V_10 ) - 24 ) / 4 ;
V_52 |= V_86 ;
F_6 ( V_52 , V_6 -> V_20 +
F_12 ( V_6 -> V_90 . V_91 ) ) ;
V_52 = V_53 ;
if ( ! V_3 -> V_42 ) {
V_52 |= V_54 ;
V_52 |= V_55 ;
V_52 |= V_3 -> V_56 ;
}
V_52 |= V_92 ;
F_6 ( V_52 , V_3 -> V_43 ) ;
V_3 -> V_89 = 1 ;
V_3 -> V_93 = 500 ;
}
if ( ! V_3 -> V_94 || ! V_3 -> V_95 ) {
V_51 = F_11 ( V_6 , V_6 -> V_90 . V_96 ) ;
if ( ! V_51 )
V_51 = F_11 ( V_6 , V_3 -> V_56 ) ;
if ( V_51 == V_3 -> V_51 ) {
V_3 -> V_95 = 1 ;
} else if ( V_51 == V_86 ) {
T_1 V_33 ;
F_17 () ;
V_33 = V_85 -> V_33 ;
F_18 ( ( V_33 >> V_64 ) != V_82 ) ;
F_18 ( ! V_3 -> V_42 && ! ( V_33 & V_97 ) ) ;
F_18 ( ( V_33 & 0x1f ) != V_3 -> V_98 ) ;
V_3 -> V_94 = 1 ;
} else if ( V_51 ) {
F_61 ( 1 ) ;
}
}
V_3 -> V_93 -- ;
if ( ! V_3 -> V_94 && V_3 -> V_93 ) {
F_62 ( 1 ) ;
return - V_99 ;
}
F_18 ( ! V_3 -> V_93 ) ;
if ( ! V_3 -> V_95 ) {
V_51 = F_11 ( V_6 , V_3 -> V_26 ) ;
if ( ! V_51 )
V_51 = F_11 ( V_6 , V_3 -> V_56 ) ;
F_18 ( ! V_51 ) ;
}
V_3 -> V_89 = 0 ;
V_3 -> V_94 = 0 ;
V_3 -> V_95 = 0 ;
F_6 ( 0 , V_3 -> V_43 ) ;
V_84 . V_100 = V_101 ;
F_21 ( & V_3 -> V_36 ) ;
F_22 ( & V_3 -> V_36 , & V_84 ) ;
return 0 ;
}
static int F_63 ( struct V_2 * V_4 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_3 -> V_6 ;
T_1 V_9 ;
T_1 V_51 ;
int V_49 ;
V_51 = F_40 ( V_3 -> V_51 ) ;
V_9 = ( V_51 - V_6 -> V_12 ) / sizeof( struct V_10 ) ;
if ( ! V_6 -> V_13 [ V_9 ] )
return 0 ;
V_49 = F_60 ( V_3 ) ;
if ( V_49 )
return V_49 ;
F_18 ( ! V_6 -> V_13 [ V_9 ] ) ;
V_6 -> V_13 [ V_9 ] = NULL ;
F_5 ( V_6 -> V_14 . V_15 ) ;
return 0 ;
}
static void F_64 ( struct V_5 * V_6 )
{
while ( ! F_34 ( & V_6 -> V_14 . V_102 ) ) {
struct V_1 * V_103 ;
V_103 = F_65 ( & V_6 -> V_14 . V_102 ,
struct V_1 , V_4 . V_104 ) ;
F_43 ( & V_103 -> V_4 . V_104 ) ;
F_66 ( V_103 ) ;
}
}
static int F_67 ( struct V_105 * V_15 , struct V_5 * V_6 )
{
struct V_1 * V_103 ;
int V_23 ;
int V_49 ;
T_1 V_106 ;
V_49 = F_68 ( V_15 -> V_107 , L_4 ,
& V_106 ) ;
if ( V_49 )
return V_49 ;
V_106 *= 2 ;
for ( V_23 = 0 ; V_23 < V_106 ; V_23 ++ ) {
V_103 = F_69 ( sizeof( * V_103 ) , V_108 ) ;
if ( ! V_103 )
goto V_109;
V_103 -> V_6 = V_6 ;
if ( V_23 & 1 ) {
V_103 -> V_43 = V_6 -> V_110 + F_70 ( V_23 >> 1 ) ;
V_103 -> V_42 = 1 ;
} else {
V_103 -> V_43 = V_6 -> V_110 + F_71 ( V_23 >> 1 ) ;
V_103 -> V_42 = 0 ;
}
V_103 -> V_98 = V_23 >> 1 ;
V_103 -> V_7 = & V_6 -> V_87 [ V_23 ] ;
V_103 -> V_51 = V_6 -> V_12 ;
V_103 -> V_51 += V_23 * sizeof( struct V_10 ) ;
V_103 -> V_4 . V_105 = & V_6 -> V_14 ;
F_46 ( & V_103 -> V_4 . V_104 , & V_6 -> V_14 . V_102 ) ;
}
V_6 -> V_88 = V_106 ;
return 0 ;
V_109:
F_64 ( V_6 ) ;
return - V_111 ;
}
static void F_72 ( struct V_105 * V_15 , struct V_5 * V_6 )
{
unsigned int V_112 ;
int V_23 ;
V_112 = V_11 * sizeof( struct V_10 ) ;
for ( V_23 = 0 ; V_23 < V_113 ; V_23 ++ ) {
F_6 ( 0 , V_6 -> V_20 + F_73 ( V_23 ) ) ;
F_6 ( 0 , V_6 -> V_20 + F_74 ( V_23 ) ) ;
F_75 ( V_15 , V_112 , V_6 -> V_87 ,
V_6 -> V_12 ) ;
}
}
static void F_76 ( struct V_5 * V_6 )
{
F_6 ( 0 , V_6 -> V_114 + V_115 ) ;
}
static void F_77 ( struct V_105 * V_15 , struct V_5 * V_6 )
{
F_76 ( V_6 ) ;
F_72 ( V_15 , V_6 ) ;
F_6 ( 0 , V_6 -> V_20 + V_116 ) ;
F_6 ( 0 , V_6 -> V_20 + V_116 ) ;
F_75 ( V_15 , V_117 , V_6 -> V_118 ,
V_6 -> V_119 ) ;
}
static int F_78 ( struct V_105 * V_15 , struct V_5 * V_6 )
{
unsigned int V_120 ;
unsigned int V_112 ;
int V_23 ;
T_1 V_52 ;
T_1 V_121 ;
F_79 ( sizeof( struct V_10 ) &
( sizeof( struct V_10 ) - 1 ) ) ;
F_79 ( sizeof( struct V_10 ) < 32 ) ;
F_79 ( V_11 < 32 ) ;
V_120 = sizeof( struct V_10 ) ;
V_112 = V_11 * V_120 ;
V_121 = 0 ;
for ( V_23 = 0 ; V_23 < V_113 ; V_23 ++ ) {
V_52 = V_121 << V_122 ;
V_52 |= ( F_80 ( V_120 ) - 5 ) << V_123 ;
V_52 |= F_80 ( V_11 ) - 5 ;
F_79 ( V_113 != 1 ) ;
V_6 -> V_87 = F_81 ( V_15 , V_112 ,
& V_6 -> V_12 , V_108 ) ;
if ( ! V_6 -> V_87 )
return - V_111 ;
F_6 ( V_6 -> V_12 , V_6 -> V_20 + F_73 ( V_23 ) ) ;
F_6 ( V_52 , V_6 -> V_20 + F_74 ( V_23 ) ) ;
V_121 += V_11 ;
}
return 0 ;
}
static void F_82 ( struct V_5 * V_6 )
{
unsigned V_124 ;
unsigned V_125 ;
T_1 V_52 ;
V_125 = 0 ;
F_6 ( 0 , V_6 -> V_114 + V_115 ) ;
for ( V_124 = 0 ; V_124 < 15 * 2 ; V_124 += 2 ) {
V_52 = F_83 ( V_124 ) ;
V_52 |= F_84 ( V_124 ) | V_126 ;
V_52 |= F_85 ( V_124 + 1 ) ;
V_52 |= F_86 ( V_124 + 1 ) | V_127 ;
F_6 ( V_52 , V_6 -> V_114 + F_87 ( V_125 ) ) ;
V_125 ++ ;
}
V_52 = 15 * 2 * 2 - 1 ;
V_52 |= V_128 ;
F_6 ( V_52 , V_6 -> V_114 + V_115 ) ;
}
static int F_88 ( struct V_105 * V_15 , struct V_5 * V_6 )
{
int V_49 ;
F_79 ( V_117 > ( ( 1 << 14 ) - 1 ) ) ;
V_6 -> V_118 = F_81 ( V_15 , V_117 ,
& V_6 -> V_119 , V_108 ) ;
if ( ! V_6 -> V_118 )
return - V_111 ;
F_6 ( V_6 -> V_119 , V_6 -> V_20 + V_116 ) ;
F_6 ( V_117 , V_6 -> V_20 + V_129 ) ;
F_6 ( 0 , V_6 -> V_20 + V_130 ) ;
V_49 = F_78 ( V_15 , V_6 ) ;
if ( V_49 )
goto V_131;
F_6 ( V_6 -> V_90 . V_91 , V_6 -> V_110 + V_132 ) ;
F_82 ( V_6 ) ;
return 0 ;
V_131:
F_77 ( V_15 , V_6 ) ;
return V_49 ;
}
static bool F_89 ( struct V_2 * V_4 , void * V_133 )
{
struct V_1 * V_103 ;
struct V_5 * V_6 ;
const struct V_134 * V_135 ;
T_1 * V_136 = V_133 ;
if ( V_4 -> V_105 -> V_15 -> V_137 != & V_138 . V_137 )
return false ;
V_103 = F_1 ( V_4 ) ;
if ( V_103 -> V_98 != V_136 [ V_139 ] )
return false ;
if ( V_103 -> V_42 && ! V_136 [ V_140 ] )
return false ;
V_6 = V_103 -> V_6 ;
if ( V_103 -> V_42 )
V_135 = V_6 -> V_141 ;
else
V_135 = V_6 -> V_142 ;
F_79 ( F_90 ( V_143 ) != F_90 ( V_144 ) ) ;
if ( F_18 ( V_103 -> V_98 > F_90 ( V_143 ) ) )
return false ;
V_103 -> V_26 = V_135 [ V_103 -> V_98 ] . V_91 ;
V_103 -> V_56 = V_135 [ V_103 -> V_98 ] . V_96 ;
return true ;
}
static struct V_2 * F_91 ( struct V_145 * V_146 ,
struct V_147 * V_148 )
{
int V_149 = V_146 -> V_150 ;
struct V_151 * V_152 = V_148 -> V_153 ;
if ( ! V_152 || ! V_152 -> V_154 )
return NULL ;
if ( V_149 != 2 )
return NULL ;
return F_92 ( V_152 -> V_155 , V_152 -> V_154 ,
& V_146 -> args [ 0 ] ) ;
}
static const struct V_156 * F_93 ( struct V_105 * V_15 )
{
const struct V_157 * V_158 ;
V_158 = F_94 ( V_159 , V_15 -> V_107 ) ;
if ( ! V_158 )
return NULL ;
return V_158 -> V_22 ;
}
static int F_95 ( struct V_160 * V_161 )
{
struct V_5 * V_6 ;
struct V_105 * V_15 = & V_161 -> V_15 ;
const struct V_156 * V_162 ;
int V_21 ;
int V_49 ;
V_162 = F_93 ( V_15 ) ;
if ( ! V_162 )
return - V_163 ;
V_6 = F_96 ( & V_161 -> V_15 , sizeof( * V_6 ) , V_108 ) ;
if ( ! V_6 )
return - V_111 ;
F_97 ( V_164 , V_6 -> V_14 . V_165 ) ;
V_6 -> V_14 . V_166 = F_25 ;
V_6 -> V_14 . V_167 = F_33 ;
V_6 -> V_14 . V_168 = F_35 ;
V_6 -> V_14 . V_169 = F_44 ;
V_6 -> V_14 . V_170 = F_55 ;
V_6 -> V_14 . V_171 = F_63 ;
V_6 -> V_14 . V_172 = F_98 ( V_173 ) | F_98 ( V_174 ) ;
V_6 -> V_14 . V_175 = V_176 ;
V_6 -> V_14 . V_177 = V_176 ;
V_6 -> V_14 . V_178 = V_179 ;
V_6 -> V_14 . V_15 = V_15 ;
F_99 ( & V_6 -> V_14 . V_102 ) ;
V_180 . V_155 = V_6 -> V_14 . V_165 ;
V_6 -> V_181 = F_100 ( V_15 -> V_107 , 0 ) ;
V_6 -> V_110 = F_100 ( V_15 -> V_107 , 1 ) ;
V_6 -> V_114 = F_100 ( V_15 -> V_107 , 2 ) ;
V_6 -> V_20 = F_100 ( V_15 -> V_107 , 3 ) ;
F_101 ( & V_6 -> V_61 ) ;
F_99 ( & V_6 -> V_45 ) ;
F_102 ( V_161 , V_6 ) ;
if ( ! V_6 -> V_181 || ! V_6 -> V_110 || ! V_6 -> V_114 ||
! V_6 -> V_20 )
return - V_182 ;
F_103 ( V_15 ) ;
F_104 ( V_15 , 100 ) ;
F_105 ( V_15 ) ;
V_49 = F_26 ( V_15 ) ;
if ( V_49 < 0 )
goto V_183;
V_6 -> V_142 = V_162 -> V_142 ;
V_6 -> V_141 = V_162 -> V_141 ;
V_6 -> V_90 = V_162 -> V_90 ;
V_49 = F_88 ( V_15 , V_6 ) ;
if ( V_49 )
goto V_184;
V_49 = F_67 ( V_15 , V_6 ) ;
if ( V_49 )
goto V_185;
V_21 = F_106 ( V_15 -> V_107 , 0 ) ;
if ( ! V_21 ) {
V_49 = - V_163 ;
goto V_186;
}
V_49 = F_107 ( & V_161 -> V_15 , V_21 , V_162 -> V_187 , V_188 ,
F_108 ( V_15 ) , V_6 ) ;
if ( V_49 )
goto V_186;
V_6 -> V_21 = V_21 ;
V_49 = F_109 ( & V_6 -> V_14 ) ;
if ( V_49 )
goto V_189;
V_49 = F_110 ( V_15 -> V_107 ,
F_91 , & V_180 ) ;
if ( V_49 )
goto V_190;
F_31 ( V_15 ) ;
F_32 ( V_15 ) ;
return 0 ;
V_190:
F_111 ( & V_6 -> V_14 ) ;
V_189:
V_186:
F_64 ( V_6 ) ;
V_185:
F_77 ( V_15 , V_6 ) ;
V_184:
F_112 ( V_15 ) ;
V_183:
F_113 ( V_15 ) ;
F_114 ( V_15 ) ;
F_115 ( V_6 -> V_181 ) ;
F_115 ( V_6 -> V_110 ) ;
F_115 ( V_6 -> V_114 ) ;
F_115 ( V_6 -> V_20 ) ;
return V_49 ;
}
static int F_116 ( struct V_160 * V_161 )
{
struct V_5 * V_6 = F_117 ( V_161 ) ;
int error ;
error = F_26 ( & V_161 -> V_15 ) ;
if ( error < 0 )
F_27 ( & V_161 -> V_15 , L_5 ,
V_30 , error ) ;
F_118 ( V_161 -> V_15 . V_107 ) ;
F_111 ( & V_6 -> V_14 ) ;
F_119 ( & V_161 -> V_15 , V_6 -> V_21 , V_6 ) ;
F_64 ( V_6 ) ;
F_77 ( & V_161 -> V_15 , V_6 ) ;
F_115 ( V_6 -> V_181 ) ;
F_115 ( V_6 -> V_110 ) ;
F_115 ( V_6 -> V_114 ) ;
F_115 ( V_6 -> V_20 ) ;
F_112 ( & V_161 -> V_15 ) ;
F_113 ( & V_161 -> V_15 ) ;
F_114 ( & V_161 -> V_15 ) ;
return 0 ;
}
static int T_5 F_120 ( struct V_105 * V_15 )
{
struct V_5 * V_6 = F_121 ( V_15 ) ;
V_6 -> V_191 = F_8 ( V_6 -> V_110 + V_132 ) ;
F_76 ( V_6 ) ;
return 0 ;
}
static int T_5 F_122 ( struct V_105 * V_15 )
{
struct V_5 * V_6 = F_121 ( V_15 ) ;
struct V_1 * V_3 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_113 ; V_23 ++ )
F_6 ( V_6 -> V_12 , V_6 -> V_20 + F_73 ( V_23 ) ) ;
F_123 (c, &cdd->ddev.channels, chan.device_node)
if ( ! V_3 -> V_42 )
F_6 ( V_3 -> V_26 , V_3 -> V_43 + V_44 ) ;
F_82 ( V_6 ) ;
F_6 ( V_6 -> V_191 , V_6 -> V_110 + V_132 ) ;
F_6 ( V_6 -> V_119 , V_6 -> V_20 + V_116 ) ;
F_6 ( V_117 , V_6 -> V_20 + V_129 ) ;
F_6 ( 0 , V_6 -> V_20 + V_130 ) ;
return 0 ;
}
static int T_5 F_124 ( struct V_105 * V_15 )
{
struct V_5 * V_6 = F_121 ( V_15 ) ;
unsigned long V_59 ;
F_45 ( & V_6 -> V_61 , V_59 ) ;
V_6 -> V_29 = true ;
F_18 ( ! F_34 ( & V_6 -> V_45 ) ) ;
F_47 ( & V_6 -> V_61 , V_59 ) ;
return 0 ;
}
static int T_5 F_125 ( struct V_105 * V_15 )
{
struct V_5 * V_6 = F_121 ( V_15 ) ;
unsigned long V_59 ;
F_45 ( & V_6 -> V_61 , V_59 ) ;
V_6 -> V_29 = false ;
F_41 ( V_6 ) ;
F_47 ( & V_6 -> V_61 , V_59 ) ;
return 0 ;
}
