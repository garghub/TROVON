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
static T_3 F_10 ( int V_17 , void * V_18 )
{
struct V_5 * V_6 = V_18 ;
struct V_1 * V_3 ;
T_1 V_19 ;
int V_20 ;
V_19 = F_7 ( V_6 -> V_21 + V_22 ) ;
if ( ! ( V_19 & V_23 ) )
return V_24 ;
F_5 ( V_19 , V_6 -> V_21 + V_22 ) ;
for ( V_20 = F_11 ( V_25 ) ; V_20 < V_26 ;
V_20 ++ ) {
T_1 V_14 ;
T_1 V_27 ;
V_14 = F_7 ( V_6 -> V_28 + F_12 ( V_20 ) ) ;
if ( V_20 == F_11 ( V_25 ) && V_14 ) {
T_1 V_29 ;
V_29 = 1 << F_13 ( V_25 ) ;
V_29 -- ;
V_14 &= ~ V_29 ;
}
if ( V_14 )
F_14 () ;
while ( V_14 ) {
T_1 V_7 ;
V_27 = F_15 ( V_14 ) ;
V_14 &= ~ ( 1 << V_27 ) ;
V_27 += 32 * V_20 ;
V_7 = F_7 ( V_6 -> V_28 + F_16 ( V_27 ) ) ;
V_7 &= ~ 0x1f ;
V_3 = F_3 ( V_6 , V_7 ) ;
if ( F_17 ( ! V_3 ) ) {
F_18 ( L_1 , V_30 ,
V_27 , V_7 ) ;
continue;
}
V_3 -> V_31 = F_9 ( V_3 -> V_7 -> V_32 ) -
F_9 ( V_3 -> V_7 -> V_33 ) ;
F_19 ( & V_3 -> V_34 ) ;
V_3 -> V_34 . V_35 ( V_3 -> V_34 . V_36 ) ;
}
}
return V_37 ;
}
static T_4 F_20 ( struct V_38 * V_39 )
{
T_4 V_40 ;
V_40 = F_21 ( V_39 ) ;
return V_40 ;
}
static int F_22 ( struct V_2 * V_4 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
F_23 ( V_4 ) ;
F_24 ( & V_3 -> V_34 , V_4 ) ;
V_3 -> V_34 . V_41 = F_20 ;
if ( ! V_3 -> V_42 )
F_5 ( V_3 -> V_27 , V_3 -> V_43 + V_44 ) ;
return 0 ;
}
static void F_25 ( struct V_2 * V_4 )
{
}
static enum V_45 F_26 ( struct V_2 * V_4 ,
T_4 V_40 , struct V_46 * V_47 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
enum V_45 V_48 ;
V_48 = F_27 ( V_4 , V_40 , V_47 ) ;
if ( V_47 && V_48 == V_49 )
V_47 -> V_31 = V_3 -> V_31 ;
return V_48 ;
}
static void F_28 ( struct V_1 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
T_1 V_9 ;
T_1 V_50 ;
T_1 V_51 ;
V_50 = F_29 ( V_3 -> V_50 ) ;
V_9 = ( V_50 - V_6 -> V_12 ) / sizeof( struct V_10 ) ;
F_17 ( V_6 -> V_13 [ V_9 ] ) ;
V_6 -> V_13 [ V_9 ] = V_3 ;
V_51 = ( sizeof( struct V_10 ) - 24 ) / 4 ;
V_51 |= V_50 ;
F_5 ( V_51 , V_6 -> V_28 + F_16 ( V_3 -> V_27 ) ) ;
}
static void F_30 ( struct V_2 * V_4 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
T_1 V_51 ;
V_3 -> V_31 = 0 ;
V_51 = V_52 ;
if ( ! V_3 -> V_42 ) {
V_51 |= V_53 ;
V_51 |= V_54 ;
V_51 |= V_3 -> V_55 ;
}
F_5 ( V_51 , V_3 -> V_43 ) ;
F_31 () ;
F_28 ( V_3 ) ;
}
static T_1 F_32 ( T_1 V_56 )
{
T_1 V_51 ;
V_51 = V_57 << V_58 ;
V_51 |= V_56 ;
return V_51 ;
}
static T_1 F_33 ( struct V_1 * V_3 )
{
T_1 V_51 ;
V_51 = 0 ;
return V_51 ;
}
static T_1 F_34 ( struct V_1 * V_3 )
{
T_1 V_51 ;
V_51 = V_59 ;
V_51 |= V_3 -> V_55 ;
return V_51 ;
}
static T_1 F_35 ( T_1 V_56 )
{
T_1 V_51 ;
V_51 = V_56 ;
return V_51 ;
}
static T_1 F_36 ( T_1 V_56 )
{
T_1 V_51 ;
V_51 = V_60 ;
V_51 |= V_56 ;
return V_51 ;
}
static T_1 F_37 ( T_1 V_61 )
{
T_1 V_51 ;
V_51 = V_61 ;
return V_51 ;
}
static T_1 F_38 ( void )
{
T_1 V_51 ;
V_51 = 0 ;
return V_51 ;
}
static struct V_38 * F_39 (
struct V_2 * V_4 , struct V_62 * V_63 , unsigned V_64 ,
enum V_65 V_66 , unsigned long V_67 , void * V_68 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_10 * V_69 ;
struct V_62 * V_70 ;
unsigned int V_20 ;
unsigned int V_71 ;
V_71 = 0 ;
V_69 = V_3 -> V_7 ;
F_40 (sgl, sg, sg_len, i) {
T_1 V_61 ;
T_1 V_72 ;
F_4 ( V_71 > 0 ) ;
V_61 = F_29 ( F_41 ( V_70 ) ) ;
V_72 = F_42 ( V_70 ) ;
V_69 -> V_33 = F_32 ( V_72 ) ;
V_69 -> V_73 = F_33 ( V_3 ) ;
V_69 -> V_74 = F_34 ( V_3 ) ;
V_69 -> V_75 = F_35 ( V_72 ) ;
V_69 -> V_76 = F_37 ( V_61 ) ;
V_69 -> V_77 = F_38 () ;
V_69 -> V_32 = F_36 ( V_72 ) ;
V_69 -> V_78 = F_37 ( V_61 ) ;
V_69 ++ ;
}
return & V_3 -> V_34 ;
}
static int F_43 ( struct V_1 * V_3 ,
struct V_79 * V_80 )
{
return 0 ;
}
static void F_44 ( struct V_10 * V_69 )
{
V_69 -> V_33 = V_81 << V_58 ;
}
static T_1 F_45 ( struct V_5 * V_6 , unsigned V_82 )
{
T_1 V_7 ;
V_7 = F_7 ( V_6 -> V_28 + F_16 ( V_82 ) ) ;
V_7 &= ~ 0x1f ;
return V_7 ;
}
static int F_46 ( struct V_1 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_10 * V_83 ;
T_1 V_51 ;
T_1 V_50 ;
T_1 V_84 ;
V_83 = V_6 -> V_85 ;
V_83 += V_6 -> V_86 ;
V_84 = V_6 -> V_12 ;
V_84 += V_6 -> V_86 * sizeof( struct V_10 ) ;
if ( ! V_3 -> V_87 ) {
F_44 ( V_83 ) ;
F_31 () ;
V_51 = ( sizeof( struct V_10 ) - 24 ) / 4 ;
V_51 |= V_84 ;
F_5 ( V_51 , V_6 -> V_28 +
F_16 ( V_6 -> V_88 . V_89 ) ) ;
V_51 = V_52 ;
if ( ! V_3 -> V_42 ) {
V_51 |= V_53 ;
V_51 |= V_54 ;
V_51 |= V_3 -> V_55 ;
}
V_51 |= V_90 ;
F_5 ( V_51 , V_3 -> V_43 ) ;
V_3 -> V_87 = 1 ;
V_3 -> V_91 = 100 ;
}
if ( ! V_3 -> V_92 ) {
unsigned V_93 ;
if ( V_3 -> V_42 )
V_93 = V_6 -> V_88 . V_94 ;
else
V_93 = V_3 -> V_55 ;
V_50 = F_45 ( V_6 , V_93 ) ;
if ( V_50 ) {
F_14 () ;
if ( V_50 == V_84 ) {
T_1 V_33 ;
V_33 = V_83 -> V_33 ;
F_17 ( ( V_33 >> V_58 ) != V_81 ) ;
F_17 ( ! V_3 -> V_42 && ! ( V_33 & V_95 ) ) ;
F_17 ( ( V_33 & 0x1f ) != V_3 -> V_96 ) ;
} else {
F_47 ( 1 ) ;
}
V_3 -> V_92 = 1 ;
}
}
if ( ! V_3 -> V_97 ) {
V_50 = F_45 ( V_6 , V_3 -> V_55 ) ;
if ( V_50 ) {
F_14 () ;
F_17 ( V_3 -> V_50 != V_50 ) ;
V_3 -> V_97 = 1 ;
}
}
V_3 -> V_91 -- ;
if ( ! V_3 -> V_92 && V_3 -> V_91 )
return - V_98 ;
F_17 ( ! V_3 -> V_91 ) ;
if ( ! V_3 -> V_97 ) {
V_50 = F_7 ( V_6 -> V_28 + F_16 ( V_3 -> V_27 ) ) ;
F_17 ( ! V_50 ) ;
}
V_3 -> V_87 = 0 ;
V_3 -> V_92 = 0 ;
V_3 -> V_97 = 0 ;
F_5 ( 0 , V_3 -> V_43 ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_4 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_3 -> V_6 ;
T_1 V_9 ;
T_1 V_50 ;
int V_48 ;
V_48 = F_46 ( V_3 ) ;
if ( V_48 )
return V_48 ;
V_50 = F_29 ( V_3 -> V_50 ) ;
V_9 = ( V_50 - V_6 -> V_12 ) / sizeof( struct V_10 ) ;
F_17 ( ! V_6 -> V_13 [ V_9 ] ) ;
V_6 -> V_13 [ V_9 ] = NULL ;
return 0 ;
}
static int F_49 ( struct V_2 * V_4 , enum V_99 V_100 ,
unsigned long V_101 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
int V_48 ;
switch ( V_100 ) {
case V_102 :
V_48 = F_43 ( V_3 , (struct V_79 * ) V_101 ) ;
break;
case V_103 :
V_48 = F_48 ( V_4 ) ;
break;
default:
V_48 = - V_104 ;
break;
}
return V_48 ;
}
static void F_50 ( struct V_5 * V_6 )
{
while ( ! F_51 ( & V_6 -> V_105 . V_106 ) ) {
struct V_1 * V_107 ;
V_107 = F_52 ( & V_6 -> V_105 . V_106 ,
struct V_1 , V_4 . V_108 ) ;
F_53 ( & V_107 -> V_4 . V_108 ) ;
F_54 ( V_107 ) ;
}
}
static int F_55 ( struct V_109 * V_110 , struct V_5 * V_6 )
{
struct V_1 * V_107 ;
int V_20 ;
int V_48 ;
T_1 V_111 ;
V_48 = F_56 ( V_110 -> V_112 . V_113 , L_2 ,
& V_111 ) ;
if ( V_48 )
return V_48 ;
V_111 *= 2 ;
for ( V_20 = 0 ; V_20 < V_111 ; V_20 ++ ) {
V_107 = F_57 ( sizeof( * V_107 ) , V_114 ) ;
if ( ! V_107 )
goto V_115;
V_107 -> V_6 = V_6 ;
if ( V_20 & 1 ) {
V_107 -> V_43 = V_6 -> V_116 + F_58 ( V_20 >> 1 ) ;
V_107 -> V_42 = 1 ;
} else {
V_107 -> V_43 = V_6 -> V_116 + F_59 ( V_20 >> 1 ) ;
V_107 -> V_42 = 0 ;
}
V_107 -> V_96 = V_20 >> 1 ;
V_107 -> V_7 = & V_6 -> V_85 [ V_20 ] ;
V_107 -> V_50 = V_6 -> V_12 ;
V_107 -> V_50 += V_20 * sizeof( struct V_10 ) ;
V_107 -> V_4 . V_117 = & V_6 -> V_105 ;
F_60 ( & V_107 -> V_4 . V_108 , & V_6 -> V_105 . V_106 ) ;
}
V_6 -> V_86 = V_111 ;
return 0 ;
V_115:
F_50 ( V_6 ) ;
return - V_118 ;
}
static void F_61 ( struct V_109 * V_110 , struct V_5 * V_6 )
{
unsigned int V_119 ;
int V_20 ;
V_119 = V_11 * sizeof( struct V_10 ) ;
for ( V_20 = 0 ; V_20 < V_120 ; V_20 ++ ) {
F_5 ( 0 , V_6 -> V_28 + F_62 ( V_20 ) ) ;
F_5 ( 0 , V_6 -> V_28 + F_63 ( V_20 ) ) ;
F_64 ( & V_110 -> V_112 , V_119 , V_6 -> V_85 ,
V_6 -> V_12 ) ;
}
}
static void F_65 ( struct V_5 * V_6 )
{
F_5 ( 0 , V_6 -> V_121 + V_122 ) ;
}
static void F_66 ( struct V_109 * V_110 , struct V_5 * V_6 )
{
F_65 ( V_6 ) ;
F_61 ( V_110 , V_6 ) ;
F_5 ( 0 , V_6 -> V_28 + V_123 ) ;
F_5 ( 0 , V_6 -> V_28 + V_123 ) ;
F_64 ( & V_110 -> V_112 , V_124 , V_6 -> V_125 ,
V_6 -> V_126 ) ;
}
static int F_67 ( struct V_109 * V_110 , struct V_5 * V_6 )
{
unsigned int V_127 ;
unsigned int V_119 ;
int V_20 ;
T_1 V_51 ;
T_1 V_128 ;
F_68 ( sizeof( struct V_10 ) &
( sizeof( struct V_10 ) - 1 ) ) ;
F_68 ( sizeof( struct V_10 ) < 32 ) ;
F_68 ( V_11 < 32 ) ;
V_127 = sizeof( struct V_10 ) ;
V_119 = V_11 * V_127 ;
V_128 = 0 ;
for ( V_20 = 0 ; V_20 < V_120 ; V_20 ++ ) {
V_51 = V_128 << V_129 ;
V_51 |= ( F_69 ( V_127 ) - 5 ) << V_130 ;
V_51 |= F_69 ( V_11 ) - 5 ;
F_68 ( V_120 != 1 ) ;
V_6 -> V_85 = F_70 ( & V_110 -> V_112 , V_119 ,
& V_6 -> V_12 , V_114 ) ;
if ( ! V_6 -> V_85 )
return - V_118 ;
F_5 ( V_6 -> V_12 , V_6 -> V_28 + F_62 ( V_20 ) ) ;
F_5 ( V_51 , V_6 -> V_28 + F_63 ( V_20 ) ) ;
V_128 += V_11 ;
}
return 0 ;
}
static void F_71 ( struct V_5 * V_6 )
{
unsigned V_131 ;
unsigned V_132 ;
T_1 V_51 ;
V_132 = 0 ;
F_5 ( 0 , V_6 -> V_121 + V_122 ) ;
for ( V_131 = 0 ; V_131 < 15 * 2 ; V_131 += 2 ) {
V_51 = F_72 ( V_131 ) ;
V_51 |= F_73 ( V_131 ) | V_133 ;
V_51 |= F_74 ( V_131 + 1 ) ;
V_51 |= F_75 ( V_131 + 1 ) | V_134 ;
F_5 ( V_51 , V_6 -> V_121 + F_76 ( V_132 ) ) ;
V_132 ++ ;
}
V_51 = 15 * 2 * 2 - 1 ;
V_51 |= V_135 ;
F_5 ( V_51 , V_6 -> V_121 + V_122 ) ;
}
static int F_77 ( struct V_109 * V_110 , struct V_5 * V_6 )
{
int V_48 ;
F_68 ( V_124 > ( ( 1 << 14 ) - 1 ) ) ;
V_6 -> V_125 = F_70 ( & V_110 -> V_112 , V_124 ,
& V_6 -> V_126 , V_114 ) ;
if ( ! V_6 -> V_125 )
return - V_118 ;
F_5 ( V_6 -> V_126 , V_6 -> V_28 + V_123 ) ;
F_5 ( V_124 , V_6 -> V_28 + V_136 ) ;
F_5 ( 0 , V_6 -> V_28 + V_137 ) ;
V_48 = F_67 ( V_110 , V_6 ) ;
if ( V_48 )
goto V_138;
F_5 ( V_6 -> V_88 . V_89 , V_6 -> V_116 + V_139 ) ;
F_71 ( V_6 ) ;
return 0 ;
V_138:
F_66 ( V_110 , V_6 ) ;
return V_48 ;
}
static bool F_78 ( struct V_2 * V_4 , void * V_140 )
{
struct V_1 * V_107 ;
struct V_5 * V_6 ;
const struct V_141 * V_142 ;
T_1 * V_71 = V_140 ;
if ( V_4 -> V_117 -> V_112 -> V_143 != & V_144 . V_143 )
return false ;
V_107 = F_1 ( V_4 ) ;
if ( V_107 -> V_96 != V_71 [ V_145 ] )
return false ;
if ( V_107 -> V_42 && ! V_71 [ V_146 ] )
return false ;
V_6 = V_107 -> V_6 ;
if ( V_107 -> V_42 )
V_142 = V_6 -> V_147 ;
else
V_142 = V_6 -> V_148 ;
F_68 ( F_79 ( V_149 ) != F_79 ( V_150 ) ) ;
if ( F_17 ( V_107 -> V_96 > F_79 ( V_149 ) ) )
return false ;
V_107 -> V_27 = V_142 [ V_107 -> V_96 ] . V_89 ;
V_107 -> V_55 = V_142 [ V_107 -> V_96 ] . V_94 ;
return true ;
}
static struct V_2 * F_80 ( struct V_151 * V_152 ,
struct V_153 * V_154 )
{
int V_155 = V_152 -> V_156 ;
struct V_157 * V_158 = V_154 -> V_159 ;
if ( ! V_158 || ! V_158 -> V_160 )
return NULL ;
if ( V_155 != 2 )
return NULL ;
return F_81 ( V_158 -> V_161 , V_158 -> V_160 ,
& V_152 -> args [ 0 ] ) ;
}
static const struct V_162 * F_82 ( struct V_109 * V_110 )
{
const struct V_163 * V_164 ;
V_164 = F_83 ( V_165 , V_110 -> V_112 . V_113 ) ;
if ( ! V_164 )
return NULL ;
return V_164 -> V_18 ;
}
static int F_84 ( struct V_109 * V_110 )
{
struct V_5 * V_6 ;
const struct V_162 * V_166 ;
int V_17 ;
int V_48 ;
V_166 = F_82 ( V_110 ) ;
if ( ! V_166 )
return - V_167 ;
V_6 = F_57 ( sizeof( * V_6 ) , V_114 ) ;
if ( ! V_6 )
return - V_118 ;
F_85 ( V_168 , V_6 -> V_105 . V_169 ) ;
V_6 -> V_105 . V_170 = F_22 ;
V_6 -> V_105 . V_171 = F_25 ;
V_6 -> V_105 . V_172 = F_26 ;
V_6 -> V_105 . V_173 = F_30 ;
V_6 -> V_105 . V_174 = F_39 ;
V_6 -> V_105 . V_175 = F_49 ;
V_6 -> V_105 . V_112 = & V_110 -> V_112 ;
F_86 ( & V_6 -> V_105 . V_106 ) ;
V_176 . V_161 = V_6 -> V_105 . V_169 ;
V_6 -> V_21 = F_87 ( V_110 -> V_112 . V_113 , 0 ) ;
V_6 -> V_116 = F_87 ( V_110 -> V_112 . V_113 , 1 ) ;
V_6 -> V_121 = F_87 ( V_110 -> V_112 . V_113 , 2 ) ;
V_6 -> V_28 = F_87 ( V_110 -> V_112 . V_113 , 3 ) ;
if ( ! V_6 -> V_21 || ! V_6 -> V_116 || ! V_6 -> V_121 ||
! V_6 -> V_28 ) {
V_48 = - V_104 ;
goto V_177;
}
F_88 ( & V_110 -> V_112 ) ;
V_48 = F_89 ( & V_110 -> V_112 ) ;
if ( V_48 )
goto V_178;
V_6 -> V_148 = V_166 -> V_148 ;
V_6 -> V_147 = V_166 -> V_147 ;
V_6 -> V_88 = V_166 -> V_88 ;
V_48 = F_77 ( V_110 , V_6 ) ;
if ( V_48 )
goto V_179;
V_48 = F_55 ( V_110 , V_6 ) ;
if ( V_48 )
goto V_180;
V_17 = F_90 ( V_110 -> V_112 . V_113 , 0 ) ;
if ( ! V_17 )
goto V_181;
F_5 ( V_23 , V_6 -> V_21 + V_182 ) ;
V_48 = F_91 ( V_17 , V_166 -> V_183 , V_184 ,
F_92 ( & V_110 -> V_112 ) , V_6 ) ;
if ( V_48 )
goto V_181;
V_6 -> V_17 = V_17 ;
V_48 = F_93 ( & V_6 -> V_105 ) ;
if ( V_48 )
goto V_185;
V_48 = F_94 ( V_110 -> V_112 . V_113 ,
F_80 , & V_176 ) ;
if ( V_48 )
goto V_186;
F_95 ( V_110 , V_6 ) ;
return 0 ;
V_186:
F_96 ( & V_6 -> V_105 ) ;
V_185:
F_97 ( V_17 , V_6 ) ;
V_181:
F_5 ( 0 , V_6 -> V_21 + V_187 ) ;
F_50 ( V_6 ) ;
V_180:
F_66 ( V_110 , V_6 ) ;
V_179:
F_98 ( & V_110 -> V_112 ) ;
V_178:
F_99 ( & V_110 -> V_112 ) ;
F_100 ( V_6 -> V_21 ) ;
F_100 ( V_6 -> V_116 ) ;
F_100 ( V_6 -> V_121 ) ;
F_100 ( V_6 -> V_28 ) ;
V_177:
F_54 ( V_6 ) ;
return V_48 ;
}
static int F_101 ( struct V_109 * V_110 )
{
struct V_5 * V_6 = F_102 ( V_110 ) ;
F_103 ( V_110 -> V_112 . V_113 ) ;
F_96 ( & V_6 -> V_105 ) ;
F_5 ( 0 , V_6 -> V_21 + V_187 ) ;
F_97 ( V_6 -> V_17 , V_6 ) ;
F_50 ( V_6 ) ;
F_66 ( V_110 , V_6 ) ;
F_100 ( V_6 -> V_21 ) ;
F_100 ( V_6 -> V_116 ) ;
F_100 ( V_6 -> V_121 ) ;
F_100 ( V_6 -> V_28 ) ;
F_98 ( & V_110 -> V_112 ) ;
F_99 ( & V_110 -> V_112 ) ;
F_54 ( V_6 ) ;
return 0 ;
}
