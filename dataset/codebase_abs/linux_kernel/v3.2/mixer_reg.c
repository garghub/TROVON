static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 . V_5 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
F_4 ( V_6 , V_2 -> V_4 . V_5 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_6 , T_1 V_7 )
{
T_1 V_8 = F_1 ( V_2 , V_3 ) ;
V_6 = ( V_6 & V_7 ) | ( V_8 & ~ V_7 ) ;
F_4 ( V_6 , V_2 -> V_4 . V_5 + V_3 ) ;
}
static inline T_1 F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 . V_9 + V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
F_4 ( V_6 , V_2 -> V_4 . V_9 + V_3 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_6 , T_1 V_7 )
{
T_1 V_8 = F_6 ( V_2 , V_3 ) ;
V_6 = ( V_6 & V_7 ) | ( V_8 & ~ V_7 ) ;
F_4 ( V_6 , V_2 -> V_4 . V_9 + V_3 ) ;
}
void F_9 ( struct V_1 * V_2 , int V_10 )
{
F_8 ( V_2 , V_11 , V_10 ? V_12 : 0 ,
V_12 ) ;
F_3 ( V_2 , V_13 , V_10 ? V_14 : 0 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
int V_15 = 100 ;
F_3 ( V_2 , V_16 , V_17 ) ;
for ( V_15 = 100 ; V_15 ; -- V_15 ) {
if ( ~ F_1 ( V_2 , V_16 ) & V_17 )
break;
F_11 ( 10 ) ;
}
F_12 ( V_15 == 0 , L_1 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
unsigned long V_18 ;
T_1 V_6 ;
F_14 ( & V_2 -> V_19 , V_18 ) ;
F_9 ( V_2 , V_20 ) ;
F_7 ( V_2 , V_21 , V_22 ) ;
F_8 ( V_2 , V_11 , V_23 ,
V_24 ) ;
V_6 = F_15 ( 1 ) ;
V_6 |= F_16 ( 2 ) ;
V_6 |= F_17 ( 3 ) ;
F_7 ( V_2 , V_25 , V_6 ) ;
F_7 ( V_2 , V_26 , 0x808080 ) ;
F_7 ( V_2 , V_27 , 0x808080 ) ;
F_7 ( V_2 , V_28 , 0x808080 ) ;
V_6 = V_29 ;
V_6 |= V_30 ;
V_6 |= F_18 ( 0xff ) ;
F_7 ( V_2 , F_19 ( 0 ) , V_6 ) ;
F_7 ( V_2 , F_19 ( 1 ) , V_6 ) ;
F_10 ( V_2 ) ;
F_20 ( V_2 ) ;
F_8 ( V_2 , V_31 , ~ 0 , V_32 ) ;
F_9 ( V_2 , V_33 ) ;
F_21 ( & V_2 -> V_19 , V_18 ) ;
}
void F_22 ( struct V_1 * V_2 , int V_34 ,
const struct V_35 * V_36 , const struct V_37 * V_38 )
{
T_1 V_6 ;
unsigned long V_18 ;
F_14 ( & V_2 -> V_19 , V_18 ) ;
F_9 ( V_2 , V_20 ) ;
F_8 ( V_2 , F_19 ( V_34 ) ,
F_23 ( V_36 -> V_39 ) , V_40 ) ;
F_7 ( V_2 , F_24 ( V_34 ) , V_38 -> V_41 . V_42 ) ;
V_6 = F_25 ( V_38 -> V_41 . V_43 ) ;
V_6 |= F_26 ( V_38 -> V_41 . V_44 ) ;
V_6 |= F_27 ( V_38 -> V_45 ) ;
V_6 |= F_28 ( V_38 -> V_46 ) ;
F_7 ( V_2 , F_29 ( V_34 ) , V_6 ) ;
V_6 = F_30 ( V_38 -> V_41 . V_47 ) ;
V_6 |= F_31 ( V_38 -> V_41 . V_48 ) ;
F_7 ( V_2 , F_32 ( V_34 ) , V_6 ) ;
V_6 = F_33 ( V_38 -> V_49 . V_47 ) ;
V_6 |= F_34 ( V_38 -> V_49 . V_48 ) ;
F_7 ( V_2 , F_35 ( V_34 ) , V_6 ) ;
F_9 ( V_2 , V_33 ) ;
F_21 ( & V_2 -> V_19 , V_18 ) ;
}
void F_36 ( struct V_1 * V_2 ,
const struct V_35 * V_36 , const struct V_37 * V_38 )
{
unsigned long V_18 ;
F_14 ( & V_2 -> V_19 , V_18 ) ;
F_9 ( V_2 , V_20 ) ;
F_5 ( V_2 , V_50 , V_36 -> V_39 , V_51 ) ;
F_3 ( V_2 , V_52 , F_37 ( V_38 -> V_41 . V_42 ) |
F_38 ( V_38 -> V_41 . V_53 ) ) ;
F_3 ( V_2 , V_54 , F_37 ( V_38 -> V_41 . V_42 ) |
F_38 ( V_38 -> V_41 . V_53 / 2 ) ) ;
F_3 ( V_2 , V_55 , V_38 -> V_41 . V_43 ) ;
F_3 ( V_2 , V_56 , V_38 -> V_41 . V_44 ) ;
F_3 ( V_2 , V_57 ,
F_39 ( V_38 -> V_41 . V_47 ) ) ;
F_3 ( V_2 , V_58 , V_38 -> V_41 . V_48 ) ;
F_3 ( V_2 , V_59 , V_38 -> V_49 . V_43 ) ;
F_3 ( V_2 , V_60 , V_38 -> V_49 . V_47 ) ;
if ( V_38 -> V_49 . V_61 == V_62 ) {
F_3 ( V_2 , V_63 , V_38 -> V_49 . V_44 / 2 ) ;
F_3 ( V_2 , V_64 , V_38 -> V_49 . V_48 / 2 ) ;
} else {
F_3 ( V_2 , V_63 , V_38 -> V_49 . V_44 ) ;
F_3 ( V_2 , V_64 , V_38 -> V_49 . V_48 ) ;
}
F_3 ( V_2 , V_65 , V_38 -> V_45 ) ;
F_3 ( V_2 , V_66 , V_38 -> V_46 ) ;
F_3 ( V_2 , V_67 , V_68 ) ;
F_9 ( V_2 , V_33 ) ;
F_21 ( & V_2 -> V_19 , V_18 ) ;
}
void F_40 ( struct V_1 * V_2 , int V_34 , T_2 V_69 )
{
T_1 V_6 = V_69 ? ~ 0 : 0 ;
unsigned long V_18 ;
F_14 ( & V_2 -> V_19 , V_18 ) ;
F_9 ( V_2 , V_20 ) ;
if ( V_34 == 0 )
F_8 ( V_2 , V_21 , V_6 , V_70 ) ;
else
F_8 ( V_2 , V_21 , V_6 , V_71 ) ;
F_7 ( V_2 , F_41 ( V_34 ) , V_69 ) ;
F_9 ( V_2 , V_33 ) ;
F_21 ( & V_2 -> V_19 , V_18 ) ;
}
void F_42 ( struct V_1 * V_2 ,
T_2 V_72 [ 2 ] , T_2 V_73 [ 2 ] )
{
T_1 V_6 = V_72 [ 0 ] ? ~ 0 : 0 ;
unsigned long V_18 ;
F_14 ( & V_2 -> V_19 , V_18 ) ;
F_9 ( V_2 , V_20 ) ;
F_8 ( V_2 , V_21 , V_6 , V_74 ) ;
F_5 ( V_2 , V_75 , V_6 , V_76 ) ;
F_3 ( V_2 , V_77 , V_72 [ 0 ] ) ;
F_3 ( V_2 , V_78 , V_73 [ 0 ] ) ;
F_3 ( V_2 , V_79 , V_72 [ 1 ] ) ;
F_3 ( V_2 , V_80 , V_73 [ 1 ] ) ;
F_9 ( V_2 , V_33 ) ;
F_21 ( & V_2 -> V_19 , V_18 ) ;
}
static void F_43 ( struct V_81 * V_82 )
{
struct V_83 * V_84 = & V_82 -> V_85 ;
struct V_86 * V_87 ;
if ( V_82 == NULL )
return;
F_44 ( & V_82 -> V_88 ) ;
if ( V_82 -> V_89 == V_90 )
goto V_87;
V_87 = V_82 -> V_91 ;
V_82 -> V_91 = V_82 -> V_92 ;
if ( F_45 ( V_84 ) ) {
if ( V_82 -> V_89 != V_93 )
V_82 -> V_92 = NULL ;
} else {
struct V_86 * V_94 ;
V_94 = F_46 ( V_84 , struct V_86 , V_95 ) ;
F_47 ( & V_94 -> V_95 ) ;
V_82 -> V_92 = V_94 ;
}
V_82 -> V_96 . V_97 ( V_82 , V_82 -> V_92 ) ;
if ( V_87 && V_87 != V_82 -> V_91 )
F_48 ( & V_87 -> V_98 , V_99 ) ;
V_87:
F_49 ( & V_82 -> V_88 ) ;
}
T_3 F_50 ( int V_100 , void * V_101 )
{
struct V_1 * V_2 = V_101 ;
T_1 V_102 , V_6 ;
F_44 ( & V_2 -> V_19 ) ;
V_6 = F_6 ( V_2 , V_103 ) ;
if ( V_6 & V_104 ) {
F_51 ( V_105 , & V_2 -> V_106 ) ;
F_52 ( & V_2 -> V_107 ) ;
}
if ( ~ V_6 & V_108 ) {
V_6 &= ~ V_108 ;
V_6 |= V_109 ;
}
F_7 ( V_2 , V_103 , V_6 ) ;
F_49 ( & V_2 -> V_19 ) ;
if ( ~ V_6 & V_109 )
return V_110 ;
for ( V_102 = 0 ; V_102 < V_111 ; ++ V_102 )
F_43 ( V_2 -> V_82 [ V_102 ] ) ;
return V_110 ;
}
void F_53 ( struct V_1 * V_2 , int V_39 )
{
T_1 V_6 ;
V_6 = V_39 == 0 ? V_112 : V_113 ;
F_8 ( V_2 , V_21 , V_6 , V_114 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
unsigned long V_18 ;
F_14 ( & V_2 -> V_19 , V_18 ) ;
F_8 ( V_2 , V_11 , ~ 0 , V_115 ) ;
F_21 ( & V_2 -> V_19 , V_18 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
unsigned long V_18 ;
F_14 ( & V_2 -> V_19 , V_18 ) ;
F_8 ( V_2 , V_11 , 0 , V_115 ) ;
F_21 ( & V_2 -> V_19 , V_18 ) ;
}
int F_56 ( struct V_1 * V_2 )
{
int V_116 ;
F_57 ( V_105 , & V_2 -> V_106 ) ;
V_116 = F_58 ( V_2 -> V_107 ,
F_59 ( V_105 , & V_2 -> V_106 ) ,
F_60 ( 1000 ) ) ;
if ( V_116 > 0 )
return 0 ;
if ( V_116 < 0 )
return V_116 ;
F_61 ( V_2 , L_2 ) ;
return - V_117 ;
}
void F_62 ( struct V_1 * V_2 ,
struct V_118 * V_36 )
{
T_1 V_6 = 0 ;
unsigned long V_18 ;
F_14 ( & V_2 -> V_19 , V_18 ) ;
F_9 ( V_2 , V_20 ) ;
if ( V_36 -> V_119 == V_120 )
V_6 |= V_121 ;
else
V_6 |= V_22 ;
if ( V_36 -> V_61 == V_62 )
V_6 |= V_122 ;
else
V_6 |= V_123 ;
if ( V_36 -> V_44 == 480 )
V_6 |= V_124 | V_125 ;
else if ( V_36 -> V_44 == 576 )
V_6 |= V_126 | V_125 ;
else if ( V_36 -> V_44 == 720 )
V_6 |= V_127 | V_128 ;
else if ( V_36 -> V_44 == 1080 )
V_6 |= V_129 | V_128 ;
else
F_12 ( 1 , L_3 , V_36 -> V_44 ) ;
F_8 ( V_2 , V_21 , V_6 , V_130 |
V_131 ) ;
V_6 = ( V_36 -> V_61 == V_62 ) ? ~ 0 : 0 ;
F_5 ( V_2 , V_50 , V_6 ,
V_132 | V_133 ) ;
F_9 ( V_2 , V_33 ) ;
F_21 ( & V_2 -> V_19 , V_18 ) ;
}
void F_63 ( struct V_1 * V_2 , int V_34 , int V_10 )
{
}
void F_64 ( struct V_1 * V_2 , int V_10 )
{
}
static inline void F_65 ( struct V_1 * V_2 ,
int V_3 , const T_4 * V_134 , unsigned int V_135 )
{
F_66 ( V_135 & 3 ) ;
for (; V_135 ; V_135 -= 4 , V_3 += 4 , V_134 += 4 ) {
T_1 V_6 = ( V_134 [ 0 ] << 24 ) | ( V_134 [ 1 ] << 16 ) |
( V_134 [ 2 ] << 8 ) | V_134 [ 3 ] ;
F_3 ( V_2 , V_3 , V_6 ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
F_65 ( V_2 , V_136 ,
V_137 , sizeof V_137 ) ;
F_65 ( V_2 , V_138 ,
V_139 , sizeof V_139 ) ;
F_65 ( V_2 , V_140 ,
V_141 , sizeof V_141 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
#define F_68 ( V_3 ) \
do { \
mxr_dbg(mdev, #reg_id " = %08x\n", \
(u32)readl(mdev->res.mxr_regs + reg_id)); \
} while (0)
F_68 ( V_11 ) ;
F_68 ( V_21 ) ;
F_68 ( V_31 ) ;
F_68 ( V_103 ) ;
F_68 ( V_25 ) ;
F_68 ( V_142 ) ;
F_68 ( V_143 ) ;
F_68 ( V_144 ) ;
F_68 ( V_145 ) ;
F_68 ( V_146 ) ;
F_68 ( V_147 ) ;
F_68 ( V_148 ) ;
F_68 ( V_149 ) ;
F_68 ( V_150 ) ;
F_68 ( V_151 ) ;
F_68 ( V_152 ) ;
F_68 ( V_153 ) ;
F_68 ( V_154 ) ;
#undef F_68
}
static void F_69 ( struct V_1 * V_2 )
{
#define F_68 ( V_3 ) \
do { \
mxr_dbg(mdev, #reg_id " = %08x\n", \
(u32) readl(mdev->res.vp_regs + reg_id)); \
} while (0)
F_68 ( V_75 ) ;
F_68 ( V_16 ) ;
F_68 ( V_13 ) ;
F_68 ( V_155 ) ;
F_68 ( V_50 ) ;
F_68 ( V_52 ) ;
F_68 ( V_54 ) ;
F_68 ( V_156 ) ;
F_68 ( V_77 ) ;
F_68 ( V_79 ) ;
F_68 ( V_78 ) ;
F_68 ( V_80 ) ;
F_68 ( V_67 ) ;
F_68 ( V_57 ) ;
F_68 ( V_58 ) ;
F_68 ( V_55 ) ;
F_68 ( V_56 ) ;
F_68 ( V_60 ) ;
F_68 ( V_64 ) ;
F_68 ( V_59 ) ;
F_68 ( V_63 ) ;
F_68 ( V_65 ) ;
F_68 ( V_66 ) ;
#undef F_68
}
void F_70 ( struct V_1 * V_2 )
{
F_67 ( V_2 ) ;
F_69 ( V_2 ) ;
}
