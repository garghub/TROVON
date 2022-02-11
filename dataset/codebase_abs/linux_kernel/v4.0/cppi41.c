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
return V_3 ;
}
static void F_5 ( T_1 V_14 , void * T_2 * V_15 )
{
F_6 ( V_14 , V_15 ) ;
}
static T_1 F_7 ( void * T_2 * V_15 )
{
return F_8 ( V_15 ) ;
}
static T_1 F_9 ( T_1 V_14 )
{
return V_14 & ( ( 1 << ( V_16 + 1 ) ) - 1 ) ;
}
static T_1 F_10 ( struct V_5 * V_6 , unsigned V_17 )
{
T_1 V_7 ;
V_7 = F_7 ( V_6 -> V_18 + F_11 ( V_17 ) ) ;
V_7 &= ~ 0x1f ;
return V_7 ;
}
static T_3 F_12 ( int V_19 , void * V_20 )
{
struct V_5 * V_6 = V_20 ;
struct V_1 * V_3 ;
T_1 V_21 ;
int V_22 ;
V_21 = F_7 ( V_6 -> V_23 + V_24 ) ;
if ( ! ( V_21 & V_25 ) )
return V_26 ;
F_5 ( V_21 , V_6 -> V_23 + V_24 ) ;
for ( V_22 = F_13 ( V_27 ) ; V_22 < V_28 ;
V_22 ++ ) {
T_1 V_14 ;
T_1 V_29 ;
V_14 = F_7 ( V_6 -> V_18 + F_14 ( V_22 ) ) ;
if ( V_22 == F_13 ( V_27 ) && V_14 ) {
T_1 V_30 ;
V_30 = 1 << F_15 ( V_27 ) ;
V_30 -- ;
V_14 &= ~ V_30 ;
}
if ( V_14 )
F_16 () ;
while ( V_14 ) {
T_1 V_7 , V_31 ;
V_29 = F_17 ( V_14 ) ;
V_14 &= ~ ( 1 << V_29 ) ;
V_29 += 32 * V_22 ;
V_7 = F_10 ( V_6 , V_29 ) ;
V_3 = F_3 ( V_6 , V_7 ) ;
if ( F_18 ( ! V_3 ) ) {
F_19 ( L_1 , V_32 ,
V_29 , V_7 ) ;
continue;
}
if ( V_3 -> V_7 -> V_33 & V_34 )
V_31 = 0 ;
else
V_31 = F_9 ( V_3 -> V_7 -> V_35 ) ;
V_3 -> V_36 = F_9 ( V_3 -> V_7 -> V_37 ) - V_31 ;
F_20 ( & V_3 -> V_38 ) ;
V_3 -> V_38 . V_39 ( V_3 -> V_38 . V_40 ) ;
}
}
return V_41 ;
}
static T_4 F_21 ( struct V_42 * V_43 )
{
T_4 V_44 ;
V_44 = F_22 ( V_43 ) ;
return V_44 ;
}
static int F_23 ( struct V_2 * V_4 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
F_24 ( V_4 ) ;
F_25 ( & V_3 -> V_38 , V_4 ) ;
V_3 -> V_38 . V_45 = F_21 ;
if ( ! V_3 -> V_46 )
F_5 ( V_3 -> V_29 , V_3 -> V_47 + V_48 ) ;
return 0 ;
}
static void F_26 ( struct V_2 * V_4 )
{
}
static enum V_49 F_27 ( struct V_2 * V_4 ,
T_4 V_44 , struct V_50 * V_51 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
enum V_49 V_52 ;
V_52 = F_28 ( V_4 , V_44 , V_51 ) ;
if ( V_51 && V_52 == V_53 )
V_51 -> V_36 = V_3 -> V_36 ;
return V_52 ;
}
static void F_29 ( struct V_1 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_1 V_9 ;
T_1 V_54 ;
T_1 V_55 ;
V_54 = F_30 ( V_3 -> V_54 ) ;
V_9 = ( V_54 - V_6 -> V_12 ) / sizeof( struct V_10 ) ;
F_18 ( V_6 -> V_13 [ V_9 ] ) ;
V_6 -> V_13 [ V_9 ] = V_3 ;
V_55 = ( sizeof( struct V_10 ) - 24 ) / 4 ;
V_55 |= V_54 ;
F_5 ( V_55 , V_6 -> V_18 + F_11 ( V_3 -> V_29 ) ) ;
}
static void F_31 ( struct V_2 * V_4 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
T_1 V_55 ;
V_3 -> V_36 = 0 ;
V_55 = V_56 ;
if ( ! V_3 -> V_46 ) {
V_55 |= V_57 ;
V_55 |= V_58 ;
V_55 |= V_3 -> V_59 ;
}
F_5 ( V_55 , V_3 -> V_47 ) ;
F_32 () ;
F_29 ( V_3 ) ;
}
static T_1 F_33 ( T_1 V_60 )
{
T_1 V_55 ;
V_55 = V_61 << V_62 ;
V_55 |= V_60 ;
return V_55 ;
}
static T_1 F_34 ( struct V_1 * V_3 )
{
T_1 V_55 ;
V_55 = 0 ;
return V_55 ;
}
static T_1 F_35 ( struct V_1 * V_3 )
{
T_1 V_55 ;
V_55 = V_63 ;
V_55 |= V_3 -> V_59 ;
return V_55 ;
}
static T_1 F_36 ( T_1 V_60 )
{
T_1 V_55 ;
V_55 = V_60 ;
return V_55 ;
}
static T_1 F_37 ( T_1 V_60 )
{
T_1 V_55 ;
V_55 = V_64 ;
V_55 |= V_60 ;
return V_55 ;
}
static T_1 F_38 ( T_1 V_65 )
{
T_1 V_55 ;
V_55 = V_65 ;
return V_55 ;
}
static T_1 F_39 ( void )
{
T_1 V_55 ;
V_55 = 0 ;
return V_55 ;
}
static struct V_42 * F_40 (
struct V_2 * V_4 , struct V_66 * V_67 , unsigned V_68 ,
enum V_69 V_70 , unsigned long V_71 , void * V_72 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_10 * V_73 ;
struct V_66 * V_74 ;
unsigned int V_22 ;
unsigned int V_75 ;
V_75 = 0 ;
V_73 = V_3 -> V_7 ;
F_41 (sgl, sg, sg_len, i) {
T_1 V_65 ;
T_1 V_31 ;
F_4 ( V_75 > 0 ) ;
V_65 = F_30 ( F_42 ( V_74 ) ) ;
V_31 = F_43 ( V_74 ) ;
V_73 -> V_35 = F_33 ( V_31 ) ;
V_73 -> V_76 = F_34 ( V_3 ) ;
V_73 -> V_33 = F_35 ( V_3 ) ;
V_73 -> V_77 = F_36 ( V_31 ) ;
V_73 -> V_78 = F_38 ( V_65 ) ;
V_73 -> V_79 = F_39 () ;
V_73 -> V_37 = F_37 ( V_31 ) ;
V_73 -> V_80 = F_38 ( V_65 ) ;
V_73 ++ ;
}
return & V_3 -> V_38 ;
}
static void F_44 ( struct V_10 * V_73 )
{
V_73 -> V_35 = V_81 << V_62 ;
}
static int F_45 ( struct V_1 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_10 * V_82 ;
T_1 V_55 ;
T_1 V_54 ;
T_1 V_83 ;
V_82 = V_6 -> V_84 ;
V_82 += V_6 -> V_85 ;
V_83 = V_6 -> V_12 ;
V_83 += V_6 -> V_85 * sizeof( struct V_10 ) ;
if ( ! V_3 -> V_86 ) {
F_44 ( V_82 ) ;
F_32 () ;
V_55 = ( sizeof( struct V_10 ) - 24 ) / 4 ;
V_55 |= V_83 ;
F_5 ( V_55 , V_6 -> V_18 +
F_11 ( V_6 -> V_87 . V_88 ) ) ;
V_55 = V_56 ;
if ( ! V_3 -> V_46 ) {
V_55 |= V_57 ;
V_55 |= V_58 ;
V_55 |= V_3 -> V_59 ;
}
V_55 |= V_89 ;
F_5 ( V_55 , V_3 -> V_47 ) ;
V_3 -> V_86 = 1 ;
V_3 -> V_90 = 500 ;
}
if ( ! V_3 -> V_91 || ! V_3 -> V_92 ) {
V_54 = F_10 ( V_6 , V_6 -> V_87 . V_93 ) ;
if ( ! V_54 )
V_54 = F_10 ( V_6 , V_3 -> V_59 ) ;
if ( V_54 == V_3 -> V_54 ) {
V_3 -> V_92 = 1 ;
} else if ( V_54 == V_83 ) {
T_1 V_35 ;
F_16 () ;
V_35 = V_82 -> V_35 ;
F_18 ( ( V_35 >> V_62 ) != V_81 ) ;
F_18 ( ! V_3 -> V_46 && ! ( V_35 & V_94 ) ) ;
F_18 ( ( V_35 & 0x1f ) != V_3 -> V_95 ) ;
V_3 -> V_91 = 1 ;
} else if ( V_54 ) {
F_46 ( 1 ) ;
}
}
V_3 -> V_90 -- ;
if ( ! V_3 -> V_91 && V_3 -> V_90 ) {
F_47 ( 1 ) ;
return - V_96 ;
}
F_18 ( ! V_3 -> V_90 ) ;
if ( ! V_3 -> V_92 ) {
V_54 = F_10 ( V_6 , V_3 -> V_29 ) ;
if ( ! V_54 )
V_54 = F_10 ( V_6 , V_3 -> V_59 ) ;
F_18 ( ! V_54 ) ;
}
V_3 -> V_86 = 0 ;
V_3 -> V_91 = 0 ;
V_3 -> V_92 = 0 ;
F_5 ( 0 , V_3 -> V_47 ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_4 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_3 -> V_6 ;
T_1 V_9 ;
T_1 V_54 ;
int V_52 ;
V_54 = F_30 ( V_3 -> V_54 ) ;
V_9 = ( V_54 - V_6 -> V_12 ) / sizeof( struct V_10 ) ;
if ( ! V_6 -> V_13 [ V_9 ] )
return 0 ;
V_52 = F_45 ( V_3 ) ;
if ( V_52 )
return V_52 ;
F_18 ( ! V_6 -> V_13 [ V_9 ] ) ;
V_6 -> V_13 [ V_9 ] = NULL ;
return 0 ;
}
static void F_49 ( struct V_5 * V_6 )
{
while ( ! F_50 ( & V_6 -> V_97 . V_98 ) ) {
struct V_1 * V_99 ;
V_99 = F_51 ( & V_6 -> V_97 . V_98 ,
struct V_1 , V_4 . V_100 ) ;
F_52 ( & V_99 -> V_4 . V_100 ) ;
F_53 ( V_99 ) ;
}
}
static int F_54 ( struct V_101 * V_102 , struct V_5 * V_6 )
{
struct V_1 * V_99 ;
int V_22 ;
int V_52 ;
T_1 V_103 ;
V_52 = F_55 ( V_102 -> V_104 , L_2 ,
& V_103 ) ;
if ( V_52 )
return V_52 ;
V_103 *= 2 ;
for ( V_22 = 0 ; V_22 < V_103 ; V_22 ++ ) {
V_99 = F_56 ( sizeof( * V_99 ) , V_105 ) ;
if ( ! V_99 )
goto V_106;
V_99 -> V_6 = V_6 ;
if ( V_22 & 1 ) {
V_99 -> V_47 = V_6 -> V_107 + F_57 ( V_22 >> 1 ) ;
V_99 -> V_46 = 1 ;
} else {
V_99 -> V_47 = V_6 -> V_107 + F_58 ( V_22 >> 1 ) ;
V_99 -> V_46 = 0 ;
}
V_99 -> V_95 = V_22 >> 1 ;
V_99 -> V_7 = & V_6 -> V_84 [ V_22 ] ;
V_99 -> V_54 = V_6 -> V_12 ;
V_99 -> V_54 += V_22 * sizeof( struct V_10 ) ;
V_99 -> V_4 . V_101 = & V_6 -> V_97 ;
F_59 ( & V_99 -> V_4 . V_100 , & V_6 -> V_97 . V_98 ) ;
}
V_6 -> V_85 = V_103 ;
return 0 ;
V_106:
F_49 ( V_6 ) ;
return - V_108 ;
}
static void F_60 ( struct V_101 * V_102 , struct V_5 * V_6 )
{
unsigned int V_109 ;
int V_22 ;
V_109 = V_11 * sizeof( struct V_10 ) ;
for ( V_22 = 0 ; V_22 < V_110 ; V_22 ++ ) {
F_5 ( 0 , V_6 -> V_18 + F_61 ( V_22 ) ) ;
F_5 ( 0 , V_6 -> V_18 + F_62 ( V_22 ) ) ;
F_63 ( V_102 , V_109 , V_6 -> V_84 ,
V_6 -> V_12 ) ;
}
}
static void F_64 ( struct V_5 * V_6 )
{
F_5 ( 0 , V_6 -> V_111 + V_112 ) ;
}
static void F_65 ( struct V_101 * V_102 , struct V_5 * V_6 )
{
F_64 ( V_6 ) ;
F_60 ( V_102 , V_6 ) ;
F_5 ( 0 , V_6 -> V_18 + V_113 ) ;
F_5 ( 0 , V_6 -> V_18 + V_113 ) ;
F_63 ( V_102 , V_114 , V_6 -> V_115 ,
V_6 -> V_116 ) ;
}
static int F_66 ( struct V_101 * V_102 , struct V_5 * V_6 )
{
unsigned int V_117 ;
unsigned int V_109 ;
int V_22 ;
T_1 V_55 ;
T_1 V_118 ;
F_67 ( sizeof( struct V_10 ) &
( sizeof( struct V_10 ) - 1 ) ) ;
F_67 ( sizeof( struct V_10 ) < 32 ) ;
F_67 ( V_11 < 32 ) ;
V_117 = sizeof( struct V_10 ) ;
V_109 = V_11 * V_117 ;
V_118 = 0 ;
for ( V_22 = 0 ; V_22 < V_110 ; V_22 ++ ) {
V_55 = V_118 << V_119 ;
V_55 |= ( F_68 ( V_117 ) - 5 ) << V_120 ;
V_55 |= F_68 ( V_11 ) - 5 ;
F_67 ( V_110 != 1 ) ;
V_6 -> V_84 = F_69 ( V_102 , V_109 ,
& V_6 -> V_12 , V_105 ) ;
if ( ! V_6 -> V_84 )
return - V_108 ;
F_5 ( V_6 -> V_12 , V_6 -> V_18 + F_61 ( V_22 ) ) ;
F_5 ( V_55 , V_6 -> V_18 + F_62 ( V_22 ) ) ;
V_118 += V_11 ;
}
return 0 ;
}
static void F_70 ( struct V_5 * V_6 )
{
unsigned V_121 ;
unsigned V_122 ;
T_1 V_55 ;
V_122 = 0 ;
F_5 ( 0 , V_6 -> V_111 + V_112 ) ;
for ( V_121 = 0 ; V_121 < 15 * 2 ; V_121 += 2 ) {
V_55 = F_71 ( V_121 ) ;
V_55 |= F_72 ( V_121 ) | V_123 ;
V_55 |= F_73 ( V_121 + 1 ) ;
V_55 |= F_74 ( V_121 + 1 ) | V_124 ;
F_5 ( V_55 , V_6 -> V_111 + F_75 ( V_122 ) ) ;
V_122 ++ ;
}
V_55 = 15 * 2 * 2 - 1 ;
V_55 |= V_125 ;
F_5 ( V_55 , V_6 -> V_111 + V_112 ) ;
}
static int F_76 ( struct V_101 * V_102 , struct V_5 * V_6 )
{
int V_52 ;
F_67 ( V_114 > ( ( 1 << 14 ) - 1 ) ) ;
V_6 -> V_115 = F_69 ( V_102 , V_114 ,
& V_6 -> V_116 , V_105 ) ;
if ( ! V_6 -> V_115 )
return - V_108 ;
F_5 ( V_6 -> V_116 , V_6 -> V_18 + V_113 ) ;
F_5 ( V_114 , V_6 -> V_18 + V_126 ) ;
F_5 ( 0 , V_6 -> V_18 + V_127 ) ;
V_52 = F_66 ( V_102 , V_6 ) ;
if ( V_52 )
goto V_128;
F_5 ( V_6 -> V_87 . V_88 , V_6 -> V_107 + V_129 ) ;
F_70 ( V_6 ) ;
return 0 ;
V_128:
F_65 ( V_102 , V_6 ) ;
return V_52 ;
}
static bool F_77 ( struct V_2 * V_4 , void * V_130 )
{
struct V_1 * V_99 ;
struct V_5 * V_6 ;
const struct V_131 * V_132 ;
T_1 * V_75 = V_130 ;
if ( V_4 -> V_101 -> V_102 -> V_133 != & V_134 . V_133 )
return false ;
V_99 = F_1 ( V_4 ) ;
if ( V_99 -> V_95 != V_75 [ V_135 ] )
return false ;
if ( V_99 -> V_46 && ! V_75 [ V_136 ] )
return false ;
V_6 = V_99 -> V_6 ;
if ( V_99 -> V_46 )
V_132 = V_6 -> V_137 ;
else
V_132 = V_6 -> V_138 ;
F_67 ( F_78 ( V_139 ) != F_78 ( V_140 ) ) ;
if ( F_18 ( V_99 -> V_95 > F_78 ( V_139 ) ) )
return false ;
V_99 -> V_29 = V_132 [ V_99 -> V_95 ] . V_88 ;
V_99 -> V_59 = V_132 [ V_99 -> V_95 ] . V_93 ;
return true ;
}
static struct V_2 * F_79 ( struct V_141 * V_142 ,
struct V_143 * V_144 )
{
int V_145 = V_142 -> V_146 ;
struct V_147 * V_148 = V_144 -> V_149 ;
if ( ! V_148 || ! V_148 -> V_150 )
return NULL ;
if ( V_145 != 2 )
return NULL ;
return F_80 ( V_148 -> V_151 , V_148 -> V_150 ,
& V_142 -> args [ 0 ] ) ;
}
static const struct V_152 * F_81 ( struct V_101 * V_102 )
{
const struct V_153 * V_154 ;
V_154 = F_82 ( V_155 , V_102 -> V_104 ) ;
if ( ! V_154 )
return NULL ;
return V_154 -> V_20 ;
}
static int F_83 ( struct V_156 * V_157 )
{
struct V_5 * V_6 ;
struct V_101 * V_102 = & V_157 -> V_102 ;
const struct V_152 * V_158 ;
int V_19 ;
int V_52 ;
V_158 = F_81 ( V_102 ) ;
if ( ! V_158 )
return - V_159 ;
V_6 = F_84 ( & V_157 -> V_102 , sizeof( * V_6 ) , V_105 ) ;
if ( ! V_6 )
return - V_108 ;
F_85 ( V_160 , V_6 -> V_97 . V_161 ) ;
V_6 -> V_97 . V_162 = F_23 ;
V_6 -> V_97 . V_163 = F_26 ;
V_6 -> V_97 . V_164 = F_27 ;
V_6 -> V_97 . V_165 = F_31 ;
V_6 -> V_97 . V_166 = F_40 ;
V_6 -> V_97 . V_167 = F_48 ;
V_6 -> V_97 . V_168 = F_86 ( V_169 ) | F_86 ( V_170 ) ;
V_6 -> V_97 . V_171 = V_172 ;
V_6 -> V_97 . V_173 = V_172 ;
V_6 -> V_97 . V_174 = V_175 ;
V_6 -> V_97 . V_102 = V_102 ;
F_87 ( & V_6 -> V_97 . V_98 ) ;
V_176 . V_151 = V_6 -> V_97 . V_161 ;
V_6 -> V_23 = F_88 ( V_102 -> V_104 , 0 ) ;
V_6 -> V_107 = F_88 ( V_102 -> V_104 , 1 ) ;
V_6 -> V_111 = F_88 ( V_102 -> V_104 , 2 ) ;
V_6 -> V_18 = F_88 ( V_102 -> V_104 , 3 ) ;
if ( ! V_6 -> V_23 || ! V_6 -> V_107 || ! V_6 -> V_111 ||
! V_6 -> V_18 )
return - V_177 ;
F_89 ( V_102 ) ;
V_52 = F_90 ( V_102 ) ;
if ( V_52 < 0 )
goto V_178;
V_6 -> V_138 = V_158 -> V_138 ;
V_6 -> V_137 = V_158 -> V_137 ;
V_6 -> V_87 = V_158 -> V_87 ;
V_52 = F_76 ( V_102 , V_6 ) ;
if ( V_52 )
goto V_179;
V_52 = F_54 ( V_102 , V_6 ) ;
if ( V_52 )
goto V_180;
V_19 = F_91 ( V_102 -> V_104 , 0 ) ;
if ( ! V_19 ) {
V_52 = - V_159 ;
goto V_181;
}
F_5 ( V_25 , V_6 -> V_23 + V_182 ) ;
V_52 = F_92 ( & V_157 -> V_102 , V_19 , V_158 -> V_183 , V_184 ,
F_93 ( V_102 ) , V_6 ) ;
if ( V_52 )
goto V_181;
V_6 -> V_19 = V_19 ;
V_52 = F_94 ( & V_6 -> V_97 ) ;
if ( V_52 )
goto V_185;
V_52 = F_95 ( V_102 -> V_104 ,
F_79 , & V_176 ) ;
if ( V_52 )
goto V_186;
F_96 ( V_157 , V_6 ) ;
return 0 ;
V_186:
F_97 ( & V_6 -> V_97 ) ;
V_185:
V_181:
F_5 ( 0 , V_6 -> V_23 + V_187 ) ;
F_49 ( V_6 ) ;
V_180:
F_65 ( V_102 , V_6 ) ;
V_179:
F_98 ( V_102 ) ;
V_178:
F_99 ( V_102 ) ;
F_100 ( V_6 -> V_23 ) ;
F_100 ( V_6 -> V_107 ) ;
F_100 ( V_6 -> V_111 ) ;
F_100 ( V_6 -> V_18 ) ;
return V_52 ;
}
static int F_101 ( struct V_156 * V_157 )
{
struct V_5 * V_6 = F_102 ( V_157 ) ;
F_103 ( V_157 -> V_102 . V_104 ) ;
F_97 ( & V_6 -> V_97 ) ;
F_5 ( 0 , V_6 -> V_23 + V_187 ) ;
F_104 ( & V_157 -> V_102 , V_6 -> V_19 , V_6 ) ;
F_49 ( V_6 ) ;
F_65 ( & V_157 -> V_102 , V_6 ) ;
F_100 ( V_6 -> V_23 ) ;
F_100 ( V_6 -> V_107 ) ;
F_100 ( V_6 -> V_111 ) ;
F_100 ( V_6 -> V_18 ) ;
F_98 ( & V_157 -> V_102 ) ;
F_99 ( & V_157 -> V_102 ) ;
return 0 ;
}
static int F_105 ( struct V_101 * V_102 )
{
struct V_5 * V_6 = F_106 ( V_102 ) ;
V_6 -> V_188 = F_7 ( V_6 -> V_107 + V_129 ) ;
F_5 ( 0 , V_6 -> V_23 + V_187 ) ;
F_64 ( V_6 ) ;
return 0 ;
}
static int F_107 ( struct V_101 * V_102 )
{
struct V_5 * V_6 = F_106 ( V_102 ) ;
struct V_1 * V_3 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_110 ; V_22 ++ )
F_5 ( V_6 -> V_12 , V_6 -> V_18 + F_61 ( V_22 ) ) ;
F_108 (c, &cdd->ddev.channels, chan.device_node)
if ( ! V_3 -> V_46 )
F_5 ( V_3 -> V_29 , V_3 -> V_47 + V_48 ) ;
F_70 ( V_6 ) ;
F_5 ( V_6 -> V_188 , V_6 -> V_107 + V_129 ) ;
F_5 ( V_6 -> V_116 , V_6 -> V_18 + V_113 ) ;
F_5 ( V_114 , V_6 -> V_18 + V_126 ) ;
F_5 ( 0 , V_6 -> V_18 + V_127 ) ;
F_5 ( V_25 , V_6 -> V_23 + V_182 ) ;
return 0 ;
}
