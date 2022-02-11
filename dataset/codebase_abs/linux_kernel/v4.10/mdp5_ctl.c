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
default: return 0 ;
}
}
static T_1 F_47 ( enum V_50 V_51 ,
enum V_52 V_53 )
{
if ( V_53 < V_64 )
return 0 ;
switch ( V_51 ) {
case V_54 : return V_65 ;
case V_55 : return V_66 ;
case V_56 : return V_67 ;
case V_57 : return V_68 ;
case V_58 : return V_69 ;
case V_59 : return V_70 ;
case V_60 : return V_71 ;
case V_61 : return V_72 ;
case V_62 : return V_73 ;
case V_63 : return V_74 ;
default: return 0 ;
}
}
int F_48 ( struct V_9 * V_10 , T_2 * V_53 , T_1 V_75 ,
T_1 V_76 )
{
unsigned long V_17 ;
T_1 V_46 = 0 , V_77 = 0 ;
int V_78 , V_79 ;
if ( V_76 & V_80 ) {
V_79 = V_81 ;
V_46 |= V_82 ;
} else {
V_79 = V_83 ;
}
for ( V_78 = V_79 ; V_78 < V_79 + V_75 ; V_78 ++ ) {
V_46 |= F_36 ( V_53 [ V_78 ] , V_78 ) ;
V_77 |= F_47 ( V_53 [ V_78 ] , V_78 ) ;
}
F_9 ( & V_10 -> V_35 , V_17 ) ;
if ( V_10 -> V_48 )
V_46 |= V_47 ;
F_4 ( V_10 , F_34 ( V_10 -> V_36 , V_10 -> V_37 ) , V_46 ) ;
F_4 ( V_10 , F_49 ( V_10 -> V_36 , V_10 -> V_37 ) , V_77 ) ;
F_15 ( & V_10 -> V_35 , V_17 ) ;
V_10 -> V_49 = F_25 ( V_10 -> V_37 ) ;
F_32 ( L_6 , V_10 -> V_37 ,
V_46 , V_77 ) ;
return 0 ;
}
T_1 F_26 ( struct V_15 * V_16 )
{
if ( V_16 -> type == V_32 )
return V_84 ;
switch ( V_16 -> V_21 ) {
case 0 : return V_85 ;
case 1 : return V_86 ;
case 2 : return V_87 ;
case 3 : return V_88 ;
default: return 0 ;
}
}
T_1 F_35 ( int V_44 )
{
switch ( V_44 ) {
case 0 : return V_89 ;
case 1 : return V_90 ;
default: return 0 ;
}
}
T_1 F_50 ( enum V_50 V_51 )
{
switch ( V_51 ) {
case V_54 : return V_91 ;
case V_55 : return V_92 ;
case V_56 : return V_93 ;
case V_57 : return V_94 ;
case V_58 : return V_95 ;
case V_59 : return V_96 ;
case V_60 : return V_97 ;
case V_61 : return V_98 ;
case V_62 : return V_99 ;
case V_63 : return V_100 ;
default: return 0 ;
}
}
T_1 F_25 ( int V_37 )
{
switch ( V_37 ) {
case 0 : return V_101 ;
case 1 : return V_102 ;
case 2 : return V_103 ;
case 5 : return V_104 ;
default: return 0 ;
}
}
static T_1 F_51 ( struct V_9 * V_10 , T_1 V_105 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
T_1 V_106 = 0 ;
#define F_52 ( T_3 ) \
(!(ctl_mgr->flush_hw_mask & bit) && (flush_mask & bit))
if ( F_52 ( V_89 ) )
V_106 |= F_25 ( V_10 -> V_37 ) ;
return V_106 ;
}
static void F_53 ( struct V_9 * V_10 , T_1 * V_105 ,
T_1 * V_107 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
if ( V_10 -> V_108 ) {
F_32 ( L_7 , V_10 -> V_36 , * V_105 ) ;
V_10 -> V_109 = true ;
V_3 -> V_110 |= ( * V_105 ) ;
* V_105 = 0 ;
if ( V_10 -> V_108 -> V_109 ) {
* V_107 = F_54 ( T_1 , V_10 -> V_36 , V_10 -> V_108 -> V_36 ) ;
* V_105 = V_3 -> V_110 ;
V_10 -> V_109 = false ;
V_10 -> V_108 -> V_109 = false ;
V_3 -> V_110 = 0 ;
F_32 ( L_8 , * V_105 ,
* V_107 ) ;
}
}
}
T_1 F_55 ( struct V_9 * V_10 , T_1 V_105 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
struct V_41 * V_38 = & V_10 -> V_38 ;
unsigned long V_17 ;
T_1 V_107 = V_10 -> V_36 ;
T_1 V_111 ;
V_38 -> V_40 &= ~ V_105 ;
F_56 ( L_9 , V_105 ,
V_38 -> V_40 , V_10 -> V_49 ) ;
if ( V_10 -> V_49 & V_105 ) {
V_105 |= V_112 ;
V_10 -> V_49 = 0 ;
}
V_105 |= F_51 ( V_10 , V_105 ) ;
V_105 &= V_3 -> V_113 ;
V_111 = V_105 ;
F_53 ( V_10 , & V_105 , & V_107 ) ;
if ( V_105 ) {
F_9 ( & V_10 -> V_35 , V_17 ) ;
F_4 ( V_10 , F_57 ( V_107 ) , V_105 ) ;
F_15 ( & V_10 -> V_35 , V_17 ) ;
}
if ( F_27 ( V_10 ) ) {
F_28 ( V_10 ) ;
F_30 ( V_10 ) ;
}
return V_111 ;
}
T_1 F_58 ( struct V_9 * V_10 )
{
return F_6 ( V_10 , F_57 ( V_10 -> V_36 ) ) ;
}
int F_59 ( struct V_9 * V_10 )
{
return F_23 ( ! V_10 ) ? - V_39 : V_10 -> V_36 ;
}
int F_60 ( struct V_9 * V_114 , struct V_9 * V_115 , bool V_45 )
{
struct V_2 * V_3 = V_114 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_3 -> V_116 )
return 0 ;
if ( ! V_45 ) {
V_114 -> V_108 = NULL ;
V_115 -> V_108 = NULL ;
F_5 ( V_1 , V_117 , 0 ) ;
return 0 ;
} else if ( ( V_114 -> V_108 != NULL ) || ( V_115 -> V_108 != NULL ) ) {
F_24 ( V_3 -> V_6 -> V_6 , L_10 ) ;
return - V_39 ;
} else if ( ! ( V_114 -> V_118 & V_115 -> V_118 & V_119 ) ) {
F_24 ( V_3 -> V_6 -> V_6 , L_11 ) ;
return - V_39 ;
}
V_114 -> V_108 = V_115 ;
V_115 -> V_108 = V_114 ;
F_5 ( V_1 , V_117 ,
V_120 ) ;
return 0 ;
}
struct V_9 * F_61 ( struct V_2 * V_3 ,
int V_121 )
{
struct V_9 * V_10 = NULL ;
const T_1 V_122 = V_123 | V_119 ;
T_1 V_124 = ( ( V_121 == 1 ) || ( V_121 == 2 ) ) ? V_119 : 0 ;
unsigned long V_17 ;
int V_125 ;
F_9 ( & V_3 -> V_126 , V_17 ) ;
for ( V_125 = 0 ; V_125 < V_3 -> V_127 ; V_125 ++ )
if ( ( V_3 -> V_128 [ V_125 ] . V_118 & V_122 ) == V_124 )
goto V_129;
F_62 ( V_3 -> V_6 -> V_6 ,
L_12 , V_121 ) ;
V_124 ^= V_119 ;
for ( V_125 = 0 ; V_125 < V_3 -> V_127 ; V_125 ++ )
if ( ( V_3 -> V_128 [ V_125 ] . V_118 & V_122 ) == V_124 )
goto V_129;
F_24 ( V_3 -> V_6 -> V_6 , L_13 ) ;
goto V_130;
V_129:
V_10 = & V_3 -> V_128 [ V_125 ] ;
V_10 -> V_38 . V_16 . V_21 = V_121 ;
V_10 -> V_37 = - 1 ;
V_10 -> V_118 |= V_123 ;
V_10 -> V_49 = 0 ;
F_32 ( L_14 , V_10 -> V_36 ) ;
V_130:
F_15 ( & V_3 -> V_126 , V_17 ) ;
return V_10 ;
}
void F_63 ( struct V_2 * V_3 )
{
unsigned long V_17 ;
int V_125 ;
for ( V_125 = 0 ; V_125 < V_3 -> V_127 ; V_125 ++ ) {
struct V_9 * V_10 = & V_3 -> V_128 [ V_125 ] ;
F_9 ( & V_10 -> V_35 , V_17 ) ;
F_4 ( V_10 , F_20 ( V_10 -> V_36 ) , 0 ) ;
F_15 ( & V_10 -> V_35 , V_17 ) ;
}
}
void F_64 ( struct V_2 * V_3 )
{
F_65 ( V_3 ) ;
}
struct V_2 * F_66 ( struct V_131 * V_6 ,
void T_4 * V_132 , struct V_133 * V_134 )
{
struct V_2 * V_3 ;
const struct V_135 * V_136 = F_67 ( V_134 ) ;
int V_137 = F_68 ( V_134 ) ;
const struct V_138 * V_139 = & V_136 -> V_10 ;
unsigned long V_17 ;
int V_125 , V_140 ;
V_3 = F_69 ( sizeof( * V_3 ) , V_141 ) ;
if ( ! V_3 ) {
F_24 ( V_6 -> V_6 , L_15 ) ;
V_140 = - V_142 ;
goto V_143;
}
if ( F_22 ( F_23 ( V_139 -> V_144 > V_145 ) ) ) {
F_24 ( V_6 -> V_6 , L_16 ,
V_139 -> V_144 ) ;
V_140 = - V_146 ;
goto V_143;
}
V_3 -> V_6 = V_6 ;
V_3 -> V_147 = V_136 -> V_37 . V_144 ;
V_3 -> V_127 = V_139 -> V_144 ;
V_3 -> V_113 = V_139 -> V_113 ;
F_70 ( & V_3 -> V_126 ) ;
F_9 ( & V_3 -> V_126 , V_17 ) ;
for ( V_125 = 0 ; V_125 < V_3 -> V_127 ; V_125 ++ ) {
struct V_9 * V_10 = & V_3 -> V_128 [ V_125 ] ;
if ( F_23 ( ! V_139 -> V_148 [ V_125 ] ) ) {
F_24 ( V_6 -> V_6 , L_17 , V_125 ) ;
V_140 = - V_39 ;
F_15 ( & V_3 -> V_126 , V_17 ) ;
goto V_143;
}
V_10 -> V_13 = V_3 ;
V_10 -> V_36 = V_125 ;
V_10 -> V_14 = V_139 -> V_148 [ V_125 ] ;
V_10 -> V_118 = 0 ;
F_70 ( & V_10 -> V_35 ) ;
}
if ( V_137 >= 3 ) {
V_3 -> V_116 = true ;
V_3 -> V_128 [ 0 ] . V_118 |= V_119 ;
V_3 -> V_128 [ 1 ] . V_118 |= V_119 ;
}
F_15 ( & V_3 -> V_126 , V_17 ) ;
F_32 ( L_18 , V_3 -> V_127 ) ;
return V_3 ;
V_143:
if ( V_3 )
F_64 ( V_3 ) ;
return F_71 ( V_140 ) ;
}
