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
struct V_22 * V_22 , * V_23 ;
struct V_24 * V_25 ;
int V_26 ;
F_12 (bond, slave, iter) {
V_26 = F_13 ( V_22 -> V_16 , V_20 , V_21 ) ;
if ( V_26 )
goto V_27;
}
return 0 ;
V_27:
F_12 (bond, rollback_slave, iter) {
if ( V_23 == V_22 )
break;
F_14 ( V_23 -> V_16 , V_20 , V_21 ) ;
}
return V_26 ;
}
static int F_15 ( struct V_14 * V_19 ,
T_1 V_20 , T_2 V_21 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter)
F_14 ( V_22 -> V_16 , V_20 , V_21 ) ;
if ( F_16 ( V_11 ) )
F_17 ( V_11 , V_21 ) ;
return 0 ;
}
static int F_18 ( struct V_10 * V_11 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 ;
if ( ! F_19 ( V_11 ) )
goto V_28;
if ( V_11 -> V_29 . V_1 == V_7 )
return F_20 ( V_11 ) ;
F_12 (bond, slave, iter) {
if ( V_22 -> V_30 == V_31 ) {
if ( ! F_21 ( V_11 -> V_16 ) ) {
F_22 ( V_11 -> V_16 ) ;
return 1 ;
}
return 0 ;
}
}
V_28:
if ( F_21 ( V_11 -> V_16 ) ) {
F_23 ( V_11 -> V_16 ) ;
return 1 ;
}
return 0 ;
}
static void F_24 ( struct V_22 * V_22 )
{
struct V_14 * V_15 = V_22 -> V_16 ;
struct V_32 V_33 ;
T_3 V_34 ;
int V_26 ;
V_22 -> V_35 = V_36 ;
V_22 -> V_37 = V_38 ;
V_26 = F_25 ( V_15 , & V_33 ) ;
if ( V_26 < 0 )
return;
V_34 = F_26 ( & V_33 ) ;
if ( V_34 == 0 || V_34 == ( ( V_39 ) - 1 ) )
return;
switch ( V_33 . V_37 ) {
case V_40 :
case V_41 :
break;
default:
return;
}
V_22 -> V_35 = V_34 ;
V_22 -> V_37 = V_33 . V_37 ;
return;
}
static int F_27 ( struct V_10 * V_11 ,
struct V_14 * V_15 , int V_42 )
{
const struct V_43 * V_44 = V_15 -> V_45 ;
int (* F_28)( struct V_14 * , struct V_46 * , int );
struct V_46 V_47 ;
struct V_48 * V_49 ;
if ( ! V_42 && ! F_29 ( V_15 ) )
return 0 ;
if ( V_11 -> V_29 . V_50 )
return F_21 ( V_15 ) ? V_51 : 0 ;
if ( V_15 -> V_52 -> V_53 )
return V_15 -> V_52 -> V_53 ( V_15 ) ?
V_51 : 0 ;
F_28 = V_44 -> V_54 ;
if ( F_28 ) {
strncpy ( V_47 . V_55 , V_15 -> V_56 , V_57 ) ;
V_49 = F_30 ( & V_47 ) ;
if ( F_31 ( V_15 , & V_47 , V_58 ) == 0 ) {
V_49 -> V_59 = V_60 ;
if ( F_31 ( V_15 , & V_47 , V_61 ) == 0 )
return V_49 -> V_62 & V_51 ;
}
}
return V_42 ? - 1 : V_51 ;
}
static int F_32 ( struct V_10 * V_11 , int V_63 )
{
struct V_24 * V_25 ;
int V_64 = 0 ;
if ( F_33 ( V_11 -> V_29 . V_1 ) ) {
if ( V_11 -> V_65 ) {
V_64 = F_34 ( V_11 -> V_65 -> V_16 ,
V_63 ) ;
}
} else {
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
V_64 = F_34 ( V_22 -> V_16 , V_63 ) ;
if ( V_64 )
return V_64 ;
}
}
return V_64 ;
}
static int F_35 ( struct V_10 * V_11 , int V_63 )
{
struct V_24 * V_25 ;
int V_64 = 0 ;
if ( F_33 ( V_11 -> V_29 . V_1 ) ) {
if ( V_11 -> V_65 ) {
V_64 = F_36 ( V_11 -> V_65 -> V_16 ,
V_63 ) ;
}
} else {
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
V_64 = F_36 ( V_22 -> V_16 , V_63 ) ;
if ( V_64 )
return V_64 ;
}
}
return V_64 ;
}
static void F_37 ( struct V_10 * V_11 )
{
if ( ! F_38 () ) {
F_39 ( V_11 -> V_66 , & V_11 -> V_67 , 1 ) ;
return;
}
F_40 ( V_68 , V_11 -> V_16 ) ;
F_41 () ;
F_42 ( & V_11 -> V_69 ) ;
if ( V_11 -> V_70 > 1 ) {
V_11 -> V_70 -- ;
F_39 ( V_11 -> V_66 , & V_11 -> V_67 , V_71 / 5 ) ;
}
F_43 ( & V_11 -> V_69 ) ;
}
static void F_44 ( struct V_72 * V_73 )
{
struct V_10 * V_11 = F_45 ( V_73 , struct V_10 ,
V_67 . V_73 ) ;
F_37 ( V_11 ) ;
}
static void F_46 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_47 ( V_15 , V_19 ) ;
F_48 ( V_15 , V_19 ) ;
if ( V_11 -> V_29 . V_1 == V_7 ) {
T_4 V_74 [ V_75 ] = V_76 ;
F_49 ( V_15 , V_74 ) ;
}
}
static void F_50 ( struct V_10 * V_11 , struct V_22 * V_77 ,
struct V_22 * V_78 )
{
F_51 () ;
if ( V_78 ) {
if ( V_11 -> V_16 -> V_79 & V_80 )
F_34 ( V_78 -> V_16 , - 1 ) ;
if ( V_11 -> V_16 -> V_79 & V_81 )
F_36 ( V_78 -> V_16 , - 1 ) ;
F_46 ( V_11 -> V_16 , V_78 -> V_16 ) ;
}
if ( V_77 ) {
if ( V_11 -> V_16 -> V_79 & V_80 )
F_34 ( V_77 -> V_16 , 1 ) ;
if ( V_11 -> V_16 -> V_79 & V_81 )
F_36 ( V_77 -> V_16 , 1 ) ;
F_52 ( V_11 -> V_16 ) ;
F_53 ( V_77 -> V_16 , V_11 -> V_16 ) ;
F_54 ( V_77 -> V_16 , V_11 -> V_16 ) ;
F_55 ( V_11 -> V_16 ) ;
}
}
static void F_56 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
F_57 ( L_9 ,
V_19 , V_15 , V_15 -> V_82 ) ;
memcpy ( V_19 -> V_83 , V_15 -> V_83 , V_15 -> V_82 ) ;
V_19 -> V_84 = V_85 ;
F_40 ( V_86 , V_19 ) ;
}
static void F_58 ( struct V_10 * V_11 ,
struct V_22 * V_77 ,
struct V_22 * V_78 )
__releases( &bond->curr_slave_lock
static bool F_59 ( struct V_10 * V_11 )
{
struct V_22 * V_87 = V_11 -> V_88 ;
struct V_22 * V_89 = V_11 -> V_65 ;
if ( ! V_87 || ! V_89 || V_89 -> V_30 != V_31 )
return true ;
if ( V_11 -> V_90 ) {
V_11 -> V_90 = false ;
return true ;
}
if ( V_11 -> V_29 . V_91 == V_92 &&
( V_87 -> V_35 < V_89 -> V_35 ||
( V_87 -> V_35 == V_89 -> V_35 && V_87 -> V_37 <= V_89 -> V_37 ) ) )
return false ;
if ( V_11 -> V_29 . V_91 == V_93 )
return false ;
return true ;
}
static struct V_22 * F_60 ( struct V_10 * V_11 )
{
struct V_22 * V_22 , * V_94 = NULL ;
struct V_24 * V_25 ;
int V_95 = V_11 -> V_29 . V_96 ;
if ( V_11 -> V_88 && V_11 -> V_88 -> V_30 == V_31 &&
F_59 ( V_11 ) )
return V_11 -> V_88 ;
F_12 (bond, slave, iter) {
if ( V_22 -> V_30 == V_31 )
return V_22 ;
if ( V_22 -> V_30 == V_97 && F_61 ( V_22 -> V_16 ) &&
V_22 -> V_98 < V_95 ) {
V_95 = V_22 -> V_98 ;
V_94 = V_22 ;
}
}
return V_94 ;
}
static bool F_62 ( struct V_10 * V_11 )
{
struct V_22 * V_22 = V_11 -> V_65 ;
F_57 ( L_10 ,
V_11 -> V_16 -> V_56 , V_22 ? V_22 -> V_16 -> V_56 : L_11 ) ;
if ( ! V_22 || ! V_11 -> V_99 ||
F_63 ( V_100 , & V_22 -> V_16 -> V_101 ) )
return false ;
return true ;
}
void F_64 ( struct V_10 * V_11 , struct V_22 * V_77 )
{
struct V_22 * V_78 = V_11 -> V_65 ;
if ( V_78 == V_77 )
return;
if ( V_77 ) {
V_77 -> V_102 = V_102 ;
if ( V_77 -> V_30 == V_97 ) {
if ( F_33 ( V_11 -> V_29 . V_1 ) ) {
F_65 ( L_12 ,
V_11 -> V_16 -> V_56 , V_77 -> V_16 -> V_56 ,
( V_11 -> V_29 . V_96 - V_77 -> V_98 ) * V_11 -> V_29 . V_103 ) ;
}
V_77 -> V_98 = 0 ;
V_77 -> V_30 = V_31 ;
if ( V_11 -> V_29 . V_1 == V_7 )
F_66 ( V_77 , V_31 ) ;
if ( F_16 ( V_11 ) )
F_67 ( V_11 , V_77 , V_31 ) ;
} else {
if ( F_33 ( V_11 -> V_29 . V_1 ) ) {
F_65 ( L_13 ,
V_11 -> V_16 -> V_56 , V_77 -> V_16 -> V_56 ) ;
}
}
}
if ( F_33 ( V_11 -> V_29 . V_1 ) )
F_50 ( V_11 , V_77 , V_78 ) ;
if ( F_16 ( V_11 ) ) {
F_68 ( V_11 , V_77 ) ;
if ( V_78 )
F_69 ( V_78 ) ;
if ( V_77 )
F_70 ( V_77 ) ;
} else {
F_71 ( V_11 -> V_65 , V_77 ) ;
}
if ( V_11 -> V_29 . V_1 == V_4 ) {
if ( V_78 )
F_69 ( V_78 ) ;
if ( V_77 ) {
bool V_104 = false ;
F_70 ( V_77 ) ;
if ( V_11 -> V_29 . V_105 )
F_58 ( V_11 , V_77 ,
V_78 ) ;
if ( F_29 ( V_11 -> V_16 ) ) {
V_11 -> V_99 =
V_11 -> V_29 . V_106 ;
V_104 =
F_62 ( V_11 ) ;
}
F_43 ( & V_11 -> V_69 ) ;
F_72 ( & V_11 -> V_107 ) ;
F_40 ( V_108 , V_11 -> V_16 ) ;
if ( V_104 )
F_40 ( V_109 ,
V_11 -> V_16 ) ;
F_73 ( & V_11 -> V_107 ) ;
F_42 ( & V_11 -> V_69 ) ;
}
}
if ( F_29 ( V_11 -> V_16 ) && ( V_11 -> V_29 . V_110 > 0 ) &&
( ( F_33 ( V_11 -> V_29 . V_1 ) && V_77 ) ||
V_11 -> V_29 . V_1 == V_3 ) ) {
V_11 -> V_70 = V_11 -> V_29 . V_110 ;
F_39 ( V_11 -> V_66 , & V_11 -> V_67 , 1 ) ;
}
}
void F_74 ( struct V_10 * V_11 )
{
struct V_22 * V_111 ;
int V_112 ;
V_111 = F_60 ( V_11 ) ;
if ( V_111 != V_11 -> V_65 ) {
F_64 ( V_11 , V_111 ) ;
V_112 = F_18 ( V_11 ) ;
if ( ! V_112 )
return;
if ( F_21 ( V_11 -> V_16 ) ) {
F_65 ( L_14 ,
V_11 -> V_16 -> V_56 ) ;
} else {
F_65 ( L_15 ,
V_11 -> V_16 -> V_56 ) ;
}
}
}
static inline int F_75 ( struct V_22 * V_22 )
{
struct V_113 * V_114 ;
int V_64 = 0 ;
V_114 = F_76 ( sizeof( * V_114 ) , V_115 ) ;
V_64 = - V_116 ;
if ( ! V_114 )
goto V_117;
V_64 = F_77 ( V_114 , V_22 -> V_16 , V_115 ) ;
if ( V_64 ) {
F_78 ( V_114 ) ;
goto V_117;
}
V_22 -> V_114 = V_114 ;
V_117:
return V_64 ;
}
static inline void F_79 ( struct V_22 * V_22 )
{
struct V_113 * V_114 = V_22 -> V_114 ;
if ( ! V_114 )
return;
V_22 -> V_114 = NULL ;
F_80 ( V_114 ) ;
}
static inline bool F_81 ( struct V_14 * V_15 )
{
if ( V_15 -> V_118 & V_119 )
return false ;
if ( ! V_15 -> V_45 -> V_120 )
return false ;
return true ;
}
static void F_82 ( struct V_14 * V_19 )
{
}
static void F_83 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter)
if ( F_61 ( V_22 -> V_16 ) )
F_79 ( V_22 ) ;
}
static int F_84 ( struct V_14 * V_16 , struct V_121 * V_122 , T_5 V_123 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_64 = 0 ;
F_12 (bond, slave, iter) {
V_64 = F_75 ( V_22 ) ;
if ( V_64 ) {
F_83 ( V_16 ) ;
break;
}
}
return V_64 ;
}
static inline int F_75 ( struct V_22 * V_22 )
{
return 0 ;
}
static inline void F_79 ( struct V_22 * V_22 )
{
}
static void F_83 ( struct V_14 * V_19 )
{
}
static T_6 F_85 ( struct V_14 * V_16 ,
T_6 V_124 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_24 * V_25 ;
T_6 V_125 ;
struct V_22 * V_22 ;
if ( ! F_19 ( V_11 ) ) {
V_124 |= V_126 ;
return V_124 ;
}
V_125 = V_124 ;
V_124 &= ~ V_127 ;
V_124 |= V_128 ;
F_12 (bond, slave, iter) {
V_124 = F_86 ( V_124 ,
V_22 -> V_16 -> V_124 ,
V_125 ) ;
}
V_124 = F_87 ( V_124 , V_125 ) ;
return V_124 ;
}
static void F_88 ( struct V_10 * V_11 )
{
unsigned int V_79 , V_129 = V_130 ;
T_6 V_131 = V_132 ;
struct V_14 * V_19 = V_11 -> V_16 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
unsigned short V_133 = V_134 ;
unsigned int V_135 = V_136 ;
T_2 V_137 = V_138 ;
if ( ! F_19 ( V_11 ) )
goto V_139;
F_12 (bond, slave, iter) {
V_131 = F_86 ( V_131 ,
V_22 -> V_16 -> V_131 , V_132 ) ;
V_129 &= V_22 -> V_16 -> V_118 ;
if ( V_22 -> V_16 -> V_140 > V_133 )
V_133 = V_22 -> V_16 -> V_140 ;
V_135 = F_89 ( V_135 , V_22 -> V_16 -> V_135 ) ;
V_137 = F_89 ( V_137 , V_22 -> V_16 -> V_137 ) ;
}
V_139:
V_19 -> V_131 = V_131 ;
V_19 -> V_140 = V_133 ;
V_19 -> V_137 = V_137 ;
F_90 ( V_19 , V_135 ) ;
V_79 = V_19 -> V_118 & ~ V_130 ;
V_19 -> V_118 = V_79 | V_129 ;
F_91 ( V_19 ) ;
}
static void F_92 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
V_19 -> V_141 = V_15 -> V_141 ;
V_19 -> type = V_15 -> type ;
V_19 -> V_140 = V_15 -> V_140 ;
V_19 -> V_82 = V_15 -> V_82 ;
memcpy ( V_19 -> V_142 , V_15 -> V_142 ,
V_15 -> V_82 ) ;
}
static bool F_93 ( struct V_12 * V_13 ,
struct V_22 * V_22 ,
struct V_10 * V_11 )
{
if ( F_94 ( V_22 ) ) {
if ( V_11 -> V_29 . V_1 == V_9 &&
V_13 -> V_143 != V_144 &&
V_13 -> V_143 != V_145 )
return false ;
return true ;
}
return false ;
}
static T_7 F_95 ( struct V_12 * * V_146 )
{
struct V_12 * V_13 = * V_146 ;
struct V_22 * V_22 ;
struct V_10 * V_11 ;
int (* F_96)( const struct V_12 * , struct V_10 * ,
struct V_22 * );
int V_147 = V_148 ;
V_13 = F_97 ( V_13 , V_115 ) ;
if ( F_5 ( ! V_13 ) )
return V_149 ;
* V_146 = V_13 ;
V_22 = F_98 ( V_13 -> V_16 ) ;
V_11 = V_22 -> V_11 ;
if ( V_11 -> V_29 . V_150 )
V_22 -> V_16 -> V_151 = V_102 ;
F_96 = F_99 ( V_11 -> F_96 ) ;
if ( F_96 ) {
V_147 = F_96 ( V_13 , V_11 , V_22 ) ;
if ( V_147 == V_149 ) {
F_100 ( V_13 ) ;
return V_147 ;
}
}
if ( F_93 ( V_13 , V_22 , V_11 ) ) {
return V_152 ;
}
V_13 -> V_16 = V_11 -> V_16 ;
if ( V_11 -> V_29 . V_1 == V_9 &&
V_11 -> V_16 -> V_118 & V_153 &&
V_13 -> V_143 == V_154 ) {
if ( F_5 ( F_101 ( V_13 ,
V_13 -> V_155 - F_102 ( V_13 ) ) ) ) {
F_103 ( V_13 ) ;
return V_149 ;
}
memcpy ( F_104 ( V_13 ) -> V_156 , V_11 -> V_16 -> V_83 , V_75 ) ;
}
return V_147 ;
}
static int F_105 ( struct V_14 * V_19 ,
struct V_14 * V_15 ,
struct V_22 * V_22 )
{
int V_64 ;
V_64 = F_106 ( V_15 , V_19 , V_22 ) ;
if ( V_64 )
return V_64 ;
V_15 -> V_79 |= V_157 ;
F_107 ( V_158 , V_15 , V_157 , V_159 ) ;
return 0 ;
}
static void F_108 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
F_109 ( V_15 , V_19 ) ;
V_15 -> V_79 &= ~ V_157 ;
F_107 ( V_158 , V_15 , V_157 , V_159 ) ;
}
int F_110 ( struct V_14 * V_19 , struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
const struct V_43 * V_44 = V_15 -> V_45 ;
struct V_22 * V_160 = NULL , * V_161 ;
struct V_162 V_163 ;
int V_164 ;
int V_26 = 0 , V_165 ;
if ( ! V_11 -> V_29 . V_50 &&
V_15 -> V_52 -> V_53 == NULL &&
V_44 -> V_54 == NULL ) {
F_111 ( L_16 ,
V_19 -> V_56 , V_15 -> V_56 ) ;
}
if ( V_15 -> V_79 & V_157 ) {
F_57 ( L_17 ) ;
return - V_166 ;
}
if ( V_15 -> V_124 & V_126 ) {
F_57 ( L_18 , V_15 -> V_56 ) ;
if ( F_112 ( V_19 ) ) {
F_113 ( L_19 ,
V_19 -> V_56 , V_15 -> V_56 , V_19 -> V_56 ) ;
return - V_167 ;
} else {
F_111 ( L_20 ,
V_19 -> V_56 , V_15 -> V_56 ,
V_15 -> V_56 , V_19 -> V_56 ) ;
}
} else {
F_57 ( L_21 , V_15 -> V_56 ) ;
}
if ( ( V_15 -> V_79 & V_168 ) ) {
F_113 ( L_22 ,
V_15 -> V_56 ) ;
V_26 = - V_167 ;
goto V_169;
}
if ( ! F_19 ( V_11 ) ) {
if ( V_19 -> type != V_15 -> type ) {
F_57 ( L_23 ,
V_19 -> V_56 ,
V_19 -> type , V_15 -> type ) ;
V_26 = F_40 ( V_170 ,
V_19 ) ;
V_26 = F_114 ( V_26 ) ;
if ( V_26 ) {
F_113 ( L_24 ,
V_19 -> V_56 ) ;
V_26 = - V_166 ;
goto V_169;
}
F_115 ( V_19 ) ;
F_116 ( V_19 ) ;
if ( V_15 -> type != V_171 )
F_92 ( V_19 , V_15 ) ;
else {
F_117 ( V_19 ) ;
V_19 -> V_118 &= ~ V_172 ;
}
F_40 ( V_173 ,
V_19 ) ;
}
} else if ( V_19 -> type != V_15 -> type ) {
F_113 ( L_25 ,
V_15 -> V_56 ,
V_15 -> type , V_19 -> type ) ;
V_26 = - V_174 ;
goto V_169;
}
if ( V_44 -> V_175 == NULL ) {
if ( ! F_19 ( V_11 ) ) {
F_111 ( L_26 ,
V_19 -> V_56 ) ;
V_11 -> V_29 . V_105 = V_176 ;
} else if ( V_11 -> V_29 . V_105 != V_176 ) {
F_113 ( L_27 ,
V_19 -> V_56 ) ;
V_26 = - V_177 ;
goto V_169;
}
}
F_40 ( V_178 , V_15 ) ;
if ( ! F_19 ( V_11 ) &&
V_11 -> V_16 -> V_84 == V_179 )
F_56 ( V_11 -> V_16 , V_15 ) ;
V_160 = F_76 ( sizeof( struct V_22 ) , V_159 ) ;
if ( ! V_160 ) {
V_26 = - V_116 ;
goto V_169;
}
V_160 -> V_180 = 0 ;
V_160 -> V_181 = V_15 -> V_182 ;
V_26 = F_118 ( V_15 , V_11 -> V_16 -> V_182 ) ;
if ( V_26 ) {
F_57 ( L_28 , V_26 ) ;
goto V_183;
}
memcpy ( V_160 -> V_184 , V_15 -> V_83 , V_75 ) ;
if ( ! V_11 -> V_29 . V_105 ) {
memcpy ( V_163 . V_185 , V_19 -> V_83 , V_19 -> V_82 ) ;
V_163 . V_186 = V_15 -> type ;
V_26 = F_119 ( V_15 , & V_163 ) ;
if ( V_26 ) {
F_57 ( L_29 , V_26 ) ;
goto V_187;
}
}
V_26 = F_120 ( V_15 ) ;
if ( V_26 ) {
F_57 ( L_30 , V_15 -> V_56 ) ;
goto V_188;
}
V_160 -> V_11 = V_11 ;
V_160 -> V_16 = V_15 ;
V_15 -> V_118 |= V_189 ;
if ( F_16 ( V_11 ) ) {
V_26 = F_121 ( V_11 , V_160 ) ;
if ( V_26 )
goto V_190;
}
if ( ! F_33 ( V_11 -> V_29 . V_1 ) ) {
if ( V_19 -> V_79 & V_80 ) {
V_26 = F_34 ( V_15 , 1 ) ;
if ( V_26 )
goto V_190;
}
if ( V_19 -> V_79 & V_81 ) {
V_26 = F_36 ( V_15 , 1 ) ;
if ( V_26 )
goto V_190;
}
F_52 ( V_19 ) ;
F_122 ( V_15 , V_19 ) ;
F_123 ( V_15 , V_19 ) ;
F_55 ( V_19 ) ;
}
if ( V_11 -> V_29 . V_1 == V_7 ) {
T_4 V_74 [ V_75 ] = V_76 ;
F_124 ( V_15 , V_74 ) ;
}
V_26 = F_125 ( V_15 , V_19 ) ;
if ( V_26 ) {
F_113 ( L_31 ,
V_19 -> V_56 , V_15 -> V_56 ) ;
goto V_190;
}
V_161 = F_126 ( V_11 ) ;
V_160 -> V_98 = 0 ;
V_160 -> V_191 = 0 ;
F_24 ( V_160 ) ;
V_160 -> V_192 = V_102 -
( F_127 ( V_11 -> V_29 . V_150 ) + 1 ) ;
for ( V_165 = 0 ; V_165 < V_193 ; V_165 ++ )
V_160 -> V_194 [ V_165 ] = V_160 -> V_192 ;
if ( V_11 -> V_29 . V_103 && ! V_11 -> V_29 . V_50 ) {
V_164 = F_27 ( V_11 , V_15 , 1 ) ;
if ( ( V_164 == - 1 ) && ! V_11 -> V_29 . V_150 ) {
F_111 ( L_32 ,
V_19 -> V_56 , V_15 -> V_56 ) ;
} else if ( V_164 == - 1 ) {
F_111 ( L_33 ,
V_19 -> V_56 , V_15 -> V_56 ) ;
}
}
if ( V_11 -> V_29 . V_103 ) {
if ( F_27 ( V_11 , V_15 , 0 ) == V_51 ) {
if ( V_11 -> V_29 . V_96 ) {
V_160 -> V_30 = V_97 ;
V_160 -> V_98 = V_11 -> V_29 . V_96 ;
} else {
V_160 -> V_30 = V_31 ;
}
} else {
V_160 -> V_30 = V_195 ;
}
} else if ( V_11 -> V_29 . V_150 ) {
V_160 -> V_30 = ( F_21 ( V_15 ) ?
V_31 : V_195 ) ;
} else {
V_160 -> V_30 = V_31 ;
}
if ( V_160 -> V_30 != V_195 )
V_160 -> V_102 = V_102 ;
F_57 ( L_34 ,
V_160 -> V_30 == V_195 ? L_35 :
( V_160 -> V_30 == V_31 ? L_36 : L_37 ) ) ;
if ( F_33 ( V_11 -> V_29 . V_1 ) && V_11 -> V_29 . V_196 [ 0 ] ) {
if ( strcmp ( V_11 -> V_29 . V_196 , V_160 -> V_16 -> V_56 ) == 0 ) {
V_11 -> V_88 = V_160 ;
V_11 -> V_90 = true ;
}
}
switch ( V_11 -> V_29 . V_1 ) {
case V_4 :
F_69 ( V_160 ) ;
break;
case V_7 :
F_69 ( V_160 ) ;
if ( ! V_161 ) {
F_128 ( V_160 ) . V_197 = 1 ;
F_129 ( V_11 , 1000 / V_198 ) ;
} else {
F_128 ( V_160 ) . V_197 =
F_128 ( V_161 ) . V_197 + 1 ;
}
F_130 ( V_160 ) ;
break;
case V_8 :
case V_9 :
F_131 ( V_160 ) ;
F_69 ( V_160 ) ;
break;
default:
F_57 ( L_38 ) ;
F_131 ( V_160 ) ;
if ( ! V_11 -> V_65 && V_160 -> V_30 == V_31 )
F_71 ( V_11 -> V_65 , V_160 ) ;
break;
}
#ifdef F_132
V_15 -> V_199 = V_11 -> V_16 -> V_199 ;
if ( V_15 -> V_199 ) {
if ( F_75 ( V_160 ) ) {
F_72 ( & V_11 -> V_107 ) ;
F_65 ( L_39
L_40 ,
V_19 -> V_56 ) ;
V_26 = - V_166 ;
goto V_200;
}
}
#endif
V_26 = F_133 ( V_15 , F_95 ,
V_160 ) ;
if ( V_26 ) {
F_57 ( L_41 , V_26 ) ;
goto V_200;
}
V_26 = F_105 ( V_19 , V_15 , V_160 ) ;
if ( V_26 ) {
F_57 ( L_42 , V_26 ) ;
goto V_201;
}
V_11 -> V_202 ++ ;
F_88 ( V_11 ) ;
F_18 ( V_11 ) ;
if ( F_33 ( V_11 -> V_29 . V_1 ) ) {
F_73 ( & V_11 -> V_107 ) ;
F_42 ( & V_11 -> V_69 ) ;
F_74 ( V_11 ) ;
F_43 ( & V_11 -> V_69 ) ;
F_72 ( & V_11 -> V_107 ) ;
}
F_65 ( L_43 ,
V_19 -> V_56 , V_15 -> V_56 ,
F_134 ( V_160 ) ? L_44 : L_45 ,
V_160 -> V_30 != V_195 ? L_46 : L_47 ) ;
return 0 ;
V_201:
F_135 ( V_15 ) ;
V_200:
if ( ! F_33 ( V_11 -> V_29 . V_1 ) )
F_46 ( V_19 , V_15 ) ;
F_136 ( V_15 , V_19 ) ;
F_42 ( & V_11 -> V_107 ) ;
if ( V_11 -> V_88 == V_160 )
V_11 -> V_88 = NULL ;
if ( V_11 -> V_65 == V_160 ) {
F_64 ( V_11 , NULL ) ;
F_43 ( & V_11 -> V_107 ) ;
F_73 ( & V_11 -> V_107 ) ;
F_42 ( & V_11 -> V_69 ) ;
F_74 ( V_11 ) ;
F_43 ( & V_11 -> V_69 ) ;
F_72 ( & V_11 -> V_107 ) ;
} else {
F_43 ( & V_11 -> V_107 ) ;
}
F_79 ( V_160 ) ;
V_190:
V_15 -> V_118 &= ~ V_189 ;
F_137 ( V_15 ) ;
V_188:
if ( ! V_11 -> V_29 . V_105 ) {
memcpy ( V_163 . V_185 , V_160 -> V_184 , V_75 ) ;
V_163 . V_186 = V_15 -> type ;
F_119 ( V_15 , & V_163 ) ;
}
V_187:
F_118 ( V_15 , V_160 -> V_181 ) ;
V_183:
F_78 ( V_160 ) ;
V_169:
if ( ! F_19 ( V_11 ) &&
F_138 ( V_19 -> V_83 , V_15 -> V_83 ) )
F_139 ( V_19 ) ;
return V_26 ;
}
static int F_140 ( struct V_14 * V_19 ,
struct V_14 * V_15 ,
bool V_203 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_204 ;
struct V_162 V_163 ;
int V_205 = V_19 -> V_79 ;
T_6 V_206 = V_19 -> V_124 ;
if ( ! ( V_15 -> V_79 & V_157 ) ||
! F_141 ( V_15 , V_19 ) ) {
F_113 ( L_48 ,
V_19 -> V_56 , V_15 -> V_56 ) ;
return - V_174 ;
}
F_142 () ;
F_42 ( & V_11 -> V_107 ) ;
V_22 = F_8 ( V_11 , V_15 ) ;
if ( ! V_22 ) {
F_65 ( L_49 ,
V_19 -> V_56 , V_15 -> V_56 ) ;
F_43 ( & V_11 -> V_107 ) ;
F_143 () ;
return - V_174 ;
}
F_43 ( & V_11 -> V_107 ) ;
V_11 -> V_202 -- ;
F_108 ( V_19 , V_15 ) ;
F_135 ( V_15 ) ;
F_42 ( & V_11 -> V_107 ) ;
if ( V_11 -> V_29 . V_1 == V_7 ) {
F_144 ( V_22 ) ;
}
F_65 ( L_50 ,
V_19 -> V_56 ,
F_134 ( V_22 ) ? L_51 : L_52 ,
V_15 -> V_56 ) ;
V_204 = V_11 -> V_65 ;
V_11 -> V_207 = NULL ;
if ( ! V_203 && ! V_11 -> V_29 . V_105 ) {
if ( F_138 ( V_19 -> V_83 , V_22 -> V_184 ) &&
F_19 ( V_11 ) )
F_145 ( L_53 ,
V_19 -> V_56 , V_15 -> V_56 ,
V_22 -> V_184 ,
V_19 -> V_56 , V_15 -> V_56 ) ;
}
if ( V_11 -> V_88 == V_22 )
V_11 -> V_88 = NULL ;
if ( V_204 == V_22 )
F_64 ( V_11 , NULL ) ;
if ( F_16 ( V_11 ) ) {
F_43 ( & V_11 -> V_107 ) ;
F_146 ( V_11 , V_22 ) ;
F_42 ( & V_11 -> V_107 ) ;
}
if ( V_203 ) {
F_71 ( V_11 -> V_65 , NULL ) ;
} else if ( V_204 == V_22 ) {
F_43 ( & V_11 -> V_107 ) ;
F_73 ( & V_11 -> V_107 ) ;
F_42 ( & V_11 -> V_69 ) ;
F_74 ( V_11 ) ;
F_43 ( & V_11 -> V_69 ) ;
F_72 ( & V_11 -> V_107 ) ;
F_42 ( & V_11 -> V_107 ) ;
}
if ( ! F_19 ( V_11 ) ) {
F_18 ( V_11 ) ;
F_139 ( V_19 ) ;
if ( F_112 ( V_19 ) ) {
F_111 ( L_54 ,
V_19 -> V_56 , V_19 -> V_56 ) ;
F_111 ( L_55 ,
V_19 -> V_56 ) ;
}
}
F_43 ( & V_11 -> V_107 ) ;
F_143 () ;
F_147 () ;
if ( ! F_19 ( V_11 ) ) {
F_40 ( V_86 , V_11 -> V_16 ) ;
F_40 ( V_208 , V_11 -> V_16 ) ;
}
F_88 ( V_11 ) ;
if ( ! ( V_19 -> V_124 & V_126 ) &&
( V_206 & V_126 ) )
F_65 ( L_56 ,
V_19 -> V_56 , V_15 -> V_56 , V_19 -> V_56 ) ;
F_136 ( V_15 , V_19 ) ;
if ( ! F_33 ( V_11 -> V_29 . V_1 ) ) {
if ( V_205 & V_80 )
F_34 ( V_15 , - 1 ) ;
if ( V_205 & V_81 )
F_36 ( V_15 , - 1 ) ;
F_46 ( V_19 , V_15 ) ;
}
F_79 ( V_22 ) ;
F_137 ( V_15 ) ;
if ( V_11 -> V_29 . V_105 != V_176 ) {
memcpy ( V_163 . V_185 , V_22 -> V_184 , V_75 ) ;
V_163 . V_186 = V_15 -> type ;
F_119 ( V_15 , & V_163 ) ;
}
F_118 ( V_15 , V_22 -> V_181 ) ;
V_15 -> V_118 &= ~ V_189 ;
F_78 ( V_22 ) ;
return 0 ;
}
int F_148 ( struct V_14 * V_19 , struct V_14 * V_15 )
{
return F_140 ( V_19 , V_15 , false ) ;
}
static int F_149 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
int V_147 ;
V_147 = F_148 ( V_19 , V_15 ) ;
if ( V_147 == 0 && ! F_19 ( V_11 ) ) {
V_19 -> V_118 |= V_119 ;
F_65 ( L_57 ,
V_19 -> V_56 , V_19 -> V_56 ) ;
F_150 ( V_19 ) ;
}
return V_147 ;
}
static int F_151 ( struct V_14 * V_19 , struct V_209 * V_210 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
V_210 -> V_211 = V_11 -> V_29 . V_1 ;
V_210 -> V_103 = V_11 -> V_29 . V_103 ;
F_73 ( & V_11 -> V_107 ) ;
V_210 -> V_212 = V_11 -> V_202 ;
F_72 ( & V_11 -> V_107 ) ;
return 0 ;
}
static int F_152 ( struct V_14 * V_19 , struct V_213 * V_210 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
int V_165 = 0 , V_26 = - V_214 ;
struct V_22 * V_22 ;
F_73 ( & V_11 -> V_107 ) ;
F_12 (bond, slave, iter) {
if ( V_165 ++ == ( int ) V_210 -> V_215 ) {
V_26 = 0 ;
strcpy ( V_210 -> V_216 , V_22 -> V_16 -> V_56 ) ;
V_210 -> V_30 = V_22 -> V_30 ;
V_210 -> V_101 = F_153 ( V_22 ) ;
V_210 -> V_191 = V_22 -> V_191 ;
break;
}
}
F_72 ( & V_11 -> V_107 ) ;
return V_26 ;
}
static int F_154 ( struct V_10 * V_11 )
{
int V_217 , V_218 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
bool V_219 ;
V_219 = ! V_11 -> V_65 ? true : false ;
F_12 (bond, slave, iter) {
V_22 -> V_220 = V_221 ;
V_217 = F_27 ( V_11 , V_22 -> V_16 , 0 ) ;
switch ( V_22 -> V_30 ) {
case V_31 :
if ( V_217 )
continue;
V_22 -> V_30 = V_222 ;
V_22 -> V_98 = V_11 -> V_29 . V_223 ;
if ( V_22 -> V_98 ) {
F_65 ( L_58 ,
V_11 -> V_16 -> V_56 ,
( V_11 -> V_29 . V_1 ==
V_4 ) ?
( F_134 ( V_22 ) ?
L_59 : L_60 ) : L_61 ,
V_22 -> V_16 -> V_56 ,
V_11 -> V_29 . V_223 * V_11 -> V_29 . V_103 ) ;
}
case V_222 :
if ( V_217 ) {
V_22 -> V_30 = V_31 ;
V_22 -> V_102 = V_102 ;
F_65 ( L_62 ,
V_11 -> V_16 -> V_56 ,
( V_11 -> V_29 . V_223 - V_22 -> V_98 ) *
V_11 -> V_29 . V_103 ,
V_22 -> V_16 -> V_56 ) ;
continue;
}
if ( V_22 -> V_98 <= 0 ) {
V_22 -> V_220 = V_195 ;
V_218 ++ ;
continue;
}
V_22 -> V_98 -- ;
break;
case V_195 :
if ( ! V_217 )
continue;
V_22 -> V_30 = V_97 ;
V_22 -> V_98 = V_11 -> V_29 . V_96 ;
if ( V_22 -> V_98 ) {
F_65 ( L_63 ,
V_11 -> V_16 -> V_56 , V_22 -> V_16 -> V_56 ,
V_219 ? 0 :
V_11 -> V_29 . V_96 *
V_11 -> V_29 . V_103 ) ;
}
case V_97 :
if ( ! V_217 ) {
V_22 -> V_30 = V_195 ;
F_65 ( L_64 ,
V_11 -> V_16 -> V_56 ,
( V_11 -> V_29 . V_96 - V_22 -> V_98 ) *
V_11 -> V_29 . V_103 ,
V_22 -> V_16 -> V_56 ) ;
continue;
}
if ( V_219 )
V_22 -> V_98 = 0 ;
if ( V_22 -> V_98 <= 0 ) {
V_22 -> V_220 = V_31 ;
V_218 ++ ;
V_219 = false ;
continue;
}
V_22 -> V_98 -- ;
break;
}
}
return V_218 ;
}
static void F_155 ( struct V_10 * V_11 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
switch ( V_22 -> V_220 ) {
case V_221 :
continue;
case V_31 :
V_22 -> V_30 = V_31 ;
V_22 -> V_102 = V_102 ;
if ( V_11 -> V_29 . V_1 == V_7 ) {
F_156 ( V_22 ) ;
} else if ( V_11 -> V_29 . V_1 != V_4 ) {
F_131 ( V_22 ) ;
} else if ( V_22 != V_11 -> V_88 ) {
F_156 ( V_22 ) ;
}
F_65 ( L_65 ,
V_11 -> V_16 -> V_56 , V_22 -> V_16 -> V_56 ,
V_22 -> V_35 == V_36 ? 0 : V_22 -> V_35 ,
V_22 -> V_37 ? L_66 : L_67 ) ;
if ( V_11 -> V_29 . V_1 == V_7 )
F_66 ( V_22 , V_31 ) ;
if ( F_16 ( V_11 ) )
F_67 ( V_11 , V_22 ,
V_31 ) ;
if ( ! V_11 -> V_65 ||
( V_22 == V_11 -> V_88 ) )
goto V_224;
continue;
case V_195 :
if ( V_22 -> V_191 < V_225 )
V_22 -> V_191 ++ ;
V_22 -> V_30 = V_195 ;
if ( V_11 -> V_29 . V_1 == V_4 ||
V_11 -> V_29 . V_1 == V_7 )
F_69 ( V_22 ) ;
F_65 ( L_68 ,
V_11 -> V_16 -> V_56 , V_22 -> V_16 -> V_56 ) ;
if ( V_11 -> V_29 . V_1 == V_7 )
F_66 ( V_22 ,
V_195 ) ;
if ( F_16 ( V_11 ) )
F_67 ( V_11 , V_22 ,
V_195 ) ;
if ( V_22 == V_11 -> V_65 )
goto V_224;
continue;
default:
F_113 ( L_69 ,
V_11 -> V_16 -> V_56 , V_22 -> V_220 ,
V_22 -> V_16 -> V_56 ) ;
V_22 -> V_220 = V_221 ;
continue;
}
V_224:
F_51 () ;
F_142 () ;
F_42 ( & V_11 -> V_69 ) ;
F_74 ( V_11 ) ;
F_43 ( & V_11 -> V_69 ) ;
F_143 () ;
}
F_18 ( V_11 ) ;
}
void F_157 ( struct V_72 * V_73 )
{
struct V_10 * V_11 = F_45 ( V_73 , struct V_10 ,
V_226 . V_73 ) ;
bool V_104 = false ;
unsigned long V_98 ;
F_73 ( & V_11 -> V_107 ) ;
V_98 = F_127 ( V_11 -> V_29 . V_103 ) ;
if ( ! F_19 ( V_11 ) )
goto V_227;
V_104 = F_62 ( V_11 ) ;
if ( F_154 ( V_11 ) ) {
F_72 ( & V_11 -> V_107 ) ;
if ( ! F_38 () ) {
F_73 ( & V_11 -> V_107 ) ;
V_98 = 1 ;
V_104 = false ;
goto V_227;
}
F_73 ( & V_11 -> V_107 ) ;
F_155 ( V_11 ) ;
F_72 ( & V_11 -> V_107 ) ;
F_41 () ;
F_73 ( & V_11 -> V_107 ) ;
}
V_227:
if ( V_11 -> V_29 . V_103 )
F_39 ( V_11 -> V_66 , & V_11 -> V_226 , V_98 ) ;
F_72 ( & V_11 -> V_107 ) ;
if ( V_104 ) {
if ( ! F_38 () )
return;
F_40 ( V_109 , V_11 -> V_16 ) ;
F_41 () ;
}
}
static bool F_158 ( struct V_10 * V_11 , T_8 V_228 )
{
struct V_14 * V_229 ;
struct V_24 * V_25 ;
bool V_147 = false ;
if ( V_228 == F_159 ( V_11 -> V_16 , 0 , V_228 ) )
return true ;
F_160 () ;
F_161 (bond->dev, upper, iter) {
if ( V_228 == F_159 ( V_229 , 0 , V_228 ) ) {
V_147 = true ;
break;
}
}
F_162 () ;
return V_147 ;
}
static void F_163 ( struct V_14 * V_15 , int V_230 , T_8 V_231 , T_8 V_232 , unsigned short V_233 )
{
struct V_12 * V_13 ;
F_57 ( L_70 , V_230 ,
V_15 -> V_56 , & V_231 , & V_232 , V_233 ) ;
V_13 = F_164 ( V_230 , V_234 , V_231 , V_15 , V_232 ,
NULL , V_15 -> V_83 , NULL ) ;
if ( ! V_13 ) {
F_113 ( L_71 ) ;
return;
}
if ( V_233 ) {
V_13 = F_165 ( V_13 , F_166 ( V_235 ) , V_233 ) ;
if ( ! V_13 ) {
F_113 ( L_72 ) ;
return;
}
}
F_167 ( V_13 ) ;
}
static void F_168 ( struct V_10 * V_11 , struct V_22 * V_22 )
{
struct V_14 * V_229 , * V_236 ;
struct V_24 * V_25 , * V_237 ;
struct V_238 * V_239 ;
T_8 * V_240 = V_11 -> V_29 . V_241 , V_163 ;
int V_165 , V_233 ;
for ( V_165 = 0 ; V_165 < V_193 && V_240 [ V_165 ] ; V_165 ++ ) {
F_57 ( L_73 , & V_240 [ V_165 ] ) ;
V_239 = F_169 ( F_170 ( V_11 -> V_16 ) , V_240 [ V_165 ] , 0 ,
V_242 , 0 ) ;
if ( F_171 ( V_239 ) ) {
F_57 ( L_74 ,
V_11 -> V_16 -> V_56 , & V_240 [ V_165 ] ) ;
continue;
}
V_233 = 0 ;
if ( V_239 -> V_243 . V_16 == V_11 -> V_16 )
goto V_244;
F_160 () ;
F_161 (bond->dev, vlan_upper,
vlan_iter) {
if ( ! F_172 ( V_236 ) )
continue;
F_161 (vlan_upper, upper,
iter) {
if ( V_229 == V_239 -> V_243 . V_16 ) {
V_233 = F_173 ( V_236 ) ;
F_162 () ;
goto V_244;
}
}
}
F_161 (bond->dev, upper, iter) {
if ( V_229 == V_239 -> V_243 . V_16 ) {
if ( F_172 ( V_229 ) )
V_233 = F_173 ( V_229 ) ;
F_162 () ;
goto V_244;
}
}
F_162 () ;
F_57 ( L_75 ,
V_11 -> V_16 -> V_56 , & V_240 [ V_165 ] ,
V_239 -> V_243 . V_16 ? V_239 -> V_243 . V_16 -> V_56 : L_11 ) ;
F_174 ( V_239 ) ;
continue;
V_244:
V_163 = F_159 ( V_239 -> V_243 . V_16 , V_240 [ V_165 ] , 0 ) ;
F_174 ( V_239 ) ;
F_163 ( V_22 -> V_16 , V_245 , V_240 [ V_165 ] ,
V_163 , V_233 ) ;
}
}
static void F_175 ( struct V_10 * V_11 , struct V_22 * V_22 , T_8 V_246 , T_8 V_247 )
{
int V_165 ;
if ( ! V_246 || ! F_158 ( V_11 , V_247 ) ) {
F_57 ( L_76 , & V_246 , & V_247 ) ;
return;
}
V_165 = F_176 ( V_11 -> V_29 . V_241 , V_246 ) ;
if ( V_165 == - 1 ) {
F_57 ( L_77 , & V_246 ) ;
return;
}
V_22 -> V_192 = V_102 ;
V_22 -> V_194 [ V_165 ] = V_102 ;
}
int F_177 ( const struct V_12 * V_13 , struct V_10 * V_11 ,
struct V_22 * V_22 )
{
struct V_248 * V_249 = (struct V_248 * ) V_13 -> V_155 ;
unsigned char * V_250 ;
T_8 V_246 , V_247 ;
int V_251 ;
if ( V_13 -> V_252 != F_178 ( V_234 ) )
return V_148 ;
F_73 ( & V_11 -> V_107 ) ;
if ( ! F_179 ( V_11 , V_22 ) )
goto V_253;
V_251 = F_180 ( V_11 -> V_16 ) ;
F_57 ( L_78 ,
V_11 -> V_16 -> V_56 , V_13 -> V_16 -> V_56 ) ;
if ( V_251 > F_181 ( V_13 ) ) {
V_249 = F_182 ( V_251 , V_115 ) ;
if ( ! V_249 )
goto V_253;
if ( F_183 ( V_13 , 0 , V_249 , V_251 ) < 0 )
goto V_253;
}
if ( V_249 -> V_254 != V_11 -> V_16 -> V_82 ||
V_13 -> V_143 == V_255 ||
V_13 -> V_143 == V_256 ||
V_249 -> V_257 != F_166 ( V_171 ) ||
V_249 -> V_258 != F_166 ( V_259 ) ||
V_249 -> V_260 != 4 )
goto V_253;
V_250 = ( unsigned char * ) ( V_249 + 1 ) ;
V_250 += V_11 -> V_16 -> V_82 ;
memcpy ( & V_246 , V_250 , 4 ) ;
V_250 += 4 + V_11 -> V_16 -> V_82 ;
memcpy ( & V_247 , V_250 , 4 ) ;
F_57 ( L_79 ,
V_11 -> V_16 -> V_56 , V_22 -> V_16 -> V_56 , F_153 ( V_22 ) ,
V_11 -> V_29 . V_261 , F_179 ( V_11 , V_22 ) ,
& V_246 , & V_247 ) ;
if ( F_134 ( V_22 ) )
F_175 ( V_11 , V_22 , V_246 , V_247 ) ;
else if ( V_11 -> V_65 &&
F_184 ( F_185 ( V_11 , V_11 -> V_65 ) ,
V_11 -> V_65 -> V_102 ) )
F_175 ( V_11 , V_22 , V_247 , V_246 ) ;
V_253:
F_72 ( & V_11 -> V_107 ) ;
if ( V_249 != (struct V_248 * ) V_13 -> V_155 )
F_78 ( V_249 ) ;
return V_148 ;
}
static bool F_186 ( struct V_10 * V_11 , unsigned long V_262 ,
int V_263 )
{
int V_264 = F_127 ( V_11 -> V_29 . V_150 ) ;
return F_187 ( V_102 ,
V_262 - V_264 ,
V_262 + V_263 * V_264 + V_264 / 2 ) ;
}
void F_188 ( struct V_72 * V_73 )
{
struct V_10 * V_11 = F_45 ( V_73 , struct V_10 ,
V_265 . V_73 ) ;
struct V_22 * V_22 , * V_204 ;
struct V_24 * V_25 ;
int V_224 = 0 ;
F_73 ( & V_11 -> V_107 ) ;
if ( ! F_19 ( V_11 ) )
goto V_227;
V_204 = V_11 -> V_65 ;
F_12 (bond, slave, iter) {
unsigned long V_266 = F_189 ( V_22 -> V_16 ) ;
if ( V_22 -> V_30 != V_31 ) {
if ( F_186 ( V_11 , V_266 , 1 ) &&
F_186 ( V_11 , V_22 -> V_16 -> V_151 , 1 ) ) {
V_22 -> V_30 = V_31 ;
F_131 ( V_22 ) ;
if ( ! V_204 ) {
F_65 ( L_80 ,
V_11 -> V_16 -> V_56 ,
V_22 -> V_16 -> V_56 ) ;
V_224 = 1 ;
} else {
F_65 ( L_81 ,
V_11 -> V_16 -> V_56 ,
V_22 -> V_16 -> V_56 ) ;
}
}
} else {
if ( ! F_186 ( V_11 , V_266 , 2 ) ||
! F_186 ( V_11 , V_22 -> V_16 -> V_151 , 2 ) ) {
V_22 -> V_30 = V_195 ;
F_156 ( V_22 ) ;
if ( V_22 -> V_191 < V_225 )
V_22 -> V_191 ++ ;
F_65 ( L_82 ,
V_11 -> V_16 -> V_56 ,
V_22 -> V_16 -> V_56 ) ;
if ( V_22 == V_204 )
V_224 = 1 ;
}
}
if ( F_61 ( V_22 -> V_16 ) )
F_168 ( V_11 , V_22 ) ;
}
if ( V_224 ) {
F_142 () ;
F_42 ( & V_11 -> V_69 ) ;
F_74 ( V_11 ) ;
F_43 ( & V_11 -> V_69 ) ;
F_143 () ;
}
V_227:
if ( V_11 -> V_29 . V_150 )
F_39 ( V_11 -> V_66 , & V_11 -> V_265 ,
F_127 ( V_11 -> V_29 . V_150 ) ) ;
F_72 ( & V_11 -> V_107 ) ;
}
static int F_190 ( struct V_10 * V_11 )
{
unsigned long V_266 , V_151 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_218 = 0 ;
F_12 (bond, slave, iter) {
V_22 -> V_220 = V_221 ;
V_151 = F_185 ( V_11 , V_22 ) ;
if ( V_22 -> V_30 != V_31 ) {
if ( F_186 ( V_11 , V_151 , 1 ) ) {
V_22 -> V_220 = V_31 ;
V_218 ++ ;
}
continue;
}
if ( F_186 ( V_11 , V_22 -> V_102 , 2 ) )
continue;
if ( ! F_134 ( V_22 ) &&
! V_11 -> V_207 &&
! F_186 ( V_11 , V_151 , 3 ) ) {
V_22 -> V_220 = V_195 ;
V_218 ++ ;
}
V_266 = F_189 ( V_22 -> V_16 ) ;
if ( F_134 ( V_22 ) &&
( ! F_186 ( V_11 , V_266 , 2 ) ||
! F_186 ( V_11 , V_151 , 2 ) ) ) {
V_22 -> V_220 = V_195 ;
V_218 ++ ;
}
}
return V_218 ;
}
static void F_191 ( struct V_10 * V_11 )
{
unsigned long V_266 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
switch ( V_22 -> V_220 ) {
case V_221 :
continue;
case V_31 :
V_266 = F_189 ( V_22 -> V_16 ) ;
if ( V_11 -> V_65 != V_22 ||
( ! V_11 -> V_65 &&
F_186 ( V_11 , V_266 , 1 ) ) ) {
V_22 -> V_30 = V_31 ;
if ( V_11 -> V_207 ) {
F_69 (
V_11 -> V_207 ) ;
V_11 -> V_207 = NULL ;
}
F_65 ( L_83 ,
V_11 -> V_16 -> V_56 , V_22 -> V_16 -> V_56 ) ;
if ( ! V_11 -> V_65 ||
( V_22 == V_11 -> V_88 ) )
goto V_224;
}
continue;
case V_195 :
if ( V_22 -> V_191 < V_225 )
V_22 -> V_191 ++ ;
V_22 -> V_30 = V_195 ;
F_69 ( V_22 ) ;
F_65 ( L_68 ,
V_11 -> V_16 -> V_56 , V_22 -> V_16 -> V_56 ) ;
if ( V_22 == V_11 -> V_65 ) {
V_11 -> V_207 = NULL ;
goto V_224;
}
continue;
default:
F_113 ( L_84 ,
V_11 -> V_16 -> V_56 , V_22 -> V_220 ,
V_22 -> V_16 -> V_56 ) ;
continue;
}
V_224:
F_51 () ;
F_142 () ;
F_42 ( & V_11 -> V_69 ) ;
F_74 ( V_11 ) ;
F_43 ( & V_11 -> V_69 ) ;
F_143 () ;
}
F_18 ( V_11 ) ;
}
static void F_192 ( struct V_10 * V_11 )
{
struct V_22 * V_22 , * V_267 = NULL , * V_160 = NULL ;
struct V_24 * V_25 ;
bool V_244 = false ;
F_73 ( & V_11 -> V_69 ) ;
if ( V_11 -> V_207 && V_11 -> V_65 )
F_65 ( L_85 ,
V_11 -> V_207 -> V_16 -> V_56 ,
V_11 -> V_65 -> V_16 -> V_56 ) ;
if ( V_11 -> V_65 ) {
F_168 ( V_11 , V_11 -> V_65 ) ;
F_72 ( & V_11 -> V_69 ) ;
return;
}
F_72 ( & V_11 -> V_69 ) ;
if ( ! V_11 -> V_207 ) {
V_11 -> V_207 = F_193 ( V_11 ) ;
if ( ! V_11 -> V_207 )
return;
}
F_69 ( V_11 -> V_207 ) ;
F_12 (bond, slave, iter) {
if ( ! V_244 && ! V_267 && F_61 ( V_22 -> V_16 ) )
V_267 = V_22 ;
if ( V_244 && ! V_160 && F_61 ( V_22 -> V_16 ) )
V_160 = V_22 ;
if ( ! F_61 ( V_22 -> V_16 ) && V_22 -> V_30 == V_31 ) {
V_22 -> V_30 = V_195 ;
if ( V_22 -> V_191 < V_225 )
V_22 -> V_191 ++ ;
F_69 ( V_22 ) ;
F_65 ( L_86 ,
V_11 -> V_16 -> V_56 , V_22 -> V_16 -> V_56 ) ;
}
if ( V_22 == V_11 -> V_207 )
V_244 = true ;
}
if ( ! V_160 && V_267 )
V_160 = V_267 ;
if ( ! V_160 )
return;
V_160 -> V_30 = V_97 ;
F_70 ( V_160 ) ;
F_168 ( V_11 , V_160 ) ;
V_160 -> V_102 = V_102 ;
V_11 -> V_207 = V_160 ;
}
void F_194 ( struct V_72 * V_73 )
{
struct V_10 * V_11 = F_45 ( V_73 , struct V_10 ,
V_265 . V_73 ) ;
bool V_104 = false ;
int V_264 ;
F_73 ( & V_11 -> V_107 ) ;
V_264 = F_127 ( V_11 -> V_29 . V_150 ) ;
if ( ! F_19 ( V_11 ) )
goto V_227;
V_104 = F_62 ( V_11 ) ;
if ( F_190 ( V_11 ) ) {
F_72 ( & V_11 -> V_107 ) ;
if ( ! F_38 () ) {
F_73 ( & V_11 -> V_107 ) ;
V_264 = 1 ;
V_104 = false ;
goto V_227;
}
F_73 ( & V_11 -> V_107 ) ;
F_191 ( V_11 ) ;
F_72 ( & V_11 -> V_107 ) ;
F_41 () ;
F_73 ( & V_11 -> V_107 ) ;
}
F_192 ( V_11 ) ;
V_227:
if ( V_11 -> V_29 . V_150 )
F_39 ( V_11 -> V_66 , & V_11 -> V_265 , V_264 ) ;
F_72 ( & V_11 -> V_107 ) ;
if ( V_104 ) {
if ( ! F_38 () )
return;
F_40 ( V_109 , V_11 -> V_16 ) ;
F_41 () ;
}
}
static int F_195 ( struct V_10 * V_11 )
{
F_196 ( V_11 ) ;
F_197 ( V_11 ) ;
F_198 ( V_11 ) ;
return V_268 ;
}
static int F_199 ( unsigned long V_269 ,
struct V_14 * V_19 )
{
struct V_10 * V_270 = F_11 ( V_19 ) ;
switch ( V_269 ) {
case V_271 :
return F_195 ( V_270 ) ;
case V_272 :
F_196 ( V_270 ) ;
break;
case V_273 :
F_197 ( V_270 ) ;
break;
case V_109 :
if ( V_270 -> V_99 )
V_270 -> V_99 -- ;
break;
default:
break;
}
return V_268 ;
}
static int F_200 ( unsigned long V_269 ,
struct V_14 * V_15 )
{
struct V_22 * V_22 = F_201 ( V_15 ) ;
struct V_10 * V_11 ;
struct V_14 * V_19 ;
T_3 V_274 ;
T_4 V_275 ;
if ( ! V_22 )
return V_268 ;
V_19 = V_22 -> V_11 -> V_16 ;
V_11 = V_22 -> V_11 ;
switch ( V_269 ) {
case V_272 :
if ( V_19 -> type != V_171 )
F_149 ( V_19 , V_15 ) ;
else
F_148 ( V_19 , V_15 ) ;
break;
case V_276 :
case V_277 :
V_274 = V_22 -> V_35 ;
V_275 = V_22 -> V_37 ;
F_24 ( V_22 ) ;
if ( V_11 -> V_29 . V_1 == V_7 ) {
if ( V_274 != V_22 -> V_35 )
F_202 ( V_22 ) ;
if ( V_275 != V_22 -> V_37 )
F_203 ( V_22 ) ;
}
break;
case V_278 :
break;
case V_279 :
break;
case V_271 :
break;
case V_280 :
F_88 ( V_11 ) ;
break;
case V_68 :
F_40 ( V_269 , V_22 -> V_11 -> V_16 ) ;
break;
default:
break;
}
return V_268 ;
}
static int F_204 ( struct V_281 * V_282 ,
unsigned long V_269 , void * V_283 )
{
struct V_14 * V_284 = F_205 ( V_283 ) ;
F_57 ( L_87 ,
V_284 ? V_284 -> V_56 : L_88 ,
V_269 ) ;
if ( ! ( V_284 -> V_118 & V_189 ) )
return V_268 ;
if ( V_284 -> V_79 & V_285 ) {
F_57 ( L_89 ) ;
return F_199 ( V_269 , V_284 ) ;
}
if ( V_284 -> V_79 & V_157 ) {
F_57 ( L_90 ) ;
return F_200 ( V_269 , V_284 ) ;
}
return V_268 ;
}
static inline T_3 F_206 ( struct V_12 * V_13 )
{
struct V_286 * V_155 = (struct V_286 * ) V_13 -> V_155 ;
if ( F_181 ( V_13 ) >= F_207 ( struct V_286 , V_287 ) )
return V_155 -> V_156 [ 5 ] ^ V_155 -> V_288 [ 5 ] ;
return 0 ;
}
static bool F_208 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_289 * V_290 )
{
const struct V_291 * V_292 ;
const struct V_293 * V_294 ;
int V_295 , V_20 = - 1 ;
if ( V_11 -> V_29 . V_296 > V_297 )
return F_209 ( V_13 , V_290 ) ;
V_290 -> V_298 = 0 ;
V_295 = F_210 ( V_13 ) ;
if ( V_13 -> V_252 == F_166 ( V_259 ) ) {
if ( ! F_211 ( V_13 , V_295 + sizeof( * V_294 ) ) )
return false ;
V_294 = F_212 ( V_13 ) ;
V_290 -> V_299 = V_294 -> V_300 ;
V_290 -> V_243 = V_294 -> V_301 ;
V_295 += V_294 -> V_302 << 2 ;
if ( ! F_213 ( V_294 ) )
V_20 = V_294 -> V_252 ;
} else if ( V_13 -> V_252 == F_166 ( V_303 ) ) {
if ( ! F_211 ( V_13 , V_295 + sizeof( * V_292 ) ) )
return false ;
V_292 = F_214 ( V_13 ) ;
V_290 -> V_299 = ( V_304 T_8 ) F_215 ( & V_292 -> V_300 ) ;
V_290 -> V_243 = ( V_304 T_8 ) F_215 ( & V_292 -> V_301 ) ;
V_295 += sizeof( * V_292 ) ;
V_20 = V_292 -> V_305 ;
} else {
return false ;
}
if ( V_11 -> V_29 . V_296 == V_306 && V_20 >= 0 )
V_290 -> V_298 = F_216 ( V_13 , V_295 , V_20 ) ;
return true ;
}
int F_217 ( struct V_10 * V_11 , struct V_12 * V_13 , int V_307 )
{
struct V_289 V_308 ;
T_3 V_309 ;
if ( V_11 -> V_29 . V_296 == V_310 ||
! F_208 ( V_11 , V_13 , & V_308 ) )
return F_206 ( V_13 ) % V_307 ;
if ( V_11 -> V_29 . V_296 == V_297 ||
V_11 -> V_29 . V_296 == V_311 )
V_309 = F_206 ( V_13 ) ;
else
V_309 = ( V_304 T_3 ) V_308 . V_298 ;
V_309 ^= ( V_304 T_3 ) V_308 . V_243 ^ ( V_304 T_3 ) V_308 . V_299 ;
V_309 ^= ( V_309 >> 16 ) ;
V_309 ^= ( V_309 >> 8 ) ;
return V_309 % V_307 ;
}
static void F_218 ( struct V_10 * V_11 )
{
F_219 ( & V_11 -> V_67 ,
F_44 ) ;
F_219 ( & V_11 -> V_312 , V_313 ) ;
F_219 ( & V_11 -> V_226 , F_157 ) ;
if ( V_11 -> V_29 . V_1 == V_4 )
F_219 ( & V_11 -> V_265 , F_194 ) ;
else
F_219 ( & V_11 -> V_265 , F_188 ) ;
F_219 ( & V_11 -> V_314 , V_315 ) ;
}
static void F_220 ( struct V_10 * V_11 )
{
F_221 ( & V_11 -> V_226 ) ;
F_221 ( & V_11 -> V_265 ) ;
F_221 ( & V_11 -> V_312 ) ;
F_221 ( & V_11 -> V_314 ) ;
F_221 ( & V_11 -> V_67 ) ;
}
static int F_222 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_73 ( & V_11 -> V_107 ) ;
if ( F_19 ( V_11 ) ) {
F_73 ( & V_11 -> V_69 ) ;
F_12 (bond, slave, iter) {
if ( ( V_11 -> V_29 . V_1 == V_4 )
&& ( V_22 != V_11 -> V_65 ) ) {
F_69 ( V_22 ) ;
} else {
F_70 ( V_22 ) ;
}
}
F_72 ( & V_11 -> V_69 ) ;
}
F_72 ( & V_11 -> V_107 ) ;
F_218 ( V_11 ) ;
if ( F_16 ( V_11 ) ) {
if ( F_223 ( V_11 , ( V_11 -> V_29 . V_1 == V_9 ) ) )
return - V_116 ;
F_39 ( V_11 -> V_66 , & V_11 -> V_312 , 0 ) ;
}
if ( V_11 -> V_29 . V_103 )
F_39 ( V_11 -> V_66 , & V_11 -> V_226 , 0 ) ;
if ( V_11 -> V_29 . V_150 ) {
F_39 ( V_11 -> V_66 , & V_11 -> V_265 , 0 ) ;
if ( V_11 -> V_29 . V_261 )
V_11 -> F_96 = F_177 ;
}
if ( V_11 -> V_29 . V_1 == V_7 ) {
F_39 ( V_11 -> V_66 , & V_11 -> V_314 , 0 ) ;
V_11 -> F_96 = V_316 ;
F_224 ( V_11 , 1 ) ;
}
return 0 ;
}
static int F_225 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_220 ( V_11 ) ;
V_11 -> V_99 = 0 ;
if ( F_16 ( V_11 ) )
F_226 ( V_11 ) ;
V_11 -> F_96 = NULL ;
return 0 ;
}
static struct V_317 * F_227 ( struct V_14 * V_19 ,
struct V_317 * V_318 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_317 V_319 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
memset ( V_318 , 0 , sizeof( * V_318 ) ) ;
F_228 ( & V_11 -> V_107 ) ;
F_12 (bond, slave, iter) {
const struct V_317 * V_320 =
F_229 ( V_22 -> V_16 , & V_319 ) ;
V_318 -> V_321 += V_320 -> V_321 ;
V_318 -> V_322 += V_320 -> V_322 ;
V_318 -> V_323 += V_320 -> V_323 ;
V_318 -> V_324 += V_320 -> V_324 ;
V_318 -> V_325 += V_320 -> V_325 ;
V_318 -> V_326 += V_320 -> V_326 ;
V_318 -> V_327 += V_320 -> V_327 ;
V_318 -> V_328 += V_320 -> V_328 ;
V_318 -> V_329 += V_320 -> V_329 ;
V_318 -> V_330 += V_320 -> V_330 ;
V_318 -> V_331 += V_320 -> V_331 ;
V_318 -> V_332 += V_320 -> V_332 ;
V_318 -> V_333 += V_320 -> V_333 ;
V_318 -> V_334 += V_320 -> V_334 ;
V_318 -> V_335 += V_320 -> V_335 ;
V_318 -> V_336 += V_320 -> V_336 ;
V_318 -> V_337 += V_320 -> V_337 ;
V_318 -> V_338 += V_320 -> V_338 ;
V_318 -> V_339 += V_320 -> V_339 ;
V_318 -> V_340 += V_320 -> V_340 ;
V_318 -> V_341 += V_320 -> V_341 ;
}
F_230 ( & V_11 -> V_107 ) ;
return V_318 ;
}
static int F_231 ( struct V_14 * V_19 , struct V_46 * V_47 , int V_342 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_14 * V_15 = NULL ;
struct V_209 V_343 ;
struct V_209 T_9 * V_344 = NULL ;
struct V_213 V_345 ;
struct V_213 T_9 * V_346 = NULL ;
struct V_48 * V_49 = NULL ;
struct V_347 * V_347 ;
int V_26 = 0 ;
F_57 ( L_91 , V_19 -> V_56 , V_342 ) ;
switch ( V_342 ) {
case V_58 :
V_49 = F_30 ( V_47 ) ;
if ( ! V_49 )
return - V_174 ;
V_49 -> V_348 = 0 ;
case V_61 :
V_49 = F_30 ( V_47 ) ;
if ( ! V_49 )
return - V_174 ;
if ( V_49 -> V_59 == 1 ) {
V_49 -> V_62 = 0 ;
F_73 ( & V_11 -> V_107 ) ;
F_73 ( & V_11 -> V_69 ) ;
if ( F_21 ( V_11 -> V_16 ) )
V_49 -> V_62 = V_51 ;
F_72 ( & V_11 -> V_69 ) ;
F_72 ( & V_11 -> V_107 ) ;
}
return 0 ;
case V_349 :
case V_350 :
V_344 = (struct V_209 T_9 * ) V_47 -> V_351 ;
if ( F_232 ( & V_343 , V_344 , sizeof( V_209 ) ) )
return - V_352 ;
V_26 = F_151 ( V_19 , & V_343 ) ;
if ( V_26 == 0 &&
F_233 ( V_344 , & V_343 , sizeof( V_209 ) ) )
return - V_352 ;
return V_26 ;
case V_353 :
case V_354 :
V_346 = (struct V_213 T_9 * ) V_47 -> V_351 ;
if ( F_232 ( & V_345 , V_346 , sizeof( V_213 ) ) )
return - V_352 ;
V_26 = F_152 ( V_19 , & V_345 ) ;
if ( V_26 == 0 &&
F_233 ( V_346 , & V_345 , sizeof( V_213 ) ) )
return - V_352 ;
return V_26 ;
default:
break;
}
V_347 = F_170 ( V_19 ) ;
if ( ! F_234 ( V_347 -> V_355 , V_356 ) )
return - V_167 ;
V_15 = F_235 ( V_347 , V_47 -> V_357 ) ;
F_57 ( L_92 , V_15 ) ;
if ( ! V_15 )
V_26 = - V_214 ;
else {
F_57 ( L_93 , V_15 -> V_56 ) ;
switch ( V_342 ) {
case V_358 :
case V_359 :
V_26 = F_110 ( V_19 , V_15 ) ;
break;
case V_360 :
case V_361 :
V_26 = F_148 ( V_19 , V_15 ) ;
break;
case V_362 :
case V_363 :
F_56 ( V_19 , V_15 ) ;
V_26 = 0 ;
break;
case V_364 :
case V_365 :
V_26 = F_236 ( V_11 , V_15 ) ;
break;
default:
V_26 = - V_177 ;
}
F_237 ( V_15 ) ;
}
return V_26 ;
}
static void F_238 ( struct V_14 * V_19 , int V_366 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_366 & V_80 )
F_32 ( V_11 ,
V_19 -> V_79 & V_80 ? 1 : - 1 ) ;
if ( V_366 & V_81 )
F_35 ( V_11 ,
V_19 -> V_79 & V_81 ? 1 : - 1 ) ;
}
static void F_239 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_160 () ;
if ( F_33 ( V_11 -> V_29 . V_1 ) ) {
V_22 = F_240 ( V_11 -> V_65 ) ;
if ( V_22 ) {
F_53 ( V_22 -> V_16 , V_19 ) ;
F_54 ( V_22 -> V_16 , V_19 ) ;
}
} else {
F_241 (bond, slave, iter) {
F_123 ( V_22 -> V_16 , V_19 ) ;
F_122 ( V_22 -> V_16 , V_19 ) ;
}
}
F_162 () ;
}
static int F_242 ( struct V_367 * V_368 )
{
struct V_10 * V_11 = F_11 ( V_368 -> V_16 ) ;
const struct V_43 * V_44 ;
struct V_369 V_370 ;
struct V_22 * V_22 ;
int V_147 ;
V_22 = F_193 ( V_11 ) ;
if ( ! V_22 )
return 0 ;
V_44 = V_22 -> V_16 -> V_45 ;
if ( ! V_44 -> V_371 )
return 0 ;
V_370 . V_372 = NULL ;
V_370 . V_373 = NULL ;
V_147 = V_44 -> V_371 ( V_22 -> V_16 , & V_370 ) ;
if ( V_147 )
return V_147 ;
V_368 -> V_370 -> V_373 = V_370 . V_373 ;
if ( ! V_370 . V_372 )
return 0 ;
return V_370 . V_372 ( V_368 ) ;
}
static int F_243 ( struct V_14 * V_16 ,
struct V_369 * V_370 )
{
if ( V_370 -> V_16 == V_16 )
V_370 -> V_372 = F_242 ;
return 0 ;
}
static int F_244 ( struct V_14 * V_19 , int V_374 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
F_57 ( L_94 , V_11 ,
( V_19 ? V_19 -> V_56 : L_88 ) , V_374 ) ;
F_12 (bond, slave, iter) {
F_57 ( L_95 ,
V_22 ,
V_22 -> V_16 -> V_45 -> V_375 ) ;
V_26 = F_118 ( V_22 -> V_16 , V_374 ) ;
if ( V_26 ) {
F_57 ( L_96 , V_26 , V_22 -> V_16 -> V_56 ) ;
goto V_27;
}
}
V_19 -> V_182 = V_374 ;
return 0 ;
V_27:
F_12 (bond, rollback_slave, iter) {
int V_376 ;
if ( V_23 == V_22 )
break;
V_376 = F_118 ( V_23 -> V_16 , V_19 -> V_182 ) ;
if ( V_376 ) {
F_57 ( L_97 ,
V_376 , V_23 -> V_16 -> V_56 ) ;
}
}
return V_26 ;
}
static int F_245 ( struct V_14 * V_19 , void * V_163 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_162 * V_377 = V_163 , V_378 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
if ( V_11 -> V_29 . V_1 == V_9 )
return F_246 ( V_19 , V_163 ) ;
F_57 ( L_98 ,
V_11 , V_19 ? V_19 -> V_56 : L_88 ) ;
if ( V_11 -> V_29 . V_105 )
return 0 ;
if ( ! F_247 ( V_377 -> V_185 ) )
return - V_379 ;
F_12 (bond, slave, iter) {
const struct V_43 * V_44 = V_22 -> V_16 -> V_45 ;
F_57 ( L_99 , V_22 , V_22 -> V_16 -> V_56 ) ;
if ( V_44 -> V_175 == NULL ) {
V_26 = - V_177 ;
F_57 ( L_100 , V_22 -> V_16 -> V_56 ) ;
goto V_27;
}
V_26 = F_119 ( V_22 -> V_16 , V_163 ) ;
if ( V_26 ) {
F_57 ( L_96 , V_26 , V_22 -> V_16 -> V_56 ) ;
goto V_27;
}
}
memcpy ( V_19 -> V_83 , V_377 -> V_185 , V_19 -> V_82 ) ;
return 0 ;
V_27:
memcpy ( V_378 . V_185 , V_19 -> V_83 , V_19 -> V_82 ) ;
V_378 . V_186 = V_19 -> type ;
F_12 (bond, rollback_slave, iter) {
int V_376 ;
if ( V_23 == V_22 )
break;
V_376 = F_119 ( V_23 -> V_16 , & V_378 ) ;
if ( V_376 ) {
F_57 ( L_97 ,
V_376 , V_23 -> V_16 -> V_56 ) ;
}
}
return V_26 ;
}
void F_248 ( struct V_10 * V_11 , struct V_12 * V_13 , int V_215 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_165 = V_215 ;
F_241 (bond, slave, iter) {
if ( -- V_165 < 0 ) {
if ( F_249 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
}
V_165 = V_215 ;
F_241 (bond, slave, iter) {
if ( -- V_165 < 0 )
break;
if ( F_249 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
F_103 ( V_13 ) ;
}
static T_3 F_250 ( struct V_10 * V_11 )
{
int V_380 = V_11 -> V_29 . V_380 ;
T_3 V_215 ;
switch ( V_380 ) {
case 0 :
V_215 = F_251 () ;
break;
case 1 :
V_215 = V_11 -> V_381 ;
break;
default:
V_215 = F_252 ( V_11 -> V_381 ,
V_380 ) ;
break;
}
V_11 -> V_381 ++ ;
return V_215 ;
}
static int F_253 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_293 * V_294 = F_212 ( V_13 ) ;
struct V_22 * V_22 ;
T_3 V_215 ;
if ( V_294 -> V_252 == V_382 && V_13 -> V_252 == F_166 ( V_259 ) ) {
V_22 = F_240 ( V_11 -> V_65 ) ;
if ( V_22 && F_249 ( V_22 ) )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_248 ( V_11 , V_13 , 0 ) ;
} else {
V_215 = F_250 ( V_11 ) ;
F_248 ( V_11 , V_13 , V_215 % V_11 -> V_202 ) ;
}
return V_383 ;
}
static int F_254 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 ;
V_22 = F_240 ( V_11 -> V_65 ) ;
if ( V_22 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_103 ( V_13 ) ;
return V_383 ;
}
static int F_255 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_248 ( V_11 , V_13 , F_217 ( V_11 , V_13 , V_11 -> V_202 ) ) ;
return V_383 ;
}
static int F_256 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
F_241 (bond, slave, iter) {
if ( F_257 ( V_11 , V_22 ) )
break;
if ( F_61 ( V_22 -> V_16 ) && V_22 -> V_30 == V_31 ) {
struct V_12 * V_384 = F_258 ( V_13 , V_115 ) ;
if ( ! V_384 ) {
F_113 ( L_101 ,
V_19 -> V_56 ) ;
continue;
}
F_2 ( V_11 , V_384 , V_22 -> V_16 ) ;
}
}
if ( V_22 && F_61 ( V_22 -> V_16 ) && V_22 -> V_30 == V_31 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_103 ( V_13 ) ;
return V_383 ;
}
static inline int F_259 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_22 * V_22 = NULL ;
struct V_22 * V_385 ;
struct V_24 * V_25 ;
int V_26 = 1 ;
if ( ! V_13 -> V_17 )
return 1 ;
F_241 (bond, check_slave, iter) {
if ( V_385 -> V_180 == V_13 -> V_17 ) {
V_22 = V_385 ;
break;
}
}
if ( V_22 && V_22 -> V_180 && F_61 ( V_22 -> V_16 ) &&
( V_22 -> V_30 == V_31 ) ) {
V_26 = F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
}
return V_26 ;
}
static T_2 F_260 ( struct V_14 * V_16 , struct V_12 * V_13 ,
void * V_386 )
{
T_2 V_387 = F_261 ( V_13 ) ? F_262 ( V_13 ) : 0 ;
F_4 ( V_13 ) -> V_18 = V_13 -> V_17 ;
if ( F_5 ( V_387 >= V_16 -> V_388 ) ) {
do {
V_387 -= V_16 -> V_388 ;
} while ( V_387 >= V_16 -> V_388 );
}
return V_387 ;
}
static T_10 F_263 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
if ( F_264 ( V_11 -> V_29 . V_1 ) ) {
if ( ! F_259 ( V_11 , V_13 ) )
return V_383 ;
}
switch ( V_11 -> V_29 . V_1 ) {
case V_3 :
return F_253 ( V_13 , V_16 ) ;
case V_4 :
return F_254 ( V_13 , V_16 ) ;
case V_5 :
return F_255 ( V_13 , V_16 ) ;
case V_6 :
return F_256 ( V_13 , V_16 ) ;
case V_7 :
return F_265 ( V_13 , V_16 ) ;
case V_9 :
case V_8 :
return F_266 ( V_13 , V_16 ) ;
default:
F_113 ( L_102 ,
V_16 -> V_56 , V_11 -> V_29 . V_1 ) ;
F_267 ( 1 ) ;
F_103 ( V_13 ) ;
return V_383 ;
}
}
static T_10 F_268 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
T_10 V_147 = V_383 ;
if ( F_269 ( V_16 ) )
return V_389 ;
F_160 () ;
if ( F_19 ( V_11 ) )
V_147 = F_263 ( V_13 , V_16 ) ;
else
F_103 ( V_13 ) ;
F_162 () ;
return V_147 ;
}
static int F_270 ( struct V_14 * V_19 ,
struct V_32 * V_33 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
unsigned long V_35 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
V_33 -> V_37 = V_38 ;
V_33 -> V_390 = V_391 ;
F_73 ( & V_11 -> V_107 ) ;
F_12 (bond, slave, iter) {
if ( F_271 ( V_22 ) ) {
if ( V_22 -> V_35 != V_36 )
V_35 += V_22 -> V_35 ;
if ( V_33 -> V_37 == V_38 &&
V_22 -> V_37 != V_38 )
V_33 -> V_37 = V_22 -> V_37 ;
}
}
F_272 ( V_33 , V_35 ? : V_36 ) ;
F_72 ( & V_11 -> V_107 ) ;
return 0 ;
}
static void F_273 ( struct V_14 * V_19 ,
struct V_392 * V_393 )
{
F_274 ( V_393 -> V_394 , V_395 , sizeof( V_393 -> V_394 ) ) ;
F_274 ( V_393 -> V_396 , V_397 , sizeof( V_393 -> V_396 ) ) ;
snprintf ( V_393 -> V_398 , sizeof( V_393 -> V_398 ) , L_103 ,
V_399 ) ;
}
static void F_275 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_11 -> V_66 )
F_276 ( V_11 -> V_66 ) ;
F_277 ( V_19 ) ;
}
void F_278 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_279 ( & V_11 -> V_107 ) ;
F_279 ( & V_11 -> V_69 ) ;
V_11 -> V_29 = V_400 ;
V_11 -> V_16 = V_19 ;
F_117 ( V_19 ) ;
V_19 -> V_45 = & V_401 ;
V_19 -> V_52 = & V_402 ;
V_19 -> V_403 = F_275 ;
F_280 ( V_19 , & V_404 ) ;
V_19 -> V_405 = 0 ;
V_19 -> V_79 |= V_285 | V_406 ;
V_19 -> V_118 |= V_189 ;
V_19 -> V_118 &= ~ ( V_130 | V_172 ) ;
V_19 -> V_124 |= V_126 ;
V_19 -> V_124 |= V_407 ;
V_19 -> V_408 = V_132 |
V_409 |
V_410 |
V_411 ;
V_19 -> V_408 &= ~ ( V_412 & ~ V_413 ) ;
V_19 -> V_124 |= V_19 -> V_408 ;
}
static void F_281 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_83 ( V_19 ) ;
F_12 (bond, slave, iter)
F_140 ( V_19 , V_22 -> V_16 , true ) ;
F_65 ( L_104 , V_19 -> V_56 ) ;
F_282 ( & V_11 -> V_414 ) ;
F_283 ( V_11 ) ;
}
int F_284 ( const char * V_415 , const struct V_416 * V_417 )
{
int V_418 = - 1 , V_165 , V_112 ;
char * V_419 , V_420 [ V_421 + 1 ] = { 0 , } ;
for ( V_419 = ( char * ) V_415 ; * V_419 ; V_419 ++ )
if ( ! ( isdigit ( * V_419 ) || isspace ( * V_419 ) ) )
break;
if ( * V_419 )
V_112 = sscanf ( V_415 , L_105 , V_420 ) ;
else
V_112 = sscanf ( V_415 , L_103 , & V_418 ) ;
if ( ! V_112 )
return - 1 ;
for ( V_165 = 0 ; V_417 [ V_165 ] . V_422 ; V_165 ++ ) {
if ( V_418 == V_417 [ V_165 ] . V_1 )
return V_417 [ V_165 ] . V_1 ;
if ( strcmp ( V_420 , V_417 [ V_165 ] . V_422 ) == 0 )
return V_417 [ V_165 ] . V_1 ;
}
return - 1 ;
}
static int F_285 ( struct V_423 * V_29 )
{
int V_424 , V_425 , V_426 , V_165 ;
int V_427 ;
if ( V_1 ) {
V_211 = F_284 ( V_1 , V_428 ) ;
if ( V_211 == - 1 ) {
F_113 ( L_106 ,
V_1 == NULL ? L_11 : V_1 ) ;
return - V_174 ;
}
}
if ( V_429 ) {
if ( ( V_211 != V_5 ) &&
( V_211 != V_7 ) ) {
F_65 ( L_107 ,
F_1 ( V_211 ) ) ;
} else {
V_430 = F_284 ( V_429 ,
V_431 ) ;
if ( V_430 == - 1 ) {
F_113 ( L_108 ,
V_429 == NULL ? L_11 :
V_429 ) ;
return - V_174 ;
}
}
}
if ( V_432 ) {
if ( V_211 != V_7 ) {
F_65 ( L_109 ,
F_1 ( V_211 ) ) ;
} else {
V_433 = F_284 ( V_432 , V_434 ) ;
if ( V_433 == - 1 ) {
F_113 ( L_110 ,
V_432 == NULL ? L_11 : V_432 ) ;
return - V_174 ;
}
}
}
if ( V_435 ) {
V_29 -> V_435 = F_284 ( V_435 , V_436 ) ;
if ( V_29 -> V_435 == - 1 ) {
F_113 ( L_111 ,
V_435 == NULL ? L_11 : V_435 ) ;
return - V_174 ;
}
if ( V_211 != V_7 ) {
F_111 ( L_112 ) ;
}
} else {
V_29 -> V_435 = V_437 ;
}
if ( V_438 < 0 ) {
F_111 ( L_113 ,
V_438 , 0 , V_439 , V_440 ) ;
V_438 = V_440 ;
}
if ( V_103 < 0 ) {
F_111 ( L_114 ,
V_103 , V_439 , V_441 ) ;
V_103 = V_441 ;
}
if ( V_96 < 0 ) {
F_111 ( L_115 ,
V_96 , V_439 ) ;
V_96 = 0 ;
}
if ( V_223 < 0 ) {
F_111 ( L_116 ,
V_223 , V_439 ) ;
V_223 = 0 ;
}
if ( ( V_50 != 0 ) && ( V_50 != 1 ) ) {
F_111 ( L_117 ,
V_50 ) ;
V_50 = 1 ;
}
if ( V_106 < 0 || V_106 > 255 ) {
F_111 ( L_118 ,
V_106 ) ;
V_106 = 1 ;
}
if ( V_211 == V_7 ) {
if ( ! V_103 ) {
F_111 ( L_119 ) ;
F_111 ( L_120 ) ;
V_103 = V_442 ;
}
}
if ( V_443 < 1 || V_443 > 255 ) {
F_111 ( L_121
L_122 ,
V_443 , V_444 ) ;
V_443 = V_444 ;
}
if ( ( V_445 != 0 ) && ( V_445 != 1 ) ) {
F_111 ( L_123
L_124
L_125 , V_445 ) ;
V_445 = 0 ;
}
if ( V_110 < 0 || V_110 > 255 ) {
F_111 ( L_126
L_127 ,
V_110 , V_446 ) ;
V_110 = V_446 ;
}
if ( V_380 < 0 || V_380 > V_447 ) {
F_145 ( L_128 ,
V_380 , V_447 ) ;
V_380 = 1 ;
}
if ( ( V_211 == V_8 ) ||
( V_211 == V_9 ) ) {
if ( ! V_103 ) {
F_111 ( L_129 ) ;
F_111 ( L_120 ) ;
V_103 = V_442 ;
}
}
if ( V_211 == V_9 ) {
F_286 ( L_130 ,
V_96 ) ;
}
if ( ! V_103 ) {
if ( V_96 || V_223 ) {
F_111 ( L_131 ,
V_96 , V_223 ) ;
}
} else {
if ( V_150 ) {
F_111 ( L_132 ,
V_103 , V_150 ) ;
V_150 = 0 ;
}
if ( ( V_96 % V_103 ) != 0 ) {
F_111 ( L_133 ,
V_96 , V_103 ,
( V_96 / V_103 ) * V_103 ) ;
}
V_96 /= V_103 ;
if ( ( V_223 % V_103 ) != 0 ) {
F_111 ( L_134 ,
V_223 , V_103 ,
( V_223 / V_103 ) * V_103 ) ;
}
V_223 /= V_103 ;
}
if ( V_150 < 0 ) {
F_111 ( L_135 ,
V_150 , V_439 , V_448 ) ;
V_150 = V_448 ;
}
for ( V_449 = 0 , V_165 = 0 ;
( V_449 < V_193 ) && V_450 [ V_165 ] ; V_165 ++ ) {
T_8 V_228 ;
if ( ! F_287 ( V_450 [ V_165 ] , - 1 , ( T_4 * ) & V_228 , - 1 , NULL ) ||
F_288 ( V_228 ) ) {
F_111 ( L_136 ,
V_450 [ V_165 ] ) ;
V_150 = 0 ;
} else {
if ( F_176 ( V_451 , V_228 ) == - 1 )
V_451 [ V_449 ++ ] = V_228 ;
else
F_111 ( L_137 ,
& V_228 ) ;
}
}
if ( V_150 && ! V_449 ) {
F_111 ( L_138 ,
V_150 ) ;
V_150 = 0 ;
}
if ( V_261 ) {
if ( V_211 != V_4 ) {
F_113 ( L_139 ) ;
return - V_174 ;
}
if ( ! V_150 ) {
F_113 ( L_140 ) ;
return - V_174 ;
}
V_424 = F_284 ( V_261 ,
V_452 ) ;
if ( V_424 == - 1 ) {
F_113 ( L_141 ,
V_261 == NULL ? L_11 : V_261 ) ;
return - V_174 ;
}
} else
V_424 = 0 ;
V_427 = 0 ;
if ( V_453 ) {
V_427 = F_284 ( V_453 ,
V_454 ) ;
if ( V_427 == - 1 ) {
F_113 ( L_142 ,
V_453 ) ;
V_427 = 0 ;
}
}
if ( V_103 ) {
F_65 ( L_143 , V_103 ) ;
} else if ( V_150 ) {
F_65 ( L_144 ,
V_150 ,
V_452 [ V_424 ] . V_422 ,
V_449 ) ;
for ( V_165 = 0 ; V_165 < V_449 ; V_165 ++ )
F_65 ( L_145 , V_450 [ V_165 ] ) ;
F_65 ( L_146 ) ;
} else if ( V_438 ) {
F_57 ( L_147 ) ;
}
if ( V_196 && ! F_33 ( V_211 ) ) {
F_111 ( L_148 ,
V_196 , F_1 ( V_211 ) ) ;
V_196 = NULL ;
}
if ( V_196 && V_91 ) {
V_426 = F_284 ( V_91 ,
V_455 ) ;
if ( V_426 == - 1 ) {
F_113 ( L_149 ,
V_91 ==
NULL ? L_11 : V_91 ) ;
return - V_174 ;
}
} else {
V_426 = V_456 ;
}
if ( V_105 ) {
V_425 = F_284 ( V_105 ,
V_457 ) ;
if ( V_425 == - 1 ) {
F_113 ( L_150 ,
V_261 == NULL ? L_11 : V_261 ) ;
return - V_174 ;
}
if ( V_211 != V_4 )
F_111 ( L_151 ) ;
} else {
V_425 = V_458 ;
}
V_29 -> V_1 = V_211 ;
V_29 -> V_296 = V_430 ;
V_29 -> V_103 = V_103 ;
V_29 -> V_106 = V_106 ;
V_29 -> V_150 = V_150 ;
V_29 -> V_261 = V_424 ;
V_29 -> V_453 = V_427 ;
V_29 -> V_96 = V_96 ;
V_29 -> V_223 = V_223 ;
V_29 -> V_50 = V_50 ;
V_29 -> V_433 = V_433 ;
V_29 -> V_196 [ 0 ] = 0 ;
V_29 -> V_91 = V_426 ;
V_29 -> V_105 = V_425 ;
V_29 -> V_443 = V_443 ;
V_29 -> V_445 = V_445 ;
V_29 -> V_110 = V_110 ;
V_29 -> V_459 = V_459 ;
V_29 -> V_460 = V_461 ;
if ( V_380 > 1 )
V_29 -> V_380 = F_289 ( V_380 ) ;
else
V_29 -> V_380 = V_380 ;
if ( V_196 ) {
strncpy ( V_29 -> V_196 , V_196 , V_57 ) ;
V_29 -> V_196 [ V_57 - 1 ] = 0 ;
}
memcpy ( V_29 -> V_241 , V_451 , sizeof( V_451 ) ) ;
return 0 ;
}
static void F_290 ( struct V_14 * V_16 ,
struct V_462 * V_387 ,
void * V_463 )
{
F_291 ( & V_387 -> V_464 ,
& V_465 ) ;
}
static void F_292 ( struct V_14 * V_16 )
{
F_291 ( & V_16 -> V_466 ,
& V_467 ) ;
F_293 ( V_16 , F_290 , NULL ) ;
V_16 -> V_468 = & V_469 ;
}
static int F_294 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_470 * V_471 = F_295 ( F_170 ( V_19 ) , V_472 ) ;
struct V_473 * V_474 = & ( F_296 ( V_11 ) ) ;
F_57 ( L_152 , V_19 -> V_56 ) ;
F_297 ( & ( V_474 -> V_475 ) ) ;
F_297 ( & ( V_474 -> V_476 ) ) ;
V_11 -> V_66 = F_298 ( V_19 -> V_56 ) ;
if ( ! V_11 -> V_66 )
return - V_116 ;
F_292 ( V_19 ) ;
F_299 ( & V_11 -> V_414 , & V_471 -> V_477 ) ;
F_300 ( V_11 ) ;
F_301 ( V_11 ) ;
if ( F_302 ( V_19 -> V_83 ) &&
V_19 -> V_84 == V_478 )
F_139 ( V_19 ) ;
return 0 ;
}
unsigned int F_303 ( void )
{
return V_443 ;
}
int F_304 ( struct V_347 * V_347 , const char * V_56 )
{
struct V_14 * V_19 ;
int V_26 ;
F_305 () ;
V_19 = F_306 ( sizeof( struct V_10 ) ,
V_56 ? V_56 : L_153 ,
F_278 , V_443 ) ;
if ( ! V_19 ) {
F_113 ( L_154 , V_56 ) ;
F_41 () ;
return - V_116 ;
}
F_307 ( V_19 , V_347 ) ;
V_19 -> V_479 = & V_480 ;
V_26 = F_308 ( V_19 ) ;
F_23 ( V_19 ) ;
F_41 () ;
if ( V_26 < 0 )
F_275 ( V_19 ) ;
return V_26 ;
}
static int T_11 F_309 ( struct V_347 * V_347 )
{
struct V_470 * V_471 = F_295 ( V_347 , V_472 ) ;
V_471 -> V_347 = V_347 ;
F_310 ( & V_471 -> V_477 ) ;
F_311 ( V_471 ) ;
F_312 ( V_471 ) ;
return 0 ;
}
static void T_12 F_313 ( struct V_347 * V_347 )
{
struct V_470 * V_471 = F_295 ( V_347 , V_472 ) ;
struct V_10 * V_11 , * V_481 ;
F_314 ( V_482 ) ;
F_315 ( V_471 ) ;
F_316 ( V_471 ) ;
F_305 () ;
F_317 (bond, tmp_bond, &bn->dev_list, bond_list)
F_318 ( V_11 -> V_16 , & V_482 ) ;
F_319 ( & V_482 ) ;
F_41 () ;
}
static int T_13 F_320 ( void )
{
int V_165 ;
int V_26 ;
F_65 ( L_155 , V_483 ) ;
V_26 = F_285 ( & V_400 ) ;
if ( V_26 )
goto V_117;
V_26 = F_321 ( & V_484 ) ;
if ( V_26 )
goto V_117;
V_26 = F_322 () ;
if ( V_26 )
goto V_485;
F_323 () ;
for ( V_165 = 0 ; V_165 < V_438 ; V_165 ++ ) {
V_26 = F_304 ( & V_486 , NULL ) ;
if ( V_26 )
goto V_64;
}
F_324 ( & V_487 ) ;
V_117:
return V_26 ;
V_64:
F_325 () ;
V_485:
F_326 ( & V_484 ) ;
goto V_117;
}
static void T_14 F_327 ( void )
{
F_328 ( & V_487 ) ;
F_329 () ;
F_325 () ;
F_326 ( & V_484 ) ;
#ifdef F_132
F_330 ( F_331 ( & V_488 ) ) ;
#endif
}
