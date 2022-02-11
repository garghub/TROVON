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
enum V_34 V_35 , int V_45 )
{
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
struct V_8 * V_9 , * V_46 ;
if ( F_25 ( & V_2 -> V_26 . V_40 ) ) {
F_26 ( V_13 , V_47 , L_1 ) ;
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
F_28 ( V_2 , V_48 ) ;
F_28 ( V_2 , V_49 ) ;
F_32 (bf, &sc->rx.rxbuf, list) {
if ( V_9 -> V_22 ) {
F_33 ( V_2 -> V_43 , V_9 -> V_21 ,
V_13 -> V_25 ,
V_50 ) ;
F_34 ( V_9 -> V_22 ) ;
V_9 -> V_21 = 0 ;
V_9 -> V_22 = NULL ;
}
}
F_35 ( & V_2 -> V_26 . V_40 ) ;
F_36 ( V_2 -> V_26 . V_51 ) ;
V_2 -> V_26 . V_51 = NULL ;
}
static void F_37 ( struct V_36 * V_37 , int V_45 )
{
F_38 ( & V_37 -> V_38 ) ;
V_37 -> V_39 = V_45 ;
}
static int F_39 ( struct V_1 * V_2 , int V_52 )
{
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_16 * V_17 ;
struct V_8 * V_9 ;
int error = 0 , V_53 ;
T_1 V_45 ;
F_40 ( V_11 , V_13 -> V_25 -
V_11 -> V_5 . V_42 ) ;
F_37 ( & V_2 -> V_26 . V_37 [ V_48 ] ,
V_11 -> V_5 . V_54 ) ;
F_37 ( & V_2 -> V_26 . V_37 [ V_49 ] ,
V_11 -> V_5 . V_55 ) ;
V_45 = sizeof( struct V_8 ) * V_52 ;
V_9 = F_41 ( V_45 , V_56 ) ;
if ( ! V_9 )
return - V_57 ;
F_35 ( & V_2 -> V_26 . V_40 ) ;
V_2 -> V_26 . V_51 = V_9 ;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ , V_9 ++ ) {
V_17 = F_42 ( V_13 , V_13 -> V_25 , V_56 ) ;
if ( ! V_17 ) {
error = - V_57 ;
goto V_58;
}
memset ( V_17 -> V_24 , 0 , V_13 -> V_25 ) ;
V_9 -> V_22 = V_17 ;
V_9 -> V_21 = F_43 ( V_2 -> V_43 , V_17 -> V_24 ,
V_13 -> V_25 ,
V_50 ) ;
if ( F_44 ( F_45 ( V_2 -> V_43 ,
V_9 -> V_21 ) ) ) {
F_34 ( V_17 ) ;
V_9 -> V_22 = NULL ;
V_9 -> V_21 = 0 ;
F_46 ( V_13 ,
L_2 ) ;
error = - V_57 ;
goto V_58;
}
F_30 ( & V_9 -> V_41 , & V_2 -> V_26 . V_40 ) ;
}
return 0 ;
V_58:
F_31 ( V_2 ) ;
return error ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_48 ( V_2 -> V_4 ) ;
F_24 ( V_2 , V_49 ,
V_2 -> V_26 . V_37 [ V_49 ] . V_39 ) ;
F_24 ( V_2 , V_48 ,
V_2 -> V_26 . V_37 [ V_48 ] . V_39 ) ;
F_10 ( V_2 ) ;
F_49 ( V_2 -> V_4 , ! ! ( V_2 -> V_59 -> V_60 . V_61 & V_62 ) ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_28 ( V_2 , V_49 ) ;
F_28 ( V_2 , V_48 ) ;
}
int F_51 ( struct V_1 * V_2 , int V_52 )
{
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
struct V_16 * V_17 ;
struct V_8 * V_9 ;
int error = 0 ;
F_52 ( & V_2 -> V_63 ) ;
V_13 -> V_25 = V_64 / 2 +
V_2 -> V_4 -> V_5 . V_42 ;
if ( V_2 -> V_4 -> V_5 . V_6 & V_65 ) {
return F_39 ( V_2 , V_52 ) ;
} else {
F_26 ( V_13 , V_66 , L_3 ,
V_13 -> V_67 , V_13 -> V_25 ) ;
error = F_53 ( V_2 , & V_2 -> V_26 . V_68 , & V_2 -> V_26 . V_40 ,
L_4 , V_52 , 1 , 0 ) ;
if ( error != 0 ) {
F_46 ( V_13 ,
L_5 ,
error ) ;
goto V_69;
}
F_32 (bf, &sc->rx.rxbuf, list) {
V_17 = F_42 ( V_13 , V_13 -> V_25 ,
V_56 ) ;
if ( V_17 == NULL ) {
error = - V_57 ;
goto V_69;
}
V_9 -> V_22 = V_17 ;
V_9 -> V_21 = F_43 ( V_2 -> V_43 , V_17 -> V_24 ,
V_13 -> V_25 ,
V_70 ) ;
if ( F_44 ( F_45 ( V_2 -> V_43 ,
V_9 -> V_21 ) ) ) {
F_34 ( V_17 ) ;
V_9 -> V_22 = NULL ;
V_9 -> V_21 = 0 ;
F_46 ( V_13 ,
L_2 ) ;
error = - V_57 ;
goto V_69;
}
}
V_2 -> V_26 . V_27 = NULL ;
}
V_69:
if ( error )
F_54 ( V_2 ) ;
return error ;
}
void F_54 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_16 * V_17 ;
struct V_8 * V_9 ;
if ( V_2 -> V_4 -> V_5 . V_6 & V_65 ) {
F_31 ( V_2 ) ;
return;
} else {
F_32 (bf, &sc->rx.rxbuf, list) {
V_17 = V_9 -> V_22 ;
if ( V_17 ) {
F_33 ( V_2 -> V_43 , V_9 -> V_21 ,
V_13 -> V_25 ,
V_70 ) ;
F_55 ( V_17 ) ;
V_9 -> V_21 = 0 ;
V_9 -> V_22 = NULL ;
}
}
if ( V_2 -> V_26 . V_68 . V_71 != 0 )
F_56 ( V_2 , & V_2 -> V_26 . V_68 , & V_2 -> V_26 . V_40 ) ;
}
}
T_1 F_11 ( struct V_1 * V_2 )
{
T_1 V_32 ;
V_32 = V_72 | V_73
| V_74 ;
if ( V_2 -> V_26 . V_75 & V_76 )
V_32 |= V_77 ;
if ( V_2 -> V_4 -> V_78 )
V_32 |= V_79 ;
if ( V_2 -> V_26 . V_75 & V_80 )
V_32 |= V_81 ;
if ( ( V_2 -> V_4 -> V_82 == V_83 ) &&
( V_2 -> V_84 <= 1 ) &&
! ( V_2 -> V_26 . V_75 & V_85 ) )
V_32 |= V_86 ;
else
V_32 |= V_87 ;
if ( ( V_2 -> V_4 -> V_82 == V_88 ) ||
( V_2 -> V_26 . V_75 & V_89 ) )
V_32 |= V_90 ;
if ( F_57 ( & V_2 -> V_59 -> V_60 ) )
V_32 |= V_91 ;
if ( V_2 -> V_84 > 1 || ( V_2 -> V_26 . V_75 & V_92 ) ) {
if ( V_2 -> V_4 -> V_93 . V_94 <= V_95 )
V_32 |= V_79 ;
V_32 |= V_96 ;
}
if ( F_58 ( V_2 -> V_4 ) )
V_32 |= V_97 ;
return V_32 ;
}
int F_59 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_8 * V_9 , * V_46 ;
if ( V_11 -> V_5 . V_6 & V_65 ) {
F_47 ( V_2 ) ;
return 0 ;
}
if ( F_25 ( & V_2 -> V_26 . V_40 ) )
goto V_98;
V_2 -> V_26 . V_27 = NULL ;
F_27 (bf, tbf, &sc->rx.rxbuf, list) {
F_2 ( V_2 , V_9 ) ;
}
if ( F_25 ( & V_2 -> V_26 . V_40 ) )
goto V_98;
V_9 = F_18 ( & V_2 -> V_26 . V_40 , struct V_8 , V_41 ) ;
F_7 ( V_11 , V_9 -> V_28 ) ;
F_48 ( V_11 ) ;
V_98:
F_10 ( V_2 ) ;
F_49 ( V_11 , ! ! ( V_2 -> V_59 -> V_60 . V_61 & V_62 ) ) ;
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
bool V_99 , V_100 = false ;
F_63 ( V_11 ) ;
F_12 ( V_11 , 0 ) ;
V_99 = F_64 ( V_11 , & V_100 ) ;
F_60 ( V_2 ) ;
if ( V_2 -> V_4 -> V_5 . V_6 & V_65 )
F_50 ( V_2 ) ;
else
V_2 -> V_26 . V_27 = NULL ;
if ( ! ( V_11 -> V_101 & V_102 ) &&
F_44 ( ! V_99 ) ) {
F_46 ( F_3 ( V_2 -> V_4 ) ,
L_6
L_7 ) ;
F_65 ( ! V_99 ) ;
}
return V_99 && ! V_100 ;
}
static bool F_66 ( struct V_16 * V_17 )
{
struct V_103 * V_104 ;
T_2 * V_105 , * V_106 , V_107 , V_108 ;
struct V_109 * V_110 ;
V_104 = (struct V_103 * ) V_17 -> V_24 ;
V_105 = V_104 -> V_111 . V_112 . V_113 ;
V_106 = V_17 -> V_24 + V_17 -> V_114 ;
while ( V_105 + 2 < V_106 ) {
V_107 = * V_105 ++ ;
V_108 = * V_105 ++ ;
if ( V_105 + V_108 > V_106 )
break;
if ( V_107 == V_115 ) {
if ( V_108 < sizeof( * V_110 ) )
break;
V_110 = (struct V_109 * ) V_105 ;
if ( V_110 -> V_116 != 0 )
break;
return V_110 -> V_117 & 0x01 ;
}
V_105 += V_108 ;
}
return false ;
}
static void F_67 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
if ( V_17 -> V_114 < 24 + 8 + 2 + 2 )
return;
V_2 -> V_118 &= ~ V_119 ;
if ( V_2 -> V_118 & V_120 ) {
V_2 -> V_118 &= ~ V_120 ;
F_26 ( V_13 , V_121 ,
L_8 ) ;
F_68 ( V_2 ) ;
}
if ( F_66 ( V_17 ) ) {
F_26 ( V_13 , V_121 ,
L_9 ) ;
V_2 -> V_118 |= V_122 | V_119 ;
return;
}
if ( V_2 -> V_118 & V_122 ) {
V_2 -> V_118 &= ~ V_122 ;
F_26 ( V_13 , V_121 , L_10 ) ;
}
}
static void F_69 ( struct V_1 * V_2 , struct V_16 * V_17 , bool V_123 )
{
struct V_124 * V_125 ;
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
V_125 = (struct V_124 * ) V_17 -> V_24 ;
if ( ( ( V_2 -> V_118 & V_119 ) || F_1 ( V_2 ) )
&& V_123 ) {
F_67 ( V_2 , V_17 ) ;
} else if ( ( V_2 -> V_118 & V_122 ) &&
( F_70 ( V_125 -> V_126 ) ||
F_71 ( V_125 -> V_126 ) ) &&
F_72 ( V_125 -> V_127 ) &&
! F_73 ( V_125 -> V_126 ) ) {
V_2 -> V_118 &= ~ ( V_122 | V_119 ) ;
F_26 ( V_13 , V_121 ,
L_11 ) ;
} else if ( ( V_2 -> V_118 & V_128 ) &&
! F_72 ( V_125 -> V_127 ) &&
! F_74 ( V_125 -> V_126 ) ) {
V_2 -> V_118 &= ~ V_128 ;
F_26 ( V_13 , V_121 ,
L_12 ,
V_2 -> V_118 & ( V_119 |
V_122 |
V_128 |
V_129 ) ) ;
}
}
static bool F_75 ( struct V_1 * V_2 ,
enum V_34 V_35 ,
struct V_130 * V_131 ,
struct V_8 * * V_132 )
{
struct V_36 * V_37 = & V_2 -> V_26 . V_37 [ V_35 ] ;
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_16 * V_17 ;
struct V_8 * V_9 ;
int V_133 ;
V_17 = F_76 ( & V_37 -> V_38 ) ;
if ( ! V_17 )
return false ;
V_9 = F_21 ( V_17 ) ;
F_5 ( ! V_9 ) ;
F_77 ( V_2 -> V_43 , V_9 -> V_21 ,
V_13 -> V_25 , V_70 ) ;
V_133 = F_78 ( V_11 , V_131 , V_17 -> V_24 ) ;
if ( V_133 == - V_134 ) {
F_20 ( V_2 -> V_43 , V_9 -> V_21 ,
V_13 -> V_25 , V_70 ) ;
return false ;
}
F_79 ( V_17 , & V_37 -> V_38 ) ;
if ( V_133 == - V_135 ) {
F_30 ( & V_9 -> V_41 , & V_2 -> V_26 . V_40 ) ;
F_16 ( V_2 , V_35 ) ;
V_17 = F_76 ( & V_37 -> V_38 ) ;
if ( V_17 ) {
V_9 = F_21 ( V_17 ) ;
F_5 ( ! V_9 ) ;
F_79 ( V_17 , & V_37 -> V_38 ) ;
F_30 ( & V_9 -> V_41 , & V_2 -> V_26 . V_40 ) ;
F_16 ( V_2 , V_35 ) ;
}
V_9 = NULL ;
}
* V_132 = V_9 ;
return true ;
}
static struct V_8 * F_80 ( struct V_1 * V_2 ,
struct V_130 * V_131 ,
enum V_34 V_35 )
{
struct V_8 * V_9 = NULL ;
while ( F_75 ( V_2 , V_35 , V_131 , & V_9 ) ) {
if ( ! V_9 )
continue;
return V_9 ;
}
return NULL ;
}
static struct V_8 * F_81 ( struct V_1 * V_2 ,
struct V_130 * V_131 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_14 * V_15 ;
struct V_8 * V_9 ;
int V_133 ;
if ( F_25 ( & V_2 -> V_26 . V_40 ) ) {
V_2 -> V_26 . V_27 = NULL ;
return NULL ;
}
V_9 = F_18 ( & V_2 -> V_26 . V_40 , struct V_8 , V_41 ) ;
V_15 = V_9 -> V_18 ;
V_133 = F_82 ( V_11 , V_15 , V_131 ) ;
if ( V_133 == - V_134 ) {
struct V_130 V_136 ;
struct V_8 * V_46 ;
struct V_14 * V_137 ;
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
if ( F_83 ( & V_9 -> V_41 , & V_2 -> V_26 . V_40 ) ) {
V_2 -> V_26 . V_27 = NULL ;
return NULL ;
}
V_46 = F_84 ( V_9 -> V_41 . V_138 , struct V_8 , V_41 ) ;
V_137 = V_46 -> V_18 ;
V_133 = F_82 ( V_11 , V_137 , & V_136 ) ;
if ( V_133 == - V_134 )
return NULL ;
}
F_85 ( & V_9 -> V_41 ) ;
if ( ! V_9 -> V_22 )
return V_9 ;
F_77 ( V_2 -> V_43 , V_9 -> V_21 ,
V_13 -> V_25 ,
V_70 ) ;
return V_9 ;
}
static bool F_86 ( struct V_12 * V_13 ,
struct V_124 * V_125 ,
struct V_139 * V_140 ,
struct V_130 * V_141 ,
bool * V_142 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 -> V_143 ;
bool V_144 , V_145 , V_146 , V_147 ;
struct V_10 * V_11 = V_13 -> V_11 ;
T_3 V_148 ;
T_2 V_42 = V_11 -> V_5 . V_42 ;
V_148 = V_125 -> V_126 ;
V_144 = ! ! F_72 ( V_125 -> V_127 ) ;
V_145 = V_141 -> V_149 != V_150 &&
F_87 ( V_141 -> V_149 , V_13 -> V_151 ) ;
V_146 = V_145 && F_70 ( V_148 ) &&
F_88 ( V_148 ) &&
! ( V_141 -> V_152 &
( V_153 | V_154 | V_155 |
V_156 ) ) ;
if ( V_141 -> V_149 == V_150 ||
! F_87 ( V_141 -> V_149 , V_13 -> V_157 ) )
V_141 -> V_152 &= ~ V_156 ;
if ( ! V_141 -> V_158 ) {
F_89 ( V_159 ) ;
return false ;
}
if ( V_141 -> V_158 > ( V_13 -> V_25 - V_42 ) ) {
F_89 ( V_159 ) ;
return false ;
}
if ( V_141 -> V_160 )
return true ;
V_147 = V_145 && ! F_90 ( V_148 ) &&
! F_74 ( V_148 ) &&
! ( F_91 ( V_125 -> V_161 ) & V_162 ) &&
( V_141 -> V_152 & V_155 ) ;
if ( V_141 -> V_152 != 0 ) {
T_2 V_163 ;
if ( V_141 -> V_152 & V_154 ) {
V_140 -> V_164 |= V_165 ;
V_147 = false ;
}
if ( V_141 -> V_152 & V_166 )
return false ;
if ( ( V_141 -> V_152 & V_153 ) ||
( ! V_144 && ( V_141 -> V_152 & V_156 ) ) ) {
* V_142 = true ;
V_147 = false ;
}
V_163 = V_153 | V_155 |
V_156 ;
if ( V_11 -> V_78 && ( V_2 -> V_26 . V_75 & V_167 ) )
V_163 |= V_154 ;
if ( V_141 -> V_152 & ~ V_163 )
return false ;
}
if ( V_146 )
V_140 -> V_164 |= V_168 ;
else if ( V_144 && V_147 )
V_140 -> V_164 |= V_169 ;
return true ;
}
static int F_92 ( struct V_12 * V_13 ,
struct V_170 * V_59 ,
struct V_130 * V_141 ,
struct V_139 * V_140 )
{
struct V_171 * V_172 ;
enum V_173 V_174 ;
unsigned int V_53 = 0 ;
struct V_1 T_4 * V_2 = V_13 -> V_143 ;
V_174 = V_59 -> V_60 . V_175 -> V_174 ;
V_172 = V_59 -> V_176 -> V_177 [ V_174 ] ;
if ( V_141 -> V_178 & 0x80 ) {
V_140 -> V_164 |= V_179 ;
if ( V_141 -> V_180 & V_181 )
V_140 -> V_164 |= V_182 ;
if ( V_141 -> V_180 & V_183 )
V_140 -> V_164 |= V_184 ;
V_140 -> V_185 = V_141 -> V_178 & 0x7f ;
return 0 ;
}
for ( V_53 = 0 ; V_53 < V_172 -> V_186 ; V_53 ++ ) {
if ( V_172 -> V_187 [ V_53 ] . V_188 == V_141 -> V_178 ) {
V_140 -> V_185 = V_53 ;
return 0 ;
}
if ( V_172 -> V_187 [ V_53 ] . V_189 == V_141 -> V_178 ) {
V_140 -> V_164 |= V_190 ;
V_140 -> V_185 = V_53 ;
return 0 ;
}
}
F_26 ( V_13 , V_191 ,
L_13 ,
V_141 -> V_178 ) ;
F_89 ( V_192 ) ;
return - V_135 ;
}
static void F_93 ( struct V_12 * V_13 ,
struct V_170 * V_59 ,
struct V_124 * V_125 ,
struct V_130 * V_141 )
{
struct V_1 * V_2 = V_59 -> V_143 ;
struct V_10 * V_11 = V_13 -> V_11 ;
int V_193 ;
int V_194 = V_141 -> V_195 ;
if ( ! V_141 -> V_196 ||
( ( V_11 -> V_82 != V_83 ) &&
( V_11 -> V_82 != V_197 ) ) )
return;
if ( V_141 -> V_195 != V_198 && ! V_141 -> V_199 )
F_94 ( V_2 -> V_193 , V_141 -> V_195 ) ;
V_193 = V_2 -> V_193 ;
if ( F_95 ( V_193 != V_200 ) )
V_194 = F_96 ( V_193 , V_201 ) ;
if ( V_194 < 0 )
V_194 = 0 ;
V_11 -> V_202 . V_203 = V_194 ;
}
static int F_97 ( struct V_12 * V_13 ,
struct V_170 * V_59 ,
struct V_124 * V_125 ,
struct V_130 * V_141 ,
struct V_139 * V_204 ,
bool * V_142 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
if ( ! F_86 ( V_13 , V_125 , V_204 , V_141 , V_142 ) )
return - V_135 ;
if ( V_141 -> V_160 )
return 0 ;
F_93 ( V_13 , V_59 , V_125 , V_141 ) ;
if ( F_92 ( V_13 , V_59 , V_141 , V_204 ) )
return - V_135 ;
V_204 -> V_174 = V_59 -> V_60 . V_175 -> V_174 ;
V_204 -> V_205 = V_59 -> V_60 . V_175 -> V_206 ;
V_204 -> signal = V_11 -> V_207 + V_141 -> V_195 ;
V_204 -> V_29 = V_141 -> V_208 ;
V_204 -> V_164 |= V_209 ;
if ( V_141 -> V_199 )
V_204 -> V_164 |= V_210 ;
return 0 ;
}
static void F_98 ( struct V_12 * V_13 ,
struct V_16 * V_17 ,
struct V_130 * V_141 ,
struct V_139 * V_140 ,
bool V_142 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
struct V_124 * V_125 ;
int V_211 , V_212 , V_213 ;
T_2 V_214 ;
T_3 V_148 ;
V_125 = (struct V_124 * ) V_17 -> V_24 ;
V_211 = F_99 ( V_17 ) ;
V_148 = V_125 -> V_126 ;
V_212 = F_100 ( V_125 -> V_126 ) ;
V_213 = V_212 & 3 ;
if ( V_213 && V_17 -> V_114 >= V_212 + V_213 + V_215 ) {
memmove ( V_17 -> V_24 + V_213 , V_17 -> V_24 , V_212 ) ;
F_101 ( V_17 , V_213 ) ;
}
V_214 = V_141 -> V_149 ;
if ( ! ( V_214 == V_150 ) && ! V_142 &&
F_88 ( V_148 ) ) {
V_140 -> V_164 |= V_216 ;
} else if ( F_88 ( V_148 )
&& ! V_142 && V_17 -> V_114 >= V_211 + 4 ) {
V_214 = V_17 -> V_24 [ V_211 + 3 ] >> 6 ;
if ( F_87 ( V_214 , V_13 -> V_217 ) )
V_140 -> V_164 |= V_216 ;
}
if ( V_11 -> V_218 &&
( V_140 -> V_164 & V_216 ) &&
F_102 ( V_148 ) )
V_140 -> V_164 &= ~ V_216 ;
}
int F_61 ( struct V_1 * V_2 , int V_219 , bool V_220 )
{
struct V_8 * V_9 ;
struct V_16 * V_17 = NULL , * V_221 , * V_222 ;
struct V_139 * V_140 ;
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_170 * V_59 = V_2 -> V_59 ;
struct V_124 * V_125 ;
int V_223 ;
struct V_130 V_131 ;
enum V_34 V_35 ;
bool V_224 = ! ! ( V_11 -> V_5 . V_6 & V_65 ) ;
int V_225 ;
T_2 V_42 = V_11 -> V_5 . V_42 ;
T_5 V_226 = 0 ;
T_1 V_227 = 0 ;
unsigned long V_61 ;
if ( V_224 )
V_225 = V_50 ;
else
V_225 = V_70 ;
V_35 = V_220 ? V_49 : V_48 ;
V_226 = F_103 ( V_11 ) ;
V_227 = V_226 & 0xffffffff ;
do {
bool V_142 = false ;
memset ( & V_131 , 0 , sizeof( V_131 ) ) ;
if ( V_224 )
V_9 = F_80 ( V_2 , & V_131 , V_35 ) ;
else
V_9 = F_81 ( V_2 , & V_131 ) ;
if ( ! V_9 )
break;
V_17 = V_9 -> V_22 ;
if ( ! V_17 )
continue;
if ( V_2 -> V_26 . V_228 )
V_222 = V_2 -> V_26 . V_228 ;
else
V_222 = V_17 ;
V_125 = (struct V_124 * ) ( V_222 -> V_24 + V_42 ) ;
V_140 = F_104 ( V_222 ) ;
if ( F_105 ( V_125 -> V_126 ) ) {
F_89 ( V_229 ) ;
if ( ! F_106 ( V_13 -> V_230 ) &&
F_107 ( V_125 -> V_231 , V_13 -> V_230 ) )
V_131 . V_196 = true ;
else
V_131 . V_196 = false ;
}
else
V_131 . V_196 = false ;
if ( F_108 ( V_125 -> V_126 ) &&
! F_109 ( V_125 -> V_126 ) )
V_2 -> V_26 . V_232 ++ ;
F_110 ( V_2 , & V_131 ) ;
memset ( V_140 , 0 , sizeof( struct V_139 ) ) ;
V_140 -> V_233 = ( V_226 & ~ 0xffffffffULL ) | V_131 . V_234 ;
if ( V_131 . V_234 > V_227 &&
F_44 ( V_131 . V_234 - V_227 > 0x10000000 ) )
V_140 -> V_233 -= 0x100000000ULL ;
if ( V_131 . V_234 < V_227 &&
F_44 ( V_227 - V_131 . V_234 > 0x10000000 ) )
V_140 -> V_233 += 0x100000000ULL ;
V_223 = F_97 ( V_13 , V_59 , V_125 , & V_131 ,
V_140 , & V_142 ) ;
if ( V_223 )
goto V_235;
if ( V_131 . V_196 ) {
V_2 -> V_236 = 0 ;
F_111 ( V_2 , 3 ) ;
}
V_221 = F_42 ( V_13 , V_13 -> V_25 , V_237 ) ;
if ( ! V_221 ) {
F_89 ( V_238 ) ;
goto V_235;
}
F_33 ( V_2 -> V_43 , V_9 -> V_21 ,
V_13 -> V_25 ,
V_225 ) ;
F_112 ( V_17 , V_131 . V_158 + V_11 -> V_5 . V_42 ) ;
if ( V_11 -> V_5 . V_42 )
F_101 ( V_17 , V_11 -> V_5 . V_42 ) ;
if ( ! V_131 . V_160 )
F_98 ( V_13 , V_222 , & V_131 ,
V_140 , V_142 ) ;
V_9 -> V_22 = V_221 ;
V_9 -> V_21 = F_43 ( V_2 -> V_43 , V_221 -> V_24 ,
V_13 -> V_25 ,
V_225 ) ;
if ( F_44 ( F_45 ( V_2 -> V_43 ,
V_9 -> V_21 ) ) ) {
F_34 ( V_221 ) ;
V_9 -> V_22 = NULL ;
V_9 -> V_21 = 0 ;
F_46 ( V_13 , L_14 ) ;
F_113 ( V_59 , V_17 ) ;
break;
}
if ( V_131 . V_160 ) {
F_89 ( V_239 ) ;
if ( V_2 -> V_26 . V_228 ) {
F_34 ( V_2 -> V_26 . V_228 ) ;
F_34 ( V_17 ) ;
F_89 ( V_240 ) ;
V_17 = NULL ;
}
V_2 -> V_26 . V_228 = V_17 ;
goto V_241;
}
if ( V_2 -> V_26 . V_228 ) {
int V_242 = V_17 -> V_114 - F_114 ( V_222 ) ;
if ( F_115 ( V_222 , 0 , V_242 , V_237 ) < 0 ) {
F_55 ( V_17 ) ;
F_89 ( V_238 ) ;
goto V_235;
}
V_2 -> V_26 . V_228 = NULL ;
F_116 ( V_17 , F_112 ( V_222 , V_17 -> V_114 ) ,
V_17 -> V_114 ) ;
F_34 ( V_17 ) ;
V_17 = V_222 ;
}
if ( V_11 -> V_5 . V_6 & V_243 ) {
if ( V_2 -> V_26 . V_30 != V_131 . V_208 ) {
if ( ++ V_2 -> V_26 . V_31 >= 3 )
F_8 ( V_2 , V_131 . V_208 ) ;
} else {
V_2 -> V_26 . V_31 = 0 ;
}
}
if ( V_140 -> V_164 & V_168 )
F_117 ( V_17 , V_17 -> V_114 - 8 ) ;
F_118 ( & V_2 -> V_244 , V_61 ) ;
if ( ( V_2 -> V_118 & ( V_119 |
V_122 |
V_128 ) ) ||
F_1 ( V_2 ) )
F_69 ( V_2 , V_17 , V_131 . V_196 ) ;
F_119 ( & V_2 -> V_244 , V_61 ) ;
if ( ( V_11 -> V_5 . V_6 & V_243 ) && V_2 -> V_245 == 3 )
F_120 ( V_2 , & V_131 ) ;
F_113 ( V_59 , V_17 ) ;
V_235:
if ( V_2 -> V_26 . V_228 ) {
F_34 ( V_2 -> V_26 . V_228 ) ;
V_2 -> V_26 . V_228 = NULL ;
}
V_241:
F_30 ( & V_9 -> V_41 , & V_2 -> V_26 . V_40 ) ;
if ( V_219 )
continue;
if ( V_224 ) {
F_16 ( V_2 , V_35 ) ;
} else {
F_2 ( V_2 , V_9 ) ;
F_48 ( V_11 ) ;
}
} while ( 1 );
if ( ! ( V_11 -> V_246 & V_247 ) ) {
V_11 -> V_246 |= ( V_247 | V_248 ) ;
F_121 ( V_11 ) ;
}
return 0 ;
}
