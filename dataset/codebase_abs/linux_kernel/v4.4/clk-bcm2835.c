static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_5 | V_4 , V_2 -> V_6 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_6 + V_3 ) ;
}
void T_2 F_5 ( void )
{
struct V_7 * V_7 ;
int V_8 ;
V_7 = F_6 ( NULL , L_1 , NULL , V_9 ,
126000000 ) ;
if ( F_7 ( V_7 ) )
F_8 ( L_2 ) ;
V_7 = F_6 ( NULL , L_3 , NULL , V_9 ,
3000000 ) ;
if ( F_7 ( V_7 ) )
F_8 ( L_4 ) ;
V_8 = F_9 ( V_7 , NULL , L_5 ) ;
if ( V_8 )
F_8 ( L_6 ) ;
V_7 = F_6 ( NULL , L_7 , NULL , V_9 ,
125000000 ) ;
if ( F_7 ( V_7 ) )
F_8 ( L_8 ) ;
V_8 = F_9 ( V_7 , NULL , L_9 ) ;
if ( V_8 )
F_8 ( L_10 ) ;
}
static int F_10 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_11 ( V_11 , struct V_12 , V_11 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
const struct V_14 * V_15 = V_13 -> V_15 ;
return F_3 ( V_2 , V_15 -> V_16 ) &
V_17 ;
}
static void F_12 ( unsigned long V_18 ,
unsigned long V_19 ,
T_1 * V_20 , T_1 * V_21 )
{
T_3 div ;
div = ( T_3 ) V_18 << V_22 ;
F_13 ( div , V_19 ) ;
* V_20 = div >> V_22 ;
* V_21 = div & ( ( 1 << V_22 ) - 1 ) ;
}
static long F_14 ( unsigned long V_19 ,
T_1 V_20 , T_1 V_21 , T_1 V_23 )
{
T_3 V_18 ;
if ( V_23 == 0 )
return 0 ;
V_18 = ( T_3 ) V_19 * ( ( V_20 << V_22 ) + V_21 ) ;
F_13 ( V_18 , V_23 ) ;
return V_18 >> V_22 ;
}
static long F_15 ( struct V_10 * V_11 , unsigned long V_18 ,
unsigned long * V_19 )
{
T_1 V_20 , V_21 ;
F_12 ( V_18 , * V_19 , & V_20 , & V_21 ) ;
return F_14 ( * V_19 , V_20 , V_21 , 1 ) ;
}
static unsigned long F_16 ( struct V_10 * V_11 ,
unsigned long V_19 )
{
struct V_12 * V_13 = F_11 ( V_11 , struct V_12 , V_11 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
const struct V_14 * V_15 = V_13 -> V_15 ;
T_1 V_24 = F_3 ( V_2 , V_15 -> V_16 ) ;
T_1 V_20 , V_23 , V_21 ;
bool V_25 ;
if ( V_19 == 0 )
return 0 ;
V_21 = F_3 ( V_2 , V_15 -> V_26 ) & V_27 ;
V_20 = ( V_24 & V_28 ) >> V_29 ;
V_23 = ( V_24 & V_30 ) >> V_31 ;
V_25 = F_3 ( V_2 , V_15 -> V_32 + 4 ) &
V_15 -> V_33 -> V_34 ;
if ( V_25 )
V_20 *= 2 ;
return F_14 ( V_19 , V_20 , V_21 , V_23 ) ;
}
static void F_17 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_11 ( V_11 , struct V_12 , V_11 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
const struct V_14 * V_15 = V_13 -> V_15 ;
F_1 ( V_2 , V_15 -> V_35 , V_36 ) ;
F_1 ( V_2 , V_15 -> V_16 , V_37 ) ;
}
static int F_18 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_11 ( V_11 , struct V_12 , V_11 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
const struct V_14 * V_15 = V_13 -> V_15 ;
T_4 V_38 ;
F_1 ( V_2 , V_15 -> V_35 ,
F_3 ( V_2 , V_15 -> V_35 ) & ~ V_36 ) ;
V_38 = F_19 ( F_20 () , V_39 ) ;
while ( ! ( F_3 ( V_2 , V_40 ) & V_15 -> V_41 ) ) {
if ( F_21 ( F_20 () , V_38 ) ) {
F_22 ( V_2 -> V_42 , L_11 ,
F_23 ( V_11 ) ) ;
return - V_43 ;
}
F_24 () ;
}
return 0 ;
}
static void
F_25 ( struct V_1 * V_2 , T_1 V_32 , T_1 * V_33 )
{
int V_44 ;
for ( V_44 = 3 ; V_44 >= 0 ; V_44 -- )
F_1 ( V_2 , V_32 + V_44 * 4 , V_33 [ V_44 ] ) ;
}
static int F_26 ( struct V_10 * V_11 ,
unsigned long V_18 , unsigned long V_19 )
{
struct V_12 * V_13 = F_11 ( V_11 , struct V_12 , V_11 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
const struct V_14 * V_15 = V_13 -> V_15 ;
bool V_45 , V_46 , V_47 ;
T_1 V_20 , V_21 , V_48 ;
T_1 V_33 [ 4 ] ;
int V_44 ;
if ( V_18 < V_15 -> V_49 || V_18 > V_15 -> V_50 ) {
F_22 ( V_2 -> V_42 , L_12 ,
F_23 ( V_11 ) , V_18 ,
V_15 -> V_49 , V_15 -> V_50 ) ;
return - V_51 ;
}
if ( V_18 > V_15 -> V_52 ) {
V_46 = true ;
V_18 /= 2 ;
} else {
V_46 = false ;
}
F_12 ( V_18 , V_19 , & V_20 , & V_21 ) ;
for ( V_44 = 3 ; V_44 >= 0 ; V_44 -- )
V_33 [ V_44 ] = F_3 ( V_2 , V_15 -> V_32 + V_44 * 4 ) ;
V_45 = V_33 [ 1 ] & V_15 -> V_33 -> V_34 ;
V_33 [ 0 ] &= ~ V_15 -> V_33 -> V_53 ;
V_33 [ 0 ] |= V_15 -> V_33 -> V_54 ;
V_33 [ 1 ] &= ~ V_15 -> V_33 -> V_55 ;
V_33 [ 1 ] |= V_15 -> V_33 -> V_56 ;
V_33 [ 3 ] &= ~ V_15 -> V_33 -> V_57 ;
V_33 [ 3 ] |= V_15 -> V_33 -> V_58 ;
if ( V_45 && ! V_46 ) {
V_33 [ 1 ] &= ~ V_15 -> V_33 -> V_34 ;
V_47 = true ;
} else if ( ! V_45 && V_46 ) {
V_33 [ 1 ] |= V_15 -> V_33 -> V_34 ;
V_47 = false ;
} else {
V_47 = true ;
}
F_1 ( V_2 , V_59 ,
F_3 ( V_2 , V_59 ) |
V_15 -> V_60 ) ;
if ( V_47 )
F_25 ( V_2 , V_15 -> V_32 , V_33 ) ;
F_1 ( V_2 , V_15 -> V_26 , V_21 ) ;
V_48 = F_3 ( V_2 , V_15 -> V_16 ) ;
V_48 &= ~ V_28 ;
V_48 |= V_20 << V_29 ;
V_48 &= ~ V_30 ;
V_48 |= 1 << V_31 ;
F_1 ( V_2 , V_15 -> V_16 , V_48 ) ;
if ( ! V_47 )
F_25 ( V_2 , V_15 -> V_32 , V_33 ) ;
return 0 ;
}
static struct V_61 *
F_27 ( struct V_10 * V_11 )
{
return F_11 ( V_11 , struct V_61 , div . V_11 ) ;
}
static int F_28 ( struct V_10 * V_11 )
{
struct V_61 * V_62 = F_27 ( V_11 ) ;
struct V_1 * V_2 = V_62 -> V_2 ;
const struct V_63 * V_15 = V_62 -> V_15 ;
return ! ( F_3 ( V_2 , V_15 -> V_64 ) & V_65 ) ;
}
static long F_29 ( struct V_10 * V_11 ,
unsigned long V_18 ,
unsigned long * V_19 )
{
return V_66 . V_67 ( V_11 , V_18 , V_19 ) ;
}
static unsigned long F_30 ( struct V_10 * V_11 ,
unsigned long V_19 )
{
struct V_61 * V_62 = F_27 ( V_11 ) ;
struct V_1 * V_2 = V_62 -> V_2 ;
const struct V_63 * V_15 = V_62 -> V_15 ;
T_1 div = F_3 ( V_2 , V_15 -> V_64 ) ;
div &= ( 1 << V_68 ) - 1 ;
if ( div == 0 )
div = 256 ;
return V_19 / div ;
}
static void F_31 ( struct V_10 * V_11 )
{
struct V_61 * V_62 = F_27 ( V_11 ) ;
struct V_1 * V_2 = V_62 -> V_2 ;
const struct V_63 * V_15 = V_62 -> V_15 ;
F_1 ( V_2 , V_15 -> V_69 ,
( F_3 ( V_2 , V_15 -> V_69 ) &
~ V_15 -> V_70 ) | V_15 -> V_71 ) ;
F_1 ( V_2 , V_15 -> V_64 , V_65 ) ;
}
static int F_32 ( struct V_10 * V_11 )
{
struct V_61 * V_62 = F_27 ( V_11 ) ;
struct V_1 * V_2 = V_62 -> V_2 ;
const struct V_63 * V_15 = V_62 -> V_15 ;
F_1 ( V_2 , V_15 -> V_64 ,
F_3 ( V_2 , V_15 -> V_64 ) &
~ V_65 ) ;
F_1 ( V_2 , V_15 -> V_69 ,
F_3 ( V_2 , V_15 -> V_69 ) & ~ V_15 -> V_71 ) ;
return 0 ;
}
static int F_33 ( struct V_10 * V_11 ,
unsigned long V_18 ,
unsigned long V_19 )
{
struct V_61 * V_62 = F_27 ( V_11 ) ;
struct V_1 * V_2 = V_62 -> V_2 ;
const struct V_63 * V_15 = V_62 -> V_15 ;
T_1 V_72 ;
int V_8 ;
V_8 = V_66 . V_73 ( V_11 , V_18 , V_19 ) ;
if ( V_8 )
return V_8 ;
V_72 = F_3 ( V_2 , V_15 -> V_69 ) ;
F_1 ( V_2 , V_15 -> V_69 , V_72 | V_15 -> V_70 ) ;
F_1 ( V_2 , V_15 -> V_69 , V_72 & ~ V_15 -> V_70 ) ;
return 0 ;
}
static struct V_74 * F_34 ( struct V_10 * V_11 )
{
return F_11 ( V_11 , struct V_74 , V_11 ) ;
}
static int F_35 ( struct V_10 * V_11 )
{
struct V_74 * clock = F_34 ( V_11 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_75 * V_15 = clock -> V_15 ;
return ( F_3 ( V_2 , V_15 -> V_76 ) & V_77 ) != 0 ;
}
static T_1 F_36 ( struct V_10 * V_11 ,
unsigned long V_18 ,
unsigned long V_19 )
{
struct V_74 * clock = F_34 ( V_11 ) ;
const struct V_75 * V_15 = clock -> V_15 ;
T_1 V_78 = F_37 ( V_79 - V_15 -> V_80 , 0 ) ;
T_3 V_81 = ( T_3 ) V_19 << V_79 ;
T_1 div ;
F_13 ( V_81 , V_18 ) ;
div = V_81 ;
if ( V_78 != 0 ) {
div += V_78 >> 1 ;
div &= ~ V_78 ;
}
div = F_38 ( div , V_78 + 1 ) ;
div = F_39 ( T_1 , div , F_37 ( V_15 -> V_82 + V_79 - 1 ,
V_79 - V_15 -> V_80 ) ) ;
return div ;
}
static long F_40 ( struct V_74 * clock ,
unsigned long V_19 ,
T_1 div )
{
const struct V_75 * V_15 = clock -> V_15 ;
T_3 V_81 ;
div >>= V_79 - V_15 -> V_80 ;
div &= ( 1 << ( V_15 -> V_82 + V_15 -> V_80 ) ) - 1 ;
if ( div == 0 )
return 0 ;
V_81 = ( T_3 ) V_19 << V_15 -> V_80 ;
F_13 ( V_81 , div ) ;
return V_81 ;
}
static long F_41 ( struct V_10 * V_11 ,
unsigned long V_18 ,
unsigned long * V_19 )
{
struct V_74 * clock = F_34 ( V_11 ) ;
T_1 div = F_36 ( V_11 , V_18 , * V_19 ) ;
return F_40 ( clock , * V_19 , div ) ;
}
static unsigned long F_42 ( struct V_10 * V_11 ,
unsigned long V_19 )
{
struct V_74 * clock = F_34 ( V_11 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_75 * V_15 = clock -> V_15 ;
T_1 div = F_3 ( V_2 , V_15 -> V_83 ) ;
return F_40 ( clock , V_19 , div ) ;
}
static void F_43 ( struct V_74 * clock )
{
struct V_1 * V_2 = clock -> V_2 ;
const struct V_75 * V_15 = clock -> V_15 ;
T_4 V_38 = F_19 ( F_20 () , V_39 ) ;
while ( F_3 ( V_2 , V_15 -> V_76 ) & V_84 ) {
if ( F_21 ( F_20 () , V_38 ) ) {
F_22 ( V_2 -> V_42 , L_11 ,
F_23 ( & clock -> V_11 ) ) ;
return;
}
F_24 () ;
}
}
static void F_44 ( struct V_10 * V_11 )
{
struct V_74 * clock = F_34 ( V_11 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_75 * V_15 = clock -> V_15 ;
F_45 ( & V_2 -> V_85 ) ;
F_1 ( V_2 , V_15 -> V_76 ,
F_3 ( V_2 , V_15 -> V_76 ) & ~ V_77 ) ;
F_46 ( & V_2 -> V_85 ) ;
F_43 ( clock ) ;
}
static int F_47 ( struct V_10 * V_11 )
{
struct V_74 * clock = F_34 ( V_11 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_75 * V_15 = clock -> V_15 ;
F_45 ( & V_2 -> V_85 ) ;
F_1 ( V_2 , V_15 -> V_76 ,
F_3 ( V_2 , V_15 -> V_76 ) |
V_77 |
V_86 ) ;
F_46 ( & V_2 -> V_85 ) ;
return 0 ;
}
static int F_48 ( struct V_10 * V_11 ,
unsigned long V_18 , unsigned long V_19 )
{
struct V_74 * clock = F_34 ( V_11 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_75 * V_15 = clock -> V_15 ;
T_1 div = F_36 ( V_11 , V_18 , V_19 ) ;
F_1 ( V_2 , V_15 -> V_83 , div ) ;
return 0 ;
}
static int F_49 ( struct V_10 * V_11 )
{
return true ;
}
static struct V_7 * F_50 ( struct V_1 * V_2 ,
const struct V_14 * V_15 )
{
struct V_12 * V_13 ;
struct V_87 V_88 ;
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
V_88 . V_89 = & V_2 -> V_90 ;
V_88 . V_91 = 1 ;
V_88 . V_92 = V_15 -> V_92 ;
V_88 . V_93 = & V_94 ;
V_88 . V_95 = V_96 ;
V_13 = F_51 ( sizeof( * V_13 ) , V_97 ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_2 = V_2 ;
V_13 -> V_15 = V_15 ;
V_13 -> V_11 . V_88 = & V_88 ;
return F_52 ( V_2 -> V_42 , & V_13 -> V_11 ) ;
}
static struct V_7 *
F_53 ( struct V_1 * V_2 ,
const struct V_63 * V_15 )
{
struct V_61 * V_62 ;
struct V_87 V_88 ;
struct V_7 * V_7 ;
const char * V_98 ;
if ( V_15 -> V_99 != 1 ) {
V_98 = F_54 ( V_2 -> V_42 , V_97 ,
L_13 , V_15 -> V_92 ) ;
if ( ! V_98 )
return NULL ;
} else {
V_98 = V_15 -> V_92 ;
}
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
V_88 . V_89 = & V_15 -> V_100 -> V_92 ;
V_88 . V_91 = 1 ;
V_88 . V_92 = V_98 ;
V_88 . V_93 = & V_101 ;
V_88 . V_95 = V_102 | V_96 ;
V_62 = F_55 ( V_2 -> V_42 , sizeof( * V_62 ) , V_97 ) ;
if ( ! V_62 )
return NULL ;
V_62 -> div . V_3 = V_2 -> V_6 + V_15 -> V_64 ;
V_62 -> div . V_103 = V_104 ;
V_62 -> div . V_105 = V_68 ;
V_62 -> div . V_95 = 0 ;
V_62 -> div . V_106 = & V_2 -> V_85 ;
V_62 -> div . V_11 . V_88 = & V_88 ;
V_62 -> div . V_107 = NULL ;
V_62 -> V_2 = V_2 ;
V_62 -> V_15 = V_15 ;
V_7 = F_52 ( V_2 -> V_42 , & V_62 -> div . V_11 ) ;
if ( F_7 ( V_7 ) )
return V_7 ;
if ( V_15 -> V_99 != 1 ) {
return F_56 ( V_2 -> V_42 , V_15 -> V_92 ,
V_98 ,
V_102 ,
1 ,
V_15 -> V_99 ) ;
}
return V_7 ;
}
static struct V_7 * F_57 ( struct V_1 * V_2 ,
const struct V_75 * V_15 )
{
struct V_74 * clock ;
struct V_87 V_88 ;
const char * V_108 ;
if ( V_15 -> V_109 ) {
const char * V_110 [ 1 << V_111 ] ;
int V_44 ;
V_108 = F_54 ( V_2 -> V_42 , V_97 ,
L_14 , V_15 -> V_92 ) ;
if ( ! V_108 )
return NULL ;
for ( V_44 = 0 ; V_44 < V_15 -> V_109 ; V_44 ++ ) {
if ( strcmp ( V_15 -> V_110 [ V_44 ] , L_15 ) == 0 )
V_110 [ V_44 ] = V_2 -> V_90 ;
else
V_110 [ V_44 ] = V_15 -> V_110 [ V_44 ] ;
}
F_58 ( V_2 -> V_42 , V_108 ,
V_110 , V_15 -> V_109 ,
V_102 ,
V_2 -> V_6 + V_15 -> V_76 ,
V_112 , V_111 ,
0 , & V_2 -> V_85 ) ;
} else {
V_108 = V_15 -> V_110 [ 0 ] ;
}
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
V_88 . V_89 = & V_108 ;
V_88 . V_91 = 1 ;
V_88 . V_92 = V_15 -> V_92 ;
V_88 . V_95 = V_96 ;
if ( V_15 -> V_113 ) {
V_88 . V_93 = & V_114 ;
} else {
V_88 . V_93 = & V_115 ;
V_88 . V_95 |= V_116 | V_117 ;
}
clock = F_55 ( V_2 -> V_42 , sizeof( * clock ) , V_97 ) ;
if ( ! clock )
return NULL ;
clock -> V_2 = V_2 ;
clock -> V_15 = V_15 ;
clock -> V_11 . V_88 = & V_88 ;
return F_52 ( V_2 -> V_42 , & clock -> V_11 ) ;
}
static int F_59 ( struct V_118 * V_119 )
{
struct V_120 * V_42 = & V_119 -> V_42 ;
struct V_7 * * V_121 ;
struct V_1 * V_2 ;
struct V_122 * V_123 ;
V_2 = F_55 ( V_42 , sizeof( * V_2 ) , V_97 ) ;
if ( ! V_2 )
return - V_124 ;
F_60 ( & V_2 -> V_85 ) ;
V_2 -> V_42 = V_42 ;
V_123 = F_61 ( V_119 , V_125 , 0 ) ;
V_2 -> V_6 = F_62 ( V_42 , V_123 ) ;
if ( F_7 ( V_2 -> V_6 ) )
return F_63 ( V_2 -> V_6 ) ;
V_2 -> V_90 = F_64 ( V_42 -> V_126 , 0 ) ;
if ( ! V_2 -> V_90 )
return - V_127 ;
F_65 ( V_119 , V_2 ) ;
V_2 -> V_128 . V_129 = V_130 ;
V_2 -> V_128 . V_121 = V_2 -> V_121 ;
V_121 = V_2 -> V_121 ;
V_121 [ V_131 ] = F_50 ( V_2 , & V_132 ) ;
V_121 [ V_133 ] = F_50 ( V_2 , & V_134 ) ;
V_121 [ V_135 ] = F_50 ( V_2 , & V_136 ) ;
V_121 [ V_137 ] = F_50 ( V_2 , & V_138 ) ;
V_121 [ V_139 ] = F_50 ( V_2 , & V_140 ) ;
V_121 [ V_141 ] =
F_53 ( V_2 , & V_142 ) ;
V_121 [ V_143 ] =
F_53 ( V_2 , & V_144 ) ;
V_121 [ V_145 ] =
F_53 ( V_2 , & V_146 ) ;
V_121 [ V_147 ] =
F_53 ( V_2 , & V_148 ) ;
V_121 [ V_149 ] =
F_53 ( V_2 , & V_150 ) ;
V_121 [ V_151 ] =
F_53 ( V_2 , & V_152 ) ;
V_121 [ V_153 ] =
F_53 ( V_2 , & V_154 ) ;
V_121 [ V_155 ] =
F_53 ( V_2 , & V_156 ) ;
V_121 [ V_157 ] =
F_53 ( V_2 , & V_158 ) ;
V_121 [ V_159 ] =
F_53 ( V_2 , & V_160 ) ;
V_121 [ V_161 ] =
F_53 ( V_2 , & V_162 ) ;
V_121 [ V_163 ] =
F_57 ( V_2 , & V_164 ) ;
V_121 [ V_165 ] =
F_57 ( V_2 , & V_166 ) ;
V_121 [ V_167 ] =
F_57 ( V_2 , & V_168 ) ;
V_121 [ V_169 ] =
F_57 ( V_2 , & V_170 ) ;
V_121 [ V_171 ] =
F_57 ( V_2 , & V_172 ) ;
V_121 [ V_173 ] =
F_57 ( V_2 , & V_174 ) ;
V_121 [ V_175 ] =
F_57 ( V_2 , & V_176 ) ;
V_121 [ V_171 ] =
F_57 ( V_2 , & V_172 ) ;
V_121 [ V_177 ] =
F_57 ( V_2 , & V_178 ) ;
V_121 [ V_179 ] =
F_57 ( V_2 , & V_180 ) ;
V_121 [ V_181 ] =
F_57 ( V_2 , & V_182 ) ;
V_121 [ V_183 ] =
F_57 ( V_2 , & V_184 ) ;
V_121 [ V_185 ] =
F_57 ( V_2 , & V_186 ) ;
V_121 [ V_187 ] =
F_66 ( V_42 , L_16 , L_17 ,
V_96 | V_116 ,
V_2 -> V_6 + V_188 , V_189 ,
0 , & V_2 -> V_85 ) ;
return F_67 ( V_42 -> V_126 , V_190 ,
& V_2 -> V_128 ) ;
}
