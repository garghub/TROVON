static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 &&
( V_2 -> V_4 -> V_5 . V_6 & V_7 ) ;
}
static void F_2 ( struct V_1 * V_2 , struct V_8 * V_9 ,
bool V_10 )
{
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
V_16 = V_9 -> V_19 ;
V_16 -> V_20 = 0 ;
V_16 -> V_21 = V_9 -> V_22 ;
V_18 = V_9 -> V_23 ;
F_4 ( V_18 == NULL ) ;
V_16 -> V_24 = V_18 -> V_25 ;
F_5 ( V_12 , V_16 ,
V_14 -> V_26 ,
0 ) ;
if ( V_2 -> V_27 . V_28 )
* V_2 -> V_27 . V_28 = V_9 -> V_29 ;
else if ( ! V_10 )
F_6 ( V_12 , V_9 -> V_29 ) ;
V_2 -> V_27 . V_28 = & V_16 -> V_20 ;
}
static void F_7 ( struct V_1 * V_2 , struct V_8 * V_9 ,
bool V_10 )
{
if ( V_2 -> V_27 . V_30 )
F_2 ( V_2 , V_2 -> V_27 . V_30 , V_10 ) ;
V_2 -> V_27 . V_30 = V_9 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_31 )
{
F_9 ( V_2 -> V_4 , V_31 ) ;
V_2 -> V_27 . V_32 = V_31 ;
V_2 -> V_27 . V_33 = 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
T_1 V_34 , V_35 [ 2 ] ;
V_34 = F_11 ( V_2 ) ;
F_12 ( V_12 , V_34 ) ;
F_13 ( V_14 ) ;
F_14 ( V_12 ) ;
V_35 [ 0 ] = V_35 [ 1 ] = ~ 0 ;
F_15 ( V_12 , V_35 [ 0 ] , V_35 [ 1 ] ) ;
}
static bool F_16 ( struct V_1 * V_2 ,
enum V_36 V_37 )
{
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_38 * V_39 ;
struct V_17 * V_18 ;
struct V_8 * V_9 ;
V_39 = & V_2 -> V_27 . V_39 [ V_37 ] ;
if ( F_17 ( & V_39 -> V_40 ) >= V_39 -> V_41 )
return false ;
V_9 = F_18 ( & V_2 -> V_27 . V_42 , struct V_8 , V_43 ) ;
F_19 ( & V_9 -> V_43 ) ;
V_18 = V_9 -> V_23 ;
memset ( V_18 -> V_25 , 0 , V_12 -> V_5 . V_44 ) ;
F_20 ( V_2 -> V_45 , V_9 -> V_22 ,
V_12 -> V_5 . V_44 , V_46 ) ;
F_21 ( V_18 ) = V_9 ;
F_22 ( V_12 , V_9 -> V_22 , V_37 ) ;
F_23 ( & V_39 -> V_40 , V_18 ) ;
return true ;
}
static void F_24 ( struct V_1 * V_2 ,
enum V_36 V_37 )
{
struct V_13 * V_14 = F_3 ( V_2 -> V_4 ) ;
struct V_8 * V_9 , * V_47 ;
if ( F_25 ( & V_2 -> V_27 . V_42 ) ) {
F_26 ( V_14 , V_48 , L_1 ) ;
return;
}
F_27 (bf, tbf, &sc->rx.rxbuf, list)
if ( ! F_16 ( V_2 , V_37 ) )
break;
}
static void F_28 ( struct V_1 * V_2 ,
enum V_36 V_37 )
{
struct V_8 * V_9 ;
struct V_38 * V_39 ;
struct V_17 * V_18 ;
V_39 = & V_2 -> V_27 . V_39 [ V_37 ] ;
while ( ( V_18 = F_29 ( & V_39 -> V_40 ) ) != NULL ) {
V_9 = F_21 ( V_18 ) ;
F_4 ( ! V_9 ) ;
F_30 ( & V_9 -> V_43 , & V_2 -> V_27 . V_42 ) ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_8 * V_9 ;
F_28 ( V_2 , V_49 ) ;
F_28 ( V_2 , V_50 ) ;
F_32 (bf, &sc->rx.rxbuf, list) {
if ( V_9 -> V_23 ) {
F_33 ( V_2 -> V_45 , V_9 -> V_22 ,
V_14 -> V_26 ,
V_51 ) ;
F_34 ( V_9 -> V_23 ) ;
V_9 -> V_22 = 0 ;
V_9 -> V_23 = NULL ;
}
}
}
static void F_35 ( struct V_38 * V_39 , int V_52 )
{
F_36 ( & V_39 -> V_40 ) ;
V_39 -> V_41 = V_52 ;
}
static int F_37 ( struct V_1 * V_2 , int V_53 )
{
struct V_13 * V_14 = F_3 ( V_2 -> V_4 ) ;
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_17 * V_18 ;
struct V_8 * V_9 ;
int error = 0 , V_54 ;
T_1 V_52 ;
F_38 ( V_12 , V_14 -> V_26 -
V_12 -> V_5 . V_44 ) ;
F_35 ( & V_2 -> V_27 . V_39 [ V_49 ] ,
V_12 -> V_5 . V_55 ) ;
F_35 ( & V_2 -> V_27 . V_39 [ V_50 ] ,
V_12 -> V_5 . V_56 ) ;
V_52 = sizeof( struct V_8 ) * V_53 ;
V_9 = F_39 ( V_2 -> V_45 , V_52 , V_57 ) ;
if ( ! V_9 )
return - V_58 ;
F_40 ( & V_2 -> V_27 . V_42 ) ;
for ( V_54 = 0 ; V_54 < V_53 ; V_54 ++ , V_9 ++ ) {
V_18 = F_41 ( V_14 , V_14 -> V_26 , V_57 ) ;
if ( ! V_18 ) {
error = - V_58 ;
goto V_59;
}
memset ( V_18 -> V_25 , 0 , V_14 -> V_26 ) ;
V_9 -> V_23 = V_18 ;
V_9 -> V_22 = F_42 ( V_2 -> V_45 , V_18 -> V_25 ,
V_14 -> V_26 ,
V_51 ) ;
if ( F_43 ( F_44 ( V_2 -> V_45 ,
V_9 -> V_22 ) ) ) {
F_34 ( V_18 ) ;
V_9 -> V_23 = NULL ;
V_9 -> V_22 = 0 ;
F_45 ( V_14 ,
L_2 ) ;
error = - V_58 ;
goto V_59;
}
F_30 ( & V_9 -> V_43 , & V_2 -> V_27 . V_42 ) ;
}
return 0 ;
V_59:
F_31 ( V_2 ) ;
return error ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_47 ( V_2 -> V_4 ) ;
F_24 ( V_2 , V_50 ) ;
F_24 ( V_2 , V_49 ) ;
F_10 ( V_2 ) ;
F_48 ( V_2 -> V_4 , V_2 -> V_60 -> V_61 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_28 ( V_2 , V_50 ) ;
F_28 ( V_2 , V_49 ) ;
}
int F_50 ( struct V_1 * V_2 , int V_53 )
{
struct V_13 * V_14 = F_3 ( V_2 -> V_4 ) ;
struct V_17 * V_18 ;
struct V_8 * V_9 ;
int error = 0 ;
F_51 ( & V_2 -> V_62 ) ;
V_14 -> V_26 = V_63 / 2 +
V_2 -> V_4 -> V_5 . V_44 ;
if ( V_2 -> V_4 -> V_5 . V_6 & V_64 )
return F_37 ( V_2 , V_53 ) ;
F_26 ( V_14 , V_65 , L_3 ,
V_14 -> V_66 , V_14 -> V_26 ) ;
error = F_52 ( V_2 , & V_2 -> V_27 . V_67 , & V_2 -> V_27 . V_42 ,
L_4 , V_53 , 1 , 0 ) ;
if ( error != 0 ) {
F_45 ( V_14 ,
L_5 ,
error ) ;
goto V_68;
}
F_32 (bf, &sc->rx.rxbuf, list) {
V_18 = F_41 ( V_14 , V_14 -> V_26 ,
V_57 ) ;
if ( V_18 == NULL ) {
error = - V_58 ;
goto V_68;
}
V_9 -> V_23 = V_18 ;
V_9 -> V_22 = F_42 ( V_2 -> V_45 , V_18 -> V_25 ,
V_14 -> V_26 ,
V_69 ) ;
if ( F_43 ( F_44 ( V_2 -> V_45 ,
V_9 -> V_22 ) ) ) {
F_34 ( V_18 ) ;
V_9 -> V_23 = NULL ;
V_9 -> V_22 = 0 ;
F_45 ( V_14 ,
L_2 ) ;
error = - V_58 ;
goto V_68;
}
}
V_2 -> V_27 . V_28 = NULL ;
V_68:
if ( error )
F_53 ( V_2 ) ;
return error ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_17 * V_18 ;
struct V_8 * V_9 ;
if ( V_2 -> V_4 -> V_5 . V_6 & V_64 ) {
F_31 ( V_2 ) ;
return;
}
F_32 (bf, &sc->rx.rxbuf, list) {
V_18 = V_9 -> V_23 ;
if ( V_18 ) {
F_33 ( V_2 -> V_45 , V_9 -> V_22 ,
V_14 -> V_26 ,
V_69 ) ;
F_54 ( V_18 ) ;
V_9 -> V_22 = 0 ;
V_9 -> V_23 = NULL ;
}
}
}
T_1 F_11 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_3 ( V_2 -> V_4 ) ;
T_1 V_34 ;
if ( F_55 ( V_70 ) )
return 0 ;
V_34 = V_71 | V_72
| V_73 ;
if ( V_2 -> V_74 -> V_75 . V_76 )
V_34 |= V_77 | V_78 ;
F_56 ( & V_2 -> V_79 ) ;
if ( V_2 -> V_60 -> V_80 & V_81 )
V_34 |= V_82 ;
if ( V_2 -> V_4 -> V_83 )
V_34 |= V_84 ;
if ( ( V_2 -> V_60 -> V_80 & V_85 ) ||
V_2 -> V_4 -> V_86 . V_87 )
V_34 |= V_88 ;
if ( ( V_2 -> V_4 -> V_89 == V_90 ) &&
( V_2 -> V_60 -> V_91 <= 1 ) &&
! ( V_2 -> V_60 -> V_80 & V_92 ) )
V_34 |= V_93 ;
else
V_34 |= V_94 ;
if ( ( V_2 -> V_4 -> V_89 == V_95 ) ||
( V_2 -> V_60 -> V_80 & V_96 ) )
V_34 |= V_97 ;
if ( V_2 -> V_98 . V_99 != V_100 )
V_34 |= V_101 ;
if ( V_2 -> V_60 -> V_91 > 1 || ( V_2 -> V_60 -> V_80 & V_102 ) ) {
if ( V_2 -> V_4 -> V_103 . V_104 <= V_105 )
V_34 |= V_84 ;
V_34 |= V_106 ;
}
if ( F_57 ( V_2 -> V_4 ) || F_58 ( V_2 -> V_4 ) ||
F_59 ( V_2 -> V_4 ) )
V_34 |= V_107 ;
if ( F_60 () &&
F_61 ( V_108 , & V_14 -> V_109 ) )
V_34 |= V_94 ;
F_62 ( & V_2 -> V_79 ) ;
return V_34 ;
}
void F_63 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_8 * V_9 , * V_47 ;
if ( V_12 -> V_5 . V_6 & V_64 ) {
F_46 ( V_2 ) ;
return;
}
if ( F_25 ( & V_2 -> V_27 . V_42 ) )
goto V_110;
V_2 -> V_27 . V_30 = NULL ;
V_2 -> V_27 . V_28 = NULL ;
F_27 (bf, tbf, &sc->rx.rxbuf, list) {
F_2 ( V_2 , V_9 , false ) ;
}
if ( F_25 ( & V_2 -> V_27 . V_42 ) )
goto V_110;
V_9 = F_18 ( & V_2 -> V_27 . V_42 , struct V_8 , V_43 ) ;
F_6 ( V_12 , V_9 -> V_29 ) ;
F_47 ( V_12 ) ;
V_110:
F_10 ( V_2 ) ;
F_48 ( V_12 , V_2 -> V_60 -> V_61 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 -> V_5 . V_6 & V_64 )
F_65 ( V_2 , 1 , true ) ;
F_65 ( V_2 , 1 , false ) ;
}
bool F_66 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_4 ;
bool V_111 , V_112 = false ;
F_67 ( V_12 ) ;
F_12 ( V_12 , 0 ) ;
V_111 = F_68 ( V_12 , & V_112 ) ;
F_64 ( V_2 ) ;
if ( V_2 -> V_4 -> V_5 . V_6 & V_64 )
F_49 ( V_2 ) ;
else
V_2 -> V_27 . V_28 = NULL ;
if ( ! ( V_12 -> V_113 & V_114 ) &&
F_43 ( ! V_111 ) ) {
F_45 ( F_3 ( V_2 -> V_4 ) ,
L_6
L_7 ) ;
F_69 ( ! V_111 ) ;
}
return V_111 && ! V_112 ;
}
static bool F_70 ( struct V_17 * V_18 )
{
struct V_115 * V_116 ;
T_2 * V_117 , * V_118 , V_119 , V_120 ;
struct V_121 * V_122 ;
V_116 = (struct V_115 * ) V_18 -> V_25 ;
V_117 = V_116 -> V_123 . V_124 . V_125 ;
V_118 = V_18 -> V_25 + V_18 -> V_126 ;
while ( V_117 + 2 < V_118 ) {
V_119 = * V_117 ++ ;
V_120 = * V_117 ++ ;
if ( V_117 + V_120 > V_118 )
break;
if ( V_119 == V_127 ) {
if ( V_120 < sizeof( * V_122 ) )
break;
V_122 = (struct V_121 * ) V_117 ;
if ( V_122 -> V_128 != 0 )
break;
return V_122 -> V_129 & 0x01 ;
}
V_117 += V_120 ;
}
return false ;
}
static void F_71 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_13 * V_14 = F_3 ( V_2 -> V_4 ) ;
bool V_130 = false ;
if ( V_18 -> V_126 < 24 + 8 + 2 + 2 )
return;
V_2 -> V_131 &= ~ V_132 ;
if ( V_2 -> V_131 & V_133 ) {
V_2 -> V_131 &= ~ V_133 ;
F_26 ( V_14 , V_134 ,
L_8 ) ;
#ifdef F_72
if ( F_60 () ) {
if ( V_2 -> V_60 == & V_2 -> V_61 . V_135 )
V_130 = true ;
}
#endif
if ( ! V_130 &&
! ( F_73 ( V_2 -> V_60 -> V_124 . V_136 == 0 ) ) )
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
}
if ( F_70 ( V_18 ) ) {
F_26 ( V_14 , V_134 ,
L_9 ) ;
V_2 -> V_131 |= V_137 | V_132 ;
return;
}
if ( V_2 -> V_131 & V_137 ) {
V_2 -> V_131 &= ~ V_137 ;
F_26 ( V_14 , V_134 , L_10 ) ;
}
}
static void F_76 ( struct V_1 * V_2 , struct V_17 * V_18 , bool V_138 )
{
struct V_139 * V_140 ;
struct V_13 * V_14 = F_3 ( V_2 -> V_4 ) ;
V_140 = (struct V_139 * ) V_18 -> V_25 ;
if ( ( ( V_2 -> V_131 & V_132 ) || F_1 ( V_2 ) )
&& V_138 ) {
F_71 ( V_2 , V_18 ) ;
} else if ( ( V_2 -> V_131 & V_137 ) &&
( F_77 ( V_140 -> V_141 ) ||
F_78 ( V_140 -> V_141 ) ) &&
F_79 ( V_140 -> V_142 ) &&
! F_80 ( V_140 -> V_141 ) ) {
V_2 -> V_131 &= ~ ( V_137 | V_132 ) ;
F_26 ( V_14 , V_134 ,
L_11 ) ;
} else if ( ( V_2 -> V_131 & V_143 ) &&
! F_79 ( V_140 -> V_142 ) &&
! F_81 ( V_140 -> V_141 ) ) {
V_2 -> V_131 &= ~ V_143 ;
F_26 ( V_14 , V_134 ,
L_12 ,
V_2 -> V_131 & ( V_132 |
V_137 |
V_143 |
V_144 ) ) ;
}
}
static bool F_82 ( struct V_1 * V_2 ,
enum V_36 V_37 ,
struct V_145 * V_146 ,
struct V_8 * * V_147 )
{
struct V_38 * V_39 = & V_2 -> V_27 . V_39 [ V_37 ] ;
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_17 * V_18 ;
struct V_8 * V_9 ;
int V_148 ;
V_18 = F_83 ( & V_39 -> V_40 ) ;
if ( ! V_18 )
return false ;
V_9 = F_21 ( V_18 ) ;
F_4 ( ! V_9 ) ;
F_84 ( V_2 -> V_45 , V_9 -> V_22 ,
V_14 -> V_26 , V_69 ) ;
V_148 = F_85 ( V_12 , V_146 , V_18 -> V_25 ) ;
if ( V_148 == - V_149 ) {
F_20 ( V_2 -> V_45 , V_9 -> V_22 ,
V_14 -> V_26 , V_69 ) ;
return false ;
}
F_86 ( V_18 , & V_39 -> V_40 ) ;
if ( V_148 == - V_150 ) {
F_30 ( & V_9 -> V_43 , & V_2 -> V_27 . V_42 ) ;
F_16 ( V_2 , V_37 ) ;
V_18 = F_83 ( & V_39 -> V_40 ) ;
if ( V_18 ) {
V_9 = F_21 ( V_18 ) ;
F_4 ( ! V_9 ) ;
F_86 ( V_18 , & V_39 -> V_40 ) ;
F_30 ( & V_9 -> V_43 , & V_2 -> V_27 . V_42 ) ;
F_16 ( V_2 , V_37 ) ;
}
V_9 = NULL ;
}
* V_147 = V_9 ;
return true ;
}
static struct V_8 * F_87 ( struct V_1 * V_2 ,
struct V_145 * V_146 ,
enum V_36 V_37 )
{
struct V_8 * V_9 = NULL ;
while ( F_82 ( V_2 , V_37 , V_146 , & V_9 ) ) {
if ( ! V_9 )
continue;
return V_9 ;
}
return NULL ;
}
static struct V_8 * F_88 ( struct V_1 * V_2 ,
struct V_145 * V_146 )
{
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_15 * V_16 ;
struct V_8 * V_9 ;
int V_148 ;
if ( F_25 ( & V_2 -> V_27 . V_42 ) ) {
V_2 -> V_27 . V_28 = NULL ;
return NULL ;
}
V_9 = F_18 ( & V_2 -> V_27 . V_42 , struct V_8 , V_43 ) ;
if ( V_9 == V_2 -> V_27 . V_30 )
return NULL ;
V_16 = V_9 -> V_19 ;
V_148 = F_89 ( V_12 , V_16 , V_146 ) ;
if ( V_148 == - V_149 ) {
struct V_145 V_151 ;
struct V_8 * V_47 ;
struct V_15 * V_152 ;
memset ( & V_151 , 0 , sizeof( V_151 ) ) ;
if ( F_90 ( & V_9 -> V_43 , & V_2 -> V_27 . V_42 ) ) {
V_2 -> V_27 . V_28 = NULL ;
return NULL ;
}
V_47 = F_91 ( V_9 -> V_43 . V_153 , struct V_8 , V_43 ) ;
V_152 = V_47 -> V_19 ;
V_148 = F_89 ( V_12 , V_152 , & V_151 ) ;
if ( V_148 == - V_149 )
return NULL ;
V_148 = F_89 ( V_12 , V_16 , V_146 ) ;
if ( V_148 == - V_149 ) {
V_146 -> V_154 = 0 ;
V_146 -> V_155 = true ;
}
}
F_92 ( & V_9 -> V_43 ) ;
if ( ! V_9 -> V_23 )
return V_9 ;
F_84 ( V_2 -> V_45 , V_9 -> V_22 ,
V_14 -> V_26 ,
V_69 ) ;
return V_9 ;
}
static void F_93 ( struct V_145 * V_146 ,
struct V_156 * V_157 ,
T_3 V_158 )
{
T_1 V_159 = V_158 & 0xffffffff ;
V_157 -> V_160 = ( V_158 & ~ 0xffffffffULL ) | V_146 -> V_161 ;
if ( V_146 -> V_161 > V_159 &&
F_43 ( V_146 -> V_161 - V_159 > 0x10000000 ) )
V_157 -> V_160 -= 0x100000000ULL ;
if ( V_146 -> V_161 < V_159 &&
F_43 ( V_159 - V_146 -> V_161 > 0x10000000 ) )
V_157 -> V_160 += 0x100000000ULL ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_145 * V_162 ,
struct V_156 * V_163 ,
bool * V_164 , T_3 V_158 )
{
struct V_165 * V_74 = V_2 -> V_74 ;
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_139 * V_140 ;
bool V_166 = V_2 -> V_27 . V_167 ;
if ( V_166 )
goto V_168;
V_2 -> V_27 . V_167 = false ;
if ( ! V_162 -> V_154 ) {
F_95 ( V_169 ) ;
goto V_168;
}
if ( V_162 -> V_154 > ( V_14 -> V_26 - V_12 -> V_5 . V_44 ) ) {
F_95 ( V_169 ) ;
goto V_168;
}
if ( V_162 -> V_155 )
return 0 ;
if ( V_162 -> V_170 & V_171 )
goto V_168;
V_140 = (struct V_139 * ) ( V_18 -> V_25 + V_12 -> V_5 . V_44 ) ;
F_93 ( V_162 , V_163 , V_158 ) ;
F_96 ( V_2 , V_162 ) ;
if ( V_162 -> V_170 & V_172 ) {
F_97 ( V_2 , V_140 , V_162 , V_163 -> V_160 ) ;
if ( F_98 ( & V_2 -> V_173 , V_140 , V_162 , V_163 -> V_160 ) )
F_95 ( V_174 ) ;
return - V_150 ;
}
F_56 ( & V_2 -> V_79 ) ;
if ( ! F_99 ( V_14 , V_140 , V_163 , V_162 , V_164 ,
V_2 -> V_60 -> V_80 ) ) {
F_62 ( & V_2 -> V_79 ) ;
return - V_150 ;
}
F_62 ( & V_2 -> V_79 ) ;
if ( F_100 ( V_14 , V_140 ) ) {
F_95 ( V_175 ) ;
V_162 -> V_176 = true ;
}
if ( F_101 ( ! V_12 -> V_177 ) )
return - V_150 ;
if ( F_102 ( V_14 , V_74 , V_162 , V_163 ) ) {
F_26 ( V_14 , V_178 , L_13 ,
V_162 -> V_179 ) ;
F_95 ( V_180 ) ;
return - V_150 ;
}
if ( F_60 () ) {
if ( V_162 -> V_176 )
F_103 ( V_2 ,
V_181 ) ;
}
F_104 ( V_14 , V_74 , V_162 , V_163 ) ;
V_163 -> V_182 = V_12 -> V_177 -> V_135 -> V_182 ;
V_163 -> V_183 = V_12 -> V_177 -> V_135 -> V_184 ;
V_163 -> V_31 = V_162 -> V_185 ;
V_163 -> V_186 |= V_187 ;
#ifdef F_105
if ( F_106 ( V_140 -> V_141 ) &&
! F_107 ( V_140 -> V_141 ) )
V_2 -> V_27 . V_188 ++ ;
#endif
return 0 ;
V_168:
V_2 -> V_27 . V_167 = V_162 -> V_155 ;
return - V_150 ;
}
static void F_108 ( struct V_1 * V_2 ,
struct V_145 * V_146 )
{
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_189 * V_190 = & V_12 -> V_5 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
if ( ! ( V_12 -> V_5 . V_6 & V_191 ) )
return;
if ( V_2 -> V_27 . V_32 != V_146 -> V_185 ) {
if ( ++ V_2 -> V_27 . V_33 >= 3 )
F_8 ( V_2 , V_146 -> V_185 ) ;
} else {
V_2 -> V_27 . V_33 = 0 ;
}
if ( V_190 -> V_6 & V_192 ) {
if ( V_14 -> V_193 )
F_109 ( V_2 , V_146 ) ;
} else {
F_109 ( V_2 , V_146 ) ;
}
}
static void F_110 ( struct V_1 * V_2 ,
struct V_145 * V_146 , struct V_156 * V_157 )
{
if ( V_146 -> V_194 ) {
V_157 -> V_186 |= V_195 | V_196 ;
V_157 -> V_197 = V_2 -> V_27 . V_198 ;
if ( ! V_146 -> V_199 ) {
V_157 -> V_186 |= V_200 ;
V_2 -> V_27 . V_198 ++ ;
}
if ( V_146 -> V_201 & V_202 )
V_157 -> V_186 |= V_203 ;
}
}
int F_65 ( struct V_1 * V_2 , int V_10 , bool V_204 )
{
struct V_8 * V_9 ;
struct V_17 * V_18 = NULL , * V_205 , * V_206 ;
struct V_156 * V_157 ;
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_165 * V_74 = V_2 -> V_74 ;
int V_207 ;
struct V_145 V_146 ;
enum V_36 V_37 ;
bool V_208 = ! ! ( V_12 -> V_5 . V_6 & V_64 ) ;
int V_209 ;
T_3 V_158 = 0 ;
unsigned long V_210 ;
T_4 V_211 ;
unsigned int V_212 = 512 ;
struct V_139 * V_140 ;
if ( V_208 )
V_209 = V_51 ;
else
V_209 = V_69 ;
V_37 = V_204 ? V_50 : V_49 ;
V_158 = F_111 ( V_12 ) ;
do {
bool V_164 = false ;
memset ( & V_146 , 0 , sizeof( V_146 ) ) ;
if ( V_208 )
V_9 = F_87 ( V_2 , & V_146 , V_37 ) ;
else
V_9 = F_88 ( V_2 , & V_146 ) ;
if ( ! V_9 )
break;
V_18 = V_9 -> V_23 ;
if ( ! V_18 )
continue;
if ( V_2 -> V_27 . V_213 )
V_206 = V_2 -> V_27 . V_213 ;
else
V_206 = V_18 ;
V_157 = F_112 ( V_206 ) ;
memset ( V_157 , 0 , sizeof( struct V_156 ) ) ;
V_207 = F_94 ( V_2 , V_206 , & V_146 , V_157 ,
& V_164 , V_158 ) ;
if ( V_207 )
goto V_214;
V_205 = F_41 ( V_14 , V_14 -> V_26 , V_215 ) ;
if ( ! V_205 ) {
F_95 ( V_216 ) ;
goto V_214;
}
V_211 = F_42 ( V_2 -> V_45 , V_205 -> V_25 ,
V_14 -> V_26 , V_209 ) ;
if ( F_43 ( F_44 ( V_2 -> V_45 , V_211 ) ) ) {
F_34 ( V_205 ) ;
goto V_214;
}
F_33 ( V_2 -> V_45 , V_9 -> V_22 ,
V_14 -> V_26 , V_209 ) ;
V_9 -> V_23 = V_205 ;
V_9 -> V_22 = V_211 ;
F_113 ( V_18 , V_146 . V_154 + V_12 -> V_5 . V_44 ) ;
if ( V_12 -> V_5 . V_44 )
F_114 ( V_18 , V_12 -> V_5 . V_44 ) ;
if ( ! V_146 . V_155 )
F_115 ( V_14 , V_206 , & V_146 ,
V_157 , V_164 ) ;
if ( V_146 . V_155 ) {
F_95 ( V_217 ) ;
if ( V_2 -> V_27 . V_213 ) {
F_34 ( V_2 -> V_27 . V_213 ) ;
F_34 ( V_18 ) ;
F_95 ( V_218 ) ;
V_18 = NULL ;
}
V_2 -> V_27 . V_213 = V_18 ;
goto V_219;
}
if ( V_2 -> V_27 . V_213 ) {
int V_220 = V_18 -> V_126 - F_116 ( V_206 ) ;
if ( F_117 ( V_206 , 0 , V_220 , V_215 ) < 0 ) {
F_54 ( V_18 ) ;
F_95 ( V_216 ) ;
goto V_214;
}
V_2 -> V_27 . V_213 = NULL ;
F_118 ( V_18 , F_113 ( V_206 , V_18 -> V_126 ) ,
V_18 -> V_126 ) ;
F_34 ( V_18 ) ;
V_18 = V_206 ;
}
if ( V_157 -> V_186 & V_221 )
F_119 ( V_18 , V_18 -> V_126 - 8 ) ;
F_120 ( & V_2 -> V_222 , V_210 ) ;
if ( ( V_2 -> V_131 & ( V_132 |
V_137 |
V_143 ) ) ||
F_1 ( V_2 ) )
F_76 ( V_2 , V_18 , V_146 . V_176 ) ;
F_121 ( & V_2 -> V_222 , V_210 ) ;
F_108 ( V_2 , & V_146 ) ;
F_110 ( V_2 , & V_146 , V_157 ) ;
F_122 ( V_2 , & V_146 , V_18 ) ;
V_140 = (struct V_139 * ) V_18 -> V_25 ;
if ( F_123 ( V_140 -> V_141 ) )
F_124 ( V_2 -> V_4 , V_18 , V_146 . V_161 ) ;
F_125 ( V_74 , V_18 ) ;
V_214:
if ( V_2 -> V_27 . V_213 ) {
F_34 ( V_2 -> V_27 . V_213 ) ;
V_2 -> V_27 . V_213 = NULL ;
}
V_219:
F_30 ( & V_9 -> V_43 , & V_2 -> V_27 . V_42 ) ;
if ( ! V_208 ) {
F_7 ( V_2 , V_9 , V_10 ) ;
if ( ! V_10 )
F_47 ( V_12 ) ;
} else if ( ! V_10 ) {
F_16 ( V_2 , V_37 ) ;
}
if ( ! V_212 -- )
break;
} while ( 1 );
if ( ! ( V_12 -> V_223 & V_224 ) ) {
V_12 -> V_223 |= ( V_224 | V_225 ) ;
F_126 ( V_12 ) ;
}
return 0 ;
}
