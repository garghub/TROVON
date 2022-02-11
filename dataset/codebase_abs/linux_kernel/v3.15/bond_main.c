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
void F_2 ( struct V_10 * V_11 , struct V_12 * V_13 ,
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
const char * F_27 ( T_4 V_30 )
{
switch ( V_30 ) {
case V_31 :
return L_9 ;
case V_42 :
return L_10 ;
case V_43 :
return L_11 ;
case V_44 :
return L_12 ;
default:
return L_8 ;
}
}
static int F_28 ( struct V_10 * V_11 ,
struct V_14 * V_15 , int V_45 )
{
const struct V_46 * V_47 = V_15 -> V_48 ;
int (* F_29)( struct V_14 * , struct V_49 * , int );
struct V_49 V_50 ;
struct V_51 * V_52 ;
if ( ! V_45 && ! F_30 ( V_15 ) )
return 0 ;
if ( V_11 -> V_29 . V_53 )
return F_21 ( V_15 ) ? V_54 : 0 ;
if ( V_15 -> V_55 -> V_56 )
return V_15 -> V_55 -> V_56 ( V_15 ) ?
V_54 : 0 ;
F_29 = V_47 -> V_57 ;
if ( F_29 ) {
strncpy ( V_50 . V_58 , V_15 -> V_59 , V_60 ) ;
V_52 = F_31 ( & V_50 ) ;
if ( F_32 ( V_15 , & V_50 , V_61 ) == 0 ) {
V_52 -> V_62 = V_63 ;
if ( F_32 ( V_15 , & V_50 , V_64 ) == 0 )
return V_52 -> V_65 & V_54 ;
}
}
return V_45 ? - 1 : V_54 ;
}
static int F_33 ( struct V_10 * V_11 , int V_66 )
{
struct V_24 * V_25 ;
int V_67 = 0 ;
if ( F_34 ( V_11 -> V_29 . V_1 ) ) {
if ( V_11 -> V_68 ) {
V_67 = F_35 ( V_11 -> V_68 -> V_16 ,
V_66 ) ;
}
} else {
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
V_67 = F_35 ( V_22 -> V_16 , V_66 ) ;
if ( V_67 )
return V_67 ;
}
}
return V_67 ;
}
static int F_36 ( struct V_10 * V_11 , int V_66 )
{
struct V_24 * V_25 ;
int V_67 = 0 ;
if ( F_34 ( V_11 -> V_29 . V_1 ) ) {
if ( V_11 -> V_68 ) {
V_67 = F_37 ( V_11 -> V_68 -> V_16 ,
V_66 ) ;
}
} else {
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
V_67 = F_37 ( V_22 -> V_16 , V_66 ) ;
if ( V_67 )
return V_67 ;
}
}
return V_67 ;
}
static void F_38 ( struct V_69 * V_70 )
{
struct V_10 * V_11 = F_39 ( V_70 , struct V_10 ,
V_71 . V_70 ) ;
if ( ! F_40 () ) {
F_41 ( V_11 -> V_72 , & V_11 -> V_71 , 1 ) ;
return;
}
F_42 ( V_73 , V_11 -> V_16 ) ;
if ( V_11 -> V_74 > 1 ) {
V_11 -> V_74 -- ;
F_41 ( V_11 -> V_72 , & V_11 -> V_71 , V_75 / 5 ) ;
}
F_43 () ;
}
static void F_44 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_45 ( V_15 , V_19 ) ;
F_46 ( V_15 , V_19 ) ;
if ( V_11 -> V_29 . V_1 == V_7 ) {
T_5 V_76 [ V_77 ] = V_78 ;
F_47 ( V_15 , V_76 ) ;
}
}
static void F_48 ( struct V_10 * V_11 , struct V_22 * V_79 ,
struct V_22 * V_80 )
{
F_49 () ;
if ( V_80 ) {
if ( V_11 -> V_16 -> V_81 & V_82 )
F_35 ( V_80 -> V_16 , - 1 ) ;
if ( V_11 -> V_16 -> V_81 & V_83 )
F_37 ( V_80 -> V_16 , - 1 ) ;
F_44 ( V_11 -> V_16 , V_80 -> V_16 ) ;
}
if ( V_79 ) {
if ( V_11 -> V_16 -> V_81 & V_82 )
F_35 ( V_79 -> V_16 , 1 ) ;
if ( V_11 -> V_16 -> V_81 & V_83 )
F_37 ( V_79 -> V_16 , 1 ) ;
F_50 ( V_11 -> V_16 ) ;
F_51 ( V_79 -> V_16 , V_11 -> V_16 ) ;
F_52 ( V_79 -> V_16 , V_11 -> V_16 ) ;
F_53 ( V_11 -> V_16 ) ;
}
}
static void F_54 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
F_55 ( L_13 ,
V_19 , V_15 , V_15 -> V_84 ) ;
memcpy ( V_19 -> V_85 , V_15 -> V_85 , V_15 -> V_84 ) ;
V_19 -> V_86 = V_87 ;
F_42 ( V_88 , V_19 ) ;
}
static void F_56 ( struct V_10 * V_11 ,
struct V_22 * V_79 ,
struct V_22 * V_80 )
__releases( &bond->curr_slave_lock
static bool F_57 ( struct V_10 * V_11 )
{
struct V_22 * V_89 = V_11 -> V_90 ;
struct V_22 * V_91 = V_11 -> V_68 ;
if ( ! V_89 || ! V_91 || V_91 -> V_30 != V_31 )
return true ;
if ( V_11 -> V_92 ) {
V_11 -> V_92 = false ;
return true ;
}
if ( V_11 -> V_29 . V_93 == V_94 &&
( V_89 -> V_35 < V_91 -> V_35 ||
( V_89 -> V_35 == V_91 -> V_35 && V_89 -> V_37 <= V_91 -> V_37 ) ) )
return false ;
if ( V_11 -> V_29 . V_93 == V_95 )
return false ;
return true ;
}
static struct V_22 * F_58 ( struct V_10 * V_11 )
{
struct V_22 * V_22 , * V_96 = NULL ;
struct V_24 * V_25 ;
int V_97 = V_11 -> V_29 . V_98 ;
if ( V_11 -> V_90 && V_11 -> V_90 -> V_30 == V_31 &&
F_57 ( V_11 ) )
return V_11 -> V_90 ;
F_12 (bond, slave, iter) {
if ( V_22 -> V_30 == V_31 )
return V_22 ;
if ( V_22 -> V_30 == V_44 && F_59 ( V_22 -> V_16 ) &&
V_22 -> V_99 < V_97 ) {
V_97 = V_22 -> V_99 ;
V_96 = V_22 ;
}
}
return V_96 ;
}
static bool F_60 ( struct V_10 * V_11 )
{
struct V_22 * V_22 ;
F_61 () ;
V_22 = F_62 ( V_11 -> V_68 ) ;
F_63 () ;
F_55 ( L_14 ,
V_11 -> V_16 -> V_59 , V_22 ? V_22 -> V_16 -> V_59 : L_15 ) ;
if ( ! V_22 || ! V_11 -> V_100 ||
F_64 ( V_101 , & V_22 -> V_16 -> V_102 ) )
return false ;
return true ;
}
void F_65 ( struct V_10 * V_11 , struct V_22 * V_79 )
{
struct V_22 * V_80 = V_11 -> V_68 ;
if ( V_80 == V_79 )
return;
if ( V_79 ) {
V_79 -> V_103 = V_104 ;
if ( V_79 -> V_30 == V_44 ) {
if ( F_34 ( V_11 -> V_29 . V_1 ) ) {
F_66 ( L_16 ,
V_11 -> V_16 -> V_59 , V_79 -> V_16 -> V_59 ,
( V_11 -> V_29 . V_98 - V_79 -> V_99 ) * V_11 -> V_29 . V_105 ) ;
}
V_79 -> V_99 = 0 ;
V_79 -> V_30 = V_31 ;
if ( V_11 -> V_29 . V_1 == V_7 )
F_67 ( V_79 , V_31 ) ;
if ( F_16 ( V_11 ) )
F_68 ( V_11 , V_79 , V_31 ) ;
} else {
if ( F_34 ( V_11 -> V_29 . V_1 ) ) {
F_66 ( L_17 ,
V_11 -> V_16 -> V_59 , V_79 -> V_16 -> V_59 ) ;
}
}
}
if ( F_34 ( V_11 -> V_29 . V_1 ) )
F_48 ( V_11 , V_79 , V_80 ) ;
if ( F_16 ( V_11 ) ) {
F_69 ( V_11 , V_79 ) ;
if ( V_80 )
F_70 ( V_80 ,
V_106 ) ;
if ( V_79 )
F_71 ( V_79 ,
V_106 ) ;
} else {
F_72 ( V_11 -> V_68 , V_79 ) ;
}
if ( V_11 -> V_29 . V_1 == V_4 ) {
if ( V_80 )
F_70 ( V_80 ,
V_106 ) ;
if ( V_79 ) {
bool V_107 = false ;
F_71 ( V_79 ,
V_106 ) ;
if ( V_11 -> V_29 . V_108 )
F_56 ( V_11 , V_79 ,
V_80 ) ;
if ( F_30 ( V_11 -> V_16 ) ) {
V_11 -> V_100 =
V_11 -> V_29 . V_109 ;
V_107 =
F_60 ( V_11 ) ;
}
F_73 ( & V_11 -> V_110 ) ;
F_42 ( V_111 , V_11 -> V_16 ) ;
if ( V_107 )
F_42 ( V_112 ,
V_11 -> V_16 ) ;
F_74 ( & V_11 -> V_110 ) ;
}
}
if ( F_30 ( V_11 -> V_16 ) && ( V_11 -> V_29 . V_113 > 0 ) &&
( ( F_34 ( V_11 -> V_29 . V_1 ) && V_79 ) ||
V_11 -> V_29 . V_1 == V_3 ) ) {
V_11 -> V_74 = V_11 -> V_29 . V_113 ;
F_41 ( V_11 -> V_72 , & V_11 -> V_71 , 1 ) ;
}
}
void F_75 ( struct V_10 * V_11 )
{
struct V_22 * V_114 ;
int V_115 ;
V_114 = F_58 ( V_11 ) ;
if ( V_114 != V_11 -> V_68 ) {
F_65 ( V_11 , V_114 ) ;
V_115 = F_18 ( V_11 ) ;
if ( ! V_115 )
return;
if ( F_21 ( V_11 -> V_16 ) ) {
F_66 ( L_18 ,
V_11 -> V_16 -> V_59 ) ;
} else {
F_66 ( L_19 ,
V_11 -> V_16 -> V_59 ) ;
}
}
}
static inline int F_76 ( struct V_22 * V_22 )
{
struct V_116 * V_117 ;
int V_67 = 0 ;
V_117 = F_77 ( sizeof( * V_117 ) , V_118 ) ;
V_67 = - V_119 ;
if ( ! V_117 )
goto V_120;
V_67 = F_78 ( V_117 , V_22 -> V_16 ) ;
if ( V_67 ) {
F_79 ( V_117 ) ;
goto V_120;
}
V_22 -> V_117 = V_117 ;
V_120:
return V_67 ;
}
static inline void F_80 ( struct V_22 * V_22 )
{
struct V_116 * V_117 = V_22 -> V_117 ;
if ( ! V_117 )
return;
V_22 -> V_117 = NULL ;
F_81 ( V_117 ) ;
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
if ( F_59 ( V_22 -> V_16 ) )
F_80 ( V_22 ) ;
}
static int F_84 ( struct V_14 * V_16 , struct V_121 * V_122 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_67 = 0 ;
F_12 (bond, slave, iter) {
V_67 = F_76 ( V_22 ) ;
if ( V_67 ) {
F_83 ( V_16 ) ;
break;
}
}
return V_67 ;
}
static inline int F_76 ( struct V_22 * V_22 )
{
return 0 ;
}
static inline void F_80 ( struct V_22 * V_22 )
{
}
static void F_83 ( struct V_14 * V_19 )
{
}
static T_6 F_85 ( struct V_14 * V_16 ,
T_6 V_123 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_24 * V_25 ;
T_6 V_124 ;
struct V_22 * V_22 ;
if ( ! F_19 ( V_11 ) ) {
V_123 |= V_125 ;
return V_123 ;
}
V_124 = V_123 ;
V_123 &= ~ V_126 ;
V_123 |= V_127 ;
F_12 (bond, slave, iter) {
V_123 = F_86 ( V_123 ,
V_22 -> V_16 -> V_123 ,
V_124 ) ;
}
V_123 = F_87 ( V_123 , V_124 ) ;
return V_123 ;
}
static void F_88 ( struct V_10 * V_11 )
{
unsigned int V_81 , V_128 = V_129 ;
T_6 V_130 = V_131 ;
struct V_14 * V_19 = V_11 -> V_16 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
unsigned short V_132 = V_133 ;
unsigned int V_134 = V_135 ;
T_2 V_136 = V_137 ;
if ( ! F_19 ( V_11 ) )
goto V_138;
F_12 (bond, slave, iter) {
V_130 = F_86 ( V_130 ,
V_22 -> V_16 -> V_130 , V_131 ) ;
V_128 &= V_22 -> V_16 -> V_139 ;
if ( V_22 -> V_16 -> V_140 > V_132 )
V_132 = V_22 -> V_16 -> V_140 ;
V_134 = F_89 ( V_134 , V_22 -> V_16 -> V_134 ) ;
V_136 = F_89 ( V_136 , V_22 -> V_16 -> V_136 ) ;
}
V_138:
V_19 -> V_130 = V_130 ;
V_19 -> V_140 = V_132 ;
V_19 -> V_136 = V_136 ;
F_90 ( V_19 , V_134 ) ;
V_81 = V_19 -> V_139 & ~ V_129 ;
V_19 -> V_139 = V_81 | V_128 ;
F_91 ( V_19 ) ;
}
static void F_92 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
V_19 -> V_141 = V_15 -> V_141 ;
V_19 -> type = V_15 -> type ;
V_19 -> V_140 = V_15 -> V_140 ;
V_19 -> V_84 = V_15 -> V_84 ;
memcpy ( V_19 -> V_142 , V_15 -> V_142 ,
V_15 -> V_84 ) ;
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
V_13 = F_97 ( V_13 , V_149 ) ;
if ( F_5 ( ! V_13 ) )
return V_150 ;
* V_146 = V_13 ;
V_22 = F_98 ( V_13 -> V_16 ) ;
V_11 = V_22 -> V_11 ;
F_96 = F_99 ( V_11 -> F_96 ) ;
if ( F_96 ) {
V_147 = F_96 ( V_13 , V_11 , V_22 ) ;
if ( V_147 == V_150 ) {
F_100 ( V_13 ) ;
return V_147 ;
}
}
if ( F_93 ( V_13 , V_22 , V_11 ) ) {
return V_151 ;
}
V_13 -> V_16 = V_11 -> V_16 ;
if ( V_11 -> V_29 . V_1 == V_9 &&
V_11 -> V_16 -> V_139 & V_152 &&
V_13 -> V_143 == V_153 ) {
if ( F_5 ( F_101 ( V_13 ,
V_13 -> V_154 - F_102 ( V_13 ) ) ) ) {
F_103 ( V_13 ) ;
return V_150 ;
}
F_104 ( F_105 ( V_13 ) -> V_155 , V_11 -> V_16 -> V_85 ) ;
}
return V_147 ;
}
static int F_106 ( struct V_14 * V_19 ,
struct V_14 * V_15 ,
struct V_22 * V_22 )
{
int V_67 ;
V_67 = F_107 ( V_15 , V_19 , V_22 ) ;
if ( V_67 )
return V_67 ;
V_15 -> V_81 |= V_156 ;
F_108 ( V_157 , V_15 , V_156 , V_118 ) ;
return 0 ;
}
static void F_109 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
F_110 ( V_15 , V_19 ) ;
V_15 -> V_81 &= ~ V_156 ;
F_108 ( V_157 , V_15 , V_156 , V_118 ) ;
}
int F_111 ( struct V_14 * V_19 , struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
const struct V_46 * V_47 = V_15 -> V_48 ;
struct V_22 * V_158 = NULL , * V_159 ;
struct V_160 V_161 ;
int V_162 ;
int V_26 = 0 , V_163 ;
if ( ! V_11 -> V_29 . V_53 &&
V_15 -> V_55 -> V_56 == NULL &&
V_47 -> V_57 == NULL ) {
F_112 ( L_20 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
}
if ( V_15 -> V_81 & V_156 ) {
F_55 ( L_21 ) ;
return - V_164 ;
}
if ( V_19 == V_15 ) {
F_113 ( L_22 , V_19 -> V_59 ) ;
return - V_165 ;
}
if ( V_15 -> V_123 & V_125 ) {
F_55 ( L_23 , V_15 -> V_59 ) ;
if ( F_114 ( V_19 ) ) {
F_113 ( L_24 ,
V_19 -> V_59 , V_15 -> V_59 , V_19 -> V_59 ) ;
return - V_165 ;
} else {
F_112 ( L_25 ,
V_19 -> V_59 , V_15 -> V_59 ,
V_15 -> V_59 , V_19 -> V_59 ) ;
}
} else {
F_55 ( L_26 , V_15 -> V_59 ) ;
}
if ( ( V_15 -> V_81 & V_166 ) ) {
F_113 ( L_27 ,
V_15 -> V_59 ) ;
V_26 = - V_165 ;
goto V_167;
}
if ( ! F_19 ( V_11 ) ) {
if ( V_19 -> type != V_15 -> type ) {
F_55 ( L_28 ,
V_19 -> V_59 ,
V_19 -> type , V_15 -> type ) ;
V_26 = F_42 ( V_168 ,
V_19 ) ;
V_26 = F_115 ( V_26 ) ;
if ( V_26 ) {
F_113 ( L_29 ,
V_19 -> V_59 ) ;
V_26 = - V_164 ;
goto V_167;
}
F_116 ( V_19 ) ;
F_117 ( V_19 ) ;
if ( V_15 -> type != V_169 )
F_92 ( V_19 , V_15 ) ;
else {
F_118 ( V_19 ) ;
V_19 -> V_139 &= ~ V_170 ;
}
F_42 ( V_171 ,
V_19 ) ;
}
} else if ( V_19 -> type != V_15 -> type ) {
F_113 ( L_30 ,
V_15 -> V_59 , V_15 -> type , V_19 -> type ) ;
V_26 = - V_172 ;
goto V_167;
}
if ( V_47 -> V_173 == NULL ) {
if ( ! F_19 ( V_11 ) ) {
F_112 ( L_31 ,
V_19 -> V_59 ) ;
if ( V_11 -> V_29 . V_1 == V_4 ) {
V_11 -> V_29 . V_108 = V_174 ;
F_112 ( L_32 ,
V_19 -> V_59 ) ;
}
} else if ( V_11 -> V_29 . V_108 != V_174 ) {
F_113 ( L_33 ,
V_19 -> V_59 ) ;
V_26 = - V_175 ;
goto V_167;
}
}
F_42 ( V_176 , V_15 ) ;
if ( ! F_19 ( V_11 ) &&
V_11 -> V_16 -> V_86 == V_177 )
F_54 ( V_11 -> V_16 , V_15 ) ;
V_158 = F_77 ( sizeof( struct V_22 ) , V_118 ) ;
if ( ! V_158 ) {
V_26 = - V_119 ;
goto V_167;
}
V_158 -> V_178 = 0 ;
V_158 -> V_179 = V_15 -> V_180 ;
V_26 = F_119 ( V_15 , V_11 -> V_16 -> V_180 ) ;
if ( V_26 ) {
F_55 ( L_34 , V_26 ) ;
goto V_181;
}
F_104 ( V_158 -> V_182 , V_15 -> V_85 ) ;
if ( ! V_11 -> V_29 . V_108 ||
V_11 -> V_29 . V_1 != V_4 ) {
memcpy ( V_161 . V_183 , V_19 -> V_85 , V_19 -> V_84 ) ;
V_161 . V_184 = V_15 -> type ;
V_26 = F_120 ( V_15 , & V_161 ) ;
if ( V_26 ) {
F_55 ( L_35 , V_26 ) ;
goto V_185;
}
}
V_26 = F_121 ( V_15 ) ;
if ( V_26 ) {
F_55 ( L_36 , V_15 -> V_59 ) ;
goto V_186;
}
V_158 -> V_11 = V_11 ;
V_158 -> V_16 = V_15 ;
V_15 -> V_139 |= V_187 ;
if ( F_16 ( V_11 ) ) {
V_26 = F_122 ( V_11 , V_158 ) ;
if ( V_26 )
goto V_188;
}
if ( ! F_34 ( V_11 -> V_29 . V_1 ) ) {
if ( V_19 -> V_81 & V_82 ) {
V_26 = F_35 ( V_15 , 1 ) ;
if ( V_26 )
goto V_188;
}
if ( V_19 -> V_81 & V_83 ) {
V_26 = F_37 ( V_15 , 1 ) ;
if ( V_26 )
goto V_188;
}
F_50 ( V_19 ) ;
F_123 ( V_15 , V_19 ) ;
F_124 ( V_15 , V_19 ) ;
F_53 ( V_19 ) ;
}
if ( V_11 -> V_29 . V_1 == V_7 ) {
T_5 V_76 [ V_77 ] = V_78 ;
F_125 ( V_15 , V_76 ) ;
}
V_26 = F_126 ( V_15 , V_19 ) ;
if ( V_26 ) {
F_113 ( L_37 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
goto V_188;
}
V_159 = F_127 ( V_11 ) ;
V_158 -> V_99 = 0 ;
V_158 -> V_189 = 0 ;
F_24 ( V_158 ) ;
V_158 -> V_190 = V_104 -
( F_128 ( V_11 -> V_29 . V_191 ) + 1 ) ;
for ( V_163 = 0 ; V_163 < V_192 ; V_163 ++ )
V_158 -> V_193 [ V_163 ] = V_158 -> V_190 ;
if ( V_11 -> V_29 . V_105 && ! V_11 -> V_29 . V_53 ) {
V_162 = F_28 ( V_11 , V_15 , 1 ) ;
if ( ( V_162 == - 1 ) && ! V_11 -> V_29 . V_191 ) {
F_112 ( L_38 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
} else if ( V_162 == - 1 ) {
F_112 ( L_39 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
}
}
if ( V_11 -> V_29 . V_105 ) {
if ( F_28 ( V_11 , V_15 , 0 ) == V_54 ) {
if ( V_11 -> V_29 . V_98 ) {
V_158 -> V_30 = V_44 ;
V_158 -> V_99 = V_11 -> V_29 . V_98 ;
} else {
V_158 -> V_30 = V_31 ;
}
} else {
V_158 -> V_30 = V_43 ;
}
} else if ( V_11 -> V_29 . V_191 ) {
V_158 -> V_30 = ( F_21 ( V_15 ) ?
V_31 : V_43 ) ;
} else {
V_158 -> V_30 = V_31 ;
}
if ( V_158 -> V_30 != V_43 )
V_158 -> V_103 = V_104 ;
F_55 ( L_40 ,
V_158 -> V_30 == V_43 ? L_41 :
( V_158 -> V_30 == V_31 ? L_42 : L_43 ) ) ;
if ( F_34 ( V_11 -> V_29 . V_1 ) && V_11 -> V_29 . V_194 [ 0 ] ) {
if ( strcmp ( V_11 -> V_29 . V_194 , V_158 -> V_16 -> V_59 ) == 0 ) {
V_11 -> V_90 = V_158 ;
V_11 -> V_92 = true ;
}
}
switch ( V_11 -> V_29 . V_1 ) {
case V_4 :
F_70 ( V_158 ,
V_106 ) ;
break;
case V_7 :
F_70 ( V_158 , V_106 ) ;
if ( ! V_159 ) {
F_129 ( V_158 ) . V_195 = 1 ;
F_130 ( V_11 , 1000 / V_196 ) ;
} else {
F_129 ( V_158 ) . V_195 =
F_129 ( V_159 ) . V_195 + 1 ;
}
F_131 ( V_158 ) ;
break;
case V_8 :
case V_9 :
F_132 ( V_158 ) ;
F_70 ( V_158 , V_106 ) ;
break;
default:
F_55 ( L_44 ) ;
F_132 ( V_158 ) ;
if ( ! V_11 -> V_68 && V_158 -> V_30 == V_31 )
F_72 ( V_11 -> V_68 , V_158 ) ;
break;
}
#ifdef F_133
V_15 -> V_197 = V_11 -> V_16 -> V_197 ;
if ( V_15 -> V_197 ) {
if ( F_76 ( V_158 ) ) {
F_66 ( L_45 ,
V_19 -> V_59 ) ;
V_26 = - V_164 ;
goto V_198;
}
}
#endif
V_26 = F_134 ( V_15 , F_95 ,
V_158 ) ;
if ( V_26 ) {
F_55 ( L_46 , V_26 ) ;
goto V_198;
}
V_26 = F_106 ( V_19 , V_15 , V_158 ) ;
if ( V_26 ) {
F_55 ( L_47 , V_26 ) ;
goto V_199;
}
V_26 = F_135 ( V_158 ) ;
if ( V_26 ) {
F_55 ( L_48 , V_26 ) ;
goto V_200;
}
V_11 -> V_201 ++ ;
F_88 ( V_11 ) ;
F_18 ( V_11 ) ;
if ( F_34 ( V_11 -> V_29 . V_1 ) ) {
F_136 () ;
F_74 ( & V_11 -> V_110 ) ;
F_75 ( V_11 ) ;
F_73 ( & V_11 -> V_110 ) ;
F_137 () ;
}
F_66 ( L_49 ,
V_19 -> V_59 , V_15 -> V_59 ,
F_138 ( V_158 ) ? L_50 : L_51 ,
V_158 -> V_30 != V_43 ? L_52 : L_53 ) ;
return 0 ;
V_200:
F_109 ( V_19 , V_15 ) ;
V_199:
F_139 ( V_15 ) ;
V_198:
if ( ! F_34 ( V_11 -> V_29 . V_1 ) )
F_44 ( V_19 , V_15 ) ;
F_140 ( V_15 , V_19 ) ;
if ( V_11 -> V_90 == V_158 )
V_11 -> V_90 = NULL ;
if ( V_11 -> V_68 == V_158 ) {
F_136 () ;
F_74 ( & V_11 -> V_110 ) ;
F_65 ( V_11 , NULL ) ;
F_75 ( V_11 ) ;
F_73 ( & V_11 -> V_110 ) ;
F_137 () ;
}
F_80 ( V_158 ) ;
V_188:
V_15 -> V_139 &= ~ V_187 ;
F_141 ( V_15 ) ;
V_186:
if ( ! V_11 -> V_29 . V_108 ||
V_11 -> V_29 . V_1 != V_4 ) {
F_104 ( V_161 . V_183 , V_158 -> V_182 ) ;
V_161 . V_184 = V_15 -> type ;
F_120 ( V_15 , & V_161 ) ;
}
V_185:
F_119 ( V_15 , V_158 -> V_179 ) ;
V_181:
F_79 ( V_158 ) ;
V_167:
if ( ! F_19 ( V_11 ) &&
F_142 ( V_19 -> V_85 , V_15 -> V_85 ) )
F_143 ( V_19 ) ;
return V_26 ;
}
static int F_144 ( struct V_14 * V_19 ,
struct V_14 * V_15 ,
bool V_202 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_203 ;
struct V_160 V_161 ;
int V_204 = V_19 -> V_81 ;
T_6 V_205 = V_19 -> V_123 ;
if ( ! ( V_15 -> V_81 & V_156 ) ||
! F_145 ( V_15 , V_19 ) ) {
F_113 ( L_54 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
return - V_172 ;
}
F_136 () ;
V_22 = F_8 ( V_11 , V_15 ) ;
if ( ! V_22 ) {
F_66 ( L_55 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
F_137 () ;
return - V_172 ;
}
F_146 ( V_22 ) ;
F_109 ( V_19 , V_15 ) ;
F_139 ( V_15 ) ;
F_74 ( & V_11 -> V_206 ) ;
if ( V_11 -> V_29 . V_1 == V_7 )
F_147 ( V_22 ) ;
F_73 ( & V_11 -> V_206 ) ;
F_66 ( L_56 ,
V_19 -> V_59 ,
F_138 ( V_22 ) ? L_57 : L_58 ,
V_15 -> V_59 ) ;
V_203 = V_11 -> V_68 ;
V_11 -> V_207 = NULL ;
if ( ! V_202 && ( ! V_11 -> V_29 . V_108 ||
V_11 -> V_29 . V_1 != V_4 ) ) {
if ( F_142 ( V_19 -> V_85 , V_22 -> V_182 ) &&
F_19 ( V_11 ) )
F_112 ( L_59 ,
V_19 -> V_59 , V_15 -> V_59 ,
V_22 -> V_182 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
}
if ( V_11 -> V_90 == V_22 )
V_11 -> V_90 = NULL ;
if ( V_203 == V_22 ) {
F_74 ( & V_11 -> V_110 ) ;
F_65 ( V_11 , NULL ) ;
F_73 ( & V_11 -> V_110 ) ;
}
if ( F_16 ( V_11 ) ) {
F_148 ( V_11 , V_22 ) ;
}
if ( V_202 ) {
F_149 ( V_11 -> V_68 , NULL ) ;
} else if ( V_203 == V_22 ) {
F_74 ( & V_11 -> V_110 ) ;
F_75 ( V_11 ) ;
F_73 ( & V_11 -> V_110 ) ;
}
if ( ! F_19 ( V_11 ) ) {
F_18 ( V_11 ) ;
F_143 ( V_19 ) ;
if ( F_114 ( V_19 ) ) {
F_112 ( L_60 ,
V_19 -> V_59 , V_19 -> V_59 ) ;
F_112 ( L_61 ,
V_19 -> V_59 ) ;
}
}
F_137 () ;
F_150 () ;
V_11 -> V_201 -- ;
if ( ! F_19 ( V_11 ) ) {
F_42 ( V_88 , V_11 -> V_16 ) ;
F_42 ( V_208 , V_11 -> V_16 ) ;
}
F_88 ( V_11 ) ;
if ( ! ( V_19 -> V_123 & V_125 ) &&
( V_205 & V_125 ) )
F_66 ( L_62 ,
V_19 -> V_59 , V_15 -> V_59 , V_19 -> V_59 ) ;
F_140 ( V_15 , V_19 ) ;
if ( ! F_34 ( V_11 -> V_29 . V_1 ) ) {
if ( V_204 & V_82 )
F_35 ( V_15 , - 1 ) ;
if ( V_204 & V_83 )
F_37 ( V_15 , - 1 ) ;
F_44 ( V_19 , V_15 ) ;
}
F_80 ( V_22 ) ;
F_141 ( V_15 ) ;
if ( V_11 -> V_29 . V_108 != V_174 ||
V_11 -> V_29 . V_1 != V_4 ) {
F_104 ( V_161 . V_183 , V_22 -> V_182 ) ;
V_161 . V_184 = V_15 -> type ;
F_120 ( V_15 , & V_161 ) ;
}
F_119 ( V_15 , V_22 -> V_179 ) ;
V_15 -> V_139 &= ~ V_187 ;
F_79 ( V_22 ) ;
return 0 ;
}
int F_151 ( struct V_14 * V_19 , struct V_14 * V_15 )
{
return F_144 ( V_19 , V_15 , false ) ;
}
static int F_152 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
int V_147 ;
V_147 = F_151 ( V_19 , V_15 ) ;
if ( V_147 == 0 && ! F_19 ( V_11 ) ) {
V_19 -> V_139 |= V_209 ;
F_66 ( L_63 ,
V_19 -> V_59 , V_19 -> V_59 ) ;
F_153 ( V_19 ) ;
}
return V_147 ;
}
static int F_154 ( struct V_14 * V_19 , struct V_210 * V_211 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
V_211 -> V_212 = V_11 -> V_29 . V_1 ;
V_211 -> V_105 = V_11 -> V_29 . V_105 ;
V_211 -> V_213 = V_11 -> V_201 ;
return 0 ;
}
static int F_155 ( struct V_14 * V_19 , struct V_214 * V_211 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
int V_163 = 0 , V_26 = - V_215 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
if ( V_163 ++ == ( int ) V_211 -> V_216 ) {
V_26 = 0 ;
strcpy ( V_211 -> V_217 , V_22 -> V_16 -> V_59 ) ;
V_211 -> V_30 = V_22 -> V_30 ;
V_211 -> V_102 = F_156 ( V_22 ) ;
V_211 -> V_189 = V_22 -> V_189 ;
break;
}
}
return V_26 ;
}
static int F_157 ( struct V_10 * V_11 )
{
int V_218 , V_219 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
bool V_220 ;
V_220 = ! V_11 -> V_68 ? true : false ;
F_158 (bond, slave, iter) {
V_22 -> V_221 = V_222 ;
V_218 = F_28 ( V_11 , V_22 -> V_16 , 0 ) ;
switch ( V_22 -> V_30 ) {
case V_31 :
if ( V_218 )
continue;
V_22 -> V_30 = V_42 ;
V_22 -> V_99 = V_11 -> V_29 . V_223 ;
if ( V_22 -> V_99 ) {
F_66 ( L_64 ,
V_11 -> V_16 -> V_59 ,
( V_11 -> V_29 . V_1 ==
V_4 ) ?
( F_138 ( V_22 ) ?
L_65 : L_66 ) : L_67 ,
V_22 -> V_16 -> V_59 ,
V_11 -> V_29 . V_223 * V_11 -> V_29 . V_105 ) ;
}
case V_42 :
if ( V_218 ) {
V_22 -> V_30 = V_31 ;
V_22 -> V_103 = V_104 ;
F_66 ( L_68 ,
V_11 -> V_16 -> V_59 ,
( V_11 -> V_29 . V_223 - V_22 -> V_99 ) *
V_11 -> V_29 . V_105 ,
V_22 -> V_16 -> V_59 ) ;
continue;
}
if ( V_22 -> V_99 <= 0 ) {
V_22 -> V_221 = V_43 ;
V_219 ++ ;
continue;
}
V_22 -> V_99 -- ;
break;
case V_43 :
if ( ! V_218 )
continue;
V_22 -> V_30 = V_44 ;
V_22 -> V_99 = V_11 -> V_29 . V_98 ;
if ( V_22 -> V_99 ) {
F_66 ( L_69 ,
V_11 -> V_16 -> V_59 , V_22 -> V_16 -> V_59 ,
V_220 ? 0 :
V_11 -> V_29 . V_98 *
V_11 -> V_29 . V_105 ) ;
}
case V_44 :
if ( ! V_218 ) {
V_22 -> V_30 = V_43 ;
F_66 ( L_70 ,
V_11 -> V_16 -> V_59 ,
( V_11 -> V_29 . V_98 - V_22 -> V_99 ) *
V_11 -> V_29 . V_105 ,
V_22 -> V_16 -> V_59 ) ;
continue;
}
if ( V_220 )
V_22 -> V_99 = 0 ;
if ( V_22 -> V_99 <= 0 ) {
V_22 -> V_221 = V_31 ;
V_219 ++ ;
V_220 = false ;
continue;
}
V_22 -> V_99 -- ;
break;
}
}
return V_219 ;
}
static void F_159 ( struct V_10 * V_11 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
switch ( V_22 -> V_221 ) {
case V_222 :
continue;
case V_31 :
V_22 -> V_30 = V_31 ;
V_22 -> V_103 = V_104 ;
if ( V_11 -> V_29 . V_1 == V_7 ) {
F_160 ( V_22 ) ;
} else if ( V_11 -> V_29 . V_1 != V_4 ) {
F_132 ( V_22 ) ;
} else if ( V_22 != V_11 -> V_90 ) {
F_160 ( V_22 ) ;
}
F_66 ( L_71 ,
V_11 -> V_16 -> V_59 , V_22 -> V_16 -> V_59 ,
V_22 -> V_35 == V_36 ? 0 : V_22 -> V_35 ,
V_22 -> V_37 ? L_72 : L_73 ) ;
if ( V_11 -> V_29 . V_1 == V_7 )
F_67 ( V_22 , V_31 ) ;
if ( F_16 ( V_11 ) )
F_68 ( V_11 , V_22 ,
V_31 ) ;
if ( ! V_11 -> V_68 ||
( V_22 == V_11 -> V_90 ) )
goto V_224;
continue;
case V_43 :
if ( V_22 -> V_189 < V_225 )
V_22 -> V_189 ++ ;
V_22 -> V_30 = V_43 ;
if ( V_11 -> V_29 . V_1 == V_4 ||
V_11 -> V_29 . V_1 == V_7 )
F_70 ( V_22 ,
V_106 ) ;
F_66 ( L_74 ,
V_11 -> V_16 -> V_59 , V_22 -> V_16 -> V_59 ) ;
if ( V_11 -> V_29 . V_1 == V_7 )
F_67 ( V_22 ,
V_43 ) ;
if ( F_16 ( V_11 ) )
F_68 ( V_11 , V_22 ,
V_43 ) ;
if ( V_22 == V_11 -> V_68 )
goto V_224;
continue;
default:
F_113 ( L_75 ,
V_11 -> V_16 -> V_59 , V_22 -> V_221 ,
V_22 -> V_16 -> V_59 ) ;
V_22 -> V_221 = V_222 ;
continue;
}
V_224:
F_49 () ;
F_136 () ;
F_74 ( & V_11 -> V_110 ) ;
F_75 ( V_11 ) ;
F_73 ( & V_11 -> V_110 ) ;
F_137 () ;
}
F_18 ( V_11 ) ;
}
static void F_161 ( struct V_69 * V_70 )
{
struct V_10 * V_11 = F_39 ( V_70 , struct V_10 ,
V_226 . V_70 ) ;
bool V_107 = false ;
unsigned long V_99 ;
V_99 = F_128 ( V_11 -> V_29 . V_105 ) ;
if ( ! F_19 ( V_11 ) )
goto V_227;
F_61 () ;
V_107 = F_60 ( V_11 ) ;
if ( F_157 ( V_11 ) ) {
F_63 () ;
if ( ! F_40 () ) {
V_99 = 1 ;
V_107 = false ;
goto V_227;
}
F_159 ( V_11 ) ;
F_43 () ;
} else
F_63 () ;
V_227:
if ( V_11 -> V_29 . V_105 )
F_41 ( V_11 -> V_72 , & V_11 -> V_226 , V_99 ) ;
if ( V_107 ) {
if ( ! F_40 () )
return;
F_42 ( V_112 , V_11 -> V_16 ) ;
F_43 () ;
}
}
static bool F_162 ( struct V_10 * V_11 , T_8 V_228 )
{
struct V_14 * V_229 ;
struct V_24 * V_25 ;
bool V_147 = false ;
if ( V_228 == F_163 ( V_11 -> V_16 , 0 , V_228 ) )
return true ;
F_61 () ;
F_164 (bond->dev, upper, iter) {
if ( V_228 == F_163 ( V_229 , 0 , V_228 ) ) {
V_147 = true ;
break;
}
}
F_63 () ;
return V_147 ;
}
static void F_165 ( struct V_14 * V_15 , int V_230 ,
T_8 V_231 , T_8 V_232 ,
struct V_233 * V_234 )
{
struct V_12 * V_13 ;
int V_163 ;
F_55 ( L_76 ,
V_230 , V_15 -> V_59 , & V_231 , & V_232 ) ;
V_13 = F_166 ( V_230 , V_235 , V_231 , V_15 , V_232 ,
NULL , V_15 -> V_85 , NULL ) ;
if ( ! V_13 ) {
F_167 ( L_77 ) ;
return;
}
for ( V_163 = V_236 - 1 ; V_163 > 0 ; V_163 -- ) {
if ( ! V_234 [ V_163 ] . V_237 )
continue;
F_55 ( L_78 ,
F_168 ( V_234 [ V_163 ] . V_238 ) , V_234 [ V_163 ] . V_237 ) ;
V_13 = F_169 ( V_13 , V_234 [ V_163 ] . V_238 ,
V_234 [ V_163 ] . V_237 ) ;
if ( ! V_13 ) {
F_167 ( L_79 ) ;
return;
}
}
if ( V_234 [ 0 ] . V_237 ) {
F_55 ( L_80 ,
F_168 ( V_234 [ 0 ] . V_238 ) , V_234 [ 0 ] . V_237 ) ;
V_13 = F_170 ( V_13 , V_234 [ 0 ] . V_238 , V_234 [ 0 ] . V_237 ) ;
if ( ! V_13 ) {
F_167 ( L_81 ) ;
return;
}
}
F_171 ( V_13 ) ;
}
static bool F_172 ( struct V_14 * V_239 ,
struct V_14 * V_240 ,
struct V_233 * V_234 )
{
struct V_14 * V_229 ;
struct V_24 * V_25 ;
int V_241 ;
if ( V_239 == V_240 )
return true ;
F_173 (start_dev, upper, iter) {
if ( F_172 ( V_229 , V_240 , V_234 ) ) {
if ( F_174 ( V_229 ) ) {
V_241 = F_175 ( V_229 ) ;
if ( V_241 >= V_236 )
return false ;
V_234 [ V_241 ] . V_238 =
F_176 ( V_229 ) ;
V_234 [ V_241 ] . V_237 = F_177 ( V_229 ) ;
}
return true ;
}
}
return false ;
}
static void F_178 ( struct V_10 * V_11 , struct V_22 * V_22 )
{
struct V_242 * V_243 ;
struct V_233 V_234 [ V_236 ] ;
T_8 * V_244 = V_11 -> V_29 . V_245 , V_161 ;
int V_163 ;
bool V_147 ;
for ( V_163 = 0 ; V_163 < V_192 && V_244 [ V_163 ] ; V_163 ++ ) {
F_55 ( L_82 , & V_244 [ V_163 ] ) ;
memset ( V_234 , 0 , sizeof( V_234 ) ) ;
V_243 = F_179 ( F_180 ( V_11 -> V_16 ) , V_244 [ V_163 ] , 0 ,
V_246 , 0 ) ;
if ( F_181 ( V_243 ) ) {
if ( V_11 -> V_29 . V_247 )
F_182 ( L_83 ,
V_11 -> V_16 -> V_59 ,
& V_244 [ V_163 ] ) ;
F_165 ( V_22 -> V_16 , V_248 , V_244 [ V_163 ] ,
0 , V_234 ) ;
continue;
}
if ( V_243 -> V_249 . V_16 == V_11 -> V_16 )
goto V_250;
F_61 () ;
V_147 = F_172 ( V_11 -> V_16 , V_243 -> V_249 . V_16 , V_234 ) ;
F_63 () ;
if ( V_147 )
goto V_250;
F_55 ( L_84 ,
V_11 -> V_16 -> V_59 , & V_244 [ V_163 ] ,
V_243 -> V_249 . V_16 ? V_243 -> V_249 . V_16 -> V_59 : L_15 ) ;
F_183 ( V_243 ) ;
continue;
V_250:
V_161 = F_163 ( V_243 -> V_249 . V_16 , V_244 [ V_163 ] , 0 ) ;
F_183 ( V_243 ) ;
F_165 ( V_22 -> V_16 , V_248 , V_244 [ V_163 ] ,
V_161 , V_234 ) ;
}
}
static void F_184 ( struct V_10 * V_11 , struct V_22 * V_22 , T_8 V_251 , T_8 V_252 )
{
int V_163 ;
if ( ! V_251 || ! F_162 ( V_11 , V_252 ) ) {
F_55 ( L_85 , & V_251 , & V_252 ) ;
return;
}
V_163 = F_185 ( V_11 -> V_29 . V_245 , V_251 ) ;
if ( V_163 == - 1 ) {
F_55 ( L_86 , & V_251 ) ;
return;
}
V_22 -> V_190 = V_104 ;
V_22 -> V_193 [ V_163 ] = V_104 ;
}
int F_186 ( const struct V_12 * V_13 , struct V_10 * V_11 ,
struct V_22 * V_22 )
{
struct V_253 * V_254 = (struct V_253 * ) V_13 -> V_154 ;
struct V_22 * V_68 ;
unsigned char * V_255 ;
T_8 V_251 , V_252 ;
int V_256 , V_257 = V_13 -> V_258 == F_187 ( V_235 ) ;
if ( ! F_188 ( V_11 , V_22 ) ) {
if ( ( F_189 ( V_11 , V_22 ) && V_257 ) ||
! F_189 ( V_11 , V_22 ) )
V_22 -> V_190 = V_104 ;
return V_148 ;
} else if ( ! V_257 ) {
return V_148 ;
}
V_256 = F_190 ( V_11 -> V_16 ) ;
F_55 ( L_87 ,
V_11 -> V_16 -> V_59 , V_13 -> V_16 -> V_59 ) ;
if ( V_256 > F_191 ( V_13 ) ) {
V_254 = F_192 ( V_256 , V_149 ) ;
if ( ! V_254 )
goto V_259;
if ( F_193 ( V_13 , 0 , V_254 , V_256 ) < 0 )
goto V_259;
}
if ( V_254 -> V_260 != V_11 -> V_16 -> V_84 ||
V_13 -> V_143 == V_261 ||
V_13 -> V_143 == V_262 ||
V_254 -> V_263 != F_194 ( V_169 ) ||
V_254 -> V_264 != F_194 ( V_265 ) ||
V_254 -> V_266 != 4 )
goto V_259;
V_255 = ( unsigned char * ) ( V_254 + 1 ) ;
V_255 += V_11 -> V_16 -> V_84 ;
memcpy ( & V_251 , V_255 , 4 ) ;
V_255 += 4 + V_11 -> V_16 -> V_84 ;
memcpy ( & V_252 , V_255 , 4 ) ;
F_55 ( L_88 ,
V_11 -> V_16 -> V_59 , V_22 -> V_16 -> V_59 , F_156 ( V_22 ) ,
V_11 -> V_29 . V_247 , F_188 ( V_11 , V_22 ) ,
& V_251 , & V_252 ) ;
V_68 = F_62 ( V_11 -> V_68 ) ;
if ( F_138 ( V_22 ) )
F_184 ( V_11 , V_22 , V_251 , V_252 ) ;
else if ( V_68 &&
F_195 ( F_196 ( V_11 , V_68 ) ,
V_68 -> V_103 ) )
F_184 ( V_11 , V_22 , V_252 , V_251 ) ;
V_259:
if ( V_254 != (struct V_253 * ) V_13 -> V_154 )
F_79 ( V_254 ) ;
return V_148 ;
}
static bool F_197 ( struct V_10 * V_11 , unsigned long V_267 ,
int V_268 )
{
int V_269 = F_128 ( V_11 -> V_29 . V_191 ) ;
return F_198 ( V_104 ,
V_267 - V_269 ,
V_267 + V_268 * V_269 + V_269 / 2 ) ;
}
static void F_199 ( struct V_69 * V_70 )
{
struct V_10 * V_11 = F_39 ( V_70 , struct V_10 ,
V_270 . V_70 ) ;
struct V_22 * V_22 , * V_203 ;
struct V_24 * V_25 ;
int V_224 = 0 , V_271 = 0 ;
if ( ! F_19 ( V_11 ) )
goto V_227;
F_61 () ;
V_203 = F_99 ( V_11 -> V_68 ) ;
F_158 (bond, slave, iter) {
unsigned long V_272 = F_200 ( V_22 -> V_16 ) ;
if ( V_22 -> V_30 != V_31 ) {
if ( F_197 ( V_11 , V_272 , 1 ) &&
F_197 ( V_11 , V_22 -> V_190 , 1 ) ) {
V_22 -> V_30 = V_31 ;
V_271 = 1 ;
if ( ! V_203 ) {
F_66 ( L_89 ,
V_11 -> V_16 -> V_59 ,
V_22 -> V_16 -> V_59 ) ;
V_224 = 1 ;
} else {
F_66 ( L_90 ,
V_11 -> V_16 -> V_59 ,
V_22 -> V_16 -> V_59 ) ;
}
}
} else {
if ( ! F_197 ( V_11 , V_272 , 2 ) ||
! F_197 ( V_11 , V_22 -> V_190 , 2 ) ) {
V_22 -> V_30 = V_43 ;
V_271 = 1 ;
if ( V_22 -> V_189 < V_225 )
V_22 -> V_189 ++ ;
F_66 ( L_91 ,
V_11 -> V_16 -> V_59 , V_22 -> V_16 -> V_59 ) ;
if ( V_22 == V_203 )
V_224 = 1 ;
}
}
if ( F_59 ( V_22 -> V_16 ) )
F_178 ( V_11 , V_22 ) ;
}
F_63 () ;
if ( V_224 || V_271 ) {
if ( ! F_40 () )
goto V_227;
if ( V_271 ) {
F_201 ( V_11 ) ;
} else if ( V_224 ) {
F_136 () ;
F_74 ( & V_11 -> V_110 ) ;
F_75 ( V_11 ) ;
F_73 ( & V_11 -> V_110 ) ;
F_137 () ;
}
F_43 () ;
}
V_227:
if ( V_11 -> V_29 . V_191 )
F_41 ( V_11 -> V_72 , & V_11 -> V_270 ,
F_128 ( V_11 -> V_29 . V_191 ) ) ;
}
static int F_202 ( struct V_10 * V_11 )
{
unsigned long V_272 , V_190 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_219 = 0 ;
F_158 (bond, slave, iter) {
V_22 -> V_221 = V_222 ;
V_190 = F_196 ( V_11 , V_22 ) ;
if ( V_22 -> V_30 != V_31 ) {
if ( F_197 ( V_11 , V_190 , 1 ) ) {
V_22 -> V_221 = V_31 ;
V_219 ++ ;
}
continue;
}
if ( F_197 ( V_11 , V_22 -> V_103 , 2 ) )
continue;
if ( ! F_138 ( V_22 ) &&
! V_11 -> V_207 &&
! F_197 ( V_11 , V_190 , 3 ) ) {
V_22 -> V_221 = V_43 ;
V_219 ++ ;
}
V_272 = F_200 ( V_22 -> V_16 ) ;
if ( F_138 ( V_22 ) &&
( ! F_197 ( V_11 , V_272 , 2 ) ||
! F_197 ( V_11 , V_190 , 2 ) ) ) {
V_22 -> V_221 = V_43 ;
V_219 ++ ;
}
}
return V_219 ;
}
static void F_203 ( struct V_10 * V_11 )
{
unsigned long V_272 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
switch ( V_22 -> V_221 ) {
case V_222 :
continue;
case V_31 :
V_272 = F_200 ( V_22 -> V_16 ) ;
if ( V_11 -> V_68 != V_22 ||
( ! V_11 -> V_68 &&
F_197 ( V_11 , V_272 , 1 ) ) ) {
V_22 -> V_30 = V_31 ;
if ( V_11 -> V_207 ) {
F_70 (
V_11 -> V_207 ,
V_106 ) ;
V_11 -> V_207 = NULL ;
}
F_66 ( L_89 ,
V_11 -> V_16 -> V_59 , V_22 -> V_16 -> V_59 ) ;
if ( ! V_11 -> V_68 ||
( V_22 == V_11 -> V_90 ) )
goto V_224;
}
continue;
case V_43 :
if ( V_22 -> V_189 < V_225 )
V_22 -> V_189 ++ ;
V_22 -> V_30 = V_43 ;
F_70 ( V_22 ,
V_106 ) ;
F_66 ( L_74 ,
V_11 -> V_16 -> V_59 , V_22 -> V_16 -> V_59 ) ;
if ( V_22 == V_11 -> V_68 ) {
V_11 -> V_207 = NULL ;
goto V_224;
}
continue;
default:
F_113 ( L_92 ,
V_11 -> V_16 -> V_59 , V_22 -> V_221 ,
V_22 -> V_16 -> V_59 ) ;
continue;
}
V_224:
F_49 () ;
F_136 () ;
F_74 ( & V_11 -> V_110 ) ;
F_75 ( V_11 ) ;
F_73 ( & V_11 -> V_110 ) ;
F_137 () ;
}
F_18 ( V_11 ) ;
}
static bool F_204 ( struct V_10 * V_11 )
{
struct V_22 * V_22 , * V_273 = NULL , * V_158 = NULL ,
* V_274 = F_62 ( V_11 -> V_207 ) ,
* V_68 = F_62 ( V_11 -> V_68 ) ;
struct V_24 * V_25 ;
bool V_250 = false ;
bool V_275 = V_276 ;
if ( V_274 && V_68 )
F_66 ( L_93 ,
V_274 -> V_16 -> V_59 ,
V_68 -> V_16 -> V_59 ) ;
if ( V_68 ) {
F_178 ( V_11 , V_68 ) ;
return V_275 ;
}
if ( ! V_274 ) {
V_274 = F_205 ( V_11 ) ;
if ( ! V_274 )
return V_275 ;
}
F_70 ( V_274 , V_276 ) ;
F_158 (bond, slave, iter) {
if ( ! V_250 && ! V_273 && F_59 ( V_22 -> V_16 ) )
V_273 = V_22 ;
if ( V_250 && ! V_158 && F_59 ( V_22 -> V_16 ) )
V_158 = V_22 ;
if ( ! F_59 ( V_22 -> V_16 ) && V_22 -> V_30 == V_31 ) {
V_22 -> V_30 = V_43 ;
if ( V_22 -> V_189 < V_225 )
V_22 -> V_189 ++ ;
F_70 ( V_22 ,
V_276 ) ;
F_66 ( L_94 ,
V_11 -> V_16 -> V_59 , V_22 -> V_16 -> V_59 ) ;
}
if ( V_22 == V_274 )
V_250 = true ;
}
if ( ! V_158 && V_273 )
V_158 = V_273 ;
if ( ! V_158 )
goto V_277;
V_158 -> V_30 = V_44 ;
F_71 ( V_158 , V_276 ) ;
F_178 ( V_11 , V_158 ) ;
V_158 -> V_103 = V_104 ;
F_72 ( V_11 -> V_207 , V_158 ) ;
V_277:
F_158 (bond, slave, iter) {
if ( V_22 -> V_278 ) {
V_275 = V_106 ;
break;
}
}
return V_275 ;
}
static void F_206 ( struct V_69 * V_70 )
{
struct V_10 * V_11 = F_39 ( V_70 , struct V_10 ,
V_270 . V_70 ) ;
bool V_107 = false ;
bool V_275 = false ;
int V_269 ;
V_269 = F_128 ( V_11 -> V_29 . V_191 ) ;
if ( ! F_19 ( V_11 ) )
goto V_227;
F_61 () ;
V_107 = F_60 ( V_11 ) ;
if ( F_202 ( V_11 ) ) {
F_63 () ;
if ( ! F_40 () ) {
V_269 = 1 ;
V_107 = false ;
goto V_227;
}
F_203 ( V_11 ) ;
F_43 () ;
F_61 () ;
}
V_275 = F_204 ( V_11 ) ;
F_63 () ;
V_227:
if ( V_11 -> V_29 . V_191 )
F_41 ( V_11 -> V_72 , & V_11 -> V_270 , V_269 ) ;
if ( V_107 || V_275 ) {
if ( ! F_40 () )
return;
if ( V_107 )
F_42 ( V_112 ,
V_11 -> V_16 ) ;
if ( V_275 )
F_207 ( V_11 ) ;
F_43 () ;
}
}
static int F_208 ( struct V_10 * V_11 )
{
F_209 ( V_11 ) ;
F_210 ( V_11 ) ;
F_211 ( V_11 ) ;
return V_279 ;
}
static int F_212 ( unsigned long V_280 ,
struct V_14 * V_19 )
{
struct V_10 * V_281 = F_11 ( V_19 ) ;
switch ( V_280 ) {
case V_282 :
return F_208 ( V_281 ) ;
case V_283 :
F_209 ( V_281 ) ;
break;
case V_284 :
F_210 ( V_281 ) ;
break;
case V_112 :
if ( V_281 -> V_100 )
V_281 -> V_100 -- ;
break;
default:
break;
}
return V_279 ;
}
static int F_213 ( unsigned long V_280 ,
struct V_14 * V_15 )
{
struct V_22 * V_22 = F_214 ( V_15 ) ;
struct V_10 * V_11 ;
struct V_14 * V_19 ;
T_3 V_285 ;
T_5 V_286 ;
if ( ! V_22 )
return V_279 ;
V_19 = V_22 -> V_11 -> V_16 ;
V_11 = V_22 -> V_11 ;
switch ( V_280 ) {
case V_283 :
if ( V_19 -> type != V_169 )
F_152 ( V_19 , V_15 ) ;
else
F_151 ( V_19 , V_15 ) ;
break;
case V_287 :
case V_288 :
V_285 = V_22 -> V_35 ;
V_286 = V_22 -> V_37 ;
F_24 ( V_22 ) ;
if ( V_11 -> V_29 . V_1 == V_7 ) {
if ( V_285 != V_22 -> V_35 )
F_215 ( V_22 ) ;
if ( V_286 != V_22 -> V_37 )
F_216 ( V_22 ) ;
}
break;
case V_289 :
break;
case V_290 :
break;
case V_282 :
if ( ! F_34 ( V_11 -> V_29 . V_1 ) ||
! V_11 -> V_29 . V_194 [ 0 ] )
break;
if ( V_22 == V_11 -> V_90 ) {
V_11 -> V_90 = NULL ;
} else if ( ! strcmp ( V_15 -> V_59 , V_11 -> V_29 . V_194 ) ) {
V_11 -> V_90 = V_22 ;
} else {
break;
}
F_66 ( L_95 ,
V_11 -> V_16 -> V_59 ,
V_11 -> V_90 ? V_15 -> V_59 : L_96 ) ;
F_136 () ;
F_74 ( & V_11 -> V_110 ) ;
F_75 ( V_11 ) ;
F_73 ( & V_11 -> V_110 ) ;
F_137 () ;
break;
case V_291 :
F_88 ( V_11 ) ;
break;
case V_73 :
F_42 ( V_280 , V_22 -> V_11 -> V_16 ) ;
break;
default:
break;
}
return V_279 ;
}
static int F_217 ( struct V_292 * V_293 ,
unsigned long V_280 , void * V_294 )
{
struct V_14 * V_295 = F_218 ( V_294 ) ;
F_55 ( L_97 ,
V_295 ? V_295 -> V_59 : L_98 , V_280 ) ;
if ( ! ( V_295 -> V_139 & V_187 ) )
return V_279 ;
if ( V_295 -> V_81 & V_296 ) {
F_55 ( L_99 ) ;
return F_212 ( V_280 , V_295 ) ;
}
if ( V_295 -> V_81 & V_156 ) {
F_55 ( L_100 ) ;
return F_213 ( V_280 , V_295 ) ;
}
return V_279 ;
}
static inline T_3 F_219 ( struct V_12 * V_13 )
{
struct V_297 * V_154 = (struct V_297 * ) V_13 -> V_154 ;
if ( F_191 ( V_13 ) >= F_220 ( struct V_297 , V_298 ) )
return V_154 -> V_155 [ 5 ] ^ V_154 -> V_299 [ 5 ] ;
return 0 ;
}
static bool F_221 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_300 * V_301 )
{
const struct V_302 * V_303 ;
const struct V_304 * V_305 ;
int V_306 , V_20 = - 1 ;
if ( V_11 -> V_29 . V_307 > V_308 )
return F_222 ( V_13 , V_301 ) ;
V_301 -> V_309 = 0 ;
V_306 = F_223 ( V_13 ) ;
if ( V_13 -> V_258 == F_194 ( V_265 ) ) {
if ( F_5 ( ! F_224 ( V_13 , V_306 + sizeof( * V_305 ) ) ) )
return false ;
V_305 = F_225 ( V_13 ) ;
V_301 -> V_310 = V_305 -> V_311 ;
V_301 -> V_249 = V_305 -> V_312 ;
V_306 += V_305 -> V_313 << 2 ;
if ( ! F_226 ( V_305 ) )
V_20 = V_305 -> V_258 ;
} else if ( V_13 -> V_258 == F_194 ( V_314 ) ) {
if ( F_5 ( ! F_224 ( V_13 , V_306 + sizeof( * V_303 ) ) ) )
return false ;
V_303 = F_227 ( V_13 ) ;
V_301 -> V_310 = ( V_315 T_8 ) F_228 ( & V_303 -> V_311 ) ;
V_301 -> V_249 = ( V_315 T_8 ) F_228 ( & V_303 -> V_312 ) ;
V_306 += sizeof( * V_303 ) ;
V_20 = V_303 -> V_316 ;
} else {
return false ;
}
if ( V_11 -> V_29 . V_307 == V_317 && V_20 >= 0 )
V_301 -> V_309 = F_229 ( V_13 , V_306 , V_20 ) ;
return true ;
}
int F_230 ( struct V_10 * V_11 , struct V_12 * V_13 , int V_318 )
{
struct V_300 V_319 ;
T_3 V_320 ;
if ( V_11 -> V_29 . V_307 == V_321 ||
! F_221 ( V_11 , V_13 , & V_319 ) )
return F_219 ( V_13 ) % V_318 ;
if ( V_11 -> V_29 . V_307 == V_308 ||
V_11 -> V_29 . V_307 == V_322 )
V_320 = F_219 ( V_13 ) ;
else
V_320 = ( V_315 T_3 ) V_319 . V_309 ;
V_320 ^= ( V_315 T_3 ) V_319 . V_249 ^ ( V_315 T_3 ) V_319 . V_310 ;
V_320 ^= ( V_320 >> 16 ) ;
V_320 ^= ( V_320 >> 8 ) ;
return V_320 % V_318 ;
}
static void F_231 ( struct V_10 * V_11 )
{
F_232 ( & V_11 -> V_71 ,
F_38 ) ;
F_232 ( & V_11 -> V_323 , V_324 ) ;
F_232 ( & V_11 -> V_226 , F_161 ) ;
if ( V_11 -> V_29 . V_1 == V_4 )
F_232 ( & V_11 -> V_270 , F_206 ) ;
else
F_232 ( & V_11 -> V_270 , F_199 ) ;
F_232 ( & V_11 -> V_325 , V_326 ) ;
}
static void F_233 ( struct V_10 * V_11 )
{
F_234 ( & V_11 -> V_226 ) ;
F_234 ( & V_11 -> V_270 ) ;
F_234 ( & V_11 -> V_323 ) ;
F_234 ( & V_11 -> V_325 ) ;
F_234 ( & V_11 -> V_71 ) ;
}
static int F_235 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_236 ( & V_11 -> V_206 ) ;
if ( F_19 ( V_11 ) ) {
F_236 ( & V_11 -> V_110 ) ;
F_12 (bond, slave, iter) {
if ( F_34 ( V_11 -> V_29 . V_1 )
&& ( V_22 != V_11 -> V_68 ) ) {
F_70 ( V_22 ,
V_106 ) ;
} else {
F_71 ( V_22 ,
V_106 ) ;
}
}
F_237 ( & V_11 -> V_110 ) ;
}
F_237 ( & V_11 -> V_206 ) ;
F_231 ( V_11 ) ;
if ( F_16 ( V_11 ) ) {
if ( F_238 ( V_11 , ( V_11 -> V_29 . V_1 == V_9 ) ) )
return - V_119 ;
F_41 ( V_11 -> V_72 , & V_11 -> V_323 , 0 ) ;
}
if ( V_11 -> V_29 . V_105 )
F_41 ( V_11 -> V_72 , & V_11 -> V_226 , 0 ) ;
if ( V_11 -> V_29 . V_191 ) {
F_41 ( V_11 -> V_72 , & V_11 -> V_270 , 0 ) ;
V_11 -> F_96 = F_186 ;
}
if ( V_11 -> V_29 . V_1 == V_7 ) {
F_41 ( V_11 -> V_72 , & V_11 -> V_325 , 0 ) ;
V_11 -> F_96 = V_327 ;
F_239 ( V_11 , 1 ) ;
}
return 0 ;
}
static int F_240 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_233 ( V_11 ) ;
V_11 -> V_100 = 0 ;
if ( F_16 ( V_11 ) )
F_241 ( V_11 ) ;
V_11 -> F_96 = NULL ;
return 0 ;
}
static struct V_328 * F_242 ( struct V_14 * V_19 ,
struct V_328 * V_329 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_328 V_330 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
memset ( V_329 , 0 , sizeof( * V_329 ) ) ;
F_243 ( & V_11 -> V_206 ) ;
F_12 (bond, slave, iter) {
const struct V_328 * V_331 =
F_244 ( V_22 -> V_16 , & V_330 ) ;
V_329 -> V_332 += V_331 -> V_332 ;
V_329 -> V_333 += V_331 -> V_333 ;
V_329 -> V_334 += V_331 -> V_334 ;
V_329 -> V_335 += V_331 -> V_335 ;
V_329 -> V_336 += V_331 -> V_336 ;
V_329 -> V_337 += V_331 -> V_337 ;
V_329 -> V_338 += V_331 -> V_338 ;
V_329 -> V_339 += V_331 -> V_339 ;
V_329 -> V_340 += V_331 -> V_340 ;
V_329 -> V_341 += V_331 -> V_341 ;
V_329 -> V_342 += V_331 -> V_342 ;
V_329 -> V_343 += V_331 -> V_343 ;
V_329 -> V_344 += V_331 -> V_344 ;
V_329 -> V_345 += V_331 -> V_345 ;
V_329 -> V_346 += V_331 -> V_346 ;
V_329 -> V_347 += V_331 -> V_347 ;
V_329 -> V_348 += V_331 -> V_348 ;
V_329 -> V_349 += V_331 -> V_349 ;
V_329 -> V_350 += V_331 -> V_350 ;
V_329 -> V_351 += V_331 -> V_351 ;
V_329 -> V_352 += V_331 -> V_352 ;
}
F_245 ( & V_11 -> V_206 ) ;
return V_329 ;
}
static int F_246 ( struct V_14 * V_19 , struct V_49 * V_50 , int V_353 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_14 * V_15 = NULL ;
struct V_210 V_354 ;
struct V_210 T_9 * V_355 = NULL ;
struct V_214 V_356 ;
struct V_214 T_9 * V_357 = NULL ;
struct V_51 * V_52 = NULL ;
struct V_358 V_359 ;
struct V_360 * V_360 ;
int V_26 = 0 ;
F_55 ( L_101 , V_19 -> V_59 , V_353 ) ;
switch ( V_353 ) {
case V_61 :
V_52 = F_31 ( V_50 ) ;
if ( ! V_52 )
return - V_172 ;
V_52 -> V_361 = 0 ;
case V_64 :
V_52 = F_31 ( V_50 ) ;
if ( ! V_52 )
return - V_172 ;
if ( V_52 -> V_62 == 1 ) {
V_52 -> V_65 = 0 ;
F_236 ( & V_11 -> V_206 ) ;
F_236 ( & V_11 -> V_110 ) ;
if ( F_21 ( V_11 -> V_16 ) )
V_52 -> V_65 = V_54 ;
F_237 ( & V_11 -> V_110 ) ;
F_237 ( & V_11 -> V_206 ) ;
}
return 0 ;
case V_362 :
case V_363 :
V_355 = (struct V_210 T_9 * ) V_50 -> V_364 ;
if ( F_247 ( & V_354 , V_355 , sizeof( V_210 ) ) )
return - V_365 ;
V_26 = F_154 ( V_19 , & V_354 ) ;
if ( V_26 == 0 &&
F_248 ( V_355 , & V_354 , sizeof( V_210 ) ) )
return - V_365 ;
return V_26 ;
case V_366 :
case V_367 :
V_357 = (struct V_214 T_9 * ) V_50 -> V_364 ;
if ( F_247 ( & V_356 , V_357 , sizeof( V_214 ) ) )
return - V_365 ;
V_26 = F_155 ( V_19 , & V_356 ) ;
if ( V_26 == 0 &&
F_248 ( V_357 , & V_356 , sizeof( V_214 ) ) )
return - V_365 ;
return V_26 ;
default:
break;
}
V_360 = F_180 ( V_19 ) ;
if ( ! F_249 ( V_360 -> V_368 , V_369 ) )
return - V_165 ;
V_15 = F_250 ( V_360 , V_50 -> V_370 ) ;
F_55 ( L_102 , V_15 ) ;
if ( ! V_15 )
return - V_215 ;
F_55 ( L_103 , V_15 -> V_59 ) ;
switch ( V_353 ) {
case V_371 :
case V_372 :
V_26 = F_111 ( V_19 , V_15 ) ;
break;
case V_373 :
case V_374 :
V_26 = F_151 ( V_19 , V_15 ) ;
break;
case V_375 :
case V_376 :
F_54 ( V_19 , V_15 ) ;
V_26 = 0 ;
break;
case V_377 :
case V_378 :
F_251 ( & V_359 , V_15 -> V_59 ) ;
V_26 = F_252 ( V_11 , V_379 , & V_359 ) ;
break;
default:
V_26 = - V_175 ;
}
return V_26 ;
}
static void F_253 ( struct V_14 * V_19 , int V_380 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_380 & V_82 )
F_33 ( V_11 ,
V_19 -> V_81 & V_82 ? 1 : - 1 ) ;
if ( V_380 & V_83 )
F_36 ( V_11 ,
V_19 -> V_81 & V_83 ? 1 : - 1 ) ;
}
static void F_254 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_61 () ;
if ( F_34 ( V_11 -> V_29 . V_1 ) ) {
V_22 = F_62 ( V_11 -> V_68 ) ;
if ( V_22 ) {
F_51 ( V_22 -> V_16 , V_19 ) ;
F_52 ( V_22 -> V_16 , V_19 ) ;
}
} else {
F_158 (bond, slave, iter) {
F_124 ( V_22 -> V_16 , V_19 ) ;
F_123 ( V_22 -> V_16 , V_19 ) ;
}
}
F_63 () ;
}
static int F_255 ( struct V_381 * V_382 )
{
struct V_10 * V_11 = F_11 ( V_382 -> V_16 ) ;
const struct V_46 * V_47 ;
struct V_383 V_384 ;
struct V_22 * V_22 ;
int V_147 ;
V_22 = F_256 ( V_11 ) ;
if ( ! V_22 )
return 0 ;
V_47 = V_22 -> V_16 -> V_48 ;
if ( ! V_47 -> V_385 )
return 0 ;
V_384 . V_386 = NULL ;
V_384 . V_387 = NULL ;
V_147 = V_47 -> V_385 ( V_22 -> V_16 , & V_384 ) ;
if ( V_147 )
return V_147 ;
V_382 -> V_384 -> V_387 = V_384 . V_387 ;
if ( ! V_384 . V_386 )
return 0 ;
return V_384 . V_386 ( V_382 ) ;
}
static int F_257 ( struct V_14 * V_16 ,
struct V_383 * V_384 )
{
if ( V_384 -> V_16 == V_16 )
V_384 -> V_386 = F_255 ;
return 0 ;
}
static int F_258 ( struct V_14 * V_19 , int V_388 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
F_55 ( L_104 ,
V_11 , V_19 ? V_19 -> V_59 : L_98 , V_388 ) ;
F_12 (bond, slave, iter) {
F_55 ( L_105 ,
V_22 , V_22 -> V_16 -> V_48 -> V_389 ) ;
V_26 = F_119 ( V_22 -> V_16 , V_388 ) ;
if ( V_26 ) {
F_55 ( L_106 , V_26 , V_22 -> V_16 -> V_59 ) ;
goto V_27;
}
}
V_19 -> V_180 = V_388 ;
return 0 ;
V_27:
F_12 (bond, rollback_slave, iter) {
int V_390 ;
if ( V_23 == V_22 )
break;
V_390 = F_119 ( V_23 -> V_16 , V_19 -> V_180 ) ;
if ( V_390 ) {
F_55 ( L_107 ,
V_390 , V_23 -> V_16 -> V_59 ) ;
}
}
return V_26 ;
}
static int F_259 ( struct V_14 * V_19 , void * V_161 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_160 * V_391 = V_161 , V_392 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
if ( V_11 -> V_29 . V_1 == V_9 )
return F_260 ( V_19 , V_161 ) ;
F_55 ( L_108 ,
V_11 , V_19 ? V_19 -> V_59 : L_98 ) ;
if ( V_11 -> V_29 . V_108 &&
V_11 -> V_29 . V_1 == V_4 )
return 0 ;
if ( ! F_261 ( V_391 -> V_183 ) )
return - V_393 ;
F_12 (bond, slave, iter) {
F_55 ( L_109 , V_22 , V_22 -> V_16 -> V_59 ) ;
V_26 = F_120 ( V_22 -> V_16 , V_161 ) ;
if ( V_26 ) {
F_55 ( L_106 , V_26 , V_22 -> V_16 -> V_59 ) ;
goto V_27;
}
}
memcpy ( V_19 -> V_85 , V_391 -> V_183 , V_19 -> V_84 ) ;
return 0 ;
V_27:
memcpy ( V_392 . V_183 , V_19 -> V_85 , V_19 -> V_84 ) ;
V_392 . V_184 = V_19 -> type ;
F_12 (bond, rollback_slave, iter) {
int V_390 ;
if ( V_23 == V_22 )
break;
V_390 = F_120 ( V_23 -> V_16 , & V_392 ) ;
if ( V_390 ) {
F_55 ( L_107 ,
V_390 , V_23 -> V_16 -> V_59 ) ;
}
}
return V_26 ;
}
static void F_262 ( struct V_10 * V_11 , struct V_12 * V_13 , int V_216 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_163 = V_216 ;
F_158 (bond, slave, iter) {
if ( -- V_163 < 0 ) {
if ( F_263 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
}
V_163 = V_216 ;
F_158 (bond, slave, iter) {
if ( -- V_163 < 0 )
break;
if ( F_263 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
F_264 ( V_13 ) ;
}
static T_3 F_265 ( struct V_10 * V_11 )
{
T_3 V_216 ;
struct V_394 V_395 ;
int V_396 = V_11 -> V_29 . V_396 ;
switch ( V_396 ) {
case 0 :
V_216 = F_266 () ;
break;
case 1 :
V_216 = V_11 -> V_397 ;
break;
default:
V_395 =
V_11 -> V_29 . V_395 ;
V_216 = F_267 ( V_11 -> V_397 ,
V_395 ) ;
break;
}
V_11 -> V_397 ++ ;
return V_216 ;
}
static int F_268 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_304 * V_305 = F_225 ( V_13 ) ;
struct V_22 * V_22 ;
T_3 V_216 ;
if ( V_305 -> V_258 == V_398 && V_13 -> V_258 == F_194 ( V_265 ) ) {
V_22 = F_62 ( V_11 -> V_68 ) ;
if ( V_22 && F_263 ( V_22 ) )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_262 ( V_11 , V_13 , 0 ) ;
} else {
V_216 = F_265 ( V_11 ) ;
F_262 ( V_11 , V_13 , V_216 % V_11 -> V_201 ) ;
}
return V_399 ;
}
static int F_269 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 ;
V_22 = F_62 ( V_11 -> V_68 ) ;
if ( V_22 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_264 ( V_13 ) ;
return V_399 ;
}
static int F_270 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_262 ( V_11 , V_13 , F_230 ( V_11 , V_13 , V_11 -> V_201 ) ) ;
return V_399 ;
}
static int F_271 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
F_158 (bond, slave, iter) {
if ( F_272 ( V_11 , V_22 ) )
break;
if ( F_59 ( V_22 -> V_16 ) && V_22 -> V_30 == V_31 ) {
struct V_12 * V_400 = F_273 ( V_13 , V_149 ) ;
if ( ! V_400 ) {
F_167 ( L_110 ,
V_19 -> V_59 , V_401 ) ;
continue;
}
F_2 ( V_11 , V_400 , V_22 -> V_16 ) ;
}
}
if ( V_22 && F_59 ( V_22 -> V_16 ) && V_22 -> V_30 == V_31 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_264 ( V_13 ) ;
return V_399 ;
}
static inline int F_274 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
if ( ! V_13 -> V_17 )
return 1 ;
F_158 (bond, slave, iter) {
if ( V_22 -> V_178 == V_13 -> V_17 ) {
if ( F_263 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return 0 ;
}
break;
}
}
return 1 ;
}
static T_2 F_275 ( struct V_14 * V_16 , struct V_12 * V_13 ,
void * V_402 , T_10 V_403 )
{
T_2 V_404 = F_276 ( V_13 ) ? F_277 ( V_13 ) : 0 ;
F_4 ( V_13 ) -> V_18 = V_13 -> V_17 ;
if ( F_5 ( V_404 >= V_16 -> V_405 ) ) {
do {
V_404 -= V_16 -> V_405 ;
} while ( V_404 >= V_16 -> V_405 );
}
return V_404 ;
}
static T_11 F_278 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
if ( F_279 ( V_11 -> V_29 . V_1 ) ) {
if ( ! F_274 ( V_11 , V_13 ) )
return V_399 ;
}
switch ( V_11 -> V_29 . V_1 ) {
case V_3 :
return F_268 ( V_13 , V_16 ) ;
case V_4 :
return F_269 ( V_13 , V_16 ) ;
case V_5 :
return F_270 ( V_13 , V_16 ) ;
case V_6 :
return F_271 ( V_13 , V_16 ) ;
case V_7 :
return F_280 ( V_13 , V_16 ) ;
case V_9 :
case V_8 :
return F_281 ( V_13 , V_16 ) ;
default:
F_113 ( L_111 ,
V_16 -> V_59 , V_11 -> V_29 . V_1 ) ;
F_282 ( 1 ) ;
F_264 ( V_13 ) ;
return V_399 ;
}
}
static T_11 F_283 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
T_11 V_147 = V_399 ;
if ( F_5 ( F_284 ( V_16 ) ) )
return V_406 ;
F_61 () ;
if ( F_19 ( V_11 ) )
V_147 = F_278 ( V_13 , V_16 ) ;
else
F_264 ( V_13 ) ;
F_63 () ;
return V_147 ;
}
static int F_285 ( struct V_14 * V_19 ,
struct V_32 * V_33 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
unsigned long V_35 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
V_33 -> V_37 = V_38 ;
V_33 -> V_407 = V_408 ;
F_236 ( & V_11 -> V_206 ) ;
F_12 (bond, slave, iter) {
if ( F_286 ( V_22 ) ) {
if ( V_22 -> V_35 != V_36 )
V_35 += V_22 -> V_35 ;
if ( V_33 -> V_37 == V_38 &&
V_22 -> V_37 != V_38 )
V_33 -> V_37 = V_22 -> V_37 ;
}
}
F_287 ( V_33 , V_35 ? : V_36 ) ;
F_237 ( & V_11 -> V_206 ) ;
return 0 ;
}
static void F_288 ( struct V_14 * V_19 ,
struct V_409 * V_410 )
{
F_289 ( V_410 -> V_411 , V_412 , sizeof( V_410 -> V_411 ) ) ;
F_289 ( V_410 -> V_413 , V_414 , sizeof( V_410 -> V_413 ) ) ;
snprintf ( V_410 -> V_415 , sizeof( V_410 -> V_415 ) , L_112 ,
V_416 ) ;
}
static void F_290 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_11 -> V_72 )
F_291 ( V_11 -> V_72 ) ;
F_292 ( V_19 ) ;
}
void F_293 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_294 ( & V_11 -> V_206 ) ;
F_294 ( & V_11 -> V_110 ) ;
V_11 -> V_29 = V_417 ;
V_11 -> V_16 = V_19 ;
F_118 ( V_19 ) ;
V_19 -> V_48 = & V_418 ;
V_19 -> V_55 = & V_419 ;
V_19 -> V_420 = F_290 ;
F_295 ( V_19 , & V_421 ) ;
V_19 -> V_422 = 0 ;
V_19 -> V_81 |= V_296 | V_423 ;
V_19 -> V_139 |= V_187 ;
V_19 -> V_139 &= ~ ( V_129 | V_170 ) ;
V_19 -> V_123 |= V_125 ;
V_19 -> V_123 |= V_424 ;
V_19 -> V_123 |= V_425 ;
V_19 -> V_426 = V_131 |
V_427 |
V_428 |
V_429 ;
V_19 -> V_426 &= ~ ( V_430 & ~ V_431 ) ;
V_19 -> V_123 |= V_19 -> V_426 ;
}
static void F_296 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_83 ( V_19 ) ;
F_12 (bond, slave, iter)
F_144 ( V_19 , V_22 -> V_16 , true ) ;
F_66 ( L_113 , V_19 -> V_59 ) ;
F_297 ( & V_11 -> V_432 ) ;
F_298 ( V_11 ) ;
}
static int F_299 ( struct V_433 * V_29 )
{
int V_434 , V_435 , V_436 , V_163 ;
struct V_358 V_359 ;
const struct V_358 * V_437 ;
int V_438 ;
if ( V_1 ) {
F_251 ( & V_359 , V_1 ) ;
V_437 = F_300 ( F_301 ( V_439 ) , & V_359 ) ;
if ( ! V_437 ) {
F_113 ( L_114 , V_1 ) ;
return - V_172 ;
}
V_212 = V_437 -> V_440 ;
}
if ( V_441 ) {
if ( ( V_212 != V_5 ) &&
( V_212 != V_7 ) ) {
F_66 ( L_115 ,
F_1 ( V_212 ) ) ;
} else {
F_251 ( & V_359 , V_441 ) ;
V_437 = F_300 ( F_301 ( V_442 ) ,
& V_359 ) ;
if ( ! V_437 ) {
F_113 ( L_116 ,
V_441 ) ;
return - V_172 ;
}
V_443 = V_437 -> V_440 ;
}
}
if ( V_444 ) {
if ( V_212 != V_7 ) {
F_66 ( L_117 ,
F_1 ( V_212 ) ) ;
} else {
F_251 ( & V_359 , V_444 ) ;
V_437 = F_300 ( F_301 ( V_445 ) ,
& V_359 ) ;
if ( ! V_437 ) {
F_113 ( L_118 ,
V_444 ) ;
return - V_172 ;
}
V_446 = V_437 -> V_440 ;
}
}
if ( V_447 ) {
F_251 ( & V_359 , V_444 ) ;
V_437 = F_300 ( F_301 ( V_448 ) ,
& V_359 ) ;
if ( ! V_437 ) {
F_113 ( L_119 , V_447 ) ;
return - V_172 ;
}
V_29 -> V_447 = V_437 -> V_440 ;
if ( V_212 != V_7 )
F_112 ( L_120 ) ;
} else {
V_29 -> V_447 = V_449 ;
}
if ( V_450 < 0 ) {
F_112 ( L_121 ,
V_450 , 0 , V_451 , V_452 ) ;
V_450 = V_452 ;
}
if ( V_105 < 0 ) {
F_112 ( L_122 ,
V_105 , V_451 ) ;
V_105 = 0 ;
}
if ( V_98 < 0 ) {
F_112 ( L_123 ,
V_98 , V_451 ) ;
V_98 = 0 ;
}
if ( V_223 < 0 ) {
F_112 ( L_124 ,
V_223 , V_451 ) ;
V_223 = 0 ;
}
if ( ( V_53 != 0 ) && ( V_53 != 1 ) ) {
F_112 ( L_125 ,
V_53 ) ;
V_53 = 1 ;
}
if ( V_109 < 0 || V_109 > 255 ) {
F_112 ( L_126 ,
V_109 ) ;
V_109 = 1 ;
}
if ( F_302 ( V_212 ) ) {
if ( ! V_105 ) {
F_112 ( L_127 ) ;
F_112 ( L_128 ) ;
V_105 = V_453 ;
}
}
if ( V_454 < 1 || V_454 > 255 ) {
F_112 ( L_129 ,
V_454 , V_455 ) ;
V_454 = V_455 ;
}
if ( ( V_456 != 0 ) && ( V_456 != 1 ) ) {
F_112 ( L_130 ,
V_456 ) ;
V_456 = 0 ;
}
if ( V_113 < 0 || V_113 > 255 ) {
F_112 ( L_131 ,
V_113 , V_457 ) ;
V_113 = V_457 ;
}
F_303 ( & V_359 , V_396 ) ;
if ( ! F_300 ( F_301 ( V_458 ) , & V_359 ) ) {
F_112 ( L_132 ,
V_396 , V_459 ) ;
V_396 = 1 ;
}
if ( V_212 == V_9 ) {
F_304 ( L_133 ,
V_98 ) ;
}
if ( ! V_105 ) {
if ( V_98 || V_223 ) {
F_112 ( L_134 ,
V_98 , V_223 ) ;
}
} else {
if ( V_191 ) {
F_112 ( L_135 ,
V_105 , V_191 ) ;
V_191 = 0 ;
}
if ( ( V_98 % V_105 ) != 0 ) {
F_112 ( L_136 ,
V_98 , V_105 , ( V_98 / V_105 ) * V_105 ) ;
}
V_98 /= V_105 ;
if ( ( V_223 % V_105 ) != 0 ) {
F_112 ( L_137 ,
V_223 , V_105 ,
( V_223 / V_105 ) * V_105 ) ;
}
V_223 /= V_105 ;
}
if ( V_191 < 0 ) {
F_112 ( L_138 ,
V_191 , V_451 ) ;
V_191 = 0 ;
}
for ( V_460 = 0 , V_163 = 0 ;
( V_460 < V_192 ) && V_461 [ V_163 ] ; V_163 ++ ) {
T_8 V_228 ;
if ( ! F_305 ( V_461 [ V_163 ] , - 1 , ( T_5 * ) & V_228 , - 1 , NULL ) ||
F_306 ( V_228 ) ) {
F_112 ( L_139 ,
V_461 [ V_163 ] ) ;
V_191 = 0 ;
} else {
if ( F_185 ( V_462 , V_228 ) == - 1 )
V_462 [ V_460 ++ ] = V_228 ;
else
F_112 ( L_140 ,
& V_228 ) ;
}
}
if ( V_191 && ! V_460 ) {
F_112 ( L_141 ,
V_191 ) ;
V_191 = 0 ;
}
if ( V_247 ) {
if ( ! V_191 ) {
F_113 ( L_142 ) ;
return - V_172 ;
}
F_251 ( & V_359 , V_247 ) ;
V_437 = F_300 ( F_301 ( V_463 ) ,
& V_359 ) ;
if ( ! V_437 ) {
F_113 ( L_143 ,
V_247 ) ;
return - V_172 ;
}
V_434 = V_437 -> V_440 ;
} else {
V_434 = 0 ;
}
V_438 = 0 ;
if ( V_464 ) {
F_251 ( & V_359 , V_464 ) ;
V_437 = F_300 ( F_301 ( V_465 ) ,
& V_359 ) ;
if ( ! V_437 ) {
F_113 ( L_144 ,
V_464 ) ;
V_438 = 0 ;
} else {
V_438 = V_437 -> V_440 ;
}
}
if ( V_105 ) {
F_66 ( L_145 , V_105 ) ;
} else if ( V_191 ) {
V_437 = F_307 ( V_463 ,
V_434 ) ;
F_66 ( L_146 ,
V_191 , V_437 -> string , V_460 ) ;
for ( V_163 = 0 ; V_163 < V_460 ; V_163 ++ )
F_308 ( L_147 , V_461 [ V_163 ] ) ;
F_308 ( L_148 ) ;
} else if ( V_450 ) {
F_55 ( L_149 ) ;
}
if ( V_194 && ! F_34 ( V_212 ) ) {
F_112 ( L_150 ,
V_194 , F_1 ( V_212 ) ) ;
V_194 = NULL ;
}
if ( V_194 && V_93 ) {
F_251 ( & V_359 , V_93 ) ;
V_437 = F_300 ( F_301 ( V_466 ) ,
& V_359 ) ;
if ( ! V_437 ) {
F_113 ( L_151 ,
V_93 ) ;
return - V_172 ;
}
V_436 = V_437 -> V_440 ;
} else {
V_436 = V_467 ;
}
if ( V_108 ) {
F_251 ( & V_359 , V_108 ) ;
V_437 = F_300 ( F_301 ( V_468 ) ,
& V_359 ) ;
if ( ! V_437 ) {
F_113 ( L_152 ,
V_108 ) ;
return - V_172 ;
}
V_435 = V_437 -> V_440 ;
if ( V_212 != V_4 )
F_112 ( L_153 ) ;
} else {
V_435 = V_469 ;
}
if ( V_470 == 0 ) {
F_112 ( L_154 ,
V_451 , V_471 ) ;
V_470 = V_471 ;
}
V_29 -> V_1 = V_212 ;
V_29 -> V_307 = V_443 ;
V_29 -> V_105 = V_105 ;
V_29 -> V_109 = V_109 ;
V_29 -> V_191 = V_191 ;
V_29 -> V_247 = V_434 ;
V_29 -> V_464 = V_438 ;
V_29 -> V_98 = V_98 ;
V_29 -> V_223 = V_223 ;
V_29 -> V_53 = V_53 ;
V_29 -> V_446 = V_446 ;
V_29 -> V_194 [ 0 ] = 0 ;
V_29 -> V_93 = V_436 ;
V_29 -> V_108 = V_435 ;
V_29 -> V_454 = V_454 ;
V_29 -> V_456 = V_456 ;
V_29 -> V_113 = V_113 ;
V_29 -> V_472 = V_472 ;
V_29 -> V_470 = V_470 ;
V_29 -> V_396 = V_396 ;
if ( V_396 > 0 ) {
V_29 -> V_395 =
V_394 ( V_396 ) ;
} else {
V_29 -> V_395 =
(struct V_394 ) { 0 } ;
}
if ( V_194 ) {
strncpy ( V_29 -> V_194 , V_194 , V_60 ) ;
V_29 -> V_194 [ V_60 - 1 ] = 0 ;
}
memcpy ( V_29 -> V_245 , V_462 , sizeof( V_462 ) ) ;
return 0 ;
}
static void F_309 ( struct V_14 * V_16 ,
struct V_473 * V_404 ,
void * V_474 )
{
F_310 ( & V_404 -> V_475 ,
& V_476 ) ;
}
static void F_311 ( struct V_14 * V_16 )
{
F_310 ( & V_16 -> V_477 ,
& V_478 ) ;
F_312 ( V_16 , F_309 , NULL ) ;
V_16 -> V_479 = & V_480 ;
}
static int F_313 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_481 * V_482 = F_314 ( F_180 ( V_19 ) , V_483 ) ;
struct V_484 * V_485 = & ( F_315 ( V_11 ) ) ;
F_55 ( L_155 , V_19 -> V_59 ) ;
F_316 ( & ( V_485 -> V_486 ) ) ;
F_316 ( & ( V_485 -> V_487 ) ) ;
V_11 -> V_72 = F_317 ( V_19 -> V_59 ) ;
if ( ! V_11 -> V_72 )
return - V_119 ;
F_311 ( V_19 ) ;
F_318 ( & V_11 -> V_432 , & V_482 -> V_488 ) ;
F_319 ( V_11 ) ;
F_320 ( V_11 ) ;
if ( F_321 ( V_19 -> V_85 ) &&
V_19 -> V_86 == V_489 )
F_143 ( V_19 ) ;
return 0 ;
}
unsigned int F_322 ( void )
{
return V_454 ;
}
int F_323 ( struct V_360 * V_360 , const char * V_59 )
{
struct V_14 * V_19 ;
int V_26 ;
F_324 () ;
V_19 = F_325 ( sizeof( struct V_10 ) ,
V_59 ? V_59 : L_156 ,
F_293 , V_454 ) ;
if ( ! V_19 ) {
F_113 ( L_157 , V_59 ) ;
F_43 () ;
return - V_119 ;
}
F_326 ( V_19 , V_360 ) ;
V_19 -> V_490 = & V_491 ;
V_26 = F_327 ( V_19 ) ;
F_23 ( V_19 ) ;
F_43 () ;
if ( V_26 < 0 )
F_290 ( V_19 ) ;
return V_26 ;
}
static int T_12 F_328 ( struct V_360 * V_360 )
{
struct V_481 * V_482 = F_314 ( V_360 , V_483 ) ;
V_482 -> V_360 = V_360 ;
F_329 ( & V_482 -> V_488 ) ;
F_330 ( V_482 ) ;
F_331 ( V_482 ) ;
return 0 ;
}
static void T_13 F_332 ( struct V_360 * V_360 )
{
struct V_481 * V_482 = F_314 ( V_360 , V_483 ) ;
struct V_10 * V_11 , * V_492 ;
F_333 ( V_493 ) ;
F_334 ( V_482 ) ;
F_335 ( V_482 ) ;
F_324 () ;
F_336 (bond, tmp_bond, &bn->dev_list, bond_list)
F_337 ( V_11 -> V_16 , & V_493 ) ;
F_338 ( & V_493 ) ;
F_43 () ;
}
static int T_14 F_339 ( void )
{
int V_163 ;
int V_26 ;
F_66 ( L_158 , V_494 ) ;
V_26 = F_299 ( & V_417 ) ;
if ( V_26 )
goto V_120;
V_26 = F_340 ( & V_495 ) ;
if ( V_26 )
goto V_120;
V_26 = F_341 () ;
if ( V_26 )
goto V_496;
F_342 () ;
for ( V_163 = 0 ; V_163 < V_450 ; V_163 ++ ) {
V_26 = F_323 ( & V_497 , NULL ) ;
if ( V_26 )
goto V_67;
}
F_343 ( & V_498 ) ;
V_120:
return V_26 ;
V_67:
F_344 () ;
F_345 () ;
V_496:
F_346 ( & V_495 ) ;
goto V_120;
}
static void T_15 F_347 ( void )
{
F_348 ( & V_498 ) ;
F_344 () ;
F_345 () ;
F_346 ( & V_495 ) ;
#ifdef F_133
F_349 ( F_350 ( & V_499 ) ) ;
#endif
}
