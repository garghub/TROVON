const char * F_1 ( int V_1 )
{
static const char * V_2 [] = {
[ V_3 ] = L_1 ,
[ V_4 ] = L_2 ,
[ V_5 ] = L_3 ,
[ V_6 ] = L_4 ,
[ V_7 ] = L_5 ,
[ V_8 ] = L_6 ,
[ V_9 ] = L_7 ,
} ;
if ( V_1 < V_3 || V_1 > V_9 )
return L_8 ;
return V_2 [ V_1 ] ;
}
int F_2 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_14 * V_15 )
{
V_13 -> V_16 = V_15 ;
F_3 ( sizeof( V_13 -> V_17 ) !=
sizeof( F_4 ( V_13 ) -> V_18 ) ) ;
V_13 -> V_17 = F_4 ( V_13 ) -> V_18 ;
if ( F_5 ( F_6 ( V_11 -> V_16 ) ) )
F_7 ( F_8 ( V_11 , V_15 ) , V_13 ) ;
else
F_9 ( V_13 ) ;
return 0 ;
}
static int F_10 ( struct V_14 * V_19 ,
T_1 V_20 , T_2 V_21 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 ;
int V_23 ;
F_12 (bond, slave) {
V_23 = F_13 ( V_22 -> V_16 , V_20 , V_21 ) ;
if ( V_23 )
goto V_24;
}
return 0 ;
V_24:
F_14 (bond, slave)
F_15 ( V_22 -> V_16 , V_20 , V_21 ) ;
return V_23 ;
}
static int F_16 ( struct V_14 * V_19 ,
T_1 V_20 , T_2 V_21 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 ;
F_12 (bond, slave)
F_15 ( V_22 -> V_16 , V_20 , V_21 ) ;
if ( F_17 ( V_11 ) )
F_18 ( V_11 , V_21 ) ;
return 0 ;
}
static int F_19 ( struct V_10 * V_11 )
{
struct V_22 * V_22 ;
if ( F_20 ( & V_11 -> V_25 ) )
goto V_26;
if ( V_11 -> V_27 . V_1 == V_7 )
return F_21 ( V_11 ) ;
F_12 (bond, slave) {
if ( V_22 -> V_28 == V_29 ) {
if ( ! F_22 ( V_11 -> V_16 ) ) {
F_23 ( V_11 -> V_16 ) ;
return 1 ;
}
return 0 ;
}
}
V_26:
if ( F_22 ( V_11 -> V_16 ) ) {
F_24 ( V_11 -> V_16 ) ;
return 1 ;
}
return 0 ;
}
static void F_25 ( struct V_22 * V_22 )
{
struct V_14 * V_15 = V_22 -> V_16 ;
struct V_30 V_31 ;
T_3 V_32 ;
int V_23 ;
V_22 -> V_33 = V_34 ;
V_22 -> V_35 = V_36 ;
V_23 = F_26 ( V_15 , & V_31 ) ;
if ( V_23 < 0 )
return;
V_32 = F_27 ( & V_31 ) ;
if ( V_32 == 0 || V_32 == ( ( V_37 ) - 1 ) )
return;
switch ( V_31 . V_35 ) {
case V_38 :
case V_39 :
break;
default:
return;
}
V_22 -> V_33 = V_32 ;
V_22 -> V_35 = V_31 . V_35 ;
return;
}
static int F_28 ( struct V_10 * V_11 ,
struct V_14 * V_15 , int V_40 )
{
const struct V_41 * V_42 = V_15 -> V_43 ;
int (* F_29)( struct V_14 * , struct V_44 * , int );
struct V_44 V_45 ;
struct V_46 * V_47 ;
if ( ! V_40 && ! F_30 ( V_15 ) )
return 0 ;
if ( V_11 -> V_27 . V_48 )
return F_22 ( V_15 ) ? V_49 : 0 ;
if ( V_15 -> V_50 -> V_51 )
return V_15 -> V_50 -> V_51 ( V_15 ) ?
V_49 : 0 ;
F_29 = V_42 -> V_52 ;
if ( F_29 ) {
strncpy ( V_45 . V_53 , V_15 -> V_54 , V_55 ) ;
V_47 = F_31 ( & V_45 ) ;
if ( F_32 ( V_15 , & V_45 , V_56 ) == 0 ) {
V_47 -> V_57 = V_58 ;
if ( F_32 ( V_15 , & V_45 , V_59 ) == 0 )
return V_47 -> V_60 & V_49 ;
}
}
return V_40 ? - 1 : V_49 ;
}
static int F_33 ( struct V_10 * V_11 , int V_61 )
{
int V_62 = 0 ;
if ( F_34 ( V_11 -> V_27 . V_1 ) ) {
if ( V_11 -> V_63 ) {
V_62 = F_35 ( V_11 -> V_63 -> V_16 ,
V_61 ) ;
}
} else {
struct V_22 * V_22 ;
F_12 (bond, slave) {
V_62 = F_35 ( V_22 -> V_16 , V_61 ) ;
if ( V_62 )
return V_62 ;
}
}
return V_62 ;
}
static int F_36 ( struct V_10 * V_11 , int V_61 )
{
int V_62 = 0 ;
if ( F_34 ( V_11 -> V_27 . V_1 ) ) {
if ( V_11 -> V_63 ) {
V_62 = F_37 ( V_11 -> V_63 -> V_16 ,
V_61 ) ;
}
} else {
struct V_22 * V_22 ;
F_12 (bond, slave) {
V_62 = F_37 ( V_22 -> V_16 , V_61 ) ;
if ( V_62 )
return V_62 ;
}
}
return V_62 ;
}
static void F_38 ( struct V_10 * V_11 )
{
if ( ! F_39 () ) {
F_40 ( V_11 -> V_64 , & V_11 -> V_65 , 1 ) ;
return;
}
F_41 ( V_66 , V_11 -> V_16 ) ;
F_42 () ;
F_43 ( & V_11 -> V_67 ) ;
if ( V_11 -> V_68 > 1 ) {
V_11 -> V_68 -- ;
F_40 ( V_11 -> V_64 , & V_11 -> V_65 , V_69 / 5 ) ;
}
F_44 ( & V_11 -> V_67 ) ;
}
static void F_45 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_46 ( V_71 , struct V_10 ,
V_65 . V_71 ) ;
F_38 ( V_11 ) ;
}
static void F_47 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_48 ( V_15 , V_19 ) ;
F_49 ( V_15 , V_19 ) ;
if ( V_11 -> V_27 . V_1 == V_7 ) {
T_4 V_72 [ V_73 ] = V_74 ;
F_50 ( V_15 , V_72 ) ;
}
}
static void F_51 ( struct V_10 * V_11 , struct V_22 * V_75 ,
struct V_22 * V_76 )
{
F_52 () ;
if ( V_76 ) {
if ( V_11 -> V_16 -> V_77 & V_78 )
F_35 ( V_76 -> V_16 , - 1 ) ;
if ( V_11 -> V_16 -> V_77 & V_79 )
F_37 ( V_76 -> V_16 , - 1 ) ;
F_47 ( V_11 -> V_16 , V_76 -> V_16 ) ;
}
if ( V_75 ) {
if ( V_11 -> V_16 -> V_77 & V_78 )
F_35 ( V_75 -> V_16 , 1 ) ;
if ( V_11 -> V_16 -> V_77 & V_79 )
F_37 ( V_75 -> V_16 , 1 ) ;
F_53 ( V_11 -> V_16 ) ;
F_54 ( V_75 -> V_16 , V_11 -> V_16 ) ;
F_55 ( V_75 -> V_16 , V_11 -> V_16 ) ;
F_56 ( V_11 -> V_16 ) ;
}
}
static void F_57 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
F_58 ( L_9 ,
V_19 , V_15 , V_15 -> V_80 ) ;
memcpy ( V_19 -> V_81 , V_15 -> V_81 , V_15 -> V_80 ) ;
V_19 -> V_82 = V_83 ;
F_41 ( V_84 , V_19 ) ;
}
static void F_59 ( struct V_10 * V_11 ,
struct V_22 * V_75 ,
struct V_22 * V_76 )
__releases( &bond->curr_slave_lock
static bool F_60 ( struct V_10 * V_11 )
{
struct V_22 * V_85 = V_11 -> V_86 ;
struct V_22 * V_87 = V_11 -> V_63 ;
if ( ! V_85 || ! V_87 || V_87 -> V_28 != V_29 )
return true ;
if ( V_11 -> V_88 ) {
V_11 -> V_88 = false ;
return true ;
}
if ( V_11 -> V_27 . V_89 == V_90 &&
( V_85 -> V_33 < V_87 -> V_33 ||
( V_85 -> V_33 == V_87 -> V_33 && V_85 -> V_35 <= V_87 -> V_35 ) ) )
return false ;
if ( V_11 -> V_27 . V_89 == V_91 )
return false ;
return true ;
}
static struct V_22 * F_61 ( struct V_10 * V_11 )
{
struct V_22 * V_75 , * V_76 ;
struct V_22 * V_92 = NULL ;
int V_93 = V_11 -> V_27 . V_94 ;
int V_95 ;
V_75 = V_11 -> V_63 ;
if ( ! V_75 ) {
V_75 = F_62 ( V_11 ) ;
if ( ! V_75 )
return NULL ;
}
if ( ( V_11 -> V_86 ) &&
V_11 -> V_86 -> V_28 == V_29 &&
F_60 ( V_11 ) ) {
V_75 = V_11 -> V_86 ;
}
V_76 = V_75 ;
F_63 (bond, new_active, i, old_active) {
if ( V_75 -> V_28 == V_29 ) {
return V_75 ;
} else if ( V_75 -> V_28 == V_96 &&
F_64 ( V_75 -> V_16 ) ) {
if ( V_75 -> V_97 < V_93 ) {
V_93 = V_75 -> V_97 ;
V_92 = V_75 ;
}
}
}
return V_92 ;
}
static bool F_65 ( struct V_10 * V_11 )
{
struct V_22 * V_22 = V_11 -> V_63 ;
F_58 ( L_10 ,
V_11 -> V_16 -> V_54 , V_22 ? V_22 -> V_16 -> V_54 : L_11 ) ;
if ( ! V_22 || ! V_11 -> V_98 ||
F_66 ( V_99 , & V_22 -> V_16 -> V_100 ) )
return false ;
return true ;
}
void F_67 ( struct V_10 * V_11 , struct V_22 * V_75 )
{
struct V_22 * V_76 = V_11 -> V_63 ;
if ( V_76 == V_75 )
return;
if ( V_75 ) {
V_75 -> V_101 = V_101 ;
if ( V_75 -> V_28 == V_96 ) {
if ( F_34 ( V_11 -> V_27 . V_1 ) ) {
F_68 ( L_12 ,
V_11 -> V_16 -> V_54 , V_75 -> V_16 -> V_54 ,
( V_11 -> V_27 . V_94 - V_75 -> V_97 ) * V_11 -> V_27 . V_102 ) ;
}
V_75 -> V_97 = 0 ;
V_75 -> V_28 = V_29 ;
if ( V_11 -> V_27 . V_1 == V_7 )
F_69 ( V_75 , V_29 ) ;
if ( F_17 ( V_11 ) )
F_70 ( V_11 , V_75 , V_29 ) ;
} else {
if ( F_34 ( V_11 -> V_27 . V_1 ) ) {
F_68 ( L_13 ,
V_11 -> V_16 -> V_54 , V_75 -> V_16 -> V_54 ) ;
}
}
}
if ( F_34 ( V_11 -> V_27 . V_1 ) )
F_51 ( V_11 , V_75 , V_76 ) ;
if ( F_17 ( V_11 ) ) {
F_71 ( V_11 , V_75 ) ;
if ( V_76 )
F_72 ( V_76 ) ;
if ( V_75 )
F_73 ( V_75 ) ;
} else {
F_74 ( V_11 -> V_63 , V_75 ) ;
}
if ( V_11 -> V_27 . V_1 == V_4 ) {
if ( V_76 )
F_72 ( V_76 ) ;
if ( V_75 ) {
bool V_103 = false ;
F_73 ( V_75 ) ;
if ( V_11 -> V_27 . V_104 )
F_59 ( V_11 , V_75 ,
V_76 ) ;
if ( F_30 ( V_11 -> V_16 ) ) {
V_11 -> V_98 =
V_11 -> V_27 . V_105 ;
V_103 =
F_65 ( V_11 ) ;
}
F_44 ( & V_11 -> V_67 ) ;
F_75 ( & V_11 -> V_106 ) ;
F_41 ( V_107 , V_11 -> V_16 ) ;
if ( V_103 )
F_41 ( V_108 ,
V_11 -> V_16 ) ;
F_76 ( & V_11 -> V_106 ) ;
F_43 ( & V_11 -> V_67 ) ;
}
}
if ( F_30 ( V_11 -> V_16 ) && ( V_11 -> V_27 . V_109 > 0 ) &&
( ( F_34 ( V_11 -> V_27 . V_1 ) && V_75 ) ||
V_11 -> V_27 . V_1 == V_3 ) ) {
V_11 -> V_68 = V_11 -> V_27 . V_109 ;
F_40 ( V_11 -> V_64 , & V_11 -> V_65 , 1 ) ;
}
}
void F_77 ( struct V_10 * V_11 )
{
struct V_22 * V_110 ;
int V_111 ;
V_110 = F_61 ( V_11 ) ;
if ( V_110 != V_11 -> V_63 ) {
F_67 ( V_11 , V_110 ) ;
V_111 = F_19 ( V_11 ) ;
if ( ! V_111 )
return;
if ( F_22 ( V_11 -> V_16 ) ) {
F_68 ( L_14 ,
V_11 -> V_16 -> V_54 ) ;
} else {
F_68 ( L_15 ,
V_11 -> V_16 -> V_54 ) ;
}
}
}
static void F_78 ( struct V_10 * V_11 , struct V_22 * V_112 )
{
F_79 ( & V_112 -> V_113 , & V_11 -> V_25 ) ;
V_11 -> V_114 ++ ;
}
static void F_80 ( struct V_10 * V_11 , struct V_22 * V_22 )
{
F_81 ( & V_22 -> V_113 ) ;
V_11 -> V_114 -- ;
}
static inline int F_82 ( struct V_22 * V_22 )
{
struct V_115 * V_116 ;
int V_62 = 0 ;
V_116 = F_83 ( sizeof( * V_116 ) , V_117 ) ;
V_62 = - V_118 ;
if ( ! V_116 )
goto V_119;
V_62 = F_84 ( V_116 , V_22 -> V_16 , V_117 ) ;
if ( V_62 ) {
F_85 ( V_116 ) ;
goto V_119;
}
V_22 -> V_116 = V_116 ;
V_119:
return V_62 ;
}
static inline void F_86 ( struct V_22 * V_22 )
{
struct V_115 * V_116 = V_22 -> V_116 ;
if ( ! V_116 )
return;
V_22 -> V_116 = NULL ;
F_87 ( V_116 ) ;
}
static inline bool F_88 ( struct V_14 * V_15 )
{
if ( V_15 -> V_120 & V_121 )
return false ;
if ( ! V_15 -> V_43 -> V_122 )
return false ;
return true ;
}
static void F_89 ( struct V_14 * V_19 )
{
}
static void F_90 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 ;
F_12 (bond, slave)
if ( F_64 ( V_22 -> V_16 ) )
F_86 ( V_22 ) ;
}
static int F_91 ( struct V_14 * V_16 , struct V_123 * V_124 , T_5 V_125 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_22 * V_22 ;
int V_62 = 0 ;
F_12 (bond, slave) {
V_62 = F_82 ( V_22 ) ;
if ( V_62 ) {
F_90 ( V_16 ) ;
break;
}
}
return V_62 ;
}
static inline int F_82 ( struct V_22 * V_22 )
{
return 0 ;
}
static inline void F_86 ( struct V_22 * V_22 )
{
}
static void F_90 ( struct V_14 * V_19 )
{
}
static T_6 F_92 ( struct V_14 * V_16 ,
T_6 V_126 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
T_6 V_127 ;
struct V_22 * V_22 ;
if ( F_20 ( & V_11 -> V_25 ) ) {
V_126 |= V_128 ;
return V_126 ;
}
V_127 = V_126 ;
V_126 &= ~ V_129 ;
V_126 |= V_130 ;
F_12 (bond, slave) {
V_126 = F_93 ( V_126 ,
V_22 -> V_16 -> V_126 ,
V_127 ) ;
}
V_126 = F_94 ( V_126 , V_127 ) ;
return V_126 ;
}
static void F_95 ( struct V_10 * V_11 )
{
unsigned int V_77 , V_131 = V_132 ;
T_6 V_133 = V_134 ;
unsigned short V_135 = V_136 ;
unsigned int V_137 = V_138 ;
struct V_14 * V_19 = V_11 -> V_16 ;
T_2 V_139 = V_140 ;
struct V_22 * V_22 ;
if ( F_20 ( & V_11 -> V_25 ) )
goto V_141;
F_12 (bond, slave) {
V_133 = F_93 ( V_133 ,
V_22 -> V_16 -> V_133 , V_134 ) ;
V_131 &= V_22 -> V_16 -> V_120 ;
if ( V_22 -> V_16 -> V_142 > V_135 )
V_135 = V_22 -> V_16 -> V_142 ;
V_137 = F_96 ( V_137 , V_22 -> V_16 -> V_137 ) ;
V_139 = F_96 ( V_139 , V_22 -> V_16 -> V_139 ) ;
}
V_141:
V_19 -> V_133 = V_133 ;
V_19 -> V_142 = V_135 ;
V_19 -> V_139 = V_139 ;
F_97 ( V_19 , V_137 ) ;
V_77 = V_19 -> V_120 & ~ V_132 ;
V_19 -> V_120 = V_77 | V_131 ;
F_98 ( V_19 ) ;
}
static void F_99 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
V_19 -> V_143 = V_15 -> V_143 ;
V_19 -> type = V_15 -> type ;
V_19 -> V_142 = V_15 -> V_142 ;
V_19 -> V_80 = V_15 -> V_80 ;
memcpy ( V_19 -> V_144 , V_15 -> V_144 ,
V_15 -> V_80 ) ;
}
static bool F_100 ( struct V_12 * V_13 ,
struct V_22 * V_22 ,
struct V_10 * V_11 )
{
if ( F_101 ( V_22 ) ) {
if ( V_11 -> V_27 . V_1 == V_9 &&
V_13 -> V_145 != V_146 &&
V_13 -> V_145 != V_147 )
return false ;
return true ;
}
return false ;
}
static T_7 F_102 ( struct V_12 * * V_148 )
{
struct V_12 * V_13 = * V_148 ;
struct V_22 * V_22 ;
struct V_10 * V_11 ;
int (* F_103)( const struct V_12 * , struct V_10 * ,
struct V_22 * );
int V_149 = V_150 ;
V_13 = F_104 ( V_13 , V_117 ) ;
if ( F_5 ( ! V_13 ) )
return V_151 ;
* V_148 = V_13 ;
V_22 = F_105 ( V_13 -> V_16 ) ;
V_11 = V_22 -> V_11 ;
if ( V_11 -> V_27 . V_152 )
V_22 -> V_16 -> V_153 = V_101 ;
F_103 = F_106 ( V_11 -> F_103 ) ;
if ( F_103 ) {
V_149 = F_103 ( V_13 , V_11 , V_22 ) ;
if ( V_149 == V_151 ) {
F_107 ( V_13 ) ;
return V_149 ;
}
}
if ( F_100 ( V_13 , V_22 , V_11 ) ) {
return V_154 ;
}
V_13 -> V_16 = V_11 -> V_16 ;
if ( V_11 -> V_27 . V_1 == V_9 &&
V_11 -> V_16 -> V_120 & V_155 &&
V_13 -> V_145 == V_156 ) {
if ( F_5 ( F_108 ( V_13 ,
V_13 -> V_157 - F_109 ( V_13 ) ) ) ) {
F_110 ( V_13 ) ;
return V_151 ;
}
memcpy ( F_111 ( V_13 ) -> V_158 , V_11 -> V_16 -> V_81 , V_73 ) ;
}
return V_149 ;
}
static int F_112 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
int V_62 ;
V_62 = F_113 ( V_15 , V_19 ) ;
if ( V_62 )
return V_62 ;
V_15 -> V_77 |= V_159 ;
F_114 ( V_160 , V_15 , V_159 ) ;
return 0 ;
}
static void F_115 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
F_116 ( V_15 , V_19 ) ;
V_15 -> V_77 &= ~ V_159 ;
F_114 ( V_160 , V_15 , V_159 ) ;
}
int F_117 ( struct V_14 * V_19 , struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
const struct V_41 * V_42 = V_15 -> V_43 ;
struct V_22 * V_112 = NULL ;
struct V_161 V_162 ;
int V_163 ;
int V_23 = 0 , V_95 ;
if ( ! V_11 -> V_27 . V_48 &&
V_15 -> V_50 -> V_51 == NULL &&
V_42 -> V_52 == NULL ) {
F_118 ( L_16 ,
V_19 -> V_54 , V_15 -> V_54 ) ;
}
if ( V_15 -> V_77 & V_159 ) {
F_58 ( L_17 ) ;
return - V_164 ;
}
if ( V_15 -> V_126 & V_128 ) {
F_58 ( L_18 , V_15 -> V_54 ) ;
if ( F_119 ( V_19 ) ) {
F_120 ( L_19 ,
V_19 -> V_54 , V_15 -> V_54 , V_19 -> V_54 ) ;
return - V_165 ;
} else {
F_118 ( L_20 ,
V_19 -> V_54 , V_15 -> V_54 ,
V_15 -> V_54 , V_19 -> V_54 ) ;
}
} else {
F_58 ( L_21 , V_15 -> V_54 ) ;
}
if ( ( V_15 -> V_77 & V_166 ) ) {
F_120 ( L_22 ,
V_15 -> V_54 ) ;
V_23 = - V_165 ;
goto V_167;
}
if ( F_20 ( & V_11 -> V_25 ) ) {
if ( V_19 -> type != V_15 -> type ) {
F_58 ( L_23 ,
V_19 -> V_54 ,
V_19 -> type , V_15 -> type ) ;
V_23 = F_41 ( V_168 ,
V_19 ) ;
V_23 = F_121 ( V_23 ) ;
if ( V_23 ) {
F_120 ( L_24 ,
V_19 -> V_54 ) ;
V_23 = - V_164 ;
goto V_167;
}
F_122 ( V_19 ) ;
F_123 ( V_19 ) ;
if ( V_15 -> type != V_169 )
F_99 ( V_19 , V_15 ) ;
else {
F_124 ( V_19 ) ;
V_19 -> V_120 &= ~ V_170 ;
}
F_41 ( V_171 ,
V_19 ) ;
}
} else if ( V_19 -> type != V_15 -> type ) {
F_120 ( L_25 ,
V_15 -> V_54 ,
V_15 -> type , V_19 -> type ) ;
V_23 = - V_172 ;
goto V_167;
}
if ( V_42 -> V_173 == NULL ) {
if ( F_20 ( & V_11 -> V_25 ) ) {
F_118 ( L_26 ,
V_19 -> V_54 ) ;
V_11 -> V_27 . V_104 = V_174 ;
} else if ( V_11 -> V_27 . V_104 != V_174 ) {
F_120 ( L_27 ,
V_19 -> V_54 ) ;
V_23 = - V_175 ;
goto V_167;
}
}
F_41 ( V_176 , V_15 ) ;
if ( F_20 ( & V_11 -> V_25 ) &&
V_11 -> V_16 -> V_82 == V_177 )
F_57 ( V_11 -> V_16 , V_15 ) ;
V_112 = F_83 ( sizeof( struct V_22 ) , V_178 ) ;
if ( ! V_112 ) {
V_23 = - V_118 ;
goto V_167;
}
F_125 ( & V_112 -> V_113 ) ;
V_112 -> V_179 = 0 ;
V_112 -> V_180 = V_15 -> V_181 ;
V_23 = F_126 ( V_15 , V_11 -> V_16 -> V_181 ) ;
if ( V_23 ) {
F_58 ( L_28 , V_23 ) ;
goto V_182;
}
memcpy ( V_112 -> V_183 , V_15 -> V_81 , V_73 ) ;
if ( ! V_11 -> V_27 . V_104 ) {
memcpy ( V_162 . V_184 , V_19 -> V_81 , V_19 -> V_80 ) ;
V_162 . V_185 = V_15 -> type ;
V_23 = F_127 ( V_15 , & V_162 ) ;
if ( V_23 ) {
F_58 ( L_29 , V_23 ) ;
goto V_186;
}
}
V_23 = F_112 ( V_19 , V_15 ) ;
if ( V_23 ) {
F_58 ( L_30 , V_23 ) ;
goto V_187;
}
V_23 = F_128 ( V_15 ) ;
if ( V_23 ) {
F_58 ( L_31 , V_15 -> V_54 ) ;
goto V_188;
}
V_112 -> V_11 = V_11 ;
V_112 -> V_16 = V_15 ;
V_15 -> V_120 |= V_189 ;
if ( F_17 ( V_11 ) ) {
V_23 = F_129 ( V_11 , V_112 ) ;
if ( V_23 )
goto V_190;
}
if ( ! F_34 ( V_11 -> V_27 . V_1 ) ) {
if ( V_19 -> V_77 & V_78 ) {
V_23 = F_35 ( V_15 , 1 ) ;
if ( V_23 )
goto V_190;
}
if ( V_19 -> V_77 & V_79 ) {
V_23 = F_37 ( V_15 , 1 ) ;
if ( V_23 )
goto V_190;
}
F_53 ( V_19 ) ;
F_130 ( V_15 , V_19 ) ;
F_131 ( V_15 , V_19 ) ;
F_56 ( V_19 ) ;
}
if ( V_11 -> V_27 . V_1 == V_7 ) {
T_4 V_72 [ V_73 ] = V_74 ;
F_132 ( V_15 , V_72 ) ;
}
V_23 = F_133 ( V_15 , V_19 ) ;
if ( V_23 ) {
F_120 ( L_32 ,
V_19 -> V_54 , V_15 -> V_54 ) ;
goto V_190;
}
F_43 ( & V_11 -> V_106 ) ;
F_78 ( V_11 , V_112 ) ;
V_112 -> V_97 = 0 ;
V_112 -> V_191 = 0 ;
F_44 ( & V_11 -> V_106 ) ;
F_95 ( V_11 ) ;
F_25 ( V_112 ) ;
F_76 ( & V_11 -> V_106 ) ;
V_112 -> V_192 = V_101 -
( F_134 ( V_11 -> V_27 . V_152 ) + 1 ) ;
for ( V_95 = 0 ; V_95 < V_193 ; V_95 ++ )
V_112 -> V_194 [ V_95 ] = V_112 -> V_192 ;
if ( V_11 -> V_27 . V_102 && ! V_11 -> V_27 . V_48 ) {
V_163 = F_28 ( V_11 , V_15 , 1 ) ;
if ( ( V_163 == - 1 ) && ! V_11 -> V_27 . V_152 ) {
F_118 ( L_33 ,
V_19 -> V_54 , V_15 -> V_54 ) ;
} else if ( V_163 == - 1 ) {
F_118 ( L_34 ,
V_19 -> V_54 , V_15 -> V_54 ) ;
}
}
if ( V_11 -> V_27 . V_102 ) {
if ( F_28 ( V_11 , V_15 , 0 ) == V_49 ) {
if ( V_11 -> V_27 . V_94 ) {
V_112 -> V_28 = V_96 ;
V_112 -> V_97 = V_11 -> V_27 . V_94 ;
} else {
V_112 -> V_28 = V_29 ;
}
} else {
V_112 -> V_28 = V_195 ;
}
} else if ( V_11 -> V_27 . V_152 ) {
V_112 -> V_28 = ( F_22 ( V_15 ) ?
V_29 : V_195 ) ;
} else {
V_112 -> V_28 = V_29 ;
}
if ( V_112 -> V_28 != V_195 )
V_112 -> V_101 = V_101 ;
F_58 ( L_35 ,
V_112 -> V_28 == V_195 ? L_36 :
( V_112 -> V_28 == V_29 ? L_37 : L_38 ) ) ;
if ( F_34 ( V_11 -> V_27 . V_1 ) && V_11 -> V_27 . V_196 [ 0 ] ) {
if ( strcmp ( V_11 -> V_27 . V_196 , V_112 -> V_16 -> V_54 ) == 0 ) {
V_11 -> V_86 = V_112 ;
V_11 -> V_88 = true ;
}
}
F_43 ( & V_11 -> V_67 ) ;
switch ( V_11 -> V_27 . V_1 ) {
case V_4 :
F_72 ( V_112 ) ;
F_77 ( V_11 ) ;
break;
case V_7 :
F_72 ( V_112 ) ;
if ( F_62 ( V_11 ) == V_112 ) {
F_135 ( V_112 ) . V_197 = 1 ;
F_136 ( V_11 , 1000 / V_198 ) ;
} else {
struct V_22 * V_199 ;
V_199 = F_137 ( V_11 , V_112 ) ;
F_135 ( V_112 ) . V_197 =
F_135 ( V_199 ) . V_197 + 1 ;
}
F_138 ( V_112 ) ;
break;
case V_8 :
case V_9 :
F_139 ( V_112 ) ;
F_72 ( V_112 ) ;
F_77 ( V_11 ) ;
break;
default:
F_58 ( L_39 ) ;
F_139 ( V_112 ) ;
if ( ! V_11 -> V_63 && V_112 -> V_28 == V_29 )
F_74 ( V_11 -> V_63 , V_112 ) ;
break;
}
F_44 ( & V_11 -> V_67 ) ;
F_19 ( V_11 ) ;
#ifdef F_140
V_15 -> V_200 = V_11 -> V_16 -> V_200 ;
if ( V_15 -> V_200 ) {
if ( F_82 ( V_112 ) ) {
F_75 ( & V_11 -> V_106 ) ;
F_68 ( L_40
L_41 ,
V_19 -> V_54 ) ;
V_23 = - V_164 ;
goto V_201;
}
}
#endif
F_75 ( & V_11 -> V_106 ) ;
V_23 = F_141 ( V_19 , V_15 ) ;
if ( V_23 )
goto V_201;
V_23 = F_142 ( V_15 , F_102 ,
V_112 ) ;
if ( V_23 ) {
F_58 ( L_42 , V_23 ) ;
goto V_202;
}
F_68 ( L_43 ,
V_19 -> V_54 , V_15 -> V_54 ,
F_143 ( V_112 ) ? L_44 : L_45 ,
V_112 -> V_28 != V_195 ? L_46 : L_47 ) ;
return 0 ;
V_202:
F_144 ( V_19 , V_15 ) ;
V_201:
if ( ! F_34 ( V_11 -> V_27 . V_1 ) )
F_47 ( V_19 , V_15 ) ;
F_145 ( V_15 , V_19 ) ;
F_43 ( & V_11 -> V_106 ) ;
F_80 ( V_11 , V_112 ) ;
if ( V_11 -> V_86 == V_112 )
V_11 -> V_86 = NULL ;
if ( V_11 -> V_63 == V_112 ) {
F_67 ( V_11 , NULL ) ;
F_44 ( & V_11 -> V_106 ) ;
F_76 ( & V_11 -> V_106 ) ;
F_43 ( & V_11 -> V_67 ) ;
F_77 ( V_11 ) ;
F_44 ( & V_11 -> V_67 ) ;
F_75 ( & V_11 -> V_106 ) ;
} else {
F_44 ( & V_11 -> V_106 ) ;
}
F_86 ( V_112 ) ;
V_190:
V_15 -> V_120 &= ~ V_189 ;
F_146 ( V_15 ) ;
V_188:
F_115 ( V_19 , V_15 ) ;
V_187:
if ( ! V_11 -> V_27 . V_104 ) {
memcpy ( V_162 . V_184 , V_112 -> V_183 , V_73 ) ;
V_162 . V_185 = V_15 -> type ;
F_127 ( V_15 , & V_162 ) ;
}
V_186:
F_126 ( V_15 , V_112 -> V_180 ) ;
V_182:
F_85 ( V_112 ) ;
V_167:
F_95 ( V_11 ) ;
if ( F_20 ( & V_11 -> V_25 ) &&
F_147 ( V_19 -> V_81 , V_15 -> V_81 ) )
F_148 ( V_19 ) ;
return V_23 ;
}
static int F_149 ( struct V_14 * V_19 ,
struct V_14 * V_15 ,
bool V_203 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_204 ;
struct V_161 V_162 ;
int V_205 = V_19 -> V_77 ;
T_6 V_206 = V_19 -> V_126 ;
if ( ! ( V_15 -> V_77 & V_159 ) ||
! F_150 ( V_15 , V_19 ) ) {
F_120 ( L_48 ,
V_19 -> V_54 , V_15 -> V_54 ) ;
return - V_172 ;
}
F_151 () ;
F_43 ( & V_11 -> V_106 ) ;
V_22 = F_8 ( V_11 , V_15 ) ;
if ( ! V_22 ) {
F_68 ( L_49 ,
V_19 -> V_54 , V_15 -> V_54 ) ;
F_44 ( & V_11 -> V_106 ) ;
F_152 () ;
return - V_172 ;
}
F_44 ( & V_11 -> V_106 ) ;
F_153 ( V_15 ) ;
F_43 ( & V_11 -> V_106 ) ;
if ( V_11 -> V_27 . V_1 == V_7 ) {
F_154 ( V_22 ) ;
}
F_68 ( L_50 ,
V_19 -> V_54 ,
F_143 ( V_22 ) ? L_51 : L_52 ,
V_15 -> V_54 ) ;
V_204 = V_11 -> V_63 ;
V_11 -> V_207 = NULL ;
F_80 ( V_11 , V_22 ) ;
if ( ! V_203 && ! V_11 -> V_27 . V_104 ) {
if ( F_147 ( V_19 -> V_81 , V_22 -> V_183 ) &&
! F_20 ( & V_11 -> V_25 ) )
F_155 ( L_53 ,
V_19 -> V_54 , V_15 -> V_54 ,
V_22 -> V_183 ,
V_19 -> V_54 , V_15 -> V_54 ) ;
}
if ( V_11 -> V_86 == V_22 )
V_11 -> V_86 = NULL ;
if ( V_204 == V_22 )
F_67 ( V_11 , NULL ) ;
if ( F_17 ( V_11 ) ) {
F_44 ( & V_11 -> V_106 ) ;
F_156 ( V_11 , V_22 ) ;
F_43 ( & V_11 -> V_106 ) ;
}
if ( V_203 ) {
F_74 ( V_11 -> V_63 , NULL ) ;
} else if ( V_204 == V_22 ) {
F_44 ( & V_11 -> V_106 ) ;
F_76 ( & V_11 -> V_106 ) ;
F_43 ( & V_11 -> V_67 ) ;
F_77 ( V_11 ) ;
F_44 ( & V_11 -> V_67 ) ;
F_75 ( & V_11 -> V_106 ) ;
F_43 ( & V_11 -> V_106 ) ;
}
if ( F_20 ( & V_11 -> V_25 ) ) {
F_19 ( V_11 ) ;
F_148 ( V_19 ) ;
if ( F_119 ( V_19 ) ) {
F_118 ( L_54 ,
V_19 -> V_54 , V_19 -> V_54 ) ;
F_118 ( L_55 ,
V_19 -> V_54 ) ;
}
}
F_44 ( & V_11 -> V_106 ) ;
F_152 () ;
F_157 () ;
if ( F_20 ( & V_11 -> V_25 ) ) {
F_41 ( V_84 , V_11 -> V_16 ) ;
F_41 ( V_208 , V_11 -> V_16 ) ;
}
F_95 ( V_11 ) ;
if ( ! ( V_19 -> V_126 & V_128 ) &&
( V_206 & V_128 ) )
F_68 ( L_56 ,
V_19 -> V_54 , V_15 -> V_54 , V_19 -> V_54 ) ;
F_144 ( V_19 , V_15 ) ;
F_145 ( V_15 , V_19 ) ;
if ( ! F_34 ( V_11 -> V_27 . V_1 ) ) {
if ( V_205 & V_78 )
F_35 ( V_15 , - 1 ) ;
if ( V_205 & V_79 )
F_37 ( V_15 , - 1 ) ;
F_47 ( V_19 , V_15 ) ;
}
F_115 ( V_19 , V_15 ) ;
F_86 ( V_22 ) ;
F_146 ( V_15 ) ;
if ( V_11 -> V_27 . V_104 != V_174 ) {
memcpy ( V_162 . V_184 , V_22 -> V_183 , V_73 ) ;
V_162 . V_185 = V_15 -> type ;
F_127 ( V_15 , & V_162 ) ;
}
F_126 ( V_15 , V_22 -> V_180 ) ;
V_15 -> V_120 &= ~ V_189 ;
F_85 ( V_22 ) ;
return 0 ;
}
int F_158 ( struct V_14 * V_19 , struct V_14 * V_15 )
{
return F_149 ( V_19 , V_15 , false ) ;
}
static int F_159 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
int V_149 ;
V_149 = F_158 ( V_19 , V_15 ) ;
if ( V_149 == 0 && F_20 ( & V_11 -> V_25 ) ) {
V_19 -> V_120 |= V_121 ;
F_68 ( L_57 ,
V_19 -> V_54 , V_19 -> V_54 ) ;
F_160 ( V_19 ) ;
}
return V_149 ;
}
static int F_161 ( struct V_14 * V_19 , struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_76 = NULL ;
struct V_22 * V_75 = NULL ;
int V_23 = 0 ;
if ( ! F_34 ( V_11 -> V_27 . V_1 ) )
return - V_172 ;
if ( ! ( V_15 -> V_77 & V_159 ) ||
! F_150 ( V_15 , V_19 ) )
return - V_172 ;
F_76 ( & V_11 -> V_106 ) ;
V_76 = V_11 -> V_63 ;
V_75 = F_8 ( V_11 , V_15 ) ;
if ( V_75 && V_75 == V_76 ) {
F_75 ( & V_11 -> V_106 ) ;
return 0 ;
}
if ( V_75 &&
V_76 &&
V_75 -> V_28 == V_29 &&
F_64 ( V_75 -> V_16 ) ) {
F_151 () ;
F_43 ( & V_11 -> V_67 ) ;
F_67 ( V_11 , V_75 ) ;
F_44 ( & V_11 -> V_67 ) ;
F_152 () ;
} else
V_23 = - V_172 ;
F_75 ( & V_11 -> V_106 ) ;
return V_23 ;
}
static int F_162 ( struct V_14 * V_19 , struct V_209 * V_210 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
V_210 -> V_211 = V_11 -> V_27 . V_1 ;
V_210 -> V_102 = V_11 -> V_27 . V_102 ;
F_76 ( & V_11 -> V_106 ) ;
V_210 -> V_212 = V_11 -> V_114 ;
F_75 ( & V_11 -> V_106 ) ;
return 0 ;
}
static int F_163 ( struct V_14 * V_19 , struct V_213 * V_210 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
int V_95 = 0 , V_23 = - V_214 ;
struct V_22 * V_22 ;
F_76 ( & V_11 -> V_106 ) ;
F_12 (bond, slave) {
if ( V_95 ++ == ( int ) V_210 -> V_215 ) {
V_23 = 0 ;
strcpy ( V_210 -> V_216 , V_22 -> V_16 -> V_54 ) ;
V_210 -> V_28 = V_22 -> V_28 ;
V_210 -> V_100 = F_164 ( V_22 ) ;
V_210 -> V_191 = V_22 -> V_191 ;
break;
}
}
F_75 ( & V_11 -> V_106 ) ;
return V_23 ;
}
static int F_165 ( struct V_10 * V_11 )
{
int V_217 , V_218 = 0 ;
struct V_22 * V_22 ;
bool V_219 ;
V_219 = ! V_11 -> V_63 ? true : false ;
F_12 (bond, slave) {
V_22 -> V_220 = V_221 ;
V_217 = F_28 ( V_11 , V_22 -> V_16 , 0 ) ;
switch ( V_22 -> V_28 ) {
case V_29 :
if ( V_217 )
continue;
V_22 -> V_28 = V_222 ;
V_22 -> V_97 = V_11 -> V_27 . V_223 ;
if ( V_22 -> V_97 ) {
F_68 ( L_58 ,
V_11 -> V_16 -> V_54 ,
( V_11 -> V_27 . V_1 ==
V_4 ) ?
( F_143 ( V_22 ) ?
L_59 : L_60 ) : L_61 ,
V_22 -> V_16 -> V_54 ,
V_11 -> V_27 . V_223 * V_11 -> V_27 . V_102 ) ;
}
case V_222 :
if ( V_217 ) {
V_22 -> V_28 = V_29 ;
V_22 -> V_101 = V_101 ;
F_68 ( L_62 ,
V_11 -> V_16 -> V_54 ,
( V_11 -> V_27 . V_223 - V_22 -> V_97 ) *
V_11 -> V_27 . V_102 ,
V_22 -> V_16 -> V_54 ) ;
continue;
}
if ( V_22 -> V_97 <= 0 ) {
V_22 -> V_220 = V_195 ;
V_218 ++ ;
continue;
}
V_22 -> V_97 -- ;
break;
case V_195 :
if ( ! V_217 )
continue;
V_22 -> V_28 = V_96 ;
V_22 -> V_97 = V_11 -> V_27 . V_94 ;
if ( V_22 -> V_97 ) {
F_68 ( L_63 ,
V_11 -> V_16 -> V_54 , V_22 -> V_16 -> V_54 ,
V_219 ? 0 :
V_11 -> V_27 . V_94 *
V_11 -> V_27 . V_102 ) ;
}
case V_96 :
if ( ! V_217 ) {
V_22 -> V_28 = V_195 ;
F_68 ( L_64 ,
V_11 -> V_16 -> V_54 ,
( V_11 -> V_27 . V_94 - V_22 -> V_97 ) *
V_11 -> V_27 . V_102 ,
V_22 -> V_16 -> V_54 ) ;
continue;
}
if ( V_219 )
V_22 -> V_97 = 0 ;
if ( V_22 -> V_97 <= 0 ) {
V_22 -> V_220 = V_29 ;
V_218 ++ ;
V_219 = false ;
continue;
}
V_22 -> V_97 -- ;
break;
}
}
return V_218 ;
}
static void F_166 ( struct V_10 * V_11 )
{
struct V_22 * V_22 ;
F_12 (bond, slave) {
switch ( V_22 -> V_220 ) {
case V_221 :
continue;
case V_29 :
V_22 -> V_28 = V_29 ;
V_22 -> V_101 = V_101 ;
if ( V_11 -> V_27 . V_1 == V_7 ) {
F_167 ( V_22 ) ;
} else if ( V_11 -> V_27 . V_1 != V_4 ) {
F_139 ( V_22 ) ;
} else if ( V_22 != V_11 -> V_86 ) {
F_167 ( V_22 ) ;
}
F_68 ( L_65 ,
V_11 -> V_16 -> V_54 , V_22 -> V_16 -> V_54 ,
V_22 -> V_33 == V_34 ? 0 : V_22 -> V_33 ,
V_22 -> V_35 ? L_66 : L_67 ) ;
if ( V_11 -> V_27 . V_1 == V_7 )
F_69 ( V_22 , V_29 ) ;
if ( F_17 ( V_11 ) )
F_70 ( V_11 , V_22 ,
V_29 ) ;
if ( ! V_11 -> V_63 ||
( V_22 == V_11 -> V_86 ) )
goto V_224;
continue;
case V_195 :
if ( V_22 -> V_191 < V_225 )
V_22 -> V_191 ++ ;
V_22 -> V_28 = V_195 ;
if ( V_11 -> V_27 . V_1 == V_4 ||
V_11 -> V_27 . V_1 == V_7 )
F_72 ( V_22 ) ;
F_68 ( L_68 ,
V_11 -> V_16 -> V_54 , V_22 -> V_16 -> V_54 ) ;
if ( V_11 -> V_27 . V_1 == V_7 )
F_69 ( V_22 ,
V_195 ) ;
if ( F_17 ( V_11 ) )
F_70 ( V_11 , V_22 ,
V_195 ) ;
if ( V_22 == V_11 -> V_63 )
goto V_224;
continue;
default:
F_120 ( L_69 ,
V_11 -> V_16 -> V_54 , V_22 -> V_220 ,
V_22 -> V_16 -> V_54 ) ;
V_22 -> V_220 = V_221 ;
continue;
}
V_224:
F_52 () ;
F_151 () ;
F_43 ( & V_11 -> V_67 ) ;
F_77 ( V_11 ) ;
F_44 ( & V_11 -> V_67 ) ;
F_152 () ;
}
F_19 ( V_11 ) ;
}
void F_168 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_46 ( V_71 , struct V_10 ,
V_226 . V_71 ) ;
bool V_103 = false ;
unsigned long V_97 ;
F_76 ( & V_11 -> V_106 ) ;
V_97 = F_134 ( V_11 -> V_27 . V_102 ) ;
if ( F_20 ( & V_11 -> V_25 ) )
goto V_227;
V_103 = F_65 ( V_11 ) ;
if ( F_165 ( V_11 ) ) {
F_75 ( & V_11 -> V_106 ) ;
if ( ! F_39 () ) {
F_76 ( & V_11 -> V_106 ) ;
V_97 = 1 ;
V_103 = false ;
goto V_227;
}
F_76 ( & V_11 -> V_106 ) ;
F_166 ( V_11 ) ;
F_75 ( & V_11 -> V_106 ) ;
F_42 () ;
F_76 ( & V_11 -> V_106 ) ;
}
V_227:
if ( V_11 -> V_27 . V_102 )
F_40 ( V_11 -> V_64 , & V_11 -> V_226 , V_97 ) ;
F_75 ( & V_11 -> V_106 ) ;
if ( V_103 ) {
if ( ! F_39 () )
return;
F_41 ( V_108 , V_11 -> V_16 ) ;
F_42 () ;
}
}
static bool F_169 ( struct V_10 * V_11 , T_8 V_228 )
{
struct V_14 * V_229 ;
struct V_230 * V_231 ;
bool V_149 = false ;
if ( V_228 == F_170 ( V_11 -> V_16 , 0 , V_228 ) )
return true ;
F_171 () ;
F_172 (bond->dev, upper, iter) {
if ( V_228 == F_170 ( V_229 , 0 , V_228 ) ) {
V_149 = true ;
break;
}
}
F_173 () ;
return V_149 ;
}
static void F_174 ( struct V_14 * V_15 , int V_232 , T_8 V_233 , T_8 V_234 , unsigned short V_235 )
{
struct V_12 * V_13 ;
F_58 ( L_70 , V_232 ,
V_15 -> V_54 , & V_233 , & V_234 , V_235 ) ;
V_13 = F_175 ( V_232 , V_236 , V_233 , V_15 , V_234 ,
NULL , V_15 -> V_81 , NULL ) ;
if ( ! V_13 ) {
F_120 ( L_71 ) ;
return;
}
if ( V_235 ) {
V_13 = F_176 ( V_13 , F_177 ( V_237 ) , V_235 ) ;
if ( ! V_13 ) {
F_120 ( L_72 ) ;
return;
}
}
F_178 ( V_13 ) ;
}
static void F_179 ( struct V_10 * V_11 , struct V_22 * V_22 )
{
struct V_14 * V_229 , * V_238 ;
struct V_230 * V_231 , * V_239 ;
struct V_240 * V_241 ;
T_8 * V_242 = V_11 -> V_27 . V_243 , V_162 ;
int V_95 , V_235 ;
for ( V_95 = 0 ; V_95 < V_193 && V_242 [ V_95 ] ; V_95 ++ ) {
F_58 ( L_73 , & V_242 [ V_95 ] ) ;
V_241 = F_180 ( F_181 ( V_11 -> V_16 ) , V_242 [ V_95 ] , 0 ,
V_244 , 0 ) ;
if ( F_182 ( V_241 ) ) {
F_58 ( L_74 ,
V_11 -> V_16 -> V_54 , & V_242 [ V_95 ] ) ;
continue;
}
V_235 = 0 ;
if ( V_241 -> V_245 . V_16 == V_11 -> V_16 )
goto V_246;
F_171 () ;
F_172 (bond->dev, vlan_upper, vlan_iter) {
if ( ! F_183 ( V_238 ) )
continue;
F_172 (vlan_upper, upper, iter) {
if ( V_229 == V_241 -> V_245 . V_16 ) {
V_235 = F_184 ( V_238 ) ;
F_173 () ;
goto V_246;
}
}
}
F_172 (bond->dev, upper, iter) {
if ( V_229 == V_241 -> V_245 . V_16 ) {
if ( F_183 ( V_229 ) )
V_235 = F_184 ( V_229 ) ;
F_173 () ;
goto V_246;
}
}
F_173 () ;
F_58 ( L_75 ,
V_11 -> V_16 -> V_54 , & V_242 [ V_95 ] ,
V_241 -> V_245 . V_16 ? V_241 -> V_245 . V_16 -> V_54 : L_11 ) ;
F_185 ( V_241 ) ;
continue;
V_246:
V_162 = F_170 ( V_241 -> V_245 . V_16 , V_242 [ V_95 ] , 0 ) ;
F_185 ( V_241 ) ;
F_174 ( V_22 -> V_16 , V_247 , V_242 [ V_95 ] ,
V_162 , V_235 ) ;
}
}
static void F_186 ( struct V_10 * V_11 , struct V_22 * V_22 , T_8 V_248 , T_8 V_249 )
{
int V_95 ;
if ( ! V_248 || ! F_169 ( V_11 , V_249 ) ) {
F_58 ( L_76 , & V_248 , & V_249 ) ;
return;
}
V_95 = F_187 ( V_11 -> V_27 . V_243 , V_248 ) ;
if ( V_95 == - 1 ) {
F_58 ( L_77 , & V_248 ) ;
return;
}
V_22 -> V_192 = V_101 ;
V_22 -> V_194 [ V_95 ] = V_101 ;
}
int F_188 ( const struct V_12 * V_13 , struct V_10 * V_11 ,
struct V_22 * V_22 )
{
struct V_250 * V_251 = (struct V_250 * ) V_13 -> V_157 ;
unsigned char * V_252 ;
T_8 V_248 , V_249 ;
int V_253 ;
if ( V_13 -> V_254 != F_189 ( V_236 ) )
return V_150 ;
F_76 ( & V_11 -> V_106 ) ;
if ( ! F_190 ( V_11 , V_22 ) )
goto V_255;
V_253 = F_191 ( V_11 -> V_16 ) ;
F_58 ( L_78 ,
V_11 -> V_16 -> V_54 , V_13 -> V_16 -> V_54 ) ;
if ( V_253 > F_192 ( V_13 ) ) {
V_251 = F_193 ( V_253 , V_117 ) ;
if ( ! V_251 )
goto V_255;
if ( F_194 ( V_13 , 0 , V_251 , V_253 ) < 0 )
goto V_255;
}
if ( V_251 -> V_256 != V_11 -> V_16 -> V_80 ||
V_13 -> V_145 == V_257 ||
V_13 -> V_145 == V_258 ||
V_251 -> V_259 != F_177 ( V_169 ) ||
V_251 -> V_260 != F_177 ( V_261 ) ||
V_251 -> V_262 != 4 )
goto V_255;
V_252 = ( unsigned char * ) ( V_251 + 1 ) ;
V_252 += V_11 -> V_16 -> V_80 ;
memcpy ( & V_248 , V_252 , 4 ) ;
V_252 += 4 + V_11 -> V_16 -> V_80 ;
memcpy ( & V_249 , V_252 , 4 ) ;
F_58 ( L_79 ,
V_11 -> V_16 -> V_54 , V_22 -> V_16 -> V_54 , F_164 ( V_22 ) ,
V_11 -> V_27 . V_263 , F_190 ( V_11 , V_22 ) ,
& V_248 , & V_249 ) ;
if ( F_143 ( V_22 ) )
F_186 ( V_11 , V_22 , V_248 , V_249 ) ;
else if ( V_11 -> V_63 &&
F_195 ( F_196 ( V_11 , V_11 -> V_63 ) ,
V_11 -> V_63 -> V_101 ) )
F_186 ( V_11 , V_22 , V_249 , V_248 ) ;
V_255:
F_75 ( & V_11 -> V_106 ) ;
if ( V_251 != (struct V_250 * ) V_13 -> V_157 )
F_85 ( V_251 ) ;
return V_150 ;
}
static bool F_197 ( struct V_10 * V_11 , unsigned long V_264 ,
int V_265 )
{
int V_266 = F_134 ( V_11 -> V_27 . V_152 ) ;
return F_198 ( V_101 ,
V_264 - V_266 ,
V_264 + V_265 * V_266 + V_266 / 2 ) ;
}
void F_199 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_46 ( V_71 , struct V_10 ,
V_267 . V_71 ) ;
struct V_22 * V_22 , * V_204 ;
int V_224 = 0 ;
F_76 ( & V_11 -> V_106 ) ;
if ( F_20 ( & V_11 -> V_25 ) )
goto V_227;
V_204 = V_11 -> V_63 ;
F_12 (bond, slave) {
unsigned long V_268 = F_200 ( V_22 -> V_16 ) ;
if ( V_22 -> V_28 != V_29 ) {
if ( F_197 ( V_11 , V_268 , 1 ) &&
F_197 ( V_11 , V_22 -> V_16 -> V_153 , 1 ) ) {
V_22 -> V_28 = V_29 ;
F_139 ( V_22 ) ;
if ( ! V_204 ) {
F_68 ( L_80 ,
V_11 -> V_16 -> V_54 ,
V_22 -> V_16 -> V_54 ) ;
V_224 = 1 ;
} else {
F_68 ( L_81 ,
V_11 -> V_16 -> V_54 ,
V_22 -> V_16 -> V_54 ) ;
}
}
} else {
if ( ! F_197 ( V_11 , V_268 , 2 ) ||
! F_197 ( V_11 , V_22 -> V_16 -> V_153 , 2 ) ) {
V_22 -> V_28 = V_195 ;
F_167 ( V_22 ) ;
if ( V_22 -> V_191 < V_225 )
V_22 -> V_191 ++ ;
F_68 ( L_82 ,
V_11 -> V_16 -> V_54 ,
V_22 -> V_16 -> V_54 ) ;
if ( V_22 == V_204 )
V_224 = 1 ;
}
}
if ( F_64 ( V_22 -> V_16 ) )
F_179 ( V_11 , V_22 ) ;
}
if ( V_224 ) {
F_151 () ;
F_43 ( & V_11 -> V_67 ) ;
F_77 ( V_11 ) ;
F_44 ( & V_11 -> V_67 ) ;
F_152 () ;
}
V_227:
if ( V_11 -> V_27 . V_152 )
F_40 ( V_11 -> V_64 , & V_11 -> V_267 ,
F_134 ( V_11 -> V_27 . V_152 ) ) ;
F_75 ( & V_11 -> V_106 ) ;
}
static int F_201 ( struct V_10 * V_11 )
{
unsigned long V_268 , V_153 ;
struct V_22 * V_22 ;
int V_218 = 0 ;
F_12 (bond, slave) {
V_22 -> V_220 = V_221 ;
V_153 = F_196 ( V_11 , V_22 ) ;
if ( V_22 -> V_28 != V_29 ) {
if ( F_197 ( V_11 , V_153 , 1 ) ) {
V_22 -> V_220 = V_29 ;
V_218 ++ ;
}
continue;
}
if ( F_197 ( V_11 , V_22 -> V_101 , 2 ) )
continue;
if ( ! F_143 ( V_22 ) &&
! V_11 -> V_207 &&
! F_197 ( V_11 , V_153 , 3 ) ) {
V_22 -> V_220 = V_195 ;
V_218 ++ ;
}
V_268 = F_200 ( V_22 -> V_16 ) ;
if ( F_143 ( V_22 ) &&
( ! F_197 ( V_11 , V_268 , 2 ) ||
! F_197 ( V_11 , V_153 , 2 ) ) ) {
V_22 -> V_220 = V_195 ;
V_218 ++ ;
}
}
return V_218 ;
}
static void F_202 ( struct V_10 * V_11 )
{
unsigned long V_268 ;
struct V_22 * V_22 ;
F_12 (bond, slave) {
switch ( V_22 -> V_220 ) {
case V_221 :
continue;
case V_29 :
V_268 = F_200 ( V_22 -> V_16 ) ;
if ( V_11 -> V_63 != V_22 ||
( ! V_11 -> V_63 &&
F_197 ( V_11 , V_268 , 1 ) ) ) {
V_22 -> V_28 = V_29 ;
if ( V_11 -> V_207 ) {
F_72 (
V_11 -> V_207 ) ;
V_11 -> V_207 = NULL ;
}
F_68 ( L_83 ,
V_11 -> V_16 -> V_54 , V_22 -> V_16 -> V_54 ) ;
if ( ! V_11 -> V_63 ||
( V_22 == V_11 -> V_86 ) )
goto V_224;
}
continue;
case V_195 :
if ( V_22 -> V_191 < V_225 )
V_22 -> V_191 ++ ;
V_22 -> V_28 = V_195 ;
F_72 ( V_22 ) ;
F_68 ( L_68 ,
V_11 -> V_16 -> V_54 , V_22 -> V_16 -> V_54 ) ;
if ( V_22 == V_11 -> V_63 ) {
V_11 -> V_207 = NULL ;
goto V_224;
}
continue;
default:
F_120 ( L_84 ,
V_11 -> V_16 -> V_54 , V_22 -> V_220 ,
V_22 -> V_16 -> V_54 ) ;
continue;
}
V_224:
F_52 () ;
F_151 () ;
F_43 ( & V_11 -> V_67 ) ;
F_77 ( V_11 ) ;
F_44 ( & V_11 -> V_67 ) ;
F_152 () ;
}
F_19 ( V_11 ) ;
}
static void F_203 ( struct V_10 * V_11 )
{
struct V_22 * V_22 , * V_269 ;
int V_95 ;
F_76 ( & V_11 -> V_67 ) ;
if ( V_11 -> V_207 && V_11 -> V_63 )
F_68 ( L_85 ,
V_11 -> V_207 -> V_16 -> V_54 ,
V_11 -> V_63 -> V_16 -> V_54 ) ;
if ( V_11 -> V_63 ) {
F_179 ( V_11 , V_11 -> V_63 ) ;
F_75 ( & V_11 -> V_67 ) ;
return;
}
F_75 ( & V_11 -> V_67 ) ;
if ( ! V_11 -> V_207 ) {
V_11 -> V_207 = F_62 ( V_11 ) ;
if ( ! V_11 -> V_207 )
return;
}
F_72 ( V_11 -> V_207 ) ;
V_269 = F_204 ( V_11 , V_11 -> V_207 ) ;
F_63 (bond, slave, i, next_slave) {
if ( F_64 ( V_22 -> V_16 ) ) {
V_22 -> V_28 = V_96 ;
F_73 ( V_22 ) ;
F_179 ( V_11 , V_22 ) ;
V_22 -> V_101 = V_101 ;
V_11 -> V_207 = V_22 ;
break;
}
if ( V_22 -> V_28 == V_29 ) {
V_22 -> V_28 = V_195 ;
if ( V_22 -> V_191 < V_225 )
V_22 -> V_191 ++ ;
F_72 ( V_22 ) ;
F_68 ( L_86 ,
V_11 -> V_16 -> V_54 , V_22 -> V_16 -> V_54 ) ;
}
}
}
void F_205 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_46 ( V_71 , struct V_10 ,
V_267 . V_71 ) ;
bool V_103 = false ;
int V_266 ;
F_76 ( & V_11 -> V_106 ) ;
V_266 = F_134 ( V_11 -> V_27 . V_152 ) ;
if ( F_20 ( & V_11 -> V_25 ) )
goto V_227;
V_103 = F_65 ( V_11 ) ;
if ( F_201 ( V_11 ) ) {
F_75 ( & V_11 -> V_106 ) ;
if ( ! F_39 () ) {
F_76 ( & V_11 -> V_106 ) ;
V_266 = 1 ;
V_103 = false ;
goto V_227;
}
F_76 ( & V_11 -> V_106 ) ;
F_202 ( V_11 ) ;
F_75 ( & V_11 -> V_106 ) ;
F_42 () ;
F_76 ( & V_11 -> V_106 ) ;
}
F_203 ( V_11 ) ;
V_227:
if ( V_11 -> V_27 . V_152 )
F_40 ( V_11 -> V_64 , & V_11 -> V_267 , V_266 ) ;
F_75 ( & V_11 -> V_106 ) ;
if ( V_103 ) {
if ( ! F_39 () )
return;
F_41 ( V_108 , V_11 -> V_16 ) ;
F_42 () ;
}
}
static int F_206 ( struct V_10 * V_11 )
{
F_207 ( V_11 ) ;
F_208 ( V_11 ) ;
F_209 ( V_11 ) ;
return V_270 ;
}
static int F_210 ( unsigned long V_271 ,
struct V_14 * V_19 )
{
struct V_10 * V_272 = F_11 ( V_19 ) ;
switch ( V_271 ) {
case V_273 :
return F_206 ( V_272 ) ;
case V_274 :
F_207 ( V_272 ) ;
break;
case V_275 :
F_208 ( V_272 ) ;
break;
case V_108 :
if ( V_272 -> V_98 )
V_272 -> V_98 -- ;
break;
default:
break;
}
return V_270 ;
}
static int F_211 ( unsigned long V_271 ,
struct V_14 * V_15 )
{
struct V_22 * V_22 = F_212 ( V_15 ) ;
struct V_10 * V_11 ;
struct V_14 * V_19 ;
T_3 V_276 ;
T_4 V_277 ;
if ( ! V_22 )
return V_270 ;
V_19 = V_22 -> V_11 -> V_16 ;
V_11 = V_22 -> V_11 ;
switch ( V_271 ) {
case V_274 :
if ( V_19 -> type != V_169 )
F_159 ( V_19 , V_15 ) ;
else
F_158 ( V_19 , V_15 ) ;
break;
case V_278 :
case V_279 :
V_276 = V_22 -> V_33 ;
V_277 = V_22 -> V_35 ;
F_25 ( V_22 ) ;
if ( V_11 -> V_27 . V_1 == V_7 ) {
if ( V_276 != V_22 -> V_33 )
F_213 ( V_22 ) ;
if ( V_277 != V_22 -> V_35 )
F_214 ( V_22 ) ;
}
break;
case V_280 :
break;
case V_281 :
break;
case V_273 :
break;
case V_282 :
F_95 ( V_11 ) ;
break;
case V_66 :
F_41 ( V_271 , V_22 -> V_11 -> V_16 ) ;
break;
default:
break;
}
return V_270 ;
}
static int F_215 ( struct V_283 * V_284 ,
unsigned long V_271 , void * V_285 )
{
struct V_14 * V_286 = F_216 ( V_285 ) ;
F_58 ( L_87 ,
V_286 ? V_286 -> V_54 : L_88 ,
V_271 ) ;
if ( ! ( V_286 -> V_120 & V_189 ) )
return V_270 ;
if ( V_286 -> V_77 & V_287 ) {
F_58 ( L_89 ) ;
return F_210 ( V_271 , V_286 ) ;
}
if ( V_286 -> V_77 & V_159 ) {
F_58 ( L_90 ) ;
return F_211 ( V_271 , V_286 ) ;
}
return V_270 ;
}
static int F_217 ( struct V_12 * V_13 , int V_288 )
{
struct V_289 * V_157 = (struct V_289 * ) V_13 -> V_157 ;
if ( F_192 ( V_13 ) >= F_218 ( struct V_289 , V_290 ) )
return ( V_157 -> V_158 [ 5 ] ^ V_157 -> V_291 [ 5 ] ) % V_288 ;
return 0 ;
}
static int F_219 ( struct V_12 * V_13 , int V_288 )
{
const struct V_289 * V_157 ;
const struct V_292 * V_293 ;
const struct V_294 * V_295 ;
T_3 V_296 ;
const T_8 * V_297 , * V_298 ;
if ( V_13 -> V_254 == F_177 ( V_261 ) &&
F_220 ( V_13 , sizeof( * V_293 ) ) ) {
V_293 = F_221 ( V_13 ) ;
V_157 = (struct V_289 * ) V_13 -> V_157 ;
return ( ( F_222 ( V_293 -> V_299 ^ V_293 -> V_300 ) & 0xffff ) ^
( V_157 -> V_158 [ 5 ] ^ V_157 -> V_291 [ 5 ] ) ) % V_288 ;
} else if ( V_13 -> V_254 == F_177 ( V_301 ) &&
F_220 ( V_13 , sizeof( * V_295 ) ) ) {
V_295 = F_223 ( V_13 ) ;
V_157 = (struct V_289 * ) V_13 -> V_157 ;
V_297 = & V_295 -> V_299 . V_302 [ 0 ] ;
V_298 = & V_295 -> V_300 . V_302 [ 0 ] ;
V_296 = ( V_297 [ 1 ] ^ V_298 [ 1 ] ) ^ ( V_297 [ 2 ] ^ V_298 [ 2 ] ) ^ ( V_297 [ 3 ] ^ V_298 [ 3 ] ) ;
V_296 ^= ( V_296 >> 24 ) ^ ( V_296 >> 16 ) ^ ( V_296 >> 8 ) ;
return ( V_296 ^ V_157 -> V_158 [ 5 ] ^ V_157 -> V_291 [ 5 ] ) % V_288 ;
}
return F_217 ( V_13 , V_288 ) ;
}
static int F_224 ( struct V_12 * V_13 , int V_288 )
{
T_3 V_303 = 0 ;
const struct V_292 * V_293 ;
const struct V_294 * V_295 ;
const T_8 * V_297 , * V_298 ;
const T_1 * V_304 = NULL ;
T_1 V_305 [ 2 ] ;
int V_306 = F_225 ( V_13 ) ;
int V_307 ;
if ( V_13 -> V_254 == F_177 ( V_261 ) &&
F_226 ( V_13 , V_306 + sizeof( * V_293 ) ) ) {
V_293 = F_221 ( V_13 ) ;
V_307 = F_227 ( V_293 -> V_254 ) ;
if ( ! F_228 ( V_293 ) && V_307 >= 0 ) {
V_304 = F_229 ( V_13 , V_306 + ( V_293 -> V_308 << 2 ) + V_307 ,
sizeof( V_305 ) , & V_305 ) ;
if ( V_304 )
V_303 = F_230 ( V_304 [ 0 ] ^ V_304 [ 1 ] ) ;
}
return ( V_303 ^
( ( F_222 ( V_293 -> V_299 ^ V_293 -> V_300 ) ) & 0xffff ) ) % V_288 ;
} else if ( V_13 -> V_254 == F_177 ( V_301 ) &&
F_226 ( V_13 , V_306 + sizeof( * V_295 ) ) ) {
V_295 = F_223 ( V_13 ) ;
V_307 = F_227 ( V_295 -> V_309 ) ;
if ( V_307 >= 0 ) {
V_304 = F_229 ( V_13 , V_306 + sizeof( * V_295 ) + V_307 ,
sizeof( V_305 ) , & V_305 ) ;
if ( V_304 )
V_303 = F_230 ( V_304 [ 0 ] ^ V_304 [ 1 ] ) ;
}
V_297 = & V_295 -> V_299 . V_302 [ 0 ] ;
V_298 = & V_295 -> V_300 . V_302 [ 0 ] ;
V_303 ^= ( V_297 [ 1 ] ^ V_298 [ 1 ] ) ^ ( V_297 [ 2 ] ^ V_298 [ 2 ] ) ^ ( V_297 [ 3 ] ^ V_298 [ 3 ] ) ;
V_303 ^= ( V_303 >> 24 ) ^ ( V_303 >> 16 ) ^
( V_303 >> 8 ) ;
return V_303 % V_288 ;
}
return F_217 ( V_13 , V_288 ) ;
}
static void F_231 ( struct V_10 * V_11 )
{
F_232 ( & V_11 -> V_65 ,
F_45 ) ;
F_232 ( & V_11 -> V_310 , V_311 ) ;
F_232 ( & V_11 -> V_226 , F_168 ) ;
if ( V_11 -> V_27 . V_1 == V_4 )
F_232 ( & V_11 -> V_267 , F_205 ) ;
else
F_232 ( & V_11 -> V_267 , F_199 ) ;
F_232 ( & V_11 -> V_312 , V_313 ) ;
}
static void F_233 ( struct V_10 * V_11 )
{
F_234 ( & V_11 -> V_226 ) ;
F_234 ( & V_11 -> V_267 ) ;
F_234 ( & V_11 -> V_310 ) ;
F_234 ( & V_11 -> V_312 ) ;
F_234 ( & V_11 -> V_65 ) ;
}
static int F_235 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 ;
F_76 ( & V_11 -> V_106 ) ;
if ( ! F_20 ( & V_11 -> V_25 ) ) {
F_76 ( & V_11 -> V_67 ) ;
F_12 (bond, slave) {
if ( ( V_11 -> V_27 . V_1 == V_4 )
&& ( V_22 != V_11 -> V_63 ) ) {
F_72 ( V_22 ) ;
} else {
F_73 ( V_22 ) ;
}
}
F_75 ( & V_11 -> V_67 ) ;
}
F_75 ( & V_11 -> V_106 ) ;
F_231 ( V_11 ) ;
if ( F_17 ( V_11 ) ) {
if ( F_236 ( V_11 , ( V_11 -> V_27 . V_1 == V_9 ) ) )
return - V_118 ;
F_40 ( V_11 -> V_64 , & V_11 -> V_310 , 0 ) ;
}
if ( V_11 -> V_27 . V_102 )
F_40 ( V_11 -> V_64 , & V_11 -> V_226 , 0 ) ;
if ( V_11 -> V_27 . V_152 ) {
F_40 ( V_11 -> V_64 , & V_11 -> V_267 , 0 ) ;
if ( V_11 -> V_27 . V_263 )
V_11 -> F_103 = F_188 ;
}
if ( V_11 -> V_27 . V_1 == V_7 ) {
F_40 ( V_11 -> V_64 , & V_11 -> V_312 , 0 ) ;
V_11 -> F_103 = V_314 ;
F_237 ( V_11 , 1 ) ;
}
return 0 ;
}
static int F_238 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_233 ( V_11 ) ;
V_11 -> V_98 = 0 ;
if ( F_17 ( V_11 ) )
F_239 ( V_11 ) ;
V_11 -> F_103 = NULL ;
return 0 ;
}
static struct V_315 * F_240 ( struct V_14 * V_19 ,
struct V_315 * V_316 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_315 V_317 ;
struct V_22 * V_22 ;
memset ( V_316 , 0 , sizeof( * V_316 ) ) ;
F_241 ( & V_11 -> V_106 ) ;
F_12 (bond, slave) {
const struct V_315 * V_318 =
F_242 ( V_22 -> V_16 , & V_317 ) ;
V_316 -> V_319 += V_318 -> V_319 ;
V_316 -> V_320 += V_318 -> V_320 ;
V_316 -> V_321 += V_318 -> V_321 ;
V_316 -> V_322 += V_318 -> V_322 ;
V_316 -> V_323 += V_318 -> V_323 ;
V_316 -> V_324 += V_318 -> V_324 ;
V_316 -> V_325 += V_318 -> V_325 ;
V_316 -> V_326 += V_318 -> V_326 ;
V_316 -> V_327 += V_318 -> V_327 ;
V_316 -> V_328 += V_318 -> V_328 ;
V_316 -> V_329 += V_318 -> V_329 ;
V_316 -> V_330 += V_318 -> V_330 ;
V_316 -> V_331 += V_318 -> V_331 ;
V_316 -> V_332 += V_318 -> V_332 ;
V_316 -> V_333 += V_318 -> V_333 ;
V_316 -> V_334 += V_318 -> V_334 ;
V_316 -> V_335 += V_318 -> V_335 ;
V_316 -> V_336 += V_318 -> V_336 ;
V_316 -> V_337 += V_318 -> V_337 ;
V_316 -> V_338 += V_318 -> V_338 ;
V_316 -> V_339 += V_318 -> V_339 ;
}
F_243 ( & V_11 -> V_106 ) ;
return V_316 ;
}
static int F_244 ( struct V_14 * V_19 , struct V_44 * V_45 , int V_340 )
{
struct V_14 * V_15 = NULL ;
struct V_209 V_341 ;
struct V_209 T_9 * V_342 = NULL ;
struct V_213 V_343 ;
struct V_213 T_9 * V_344 = NULL ;
struct V_46 * V_47 = NULL ;
struct V_345 * V_345 ;
int V_23 = 0 ;
F_58 ( L_91 , V_19 -> V_54 , V_340 ) ;
switch ( V_340 ) {
case V_56 :
V_47 = F_31 ( V_45 ) ;
if ( ! V_47 )
return - V_172 ;
V_47 -> V_346 = 0 ;
case V_59 :
V_47 = F_31 ( V_45 ) ;
if ( ! V_47 )
return - V_172 ;
if ( V_47 -> V_57 == 1 ) {
struct V_10 * V_11 = F_11 ( V_19 ) ;
V_47 -> V_60 = 0 ;
F_76 ( & V_11 -> V_106 ) ;
F_76 ( & V_11 -> V_67 ) ;
if ( F_22 ( V_11 -> V_16 ) )
V_47 -> V_60 = V_49 ;
F_75 ( & V_11 -> V_67 ) ;
F_75 ( & V_11 -> V_106 ) ;
}
return 0 ;
case V_347 :
case V_348 :
V_342 = (struct V_209 T_9 * ) V_45 -> V_349 ;
if ( F_245 ( & V_341 , V_342 , sizeof( V_209 ) ) )
return - V_350 ;
V_23 = F_162 ( V_19 , & V_341 ) ;
if ( V_23 == 0 &&
F_246 ( V_342 , & V_341 , sizeof( V_209 ) ) )
return - V_350 ;
return V_23 ;
case V_351 :
case V_352 :
V_344 = (struct V_213 T_9 * ) V_45 -> V_349 ;
if ( F_245 ( & V_343 , V_344 , sizeof( V_213 ) ) )
return - V_350 ;
V_23 = F_163 ( V_19 , & V_343 ) ;
if ( V_23 == 0 &&
F_246 ( V_344 , & V_343 , sizeof( V_213 ) ) )
return - V_350 ;
return V_23 ;
default:
break;
}
V_345 = F_181 ( V_19 ) ;
if ( ! F_247 ( V_345 -> V_353 , V_354 ) )
return - V_165 ;
V_15 = F_248 ( V_345 , V_45 -> V_355 ) ;
F_58 ( L_92 , V_15 ) ;
if ( ! V_15 )
V_23 = - V_214 ;
else {
F_58 ( L_93 , V_15 -> V_54 ) ;
switch ( V_340 ) {
case V_356 :
case V_357 :
V_23 = F_117 ( V_19 , V_15 ) ;
break;
case V_358 :
case V_359 :
V_23 = F_158 ( V_19 , V_15 ) ;
break;
case V_360 :
case V_361 :
F_57 ( V_19 , V_15 ) ;
V_23 = 0 ;
break;
case V_362 :
case V_363 :
V_23 = F_161 ( V_19 , V_15 ) ;
break;
default:
V_23 = - V_175 ;
}
F_249 ( V_15 ) ;
}
return V_23 ;
}
static void F_250 ( struct V_14 * V_19 , int V_364 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_364 & V_78 )
F_33 ( V_11 ,
V_19 -> V_77 & V_78 ? 1 : - 1 ) ;
if ( V_364 & V_79 )
F_36 ( V_11 ,
V_19 -> V_77 & V_79 ? 1 : - 1 ) ;
}
static void F_251 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 ;
F_52 () ;
if ( F_34 ( V_11 -> V_27 . V_1 ) ) {
V_22 = F_252 ( V_11 -> V_63 ) ;
if ( V_22 ) {
F_54 ( V_22 -> V_16 , V_19 ) ;
F_55 ( V_22 -> V_16 , V_19 ) ;
}
} else {
F_12 (bond, slave) {
F_131 ( V_22 -> V_16 , V_19 ) ;
F_130 ( V_22 -> V_16 , V_19 ) ;
}
}
}
static int F_253 ( struct V_365 * V_366 )
{
struct V_10 * V_11 = F_11 ( V_366 -> V_16 ) ;
const struct V_41 * V_42 ;
struct V_367 V_368 ;
struct V_22 * V_22 ;
int V_149 ;
V_22 = F_62 ( V_11 ) ;
if ( ! V_22 )
return 0 ;
V_42 = V_22 -> V_16 -> V_43 ;
if ( ! V_42 -> V_369 )
return 0 ;
V_368 . V_370 = NULL ;
V_368 . V_371 = NULL ;
V_149 = V_42 -> V_369 ( V_22 -> V_16 , & V_368 ) ;
if ( V_149 )
return V_149 ;
V_366 -> V_368 -> V_371 = V_368 . V_371 ;
if ( ! V_368 . V_370 )
return 0 ;
return V_368 . V_370 ( V_366 ) ;
}
static int F_254 ( struct V_14 * V_16 ,
struct V_367 * V_368 )
{
if ( V_368 -> V_16 == V_16 )
V_368 -> V_370 = F_253 ;
return 0 ;
}
static int F_255 ( struct V_14 * V_19 , int V_372 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 ;
int V_23 = 0 ;
F_58 ( L_94 , V_11 ,
( V_19 ? V_19 -> V_54 : L_88 ) , V_372 ) ;
F_12 (bond, slave) {
F_58 ( L_95 ,
V_22 ,
F_137 ( V_11 , V_22 ) ,
V_22 -> V_16 -> V_43 -> V_373 ) ;
V_23 = F_126 ( V_22 -> V_16 , V_372 ) ;
if ( V_23 ) {
F_58 ( L_96 , V_23 , V_22 -> V_16 -> V_54 ) ;
goto V_24;
}
}
V_19 -> V_181 = V_372 ;
return 0 ;
V_24:
F_14 (bond, slave) {
int V_374 ;
V_374 = F_126 ( V_22 -> V_16 , V_19 -> V_181 ) ;
if ( V_374 ) {
F_58 ( L_97 ,
V_374 , V_22 -> V_16 -> V_54 ) ;
}
}
return V_23 ;
}
static int F_256 ( struct V_14 * V_19 , void * V_162 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_161 * V_375 = V_162 , V_376 ;
struct V_22 * V_22 ;
int V_23 = 0 ;
if ( V_11 -> V_27 . V_1 == V_9 )
return F_257 ( V_19 , V_162 ) ;
F_58 ( L_98 ,
V_11 , V_19 ? V_19 -> V_54 : L_88 ) ;
if ( V_11 -> V_27 . V_104 )
return 0 ;
if ( ! F_258 ( V_375 -> V_184 ) )
return - V_377 ;
F_12 (bond, slave) {
const struct V_41 * V_42 = V_22 -> V_16 -> V_43 ;
F_58 ( L_99 , V_22 , V_22 -> V_16 -> V_54 ) ;
if ( V_42 -> V_173 == NULL ) {
V_23 = - V_175 ;
F_58 ( L_100 , V_22 -> V_16 -> V_54 ) ;
goto V_24;
}
V_23 = F_127 ( V_22 -> V_16 , V_162 ) ;
if ( V_23 ) {
F_58 ( L_96 , V_23 , V_22 -> V_16 -> V_54 ) ;
goto V_24;
}
}
memcpy ( V_19 -> V_81 , V_375 -> V_184 , V_19 -> V_80 ) ;
return 0 ;
V_24:
memcpy ( V_376 . V_184 , V_19 -> V_81 , V_19 -> V_80 ) ;
V_376 . V_185 = V_19 -> type ;
F_14 (bond, slave) {
int V_374 ;
V_374 = F_127 ( V_22 -> V_16 , & V_376 ) ;
if ( V_374 ) {
F_58 ( L_97 ,
V_374 , V_22 -> V_16 -> V_54 ) ;
}
}
return V_23 ;
}
void F_259 ( struct V_10 * V_11 , struct V_12 * V_13 , int V_215 )
{
struct V_22 * V_22 ;
int V_95 = V_215 ;
F_260 (bond, slave) {
if ( -- V_95 < 0 ) {
if ( F_261 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
}
V_95 = V_215 ;
F_260 (bond, slave) {
if ( -- V_95 < 0 )
break;
if ( F_261 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
F_110 ( V_13 ) ;
}
static int F_262 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_292 * V_293 = F_221 ( V_13 ) ;
struct V_22 * V_22 ;
if ( V_293 -> V_254 == V_378 && V_13 -> V_254 == F_177 ( V_261 ) ) {
V_22 = F_263 ( V_11 -> V_63 ) ;
if ( V_22 && F_261 ( V_22 ) )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_259 ( V_11 , V_13 , 0 ) ;
} else {
F_259 ( V_11 , V_13 ,
V_11 -> V_379 ++ % V_11 -> V_114 ) ;
}
return V_380 ;
}
static int F_264 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 ;
V_22 = F_263 ( V_11 -> V_63 ) ;
if ( V_22 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_110 ( V_13 ) ;
return V_380 ;
}
static int F_265 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_259 ( V_11 , V_13 ,
V_11 -> V_381 ( V_13 , V_11 -> V_114 ) ) ;
return V_380 ;
}
static int F_266 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 = NULL ;
F_260 (bond, slave) {
if ( F_267 ( V_11 , V_22 ) )
break;
if ( F_64 ( V_22 -> V_16 ) && V_22 -> V_28 == V_29 ) {
struct V_12 * V_382 = F_268 ( V_13 , V_117 ) ;
if ( ! V_382 ) {
F_120 ( L_101 ,
V_19 -> V_54 ) ;
continue;
}
F_2 ( V_11 , V_382 , V_22 -> V_16 ) ;
}
}
if ( V_22 && F_64 ( V_22 -> V_16 ) && V_22 -> V_28 == V_29 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_110 ( V_13 ) ;
return V_380 ;
}
static void F_269 ( struct V_10 * V_11 )
{
switch ( V_11 -> V_27 . V_383 ) {
case V_384 :
V_11 -> V_381 = F_219 ;
break;
case V_385 :
V_11 -> V_381 = F_224 ;
break;
case V_386 :
default:
V_11 -> V_381 = F_217 ;
break;
}
}
static inline int F_270 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_22 * V_22 = NULL ;
struct V_22 * V_387 ;
int V_23 = 1 ;
if ( ! V_13 -> V_17 )
return 1 ;
F_260 (bond, check_slave) {
if ( V_387 -> V_179 == V_13 -> V_17 ) {
V_22 = V_387 ;
break;
}
}
if ( V_22 && V_22 -> V_179 && F_64 ( V_22 -> V_16 ) &&
( V_22 -> V_28 == V_29 ) ) {
V_23 = F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
}
return V_23 ;
}
static T_2 F_271 ( struct V_14 * V_16 , struct V_12 * V_13 )
{
T_2 V_388 = F_272 ( V_13 ) ? F_273 ( V_13 ) : 0 ;
F_4 ( V_13 ) -> V_18 = V_13 -> V_17 ;
if ( F_5 ( V_388 >= V_16 -> V_389 ) ) {
do {
V_388 -= V_16 -> V_389 ;
} while ( V_388 >= V_16 -> V_389 );
}
return V_388 ;
}
static T_10 F_274 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
if ( F_275 ( V_11 -> V_27 . V_1 ) ) {
if ( ! F_270 ( V_11 , V_13 ) )
return V_380 ;
}
switch ( V_11 -> V_27 . V_1 ) {
case V_3 :
return F_262 ( V_13 , V_16 ) ;
case V_4 :
return F_264 ( V_13 , V_16 ) ;
case V_5 :
return F_265 ( V_13 , V_16 ) ;
case V_6 :
return F_266 ( V_13 , V_16 ) ;
case V_7 :
return F_276 ( V_13 , V_16 ) ;
case V_9 :
case V_8 :
return F_277 ( V_13 , V_16 ) ;
default:
F_120 ( L_102 ,
V_16 -> V_54 , V_11 -> V_27 . V_1 ) ;
F_278 ( 1 ) ;
F_110 ( V_13 ) ;
return V_380 ;
}
}
static T_10 F_279 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
T_10 V_149 = V_380 ;
if ( F_280 ( V_16 ) )
return V_390 ;
F_171 () ;
if ( ! F_20 ( & V_11 -> V_25 ) )
V_149 = F_274 ( V_13 , V_16 ) ;
else
F_110 ( V_13 ) ;
F_173 () ;
return V_149 ;
}
void F_281 ( struct V_10 * V_11 , int V_1 )
{
struct V_14 * V_19 = V_11 -> V_16 ;
switch ( V_1 ) {
case V_3 :
break;
case V_4 :
break;
case V_5 :
F_269 ( V_11 ) ;
break;
case V_6 :
break;
case V_7 :
F_269 ( V_11 ) ;
break;
case V_9 :
case V_8 :
break;
default:
F_120 ( L_102 ,
V_19 -> V_54 , V_1 ) ;
break;
}
}
static int F_282 ( struct V_14 * V_19 ,
struct V_30 * V_31 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
unsigned long V_33 = 0 ;
struct V_22 * V_22 ;
V_31 -> V_35 = V_36 ;
V_31 -> V_391 = V_392 ;
F_76 ( & V_11 -> V_106 ) ;
F_12 (bond, slave) {
if ( F_283 ( V_22 ) ) {
if ( V_22 -> V_33 != V_34 )
V_33 += V_22 -> V_33 ;
if ( V_31 -> V_35 == V_36 &&
V_22 -> V_35 != V_36 )
V_31 -> V_35 = V_22 -> V_35 ;
}
}
F_284 ( V_31 , V_33 ? : V_34 ) ;
F_75 ( & V_11 -> V_106 ) ;
return 0 ;
}
static void F_285 ( struct V_14 * V_19 ,
struct V_393 * V_394 )
{
F_286 ( V_394 -> V_395 , V_396 , sizeof( V_394 -> V_395 ) ) ;
F_286 ( V_394 -> V_397 , V_398 , sizeof( V_394 -> V_397 ) ) ;
snprintf ( V_394 -> V_399 , sizeof( V_394 -> V_399 ) , L_103 ,
V_400 ) ;
}
static void F_287 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_11 -> V_64 )
F_288 ( V_11 -> V_64 ) ;
F_289 ( V_19 ) ;
}
static void F_290 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_291 ( & V_11 -> V_106 ) ;
F_291 ( & V_11 -> V_67 ) ;
F_125 ( & V_11 -> V_25 ) ;
V_11 -> V_27 = V_401 ;
V_11 -> V_16 = V_19 ;
F_124 ( V_19 ) ;
V_19 -> V_43 = & V_402 ;
V_19 -> V_50 = & V_403 ;
F_281 ( V_11 , V_11 -> V_27 . V_1 ) ;
V_19 -> V_404 = F_287 ;
F_292 ( V_19 , & V_405 ) ;
V_19 -> V_406 = 0 ;
V_19 -> V_77 |= V_287 | V_407 ;
V_19 -> V_120 |= V_189 ;
V_19 -> V_120 &= ~ ( V_132 | V_170 ) ;
V_19 -> V_126 |= V_128 ;
V_19 -> V_126 |= V_408 ;
V_19 -> V_409 = V_134 |
V_410 |
V_411 |
V_412 ;
V_19 -> V_409 &= ~ ( V_413 & ~ V_414 ) ;
V_19 -> V_126 |= V_19 -> V_409 ;
}
static void F_293 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_415 ;
F_90 ( V_19 ) ;
F_294 (slave, tmp_slave, &bond->slave_list, list)
F_149 ( V_19 , V_22 -> V_16 , true ) ;
F_68 ( L_104 , V_19 -> V_54 ) ;
F_295 ( & V_11 -> V_416 ) ;
F_296 ( V_11 ) ;
}
int F_297 ( const char * V_417 , const struct V_418 * V_419 )
{
int V_420 = - 1 , V_95 , V_111 ;
char * V_421 , V_422 [ V_423 + 1 ] = { 0 , } ;
for ( V_421 = ( char * ) V_417 ; * V_421 ; V_421 ++ )
if ( ! ( isdigit ( * V_421 ) || isspace ( * V_421 ) ) )
break;
if ( * V_421 )
V_111 = sscanf ( V_417 , L_105 , V_422 ) ;
else
V_111 = sscanf ( V_417 , L_103 , & V_420 ) ;
if ( ! V_111 )
return - 1 ;
for ( V_95 = 0 ; V_419 [ V_95 ] . V_424 ; V_95 ++ ) {
if ( V_420 == V_419 [ V_95 ] . V_1 )
return V_419 [ V_95 ] . V_1 ;
if ( strcmp ( V_422 , V_419 [ V_95 ] . V_424 ) == 0 )
return V_419 [ V_95 ] . V_1 ;
}
return - 1 ;
}
static int F_298 ( struct V_425 * V_27 )
{
int V_426 , V_427 , V_428 , V_95 ;
int V_429 ;
if ( V_1 ) {
V_211 = F_297 ( V_1 , V_430 ) ;
if ( V_211 == - 1 ) {
F_120 ( L_106 ,
V_1 == NULL ? L_11 : V_1 ) ;
return - V_172 ;
}
}
if ( V_381 ) {
if ( ( V_211 != V_5 ) &&
( V_211 != V_7 ) ) {
F_68 ( L_107 ,
F_1 ( V_211 ) ) ;
} else {
V_431 = F_297 ( V_381 ,
V_432 ) ;
if ( V_431 == - 1 ) {
F_120 ( L_108 ,
V_381 == NULL ? L_11 :
V_381 ) ;
return - V_172 ;
}
}
}
if ( V_433 ) {
if ( V_211 != V_7 ) {
F_68 ( L_109 ,
F_1 ( V_211 ) ) ;
} else {
V_434 = F_297 ( V_433 , V_435 ) ;
if ( V_434 == - 1 ) {
F_120 ( L_110 ,
V_433 == NULL ? L_11 : V_433 ) ;
return - V_172 ;
}
}
}
if ( V_436 ) {
V_27 -> V_436 = F_297 ( V_436 , V_437 ) ;
if ( V_27 -> V_436 == - 1 ) {
F_120 ( L_111 ,
V_436 == NULL ? L_11 : V_436 ) ;
return - V_172 ;
}
if ( V_211 != V_7 ) {
F_118 ( L_112 ) ;
}
} else {
V_27 -> V_436 = V_438 ;
}
if ( V_439 < 0 ) {
F_118 ( L_113 ,
V_439 , 0 , V_440 , V_441 ) ;
V_439 = V_441 ;
}
if ( V_102 < 0 ) {
F_118 ( L_114 ,
V_102 , V_440 , V_442 ) ;
V_102 = V_442 ;
}
if ( V_94 < 0 ) {
F_118 ( L_115 ,
V_94 , V_440 ) ;
V_94 = 0 ;
}
if ( V_223 < 0 ) {
F_118 ( L_116 ,
V_223 , V_440 ) ;
V_223 = 0 ;
}
if ( ( V_48 != 0 ) && ( V_48 != 1 ) ) {
F_118 ( L_117 ,
V_48 ) ;
V_48 = 1 ;
}
if ( V_105 < 0 || V_105 > 255 ) {
F_118 ( L_118 ,
V_105 ) ;
V_105 = 1 ;
}
if ( V_211 == V_7 ) {
if ( ! V_102 ) {
F_118 ( L_119 ) ;
F_118 ( L_120 ) ;
V_102 = 100 ;
}
}
if ( V_443 < 1 || V_443 > 255 ) {
F_118 ( L_121
L_122 ,
V_443 , V_444 ) ;
V_443 = V_444 ;
}
if ( ( V_445 != 0 ) && ( V_445 != 1 ) ) {
F_118 ( L_123
L_124
L_125 , V_445 ) ;
V_445 = 0 ;
}
if ( V_109 < 0 || V_109 > 255 ) {
F_118 ( L_126
L_127 ,
V_109 , V_446 ) ;
V_109 = V_446 ;
}
if ( ( V_211 == V_8 ) ||
( V_211 == V_9 ) ) {
if ( ! V_102 ) {
F_118 ( L_128 ) ;
F_118 ( L_120 ) ;
V_102 = 100 ;
}
}
if ( V_211 == V_9 ) {
F_299 ( L_129 ,
V_94 ) ;
}
if ( ! V_102 ) {
if ( V_94 || V_223 ) {
F_118 ( L_130 ,
V_94 , V_223 ) ;
}
} else {
if ( V_152 ) {
F_118 ( L_131 ,
V_102 , V_152 ) ;
V_152 = 0 ;
}
if ( ( V_94 % V_102 ) != 0 ) {
F_118 ( L_132 ,
V_94 , V_102 ,
( V_94 / V_102 ) * V_102 ) ;
}
V_94 /= V_102 ;
if ( ( V_223 % V_102 ) != 0 ) {
F_118 ( L_133 ,
V_223 , V_102 ,
( V_223 / V_102 ) * V_102 ) ;
}
V_223 /= V_102 ;
}
if ( V_152 < 0 ) {
F_118 ( L_134 ,
V_152 , V_440 , V_447 ) ;
V_152 = V_447 ;
}
for ( V_448 = 0 , V_95 = 0 ;
( V_448 < V_193 ) && V_449 [ V_95 ] ; V_95 ++ ) {
T_8 V_228 = F_300 ( V_449 [ V_95 ] ) ;
if ( ! isdigit ( V_449 [ V_95 ] [ 0 ] ) || V_228 == 0 ||
V_228 == F_301 ( V_450 ) ) {
F_118 ( L_135 ,
V_449 [ V_95 ] ) ;
V_152 = 0 ;
} else {
if ( F_187 ( V_451 , V_228 ) == - 1 )
V_451 [ V_448 ++ ] = V_228 ;
else
F_118 ( L_136 ,
& V_228 ) ;
}
}
if ( V_152 && ! V_448 ) {
F_118 ( L_137 ,
V_152 ) ;
V_152 = 0 ;
}
if ( V_263 ) {
if ( V_211 != V_4 ) {
F_120 ( L_138 ) ;
return - V_172 ;
}
if ( ! V_152 ) {
F_120 ( L_139 ) ;
return - V_172 ;
}
V_426 = F_297 ( V_263 ,
V_452 ) ;
if ( V_426 == - 1 ) {
F_120 ( L_140 ,
V_263 == NULL ? L_11 : V_263 ) ;
return - V_172 ;
}
} else
V_426 = 0 ;
V_429 = 0 ;
if ( V_453 ) {
V_429 = F_297 ( V_453 ,
V_454 ) ;
if ( V_429 == - 1 ) {
F_120 ( L_141 ,
V_453 ) ;
V_429 = 0 ;
}
}
if ( V_102 ) {
F_68 ( L_142 , V_102 ) ;
} else if ( V_152 ) {
F_68 ( L_143 ,
V_152 ,
V_452 [ V_426 ] . V_424 ,
V_448 ) ;
for ( V_95 = 0 ; V_95 < V_448 ; V_95 ++ )
F_68 ( L_144 , V_449 [ V_95 ] ) ;
F_68 ( L_145 ) ;
} else if ( V_439 ) {
F_58 ( L_146 ) ;
}
if ( V_196 && ! F_34 ( V_211 ) ) {
F_118 ( L_147 ,
V_196 , F_1 ( V_211 ) ) ;
V_196 = NULL ;
}
if ( V_196 && V_89 ) {
V_428 = F_297 ( V_89 ,
V_455 ) ;
if ( V_428 == - 1 ) {
F_120 ( L_148 ,
V_89 ==
NULL ? L_11 : V_89 ) ;
return - V_172 ;
}
} else {
V_428 = V_456 ;
}
if ( V_104 ) {
V_427 = F_297 ( V_104 ,
V_457 ) ;
if ( V_427 == - 1 ) {
F_120 ( L_149 ,
V_263 == NULL ? L_11 : V_263 ) ;
return - V_172 ;
}
if ( V_211 != V_4 )
F_118 ( L_150 ) ;
} else {
V_427 = V_458 ;
}
V_27 -> V_1 = V_211 ;
V_27 -> V_383 = V_431 ;
V_27 -> V_102 = V_102 ;
V_27 -> V_105 = V_105 ;
V_27 -> V_152 = V_152 ;
V_27 -> V_263 = V_426 ;
V_27 -> V_453 = V_429 ;
V_27 -> V_94 = V_94 ;
V_27 -> V_223 = V_223 ;
V_27 -> V_48 = V_48 ;
V_27 -> V_434 = V_434 ;
V_27 -> V_196 [ 0 ] = 0 ;
V_27 -> V_89 = V_428 ;
V_27 -> V_104 = V_427 ;
V_27 -> V_443 = V_443 ;
V_27 -> V_445 = V_445 ;
V_27 -> V_109 = V_109 ;
V_27 -> V_459 = V_459 ;
V_27 -> V_460 = V_461 ;
if ( V_196 ) {
strncpy ( V_27 -> V_196 , V_196 , V_55 ) ;
V_27 -> V_196 [ V_55 - 1 ] = 0 ;
}
memcpy ( V_27 -> V_243 , V_451 , sizeof( V_451 ) ) ;
return 0 ;
}
static void F_302 ( struct V_14 * V_16 ,
struct V_462 * V_388 ,
void * V_463 )
{
F_303 ( & V_388 -> V_464 ,
& V_465 ) ;
}
static void F_304 ( struct V_14 * V_16 )
{
F_303 ( & V_16 -> V_466 ,
& V_467 ) ;
F_305 ( V_16 , F_302 , NULL ) ;
V_16 -> V_468 = & V_469 ;
}
static int F_306 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_470 * V_471 = F_307 ( F_181 ( V_19 ) , V_472 ) ;
struct V_473 * V_474 = & ( F_308 ( V_11 ) ) ;
F_58 ( L_151 , V_19 -> V_54 ) ;
F_309 ( & ( V_474 -> V_475 ) ) ;
F_309 ( & ( V_474 -> V_476 ) ) ;
V_11 -> V_64 = F_310 ( V_19 -> V_54 ) ;
if ( ! V_11 -> V_64 )
return - V_118 ;
F_304 ( V_19 ) ;
F_311 ( & V_11 -> V_416 , & V_471 -> V_477 ) ;
F_312 ( V_11 ) ;
F_313 ( V_11 ) ;
if ( F_314 ( V_19 -> V_81 ) &&
V_19 -> V_82 == V_478 )
F_148 ( V_19 ) ;
return 0 ;
}
static int F_315 ( struct V_479 * V_480 [] , struct V_479 * V_157 [] )
{
if ( V_480 [ V_481 ] ) {
if ( F_316 ( V_480 [ V_481 ] ) != V_73 )
return - V_172 ;
if ( ! F_258 ( F_317 ( V_480 [ V_481 ] ) ) )
return - V_377 ;
}
return 0 ;
}
static unsigned int F_318 ( void )
{
return V_443 ;
}
int F_319 ( struct V_345 * V_345 , const char * V_54 )
{
struct V_14 * V_19 ;
int V_23 ;
F_320 () ;
V_19 = F_321 ( sizeof( struct V_10 ) ,
V_54 ? V_54 : L_152 ,
F_290 , V_443 ) ;
if ( ! V_19 ) {
F_120 ( L_153 , V_54 ) ;
F_42 () ;
return - V_118 ;
}
F_322 ( V_19 , V_345 ) ;
V_19 -> V_482 = & V_483 ;
V_23 = F_323 ( V_19 ) ;
F_24 ( V_19 ) ;
F_42 () ;
if ( V_23 < 0 )
F_287 ( V_19 ) ;
return V_23 ;
}
static int T_11 F_324 ( struct V_345 * V_345 )
{
struct V_470 * V_471 = F_307 ( V_345 , V_472 ) ;
V_471 -> V_345 = V_345 ;
F_125 ( & V_471 -> V_477 ) ;
F_325 ( V_471 ) ;
F_326 ( V_471 ) ;
return 0 ;
}
static void T_12 F_327 ( struct V_345 * V_345 )
{
struct V_470 * V_471 = F_307 ( V_345 , V_472 ) ;
struct V_10 * V_11 , * V_484 ;
F_328 ( V_113 ) ;
F_329 ( V_471 ) ;
F_330 ( V_471 ) ;
F_320 () ;
F_294 (bond, tmp_bond, &bn->dev_list, bond_list)
F_331 ( V_11 -> V_16 , & V_113 ) ;
F_332 ( & V_113 ) ;
F_42 () ;
}
static int T_13 F_333 ( void )
{
int V_95 ;
int V_23 ;
F_68 ( L_154 , V_485 ) ;
V_23 = F_298 ( & V_401 ) ;
if ( V_23 )
goto V_119;
V_23 = F_334 ( & V_486 ) ;
if ( V_23 )
goto V_119;
V_23 = F_335 ( & V_483 ) ;
if ( V_23 )
goto V_487;
F_336 () ;
for ( V_95 = 0 ; V_95 < V_439 ; V_95 ++ ) {
V_23 = F_319 ( & V_488 , NULL ) ;
if ( V_23 )
goto V_62;
}
F_337 ( & V_489 ) ;
V_119:
return V_23 ;
V_62:
F_338 ( & V_483 ) ;
V_487:
F_339 ( & V_486 ) ;
goto V_119;
}
static void T_14 F_340 ( void )
{
F_341 ( & V_489 ) ;
F_342 () ;
F_338 ( & V_483 ) ;
F_339 ( & V_486 ) ;
#ifdef F_140
F_343 ( F_344 ( & V_490 ) ) ;
#endif
}
