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
F_48 ( V_2 -> V_4 , ! ! ( V_2 -> V_60 -> V_61 . V_62 & V_63 ) ) ;
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
F_51 ( & V_2 -> V_64 ) ;
V_14 -> V_26 = V_65 / 2 +
V_2 -> V_4 -> V_5 . V_44 ;
if ( V_2 -> V_4 -> V_5 . V_6 & V_66 )
return F_37 ( V_2 , V_53 ) ;
F_26 ( V_14 , V_67 , L_3 ,
V_14 -> V_68 , V_14 -> V_26 ) ;
error = F_52 ( V_2 , & V_2 -> V_27 . V_69 , & V_2 -> V_27 . V_42 ,
L_4 , V_53 , 1 , 0 ) ;
if ( error != 0 ) {
F_45 ( V_14 ,
L_5 ,
error ) ;
goto V_70;
}
F_32 (bf, &sc->rx.rxbuf, list) {
V_18 = F_41 ( V_14 , V_14 -> V_26 ,
V_57 ) ;
if ( V_18 == NULL ) {
error = - V_58 ;
goto V_70;
}
V_9 -> V_23 = V_18 ;
V_9 -> V_22 = F_42 ( V_2 -> V_45 , V_18 -> V_25 ,
V_14 -> V_26 ,
V_71 ) ;
if ( F_43 ( F_44 ( V_2 -> V_45 ,
V_9 -> V_22 ) ) ) {
F_34 ( V_18 ) ;
V_9 -> V_23 = NULL ;
V_9 -> V_22 = 0 ;
F_45 ( V_14 ,
L_2 ) ;
error = - V_58 ;
goto V_70;
}
}
V_2 -> V_27 . V_28 = NULL ;
V_70:
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
if ( V_2 -> V_4 -> V_5 . V_6 & V_66 ) {
F_31 ( V_2 ) ;
return;
}
F_32 (bf, &sc->rx.rxbuf, list) {
V_18 = V_9 -> V_23 ;
if ( V_18 ) {
F_33 ( V_2 -> V_45 , V_9 -> V_22 ,
V_14 -> V_26 ,
V_71 ) ;
F_54 ( V_18 ) ;
V_9 -> V_22 = 0 ;
V_9 -> V_23 = NULL ;
}
}
}
T_1 F_11 ( struct V_1 * V_2 )
{
T_1 V_34 ;
if ( F_55 ( V_72 ) )
return 0 ;
V_34 = V_73 | V_74
| V_75 ;
if ( V_2 -> V_60 -> V_61 . V_76 )
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
if ( F_56 ( & V_2 -> V_60 -> V_61 ) )
V_34 |= V_95 ;
if ( V_2 -> V_88 > 1 || ( V_2 -> V_27 . V_79 & V_96 ) ) {
if ( V_2 -> V_4 -> V_97 . V_98 <= V_99 )
V_34 |= V_83 ;
V_34 |= V_100 ;
}
if ( F_57 ( V_2 -> V_4 ) || F_58 ( V_2 -> V_4 ) )
V_34 |= V_101 ;
return V_34 ;
}
int F_59 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_8 * V_9 , * V_47 ;
if ( V_12 -> V_5 . V_6 & V_66 ) {
F_46 ( V_2 ) ;
return 0 ;
}
if ( F_25 ( & V_2 -> V_27 . V_42 ) )
goto V_102;
V_2 -> V_27 . V_30 = NULL ;
V_2 -> V_27 . V_28 = NULL ;
F_27 (bf, tbf, &sc->rx.rxbuf, list) {
F_2 ( V_2 , V_9 , false ) ;
}
if ( F_25 ( & V_2 -> V_27 . V_42 ) )
goto V_102;
V_9 = F_18 ( & V_2 -> V_27 . V_42 , struct V_8 , V_43 ) ;
F_6 ( V_12 , V_9 -> V_29 ) ;
F_47 ( V_12 ) ;
V_102:
F_10 ( V_2 ) ;
F_48 ( V_12 , ! ! ( V_2 -> V_60 -> V_61 . V_62 & V_63 ) ) ;
return 0 ;
}
static void F_60 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 -> V_5 . V_6 & V_66 )
F_61 ( V_2 , 1 , true ) ;
F_61 ( V_2 , 1 , false ) ;
}
bool F_62 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_4 ;
bool V_103 , V_104 = false ;
F_63 ( V_12 ) ;
F_12 ( V_12 , 0 ) ;
V_103 = F_64 ( V_12 , & V_104 ) ;
F_60 ( V_2 ) ;
if ( V_2 -> V_4 -> V_5 . V_6 & V_66 )
F_49 ( V_2 ) ;
else
V_2 -> V_27 . V_28 = NULL ;
if ( ! ( V_12 -> V_105 & V_106 ) &&
F_43 ( ! V_103 ) ) {
F_45 ( F_3 ( V_2 -> V_4 ) ,
L_6
L_7 ) ;
F_65 ( ! V_103 ) ;
}
return V_103 && ! V_104 ;
}
static bool F_66 ( struct V_17 * V_18 )
{
struct V_107 * V_108 ;
T_2 * V_109 , * V_110 , V_111 , V_112 ;
struct V_113 * V_114 ;
V_108 = (struct V_107 * ) V_18 -> V_25 ;
V_109 = V_108 -> V_115 . V_116 . V_117 ;
V_110 = V_18 -> V_25 + V_18 -> V_118 ;
while ( V_109 + 2 < V_110 ) {
V_111 = * V_109 ++ ;
V_112 = * V_109 ++ ;
if ( V_109 + V_112 > V_110 )
break;
if ( V_111 == V_119 ) {
if ( V_112 < sizeof( * V_114 ) )
break;
V_114 = (struct V_113 * ) V_109 ;
if ( V_114 -> V_120 != 0 )
break;
return V_114 -> V_121 & 0x01 ;
}
V_109 += V_112 ;
}
return false ;
}
static void F_67 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_13 * V_14 = F_3 ( V_2 -> V_4 ) ;
if ( V_18 -> V_118 < 24 + 8 + 2 + 2 )
return;
V_2 -> V_122 &= ~ V_123 ;
if ( V_2 -> V_122 & V_124 ) {
V_2 -> V_122 &= ~ V_124 ;
F_26 ( V_14 , V_125 ,
L_8 ) ;
if ( ! ( F_68 ( V_2 -> V_126 . V_127 == 0 ) ) )
F_69 ( V_2 ) ;
if ( V_2 -> V_128 )
F_70 ( V_2 , V_2 -> V_128 -> V_129 ) ;
}
if ( F_66 ( V_18 ) ) {
F_26 ( V_14 , V_125 ,
L_9 ) ;
V_2 -> V_122 |= V_130 | V_123 ;
return;
}
if ( V_2 -> V_122 & V_130 ) {
V_2 -> V_122 &= ~ V_130 ;
F_26 ( V_14 , V_125 , L_10 ) ;
}
}
static void F_71 ( struct V_1 * V_2 , struct V_17 * V_18 , bool V_131 )
{
struct V_132 * V_133 ;
struct V_13 * V_14 = F_3 ( V_2 -> V_4 ) ;
V_133 = (struct V_132 * ) V_18 -> V_25 ;
if ( ( ( V_2 -> V_122 & V_123 ) || F_1 ( V_2 ) )
&& V_131 ) {
F_67 ( V_2 , V_18 ) ;
} else if ( ( V_2 -> V_122 & V_130 ) &&
( F_72 ( V_133 -> V_134 ) ||
F_73 ( V_133 -> V_134 ) ) &&
F_74 ( V_133 -> V_135 ) &&
! F_75 ( V_133 -> V_134 ) ) {
V_2 -> V_122 &= ~ ( V_130 | V_123 ) ;
F_26 ( V_14 , V_125 ,
L_11 ) ;
} else if ( ( V_2 -> V_122 & V_136 ) &&
! F_74 ( V_133 -> V_135 ) &&
! F_76 ( V_133 -> V_134 ) ) {
V_2 -> V_122 &= ~ V_136 ;
F_26 ( V_14 , V_125 ,
L_12 ,
V_2 -> V_122 & ( V_123 |
V_130 |
V_136 |
V_137 ) ) ;
}
}
static bool F_77 ( struct V_1 * V_2 ,
enum V_36 V_37 ,
struct V_138 * V_139 ,
struct V_8 * * V_140 )
{
struct V_38 * V_39 = & V_2 -> V_27 . V_39 [ V_37 ] ;
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_17 * V_18 ;
struct V_8 * V_9 ;
int V_141 ;
V_18 = F_78 ( & V_39 -> V_40 ) ;
if ( ! V_18 )
return false ;
V_9 = F_21 ( V_18 ) ;
F_4 ( ! V_9 ) ;
F_79 ( V_2 -> V_45 , V_9 -> V_22 ,
V_14 -> V_26 , V_71 ) ;
V_141 = F_80 ( V_12 , V_139 , V_18 -> V_25 ) ;
if ( V_141 == - V_142 ) {
F_20 ( V_2 -> V_45 , V_9 -> V_22 ,
V_14 -> V_26 , V_71 ) ;
return false ;
}
F_81 ( V_18 , & V_39 -> V_40 ) ;
if ( V_141 == - V_143 ) {
F_30 ( & V_9 -> V_43 , & V_2 -> V_27 . V_42 ) ;
F_16 ( V_2 , V_37 ) ;
V_18 = F_78 ( & V_39 -> V_40 ) ;
if ( V_18 ) {
V_9 = F_21 ( V_18 ) ;
F_4 ( ! V_9 ) ;
F_81 ( V_18 , & V_39 -> V_40 ) ;
F_30 ( & V_9 -> V_43 , & V_2 -> V_27 . V_42 ) ;
F_16 ( V_2 , V_37 ) ;
}
V_9 = NULL ;
}
* V_140 = V_9 ;
return true ;
}
static struct V_8 * F_82 ( struct V_1 * V_2 ,
struct V_138 * V_139 ,
enum V_36 V_37 )
{
struct V_8 * V_9 = NULL ;
while ( F_77 ( V_2 , V_37 , V_139 , & V_9 ) ) {
if ( ! V_9 )
continue;
return V_9 ;
}
return NULL ;
}
static struct V_8 * F_83 ( struct V_1 * V_2 ,
struct V_138 * V_139 )
{
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_15 * V_16 ;
struct V_8 * V_9 ;
int V_141 ;
if ( F_25 ( & V_2 -> V_27 . V_42 ) ) {
V_2 -> V_27 . V_28 = NULL ;
return NULL ;
}
V_9 = F_18 ( & V_2 -> V_27 . V_42 , struct V_8 , V_43 ) ;
if ( V_9 == V_2 -> V_27 . V_30 )
return NULL ;
V_16 = V_9 -> V_19 ;
V_141 = F_84 ( V_12 , V_16 , V_139 ) ;
if ( V_141 == - V_142 ) {
struct V_138 V_144 ;
struct V_8 * V_47 ;
struct V_15 * V_145 ;
memset ( & V_144 , 0 , sizeof( V_144 ) ) ;
if ( F_85 ( & V_9 -> V_43 , & V_2 -> V_27 . V_42 ) ) {
V_2 -> V_27 . V_28 = NULL ;
return NULL ;
}
V_47 = F_86 ( V_9 -> V_43 . V_146 , struct V_8 , V_43 ) ;
V_145 = V_47 -> V_19 ;
V_141 = F_84 ( V_12 , V_145 , & V_144 ) ;
if ( V_141 == - V_142 )
return NULL ;
V_141 = F_84 ( V_12 , V_16 , V_139 ) ;
if ( V_141 == - V_142 ) {
V_139 -> V_147 = 0 ;
V_139 -> V_148 = true ;
}
}
F_87 ( & V_9 -> V_43 ) ;
if ( ! V_9 -> V_23 )
return V_9 ;
F_79 ( V_2 -> V_45 , V_9 -> V_22 ,
V_14 -> V_26 ,
V_71 ) ;
return V_9 ;
}
static void F_88 ( struct V_138 * V_139 ,
struct V_149 * V_150 ,
T_3 V_151 )
{
T_1 V_152 = V_151 & 0xffffffff ;
V_150 -> V_153 = ( V_151 & ~ 0xffffffffULL ) | V_139 -> V_154 ;
if ( V_139 -> V_154 > V_152 &&
F_43 ( V_139 -> V_154 - V_152 > 0x10000000 ) )
V_150 -> V_153 -= 0x100000000ULL ;
if ( V_139 -> V_154 < V_152 &&
F_43 ( V_152 - V_139 -> V_154 > 0x10000000 ) )
V_150 -> V_153 += 0x100000000ULL ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_138 * V_155 ,
struct V_149 * V_156 ,
bool * V_157 , T_3 V_151 )
{
struct V_158 * V_60 = V_2 -> V_60 ;
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_132 * V_133 ;
bool V_159 = V_2 -> V_27 . V_160 ;
if ( V_159 )
goto V_161;
V_2 -> V_27 . V_160 = false ;
if ( ! V_155 -> V_147 ) {
F_90 ( V_162 ) ;
goto V_161;
}
if ( V_155 -> V_147 > ( V_14 -> V_26 - V_12 -> V_5 . V_44 ) ) {
F_90 ( V_162 ) ;
goto V_161;
}
if ( V_155 -> V_148 )
return 0 ;
if ( V_155 -> V_163 & V_164 )
goto V_161;
V_133 = (struct V_132 * ) ( V_18 -> V_25 + V_12 -> V_5 . V_44 ) ;
F_88 ( V_155 , V_156 , V_151 ) ;
F_91 ( V_2 , V_155 ) ;
if ( V_155 -> V_163 & V_165 ) {
F_92 ( V_2 , V_133 , V_155 , V_156 -> V_153 ) ;
if ( F_93 ( V_2 , V_133 , V_155 , V_156 -> V_153 ) )
F_90 ( V_166 ) ;
return - V_143 ;
}
if ( ! F_94 ( V_14 , V_133 , V_156 , V_155 , V_157 , V_2 -> V_27 . V_79 ) )
return - V_143 ;
if ( F_95 ( V_14 , V_133 ) ) {
F_90 ( V_167 ) ;
V_155 -> V_168 = true ;
}
if ( F_96 ( ! V_12 -> V_169 ) )
return - V_143 ;
if ( F_97 ( V_14 , V_60 , V_155 , V_156 ) ) {
F_26 ( V_14 , V_170 , L_13 ,
V_155 -> V_171 ) ;
F_90 ( V_172 ) ;
return - V_143 ;
}
F_98 ( V_14 , V_60 , V_155 , V_156 ) ;
V_156 -> V_173 = V_12 -> V_169 -> V_174 -> V_173 ;
V_156 -> V_175 = V_12 -> V_169 -> V_174 -> V_176 ;
V_156 -> V_31 = V_155 -> V_177 ;
V_156 -> V_178 |= V_179 ;
#ifdef F_99
if ( F_100 ( V_133 -> V_134 ) &&
! F_101 ( V_133 -> V_134 ) )
V_2 -> V_27 . V_180 ++ ;
#endif
return 0 ;
V_161:
V_2 -> V_27 . V_160 = V_155 -> V_148 ;
return - V_143 ;
}
static void F_102 ( struct V_1 * V_2 ,
struct V_138 * V_139 )
{
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_181 * V_182 = & V_12 -> V_5 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
if ( ! ( V_12 -> V_5 . V_6 & V_183 ) )
return;
if ( V_2 -> V_27 . V_32 != V_139 -> V_177 ) {
if ( ++ V_2 -> V_27 . V_33 >= 3 )
F_8 ( V_2 , V_139 -> V_177 ) ;
} else {
V_2 -> V_27 . V_33 = 0 ;
}
if ( V_182 -> V_6 & V_184 ) {
if ( V_14 -> V_185 )
F_103 ( V_2 , V_139 ) ;
} else {
F_103 ( V_2 , V_139 ) ;
}
}
static void F_104 ( struct V_1 * V_2 ,
struct V_138 * V_139 , struct V_149 * V_150 )
{
if ( V_139 -> V_186 ) {
V_150 -> V_178 |= V_187 | V_188 ;
V_150 -> V_189 = V_2 -> V_27 . V_190 ;
if ( ! V_139 -> V_191 ) {
V_150 -> V_178 |= V_192 ;
V_2 -> V_27 . V_190 ++ ;
}
if ( V_139 -> V_193 & V_194 )
V_150 -> V_178 |= V_195 ;
}
}
int F_61 ( struct V_1 * V_2 , int V_10 , bool V_196 )
{
struct V_8 * V_9 ;
struct V_17 * V_18 = NULL , * V_197 , * V_198 ;
struct V_149 * V_150 ;
struct V_11 * V_12 = V_2 -> V_4 ;
struct V_13 * V_14 = F_3 ( V_12 ) ;
struct V_158 * V_60 = V_2 -> V_60 ;
int V_199 ;
struct V_138 V_139 ;
enum V_36 V_37 ;
bool V_200 = ! ! ( V_12 -> V_5 . V_6 & V_66 ) ;
int V_201 ;
T_3 V_151 = 0 ;
unsigned long V_62 ;
T_4 V_202 ;
unsigned int V_203 = 512 ;
if ( V_200 )
V_201 = V_51 ;
else
V_201 = V_71 ;
V_37 = V_196 ? V_50 : V_49 ;
V_151 = F_105 ( V_12 ) ;
do {
bool V_157 = false ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
if ( V_200 )
V_9 = F_82 ( V_2 , & V_139 , V_37 ) ;
else
V_9 = F_83 ( V_2 , & V_139 ) ;
if ( ! V_9 )
break;
V_18 = V_9 -> V_23 ;
if ( ! V_18 )
continue;
if ( V_2 -> V_27 . V_204 )
V_198 = V_2 -> V_27 . V_204 ;
else
V_198 = V_18 ;
V_150 = F_106 ( V_198 ) ;
memset ( V_150 , 0 , sizeof( struct V_149 ) ) ;
V_199 = F_89 ( V_2 , V_198 , & V_139 , V_150 ,
& V_157 , V_151 ) ;
if ( V_199 )
goto V_205;
V_197 = F_41 ( V_14 , V_14 -> V_26 , V_206 ) ;
if ( ! V_197 ) {
F_90 ( V_207 ) ;
goto V_205;
}
V_202 = F_42 ( V_2 -> V_45 , V_197 -> V_25 ,
V_14 -> V_26 , V_201 ) ;
if ( F_43 ( F_44 ( V_2 -> V_45 , V_202 ) ) ) {
F_34 ( V_197 ) ;
goto V_205;
}
F_33 ( V_2 -> V_45 , V_9 -> V_22 ,
V_14 -> V_26 , V_201 ) ;
V_9 -> V_23 = V_197 ;
V_9 -> V_22 = V_202 ;
F_107 ( V_18 , V_139 . V_147 + V_12 -> V_5 . V_44 ) ;
if ( V_12 -> V_5 . V_44 )
F_108 ( V_18 , V_12 -> V_5 . V_44 ) ;
if ( ! V_139 . V_148 )
F_109 ( V_14 , V_198 , & V_139 ,
V_150 , V_157 ) ;
if ( V_139 . V_148 ) {
F_90 ( V_208 ) ;
if ( V_2 -> V_27 . V_204 ) {
F_34 ( V_2 -> V_27 . V_204 ) ;
F_34 ( V_18 ) ;
F_90 ( V_209 ) ;
V_18 = NULL ;
}
V_2 -> V_27 . V_204 = V_18 ;
goto V_210;
}
if ( V_2 -> V_27 . V_204 ) {
int V_211 = V_18 -> V_118 - F_110 ( V_198 ) ;
if ( F_111 ( V_198 , 0 , V_211 , V_206 ) < 0 ) {
F_54 ( V_18 ) ;
F_90 ( V_207 ) ;
goto V_205;
}
V_2 -> V_27 . V_204 = NULL ;
F_112 ( V_18 , F_107 ( V_198 , V_18 -> V_118 ) ,
V_18 -> V_118 ) ;
F_34 ( V_18 ) ;
V_18 = V_198 ;
}
if ( V_150 -> V_178 & V_212 )
F_113 ( V_18 , V_18 -> V_118 - 8 ) ;
F_114 ( & V_2 -> V_213 , V_62 ) ;
if ( ( V_2 -> V_122 & ( V_123 |
V_130 |
V_136 ) ) ||
F_1 ( V_2 ) )
F_71 ( V_2 , V_18 , V_139 . V_168 ) ;
F_115 ( & V_2 -> V_213 , V_62 ) ;
F_102 ( V_2 , & V_139 ) ;
F_104 ( V_2 , & V_139 , V_150 ) ;
F_116 ( V_2 , & V_139 , V_18 ) ;
F_117 ( V_60 , V_18 ) ;
V_205:
if ( V_2 -> V_27 . V_204 ) {
F_34 ( V_2 -> V_27 . V_204 ) ;
V_2 -> V_27 . V_204 = NULL ;
}
V_210:
F_30 ( & V_9 -> V_43 , & V_2 -> V_27 . V_42 ) ;
if ( ! V_200 ) {
F_7 ( V_2 , V_9 , V_10 ) ;
if ( ! V_10 )
F_47 ( V_12 ) ;
} else if ( ! V_10 ) {
F_16 ( V_2 , V_37 ) ;
}
if ( ! V_203 -- )
break;
} while ( 1 );
if ( ! ( V_12 -> V_214 & V_215 ) ) {
V_12 -> V_214 |= ( V_215 | V_216 ) ;
F_118 ( V_12 ) ;
}
return 0 ;
}
