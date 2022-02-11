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
if ( F_57 ( V_2 -> V_4 ) || F_58 ( V_2 -> V_4 ) )
V_33 |= V_100 ;
return V_33 ;
}
int F_59 ( struct V_1 * V_2 )
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
static void F_60 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 -> V_5 . V_6 & V_65 )
F_61 ( V_2 , 1 , true ) ;
F_61 ( V_2 , 1 , false ) ;
}
bool F_62 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
bool V_102 , V_103 = false ;
F_63 ( V_11 ) ;
F_12 ( V_11 , 0 ) ;
V_102 = F_64 ( V_11 , & V_103 ) ;
F_60 ( V_2 ) ;
if ( V_2 -> V_4 -> V_5 . V_6 & V_65 )
F_49 ( V_2 ) ;
else
V_2 -> V_26 . V_27 = NULL ;
if ( ! ( V_11 -> V_104 & V_105 ) &&
F_43 ( ! V_102 ) ) {
F_45 ( F_3 ( V_2 -> V_4 ) ,
L_6
L_7 ) ;
F_65 ( ! V_102 ) ;
}
return V_102 && ! V_103 ;
}
static bool F_66 ( struct V_16 * V_17 )
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
static void F_67 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
if ( V_17 -> V_117 < 24 + 8 + 2 + 2 )
return;
V_2 -> V_121 &= ~ V_122 ;
if ( V_2 -> V_121 & V_123 ) {
V_2 -> V_121 &= ~ V_123 ;
F_26 ( V_13 , V_124 ,
L_8 ) ;
F_68 ( V_2 ) ;
}
if ( F_66 ( V_17 ) ) {
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
static void F_69 ( struct V_1 * V_2 , struct V_16 * V_17 , bool V_126 )
{
struct V_127 * V_128 ;
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
V_128 = (struct V_127 * ) V_17 -> V_24 ;
if ( ( ( V_2 -> V_121 & V_122 ) || F_1 ( V_2 ) )
&& V_126 ) {
F_67 ( V_2 , V_17 ) ;
} else if ( ( V_2 -> V_121 & V_125 ) &&
( F_70 ( V_128 -> V_129 ) ||
F_71 ( V_128 -> V_129 ) ) &&
F_72 ( V_128 -> V_130 ) &&
! F_73 ( V_128 -> V_129 ) ) {
V_2 -> V_121 &= ~ ( V_125 | V_122 ) ;
F_26 ( V_13 , V_124 ,
L_11 ) ;
} else if ( ( V_2 -> V_121 & V_131 ) &&
! F_72 ( V_128 -> V_130 ) &&
! F_74 ( V_128 -> V_129 ) ) {
V_2 -> V_121 &= ~ V_131 ;
F_26 ( V_13 , V_124 ,
L_12 ,
V_2 -> V_121 & ( V_122 |
V_125 |
V_131 |
V_132 ) ) ;
}
}
static bool F_75 ( struct V_1 * V_2 ,
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
V_17 = F_76 ( & V_38 -> V_39 ) ;
if ( ! V_17 )
return false ;
V_9 = F_21 ( V_17 ) ;
F_4 ( ! V_9 ) ;
F_77 ( V_2 -> V_44 , V_9 -> V_21 ,
V_13 -> V_25 , V_70 ) ;
V_136 = F_78 ( V_11 , V_134 , V_17 -> V_24 ) ;
if ( V_136 == - V_137 ) {
F_20 ( V_2 -> V_44 , V_9 -> V_21 ,
V_13 -> V_25 , V_70 ) ;
return false ;
}
F_79 ( V_17 , & V_38 -> V_39 ) ;
if ( V_136 == - V_138 ) {
F_30 ( & V_9 -> V_42 , & V_2 -> V_26 . V_41 ) ;
F_16 ( V_2 , V_36 ) ;
V_17 = F_76 ( & V_38 -> V_39 ) ;
if ( V_17 ) {
V_9 = F_21 ( V_17 ) ;
F_4 ( ! V_9 ) ;
F_79 ( V_17 , & V_38 -> V_39 ) ;
F_30 ( & V_9 -> V_42 , & V_2 -> V_26 . V_41 ) ;
F_16 ( V_2 , V_36 ) ;
}
V_9 = NULL ;
}
* V_135 = V_9 ;
return true ;
}
static struct V_8 * F_80 ( struct V_1 * V_2 ,
struct V_133 * V_134 ,
enum V_35 V_36 )
{
struct V_8 * V_9 = NULL ;
while ( F_75 ( V_2 , V_36 , V_134 , & V_9 ) ) {
if ( ! V_9 )
continue;
return V_9 ;
}
return NULL ;
}
static struct V_8 * F_81 ( struct V_1 * V_2 ,
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
V_136 = F_82 ( V_11 , V_15 , V_134 ) ;
if ( V_136 == - V_137 ) {
struct V_133 V_139 ;
struct V_8 * V_46 ;
struct V_14 * V_140 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
if ( F_83 ( & V_9 -> V_42 , & V_2 -> V_26 . V_41 ) ) {
V_2 -> V_26 . V_27 = NULL ;
return NULL ;
}
V_46 = F_84 ( V_9 -> V_42 . V_141 , struct V_8 , V_42 ) ;
V_140 = V_46 -> V_18 ;
V_136 = F_82 ( V_11 , V_140 , & V_139 ) ;
if ( V_136 == - V_137 )
return NULL ;
V_136 = F_82 ( V_11 , V_15 , V_134 ) ;
if ( V_136 == - V_137 ) {
V_134 -> V_142 = 0 ;
V_134 -> V_143 = true ;
}
}
F_85 ( & V_9 -> V_42 ) ;
if ( ! V_9 -> V_22 )
return V_9 ;
F_77 ( V_2 -> V_44 , V_9 -> V_21 ,
V_13 -> V_25 ,
V_70 ) ;
return V_9 ;
}
static bool F_86 ( struct V_12 * V_13 ,
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
V_149 = ! ! F_72 ( V_128 -> V_130 ) ;
V_150 = V_146 -> V_154 != V_155 &&
F_87 ( V_146 -> V_154 , V_13 -> V_156 ) ;
V_151 = V_150 && F_70 ( V_153 ) &&
F_88 ( V_153 ) &&
! ( V_146 -> V_157 &
( V_158 | V_159 | V_160 |
V_161 ) ) ;
if ( V_146 -> V_154 == V_155 ||
! F_87 ( V_146 -> V_154 , V_13 -> V_162 ) )
V_146 -> V_157 &= ~ V_161 ;
V_152 = V_150 && ! F_89 ( V_153 ) &&
! F_74 ( V_153 ) &&
! ( F_90 ( V_128 -> V_163 ) & V_164 ) &&
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
static int F_91 ( struct V_12 * V_13 ,
struct V_171 * V_59 ,
struct V_133 * V_146 ,
struct V_144 * V_145 )
{
struct V_172 * V_173 ;
enum V_174 V_175 ;
unsigned int V_53 = 0 ;
struct V_1 T_4 * V_2 = V_13 -> V_148 ;
struct V_10 * V_11 = V_2 -> V_4 ;
V_175 = V_11 -> V_176 -> V_177 -> V_175 ;
V_173 = V_59 -> V_178 -> V_179 [ V_175 ] ;
if ( F_92 ( V_11 -> V_176 ) )
V_145 -> V_166 |= V_180 ;
else if ( F_93 ( V_11 -> V_176 ) )
V_145 -> V_166 |= V_181 ;
if ( V_146 -> V_182 & 0x80 ) {
V_145 -> V_166 |= V_183 ;
V_145 -> V_166 |= V_146 -> V_166 ;
V_145 -> V_184 = V_146 -> V_182 & 0x7f ;
return 0 ;
}
for ( V_53 = 0 ; V_53 < V_173 -> V_185 ; V_53 ++ ) {
if ( V_173 -> V_186 [ V_53 ] . V_187 == V_146 -> V_182 ) {
V_145 -> V_184 = V_53 ;
return 0 ;
}
if ( V_173 -> V_186 [ V_53 ] . V_188 == V_146 -> V_182 ) {
V_145 -> V_166 |= V_189 ;
V_145 -> V_184 = V_53 ;
return 0 ;
}
}
F_26 ( V_13 , V_190 ,
L_13 ,
V_146 -> V_182 ) ;
F_94 ( V_191 ) ;
return - V_138 ;
}
static void F_95 ( struct V_12 * V_13 ,
struct V_171 * V_59 ,
struct V_133 * V_146 ,
struct V_144 * V_145 )
{
struct V_1 * V_2 = V_59 -> V_148 ;
struct V_10 * V_11 = V_13 -> V_11 ;
int V_192 ;
int V_193 = V_146 -> V_194 ;
int V_53 , V_195 ;
if ( V_146 -> V_196 ) {
V_145 -> V_166 |= V_197 ;
return;
}
if ( V_146 -> V_194 == V_198 ) {
V_145 -> V_166 |= V_197 ;
return;
}
for ( V_53 = 0 , V_195 = 0 ; V_53 < F_96 ( V_146 -> V_199 ) ; V_53 ++ ) {
T_5 V_193 ;
if ( ! ( V_11 -> V_200 & F_97 ( V_53 ) ) )
continue;
V_193 = V_146 -> V_199 [ V_53 ] ;
if ( V_193 != V_198 ) {
V_145 -> V_201 |= F_97 ( V_195 ) ;
V_145 -> V_202 [ V_195 ] = V_11 -> V_203 + V_193 ;
}
V_195 ++ ;
}
if ( V_146 -> V_204 &&
( ( V_11 -> V_85 == V_86 ) ||
( V_11 -> V_85 == V_205 ) ) ) {
F_98 ( V_2 -> V_192 , V_146 -> V_194 ) ;
V_192 = V_2 -> V_192 ;
if ( F_99 ( V_192 != V_206 ) )
V_193 = F_100 ( V_192 , V_207 ) ;
if ( V_193 < 0 )
V_193 = 0 ;
V_11 -> V_208 . V_209 = V_193 ;
}
V_145 -> signal = V_11 -> V_203 + V_146 -> V_194 ;
}
static void F_101 ( struct V_133 * V_134 ,
struct V_144 * V_145 ,
T_6 V_210 )
{
T_1 V_211 = V_210 & 0xffffffff ;
V_145 -> V_212 = ( V_210 & ~ 0xffffffffULL ) | V_134 -> V_213 ;
if ( V_134 -> V_213 > V_211 &&
F_43 ( V_134 -> V_213 - V_211 > 0x10000000 ) )
V_145 -> V_212 -= 0x100000000ULL ;
if ( V_134 -> V_213 < V_211 &&
F_43 ( V_211 - V_134 -> V_213 > 0x10000000 ) )
V_145 -> V_212 += 0x100000000ULL ;
}
static int F_102 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_133 * V_146 ,
struct V_144 * V_214 ,
bool * V_147 , T_6 V_210 )
{
struct V_171 * V_59 = V_2 -> V_59 ;
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_127 * V_128 ;
bool V_215 = V_2 -> V_26 . V_216 ;
if ( V_215 )
goto V_217;
V_2 -> V_26 . V_216 = false ;
if ( ! V_146 -> V_142 ) {
F_94 ( V_218 ) ;
goto V_217;
}
if ( V_146 -> V_142 > ( V_13 -> V_25 - V_11 -> V_5 . V_43 ) ) {
F_94 ( V_218 ) ;
goto V_217;
}
if ( V_146 -> V_143 )
return 0 ;
if ( V_146 -> V_157 & V_219 )
goto V_217;
V_128 = (struct V_127 * ) ( V_17 -> V_24 + V_11 -> V_5 . V_43 ) ;
F_101 ( V_146 , V_214 , V_210 ) ;
F_103 ( V_2 , V_146 ) ;
if ( V_146 -> V_157 & V_220 ) {
F_104 ( V_2 , V_128 , V_146 , V_214 -> V_212 ) ;
if ( F_105 ( V_2 , V_128 , V_146 , V_214 -> V_212 ) )
F_94 ( V_221 ) ;
return - V_138 ;
}
if ( ! F_86 ( V_13 , V_128 , V_214 , V_146 , V_147 ) )
return - V_138 ;
if ( F_106 ( V_13 , V_128 ) ) {
F_94 ( V_222 ) ;
V_146 -> V_204 = true ;
}
if ( F_107 ( ! V_11 -> V_176 ) )
return - V_138 ;
if ( F_91 ( V_13 , V_59 , V_146 , V_214 ) )
return - V_138 ;
F_95 ( V_13 , V_59 , V_146 , V_214 ) ;
V_214 -> V_175 = V_11 -> V_176 -> V_177 -> V_175 ;
V_214 -> V_223 = V_11 -> V_176 -> V_177 -> V_224 ;
V_214 -> V_30 = V_146 -> V_225 ;
V_214 -> V_166 |= V_226 ;
#ifdef F_108
if ( F_109 ( V_128 -> V_129 ) &&
! F_110 ( V_128 -> V_129 ) )
V_2 -> V_26 . V_227 ++ ;
#endif
return 0 ;
V_217:
V_2 -> V_26 . V_216 = V_146 -> V_143 ;
return - V_138 ;
}
static void F_111 ( struct V_12 * V_13 ,
struct V_16 * V_17 ,
struct V_133 * V_146 ,
struct V_144 * V_145 ,
bool V_147 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
struct V_127 * V_128 ;
int V_228 , V_229 , V_230 ;
T_2 V_231 ;
T_3 V_153 ;
V_128 = (struct V_127 * ) V_17 -> V_24 ;
V_228 = F_112 ( V_17 ) ;
V_153 = V_128 -> V_129 ;
V_229 = F_113 ( V_153 ) ;
V_230 = V_229 & 3 ;
if ( V_230 && V_17 -> V_117 >= V_229 + V_230 + V_232 ) {
memmove ( V_17 -> V_24 + V_230 , V_17 -> V_24 , V_229 ) ;
F_114 ( V_17 , V_230 ) ;
}
V_231 = V_146 -> V_154 ;
if ( ! ( V_231 == V_155 ) && ! V_147 &&
F_88 ( V_153 ) ) {
V_145 -> V_166 |= V_233 ;
} else if ( F_88 ( V_153 )
&& ! V_147 && V_17 -> V_117 >= V_228 + 4 ) {
V_231 = V_17 -> V_24 [ V_228 + 3 ] >> 6 ;
if ( F_87 ( V_231 , V_13 -> V_234 ) )
V_145 -> V_166 |= V_233 ;
}
if ( V_11 -> V_235 &&
( V_145 -> V_166 & V_233 ) &&
F_115 ( V_153 ) )
V_145 -> V_166 &= ~ V_233 ;
}
static void F_116 ( struct V_1 * V_2 ,
struct V_133 * V_134 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_236 * V_237 = & V_11 -> V_5 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
if ( ! ( V_11 -> V_5 . V_6 & V_238 ) )
return;
if ( V_2 -> V_26 . V_31 != V_134 -> V_225 ) {
if ( ++ V_2 -> V_26 . V_32 >= 3 )
F_8 ( V_2 , V_134 -> V_225 ) ;
} else {
V_2 -> V_26 . V_32 = 0 ;
}
if ( V_237 -> V_6 & V_239 ) {
if ( V_13 -> V_240 )
F_117 ( V_2 , V_134 ) ;
} else {
F_117 ( V_2 , V_134 ) ;
}
}
static void F_118 ( struct V_1 * V_2 ,
struct V_133 * V_134 , struct V_144 * V_145 )
{
if ( V_134 -> V_241 ) {
V_145 -> V_166 |= V_242 | V_243 ;
V_145 -> V_244 = V_2 -> V_26 . V_245 ;
if ( ! V_134 -> V_196 ) {
V_145 -> V_166 |= V_246 ;
V_2 -> V_26 . V_245 ++ ;
}
if ( V_134 -> V_247 & V_248 )
V_145 -> V_166 |= V_249 ;
}
}
int F_61 ( struct V_1 * V_2 , int V_250 , bool V_251 )
{
struct V_8 * V_9 ;
struct V_16 * V_17 = NULL , * V_252 , * V_253 ;
struct V_144 * V_145 ;
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_171 * V_59 = V_2 -> V_59 ;
int V_254 ;
struct V_133 V_134 ;
enum V_35 V_36 ;
bool V_255 = ! ! ( V_11 -> V_5 . V_6 & V_65 ) ;
int V_256 ;
T_6 V_210 = 0 ;
unsigned long V_61 ;
T_7 V_257 ;
if ( V_255 )
V_256 = V_50 ;
else
V_256 = V_70 ;
V_36 = V_251 ? V_49 : V_48 ;
V_210 = F_119 ( V_11 ) ;
do {
bool V_147 = false ;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
if ( V_255 )
V_9 = F_80 ( V_2 , & V_134 , V_36 ) ;
else
V_9 = F_81 ( V_2 , & V_134 ) ;
if ( ! V_9 )
break;
V_17 = V_9 -> V_22 ;
if ( ! V_17 )
continue;
if ( V_2 -> V_26 . V_258 )
V_253 = V_2 -> V_26 . V_258 ;
else
V_253 = V_17 ;
V_145 = F_120 ( V_253 ) ;
memset ( V_145 , 0 , sizeof( struct V_144 ) ) ;
V_254 = F_102 ( V_2 , V_253 , & V_134 , V_145 ,
& V_147 , V_210 ) ;
if ( V_254 )
goto V_259;
V_252 = F_41 ( V_13 , V_13 -> V_25 , V_260 ) ;
if ( ! V_252 ) {
F_94 ( V_261 ) ;
goto V_259;
}
V_257 = F_42 ( V_2 -> V_44 , V_252 -> V_24 ,
V_13 -> V_25 , V_256 ) ;
if ( F_43 ( F_44 ( V_2 -> V_44 , V_257 ) ) ) {
F_34 ( V_252 ) ;
goto V_259;
}
F_33 ( V_2 -> V_44 , V_9 -> V_21 ,
V_13 -> V_25 , V_256 ) ;
V_9 -> V_22 = V_252 ;
V_9 -> V_21 = V_257 ;
F_121 ( V_17 , V_134 . V_142 + V_11 -> V_5 . V_43 ) ;
if ( V_11 -> V_5 . V_43 )
F_114 ( V_17 , V_11 -> V_5 . V_43 ) ;
if ( ! V_134 . V_143 )
F_111 ( V_13 , V_253 , & V_134 ,
V_145 , V_147 ) ;
if ( V_134 . V_143 ) {
F_94 ( V_262 ) ;
if ( V_2 -> V_26 . V_258 ) {
F_34 ( V_2 -> V_26 . V_258 ) ;
F_34 ( V_17 ) ;
F_94 ( V_263 ) ;
V_17 = NULL ;
}
V_2 -> V_26 . V_258 = V_17 ;
goto V_264;
}
if ( V_2 -> V_26 . V_258 ) {
int V_265 = V_17 -> V_117 - F_122 ( V_253 ) ;
if ( F_123 ( V_253 , 0 , V_265 , V_260 ) < 0 ) {
F_54 ( V_17 ) ;
F_94 ( V_261 ) ;
goto V_259;
}
V_2 -> V_26 . V_258 = NULL ;
F_124 ( V_17 , F_121 ( V_253 , V_17 -> V_117 ) ,
V_17 -> V_117 ) ;
F_34 ( V_17 ) ;
V_17 = V_253 ;
}
if ( V_145 -> V_166 & V_169 )
F_125 ( V_17 , V_17 -> V_117 - 8 ) ;
F_126 ( & V_2 -> V_266 , V_61 ) ;
if ( ( V_2 -> V_121 & ( V_122 |
V_125 |
V_131 ) ) ||
F_1 ( V_2 ) )
F_69 ( V_2 , V_17 , V_134 . V_204 ) ;
F_127 ( & V_2 -> V_266 , V_61 ) ;
F_116 ( V_2 , & V_134 ) ;
F_118 ( V_2 , & V_134 , V_145 ) ;
F_128 ( V_2 , & V_134 , V_17 ) ;
F_129 ( V_59 , V_17 ) ;
V_259:
if ( V_2 -> V_26 . V_258 ) {
F_34 ( V_2 -> V_26 . V_258 ) ;
V_2 -> V_26 . V_258 = NULL ;
}
V_264:
F_30 ( & V_9 -> V_42 , & V_2 -> V_26 . V_41 ) ;
if ( V_250 )
continue;
if ( V_255 ) {
F_16 ( V_2 , V_36 ) ;
} else {
F_7 ( V_2 , V_9 ) ;
F_47 ( V_11 ) ;
}
} while ( 1 );
if ( ! ( V_11 -> V_267 & V_268 ) ) {
V_11 -> V_267 |= ( V_268 | V_269 ) ;
F_130 ( V_11 ) ;
}
return 0 ;
}
