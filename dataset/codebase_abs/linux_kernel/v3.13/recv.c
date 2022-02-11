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
V_15 = V_9 -> V_18 ;
V_15 -> V_19 = 0 ;
V_15 -> V_20 = V_9 -> V_21 ;
V_17 = V_9 -> V_22 ;
F_4 ( V_17 == NULL ) ;
V_15 -> V_23 = V_17 -> V_24 ;
F_5 ( V_11 , V_15 ,
V_13 -> V_25 ,
0 ) ;
if ( V_2 -> V_26 . V_27 == NULL )
F_6 ( V_11 , V_9 -> V_28 ) ;
else
* V_2 -> V_26 . V_27 = V_9 -> V_28 ;
V_2 -> V_26 . V_27 = & V_15 -> V_19 ;
}
static void F_7 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
if ( V_2 -> V_26 . V_29 )
F_2 ( V_2 , V_2 -> V_26 . V_29 ) ;
V_2 -> V_26 . V_29 = V_9 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_30 )
{
F_9 ( V_2 -> V_4 , V_30 ) ;
V_2 -> V_26 . V_31 = V_30 ;
V_2 -> V_26 . V_32 = 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
T_1 V_33 , V_34 [ 2 ] ;
V_33 = F_11 ( V_2 ) ;
F_12 ( V_11 , V_33 ) ;
F_13 ( V_13 ) ;
F_14 ( V_11 ) ;
V_34 [ 0 ] = V_34 [ 1 ] = ~ 0 ;
F_15 ( V_11 , V_34 [ 0 ] , V_34 [ 1 ] ) ;
}
static bool F_16 ( struct V_1 * V_2 ,
enum V_35 V_36 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_37 * V_38 ;
struct V_16 * V_17 ;
struct V_8 * V_9 ;
V_38 = & V_2 -> V_26 . V_38 [ V_36 ] ;
if ( F_17 ( & V_38 -> V_39 ) >= V_38 -> V_40 )
return false ;
V_9 = F_18 ( & V_2 -> V_26 . V_41 , struct V_8 , V_42 ) ;
F_19 ( & V_9 -> V_42 ) ;
V_17 = V_9 -> V_22 ;
memset ( V_17 -> V_24 , 0 , V_11 -> V_5 . V_43 ) ;
F_20 ( V_2 -> V_44 , V_9 -> V_21 ,
V_11 -> V_5 . V_43 , V_45 ) ;
F_21 ( V_17 ) = V_9 ;
F_22 ( V_11 , V_9 -> V_21 , V_36 ) ;
F_23 ( & V_38 -> V_39 , V_17 ) ;
return true ;
}
static void F_24 ( struct V_1 * V_2 ,
enum V_35 V_36 )
{
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
struct V_8 * V_9 , * V_46 ;
if ( F_25 ( & V_2 -> V_26 . V_41 ) ) {
F_26 ( V_13 , V_47 , L_1 ) ;
return;
}
F_27 (bf, tbf, &sc->rx.rxbuf, list)
if ( ! F_16 ( V_2 , V_36 ) )
break;
}
static void F_28 ( struct V_1 * V_2 ,
enum V_35 V_36 )
{
struct V_8 * V_9 ;
struct V_37 * V_38 ;
struct V_16 * V_17 ;
V_38 = & V_2 -> V_26 . V_38 [ V_36 ] ;
while ( ( V_17 = F_29 ( & V_38 -> V_39 ) ) != NULL ) {
V_9 = F_21 ( V_17 ) ;
F_4 ( ! V_9 ) ;
F_30 ( & V_9 -> V_42 , & V_2 -> V_26 . V_41 ) ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_8 * V_9 ;
F_28 ( V_2 , V_48 ) ;
F_28 ( V_2 , V_49 ) ;
F_32 (bf, &sc->rx.rxbuf, list) {
if ( V_9 -> V_22 ) {
F_33 ( V_2 -> V_44 , V_9 -> V_21 ,
V_13 -> V_25 ,
V_50 ) ;
F_34 ( V_9 -> V_22 ) ;
V_9 -> V_21 = 0 ;
V_9 -> V_22 = NULL ;
}
}
}
static void F_35 ( struct V_37 * V_38 , int V_51 )
{
F_36 ( & V_38 -> V_39 ) ;
V_38 -> V_40 = V_51 ;
}
static int F_37 ( struct V_1 * V_2 , int V_52 )
{
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_16 * V_17 ;
struct V_8 * V_9 ;
int error = 0 , V_53 ;
T_1 V_51 ;
F_38 ( V_11 , V_13 -> V_25 -
V_11 -> V_5 . V_43 ) ;
F_35 ( & V_2 -> V_26 . V_38 [ V_48 ] ,
V_11 -> V_5 . V_54 ) ;
F_35 ( & V_2 -> V_26 . V_38 [ V_49 ] ,
V_11 -> V_5 . V_55 ) ;
V_51 = sizeof( struct V_8 ) * V_52 ;
V_9 = F_39 ( V_2 -> V_44 , V_51 , V_56 ) ;
if ( ! V_9 )
return - V_57 ;
F_40 ( & V_2 -> V_26 . V_41 ) ;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ , V_9 ++ ) {
V_17 = F_41 ( V_13 , V_13 -> V_25 , V_56 ) ;
if ( ! V_17 ) {
error = - V_57 ;
goto V_58;
}
memset ( V_17 -> V_24 , 0 , V_13 -> V_25 ) ;
V_9 -> V_22 = V_17 ;
V_9 -> V_21 = F_42 ( V_2 -> V_44 , V_17 -> V_24 ,
V_13 -> V_25 ,
V_50 ) ;
if ( F_43 ( F_44 ( V_2 -> V_44 ,
V_9 -> V_21 ) ) ) {
F_34 ( V_17 ) ;
V_9 -> V_22 = NULL ;
V_9 -> V_21 = 0 ;
F_45 ( V_13 ,
L_2 ) ;
error = - V_57 ;
goto V_58;
}
F_30 ( & V_9 -> V_42 , & V_2 -> V_26 . V_41 ) ;
}
return 0 ;
V_58:
F_31 ( V_2 ) ;
return error ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_47 ( V_2 -> V_4 ) ;
F_24 ( V_2 , V_49 ) ;
F_24 ( V_2 , V_48 ) ;
F_10 ( V_2 ) ;
F_48 ( V_2 -> V_4 , ! ! ( V_2 -> V_59 -> V_60 . V_61 & V_62 ) ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_28 ( V_2 , V_49 ) ;
F_28 ( V_2 , V_48 ) ;
}
int F_50 ( struct V_1 * V_2 , int V_52 )
{
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
struct V_16 * V_17 ;
struct V_8 * V_9 ;
int error = 0 ;
F_51 ( & V_2 -> V_63 ) ;
V_13 -> V_25 = V_64 / 2 +
V_2 -> V_4 -> V_5 . V_43 ;
if ( V_2 -> V_4 -> V_5 . V_6 & V_65 )
return F_37 ( V_2 , V_52 ) ;
F_26 ( V_13 , V_66 , L_3 ,
V_13 -> V_67 , V_13 -> V_25 ) ;
error = F_52 ( V_2 , & V_2 -> V_26 . V_68 , & V_2 -> V_26 . V_41 ,
L_4 , V_52 , 1 , 0 ) ;
if ( error != 0 ) {
F_45 ( V_13 ,
L_5 ,
error ) ;
goto V_69;
}
F_32 (bf, &sc->rx.rxbuf, list) {
V_17 = F_41 ( V_13 , V_13 -> V_25 ,
V_56 ) ;
if ( V_17 == NULL ) {
error = - V_57 ;
goto V_69;
}
V_9 -> V_22 = V_17 ;
V_9 -> V_21 = F_42 ( V_2 -> V_44 , V_17 -> V_24 ,
V_13 -> V_25 ,
V_70 ) ;
if ( F_43 ( F_44 ( V_2 -> V_44 ,
V_9 -> V_21 ) ) ) {
F_34 ( V_17 ) ;
V_9 -> V_22 = NULL ;
V_9 -> V_21 = 0 ;
F_45 ( V_13 ,
L_2 ) ;
error = - V_57 ;
goto V_69;
}
}
V_2 -> V_26 . V_27 = NULL ;
V_69:
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
if ( V_2 -> V_4 -> V_5 . V_6 & V_65 ) {
F_31 ( V_2 ) ;
return;
}
F_32 (bf, &sc->rx.rxbuf, list) {
V_17 = V_9 -> V_22 ;
if ( V_17 ) {
F_33 ( V_2 -> V_44 , V_9 -> V_21 ,
V_13 -> V_25 ,
V_70 ) ;
F_54 ( V_17 ) ;
V_9 -> V_21 = 0 ;
V_9 -> V_22 = NULL ;
}
}
}
T_1 F_11 ( struct V_1 * V_2 )
{
T_1 V_33 ;
if ( F_55 ( V_71 ) )
return 0 ;
V_33 = V_72 | V_73
| V_74 ;
if ( V_2 -> V_59 -> V_60 . V_75 )
V_33 |= V_76 | V_77 ;
if ( V_2 -> V_26 . V_78 & V_79 )
V_33 |= V_80 ;
if ( V_2 -> V_4 -> V_81 )
V_33 |= V_82 ;
if ( V_2 -> V_26 . V_78 & V_83 )
V_33 |= V_84 ;
if ( ( V_2 -> V_4 -> V_85 == V_86 ) &&
( V_2 -> V_87 <= 1 ) &&
! ( V_2 -> V_26 . V_78 & V_88 ) )
V_33 |= V_89 ;
else
V_33 |= V_90 ;
if ( ( V_2 -> V_4 -> V_85 == V_91 ) ||
( V_2 -> V_26 . V_78 & V_92 ) )
V_33 |= V_93 ;
if ( F_56 ( & V_2 -> V_59 -> V_60 ) )
V_33 |= V_94 ;
if ( V_2 -> V_87 > 1 || ( V_2 -> V_26 . V_78 & V_95 ) ) {
if ( V_2 -> V_4 -> V_96 . V_97 <= V_98 )
V_33 |= V_82 ;
V_33 |= V_99 ;
}
if ( F_57 ( V_2 -> V_4 ) )
V_33 |= V_100 ;
return V_33 ;
}
int F_58 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_8 * V_9 , * V_46 ;
if ( V_11 -> V_5 . V_6 & V_65 ) {
F_46 ( V_2 ) ;
return 0 ;
}
if ( F_25 ( & V_2 -> V_26 . V_41 ) )
goto V_101;
V_2 -> V_26 . V_29 = NULL ;
V_2 -> V_26 . V_27 = NULL ;
F_27 (bf, tbf, &sc->rx.rxbuf, list) {
F_2 ( V_2 , V_9 ) ;
}
if ( F_25 ( & V_2 -> V_26 . V_41 ) )
goto V_101;
V_9 = F_18 ( & V_2 -> V_26 . V_41 , struct V_8 , V_42 ) ;
F_6 ( V_11 , V_9 -> V_28 ) ;
F_47 ( V_11 ) ;
V_101:
F_10 ( V_2 ) ;
F_48 ( V_11 , ! ! ( V_2 -> V_59 -> V_60 . V_61 & V_62 ) ) ;
return 0 ;
}
static void F_59 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 -> V_5 . V_6 & V_65 )
F_60 ( V_2 , 1 , true ) ;
F_60 ( V_2 , 1 , false ) ;
}
bool F_61 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
bool V_102 , V_103 = false ;
F_62 ( V_11 ) ;
F_12 ( V_11 , 0 ) ;
V_102 = F_63 ( V_11 , & V_103 ) ;
F_59 ( V_2 ) ;
if ( V_2 -> V_4 -> V_5 . V_6 & V_65 )
F_49 ( V_2 ) ;
else
V_2 -> V_26 . V_27 = NULL ;
if ( ! ( V_11 -> V_104 & V_105 ) &&
F_43 ( ! V_102 ) ) {
F_45 ( F_3 ( V_2 -> V_4 ) ,
L_6
L_7 ) ;
F_64 ( ! V_102 ) ;
}
return V_102 && ! V_103 ;
}
static bool F_65 ( struct V_16 * V_17 )
{
struct V_106 * V_107 ;
T_2 * V_108 , * V_109 , V_110 , V_111 ;
struct V_112 * V_113 ;
V_107 = (struct V_106 * ) V_17 -> V_24 ;
V_108 = V_107 -> V_114 . V_115 . V_116 ;
V_109 = V_17 -> V_24 + V_17 -> V_117 ;
while ( V_108 + 2 < V_109 ) {
V_110 = * V_108 ++ ;
V_111 = * V_108 ++ ;
if ( V_108 + V_111 > V_109 )
break;
if ( V_110 == V_118 ) {
if ( V_111 < sizeof( * V_113 ) )
break;
V_113 = (struct V_112 * ) V_108 ;
if ( V_113 -> V_119 != 0 )
break;
return V_113 -> V_120 & 0x01 ;
}
V_108 += V_111 ;
}
return false ;
}
static void F_66 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
if ( V_17 -> V_117 < 24 + 8 + 2 + 2 )
return;
V_2 -> V_121 &= ~ V_122 ;
if ( V_2 -> V_121 & V_123 ) {
V_2 -> V_121 &= ~ V_123 ;
F_26 ( V_13 , V_124 ,
L_8 ) ;
F_67 ( V_2 ) ;
}
if ( F_65 ( V_17 ) ) {
F_26 ( V_13 , V_124 ,
L_9 ) ;
V_2 -> V_121 |= V_125 | V_122 ;
return;
}
if ( V_2 -> V_121 & V_125 ) {
V_2 -> V_121 &= ~ V_125 ;
F_26 ( V_13 , V_124 , L_10 ) ;
}
}
static void F_68 ( struct V_1 * V_2 , struct V_16 * V_17 , bool V_126 )
{
struct V_127 * V_128 ;
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
V_128 = (struct V_127 * ) V_17 -> V_24 ;
if ( ( ( V_2 -> V_121 & V_122 ) || F_1 ( V_2 ) )
&& V_126 ) {
F_66 ( V_2 , V_17 ) ;
} else if ( ( V_2 -> V_121 & V_125 ) &&
( F_69 ( V_128 -> V_129 ) ||
F_70 ( V_128 -> V_129 ) ) &&
F_71 ( V_128 -> V_130 ) &&
! F_72 ( V_128 -> V_129 ) ) {
V_2 -> V_121 &= ~ ( V_125 | V_122 ) ;
F_26 ( V_13 , V_124 ,
L_11 ) ;
} else if ( ( V_2 -> V_121 & V_131 ) &&
! F_71 ( V_128 -> V_130 ) &&
! F_73 ( V_128 -> V_129 ) ) {
V_2 -> V_121 &= ~ V_131 ;
F_26 ( V_13 , V_124 ,
L_12 ,
V_2 -> V_121 & ( V_122 |
V_125 |
V_131 |
V_132 ) ) ;
}
}
static bool F_74 ( struct V_1 * V_2 ,
enum V_35 V_36 ,
struct V_133 * V_134 ,
struct V_8 * * V_135 )
{
struct V_37 * V_38 = & V_2 -> V_26 . V_38 [ V_36 ] ;
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_16 * V_17 ;
struct V_8 * V_9 ;
int V_136 ;
V_17 = F_75 ( & V_38 -> V_39 ) ;
if ( ! V_17 )
return false ;
V_9 = F_21 ( V_17 ) ;
F_4 ( ! V_9 ) ;
F_76 ( V_2 -> V_44 , V_9 -> V_21 ,
V_13 -> V_25 , V_70 ) ;
V_136 = F_77 ( V_11 , V_134 , V_17 -> V_24 ) ;
if ( V_136 == - V_137 ) {
F_20 ( V_2 -> V_44 , V_9 -> V_21 ,
V_13 -> V_25 , V_70 ) ;
return false ;
}
F_78 ( V_17 , & V_38 -> V_39 ) ;
if ( V_136 == - V_138 ) {
F_30 ( & V_9 -> V_42 , & V_2 -> V_26 . V_41 ) ;
F_16 ( V_2 , V_36 ) ;
V_17 = F_75 ( & V_38 -> V_39 ) ;
if ( V_17 ) {
V_9 = F_21 ( V_17 ) ;
F_4 ( ! V_9 ) ;
F_78 ( V_17 , & V_38 -> V_39 ) ;
F_30 ( & V_9 -> V_42 , & V_2 -> V_26 . V_41 ) ;
F_16 ( V_2 , V_36 ) ;
}
V_9 = NULL ;
}
* V_135 = V_9 ;
return true ;
}
static struct V_8 * F_79 ( struct V_1 * V_2 ,
struct V_133 * V_134 ,
enum V_35 V_36 )
{
struct V_8 * V_9 = NULL ;
while ( F_74 ( V_2 , V_36 , V_134 , & V_9 ) ) {
if ( ! V_9 )
continue;
return V_9 ;
}
return NULL ;
}
static struct V_8 * F_80 ( struct V_1 * V_2 ,
struct V_133 * V_134 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_14 * V_15 ;
struct V_8 * V_9 ;
int V_136 ;
if ( F_25 ( & V_2 -> V_26 . V_41 ) ) {
V_2 -> V_26 . V_27 = NULL ;
return NULL ;
}
V_9 = F_18 ( & V_2 -> V_26 . V_41 , struct V_8 , V_42 ) ;
if ( V_9 == V_2 -> V_26 . V_29 )
return NULL ;
V_15 = V_9 -> V_18 ;
V_136 = F_81 ( V_11 , V_15 , V_134 ) ;
if ( V_136 == - V_137 ) {
struct V_133 V_139 ;
struct V_8 * V_46 ;
struct V_14 * V_140 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
if ( F_82 ( & V_9 -> V_42 , & V_2 -> V_26 . V_41 ) ) {
V_2 -> V_26 . V_27 = NULL ;
return NULL ;
}
V_46 = F_83 ( V_9 -> V_42 . V_141 , struct V_8 , V_42 ) ;
V_140 = V_46 -> V_18 ;
V_136 = F_81 ( V_11 , V_140 , & V_139 ) ;
if ( V_136 == - V_137 )
return NULL ;
V_134 -> V_142 = 0 ;
V_134 -> V_143 = true ;
}
F_84 ( & V_9 -> V_42 ) ;
if ( ! V_9 -> V_22 )
return V_9 ;
F_76 ( V_2 -> V_44 , V_9 -> V_21 ,
V_13 -> V_25 ,
V_70 ) ;
return V_9 ;
}
static bool F_85 ( struct V_12 * V_13 ,
struct V_127 * V_128 ,
struct V_144 * V_145 ,
struct V_133 * V_146 ,
bool * V_147 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 -> V_148 ;
bool V_149 , V_150 , V_151 , V_152 ;
struct V_10 * V_11 = V_13 -> V_11 ;
T_3 V_153 ;
V_153 = V_128 -> V_129 ;
V_149 = ! ! F_71 ( V_128 -> V_130 ) ;
V_150 = V_146 -> V_154 != V_155 &&
F_86 ( V_146 -> V_154 , V_13 -> V_156 ) ;
V_151 = V_150 && F_69 ( V_153 ) &&
F_87 ( V_153 ) &&
! ( V_146 -> V_157 &
( V_158 | V_159 | V_160 |
V_161 ) ) ;
if ( V_146 -> V_154 == V_155 ||
! F_86 ( V_146 -> V_154 , V_13 -> V_162 ) )
V_146 -> V_157 &= ~ V_161 ;
V_152 = V_150 && ! F_88 ( V_153 ) &&
! F_73 ( V_153 ) &&
! ( F_89 ( V_128 -> V_163 ) & V_164 ) &&
( V_146 -> V_157 & V_160 ) ;
if ( V_146 -> V_157 != 0 ) {
T_2 V_165 ;
if ( V_146 -> V_157 & V_159 ) {
V_145 -> V_166 |= V_167 ;
V_152 = false ;
}
if ( ( V_146 -> V_157 & V_158 ) ||
( ! V_149 && ( V_146 -> V_157 & V_161 ) ) ) {
* V_147 = true ;
V_152 = false ;
}
V_165 = V_158 | V_160 |
V_161 ;
if ( V_11 -> V_81 && ( V_2 -> V_26 . V_78 & V_168 ) )
V_165 |= V_159 ;
if ( V_146 -> V_157 & ~ V_165 )
return false ;
}
if ( V_151 )
V_145 -> V_166 |= V_169 ;
else if ( V_149 && V_152 )
V_145 -> V_166 |= V_170 ;
return true ;
}
static int F_90 ( struct V_12 * V_13 ,
struct V_171 * V_59 ,
struct V_133 * V_146 ,
struct V_144 * V_145 )
{
struct V_172 * V_173 ;
enum V_174 V_175 ;
unsigned int V_53 = 0 ;
struct V_1 T_4 * V_2 = V_13 -> V_148 ;
V_175 = V_59 -> V_60 . V_176 . V_177 -> V_175 ;
V_173 = V_59 -> V_178 -> V_179 [ V_175 ] ;
switch ( V_59 -> V_60 . V_176 . V_180 ) {
case V_181 :
V_145 -> V_166 |= V_182 ;
break;
case V_183 :
V_145 -> V_166 |= V_184 ;
break;
default:
break;
}
if ( V_146 -> V_185 & 0x80 ) {
V_145 -> V_166 |= V_186 ;
V_145 -> V_166 |= V_146 -> V_166 ;
V_145 -> V_187 = V_146 -> V_185 & 0x7f ;
return 0 ;
}
for ( V_53 = 0 ; V_53 < V_173 -> V_188 ; V_53 ++ ) {
if ( V_173 -> V_189 [ V_53 ] . V_190 == V_146 -> V_185 ) {
V_145 -> V_187 = V_53 ;
return 0 ;
}
if ( V_173 -> V_189 [ V_53 ] . V_191 == V_146 -> V_185 ) {
V_145 -> V_166 |= V_192 ;
V_145 -> V_187 = V_53 ;
return 0 ;
}
}
F_26 ( V_13 , V_193 ,
L_13 ,
V_146 -> V_185 ) ;
F_91 ( V_194 ) ;
return - V_138 ;
}
static void F_92 ( struct V_12 * V_13 ,
struct V_171 * V_59 ,
struct V_133 * V_146 ,
struct V_144 * V_145 )
{
struct V_1 * V_2 = V_59 -> V_148 ;
struct V_10 * V_11 = V_13 -> V_11 ;
int V_195 ;
int V_196 = V_146 -> V_197 ;
if ( V_146 -> V_198 ) {
V_145 -> V_166 |= V_199 ;
return;
}
if ( V_146 -> V_197 == V_200 ) {
V_145 -> V_166 |= V_199 ;
return;
}
if ( V_146 -> V_201 &&
( ( V_11 -> V_85 == V_86 ) ||
( V_11 -> V_85 == V_202 ) ) ) {
F_93 ( V_2 -> V_195 , V_146 -> V_197 ) ;
V_195 = V_2 -> V_195 ;
if ( F_94 ( V_195 != V_203 ) )
V_196 = F_95 ( V_195 , V_204 ) ;
if ( V_196 < 0 )
V_196 = 0 ;
V_11 -> V_205 . V_206 = V_196 ;
}
V_145 -> signal = V_11 -> V_207 + V_146 -> V_197 ;
}
static void F_96 ( struct V_133 * V_134 ,
struct V_144 * V_145 ,
T_5 V_208 )
{
T_1 V_209 = V_208 & 0xffffffff ;
V_145 -> V_210 = ( V_208 & ~ 0xffffffffULL ) | V_134 -> V_211 ;
if ( V_134 -> V_211 > V_209 &&
F_43 ( V_134 -> V_211 - V_209 > 0x10000000 ) )
V_145 -> V_210 -= 0x100000000ULL ;
if ( V_134 -> V_211 < V_209 &&
F_43 ( V_209 - V_134 -> V_211 > 0x10000000 ) )
V_145 -> V_210 += 0x100000000ULL ;
}
static T_6 F_97 ( T_2 V_212 )
{
if ( V_212 == 128 )
V_212 = 0 ;
return ( T_6 ) V_212 ;
}
static int F_98 ( struct V_1 * V_2 , struct V_127 * V_128 ,
struct V_133 * V_134 , T_5 V_208 )
{
#ifdef F_99
struct V_10 * V_11 = V_2 -> V_4 ;
T_2 V_213 , * V_214 , * V_215 = ( T_2 * ) V_128 ;
struct V_216 V_217 ;
struct V_218 V_219 ;
struct V_220 * V_221 ;
struct V_222 * V_223 ;
int V_117 = V_134 -> V_142 ;
int V_224 ;
T_7 V_225 , V_226 , V_227 = V_11 -> V_228 -> V_177 -> V_229 ;
enum V_230 V_231 ;
if ( V_134 -> V_232 != V_233 &&
V_134 -> V_232 != V_234 &&
V_134 -> V_232 != V_235 )
return 0 ;
V_223 = ( (struct V_222 * ) & V_215 [ V_117 ] ) - 1 ;
if ( ! ( V_223 -> V_236 & V_237 ) )
return 0 ;
V_231 = F_100 ( & V_2 -> V_59 -> V_60 . V_176 ) ;
if ( ( V_231 == V_238 ) ||
( V_231 == V_239 ) ) {
V_225 = V_240 ;
V_213 = V_241 ;
V_214 = ( T_2 * ) V_219 . V_24 ;
} else {
V_225 = V_242 ;
V_213 = V_243 ;
V_214 = ( T_2 * ) V_217 . V_24 ;
}
if ( ( V_117 > V_225 + 2 ) || ( V_117 < V_225 - 1 ) )
return 1 ;
switch ( V_117 - V_225 ) {
case 0 :
memcpy ( V_214 , V_215 , V_213 ) ;
break;
case - 1 :
memcpy ( & V_214 [ 1 ] , V_215 , V_213 - 1 ) ;
V_214 [ 0 ] = V_215 [ 0 ] ;
break;
case 2 :
memcpy ( V_214 , V_215 , 30 ) ;
V_214 [ 30 ] = V_215 [ 31 ] ;
memcpy ( & V_214 [ 31 ] , & V_215 [ 33 ] , V_213 - 31 ) ;
break;
case 1 :
V_214 [ 0 ] = V_215 [ 0 ] ;
memcpy ( & V_214 [ 1 ] , V_215 , 30 ) ;
V_214 [ 31 ] = V_215 [ 31 ] ;
memcpy ( & V_214 [ 32 ] , & V_215 [ 33 ] , V_213 - 32 ) ;
break;
default:
return 1 ;
}
V_224 = V_213 / 2 ;
V_214 [ V_224 ] = ( V_214 [ V_224 + 1 ] + V_214 [ V_224 - 1 ] ) / 2 ;
if ( ( V_231 == V_238 ) ||
( V_231 == V_239 ) ) {
T_6 V_244 , V_245 ;
T_8 V_246 ;
T_2 V_247 , V_248 ;
T_2 V_249 , V_250 ;
T_7 V_251 , V_252 ;
struct V_253 * V_254 = V_11 -> V_254 ;
struct V_255 * V_256 ;
if ( V_254 )
V_246 = F_101 ( V_11 , V_11 -> V_228 ,
V_254 -> V_257 [ 3 ] . V_258 ) ;
else
V_246 = V_259 ;
V_226 = sizeof( V_219 ) - sizeof( struct V_220 ) ;
V_219 . V_221 . type = V_260 ;
V_219 . V_221 . V_226 = F_102 ( V_226 ) ;
V_219 . V_227 = F_102 ( V_227 ) ;
V_219 . V_261 = V_231 ;
if ( V_231 == V_239 ) {
V_244 = F_97 ( V_134 -> V_262 ) ;
V_245 = F_97 ( V_134 -> V_263 ) ;
V_219 . V_264 = V_11 -> V_207 ;
V_219 . V_265 = V_246 ;
} else {
V_244 = F_97 ( V_134 -> V_263 ) ;
V_245 = F_97 ( V_134 -> V_262 ) ;
V_219 . V_264 = V_246 ;
V_219 . V_265 = V_11 -> V_207 ;
}
V_219 . V_244 = V_244 ;
V_219 . V_245 = V_245 ;
V_256 = ( (struct V_255 * ) V_223 ) - 1 ;
V_251 = F_103 ( V_256 -> V_266 ) ;
V_252 = F_103 ( V_256 -> V_267 ) ;
V_219 . V_268 = F_102 ( V_251 ) ;
V_219 . V_269 = F_102 ( V_252 ) ;
V_247 = F_104 ( V_256 -> V_266 ) ;
V_248 = F_104 ( V_256 -> V_267 ) ;
V_219 . V_247 = V_247 ;
V_219 . V_248 = V_248 ;
V_249 = F_105 ( V_256 -> V_266 ) ;
V_250 = F_105 ( V_256 -> V_267 ) ;
V_219 . V_270 = V_249 ;
V_219 . V_271 = V_250 ;
V_219 . V_272 = V_256 -> V_272 & 0xf ;
V_219 . V_208 = F_106 ( V_208 ) ;
V_221 = (struct V_220 * ) & V_219 ;
} else {
T_2 V_273 , V_274 ;
T_7 V_275 ;
struct V_276 * V_256 ;
V_226 = sizeof( V_217 ) - sizeof( struct V_220 ) ;
V_217 . V_221 . type = V_277 ;
V_217 . V_221 . V_226 = F_102 ( V_226 ) ;
V_217 . V_227 = F_102 ( V_227 ) ;
V_217 . V_196 = F_97 ( V_134 -> V_262 ) ;
V_217 . V_207 = V_11 -> V_207 ;
V_256 = ( (struct V_276 * ) V_223 ) - 1 ;
V_275 = F_103 ( V_256 -> V_278 ) ;
V_217 . V_279 = F_102 ( V_275 ) ;
V_273 = F_104 ( V_256 -> V_278 ) ;
V_217 . V_273 = V_273 ;
V_274 = F_105 ( V_256 -> V_278 ) ;
V_217 . V_280 = V_274 ;
V_217 . V_272 = V_256 -> V_272 & 0xf ;
V_217 . V_208 = F_106 ( V_208 ) ;
V_221 = (struct V_220 * ) & V_217 ;
}
F_107 ( V_2 , V_221 ) ;
return 1 ;
#else
return 0 ;
#endif
}
static bool F_108 ( struct V_1 * V_2 , struct V_127 * V_128 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
if ( F_109 ( V_128 -> V_129 ) ) {
F_91 ( V_281 ) ;
if ( ! F_110 ( V_13 -> V_282 ) &&
F_111 ( V_128 -> V_283 , V_13 -> V_282 ) )
return true ;
}
return false ;
}
static int F_112 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_133 * V_146 ,
struct V_144 * V_284 ,
bool * V_147 , T_5 V_208 )
{
struct V_171 * V_59 = V_2 -> V_59 ;
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_127 * V_128 ;
bool V_285 = V_2 -> V_26 . V_286 ;
int V_136 = 0 ;
V_2 -> V_26 . V_286 = V_146 -> V_143 ;
if ( V_285 )
return - V_138 ;
if ( ! V_146 -> V_142 ) {
F_91 ( V_287 ) ;
return - V_138 ;
}
if ( V_146 -> V_142 > ( V_13 -> V_25 - V_11 -> V_5 . V_43 ) ) {
F_91 ( V_287 ) ;
return - V_138 ;
}
if ( V_146 -> V_143 )
return 0 ;
if ( V_146 -> V_157 & V_288 ) {
V_136 = - V_138 ;
goto exit;
}
V_128 = (struct V_127 * ) ( V_17 -> V_24 + V_11 -> V_5 . V_43 ) ;
F_96 ( V_146 , V_284 , V_208 ) ;
F_113 ( V_2 , V_146 ) ;
if ( V_146 -> V_157 & V_289 ) {
F_114 ( V_2 , V_128 , V_146 , V_284 -> V_210 ) ;
if ( F_98 ( V_2 , V_128 , V_146 , V_284 -> V_210 ) )
F_91 ( V_290 ) ;
V_136 = - V_138 ;
goto exit;
}
if ( ! F_85 ( V_13 , V_128 , V_284 , V_146 , V_147 ) ) {
V_136 = - V_138 ;
goto exit;
}
V_146 -> V_201 = F_108 ( V_2 , V_128 ) ;
if ( V_146 -> V_201 ) {
V_2 -> V_291 = 0 ;
F_115 ( V_2 , 3 ) ;
}
if ( F_90 ( V_13 , V_59 , V_146 , V_284 ) ) {
V_136 = - V_138 ;
goto exit;
}
F_92 ( V_13 , V_59 , V_146 , V_284 ) ;
V_284 -> V_175 = V_59 -> V_60 . V_176 . V_177 -> V_175 ;
V_284 -> V_227 = V_59 -> V_60 . V_176 . V_177 -> V_229 ;
V_284 -> V_30 = V_146 -> V_292 ;
V_284 -> V_166 |= V_293 ;
#ifdef F_116
if ( F_117 ( V_128 -> V_129 ) &&
! F_118 ( V_128 -> V_129 ) )
V_2 -> V_26 . V_294 ++ ;
#endif
exit:
V_2 -> V_26 . V_286 = false ;
return V_136 ;
}
static void F_119 ( struct V_12 * V_13 ,
struct V_16 * V_17 ,
struct V_133 * V_146 ,
struct V_144 * V_145 ,
bool V_147 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
struct V_127 * V_128 ;
int V_295 , V_296 , V_297 ;
T_2 V_298 ;
T_3 V_153 ;
V_128 = (struct V_127 * ) V_17 -> V_24 ;
V_295 = F_120 ( V_17 ) ;
V_153 = V_128 -> V_129 ;
V_296 = F_121 ( V_153 ) ;
V_297 = V_296 & 3 ;
if ( V_297 && V_17 -> V_117 >= V_296 + V_297 + V_299 ) {
memmove ( V_17 -> V_24 + V_297 , V_17 -> V_24 , V_296 ) ;
F_122 ( V_17 , V_297 ) ;
}
V_298 = V_146 -> V_154 ;
if ( ! ( V_298 == V_155 ) && ! V_147 &&
F_87 ( V_153 ) ) {
V_145 -> V_166 |= V_300 ;
} else if ( F_87 ( V_153 )
&& ! V_147 && V_17 -> V_117 >= V_295 + 4 ) {
V_298 = V_17 -> V_24 [ V_295 + 3 ] >> 6 ;
if ( F_86 ( V_298 , V_13 -> V_301 ) )
V_145 -> V_166 |= V_300 ;
}
if ( V_11 -> V_302 &&
( V_145 -> V_166 & V_300 ) &&
F_123 ( V_153 ) )
V_145 -> V_166 &= ~ V_300 ;
}
static void F_124 ( struct V_1 * V_2 ,
struct V_133 * V_134 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_303 * V_304 = & V_11 -> V_5 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
if ( ! ( V_11 -> V_5 . V_6 & V_305 ) )
return;
if ( V_2 -> V_26 . V_31 != V_134 -> V_292 ) {
if ( ++ V_2 -> V_26 . V_32 >= 3 )
F_8 ( V_2 , V_134 -> V_292 ) ;
} else {
V_2 -> V_26 . V_32 = 0 ;
}
if ( V_304 -> V_6 & V_306 ) {
if ( V_13 -> V_307 )
F_125 ( V_2 , V_134 ) ;
} else {
F_125 ( V_2 , V_134 ) ;
}
}
static void F_126 ( struct V_1 * V_2 ,
struct V_133 * V_134 , struct V_144 * V_145 )
{
if ( V_134 -> V_308 ) {
V_145 -> V_166 |= V_309 | V_310 ;
V_145 -> V_311 = V_2 -> V_26 . V_312 ;
if ( ! V_134 -> V_198 ) {
V_145 -> V_166 |= V_313 ;
V_2 -> V_26 . V_312 ++ ;
}
if ( V_134 -> V_314 & V_315 )
V_145 -> V_166 |= V_316 ;
}
}
int F_60 ( struct V_1 * V_2 , int V_317 , bool V_318 )
{
struct V_8 * V_9 ;
struct V_16 * V_17 = NULL , * V_319 , * V_320 ;
struct V_144 * V_145 ;
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_171 * V_59 = V_2 -> V_59 ;
int V_321 ;
struct V_133 V_134 ;
enum V_35 V_36 ;
bool V_322 = ! ! ( V_11 -> V_5 . V_6 & V_65 ) ;
int V_323 ;
T_5 V_208 = 0 ;
unsigned long V_61 ;
T_9 V_324 ;
if ( V_322 )
V_323 = V_50 ;
else
V_323 = V_70 ;
V_36 = V_318 ? V_49 : V_48 ;
V_208 = F_127 ( V_11 ) ;
do {
bool V_147 = false ;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
if ( V_322 )
V_9 = F_79 ( V_2 , & V_134 , V_36 ) ;
else
V_9 = F_80 ( V_2 , & V_134 ) ;
if ( ! V_9 )
break;
V_17 = V_9 -> V_22 ;
if ( ! V_17 )
continue;
if ( V_2 -> V_26 . V_325 )
V_320 = V_2 -> V_26 . V_325 ;
else
V_320 = V_17 ;
V_145 = F_128 ( V_320 ) ;
memset ( V_145 , 0 , sizeof( struct V_144 ) ) ;
V_321 = F_112 ( V_2 , V_320 , & V_134 , V_145 ,
& V_147 , V_208 ) ;
if ( V_321 )
goto V_326;
V_319 = F_41 ( V_13 , V_13 -> V_25 , V_327 ) ;
if ( ! V_319 ) {
F_91 ( V_328 ) ;
goto V_326;
}
V_324 = F_42 ( V_2 -> V_44 , V_319 -> V_24 ,
V_13 -> V_25 , V_323 ) ;
if ( F_43 ( F_44 ( V_2 -> V_44 , V_324 ) ) ) {
F_34 ( V_319 ) ;
goto V_326;
}
F_33 ( V_2 -> V_44 , V_9 -> V_21 ,
V_13 -> V_25 , V_323 ) ;
V_9 -> V_22 = V_319 ;
V_9 -> V_21 = V_324 ;
F_129 ( V_17 , V_134 . V_142 + V_11 -> V_5 . V_43 ) ;
if ( V_11 -> V_5 . V_43 )
F_122 ( V_17 , V_11 -> V_5 . V_43 ) ;
if ( ! V_134 . V_143 )
F_119 ( V_13 , V_320 , & V_134 ,
V_145 , V_147 ) ;
if ( V_134 . V_143 ) {
F_91 ( V_329 ) ;
if ( V_2 -> V_26 . V_325 ) {
F_34 ( V_2 -> V_26 . V_325 ) ;
F_34 ( V_17 ) ;
F_91 ( V_330 ) ;
V_17 = NULL ;
}
V_2 -> V_26 . V_325 = V_17 ;
goto V_331;
}
if ( V_2 -> V_26 . V_325 ) {
int V_332 = V_17 -> V_117 - F_130 ( V_320 ) ;
if ( F_131 ( V_320 , 0 , V_332 , V_327 ) < 0 ) {
F_54 ( V_17 ) ;
F_91 ( V_328 ) ;
goto V_326;
}
V_2 -> V_26 . V_325 = NULL ;
F_132 ( V_17 , F_129 ( V_320 , V_17 -> V_117 ) ,
V_17 -> V_117 ) ;
F_34 ( V_17 ) ;
V_17 = V_320 ;
}
if ( V_145 -> V_166 & V_169 )
F_133 ( V_17 , V_17 -> V_117 - 8 ) ;
F_134 ( & V_2 -> V_333 , V_61 ) ;
if ( ( V_2 -> V_121 & ( V_122 |
V_125 |
V_131 ) ) ||
F_1 ( V_2 ) )
F_68 ( V_2 , V_17 , V_134 . V_201 ) ;
F_135 ( & V_2 -> V_333 , V_61 ) ;
F_124 ( V_2 , & V_134 ) ;
F_126 ( V_2 , & V_134 , V_145 ) ;
F_136 ( V_59 , V_17 ) ;
V_326:
if ( V_2 -> V_26 . V_325 ) {
F_34 ( V_2 -> V_26 . V_325 ) ;
V_2 -> V_26 . V_325 = NULL ;
}
V_331:
F_30 ( & V_9 -> V_42 , & V_2 -> V_26 . V_41 ) ;
if ( V_317 )
continue;
if ( V_322 ) {
F_16 ( V_2 , V_36 ) ;
} else {
F_7 ( V_2 , V_9 ) ;
F_47 ( V_11 ) ;
}
} while ( 1 );
if ( ! ( V_11 -> V_334 & V_335 ) ) {
V_11 -> V_334 |= ( V_335 | V_336 ) ;
F_137 ( V_11 ) ;
}
return 0 ;
}
