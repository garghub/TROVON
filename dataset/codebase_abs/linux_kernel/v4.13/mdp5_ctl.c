static inline
struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static inline
void F_4 ( struct V_9 * V_10 , T_1 V_11 , T_1 V_12 )
{
struct V_1 * V_1 = F_1 ( V_10 -> V_13 ) ;
( void ) V_10 -> V_14 ;
F_5 ( V_1 , V_11 , V_12 ) ;
}
static inline
T_1 F_6 ( struct V_9 * V_10 , T_1 V_11 )
{
struct V_1 * V_1 = F_1 ( V_10 -> V_13 ) ;
( void ) V_10 -> V_14 ;
return F_7 ( V_1 , V_11 ) ;
}
static void F_8 ( struct V_1 * V_1 ,
struct V_15 * V_16 )
{
unsigned long V_17 ;
T_1 V_18 ;
F_9 ( & V_1 -> V_19 , V_17 ) ;
V_18 = F_7 ( V_1 , V_20 ) ;
switch ( V_16 -> V_21 ) {
case 0 :
V_18 &= ~ V_22 ;
V_18 |= F_10 ( V_16 -> type ) ;
break;
case 1 :
V_18 &= ~ V_23 ;
V_18 |= F_11 ( V_16 -> type ) ;
break;
case 2 :
V_18 &= ~ V_24 ;
V_18 |= F_12 ( V_16 -> type ) ;
break;
case 3 :
V_18 &= ~ V_25 ;
V_18 |= F_13 ( V_16 -> type ) ;
break;
default:
F_14 () ;
break;
}
F_5 ( V_1 , V_20 , V_18 ) ;
F_15 ( & V_1 -> V_19 , V_17 ) ;
}
static void F_16 ( struct V_9 * V_10 , struct V_26 * V_27 )
{
unsigned long V_17 ;
struct V_15 * V_16 = V_27 -> V_16 ;
T_1 V_28 = 0 ;
if ( ! F_17 ( V_16 -> type ) )
V_28 |= F_18 ( V_29 + V_16 -> V_21 ) ;
switch ( V_16 -> type ) {
case V_30 :
if ( V_16 -> V_31 == V_32 )
V_28 |= V_33 ;
break;
case V_34 :
if ( V_16 -> V_31 == V_35 )
V_28 |= F_19 ( V_36 ) ;
break;
default:
break;
}
if ( V_27 -> V_37 )
V_28 |= V_38 |
F_20 ( 1 ) ;
F_9 ( & V_10 -> V_39 , V_17 ) ;
F_4 ( V_10 , F_21 ( V_10 -> V_40 ) , V_28 ) ;
F_15 ( & V_10 -> V_39 , V_17 ) ;
}
int F_22 ( struct V_9 * V_10 , struct V_26 * V_27 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_27 -> V_16 ;
struct V_41 * V_42 = V_27 -> V_42 ;
struct V_41 * V_37 = V_27 -> V_37 ;
V_10 -> V_43 = F_23 ( V_42 -> V_44 ) |
F_24 ( V_16 ) ;
if ( V_37 )
V_10 -> V_43 |= F_23 ( V_37 -> V_44 ) ;
if ( ! F_17 ( V_16 -> type ) )
F_8 ( V_1 , V_16 ) ;
F_16 ( V_10 , V_27 ) ;
return 0 ;
}
static bool F_25 ( struct V_9 * V_10 ,
struct V_26 * V_27 )
{
struct V_15 * V_16 = V_27 -> V_16 ;
if ( ! V_10 -> V_45 || V_10 -> V_43 != 0 )
return false ;
switch ( V_16 -> type ) {
case V_34 :
return true ;
case V_30 :
return V_16 -> V_31 == V_32 ;
default:
return false ;
}
}
static void F_26 ( struct V_9 * V_10 )
{
unsigned long V_17 ;
F_9 ( & V_10 -> V_39 , V_17 ) ;
F_4 ( V_10 , F_27 ( V_10 -> V_40 ) , 1 ) ;
F_15 ( & V_10 -> V_39 , V_17 ) ;
}
static void F_28 ( struct V_9 * V_10 ,
struct V_26 * V_27 )
{
struct V_15 * V_16 = V_27 -> V_16 ;
struct V_41 * V_42 = V_27 -> V_42 ;
struct V_41 * V_37 = V_27 -> V_37 ;
V_10 -> V_43 = F_23 ( V_42 -> V_44 ) ;
if ( V_37 )
V_10 -> V_43 |= F_23 ( V_37 -> V_44 ) ;
if ( V_16 -> type == V_34 )
V_10 -> V_43 |= F_24 ( V_16 ) ;
}
int F_29 ( struct V_9 * V_10 ,
struct V_26 * V_27 ,
bool V_46 )
{
struct V_15 * V_16 = V_27 -> V_16 ;
if ( F_30 ( ! V_10 ) )
return - V_47 ;
V_10 -> V_45 = V_46 ;
F_31 ( L_1 , V_16 -> V_21 , V_46 ? L_2 : L_3 ) ;
if ( F_25 ( V_10 , V_27 ) ) {
F_26 ( V_10 ) ;
F_28 ( V_10 , V_27 ) ;
}
return 0 ;
}
int F_32 ( struct V_9 * V_10 , struct V_26 * V_27 ,
int V_48 , bool V_49 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
unsigned long V_17 ;
T_1 V_50 ;
struct V_41 * V_42 = V_27 -> V_42 ;
if ( F_33 ( F_30 ( ! V_42 ) ) ) {
F_34 ( V_3 -> V_6 -> V_6 , L_4 ,
V_10 -> V_40 ) ;
return - V_47 ;
}
if ( V_27 -> V_37 ) {
F_34 ( V_3 -> V_6 -> V_6 , L_5 ) ;
return - V_47 ;
}
F_9 ( & V_10 -> V_39 , V_17 ) ;
V_50 = F_6 ( V_10 , F_35 ( V_10 -> V_40 , V_42 -> V_44 ) ) ;
if ( V_49 )
V_50 |= V_51 ;
else
V_50 &= ~ V_51 ;
F_4 ( V_10 , F_35 ( V_10 -> V_40 , V_42 -> V_44 ) , V_50 ) ;
V_10 -> V_52 = V_49 ;
F_15 ( & V_10 -> V_39 , V_17 ) ;
V_10 -> V_53 = F_36 ( V_48 ) ;
return 0 ;
}
static T_1 F_37 ( enum V_54 V_55 ,
enum V_56 V_57 )
{
switch ( V_55 ) {
case V_58 : return F_38 ( V_57 ) ;
case V_59 : return F_39 ( V_57 ) ;
case V_60 : return F_40 ( V_57 ) ;
case V_61 : return F_41 ( V_57 ) ;
case V_62 : return F_42 ( V_57 ) ;
case V_63 : return F_43 ( V_57 ) ;
case V_64 : return F_44 ( V_57 ) ;
case V_65 : return F_45 ( V_57 ) ;
case V_66 : return F_46 ( V_57 ) ;
case V_67 : return F_47 ( V_57 ) ;
case V_68 :
case V_69 :
default: return 0 ;
}
}
static T_1 F_48 ( enum V_54 V_55 ,
enum V_56 V_57 )
{
if ( V_57 < V_70 && ( V_55 != V_68 && V_55 != V_69 ) )
return 0 ;
switch ( V_55 ) {
case V_58 : return V_71 ;
case V_59 : return V_72 ;
case V_60 : return V_73 ;
case V_61 : return V_74 ;
case V_62 : return V_75 ;
case V_63 : return V_76 ;
case V_64 : return V_77 ;
case V_65 : return V_78 ;
case V_66 : return V_79 ;
case V_67 : return V_80 ;
case V_68 : return F_49 ( V_57 ) ;
case V_69 : return F_50 ( V_57 ) ;
default: return 0 ;
}
}
static void F_51 ( struct V_9 * V_10 )
{
unsigned long V_17 ;
struct V_2 * V_3 = V_10 -> V_13 ;
int V_81 ;
F_9 ( & V_10 -> V_39 , V_17 ) ;
for ( V_81 = 0 ; V_81 < V_3 -> V_82 ; V_81 ++ ) {
F_4 ( V_10 , F_35 ( V_10 -> V_40 , V_81 ) , 0x0 ) ;
F_4 ( V_10 , F_52 ( V_10 -> V_40 , V_81 ) , 0x0 ) ;
}
F_15 ( & V_10 -> V_39 , V_17 ) ;
}
int F_53 ( struct V_9 * V_10 , struct V_26 * V_27 ,
enum V_54 V_57 [] [ V_83 ] ,
enum V_54 V_84 [] [ V_83 ] ,
T_1 V_85 , T_1 V_86 )
{
struct V_41 * V_42 = V_27 -> V_42 ;
struct V_41 * V_37 = V_27 -> V_37 ;
unsigned long V_17 ;
T_1 V_50 = 0 , V_87 = 0 ;
T_1 V_88 = 0 , V_89 = 0 ;
int V_81 , V_90 ;
F_51 ( V_10 ) ;
if ( V_86 & V_91 ) {
V_90 = V_92 ;
V_50 |= V_93 ;
if ( V_37 )
V_88 |= V_93 ;
} else {
V_90 = V_94 ;
}
for ( V_81 = V_90 ; V_85 && V_81 <= V_95 ; V_81 ++ ) {
V_50 |=
F_37 ( V_57 [ V_81 ] [ V_96 ] , V_81 ) |
F_37 ( V_57 [ V_81 ] [ V_97 ] , V_81 ) ;
V_87 |=
F_48 ( V_57 [ V_81 ] [ V_96 ] , V_81 ) |
F_48 ( V_57 [ V_81 ] [ V_97 ] , V_81 ) ;
if ( V_37 ) {
V_88 |=
F_37 ( V_84 [ V_81 ] [ V_96 ] , V_81 ) |
F_37 ( V_84 [ V_81 ] [ V_97 ] , V_81 ) ;
V_89 |=
F_48 ( V_84 [ V_81 ] [ V_96 ] , V_81 ) |
F_48 ( V_84 [ V_81 ] [ V_97 ] , V_81 ) ;
}
}
F_9 ( & V_10 -> V_39 , V_17 ) ;
if ( V_10 -> V_52 )
V_50 |= V_51 ;
F_4 ( V_10 , F_35 ( V_10 -> V_40 , V_42 -> V_44 ) , V_50 ) ;
F_4 ( V_10 , F_52 ( V_10 -> V_40 , V_42 -> V_44 ) ,
V_87 ) ;
if ( V_37 ) {
F_4 ( V_10 , F_35 ( V_10 -> V_40 , V_37 -> V_44 ) ,
V_88 ) ;
F_4 ( V_10 , F_52 ( V_10 -> V_40 , V_37 -> V_44 ) ,
V_89 ) ;
}
F_15 ( & V_10 -> V_39 , V_17 ) ;
V_10 -> V_53 = F_23 ( V_42 -> V_44 ) ;
if ( V_37 )
V_10 -> V_53 |= F_23 ( V_37 -> V_44 ) ;
F_31 ( L_6 , V_42 -> V_44 ,
V_50 , V_87 ) ;
if ( V_37 )
F_31 ( L_6 ,
V_37 -> V_44 , V_88 , V_89 ) ;
return 0 ;
}
T_1 F_24 ( struct V_15 * V_16 )
{
if ( V_16 -> type == V_34 )
return V_98 ;
switch ( V_16 -> V_21 ) {
case 0 : return V_99 ;
case 1 : return V_100 ;
case 2 : return V_101 ;
case 3 : return V_102 ;
default: return 0 ;
}
}
T_1 F_36 ( int V_48 )
{
switch ( V_48 ) {
case 0 : return V_103 ;
case 1 : return V_104 ;
default: return 0 ;
}
}
T_1 F_54 ( enum V_54 V_55 )
{
switch ( V_55 ) {
case V_58 : return V_105 ;
case V_59 : return V_106 ;
case V_60 : return V_107 ;
case V_61 : return V_108 ;
case V_62 : return V_109 ;
case V_63 : return V_110 ;
case V_64 : return V_111 ;
case V_65 : return V_112 ;
case V_66 : return V_113 ;
case V_67 : return V_114 ;
case V_68 : return V_103 ;
case V_69 : return V_104 ;
default: return 0 ;
}
}
T_1 F_23 ( int V_44 )
{
switch ( V_44 ) {
case 0 : return V_115 ;
case 1 : return V_116 ;
case 2 : return V_117 ;
case 5 : return V_118 ;
default: return 0 ;
}
}
static T_1 F_55 ( struct V_9 * V_10 , struct V_26 * V_27 ,
T_1 V_119 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
T_1 V_120 = 0 ;
#define F_56 ( T_2 ) \
(!(ctl_mgr->flush_hw_mask & bit) && (flush_mask & bit))
if ( F_56 ( V_103 ) )
V_120 |= F_23 ( V_27 -> V_42 -> V_44 ) ;
return V_120 ;
}
static void F_57 ( struct V_9 * V_10 , T_1 * V_119 ,
T_1 * V_121 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
if ( V_10 -> V_122 ) {
F_31 ( L_7 , V_10 -> V_40 , * V_119 ) ;
V_10 -> V_123 = true ;
V_3 -> V_124 |= ( * V_119 ) ;
* V_119 = 0 ;
if ( V_10 -> V_122 -> V_123 ) {
* V_121 = F_58 ( T_1 , V_10 -> V_40 , V_10 -> V_122 -> V_40 ) ;
* V_119 = V_3 -> V_124 ;
V_10 -> V_123 = false ;
V_10 -> V_122 -> V_123 = false ;
V_3 -> V_124 = 0 ;
F_31 ( L_8 , * V_119 ,
* V_121 ) ;
}
}
}
T_1 F_59 ( struct V_9 * V_10 ,
struct V_26 * V_27 ,
T_1 V_119 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
unsigned long V_17 ;
T_1 V_121 = V_10 -> V_40 ;
T_1 V_125 ;
V_10 -> V_43 &= ~ V_119 ;
F_60 ( L_9 , V_119 ,
V_10 -> V_43 , V_10 -> V_53 ) ;
if ( V_10 -> V_53 & V_119 ) {
V_119 |= V_126 ;
V_10 -> V_53 = 0 ;
}
V_119 |= F_55 ( V_10 , V_27 , V_119 ) ;
V_119 &= V_3 -> V_127 ;
V_125 = V_119 ;
F_57 ( V_10 , & V_119 , & V_121 ) ;
if ( V_119 ) {
F_9 ( & V_10 -> V_39 , V_17 ) ;
F_4 ( V_10 , F_61 ( V_121 ) , V_119 ) ;
F_15 ( & V_10 -> V_39 , V_17 ) ;
}
if ( F_25 ( V_10 , V_27 ) ) {
F_26 ( V_10 ) ;
F_28 ( V_10 , V_27 ) ;
}
return V_125 ;
}
T_1 F_62 ( struct V_9 * V_10 )
{
return F_6 ( V_10 , F_61 ( V_10 -> V_40 ) ) ;
}
int F_63 ( struct V_9 * V_10 )
{
return F_30 ( ! V_10 ) ? - V_47 : V_10 -> V_40 ;
}
int F_64 ( struct V_9 * V_128 , struct V_9 * V_129 , bool V_49 )
{
struct V_2 * V_3 = V_128 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_3 -> V_130 )
return 0 ;
if ( ! V_49 ) {
V_128 -> V_122 = NULL ;
V_129 -> V_122 = NULL ;
F_5 ( V_1 , V_131 , 0 ) ;
return 0 ;
} else if ( ( V_128 -> V_122 != NULL ) || ( V_129 -> V_122 != NULL ) ) {
F_34 ( V_3 -> V_6 -> V_6 , L_10 ) ;
return - V_47 ;
} else if ( ! ( V_128 -> V_132 & V_129 -> V_132 & V_133 ) ) {
F_34 ( V_3 -> V_6 -> V_6 , L_11 ) ;
return - V_47 ;
}
V_128 -> V_122 = V_129 ;
V_129 -> V_122 = V_128 ;
F_5 ( V_1 , V_131 ,
V_134 ) ;
return 0 ;
}
struct V_9 * F_65 ( struct V_2 * V_3 ,
int V_135 )
{
struct V_9 * V_10 = NULL ;
const T_1 V_136 = V_137 | V_133 ;
T_1 V_138 = ( ( V_135 == 1 ) || ( V_135 == 2 ) ) ? V_133 : 0 ;
unsigned long V_17 ;
int V_139 ;
F_9 ( & V_3 -> V_140 , V_17 ) ;
for ( V_139 = 0 ; V_139 < V_3 -> V_141 ; V_139 ++ )
if ( ( V_3 -> V_142 [ V_139 ] . V_132 & V_136 ) == V_138 )
goto V_143;
F_66 ( V_3 -> V_6 -> V_6 ,
L_12 , V_135 ) ;
V_138 ^= V_133 ;
for ( V_139 = 0 ; V_139 < V_3 -> V_141 ; V_139 ++ )
if ( ( V_3 -> V_142 [ V_139 ] . V_132 & V_136 ) == V_138 )
goto V_143;
F_34 ( V_3 -> V_6 -> V_6 , L_13 ) ;
goto V_144;
V_143:
V_10 = & V_3 -> V_142 [ V_139 ] ;
V_10 -> V_132 |= V_137 ;
V_10 -> V_53 = 0 ;
F_31 ( L_14 , V_10 -> V_40 ) ;
V_144:
F_15 ( & V_3 -> V_140 , V_17 ) ;
return V_10 ;
}
void F_67 ( struct V_2 * V_3 )
{
unsigned long V_17 ;
int V_139 ;
for ( V_139 = 0 ; V_139 < V_3 -> V_141 ; V_139 ++ ) {
struct V_9 * V_10 = & V_3 -> V_142 [ V_139 ] ;
F_9 ( & V_10 -> V_39 , V_17 ) ;
F_4 ( V_10 , F_21 ( V_10 -> V_40 ) , 0 ) ;
F_15 ( & V_10 -> V_39 , V_17 ) ;
}
}
void F_68 ( struct V_2 * V_3 )
{
F_69 ( V_3 ) ;
}
struct V_2 * F_70 ( struct V_145 * V_6 ,
void T_3 * V_146 , struct V_147 * V_148 )
{
struct V_2 * V_3 ;
const struct V_149 * V_150 = F_71 ( V_148 ) ;
int V_151 = F_72 ( V_148 ) ;
const struct V_152 * V_153 = & V_150 -> V_10 ;
unsigned long V_17 ;
int V_139 , V_154 ;
V_3 = F_73 ( sizeof( * V_3 ) , V_155 ) ;
if ( ! V_3 ) {
F_34 ( V_6 -> V_6 , L_15 ) ;
V_154 = - V_156 ;
goto V_157;
}
if ( F_33 ( F_30 ( V_153 -> V_158 > V_159 ) ) ) {
F_34 ( V_6 -> V_6 , L_16 ,
V_153 -> V_158 ) ;
V_154 = - V_160 ;
goto V_157;
}
V_3 -> V_6 = V_6 ;
V_3 -> V_82 = V_150 -> V_44 . V_158 ;
V_3 -> V_141 = V_153 -> V_158 ;
V_3 -> V_127 = V_153 -> V_127 ;
F_74 ( & V_3 -> V_140 ) ;
F_9 ( & V_3 -> V_140 , V_17 ) ;
for ( V_139 = 0 ; V_139 < V_3 -> V_141 ; V_139 ++ ) {
struct V_9 * V_10 = & V_3 -> V_142 [ V_139 ] ;
if ( F_30 ( ! V_153 -> V_161 [ V_139 ] ) ) {
F_34 ( V_6 -> V_6 , L_17 , V_139 ) ;
V_154 = - V_47 ;
F_15 ( & V_3 -> V_140 , V_17 ) ;
goto V_157;
}
V_10 -> V_13 = V_3 ;
V_10 -> V_40 = V_139 ;
V_10 -> V_14 = V_153 -> V_161 [ V_139 ] ;
V_10 -> V_132 = 0 ;
F_74 ( & V_10 -> V_39 ) ;
}
if ( V_151 >= 3 ) {
V_3 -> V_130 = true ;
V_3 -> V_142 [ 0 ] . V_132 |= V_133 ;
V_3 -> V_142 [ 1 ] . V_132 |= V_133 ;
}
F_15 ( & V_3 -> V_140 , V_17 ) ;
F_31 ( L_18 , V_3 -> V_141 ) ;
return V_3 ;
V_157:
if ( V_3 )
F_68 ( V_3 ) ;
return F_75 ( V_154 ) ;
}
