static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 &&
( V_2 -> V_4 -> V_5 . V_6 & V_7 ) ;
}
static void F_2 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
F_4 ( V_9 ) ;
V_15 = V_9 -> V_18 ;
V_15 -> V_19 = 0 ;
V_15 -> V_20 = V_9 -> V_21 ;
V_17 = V_9 -> V_22 ;
F_5 ( V_17 == NULL ) ;
V_15 -> V_23 = V_17 -> V_24 ;
F_6 ( V_11 , V_15 ,
V_13 -> V_25 ,
0 ) ;
if ( V_2 -> V_26 . V_27 == NULL )
F_7 ( V_11 , V_9 -> V_28 ) ;
else
* V_2 -> V_26 . V_27 = V_9 -> V_28 ;
V_2 -> V_26 . V_27 = & V_15 -> V_19 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_29 )
{
F_9 ( V_2 -> V_4 , V_29 ) ;
V_2 -> V_26 . V_30 = V_29 ;
V_2 -> V_26 . V_31 = 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
T_1 V_32 , V_33 [ 2 ] ;
V_32 = F_11 ( V_2 ) ;
F_12 ( V_11 , V_32 ) ;
F_13 ( V_13 ) ;
F_14 ( V_11 ) ;
V_33 [ 0 ] = V_33 [ 1 ] = ~ 0 ;
F_15 ( V_11 , V_33 [ 0 ] , V_33 [ 1 ] ) ;
}
static bool F_16 ( struct V_1 * V_2 ,
enum V_34 V_35 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_36 * V_37 ;
struct V_16 * V_17 ;
struct V_8 * V_9 ;
V_37 = & V_2 -> V_26 . V_37 [ V_35 ] ;
if ( F_17 ( & V_37 -> V_38 ) >= V_37 -> V_39 )
return false ;
V_9 = F_18 ( & V_2 -> V_26 . V_40 , struct V_8 , V_41 ) ;
F_19 ( & V_9 -> V_41 ) ;
V_17 = V_9 -> V_22 ;
F_4 ( V_9 ) ;
memset ( V_17 -> V_24 , 0 , V_11 -> V_5 . V_42 ) ;
F_20 ( V_2 -> V_43 , V_9 -> V_21 ,
V_11 -> V_5 . V_42 , V_44 ) ;
F_21 ( V_17 ) = V_9 ;
F_22 ( V_11 , V_9 -> V_21 , V_35 ) ;
F_23 ( & V_37 -> V_38 , V_17 ) ;
return true ;
}
static void F_24 ( struct V_1 * V_2 ,
enum V_34 V_35 )
{
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
struct V_8 * V_9 , * V_45 ;
if ( F_25 ( & V_2 -> V_26 . V_40 ) ) {
F_26 ( V_13 , V_46 , L_1 ) ;
return;
}
F_27 (bf, tbf, &sc->rx.rxbuf, list)
if ( ! F_16 ( V_2 , V_35 ) )
break;
}
static void F_28 ( struct V_1 * V_2 ,
enum V_34 V_35 )
{
struct V_8 * V_9 ;
struct V_36 * V_37 ;
struct V_16 * V_17 ;
V_37 = & V_2 -> V_26 . V_37 [ V_35 ] ;
while ( ( V_17 = F_29 ( & V_37 -> V_38 ) ) != NULL ) {
V_9 = F_21 ( V_17 ) ;
F_5 ( ! V_9 ) ;
F_30 ( & V_9 -> V_41 , & V_2 -> V_26 . V_40 ) ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_8 * V_9 ;
F_28 ( V_2 , V_47 ) ;
F_28 ( V_2 , V_48 ) ;
F_32 (bf, &sc->rx.rxbuf, list) {
if ( V_9 -> V_22 ) {
F_33 ( V_2 -> V_43 , V_9 -> V_21 ,
V_13 -> V_25 ,
V_49 ) ;
F_34 ( V_9 -> V_22 ) ;
V_9 -> V_21 = 0 ;
V_9 -> V_22 = NULL ;
}
}
}
static void F_35 ( struct V_36 * V_37 , int V_50 )
{
F_36 ( & V_37 -> V_38 ) ;
V_37 -> V_39 = V_50 ;
}
static int F_37 ( struct V_1 * V_2 , int V_51 )
{
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_16 * V_17 ;
struct V_8 * V_9 ;
int error = 0 , V_52 ;
T_1 V_50 ;
F_38 ( V_11 , V_13 -> V_25 -
V_11 -> V_5 . V_42 ) ;
F_35 ( & V_2 -> V_26 . V_37 [ V_47 ] ,
V_11 -> V_5 . V_53 ) ;
F_35 ( & V_2 -> V_26 . V_37 [ V_48 ] ,
V_11 -> V_5 . V_54 ) ;
V_50 = sizeof( struct V_8 ) * V_51 ;
V_9 = F_39 ( V_2 -> V_43 , V_50 , V_55 ) ;
if ( ! V_9 )
return - V_56 ;
F_40 ( & V_2 -> V_26 . V_40 ) ;
for ( V_52 = 0 ; V_52 < V_51 ; V_52 ++ , V_9 ++ ) {
V_17 = F_41 ( V_13 , V_13 -> V_25 , V_55 ) ;
if ( ! V_17 ) {
error = - V_56 ;
goto V_57;
}
memset ( V_17 -> V_24 , 0 , V_13 -> V_25 ) ;
V_9 -> V_22 = V_17 ;
V_9 -> V_21 = F_42 ( V_2 -> V_43 , V_17 -> V_24 ,
V_13 -> V_25 ,
V_49 ) ;
if ( F_43 ( F_44 ( V_2 -> V_43 ,
V_9 -> V_21 ) ) ) {
F_34 ( V_17 ) ;
V_9 -> V_22 = NULL ;
V_9 -> V_21 = 0 ;
F_45 ( V_13 ,
L_2 ) ;
error = - V_56 ;
goto V_57;
}
F_30 ( & V_9 -> V_41 , & V_2 -> V_26 . V_40 ) ;
}
return 0 ;
V_57:
F_31 ( V_2 ) ;
return error ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_47 ( V_2 -> V_4 ) ;
F_24 ( V_2 , V_48 ) ;
F_24 ( V_2 , V_47 ) ;
F_10 ( V_2 ) ;
F_48 ( V_2 -> V_4 , ! ! ( V_2 -> V_58 -> V_59 . V_60 & V_61 ) ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_28 ( V_2 , V_48 ) ;
F_28 ( V_2 , V_47 ) ;
}
int F_50 ( struct V_1 * V_2 , int V_51 )
{
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
struct V_16 * V_17 ;
struct V_8 * V_9 ;
int error = 0 ;
F_51 ( & V_2 -> V_62 ) ;
V_13 -> V_25 = V_63 / 2 +
V_2 -> V_4 -> V_5 . V_42 ;
if ( V_2 -> V_4 -> V_5 . V_6 & V_64 )
return F_37 ( V_2 , V_51 ) ;
F_26 ( V_13 , V_65 , L_3 ,
V_13 -> V_66 , V_13 -> V_25 ) ;
error = F_52 ( V_2 , & V_2 -> V_26 . V_67 , & V_2 -> V_26 . V_40 ,
L_4 , V_51 , 1 , 0 ) ;
if ( error != 0 ) {
F_45 ( V_13 ,
L_5 ,
error ) ;
goto V_68;
}
F_32 (bf, &sc->rx.rxbuf, list) {
V_17 = F_41 ( V_13 , V_13 -> V_25 ,
V_55 ) ;
if ( V_17 == NULL ) {
error = - V_56 ;
goto V_68;
}
V_9 -> V_22 = V_17 ;
V_9 -> V_21 = F_42 ( V_2 -> V_43 , V_17 -> V_24 ,
V_13 -> V_25 ,
V_69 ) ;
if ( F_43 ( F_44 ( V_2 -> V_43 ,
V_9 -> V_21 ) ) ) {
F_34 ( V_17 ) ;
V_9 -> V_22 = NULL ;
V_9 -> V_21 = 0 ;
F_45 ( V_13 ,
L_2 ) ;
error = - V_56 ;
goto V_68;
}
}
V_2 -> V_26 . V_27 = NULL ;
V_68:
if ( error )
F_53 ( V_2 ) ;
return error ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_16 * V_17 ;
struct V_8 * V_9 ;
if ( V_2 -> V_4 -> V_5 . V_6 & V_64 ) {
F_31 ( V_2 ) ;
return;
}
F_32 (bf, &sc->rx.rxbuf, list) {
V_17 = V_9 -> V_22 ;
if ( V_17 ) {
F_33 ( V_2 -> V_43 , V_9 -> V_21 ,
V_13 -> V_25 ,
V_69 ) ;
F_54 ( V_17 ) ;
V_9 -> V_21 = 0 ;
V_9 -> V_22 = NULL ;
}
}
}
T_1 F_11 ( struct V_1 * V_2 )
{
T_1 V_32 ;
V_32 = V_70 | V_71
| V_72 ;
if ( V_2 -> V_58 -> V_59 . V_73 )
V_32 |= V_74 | V_75 ;
if ( V_2 -> V_26 . V_76 & V_77 )
V_32 |= V_78 ;
if ( V_2 -> V_4 -> V_79 )
V_32 |= V_80 ;
if ( V_2 -> V_26 . V_76 & V_81 )
V_32 |= V_82 ;
if ( ( V_2 -> V_4 -> V_83 == V_84 ) &&
( V_2 -> V_85 <= 1 ) &&
! ( V_2 -> V_26 . V_76 & V_86 ) )
V_32 |= V_87 ;
else
V_32 |= V_88 ;
if ( ( V_2 -> V_4 -> V_83 == V_89 ) ||
( V_2 -> V_26 . V_76 & V_90 ) )
V_32 |= V_91 ;
if ( F_55 ( & V_2 -> V_58 -> V_59 ) )
V_32 |= V_92 ;
if ( V_2 -> V_85 > 1 || ( V_2 -> V_26 . V_76 & V_93 ) ) {
if ( V_2 -> V_4 -> V_94 . V_95 <= V_96 )
V_32 |= V_80 ;
V_32 |= V_97 ;
}
if ( F_56 ( V_2 -> V_4 ) )
V_32 |= V_98 ;
return V_32 ;
}
int F_57 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_8 * V_9 , * V_45 ;
if ( V_11 -> V_5 . V_6 & V_64 ) {
F_46 ( V_2 ) ;
return 0 ;
}
if ( F_25 ( & V_2 -> V_26 . V_40 ) )
goto V_99;
V_2 -> V_26 . V_27 = NULL ;
F_27 (bf, tbf, &sc->rx.rxbuf, list) {
F_2 ( V_2 , V_9 ) ;
}
if ( F_25 ( & V_2 -> V_26 . V_40 ) )
goto V_99;
V_9 = F_18 ( & V_2 -> V_26 . V_40 , struct V_8 , V_41 ) ;
F_7 ( V_11 , V_9 -> V_28 ) ;
F_47 ( V_11 ) ;
V_99:
F_10 ( V_2 ) ;
F_48 ( V_11 , ! ! ( V_2 -> V_58 -> V_59 . V_60 & V_61 ) ) ;
return 0 ;
}
static void F_58 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 -> V_5 . V_6 & V_64 )
F_59 ( V_2 , 1 , true ) ;
F_59 ( V_2 , 1 , false ) ;
}
bool F_60 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
bool V_100 , V_101 = false ;
F_61 ( V_11 ) ;
F_12 ( V_11 , 0 ) ;
V_100 = F_62 ( V_11 , & V_101 ) ;
F_58 ( V_2 ) ;
if ( V_2 -> V_4 -> V_5 . V_6 & V_64 )
F_49 ( V_2 ) ;
else
V_2 -> V_26 . V_27 = NULL ;
if ( ! ( V_11 -> V_102 & V_103 ) &&
F_43 ( ! V_100 ) ) {
F_45 ( F_3 ( V_2 -> V_4 ) ,
L_6
L_7 ) ;
F_63 ( ! V_100 ) ;
}
return V_100 && ! V_101 ;
}
static bool F_64 ( struct V_16 * V_17 )
{
struct V_104 * V_105 ;
T_2 * V_106 , * V_107 , V_108 , V_109 ;
struct V_110 * V_111 ;
V_105 = (struct V_104 * ) V_17 -> V_24 ;
V_106 = V_105 -> V_112 . V_113 . V_114 ;
V_107 = V_17 -> V_24 + V_17 -> V_115 ;
while ( V_106 + 2 < V_107 ) {
V_108 = * V_106 ++ ;
V_109 = * V_106 ++ ;
if ( V_106 + V_109 > V_107 )
break;
if ( V_108 == V_116 ) {
if ( V_109 < sizeof( * V_111 ) )
break;
V_111 = (struct V_110 * ) V_106 ;
if ( V_111 -> V_117 != 0 )
break;
return V_111 -> V_118 & 0x01 ;
}
V_106 += V_109 ;
}
return false ;
}
static void F_65 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
if ( V_17 -> V_115 < 24 + 8 + 2 + 2 )
return;
V_2 -> V_119 &= ~ V_120 ;
if ( V_2 -> V_119 & V_121 ) {
V_2 -> V_119 &= ~ V_121 ;
F_26 ( V_13 , V_122 ,
L_8 ) ;
F_66 ( V_2 ) ;
}
if ( F_64 ( V_17 ) ) {
F_26 ( V_13 , V_122 ,
L_9 ) ;
V_2 -> V_119 |= V_123 | V_120 ;
return;
}
if ( V_2 -> V_119 & V_123 ) {
V_2 -> V_119 &= ~ V_123 ;
F_26 ( V_13 , V_122 , L_10 ) ;
}
}
static void F_67 ( struct V_1 * V_2 , struct V_16 * V_17 , bool V_124 )
{
struct V_125 * V_126 ;
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
V_126 = (struct V_125 * ) V_17 -> V_24 ;
if ( ( ( V_2 -> V_119 & V_120 ) || F_1 ( V_2 ) )
&& V_124 ) {
F_65 ( V_2 , V_17 ) ;
} else if ( ( V_2 -> V_119 & V_123 ) &&
( F_68 ( V_126 -> V_127 ) ||
F_69 ( V_126 -> V_127 ) ) &&
F_70 ( V_126 -> V_128 ) &&
! F_71 ( V_126 -> V_127 ) ) {
V_2 -> V_119 &= ~ ( V_123 | V_120 ) ;
F_26 ( V_13 , V_122 ,
L_11 ) ;
} else if ( ( V_2 -> V_119 & V_129 ) &&
! F_70 ( V_126 -> V_128 ) &&
! F_72 ( V_126 -> V_127 ) ) {
V_2 -> V_119 &= ~ V_129 ;
F_26 ( V_13 , V_122 ,
L_12 ,
V_2 -> V_119 & ( V_120 |
V_123 |
V_129 |
V_130 ) ) ;
}
}
static bool F_73 ( struct V_1 * V_2 ,
enum V_34 V_35 ,
struct V_131 * V_132 ,
struct V_8 * * V_133 )
{
struct V_36 * V_37 = & V_2 -> V_26 . V_37 [ V_35 ] ;
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_16 * V_17 ;
struct V_8 * V_9 ;
int V_134 ;
V_17 = F_74 ( & V_37 -> V_38 ) ;
if ( ! V_17 )
return false ;
V_9 = F_21 ( V_17 ) ;
F_5 ( ! V_9 ) ;
F_75 ( V_2 -> V_43 , V_9 -> V_21 ,
V_13 -> V_25 , V_69 ) ;
V_134 = F_76 ( V_11 , V_132 , V_17 -> V_24 ) ;
if ( V_134 == - V_135 ) {
F_20 ( V_2 -> V_43 , V_9 -> V_21 ,
V_13 -> V_25 , V_69 ) ;
return false ;
}
F_77 ( V_17 , & V_37 -> V_38 ) ;
if ( V_134 == - V_136 ) {
F_30 ( & V_9 -> V_41 , & V_2 -> V_26 . V_40 ) ;
F_16 ( V_2 , V_35 ) ;
V_17 = F_74 ( & V_37 -> V_38 ) ;
if ( V_17 ) {
V_9 = F_21 ( V_17 ) ;
F_5 ( ! V_9 ) ;
F_77 ( V_17 , & V_37 -> V_38 ) ;
F_30 ( & V_9 -> V_41 , & V_2 -> V_26 . V_40 ) ;
F_16 ( V_2 , V_35 ) ;
}
V_9 = NULL ;
}
* V_133 = V_9 ;
return true ;
}
static struct V_8 * F_78 ( struct V_1 * V_2 ,
struct V_131 * V_132 ,
enum V_34 V_35 )
{
struct V_8 * V_9 = NULL ;
while ( F_73 ( V_2 , V_35 , V_132 , & V_9 ) ) {
if ( ! V_9 )
continue;
return V_9 ;
}
return NULL ;
}
static struct V_8 * F_79 ( struct V_1 * V_2 ,
struct V_131 * V_132 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_14 * V_15 ;
struct V_8 * V_9 ;
int V_134 ;
if ( F_25 ( & V_2 -> V_26 . V_40 ) ) {
V_2 -> V_26 . V_27 = NULL ;
return NULL ;
}
V_9 = F_18 ( & V_2 -> V_26 . V_40 , struct V_8 , V_41 ) ;
V_15 = V_9 -> V_18 ;
V_134 = F_80 ( V_11 , V_15 , V_132 ) ;
if ( V_134 == - V_135 ) {
struct V_131 V_137 ;
struct V_8 * V_45 ;
struct V_14 * V_138 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
if ( F_81 ( & V_9 -> V_41 , & V_2 -> V_26 . V_40 ) ) {
V_2 -> V_26 . V_27 = NULL ;
return NULL ;
}
V_45 = F_82 ( V_9 -> V_41 . V_139 , struct V_8 , V_41 ) ;
V_138 = V_45 -> V_18 ;
V_134 = F_80 ( V_11 , V_138 , & V_137 ) ;
if ( V_134 == - V_135 )
return NULL ;
V_132 -> V_140 = 0 ;
V_132 -> V_141 = true ;
}
F_83 ( & V_9 -> V_41 ) ;
if ( ! V_9 -> V_22 )
return V_9 ;
F_75 ( V_2 -> V_43 , V_9 -> V_21 ,
V_13 -> V_25 ,
V_69 ) ;
return V_9 ;
}
static bool F_84 ( struct V_12 * V_13 ,
struct V_125 * V_126 ,
struct V_142 * V_143 ,
struct V_131 * V_144 ,
bool * V_145 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 -> V_146 ;
bool V_147 , V_148 , V_149 , V_150 ;
struct V_10 * V_11 = V_13 -> V_11 ;
T_3 V_151 ;
T_2 V_42 = V_11 -> V_5 . V_42 ;
V_151 = V_126 -> V_127 ;
V_147 = ! ! F_70 ( V_126 -> V_128 ) ;
V_148 = V_144 -> V_152 != V_153 &&
F_85 ( V_144 -> V_152 , V_13 -> V_154 ) ;
V_149 = V_148 && F_68 ( V_151 ) &&
F_86 ( V_151 ) &&
! ( V_144 -> V_155 &
( V_156 | V_157 | V_158 |
V_159 ) ) ;
if ( V_144 -> V_152 == V_153 ||
! F_85 ( V_144 -> V_152 , V_13 -> V_160 ) )
V_144 -> V_155 &= ~ V_159 ;
if ( ! V_144 -> V_140 ) {
F_87 ( V_161 ) ;
return false ;
}
if ( V_144 -> V_140 > ( V_13 -> V_25 - V_42 ) ) {
F_87 ( V_161 ) ;
return false ;
}
if ( V_144 -> V_141 )
return true ;
V_150 = V_148 && ! F_88 ( V_151 ) &&
! F_72 ( V_151 ) &&
! ( F_89 ( V_126 -> V_162 ) & V_163 ) &&
( V_144 -> V_155 & V_158 ) ;
if ( V_144 -> V_155 != 0 ) {
T_2 V_164 ;
if ( V_144 -> V_155 & V_157 ) {
V_143 -> V_165 |= V_166 ;
V_150 = false ;
}
if ( V_144 -> V_155 & V_167 )
return false ;
if ( ( V_144 -> V_155 & V_156 ) ||
( ! V_147 && ( V_144 -> V_155 & V_159 ) ) ) {
* V_145 = true ;
V_150 = false ;
}
V_164 = V_156 | V_158 |
V_159 ;
if ( V_11 -> V_79 && ( V_2 -> V_26 . V_76 & V_168 ) )
V_164 |= V_157 ;
if ( V_144 -> V_155 & ~ V_164 )
return false ;
}
if ( V_149 )
V_143 -> V_165 |= V_169 ;
else if ( V_147 && V_150 )
V_143 -> V_165 |= V_170 ;
return true ;
}
static int F_90 ( struct V_12 * V_13 ,
struct V_171 * V_58 ,
struct V_131 * V_144 ,
struct V_142 * V_143 )
{
struct V_172 * V_173 ;
enum V_174 V_175 ;
unsigned int V_52 = 0 ;
struct V_1 T_4 * V_2 = V_13 -> V_146 ;
V_175 = V_58 -> V_59 . V_176 . V_177 -> V_175 ;
V_173 = V_58 -> V_178 -> V_179 [ V_175 ] ;
if ( V_144 -> V_180 & 0x80 ) {
V_143 -> V_165 |= V_181 ;
V_143 -> V_165 |= V_144 -> V_165 ;
V_143 -> V_182 = V_144 -> V_180 & 0x7f ;
return 0 ;
}
for ( V_52 = 0 ; V_52 < V_173 -> V_183 ; V_52 ++ ) {
if ( V_173 -> V_184 [ V_52 ] . V_185 == V_144 -> V_180 ) {
V_143 -> V_182 = V_52 ;
return 0 ;
}
if ( V_173 -> V_184 [ V_52 ] . V_186 == V_144 -> V_180 ) {
V_143 -> V_165 |= V_187 ;
V_143 -> V_182 = V_52 ;
return 0 ;
}
}
F_26 ( V_13 , V_188 ,
L_13 ,
V_144 -> V_180 ) ;
F_87 ( V_189 ) ;
return - V_136 ;
}
static void F_91 ( struct V_12 * V_13 ,
struct V_171 * V_58 ,
struct V_125 * V_126 ,
struct V_131 * V_144 )
{
struct V_1 * V_2 = V_58 -> V_146 ;
struct V_10 * V_11 = V_13 -> V_11 ;
int V_190 ;
int V_191 = V_144 -> V_192 ;
if ( ! V_144 -> V_193 ||
( ( V_11 -> V_83 != V_84 ) &&
( V_11 -> V_83 != V_194 ) ) )
return;
if ( V_144 -> V_192 != V_195 && ! V_144 -> V_196 )
F_92 ( V_2 -> V_190 , V_144 -> V_192 ) ;
V_190 = V_2 -> V_190 ;
if ( F_93 ( V_190 != V_197 ) )
V_191 = F_94 ( V_190 , V_198 ) ;
if ( V_191 < 0 )
V_191 = 0 ;
V_11 -> V_199 . V_200 = V_191 ;
}
static int F_95 ( struct V_1 * V_2 ,
struct V_125 * V_126 ,
struct V_131 * V_144 ,
struct V_142 * V_201 ,
bool * V_145 )
{
struct V_171 * V_58 = V_2 -> V_58 ;
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
bool V_202 = V_2 -> V_26 . V_203 ;
V_2 -> V_26 . V_203 = V_144 -> V_141 ;
if ( V_202 )
return - V_136 ;
if ( ! F_84 ( V_13 , V_126 , V_201 , V_144 , V_145 ) )
return - V_136 ;
if ( V_144 -> V_141 )
return 0 ;
if ( F_90 ( V_13 , V_58 , V_144 , V_201 ) )
return - V_136 ;
F_91 ( V_13 , V_58 , V_126 , V_144 ) ;
V_201 -> V_175 = V_58 -> V_59 . V_176 . V_177 -> V_175 ;
V_201 -> V_204 = V_58 -> V_59 . V_176 . V_177 -> V_205 ;
V_201 -> signal = V_11 -> V_206 + V_144 -> V_192 ;
V_201 -> V_29 = V_144 -> V_207 ;
V_201 -> V_165 |= V_208 ;
if ( V_144 -> V_196 )
V_201 -> V_165 |= V_209 ;
V_2 -> V_26 . V_203 = false ;
return 0 ;
}
static void F_96 ( struct V_12 * V_13 ,
struct V_16 * V_17 ,
struct V_131 * V_144 ,
struct V_142 * V_143 ,
bool V_145 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
struct V_125 * V_126 ;
int V_210 , V_211 , V_212 ;
T_2 V_213 ;
T_3 V_151 ;
V_126 = (struct V_125 * ) V_17 -> V_24 ;
V_210 = F_97 ( V_17 ) ;
V_151 = V_126 -> V_127 ;
V_211 = F_98 ( V_151 ) ;
V_212 = V_211 & 3 ;
if ( V_212 && V_17 -> V_115 >= V_211 + V_212 + V_214 ) {
memmove ( V_17 -> V_24 + V_212 , V_17 -> V_24 , V_211 ) ;
F_99 ( V_17 , V_212 ) ;
}
V_213 = V_144 -> V_152 ;
if ( ! ( V_213 == V_153 ) && ! V_145 &&
F_86 ( V_151 ) ) {
V_143 -> V_165 |= V_215 ;
} else if ( F_86 ( V_151 )
&& ! V_145 && V_17 -> V_115 >= V_210 + 4 ) {
V_213 = V_17 -> V_24 [ V_210 + 3 ] >> 6 ;
if ( F_85 ( V_213 , V_13 -> V_216 ) )
V_143 -> V_165 |= V_215 ;
}
if ( V_11 -> V_217 &&
( V_143 -> V_165 & V_215 ) &&
F_100 ( V_151 ) )
V_143 -> V_165 &= ~ V_215 ;
}
static T_5 F_101 ( T_2 V_218 )
{
if ( V_218 == 128 )
V_218 = 0 ;
return ( T_5 ) V_218 ;
}
static int F_102 ( struct V_1 * V_2 , struct V_125 * V_126 ,
struct V_131 * V_132 , T_6 V_219 )
{
#ifdef F_103
struct V_10 * V_11 = V_2 -> V_4 ;
T_2 V_220 [ V_221 ] ;
T_2 * V_222 = ( T_2 * ) V_126 ;
struct V_223 V_224 ;
struct V_225 * V_226 ;
struct V_227 * V_228 ;
int V_115 = V_132 -> V_140 ;
int V_229 ;
T_7 V_230 , V_231 ;
if ( V_132 -> V_232 != V_233 &&
V_132 -> V_232 != V_234 &&
V_132 -> V_232 != V_235 )
return 0 ;
V_226 = ( (struct V_225 * ) & V_222 [ V_115 ] ) - 1 ;
if ( ! ( V_226 -> V_236 & V_237 ) )
return 0 ;
if ( ( V_115 > V_238 + 2 ) ||
( V_115 < V_238 - 1 ) )
return 1 ;
V_224 . V_239 . type = V_240 ;
V_230 = sizeof( V_224 ) - sizeof( V_224 . V_239 ) ;
V_224 . V_239 . V_230 = F_104 ( V_230 ) ;
V_224 . V_204 = F_104 ( V_11 -> V_241 -> V_177 -> V_205 ) ;
V_224 . V_191 = F_101 ( V_132 -> V_242 ) ;
V_224 . V_206 = V_11 -> V_206 ;
switch ( V_115 - V_238 ) {
case 0 :
memcpy ( V_220 , V_222 , V_221 ) ;
break;
case - 1 :
memcpy ( & V_220 [ 1 ] , V_222 , V_221 - 1 ) ;
V_220 [ 0 ] = V_222 [ 0 ] ;
break;
case 2 :
memcpy ( V_220 , V_222 , 30 ) ;
V_220 [ 30 ] = V_222 [ 31 ] ;
memcpy ( & V_220 [ 31 ] , & V_222 [ 33 ] , V_221 - 31 ) ;
break;
case 1 :
V_220 [ 0 ] = V_222 [ 0 ] ;
memcpy ( & V_220 [ 0 ] , V_222 , 30 ) ;
V_220 [ 31 ] = V_222 [ 31 ] ;
memcpy ( & V_220 [ 32 ] , & V_222 [ 33 ] , V_221 - 32 ) ;
break;
default:
return 1 ;
}
V_229 = V_221 / 2 ;
V_220 [ V_229 ] = ( V_220 [ V_229 + 1 ] + V_220 [ V_229 - 1 ] ) / 2 ;
V_228 = ( (struct V_227 * ) V_226 ) - 1 ;
memcpy ( V_224 . V_24 , V_220 , V_221 ) ;
V_224 . V_243 = V_228 -> V_243 & 0xf ;
V_231 = F_105 ( V_228 -> V_244 ) ;
V_224 . V_231 = F_104 ( V_231 ) ;
V_224 . V_245 = F_106 ( V_228 -> V_244 ) ;
V_224 . V_246 = F_107 ( V_228 -> V_244 ) ;
V_224 . V_219 = F_108 ( V_219 ) ;
F_109 ( V_2 , & V_224 . V_239 ) ;
return 1 ;
#else
return 0 ;
#endif
}
static void F_110 ( struct V_1 * V_2 ,
struct V_131 * V_132 , struct V_142 * V_143 )
{
if ( V_132 -> V_247 ) {
V_143 -> V_165 |= V_248 | V_249 ;
V_143 -> V_250 = V_2 -> V_26 . V_251 ;
if ( ! V_132 -> V_196 ) {
V_143 -> V_165 |= V_252 ;
V_2 -> V_26 . V_251 ++ ;
}
if ( V_132 -> V_253 & V_254 )
V_143 -> V_165 |= V_255 ;
}
}
int F_59 ( struct V_1 * V_2 , int V_256 , bool V_257 )
{
struct V_8 * V_9 ;
struct V_16 * V_17 = NULL , * V_258 , * V_259 ;
struct V_142 * V_143 ;
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_171 * V_58 = V_2 -> V_58 ;
struct V_125 * V_126 ;
int V_260 ;
struct V_131 V_132 ;
enum V_34 V_35 ;
bool V_261 = ! ! ( V_11 -> V_5 . V_6 & V_64 ) ;
int V_262 ;
T_2 V_42 = V_11 -> V_5 . V_42 ;
T_6 V_219 = 0 ;
T_1 V_263 = 0 ;
unsigned long V_60 ;
T_8 V_264 ;
if ( V_261 )
V_262 = V_49 ;
else
V_262 = V_69 ;
V_35 = V_257 ? V_48 : V_47 ;
V_219 = F_111 ( V_11 ) ;
V_263 = V_219 & 0xffffffff ;
do {
bool V_145 = false ;
memset ( & V_132 , 0 , sizeof( V_132 ) ) ;
if ( V_261 )
V_9 = F_78 ( V_2 , & V_132 , V_35 ) ;
else
V_9 = F_79 ( V_2 , & V_132 ) ;
if ( ! V_9 )
break;
V_17 = V_9 -> V_22 ;
if ( ! V_17 )
continue;
if ( V_2 -> V_26 . V_265 )
V_259 = V_2 -> V_26 . V_265 ;
else
V_259 = V_17 ;
V_126 = (struct V_125 * ) ( V_259 -> V_24 + V_42 ) ;
V_143 = F_112 ( V_259 ) ;
if ( F_113 ( V_126 -> V_127 ) ) {
F_87 ( V_266 ) ;
if ( ! F_114 ( V_13 -> V_267 ) &&
F_115 ( V_126 -> V_268 , V_13 -> V_267 ) )
V_132 . V_193 = true ;
else
V_132 . V_193 = false ;
}
else
V_132 . V_193 = false ;
if ( F_116 ( V_126 -> V_127 ) &&
! F_117 ( V_126 -> V_127 ) )
V_2 -> V_26 . V_269 ++ ;
F_118 ( V_2 , & V_132 ) ;
memset ( V_143 , 0 , sizeof( struct V_142 ) ) ;
V_143 -> V_270 = ( V_219 & ~ 0xffffffffULL ) | V_132 . V_271 ;
if ( V_132 . V_271 > V_263 &&
F_43 ( V_132 . V_271 - V_263 > 0x10000000 ) )
V_143 -> V_270 -= 0x100000000ULL ;
if ( V_132 . V_271 < V_263 &&
F_43 ( V_263 - V_132 . V_271 > 0x10000000 ) )
V_143 -> V_270 += 0x100000000ULL ;
if ( V_132 . V_232 == V_233 )
F_119 ( V_2 , V_126 , & V_132 , V_143 -> V_270 ) ;
if ( V_132 . V_155 & V_167 ) {
if ( F_102 ( V_2 , V_126 , & V_132 , V_143 -> V_270 ) ) {
F_87 ( V_272 ) ;
goto V_273;
}
}
V_260 = F_95 ( V_2 , V_126 , & V_132 , V_143 ,
& V_145 ) ;
if ( V_260 )
goto V_273;
if ( V_132 . V_193 ) {
V_2 -> V_274 = 0 ;
F_120 ( V_2 , 3 ) ;
}
V_258 = F_41 ( V_13 , V_13 -> V_25 , V_275 ) ;
if ( ! V_258 ) {
F_87 ( V_276 ) ;
goto V_273;
}
V_264 = F_42 ( V_2 -> V_43 , V_258 -> V_24 ,
V_13 -> V_25 , V_262 ) ;
if ( F_43 ( F_44 ( V_2 -> V_43 , V_264 ) ) ) {
F_34 ( V_258 ) ;
goto V_273;
}
F_33 ( V_2 -> V_43 , V_9 -> V_21 ,
V_13 -> V_25 , V_262 ) ;
V_9 -> V_22 = V_258 ;
V_9 -> V_21 = V_264 ;
F_121 ( V_17 , V_132 . V_140 + V_11 -> V_5 . V_42 ) ;
if ( V_11 -> V_5 . V_42 )
F_99 ( V_17 , V_11 -> V_5 . V_42 ) ;
if ( ! V_132 . V_141 )
F_96 ( V_13 , V_259 , & V_132 ,
V_143 , V_145 ) ;
if ( V_132 . V_141 ) {
F_87 ( V_277 ) ;
if ( V_2 -> V_26 . V_265 ) {
F_34 ( V_2 -> V_26 . V_265 ) ;
F_34 ( V_17 ) ;
F_87 ( V_278 ) ;
V_17 = NULL ;
}
V_2 -> V_26 . V_265 = V_17 ;
goto V_279;
}
if ( V_132 . V_155 & V_280 )
goto V_273;
if ( V_2 -> V_26 . V_265 ) {
int V_281 = V_17 -> V_115 - F_122 ( V_259 ) ;
if ( F_123 ( V_259 , 0 , V_281 , V_275 ) < 0 ) {
F_54 ( V_17 ) ;
F_87 ( V_276 ) ;
goto V_273;
}
V_2 -> V_26 . V_265 = NULL ;
F_124 ( V_17 , F_121 ( V_259 , V_17 -> V_115 ) ,
V_17 -> V_115 ) ;
F_34 ( V_17 ) ;
V_17 = V_259 ;
}
if ( V_11 -> V_5 . V_6 & V_282 ) {
if ( V_2 -> V_26 . V_30 != V_132 . V_207 ) {
if ( ++ V_2 -> V_26 . V_31 >= 3 )
F_8 ( V_2 , V_132 . V_207 ) ;
} else {
V_2 -> V_26 . V_31 = 0 ;
}
}
if ( V_143 -> V_165 & V_169 )
F_125 ( V_17 , V_17 -> V_115 - 8 ) ;
F_126 ( & V_2 -> V_283 , V_60 ) ;
if ( ( V_2 -> V_119 & ( V_120 |
V_123 |
V_129 ) ) ||
F_1 ( V_2 ) )
F_67 ( V_2 , V_17 , V_132 . V_193 ) ;
F_127 ( & V_2 -> V_283 , V_60 ) ;
if ( ( V_11 -> V_5 . V_6 & V_282 ) && V_2 -> V_284 == 3 )
F_128 ( V_2 , & V_132 ) ;
F_110 ( V_2 , & V_132 , V_143 ) ;
F_129 ( V_58 , V_17 ) ;
V_273:
if ( V_2 -> V_26 . V_265 ) {
F_34 ( V_2 -> V_26 . V_265 ) ;
V_2 -> V_26 . V_265 = NULL ;
}
V_279:
F_30 ( & V_9 -> V_41 , & V_2 -> V_26 . V_40 ) ;
if ( V_256 )
continue;
if ( V_261 ) {
F_16 ( V_2 , V_35 ) ;
} else {
F_2 ( V_2 , V_9 ) ;
F_47 ( V_11 ) ;
}
} while ( 1 );
if ( ! ( V_11 -> V_285 & V_286 ) ) {
V_11 -> V_285 |= ( V_286 | V_287 ) ;
F_130 ( V_11 ) ;
}
return 0 ;
}
