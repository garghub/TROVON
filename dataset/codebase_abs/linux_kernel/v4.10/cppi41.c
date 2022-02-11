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
T_1 V_23 ;
int V_24 ;
V_23 = F_8 ( V_6 -> V_25 + V_26 ) ;
if ( ! ( V_23 & V_27 ) )
return V_28 ;
F_6 ( V_23 , V_6 -> V_25 + V_26 ) ;
for ( V_24 = F_14 ( V_29 ) ; V_24 < V_30 ;
V_24 ++ ) {
T_1 V_16 ;
T_1 V_31 ;
V_16 = F_8 ( V_6 -> V_20 + F_15 ( V_24 ) ) ;
if ( V_24 == F_14 ( V_29 ) && V_16 ) {
T_1 V_32 ;
V_32 = 1 << F_16 ( V_29 ) ;
V_32 -- ;
V_16 &= ~ V_32 ;
}
if ( V_16 )
F_17 () ;
while ( V_16 ) {
T_1 V_7 , V_33 ;
F_18 ( V_6 -> V_34 ) ;
V_31 = F_19 ( V_16 ) ;
V_16 &= ~ ( 1 << V_31 ) ;
V_31 += 32 * V_24 ;
V_7 = F_11 ( V_6 , V_31 ) ;
V_3 = F_3 ( V_6 , V_7 ) ;
if ( F_18 ( ! V_3 ) ) {
F_20 ( L_1 , V_35 ,
V_31 , V_7 ) ;
continue;
}
if ( V_3 -> V_7 -> V_36 & V_37 )
V_33 = 0 ;
else
V_33 = F_10 ( V_3 -> V_7 -> V_38 ) ;
V_3 -> V_39 = F_10 ( V_3 -> V_7 -> V_40 ) - V_33 ;
F_21 ( & V_3 -> V_41 ) ;
F_22 ( & V_3 -> V_41 , NULL ) ;
}
}
return V_42 ;
}
static T_4 F_23 ( struct V_43 * V_44 )
{
T_4 V_45 ;
V_45 = F_24 ( V_44 ) ;
return V_45 ;
}
static int F_25 ( struct V_2 * V_4 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_3 -> V_6 ;
int error ;
error = F_26 ( V_6 -> V_14 . V_15 ) ;
if ( error < 0 ) {
F_27 ( V_6 -> V_14 . V_15 , L_2 ,
V_35 , error ) ;
F_28 ( V_6 -> V_14 . V_15 ) ;
return error ;
}
F_29 ( V_4 ) ;
F_30 ( & V_3 -> V_41 , V_4 ) ;
V_3 -> V_41 . V_46 = F_23 ;
if ( ! V_3 -> V_47 )
F_6 ( V_3 -> V_31 , V_3 -> V_48 + V_49 ) ;
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
F_18 ( ! F_34 ( & V_6 -> V_50 ) ) ;
F_31 ( V_6 -> V_14 . V_15 ) ;
F_32 ( V_6 -> V_14 . V_15 ) ;
}
static enum V_51 F_35 ( struct V_2 * V_4 ,
T_4 V_45 , struct V_52 * V_53 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
enum V_51 V_54 ;
V_54 = F_36 ( V_4 , V_45 , V_53 ) ;
if ( V_53 && V_54 == V_55 )
V_53 -> V_39 = V_3 -> V_39 ;
return V_54 ;
}
static void F_37 ( struct V_1 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_1 V_9 ;
T_1 V_56 ;
T_1 V_57 ;
V_3 -> V_39 = 0 ;
V_57 = V_58 ;
if ( ! V_3 -> V_47 ) {
V_57 |= V_59 ;
V_57 |= V_60 ;
V_57 |= V_3 -> V_61 ;
}
F_6 ( V_57 , V_3 -> V_48 ) ;
F_38 () ;
F_39 ( V_6 -> V_14 . V_15 ) ;
V_56 = F_40 ( V_3 -> V_56 ) ;
V_9 = ( V_56 - V_6 -> V_12 ) / sizeof( struct V_10 ) ;
F_18 ( V_6 -> V_13 [ V_9 ] ) ;
V_6 -> V_13 [ V_9 ] = V_3 ;
V_57 = ( sizeof( struct V_10 ) - 24 ) / 4 ;
V_57 |= V_56 ;
F_6 ( V_57 , V_6 -> V_20 + F_12 ( V_3 -> V_31 ) ) ;
}
static void F_41 ( struct V_5 * V_6 )
{
struct V_1 * V_3 , * V_62 ;
F_42 (c, _c, &cdd->pending, node) {
F_37 ( V_3 ) ;
F_43 ( & V_3 -> V_63 ) ;
}
}
static void F_44 ( struct V_2 * V_4 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_3 -> V_6 ;
unsigned long V_64 ;
int error ;
error = F_39 ( V_6 -> V_14 . V_15 ) ;
if ( ( error != - V_65 ) && error < 0 ) {
F_28 ( V_6 -> V_14 . V_15 ) ;
F_27 ( V_6 -> V_14 . V_15 , L_3 ,
error ) ;
return;
}
F_45 ( & V_6 -> V_66 , V_64 ) ;
F_46 ( & V_3 -> V_63 , & V_6 -> V_50 ) ;
if ( ! V_6 -> V_34 )
F_41 ( V_6 ) ;
F_47 ( & V_6 -> V_66 , V_64 ) ;
F_31 ( V_6 -> V_14 . V_15 ) ;
F_32 ( V_6 -> V_14 . V_15 ) ;
}
static T_1 F_48 ( T_1 V_67 )
{
T_1 V_57 ;
V_57 = V_68 << V_69 ;
V_57 |= V_67 ;
return V_57 ;
}
static T_1 F_49 ( struct V_1 * V_3 )
{
T_1 V_57 ;
V_57 = 0 ;
return V_57 ;
}
static T_1 F_50 ( struct V_1 * V_3 )
{
T_1 V_57 ;
V_57 = V_70 ;
V_57 |= V_3 -> V_61 ;
return V_57 ;
}
static T_1 F_51 ( T_1 V_67 )
{
T_1 V_57 ;
V_57 = V_67 ;
return V_57 ;
}
static T_1 F_52 ( T_1 V_67 )
{
T_1 V_57 ;
V_57 = V_71 ;
V_57 |= V_67 ;
return V_57 ;
}
static T_1 F_53 ( T_1 V_72 )
{
T_1 V_57 ;
V_57 = V_72 ;
return V_57 ;
}
static T_1 F_54 ( void )
{
T_1 V_57 ;
V_57 = 0 ;
return V_57 ;
}
static struct V_43 * F_55 (
struct V_2 * V_4 , struct V_73 * V_74 , unsigned V_75 ,
enum V_76 V_77 , unsigned long V_78 , void * V_79 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_10 * V_80 ;
struct V_73 * V_81 ;
unsigned int V_24 ;
V_80 = V_3 -> V_7 ;
F_56 (sgl, sg, sg_len, i) {
T_1 V_72 ;
T_1 V_33 ;
V_72 = F_40 ( F_57 ( V_81 ) ) ;
V_33 = F_58 ( V_81 ) ;
V_80 -> V_38 = F_48 ( V_33 ) ;
V_80 -> V_82 = F_49 ( V_3 ) ;
V_80 -> V_36 = F_50 ( V_3 ) ;
V_80 -> V_83 = F_51 ( V_33 ) ;
V_80 -> V_84 = F_53 ( V_72 ) ;
V_80 -> V_85 = F_54 () ;
V_80 -> V_40 = F_52 ( V_33 ) ;
V_80 -> V_86 = F_53 ( V_72 ) ;
V_80 ++ ;
}
return & V_3 -> V_41 ;
}
static void F_59 ( struct V_10 * V_80 )
{
V_80 -> V_38 = V_87 << V_69 ;
}
static int F_60 ( struct V_1 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_10 * V_88 ;
T_1 V_57 ;
T_1 V_56 ;
T_1 V_89 ;
V_88 = V_6 -> V_90 ;
V_88 += V_6 -> V_91 ;
V_89 = V_6 -> V_12 ;
V_89 += V_6 -> V_91 * sizeof( struct V_10 ) ;
if ( ! V_3 -> V_92 ) {
F_59 ( V_88 ) ;
F_38 () ;
V_57 = ( sizeof( struct V_10 ) - 24 ) / 4 ;
V_57 |= V_89 ;
F_6 ( V_57 , V_6 -> V_20 +
F_12 ( V_6 -> V_93 . V_94 ) ) ;
V_57 = V_58 ;
if ( ! V_3 -> V_47 ) {
V_57 |= V_59 ;
V_57 |= V_60 ;
V_57 |= V_3 -> V_61 ;
}
V_57 |= V_95 ;
F_6 ( V_57 , V_3 -> V_48 ) ;
V_3 -> V_92 = 1 ;
V_3 -> V_96 = 500 ;
}
if ( ! V_3 -> V_97 || ! V_3 -> V_98 ) {
V_56 = F_11 ( V_6 , V_6 -> V_93 . V_99 ) ;
if ( ! V_56 )
V_56 = F_11 ( V_6 , V_3 -> V_61 ) ;
if ( V_56 == V_3 -> V_56 ) {
V_3 -> V_98 = 1 ;
} else if ( V_56 == V_89 ) {
T_1 V_38 ;
F_17 () ;
V_38 = V_88 -> V_38 ;
F_18 ( ( V_38 >> V_69 ) != V_87 ) ;
F_18 ( ! V_3 -> V_47 && ! ( V_38 & V_100 ) ) ;
F_18 ( ( V_38 & 0x1f ) != V_3 -> V_101 ) ;
V_3 -> V_97 = 1 ;
} else if ( V_56 ) {
F_61 ( 1 ) ;
}
}
V_3 -> V_96 -- ;
if ( ! V_3 -> V_97 && V_3 -> V_96 ) {
F_62 ( 1 ) ;
return - V_102 ;
}
F_18 ( ! V_3 -> V_96 ) ;
if ( ! V_3 -> V_98 ) {
V_56 = F_11 ( V_6 , V_3 -> V_31 ) ;
if ( ! V_56 )
V_56 = F_11 ( V_6 , V_3 -> V_61 ) ;
F_18 ( ! V_56 ) ;
}
V_3 -> V_92 = 0 ;
V_3 -> V_97 = 0 ;
V_3 -> V_98 = 0 ;
F_6 ( 0 , V_3 -> V_48 ) ;
return 0 ;
}
static int F_63 ( struct V_2 * V_4 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_3 -> V_6 ;
T_1 V_9 ;
T_1 V_56 ;
int V_54 ;
V_56 = F_40 ( V_3 -> V_56 ) ;
V_9 = ( V_56 - V_6 -> V_12 ) / sizeof( struct V_10 ) ;
if ( ! V_6 -> V_13 [ V_9 ] )
return 0 ;
V_54 = F_60 ( V_3 ) ;
if ( V_54 )
return V_54 ;
F_18 ( ! V_6 -> V_13 [ V_9 ] ) ;
V_6 -> V_13 [ V_9 ] = NULL ;
F_5 ( V_6 -> V_14 . V_15 ) ;
return 0 ;
}
static void F_64 ( struct V_5 * V_6 )
{
while ( ! F_34 ( & V_6 -> V_14 . V_103 ) ) {
struct V_1 * V_104 ;
V_104 = F_65 ( & V_6 -> V_14 . V_103 ,
struct V_1 , V_4 . V_105 ) ;
F_43 ( & V_104 -> V_4 . V_105 ) ;
F_66 ( V_104 ) ;
}
}
static int F_67 ( struct V_106 * V_15 , struct V_5 * V_6 )
{
struct V_1 * V_104 ;
int V_24 ;
int V_54 ;
T_1 V_107 ;
V_54 = F_68 ( V_15 -> V_108 , L_4 ,
& V_107 ) ;
if ( V_54 )
return V_54 ;
V_107 *= 2 ;
for ( V_24 = 0 ; V_24 < V_107 ; V_24 ++ ) {
V_104 = F_69 ( sizeof( * V_104 ) , V_109 ) ;
if ( ! V_104 )
goto V_110;
V_104 -> V_6 = V_6 ;
if ( V_24 & 1 ) {
V_104 -> V_48 = V_6 -> V_111 + F_70 ( V_24 >> 1 ) ;
V_104 -> V_47 = 1 ;
} else {
V_104 -> V_48 = V_6 -> V_111 + F_71 ( V_24 >> 1 ) ;
V_104 -> V_47 = 0 ;
}
V_104 -> V_101 = V_24 >> 1 ;
V_104 -> V_7 = & V_6 -> V_90 [ V_24 ] ;
V_104 -> V_56 = V_6 -> V_12 ;
V_104 -> V_56 += V_24 * sizeof( struct V_10 ) ;
V_104 -> V_4 . V_106 = & V_6 -> V_14 ;
F_46 ( & V_104 -> V_4 . V_105 , & V_6 -> V_14 . V_103 ) ;
}
V_6 -> V_91 = V_107 ;
return 0 ;
V_110:
F_64 ( V_6 ) ;
return - V_112 ;
}
static void F_72 ( struct V_106 * V_15 , struct V_5 * V_6 )
{
unsigned int V_113 ;
int V_24 ;
V_113 = V_11 * sizeof( struct V_10 ) ;
for ( V_24 = 0 ; V_24 < V_114 ; V_24 ++ ) {
F_6 ( 0 , V_6 -> V_20 + F_73 ( V_24 ) ) ;
F_6 ( 0 , V_6 -> V_20 + F_74 ( V_24 ) ) ;
F_75 ( V_15 , V_113 , V_6 -> V_90 ,
V_6 -> V_12 ) ;
}
}
static void F_76 ( struct V_5 * V_6 )
{
F_6 ( 0 , V_6 -> V_115 + V_116 ) ;
}
static void F_77 ( struct V_106 * V_15 , struct V_5 * V_6 )
{
F_76 ( V_6 ) ;
F_72 ( V_15 , V_6 ) ;
F_6 ( 0 , V_6 -> V_20 + V_117 ) ;
F_6 ( 0 , V_6 -> V_20 + V_117 ) ;
F_75 ( V_15 , V_118 , V_6 -> V_119 ,
V_6 -> V_120 ) ;
}
static int F_78 ( struct V_106 * V_15 , struct V_5 * V_6 )
{
unsigned int V_121 ;
unsigned int V_113 ;
int V_24 ;
T_1 V_57 ;
T_1 V_122 ;
F_79 ( sizeof( struct V_10 ) &
( sizeof( struct V_10 ) - 1 ) ) ;
F_79 ( sizeof( struct V_10 ) < 32 ) ;
F_79 ( V_11 < 32 ) ;
V_121 = sizeof( struct V_10 ) ;
V_113 = V_11 * V_121 ;
V_122 = 0 ;
for ( V_24 = 0 ; V_24 < V_114 ; V_24 ++ ) {
V_57 = V_122 << V_123 ;
V_57 |= ( F_80 ( V_121 ) - 5 ) << V_124 ;
V_57 |= F_80 ( V_11 ) - 5 ;
F_79 ( V_114 != 1 ) ;
V_6 -> V_90 = F_81 ( V_15 , V_113 ,
& V_6 -> V_12 , V_109 ) ;
if ( ! V_6 -> V_90 )
return - V_112 ;
F_6 ( V_6 -> V_12 , V_6 -> V_20 + F_73 ( V_24 ) ) ;
F_6 ( V_57 , V_6 -> V_20 + F_74 ( V_24 ) ) ;
V_122 += V_11 ;
}
return 0 ;
}
static void F_82 ( struct V_5 * V_6 )
{
unsigned V_125 ;
unsigned V_126 ;
T_1 V_57 ;
V_126 = 0 ;
F_6 ( 0 , V_6 -> V_115 + V_116 ) ;
for ( V_125 = 0 ; V_125 < 15 * 2 ; V_125 += 2 ) {
V_57 = F_83 ( V_125 ) ;
V_57 |= F_84 ( V_125 ) | V_127 ;
V_57 |= F_85 ( V_125 + 1 ) ;
V_57 |= F_86 ( V_125 + 1 ) | V_128 ;
F_6 ( V_57 , V_6 -> V_115 + F_87 ( V_126 ) ) ;
V_126 ++ ;
}
V_57 = 15 * 2 * 2 - 1 ;
V_57 |= V_129 ;
F_6 ( V_57 , V_6 -> V_115 + V_116 ) ;
}
static int F_88 ( struct V_106 * V_15 , struct V_5 * V_6 )
{
int V_54 ;
F_79 ( V_118 > ( ( 1 << 14 ) - 1 ) ) ;
V_6 -> V_119 = F_81 ( V_15 , V_118 ,
& V_6 -> V_120 , V_109 ) ;
if ( ! V_6 -> V_119 )
return - V_112 ;
F_6 ( V_6 -> V_120 , V_6 -> V_20 + V_117 ) ;
F_6 ( V_118 , V_6 -> V_20 + V_130 ) ;
F_6 ( 0 , V_6 -> V_20 + V_131 ) ;
V_54 = F_78 ( V_15 , V_6 ) ;
if ( V_54 )
goto V_132;
F_6 ( V_6 -> V_93 . V_94 , V_6 -> V_111 + V_133 ) ;
F_82 ( V_6 ) ;
return 0 ;
V_132:
F_77 ( V_15 , V_6 ) ;
return V_54 ;
}
static bool F_89 ( struct V_2 * V_4 , void * V_134 )
{
struct V_1 * V_104 ;
struct V_5 * V_6 ;
const struct V_135 * V_136 ;
T_1 * V_137 = V_134 ;
if ( V_4 -> V_106 -> V_15 -> V_138 != & V_139 . V_138 )
return false ;
V_104 = F_1 ( V_4 ) ;
if ( V_104 -> V_101 != V_137 [ V_140 ] )
return false ;
if ( V_104 -> V_47 && ! V_137 [ V_141 ] )
return false ;
V_6 = V_104 -> V_6 ;
if ( V_104 -> V_47 )
V_136 = V_6 -> V_142 ;
else
V_136 = V_6 -> V_143 ;
F_79 ( F_90 ( V_144 ) != F_90 ( V_145 ) ) ;
if ( F_18 ( V_104 -> V_101 > F_90 ( V_144 ) ) )
return false ;
V_104 -> V_31 = V_136 [ V_104 -> V_101 ] . V_94 ;
V_104 -> V_61 = V_136 [ V_104 -> V_101 ] . V_99 ;
return true ;
}
static struct V_2 * F_91 ( struct V_146 * V_147 ,
struct V_148 * V_149 )
{
int V_150 = V_147 -> V_151 ;
struct V_152 * V_153 = V_149 -> V_154 ;
if ( ! V_153 || ! V_153 -> V_155 )
return NULL ;
if ( V_150 != 2 )
return NULL ;
return F_92 ( V_153 -> V_156 , V_153 -> V_155 ,
& V_147 -> args [ 0 ] ) ;
}
static const struct V_157 * F_93 ( struct V_106 * V_15 )
{
const struct V_158 * V_159 ;
V_159 = F_94 ( V_160 , V_15 -> V_108 ) ;
if ( ! V_159 )
return NULL ;
return V_159 -> V_22 ;
}
static int F_95 ( struct V_161 * V_162 )
{
struct V_5 * V_6 ;
struct V_106 * V_15 = & V_162 -> V_15 ;
const struct V_157 * V_163 ;
int V_21 ;
int V_54 ;
V_163 = F_93 ( V_15 ) ;
if ( ! V_163 )
return - V_164 ;
V_6 = F_96 ( & V_162 -> V_15 , sizeof( * V_6 ) , V_109 ) ;
if ( ! V_6 )
return - V_112 ;
F_97 ( V_165 , V_6 -> V_14 . V_166 ) ;
V_6 -> V_14 . V_167 = F_25 ;
V_6 -> V_14 . V_168 = F_33 ;
V_6 -> V_14 . V_169 = F_35 ;
V_6 -> V_14 . V_170 = F_44 ;
V_6 -> V_14 . V_171 = F_55 ;
V_6 -> V_14 . V_172 = F_63 ;
V_6 -> V_14 . V_173 = F_98 ( V_174 ) | F_98 ( V_175 ) ;
V_6 -> V_14 . V_176 = V_177 ;
V_6 -> V_14 . V_178 = V_177 ;
V_6 -> V_14 . V_179 = V_180 ;
V_6 -> V_14 . V_15 = V_15 ;
F_99 ( & V_6 -> V_14 . V_103 ) ;
V_181 . V_156 = V_6 -> V_14 . V_166 ;
V_6 -> V_25 = F_100 ( V_15 -> V_108 , 0 ) ;
V_6 -> V_111 = F_100 ( V_15 -> V_108 , 1 ) ;
V_6 -> V_115 = F_100 ( V_15 -> V_108 , 2 ) ;
V_6 -> V_20 = F_100 ( V_15 -> V_108 , 3 ) ;
F_101 ( & V_6 -> V_66 ) ;
F_99 ( & V_6 -> V_50 ) ;
F_102 ( V_162 , V_6 ) ;
if ( ! V_6 -> V_25 || ! V_6 -> V_111 || ! V_6 -> V_115 ||
! V_6 -> V_20 )
return - V_182 ;
F_103 ( V_15 ) ;
F_104 ( V_15 , 100 ) ;
F_105 ( V_15 ) ;
V_54 = F_26 ( V_15 ) ;
if ( V_54 < 0 )
goto V_183;
V_6 -> V_143 = V_163 -> V_143 ;
V_6 -> V_142 = V_163 -> V_142 ;
V_6 -> V_93 = V_163 -> V_93 ;
V_54 = F_88 ( V_15 , V_6 ) ;
if ( V_54 )
goto V_184;
V_54 = F_67 ( V_15 , V_6 ) ;
if ( V_54 )
goto V_185;
V_21 = F_106 ( V_15 -> V_108 , 0 ) ;
if ( ! V_21 ) {
V_54 = - V_164 ;
goto V_186;
}
F_6 ( V_27 , V_6 -> V_25 + V_187 ) ;
V_54 = F_107 ( & V_162 -> V_15 , V_21 , V_163 -> V_188 , V_189 ,
F_108 ( V_15 ) , V_6 ) ;
if ( V_54 )
goto V_186;
V_6 -> V_21 = V_21 ;
V_54 = F_109 ( & V_6 -> V_14 ) ;
if ( V_54 )
goto V_190;
V_54 = F_110 ( V_15 -> V_108 ,
F_91 , & V_181 ) ;
if ( V_54 )
goto V_191;
F_31 ( V_15 ) ;
F_32 ( V_15 ) ;
return 0 ;
V_191:
F_111 ( & V_6 -> V_14 ) ;
V_190:
V_186:
F_6 ( 0 , V_6 -> V_25 + V_192 ) ;
F_64 ( V_6 ) ;
V_185:
F_77 ( V_15 , V_6 ) ;
V_184:
F_112 ( V_15 ) ;
V_183:
F_113 ( V_15 ) ;
F_114 ( V_15 ) ;
F_115 ( V_6 -> V_25 ) ;
F_115 ( V_6 -> V_111 ) ;
F_115 ( V_6 -> V_115 ) ;
F_115 ( V_6 -> V_20 ) ;
return V_54 ;
}
static int F_116 ( struct V_161 * V_162 )
{
struct V_5 * V_6 = F_117 ( V_162 ) ;
int error ;
error = F_26 ( & V_162 -> V_15 ) ;
if ( error < 0 )
F_27 ( & V_162 -> V_15 , L_5 ,
V_35 , error ) ;
F_118 ( V_162 -> V_15 . V_108 ) ;
F_111 ( & V_6 -> V_14 ) ;
F_6 ( 0 , V_6 -> V_25 + V_192 ) ;
F_119 ( & V_162 -> V_15 , V_6 -> V_21 , V_6 ) ;
F_64 ( V_6 ) ;
F_77 ( & V_162 -> V_15 , V_6 ) ;
F_115 ( V_6 -> V_25 ) ;
F_115 ( V_6 -> V_111 ) ;
F_115 ( V_6 -> V_115 ) ;
F_115 ( V_6 -> V_20 ) ;
F_112 ( & V_162 -> V_15 ) ;
F_113 ( & V_162 -> V_15 ) ;
F_114 ( & V_162 -> V_15 ) ;
return 0 ;
}
static int T_5 F_120 ( struct V_106 * V_15 )
{
struct V_5 * V_6 = F_121 ( V_15 ) ;
V_6 -> V_193 = F_8 ( V_6 -> V_111 + V_133 ) ;
F_6 ( 0 , V_6 -> V_25 + V_192 ) ;
F_76 ( V_6 ) ;
return 0 ;
}
static int T_5 F_122 ( struct V_106 * V_15 )
{
struct V_5 * V_6 = F_121 ( V_15 ) ;
struct V_1 * V_3 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_114 ; V_24 ++ )
F_6 ( V_6 -> V_12 , V_6 -> V_20 + F_73 ( V_24 ) ) ;
F_123 (c, &cdd->ddev.channels, chan.device_node)
if ( ! V_3 -> V_47 )
F_6 ( V_3 -> V_31 , V_3 -> V_48 + V_49 ) ;
F_82 ( V_6 ) ;
F_6 ( V_6 -> V_193 , V_6 -> V_111 + V_133 ) ;
F_6 ( V_6 -> V_120 , V_6 -> V_20 + V_117 ) ;
F_6 ( V_118 , V_6 -> V_20 + V_130 ) ;
F_6 ( 0 , V_6 -> V_20 + V_131 ) ;
F_6 ( V_27 , V_6 -> V_25 + V_187 ) ;
return 0 ;
}
static int T_5 F_124 ( struct V_106 * V_15 )
{
struct V_5 * V_6 = F_121 ( V_15 ) ;
unsigned long V_64 ;
F_45 ( & V_6 -> V_66 , V_64 ) ;
V_6 -> V_34 = true ;
F_18 ( ! F_34 ( & V_6 -> V_50 ) ) ;
F_47 ( & V_6 -> V_66 , V_64 ) ;
return 0 ;
}
static int T_5 F_125 ( struct V_106 * V_15 )
{
struct V_5 * V_6 = F_121 ( V_15 ) ;
unsigned long V_64 ;
F_45 ( & V_6 -> V_66 , V_64 ) ;
V_6 -> V_34 = false ;
F_41 ( V_6 ) ;
F_47 ( & V_6 -> V_66 , V_64 ) ;
return 0 ;
}
