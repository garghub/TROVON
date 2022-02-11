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
V_44 = F_27 ( L_6 , 0400 , V_63 , V_13 , & V_67 ) ;
if ( ! V_44 )
goto V_68;
V_65 = F_35 ( V_13 -> V_61 , V_69 ,
V_70 ) ;
V_44 -> V_71 -> V_42 = F_36 ( V_65 ) ;
V_13 -> V_72 = V_44 ;
F_25 ( V_13 , F_37 ( V_13 -> V_66 . V_73 ) ) ;
return;
V_68:
F_30 ( V_63 ) ;
V_49:
V_13 -> V_48 = NULL ;
F_31 ( & V_13 -> V_61 -> V_62 , L_7 ) ;
}
static void F_38 ( struct V_38 * V_13 )
{
F_32 ( F_37 ( V_13 -> V_66 . V_73 ) ) ;
F_30 ( V_13 -> V_72 ) ;
F_30 ( V_13 -> V_48 ) ;
V_13 -> V_72 = NULL ;
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
static inline void F_38 ( struct V_38 * V_13 )
{
}
static int F_39 ( struct V_38 * V_13 )
{
if ( F_40 ( V_13 -> V_74 ) )
return F_41 ( V_13 -> V_74 ) ^ V_13 -> V_75 ;
return 1 ;
}
static void F_42 ( int V_76 )
{
unsigned int V_77 = F_43 ( V_78 ) ;
if ( V_76 )
F_44 ( V_78 , V_77 | V_79 ) ;
else
F_44 ( V_78 , V_77 & ~ ( V_79 ) ) ;
}
static void F_42 ( int V_76 )
{
}
static void F_45 ( struct V_3 * V_4 , struct V_6 * V_7 )
{
unsigned int V_80 ;
V_80 = V_7 -> V_7 . V_30 - V_7 -> V_7 . V_25 ;
V_7 -> V_37 = 1 ;
if ( V_80 > V_4 -> V_4 . V_81 ) {
V_80 = V_4 -> V_4 . V_81 ;
V_7 -> V_37 = 0 ;
} else if ( V_80 == V_4 -> V_4 . V_81 && V_7 -> V_7 . V_32 )
V_7 -> V_37 = 0 ;
F_46 ( V_82 , L_8 ,
V_4 -> V_4 . V_47 , V_7 , V_80 ,
V_7 -> V_37 ? L_9 : L_10 ) ;
F_47 ( V_4 -> V_83 , V_7 -> V_7 . V_19 + V_7 -> V_7 . V_25 , V_80 ) ;
F_48 ( V_4 , V_84 , V_85 ) ;
V_7 -> V_7 . V_25 += V_80 ;
}
static void F_49 ( struct V_3 * V_4 , struct V_6 * V_7 )
{
F_46 ( V_82 , L_11 ,
V_4 -> V_4 . V_47 , V_7 , V_7 -> V_7 . V_30 ) ;
V_7 -> V_7 . V_25 = 0 ;
V_7 -> V_35 = 1 ;
if ( V_7 -> V_36 ) {
if ( V_7 -> V_7 . V_30 == 0 ) {
F_48 ( V_4 , V_86 , V_85 ) ;
return;
}
if ( V_7 -> V_7 . V_32 )
F_48 ( V_4 , V_86 , V_87 ) ;
else
F_48 ( V_4 , V_88 , V_87 ) ;
F_50 ( V_4 , V_89 , V_7 -> V_7 . V_90 ) ;
F_50 ( V_4 , V_91 , V_7 -> V_92 ) ;
} else {
F_45 ( V_4 , V_7 ) ;
if ( V_7 -> V_37 ) {
F_48 ( V_4 , V_88 , V_85 ) ;
F_48 ( V_4 , V_86 , V_93 ) ;
} else {
F_48 ( V_4 , V_88 , V_93 ) ;
F_48 ( V_4 , V_86 , V_85 ) ;
}
}
}
static void F_51 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
if ( F_52 ( & V_4 -> V_17 ) ) {
F_48 ( V_4 , V_88 , V_85 | V_94 ) ;
return;
}
V_7 = F_53 ( V_4 -> V_17 . V_95 , struct V_6 , V_17 ) ;
if ( ! V_7 -> V_35 )
F_49 ( V_4 , V_7 ) ;
}
static void F_54 ( struct V_38 * V_13 , struct V_3 * V_4 )
{
V_4 -> V_59 = V_96 ;
F_48 ( V_4 , V_84 , V_85 ) ;
F_48 ( V_4 , V_86 , V_93 ) ;
}
static void F_55 ( struct V_3 * V_4 )
{
struct V_38 * V_13 = V_4 -> V_13 ;
struct V_6 * V_7 ;
unsigned long V_34 ;
unsigned int V_97 , V_98 ;
int V_99 = 0 ;
V_34 = F_56 ( V_4 , V_100 ) ;
V_98 = F_57 ( V_101 , V_34 ) ;
F_46 ( V_82 , L_12 , V_98 ) ;
while ( V_98 > 0 ) {
if ( F_52 ( & V_4 -> V_17 ) ) {
F_48 ( V_4 , V_88 , V_94 ) ;
break;
}
V_7 = F_53 ( V_4 -> V_17 . V_95 ,
struct V_6 , V_17 ) ;
V_97 = F_57 ( V_102 , V_34 ) ;
if ( V_34 & ( 1 << 31 ) )
V_99 = 1 ;
if ( V_7 -> V_7 . V_25 + V_97 >= V_7 -> V_7 . V_30 ) {
V_99 = 1 ;
V_97 = V_7 -> V_7 . V_30 - V_7 -> V_7 . V_25 ;
}
F_58 ( V_7 -> V_7 . V_19 + V_7 -> V_7 . V_25 ,
V_4 -> V_83 , V_97 ) ;
V_7 -> V_7 . V_25 += V_97 ;
F_48 ( V_4 , V_103 , V_94 ) ;
if ( V_99 ) {
F_46 ( V_82 , L_13 , V_4 -> V_4 . V_47 ) ;
V_7 -> V_7 . V_34 = 0 ;
F_59 ( & V_7 -> V_17 ) ;
F_48 ( V_4 , V_88 , V_94 ) ;
F_60 ( & V_13 -> V_14 ) ;
F_61 ( & V_4 -> V_4 , & V_7 -> V_7 ) ;
F_62 ( & V_13 -> V_14 ) ;
}
V_34 = F_56 ( V_4 , V_100 ) ;
V_98 = F_57 ( V_101 , V_34 ) ;
if ( V_99 && F_29 ( V_4 ) ) {
F_54 ( V_13 , V_4 ) ;
break;
}
}
}
static void
F_63 ( struct V_3 * V_4 , struct V_6 * V_7 , int V_34 )
{
struct V_38 * V_13 = V_4 -> V_13 ;
F_64 ( ! F_52 ( & V_7 -> V_17 ) ) ;
if ( V_7 -> V_7 . V_34 == - V_104 )
V_7 -> V_7 . V_34 = V_34 ;
if ( V_7 -> V_36 )
F_65 ( & V_13 -> V_66 , & V_7 -> V_7 , V_4 -> V_105 ) ;
F_46 ( V_106 | V_107 ,
L_14 ,
V_4 -> V_4 . V_47 , V_7 , V_7 -> V_7 . V_34 , V_7 -> V_7 . V_25 ) ;
F_60 ( & V_13 -> V_14 ) ;
F_61 ( & V_4 -> V_4 , & V_7 -> V_7 ) ;
F_62 ( & V_13 -> V_14 ) ;
}
static void
F_66 ( struct V_3 * V_4 , struct V_9 * V_108 , int V_34 )
{
struct V_6 * V_7 , * V_22 ;
F_9 (req, tmp_req, list, queue) {
F_59 ( & V_7 -> V_17 ) ;
F_63 ( V_4 , V_7 , V_34 ) ;
}
}
static int
F_67 ( struct V_109 * V_110 , const struct V_111 * V_112 )
{
struct V_3 * V_4 = F_37 ( V_110 ) ;
struct V_38 * V_13 = V_4 -> V_13 ;
unsigned long V_113 , V_114 , V_81 ;
unsigned int V_115 ;
F_46 ( V_106 , L_15 , V_4 -> V_4 . V_47 , V_112 ) ;
V_81 = F_68 ( V_112 ) & 0x7ff ;
if ( ( ( V_112 -> V_116 & V_117 ) != V_4 -> V_118 )
|| V_4 -> V_118 == 0
|| V_112 -> V_119 != V_120
|| V_81 == 0
|| V_81 > V_4 -> V_121 ) {
F_46 ( V_122 , L_16 ) ;
return - V_123 ;
}
V_4 -> V_124 = 0 ;
V_4 -> V_105 = 0 ;
if ( V_81 <= 8 )
V_114 = F_69 ( V_125 , V_126 ) ;
else
V_114 = F_69 ( V_125 , F_70 ( V_81 - 1 ) - 3 ) ;
F_46 ( V_127 , L_17 ,
V_4 -> V_4 . V_47 , V_114 , V_81 ) ;
if ( F_71 ( V_112 ) ) {
V_4 -> V_105 = 1 ;
V_114 |= V_128 ;
}
switch ( F_72 ( V_112 ) ) {
case V_129 :
V_114 |= F_69 ( V_130 , V_131 ) ;
V_114 |= F_69 ( V_132 , V_133 ) ;
break;
case V_134 :
if ( ! V_4 -> V_135 ) {
F_46 ( V_122 , L_18 ,
V_4 -> V_4 . V_47 ) ;
return - V_123 ;
}
V_115 = ( ( F_68 ( V_112 ) >> 11 ) & 3 ) + 1 ;
if ( V_115 > 3 )
return - V_123 ;
V_4 -> V_124 = 1 ;
V_114 |= F_69 ( V_130 , V_136 ) ;
if ( V_115 > 1 && V_4 -> V_137 == 3 )
V_114 |= F_69 ( V_132 , V_138 ) ;
else
V_114 |= F_69 ( V_132 , V_139 ) ;
V_114 |= F_69 ( V_140 , V_115 ) ;
break;
case V_141 :
V_114 |= F_69 ( V_130 , V_142 ) ;
V_114 |= F_69 ( V_132 , V_139 ) ;
break;
case V_143 :
V_114 |= F_69 ( V_130 , V_144 ) ;
V_114 |= F_69 ( V_132 , V_139 ) ;
break;
}
F_73 ( & V_4 -> V_13 -> V_14 , V_113 ) ;
V_4 -> V_4 . V_112 = V_112 ;
V_4 -> V_4 . V_81 = V_81 ;
F_48 ( V_4 , V_145 , V_114 ) ;
F_48 ( V_4 , V_86 , V_146 ) ;
if ( V_4 -> V_54 ) {
T_5 V_92 ;
F_74 ( V_13 , V_147 ,
( F_75 ( V_13 , V_147 )
| F_69 ( V_148 , 1 << V_4 -> V_118 )
| F_69 ( V_149 , 1 << V_4 -> V_118 ) ) ) ;
V_92 = V_150 | V_151 ;
F_48 ( V_4 , V_86 , V_92 ) ;
} else {
F_74 ( V_13 , V_147 ,
( F_75 ( V_13 , V_147 )
| F_69 ( V_148 , 1 << V_4 -> V_118 ) ) ) ;
}
F_76 ( & V_13 -> V_14 , V_113 ) ;
F_46 ( V_127 , L_19 , V_4 -> V_118 ,
( unsigned long ) F_56 ( V_4 , V_145 ) ) ;
F_46 ( V_127 , L_20 ,
( unsigned long ) F_75 ( V_13 , V_147 ) ) ;
return 0 ;
}
static int F_77 ( struct V_109 * V_110 )
{
struct V_3 * V_4 = F_37 ( V_110 ) ;
struct V_38 * V_13 = V_4 -> V_13 ;
F_78 ( V_152 ) ;
unsigned long V_113 ;
F_46 ( V_106 , L_21 , V_4 -> V_4 . V_47 ) ;
F_73 ( & V_13 -> V_14 , V_113 ) ;
if ( ! V_4 -> V_4 . V_112 ) {
F_76 ( & V_13 -> V_14 , V_113 ) ;
if ( V_13 -> V_66 . V_153 != V_154 )
F_46 ( V_122 , L_22 ,
V_4 -> V_4 . V_47 ) ;
return - V_123 ;
}
V_4 -> V_4 . V_112 = NULL ;
F_79 ( & V_4 -> V_17 , & V_152 ) ;
if ( V_4 -> V_54 ) {
F_50 ( V_4 , V_91 , 0 ) ;
F_50 ( V_4 , V_89 , 0 ) ;
F_80 ( V_4 , V_155 ) ;
}
F_48 ( V_4 , V_88 , V_146 ) ;
F_74 ( V_13 , V_147 ,
F_75 ( V_13 , V_147 )
& ~ F_69 ( V_148 , 1 << V_4 -> V_118 ) ) ;
F_66 ( V_4 , & V_152 , - V_156 ) ;
F_76 ( & V_13 -> V_14 , V_113 ) ;
return 0 ;
}
static struct V_157 *
F_81 ( struct V_109 * V_110 , T_6 V_158 )
{
struct V_6 * V_7 ;
F_46 ( V_106 , L_23 , V_110 , V_158 ) ;
V_7 = F_82 ( sizeof( * V_7 ) , V_158 ) ;
if ( ! V_7 )
return NULL ;
F_3 ( & V_7 -> V_17 ) ;
return & V_7 -> V_7 ;
}
static void
F_83 ( struct V_109 * V_110 , struct V_157 * V_159 )
{
struct V_6 * V_7 = F_84 ( V_159 ) ;
F_46 ( V_106 , L_24 , V_110 , V_159 ) ;
F_11 ( V_7 ) ;
}
static int F_85 ( struct V_38 * V_13 , struct V_3 * V_4 ,
struct V_6 * V_7 , T_6 V_158 )
{
unsigned long V_113 ;
int V_41 ;
F_46 ( V_160 , L_25 ,
V_4 -> V_4 . V_47 , V_7 -> V_7 . V_30 , V_7 -> V_7 . V_90 ,
V_7 -> V_7 . V_32 ? 'Z' : 'z' ,
V_7 -> V_7 . V_33 ? 'S' : 's' ,
V_7 -> V_7 . V_31 ? 'I' : 'i' ) ;
if ( V_7 -> V_7 . V_30 > 0x10000 ) {
F_46 ( V_122 , L_26 , V_7 -> V_7 . V_30 ) ;
return - V_123 ;
}
V_41 = F_86 ( & V_13 -> V_66 , & V_7 -> V_7 , V_4 -> V_105 ) ;
if ( V_41 )
return V_41 ;
V_7 -> V_36 = 1 ;
V_7 -> V_92 = F_69 ( V_161 , V_7 -> V_7 . V_30 )
| V_162 | V_163
| V_164 | V_165 ;
if ( V_4 -> V_105 )
V_7 -> V_92 |= V_166 ;
V_41 = - V_156 ;
F_73 ( & V_13 -> V_14 , V_113 ) ;
if ( V_4 -> V_4 . V_112 ) {
if ( F_52 ( & V_4 -> V_17 ) )
F_49 ( V_4 , V_7 ) ;
F_7 ( & V_7 -> V_17 , & V_4 -> V_17 ) ;
V_41 = 0 ;
}
F_76 ( & V_13 -> V_14 , V_113 ) ;
return V_41 ;
}
static int
F_87 ( struct V_109 * V_110 , struct V_157 * V_159 , T_6 V_158 )
{
struct V_6 * V_7 = F_84 ( V_159 ) ;
struct V_3 * V_4 = F_37 ( V_110 ) ;
struct V_38 * V_13 = V_4 -> V_13 ;
unsigned long V_113 ;
int V_41 ;
F_46 ( V_106 | V_82 | V_107 , L_27 ,
V_4 -> V_4 . V_47 , V_7 , V_159 -> V_30 ) ;
if ( ! V_13 -> V_167 || V_13 -> V_66 . V_153 == V_154 ||
! V_4 -> V_4 . V_112 )
return - V_156 ;
V_7 -> V_35 = 0 ;
V_7 -> V_36 = 0 ;
V_7 -> V_37 = 0 ;
V_159 -> V_34 = - V_104 ;
V_159 -> V_25 = 0 ;
if ( V_4 -> V_54 )
return F_85 ( V_13 , V_4 , V_7 , V_158 ) ;
V_41 = - V_156 ;
F_73 ( & V_13 -> V_14 , V_113 ) ;
if ( V_4 -> V_4 . V_112 ) {
F_7 ( & V_7 -> V_17 , & V_4 -> V_17 ) ;
if ( ( ! F_29 ( V_4 ) && V_4 -> V_105 ) ||
( F_29 ( V_4 )
&& ( V_4 -> V_59 == V_168
|| V_4 -> V_59 == V_96 ) ) )
F_48 ( V_4 , V_86 , V_85 ) ;
else
F_48 ( V_4 , V_86 , V_94 ) ;
V_41 = 0 ;
}
F_76 ( & V_13 -> V_14 , V_113 ) ;
return V_41 ;
}
static void
F_88 ( struct V_3 * V_4 , struct V_6 * V_7 , T_5 V_34 )
{
V_7 -> V_7 . V_25 = V_7 -> V_7 . V_30 - F_57 ( V_161 , V_34 ) ;
}
static int F_89 ( struct V_3 * V_4 , T_5 * V_169 )
{
unsigned int V_170 ;
T_5 V_34 ;
F_50 ( V_4 , V_91 , 0 ) ;
for ( V_170 = 40 ; V_170 ; -- V_170 ) {
V_34 = F_80 ( V_4 , V_155 ) ;
if ( ! ( V_34 & V_162 ) )
break;
F_90 ( 1 ) ;
}
if ( V_169 )
* V_169 = V_34 ;
if ( V_170 == 0 ) {
F_31 ( & V_4 -> V_13 -> V_61 -> V_62 ,
L_28 ,
V_4 -> V_4 . V_47 ) ;
return - V_171 ;
}
return 0 ;
}
static int F_91 ( struct V_109 * V_110 , struct V_157 * V_159 )
{
struct V_3 * V_4 = F_37 ( V_110 ) ;
struct V_38 * V_13 = V_4 -> V_13 ;
struct V_6 * V_7 = F_84 ( V_159 ) ;
unsigned long V_113 ;
T_5 V_34 ;
F_46 ( V_106 | V_82 , L_29 ,
V_4 -> V_4 . V_47 , V_7 ) ;
F_73 ( & V_13 -> V_14 , V_113 ) ;
if ( V_7 -> V_36 ) {
if ( V_4 -> V_17 . V_95 == & V_7 -> V_17 ) {
V_34 = F_80 ( V_4 , V_155 ) ;
if ( V_34 & V_162 )
F_89 ( V_4 , & V_34 ) ;
#ifdef F_92
V_4 -> V_56 = V_34 ;
#endif
F_74 ( V_13 , V_172 , 1 << V_4 -> V_118 ) ;
F_88 ( V_4 , V_7 , V_34 ) ;
}
}
F_59 ( & V_7 -> V_17 ) ;
F_63 ( V_4 , V_7 , - V_173 ) ;
F_51 ( V_4 ) ;
F_76 ( & V_13 -> V_14 , V_113 ) ;
return 0 ;
}
static int F_93 ( struct V_109 * V_110 , int V_174 )
{
struct V_3 * V_4 = F_37 ( V_110 ) ;
struct V_38 * V_13 = V_4 -> V_13 ;
unsigned long V_113 ;
int V_41 = 0 ;
F_46 ( V_106 , L_30 , V_4 -> V_4 . V_47 ,
V_174 ? L_31 : L_32 ) ;
if ( ! V_4 -> V_4 . V_112 ) {
F_46 ( V_122 , L_33 ,
V_4 -> V_4 . V_47 ) ;
return - V_175 ;
}
if ( V_4 -> V_124 ) {
F_46 ( V_122 , L_34 ,
V_4 -> V_4 . V_47 ) ;
return - V_176 ;
}
F_73 ( & V_13 -> V_14 , V_113 ) ;
if ( ! F_52 ( & V_4 -> V_17 )
|| ( ( V_174 && V_4 -> V_105 && ( F_56 ( V_4 , V_100 )
& F_69 ( V_101 , - 1L ) ) ) ) ) {
V_41 = - V_177 ;
} else {
if ( V_174 )
F_48 ( V_4 , V_84 , V_178 ) ;
else
F_48 ( V_4 , V_103 ,
V_178 | V_179 ) ;
F_56 ( V_4 , V_100 ) ;
}
F_76 ( & V_13 -> V_14 , V_113 ) ;
return V_41 ;
}
static int F_94 ( struct V_109 * V_110 )
{
struct V_3 * V_4 = F_37 ( V_110 ) ;
return F_57 ( V_102 , F_56 ( V_4 , V_100 ) ) ;
}
static void F_95 ( struct V_109 * V_110 )
{
struct V_3 * V_4 = F_37 ( V_110 ) ;
struct V_38 * V_13 = V_4 -> V_13 ;
F_74 ( V_13 , V_172 , 1 << V_4 -> V_118 ) ;
}
static int F_96 ( struct V_180 * V_66 )
{
struct V_38 * V_13 = F_97 ( V_66 ) ;
return F_57 ( V_181 , F_75 ( V_13 , V_182 ) ) ;
}
static int F_98 ( struct V_180 * V_66 )
{
struct V_38 * V_13 = F_97 ( V_66 ) ;
unsigned long V_113 ;
T_5 V_92 ;
int V_41 = - V_123 ;
F_73 ( & V_13 -> V_14 , V_113 ) ;
if ( V_13 -> V_183 & ( 1 << V_184 ) ) {
V_92 = F_75 ( V_13 , V_185 ) ;
F_74 ( V_13 , V_185 , V_92 | V_186 ) ;
V_41 = 0 ;
}
F_76 ( & V_13 -> V_14 , V_113 ) ;
return V_41 ;
}
static int
F_99 ( struct V_180 * V_66 , int V_187 )
{
struct V_38 * V_13 = F_97 ( V_66 ) ;
unsigned long V_113 ;
F_73 ( & V_13 -> V_14 , V_113 ) ;
if ( V_187 )
V_13 -> V_183 |= 1 << V_188 ;
else
V_13 -> V_183 &= ~ ( 1 << V_188 ) ;
F_76 ( & V_13 -> V_14 , V_113 ) ;
return 0 ;
}
static void F_100 ( struct V_189 * V_62 )
{
}
static void F_101 ( struct V_38 * V_13 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 , * V_22 ;
F_74 ( V_13 , V_172 , ~ 0UL ) ;
V_4 = F_37 ( V_13 -> V_66 . V_73 ) ;
F_9 (req, tmp_req, &ep->queue, queue) {
F_59 ( & V_7 -> V_17 ) ;
F_63 ( V_4 , V_7 , - V_173 ) ;
}
F_5 (ep, &udc->gadget.ep_list, ep.ep_list) {
if ( V_4 -> V_4 . V_112 ) {
F_60 ( & V_13 -> V_14 ) ;
F_77 ( & V_4 -> V_4 ) ;
F_62 ( & V_13 -> V_14 ) ;
}
}
}
static struct V_3 * F_102 ( struct V_38 * V_13 , T_7 V_190 )
{
struct V_3 * V_4 ;
if ( ( V_190 & V_117 ) == 0 )
return F_37 ( V_13 -> V_66 . V_73 ) ;
F_5 (ep, &udc->gadget.ep_list, ep.ep_list) {
T_8 V_116 ;
if ( ! V_4 -> V_4 . V_112 )
continue;
V_116 = V_4 -> V_4 . V_112 -> V_116 ;
if ( ( V_190 ^ V_116 ) & V_191 )
continue;
if ( ( V_116 & V_117 )
== ( V_190 & V_117 ) )
return V_4 ;
}
return NULL ;
}
static inline void F_103 ( struct V_38 * V_13 , struct V_3 * V_4 )
{
F_48 ( V_4 , V_84 , V_178 ) ;
V_4 -> V_59 = V_192 ;
}
static inline int F_104 ( struct V_38 * V_13 , struct V_3 * V_4 )
{
if ( F_56 ( V_4 , V_100 ) & V_178 )
return 1 ;
return 0 ;
}
static inline void F_105 ( struct V_38 * V_13 , unsigned int V_193 )
{
T_5 V_194 ;
F_46 ( V_195 , L_35 , V_193 ) ;
V_194 = F_75 ( V_13 , V_185 ) ;
V_194 = F_106 ( V_196 , V_193 , V_194 ) ;
F_74 ( V_13 , V_185 , V_194 ) ;
}
static int F_107 ( struct V_38 * V_13 )
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
struct V_189 * V_62 = & V_13 -> V_61 -> V_62 ;
int V_198 ;
V_198 = V_13 -> V_198 ;
F_101 ( V_13 ) ;
switch ( V_198 ) {
case 0x0100 :
F_74 ( V_13 , V_199 , V_200 ) ;
F_108 ( V_62 , L_36 ) ;
break;
case 0x0200 :
F_74 ( V_13 , V_199 , V_201 ) ;
F_108 ( V_62 , L_37 ) ;
break;
case 0x0300 :
V_4 = & V_13 -> V_3 [ 0 ] ;
F_74 ( V_13 , V_199 ,
F_69 ( V_202 , V_203 ) ) ;
F_48 ( V_4 , V_145 ,
F_69 ( V_125 , V_204 )
| V_128
| F_69 ( V_130 , V_142 )
| F_69 ( V_132 , 1 ) ) ;
if ( ! ( F_56 ( V_4 , V_145 ) & V_205 ) ) {
F_103 ( V_13 , V_4 ) ;
F_31 ( V_62 , L_38 ) ;
} else {
F_48 ( V_4 , V_86 , V_146 ) ;
F_108 ( V_62 , L_39 ) ;
}
break;
case 0x0400 :
V_4 = & V_13 -> V_3 [ 0 ] ;
F_48 ( V_4 , V_145 ,
F_69 ( V_125 , V_204 )
| V_128
| F_69 ( V_130 , V_142 )
| F_69 ( V_132 , 1 ) ) ;
if ( ! ( F_56 ( V_4 , V_145 ) & V_205 ) ) {
F_103 ( V_13 , V_4 ) ;
F_31 ( V_62 , L_40 ) ;
} else {
F_48 ( V_4 , V_86 , V_146 ) ;
F_74 ( V_13 , V_199 , V_206 ) ;
F_47 ( V_4 -> V_83 , V_197 ,
sizeof( V_197 ) ) ;
F_48 ( V_4 , V_84 , V_85 ) ;
F_108 ( V_62 , L_41 ) ;
}
break;
default:
F_31 ( V_62 , L_42 , V_198 ) ;
return - V_123 ;
}
return 0 ;
}
static inline bool F_109 ( struct V_207 * V_208 )
{
if ( V_208 -> V_209 == F_110 ( V_184 ) )
return true ;
return false ;
}
static inline bool F_111 ( struct V_207 * V_208 )
{
if ( V_208 -> V_209 == F_110 ( V_210 ) )
return true ;
return false ;
}
static inline bool F_112 ( struct V_207 * V_208 )
{
if ( V_208 -> V_209 == F_110 ( V_211 ) )
return true ;
return false ;
}
static int F_113 ( struct V_38 * V_13 , struct V_3 * V_4 ,
struct V_207 * V_208 )
{
int V_212 = 0 ;
switch ( V_208 -> V_213 ) {
case V_214 : {
T_7 V_34 ;
if ( V_208 -> V_215 == ( V_191 | V_216 ) ) {
V_34 = F_110 ( V_13 -> V_183 ) ;
} else if ( V_208 -> V_215
== ( V_191 | V_217 ) ) {
V_34 = F_110 ( 0 ) ;
} else if ( V_208 -> V_215
== ( V_191 | V_218 ) ) {
struct V_3 * V_219 ;
V_219 = F_102 ( V_13 , F_114 ( V_208 -> V_190 ) ) ;
if ( ! V_219 )
goto V_220;
V_34 = 0 ;
if ( F_104 ( V_13 , V_219 ) )
V_34 |= F_110 ( 1 ) ;
} else
goto V_221;
if ( V_208 -> V_222 != F_110 ( sizeof( V_34 ) ) )
goto V_220;
V_4 -> V_59 = V_168 ;
F_115 ( V_34 , V_4 -> V_83 ) ;
F_48 ( V_4 , V_84 , V_85 ) ;
break;
}
case V_223 : {
if ( V_208 -> V_215 == V_216 ) {
if ( F_109 ( V_208 ) )
V_13 -> V_183
&= ~ ( 1 << V_184 ) ;
else
goto V_220;
} else if ( V_208 -> V_215 == V_218 ) {
struct V_3 * V_219 ;
if ( V_208 -> V_222 != F_110 ( 0 )
|| ! F_112 ( V_208 ) )
goto V_220;
V_219 = F_102 ( V_13 , F_114 ( V_208 -> V_190 ) ) ;
if ( ! V_219 )
goto V_220;
F_48 ( V_219 , V_103 , V_178 ) ;
if ( V_219 -> V_118 != 0 )
F_48 ( V_219 , V_103 ,
V_179 ) ;
} else {
goto V_221;
}
F_54 ( V_13 , V_4 ) ;
break;
}
case V_224 : {
if ( V_208 -> V_215 == V_216 ) {
if ( F_111 ( V_208 ) ) {
F_54 ( V_13 , V_4 ) ;
V_4 -> V_59 = V_225 ;
V_13 -> V_198 = F_114 ( V_208 -> V_190 ) ;
return 0 ;
} else if ( F_109 ( V_208 ) ) {
V_13 -> V_183 |= 1 << V_184 ;
} else {
goto V_220;
}
} else if ( V_208 -> V_215 == V_218 ) {
struct V_3 * V_219 ;
if ( V_208 -> V_222 != F_110 ( 0 )
|| ! F_112 ( V_208 ) )
goto V_220;
V_219 = F_102 ( V_13 , F_114 ( V_208 -> V_190 ) ) ;
if ( ! V_219 )
goto V_220;
F_48 ( V_219 , V_84 , V_178 ) ;
} else
goto V_221;
F_54 ( V_13 , V_4 ) ;
break;
}
case V_226 :
if ( V_208 -> V_215 != ( V_227 | V_216 ) )
goto V_221;
F_105 ( V_13 , F_114 ( V_208 -> V_209 ) ) ;
F_54 ( V_13 , V_4 ) ;
V_4 -> V_59 = V_228 ;
break;
default:
V_221:
F_60 ( & V_13 -> V_14 ) ;
V_212 = V_13 -> V_167 -> V_229 ( & V_13 -> V_66 , V_208 ) ;
F_62 ( & V_13 -> V_14 ) ;
}
return V_212 ;
V_220:
F_116 ( L_43
L_44 ,
V_4 -> V_4 . V_47 , V_208 -> V_215 , V_208 -> V_213 ,
F_114 ( V_208 -> V_209 ) , F_114 ( V_208 -> V_190 ) ,
F_114 ( V_208 -> V_222 ) ) ;
F_103 ( V_13 , V_4 ) ;
return - 1 ;
}
static void F_117 ( struct V_38 * V_13 , struct V_3 * V_4 )
{
struct V_6 * V_7 ;
T_5 V_230 ;
T_5 V_231 ;
V_232:
V_230 = F_56 ( V_4 , V_100 ) ;
V_231 = F_56 ( V_4 , V_233 ) ;
F_46 ( V_234 , L_45 ,
V_4 -> V_4 . V_47 , V_4 -> V_59 , V_230 , V_231 ) ;
V_7 = NULL ;
if ( ! F_52 ( & V_4 -> V_17 ) )
V_7 = F_53 ( V_4 -> V_17 . V_95 ,
struct V_6 , V_17 ) ;
if ( ( V_231 & V_85 ) && ! ( V_230 & V_85 ) ) {
if ( V_7 -> V_35 )
F_45 ( V_4 , V_7 ) ;
else
F_49 ( V_4 , V_7 ) ;
if ( V_7 -> V_37 ) {
F_48 ( V_4 , V_88 , V_85 ) ;
F_48 ( V_4 , V_86 , V_93 ) ;
}
goto V_232;
}
if ( ( V_230 & V_231 ) & V_93 ) {
F_48 ( V_4 , V_103 , V_93 ) ;
switch ( V_4 -> V_59 ) {
case V_168 :
F_48 ( V_4 , V_86 , V_94 ) ;
F_48 ( V_4 , V_88 , V_93 ) ;
V_4 -> V_59 = V_235 ;
break;
case V_228 :
F_74 ( V_13 , V_185 , ( F_75 ( V_13 , V_185 )
| V_236 ) ) ;
F_48 ( V_4 , V_88 , V_93 ) ;
V_4 -> V_59 = V_192 ;
break;
case V_96 :
if ( V_7 ) {
F_59 ( & V_7 -> V_17 ) ;
F_63 ( V_4 , V_7 , 0 ) ;
F_51 ( V_4 ) ;
}
F_48 ( V_4 , V_88 , V_93 ) ;
V_4 -> V_59 = V_192 ;
break;
case V_225 :
F_48 ( V_4 , V_88 , V_93 ) ;
V_4 -> V_59 = V_192 ;
if ( F_107 ( V_13 ) )
F_103 ( V_13 , V_4 ) ;
break;
default:
F_116 ( L_46
L_44 ,
V_4 -> V_4 . V_47 , V_4 -> V_59 ) ;
F_103 ( V_13 , V_4 ) ;
break;
}
goto V_232;
}
if ( ( V_230 & V_231 ) & V_94 ) {
switch ( V_4 -> V_59 ) {
case V_235 :
F_48 ( V_4 , V_103 , V_94 ) ;
F_48 ( V_4 , V_88 , V_94 ) ;
if ( V_7 ) {
F_59 ( & V_7 -> V_17 ) ;
F_63 ( V_4 , V_7 , 0 ) ;
}
V_4 -> V_59 = V_192 ;
break;
case V_237 :
F_55 ( V_4 ) ;
break;
default:
F_48 ( V_4 , V_103 , V_94 ) ;
F_48 ( V_4 , V_88 , V_94 ) ;
F_116 ( L_47
L_44 ,
V_4 -> V_4 . V_47 , V_4 -> V_59 ) ;
F_103 ( V_13 , V_4 ) ;
break;
}
goto V_232;
}
if ( V_230 & V_238 ) {
union {
struct V_207 V_208 ;
unsigned long V_40 [ 2 ] ;
} V_208 ;
unsigned int V_239 ;
int V_41 ;
if ( V_4 -> V_59 != V_192 ) {
int V_34 = - V_240 ;
if ( V_4 -> V_59 == V_235
|| V_4 -> V_59 == V_96 ) {
F_48 ( V_4 , V_88 , V_94 ) ;
V_34 = 0 ;
}
if ( V_7 ) {
F_59 ( & V_7 -> V_17 ) ;
F_63 ( V_4 , V_7 , V_34 ) ;
}
}
V_239 = F_57 ( V_102 , F_56 ( V_4 , V_100 ) ) ;
F_46 ( V_127 , L_48 , V_239 ) ;
if ( V_239 != sizeof( V_208 ) ) {
F_118 ( L_49
L_50 , V_239 , sizeof( V_208 ) ) ;
F_103 ( V_13 , V_4 ) ;
return;
}
F_46 ( V_241 , L_51 , V_4 -> V_83 ) ;
F_58 ( V_208 . V_40 , V_4 -> V_83 , sizeof( V_208 ) ) ;
F_48 ( V_4 , V_103 , V_238 ) ;
if ( V_208 . V_208 . V_215 & V_191 ) {
V_4 -> V_59 = V_168 ;
} else {
if ( V_208 . V_208 . V_222 != F_110 ( 0 ) )
V_4 -> V_59 = V_237 ;
else
V_4 -> V_59 = V_96 ;
}
V_41 = - 1 ;
if ( V_4 -> V_118 == 0 )
V_41 = F_113 ( V_13 , V_4 , & V_208 . V_208 ) ;
else {
F_60 ( & V_13 -> V_14 ) ;
V_41 = V_13 -> V_167 -> V_229 ( & V_13 -> V_66 , & V_208 . V_208 ) ;
F_62 ( & V_13 -> V_14 ) ;
}
F_46 ( V_195 , L_52 ,
V_208 . V_208 . V_215 , V_208 . V_208 . V_213 ,
F_114 ( V_208 . V_208 . V_222 ) , V_4 -> V_59 , V_41 ) ;
if ( V_41 < 0 ) {
F_103 ( V_13 , V_4 ) ;
}
}
}
static void F_119 ( struct V_38 * V_13 , struct V_3 * V_4 )
{
struct V_6 * V_7 ;
T_5 V_230 ;
T_5 V_231 ;
V_230 = F_56 ( V_4 , V_100 ) ;
V_231 = F_56 ( V_4 , V_233 ) ;
F_46 ( V_234 , L_53 , V_4 -> V_4 . V_47 , V_230 ) ;
while ( ( V_231 & V_85 ) && ! ( V_230 & V_85 ) ) {
F_46 ( V_195 , L_54 , V_4 -> V_4 . V_47 ) ;
if ( F_52 ( & V_4 -> V_17 ) ) {
F_120 ( & V_13 -> V_61 -> V_62 , L_55 ) ;
F_48 ( V_4 , V_88 , V_85 ) ;
return;
}
V_7 = F_53 ( V_4 -> V_17 . V_95 , struct V_6 , V_17 ) ;
if ( V_7 -> V_36 ) {
F_48 ( V_4 , V_84 ,
V_85 ) ;
F_48 ( V_4 , V_88 ,
V_85 ) ;
F_59 ( & V_7 -> V_17 ) ;
F_51 ( V_4 ) ;
F_63 ( V_4 , V_7 , 0 ) ;
} else {
if ( V_7 -> V_35 )
F_45 ( V_4 , V_7 ) ;
else
F_49 ( V_4 , V_7 ) ;
if ( V_7 -> V_37 ) {
F_59 ( & V_7 -> V_17 ) ;
F_51 ( V_4 ) ;
F_63 ( V_4 , V_7 , 0 ) ;
}
}
V_230 = F_56 ( V_4 , V_100 ) ;
V_231 = F_56 ( V_4 , V_233 ) ;
}
if ( ( V_230 & V_231 ) & V_94 ) {
F_46 ( V_195 , L_56 , V_4 -> V_4 . V_47 ) ;
F_55 ( V_4 ) ;
F_48 ( V_4 , V_103 , V_94 ) ;
}
}
static void F_121 ( struct V_38 * V_13 , struct V_3 * V_4 )
{
struct V_6 * V_7 ;
T_5 V_34 , V_242 , V_243 ;
V_34 = F_80 ( V_4 , V_155 ) ;
V_242 = F_80 ( V_4 , V_91 ) ;
#ifdef F_92
V_4 -> V_56 = V_34 ;
#endif
V_243 = V_34 & V_242 ;
F_46 ( V_234 | V_160 , L_57 , V_34 , V_242 ) ;
if ( V_34 & V_162 ) {
F_31 ( & V_13 -> V_61 -> V_62 ,
L_58 ) ;
F_31 ( & V_13 -> V_61 -> V_62 ,
L_59 ,
V_34 , V_243 , V_242 ) ;
}
if ( F_52 ( & V_4 -> V_17 ) )
return;
if ( V_243 & ( V_244 | V_245 ) ) {
V_7 = F_53 ( V_4 -> V_17 . V_95 , struct V_6 , V_17 ) ;
F_88 ( V_4 , V_7 , V_34 ) ;
F_59 ( & V_7 -> V_17 ) ;
F_51 ( V_4 ) ;
F_63 ( V_4 , V_7 , 0 ) ;
}
}
static T_9 F_122 ( int V_246 , void * V_247 )
{
struct V_38 * V_13 = V_247 ;
T_5 V_34 ;
T_5 V_248 ;
T_5 V_249 ;
F_62 ( & V_13 -> V_14 ) ;
V_34 = F_75 ( V_13 , V_250 ) ;
F_46 ( V_234 , L_60 , V_34 ) ;
if ( V_34 & V_251 ) {
F_42 ( 0 ) ;
F_74 ( V_13 , V_252 , V_251 ) ;
F_46 ( V_195 , L_61 ) ;
if ( V_13 -> V_66 . V_153 != V_154
&& V_13 -> V_167 && V_13 -> V_167 -> V_253 ) {
F_60 ( & V_13 -> V_14 ) ;
V_13 -> V_167 -> V_253 ( & V_13 -> V_66 ) ;
F_62 ( & V_13 -> V_14 ) ;
}
}
if ( V_34 & V_254 ) {
F_42 ( 1 ) ;
F_74 ( V_13 , V_252 , V_254 ) ;
F_46 ( V_195 , L_62 ) ;
}
if ( V_34 & V_255 ) {
F_74 ( V_13 , V_252 , V_255 ) ;
F_46 ( V_195 , L_63 ) ;
if ( V_13 -> V_66 . V_153 != V_154
&& V_13 -> V_167 && V_13 -> V_167 -> V_256 ) {
F_60 ( & V_13 -> V_14 ) ;
V_13 -> V_167 -> V_256 ( & V_13 -> V_66 ) ;
F_62 ( & V_13 -> V_14 ) ;
}
}
V_248 = F_57 ( V_149 , V_34 ) ;
if ( V_248 ) {
int V_39 ;
for ( V_39 = 1 ; V_39 <= V_257 ; V_39 ++ )
if ( V_248 & ( 1 << V_39 ) )
F_121 ( V_13 , & V_13 -> V_3 [ V_39 ] ) ;
}
V_249 = F_57 ( V_148 , V_34 ) ;
if ( V_249 ) {
int V_39 ;
for ( V_39 = 0 ; V_39 < V_13 -> V_258 ; V_39 ++ )
if ( V_249 & ( 1 << V_39 ) ) {
if ( F_29 ( & V_13 -> V_3 [ V_39 ] ) )
F_117 ( V_13 , & V_13 -> V_3 [ V_39 ] ) ;
else
F_119 ( V_13 , & V_13 -> V_3 [ V_39 ] ) ;
}
}
if ( V_34 & V_259 ) {
struct V_3 * V_73 ;
F_74 ( V_13 , V_252 , V_259 ) ;
F_101 ( V_13 ) ;
if ( V_13 -> V_66 . V_153 != V_154
&& V_13 -> V_167 && V_13 -> V_167 -> V_260 ) {
V_13 -> V_66 . V_153 = V_154 ;
F_60 ( & V_13 -> V_14 ) ;
V_13 -> V_167 -> V_260 ( & V_13 -> V_66 ) ;
F_62 ( & V_13 -> V_14 ) ;
}
if ( V_34 & V_261 )
V_13 -> V_66 . V_153 = V_262 ;
else
V_13 -> V_66 . V_153 = V_263 ;
F_46 ( V_195 , L_64 ,
F_123 ( V_13 -> V_66 . V_153 ) ) ;
V_73 = & V_13 -> V_3 [ 0 ] ;
V_73 -> V_4 . V_112 = & V_264 ;
V_73 -> V_59 = V_192 ;
F_48 ( V_73 , V_145 ,
( F_69 ( V_125 , V_265 )
| F_69 ( V_130 , V_131 )
| F_69 ( V_132 , V_133 ) ) ) ;
F_48 ( V_73 , V_86 ,
V_146 | V_238 ) ;
F_74 ( V_13 , V_147 ,
( F_75 ( V_13 , V_147 )
| F_69 ( V_148 , 1 )
| V_251
| V_255 ) ) ;
if ( ! ( F_56 ( V_73 , V_145 ) & V_205 ) )
F_124 ( & V_13 -> V_61 -> V_62 ,
L_65 ) ;
}
F_60 ( & V_13 -> V_14 ) ;
return V_266 ;
}
static T_9 F_125 ( int V_246 , void * V_247 )
{
struct V_38 * V_13 = V_247 ;
int V_267 ;
F_90 ( 10 ) ;
F_62 ( & V_13 -> V_14 ) ;
if ( ! V_13 -> V_167 )
goto V_43;
V_267 = F_39 ( V_13 ) ;
if ( V_267 != V_13 -> V_268 ) {
if ( V_267 ) {
F_42 ( 1 ) ;
F_74 ( V_13 , V_185 , V_269 ) ;
F_74 ( V_13 , V_147 , V_259 ) ;
} else {
V_13 -> V_66 . V_153 = V_154 ;
F_101 ( V_13 ) ;
F_42 ( 0 ) ;
F_74 ( V_13 , V_185 , V_270 ) ;
if ( V_13 -> V_167 -> V_260 ) {
F_60 ( & V_13 -> V_14 ) ;
V_13 -> V_167 -> V_260 ( & V_13 -> V_66 ) ;
F_62 ( & V_13 -> V_14 ) ;
}
}
V_13 -> V_268 = V_267 ;
}
V_43:
F_60 ( & V_13 -> V_14 ) ;
return V_266 ;
}
static int F_126 ( struct V_180 * V_66 ,
struct V_271 * V_167 )
{
int V_41 ;
struct V_38 * V_13 = F_127 ( V_66 , struct V_38 , V_66 ) ;
unsigned long V_113 ;
F_73 ( & V_13 -> V_14 , V_113 ) ;
V_13 -> V_183 = 1 << V_188 ;
V_13 -> V_167 = V_167 ;
F_76 ( & V_13 -> V_14 , V_113 ) ;
V_41 = F_128 ( V_13 -> V_272 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_128 ( V_13 -> V_273 ) ;
if ( V_41 ) {
F_129 ( V_13 -> V_272 ) ;
return V_41 ;
}
F_46 ( V_106 , L_66 , V_167 -> V_167 . V_47 ) ;
V_13 -> V_268 = 0 ;
if ( F_40 ( V_13 -> V_74 ) )
F_130 ( F_131 ( V_13 -> V_74 ) ) ;
F_73 ( & V_13 -> V_14 , V_113 ) ;
if ( F_39 ( V_13 ) && V_13 -> V_268 == 0 ) {
F_42 ( 1 ) ;
F_74 ( V_13 , V_185 , V_269 ) ;
F_74 ( V_13 , V_147 , V_259 ) ;
}
F_76 ( & V_13 -> V_14 , V_113 ) ;
return 0 ;
}
static int F_132 ( struct V_180 * V_66 ,
struct V_271 * V_167 )
{
struct V_38 * V_13 = F_127 ( V_66 , struct V_38 , V_66 ) ;
unsigned long V_113 ;
if ( F_40 ( V_13 -> V_74 ) )
F_133 ( F_131 ( V_13 -> V_74 ) ) ;
F_73 ( & V_13 -> V_14 , V_113 ) ;
V_13 -> V_66 . V_153 = V_154 ;
F_101 ( V_13 ) ;
F_76 ( & V_13 -> V_14 , V_113 ) ;
F_42 ( 0 ) ;
F_74 ( V_13 , V_185 , V_270 ) ;
F_129 ( V_13 -> V_273 ) ;
F_129 ( V_13 -> V_272 ) ;
F_46 ( V_106 , L_67 , V_13 -> V_167 -> V_167 . V_47 ) ;
V_13 -> V_167 = NULL ;
return 0 ;
}
static struct V_3 * F_134 ( struct V_274 * V_61 ,
struct V_38 * V_13 )
{
T_5 V_275 ;
const char * V_47 ;
enum V_276 V_113 ;
struct V_277 * V_278 = V_61 -> V_62 . V_279 ;
struct V_277 * V_280 ;
int V_39 , V_41 ;
struct V_3 * V_281 , * V_4 ;
V_13 -> V_258 = 0 ;
V_13 -> V_74 = F_135 ( V_278 , L_68 , 0 ,
& V_113 ) ;
V_13 -> V_75 = ( V_113 & V_282 ) ? 1 : 0 ;
V_280 = NULL ;
while ( ( V_280 = F_136 ( V_278 , V_280 ) ) )
V_13 -> V_258 ++ ;
V_281 = F_137 ( & V_61 -> V_62 , sizeof( struct V_3 ) * V_13 -> V_258 ,
V_11 ) ;
if ( ! V_281 )
return F_138 ( - V_12 ) ;
V_13 -> V_66 . V_73 = & V_281 [ 0 ] . V_4 ;
F_3 ( & V_281 [ 0 ] . V_4 . V_283 ) ;
V_280 = NULL ;
V_39 = 0 ;
while ( ( V_280 = F_136 ( V_278 , V_280 ) ) ) {
V_4 = & V_281 [ V_39 ] ;
V_41 = F_139 ( V_280 , L_69 , & V_275 ) ;
if ( V_41 ) {
F_31 ( & V_61 -> V_62 , L_70 , V_41 ) ;
goto V_284;
}
V_4 -> V_118 = V_275 ;
V_41 = F_139 ( V_280 , L_71 , & V_275 ) ;
if ( V_41 ) {
F_31 ( & V_61 -> V_62 , L_72 , V_41 ) ;
goto V_284;
}
V_4 -> V_121 = V_275 ;
V_41 = F_139 ( V_280 , L_73 , & V_275 ) ;
if ( V_41 ) {
F_31 ( & V_61 -> V_62 , L_74 , V_41 ) ;
goto V_284;
}
V_4 -> V_137 = V_275 ;
V_4 -> V_54 = F_140 ( V_280 , L_75 ) ;
V_4 -> V_135 = F_140 ( V_280 , L_76 ) ;
V_41 = F_141 ( V_280 , L_77 , & V_47 ) ;
V_4 -> V_4 . V_47 = V_47 ;
V_4 -> V_285 = V_13 -> V_44 + F_142 ( V_39 ) ;
V_4 -> V_286 = V_13 -> V_44 + F_143 ( V_39 ) ;
V_4 -> V_83 = V_13 -> V_83 + F_144 ( V_39 ) ;
V_4 -> V_4 . V_287 = & V_288 ;
F_145 ( & V_4 -> V_4 , V_4 -> V_121 ) ;
V_4 -> V_13 = V_13 ;
F_3 ( & V_4 -> V_17 ) ;
if ( V_39 )
F_7 ( & V_4 -> V_4 . V_283 , & V_13 -> V_66 . V_283 ) ;
V_39 ++ ;
}
if ( V_39 == 0 ) {
F_31 ( & V_61 -> V_62 , L_78 ) ;
V_41 = - V_123 ;
goto V_284;
}
return V_281 ;
V_284:
return F_138 ( V_41 ) ;
}
static struct V_3 * F_134 ( struct V_274 * V_61 ,
struct V_38 * V_13 )
{
return F_138 ( - V_289 ) ;
}
static struct V_3 * F_146 ( struct V_274 * V_61 ,
struct V_38 * V_13 )
{
struct V_290 * V_291 = F_147 ( & V_61 -> V_62 ) ;
struct V_3 * V_281 ;
int V_39 ;
if ( ! V_291 )
return F_138 ( - V_292 ) ;
V_281 = F_137 ( & V_61 -> V_62 , sizeof( struct V_3 ) * V_291 -> V_258 ,
V_11 ) ;
if ( ! V_281 )
return F_138 ( - V_12 ) ;
V_13 -> V_66 . V_73 = & V_281 [ 0 ] . V_4 ;
V_13 -> V_74 = V_291 -> V_74 ;
V_13 -> V_75 = V_291 -> V_75 ;
V_13 -> V_258 = V_291 -> V_258 ;
F_3 ( & V_281 [ 0 ] . V_4 . V_283 ) ;
for ( V_39 = 0 ; V_39 < V_291 -> V_258 ; V_39 ++ ) {
struct V_3 * V_4 = & V_281 [ V_39 ] ;
V_4 -> V_285 = V_13 -> V_44 + F_142 ( V_39 ) ;
V_4 -> V_286 = V_13 -> V_44 + F_143 ( V_39 ) ;
V_4 -> V_83 = V_13 -> V_83 + F_144 ( V_39 ) ;
V_4 -> V_4 . V_287 = & V_288 ;
V_4 -> V_4 . V_47 = V_291 -> V_4 [ V_39 ] . V_47 ;
V_4 -> V_121 = V_291 -> V_4 [ V_39 ] . V_121 ;
F_145 ( & V_4 -> V_4 , V_4 -> V_121 ) ;
V_4 -> V_13 = V_13 ;
F_3 ( & V_4 -> V_17 ) ;
V_4 -> V_137 = V_291 -> V_4 [ V_39 ] . V_137 ;
V_4 -> V_118 = V_291 -> V_4 [ V_39 ] . V_118 ;
V_4 -> V_54 = V_291 -> V_4 [ V_39 ] . V_54 ;
V_4 -> V_135 = V_291 -> V_4 [ V_39 ] . V_135 ;
if ( V_39 )
F_7 ( & V_4 -> V_4 . V_283 , & V_13 -> V_66 . V_283 ) ;
}
return V_281 ;
}
static int F_148 ( struct V_274 * V_61 )
{
struct V_64 * V_44 , * V_83 ;
struct V_293 * V_272 , * V_273 ;
struct V_38 * V_13 ;
int V_246 , V_41 , V_39 ;
V_13 = F_137 ( & V_61 -> V_62 , sizeof( * V_13 ) , V_11 ) ;
if ( ! V_13 )
return - V_12 ;
V_13 -> V_66 = V_294 ;
F_3 ( & V_13 -> V_66 . V_283 ) ;
V_44 = F_35 ( V_61 , V_69 , V_70 ) ;
V_83 = F_35 ( V_61 , V_69 , V_295 ) ;
if ( ! V_44 || ! V_83 )
return - V_292 ;
V_246 = F_149 ( V_61 , 0 ) ;
if ( V_246 < 0 )
return V_246 ;
V_272 = F_150 ( & V_61 -> V_62 , L_79 ) ;
if ( F_34 ( V_272 ) )
return F_151 ( V_272 ) ;
V_273 = F_150 ( & V_61 -> V_62 , L_80 ) ;
if ( F_34 ( V_273 ) )
return F_151 ( V_273 ) ;
F_152 ( & V_13 -> V_14 ) ;
V_13 -> V_61 = V_61 ;
V_13 -> V_272 = V_272 ;
V_13 -> V_273 = V_273 ;
V_13 -> V_74 = - V_175 ;
V_41 = - V_12 ;
V_13 -> V_44 = F_153 ( & V_61 -> V_62 , V_44 -> V_296 , F_36 ( V_44 ) ) ;
if ( ! V_13 -> V_44 ) {
F_31 ( & V_61 -> V_62 , L_81 ) ;
return V_41 ;
}
F_108 ( & V_61 -> V_62 , L_82 ,
( unsigned long ) V_44 -> V_296 , V_13 -> V_44 ) ;
V_13 -> V_83 = F_153 ( & V_61 -> V_62 , V_83 -> V_296 , F_36 ( V_83 ) ) ;
if ( ! V_13 -> V_83 ) {
F_31 ( & V_61 -> V_62 , L_83 ) ;
return V_41 ;
}
F_108 ( & V_61 -> V_62 , L_84 ,
( unsigned long ) V_83 -> V_296 , V_13 -> V_83 ) ;
F_154 ( V_61 , V_13 ) ;
V_41 = F_128 ( V_272 ) ;
if ( V_41 ) {
F_31 ( & V_61 -> V_62 , L_85 ) ;
return V_41 ;
}
F_42 ( 0 ) ;
F_74 ( V_13 , V_185 , V_270 ) ;
F_129 ( V_272 ) ;
if ( V_61 -> V_62 . V_279 )
V_13 -> V_3 = F_134 ( V_61 , V_13 ) ;
else
V_13 -> V_3 = F_146 ( V_61 , V_13 ) ;
if ( F_34 ( V_13 -> V_3 ) )
return F_151 ( V_13 -> V_3 ) ;
V_41 = F_155 ( & V_61 -> V_62 , V_246 , F_122 , 0 ,
L_86 , V_13 ) ;
if ( V_41 ) {
F_31 ( & V_61 -> V_62 , L_87 ,
V_246 , V_41 ) ;
return V_41 ;
}
V_13 -> V_246 = V_246 ;
if ( F_40 ( V_13 -> V_74 ) ) {
if ( ! F_156 ( & V_61 -> V_62 , V_13 -> V_74 , L_86 ) ) {
V_41 = F_155 ( & V_61 -> V_62 ,
F_131 ( V_13 -> V_74 ) ,
F_125 , 0 ,
L_86 , V_13 ) ;
if ( V_41 ) {
V_13 -> V_74 = - V_175 ;
F_120 ( & V_13 -> V_61 -> V_62 ,
L_88
L_89 ) ;
} else {
F_133 ( F_131 ( V_13 -> V_74 ) ) ;
}
} else {
V_13 -> V_74 = - V_123 ;
}
}
V_41 = F_157 ( & V_61 -> V_62 , & V_13 -> V_66 ) ;
if ( V_41 )
return V_41 ;
F_33 ( V_13 ) ;
for ( V_39 = 1 ; V_39 < V_13 -> V_258 ; V_39 ++ )
F_25 ( V_13 , & V_13 -> V_3 [ V_39 ] ) ;
return 0 ;
}
static int T_10 F_158 ( struct V_274 * V_61 )
{
struct V_38 * V_13 ;
int V_39 ;
V_13 = F_159 ( V_61 ) ;
F_160 ( & V_13 -> V_66 ) ;
for ( V_39 = 1 ; V_39 < V_13 -> V_258 ; V_39 ++ )
F_32 ( & V_13 -> V_3 [ V_39 ] ) ;
F_38 ( V_13 ) ;
return 0 ;
}
