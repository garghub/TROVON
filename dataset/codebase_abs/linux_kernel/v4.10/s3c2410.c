static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
if ( V_3 )
return - V_6 ;
V_5 -> V_7 = 0 ;
V_5 -> V_8 = 3 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
if ( V_3 )
return - V_6 ;
V_5 -> V_7 = 8 ;
V_5 -> V_8 = 8 ;
return 0 ;
}
static struct V_9 * F_3 ( struct V_1 * V_2 )
{
return F_4 ( F_5 ( V_2 ) , struct V_9 ,
V_10 ) ;
}
static struct V_11 * F_6 ( struct V_1 * V_2 )
{
return F_3 ( V_2 ) -> V_12 ;
}
static struct V_11 * F_7 ( struct V_13 * V_14 )
{
return F_8 ( V_14 ) ;
}
static struct V_15 * F_9 ( struct V_13 * V_14 )
{
return F_10 ( & V_14 -> V_14 ) ;
}
static inline int F_11 ( struct V_11 * V_12 )
{
#ifdef F_12
return 1 ;
#else
return 0 ;
#endif
}
static void F_13 ( struct V_11 * V_12 ,
enum V_16 V_17 )
{
if ( ! F_11 ( V_12 ) && V_17 == V_18 )
return;
if ( V_12 -> V_19 == V_20 ) {
if ( V_17 != V_20 )
F_14 ( V_12 -> V_21 ) ;
} else {
if ( V_17 == V_20 )
F_15 ( V_12 -> V_21 ) ;
}
V_12 -> V_19 = V_17 ;
}
static int F_16 ( int V_22 , unsigned long V_21 , int V_23 )
{
int V_24 ;
V_24 = F_17 ( ( V_22 * V_21 ) , V_25 ) ;
F_18 ( L_1 , V_24 , V_21 , V_22 ) ;
if ( V_24 > V_23 ) {
F_19 ( L_2 ,
V_22 , V_21 ) ;
return - 1 ;
}
if ( V_24 < 1 )
V_24 = 1 ;
return V_24 ;
}
static int F_20 ( struct V_11 * V_12 )
{
struct V_15 * V_26 = V_12 -> V_27 ;
int V_28 = ( V_12 -> V_29 == V_30 ) ? 8 : 4 ;
int V_31 , V_32 , V_33 ;
unsigned long V_34 = F_21 ( V_12 -> V_21 ) ;
unsigned long V_35 ( V_36 ) , V_37 , V_35 ( V_38 ) ;
unsigned long V_39 ;
V_12 -> V_40 = V_34 ;
V_34 /= 1000 ;
if ( V_26 != NULL ) {
V_31 = F_16 ( V_26 -> V_31 , V_34 , V_28 ) ;
V_32 = F_16 ( V_26 -> V_32 , V_34 , 8 ) ;
V_33 = F_16 ( V_26 -> V_33 , V_34 , 8 ) ;
} else {
V_31 = V_28 ;
V_32 = 8 ;
V_33 = 8 ;
}
if ( V_31 < 0 || V_32 < 0 || V_33 < 0 ) {
F_22 ( V_12 -> V_41 , L_3 ) ;
return - V_42 ;
}
F_23 ( V_12 -> V_41 , L_4 ,
V_31 , F_24 ( V_31 , V_34 ) , V_32 , F_24 ( V_32 , V_34 ) ,
V_33 , F_24 ( V_33 , V_34 ) ) ;
switch ( V_12 -> V_29 ) {
case V_43 :
V_38 = ( F_25 ( 3 ) |
F_26 ( 7 ) |
F_27 ( 7 ) ) ;
V_36 = V_44 ;
V_36 |= F_25 ( V_31 - 1 ) ;
V_36 |= F_26 ( V_32 - 1 ) ;
V_36 |= F_27 ( V_33 - 1 ) ;
break;
case V_45 :
case V_30 :
V_38 = ( F_28 ( V_28 - 1 ) |
F_29 ( 7 ) |
F_30 ( 7 ) ) ;
V_36 = F_28 ( V_31 - 1 ) ;
V_36 |= F_29 ( V_32 - 1 ) ;
V_36 |= F_30 ( V_33 - 1 ) ;
break;
default:
F_31 () ;
}
F_32 ( V_39 ) ;
V_37 = F_33 ( V_12 -> V_46 + V_47 ) ;
V_37 &= ~ V_38 ;
V_37 |= V_36 ;
F_34 ( V_37 , V_12 -> V_46 + V_47 ) ;
F_35 ( V_39 ) ;
F_36 ( V_12 -> V_41 , L_5 , V_37 ) ;
return 0 ;
}
static int F_37 ( struct V_11 * V_12 )
{
int V_48 ;
V_48 = F_20 ( V_12 ) ;
if ( V_48 < 0 )
return V_48 ;
switch ( V_12 -> V_29 ) {
case V_43 :
default:
break;
case V_45 :
case V_30 :
F_34 ( V_49 , V_12 -> V_46 + V_50 ) ;
}
return 0 ;
}
static void F_38 ( struct V_1 * V_2 , int V_10 )
{
struct V_11 * V_12 ;
struct V_9 * V_51 ;
struct V_52 * V_53 = F_5 ( V_2 ) ;
unsigned long V_54 ;
V_51 = F_39 ( V_53 ) ;
V_12 = V_51 -> V_12 ;
if ( V_10 != - 1 )
F_13 ( V_12 , V_20 ) ;
V_54 = F_33 ( V_12 -> V_55 ) ;
if ( V_10 == - 1 ) {
V_54 |= V_12 -> V_56 ;
} else {
if ( V_51 -> V_36 != NULL && V_10 > V_51 -> V_36 -> V_57 ) {
F_22 ( V_12 -> V_41 , L_6 , V_10 ) ;
return;
}
if ( V_12 -> V_27 != NULL ) {
if ( V_12 -> V_27 -> V_58 != NULL )
( V_12 -> V_27 -> V_58 ) ( V_51 -> V_36 , V_10 ) ;
}
V_54 &= ~ V_12 -> V_56 ;
}
F_34 ( V_54 , V_12 -> V_55 ) ;
if ( V_10 == - 1 )
F_13 ( V_12 , V_18 ) ;
}
static void F_40 ( struct V_1 * V_2 , int V_59 ,
unsigned int V_60 )
{
struct V_11 * V_12 = F_6 ( V_2 ) ;
if ( V_59 == V_61 )
return;
if ( V_60 & V_62 )
F_41 ( V_59 , V_12 -> V_46 + V_63 ) ;
else
F_41 ( V_59 , V_12 -> V_46 + V_64 ) ;
}
static void F_42 ( struct V_1 * V_2 , int V_59 ,
unsigned int V_60 )
{
struct V_11 * V_12 = F_6 ( V_2 ) ;
if ( V_59 == V_61 )
return;
if ( V_60 & V_62 )
F_41 ( V_59 , V_12 -> V_46 + V_65 ) ;
else
F_41 ( V_59 , V_12 -> V_46 + V_66 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_6 ( V_2 ) ;
return F_44 ( V_12 -> V_46 + V_67 ) & V_68 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_6 ( V_2 ) ;
return F_44 ( V_12 -> V_46 + V_69 ) & V_70 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_6 ( V_2 ) ;
return F_44 ( V_12 -> V_46 + V_71 ) & V_72 ;
}
static int F_47 ( struct V_1 * V_2 , T_1 * V_73 ,
T_1 * V_74 , T_1 * V_75 )
{
struct V_11 * V_12 = F_6 ( V_2 ) ;
unsigned int V_76 , V_77 , V_78 ;
unsigned int V_79 , V_80 ;
F_18 ( L_7 , V_81 , V_2 , V_73 , V_74 , V_75 ) ;
V_76 = V_74 [ 0 ] ^ V_75 [ 0 ] ;
V_77 = V_74 [ 1 ] ^ V_75 [ 1 ] ;
V_78 = V_74 [ 2 ] ^ V_75 [ 2 ] ;
F_18 ( L_8 ,
V_81 , 3 , V_74 , 3 , V_75 ,
V_76 , V_77 , V_78 ) ;
if ( V_76 == 0 && V_77 == 0 && V_78 == 0 )
return 0 ;
if ( V_74 [ 0 ] == 0xff && V_74 [ 1 ] == 0xff && V_74 [ 2 ] == 0xff
&& V_12 -> V_27 -> V_82 )
return 0 ;
if ( ( ( V_76 ^ ( V_76 >> 1 ) ) & 0x55 ) == 0x55 &&
( ( V_77 ^ ( V_77 >> 1 ) ) & 0x55 ) == 0x55 &&
( ( V_78 ^ ( V_78 >> 1 ) ) & 0x55 ) == 0x55 ) {
V_79 = ( ( V_78 >> 3 ) & 1 ) |
( ( V_78 >> 4 ) & 2 ) |
( ( V_78 >> 5 ) & 4 ) ;
V_80 = ( ( V_78 << 7 ) & 0x100 ) |
( ( V_77 << 0 ) & 0x80 ) |
( ( V_77 << 1 ) & 0x40 ) |
( ( V_77 << 2 ) & 0x20 ) |
( ( V_77 << 3 ) & 0x10 ) |
( ( V_76 >> 4 ) & 0x08 ) |
( ( V_76 >> 3 ) & 0x04 ) |
( ( V_76 >> 2 ) & 0x02 ) |
( ( V_76 >> 1 ) & 0x01 ) ;
F_36 ( V_12 -> V_41 , L_9 ,
V_79 , V_80 ) ;
V_73 [ V_80 ] ^= ( 1 << V_79 ) ;
return 1 ;
}
V_76 |= ( V_77 << 8 ) ;
V_76 |= ( V_78 << 16 ) ;
if ( ( V_76 & ( V_76 - 1 ) ) == 0 )
return 1 ;
return - 1 ;
}
static void F_48 ( struct V_1 * V_2 , int V_83 )
{
struct V_11 * V_12 = F_6 ( V_2 ) ;
unsigned long V_60 ;
V_60 = F_33 ( V_12 -> V_46 + V_47 ) ;
V_60 |= V_84 ;
F_34 ( V_60 , V_12 -> V_46 + V_47 ) ;
}
static void F_49 ( struct V_1 * V_2 , int V_83 )
{
struct V_11 * V_12 = F_6 ( V_2 ) ;
unsigned long V_60 ;
V_60 = F_33 ( V_12 -> V_46 + V_50 ) ;
F_34 ( V_60 | V_85 ,
V_12 -> V_46 + V_50 ) ;
}
static void F_50 ( struct V_1 * V_2 , int V_83 )
{
struct V_11 * V_12 = F_6 ( V_2 ) ;
unsigned long V_60 ;
V_60 = F_33 ( V_12 -> V_46 + V_50 ) ;
F_34 ( V_60 | V_86 , V_12 -> V_46 + V_50 ) ;
}
static int F_51 ( struct V_1 * V_2 , const T_1 * V_73 ,
T_1 * V_87 )
{
struct V_11 * V_12 = F_6 ( V_2 ) ;
V_87 [ 0 ] = F_44 ( V_12 -> V_46 + V_88 + 0 ) ;
V_87 [ 1 ] = F_44 ( V_12 -> V_46 + V_88 + 1 ) ;
V_87 [ 2 ] = F_44 ( V_12 -> V_46 + V_88 + 2 ) ;
F_18 ( L_10 , V_81 , 3 , V_87 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , const T_1 * V_73 ,
T_1 * V_87 )
{
struct V_11 * V_12 = F_6 ( V_2 ) ;
unsigned long V_89 = F_33 ( V_12 -> V_46 + V_90 ) ;
V_87 [ 0 ] = V_89 ;
V_87 [ 1 ] = V_89 >> 8 ;
V_87 [ 2 ] = V_89 >> 16 ;
F_18 ( L_10 , V_81 , 3 , V_87 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , const T_1 * V_73 ,
T_1 * V_87 )
{
struct V_11 * V_12 = F_6 ( V_2 ) ;
unsigned long V_89 = F_33 ( V_12 -> V_46 + V_91 ) ;
V_87 [ 0 ] = V_89 ;
V_87 [ 1 ] = V_89 >> 8 ;
V_87 [ 2 ] = V_89 >> 16 ;
F_18 ( L_11 , V_81 , V_89 & 0xffffff ) ;
return 0 ;
}
static void F_54 ( struct V_1 * V_2 , T_1 * V_92 , int V_93 )
{
struct V_52 * V_53 = F_5 ( V_2 ) ;
F_55 ( V_53 -> V_94 , V_92 , V_93 ) ;
}
static void F_56 ( struct V_1 * V_2 , T_1 * V_92 , int V_93 )
{
struct V_11 * V_12 = F_6 ( V_2 ) ;
F_57 ( V_12 -> V_46 + V_95 , V_92 , V_93 >> 2 ) ;
if ( V_93 & 3 ) {
V_92 += V_93 & ~ 3 ;
for (; V_93 & 3 ; V_93 -- )
* V_92 ++ = F_44 ( V_12 -> V_46 + V_95 ) ;
}
}
static void F_58 ( struct V_1 * V_2 , const T_1 * V_92 ,
int V_93 )
{
struct V_52 * V_53 = F_5 ( V_2 ) ;
F_59 ( V_53 -> V_96 , V_92 , V_93 ) ;
}
static void F_60 ( struct V_1 * V_2 , const T_1 * V_92 ,
int V_93 )
{
struct V_11 * V_12 = F_6 ( V_2 ) ;
F_61 ( V_12 -> V_46 + V_95 , V_92 , V_93 >> 2 ) ;
if ( V_93 & 3 ) {
V_92 += V_93 & ~ 3 ;
for (; V_93 & 3 ; V_93 -- , V_92 ++ )
F_41 ( * V_92 , V_12 -> V_46 + V_95 ) ;
}
}
static int F_62 ( struct V_97 * V_98 ,
unsigned long V_99 , void * V_100 )
{
struct V_11 * V_12 ;
unsigned long V_101 ;
V_12 = F_4 ( V_98 , struct V_11 , V_102 ) ;
V_101 = F_21 ( V_12 -> V_21 ) ;
if ( ( V_99 == V_103 && V_101 < V_12 -> V_40 ) ||
( V_99 == V_104 && V_101 > V_12 -> V_40 ) ) {
F_20 ( V_12 ) ;
}
return 0 ;
}
static inline int F_63 ( struct V_11 * V_12 )
{
V_12 -> V_102 . V_105 = F_62 ;
return F_64 ( & V_12 -> V_102 ,
V_106 ) ;
}
static inline void
F_65 ( struct V_11 * V_12 )
{
F_66 ( & V_12 -> V_102 ,
V_106 ) ;
}
static inline int F_63 ( struct V_11 * V_12 )
{
return 0 ;
}
static inline void
F_65 ( struct V_11 * V_12 )
{
}
static int F_67 ( struct V_13 * V_107 )
{
struct V_11 * V_12 = F_7 ( V_107 ) ;
if ( V_12 == NULL )
return 0 ;
F_65 ( V_12 ) ;
if ( V_12 -> V_108 != NULL ) {
struct V_9 * V_109 = V_12 -> V_108 ;
int V_110 ;
for ( V_110 = 0 ; V_110 < V_12 -> V_111 ; V_110 ++ , V_109 ++ ) {
F_18 ( L_12 , V_110 , V_109 ) ;
F_68 ( F_69 ( & V_109 -> V_10 ) ) ;
}
}
if ( ! F_70 ( V_12 -> V_21 ) )
F_13 ( V_12 , V_112 ) ;
return 0 ;
}
static int F_71 ( struct V_11 * V_12 ,
struct V_9 * V_2 ,
struct V_113 * V_36 )
{
if ( V_36 ) {
struct V_1 * V_114 = F_69 ( & V_2 -> V_10 ) ;
V_114 -> V_115 = V_36 -> V_115 ;
return F_72 ( V_114 , NULL , NULL ,
V_36 -> V_116 , V_36 -> V_117 ) ;
}
return - V_118 ;
}
static int F_73 ( struct V_1 * V_2 ,
const struct V_119 * V_120 ,
bool V_121 )
{
struct V_11 * V_12 = F_6 ( V_2 ) ;
struct V_15 * V_122 = V_12 -> V_27 ;
const struct V_123 * V_124 ;
int V_31 ;
V_124 = F_74 ( V_120 ) ;
if ( F_70 ( V_124 ) )
return - V_125 ;
V_31 = V_124 -> V_126 - V_124 -> V_127 ;
if ( V_31 < 0 )
V_31 = 0 ;
V_122 -> V_31 = F_17 ( V_31 , 1000 ) ;
V_122 -> V_32 = F_17 ( V_124 -> V_127 , 1000 ) ;
V_122 -> V_33 = F_17 ( V_124 -> V_128 , 1000 ) ;
return F_20 ( V_12 ) ;
}
static void F_75 ( struct V_11 * V_12 ,
struct V_9 * V_51 ,
struct V_113 * V_36 )
{
struct V_129 * V_130 = V_12 -> V_41 -> V_131 ;
struct V_52 * V_10 = & V_51 -> V_10 ;
void T_2 * V_46 = V_12 -> V_46 ;
F_76 ( V_10 , V_36 -> V_131 ) ;
V_10 -> V_132 = F_58 ;
V_10 -> V_133 = F_54 ;
V_10 -> V_58 = F_38 ;
V_10 -> V_134 = 50 ;
F_77 ( V_10 , V_51 ) ;
V_10 -> V_135 = V_36 -> V_135 ;
V_10 -> V_136 = & V_12 -> V_136 ;
if ( V_130 )
V_10 -> V_137 = F_73 ;
switch ( V_12 -> V_29 ) {
case V_43 :
V_10 -> V_96 = V_46 + V_138 ;
V_12 -> V_55 = V_46 + V_47 ;
V_12 -> V_56 = V_139 ;
V_10 -> V_140 = F_40 ;
V_10 -> V_141 = F_43 ;
break;
case V_45 :
V_10 -> V_96 = V_46 + V_95 ;
V_12 -> V_55 = V_46 + V_50 ;
V_12 -> V_56 = V_142 ;
V_10 -> V_140 = F_42 ;
V_10 -> V_141 = F_45 ;
V_10 -> V_133 = F_56 ;
V_10 -> V_132 = F_60 ;
break;
case V_30 :
V_10 -> V_96 = V_46 + V_95 ;
V_12 -> V_55 = V_46 + V_50 ;
V_12 -> V_56 = V_143 ;
V_10 -> V_140 = F_42 ;
V_10 -> V_141 = F_46 ;
if ( F_33 ( V_46 + V_47 ) & V_144 )
F_23 ( V_12 -> V_41 , L_13 ) ;
break;
}
V_10 -> V_94 = V_10 -> V_96 ;
V_51 -> V_12 = V_12 ;
V_51 -> V_36 = V_36 ;
V_10 -> V_89 . V_83 = V_12 -> V_27 -> V_145 ;
if ( V_36 -> V_146 )
V_10 -> V_147 |= V_148 ;
}
static int F_78 ( struct V_11 * V_12 ,
struct V_9 * V_51 )
{
struct V_52 * V_10 = & V_51 -> V_10 ;
switch ( V_10 -> V_89 . V_83 ) {
case V_149 :
F_23 ( V_12 -> V_41 , L_14 ) ;
break;
case V_150 :
V_10 -> V_89 . V_151 = V_152 ;
F_23 ( V_12 -> V_41 , L_15 ) ;
break;
case V_153 :
V_10 -> V_89 . V_154 = F_51 ;
V_10 -> V_89 . V_155 = F_47 ;
V_10 -> V_89 . V_156 = 1 ;
switch ( V_12 -> V_29 ) {
case V_43 :
V_10 -> V_89 . V_157 = F_48 ;
V_10 -> V_89 . V_154 = F_51 ;
break;
case V_30 :
V_10 -> V_89 . V_157 = F_49 ;
V_10 -> V_89 . V_154 = F_52 ;
break;
case V_45 :
V_10 -> V_89 . V_157 = F_50 ;
V_10 -> V_89 . V_154 = F_53 ;
break;
}
F_36 ( V_12 -> V_41 , L_16 ,
V_10 , V_10 -> V_158 ) ;
if ( V_10 -> V_158 > 10 ) {
V_10 -> V_89 . V_159 = 256 ;
V_10 -> V_89 . V_160 = 3 ;
} else {
V_10 -> V_89 . V_159 = 512 ;
V_10 -> V_89 . V_160 = 3 ;
F_79 ( F_69 ( V_10 ) ,
& V_161 ) ;
}
F_23 ( V_12 -> V_41 , L_17 ) ;
break;
default:
F_22 ( V_12 -> V_41 , L_18 ) ;
return - V_42 ;
}
if ( V_10 -> V_147 & V_148 )
V_10 -> V_135 |= V_162 ;
return 0 ;
}
static int F_80 ( struct V_13 * V_107 )
{
const struct V_163 * V_164 ;
struct V_15 * V_122 ;
struct V_11 * V_12 = F_8 ( V_107 ) ;
struct V_129 * V_130 = V_107 -> V_14 . V_131 , * V_165 ;
struct V_113 * V_166 ;
V_164 = F_81 ( & V_107 -> V_14 ) ;
if ( ! V_164 )
return - V_118 ;
V_12 -> V_29 = V_164 -> type ;
V_122 = F_82 ( & V_107 -> V_14 , sizeof( * V_122 ) , V_167 ) ;
if ( ! V_122 )
return - V_168 ;
V_107 -> V_14 . V_169 = V_122 ;
V_122 -> V_170 = F_83 ( V_130 ) ;
if ( ! V_122 -> V_170 )
return 0 ;
V_166 = F_82 ( & V_107 -> V_14 , sizeof( * V_166 ) * V_122 -> V_170 ,
V_167 ) ;
if ( ! V_166 )
return - V_168 ;
V_122 -> V_166 = V_166 ;
F_84 (np, child) {
V_166 -> V_115 = ( char * ) V_165 -> V_115 ;
V_166 -> V_131 = V_165 ;
V_166 -> V_57 = 1 ;
F_85 ( V_165 ) ;
V_166 ++ ;
}
return 0 ;
}
static int F_86 ( struct V_13 * V_107 )
{
struct V_11 * V_12 = F_8 ( V_107 ) ;
V_12 -> V_29 = F_87 ( V_107 ) -> V_171 ;
return 0 ;
}
static int F_88 ( struct V_13 * V_107 )
{
struct V_15 * V_26 ;
struct V_11 * V_12 ;
struct V_9 * V_51 ;
struct V_113 * V_166 ;
struct V_172 * V_173 ;
int V_174 = 0 ;
int V_159 ;
int V_170 ;
int V_175 ;
V_12 = F_82 ( & V_107 -> V_14 , sizeof( * V_12 ) , V_167 ) ;
if ( V_12 == NULL ) {
V_174 = - V_168 ;
goto V_176;
}
F_89 ( V_107 , V_12 ) ;
F_90 ( & V_12 -> V_136 ) ;
V_12 -> V_21 = F_91 ( & V_107 -> V_14 , L_19 ) ;
if ( F_70 ( V_12 -> V_21 ) ) {
F_22 ( & V_107 -> V_14 , L_20 ) ;
V_174 = - V_177 ;
goto V_176;
}
F_13 ( V_12 , V_20 ) ;
if ( V_107 -> V_14 . V_131 )
V_174 = F_80 ( V_107 ) ;
else
V_174 = F_86 ( V_107 ) ;
if ( V_174 )
goto V_176;
V_26 = F_9 ( V_107 ) ;
V_173 = V_107 -> V_172 ;
V_159 = F_92 ( V_173 ) ;
V_12 -> V_41 = & V_107 -> V_14 ;
V_12 -> V_27 = V_26 ;
V_12 -> V_46 = F_93 ( & V_107 -> V_14 , V_173 ) ;
if ( F_70 ( V_12 -> V_46 ) ) {
V_174 = F_94 ( V_12 -> V_46 ) ;
goto V_176;
}
F_36 ( & V_107 -> V_14 , L_21 , V_12 -> V_46 ) ;
V_166 = ( V_26 != NULL ) ? V_26 -> V_166 : NULL ;
V_170 = ( V_26 != NULL ) ? V_26 -> V_170 : 1 ;
V_12 -> V_111 = V_170 ;
V_159 = V_170 * sizeof( * V_12 -> V_108 ) ;
V_12 -> V_108 = F_82 ( & V_107 -> V_14 , V_159 , V_167 ) ;
if ( V_12 -> V_108 == NULL ) {
V_174 = - V_168 ;
goto V_176;
}
V_51 = V_12 -> V_108 ;
for ( V_175 = 0 ; V_175 < V_170 ; V_175 ++ , V_51 ++ ) {
struct V_1 * V_2 = F_69 ( & V_51 -> V_10 ) ;
F_18 ( L_22 ,
V_175 , V_51 , V_12 ) ;
V_2 -> V_14 . V_178 = & V_107 -> V_14 ;
F_75 ( V_12 , V_51 , V_166 ) ;
V_51 -> V_179 = F_95 ( V_2 ,
( V_166 ) ? V_166 -> V_57 : 1 ,
NULL ) ;
if ( V_51 -> V_179 == 0 ) {
V_174 = F_78 ( V_12 , V_51 ) ;
if ( V_174 < 0 )
goto V_176;
F_96 ( V_2 ) ;
F_71 ( V_12 , V_51 , V_166 ) ;
}
if ( V_166 != NULL )
V_166 ++ ;
}
V_174 = F_37 ( V_12 ) ;
if ( V_174 != 0 )
goto V_176;
V_174 = F_63 ( V_12 ) ;
if ( V_174 < 0 ) {
F_22 ( & V_107 -> V_14 , L_23 ) ;
goto V_176;
}
if ( F_11 ( V_12 ) ) {
F_23 ( & V_107 -> V_14 , L_24 ) ;
F_13 ( V_12 , V_18 ) ;
}
return 0 ;
V_176:
F_67 ( V_107 ) ;
if ( V_174 == 0 )
V_174 = - V_42 ;
return V_174 ;
}
static int F_97 ( struct V_13 * V_14 , T_3 V_180 )
{
struct V_11 * V_12 = F_8 ( V_14 ) ;
if ( V_12 ) {
V_12 -> V_181 = F_33 ( V_12 -> V_55 ) ;
F_34 ( V_12 -> V_181 | V_12 -> V_56 , V_12 -> V_55 ) ;
F_13 ( V_12 , V_112 ) ;
}
return 0 ;
}
static int F_98 ( struct V_13 * V_14 )
{
struct V_11 * V_12 = F_8 ( V_14 ) ;
unsigned long V_182 ;
if ( V_12 ) {
F_13 ( V_12 , V_20 ) ;
F_37 ( V_12 ) ;
V_182 = F_33 ( V_12 -> V_55 ) ;
V_182 &= ~ V_12 -> V_56 ;
V_182 |= V_12 -> V_181 & V_12 -> V_56 ;
F_34 ( V_182 , V_12 -> V_55 ) ;
F_13 ( V_12 , V_18 ) ;
}
return 0 ;
}
