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
struct V_25 * V_26 = F_10 ( V_2 -> V_27 ) ;
struct V_28 * V_29 = NULL ;
struct V_28 * V_30 = V_26 -> V_31 +
V_26 -> V_30 ;
int type = V_30 -> type ;
unsigned V_32 ;
F_5 ( L_5 , V_16 , V_6 ) ;
if ( V_16 -> V_17 == V_30 -> V_17 &&
V_16 -> V_33 == V_30 -> V_33 &&
V_16 -> V_34 == V_30 -> V_35 )
V_29 = V_30 ;
else
for ( V_32 = 0 ; V_32 < V_26 -> V_36 ; V_32 ++ )
if ( type == V_26 -> V_31 [ V_32 ] . type &&
V_16 -> V_17 == V_26 -> V_31 [ V_32 ] . V_17 &&
V_16 -> V_33 == V_26 -> V_31 [ V_32 ] . V_33 &&
V_16 -> V_34 == V_26 -> V_31 [ V_32 ] . V_35 ) {
V_29 = V_26 -> V_31 + V_32 ;
break;
}
if ( ! V_29 ) {
F_5 ( L_6 ,
V_16 -> V_33 , V_16 -> V_17 , V_16 -> V_34 ) ;
return - V_37 ;
}
V_16 -> V_38 = V_29 -> V_33 ;
V_16 -> V_39 = V_29 -> V_17 ;
V_16 -> V_40 = V_29 -> V_40 ;
V_16 -> V_41 = V_29 -> V_41 ;
V_16 -> V_42 = V_29 -> V_42 ;
V_16 -> V_43 = V_29 -> V_43 ;
V_16 -> V_44 = V_29 -> V_44 ;
V_16 -> V_45 = V_29 -> V_45 ;
V_16 -> V_46 = V_29 -> V_46 ;
V_16 -> V_47 = V_29 -> V_47 ;
V_16 -> V_48 = V_29 -> V_48 ;
V_2 -> V_11 . V_49 = V_29 -> V_49 ;
V_2 -> V_11 . V_50 = V_29 -> type ;
V_16 -> V_51 . V_52 = 0 ;
V_16 -> V_51 . V_53 = 0 ;
switch ( V_16 -> V_34 ) {
case 1 :
case 2 :
case 4 :
V_16 -> V_54 . V_52 = 0 ;
V_16 -> V_54 . V_53 = V_16 -> V_34 ;
V_16 -> V_55 = V_16 -> V_54 ;
V_16 -> V_56 = V_16 -> V_54 ;
break;
case 8 :
if ( V_29 -> type != V_57 ) {
V_16 -> V_54 . V_53 = 3 ;
V_16 -> V_54 . V_52 = 5 ;
V_16 -> V_55 . V_53 = 3 ;
V_16 -> V_55 . V_52 = 2 ;
V_16 -> V_56 . V_53 = 2 ;
V_16 -> V_56 . V_52 = 0 ;
} else {
V_16 -> V_54 . V_52 = 0 ;
V_16 -> V_54 . V_53 = 8 ;
V_16 -> V_55 = V_16 -> V_54 ;
V_16 -> V_56 = V_16 -> V_54 ;
}
break;
case 12 :
V_16 -> V_54 . V_53 = 4 ;
V_16 -> V_54 . V_52 = 8 ;
V_16 -> V_55 . V_53 = 4 ;
V_16 -> V_55 . V_52 = 4 ;
V_16 -> V_56 . V_53 = 4 ;
V_16 -> V_56 . V_52 = 0 ;
break;
default:
case 16 :
if ( V_29 -> V_49 & V_58 ) {
V_16 -> V_54 . V_52 = 11 ;
V_16 -> V_55 . V_52 = 5 ;
V_16 -> V_56 . V_52 = 0 ;
V_16 -> V_54 . V_53 = 5 ;
V_16 -> V_55 . V_53 = 6 ;
V_16 -> V_56 . V_53 = 5 ;
} else {
V_16 -> V_54 . V_52 = 11 ;
V_16 -> V_55 . V_52 = 6 ;
V_16 -> V_56 . V_52 = 1 ;
V_16 -> V_54 . V_53 = 5 ;
V_16 -> V_55 . V_53 = 5 ;
V_16 -> V_56 . V_53 = 5 ;
}
break;
case 32 :
V_16 -> V_54 . V_53 = 8 ;
V_16 -> V_54 . V_52 = 16 ;
V_16 -> V_55 . V_53 = 8 ;
V_16 -> V_55 . V_52 = 8 ;
V_16 -> V_56 . V_53 = 8 ;
V_16 -> V_56 . V_52 = 0 ;
break;
}
return 0 ;
}
static void F_11 ( const struct V_5 * V_6 ,
struct V_59 * V_11 )
{
const struct V_1 * V_2 = V_6 -> V_10 ;
const struct V_24 * V_16 = & V_6 -> V_16 ;
int type = V_11 -> V_50 & ~ V_57 ;
int V_60 = V_16 -> V_33 >> 2 ;
unsigned V_61 = ( V_16 -> V_43 >> 4 ) - 1 ;
unsigned V_62 = ( V_16 -> V_48 >> 4 ) - 1 ;
if ( type != V_63 )
V_60 >>= 1 ;
switch ( V_16 -> V_34 ) {
case 1 :
V_11 -> V_50 |= V_64 ;
break;
case 2 :
V_11 -> V_50 |= V_65 ;
break;
case 4 :
V_11 -> V_50 |= V_66 ;
break;
case 8 :
V_11 -> V_50 |= V_67 ;
V_60 *= 3 ;
break;
case 12 :
V_11 -> V_50 |= V_68 ;
V_60 *= 3 ;
break;
default:
F_12 ( V_2 -> V_27 , L_7 ,
V_16 -> V_34 ) ;
}
F_5 ( L_8 ,
V_16 -> V_43 , V_16 -> V_44 , V_16 -> V_48 ) ;
V_11 -> V_69 = F_13 ( V_16 -> V_17 - 1 ) ;
if ( V_61 > 3 )
V_61 = 3 ;
if ( V_62 > 3 )
V_62 = 3 ;
V_11 -> V_70 = F_14 ( V_61 ) |
F_15 ( V_16 -> V_44 / 8 ) |
F_16 ( V_60 - 1 ) ;
V_11 -> V_71 = F_17 ( V_62 ) ;
}
static void F_18 ( const struct V_5 * V_6 ,
struct V_59 * V_11 )
{
const struct V_1 * V_2 = V_6 -> V_10 ;
const struct V_24 * V_16 = & V_6 -> V_16 ;
switch ( V_16 -> V_34 ) {
case 1 :
V_11 -> V_50 |= V_72 ;
break;
case 2 :
V_11 -> V_50 |= V_73 ;
break;
case 4 :
V_11 -> V_50 |= V_74 ;
break;
case 8 :
V_11 -> V_50 |= V_75 ;
V_11 -> V_49 |= V_76 |
V_58 ;
V_11 -> V_49 &= ~ V_77 ;
break;
case 16 :
V_11 -> V_50 |= V_78 ;
V_11 -> V_49 &= ~ V_76 ;
V_11 -> V_49 |= V_77 ;
break;
case 32 :
V_11 -> V_50 |= V_79 ;
V_11 -> V_49 &= ~ ( V_76 |
V_77 |
V_80 ) ;
break;
default:
F_12 ( V_2 -> V_27 , L_7 ,
V_16 -> V_34 ) ;
}
F_5 ( L_9 ,
V_16 -> V_45 , V_16 -> V_46 , V_16 -> V_47 ) ;
F_5 ( L_8 ,
V_16 -> V_43 , V_16 -> V_44 , V_16 -> V_48 ) ;
V_11 -> V_69 = F_13 ( V_16 -> V_17 - 1 ) |
F_19 ( V_16 -> V_45 - 1 ) |
F_20 ( V_16 -> V_46 - 1 ) |
F_21 ( V_16 -> V_47 - 1 ) ;
V_11 -> V_70 = F_22 ( V_16 -> V_44 - 1 ) |
F_23 ( V_16 -> V_43 - 1 ) |
F_16 ( V_16 -> V_33 - 1 ) ;
V_11 -> V_71 = F_24 ( V_16 -> V_48 - 1 ) ;
}
static void F_25 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
void T_1 * V_11 = V_2 -> V_12 ;
int type = V_2 -> V_11 . V_50 & V_57 ;
struct V_24 * V_16 = & V_6 -> V_16 ;
int V_81 ;
V_81 = F_26 ( F_7 ( V_2 , V_16 -> V_42 ) , 2 ) ;
F_5 ( L_10 , V_82 , V_16 -> V_33 ) ;
F_5 ( L_11 , V_82 , V_16 -> V_17 ) ;
F_5 ( L_12 , V_82 , V_16 -> V_34 ) ;
if ( type == V_57 ) {
F_18 ( V_6 , & V_2 -> V_11 ) ;
-- V_81 ;
if ( V_81 < 0 )
V_81 = 0 ;
} else {
F_11 ( V_6 , & V_2 -> V_11 ) ;
if ( V_81 < 2 )
V_81 = 2 ;
}
V_2 -> V_11 . V_50 |= F_27 ( V_81 ) ;
F_5 ( L_13 ) ;
F_5 ( L_14 , V_2 -> V_11 . V_50 ) ;
F_5 ( L_15 , V_2 -> V_11 . V_69 ) ;
F_5 ( L_16 , V_2 -> V_11 . V_70 ) ;
F_5 ( L_17 , V_2 -> V_11 . V_71 ) ;
F_5 ( L_18 , V_2 -> V_11 . V_49 ) ;
F_6 ( V_2 -> V_11 . V_50 & ~ V_83 ,
V_11 + V_84 ) ;
F_6 ( V_2 -> V_11 . V_69 , V_11 + V_85 ) ;
F_6 ( V_2 -> V_11 . V_70 , V_11 + V_86 ) ;
F_6 ( V_2 -> V_11 . V_71 , V_11 + V_87 ) ;
F_6 ( V_2 -> V_11 . V_49 , V_11 + V_88 ) ;
F_2 ( V_6 ) ;
V_2 -> V_11 . V_50 |= V_83 ,
F_6 ( V_2 -> V_11 . V_50 , V_11 + V_84 ) ;
}
static int F_28 ( struct V_5 * V_6 )
{
struct V_24 * V_16 = & V_6 -> V_16 ;
switch ( V_16 -> V_34 ) {
case 32 :
case 16 :
case 12 :
V_6 -> V_13 . V_89 = V_90 ;
break;
case 1 :
V_6 -> V_13 . V_89 = V_91 ;
break;
default:
V_6 -> V_13 . V_89 = V_92 ;
break;
}
V_6 -> V_13 . V_15 = ( V_16 -> V_38 * V_16 -> V_34 ) / 8 ;
F_25 ( V_6 ) ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 ,
unsigned int V_93 , unsigned int V_94 )
{
unsigned long V_95 ;
unsigned long V_96 ;
void T_1 * V_97 = V_2 -> V_97 ;
F_30 ( V_95 ) ;
V_2 -> V_98 [ V_93 ] = V_94 ;
if ( ! V_2 -> V_99 ) {
V_2 -> V_99 = 1 ;
V_96 = F_31 ( V_97 + V_100 ) ;
V_96 &= ~ V_101 ;
F_6 ( V_96 , V_97 + V_100 ) ;
}
F_32 ( V_95 ) ;
}
static inline unsigned int F_33 ( unsigned int V_102 ,
struct V_103 * V_104 )
{
V_102 &= 0xffff ;
V_102 >>= 16 - V_104 -> V_53 ;
return V_102 << V_104 -> V_52 ;
}
static int F_34 ( unsigned V_93 ,
unsigned V_54 , unsigned V_55 , unsigned V_56 ,
unsigned V_51 , struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
void T_1 * V_11 = V_2 -> V_12 ;
unsigned int V_94 ;
switch ( V_6 -> V_13 . V_89 ) {
case V_90 :
if ( V_93 < 16 ) {
T_2 * V_105 = V_6 -> V_106 ;
V_94 = F_33 ( V_54 , & V_6 -> V_16 . V_54 ) ;
V_94 |= F_33 ( V_55 , & V_6 -> V_16 . V_55 ) ;
V_94 |= F_33 ( V_56 , & V_6 -> V_16 . V_56 ) ;
V_105 [ V_93 ] = V_94 ;
}
break;
case V_92 :
if ( V_93 < 256 ) {
V_94 = ( V_54 >> 0 ) & 0xf800 ;
V_94 |= ( V_55 >> 5 ) & 0x07e0 ;
V_94 |= ( V_56 >> 11 ) & 0x001f ;
F_6 ( V_94 , V_11 + F_35 ( V_93 ) ) ;
F_29 ( V_2 , V_93 , V_94 ) ;
}
break;
default:
return 1 ;
}
return 0 ;
}
static void F_36 ( struct V_1 * V_2 , int V_107 )
{
unsigned long V_95 ;
F_30 ( V_95 ) ;
if ( V_107 )
V_2 -> V_11 . V_50 |= V_83 ;
else
V_2 -> V_11 . V_50 &= ~ V_83 ;
F_6 ( V_2 -> V_11 . V_50 , V_2 -> V_12 + V_84 ) ;
F_32 ( V_95 ) ;
}
static int F_37 ( int V_108 , struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
void T_1 * V_109 = V_2 -> V_12 ;
F_5 ( L_19 , V_108 , V_6 ) ;
V_109 += F_1 ( V_2 ) ? V_110 : V_111 ;
if ( V_108 == V_112 )
F_36 ( V_2 , 0 ) ;
else
F_36 ( V_2 , 1 ) ;
if ( V_108 == V_113 )
F_6 ( 0x0 , V_109 ) ;
else {
F_5 ( L_20 ) ;
F_6 ( V_114 , V_109 ) ;
}
return 0 ;
}
static int F_38 ( struct V_115 * V_27 ,
struct V_116 * V_117 , char * V_118 )
{
return snprintf ( V_118 , V_119 , L_21 , V_120 ? L_22 : L_23 ) ;
}
static int F_39 ( struct V_115 * V_27 ,
struct V_116 * V_117 ,
const char * V_118 , T_3 V_121 )
{
if ( V_121 < 1 )
return - V_37 ;
if ( F_40 ( V_118 , L_22 , 2 ) == 0 ||
F_40 ( V_118 , L_24 , 1 ) == 0 ) {
V_120 = 1 ;
F_41 ( V_27 , L_25 ) ;
} else if ( F_40 ( V_118 , L_23 , 3 ) == 0 ||
F_40 ( V_118 , L_26 , 1 ) == 0 ) {
V_120 = 0 ;
F_41 ( V_27 , L_27 ) ;
} else {
return - V_37 ;
}
return V_121 ;
}
static int F_42 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
T_4 V_122 ;
unsigned V_123 = F_43 ( V_6 -> V_13 . V_124 ) ;
F_5 ( L_28 , V_2 , V_123 ) ;
V_6 -> V_125 = F_44 ( V_2 -> V_27 , V_123 ,
& V_122 , V_126 ) ;
if ( V_6 -> V_125 ) {
F_5 ( L_29 ,
V_6 -> V_125 , V_123 ) ;
memset ( V_6 -> V_125 , 0x00 , V_123 ) ;
V_6 -> V_13 . V_14 = V_122 ;
F_5 ( L_30 ,
V_6 -> V_13 . V_14 , V_6 -> V_125 , V_123 ) ;
}
return V_6 -> V_125 ? 0 : - V_127 ;
}
static inline void F_45 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
F_46 ( V_2 -> V_27 , F_43 ( V_6 -> V_13 . V_124 ) ,
V_6 -> V_125 , V_6 -> V_13 . V_14 ) ;
}
static inline void F_47 ( void T_1 * V_128 ,
unsigned long V_129 , unsigned long V_130 )
{
unsigned long V_131 ;
V_131 = F_31 ( V_128 ) & ~ V_130 ;
F_6 ( V_131 | V_129 , V_128 ) ;
}
static int F_48 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
struct V_25 * V_26 = F_10 ( V_2 -> V_27 ) ;
unsigned long V_95 ;
void T_1 * V_11 = V_2 -> V_12 ;
void T_1 * V_132 ;
void T_1 * V_133 ;
if ( F_1 ( V_2 ) ) {
V_132 = V_11 + V_110 ;
V_133 = V_11 + V_134 ;
} else {
V_132 = V_11 + V_111 ;
V_133 = V_11 + V_135 ;
}
F_30 ( V_95 ) ;
F_47 ( V_136 , V_26 -> V_137 , V_26 -> V_138 ) ;
F_47 ( V_139 , V_26 -> V_140 , V_26 -> V_141 ) ;
F_47 ( V_142 , V_26 -> V_143 , V_26 -> V_144 ) ;
F_47 ( V_145 , V_26 -> V_146 , V_26 -> V_147 ) ;
F_32 ( V_95 ) ;
F_5 ( L_31 , V_26 -> V_133 ) ;
F_6 ( V_26 -> V_133 , V_133 ) ;
F_5 ( L_32 , F_31 ( V_132 ) ) ;
F_6 ( 0x00 , V_132 ) ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 )
{
unsigned int V_32 ;
void T_1 * V_11 = V_2 -> V_12 ;
V_2 -> V_99 = 0 ;
for ( V_32 = 0 ; V_32 < 256 ; V_32 ++ ) {
unsigned long V_148 = V_2 -> V_98 [ V_32 ] ;
if ( V_148 == V_149 )
continue;
F_6 ( V_148 , V_11 + F_35 ( V_32 ) ) ;
if ( F_50 ( V_11 + F_35 ( V_32 ) ) == V_148 )
V_2 -> V_98 [ V_32 ] = V_149 ;
else
V_2 -> V_99 = 1 ;
}
}
static T_5 F_51 ( int V_150 , void * V_151 )
{
struct V_1 * V_2 = V_151 ;
void T_1 * V_97 = V_2 -> V_97 ;
unsigned long V_152 = F_31 ( V_97 + V_153 ) ;
if ( V_152 & V_101 ) {
if ( V_2 -> V_99 )
F_49 ( V_2 ) ;
F_6 ( V_101 , V_97 + V_153 ) ;
F_6 ( V_101 , V_97 + V_154 ) ;
}
return V_155 ;
}
static int F_52 ( struct V_156 * V_157 ,
unsigned long V_94 , void * V_158 )
{
struct V_1 * V_6 ;
struct V_5 * V_159 ;
long V_160 ;
V_6 = F_53 ( V_157 , struct V_1 , V_161 ) ;
V_159 = F_54 ( F_55 ( V_6 -> V_27 ) ) ;
V_160 = V_6 -> V_23 - F_56 ( V_6 -> V_22 ) ;
if ( ( V_94 == V_162 && V_160 > 0 ) ||
( V_94 == V_163 && V_160 < 0 ) ) {
V_6 -> V_23 = F_56 ( V_6 -> V_22 ) ;
F_25 ( V_159 ) ;
}
return 0 ;
}
static inline int F_57 ( struct V_1 * V_6 )
{
V_6 -> V_161 . V_164 = F_52 ;
return F_58 ( & V_6 -> V_161 ,
V_165 ) ;
}
static inline void F_59 ( struct V_1 * V_6 )
{
F_60 ( & V_6 -> V_161 ,
V_165 ) ;
}
static inline int F_57 ( struct V_1 * V_6 )
{
return 0 ;
}
static inline void F_59 ( struct V_1 * V_6 )
{
}
static int F_61 ( struct V_166 * V_167 ,
enum V_168 V_3 )
{
struct V_1 * V_6 ;
struct V_28 * V_29 ;
struct V_5 * V_159 ;
struct V_25 * V_26 ;
struct V_169 * V_170 ;
int V_171 ;
int V_150 ;
int V_32 ;
int V_172 ;
T_2 V_50 ;
V_26 = F_10 ( & V_167 -> V_27 ) ;
if ( V_26 == NULL ) {
F_12 ( & V_167 -> V_27 ,
L_33 ) ;
return - V_37 ;
}
if ( V_26 -> V_30 >= V_26 -> V_36 ) {
F_12 ( & V_167 -> V_27 , L_34 ,
V_26 -> V_30 , V_26 -> V_36 ) ;
return - V_37 ;
}
V_29 = V_26 -> V_31 + V_26 -> V_30 ;
V_150 = F_62 ( V_167 , 0 ) ;
if ( V_150 < 0 ) {
F_12 ( & V_167 -> V_27 , L_35 ) ;
return - V_173 ;
}
V_159 = F_63 ( sizeof( struct V_1 ) , & V_167 -> V_27 ) ;
if ( ! V_159 )
return - V_127 ;
F_64 ( V_167 , V_159 ) ;
V_6 = V_159 -> V_10 ;
V_6 -> V_27 = & V_167 -> V_27 ;
V_6 -> V_3 = V_3 ;
V_170 = F_65 ( V_167 , V_174 , 0 ) ;
if ( V_170 == NULL ) {
F_12 ( & V_167 -> V_27 , L_36 ) ;
V_171 = - V_175 ;
goto V_176;
}
V_172 = F_66 ( V_170 ) ;
V_6 -> V_177 = F_67 ( V_170 -> V_178 , V_172 , V_167 -> V_179 ) ;
if ( V_6 -> V_177 == NULL ) {
F_12 ( & V_167 -> V_27 , L_37 ) ;
V_171 = - V_173 ;
goto V_176;
}
V_6 -> V_12 = F_68 ( V_170 -> V_178 , V_172 ) ;
if ( V_6 -> V_12 == NULL ) {
F_12 ( & V_167 -> V_27 , L_38 ) ;
V_171 = - V_175 ;
goto V_180;
}
if ( V_3 == V_4 )
V_6 -> V_97 = V_6 -> V_12 + V_181 ;
else
V_6 -> V_97 = V_6 -> V_12 + V_182 ;
F_5 ( L_39 ) ;
strcpy ( V_159 -> V_13 . V_183 , V_184 ) ;
V_50 = F_31 ( V_6 -> V_12 + V_84 ) ;
F_6 ( V_50 & ~ V_83 , V_6 -> V_12 + V_84 ) ;
V_159 -> V_13 . type = V_185 ;
V_159 -> V_13 . V_186 = 0 ;
V_159 -> V_13 . V_187 = 0 ;
V_159 -> V_13 . V_188 = 0 ;
V_159 -> V_13 . V_189 = 0 ;
V_159 -> V_13 . V_190 = V_191 ;
V_159 -> V_16 . V_192 = 0 ;
V_159 -> V_16 . V_193 = V_194 ;
V_159 -> V_16 . V_195 = 0 ;
V_159 -> V_16 . V_196 = V_197 ;
V_159 -> V_198 = & V_199 ;
V_159 -> V_95 = V_200 ;
V_159 -> V_106 = & V_6 -> V_201 ;
for ( V_32 = 0 ; V_32 < 256 ; V_32 ++ )
V_6 -> V_98 [ V_32 ] = V_149 ;
V_171 = F_69 ( V_150 , F_51 , 0 , V_167 -> V_179 , V_6 ) ;
if ( V_171 ) {
F_12 ( & V_167 -> V_27 , L_40 , V_150 , V_171 ) ;
V_171 = - V_202 ;
goto V_203;
}
V_6 -> V_22 = F_70 ( NULL , L_41 ) ;
if ( F_71 ( V_6 -> V_22 ) ) {
F_12 ( & V_167 -> V_27 , L_42 ) ;
V_171 = F_72 ( V_6 -> V_22 ) ;
goto V_204;
}
F_73 ( V_6 -> V_22 ) ;
F_5 ( L_43 ) ;
F_74 ( 1000 , 1100 ) ;
V_6 -> V_23 = F_56 ( V_6 -> V_22 ) ;
for ( V_32 = 0 ; V_32 < V_26 -> V_36 ; V_32 ++ ) {
unsigned long V_124 = V_26 -> V_31 [ V_32 ] . V_33 ;
V_124 *= V_26 -> V_31 [ V_32 ] . V_17 ;
V_124 *= V_26 -> V_31 [ V_32 ] . V_35 ;
V_124 >>= 3 ;
if ( V_159 -> V_13 . V_124 < V_124 )
V_159 -> V_13 . V_124 = V_124 ;
}
V_171 = F_42 ( V_159 ) ;
if ( V_171 ) {
F_12 ( & V_167 -> V_27 , L_44 , V_171 ) ;
V_171 = - V_127 ;
goto V_205;
}
F_5 ( L_45 ) ;
V_159 -> V_16 . V_33 = V_29 -> V_33 ;
V_159 -> V_16 . V_17 = V_29 -> V_17 ;
V_159 -> V_16 . V_34 = V_29 -> V_35 ;
F_48 ( V_159 ) ;
F_9 ( & V_159 -> V_16 , V_159 ) ;
V_171 = F_57 ( V_6 ) ;
if ( V_171 < 0 ) {
F_12 ( & V_167 -> V_27 , L_46 ) ;
goto V_206;
}
V_171 = F_75 ( V_159 ) ;
if ( V_171 < 0 ) {
F_12 ( & V_167 -> V_27 , L_47 ,
V_171 ) ;
goto V_207;
}
V_171 = F_76 ( & V_167 -> V_27 , & V_208 ) ;
if ( V_171 )
F_12 ( & V_167 -> V_27 , L_48 ) ;
F_77 ( & V_167 -> V_27 , L_49 ,
V_159 -> V_209 , V_159 -> V_13 . V_183 ) ;
return 0 ;
V_207:
F_59 ( V_6 ) ;
V_206:
F_45 ( V_159 ) ;
V_205:
F_78 ( V_6 -> V_22 ) ;
F_79 ( V_6 -> V_22 ) ;
V_204:
F_80 ( V_150 , V_6 ) ;
V_203:
F_81 ( V_6 -> V_12 ) ;
V_180:
F_82 ( V_170 -> V_178 , V_172 ) ;
V_176:
F_83 ( V_159 ) ;
return V_171 ;
}
static int F_84 ( struct V_166 * V_167 )
{
return F_61 ( V_167 , V_210 ) ;
}
static int F_85 ( struct V_166 * V_167 )
{
return F_61 ( V_167 , V_4 ) ;
}
static int F_86 ( struct V_166 * V_167 )
{
struct V_5 * V_159 = F_54 ( V_167 ) ;
struct V_1 * V_6 = V_159 -> V_10 ;
int V_150 ;
F_87 ( V_159 ) ;
F_59 ( V_6 ) ;
F_36 ( V_6 , 0 ) ;
F_74 ( 1000 , 1100 ) ;
F_45 ( V_159 ) ;
if ( V_6 -> V_22 ) {
F_78 ( V_6 -> V_22 ) ;
F_79 ( V_6 -> V_22 ) ;
V_6 -> V_22 = NULL ;
}
V_150 = F_62 ( V_167 , 0 ) ;
F_80 ( V_150 , V_6 ) ;
F_81 ( V_6 -> V_12 ) ;
F_82 ( V_6 -> V_177 -> V_178 , F_66 ( V_6 -> V_177 ) ) ;
F_83 ( V_159 ) ;
return 0 ;
}
static int F_88 ( struct V_166 * V_27 , T_6 V_211 )
{
struct V_5 * V_159 = F_54 ( V_27 ) ;
struct V_1 * V_6 = V_159 -> V_10 ;
F_36 ( V_6 , 0 ) ;
F_74 ( 1000 , 1100 ) ;
F_78 ( V_6 -> V_22 ) ;
return 0 ;
}
static int F_89 ( struct V_166 * V_27 )
{
struct V_5 * V_159 = F_54 ( V_27 ) ;
struct V_1 * V_6 = V_159 -> V_10 ;
F_73 ( V_6 -> V_22 ) ;
F_74 ( 1000 , 1100 ) ;
F_48 ( V_159 ) ;
F_25 ( V_159 ) ;
F_37 ( V_113 , V_159 ) ;
return 0 ;
}
int T_7 F_90 ( void )
{
int V_171 = F_91 ( & V_212 ) ;
if ( V_171 == 0 )
V_171 = F_91 ( & V_213 ) ;
return V_171 ;
}
static void T_8 F_92 ( void )
{
F_93 ( & V_212 ) ;
F_93 ( & V_213 ) ;
}
