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
else if ( V_2 -> V_4 -> V_89 != V_94 )
V_34 |= V_95 ;
if ( ( V_2 -> V_4 -> V_89 == V_96 ) ||
( V_2 -> V_60 -> V_80 & V_97 ) )
V_34 |= V_98 ;
if ( V_2 -> V_99 . V_100 != V_101 )
V_34 |= V_102 ;
if ( V_2 -> V_60 -> V_91 > 1 || ( V_2 -> V_60 -> V_80 & V_103 ) ) {
if ( V_2 -> V_4 -> V_104 . V_105 <= V_106 )
V_34 |= V_84 ;
V_34 |= V_107 ;
}
if ( F_57 ( V_2 -> V_4 ) || F_58 ( V_2 -> V_4 ) ||
F_59 ( V_2 -> V_4 ) )
V_34 |= V_108 ;
if ( F_60 () &&
F_61 ( V_109 , & V_14 -> V_110 ) )
V_34 |= V_95 ;
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
goto V_111;
V_2 -> V_27 . V_30 = NULL ;
V_2 -> V_27 . V_28 = NULL ;
F_27 (bf, tbf, &sc->rx.rxbuf, list) {
F_2 ( V_2 , V_9 , false ) ;
}
if ( F_25 ( & V_2 -> V_27 . V_42 ) )
goto V_111;
V_9 = F_18 ( & V_2 -> V_27 . V_42 , struct V_8 , V_43 ) ;
F_6 ( V_12 , V_9 -> V_29 ) ;
F_47 ( V_12 ) ;
V_111:
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
bool V_112 , V_113 = false ;
F_67 ( V_12 ) ;
F_12 ( V_12 , 0 ) ;
V_112 = F_68 ( V_12 , & V_113 ) ;
F_64 ( V_2 ) ;
if ( V_2 -> V_4 -> V_5 . V_6 & V_64 )
F_49 ( V_2 ) ;
else
V_2 -> V_27 . V_28 = NULL ;
if ( ! ( V_12 -> V_114 & V_115 ) &&
F_43 ( ! V_112 ) ) {
F_26 ( F_3 ( V_2 -> V_4 ) , V_116 ,
L_6 ) ;
F_69 ( V_2 , V_117 ) ;
}
return V_112 && ! V_113 ;
}
static bool F_70 ( struct V_17 * V_18 )
{
struct V_118 * V_119 ;
T_2 * V_120 , * V_121 , V_122 , V_123 ;
struct V_124 * V_125 ;
V_119 = (struct V_118 * ) V_18 -> V_25 ;
V_120 = V_119 -> V_126 . V_127 . V_128 ;
V_121 = V_18 -> V_25 + V_18 -> V_129 ;
while ( V_120 + 2 < V_121 ) {
V_122 = * V_120 ++ ;
V_123 = * V_120 ++ ;
if ( V_120 + V_123 > V_121 )
break;
if ( V_122 == V_130 ) {
if ( V_123 < sizeof( * V_125 ) )
break;
V_125 = (struct V_124 * ) V_120 ;
if ( V_125 -> V_131 != 0 )
break;
return V_125 -> V_132 & 0x01 ;
}
V_120 += V_123 ;
}
return false ;
}
static void F_71 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_13 * V_14 = F_3 ( V_2 -> V_4 ) ;
bool V_133 = false ;
if ( V_18 -> V_129 < 24 + 8 + 2 + 2 )
return;
V_2 -> V_134 &= ~ V_135 ;
if ( V_2 -> V_134 & V_136 ) {
V_2 -> V_134 &= ~ V_136 ;
F_26 ( V_14 , V_137 ,
L_7 ) ;
#ifdef F_72
if ( F_60 () ) {
if ( V_2 -> V_60 == & V_2 -> V_61 . V_138 )
V_133 = true ;
}
#endif
if ( ! V_133 &&
! ( F_73 ( V_2 -> V_60 -> V_127 . V_139 == 0 ) ) )
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
}
if ( F_70 ( V_18 ) ) {
F_26 ( V_14 , V_137 ,
L_8 ) ;
V_2 -> V_134 |= V_140 | V_135 ;
return;
}
if ( V_2 -> V_134 & V_140 ) {
V_2 -> V_134 &= ~ V_140 ;
F_26 ( V_14 , V_137 , L_9 ) ;
}
}
static void F_76 ( struct V_1 * V_2 , struct V_17 * V_18 , bool V_141 )
{
struct V_142 * V_143 ;
struct V_13 * V_14 = F_3 ( V_2 -> V_4 ) ;
V_143 = (struct V_142 * ) V_18 -> V_25 ;
if ( ( ( V_2 -> V_134 & V_135 ) || F_1 ( V_2 ) )
&& V_141 ) {
F_71 ( V_2 , V_18 ) ;
} else if ( ( V_2 -> V_134 & V_140 ) &&
( F_77 ( V_143 -> V_144 ) ||
F_78 ( V_143 -> V_144 ) ) &&
F_79 ( V_143 -> V_145 ) &&
! F_80 ( V_143 -> V_144 ) ) {
V_2 -> V_134 &= ~ ( V_140 | V_135 ) ;
F_26 ( V_14 , V_137 ,
L_10 ) ;
} else if ( ( V_2 -> V_134 & V_146 ) &&
! F_79 ( V_143 -> V_145 ) &&
! F_81 ( V_143 -> V_144 ) ) {
V_2 -> V_134 &= ~ V_146 ;
F_26 ( V_14 , V_137 ,
L_11 ,
V_2 -> V_134 & ( V_135 |
V_140 |
V_146 |
V_147 ) ) ;
}
}
static bool F_82 ( struct V_1 * V_2 ,
enum V_36 V_37 ,
struct V_148 * V_149 ,
struct V_8 * * V_150 )
{
struct V_38 * V_39 = & V_2 -> V_27 . V_39 [ V_37 ] ;
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_17 * V_18 ;
struct V_8 * V_9 ;
int V_151 ;
V_18 = F_83 ( & V_39 -> V_40 ) ;
if ( ! V_18 )
return false ;
V_9 = F_21 ( V_18 ) ;
F_4 ( ! V_9 ) ;
F_84 ( V_2 -> V_45 , V_9 -> V_22 ,
V_14 -> V_26 , V_69 ) ;
V_151 = F_85 ( V_12 , V_149 , V_18 -> V_25 ) ;
if ( V_151 == - V_152 ) {
F_20 ( V_2 -> V_45 , V_9 -> V_22 ,
V_14 -> V_26 , V_69 ) ;
return false ;
}
F_86 ( V_18 , & V_39 -> V_40 ) ;
if ( V_151 == - V_153 ) {
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
* V_150 = V_9 ;
return true ;
}
static struct V_8 * F_87 ( struct V_1 * V_2 ,
struct V_148 * V_149 ,
enum V_36 V_37 )
{
struct V_8 * V_9 = NULL ;
while ( F_82 ( V_2 , V_37 , V_149 , & V_9 ) ) {
if ( ! V_9 )
continue;
return V_9 ;
}
return NULL ;
}
static struct V_8 * F_88 ( struct V_1 * V_2 ,
struct V_148 * V_149 )
{
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_15 * V_16 ;
struct V_8 * V_9 ;
int V_151 ;
if ( F_25 ( & V_2 -> V_27 . V_42 ) ) {
V_2 -> V_27 . V_28 = NULL ;
return NULL ;
}
V_9 = F_18 ( & V_2 -> V_27 . V_42 , struct V_8 , V_43 ) ;
if ( V_9 == V_2 -> V_27 . V_30 )
return NULL ;
V_16 = V_9 -> V_19 ;
V_151 = F_89 ( V_12 , V_16 , V_149 ) ;
if ( V_151 == - V_152 ) {
struct V_148 V_154 ;
struct V_8 * V_47 ;
struct V_15 * V_155 ;
memset ( & V_154 , 0 , sizeof( V_154 ) ) ;
if ( F_90 ( & V_9 -> V_43 , & V_2 -> V_27 . V_42 ) ) {
V_2 -> V_27 . V_28 = NULL ;
return NULL ;
}
V_47 = F_91 ( V_9 -> V_43 . V_156 , struct V_8 , V_43 ) ;
V_155 = V_47 -> V_19 ;
V_151 = F_89 ( V_12 , V_155 , & V_154 ) ;
if ( V_151 == - V_152 )
return NULL ;
V_151 = F_89 ( V_12 , V_16 , V_149 ) ;
if ( V_151 == - V_152 ) {
V_149 -> V_157 = 0 ;
V_149 -> V_158 = true ;
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
static void F_93 ( struct V_148 * V_149 ,
struct V_159 * V_160 ,
T_3 V_161 )
{
T_1 V_162 = V_161 & 0xffffffff ;
V_160 -> V_163 = ( V_161 & ~ 0xffffffffULL ) | V_149 -> V_164 ;
if ( V_149 -> V_164 > V_162 &&
F_43 ( V_149 -> V_164 - V_162 > 0x10000000 ) )
V_160 -> V_163 -= 0x100000000ULL ;
if ( V_149 -> V_164 < V_162 &&
F_43 ( V_162 - V_149 -> V_164 > 0x10000000 ) )
V_160 -> V_163 += 0x100000000ULL ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_148 * V_165 ,
struct V_159 * V_166 ,
bool * V_167 , T_3 V_161 )
{
struct V_168 * V_74 = V_2 -> V_74 ;
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_142 * V_143 ;
bool V_169 = V_2 -> V_27 . V_170 ;
if ( V_169 )
goto V_171;
V_2 -> V_27 . V_170 = false ;
if ( ! V_165 -> V_157 ) {
F_95 ( V_172 ) ;
goto V_171;
}
if ( V_165 -> V_157 > ( V_14 -> V_26 - V_12 -> V_5 . V_44 ) ) {
F_95 ( V_172 ) ;
goto V_171;
}
if ( V_165 -> V_158 )
return 0 ;
if ( V_165 -> V_173 & V_174 )
goto V_171;
V_143 = (struct V_142 * ) ( V_18 -> V_25 + V_12 -> V_5 . V_44 ) ;
F_93 ( V_165 , V_166 , V_161 ) ;
F_96 ( V_2 , V_165 ) ;
if ( V_165 -> V_173 & V_175 ) {
F_97 ( V_2 , V_143 , V_165 , V_166 -> V_163 ) ;
if ( F_98 ( & V_2 -> V_176 , V_143 , V_165 , V_166 -> V_163 ) )
F_95 ( V_177 ) ;
return - V_153 ;
}
F_56 ( & V_2 -> V_79 ) ;
if ( ! F_99 ( V_14 , V_143 , V_166 , V_165 , V_167 ,
V_2 -> V_60 -> V_80 ) ) {
F_62 ( & V_2 -> V_79 ) ;
return - V_153 ;
}
F_62 ( & V_2 -> V_79 ) ;
if ( F_100 ( V_14 , V_143 ) ) {
F_95 ( V_178 ) ;
V_165 -> V_179 = true ;
}
if ( F_101 ( ! V_12 -> V_180 ) )
return - V_153 ;
if ( F_102 ( V_14 , V_74 , V_165 , V_166 ) ) {
F_26 ( V_14 , V_181 , L_12 ,
V_165 -> V_182 ) ;
F_95 ( V_183 ) ;
return - V_153 ;
}
if ( F_60 () ) {
if ( V_165 -> V_179 )
F_103 ( V_2 ,
V_184 ) ;
}
F_104 ( V_14 , V_74 , V_165 , V_166 ) ;
V_166 -> V_185 = V_12 -> V_180 -> V_138 -> V_185 ;
V_166 -> V_186 = V_12 -> V_180 -> V_138 -> V_187 ;
V_166 -> V_31 = V_165 -> V_188 ;
V_166 -> V_189 |= V_190 ;
#ifdef F_105
if ( F_106 ( V_143 -> V_144 ) &&
! F_107 ( V_143 -> V_144 ) )
V_2 -> V_27 . V_191 ++ ;
#endif
return 0 ;
V_171:
V_2 -> V_27 . V_170 = V_165 -> V_158 ;
return - V_153 ;
}
static void F_108 ( struct V_1 * V_2 ,
struct V_148 * V_149 )
{
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_192 * V_193 = & V_12 -> V_5 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
if ( ! ( V_12 -> V_5 . V_6 & V_194 ) )
return;
if ( V_2 -> V_27 . V_32 != V_149 -> V_188 ) {
if ( ++ V_2 -> V_27 . V_33 >= 3 )
F_8 ( V_2 , V_149 -> V_188 ) ;
} else {
V_2 -> V_27 . V_33 = 0 ;
}
if ( V_193 -> V_6 & V_195 ) {
if ( V_14 -> V_196 )
F_109 ( V_2 , V_149 ) ;
} else {
F_109 ( V_2 , V_149 ) ;
}
}
static void F_110 ( struct V_1 * V_2 ,
struct V_148 * V_149 , struct V_159 * V_160 )
{
if ( V_149 -> V_197 ) {
V_160 -> V_189 |= V_198 | V_199 ;
V_160 -> V_200 = V_2 -> V_27 . V_201 ;
if ( ! V_149 -> V_202 ) {
V_160 -> V_189 |= V_203 ;
V_2 -> V_27 . V_201 ++ ;
}
if ( V_149 -> V_204 & V_205 )
V_160 -> V_189 |= V_206 ;
}
}
int F_65 ( struct V_1 * V_2 , int V_10 , bool V_207 )
{
struct V_8 * V_9 ;
struct V_17 * V_18 = NULL , * V_208 , * V_209 ;
struct V_159 * V_160 ;
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_168 * V_74 = V_2 -> V_74 ;
int V_210 ;
struct V_148 V_149 ;
enum V_36 V_37 ;
bool V_211 = ! ! ( V_12 -> V_5 . V_6 & V_64 ) ;
int V_212 ;
T_3 V_161 = 0 ;
unsigned long V_213 ;
T_4 V_214 ;
unsigned int V_215 = 512 ;
struct V_142 * V_143 ;
if ( V_211 )
V_212 = V_51 ;
else
V_212 = V_69 ;
V_37 = V_207 ? V_50 : V_49 ;
V_161 = F_111 ( V_12 ) ;
do {
bool V_167 = false ;
memset ( & V_149 , 0 , sizeof( V_149 ) ) ;
if ( V_211 )
V_9 = F_87 ( V_2 , & V_149 , V_37 ) ;
else
V_9 = F_88 ( V_2 , & V_149 ) ;
if ( ! V_9 )
break;
V_18 = V_9 -> V_23 ;
if ( ! V_18 )
continue;
if ( V_2 -> V_27 . V_216 )
V_209 = V_2 -> V_27 . V_216 ;
else
V_209 = V_18 ;
V_160 = F_112 ( V_209 ) ;
memset ( V_160 , 0 , sizeof( struct V_159 ) ) ;
V_210 = F_94 ( V_2 , V_209 , & V_149 , V_160 ,
& V_167 , V_161 ) ;
if ( V_210 )
goto V_217;
V_208 = F_41 ( V_14 , V_14 -> V_26 , V_218 ) ;
if ( ! V_208 ) {
F_95 ( V_219 ) ;
goto V_217;
}
V_214 = F_42 ( V_2 -> V_45 , V_208 -> V_25 ,
V_14 -> V_26 , V_212 ) ;
if ( F_43 ( F_44 ( V_2 -> V_45 , V_214 ) ) ) {
F_34 ( V_208 ) ;
goto V_217;
}
F_33 ( V_2 -> V_45 , V_9 -> V_22 ,
V_14 -> V_26 , V_212 ) ;
V_9 -> V_23 = V_208 ;
V_9 -> V_22 = V_214 ;
F_113 ( V_18 , V_149 . V_157 + V_12 -> V_5 . V_44 ) ;
if ( V_12 -> V_5 . V_44 )
F_114 ( V_18 , V_12 -> V_5 . V_44 ) ;
if ( ! V_149 . V_158 )
F_115 ( V_14 , V_209 , & V_149 ,
V_160 , V_167 ) ;
if ( V_149 . V_158 ) {
F_95 ( V_220 ) ;
if ( V_2 -> V_27 . V_216 ) {
F_34 ( V_2 -> V_27 . V_216 ) ;
F_34 ( V_18 ) ;
F_95 ( V_221 ) ;
V_18 = NULL ;
}
V_2 -> V_27 . V_216 = V_18 ;
goto V_222;
}
if ( V_2 -> V_27 . V_216 ) {
int V_223 = V_18 -> V_129 - F_116 ( V_209 ) ;
if ( F_117 ( V_209 , 0 , V_223 , V_218 ) < 0 ) {
F_54 ( V_18 ) ;
F_95 ( V_219 ) ;
goto V_217;
}
V_2 -> V_27 . V_216 = NULL ;
F_118 ( V_18 , F_113 ( V_209 , V_18 -> V_129 ) ,
V_18 -> V_129 ) ;
F_34 ( V_18 ) ;
V_18 = V_209 ;
}
if ( V_160 -> V_189 & V_224 )
F_119 ( V_18 , V_18 -> V_129 - 8 ) ;
F_120 ( & V_2 -> V_225 , V_213 ) ;
if ( ( V_2 -> V_134 & ( V_135 |
V_140 |
V_146 ) ) ||
F_1 ( V_2 ) )
F_76 ( V_2 , V_18 , V_149 . V_179 ) ;
F_121 ( & V_2 -> V_225 , V_213 ) ;
F_108 ( V_2 , & V_149 ) ;
F_110 ( V_2 , & V_149 , V_160 ) ;
F_122 ( V_2 , & V_149 , V_18 ) ;
V_143 = (struct V_142 * ) V_18 -> V_25 ;
if ( F_123 ( V_143 -> V_144 ) )
F_124 ( V_2 -> V_4 , V_18 , V_149 . V_164 ) ;
F_125 ( V_74 , V_18 ) ;
V_217:
if ( V_2 -> V_27 . V_216 ) {
F_34 ( V_2 -> V_27 . V_216 ) ;
V_2 -> V_27 . V_216 = NULL ;
}
V_222:
F_30 ( & V_9 -> V_43 , & V_2 -> V_27 . V_42 ) ;
if ( ! V_211 ) {
F_7 ( V_2 , V_9 , V_10 ) ;
if ( ! V_10 )
F_47 ( V_12 ) ;
} else if ( ! V_10 ) {
F_16 ( V_2 , V_37 ) ;
}
if ( ! V_215 -- )
break;
} while ( 1 );
if ( ! ( V_12 -> V_226 & V_227 ) ) {
V_12 -> V_226 |= ( V_227 | V_228 ) ;
F_126 ( V_12 ) ;
}
return 0 ;
}
