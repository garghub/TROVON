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
F_26 ( F_3 ( V_2 -> V_4 ) , V_115 ,
L_6 ) ;
F_69 ( V_2 , V_116 ) ;
}
return V_111 && ! V_112 ;
}
static bool F_70 ( struct V_17 * V_18 )
{
struct V_117 * V_118 ;
T_2 * V_119 , * V_120 , V_121 , V_122 ;
struct V_123 * V_124 ;
V_118 = (struct V_117 * ) V_18 -> V_25 ;
V_119 = V_118 -> V_125 . V_126 . V_127 ;
V_120 = V_18 -> V_25 + V_18 -> V_128 ;
while ( V_119 + 2 < V_120 ) {
V_121 = * V_119 ++ ;
V_122 = * V_119 ++ ;
if ( V_119 + V_122 > V_120 )
break;
if ( V_121 == V_129 ) {
if ( V_122 < sizeof( * V_124 ) )
break;
V_124 = (struct V_123 * ) V_119 ;
if ( V_124 -> V_130 != 0 )
break;
return V_124 -> V_131 & 0x01 ;
}
V_119 += V_122 ;
}
return false ;
}
static void F_71 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_13 * V_14 = F_3 ( V_2 -> V_4 ) ;
bool V_132 = false ;
if ( V_18 -> V_128 < 24 + 8 + 2 + 2 )
return;
V_2 -> V_133 &= ~ V_134 ;
if ( V_2 -> V_133 & V_135 ) {
V_2 -> V_133 &= ~ V_135 ;
F_26 ( V_14 , V_136 ,
L_7 ) ;
#ifdef F_72
if ( F_60 () ) {
if ( V_2 -> V_60 == & V_2 -> V_61 . V_137 )
V_132 = true ;
}
#endif
if ( ! V_132 &&
! ( F_73 ( V_2 -> V_60 -> V_126 . V_138 == 0 ) ) )
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
}
if ( F_70 ( V_18 ) ) {
F_26 ( V_14 , V_136 ,
L_8 ) ;
V_2 -> V_133 |= V_139 | V_134 ;
return;
}
if ( V_2 -> V_133 & V_139 ) {
V_2 -> V_133 &= ~ V_139 ;
F_26 ( V_14 , V_136 , L_9 ) ;
}
}
static void F_76 ( struct V_1 * V_2 , struct V_17 * V_18 , bool V_140 )
{
struct V_141 * V_142 ;
struct V_13 * V_14 = F_3 ( V_2 -> V_4 ) ;
V_142 = (struct V_141 * ) V_18 -> V_25 ;
if ( ( ( V_2 -> V_133 & V_134 ) || F_1 ( V_2 ) )
&& V_140 ) {
F_71 ( V_2 , V_18 ) ;
} else if ( ( V_2 -> V_133 & V_139 ) &&
( F_77 ( V_142 -> V_143 ) ||
F_78 ( V_142 -> V_143 ) ) &&
F_79 ( V_142 -> V_144 ) &&
! F_80 ( V_142 -> V_143 ) ) {
V_2 -> V_133 &= ~ ( V_139 | V_134 ) ;
F_26 ( V_14 , V_136 ,
L_10 ) ;
} else if ( ( V_2 -> V_133 & V_145 ) &&
! F_79 ( V_142 -> V_144 ) &&
! F_81 ( V_142 -> V_143 ) ) {
V_2 -> V_133 &= ~ V_145 ;
F_26 ( V_14 , V_136 ,
L_11 ,
V_2 -> V_133 & ( V_134 |
V_139 |
V_145 |
V_146 ) ) ;
}
}
static bool F_82 ( struct V_1 * V_2 ,
enum V_36 V_37 ,
struct V_147 * V_148 ,
struct V_8 * * V_149 )
{
struct V_38 * V_39 = & V_2 -> V_27 . V_39 [ V_37 ] ;
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_17 * V_18 ;
struct V_8 * V_9 ;
int V_150 ;
V_18 = F_83 ( & V_39 -> V_40 ) ;
if ( ! V_18 )
return false ;
V_9 = F_21 ( V_18 ) ;
F_4 ( ! V_9 ) ;
F_84 ( V_2 -> V_45 , V_9 -> V_22 ,
V_14 -> V_26 , V_69 ) ;
V_150 = F_85 ( V_12 , V_148 , V_18 -> V_25 ) ;
if ( V_150 == - V_151 ) {
F_20 ( V_2 -> V_45 , V_9 -> V_22 ,
V_14 -> V_26 , V_69 ) ;
return false ;
}
F_86 ( V_18 , & V_39 -> V_40 ) ;
if ( V_150 == - V_152 ) {
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
* V_149 = V_9 ;
return true ;
}
static struct V_8 * F_87 ( struct V_1 * V_2 ,
struct V_147 * V_148 ,
enum V_36 V_37 )
{
struct V_8 * V_9 = NULL ;
while ( F_82 ( V_2 , V_37 , V_148 , & V_9 ) ) {
if ( ! V_9 )
continue;
return V_9 ;
}
return NULL ;
}
static struct V_8 * F_88 ( struct V_1 * V_2 ,
struct V_147 * V_148 )
{
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_15 * V_16 ;
struct V_8 * V_9 ;
int V_150 ;
if ( F_25 ( & V_2 -> V_27 . V_42 ) ) {
V_2 -> V_27 . V_28 = NULL ;
return NULL ;
}
V_9 = F_18 ( & V_2 -> V_27 . V_42 , struct V_8 , V_43 ) ;
if ( V_9 == V_2 -> V_27 . V_30 )
return NULL ;
V_16 = V_9 -> V_19 ;
V_150 = F_89 ( V_12 , V_16 , V_148 ) ;
if ( V_150 == - V_151 ) {
struct V_147 V_153 ;
struct V_8 * V_47 ;
struct V_15 * V_154 ;
memset ( & V_153 , 0 , sizeof( V_153 ) ) ;
if ( F_90 ( & V_9 -> V_43 , & V_2 -> V_27 . V_42 ) ) {
V_2 -> V_27 . V_28 = NULL ;
return NULL ;
}
V_47 = F_91 ( V_9 -> V_43 . V_155 , struct V_8 , V_43 ) ;
V_154 = V_47 -> V_19 ;
V_150 = F_89 ( V_12 , V_154 , & V_153 ) ;
if ( V_150 == - V_151 )
return NULL ;
V_150 = F_89 ( V_12 , V_16 , V_148 ) ;
if ( V_150 == - V_151 ) {
V_148 -> V_156 = 0 ;
V_148 -> V_157 = true ;
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
static void F_93 ( struct V_147 * V_148 ,
struct V_158 * V_159 ,
T_3 V_160 )
{
T_1 V_161 = V_160 & 0xffffffff ;
V_159 -> V_162 = ( V_160 & ~ 0xffffffffULL ) | V_148 -> V_163 ;
if ( V_148 -> V_163 > V_161 &&
F_43 ( V_148 -> V_163 - V_161 > 0x10000000 ) )
V_159 -> V_162 -= 0x100000000ULL ;
if ( V_148 -> V_163 < V_161 &&
F_43 ( V_161 - V_148 -> V_163 > 0x10000000 ) )
V_159 -> V_162 += 0x100000000ULL ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_147 * V_164 ,
struct V_158 * V_165 ,
bool * V_166 , T_3 V_160 )
{
struct V_167 * V_74 = V_2 -> V_74 ;
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_141 * V_142 ;
bool V_168 = V_2 -> V_27 . V_169 ;
if ( V_168 )
goto V_170;
V_2 -> V_27 . V_169 = false ;
if ( ! V_164 -> V_156 ) {
F_95 ( V_171 ) ;
goto V_170;
}
if ( V_164 -> V_156 > ( V_14 -> V_26 - V_12 -> V_5 . V_44 ) ) {
F_95 ( V_171 ) ;
goto V_170;
}
if ( V_164 -> V_157 )
return 0 ;
if ( V_164 -> V_172 & V_173 )
goto V_170;
V_142 = (struct V_141 * ) ( V_18 -> V_25 + V_12 -> V_5 . V_44 ) ;
F_93 ( V_164 , V_165 , V_160 ) ;
F_96 ( V_2 , V_164 ) ;
if ( V_164 -> V_172 & V_174 ) {
F_97 ( V_2 , V_142 , V_164 , V_165 -> V_162 ) ;
if ( F_98 ( & V_2 -> V_175 , V_142 , V_164 , V_165 -> V_162 ) )
F_95 ( V_176 ) ;
return - V_152 ;
}
F_56 ( & V_2 -> V_79 ) ;
if ( ! F_99 ( V_14 , V_142 , V_165 , V_164 , V_166 ,
V_2 -> V_60 -> V_80 ) ) {
F_62 ( & V_2 -> V_79 ) ;
return - V_152 ;
}
F_62 ( & V_2 -> V_79 ) ;
if ( F_100 ( V_14 , V_142 ) ) {
F_95 ( V_177 ) ;
V_164 -> V_178 = true ;
}
if ( F_101 ( ! V_12 -> V_179 ) )
return - V_152 ;
if ( F_102 ( V_14 , V_74 , V_164 , V_165 ) ) {
F_26 ( V_14 , V_180 , L_12 ,
V_164 -> V_181 ) ;
F_95 ( V_182 ) ;
return - V_152 ;
}
if ( F_60 () ) {
if ( V_164 -> V_178 )
F_103 ( V_2 ,
V_183 ) ;
}
F_104 ( V_14 , V_74 , V_164 , V_165 ) ;
V_165 -> V_184 = V_12 -> V_179 -> V_137 -> V_184 ;
V_165 -> V_185 = V_12 -> V_179 -> V_137 -> V_186 ;
V_165 -> V_31 = V_164 -> V_187 ;
V_165 -> V_188 |= V_189 ;
#ifdef F_105
if ( F_106 ( V_142 -> V_143 ) &&
! F_107 ( V_142 -> V_143 ) )
V_2 -> V_27 . V_190 ++ ;
#endif
return 0 ;
V_170:
V_2 -> V_27 . V_169 = V_164 -> V_157 ;
return - V_152 ;
}
static void F_108 ( struct V_1 * V_2 ,
struct V_147 * V_148 )
{
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_191 * V_192 = & V_12 -> V_5 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
if ( ! ( V_12 -> V_5 . V_6 & V_193 ) )
return;
if ( V_2 -> V_27 . V_32 != V_148 -> V_187 ) {
if ( ++ V_2 -> V_27 . V_33 >= 3 )
F_8 ( V_2 , V_148 -> V_187 ) ;
} else {
V_2 -> V_27 . V_33 = 0 ;
}
if ( V_192 -> V_6 & V_194 ) {
if ( V_14 -> V_195 )
F_109 ( V_2 , V_148 ) ;
} else {
F_109 ( V_2 , V_148 ) ;
}
}
static void F_110 ( struct V_1 * V_2 ,
struct V_147 * V_148 , struct V_158 * V_159 )
{
if ( V_148 -> V_196 ) {
V_159 -> V_188 |= V_197 | V_198 ;
V_159 -> V_199 = V_2 -> V_27 . V_200 ;
if ( ! V_148 -> V_201 ) {
V_159 -> V_188 |= V_202 ;
V_2 -> V_27 . V_200 ++ ;
}
if ( V_148 -> V_203 & V_204 )
V_159 -> V_188 |= V_205 ;
}
}
int F_65 ( struct V_1 * V_2 , int V_10 , bool V_206 )
{
struct V_8 * V_9 ;
struct V_17 * V_18 = NULL , * V_207 , * V_208 ;
struct V_158 * V_159 ;
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_167 * V_74 = V_2 -> V_74 ;
int V_209 ;
struct V_147 V_148 ;
enum V_36 V_37 ;
bool V_210 = ! ! ( V_12 -> V_5 . V_6 & V_64 ) ;
int V_211 ;
T_3 V_160 = 0 ;
unsigned long V_212 ;
T_4 V_213 ;
unsigned int V_214 = 512 ;
struct V_141 * V_142 ;
if ( V_210 )
V_211 = V_51 ;
else
V_211 = V_69 ;
V_37 = V_206 ? V_50 : V_49 ;
V_160 = F_111 ( V_12 ) ;
do {
bool V_166 = false ;
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
if ( V_210 )
V_9 = F_87 ( V_2 , & V_148 , V_37 ) ;
else
V_9 = F_88 ( V_2 , & V_148 ) ;
if ( ! V_9 )
break;
V_18 = V_9 -> V_23 ;
if ( ! V_18 )
continue;
if ( V_2 -> V_27 . V_215 )
V_208 = V_2 -> V_27 . V_215 ;
else
V_208 = V_18 ;
V_159 = F_112 ( V_208 ) ;
memset ( V_159 , 0 , sizeof( struct V_158 ) ) ;
V_209 = F_94 ( V_2 , V_208 , & V_148 , V_159 ,
& V_166 , V_160 ) ;
if ( V_209 )
goto V_216;
V_207 = F_41 ( V_14 , V_14 -> V_26 , V_217 ) ;
if ( ! V_207 ) {
F_95 ( V_218 ) ;
goto V_216;
}
V_213 = F_42 ( V_2 -> V_45 , V_207 -> V_25 ,
V_14 -> V_26 , V_211 ) ;
if ( F_43 ( F_44 ( V_2 -> V_45 , V_213 ) ) ) {
F_34 ( V_207 ) ;
goto V_216;
}
F_33 ( V_2 -> V_45 , V_9 -> V_22 ,
V_14 -> V_26 , V_211 ) ;
V_9 -> V_23 = V_207 ;
V_9 -> V_22 = V_213 ;
F_113 ( V_18 , V_148 . V_156 + V_12 -> V_5 . V_44 ) ;
if ( V_12 -> V_5 . V_44 )
F_114 ( V_18 , V_12 -> V_5 . V_44 ) ;
if ( ! V_148 . V_157 )
F_115 ( V_14 , V_208 , & V_148 ,
V_159 , V_166 ) ;
if ( V_148 . V_157 ) {
F_95 ( V_219 ) ;
if ( V_2 -> V_27 . V_215 ) {
F_34 ( V_2 -> V_27 . V_215 ) ;
F_34 ( V_18 ) ;
F_95 ( V_220 ) ;
V_18 = NULL ;
}
V_2 -> V_27 . V_215 = V_18 ;
goto V_221;
}
if ( V_2 -> V_27 . V_215 ) {
int V_222 = V_18 -> V_128 - F_116 ( V_208 ) ;
if ( F_117 ( V_208 , 0 , V_222 , V_217 ) < 0 ) {
F_54 ( V_18 ) ;
F_95 ( V_218 ) ;
goto V_216;
}
V_2 -> V_27 . V_215 = NULL ;
F_118 ( V_18 , F_113 ( V_208 , V_18 -> V_128 ) ,
V_18 -> V_128 ) ;
F_34 ( V_18 ) ;
V_18 = V_208 ;
}
if ( V_159 -> V_188 & V_223 )
F_119 ( V_18 , V_18 -> V_128 - 8 ) ;
F_120 ( & V_2 -> V_224 , V_212 ) ;
if ( ( V_2 -> V_133 & ( V_134 |
V_139 |
V_145 ) ) ||
F_1 ( V_2 ) )
F_76 ( V_2 , V_18 , V_148 . V_178 ) ;
F_121 ( & V_2 -> V_224 , V_212 ) ;
F_108 ( V_2 , & V_148 ) ;
F_110 ( V_2 , & V_148 , V_159 ) ;
F_122 ( V_2 , & V_148 , V_18 ) ;
V_142 = (struct V_141 * ) V_18 -> V_25 ;
if ( F_123 ( V_142 -> V_143 ) )
F_124 ( V_2 -> V_4 , V_18 , V_148 . V_163 ) ;
F_125 ( V_74 , V_18 ) ;
V_216:
if ( V_2 -> V_27 . V_215 ) {
F_34 ( V_2 -> V_27 . V_215 ) ;
V_2 -> V_27 . V_215 = NULL ;
}
V_221:
F_30 ( & V_9 -> V_43 , & V_2 -> V_27 . V_42 ) ;
if ( ! V_210 ) {
F_7 ( V_2 , V_9 , V_10 ) ;
if ( ! V_10 )
F_47 ( V_12 ) ;
} else if ( ! V_10 ) {
F_16 ( V_2 , V_37 ) ;
}
if ( ! V_214 -- )
break;
} while ( 1 );
if ( ! ( V_12 -> V_225 & V_226 ) ) {
V_12 -> V_225 |= ( V_226 | V_227 ) ;
F_126 ( V_12 ) ;
}
return 0 ;
}
