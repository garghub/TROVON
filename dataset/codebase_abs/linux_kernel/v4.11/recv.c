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
if ( F_60 ( V_2 -> V_4 ) || F_61 ( V_2 -> V_4 ) )
V_34 |= V_109 ;
if ( F_62 () &&
F_63 ( V_110 , & V_14 -> V_111 ) )
V_34 |= V_95 ;
F_64 ( & V_2 -> V_79 ) ;
return V_34 ;
}
void F_65 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_8 * V_9 , * V_47 ;
if ( V_12 -> V_5 . V_6 & V_64 ) {
F_46 ( V_2 ) ;
return;
}
if ( F_25 ( & V_2 -> V_27 . V_42 ) )
goto V_112;
V_2 -> V_27 . V_30 = NULL ;
V_2 -> V_27 . V_28 = NULL ;
F_27 (bf, tbf, &sc->rx.rxbuf, list) {
F_2 ( V_2 , V_9 , false ) ;
}
if ( F_25 ( & V_2 -> V_27 . V_42 ) )
goto V_112;
V_9 = F_18 ( & V_2 -> V_27 . V_42 , struct V_8 , V_43 ) ;
F_6 ( V_12 , V_9 -> V_29 ) ;
F_47 ( V_12 ) ;
V_112:
F_10 ( V_2 ) ;
F_48 ( V_12 , V_2 -> V_60 -> V_61 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 -> V_5 . V_6 & V_64 )
F_67 ( V_2 , 1 , true ) ;
F_67 ( V_2 , 1 , false ) ;
}
bool F_68 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_4 ;
bool V_113 , V_114 = false ;
F_69 ( V_12 ) ;
F_12 ( V_12 , 0 ) ;
V_113 = F_70 ( V_12 , & V_114 ) ;
F_66 ( V_2 ) ;
if ( V_2 -> V_4 -> V_5 . V_6 & V_64 )
F_49 ( V_2 ) ;
else
V_2 -> V_27 . V_28 = NULL ;
if ( ! ( V_12 -> V_115 & V_116 ) &&
F_43 ( ! V_113 ) ) {
F_26 ( F_3 ( V_2 -> V_4 ) , V_117 ,
L_6 ) ;
F_71 ( V_2 , V_118 ) ;
}
return V_113 && ! V_114 ;
}
static bool F_72 ( struct V_17 * V_18 )
{
struct V_119 * V_120 ;
T_2 * V_121 , * V_122 , V_123 , V_124 ;
struct V_125 * V_126 ;
V_120 = (struct V_119 * ) V_18 -> V_25 ;
V_121 = V_120 -> V_127 . V_128 . V_129 ;
V_122 = V_18 -> V_25 + V_18 -> V_130 ;
while ( V_121 + 2 < V_122 ) {
V_123 = * V_121 ++ ;
V_124 = * V_121 ++ ;
if ( V_121 + V_124 > V_122 )
break;
if ( V_123 == V_131 ) {
if ( V_124 < sizeof( * V_126 ) )
break;
V_126 = (struct V_125 * ) V_121 ;
if ( V_126 -> V_132 != 0 )
break;
return V_126 -> V_133 & 0x01 ;
}
V_121 += V_124 ;
}
return false ;
}
static void F_73 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_13 * V_14 = F_3 ( V_2 -> V_4 ) ;
bool V_134 = false ;
if ( V_18 -> V_130 < 24 + 8 + 2 + 2 )
return;
V_2 -> V_135 &= ~ V_136 ;
if ( V_2 -> V_135 & V_137 ) {
V_2 -> V_135 &= ~ V_137 ;
F_26 ( V_14 , V_138 ,
L_7 ) ;
#ifdef F_74
if ( F_62 () ) {
if ( V_2 -> V_60 == & V_2 -> V_61 . V_139 )
V_134 = true ;
}
#endif
if ( ! V_134 &&
! ( F_75 ( V_2 -> V_60 -> V_128 . V_140 == 0 ) ) )
F_76 ( V_2 ) ;
F_77 ( V_2 ) ;
}
if ( F_72 ( V_18 ) ) {
F_26 ( V_14 , V_138 ,
L_8 ) ;
V_2 -> V_135 |= V_141 | V_136 ;
return;
}
if ( V_2 -> V_135 & V_141 ) {
V_2 -> V_135 &= ~ V_141 ;
F_26 ( V_14 , V_138 , L_9 ) ;
}
}
static void F_78 ( struct V_1 * V_2 , struct V_17 * V_18 , bool V_142 )
{
struct V_143 * V_144 ;
struct V_13 * V_14 = F_3 ( V_2 -> V_4 ) ;
V_144 = (struct V_143 * ) V_18 -> V_25 ;
if ( ( ( V_2 -> V_135 & V_136 ) || F_1 ( V_2 ) )
&& V_142 ) {
F_73 ( V_2 , V_18 ) ;
} else if ( ( V_2 -> V_135 & V_141 ) &&
( F_79 ( V_144 -> V_145 ) ||
F_80 ( V_144 -> V_145 ) ) &&
F_81 ( V_144 -> V_146 ) &&
! F_82 ( V_144 -> V_145 ) ) {
V_2 -> V_135 &= ~ ( V_141 | V_136 ) ;
F_26 ( V_14 , V_138 ,
L_10 ) ;
} else if ( ( V_2 -> V_135 & V_147 ) &&
! F_81 ( V_144 -> V_146 ) &&
! F_83 ( V_144 -> V_145 ) ) {
V_2 -> V_135 &= ~ V_147 ;
F_26 ( V_14 , V_138 ,
L_11 ,
V_2 -> V_135 & ( V_136 |
V_141 |
V_147 |
V_148 ) ) ;
}
}
static bool F_84 ( struct V_1 * V_2 ,
enum V_36 V_37 ,
struct V_149 * V_150 ,
struct V_8 * * V_151 )
{
struct V_38 * V_39 = & V_2 -> V_27 . V_39 [ V_37 ] ;
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_17 * V_18 ;
struct V_8 * V_9 ;
int V_152 ;
V_18 = F_85 ( & V_39 -> V_40 ) ;
if ( ! V_18 )
return false ;
V_9 = F_21 ( V_18 ) ;
F_4 ( ! V_9 ) ;
F_86 ( V_2 -> V_45 , V_9 -> V_22 ,
V_14 -> V_26 , V_69 ) ;
V_152 = F_87 ( V_12 , V_150 , V_18 -> V_25 ) ;
if ( V_152 == - V_153 ) {
F_20 ( V_2 -> V_45 , V_9 -> V_22 ,
V_14 -> V_26 , V_69 ) ;
return false ;
}
F_88 ( V_18 , & V_39 -> V_40 ) ;
if ( V_152 == - V_154 ) {
F_30 ( & V_9 -> V_43 , & V_2 -> V_27 . V_42 ) ;
F_16 ( V_2 , V_37 ) ;
V_18 = F_85 ( & V_39 -> V_40 ) ;
if ( V_18 ) {
V_9 = F_21 ( V_18 ) ;
F_4 ( ! V_9 ) ;
F_88 ( V_18 , & V_39 -> V_40 ) ;
F_30 ( & V_9 -> V_43 , & V_2 -> V_27 . V_42 ) ;
F_16 ( V_2 , V_37 ) ;
}
V_9 = NULL ;
}
* V_151 = V_9 ;
return true ;
}
static struct V_8 * F_89 ( struct V_1 * V_2 ,
struct V_149 * V_150 ,
enum V_36 V_37 )
{
struct V_8 * V_9 = NULL ;
while ( F_84 ( V_2 , V_37 , V_150 , & V_9 ) ) {
if ( ! V_9 )
continue;
return V_9 ;
}
return NULL ;
}
static struct V_8 * F_90 ( struct V_1 * V_2 ,
struct V_149 * V_150 )
{
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_15 * V_16 ;
struct V_8 * V_9 ;
int V_152 ;
if ( F_25 ( & V_2 -> V_27 . V_42 ) ) {
V_2 -> V_27 . V_28 = NULL ;
return NULL ;
}
V_9 = F_18 ( & V_2 -> V_27 . V_42 , struct V_8 , V_43 ) ;
if ( V_9 == V_2 -> V_27 . V_30 )
return NULL ;
V_16 = V_9 -> V_19 ;
V_152 = F_91 ( V_12 , V_16 , V_150 ) ;
if ( V_152 == - V_153 ) {
struct V_149 V_155 ;
struct V_8 * V_47 ;
struct V_15 * V_156 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
if ( F_92 ( & V_9 -> V_43 , & V_2 -> V_27 . V_42 ) ) {
V_2 -> V_27 . V_28 = NULL ;
return NULL ;
}
V_47 = F_93 ( V_9 -> V_43 . V_157 , struct V_8 , V_43 ) ;
V_156 = V_47 -> V_19 ;
V_152 = F_91 ( V_12 , V_156 , & V_155 ) ;
if ( V_152 == - V_153 )
return NULL ;
V_152 = F_91 ( V_12 , V_16 , V_150 ) ;
if ( V_152 == - V_153 ) {
V_150 -> V_158 = 0 ;
V_150 -> V_159 = true ;
}
}
F_94 ( & V_9 -> V_43 ) ;
if ( ! V_9 -> V_23 )
return V_9 ;
F_86 ( V_2 -> V_45 , V_9 -> V_22 ,
V_14 -> V_26 ,
V_69 ) ;
return V_9 ;
}
static void F_95 ( struct V_149 * V_150 ,
struct V_160 * V_161 ,
T_3 V_162 )
{
T_1 V_163 = V_162 & 0xffffffff ;
V_161 -> V_164 = ( V_162 & ~ 0xffffffffULL ) | V_150 -> V_165 ;
if ( V_150 -> V_165 > V_163 &&
F_43 ( V_150 -> V_165 - V_163 > 0x10000000 ) )
V_161 -> V_164 -= 0x100000000ULL ;
if ( V_150 -> V_165 < V_163 &&
F_43 ( V_163 - V_150 -> V_165 > 0x10000000 ) )
V_161 -> V_164 += 0x100000000ULL ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_149 * V_166 ,
struct V_160 * V_167 ,
bool * V_168 , T_3 V_162 )
{
struct V_169 * V_74 = V_2 -> V_74 ;
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_143 * V_144 ;
bool V_170 = V_2 -> V_27 . V_171 ;
if ( V_170 )
goto V_172;
V_2 -> V_27 . V_171 = false ;
if ( ! V_166 -> V_158 ) {
F_97 ( V_173 ) ;
goto V_172;
}
if ( V_166 -> V_158 > ( V_14 -> V_26 - V_12 -> V_5 . V_44 ) ) {
F_97 ( V_173 ) ;
goto V_172;
}
if ( V_166 -> V_159 )
return 0 ;
if ( V_166 -> V_174 & V_175 )
goto V_172;
V_144 = (struct V_143 * ) ( V_18 -> V_25 + V_12 -> V_5 . V_44 ) ;
F_95 ( V_166 , V_167 , V_162 ) ;
F_98 ( V_2 , V_166 ) ;
if ( V_166 -> V_174 & V_176 ) {
if ( V_74 -> V_75 . V_76 ) {
F_99 ( V_2 , V_144 , V_166 ,
V_167 -> V_164 ) ;
} else if ( V_2 -> V_177 . V_178 != V_179 &&
F_100 ( & V_2 -> V_177 , V_144 , V_166 ,
V_167 -> V_164 ) ) {
F_97 ( V_180 ) ;
}
return - V_154 ;
}
F_56 ( & V_2 -> V_79 ) ;
if ( ! F_101 ( V_14 , V_144 , V_167 , V_166 , V_168 ,
V_2 -> V_60 -> V_80 ) ) {
F_64 ( & V_2 -> V_79 ) ;
return - V_154 ;
}
F_64 ( & V_2 -> V_79 ) ;
if ( F_102 ( V_14 , V_144 ) ) {
F_97 ( V_181 ) ;
V_166 -> V_182 = true ;
}
if ( F_103 ( ! V_12 -> V_183 ) )
return - V_154 ;
if ( F_104 ( V_14 , V_74 , V_166 , V_167 ) ) {
F_26 ( V_14 , V_184 , L_12 ,
V_166 -> V_185 ) ;
F_97 ( V_186 ) ;
return - V_154 ;
}
if ( F_62 () ) {
if ( V_166 -> V_182 )
F_105 ( V_2 ,
V_187 ) ;
}
F_106 ( V_14 , V_74 , V_166 , V_167 ) ;
V_167 -> V_188 = V_12 -> V_183 -> V_139 -> V_188 ;
V_167 -> V_189 = V_12 -> V_183 -> V_139 -> V_190 ;
V_167 -> V_31 = V_166 -> V_191 ;
V_167 -> V_192 |= V_193 ;
#ifdef F_107
if ( F_108 ( V_144 -> V_145 ) &&
! F_109 ( V_144 -> V_145 ) )
V_2 -> V_27 . V_194 ++ ;
#endif
return 0 ;
V_172:
V_2 -> V_27 . V_171 = V_166 -> V_159 ;
return - V_154 ;
}
static void F_110 ( struct V_1 * V_2 ,
struct V_149 * V_150 )
{
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_195 * V_196 = & V_12 -> V_5 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
if ( ! ( V_12 -> V_5 . V_6 & V_197 ) )
return;
if ( V_2 -> V_27 . V_32 != V_150 -> V_191 ) {
if ( ++ V_2 -> V_27 . V_33 >= 3 )
F_8 ( V_2 , V_150 -> V_191 ) ;
} else {
V_2 -> V_27 . V_33 = 0 ;
}
if ( V_196 -> V_6 & V_198 ) {
if ( V_14 -> V_199 )
F_111 ( V_2 , V_150 ) ;
} else {
F_111 ( V_2 , V_150 ) ;
}
}
static void F_112 ( struct V_1 * V_2 ,
struct V_149 * V_150 , struct V_160 * V_161 )
{
if ( V_150 -> V_200 ) {
V_161 -> V_192 |= V_201 | V_202 ;
V_161 -> V_203 = V_2 -> V_27 . V_204 ;
if ( ! V_150 -> V_205 ) {
V_161 -> V_192 |= V_206 ;
V_2 -> V_27 . V_204 ++ ;
}
if ( V_150 -> V_207 & V_208 )
V_161 -> V_192 |= V_209 ;
}
}
static void F_113 ( struct V_1 * V_2 ,
struct V_149 * V_150 ,
struct V_17 * V_18 )
{
struct V_210 * V_211 ;
struct V_212 * V_213 ;
struct V_214 * V_215 ;
struct V_143 * V_144 = (struct V_143 * ) V_18 -> V_25 ;
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_216 * V_217 ;
struct V_160 * V_161 ;
const struct V_218 * V_219 ;
bool V_220 , V_221 , V_222 ;
int V_223 ;
T_4 V_130 = V_150 -> V_158 ;
T_1 V_224 = 0 ;
T_2 V_225 , V_226 ;
if ( ! F_79 ( V_144 -> V_145 ) )
return;
F_114 () ;
V_217 = F_115 ( V_2 -> V_74 , V_144 -> V_227 , NULL ) ;
if ( ! V_217 )
goto exit;
V_211 = (struct V_210 * ) V_217 -> V_228 ;
V_215 = (struct V_214 * ) V_211 -> V_229 -> V_228 ;
V_225 = V_18 -> V_230 & V_231 ;
V_226 = F_116 ( V_225 ) ;
V_213 = & V_215 -> V_232 -> V_213 [ V_226 ] ;
V_161 = F_117 ( V_18 ) ;
V_220 = ! ! ( V_161 -> V_192 & V_233 ) ;
V_221 = ! ! ( V_161 -> V_192 & V_234 ) ;
V_222 = ! ! ( V_161 -> V_192 & V_235 ) ;
if ( ! ! ( V_161 -> V_192 & V_236 ) ) {
V_224 += F_118 ( V_2 , V_161 -> V_237 , V_130 ,
V_221 , V_220 , V_222 ) ;
} else {
V_223 = F_119 ( V_150 -> V_185 ) ? V_238 : V_239 ;
V_219 = & V_14 -> V_240 [ V_161 -> V_188 ] . V_241 [ V_161 -> V_237 ] ;
V_224 += F_120 ( V_12 , V_223 , V_219 -> V_242 * 100 ,
V_130 , V_161 -> V_237 , V_222 ) ;
}
if ( ! ! ( V_2 -> V_243 & V_244 ) ) {
F_56 ( & V_213 -> V_245 ) ;
V_211 -> V_246 [ V_226 ] -= V_224 ;
if ( V_211 -> V_246 [ V_226 ] <= 0 )
F_121 ( V_2 , F_122 ( V_211 , V_225 ) ) ;
F_64 ( & V_213 -> V_245 ) ;
}
F_123 ( V_2 , V_211 , V_224 , 0 ) ;
exit:
F_124 () ;
}
int F_67 ( struct V_1 * V_2 , int V_10 , bool V_247 )
{
struct V_8 * V_9 ;
struct V_17 * V_18 = NULL , * V_248 , * V_249 ;
struct V_160 * V_161 ;
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_169 * V_74 = V_2 -> V_74 ;
int V_250 ;
struct V_149 V_150 ;
enum V_36 V_37 ;
bool V_251 = ! ! ( V_12 -> V_5 . V_6 & V_64 ) ;
int V_252 ;
T_3 V_162 = 0 ;
unsigned long V_253 ;
T_5 V_254 ;
unsigned int V_255 = 512 ;
struct V_143 * V_144 ;
if ( V_251 )
V_252 = V_51 ;
else
V_252 = V_69 ;
V_37 = V_247 ? V_50 : V_49 ;
V_162 = F_125 ( V_12 ) ;
do {
bool V_168 = false ;
memset ( & V_150 , 0 , sizeof( V_150 ) ) ;
if ( V_251 )
V_9 = F_89 ( V_2 , & V_150 , V_37 ) ;
else
V_9 = F_90 ( V_2 , & V_150 ) ;
if ( ! V_9 )
break;
V_18 = V_9 -> V_23 ;
if ( ! V_18 )
continue;
if ( V_2 -> V_27 . V_256 )
V_249 = V_2 -> V_27 . V_256 ;
else
V_249 = V_18 ;
V_161 = F_117 ( V_249 ) ;
memset ( V_161 , 0 , sizeof( struct V_160 ) ) ;
V_250 = F_96 ( V_2 , V_249 , & V_150 , V_161 ,
& V_168 , V_162 ) ;
if ( V_250 )
goto V_257;
V_248 = F_41 ( V_14 , V_14 -> V_26 , V_258 ) ;
if ( ! V_248 ) {
F_97 ( V_259 ) ;
goto V_257;
}
V_254 = F_42 ( V_2 -> V_45 , V_248 -> V_25 ,
V_14 -> V_26 , V_252 ) ;
if ( F_43 ( F_44 ( V_2 -> V_45 , V_254 ) ) ) {
F_34 ( V_248 ) ;
goto V_257;
}
F_33 ( V_2 -> V_45 , V_9 -> V_22 ,
V_14 -> V_26 , V_252 ) ;
V_9 -> V_23 = V_248 ;
V_9 -> V_22 = V_254 ;
F_126 ( V_18 , V_150 . V_158 + V_12 -> V_5 . V_44 ) ;
if ( V_12 -> V_5 . V_44 )
F_127 ( V_18 , V_12 -> V_5 . V_44 ) ;
if ( ! V_150 . V_159 )
F_128 ( V_14 , V_249 , & V_150 ,
V_161 , V_168 ) ;
if ( V_150 . V_159 ) {
F_97 ( V_260 ) ;
if ( V_2 -> V_27 . V_256 ) {
F_34 ( V_2 -> V_27 . V_256 ) ;
F_34 ( V_18 ) ;
F_97 ( V_261 ) ;
V_18 = NULL ;
}
V_2 -> V_27 . V_256 = V_18 ;
goto V_262;
}
if ( V_2 -> V_27 . V_256 ) {
int V_263 = V_18 -> V_130 - F_129 ( V_249 ) ;
if ( F_130 ( V_249 , 0 , V_263 , V_258 ) < 0 ) {
F_54 ( V_18 ) ;
F_97 ( V_259 ) ;
goto V_257;
}
V_2 -> V_27 . V_256 = NULL ;
F_131 ( V_18 , F_126 ( V_249 , V_18 -> V_130 ) ,
V_18 -> V_130 ) ;
F_34 ( V_18 ) ;
V_18 = V_249 ;
}
if ( V_161 -> V_192 & V_264 )
F_132 ( V_18 , V_18 -> V_130 - 8 ) ;
F_133 ( & V_2 -> V_265 , V_253 ) ;
if ( ( V_2 -> V_135 & ( V_136 |
V_141 |
V_147 ) ) ||
F_1 ( V_2 ) )
F_78 ( V_2 , V_18 , V_150 . V_182 ) ;
F_134 ( & V_2 -> V_265 , V_253 ) ;
F_110 ( V_2 , & V_150 ) ;
F_112 ( V_2 , & V_150 , V_161 ) ;
F_135 ( V_2 , & V_150 , V_18 ) ;
F_113 ( V_2 , & V_150 , V_18 ) ;
V_144 = (struct V_143 * ) V_18 -> V_25 ;
if ( F_136 ( V_144 -> V_145 ) )
F_137 ( V_2 -> V_4 , V_18 , V_150 . V_165 ) ;
F_138 ( V_74 , V_18 ) ;
V_257:
if ( V_2 -> V_27 . V_256 ) {
F_34 ( V_2 -> V_27 . V_256 ) ;
V_2 -> V_27 . V_256 = NULL ;
}
V_262:
F_30 ( & V_9 -> V_43 , & V_2 -> V_27 . V_42 ) ;
if ( ! V_251 ) {
F_7 ( V_2 , V_9 , V_10 ) ;
if ( ! V_10 )
F_47 ( V_12 ) ;
} else if ( ! V_10 ) {
F_16 ( V_2 , V_37 ) ;
}
if ( ! V_255 -- )
break;
} while ( 1 );
if ( ! ( V_12 -> V_266 & V_267 ) ) {
V_12 -> V_266 |= ( V_267 | V_268 ) ;
F_139 ( V_12 ) ;
}
return 0 ;
}
