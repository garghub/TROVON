static inline bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
return V_4 -> V_5 ;
}
static int F_2 ( struct V_1 * V_2 ,
T_1 V_6 , int V_7 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_8 ;
struct V_9 * V_10 ;
if ( V_7 == - 1 )
V_7 = 0 ;
for ( V_8 = 0 ; V_8 < V_4 -> V_11 ; V_8 ++ ) {
V_10 = F_3 ( V_4 , V_8 ) ;
if ( ( V_10 -> V_6 == V_6 ) &&
( V_10 -> V_7 == V_7 ) )
return V_8 ;
}
F_4 ( V_2 , L_1 , V_6 ) ;
return - V_12 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_4 -> V_16 ; V_15 ++ )
if ( F_6 ( V_4 , V_15 ) -> V_17 == V_14 )
return V_15 ;
F_4 ( V_2 , L_2 , V_14 ) ;
return - V_12 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 -> V_11 ; V_8 ++ ) {
V_10 = F_3 ( V_4 , V_8 ) ;
if ( V_10 -> V_18 &&
V_10 -> V_18 -> V_18 -> V_17 == V_14 )
return V_8 ;
}
F_8 ( V_2 , L_2 , V_14 ) ;
return - V_12 ;
}
static struct V_9 * F_9 ( struct V_3 * V_4 ,
int V_15 )
{
int V_19 ;
struct V_9 * V_10 ;
for ( V_19 = 0 ; V_19 < V_4 -> V_11 ; V_19 ++ ) {
V_10 = F_3 ( V_4 , V_19 ) ;
if ( V_10 -> V_15 == V_15 )
return V_10 ;
}
return NULL ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_20 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_4 -> V_22 ; V_21 ++ )
if ( F_11 ( V_4 , V_21 ) -> V_20 == V_20 )
return V_21 ;
F_4 ( V_2 , L_3 , V_20 ) ;
return - V_12 ;
}
static int F_12 ( struct V_23 * V_24 ,
struct V_25 * V_26 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 ;
struct V_27 * V_28 ;
int V_15 ;
V_26 -> type = V_29 ;
V_15 = V_24 -> V_30 ;
F_14 ( & V_4 -> V_31 ) ;
V_10 = F_9 ( V_4 , V_15 ) ;
if ( ! V_10 ) {
V_26 -> V_32 = 0 ;
F_15 ( & V_4 -> V_31 ) ;
return 0 ;
}
V_28 = & V_10 -> V_33 ;
V_26 -> V_32 = V_28 -> V_34 ? V_28 -> V_35 : 0 ;
F_15 ( & V_4 -> V_31 ) ;
return 0 ;
}
static int F_16 ( struct V_23 * V_24 ,
struct V_36 * V_37 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 ;
struct V_27 * V_28 ;
int V_15 ;
V_15 = V_24 -> V_30 ;
F_14 ( & V_4 -> V_31 ) ;
V_10 = F_9 ( V_4 , V_15 ) ;
if ( ! V_10 ) {
memset ( V_37 -> V_38 . V_39 . V_40 , 0 ,
F_17 ( V_37 -> V_38 . V_39 . V_40 ) ) ;
F_15 ( & V_4 -> V_31 ) ;
return 0 ;
}
V_28 = & V_10 -> V_33 ;
if ( V_28 -> V_35 > F_17 ( V_37 -> V_38 . V_39 . V_40 ) ||
V_28 -> V_35 > V_41 ) {
F_15 ( & V_4 -> V_31 ) ;
F_18 () ;
return - V_12 ;
}
memset ( V_37 -> V_38 . V_39 . V_40 , 0 ,
F_17 ( V_37 -> V_38 . V_39 . V_40 ) ) ;
if ( V_28 -> V_34 )
memcpy ( V_37 -> V_38 . V_39 . V_40 , V_28 -> V_42 ,
V_28 -> V_35 ) ;
F_15 ( & V_4 -> V_31 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_15 ,
int V_43 )
{
struct V_23 * V_44 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_45 ;
V_44 = F_20 ( & V_46 , V_2 ) ;
if ( ! V_44 )
return - V_47 ;
V_44 -> V_30 = V_15 ;
V_44 -> V_48 . V_43 = V_43 ;
V_45 = F_21 ( V_2 , 0 , V_44 ) ;
if ( V_45 < 0 )
return V_45 ;
F_22 ( V_4 , V_15 ) -> V_49 = V_44 ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 , T_1 V_6 ,
int * V_50 , int * V_51 )
{
int V_52 ;
V_52 = F_24 ( V_2 , V_6 , 0 ,
V_53 , 0 ) ;
* V_50 = V_52 >> 5 ;
* V_51 = V_52 & 0x1f ;
}
static void F_25 ( struct V_1 * V_2 , T_1 V_6 ,
int V_50 , int V_51 )
{
int V_52 ;
V_52 = ( V_50 << 5 ) | ( V_51 & 0x1f ) ;
F_26 ( V_2 , V_6 , 0 , V_54 , V_52 ) ;
}
static void F_27 ( struct V_1 * V_2 , T_1 V_6 ,
unsigned char V_52 )
{
F_26 ( V_2 , V_6 , 0 , V_55 , V_52 ) ;
}
static void F_28 ( struct V_1 * V_2 , T_1 V_6 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_56 ;
if ( F_29 ( V_2 , V_6 ) & V_57 )
F_26 ( V_2 , V_6 , 0 ,
V_58 , V_59 ) ;
if ( V_4 -> V_60 )
V_56 = 0 ;
else
V_56 = V_61 ;
F_26 ( V_2 , V_6 , 0 ,
V_62 , V_56 ) ;
}
static void F_30 ( struct V_63 * V_64 ,
struct V_65 * V_66 )
{
struct V_9 * V_10 = V_64 -> V_67 ;
F_14 ( & V_10 -> V_68 ) ;
F_31 ( & V_10 -> V_33 , V_66 ) ;
F_15 ( & V_10 -> V_68 ) ;
}
static void F_32 ( struct V_63 * V_64 ,
struct V_65 * V_66 )
{
struct V_9 * V_10 = V_64 -> V_67 ;
F_14 ( & V_10 -> V_68 ) ;
F_33 ( & V_10 -> V_33 , V_66 ) ;
F_15 ( & V_10 -> V_68 ) ;
}
static int F_34 ( struct V_9 * V_10 , int V_69 )
{
char V_70 [ 32 ] ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_63 * V_64 ;
int V_45 ;
snprintf ( V_70 , sizeof( V_70 ) , L_4 , V_2 -> V_71 , V_69 ) ;
V_45 = F_35 ( V_2 -> V_72 , V_70 , & V_64 ) ;
if ( V_45 < 0 )
return V_45 ;
F_36 ( V_64 , V_10 , F_30 ) ;
V_64 -> V_73 . V_74 . V_75 = F_32 ;
V_64 -> V_76 |= V_77 ;
V_10 -> V_78 = V_64 ;
return 0 ;
}
static void F_37 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_2 -> V_79 -> V_80 ) {
F_38 ( V_10 -> V_78 ) ;
V_10 -> V_78 = NULL ;
}
}
static inline int F_34 ( struct V_9 * V_10 ,
int V_69 )
{
return 0 ;
}
static inline void F_37 ( struct V_9 * V_10 )
{
}
static void F_39 ( struct V_1 * V_2 ,
T_1 V_6 )
{
F_25 ( V_2 , V_6 , 0x0 , 0x0 ) ;
F_26 ( V_2 , V_6 , 0 , V_81 ,
V_82 ) ;
}
static void F_40 ( struct V_1 * V_2 ,
T_1 V_6 )
{
F_25 ( V_2 , V_6 , 0x0 , 0x0 ) ;
F_26 ( V_2 , V_6 , 0 , V_81 ,
V_83 ) ;
}
static void F_41 ( struct V_1 * V_2 , T_1 V_6 )
{
#ifdef F_42
int V_19 ;
int V_84 ;
V_84 = F_43 ( V_2 , V_6 ) ;
F_8 ( V_2 , L_5 , V_84 ) ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
V_84 = F_24 ( V_2 , V_6 , 0 ,
V_85 , V_19 ) ;
F_8 ( V_2 , L_6 , V_19 , V_84 ) ;
}
#endif
}
static void F_44 ( struct V_1 * V_2 , T_1 V_6 )
{
#ifdef F_45
int V_19 , V_86 ;
int V_84 ;
int V_87 , V_88 ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
V_84 = F_24 ( V_2 , V_6 , 0 ,
V_85 , V_19 ) ;
if ( V_84 == 0 )
continue;
F_25 ( V_2 , V_6 , V_19 , 0x0 ) ;
for ( V_86 = 1 ; V_86 < 1000 ; V_86 ++ ) {
F_27 ( V_2 , V_6 , 0x0 ) ;
F_23 ( V_2 , V_6 , & V_87 , & V_88 ) ;
if ( V_87 != V_19 )
F_8 ( V_2 , L_7 ,
V_88 , V_87 , V_19 ) ;
if ( V_88 == 0 )
break;
}
F_8 ( V_2 ,
L_8 ,
V_19 , V_84 , V_86 ) ;
}
#endif
}
static void F_46 ( struct V_89 * V_90 )
{
T_2 * V_39 = ( T_2 * ) V_90 ;
T_2 V_91 = 0 ;
int V_19 ;
V_90 -> V_92 = 0 ;
for ( V_19 = 0 ; V_19 < sizeof( * V_90 ) ; V_19 ++ )
V_91 += V_39 [ V_19 ] ;
V_90 -> V_92 = - V_91 ;
}
static void F_47 ( struct V_1 * V_2 ,
T_1 V_6 ,
T_2 * V_93 , int V_84 )
{
int V_19 ;
F_41 ( V_2 , V_6 ) ;
F_44 ( V_2 , V_6 ) ;
F_25 ( V_2 , V_6 , 0x0 , 0x0 ) ;
for ( V_19 = 0 ; V_19 < V_84 ; V_19 ++ )
F_27 ( V_2 , V_6 , V_93 [ V_19 ] ) ;
}
static bool F_48 ( struct V_1 * V_2 , T_1 V_6 ,
T_2 * V_93 , int V_84 )
{
T_2 V_52 ;
int V_19 ;
if ( F_24 ( V_2 , V_6 , 0 , V_94 , 0 )
!= V_82 )
return false ;
F_25 ( V_2 , V_6 , 0x0 , 0x0 ) ;
for ( V_19 = 0 ; V_19 < V_84 ; V_19 ++ ) {
V_52 = F_24 ( V_2 , V_6 , 0 ,
V_95 , 0 ) ;
if ( V_52 != V_93 [ V_19 ] )
return false ;
}
return true ;
}
static void F_49 ( struct V_1 * V_2 ,
T_1 V_6 ,
int V_96 , int V_97 ,
int V_98 )
{
union V_99 V_100 ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
if ( V_98 == 0 ) {
struct V_89 * V_90 = & V_100 . V_101 ;
V_90 -> type = 0x84 ;
V_90 -> V_102 = 0x01 ;
V_90 -> V_103 = 0x0a ;
V_90 -> V_104 = V_97 - 1 ;
V_90 -> V_105 = V_96 ;
F_46 ( V_90 ) ;
} else if ( V_98 == 1 ) {
struct V_106 * V_107 = & V_100 . V_108 ;
V_107 -> type = 0x84 ;
V_107 -> V_103 = 0x1b ;
V_107 -> V_102 = 0x11 << 2 ;
V_107 -> V_104 = V_97 - 1 ;
V_107 -> V_105 = V_96 ;
} else {
F_8 ( V_2 , L_9 ,
V_6 ) ;
return;
}
if ( ! F_48 ( V_2 , V_6 , V_100 . V_39 ,
sizeof( V_100 ) ) ) {
F_8 ( V_2 ,
L_10 ,
V_6 ,
V_97 , V_96 ) ;
F_40 ( V_2 , V_6 ) ;
F_47 ( V_2 , V_6 ,
V_100 . V_39 , sizeof( V_100 ) ) ;
F_39 ( V_2 , V_6 ) ;
}
}
static void F_50 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
bool V_109 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_110 * V_111 = & V_4 -> V_111 ;
T_1 V_6 = V_10 -> V_6 ;
int V_112 = V_10 -> V_112 ;
int V_97 ;
struct V_27 * V_28 ;
int V_96 ;
if ( ! V_112 )
return;
if ( F_29 ( V_2 , V_6 ) & V_57 )
F_26 ( V_2 , V_6 , 0 ,
V_58 ,
V_59 ) ;
V_28 = & V_10 -> V_33 ;
V_96 = F_51 ( & V_2 -> V_113 ,
V_28 -> V_114 . V_115 , V_112 ,
V_10 -> V_116 , V_109 , V_10 -> V_111 ) ;
V_97 = F_52 ( V_96 ) ;
V_111 -> V_117 . V_118 ( & V_2 -> V_113 , V_10 -> V_20 ,
V_97 ) ;
F_53 ( & V_4 -> V_111 ,
V_6 , V_109 , V_96 , V_112 ,
V_10 -> V_111 , V_10 -> V_116 ) ;
V_4 -> V_117 . V_119 ( V_2 , V_6 , V_96 , V_97 ,
V_28 -> V_114 . V_98 ) ;
V_10 -> V_109 = V_109 ;
}
static void F_54 ( struct V_1 * V_2 , T_1 V_120 ,
int V_7 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_8 = F_2 ( V_2 , V_120 , V_7 ) ;
if ( V_8 < 0 )
return;
if ( F_55 ( F_3 ( V_4 , V_8 ) , 1 ) )
F_56 ( V_2 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_121 * V_122 )
{
F_54 ( V_2 , V_122 -> V_120 , 0 ) ;
}
static void F_58 ( struct V_1 * V_2 , unsigned int V_123 )
{
int V_124 = V_123 >> V_125 ;
struct V_126 * V_122 ;
int V_127 = ( V_123 & V_128 ) >> V_129 ;
V_122 = F_59 ( V_2 , V_124 ) ;
if ( ! V_122 )
return;
V_122 -> V_130 = 1 ;
F_8 ( V_2 ,
L_11 ,
V_2 -> V_71 , V_122 -> V_120 , V_127 , ! ! ( V_123 & V_131 ) ,
! ! ( V_123 & V_132 ) , ! ! ( V_123 & V_133 ) ) ;
F_54 ( V_2 , V_122 -> V_120 , 0 ) ;
}
static void F_60 ( struct V_1 * V_2 , unsigned int V_123 )
{
int V_124 = V_123 >> V_125 ;
int V_134 = ( V_123 & V_135 ) >> V_136 ;
int V_137 = ! ! ( V_123 & V_138 ) ;
int V_139 = ! ! ( V_123 & V_140 ) ;
F_61 ( V_2 ,
L_12 ,
V_2 -> V_71 ,
V_124 ,
V_134 ,
V_137 ,
V_139 ) ;
if ( V_137 )
;
if ( V_139 )
;
}
static void F_62 ( struct V_1 * V_2 , unsigned int V_123 )
{
int V_124 = V_123 >> V_125 ;
int V_134 = ( V_123 & V_135 ) >> V_136 ;
if ( ! F_59 ( V_2 , V_124 ) ) {
F_8 ( V_2 , L_13 , V_124 ) ;
return;
}
if ( V_134 == 0 )
F_58 ( V_2 , V_123 ) ;
else
F_60 ( V_2 , V_123 ) ;
}
static void F_63 ( struct V_1 * V_2 ,
T_1 V_20 , T_1 V_120 )
{
int V_141 ;
if ( ! F_64 ( V_2 , V_20 , V_142 ) )
F_26 ( V_2 , V_20 , 0 , V_143 , V_142 ) ;
if ( ! F_64 ( V_2 , V_120 , V_142 ) ) {
F_26 ( V_2 , V_120 , 0 , V_143 ,
V_142 ) ;
F_65 ( 40 ) ;
V_141 = F_24 ( V_2 , V_120 , 0 , V_144 , 0 ) ;
V_141 = ( V_141 & V_145 ) >> V_146 ;
F_8 ( V_2 , L_14 , V_120 , V_141 ) ;
}
}
static int F_66 ( struct V_1 * V_2 , T_1 V_6 ,
bool V_147 )
{
int V_148 , V_149 ;
if ( F_67 ( V_2 , V_6 ) & V_150 ) {
V_148 = F_24 ( V_2 , V_6 , 0 ,
V_151 , 0 ) ;
if ( V_148 < 0 )
return V_147 ? - V_12 : 0 ;
V_149 = V_148 & ~ V_152 ;
if ( V_147 )
V_149 |= V_153 ;
else
V_149 |= V_154 ;
F_8 ( V_2 ,
L_15 ,
V_6 ,
V_148 == V_149 ? L_16 : L_17 ,
V_149 ) ;
if ( V_148 != V_149 )
F_26 ( V_2 , V_6 , 0 ,
V_62 ,
V_149 ) ;
} else if ( V_147 )
return - V_12 ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , T_1 V_20 ,
T_1 V_6 , T_3 V_155 , int V_156 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_45 ;
V_45 = V_4 -> V_117 . V_157 ( V_2 , V_6 , F_69 ( V_156 ) ) ;
if ( V_45 ) {
F_8 ( V_2 , L_18 ) ;
return V_45 ;
}
F_70 ( V_2 , V_20 , V_155 , 0 , V_156 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 ,
int V_8 , int * V_158 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 ;
struct V_159 * V_160 = NULL ;
int V_21 , V_161 = 0 ;
if ( V_8 < 0 )
V_10 = NULL ;
else
V_10 = F_3 ( V_4 , V_8 ) ;
for ( V_21 = 0 ; V_21 < V_4 -> V_22 ; V_21 ++ ) {
V_160 = F_11 ( V_4 , V_21 ) ;
if ( V_160 -> V_162 )
continue;
if ( V_10 == NULL )
break;
for ( V_161 = 0 ; V_161 < V_10 -> V_163 ; V_161 ++ )
if ( V_10 -> V_164 [ V_161 ] == V_160 -> V_20 )
break;
if ( V_161 == V_10 -> V_163 )
continue;
break;
}
if ( V_21 == V_4 -> V_22 )
return - V_165 ;
if ( V_10 != NULL )
V_10 -> V_161 = V_161 ;
if ( V_158 )
* V_158 = V_21 ;
return 0 ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
T_1 V_6 = V_10 -> V_6 ;
int V_161 , V_166 ;
V_161 = V_10 -> V_161 ;
V_166 = F_24 ( V_2 , V_6 , 0 ,
V_167 , 0 ) ;
if ( V_166 != V_161 )
F_73 ( V_2 , V_6 , 0 ,
V_168 ,
V_161 ) ;
}
static int F_74 ( struct V_3 * V_4 ,
T_1 V_20 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_4 -> V_22 ; V_19 ++ )
if ( V_4 -> V_169 [ V_19 ] == V_20 )
return V_19 ;
return - V_12 ;
}
static void F_75 ( struct V_1 * V_2 ,
T_1 V_6 ,
int V_7 , int V_161 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_120 ;
int V_21 , V_166 ;
struct V_159 * V_160 ;
struct V_9 * V_10 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 -> V_11 ; V_8 ++ ) {
int V_170 ;
int V_171 ;
V_10 = F_3 ( V_4 , V_8 ) ;
if ( ! V_10 -> V_18 )
continue;
if ( ( V_10 -> V_6 == V_6 ) &&
( V_10 -> V_7 == V_7 ) )
continue;
V_171 = F_76 ( V_2 , V_10 -> V_6 ) + 1 ;
if ( V_10 -> V_7 >= V_171 )
continue;
V_120 = V_10 -> V_6 ;
V_170 = F_77 ( V_2 , V_120 ) ;
F_78 ( V_2 , V_120 , V_10 -> V_7 ) ;
V_166 = F_24 ( V_2 , V_120 , 0 ,
V_167 , 0 ) ;
if ( V_166 != V_161 ) {
F_78 ( V_2 , V_120 , V_170 ) ;
continue;
}
for ( V_21 = 0 ; V_21 < V_4 -> V_22 ; V_21 ++ ) {
V_160 = F_11 ( V_4 , V_21 ) ;
if ( ! V_160 -> V_162 ) {
F_8 ( V_2 ,
L_19 ,
V_21 , V_120 ) ;
F_73 ( V_2 , V_120 , 0 ,
V_168 ,
V_21 ) ;
break;
}
}
F_78 ( V_2 , V_120 , V_170 ) ;
}
}
static void F_79 ( struct V_1 * V_2 ,
T_1 V_6 , int V_7 , T_1 V_20 )
{
int V_161 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_161 = F_74 ( V_4 , V_20 ) ;
if ( V_161 >= 0 )
F_75 ( V_2 , V_6 , V_7 , V_161 ) ;
}
static void F_80 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
T_1 V_20 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_117 . F_80 )
V_4 -> V_117 . F_80 ( V_2 , V_10 , V_20 ) ;
}
static int F_81 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_172 * V_173 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_174 * V_175 = V_173 -> V_175 ;
int V_21 , V_15 ;
struct V_159 * V_160 = NULL ;
int V_45 ;
V_15 = F_5 ( V_2 , V_14 ) ;
if ( V_15 < 0 )
return - V_12 ;
V_45 = F_71 ( V_2 , - 1 , & V_21 ) ;
if ( V_45 )
return V_45 ;
V_160 = F_11 ( V_4 , V_21 ) ;
V_160 -> V_162 = 1 ;
V_14 -> V_120 = V_160 -> V_20 ;
F_80 ( V_2 , NULL , V_160 -> V_20 ) ;
F_82 ( V_15 , & V_4 -> V_176 ) ;
V_14 -> V_177 = V_160 -> V_177 ;
V_14 -> V_178 = V_160 -> V_178 ;
V_14 -> V_179 = V_160 -> V_179 ;
V_14 -> V_180 = V_160 -> V_180 ;
V_14 -> V_181 = V_160 -> V_181 ;
V_175 -> V_182 . V_177 = V_14 -> V_177 ;
V_175 -> V_182 . V_178 = V_14 -> V_178 ;
V_175 -> V_182 . V_180 = V_14 -> V_180 ;
V_175 -> V_182 . V_179 = V_14 -> V_179 ;
F_83 ( V_173 -> V_175 , 0 ,
V_183 , 2 ) ;
return 0 ;
}
static int F_84 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_172 * V_173 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_174 * V_175 = V_173 -> V_175 ;
int V_8 , V_21 , V_15 ;
struct V_9 * V_10 ;
struct V_27 * V_28 ;
struct V_159 * V_160 = NULL ;
int V_45 ;
V_15 = F_5 ( V_2 , V_14 ) ;
if ( V_15 < 0 )
return - V_12 ;
F_14 ( & V_4 -> V_31 ) ;
V_8 = F_7 ( V_2 , V_14 ) ;
if ( ! V_4 -> V_184 ) {
if ( F_85 ( V_8 < 0 ) ) {
F_15 ( & V_4 -> V_31 ) ;
return - V_12 ;
}
} else {
if ( V_8 < 0 ) {
V_45 = F_81 ( V_14 , V_2 , V_173 ) ;
F_15 ( & V_4 -> V_31 ) ;
return V_45 ;
}
}
V_45 = F_71 ( V_2 , V_8 , & V_21 ) ;
if ( V_45 < 0 ) {
F_15 ( & V_4 -> V_31 ) ;
return V_45 ;
}
V_160 = F_11 ( V_4 , V_21 ) ;
V_160 -> V_162 = 1 ;
F_82 ( V_15 , & V_4 -> V_176 ) ;
V_10 = F_3 ( V_4 , V_8 ) ;
V_10 -> V_20 = V_160 -> V_20 ;
V_14 -> V_120 = V_160 -> V_20 ;
F_78 ( V_2 , V_10 -> V_6 , V_10 -> V_7 ) ;
F_73 ( V_2 , V_10 -> V_6 , 0 ,
V_168 ,
V_10 -> V_161 ) ;
F_80 ( V_2 , V_10 , 0 ) ;
F_86 ( V_2 , V_15 , V_160 -> V_20 ) ;
V_14 -> V_177 = V_160 -> V_177 ;
V_14 -> V_178 = V_160 -> V_178 ;
V_14 -> V_179 = V_160 -> V_179 ;
V_14 -> V_180 = V_160 -> V_180 ;
V_14 -> V_181 = V_160 -> V_181 ;
V_28 = & V_10 -> V_33 ;
if ( ! V_185 && V_28 -> V_34 ) {
F_87 ( & V_28 -> V_114 , V_14 ) ;
if ( V_14 -> V_177 > V_14 -> V_178 ||
! V_14 -> V_179 || ! V_14 -> V_180 ) {
V_160 -> V_162 = 0 ;
V_14 -> V_120 = 0 ;
F_88 ( V_2 , V_15 ) ;
F_15 ( & V_4 -> V_31 ) ;
return - V_186 ;
}
}
F_15 ( & V_4 -> V_31 ) ;
V_175 -> V_182 . V_177 = V_14 -> V_177 ;
V_175 -> V_182 . V_178 = V_14 -> V_178 ;
V_175 -> V_182 . V_180 = V_14 -> V_180 ;
V_175 -> V_182 . V_179 = V_14 -> V_179 ;
F_83 ( V_173 -> V_175 , 0 ,
V_183 , 2 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 , int V_8 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 = F_3 ( V_4 , V_8 ) ;
T_1 V_6 = V_10 -> V_6 ;
if ( ! ( F_29 ( V_2 , V_6 ) & V_187 ) ) {
F_4 ( V_2 ,
L_20 ,
V_6 , F_29 ( V_2 , V_6 ) ) ;
return - V_12 ;
}
V_10 -> V_163 = F_90 ( V_2 , V_6 ,
V_10 -> V_164 ,
V_188 ) ;
return 0 ;
}
static int F_91 ( struct V_3 * V_4 ,
struct V_9 * V_10 )
{
int V_19 ;
if ( ! F_92 ( V_10 -> V_189 , & V_4 -> V_190 ) )
return V_10 -> V_189 ;
for ( V_19 = V_4 -> V_191 ; V_19 < V_4 -> V_16 ; V_19 ++ ) {
if ( ! F_92 ( V_19 , & V_4 -> V_190 ) )
return V_19 ;
}
for ( V_19 = 0 ; V_19 < V_4 -> V_191 ; V_19 ++ ) {
if ( ! F_92 ( V_19 , & V_4 -> V_190 ) )
return V_19 ;
}
return - V_165 ;
}
static void F_93 ( struct V_3 * V_4 ,
struct V_9 * V_10 )
{
int V_192 ;
if ( V_10 -> V_18 )
return;
V_192 = F_91 ( V_4 , V_10 ) ;
if ( V_192 == - V_165 )
return;
V_10 -> V_15 = V_192 ;
V_10 -> V_18 = F_22 ( V_4 , V_192 ) ;
F_82 ( V_192 , & V_4 -> V_190 ) ;
}
static void F_94 ( struct V_3 * V_4 ,
struct V_9 * V_10 )
{
int V_192 ;
if ( ! V_10 -> V_18 )
return;
V_192 = V_10 -> V_15 ;
V_10 -> V_15 = - 1 ;
V_10 -> V_18 = NULL ;
if ( V_192 >= 0 && V_192 < V_4 -> V_16 )
F_95 ( V_192 , & V_4 -> V_190 ) ;
}
static int F_96 ( struct V_3 * V_4 ,
struct V_9 * V_10 , T_1 V_20 )
{
int V_161 ;
for ( V_161 = 0 ; V_161 < V_10 -> V_163 ; V_161 ++ )
if ( V_10 -> V_164 [ V_161 ] == V_20 )
break;
return V_161 ;
}
static void F_97 ( struct V_3 * V_4 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_193 * V_18 ;
struct V_13 * V_14 ;
struct V_172 * V_173 ;
int V_161 ;
bool V_109 ;
if ( V_10 -> V_15 >= 0 && V_10 -> V_15 < V_4 -> V_16 )
V_18 = F_6 ( V_4 , V_10 -> V_15 ) ;
else
return;
if ( ! F_92 ( V_10 -> V_15 , & V_4 -> V_176 ) )
return;
V_14 = V_18 -> V_17 ;
V_173 = V_18 -> V_18 -> V_194 [ 0 ] . V_173 ;
V_10 -> V_20 = V_14 -> V_120 ;
V_161 = F_96 ( V_4 , V_10 , V_14 -> V_120 ) ;
if ( V_161 < V_10 -> V_163 ) {
F_78 ( V_2 , V_10 -> V_6 ,
V_10 -> V_7 ) ;
F_73 ( V_2 , V_10 -> V_6 , 0 ,
V_168 ,
V_161 ) ;
}
F_86 ( V_2 , V_10 -> V_15 , V_14 -> V_120 ) ;
V_109 = F_98 ( V_2 , V_14 -> V_120 ) ;
if ( V_173 -> V_175 )
V_10 -> V_112 = V_173 -> V_175 -> V_112 ;
V_10 -> V_195 = true ;
V_10 -> V_161 = V_161 ;
F_50 ( V_2 , V_10 , V_109 ) ;
}
static void F_99 ( struct V_3 * V_4 ,
struct V_9 * V_10 )
{
if ( V_10 -> V_15 >= 0 && V_10 -> V_15 < V_4 -> V_16 )
F_88 ( V_10 -> V_2 , V_10 -> V_15 ) ;
V_10 -> V_116 = false ;
memset ( V_10 -> V_111 , 0 , sizeof( V_10 -> V_111 ) ) ;
V_10 -> V_195 = false ;
V_10 -> V_112 = 0 ;
}
static void F_100 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_27 * V_28 )
{
struct V_27 * V_196 = & V_10 -> V_33 ;
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_197 = V_196 -> V_34 ;
bool V_198 ;
int V_15 = - 1 ;
V_15 = V_10 -> V_15 ;
if ( V_4 -> V_184 ) {
if ( V_28 -> V_34 ) {
F_93 ( V_4 , V_10 ) ;
F_97 ( V_4 , V_10 ) ;
} else {
F_99 ( V_4 , V_10 ) ;
F_94 ( V_4 , V_10 ) ;
}
}
if ( V_15 == - 1 )
V_15 = V_10 -> V_15 ;
if ( V_28 -> V_34 )
F_101 ( V_2 , & V_28 -> V_114 ) ;
V_198 = ( V_196 -> V_34 != V_28 -> V_34 ) ;
if ( V_28 -> V_34 && V_196 -> V_34 )
if ( V_196 -> V_35 != V_28 -> V_35 ||
memcmp ( V_196 -> V_42 , V_28 -> V_42 ,
V_28 -> V_35 ) != 0 )
V_198 = true ;
V_196 -> V_199 = V_28 -> V_199 ;
V_196 -> V_34 = V_28 -> V_34 ;
V_196 -> V_35 = V_28 -> V_35 ;
if ( V_28 -> V_34 )
memcpy ( V_196 -> V_42 , V_28 -> V_42 , V_28 -> V_35 ) ;
V_196 -> V_114 = V_28 -> V_114 ;
if ( V_28 -> V_34 && ! V_197 && V_10 -> V_195 ) {
F_80 ( V_2 , V_10 , 0 ) ;
F_50 ( V_2 , V_10 , V_10 -> V_109 ) ;
}
if ( V_198 && V_15 >= 0 )
F_102 ( V_2 -> V_72 ,
V_200 |
V_201 ,
& F_22 ( V_4 , V_15 ) -> V_49 -> V_48 ) ;
}
static bool F_103 ( struct V_9 * V_10 ,
int V_202 )
{
struct V_126 * V_122 ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_27 * V_28 = & V_4 -> V_203 ;
T_1 V_6 = V_10 -> V_6 ;
int V_204 ;
bool V_205 ;
bool V_206 = false ;
V_204 = F_104 ( V_2 , V_6 ) ;
F_14 ( & V_10 -> V_68 ) ;
V_28 -> V_199 = ! ! ( V_204 & V_207 ) ;
if ( V_28 -> V_199 )
V_28 -> V_34 = ! ! ( V_204 & V_208 ) ;
else
V_28 -> V_34 = false ;
F_8 ( V_2 ,
L_21 ,
V_2 -> V_71 , V_6 , V_28 -> V_199 , V_28 -> V_34 ) ;
if ( V_28 -> V_34 ) {
if ( V_4 -> V_117 . V_209 ( V_2 , V_6 , V_28 -> V_42 ,
& V_28 -> V_35 ) < 0 )
V_28 -> V_34 = false ;
else {
if ( F_105 ( V_2 , & V_28 -> V_114 , V_28 -> V_42 ,
V_28 -> V_35 ) < 0 )
V_28 -> V_34 = false ;
}
if ( ! V_28 -> V_34 && V_202 )
V_206 = true ;
}
if ( V_206 )
F_106 ( & V_10 -> V_210 , F_107 ( 300 ) ) ;
else
F_100 ( V_2 , V_10 , V_28 ) ;
V_205 = ! V_202 || ! V_28 -> V_199 || V_28 -> V_34 ;
V_122 = F_108 ( V_2 , V_6 ) ;
if ( V_122 )
V_122 -> V_211 = ! V_205 ;
F_15 ( & V_10 -> V_68 ) ;
return V_205 ;
}
static struct V_212 * F_109 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_212 * V_122 = NULL ;
struct V_126 * V_213 ;
if ( V_10 -> V_15 >= 0 && V_4 -> V_184 )
V_122 = V_4 -> V_214 [ V_10 -> V_15 ] . V_122 ;
else if ( ! V_4 -> V_184 ) {
V_213 = F_108 ( V_2 , V_10 -> V_6 ) ;
if ( V_213 )
V_122 = V_213 -> V_122 ;
}
return V_122 ;
}
static void F_110 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_27 * V_28 = & V_4 -> V_203 ;
struct V_212 * V_122 = NULL ;
int V_84 ;
F_14 ( & V_10 -> V_68 ) ;
V_28 -> V_199 = false ;
V_84 = F_111 ( & V_2 -> V_113 , V_10 -> V_6 ,
V_10 -> V_7 , & V_28 -> V_199 ,
V_28 -> V_42 , V_41 ) ;
if ( V_84 > 0 ) {
V_84 = F_112 ( V_84 , V_41 ) ;
if ( F_105 ( V_2 , & V_28 -> V_114 ,
V_28 -> V_42 , V_84 ) < 0 )
V_84 = - V_12 ;
}
if ( V_84 > 0 ) {
V_28 -> V_34 = true ;
V_28 -> V_35 = V_84 ;
} else {
V_28 -> V_34 = false ;
V_28 -> V_35 = 0 ;
}
V_122 = F_109 ( V_2 , V_10 ) ;
F_100 ( V_2 , V_10 , V_28 ) ;
if ( V_122 == NULL )
V_122 = F_109 ( V_2 , V_10 ) ;
if ( V_122 == NULL )
goto V_215;
F_113 ( V_122 ,
V_28 -> V_199 ? V_216 : 0 ) ;
V_215:
F_15 ( & V_10 -> V_68 ) ;
}
static bool F_55 ( struct V_9 * V_10 , int V_202 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_205 ;
if ( ! F_1 ( V_2 ) )
F_114 ( V_2 ) ;
F_14 ( & V_4 -> V_31 ) ;
if ( F_1 ( V_2 ) ) {
F_110 ( V_2 , V_10 ) ;
V_205 = false ;
} else {
V_205 = F_103 ( V_10 , V_202 ) ;
}
F_15 ( & V_4 -> V_31 ) ;
if ( ! F_1 ( V_2 ) )
F_115 ( V_2 ) ;
return V_205 ;
}
static void F_116 ( struct V_217 * V_210 )
{
struct V_9 * V_10 =
F_117 ( F_118 ( V_210 ) , struct V_9 , V_210 ) ;
if ( V_10 -> V_218 ++ > 6 )
V_10 -> V_218 = 0 ;
if ( F_55 ( V_10 , V_10 -> V_218 ) )
F_56 ( V_10 -> V_2 ) ;
}
static int F_119 ( struct V_1 * V_2 , T_1 V_6 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_219 , V_220 ;
int V_8 ;
struct V_9 * V_10 ;
int V_45 ;
int V_171 , V_19 ;
V_219 = F_67 ( V_2 , V_6 ) ;
if ( ! ( V_219 & ( V_221 | V_222 ) ) )
return 0 ;
V_220 = F_120 ( V_2 , V_6 ) ;
if ( F_121 ( V_220 ) == V_223 )
return 0 ;
if ( F_122 ( V_2 ) ) {
V_171 = 3 ;
V_4 -> V_171 = 3 ;
} else if ( V_4 -> V_184 && V_2 -> V_224 ) {
V_171 = F_76 ( V_2 , V_6 ) + 1 ;
V_4 -> V_171 = ( V_4 -> V_171 > V_171 ) ?
V_4 -> V_171 : V_171 ;
} else {
V_171 = 1 ;
V_4 -> V_171 = 1 ;
}
for ( V_19 = 0 ; V_19 < V_171 ; V_19 ++ ) {
V_8 = V_4 -> V_11 ;
V_10 = F_123 ( & V_4 -> V_225 ) ;
if ( ! V_10 )
return - V_47 ;
if ( V_4 -> V_184 ) {
V_10 -> V_18 = NULL ;
V_10 -> V_15 = - 1 ;
} else {
V_10 -> V_18 = F_22 ( V_4 , V_8 ) ;
V_10 -> V_15 = V_8 ;
}
V_10 -> V_6 = V_6 ;
V_10 -> V_189 = V_4 -> V_191 ;
V_10 -> V_7 = V_19 ;
V_10 -> V_109 = false ;
F_78 ( V_2 , V_6 , V_19 ) ;
if ( F_122 ( V_2 ) )
F_124 ( V_2 , V_6 ) ;
V_45 = F_89 ( V_2 , V_8 ) ;
if ( V_45 < 0 )
return V_45 ;
V_4 -> V_11 ++ ;
}
V_4 -> V_191 ++ ;
return 0 ;
}
static int F_125 ( struct V_1 * V_2 , T_1 V_20 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_159 * V_160 ;
unsigned int V_226 ;
int V_45 ;
V_226 = F_29 ( V_2 , V_20 ) ;
V_226 = F_126 ( V_226 ) ;
V_160 = F_123 ( & V_4 -> V_227 ) ;
if ( ! V_160 )
return - V_47 ;
V_160 -> V_20 = V_20 ;
V_160 -> V_177 = 2 ;
if ( V_226 <= 16 ) {
V_160 -> V_178 = V_226 ;
if ( V_226 > V_4 -> V_111 . V_178 )
V_4 -> V_111 . V_178 = V_226 ;
}
V_45 = F_127 ( V_2 , V_20 ,
& V_160 -> V_179 ,
& V_160 -> V_180 ,
& V_160 -> V_181 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_4 -> V_22 < F_17 ( V_4 -> V_169 ) )
V_4 -> V_169 [ V_4 -> V_22 ] = V_20 ;
V_4 -> V_22 ++ ;
return 0 ;
}
static int F_128 ( struct V_1 * V_2 )
{
T_1 V_120 ;
int V_19 , V_228 ;
V_228 = F_129 ( V_2 , V_2 -> V_113 . V_229 , & V_120 ) ;
if ( ! V_120 || V_228 < 0 ) {
F_4 ( V_2 , L_22 ) ;
return - V_12 ;
}
for ( V_19 = 0 ; V_19 < V_228 ; V_19 ++ , V_120 ++ ) {
unsigned int V_219 ;
unsigned int type ;
V_219 = F_29 ( V_2 , V_120 ) ;
type = F_130 ( V_219 ) ;
if ( ! ( V_219 & V_230 ) )
continue;
switch ( type ) {
case V_231 :
F_125 ( V_2 , V_120 ) ;
break;
case V_232 :
F_119 ( V_2 , V_120 ) ;
break;
}
}
return 0 ;
}
static bool F_98 ( struct V_1 * V_2 , T_1 V_20 )
{
struct V_233 * V_234 ;
bool V_109 ;
F_14 ( & V_2 -> V_235 ) ;
V_234 = F_131 ( V_2 , V_20 ) ;
if ( F_132 ( V_234 == NULL ) )
return true ;
V_109 = ! ! ( V_234 -> V_236 & V_237 ) ;
F_15 ( & V_2 -> V_235 ) ;
return V_109 ;
}
static int F_133 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
unsigned int V_155 ,
unsigned int V_156 ,
struct V_172 * V_173 )
{
T_1 V_20 = V_14 -> V_120 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_8 ;
struct V_9 * V_10 ;
T_1 V_6 ;
struct V_174 * V_175 = V_173 -> V_175 ;
bool V_109 ;
int V_148 ;
int V_45 ;
F_14 ( & V_4 -> V_31 ) ;
V_8 = F_7 ( V_2 , V_14 ) ;
if ( V_4 -> V_184 && V_8 < 0 ) {
F_80 ( V_2 , NULL , V_20 ) ;
F_70 ( V_2 , V_20 ,
V_155 , 0 , V_156 ) ;
F_15 ( & V_4 -> V_31 ) ;
return 0 ;
}
if ( F_85 ( V_8 < 0 ) ) {
F_15 ( & V_4 -> V_31 ) ;
return - V_12 ;
}
V_10 = F_3 ( V_4 , V_8 ) ;
V_6 = V_10 -> V_6 ;
F_80 ( V_2 , V_10 , 0 ) ;
if ( F_1 ( V_2 ) )
F_134 ( & V_2 -> V_113 , V_6 , V_10 -> V_7 ,
V_175 -> V_238 ) ;
V_109 = F_98 ( V_2 , V_20 ) ;
F_14 ( & V_10 -> V_68 ) ;
V_10 -> V_112 = V_173 -> V_175 -> V_112 ;
V_10 -> V_195 = true ;
F_50 ( V_2 , V_10 , V_109 ) ;
F_15 ( & V_10 -> V_68 ) ;
if ( V_4 -> V_60 ) {
V_148 = F_24 ( V_2 , V_6 , 0 ,
V_151 , 0 ) ;
F_26 ( V_2 , V_6 , 0 ,
V_62 ,
V_148 | V_61 ) ;
}
V_45 = V_4 -> V_117 . V_239 ( V_2 , V_20 , V_6 ,
V_155 , V_156 ) ;
F_15 ( & V_4 -> V_31 ) ;
return V_45 ;
}
static int F_135 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_172 * V_173 )
{
F_136 ( V_2 , V_14 -> V_120 ) ;
return 0 ;
}
static int F_137 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_172 * V_173 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_21 , V_8 , V_15 ;
struct V_159 * V_160 ;
struct V_9 * V_10 ;
int V_148 ;
if ( V_14 -> V_120 ) {
V_15 = F_5 ( V_2 , V_14 ) ;
if ( F_85 ( V_15 < 0 ) )
return - V_12 ;
V_21 = F_10 ( V_2 , V_14 -> V_120 ) ;
if ( F_85 ( V_21 < 0 ) )
return - V_12 ;
V_160 = F_11 ( V_4 , V_21 ) ;
F_85 ( ! V_160 -> V_162 ) ;
V_160 -> V_162 = 0 ;
V_14 -> V_120 = 0 ;
F_14 ( & V_4 -> V_31 ) ;
F_88 ( V_2 , V_15 ) ;
F_95 ( V_15 , & V_4 -> V_176 ) ;
V_8 = F_7 ( V_2 , V_14 ) ;
if ( V_4 -> V_184 && V_8 < 0 ) {
F_15 ( & V_4 -> V_31 ) ;
return 0 ;
}
if ( F_85 ( V_8 < 0 ) ) {
F_15 ( & V_4 -> V_31 ) ;
return - V_12 ;
}
V_10 = F_3 ( V_4 , V_8 ) ;
if ( V_4 -> V_60 ) {
V_148 = F_24 ( V_2 , V_10 -> V_6 , 0 ,
V_151 , 0 ) ;
F_26 ( V_2 , V_10 -> V_6 , 0 ,
V_62 ,
V_148 & ~ V_61 ) ;
}
F_14 ( & V_10 -> V_68 ) ;
V_10 -> V_116 = false ;
memset ( V_10 -> V_111 , 0 , sizeof( V_10 -> V_111 ) ) ;
V_10 -> V_195 = false ;
V_10 -> V_112 = 0 ;
F_15 ( & V_10 -> V_68 ) ;
F_15 ( & V_4 -> V_31 ) ;
}
return 0 ;
}
static int F_138 ( struct V_240 * V_241 , int V_15 )
{
struct V_1 * V_2 = F_117 ( V_241 , struct V_1 , V_113 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 = F_9 ( V_4 , V_15 ) ;
if ( ! V_10 )
return 0 ;
return V_10 -> V_33 . V_114 . V_115 ;
}
static void F_139 ( struct V_240 * V_241 , int V_15 ,
unsigned char * V_111 )
{
struct V_1 * V_2 = F_117 ( V_241 , struct V_1 , V_113 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 = F_9 ( V_4 , V_15 ) ;
if ( ! V_10 )
return;
memcpy ( V_111 , V_10 -> V_111 , F_17 ( V_10 -> V_111 ) ) ;
}
static void F_140 ( struct V_240 * V_241 , int V_15 ,
unsigned char * V_111 , int V_242 )
{
struct V_1 * V_2 = F_117 ( V_241 , struct V_1 , V_113 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 = F_9 ( V_4 , V_15 ) ;
if ( ! V_10 )
return;
F_14 ( & V_10 -> V_68 ) ;
V_10 -> V_116 = true ;
memcpy ( V_10 -> V_111 , V_111 , F_17 ( V_10 -> V_111 ) ) ;
if ( V_242 )
F_50 ( V_2 , V_10 , V_10 -> V_109 ) ;
F_15 ( & V_10 -> V_68 ) ;
}
static bool F_141 ( struct V_240 * V_241 , int V_15 )
{
struct V_1 * V_2 = F_117 ( V_241 , struct V_1 , V_113 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 = F_9 ( V_4 , V_15 ) ;
return V_10 ? true : false ;
}
static int F_142 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_192 ;
for ( V_192 = 0 ; V_192 < V_4 -> V_191 + V_4 -> V_171 - 1 ; V_192 ++ ) {
struct V_193 * V_114 ;
struct V_13 * V_243 ;
V_114 = F_143 ( V_2 , L_23 , V_192 ) ;
if ( ! V_114 )
return - V_47 ;
V_4 -> V_214 [ V_192 ] . V_18 = V_114 ;
V_4 -> V_16 ++ ;
V_114 -> V_244 = V_245 ;
V_114 -> V_246 = true ;
V_243 = & V_114 -> V_17 [ V_247 ] ;
V_243 -> V_248 = 1 ;
V_243 -> V_117 = V_249 ;
if ( V_4 -> V_16 >= 16 )
break;
}
return 0 ;
}
static void F_144 ( struct V_212 * V_122 )
{
struct V_250 * V_18 = V_122 -> V_67 ;
V_18 -> V_122 = NULL ;
}
static int F_145 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_15 ,
const char * V_70 )
{
struct V_212 * V_122 ;
int V_45 ;
V_45 = F_146 ( V_2 -> V_72 , V_70 , V_216 , & V_122 ,
true , false ) ;
if ( V_45 < 0 )
return V_45 ;
V_4 -> V_214 [ V_15 ] . V_122 = V_122 ;
V_122 -> V_67 = & V_4 -> V_214 [ V_15 ] ;
V_122 -> V_251 = F_144 ;
return 0 ;
}
static int F_147 ( struct V_1 * V_2 , int V_15 )
{
char V_252 [ 32 ] = L_24 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 ;
struct V_126 * V_122 ;
int V_253 = F_6 ( V_4 , V_15 ) -> V_43 ;
bool V_254 ;
int V_205 ;
if ( V_253 > 0 )
sprintf ( V_252 + strlen ( V_252 ) , L_25 , V_253 ) ;
if ( V_4 -> V_184 )
return F_145 ( V_2 , V_4 , V_15 , V_252 ) ;
V_10 = F_3 ( V_4 , V_15 ) ;
V_254 = ! F_148 ( V_2 , V_10 -> V_6 ) ;
if ( V_254 )
strncat ( V_252 , L_26 ,
sizeof( V_252 ) - strlen ( V_252 ) - 1 ) ;
V_205 = F_149 ( V_2 , V_10 -> V_6 , V_252 ,
V_254 ) ;
if ( V_205 < 0 )
return V_205 ;
V_122 = F_108 ( V_2 , V_10 -> V_6 ) ;
if ( V_122 == NULL )
return 0 ;
V_4 -> V_214 [ V_15 ] . V_122 = V_122 -> V_122 ;
return 0 ;
}
static int F_150 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_45 ;
int V_8 , V_15 ;
for ( V_15 = 0 ; V_15 < V_4 -> V_16 ; V_15 ++ ) {
V_45 = F_147 ( V_2 , V_15 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_4 -> V_184 )
V_45 = F_151 ( V_2 ,
0 , V_4 -> V_169 [ 0 ] ,
V_245 ) ;
else {
struct V_9 * V_10 =
F_3 ( V_4 , V_15 ) ;
V_45 = F_151 ( V_2 ,
V_10 -> V_6 ,
V_10 -> V_164 [ 0 ] ,
V_245 ) ;
}
if ( V_45 < 0 )
return V_45 ;
F_88 ( V_2 , V_15 ) ;
V_45 = F_19 ( V_2 , V_15 ,
F_6 ( V_4 , V_15 ) -> V_43 ) ;
if ( V_45 < 0 )
return V_45 ;
}
for ( V_8 = 0 ; V_8 < V_4 -> V_11 ; V_8 ++ ) {
struct V_9 * V_10 = F_3 ( V_4 , V_8 ) ;
F_55 ( V_10 , 0 ) ;
}
for ( V_15 = 0 ; V_15 < V_4 -> V_16 ; V_15 ++ ) {
struct V_193 * V_18 ;
V_18 = F_6 ( V_4 , V_15 ) ;
if ( ! V_18 || ! V_18 -> V_18 )
break;
V_45 = F_152 ( V_18 -> V_18 , V_15 , & V_4 -> V_111 ) ;
if ( V_45 < 0 )
return V_45 ;
}
return 0 ;
}
static int F_153 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 -> V_11 ; V_8 ++ ) {
struct V_9 * V_10 = F_3 ( V_4 , V_8 ) ;
V_10 -> V_2 = V_2 ;
F_154 ( & V_10 -> V_68 ) ;
F_155 ( & V_10 -> V_210 , F_116 ) ;
F_34 ( V_10 , V_8 ) ;
}
return 0 ;
}
static int F_156 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_4 -> V_11 ; V_8 ++ ) {
struct V_9 * V_10 = F_3 ( V_4 , V_8 ) ;
T_1 V_6 = V_10 -> V_6 ;
int V_7 = V_10 -> V_7 ;
F_78 ( V_2 , V_6 , V_7 ) ;
F_28 ( V_2 , V_6 ) ;
if ( ! F_1 ( V_2 ) )
F_157 ( V_2 , V_6 ,
V_2 -> V_255 > 0 ?
F_57 : NULL ) ;
}
return 0 ;
}
static void F_158 ( struct V_3 * V_4 , int V_256 )
{
F_159 ( & V_4 -> V_225 , sizeof( struct V_9 ) , V_256 ) ;
F_159 ( & V_4 -> V_227 , sizeof( struct V_159 ) , V_256 ) ;
}
static void F_160 ( struct V_3 * V_4 )
{
F_161 ( & V_4 -> V_225 ) ;
F_161 ( & V_4 -> V_227 ) ;
}
static void F_162 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 ) {
F_160 ( V_4 ) ;
F_163 ( V_4 ) ;
V_2 -> V_4 = NULL ;
}
V_2 -> V_224 = false ;
}
static void F_164 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_8 , V_15 ;
if ( F_1 ( V_2 ) )
F_165 ( NULL ) ;
for ( V_8 = 0 ; V_8 < V_4 -> V_11 ; V_8 ++ ) {
struct V_9 * V_10 = F_3 ( V_4 , V_8 ) ;
F_166 ( & V_10 -> V_210 ) ;
F_37 ( V_10 ) ;
}
for ( V_15 = 0 ; V_15 < V_4 -> V_16 ; V_15 ++ ) {
if ( V_4 -> V_214 [ V_15 ] . V_122 == NULL )
continue;
if ( V_4 -> V_184 )
F_167 ( V_2 -> V_72 ,
V_4 -> V_214 [ V_15 ] . V_122 ) ;
else
V_4 -> V_214 [ V_15 ] . V_122 = NULL ;
}
F_162 ( V_2 ) ;
}
static int F_168 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_8 ;
V_2 -> V_257 . V_258 ( V_2 ) ;
F_169 ( V_2 -> V_113 . V_259 ) ;
for ( V_8 = 0 ; V_8 < V_4 -> V_11 ; V_8 ++ ) {
struct V_9 * V_10 = F_3 ( V_4 , V_8 ) ;
F_55 ( V_10 , 1 ) ;
}
return 0 ;
}
static int F_170 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_171 ( sizeof( * V_4 ) , V_260 ) ;
if ( ! V_4 )
return - V_47 ;
V_4 -> V_117 = V_261 ;
V_4 -> V_171 = 1 ;
F_154 ( & V_4 -> V_31 ) ;
F_172 ( & V_2 -> V_113 , & V_4 -> V_111 ) ;
V_4 -> V_111 . V_117 . V_262 = F_139 ;
V_4 -> V_111 . V_117 . V_263 = F_140 ;
V_4 -> V_111 . V_117 . V_264 = F_141 ;
V_4 -> V_111 . V_117 . V_265 = F_138 ,
V_2 -> V_4 = V_4 ;
F_158 ( V_4 , 4 ) ;
V_2 -> V_257 = V_266 ;
return 0 ;
}
static int F_173 ( struct V_1 * V_2 )
{
int V_45 ;
V_45 = F_170 ( V_2 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_128 ( V_2 ) ;
if ( V_45 < 0 ) {
F_162 ( V_2 ) ;
return V_45 ;
}
F_153 ( V_2 ) ;
return 0 ;
}
static void F_124 ( struct V_1 * V_2 ,
T_1 V_120 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_267 [ 4 ] ;
int V_268 ;
V_268 = F_90 ( V_2 , V_120 , V_267 , F_17 ( V_267 ) ) ;
if ( V_268 == V_4 -> V_22 &&
! memcmp ( V_267 , V_4 -> V_169 , V_4 -> V_22 * sizeof( T_1 ) ) )
return;
F_8 ( V_2 , L_27 , V_120 ) ;
F_174 ( V_2 , V_120 , V_4 -> V_22 , V_4 -> V_169 ) ;
}
static void F_175 ( struct V_1 * V_2 ,
bool V_269 )
{
unsigned int V_270 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_270 = F_24 ( V_2 , V_4 -> V_271 , 0 ,
V_272 , 0 ) ;
if ( V_270 == - 1 || V_270 & V_273 )
return;
V_270 |= V_273 ;
V_270 = F_24 ( V_2 , V_4 -> V_271 , 0 ,
V_274 , V_270 ) ;
if ( V_270 == - 1 )
return;
if ( V_269 )
F_176 ( V_2 ) ;
}
static void F_177 ( struct V_1 * V_2 )
{
unsigned int V_270 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_270 = F_24 ( V_2 , V_4 -> V_271 , 0 ,
V_272 , 0 ) ;
if ( V_270 == - 1 || V_270 & V_275 )
return;
V_270 |= V_275 ;
F_178 ( & V_2 -> V_113 , V_274 ) ;
F_73 ( V_2 , V_4 -> V_271 , 0 ,
V_274 , V_270 ) ;
}
static void F_179 ( struct V_1 * V_2 , T_1 V_276 ,
unsigned int V_277 )
{
if ( V_277 == V_142 ) {
F_175 ( V_2 , false ) ;
F_177 ( V_2 ) ;
}
F_24 ( V_2 , V_276 , 0 , V_143 , V_277 ) ;
F_180 ( V_2 , V_276 , V_277 ) ;
}
static void F_181 ( void * V_278 , int V_279 , int V_280 )
{
struct V_1 * V_2 = V_278 ;
int V_6 ;
int V_7 = V_280 ;
if ( V_279 < 1 || V_279 > 3 )
return;
switch ( V_2 -> V_113 . V_281 ) {
case 0x80860054 :
case 0x80862804 :
case 0x80862882 :
V_6 = V_279 + 0x03 ;
break;
default:
V_6 = V_279 + 0x04 ;
break;
}
if ( F_182 ( V_2 -> V_72 ) != V_282 )
return;
if ( F_183 ( & ( V_2 ) -> V_113 . V_283 ) )
return;
F_184 ( & V_2 -> V_79 -> V_113 ) ;
F_54 ( V_2 , V_6 , V_7 ) ;
}
static void F_185 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_4 -> V_5 = true ;
V_4 -> V_284 . V_278 = V_2 ;
F_186 () ;
V_4 -> V_284 . V_285 = F_181 ;
F_165 ( & V_4 -> V_284 ) ;
}
static int F_187 ( struct V_1 * V_2 , T_1 V_20 ,
T_1 V_6 , T_3 V_155 , int V_156 )
{
F_63 ( V_2 , V_20 , V_6 ) ;
return F_68 ( V_2 , V_20 , V_6 , V_155 , V_156 ) ;
}
static void F_188 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
T_1 V_20 )
{
if ( V_10 ) {
F_78 ( V_2 , V_10 -> V_6 ,
V_10 -> V_7 ) ;
F_72 ( V_2 , V_10 ) ;
F_75 ( V_2 , V_10 -> V_6 ,
V_10 -> V_7 , V_10 -> V_161 ) ;
} else {
F_79 ( V_2 , 0 , 0 , V_20 ) ;
}
}
static int F_189 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_79 -> V_113 . V_286 ) {
F_61 ( V_2 , L_28 ) ;
return - V_186 ;
}
return F_170 ( V_2 ) ;
}
static int F_190 ( struct V_1 * V_2 )
{
int V_45 ;
V_45 = F_128 ( V_2 ) ;
if ( V_45 < 0 ) {
F_162 ( V_2 ) ;
return V_45 ;
}
F_153 ( V_2 ) ;
F_185 ( V_2 ) ;
return 0 ;
}
static int F_191 ( struct V_1 * V_2 , T_1 V_271 )
{
struct V_3 * V_4 ;
int V_45 ;
V_45 = F_189 ( V_2 ) ;
if ( V_45 < 0 )
return V_45 ;
V_4 = V_2 -> V_4 ;
V_2 -> V_224 = true ;
V_4 -> V_184 = true ;
V_4 -> V_271 = V_271 ;
F_175 ( V_2 , true ) ;
F_177 ( V_2 ) ;
if ( ! F_192 ( V_2 ) && ! F_193 ( V_2 ) )
V_2 -> V_113 . V_287 = 1 ;
V_2 -> V_257 . V_288 = F_179 ;
V_2 -> V_289 = 0 ;
V_2 -> V_290 = 1 ;
V_4 -> V_117 . V_239 = F_187 ;
V_4 -> V_117 . F_80 = F_188 ;
return F_190 ( V_2 ) ;
}
static int F_194 ( struct V_1 * V_2 )
{
return F_191 ( V_2 , V_291 ) ;
}
static int F_195 ( struct V_1 * V_2 )
{
return F_191 ( V_2 , V_292 ) ;
}
static int F_196 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_45 ;
V_45 = F_189 ( V_2 ) ;
if ( V_45 < 0 )
return V_45 ;
V_4 = V_2 -> V_4 ;
V_2 -> V_113 . V_287 = 1 ;
V_2 -> V_289 = 0 ;
V_2 -> V_290 = 1 ;
V_4 -> V_117 . F_80 = F_188 ;
return F_190 ( V_2 ) ;
}
static int F_197 ( struct V_1 * V_2 )
{
int V_45 ;
V_45 = F_189 ( V_2 ) ;
if ( V_45 < 0 )
return V_45 ;
return F_190 ( V_2 ) ;
}
static int F_198 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_193 * V_114 ;
unsigned int V_226 ;
struct V_13 * V_243 ;
struct V_159 * V_160 ;
V_160 = F_11 ( V_4 , 0 ) ;
V_226 = F_29 ( V_2 , V_160 -> V_20 ) ;
V_226 = F_126 ( V_226 ) ;
V_114 = F_143 ( V_2 , L_29 ) ;
if ( ! V_114 )
return - V_47 ;
V_4 -> V_214 [ 0 ] . V_18 = V_114 ;
V_114 -> V_244 = V_245 ;
V_243 = & V_114 -> V_17 [ V_247 ] ;
* V_243 = V_4 -> V_293 ;
V_243 -> V_120 = V_160 -> V_20 ;
if ( V_243 -> V_178 <= 2 && V_226 && V_226 <= 16 )
V_243 -> V_178 = V_226 ;
return 0 ;
}
static void F_199 ( struct V_1 * V_2 ,
unsigned int V_123 )
{
F_200 ( V_2 ) ;
F_56 ( V_2 ) ;
}
static int F_201 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_159 * V_160 ;
int V_45 ;
V_160 = F_11 ( V_4 , 0 ) ;
V_45 = F_151 ( V_2 , V_160 -> V_20 ,
V_160 -> V_20 ,
V_245 ) ;
if ( V_45 < 0 )
return V_45 ;
return F_202 ( V_2 , 0 ) ;
}
static int F_203 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 = F_3 ( V_4 , 0 ) ;
T_1 V_294 = V_10 -> V_6 ;
F_26 ( V_2 , V_294 , 0 ,
V_62 , V_61 ) ;
if ( F_29 ( V_2 , V_294 ) & V_57 )
F_26 ( V_2 , V_294 , 0 , V_58 ,
V_59 ) ;
F_204 ( V_2 , V_294 ) ;
return 0 ;
}
static void F_205 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_160 ( V_4 ) ;
F_163 ( V_4 ) ;
}
static int F_206 ( struct V_1 * V_2 )
{
F_207 ( V_2 , V_295 ) ;
return 0 ;
}
static int F_208 ( struct V_1 * V_2 )
{
F_207 ( V_2 , V_296 ) ;
return 0 ;
}
static int F_209 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_172 * V_173 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_297 * V_298 = NULL ;
switch ( V_2 -> V_299 -> V_281 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_298 = & V_300 ;
break;
case 0x10de0007 :
V_298 = & V_301 ;
break;
default:
break;
}
if ( V_298 != NULL ) {
V_297 ( V_173 -> V_175 , 0 ,
V_183 ,
V_298 ) ;
} else {
F_83 ( V_173 -> V_175 , 0 ,
V_183 , 2 ) ;
}
return F_210 ( V_2 , & V_4 -> V_302 ) ;
}
static int F_211 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_172 * V_173 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
return F_212 ( V_2 , & V_4 -> V_302 ) ;
}
static int F_213 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
unsigned int V_155 ,
unsigned int V_156 ,
struct V_172 * V_173 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
return F_214 ( V_2 , & V_4 -> V_302 ,
V_155 , V_156 , V_173 ) ;
}
static int F_215 ( struct V_1 * V_2 ,
T_1 V_20 , T_1 V_6 )
{
struct V_3 * V_4 ;
struct V_159 * V_160 ;
struct V_9 * V_10 ;
V_4 = F_171 ( sizeof( * V_4 ) , V_260 ) ;
if ( ! V_4 )
return - V_47 ;
V_2 -> V_4 = V_4 ;
F_158 ( V_4 , 1 ) ;
V_4 -> V_302 . V_303 = 0 ;
V_4 -> V_302 . V_304 = 2 ;
V_4 -> V_302 . V_305 = V_20 ;
V_4 -> V_22 = 1 ;
V_4 -> V_11 = 1 ;
V_10 = F_123 ( & V_4 -> V_225 ) ;
V_160 = F_123 ( & V_4 -> V_227 ) ;
if ( ! V_10 || ! V_160 ) {
F_205 ( V_2 ) ;
return - V_47 ;
}
V_160 -> V_20 = V_20 ;
V_10 -> V_6 = V_6 ;
V_4 -> V_293 = V_306 ;
V_2 -> V_257 = V_307 ;
return 0 ;
}
static void F_216 ( struct V_1 * V_2 ,
int V_112 )
{
unsigned int V_308 ;
int V_309 = V_112 ? ( V_112 - 1 ) : 1 ;
switch ( V_112 ) {
default:
case 0 :
case 2 :
V_308 = 0x00 ;
break;
case 4 :
V_308 = 0x08 ;
break;
case 6 :
V_308 = 0x0b ;
break;
case 8 :
V_308 = 0x13 ;
break;
}
F_26 ( V_2 , 0x1 , 0 ,
V_310 , V_308 ) ;
F_26 ( V_2 , 0x1 , 0 ,
V_311 ,
( 0x71 - V_309 - V_308 ) ) ;
}
static int F_217 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_172 * V_173 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_19 ;
F_26 ( V_2 , V_312 ,
0 , V_313 , 0 ) ;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
F_26 ( V_2 , V_314 [ V_19 ] , 0 ,
V_313 , 0 ) ;
F_26 ( V_2 , V_314 [ V_19 ] , 0 ,
V_315 , 0 ) ;
}
F_216 ( V_2 , 8 ) ;
return F_212 ( V_2 , & V_4 -> V_302 ) ;
}
static int F_218 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
unsigned int V_155 ,
unsigned int V_156 ,
struct V_172 * V_173 )
{
int V_316 ;
unsigned int V_317 , V_318 ;
int V_19 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_233 * V_234 ;
struct V_159 * V_160 ;
F_14 ( & V_2 -> V_235 ) ;
V_160 = F_11 ( V_4 , 0 ) ;
V_234 = F_131 ( V_2 , V_160 -> V_20 ) ;
V_316 = V_173 -> V_175 -> V_112 ;
V_317 = 0x2 ;
if ( V_2 -> V_319 && ( V_234 -> V_320 & V_321 ) )
F_26 ( V_2 ,
V_312 ,
0 ,
V_322 ,
V_234 -> V_320 & ~ V_321 & 0xff ) ;
F_26 ( V_2 , V_312 , 0 ,
V_313 , ( V_155 << 4 ) | 0x0 ) ;
F_26 ( V_2 , V_312 , 0 ,
V_315 , V_156 ) ;
if ( V_2 -> V_319 && ( V_234 -> V_320 & V_321 ) ) {
F_26 ( V_2 ,
V_312 ,
0 ,
V_322 ,
V_234 -> V_320 & 0xff ) ;
F_26 ( V_2 ,
V_312 ,
0 ,
V_323 , V_317 ) ;
}
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
if ( V_316 == 2 )
V_318 = 0 ;
else
V_318 = V_19 * 2 ;
if ( V_2 -> V_319 &&
( V_234 -> V_320 & V_321 ) )
F_26 ( V_2 ,
V_314 [ V_19 ] ,
0 ,
V_322 ,
V_234 -> V_320 & ~ V_321 & 0xff ) ;
F_26 ( V_2 ,
V_314 [ V_19 ] ,
0 ,
V_313 ,
( V_155 << 4 ) | V_318 ) ;
F_26 ( V_2 ,
V_314 [ V_19 ] ,
0 ,
V_315 ,
V_156 ) ;
if ( V_2 -> V_319 &&
( V_234 -> V_320 & V_321 ) ) {
F_26 ( V_2 ,
V_314 [ V_19 ] ,
0 ,
V_322 ,
V_234 -> V_320 & 0xff ) ;
F_26 ( V_2 ,
V_314 [ V_19 ] ,
0 ,
V_323 , V_317 ) ;
}
}
F_216 ( V_2 , V_316 ) ;
F_15 ( & V_2 -> V_235 ) ;
return 0 ;
}
static int F_219 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_45 = F_215 ( V_2 , V_312 ,
V_324 ) ;
if ( V_45 < 0 )
return V_45 ;
V_2 -> V_257 . V_258 = F_206 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_293 . V_179 = V_325 ;
V_4 -> V_293 . V_181 = V_326 ;
V_4 -> V_293 . V_180 = V_327 ;
return 0 ;
}
static int F_220 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_45 = F_198 ( V_2 ) ;
if ( ! V_45 ) {
struct V_193 * V_114 = F_6 ( V_4 , 0 ) ;
V_114 -> V_246 = true ;
}
return V_45 ;
}
static int F_221 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_193 * V_114 ;
struct V_328 * V_111 ;
int V_45 ;
V_45 = F_201 ( V_2 ) ;
if ( V_45 < 0 )
return V_45 ;
V_114 = F_6 ( V_4 , 0 ) ;
V_45 = F_222 ( V_114 -> V_18 ,
V_247 ,
V_329 , 8 , 0 , & V_111 ) ;
if ( V_45 < 0 )
return V_45 ;
switch ( V_2 -> V_299 -> V_281 ) {
case 0x10de0002 :
case 0x10de0003 :
case 0x10de0005 :
case 0x10de0006 :
V_111 -> V_330 = ( 1U << 2 ) | ( 1U << 8 ) ;
break;
case 0x10de0007 :
V_111 -> V_330 = ( 1U << 2 ) | ( 1U << 6 ) | ( 1U << 8 ) ;
}
return 0 ;
}
static int F_223 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_45 = F_219 ( V_2 ) ;
if ( V_45 < 0 )
return V_45 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_302 . V_304 = 8 ;
V_4 -> V_293 = V_331 ;
V_2 -> V_257 . V_258 = F_208 ;
V_2 -> V_257 . V_332 = F_220 ;
V_2 -> V_257 . V_333 = F_221 ;
F_216 ( V_2 , 8 ) ;
return 0 ;
}
static int F_224 ( struct V_110 * V_111 ,
struct V_334 * V_335 , int V_112 )
{
if ( V_335 -> V_336 == 0x00 && V_112 == 2 )
return V_337 ;
if ( V_335 -> V_112 != V_112 )
return - 1 ;
return V_338 ;
}
static int F_225 ( struct V_110 * V_111 ,
int V_96 , int V_316 , unsigned char * V_339 )
{
if ( V_96 == 0x00 && ( V_339 [ 0 ] != V_340 || V_339 [ 1 ] != V_341 ) )
return - V_12 ;
return 0 ;
}
static int F_226 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_45 ;
V_45 = F_173 ( V_2 ) ;
if ( V_45 )
return V_45 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_60 = true ;
V_4 -> V_111 . V_117 . V_342 =
F_224 ;
V_4 -> V_111 . V_117 . V_343 = F_225 ;
return 0 ;
}
static void F_227 ( struct V_1 * V_2 , unsigned int V_156 )
{
unsigned int V_38 ;
V_38 = F_24 ( V_2 , V_344 , 0 ,
V_345 , 0 ) ;
V_38 = ( V_38 >> 24 ) & 0xff ;
F_26 ( V_2 , V_344 , 0 ,
V_346 ,
( V_156 >> 0 ) & 0xff ) ;
F_26 ( V_2 , V_344 , 0 ,
V_347 ,
( V_156 >> 8 ) & 0xff ) ;
F_26 ( V_2 , V_344 , 0 ,
V_348 , 0 ) ;
if ( V_156 == 0 )
V_38 &= ~ V_349 ;
else
V_38 |= V_349 ;
V_38 ^= V_350 ;
F_26 ( V_2 , V_344 , 0 ,
V_351 , V_38 ) ;
}
static int F_228 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
unsigned int V_155 ,
unsigned int V_156 ,
struct V_172 * V_173 )
{
int V_45 ;
V_45 = F_133 ( V_14 , V_2 , V_155 ,
V_156 , V_173 ) ;
if ( V_45 < 0 )
return V_45 ;
F_227 ( V_2 , V_156 ) ;
return 0 ;
}
static int F_229 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_172 * V_173 )
{
F_227 ( V_2 , 0 ) ;
return F_135 ( V_14 , V_2 , V_173 ) ;
}
static struct V_193 * F_230 ( struct V_1 * V_2 , int type )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_4 -> V_11 ; V_19 ++ ) {
struct V_193 * V_18 = F_6 ( V_4 , V_19 ) ;
if ( V_18 -> V_244 == type )
return V_18 ;
}
return NULL ;
}
static int F_231 ( struct V_1 * V_2 )
{
struct V_13 * V_17 ;
struct V_193 * V_18 ;
int V_45 ;
V_45 = F_142 ( V_2 ) ;
if ( V_45 < 0 )
return V_45 ;
V_18 = F_230 ( V_2 , V_245 ) ;
if ( ! V_18 )
return - V_186 ;
V_17 = & V_18 -> V_17 [ V_247 ] ;
V_17 -> V_117 . V_352 = F_228 ;
V_17 -> V_117 . V_353 = F_229 ;
return 0 ;
}
static int F_232 ( struct V_1 * V_2 )
{
int V_45 ;
V_45 = F_173 ( V_2 ) ;
if ( V_45 )
return V_45 ;
V_2 -> V_257 . V_332 = F_231 ;
return 0 ;
}
static int F_233 ( struct V_1 * V_2 , T_1 V_120 ,
unsigned char * V_354 , int * V_35 )
{
return F_234 ( V_2 , V_120 , V_354 , V_35 ,
F_235 ( V_2 ) ) ;
}
static void F_236 ( struct V_1 * V_2 , T_1 V_6 , int V_96 ,
int V_97 , int V_98 )
{
F_26 ( V_2 , V_6 , 0 , V_355 , V_96 ) ;
}
static int F_237 ( int V_356 )
{
switch ( V_356 ) {
case 2 : return 3 ;
case 3 : return 2 ;
default: break;
}
return V_356 ;
}
static int F_238 ( struct V_110 * V_111 ,
int V_96 , int V_316 , unsigned char * V_339 )
{
struct V_334 * V_335 ;
int V_19 , V_86 ;
V_335 = F_239 ( V_96 ) ;
for ( V_19 = 0 ; V_19 < V_316 ; ++ V_19 ) {
int V_357 = F_240 ( V_339 [ V_19 ] ) ;
bool V_358 = false ;
bool V_359 = false ;
if ( ! V_357 )
continue;
for ( V_86 = 0 + V_19 % 2 ; V_86 < 8 ; V_86 += 2 ) {
int V_360 = 7 - F_237 ( V_86 ) ;
if ( V_335 -> V_361 [ V_360 ] == V_357 ) {
V_358 = true ;
if ( V_19 % 2 == 0 && V_19 + 1 < V_316 ) {
int V_362 = 7 - F_237 ( V_86 + 1 ) ;
int V_363 = F_240 ( V_339 [ V_19 + 1 ] ) ;
int V_364 = V_335 -> V_361 [ V_362 ] ;
if ( V_363 == V_364 )
V_359 = true ;
else
return - V_12 ;
}
break;
}
}
if ( ! V_358 )
return - V_12 ;
if ( V_359 )
V_19 ++ ;
}
return 0 ;
}
static int F_241 ( struct V_240 * V_241 ,
T_1 V_6 , int V_365 , int V_366 )
{
struct V_1 * V_2 = F_117 ( V_241 , struct V_1 , V_113 ) ;
int V_367 ;
int V_368 = 0 ;
if ( V_365 > 7 )
return - V_12 ;
if ( ! F_242 ( V_2 ) ) {
V_365 = F_237 ( V_365 ) ;
if ( V_365 % 2 != 0 && V_366 == 0xf )
return 0 ;
V_365 -= V_365 % 2 ;
if ( V_366 != 0xf )
V_366 -= V_366 % 2 ;
}
V_367 = V_369 + V_365 / 2 + ( V_365 % 2 ) * 0x00e ;
if ( V_366 != 0xf )
V_368 = ( V_366 << 4 ) | V_370 ;
return F_26 ( V_2 , V_6 , 0 , V_367 , V_368 ) ;
}
static int F_243 ( struct V_240 * V_241 ,
T_1 V_6 , int V_371 )
{
struct V_1 * V_2 = F_117 ( V_241 , struct V_1 , V_113 ) ;
bool V_372 = false ;
int V_373 = V_371 ;
int V_367 ;
int V_368 ;
if ( V_371 > 7 )
return - V_12 ;
if ( ! F_242 ( V_2 ) ) {
V_373 = F_237 ( V_371 ) ;
if ( V_373 % 2 != 0 ) {
V_373 -= 1 ;
V_372 = true ;
}
}
V_367 = V_374 + V_373 / 2 + ( V_373 % 2 ) * 0x00e ;
V_368 = F_24 ( V_2 , V_6 , 0 , V_367 , 0 ) ;
if ( ! ( V_368 & V_370 ) )
return 0xf ;
return ( ( V_368 & 0xf0 ) >> 4 ) + ! ! V_372 ;
}
static int F_244 (
struct V_110 * V_111 ,
struct V_334 * V_335 ,
int V_112 )
{
int V_73 ;
int V_375 = 0 ;
if ( ( V_112 % 2 ) != 0 )
return - 1 ;
for ( V_73 = 0 ; V_73 < 7 ; V_73 += 2 ) {
if ( V_335 -> V_361 [ V_73 ] || V_335 -> V_361 [ V_73 + 1 ] )
V_375 ++ ;
}
if ( V_375 * 2 != V_112 )
return - 1 ;
return V_376 ;
}
static void F_245 ( struct V_110 * V_377 ,
struct V_334 * V_335 ,
unsigned int * V_111 , int V_112 )
{
int V_32 = 0 ;
int V_73 ;
for ( V_73 = 7 ; V_73 >= 0 ; V_73 -- ) {
int V_309 = 7 - F_237 ( 7 - V_73 ) ;
int V_378 = V_335 -> V_361 [ V_309 ] ;
if ( ! V_378 ) {
if ( V_335 -> V_361 [ V_309 + ( V_309 % 2 ? - 1 : 1 ) ] )
V_111 [ V_32 ++ ] = V_379 ;
continue;
}
V_111 [ V_32 ++ ] = F_246 ( V_378 ) ;
}
F_132 ( V_32 != V_112 ) ;
}
static int F_247 ( struct V_1 * V_2 , T_1 V_6 ,
bool V_147 )
{
int V_380 , V_381 ;
V_380 = F_24 ( V_2 , V_6 , 0 , V_382 , 0 ) ;
if ( V_380 >= 0 && ( V_380 & V_383 ) ) {
if ( V_147 )
V_381 = V_380 | V_384 ;
else
V_381 = V_380 & ~ V_384 ;
F_8 ( V_2 ,
L_30 ,
V_6 ,
V_380 == V_381 ? L_16 : L_17 ,
V_381 ) ;
if ( V_380 != V_381 )
F_26 ( V_2 , V_6 , 0 ,
V_385 ,
V_381 ) ;
} else if ( V_147 )
return - V_12 ;
return 0 ;
}
static int F_248 ( struct V_1 * V_2 , T_1 V_20 ,
T_1 V_6 , T_3 V_155 , int V_156 )
{
if ( F_235 ( V_2 ) ) {
int V_386 = 180 ;
if ( V_156 & V_387 )
V_386 = 0 ;
F_26 ( V_2 , V_20 , 0 , V_388 , V_386 ) ;
}
return F_68 ( V_2 , V_20 , V_6 , V_155 , V_156 ) ;
}
static int F_249 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_8 , V_45 ;
V_45 = F_156 ( V_2 ) ;
if ( V_45 )
return V_45 ;
for ( V_8 = 0 ; V_8 < V_4 -> V_11 ; V_8 ++ ) {
struct V_9 * V_10 = F_3 ( V_4 , V_8 ) ;
F_26 ( V_2 , V_10 -> V_6 , 0 , V_389 , 0 ) ;
if ( F_242 ( V_2 ) )
F_26 ( V_2 , V_10 -> V_6 , 0 ,
V_390 ,
V_391 ) ;
}
return 0 ;
}
static int F_250 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_159 * V_160 ;
int V_45 , V_21 ;
V_45 = F_173 ( V_2 ) ;
if ( V_45 )
return V_45 ;
V_2 -> V_257 . V_258 = F_249 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_117 . V_209 = F_233 ;
V_4 -> V_117 . V_119 = F_236 ;
V_4 -> V_117 . V_157 = F_247 ;
V_4 -> V_117 . V_239 = F_248 ;
V_4 -> V_111 . V_117 . V_392 = F_243 ;
V_4 -> V_111 . V_117 . V_393 = F_241 ;
if ( ! F_242 ( V_2 ) ) {
V_4 -> V_111 . V_117 . V_342 =
F_244 ;
V_4 -> V_111 . V_117 . V_394 =
F_245 ;
V_4 -> V_111 . V_117 . V_343 = F_238 ;
}
for ( V_21 = 0 ; V_21 < V_4 -> V_22 ; V_21 ++ ) {
V_160 = F_11 ( V_4 , V_21 ) ;
V_160 -> V_178 = F_251 ( V_160 -> V_178 , 8u ) ;
V_160 -> V_179 |= V_325 ;
V_160 -> V_180 |= V_327 ;
V_160 -> V_181 = F_251 ( V_160 -> V_181 , 24u ) ;
}
V_4 -> V_111 . V_178 = F_251 ( V_4 -> V_111 . V_178 , 8u ) ;
return 0 ;
}
static int F_252 ( struct V_1 * V_2 )
{
return F_215 ( V_2 , V_395 , V_396 ) ;
}
