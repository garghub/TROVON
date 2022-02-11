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
int error ;
error = F_17 ( V_6 -> V_32 . V_33 ) ;
if ( error < 0 )
F_18 ( V_6 -> V_32 . V_33 , L_1 ,
V_34 , error ) ;
V_29 = F_19 ( V_14 ) ;
V_14 &= ~ ( 1 << V_29 ) ;
V_29 += 32 * V_22 ;
V_7 = F_10 ( V_6 , V_29 ) ;
V_3 = F_3 ( V_6 , V_7 ) ;
if ( F_20 ( ! V_3 ) ) {
F_21 ( L_2 , V_34 ,
V_29 , V_7 ) ;
continue;
}
if ( V_3 -> V_7 -> V_35 & V_36 )
V_31 = 0 ;
else
V_31 = F_9 ( V_3 -> V_7 -> V_37 ) ;
V_3 -> V_38 = F_9 ( V_3 -> V_7 -> V_39 ) - V_31 ;
F_22 ( & V_3 -> V_40 ) ;
F_23 ( & V_3 -> V_40 , NULL ) ;
F_24 ( V_6 -> V_32 . V_33 ) ;
F_25 ( V_6 -> V_32 . V_33 ) ;
}
}
return V_41 ;
}
static T_4 F_26 ( struct V_42 * V_43 )
{
T_4 V_44 ;
V_44 = F_27 ( V_43 ) ;
return V_44 ;
}
static int F_28 ( struct V_2 * V_4 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_3 -> V_6 ;
int error ;
error = F_29 ( V_6 -> V_32 . V_33 ) ;
if ( error < 0 ) {
F_18 ( V_6 -> V_32 . V_33 , L_1 ,
V_34 , error ) ;
F_30 ( V_6 -> V_32 . V_33 ) ;
return error ;
}
F_31 ( V_4 ) ;
F_32 ( & V_3 -> V_40 , V_4 ) ;
V_3 -> V_40 . V_45 = F_26 ;
if ( ! V_3 -> V_46 )
F_5 ( V_3 -> V_29 , V_3 -> V_47 + V_48 ) ;
F_24 ( V_6 -> V_32 . V_33 ) ;
F_25 ( V_6 -> V_32 . V_33 ) ;
return 0 ;
}
static void F_33 ( struct V_2 * V_4 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_3 -> V_6 ;
int error ;
error = F_29 ( V_6 -> V_32 . V_33 ) ;
if ( error < 0 ) {
F_30 ( V_6 -> V_32 . V_33 ) ;
return;
}
F_20 ( ! F_34 ( & V_6 -> V_49 ) ) ;
F_24 ( V_6 -> V_32 . V_33 ) ;
F_25 ( V_6 -> V_32 . V_33 ) ;
}
static enum V_50 F_35 ( struct V_2 * V_4 ,
T_4 V_44 , struct V_51 * V_52 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
enum V_50 V_53 ;
V_53 = F_36 ( V_4 , V_44 , V_52 ) ;
if ( V_52 && V_53 == V_54 )
V_52 -> V_38 = V_3 -> V_38 ;
return V_53 ;
}
static void F_37 ( struct V_1 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_1 V_9 ;
T_1 V_55 ;
T_1 V_56 ;
V_3 -> V_38 = 0 ;
V_56 = V_57 ;
if ( ! V_3 -> V_46 ) {
V_56 |= V_58 ;
V_56 |= V_59 ;
V_56 |= V_3 -> V_60 ;
}
F_5 ( V_56 , V_3 -> V_47 ) ;
F_38 () ;
V_55 = F_39 ( V_3 -> V_55 ) ;
V_9 = ( V_55 - V_6 -> V_12 ) / sizeof( struct V_10 ) ;
F_20 ( V_6 -> V_13 [ V_9 ] ) ;
V_6 -> V_13 [ V_9 ] = V_3 ;
V_56 = ( sizeof( struct V_10 ) - 24 ) / 4 ;
V_56 |= V_55 ;
F_5 ( V_56 , V_6 -> V_18 + F_11 ( V_3 -> V_29 ) ) ;
}
static void F_40 ( struct V_1 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
unsigned long V_61 ;
F_41 ( & V_6 -> V_62 , V_61 ) ;
F_42 ( & V_3 -> V_63 , & V_6 -> V_49 ) ;
F_43 ( & V_6 -> V_62 , V_61 ) ;
}
static void F_44 ( struct V_2 * V_4 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_3 -> V_6 ;
int error ;
error = F_17 ( V_6 -> V_32 . V_33 ) ;
if ( ( error != - V_64 ) && error < 0 ) {
F_30 ( V_6 -> V_32 . V_33 ) ;
F_18 ( V_6 -> V_32 . V_33 , L_3 ,
error ) ;
return;
}
if ( F_45 ( F_46 ( V_6 -> V_32 . V_33 ) ) )
F_37 ( V_3 ) ;
else
F_40 ( V_3 ) ;
F_24 ( V_6 -> V_32 . V_33 ) ;
F_25 ( V_6 -> V_32 . V_33 ) ;
}
static T_1 F_47 ( T_1 V_65 )
{
T_1 V_56 ;
V_56 = V_66 << V_67 ;
V_56 |= V_65 ;
return V_56 ;
}
static T_1 F_48 ( struct V_1 * V_3 )
{
T_1 V_56 ;
V_56 = 0 ;
return V_56 ;
}
static T_1 F_49 ( struct V_1 * V_3 )
{
T_1 V_56 ;
V_56 = V_68 ;
V_56 |= V_3 -> V_60 ;
return V_56 ;
}
static T_1 F_50 ( T_1 V_65 )
{
T_1 V_56 ;
V_56 = V_65 ;
return V_56 ;
}
static T_1 F_51 ( T_1 V_65 )
{
T_1 V_56 ;
V_56 = V_69 ;
V_56 |= V_65 ;
return V_56 ;
}
static T_1 F_52 ( T_1 V_70 )
{
T_1 V_56 ;
V_56 = V_70 ;
return V_56 ;
}
static T_1 F_53 ( void )
{
T_1 V_56 ;
V_56 = 0 ;
return V_56 ;
}
static struct V_42 * F_54 (
struct V_2 * V_4 , struct V_71 * V_72 , unsigned V_73 ,
enum V_74 V_75 , unsigned long V_76 , void * V_77 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_10 * V_78 ;
struct V_71 * V_79 ;
unsigned int V_22 ;
V_78 = V_3 -> V_7 ;
F_55 (sgl, sg, sg_len, i) {
T_1 V_70 ;
T_1 V_31 ;
V_70 = F_39 ( F_56 ( V_79 ) ) ;
V_31 = F_57 ( V_79 ) ;
V_78 -> V_37 = F_47 ( V_31 ) ;
V_78 -> V_80 = F_48 ( V_3 ) ;
V_78 -> V_35 = F_49 ( V_3 ) ;
V_78 -> V_81 = F_50 ( V_31 ) ;
V_78 -> V_82 = F_52 ( V_70 ) ;
V_78 -> V_83 = F_53 () ;
V_78 -> V_39 = F_51 ( V_31 ) ;
V_78 -> V_84 = F_52 ( V_70 ) ;
V_78 ++ ;
}
return & V_3 -> V_40 ;
}
static void F_58 ( struct V_10 * V_78 )
{
V_78 -> V_37 = V_85 << V_67 ;
}
static int F_59 ( struct V_1 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_10 * V_86 ;
T_1 V_56 ;
T_1 V_55 ;
T_1 V_87 ;
V_86 = V_6 -> V_88 ;
V_86 += V_6 -> V_89 ;
V_87 = V_6 -> V_12 ;
V_87 += V_6 -> V_89 * sizeof( struct V_10 ) ;
if ( ! V_3 -> V_90 ) {
F_58 ( V_86 ) ;
F_38 () ;
V_56 = ( sizeof( struct V_10 ) - 24 ) / 4 ;
V_56 |= V_87 ;
F_5 ( V_56 , V_6 -> V_18 +
F_11 ( V_6 -> V_91 . V_92 ) ) ;
V_56 = V_57 ;
if ( ! V_3 -> V_46 ) {
V_56 |= V_58 ;
V_56 |= V_59 ;
V_56 |= V_3 -> V_60 ;
}
V_56 |= V_93 ;
F_5 ( V_56 , V_3 -> V_47 ) ;
V_3 -> V_90 = 1 ;
V_3 -> V_94 = 500 ;
}
if ( ! V_3 -> V_95 || ! V_3 -> V_96 ) {
V_55 = F_10 ( V_6 , V_6 -> V_91 . V_97 ) ;
if ( ! V_55 )
V_55 = F_10 ( V_6 , V_3 -> V_60 ) ;
if ( V_55 == V_3 -> V_55 ) {
V_3 -> V_96 = 1 ;
} else if ( V_55 == V_87 ) {
T_1 V_37 ;
F_16 () ;
V_37 = V_86 -> V_37 ;
F_20 ( ( V_37 >> V_67 ) != V_85 ) ;
F_20 ( ! V_3 -> V_46 && ! ( V_37 & V_98 ) ) ;
F_20 ( ( V_37 & 0x1f ) != V_3 -> V_99 ) ;
V_3 -> V_95 = 1 ;
} else if ( V_55 ) {
F_60 ( 1 ) ;
}
}
V_3 -> V_94 -- ;
if ( ! V_3 -> V_95 && V_3 -> V_94 ) {
F_61 ( 1 ) ;
return - V_100 ;
}
F_20 ( ! V_3 -> V_94 ) ;
if ( ! V_3 -> V_96 ) {
V_55 = F_10 ( V_6 , V_3 -> V_29 ) ;
if ( ! V_55 )
V_55 = F_10 ( V_6 , V_3 -> V_60 ) ;
F_20 ( ! V_55 ) ;
}
V_3 -> V_90 = 0 ;
V_3 -> V_95 = 0 ;
V_3 -> V_96 = 0 ;
F_5 ( 0 , V_3 -> V_47 ) ;
return 0 ;
}
static int F_62 ( struct V_2 * V_4 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_3 -> V_6 ;
T_1 V_9 ;
T_1 V_55 ;
int V_53 ;
V_55 = F_39 ( V_3 -> V_55 ) ;
V_9 = ( V_55 - V_6 -> V_12 ) / sizeof( struct V_10 ) ;
if ( ! V_6 -> V_13 [ V_9 ] )
return 0 ;
V_53 = F_59 ( V_3 ) ;
if ( V_53 )
return V_53 ;
F_20 ( ! V_6 -> V_13 [ V_9 ] ) ;
V_6 -> V_13 [ V_9 ] = NULL ;
return 0 ;
}
static void F_63 ( struct V_5 * V_6 )
{
while ( ! F_34 ( & V_6 -> V_32 . V_101 ) ) {
struct V_1 * V_102 ;
V_102 = F_64 ( & V_6 -> V_32 . V_101 ,
struct V_1 , V_4 . V_103 ) ;
F_65 ( & V_102 -> V_4 . V_103 ) ;
F_66 ( V_102 ) ;
}
}
static int F_67 ( struct V_104 * V_33 , struct V_5 * V_6 )
{
struct V_1 * V_102 ;
int V_22 ;
int V_53 ;
T_1 V_105 ;
V_53 = F_68 ( V_33 -> V_106 , L_4 ,
& V_105 ) ;
if ( V_53 )
return V_53 ;
V_105 *= 2 ;
for ( V_22 = 0 ; V_22 < V_105 ; V_22 ++ ) {
V_102 = F_69 ( sizeof( * V_102 ) , V_107 ) ;
if ( ! V_102 )
goto V_108;
V_102 -> V_6 = V_6 ;
if ( V_22 & 1 ) {
V_102 -> V_47 = V_6 -> V_109 + F_70 ( V_22 >> 1 ) ;
V_102 -> V_46 = 1 ;
} else {
V_102 -> V_47 = V_6 -> V_109 + F_71 ( V_22 >> 1 ) ;
V_102 -> V_46 = 0 ;
}
V_102 -> V_99 = V_22 >> 1 ;
V_102 -> V_7 = & V_6 -> V_88 [ V_22 ] ;
V_102 -> V_55 = V_6 -> V_12 ;
V_102 -> V_55 += V_22 * sizeof( struct V_10 ) ;
V_102 -> V_4 . V_104 = & V_6 -> V_32 ;
F_42 ( & V_102 -> V_4 . V_103 , & V_6 -> V_32 . V_101 ) ;
}
V_6 -> V_89 = V_105 ;
return 0 ;
V_108:
F_63 ( V_6 ) ;
return - V_110 ;
}
static void F_72 ( struct V_104 * V_33 , struct V_5 * V_6 )
{
unsigned int V_111 ;
int V_22 ;
V_111 = V_11 * sizeof( struct V_10 ) ;
for ( V_22 = 0 ; V_22 < V_112 ; V_22 ++ ) {
F_5 ( 0 , V_6 -> V_18 + F_73 ( V_22 ) ) ;
F_5 ( 0 , V_6 -> V_18 + F_74 ( V_22 ) ) ;
F_75 ( V_33 , V_111 , V_6 -> V_88 ,
V_6 -> V_12 ) ;
}
}
static void F_76 ( struct V_5 * V_6 )
{
F_5 ( 0 , V_6 -> V_113 + V_114 ) ;
}
static void F_77 ( struct V_104 * V_33 , struct V_5 * V_6 )
{
F_76 ( V_6 ) ;
F_72 ( V_33 , V_6 ) ;
F_5 ( 0 , V_6 -> V_18 + V_115 ) ;
F_5 ( 0 , V_6 -> V_18 + V_115 ) ;
F_75 ( V_33 , V_116 , V_6 -> V_117 ,
V_6 -> V_118 ) ;
}
static int F_78 ( struct V_104 * V_33 , struct V_5 * V_6 )
{
unsigned int V_119 ;
unsigned int V_111 ;
int V_22 ;
T_1 V_56 ;
T_1 V_120 ;
F_79 ( sizeof( struct V_10 ) &
( sizeof( struct V_10 ) - 1 ) ) ;
F_79 ( sizeof( struct V_10 ) < 32 ) ;
F_79 ( V_11 < 32 ) ;
V_119 = sizeof( struct V_10 ) ;
V_111 = V_11 * V_119 ;
V_120 = 0 ;
for ( V_22 = 0 ; V_22 < V_112 ; V_22 ++ ) {
V_56 = V_120 << V_121 ;
V_56 |= ( F_80 ( V_119 ) - 5 ) << V_122 ;
V_56 |= F_80 ( V_11 ) - 5 ;
F_79 ( V_112 != 1 ) ;
V_6 -> V_88 = F_81 ( V_33 , V_111 ,
& V_6 -> V_12 , V_107 ) ;
if ( ! V_6 -> V_88 )
return - V_110 ;
F_5 ( V_6 -> V_12 , V_6 -> V_18 + F_73 ( V_22 ) ) ;
F_5 ( V_56 , V_6 -> V_18 + F_74 ( V_22 ) ) ;
V_120 += V_11 ;
}
return 0 ;
}
static void F_82 ( struct V_5 * V_6 )
{
unsigned V_123 ;
unsigned V_124 ;
T_1 V_56 ;
V_124 = 0 ;
F_5 ( 0 , V_6 -> V_113 + V_114 ) ;
for ( V_123 = 0 ; V_123 < 15 * 2 ; V_123 += 2 ) {
V_56 = F_83 ( V_123 ) ;
V_56 |= F_84 ( V_123 ) | V_125 ;
V_56 |= F_85 ( V_123 + 1 ) ;
V_56 |= F_86 ( V_123 + 1 ) | V_126 ;
F_5 ( V_56 , V_6 -> V_113 + F_87 ( V_124 ) ) ;
V_124 ++ ;
}
V_56 = 15 * 2 * 2 - 1 ;
V_56 |= V_127 ;
F_5 ( V_56 , V_6 -> V_113 + V_114 ) ;
}
static int F_88 ( struct V_104 * V_33 , struct V_5 * V_6 )
{
int V_53 ;
F_79 ( V_116 > ( ( 1 << 14 ) - 1 ) ) ;
V_6 -> V_117 = F_81 ( V_33 , V_116 ,
& V_6 -> V_118 , V_107 ) ;
if ( ! V_6 -> V_117 )
return - V_110 ;
F_5 ( V_6 -> V_118 , V_6 -> V_18 + V_115 ) ;
F_5 ( V_116 , V_6 -> V_18 + V_128 ) ;
F_5 ( 0 , V_6 -> V_18 + V_129 ) ;
V_53 = F_78 ( V_33 , V_6 ) ;
if ( V_53 )
goto V_130;
F_5 ( V_6 -> V_91 . V_92 , V_6 -> V_109 + V_131 ) ;
F_82 ( V_6 ) ;
return 0 ;
V_130:
F_77 ( V_33 , V_6 ) ;
return V_53 ;
}
static bool F_89 ( struct V_2 * V_4 , void * V_132 )
{
struct V_1 * V_102 ;
struct V_5 * V_6 ;
const struct V_133 * V_134 ;
T_1 * V_135 = V_132 ;
if ( V_4 -> V_104 -> V_33 -> V_136 != & V_137 . V_136 )
return false ;
V_102 = F_1 ( V_4 ) ;
if ( V_102 -> V_99 != V_135 [ V_138 ] )
return false ;
if ( V_102 -> V_46 && ! V_135 [ V_139 ] )
return false ;
V_6 = V_102 -> V_6 ;
if ( V_102 -> V_46 )
V_134 = V_6 -> V_140 ;
else
V_134 = V_6 -> V_141 ;
F_79 ( F_90 ( V_142 ) != F_90 ( V_143 ) ) ;
if ( F_20 ( V_102 -> V_99 > F_90 ( V_142 ) ) )
return false ;
V_102 -> V_29 = V_134 [ V_102 -> V_99 ] . V_92 ;
V_102 -> V_60 = V_134 [ V_102 -> V_99 ] . V_97 ;
return true ;
}
static struct V_2 * F_91 ( struct V_144 * V_145 ,
struct V_146 * V_147 )
{
int V_148 = V_145 -> V_149 ;
struct V_150 * V_151 = V_147 -> V_152 ;
if ( ! V_151 || ! V_151 -> V_153 )
return NULL ;
if ( V_148 != 2 )
return NULL ;
return F_92 ( V_151 -> V_154 , V_151 -> V_153 ,
& V_145 -> args [ 0 ] ) ;
}
static const struct V_155 * F_93 ( struct V_104 * V_33 )
{
const struct V_156 * V_157 ;
V_157 = F_94 ( V_158 , V_33 -> V_106 ) ;
if ( ! V_157 )
return NULL ;
return V_157 -> V_20 ;
}
static int F_95 ( struct V_159 * V_160 )
{
struct V_5 * V_6 ;
struct V_104 * V_33 = & V_160 -> V_33 ;
const struct V_155 * V_161 ;
int V_19 ;
int V_53 ;
V_161 = F_93 ( V_33 ) ;
if ( ! V_161 )
return - V_162 ;
V_6 = F_96 ( & V_160 -> V_33 , sizeof( * V_6 ) , V_107 ) ;
if ( ! V_6 )
return - V_110 ;
F_97 ( V_163 , V_6 -> V_32 . V_164 ) ;
V_6 -> V_32 . V_165 = F_28 ;
V_6 -> V_32 . V_166 = F_33 ;
V_6 -> V_32 . V_167 = F_35 ;
V_6 -> V_32 . V_168 = F_44 ;
V_6 -> V_32 . V_169 = F_54 ;
V_6 -> V_32 . V_170 = F_62 ;
V_6 -> V_32 . V_171 = F_98 ( V_172 ) | F_98 ( V_173 ) ;
V_6 -> V_32 . V_174 = V_175 ;
V_6 -> V_32 . V_176 = V_175 ;
V_6 -> V_32 . V_177 = V_178 ;
V_6 -> V_32 . V_33 = V_33 ;
F_99 ( & V_6 -> V_32 . V_101 ) ;
V_179 . V_154 = V_6 -> V_32 . V_164 ;
V_6 -> V_23 = F_100 ( V_33 -> V_106 , 0 ) ;
V_6 -> V_109 = F_100 ( V_33 -> V_106 , 1 ) ;
V_6 -> V_113 = F_100 ( V_33 -> V_106 , 2 ) ;
V_6 -> V_18 = F_100 ( V_33 -> V_106 , 3 ) ;
F_101 ( & V_6 -> V_62 ) ;
F_99 ( & V_6 -> V_49 ) ;
F_102 ( V_160 , V_6 ) ;
if ( ! V_6 -> V_23 || ! V_6 -> V_109 || ! V_6 -> V_113 ||
! V_6 -> V_18 )
return - V_180 ;
F_103 ( V_33 ) ;
F_104 ( V_33 , 100 ) ;
F_105 ( V_33 ) ;
V_53 = F_29 ( V_33 ) ;
if ( V_53 < 0 )
goto V_181;
V_6 -> V_141 = V_161 -> V_141 ;
V_6 -> V_140 = V_161 -> V_140 ;
V_6 -> V_91 = V_161 -> V_91 ;
V_53 = F_88 ( V_33 , V_6 ) ;
if ( V_53 )
goto V_182;
V_53 = F_67 ( V_33 , V_6 ) ;
if ( V_53 )
goto V_183;
V_19 = F_106 ( V_33 -> V_106 , 0 ) ;
if ( ! V_19 ) {
V_53 = - V_162 ;
goto V_184;
}
F_5 ( V_25 , V_6 -> V_23 + V_185 ) ;
V_53 = F_107 ( & V_160 -> V_33 , V_19 , V_161 -> V_186 , V_187 ,
F_108 ( V_33 ) , V_6 ) ;
if ( V_53 )
goto V_184;
V_6 -> V_19 = V_19 ;
V_53 = F_109 ( & V_6 -> V_32 ) ;
if ( V_53 )
goto V_188;
V_53 = F_110 ( V_33 -> V_106 ,
F_91 , & V_179 ) ;
if ( V_53 )
goto V_189;
F_24 ( V_33 ) ;
F_25 ( V_33 ) ;
return 0 ;
V_189:
F_111 ( & V_6 -> V_32 ) ;
V_188:
V_184:
F_5 ( 0 , V_6 -> V_23 + V_190 ) ;
F_63 ( V_6 ) ;
V_183:
F_77 ( V_33 , V_6 ) ;
V_182:
F_112 ( V_33 ) ;
V_181:
F_113 ( V_33 ) ;
F_114 ( V_33 ) ;
F_115 ( V_6 -> V_23 ) ;
F_115 ( V_6 -> V_109 ) ;
F_115 ( V_6 -> V_113 ) ;
F_115 ( V_6 -> V_18 ) ;
return V_53 ;
}
static int F_116 ( struct V_159 * V_160 )
{
struct V_5 * V_6 = F_117 ( V_160 ) ;
int error ;
error = F_29 ( & V_160 -> V_33 ) ;
if ( error < 0 )
F_18 ( & V_160 -> V_33 , L_5 ,
V_34 , error ) ;
F_118 ( V_160 -> V_33 . V_106 ) ;
F_111 ( & V_6 -> V_32 ) ;
F_5 ( 0 , V_6 -> V_23 + V_190 ) ;
F_119 ( & V_160 -> V_33 , V_6 -> V_19 , V_6 ) ;
F_63 ( V_6 ) ;
F_77 ( & V_160 -> V_33 , V_6 ) ;
F_115 ( V_6 -> V_23 ) ;
F_115 ( V_6 -> V_109 ) ;
F_115 ( V_6 -> V_113 ) ;
F_115 ( V_6 -> V_18 ) ;
F_112 ( & V_160 -> V_33 ) ;
F_113 ( & V_160 -> V_33 ) ;
F_114 ( & V_160 -> V_33 ) ;
return 0 ;
}
static int T_5 F_120 ( struct V_104 * V_33 )
{
struct V_5 * V_6 = F_121 ( V_33 ) ;
V_6 -> V_191 = F_7 ( V_6 -> V_109 + V_131 ) ;
F_5 ( 0 , V_6 -> V_23 + V_190 ) ;
F_76 ( V_6 ) ;
return 0 ;
}
static int T_5 F_122 ( struct V_104 * V_33 )
{
struct V_5 * V_6 = F_121 ( V_33 ) ;
struct V_1 * V_3 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_112 ; V_22 ++ )
F_5 ( V_6 -> V_12 , V_6 -> V_18 + F_73 ( V_22 ) ) ;
F_123 (c, &cdd->ddev.channels, chan.device_node)
if ( ! V_3 -> V_46 )
F_5 ( V_3 -> V_29 , V_3 -> V_47 + V_48 ) ;
F_82 ( V_6 ) ;
F_5 ( V_6 -> V_191 , V_6 -> V_109 + V_131 ) ;
F_5 ( V_6 -> V_118 , V_6 -> V_18 + V_115 ) ;
F_5 ( V_116 , V_6 -> V_18 + V_128 ) ;
F_5 ( 0 , V_6 -> V_18 + V_129 ) ;
F_5 ( V_25 , V_6 -> V_23 + V_185 ) ;
return 0 ;
}
static int T_5 F_124 ( struct V_104 * V_33 )
{
struct V_5 * V_6 = F_121 ( V_33 ) ;
F_20 ( ! F_34 ( & V_6 -> V_49 ) ) ;
return 0 ;
}
static int T_5 F_125 ( struct V_104 * V_33 )
{
struct V_5 * V_6 = F_121 ( V_33 ) ;
struct V_1 * V_3 , * V_192 ;
unsigned long V_61 ;
F_41 ( & V_6 -> V_62 , V_61 ) ;
F_126 (c, _c, &cdd->pending, node) {
F_37 ( V_3 ) ;
F_65 ( & V_3 -> V_63 ) ;
}
F_43 ( & V_6 -> V_62 , V_61 ) ;
return 0 ;
}
