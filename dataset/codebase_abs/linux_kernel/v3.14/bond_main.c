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
V_79 -> V_103 = V_103 ;
if ( V_79 -> V_30 == V_44 ) {
if ( F_34 ( V_11 -> V_29 . V_1 ) ) {
F_66 ( L_16 ,
V_11 -> V_16 -> V_59 , V_79 -> V_16 -> V_59 ,
( V_11 -> V_29 . V_98 - V_79 -> V_99 ) * V_11 -> V_29 . V_104 ) ;
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
V_105 ) ;
if ( V_79 )
F_71 ( V_79 ,
V_105 ) ;
} else {
F_72 ( V_11 -> V_68 , V_79 ) ;
}
if ( V_11 -> V_29 . V_1 == V_4 ) {
if ( V_80 )
F_70 ( V_80 ,
V_105 ) ;
if ( V_79 ) {
bool V_106 = false ;
F_71 ( V_79 ,
V_105 ) ;
if ( V_11 -> V_29 . V_107 )
F_56 ( V_11 , V_79 ,
V_80 ) ;
if ( F_30 ( V_11 -> V_16 ) ) {
V_11 -> V_100 =
V_11 -> V_29 . V_108 ;
V_106 =
F_60 ( V_11 ) ;
}
F_73 ( & V_11 -> V_109 ) ;
F_42 ( V_110 , V_11 -> V_16 ) ;
if ( V_106 )
F_42 ( V_111 ,
V_11 -> V_16 ) ;
F_74 ( & V_11 -> V_109 ) ;
}
}
if ( F_30 ( V_11 -> V_16 ) && ( V_11 -> V_29 . V_112 > 0 ) &&
( ( F_34 ( V_11 -> V_29 . V_1 ) && V_79 ) ||
V_11 -> V_29 . V_1 == V_3 ) ) {
V_11 -> V_74 = V_11 -> V_29 . V_112 ;
F_41 ( V_11 -> V_72 , & V_11 -> V_71 , 1 ) ;
}
}
void F_75 ( struct V_10 * V_11 )
{
struct V_22 * V_113 ;
int V_114 ;
V_113 = F_58 ( V_11 ) ;
if ( V_113 != V_11 -> V_68 ) {
F_65 ( V_11 , V_113 ) ;
V_114 = F_18 ( V_11 ) ;
if ( ! V_114 )
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
struct V_115 * V_116 ;
int V_67 = 0 ;
V_116 = F_77 ( sizeof( * V_116 ) , V_117 ) ;
V_67 = - V_118 ;
if ( ! V_116 )
goto V_119;
V_67 = F_78 ( V_116 , V_22 -> V_16 , V_117 ) ;
if ( V_67 ) {
F_79 ( V_116 ) ;
goto V_119;
}
V_22 -> V_116 = V_116 ;
V_119:
return V_67 ;
}
static inline void F_80 ( struct V_22 * V_22 )
{
struct V_115 * V_116 = V_22 -> V_116 ;
if ( ! V_116 )
return;
V_22 -> V_116 = NULL ;
F_81 ( V_116 ) ;
}
static inline bool F_82 ( struct V_14 * V_15 )
{
if ( V_15 -> V_120 & V_121 )
return false ;
if ( ! V_15 -> V_48 -> V_122 )
return false ;
return true ;
}
static void F_83 ( struct V_14 * V_19 )
{
}
static void F_84 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter)
if ( F_59 ( V_22 -> V_16 ) )
F_80 ( V_22 ) ;
}
static int F_85 ( struct V_14 * V_16 , struct V_123 * V_124 , T_6 V_125 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_67 = 0 ;
F_12 (bond, slave, iter) {
V_67 = F_76 ( V_22 ) ;
if ( V_67 ) {
F_84 ( V_16 ) ;
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
static void F_84 ( struct V_14 * V_19 )
{
}
static T_7 F_86 ( struct V_14 * V_16 ,
T_7 V_126 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_24 * V_25 ;
T_7 V_127 ;
struct V_22 * V_22 ;
if ( ! F_19 ( V_11 ) ) {
V_126 |= V_128 ;
return V_126 ;
}
V_127 = V_126 ;
V_126 &= ~ V_129 ;
V_126 |= V_130 ;
F_12 (bond, slave, iter) {
V_126 = F_87 ( V_126 ,
V_22 -> V_16 -> V_126 ,
V_127 ) ;
}
V_126 = F_88 ( V_126 , V_127 ) ;
return V_126 ;
}
static void F_89 ( struct V_10 * V_11 )
{
unsigned int V_81 , V_131 = V_132 ;
T_7 V_133 = V_134 ;
struct V_14 * V_19 = V_11 -> V_16 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
unsigned short V_135 = V_136 ;
unsigned int V_137 = V_138 ;
T_2 V_139 = V_140 ;
if ( ! F_19 ( V_11 ) )
goto V_141;
F_12 (bond, slave, iter) {
V_133 = F_87 ( V_133 ,
V_22 -> V_16 -> V_133 , V_134 ) ;
V_131 &= V_22 -> V_16 -> V_120 ;
if ( V_22 -> V_16 -> V_142 > V_135 )
V_135 = V_22 -> V_16 -> V_142 ;
V_137 = F_90 ( V_137 , V_22 -> V_16 -> V_137 ) ;
V_139 = F_90 ( V_139 , V_22 -> V_16 -> V_139 ) ;
}
V_141:
V_19 -> V_133 = V_133 ;
V_19 -> V_142 = V_135 ;
V_19 -> V_139 = V_139 ;
F_91 ( V_19 , V_137 ) ;
V_81 = V_19 -> V_120 & ~ V_132 ;
V_19 -> V_120 = V_81 | V_131 ;
F_92 ( V_19 ) ;
}
static void F_93 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
V_19 -> V_143 = V_15 -> V_143 ;
V_19 -> type = V_15 -> type ;
V_19 -> V_142 = V_15 -> V_142 ;
V_19 -> V_84 = V_15 -> V_84 ;
memcpy ( V_19 -> V_144 , V_15 -> V_144 ,
V_15 -> V_84 ) ;
}
static bool F_94 ( struct V_12 * V_13 ,
struct V_22 * V_22 ,
struct V_10 * V_11 )
{
if ( F_95 ( V_22 ) ) {
if ( V_11 -> V_29 . V_1 == V_9 &&
V_13 -> V_145 != V_146 &&
V_13 -> V_145 != V_147 )
return false ;
return true ;
}
return false ;
}
static T_8 F_96 ( struct V_12 * * V_148 )
{
struct V_12 * V_13 = * V_148 ;
struct V_22 * V_22 ;
struct V_10 * V_11 ;
int (* F_97)( const struct V_12 * , struct V_10 * ,
struct V_22 * );
int V_149 = V_150 ;
V_13 = F_98 ( V_13 , V_117 ) ;
if ( F_5 ( ! V_13 ) )
return V_151 ;
* V_148 = V_13 ;
V_22 = F_99 ( V_13 -> V_16 ) ;
V_11 = V_22 -> V_11 ;
if ( V_11 -> V_29 . V_152 )
V_22 -> V_16 -> V_153 = V_103 ;
F_97 = F_100 ( V_11 -> F_97 ) ;
if ( F_97 ) {
V_149 = F_97 ( V_13 , V_11 , V_22 ) ;
if ( V_149 == V_151 ) {
F_101 ( V_13 ) ;
return V_149 ;
}
}
if ( F_94 ( V_13 , V_22 , V_11 ) ) {
return V_154 ;
}
V_13 -> V_16 = V_11 -> V_16 ;
if ( V_11 -> V_29 . V_1 == V_9 &&
V_11 -> V_16 -> V_120 & V_155 &&
V_13 -> V_145 == V_156 ) {
if ( F_5 ( F_102 ( V_13 ,
V_13 -> V_157 - F_103 ( V_13 ) ) ) ) {
F_104 ( V_13 ) ;
return V_151 ;
}
memcpy ( F_105 ( V_13 ) -> V_158 , V_11 -> V_16 -> V_85 , V_77 ) ;
}
return V_149 ;
}
static int F_106 ( struct V_14 * V_19 ,
struct V_14 * V_15 ,
struct V_22 * V_22 )
{
int V_67 ;
V_67 = F_107 ( V_15 , V_19 , V_22 ) ;
if ( V_67 )
return V_67 ;
V_15 -> V_81 |= V_159 ;
F_108 ( V_160 , V_15 , V_159 , V_161 ) ;
return 0 ;
}
static void F_109 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
F_110 ( V_15 , V_19 ) ;
V_15 -> V_81 &= ~ V_159 ;
F_108 ( V_160 , V_15 , V_159 , V_161 ) ;
}
int F_111 ( struct V_14 * V_19 , struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
const struct V_46 * V_47 = V_15 -> V_48 ;
struct V_22 * V_162 = NULL , * V_163 ;
struct V_164 V_165 ;
int V_166 ;
int V_26 = 0 , V_167 ;
if ( ! V_11 -> V_29 . V_53 &&
V_15 -> V_55 -> V_56 == NULL &&
V_47 -> V_57 == NULL ) {
F_112 ( L_20 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
}
if ( V_15 -> V_81 & V_159 ) {
F_55 ( L_21 ) ;
return - V_168 ;
}
if ( V_19 == V_15 ) {
F_113 ( L_22 , V_19 -> V_59 ) ;
return - V_169 ;
}
if ( V_15 -> V_126 & V_128 ) {
F_55 ( L_23 , V_15 -> V_59 ) ;
if ( F_114 ( V_19 ) ) {
F_113 ( L_24 ,
V_19 -> V_59 , V_15 -> V_59 , V_19 -> V_59 ) ;
return - V_169 ;
} else {
F_112 ( L_25 ,
V_19 -> V_59 , V_15 -> V_59 ,
V_15 -> V_59 , V_19 -> V_59 ) ;
}
} else {
F_55 ( L_26 , V_15 -> V_59 ) ;
}
if ( ( V_15 -> V_81 & V_170 ) ) {
F_113 ( L_27 ,
V_15 -> V_59 ) ;
V_26 = - V_169 ;
goto V_171;
}
if ( ! F_19 ( V_11 ) ) {
if ( V_19 -> type != V_15 -> type ) {
F_55 ( L_28 ,
V_19 -> V_59 ,
V_19 -> type , V_15 -> type ) ;
V_26 = F_42 ( V_172 ,
V_19 ) ;
V_26 = F_115 ( V_26 ) ;
if ( V_26 ) {
F_113 ( L_29 ,
V_19 -> V_59 ) ;
V_26 = - V_168 ;
goto V_171;
}
F_116 ( V_19 ) ;
F_117 ( V_19 ) ;
if ( V_15 -> type != V_173 )
F_93 ( V_19 , V_15 ) ;
else {
F_118 ( V_19 ) ;
V_19 -> V_120 &= ~ V_174 ;
}
F_42 ( V_175 ,
V_19 ) ;
}
} else if ( V_19 -> type != V_15 -> type ) {
F_113 ( L_30 ,
V_15 -> V_59 ,
V_15 -> type , V_19 -> type ) ;
V_26 = - V_176 ;
goto V_171;
}
if ( V_47 -> V_177 == NULL ) {
if ( ! F_19 ( V_11 ) ) {
F_119 ( L_31 ,
V_19 -> V_59 ) ;
if ( V_11 -> V_29 . V_1 == V_4 ) {
V_11 -> V_29 . V_107 = V_178 ;
F_119 ( L_32 ,
V_19 -> V_59 ) ;
}
} else if ( V_11 -> V_29 . V_107 != V_178 ) {
F_113 ( L_33 ,
V_19 -> V_59 ) ;
V_26 = - V_179 ;
goto V_171;
}
}
F_42 ( V_180 , V_15 ) ;
if ( ! F_19 ( V_11 ) &&
V_11 -> V_16 -> V_86 == V_181 )
F_54 ( V_11 -> V_16 , V_15 ) ;
V_162 = F_77 ( sizeof( struct V_22 ) , V_161 ) ;
if ( ! V_162 ) {
V_26 = - V_118 ;
goto V_171;
}
V_162 -> V_182 = 0 ;
V_162 -> V_183 = V_15 -> V_184 ;
V_26 = F_120 ( V_15 , V_11 -> V_16 -> V_184 ) ;
if ( V_26 ) {
F_55 ( L_34 , V_26 ) ;
goto V_185;
}
memcpy ( V_162 -> V_186 , V_15 -> V_85 , V_77 ) ;
if ( ! V_11 -> V_29 . V_107 ||
V_11 -> V_29 . V_1 != V_4 ) {
memcpy ( V_165 . V_187 , V_19 -> V_85 , V_19 -> V_84 ) ;
V_165 . V_188 = V_15 -> type ;
V_26 = F_121 ( V_15 , & V_165 ) ;
if ( V_26 ) {
F_55 ( L_35 , V_26 ) ;
goto V_189;
}
}
V_26 = F_122 ( V_15 ) ;
if ( V_26 ) {
F_55 ( L_36 , V_15 -> V_59 ) ;
goto V_190;
}
V_162 -> V_11 = V_11 ;
V_162 -> V_16 = V_15 ;
V_15 -> V_120 |= V_191 ;
if ( F_16 ( V_11 ) ) {
V_26 = F_123 ( V_11 , V_162 ) ;
if ( V_26 )
goto V_192;
}
if ( ! F_34 ( V_11 -> V_29 . V_1 ) ) {
if ( V_19 -> V_81 & V_82 ) {
V_26 = F_35 ( V_15 , 1 ) ;
if ( V_26 )
goto V_192;
}
if ( V_19 -> V_81 & V_83 ) {
V_26 = F_37 ( V_15 , 1 ) ;
if ( V_26 )
goto V_192;
}
F_50 ( V_19 ) ;
F_124 ( V_15 , V_19 ) ;
F_125 ( V_15 , V_19 ) ;
F_53 ( V_19 ) ;
}
if ( V_11 -> V_29 . V_1 == V_7 ) {
T_5 V_76 [ V_77 ] = V_78 ;
F_126 ( V_15 , V_76 ) ;
}
V_26 = F_127 ( V_15 , V_19 ) ;
if ( V_26 ) {
F_113 ( L_37 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
goto V_192;
}
V_163 = F_128 ( V_11 ) ;
V_162 -> V_99 = 0 ;
V_162 -> V_193 = 0 ;
F_24 ( V_162 ) ;
V_162 -> V_194 = V_103 -
( F_129 ( V_11 -> V_29 . V_152 ) + 1 ) ;
for ( V_167 = 0 ; V_167 < V_195 ; V_167 ++ )
V_162 -> V_196 [ V_167 ] = V_162 -> V_194 ;
if ( V_11 -> V_29 . V_104 && ! V_11 -> V_29 . V_53 ) {
V_166 = F_28 ( V_11 , V_15 , 1 ) ;
if ( ( V_166 == - 1 ) && ! V_11 -> V_29 . V_152 ) {
F_112 ( L_38 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
} else if ( V_166 == - 1 ) {
F_112 ( L_39 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
}
}
if ( V_11 -> V_29 . V_104 ) {
if ( F_28 ( V_11 , V_15 , 0 ) == V_54 ) {
if ( V_11 -> V_29 . V_98 ) {
V_162 -> V_30 = V_44 ;
V_162 -> V_99 = V_11 -> V_29 . V_98 ;
} else {
V_162 -> V_30 = V_31 ;
}
} else {
V_162 -> V_30 = V_43 ;
}
} else if ( V_11 -> V_29 . V_152 ) {
V_162 -> V_30 = ( F_21 ( V_15 ) ?
V_31 : V_43 ) ;
} else {
V_162 -> V_30 = V_31 ;
}
if ( V_162 -> V_30 != V_43 )
V_162 -> V_103 = V_103 ;
F_55 ( L_40 ,
V_162 -> V_30 == V_43 ? L_41 :
( V_162 -> V_30 == V_31 ? L_42 : L_43 ) ) ;
if ( F_34 ( V_11 -> V_29 . V_1 ) && V_11 -> V_29 . V_197 [ 0 ] ) {
if ( strcmp ( V_11 -> V_29 . V_197 , V_162 -> V_16 -> V_59 ) == 0 ) {
V_11 -> V_90 = V_162 ;
V_11 -> V_92 = true ;
}
}
switch ( V_11 -> V_29 . V_1 ) {
case V_4 :
F_70 ( V_162 ,
V_105 ) ;
break;
case V_7 :
F_70 ( V_162 , V_105 ) ;
if ( ! V_163 ) {
F_130 ( V_162 ) . V_198 = 1 ;
F_131 ( V_11 , 1000 / V_199 ) ;
} else {
F_130 ( V_162 ) . V_198 =
F_130 ( V_163 ) . V_198 + 1 ;
}
F_132 ( V_162 ) ;
break;
case V_8 :
case V_9 :
F_133 ( V_162 ) ;
F_70 ( V_162 , V_105 ) ;
break;
default:
F_55 ( L_44 ) ;
F_133 ( V_162 ) ;
if ( ! V_11 -> V_68 && V_162 -> V_30 == V_31 )
F_72 ( V_11 -> V_68 , V_162 ) ;
break;
}
#ifdef F_134
V_15 -> V_200 = V_11 -> V_16 -> V_200 ;
if ( V_15 -> V_200 ) {
if ( F_76 ( V_162 ) ) {
F_66 ( L_45
L_46 ,
V_19 -> V_59 ) ;
V_26 = - V_168 ;
goto V_201;
}
}
#endif
V_26 = F_135 ( V_15 , F_96 ,
V_162 ) ;
if ( V_26 ) {
F_55 ( L_47 , V_26 ) ;
goto V_201;
}
V_26 = F_106 ( V_19 , V_15 , V_162 ) ;
if ( V_26 ) {
F_55 ( L_48 , V_26 ) ;
goto V_202;
}
V_26 = F_136 ( V_162 ) ;
if ( V_26 ) {
F_55 ( L_49 , V_26 ) ;
goto V_203;
}
V_11 -> V_204 ++ ;
F_89 ( V_11 ) ;
F_18 ( V_11 ) ;
if ( F_34 ( V_11 -> V_29 . V_1 ) ) {
F_137 () ;
F_74 ( & V_11 -> V_109 ) ;
F_75 ( V_11 ) ;
F_73 ( & V_11 -> V_109 ) ;
F_138 () ;
}
F_66 ( L_50 ,
V_19 -> V_59 , V_15 -> V_59 ,
F_139 ( V_162 ) ? L_51 : L_52 ,
V_162 -> V_30 != V_43 ? L_53 : L_54 ) ;
return 0 ;
V_203:
F_109 ( V_19 , V_15 ) ;
V_202:
F_140 ( V_15 ) ;
V_201:
if ( ! F_34 ( V_11 -> V_29 . V_1 ) )
F_44 ( V_19 , V_15 ) ;
F_141 ( V_15 , V_19 ) ;
if ( V_11 -> V_90 == V_162 )
V_11 -> V_90 = NULL ;
if ( V_11 -> V_68 == V_162 ) {
F_137 () ;
F_74 ( & V_11 -> V_109 ) ;
F_65 ( V_11 , NULL ) ;
F_75 ( V_11 ) ;
F_73 ( & V_11 -> V_109 ) ;
F_138 () ;
}
F_80 ( V_162 ) ;
V_192:
V_15 -> V_120 &= ~ V_191 ;
F_142 ( V_15 ) ;
V_190:
if ( ! V_11 -> V_29 . V_107 ||
V_11 -> V_29 . V_1 != V_4 ) {
memcpy ( V_165 . V_187 , V_162 -> V_186 , V_77 ) ;
V_165 . V_188 = V_15 -> type ;
F_121 ( V_15 , & V_165 ) ;
}
V_189:
F_120 ( V_15 , V_162 -> V_183 ) ;
V_185:
F_79 ( V_162 ) ;
V_171:
if ( ! F_19 ( V_11 ) &&
F_143 ( V_19 -> V_85 , V_15 -> V_85 ) )
F_144 ( V_19 ) ;
return V_26 ;
}
static int F_145 ( struct V_14 * V_19 ,
struct V_14 * V_15 ,
bool V_205 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_206 ;
struct V_164 V_165 ;
int V_207 = V_19 -> V_81 ;
T_7 V_208 = V_19 -> V_126 ;
if ( ! ( V_15 -> V_81 & V_159 ) ||
! F_146 ( V_15 , V_19 ) ) {
F_113 ( L_55 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
return - V_176 ;
}
F_137 () ;
V_22 = F_8 ( V_11 , V_15 ) ;
if ( ! V_22 ) {
F_66 ( L_56 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
F_138 () ;
return - V_176 ;
}
F_147 ( V_22 ) ;
F_109 ( V_19 , V_15 ) ;
F_140 ( V_15 ) ;
F_74 ( & V_11 -> V_209 ) ;
if ( V_11 -> V_29 . V_1 == V_7 )
F_148 ( V_22 ) ;
F_73 ( & V_11 -> V_209 ) ;
F_66 ( L_57 ,
V_19 -> V_59 ,
F_139 ( V_22 ) ? L_58 : L_59 ,
V_15 -> V_59 ) ;
V_206 = V_11 -> V_68 ;
V_11 -> V_210 = NULL ;
if ( ! V_205 && ( ! V_11 -> V_29 . V_107 ||
V_11 -> V_29 . V_1 != V_4 ) ) {
if ( F_143 ( V_19 -> V_85 , V_22 -> V_186 ) &&
F_19 ( V_11 ) )
F_119 ( L_60 ,
V_19 -> V_59 , V_15 -> V_59 ,
V_22 -> V_186 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
}
if ( V_11 -> V_90 == V_22 )
V_11 -> V_90 = NULL ;
if ( V_206 == V_22 ) {
F_74 ( & V_11 -> V_109 ) ;
F_65 ( V_11 , NULL ) ;
F_73 ( & V_11 -> V_109 ) ;
}
if ( F_16 ( V_11 ) ) {
F_149 ( V_11 , V_22 ) ;
}
if ( V_205 ) {
F_150 ( V_11 -> V_68 , NULL ) ;
} else if ( V_206 == V_22 ) {
F_74 ( & V_11 -> V_109 ) ;
F_75 ( V_11 ) ;
F_73 ( & V_11 -> V_109 ) ;
}
if ( ! F_19 ( V_11 ) ) {
F_18 ( V_11 ) ;
F_144 ( V_19 ) ;
if ( F_114 ( V_19 ) ) {
F_112 ( L_61 ,
V_19 -> V_59 , V_19 -> V_59 ) ;
F_112 ( L_62 ,
V_19 -> V_59 ) ;
}
}
F_138 () ;
F_151 () ;
V_11 -> V_204 -- ;
if ( ! F_19 ( V_11 ) ) {
F_42 ( V_88 , V_11 -> V_16 ) ;
F_42 ( V_211 , V_11 -> V_16 ) ;
}
F_89 ( V_11 ) ;
if ( ! ( V_19 -> V_126 & V_128 ) &&
( V_208 & V_128 ) )
F_66 ( L_63 ,
V_19 -> V_59 , V_15 -> V_59 , V_19 -> V_59 ) ;
F_141 ( V_15 , V_19 ) ;
if ( ! F_34 ( V_11 -> V_29 . V_1 ) ) {
if ( V_207 & V_82 )
F_35 ( V_15 , - 1 ) ;
if ( V_207 & V_83 )
F_37 ( V_15 , - 1 ) ;
F_44 ( V_19 , V_15 ) ;
}
F_80 ( V_22 ) ;
F_142 ( V_15 ) ;
if ( V_11 -> V_29 . V_107 != V_178 ||
V_11 -> V_29 . V_1 != V_4 ) {
memcpy ( V_165 . V_187 , V_22 -> V_186 , V_77 ) ;
V_165 . V_188 = V_15 -> type ;
F_121 ( V_15 , & V_165 ) ;
}
F_120 ( V_15 , V_22 -> V_183 ) ;
V_15 -> V_120 &= ~ V_191 ;
F_79 ( V_22 ) ;
return 0 ;
}
int F_152 ( struct V_14 * V_19 , struct V_14 * V_15 )
{
return F_145 ( V_19 , V_15 , false ) ;
}
static int F_153 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
int V_149 ;
V_149 = F_152 ( V_19 , V_15 ) ;
if ( V_149 == 0 && ! F_19 ( V_11 ) ) {
V_19 -> V_120 |= V_121 ;
F_66 ( L_64 ,
V_19 -> V_59 , V_19 -> V_59 ) ;
F_154 ( V_19 ) ;
}
return V_149 ;
}
static int F_155 ( struct V_14 * V_19 , struct V_212 * V_213 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
V_213 -> V_214 = V_11 -> V_29 . V_1 ;
V_213 -> V_104 = V_11 -> V_29 . V_104 ;
F_156 ( & V_11 -> V_209 ) ;
V_213 -> V_215 = V_11 -> V_204 ;
F_157 ( & V_11 -> V_209 ) ;
return 0 ;
}
static int F_158 ( struct V_14 * V_19 , struct V_216 * V_213 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
int V_167 = 0 , V_26 = - V_217 ;
struct V_22 * V_22 ;
F_156 ( & V_11 -> V_209 ) ;
F_12 (bond, slave, iter) {
if ( V_167 ++ == ( int ) V_213 -> V_218 ) {
V_26 = 0 ;
strcpy ( V_213 -> V_219 , V_22 -> V_16 -> V_59 ) ;
V_213 -> V_30 = V_22 -> V_30 ;
V_213 -> V_102 = F_159 ( V_22 ) ;
V_213 -> V_193 = V_22 -> V_193 ;
break;
}
}
F_157 ( & V_11 -> V_209 ) ;
return V_26 ;
}
static int F_160 ( struct V_10 * V_11 )
{
int V_220 , V_221 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
bool V_222 ;
V_222 = ! V_11 -> V_68 ? true : false ;
F_161 (bond, slave, iter) {
V_22 -> V_223 = V_224 ;
V_220 = F_28 ( V_11 , V_22 -> V_16 , 0 ) ;
switch ( V_22 -> V_30 ) {
case V_31 :
if ( V_220 )
continue;
V_22 -> V_30 = V_42 ;
V_22 -> V_99 = V_11 -> V_29 . V_225 ;
if ( V_22 -> V_99 ) {
F_66 ( L_65 ,
V_11 -> V_16 -> V_59 ,
( V_11 -> V_29 . V_1 ==
V_4 ) ?
( F_139 ( V_22 ) ?
L_66 : L_67 ) : L_68 ,
V_22 -> V_16 -> V_59 ,
V_11 -> V_29 . V_225 * V_11 -> V_29 . V_104 ) ;
}
case V_42 :
if ( V_220 ) {
V_22 -> V_30 = V_31 ;
V_22 -> V_103 = V_103 ;
F_66 ( L_69 ,
V_11 -> V_16 -> V_59 ,
( V_11 -> V_29 . V_225 - V_22 -> V_99 ) *
V_11 -> V_29 . V_104 ,
V_22 -> V_16 -> V_59 ) ;
continue;
}
if ( V_22 -> V_99 <= 0 ) {
V_22 -> V_223 = V_43 ;
V_221 ++ ;
continue;
}
V_22 -> V_99 -- ;
break;
case V_43 :
if ( ! V_220 )
continue;
V_22 -> V_30 = V_44 ;
V_22 -> V_99 = V_11 -> V_29 . V_98 ;
if ( V_22 -> V_99 ) {
F_66 ( L_70 ,
V_11 -> V_16 -> V_59 , V_22 -> V_16 -> V_59 ,
V_222 ? 0 :
V_11 -> V_29 . V_98 *
V_11 -> V_29 . V_104 ) ;
}
case V_44 :
if ( ! V_220 ) {
V_22 -> V_30 = V_43 ;
F_66 ( L_71 ,
V_11 -> V_16 -> V_59 ,
( V_11 -> V_29 . V_98 - V_22 -> V_99 ) *
V_11 -> V_29 . V_104 ,
V_22 -> V_16 -> V_59 ) ;
continue;
}
if ( V_222 )
V_22 -> V_99 = 0 ;
if ( V_22 -> V_99 <= 0 ) {
V_22 -> V_223 = V_31 ;
V_221 ++ ;
V_222 = false ;
continue;
}
V_22 -> V_99 -- ;
break;
}
}
return V_221 ;
}
static void F_162 ( struct V_10 * V_11 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
switch ( V_22 -> V_223 ) {
case V_224 :
continue;
case V_31 :
V_22 -> V_30 = V_31 ;
V_22 -> V_103 = V_103 ;
if ( V_11 -> V_29 . V_1 == V_7 ) {
F_163 ( V_22 ) ;
} else if ( V_11 -> V_29 . V_1 != V_4 ) {
F_133 ( V_22 ) ;
} else if ( V_22 != V_11 -> V_90 ) {
F_163 ( V_22 ) ;
}
F_66 ( L_72 ,
V_11 -> V_16 -> V_59 , V_22 -> V_16 -> V_59 ,
V_22 -> V_35 == V_36 ? 0 : V_22 -> V_35 ,
V_22 -> V_37 ? L_73 : L_74 ) ;
if ( V_11 -> V_29 . V_1 == V_7 )
F_67 ( V_22 , V_31 ) ;
if ( F_16 ( V_11 ) )
F_68 ( V_11 , V_22 ,
V_31 ) ;
if ( ! V_11 -> V_68 ||
( V_22 == V_11 -> V_90 ) )
goto V_226;
continue;
case V_43 :
if ( V_22 -> V_193 < V_227 )
V_22 -> V_193 ++ ;
V_22 -> V_30 = V_43 ;
if ( V_11 -> V_29 . V_1 == V_4 ||
V_11 -> V_29 . V_1 == V_7 )
F_70 ( V_22 ,
V_105 ) ;
F_66 ( L_75 ,
V_11 -> V_16 -> V_59 , V_22 -> V_16 -> V_59 ) ;
if ( V_11 -> V_29 . V_1 == V_7 )
F_67 ( V_22 ,
V_43 ) ;
if ( F_16 ( V_11 ) )
F_68 ( V_11 , V_22 ,
V_43 ) ;
if ( V_22 == V_11 -> V_68 )
goto V_226;
continue;
default:
F_113 ( L_76 ,
V_11 -> V_16 -> V_59 , V_22 -> V_223 ,
V_22 -> V_16 -> V_59 ) ;
V_22 -> V_223 = V_224 ;
continue;
}
V_226:
F_49 () ;
F_137 () ;
F_74 ( & V_11 -> V_109 ) ;
F_75 ( V_11 ) ;
F_73 ( & V_11 -> V_109 ) ;
F_138 () ;
}
F_18 ( V_11 ) ;
}
static void F_164 ( struct V_69 * V_70 )
{
struct V_10 * V_11 = F_39 ( V_70 , struct V_10 ,
V_228 . V_70 ) ;
bool V_106 = false ;
unsigned long V_99 ;
V_99 = F_129 ( V_11 -> V_29 . V_104 ) ;
if ( ! F_19 ( V_11 ) )
goto V_229;
F_61 () ;
V_106 = F_60 ( V_11 ) ;
if ( F_160 ( V_11 ) ) {
F_63 () ;
if ( ! F_40 () ) {
V_99 = 1 ;
V_106 = false ;
goto V_229;
}
F_162 ( V_11 ) ;
F_43 () ;
} else
F_63 () ;
V_229:
if ( V_11 -> V_29 . V_104 )
F_41 ( V_11 -> V_72 , & V_11 -> V_228 , V_99 ) ;
if ( V_106 ) {
if ( ! F_40 () )
return;
F_42 ( V_111 , V_11 -> V_16 ) ;
F_43 () ;
}
}
static bool F_165 ( struct V_10 * V_11 , T_9 V_230 )
{
struct V_14 * V_231 ;
struct V_24 * V_25 ;
bool V_149 = false ;
if ( V_230 == F_166 ( V_11 -> V_16 , 0 , V_230 ) )
return true ;
F_61 () ;
F_167 (bond->dev, upper, iter) {
if ( V_230 == F_166 ( V_231 , 0 , V_230 ) ) {
V_149 = true ;
break;
}
}
F_63 () ;
return V_149 ;
}
static void F_168 ( struct V_14 * V_15 , int V_232 , T_9 V_233 , T_9 V_234 , unsigned short V_235 )
{
struct V_12 * V_13 ;
F_55 ( L_77 , V_232 ,
V_15 -> V_59 , & V_233 , & V_234 , V_235 ) ;
V_13 = F_169 ( V_232 , V_236 , V_233 , V_15 , V_234 ,
NULL , V_15 -> V_85 , NULL ) ;
if ( ! V_13 ) {
F_113 ( L_78 ) ;
return;
}
if ( V_235 ) {
V_13 = F_170 ( V_13 , F_171 ( V_237 ) , V_235 ) ;
if ( ! V_13 ) {
F_113 ( L_79 ) ;
return;
}
}
F_172 ( V_13 ) ;
}
static void F_173 ( struct V_10 * V_11 , struct V_22 * V_22 )
{
struct V_14 * V_231 , * V_238 ;
struct V_24 * V_25 , * V_239 ;
struct V_240 * V_241 ;
T_9 * V_242 = V_11 -> V_29 . V_243 , V_165 ;
int V_167 , V_235 ;
for ( V_167 = 0 ; V_167 < V_195 && V_242 [ V_167 ] ; V_167 ++ ) {
F_55 ( L_80 , & V_242 [ V_167 ] ) ;
V_241 = F_174 ( F_175 ( V_11 -> V_16 ) , V_242 [ V_167 ] , 0 ,
V_244 , 0 ) ;
if ( F_176 ( V_241 ) ) {
F_55 ( L_81 ,
V_11 -> V_16 -> V_59 , & V_242 [ V_167 ] ) ;
continue;
}
V_235 = 0 ;
if ( V_241 -> V_245 . V_16 == V_11 -> V_16 )
goto V_246;
F_61 () ;
F_167 (bond->dev, vlan_upper,
vlan_iter) {
if ( ! F_177 ( V_238 ) )
continue;
F_167 (vlan_upper, upper,
iter) {
if ( V_231 == V_241 -> V_245 . V_16 ) {
V_235 = F_178 ( V_238 ) ;
F_63 () ;
goto V_246;
}
}
}
F_167 (bond->dev, upper, iter) {
if ( V_231 == V_241 -> V_245 . V_16 ) {
if ( F_177 ( V_231 ) )
V_235 = F_178 ( V_231 ) ;
F_63 () ;
goto V_246;
}
}
F_63 () ;
F_55 ( L_82 ,
V_11 -> V_16 -> V_59 , & V_242 [ V_167 ] ,
V_241 -> V_245 . V_16 ? V_241 -> V_245 . V_16 -> V_59 : L_15 ) ;
F_179 ( V_241 ) ;
continue;
V_246:
V_165 = F_166 ( V_241 -> V_245 . V_16 , V_242 [ V_167 ] , 0 ) ;
F_179 ( V_241 ) ;
F_168 ( V_22 -> V_16 , V_247 , V_242 [ V_167 ] ,
V_165 , V_235 ) ;
}
}
static void F_180 ( struct V_10 * V_11 , struct V_22 * V_22 , T_9 V_248 , T_9 V_249 )
{
int V_167 ;
if ( ! V_248 || ! F_165 ( V_11 , V_249 ) ) {
F_55 ( L_83 , & V_248 , & V_249 ) ;
return;
}
V_167 = F_181 ( V_11 -> V_29 . V_243 , V_248 ) ;
if ( V_167 == - 1 ) {
F_55 ( L_84 , & V_248 ) ;
return;
}
V_22 -> V_194 = V_103 ;
V_22 -> V_196 [ V_167 ] = V_103 ;
}
int F_182 ( const struct V_12 * V_13 , struct V_10 * V_11 ,
struct V_22 * V_22 )
{
struct V_250 * V_251 = (struct V_250 * ) V_13 -> V_157 ;
unsigned char * V_252 ;
T_9 V_248 , V_249 ;
int V_253 ;
if ( V_13 -> V_254 != F_183 ( V_236 ) )
return V_150 ;
F_156 ( & V_11 -> V_209 ) ;
if ( ! F_184 ( V_11 , V_22 ) )
goto V_255;
V_253 = F_185 ( V_11 -> V_16 ) ;
F_55 ( L_85 ,
V_11 -> V_16 -> V_59 , V_13 -> V_16 -> V_59 ) ;
if ( V_253 > F_186 ( V_13 ) ) {
V_251 = F_187 ( V_253 , V_117 ) ;
if ( ! V_251 )
goto V_255;
if ( F_188 ( V_13 , 0 , V_251 , V_253 ) < 0 )
goto V_255;
}
if ( V_251 -> V_256 != V_11 -> V_16 -> V_84 ||
V_13 -> V_145 == V_257 ||
V_13 -> V_145 == V_258 ||
V_251 -> V_259 != F_171 ( V_173 ) ||
V_251 -> V_260 != F_171 ( V_261 ) ||
V_251 -> V_262 != 4 )
goto V_255;
V_252 = ( unsigned char * ) ( V_251 + 1 ) ;
V_252 += V_11 -> V_16 -> V_84 ;
memcpy ( & V_248 , V_252 , 4 ) ;
V_252 += 4 + V_11 -> V_16 -> V_84 ;
memcpy ( & V_249 , V_252 , 4 ) ;
F_55 ( L_86 ,
V_11 -> V_16 -> V_59 , V_22 -> V_16 -> V_59 , F_159 ( V_22 ) ,
V_11 -> V_29 . V_263 , F_184 ( V_11 , V_22 ) ,
& V_248 , & V_249 ) ;
if ( F_139 ( V_22 ) )
F_180 ( V_11 , V_22 , V_248 , V_249 ) ;
else if ( V_11 -> V_68 &&
F_189 ( F_190 ( V_11 , V_11 -> V_68 ) ,
V_11 -> V_68 -> V_103 ) )
F_180 ( V_11 , V_22 , V_249 , V_248 ) ;
V_255:
F_157 ( & V_11 -> V_209 ) ;
if ( V_251 != (struct V_250 * ) V_13 -> V_157 )
F_79 ( V_251 ) ;
return V_150 ;
}
static bool F_191 ( struct V_10 * V_11 , unsigned long V_264 ,
int V_265 )
{
int V_266 = F_129 ( V_11 -> V_29 . V_152 ) ;
return F_192 ( V_103 ,
V_264 - V_266 ,
V_264 + V_265 * V_266 + V_266 / 2 ) ;
}
static void F_193 ( struct V_69 * V_70 )
{
struct V_10 * V_11 = F_39 ( V_70 , struct V_10 ,
V_267 . V_70 ) ;
struct V_22 * V_22 , * V_206 ;
struct V_24 * V_25 ;
int V_226 = 0 , V_268 = 0 ;
if ( ! F_19 ( V_11 ) )
goto V_229;
F_61 () ;
V_206 = F_100 ( V_11 -> V_68 ) ;
F_161 (bond, slave, iter) {
unsigned long V_269 = F_194 ( V_22 -> V_16 ) ;
if ( V_22 -> V_30 != V_31 ) {
if ( F_191 ( V_11 , V_269 , 1 ) &&
F_191 ( V_11 , V_22 -> V_16 -> V_153 , 1 ) ) {
V_22 -> V_30 = V_31 ;
V_268 = 1 ;
if ( ! V_206 ) {
F_66 ( L_87 ,
V_11 -> V_16 -> V_59 ,
V_22 -> V_16 -> V_59 ) ;
V_226 = 1 ;
} else {
F_66 ( L_88 ,
V_11 -> V_16 -> V_59 ,
V_22 -> V_16 -> V_59 ) ;
}
}
} else {
if ( ! F_191 ( V_11 , V_269 , 2 ) ||
! F_191 ( V_11 , V_22 -> V_16 -> V_153 , 2 ) ) {
V_22 -> V_30 = V_43 ;
V_268 = 1 ;
if ( V_22 -> V_193 < V_227 )
V_22 -> V_193 ++ ;
F_66 ( L_89 ,
V_11 -> V_16 -> V_59 ,
V_22 -> V_16 -> V_59 ) ;
if ( V_22 == V_206 )
V_226 = 1 ;
}
}
if ( F_59 ( V_22 -> V_16 ) )
F_173 ( V_11 , V_22 ) ;
}
F_63 () ;
if ( V_226 || V_268 ) {
if ( ! F_40 () )
goto V_229;
if ( V_268 ) {
F_195 ( V_11 ) ;
} else if ( V_226 ) {
F_137 () ;
F_74 ( & V_11 -> V_109 ) ;
F_75 ( V_11 ) ;
F_73 ( & V_11 -> V_109 ) ;
F_138 () ;
}
F_43 () ;
}
V_229:
if ( V_11 -> V_29 . V_152 )
F_41 ( V_11 -> V_72 , & V_11 -> V_267 ,
F_129 ( V_11 -> V_29 . V_152 ) ) ;
}
static int F_196 ( struct V_10 * V_11 )
{
unsigned long V_269 , V_153 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_221 = 0 ;
F_161 (bond, slave, iter) {
V_22 -> V_223 = V_224 ;
V_153 = F_190 ( V_11 , V_22 ) ;
if ( V_22 -> V_30 != V_31 ) {
if ( F_191 ( V_11 , V_153 , 1 ) ) {
V_22 -> V_223 = V_31 ;
V_221 ++ ;
}
continue;
}
if ( F_191 ( V_11 , V_22 -> V_103 , 2 ) )
continue;
if ( ! F_139 ( V_22 ) &&
! V_11 -> V_210 &&
! F_191 ( V_11 , V_153 , 3 ) ) {
V_22 -> V_223 = V_43 ;
V_221 ++ ;
}
V_269 = F_194 ( V_22 -> V_16 ) ;
if ( F_139 ( V_22 ) &&
( ! F_191 ( V_11 , V_269 , 2 ) ||
! F_191 ( V_11 , V_153 , 2 ) ) ) {
V_22 -> V_223 = V_43 ;
V_221 ++ ;
}
}
return V_221 ;
}
static void F_197 ( struct V_10 * V_11 )
{
unsigned long V_269 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
switch ( V_22 -> V_223 ) {
case V_224 :
continue;
case V_31 :
V_269 = F_194 ( V_22 -> V_16 ) ;
if ( V_11 -> V_68 != V_22 ||
( ! V_11 -> V_68 &&
F_191 ( V_11 , V_269 , 1 ) ) ) {
V_22 -> V_30 = V_31 ;
if ( V_11 -> V_210 ) {
F_70 (
V_11 -> V_210 ,
V_105 ) ;
V_11 -> V_210 = NULL ;
}
F_66 ( L_90 ,
V_11 -> V_16 -> V_59 , V_22 -> V_16 -> V_59 ) ;
if ( ! V_11 -> V_68 ||
( V_22 == V_11 -> V_90 ) )
goto V_226;
}
continue;
case V_43 :
if ( V_22 -> V_193 < V_227 )
V_22 -> V_193 ++ ;
V_22 -> V_30 = V_43 ;
F_70 ( V_22 ,
V_105 ) ;
F_66 ( L_75 ,
V_11 -> V_16 -> V_59 , V_22 -> V_16 -> V_59 ) ;
if ( V_22 == V_11 -> V_68 ) {
V_11 -> V_210 = NULL ;
goto V_226;
}
continue;
default:
F_113 ( L_91 ,
V_11 -> V_16 -> V_59 , V_22 -> V_223 ,
V_22 -> V_16 -> V_59 ) ;
continue;
}
V_226:
F_49 () ;
F_137 () ;
F_74 ( & V_11 -> V_109 ) ;
F_75 ( V_11 ) ;
F_73 ( & V_11 -> V_109 ) ;
F_138 () ;
}
F_18 ( V_11 ) ;
}
static bool F_198 ( struct V_10 * V_11 )
{
struct V_22 * V_22 , * V_270 = NULL , * V_162 = NULL ,
* V_271 = F_62 ( V_11 -> V_210 ) ,
* V_68 = F_62 ( V_11 -> V_68 ) ;
struct V_24 * V_25 ;
bool V_246 = false ;
bool V_272 = V_273 ;
if ( V_271 && V_68 )
F_66 ( L_92 ,
V_271 -> V_16 -> V_59 ,
V_68 -> V_16 -> V_59 ) ;
if ( V_68 ) {
F_173 ( V_11 , V_68 ) ;
return V_272 ;
}
if ( ! V_271 ) {
V_271 = F_199 ( V_11 ) ;
if ( ! V_271 )
return V_272 ;
}
F_70 ( V_271 , V_273 ) ;
F_161 (bond, slave, iter) {
if ( ! V_246 && ! V_270 && F_59 ( V_22 -> V_16 ) )
V_270 = V_22 ;
if ( V_246 && ! V_162 && F_59 ( V_22 -> V_16 ) )
V_162 = V_22 ;
if ( ! F_59 ( V_22 -> V_16 ) && V_22 -> V_30 == V_31 ) {
V_22 -> V_30 = V_43 ;
if ( V_22 -> V_193 < V_227 )
V_22 -> V_193 ++ ;
F_70 ( V_22 ,
V_273 ) ;
F_66 ( L_93 ,
V_11 -> V_16 -> V_59 , V_22 -> V_16 -> V_59 ) ;
}
if ( V_22 == V_271 )
V_246 = true ;
}
if ( ! V_162 && V_270 )
V_162 = V_270 ;
if ( ! V_162 )
goto V_274;
V_162 -> V_30 = V_44 ;
F_71 ( V_162 , V_273 ) ;
F_173 ( V_11 , V_162 ) ;
V_162 -> V_103 = V_103 ;
F_72 ( V_11 -> V_210 , V_162 ) ;
V_274:
F_161 (bond, slave, iter) {
if ( V_22 -> V_275 ) {
V_272 = V_105 ;
break;
}
}
return V_272 ;
}
static void F_200 ( struct V_69 * V_70 )
{
struct V_10 * V_11 = F_39 ( V_70 , struct V_10 ,
V_267 . V_70 ) ;
bool V_106 = false ;
bool V_272 = false ;
int V_266 ;
V_266 = F_129 ( V_11 -> V_29 . V_152 ) ;
if ( ! F_19 ( V_11 ) )
goto V_229;
F_61 () ;
V_106 = F_60 ( V_11 ) ;
if ( F_196 ( V_11 ) ) {
F_63 () ;
if ( ! F_40 () ) {
V_266 = 1 ;
V_106 = false ;
goto V_229;
}
F_197 ( V_11 ) ;
F_43 () ;
F_61 () ;
}
V_272 = F_198 ( V_11 ) ;
F_63 () ;
V_229:
if ( V_11 -> V_29 . V_152 )
F_41 ( V_11 -> V_72 , & V_11 -> V_267 , V_266 ) ;
if ( V_106 || V_272 ) {
if ( ! F_40 () )
return;
if ( V_106 )
F_42 ( V_111 ,
V_11 -> V_16 ) ;
if ( V_272 )
F_201 ( V_11 ) ;
F_43 () ;
}
}
static int F_202 ( struct V_10 * V_11 )
{
F_203 ( V_11 ) ;
F_204 ( V_11 ) ;
F_205 ( V_11 ) ;
return V_276 ;
}
static int F_206 ( unsigned long V_277 ,
struct V_14 * V_19 )
{
struct V_10 * V_278 = F_11 ( V_19 ) ;
switch ( V_277 ) {
case V_279 :
return F_202 ( V_278 ) ;
case V_280 :
F_203 ( V_278 ) ;
break;
case V_281 :
F_204 ( V_278 ) ;
break;
case V_111 :
if ( V_278 -> V_100 )
V_278 -> V_100 -- ;
break;
default:
break;
}
return V_276 ;
}
static int F_207 ( unsigned long V_277 ,
struct V_14 * V_15 )
{
struct V_22 * V_22 = F_208 ( V_15 ) ;
struct V_10 * V_11 ;
struct V_14 * V_19 ;
T_3 V_282 ;
T_5 V_283 ;
if ( ! V_22 )
return V_276 ;
V_19 = V_22 -> V_11 -> V_16 ;
V_11 = V_22 -> V_11 ;
switch ( V_277 ) {
case V_280 :
if ( V_19 -> type != V_173 )
F_153 ( V_19 , V_15 ) ;
else
F_152 ( V_19 , V_15 ) ;
break;
case V_284 :
case V_285 :
V_282 = V_22 -> V_35 ;
V_283 = V_22 -> V_37 ;
F_24 ( V_22 ) ;
if ( V_11 -> V_29 . V_1 == V_7 ) {
if ( V_282 != V_22 -> V_35 )
F_209 ( V_22 ) ;
if ( V_283 != V_22 -> V_37 )
F_210 ( V_22 ) ;
}
break;
case V_286 :
break;
case V_287 :
break;
case V_279 :
if ( ! F_34 ( V_11 -> V_29 . V_1 ) ||
! V_11 -> V_29 . V_197 [ 0 ] )
break;
if ( V_22 == V_11 -> V_90 ) {
V_11 -> V_90 = NULL ;
} else if ( ! strcmp ( V_15 -> V_59 , V_11 -> V_29 . V_197 ) ) {
V_11 -> V_90 = V_22 ;
} else {
break;
}
F_66 ( L_94 ,
V_11 -> V_16 -> V_59 , V_11 -> V_90 ? V_15 -> V_59 :
L_95 ) ;
F_137 () ;
F_74 ( & V_11 -> V_109 ) ;
F_75 ( V_11 ) ;
F_73 ( & V_11 -> V_109 ) ;
F_138 () ;
break;
case V_288 :
F_89 ( V_11 ) ;
break;
case V_73 :
F_42 ( V_277 , V_22 -> V_11 -> V_16 ) ;
break;
default:
break;
}
return V_276 ;
}
static int F_211 ( struct V_289 * V_290 ,
unsigned long V_277 , void * V_291 )
{
struct V_14 * V_292 = F_212 ( V_291 ) ;
F_55 ( L_96 ,
V_292 ? V_292 -> V_59 : L_97 ,
V_277 ) ;
if ( ! ( V_292 -> V_120 & V_191 ) )
return V_276 ;
if ( V_292 -> V_81 & V_293 ) {
F_55 ( L_98 ) ;
return F_206 ( V_277 , V_292 ) ;
}
if ( V_292 -> V_81 & V_159 ) {
F_55 ( L_99 ) ;
return F_207 ( V_277 , V_292 ) ;
}
return V_276 ;
}
static inline T_3 F_213 ( struct V_12 * V_13 )
{
struct V_294 * V_157 = (struct V_294 * ) V_13 -> V_157 ;
if ( F_186 ( V_13 ) >= F_214 ( struct V_294 , V_295 ) )
return V_157 -> V_158 [ 5 ] ^ V_157 -> V_296 [ 5 ] ;
return 0 ;
}
static bool F_215 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_297 * V_298 )
{
const struct V_299 * V_300 ;
const struct V_301 * V_302 ;
int V_303 , V_20 = - 1 ;
if ( V_11 -> V_29 . V_304 > V_305 )
return F_216 ( V_13 , V_298 ) ;
V_298 -> V_306 = 0 ;
V_303 = F_217 ( V_13 ) ;
if ( V_13 -> V_254 == F_171 ( V_261 ) ) {
if ( ! F_218 ( V_13 , V_303 + sizeof( * V_302 ) ) )
return false ;
V_302 = F_219 ( V_13 ) ;
V_298 -> V_307 = V_302 -> V_308 ;
V_298 -> V_245 = V_302 -> V_309 ;
V_303 += V_302 -> V_310 << 2 ;
if ( ! F_220 ( V_302 ) )
V_20 = V_302 -> V_254 ;
} else if ( V_13 -> V_254 == F_171 ( V_311 ) ) {
if ( ! F_218 ( V_13 , V_303 + sizeof( * V_300 ) ) )
return false ;
V_300 = F_221 ( V_13 ) ;
V_298 -> V_307 = ( V_312 T_9 ) F_222 ( & V_300 -> V_308 ) ;
V_298 -> V_245 = ( V_312 T_9 ) F_222 ( & V_300 -> V_309 ) ;
V_303 += sizeof( * V_300 ) ;
V_20 = V_300 -> V_313 ;
} else {
return false ;
}
if ( V_11 -> V_29 . V_304 == V_314 && V_20 >= 0 )
V_298 -> V_306 = F_223 ( V_13 , V_303 , V_20 ) ;
return true ;
}
int F_224 ( struct V_10 * V_11 , struct V_12 * V_13 , int V_315 )
{
struct V_297 V_316 ;
T_3 V_317 ;
if ( V_11 -> V_29 . V_304 == V_318 ||
! F_215 ( V_11 , V_13 , & V_316 ) )
return F_213 ( V_13 ) % V_315 ;
if ( V_11 -> V_29 . V_304 == V_305 ||
V_11 -> V_29 . V_304 == V_319 )
V_317 = F_213 ( V_13 ) ;
else
V_317 = ( V_312 T_3 ) V_316 . V_306 ;
V_317 ^= ( V_312 T_3 ) V_316 . V_245 ^ ( V_312 T_3 ) V_316 . V_307 ;
V_317 ^= ( V_317 >> 16 ) ;
V_317 ^= ( V_317 >> 8 ) ;
return V_317 % V_315 ;
}
static void F_225 ( struct V_10 * V_11 )
{
F_226 ( & V_11 -> V_71 ,
F_38 ) ;
F_226 ( & V_11 -> V_320 , V_321 ) ;
F_226 ( & V_11 -> V_228 , F_164 ) ;
if ( V_11 -> V_29 . V_1 == V_4 )
F_226 ( & V_11 -> V_267 , F_200 ) ;
else
F_226 ( & V_11 -> V_267 , F_193 ) ;
F_226 ( & V_11 -> V_322 , V_323 ) ;
}
static void F_227 ( struct V_10 * V_11 )
{
F_228 ( & V_11 -> V_228 ) ;
F_228 ( & V_11 -> V_267 ) ;
F_228 ( & V_11 -> V_320 ) ;
F_228 ( & V_11 -> V_322 ) ;
F_228 ( & V_11 -> V_71 ) ;
}
static int F_229 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_156 ( & V_11 -> V_209 ) ;
if ( F_19 ( V_11 ) ) {
F_156 ( & V_11 -> V_109 ) ;
F_12 (bond, slave, iter) {
if ( ( V_11 -> V_29 . V_1 == V_4 )
&& ( V_22 != V_11 -> V_68 ) ) {
F_70 ( V_22 ,
V_105 ) ;
} else {
F_71 ( V_22 ,
V_105 ) ;
}
}
F_157 ( & V_11 -> V_109 ) ;
}
F_157 ( & V_11 -> V_209 ) ;
F_225 ( V_11 ) ;
if ( F_16 ( V_11 ) ) {
if ( F_230 ( V_11 , ( V_11 -> V_29 . V_1 == V_9 ) ) )
return - V_118 ;
F_41 ( V_11 -> V_72 , & V_11 -> V_320 , 0 ) ;
}
if ( V_11 -> V_29 . V_104 )
F_41 ( V_11 -> V_72 , & V_11 -> V_228 , 0 ) ;
if ( V_11 -> V_29 . V_152 ) {
F_41 ( V_11 -> V_72 , & V_11 -> V_267 , 0 ) ;
if ( V_11 -> V_29 . V_263 )
V_11 -> F_97 = F_182 ;
}
if ( V_11 -> V_29 . V_1 == V_7 ) {
F_41 ( V_11 -> V_72 , & V_11 -> V_322 , 0 ) ;
V_11 -> F_97 = V_324 ;
F_231 ( V_11 , 1 ) ;
}
return 0 ;
}
static int F_232 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_227 ( V_11 ) ;
V_11 -> V_100 = 0 ;
if ( F_16 ( V_11 ) )
F_233 ( V_11 ) ;
V_11 -> F_97 = NULL ;
return 0 ;
}
static struct V_325 * F_234 ( struct V_14 * V_19 ,
struct V_325 * V_326 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_325 V_327 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
memset ( V_326 , 0 , sizeof( * V_326 ) ) ;
F_235 ( & V_11 -> V_209 ) ;
F_12 (bond, slave, iter) {
const struct V_325 * V_328 =
F_236 ( V_22 -> V_16 , & V_327 ) ;
V_326 -> V_329 += V_328 -> V_329 ;
V_326 -> V_330 += V_328 -> V_330 ;
V_326 -> V_331 += V_328 -> V_331 ;
V_326 -> V_332 += V_328 -> V_332 ;
V_326 -> V_333 += V_328 -> V_333 ;
V_326 -> V_334 += V_328 -> V_334 ;
V_326 -> V_335 += V_328 -> V_335 ;
V_326 -> V_336 += V_328 -> V_336 ;
V_326 -> V_337 += V_328 -> V_337 ;
V_326 -> V_338 += V_328 -> V_338 ;
V_326 -> V_339 += V_328 -> V_339 ;
V_326 -> V_340 += V_328 -> V_340 ;
V_326 -> V_341 += V_328 -> V_341 ;
V_326 -> V_342 += V_328 -> V_342 ;
V_326 -> V_343 += V_328 -> V_343 ;
V_326 -> V_344 += V_328 -> V_344 ;
V_326 -> V_345 += V_328 -> V_345 ;
V_326 -> V_346 += V_328 -> V_346 ;
V_326 -> V_347 += V_328 -> V_347 ;
V_326 -> V_348 += V_328 -> V_348 ;
V_326 -> V_349 += V_328 -> V_349 ;
}
F_237 ( & V_11 -> V_209 ) ;
return V_326 ;
}
static int F_238 ( struct V_14 * V_19 , struct V_49 * V_50 , int V_350 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_14 * V_15 = NULL ;
struct V_212 V_351 ;
struct V_212 T_10 * V_352 = NULL ;
struct V_216 V_353 ;
struct V_216 T_10 * V_354 = NULL ;
struct V_51 * V_52 = NULL ;
struct V_355 V_356 ;
struct V_357 * V_357 ;
int V_26 = 0 ;
F_55 ( L_100 , V_19 -> V_59 , V_350 ) ;
switch ( V_350 ) {
case V_61 :
V_52 = F_31 ( V_50 ) ;
if ( ! V_52 )
return - V_176 ;
V_52 -> V_358 = 0 ;
case V_64 :
V_52 = F_31 ( V_50 ) ;
if ( ! V_52 )
return - V_176 ;
if ( V_52 -> V_62 == 1 ) {
V_52 -> V_65 = 0 ;
F_156 ( & V_11 -> V_209 ) ;
F_156 ( & V_11 -> V_109 ) ;
if ( F_21 ( V_11 -> V_16 ) )
V_52 -> V_65 = V_54 ;
F_157 ( & V_11 -> V_109 ) ;
F_157 ( & V_11 -> V_209 ) ;
}
return 0 ;
case V_359 :
case V_360 :
V_352 = (struct V_212 T_10 * ) V_50 -> V_361 ;
if ( F_239 ( & V_351 , V_352 , sizeof( V_212 ) ) )
return - V_362 ;
V_26 = F_155 ( V_19 , & V_351 ) ;
if ( V_26 == 0 &&
F_240 ( V_352 , & V_351 , sizeof( V_212 ) ) )
return - V_362 ;
return V_26 ;
case V_363 :
case V_364 :
V_354 = (struct V_216 T_10 * ) V_50 -> V_361 ;
if ( F_239 ( & V_353 , V_354 , sizeof( V_216 ) ) )
return - V_362 ;
V_26 = F_158 ( V_19 , & V_353 ) ;
if ( V_26 == 0 &&
F_240 ( V_354 , & V_353 , sizeof( V_216 ) ) )
return - V_362 ;
return V_26 ;
default:
break;
}
V_357 = F_175 ( V_19 ) ;
if ( ! F_241 ( V_357 -> V_365 , V_366 ) )
return - V_169 ;
V_15 = F_242 ( V_357 , V_50 -> V_367 ) ;
F_55 ( L_101 , V_15 ) ;
if ( ! V_15 )
return - V_217 ;
F_55 ( L_102 , V_15 -> V_59 ) ;
switch ( V_350 ) {
case V_368 :
case V_369 :
V_26 = F_111 ( V_19 , V_15 ) ;
break;
case V_370 :
case V_371 :
V_26 = F_152 ( V_19 , V_15 ) ;
break;
case V_372 :
case V_373 :
F_54 ( V_19 , V_15 ) ;
V_26 = 0 ;
break;
case V_374 :
case V_375 :
F_243 ( & V_356 , V_15 -> V_59 ) ;
V_26 = F_244 ( V_11 , V_376 , & V_356 ) ;
break;
default:
V_26 = - V_179 ;
}
return V_26 ;
}
static void F_245 ( struct V_14 * V_19 , int V_377 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_377 & V_82 )
F_33 ( V_11 ,
V_19 -> V_81 & V_82 ? 1 : - 1 ) ;
if ( V_377 & V_83 )
F_36 ( V_11 ,
V_19 -> V_81 & V_83 ? 1 : - 1 ) ;
}
static void F_246 ( struct V_14 * V_19 )
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
F_161 (bond, slave, iter) {
F_125 ( V_22 -> V_16 , V_19 ) ;
F_124 ( V_22 -> V_16 , V_19 ) ;
}
}
F_63 () ;
}
static int F_247 ( struct V_378 * V_379 )
{
struct V_10 * V_11 = F_11 ( V_379 -> V_16 ) ;
const struct V_46 * V_47 ;
struct V_380 V_381 ;
struct V_22 * V_22 ;
int V_149 ;
V_22 = F_248 ( V_11 ) ;
if ( ! V_22 )
return 0 ;
V_47 = V_22 -> V_16 -> V_48 ;
if ( ! V_47 -> V_382 )
return 0 ;
V_381 . V_383 = NULL ;
V_381 . V_384 = NULL ;
V_149 = V_47 -> V_382 ( V_22 -> V_16 , & V_381 ) ;
if ( V_149 )
return V_149 ;
V_379 -> V_381 -> V_384 = V_381 . V_384 ;
if ( ! V_381 . V_383 )
return 0 ;
return V_381 . V_383 ( V_379 ) ;
}
static int F_249 ( struct V_14 * V_16 ,
struct V_380 * V_381 )
{
if ( V_381 -> V_16 == V_16 )
V_381 -> V_383 = F_247 ;
return 0 ;
}
static int F_250 ( struct V_14 * V_19 , int V_385 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
F_55 ( L_103 , V_11 ,
( V_19 ? V_19 -> V_59 : L_97 ) , V_385 ) ;
F_12 (bond, slave, iter) {
F_55 ( L_104 ,
V_22 ,
V_22 -> V_16 -> V_48 -> V_386 ) ;
V_26 = F_120 ( V_22 -> V_16 , V_385 ) ;
if ( V_26 ) {
F_55 ( L_105 , V_26 , V_22 -> V_16 -> V_59 ) ;
goto V_27;
}
}
V_19 -> V_184 = V_385 ;
return 0 ;
V_27:
F_12 (bond, rollback_slave, iter) {
int V_387 ;
if ( V_23 == V_22 )
break;
V_387 = F_120 ( V_23 -> V_16 , V_19 -> V_184 ) ;
if ( V_387 ) {
F_55 ( L_106 ,
V_387 , V_23 -> V_16 -> V_59 ) ;
}
}
return V_26 ;
}
static int F_251 ( struct V_14 * V_19 , void * V_165 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_164 * V_388 = V_165 , V_389 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
if ( V_11 -> V_29 . V_1 == V_9 )
return F_252 ( V_19 , V_165 ) ;
F_55 ( L_107 ,
V_11 , V_19 ? V_19 -> V_59 : L_97 ) ;
if ( V_11 -> V_29 . V_107 &&
V_11 -> V_29 . V_1 == V_4 )
return 0 ;
if ( ! F_253 ( V_388 -> V_187 ) )
return - V_390 ;
F_12 (bond, slave, iter) {
const struct V_46 * V_47 = V_22 -> V_16 -> V_48 ;
F_55 ( L_108 , V_22 , V_22 -> V_16 -> V_59 ) ;
if ( V_47 -> V_177 == NULL ) {
V_26 = - V_179 ;
F_55 ( L_109 , V_22 -> V_16 -> V_59 ) ;
goto V_27;
}
V_26 = F_121 ( V_22 -> V_16 , V_165 ) ;
if ( V_26 ) {
F_55 ( L_105 , V_26 , V_22 -> V_16 -> V_59 ) ;
goto V_27;
}
}
memcpy ( V_19 -> V_85 , V_388 -> V_187 , V_19 -> V_84 ) ;
return 0 ;
V_27:
memcpy ( V_389 . V_187 , V_19 -> V_85 , V_19 -> V_84 ) ;
V_389 . V_188 = V_19 -> type ;
F_12 (bond, rollback_slave, iter) {
int V_387 ;
if ( V_23 == V_22 )
break;
V_387 = F_121 ( V_23 -> V_16 , & V_389 ) ;
if ( V_387 ) {
F_55 ( L_106 ,
V_387 , V_23 -> V_16 -> V_59 ) ;
}
}
return V_26 ;
}
static void F_254 ( struct V_10 * V_11 , struct V_12 * V_13 , int V_218 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_167 = V_218 ;
F_161 (bond, slave, iter) {
if ( -- V_167 < 0 ) {
if ( F_255 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
}
V_167 = V_218 ;
F_161 (bond, slave, iter) {
if ( -- V_167 < 0 )
break;
if ( F_255 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
F_104 ( V_13 ) ;
}
static T_3 F_256 ( struct V_10 * V_11 )
{
T_3 V_218 ;
struct V_391 V_392 ;
int V_393 = V_11 -> V_29 . V_393 ;
switch ( V_393 ) {
case 0 :
V_218 = F_257 () ;
break;
case 1 :
V_218 = V_11 -> V_394 ;
break;
default:
V_392 =
V_11 -> V_29 . V_392 ;
V_218 = F_258 ( V_11 -> V_394 ,
V_392 ) ;
break;
}
V_11 -> V_394 ++ ;
return V_218 ;
}
static int F_259 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_301 * V_302 = F_219 ( V_13 ) ;
struct V_22 * V_22 ;
T_3 V_218 ;
if ( V_302 -> V_254 == V_395 && V_13 -> V_254 == F_171 ( V_261 ) ) {
V_22 = F_62 ( V_11 -> V_68 ) ;
if ( V_22 && F_255 ( V_22 ) )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_254 ( V_11 , V_13 , 0 ) ;
} else {
V_218 = F_256 ( V_11 ) ;
F_254 ( V_11 , V_13 , V_218 % V_11 -> V_204 ) ;
}
return V_396 ;
}
static int F_260 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 ;
V_22 = F_62 ( V_11 -> V_68 ) ;
if ( V_22 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_104 ( V_13 ) ;
return V_396 ;
}
static int F_261 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_254 ( V_11 , V_13 , F_224 ( V_11 , V_13 , V_11 -> V_204 ) ) ;
return V_396 ;
}
static int F_262 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
F_161 (bond, slave, iter) {
if ( F_263 ( V_11 , V_22 ) )
break;
if ( F_59 ( V_22 -> V_16 ) && V_22 -> V_30 == V_31 ) {
struct V_12 * V_397 = F_264 ( V_13 , V_117 ) ;
if ( ! V_397 ) {
F_113 ( L_110 ,
V_19 -> V_59 ) ;
continue;
}
F_2 ( V_11 , V_397 , V_22 -> V_16 ) ;
}
}
if ( V_22 && F_59 ( V_22 -> V_16 ) && V_22 -> V_30 == V_31 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_104 ( V_13 ) ;
return V_396 ;
}
static inline int F_265 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
if ( ! V_13 -> V_17 )
return 1 ;
F_161 (bond, slave, iter) {
if ( V_22 -> V_182 == V_13 -> V_17 ) {
if ( F_255 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return 0 ;
}
break;
}
}
return 1 ;
}
static T_2 F_266 ( struct V_14 * V_16 , struct V_12 * V_13 ,
void * V_398 , T_11 V_399 )
{
T_2 V_400 = F_267 ( V_13 ) ? F_268 ( V_13 ) : 0 ;
F_4 ( V_13 ) -> V_18 = V_13 -> V_17 ;
if ( F_5 ( V_400 >= V_16 -> V_401 ) ) {
do {
V_400 -= V_16 -> V_401 ;
} while ( V_400 >= V_16 -> V_401 );
}
return V_400 ;
}
static T_12 F_269 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
if ( F_270 ( V_11 -> V_29 . V_1 ) ) {
if ( ! F_265 ( V_11 , V_13 ) )
return V_396 ;
}
switch ( V_11 -> V_29 . V_1 ) {
case V_3 :
return F_259 ( V_13 , V_16 ) ;
case V_4 :
return F_260 ( V_13 , V_16 ) ;
case V_5 :
return F_261 ( V_13 , V_16 ) ;
case V_6 :
return F_262 ( V_13 , V_16 ) ;
case V_7 :
return F_271 ( V_13 , V_16 ) ;
case V_9 :
case V_8 :
return F_272 ( V_13 , V_16 ) ;
default:
F_113 ( L_111 ,
V_16 -> V_59 , V_11 -> V_29 . V_1 ) ;
F_273 ( 1 ) ;
F_104 ( V_13 ) ;
return V_396 ;
}
}
static T_12 F_274 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
T_12 V_149 = V_396 ;
if ( F_275 ( V_16 ) )
return V_402 ;
F_61 () ;
if ( F_19 ( V_11 ) )
V_149 = F_269 ( V_13 , V_16 ) ;
else
F_104 ( V_13 ) ;
F_63 () ;
return V_149 ;
}
static int F_276 ( struct V_14 * V_19 ,
struct V_32 * V_33 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
unsigned long V_35 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
V_33 -> V_37 = V_38 ;
V_33 -> V_403 = V_404 ;
F_156 ( & V_11 -> V_209 ) ;
F_12 (bond, slave, iter) {
if ( F_277 ( V_22 ) ) {
if ( V_22 -> V_35 != V_36 )
V_35 += V_22 -> V_35 ;
if ( V_33 -> V_37 == V_38 &&
V_22 -> V_37 != V_38 )
V_33 -> V_37 = V_22 -> V_37 ;
}
}
F_278 ( V_33 , V_35 ? : V_36 ) ;
F_157 ( & V_11 -> V_209 ) ;
return 0 ;
}
static void F_279 ( struct V_14 * V_19 ,
struct V_405 * V_406 )
{
F_280 ( V_406 -> V_407 , V_408 , sizeof( V_406 -> V_407 ) ) ;
F_280 ( V_406 -> V_409 , V_410 , sizeof( V_406 -> V_409 ) ) ;
snprintf ( V_406 -> V_411 , sizeof( V_406 -> V_411 ) , L_112 ,
V_412 ) ;
}
static void F_281 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_11 -> V_72 )
F_282 ( V_11 -> V_72 ) ;
F_283 ( V_19 ) ;
}
void F_284 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_285 ( & V_11 -> V_209 ) ;
F_285 ( & V_11 -> V_109 ) ;
V_11 -> V_29 = V_413 ;
V_11 -> V_16 = V_19 ;
F_118 ( V_19 ) ;
V_19 -> V_48 = & V_414 ;
V_19 -> V_55 = & V_415 ;
V_19 -> V_416 = F_281 ;
F_286 ( V_19 , & V_417 ) ;
V_19 -> V_418 = 0 ;
V_19 -> V_81 |= V_293 | V_419 ;
V_19 -> V_120 |= V_191 ;
V_19 -> V_120 &= ~ ( V_132 | V_174 ) ;
V_19 -> V_126 |= V_128 ;
V_19 -> V_126 |= V_420 ;
V_19 -> V_126 |= V_421 ;
V_19 -> V_422 = V_134 |
V_423 |
V_424 |
V_425 ;
V_19 -> V_422 &= ~ ( V_426 & ~ V_427 ) ;
V_19 -> V_126 |= V_19 -> V_422 ;
}
static void F_287 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_84 ( V_19 ) ;
F_12 (bond, slave, iter)
F_145 ( V_19 , V_22 -> V_16 , true ) ;
F_66 ( L_113 , V_19 -> V_59 ) ;
F_288 ( & V_11 -> V_428 ) ;
F_289 ( V_11 ) ;
}
int F_290 ( int V_1 , const struct V_429 * V_430 )
{
int V_167 ;
for ( V_167 = 0 ; V_430 [ V_167 ] . V_431 ; V_167 ++ )
if ( V_1 == V_430 [ V_167 ] . V_1 )
return V_430 [ V_167 ] . V_1 ;
return - 1 ;
}
static int F_291 ( const char * V_431 ,
const struct V_429 * V_430 )
{
int V_167 ;
for ( V_167 = 0 ; V_430 [ V_167 ] . V_431 ; V_167 ++ )
if ( strcmp ( V_431 , V_430 [ V_167 ] . V_431 ) == 0 )
return V_430 [ V_167 ] . V_1 ;
return - 1 ;
}
int F_292 ( const char * V_432 , const struct V_429 * V_430 )
{
int V_433 ;
char * V_434 , V_435 [ V_436 + 1 ] ;
for ( V_434 = ( char * ) V_432 ; * V_434 ; V_434 ++ )
if ( ! ( isdigit ( * V_434 ) || isspace ( * V_434 ) ) )
break;
if ( * V_434 && sscanf ( V_432 , L_114 , V_435 ) != 0 )
return F_291 ( V_435 , V_430 ) ;
else if ( sscanf ( V_432 , L_112 , & V_433 ) != 0 )
return F_290 ( V_433 , V_430 ) ;
return - 1 ;
}
static int F_293 ( struct V_437 * V_29 )
{
int V_438 , V_439 , V_440 , V_167 ;
struct V_355 V_356 , * V_441 ;
int V_442 ;
if ( V_1 ) {
F_243 ( & V_356 , V_1 ) ;
V_441 = F_294 ( F_295 ( V_443 ) , & V_356 ) ;
if ( ! V_441 ) {
F_113 ( L_115 , V_1 ) ;
return - V_176 ;
}
V_214 = V_441 -> V_444 ;
}
if ( V_445 ) {
if ( ( V_214 != V_5 ) &&
( V_214 != V_7 ) ) {
F_66 ( L_116 ,
F_1 ( V_214 ) ) ;
} else {
F_243 ( & V_356 , V_445 ) ;
V_441 = F_294 ( F_295 ( V_446 ) ,
& V_356 ) ;
if ( ! V_441 ) {
F_113 ( L_117 ,
V_445 ) ;
return - V_176 ;
}
V_447 = V_441 -> V_444 ;
}
}
if ( V_448 ) {
if ( V_214 != V_7 ) {
F_66 ( L_118 ,
F_1 ( V_214 ) ) ;
} else {
F_243 ( & V_356 , V_448 ) ;
V_441 = F_294 ( F_295 ( V_449 ) ,
& V_356 ) ;
if ( ! V_441 ) {
F_113 ( L_119 ,
V_448 ) ;
return - V_176 ;
}
V_450 = V_441 -> V_444 ;
}
}
if ( V_451 ) {
F_243 ( & V_356 , V_448 ) ;
V_441 = F_294 ( F_295 ( V_452 ) ,
& V_356 ) ;
if ( ! V_441 ) {
F_113 ( L_120 , V_451 ) ;
return - V_176 ;
}
V_29 -> V_451 = V_441 -> V_444 ;
if ( V_214 != V_7 )
F_112 ( L_121 ) ;
} else {
V_29 -> V_451 = V_453 ;
}
if ( V_454 < 0 ) {
F_112 ( L_122 ,
V_454 , 0 , V_455 , V_456 ) ;
V_454 = V_456 ;
}
if ( V_104 < 0 ) {
F_112 ( L_123 ,
V_104 , V_455 ) ;
V_104 = 0 ;
}
if ( V_98 < 0 ) {
F_112 ( L_124 ,
V_98 , V_455 ) ;
V_98 = 0 ;
}
if ( V_225 < 0 ) {
F_112 ( L_125 ,
V_225 , V_455 ) ;
V_225 = 0 ;
}
if ( ( V_53 != 0 ) && ( V_53 != 1 ) ) {
F_112 ( L_126 ,
V_53 ) ;
V_53 = 1 ;
}
if ( V_108 < 0 || V_108 > 255 ) {
F_112 ( L_127 ,
V_108 ) ;
V_108 = 1 ;
}
if ( F_296 ( V_214 ) ) {
if ( ! V_104 ) {
F_112 ( L_128 ) ;
F_112 ( L_129 ) ;
V_104 = V_457 ;
}
}
if ( V_458 < 1 || V_458 > 255 ) {
F_112 ( L_130
L_131 ,
V_458 , V_459 ) ;
V_458 = V_459 ;
}
if ( ( V_460 != 0 ) && ( V_460 != 1 ) ) {
F_112 ( L_132
L_133
L_134 , V_460 ) ;
V_460 = 0 ;
}
if ( V_112 < 0 || V_112 > 255 ) {
F_112 ( L_135
L_136 ,
V_112 , V_461 ) ;
V_112 = V_461 ;
}
F_297 ( & V_356 , V_393 ) ;
if ( ! F_294 ( F_295 ( V_462 ) , & V_356 ) ) {
F_119 ( L_137 ,
V_393 , V_463 ) ;
V_393 = 1 ;
}
if ( V_214 == V_9 ) {
F_298 ( L_138 ,
V_98 ) ;
}
if ( ! V_104 ) {
if ( V_98 || V_225 ) {
F_112 ( L_139 ,
V_98 , V_225 ) ;
}
} else {
if ( V_152 ) {
F_112 ( L_140 ,
V_104 , V_152 ) ;
V_152 = 0 ;
}
if ( ( V_98 % V_104 ) != 0 ) {
F_112 ( L_141 ,
V_98 , V_104 ,
( V_98 / V_104 ) * V_104 ) ;
}
V_98 /= V_104 ;
if ( ( V_225 % V_104 ) != 0 ) {
F_112 ( L_142 ,
V_225 , V_104 ,
( V_225 / V_104 ) * V_104 ) ;
}
V_225 /= V_104 ;
}
if ( V_152 < 0 ) {
F_112 ( L_143 ,
V_152 , V_455 ) ;
V_152 = 0 ;
}
for ( V_464 = 0 , V_167 = 0 ;
( V_464 < V_195 ) && V_465 [ V_167 ] ; V_167 ++ ) {
T_9 V_230 ;
if ( ! F_299 ( V_465 [ V_167 ] , - 1 , ( T_5 * ) & V_230 , - 1 , NULL ) ||
F_300 ( V_230 ) ) {
F_112 ( L_144 ,
V_465 [ V_167 ] ) ;
V_152 = 0 ;
} else {
if ( F_181 ( V_466 , V_230 ) == - 1 )
V_466 [ V_464 ++ ] = V_230 ;
else
F_112 ( L_145 ,
& V_230 ) ;
}
}
if ( V_152 && ! V_464 ) {
F_112 ( L_146 ,
V_152 ) ;
V_152 = 0 ;
}
if ( V_263 ) {
if ( V_214 != V_4 ) {
F_113 ( L_147 ) ;
return - V_176 ;
}
if ( ! V_152 ) {
F_113 ( L_148 ) ;
return - V_176 ;
}
F_243 ( & V_356 , V_263 ) ;
V_441 = F_294 ( F_295 ( V_467 ) ,
& V_356 ) ;
if ( ! V_441 ) {
F_113 ( L_149 ,
V_263 ) ;
return - V_176 ;
}
V_438 = V_441 -> V_444 ;
} else {
V_438 = 0 ;
}
V_442 = 0 ;
if ( V_468 ) {
F_243 ( & V_356 , V_468 ) ;
V_441 = F_294 ( F_295 ( V_469 ) ,
& V_356 ) ;
if ( ! V_441 ) {
F_113 ( L_150 ,
V_468 ) ;
V_442 = 0 ;
} else {
V_442 = V_441 -> V_444 ;
}
}
if ( V_104 ) {
F_66 ( L_151 , V_104 ) ;
} else if ( V_152 ) {
V_441 = F_301 ( V_467 ,
V_438 ) ;
F_66 ( L_152 ,
V_152 , V_441 -> string , V_464 ) ;
for ( V_167 = 0 ; V_167 < V_464 ; V_167 ++ )
F_66 ( L_153 , V_465 [ V_167 ] ) ;
F_66 ( L_154 ) ;
} else if ( V_454 ) {
F_55 ( L_155 ) ;
}
if ( V_197 && ! F_34 ( V_214 ) ) {
F_112 ( L_156 ,
V_197 , F_1 ( V_214 ) ) ;
V_197 = NULL ;
}
if ( V_197 && V_93 ) {
F_243 ( & V_356 , V_93 ) ;
V_441 = F_294 ( F_295 ( V_470 ) ,
& V_356 ) ;
if ( ! V_441 ) {
F_113 ( L_157 ,
V_93 ) ;
return - V_176 ;
}
V_440 = V_441 -> V_444 ;
} else {
V_440 = V_471 ;
}
if ( V_107 ) {
F_243 ( & V_356 , V_107 ) ;
V_441 = F_294 ( F_295 ( V_472 ) ,
& V_356 ) ;
if ( ! V_441 ) {
F_113 ( L_158 ,
V_107 ) ;
return - V_176 ;
}
V_439 = V_441 -> V_444 ;
if ( V_214 != V_4 )
F_112 ( L_159 ) ;
} else {
V_439 = V_473 ;
}
if ( V_474 == 0 ) {
F_112 ( L_160 ,
V_455 , V_475 ) ;
V_474 = V_475 ;
}
V_29 -> V_1 = V_214 ;
V_29 -> V_304 = V_447 ;
V_29 -> V_104 = V_104 ;
V_29 -> V_108 = V_108 ;
V_29 -> V_152 = V_152 ;
V_29 -> V_263 = V_438 ;
V_29 -> V_468 = V_442 ;
V_29 -> V_98 = V_98 ;
V_29 -> V_225 = V_225 ;
V_29 -> V_53 = V_53 ;
V_29 -> V_450 = V_450 ;
V_29 -> V_197 [ 0 ] = 0 ;
V_29 -> V_93 = V_440 ;
V_29 -> V_107 = V_439 ;
V_29 -> V_458 = V_458 ;
V_29 -> V_460 = V_460 ;
V_29 -> V_112 = V_112 ;
V_29 -> V_476 = V_476 ;
V_29 -> V_474 = V_474 ;
V_29 -> V_393 = V_393 ;
if ( V_393 > 0 ) {
V_29 -> V_392 =
V_391 ( V_393 ) ;
} else {
V_29 -> V_392 =
(struct V_391 ) { 0 } ;
}
if ( V_197 ) {
strncpy ( V_29 -> V_197 , V_197 , V_60 ) ;
V_29 -> V_197 [ V_60 - 1 ] = 0 ;
}
memcpy ( V_29 -> V_243 , V_466 , sizeof( V_466 ) ) ;
return 0 ;
}
static void F_302 ( struct V_14 * V_16 ,
struct V_477 * V_400 ,
void * V_478 )
{
F_303 ( & V_400 -> V_479 ,
& V_480 ) ;
}
static void F_304 ( struct V_14 * V_16 )
{
F_303 ( & V_16 -> V_481 ,
& V_482 ) ;
F_305 ( V_16 , F_302 , NULL ) ;
V_16 -> V_483 = & V_484 ;
}
static int F_306 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_485 * V_486 = F_307 ( F_175 ( V_19 ) , V_487 ) ;
struct V_488 * V_489 = & ( F_308 ( V_11 ) ) ;
F_55 ( L_161 , V_19 -> V_59 ) ;
F_309 ( & ( V_489 -> V_490 ) ) ;
F_309 ( & ( V_489 -> V_491 ) ) ;
V_11 -> V_72 = F_310 ( V_19 -> V_59 ) ;
if ( ! V_11 -> V_72 )
return - V_118 ;
F_304 ( V_19 ) ;
F_311 ( & V_11 -> V_428 , & V_486 -> V_492 ) ;
F_312 ( V_11 ) ;
F_313 ( V_11 ) ;
if ( F_314 ( V_19 -> V_85 ) &&
V_19 -> V_86 == V_493 )
F_144 ( V_19 ) ;
return 0 ;
}
unsigned int F_315 ( void )
{
return V_458 ;
}
int F_316 ( struct V_357 * V_357 , const char * V_59 )
{
struct V_14 * V_19 ;
int V_26 ;
F_317 () ;
V_19 = F_318 ( sizeof( struct V_10 ) ,
V_59 ? V_59 : L_162 ,
F_284 , V_458 ) ;
if ( ! V_19 ) {
F_113 ( L_163 , V_59 ) ;
F_43 () ;
return - V_118 ;
}
F_319 ( V_19 , V_357 ) ;
V_19 -> V_494 = & V_495 ;
V_26 = F_320 ( V_19 ) ;
F_23 ( V_19 ) ;
F_43 () ;
if ( V_26 < 0 )
F_281 ( V_19 ) ;
return V_26 ;
}
static int T_13 F_321 ( struct V_357 * V_357 )
{
struct V_485 * V_486 = F_307 ( V_357 , V_487 ) ;
V_486 -> V_357 = V_357 ;
F_322 ( & V_486 -> V_492 ) ;
F_323 ( V_486 ) ;
F_324 ( V_486 ) ;
return 0 ;
}
static void T_14 F_325 ( struct V_357 * V_357 )
{
struct V_485 * V_486 = F_307 ( V_357 , V_487 ) ;
struct V_10 * V_11 , * V_496 ;
F_326 ( V_497 ) ;
F_327 ( V_486 ) ;
F_328 ( V_486 ) ;
F_317 () ;
F_329 (bond, tmp_bond, &bn->dev_list, bond_list)
F_330 ( V_11 -> V_16 , & V_497 ) ;
F_331 ( & V_497 ) ;
F_43 () ;
}
static int T_15 F_332 ( void )
{
int V_167 ;
int V_26 ;
F_66 ( L_164 , V_498 ) ;
V_26 = F_293 ( & V_413 ) ;
if ( V_26 )
goto V_119;
V_26 = F_333 ( & V_499 ) ;
if ( V_26 )
goto V_119;
V_26 = F_334 () ;
if ( V_26 )
goto V_500;
F_335 () ;
for ( V_167 = 0 ; V_167 < V_454 ; V_167 ++ ) {
V_26 = F_316 ( & V_501 , NULL ) ;
if ( V_26 )
goto V_67;
}
F_336 ( & V_502 ) ;
V_119:
return V_26 ;
V_67:
F_337 () ;
V_500:
F_338 ( & V_499 ) ;
goto V_119;
}
static void T_16 F_339 ( void )
{
F_340 ( & V_502 ) ;
F_341 () ;
F_337 () ;
F_338 ( & V_499 ) ;
#ifdef F_134
F_342 ( F_343 ( & V_503 ) ) ;
#endif
}
