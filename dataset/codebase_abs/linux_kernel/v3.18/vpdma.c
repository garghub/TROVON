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
F_22 ( V_11 , V_41 -> V_48 , V_41 -> V_42 , V_49 ) ;
V_41 -> V_43 = false ;
}
int F_23 ( struct V_51 * V_52 , T_3 V_42 , int type )
{
int T_2 ;
T_2 = F_12 ( & V_52 -> V_41 , V_42 ) ;
if ( T_2 )
return T_2 ;
V_52 -> V_53 = V_52 -> V_41 . V_44 ;
V_52 -> type = type ;
return 0 ;
}
void F_24 ( struct V_51 * V_52 )
{
V_52 -> V_53 = V_52 -> V_41 . V_44 ;
}
void F_25 ( struct V_51 * V_52 )
{
F_15 ( & V_52 -> V_41 ) ;
V_52 -> V_53 = NULL ;
}
static bool F_26 ( struct V_1 * V_2 , int V_54 )
{
return F_1 ( V_2 , V_55 ) & F_27 ( V_54 + 16 ) ;
}
int F_28 ( struct V_1 * V_2 , struct V_51 * V_52 )
{
int V_54 = 0 ;
int V_56 ;
if ( F_26 ( V_2 , V_54 ) )
return - V_57 ;
V_56 = ( V_52 -> V_53 - V_52 -> V_41 . V_44 ) >> 4 ;
F_3 ( V_2 , V_58 , ( T_1 ) V_52 -> V_41 . V_48 ) ;
F_3 ( V_2 , V_59 ,
( V_54 << V_60 ) |
( V_52 -> type << V_61 ) |
V_56 ) ;
return 0 ;
}
static void F_29 ( struct V_62 * V_63 )
{
int V_64 ;
V_64 = F_30 ( V_63 ) ;
F_31 ( L_3 ,
V_64 == V_65 ? L_4 :
L_5 ) ;
if ( V_64 == V_65 )
F_31 ( L_6 ,
V_63 -> V_66 ) ;
if ( V_64 == V_65 )
F_31 ( L_7 , V_63 -> V_67 ) ;
F_31 ( L_8 , V_63 -> V_68 ) ;
F_31 ( L_9
L_10 , F_32 ( V_63 ) ,
F_33 ( V_63 ) , V_64 , F_34 ( V_63 ) ,
F_35 ( V_63 ) ) ;
}
void F_36 ( struct V_51 * V_52 , int V_69 ,
struct V_40 * V_70 , T_1 V_71 )
{
struct V_62 * V_63 ;
int V_72 = V_70 -> V_42 ;
F_14 ( V_70 -> V_48 & V_47 ) ;
V_63 = V_52 -> V_53 ;
F_14 ( ( void * ) ( V_63 + 1 ) > ( V_52 -> V_41 . V_44 + V_52 -> V_41 . V_42 ) ) ;
V_63 -> V_66 = V_71 ;
V_63 -> V_67 = V_72 ;
V_63 -> V_68 = ( T_1 ) V_70 -> V_48 ;
V_63 -> V_73 = F_37 ( V_74 , V_65 ,
V_69 , V_72 >> 4 ) ;
V_52 -> V_53 = V_63 + 1 ;
F_29 ( V_63 ) ;
}
void F_38 ( struct V_51 * V_52 , int V_69 ,
struct V_40 * V_75 )
{
struct V_62 * V_63 ;
unsigned int V_72 = V_75 -> V_42 ;
F_14 ( V_72 & V_76 ) ;
F_14 ( V_75 -> V_48 & V_47 ) ;
V_63 = V_52 -> V_53 ;
F_39 ( ( void * ) ( V_63 + 1 ) > ( V_52 -> V_41 . V_44 + V_52 -> V_41 . V_42 ) ) ;
V_63 -> V_77 = 0 ;
V_63 -> V_78 = 0 ;
V_63 -> V_68 = ( T_1 ) V_75 -> V_48 ;
V_63 -> V_73 = F_37 ( V_74 , V_79 ,
V_69 , V_72 >> 4 ) ;
V_52 -> V_53 = V_63 + 1 ;
F_29 ( V_63 ) ;
}
static void F_40 ( struct V_80 * V_81 )
{
F_31 ( L_11 ) ;
F_31 ( L_12 ,
F_41 ( V_81 ) , F_42 ( V_81 ) , F_43 ( V_81 ) ) ;
}
void F_44 ( struct V_51 * V_52 ,
enum V_82 V_83 )
{
struct V_80 * V_81 ;
V_81 = V_52 -> V_53 ;
F_14 ( ( void * ) ( V_81 + 1 ) > ( V_52 -> V_41 . V_44 + V_52 -> V_41 . V_42 ) ) ;
V_81 -> V_77 = 0 ;
V_81 -> V_78 = 0 ;
V_81 -> V_84 = 0 ;
V_81 -> V_85 = F_45 ( V_86 [ V_83 ] . V_87 ,
V_88 ) ;
V_52 -> V_53 = V_81 + 1 ;
F_40 ( V_81 ) ;
}
static void F_46 ( struct V_89 * V_90 )
{
int V_91 , V_83 ;
V_91 = F_47 ( V_90 ) ;
V_83 = F_48 ( V_90 ) ;
F_31 ( L_13 ,
V_91 == V_92 ? L_14 : L_15 , V_83 ) ;
F_31 ( L_16
L_17 ,
F_49 ( V_90 ) , F_50 ( V_90 ) , F_51 ( V_90 ) ,
F_52 ( V_90 ) , F_53 ( V_90 ) ,
F_54 ( V_90 ) , F_55 ( V_90 ) ) ;
if ( V_91 == V_93 )
F_31 ( L_18 ,
F_56 ( V_90 ) , F_57 ( V_90 ) ) ;
F_31 ( L_19 , & V_90 -> V_94 ) ;
F_31 ( L_20
L_21 , F_58 ( V_90 ) ,
F_59 ( V_90 ) , V_91 , V_83 , F_60 ( V_90 ) ,
F_61 ( V_90 ) ) ;
if ( V_91 == V_93 )
F_31 ( L_22 ,
F_62 ( V_90 ) , F_63 ( V_90 ) ) ;
else
F_31 ( L_23
L_24 ,
F_64 ( V_90 ) , F_65 ( V_90 ) ,
F_66 ( V_90 ) , F_67 ( V_90 ) ) ;
if ( V_91 == V_93 )
F_31 ( L_25 ,
F_68 ( V_90 ) , F_69 ( V_90 ) ) ;
else
F_31 ( L_26 ,
F_70 ( V_90 ) , F_71 ( V_90 ) ) ;
F_31 ( L_27 , V_90 -> V_95 ) ;
F_31 ( L_28 , V_90 -> V_96 ) ;
}
void F_72 ( struct V_51 * V_52 , int V_97 ,
const struct V_98 * V_99 ,
const struct V_100 * V_101 , T_4 V_48 ,
enum V_82 V_83 , T_1 V_102 )
{
int V_103 = 0 ;
int V_8 = 0 ;
int V_104 = 1 ;
int V_105 , V_106 ;
struct V_98 V_107 = * V_99 ;
int V_108 = V_101 -> V_108 ;
int V_109 ;
struct V_89 * V_90 ;
V_105 = V_106 = V_86 [ V_83 ] . V_87 ;
if ( V_101 -> type == V_110 &&
V_101 -> V_111 == V_112 ) {
V_107 . V_113 >>= 1 ;
V_107 . V_114 >>= 1 ;
V_108 = 8 ;
}
V_109 = F_73 ( ( V_108 * V_97 ) >> 3 , V_115 ) ;
V_48 += V_107 . V_114 * V_109 + ( V_107 . V_116 * V_108 >> 3 ) ;
V_90 = V_52 -> V_53 ;
F_14 ( ( void * ) ( V_90 + 1 ) > ( V_52 -> V_41 . V_44 + V_52 -> V_41 . V_42 ) ) ;
V_90 -> V_117 = F_74 ( V_101 -> V_111 ,
V_104 ,
V_8 ,
! ! ( V_102 & V_118 ) ,
! ! ( V_102 & V_119 ) ,
! ! ( V_102 & V_120 ) ,
V_109 ) ;
V_90 -> V_78 = 0 ;
V_90 -> V_94 = ( T_1 ) V_48 ;
V_90 -> V_121 = F_75 ( ! ! ( V_102 & V_122 ) ,
V_92 , V_105 , V_103 , V_106 ) ;
V_90 -> V_123 = F_76 ( 0 , 0 , 0 , 0 ) ;
V_90 -> V_124 = F_77 ( V_125 ,
V_126 ) ;
V_90 -> V_95 = 0 ;
V_90 -> V_96 = 0 ;
V_52 -> V_53 = V_90 + 1 ;
F_46 ( V_90 ) ;
}
void F_78 ( struct V_51 * V_52 , int V_97 ,
const struct V_98 * V_99 ,
const struct V_100 * V_101 , T_4 V_48 ,
enum V_82 V_83 , int V_8 , T_1 V_102 , int V_127 ,
int V_128 , int V_129 , int V_130 )
{
int V_103 = 0 ;
int V_104 = 1 ;
int V_108 = V_101 -> V_108 ;
int V_105 , V_106 ;
struct V_98 V_107 = * V_99 ;
int V_109 ;
struct V_89 * V_90 ;
V_105 = V_106 = V_86 [ V_83 ] . V_87 ;
if ( V_101 -> type == V_110 &&
V_101 -> V_111 == V_112 ) {
V_107 . V_113 >>= 1 ;
V_107 . V_114 >>= 1 ;
V_108 = 8 ;
}
V_109 = F_73 ( ( V_108 * V_97 ) >> 3 , V_115 ) ;
V_48 += V_107 . V_114 * V_109 + ( V_107 . V_116 * V_108 >> 3 ) ;
V_90 = V_52 -> V_53 ;
F_14 ( ( void * ) ( V_90 + 1 ) > ( V_52 -> V_41 . V_44 + V_52 -> V_41 . V_42 ) ) ;
V_90 -> V_117 = F_74 ( V_101 -> V_111 ,
V_104 ,
V_8 ,
! ! ( V_102 & V_118 ) ,
! ! ( V_102 & V_119 ) ,
! ! ( V_102 & V_120 ) ,
V_109 ) ;
V_90 -> V_131 = F_79 ( V_107 . V_97 ,
V_107 . V_113 ) ;
V_90 -> V_94 = ( T_1 ) V_48 ;
V_90 -> V_121 = F_75 ( ! ! ( V_102 & V_122 ) ,
V_93 , V_105 , V_103 , V_106 ) ;
V_90 -> V_132 = F_80 ( V_127 ,
V_128 ) ;
V_90 -> V_133 = F_81 ( V_129 , V_130 ) ;
V_90 -> V_95 = 0 ;
V_90 -> V_96 = 0 ;
V_52 -> V_53 = V_90 + 1 ;
F_46 ( V_90 ) ;
}
void F_82 ( struct V_1 * V_2 , int V_54 ,
bool V_134 )
{
T_1 V_9 ;
V_9 = F_1 ( V_2 , V_135 ) ;
if ( V_134 )
V_9 |= ( 1 << ( V_54 * 2 ) ) ;
else
V_9 &= ~ ( 1 << ( V_54 * 2 ) ) ;
F_3 ( V_2 , V_135 , V_9 ) ;
}
void F_83 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_136 ,
F_1 ( V_2 , V_136 ) ) ;
}
void F_84 ( struct V_1 * V_2 , int V_137 ,
enum V_82 V_83 )
{
int V_138 = V_86 [ V_83 ] . V_139 ;
F_6 ( V_2 , V_138 , V_137 ,
V_140 , V_141 ) ;
}
void F_85 ( struct V_1 * V_2 ,
enum V_142 V_143 ,
enum V_82 V_83 )
{
int V_138 = V_86 [ V_83 ] . V_139 ;
F_6 ( V_2 , V_138 , V_143 ,
V_144 , V_145 ) ;
}
static void F_86 ( const struct V_146 * V_147 , void * V_148 )
{
struct V_1 * V_2 = V_148 ;
struct V_40 V_149 ;
int V_150 , T_2 ;
F_9 ( & V_2 -> V_12 -> V_11 , L_29 ) ;
if ( ! V_147 || ! V_147 -> V_151 ) {
F_20 ( & V_2 -> V_12 -> V_11 , L_30 ) ;
return;
}
if ( F_5 ( V_2 , V_59 , V_152 ,
V_153 ) ) {
V_2 -> V_154 ( V_2 -> V_12 ) ;
return;
}
T_2 = F_12 ( & V_149 , V_147 -> V_42 ) ;
if ( T_2 ) {
F_20 ( & V_2 -> V_12 -> V_11 ,
L_31 ) ;
goto V_155;
}
memcpy ( V_149 . V_44 , V_147 -> V_151 , V_147 -> V_42 ) ;
F_17 ( V_2 , & V_149 ) ;
F_3 ( V_2 , V_58 , ( T_1 ) V_149 . V_48 ) ;
for ( V_150 = 0 ; V_150 < 100 ; V_150 ++ ) {
F_87 ( 10 ) ;
if ( F_5 ( V_2 , V_59 , V_152 ,
V_153 ) )
break;
}
if ( V_150 == 100 ) {
F_20 ( & V_2 -> V_12 -> V_11 , L_32 ) ;
goto V_156;
}
V_2 -> V_154 ( V_2 -> V_12 ) ;
V_156:
F_21 ( V_2 , & V_149 ) ;
F_15 ( & V_149 ) ;
V_155:
F_88 ( V_147 ) ;
}
static int F_89 ( struct V_1 * V_2 )
{
int T_2 ;
struct V_10 * V_11 = & V_2 -> V_12 -> V_11 ;
T_2 = F_90 ( V_157 , 1 ,
( const char * ) V_158 , V_11 , V_45 , V_2 ,
F_86 ) ;
if ( T_2 ) {
F_20 ( V_11 , L_33 , V_158 ) ;
return T_2 ;
} else {
F_91 ( V_11 , L_34 , V_158 ) ;
}
return 0 ;
}
struct V_1 * F_92 ( struct V_159 * V_12 ,
void (* V_154)( struct V_159 * V_12 ) )
{
struct V_160 * V_161 ;
struct V_1 * V_2 ;
int T_2 ;
F_9 ( & V_12 -> V_11 , L_35 ) ;
V_2 = F_93 ( & V_12 -> V_11 , sizeof( * V_2 ) , V_45 ) ;
if ( ! V_2 ) {
F_20 ( & V_12 -> V_11 , L_36 ) ;
return F_94 ( - V_46 ) ;
}
V_2 -> V_12 = V_12 ;
V_2 -> V_154 = V_154 ;
V_161 = F_95 ( V_12 , V_162 , L_37 ) ;
if ( V_161 == NULL ) {
F_20 ( & V_12 -> V_11 , L_38 ) ;
return F_94 ( - V_163 ) ;
}
V_2 -> V_4 = F_96 ( & V_12 -> V_11 , V_161 -> V_164 , F_97 ( V_161 ) ) ;
if ( ! V_2 -> V_4 ) {
F_20 ( & V_12 -> V_11 , L_39 ) ;
return F_94 ( - V_46 ) ;
}
T_2 = F_89 ( V_2 ) ;
if ( T_2 ) {
F_98 ( L_40 , V_158 ) ;
return F_94 ( T_2 ) ;
}
return V_2 ;
}
