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
F_48 ( & V_2 -> V_26 . V_59 ) ;
F_49 ( V_2 -> V_4 ) ;
F_24 ( V_2 , V_49 ,
V_2 -> V_26 . V_37 [ V_49 ] . V_39 ) ;
F_24 ( V_2 , V_48 ,
V_2 -> V_26 . V_37 [ V_48 ] . V_39 ) ;
F_10 ( V_2 ) ;
F_50 ( V_2 -> V_4 , ! ! ( V_2 -> V_60 -> V_61 . V_62 & V_63 ) ) ;
F_51 ( & V_2 -> V_26 . V_59 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_28 ( V_2 , V_49 ) ;
F_28 ( V_2 , V_48 ) ;
}
int F_53 ( struct V_1 * V_2 , int V_52 )
{
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
struct V_16 * V_17 ;
struct V_8 * V_9 ;
int error = 0 ;
F_54 ( & V_2 -> V_64 ) ;
F_54 ( & V_2 -> V_26 . V_59 ) ;
F_55 ( V_65 , & V_2 -> V_66 ) ;
V_13 -> V_25 = V_67 / 2 +
V_2 -> V_4 -> V_5 . V_42 ;
if ( V_2 -> V_4 -> V_5 . V_6 & V_68 ) {
return F_39 ( V_2 , V_52 ) ;
} else {
F_26 ( V_13 , V_69 , L_3 ,
V_13 -> V_70 , V_13 -> V_25 ) ;
error = F_56 ( V_2 , & V_2 -> V_26 . V_71 , & V_2 -> V_26 . V_40 ,
L_4 , V_52 , 1 , 0 ) ;
if ( error != 0 ) {
F_46 ( V_13 ,
L_5 ,
error ) ;
goto V_72;
}
F_32 (bf, &sc->rx.rxbuf, list) {
V_17 = F_42 ( V_13 , V_13 -> V_25 ,
V_56 ) ;
if ( V_17 == NULL ) {
error = - V_57 ;
goto V_72;
}
V_9 -> V_22 = V_17 ;
V_9 -> V_21 = F_43 ( V_2 -> V_43 , V_17 -> V_24 ,
V_13 -> V_25 ,
V_73 ) ;
if ( F_44 ( F_45 ( V_2 -> V_43 ,
V_9 -> V_21 ) ) ) {
F_34 ( V_17 ) ;
V_9 -> V_22 = NULL ;
V_9 -> V_21 = 0 ;
F_46 ( V_13 ,
L_2 ) ;
error = - V_57 ;
goto V_72;
}
}
V_2 -> V_26 . V_27 = NULL ;
}
V_72:
if ( error )
F_57 ( V_2 ) ;
return error ;
}
void F_57 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_16 * V_17 ;
struct V_8 * V_9 ;
if ( V_2 -> V_4 -> V_5 . V_6 & V_68 ) {
F_31 ( V_2 ) ;
return;
} else {
F_32 (bf, &sc->rx.rxbuf, list) {
V_17 = V_9 -> V_22 ;
if ( V_17 ) {
F_33 ( V_2 -> V_43 , V_9 -> V_21 ,
V_13 -> V_25 ,
V_73 ) ;
F_58 ( V_17 ) ;
V_9 -> V_21 = 0 ;
V_9 -> V_22 = NULL ;
}
}
if ( V_2 -> V_26 . V_71 . V_74 != 0 )
F_59 ( V_2 , & V_2 -> V_26 . V_71 , & V_2 -> V_26 . V_40 ) ;
}
}
T_1 F_11 ( struct V_1 * V_2 )
{
T_1 V_32 ;
V_32 = V_75 | V_76
| V_77 ;
if ( V_2 -> V_26 . V_78 & V_79 )
V_32 |= V_80 ;
if ( V_2 -> V_4 -> V_81 )
V_32 |= V_82 ;
if ( V_2 -> V_26 . V_78 & V_83 )
V_32 |= V_84 ;
if ( ( V_2 -> V_4 -> V_85 == V_86 ) &&
( V_2 -> V_87 <= 1 ) &&
! ( V_2 -> V_26 . V_78 & V_88 ) )
V_32 |= V_89 ;
else
V_32 |= V_90 ;
if ( ( V_2 -> V_4 -> V_85 == V_91 ) ||
( V_2 -> V_26 . V_78 & V_92 ) )
V_32 |= V_93 ;
if ( F_60 ( & V_2 -> V_60 -> V_61 ) )
V_32 |= V_94 ;
if ( V_2 -> V_87 > 1 || ( V_2 -> V_26 . V_78 & V_95 ) ) {
if ( V_2 -> V_4 -> V_96 . V_97 == V_98 )
V_32 |= V_82 ;
V_32 |= V_99 ;
}
if ( F_61 ( V_2 -> V_4 ) )
V_32 |= V_100 ;
return V_32 ;
}
int F_62 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_8 * V_9 , * V_46 ;
if ( V_11 -> V_5 . V_6 & V_68 ) {
F_47 ( V_2 ) ;
return 0 ;
}
F_48 ( & V_2 -> V_26 . V_59 ) ;
if ( F_25 ( & V_2 -> V_26 . V_40 ) )
goto V_101;
V_2 -> V_26 . V_27 = NULL ;
F_27 (bf, tbf, &sc->rx.rxbuf, list) {
F_2 ( V_2 , V_9 ) ;
}
if ( F_25 ( & V_2 -> V_26 . V_40 ) )
goto V_101;
V_9 = F_18 ( & V_2 -> V_26 . V_40 , struct V_8 , V_41 ) ;
F_7 ( V_11 , V_9 -> V_28 ) ;
F_49 ( V_11 ) ;
V_101:
F_10 ( V_2 ) ;
F_50 ( V_11 , ! ! ( V_2 -> V_60 -> V_61 . V_62 & V_63 ) ) ;
F_51 ( & V_2 -> V_26 . V_59 ) ;
return 0 ;
}
bool F_63 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
bool V_102 , V_103 = false ;
F_48 ( & V_2 -> V_26 . V_59 ) ;
F_64 ( V_11 ) ;
F_12 ( V_11 , 0 ) ;
V_102 = F_65 ( V_11 , & V_103 ) ;
if ( V_2 -> V_4 -> V_5 . V_6 & V_68 )
F_52 ( V_2 ) ;
else
V_2 -> V_26 . V_27 = NULL ;
F_51 ( & V_2 -> V_26 . V_59 ) ;
if ( ! ( V_11 -> V_104 & V_105 ) &&
F_44 ( ! V_102 ) ) {
F_46 ( F_3 ( V_2 -> V_4 ) ,
L_6
L_7 ) ;
F_66 ( ! V_102 ) ;
}
return V_102 && ! V_103 ;
}
void F_67 ( struct V_1 * V_2 )
{
F_68 ( V_65 , & V_2 -> V_66 ) ;
if ( V_2 -> V_4 -> V_5 . V_6 & V_68 )
F_69 ( V_2 , 1 , true ) ;
F_69 ( V_2 , 1 , false ) ;
F_55 ( V_65 , & V_2 -> V_66 ) ;
}
static bool F_70 ( struct V_16 * V_17 )
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
static void F_71 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
if ( V_17 -> V_117 < 24 + 8 + 2 + 2 )
return;
V_2 -> V_121 &= ~ V_122 ;
if ( V_2 -> V_121 & V_123 ) {
V_2 -> V_121 &= ~ V_123 ;
F_26 ( V_13 , V_124 ,
L_8 ) ;
F_72 ( V_2 ) ;
}
if ( F_70 ( V_17 ) ) {
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
static void F_73 ( struct V_1 * V_2 , struct V_16 * V_17 , bool V_126 )
{
struct V_127 * V_128 ;
struct V_12 * V_13 = F_3 ( V_2 -> V_4 ) ;
V_128 = (struct V_127 * ) V_17 -> V_24 ;
if ( ( ( V_2 -> V_121 & V_122 ) || F_1 ( V_2 ) )
&& V_126 ) {
F_71 ( V_2 , V_17 ) ;
} else if ( ( V_2 -> V_121 & V_125 ) &&
( F_74 ( V_128 -> V_129 ) ||
F_75 ( V_128 -> V_129 ) ) &&
F_76 ( V_128 -> V_130 ) &&
! F_77 ( V_128 -> V_129 ) ) {
V_2 -> V_121 &= ~ ( V_125 | V_122 ) ;
F_26 ( V_13 , V_124 ,
L_11 ) ;
} else if ( ( V_2 -> V_121 & V_131 ) &&
! F_76 ( V_128 -> V_130 ) &&
! F_78 ( V_128 -> V_129 ) ) {
V_2 -> V_121 &= ~ V_131 ;
F_26 ( V_13 , V_124 ,
L_12 ,
V_2 -> V_121 & ( V_122 |
V_125 |
V_131 |
V_132 ) ) ;
}
}
static bool F_79 ( struct V_1 * V_2 ,
enum V_34 V_35 ,
struct V_133 * V_134 ,
struct V_8 * * V_135 )
{
struct V_36 * V_37 = & V_2 -> V_26 . V_37 [ V_35 ] ;
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_16 * V_17 ;
struct V_8 * V_9 ;
int V_136 ;
V_17 = F_80 ( & V_37 -> V_38 ) ;
if ( ! V_17 )
return false ;
V_9 = F_21 ( V_17 ) ;
F_5 ( ! V_9 ) ;
F_81 ( V_2 -> V_43 , V_9 -> V_21 ,
V_13 -> V_25 , V_73 ) ;
V_136 = F_82 ( V_11 , V_134 , V_17 -> V_24 ) ;
if ( V_136 == - V_137 ) {
F_20 ( V_2 -> V_43 , V_9 -> V_21 ,
V_13 -> V_25 , V_73 ) ;
return false ;
}
F_83 ( V_17 , & V_37 -> V_38 ) ;
if ( V_136 == - V_138 ) {
F_30 ( & V_9 -> V_41 , & V_2 -> V_26 . V_40 ) ;
F_16 ( V_2 , V_35 ) ;
V_17 = F_80 ( & V_37 -> V_38 ) ;
if ( V_17 ) {
V_9 = F_21 ( V_17 ) ;
F_5 ( ! V_9 ) ;
F_83 ( V_17 , & V_37 -> V_38 ) ;
F_30 ( & V_9 -> V_41 , & V_2 -> V_26 . V_40 ) ;
F_16 ( V_2 , V_35 ) ;
}
V_9 = NULL ;
}
* V_135 = V_9 ;
return true ;
}
static struct V_8 * F_84 ( struct V_1 * V_2 ,
struct V_133 * V_134 ,
enum V_34 V_35 )
{
struct V_8 * V_9 = NULL ;
while ( F_79 ( V_2 , V_35 , V_134 , & V_9 ) ) {
if ( ! V_9 )
continue;
return V_9 ;
}
return NULL ;
}
static struct V_8 * F_85 ( struct V_1 * V_2 ,
struct V_133 * V_134 )
{
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_14 * V_15 ;
struct V_8 * V_9 ;
int V_136 ;
if ( F_25 ( & V_2 -> V_26 . V_40 ) ) {
V_2 -> V_26 . V_27 = NULL ;
return NULL ;
}
V_9 = F_18 ( & V_2 -> V_26 . V_40 , struct V_8 , V_41 ) ;
V_15 = V_9 -> V_18 ;
V_136 = F_86 ( V_11 , V_15 , V_134 ) ;
if ( V_136 == - V_137 ) {
struct V_133 V_139 ;
struct V_8 * V_46 ;
struct V_14 * V_140 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
if ( F_87 ( & V_9 -> V_41 , & V_2 -> V_26 . V_40 ) ) {
V_2 -> V_26 . V_27 = NULL ;
return NULL ;
}
V_46 = F_88 ( V_9 -> V_41 . V_141 , struct V_8 , V_41 ) ;
V_140 = V_46 -> V_18 ;
V_136 = F_86 ( V_11 , V_140 , & V_139 ) ;
if ( V_136 == - V_137 )
return NULL ;
}
if ( ! V_9 -> V_22 )
return V_9 ;
F_81 ( V_2 -> V_43 , V_9 -> V_21 ,
V_13 -> V_25 ,
V_73 ) ;
return V_9 ;
}
static bool F_89 ( struct V_12 * V_13 ,
struct V_127 * V_128 ,
struct V_142 * V_143 ,
struct V_133 * V_144 ,
bool * V_145 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 -> V_146 ;
bool V_147 , V_148 , V_149 , V_150 ;
struct V_10 * V_11 = V_13 -> V_11 ;
T_3 V_151 ;
T_2 V_42 = V_11 -> V_5 . V_42 ;
V_151 = V_128 -> V_129 ;
V_147 = ! ! F_76 ( V_128 -> V_130 ) ;
V_148 = V_144 -> V_152 != V_153 &&
F_90 ( V_144 -> V_152 , V_13 -> V_154 ) ;
V_149 = V_148 && F_74 ( V_151 ) &&
F_91 ( V_151 ) &&
! ( V_144 -> V_155 &
( V_156 | V_157 | V_158 |
V_159 ) ) ;
if ( V_144 -> V_152 == V_153 ||
! F_90 ( V_144 -> V_152 , V_13 -> V_160 ) )
V_144 -> V_155 &= ~ V_159 ;
if ( ! V_144 -> V_161 ) {
F_92 ( V_162 ) ;
return false ;
}
if ( V_144 -> V_161 > ( V_13 -> V_25 - V_42 ) ) {
F_92 ( V_162 ) ;
return false ;
}
if ( V_144 -> V_163 )
return true ;
V_150 = V_148 && ! F_93 ( V_151 ) &&
! F_78 ( V_151 ) &&
! ( F_94 ( V_128 -> V_164 ) & V_165 ) &&
( V_144 -> V_155 & V_158 ) ;
if ( V_144 -> V_155 != 0 ) {
T_2 V_166 ;
if ( V_144 -> V_155 & V_157 ) {
V_143 -> V_167 |= V_168 ;
V_150 = false ;
}
if ( V_144 -> V_155 & V_169 )
return false ;
if ( ( V_144 -> V_155 & V_156 ) ||
( ! V_147 && ( V_144 -> V_155 & V_159 ) ) ) {
* V_145 = true ;
V_150 = false ;
}
V_166 = V_156 | V_158 |
V_159 ;
if ( V_11 -> V_81 && ( V_2 -> V_26 . V_78 & V_170 ) )
V_166 |= V_157 ;
if ( V_144 -> V_155 & ~ V_166 )
return false ;
}
if ( V_149 )
V_143 -> V_167 |= V_171 ;
else if ( V_147 && V_150 )
V_143 -> V_167 |= V_172 ;
return true ;
}
static int F_95 ( struct V_12 * V_13 ,
struct V_173 * V_60 ,
struct V_133 * V_144 ,
struct V_142 * V_143 )
{
struct V_174 * V_175 ;
enum V_176 V_177 ;
unsigned int V_53 = 0 ;
struct V_1 T_4 * V_2 = V_13 -> V_146 ;
V_177 = V_60 -> V_61 . V_178 -> V_177 ;
V_175 = V_60 -> V_179 -> V_180 [ V_177 ] ;
if ( V_144 -> V_181 & 0x80 ) {
V_143 -> V_167 |= V_182 ;
if ( V_144 -> V_183 & V_184 )
V_143 -> V_167 |= V_185 ;
if ( V_144 -> V_183 & V_186 )
V_143 -> V_167 |= V_187 ;
V_143 -> V_188 = V_144 -> V_181 & 0x7f ;
return 0 ;
}
for ( V_53 = 0 ; V_53 < V_175 -> V_189 ; V_53 ++ ) {
if ( V_175 -> V_190 [ V_53 ] . V_191 == V_144 -> V_181 ) {
V_143 -> V_188 = V_53 ;
return 0 ;
}
if ( V_175 -> V_190 [ V_53 ] . V_192 == V_144 -> V_181 ) {
V_143 -> V_167 |= V_193 ;
V_143 -> V_188 = V_53 ;
return 0 ;
}
}
F_26 ( V_13 , V_194 ,
L_13 ,
V_144 -> V_181 ) ;
F_92 ( V_195 ) ;
return - V_138 ;
}
static void F_96 ( struct V_12 * V_13 ,
struct V_173 * V_60 ,
struct V_127 * V_128 ,
struct V_133 * V_144 )
{
struct V_1 * V_2 = V_60 -> V_146 ;
struct V_10 * V_11 = V_13 -> V_11 ;
int V_196 ;
int V_197 = V_144 -> V_198 ;
if ( ! V_144 -> V_199 ||
( ( V_11 -> V_85 != V_86 ) &&
( V_11 -> V_85 != V_200 ) ) )
return;
if ( V_144 -> V_198 != V_201 && ! V_144 -> V_202 )
F_97 ( V_2 -> V_196 , V_144 -> V_198 ) ;
V_196 = V_2 -> V_196 ;
if ( F_98 ( V_196 != V_203 ) )
V_197 = F_99 ( V_196 , V_204 ) ;
if ( V_197 < 0 )
V_197 = 0 ;
V_11 -> V_205 . V_206 = V_197 ;
}
static int F_100 ( struct V_12 * V_13 ,
struct V_173 * V_60 ,
struct V_127 * V_128 ,
struct V_133 * V_144 ,
struct V_142 * V_207 ,
bool * V_145 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
if ( ! F_89 ( V_13 , V_128 , V_207 , V_144 , V_145 ) )
return - V_138 ;
if ( V_144 -> V_163 )
return 0 ;
F_96 ( V_13 , V_60 , V_128 , V_144 ) ;
if ( F_95 ( V_13 , V_60 , V_144 , V_207 ) )
return - V_138 ;
V_207 -> V_177 = V_60 -> V_61 . V_178 -> V_177 ;
V_207 -> V_208 = V_60 -> V_61 . V_178 -> V_209 ;
V_207 -> signal = V_11 -> V_210 + V_144 -> V_198 ;
V_207 -> V_29 = V_144 -> V_211 ;
V_207 -> V_167 |= V_212 ;
if ( V_144 -> V_202 )
V_207 -> V_167 |= V_213 ;
return 0 ;
}
static void F_101 ( struct V_12 * V_13 ,
struct V_16 * V_17 ,
struct V_133 * V_144 ,
struct V_142 * V_143 ,
bool V_145 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
struct V_127 * V_128 ;
int V_214 , V_215 , V_216 ;
T_2 V_217 ;
T_3 V_151 ;
V_128 = (struct V_127 * ) V_17 -> V_24 ;
V_214 = F_102 ( V_17 ) ;
V_151 = V_128 -> V_129 ;
V_215 = F_103 ( V_128 -> V_129 ) ;
V_216 = V_215 & 3 ;
if ( V_216 && V_17 -> V_117 >= V_215 + V_216 + V_218 ) {
memmove ( V_17 -> V_24 + V_216 , V_17 -> V_24 , V_215 ) ;
F_104 ( V_17 , V_216 ) ;
}
V_217 = V_144 -> V_152 ;
if ( ! ( V_217 == V_153 ) && ! V_145 &&
F_91 ( V_151 ) ) {
V_143 -> V_167 |= V_219 ;
} else if ( F_91 ( V_151 )
&& ! V_145 && V_17 -> V_117 >= V_214 + 4 ) {
V_217 = V_17 -> V_24 [ V_214 + 3 ] >> 6 ;
if ( F_90 ( V_217 , V_13 -> V_220 ) )
V_143 -> V_167 |= V_219 ;
}
if ( V_11 -> V_221 &&
( V_143 -> V_167 & V_219 ) &&
F_105 ( V_151 ) )
V_143 -> V_167 &= ~ V_219 ;
}
int F_69 ( struct V_1 * V_2 , int V_222 , bool V_223 )
{
struct V_8 * V_9 ;
struct V_16 * V_17 = NULL , * V_224 , * V_225 ;
struct V_142 * V_143 ;
struct V_10 * V_11 = V_2 -> V_4 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_173 * V_60 = V_2 -> V_60 ;
struct V_127 * V_128 ;
int V_226 ;
struct V_133 V_134 ;
enum V_34 V_35 ;
bool V_227 = ! ! ( V_11 -> V_5 . V_6 & V_68 ) ;
int V_228 ;
T_2 V_42 = V_11 -> V_5 . V_42 ;
T_5 V_229 = 0 ;
T_1 V_230 = 0 ;
unsigned long V_62 ;
if ( V_227 )
V_228 = V_50 ;
else
V_228 = V_73 ;
V_35 = V_223 ? V_49 : V_48 ;
F_48 ( & V_2 -> V_26 . V_59 ) ;
V_229 = F_106 ( V_11 ) ;
V_230 = V_229 & 0xffffffff ;
do {
bool V_145 = false ;
if ( F_90 ( V_65 , & V_2 -> V_66 ) && ( V_222 == 0 ) )
break;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
if ( V_227 )
V_9 = F_84 ( V_2 , & V_134 , V_35 ) ;
else
V_9 = F_85 ( V_2 , & V_134 ) ;
if ( ! V_9 )
break;
V_17 = V_9 -> V_22 ;
if ( ! V_17 )
continue;
if ( V_2 -> V_26 . V_231 )
V_225 = V_2 -> V_26 . V_231 ;
else
V_225 = V_17 ;
V_128 = (struct V_127 * ) ( V_225 -> V_24 + V_42 ) ;
V_143 = F_107 ( V_225 ) ;
if ( F_108 ( V_128 -> V_129 ) ) {
F_92 ( V_232 ) ;
if ( ! F_109 ( V_13 -> V_233 ) &&
F_110 ( V_128 -> V_234 , V_13 -> V_233 ) )
V_134 . V_199 = true ;
else
V_134 . V_199 = false ;
}
else
V_134 . V_199 = false ;
V_2 -> V_26 . V_235 ++ ;
F_111 ( V_2 , & V_134 ) ;
if ( F_90 ( V_65 , & V_2 -> V_66 ) ) {
F_92 ( V_236 ) ;
goto V_237;
}
memset ( V_143 , 0 , sizeof( struct V_142 ) ) ;
V_143 -> V_238 = ( V_229 & ~ 0xffffffffULL ) | V_134 . V_239 ;
if ( V_134 . V_239 > V_230 &&
F_44 ( V_134 . V_239 - V_230 > 0x10000000 ) )
V_143 -> V_238 -= 0x100000000ULL ;
if ( V_134 . V_239 < V_230 &&
F_44 ( V_230 - V_134 . V_239 > 0x10000000 ) )
V_143 -> V_238 += 0x100000000ULL ;
V_226 = F_100 ( V_13 , V_60 , V_128 , & V_134 ,
V_143 , & V_145 ) ;
if ( V_226 )
goto V_237;
if ( V_134 . V_199 ) {
V_2 -> V_240 = 0 ;
F_112 ( V_2 , 3 ) ;
}
V_224 = F_42 ( V_13 , V_13 -> V_25 , V_241 ) ;
if ( ! V_224 ) {
F_92 ( V_242 ) ;
goto V_237;
}
F_33 ( V_2 -> V_43 , V_9 -> V_21 ,
V_13 -> V_25 ,
V_228 ) ;
F_113 ( V_17 , V_134 . V_161 + V_11 -> V_5 . V_42 ) ;
if ( V_11 -> V_5 . V_42 )
F_104 ( V_17 , V_11 -> V_5 . V_42 ) ;
if ( ! V_134 . V_163 )
F_101 ( V_13 , V_225 , & V_134 ,
V_143 , V_145 ) ;
V_9 -> V_22 = V_224 ;
V_9 -> V_21 = F_43 ( V_2 -> V_43 , V_224 -> V_24 ,
V_13 -> V_25 ,
V_228 ) ;
if ( F_44 ( F_45 ( V_2 -> V_43 ,
V_9 -> V_21 ) ) ) {
F_34 ( V_224 ) ;
V_9 -> V_22 = NULL ;
V_9 -> V_21 = 0 ;
F_46 ( V_13 , L_14 ) ;
F_114 ( V_60 , V_17 ) ;
break;
}
if ( V_134 . V_163 ) {
F_92 ( V_243 ) ;
if ( V_2 -> V_26 . V_231 ) {
F_34 ( V_2 -> V_26 . V_231 ) ;
F_34 ( V_17 ) ;
F_92 ( V_244 ) ;
V_17 = NULL ;
}
V_2 -> V_26 . V_231 = V_17 ;
goto V_245;
}
if ( V_2 -> V_26 . V_231 ) {
int V_246 = V_17 -> V_117 - F_115 ( V_225 ) ;
if ( F_116 ( V_225 , 0 , V_246 , V_241 ) < 0 ) {
F_58 ( V_17 ) ;
F_92 ( V_242 ) ;
goto V_237;
}
V_2 -> V_26 . V_231 = NULL ;
F_117 ( V_17 , F_113 ( V_225 , V_17 -> V_117 ) ,
V_17 -> V_117 ) ;
F_34 ( V_17 ) ;
V_17 = V_225 ;
}
if ( V_11 -> V_5 . V_6 & V_247 ) {
if ( V_2 -> V_26 . V_30 != V_134 . V_211 ) {
if ( ++ V_2 -> V_26 . V_31 >= 3 )
F_8 ( V_2 , V_134 . V_211 ) ;
} else {
V_2 -> V_26 . V_31 = 0 ;
}
}
if ( V_143 -> V_167 & V_171 )
F_118 ( V_17 , V_17 -> V_117 - 8 ) ;
F_119 ( & V_2 -> V_248 , V_62 ) ;
if ( ( V_2 -> V_121 & ( V_122 |
V_125 |
V_131 ) ) ||
F_1 ( V_2 ) )
F_73 ( V_2 , V_17 , V_134 . V_199 ) ;
F_120 ( & V_2 -> V_248 , V_62 ) ;
if ( ( V_11 -> V_5 . V_6 & V_247 ) && V_2 -> V_249 == 3 )
F_121 ( V_2 , & V_134 ) ;
F_114 ( V_60 , V_17 ) ;
V_237:
if ( V_2 -> V_26 . V_231 ) {
F_34 ( V_2 -> V_26 . V_231 ) ;
V_2 -> V_26 . V_231 = NULL ;
}
V_245:
if ( V_227 ) {
F_30 ( & V_9 -> V_41 , & V_2 -> V_26 . V_40 ) ;
F_16 ( V_2 , V_35 ) ;
} else {
F_122 ( & V_9 -> V_41 , & V_2 -> V_26 . V_40 ) ;
F_2 ( V_2 , V_9 ) ;
if ( ! V_222 )
F_49 ( V_11 ) ;
}
} while ( 1 );
F_51 ( & V_2 -> V_26 . V_59 ) ;
if ( ! ( V_11 -> V_250 & V_251 ) ) {
V_11 -> V_250 |= ( V_251 | V_252 ) ;
F_123 ( V_11 ) ;
}
return 0 ;
}
