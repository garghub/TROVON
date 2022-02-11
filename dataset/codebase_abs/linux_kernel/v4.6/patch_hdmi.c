static inline bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
return V_4 -> V_5 ;
}
static int F_2 ( struct V_1 * V_2 , T_1 V_6 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_8 ; V_7 ++ )
if ( F_3 ( V_4 , V_7 ) -> V_6 == V_6 )
return V_7 ;
F_4 ( V_2 , L_1 , V_6 ) ;
return - V_9 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_4 -> V_13 ; V_12 ++ )
if ( F_6 ( V_4 , V_12 ) -> V_14 == V_11 )
return V_12 ;
F_4 ( V_2 , L_2 , V_11 ) ;
return - V_9 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_15 * V_16 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_8 ; V_7 ++ ) {
V_16 = F_3 ( V_4 , V_7 ) ;
if ( V_16 -> V_17 &&
V_16 -> V_17 -> V_17 -> V_14 == V_11 )
return V_7 ;
}
F_8 ( V_2 , L_2 , V_11 ) ;
return - V_9 ;
}
static struct V_15 * F_9 ( struct V_3 * V_4 ,
int V_12 )
{
int V_18 ;
struct V_15 * V_16 ;
for ( V_18 = 0 ; V_18 < V_4 -> V_8 ; V_18 ++ ) {
V_16 = F_3 ( V_4 , V_18 ) ;
if ( V_16 -> V_12 == V_12 )
return V_16 ;
}
return NULL ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_19 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_4 -> V_21 ; V_20 ++ )
if ( F_11 ( V_4 , V_20 ) -> V_19 == V_19 )
return V_20 ;
F_4 ( V_2 , L_3 , V_19 ) ;
return - V_9 ;
}
static int F_12 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
struct V_1 * V_2 = F_13 ( V_23 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_15 * V_16 ;
struct V_26 * V_27 ;
int V_12 ;
V_25 -> type = V_28 ;
V_12 = V_23 -> V_29 ;
F_14 ( & V_4 -> V_30 ) ;
V_16 = F_9 ( V_4 , V_12 ) ;
if ( ! V_16 ) {
V_25 -> V_31 = 0 ;
F_15 ( & V_4 -> V_30 ) ;
return 0 ;
}
V_27 = & V_16 -> V_32 ;
V_25 -> V_31 = V_27 -> V_33 ? V_27 -> V_34 : 0 ;
F_15 ( & V_4 -> V_30 ) ;
return 0 ;
}
static int F_16 ( struct V_22 * V_23 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = F_13 ( V_23 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_15 * V_16 ;
struct V_26 * V_27 ;
int V_12 ;
V_12 = V_23 -> V_29 ;
F_14 ( & V_4 -> V_30 ) ;
V_16 = F_9 ( V_4 , V_12 ) ;
if ( ! V_16 ) {
memset ( V_36 -> V_37 . V_38 . V_39 , 0 ,
F_17 ( V_36 -> V_37 . V_38 . V_39 ) ) ;
F_15 ( & V_4 -> V_30 ) ;
return 0 ;
}
V_27 = & V_16 -> V_32 ;
if ( V_27 -> V_34 > F_17 ( V_36 -> V_37 . V_38 . V_39 ) ||
V_27 -> V_34 > V_40 ) {
F_15 ( & V_4 -> V_30 ) ;
F_18 () ;
return - V_9 ;
}
memset ( V_36 -> V_37 . V_38 . V_39 , 0 ,
F_17 ( V_36 -> V_37 . V_38 . V_39 ) ) ;
if ( V_27 -> V_33 )
memcpy ( V_36 -> V_37 . V_38 . V_39 , V_27 -> V_41 ,
V_27 -> V_34 ) ;
F_15 ( & V_4 -> V_30 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_12 ,
int V_42 )
{
struct V_22 * V_43 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_44 ;
V_43 = F_20 ( & V_45 , V_2 ) ;
if ( ! V_43 )
return - V_46 ;
V_43 -> V_29 = V_12 ;
V_43 -> V_47 . V_42 = V_42 ;
V_44 = F_21 ( V_2 , 0 , V_43 ) ;
if ( V_44 < 0 )
return V_44 ;
F_22 ( V_4 , V_12 ) -> V_48 = V_43 ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 , T_1 V_6 ,
int * V_49 , int * V_50 )
{
int V_51 ;
V_51 = F_24 ( V_2 , V_6 , 0 ,
V_52 , 0 ) ;
* V_49 = V_51 >> 5 ;
* V_50 = V_51 & 0x1f ;
}
static void F_25 ( struct V_1 * V_2 , T_1 V_6 ,
int V_49 , int V_50 )
{
int V_51 ;
V_51 = ( V_49 << 5 ) | ( V_50 & 0x1f ) ;
F_26 ( V_2 , V_6 , 0 , V_53 , V_51 ) ;
}
static void F_27 ( struct V_1 * V_2 , T_1 V_6 ,
unsigned char V_51 )
{
F_26 ( V_2 , V_6 , 0 , V_54 , V_51 ) ;
}
static void F_28 ( struct V_1 * V_2 , T_1 V_6 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_55 ;
if ( F_29 ( V_2 , V_6 ) & V_56 )
F_26 ( V_2 , V_6 , 0 ,
V_57 , V_58 ) ;
if ( V_4 -> V_59 )
V_55 = 0 ;
else
V_55 = V_60 ;
F_26 ( V_2 , V_6 , 0 ,
V_61 , V_55 ) ;
}
static void F_30 ( struct V_62 * V_63 ,
struct V_64 * V_65 )
{
struct V_15 * V_16 = V_63 -> V_66 ;
F_14 ( & V_16 -> V_67 ) ;
F_31 ( & V_16 -> V_32 , V_65 ) ;
F_15 ( & V_16 -> V_67 ) ;
}
static void F_32 ( struct V_62 * V_63 ,
struct V_64 * V_65 )
{
struct V_15 * V_16 = V_63 -> V_66 ;
F_14 ( & V_16 -> V_67 ) ;
F_33 ( & V_16 -> V_32 , V_65 ) ;
F_15 ( & V_16 -> V_67 ) ;
}
static int F_34 ( struct V_15 * V_16 , int V_68 )
{
char V_69 [ 32 ] ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_62 * V_63 ;
int V_44 ;
snprintf ( V_69 , sizeof( V_69 ) , L_4 , V_2 -> V_70 , V_68 ) ;
V_44 = F_35 ( V_2 -> V_71 , V_69 , & V_63 ) ;
if ( V_44 < 0 )
return V_44 ;
F_36 ( V_63 , V_16 , F_30 ) ;
V_63 -> V_72 . V_73 . V_74 = F_32 ;
V_63 -> V_75 |= V_76 ;
V_16 -> V_77 = V_63 ;
return 0 ;
}
static void F_37 ( struct V_15 * V_16 )
{
if ( ! V_16 -> V_2 -> V_78 -> V_79 ) {
F_38 ( V_16 -> V_77 ) ;
V_16 -> V_77 = NULL ;
}
}
static inline int F_34 ( struct V_15 * V_16 ,
int V_68 )
{
return 0 ;
}
static inline void F_37 ( struct V_15 * V_16 )
{
}
static void F_39 ( struct V_1 * V_2 ,
T_1 V_6 )
{
F_25 ( V_2 , V_6 , 0x0 , 0x0 ) ;
F_26 ( V_2 , V_6 , 0 , V_80 ,
V_81 ) ;
}
static void F_40 ( struct V_1 * V_2 ,
T_1 V_6 )
{
F_25 ( V_2 , V_6 , 0x0 , 0x0 ) ;
F_26 ( V_2 , V_6 , 0 , V_80 ,
V_82 ) ;
}
static void F_41 ( struct V_1 * V_2 , T_1 V_6 )
{
#ifdef F_42
int V_18 ;
int V_83 ;
V_83 = F_43 ( V_2 , V_6 ) ;
F_8 ( V_2 , L_5 , V_83 ) ;
for ( V_18 = 0 ; V_18 < 8 ; V_18 ++ ) {
V_83 = F_24 ( V_2 , V_6 , 0 ,
V_84 , V_18 ) ;
F_8 ( V_2 , L_6 , V_18 , V_83 ) ;
}
#endif
}
static void F_44 ( struct V_1 * V_2 , T_1 V_6 )
{
#ifdef F_45
int V_18 , V_85 ;
int V_83 ;
int V_86 , V_87 ;
for ( V_18 = 0 ; V_18 < 8 ; V_18 ++ ) {
V_83 = F_24 ( V_2 , V_6 , 0 ,
V_84 , V_18 ) ;
if ( V_83 == 0 )
continue;
F_25 ( V_2 , V_6 , V_18 , 0x0 ) ;
for ( V_85 = 1 ; V_85 < 1000 ; V_85 ++ ) {
F_27 ( V_2 , V_6 , 0x0 ) ;
F_23 ( V_2 , V_6 , & V_86 , & V_87 ) ;
if ( V_86 != V_18 )
F_8 ( V_2 , L_7 ,
V_87 , V_86 , V_18 ) ;
if ( V_87 == 0 )
break;
}
F_8 ( V_2 ,
L_8 ,
V_18 , V_83 , V_85 ) ;
}
#endif
}
static void F_46 ( struct V_88 * V_89 )
{
T_2 * V_38 = ( T_2 * ) V_89 ;
T_2 V_90 = 0 ;
int V_18 ;
V_89 -> V_91 = 0 ;
for ( V_18 = 0 ; V_18 < sizeof( * V_89 ) ; V_18 ++ )
V_90 += V_38 [ V_18 ] ;
V_89 -> V_91 = - V_90 ;
}
static void F_47 ( struct V_1 * V_2 ,
T_1 V_6 ,
T_2 * V_92 , int V_83 )
{
int V_18 ;
F_41 ( V_2 , V_6 ) ;
F_44 ( V_2 , V_6 ) ;
F_25 ( V_2 , V_6 , 0x0 , 0x0 ) ;
for ( V_18 = 0 ; V_18 < V_83 ; V_18 ++ )
F_27 ( V_2 , V_6 , V_92 [ V_18 ] ) ;
}
static bool F_48 ( struct V_1 * V_2 , T_1 V_6 ,
T_2 * V_92 , int V_83 )
{
T_2 V_51 ;
int V_18 ;
if ( F_24 ( V_2 , V_6 , 0 , V_93 , 0 )
!= V_81 )
return false ;
F_25 ( V_2 , V_6 , 0x0 , 0x0 ) ;
for ( V_18 = 0 ; V_18 < V_83 ; V_18 ++ ) {
V_51 = F_24 ( V_2 , V_6 , 0 ,
V_94 , 0 ) ;
if ( V_51 != V_92 [ V_18 ] )
return false ;
}
return true ;
}
static void F_49 ( struct V_1 * V_2 ,
T_1 V_6 ,
int V_95 , int V_96 ,
int V_97 )
{
union V_98 V_99 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
if ( V_97 == 0 ) {
struct V_88 * V_89 = & V_99 . V_100 ;
V_89 -> type = 0x84 ;
V_89 -> V_101 = 0x01 ;
V_89 -> V_102 = 0x0a ;
V_89 -> V_103 = V_96 - 1 ;
V_89 -> V_104 = V_95 ;
F_46 ( V_89 ) ;
} else if ( V_97 == 1 ) {
struct V_105 * V_106 = & V_99 . V_107 ;
V_106 -> type = 0x84 ;
V_106 -> V_102 = 0x1b ;
V_106 -> V_101 = 0x11 << 2 ;
V_106 -> V_103 = V_96 - 1 ;
V_106 -> V_104 = V_95 ;
} else {
F_8 ( V_2 , L_9 ,
V_6 ) ;
return;
}
if ( ! F_48 ( V_2 , V_6 , V_99 . V_38 ,
sizeof( V_99 ) ) ) {
F_8 ( V_2 ,
L_10 ,
V_6 ,
V_96 , V_95 ) ;
F_40 ( V_2 , V_6 ) ;
F_47 ( V_2 , V_6 ,
V_99 . V_38 , sizeof( V_99 ) ) ;
F_39 ( V_2 , V_6 ) ;
}
}
static void F_50 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
bool V_108 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_109 * V_110 = & V_4 -> V_110 ;
T_1 V_6 = V_16 -> V_6 ;
int V_111 = V_16 -> V_111 ;
int V_96 ;
struct V_26 * V_27 ;
int V_95 ;
if ( ! V_111 )
return;
if ( F_51 ( V_2 ) )
F_26 ( V_2 , V_6 , 0 ,
V_57 ,
V_58 ) ;
V_27 = & V_16 -> V_32 ;
V_95 = F_52 ( & V_2 -> V_112 ,
V_27 -> V_113 . V_114 , V_111 ,
V_16 -> V_115 , V_108 , V_16 -> V_110 ) ;
V_96 = F_53 ( V_95 ) ;
V_110 -> V_116 . V_117 ( & V_2 -> V_112 , V_16 -> V_19 ,
V_96 ) ;
F_54 ( & V_4 -> V_110 ,
V_6 , V_108 , V_95 , V_111 ,
V_16 -> V_110 , V_16 -> V_115 ) ;
V_4 -> V_116 . V_118 ( V_2 , V_6 , V_95 , V_96 ,
V_27 -> V_113 . V_97 ) ;
V_16 -> V_108 = V_108 ;
}
static void F_55 ( struct V_1 * V_2 , T_1 V_119 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_7 = F_2 ( V_2 , V_119 ) ;
if ( V_7 < 0 )
return;
if ( F_56 ( F_3 ( V_4 , V_7 ) , 1 ) )
F_57 ( V_2 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_120 * V_121 )
{
F_55 ( V_2 , V_121 -> V_119 ) ;
}
static void F_59 ( struct V_1 * V_2 , unsigned int V_122 )
{
int V_123 = V_122 >> V_124 ;
struct V_125 * V_121 ;
int V_126 = ( V_122 & V_127 ) >> V_128 ;
V_121 = F_60 ( V_2 , V_123 ) ;
if ( ! V_121 )
return;
V_121 -> V_129 = 1 ;
F_8 ( V_2 ,
L_11 ,
V_2 -> V_70 , V_121 -> V_119 , V_126 , ! ! ( V_122 & V_130 ) ,
! ! ( V_122 & V_131 ) , ! ! ( V_122 & V_132 ) ) ;
F_55 ( V_2 , V_121 -> V_119 ) ;
}
static void F_61 ( struct V_1 * V_2 , unsigned int V_122 )
{
int V_123 = V_122 >> V_124 ;
int V_133 = ( V_122 & V_134 ) >> V_135 ;
int V_136 = ! ! ( V_122 & V_137 ) ;
int V_138 = ! ! ( V_122 & V_139 ) ;
F_62 ( V_2 ,
L_12 ,
V_2 -> V_70 ,
V_123 ,
V_133 ,
V_136 ,
V_138 ) ;
if ( V_136 )
;
if ( V_138 )
;
}
static void F_63 ( struct V_1 * V_2 , unsigned int V_122 )
{
int V_123 = V_122 >> V_124 ;
int V_133 = ( V_122 & V_134 ) >> V_135 ;
if ( ! F_60 ( V_2 , V_123 ) ) {
F_8 ( V_2 , L_13 , V_123 ) ;
return;
}
if ( V_133 == 0 )
F_59 ( V_2 , V_122 ) ;
else
F_61 ( V_2 , V_122 ) ;
}
static void F_64 ( struct V_1 * V_2 ,
T_1 V_19 , T_1 V_119 )
{
int V_140 ;
if ( ! F_65 ( V_2 , V_19 , V_141 ) )
F_26 ( V_2 , V_19 , 0 , V_142 , V_141 ) ;
if ( ! F_65 ( V_2 , V_119 , V_141 ) ) {
F_26 ( V_2 , V_119 , 0 , V_142 ,
V_141 ) ;
F_66 ( 40 ) ;
V_140 = F_24 ( V_2 , V_119 , 0 , V_143 , 0 ) ;
V_140 = ( V_140 & V_144 ) >> V_145 ;
F_8 ( V_2 , L_14 , V_119 , V_140 ) ;
}
}
static int F_67 ( struct V_1 * V_2 , T_1 V_6 ,
bool V_146 )
{
int V_147 , V_148 ;
if ( F_68 ( V_2 , V_6 ) & V_149 ) {
V_147 = F_24 ( V_2 , V_6 , 0 ,
V_150 , 0 ) ;
if ( V_147 < 0 )
return V_146 ? - V_9 : 0 ;
V_148 = V_147 & ~ V_151 ;
if ( V_146 )
V_148 |= V_152 ;
else
V_148 |= V_153 ;
F_8 ( V_2 ,
L_15 ,
V_6 ,
V_147 == V_148 ? L_16 : L_17 ,
V_148 ) ;
if ( V_147 != V_148 )
F_26 ( V_2 , V_6 , 0 ,
V_61 ,
V_148 ) ;
} else if ( V_146 )
return - V_9 ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 , T_1 V_19 ,
T_1 V_6 , T_3 V_154 , int V_155 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_44 ;
if ( F_51 ( V_2 ) )
F_64 ( V_2 , V_19 , V_6 ) ;
V_44 = V_4 -> V_116 . V_156 ( V_2 , V_6 , F_70 ( V_155 ) ) ;
if ( V_44 ) {
F_8 ( V_2 , L_18 ) ;
return V_44 ;
}
F_71 ( V_2 , V_19 , V_154 , 0 , V_155 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 ,
int V_7 , int * V_157 , int * V_158 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_15 * V_16 ;
struct V_159 * V_160 = NULL ;
int V_20 , V_161 = 0 ;
if ( V_7 < 0 )
V_16 = NULL ;
else
V_16 = F_3 ( V_4 , V_7 ) ;
for ( V_20 = 0 ; V_20 < V_4 -> V_21 ; V_20 ++ ) {
V_160 = F_11 ( V_4 , V_20 ) ;
if ( V_160 -> V_162 )
continue;
if ( V_16 == NULL )
break;
for ( V_161 = 0 ; V_161 < V_16 -> V_163 ; V_161 ++ )
if ( V_16 -> V_164 [ V_161 ] == V_160 -> V_19 )
break;
if ( V_161 == V_16 -> V_163 )
continue;
break;
}
if ( V_20 == V_4 -> V_21 )
return - V_165 ;
if ( V_16 != NULL )
V_16 -> V_161 = V_161 ;
if ( V_157 )
* V_157 = V_20 ;
if ( V_158 )
* V_158 = V_161 ;
return 0 ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
T_1 V_6 = V_16 -> V_6 ;
int V_161 , V_166 ;
V_161 = V_16 -> V_161 ;
V_166 = F_24 ( V_2 , V_6 , 0 ,
V_167 , 0 ) ;
if ( V_166 != V_161 )
F_74 ( V_2 , V_6 , 0 ,
V_168 ,
V_161 ) ;
}
static int F_75 ( struct V_3 * V_4 ,
T_1 V_19 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_4 -> V_21 ; V_18 ++ )
if ( V_4 -> V_169 [ V_18 ] == V_19 )
return V_18 ;
return - V_9 ;
}
static void F_76 ( struct V_1 * V_2 ,
T_1 V_6 , int V_161 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_119 ;
int V_20 , V_166 ;
struct V_159 * V_160 ;
F_77 (nid, codec) {
unsigned int V_170 = F_29 ( V_2 , V_119 ) ;
unsigned int V_171 = F_78 ( V_170 ) ;
if ( V_171 != V_172 )
continue;
if ( V_119 == V_6 )
continue;
V_166 = F_24 ( V_2 , V_119 , 0 ,
V_167 , 0 ) ;
if ( V_166 != V_161 )
continue;
for ( V_20 = 0 ; V_20 < V_4 -> V_21 ; V_20 ++ ) {
V_160 = F_11 ( V_4 , V_20 ) ;
if ( ! V_160 -> V_162 ) {
F_8 ( V_2 ,
L_19 ,
V_20 , V_119 ) ;
F_74 ( V_2 , V_119 , 0 ,
V_168 ,
V_20 ) ;
break;
}
}
}
}
static void F_79 ( struct V_1 * V_2 ,
T_1 V_6 , T_1 V_19 )
{
int V_161 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! F_51 ( V_2 ) && ! F_80 ( V_2 ) )
return;
V_161 = F_75 ( V_4 , V_19 ) ;
if ( V_161 >= 0 )
F_76 ( V_2 , V_6 , V_161 ) ;
}
static int F_81 ( struct V_10 * V_11 ,
struct V_1 * V_2 ,
struct V_173 * V_174 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_175 * V_176 = V_174 -> V_176 ;
int V_20 , V_12 ;
struct V_159 * V_160 = NULL ;
int V_44 ;
V_12 = F_5 ( V_2 , V_11 ) ;
if ( V_12 < 0 )
return - V_9 ;
V_44 = F_72 ( V_2 , - 1 , & V_20 , NULL ) ;
if ( V_44 )
return V_44 ;
V_160 = F_11 ( V_4 , V_20 ) ;
V_160 -> V_162 = 1 ;
V_11 -> V_119 = V_160 -> V_19 ;
F_79 ( V_2 , 0 , V_160 -> V_19 ) ;
F_82 ( V_12 , & V_4 -> V_177 ) ;
V_11 -> V_178 = V_160 -> V_178 ;
V_11 -> V_179 = V_160 -> V_179 ;
V_11 -> V_180 = V_160 -> V_180 ;
V_11 -> V_181 = V_160 -> V_181 ;
V_11 -> V_182 = V_160 -> V_182 ;
V_176 -> V_183 . V_178 = V_11 -> V_178 ;
V_176 -> V_183 . V_179 = V_11 -> V_179 ;
V_176 -> V_183 . V_181 = V_11 -> V_181 ;
V_176 -> V_183 . V_180 = V_11 -> V_180 ;
F_83 ( V_174 -> V_176 , 0 ,
V_184 , 2 ) ;
return 0 ;
}
static int F_84 ( struct V_10 * V_11 ,
struct V_1 * V_2 ,
struct V_173 * V_174 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_175 * V_176 = V_174 -> V_176 ;
int V_7 , V_20 , V_12 , V_161 = 0 ;
struct V_15 * V_16 ;
struct V_26 * V_27 ;
struct V_159 * V_160 = NULL ;
int V_44 ;
V_12 = F_5 ( V_2 , V_11 ) ;
if ( V_12 < 0 )
return - V_9 ;
F_14 ( & V_4 -> V_30 ) ;
V_7 = F_7 ( V_2 , V_11 ) ;
if ( ! V_4 -> V_185 ) {
if ( F_85 ( V_7 < 0 ) ) {
F_15 ( & V_4 -> V_30 ) ;
return - V_9 ;
}
} else {
if ( V_7 < 0 ) {
V_44 = F_81 ( V_11 , V_2 , V_174 ) ;
F_15 ( & V_4 -> V_30 ) ;
return V_44 ;
}
}
V_44 = F_72 ( V_2 , V_7 , & V_20 , & V_161 ) ;
if ( V_44 < 0 ) {
F_15 ( & V_4 -> V_30 ) ;
return V_44 ;
}
V_160 = F_11 ( V_4 , V_20 ) ;
V_160 -> V_162 = 1 ;
F_82 ( V_12 , & V_4 -> V_177 ) ;
V_16 = F_3 ( V_4 , V_7 ) ;
V_16 -> V_19 = V_160 -> V_19 ;
V_11 -> V_119 = V_160 -> V_19 ;
F_74 ( V_2 , V_16 -> V_6 , 0 ,
V_168 ,
V_161 ) ;
if ( F_51 ( V_2 ) || F_80 ( V_2 ) )
F_76 ( V_2 , V_16 -> V_6 , V_161 ) ;
F_86 ( V_2 , V_12 , V_160 -> V_19 ) ;
V_11 -> V_178 = V_160 -> V_178 ;
V_11 -> V_179 = V_160 -> V_179 ;
V_11 -> V_180 = V_160 -> V_180 ;
V_11 -> V_181 = V_160 -> V_181 ;
V_11 -> V_182 = V_160 -> V_182 ;
V_27 = & V_16 -> V_32 ;
if ( ! V_186 && V_27 -> V_33 ) {
F_87 ( & V_27 -> V_113 , V_11 ) ;
if ( V_11 -> V_178 > V_11 -> V_179 ||
! V_11 -> V_180 || ! V_11 -> V_181 ) {
V_160 -> V_162 = 0 ;
V_11 -> V_119 = 0 ;
F_88 ( V_2 , V_12 ) ;
F_15 ( & V_4 -> V_30 ) ;
return - V_187 ;
}
}
F_15 ( & V_4 -> V_30 ) ;
V_176 -> V_183 . V_178 = V_11 -> V_178 ;
V_176 -> V_183 . V_179 = V_11 -> V_179 ;
V_176 -> V_183 . V_181 = V_11 -> V_181 ;
V_176 -> V_183 . V_180 = V_11 -> V_180 ;
F_83 ( V_174 -> V_176 , 0 ,
V_184 , 2 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 , int V_7 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_15 * V_16 = F_3 ( V_4 , V_7 ) ;
T_1 V_6 = V_16 -> V_6 ;
if ( ! ( F_29 ( V_2 , V_6 ) & V_188 ) ) {
F_4 ( V_2 ,
L_20 ,
V_6 , F_29 ( V_2 , V_6 ) ) ;
return - V_9 ;
}
V_16 -> V_163 = F_90 ( V_2 , V_6 ,
V_16 -> V_164 ,
V_189 ) ;
return 0 ;
}
static int F_91 ( struct V_3 * V_4 ,
struct V_15 * V_16 )
{
int V_18 ;
if ( ! F_92 ( V_16 -> V_190 , & V_4 -> V_191 ) )
return V_16 -> V_190 ;
for ( V_18 = V_4 -> V_8 ; V_18 < V_4 -> V_13 ; V_18 ++ ) {
if ( ! F_92 ( V_18 , & V_4 -> V_191 ) )
return V_18 ;
}
for ( V_18 = 0 ; V_18 < V_4 -> V_8 ; V_18 ++ ) {
if ( ! F_92 ( V_18 , & V_4 -> V_191 ) )
return V_18 ;
}
return - V_165 ;
}
static void F_93 ( struct V_3 * V_4 ,
struct V_15 * V_16 )
{
int V_192 ;
if ( V_16 -> V_17 )
return;
V_192 = F_91 ( V_4 , V_16 ) ;
if ( V_192 == - V_165 )
return;
V_16 -> V_12 = V_192 ;
V_16 -> V_17 = F_22 ( V_4 , V_192 ) ;
F_82 ( V_192 , & V_4 -> V_191 ) ;
}
static void F_94 ( struct V_3 * V_4 ,
struct V_15 * V_16 )
{
int V_192 ;
if ( ! V_16 -> V_17 )
return;
V_192 = V_16 -> V_12 ;
V_16 -> V_12 = - 1 ;
V_16 -> V_17 = NULL ;
if ( V_192 >= 0 && V_192 < V_4 -> V_13 )
F_95 ( V_192 , & V_4 -> V_191 ) ;
}
static int F_96 ( struct V_3 * V_4 ,
struct V_15 * V_16 , T_1 V_19 )
{
int V_161 ;
for ( V_161 = 0 ; V_161 < V_16 -> V_163 ; V_161 ++ )
if ( V_16 -> V_164 [ V_161 ] == V_19 )
break;
return V_161 ;
}
static void F_97 ( struct V_3 * V_4 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_193 * V_17 ;
struct V_10 * V_11 ;
struct V_173 * V_174 ;
int V_161 ;
bool V_108 ;
if ( V_16 -> V_12 >= 0 && V_16 -> V_12 < V_4 -> V_13 )
V_17 = F_6 ( V_4 , V_16 -> V_12 ) ;
else
return;
if ( ! F_92 ( V_16 -> V_12 , & V_4 -> V_177 ) )
return;
V_11 = V_17 -> V_14 ;
V_174 = V_17 -> V_17 -> V_194 [ 0 ] . V_174 ;
V_16 -> V_19 = V_11 -> V_119 ;
V_161 = F_96 ( V_4 , V_16 , V_11 -> V_119 ) ;
if ( V_161 < V_16 -> V_163 )
F_74 ( V_2 , V_16 -> V_6 , 0 ,
V_168 ,
V_161 ) ;
F_86 ( V_2 , V_16 -> V_12 , V_11 -> V_119 ) ;
V_108 = F_98 ( V_2 , V_11 -> V_119 ) ;
if ( V_174 -> V_176 )
V_16 -> V_111 = V_174 -> V_176 -> V_111 ;
V_16 -> V_195 = true ;
V_16 -> V_161 = V_161 ;
F_50 ( V_2 , V_16 , V_108 ) ;
}
static void F_99 ( struct V_3 * V_4 ,
struct V_15 * V_16 )
{
if ( V_16 -> V_12 >= 0 && V_16 -> V_12 < V_4 -> V_13 )
F_88 ( V_16 -> V_2 , V_16 -> V_12 ) ;
V_16 -> V_115 = false ;
memset ( V_16 -> V_110 , 0 , sizeof( V_16 -> V_110 ) ) ;
V_16 -> V_195 = false ;
V_16 -> V_111 = 0 ;
}
static void F_100 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_26 * V_27 )
{
struct V_26 * V_196 = & V_16 -> V_32 ;
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_197 = V_196 -> V_33 ;
bool V_198 ;
int V_12 = - 1 ;
V_12 = V_16 -> V_12 ;
if ( V_4 -> V_185 ) {
if ( V_27 -> V_33 ) {
F_93 ( V_4 , V_16 ) ;
F_97 ( V_4 , V_16 ) ;
} else {
F_99 ( V_4 , V_16 ) ;
F_94 ( V_4 , V_16 ) ;
}
}
if ( V_12 == - 1 )
V_12 = V_16 -> V_12 ;
if ( V_27 -> V_33 )
F_101 ( V_2 , & V_27 -> V_113 ) ;
V_198 = ( V_196 -> V_33 != V_27 -> V_33 ) ;
if ( V_27 -> V_33 && V_196 -> V_33 )
if ( V_196 -> V_34 != V_27 -> V_34 ||
memcmp ( V_196 -> V_41 , V_27 -> V_41 ,
V_27 -> V_34 ) != 0 )
V_198 = true ;
V_196 -> V_199 = V_27 -> V_199 ;
V_196 -> V_33 = V_27 -> V_33 ;
V_196 -> V_34 = V_27 -> V_34 ;
if ( V_27 -> V_33 )
memcpy ( V_196 -> V_41 , V_27 -> V_41 , V_27 -> V_34 ) ;
V_196 -> V_113 = V_27 -> V_113 ;
if ( V_27 -> V_33 && ! V_197 && V_16 -> V_195 ) {
if ( F_51 ( V_2 ) || F_80 ( V_2 ) ) {
F_73 ( V_2 , V_16 ) ;
F_76 ( V_2 , V_16 -> V_6 ,
V_16 -> V_161 ) ;
}
F_50 ( V_2 , V_16 , V_16 -> V_108 ) ;
}
if ( V_198 && V_12 >= 0 )
F_102 ( V_2 -> V_71 ,
V_200 |
V_201 ,
& F_22 ( V_4 , V_12 ) -> V_48 -> V_47 ) ;
}
static bool F_103 ( struct V_15 * V_16 ,
int V_202 )
{
struct V_125 * V_121 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_26 * V_27 = & V_4 -> V_203 ;
T_1 V_6 = V_16 -> V_6 ;
int V_204 ;
bool V_205 ;
bool V_206 = false ;
V_204 = F_104 ( V_2 , V_6 ) ;
F_14 ( & V_16 -> V_67 ) ;
V_27 -> V_199 = ! ! ( V_204 & V_207 ) ;
if ( V_27 -> V_199 )
V_27 -> V_33 = ! ! ( V_204 & V_208 ) ;
else
V_27 -> V_33 = false ;
F_8 ( V_2 ,
L_21 ,
V_2 -> V_70 , V_6 , V_27 -> V_199 , V_27 -> V_33 ) ;
if ( V_27 -> V_33 ) {
if ( V_4 -> V_116 . V_209 ( V_2 , V_6 , V_27 -> V_41 ,
& V_27 -> V_34 ) < 0 )
V_27 -> V_33 = false ;
else {
if ( F_105 ( V_2 , & V_27 -> V_113 , V_27 -> V_41 ,
V_27 -> V_34 ) < 0 )
V_27 -> V_33 = false ;
}
if ( ! V_27 -> V_33 && V_202 )
V_206 = true ;
}
if ( V_206 )
F_106 ( & V_16 -> V_210 , F_107 ( 300 ) ) ;
else
F_100 ( V_2 , V_16 , V_27 ) ;
V_205 = ! V_202 || ! V_27 -> V_199 || V_27 -> V_33 ;
V_121 = F_108 ( V_2 , V_6 ) ;
if ( V_121 )
V_121 -> V_211 = ! V_205 ;
F_15 ( & V_16 -> V_67 ) ;
return V_205 ;
}
static struct V_212 * F_109 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_212 * V_121 = NULL ;
struct V_125 * V_213 ;
if ( V_16 -> V_12 >= 0 && V_4 -> V_185 )
V_121 = V_4 -> V_214 [ V_16 -> V_12 ] . V_121 ;
else if ( ! V_4 -> V_185 ) {
V_213 = F_108 ( V_2 , V_16 -> V_6 ) ;
if ( V_213 )
V_121 = V_213 -> V_121 ;
}
return V_121 ;
}
static void F_110 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_26 * V_27 = & V_4 -> V_203 ;
struct V_212 * V_121 = NULL ;
int V_83 ;
F_14 ( & V_16 -> V_67 ) ;
V_27 -> V_199 = false ;
V_83 = F_111 ( & V_2 -> V_78 -> V_112 , V_16 -> V_6 ,
& V_27 -> V_199 , V_27 -> V_41 ,
V_40 ) ;
if ( V_83 > 0 ) {
V_83 = F_112 ( V_83 , V_40 ) ;
if ( F_105 ( V_2 , & V_27 -> V_113 ,
V_27 -> V_41 , V_83 ) < 0 )
V_83 = - V_9 ;
}
if ( V_83 > 0 ) {
V_27 -> V_33 = true ;
V_27 -> V_34 = V_83 ;
} else {
V_27 -> V_33 = false ;
V_27 -> V_34 = 0 ;
}
V_121 = F_109 ( V_2 , V_16 ) ;
F_100 ( V_2 , V_16 , V_27 ) ;
if ( V_121 == NULL )
V_121 = F_109 ( V_2 , V_16 ) ;
if ( V_121 == NULL )
goto V_215;
F_113 ( V_121 ,
V_27 -> V_199 ? V_216 : 0 ) ;
V_215:
F_15 ( & V_16 -> V_67 ) ;
}
static bool F_56 ( struct V_15 * V_16 , int V_202 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_205 ;
if ( ! F_1 ( V_2 ) )
F_114 ( V_2 ) ;
F_14 ( & V_4 -> V_30 ) ;
if ( F_1 ( V_2 ) ) {
F_110 ( V_2 , V_16 ) ;
V_205 = false ;
} else {
V_205 = F_103 ( V_16 , V_202 ) ;
}
F_15 ( & V_4 -> V_30 ) ;
if ( ! F_1 ( V_2 ) )
F_115 ( V_2 ) ;
return V_205 ;
}
static void F_116 ( struct V_217 * V_210 )
{
struct V_15 * V_16 =
F_117 ( F_118 ( V_210 ) , struct V_15 , V_210 ) ;
if ( V_16 -> V_218 ++ > 6 )
V_16 -> V_218 = 0 ;
if ( F_56 ( V_16 , V_16 -> V_218 ) )
F_57 ( V_16 -> V_2 ) ;
}
static int F_119 ( struct V_1 * V_2 , T_1 V_6 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_219 , V_220 ;
int V_7 ;
struct V_15 * V_16 ;
int V_44 ;
V_219 = F_68 ( V_2 , V_6 ) ;
if ( ! ( V_219 & ( V_221 | V_222 ) ) )
return 0 ;
V_220 = F_120 ( V_2 , V_6 ) ;
if ( F_121 ( V_220 ) == V_223 )
return 0 ;
if ( F_51 ( V_2 ) )
F_122 ( V_2 , V_6 ) ;
V_7 = V_4 -> V_8 ;
V_16 = F_123 ( & V_4 -> V_224 ) ;
if ( ! V_16 )
return - V_46 ;
V_16 -> V_6 = V_6 ;
V_16 -> V_108 = false ;
if ( V_4 -> V_185 )
V_16 -> V_12 = - 1 ;
else {
V_16 -> V_17 = F_22 ( V_4 , V_7 ) ;
V_16 -> V_12 = V_7 ;
}
V_16 -> V_190 = V_7 ;
V_44 = F_89 ( V_2 , V_7 ) ;
if ( V_44 < 0 )
return V_44 ;
V_4 -> V_8 ++ ;
return 0 ;
}
static int F_124 ( struct V_1 * V_2 , T_1 V_19 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_159 * V_160 ;
unsigned int V_225 ;
int V_44 ;
V_225 = F_29 ( V_2 , V_19 ) ;
V_225 = F_125 ( V_225 ) ;
V_160 = F_123 ( & V_4 -> V_226 ) ;
if ( ! V_160 )
return - V_46 ;
V_160 -> V_19 = V_19 ;
V_160 -> V_178 = 2 ;
if ( V_225 <= 16 ) {
V_160 -> V_179 = V_225 ;
if ( V_225 > V_4 -> V_110 . V_179 )
V_4 -> V_110 . V_179 = V_225 ;
}
V_44 = F_126 ( V_2 , V_19 ,
& V_160 -> V_180 ,
& V_160 -> V_181 ,
& V_160 -> V_182 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_4 -> V_21 < F_17 ( V_4 -> V_169 ) )
V_4 -> V_169 [ V_4 -> V_21 ] = V_19 ;
V_4 -> V_21 ++ ;
return 0 ;
}
static int F_127 ( struct V_1 * V_2 )
{
T_1 V_119 ;
int V_18 , V_227 ;
V_227 = F_128 ( V_2 , V_2 -> V_112 . V_228 , & V_119 ) ;
if ( ! V_119 || V_227 < 0 ) {
F_4 ( V_2 , L_22 ) ;
return - V_9 ;
}
for ( V_18 = 0 ; V_18 < V_227 ; V_18 ++ , V_119 ++ ) {
unsigned int V_219 ;
unsigned int type ;
V_219 = F_29 ( V_2 , V_119 ) ;
type = F_78 ( V_219 ) ;
if ( ! ( V_219 & V_229 ) )
continue;
switch ( type ) {
case V_230 :
F_124 ( V_2 , V_119 ) ;
break;
case V_172 :
F_119 ( V_2 , V_119 ) ;
break;
}
}
return 0 ;
}
static bool F_98 ( struct V_1 * V_2 , T_1 V_19 )
{
struct V_231 * V_232 ;
bool V_108 ;
F_14 ( & V_2 -> V_233 ) ;
V_232 = F_129 ( V_2 , V_19 ) ;
V_108 = ! ! ( V_232 -> V_234 & V_235 ) ;
F_15 ( & V_2 -> V_233 ) ;
return V_108 ;
}
static int F_130 ( struct V_10 * V_11 ,
struct V_1 * V_2 ,
unsigned int V_154 ,
unsigned int V_155 ,
struct V_173 * V_174 )
{
T_1 V_19 = V_11 -> V_119 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_7 ;
struct V_15 * V_16 ;
T_1 V_6 ;
struct V_175 * V_176 = V_174 -> V_176 ;
bool V_108 ;
int V_147 ;
int V_44 ;
F_14 ( & V_4 -> V_30 ) ;
V_7 = F_7 ( V_2 , V_11 ) ;
if ( V_4 -> V_185 && V_7 < 0 ) {
F_79 ( V_2 , 0 , V_19 ) ;
F_71 ( V_2 , V_19 ,
V_154 , 0 , V_155 ) ;
F_15 ( & V_4 -> V_30 ) ;
return 0 ;
}
if ( F_85 ( V_7 < 0 ) ) {
F_15 ( & V_4 -> V_30 ) ;
return - V_9 ;
}
V_16 = F_3 ( V_4 , V_7 ) ;
V_6 = V_16 -> V_6 ;
if ( F_51 ( V_2 ) || F_80 ( V_2 ) ) {
F_73 ( V_2 , V_16 ) ;
F_76 ( V_2 , V_6 , V_16 -> V_161 ) ;
}
if ( F_1 ( V_2 ) )
F_131 ( & V_2 -> V_78 -> V_112 , V_6 , V_176 -> V_236 ) ;
V_108 = F_98 ( V_2 , V_19 ) ;
F_14 ( & V_16 -> V_67 ) ;
V_16 -> V_111 = V_174 -> V_176 -> V_111 ;
V_16 -> V_195 = true ;
F_50 ( V_2 , V_16 , V_108 ) ;
F_15 ( & V_16 -> V_67 ) ;
if ( V_4 -> V_59 ) {
V_147 = F_24 ( V_2 , V_6 , 0 ,
V_150 , 0 ) ;
F_26 ( V_2 , V_6 , 0 ,
V_61 ,
V_147 | V_60 ) ;
}
V_44 = V_4 -> V_116 . V_237 ( V_2 , V_19 , V_6 ,
V_154 , V_155 ) ;
F_15 ( & V_4 -> V_30 ) ;
return V_44 ;
}
static int F_132 ( struct V_10 * V_11 ,
struct V_1 * V_2 ,
struct V_173 * V_174 )
{
F_133 ( V_2 , V_11 -> V_119 ) ;
return 0 ;
}
static int F_134 ( struct V_10 * V_11 ,
struct V_1 * V_2 ,
struct V_173 * V_174 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_20 , V_7 , V_12 ;
struct V_159 * V_160 ;
struct V_15 * V_16 ;
int V_147 ;
if ( V_11 -> V_119 ) {
V_12 = F_5 ( V_2 , V_11 ) ;
if ( F_85 ( V_12 < 0 ) )
return - V_9 ;
V_20 = F_10 ( V_2 , V_11 -> V_119 ) ;
if ( F_85 ( V_20 < 0 ) )
return - V_9 ;
V_160 = F_11 ( V_4 , V_20 ) ;
F_85 ( ! V_160 -> V_162 ) ;
V_160 -> V_162 = 0 ;
V_11 -> V_119 = 0 ;
F_14 ( & V_4 -> V_30 ) ;
F_88 ( V_2 , V_12 ) ;
F_95 ( V_12 , & V_4 -> V_177 ) ;
V_7 = F_7 ( V_2 , V_11 ) ;
if ( V_4 -> V_185 && V_7 < 0 ) {
F_15 ( & V_4 -> V_30 ) ;
return 0 ;
}
if ( F_85 ( V_7 < 0 ) ) {
F_15 ( & V_4 -> V_30 ) ;
return - V_9 ;
}
V_16 = F_3 ( V_4 , V_7 ) ;
if ( V_4 -> V_59 ) {
V_147 = F_24 ( V_2 , V_16 -> V_6 , 0 ,
V_150 , 0 ) ;
F_26 ( V_2 , V_16 -> V_6 , 0 ,
V_61 ,
V_147 & ~ V_60 ) ;
}
F_14 ( & V_16 -> V_67 ) ;
V_16 -> V_115 = false ;
memset ( V_16 -> V_110 , 0 , sizeof( V_16 -> V_110 ) ) ;
V_16 -> V_195 = false ;
V_16 -> V_111 = 0 ;
F_15 ( & V_16 -> V_67 ) ;
F_15 ( & V_4 -> V_30 ) ;
}
return 0 ;
}
static void F_135 ( struct V_238 * V_239 , int V_12 ,
unsigned char * V_110 )
{
struct V_1 * V_2 = F_117 ( V_239 , struct V_1 , V_112 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_15 * V_16 = F_9 ( V_4 , V_12 ) ;
if ( ! V_16 )
return;
memcpy ( V_110 , V_16 -> V_110 , F_17 ( V_16 -> V_110 ) ) ;
}
static void F_136 ( struct V_238 * V_239 , int V_12 ,
unsigned char * V_110 , int V_240 )
{
struct V_1 * V_2 = F_117 ( V_239 , struct V_1 , V_112 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_15 * V_16 = F_9 ( V_4 , V_12 ) ;
if ( ! V_16 )
return;
F_14 ( & V_16 -> V_67 ) ;
V_16 -> V_115 = true ;
memcpy ( V_16 -> V_110 , V_110 , F_17 ( V_16 -> V_110 ) ) ;
if ( V_240 )
F_50 ( V_2 , V_16 , V_16 -> V_108 ) ;
F_15 ( & V_16 -> V_67 ) ;
}
static bool F_137 ( struct V_238 * V_239 , int V_12 )
{
struct V_1 * V_2 = F_117 ( V_239 , struct V_1 , V_112 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_15 * V_16 = F_9 ( V_4 , V_12 ) ;
return V_16 ? true : false ;
}
static int F_138 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_8 ; V_7 ++ ) {
struct V_193 * V_113 ;
struct V_10 * V_241 ;
V_113 = F_139 ( V_2 , L_23 , V_7 ) ;
if ( ! V_113 )
return - V_46 ;
V_4 -> V_214 [ V_7 ] . V_17 = V_113 ;
V_4 -> V_13 ++ ;
V_113 -> V_242 = V_243 ;
V_113 -> V_244 = true ;
V_241 = & V_113 -> V_14 [ V_245 ] ;
V_241 -> V_246 = 1 ;
V_241 -> V_116 = V_247 ;
}
return 0 ;
}
static void F_140 ( struct V_212 * V_121 )
{
struct V_248 * V_17 = V_121 -> V_66 ;
V_17 -> V_121 = NULL ;
}
static int F_141 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_12 ,
const char * V_69 )
{
struct V_212 * V_121 ;
int V_44 ;
V_44 = F_142 ( V_2 -> V_71 , V_69 , V_216 , & V_121 ,
true , false ) ;
if ( V_44 < 0 )
return V_44 ;
V_4 -> V_214 [ V_12 ] . V_121 = V_121 ;
V_121 -> V_66 = & V_4 -> V_214 [ V_12 ] ;
V_121 -> V_249 = F_140 ;
return 0 ;
}
static int F_143 ( struct V_1 * V_2 , int V_12 )
{
char V_250 [ 32 ] = L_24 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_15 * V_16 ;
struct V_125 * V_121 ;
int V_251 = F_6 ( V_4 , V_12 ) -> V_42 ;
bool V_252 ;
int V_205 ;
if ( V_251 > 0 )
sprintf ( V_250 + strlen ( V_250 ) , L_25 , V_251 ) ;
if ( V_4 -> V_185 )
return F_141 ( V_2 , V_4 , V_12 , V_250 ) ;
V_16 = F_3 ( V_4 , V_12 ) ;
V_252 = ! F_144 ( V_2 , V_16 -> V_6 ) ;
if ( V_252 )
strncat ( V_250 , L_26 ,
sizeof( V_250 ) - strlen ( V_250 ) - 1 ) ;
V_205 = F_145 ( V_2 , V_16 -> V_6 , V_250 ,
V_252 ) ;
if ( V_205 < 0 )
return V_205 ;
V_121 = F_108 ( V_2 , V_16 -> V_6 ) ;
if ( V_121 == NULL )
return 0 ;
V_4 -> V_214 [ V_12 ] . V_121 = V_121 -> V_121 ;
return 0 ;
}
static int F_146 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_44 ;
int V_7 , V_12 ;
for ( V_12 = 0 ; V_12 < V_4 -> V_13 ; V_12 ++ ) {
V_44 = F_143 ( V_2 , V_12 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_4 -> V_185 )
V_44 = F_147 ( V_2 ,
0 , V_4 -> V_169 [ 0 ] ,
V_243 ) ;
else {
struct V_15 * V_16 =
F_3 ( V_4 , V_12 ) ;
V_44 = F_147 ( V_2 ,
V_16 -> V_6 ,
V_16 -> V_164 [ 0 ] ,
V_243 ) ;
}
if ( V_44 < 0 )
return V_44 ;
F_88 ( V_2 , V_12 ) ;
V_44 = F_19 ( V_2 , V_12 ,
F_6 ( V_4 , V_12 ) -> V_42 ) ;
if ( V_44 < 0 )
return V_44 ;
}
for ( V_7 = 0 ; V_7 < V_4 -> V_8 ; V_7 ++ ) {
struct V_15 * V_16 = F_3 ( V_4 , V_7 ) ;
F_56 ( V_16 , 0 ) ;
}
for ( V_12 = 0 ; V_12 < V_4 -> V_13 ; V_12 ++ ) {
struct V_193 * V_17 ;
V_17 = F_6 ( V_4 , V_12 ) ;
if ( ! V_17 || ! V_17 -> V_17 )
break;
V_44 = F_148 ( V_17 -> V_17 , V_12 , & V_4 -> V_110 ) ;
if ( V_44 < 0 )
return V_44 ;
}
return 0 ;
}
static int F_149 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_8 ; V_7 ++ ) {
struct V_15 * V_16 = F_3 ( V_4 , V_7 ) ;
V_16 -> V_2 = V_2 ;
F_150 ( & V_16 -> V_67 ) ;
F_151 ( & V_16 -> V_210 , F_116 ) ;
F_34 ( V_16 , V_7 ) ;
}
return 0 ;
}
static int F_152 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_8 ; V_7 ++ ) {
struct V_15 * V_16 = F_3 ( V_4 , V_7 ) ;
T_1 V_6 = V_16 -> V_6 ;
F_28 ( V_2 , V_6 ) ;
if ( ! F_1 ( V_2 ) )
F_153 ( V_2 , V_6 ,
V_2 -> V_253 > 0 ?
F_58 : NULL ) ;
}
return 0 ;
}
static void F_154 ( struct V_3 * V_4 , int V_254 )
{
F_155 ( & V_4 -> V_224 , sizeof( struct V_15 ) , V_254 ) ;
F_155 ( & V_4 -> V_226 , sizeof( struct V_159 ) , V_254 ) ;
}
static void F_156 ( struct V_3 * V_4 )
{
F_157 ( & V_4 -> V_224 ) ;
F_157 ( & V_4 -> V_226 ) ;
}
static void F_158 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_7 , V_12 ;
if ( F_1 ( V_2 ) )
F_159 ( NULL ) ;
for ( V_7 = 0 ; V_7 < V_4 -> V_8 ; V_7 ++ ) {
struct V_15 * V_16 = F_3 ( V_4 , V_7 ) ;
F_160 ( & V_16 -> V_210 ) ;
F_37 ( V_16 ) ;
}
for ( V_12 = 0 ; V_12 < V_4 -> V_13 ; V_12 ++ ) {
if ( V_4 -> V_214 [ V_12 ] . V_121 == NULL )
continue;
if ( V_4 -> V_185 )
F_161 ( V_2 -> V_71 ,
V_4 -> V_214 [ V_12 ] . V_121 ) ;
else
V_4 -> V_214 [ V_12 ] . V_121 = NULL ;
}
if ( V_4 -> V_255 )
F_162 ( & V_2 -> V_78 -> V_112 ) ;
F_156 ( V_4 ) ;
F_163 ( V_4 ) ;
}
static int F_164 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_7 ;
V_2 -> V_256 . V_257 ( V_2 ) ;
F_165 ( V_2 -> V_112 . V_258 ) ;
for ( V_7 = 0 ; V_7 < V_4 -> V_8 ; V_7 ++ ) {
struct V_15 * V_16 = F_3 ( V_4 , V_7 ) ;
F_56 ( V_16 , 1 ) ;
}
return 0 ;
}
static void F_122 ( struct V_1 * V_2 ,
T_1 V_119 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_259 [ 4 ] ;
int V_260 ;
V_260 = F_90 ( V_2 , V_119 , V_259 , F_17 ( V_259 ) ) ;
if ( V_260 == V_4 -> V_21 &&
! memcmp ( V_259 , V_4 -> V_169 , V_4 -> V_21 * sizeof( T_1 ) ) )
return;
F_8 ( V_2 , L_27 , V_119 ) ;
F_166 ( V_2 , V_119 , V_4 -> V_21 , V_4 -> V_169 ) ;
}
static void F_167 ( struct V_1 * V_2 ,
bool V_261 )
{
unsigned int V_262 ;
V_262 = F_24 ( V_2 , V_263 , 0 ,
V_264 , 0 ) ;
if ( V_262 == - 1 || V_262 & V_265 )
return;
V_262 |= V_265 ;
V_262 = F_24 ( V_2 , V_263 , 0 ,
V_266 , V_262 ) ;
if ( V_262 == - 1 )
return;
if ( V_261 )
F_168 ( V_2 ) ;
}
static void F_169 ( struct V_1 * V_2 )
{
unsigned int V_262 ;
V_262 = F_24 ( V_2 , V_263 , 0 ,
V_264 , 0 ) ;
if ( V_262 == - 1 || V_262 & V_267 )
return;
V_262 |= V_267 ;
F_170 ( & V_2 -> V_112 , V_266 ) ;
F_74 ( V_2 , V_263 , 0 ,
V_266 , V_262 ) ;
}
static void F_171 ( struct V_1 * V_2 , T_1 V_268 ,
unsigned int V_269 )
{
if ( V_269 == V_141 ) {
F_167 ( V_2 , false ) ;
F_169 ( V_2 ) ;
}
F_24 ( V_2 , V_268 , 0 , V_142 , V_269 ) ;
F_172 ( V_2 , V_268 , V_269 ) ;
}
static void F_173 ( void * V_270 , int V_271 )
{
struct V_1 * V_2 = V_270 ;
int V_6 = V_271 + 0x04 ;
if ( V_271 < 1 || V_271 > 3 )
return;
if ( F_174 ( V_2 -> V_71 ) != V_272 )
return;
if ( F_175 ( & ( V_2 ) -> V_112 . V_273 ) )
return;
F_176 ( & V_2 -> V_78 -> V_112 ) ;
F_55 ( V_2 , V_6 ) ;
}
static int F_177 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_178 ( sizeof( * V_4 ) , V_274 ) ;
if ( V_4 == NULL )
return - V_46 ;
V_4 -> V_116 = V_275 ;
F_150 ( & V_4 -> V_30 ) ;
F_179 ( & V_2 -> V_112 , & V_4 -> V_110 ) ;
V_4 -> V_110 . V_116 . V_276 = F_135 ;
V_4 -> V_110 . V_116 . V_277 = F_136 ;
V_4 -> V_110 . V_116 . V_278 = F_137 ;
V_2 -> V_4 = V_4 ;
F_154 ( V_4 , 4 ) ;
#ifdef F_180
if ( ( V_2 -> V_112 . V_279 >> 16 ) == 0x8086 &&
F_51 ( V_2 ) ) {
#if 0
if (!codec->bus->core.audio_component)
if (!snd_hdac_i915_init(&codec->bus->core))
spec->i915_bound = true;
#endif
if ( V_2 -> V_78 -> V_112 . V_280 )
V_4 -> V_5 = true ;
}
#endif
if ( F_51 ( V_2 ) ) {
F_167 ( V_2 , true ) ;
F_169 ( V_2 ) ;
}
if ( F_80 ( V_2 ) || F_181 ( V_2 ) ||
F_182 ( V_2 ) )
V_2 -> V_112 . V_281 = 1 ;
if ( F_127 ( V_2 ) < 0 ) {
if ( V_4 -> V_255 )
F_162 ( & V_2 -> V_78 -> V_112 ) ;
V_2 -> V_4 = NULL ;
F_163 ( V_4 ) ;
return - V_9 ;
}
V_2 -> V_256 = V_282 ;
if ( F_51 ( V_2 ) ) {
V_2 -> V_256 . V_283 = F_171 ;
V_2 -> V_284 = true ;
}
if ( F_51 ( V_2 ) || F_80 ( V_2 ) )
V_2 -> V_285 = 1 ;
F_149 ( V_2 ) ;
if ( F_1 ( V_2 ) ) {
V_2 -> V_286 = 0 ;
V_4 -> V_287 . V_270 = V_2 ;
F_183 () ;
V_4 -> V_287 . V_288 = F_173 ;
F_159 ( & V_4 -> V_287 ) ;
}
F_184 ( V_4 -> V_185 && ! F_1 ( V_2 ) ) ;
return 0 ;
}
static int F_185 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_193 * V_113 ;
unsigned int V_225 ;
struct V_10 * V_241 ;
struct V_159 * V_160 ;
V_160 = F_11 ( V_4 , 0 ) ;
V_225 = F_29 ( V_2 , V_160 -> V_19 ) ;
V_225 = F_125 ( V_225 ) ;
V_113 = F_139 ( V_2 , L_28 ) ;
if ( ! V_113 )
return - V_46 ;
V_4 -> V_214 [ 0 ] . V_17 = V_113 ;
V_113 -> V_242 = V_243 ;
V_241 = & V_113 -> V_14 [ V_245 ] ;
* V_241 = V_4 -> V_289 ;
V_241 -> V_119 = V_160 -> V_19 ;
if ( V_241 -> V_179 <= 2 && V_225 && V_225 <= 16 )
V_241 -> V_179 = V_225 ;
return 0 ;
}
static void F_186 ( struct V_1 * V_2 ,
unsigned int V_122 )
{
F_187 ( V_2 ) ;
F_57 ( V_2 ) ;
}
static int F_188 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_159 * V_160 ;
int V_44 ;
V_160 = F_11 ( V_4 , 0 ) ;
V_44 = F_147 ( V_2 , V_160 -> V_19 ,
V_160 -> V_19 ,
V_243 ) ;
if ( V_44 < 0 )
return V_44 ;
return F_189 ( V_2 , 0 ) ;
}
static int F_190 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_15 * V_16 = F_3 ( V_4 , 0 ) ;
T_1 V_290 = V_16 -> V_6 ;
F_26 ( V_2 , V_290 , 0 ,
V_61 , V_60 ) ;
if ( F_29 ( V_2 , V_290 ) & V_56 )
F_26 ( V_2 , V_290 , 0 , V_57 ,
V_58 ) ;
F_191 ( V_2 , V_290 ) ;
return 0 ;
}
static void F_192 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_156 ( V_4 ) ;
F_163 ( V_4 ) ;
}
static int F_193 ( struct V_1 * V_2 )
{
F_194 ( V_2 , V_291 ) ;
return 0 ;
}
static int F_195 ( struct V_1 * V_2 )
{
F_194 ( V_2 , V_292 ) ;
return 0 ;
}
static int F_196 ( struct V_10 * V_11 ,
struct V_1 * V_2 ,
struct V_173 * V_174 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_293 * V_294 = NULL ;
switch ( V_2 -> V_295 -> V_279 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_294 = & V_296 ;
break;
case 0x10de0007 :
V_294 = & V_297 ;
break;
default:
break;
}
if ( V_294 != NULL ) {
V_293 ( V_174 -> V_176 , 0 ,
V_184 ,
V_294 ) ;
} else {
F_83 ( V_174 -> V_176 , 0 ,
V_184 , 2 ) ;
}
return F_197 ( V_2 , & V_4 -> V_298 ) ;
}
static int F_198 ( struct V_10 * V_11 ,
struct V_1 * V_2 ,
struct V_173 * V_174 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
return F_199 ( V_2 , & V_4 -> V_298 ) ;
}
static int F_200 ( struct V_10 * V_11 ,
struct V_1 * V_2 ,
unsigned int V_154 ,
unsigned int V_155 ,
struct V_173 * V_174 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
return F_201 ( V_2 , & V_4 -> V_298 ,
V_154 , V_155 , V_174 ) ;
}
static int F_202 ( struct V_1 * V_2 ,
T_1 V_19 , T_1 V_6 )
{
struct V_3 * V_4 ;
struct V_159 * V_160 ;
struct V_15 * V_16 ;
V_4 = F_178 ( sizeof( * V_4 ) , V_274 ) ;
if ( ! V_4 )
return - V_46 ;
V_2 -> V_4 = V_4 ;
F_154 ( V_4 , 1 ) ;
V_4 -> V_298 . V_299 = 0 ;
V_4 -> V_298 . V_300 = 2 ;
V_4 -> V_298 . V_301 = V_19 ;
V_4 -> V_21 = 1 ;
V_4 -> V_8 = 1 ;
V_16 = F_123 ( & V_4 -> V_224 ) ;
V_160 = F_123 ( & V_4 -> V_226 ) ;
if ( ! V_16 || ! V_160 ) {
F_192 ( V_2 ) ;
return - V_46 ;
}
V_160 -> V_19 = V_19 ;
V_16 -> V_6 = V_6 ;
V_4 -> V_289 = V_302 ;
V_2 -> V_256 = V_303 ;
return 0 ;
}
static void F_203 ( struct V_1 * V_2 ,
int V_111 )
{
unsigned int V_304 ;
int V_305 = V_111 ? ( V_111 - 1 ) : 1 ;
switch ( V_111 ) {
default:
case 0 :
case 2 :
V_304 = 0x00 ;
break;
case 4 :
V_304 = 0x08 ;
break;
case 6 :
V_304 = 0x0b ;
break;
case 8 :
V_304 = 0x13 ;
break;
}
F_26 ( V_2 , 0x1 , 0 ,
V_306 , V_304 ) ;
F_26 ( V_2 , 0x1 , 0 ,
V_307 ,
( 0x71 - V_305 - V_304 ) ) ;
}
static int F_204 ( struct V_10 * V_11 ,
struct V_1 * V_2 ,
struct V_173 * V_174 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_18 ;
F_26 ( V_2 , V_308 ,
0 , V_309 , 0 ) ;
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ ) {
F_26 ( V_2 , V_310 [ V_18 ] , 0 ,
V_309 , 0 ) ;
F_26 ( V_2 , V_310 [ V_18 ] , 0 ,
V_311 , 0 ) ;
}
F_203 ( V_2 , 8 ) ;
return F_199 ( V_2 , & V_4 -> V_298 ) ;
}
static int F_205 ( struct V_10 * V_11 ,
struct V_1 * V_2 ,
unsigned int V_154 ,
unsigned int V_155 ,
struct V_173 * V_174 )
{
int V_312 ;
unsigned int V_313 , V_314 ;
int V_18 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_231 * V_232 ;
struct V_159 * V_160 ;
F_14 ( & V_2 -> V_233 ) ;
V_160 = F_11 ( V_4 , 0 ) ;
V_232 = F_129 ( V_2 , V_160 -> V_19 ) ;
V_312 = V_174 -> V_176 -> V_111 ;
V_313 = 0x2 ;
if ( V_2 -> V_315 && ( V_232 -> V_316 & V_317 ) )
F_26 ( V_2 ,
V_308 ,
0 ,
V_318 ,
V_232 -> V_316 & ~ V_317 & 0xff ) ;
F_26 ( V_2 , V_308 , 0 ,
V_309 , ( V_154 << 4 ) | 0x0 ) ;
F_26 ( V_2 , V_308 , 0 ,
V_311 , V_155 ) ;
if ( V_2 -> V_315 && ( V_232 -> V_316 & V_317 ) ) {
F_26 ( V_2 ,
V_308 ,
0 ,
V_318 ,
V_232 -> V_316 & 0xff ) ;
F_26 ( V_2 ,
V_308 ,
0 ,
V_319 , V_313 ) ;
}
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ ) {
if ( V_312 == 2 )
V_314 = 0 ;
else
V_314 = V_18 * 2 ;
if ( V_2 -> V_315 &&
( V_232 -> V_316 & V_317 ) )
F_26 ( V_2 ,
V_310 [ V_18 ] ,
0 ,
V_318 ,
V_232 -> V_316 & ~ V_317 & 0xff ) ;
F_26 ( V_2 ,
V_310 [ V_18 ] ,
0 ,
V_309 ,
( V_154 << 4 ) | V_314 ) ;
F_26 ( V_2 ,
V_310 [ V_18 ] ,
0 ,
V_311 ,
V_155 ) ;
if ( V_2 -> V_315 &&
( V_232 -> V_316 & V_317 ) ) {
F_26 ( V_2 ,
V_310 [ V_18 ] ,
0 ,
V_318 ,
V_232 -> V_316 & 0xff ) ;
F_26 ( V_2 ,
V_310 [ V_18 ] ,
0 ,
V_319 , V_313 ) ;
}
}
F_203 ( V_2 , V_312 ) ;
F_15 ( & V_2 -> V_233 ) ;
return 0 ;
}
static int F_206 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_44 = F_202 ( V_2 , V_308 ,
V_320 ) ;
if ( V_44 < 0 )
return V_44 ;
V_2 -> V_256 . V_257 = F_193 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_289 . V_180 = V_321 ;
V_4 -> V_289 . V_182 = V_322 ;
V_4 -> V_289 . V_181 = V_323 ;
return 0 ;
}
static int F_207 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_44 = F_185 ( V_2 ) ;
if ( ! V_44 ) {
struct V_193 * V_113 = F_6 ( V_4 , 0 ) ;
V_113 -> V_244 = true ;
}
return V_44 ;
}
static int F_208 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_193 * V_113 ;
struct V_324 * V_110 ;
int V_44 ;
V_44 = F_188 ( V_2 ) ;
if ( V_44 < 0 )
return V_44 ;
V_113 = F_6 ( V_4 , 0 ) ;
V_44 = F_209 ( V_113 -> V_17 ,
V_245 ,
V_325 , 8 , 0 , & V_110 ) ;
if ( V_44 < 0 )
return V_44 ;
switch ( V_2 -> V_295 -> V_279 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_110 -> V_326 = ( 1U << 2 ) | ( 1U << 8 ) ;
break;
case 0x10de0007 :
V_110 -> V_326 = ( 1U << 2 ) | ( 1U << 6 ) | ( 1U << 8 ) ;
}
return 0 ;
}
static int F_210 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_44 = F_206 ( V_2 ) ;
if ( V_44 < 0 )
return V_44 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_298 . V_300 = 8 ;
V_4 -> V_289 = V_327 ;
V_2 -> V_256 . V_257 = F_195 ;
V_2 -> V_256 . V_328 = F_207 ;
V_2 -> V_256 . V_329 = F_208 ;
F_203 ( V_2 , 8 ) ;
return 0 ;
}
static int F_211 ( struct V_109 * V_110 ,
struct V_330 * V_331 , int V_111 )
{
if ( V_331 -> V_332 == 0x00 && V_111 == 2 )
return V_333 ;
if ( V_331 -> V_111 != V_111 )
return - 1 ;
return V_334 ;
}
static int F_212 ( struct V_109 * V_110 ,
int V_95 , int V_312 , unsigned char * V_335 )
{
if ( V_95 == 0x00 && ( V_335 [ 0 ] != V_336 || V_335 [ 1 ] != V_337 ) )
return - V_9 ;
return 0 ;
}
static int F_213 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_44 ;
V_44 = F_177 ( V_2 ) ;
if ( V_44 )
return V_44 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_59 = true ;
V_4 -> V_110 . V_116 . V_338 =
F_211 ;
V_4 -> V_110 . V_116 . V_339 = F_212 ;
return 0 ;
}
static void F_214 ( struct V_1 * V_2 , unsigned int V_155 )
{
unsigned int V_37 ;
V_37 = F_24 ( V_2 , V_340 , 0 ,
V_341 , 0 ) ;
V_37 = ( V_37 >> 24 ) & 0xff ;
F_26 ( V_2 , V_340 , 0 ,
V_342 ,
( V_155 >> 0 ) & 0xff ) ;
F_26 ( V_2 , V_340 , 0 ,
V_343 ,
( V_155 >> 8 ) & 0xff ) ;
F_26 ( V_2 , V_340 , 0 ,
V_344 , 0 ) ;
if ( V_155 == 0 )
V_37 &= ~ V_345 ;
else
V_37 |= V_345 ;
V_37 ^= V_346 ;
F_26 ( V_2 , V_340 , 0 ,
V_347 , V_37 ) ;
}
static int F_215 ( struct V_10 * V_11 ,
struct V_1 * V_2 ,
unsigned int V_154 ,
unsigned int V_155 ,
struct V_173 * V_174 )
{
int V_44 ;
V_44 = F_130 ( V_11 , V_2 , V_154 ,
V_155 , V_174 ) ;
if ( V_44 < 0 )
return V_44 ;
F_214 ( V_2 , V_155 ) ;
return 0 ;
}
static int F_216 ( struct V_10 * V_11 ,
struct V_1 * V_2 ,
struct V_173 * V_174 )
{
F_214 ( V_2 , 0 ) ;
return F_132 ( V_11 , V_2 , V_174 ) ;
}
static struct V_193 * F_217 ( struct V_1 * V_2 , int type )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_18 ;
for ( V_18 = 0 ; V_18 < V_4 -> V_8 ; V_18 ++ ) {
struct V_193 * V_17 = F_6 ( V_4 , V_18 ) ;
if ( V_17 -> V_242 == type )
return V_17 ;
}
return NULL ;
}
static int F_218 ( struct V_1 * V_2 )
{
struct V_10 * V_14 ;
struct V_193 * V_17 ;
int V_44 ;
V_44 = F_138 ( V_2 ) ;
if ( V_44 < 0 )
return V_44 ;
V_17 = F_217 ( V_2 , V_243 ) ;
if ( ! V_17 )
return - V_187 ;
V_14 = & V_17 -> V_14 [ V_245 ] ;
V_14 -> V_116 . V_348 = F_215 ;
V_14 -> V_116 . V_349 = F_216 ;
return 0 ;
}
static int F_219 ( struct V_1 * V_2 )
{
int V_44 ;
V_44 = F_177 ( V_2 ) ;
if ( V_44 )
return V_44 ;
V_2 -> V_256 . V_328 = F_218 ;
return 0 ;
}
static int F_220 ( struct V_1 * V_2 , T_1 V_119 ,
unsigned char * V_350 , int * V_34 )
{
return F_221 ( V_2 , V_119 , V_350 , V_34 ,
F_222 ( V_2 ) ) ;
}
static void F_223 ( struct V_1 * V_2 , T_1 V_6 , int V_95 ,
int V_96 , int V_97 )
{
F_26 ( V_2 , V_6 , 0 , V_351 , V_95 ) ;
}
static int F_224 ( int V_352 )
{
switch ( V_352 ) {
case 2 : return 3 ;
case 3 : return 2 ;
default: break;
}
return V_352 ;
}
static int F_225 ( struct V_109 * V_110 ,
int V_95 , int V_312 , unsigned char * V_335 )
{
struct V_330 * V_331 ;
int V_18 , V_85 ;
V_331 = F_226 ( V_95 ) ;
for ( V_18 = 0 ; V_18 < V_312 ; ++ V_18 ) {
int V_353 = F_227 ( V_335 [ V_18 ] ) ;
bool V_354 = false ;
bool V_355 = false ;
if ( ! V_353 )
continue;
for ( V_85 = 0 + V_18 % 2 ; V_85 < 8 ; V_85 += 2 ) {
int V_356 = 7 - F_224 ( V_85 ) ;
if ( V_331 -> V_357 [ V_356 ] == V_353 ) {
V_354 = true ;
if ( V_18 % 2 == 0 && V_18 + 1 < V_312 ) {
int V_358 = 7 - F_224 ( V_85 + 1 ) ;
int V_359 = F_227 ( V_335 [ V_18 + 1 ] ) ;
int V_360 = V_331 -> V_357 [ V_358 ] ;
if ( V_359 == V_360 )
V_355 = true ;
else
return - V_9 ;
}
break;
}
}
if ( ! V_354 )
return - V_9 ;
if ( V_355 )
V_18 ++ ;
}
return 0 ;
}
static int F_228 ( struct V_238 * V_239 ,
T_1 V_6 , int V_361 , int V_362 )
{
struct V_1 * V_2 = F_117 ( V_239 , struct V_1 , V_112 ) ;
int V_363 ;
int V_364 = 0 ;
if ( V_361 > 7 )
return - V_9 ;
if ( ! F_229 ( V_2 ) ) {
V_361 = F_224 ( V_361 ) ;
if ( V_361 % 2 != 0 && V_362 == 0xf )
return 0 ;
V_361 -= V_361 % 2 ;
if ( V_362 != 0xf )
V_362 -= V_362 % 2 ;
}
V_363 = V_365 + V_361 / 2 + ( V_361 % 2 ) * 0x00e ;
if ( V_362 != 0xf )
V_364 = ( V_362 << 4 ) | V_366 ;
return F_26 ( V_2 , V_6 , 0 , V_363 , V_364 ) ;
}
static int F_230 ( struct V_238 * V_239 ,
T_1 V_6 , int V_367 )
{
struct V_1 * V_2 = F_117 ( V_239 , struct V_1 , V_112 ) ;
bool V_368 = false ;
int V_369 = V_367 ;
int V_363 ;
int V_364 ;
if ( V_367 > 7 )
return - V_9 ;
if ( ! F_229 ( V_2 ) ) {
V_369 = F_224 ( V_367 ) ;
if ( V_369 % 2 != 0 ) {
V_369 -= 1 ;
V_368 = true ;
}
}
V_363 = V_370 + V_369 / 2 + ( V_369 % 2 ) * 0x00e ;
V_364 = F_24 ( V_2 , V_6 , 0 , V_363 , 0 ) ;
if ( ! ( V_364 & V_366 ) )
return 0xf ;
return ( ( V_364 & 0xf0 ) >> 4 ) + ! ! V_368 ;
}
static int F_231 (
struct V_109 * V_110 ,
struct V_330 * V_331 ,
int V_111 )
{
int V_72 ;
int V_371 = 0 ;
if ( ( V_111 % 2 ) != 0 )
return - 1 ;
for ( V_72 = 0 ; V_72 < 7 ; V_72 += 2 ) {
if ( V_331 -> V_357 [ V_72 ] || V_331 -> V_357 [ V_72 + 1 ] )
V_371 ++ ;
}
if ( V_371 * 2 != V_111 )
return - 1 ;
return V_372 ;
}
static void F_232 ( struct V_109 * V_373 ,
struct V_330 * V_331 ,
unsigned int * V_110 , int V_111 )
{
int V_31 = 0 ;
int V_72 ;
for ( V_72 = 7 ; V_72 >= 0 ; V_72 -- ) {
int V_305 = 7 - F_224 ( 7 - V_72 ) ;
int V_374 = V_331 -> V_357 [ V_305 ] ;
if ( ! V_374 ) {
if ( V_331 -> V_357 [ V_305 + ( V_305 % 2 ? - 1 : 1 ) ] )
V_110 [ V_31 ++ ] = V_375 ;
continue;
}
V_110 [ V_31 ++ ] = F_233 ( V_374 ) ;
}
F_184 ( V_31 != V_111 ) ;
}
static int F_234 ( struct V_1 * V_2 , T_1 V_6 ,
bool V_146 )
{
int V_376 , V_377 ;
V_376 = F_24 ( V_2 , V_6 , 0 , V_378 , 0 ) ;
if ( V_376 >= 0 && ( V_376 & V_379 ) ) {
if ( V_146 )
V_377 = V_376 | V_380 ;
else
V_377 = V_376 & ~ V_380 ;
F_8 ( V_2 ,
L_29 ,
V_6 ,
V_376 == V_377 ? L_16 : L_17 ,
V_377 ) ;
if ( V_376 != V_377 )
F_26 ( V_2 , V_6 , 0 ,
V_381 ,
V_377 ) ;
} else if ( V_146 )
return - V_9 ;
return 0 ;
}
static int F_235 ( struct V_1 * V_2 , T_1 V_19 ,
T_1 V_6 , T_3 V_154 , int V_155 )
{
if ( F_222 ( V_2 ) ) {
int V_382 = 180 ;
if ( V_155 & V_383 )
V_382 = 0 ;
F_26 ( V_2 , V_19 , 0 , V_384 , V_382 ) ;
}
return F_69 ( V_2 , V_19 , V_6 , V_154 , V_155 ) ;
}
static int F_236 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_7 , V_44 ;
V_44 = F_152 ( V_2 ) ;
if ( V_44 )
return V_44 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_8 ; V_7 ++ ) {
struct V_15 * V_16 = F_3 ( V_4 , V_7 ) ;
F_26 ( V_2 , V_16 -> V_6 , 0 , V_385 , 0 ) ;
if ( F_229 ( V_2 ) )
F_26 ( V_2 , V_16 -> V_6 , 0 ,
V_386 ,
V_387 ) ;
}
return 0 ;
}
static int F_237 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_159 * V_160 ;
int V_44 , V_20 ;
V_44 = F_177 ( V_2 ) ;
if ( V_44 )
return V_44 ;
V_2 -> V_256 . V_257 = F_236 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_116 . V_209 = F_220 ;
V_4 -> V_116 . V_118 = F_223 ;
V_4 -> V_116 . V_156 = F_234 ;
V_4 -> V_116 . V_237 = F_235 ;
V_4 -> V_110 . V_116 . V_388 = F_230 ;
V_4 -> V_110 . V_116 . V_389 = F_228 ;
if ( ! F_229 ( V_2 ) ) {
V_4 -> V_110 . V_116 . V_338 =
F_231 ;
V_4 -> V_110 . V_116 . V_390 =
F_232 ;
V_4 -> V_110 . V_116 . V_339 = F_225 ;
}
for ( V_20 = 0 ; V_20 < V_4 -> V_21 ; V_20 ++ ) {
V_160 = F_11 ( V_4 , V_20 ) ;
V_160 -> V_179 = F_238 ( V_160 -> V_179 , 8u ) ;
V_160 -> V_180 |= V_321 ;
V_160 -> V_181 |= V_323 ;
V_160 -> V_182 = F_238 ( V_160 -> V_182 , 24u ) ;
}
V_4 -> V_110 . V_179 = F_238 ( V_4 -> V_110 . V_179 , 8u ) ;
return 0 ;
}
static int F_239 ( struct V_1 * V_2 )
{
return F_202 ( V_2 , V_391 , V_392 ) ;
}
