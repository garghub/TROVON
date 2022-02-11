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
int F_40 ( struct V_37 * V_13 )
{
int V_72 ;
switch ( V_73 ) {
default:
V_73 = 0 ;
case 0 :
V_13 -> V_74 = NULL ;
V_72 = 0 ;
break;
case 1 :
V_13 -> V_74 = V_75 ;
V_72 = F_41 ( V_75 ) ;
break;
case 2 :
V_13 -> V_74 = V_76 ;
V_72 = F_41 ( V_76 ) ;
break;
case 3 :
V_13 -> V_74 = V_77 ;
V_72 = F_41 ( V_77 ) ;
break;
case 4 :
V_13 -> V_74 = V_78 ;
V_72 = F_41 ( V_78 ) ;
break;
}
F_42 ( V_79 , L_8 , V_73 ) ;
return V_72 ;
}
static inline T_5 F_43 ( struct V_37 * V_13 )
{
return V_13 -> V_80 ;
}
static inline void F_44 ( struct V_37 * V_13 , T_5 V_81 )
{
F_45 ( V_13 , V_82 , V_81 ) ;
V_13 -> V_80 = V_81 ;
}
static int F_46 ( struct V_37 * V_13 )
{
if ( F_47 ( V_13 -> V_83 ) )
return F_48 ( V_13 -> V_83 ) ^ V_13 -> V_84 ;
return 1 ;
}
static void F_49 ( struct V_37 * V_13 , int V_85 )
{
if ( V_13 -> V_86 && V_13 -> V_86 -> F_49 )
V_13 -> V_86 -> F_49 ( V_13 , V_85 ) ;
}
static void F_50 ( struct V_37 * V_13 )
{
if ( ! V_13 -> V_87 )
return;
if ( V_13 -> V_86 && V_13 -> V_86 -> V_88 )
V_13 -> V_86 -> V_88 ( V_13 ) ;
V_13 -> V_87 = false ;
}
static void F_51 ( struct V_3 * V_4 , struct V_6 * V_7 )
{
unsigned int V_89 ;
V_89 = V_7 -> V_7 . V_29 - V_7 -> V_7 . V_25 ;
V_7 -> V_36 = 1 ;
if ( V_89 > V_4 -> V_4 . V_90 ) {
V_89 = V_4 -> V_4 . V_90 ;
V_7 -> V_36 = 0 ;
} else if ( V_89 == V_4 -> V_4 . V_90 && V_7 -> V_7 . V_31 )
V_7 -> V_36 = 0 ;
F_42 ( V_91 , L_9 ,
V_4 -> V_4 . V_46 , V_7 , V_89 ,
V_7 -> V_36 ? L_10 : L_11 ) ;
F_52 ( V_4 -> V_92 , V_7 -> V_7 . V_19 + V_7 -> V_7 . V_25 , V_89 ) ;
F_53 ( V_4 , V_93 , V_94 ) ;
V_7 -> V_7 . V_25 += V_89 ;
}
static void F_54 ( struct V_3 * V_4 , struct V_6 * V_7 )
{
F_42 ( V_91 , L_12 ,
V_4 -> V_4 . V_46 , V_7 , V_7 -> V_7 . V_29 ) ;
V_7 -> V_7 . V_25 = 0 ;
V_7 -> V_34 = 1 ;
if ( V_7 -> V_35 ) {
if ( V_7 -> V_7 . V_29 == 0 ) {
F_53 ( V_4 , V_95 , V_94 ) ;
return;
}
if ( V_7 -> V_7 . V_31 )
F_53 ( V_4 , V_95 , V_96 ) ;
else
F_53 ( V_4 , V_97 , V_96 ) ;
F_55 ( V_4 , V_98 , V_7 -> V_7 . V_99 ) ;
F_55 ( V_4 , V_100 , V_7 -> V_101 ) ;
} else {
F_51 ( V_4 , V_7 ) ;
if ( V_7 -> V_36 ) {
F_53 ( V_4 , V_97 , V_94 ) ;
F_53 ( V_4 , V_95 , V_102 ) ;
} else {
F_53 ( V_4 , V_97 , V_102 ) ;
F_53 ( V_4 , V_95 , V_94 ) ;
}
}
}
static void F_56 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
if ( F_57 ( & V_4 -> V_17 ) ) {
F_53 ( V_4 , V_97 , V_94 | V_103 ) ;
return;
}
V_7 = F_58 ( V_4 -> V_17 . V_104 , struct V_6 , V_17 ) ;
if ( ! V_7 -> V_34 )
F_54 ( V_4 , V_7 ) ;
}
static void F_59 ( struct V_37 * V_13 , struct V_3 * V_4 )
{
V_4 -> V_58 = V_105 ;
F_53 ( V_4 , V_93 , V_94 ) ;
F_53 ( V_4 , V_95 , V_102 ) ;
}
static void F_60 ( struct V_3 * V_4 )
{
struct V_37 * V_13 = V_4 -> V_13 ;
struct V_6 * V_7 ;
unsigned long V_33 ;
unsigned int V_106 , V_107 ;
int V_108 = 0 ;
V_33 = F_61 ( V_4 , V_109 ) ;
V_107 = F_62 ( V_110 , V_33 ) ;
F_42 ( V_91 , L_13 , V_107 ) ;
while ( V_107 > 0 ) {
if ( F_57 ( & V_4 -> V_17 ) ) {
F_53 ( V_4 , V_97 , V_103 ) ;
break;
}
V_7 = F_58 ( V_4 -> V_17 . V_104 ,
struct V_6 , V_17 ) ;
V_106 = F_62 ( V_111 , V_33 ) ;
if ( V_33 & ( 1 << 31 ) )
V_108 = 1 ;
if ( V_7 -> V_7 . V_25 + V_106 >= V_7 -> V_7 . V_29 ) {
V_108 = 1 ;
V_106 = V_7 -> V_7 . V_29 - V_7 -> V_7 . V_25 ;
}
F_63 ( V_7 -> V_7 . V_19 + V_7 -> V_7 . V_25 ,
V_4 -> V_92 , V_106 ) ;
V_7 -> V_7 . V_25 += V_106 ;
F_53 ( V_4 , V_112 , V_103 ) ;
if ( V_108 ) {
F_42 ( V_91 , L_14 , V_4 -> V_4 . V_46 ) ;
V_7 -> V_7 . V_33 = 0 ;
F_64 ( & V_7 -> V_17 ) ;
F_53 ( V_4 , V_97 , V_103 ) ;
F_65 ( & V_13 -> V_14 ) ;
F_66 ( & V_4 -> V_4 , & V_7 -> V_7 ) ;
F_67 ( & V_13 -> V_14 ) ;
}
V_33 = F_61 ( V_4 , V_109 ) ;
V_107 = F_62 ( V_110 , V_33 ) ;
if ( V_108 && F_29 ( V_4 ) ) {
F_59 ( V_13 , V_4 ) ;
break;
}
}
}
static void
F_68 ( struct V_3 * V_4 , struct V_6 * V_7 , int V_33 )
{
struct V_37 * V_13 = V_4 -> V_13 ;
F_69 ( ! F_57 ( & V_7 -> V_17 ) ) ;
if ( V_7 -> V_7 . V_33 == - V_113 )
V_7 -> V_7 . V_33 = V_33 ;
if ( V_7 -> V_35 )
F_70 ( & V_13 -> V_65 , & V_7 -> V_7 , V_4 -> V_114 ) ;
F_42 ( V_115 | V_116 ,
L_15 ,
V_4 -> V_4 . V_46 , V_7 , V_7 -> V_7 . V_33 , V_7 -> V_7 . V_25 ) ;
F_65 ( & V_13 -> V_14 ) ;
F_66 ( & V_4 -> V_4 , & V_7 -> V_7 ) ;
F_67 ( & V_13 -> V_14 ) ;
}
static void
F_71 ( struct V_3 * V_4 , struct V_9 * V_117 , int V_33 )
{
struct V_6 * V_7 , * V_22 ;
F_9 (req, tmp_req, list, queue) {
F_64 ( & V_7 -> V_17 ) ;
F_68 ( V_4 , V_7 , V_33 ) ;
}
}
static int
F_72 ( struct V_118 * V_119 , const struct V_120 * V_121 )
{
struct V_3 * V_4 = F_38 ( V_119 ) ;
struct V_37 * V_13 = V_4 -> V_13 ;
unsigned long V_122 , V_90 ;
unsigned int V_123 ;
F_42 ( V_115 , L_16 , V_4 -> V_4 . V_46 , V_121 ) ;
V_90 = F_73 ( V_121 ) ;
if ( ( ( V_121 -> V_124 & V_125 ) != V_4 -> V_126 )
|| V_4 -> V_126 == 0
|| V_121 -> V_127 != V_128
|| V_90 == 0
|| V_90 > V_4 -> V_129 ) {
F_42 ( V_130 , L_17 ) ;
return - V_131 ;
}
V_4 -> V_132 = 0 ;
V_4 -> V_114 = 0 ;
F_42 ( V_130 , L_18 ,
V_4 -> V_4 . V_46 , V_4 -> V_133 , V_90 ) ;
if ( F_74 ( V_121 ) ) {
V_4 -> V_114 = 1 ;
V_4 -> V_133 |= V_134 ;
}
switch ( F_75 ( V_121 ) ) {
case V_135 :
V_4 -> V_133 |= F_76 ( V_136 , V_137 ) ;
break;
case V_138 :
if ( ! V_4 -> V_139 ) {
F_42 ( V_130 , L_19 ,
V_4 -> V_4 . V_46 ) ;
return - V_131 ;
}
V_123 = F_77 ( V_121 ) ;
if ( V_123 > 3 )
return - V_131 ;
V_4 -> V_132 = 1 ;
V_4 -> V_133 |= F_76 ( V_136 , V_140 ) ;
V_4 -> V_133 |= F_76 ( V_141 , V_123 ) ;
break;
case V_142 :
V_4 -> V_133 |= F_76 ( V_136 , V_143 ) ;
break;
case V_144 :
V_4 -> V_133 |= F_76 ( V_136 , V_145 ) ;
break;
}
F_78 ( & V_4 -> V_13 -> V_14 , V_122 ) ;
V_4 -> V_4 . V_121 = V_121 ;
V_4 -> V_4 . V_90 = V_90 ;
F_53 ( V_4 , V_146 , V_4 -> V_133 ) ;
F_53 ( V_4 , V_95 , V_147 ) ;
if ( V_4 -> V_53 ) {
T_5 V_101 ;
F_44 ( V_13 , F_43 ( V_13 ) |
F_76 ( V_148 , 1 << V_4 -> V_126 ) |
F_76 ( V_149 , 1 << V_4 -> V_126 ) ) ;
V_101 = V_150 | V_151 ;
F_53 ( V_4 , V_95 , V_101 ) ;
} else {
F_44 ( V_13 , F_43 ( V_13 ) |
F_76 ( V_148 , 1 << V_4 -> V_126 ) ) ;
}
F_79 ( & V_13 -> V_14 , V_122 ) ;
F_42 ( V_79 , L_20 , V_4 -> V_126 ,
( unsigned long ) F_61 ( V_4 , V_146 ) ) ;
F_42 ( V_79 , L_21 ,
( unsigned long ) F_43 ( V_13 ) ) ;
return 0 ;
}
static int F_80 ( struct V_118 * V_119 )
{
struct V_3 * V_4 = F_38 ( V_119 ) ;
struct V_37 * V_13 = V_4 -> V_13 ;
F_81 ( V_152 ) ;
unsigned long V_122 ;
F_42 ( V_115 , L_22 , V_4 -> V_4 . V_46 ) ;
F_78 ( & V_13 -> V_14 , V_122 ) ;
if ( ! V_4 -> V_4 . V_121 ) {
F_79 ( & V_13 -> V_14 , V_122 ) ;
if ( V_13 -> V_65 . V_153 != V_154 )
F_42 ( V_130 , L_23 ,
V_4 -> V_4 . V_46 ) ;
return - V_131 ;
}
V_4 -> V_4 . V_121 = NULL ;
F_82 ( & V_4 -> V_17 , & V_152 ) ;
if ( V_4 -> V_53 ) {
F_55 ( V_4 , V_100 , 0 ) ;
F_55 ( V_4 , V_98 , 0 ) ;
F_83 ( V_4 , V_155 ) ;
}
F_53 ( V_4 , V_97 , V_147 ) ;
F_44 ( V_13 , F_43 ( V_13 ) &
~ F_76 ( V_148 , 1 << V_4 -> V_126 ) ) ;
F_71 ( V_4 , & V_152 , - V_156 ) ;
F_79 ( & V_13 -> V_14 , V_122 ) ;
return 0 ;
}
static struct V_157 *
F_84 ( struct V_118 * V_119 , T_6 V_158 )
{
struct V_6 * V_7 ;
F_42 ( V_115 , L_24 , V_119 , V_158 ) ;
V_7 = F_85 ( sizeof( * V_7 ) , V_158 ) ;
if ( ! V_7 )
return NULL ;
F_3 ( & V_7 -> V_17 ) ;
return & V_7 -> V_7 ;
}
static void
F_86 ( struct V_118 * V_119 , struct V_157 * V_159 )
{
struct V_6 * V_7 = F_87 ( V_159 ) ;
F_42 ( V_115 , L_25 , V_119 , V_159 ) ;
F_11 ( V_7 ) ;
}
static int F_88 ( struct V_37 * V_13 , struct V_3 * V_4 ,
struct V_6 * V_7 , T_6 V_158 )
{
unsigned long V_122 ;
int V_40 ;
F_42 ( V_160 , L_26 ,
V_4 -> V_4 . V_46 , V_7 -> V_7 . V_29 , & V_7 -> V_7 . V_99 ,
V_7 -> V_7 . V_31 ? 'Z' : 'z' ,
V_7 -> V_7 . V_32 ? 'S' : 's' ,
V_7 -> V_7 . V_30 ? 'I' : 'i' ) ;
if ( V_7 -> V_7 . V_29 > 0x10000 ) {
F_42 ( V_130 , L_27 , V_7 -> V_7 . V_29 ) ;
return - V_131 ;
}
V_40 = F_89 ( & V_13 -> V_65 , & V_7 -> V_7 , V_4 -> V_114 ) ;
if ( V_40 )
return V_40 ;
V_7 -> V_35 = 1 ;
V_7 -> V_101 = F_76 ( V_161 , V_7 -> V_7 . V_29 )
| V_162 | V_163
| V_164 ;
if ( ! V_4 -> V_114 )
V_7 -> V_101 |= V_165 | V_166 ;
V_40 = - V_156 ;
F_78 ( & V_13 -> V_14 , V_122 ) ;
if ( V_4 -> V_4 . V_121 ) {
if ( F_57 ( & V_4 -> V_17 ) )
F_54 ( V_4 , V_7 ) ;
F_7 ( & V_7 -> V_17 , & V_4 -> V_17 ) ;
V_40 = 0 ;
}
F_79 ( & V_13 -> V_14 , V_122 ) ;
return V_40 ;
}
static int
F_90 ( struct V_118 * V_119 , struct V_157 * V_159 , T_6 V_158 )
{
struct V_6 * V_7 = F_87 ( V_159 ) ;
struct V_3 * V_4 = F_38 ( V_119 ) ;
struct V_37 * V_13 = V_4 -> V_13 ;
unsigned long V_122 ;
int V_40 ;
F_42 ( V_115 | V_91 | V_116 , L_28 ,
V_4 -> V_4 . V_46 , V_7 , V_159 -> V_29 ) ;
if ( ! V_13 -> V_167 || V_13 -> V_65 . V_153 == V_154 ||
! V_4 -> V_4 . V_121 )
return - V_156 ;
V_7 -> V_34 = 0 ;
V_7 -> V_35 = 0 ;
V_7 -> V_36 = 0 ;
V_159 -> V_33 = - V_113 ;
V_159 -> V_25 = 0 ;
if ( V_4 -> V_53 )
return F_88 ( V_13 , V_4 , V_7 , V_158 ) ;
V_40 = - V_156 ;
F_78 ( & V_13 -> V_14 , V_122 ) ;
if ( V_4 -> V_4 . V_121 ) {
F_7 ( & V_7 -> V_17 , & V_4 -> V_17 ) ;
if ( ( ! F_29 ( V_4 ) && V_4 -> V_114 ) ||
( F_29 ( V_4 )
&& ( V_4 -> V_58 == V_168
|| V_4 -> V_58 == V_105 ) ) )
F_53 ( V_4 , V_95 , V_94 ) ;
else
F_53 ( V_4 , V_95 , V_103 ) ;
V_40 = 0 ;
}
F_79 ( & V_13 -> V_14 , V_122 ) ;
return V_40 ;
}
static void
F_91 ( struct V_3 * V_4 , struct V_6 * V_7 , T_5 V_33 )
{
V_7 -> V_7 . V_25 = V_7 -> V_7 . V_29 - F_62 ( V_161 , V_33 ) ;
}
static int F_92 ( struct V_3 * V_4 , T_5 * V_169 )
{
unsigned int V_170 ;
T_5 V_33 ;
F_55 ( V_4 , V_100 , 0 ) ;
for ( V_170 = 40 ; V_170 ; -- V_170 ) {
V_33 = F_83 ( V_4 , V_155 ) ;
if ( ! ( V_33 & V_162 ) )
break;
F_93 ( 1 ) ;
}
if ( V_169 )
* V_169 = V_33 ;
if ( V_170 == 0 ) {
F_31 ( & V_4 -> V_13 -> V_60 -> V_61 ,
L_29 ,
V_4 -> V_4 . V_46 ) ;
return - V_171 ;
}
return 0 ;
}
static int F_94 ( struct V_118 * V_119 , struct V_157 * V_159 )
{
struct V_3 * V_4 = F_38 ( V_119 ) ;
struct V_37 * V_13 = V_4 -> V_13 ;
struct V_6 * V_7 ;
unsigned long V_122 ;
T_5 V_33 ;
F_42 ( V_115 | V_91 , L_30 ,
V_4 -> V_4 . V_46 , V_7 ) ;
F_78 ( & V_13 -> V_14 , V_122 ) ;
F_5 (req, &ep->queue, queue) {
if ( & V_7 -> V_7 == V_159 )
break;
}
if ( & V_7 -> V_7 != V_159 ) {
F_79 ( & V_13 -> V_14 , V_122 ) ;
return - V_131 ;
}
if ( V_7 -> V_35 ) {
if ( V_4 -> V_17 . V_104 == & V_7 -> V_17 ) {
V_33 = F_83 ( V_4 , V_155 ) ;
if ( V_33 & V_162 )
F_92 ( V_4 , & V_33 ) ;
#ifdef F_95
V_4 -> V_55 = V_33 ;
#endif
F_45 ( V_13 , V_172 , 1 << V_4 -> V_126 ) ;
F_91 ( V_4 , V_7 , V_33 ) ;
}
}
F_64 ( & V_7 -> V_17 ) ;
F_68 ( V_4 , V_7 , - V_173 ) ;
F_56 ( V_4 ) ;
F_79 ( & V_13 -> V_14 , V_122 ) ;
return 0 ;
}
static int F_96 ( struct V_118 * V_119 , int V_174 )
{
struct V_3 * V_4 = F_38 ( V_119 ) ;
struct V_37 * V_13 = V_4 -> V_13 ;
unsigned long V_122 ;
int V_40 = 0 ;
F_42 ( V_115 , L_31 , V_4 -> V_4 . V_46 ,
V_174 ? L_32 : L_33 ) ;
if ( ! V_4 -> V_4 . V_121 ) {
F_42 ( V_130 , L_34 ,
V_4 -> V_4 . V_46 ) ;
return - V_175 ;
}
if ( V_4 -> V_132 ) {
F_42 ( V_130 , L_35 ,
V_4 -> V_4 . V_46 ) ;
return - V_176 ;
}
F_78 ( & V_13 -> V_14 , V_122 ) ;
if ( ! F_57 ( & V_4 -> V_17 )
|| ( ( V_174 && V_4 -> V_114 && ( F_61 ( V_4 , V_109 )
& F_76 ( V_110 , - 1L ) ) ) ) ) {
V_40 = - V_177 ;
} else {
if ( V_174 )
F_53 ( V_4 , V_93 , V_178 ) ;
else
F_53 ( V_4 , V_112 ,
V_178 | V_179 ) ;
F_61 ( V_4 , V_109 ) ;
}
F_79 ( & V_13 -> V_14 , V_122 ) ;
return V_40 ;
}
static int F_97 ( struct V_118 * V_119 )
{
struct V_3 * V_4 = F_38 ( V_119 ) ;
return F_62 ( V_111 , F_61 ( V_4 , V_109 ) ) ;
}
static void F_98 ( struct V_118 * V_119 )
{
struct V_3 * V_4 = F_38 ( V_119 ) ;
struct V_37 * V_13 = V_4 -> V_13 ;
F_45 ( V_13 , V_172 , 1 << V_4 -> V_126 ) ;
}
static int F_99 ( struct V_180 * V_65 )
{
struct V_37 * V_13 = F_100 ( V_65 ) ;
return F_62 ( V_181 , F_101 ( V_13 , V_182 ) ) ;
}
static int F_102 ( struct V_180 * V_65 )
{
struct V_37 * V_13 = F_100 ( V_65 ) ;
unsigned long V_122 ;
T_5 V_101 ;
int V_40 = - V_131 ;
F_78 ( & V_13 -> V_14 , V_122 ) ;
if ( V_13 -> V_183 & ( 1 << V_184 ) ) {
V_101 = F_101 ( V_13 , V_185 ) ;
F_45 ( V_13 , V_185 , V_101 | V_186 ) ;
V_40 = 0 ;
}
F_79 ( & V_13 -> V_14 , V_122 ) ;
return V_40 ;
}
static int
F_103 ( struct V_180 * V_65 , int V_187 )
{
struct V_37 * V_13 = F_100 ( V_65 ) ;
unsigned long V_122 ;
V_65 -> V_187 = ( V_187 != 0 ) ;
F_78 ( & V_13 -> V_14 , V_122 ) ;
if ( V_187 )
V_13 -> V_183 |= 1 << V_188 ;
else
V_13 -> V_183 &= ~ ( 1 << V_188 ) ;
F_79 ( & V_13 -> V_14 , V_122 ) ;
return 0 ;
}
static struct V_118 * F_104 (
struct V_180 * V_65 ,
struct V_120 * V_121 ,
struct V_189 * V_190
)
{
struct V_118 * V_119 ;
struct V_3 * V_4 ;
F_5 (_ep, &gadget->ep_list, ep_list) {
if ( F_105 ( V_65 , V_119 , V_121 , V_190 ) )
goto V_191;
}
return NULL ;
V_191:
if ( V_73 == 0 ) {
V_4 = F_38 ( V_119 ) ;
switch ( F_75 ( V_121 ) ) {
case V_135 :
break;
case V_138 :
V_4 -> V_129 = 1024 ;
V_4 -> V_192 = 2 ;
break;
case V_142 :
V_4 -> V_129 = 512 ;
V_4 -> V_192 = 1 ;
break;
case V_144 :
if ( V_121 -> V_193 == 0 )
V_4 -> V_129 =
F_106 ( V_119 -> V_194 ) ;
else
V_4 -> V_129 =
F_106 ( F_107 ( V_121 -> V_193 ) ) ;
V_4 -> V_192 = 1 ;
break;
}
F_108 ( & V_4 -> V_4 , V_4 -> V_129 ) ;
if ( V_4 -> V_129 <= 8 )
V_4 -> V_133 = F_76 ( V_195 , V_196 ) ;
else
V_4 -> V_133 =
F_76 ( V_195 , F_109 ( V_4 -> V_129 - 1 ) - 3 ) ;
V_4 -> V_133 |= F_76 ( V_197 , V_4 -> V_192 ) ;
V_4 -> V_13 -> V_198 ++ ;
}
return V_119 ;
}
static void F_110 ( struct V_37 * V_13 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 , * V_22 ;
F_45 ( V_13 , V_172 , ~ 0UL ) ;
V_4 = F_38 ( V_13 -> V_65 . V_71 ) ;
F_9 (req, tmp_req, &ep->queue, queue) {
F_64 ( & V_7 -> V_17 ) ;
F_68 ( V_4 , V_7 , - V_173 ) ;
}
}
static struct V_3 * F_111 ( struct V_37 * V_13 , T_7 V_199 )
{
struct V_3 * V_4 ;
if ( ( V_199 & V_125 ) == 0 )
return F_38 ( V_13 -> V_65 . V_71 ) ;
F_5 (ep, &udc->gadget.ep_list, ep.ep_list) {
T_8 V_124 ;
if ( ! V_4 -> V_4 . V_121 )
continue;
V_124 = V_4 -> V_4 . V_121 -> V_124 ;
if ( ( V_199 ^ V_124 ) & V_200 )
continue;
if ( ( V_124 & V_125 )
== ( V_199 & V_125 ) )
return V_4 ;
}
return NULL ;
}
static inline void F_112 ( struct V_37 * V_13 , struct V_3 * V_4 )
{
F_53 ( V_4 , V_93 , V_178 ) ;
V_4 -> V_58 = V_201 ;
}
static inline int F_113 ( struct V_37 * V_13 , struct V_3 * V_4 )
{
if ( F_61 ( V_4 , V_109 ) & V_178 )
return 1 ;
return 0 ;
}
static inline void F_114 ( struct V_37 * V_13 , unsigned int V_202 )
{
T_5 V_203 ;
F_42 ( V_204 , L_36 , V_202 ) ;
V_203 = F_101 ( V_13 , V_185 ) ;
V_203 = F_115 ( V_205 , V_202 , V_203 ) ;
F_45 ( V_13 , V_185 , V_203 ) ;
}
static int F_116 ( struct V_37 * V_13 )
{
static const char V_206 [] = {
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0xAA , 0xAA , 0xAA , 0xAA , 0xAA , 0xAA , 0xAA , 0xAA ,
0xEE , 0xEE , 0xEE , 0xEE , 0xEE , 0xEE , 0xEE , 0xEE ,
0xFE , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF ,
0xFF , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF ,
0x7F , 0xBF , 0xDF , 0xEF , 0xF7 , 0xFB , 0xFD ,
0xFC , 0x7E , 0xBF , 0xDF , 0xEF , 0xF7 , 0xFB , 0xFD , 0x7E
} ;
struct V_3 * V_4 ;
struct V_207 * V_61 = & V_13 -> V_60 -> V_61 ;
int V_208 ;
V_208 = V_13 -> V_208 ;
F_110 ( V_13 ) ;
switch ( V_208 ) {
case 0x0100 :
F_45 ( V_13 , V_209 , V_210 ) ;
F_117 ( V_61 , L_37 ) ;
break;
case 0x0200 :
F_45 ( V_13 , V_209 , V_211 ) ;
F_117 ( V_61 , L_38 ) ;
break;
case 0x0300 :
V_4 = & V_13 -> V_3 [ 0 ] ;
F_45 ( V_13 , V_209 ,
F_76 ( V_212 , V_213 ) ) ;
F_53 ( V_4 , V_146 ,
F_76 ( V_195 , V_214 )
| V_134
| F_76 ( V_136 , V_143 )
| F_76 ( V_197 , 1 ) ) ;
if ( ! ( F_61 ( V_4 , V_146 ) & V_215 ) ) {
F_112 ( V_13 , V_4 ) ;
F_31 ( V_61 , L_39 ) ;
} else {
F_53 ( V_4 , V_95 , V_147 ) ;
F_117 ( V_61 , L_40 ) ;
}
break;
case 0x0400 :
V_4 = & V_13 -> V_3 [ 0 ] ;
F_53 ( V_4 , V_146 ,
F_76 ( V_195 , V_214 )
| V_134
| F_76 ( V_136 , V_143 )
| F_76 ( V_197 , 1 ) ) ;
if ( ! ( F_61 ( V_4 , V_146 ) & V_215 ) ) {
F_112 ( V_13 , V_4 ) ;
F_31 ( V_61 , L_41 ) ;
} else {
F_53 ( V_4 , V_95 , V_147 ) ;
F_45 ( V_13 , V_209 , V_216 ) ;
F_52 ( V_4 -> V_92 , V_206 ,
sizeof( V_206 ) ) ;
F_53 ( V_4 , V_93 , V_94 ) ;
F_117 ( V_61 , L_42 ) ;
}
break;
default:
F_31 ( V_61 , L_43 , V_208 ) ;
return - V_131 ;
}
return 0 ;
}
static inline bool F_118 ( struct V_217 * V_218 )
{
if ( V_218 -> V_219 == F_119 ( V_184 ) )
return true ;
return false ;
}
static inline bool F_120 ( struct V_217 * V_218 )
{
if ( V_218 -> V_219 == F_119 ( V_220 ) )
return true ;
return false ;
}
static inline bool F_121 ( struct V_217 * V_218 )
{
if ( V_218 -> V_219 == F_119 ( V_221 ) )
return true ;
return false ;
}
static int F_122 ( struct V_37 * V_13 , struct V_3 * V_4 ,
struct V_217 * V_218 )
{
int V_222 = 0 ;
switch ( V_218 -> V_223 ) {
case V_224 : {
T_7 V_33 ;
if ( V_218 -> V_225 == ( V_200 | V_226 ) ) {
V_33 = F_119 ( V_13 -> V_183 ) ;
} else if ( V_218 -> V_225
== ( V_200 | V_227 ) ) {
V_33 = F_119 ( 0 ) ;
} else if ( V_218 -> V_225
== ( V_200 | V_228 ) ) {
struct V_3 * V_229 ;
V_229 = F_111 ( V_13 , F_107 ( V_218 -> V_199 ) ) ;
if ( ! V_229 )
goto V_230;
V_33 = 0 ;
if ( F_113 ( V_13 , V_229 ) )
V_33 |= F_119 ( 1 ) ;
} else
goto V_231;
if ( V_218 -> V_232 != F_119 ( sizeof( V_33 ) ) )
goto V_230;
V_4 -> V_58 = V_168 ;
F_123 ( V_33 , V_4 -> V_92 ) ;
F_53 ( V_4 , V_93 , V_94 ) ;
break;
}
case V_233 : {
if ( V_218 -> V_225 == V_226 ) {
if ( F_118 ( V_218 ) )
V_13 -> V_183
&= ~ ( 1 << V_184 ) ;
else
goto V_230;
} else if ( V_218 -> V_225 == V_228 ) {
struct V_3 * V_229 ;
if ( V_218 -> V_232 != F_119 ( 0 )
|| ! F_121 ( V_218 ) )
goto V_230;
V_229 = F_111 ( V_13 , F_107 ( V_218 -> V_199 ) ) ;
if ( ! V_229 )
goto V_230;
F_53 ( V_229 , V_112 , V_178 ) ;
if ( V_229 -> V_126 != 0 )
F_53 ( V_229 , V_112 ,
V_179 ) ;
} else {
goto V_231;
}
F_59 ( V_13 , V_4 ) ;
break;
}
case V_234 : {
if ( V_218 -> V_225 == V_226 ) {
if ( F_120 ( V_218 ) ) {
F_59 ( V_13 , V_4 ) ;
V_4 -> V_58 = V_235 ;
V_13 -> V_208 = F_107 ( V_218 -> V_199 ) ;
return 0 ;
} else if ( F_118 ( V_218 ) ) {
V_13 -> V_183 |= 1 << V_184 ;
} else {
goto V_230;
}
} else if ( V_218 -> V_225 == V_228 ) {
struct V_3 * V_229 ;
if ( V_218 -> V_232 != F_119 ( 0 )
|| ! F_121 ( V_218 ) )
goto V_230;
V_229 = F_111 ( V_13 , F_107 ( V_218 -> V_199 ) ) ;
if ( ! V_229 )
goto V_230;
F_53 ( V_229 , V_93 , V_178 ) ;
} else
goto V_231;
F_59 ( V_13 , V_4 ) ;
break;
}
case V_236 :
if ( V_218 -> V_225 != ( V_237 | V_226 ) )
goto V_231;
F_114 ( V_13 , F_107 ( V_218 -> V_219 ) ) ;
F_59 ( V_13 , V_4 ) ;
V_4 -> V_58 = V_238 ;
break;
default:
V_231:
F_65 ( & V_13 -> V_14 ) ;
V_222 = V_13 -> V_167 -> V_239 ( & V_13 -> V_65 , V_218 ) ;
F_67 ( & V_13 -> V_14 ) ;
}
return V_222 ;
V_230:
F_124 ( L_44
L_45 ,
V_4 -> V_4 . V_46 , V_218 -> V_225 , V_218 -> V_223 ,
F_107 ( V_218 -> V_219 ) , F_107 ( V_218 -> V_199 ) ,
F_107 ( V_218 -> V_232 ) ) ;
F_112 ( V_13 , V_4 ) ;
return - 1 ;
}
static void F_125 ( struct V_37 * V_13 , struct V_3 * V_4 )
{
struct V_6 * V_7 ;
T_5 V_240 ;
T_5 V_241 ;
V_242:
V_240 = F_61 ( V_4 , V_109 ) ;
V_241 = F_61 ( V_4 , V_243 ) ;
F_42 ( V_244 , L_46 ,
V_4 -> V_4 . V_46 , V_4 -> V_58 , V_240 , V_241 ) ;
V_7 = NULL ;
if ( ! F_57 ( & V_4 -> V_17 ) )
V_7 = F_58 ( V_4 -> V_17 . V_104 ,
struct V_6 , V_17 ) ;
if ( ( V_241 & V_94 ) && ! ( V_240 & V_94 ) ) {
if ( V_7 -> V_34 )
F_51 ( V_4 , V_7 ) ;
else
F_54 ( V_4 , V_7 ) ;
if ( V_7 -> V_36 ) {
F_53 ( V_4 , V_97 , V_94 ) ;
F_53 ( V_4 , V_95 , V_102 ) ;
}
goto V_242;
}
if ( ( V_240 & V_241 ) & V_102 ) {
F_53 ( V_4 , V_112 , V_102 ) ;
switch ( V_4 -> V_58 ) {
case V_168 :
F_53 ( V_4 , V_95 , V_103 ) ;
F_53 ( V_4 , V_97 , V_102 ) ;
V_4 -> V_58 = V_245 ;
break;
case V_238 :
F_45 ( V_13 , V_185 , ( F_101 ( V_13 , V_185 )
| V_246 ) ) ;
F_53 ( V_4 , V_97 , V_102 ) ;
V_4 -> V_58 = V_201 ;
break;
case V_105 :
if ( V_7 ) {
F_64 ( & V_7 -> V_17 ) ;
F_68 ( V_4 , V_7 , 0 ) ;
F_56 ( V_4 ) ;
}
F_53 ( V_4 , V_97 , V_102 ) ;
V_4 -> V_58 = V_201 ;
break;
case V_235 :
F_53 ( V_4 , V_97 , V_102 ) ;
V_4 -> V_58 = V_201 ;
if ( F_116 ( V_13 ) )
F_112 ( V_13 , V_4 ) ;
break;
default:
F_124 ( L_47
L_45 ,
V_4 -> V_4 . V_46 , V_4 -> V_58 ) ;
F_112 ( V_13 , V_4 ) ;
break;
}
goto V_242;
}
if ( ( V_240 & V_241 ) & V_103 ) {
switch ( V_4 -> V_58 ) {
case V_245 :
F_53 ( V_4 , V_112 , V_103 ) ;
F_53 ( V_4 , V_97 , V_103 ) ;
if ( V_7 ) {
F_64 ( & V_7 -> V_17 ) ;
F_68 ( V_4 , V_7 , 0 ) ;
}
V_4 -> V_58 = V_201 ;
break;
case V_247 :
F_60 ( V_4 ) ;
break;
default:
F_53 ( V_4 , V_112 , V_103 ) ;
F_53 ( V_4 , V_97 , V_103 ) ;
F_124 ( L_48
L_45 ,
V_4 -> V_4 . V_46 , V_4 -> V_58 ) ;
F_112 ( V_13 , V_4 ) ;
break;
}
goto V_242;
}
if ( V_240 & V_248 ) {
union {
struct V_217 V_218 ;
unsigned long V_39 [ 2 ] ;
} V_218 ;
unsigned int V_249 ;
int V_40 ;
if ( V_4 -> V_58 != V_201 ) {
int V_33 = - V_250 ;
if ( V_4 -> V_58 == V_245
|| V_4 -> V_58 == V_105 ) {
F_53 ( V_4 , V_97 , V_103 ) ;
V_33 = 0 ;
}
if ( V_7 ) {
F_64 ( & V_7 -> V_17 ) ;
F_68 ( V_4 , V_7 , V_33 ) ;
}
}
V_249 = F_62 ( V_111 , F_61 ( V_4 , V_109 ) ) ;
F_42 ( V_79 , L_49 , V_249 ) ;
if ( V_249 != sizeof( V_218 ) ) {
F_126 ( L_50 ,
V_249 , sizeof( V_218 ) ) ;
F_112 ( V_13 , V_4 ) ;
return;
}
F_42 ( V_251 , L_51 , V_4 -> V_92 ) ;
F_63 ( V_218 . V_39 , V_4 -> V_92 , sizeof( V_218 ) ) ;
F_53 ( V_4 , V_112 , V_248 ) ;
if ( V_218 . V_218 . V_225 & V_200 ) {
V_4 -> V_58 = V_168 ;
} else {
if ( V_218 . V_218 . V_232 != F_119 ( 0 ) )
V_4 -> V_58 = V_247 ;
else
V_4 -> V_58 = V_105 ;
}
V_40 = - 1 ;
if ( V_4 -> V_126 == 0 )
V_40 = F_122 ( V_13 , V_4 , & V_218 . V_218 ) ;
else {
F_65 ( & V_13 -> V_14 ) ;
V_40 = V_13 -> V_167 -> V_239 ( & V_13 -> V_65 , & V_218 . V_218 ) ;
F_67 ( & V_13 -> V_14 ) ;
}
F_42 ( V_204 , L_52 ,
V_218 . V_218 . V_225 , V_218 . V_218 . V_223 ,
F_107 ( V_218 . V_218 . V_232 ) , V_4 -> V_58 , V_40 ) ;
if ( V_40 < 0 ) {
F_112 ( V_13 , V_4 ) ;
}
}
}
static void F_127 ( struct V_37 * V_13 , struct V_3 * V_4 )
{
struct V_6 * V_7 ;
T_5 V_240 ;
T_5 V_241 ;
V_240 = F_61 ( V_4 , V_109 ) ;
V_241 = F_61 ( V_4 , V_243 ) ;
F_42 ( V_244 , L_53 , V_4 -> V_4 . V_46 , V_240 ) ;
while ( ( V_241 & V_94 ) && ! ( V_240 & V_94 ) ) {
F_42 ( V_204 , L_54 , V_4 -> V_4 . V_46 ) ;
if ( F_57 ( & V_4 -> V_17 ) ) {
F_128 ( & V_13 -> V_60 -> V_61 , L_55 ) ;
F_53 ( V_4 , V_97 , V_94 ) ;
return;
}
V_7 = F_58 ( V_4 -> V_17 . V_104 , struct V_6 , V_17 ) ;
if ( V_7 -> V_35 ) {
F_53 ( V_4 , V_93 ,
V_94 ) ;
F_53 ( V_4 , V_97 ,
V_94 ) ;
F_64 ( & V_7 -> V_17 ) ;
F_56 ( V_4 ) ;
F_68 ( V_4 , V_7 , 0 ) ;
} else {
if ( V_7 -> V_34 )
F_51 ( V_4 , V_7 ) ;
else
F_54 ( V_4 , V_7 ) ;
if ( V_7 -> V_36 ) {
F_64 ( & V_7 -> V_17 ) ;
F_56 ( V_4 ) ;
F_68 ( V_4 , V_7 , 0 ) ;
}
}
V_240 = F_61 ( V_4 , V_109 ) ;
V_241 = F_61 ( V_4 , V_243 ) ;
}
if ( ( V_240 & V_241 ) & V_103 ) {
F_42 ( V_204 , L_56 , V_4 -> V_4 . V_46 ) ;
F_60 ( V_4 ) ;
}
}
static void F_129 ( struct V_37 * V_13 , struct V_3 * V_4 )
{
struct V_6 * V_7 ;
T_5 V_33 , V_252 , V_253 ;
V_33 = F_83 ( V_4 , V_155 ) ;
V_252 = F_83 ( V_4 , V_100 ) ;
#ifdef F_95
V_4 -> V_55 = V_33 ;
#endif
V_253 = V_33 & V_252 ;
F_42 ( V_244 | V_160 , L_57 , V_33 , V_252 ) ;
if ( V_33 & V_162 ) {
F_31 ( & V_13 -> V_60 -> V_61 ,
L_58 ) ;
F_31 ( & V_13 -> V_60 -> V_61 ,
L_59 ,
V_33 , V_253 , V_252 ) ;
}
if ( F_57 ( & V_4 -> V_17 ) )
return;
if ( V_253 & ( V_254 | V_255 ) ) {
V_7 = F_58 ( V_4 -> V_17 . V_104 , struct V_6 , V_17 ) ;
F_91 ( V_4 , V_7 , V_33 ) ;
F_64 ( & V_7 -> V_17 ) ;
F_56 ( V_4 ) ;
F_68 ( V_4 , V_7 , 0 ) ;
}
}
static T_9 F_130 ( int V_256 , void * V_257 )
{
struct V_37 * V_13 = V_257 ;
T_5 V_33 , V_258 ;
T_5 V_259 ;
T_5 V_260 ;
F_67 ( & V_13 -> V_14 ) ;
V_258 = F_43 ( V_13 ) ;
V_33 = F_101 ( V_13 , V_261 ) & ( V_258 | V_262 ) ;
F_42 ( V_244 , L_60 , V_33 ) ;
if ( V_33 & V_263 ) {
F_49 ( V_13 , 0 ) ;
F_45 ( V_13 , V_264 , V_263 ) ;
F_44 ( V_13 , V_258 | V_265 ) ;
V_13 -> V_87 = true ;
F_42 ( V_204 , L_61 ) ;
if ( V_13 -> V_65 . V_153 != V_154
&& V_13 -> V_167 && V_13 -> V_167 -> V_266 ) {
F_65 ( & V_13 -> V_14 ) ;
V_13 -> V_167 -> V_266 ( & V_13 -> V_65 ) ;
F_67 ( & V_13 -> V_14 ) ;
}
}
if ( V_33 & V_265 ) {
F_49 ( V_13 , 1 ) ;
F_45 ( V_13 , V_264 , V_265 ) ;
F_44 ( V_13 , V_258 & ~ V_265 ) ;
F_42 ( V_204 , L_62 ) ;
}
if ( V_33 & V_267 ) {
F_45 ( V_13 , V_264 , V_267 ) ;
F_50 ( V_13 ) ;
F_42 ( V_204 , L_63 ) ;
if ( V_13 -> V_65 . V_153 != V_154
&& V_13 -> V_167 && V_13 -> V_167 -> V_268 ) {
F_65 ( & V_13 -> V_14 ) ;
V_13 -> V_167 -> V_268 ( & V_13 -> V_65 ) ;
F_67 ( & V_13 -> V_14 ) ;
}
}
V_259 = F_62 ( V_149 , V_33 ) ;
if ( V_259 ) {
int V_38 ;
for ( V_38 = 1 ; V_38 <= V_269 ; V_38 ++ )
if ( V_259 & ( 1 << V_38 ) )
F_129 ( V_13 , & V_13 -> V_3 [ V_38 ] ) ;
}
V_260 = F_62 ( V_148 , V_33 ) ;
if ( V_260 ) {
int V_38 ;
for ( V_38 = 0 ; V_38 < V_13 -> V_270 ; V_38 ++ )
if ( V_260 & ( 1 << V_38 ) ) {
if ( F_29 ( & V_13 -> V_3 [ V_38 ] ) )
F_125 ( V_13 , & V_13 -> V_3 [ V_38 ] ) ;
else
F_127 ( V_13 , & V_13 -> V_3 [ V_38 ] ) ;
}
}
if ( V_33 & V_271 ) {
struct V_3 * V_71 , * V_4 ;
int V_38 , V_72 ;
F_45 ( V_13 , V_264 , V_271 ) ;
F_50 ( V_13 ) ;
F_110 ( V_13 ) ;
if ( V_13 -> V_65 . V_153 != V_154 && V_13 -> V_167 ) {
V_13 -> V_65 . V_153 = V_154 ;
F_65 ( & V_13 -> V_14 ) ;
F_131 ( & V_13 -> V_65 , V_13 -> V_167 ) ;
F_67 ( & V_13 -> V_14 ) ;
}
if ( V_33 & V_262 )
V_13 -> V_65 . V_153 = V_272 ;
else
V_13 -> V_65 . V_153 = V_273 ;
F_42 ( V_204 , L_64 ,
F_132 ( V_13 -> V_65 . V_153 ) ) ;
V_71 = & V_13 -> V_3 [ 0 ] ;
V_71 -> V_4 . V_121 = & V_274 ;
V_71 -> V_58 = V_201 ;
F_53 ( V_71 , V_146 ,
( F_76 ( V_195 , V_275 )
| F_76 ( V_136 , V_137 )
| F_76 ( V_197 , V_276 ) ) ) ;
F_53 ( V_71 , V_95 ,
V_147 | V_248 ) ;
F_44 ( V_13 , V_258 | F_76 ( V_148 , 1 ) |
V_263 | V_267 ) ;
if ( ! ( F_61 ( V_71 , V_146 ) & V_215 ) )
F_133 ( & V_13 -> V_60 -> V_61 ,
L_65 ) ;
V_72 = V_73 ? V_13 -> V_270 : V_13 -> V_198 ;
for ( V_38 = 1 ; V_38 < V_72 ; V_38 ++ ) {
V_4 = & V_13 -> V_3 [ V_38 ] ;
F_53 ( V_4 , V_146 , V_4 -> V_133 ) ;
if ( ! ( F_61 ( V_4 , V_146 ) & V_215 ) )
F_133 ( & V_13 -> V_60 -> V_61 ,
L_66 , V_38 ) ;
}
}
F_65 ( & V_13 -> V_14 ) ;
return V_277 ;
}
static int F_134 ( struct V_37 * V_13 )
{
int V_40 ;
if ( V_13 -> V_278 )
return 0 ;
V_40 = F_135 ( V_13 -> V_279 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_135 ( V_13 -> V_280 ) ;
if ( V_40 ) {
F_136 ( V_13 -> V_279 ) ;
return V_40 ;
}
V_13 -> V_278 = true ;
return 0 ;
}
static void F_137 ( struct V_37 * V_13 )
{
if ( ! V_13 -> V_278 )
return;
F_136 ( V_13 -> V_280 ) ;
F_136 ( V_13 -> V_279 ) ;
V_13 -> V_278 = false ;
}
static int F_138 ( struct V_37 * V_13 )
{
unsigned long V_122 ;
int V_40 ;
V_40 = F_134 ( V_13 ) ;
if ( V_40 )
return V_40 ;
F_78 ( & V_13 -> V_14 , V_122 ) ;
F_49 ( V_13 , 1 ) ;
F_45 ( V_13 , V_185 , V_281 ) ;
F_44 ( V_13 , V_271 ) ;
F_79 ( & V_13 -> V_14 , V_122 ) ;
return 0 ;
}
static void F_139 ( struct V_37 * V_13 )
{
unsigned long V_122 ;
F_78 ( & V_13 -> V_14 , V_122 ) ;
V_13 -> V_65 . V_153 = V_154 ;
F_110 ( V_13 ) ;
F_49 ( V_13 , 0 ) ;
F_45 ( V_13 , V_185 , V_282 ) ;
F_79 ( & V_13 -> V_14 , V_122 ) ;
F_137 ( V_13 ) ;
}
static T_9 F_140 ( int V_256 , void * V_257 )
{
struct V_37 * V_13 = V_257 ;
int V_283 ;
F_93 ( 10 ) ;
F_141 ( & V_13 -> V_284 ) ;
V_283 = F_46 ( V_13 ) ;
if ( V_283 != V_13 -> V_285 ) {
if ( V_283 ) {
F_138 ( V_13 ) ;
} else {
F_139 ( V_13 ) ;
if ( V_13 -> V_167 -> V_286 )
V_13 -> V_167 -> V_286 ( & V_13 -> V_65 ) ;
}
V_13 -> V_285 = V_283 ;
}
F_142 ( & V_13 -> V_284 ) ;
return V_277 ;
}
static int F_143 ( struct V_180 * V_65 ,
struct V_287 * V_167 )
{
int V_40 ;
struct V_37 * V_13 = F_144 ( V_65 , struct V_37 , V_65 ) ;
unsigned long V_122 ;
F_78 ( & V_13 -> V_14 , V_122 ) ;
V_13 -> V_183 = 1 << V_188 ;
V_13 -> V_167 = V_167 ;
F_79 ( & V_13 -> V_14 , V_122 ) ;
F_141 ( & V_13 -> V_284 ) ;
if ( F_47 ( V_13 -> V_83 ) )
F_145 ( F_146 ( V_13 -> V_83 ) ) ;
V_13 -> V_285 = F_46 ( V_13 ) ;
if ( V_13 -> V_285 ) {
V_40 = F_138 ( V_13 ) ;
if ( V_40 )
goto V_288;
}
F_142 ( & V_13 -> V_284 ) ;
return 0 ;
V_288:
if ( F_47 ( V_13 -> V_83 ) )
F_147 ( F_146 ( V_13 -> V_83 ) ) ;
F_142 ( & V_13 -> V_284 ) ;
F_78 ( & V_13 -> V_14 , V_122 ) ;
V_13 -> V_183 &= ~ ( 1 << V_188 ) ;
V_13 -> V_167 = NULL ;
F_79 ( & V_13 -> V_14 , V_122 ) ;
return V_40 ;
}
static int F_148 ( struct V_180 * V_65 )
{
struct V_37 * V_13 = F_144 ( V_65 , struct V_37 , V_65 ) ;
if ( F_47 ( V_13 -> V_83 ) )
F_147 ( F_146 ( V_13 -> V_83 ) ) ;
if ( V_73 == 0 )
V_13 -> V_198 = 1 ;
F_139 ( V_13 ) ;
V_13 -> V_167 = NULL ;
return 0 ;
}
static void F_149 ( struct V_37 * V_13 , int V_85 )
{
F_150 ( V_13 -> V_289 , V_290 , V_291 ,
V_85 ? V_291 : 0 ) ;
}
static void F_151 ( struct V_37 * V_13 )
{
F_150 ( V_13 -> V_289 , V_290 , V_291 , 0 ) ;
F_150 ( V_13 -> V_289 , V_290 , V_291 ,
V_291 ) ;
}
static struct V_3 * F_152 ( struct V_292 * V_60 ,
struct V_37 * V_13 )
{
T_5 V_81 ;
const char * V_46 ;
enum V_293 V_122 ;
struct V_294 * V_295 = V_60 -> V_61 . V_296 ;
const struct V_297 * V_298 ;
struct V_294 * V_299 ;
int V_38 , V_40 ;
struct V_3 * V_300 , * V_4 ;
V_298 = F_153 ( V_301 , V_295 ) ;
if ( ! V_298 )
return F_154 ( - V_131 ) ;
V_13 -> V_86 = V_298 -> V_39 ;
V_13 -> V_289 = F_155 ( L_67 ) ;
if ( F_34 ( V_13 -> V_289 ) )
V_13 -> V_289 = F_155 ( L_68 ) ;
if ( V_13 -> V_86 && F_34 ( V_13 -> V_289 ) )
return F_156 ( V_13 -> V_289 ) ;
V_13 -> V_270 = 0 ;
V_13 -> V_83 = F_157 ( V_295 , L_69 , 0 ,
& V_122 ) ;
V_13 -> V_84 = ( V_122 & V_302 ) ? 1 : 0 ;
if ( V_73 == 0 ) {
V_299 = NULL ;
while ( ( V_299 = F_158 ( V_295 , V_299 ) ) )
V_13 -> V_270 ++ ;
V_13 -> V_198 = 1 ;
} else
V_13 -> V_270 = F_40 ( V_13 ) ;
V_300 = F_159 ( & V_60 -> V_61 , sizeof( struct V_3 ) * V_13 -> V_270 ,
V_11 ) ;
if ( ! V_300 )
return F_154 ( - V_12 ) ;
V_13 -> V_65 . V_71 = & V_300 [ 0 ] . V_4 ;
F_3 ( & V_300 [ 0 ] . V_4 . V_303 ) ;
V_299 = NULL ;
V_38 = 0 ;
while ( ( V_299 = F_158 ( V_295 , V_299 ) ) && V_38 < V_13 -> V_270 ) {
V_4 = & V_300 [ V_38 ] ;
V_40 = F_160 ( V_299 , L_70 , & V_81 ) ;
if ( V_40 ) {
F_31 ( & V_60 -> V_61 , L_71 , V_40 ) ;
goto V_288;
}
V_4 -> V_126 = V_73 ? V_13 -> V_74 [ V_38 ] . V_304 : V_81 ;
V_40 = F_160 ( V_299 , L_72 , & V_81 ) ;
if ( V_40 ) {
F_31 ( & V_60 -> V_61 , L_73 , V_40 ) ;
goto V_288;
}
V_4 -> V_129 = V_73 ? V_13 -> V_74 [ V_38 ] . V_129 : V_81 ;
V_40 = F_160 ( V_299 , L_74 , & V_81 ) ;
if ( V_40 ) {
F_31 ( & V_60 -> V_61 , L_75 , V_40 ) ;
goto V_288;
}
V_4 -> V_192 = V_73 ? V_13 -> V_74 [ V_38 ] . V_192 : V_81 ;
V_4 -> V_53 = F_161 ( V_299 , L_76 ) ;
V_4 -> V_139 = F_161 ( V_299 , L_77 ) ;
V_40 = F_162 ( V_299 , L_78 , & V_46 ) ;
if ( V_40 ) {
F_31 ( & V_60 -> V_61 , L_79 , V_40 ) ;
goto V_288;
}
sprintf ( V_4 -> V_46 , L_80 , V_4 -> V_126 ) ;
V_4 -> V_4 . V_46 = V_4 -> V_46 ;
V_4 -> V_305 = V_13 -> V_43 + F_163 ( V_38 ) ;
V_4 -> V_306 = V_13 -> V_43 + F_164 ( V_38 ) ;
V_4 -> V_92 = V_13 -> V_92 + F_165 ( V_38 ) ;
V_4 -> V_4 . V_307 = & V_308 ;
F_108 ( & V_4 -> V_4 , V_4 -> V_129 ) ;
V_4 -> V_13 = V_13 ;
F_3 ( & V_4 -> V_17 ) ;
if ( V_4 -> V_126 == 0 ) {
V_4 -> V_4 . V_309 . V_310 = true ;
} else {
V_4 -> V_4 . V_309 . V_311 = V_4 -> V_139 ;
V_4 -> V_4 . V_309 . V_312 = true ;
V_4 -> V_4 . V_309 . V_313 = true ;
}
V_4 -> V_4 . V_309 . V_314 = true ;
V_4 -> V_4 . V_309 . V_315 = true ;
if ( V_73 != 0 ) {
if ( V_4 -> V_129 <= 8 )
V_4 -> V_133 = F_76 ( V_195 , V_196 ) ;
else
V_4 -> V_133 =
F_76 ( V_195 , F_109 ( V_4 -> V_129 - 1 ) - 3 ) ;
V_4 -> V_133 |= F_76 ( V_197 , V_4 -> V_192 ) ;
}
if ( V_38 )
F_7 ( & V_4 -> V_4 . V_303 , & V_13 -> V_65 . V_303 ) ;
V_38 ++ ;
}
if ( V_38 == 0 ) {
F_31 ( & V_60 -> V_61 , L_81 ) ;
V_40 = - V_131 ;
goto V_288;
}
return V_300 ;
V_288:
return F_154 ( V_40 ) ;
}
static struct V_3 * F_152 ( struct V_292 * V_60 ,
struct V_37 * V_13 )
{
return F_154 ( - V_316 ) ;
}
static struct V_3 * F_166 ( struct V_292 * V_60 ,
struct V_37 * V_13 )
{
struct V_317 * V_318 = F_167 ( & V_60 -> V_61 ) ;
struct V_3 * V_300 ;
int V_38 ;
if ( ! V_318 )
return F_154 ( - V_319 ) ;
V_300 = F_159 ( & V_60 -> V_61 , sizeof( struct V_3 ) * V_318 -> V_270 ,
V_11 ) ;
if ( ! V_300 )
return F_154 ( - V_12 ) ;
V_13 -> V_65 . V_71 = & V_300 [ 0 ] . V_4 ;
V_13 -> V_83 = V_318 -> V_83 ;
V_13 -> V_84 = V_318 -> V_84 ;
V_13 -> V_270 = V_318 -> V_270 ;
F_3 ( & V_300 [ 0 ] . V_4 . V_303 ) ;
for ( V_38 = 0 ; V_38 < V_318 -> V_270 ; V_38 ++ ) {
struct V_3 * V_4 = & V_300 [ V_38 ] ;
V_4 -> V_305 = V_13 -> V_43 + F_163 ( V_38 ) ;
V_4 -> V_306 = V_13 -> V_43 + F_164 ( V_38 ) ;
V_4 -> V_92 = V_13 -> V_92 + F_165 ( V_38 ) ;
V_4 -> V_4 . V_307 = & V_308 ;
V_4 -> V_4 . V_46 = V_318 -> V_4 [ V_38 ] . V_46 ;
V_4 -> V_129 = V_318 -> V_4 [ V_38 ] . V_129 ;
F_108 ( & V_4 -> V_4 , V_4 -> V_129 ) ;
V_4 -> V_13 = V_13 ;
F_3 ( & V_4 -> V_17 ) ;
V_4 -> V_192 = V_318 -> V_4 [ V_38 ] . V_192 ;
V_4 -> V_126 = V_318 -> V_4 [ V_38 ] . V_126 ;
V_4 -> V_53 = V_318 -> V_4 [ V_38 ] . V_53 ;
V_4 -> V_139 = V_318 -> V_4 [ V_38 ] . V_139 ;
if ( V_38 == 0 ) {
V_4 -> V_4 . V_309 . V_310 = true ;
} else {
V_4 -> V_4 . V_309 . V_311 = V_4 -> V_139 ;
V_4 -> V_4 . V_309 . V_312 = true ;
V_4 -> V_4 . V_309 . V_313 = true ;
}
V_4 -> V_4 . V_309 . V_314 = true ;
V_4 -> V_4 . V_309 . V_315 = true ;
if ( V_38 )
F_7 ( & V_4 -> V_4 . V_303 , & V_13 -> V_65 . V_303 ) ;
}
return V_300 ;
}
static int F_168 ( struct V_292 * V_60 )
{
struct V_63 * V_43 , * V_92 ;
struct V_320 * V_279 , * V_280 ;
struct V_37 * V_13 ;
int V_256 , V_40 , V_38 ;
V_13 = F_159 ( & V_60 -> V_61 , sizeof( * V_13 ) , V_11 ) ;
if ( ! V_13 )
return - V_12 ;
V_13 -> V_65 = V_321 ;
F_3 ( & V_13 -> V_65 . V_303 ) ;
V_43 = F_35 ( V_60 , V_66 , V_67 ) ;
V_92 = F_35 ( V_60 , V_66 , V_322 ) ;
if ( ! V_43 || ! V_92 )
return - V_319 ;
V_256 = F_169 ( V_60 , 0 ) ;
if ( V_256 < 0 )
return V_256 ;
V_279 = F_170 ( & V_60 -> V_61 , L_82 ) ;
if ( F_34 ( V_279 ) )
return F_171 ( V_279 ) ;
V_280 = F_170 ( & V_60 -> V_61 , L_83 ) ;
if ( F_34 ( V_280 ) )
return F_171 ( V_280 ) ;
F_172 ( & V_13 -> V_14 ) ;
F_173 ( & V_13 -> V_284 ) ;
V_13 -> V_60 = V_60 ;
V_13 -> V_279 = V_279 ;
V_13 -> V_280 = V_280 ;
V_13 -> V_83 = - V_175 ;
V_40 = - V_12 ;
V_13 -> V_43 = F_174 ( & V_60 -> V_61 , V_43 -> V_323 , F_37 ( V_43 ) ) ;
if ( ! V_13 -> V_43 ) {
F_31 ( & V_60 -> V_61 , L_84 ) ;
return V_40 ;
}
F_117 ( & V_60 -> V_61 , L_85 ,
( unsigned long ) V_43 -> V_323 , V_13 -> V_43 ) ;
V_13 -> V_92 = F_174 ( & V_60 -> V_61 , V_92 -> V_323 , F_37 ( V_92 ) ) ;
if ( ! V_13 -> V_92 ) {
F_31 ( & V_60 -> V_61 , L_86 ) ;
return V_40 ;
}
F_117 ( & V_60 -> V_61 , L_87 ,
( unsigned long ) V_92 -> V_323 , V_13 -> V_92 ) ;
F_175 ( V_60 , V_13 ) ;
V_40 = F_135 ( V_279 ) ;
if ( V_40 ) {
F_31 ( & V_60 -> V_61 , L_88 ) ;
return V_40 ;
}
F_45 ( V_13 , V_185 , V_282 ) ;
F_136 ( V_279 ) ;
if ( V_60 -> V_61 . V_296 )
V_13 -> V_3 = F_152 ( V_60 , V_13 ) ;
else
V_13 -> V_3 = F_166 ( V_60 , V_13 ) ;
F_49 ( V_13 , 0 ) ;
if ( F_34 ( V_13 -> V_3 ) )
return F_171 ( V_13 -> V_3 ) ;
V_40 = F_176 ( & V_60 -> V_61 , V_256 , F_130 , 0 ,
L_89 , V_13 ) ;
if ( V_40 ) {
F_31 ( & V_60 -> V_61 , L_90 ,
V_256 , V_40 ) ;
return V_40 ;
}
V_13 -> V_256 = V_256 ;
if ( F_47 ( V_13 -> V_83 ) ) {
if ( ! F_177 ( & V_60 -> V_61 , V_13 -> V_83 , L_89 ) ) {
F_178 ( F_146 ( V_13 -> V_83 ) ,
V_324 ) ;
V_40 = F_179 ( & V_60 -> V_61 ,
F_146 ( V_13 -> V_83 ) , NULL ,
F_140 , V_325 ,
L_89 , V_13 ) ;
if ( V_40 ) {
V_13 -> V_83 = - V_175 ;
F_128 ( & V_13 -> V_60 -> V_61 ,
L_91
L_92 ) ;
}
} else {
V_13 -> V_83 = - V_131 ;
}
}
V_40 = F_180 ( & V_60 -> V_61 , & V_13 -> V_65 ) ;
if ( V_40 )
return V_40 ;
F_181 ( & V_60 -> V_61 , 1 ) ;
F_33 ( V_13 ) ;
for ( V_38 = 1 ; V_38 < V_13 -> V_270 ; V_38 ++ )
F_25 ( V_13 , & V_13 -> V_3 [ V_38 ] ) ;
return 0 ;
}
static int F_182 ( struct V_292 * V_60 )
{
struct V_37 * V_13 ;
int V_38 ;
V_13 = F_183 ( V_60 ) ;
F_181 ( & V_60 -> V_61 , 0 ) ;
F_184 ( & V_13 -> V_65 ) ;
for ( V_38 = 1 ; V_38 < V_13 -> V_270 ; V_38 ++ )
F_32 ( & V_13 -> V_3 [ V_38 ] ) ;
F_39 ( V_13 ) ;
return 0 ;
}
static int F_185 ( struct V_207 * V_61 )
{
struct V_37 * V_13 = F_186 ( V_61 ) ;
if ( ! V_13 -> V_167 )
return 0 ;
F_141 ( & V_13 -> V_284 ) ;
if ( ! F_187 ( V_61 ) ) {
F_139 ( V_13 ) ;
goto V_42;
}
if ( F_47 ( V_13 -> V_83 ) ) {
F_139 ( V_13 ) ;
F_188 ( F_146 ( V_13 -> V_83 ) ) ;
}
V_42:
F_142 ( & V_13 -> V_284 ) ;
return 0 ;
}
static int F_189 ( struct V_207 * V_61 )
{
struct V_37 * V_13 = F_186 ( V_61 ) ;
if ( ! V_13 -> V_167 )
return 0 ;
if ( F_187 ( V_61 ) && F_47 ( V_13 -> V_83 ) )
F_190 ( F_146 ( V_13 -> V_83 ) ) ;
F_141 ( & V_13 -> V_284 ) ;
V_13 -> V_285 = F_46 ( V_13 ) ;
if ( V_13 -> V_285 )
F_138 ( V_13 ) ;
F_142 ( & V_13 -> V_284 ) ;
return 0 ;
}
