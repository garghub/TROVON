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
}
static void F_35 ( struct V_36 * V_37 , int V_45 )
{
F_36 ( & V_37 -> V_38 ) ;
V_37 -> V_39 = V_45 ;
}
static int F_37 ( struct V_1 * V_2 , int V_51 )
{
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_16 * V_17 ;
struct V_8 * V_9 ;
int error = 0 , V_52 ;
T_1 V_45 ;
F_38 ( V_11 , V_13 -> V_25 -
V_11 -> V_5 . V_42 ) ;
F_35 ( & V_2 -> V_26 . V_37 [ V_48 ] ,
V_11 -> V_5 . V_53 ) ;
F_35 ( & V_2 -> V_26 . V_37 [ V_49 ] ,
V_11 -> V_5 . V_54 ) ;
V_45 = sizeof( struct V_8 ) * V_51 ;
V_9 = F_39 ( V_2 -> V_43 , V_45 , V_55 ) ;
if ( ! V_9 )
return - V_56 ;
F_40 ( & V_2 -> V_26 . V_40 ) ;
for ( V_52 = 0 ; V_52 < V_51 ; V_52 ++ , V_9 ++ ) {
V_17 = F_41 ( V_13 , V_13 -> V_25 , V_55 ) ;
if ( ! V_17 ) {
error = - V_56 ;
goto V_57;
}
memset ( V_17 -> V_24 , 0 , V_13 -> V_25 ) ;
V_9 -> V_22 = V_17 ;
V_9 -> V_21 = F_42 ( V_2 -> V_43 , V_17 -> V_24 ,
V_13 -> V_25 ,
V_50 ) ;
if ( F_43 ( F_44 ( V_2 -> V_43 ,
V_9 -> V_21 ) ) ) {
F_34 ( V_17 ) ;
V_9 -> V_22 = NULL ;
V_9 -> V_21 = 0 ;
F_45 ( V_13 ,
L_2 ) ;
error = - V_56 ;
goto V_57;
}
F_30 ( & V_9 -> V_41 , & V_2 -> V_26 . V_40 ) ;
}
return 0 ;
V_57:
F_31 ( V_2 ) ;
return error ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_47 ( V_2 -> V_4 ) ;
F_24 ( V_2 , V_49 ,
V_2 -> V_26 . V_37 [ V_49 ] . V_39 ) ;
F_24 ( V_2 , V_48 ,
V_2 -> V_26 . V_37 [ V_48 ] . V_39 ) ;
F_10 ( V_2 ) ;
F_48 ( V_2 -> V_4 , ! ! ( V_2 -> V_58 -> V_59 . V_60 & V_61 ) ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_28 ( V_2 , V_49 ) ;
F_28 ( V_2 , V_48 ) ;
}
int F_50 ( struct V_1 * V_2 , int V_51 )
{
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
struct V_16 * V_17 ;
struct V_8 * V_9 ;
int error = 0 ;
F_51 ( & V_2 -> V_62 ) ;
V_13 -> V_25 = V_63 / 2 +
V_2 -> V_4 -> V_5 . V_42 ;
if ( V_2 -> V_4 -> V_5 . V_6 & V_64 ) {
return F_37 ( V_2 , V_51 ) ;
} else {
F_26 ( V_13 , V_65 , L_3 ,
V_13 -> V_66 , V_13 -> V_25 ) ;
error = F_52 ( V_2 , & V_2 -> V_26 . V_67 , & V_2 -> V_26 . V_40 ,
L_4 , V_51 , 1 , 0 ) ;
if ( error != 0 ) {
F_45 ( V_13 ,
L_5 ,
error ) ;
goto V_68;
}
F_32 (bf, &sc->rx.rxbuf, list) {
V_17 = F_41 ( V_13 , V_13 -> V_25 ,
V_55 ) ;
if ( V_17 == NULL ) {
error = - V_56 ;
goto V_68;
}
V_9 -> V_22 = V_17 ;
V_9 -> V_21 = F_42 ( V_2 -> V_43 , V_17 -> V_24 ,
V_13 -> V_25 ,
V_69 ) ;
if ( F_43 ( F_44 ( V_2 -> V_43 ,
V_9 -> V_21 ) ) ) {
F_34 ( V_17 ) ;
V_9 -> V_22 = NULL ;
V_9 -> V_21 = 0 ;
F_45 ( V_13 ,
L_2 ) ;
error = - V_56 ;
goto V_68;
}
}
V_2 -> V_26 . V_27 = NULL ;
}
V_68:
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
if ( V_2 -> V_4 -> V_5 . V_6 & V_64 ) {
F_31 ( V_2 ) ;
return;
} else {
F_32 (bf, &sc->rx.rxbuf, list) {
V_17 = V_9 -> V_22 ;
if ( V_17 ) {
F_33 ( V_2 -> V_43 , V_9 -> V_21 ,
V_13 -> V_25 ,
V_69 ) ;
F_54 ( V_17 ) ;
V_9 -> V_21 = 0 ;
V_9 -> V_22 = NULL ;
}
}
}
}
T_1 F_11 ( struct V_1 * V_2 )
{
T_1 V_32 ;
V_32 = V_70 | V_71
| V_72 ;
if ( V_2 -> V_26 . V_73 & V_74 )
V_32 |= V_75 ;
if ( V_2 -> V_4 -> V_76 )
V_32 |= V_77 ;
if ( V_2 -> V_26 . V_73 & V_78 )
V_32 |= V_79 ;
if ( ( V_2 -> V_4 -> V_80 == V_81 ) &&
( V_2 -> V_82 <= 1 ) &&
! ( V_2 -> V_26 . V_73 & V_83 ) )
V_32 |= V_84 ;
else
V_32 |= V_85 ;
if ( ( V_2 -> V_4 -> V_80 == V_86 ) ||
( V_2 -> V_26 . V_73 & V_87 ) )
V_32 |= V_88 ;
if ( F_55 ( & V_2 -> V_58 -> V_59 ) )
V_32 |= V_89 ;
if ( V_2 -> V_82 > 1 || ( V_2 -> V_26 . V_73 & V_90 ) ) {
if ( V_2 -> V_4 -> V_91 . V_92 <= V_93 )
V_32 |= V_77 ;
V_32 |= V_94 ;
}
if ( F_56 ( V_2 -> V_4 ) )
V_32 |= V_95 ;
return V_32 ;
}
int F_57 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_8 * V_9 , * V_46 ;
if ( V_11 -> V_5 . V_6 & V_64 ) {
F_46 ( V_2 ) ;
return 0 ;
}
if ( F_25 ( & V_2 -> V_26 . V_40 ) )
goto V_96;
V_2 -> V_26 . V_27 = NULL ;
F_27 (bf, tbf, &sc->rx.rxbuf, list) {
F_2 ( V_2 , V_9 ) ;
}
if ( F_25 ( & V_2 -> V_26 . V_40 ) )
goto V_96;
V_9 = F_18 ( & V_2 -> V_26 . V_40 , struct V_8 , V_41 ) ;
F_7 ( V_11 , V_9 -> V_28 ) ;
F_47 ( V_11 ) ;
V_96:
F_10 ( V_2 ) ;
F_48 ( V_11 , ! ! ( V_2 -> V_58 -> V_59 . V_60 & V_61 ) ) ;
return 0 ;
}
static void F_58 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 -> V_5 . V_6 & V_64 )
F_59 ( V_2 , 1 , true ) ;
F_59 ( V_2 , 1 , false ) ;
}
bool F_60 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
bool V_97 , V_98 = false ;
F_61 ( V_11 ) ;
F_12 ( V_11 , 0 ) ;
V_97 = F_62 ( V_11 , & V_98 ) ;
F_58 ( V_2 ) ;
if ( V_2 -> V_4 -> V_5 . V_6 & V_64 )
F_49 ( V_2 ) ;
else
V_2 -> V_26 . V_27 = NULL ;
if ( ! ( V_11 -> V_99 & V_100 ) &&
F_43 ( ! V_97 ) ) {
F_45 ( F_3 ( V_2 -> V_4 ) ,
L_6
L_7 ) ;
F_63 ( ! V_97 ) ;
}
return V_97 && ! V_98 ;
}
static bool F_64 ( struct V_16 * V_17 )
{
struct V_101 * V_102 ;
T_2 * V_103 , * V_104 , V_105 , V_106 ;
struct V_107 * V_108 ;
V_102 = (struct V_101 * ) V_17 -> V_24 ;
V_103 = V_102 -> V_109 . V_110 . V_111 ;
V_104 = V_17 -> V_24 + V_17 -> V_112 ;
while ( V_103 + 2 < V_104 ) {
V_105 = * V_103 ++ ;
V_106 = * V_103 ++ ;
if ( V_103 + V_106 > V_104 )
break;
if ( V_105 == V_113 ) {
if ( V_106 < sizeof( * V_108 ) )
break;
V_108 = (struct V_107 * ) V_103 ;
if ( V_108 -> V_114 != 0 )
break;
return V_108 -> V_115 & 0x01 ;
}
V_103 += V_106 ;
}
return false ;
}
static void F_65 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
if ( V_17 -> V_112 < 24 + 8 + 2 + 2 )
return;
V_2 -> V_116 &= ~ V_117 ;
if ( V_2 -> V_116 & V_118 ) {
V_2 -> V_116 &= ~ V_118 ;
F_26 ( V_13 , V_119 ,
L_8 ) ;
F_66 ( V_2 ) ;
}
if ( F_64 ( V_17 ) ) {
F_26 ( V_13 , V_119 ,
L_9 ) ;
V_2 -> V_116 |= V_120 | V_117 ;
return;
}
if ( V_2 -> V_116 & V_120 ) {
V_2 -> V_116 &= ~ V_120 ;
F_26 ( V_13 , V_119 , L_10 ) ;
}
}
static void F_67 ( struct V_1 * V_2 , struct V_16 * V_17 , bool V_121 )
{
struct V_122 * V_123 ;
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
V_123 = (struct V_122 * ) V_17 -> V_24 ;
if ( ( ( V_2 -> V_116 & V_117 ) || F_1 ( V_2 ) )
&& V_121 ) {
F_65 ( V_2 , V_17 ) ;
} else if ( ( V_2 -> V_116 & V_120 ) &&
( F_68 ( V_123 -> V_124 ) ||
F_69 ( V_123 -> V_124 ) ) &&
F_70 ( V_123 -> V_125 ) &&
! F_71 ( V_123 -> V_124 ) ) {
V_2 -> V_116 &= ~ ( V_120 | V_117 ) ;
F_26 ( V_13 , V_119 ,
L_11 ) ;
} else if ( ( V_2 -> V_116 & V_126 ) &&
! F_70 ( V_123 -> V_125 ) &&
! F_72 ( V_123 -> V_124 ) ) {
V_2 -> V_116 &= ~ V_126 ;
F_26 ( V_13 , V_119 ,
L_12 ,
V_2 -> V_116 & ( V_117 |
V_120 |
V_126 |
V_127 ) ) ;
}
}
static bool F_73 ( struct V_1 * V_2 ,
enum V_34 V_35 ,
struct V_128 * V_129 ,
struct V_8 * * V_130 )
{
struct V_36 * V_37 = & V_2 -> V_26 . V_37 [ V_35 ] ;
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_16 * V_17 ;
struct V_8 * V_9 ;
int V_131 ;
V_17 = F_74 ( & V_37 -> V_38 ) ;
if ( ! V_17 )
return false ;
V_9 = F_21 ( V_17 ) ;
F_5 ( ! V_9 ) ;
F_75 ( V_2 -> V_43 , V_9 -> V_21 ,
V_13 -> V_25 , V_69 ) ;
V_131 = F_76 ( V_11 , V_129 , V_17 -> V_24 ) ;
if ( V_131 == - V_132 ) {
F_20 ( V_2 -> V_43 , V_9 -> V_21 ,
V_13 -> V_25 , V_69 ) ;
return false ;
}
F_77 ( V_17 , & V_37 -> V_38 ) ;
if ( V_131 == - V_133 ) {
F_30 ( & V_9 -> V_41 , & V_2 -> V_26 . V_40 ) ;
F_16 ( V_2 , V_35 ) ;
V_17 = F_74 ( & V_37 -> V_38 ) ;
if ( V_17 ) {
V_9 = F_21 ( V_17 ) ;
F_5 ( ! V_9 ) ;
F_77 ( V_17 , & V_37 -> V_38 ) ;
F_30 ( & V_9 -> V_41 , & V_2 -> V_26 . V_40 ) ;
F_16 ( V_2 , V_35 ) ;
}
V_9 = NULL ;
}
* V_130 = V_9 ;
return true ;
}
static struct V_8 * F_78 ( struct V_1 * V_2 ,
struct V_128 * V_129 ,
enum V_34 V_35 )
{
struct V_8 * V_9 = NULL ;
while ( F_73 ( V_2 , V_35 , V_129 , & V_9 ) ) {
if ( ! V_9 )
continue;
return V_9 ;
}
return NULL ;
}
static struct V_8 * F_79 ( struct V_1 * V_2 ,
struct V_128 * V_129 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_14 * V_15 ;
struct V_8 * V_9 ;
int V_131 ;
if ( F_25 ( & V_2 -> V_26 . V_40 ) ) {
V_2 -> V_26 . V_27 = NULL ;
return NULL ;
}
V_9 = F_18 ( & V_2 -> V_26 . V_40 , struct V_8 , V_41 ) ;
V_15 = V_9 -> V_18 ;
V_131 = F_80 ( V_11 , V_15 , V_129 ) ;
if ( V_131 == - V_132 ) {
struct V_128 V_134 ;
struct V_8 * V_46 ;
struct V_14 * V_135 ;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
if ( F_81 ( & V_9 -> V_41 , & V_2 -> V_26 . V_40 ) ) {
V_2 -> V_26 . V_27 = NULL ;
return NULL ;
}
V_46 = F_82 ( V_9 -> V_41 . V_136 , struct V_8 , V_41 ) ;
V_135 = V_46 -> V_18 ;
V_131 = F_80 ( V_11 , V_135 , & V_134 ) ;
if ( V_131 == - V_132 )
return NULL ;
}
F_83 ( & V_9 -> V_41 ) ;
if ( ! V_9 -> V_22 )
return V_9 ;
F_75 ( V_2 -> V_43 , V_9 -> V_21 ,
V_13 -> V_25 ,
V_69 ) ;
return V_9 ;
}
static bool F_84 ( struct V_12 * V_13 ,
struct V_122 * V_123 ,
struct V_137 * V_138 ,
struct V_128 * V_139 ,
bool * V_140 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 -> V_141 ;
bool V_142 , V_143 , V_144 , V_145 ;
struct V_10 * V_11 = V_13 -> V_11 ;
T_3 V_146 ;
T_2 V_42 = V_11 -> V_5 . V_42 ;
V_146 = V_123 -> V_124 ;
V_142 = ! ! F_70 ( V_123 -> V_125 ) ;
V_143 = V_139 -> V_147 != V_148 &&
F_85 ( V_139 -> V_147 , V_13 -> V_149 ) ;
V_144 = V_143 && F_68 ( V_146 ) &&
F_86 ( V_146 ) &&
! ( V_139 -> V_150 &
( V_151 | V_152 | V_153 |
V_154 ) ) ;
if ( V_139 -> V_147 == V_148 ||
! F_85 ( V_139 -> V_147 , V_13 -> V_155 ) )
V_139 -> V_150 &= ~ V_154 ;
if ( ! V_139 -> V_156 ) {
F_87 ( V_157 ) ;
return false ;
}
if ( V_139 -> V_156 > ( V_13 -> V_25 - V_42 ) ) {
F_87 ( V_157 ) ;
return false ;
}
if ( V_139 -> V_158 )
return true ;
V_145 = V_143 && ! F_88 ( V_146 ) &&
! F_72 ( V_146 ) &&
! ( F_89 ( V_123 -> V_159 ) & V_160 ) &&
( V_139 -> V_150 & V_153 ) ;
if ( V_139 -> V_150 != 0 ) {
T_2 V_161 ;
if ( V_139 -> V_150 & V_152 ) {
V_138 -> V_162 |= V_163 ;
V_145 = false ;
}
if ( V_139 -> V_150 & V_164 )
return false ;
if ( ( V_139 -> V_150 & V_151 ) ||
( ! V_142 && ( V_139 -> V_150 & V_154 ) ) ) {
* V_140 = true ;
V_145 = false ;
}
V_161 = V_151 | V_153 |
V_154 ;
if ( V_11 -> V_76 && ( V_2 -> V_26 . V_73 & V_165 ) )
V_161 |= V_152 ;
if ( V_139 -> V_150 & ~ V_161 )
return false ;
}
if ( V_144 )
V_138 -> V_162 |= V_166 ;
else if ( V_142 && V_145 )
V_138 -> V_162 |= V_167 ;
return true ;
}
static int F_90 ( struct V_12 * V_13 ,
struct V_168 * V_58 ,
struct V_128 * V_139 ,
struct V_137 * V_138 )
{
struct V_169 * V_170 ;
enum V_171 V_172 ;
unsigned int V_52 = 0 ;
struct V_1 T_4 * V_2 = V_13 -> V_141 ;
V_172 = V_58 -> V_59 . V_173 -> V_172 ;
V_170 = V_58 -> V_174 -> V_175 [ V_172 ] ;
if ( V_139 -> V_176 & 0x80 ) {
V_138 -> V_162 |= V_177 ;
if ( V_139 -> V_178 & V_179 )
V_138 -> V_162 |= V_180 ;
if ( V_139 -> V_178 & V_181 )
V_138 -> V_162 |= V_182 ;
V_138 -> V_183 = V_139 -> V_176 & 0x7f ;
return 0 ;
}
for ( V_52 = 0 ; V_52 < V_170 -> V_184 ; V_52 ++ ) {
if ( V_170 -> V_185 [ V_52 ] . V_186 == V_139 -> V_176 ) {
V_138 -> V_183 = V_52 ;
return 0 ;
}
if ( V_170 -> V_185 [ V_52 ] . V_187 == V_139 -> V_176 ) {
V_138 -> V_162 |= V_188 ;
V_138 -> V_183 = V_52 ;
return 0 ;
}
}
F_26 ( V_13 , V_189 ,
L_13 ,
V_139 -> V_176 ) ;
F_87 ( V_190 ) ;
return - V_133 ;
}
static void F_91 ( struct V_12 * V_13 ,
struct V_168 * V_58 ,
struct V_122 * V_123 ,
struct V_128 * V_139 )
{
struct V_1 * V_2 = V_58 -> V_141 ;
struct V_10 * V_11 = V_13 -> V_11 ;
int V_191 ;
int V_192 = V_139 -> V_193 ;
if ( ! V_139 -> V_194 ||
( ( V_11 -> V_80 != V_81 ) &&
( V_11 -> V_80 != V_195 ) ) )
return;
if ( V_139 -> V_193 != V_196 && ! V_139 -> V_197 )
F_92 ( V_2 -> V_191 , V_139 -> V_193 ) ;
V_191 = V_2 -> V_191 ;
if ( F_93 ( V_191 != V_198 ) )
V_192 = F_94 ( V_191 , V_199 ) ;
if ( V_192 < 0 )
V_192 = 0 ;
V_11 -> V_200 . V_201 = V_192 ;
}
static int F_95 ( struct V_12 * V_13 ,
struct V_168 * V_58 ,
struct V_122 * V_123 ,
struct V_128 * V_139 ,
struct V_137 * V_202 ,
bool * V_140 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
if ( ! F_84 ( V_13 , V_123 , V_202 , V_139 , V_140 ) )
return - V_133 ;
if ( V_139 -> V_158 )
return 0 ;
F_91 ( V_13 , V_58 , V_123 , V_139 ) ;
if ( F_90 ( V_13 , V_58 , V_139 , V_202 ) )
return - V_133 ;
V_202 -> V_172 = V_58 -> V_59 . V_173 -> V_172 ;
V_202 -> V_203 = V_58 -> V_59 . V_173 -> V_204 ;
V_202 -> signal = V_11 -> V_205 + V_139 -> V_193 ;
V_202 -> V_29 = V_139 -> V_206 ;
V_202 -> V_162 |= V_207 ;
if ( V_139 -> V_197 )
V_202 -> V_162 |= V_208 ;
return 0 ;
}
static void F_96 ( struct V_12 * V_13 ,
struct V_16 * V_17 ,
struct V_128 * V_139 ,
struct V_137 * V_138 ,
bool V_140 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
struct V_122 * V_123 ;
int V_209 , V_210 , V_211 ;
T_2 V_212 ;
T_3 V_146 ;
V_123 = (struct V_122 * ) V_17 -> V_24 ;
V_209 = F_97 ( V_17 ) ;
V_146 = V_123 -> V_124 ;
V_210 = F_98 ( V_123 -> V_124 ) ;
V_211 = V_210 & 3 ;
if ( V_211 && V_17 -> V_112 >= V_210 + V_211 + V_213 ) {
memmove ( V_17 -> V_24 + V_211 , V_17 -> V_24 , V_210 ) ;
F_99 ( V_17 , V_211 ) ;
}
V_212 = V_139 -> V_147 ;
if ( ! ( V_212 == V_148 ) && ! V_140 &&
F_86 ( V_146 ) ) {
V_138 -> V_162 |= V_214 ;
} else if ( F_86 ( V_146 )
&& ! V_140 && V_17 -> V_112 >= V_209 + 4 ) {
V_212 = V_17 -> V_24 [ V_209 + 3 ] >> 6 ;
if ( F_85 ( V_212 , V_13 -> V_215 ) )
V_138 -> V_162 |= V_214 ;
}
if ( V_11 -> V_216 &&
( V_138 -> V_162 & V_214 ) &&
F_100 ( V_146 ) )
V_138 -> V_162 &= ~ V_214 ;
}
static T_5 F_101 ( T_2 V_217 )
{
if ( V_217 == 128 )
V_217 = 0 ;
return ( T_5 ) V_217 ;
}
static int F_102 ( struct V_1 * V_2 , struct V_122 * V_123 ,
struct V_128 * V_129 , T_6 V_218 )
{
#ifdef F_103
struct V_10 * V_11 = V_2 -> V_4 ;
T_2 V_219 [ V_220 ] ;
T_2 * V_221 = ( T_2 * ) V_123 ;
struct V_222 V_223 ;
struct V_224 * V_225 ;
struct V_226 * V_227 ;
int V_112 = V_129 -> V_156 ;
int V_228 ;
T_7 V_229 , V_230 ;
if ( V_129 -> V_231 != V_232 &&
V_129 -> V_231 != V_233 &&
V_129 -> V_231 != V_234 )
return 0 ;
V_225 = ( (struct V_224 * ) & V_221 [ V_112 ] ) - 1 ;
if ( ! ( V_225 -> V_235 & V_236 ) )
return 0 ;
if ( ( V_112 > V_237 + 2 ) ||
( V_112 < V_237 - 1 ) )
return 1 ;
V_223 . V_238 . type = V_239 ;
V_229 = sizeof( V_223 ) - sizeof( V_223 . V_238 ) ;
V_223 . V_238 . V_229 = F_104 ( V_229 ) ;
V_223 . V_203 = F_104 ( V_11 -> V_240 -> V_241 -> V_204 ) ;
V_223 . V_192 = F_101 ( V_129 -> V_242 ) ;
V_223 . V_205 = V_11 -> V_205 ;
switch ( V_112 - V_237 ) {
case 0 :
memcpy ( V_219 , V_221 , V_220 ) ;
break;
case - 1 :
memcpy ( & V_219 [ 1 ] , V_221 , V_220 - 1 ) ;
V_219 [ 0 ] = V_221 [ 0 ] ;
break;
case 2 :
memcpy ( V_219 , V_221 , 30 ) ;
V_219 [ 30 ] = V_221 [ 31 ] ;
memcpy ( & V_219 [ 31 ] , & V_221 [ 33 ] , V_220 - 31 ) ;
break;
case 1 :
V_219 [ 0 ] = V_221 [ 0 ] ;
memcpy ( & V_219 [ 0 ] , V_221 , 30 ) ;
V_219 [ 31 ] = V_221 [ 31 ] ;
memcpy ( & V_219 [ 32 ] , & V_221 [ 33 ] , V_220 - 32 ) ;
break;
default:
return 1 ;
}
V_228 = V_220 / 2 ;
V_219 [ V_228 ] = ( V_219 [ V_228 + 1 ] + V_219 [ V_228 - 1 ] ) / 2 ;
V_227 = ( (struct V_226 * ) V_225 ) - 1 ;
memcpy ( V_223 . V_24 , V_219 , V_220 ) ;
V_223 . V_243 = V_227 -> V_243 & 0xf ;
V_230 = F_105 ( V_227 -> V_244 ) ;
V_223 . V_230 = F_104 ( V_230 ) ;
V_223 . V_245 = F_106 ( V_227 -> V_244 ) ;
V_223 . V_246 = F_107 ( V_227 -> V_244 ) ;
V_223 . V_218 = F_108 ( V_218 ) ;
F_109 ( V_2 , & V_223 . V_238 ) ;
return 1 ;
#else
return 0 ;
#endif
}
static void F_110 ( struct V_1 * V_2 ,
struct V_128 * V_129 , struct V_137 * V_138 )
{
if ( V_129 -> V_247 ) {
V_138 -> V_162 |= V_248 | V_249 ;
V_138 -> V_250 = V_2 -> V_26 . V_251 ;
if ( ! V_129 -> V_197 ) {
V_138 -> V_162 |= V_252 ;
V_2 -> V_26 . V_251 ++ ;
}
if ( V_129 -> V_178 & V_253 )
V_138 -> V_162 |= V_254 ;
}
}
int F_59 ( struct V_1 * V_2 , int V_255 , bool V_256 )
{
struct V_8 * V_9 ;
struct V_16 * V_17 = NULL , * V_257 , * V_258 ;
struct V_137 * V_138 ;
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_168 * V_58 = V_2 -> V_58 ;
struct V_122 * V_123 ;
int V_259 ;
struct V_128 V_129 ;
enum V_34 V_35 ;
bool V_260 = ! ! ( V_11 -> V_5 . V_6 & V_64 ) ;
int V_261 ;
T_2 V_42 = V_11 -> V_5 . V_42 ;
T_6 V_218 = 0 ;
T_1 V_262 = 0 ;
unsigned long V_60 ;
if ( V_260 )
V_261 = V_50 ;
else
V_261 = V_69 ;
V_35 = V_256 ? V_49 : V_48 ;
V_218 = F_111 ( V_11 ) ;
V_262 = V_218 & 0xffffffff ;
do {
bool V_140 = false ;
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
if ( V_260 )
V_9 = F_78 ( V_2 , & V_129 , V_35 ) ;
else
V_9 = F_79 ( V_2 , & V_129 ) ;
if ( ! V_9 )
break;
V_17 = V_9 -> V_22 ;
if ( ! V_17 )
continue;
if ( V_2 -> V_26 . V_263 )
V_258 = V_2 -> V_26 . V_263 ;
else
V_258 = V_17 ;
V_123 = (struct V_122 * ) ( V_258 -> V_24 + V_42 ) ;
V_138 = F_112 ( V_258 ) ;
if ( F_113 ( V_123 -> V_124 ) ) {
F_87 ( V_264 ) ;
if ( ! F_114 ( V_13 -> V_265 ) &&
F_115 ( V_123 -> V_266 , V_13 -> V_265 ) )
V_129 . V_194 = true ;
else
V_129 . V_194 = false ;
}
else
V_129 . V_194 = false ;
if ( F_116 ( V_123 -> V_124 ) &&
! F_117 ( V_123 -> V_124 ) )
V_2 -> V_26 . V_267 ++ ;
F_118 ( V_2 , & V_129 ) ;
memset ( V_138 , 0 , sizeof( struct V_137 ) ) ;
V_138 -> V_268 = ( V_218 & ~ 0xffffffffULL ) | V_129 . V_269 ;
if ( V_129 . V_269 > V_262 &&
F_43 ( V_129 . V_269 - V_262 > 0x10000000 ) )
V_138 -> V_268 -= 0x100000000ULL ;
if ( V_129 . V_269 < V_262 &&
F_43 ( V_262 - V_129 . V_269 > 0x10000000 ) )
V_138 -> V_268 += 0x100000000ULL ;
if ( V_129 . V_150 & V_164 ) {
if ( F_102 ( V_2 , V_123 , & V_129 , V_138 -> V_268 ) ) {
F_87 ( V_270 ) ;
goto V_271;
}
}
V_259 = F_95 ( V_13 , V_58 , V_123 , & V_129 ,
V_138 , & V_140 ) ;
if ( V_259 )
goto V_271;
if ( V_129 . V_194 ) {
V_2 -> V_272 = 0 ;
F_119 ( V_2 , 3 ) ;
}
V_257 = F_41 ( V_13 , V_13 -> V_25 , V_273 ) ;
if ( ! V_257 ) {
F_87 ( V_274 ) ;
goto V_271;
}
F_33 ( V_2 -> V_43 , V_9 -> V_21 ,
V_13 -> V_25 ,
V_261 ) ;
F_120 ( V_17 , V_129 . V_156 + V_11 -> V_5 . V_42 ) ;
if ( V_11 -> V_5 . V_42 )
F_99 ( V_17 , V_11 -> V_5 . V_42 ) ;
if ( ! V_129 . V_158 )
F_96 ( V_13 , V_258 , & V_129 ,
V_138 , V_140 ) ;
V_9 -> V_22 = V_257 ;
V_9 -> V_21 = F_42 ( V_2 -> V_43 , V_257 -> V_24 ,
V_13 -> V_25 ,
V_261 ) ;
if ( F_43 ( F_44 ( V_2 -> V_43 ,
V_9 -> V_21 ) ) ) {
F_34 ( V_257 ) ;
V_9 -> V_22 = NULL ;
V_9 -> V_21 = 0 ;
F_45 ( V_13 , L_14 ) ;
F_121 ( V_58 , V_17 ) ;
break;
}
if ( V_129 . V_158 ) {
F_87 ( V_275 ) ;
if ( V_2 -> V_26 . V_263 ) {
F_34 ( V_2 -> V_26 . V_263 ) ;
F_34 ( V_17 ) ;
F_87 ( V_276 ) ;
V_17 = NULL ;
}
V_2 -> V_26 . V_263 = V_17 ;
goto V_277;
}
if ( V_2 -> V_26 . V_263 ) {
int V_278 = V_17 -> V_112 - F_122 ( V_258 ) ;
if ( F_123 ( V_258 , 0 , V_278 , V_273 ) < 0 ) {
F_54 ( V_17 ) ;
F_87 ( V_274 ) ;
goto V_271;
}
V_2 -> V_26 . V_263 = NULL ;
F_124 ( V_17 , F_120 ( V_258 , V_17 -> V_112 ) ,
V_17 -> V_112 ) ;
F_34 ( V_17 ) ;
V_17 = V_258 ;
}
if ( V_11 -> V_5 . V_6 & V_279 ) {
if ( V_2 -> V_26 . V_30 != V_129 . V_206 ) {
if ( ++ V_2 -> V_26 . V_31 >= 3 )
F_8 ( V_2 , V_129 . V_206 ) ;
} else {
V_2 -> V_26 . V_31 = 0 ;
}
}
if ( V_138 -> V_162 & V_166 )
F_125 ( V_17 , V_17 -> V_112 - 8 ) ;
F_126 ( & V_2 -> V_280 , V_60 ) ;
if ( ( V_2 -> V_116 & ( V_117 |
V_120 |
V_126 ) ) ||
F_1 ( V_2 ) )
F_67 ( V_2 , V_17 , V_129 . V_194 ) ;
F_127 ( & V_2 -> V_280 , V_60 ) ;
if ( ( V_11 -> V_5 . V_6 & V_279 ) && V_2 -> V_281 == 3 )
F_128 ( V_2 , & V_129 ) ;
F_110 ( V_2 , & V_129 , V_138 ) ;
F_121 ( V_58 , V_17 ) ;
V_271:
if ( V_2 -> V_26 . V_263 ) {
F_34 ( V_2 -> V_26 . V_263 ) ;
V_2 -> V_26 . V_263 = NULL ;
}
V_277:
F_30 ( & V_9 -> V_41 , & V_2 -> V_26 . V_40 ) ;
if ( V_255 )
continue;
if ( V_260 ) {
F_16 ( V_2 , V_35 ) ;
} else {
F_2 ( V_2 , V_9 ) ;
F_47 ( V_11 ) ;
}
} while ( 1 );
if ( ! ( V_11 -> V_282 & V_283 ) ) {
V_11 -> V_282 |= ( V_283 | V_284 ) ;
F_129 ( V_11 ) ;
}
return 0 ;
}
