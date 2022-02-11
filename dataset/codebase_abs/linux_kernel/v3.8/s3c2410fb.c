static int F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 == V_4 ) ;
}
static void F_2 ( struct V_5 * V_6 )
{
unsigned long V_7 , V_8 , V_9 ;
struct V_1 * V_2 = V_6 -> V_10 ;
void T_1 * V_11 = V_2 -> V_12 ;
V_7 = V_6 -> V_13 . V_14 >> 1 ;
V_8 = V_6 -> V_13 . V_14 ;
V_8 += V_6 -> V_13 . V_15 * V_6 -> V_16 . V_17 ;
V_8 >>= 1 ;
V_9 = F_3 ( 0 ) |
F_4 ( ( V_6 -> V_13 . V_15 / 2 ) & 0x3ff ) ;
F_5 ( L_1 , V_7 ) ;
F_5 ( L_2 , V_8 ) ;
F_5 ( L_3 , V_9 ) ;
F_6 ( V_7 , V_11 + V_18 ) ;
F_6 ( V_8 , V_11 + V_19 ) ;
F_6 ( V_9 , V_11 + V_20 ) ;
}
static unsigned int F_7 ( struct V_1 * V_2 ,
unsigned long V_21 )
{
unsigned long V_22 = V_2 -> V_23 ;
unsigned long long div ;
div = ( unsigned long long ) V_22 * V_21 ;
div >>= 12 ;
F_8 ( div , 625 * 625UL * 625 ) ;
F_5 ( L_4 , V_21 , ( long ) div ) ;
return div ;
}
static int F_9 ( struct V_24 * V_16 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
struct V_25 * V_26 = V_2 -> V_27 -> V_28 ;
struct V_29 * V_30 = NULL ;
struct V_29 * V_31 = V_26 -> V_32 +
V_26 -> V_31 ;
int type = V_31 -> type ;
unsigned V_33 ;
F_5 ( L_5 , V_16 , V_6 ) ;
if ( V_16 -> V_17 == V_31 -> V_17 &&
V_16 -> V_34 == V_31 -> V_34 &&
V_16 -> V_35 == V_31 -> V_36 )
V_30 = V_31 ;
else
for ( V_33 = 0 ; V_33 < V_26 -> V_37 ; V_33 ++ )
if ( type == V_26 -> V_32 [ V_33 ] . type &&
V_16 -> V_17 == V_26 -> V_32 [ V_33 ] . V_17 &&
V_16 -> V_34 == V_26 -> V_32 [ V_33 ] . V_34 &&
V_16 -> V_35 == V_26 -> V_32 [ V_33 ] . V_36 ) {
V_30 = V_26 -> V_32 + V_33 ;
break;
}
if ( ! V_30 ) {
F_5 ( L_6 ,
V_16 -> V_34 , V_16 -> V_17 , V_16 -> V_35 ) ;
return - V_38 ;
}
V_16 -> V_39 = V_30 -> V_34 ;
V_16 -> V_40 = V_30 -> V_17 ;
V_16 -> V_41 = V_30 -> V_41 ;
V_16 -> V_42 = V_30 -> V_42 ;
V_16 -> V_43 = V_30 -> V_43 ;
V_16 -> V_44 = V_30 -> V_44 ;
V_16 -> V_45 = V_30 -> V_45 ;
V_16 -> V_46 = V_30 -> V_46 ;
V_16 -> V_47 = V_30 -> V_47 ;
V_16 -> V_48 = V_30 -> V_48 ;
V_16 -> V_49 = V_30 -> V_49 ;
V_2 -> V_11 . V_50 = V_30 -> V_50 ;
V_2 -> V_11 . V_51 = V_30 -> type ;
V_16 -> V_52 . V_53 = 0 ;
V_16 -> V_52 . V_54 = 0 ;
switch ( V_16 -> V_35 ) {
case 1 :
case 2 :
case 4 :
V_16 -> V_55 . V_53 = 0 ;
V_16 -> V_55 . V_54 = V_16 -> V_35 ;
V_16 -> V_56 = V_16 -> V_55 ;
V_16 -> V_57 = V_16 -> V_55 ;
break;
case 8 :
if ( V_30 -> type != V_58 ) {
V_16 -> V_55 . V_54 = 3 ;
V_16 -> V_55 . V_53 = 5 ;
V_16 -> V_56 . V_54 = 3 ;
V_16 -> V_56 . V_53 = 2 ;
V_16 -> V_57 . V_54 = 2 ;
V_16 -> V_57 . V_53 = 0 ;
} else {
V_16 -> V_55 . V_53 = 0 ;
V_16 -> V_55 . V_54 = 8 ;
V_16 -> V_56 = V_16 -> V_55 ;
V_16 -> V_57 = V_16 -> V_55 ;
}
break;
case 12 :
V_16 -> V_55 . V_54 = 4 ;
V_16 -> V_55 . V_53 = 8 ;
V_16 -> V_56 . V_54 = 4 ;
V_16 -> V_56 . V_53 = 4 ;
V_16 -> V_57 . V_54 = 4 ;
V_16 -> V_57 . V_53 = 0 ;
break;
default:
case 16 :
if ( V_30 -> V_50 & V_59 ) {
V_16 -> V_55 . V_53 = 11 ;
V_16 -> V_56 . V_53 = 5 ;
V_16 -> V_57 . V_53 = 0 ;
V_16 -> V_55 . V_54 = 5 ;
V_16 -> V_56 . V_54 = 6 ;
V_16 -> V_57 . V_54 = 5 ;
} else {
V_16 -> V_55 . V_53 = 11 ;
V_16 -> V_56 . V_53 = 6 ;
V_16 -> V_57 . V_53 = 1 ;
V_16 -> V_55 . V_54 = 5 ;
V_16 -> V_56 . V_54 = 5 ;
V_16 -> V_57 . V_54 = 5 ;
}
break;
case 32 :
V_16 -> V_55 . V_54 = 8 ;
V_16 -> V_55 . V_53 = 16 ;
V_16 -> V_56 . V_54 = 8 ;
V_16 -> V_56 . V_53 = 8 ;
V_16 -> V_57 . V_54 = 8 ;
V_16 -> V_57 . V_53 = 0 ;
break;
}
return 0 ;
}
static void F_10 ( const struct V_5 * V_6 ,
struct V_60 * V_11 )
{
const struct V_1 * V_2 = V_6 -> V_10 ;
const struct V_24 * V_16 = & V_6 -> V_16 ;
int type = V_11 -> V_51 & ~ V_58 ;
int V_61 = V_16 -> V_34 >> 2 ;
unsigned V_62 = ( V_16 -> V_44 >> 4 ) - 1 ;
unsigned V_63 = ( V_16 -> V_49 >> 4 ) - 1 ;
if ( type != V_64 )
V_61 >>= 1 ;
switch ( V_16 -> V_35 ) {
case 1 :
V_11 -> V_51 |= V_65 ;
break;
case 2 :
V_11 -> V_51 |= V_66 ;
break;
case 4 :
V_11 -> V_51 |= V_67 ;
break;
case 8 :
V_11 -> V_51 |= V_68 ;
V_61 *= 3 ;
break;
case 12 :
V_11 -> V_51 |= V_69 ;
V_61 *= 3 ;
break;
default:
F_11 ( V_2 -> V_27 , L_7 ,
V_16 -> V_35 ) ;
}
F_5 ( L_8 ,
V_16 -> V_44 , V_16 -> V_45 , V_16 -> V_49 ) ;
V_11 -> V_70 = F_12 ( V_16 -> V_17 - 1 ) ;
if ( V_62 > 3 )
V_62 = 3 ;
if ( V_63 > 3 )
V_63 = 3 ;
V_11 -> V_71 = F_13 ( V_62 ) |
F_14 ( V_16 -> V_45 / 8 ) |
F_15 ( V_61 - 1 ) ;
V_11 -> V_72 = F_16 ( V_63 ) ;
}
static void F_17 ( const struct V_5 * V_6 ,
struct V_60 * V_11 )
{
const struct V_1 * V_2 = V_6 -> V_10 ;
const struct V_24 * V_16 = & V_6 -> V_16 ;
switch ( V_16 -> V_35 ) {
case 1 :
V_11 -> V_51 |= V_73 ;
break;
case 2 :
V_11 -> V_51 |= V_74 ;
break;
case 4 :
V_11 -> V_51 |= V_75 ;
break;
case 8 :
V_11 -> V_51 |= V_76 ;
V_11 -> V_50 |= V_77 |
V_59 ;
V_11 -> V_50 &= ~ V_78 ;
break;
case 16 :
V_11 -> V_51 |= V_79 ;
V_11 -> V_50 &= ~ V_77 ;
V_11 -> V_50 |= V_78 ;
break;
case 32 :
V_11 -> V_51 |= V_80 ;
V_11 -> V_50 &= ~ ( V_77 |
V_78 |
V_81 ) ;
break;
default:
F_11 ( V_2 -> V_27 , L_7 ,
V_16 -> V_35 ) ;
}
F_5 ( L_9 ,
V_16 -> V_46 , V_16 -> V_47 , V_16 -> V_48 ) ;
F_5 ( L_8 ,
V_16 -> V_44 , V_16 -> V_45 , V_16 -> V_49 ) ;
V_11 -> V_70 = F_12 ( V_16 -> V_17 - 1 ) |
F_18 ( V_16 -> V_46 - 1 ) |
F_19 ( V_16 -> V_47 - 1 ) |
F_20 ( V_16 -> V_48 - 1 ) ;
V_11 -> V_71 = F_21 ( V_16 -> V_45 - 1 ) |
F_22 ( V_16 -> V_44 - 1 ) |
F_15 ( V_16 -> V_34 - 1 ) ;
V_11 -> V_72 = F_23 ( V_16 -> V_49 - 1 ) ;
}
static void F_24 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
void T_1 * V_11 = V_2 -> V_12 ;
int type = V_2 -> V_11 . V_51 & V_58 ;
struct V_24 * V_16 = & V_6 -> V_16 ;
int V_82 ;
V_82 = F_25 ( F_7 ( V_2 , V_16 -> V_43 ) , 2 ) ;
F_5 ( L_10 , V_83 , V_16 -> V_34 ) ;
F_5 ( L_11 , V_83 , V_16 -> V_17 ) ;
F_5 ( L_12 , V_83 , V_16 -> V_35 ) ;
if ( type == V_58 ) {
F_17 ( V_6 , & V_2 -> V_11 ) ;
-- V_82 ;
if ( V_82 < 0 )
V_82 = 0 ;
} else {
F_10 ( V_6 , & V_2 -> V_11 ) ;
if ( V_82 < 2 )
V_82 = 2 ;
}
V_2 -> V_11 . V_51 |= F_26 ( V_82 ) ;
F_5 ( L_13 ) ;
F_5 ( L_14 , V_2 -> V_11 . V_51 ) ;
F_5 ( L_15 , V_2 -> V_11 . V_70 ) ;
F_5 ( L_16 , V_2 -> V_11 . V_71 ) ;
F_5 ( L_17 , V_2 -> V_11 . V_72 ) ;
F_5 ( L_18 , V_2 -> V_11 . V_50 ) ;
F_6 ( V_2 -> V_11 . V_51 & ~ V_84 ,
V_11 + V_85 ) ;
F_6 ( V_2 -> V_11 . V_70 , V_11 + V_86 ) ;
F_6 ( V_2 -> V_11 . V_71 , V_11 + V_87 ) ;
F_6 ( V_2 -> V_11 . V_72 , V_11 + V_88 ) ;
F_6 ( V_2 -> V_11 . V_50 , V_11 + V_89 ) ;
F_2 ( V_6 ) ;
V_2 -> V_11 . V_51 |= V_84 ,
F_6 ( V_2 -> V_11 . V_51 , V_11 + V_85 ) ;
}
static int F_27 ( struct V_5 * V_6 )
{
struct V_24 * V_16 = & V_6 -> V_16 ;
switch ( V_16 -> V_35 ) {
case 32 :
case 16 :
case 12 :
V_6 -> V_13 . V_90 = V_91 ;
break;
case 1 :
V_6 -> V_13 . V_90 = V_92 ;
break;
default:
V_6 -> V_13 . V_90 = V_93 ;
break;
}
V_6 -> V_13 . V_15 = ( V_16 -> V_39 * V_16 -> V_35 ) / 8 ;
F_24 ( V_6 ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 ,
unsigned int V_94 , unsigned int V_95 )
{
unsigned long V_96 ;
unsigned long V_97 ;
void T_1 * V_98 = V_2 -> V_98 ;
F_29 ( V_96 ) ;
V_2 -> V_99 [ V_94 ] = V_95 ;
if ( ! V_2 -> V_100 ) {
V_2 -> V_100 = 1 ;
V_97 = F_30 ( V_98 + V_101 ) ;
V_97 &= ~ V_102 ;
F_6 ( V_97 , V_98 + V_101 ) ;
}
F_31 ( V_96 ) ;
}
static inline unsigned int F_32 ( unsigned int V_103 ,
struct V_104 * V_105 )
{
V_103 &= 0xffff ;
V_103 >>= 16 - V_105 -> V_54 ;
return V_103 << V_105 -> V_53 ;
}
static int F_33 ( unsigned V_94 ,
unsigned V_55 , unsigned V_56 , unsigned V_57 ,
unsigned V_52 , struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
void T_1 * V_11 = V_2 -> V_12 ;
unsigned int V_95 ;
switch ( V_6 -> V_13 . V_90 ) {
case V_91 :
if ( V_94 < 16 ) {
T_2 * V_106 = V_6 -> V_107 ;
V_95 = F_32 ( V_55 , & V_6 -> V_16 . V_55 ) ;
V_95 |= F_32 ( V_56 , & V_6 -> V_16 . V_56 ) ;
V_95 |= F_32 ( V_57 , & V_6 -> V_16 . V_57 ) ;
V_106 [ V_94 ] = V_95 ;
}
break;
case V_93 :
if ( V_94 < 256 ) {
V_95 = ( V_55 >> 0 ) & 0xf800 ;
V_95 |= ( V_56 >> 5 ) & 0x07e0 ;
V_95 |= ( V_57 >> 11 ) & 0x001f ;
F_6 ( V_95 , V_11 + F_34 ( V_94 ) ) ;
F_28 ( V_2 , V_94 , V_95 ) ;
}
break;
default:
return 1 ;
}
return 0 ;
}
static void F_35 ( struct V_1 * V_2 , int V_108 )
{
unsigned long V_96 ;
F_29 ( V_96 ) ;
if ( V_108 )
V_2 -> V_11 . V_51 |= V_84 ;
else
V_2 -> V_11 . V_51 &= ~ V_84 ;
F_6 ( V_2 -> V_11 . V_51 , V_2 -> V_12 + V_85 ) ;
F_31 ( V_96 ) ;
}
static int F_36 ( int V_109 , struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
void T_1 * V_110 = V_2 -> V_12 ;
F_5 ( L_19 , V_109 , V_6 ) ;
V_110 += F_1 ( V_2 ) ? V_111 : V_112 ;
if ( V_109 == V_113 )
F_35 ( V_2 , 0 ) ;
else
F_35 ( V_2 , 1 ) ;
if ( V_109 == V_114 )
F_6 ( 0x0 , V_110 ) ;
else {
F_5 ( L_20 ) ;
F_6 ( V_115 , V_110 ) ;
}
return 0 ;
}
static int F_37 ( struct V_116 * V_27 ,
struct V_117 * V_118 , char * V_119 )
{
return snprintf ( V_119 , V_120 , L_21 , V_121 ? L_22 : L_23 ) ;
}
static int F_38 ( struct V_116 * V_27 ,
struct V_117 * V_118 ,
const char * V_119 , T_3 V_122 )
{
if ( V_122 < 1 )
return - V_38 ;
if ( F_39 ( V_119 , L_22 , 2 ) == 0 ||
F_39 ( V_119 , L_24 , 1 ) == 0 ) {
V_121 = 1 ;
F_40 ( V_27 , L_25 ) ;
} else if ( F_39 ( V_119 , L_23 , 3 ) == 0 ||
F_39 ( V_119 , L_26 , 1 ) == 0 ) {
V_121 = 0 ;
F_40 ( V_27 , L_27 ) ;
} else {
return - V_38 ;
}
return V_122 ;
}
static int F_41 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
T_4 V_123 ;
unsigned V_124 = F_42 ( V_6 -> V_13 . V_125 ) ;
F_5 ( L_28 , V_2 , V_124 ) ;
V_6 -> V_126 = F_43 ( V_2 -> V_27 , V_124 ,
& V_123 , V_127 ) ;
if ( V_6 -> V_126 ) {
F_5 ( L_29 ,
V_6 -> V_126 , V_124 ) ;
memset ( V_6 -> V_126 , 0x00 , V_124 ) ;
V_6 -> V_13 . V_14 = V_123 ;
F_5 ( L_30 ,
V_6 -> V_13 . V_14 , V_6 -> V_126 , V_124 ) ;
}
return V_6 -> V_126 ? 0 : - V_128 ;
}
static inline void F_44 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
F_45 ( V_2 -> V_27 , F_42 ( V_6 -> V_13 . V_125 ) ,
V_6 -> V_126 , V_6 -> V_13 . V_14 ) ;
}
static inline void F_46 ( void T_1 * V_129 ,
unsigned long V_130 , unsigned long V_131 )
{
unsigned long V_132 ;
V_132 = F_30 ( V_129 ) & ~ V_131 ;
F_6 ( V_132 | V_130 , V_129 ) ;
}
static int F_47 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
struct V_25 * V_26 = V_2 -> V_27 -> V_28 ;
unsigned long V_96 ;
void T_1 * V_11 = V_2 -> V_12 ;
void T_1 * V_133 ;
void T_1 * V_134 ;
if ( F_1 ( V_2 ) ) {
V_133 = V_11 + V_111 ;
V_134 = V_11 + V_135 ;
} else {
V_133 = V_11 + V_112 ;
V_134 = V_11 + V_136 ;
}
F_29 ( V_96 ) ;
F_46 ( V_137 , V_26 -> V_138 , V_26 -> V_139 ) ;
F_46 ( V_140 , V_26 -> V_141 , V_26 -> V_142 ) ;
F_46 ( V_143 , V_26 -> V_144 , V_26 -> V_145 ) ;
F_46 ( V_146 , V_26 -> V_147 , V_26 -> V_148 ) ;
F_31 ( V_96 ) ;
F_5 ( L_31 , V_26 -> V_134 ) ;
F_6 ( V_26 -> V_134 , V_134 ) ;
F_5 ( L_32 , F_30 ( V_133 ) ) ;
F_6 ( 0x00 , V_133 ) ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 )
{
unsigned int V_33 ;
void T_1 * V_11 = V_2 -> V_12 ;
V_2 -> V_100 = 0 ;
for ( V_33 = 0 ; V_33 < 256 ; V_33 ++ ) {
unsigned long V_149 = V_2 -> V_99 [ V_33 ] ;
if ( V_149 == V_150 )
continue;
F_6 ( V_149 , V_11 + F_34 ( V_33 ) ) ;
if ( F_49 ( V_11 + F_34 ( V_33 ) ) == V_149 )
V_2 -> V_99 [ V_33 ] = V_150 ;
else
V_2 -> V_100 = 1 ;
}
}
static T_5 F_50 ( int V_151 , void * V_152 )
{
struct V_1 * V_2 = V_152 ;
void T_1 * V_98 = V_2 -> V_98 ;
unsigned long V_153 = F_30 ( V_98 + V_154 ) ;
if ( V_153 & V_102 ) {
if ( V_2 -> V_100 )
F_48 ( V_2 ) ;
F_6 ( V_102 , V_98 + V_154 ) ;
F_6 ( V_102 , V_98 + V_155 ) ;
}
return V_156 ;
}
static int F_51 ( struct V_157 * V_158 ,
unsigned long V_95 , void * V_159 )
{
struct V_1 * V_6 ;
struct V_5 * V_160 ;
long V_161 ;
V_6 = F_52 ( V_158 , struct V_1 , V_162 ) ;
V_160 = F_53 ( F_54 ( V_6 -> V_27 ) ) ;
V_161 = V_6 -> V_23 - F_55 ( V_6 -> V_22 ) ;
if ( ( V_95 == V_163 && V_161 > 0 ) ||
( V_95 == V_164 && V_161 < 0 ) ) {
V_6 -> V_23 = F_55 ( V_6 -> V_22 ) ;
F_24 ( V_160 ) ;
}
return 0 ;
}
static inline int F_56 ( struct V_1 * V_6 )
{
V_6 -> V_162 . V_165 = F_51 ;
return F_57 ( & V_6 -> V_162 ,
V_166 ) ;
}
static inline void F_58 ( struct V_1 * V_6 )
{
F_59 ( & V_6 -> V_162 ,
V_166 ) ;
}
static inline int F_56 ( struct V_1 * V_6 )
{
return 0 ;
}
static inline void F_58 ( struct V_1 * V_6 )
{
}
static int F_60 ( struct V_167 * V_168 ,
enum V_169 V_3 )
{
struct V_1 * V_6 ;
struct V_29 * V_30 ;
struct V_5 * V_160 ;
struct V_25 * V_26 ;
struct V_170 * V_171 ;
int V_172 ;
int V_151 ;
int V_33 ;
int V_173 ;
T_2 V_51 ;
V_26 = V_168 -> V_27 . V_28 ;
if ( V_26 == NULL ) {
F_11 ( & V_168 -> V_27 ,
L_33 ) ;
return - V_38 ;
}
if ( V_26 -> V_31 >= V_26 -> V_37 ) {
F_11 ( & V_168 -> V_27 , L_34 ,
V_26 -> V_31 , V_26 -> V_37 ) ;
return - V_38 ;
}
V_30 = V_26 -> V_32 + V_26 -> V_31 ;
V_151 = F_61 ( V_168 , 0 ) ;
if ( V_151 < 0 ) {
F_11 ( & V_168 -> V_27 , L_35 ) ;
return - V_174 ;
}
V_160 = F_62 ( sizeof( struct V_1 ) , & V_168 -> V_27 ) ;
if ( ! V_160 )
return - V_128 ;
F_63 ( V_168 , V_160 ) ;
V_6 = V_160 -> V_10 ;
V_6 -> V_27 = & V_168 -> V_27 ;
V_6 -> V_3 = V_3 ;
V_171 = F_64 ( V_168 , V_175 , 0 ) ;
if ( V_171 == NULL ) {
F_11 ( & V_168 -> V_27 , L_36 ) ;
V_172 = - V_176 ;
goto V_177;
}
V_173 = F_65 ( V_171 ) ;
V_6 -> V_178 = F_66 ( V_171 -> V_179 , V_173 , V_168 -> V_180 ) ;
if ( V_6 -> V_178 == NULL ) {
F_11 ( & V_168 -> V_27 , L_37 ) ;
V_172 = - V_174 ;
goto V_177;
}
V_6 -> V_12 = F_67 ( V_171 -> V_179 , V_173 ) ;
if ( V_6 -> V_12 == NULL ) {
F_11 ( & V_168 -> V_27 , L_38 ) ;
V_172 = - V_176 ;
goto V_181;
}
if ( V_3 == V_4 )
V_6 -> V_98 = V_6 -> V_12 + V_182 ;
else
V_6 -> V_98 = V_6 -> V_12 + V_183 ;
F_5 ( L_39 ) ;
strcpy ( V_160 -> V_13 . V_184 , V_185 ) ;
V_51 = F_30 ( V_6 -> V_12 + V_85 ) ;
F_6 ( V_51 & ~ V_84 , V_6 -> V_12 + V_85 ) ;
V_160 -> V_13 . type = V_186 ;
V_160 -> V_13 . V_187 = 0 ;
V_160 -> V_13 . V_188 = 0 ;
V_160 -> V_13 . V_189 = 0 ;
V_160 -> V_13 . V_190 = 0 ;
V_160 -> V_13 . V_191 = V_192 ;
V_160 -> V_16 . V_193 = 0 ;
V_160 -> V_16 . V_194 = V_195 ;
V_160 -> V_16 . V_196 = 0 ;
V_160 -> V_16 . V_197 = V_198 ;
V_160 -> V_199 = & V_200 ;
V_160 -> V_96 = V_201 ;
V_160 -> V_107 = & V_6 -> V_202 ;
for ( V_33 = 0 ; V_33 < 256 ; V_33 ++ )
V_6 -> V_99 [ V_33 ] = V_150 ;
V_172 = F_68 ( V_151 , F_50 , 0 , V_168 -> V_180 , V_6 ) ;
if ( V_172 ) {
F_11 ( & V_168 -> V_27 , L_40 , V_151 , V_172 ) ;
V_172 = - V_203 ;
goto V_204;
}
V_6 -> V_22 = F_69 ( NULL , L_41 ) ;
if ( F_70 ( V_6 -> V_22 ) ) {
F_11 ( & V_168 -> V_27 , L_42 ) ;
V_172 = F_71 ( V_6 -> V_22 ) ;
goto V_205;
}
F_72 ( V_6 -> V_22 ) ;
F_5 ( L_43 ) ;
F_73 ( 1000 , 1100 ) ;
V_6 -> V_23 = F_55 ( V_6 -> V_22 ) ;
for ( V_33 = 0 ; V_33 < V_26 -> V_37 ; V_33 ++ ) {
unsigned long V_125 = V_26 -> V_32 [ V_33 ] . V_34 ;
V_125 *= V_26 -> V_32 [ V_33 ] . V_17 ;
V_125 *= V_26 -> V_32 [ V_33 ] . V_36 ;
V_125 >>= 3 ;
if ( V_160 -> V_13 . V_125 < V_125 )
V_160 -> V_13 . V_125 = V_125 ;
}
V_172 = F_41 ( V_160 ) ;
if ( V_172 ) {
F_11 ( & V_168 -> V_27 , L_44 , V_172 ) ;
V_172 = - V_128 ;
goto V_206;
}
F_5 ( L_45 ) ;
V_160 -> V_16 . V_34 = V_30 -> V_34 ;
V_160 -> V_16 . V_17 = V_30 -> V_17 ;
V_160 -> V_16 . V_35 = V_30 -> V_36 ;
F_47 ( V_160 ) ;
F_9 ( & V_160 -> V_16 , V_160 ) ;
V_172 = F_56 ( V_6 ) ;
if ( V_172 < 0 ) {
F_11 ( & V_168 -> V_27 , L_46 ) ;
goto V_207;
}
V_172 = F_74 ( V_160 ) ;
if ( V_172 < 0 ) {
F_11 ( & V_168 -> V_27 , L_47 ,
V_172 ) ;
goto V_208;
}
V_172 = F_75 ( & V_168 -> V_27 , & V_209 ) ;
if ( V_172 )
F_11 ( & V_168 -> V_27 , L_48 ) ;
F_76 ( & V_168 -> V_27 , L_49 ,
V_160 -> V_210 , V_160 -> V_13 . V_184 ) ;
return 0 ;
V_208:
F_58 ( V_6 ) ;
V_207:
F_44 ( V_160 ) ;
V_206:
F_77 ( V_6 -> V_22 ) ;
F_78 ( V_6 -> V_22 ) ;
V_205:
F_79 ( V_151 , V_6 ) ;
V_204:
F_80 ( V_6 -> V_12 ) ;
V_181:
F_81 ( V_171 -> V_179 , V_173 ) ;
V_177:
F_63 ( V_168 , NULL ) ;
F_82 ( V_160 ) ;
return V_172 ;
}
static int F_83 ( struct V_167 * V_168 )
{
return F_60 ( V_168 , V_211 ) ;
}
static int F_84 ( struct V_167 * V_168 )
{
return F_60 ( V_168 , V_4 ) ;
}
static int F_85 ( struct V_167 * V_168 )
{
struct V_5 * V_160 = F_53 ( V_168 ) ;
struct V_1 * V_6 = V_160 -> V_10 ;
int V_151 ;
F_86 ( V_160 ) ;
F_58 ( V_6 ) ;
F_35 ( V_6 , 0 ) ;
F_73 ( 1000 , 1100 ) ;
F_44 ( V_160 ) ;
if ( V_6 -> V_22 ) {
F_77 ( V_6 -> V_22 ) ;
F_78 ( V_6 -> V_22 ) ;
V_6 -> V_22 = NULL ;
}
V_151 = F_61 ( V_168 , 0 ) ;
F_79 ( V_151 , V_6 ) ;
F_80 ( V_6 -> V_12 ) ;
F_81 ( V_6 -> V_178 -> V_179 , F_65 ( V_6 -> V_178 ) ) ;
F_63 ( V_168 , NULL ) ;
F_82 ( V_160 ) ;
return 0 ;
}
static int F_87 ( struct V_167 * V_27 , T_6 V_212 )
{
struct V_5 * V_160 = F_53 ( V_27 ) ;
struct V_1 * V_6 = V_160 -> V_10 ;
F_35 ( V_6 , 0 ) ;
F_73 ( 1000 , 1100 ) ;
F_77 ( V_6 -> V_22 ) ;
return 0 ;
}
static int F_88 ( struct V_167 * V_27 )
{
struct V_5 * V_160 = F_53 ( V_27 ) ;
struct V_1 * V_6 = V_160 -> V_10 ;
F_72 ( V_6 -> V_22 ) ;
F_73 ( 1000 , 1100 ) ;
F_47 ( V_160 ) ;
F_24 ( V_160 ) ;
F_36 ( V_114 , V_160 ) ;
return 0 ;
}
int T_7 F_89 ( void )
{
int V_172 = F_90 ( & V_213 ) ;
if ( V_172 == 0 )
V_172 = F_90 ( & V_214 ) ;
return V_172 ;
}
static void T_8 F_91 ( void )
{
F_92 ( & V_213 ) ;
F_92 ( & V_214 ) ;
}
