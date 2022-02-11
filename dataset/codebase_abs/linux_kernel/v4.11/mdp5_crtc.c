static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static void F_4 ( struct V_2 * V_3 , T_1 V_9 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_6 ( V_9 , & V_10 -> V_9 ) ;
F_7 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
}
static void F_8 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_9 ( & V_10 -> V_13 ) ;
}
static T_2 F_10 ( struct V_2 * V_3 , T_2 V_14 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_11 ( L_1 , V_3 -> V_15 , V_14 ) ;
return F_12 ( V_10 -> V_16 , V_14 ) ;
}
static T_2 F_13 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_17 * V_18 ;
T_1 V_14 = 0 ;
if ( F_14 ( ! V_10 -> V_16 ) )
return 0 ;
F_15 (plane, crtc) {
V_14 |= F_16 ( V_18 ) ;
}
V_14 |= F_17 ( V_10 -> V_19 ) ;
return F_10 ( V_3 , V_14 ) ;
}
static void F_18 ( struct V_2 * V_3 , struct V_20 * V_21 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_23 * V_24 ;
unsigned long V_25 ;
F_19 ( & V_6 -> V_26 , V_25 ) ;
V_24 = V_10 -> V_24 ;
if ( V_24 ) {
if ( ! V_21 || ( V_24 -> V_11 . V_27 == V_21 ) ) {
V_10 -> V_24 = NULL ;
F_11 ( L_2 , V_3 -> V_15 , V_24 ) ;
F_20 ( V_3 , V_24 ) ;
}
}
F_21 ( & V_6 -> V_26 , V_25 ) ;
if ( V_10 -> V_16 && ! V_3 -> V_28 -> V_29 ) {
F_22 ( V_10 -> V_16 , NULL , 0 , 0 ) ;
V_10 -> V_16 = NULL ;
}
}
static void F_23 ( struct V_30 * V_31 , void * V_32 )
{
struct V_10 * V_10 =
F_24 ( V_31 , struct V_10 , V_33 ) ;
struct V_1 * V_1 = F_1 ( & V_10 -> V_11 ) ;
F_25 ( V_32 , V_1 -> V_34 ) ;
F_26 ( V_32 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_28 ( V_3 ) ;
F_29 ( & V_10 -> V_33 ) ;
F_30 ( V_10 ) ;
}
static inline T_2 F_31 ( enum V_35 V_36 )
{
switch ( V_36 ) {
case V_37 : return V_38 ;
case V_39 : return V_40 ;
case V_41 : return V_42 ;
case V_43 : return V_44 ;
case V_45 : return V_46 ;
case V_47 : return V_48 ;
case V_49 : return V_50 ;
default:
return 0 ;
}
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_17 * V_18 ;
const struct V_51 * V_52 ;
struct V_53 * V_54 , * V_55 [ V_56 + 1 ] = { NULL } ;
const struct V_57 * V_58 ;
T_1 V_19 = V_10 -> V_19 ;
T_1 V_59 , V_60 , V_61 , V_62 = 0 ;
unsigned long V_25 ;
enum V_63 V_36 [ V_56 + 1 ] = { V_64 } ;
int V_65 , V_66 = 0 ;
bool V_67 = false ;
T_2 V_68 = 0 ;
#define F_33 ( V_36 ) ((stage) - STAGE0)
V_52 = F_34 ( V_1 -> V_69 ) ;
F_19 ( & V_10 -> V_70 , V_25 ) ;
if ( ! V_10 -> V_16 )
goto V_71;
F_15 (plane, crtc) {
V_54 = F_35 ( V_18 -> V_28 ) ;
V_55 [ V_54 -> V_36 ] = V_54 ;
V_36 [ V_54 -> V_36 ] = F_36 ( V_18 ) ;
V_66 ++ ;
}
if ( ! V_55 [ V_72 ] ) {
V_62 |= V_73 ;
F_11 ( L_3 ) ;
} else if ( V_66 ) {
V_58 = F_37 ( F_38 ( V_55 [ V_72 ] -> V_11 . V_74 ) ) ;
if ( V_58 -> V_75 )
V_67 = true ;
}
for ( V_65 = V_37 ; V_65 <= V_56 ; V_65 ++ ) {
if ( ! V_55 [ V_65 ] )
continue;
V_58 = F_37 (
F_38 ( V_55 [ V_65 ] -> V_11 . V_74 ) ) ;
V_18 = V_55 [ V_65 ] -> V_11 . V_18 ;
V_59 = F_39 ( V_76 ) |
F_40 ( V_77 ) ;
V_60 = V_55 [ V_65 ] -> V_78 ;
V_61 = 0xFF - V_55 [ V_65 ] -> V_78 ;
if ( ! V_58 -> V_75 && V_67 )
V_68 = 0 ;
else
V_68 |= F_31 ( V_65 ) ;
F_11 ( L_4 , V_65 , V_60 , V_61 ) ;
if ( V_58 -> V_75 && V_55 [ V_65 ] -> V_79 ) {
V_59 = F_39 ( V_76 ) |
F_40 ( V_80 ) ;
if ( V_60 != 0xff ) {
V_61 = V_60 ;
V_59 |=
V_81 |
V_82 ;
} else {
V_59 |= V_83 ;
}
} else if ( V_58 -> V_75 ) {
V_59 = F_39 ( V_80 ) |
F_40 ( V_80 ) ;
if ( V_60 != 0xff ) {
V_61 = V_60 ;
V_59 |=
V_84 |
V_85 |
V_81 |
V_82 ;
} else {
V_59 |= V_83 ;
}
}
F_41 ( V_1 , F_42 ( V_19 ,
F_33 ( V_65 ) ) , V_59 ) ;
F_41 ( V_1 , F_43 ( V_19 ,
F_33 ( V_65 ) ) , V_60 ) ;
F_41 ( V_1 , F_44 ( V_19 ,
F_33 ( V_65 ) ) , V_61 ) ;
}
F_41 ( V_1 , F_45 ( V_19 ) , V_68 ) ;
F_22 ( V_10 -> V_16 , V_36 , V_66 , V_62 ) ;
V_71:
F_21 ( & V_10 -> V_70 , V_25 ) ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_25 ;
struct V_86 * V_87 ;
if ( F_14 ( ! V_3 -> V_28 ) )
return;
V_87 = & V_3 -> V_28 -> V_88 ;
F_11 ( L_5 ,
V_3 -> V_15 , V_87 -> V_11 . V_34 , V_87 -> V_15 ,
V_87 -> V_89 , V_87 -> clock ,
V_87 -> V_90 , V_87 -> V_91 ,
V_87 -> V_92 , V_87 -> V_93 ,
V_87 -> V_94 , V_87 -> V_95 ,
V_87 -> V_96 , V_87 -> V_97 ,
V_87 -> type , V_87 -> V_25 ) ;
F_19 ( & V_10 -> V_70 , V_25 ) ;
F_41 ( V_1 , F_47 ( V_10 -> V_19 ) ,
F_48 ( V_87 -> V_90 ) |
F_49 ( V_87 -> V_94 ) ) ;
F_21 ( & V_10 -> V_70 , V_25 ) ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_11 ( L_6 , V_3 -> V_15 ) ;
if ( F_14 ( ! V_10 -> V_98 ) )
return;
if ( V_10 -> V_99 )
F_51 ( & V_1 -> V_11 , & V_10 -> V_100 ) ;
F_51 ( & V_1 -> V_11 , & V_10 -> V_101 ) ;
F_52 ( V_1 ) ;
V_10 -> V_98 = false ;
}
static void F_53 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_11 ( L_6 , V_3 -> V_15 ) ;
if ( F_14 ( V_10 -> V_98 ) )
return;
F_54 ( V_1 ) ;
F_7 ( & V_1 -> V_11 , & V_10 -> V_101 ) ;
if ( V_10 -> V_99 )
F_7 ( & V_1 -> V_11 , & V_10 -> V_100 ) ;
V_10 -> V_98 = true ;
}
static int F_55 ( const void * V_102 , const void * V_103 )
{
struct V_104 * V_105 = (struct V_104 * ) V_102 ;
struct V_104 * V_106 = (struct V_104 * ) V_103 ;
return V_105 -> V_28 -> V_107 - V_106 -> V_28 -> V_107 ;
}
static bool F_56 ( struct V_108 * V_109 ,
struct V_110 * V_54 )
{
return ( V_54 -> V_111 <= 0 ) && ( V_54 -> V_112 <= 0 ) &&
( ( V_54 -> V_111 + V_54 -> V_113 ) >= V_109 -> V_87 . V_90 ) &&
( ( V_54 -> V_112 + V_54 -> V_114 ) >= V_109 -> V_87 . V_94 ) ;
}
static int F_57 ( struct V_2 * V_3 ,
struct V_108 * V_28 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_17 * V_18 ;
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_104 V_55 [ V_56 + 1 ] ;
const struct V_51 * V_52 ;
const struct V_110 * V_54 ;
bool V_115 = false ;
int V_116 = 0 , V_11 = 0 , V_65 ;
F_11 ( L_7 , V_3 -> V_15 ) ;
F_58 (plane, pstate, state) {
V_55 [ V_116 ] . V_18 = V_18 ;
V_55 [ V_116 ] . V_28 = F_35 ( V_54 ) ;
V_116 ++ ;
if ( V_18 -> type == V_117 )
V_115 = true ;
}
F_59 ( V_55 , V_116 , sizeof( V_55 [ 0 ] ) , F_55 , NULL ) ;
if ( ( V_116 > 0 ) && ! F_56 ( V_28 , & V_55 [ 0 ] . V_28 -> V_11 ) )
V_11 ++ ;
F_14 ( V_115 &&
( V_55 [ V_116 - 1 ] . V_18 -> type != V_117 ) ) ;
V_52 = F_34 ( V_1 -> V_69 ) ;
if ( ( V_116 + V_11 ) >= V_52 -> V_19 . V_118 ) {
F_60 ( V_6 -> V_6 , L_8 , V_116 , V_11 ) ;
return - V_119 ;
}
for ( V_65 = 0 ; V_65 < V_116 ; V_65 ++ ) {
if ( V_115 && ( V_65 == ( V_116 - 1 ) ) )
V_55 [ V_65 ] . V_28 -> V_36 = V_52 -> V_19 . V_118 ;
else
V_55 [ V_65 ] . V_28 -> V_36 = V_72 + V_65 + V_11 ;
F_11 ( L_9 , V_3 -> V_15 ,
V_55 [ V_65 ] . V_18 -> V_15 ,
V_55 [ V_65 ] . V_28 -> V_36 ) ;
}
return 0 ;
}
static void F_61 ( struct V_2 * V_3 ,
struct V_108 * V_120 )
{
F_11 ( L_10 , V_3 -> V_15 ) ;
}
static void F_62 ( struct V_2 * V_3 ,
struct V_108 * V_120 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_22 * V_6 = V_3 -> V_6 ;
unsigned long V_25 ;
F_11 ( L_11 , V_3 -> V_15 , V_3 -> V_28 -> V_24 ) ;
F_14 ( V_10 -> V_24 ) ;
F_19 ( & V_6 -> V_26 , V_25 ) ;
V_10 -> V_24 = V_3 -> V_28 -> V_24 ;
F_21 ( & V_6 -> V_26 , V_25 ) ;
if ( F_63 ( ! V_10 -> V_16 ) )
return;
F_32 ( V_3 ) ;
if ( V_10 -> V_99 )
F_8 ( V_3 ) ;
V_10 -> V_121 = F_13 ( V_3 ) ;
F_4 ( V_3 , V_122 ) ;
}
static void F_64 ( struct V_2 * V_3 , T_1 * V_123 , T_1 * V_124 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
T_1 V_125 = V_3 -> V_87 . V_90 ;
T_1 V_126 = V_3 -> V_87 . V_94 ;
* V_123 = F_65 ( V_10 -> V_127 . V_128 , V_125 -
V_10 -> V_127 . V_129 ) ;
* V_124 = F_65 ( V_10 -> V_127 . V_130 , V_126 -
V_10 -> V_127 . V_131 ) ;
}
static int F_66 ( struct V_2 * V_3 ,
struct V_20 * V_21 , T_1 V_132 ,
T_1 V_128 , T_1 V_130 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_133 * V_134 , * V_135 = NULL ;
T_1 V_136 , V_137 ;
T_3 V_138 ;
int V_139 , V_19 ;
enum V_140 V_141 = V_142 ;
T_1 V_14 = F_67 ( 0 ) ;
T_1 V_123 , V_124 ;
bool V_143 = true ;
unsigned long V_25 ;
if ( ( V_128 > V_144 ) || ( V_130 > V_145 ) ) {
F_60 ( V_6 -> V_6 , L_12 , V_128 , V_130 ) ;
return - V_119 ;
}
if ( NULL == V_10 -> V_16 )
return - V_119 ;
if ( ! V_132 ) {
F_11 ( L_13 ) ;
V_143 = false ;
goto V_146;
}
V_134 = F_68 ( V_21 , V_132 ) ;
if ( ! V_134 )
return - V_147 ;
V_139 = F_69 ( V_134 , V_1 -> V_34 , & V_138 ) ;
if ( V_139 )
return - V_119 ;
V_19 = V_10 -> V_19 ;
V_137 = V_128 * F_70 ( V_148 , 0 ) ;
F_19 ( & V_10 -> V_127 . V_149 , V_25 ) ;
V_135 = V_10 -> V_127 . V_150 ;
V_10 -> V_127 . V_150 = V_134 ;
V_10 -> V_127 . V_128 = V_128 ;
V_10 -> V_127 . V_130 = V_130 ;
F_64 ( V_3 , & V_123 , & V_124 ) ;
F_41 ( V_1 , F_71 ( V_19 ) , V_137 ) ;
F_41 ( V_1 , F_72 ( V_19 ) ,
F_73 ( V_151 ) ) ;
F_41 ( V_1 , F_74 ( V_19 ) ,
F_75 ( V_130 ) |
F_76 ( V_128 ) ) ;
F_41 ( V_1 , F_77 ( V_19 ) ,
F_78 ( V_124 ) |
F_79 ( V_123 ) ) ;
F_41 ( V_1 , F_80 ( V_19 ) , V_138 ) ;
V_136 = V_152 ;
V_136 |= F_81 ( V_141 ) ;
F_41 ( V_1 , F_82 ( V_19 ) , V_136 ) ;
F_21 ( & V_10 -> V_127 . V_149 , V_25 ) ;
V_146:
V_139 = F_83 ( V_10 -> V_16 , 0 , V_143 ) ;
if ( V_139 ) {
F_60 ( V_6 -> V_6 , L_14 ,
V_143 ? L_15 : L_16 , V_139 ) ;
goto V_153;
}
F_10 ( V_3 , V_14 ) ;
V_153:
if ( V_135 ) {
F_84 ( & V_10 -> V_33 , V_135 ) ;
F_4 ( V_3 , V_154 ) ;
}
return V_139 ;
}
static int F_85 ( struct V_2 * V_3 , int V_129 , int V_131 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
T_1 V_14 = F_67 ( 0 ) ;
T_1 V_123 ;
T_1 V_124 ;
unsigned long V_25 ;
if ( F_63 ( ! V_3 -> V_28 -> V_29 ) )
return 0 ;
V_10 -> V_127 . V_129 = V_129 = F_86 ( V_129 , 0 ) ;
V_10 -> V_127 . V_131 = V_131 = F_86 ( V_131 , 0 ) ;
F_64 ( V_3 , & V_123 , & V_124 ) ;
F_19 ( & V_10 -> V_127 . V_149 , V_25 ) ;
F_41 ( V_1 , F_77 ( V_10 -> V_19 ) ,
F_78 ( V_124 ) |
F_79 ( V_123 ) ) ;
F_41 ( V_1 , F_87 ( V_10 -> V_19 ) ,
F_88 ( V_131 ) |
F_89 ( V_129 ) ) ;
F_21 ( & V_10 -> V_127 . V_149 , V_25 ) ;
F_10 ( V_3 , V_14 ) ;
return 0 ;
}
static void F_90 ( struct V_155 * V_156 , T_1 V_157 )
{
struct V_10 * V_10 = F_24 ( V_156 , struct V_10 , V_12 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
unsigned V_9 ;
F_51 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
V_9 = F_91 ( & V_10 -> V_9 , 0 ) ;
if ( V_9 & V_122 ) {
F_18 ( V_3 , NULL ) ;
}
if ( V_9 & V_154 )
F_92 ( & V_10 -> V_33 , V_5 -> V_158 ) ;
}
static void F_93 ( struct V_155 * V_156 , T_1 V_157 )
{
struct V_10 * V_10 = F_24 ( V_156 , struct V_10 , V_101 ) ;
F_11 ( L_17 , V_10 -> V_11 . V_15 , V_157 ) ;
}
static void F_94 ( struct V_155 * V_156 , T_1 V_157 )
{
struct V_10 * V_10 = F_24 ( V_156 , struct V_10 ,
V_100 ) ;
F_95 ( & V_10 -> V_13 ) ;
}
static void F_96 ( struct V_2 * V_3 )
{
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
int V_139 ;
V_139 = F_97 ( & V_10 -> V_13 ,
F_98 ( 50 ) ) ;
if ( V_139 == 0 )
F_99 ( V_6 -> V_6 , L_18 , V_10 -> V_19 ) ;
}
static void F_100 ( struct V_2 * V_3 )
{
struct V_22 * V_6 = V_3 -> V_6 ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
int V_139 ;
if ( ! V_10 -> V_16 )
return;
V_139 = F_101 ( V_3 ) ;
if ( V_139 )
return;
V_139 = F_102 ( V_6 -> V_12 [ F_103 ( V_3 ) ] . V_159 ,
( ( F_104 ( V_10 -> V_16 ) &
V_10 -> V_121 ) == 0 ) ,
F_98 ( 50 ) ) ;
if ( V_139 <= 0 )
F_99 ( V_6 -> V_6 , L_19 , V_10 -> V_34 ) ;
V_10 -> V_121 = 0 ;
F_105 ( V_3 ) ;
}
T_1 F_106 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return V_10 -> V_12 . V_160 ;
}
void F_107 ( struct V_2 * V_3 ,
struct V_161 * V_162 , struct V_163 * V_16 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_19 = F_108 ( V_3 ) ;
V_10 -> V_101 . V_160 = F_109 ( V_162 -> V_164 ) ;
V_10 -> V_12 . V_160 = F_110 ( V_19 , V_162 ) ;
if ( ( V_162 -> type == V_165 ) &&
( V_162 -> V_87 == V_166 ) ) {
V_10 -> V_100 . V_160 = F_111 ( V_19 ) ;
V_10 -> V_100 . V_156 = F_94 ;
V_10 -> V_99 = true ;
} else {
V_10 -> V_100 . V_160 = 0 ;
V_10 -> V_100 . V_156 = NULL ;
V_10 -> V_99 = false ;
}
F_112 ( & V_1 -> V_11 ) ;
V_10 -> V_16 = V_16 ;
F_113 ( V_16 , V_162 , V_19 ) ;
}
struct V_163 * F_114 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return V_10 -> V_16 ;
}
int F_108 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return F_14 ( ! V_3 ) ? - V_119 : V_10 -> V_19 ;
}
void F_115 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
if ( V_10 -> V_99 )
F_96 ( V_3 ) ;
else
F_100 ( V_3 ) ;
}
struct V_2 * F_116 ( struct V_22 * V_6 ,
struct V_17 * V_18 ,
struct V_17 * V_115 , int V_34 )
{
struct V_2 * V_3 = NULL ;
struct V_10 * V_10 ;
V_10 = F_117 ( sizeof( * V_10 ) , V_167 ) ;
if ( ! V_10 )
return F_118 ( - V_168 ) ;
V_3 = & V_10 -> V_11 ;
V_10 -> V_34 = V_34 ;
V_10 -> V_19 = F_119 ( V_34 ) ;
F_120 ( & V_10 -> V_70 ) ;
F_120 ( & V_10 -> V_127 . V_149 ) ;
F_121 ( & V_10 -> V_13 ) ;
V_10 -> V_12 . V_156 = F_90 ;
V_10 -> V_101 . V_156 = F_93 ;
if ( V_115 )
F_122 ( V_6 , V_3 , V_18 , V_115 ,
& V_169 , NULL ) ;
else
F_122 ( V_6 , V_3 , V_18 , NULL ,
& V_170 , NULL ) ;
F_123 ( & V_10 -> V_33 ,
L_20 , F_23 ) ;
F_124 ( V_3 , & V_171 ) ;
V_18 -> V_3 = V_3 ;
return V_3 ;
}
