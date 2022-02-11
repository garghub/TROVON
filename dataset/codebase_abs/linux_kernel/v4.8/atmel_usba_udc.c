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
F_14 ( F_15 ( V_2 ) ) ;
F_9 (req, tmp_req, queue, queue) {
V_23 = snprintf ( V_26 , sizeof( V_26 ) ,
L_1 ,
V_7 -> V_7 . V_19 , V_7 -> V_7 . V_29 ,
V_7 -> V_7 . V_30 ? 'i' : 'I' ,
V_7 -> V_7 . V_31 ? 'Z' : 'z' ,
V_7 -> V_7 . V_32 ? 's' : 'S' ,
V_7 -> V_7 . V_33 ,
V_7 -> V_34 ? 'F' : 'f' ,
V_7 -> V_35 ? 'D' : 'd' ,
V_7 -> V_36 ? 'L' : 'l' ) ;
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
F_18 ( F_15 ( V_2 ) ) ;
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
struct V_37 * V_13 ;
unsigned int V_38 ;
T_5 * V_39 ;
int V_40 = - V_12 ;
F_14 ( V_1 ) ;
V_13 = V_1 -> V_5 ;
V_39 = F_2 ( V_1 -> V_41 , V_11 ) ;
if ( ! V_39 )
goto V_42;
F_4 ( & V_13 -> V_14 ) ;
for ( V_38 = 0 ; V_38 < V_1 -> V_41 / 4 ; V_38 ++ )
V_39 [ V_38 ] = F_21 ( V_13 -> V_43 + V_38 * 4 ) ;
F_8 ( & V_13 -> V_14 ) ;
V_2 -> V_18 = V_39 ;
V_40 = 0 ;
V_42:
F_18 ( V_1 ) ;
return V_40 ;
}
static T_1 F_22 ( struct V_2 * V_2 , char T_2 * V_19 ,
T_3 V_20 , T_4 * V_21 )
{
struct V_1 * V_1 = F_15 ( V_2 ) ;
int V_40 ;
F_14 ( V_1 ) ;
V_40 = F_23 ( V_19 , V_20 , V_21 ,
V_2 -> V_18 ,
F_15 ( V_2 ) -> V_41 ) ;
F_18 ( V_1 ) ;
return V_40 ;
}
static int F_24 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
F_11 ( V_2 -> V_18 ) ;
return 0 ;
}
static void F_25 ( struct V_37 * V_13 ,
struct V_3 * V_4 )
{
struct V_44 * V_45 ;
V_45 = F_26 ( V_4 -> V_4 . V_46 , V_13 -> V_47 ) ;
if ( ! V_45 )
goto V_48;
V_4 -> V_49 = V_45 ;
V_4 -> V_50 = F_27 ( L_2 , 0400 , V_45 ,
V_4 , & V_51 ) ;
if ( ! V_4 -> V_50 )
goto V_52;
if ( V_4 -> V_53 ) {
V_4 -> V_54
= F_28 ( L_3 , 0400 , V_45 ,
& V_4 -> V_55 ) ;
if ( ! V_4 -> V_54 )
goto V_56;
}
if ( F_29 ( V_4 ) ) {
V_4 -> V_57
= F_28 ( L_4 , 0400 , V_45 ,
& V_4 -> V_58 ) ;
if ( ! V_4 -> V_57 )
goto V_59;
}
return;
V_59:
if ( V_4 -> V_53 )
F_30 ( V_4 -> V_54 ) ;
V_56:
F_30 ( V_4 -> V_50 ) ;
V_52:
F_30 ( V_45 ) ;
V_48:
F_31 ( & V_4 -> V_13 -> V_60 -> V_61 ,
L_5 , V_4 -> V_4 . V_46 ) ;
}
static void F_32 ( struct V_3 * V_4 )
{
F_30 ( V_4 -> V_50 ) ;
F_30 ( V_4 -> V_54 ) ;
F_30 ( V_4 -> V_57 ) ;
F_30 ( V_4 -> V_49 ) ;
V_4 -> V_54 = NULL ;
V_4 -> V_49 = NULL ;
}
static void F_33 ( struct V_37 * V_13 )
{
struct V_44 * V_62 , * V_43 ;
struct V_63 * V_64 ;
V_62 = F_26 ( V_13 -> V_65 . V_46 , NULL ) ;
if ( F_34 ( V_62 ) || ! V_62 )
goto V_48;
V_13 -> V_47 = V_62 ;
V_64 = F_35 ( V_13 -> V_60 , V_66 ,
V_67 ) ;
if ( V_64 ) {
V_43 = F_36 ( L_6 , 0400 , V_62 , V_13 ,
& V_68 ,
F_37 ( V_64 ) ) ;
if ( ! V_43 )
goto V_69;
V_13 -> V_70 = V_43 ;
}
F_25 ( V_13 , F_38 ( V_13 -> V_65 . V_71 ) ) ;
return;
V_69:
F_30 ( V_62 ) ;
V_48:
V_13 -> V_47 = NULL ;
F_31 ( & V_13 -> V_60 -> V_61 , L_7 ) ;
}
static void F_39 ( struct V_37 * V_13 )
{
F_32 ( F_38 ( V_13 -> V_65 . V_71 ) ) ;
F_30 ( V_13 -> V_70 ) ;
F_30 ( V_13 -> V_47 ) ;
V_13 -> V_70 = NULL ;
V_13 -> V_47 = NULL ;
}
static inline void F_25 ( struct V_37 * V_13 ,
struct V_3 * V_4 )
{
}
static inline void F_32 ( struct V_3 * V_4 )
{
}
static inline void F_33 ( struct V_37 * V_13 )
{
}
static inline void F_39 ( struct V_37 * V_13 )
{
}
static inline T_5 F_40 ( struct V_37 * V_13 )
{
return V_13 -> V_72 ;
}
static inline void F_41 ( struct V_37 * V_13 , T_5 V_73 )
{
F_42 ( V_13 , V_74 , V_73 ) ;
V_13 -> V_72 = V_73 ;
}
static int F_43 ( struct V_37 * V_13 )
{
if ( F_44 ( V_13 -> V_75 ) )
return F_45 ( V_13 -> V_75 ) ^ V_13 -> V_76 ;
return 1 ;
}
static void F_46 ( struct V_37 * V_13 , int V_77 )
{
if ( V_13 -> V_78 && V_13 -> V_78 -> F_46 )
V_13 -> V_78 -> F_46 ( V_13 , V_77 ) ;
}
static void F_47 ( struct V_37 * V_13 )
{
if ( ! V_13 -> V_79 )
return;
if ( V_13 -> V_78 && V_13 -> V_78 -> V_80 )
V_13 -> V_78 -> V_80 ( V_13 ) ;
V_13 -> V_79 = false ;
}
static void F_48 ( struct V_3 * V_4 , struct V_6 * V_7 )
{
unsigned int V_81 ;
V_81 = V_7 -> V_7 . V_29 - V_7 -> V_7 . V_25 ;
V_7 -> V_36 = 1 ;
if ( V_81 > V_4 -> V_4 . V_82 ) {
V_81 = V_4 -> V_4 . V_82 ;
V_7 -> V_36 = 0 ;
} else if ( V_81 == V_4 -> V_4 . V_82 && V_7 -> V_7 . V_31 )
V_7 -> V_36 = 0 ;
F_49 ( V_83 , L_8 ,
V_4 -> V_4 . V_46 , V_7 , V_81 ,
V_7 -> V_36 ? L_9 : L_10 ) ;
F_50 ( V_4 -> V_84 , V_7 -> V_7 . V_19 + V_7 -> V_7 . V_25 , V_81 ) ;
F_51 ( V_4 , V_85 , V_86 ) ;
V_7 -> V_7 . V_25 += V_81 ;
}
static void F_52 ( struct V_3 * V_4 , struct V_6 * V_7 )
{
F_49 ( V_83 , L_11 ,
V_4 -> V_4 . V_46 , V_7 , V_7 -> V_7 . V_29 ) ;
V_7 -> V_7 . V_25 = 0 ;
V_7 -> V_34 = 1 ;
if ( V_7 -> V_35 ) {
if ( V_7 -> V_7 . V_29 == 0 ) {
F_51 ( V_4 , V_87 , V_86 ) ;
return;
}
if ( V_7 -> V_7 . V_31 )
F_51 ( V_4 , V_87 , V_88 ) ;
else
F_51 ( V_4 , V_89 , V_88 ) ;
F_53 ( V_4 , V_90 , V_7 -> V_7 . V_91 ) ;
F_53 ( V_4 , V_92 , V_7 -> V_93 ) ;
} else {
F_48 ( V_4 , V_7 ) ;
if ( V_7 -> V_36 ) {
F_51 ( V_4 , V_89 , V_86 ) ;
F_51 ( V_4 , V_87 , V_94 ) ;
} else {
F_51 ( V_4 , V_89 , V_94 ) ;
F_51 ( V_4 , V_87 , V_86 ) ;
}
}
}
static void F_54 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
if ( F_55 ( & V_4 -> V_17 ) ) {
F_51 ( V_4 , V_89 , V_86 | V_95 ) ;
return;
}
V_7 = F_56 ( V_4 -> V_17 . V_96 , struct V_6 , V_17 ) ;
if ( ! V_7 -> V_34 )
F_52 ( V_4 , V_7 ) ;
}
static void F_57 ( struct V_37 * V_13 , struct V_3 * V_4 )
{
V_4 -> V_58 = V_97 ;
F_51 ( V_4 , V_85 , V_86 ) ;
F_51 ( V_4 , V_87 , V_94 ) ;
}
static void F_58 ( struct V_3 * V_4 )
{
struct V_37 * V_13 = V_4 -> V_13 ;
struct V_6 * V_7 ;
unsigned long V_33 ;
unsigned int V_98 , V_99 ;
int V_100 = 0 ;
V_33 = F_59 ( V_4 , V_101 ) ;
V_99 = F_60 ( V_102 , V_33 ) ;
F_49 ( V_83 , L_12 , V_99 ) ;
while ( V_99 > 0 ) {
if ( F_55 ( & V_4 -> V_17 ) ) {
F_51 ( V_4 , V_89 , V_95 ) ;
break;
}
V_7 = F_56 ( V_4 -> V_17 . V_96 ,
struct V_6 , V_17 ) ;
V_98 = F_60 ( V_103 , V_33 ) ;
if ( V_33 & ( 1 << 31 ) )
V_100 = 1 ;
if ( V_7 -> V_7 . V_25 + V_98 >= V_7 -> V_7 . V_29 ) {
V_100 = 1 ;
V_98 = V_7 -> V_7 . V_29 - V_7 -> V_7 . V_25 ;
}
F_61 ( V_7 -> V_7 . V_19 + V_7 -> V_7 . V_25 ,
V_4 -> V_84 , V_98 ) ;
V_7 -> V_7 . V_25 += V_98 ;
F_51 ( V_4 , V_104 , V_95 ) ;
if ( V_100 ) {
F_49 ( V_83 , L_13 , V_4 -> V_4 . V_46 ) ;
V_7 -> V_7 . V_33 = 0 ;
F_62 ( & V_7 -> V_17 ) ;
F_51 ( V_4 , V_89 , V_95 ) ;
F_63 ( & V_13 -> V_14 ) ;
F_64 ( & V_4 -> V_4 , & V_7 -> V_7 ) ;
F_65 ( & V_13 -> V_14 ) ;
}
V_33 = F_59 ( V_4 , V_101 ) ;
V_99 = F_60 ( V_102 , V_33 ) ;
if ( V_100 && F_29 ( V_4 ) ) {
F_57 ( V_13 , V_4 ) ;
break;
}
}
}
static void
F_66 ( struct V_3 * V_4 , struct V_6 * V_7 , int V_33 )
{
struct V_37 * V_13 = V_4 -> V_13 ;
F_67 ( ! F_55 ( & V_7 -> V_17 ) ) ;
if ( V_7 -> V_7 . V_33 == - V_105 )
V_7 -> V_7 . V_33 = V_33 ;
if ( V_7 -> V_35 )
F_68 ( & V_13 -> V_65 , & V_7 -> V_7 , V_4 -> V_106 ) ;
F_49 ( V_107 | V_108 ,
L_14 ,
V_4 -> V_4 . V_46 , V_7 , V_7 -> V_7 . V_33 , V_7 -> V_7 . V_25 ) ;
F_63 ( & V_13 -> V_14 ) ;
F_64 ( & V_4 -> V_4 , & V_7 -> V_7 ) ;
F_65 ( & V_13 -> V_14 ) ;
}
static void
F_69 ( struct V_3 * V_4 , struct V_9 * V_109 , int V_33 )
{
struct V_6 * V_7 , * V_22 ;
F_9 (req, tmp_req, list, queue) {
F_62 ( & V_7 -> V_17 ) ;
F_66 ( V_4 , V_7 , V_33 ) ;
}
}
static int
F_70 ( struct V_110 * V_111 , const struct V_112 * V_113 )
{
struct V_3 * V_4 = F_38 ( V_111 ) ;
struct V_37 * V_13 = V_4 -> V_13 ;
unsigned long V_114 , V_115 , V_82 ;
unsigned int V_116 ;
F_49 ( V_107 , L_15 , V_4 -> V_4 . V_46 , V_113 ) ;
V_82 = F_71 ( V_113 ) & 0x7ff ;
if ( ( ( V_113 -> V_117 & V_118 ) != V_4 -> V_119 )
|| V_4 -> V_119 == 0
|| V_113 -> V_120 != V_121
|| V_82 == 0
|| V_82 > V_4 -> V_122 ) {
F_49 ( V_123 , L_16 ) ;
return - V_124 ;
}
V_4 -> V_125 = 0 ;
V_4 -> V_106 = 0 ;
if ( V_82 <= 8 )
V_115 = F_72 ( V_126 , V_127 ) ;
else
V_115 = F_72 ( V_126 , F_73 ( V_82 - 1 ) - 3 ) ;
F_49 ( V_128 , L_17 ,
V_4 -> V_4 . V_46 , V_115 , V_82 ) ;
if ( F_74 ( V_113 ) ) {
V_4 -> V_106 = 1 ;
V_115 |= V_129 ;
}
switch ( F_75 ( V_113 ) ) {
case V_130 :
V_115 |= F_72 ( V_131 , V_132 ) ;
V_115 |= F_72 ( V_133 , V_134 ) ;
break;
case V_135 :
if ( ! V_4 -> V_136 ) {
F_49 ( V_123 , L_18 ,
V_4 -> V_4 . V_46 ) ;
return - V_124 ;
}
V_116 = ( ( F_71 ( V_113 ) >> 11 ) & 3 ) + 1 ;
if ( V_116 > 3 )
return - V_124 ;
V_4 -> V_125 = 1 ;
V_115 |= F_72 ( V_131 , V_137 ) ;
if ( V_116 > 1 && V_4 -> V_138 == 3 )
V_115 |= F_72 ( V_133 , V_139 ) ;
else
V_115 |= F_72 ( V_133 , V_140 ) ;
V_115 |= F_72 ( V_141 , V_116 ) ;
break;
case V_142 :
V_115 |= F_72 ( V_131 , V_143 ) ;
V_115 |= F_72 ( V_133 , V_140 ) ;
break;
case V_144 :
V_115 |= F_72 ( V_131 , V_145 ) ;
V_115 |= F_72 ( V_133 , V_140 ) ;
break;
}
F_76 ( & V_4 -> V_13 -> V_14 , V_114 ) ;
V_4 -> V_4 . V_113 = V_113 ;
V_4 -> V_4 . V_82 = V_82 ;
F_51 ( V_4 , V_146 , V_115 ) ;
F_51 ( V_4 , V_87 , V_147 ) ;
if ( V_4 -> V_53 ) {
T_5 V_93 ;
F_41 ( V_13 , F_40 ( V_13 ) |
F_72 ( V_148 , 1 << V_4 -> V_119 ) |
F_72 ( V_149 , 1 << V_4 -> V_119 ) ) ;
V_93 = V_150 | V_151 ;
F_51 ( V_4 , V_87 , V_93 ) ;
} else {
F_41 ( V_13 , F_40 ( V_13 ) |
F_72 ( V_148 , 1 << V_4 -> V_119 ) ) ;
}
F_77 ( & V_13 -> V_14 , V_114 ) ;
F_49 ( V_128 , L_19 , V_4 -> V_119 ,
( unsigned long ) F_59 ( V_4 , V_146 ) ) ;
F_49 ( V_128 , L_20 ,
( unsigned long ) F_40 ( V_13 ) ) ;
return 0 ;
}
static int F_78 ( struct V_110 * V_111 )
{
struct V_3 * V_4 = F_38 ( V_111 ) ;
struct V_37 * V_13 = V_4 -> V_13 ;
F_79 ( V_152 ) ;
unsigned long V_114 ;
F_49 ( V_107 , L_21 , V_4 -> V_4 . V_46 ) ;
F_76 ( & V_13 -> V_14 , V_114 ) ;
if ( ! V_4 -> V_4 . V_113 ) {
F_77 ( & V_13 -> V_14 , V_114 ) ;
if ( V_13 -> V_65 . V_153 != V_154 )
F_49 ( V_123 , L_22 ,
V_4 -> V_4 . V_46 ) ;
return - V_124 ;
}
V_4 -> V_4 . V_113 = NULL ;
F_80 ( & V_4 -> V_17 , & V_152 ) ;
if ( V_4 -> V_53 ) {
F_53 ( V_4 , V_92 , 0 ) ;
F_53 ( V_4 , V_90 , 0 ) ;
F_81 ( V_4 , V_155 ) ;
}
F_51 ( V_4 , V_89 , V_147 ) ;
F_41 ( V_13 , F_40 ( V_13 ) &
~ F_72 ( V_148 , 1 << V_4 -> V_119 ) ) ;
F_69 ( V_4 , & V_152 , - V_156 ) ;
F_77 ( & V_13 -> V_14 , V_114 ) ;
return 0 ;
}
static struct V_157 *
F_82 ( struct V_110 * V_111 , T_6 V_158 )
{
struct V_6 * V_7 ;
F_49 ( V_107 , L_23 , V_111 , V_158 ) ;
V_7 = F_83 ( sizeof( * V_7 ) , V_158 ) ;
if ( ! V_7 )
return NULL ;
F_3 ( & V_7 -> V_17 ) ;
return & V_7 -> V_7 ;
}
static void
F_84 ( struct V_110 * V_111 , struct V_157 * V_159 )
{
struct V_6 * V_7 = F_85 ( V_159 ) ;
F_49 ( V_107 , L_24 , V_111 , V_159 ) ;
F_11 ( V_7 ) ;
}
static int F_86 ( struct V_37 * V_13 , struct V_3 * V_4 ,
struct V_6 * V_7 , T_6 V_158 )
{
unsigned long V_114 ;
int V_40 ;
F_49 ( V_160 , L_25 ,
V_4 -> V_4 . V_46 , V_7 -> V_7 . V_29 , & V_7 -> V_7 . V_91 ,
V_7 -> V_7 . V_31 ? 'Z' : 'z' ,
V_7 -> V_7 . V_32 ? 'S' : 's' ,
V_7 -> V_7 . V_30 ? 'I' : 'i' ) ;
if ( V_7 -> V_7 . V_29 > 0x10000 ) {
F_49 ( V_123 , L_26 , V_7 -> V_7 . V_29 ) ;
return - V_124 ;
}
V_40 = F_87 ( & V_13 -> V_65 , & V_7 -> V_7 , V_4 -> V_106 ) ;
if ( V_40 )
return V_40 ;
V_7 -> V_35 = 1 ;
V_7 -> V_93 = F_72 ( V_161 , V_7 -> V_7 . V_29 )
| V_162 | V_163
| V_164 ;
if ( ! V_4 -> V_106 )
V_7 -> V_93 |= V_165 | V_166 ;
V_40 = - V_156 ;
F_76 ( & V_13 -> V_14 , V_114 ) ;
if ( V_4 -> V_4 . V_113 ) {
if ( F_55 ( & V_4 -> V_17 ) )
F_52 ( V_4 , V_7 ) ;
F_7 ( & V_7 -> V_17 , & V_4 -> V_17 ) ;
V_40 = 0 ;
}
F_77 ( & V_13 -> V_14 , V_114 ) ;
return V_40 ;
}
static int
F_88 ( struct V_110 * V_111 , struct V_157 * V_159 , T_6 V_158 )
{
struct V_6 * V_7 = F_85 ( V_159 ) ;
struct V_3 * V_4 = F_38 ( V_111 ) ;
struct V_37 * V_13 = V_4 -> V_13 ;
unsigned long V_114 ;
int V_40 ;
F_49 ( V_107 | V_83 | V_108 , L_27 ,
V_4 -> V_4 . V_46 , V_7 , V_159 -> V_29 ) ;
if ( ! V_13 -> V_167 || V_13 -> V_65 . V_153 == V_154 ||
! V_4 -> V_4 . V_113 )
return - V_156 ;
V_7 -> V_34 = 0 ;
V_7 -> V_35 = 0 ;
V_7 -> V_36 = 0 ;
V_159 -> V_33 = - V_105 ;
V_159 -> V_25 = 0 ;
if ( V_4 -> V_53 )
return F_86 ( V_13 , V_4 , V_7 , V_158 ) ;
V_40 = - V_156 ;
F_76 ( & V_13 -> V_14 , V_114 ) ;
if ( V_4 -> V_4 . V_113 ) {
F_7 ( & V_7 -> V_17 , & V_4 -> V_17 ) ;
if ( ( ! F_29 ( V_4 ) && V_4 -> V_106 ) ||
( F_29 ( V_4 )
&& ( V_4 -> V_58 == V_168
|| V_4 -> V_58 == V_97 ) ) )
F_51 ( V_4 , V_87 , V_86 ) ;
else
F_51 ( V_4 , V_87 , V_95 ) ;
V_40 = 0 ;
}
F_77 ( & V_13 -> V_14 , V_114 ) ;
return V_40 ;
}
static void
F_89 ( struct V_3 * V_4 , struct V_6 * V_7 , T_5 V_33 )
{
V_7 -> V_7 . V_25 = V_7 -> V_7 . V_29 - F_60 ( V_161 , V_33 ) ;
}
static int F_90 ( struct V_3 * V_4 , T_5 * V_169 )
{
unsigned int V_170 ;
T_5 V_33 ;
F_53 ( V_4 , V_92 , 0 ) ;
for ( V_170 = 40 ; V_170 ; -- V_170 ) {
V_33 = F_81 ( V_4 , V_155 ) ;
if ( ! ( V_33 & V_162 ) )
break;
F_91 ( 1 ) ;
}
if ( V_169 )
* V_169 = V_33 ;
if ( V_170 == 0 ) {
F_31 ( & V_4 -> V_13 -> V_60 -> V_61 ,
L_28 ,
V_4 -> V_4 . V_46 ) ;
return - V_171 ;
}
return 0 ;
}
static int F_92 ( struct V_110 * V_111 , struct V_157 * V_159 )
{
struct V_3 * V_4 = F_38 ( V_111 ) ;
struct V_37 * V_13 = V_4 -> V_13 ;
struct V_6 * V_7 ;
unsigned long V_114 ;
T_5 V_33 ;
F_49 ( V_107 | V_83 , L_29 ,
V_4 -> V_4 . V_46 , V_7 ) ;
F_76 ( & V_13 -> V_14 , V_114 ) ;
F_5 (req, &ep->queue, queue) {
if ( & V_7 -> V_7 == V_159 )
break;
}
if ( & V_7 -> V_7 != V_159 ) {
F_77 ( & V_13 -> V_14 , V_114 ) ;
return - V_124 ;
}
if ( V_7 -> V_35 ) {
if ( V_4 -> V_17 . V_96 == & V_7 -> V_17 ) {
V_33 = F_81 ( V_4 , V_155 ) ;
if ( V_33 & V_162 )
F_90 ( V_4 , & V_33 ) ;
#ifdef F_93
V_4 -> V_55 = V_33 ;
#endif
F_42 ( V_13 , V_172 , 1 << V_4 -> V_119 ) ;
F_89 ( V_4 , V_7 , V_33 ) ;
}
}
F_62 ( & V_7 -> V_17 ) ;
F_66 ( V_4 , V_7 , - V_173 ) ;
F_54 ( V_4 ) ;
F_77 ( & V_13 -> V_14 , V_114 ) ;
return 0 ;
}
static int F_94 ( struct V_110 * V_111 , int V_174 )
{
struct V_3 * V_4 = F_38 ( V_111 ) ;
struct V_37 * V_13 = V_4 -> V_13 ;
unsigned long V_114 ;
int V_40 = 0 ;
F_49 ( V_107 , L_30 , V_4 -> V_4 . V_46 ,
V_174 ? L_31 : L_32 ) ;
if ( ! V_4 -> V_4 . V_113 ) {
F_49 ( V_123 , L_33 ,
V_4 -> V_4 . V_46 ) ;
return - V_175 ;
}
if ( V_4 -> V_125 ) {
F_49 ( V_123 , L_34 ,
V_4 -> V_4 . V_46 ) ;
return - V_176 ;
}
F_76 ( & V_13 -> V_14 , V_114 ) ;
if ( ! F_55 ( & V_4 -> V_17 )
|| ( ( V_174 && V_4 -> V_106 && ( F_59 ( V_4 , V_101 )
& F_72 ( V_102 , - 1L ) ) ) ) ) {
V_40 = - V_177 ;
} else {
if ( V_174 )
F_51 ( V_4 , V_85 , V_178 ) ;
else
F_51 ( V_4 , V_104 ,
V_178 | V_179 ) ;
F_59 ( V_4 , V_101 ) ;
}
F_77 ( & V_13 -> V_14 , V_114 ) ;
return V_40 ;
}
static int F_95 ( struct V_110 * V_111 )
{
struct V_3 * V_4 = F_38 ( V_111 ) ;
return F_60 ( V_103 , F_59 ( V_4 , V_101 ) ) ;
}
static void F_96 ( struct V_110 * V_111 )
{
struct V_3 * V_4 = F_38 ( V_111 ) ;
struct V_37 * V_13 = V_4 -> V_13 ;
F_42 ( V_13 , V_172 , 1 << V_4 -> V_119 ) ;
}
static int F_97 ( struct V_180 * V_65 )
{
struct V_37 * V_13 = F_98 ( V_65 ) ;
return F_60 ( V_181 , F_99 ( V_13 , V_182 ) ) ;
}
static int F_100 ( struct V_180 * V_65 )
{
struct V_37 * V_13 = F_98 ( V_65 ) ;
unsigned long V_114 ;
T_5 V_93 ;
int V_40 = - V_124 ;
F_76 ( & V_13 -> V_14 , V_114 ) ;
if ( V_13 -> V_183 & ( 1 << V_184 ) ) {
V_93 = F_99 ( V_13 , V_185 ) ;
F_42 ( V_13 , V_185 , V_93 | V_186 ) ;
V_40 = 0 ;
}
F_77 ( & V_13 -> V_14 , V_114 ) ;
return V_40 ;
}
static int
F_101 ( struct V_180 * V_65 , int V_187 )
{
struct V_37 * V_13 = F_98 ( V_65 ) ;
unsigned long V_114 ;
V_65 -> V_187 = ( V_187 != 0 ) ;
F_76 ( & V_13 -> V_14 , V_114 ) ;
if ( V_187 )
V_13 -> V_183 |= 1 << V_188 ;
else
V_13 -> V_183 &= ~ ( 1 << V_188 ) ;
F_77 ( & V_13 -> V_14 , V_114 ) ;
return 0 ;
}
static void F_102 ( struct V_37 * V_13 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 , * V_22 ;
F_42 ( V_13 , V_172 , ~ 0UL ) ;
V_4 = F_38 ( V_13 -> V_65 . V_71 ) ;
F_9 (req, tmp_req, &ep->queue, queue) {
F_62 ( & V_7 -> V_17 ) ;
F_66 ( V_4 , V_7 , - V_173 ) ;
}
}
static struct V_3 * F_103 ( struct V_37 * V_13 , T_7 V_189 )
{
struct V_3 * V_4 ;
if ( ( V_189 & V_118 ) == 0 )
return F_38 ( V_13 -> V_65 . V_71 ) ;
F_5 (ep, &udc->gadget.ep_list, ep.ep_list) {
T_8 V_117 ;
if ( ! V_4 -> V_4 . V_113 )
continue;
V_117 = V_4 -> V_4 . V_113 -> V_117 ;
if ( ( V_189 ^ V_117 ) & V_190 )
continue;
if ( ( V_117 & V_118 )
== ( V_189 & V_118 ) )
return V_4 ;
}
return NULL ;
}
static inline void F_104 ( struct V_37 * V_13 , struct V_3 * V_4 )
{
F_51 ( V_4 , V_85 , V_178 ) ;
V_4 -> V_58 = V_191 ;
}
static inline int F_105 ( struct V_37 * V_13 , struct V_3 * V_4 )
{
if ( F_59 ( V_4 , V_101 ) & V_178 )
return 1 ;
return 0 ;
}
static inline void F_106 ( struct V_37 * V_13 , unsigned int V_192 )
{
T_5 V_193 ;
F_49 ( V_194 , L_35 , V_192 ) ;
V_193 = F_99 ( V_13 , V_185 ) ;
V_193 = F_107 ( V_195 , V_192 , V_193 ) ;
F_42 ( V_13 , V_185 , V_193 ) ;
}
static int F_108 ( struct V_37 * V_13 )
{
static const char V_196 [] = {
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0xAA , 0xAA , 0xAA , 0xAA , 0xAA , 0xAA , 0xAA , 0xAA ,
0xEE , 0xEE , 0xEE , 0xEE , 0xEE , 0xEE , 0xEE , 0xEE ,
0xFE , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF ,
0xFF , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF ,
0x7F , 0xBF , 0xDF , 0xEF , 0xF7 , 0xFB , 0xFD ,
0xFC , 0x7E , 0xBF , 0xDF , 0xEF , 0xF7 , 0xFB , 0xFD , 0x7E
} ;
struct V_3 * V_4 ;
struct V_197 * V_61 = & V_13 -> V_60 -> V_61 ;
int V_198 ;
V_198 = V_13 -> V_198 ;
F_102 ( V_13 ) ;
switch ( V_198 ) {
case 0x0100 :
F_42 ( V_13 , V_199 , V_200 ) ;
F_109 ( V_61 , L_36 ) ;
break;
case 0x0200 :
F_42 ( V_13 , V_199 , V_201 ) ;
F_109 ( V_61 , L_37 ) ;
break;
case 0x0300 :
V_4 = & V_13 -> V_3 [ 0 ] ;
F_42 ( V_13 , V_199 ,
F_72 ( V_202 , V_203 ) ) ;
F_51 ( V_4 , V_146 ,
F_72 ( V_126 , V_204 )
| V_129
| F_72 ( V_131 , V_143 )
| F_72 ( V_133 , 1 ) ) ;
if ( ! ( F_59 ( V_4 , V_146 ) & V_205 ) ) {
F_104 ( V_13 , V_4 ) ;
F_31 ( V_61 , L_38 ) ;
} else {
F_51 ( V_4 , V_87 , V_147 ) ;
F_109 ( V_61 , L_39 ) ;
}
break;
case 0x0400 :
V_4 = & V_13 -> V_3 [ 0 ] ;
F_51 ( V_4 , V_146 ,
F_72 ( V_126 , V_204 )
| V_129
| F_72 ( V_131 , V_143 )
| F_72 ( V_133 , 1 ) ) ;
if ( ! ( F_59 ( V_4 , V_146 ) & V_205 ) ) {
F_104 ( V_13 , V_4 ) ;
F_31 ( V_61 , L_40 ) ;
} else {
F_51 ( V_4 , V_87 , V_147 ) ;
F_42 ( V_13 , V_199 , V_206 ) ;
F_50 ( V_4 -> V_84 , V_196 ,
sizeof( V_196 ) ) ;
F_51 ( V_4 , V_85 , V_86 ) ;
F_109 ( V_61 , L_41 ) ;
}
break;
default:
F_31 ( V_61 , L_42 , V_198 ) ;
return - V_124 ;
}
return 0 ;
}
static inline bool F_110 ( struct V_207 * V_208 )
{
if ( V_208 -> V_209 == F_111 ( V_184 ) )
return true ;
return false ;
}
static inline bool F_112 ( struct V_207 * V_208 )
{
if ( V_208 -> V_209 == F_111 ( V_210 ) )
return true ;
return false ;
}
static inline bool F_113 ( struct V_207 * V_208 )
{
if ( V_208 -> V_209 == F_111 ( V_211 ) )
return true ;
return false ;
}
static int F_114 ( struct V_37 * V_13 , struct V_3 * V_4 ,
struct V_207 * V_208 )
{
int V_212 = 0 ;
switch ( V_208 -> V_213 ) {
case V_214 : {
T_7 V_33 ;
if ( V_208 -> V_215 == ( V_190 | V_216 ) ) {
V_33 = F_111 ( V_13 -> V_183 ) ;
} else if ( V_208 -> V_215
== ( V_190 | V_217 ) ) {
V_33 = F_111 ( 0 ) ;
} else if ( V_208 -> V_215
== ( V_190 | V_218 ) ) {
struct V_3 * V_219 ;
V_219 = F_103 ( V_13 , F_115 ( V_208 -> V_189 ) ) ;
if ( ! V_219 )
goto V_220;
V_33 = 0 ;
if ( F_105 ( V_13 , V_219 ) )
V_33 |= F_111 ( 1 ) ;
} else
goto V_221;
if ( V_208 -> V_222 != F_111 ( sizeof( V_33 ) ) )
goto V_220;
V_4 -> V_58 = V_168 ;
F_116 ( V_33 , V_4 -> V_84 ) ;
F_51 ( V_4 , V_85 , V_86 ) ;
break;
}
case V_223 : {
if ( V_208 -> V_215 == V_216 ) {
if ( F_110 ( V_208 ) )
V_13 -> V_183
&= ~ ( 1 << V_184 ) ;
else
goto V_220;
} else if ( V_208 -> V_215 == V_218 ) {
struct V_3 * V_219 ;
if ( V_208 -> V_222 != F_111 ( 0 )
|| ! F_113 ( V_208 ) )
goto V_220;
V_219 = F_103 ( V_13 , F_115 ( V_208 -> V_189 ) ) ;
if ( ! V_219 )
goto V_220;
F_51 ( V_219 , V_104 , V_178 ) ;
if ( V_219 -> V_119 != 0 )
F_51 ( V_219 , V_104 ,
V_179 ) ;
} else {
goto V_221;
}
F_57 ( V_13 , V_4 ) ;
break;
}
case V_224 : {
if ( V_208 -> V_215 == V_216 ) {
if ( F_112 ( V_208 ) ) {
F_57 ( V_13 , V_4 ) ;
V_4 -> V_58 = V_225 ;
V_13 -> V_198 = F_115 ( V_208 -> V_189 ) ;
return 0 ;
} else if ( F_110 ( V_208 ) ) {
V_13 -> V_183 |= 1 << V_184 ;
} else {
goto V_220;
}
} else if ( V_208 -> V_215 == V_218 ) {
struct V_3 * V_219 ;
if ( V_208 -> V_222 != F_111 ( 0 )
|| ! F_113 ( V_208 ) )
goto V_220;
V_219 = F_103 ( V_13 , F_115 ( V_208 -> V_189 ) ) ;
if ( ! V_219 )
goto V_220;
F_51 ( V_219 , V_85 , V_178 ) ;
} else
goto V_221;
F_57 ( V_13 , V_4 ) ;
break;
}
case V_226 :
if ( V_208 -> V_215 != ( V_227 | V_216 ) )
goto V_221;
F_106 ( V_13 , F_115 ( V_208 -> V_209 ) ) ;
F_57 ( V_13 , V_4 ) ;
V_4 -> V_58 = V_228 ;
break;
default:
V_221:
F_63 ( & V_13 -> V_14 ) ;
V_212 = V_13 -> V_167 -> V_229 ( & V_13 -> V_65 , V_208 ) ;
F_65 ( & V_13 -> V_14 ) ;
}
return V_212 ;
V_220:
F_117 ( L_43
L_44 ,
V_4 -> V_4 . V_46 , V_208 -> V_215 , V_208 -> V_213 ,
F_115 ( V_208 -> V_209 ) , F_115 ( V_208 -> V_189 ) ,
F_115 ( V_208 -> V_222 ) ) ;
F_104 ( V_13 , V_4 ) ;
return - 1 ;
}
static void F_118 ( struct V_37 * V_13 , struct V_3 * V_4 )
{
struct V_6 * V_7 ;
T_5 V_230 ;
T_5 V_231 ;
V_232:
V_230 = F_59 ( V_4 , V_101 ) ;
V_231 = F_59 ( V_4 , V_233 ) ;
F_49 ( V_234 , L_45 ,
V_4 -> V_4 . V_46 , V_4 -> V_58 , V_230 , V_231 ) ;
V_7 = NULL ;
if ( ! F_55 ( & V_4 -> V_17 ) )
V_7 = F_56 ( V_4 -> V_17 . V_96 ,
struct V_6 , V_17 ) ;
if ( ( V_231 & V_86 ) && ! ( V_230 & V_86 ) ) {
if ( V_7 -> V_34 )
F_48 ( V_4 , V_7 ) ;
else
F_52 ( V_4 , V_7 ) ;
if ( V_7 -> V_36 ) {
F_51 ( V_4 , V_89 , V_86 ) ;
F_51 ( V_4 , V_87 , V_94 ) ;
}
goto V_232;
}
if ( ( V_230 & V_231 ) & V_94 ) {
F_51 ( V_4 , V_104 , V_94 ) ;
switch ( V_4 -> V_58 ) {
case V_168 :
F_51 ( V_4 , V_87 , V_95 ) ;
F_51 ( V_4 , V_89 , V_94 ) ;
V_4 -> V_58 = V_235 ;
break;
case V_228 :
F_42 ( V_13 , V_185 , ( F_99 ( V_13 , V_185 )
| V_236 ) ) ;
F_51 ( V_4 , V_89 , V_94 ) ;
V_4 -> V_58 = V_191 ;
break;
case V_97 :
if ( V_7 ) {
F_62 ( & V_7 -> V_17 ) ;
F_66 ( V_4 , V_7 , 0 ) ;
F_54 ( V_4 ) ;
}
F_51 ( V_4 , V_89 , V_94 ) ;
V_4 -> V_58 = V_191 ;
break;
case V_225 :
F_51 ( V_4 , V_89 , V_94 ) ;
V_4 -> V_58 = V_191 ;
if ( F_108 ( V_13 ) )
F_104 ( V_13 , V_4 ) ;
break;
default:
F_117 ( L_46
L_44 ,
V_4 -> V_4 . V_46 , V_4 -> V_58 ) ;
F_104 ( V_13 , V_4 ) ;
break;
}
goto V_232;
}
if ( ( V_230 & V_231 ) & V_95 ) {
switch ( V_4 -> V_58 ) {
case V_235 :
F_51 ( V_4 , V_104 , V_95 ) ;
F_51 ( V_4 , V_89 , V_95 ) ;
if ( V_7 ) {
F_62 ( & V_7 -> V_17 ) ;
F_66 ( V_4 , V_7 , 0 ) ;
}
V_4 -> V_58 = V_191 ;
break;
case V_237 :
F_58 ( V_4 ) ;
break;
default:
F_51 ( V_4 , V_104 , V_95 ) ;
F_51 ( V_4 , V_89 , V_95 ) ;
F_117 ( L_47
L_44 ,
V_4 -> V_4 . V_46 , V_4 -> V_58 ) ;
F_104 ( V_13 , V_4 ) ;
break;
}
goto V_232;
}
if ( V_230 & V_238 ) {
union {
struct V_207 V_208 ;
unsigned long V_39 [ 2 ] ;
} V_208 ;
unsigned int V_239 ;
int V_40 ;
if ( V_4 -> V_58 != V_191 ) {
int V_33 = - V_240 ;
if ( V_4 -> V_58 == V_235
|| V_4 -> V_58 == V_97 ) {
F_51 ( V_4 , V_89 , V_95 ) ;
V_33 = 0 ;
}
if ( V_7 ) {
F_62 ( & V_7 -> V_17 ) ;
F_66 ( V_4 , V_7 , V_33 ) ;
}
}
V_239 = F_60 ( V_103 , F_59 ( V_4 , V_101 ) ) ;
F_49 ( V_128 , L_48 , V_239 ) ;
if ( V_239 != sizeof( V_208 ) ) {
F_119 ( L_49
L_50 , V_239 , sizeof( V_208 ) ) ;
F_104 ( V_13 , V_4 ) ;
return;
}
F_49 ( V_241 , L_51 , V_4 -> V_84 ) ;
F_61 ( V_208 . V_39 , V_4 -> V_84 , sizeof( V_208 ) ) ;
F_51 ( V_4 , V_104 , V_238 ) ;
if ( V_208 . V_208 . V_215 & V_190 ) {
V_4 -> V_58 = V_168 ;
} else {
if ( V_208 . V_208 . V_222 != F_111 ( 0 ) )
V_4 -> V_58 = V_237 ;
else
V_4 -> V_58 = V_97 ;
}
V_40 = - 1 ;
if ( V_4 -> V_119 == 0 )
V_40 = F_114 ( V_13 , V_4 , & V_208 . V_208 ) ;
else {
F_63 ( & V_13 -> V_14 ) ;
V_40 = V_13 -> V_167 -> V_229 ( & V_13 -> V_65 , & V_208 . V_208 ) ;
F_65 ( & V_13 -> V_14 ) ;
}
F_49 ( V_194 , L_52 ,
V_208 . V_208 . V_215 , V_208 . V_208 . V_213 ,
F_115 ( V_208 . V_208 . V_222 ) , V_4 -> V_58 , V_40 ) ;
if ( V_40 < 0 ) {
F_104 ( V_13 , V_4 ) ;
}
}
}
static void F_120 ( struct V_37 * V_13 , struct V_3 * V_4 )
{
struct V_6 * V_7 ;
T_5 V_230 ;
T_5 V_231 ;
V_230 = F_59 ( V_4 , V_101 ) ;
V_231 = F_59 ( V_4 , V_233 ) ;
F_49 ( V_234 , L_53 , V_4 -> V_4 . V_46 , V_230 ) ;
while ( ( V_231 & V_86 ) && ! ( V_230 & V_86 ) ) {
F_49 ( V_194 , L_54 , V_4 -> V_4 . V_46 ) ;
if ( F_55 ( & V_4 -> V_17 ) ) {
F_121 ( & V_13 -> V_60 -> V_61 , L_55 ) ;
F_51 ( V_4 , V_89 , V_86 ) ;
return;
}
V_7 = F_56 ( V_4 -> V_17 . V_96 , struct V_6 , V_17 ) ;
if ( V_7 -> V_35 ) {
F_51 ( V_4 , V_85 ,
V_86 ) ;
F_51 ( V_4 , V_89 ,
V_86 ) ;
F_62 ( & V_7 -> V_17 ) ;
F_54 ( V_4 ) ;
F_66 ( V_4 , V_7 , 0 ) ;
} else {
if ( V_7 -> V_34 )
F_48 ( V_4 , V_7 ) ;
else
F_52 ( V_4 , V_7 ) ;
if ( V_7 -> V_36 ) {
F_62 ( & V_7 -> V_17 ) ;
F_54 ( V_4 ) ;
F_66 ( V_4 , V_7 , 0 ) ;
}
}
V_230 = F_59 ( V_4 , V_101 ) ;
V_231 = F_59 ( V_4 , V_233 ) ;
}
if ( ( V_230 & V_231 ) & V_95 ) {
F_49 ( V_194 , L_56 , V_4 -> V_4 . V_46 ) ;
F_58 ( V_4 ) ;
}
}
static void F_122 ( struct V_37 * V_13 , struct V_3 * V_4 )
{
struct V_6 * V_7 ;
T_5 V_33 , V_242 , V_243 ;
V_33 = F_81 ( V_4 , V_155 ) ;
V_242 = F_81 ( V_4 , V_92 ) ;
#ifdef F_93
V_4 -> V_55 = V_33 ;
#endif
V_243 = V_33 & V_242 ;
F_49 ( V_234 | V_160 , L_57 , V_33 , V_242 ) ;
if ( V_33 & V_162 ) {
F_31 ( & V_13 -> V_60 -> V_61 ,
L_58 ) ;
F_31 ( & V_13 -> V_60 -> V_61 ,
L_59 ,
V_33 , V_243 , V_242 ) ;
}
if ( F_55 ( & V_4 -> V_17 ) )
return;
if ( V_243 & ( V_244 | V_245 ) ) {
V_7 = F_56 ( V_4 -> V_17 . V_96 , struct V_6 , V_17 ) ;
F_89 ( V_4 , V_7 , V_33 ) ;
F_62 ( & V_7 -> V_17 ) ;
F_54 ( V_4 ) ;
F_66 ( V_4 , V_7 , 0 ) ;
}
}
static T_9 F_123 ( int V_246 , void * V_247 )
{
struct V_37 * V_13 = V_247 ;
T_5 V_33 , V_248 ;
T_5 V_249 ;
T_5 V_250 ;
F_65 ( & V_13 -> V_14 ) ;
V_248 = F_40 ( V_13 ) ;
V_33 = F_99 ( V_13 , V_251 ) & ( V_248 | V_252 ) ;
F_49 ( V_234 , L_60 , V_33 ) ;
if ( V_33 & V_253 ) {
F_46 ( V_13 , 0 ) ;
F_42 ( V_13 , V_254 , V_253 ) ;
F_41 ( V_13 , V_248 | V_255 ) ;
V_13 -> V_79 = true ;
F_49 ( V_194 , L_61 ) ;
if ( V_13 -> V_65 . V_153 != V_154
&& V_13 -> V_167 && V_13 -> V_167 -> V_256 ) {
F_63 ( & V_13 -> V_14 ) ;
V_13 -> V_167 -> V_256 ( & V_13 -> V_65 ) ;
F_65 ( & V_13 -> V_14 ) ;
}
}
if ( V_33 & V_255 ) {
F_46 ( V_13 , 1 ) ;
F_42 ( V_13 , V_254 , V_255 ) ;
F_41 ( V_13 , V_248 & ~ V_255 ) ;
F_49 ( V_194 , L_62 ) ;
}
if ( V_33 & V_257 ) {
F_42 ( V_13 , V_254 , V_257 ) ;
F_47 ( V_13 ) ;
F_49 ( V_194 , L_63 ) ;
if ( V_13 -> V_65 . V_153 != V_154
&& V_13 -> V_167 && V_13 -> V_167 -> V_258 ) {
F_63 ( & V_13 -> V_14 ) ;
V_13 -> V_167 -> V_258 ( & V_13 -> V_65 ) ;
F_65 ( & V_13 -> V_14 ) ;
}
}
V_249 = F_60 ( V_149 , V_33 ) ;
if ( V_249 ) {
int V_38 ;
for ( V_38 = 1 ; V_38 <= V_259 ; V_38 ++ )
if ( V_249 & ( 1 << V_38 ) )
F_122 ( V_13 , & V_13 -> V_3 [ V_38 ] ) ;
}
V_250 = F_60 ( V_148 , V_33 ) ;
if ( V_250 ) {
int V_38 ;
for ( V_38 = 0 ; V_38 < V_13 -> V_260 ; V_38 ++ )
if ( V_250 & ( 1 << V_38 ) ) {
if ( F_29 ( & V_13 -> V_3 [ V_38 ] ) )
F_118 ( V_13 , & V_13 -> V_3 [ V_38 ] ) ;
else
F_120 ( V_13 , & V_13 -> V_3 [ V_38 ] ) ;
}
}
if ( V_33 & V_261 ) {
struct V_3 * V_71 ;
F_42 ( V_13 , V_254 , V_261 ) ;
F_47 ( V_13 ) ;
F_102 ( V_13 ) ;
if ( V_13 -> V_65 . V_153 != V_154 && V_13 -> V_167 ) {
V_13 -> V_65 . V_153 = V_154 ;
F_63 ( & V_13 -> V_14 ) ;
F_124 ( & V_13 -> V_65 , V_13 -> V_167 ) ;
F_65 ( & V_13 -> V_14 ) ;
}
if ( V_33 & V_252 )
V_13 -> V_65 . V_153 = V_262 ;
else
V_13 -> V_65 . V_153 = V_263 ;
F_49 ( V_194 , L_64 ,
F_125 ( V_13 -> V_65 . V_153 ) ) ;
V_71 = & V_13 -> V_3 [ 0 ] ;
V_71 -> V_4 . V_113 = & V_264 ;
V_71 -> V_58 = V_191 ;
F_51 ( V_71 , V_146 ,
( F_72 ( V_126 , V_265 )
| F_72 ( V_131 , V_132 )
| F_72 ( V_133 , V_134 ) ) ) ;
F_51 ( V_71 , V_87 ,
V_147 | V_238 ) ;
F_41 ( V_13 , V_248 | F_72 ( V_148 , 1 ) |
V_253 | V_257 ) ;
if ( ! ( F_59 ( V_71 , V_146 ) & V_205 ) )
F_126 ( & V_13 -> V_60 -> V_61 ,
L_65 ) ;
}
F_63 ( & V_13 -> V_14 ) ;
return V_266 ;
}
static int F_127 ( struct V_37 * V_13 )
{
int V_40 ;
if ( V_13 -> V_267 )
return 0 ;
V_40 = F_128 ( V_13 -> V_268 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_128 ( V_13 -> V_269 ) ;
if ( V_40 ) {
F_129 ( V_13 -> V_268 ) ;
return V_40 ;
}
V_13 -> V_267 = true ;
return 0 ;
}
static void F_130 ( struct V_37 * V_13 )
{
if ( ! V_13 -> V_267 )
return;
F_129 ( V_13 -> V_269 ) ;
F_129 ( V_13 -> V_268 ) ;
V_13 -> V_267 = false ;
}
static int F_131 ( struct V_37 * V_13 )
{
unsigned long V_114 ;
int V_40 ;
V_40 = F_127 ( V_13 ) ;
if ( V_40 )
return V_40 ;
F_76 ( & V_13 -> V_14 , V_114 ) ;
F_46 ( V_13 , 1 ) ;
F_42 ( V_13 , V_185 , V_270 ) ;
F_41 ( V_13 , V_261 ) ;
F_77 ( & V_13 -> V_14 , V_114 ) ;
return 0 ;
}
static void F_132 ( struct V_37 * V_13 )
{
unsigned long V_114 ;
F_76 ( & V_13 -> V_14 , V_114 ) ;
V_13 -> V_65 . V_153 = V_154 ;
F_102 ( V_13 ) ;
F_46 ( V_13 , 0 ) ;
F_42 ( V_13 , V_185 , V_271 ) ;
F_77 ( & V_13 -> V_14 , V_114 ) ;
F_130 ( V_13 ) ;
}
static T_9 F_133 ( int V_246 , void * V_247 )
{
struct V_37 * V_13 = V_247 ;
int V_272 ;
F_91 ( 10 ) ;
F_134 ( & V_13 -> V_273 ) ;
V_272 = F_43 ( V_13 ) ;
if ( V_272 != V_13 -> V_274 ) {
if ( V_272 ) {
F_131 ( V_13 ) ;
} else {
F_132 ( V_13 ) ;
if ( V_13 -> V_167 -> V_275 )
V_13 -> V_167 -> V_275 ( & V_13 -> V_65 ) ;
}
V_13 -> V_274 = V_272 ;
}
F_135 ( & V_13 -> V_273 ) ;
return V_266 ;
}
static int F_136 ( struct V_180 * V_65 ,
struct V_276 * V_167 )
{
int V_40 ;
struct V_37 * V_13 = F_137 ( V_65 , struct V_37 , V_65 ) ;
unsigned long V_114 ;
F_76 ( & V_13 -> V_14 , V_114 ) ;
V_13 -> V_183 = 1 << V_188 ;
V_13 -> V_167 = V_167 ;
F_77 ( & V_13 -> V_14 , V_114 ) ;
F_134 ( & V_13 -> V_273 ) ;
if ( F_44 ( V_13 -> V_75 ) )
F_138 ( F_139 ( V_13 -> V_75 ) ) ;
V_13 -> V_274 = F_43 ( V_13 ) ;
if ( V_13 -> V_274 ) {
V_40 = F_131 ( V_13 ) ;
if ( V_40 )
goto V_277;
}
F_135 ( & V_13 -> V_273 ) ;
return 0 ;
V_277:
if ( F_44 ( V_13 -> V_75 ) )
F_140 ( F_139 ( V_13 -> V_75 ) ) ;
F_135 ( & V_13 -> V_273 ) ;
F_76 ( & V_13 -> V_14 , V_114 ) ;
V_13 -> V_183 &= ~ ( 1 << V_188 ) ;
V_13 -> V_167 = NULL ;
F_77 ( & V_13 -> V_14 , V_114 ) ;
return V_40 ;
}
static int F_141 ( struct V_180 * V_65 )
{
struct V_37 * V_13 = F_137 ( V_65 , struct V_37 , V_65 ) ;
if ( F_44 ( V_13 -> V_75 ) )
F_140 ( F_139 ( V_13 -> V_75 ) ) ;
F_132 ( V_13 ) ;
V_13 -> V_167 = NULL ;
return 0 ;
}
static void F_142 ( struct V_37 * V_13 , int V_77 )
{
F_143 ( V_13 -> V_278 , V_279 , V_280 ,
V_77 ? V_280 : 0 ) ;
}
static void F_144 ( struct V_37 * V_13 )
{
F_143 ( V_13 -> V_278 , V_279 , V_280 , 0 ) ;
F_143 ( V_13 -> V_278 , V_279 , V_280 ,
V_280 ) ;
}
static struct V_3 * F_145 ( struct V_281 * V_60 ,
struct V_37 * V_13 )
{
T_5 V_73 ;
const char * V_46 ;
enum V_282 V_114 ;
struct V_283 * V_284 = V_60 -> V_61 . V_285 ;
const struct V_286 * V_287 ;
struct V_283 * V_288 ;
int V_38 , V_40 ;
struct V_3 * V_289 , * V_4 ;
V_287 = F_146 ( V_290 , V_284 ) ;
if ( ! V_287 )
return F_147 ( - V_124 ) ;
V_13 -> V_78 = V_287 -> V_39 ;
V_13 -> V_278 = F_148 ( L_66 ) ;
if ( F_34 ( V_13 -> V_278 ) )
V_13 -> V_278 = F_148 ( L_67 ) ;
if ( V_13 -> V_78 && F_34 ( V_13 -> V_278 ) )
return F_149 ( V_13 -> V_278 ) ;
V_13 -> V_260 = 0 ;
V_13 -> V_75 = F_150 ( V_284 , L_68 , 0 ,
& V_114 ) ;
V_13 -> V_76 = ( V_114 & V_291 ) ? 1 : 0 ;
V_288 = NULL ;
while ( ( V_288 = F_151 ( V_284 , V_288 ) ) )
V_13 -> V_260 ++ ;
V_289 = F_152 ( & V_60 -> V_61 , sizeof( struct V_3 ) * V_13 -> V_260 ,
V_11 ) ;
if ( ! V_289 )
return F_147 ( - V_12 ) ;
V_13 -> V_65 . V_71 = & V_289 [ 0 ] . V_4 ;
F_3 ( & V_289 [ 0 ] . V_4 . V_292 ) ;
V_288 = NULL ;
V_38 = 0 ;
while ( ( V_288 = F_151 ( V_284 , V_288 ) ) ) {
V_4 = & V_289 [ V_38 ] ;
V_40 = F_153 ( V_288 , L_69 , & V_73 ) ;
if ( V_40 ) {
F_31 ( & V_60 -> V_61 , L_70 , V_40 ) ;
goto V_277;
}
V_4 -> V_119 = V_73 ;
V_40 = F_153 ( V_288 , L_71 , & V_73 ) ;
if ( V_40 ) {
F_31 ( & V_60 -> V_61 , L_72 , V_40 ) ;
goto V_277;
}
V_4 -> V_122 = V_73 ;
V_40 = F_153 ( V_288 , L_73 , & V_73 ) ;
if ( V_40 ) {
F_31 ( & V_60 -> V_61 , L_74 , V_40 ) ;
goto V_277;
}
V_4 -> V_138 = V_73 ;
V_4 -> V_53 = F_154 ( V_288 , L_75 ) ;
V_4 -> V_136 = F_154 ( V_288 , L_76 ) ;
V_40 = F_155 ( V_288 , L_77 , & V_46 ) ;
if ( V_40 ) {
F_31 ( & V_60 -> V_61 , L_78 , V_40 ) ;
goto V_277;
}
V_4 -> V_4 . V_46 = V_46 ;
V_4 -> V_293 = V_13 -> V_43 + F_156 ( V_38 ) ;
V_4 -> V_294 = V_13 -> V_43 + F_157 ( V_38 ) ;
V_4 -> V_84 = V_13 -> V_84 + F_158 ( V_38 ) ;
V_4 -> V_4 . V_295 = & V_296 ;
F_159 ( & V_4 -> V_4 , V_4 -> V_122 ) ;
V_4 -> V_13 = V_13 ;
F_3 ( & V_4 -> V_17 ) ;
if ( V_4 -> V_119 == 0 ) {
V_4 -> V_4 . V_297 . V_298 = true ;
} else {
V_4 -> V_4 . V_297 . V_299 = V_4 -> V_136 ;
V_4 -> V_4 . V_297 . V_300 = true ;
V_4 -> V_4 . V_297 . V_301 = true ;
}
V_4 -> V_4 . V_297 . V_302 = true ;
V_4 -> V_4 . V_297 . V_303 = true ;
if ( V_38 )
F_7 ( & V_4 -> V_4 . V_292 , & V_13 -> V_65 . V_292 ) ;
V_38 ++ ;
}
if ( V_38 == 0 ) {
F_31 ( & V_60 -> V_61 , L_79 ) ;
V_40 = - V_124 ;
goto V_277;
}
return V_289 ;
V_277:
return F_147 ( V_40 ) ;
}
static struct V_3 * F_145 ( struct V_281 * V_60 ,
struct V_37 * V_13 )
{
return F_147 ( - V_304 ) ;
}
static struct V_3 * F_160 ( struct V_281 * V_60 ,
struct V_37 * V_13 )
{
struct V_305 * V_306 = F_161 ( & V_60 -> V_61 ) ;
struct V_3 * V_289 ;
int V_38 ;
if ( ! V_306 )
return F_147 ( - V_307 ) ;
V_289 = F_152 ( & V_60 -> V_61 , sizeof( struct V_3 ) * V_306 -> V_260 ,
V_11 ) ;
if ( ! V_289 )
return F_147 ( - V_12 ) ;
V_13 -> V_65 . V_71 = & V_289 [ 0 ] . V_4 ;
V_13 -> V_75 = V_306 -> V_75 ;
V_13 -> V_76 = V_306 -> V_76 ;
V_13 -> V_260 = V_306 -> V_260 ;
F_3 ( & V_289 [ 0 ] . V_4 . V_292 ) ;
for ( V_38 = 0 ; V_38 < V_306 -> V_260 ; V_38 ++ ) {
struct V_3 * V_4 = & V_289 [ V_38 ] ;
V_4 -> V_293 = V_13 -> V_43 + F_156 ( V_38 ) ;
V_4 -> V_294 = V_13 -> V_43 + F_157 ( V_38 ) ;
V_4 -> V_84 = V_13 -> V_84 + F_158 ( V_38 ) ;
V_4 -> V_4 . V_295 = & V_296 ;
V_4 -> V_4 . V_46 = V_306 -> V_4 [ V_38 ] . V_46 ;
V_4 -> V_122 = V_306 -> V_4 [ V_38 ] . V_122 ;
F_159 ( & V_4 -> V_4 , V_4 -> V_122 ) ;
V_4 -> V_13 = V_13 ;
F_3 ( & V_4 -> V_17 ) ;
V_4 -> V_138 = V_306 -> V_4 [ V_38 ] . V_138 ;
V_4 -> V_119 = V_306 -> V_4 [ V_38 ] . V_119 ;
V_4 -> V_53 = V_306 -> V_4 [ V_38 ] . V_53 ;
V_4 -> V_136 = V_306 -> V_4 [ V_38 ] . V_136 ;
if ( V_38 == 0 ) {
V_4 -> V_4 . V_297 . V_298 = true ;
} else {
V_4 -> V_4 . V_297 . V_299 = V_4 -> V_136 ;
V_4 -> V_4 . V_297 . V_300 = true ;
V_4 -> V_4 . V_297 . V_301 = true ;
}
V_4 -> V_4 . V_297 . V_302 = true ;
V_4 -> V_4 . V_297 . V_303 = true ;
if ( V_38 )
F_7 ( & V_4 -> V_4 . V_292 , & V_13 -> V_65 . V_292 ) ;
}
return V_289 ;
}
static int F_162 ( struct V_281 * V_60 )
{
struct V_63 * V_43 , * V_84 ;
struct V_308 * V_268 , * V_269 ;
struct V_37 * V_13 ;
int V_246 , V_40 , V_38 ;
V_13 = F_152 ( & V_60 -> V_61 , sizeof( * V_13 ) , V_11 ) ;
if ( ! V_13 )
return - V_12 ;
V_13 -> V_65 = V_309 ;
F_3 ( & V_13 -> V_65 . V_292 ) ;
V_43 = F_35 ( V_60 , V_66 , V_67 ) ;
V_84 = F_35 ( V_60 , V_66 , V_310 ) ;
if ( ! V_43 || ! V_84 )
return - V_307 ;
V_246 = F_163 ( V_60 , 0 ) ;
if ( V_246 < 0 )
return V_246 ;
V_268 = F_164 ( & V_60 -> V_61 , L_80 ) ;
if ( F_34 ( V_268 ) )
return F_165 ( V_268 ) ;
V_269 = F_164 ( & V_60 -> V_61 , L_81 ) ;
if ( F_34 ( V_269 ) )
return F_165 ( V_269 ) ;
F_166 ( & V_13 -> V_14 ) ;
F_167 ( & V_13 -> V_273 ) ;
V_13 -> V_60 = V_60 ;
V_13 -> V_268 = V_268 ;
V_13 -> V_269 = V_269 ;
V_13 -> V_75 = - V_175 ;
V_40 = - V_12 ;
V_13 -> V_43 = F_168 ( & V_60 -> V_61 , V_43 -> V_311 , F_37 ( V_43 ) ) ;
if ( ! V_13 -> V_43 ) {
F_31 ( & V_60 -> V_61 , L_82 ) ;
return V_40 ;
}
F_109 ( & V_60 -> V_61 , L_83 ,
( unsigned long ) V_43 -> V_311 , V_13 -> V_43 ) ;
V_13 -> V_84 = F_168 ( & V_60 -> V_61 , V_84 -> V_311 , F_37 ( V_84 ) ) ;
if ( ! V_13 -> V_84 ) {
F_31 ( & V_60 -> V_61 , L_84 ) ;
return V_40 ;
}
F_109 ( & V_60 -> V_61 , L_85 ,
( unsigned long ) V_84 -> V_311 , V_13 -> V_84 ) ;
F_169 ( V_60 , V_13 ) ;
V_40 = F_128 ( V_268 ) ;
if ( V_40 ) {
F_31 ( & V_60 -> V_61 , L_86 ) ;
return V_40 ;
}
F_42 ( V_13 , V_185 , V_271 ) ;
F_129 ( V_268 ) ;
if ( V_60 -> V_61 . V_285 )
V_13 -> V_3 = F_145 ( V_60 , V_13 ) ;
else
V_13 -> V_3 = F_160 ( V_60 , V_13 ) ;
F_46 ( V_13 , 0 ) ;
if ( F_34 ( V_13 -> V_3 ) )
return F_165 ( V_13 -> V_3 ) ;
V_40 = F_170 ( & V_60 -> V_61 , V_246 , F_123 , 0 ,
L_87 , V_13 ) ;
if ( V_40 ) {
F_31 ( & V_60 -> V_61 , L_88 ,
V_246 , V_40 ) ;
return V_40 ;
}
V_13 -> V_246 = V_246 ;
if ( F_44 ( V_13 -> V_75 ) ) {
if ( ! F_171 ( & V_60 -> V_61 , V_13 -> V_75 , L_87 ) ) {
F_172 ( F_139 ( V_13 -> V_75 ) ,
V_312 ) ;
V_40 = F_173 ( & V_60 -> V_61 ,
F_139 ( V_13 -> V_75 ) , NULL ,
F_133 , V_313 ,
L_87 , V_13 ) ;
if ( V_40 ) {
V_13 -> V_75 = - V_175 ;
F_121 ( & V_13 -> V_60 -> V_61 ,
L_89
L_90 ) ;
}
} else {
V_13 -> V_75 = - V_124 ;
}
}
V_40 = F_174 ( & V_60 -> V_61 , & V_13 -> V_65 ) ;
if ( V_40 )
return V_40 ;
F_175 ( & V_60 -> V_61 , 1 ) ;
F_33 ( V_13 ) ;
for ( V_38 = 1 ; V_38 < V_13 -> V_260 ; V_38 ++ )
F_25 ( V_13 , & V_13 -> V_3 [ V_38 ] ) ;
return 0 ;
}
static int F_176 ( struct V_281 * V_60 )
{
struct V_37 * V_13 ;
int V_38 ;
V_13 = F_177 ( V_60 ) ;
F_175 ( & V_60 -> V_61 , 0 ) ;
F_178 ( & V_13 -> V_65 ) ;
for ( V_38 = 1 ; V_38 < V_13 -> V_260 ; V_38 ++ )
F_32 ( & V_13 -> V_3 [ V_38 ] ) ;
F_39 ( V_13 ) ;
return 0 ;
}
static int F_179 ( struct V_197 * V_61 )
{
struct V_37 * V_13 = F_180 ( V_61 ) ;
if ( ! V_13 -> V_167 )
return 0 ;
F_134 ( & V_13 -> V_273 ) ;
if ( ! F_181 ( V_61 ) ) {
F_132 ( V_13 ) ;
goto V_42;
}
if ( F_44 ( V_13 -> V_75 ) ) {
F_132 ( V_13 ) ;
F_182 ( F_139 ( V_13 -> V_75 ) ) ;
}
V_42:
F_135 ( & V_13 -> V_273 ) ;
return 0 ;
}
static int F_183 ( struct V_197 * V_61 )
{
struct V_37 * V_13 = F_180 ( V_61 ) ;
if ( ! V_13 -> V_167 )
return 0 ;
if ( F_181 ( V_61 ) && F_44 ( V_13 -> V_75 ) )
F_184 ( F_139 ( V_13 -> V_75 ) ) ;
F_134 ( & V_13 -> V_273 ) ;
V_13 -> V_274 = F_43 ( V_13 ) ;
if ( V_13 -> V_274 )
F_131 ( V_13 ) ;
F_135 ( & V_13 -> V_273 ) ;
return 0 ;
}
