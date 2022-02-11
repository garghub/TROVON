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
V_33 = V_71 | V_72
| V_73 ;
if ( V_2 -> V_59 -> V_60 . V_74 )
V_33 |= V_75 | V_76 ;
if ( V_2 -> V_26 . V_77 & V_78 )
V_33 |= V_79 ;
if ( V_2 -> V_4 -> V_80 )
V_33 |= V_81 ;
if ( V_2 -> V_26 . V_77 & V_82 )
V_33 |= V_83 ;
if ( ( V_2 -> V_4 -> V_84 == V_85 ) &&
( V_2 -> V_86 <= 1 ) &&
! ( V_2 -> V_26 . V_77 & V_87 ) )
V_33 |= V_88 ;
else
V_33 |= V_89 ;
if ( ( V_2 -> V_4 -> V_84 == V_90 ) ||
( V_2 -> V_26 . V_77 & V_91 ) )
V_33 |= V_92 ;
if ( F_55 ( & V_2 -> V_59 -> V_60 ) )
V_33 |= V_93 ;
if ( V_2 -> V_86 > 1 || ( V_2 -> V_26 . V_77 & V_94 ) ) {
if ( V_2 -> V_4 -> V_95 . V_96 <= V_97 )
V_33 |= V_81 ;
V_33 |= V_98 ;
}
if ( F_56 ( V_2 -> V_4 ) )
V_33 |= V_99 ;
return V_33 ;
}
int F_57 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_8 * V_9 , * V_46 ;
if ( V_11 -> V_5 . V_6 & V_65 ) {
F_46 ( V_2 ) ;
return 0 ;
}
if ( F_25 ( & V_2 -> V_26 . V_41 ) )
goto V_100;
V_2 -> V_26 . V_29 = NULL ;
V_2 -> V_26 . V_27 = NULL ;
F_27 (bf, tbf, &sc->rx.rxbuf, list) {
F_2 ( V_2 , V_9 ) ;
}
if ( F_25 ( & V_2 -> V_26 . V_41 ) )
goto V_100;
V_9 = F_18 ( & V_2 -> V_26 . V_41 , struct V_8 , V_42 ) ;
F_6 ( V_11 , V_9 -> V_28 ) ;
F_47 ( V_11 ) ;
V_100:
F_10 ( V_2 ) ;
F_48 ( V_11 , ! ! ( V_2 -> V_59 -> V_60 . V_61 & V_62 ) ) ;
return 0 ;
}
static void F_58 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 -> V_5 . V_6 & V_65 )
F_59 ( V_2 , 1 , true ) ;
F_59 ( V_2 , 1 , false ) ;
}
bool F_60 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
bool V_101 , V_102 = false ;
F_61 ( V_11 ) ;
F_12 ( V_11 , 0 ) ;
V_101 = F_62 ( V_11 , & V_102 ) ;
F_58 ( V_2 ) ;
if ( V_2 -> V_4 -> V_5 . V_6 & V_65 )
F_49 ( V_2 ) ;
else
V_2 -> V_26 . V_27 = NULL ;
if ( ! ( V_11 -> V_103 & V_104 ) &&
F_43 ( ! V_101 ) ) {
F_45 ( F_3 ( V_2 -> V_4 ) ,
L_6
L_7 ) ;
F_63 ( ! V_101 ) ;
}
return V_101 && ! V_102 ;
}
static bool F_64 ( struct V_16 * V_17 )
{
struct V_105 * V_106 ;
T_2 * V_107 , * V_108 , V_109 , V_110 ;
struct V_111 * V_112 ;
V_106 = (struct V_105 * ) V_17 -> V_24 ;
V_107 = V_106 -> V_113 . V_114 . V_115 ;
V_108 = V_17 -> V_24 + V_17 -> V_116 ;
while ( V_107 + 2 < V_108 ) {
V_109 = * V_107 ++ ;
V_110 = * V_107 ++ ;
if ( V_107 + V_110 > V_108 )
break;
if ( V_109 == V_117 ) {
if ( V_110 < sizeof( * V_112 ) )
break;
V_112 = (struct V_111 * ) V_107 ;
if ( V_112 -> V_118 != 0 )
break;
return V_112 -> V_119 & 0x01 ;
}
V_107 += V_110 ;
}
return false ;
}
static void F_65 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
if ( V_17 -> V_116 < 24 + 8 + 2 + 2 )
return;
V_2 -> V_120 &= ~ V_121 ;
if ( V_2 -> V_120 & V_122 ) {
V_2 -> V_120 &= ~ V_122 ;
F_26 ( V_13 , V_123 ,
L_8 ) ;
F_66 ( V_2 ) ;
}
if ( F_64 ( V_17 ) ) {
F_26 ( V_13 , V_123 ,
L_9 ) ;
V_2 -> V_120 |= V_124 | V_121 ;
return;
}
if ( V_2 -> V_120 & V_124 ) {
V_2 -> V_120 &= ~ V_124 ;
F_26 ( V_13 , V_123 , L_10 ) ;
}
}
static void F_67 ( struct V_1 * V_2 , struct V_16 * V_17 , bool V_125 )
{
struct V_126 * V_127 ;
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
V_127 = (struct V_126 * ) V_17 -> V_24 ;
if ( ( ( V_2 -> V_120 & V_121 ) || F_1 ( V_2 ) )
&& V_125 ) {
F_65 ( V_2 , V_17 ) ;
} else if ( ( V_2 -> V_120 & V_124 ) &&
( F_68 ( V_127 -> V_128 ) ||
F_69 ( V_127 -> V_128 ) ) &&
F_70 ( V_127 -> V_129 ) &&
! F_71 ( V_127 -> V_128 ) ) {
V_2 -> V_120 &= ~ ( V_124 | V_121 ) ;
F_26 ( V_13 , V_123 ,
L_11 ) ;
} else if ( ( V_2 -> V_120 & V_130 ) &&
! F_70 ( V_127 -> V_129 ) &&
! F_72 ( V_127 -> V_128 ) ) {
V_2 -> V_120 &= ~ V_130 ;
F_26 ( V_13 , V_123 ,
L_12 ,
V_2 -> V_120 & ( V_121 |
V_124 |
V_130 |
V_131 ) ) ;
}
}
static bool F_73 ( struct V_1 * V_2 ,
enum V_35 V_36 ,
struct V_132 * V_133 ,
struct V_8 * * V_134 )
{
struct V_37 * V_38 = & V_2 -> V_26 . V_38 [ V_36 ] ;
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_16 * V_17 ;
struct V_8 * V_9 ;
int V_135 ;
V_17 = F_74 ( & V_38 -> V_39 ) ;
if ( ! V_17 )
return false ;
V_9 = F_21 ( V_17 ) ;
F_4 ( ! V_9 ) ;
F_75 ( V_2 -> V_44 , V_9 -> V_21 ,
V_13 -> V_25 , V_70 ) ;
V_135 = F_76 ( V_11 , V_133 , V_17 -> V_24 ) ;
if ( V_135 == - V_136 ) {
F_20 ( V_2 -> V_44 , V_9 -> V_21 ,
V_13 -> V_25 , V_70 ) ;
return false ;
}
F_77 ( V_17 , & V_38 -> V_39 ) ;
if ( V_135 == - V_137 ) {
F_30 ( & V_9 -> V_42 , & V_2 -> V_26 . V_41 ) ;
F_16 ( V_2 , V_36 ) ;
V_17 = F_74 ( & V_38 -> V_39 ) ;
if ( V_17 ) {
V_9 = F_21 ( V_17 ) ;
F_4 ( ! V_9 ) ;
F_77 ( V_17 , & V_38 -> V_39 ) ;
F_30 ( & V_9 -> V_42 , & V_2 -> V_26 . V_41 ) ;
F_16 ( V_2 , V_36 ) ;
}
V_9 = NULL ;
}
* V_134 = V_9 ;
return true ;
}
static struct V_8 * F_78 ( struct V_1 * V_2 ,
struct V_132 * V_133 ,
enum V_35 V_36 )
{
struct V_8 * V_9 = NULL ;
while ( F_73 ( V_2 , V_36 , V_133 , & V_9 ) ) {
if ( ! V_9 )
continue;
return V_9 ;
}
return NULL ;
}
static struct V_8 * F_79 ( struct V_1 * V_2 ,
struct V_132 * V_133 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_14 * V_15 ;
struct V_8 * V_9 ;
int V_135 ;
if ( F_25 ( & V_2 -> V_26 . V_41 ) ) {
V_2 -> V_26 . V_27 = NULL ;
return NULL ;
}
V_9 = F_18 ( & V_2 -> V_26 . V_41 , struct V_8 , V_42 ) ;
if ( V_9 == V_2 -> V_26 . V_29 )
return NULL ;
V_15 = V_9 -> V_18 ;
V_135 = F_80 ( V_11 , V_15 , V_133 ) ;
if ( V_135 == - V_136 ) {
struct V_132 V_138 ;
struct V_8 * V_46 ;
struct V_14 * V_139 ;
memset ( & V_138 , 0 , sizeof( V_138 ) ) ;
if ( F_81 ( & V_9 -> V_42 , & V_2 -> V_26 . V_41 ) ) {
V_2 -> V_26 . V_27 = NULL ;
return NULL ;
}
V_46 = F_82 ( V_9 -> V_42 . V_140 , struct V_8 , V_42 ) ;
V_139 = V_46 -> V_18 ;
V_135 = F_80 ( V_11 , V_139 , & V_138 ) ;
if ( V_135 == - V_136 )
return NULL ;
V_133 -> V_141 = 0 ;
V_133 -> V_142 = true ;
}
F_83 ( & V_9 -> V_42 ) ;
if ( ! V_9 -> V_22 )
return V_9 ;
F_75 ( V_2 -> V_44 , V_9 -> V_21 ,
V_13 -> V_25 ,
V_70 ) ;
return V_9 ;
}
static bool F_84 ( struct V_12 * V_13 ,
struct V_126 * V_127 ,
struct V_143 * V_144 ,
struct V_132 * V_145 ,
bool * V_146 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 -> V_147 ;
bool V_148 , V_149 , V_150 , V_151 ;
struct V_10 * V_11 = V_13 -> V_11 ;
T_3 V_152 ;
V_152 = V_127 -> V_128 ;
V_148 = ! ! F_70 ( V_127 -> V_129 ) ;
V_149 = V_145 -> V_153 != V_154 &&
F_85 ( V_145 -> V_153 , V_13 -> V_155 ) ;
V_150 = V_149 && F_68 ( V_152 ) &&
F_86 ( V_152 ) &&
! ( V_145 -> V_156 &
( V_157 | V_158 | V_159 |
V_160 ) ) ;
if ( V_145 -> V_153 == V_154 ||
! F_85 ( V_145 -> V_153 , V_13 -> V_161 ) )
V_145 -> V_156 &= ~ V_160 ;
V_151 = V_149 && ! F_87 ( V_152 ) &&
! F_72 ( V_152 ) &&
! ( F_88 ( V_127 -> V_162 ) & V_163 ) &&
( V_145 -> V_156 & V_159 ) ;
if ( V_145 -> V_156 != 0 ) {
T_2 V_164 ;
if ( V_145 -> V_156 & V_158 ) {
V_144 -> V_165 |= V_166 ;
V_151 = false ;
}
if ( ( V_145 -> V_156 & V_157 ) ||
( ! V_148 && ( V_145 -> V_156 & V_160 ) ) ) {
* V_146 = true ;
V_151 = false ;
}
V_164 = V_157 | V_159 |
V_160 ;
if ( V_11 -> V_80 && ( V_2 -> V_26 . V_77 & V_167 ) )
V_164 |= V_158 ;
if ( V_145 -> V_156 & ~ V_164 )
return false ;
}
if ( V_150 )
V_144 -> V_165 |= V_168 ;
else if ( V_148 && V_151 )
V_144 -> V_165 |= V_169 ;
return true ;
}
static int F_89 ( struct V_12 * V_13 ,
struct V_170 * V_59 ,
struct V_132 * V_145 ,
struct V_143 * V_144 )
{
struct V_171 * V_172 ;
enum V_173 V_174 ;
unsigned int V_53 = 0 ;
struct V_1 T_4 * V_2 = V_13 -> V_147 ;
V_174 = V_59 -> V_60 . V_175 . V_176 -> V_174 ;
V_172 = V_59 -> V_177 -> V_178 [ V_174 ] ;
switch ( V_59 -> V_60 . V_175 . V_179 ) {
case V_180 :
V_144 -> V_165 |= V_181 ;
break;
case V_182 :
V_144 -> V_165 |= V_183 ;
break;
default:
break;
}
if ( V_145 -> V_184 & 0x80 ) {
V_144 -> V_165 |= V_185 ;
V_144 -> V_165 |= V_145 -> V_165 ;
V_144 -> V_186 = V_145 -> V_184 & 0x7f ;
return 0 ;
}
for ( V_53 = 0 ; V_53 < V_172 -> V_187 ; V_53 ++ ) {
if ( V_172 -> V_188 [ V_53 ] . V_189 == V_145 -> V_184 ) {
V_144 -> V_186 = V_53 ;
return 0 ;
}
if ( V_172 -> V_188 [ V_53 ] . V_190 == V_145 -> V_184 ) {
V_144 -> V_165 |= V_191 ;
V_144 -> V_186 = V_53 ;
return 0 ;
}
}
F_26 ( V_13 , V_192 ,
L_13 ,
V_145 -> V_184 ) ;
F_90 ( V_193 ) ;
return - V_137 ;
}
static void F_91 ( struct V_12 * V_13 ,
struct V_170 * V_59 ,
struct V_132 * V_145 ,
struct V_143 * V_144 )
{
struct V_1 * V_2 = V_59 -> V_147 ;
struct V_10 * V_11 = V_13 -> V_11 ;
int V_194 ;
int V_195 = V_145 -> V_196 ;
if ( V_145 -> V_197 ) {
V_144 -> V_165 |= V_198 ;
return;
}
if ( V_145 -> V_196 == V_199 ) {
V_144 -> V_165 |= V_198 ;
return;
}
if ( V_145 -> V_200 &&
( ( V_11 -> V_84 == V_85 ) ||
( V_11 -> V_84 == V_201 ) ) ) {
F_92 ( V_2 -> V_194 , V_145 -> V_196 ) ;
V_194 = V_2 -> V_194 ;
if ( F_93 ( V_194 != V_202 ) )
V_195 = F_94 ( V_194 , V_203 ) ;
if ( V_195 < 0 )
V_195 = 0 ;
V_11 -> V_204 . V_205 = V_195 ;
}
V_144 -> signal = V_11 -> V_206 + V_145 -> V_196 ;
}
static void F_95 ( struct V_132 * V_133 ,
struct V_143 * V_144 ,
T_5 V_207 )
{
T_1 V_208 = V_207 & 0xffffffff ;
V_144 -> V_209 = ( V_207 & ~ 0xffffffffULL ) | V_133 -> V_210 ;
if ( V_133 -> V_210 > V_208 &&
F_43 ( V_133 -> V_210 - V_208 > 0x10000000 ) )
V_144 -> V_209 -= 0x100000000ULL ;
if ( V_133 -> V_210 < V_208 &&
F_43 ( V_208 - V_133 -> V_210 > 0x10000000 ) )
V_144 -> V_209 += 0x100000000ULL ;
}
static T_6 F_96 ( T_2 V_211 )
{
if ( V_211 == 128 )
V_211 = 0 ;
return ( T_6 ) V_211 ;
}
static int F_97 ( struct V_1 * V_2 , struct V_126 * V_127 ,
struct V_132 * V_133 , T_5 V_207 )
{
#ifdef F_98
struct V_10 * V_11 = V_2 -> V_4 ;
T_2 V_212 [ V_213 ] ;
T_2 * V_214 = ( T_2 * ) V_127 ;
struct V_215 V_216 ;
struct V_217 * V_218 ;
struct V_219 * V_220 ;
int V_116 = V_133 -> V_141 ;
int V_221 ;
T_7 V_222 , V_223 ;
if ( V_133 -> V_224 != V_225 &&
V_133 -> V_224 != V_226 &&
V_133 -> V_224 != V_227 )
return 0 ;
V_218 = ( (struct V_217 * ) & V_214 [ V_116 ] ) - 1 ;
if ( ! ( V_218 -> V_228 & V_229 ) )
return 0 ;
if ( ( V_116 > V_230 + 2 ) ||
( V_116 < V_230 - 1 ) )
return 1 ;
V_216 . V_231 . type = V_232 ;
V_222 = sizeof( V_216 ) - sizeof( V_216 . V_231 ) ;
V_216 . V_231 . V_222 = F_99 ( V_222 ) ;
V_216 . V_233 = F_99 ( V_11 -> V_234 -> V_176 -> V_235 ) ;
V_216 . V_195 = F_96 ( V_133 -> V_236 ) ;
V_216 . V_206 = V_11 -> V_206 ;
switch ( V_116 - V_230 ) {
case 0 :
memcpy ( V_212 , V_214 , V_213 ) ;
break;
case - 1 :
memcpy ( & V_212 [ 1 ] , V_214 , V_213 - 1 ) ;
V_212 [ 0 ] = V_214 [ 0 ] ;
break;
case 2 :
memcpy ( V_212 , V_214 , 30 ) ;
V_212 [ 30 ] = V_214 [ 31 ] ;
memcpy ( & V_212 [ 31 ] , & V_214 [ 33 ] , V_213 - 31 ) ;
break;
case 1 :
V_212 [ 0 ] = V_214 [ 0 ] ;
memcpy ( & V_212 [ 0 ] , V_214 , 30 ) ;
V_212 [ 31 ] = V_214 [ 31 ] ;
memcpy ( & V_212 [ 32 ] , & V_214 [ 33 ] , V_213 - 32 ) ;
break;
default:
return 1 ;
}
V_221 = V_213 / 2 ;
V_212 [ V_221 ] = ( V_212 [ V_221 + 1 ] + V_212 [ V_221 - 1 ] ) / 2 ;
V_220 = ( (struct V_219 * ) V_218 ) - 1 ;
memcpy ( V_216 . V_24 , V_212 , V_213 ) ;
V_216 . V_237 = V_220 -> V_237 & 0xf ;
V_223 = F_100 ( V_220 -> V_238 ) ;
V_216 . V_223 = F_99 ( V_223 ) ;
V_216 . V_239 = F_101 ( V_220 -> V_238 ) ;
V_216 . V_240 = F_102 ( V_220 -> V_238 ) ;
V_216 . V_207 = F_103 ( V_207 ) ;
F_104 ( V_2 , & V_216 . V_231 ) ;
return 1 ;
#else
return 0 ;
#endif
}
static bool F_105 ( struct V_1 * V_2 , struct V_126 * V_127 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
if ( F_106 ( V_127 -> V_128 ) ) {
F_90 ( V_241 ) ;
if ( ! F_107 ( V_13 -> V_242 ) &&
F_108 ( V_127 -> V_243 , V_13 -> V_242 ) )
return true ;
}
return false ;
}
static int F_109 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_132 * V_145 ,
struct V_143 * V_244 ,
bool * V_146 , T_5 V_207 )
{
struct V_170 * V_59 = V_2 -> V_59 ;
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_126 * V_127 ;
bool V_245 = V_2 -> V_26 . V_246 ;
int V_135 = 0 ;
V_2 -> V_26 . V_246 = V_145 -> V_142 ;
if ( V_245 )
return - V_137 ;
if ( ! V_145 -> V_141 ) {
F_90 ( V_247 ) ;
return - V_137 ;
}
if ( V_145 -> V_141 > ( V_13 -> V_25 - V_11 -> V_5 . V_43 ) ) {
F_90 ( V_247 ) ;
return - V_137 ;
}
if ( V_145 -> V_142 )
return 0 ;
if ( V_145 -> V_156 & V_248 ) {
V_135 = - V_137 ;
goto exit;
}
V_127 = (struct V_126 * ) ( V_17 -> V_24 + V_11 -> V_5 . V_43 ) ;
F_95 ( V_145 , V_244 , V_207 ) ;
F_110 ( V_2 , V_145 ) ;
if ( V_145 -> V_156 & V_249 ) {
F_111 ( V_2 , V_127 , V_145 , V_244 -> V_209 ) ;
if ( F_97 ( V_2 , V_127 , V_145 , V_244 -> V_209 ) )
F_90 ( V_250 ) ;
V_135 = - V_137 ;
goto exit;
}
if ( ! F_84 ( V_13 , V_127 , V_244 , V_145 , V_146 ) ) {
V_135 = - V_137 ;
goto exit;
}
V_145 -> V_200 = F_105 ( V_2 , V_127 ) ;
if ( V_145 -> V_200 ) {
V_2 -> V_251 = 0 ;
F_112 ( V_2 , 3 ) ;
}
if ( F_89 ( V_13 , V_59 , V_145 , V_244 ) ) {
V_135 = - V_137 ;
goto exit;
}
F_91 ( V_13 , V_59 , V_145 , V_244 ) ;
V_244 -> V_174 = V_59 -> V_60 . V_175 . V_176 -> V_174 ;
V_244 -> V_233 = V_59 -> V_60 . V_175 . V_176 -> V_235 ;
V_244 -> V_30 = V_145 -> V_252 ;
V_244 -> V_165 |= V_253 ;
#ifdef F_113
if ( F_114 ( V_127 -> V_128 ) &&
! F_115 ( V_127 -> V_128 ) )
V_2 -> V_26 . V_254 ++ ;
#endif
exit:
V_2 -> V_26 . V_246 = false ;
return V_135 ;
}
static void F_116 ( struct V_12 * V_13 ,
struct V_16 * V_17 ,
struct V_132 * V_145 ,
struct V_143 * V_144 ,
bool V_146 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
struct V_126 * V_127 ;
int V_255 , V_256 , V_257 ;
T_2 V_258 ;
T_3 V_152 ;
V_127 = (struct V_126 * ) V_17 -> V_24 ;
V_255 = F_117 ( V_17 ) ;
V_152 = V_127 -> V_128 ;
V_256 = F_118 ( V_152 ) ;
V_257 = V_256 & 3 ;
if ( V_257 && V_17 -> V_116 >= V_256 + V_257 + V_259 ) {
memmove ( V_17 -> V_24 + V_257 , V_17 -> V_24 , V_256 ) ;
F_119 ( V_17 , V_257 ) ;
}
V_258 = V_145 -> V_153 ;
if ( ! ( V_258 == V_154 ) && ! V_146 &&
F_86 ( V_152 ) ) {
V_144 -> V_165 |= V_260 ;
} else if ( F_86 ( V_152 )
&& ! V_146 && V_17 -> V_116 >= V_255 + 4 ) {
V_258 = V_17 -> V_24 [ V_255 + 3 ] >> 6 ;
if ( F_85 ( V_258 , V_13 -> V_261 ) )
V_144 -> V_165 |= V_260 ;
}
if ( V_11 -> V_262 &&
( V_144 -> V_165 & V_260 ) &&
F_120 ( V_152 ) )
V_144 -> V_165 &= ~ V_260 ;
}
static void F_121 ( struct V_1 * V_2 ,
struct V_132 * V_133 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_263 * V_264 = & V_11 -> V_5 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
if ( ! ( V_11 -> V_5 . V_6 & V_265 ) )
return;
if ( V_2 -> V_26 . V_31 != V_133 -> V_252 ) {
if ( ++ V_2 -> V_26 . V_32 >= 3 )
F_8 ( V_2 , V_133 -> V_252 ) ;
} else {
V_2 -> V_26 . V_32 = 0 ;
}
if ( V_264 -> V_6 & V_266 ) {
if ( V_13 -> V_267 )
F_122 ( V_2 , V_133 ) ;
} else {
F_122 ( V_2 , V_133 ) ;
}
}
static void F_123 ( struct V_1 * V_2 ,
struct V_132 * V_133 , struct V_143 * V_144 )
{
if ( V_133 -> V_268 ) {
V_144 -> V_165 |= V_269 | V_270 ;
V_144 -> V_271 = V_2 -> V_26 . V_272 ;
if ( ! V_133 -> V_197 ) {
V_144 -> V_165 |= V_273 ;
V_2 -> V_26 . V_272 ++ ;
}
if ( V_133 -> V_274 & V_275 )
V_144 -> V_165 |= V_276 ;
}
}
int F_59 ( struct V_1 * V_2 , int V_277 , bool V_278 )
{
struct V_8 * V_9 ;
struct V_16 * V_17 = NULL , * V_279 , * V_280 ;
struct V_143 * V_144 ;
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_170 * V_59 = V_2 -> V_59 ;
int V_281 ;
struct V_132 V_133 ;
enum V_35 V_36 ;
bool V_282 = ! ! ( V_11 -> V_5 . V_6 & V_65 ) ;
int V_283 ;
T_5 V_207 = 0 ;
unsigned long V_61 ;
T_8 V_284 ;
if ( V_282 )
V_283 = V_50 ;
else
V_283 = V_70 ;
V_36 = V_278 ? V_49 : V_48 ;
V_207 = F_124 ( V_11 ) ;
do {
bool V_146 = false ;
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
if ( V_282 )
V_9 = F_78 ( V_2 , & V_133 , V_36 ) ;
else
V_9 = F_79 ( V_2 , & V_133 ) ;
if ( ! V_9 )
break;
V_17 = V_9 -> V_22 ;
if ( ! V_17 )
continue;
if ( V_2 -> V_26 . V_285 )
V_280 = V_2 -> V_26 . V_285 ;
else
V_280 = V_17 ;
V_144 = F_125 ( V_280 ) ;
memset ( V_144 , 0 , sizeof( struct V_143 ) ) ;
V_281 = F_109 ( V_2 , V_280 , & V_133 , V_144 ,
& V_146 , V_207 ) ;
if ( V_281 )
goto V_286;
V_279 = F_41 ( V_13 , V_13 -> V_25 , V_287 ) ;
if ( ! V_279 ) {
F_90 ( V_288 ) ;
goto V_286;
}
V_284 = F_42 ( V_2 -> V_44 , V_279 -> V_24 ,
V_13 -> V_25 , V_283 ) ;
if ( F_43 ( F_44 ( V_2 -> V_44 , V_284 ) ) ) {
F_34 ( V_279 ) ;
goto V_286;
}
F_33 ( V_2 -> V_44 , V_9 -> V_21 ,
V_13 -> V_25 , V_283 ) ;
V_9 -> V_22 = V_279 ;
V_9 -> V_21 = V_284 ;
F_126 ( V_17 , V_133 . V_141 + V_11 -> V_5 . V_43 ) ;
if ( V_11 -> V_5 . V_43 )
F_119 ( V_17 , V_11 -> V_5 . V_43 ) ;
if ( ! V_133 . V_142 )
F_116 ( V_13 , V_280 , & V_133 ,
V_144 , V_146 ) ;
if ( V_133 . V_142 ) {
F_90 ( V_289 ) ;
if ( V_2 -> V_26 . V_285 ) {
F_34 ( V_2 -> V_26 . V_285 ) ;
F_34 ( V_17 ) ;
F_90 ( V_290 ) ;
V_17 = NULL ;
}
V_2 -> V_26 . V_285 = V_17 ;
goto V_291;
}
if ( V_2 -> V_26 . V_285 ) {
int V_292 = V_17 -> V_116 - F_127 ( V_280 ) ;
if ( F_128 ( V_280 , 0 , V_292 , V_287 ) < 0 ) {
F_54 ( V_17 ) ;
F_90 ( V_288 ) ;
goto V_286;
}
V_2 -> V_26 . V_285 = NULL ;
F_129 ( V_17 , F_126 ( V_280 , V_17 -> V_116 ) ,
V_17 -> V_116 ) ;
F_34 ( V_17 ) ;
V_17 = V_280 ;
}
if ( V_144 -> V_165 & V_168 )
F_130 ( V_17 , V_17 -> V_116 - 8 ) ;
F_131 ( & V_2 -> V_293 , V_61 ) ;
if ( ( V_2 -> V_120 & ( V_121 |
V_124 |
V_130 ) ) ||
F_1 ( V_2 ) )
F_67 ( V_2 , V_17 , V_133 . V_200 ) ;
F_132 ( & V_2 -> V_293 , V_61 ) ;
F_121 ( V_2 , & V_133 ) ;
F_123 ( V_2 , & V_133 , V_144 ) ;
F_133 ( V_59 , V_17 ) ;
V_286:
if ( V_2 -> V_26 . V_285 ) {
F_34 ( V_2 -> V_26 . V_285 ) ;
V_2 -> V_26 . V_285 = NULL ;
}
V_291:
F_30 ( & V_9 -> V_42 , & V_2 -> V_26 . V_41 ) ;
if ( V_277 )
continue;
if ( V_282 ) {
F_16 ( V_2 , V_36 ) ;
} else {
F_7 ( V_2 , V_9 ) ;
F_47 ( V_11 ) ;
}
} while ( 1 );
if ( ! ( V_11 -> V_294 & V_295 ) ) {
V_11 -> V_294 |= ( V_295 | V_296 ) ;
F_134 ( V_11 ) ;
}
return 0 ;
}
