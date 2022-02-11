static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_6 * V_7 , * V_8 ;
struct V_9 * V_10 ;
V_10 = F_2 ( sizeof( * V_10 ) , V_11 ) ;
if ( ! V_10 )
return - V_12 ;
F_3 ( V_10 ) ;
F_4 ( & V_4 -> V_13 -> V_14 ) ;
F_5 (req, &ep->queue, queue) {
V_8 = F_6 ( V_7 , sizeof( * V_8 ) , V_15 ) ;
if ( ! V_8 )
goto V_16;
F_7 ( & V_8 -> V_17 , V_10 ) ;
}
F_8 ( & V_4 -> V_13 -> V_14 ) ;
V_2 -> V_18 = V_10 ;
return 0 ;
V_16:
F_8 ( & V_4 -> V_13 -> V_14 ) ;
F_9 (req, req_copy, queue_data, queue) {
F_10 ( & V_7 -> V_17 ) ;
F_11 ( V_7 ) ;
}
F_11 ( V_10 ) ;
return - V_12 ;
}
static T_1 F_12 ( struct V_2 * V_2 , char T_2 * V_19 ,
T_3 V_20 , T_4 * V_21 )
{
struct V_9 * V_17 = V_2 -> V_18 ;
struct V_6 * V_7 , * V_22 ;
T_3 V_23 , V_24 , V_25 = 0 ;
char V_26 [ 38 ] ;
if ( ! F_13 ( V_27 , V_19 , V_20 ) )
return - V_28 ;
F_14 ( & F_15 ( V_2 ) -> V_29 ) ;
F_9 (req, tmp_req, queue, queue) {
V_23 = snprintf ( V_26 , sizeof( V_26 ) ,
L_1 ,
V_7 -> V_7 . V_19 , V_7 -> V_7 . V_30 ,
V_7 -> V_7 . V_31 ? 'i' : 'I' ,
V_7 -> V_7 . V_32 ? 'Z' : 'z' ,
V_7 -> V_7 . V_33 ? 's' : 'S' ,
V_7 -> V_7 . V_34 ,
V_7 -> V_35 ? 'F' : 'f' ,
V_7 -> V_36 ? 'D' : 'd' ,
V_7 -> V_37 ? 'L' : 'l' ) ;
V_23 = F_16 ( V_23 , sizeof( V_26 ) ) ;
if ( V_23 > V_20 )
break;
F_10 ( & V_7 -> V_17 ) ;
F_11 ( V_7 ) ;
V_24 = F_17 ( V_19 , V_26 , V_23 ) ;
V_25 += V_23 - V_24 ;
if ( V_24 )
break;
V_20 -= V_23 ;
V_19 += V_23 ;
}
F_18 ( & F_15 ( V_2 ) -> V_29 ) ;
return V_25 ;
}
static int F_19 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_18 ;
struct V_6 * V_7 , * V_22 ;
F_9 (req, tmp_req, queue_data, queue) {
F_10 ( & V_7 -> V_17 ) ;
F_11 ( V_7 ) ;
}
F_11 ( V_10 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_38 * V_13 ;
unsigned int V_39 ;
T_5 * V_40 ;
int V_41 = - V_12 ;
F_14 ( & V_1 -> V_29 ) ;
V_13 = V_1 -> V_5 ;
V_40 = F_2 ( V_1 -> V_42 , V_11 ) ;
if ( ! V_40 )
goto V_43;
F_4 ( & V_13 -> V_14 ) ;
for ( V_39 = 0 ; V_39 < V_1 -> V_42 / 4 ; V_39 ++ )
V_40 [ V_39 ] = F_21 ( V_13 -> V_44 + V_39 * 4 ) ;
F_8 ( & V_13 -> V_14 ) ;
V_2 -> V_18 = V_40 ;
V_41 = 0 ;
V_43:
F_18 ( & V_1 -> V_29 ) ;
return V_41 ;
}
static T_1 F_22 ( struct V_2 * V_2 , char T_2 * V_19 ,
T_3 V_20 , T_4 * V_21 )
{
struct V_1 * V_1 = F_15 ( V_2 ) ;
int V_41 ;
F_14 ( & V_1 -> V_29 ) ;
V_41 = F_23 ( V_19 , V_20 , V_21 ,
V_2 -> V_18 ,
F_15 ( V_2 ) -> V_42 ) ;
F_18 ( & V_1 -> V_29 ) ;
return V_41 ;
}
static int F_24 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
F_11 ( V_2 -> V_18 ) ;
return 0 ;
}
static void F_25 ( struct V_38 * V_13 ,
struct V_3 * V_4 )
{
struct V_45 * V_46 ;
V_46 = F_26 ( V_4 -> V_4 . V_47 , V_13 -> V_48 ) ;
if ( ! V_46 )
goto V_49;
V_4 -> V_50 = V_46 ;
V_4 -> V_51 = F_27 ( L_2 , 0400 , V_46 ,
V_4 , & V_52 ) ;
if ( ! V_4 -> V_51 )
goto V_53;
if ( V_4 -> V_54 ) {
V_4 -> V_55
= F_28 ( L_3 , 0400 , V_46 ,
& V_4 -> V_56 ) ;
if ( ! V_4 -> V_55 )
goto V_57;
}
if ( F_29 ( V_4 ) ) {
V_4 -> V_58
= F_28 ( L_4 , 0400 , V_46 ,
& V_4 -> V_59 ) ;
if ( ! V_4 -> V_58 )
goto V_60;
}
return;
V_60:
if ( V_4 -> V_54 )
F_30 ( V_4 -> V_55 ) ;
V_57:
F_30 ( V_4 -> V_51 ) ;
V_53:
F_30 ( V_46 ) ;
V_49:
F_31 ( & V_4 -> V_13 -> V_61 -> V_62 ,
L_5 , V_4 -> V_4 . V_47 ) ;
}
static void F_32 ( struct V_3 * V_4 )
{
F_30 ( V_4 -> V_51 ) ;
F_30 ( V_4 -> V_55 ) ;
F_30 ( V_4 -> V_58 ) ;
F_30 ( V_4 -> V_50 ) ;
V_4 -> V_55 = NULL ;
V_4 -> V_50 = NULL ;
}
static void F_33 ( struct V_38 * V_13 )
{
struct V_45 * V_63 , * V_44 ;
struct V_64 * V_65 ;
V_63 = F_26 ( V_13 -> V_66 . V_47 , NULL ) ;
if ( F_34 ( V_63 ) || ! V_63 )
goto V_49;
V_13 -> V_48 = V_63 ;
V_65 = F_35 ( V_13 -> V_61 , V_67 ,
V_68 ) ;
if ( V_65 ) {
V_44 = F_36 ( L_6 , 0400 , V_63 , V_13 ,
& V_69 ,
F_37 ( V_65 ) ) ;
if ( ! V_44 )
goto V_70;
V_13 -> V_71 = V_44 ;
}
F_25 ( V_13 , F_38 ( V_13 -> V_66 . V_72 ) ) ;
return;
V_70:
F_30 ( V_63 ) ;
V_49:
V_13 -> V_48 = NULL ;
F_31 ( & V_13 -> V_61 -> V_62 , L_7 ) ;
}
static void F_39 ( struct V_38 * V_13 )
{
F_32 ( F_38 ( V_13 -> V_66 . V_72 ) ) ;
F_30 ( V_13 -> V_71 ) ;
F_30 ( V_13 -> V_48 ) ;
V_13 -> V_71 = NULL ;
V_13 -> V_48 = NULL ;
}
static inline void F_25 ( struct V_38 * V_13 ,
struct V_3 * V_4 )
{
}
static inline void F_32 ( struct V_3 * V_4 )
{
}
static inline void F_33 ( struct V_38 * V_13 )
{
}
static inline void F_39 ( struct V_38 * V_13 )
{
}
static inline T_5 F_40 ( struct V_38 * V_13 )
{
return V_13 -> V_73 ;
}
static inline void F_41 ( struct V_38 * V_13 , T_5 V_74 )
{
F_42 ( V_13 , V_75 , V_74 ) ;
V_13 -> V_73 = V_74 ;
}
static int F_43 ( struct V_38 * V_13 )
{
if ( F_44 ( V_13 -> V_76 ) )
return F_45 ( V_13 -> V_76 ) ^ V_13 -> V_77 ;
return 1 ;
}
static void F_46 ( struct V_38 * V_13 , int V_78 )
{
if ( V_13 -> V_79 && V_13 -> V_79 -> F_46 )
V_13 -> V_79 -> F_46 ( V_13 , V_78 ) ;
}
static void F_47 ( struct V_38 * V_13 )
{
if ( ! V_13 -> V_80 )
return;
if ( V_13 -> V_79 && V_13 -> V_79 -> V_81 )
V_13 -> V_79 -> V_81 ( V_13 ) ;
V_13 -> V_80 = false ;
}
static void F_48 ( struct V_3 * V_4 , struct V_6 * V_7 )
{
unsigned int V_82 ;
V_82 = V_7 -> V_7 . V_30 - V_7 -> V_7 . V_25 ;
V_7 -> V_37 = 1 ;
if ( V_82 > V_4 -> V_4 . V_83 ) {
V_82 = V_4 -> V_4 . V_83 ;
V_7 -> V_37 = 0 ;
} else if ( V_82 == V_4 -> V_4 . V_83 && V_7 -> V_7 . V_32 )
V_7 -> V_37 = 0 ;
F_49 ( V_84 , L_8 ,
V_4 -> V_4 . V_47 , V_7 , V_82 ,
V_7 -> V_37 ? L_9 : L_10 ) ;
F_50 ( V_4 -> V_85 , V_7 -> V_7 . V_19 + V_7 -> V_7 . V_25 , V_82 ) ;
F_51 ( V_4 , V_86 , V_87 ) ;
V_7 -> V_7 . V_25 += V_82 ;
}
static void F_52 ( struct V_3 * V_4 , struct V_6 * V_7 )
{
F_49 ( V_84 , L_11 ,
V_4 -> V_4 . V_47 , V_7 , V_7 -> V_7 . V_30 ) ;
V_7 -> V_7 . V_25 = 0 ;
V_7 -> V_35 = 1 ;
if ( V_7 -> V_36 ) {
if ( V_7 -> V_7 . V_30 == 0 ) {
F_51 ( V_4 , V_88 , V_87 ) ;
return;
}
if ( V_7 -> V_7 . V_32 )
F_51 ( V_4 , V_88 , V_89 ) ;
else
F_51 ( V_4 , V_90 , V_89 ) ;
F_53 ( V_4 , V_91 , V_7 -> V_7 . V_92 ) ;
F_53 ( V_4 , V_93 , V_7 -> V_94 ) ;
} else {
F_48 ( V_4 , V_7 ) ;
if ( V_7 -> V_37 ) {
F_51 ( V_4 , V_90 , V_87 ) ;
F_51 ( V_4 , V_88 , V_95 ) ;
} else {
F_51 ( V_4 , V_90 , V_95 ) ;
F_51 ( V_4 , V_88 , V_87 ) ;
}
}
}
static void F_54 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
if ( F_55 ( & V_4 -> V_17 ) ) {
F_51 ( V_4 , V_90 , V_87 | V_96 ) ;
return;
}
V_7 = F_56 ( V_4 -> V_17 . V_97 , struct V_6 , V_17 ) ;
if ( ! V_7 -> V_35 )
F_52 ( V_4 , V_7 ) ;
}
static void F_57 ( struct V_38 * V_13 , struct V_3 * V_4 )
{
V_4 -> V_59 = V_98 ;
F_51 ( V_4 , V_86 , V_87 ) ;
F_51 ( V_4 , V_88 , V_95 ) ;
}
static void F_58 ( struct V_3 * V_4 )
{
struct V_38 * V_13 = V_4 -> V_13 ;
struct V_6 * V_7 ;
unsigned long V_34 ;
unsigned int V_99 , V_100 ;
int V_101 = 0 ;
V_34 = F_59 ( V_4 , V_102 ) ;
V_100 = F_60 ( V_103 , V_34 ) ;
F_49 ( V_84 , L_12 , V_100 ) ;
while ( V_100 > 0 ) {
if ( F_55 ( & V_4 -> V_17 ) ) {
F_51 ( V_4 , V_90 , V_96 ) ;
break;
}
V_7 = F_56 ( V_4 -> V_17 . V_97 ,
struct V_6 , V_17 ) ;
V_99 = F_60 ( V_104 , V_34 ) ;
if ( V_34 & ( 1 << 31 ) )
V_101 = 1 ;
if ( V_7 -> V_7 . V_25 + V_99 >= V_7 -> V_7 . V_30 ) {
V_101 = 1 ;
V_99 = V_7 -> V_7 . V_30 - V_7 -> V_7 . V_25 ;
}
F_61 ( V_7 -> V_7 . V_19 + V_7 -> V_7 . V_25 ,
V_4 -> V_85 , V_99 ) ;
V_7 -> V_7 . V_25 += V_99 ;
F_51 ( V_4 , V_105 , V_96 ) ;
if ( V_101 ) {
F_49 ( V_84 , L_13 , V_4 -> V_4 . V_47 ) ;
V_7 -> V_7 . V_34 = 0 ;
F_62 ( & V_7 -> V_17 ) ;
F_51 ( V_4 , V_90 , V_96 ) ;
F_63 ( & V_13 -> V_14 ) ;
F_64 ( & V_4 -> V_4 , & V_7 -> V_7 ) ;
F_65 ( & V_13 -> V_14 ) ;
}
V_34 = F_59 ( V_4 , V_102 ) ;
V_100 = F_60 ( V_103 , V_34 ) ;
if ( V_101 && F_29 ( V_4 ) ) {
F_57 ( V_13 , V_4 ) ;
break;
}
}
}
static void
F_66 ( struct V_3 * V_4 , struct V_6 * V_7 , int V_34 )
{
struct V_38 * V_13 = V_4 -> V_13 ;
F_67 ( ! F_55 ( & V_7 -> V_17 ) ) ;
if ( V_7 -> V_7 . V_34 == - V_106 )
V_7 -> V_7 . V_34 = V_34 ;
if ( V_7 -> V_36 )
F_68 ( & V_13 -> V_66 , & V_7 -> V_7 , V_4 -> V_107 ) ;
F_49 ( V_108 | V_109 ,
L_14 ,
V_4 -> V_4 . V_47 , V_7 , V_7 -> V_7 . V_34 , V_7 -> V_7 . V_25 ) ;
F_63 ( & V_13 -> V_14 ) ;
F_64 ( & V_4 -> V_4 , & V_7 -> V_7 ) ;
F_65 ( & V_13 -> V_14 ) ;
}
static void
F_69 ( struct V_3 * V_4 , struct V_9 * V_110 , int V_34 )
{
struct V_6 * V_7 , * V_22 ;
F_9 (req, tmp_req, list, queue) {
F_62 ( & V_7 -> V_17 ) ;
F_66 ( V_4 , V_7 , V_34 ) ;
}
}
static int
F_70 ( struct V_111 * V_112 , const struct V_113 * V_114 )
{
struct V_3 * V_4 = F_38 ( V_112 ) ;
struct V_38 * V_13 = V_4 -> V_13 ;
unsigned long V_115 , V_116 , V_83 ;
unsigned int V_117 ;
F_49 ( V_108 , L_15 , V_4 -> V_4 . V_47 , V_114 ) ;
V_83 = F_71 ( V_114 ) & 0x7ff ;
if ( ( ( V_114 -> V_118 & V_119 ) != V_4 -> V_120 )
|| V_4 -> V_120 == 0
|| V_114 -> V_121 != V_122
|| V_83 == 0
|| V_83 > V_4 -> V_123 ) {
F_49 ( V_124 , L_16 ) ;
return - V_125 ;
}
V_4 -> V_126 = 0 ;
V_4 -> V_107 = 0 ;
if ( V_83 <= 8 )
V_116 = F_72 ( V_127 , V_128 ) ;
else
V_116 = F_72 ( V_127 , F_73 ( V_83 - 1 ) - 3 ) ;
F_49 ( V_129 , L_17 ,
V_4 -> V_4 . V_47 , V_116 , V_83 ) ;
if ( F_74 ( V_114 ) ) {
V_4 -> V_107 = 1 ;
V_116 |= V_130 ;
}
switch ( F_75 ( V_114 ) ) {
case V_131 :
V_116 |= F_72 ( V_132 , V_133 ) ;
V_116 |= F_72 ( V_134 , V_135 ) ;
break;
case V_136 :
if ( ! V_4 -> V_137 ) {
F_49 ( V_124 , L_18 ,
V_4 -> V_4 . V_47 ) ;
return - V_125 ;
}
V_117 = ( ( F_71 ( V_114 ) >> 11 ) & 3 ) + 1 ;
if ( V_117 > 3 )
return - V_125 ;
V_4 -> V_126 = 1 ;
V_116 |= F_72 ( V_132 , V_138 ) ;
if ( V_117 > 1 && V_4 -> V_139 == 3 )
V_116 |= F_72 ( V_134 , V_140 ) ;
else
V_116 |= F_72 ( V_134 , V_141 ) ;
V_116 |= F_72 ( V_142 , V_117 ) ;
break;
case V_143 :
V_116 |= F_72 ( V_132 , V_144 ) ;
V_116 |= F_72 ( V_134 , V_141 ) ;
break;
case V_145 :
V_116 |= F_72 ( V_132 , V_146 ) ;
V_116 |= F_72 ( V_134 , V_141 ) ;
break;
}
F_76 ( & V_4 -> V_13 -> V_14 , V_115 ) ;
V_4 -> V_4 . V_114 = V_114 ;
V_4 -> V_4 . V_83 = V_83 ;
F_51 ( V_4 , V_147 , V_116 ) ;
F_51 ( V_4 , V_88 , V_148 ) ;
if ( V_4 -> V_54 ) {
T_5 V_94 ;
F_41 ( V_13 , F_40 ( V_13 ) |
F_72 ( V_149 , 1 << V_4 -> V_120 ) |
F_72 ( V_150 , 1 << V_4 -> V_120 ) ) ;
V_94 = V_151 | V_152 ;
F_51 ( V_4 , V_88 , V_94 ) ;
} else {
F_41 ( V_13 , F_40 ( V_13 ) |
F_72 ( V_149 , 1 << V_4 -> V_120 ) ) ;
}
F_77 ( & V_13 -> V_14 , V_115 ) ;
F_49 ( V_129 , L_19 , V_4 -> V_120 ,
( unsigned long ) F_59 ( V_4 , V_147 ) ) ;
F_49 ( V_129 , L_20 ,
( unsigned long ) F_40 ( V_13 ) ) ;
return 0 ;
}
static int F_78 ( struct V_111 * V_112 )
{
struct V_3 * V_4 = F_38 ( V_112 ) ;
struct V_38 * V_13 = V_4 -> V_13 ;
F_79 ( V_153 ) ;
unsigned long V_115 ;
F_49 ( V_108 , L_21 , V_4 -> V_4 . V_47 ) ;
F_76 ( & V_13 -> V_14 , V_115 ) ;
if ( ! V_4 -> V_4 . V_114 ) {
F_77 ( & V_13 -> V_14 , V_115 ) ;
if ( V_13 -> V_66 . V_154 != V_155 )
F_49 ( V_124 , L_22 ,
V_4 -> V_4 . V_47 ) ;
return - V_125 ;
}
V_4 -> V_4 . V_114 = NULL ;
F_80 ( & V_4 -> V_17 , & V_153 ) ;
if ( V_4 -> V_54 ) {
F_53 ( V_4 , V_93 , 0 ) ;
F_53 ( V_4 , V_91 , 0 ) ;
F_81 ( V_4 , V_156 ) ;
}
F_51 ( V_4 , V_90 , V_148 ) ;
F_41 ( V_13 , F_40 ( V_13 ) &
~ F_72 ( V_149 , 1 << V_4 -> V_120 ) ) ;
F_69 ( V_4 , & V_153 , - V_157 ) ;
F_77 ( & V_13 -> V_14 , V_115 ) ;
return 0 ;
}
static struct V_158 *
F_82 ( struct V_111 * V_112 , T_6 V_159 )
{
struct V_6 * V_7 ;
F_49 ( V_108 , L_23 , V_112 , V_159 ) ;
V_7 = F_83 ( sizeof( * V_7 ) , V_159 ) ;
if ( ! V_7 )
return NULL ;
F_3 ( & V_7 -> V_17 ) ;
return & V_7 -> V_7 ;
}
static void
F_84 ( struct V_111 * V_112 , struct V_158 * V_160 )
{
struct V_6 * V_7 = F_85 ( V_160 ) ;
F_49 ( V_108 , L_24 , V_112 , V_160 ) ;
F_11 ( V_7 ) ;
}
static int F_86 ( struct V_38 * V_13 , struct V_3 * V_4 ,
struct V_6 * V_7 , T_6 V_159 )
{
unsigned long V_115 ;
int V_41 ;
F_49 ( V_161 , L_25 ,
V_4 -> V_4 . V_47 , V_7 -> V_7 . V_30 , & V_7 -> V_7 . V_92 ,
V_7 -> V_7 . V_32 ? 'Z' : 'z' ,
V_7 -> V_7 . V_33 ? 'S' : 's' ,
V_7 -> V_7 . V_31 ? 'I' : 'i' ) ;
if ( V_7 -> V_7 . V_30 > 0x10000 ) {
F_49 ( V_124 , L_26 , V_7 -> V_7 . V_30 ) ;
return - V_125 ;
}
V_41 = F_87 ( & V_13 -> V_66 , & V_7 -> V_7 , V_4 -> V_107 ) ;
if ( V_41 )
return V_41 ;
V_7 -> V_36 = 1 ;
V_7 -> V_94 = F_72 ( V_162 , V_7 -> V_7 . V_30 )
| V_163 | V_164
| V_165 ;
if ( ! V_4 -> V_107 )
V_7 -> V_94 |= V_166 | V_167 ;
V_41 = - V_157 ;
F_76 ( & V_13 -> V_14 , V_115 ) ;
if ( V_4 -> V_4 . V_114 ) {
if ( F_55 ( & V_4 -> V_17 ) )
F_52 ( V_4 , V_7 ) ;
F_7 ( & V_7 -> V_17 , & V_4 -> V_17 ) ;
V_41 = 0 ;
}
F_77 ( & V_13 -> V_14 , V_115 ) ;
return V_41 ;
}
static int
F_88 ( struct V_111 * V_112 , struct V_158 * V_160 , T_6 V_159 )
{
struct V_6 * V_7 = F_85 ( V_160 ) ;
struct V_3 * V_4 = F_38 ( V_112 ) ;
struct V_38 * V_13 = V_4 -> V_13 ;
unsigned long V_115 ;
int V_41 ;
F_49 ( V_108 | V_84 | V_109 , L_27 ,
V_4 -> V_4 . V_47 , V_7 , V_160 -> V_30 ) ;
if ( ! V_13 -> V_168 || V_13 -> V_66 . V_154 == V_155 ||
! V_4 -> V_4 . V_114 )
return - V_157 ;
V_7 -> V_35 = 0 ;
V_7 -> V_36 = 0 ;
V_7 -> V_37 = 0 ;
V_160 -> V_34 = - V_106 ;
V_160 -> V_25 = 0 ;
if ( V_4 -> V_54 )
return F_86 ( V_13 , V_4 , V_7 , V_159 ) ;
V_41 = - V_157 ;
F_76 ( & V_13 -> V_14 , V_115 ) ;
if ( V_4 -> V_4 . V_114 ) {
F_7 ( & V_7 -> V_17 , & V_4 -> V_17 ) ;
if ( ( ! F_29 ( V_4 ) && V_4 -> V_107 ) ||
( F_29 ( V_4 )
&& ( V_4 -> V_59 == V_169
|| V_4 -> V_59 == V_98 ) ) )
F_51 ( V_4 , V_88 , V_87 ) ;
else
F_51 ( V_4 , V_88 , V_96 ) ;
V_41 = 0 ;
}
F_77 ( & V_13 -> V_14 , V_115 ) ;
return V_41 ;
}
static void
F_89 ( struct V_3 * V_4 , struct V_6 * V_7 , T_5 V_34 )
{
V_7 -> V_7 . V_25 = V_7 -> V_7 . V_30 - F_60 ( V_162 , V_34 ) ;
}
static int F_90 ( struct V_3 * V_4 , T_5 * V_170 )
{
unsigned int V_171 ;
T_5 V_34 ;
F_53 ( V_4 , V_93 , 0 ) ;
for ( V_171 = 40 ; V_171 ; -- V_171 ) {
V_34 = F_81 ( V_4 , V_156 ) ;
if ( ! ( V_34 & V_163 ) )
break;
F_91 ( 1 ) ;
}
if ( V_170 )
* V_170 = V_34 ;
if ( V_171 == 0 ) {
F_31 ( & V_4 -> V_13 -> V_61 -> V_62 ,
L_28 ,
V_4 -> V_4 . V_47 ) ;
return - V_172 ;
}
return 0 ;
}
static int F_92 ( struct V_111 * V_112 , struct V_158 * V_160 )
{
struct V_3 * V_4 = F_38 ( V_112 ) ;
struct V_38 * V_13 = V_4 -> V_13 ;
struct V_6 * V_7 ;
unsigned long V_115 ;
T_5 V_34 ;
F_49 ( V_108 | V_84 , L_29 ,
V_4 -> V_4 . V_47 , V_7 ) ;
F_76 ( & V_13 -> V_14 , V_115 ) ;
F_5 (req, &ep->queue, queue) {
if ( & V_7 -> V_7 == V_160 )
break;
}
if ( & V_7 -> V_7 != V_160 ) {
F_77 ( & V_13 -> V_14 , V_115 ) ;
return - V_125 ;
}
if ( V_7 -> V_36 ) {
if ( V_4 -> V_17 . V_97 == & V_7 -> V_17 ) {
V_34 = F_81 ( V_4 , V_156 ) ;
if ( V_34 & V_163 )
F_90 ( V_4 , & V_34 ) ;
#ifdef F_93
V_4 -> V_56 = V_34 ;
#endif
F_42 ( V_13 , V_173 , 1 << V_4 -> V_120 ) ;
F_89 ( V_4 , V_7 , V_34 ) ;
}
}
F_62 ( & V_7 -> V_17 ) ;
F_66 ( V_4 , V_7 , - V_174 ) ;
F_54 ( V_4 ) ;
F_77 ( & V_13 -> V_14 , V_115 ) ;
return 0 ;
}
static int F_94 ( struct V_111 * V_112 , int V_175 )
{
struct V_3 * V_4 = F_38 ( V_112 ) ;
struct V_38 * V_13 = V_4 -> V_13 ;
unsigned long V_115 ;
int V_41 = 0 ;
F_49 ( V_108 , L_30 , V_4 -> V_4 . V_47 ,
V_175 ? L_31 : L_32 ) ;
if ( ! V_4 -> V_4 . V_114 ) {
F_49 ( V_124 , L_33 ,
V_4 -> V_4 . V_47 ) ;
return - V_176 ;
}
if ( V_4 -> V_126 ) {
F_49 ( V_124 , L_34 ,
V_4 -> V_4 . V_47 ) ;
return - V_177 ;
}
F_76 ( & V_13 -> V_14 , V_115 ) ;
if ( ! F_55 ( & V_4 -> V_17 )
|| ( ( V_175 && V_4 -> V_107 && ( F_59 ( V_4 , V_102 )
& F_72 ( V_103 , - 1L ) ) ) ) ) {
V_41 = - V_178 ;
} else {
if ( V_175 )
F_51 ( V_4 , V_86 , V_179 ) ;
else
F_51 ( V_4 , V_105 ,
V_179 | V_180 ) ;
F_59 ( V_4 , V_102 ) ;
}
F_77 ( & V_13 -> V_14 , V_115 ) ;
return V_41 ;
}
static int F_95 ( struct V_111 * V_112 )
{
struct V_3 * V_4 = F_38 ( V_112 ) ;
return F_60 ( V_104 , F_59 ( V_4 , V_102 ) ) ;
}
static void F_96 ( struct V_111 * V_112 )
{
struct V_3 * V_4 = F_38 ( V_112 ) ;
struct V_38 * V_13 = V_4 -> V_13 ;
F_42 ( V_13 , V_173 , 1 << V_4 -> V_120 ) ;
}
static int F_97 ( struct V_181 * V_66 )
{
struct V_38 * V_13 = F_98 ( V_66 ) ;
return F_60 ( V_182 , F_99 ( V_13 , V_183 ) ) ;
}
static int F_100 ( struct V_181 * V_66 )
{
struct V_38 * V_13 = F_98 ( V_66 ) ;
unsigned long V_115 ;
T_5 V_94 ;
int V_41 = - V_125 ;
F_76 ( & V_13 -> V_14 , V_115 ) ;
if ( V_13 -> V_184 & ( 1 << V_185 ) ) {
V_94 = F_99 ( V_13 , V_186 ) ;
F_42 ( V_13 , V_186 , V_94 | V_187 ) ;
V_41 = 0 ;
}
F_77 ( & V_13 -> V_14 , V_115 ) ;
return V_41 ;
}
static int
F_101 ( struct V_181 * V_66 , int V_188 )
{
struct V_38 * V_13 = F_98 ( V_66 ) ;
unsigned long V_115 ;
V_66 -> V_188 = ( V_188 != 0 ) ;
F_76 ( & V_13 -> V_14 , V_115 ) ;
if ( V_188 )
V_13 -> V_184 |= 1 << V_189 ;
else
V_13 -> V_184 &= ~ ( 1 << V_189 ) ;
F_77 ( & V_13 -> V_14 , V_115 ) ;
return 0 ;
}
static void F_102 ( struct V_38 * V_13 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 , * V_22 ;
F_42 ( V_13 , V_173 , ~ 0UL ) ;
V_4 = F_38 ( V_13 -> V_66 . V_72 ) ;
F_9 (req, tmp_req, &ep->queue, queue) {
F_62 ( & V_7 -> V_17 ) ;
F_66 ( V_4 , V_7 , - V_174 ) ;
}
F_5 (ep, &udc->gadget.ep_list, ep.ep_list) {
if ( V_4 -> V_4 . V_114 ) {
F_63 ( & V_13 -> V_14 ) ;
F_78 ( & V_4 -> V_4 ) ;
F_65 ( & V_13 -> V_14 ) ;
}
}
}
static struct V_3 * F_103 ( struct V_38 * V_13 , T_7 V_190 )
{
struct V_3 * V_4 ;
if ( ( V_190 & V_119 ) == 0 )
return F_38 ( V_13 -> V_66 . V_72 ) ;
F_5 (ep, &udc->gadget.ep_list, ep.ep_list) {
T_8 V_118 ;
if ( ! V_4 -> V_4 . V_114 )
continue;
V_118 = V_4 -> V_4 . V_114 -> V_118 ;
if ( ( V_190 ^ V_118 ) & V_191 )
continue;
if ( ( V_118 & V_119 )
== ( V_190 & V_119 ) )
return V_4 ;
}
return NULL ;
}
static inline void F_104 ( struct V_38 * V_13 , struct V_3 * V_4 )
{
F_51 ( V_4 , V_86 , V_179 ) ;
V_4 -> V_59 = V_192 ;
}
static inline int F_105 ( struct V_38 * V_13 , struct V_3 * V_4 )
{
if ( F_59 ( V_4 , V_102 ) & V_179 )
return 1 ;
return 0 ;
}
static inline void F_106 ( struct V_38 * V_13 , unsigned int V_193 )
{
T_5 V_194 ;
F_49 ( V_195 , L_35 , V_193 ) ;
V_194 = F_99 ( V_13 , V_186 ) ;
V_194 = F_107 ( V_196 , V_193 , V_194 ) ;
F_42 ( V_13 , V_186 , V_194 ) ;
}
static int F_108 ( struct V_38 * V_13 )
{
static const char V_197 [] = {
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0xAA , 0xAA , 0xAA , 0xAA , 0xAA , 0xAA , 0xAA , 0xAA ,
0xEE , 0xEE , 0xEE , 0xEE , 0xEE , 0xEE , 0xEE , 0xEE ,
0xFE , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF ,
0xFF , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF ,
0x7F , 0xBF , 0xDF , 0xEF , 0xF7 , 0xFB , 0xFD ,
0xFC , 0x7E , 0xBF , 0xDF , 0xEF , 0xF7 , 0xFB , 0xFD , 0x7E
} ;
struct V_3 * V_4 ;
struct V_198 * V_62 = & V_13 -> V_61 -> V_62 ;
int V_199 ;
V_199 = V_13 -> V_199 ;
F_102 ( V_13 ) ;
switch ( V_199 ) {
case 0x0100 :
F_42 ( V_13 , V_200 , V_201 ) ;
F_109 ( V_62 , L_36 ) ;
break;
case 0x0200 :
F_42 ( V_13 , V_200 , V_202 ) ;
F_109 ( V_62 , L_37 ) ;
break;
case 0x0300 :
V_4 = & V_13 -> V_3 [ 0 ] ;
F_42 ( V_13 , V_200 ,
F_72 ( V_203 , V_204 ) ) ;
F_51 ( V_4 , V_147 ,
F_72 ( V_127 , V_205 )
| V_130
| F_72 ( V_132 , V_144 )
| F_72 ( V_134 , 1 ) ) ;
if ( ! ( F_59 ( V_4 , V_147 ) & V_206 ) ) {
F_104 ( V_13 , V_4 ) ;
F_31 ( V_62 , L_38 ) ;
} else {
F_51 ( V_4 , V_88 , V_148 ) ;
F_109 ( V_62 , L_39 ) ;
}
break;
case 0x0400 :
V_4 = & V_13 -> V_3 [ 0 ] ;
F_51 ( V_4 , V_147 ,
F_72 ( V_127 , V_205 )
| V_130
| F_72 ( V_132 , V_144 )
| F_72 ( V_134 , 1 ) ) ;
if ( ! ( F_59 ( V_4 , V_147 ) & V_206 ) ) {
F_104 ( V_13 , V_4 ) ;
F_31 ( V_62 , L_40 ) ;
} else {
F_51 ( V_4 , V_88 , V_148 ) ;
F_42 ( V_13 , V_200 , V_207 ) ;
F_50 ( V_4 -> V_85 , V_197 ,
sizeof( V_197 ) ) ;
F_51 ( V_4 , V_86 , V_87 ) ;
F_109 ( V_62 , L_41 ) ;
}
break;
default:
F_31 ( V_62 , L_42 , V_199 ) ;
return - V_125 ;
}
return 0 ;
}
static inline bool F_110 ( struct V_208 * V_209 )
{
if ( V_209 -> V_210 == F_111 ( V_185 ) )
return true ;
return false ;
}
static inline bool F_112 ( struct V_208 * V_209 )
{
if ( V_209 -> V_210 == F_111 ( V_211 ) )
return true ;
return false ;
}
static inline bool F_113 ( struct V_208 * V_209 )
{
if ( V_209 -> V_210 == F_111 ( V_212 ) )
return true ;
return false ;
}
static int F_114 ( struct V_38 * V_13 , struct V_3 * V_4 ,
struct V_208 * V_209 )
{
int V_213 = 0 ;
switch ( V_209 -> V_214 ) {
case V_215 : {
T_7 V_34 ;
if ( V_209 -> V_216 == ( V_191 | V_217 ) ) {
V_34 = F_111 ( V_13 -> V_184 ) ;
} else if ( V_209 -> V_216
== ( V_191 | V_218 ) ) {
V_34 = F_111 ( 0 ) ;
} else if ( V_209 -> V_216
== ( V_191 | V_219 ) ) {
struct V_3 * V_220 ;
V_220 = F_103 ( V_13 , F_115 ( V_209 -> V_190 ) ) ;
if ( ! V_220 )
goto V_221;
V_34 = 0 ;
if ( F_105 ( V_13 , V_220 ) )
V_34 |= F_111 ( 1 ) ;
} else
goto V_222;
if ( V_209 -> V_223 != F_111 ( sizeof( V_34 ) ) )
goto V_221;
V_4 -> V_59 = V_169 ;
F_116 ( V_34 , V_4 -> V_85 ) ;
F_51 ( V_4 , V_86 , V_87 ) ;
break;
}
case V_224 : {
if ( V_209 -> V_216 == V_217 ) {
if ( F_110 ( V_209 ) )
V_13 -> V_184
&= ~ ( 1 << V_185 ) ;
else
goto V_221;
} else if ( V_209 -> V_216 == V_219 ) {
struct V_3 * V_220 ;
if ( V_209 -> V_223 != F_111 ( 0 )
|| ! F_113 ( V_209 ) )
goto V_221;
V_220 = F_103 ( V_13 , F_115 ( V_209 -> V_190 ) ) ;
if ( ! V_220 )
goto V_221;
F_51 ( V_220 , V_105 , V_179 ) ;
if ( V_220 -> V_120 != 0 )
F_51 ( V_220 , V_105 ,
V_180 ) ;
} else {
goto V_222;
}
F_57 ( V_13 , V_4 ) ;
break;
}
case V_225 : {
if ( V_209 -> V_216 == V_217 ) {
if ( F_112 ( V_209 ) ) {
F_57 ( V_13 , V_4 ) ;
V_4 -> V_59 = V_226 ;
V_13 -> V_199 = F_115 ( V_209 -> V_190 ) ;
return 0 ;
} else if ( F_110 ( V_209 ) ) {
V_13 -> V_184 |= 1 << V_185 ;
} else {
goto V_221;
}
} else if ( V_209 -> V_216 == V_219 ) {
struct V_3 * V_220 ;
if ( V_209 -> V_223 != F_111 ( 0 )
|| ! F_113 ( V_209 ) )
goto V_221;
V_220 = F_103 ( V_13 , F_115 ( V_209 -> V_190 ) ) ;
if ( ! V_220 )
goto V_221;
F_51 ( V_220 , V_86 , V_179 ) ;
} else
goto V_222;
F_57 ( V_13 , V_4 ) ;
break;
}
case V_227 :
if ( V_209 -> V_216 != ( V_228 | V_217 ) )
goto V_222;
F_106 ( V_13 , F_115 ( V_209 -> V_210 ) ) ;
F_57 ( V_13 , V_4 ) ;
V_4 -> V_59 = V_229 ;
break;
default:
V_222:
F_63 ( & V_13 -> V_14 ) ;
V_213 = V_13 -> V_168 -> V_230 ( & V_13 -> V_66 , V_209 ) ;
F_65 ( & V_13 -> V_14 ) ;
}
return V_213 ;
V_221:
F_117 ( L_43
L_44 ,
V_4 -> V_4 . V_47 , V_209 -> V_216 , V_209 -> V_214 ,
F_115 ( V_209 -> V_210 ) , F_115 ( V_209 -> V_190 ) ,
F_115 ( V_209 -> V_223 ) ) ;
F_104 ( V_13 , V_4 ) ;
return - 1 ;
}
static void F_118 ( struct V_38 * V_13 , struct V_3 * V_4 )
{
struct V_6 * V_7 ;
T_5 V_231 ;
T_5 V_232 ;
V_233:
V_231 = F_59 ( V_4 , V_102 ) ;
V_232 = F_59 ( V_4 , V_234 ) ;
F_49 ( V_235 , L_45 ,
V_4 -> V_4 . V_47 , V_4 -> V_59 , V_231 , V_232 ) ;
V_7 = NULL ;
if ( ! F_55 ( & V_4 -> V_17 ) )
V_7 = F_56 ( V_4 -> V_17 . V_97 ,
struct V_6 , V_17 ) ;
if ( ( V_232 & V_87 ) && ! ( V_231 & V_87 ) ) {
if ( V_7 -> V_35 )
F_48 ( V_4 , V_7 ) ;
else
F_52 ( V_4 , V_7 ) ;
if ( V_7 -> V_37 ) {
F_51 ( V_4 , V_90 , V_87 ) ;
F_51 ( V_4 , V_88 , V_95 ) ;
}
goto V_233;
}
if ( ( V_231 & V_232 ) & V_95 ) {
F_51 ( V_4 , V_105 , V_95 ) ;
switch ( V_4 -> V_59 ) {
case V_169 :
F_51 ( V_4 , V_88 , V_96 ) ;
F_51 ( V_4 , V_90 , V_95 ) ;
V_4 -> V_59 = V_236 ;
break;
case V_229 :
F_42 ( V_13 , V_186 , ( F_99 ( V_13 , V_186 )
| V_237 ) ) ;
F_51 ( V_4 , V_90 , V_95 ) ;
V_4 -> V_59 = V_192 ;
break;
case V_98 :
if ( V_7 ) {
F_62 ( & V_7 -> V_17 ) ;
F_66 ( V_4 , V_7 , 0 ) ;
F_54 ( V_4 ) ;
}
F_51 ( V_4 , V_90 , V_95 ) ;
V_4 -> V_59 = V_192 ;
break;
case V_226 :
F_51 ( V_4 , V_90 , V_95 ) ;
V_4 -> V_59 = V_192 ;
if ( F_108 ( V_13 ) )
F_104 ( V_13 , V_4 ) ;
break;
default:
F_117 ( L_46
L_44 ,
V_4 -> V_4 . V_47 , V_4 -> V_59 ) ;
F_104 ( V_13 , V_4 ) ;
break;
}
goto V_233;
}
if ( ( V_231 & V_232 ) & V_96 ) {
switch ( V_4 -> V_59 ) {
case V_236 :
F_51 ( V_4 , V_105 , V_96 ) ;
F_51 ( V_4 , V_90 , V_96 ) ;
if ( V_7 ) {
F_62 ( & V_7 -> V_17 ) ;
F_66 ( V_4 , V_7 , 0 ) ;
}
V_4 -> V_59 = V_192 ;
break;
case V_238 :
F_58 ( V_4 ) ;
break;
default:
F_51 ( V_4 , V_105 , V_96 ) ;
F_51 ( V_4 , V_90 , V_96 ) ;
F_117 ( L_47
L_44 ,
V_4 -> V_4 . V_47 , V_4 -> V_59 ) ;
F_104 ( V_13 , V_4 ) ;
break;
}
goto V_233;
}
if ( V_231 & V_239 ) {
union {
struct V_208 V_209 ;
unsigned long V_40 [ 2 ] ;
} V_209 ;
unsigned int V_240 ;
int V_41 ;
if ( V_4 -> V_59 != V_192 ) {
int V_34 = - V_241 ;
if ( V_4 -> V_59 == V_236
|| V_4 -> V_59 == V_98 ) {
F_51 ( V_4 , V_90 , V_96 ) ;
V_34 = 0 ;
}
if ( V_7 ) {
F_62 ( & V_7 -> V_17 ) ;
F_66 ( V_4 , V_7 , V_34 ) ;
}
}
V_240 = F_60 ( V_104 , F_59 ( V_4 , V_102 ) ) ;
F_49 ( V_129 , L_48 , V_240 ) ;
if ( V_240 != sizeof( V_209 ) ) {
F_119 ( L_49
L_50 , V_240 , sizeof( V_209 ) ) ;
F_104 ( V_13 , V_4 ) ;
return;
}
F_49 ( V_242 , L_51 , V_4 -> V_85 ) ;
F_61 ( V_209 . V_40 , V_4 -> V_85 , sizeof( V_209 ) ) ;
F_51 ( V_4 , V_105 , V_239 ) ;
if ( V_209 . V_209 . V_216 & V_191 ) {
V_4 -> V_59 = V_169 ;
} else {
if ( V_209 . V_209 . V_223 != F_111 ( 0 ) )
V_4 -> V_59 = V_238 ;
else
V_4 -> V_59 = V_98 ;
}
V_41 = - 1 ;
if ( V_4 -> V_120 == 0 )
V_41 = F_114 ( V_13 , V_4 , & V_209 . V_209 ) ;
else {
F_63 ( & V_13 -> V_14 ) ;
V_41 = V_13 -> V_168 -> V_230 ( & V_13 -> V_66 , & V_209 . V_209 ) ;
F_65 ( & V_13 -> V_14 ) ;
}
F_49 ( V_195 , L_52 ,
V_209 . V_209 . V_216 , V_209 . V_209 . V_214 ,
F_115 ( V_209 . V_209 . V_223 ) , V_4 -> V_59 , V_41 ) ;
if ( V_41 < 0 ) {
F_104 ( V_13 , V_4 ) ;
}
}
}
static void F_120 ( struct V_38 * V_13 , struct V_3 * V_4 )
{
struct V_6 * V_7 ;
T_5 V_231 ;
T_5 V_232 ;
V_231 = F_59 ( V_4 , V_102 ) ;
V_232 = F_59 ( V_4 , V_234 ) ;
F_49 ( V_235 , L_53 , V_4 -> V_4 . V_47 , V_231 ) ;
while ( ( V_232 & V_87 ) && ! ( V_231 & V_87 ) ) {
F_49 ( V_195 , L_54 , V_4 -> V_4 . V_47 ) ;
if ( F_55 ( & V_4 -> V_17 ) ) {
F_121 ( & V_13 -> V_61 -> V_62 , L_55 ) ;
F_51 ( V_4 , V_90 , V_87 ) ;
return;
}
V_7 = F_56 ( V_4 -> V_17 . V_97 , struct V_6 , V_17 ) ;
if ( V_7 -> V_36 ) {
F_51 ( V_4 , V_86 ,
V_87 ) ;
F_51 ( V_4 , V_90 ,
V_87 ) ;
F_62 ( & V_7 -> V_17 ) ;
F_54 ( V_4 ) ;
F_66 ( V_4 , V_7 , 0 ) ;
} else {
if ( V_7 -> V_35 )
F_48 ( V_4 , V_7 ) ;
else
F_52 ( V_4 , V_7 ) ;
if ( V_7 -> V_37 ) {
F_62 ( & V_7 -> V_17 ) ;
F_54 ( V_4 ) ;
F_66 ( V_4 , V_7 , 0 ) ;
}
}
V_231 = F_59 ( V_4 , V_102 ) ;
V_232 = F_59 ( V_4 , V_234 ) ;
}
if ( ( V_231 & V_232 ) & V_96 ) {
F_49 ( V_195 , L_56 , V_4 -> V_4 . V_47 ) ;
F_58 ( V_4 ) ;
}
}
static void F_122 ( struct V_38 * V_13 , struct V_3 * V_4 )
{
struct V_6 * V_7 ;
T_5 V_34 , V_243 , V_244 ;
V_34 = F_81 ( V_4 , V_156 ) ;
V_243 = F_81 ( V_4 , V_93 ) ;
#ifdef F_93
V_4 -> V_56 = V_34 ;
#endif
V_244 = V_34 & V_243 ;
F_49 ( V_235 | V_161 , L_57 , V_34 , V_243 ) ;
if ( V_34 & V_163 ) {
F_31 ( & V_13 -> V_61 -> V_62 ,
L_58 ) ;
F_31 ( & V_13 -> V_61 -> V_62 ,
L_59 ,
V_34 , V_244 , V_243 ) ;
}
if ( F_55 ( & V_4 -> V_17 ) )
return;
if ( V_244 & ( V_245 | V_246 ) ) {
V_7 = F_56 ( V_4 -> V_17 . V_97 , struct V_6 , V_17 ) ;
F_89 ( V_4 , V_7 , V_34 ) ;
F_62 ( & V_7 -> V_17 ) ;
F_54 ( V_4 ) ;
F_66 ( V_4 , V_7 , 0 ) ;
}
}
static T_9 F_123 ( int V_247 , void * V_248 )
{
struct V_38 * V_13 = V_248 ;
T_5 V_34 , V_249 ;
T_5 V_250 ;
T_5 V_251 ;
F_65 ( & V_13 -> V_14 ) ;
V_249 = F_40 ( V_13 ) ;
V_34 = F_99 ( V_13 , V_252 ) & V_249 ;
F_49 ( V_235 , L_60 , V_34 ) ;
if ( V_34 & V_253 ) {
F_46 ( V_13 , 0 ) ;
F_42 ( V_13 , V_254 , V_253 ) ;
F_41 ( V_13 , V_249 | V_255 ) ;
V_13 -> V_80 = true ;
F_49 ( V_195 , L_61 ) ;
if ( V_13 -> V_66 . V_154 != V_155
&& V_13 -> V_168 && V_13 -> V_168 -> V_256 ) {
F_63 ( & V_13 -> V_14 ) ;
V_13 -> V_168 -> V_256 ( & V_13 -> V_66 ) ;
F_65 ( & V_13 -> V_14 ) ;
}
}
if ( V_34 & V_255 ) {
F_46 ( V_13 , 1 ) ;
F_42 ( V_13 , V_254 , V_255 ) ;
F_41 ( V_13 , V_249 & ~ V_255 ) ;
F_49 ( V_195 , L_62 ) ;
}
if ( V_34 & V_257 ) {
F_42 ( V_13 , V_254 , V_257 ) ;
F_47 ( V_13 ) ;
F_49 ( V_195 , L_63 ) ;
if ( V_13 -> V_66 . V_154 != V_155
&& V_13 -> V_168 && V_13 -> V_168 -> V_258 ) {
F_63 ( & V_13 -> V_14 ) ;
V_13 -> V_168 -> V_258 ( & V_13 -> V_66 ) ;
F_65 ( & V_13 -> V_14 ) ;
}
}
V_250 = F_60 ( V_150 , V_34 ) ;
if ( V_250 ) {
int V_39 ;
for ( V_39 = 1 ; V_39 <= V_259 ; V_39 ++ )
if ( V_250 & ( 1 << V_39 ) )
F_122 ( V_13 , & V_13 -> V_3 [ V_39 ] ) ;
}
V_251 = F_60 ( V_149 , V_34 ) ;
if ( V_251 ) {
int V_39 ;
for ( V_39 = 0 ; V_39 < V_13 -> V_260 ; V_39 ++ )
if ( V_251 & ( 1 << V_39 ) ) {
if ( F_29 ( & V_13 -> V_3 [ V_39 ] ) )
F_118 ( V_13 , & V_13 -> V_3 [ V_39 ] ) ;
else
F_120 ( V_13 , & V_13 -> V_3 [ V_39 ] ) ;
}
}
if ( V_34 & V_261 ) {
struct V_3 * V_72 ;
F_42 ( V_13 , V_254 , V_261 ) ;
F_47 ( V_13 ) ;
F_102 ( V_13 ) ;
if ( V_13 -> V_66 . V_154 != V_155 && V_13 -> V_168 ) {
V_13 -> V_66 . V_154 = V_155 ;
F_63 ( & V_13 -> V_14 ) ;
F_124 ( & V_13 -> V_66 , V_13 -> V_168 ) ;
F_65 ( & V_13 -> V_14 ) ;
}
if ( V_34 & V_262 )
V_13 -> V_66 . V_154 = V_263 ;
else
V_13 -> V_66 . V_154 = V_264 ;
F_49 ( V_195 , L_64 ,
F_125 ( V_13 -> V_66 . V_154 ) ) ;
V_72 = & V_13 -> V_3 [ 0 ] ;
V_72 -> V_4 . V_114 = & V_265 ;
V_72 -> V_59 = V_192 ;
F_51 ( V_72 , V_147 ,
( F_72 ( V_127 , V_266 )
| F_72 ( V_132 , V_133 )
| F_72 ( V_134 , V_135 ) ) ) ;
F_51 ( V_72 , V_88 ,
V_148 | V_239 ) ;
F_41 ( V_13 , V_249 | F_72 ( V_149 , 1 ) |
V_253 | V_257 ) ;
if ( ! ( F_59 ( V_72 , V_147 ) & V_206 ) )
F_126 ( & V_13 -> V_61 -> V_62 ,
L_65 ) ;
}
F_63 ( & V_13 -> V_14 ) ;
return V_267 ;
}
static int F_127 ( struct V_38 * V_13 )
{
int V_41 ;
if ( V_13 -> V_268 )
return 0 ;
V_41 = F_128 ( V_13 -> V_269 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_128 ( V_13 -> V_270 ) ;
if ( V_41 ) {
F_129 ( V_13 -> V_269 ) ;
return V_41 ;
}
V_13 -> V_268 = true ;
return 0 ;
}
static void F_130 ( struct V_38 * V_13 )
{
if ( ! V_13 -> V_268 )
return;
F_129 ( V_13 -> V_270 ) ;
F_129 ( V_13 -> V_269 ) ;
V_13 -> V_268 = false ;
}
static int F_131 ( struct V_38 * V_13 )
{
unsigned long V_115 ;
int V_41 ;
V_41 = F_127 ( V_13 ) ;
if ( V_41 )
return V_41 ;
F_76 ( & V_13 -> V_14 , V_115 ) ;
F_46 ( V_13 , 1 ) ;
F_42 ( V_13 , V_186 , V_271 ) ;
F_41 ( V_13 , V_261 ) ;
F_77 ( & V_13 -> V_14 , V_115 ) ;
return 0 ;
}
static void F_132 ( struct V_38 * V_13 )
{
unsigned long V_115 ;
F_76 ( & V_13 -> V_14 , V_115 ) ;
V_13 -> V_66 . V_154 = V_155 ;
F_102 ( V_13 ) ;
F_46 ( V_13 , 0 ) ;
F_42 ( V_13 , V_186 , V_272 ) ;
F_77 ( & V_13 -> V_14 , V_115 ) ;
F_130 ( V_13 ) ;
}
static T_9 F_133 ( int V_247 , void * V_248 )
{
struct V_38 * V_13 = V_248 ;
int V_273 ;
F_91 ( 10 ) ;
F_14 ( & V_13 -> V_274 ) ;
V_273 = F_43 ( V_13 ) ;
if ( V_273 != V_13 -> V_275 ) {
if ( V_273 ) {
F_131 ( V_13 ) ;
} else {
F_132 ( V_13 ) ;
if ( V_13 -> V_168 -> V_276 )
V_13 -> V_168 -> V_276 ( & V_13 -> V_66 ) ;
}
V_13 -> V_275 = V_273 ;
}
F_18 ( & V_13 -> V_274 ) ;
return V_267 ;
}
static int F_134 ( struct V_181 * V_66 ,
struct V_277 * V_168 )
{
int V_41 ;
struct V_38 * V_13 = F_135 ( V_66 , struct V_38 , V_66 ) ;
unsigned long V_115 ;
F_76 ( & V_13 -> V_14 , V_115 ) ;
V_13 -> V_184 = 1 << V_189 ;
V_13 -> V_168 = V_168 ;
F_77 ( & V_13 -> V_14 , V_115 ) ;
F_14 ( & V_13 -> V_274 ) ;
if ( F_44 ( V_13 -> V_76 ) )
F_136 ( F_137 ( V_13 -> V_76 ) ) ;
V_13 -> V_275 = F_43 ( V_13 ) ;
if ( V_13 -> V_275 ) {
V_41 = F_131 ( V_13 ) ;
if ( V_41 )
goto V_278;
}
F_18 ( & V_13 -> V_274 ) ;
return 0 ;
V_278:
if ( F_44 ( V_13 -> V_76 ) )
F_138 ( F_137 ( V_13 -> V_76 ) ) ;
F_18 ( & V_13 -> V_274 ) ;
F_76 ( & V_13 -> V_14 , V_115 ) ;
V_13 -> V_184 &= ~ ( 1 << V_189 ) ;
V_13 -> V_168 = NULL ;
F_77 ( & V_13 -> V_14 , V_115 ) ;
return V_41 ;
}
static int F_139 ( struct V_181 * V_66 )
{
struct V_38 * V_13 = F_135 ( V_66 , struct V_38 , V_66 ) ;
if ( F_44 ( V_13 -> V_76 ) )
F_138 ( F_137 ( V_13 -> V_76 ) ) ;
F_132 ( V_13 ) ;
V_13 -> V_168 = NULL ;
return 0 ;
}
static void F_140 ( struct V_38 * V_13 , int V_78 )
{
unsigned int V_279 = F_141 ( V_280 ) ;
if ( V_78 )
F_142 ( V_280 , V_279 | V_281 ) ;
else
F_142 ( V_280 , V_279 & ~ ( V_281 ) ) ;
}
static void F_143 ( struct V_38 * V_13 )
{
unsigned int V_279 = F_141 ( V_280 ) ;
F_142 ( V_280 , V_279 & ~ ( V_281 ) ) ;
F_142 ( V_280 , V_279 | V_281 ) ;
}
static struct V_3 * F_144 ( struct V_282 * V_61 ,
struct V_38 * V_13 )
{
T_5 V_74 ;
const char * V_47 ;
enum V_283 V_115 ;
struct V_284 * V_285 = V_61 -> V_62 . V_286 ;
const struct V_287 * V_288 ;
struct V_284 * V_289 ;
int V_39 , V_41 ;
struct V_3 * V_290 , * V_4 ;
V_288 = F_145 ( V_291 , V_285 ) ;
if ( ! V_288 )
return F_146 ( - V_125 ) ;
V_13 -> V_79 = V_288 -> V_40 ;
V_13 -> V_260 = 0 ;
V_13 -> V_76 = F_147 ( V_285 , L_66 , 0 ,
& V_115 ) ;
V_13 -> V_77 = ( V_115 & V_292 ) ? 1 : 0 ;
V_289 = NULL ;
while ( ( V_289 = F_148 ( V_285 , V_289 ) ) )
V_13 -> V_260 ++ ;
V_290 = F_149 ( & V_61 -> V_62 , sizeof( struct V_3 ) * V_13 -> V_260 ,
V_11 ) ;
if ( ! V_290 )
return F_146 ( - V_12 ) ;
V_13 -> V_66 . V_72 = & V_290 [ 0 ] . V_4 ;
F_3 ( & V_290 [ 0 ] . V_4 . V_293 ) ;
V_289 = NULL ;
V_39 = 0 ;
while ( ( V_289 = F_148 ( V_285 , V_289 ) ) ) {
V_4 = & V_290 [ V_39 ] ;
V_41 = F_150 ( V_289 , L_67 , & V_74 ) ;
if ( V_41 ) {
F_31 ( & V_61 -> V_62 , L_68 , V_41 ) ;
goto V_278;
}
V_4 -> V_120 = V_74 ;
V_41 = F_150 ( V_289 , L_69 , & V_74 ) ;
if ( V_41 ) {
F_31 ( & V_61 -> V_62 , L_70 , V_41 ) ;
goto V_278;
}
V_4 -> V_123 = V_74 ;
V_41 = F_150 ( V_289 , L_71 , & V_74 ) ;
if ( V_41 ) {
F_31 ( & V_61 -> V_62 , L_72 , V_41 ) ;
goto V_278;
}
V_4 -> V_139 = V_74 ;
V_4 -> V_54 = F_151 ( V_289 , L_73 ) ;
V_4 -> V_137 = F_151 ( V_289 , L_74 ) ;
V_41 = F_152 ( V_289 , L_75 , & V_47 ) ;
if ( V_41 ) {
F_31 ( & V_61 -> V_62 , L_76 , V_41 ) ;
goto V_278;
}
V_4 -> V_4 . V_47 = V_47 ;
V_4 -> V_294 = V_13 -> V_44 + F_153 ( V_39 ) ;
V_4 -> V_295 = V_13 -> V_44 + F_154 ( V_39 ) ;
V_4 -> V_85 = V_13 -> V_85 + F_155 ( V_39 ) ;
V_4 -> V_4 . V_296 = & V_297 ;
F_156 ( & V_4 -> V_4 , V_4 -> V_123 ) ;
V_4 -> V_13 = V_13 ;
F_3 ( & V_4 -> V_17 ) ;
if ( V_4 -> V_120 == 0 ) {
V_4 -> V_4 . V_298 . V_299 = true ;
} else {
V_4 -> V_4 . V_298 . V_300 = V_4 -> V_137 ;
V_4 -> V_4 . V_298 . V_301 = true ;
V_4 -> V_4 . V_298 . V_302 = true ;
}
V_4 -> V_4 . V_298 . V_303 = true ;
V_4 -> V_4 . V_298 . V_304 = true ;
if ( V_39 )
F_7 ( & V_4 -> V_4 . V_293 , & V_13 -> V_66 . V_293 ) ;
V_39 ++ ;
}
if ( V_39 == 0 ) {
F_31 ( & V_61 -> V_62 , L_77 ) ;
V_41 = - V_125 ;
goto V_278;
}
return V_290 ;
V_278:
return F_146 ( V_41 ) ;
}
static struct V_3 * F_144 ( struct V_282 * V_61 ,
struct V_38 * V_13 )
{
return F_146 ( - V_305 ) ;
}
static struct V_3 * F_157 ( struct V_282 * V_61 ,
struct V_38 * V_13 )
{
struct V_306 * V_307 = F_158 ( & V_61 -> V_62 ) ;
struct V_3 * V_290 ;
int V_39 ;
if ( ! V_307 )
return F_146 ( - V_308 ) ;
V_290 = F_149 ( & V_61 -> V_62 , sizeof( struct V_3 ) * V_307 -> V_260 ,
V_11 ) ;
if ( ! V_290 )
return F_146 ( - V_12 ) ;
V_13 -> V_66 . V_72 = & V_290 [ 0 ] . V_4 ;
V_13 -> V_76 = V_307 -> V_76 ;
V_13 -> V_77 = V_307 -> V_77 ;
V_13 -> V_260 = V_307 -> V_260 ;
F_3 ( & V_290 [ 0 ] . V_4 . V_293 ) ;
for ( V_39 = 0 ; V_39 < V_307 -> V_260 ; V_39 ++ ) {
struct V_3 * V_4 = & V_290 [ V_39 ] ;
V_4 -> V_294 = V_13 -> V_44 + F_153 ( V_39 ) ;
V_4 -> V_295 = V_13 -> V_44 + F_154 ( V_39 ) ;
V_4 -> V_85 = V_13 -> V_85 + F_155 ( V_39 ) ;
V_4 -> V_4 . V_296 = & V_297 ;
V_4 -> V_4 . V_47 = V_307 -> V_4 [ V_39 ] . V_47 ;
V_4 -> V_123 = V_307 -> V_4 [ V_39 ] . V_123 ;
F_156 ( & V_4 -> V_4 , V_4 -> V_123 ) ;
V_4 -> V_13 = V_13 ;
F_3 ( & V_4 -> V_17 ) ;
V_4 -> V_139 = V_307 -> V_4 [ V_39 ] . V_139 ;
V_4 -> V_120 = V_307 -> V_4 [ V_39 ] . V_120 ;
V_4 -> V_54 = V_307 -> V_4 [ V_39 ] . V_54 ;
V_4 -> V_137 = V_307 -> V_4 [ V_39 ] . V_137 ;
if ( V_39 == 0 ) {
V_4 -> V_4 . V_298 . V_299 = true ;
} else {
V_4 -> V_4 . V_298 . V_300 = V_4 -> V_137 ;
V_4 -> V_4 . V_298 . V_301 = true ;
V_4 -> V_4 . V_298 . V_302 = true ;
}
V_4 -> V_4 . V_298 . V_303 = true ;
V_4 -> V_4 . V_298 . V_304 = true ;
if ( V_39 )
F_7 ( & V_4 -> V_4 . V_293 , & V_13 -> V_66 . V_293 ) ;
}
return V_290 ;
}
static int F_159 ( struct V_282 * V_61 )
{
struct V_64 * V_44 , * V_85 ;
struct V_309 * V_269 , * V_270 ;
struct V_38 * V_13 ;
int V_247 , V_41 , V_39 ;
V_13 = F_149 ( & V_61 -> V_62 , sizeof( * V_13 ) , V_11 ) ;
if ( ! V_13 )
return - V_12 ;
V_13 -> V_66 = V_310 ;
F_3 ( & V_13 -> V_66 . V_293 ) ;
V_44 = F_35 ( V_61 , V_67 , V_68 ) ;
V_85 = F_35 ( V_61 , V_67 , V_311 ) ;
if ( ! V_44 || ! V_85 )
return - V_308 ;
V_247 = F_160 ( V_61 , 0 ) ;
if ( V_247 < 0 )
return V_247 ;
V_269 = F_161 ( & V_61 -> V_62 , L_78 ) ;
if ( F_34 ( V_269 ) )
return F_162 ( V_269 ) ;
V_270 = F_161 ( & V_61 -> V_62 , L_79 ) ;
if ( F_34 ( V_270 ) )
return F_162 ( V_270 ) ;
F_163 ( & V_13 -> V_14 ) ;
F_164 ( & V_13 -> V_274 ) ;
V_13 -> V_61 = V_61 ;
V_13 -> V_269 = V_269 ;
V_13 -> V_270 = V_270 ;
V_13 -> V_76 = - V_176 ;
V_41 = - V_12 ;
V_13 -> V_44 = F_165 ( & V_61 -> V_62 , V_44 -> V_312 , F_37 ( V_44 ) ) ;
if ( ! V_13 -> V_44 ) {
F_31 ( & V_61 -> V_62 , L_80 ) ;
return V_41 ;
}
F_109 ( & V_61 -> V_62 , L_81 ,
( unsigned long ) V_44 -> V_312 , V_13 -> V_44 ) ;
V_13 -> V_85 = F_165 ( & V_61 -> V_62 , V_85 -> V_312 , F_37 ( V_85 ) ) ;
if ( ! V_13 -> V_85 ) {
F_31 ( & V_61 -> V_62 , L_82 ) ;
return V_41 ;
}
F_109 ( & V_61 -> V_62 , L_83 ,
( unsigned long ) V_85 -> V_312 , V_13 -> V_85 ) ;
F_166 ( V_61 , V_13 ) ;
V_41 = F_128 ( V_269 ) ;
if ( V_41 ) {
F_31 ( & V_61 -> V_62 , L_84 ) ;
return V_41 ;
}
F_42 ( V_13 , V_186 , V_272 ) ;
F_129 ( V_269 ) ;
if ( V_61 -> V_62 . V_286 )
V_13 -> V_3 = F_144 ( V_61 , V_13 ) ;
else
V_13 -> V_3 = F_157 ( V_61 , V_13 ) ;
F_46 ( V_13 , 0 ) ;
if ( F_34 ( V_13 -> V_3 ) )
return F_162 ( V_13 -> V_3 ) ;
V_41 = F_167 ( & V_61 -> V_62 , V_247 , F_123 , 0 ,
L_85 , V_13 ) ;
if ( V_41 ) {
F_31 ( & V_61 -> V_62 , L_86 ,
V_247 , V_41 ) ;
return V_41 ;
}
V_13 -> V_247 = V_247 ;
if ( F_44 ( V_13 -> V_76 ) ) {
if ( ! F_168 ( & V_61 -> V_62 , V_13 -> V_76 , L_85 ) ) {
F_169 ( F_137 ( V_13 -> V_76 ) ,
V_313 ) ;
V_41 = F_170 ( & V_61 -> V_62 ,
F_137 ( V_13 -> V_76 ) , NULL ,
F_133 , V_314 ,
L_85 , V_13 ) ;
if ( V_41 ) {
V_13 -> V_76 = - V_176 ;
F_121 ( & V_13 -> V_61 -> V_62 ,
L_87
L_88 ) ;
}
} else {
V_13 -> V_76 = - V_125 ;
}
}
V_41 = F_171 ( & V_61 -> V_62 , & V_13 -> V_66 ) ;
if ( V_41 )
return V_41 ;
F_172 ( & V_61 -> V_62 , 1 ) ;
F_33 ( V_13 ) ;
for ( V_39 = 1 ; V_39 < V_13 -> V_260 ; V_39 ++ )
F_25 ( V_13 , & V_13 -> V_3 [ V_39 ] ) ;
return 0 ;
}
static int F_173 ( struct V_282 * V_61 )
{
struct V_38 * V_13 ;
int V_39 ;
V_13 = F_174 ( V_61 ) ;
F_172 ( & V_61 -> V_62 , 0 ) ;
F_175 ( & V_13 -> V_66 ) ;
for ( V_39 = 1 ; V_39 < V_13 -> V_260 ; V_39 ++ )
F_32 ( & V_13 -> V_3 [ V_39 ] ) ;
F_39 ( V_13 ) ;
return 0 ;
}
static int F_176 ( struct V_198 * V_62 )
{
struct V_38 * V_13 = F_177 ( V_62 ) ;
if ( ! V_13 -> V_168 )
return 0 ;
F_14 ( & V_13 -> V_274 ) ;
if ( ! F_178 ( V_62 ) ) {
F_132 ( V_13 ) ;
goto V_43;
}
if ( F_44 ( V_13 -> V_76 ) ) {
F_132 ( V_13 ) ;
F_179 ( F_137 ( V_13 -> V_76 ) ) ;
}
V_43:
F_18 ( & V_13 -> V_274 ) ;
return 0 ;
}
static int F_180 ( struct V_198 * V_62 )
{
struct V_38 * V_13 = F_177 ( V_62 ) ;
if ( ! V_13 -> V_168 )
return 0 ;
if ( F_178 ( V_62 ) && F_44 ( V_13 -> V_76 ) )
F_181 ( F_137 ( V_13 -> V_76 ) ) ;
F_14 ( & V_13 -> V_274 ) ;
V_13 -> V_275 = F_43 ( V_13 ) ;
if ( V_13 -> V_275 )
F_131 ( V_13 ) ;
F_18 ( & V_13 -> V_274 ) ;
return 0 ;
}
