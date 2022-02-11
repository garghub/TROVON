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
if ( V_2 -> V_27 . V_79 & V_80 )
V_34 |= V_81 ;
if ( V_2 -> V_4 -> V_82 )
V_34 |= V_83 ;
if ( V_2 -> V_27 . V_79 & V_84 )
V_34 |= V_85 ;
if ( ( V_2 -> V_4 -> V_86 == V_87 ) &&
( V_2 -> V_88 <= 1 ) &&
! ( V_2 -> V_27 . V_79 & V_89 ) )
V_34 |= V_90 ;
else
V_34 |= V_91 ;
if ( ( V_2 -> V_4 -> V_86 == V_92 ) ||
( V_2 -> V_27 . V_79 & V_93 ) )
V_34 |= V_94 ;
if ( F_56 ( & V_2 -> V_74 -> V_75 ) )
V_34 |= V_95 ;
if ( V_2 -> V_88 > 1 || ( V_2 -> V_27 . V_79 & V_96 ) ) {
if ( V_2 -> V_4 -> V_97 . V_98 <= V_99 )
V_34 |= V_83 ;
V_34 |= V_100 ;
}
if ( F_57 ( V_2 -> V_4 ) || F_58 ( V_2 -> V_4 ) )
V_34 |= V_101 ;
if ( V_102 &&
F_59 ( V_103 , & V_14 -> V_104 ) )
V_34 |= V_91 ;
return V_34 ;
}
int F_60 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_8 * V_9 , * V_47 ;
if ( V_12 -> V_5 . V_6 & V_64 ) {
F_46 ( V_2 ) ;
return 0 ;
}
if ( F_25 ( & V_2 -> V_27 . V_42 ) )
goto V_105;
V_2 -> V_27 . V_30 = NULL ;
V_2 -> V_27 . V_28 = NULL ;
F_27 (bf, tbf, &sc->rx.rxbuf, list) {
F_2 ( V_2 , V_9 , false ) ;
}
if ( F_25 ( & V_2 -> V_27 . V_42 ) )
goto V_105;
V_9 = F_18 ( & V_2 -> V_27 . V_42 , struct V_8 , V_43 ) ;
F_6 ( V_12 , V_9 -> V_29 ) ;
F_47 ( V_12 ) ;
V_105:
F_10 ( V_2 ) ;
F_48 ( V_12 , V_2 -> V_60 -> V_61 ) ;
return 0 ;
}
static void F_61 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 -> V_5 . V_6 & V_64 )
F_62 ( V_2 , 1 , true ) ;
F_62 ( V_2 , 1 , false ) ;
}
bool F_63 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_4 ;
bool V_106 , V_107 = false ;
F_64 ( V_12 ) ;
F_12 ( V_12 , 0 ) ;
V_106 = F_65 ( V_12 , & V_107 ) ;
F_61 ( V_2 ) ;
if ( V_2 -> V_4 -> V_5 . V_6 & V_64 )
F_49 ( V_2 ) ;
else
V_2 -> V_27 . V_28 = NULL ;
if ( ! ( V_12 -> V_108 & V_109 ) &&
F_43 ( ! V_106 ) ) {
F_45 ( F_3 ( V_2 -> V_4 ) ,
L_6
L_7 ) ;
F_66 ( ! V_106 ) ;
}
return V_106 && ! V_107 ;
}
static bool F_67 ( struct V_17 * V_18 )
{
struct V_110 * V_111 ;
T_2 * V_112 , * V_113 , V_114 , V_115 ;
struct V_116 * V_117 ;
V_111 = (struct V_110 * ) V_18 -> V_25 ;
V_112 = V_111 -> V_118 . V_119 . V_120 ;
V_113 = V_18 -> V_25 + V_18 -> V_121 ;
while ( V_112 + 2 < V_113 ) {
V_114 = * V_112 ++ ;
V_115 = * V_112 ++ ;
if ( V_112 + V_115 > V_113 )
break;
if ( V_114 == V_122 ) {
if ( V_115 < sizeof( * V_117 ) )
break;
V_117 = (struct V_116 * ) V_112 ;
if ( V_117 -> V_123 != 0 )
break;
return V_117 -> V_124 & 0x01 ;
}
V_112 += V_115 ;
}
return false ;
}
static void F_68 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_13 * V_14 = F_3 ( V_2 -> V_4 ) ;
if ( V_18 -> V_121 < 24 + 8 + 2 + 2 )
return;
V_2 -> V_125 &= ~ V_126 ;
if ( V_2 -> V_125 & V_127 ) {
V_2 -> V_125 &= ~ V_127 ;
F_26 ( V_14 , V_128 ,
L_8 ) ;
if ( ! ( F_69 ( V_2 -> V_60 -> V_119 . V_129 == 0 ) ) )
F_70 ( V_2 ) ;
if ( V_2 -> V_130 )
F_71 ( V_2 , V_2 -> V_130 -> V_131 ) ;
}
if ( F_67 ( V_18 ) ) {
F_26 ( V_14 , V_128 ,
L_9 ) ;
V_2 -> V_125 |= V_132 | V_126 ;
return;
}
if ( V_2 -> V_125 & V_132 ) {
V_2 -> V_125 &= ~ V_132 ;
F_26 ( V_14 , V_128 , L_10 ) ;
}
}
static void F_72 ( struct V_1 * V_2 , struct V_17 * V_18 , bool V_133 )
{
struct V_134 * V_135 ;
struct V_13 * V_14 = F_3 ( V_2 -> V_4 ) ;
V_135 = (struct V_134 * ) V_18 -> V_25 ;
if ( ( ( V_2 -> V_125 & V_126 ) || F_1 ( V_2 ) )
&& V_133 ) {
F_68 ( V_2 , V_18 ) ;
} else if ( ( V_2 -> V_125 & V_132 ) &&
( F_73 ( V_135 -> V_136 ) ||
F_74 ( V_135 -> V_136 ) ) &&
F_75 ( V_135 -> V_137 ) &&
! F_76 ( V_135 -> V_136 ) ) {
V_2 -> V_125 &= ~ ( V_132 | V_126 ) ;
F_26 ( V_14 , V_128 ,
L_11 ) ;
} else if ( ( V_2 -> V_125 & V_138 ) &&
! F_75 ( V_135 -> V_137 ) &&
! F_77 ( V_135 -> V_136 ) ) {
V_2 -> V_125 &= ~ V_138 ;
F_26 ( V_14 , V_128 ,
L_12 ,
V_2 -> V_125 & ( V_126 |
V_132 |
V_138 |
V_139 ) ) ;
}
}
static bool F_78 ( struct V_1 * V_2 ,
enum V_36 V_37 ,
struct V_140 * V_141 ,
struct V_8 * * V_142 )
{
struct V_38 * V_39 = & V_2 -> V_27 . V_39 [ V_37 ] ;
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_17 * V_18 ;
struct V_8 * V_9 ;
int V_143 ;
V_18 = F_79 ( & V_39 -> V_40 ) ;
if ( ! V_18 )
return false ;
V_9 = F_21 ( V_18 ) ;
F_4 ( ! V_9 ) ;
F_80 ( V_2 -> V_45 , V_9 -> V_22 ,
V_14 -> V_26 , V_69 ) ;
V_143 = F_81 ( V_12 , V_141 , V_18 -> V_25 ) ;
if ( V_143 == - V_144 ) {
F_20 ( V_2 -> V_45 , V_9 -> V_22 ,
V_14 -> V_26 , V_69 ) ;
return false ;
}
F_82 ( V_18 , & V_39 -> V_40 ) ;
if ( V_143 == - V_145 ) {
F_30 ( & V_9 -> V_43 , & V_2 -> V_27 . V_42 ) ;
F_16 ( V_2 , V_37 ) ;
V_18 = F_79 ( & V_39 -> V_40 ) ;
if ( V_18 ) {
V_9 = F_21 ( V_18 ) ;
F_4 ( ! V_9 ) ;
F_82 ( V_18 , & V_39 -> V_40 ) ;
F_30 ( & V_9 -> V_43 , & V_2 -> V_27 . V_42 ) ;
F_16 ( V_2 , V_37 ) ;
}
V_9 = NULL ;
}
* V_142 = V_9 ;
return true ;
}
static struct V_8 * F_83 ( struct V_1 * V_2 ,
struct V_140 * V_141 ,
enum V_36 V_37 )
{
struct V_8 * V_9 = NULL ;
while ( F_78 ( V_2 , V_37 , V_141 , & V_9 ) ) {
if ( ! V_9 )
continue;
return V_9 ;
}
return NULL ;
}
static struct V_8 * F_84 ( struct V_1 * V_2 ,
struct V_140 * V_141 )
{
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_15 * V_16 ;
struct V_8 * V_9 ;
int V_143 ;
if ( F_25 ( & V_2 -> V_27 . V_42 ) ) {
V_2 -> V_27 . V_28 = NULL ;
return NULL ;
}
V_9 = F_18 ( & V_2 -> V_27 . V_42 , struct V_8 , V_43 ) ;
if ( V_9 == V_2 -> V_27 . V_30 )
return NULL ;
V_16 = V_9 -> V_19 ;
V_143 = F_85 ( V_12 , V_16 , V_141 ) ;
if ( V_143 == - V_144 ) {
struct V_140 V_146 ;
struct V_8 * V_47 ;
struct V_15 * V_147 ;
memset ( & V_146 , 0 , sizeof( V_146 ) ) ;
if ( F_86 ( & V_9 -> V_43 , & V_2 -> V_27 . V_42 ) ) {
V_2 -> V_27 . V_28 = NULL ;
return NULL ;
}
V_47 = F_87 ( V_9 -> V_43 . V_148 , struct V_8 , V_43 ) ;
V_147 = V_47 -> V_19 ;
V_143 = F_85 ( V_12 , V_147 , & V_146 ) ;
if ( V_143 == - V_144 )
return NULL ;
V_143 = F_85 ( V_12 , V_16 , V_141 ) ;
if ( V_143 == - V_144 ) {
V_141 -> V_149 = 0 ;
V_141 -> V_150 = true ;
}
}
F_88 ( & V_9 -> V_43 ) ;
if ( ! V_9 -> V_23 )
return V_9 ;
F_80 ( V_2 -> V_45 , V_9 -> V_22 ,
V_14 -> V_26 ,
V_69 ) ;
return V_9 ;
}
static void F_89 ( struct V_140 * V_141 ,
struct V_151 * V_152 ,
T_3 V_153 )
{
T_1 V_154 = V_153 & 0xffffffff ;
V_152 -> V_155 = ( V_153 & ~ 0xffffffffULL ) | V_141 -> V_156 ;
if ( V_141 -> V_156 > V_154 &&
F_43 ( V_141 -> V_156 - V_154 > 0x10000000 ) )
V_152 -> V_155 -= 0x100000000ULL ;
if ( V_141 -> V_156 < V_154 &&
F_43 ( V_154 - V_141 -> V_156 > 0x10000000 ) )
V_152 -> V_155 += 0x100000000ULL ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_140 * V_157 ,
struct V_151 * V_158 ,
bool * V_159 , T_3 V_153 )
{
struct V_160 * V_74 = V_2 -> V_74 ;
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_134 * V_135 ;
bool V_161 = V_2 -> V_27 . V_162 ;
if ( V_161 )
goto V_163;
V_2 -> V_27 . V_162 = false ;
if ( ! V_157 -> V_149 ) {
F_91 ( V_164 ) ;
goto V_163;
}
if ( V_157 -> V_149 > ( V_14 -> V_26 - V_12 -> V_5 . V_44 ) ) {
F_91 ( V_164 ) ;
goto V_163;
}
if ( V_157 -> V_150 )
return 0 ;
if ( V_157 -> V_165 & V_166 )
goto V_163;
V_135 = (struct V_134 * ) ( V_18 -> V_25 + V_12 -> V_5 . V_44 ) ;
F_89 ( V_157 , V_158 , V_153 ) ;
F_92 ( V_2 , V_157 ) ;
if ( V_157 -> V_165 & V_167 ) {
F_93 ( V_2 , V_135 , V_157 , V_158 -> V_155 ) ;
if ( F_94 ( V_2 , V_135 , V_157 , V_158 -> V_155 ) )
F_91 ( V_168 ) ;
return - V_145 ;
}
if ( ! F_95 ( V_14 , V_135 , V_158 , V_157 , V_159 , V_2 -> V_27 . V_79 ) )
return - V_145 ;
if ( F_96 ( V_14 , V_135 ) ) {
F_91 ( V_169 ) ;
V_157 -> V_170 = true ;
}
if ( F_97 ( ! V_12 -> V_171 ) )
return - V_145 ;
if ( F_98 ( V_14 , V_74 , V_157 , V_158 ) ) {
F_26 ( V_14 , V_172 , L_13 ,
V_157 -> V_173 ) ;
F_91 ( V_174 ) ;
return - V_145 ;
}
if ( V_157 -> V_170 ) {
V_2 -> V_175 . V_176 = V_157 -> V_156 ;
F_99 ( V_2 , NULL , V_177 ) ;
}
F_100 ( V_14 , V_74 , V_157 , V_158 ) ;
V_158 -> V_178 = V_12 -> V_171 -> V_179 -> V_178 ;
V_158 -> V_180 = V_12 -> V_171 -> V_179 -> V_181 ;
V_158 -> V_31 = V_157 -> V_182 ;
V_158 -> V_183 |= V_184 ;
#ifdef F_101
if ( F_102 ( V_135 -> V_136 ) &&
! F_103 ( V_135 -> V_136 ) )
V_2 -> V_27 . V_185 ++ ;
#endif
return 0 ;
V_163:
V_2 -> V_27 . V_162 = V_157 -> V_150 ;
return - V_145 ;
}
static void F_104 ( struct V_1 * V_2 ,
struct V_140 * V_141 )
{
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_186 * V_187 = & V_12 -> V_5 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
if ( ! ( V_12 -> V_5 . V_6 & V_188 ) )
return;
if ( V_2 -> V_27 . V_32 != V_141 -> V_182 ) {
if ( ++ V_2 -> V_27 . V_33 >= 3 )
F_8 ( V_2 , V_141 -> V_182 ) ;
} else {
V_2 -> V_27 . V_33 = 0 ;
}
if ( V_187 -> V_6 & V_189 ) {
if ( V_14 -> V_190 )
F_105 ( V_2 , V_141 ) ;
} else {
F_105 ( V_2 , V_141 ) ;
}
}
static void F_106 ( struct V_1 * V_2 ,
struct V_140 * V_141 , struct V_151 * V_152 )
{
if ( V_141 -> V_191 ) {
V_152 -> V_183 |= V_192 | V_193 ;
V_152 -> V_194 = V_2 -> V_27 . V_195 ;
if ( ! V_141 -> V_196 ) {
V_152 -> V_183 |= V_197 ;
V_2 -> V_27 . V_195 ++ ;
}
if ( V_141 -> V_198 & V_199 )
V_152 -> V_183 |= V_200 ;
}
}
int F_62 ( struct V_1 * V_2 , int V_10 , bool V_201 )
{
struct V_8 * V_9 ;
struct V_17 * V_18 = NULL , * V_202 , * V_203 ;
struct V_151 * V_152 ;
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_160 * V_74 = V_2 -> V_74 ;
int V_204 ;
struct V_140 V_141 ;
enum V_36 V_37 ;
bool V_205 = ! ! ( V_12 -> V_5 . V_6 & V_64 ) ;
int V_206 ;
T_3 V_153 = 0 ;
unsigned long V_207 ;
T_4 V_208 ;
unsigned int V_209 = 512 ;
if ( V_205 )
V_206 = V_51 ;
else
V_206 = V_69 ;
V_37 = V_201 ? V_50 : V_49 ;
V_153 = F_107 ( V_12 ) ;
do {
bool V_159 = false ;
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
if ( V_205 )
V_9 = F_83 ( V_2 , & V_141 , V_37 ) ;
else
V_9 = F_84 ( V_2 , & V_141 ) ;
if ( ! V_9 )
break;
V_18 = V_9 -> V_23 ;
if ( ! V_18 )
continue;
if ( V_2 -> V_27 . V_210 )
V_203 = V_2 -> V_27 . V_210 ;
else
V_203 = V_18 ;
V_152 = F_108 ( V_203 ) ;
memset ( V_152 , 0 , sizeof( struct V_151 ) ) ;
V_204 = F_90 ( V_2 , V_203 , & V_141 , V_152 ,
& V_159 , V_153 ) ;
if ( V_204 )
goto V_211;
V_202 = F_41 ( V_14 , V_14 -> V_26 , V_212 ) ;
if ( ! V_202 ) {
F_91 ( V_213 ) ;
goto V_211;
}
V_208 = F_42 ( V_2 -> V_45 , V_202 -> V_25 ,
V_14 -> V_26 , V_206 ) ;
if ( F_43 ( F_44 ( V_2 -> V_45 , V_208 ) ) ) {
F_34 ( V_202 ) ;
goto V_211;
}
F_33 ( V_2 -> V_45 , V_9 -> V_22 ,
V_14 -> V_26 , V_206 ) ;
V_9 -> V_23 = V_202 ;
V_9 -> V_22 = V_208 ;
F_109 ( V_18 , V_141 . V_149 + V_12 -> V_5 . V_44 ) ;
if ( V_12 -> V_5 . V_44 )
F_110 ( V_18 , V_12 -> V_5 . V_44 ) ;
if ( ! V_141 . V_150 )
F_111 ( V_14 , V_203 , & V_141 ,
V_152 , V_159 ) ;
if ( V_141 . V_150 ) {
F_91 ( V_214 ) ;
if ( V_2 -> V_27 . V_210 ) {
F_34 ( V_2 -> V_27 . V_210 ) ;
F_34 ( V_18 ) ;
F_91 ( V_215 ) ;
V_18 = NULL ;
}
V_2 -> V_27 . V_210 = V_18 ;
goto V_216;
}
if ( V_2 -> V_27 . V_210 ) {
int V_217 = V_18 -> V_121 - F_112 ( V_203 ) ;
if ( F_113 ( V_203 , 0 , V_217 , V_212 ) < 0 ) {
F_54 ( V_18 ) ;
F_91 ( V_213 ) ;
goto V_211;
}
V_2 -> V_27 . V_210 = NULL ;
F_114 ( V_18 , F_109 ( V_203 , V_18 -> V_121 ) ,
V_18 -> V_121 ) ;
F_34 ( V_18 ) ;
V_18 = V_203 ;
}
if ( V_152 -> V_183 & V_218 )
F_115 ( V_18 , V_18 -> V_121 - 8 ) ;
F_116 ( & V_2 -> V_219 , V_207 ) ;
if ( ( V_2 -> V_125 & ( V_126 |
V_132 |
V_138 ) ) ||
F_1 ( V_2 ) )
F_72 ( V_2 , V_18 , V_141 . V_170 ) ;
F_117 ( & V_2 -> V_219 , V_207 ) ;
F_104 ( V_2 , & V_141 ) ;
F_106 ( V_2 , & V_141 , V_152 ) ;
F_118 ( V_2 , & V_141 , V_18 ) ;
F_119 ( V_74 , V_18 ) ;
V_211:
if ( V_2 -> V_27 . V_210 ) {
F_34 ( V_2 -> V_27 . V_210 ) ;
V_2 -> V_27 . V_210 = NULL ;
}
V_216:
F_30 ( & V_9 -> V_43 , & V_2 -> V_27 . V_42 ) ;
if ( ! V_205 ) {
F_7 ( V_2 , V_9 , V_10 ) ;
if ( ! V_10 )
F_47 ( V_12 ) ;
} else if ( ! V_10 ) {
F_16 ( V_2 , V_37 ) ;
}
if ( ! V_209 -- )
break;
} while ( 1 );
if ( ! ( V_12 -> V_220 & V_221 ) ) {
V_12 -> V_220 |= ( V_221 | V_222 ) ;
F_120 ( V_12 ) ;
}
return 0 ;
}
