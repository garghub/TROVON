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
static void F_16 ( struct V_9 * V_10 , struct V_15 * V_16 )
{
unsigned long V_17 ;
T_1 V_26 = 0 ;
if ( ! F_17 ( V_16 -> type ) )
V_26 |= F_18 ( V_27 + V_16 -> V_21 ) ;
switch ( V_16 -> type ) {
case V_28 :
if ( V_16 -> V_29 == V_30 )
V_26 |= V_31 ;
break;
case V_32 :
if ( V_16 -> V_29 == V_33 )
V_26 |= F_19 ( V_34 ) ;
break;
default:
break;
}
F_9 ( & V_10 -> V_35 , V_17 ) ;
F_4 ( V_10 , F_20 ( V_10 -> V_36 ) , V_26 ) ;
F_15 ( & V_10 -> V_35 , V_17 ) ;
}
int F_21 ( struct V_9 * V_10 ,
struct V_15 * V_16 , int V_37 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( F_22 ( F_23 ( V_16 -> V_21 != V_10 -> V_38 . V_16 . V_21 ) ) ) {
F_24 ( V_1 -> V_6 -> V_6 ,
L_1 ,
V_10 -> V_36 , V_10 -> V_38 . V_16 . V_21 , V_16 -> V_21 ) ;
return - V_39 ;
}
V_10 -> V_37 = V_37 ;
memcpy ( & V_10 -> V_38 . V_16 , V_16 , sizeof( * V_16 ) ) ;
V_10 -> V_38 . V_40 = F_25 ( V_10 -> V_37 ) |
F_26 ( V_16 ) ;
if ( ! F_17 ( V_16 -> type ) )
F_8 ( V_1 , V_16 ) ;
F_16 ( V_10 , V_16 ) ;
return 0 ;
}
static bool F_27 ( struct V_9 * V_10 )
{
struct V_41 * V_38 = & V_10 -> V_38 ;
if ( ! V_38 -> V_42 || V_38 -> V_40 != 0 )
return false ;
switch ( V_38 -> V_16 . type ) {
case V_32 :
return true ;
case V_28 :
return V_38 -> V_16 . V_29 == V_30 ;
default:
return false ;
}
}
static void F_28 ( struct V_9 * V_10 )
{
unsigned long V_17 ;
F_9 ( & V_10 -> V_35 , V_17 ) ;
F_4 ( V_10 , F_29 ( V_10 -> V_36 ) , 1 ) ;
F_15 ( & V_10 -> V_35 , V_17 ) ;
}
static void F_30 ( struct V_9 * V_10 )
{
struct V_41 * V_38 = & V_10 -> V_38 ;
struct V_15 * V_16 = & V_10 -> V_38 . V_16 ;
V_38 -> V_40 = F_25 ( V_10 -> V_37 ) ;
if ( V_16 -> type == V_32 )
V_38 -> V_40 |= F_26 ( V_16 ) ;
}
int F_31 ( struct V_9 * V_10 , bool V_43 )
{
if ( F_23 ( ! V_10 ) )
return - V_39 ;
V_10 -> V_38 . V_42 = V_43 ;
F_32 ( L_2 , V_10 -> V_38 . V_16 . V_21 , V_43 ? L_3 : L_4 ) ;
if ( F_27 ( V_10 ) ) {
F_28 ( V_10 ) ;
F_30 ( V_10 ) ;
}
return 0 ;
}
int F_33 ( struct V_9 * V_10 , int V_44 , bool V_45 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
unsigned long V_17 ;
T_1 V_46 ;
int V_37 = V_10 -> V_37 ;
if ( F_22 ( F_23 ( V_37 < 0 ) ) ) {
F_24 ( V_3 -> V_6 -> V_6 , L_5 ,
V_10 -> V_36 , V_37 ) ;
return - V_39 ;
}
F_9 ( & V_10 -> V_35 , V_17 ) ;
V_46 = F_6 ( V_10 , F_34 ( V_10 -> V_36 , V_37 ) ) ;
if ( V_45 )
V_46 |= V_47 ;
else
V_46 &= ~ V_47 ;
F_4 ( V_10 , F_34 ( V_10 -> V_36 , V_37 ) , V_46 ) ;
V_10 -> V_48 = V_45 ;
F_15 ( & V_10 -> V_35 , V_17 ) ;
V_10 -> V_49 = F_35 ( V_44 ) ;
return 0 ;
}
static T_1 F_36 ( enum V_50 V_51 ,
enum V_52 V_53 )
{
switch ( V_51 ) {
case V_54 : return F_37 ( V_53 ) ;
case V_55 : return F_38 ( V_53 ) ;
case V_56 : return F_39 ( V_53 ) ;
case V_57 : return F_40 ( V_53 ) ;
case V_58 : return F_41 ( V_53 ) ;
case V_59 : return F_42 ( V_53 ) ;
case V_60 : return F_43 ( V_53 ) ;
case V_61 : return F_44 ( V_53 ) ;
case V_62 : return F_45 ( V_53 ) ;
case V_63 : return F_46 ( V_53 ) ;
case V_64 :
case V_65 :
default: return 0 ;
}
}
static T_1 F_47 ( enum V_50 V_51 ,
enum V_52 V_53 )
{
if ( V_53 < V_66 && ( V_51 != V_64 && V_51 != V_65 ) )
return 0 ;
switch ( V_51 ) {
case V_54 : return V_67 ;
case V_55 : return V_68 ;
case V_56 : return V_69 ;
case V_57 : return V_70 ;
case V_58 : return V_71 ;
case V_59 : return V_72 ;
case V_60 : return V_73 ;
case V_61 : return V_74 ;
case V_62 : return V_75 ;
case V_63 : return V_76 ;
case V_64 : return F_48 ( V_53 ) ;
case V_65 : return F_49 ( V_53 ) ;
default: return 0 ;
}
}
int F_50 ( struct V_9 * V_10 , enum V_50 * V_53 , T_1 V_77 ,
T_1 V_78 )
{
unsigned long V_17 ;
T_1 V_46 = 0 , V_79 = 0 ;
int V_80 , V_81 ;
if ( V_78 & V_82 ) {
V_81 = V_83 ;
V_46 |= V_84 ;
} else {
V_81 = V_85 ;
}
for ( V_80 = V_81 ; V_77 && V_80 <= V_86 ; V_80 ++ ) {
V_46 |= F_36 ( V_53 [ V_80 ] , V_80 ) ;
V_79 |= F_47 ( V_53 [ V_80 ] , V_80 ) ;
}
F_9 ( & V_10 -> V_35 , V_17 ) ;
if ( V_10 -> V_48 )
V_46 |= V_47 ;
F_4 ( V_10 , F_34 ( V_10 -> V_36 , V_10 -> V_37 ) , V_46 ) ;
F_4 ( V_10 , F_51 ( V_10 -> V_36 , V_10 -> V_37 ) , V_79 ) ;
F_15 ( & V_10 -> V_35 , V_17 ) ;
V_10 -> V_49 = F_25 ( V_10 -> V_37 ) ;
F_32 ( L_6 , V_10 -> V_37 ,
V_46 , V_79 ) ;
return 0 ;
}
T_1 F_26 ( struct V_15 * V_16 )
{
if ( V_16 -> type == V_32 )
return V_87 ;
switch ( V_16 -> V_21 ) {
case 0 : return V_88 ;
case 1 : return V_89 ;
case 2 : return V_90 ;
case 3 : return V_91 ;
default: return 0 ;
}
}
T_1 F_35 ( int V_44 )
{
switch ( V_44 ) {
case 0 : return V_92 ;
case 1 : return V_93 ;
default: return 0 ;
}
}
T_1 F_52 ( enum V_50 V_51 )
{
switch ( V_51 ) {
case V_54 : return V_94 ;
case V_55 : return V_95 ;
case V_56 : return V_96 ;
case V_57 : return V_97 ;
case V_58 : return V_98 ;
case V_59 : return V_99 ;
case V_60 : return V_100 ;
case V_61 : return V_101 ;
case V_62 : return V_102 ;
case V_63 : return V_103 ;
case V_64 : return V_92 ;
case V_65 : return V_93 ;
default: return 0 ;
}
}
T_1 F_25 ( int V_37 )
{
switch ( V_37 ) {
case 0 : return V_104 ;
case 1 : return V_105 ;
case 2 : return V_106 ;
case 5 : return V_107 ;
default: return 0 ;
}
}
static T_1 F_53 ( struct V_9 * V_10 , T_1 V_108 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
T_1 V_109 = 0 ;
#define F_54 ( T_2 ) \
(!(ctl_mgr->flush_hw_mask & bit) && (flush_mask & bit))
if ( F_54 ( V_92 ) )
V_109 |= F_25 ( V_10 -> V_37 ) ;
return V_109 ;
}
static void F_55 ( struct V_9 * V_10 , T_1 * V_108 ,
T_1 * V_110 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
if ( V_10 -> V_111 ) {
F_32 ( L_7 , V_10 -> V_36 , * V_108 ) ;
V_10 -> V_112 = true ;
V_3 -> V_113 |= ( * V_108 ) ;
* V_108 = 0 ;
if ( V_10 -> V_111 -> V_112 ) {
* V_110 = F_56 ( T_1 , V_10 -> V_36 , V_10 -> V_111 -> V_36 ) ;
* V_108 = V_3 -> V_113 ;
V_10 -> V_112 = false ;
V_10 -> V_111 -> V_112 = false ;
V_3 -> V_113 = 0 ;
F_32 ( L_8 , * V_108 ,
* V_110 ) ;
}
}
}
T_1 F_57 ( struct V_9 * V_10 , T_1 V_108 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
struct V_41 * V_38 = & V_10 -> V_38 ;
unsigned long V_17 ;
T_1 V_110 = V_10 -> V_36 ;
T_1 V_114 ;
V_38 -> V_40 &= ~ V_108 ;
F_58 ( L_9 , V_108 ,
V_38 -> V_40 , V_10 -> V_49 ) ;
if ( V_10 -> V_49 & V_108 ) {
V_108 |= V_115 ;
V_10 -> V_49 = 0 ;
}
V_108 |= F_53 ( V_10 , V_108 ) ;
V_108 &= V_3 -> V_116 ;
V_114 = V_108 ;
F_55 ( V_10 , & V_108 , & V_110 ) ;
if ( V_108 ) {
F_9 ( & V_10 -> V_35 , V_17 ) ;
F_4 ( V_10 , F_59 ( V_110 ) , V_108 ) ;
F_15 ( & V_10 -> V_35 , V_17 ) ;
}
if ( F_27 ( V_10 ) ) {
F_28 ( V_10 ) ;
F_30 ( V_10 ) ;
}
return V_114 ;
}
T_1 F_60 ( struct V_9 * V_10 )
{
return F_6 ( V_10 , F_59 ( V_10 -> V_36 ) ) ;
}
int F_61 ( struct V_9 * V_10 )
{
return F_23 ( ! V_10 ) ? - V_39 : V_10 -> V_36 ;
}
int F_62 ( struct V_9 * V_117 , struct V_9 * V_118 , bool V_45 )
{
struct V_2 * V_3 = V_117 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_3 -> V_119 )
return 0 ;
if ( ! V_45 ) {
V_117 -> V_111 = NULL ;
V_118 -> V_111 = NULL ;
F_5 ( V_1 , V_120 , 0 ) ;
return 0 ;
} else if ( ( V_117 -> V_111 != NULL ) || ( V_118 -> V_111 != NULL ) ) {
F_24 ( V_3 -> V_6 -> V_6 , L_10 ) ;
return - V_39 ;
} else if ( ! ( V_117 -> V_121 & V_118 -> V_121 & V_122 ) ) {
F_24 ( V_3 -> V_6 -> V_6 , L_11 ) ;
return - V_39 ;
}
V_117 -> V_111 = V_118 ;
V_118 -> V_111 = V_117 ;
F_5 ( V_1 , V_120 ,
V_123 ) ;
return 0 ;
}
struct V_9 * F_63 ( struct V_2 * V_3 ,
int V_124 )
{
struct V_9 * V_10 = NULL ;
const T_1 V_125 = V_126 | V_122 ;
T_1 V_127 = ( ( V_124 == 1 ) || ( V_124 == 2 ) ) ? V_122 : 0 ;
unsigned long V_17 ;
int V_128 ;
F_9 ( & V_3 -> V_129 , V_17 ) ;
for ( V_128 = 0 ; V_128 < V_3 -> V_130 ; V_128 ++ )
if ( ( V_3 -> V_131 [ V_128 ] . V_121 & V_125 ) == V_127 )
goto V_132;
F_64 ( V_3 -> V_6 -> V_6 ,
L_12 , V_124 ) ;
V_127 ^= V_122 ;
for ( V_128 = 0 ; V_128 < V_3 -> V_130 ; V_128 ++ )
if ( ( V_3 -> V_131 [ V_128 ] . V_121 & V_125 ) == V_127 )
goto V_132;
F_24 ( V_3 -> V_6 -> V_6 , L_13 ) ;
goto V_133;
V_132:
V_10 = & V_3 -> V_131 [ V_128 ] ;
V_10 -> V_38 . V_16 . V_21 = V_124 ;
V_10 -> V_37 = - 1 ;
V_10 -> V_121 |= V_126 ;
V_10 -> V_49 = 0 ;
F_32 ( L_14 , V_10 -> V_36 ) ;
V_133:
F_15 ( & V_3 -> V_129 , V_17 ) ;
return V_10 ;
}
void F_65 ( struct V_2 * V_3 )
{
unsigned long V_17 ;
int V_128 ;
for ( V_128 = 0 ; V_128 < V_3 -> V_130 ; V_128 ++ ) {
struct V_9 * V_10 = & V_3 -> V_131 [ V_128 ] ;
F_9 ( & V_10 -> V_35 , V_17 ) ;
F_4 ( V_10 , F_20 ( V_10 -> V_36 ) , 0 ) ;
F_15 ( & V_10 -> V_35 , V_17 ) ;
}
}
void F_66 ( struct V_2 * V_3 )
{
F_67 ( V_3 ) ;
}
struct V_2 * F_68 ( struct V_134 * V_6 ,
void T_3 * V_135 , struct V_136 * V_137 )
{
struct V_2 * V_3 ;
const struct V_138 * V_139 = F_69 ( V_137 ) ;
int V_140 = F_70 ( V_137 ) ;
const struct V_141 * V_142 = & V_139 -> V_10 ;
unsigned long V_17 ;
int V_128 , V_143 ;
V_3 = F_71 ( sizeof( * V_3 ) , V_144 ) ;
if ( ! V_3 ) {
F_24 ( V_6 -> V_6 , L_15 ) ;
V_143 = - V_145 ;
goto V_146;
}
if ( F_22 ( F_23 ( V_142 -> V_147 > V_148 ) ) ) {
F_24 ( V_6 -> V_6 , L_16 ,
V_142 -> V_147 ) ;
V_143 = - V_149 ;
goto V_146;
}
V_3 -> V_6 = V_6 ;
V_3 -> V_150 = V_139 -> V_37 . V_147 ;
V_3 -> V_130 = V_142 -> V_147 ;
V_3 -> V_116 = V_142 -> V_116 ;
F_72 ( & V_3 -> V_129 ) ;
F_9 ( & V_3 -> V_129 , V_17 ) ;
for ( V_128 = 0 ; V_128 < V_3 -> V_130 ; V_128 ++ ) {
struct V_9 * V_10 = & V_3 -> V_131 [ V_128 ] ;
if ( F_23 ( ! V_142 -> V_151 [ V_128 ] ) ) {
F_24 ( V_6 -> V_6 , L_17 , V_128 ) ;
V_143 = - V_39 ;
F_15 ( & V_3 -> V_129 , V_17 ) ;
goto V_146;
}
V_10 -> V_13 = V_3 ;
V_10 -> V_36 = V_128 ;
V_10 -> V_14 = V_142 -> V_151 [ V_128 ] ;
V_10 -> V_121 = 0 ;
F_72 ( & V_10 -> V_35 ) ;
}
if ( V_140 >= 3 ) {
V_3 -> V_119 = true ;
V_3 -> V_131 [ 0 ] . V_121 |= V_122 ;
V_3 -> V_131 [ 1 ] . V_121 |= V_122 ;
}
F_15 ( & V_3 -> V_129 , V_17 ) ;
F_32 ( L_18 , V_3 -> V_130 ) ;
return V_3 ;
V_146:
if ( V_3 )
F_66 ( V_3 ) ;
return F_73 ( V_143 ) ;
}
