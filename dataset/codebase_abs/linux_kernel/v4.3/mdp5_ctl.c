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
V_18 = F_7 ( V_1 , F_10 ( 0 ) ) ;
switch ( V_16 -> V_20 ) {
case 0 :
V_18 &= ~ V_21 ;
V_18 |= F_11 ( V_16 -> type ) ;
break;
case 1 :
V_18 &= ~ V_22 ;
V_18 |= F_12 ( V_16 -> type ) ;
break;
case 2 :
V_18 &= ~ V_23 ;
V_18 |= F_13 ( V_16 -> type ) ;
break;
case 3 :
V_18 &= ~ V_24 ;
V_18 |= F_14 ( V_16 -> type ) ;
break;
default:
F_15 () ;
break;
}
F_5 ( V_1 , F_10 ( 0 ) , V_18 ) ;
F_16 ( & V_1 -> V_19 , V_17 ) ;
}
static void F_17 ( struct V_9 * V_10 , struct V_15 * V_16 )
{
unsigned long V_17 ;
T_1 V_25 = 0 ;
if ( ! F_18 ( V_16 -> type ) )
V_25 |= F_19 ( V_26 + V_16 -> V_20 ) ;
switch ( V_16 -> type ) {
case V_27 :
if ( V_16 -> V_28 == V_29 )
V_25 |= V_30 ;
break;
case V_31 :
if ( V_16 -> V_28 == V_32 )
V_25 |= F_20 ( V_33 ) ;
break;
default:
break;
}
F_9 ( & V_10 -> V_34 , V_17 ) ;
F_4 ( V_10 , F_21 ( V_10 -> V_35 ) , V_25 ) ;
F_16 ( & V_10 -> V_34 , V_17 ) ;
}
int F_22 ( struct V_9 * V_10 ,
struct V_15 * V_16 , int V_36 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( F_23 ( F_24 ( V_16 -> V_20 != V_10 -> V_37 . V_16 . V_20 ) ) ) {
F_25 ( V_1 -> V_6 -> V_6 ,
L_1 ,
V_10 -> V_35 , V_10 -> V_37 . V_16 . V_20 , V_16 -> V_20 ) ;
return - V_38 ;
}
V_10 -> V_36 = V_36 ;
memcpy ( & V_10 -> V_37 . V_16 , V_16 , sizeof( * V_16 ) ) ;
V_10 -> V_37 . V_39 = F_26 ( V_10 -> V_36 ) |
F_27 ( V_16 ) ;
if ( ! F_18 ( V_16 -> type ) )
F_8 ( V_1 , V_16 ) ;
F_17 ( V_10 , V_16 ) ;
return 0 ;
}
static bool F_28 ( struct V_9 * V_10 )
{
struct V_40 * V_37 = & V_10 -> V_37 ;
if ( ! V_37 -> V_41 || V_37 -> V_39 != 0 )
return false ;
switch ( V_37 -> V_16 . type ) {
case V_31 :
return true ;
case V_27 :
return V_37 -> V_16 . V_28 == V_29 ;
default:
return false ;
}
}
static void F_29 ( struct V_9 * V_10 )
{
unsigned long V_17 ;
F_9 ( & V_10 -> V_34 , V_17 ) ;
F_4 ( V_10 , F_30 ( V_10 -> V_35 ) , 1 ) ;
F_16 ( & V_10 -> V_34 , V_17 ) ;
}
static void F_31 ( struct V_9 * V_10 )
{
struct V_40 * V_37 = & V_10 -> V_37 ;
struct V_15 * V_16 = & V_10 -> V_37 . V_16 ;
V_37 -> V_39 = F_26 ( V_10 -> V_36 ) ;
if ( V_16 -> type == V_31 )
V_37 -> V_39 |= F_27 ( V_16 ) ;
}
int F_32 ( struct V_9 * V_10 , bool V_42 )
{
if ( F_24 ( ! V_10 ) )
return - V_38 ;
V_10 -> V_37 . V_41 = V_42 ;
F_33 ( L_2 , V_10 -> V_37 . V_16 . V_20 , V_42 ? L_3 : L_4 ) ;
if ( F_28 ( V_10 ) ) {
F_29 ( V_10 ) ;
F_31 ( V_10 ) ;
}
return 0 ;
}
int F_34 ( struct V_9 * V_10 , int V_43 , bool V_44 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
unsigned long V_17 ;
T_1 V_45 ;
int V_36 = V_10 -> V_36 ;
if ( F_23 ( F_24 ( V_36 < 0 ) ) ) {
F_25 ( V_3 -> V_6 -> V_6 , L_5 ,
V_10 -> V_35 , V_36 ) ;
return - V_38 ;
}
F_9 ( & V_10 -> V_34 , V_17 ) ;
V_45 = F_6 ( V_10 , F_35 ( V_10 -> V_35 , V_36 ) ) ;
if ( V_44 )
V_45 |= V_46 ;
else
V_45 &= ~ V_46 ;
F_4 ( V_10 , F_35 ( V_10 -> V_35 , V_36 ) , V_45 ) ;
V_10 -> V_47 = V_44 ;
F_16 ( & V_10 -> V_34 , V_17 ) ;
V_10 -> V_48 = F_36 ( V_43 ) ;
return 0 ;
}
static T_1 F_37 ( enum V_49 V_50 ,
enum V_51 V_52 )
{
switch ( V_50 ) {
case V_53 : return F_38 ( V_52 ) ;
case V_54 : return F_39 ( V_52 ) ;
case V_55 : return F_40 ( V_52 ) ;
case V_56 : return F_41 ( V_52 ) ;
case V_57 : return F_42 ( V_52 ) ;
case V_58 : return F_43 ( V_52 ) ;
case V_59 : return F_44 ( V_52 ) ;
case V_60 : return F_45 ( V_52 ) ;
case V_61 : return F_46 ( V_52 ) ;
case V_62 : return F_47 ( V_52 ) ;
default: return 0 ;
}
}
static T_1 F_48 ( enum V_49 V_50 ,
enum V_51 V_52 )
{
if ( V_52 < V_63 )
return 0 ;
switch ( V_50 ) {
case V_53 : return V_64 ;
case V_54 : return V_65 ;
case V_55 : return V_66 ;
case V_56 : return V_67 ;
case V_57 : return V_68 ;
case V_58 : return V_69 ;
case V_59 : return V_70 ;
case V_60 : return V_71 ;
case V_61 : return V_72 ;
case V_62 : return V_73 ;
default: return 0 ;
}
}
int F_49 ( struct V_9 * V_10 , T_2 * V_52 , T_1 V_74 ,
T_1 V_75 )
{
unsigned long V_17 ;
T_1 V_45 = 0 , V_76 = 0 ;
int V_77 , V_78 ;
if ( V_75 & V_79 ) {
V_78 = V_80 ;
V_45 |= V_81 ;
} else {
V_78 = V_82 ;
}
for ( V_77 = V_78 ; V_77 < V_78 + V_74 ; V_77 ++ ) {
V_45 |= F_37 ( V_52 [ V_77 ] , V_77 ) ;
V_76 |= F_48 ( V_52 [ V_77 ] , V_77 ) ;
}
F_9 ( & V_10 -> V_34 , V_17 ) ;
if ( V_10 -> V_47 )
V_45 |= V_46 ;
F_4 ( V_10 , F_35 ( V_10 -> V_35 , V_10 -> V_36 ) , V_45 ) ;
F_4 ( V_10 , F_50 ( V_10 -> V_35 , V_10 -> V_36 ) , V_76 ) ;
F_16 ( & V_10 -> V_34 , V_17 ) ;
V_10 -> V_48 = F_26 ( V_10 -> V_36 ) ;
F_33 ( L_6 , V_10 -> V_36 ,
V_45 , V_76 ) ;
return 0 ;
}
T_1 F_27 ( struct V_15 * V_16 )
{
if ( V_16 -> type == V_31 )
return V_83 ;
switch ( V_16 -> V_20 ) {
case 0 : return V_84 ;
case 1 : return V_85 ;
case 2 : return V_86 ;
case 3 : return V_87 ;
default: return 0 ;
}
}
T_1 F_36 ( int V_43 )
{
switch ( V_43 ) {
case 0 : return V_88 ;
case 1 : return V_89 ;
default: return 0 ;
}
}
T_1 F_51 ( enum V_49 V_50 )
{
switch ( V_50 ) {
case V_53 : return V_90 ;
case V_54 : return V_91 ;
case V_55 : return V_92 ;
case V_56 : return V_93 ;
case V_57 : return V_94 ;
case V_58 : return V_95 ;
case V_59 : return V_96 ;
case V_60 : return V_97 ;
case V_61 : return V_98 ;
case V_62 : return V_99 ;
default: return 0 ;
}
}
T_1 F_26 ( int V_36 )
{
switch ( V_36 ) {
case 0 : return V_100 ;
case 1 : return V_101 ;
case 2 : return V_102 ;
case 5 : return V_103 ;
default: return 0 ;
}
}
static T_1 F_52 ( struct V_9 * V_10 , T_1 V_104 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
T_1 V_105 = 0 ;
#define F_53 ( T_3 ) \
(!(ctl_mgr->flush_hw_mask & bit) && (flush_mask & bit))
if ( F_53 ( V_88 ) )
V_105 |= F_26 ( V_10 -> V_36 ) ;
return V_105 ;
}
static void F_54 ( struct V_9 * V_10 , T_1 * V_104 ,
T_1 * V_106 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
if ( V_10 -> V_107 ) {
F_33 ( L_7 , V_10 -> V_35 , * V_104 ) ;
V_10 -> V_108 = true ;
V_3 -> V_109 |= ( * V_104 ) ;
* V_104 = 0 ;
if ( V_10 -> V_107 -> V_108 ) {
* V_106 = F_55 ( T_1 , V_10 -> V_35 , V_10 -> V_107 -> V_35 ) ;
* V_104 = V_3 -> V_109 ;
V_10 -> V_108 = false ;
V_10 -> V_107 -> V_108 = false ;
V_3 -> V_109 = 0 ;
F_33 ( L_8 , * V_104 ,
* V_106 ) ;
}
}
}
T_1 F_56 ( struct V_9 * V_10 , T_1 V_104 )
{
struct V_2 * V_3 = V_10 -> V_13 ;
struct V_40 * V_37 = & V_10 -> V_37 ;
unsigned long V_17 ;
T_1 V_106 = V_10 -> V_35 ;
T_1 V_110 ;
V_37 -> V_39 &= ~ V_104 ;
F_57 ( L_9 , V_104 ,
V_37 -> V_39 , V_10 -> V_48 ) ;
if ( V_10 -> V_48 & V_104 ) {
V_104 |= V_111 ;
V_10 -> V_48 = 0 ;
}
V_104 |= F_52 ( V_10 , V_104 ) ;
V_104 &= V_3 -> V_112 ;
V_110 = V_104 ;
F_54 ( V_10 , & V_104 , & V_106 ) ;
if ( V_104 ) {
F_9 ( & V_10 -> V_34 , V_17 ) ;
F_4 ( V_10 , F_58 ( V_106 ) , V_104 ) ;
F_16 ( & V_10 -> V_34 , V_17 ) ;
}
if ( F_28 ( V_10 ) ) {
F_29 ( V_10 ) ;
F_31 ( V_10 ) ;
}
return V_110 ;
}
T_1 F_59 ( struct V_9 * V_10 )
{
return F_6 ( V_10 , F_58 ( V_10 -> V_35 ) ) ;
}
int F_60 ( struct V_9 * V_10 )
{
return F_24 ( ! V_10 ) ? - V_38 : V_10 -> V_35 ;
}
int F_61 ( struct V_9 * V_113 , struct V_9 * V_114 , bool V_44 )
{
struct V_2 * V_3 = V_113 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_3 -> V_115 )
return 0 ;
if ( ! V_44 ) {
V_113 -> V_107 = NULL ;
V_114 -> V_107 = NULL ;
F_5 ( V_1 , F_62 ( 0 ) , 0 ) ;
return 0 ;
} else if ( ( V_113 -> V_107 != NULL ) || ( V_114 -> V_107 != NULL ) ) {
F_25 ( V_3 -> V_6 -> V_6 , L_10 ) ;
return - V_38 ;
} else if ( ! ( V_113 -> V_116 & V_114 -> V_116 & V_117 ) ) {
F_25 ( V_3 -> V_6 -> V_6 , L_11 ) ;
return - V_38 ;
}
V_113 -> V_107 = V_114 ;
V_114 -> V_107 = V_113 ;
F_5 ( V_1 , F_62 ( 0 ) ,
V_118 ) ;
return 0 ;
}
struct V_9 * F_63 ( struct V_2 * V_3 ,
int V_119 )
{
struct V_9 * V_10 = NULL ;
const T_1 V_120 = V_121 | V_117 ;
T_1 V_122 = ( ( V_119 == 1 ) || ( V_119 == 2 ) ) ? V_117 : 0 ;
unsigned long V_17 ;
int V_123 ;
F_9 ( & V_3 -> V_124 , V_17 ) ;
for ( V_123 = 0 ; V_123 < V_3 -> V_125 ; V_123 ++ )
if ( ( V_3 -> V_126 [ V_123 ] . V_116 & V_120 ) == V_122 )
goto V_127;
F_64 ( V_3 -> V_6 -> V_6 ,
L_12 , V_119 ) ;
V_122 ^= V_117 ;
for ( V_123 = 0 ; V_123 < V_3 -> V_125 ; V_123 ++ )
if ( ( V_3 -> V_126 [ V_123 ] . V_116 & V_120 ) == V_122 )
goto V_127;
F_25 ( V_3 -> V_6 -> V_6 , L_13 ) ;
goto V_128;
V_127:
V_10 = & V_3 -> V_126 [ V_123 ] ;
V_10 -> V_37 . V_16 . V_20 = V_119 ;
V_10 -> V_36 = - 1 ;
V_10 -> V_116 |= V_121 ;
V_10 -> V_48 = 0 ;
F_33 ( L_14 , V_10 -> V_35 ) ;
V_128:
F_16 ( & V_3 -> V_124 , V_17 ) ;
return V_10 ;
}
void F_65 ( struct V_2 * V_3 )
{
unsigned long V_17 ;
int V_123 ;
for ( V_123 = 0 ; V_123 < V_3 -> V_125 ; V_123 ++ ) {
struct V_9 * V_10 = & V_3 -> V_126 [ V_123 ] ;
F_9 ( & V_10 -> V_34 , V_17 ) ;
F_4 ( V_10 , F_21 ( V_10 -> V_35 ) , 0 ) ;
F_16 ( & V_10 -> V_34 , V_17 ) ;
}
}
void F_66 ( struct V_2 * V_3 )
{
F_67 ( V_3 ) ;
}
struct V_2 * F_68 ( struct V_129 * V_6 ,
void T_4 * V_130 , struct V_131 * V_132 )
{
struct V_2 * V_3 ;
const struct V_133 * V_134 = F_69 ( V_132 ) ;
int V_135 = F_70 ( V_132 ) ;
const struct V_136 * V_137 = & V_134 -> V_10 ;
unsigned long V_17 ;
int V_123 , V_138 ;
V_3 = F_71 ( sizeof( * V_3 ) , V_139 ) ;
if ( ! V_3 ) {
F_25 ( V_6 -> V_6 , L_15 ) ;
V_138 = - V_140 ;
goto V_141;
}
if ( F_23 ( F_24 ( V_137 -> V_142 > V_143 ) ) ) {
F_25 ( V_6 -> V_6 , L_16 ,
V_137 -> V_142 ) ;
V_138 = - V_144 ;
goto V_141;
}
V_3 -> V_6 = V_6 ;
V_3 -> V_145 = V_134 -> V_36 . V_142 ;
V_3 -> V_125 = V_137 -> V_142 ;
V_3 -> V_112 = V_137 -> V_112 ;
F_72 ( & V_3 -> V_124 ) ;
F_9 ( & V_3 -> V_124 , V_17 ) ;
for ( V_123 = 0 ; V_123 < V_3 -> V_125 ; V_123 ++ ) {
struct V_9 * V_10 = & V_3 -> V_126 [ V_123 ] ;
if ( F_24 ( ! V_137 -> V_146 [ V_123 ] ) ) {
F_25 ( V_6 -> V_6 , L_17 , V_123 ) ;
V_138 = - V_38 ;
F_16 ( & V_3 -> V_124 , V_17 ) ;
goto V_141;
}
V_10 -> V_13 = V_3 ;
V_10 -> V_35 = V_123 ;
V_10 -> V_14 = V_137 -> V_146 [ V_123 ] ;
V_10 -> V_116 = 0 ;
F_72 ( & V_10 -> V_34 ) ;
}
if ( V_135 >= 3 ) {
V_3 -> V_115 = true ;
V_3 -> V_126 [ 0 ] . V_116 |= V_117 ;
V_3 -> V_126 [ 1 ] . V_116 |= V_117 ;
}
F_16 ( & V_3 -> V_124 , V_17 ) ;
F_33 ( L_18 , V_3 -> V_125 ) ;
return V_3 ;
V_141:
if ( V_3 )
F_66 ( V_3 ) ;
return F_73 ( V_138 ) ;
}
