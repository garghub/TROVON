static inline bool F_1 ( int V_1 , int V_2 ,
int V_3 , int V_4 ,
int V_5 , int V_6 )
{
return ( ( ( V_1 >= V_7 ) &&
( V_5 > V_4 + V_2 ) ) ||
( V_5 > V_4 + V_3 ) ) && ( V_6 > 50 ) ;
}
static inline bool F_2 ( T_1 V_8 , int V_1 ,
int V_9 , int V_10 ,
int V_5 , int V_4 )
{
bool V_11 = false ;
switch ( V_8 ) {
case 0 :
if ( V_1 > V_12 )
V_11 = true ;
break;
case 1 :
case 2 :
if ( ( ( ( V_9 == V_13 ) &&
( V_10 == V_14 ) &&
( V_5 >= ( V_4 - 5 ) ) ) ||
( ( V_9 == V_14 ) &&
( V_10 == V_13 ) &&
( V_5 >= ( V_4 - 2 ) ) ) ) &&
( V_5 >= 4 ) )
V_11 = true ;
else
V_11 = false ;
break;
}
return V_11 ;
}
static inline bool F_3 ( struct V_15 * V_16 )
{
return V_16 -> V_17 &&
( V_16 -> V_18 -> V_19 . V_20 & V_21 ) ;
}
static void F_4 ( struct V_15 * V_16 , struct V_22 * V_23 )
{
struct V_24 * V_25 = V_16 -> V_18 ;
struct V_26 * V_27 = F_5 ( V_25 ) ;
struct V_28 * V_29 ;
struct V_30 * V_31 ;
F_6 ( V_23 ) ;
V_29 = V_23 -> V_32 ;
V_29 -> V_33 = 0 ;
V_29 -> V_34 = V_23 -> V_35 ;
V_31 = V_23 -> V_36 ;
F_7 ( V_31 == NULL ) ;
V_29 -> V_37 = V_31 -> V_38 ;
F_8 ( V_25 , V_29 ,
V_27 -> V_39 ,
0 ) ;
if ( V_16 -> V_40 . V_41 == NULL )
F_9 ( V_25 , V_23 -> V_42 ) ;
else
* V_16 -> V_40 . V_41 = V_23 -> V_42 ;
V_16 -> V_40 . V_41 = & V_29 -> V_33 ;
}
static void F_10 ( struct V_15 * V_16 , T_2 V_43 )
{
F_11 ( V_16 -> V_18 , V_43 ) ;
V_16 -> V_40 . V_44 = V_43 ;
V_16 -> V_40 . V_45 = 0 ;
}
static void F_12 ( struct V_15 * V_16 )
{
struct V_24 * V_25 = V_16 -> V_18 ;
struct V_26 * V_27 = F_5 ( V_25 ) ;
T_2 V_46 , V_47 [ 2 ] ;
V_46 = F_13 ( V_16 ) ;
F_14 ( V_25 , V_46 ) ;
F_15 ( V_27 ) ;
F_16 ( V_25 ) ;
V_47 [ 0 ] = V_47 [ 1 ] = ~ 0 ;
F_17 ( V_25 , V_47 [ 0 ] , V_47 [ 1 ] ) ;
}
static bool F_18 ( struct V_15 * V_16 ,
enum V_48 V_49 )
{
struct V_24 * V_25 = V_16 -> V_18 ;
struct V_50 * V_51 ;
struct V_30 * V_31 ;
struct V_22 * V_23 ;
V_51 = & V_16 -> V_40 . V_51 [ V_49 ] ;
if ( F_19 ( & V_51 -> V_52 ) >= V_51 -> V_53 )
return false ;
V_23 = F_20 ( & V_16 -> V_40 . V_54 , struct V_22 , V_55 ) ;
F_21 ( & V_23 -> V_55 ) ;
V_31 = V_23 -> V_36 ;
F_6 ( V_23 ) ;
memset ( V_31 -> V_38 , 0 , V_25 -> V_19 . V_56 ) ;
F_22 ( V_16 -> V_57 , V_23 -> V_35 ,
V_25 -> V_19 . V_56 , V_58 ) ;
F_23 ( V_31 ) = V_23 ;
F_24 ( V_25 , V_23 -> V_35 , V_49 ) ;
F_25 ( & V_51 -> V_52 , V_31 ) ;
return true ;
}
static void F_26 ( struct V_15 * V_16 ,
enum V_48 V_49 , int V_59 )
{
struct V_26 * V_27 = F_5 ( V_16 -> V_18 ) ;
struct V_22 * V_23 , * V_60 ;
if ( F_27 ( & V_16 -> V_40 . V_54 ) ) {
F_28 ( V_27 , V_61 , L_1 ) ;
return;
}
F_29 (bf, tbf, &sc->rx.rxbuf, list)
if ( ! F_18 ( V_16 , V_49 ) )
break;
}
static void F_30 ( struct V_15 * V_16 ,
enum V_48 V_49 )
{
struct V_22 * V_23 ;
struct V_50 * V_51 ;
struct V_30 * V_31 ;
V_51 = & V_16 -> V_40 . V_51 [ V_49 ] ;
while ( ( V_31 = F_31 ( & V_51 -> V_52 ) ) != NULL ) {
V_23 = F_23 ( V_31 ) ;
F_7 ( ! V_23 ) ;
F_32 ( & V_23 -> V_55 , & V_16 -> V_40 . V_54 ) ;
}
}
static void F_33 ( struct V_15 * V_16 )
{
struct V_24 * V_25 = V_16 -> V_18 ;
struct V_26 * V_27 = F_5 ( V_25 ) ;
struct V_22 * V_23 ;
F_30 ( V_16 , V_62 ) ;
F_30 ( V_16 , V_63 ) ;
F_34 (bf, &sc->rx.rxbuf, list) {
if ( V_23 -> V_36 ) {
F_35 ( V_16 -> V_57 , V_23 -> V_35 ,
V_27 -> V_39 ,
V_64 ) ;
F_36 ( V_23 -> V_36 ) ;
V_23 -> V_35 = 0 ;
V_23 -> V_36 = NULL ;
}
}
F_37 ( & V_16 -> V_40 . V_54 ) ;
F_38 ( V_16 -> V_40 . V_65 ) ;
V_16 -> V_40 . V_65 = NULL ;
}
static void F_39 ( struct V_50 * V_51 , int V_59 )
{
F_40 ( & V_51 -> V_52 ) ;
V_51 -> V_53 = V_59 ;
}
static int F_41 ( struct V_15 * V_16 , int V_66 )
{
struct V_26 * V_27 = F_5 ( V_16 -> V_18 ) ;
struct V_24 * V_25 = V_16 -> V_18 ;
struct V_30 * V_31 ;
struct V_22 * V_23 ;
int error = 0 , V_67 ;
T_2 V_59 ;
F_42 ( V_25 , V_27 -> V_39 -
V_25 -> V_19 . V_56 ) ;
F_39 ( & V_16 -> V_40 . V_51 [ V_62 ] ,
V_25 -> V_19 . V_68 ) ;
F_39 ( & V_16 -> V_40 . V_51 [ V_63 ] ,
V_25 -> V_19 . V_69 ) ;
V_59 = sizeof( struct V_22 ) * V_66 ;
V_23 = F_43 ( V_59 , V_70 ) ;
if ( ! V_23 )
return - V_71 ;
F_37 ( & V_16 -> V_40 . V_54 ) ;
V_16 -> V_40 . V_65 = V_23 ;
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ , V_23 ++ ) {
V_31 = F_44 ( V_27 , V_27 -> V_39 , V_70 ) ;
if ( ! V_31 ) {
error = - V_71 ;
goto V_72;
}
memset ( V_31 -> V_38 , 0 , V_27 -> V_39 ) ;
V_23 -> V_36 = V_31 ;
V_23 -> V_35 = F_45 ( V_16 -> V_57 , V_31 -> V_38 ,
V_27 -> V_39 ,
V_64 ) ;
if ( F_46 ( F_47 ( V_16 -> V_57 ,
V_23 -> V_35 ) ) ) {
F_36 ( V_31 ) ;
V_23 -> V_36 = NULL ;
V_23 -> V_35 = 0 ;
F_48 ( V_27 ,
L_2 ) ;
error = - V_71 ;
goto V_72;
}
F_32 ( & V_23 -> V_55 , & V_16 -> V_40 . V_54 ) ;
}
return 0 ;
V_72:
F_33 ( V_16 ) ;
return error ;
}
static void F_49 ( struct V_15 * V_16 )
{
F_50 ( & V_16 -> V_40 . V_73 ) ;
F_51 ( V_16 -> V_18 ) ;
F_26 ( V_16 , V_63 ,
V_16 -> V_40 . V_51 [ V_63 ] . V_53 ) ;
F_26 ( V_16 , V_62 ,
V_16 -> V_40 . V_51 [ V_62 ] . V_53 ) ;
F_12 ( V_16 ) ;
F_52 ( V_16 -> V_18 , ( V_16 -> V_74 & V_75 ) ) ;
F_53 ( & V_16 -> V_40 . V_73 ) ;
}
static void F_54 ( struct V_15 * V_16 )
{
F_30 ( V_16 , V_63 ) ;
F_30 ( V_16 , V_62 ) ;
}
int F_55 ( struct V_15 * V_16 , int V_66 )
{
struct V_26 * V_27 = F_5 ( V_16 -> V_18 ) ;
struct V_30 * V_31 ;
struct V_22 * V_23 ;
int error = 0 ;
F_56 ( & V_16 -> V_76 ) ;
V_16 -> V_74 &= ~ V_77 ;
F_56 ( & V_16 -> V_40 . V_73 ) ;
V_27 -> V_39 = V_78 / 2 +
V_16 -> V_18 -> V_19 . V_56 ;
if ( V_16 -> V_18 -> V_19 . V_20 & V_79 ) {
return F_41 ( V_16 , V_66 ) ;
} else {
F_28 ( V_27 , V_80 , L_3 ,
V_27 -> V_81 , V_27 -> V_39 ) ;
error = F_57 ( V_16 , & V_16 -> V_40 . V_82 , & V_16 -> V_40 . V_54 ,
L_4 , V_66 , 1 , 0 ) ;
if ( error != 0 ) {
F_48 ( V_27 ,
L_5 ,
error ) ;
goto V_83;
}
F_34 (bf, &sc->rx.rxbuf, list) {
V_31 = F_44 ( V_27 , V_27 -> V_39 ,
V_70 ) ;
if ( V_31 == NULL ) {
error = - V_71 ;
goto V_83;
}
V_23 -> V_36 = V_31 ;
V_23 -> V_35 = F_45 ( V_16 -> V_57 , V_31 -> V_38 ,
V_27 -> V_39 ,
V_84 ) ;
if ( F_46 ( F_47 ( V_16 -> V_57 ,
V_23 -> V_35 ) ) ) {
F_36 ( V_31 ) ;
V_23 -> V_36 = NULL ;
V_23 -> V_35 = 0 ;
F_48 ( V_27 ,
L_2 ) ;
error = - V_71 ;
goto V_83;
}
}
V_16 -> V_40 . V_41 = NULL ;
}
V_83:
if ( error )
F_58 ( V_16 ) ;
return error ;
}
void F_58 ( struct V_15 * V_16 )
{
struct V_24 * V_25 = V_16 -> V_18 ;
struct V_26 * V_27 = F_5 ( V_25 ) ;
struct V_30 * V_31 ;
struct V_22 * V_23 ;
if ( V_16 -> V_18 -> V_19 . V_20 & V_79 ) {
F_33 ( V_16 ) ;
return;
} else {
F_34 (bf, &sc->rx.rxbuf, list) {
V_31 = V_23 -> V_36 ;
if ( V_31 ) {
F_35 ( V_16 -> V_57 , V_23 -> V_35 ,
V_27 -> V_39 ,
V_84 ) ;
F_59 ( V_31 ) ;
V_23 -> V_35 = 0 ;
V_23 -> V_36 = NULL ;
}
}
if ( V_16 -> V_40 . V_82 . V_85 != 0 )
F_60 ( V_16 , & V_16 -> V_40 . V_82 , & V_16 -> V_40 . V_54 ) ;
}
}
T_2 F_13 ( struct V_15 * V_16 )
{
T_2 V_46 ;
V_46 = V_86 | V_87
| V_88 ;
if ( V_16 -> V_40 . V_89 & V_90 )
V_46 |= V_91 ;
if ( V_16 -> V_18 -> V_92 )
V_46 |= V_93 ;
if ( V_16 -> V_40 . V_89 & V_94 )
V_46 |= V_95 ;
if ( ( V_16 -> V_18 -> V_96 == V_97 ) &&
( V_16 -> V_98 <= 1 ) &&
! ( V_16 -> V_40 . V_89 & V_99 ) )
V_46 |= V_100 ;
else
V_46 |= V_101 ;
if ( ( V_16 -> V_18 -> V_96 == V_102 ) ||
( V_16 -> V_40 . V_89 & V_103 ) )
V_46 |= V_104 ;
if ( F_61 ( & V_16 -> V_105 -> V_106 ) )
V_46 |= V_107 ;
if ( V_16 -> V_98 > 1 || ( V_16 -> V_40 . V_89 & V_108 ) ) {
if ( V_16 -> V_18 -> V_109 . V_110 == V_111 )
V_46 |= V_93 ;
V_46 |= V_112 ;
}
return V_46 ;
}
int F_62 ( struct V_15 * V_16 )
{
struct V_24 * V_25 = V_16 -> V_18 ;
struct V_22 * V_23 , * V_60 ;
if ( V_25 -> V_19 . V_20 & V_79 ) {
F_49 ( V_16 ) ;
return 0 ;
}
F_50 ( & V_16 -> V_40 . V_73 ) ;
if ( F_27 ( & V_16 -> V_40 . V_54 ) )
goto V_113;
V_16 -> V_40 . V_41 = NULL ;
F_29 (bf, tbf, &sc->rx.rxbuf, list) {
F_4 ( V_16 , V_23 ) ;
}
if ( F_27 ( & V_16 -> V_40 . V_54 ) )
goto V_113;
V_23 = F_20 ( & V_16 -> V_40 . V_54 , struct V_22 , V_55 ) ;
F_9 ( V_25 , V_23 -> V_42 ) ;
F_51 ( V_25 ) ;
V_113:
F_12 ( V_16 ) ;
F_52 ( V_25 , ( V_16 -> V_74 & V_75 ) ) ;
F_53 ( & V_16 -> V_40 . V_73 ) ;
return 0 ;
}
bool F_63 ( struct V_15 * V_16 )
{
struct V_24 * V_25 = V_16 -> V_18 ;
bool V_114 , V_115 = false ;
F_50 ( & V_16 -> V_40 . V_73 ) ;
F_64 ( V_25 ) ;
F_14 ( V_25 , 0 ) ;
V_114 = F_65 ( V_25 , & V_115 ) ;
if ( V_16 -> V_18 -> V_19 . V_20 & V_79 )
F_54 ( V_16 ) ;
else
V_16 -> V_40 . V_41 = NULL ;
F_53 ( & V_16 -> V_40 . V_73 ) ;
if ( ! ( V_25 -> V_116 & V_117 ) &&
F_46 ( ! V_114 ) ) {
F_48 ( F_5 ( V_16 -> V_18 ) ,
L_6
L_7 ) ;
F_66 ( ! V_114 ) ;
}
return V_114 && ! V_115 ;
}
void F_67 ( struct V_15 * V_16 )
{
V_16 -> V_74 |= V_77 ;
if ( V_16 -> V_18 -> V_19 . V_20 & V_79 )
F_68 ( V_16 , 1 , true ) ;
F_68 ( V_16 , 1 , false ) ;
V_16 -> V_74 &= ~ V_77 ;
}
static bool F_69 ( struct V_30 * V_31 )
{
struct V_118 * V_119 ;
T_1 * V_120 , * V_121 , V_122 , V_123 ;
struct V_124 * V_125 ;
V_119 = (struct V_118 * ) V_31 -> V_38 ;
V_120 = V_119 -> V_126 . V_127 . V_128 ;
V_121 = V_31 -> V_38 + V_31 -> V_129 ;
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
static void F_70 ( struct V_15 * V_16 , struct V_30 * V_31 )
{
struct V_26 * V_27 = F_5 ( V_16 -> V_18 ) ;
if ( V_31 -> V_129 < 24 + 8 + 2 + 2 )
return;
V_16 -> V_133 &= ~ V_134 ;
if ( V_16 -> V_133 & V_135 ) {
V_16 -> V_133 &= ~ V_135 ;
F_28 ( V_27 , V_136 ,
L_8 ) ;
F_71 ( V_16 ) ;
}
if ( F_69 ( V_31 ) ) {
F_28 ( V_27 , V_136 ,
L_9 ) ;
V_16 -> V_133 |= V_137 | V_134 ;
return;
}
if ( V_16 -> V_133 & V_137 ) {
V_16 -> V_133 &= ~ V_137 ;
F_28 ( V_27 , V_136 , L_10 ) ;
}
}
static void F_72 ( struct V_15 * V_16 , struct V_30 * V_31 , bool V_138 )
{
struct V_139 * V_140 ;
struct V_26 * V_27 = F_5 ( V_16 -> V_18 ) ;
V_140 = (struct V_139 * ) V_31 -> V_38 ;
if ( ( ( V_16 -> V_133 & V_134 ) || F_3 ( V_16 ) )
&& V_138 )
F_70 ( V_16 , V_31 ) ;
else if ( ( V_16 -> V_133 & V_137 ) &&
( F_73 ( V_140 -> V_141 ) ||
F_74 ( V_140 -> V_141 ) ) &&
F_75 ( V_140 -> V_142 ) &&
! F_76 ( V_140 -> V_141 ) ) {
V_16 -> V_133 &= ~ ( V_137 | V_134 ) ;
F_28 ( V_27 , V_136 ,
L_11 ) ;
} else if ( ( V_16 -> V_133 & V_143 ) &&
! F_75 ( V_140 -> V_142 ) &&
! F_77 ( V_140 -> V_141 ) ) {
V_16 -> V_133 &= ~ V_143 ;
F_28 ( V_27 , V_136 ,
L_12 ,
V_16 -> V_133 & ( V_134 |
V_137 |
V_143 |
V_144 ) ) ;
}
}
static bool F_78 ( struct V_15 * V_16 ,
enum V_48 V_49 ,
struct V_145 * V_146 ,
struct V_22 * * V_147 )
{
struct V_50 * V_51 = & V_16 -> V_40 . V_51 [ V_49 ] ;
struct V_24 * V_25 = V_16 -> V_18 ;
struct V_26 * V_27 = F_5 ( V_25 ) ;
struct V_30 * V_31 ;
struct V_22 * V_23 ;
int V_148 ;
V_31 = F_79 ( & V_51 -> V_52 ) ;
if ( ! V_31 )
return false ;
V_23 = F_23 ( V_31 ) ;
F_7 ( ! V_23 ) ;
F_80 ( V_16 -> V_57 , V_23 -> V_35 ,
V_27 -> V_39 , V_84 ) ;
V_148 = F_81 ( V_25 , V_146 , V_31 -> V_38 ) ;
if ( V_148 == - V_149 ) {
F_22 ( V_16 -> V_57 , V_23 -> V_35 ,
V_27 -> V_39 , V_84 ) ;
return false ;
}
F_82 ( V_31 , & V_51 -> V_52 ) ;
if ( V_148 == - V_150 ) {
F_32 ( & V_23 -> V_55 , & V_16 -> V_40 . V_54 ) ;
F_18 ( V_16 , V_49 ) ;
V_31 = F_79 ( & V_51 -> V_52 ) ;
if ( V_31 ) {
V_23 = F_23 ( V_31 ) ;
F_7 ( ! V_23 ) ;
F_82 ( V_31 , & V_51 -> V_52 ) ;
F_32 ( & V_23 -> V_55 , & V_16 -> V_40 . V_54 ) ;
F_18 ( V_16 , V_49 ) ;
}
V_23 = NULL ;
}
* V_147 = V_23 ;
return true ;
}
static struct V_22 * F_83 ( struct V_15 * V_16 ,
struct V_145 * V_146 ,
enum V_48 V_49 )
{
struct V_22 * V_23 = NULL ;
while ( F_78 ( V_16 , V_49 , V_146 , & V_23 ) ) {
if ( ! V_23 )
continue;
return V_23 ;
}
return NULL ;
}
static struct V_22 * F_84 ( struct V_15 * V_16 ,
struct V_145 * V_146 )
{
struct V_24 * V_25 = V_16 -> V_18 ;
struct V_26 * V_27 = F_5 ( V_25 ) ;
struct V_28 * V_29 ;
struct V_22 * V_23 ;
int V_148 ;
if ( F_27 ( & V_16 -> V_40 . V_54 ) ) {
V_16 -> V_40 . V_41 = NULL ;
return NULL ;
}
V_23 = F_20 ( & V_16 -> V_40 . V_54 , struct V_22 , V_55 ) ;
V_29 = V_23 -> V_32 ;
V_148 = F_85 ( V_25 , V_29 , V_146 ) ;
if ( V_148 == - V_149 ) {
struct V_145 V_151 ;
struct V_22 * V_60 ;
struct V_28 * V_152 ;
memset ( & V_151 , 0 , sizeof( V_151 ) ) ;
if ( F_86 ( & V_23 -> V_55 , & V_16 -> V_40 . V_54 ) ) {
V_16 -> V_40 . V_41 = NULL ;
return NULL ;
}
V_60 = F_87 ( V_23 -> V_55 . V_153 , struct V_22 , V_55 ) ;
V_152 = V_60 -> V_32 ;
V_148 = F_85 ( V_25 , V_152 , & V_151 ) ;
if ( V_148 == - V_149 )
return NULL ;
}
if ( ! V_23 -> V_36 )
return V_23 ;
F_80 ( V_16 -> V_57 , V_23 -> V_35 ,
V_27 -> V_39 ,
V_84 ) ;
return V_23 ;
}
static bool F_88 ( struct V_26 * V_27 ,
struct V_139 * V_140 ,
struct V_154 * V_155 ,
struct V_145 * V_156 ,
bool * V_157 )
{
struct V_15 * V_16 = (struct V_15 * ) V_27 -> V_158 ;
bool V_159 , V_160 , V_161 , V_162 ;
struct V_24 * V_25 = V_27 -> V_25 ;
T_3 V_163 ;
T_1 V_56 = V_25 -> V_19 . V_56 ;
V_163 = V_140 -> V_141 ;
V_159 = ! ! F_75 ( V_140 -> V_142 ) ;
V_160 = V_156 -> V_164 != V_165 &&
F_89 ( V_156 -> V_164 , V_27 -> V_166 ) ;
V_161 = V_160 && F_73 ( V_163 ) &&
F_90 ( V_163 ) &&
! ( V_156 -> V_167 &
( V_168 | V_169 | V_170 |
V_171 ) ) ;
if ( V_156 -> V_164 == V_165 ||
! F_89 ( V_156 -> V_164 , V_27 -> V_172 ) )
V_156 -> V_167 &= ~ V_171 ;
if ( ! V_156 -> V_173 ) {
F_91 ( V_174 ) ;
return false ;
}
if ( V_156 -> V_173 > ( V_27 -> V_39 - V_56 ) ) {
F_91 ( V_174 ) ;
return false ;
}
if ( V_156 -> V_175 )
return true ;
V_162 = V_160 && ! F_92 ( V_163 ) &&
! F_77 ( V_163 ) &&
! ( F_93 ( V_140 -> V_176 ) & V_177 ) &&
( V_156 -> V_167 & V_170 ) ;
if ( V_156 -> V_167 != 0 ) {
T_1 V_178 ;
if ( V_156 -> V_167 & V_169 ) {
V_155 -> V_179 |= V_180 ;
V_162 = false ;
}
if ( V_156 -> V_167 & V_181 )
return false ;
if ( ( V_156 -> V_167 & V_168 ) ||
( ! V_159 && ( V_156 -> V_167 & V_171 ) ) ) {
* V_157 = true ;
V_162 = false ;
}
V_178 = V_168 | V_170 |
V_171 ;
if ( V_25 -> V_92 && ( V_16 -> V_40 . V_89 & V_182 ) )
V_178 |= V_169 ;
if ( V_156 -> V_167 & ~ V_178 )
return false ;
}
if ( V_161 )
V_155 -> V_179 |= V_183 ;
else if ( V_159 && V_162 )
V_155 -> V_179 |= V_184 ;
return true ;
}
static int F_94 ( struct V_26 * V_27 ,
struct V_185 * V_105 ,
struct V_145 * V_156 ,
struct V_154 * V_155 )
{
struct V_186 * V_187 ;
enum V_188 V_189 ;
unsigned int V_67 = 0 ;
struct V_15 T_4 * V_16 = V_27 -> V_158 ;
V_189 = V_105 -> V_106 . V_190 -> V_189 ;
V_187 = V_105 -> V_191 -> V_192 [ V_189 ] ;
if ( V_156 -> V_193 & 0x80 ) {
V_155 -> V_179 |= V_194 ;
if ( V_156 -> V_195 & V_196 )
V_155 -> V_179 |= V_197 ;
if ( V_156 -> V_195 & V_198 )
V_155 -> V_179 |= V_199 ;
V_155 -> V_200 = V_156 -> V_193 & 0x7f ;
return 0 ;
}
for ( V_67 = 0 ; V_67 < V_187 -> V_201 ; V_67 ++ ) {
if ( V_187 -> V_202 [ V_67 ] . V_203 == V_156 -> V_193 ) {
V_155 -> V_200 = V_67 ;
return 0 ;
}
if ( V_187 -> V_202 [ V_67 ] . V_204 == V_156 -> V_193 ) {
V_155 -> V_179 |= V_205 ;
V_155 -> V_200 = V_67 ;
return 0 ;
}
}
F_28 ( V_27 , V_206 ,
L_13 ,
V_156 -> V_193 ) ;
F_91 ( V_207 ) ;
return - V_150 ;
}
static void F_95 ( struct V_26 * V_27 ,
struct V_185 * V_105 ,
struct V_139 * V_140 ,
struct V_145 * V_156 )
{
struct V_15 * V_16 = V_105 -> V_158 ;
struct V_24 * V_25 = V_27 -> V_25 ;
int V_208 ;
int V_209 = V_156 -> V_210 ;
if ( ! V_156 -> V_211 ||
( ( V_25 -> V_96 != V_97 ) &&
( V_25 -> V_96 != V_212 ) ) )
return;
if ( V_156 -> V_210 != V_213 && ! V_156 -> V_214 )
F_96 ( V_16 -> V_208 , V_156 -> V_210 ) ;
V_208 = V_16 -> V_208 ;
if ( F_97 ( V_208 != V_215 ) )
V_209 = F_98 ( V_208 , V_216 ) ;
if ( V_209 < 0 )
V_209 = 0 ;
V_25 -> V_217 . V_218 = V_209 ;
}
static int F_99 ( struct V_26 * V_27 ,
struct V_185 * V_105 ,
struct V_139 * V_140 ,
struct V_145 * V_156 ,
struct V_154 * V_219 ,
bool * V_157 )
{
struct V_24 * V_25 = V_27 -> V_25 ;
if ( ! F_88 ( V_27 , V_140 , V_219 , V_156 , V_157 ) )
return - V_150 ;
if ( V_156 -> V_175 )
return 0 ;
F_95 ( V_27 , V_105 , V_140 , V_156 ) ;
if ( F_94 ( V_27 , V_105 , V_156 , V_219 ) )
return - V_150 ;
V_219 -> V_189 = V_105 -> V_106 . V_190 -> V_189 ;
V_219 -> V_220 = V_105 -> V_106 . V_190 -> V_221 ;
V_219 -> signal = V_25 -> V_222 + V_156 -> V_210 ;
V_219 -> V_43 = V_156 -> V_223 ;
V_219 -> V_179 |= V_224 ;
if ( V_156 -> V_214 )
V_219 -> V_179 |= V_225 ;
return 0 ;
}
static void F_100 ( struct V_26 * V_27 ,
struct V_30 * V_31 ,
struct V_145 * V_156 ,
struct V_154 * V_155 ,
bool V_157 )
{
struct V_24 * V_25 = V_27 -> V_25 ;
struct V_139 * V_140 ;
int V_226 , V_227 , V_228 ;
T_1 V_229 ;
T_3 V_163 ;
V_140 = (struct V_139 * ) V_31 -> V_38 ;
V_226 = F_101 ( V_31 ) ;
V_163 = V_140 -> V_141 ;
V_227 = F_102 ( V_140 -> V_141 ) ;
V_228 = V_227 & 3 ;
if ( V_228 && V_31 -> V_129 >= V_227 + V_228 + V_230 ) {
memmove ( V_31 -> V_38 + V_228 , V_31 -> V_38 , V_227 ) ;
F_103 ( V_31 , V_228 ) ;
}
V_229 = V_156 -> V_164 ;
if ( ! ( V_229 == V_165 ) && ! V_157 &&
F_90 ( V_163 ) ) {
V_155 -> V_179 |= V_231 ;
} else if ( F_90 ( V_163 )
&& ! V_157 && V_31 -> V_129 >= V_226 + 4 ) {
V_229 = V_31 -> V_38 [ V_226 + 3 ] >> 6 ;
if ( F_89 ( V_229 , V_27 -> V_232 ) )
V_155 -> V_179 |= V_231 ;
}
if ( V_25 -> V_233 &&
( V_155 -> V_179 & V_231 ) &&
F_104 ( V_163 ) )
V_155 -> V_179 &= ~ V_231 ;
}
static void F_105 ( struct V_234 * V_235 ,
struct V_236 V_237 ,
int V_4 )
{
V_235 -> V_238 = 0 ;
if ( V_237 . V_239 == V_13 )
V_235 -> V_240 = V_4 ;
else if ( V_237 . V_239 == V_14 )
V_235 -> V_241 = V_4 ;
switch ( ( V_237 . V_239 << 4 ) | V_237 . V_242 ) {
case 0x10 :
V_235 -> V_243 = V_244 ;
V_235 -> V_245 =
V_246 ;
V_235 -> V_247 = V_14 ;
break;
case 0x20 :
V_235 -> V_243 = V_244 ;
V_235 -> V_245 =
V_246 ;
V_235 -> V_247 = V_13 ;
break;
case 0x21 :
V_235 -> V_243 = V_13 ;
V_235 -> V_245 =
V_244 ;
V_235 -> V_247 =
V_246 ;
break;
case 0x12 :
V_235 -> V_243 = V_14 ;
V_235 -> V_245 =
V_244 ;
V_235 -> V_247 =
V_246 ;
break;
case 0x13 :
V_235 -> V_243 = V_246 ;
V_235 -> V_245 =
V_244 ;
V_235 -> V_247 = V_14 ;
break;
case 0x23 :
V_235 -> V_243 = V_246 ;
V_235 -> V_245 =
V_244 ;
V_235 -> V_247 = V_13 ;
break;
default:
break;
}
}
static void F_106 ( struct V_234 * V_235 ,
struct V_236 * V_248 ,
int V_4 , int V_5 ,
int V_1 )
{
switch ( V_235 -> V_238 ) {
case 0 :
V_248 -> V_239 = V_235 -> V_243 ;
V_248 -> V_242 = V_235 -> V_245 ;
break;
case 1 :
V_248 -> V_239 = V_235 -> V_243 ;
V_248 -> V_242 = V_235 -> V_247 ;
V_235 -> V_249 = V_4 ;
V_235 -> V_250 = V_5 ;
if ( V_235 -> V_243 == V_14 ) {
if ( F_1 ( V_1 ,
V_251 ,
V_252 ,
V_4 , V_5 ,
V_235 -> V_253 ) )
V_235 -> V_254 = true ;
else
V_235 -> V_254 = false ;
} else if ( V_235 -> V_243 == V_13 ) {
if ( F_1 ( V_1 ,
V_255 ,
V_252 ,
V_4 , V_5 ,
V_235 -> V_253 ) )
V_235 -> V_254 = true ;
else
V_235 -> V_254 = false ;
} else {
if ( ( ( ( V_1 >= V_7 ) &&
( V_5 > V_4 +
V_251 ) ) ||
( V_5 > V_4 ) ) &&
( V_235 -> V_253 > 50 ) )
V_235 -> V_254 = true ;
else
V_235 -> V_254 = false ;
}
break;
case 2 :
V_235 -> V_256 = false ;
V_235 -> V_257 = false ;
V_235 -> V_258 = false ;
V_235 -> V_249 = V_4 ;
V_235 -> V_259 = V_5 ;
if ( V_235 -> V_247 == V_14 )
V_235 -> V_241 = V_5 ;
else if ( V_235 -> V_247 ==
V_13 )
V_235 -> V_240 = V_5 ;
else if ( V_235 -> V_247 ==
V_246 ) {
if ( V_235 -> V_243 == V_13 )
V_235 -> V_240 = V_4 ;
else if ( V_235 -> V_243 == V_14 )
V_235 -> V_241 = V_4 ;
}
if ( V_235 -> V_240 > V_235 -> V_241 +
V_260 )
V_248 -> V_239 = V_13 ;
else
V_248 -> V_239 = V_14 ;
if ( V_235 -> V_243 == V_14 ) {
if ( F_1 ( V_1 ,
V_251 ,
V_252 ,
V_4 , V_5 ,
V_235 -> V_253 ) )
V_235 -> V_261 = true ;
else
V_235 -> V_261 = false ;
} else if ( V_235 -> V_243 == V_13 ) {
if ( F_1 ( V_1 ,
V_255 ,
V_252 ,
V_4 , V_5 ,
V_235 -> V_253 ) )
V_235 -> V_261 = true ;
else
V_235 -> V_261 = false ;
} else {
if ( ( ( ( V_1 >= V_7 ) &&
( V_5 > V_4 +
V_251 ) ) ||
( V_5 > V_4 ) ) &&
( V_235 -> V_253 > 50 ) )
V_235 -> V_261 = true ;
else
V_235 -> V_261 = false ;
}
if ( V_235 -> V_254 && V_235 -> V_261 ) {
if ( V_235 -> V_250 > V_235 -> V_259 ) {
if ( ( V_235 -> V_245 ==
V_14 ) ||
( V_235 -> V_245 ==
V_13 ) )
if ( V_248 -> V_239 ==
V_13 )
V_248 -> V_242 =
V_14 ;
else
V_248 -> V_242 =
V_13 ;
else
V_248 -> V_242 =
V_235 -> V_245 ;
} else if ( ( V_235 -> V_247 ==
V_14 ) ||
( V_235 -> V_247 ==
V_13 ) ) {
if ( V_248 -> V_239 ==
V_13 )
V_248 -> V_242 =
V_14 ;
else
V_248 -> V_242 =
V_13 ;
} else {
V_248 -> V_242 =
V_235 -> V_247 ;
}
} else if ( V_235 -> V_254 ) {
if ( ( V_235 -> V_245 ==
V_14 ) ||
( V_235 -> V_245 ==
V_13 ) )
if ( V_248 -> V_239 ==
V_13 )
V_248 -> V_242 =
V_14 ;
else
V_248 -> V_242 =
V_13 ;
else
V_248 -> V_242 =
V_235 -> V_245 ;
} else if ( V_235 -> V_261 ) {
if ( ( V_235 -> V_247 ==
V_14 ) ||
( V_235 -> V_247 ==
V_13 ) )
if ( V_248 -> V_239 ==
V_13 )
V_248 -> V_242 =
V_14 ;
else
V_248 -> V_242 =
V_13 ;
else
V_248 -> V_242 =
V_235 -> V_247 ;
} else {
if ( ( V_235 -> V_243 == V_14 ) ||
( V_235 -> V_243 == V_13 ) )
if ( V_248 -> V_239 ==
V_13 )
V_248 -> V_242 =
V_14 ;
else
V_248 -> V_242 =
V_13 ;
else
V_248 -> V_242 = V_235 -> V_243 ;
}
break;
default:
break;
}
}
static void F_107 ( struct V_236 * V_237 ,
struct V_234 * V_235 , int V_1 )
{
if ( V_237 -> V_8 == 0 ) {
switch ( ( V_237 -> V_239 << 4 ) |
V_237 -> V_242 ) {
case 0x01 :
V_237 -> V_262 = 0x3b ;
break;
case 0x02 :
V_237 -> V_262 = 0x3d ;
break;
case 0x03 :
V_237 -> V_262 = 0x1 ;
break;
case 0x10 :
V_237 -> V_262 = 0x7 ;
break;
case 0x12 :
V_237 -> V_262 = 0x2 ;
break;
case 0x13 :
V_237 -> V_262 = 0x7 ;
break;
case 0x20 :
V_237 -> V_262 = 0x6 ;
break;
case 0x21 :
V_237 -> V_262 = 0x0 ;
break;
case 0x23 :
V_237 -> V_262 = 0x6 ;
break;
case 0x30 :
V_237 -> V_262 = 0x1 ;
break;
case 0x31 :
V_237 -> V_262 = 0x3b ;
break;
case 0x32 :
V_237 -> V_262 = 0x3d ;
break;
default:
break;
}
} else if ( V_237 -> V_8 == 1 ) {
switch ( ( V_237 -> V_239 << 4 ) |
V_237 -> V_242 ) {
case 0x01 :
V_237 -> V_262 = 0x1 ;
V_237 -> V_263 = 0 ;
V_237 -> V_264 = 0 ;
break;
case 0x02 :
V_237 -> V_262 = 0x1 ;
V_237 -> V_263 = 0 ;
V_237 -> V_264 = 0 ;
break;
case 0x03 :
V_237 -> V_262 = 0x1 ;
V_237 -> V_263 = 0 ;
V_237 -> V_264 = 0 ;
break;
case 0x10 :
if ( ! ( V_235 -> V_258 ) &&
( V_1 > V_12 ) )
V_237 -> V_262 = 0x3f ;
else
V_237 -> V_262 = 0x1 ;
V_237 -> V_263 = 0 ;
V_237 -> V_264 = 0 ;
break;
case 0x12 :
V_237 -> V_262 = 0x1 ;
V_237 -> V_263 = 0 ;
V_237 -> V_264 = 0 ;
break;
case 0x13 :
if ( ! ( V_235 -> V_258 ) &&
( V_1 > V_12 ) )
V_237 -> V_262 = 0x3f ;
else
V_237 -> V_262 = 0x1 ;
V_237 -> V_263 = 0 ;
V_237 -> V_264 = 0 ;
break;
case 0x20 :
if ( ! ( V_235 -> V_258 ) &&
( V_1 > V_12 ) )
V_237 -> V_262 = 0x3f ;
else
V_237 -> V_262 = 0x1 ;
V_237 -> V_263 = 0 ;
V_237 -> V_264 = 0 ;
break;
case 0x21 :
V_237 -> V_262 = 0x1 ;
V_237 -> V_263 = 0 ;
V_237 -> V_264 = 0 ;
break;
case 0x23 :
if ( ! ( V_235 -> V_258 ) &&
( V_1 > V_12 ) )
V_237 -> V_262 = 0x3f ;
else
V_237 -> V_262 = 0x1 ;
V_237 -> V_263 = 0 ;
V_237 -> V_264 = 0 ;
break;
case 0x30 :
V_237 -> V_262 = 0x1 ;
V_237 -> V_263 = 0 ;
V_237 -> V_264 = 0 ;
break;
case 0x31 :
V_237 -> V_262 = 0x1 ;
V_237 -> V_263 = 0 ;
V_237 -> V_264 = 0 ;
break;
case 0x32 :
V_237 -> V_262 = 0x1 ;
V_237 -> V_263 = 0 ;
V_237 -> V_264 = 0 ;
break;
default:
break;
}
} else if ( V_237 -> V_8 == 2 ) {
switch ( ( V_237 -> V_239 << 4 ) |
V_237 -> V_242 ) {
case 0x01 :
V_237 -> V_262 = 0x1 ;
V_237 -> V_263 = 0 ;
V_237 -> V_264 = 0 ;
break;
case 0x02 :
V_237 -> V_262 = 0x1 ;
V_237 -> V_263 = 0 ;
V_237 -> V_264 = 0 ;
break;
case 0x03 :
V_237 -> V_262 = 0x1 ;
V_237 -> V_263 = 0 ;
V_237 -> V_264 = 0 ;
break;
case 0x10 :
if ( ! ( V_235 -> V_258 ) &&
( V_1 > V_12 ) )
V_237 -> V_262 = 0x1 ;
else
V_237 -> V_262 = 0x2 ;
V_237 -> V_263 = 0 ;
V_237 -> V_264 = 0 ;
break;
case 0x12 :
V_237 -> V_262 = 0x1 ;
V_237 -> V_263 = 0 ;
V_237 -> V_264 = 0 ;
break;
case 0x13 :
if ( ! ( V_235 -> V_258 ) &&
( V_1 > V_12 ) )
V_237 -> V_262 = 0x1 ;
else
V_237 -> V_262 = 0x2 ;
V_237 -> V_263 = 0 ;
V_237 -> V_264 = 0 ;
break;
case 0x20 :
if ( ! ( V_235 -> V_258 ) &&
( V_1 > V_12 ) )
V_237 -> V_262 = 0x1 ;
else
V_237 -> V_262 = 0x2 ;
V_237 -> V_263 = 0 ;
V_237 -> V_264 = 0 ;
break;
case 0x21 :
V_237 -> V_262 = 0x1 ;
V_237 -> V_263 = 0 ;
V_237 -> V_264 = 0 ;
break;
case 0x23 :
if ( ! ( V_235 -> V_258 ) &&
( V_1 > V_12 ) )
V_237 -> V_262 = 0x1 ;
else
V_237 -> V_262 = 0x2 ;
V_237 -> V_263 = 0 ;
V_237 -> V_264 = 0 ;
break;
case 0x30 :
V_237 -> V_262 = 0x1 ;
V_237 -> V_263 = 0 ;
V_237 -> V_264 = 0 ;
break;
case 0x31 :
V_237 -> V_262 = 0x1 ;
V_237 -> V_263 = 0 ;
V_237 -> V_264 = 0 ;
break;
case 0x32 :
V_237 -> V_262 = 0x1 ;
V_237 -> V_263 = 0 ;
V_237 -> V_264 = 0 ;
break;
default:
break;
}
}
}
static void F_108 ( struct V_15 * V_16 , struct V_145 * V_146 )
{
struct V_236 V_248 ;
struct V_234 * V_235 = & V_16 -> V_265 ;
int V_1 = 0 , V_5 = 0 , V_4 = 0 , V_10 ;
int V_9 ;
int V_266 = V_146 -> V_267 ;
int V_268 = V_146 -> V_269 ;
int V_270 , V_271 ;
bool V_272 = false ;
V_270 = ( V_146 -> V_273 >> V_274 ) &
V_275 ;
V_271 = ( V_146 -> V_273 >> V_276 ) &
V_275 ;
if ( V_266 > 0 && V_268 > 0 ) {
V_235 -> V_253 ++ ;
V_235 -> V_277 += V_266 ;
V_235 -> V_278 += V_268 ;
if ( V_271 == V_270 )
V_235 -> V_279 ++ ;
else
V_235 -> V_280 ++ ;
}
if ( V_235 -> V_258 && V_235 -> V_256 ) {
if ( F_109 ( V_281 , V_235 -> V_282 +
F_110 ( V_283 ) ) )
V_272 = true ;
else
if ( V_235 -> V_253 ==
V_284 ) {
V_1 = ( ( V_235 -> V_280 * 100 ) /
V_235 -> V_253 ) ;
if ( V_1 < V_12 )
V_272 = true ;
}
}
if ( ( ( V_235 -> V_253 < V_285 ) ||
V_146 -> V_214 ) && ! V_272 )
return;
if ( V_235 -> V_253 ) {
V_1 = ( ( V_235 -> V_280 * 100 ) /
V_235 -> V_253 ) ;
V_4 = ( V_235 -> V_277 /
V_235 -> V_253 ) ;
V_5 = ( V_235 -> V_278 /
V_235 -> V_253 ) ;
}
F_111 ( V_16 -> V_18 , & V_248 ) ;
V_10 = V_248 . V_242 ;
V_9 = V_248 . V_239 ;
V_235 -> V_286 ++ ;
if ( V_235 -> V_286 == V_287 ) {
if ( V_1 > V_12 ) {
F_105 ( V_235 , V_248 ,
V_4 ) ;
V_235 -> V_256 = true ;
} else {
V_235 -> V_256 = false ;
}
V_235 -> V_286 = 0 ;
V_235 -> V_258 = true ;
V_235 -> V_257 = true ;
}
if ( ! V_235 -> V_258 ) {
if ( F_2 ( V_248 . V_8 ,
V_1 , V_9 , V_10 ,
V_5 , V_4 ) ) {
if ( V_10 == V_13 ) {
V_248 . V_239 =
V_13 ;
V_248 . V_242 =
V_14 ;
} else if ( V_10 == V_14 ) {
V_248 . V_239 =
V_14 ;
V_248 . V_242 =
V_13 ;
}
goto V_288;
} else if ( ( V_10 != V_14 ) &&
( V_10 != V_13 ) ) {
if ( V_9 == V_13 )
V_248 . V_242 =
V_14 ;
else if ( V_9 == V_14 )
V_248 . V_242 =
V_13 ;
goto V_288;
}
if ( ( V_5 < ( V_4 +
V_248 . V_289 ) ) )
goto V_288;
}
if ( ! V_235 -> V_257 ) {
switch ( V_10 ) {
case V_13 :
V_235 -> V_240 = V_5 ;
V_235 -> V_241 = V_4 ;
V_235 -> V_258 = true ;
V_248 . V_239 =
V_14 ;
V_248 . V_242 =
V_246 ;
break;
case V_14 :
V_235 -> V_241 = V_5 ;
V_235 -> V_240 = V_4 ;
V_235 -> V_258 = true ;
V_248 . V_239 = V_13 ;
V_248 . V_242 =
V_246 ;
break;
case V_246 :
V_235 -> V_290 = V_5 ;
V_235 -> V_258 = true ;
V_248 . V_242 =
V_244 ;
break;
case V_244 :
V_235 -> V_291 = V_5 ;
V_235 -> V_258 = false ;
if ( V_235 -> V_240 >
( V_235 -> V_241 +
V_260 ) ) {
if ( ( V_235 -> V_290 > V_235 -> V_241 ) &&
( V_235 -> V_290 > V_235 -> V_291 ) ) {
V_248 . V_239 =
V_13 ;
V_248 . V_242 =
V_246 ;
} else if ( V_235 -> V_291 >
V_235 -> V_241 ) {
V_248 . V_239 =
V_13 ;
V_248 . V_242 =
V_244 ;
} else {
V_248 . V_239 =
V_13 ;
V_248 . V_242 =
V_14 ;
}
} else {
if ( ( V_235 -> V_290 > V_235 -> V_240 ) &&
( V_235 -> V_290 > V_235 -> V_291 ) ) {
V_248 . V_239 =
V_14 ;
V_248 . V_242 =
V_246 ;
} else if ( V_235 -> V_291 >
V_235 -> V_241 ) {
V_248 . V_239 =
V_14 ;
V_248 . V_242 =
V_244 ;
} else {
V_248 . V_239 =
V_14 ;
V_248 . V_242 =
V_13 ;
}
}
break;
default:
break;
}
} else {
if ( ! V_235 -> V_256 ) {
V_235 -> V_257 = false ;
if ( V_9 == V_13 ) {
V_248 . V_239 =
V_13 ;
V_248 . V_242 =
V_14 ;
} else if ( V_9 == V_14 ) {
V_248 . V_239 =
V_14 ;
V_248 . V_242 =
V_13 ;
}
goto V_288;
}
}
F_106 ( V_235 , & V_248 ,
V_4 , V_5 ,
V_1 ) ;
V_235 -> V_238 ++ ;
V_288:
F_107 ( & V_248 , V_235 , V_1 ) ;
F_112 ( V_16 -> V_18 , & V_248 ) ;
V_235 -> V_282 = V_281 ;
V_235 -> V_253 = 0 ;
V_235 -> V_277 = 0 ;
V_235 -> V_278 = 0 ;
V_235 -> V_279 = 0 ;
V_235 -> V_280 = 0 ;
}
int F_68 ( struct V_15 * V_16 , int V_292 , bool V_293 )
{
struct V_22 * V_23 ;
struct V_30 * V_31 = NULL , * V_294 , * V_295 ;
struct V_154 * V_155 ;
struct V_24 * V_25 = V_16 -> V_18 ;
struct V_26 * V_27 = F_5 ( V_25 ) ;
struct V_185 * V_105 = V_16 -> V_105 ;
struct V_139 * V_140 ;
int V_296 ;
bool V_157 = false ;
struct V_145 V_146 ;
enum V_48 V_49 ;
bool V_297 = ! ! ( V_25 -> V_19 . V_20 & V_79 ) ;
int V_298 ;
T_1 V_56 = V_25 -> V_19 . V_56 ;
T_5 V_299 = 0 ;
T_2 V_300 = 0 ;
unsigned long V_301 ;
if ( V_297 )
V_298 = V_64 ;
else
V_298 = V_84 ;
V_49 = V_293 ? V_63 : V_62 ;
F_50 ( & V_16 -> V_40 . V_73 ) ;
V_299 = F_113 ( V_25 ) ;
V_300 = V_299 & 0xffffffff ;
do {
if ( ( V_16 -> V_74 & V_77 ) && ( V_292 == 0 ) )
break;
memset ( & V_146 , 0 , sizeof( V_146 ) ) ;
if ( V_297 )
V_23 = F_83 ( V_16 , & V_146 , V_49 ) ;
else
V_23 = F_84 ( V_16 , & V_146 ) ;
if ( ! V_23 )
break;
V_31 = V_23 -> V_36 ;
if ( ! V_31 )
continue;
if ( V_16 -> V_40 . V_302 )
V_295 = V_16 -> V_40 . V_302 ;
else
V_295 = V_31 ;
V_140 = (struct V_139 * ) ( V_295 -> V_38 + V_56 ) ;
V_155 = F_114 ( V_295 ) ;
if ( F_115 ( V_140 -> V_141 ) ) {
F_91 ( V_303 ) ;
if ( ! F_116 ( V_27 -> V_304 ) &&
F_117 ( V_140 -> V_305 , V_27 -> V_304 ) )
V_146 . V_211 = true ;
else
V_146 . V_211 = false ;
}
else
V_146 . V_211 = false ;
F_118 ( V_16 , & V_146 ) ;
if ( V_16 -> V_74 & V_77 ) {
F_91 ( V_306 ) ;
goto V_307;
}
memset ( V_155 , 0 , sizeof( struct V_154 ) ) ;
V_155 -> V_308 = ( V_299 & ~ 0xffffffffULL ) | V_146 . V_309 ;
if ( V_146 . V_309 > V_300 &&
F_46 ( V_146 . V_309 - V_300 > 0x10000000 ) )
V_155 -> V_308 -= 0x100000000ULL ;
if ( V_146 . V_309 < V_300 &&
F_46 ( V_300 - V_146 . V_309 > 0x10000000 ) )
V_155 -> V_308 += 0x100000000ULL ;
V_296 = F_99 ( V_27 , V_105 , V_140 , & V_146 ,
V_155 , & V_157 ) ;
if ( V_296 )
goto V_307;
if ( V_146 . V_211 ) {
V_16 -> V_310 = 0 ;
F_119 ( V_16 , 3 ) ;
}
V_294 = F_44 ( V_27 , V_27 -> V_39 , V_311 ) ;
if ( ! V_294 ) {
F_91 ( V_312 ) ;
goto V_307;
}
F_35 ( V_16 -> V_57 , V_23 -> V_35 ,
V_27 -> V_39 ,
V_298 ) ;
F_120 ( V_31 , V_146 . V_173 + V_25 -> V_19 . V_56 ) ;
if ( V_25 -> V_19 . V_56 )
F_103 ( V_31 , V_25 -> V_19 . V_56 ) ;
if ( ! V_146 . V_175 )
F_100 ( V_27 , V_295 , & V_146 ,
V_155 , V_157 ) ;
V_23 -> V_36 = V_294 ;
V_23 -> V_35 = F_45 ( V_16 -> V_57 , V_294 -> V_38 ,
V_27 -> V_39 ,
V_298 ) ;
if ( F_46 ( F_47 ( V_16 -> V_57 ,
V_23 -> V_35 ) ) ) {
F_36 ( V_294 ) ;
V_23 -> V_36 = NULL ;
V_23 -> V_35 = 0 ;
F_48 ( V_27 , L_14 ) ;
F_121 ( V_105 , V_31 ) ;
break;
}
if ( V_146 . V_175 ) {
F_91 ( V_313 ) ;
if ( V_16 -> V_40 . V_302 ) {
F_36 ( V_16 -> V_40 . V_302 ) ;
F_36 ( V_31 ) ;
F_91 ( V_314 ) ;
V_31 = NULL ;
}
V_16 -> V_40 . V_302 = V_31 ;
goto V_315;
}
if ( V_16 -> V_40 . V_302 ) {
int V_316 = V_31 -> V_129 - F_122 ( V_295 ) ;
if ( F_123 ( V_295 , 0 , V_316 , V_311 ) < 0 ) {
F_59 ( V_31 ) ;
F_91 ( V_312 ) ;
goto V_307;
}
V_16 -> V_40 . V_302 = NULL ;
F_124 ( V_31 , F_120 ( V_295 , V_31 -> V_129 ) ,
V_31 -> V_129 ) ;
F_36 ( V_31 ) ;
V_31 = V_295 ;
}
if ( V_25 -> V_19 . V_20 & V_317 ) {
if ( V_16 -> V_40 . V_44 != V_146 . V_223 ) {
if ( ++ V_16 -> V_40 . V_45 >= 3 )
F_10 ( V_16 , V_146 . V_223 ) ;
} else {
V_16 -> V_40 . V_45 = 0 ;
}
}
if ( V_155 -> V_179 & V_183 )
F_125 ( V_31 , V_31 -> V_129 - 8 ) ;
F_126 ( & V_16 -> V_318 , V_301 ) ;
if ( ( V_16 -> V_133 & ( V_134 |
V_137 |
V_143 ) ) ||
F_3 ( V_16 ) )
F_72 ( V_16 , V_31 , V_146 . V_211 ) ;
F_127 ( & V_16 -> V_318 , V_301 ) ;
if ( ( V_25 -> V_19 . V_20 & V_317 ) && V_16 -> V_319 == 3 )
F_108 ( V_16 , & V_146 ) ;
F_121 ( V_105 , V_31 ) ;
V_307:
if ( V_16 -> V_40 . V_302 ) {
F_36 ( V_16 -> V_40 . V_302 ) ;
V_16 -> V_40 . V_302 = NULL ;
}
V_315:
if ( V_297 ) {
F_32 ( & V_23 -> V_55 , & V_16 -> V_40 . V_54 ) ;
F_18 ( V_16 , V_49 ) ;
} else {
F_128 ( & V_23 -> V_55 , & V_16 -> V_40 . V_54 ) ;
F_4 ( V_16 , V_23 ) ;
if ( ! V_292 )
F_51 ( V_25 ) ;
}
} while ( 1 );
F_53 ( & V_16 -> V_40 . V_73 ) ;
if ( ! ( V_25 -> V_320 & V_321 ) ) {
V_25 -> V_320 |= ( V_321 | V_322 ) ;
F_129 ( V_25 ) ;
}
return 0 ;
}
