static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 ,
T_1 V_6 , int V_7 )
{
return ( F_1 ( V_2 , V_3 ) & ( V_6 << V_7 ) ) >> V_7 ;
}
static void F_6 ( struct V_1 * V_2 , int V_3 , T_1 V_8 ,
T_1 V_6 , int V_7 )
{
T_1 V_9 = F_1 ( V_2 , V_3 ) ;
V_9 &= ~ ( V_6 << V_7 ) ;
V_9 |= ( V_8 & V_6 ) << V_7 ;
F_3 ( V_2 , V_3 , V_9 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = & V_2 -> V_12 -> V_11 ;
#define F_8 ( T_2 ) dev_dbg(dev, "%-35s %08x\n", #r, read_reg(vpdma, VPDMA_##r))
F_9 ( V_11 , L_1 ) ;
F_8 ( V_13 ) ;
F_8 ( V_14 ) ;
F_8 ( V_15 ) ;
F_8 ( V_16 ) ;
F_8 ( V_17 ) ;
F_8 ( V_18 ) ;
F_8 ( V_19 ) ;
F_8 ( V_20 ) ;
F_8 ( V_21 ) ;
F_8 ( V_22 ) ;
F_8 ( F_10 ( 0 ) ) ;
F_8 ( F_11 ( 0 ) ) ;
F_8 ( F_10 ( 3 ) ) ;
F_8 ( F_11 ( 3 ) ) ;
F_8 ( V_23 ) ;
F_8 ( V_24 ) ;
F_8 ( V_25 ) ;
F_8 ( V_26 ) ;
F_8 ( V_27 ) ;
F_8 ( V_28 ) ;
F_8 ( V_29 ) ;
F_8 ( V_30 ) ;
F_8 ( V_31 ) ;
F_8 ( V_32 ) ;
F_8 ( V_33 ) ;
F_8 ( V_34 ) ;
F_8 ( V_35 ) ;
F_8 ( V_36 ) ;
F_8 ( V_37 ) ;
F_8 ( V_38 ) ;
F_8 ( V_39 ) ;
}
int F_12 ( struct V_40 * V_41 , T_3 V_42 )
{
V_41 -> V_42 = V_42 ;
V_41 -> V_43 = false ;
V_41 -> V_44 = F_13 ( V_42 , V_45 ) ;
if ( ! V_41 -> V_44 )
return - V_46 ;
F_14 ( ( ( unsigned long ) V_41 -> V_44 & V_47 ) != 0 ) ;
return 0 ;
}
void F_15 ( struct V_40 * V_41 )
{
F_14 ( V_41 -> V_43 ) ;
F_16 ( V_41 -> V_44 ) ;
V_41 -> V_44 = NULL ;
V_41 -> V_42 = 0 ;
}
int F_17 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
struct V_10 * V_11 = & V_2 -> V_12 -> V_11 ;
F_14 ( V_41 -> V_43 ) ;
V_41 -> V_48 = F_18 ( V_11 , V_41 -> V_44 , V_41 -> V_42 ,
V_49 ) ;
if ( F_19 ( V_11 , V_41 -> V_48 ) ) {
F_20 ( V_11 , L_2 ) ;
return - V_50 ;
}
V_41 -> V_43 = true ;
return 0 ;
}
void F_21 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
struct V_10 * V_11 = & V_2 -> V_12 -> V_11 ;
if ( V_41 -> V_43 )
F_22 ( V_11 , V_41 -> V_48 , V_41 -> V_42 ,
V_49 ) ;
V_41 -> V_43 = false ;
}
int F_23 ( struct V_1 * V_2 , int V_51 ,
int * V_52 , int V_42 )
{
struct V_53 V_54 ;
int V_55 , V_56 , V_57 = 500 ;
F_3 ( V_2 , V_58 ,
( V_51 << V_59 ) |
( 1 << V_60 ) ) ;
if ( V_42 <= 0 || ! V_52 )
return 0 ;
V_56 = F_24 ( & V_54 ,
V_42 * sizeof( struct V_61 ) , V_62 ) ;
if ( V_56 )
return V_56 ;
for ( V_55 = 0 ; V_55 < V_42 ; V_55 ++ )
F_25 ( & V_54 , V_52 [ V_55 ] ) ;
V_56 = F_17 ( V_2 , & V_54 . V_41 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_26 ( V_2 , & V_54 , V_51 ) ;
if ( V_56 )
return V_56 ;
while ( F_27 ( V_2 , V_51 ) && -- V_57 )
;
if ( V_57 == 0 ) {
F_20 ( & V_2 -> V_12 -> V_11 , L_3 ) ;
return - V_63 ;
}
F_21 ( V_2 , & V_54 . V_41 ) ;
F_15 ( & V_54 . V_41 ) ;
return 0 ;
}
int F_24 ( struct V_53 * V_64 , T_3 V_42 , int type )
{
int T_2 ;
T_2 = F_12 ( & V_64 -> V_41 , V_42 ) ;
if ( T_2 )
return T_2 ;
V_64 -> V_65 = V_64 -> V_41 . V_44 ;
V_64 -> type = type ;
return 0 ;
}
void F_28 ( struct V_53 * V_64 )
{
V_64 -> V_65 = V_64 -> V_41 . V_44 ;
}
void F_29 ( struct V_53 * V_64 )
{
F_15 ( & V_64 -> V_41 ) ;
V_64 -> V_65 = NULL ;
}
bool F_27 ( struct V_1 * V_2 , int V_51 )
{
return F_1 ( V_2 , V_66 ) & F_30 ( V_51 + 16 ) ;
}
int F_26 ( struct V_1 * V_2 ,
struct V_53 * V_64 , int V_51 )
{
int V_67 ;
unsigned long V_68 ;
if ( F_27 ( V_2 , V_51 ) )
return - V_63 ;
V_67 = ( V_64 -> V_65 - V_64 -> V_41 . V_44 ) >> 4 ;
F_31 ( & V_2 -> V_69 , V_68 ) ;
F_3 ( V_2 , V_70 , ( T_1 ) V_64 -> V_41 . V_48 ) ;
F_3 ( V_2 , V_58 ,
( V_51 << V_59 ) |
( V_64 -> type << V_71 ) |
V_67 ) ;
F_32 ( & V_2 -> V_69 , V_68 ) ;
return 0 ;
}
void F_33 ( struct V_1 * V_2 ,
struct V_53 * V_64 , T_4 V_48 ,
void * V_72 , int V_73 , int V_74 )
{
struct V_61 * V_75 = V_64 -> V_41 . V_44 ;
T_4 V_76 ;
int V_3 ;
V_75 += V_74 ;
F_21 ( V_2 , & V_64 -> V_41 ) ;
V_75 -> V_77 = V_48 ;
V_3 = ( void * ) V_72 - V_64 -> V_41 . V_44 ;
V_76 = V_64 -> V_41 . V_48 + V_3 ;
if ( V_73 )
V_75 -> V_78 = F_34 ( V_76 ,
1 , 1 , 0 ) ;
else
V_75 -> V_78 = F_34 ( V_76 ,
1 , 0 , 0 ) ;
F_17 ( V_2 , & V_64 -> V_41 ) ;
F_35 ( V_75 ) ;
}
void F_36 ( struct V_1 * V_2 , int V_79 ,
T_1 V_80 , T_1 V_81 )
{
if ( V_79 != V_82 && V_79 != V_83 &&
V_79 != V_84 )
V_79 = V_82 ;
F_6 ( V_2 , V_79 , V_80 - 1 ,
V_85 , V_86 ) ;
F_6 ( V_2 , V_79 , V_81 - 1 ,
V_87 , V_88 ) ;
}
static void F_37 ( struct V_89 * V_90 )
{
int V_91 ;
V_91 = F_38 ( V_90 ) ;
F_39 ( L_4 ,
V_91 == V_92 ? L_5 :
L_6 ) ;
if ( V_91 == V_92 )
F_39 ( L_7 ,
V_90 -> V_93 ) ;
if ( V_91 == V_92 )
F_39 ( L_8 , V_90 -> V_94 ) ;
F_39 ( L_9 , V_90 -> V_95 ) ;
F_39 ( L_10 ,
F_40 ( V_90 ) ,
F_41 ( V_90 ) , V_91 , F_42 ( V_90 ) ,
F_43 ( V_90 ) ) ;
}
void F_44 ( struct V_53 * V_64 , int V_96 ,
struct V_40 * V_97 , T_1 V_98 )
{
struct V_89 * V_90 ;
int V_99 = V_97 -> V_42 ;
F_14 ( V_97 -> V_48 & V_47 ) ;
V_90 = V_64 -> V_65 ;
F_14 ( ( void * ) ( V_90 + 1 ) > ( V_64 -> V_41 . V_44 + V_64 -> V_41 . V_42 ) ) ;
V_90 -> V_93 = V_98 ;
V_90 -> V_94 = V_99 ;
V_90 -> V_95 = ( T_1 ) V_97 -> V_48 ;
V_90 -> V_100 = F_45 ( V_101 , V_92 ,
V_96 , V_99 >> 4 ) ;
V_64 -> V_65 = V_90 + 1 ;
F_37 ( V_90 ) ;
}
void F_46 ( struct V_53 * V_64 , int V_96 ,
struct V_40 * V_102 )
{
struct V_89 * V_90 ;
unsigned int V_99 = V_102 -> V_42 ;
F_14 ( V_99 & V_103 ) ;
F_14 ( V_102 -> V_48 & V_47 ) ;
V_90 = V_64 -> V_65 ;
F_47 ( ( void * ) ( V_90 + 1 ) > ( V_64 -> V_41 . V_44 + V_64 -> V_41 . V_42 ) ) ;
V_90 -> V_104 = 0 ;
V_90 -> V_105 = 0 ;
V_90 -> V_95 = ( T_1 ) V_102 -> V_48 ;
V_90 -> V_100 = F_45 ( V_101 , V_106 ,
V_96 , V_99 >> 4 ) ;
V_64 -> V_65 = V_90 + 1 ;
F_37 ( V_90 ) ;
}
static void F_48 ( struct V_107 * V_108 )
{
F_39 ( L_11 ) ;
F_39 ( L_12 ,
F_49 ( V_108 ) , F_50 ( V_108 ) , F_51 ( V_108 ) ) ;
}
void F_52 ( struct V_53 * V_64 ,
enum V_109 V_110 )
{
struct V_107 * V_108 ;
V_108 = V_64 -> V_65 ;
F_14 ( ( void * ) ( V_108 + 1 ) > ( V_64 -> V_41 . V_44 + V_64 -> V_41 . V_42 ) ) ;
V_108 -> V_104 = 0 ;
V_108 -> V_105 = 0 ;
V_108 -> V_111 = 0 ;
V_108 -> V_112 = F_53 ( V_113 [ V_110 ] . V_114 ,
V_115 ) ;
V_64 -> V_65 = V_108 + 1 ;
F_48 ( V_108 ) ;
}
void F_25 ( struct V_53 * V_64 ,
int V_116 )
{
struct V_107 * V_108 ;
V_108 = V_64 -> V_65 ;
F_14 ( ( void * ) ( V_108 + 1 ) > ( V_64 -> V_41 . V_44 + V_64 -> V_41 . V_42 ) ) ;
V_108 -> V_104 = 0 ;
V_108 -> V_105 = 0 ;
V_108 -> V_111 = 0 ;
V_108 -> V_112 = F_53 ( V_116 ,
V_117 ) ;
V_64 -> V_65 = V_108 + 1 ;
F_48 ( V_108 ) ;
}
static void F_35 ( struct V_61 * V_75 )
{
int V_118 , V_110 ;
V_118 = F_54 ( V_75 ) ;
V_110 = F_55 ( V_75 ) ;
F_39 ( L_13 ,
V_118 == V_119 ? L_14 : L_15 , V_110 ) ;
F_39 ( L_16 ,
F_56 ( V_75 ) , F_57 ( V_75 ) , F_58 ( V_75 ) ,
F_59 ( V_75 ) , F_60 ( V_75 ) ,
F_61 ( V_75 ) , F_62 ( V_75 ) ) ;
if ( V_118 == V_120 )
F_39 ( L_17 ,
F_63 ( V_75 ) , F_64 ( V_75 ) ) ;
F_39 ( L_18 , & V_75 -> V_77 ) ;
F_39 ( L_19 ,
F_65 ( V_75 ) ,
F_66 ( V_75 ) , V_118 , V_110 , F_67 ( V_75 ) ,
F_68 ( V_75 ) ) ;
if ( V_118 == V_120 )
F_39 ( L_20 ,
F_69 ( V_75 ) , F_70 ( V_75 ) ) ;
else
F_39 ( L_21 ,
F_71 ( V_75 ) , F_72 ( V_75 ) ,
F_73 ( V_75 ) , F_74 ( V_75 ) ) ;
if ( V_118 == V_120 )
F_39 ( L_22 ,
F_75 ( V_75 ) , F_76 ( V_75 ) ) ;
else
F_39 ( L_23 ,
F_77 ( V_75 ) , F_78 ( V_75 ) ) ;
F_39 ( L_24 , V_75 -> V_121 ) ;
F_39 ( L_25 , V_75 -> V_122 ) ;
}
void F_79 ( struct V_53 * V_64 , int V_80 ,
const struct V_123 * V_124 ,
const struct V_125 * V_126 , T_4 V_48 ,
int V_127 , int V_128 , enum V_109 V_110 , T_1 V_68 )
{
F_80 ( V_64 , V_80 , V_124 , V_126 , V_48 ,
V_127 , V_128 , V_113 [ V_110 ] . V_114 , V_68 ) ;
}
void F_80 ( struct V_53 * V_64 , int V_80 ,
const struct V_123 * V_124 ,
const struct V_125 * V_126 , T_4 V_48 ,
int V_127 , int V_128 , int V_129 , T_1 V_68 )
{
int V_130 = 0 ;
int V_8 = 0 ;
int V_131 = 1 ;
int V_132 , V_133 ;
struct V_123 V_134 = * V_124 ;
int V_135 = V_126 -> V_135 ;
int V_136 ;
struct V_61 * V_75 ;
V_132 = V_133 = V_129 ;
if ( V_126 -> type == V_137 &&
V_126 -> V_138 == V_139 ) {
V_134 . V_81 >>= 1 ;
V_134 . V_140 >>= 1 ;
V_135 = 8 ;
}
V_136 = F_81 ( ( V_135 * V_80 ) >> 3 , V_141 ) ;
V_48 += V_134 . V_140 * V_136 + ( V_134 . V_142 * V_135 >> 3 ) ;
V_75 = V_64 -> V_65 ;
F_14 ( ( void * ) ( V_75 + 1 ) > ( V_64 -> V_41 . V_44 + V_64 -> V_41 . V_42 ) ) ;
V_75 -> V_143 = F_82 ( V_126 -> V_138 ,
V_131 ,
V_8 ,
! ! ( V_68 & V_144 ) ,
! ! ( V_68 & V_145 ) ,
! ! ( V_68 & V_146 ) ,
V_136 ) ;
V_75 -> V_105 = 0 ;
V_75 -> V_77 = ( T_1 ) V_48 ;
V_75 -> V_147 = F_83 ( ! ! ( V_68 & V_148 ) ,
V_119 , V_132 , V_130 , V_133 ) ;
V_75 -> V_78 = F_34 ( 0 , 0 , 0 , 0 ) ;
V_75 -> V_149 = F_84 ( V_127 , V_128 ) ;
V_75 -> V_121 = 0 ;
V_75 -> V_122 = 0 ;
V_64 -> V_65 = V_75 + 1 ;
F_35 ( V_75 ) ;
}
void F_85 ( struct V_53 * V_64 , int V_80 ,
const struct V_123 * V_124 ,
const struct V_125 * V_126 , T_4 V_48 ,
enum V_109 V_110 , int V_8 , T_1 V_68 , int V_150 ,
int V_151 , int V_152 , int V_153 )
{
int V_130 = 0 ;
int V_131 = 1 ;
int V_135 = V_126 -> V_135 ;
int V_132 , V_133 ;
struct V_123 V_134 = * V_124 ;
int V_136 ;
struct V_61 * V_75 ;
V_132 = V_133 = V_113 [ V_110 ] . V_114 ;
if ( V_126 -> type == V_137 &&
V_126 -> V_138 == V_139 ) {
V_134 . V_81 >>= 1 ;
V_134 . V_140 >>= 1 ;
V_135 = 8 ;
}
V_136 = F_81 ( ( V_135 * V_80 ) >> 3 , V_141 ) ;
V_48 += V_134 . V_140 * V_136 + ( V_134 . V_142 * V_135 >> 3 ) ;
V_75 = V_64 -> V_65 ;
F_14 ( ( void * ) ( V_75 + 1 ) > ( V_64 -> V_41 . V_44 + V_64 -> V_41 . V_42 ) ) ;
V_75 -> V_143 = F_82 ( V_126 -> V_138 ,
V_131 ,
V_8 ,
! ! ( V_68 & V_144 ) ,
! ! ( V_68 & V_145 ) ,
! ! ( V_68 & V_146 ) ,
V_136 ) ;
V_75 -> V_154 = F_86 ( V_134 . V_80 ,
V_134 . V_81 ) ;
V_75 -> V_77 = ( T_1 ) V_48 ;
V_75 -> V_147 = F_83 ( ! ! ( V_68 & V_148 ) ,
V_120 , V_132 , V_130 , V_133 ) ;
V_75 -> V_155 = F_87 ( V_150 ,
V_151 ) ;
V_75 -> V_156 = F_88 ( V_152 , V_153 ) ;
V_75 -> V_121 = 0 ;
V_75 -> V_122 = 0 ;
V_64 -> V_65 = V_75 + 1 ;
F_35 ( V_75 ) ;
}
int F_89 ( struct V_1 * V_2 , void * V_157 )
{
int V_55 , V_51 = - 1 ;
unsigned long V_68 ;
F_31 ( & V_2 -> V_69 , V_68 ) ;
for ( V_55 = 0 ; V_55 < V_158 &&
V_2 -> V_159 [ V_55 ] == true ; V_55 ++ )
;
if ( V_55 < V_158 ) {
V_51 = V_55 ;
V_2 -> V_159 [ V_55 ] = true ;
V_2 -> V_160 [ V_55 ] = V_157 ;
}
F_32 ( & V_2 -> V_69 , V_68 ) ;
return V_51 ;
}
void * F_90 ( struct V_1 * V_2 , int V_51 )
{
if ( ! V_2 || V_51 >= V_158 )
return NULL ;
return V_2 -> V_160 [ V_51 ] ;
}
void * F_91 ( struct V_1 * V_2 , int V_51 )
{
void * V_157 ;
unsigned long V_68 ;
F_31 ( & V_2 -> V_69 , V_68 ) ;
V_2 -> V_159 [ V_51 ] = false ;
V_157 = V_2 -> V_160 ;
F_32 ( & V_2 -> V_69 , V_68 ) ;
return V_157 ;
}
void F_92 ( struct V_1 * V_2 , int V_161 ,
int V_51 , bool V_162 )
{
T_1 V_79 = V_163 + V_164 * V_161 ;
T_1 V_9 ;
V_9 = F_1 ( V_2 , V_79 ) ;
if ( V_162 )
V_9 |= ( 1 << ( V_51 * 2 ) ) ;
else
V_9 &= ~ ( 1 << ( V_51 * 2 ) ) ;
F_3 ( V_2 , V_79 , V_9 ) ;
}
unsigned int F_93 ( struct V_1 * V_2 , int V_161 )
{
T_1 V_79 = V_165 + V_164 * V_161 ;
return F_1 ( V_2 , V_79 ) ;
}
unsigned int F_94 ( struct V_1 * V_2 , int V_161 )
{
T_1 V_79 = V_163 + V_164 * V_161 ;
return F_1 ( V_2 , V_79 ) ;
}
void F_95 ( struct V_1 * V_2 , int V_161 ,
int V_51 )
{
T_1 V_79 = V_165 + V_164 * V_161 ;
F_3 ( V_2 , V_79 , 3 << ( V_51 * 2 ) ) ;
}
void F_96 ( struct V_1 * V_2 ,
struct V_125 * V_126 , T_1 V_166 )
{
if ( V_126 -> type == V_167 )
F_3 ( V_2 , V_168 , V_166 ) ;
else if ( V_126 -> type == V_137 )
F_3 ( V_2 , V_169 , V_166 ) ;
}
void F_97 ( struct V_1 * V_2 , int V_170 ,
enum V_109 V_110 )
{
int V_171 = V_113 [ V_110 ] . V_172 ;
F_6 ( V_2 , V_171 , V_170 ,
V_173 , V_174 ) ;
}
void F_98 ( struct V_1 * V_2 ,
enum V_175 V_176 ,
enum V_109 V_110 )
{
int V_171 = V_113 [ V_110 ] . V_172 ;
F_6 ( V_2 , V_171 , V_176 ,
V_177 , V_178 ) ;
}
static void F_99 ( const struct V_179 * V_180 , void * V_181 )
{
struct V_1 * V_2 = V_181 ;
struct V_40 V_182 ;
int V_55 , T_2 ;
F_9 ( & V_2 -> V_12 -> V_11 , L_26 ) ;
if ( ! V_180 || ! V_180 -> V_183 ) {
F_20 ( & V_2 -> V_12 -> V_11 , L_27 ) ;
return;
}
if ( F_5 ( V_2 , V_58 , V_184 ,
V_185 ) ) {
V_2 -> V_186 ( V_2 -> V_12 ) ;
return;
}
T_2 = F_12 ( & V_182 , V_180 -> V_42 ) ;
if ( T_2 ) {
F_20 ( & V_2 -> V_12 -> V_11 ,
L_28 ) ;
goto V_187;
}
memcpy ( V_182 . V_44 , V_180 -> V_183 , V_180 -> V_42 ) ;
F_17 ( V_2 , & V_182 ) ;
F_3 ( V_2 , V_70 , ( T_1 ) V_182 . V_48 ) ;
for ( V_55 = 0 ; V_55 < 100 ; V_55 ++ ) {
F_100 ( 10 ) ;
if ( F_5 ( V_2 , V_58 , V_184 ,
V_185 ) )
break;
}
if ( V_55 == 100 ) {
F_20 ( & V_2 -> V_12 -> V_11 , L_29 ) ;
goto V_188;
}
V_2 -> V_186 ( V_2 -> V_12 ) ;
V_188:
F_21 ( V_2 , & V_182 ) ;
F_15 ( & V_182 ) ;
V_187:
F_101 ( V_180 ) ;
}
static int F_102 ( struct V_1 * V_2 )
{
int T_2 ;
struct V_10 * V_11 = & V_2 -> V_12 -> V_11 ;
T_2 = F_103 ( V_189 , 1 ,
( const char * ) V_190 , V_11 , V_45 , V_2 ,
F_99 ) ;
if ( T_2 ) {
F_20 ( V_11 , L_30 , V_190 ) ;
return T_2 ;
} else {
F_104 ( V_11 , L_31 , V_190 ) ;
}
return 0 ;
}
int F_105 ( struct V_191 * V_12 , struct V_1 * V_2 ,
void (* V_186)( struct V_191 * V_12 ) )
{
struct V_192 * V_193 ;
int T_2 ;
F_9 ( & V_12 -> V_11 , L_32 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_186 = V_186 ;
F_106 ( & V_2 -> V_69 ) ;
V_193 = F_107 ( V_12 , V_194 , L_33 ) ;
if ( V_193 == NULL ) {
F_20 ( & V_12 -> V_11 , L_34 ) ;
return - V_195 ;
}
V_2 -> V_4 = F_108 ( & V_12 -> V_11 , V_193 -> V_196 , F_109 ( V_193 ) ) ;
if ( ! V_2 -> V_4 ) {
F_20 ( & V_12 -> V_11 , L_35 ) ;
return - V_46 ;
}
T_2 = F_102 ( V_2 ) ;
if ( T_2 ) {
F_110 ( L_36 , V_190 ) ;
return T_2 ;
}
return 0 ;
}
