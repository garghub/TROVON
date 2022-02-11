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
static int F_44 ( struct V_1 * V_3 ,
struct V_81 * V_82 )
{
return 0 ;
}
static void F_45 ( struct V_10 * V_73 )
{
V_73 -> V_35 = V_83 << V_62 ;
}
static int F_46 ( struct V_1 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_10 * V_84 ;
T_1 V_55 ;
T_1 V_54 ;
T_1 V_85 ;
V_84 = V_6 -> V_86 ;
V_84 += V_6 -> V_87 ;
V_85 = V_6 -> V_12 ;
V_85 += V_6 -> V_87 * sizeof( struct V_10 ) ;
if ( ! V_3 -> V_88 ) {
F_45 ( V_84 ) ;
F_32 () ;
V_55 = ( sizeof( struct V_10 ) - 24 ) / 4 ;
V_55 |= V_85 ;
F_5 ( V_55 , V_6 -> V_18 +
F_11 ( V_6 -> V_89 . V_90 ) ) ;
V_55 = V_56 ;
if ( ! V_3 -> V_46 ) {
V_55 |= V_57 ;
V_55 |= V_58 ;
V_55 |= V_3 -> V_59 ;
}
V_55 |= V_91 ;
F_5 ( V_55 , V_3 -> V_47 ) ;
V_3 -> V_88 = 1 ;
V_3 -> V_92 = 100 ;
}
if ( ! V_3 -> V_93 || ! V_3 -> V_94 ) {
V_54 = F_10 ( V_6 , V_6 -> V_89 . V_95 ) ;
if ( ! V_54 )
V_54 = F_10 ( V_6 , V_3 -> V_59 ) ;
if ( V_54 == V_3 -> V_54 ) {
V_3 -> V_94 = 1 ;
} else if ( V_54 == V_85 ) {
T_1 V_35 ;
F_16 () ;
V_35 = V_84 -> V_35 ;
F_18 ( ( V_35 >> V_62 ) != V_83 ) ;
F_18 ( ! V_3 -> V_46 && ! ( V_35 & V_96 ) ) ;
F_18 ( ( V_35 & 0x1f ) != V_3 -> V_97 ) ;
V_3 -> V_93 = 1 ;
} else if ( V_54 ) {
F_47 ( 1 ) ;
}
}
V_3 -> V_92 -- ;
if ( ! V_3 -> V_93 && V_3 -> V_92 )
return - V_98 ;
F_18 ( ! V_3 -> V_92 ) ;
if ( ! V_3 -> V_94 ) {
V_54 = F_10 ( V_6 , V_3 -> V_29 ) ;
F_18 ( ! V_54 ) ;
}
V_3 -> V_88 = 0 ;
V_3 -> V_93 = 0 ;
V_3 -> V_94 = 0 ;
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
V_52 = F_46 ( V_3 ) ;
if ( V_52 )
return V_52 ;
F_18 ( ! V_6 -> V_13 [ V_9 ] ) ;
V_6 -> V_13 [ V_9 ] = NULL ;
return 0 ;
}
static int F_49 ( struct V_2 * V_4 , enum V_99 V_100 ,
unsigned long V_101 )
{
struct V_1 * V_3 = F_1 ( V_4 ) ;
int V_52 ;
switch ( V_100 ) {
case V_102 :
V_52 = F_44 ( V_3 , (struct V_81 * ) V_101 ) ;
break;
case V_103 :
V_52 = F_48 ( V_4 ) ;
break;
default:
V_52 = - V_104 ;
break;
}
return V_52 ;
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
int V_22 ;
int V_52 ;
T_1 V_111 ;
V_52 = F_56 ( V_110 -> V_112 , L_2 ,
& V_111 ) ;
if ( V_52 )
return V_52 ;
V_111 *= 2 ;
for ( V_22 = 0 ; V_22 < V_111 ; V_22 ++ ) {
V_107 = F_57 ( sizeof( * V_107 ) , V_113 ) ;
if ( ! V_107 )
goto V_114;
V_107 -> V_6 = V_6 ;
if ( V_22 & 1 ) {
V_107 -> V_47 = V_6 -> V_115 + F_58 ( V_22 >> 1 ) ;
V_107 -> V_46 = 1 ;
} else {
V_107 -> V_47 = V_6 -> V_115 + F_59 ( V_22 >> 1 ) ;
V_107 -> V_46 = 0 ;
}
V_107 -> V_97 = V_22 >> 1 ;
V_107 -> V_7 = & V_6 -> V_86 [ V_22 ] ;
V_107 -> V_54 = V_6 -> V_12 ;
V_107 -> V_54 += V_22 * sizeof( struct V_10 ) ;
V_107 -> V_4 . V_109 = & V_6 -> V_105 ;
F_60 ( & V_107 -> V_4 . V_108 , & V_6 -> V_105 . V_106 ) ;
}
V_6 -> V_87 = V_111 ;
return 0 ;
V_114:
F_50 ( V_6 ) ;
return - V_116 ;
}
static void F_61 ( struct V_109 * V_110 , struct V_5 * V_6 )
{
unsigned int V_117 ;
int V_22 ;
V_117 = V_11 * sizeof( struct V_10 ) ;
for ( V_22 = 0 ; V_22 < V_118 ; V_22 ++ ) {
F_5 ( 0 , V_6 -> V_18 + F_62 ( V_22 ) ) ;
F_5 ( 0 , V_6 -> V_18 + F_63 ( V_22 ) ) ;
F_64 ( V_110 , V_117 , V_6 -> V_86 ,
V_6 -> V_12 ) ;
}
}
static void F_65 ( struct V_5 * V_6 )
{
F_5 ( 0 , V_6 -> V_119 + V_120 ) ;
}
static void F_66 ( struct V_109 * V_110 , struct V_5 * V_6 )
{
F_65 ( V_6 ) ;
F_61 ( V_110 , V_6 ) ;
F_5 ( 0 , V_6 -> V_18 + V_121 ) ;
F_5 ( 0 , V_6 -> V_18 + V_121 ) ;
F_64 ( V_110 , V_122 , V_6 -> V_123 ,
V_6 -> V_124 ) ;
}
static int F_67 ( struct V_109 * V_110 , struct V_5 * V_6 )
{
unsigned int V_125 ;
unsigned int V_117 ;
int V_22 ;
T_1 V_55 ;
T_1 V_126 ;
F_68 ( sizeof( struct V_10 ) &
( sizeof( struct V_10 ) - 1 ) ) ;
F_68 ( sizeof( struct V_10 ) < 32 ) ;
F_68 ( V_11 < 32 ) ;
V_125 = sizeof( struct V_10 ) ;
V_117 = V_11 * V_125 ;
V_126 = 0 ;
for ( V_22 = 0 ; V_22 < V_118 ; V_22 ++ ) {
V_55 = V_126 << V_127 ;
V_55 |= ( F_69 ( V_125 ) - 5 ) << V_128 ;
V_55 |= F_69 ( V_11 ) - 5 ;
F_68 ( V_118 != 1 ) ;
V_6 -> V_86 = F_70 ( V_110 , V_117 ,
& V_6 -> V_12 , V_113 ) ;
if ( ! V_6 -> V_86 )
return - V_116 ;
F_5 ( V_6 -> V_12 , V_6 -> V_18 + F_62 ( V_22 ) ) ;
F_5 ( V_55 , V_6 -> V_18 + F_63 ( V_22 ) ) ;
V_126 += V_11 ;
}
return 0 ;
}
static void F_71 ( struct V_5 * V_6 )
{
unsigned V_129 ;
unsigned V_130 ;
T_1 V_55 ;
V_130 = 0 ;
F_5 ( 0 , V_6 -> V_119 + V_120 ) ;
for ( V_129 = 0 ; V_129 < 15 * 2 ; V_129 += 2 ) {
V_55 = F_72 ( V_129 ) ;
V_55 |= F_73 ( V_129 ) | V_131 ;
V_55 |= F_74 ( V_129 + 1 ) ;
V_55 |= F_75 ( V_129 + 1 ) | V_132 ;
F_5 ( V_55 , V_6 -> V_119 + F_76 ( V_130 ) ) ;
V_130 ++ ;
}
V_55 = 15 * 2 * 2 - 1 ;
V_55 |= V_133 ;
F_5 ( V_55 , V_6 -> V_119 + V_120 ) ;
}
static int F_77 ( struct V_109 * V_110 , struct V_5 * V_6 )
{
int V_52 ;
F_68 ( V_122 > ( ( 1 << 14 ) - 1 ) ) ;
V_6 -> V_123 = F_70 ( V_110 , V_122 ,
& V_6 -> V_124 , V_113 ) ;
if ( ! V_6 -> V_123 )
return - V_116 ;
F_5 ( V_6 -> V_124 , V_6 -> V_18 + V_121 ) ;
F_5 ( V_122 , V_6 -> V_18 + V_134 ) ;
F_5 ( 0 , V_6 -> V_18 + V_135 ) ;
V_52 = F_67 ( V_110 , V_6 ) ;
if ( V_52 )
goto V_136;
F_5 ( V_6 -> V_89 . V_90 , V_6 -> V_115 + V_137 ) ;
F_71 ( V_6 ) ;
return 0 ;
V_136:
F_66 ( V_110 , V_6 ) ;
return V_52 ;
}
static bool F_78 ( struct V_2 * V_4 , void * V_138 )
{
struct V_1 * V_107 ;
struct V_5 * V_6 ;
const struct V_139 * V_140 ;
T_1 * V_75 = V_138 ;
if ( V_4 -> V_109 -> V_110 -> V_141 != & V_142 . V_141 )
return false ;
V_107 = F_1 ( V_4 ) ;
if ( V_107 -> V_97 != V_75 [ V_143 ] )
return false ;
if ( V_107 -> V_46 && ! V_75 [ V_144 ] )
return false ;
V_6 = V_107 -> V_6 ;
if ( V_107 -> V_46 )
V_140 = V_6 -> V_145 ;
else
V_140 = V_6 -> V_146 ;
F_68 ( F_79 ( V_147 ) != F_79 ( V_148 ) ) ;
if ( F_18 ( V_107 -> V_97 > F_79 ( V_147 ) ) )
return false ;
V_107 -> V_29 = V_140 [ V_107 -> V_97 ] . V_90 ;
V_107 -> V_59 = V_140 [ V_107 -> V_97 ] . V_95 ;
return true ;
}
static struct V_2 * F_80 ( struct V_149 * V_150 ,
struct V_151 * V_152 )
{
int V_153 = V_150 -> V_154 ;
struct V_155 * V_156 = V_152 -> V_157 ;
if ( ! V_156 || ! V_156 -> V_158 )
return NULL ;
if ( V_153 != 2 )
return NULL ;
return F_81 ( V_156 -> V_159 , V_156 -> V_158 ,
& V_150 -> args [ 0 ] ) ;
}
static const struct V_160 * F_82 ( struct V_109 * V_110 )
{
const struct V_161 * V_162 ;
V_162 = F_83 ( V_163 , V_110 -> V_112 ) ;
if ( ! V_162 )
return NULL ;
return V_162 -> V_20 ;
}
static int F_84 ( struct V_164 * V_165 )
{
struct V_5 * V_6 ;
struct V_109 * V_110 = & V_165 -> V_110 ;
const struct V_160 * V_166 ;
int V_19 ;
int V_52 ;
V_166 = F_82 ( V_110 ) ;
if ( ! V_166 )
return - V_167 ;
V_6 = F_57 ( sizeof( * V_6 ) , V_113 ) ;
if ( ! V_6 )
return - V_116 ;
F_85 ( V_168 , V_6 -> V_105 . V_169 ) ;
V_6 -> V_105 . V_170 = F_23 ;
V_6 -> V_105 . V_171 = F_26 ;
V_6 -> V_105 . V_172 = F_27 ;
V_6 -> V_105 . V_173 = F_31 ;
V_6 -> V_105 . V_174 = F_40 ;
V_6 -> V_105 . V_175 = F_49 ;
V_6 -> V_105 . V_110 = V_110 ;
F_86 ( & V_6 -> V_105 . V_106 ) ;
V_176 . V_159 = V_6 -> V_105 . V_169 ;
V_6 -> V_23 = F_87 ( V_110 -> V_112 , 0 ) ;
V_6 -> V_115 = F_87 ( V_110 -> V_112 , 1 ) ;
V_6 -> V_119 = F_87 ( V_110 -> V_112 , 2 ) ;
V_6 -> V_18 = F_87 ( V_110 -> V_112 , 3 ) ;
if ( ! V_6 -> V_23 || ! V_6 -> V_115 || ! V_6 -> V_119 ||
! V_6 -> V_18 ) {
V_52 = - V_104 ;
goto V_177;
}
F_88 ( V_110 ) ;
V_52 = F_89 ( V_110 ) ;
if ( V_52 < 0 )
goto V_178;
V_6 -> V_146 = V_166 -> V_146 ;
V_6 -> V_145 = V_166 -> V_145 ;
V_6 -> V_89 = V_166 -> V_89 ;
V_52 = F_77 ( V_110 , V_6 ) ;
if ( V_52 )
goto V_179;
V_52 = F_55 ( V_110 , V_6 ) ;
if ( V_52 )
goto V_180;
V_19 = F_90 ( V_110 -> V_112 , 0 ) ;
if ( ! V_19 ) {
V_52 = - V_167 ;
goto V_181;
}
F_5 ( V_25 , V_6 -> V_23 + V_182 ) ;
V_52 = F_91 ( V_19 , V_166 -> V_183 , V_184 ,
F_92 ( V_110 ) , V_6 ) ;
if ( V_52 )
goto V_181;
V_6 -> V_19 = V_19 ;
V_52 = F_93 ( & V_6 -> V_105 ) ;
if ( V_52 )
goto V_185;
V_52 = F_94 ( V_110 -> V_112 ,
F_80 , & V_176 ) ;
if ( V_52 )
goto V_186;
F_95 ( V_165 , V_6 ) ;
return 0 ;
V_186:
F_96 ( & V_6 -> V_105 ) ;
V_185:
F_97 ( V_19 , V_6 ) ;
V_181:
F_5 ( 0 , V_6 -> V_23 + V_187 ) ;
F_50 ( V_6 ) ;
V_180:
F_66 ( V_110 , V_6 ) ;
V_179:
F_98 ( V_110 ) ;
V_178:
F_99 ( V_110 ) ;
F_100 ( V_6 -> V_23 ) ;
F_100 ( V_6 -> V_115 ) ;
F_100 ( V_6 -> V_119 ) ;
F_100 ( V_6 -> V_18 ) ;
V_177:
F_54 ( V_6 ) ;
return V_52 ;
}
static int F_101 ( struct V_164 * V_165 )
{
struct V_5 * V_6 = F_102 ( V_165 ) ;
F_103 ( V_165 -> V_110 . V_112 ) ;
F_96 ( & V_6 -> V_105 ) ;
F_5 ( 0 , V_6 -> V_23 + V_187 ) ;
F_97 ( V_6 -> V_19 , V_6 ) ;
F_50 ( V_6 ) ;
F_66 ( & V_165 -> V_110 , V_6 ) ;
F_100 ( V_6 -> V_23 ) ;
F_100 ( V_6 -> V_115 ) ;
F_100 ( V_6 -> V_119 ) ;
F_100 ( V_6 -> V_18 ) ;
F_98 ( & V_165 -> V_110 ) ;
F_99 ( & V_165 -> V_110 ) ;
F_54 ( V_6 ) ;
return 0 ;
}
static int F_104 ( struct V_109 * V_110 )
{
struct V_5 * V_6 = F_105 ( V_110 ) ;
V_6 -> V_188 = F_7 ( V_6 -> V_115 + V_137 ) ;
F_5 ( 0 , V_6 -> V_23 + V_187 ) ;
F_65 ( V_6 ) ;
return 0 ;
}
static int F_106 ( struct V_109 * V_110 )
{
struct V_5 * V_6 = F_105 ( V_110 ) ;
struct V_1 * V_3 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_118 ; V_22 ++ )
F_5 ( V_6 -> V_12 , V_6 -> V_18 + F_62 ( V_22 ) ) ;
F_107 (c, &cdd->ddev.channels, chan.device_node)
if ( ! V_3 -> V_46 )
F_5 ( V_3 -> V_29 , V_3 -> V_47 + V_48 ) ;
F_71 ( V_6 ) ;
F_5 ( V_6 -> V_188 , V_6 -> V_115 + V_137 ) ;
F_5 ( V_6 -> V_124 , V_6 -> V_18 + V_121 ) ;
F_5 ( V_122 , V_6 -> V_18 + V_134 ) ;
F_5 ( 0 , V_6 -> V_18 + V_135 ) ;
F_5 ( V_25 , V_6 -> V_23 + V_182 ) ;
return 0 ;
}
