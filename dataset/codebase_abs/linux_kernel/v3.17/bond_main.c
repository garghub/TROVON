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
if ( F_20 ( V_11 ) == V_7 )
return F_21 ( V_11 ) ;
F_12 (bond, slave, iter) {
if ( V_22 -> V_29 == V_30 ) {
if ( ! F_22 ( V_11 -> V_16 ) ) {
F_23 ( V_11 -> V_16 ) ;
return 1 ;
}
return 0 ;
}
}
V_28:
if ( F_22 ( V_11 -> V_16 ) ) {
F_24 ( V_11 -> V_16 ) ;
return 1 ;
}
return 0 ;
}
static void F_25 ( struct V_22 * V_22 )
{
struct V_14 * V_15 = V_22 -> V_16 ;
struct V_31 V_32 ;
T_3 V_33 ;
int V_26 ;
V_22 -> V_34 = V_35 ;
V_22 -> V_36 = V_37 ;
V_26 = F_26 ( V_15 , & V_32 ) ;
if ( V_26 < 0 )
return;
V_33 = F_27 ( & V_32 ) ;
if ( V_33 == 0 || V_33 == ( ( V_38 ) - 1 ) )
return;
switch ( V_32 . V_36 ) {
case V_39 :
case V_40 :
break;
default:
return;
}
V_22 -> V_34 = V_33 ;
V_22 -> V_36 = V_32 . V_36 ;
return;
}
const char * F_28 ( T_4 V_29 )
{
switch ( V_29 ) {
case V_30 :
return L_9 ;
case V_41 :
return L_10 ;
case V_42 :
return L_11 ;
case V_43 :
return L_12 ;
default:
return L_8 ;
}
}
static int F_29 ( struct V_10 * V_11 ,
struct V_14 * V_15 , int V_44 )
{
const struct V_45 * V_46 = V_15 -> V_47 ;
int (* F_30)( struct V_14 * , struct V_48 * , int );
struct V_48 V_49 ;
struct V_50 * V_51 ;
if ( ! V_44 && ! F_31 ( V_15 ) )
return 0 ;
if ( V_11 -> V_52 . V_53 )
return F_22 ( V_15 ) ? V_54 : 0 ;
if ( V_15 -> V_55 -> V_56 )
return V_15 -> V_55 -> V_56 ( V_15 ) ?
V_54 : 0 ;
F_30 = V_46 -> V_57 ;
if ( F_30 ) {
strncpy ( V_49 . V_58 , V_15 -> V_59 , V_60 ) ;
V_51 = F_32 ( & V_49 ) ;
if ( F_33 ( V_15 , & V_49 , V_61 ) == 0 ) {
V_51 -> V_62 = V_63 ;
if ( F_33 ( V_15 , & V_49 , V_64 ) == 0 )
return V_51 -> V_65 & V_54 ;
}
}
return V_44 ? - 1 : V_54 ;
}
static int F_34 ( struct V_10 * V_11 , int V_66 )
{
struct V_24 * V_25 ;
int V_67 = 0 ;
if ( F_35 ( V_11 ) ) {
struct V_22 * V_68 = F_36 ( V_11 -> V_69 ) ;
if ( V_68 )
V_67 = F_37 ( V_68 -> V_16 , V_66 ) ;
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
static int F_38 ( struct V_10 * V_11 , int V_66 )
{
struct V_24 * V_25 ;
int V_67 = 0 ;
if ( F_35 ( V_11 ) ) {
struct V_22 * V_68 = F_36 ( V_11 -> V_69 ) ;
if ( V_68 )
V_67 = F_39 ( V_68 -> V_16 , V_66 ) ;
} else {
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
V_67 = F_39 ( V_22 -> V_16 , V_66 ) ;
if ( V_67 )
return V_67 ;
}
}
return V_67 ;
}
static void F_40 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_72 . V_71 ) ;
if ( ! F_42 () ) {
F_43 ( V_11 -> V_73 , & V_11 -> V_72 , 1 ) ;
return;
}
F_44 ( V_74 , V_11 -> V_16 ) ;
if ( V_11 -> V_75 > 1 ) {
V_11 -> V_75 -- ;
F_43 ( V_11 -> V_73 , & V_11 -> V_72 , V_76 / 5 ) ;
}
F_45 () ;
}
static void F_46 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_47 ( V_15 , V_19 ) ;
F_48 ( V_15 , V_19 ) ;
if ( F_20 ( V_11 ) == V_7 ) {
T_5 V_77 [ V_78 ] = V_79 ;
F_49 ( V_15 , V_77 ) ;
}
}
static void F_50 ( struct V_10 * V_11 , struct V_22 * V_80 ,
struct V_22 * V_81 )
{
F_51 () ;
if ( V_81 ) {
if ( V_11 -> V_16 -> V_82 & V_83 )
F_37 ( V_81 -> V_16 , - 1 ) ;
if ( V_11 -> V_16 -> V_82 & V_84 )
F_39 ( V_81 -> V_16 , - 1 ) ;
F_46 ( V_11 -> V_16 , V_81 -> V_16 ) ;
}
if ( V_80 ) {
if ( V_11 -> V_16 -> V_82 & V_83 )
F_37 ( V_80 -> V_16 , 1 ) ;
if ( V_11 -> V_16 -> V_82 & V_84 )
F_39 ( V_80 -> V_16 , 1 ) ;
F_52 ( V_11 -> V_16 ) ;
F_53 ( V_80 -> V_16 , V_11 -> V_16 ) ;
F_54 ( V_80 -> V_16 , V_11 -> V_16 ) ;
F_55 ( V_11 -> V_16 ) ;
}
}
static void F_56 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
F_57 ( V_19 , L_13 ,
V_19 , V_15 , V_15 -> V_85 ) ;
memcpy ( V_19 -> V_86 , V_15 -> V_86 , V_15 -> V_85 ) ;
V_19 -> V_87 = V_88 ;
F_44 ( V_89 , V_19 ) ;
}
static void F_58 ( struct V_10 * V_11 ,
struct V_22 * V_80 ,
struct V_22 * V_81 )
__releases( &bond->curr_slave_lock
static bool F_59 ( struct V_10 * V_11 )
{
struct V_22 * V_90 = V_11 -> V_91 ;
struct V_22 * V_92 = F_60 ( V_11 ) ;
if ( ! V_90 || ! V_92 || V_92 -> V_29 != V_30 )
return true ;
if ( V_11 -> V_93 ) {
V_11 -> V_93 = false ;
return true ;
}
if ( V_11 -> V_52 . V_94 == V_95 &&
( V_90 -> V_34 < V_92 -> V_34 ||
( V_90 -> V_34 == V_92 -> V_34 && V_90 -> V_36 <= V_92 -> V_36 ) ) )
return false ;
if ( V_11 -> V_52 . V_94 == V_96 )
return false ;
return true ;
}
static struct V_22 * F_61 ( struct V_10 * V_11 )
{
struct V_22 * V_22 , * V_97 = NULL ;
struct V_24 * V_25 ;
int V_98 = V_11 -> V_52 . V_99 ;
if ( V_11 -> V_91 && V_11 -> V_91 -> V_29 == V_30 &&
F_59 ( V_11 ) )
return V_11 -> V_91 ;
F_12 (bond, slave, iter) {
if ( V_22 -> V_29 == V_30 )
return V_22 ;
if ( V_22 -> V_29 == V_43 && F_62 ( V_22 ) &&
V_22 -> V_100 < V_98 ) {
V_98 = V_22 -> V_100 ;
V_97 = V_22 ;
}
}
return V_97 ;
}
static bool F_63 ( struct V_10 * V_11 )
{
struct V_22 * V_22 ;
F_64 () ;
V_22 = F_65 ( V_11 -> V_69 ) ;
F_66 () ;
F_57 ( V_11 -> V_16 , L_14 ,
V_22 ? V_22 -> V_16 -> V_59 : L_15 ) ;
if ( ! V_22 || ! V_11 -> V_101 ||
F_67 ( V_102 , & V_22 -> V_16 -> V_103 ) )
return false ;
return true ;
}
void F_68 ( struct V_10 * V_11 , struct V_22 * V_80 )
{
struct V_22 * V_81 ;
V_81 = F_69 ( V_11 -> V_69 ,
! V_80 ||
F_70 ( & V_11 -> V_104 ) ) ;
if ( V_81 == V_80 )
return;
if ( V_80 ) {
V_80 -> V_105 = V_106 ;
if ( V_80 -> V_29 == V_43 ) {
if ( F_35 ( V_11 ) ) {
F_71 ( V_11 -> V_16 , L_16 ,
V_80 -> V_16 -> V_59 ,
( V_11 -> V_52 . V_99 - V_80 -> V_100 ) * V_11 -> V_52 . V_107 ) ;
}
V_80 -> V_100 = 0 ;
V_80 -> V_29 = V_30 ;
if ( F_20 ( V_11 ) == V_7 )
F_72 ( V_80 , V_30 ) ;
if ( F_16 ( V_11 ) )
F_73 ( V_11 , V_80 , V_30 ) ;
} else {
if ( F_35 ( V_11 ) ) {
F_71 ( V_11 -> V_16 , L_17 ,
V_80 -> V_16 -> V_59 ) ;
}
}
}
if ( F_35 ( V_11 ) )
F_50 ( V_11 , V_80 , V_81 ) ;
if ( F_16 ( V_11 ) ) {
F_74 ( V_11 , V_80 ) ;
if ( V_81 )
F_75 ( V_81 ,
V_108 ) ;
if ( V_80 )
F_76 ( V_80 ,
V_108 ) ;
} else {
F_77 ( V_11 -> V_69 , V_80 ) ;
}
if ( F_20 ( V_11 ) == V_4 ) {
if ( V_81 )
F_75 ( V_81 ,
V_108 ) ;
if ( V_80 ) {
bool V_109 = false ;
F_76 ( V_80 ,
V_108 ) ;
if ( V_11 -> V_52 . V_110 )
F_58 ( V_11 , V_80 ,
V_81 ) ;
if ( F_31 ( V_11 -> V_16 ) ) {
V_11 -> V_101 =
V_11 -> V_52 . V_111 ;
V_109 =
F_63 ( V_11 ) ;
}
F_78 ( & V_11 -> V_104 ) ;
F_44 ( V_112 , V_11 -> V_16 ) ;
if ( V_109 )
F_44 ( V_113 ,
V_11 -> V_16 ) ;
F_79 ( & V_11 -> V_104 ) ;
}
}
if ( F_31 ( V_11 -> V_16 ) && ( V_11 -> V_52 . V_114 > 0 ) &&
( ( F_35 ( V_11 ) && V_80 ) ||
F_20 ( V_11 ) == V_3 ) ) {
V_11 -> V_75 = V_11 -> V_52 . V_114 ;
F_43 ( V_11 -> V_73 , & V_11 -> V_72 , 1 ) ;
}
}
void F_80 ( struct V_10 * V_11 )
{
struct V_22 * V_115 ;
int V_116 ;
V_115 = F_61 ( V_11 ) ;
if ( V_115 != F_60 ( V_11 ) ) {
F_68 ( V_11 , V_115 ) ;
V_116 = F_18 ( V_11 ) ;
if ( ! V_116 )
return;
if ( F_22 ( V_11 -> V_16 ) ) {
F_71 ( V_11 -> V_16 , L_18 ) ;
} else {
F_71 ( V_11 -> V_16 , L_19 ) ;
}
}
}
static inline int F_81 ( struct V_22 * V_22 )
{
struct V_117 * V_118 ;
int V_67 = 0 ;
V_118 = F_82 ( sizeof( * V_118 ) , V_119 ) ;
V_67 = - V_120 ;
if ( ! V_118 )
goto V_121;
V_67 = F_83 ( V_118 , V_22 -> V_16 ) ;
if ( V_67 ) {
F_84 ( V_118 ) ;
goto V_121;
}
V_22 -> V_118 = V_118 ;
V_121:
return V_67 ;
}
static inline void F_85 ( struct V_22 * V_22 )
{
struct V_117 * V_118 = V_22 -> V_118 ;
if ( ! V_118 )
return;
V_22 -> V_118 = NULL ;
F_86 ( V_118 ) ;
}
static void F_87 ( struct V_14 * V_19 )
{
}
static void F_88 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter)
if ( F_62 ( V_22 ) )
F_85 ( V_22 ) ;
}
static int F_89 ( struct V_14 * V_16 , struct V_122 * V_123 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_67 = 0 ;
F_12 (bond, slave, iter) {
V_67 = F_81 ( V_22 ) ;
if ( V_67 ) {
F_88 ( V_16 ) ;
break;
}
}
return V_67 ;
}
static inline int F_81 ( struct V_22 * V_22 )
{
return 0 ;
}
static inline void F_85 ( struct V_22 * V_22 )
{
}
static void F_88 ( struct V_14 * V_19 )
{
}
static T_6 F_90 ( struct V_14 * V_16 ,
T_6 V_124 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_24 * V_25 ;
T_6 V_125 ;
struct V_22 * V_22 ;
V_125 = V_124 ;
V_124 &= ~ V_126 ;
V_124 |= V_127 ;
F_12 (bond, slave, iter) {
V_124 = F_91 ( V_124 ,
V_22 -> V_16 -> V_124 ,
V_125 ) ;
}
V_124 = F_92 ( V_124 , V_125 ) ;
return V_124 ;
}
static void F_93 ( struct V_10 * V_11 )
{
unsigned int V_82 , V_128 = V_129 ;
T_6 V_130 = V_131 ;
T_6 V_132 = V_133 ;
struct V_14 * V_19 = V_11 -> V_16 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
unsigned short V_134 = V_135 ;
unsigned int V_136 = V_137 ;
T_2 V_138 = V_139 ;
if ( ! F_19 ( V_11 ) )
goto V_140;
V_130 &= V_127 ;
F_12 (bond, slave, iter) {
V_130 = F_91 ( V_130 ,
V_22 -> V_16 -> V_130 , V_131 ) ;
V_132 = F_91 ( V_132 ,
V_22 -> V_16 -> V_141 ,
V_133 ) ;
V_128 &= V_22 -> V_16 -> V_142 ;
if ( V_22 -> V_16 -> V_143 > V_134 )
V_134 = V_22 -> V_16 -> V_143 ;
V_136 = F_94 ( V_136 , V_22 -> V_16 -> V_136 ) ;
V_138 = F_94 ( V_138 , V_22 -> V_16 -> V_138 ) ;
}
V_140:
V_19 -> V_130 = V_130 ;
V_19 -> V_141 = V_132 ;
V_19 -> V_143 = V_134 ;
V_19 -> V_138 = V_138 ;
F_95 ( V_19 , V_136 ) ;
V_82 = V_19 -> V_142 & ~ V_129 ;
V_19 -> V_142 = V_82 | V_128 ;
F_96 ( V_19 ) ;
}
static void F_97 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
V_19 -> V_144 = V_15 -> V_144 ;
V_19 -> type = V_15 -> type ;
V_19 -> V_143 = V_15 -> V_143 ;
V_19 -> V_85 = V_15 -> V_85 ;
memcpy ( V_19 -> V_145 , V_15 -> V_145 ,
V_15 -> V_85 ) ;
}
static bool F_98 ( struct V_12 * V_13 ,
struct V_22 * V_22 ,
struct V_10 * V_11 )
{
if ( F_99 ( V_22 ) ) {
if ( F_20 ( V_11 ) == V_9 &&
V_13 -> V_146 != V_147 &&
V_13 -> V_146 != V_148 )
return false ;
return true ;
}
return false ;
}
static T_7 F_100 ( struct V_12 * * V_149 )
{
struct V_12 * V_13 = * V_149 ;
struct V_22 * V_22 ;
struct V_10 * V_11 ;
int (* F_101)( const struct V_12 * , struct V_10 * ,
struct V_22 * );
int V_150 = V_151 ;
V_13 = F_102 ( V_13 , V_152 ) ;
if ( F_5 ( ! V_13 ) )
return V_153 ;
* V_149 = V_13 ;
V_22 = F_103 ( V_13 -> V_16 ) ;
V_11 = V_22 -> V_11 ;
F_101 = F_104 ( V_11 -> F_101 ) ;
if ( F_101 ) {
V_150 = F_101 ( V_13 , V_11 , V_22 ) ;
if ( V_150 == V_153 ) {
F_105 ( V_13 ) ;
return V_150 ;
}
}
if ( F_98 ( V_13 , V_22 , V_11 ) ) {
return V_154 ;
}
V_13 -> V_16 = V_11 -> V_16 ;
if ( F_20 ( V_11 ) == V_9 &&
V_11 -> V_16 -> V_142 & V_155 &&
V_13 -> V_146 == V_156 ) {
if ( F_5 ( F_106 ( V_13 ,
V_13 -> V_157 - F_107 ( V_13 ) ) ) ) {
F_108 ( V_13 ) ;
return V_153 ;
}
F_109 ( F_110 ( V_13 ) -> V_158 , V_11 -> V_16 -> V_86 ) ;
}
return V_150 ;
}
static int F_111 ( struct V_14 * V_19 ,
struct V_14 * V_15 ,
struct V_22 * V_22 )
{
int V_67 ;
V_67 = F_112 ( V_15 , V_19 , V_22 ) ;
if ( V_67 )
return V_67 ;
V_15 -> V_82 |= V_159 ;
F_113 ( V_160 , V_15 , V_159 , V_119 ) ;
return 0 ;
}
static void F_114 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
F_115 ( V_15 , V_19 ) ;
V_15 -> V_82 &= ~ V_159 ;
F_113 ( V_160 , V_15 , V_159 , V_119 ) ;
}
static struct V_22 * F_116 ( struct V_10 * V_11 )
{
struct V_22 * V_22 = NULL ;
V_22 = F_82 ( sizeof( struct V_22 ) , V_119 ) ;
if ( ! V_22 )
return NULL ;
if ( F_20 ( V_11 ) == V_7 ) {
F_117 ( V_22 ) = F_82 ( sizeof( struct V_161 ) ,
V_119 ) ;
if ( ! F_117 ( V_22 ) ) {
F_84 ( V_22 ) ;
return NULL ;
}
}
return V_22 ;
}
static void F_118 ( struct V_22 * V_22 )
{
struct V_10 * V_11 = F_119 ( V_22 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_84 ( F_117 ( V_22 ) ) ;
F_84 ( V_22 ) ;
}
int F_120 ( struct V_14 * V_19 , struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
const struct V_45 * V_46 = V_15 -> V_47 ;
struct V_22 * V_162 = NULL , * V_163 ;
struct V_164 V_165 ;
int V_166 ;
int V_26 = 0 , V_167 ;
if ( ! V_11 -> V_52 . V_53 &&
V_15 -> V_55 -> V_56 == NULL &&
V_46 -> V_57 == NULL ) {
F_121 ( V_19 , L_20 ,
V_15 -> V_59 ) ;
}
if ( V_15 -> V_82 & V_159 ) {
F_57 ( V_19 , L_21 ) ;
return - V_168 ;
}
if ( V_19 == V_15 ) {
F_122 ( V_19 , L_22 ) ;
return - V_169 ;
}
if ( V_15 -> V_124 & V_170 ) {
F_57 ( V_19 , L_23 ,
V_15 -> V_59 ) ;
if ( F_123 ( V_19 ) ) {
F_122 ( V_19 , L_24 ,
V_15 -> V_59 , V_19 -> V_59 ) ;
return - V_169 ;
} else {
F_121 ( V_19 , L_25 ,
V_15 -> V_59 , V_15 -> V_59 ,
V_19 -> V_59 ) ;
}
} else {
F_57 ( V_19 , L_26 ,
V_15 -> V_59 ) ;
}
if ( ( V_15 -> V_82 & V_171 ) ) {
F_122 ( V_19 , L_27 ,
V_15 -> V_59 ) ;
V_26 = - V_169 ;
goto V_172;
}
if ( ! F_19 ( V_11 ) ) {
if ( V_19 -> type != V_15 -> type ) {
F_57 ( V_19 , L_28 ,
V_19 -> type , V_15 -> type ) ;
V_26 = F_44 ( V_173 ,
V_19 ) ;
V_26 = F_124 ( V_26 ) ;
if ( V_26 ) {
F_122 ( V_19 , L_29 ) ;
V_26 = - V_168 ;
goto V_172;
}
F_125 ( V_19 ) ;
F_126 ( V_19 ) ;
if ( V_15 -> type != V_174 )
F_97 ( V_19 , V_15 ) ;
else {
F_127 ( V_19 ) ;
V_19 -> V_142 &= ~ V_175 ;
}
F_44 ( V_176 ,
V_19 ) ;
}
} else if ( V_19 -> type != V_15 -> type ) {
F_122 ( V_19 , L_30 ,
V_15 -> V_59 , V_15 -> type , V_19 -> type ) ;
V_26 = - V_177 ;
goto V_172;
}
if ( V_46 -> V_178 == NULL ) {
F_121 ( V_19 , L_31 ) ;
if ( F_20 ( V_11 ) == V_4 &&
V_11 -> V_52 . V_110 != V_179 ) {
if ( ! F_19 ( V_11 ) ) {
V_11 -> V_52 . V_110 = V_179 ;
F_121 ( V_19 , L_32 ) ;
} else {
F_122 ( V_19 , L_33 ) ;
V_26 = - V_180 ;
goto V_172;
}
}
}
F_44 ( V_181 , V_15 ) ;
if ( ! F_19 ( V_11 ) &&
V_11 -> V_16 -> V_87 == V_182 )
F_56 ( V_11 -> V_16 , V_15 ) ;
V_162 = F_116 ( V_11 ) ;
if ( ! V_162 ) {
V_26 = - V_120 ;
goto V_172;
}
V_162 -> V_11 = V_11 ;
V_162 -> V_16 = V_15 ;
V_162 -> V_183 = 0 ;
V_162 -> V_184 = V_15 -> V_185 ;
V_26 = F_128 ( V_15 , V_11 -> V_16 -> V_185 ) ;
if ( V_26 ) {
F_57 ( V_19 , L_34 , V_26 ) ;
goto V_186;
}
F_109 ( V_162 -> V_187 , V_15 -> V_86 ) ;
if ( ! V_11 -> V_52 . V_110 ||
F_20 ( V_11 ) != V_4 ) {
memcpy ( V_165 . V_188 , V_19 -> V_86 , V_19 -> V_85 ) ;
V_165 . V_189 = V_15 -> type ;
V_26 = F_129 ( V_15 , & V_165 ) ;
if ( V_26 ) {
F_57 ( V_19 , L_35 , V_26 ) ;
goto V_190;
}
}
V_26 = F_130 ( V_15 ) ;
if ( V_26 ) {
F_57 ( V_19 , L_36 , V_15 -> V_59 ) ;
goto V_191;
}
V_15 -> V_142 |= V_192 ;
if ( F_16 ( V_11 ) ) {
V_26 = F_131 ( V_11 , V_162 ) ;
if ( V_26 )
goto V_193;
}
if ( ! F_35 ( V_11 ) ) {
if ( V_19 -> V_82 & V_83 ) {
V_26 = F_37 ( V_15 , 1 ) ;
if ( V_26 )
goto V_193;
}
if ( V_19 -> V_82 & V_84 ) {
V_26 = F_39 ( V_15 , 1 ) ;
if ( V_26 )
goto V_193;
}
F_52 ( V_19 ) ;
F_132 ( V_15 , V_19 ) ;
F_133 ( V_15 , V_19 ) ;
F_55 ( V_19 ) ;
}
if ( F_20 ( V_11 ) == V_7 ) {
T_5 V_77 [ V_78 ] = V_79 ;
F_134 ( V_15 , V_77 ) ;
}
V_26 = F_135 ( V_15 , V_19 ) ;
if ( V_26 ) {
F_122 ( V_19 , L_37 ,
V_15 -> V_59 ) ;
goto V_193;
}
V_163 = F_136 ( V_11 ) ;
V_162 -> V_100 = 0 ;
V_162 -> V_194 = 0 ;
F_25 ( V_162 ) ;
V_162 -> V_195 = V_106 -
( F_137 ( V_11 -> V_52 . V_196 ) + 1 ) ;
for ( V_167 = 0 ; V_167 < V_197 ; V_167 ++ )
V_162 -> V_198 [ V_167 ] = V_162 -> V_195 ;
if ( V_11 -> V_52 . V_107 && ! V_11 -> V_52 . V_53 ) {
V_166 = F_29 ( V_11 , V_15 , 1 ) ;
if ( ( V_166 == - 1 ) && ! V_11 -> V_52 . V_196 ) {
F_121 ( V_19 , L_38 ,
V_15 -> V_59 ) ;
} else if ( V_166 == - 1 ) {
F_121 ( V_19 , L_39 ,
V_15 -> V_59 ) ;
}
}
if ( V_11 -> V_52 . V_107 ) {
if ( F_29 ( V_11 , V_15 , 0 ) == V_54 ) {
if ( V_11 -> V_52 . V_99 ) {
V_162 -> V_29 = V_43 ;
V_162 -> V_100 = V_11 -> V_52 . V_99 ;
} else {
V_162 -> V_29 = V_30 ;
}
} else {
V_162 -> V_29 = V_42 ;
}
} else if ( V_11 -> V_52 . V_196 ) {
V_162 -> V_29 = ( F_22 ( V_15 ) ?
V_30 : V_42 ) ;
} else {
V_162 -> V_29 = V_30 ;
}
if ( V_162 -> V_29 != V_42 )
V_162 -> V_105 = V_106 ;
F_57 ( V_19 , L_40 ,
V_162 -> V_29 == V_42 ? L_41 :
( V_162 -> V_29 == V_30 ? L_42 : L_43 ) ) ;
if ( F_35 ( V_11 ) && V_11 -> V_52 . V_199 [ 0 ] ) {
if ( strcmp ( V_11 -> V_52 . V_199 , V_162 -> V_16 -> V_59 ) == 0 ) {
V_11 -> V_91 = V_162 ;
V_11 -> V_93 = true ;
}
}
switch ( F_20 ( V_11 ) ) {
case V_4 :
F_75 ( V_162 ,
V_108 ) ;
break;
case V_7 :
F_75 ( V_162 , V_108 ) ;
if ( ! V_163 ) {
F_117 ( V_162 ) -> V_200 = 1 ;
F_138 ( V_11 , 1000 / V_201 ) ;
} else {
F_117 ( V_162 ) -> V_200 =
F_117 ( V_163 ) -> V_200 + 1 ;
}
F_139 ( V_162 ) ;
break;
case V_8 :
case V_9 :
F_140 ( V_162 ) ;
F_75 ( V_162 , V_108 ) ;
break;
default:
F_57 ( V_19 , L_44 ) ;
F_140 ( V_162 ) ;
if ( ! F_141 ( V_11 -> V_69 ) &&
V_162 -> V_29 == V_30 )
F_77 ( V_11 -> V_69 , V_162 ) ;
break;
}
#ifdef F_142
V_15 -> V_202 = V_11 -> V_16 -> V_202 ;
if ( V_15 -> V_202 ) {
if ( F_81 ( V_162 ) ) {
F_71 ( V_19 , L_45 ) ;
V_26 = - V_168 ;
goto V_203;
}
}
#endif
V_26 = F_143 ( V_15 , F_100 ,
V_162 ) ;
if ( V_26 ) {
F_57 ( V_19 , L_46 , V_26 ) ;
goto V_203;
}
V_26 = F_111 ( V_19 , V_15 , V_162 ) ;
if ( V_26 ) {
F_57 ( V_19 , L_47 , V_26 ) ;
goto V_204;
}
V_26 = F_144 ( V_162 ) ;
if ( V_26 ) {
F_57 ( V_19 , L_48 , V_26 ) ;
goto V_205;
}
V_11 -> V_206 ++ ;
F_93 ( V_11 ) ;
F_18 ( V_11 ) ;
if ( F_35 ( V_11 ) ) {
F_145 () ;
F_79 ( & V_11 -> V_104 ) ;
F_80 ( V_11 ) ;
F_78 ( & V_11 -> V_104 ) ;
F_146 () ;
}
F_71 ( V_19 , L_49 ,
V_15 -> V_59 ,
F_147 ( V_162 ) ? L_50 : L_51 ,
V_162 -> V_29 != V_42 ? L_52 : L_53 ) ;
return 0 ;
V_205:
F_114 ( V_19 , V_15 ) ;
V_204:
F_148 ( V_15 ) ;
V_203:
if ( ! F_35 ( V_11 ) )
F_46 ( V_19 , V_15 ) ;
F_149 ( V_15 , V_19 ) ;
if ( V_11 -> V_91 == V_162 )
V_11 -> V_91 = NULL ;
if ( F_141 ( V_11 -> V_69 ) == V_162 ) {
F_145 () ;
F_79 ( & V_11 -> V_104 ) ;
F_68 ( V_11 , NULL ) ;
F_80 ( V_11 ) ;
F_78 ( & V_11 -> V_104 ) ;
F_146 () ;
}
F_85 ( V_162 ) ;
V_193:
V_15 -> V_142 &= ~ V_192 ;
F_150 ( V_15 ) ;
V_191:
if ( ! V_11 -> V_52 . V_110 ||
F_20 ( V_11 ) != V_4 ) {
F_109 ( V_165 . V_188 , V_162 -> V_187 ) ;
V_165 . V_189 = V_15 -> type ;
F_129 ( V_15 , & V_165 ) ;
}
V_190:
F_128 ( V_15 , V_162 -> V_184 ) ;
V_186:
F_118 ( V_162 ) ;
V_172:
if ( ! F_19 ( V_11 ) &&
F_151 ( V_19 -> V_86 , V_15 -> V_86 ) )
F_152 ( V_19 ) ;
return V_26 ;
}
static int F_153 ( struct V_14 * V_19 ,
struct V_14 * V_15 ,
bool V_207 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_208 ;
struct V_164 V_165 ;
int V_209 = V_19 -> V_82 ;
T_6 V_210 = V_19 -> V_124 ;
if ( ! ( V_15 -> V_82 & V_159 ) ||
! F_154 ( V_15 , V_19 ) ) {
F_122 ( V_19 , L_54 ,
V_15 -> V_59 ) ;
return - V_177 ;
}
F_145 () ;
V_22 = F_8 ( V_11 , V_15 ) ;
if ( ! V_22 ) {
F_71 ( V_19 , L_55 ,
V_15 -> V_59 ) ;
F_146 () ;
return - V_177 ;
}
F_155 ( V_22 ) ;
F_114 ( V_19 , V_15 ) ;
F_148 ( V_15 ) ;
F_79 ( & V_11 -> V_211 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_156 ( V_22 ) ;
F_78 ( & V_11 -> V_211 ) ;
F_71 ( V_19 , L_56 ,
F_147 ( V_22 ) ? L_57 : L_58 ,
V_15 -> V_59 ) ;
V_208 = F_141 ( V_11 -> V_69 ) ;
F_157 ( V_11 -> V_212 , NULL ) ;
if ( ! V_207 && ( ! V_11 -> V_52 . V_110 ||
F_20 ( V_11 ) != V_4 ) ) {
if ( F_151 ( V_19 -> V_86 , V_22 -> V_187 ) &&
F_19 ( V_11 ) )
F_121 ( V_19 , L_59 ,
V_15 -> V_59 , V_22 -> V_187 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
}
if ( V_11 -> V_91 == V_22 )
V_11 -> V_91 = NULL ;
if ( V_208 == V_22 ) {
F_79 ( & V_11 -> V_104 ) ;
F_68 ( V_11 , NULL ) ;
F_78 ( & V_11 -> V_104 ) ;
}
if ( F_16 ( V_11 ) ) {
F_158 ( V_11 , V_22 ) ;
}
if ( V_207 ) {
F_157 ( V_11 -> V_69 , NULL ) ;
} else if ( V_208 == V_22 ) {
F_79 ( & V_11 -> V_104 ) ;
F_80 ( V_11 ) ;
F_78 ( & V_11 -> V_104 ) ;
}
if ( ! F_19 ( V_11 ) ) {
F_18 ( V_11 ) ;
F_152 ( V_19 ) ;
}
F_146 () ;
F_159 () ;
V_11 -> V_206 -- ;
if ( ! F_19 ( V_11 ) ) {
F_44 ( V_89 , V_11 -> V_16 ) ;
F_44 ( V_213 , V_11 -> V_16 ) ;
}
F_93 ( V_11 ) ;
if ( ! ( V_19 -> V_124 & V_170 ) &&
( V_210 & V_170 ) )
F_71 ( V_19 , L_60 ,
V_15 -> V_59 , V_19 -> V_59 ) ;
F_149 ( V_15 , V_19 ) ;
if ( ! F_35 ( V_11 ) ) {
if ( V_209 & V_83 )
F_37 ( V_15 , - 1 ) ;
if ( V_209 & V_84 )
F_39 ( V_15 , - 1 ) ;
F_46 ( V_19 , V_15 ) ;
}
F_85 ( V_22 ) ;
F_150 ( V_15 ) ;
if ( V_11 -> V_52 . V_110 != V_179 ||
F_20 ( V_11 ) != V_4 ) {
F_109 ( V_165 . V_188 , V_22 -> V_187 ) ;
V_165 . V_189 = V_15 -> type ;
F_129 ( V_15 , & V_165 ) ;
}
F_128 ( V_15 , V_22 -> V_184 ) ;
V_15 -> V_142 &= ~ V_192 ;
F_118 ( V_22 ) ;
return 0 ;
}
int F_160 ( struct V_14 * V_19 , struct V_14 * V_15 )
{
return F_153 ( V_19 , V_15 , false ) ;
}
static int F_161 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
int V_150 ;
V_150 = F_160 ( V_19 , V_15 ) ;
if ( V_150 == 0 && ! F_19 ( V_11 ) ) {
V_19 -> V_142 |= V_214 ;
F_71 ( V_19 , L_61 ,
V_19 -> V_59 ) ;
F_162 ( V_19 ) ;
}
return V_150 ;
}
static int F_163 ( struct V_14 * V_19 , struct V_215 * V_216 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
V_216 -> V_217 = F_20 ( V_11 ) ;
V_216 -> V_107 = V_11 -> V_52 . V_107 ;
V_216 -> V_218 = V_11 -> V_206 ;
return 0 ;
}
static int F_164 ( struct V_14 * V_19 , struct V_219 * V_216 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
int V_167 = 0 , V_26 = - V_220 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
if ( V_167 ++ == ( int ) V_216 -> V_221 ) {
V_26 = 0 ;
strcpy ( V_216 -> V_222 , V_22 -> V_16 -> V_59 ) ;
V_216 -> V_29 = V_22 -> V_29 ;
V_216 -> V_103 = F_165 ( V_22 ) ;
V_216 -> V_194 = V_22 -> V_194 ;
break;
}
}
return V_26 ;
}
static int F_166 ( struct V_10 * V_11 )
{
int V_223 , V_224 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
bool V_225 ;
V_225 = ! F_65 ( V_11 -> V_69 ) ;
F_167 (bond, slave, iter) {
V_22 -> V_226 = V_227 ;
V_223 = F_29 ( V_11 , V_22 -> V_16 , 0 ) ;
switch ( V_22 -> V_29 ) {
case V_30 :
if ( V_223 )
continue;
V_22 -> V_29 = V_41 ;
V_22 -> V_100 = V_11 -> V_52 . V_228 ;
if ( V_22 -> V_100 ) {
F_71 ( V_11 -> V_16 , L_62 ,
( F_20 ( V_11 ) ==
V_4 ) ?
( F_147 ( V_22 ) ?
L_63 : L_64 ) : L_65 ,
V_22 -> V_16 -> V_59 ,
V_11 -> V_52 . V_228 * V_11 -> V_52 . V_107 ) ;
}
case V_41 :
if ( V_223 ) {
V_22 -> V_29 = V_30 ;
V_22 -> V_105 = V_106 ;
F_71 ( V_11 -> V_16 , L_66 ,
( V_11 -> V_52 . V_228 - V_22 -> V_100 ) *
V_11 -> V_52 . V_107 ,
V_22 -> V_16 -> V_59 ) ;
continue;
}
if ( V_22 -> V_100 <= 0 ) {
V_22 -> V_226 = V_42 ;
V_224 ++ ;
continue;
}
V_22 -> V_100 -- ;
break;
case V_42 :
if ( ! V_223 )
continue;
V_22 -> V_29 = V_43 ;
V_22 -> V_100 = V_11 -> V_52 . V_99 ;
if ( V_22 -> V_100 ) {
F_71 ( V_11 -> V_16 , L_67 ,
V_22 -> V_16 -> V_59 ,
V_225 ? 0 :
V_11 -> V_52 . V_99 *
V_11 -> V_52 . V_107 ) ;
}
case V_43 :
if ( ! V_223 ) {
V_22 -> V_29 = V_42 ;
F_71 ( V_11 -> V_16 , L_68 ,
( V_11 -> V_52 . V_99 - V_22 -> V_100 ) *
V_11 -> V_52 . V_107 ,
V_22 -> V_16 -> V_59 ) ;
continue;
}
if ( V_225 )
V_22 -> V_100 = 0 ;
if ( V_22 -> V_100 <= 0 ) {
V_22 -> V_226 = V_30 ;
V_224 ++ ;
V_225 = false ;
continue;
}
V_22 -> V_100 -- ;
break;
}
}
return V_224 ;
}
static void F_168 ( struct V_10 * V_11 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
switch ( V_22 -> V_226 ) {
case V_227 :
continue;
case V_30 :
V_22 -> V_29 = V_30 ;
V_22 -> V_105 = V_106 ;
if ( F_20 ( V_11 ) == V_7 ) {
F_169 ( V_22 ) ;
} else if ( F_20 ( V_11 ) != V_4 ) {
F_140 ( V_22 ) ;
} else if ( V_22 != V_11 -> V_91 ) {
F_169 ( V_22 ) ;
}
F_71 ( V_11 -> V_16 , L_69 ,
V_22 -> V_16 -> V_59 ,
V_22 -> V_34 == V_35 ? 0 : V_22 -> V_34 ,
V_22 -> V_36 ? L_70 : L_71 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_72 ( V_22 , V_30 ) ;
if ( F_16 ( V_11 ) )
F_73 ( V_11 , V_22 ,
V_30 ) ;
if ( ! V_11 -> V_69 ||
( V_22 == V_11 -> V_91 ) )
goto V_229;
continue;
case V_42 :
if ( V_22 -> V_194 < V_230 )
V_22 -> V_194 ++ ;
V_22 -> V_29 = V_42 ;
if ( F_20 ( V_11 ) == V_4 ||
F_20 ( V_11 ) == V_7 )
F_75 ( V_22 ,
V_108 ) ;
F_71 ( V_11 -> V_16 , L_72 ,
V_22 -> V_16 -> V_59 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_72 ( V_22 ,
V_42 ) ;
if ( F_16 ( V_11 ) )
F_73 ( V_11 , V_22 ,
V_42 ) ;
if ( V_22 == F_141 ( V_11 -> V_69 ) )
goto V_229;
continue;
default:
F_122 ( V_11 -> V_16 , L_73 ,
V_22 -> V_226 , V_22 -> V_16 -> V_59 ) ;
V_22 -> V_226 = V_227 ;
continue;
}
V_229:
F_51 () ;
F_145 () ;
F_79 ( & V_11 -> V_104 ) ;
F_80 ( V_11 ) ;
F_78 ( & V_11 -> V_104 ) ;
F_146 () ;
}
F_18 ( V_11 ) ;
}
static void F_170 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_231 . V_71 ) ;
bool V_109 = false ;
unsigned long V_100 ;
V_100 = F_137 ( V_11 -> V_52 . V_107 ) ;
if ( ! F_19 ( V_11 ) )
goto V_232;
F_64 () ;
V_109 = F_63 ( V_11 ) ;
if ( F_166 ( V_11 ) ) {
F_66 () ;
if ( ! F_42 () ) {
V_100 = 1 ;
V_109 = false ;
goto V_232;
}
F_168 ( V_11 ) ;
F_45 () ;
} else
F_66 () ;
V_232:
if ( V_11 -> V_52 . V_107 )
F_43 ( V_11 -> V_73 , & V_11 -> V_231 , V_100 ) ;
if ( V_109 ) {
if ( ! F_42 () )
return;
F_44 ( V_113 , V_11 -> V_16 ) ;
F_45 () ;
}
}
static bool F_171 ( struct V_10 * V_11 , T_8 V_233 )
{
struct V_14 * V_234 ;
struct V_24 * V_25 ;
bool V_150 = false ;
if ( V_233 == F_172 ( V_11 -> V_16 , 0 , V_233 ) )
return true ;
F_64 () ;
F_173 (bond->dev, upper, iter) {
if ( V_233 == F_172 ( V_234 , 0 , V_233 ) ) {
V_150 = true ;
break;
}
}
F_66 () ;
return V_150 ;
}
static void F_174 ( struct V_14 * V_15 , int V_235 ,
T_8 V_236 , T_8 V_237 ,
struct V_238 * V_239 )
{
struct V_12 * V_13 ;
struct V_238 * V_240 = V_239 ;
F_57 ( V_15 , L_74 ,
V_235 , V_15 -> V_59 , & V_236 , & V_237 ) ;
V_13 = F_175 ( V_235 , V_241 , V_236 , V_15 , V_237 ,
NULL , V_15 -> V_86 , NULL ) ;
if ( ! V_13 ) {
F_176 ( L_75 ) ;
return;
}
if ( ! V_239 || V_239 -> V_242 == V_243 )
goto V_244;
V_239 ++ ;
while ( V_239 -> V_242 != V_243 ) {
if ( ! V_239 -> V_245 ) {
V_239 ++ ;
continue;
}
F_57 ( V_15 , L_76 ,
F_177 ( V_240 -> V_242 ) , V_239 -> V_245 ) ;
V_13 = F_178 ( V_13 , V_239 -> V_242 ,
V_239 -> V_245 ) ;
if ( ! V_13 ) {
F_176 ( L_77 ) ;
return;
}
V_239 ++ ;
}
if ( V_240 -> V_245 ) {
F_57 ( V_15 , L_78 ,
F_177 ( V_240 -> V_242 ) , V_240 -> V_245 ) ;
V_13 = F_179 ( V_13 , V_240 -> V_242 ,
V_240 -> V_245 ) ;
if ( ! V_13 ) {
F_176 ( L_79 ) ;
return;
}
}
V_244:
F_180 ( V_13 ) ;
}
struct V_238 * F_181 ( struct V_14 * V_246 ,
struct V_14 * V_247 ,
int V_248 )
{
struct V_238 * V_239 ;
struct V_14 * V_234 ;
struct V_24 * V_25 ;
if ( V_246 == V_247 ) {
V_239 = F_82 ( sizeof( * V_239 ) * ( V_248 + 1 ) , V_152 ) ;
if ( ! V_239 )
return F_182 ( - V_120 ) ;
V_239 [ V_248 ] . V_242 = V_243 ;
return V_239 ;
}
F_183 (start_dev, upper, iter) {
V_239 = F_181 ( V_234 , V_247 , V_248 + 1 ) ;
if ( F_184 ( V_239 ) ) {
if ( F_185 ( V_239 ) )
return V_239 ;
continue;
}
if ( F_186 ( V_234 ) ) {
V_239 [ V_248 ] . V_242 = F_187 ( V_234 ) ;
V_239 [ V_248 ] . V_245 = F_188 ( V_234 ) ;
}
return V_239 ;
}
return NULL ;
}
static void F_189 ( struct V_10 * V_11 , struct V_22 * V_22 )
{
struct V_249 * V_250 ;
struct V_238 * V_239 ;
T_8 * V_251 = V_11 -> V_52 . V_252 , V_165 ;
int V_167 ;
for ( V_167 = 0 ; V_167 < V_197 && V_251 [ V_167 ] ; V_167 ++ ) {
F_57 ( V_11 -> V_16 , L_80 , & V_251 [ V_167 ] ) ;
V_239 = NULL ;
V_250 = F_190 ( F_191 ( V_11 -> V_16 ) , V_251 [ V_167 ] , 0 ,
V_253 , 0 ) ;
if ( F_185 ( V_250 ) ) {
if ( V_11 -> V_52 . V_254 )
F_192 ( L_81 ,
V_11 -> V_16 -> V_59 ,
& V_251 [ V_167 ] ) ;
F_174 ( V_22 -> V_16 , V_255 , V_251 [ V_167 ] ,
0 , V_239 ) ;
continue;
}
if ( V_250 -> V_256 . V_16 == V_11 -> V_16 )
goto V_257;
F_64 () ;
V_239 = F_181 ( V_11 -> V_16 , V_250 -> V_256 . V_16 , 0 ) ;
F_66 () ;
if ( ! F_184 ( V_239 ) )
goto V_257;
F_57 ( V_11 -> V_16 , L_82 ,
& V_251 [ V_167 ] , V_250 -> V_256 . V_16 ? V_250 -> V_256 . V_16 -> V_59 : L_15 ) ;
F_193 ( V_250 ) ;
continue;
V_257:
V_165 = F_172 ( V_250 -> V_256 . V_16 , V_251 [ V_167 ] , 0 ) ;
F_193 ( V_250 ) ;
F_174 ( V_22 -> V_16 , V_255 , V_251 [ V_167 ] ,
V_165 , V_239 ) ;
F_84 ( V_239 ) ;
}
}
static void F_194 ( struct V_10 * V_11 , struct V_22 * V_22 , T_8 V_258 , T_8 V_259 )
{
int V_167 ;
if ( ! V_258 || ! F_171 ( V_11 , V_259 ) ) {
F_57 ( V_11 -> V_16 , L_83 ,
& V_258 , & V_259 ) ;
return;
}
V_167 = F_195 ( V_11 -> V_52 . V_252 , V_258 ) ;
if ( V_167 == - 1 ) {
F_57 ( V_11 -> V_16 , L_84 ,
& V_258 ) ;
return;
}
V_22 -> V_195 = V_106 ;
V_22 -> V_198 [ V_167 ] = V_106 ;
}
int F_196 ( const struct V_12 * V_13 , struct V_10 * V_11 ,
struct V_22 * V_22 )
{
struct V_260 * V_261 = (struct V_260 * ) V_13 -> V_157 ;
struct V_22 * V_69 ;
unsigned char * V_262 ;
T_8 V_258 , V_259 ;
int V_263 , V_264 = V_13 -> V_265 == F_197 ( V_241 ) ;
if ( ! F_198 ( V_11 , V_22 ) ) {
if ( ( F_199 ( V_11 ) && V_264 ) ||
! F_199 ( V_11 ) )
V_22 -> V_195 = V_106 ;
return V_151 ;
} else if ( ! V_264 ) {
return V_151 ;
}
V_263 = F_200 ( V_11 -> V_16 ) ;
F_57 ( V_11 -> V_16 , L_85 ,
V_13 -> V_16 -> V_59 ) ;
if ( V_263 > F_201 ( V_13 ) ) {
V_261 = F_202 ( V_263 , V_152 ) ;
if ( ! V_261 )
goto V_266;
if ( F_203 ( V_13 , 0 , V_261 , V_263 ) < 0 )
goto V_266;
}
if ( V_261 -> V_267 != V_11 -> V_16 -> V_85 ||
V_13 -> V_146 == V_268 ||
V_13 -> V_146 == V_269 ||
V_261 -> V_270 != F_204 ( V_174 ) ||
V_261 -> V_271 != F_204 ( V_272 ) ||
V_261 -> V_273 != 4 )
goto V_266;
V_262 = ( unsigned char * ) ( V_261 + 1 ) ;
V_262 += V_11 -> V_16 -> V_85 ;
memcpy ( & V_258 , V_262 , 4 ) ;
V_262 += 4 + V_11 -> V_16 -> V_85 ;
memcpy ( & V_259 , V_262 , 4 ) ;
F_57 ( V_11 -> V_16 , L_86 ,
V_22 -> V_16 -> V_59 , F_165 ( V_22 ) ,
V_11 -> V_52 . V_254 , F_198 ( V_11 , V_22 ) ,
& V_258 , & V_259 ) ;
V_69 = F_65 ( V_11 -> V_69 ) ;
if ( F_147 ( V_22 ) )
F_194 ( V_11 , V_22 , V_258 , V_259 ) ;
else if ( V_69 &&
F_205 ( F_206 ( V_11 , V_69 ) ,
V_69 -> V_105 ) )
F_194 ( V_11 , V_22 , V_259 , V_258 ) ;
V_266:
if ( V_261 != (struct V_260 * ) V_13 -> V_157 )
F_84 ( V_261 ) ;
return V_151 ;
}
static bool F_207 ( struct V_10 * V_11 , unsigned long V_274 ,
int V_275 )
{
int V_276 = F_137 ( V_11 -> V_52 . V_196 ) ;
return F_208 ( V_106 ,
V_274 - V_276 ,
V_274 + V_275 * V_276 + V_276 / 2 ) ;
}
static void F_209 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_277 . V_71 ) ;
struct V_22 * V_22 , * V_208 ;
struct V_24 * V_25 ;
int V_229 = 0 , V_278 = 0 ;
if ( ! F_19 ( V_11 ) )
goto V_232;
F_64 () ;
V_208 = F_65 ( V_11 -> V_69 ) ;
F_167 (bond, slave, iter) {
unsigned long V_279 = F_210 ( V_22 -> V_16 ) ;
if ( V_22 -> V_29 != V_30 ) {
if ( F_207 ( V_11 , V_279 , 1 ) &&
F_207 ( V_11 , V_22 -> V_195 , 1 ) ) {
V_22 -> V_29 = V_30 ;
V_278 = 1 ;
if ( ! V_208 ) {
F_71 ( V_11 -> V_16 , L_87 ,
V_22 -> V_16 -> V_59 ) ;
V_229 = 1 ;
} else {
F_71 ( V_11 -> V_16 , L_88 ,
V_22 -> V_16 -> V_59 ) ;
}
}
} else {
if ( ! F_207 ( V_11 , V_279 , 2 ) ||
! F_207 ( V_11 , V_22 -> V_195 , 2 ) ) {
V_22 -> V_29 = V_42 ;
V_278 = 1 ;
if ( V_22 -> V_194 < V_230 )
V_22 -> V_194 ++ ;
F_71 ( V_11 -> V_16 , L_89 ,
V_22 -> V_16 -> V_59 ) ;
if ( V_22 == V_208 )
V_229 = 1 ;
}
}
if ( F_62 ( V_22 ) )
F_189 ( V_11 , V_22 ) ;
}
F_66 () ;
if ( V_229 || V_278 ) {
if ( ! F_42 () )
goto V_232;
if ( V_278 ) {
F_211 ( V_11 ) ;
} else if ( V_229 ) {
F_145 () ;
F_79 ( & V_11 -> V_104 ) ;
F_80 ( V_11 ) ;
F_78 ( & V_11 -> V_104 ) ;
F_146 () ;
}
F_45 () ;
}
V_232:
if ( V_11 -> V_52 . V_196 )
F_43 ( V_11 -> V_73 , & V_11 -> V_277 ,
F_137 ( V_11 -> V_52 . V_196 ) ) ;
}
static int F_212 ( struct V_10 * V_11 )
{
unsigned long V_279 , V_195 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_224 = 0 ;
F_167 (bond, slave, iter) {
V_22 -> V_226 = V_227 ;
V_195 = F_206 ( V_11 , V_22 ) ;
if ( V_22 -> V_29 != V_30 ) {
if ( F_207 ( V_11 , V_195 , 1 ) ) {
V_22 -> V_226 = V_30 ;
V_224 ++ ;
}
continue;
}
if ( F_207 ( V_11 , V_22 -> V_105 , 2 ) )
continue;
if ( ! F_147 ( V_22 ) &&
! F_141 ( V_11 -> V_212 ) &&
! F_207 ( V_11 , V_195 , 3 ) ) {
V_22 -> V_226 = V_42 ;
V_224 ++ ;
}
V_279 = F_210 ( V_22 -> V_16 ) ;
if ( F_147 ( V_22 ) &&
( ! F_207 ( V_11 , V_279 , 2 ) ||
! F_207 ( V_11 , V_195 , 2 ) ) ) {
V_22 -> V_226 = V_42 ;
V_224 ++ ;
}
}
return V_224 ;
}
static void F_213 ( struct V_10 * V_11 )
{
unsigned long V_279 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
switch ( V_22 -> V_226 ) {
case V_227 :
continue;
case V_30 :
V_279 = F_210 ( V_22 -> V_16 ) ;
if ( F_36 ( V_11 -> V_69 ) != V_22 ||
( ! F_36 ( V_11 -> V_69 ) &&
F_207 ( V_11 , V_279 , 1 ) ) ) {
struct V_22 * V_212 ;
V_212 = F_36 ( V_11 -> V_212 ) ;
V_22 -> V_29 = V_30 ;
if ( V_212 ) {
F_75 (
V_212 ,
V_108 ) ;
F_157 ( V_11 -> V_212 , NULL ) ;
}
F_71 ( V_11 -> V_16 , L_87 ,
V_22 -> V_16 -> V_59 ) ;
if ( ! F_36 ( V_11 -> V_69 ) ||
( V_22 == V_11 -> V_91 ) )
goto V_229;
}
continue;
case V_42 :
if ( V_22 -> V_194 < V_230 )
V_22 -> V_194 ++ ;
V_22 -> V_29 = V_42 ;
F_75 ( V_22 ,
V_108 ) ;
F_71 ( V_11 -> V_16 , L_72 ,
V_22 -> V_16 -> V_59 ) ;
if ( V_22 == F_36 ( V_11 -> V_69 ) ) {
F_157 ( V_11 -> V_212 , NULL ) ;
goto V_229;
}
continue;
default:
F_122 ( V_11 -> V_16 , L_90 ,
V_22 -> V_226 , V_22 -> V_16 -> V_59 ) ;
continue;
}
V_229:
F_51 () ;
F_145 () ;
F_79 ( & V_11 -> V_104 ) ;
F_80 ( V_11 ) ;
F_78 ( & V_11 -> V_104 ) ;
F_146 () ;
}
F_18 ( V_11 ) ;
}
static bool F_214 ( struct V_10 * V_11 )
{
struct V_22 * V_22 , * V_280 = NULL , * V_162 = NULL ,
* V_281 = F_65 ( V_11 -> V_212 ) ,
* V_69 = F_65 ( V_11 -> V_69 ) ;
struct V_24 * V_25 ;
bool V_257 = false ;
bool V_282 = V_283 ;
if ( V_281 && V_69 )
F_71 ( V_11 -> V_16 , L_91 ,
V_281 -> V_16 -> V_59 ,
V_69 -> V_16 -> V_59 ) ;
if ( V_69 ) {
F_189 ( V_11 , V_69 ) ;
return V_282 ;
}
if ( ! V_281 ) {
V_281 = F_215 ( V_11 ) ;
if ( ! V_281 )
return V_282 ;
}
F_75 ( V_281 , V_283 ) ;
F_167 (bond, slave, iter) {
if ( ! V_257 && ! V_280 && F_62 ( V_22 ) )
V_280 = V_22 ;
if ( V_257 && ! V_162 && F_62 ( V_22 ) )
V_162 = V_22 ;
if ( ! F_62 ( V_22 ) && V_22 -> V_29 == V_30 ) {
V_22 -> V_29 = V_42 ;
if ( V_22 -> V_194 < V_230 )
V_22 -> V_194 ++ ;
F_75 ( V_22 ,
V_283 ) ;
F_71 ( V_11 -> V_16 , L_92 ,
V_22 -> V_16 -> V_59 ) ;
}
if ( V_22 == V_281 )
V_257 = true ;
}
if ( ! V_162 && V_280 )
V_162 = V_280 ;
if ( ! V_162 )
goto V_284;
V_162 -> V_29 = V_43 ;
F_76 ( V_162 , V_283 ) ;
F_189 ( V_11 , V_162 ) ;
V_162 -> V_105 = V_106 ;
F_77 ( V_11 -> V_212 , V_162 ) ;
V_284:
F_167 (bond, slave, iter) {
if ( V_22 -> V_285 ) {
V_282 = V_108 ;
break;
}
}
return V_282 ;
}
static void F_216 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_277 . V_71 ) ;
bool V_109 = false ;
bool V_282 = false ;
int V_276 ;
V_276 = F_137 ( V_11 -> V_52 . V_196 ) ;
if ( ! F_19 ( V_11 ) )
goto V_232;
F_64 () ;
V_109 = F_63 ( V_11 ) ;
if ( F_212 ( V_11 ) ) {
F_66 () ;
if ( ! F_42 () ) {
V_276 = 1 ;
V_109 = false ;
goto V_232;
}
F_213 ( V_11 ) ;
F_45 () ;
F_64 () ;
}
V_282 = F_214 ( V_11 ) ;
F_66 () ;
V_232:
if ( V_11 -> V_52 . V_196 )
F_43 ( V_11 -> V_73 , & V_11 -> V_277 , V_276 ) ;
if ( V_109 || V_282 ) {
if ( ! F_42 () )
return;
if ( V_109 )
F_44 ( V_113 ,
V_11 -> V_16 ) ;
if ( V_282 )
F_217 ( V_11 ) ;
F_45 () ;
}
}
static int F_218 ( struct V_10 * V_11 )
{
F_219 ( V_11 ) ;
F_220 ( V_11 ) ;
F_221 ( V_11 ) ;
return V_286 ;
}
static int F_222 ( unsigned long V_287 ,
struct V_14 * V_19 )
{
struct V_10 * V_288 = F_11 ( V_19 ) ;
switch ( V_287 ) {
case V_289 :
return F_218 ( V_288 ) ;
case V_290 :
F_219 ( V_288 ) ;
break;
case V_291 :
F_220 ( V_288 ) ;
break;
case V_113 :
if ( V_288 -> V_101 )
V_288 -> V_101 -- ;
break;
default:
break;
}
return V_286 ;
}
static int F_223 ( unsigned long V_287 ,
struct V_14 * V_15 )
{
struct V_22 * V_22 = F_224 ( V_15 ) ;
struct V_10 * V_11 ;
struct V_14 * V_19 ;
T_3 V_292 ;
T_5 V_293 ;
if ( ! V_22 )
return V_286 ;
V_19 = V_22 -> V_11 -> V_16 ;
V_11 = V_22 -> V_11 ;
switch ( V_287 ) {
case V_290 :
if ( V_19 -> type != V_174 )
F_161 ( V_19 , V_15 ) ;
else
F_160 ( V_19 , V_15 ) ;
break;
case V_294 :
case V_295 :
V_292 = V_22 -> V_34 ;
V_293 = V_22 -> V_36 ;
F_25 ( V_22 ) ;
if ( F_20 ( V_11 ) == V_7 ) {
if ( V_292 != V_22 -> V_34 )
F_225 ( V_22 ) ;
if ( V_293 != V_22 -> V_36 )
F_226 ( V_22 ) ;
}
break;
case V_296 :
break;
case V_297 :
break;
case V_289 :
if ( ! F_35 ( V_11 ) ||
! V_11 -> V_52 . V_199 [ 0 ] )
break;
if ( V_22 == V_11 -> V_91 ) {
V_11 -> V_91 = NULL ;
} else if ( ! strcmp ( V_15 -> V_59 , V_11 -> V_52 . V_199 ) ) {
V_11 -> V_91 = V_22 ;
} else {
break;
}
F_71 ( V_11 -> V_16 , L_93 ,
V_11 -> V_91 ? V_15 -> V_59 : L_94 ) ;
F_145 () ;
F_79 ( & V_11 -> V_104 ) ;
F_80 ( V_11 ) ;
F_78 ( & V_11 -> V_104 ) ;
F_146 () ;
break;
case V_298 :
F_93 ( V_11 ) ;
break;
case V_74 :
F_44 ( V_287 , V_22 -> V_11 -> V_16 ) ;
break;
default:
break;
}
return V_286 ;
}
static int F_227 ( struct V_299 * V_300 ,
unsigned long V_287 , void * V_301 )
{
struct V_14 * V_302 = F_228 ( V_301 ) ;
F_57 ( V_302 , L_95 , V_287 ) ;
if ( ! ( V_302 -> V_142 & V_192 ) )
return V_286 ;
if ( V_302 -> V_82 & V_303 ) {
F_57 ( V_302 , L_96 ) ;
return F_222 ( V_287 , V_302 ) ;
}
if ( V_302 -> V_82 & V_159 ) {
F_57 ( V_302 , L_97 ) ;
return F_223 ( V_287 , V_302 ) ;
}
return V_286 ;
}
static inline T_3 F_229 ( struct V_12 * V_13 )
{
struct V_304 * V_305 , V_306 ;
V_305 = F_230 ( V_13 , 0 , sizeof( V_306 ) , & V_306 ) ;
if ( V_305 )
return V_305 -> V_158 [ 5 ] ^ V_305 -> V_307 [ 5 ] ^ V_305 -> V_308 ;
return 0 ;
}
static bool F_231 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_309 * V_310 )
{
const struct V_311 * V_312 ;
const struct V_313 * V_314 ;
int V_315 , V_20 = - 1 ;
if ( V_11 -> V_52 . V_316 > V_317 )
return F_232 ( V_13 , V_310 ) ;
V_310 -> V_318 = 0 ;
V_315 = F_233 ( V_13 ) ;
if ( V_13 -> V_265 == F_204 ( V_272 ) ) {
if ( F_5 ( ! F_234 ( V_13 , V_315 + sizeof( * V_314 ) ) ) )
return false ;
V_314 = F_235 ( V_13 ) ;
V_310 -> V_319 = V_314 -> V_320 ;
V_310 -> V_256 = V_314 -> V_321 ;
V_315 += V_314 -> V_322 << 2 ;
if ( ! F_236 ( V_314 ) )
V_20 = V_314 -> V_265 ;
} else if ( V_13 -> V_265 == F_204 ( V_323 ) ) {
if ( F_5 ( ! F_234 ( V_13 , V_315 + sizeof( * V_312 ) ) ) )
return false ;
V_312 = F_237 ( V_13 ) ;
V_310 -> V_319 = ( V_324 T_8 ) F_238 ( & V_312 -> V_320 ) ;
V_310 -> V_256 = ( V_324 T_8 ) F_238 ( & V_312 -> V_321 ) ;
V_315 += sizeof( * V_312 ) ;
V_20 = V_312 -> V_325 ;
} else {
return false ;
}
if ( V_11 -> V_52 . V_316 == V_326 && V_20 >= 0 )
V_310 -> V_318 = F_239 ( V_13 , V_315 , V_20 ) ;
return true ;
}
T_3 F_240 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_309 V_327 ;
T_3 V_328 ;
if ( V_11 -> V_52 . V_316 == V_329 ||
! F_231 ( V_11 , V_13 , & V_327 ) )
return F_229 ( V_13 ) ;
if ( V_11 -> V_52 . V_316 == V_317 ||
V_11 -> V_52 . V_316 == V_330 )
V_328 = F_229 ( V_13 ) ;
else
V_328 = ( V_324 T_3 ) V_327 . V_318 ;
V_328 ^= ( V_324 T_3 ) V_327 . V_256 ^ ( V_324 T_3 ) V_327 . V_319 ;
V_328 ^= ( V_328 >> 16 ) ;
V_328 ^= ( V_328 >> 8 ) ;
return V_328 ;
}
static void F_241 ( struct V_10 * V_11 )
{
F_242 ( & V_11 -> V_72 ,
F_40 ) ;
F_242 ( & V_11 -> V_331 , V_332 ) ;
F_242 ( & V_11 -> V_231 , F_170 ) ;
if ( F_20 ( V_11 ) == V_4 )
F_242 ( & V_11 -> V_277 , F_216 ) ;
else
F_242 ( & V_11 -> V_277 , F_209 ) ;
F_242 ( & V_11 -> V_333 , V_334 ) ;
}
static void F_243 ( struct V_10 * V_11 )
{
F_244 ( & V_11 -> V_231 ) ;
F_244 ( & V_11 -> V_277 ) ;
F_244 ( & V_11 -> V_331 ) ;
F_244 ( & V_11 -> V_333 ) ;
F_244 ( & V_11 -> V_72 ) ;
}
static int F_245 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_246 ( & V_11 -> V_211 ) ;
if ( F_19 ( V_11 ) ) {
F_246 ( & V_11 -> V_104 ) ;
F_12 (bond, slave, iter) {
if ( F_35 ( V_11 ) &&
V_22 != F_141 ( V_11 -> V_69 ) ) {
F_75 ( V_22 ,
V_108 ) ;
} else {
F_76 ( V_22 ,
V_108 ) ;
}
}
F_247 ( & V_11 -> V_104 ) ;
}
F_247 ( & V_11 -> V_211 ) ;
F_241 ( V_11 ) ;
if ( F_16 ( V_11 ) ) {
if ( F_248 ( V_11 , ( F_20 ( V_11 ) == V_9 ) ) )
return - V_120 ;
if ( V_11 -> V_52 . V_335 )
F_43 ( V_11 -> V_73 , & V_11 -> V_331 , 0 ) ;
}
if ( V_11 -> V_52 . V_107 )
F_43 ( V_11 -> V_73 , & V_11 -> V_231 , 0 ) ;
if ( V_11 -> V_52 . V_196 ) {
F_43 ( V_11 -> V_73 , & V_11 -> V_277 , 0 ) ;
V_11 -> F_101 = F_196 ;
}
if ( F_20 ( V_11 ) == V_7 ) {
F_43 ( V_11 -> V_73 , & V_11 -> V_333 , 0 ) ;
V_11 -> F_101 = V_336 ;
F_249 ( V_11 , 1 ) ;
}
return 0 ;
}
static int F_250 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_243 ( V_11 ) ;
V_11 -> V_101 = 0 ;
if ( F_16 ( V_11 ) )
F_251 ( V_11 ) ;
V_11 -> F_101 = NULL ;
return 0 ;
}
static struct V_337 * F_252 ( struct V_14 * V_19 ,
struct V_337 * V_338 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_337 V_339 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
memset ( V_338 , 0 , sizeof( * V_338 ) ) ;
F_253 ( & V_11 -> V_211 ) ;
F_12 (bond, slave, iter) {
const struct V_337 * V_340 =
F_254 ( V_22 -> V_16 , & V_339 ) ;
V_338 -> V_341 += V_340 -> V_341 ;
V_338 -> V_342 += V_340 -> V_342 ;
V_338 -> V_343 += V_340 -> V_343 ;
V_338 -> V_344 += V_340 -> V_344 ;
V_338 -> V_345 += V_340 -> V_345 ;
V_338 -> V_346 += V_340 -> V_346 ;
V_338 -> V_347 += V_340 -> V_347 ;
V_338 -> V_348 += V_340 -> V_348 ;
V_338 -> V_349 += V_340 -> V_349 ;
V_338 -> V_350 += V_340 -> V_350 ;
V_338 -> V_351 += V_340 -> V_351 ;
V_338 -> V_352 += V_340 -> V_352 ;
V_338 -> V_353 += V_340 -> V_353 ;
V_338 -> V_354 += V_340 -> V_354 ;
V_338 -> V_355 += V_340 -> V_355 ;
V_338 -> V_356 += V_340 -> V_356 ;
V_338 -> V_357 += V_340 -> V_357 ;
V_338 -> V_358 += V_340 -> V_358 ;
V_338 -> V_359 += V_340 -> V_359 ;
V_338 -> V_360 += V_340 -> V_360 ;
V_338 -> V_361 += V_340 -> V_361 ;
}
F_255 ( & V_11 -> V_211 ) ;
return V_338 ;
}
static int F_256 ( struct V_14 * V_19 , struct V_48 * V_49 , int V_362 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_14 * V_15 = NULL ;
struct V_215 V_363 ;
struct V_215 T_9 * V_364 = NULL ;
struct V_219 V_365 ;
struct V_219 T_9 * V_366 = NULL ;
struct V_50 * V_51 = NULL ;
struct V_367 V_368 ;
struct V_369 * V_369 ;
int V_26 = 0 ;
F_57 ( V_19 , L_98 , V_362 ) ;
switch ( V_362 ) {
case V_61 :
V_51 = F_32 ( V_49 ) ;
if ( ! V_51 )
return - V_177 ;
V_51 -> V_370 = 0 ;
case V_64 :
V_51 = F_32 ( V_49 ) ;
if ( ! V_51 )
return - V_177 ;
if ( V_51 -> V_62 == 1 ) {
V_51 -> V_65 = 0 ;
F_246 ( & V_11 -> V_211 ) ;
F_246 ( & V_11 -> V_104 ) ;
if ( F_22 ( V_11 -> V_16 ) )
V_51 -> V_65 = V_54 ;
F_247 ( & V_11 -> V_104 ) ;
F_247 ( & V_11 -> V_211 ) ;
}
return 0 ;
case V_371 :
case V_372 :
V_364 = (struct V_215 T_9 * ) V_49 -> V_373 ;
if ( F_257 ( & V_363 , V_364 , sizeof( V_215 ) ) )
return - V_374 ;
V_26 = F_163 ( V_19 , & V_363 ) ;
if ( V_26 == 0 &&
F_258 ( V_364 , & V_363 , sizeof( V_215 ) ) )
return - V_374 ;
return V_26 ;
case V_375 :
case V_376 :
V_366 = (struct V_219 T_9 * ) V_49 -> V_373 ;
if ( F_257 ( & V_365 , V_366 , sizeof( V_219 ) ) )
return - V_374 ;
V_26 = F_164 ( V_19 , & V_365 ) ;
if ( V_26 == 0 &&
F_258 ( V_366 , & V_365 , sizeof( V_219 ) ) )
return - V_374 ;
return V_26 ;
default:
break;
}
V_369 = F_191 ( V_19 ) ;
if ( ! F_259 ( V_369 -> V_377 , V_378 ) )
return - V_169 ;
V_15 = F_260 ( V_369 , V_49 -> V_379 ) ;
F_57 ( V_19 , L_99 , V_15 ) ;
if ( ! V_15 )
return - V_220 ;
F_57 ( V_19 , L_100 , V_15 -> V_59 ) ;
switch ( V_362 ) {
case V_380 :
case V_381 :
V_26 = F_120 ( V_19 , V_15 ) ;
break;
case V_382 :
case V_383 :
V_26 = F_160 ( V_19 , V_15 ) ;
break;
case V_384 :
case V_385 :
F_56 ( V_19 , V_15 ) ;
V_26 = 0 ;
break;
case V_386 :
case V_387 :
F_261 ( & V_368 , V_15 -> V_59 ) ;
V_26 = F_262 ( V_11 , V_388 , & V_368 ) ;
break;
default:
V_26 = - V_180 ;
}
return V_26 ;
}
static void F_263 ( struct V_14 * V_19 , int V_389 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_389 & V_83 )
F_34 ( V_11 ,
V_19 -> V_82 & V_83 ? 1 : - 1 ) ;
if ( V_389 & V_84 )
F_38 ( V_11 ,
V_19 -> V_82 & V_84 ? 1 : - 1 ) ;
}
static void F_264 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_64 () ;
if ( F_35 ( V_11 ) ) {
V_22 = F_65 ( V_11 -> V_69 ) ;
if ( V_22 ) {
F_53 ( V_22 -> V_16 , V_19 ) ;
F_54 ( V_22 -> V_16 , V_19 ) ;
}
} else {
F_167 (bond, slave, iter) {
F_133 ( V_22 -> V_16 , V_19 ) ;
F_132 ( V_22 -> V_16 , V_19 ) ;
}
}
F_66 () ;
}
static int F_265 ( struct V_390 * V_391 )
{
struct V_10 * V_11 = F_11 ( V_391 -> V_16 ) ;
const struct V_45 * V_46 ;
struct V_392 V_393 ;
struct V_22 * V_22 ;
int V_150 ;
V_22 = F_266 ( V_11 ) ;
if ( ! V_22 )
return 0 ;
V_46 = V_22 -> V_16 -> V_47 ;
if ( ! V_46 -> V_394 )
return 0 ;
V_393 . V_395 = NULL ;
V_393 . V_396 = NULL ;
V_150 = V_46 -> V_394 ( V_22 -> V_16 , & V_393 ) ;
if ( V_150 )
return V_150 ;
V_391 -> V_393 -> V_396 = V_393 . V_396 ;
if ( ! V_393 . V_395 )
return 0 ;
return V_393 . V_395 ( V_391 ) ;
}
static int F_267 ( struct V_14 * V_16 ,
struct V_392 * V_393 )
{
if ( V_393 -> V_16 == V_16 )
V_393 -> V_395 = F_265 ;
return 0 ;
}
static int F_268 ( struct V_14 * V_19 , int V_397 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
F_57 ( V_19 , L_101 , V_11 , V_397 ) ;
F_12 (bond, slave, iter) {
F_57 ( V_19 , L_102 ,
V_22 , V_22 -> V_16 -> V_47 -> V_398 ) ;
V_26 = F_128 ( V_22 -> V_16 , V_397 ) ;
if ( V_26 ) {
F_57 ( V_19 , L_103 , V_26 ,
V_22 -> V_16 -> V_59 ) ;
goto V_27;
}
}
V_19 -> V_185 = V_397 ;
return 0 ;
V_27:
F_12 (bond, rollback_slave, iter) {
int V_399 ;
if ( V_23 == V_22 )
break;
V_399 = F_128 ( V_23 -> V_16 , V_19 -> V_185 ) ;
if ( V_399 ) {
F_57 ( V_19 , L_104 ,
V_399 , V_23 -> V_16 -> V_59 ) ;
}
}
return V_26 ;
}
static int F_269 ( struct V_14 * V_19 , void * V_165 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_164 * V_400 = V_165 , V_401 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
if ( F_20 ( V_11 ) == V_9 )
return F_270 ( V_19 , V_165 ) ;
F_57 ( V_19 , L_105 , V_11 ) ;
if ( V_11 -> V_52 . V_110 &&
F_20 ( V_11 ) == V_4 )
return 0 ;
if ( ! F_271 ( V_400 -> V_188 ) )
return - V_402 ;
F_12 (bond, slave, iter) {
F_57 ( V_19 , L_106 , V_22 , V_22 -> V_16 -> V_59 ) ;
V_26 = F_129 ( V_22 -> V_16 , V_165 ) ;
if ( V_26 ) {
F_57 ( V_19 , L_103 , V_26 , V_22 -> V_16 -> V_59 ) ;
goto V_27;
}
}
memcpy ( V_19 -> V_86 , V_400 -> V_188 , V_19 -> V_85 ) ;
return 0 ;
V_27:
memcpy ( V_401 . V_188 , V_19 -> V_86 , V_19 -> V_85 ) ;
V_401 . V_189 = V_19 -> type ;
F_12 (bond, rollback_slave, iter) {
int V_399 ;
if ( V_23 == V_22 )
break;
V_399 = F_129 ( V_23 -> V_16 , & V_401 ) ;
if ( V_399 ) {
F_57 ( V_19 , L_104 ,
V_399 , V_23 -> V_16 -> V_59 ) ;
}
}
return V_26 ;
}
static void F_272 ( struct V_10 * V_11 , struct V_12 * V_13 , int V_221 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_167 = V_221 ;
F_167 (bond, slave, iter) {
if ( -- V_167 < 0 ) {
if ( F_273 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
}
V_167 = V_221 ;
F_167 (bond, slave, iter) {
if ( -- V_167 < 0 )
break;
if ( F_273 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
F_274 ( V_13 ) ;
}
static T_3 F_275 ( struct V_10 * V_11 )
{
T_3 V_221 ;
struct V_403 V_404 ;
int V_405 = V_11 -> V_52 . V_405 ;
switch ( V_405 ) {
case 0 :
V_221 = F_276 () ;
break;
case 1 :
V_221 = V_11 -> V_406 ;
break;
default:
V_404 =
V_11 -> V_52 . V_404 ;
V_221 = F_277 ( V_11 -> V_406 ,
V_404 ) ;
break;
}
V_11 -> V_406 ++ ;
return V_221 ;
}
static int F_278 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_313 * V_314 = F_235 ( V_13 ) ;
struct V_22 * V_22 ;
T_3 V_221 ;
if ( V_314 -> V_265 == V_407 && V_13 -> V_265 == F_204 ( V_272 ) ) {
V_22 = F_65 ( V_11 -> V_69 ) ;
if ( V_22 && F_273 ( V_22 ) )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_272 ( V_11 , V_13 , 0 ) ;
} else {
int V_206 = F_104 ( V_11 -> V_206 ) ;
if ( F_279 ( V_206 ) ) {
V_221 = F_275 ( V_11 ) ;
F_272 ( V_11 , V_13 , V_221 % V_206 ) ;
} else {
F_274 ( V_13 ) ;
}
}
return V_408 ;
}
static int F_280 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 ;
V_22 = F_65 ( V_11 -> V_69 ) ;
if ( V_22 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_274 ( V_13 ) ;
return V_408 ;
}
static int F_281 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
int V_206 = F_104 ( V_11 -> V_206 ) ;
if ( F_279 ( V_206 ) )
F_272 ( V_11 , V_13 ,
F_240 ( V_11 , V_13 ) % V_206 ) ;
else
F_274 ( V_13 ) ;
return V_408 ;
}
static int F_282 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
F_167 (bond, slave, iter) {
if ( F_283 ( V_11 , V_22 ) )
break;
if ( F_62 ( V_22 ) && V_22 -> V_29 == V_30 ) {
struct V_12 * V_409 = F_284 ( V_13 , V_152 ) ;
if ( ! V_409 ) {
F_176 ( L_107 ,
V_19 -> V_59 , V_410 ) ;
continue;
}
F_2 ( V_11 , V_409 , V_22 -> V_16 ) ;
}
}
if ( V_22 && F_62 ( V_22 ) && V_22 -> V_29 == V_30 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_274 ( V_13 ) ;
return V_408 ;
}
static inline int F_285 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
if ( ! V_13 -> V_17 )
return 1 ;
F_167 (bond, slave, iter) {
if ( V_22 -> V_183 == V_13 -> V_17 ) {
if ( F_273 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return 0 ;
}
break;
}
}
return 1 ;
}
static T_2 F_286 ( struct V_14 * V_16 , struct V_12 * V_13 ,
void * V_411 , T_10 V_412 )
{
T_2 V_413 = F_287 ( V_13 ) ? F_288 ( V_13 ) : 0 ;
F_4 ( V_13 ) -> V_18 = V_13 -> V_17 ;
if ( F_5 ( V_413 >= V_16 -> V_414 ) ) {
do {
V_413 -= V_16 -> V_414 ;
} while ( V_413 >= V_16 -> V_414 );
}
return V_413 ;
}
static T_11 F_289 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
if ( F_290 ( V_11 ) &&
! F_285 ( V_11 , V_13 ) )
return V_408 ;
switch ( F_20 ( V_11 ) ) {
case V_3 :
return F_278 ( V_13 , V_16 ) ;
case V_4 :
return F_280 ( V_13 , V_16 ) ;
case V_5 :
return F_281 ( V_13 , V_16 ) ;
case V_6 :
return F_282 ( V_13 , V_16 ) ;
case V_7 :
return F_291 ( V_13 , V_16 ) ;
case V_9 :
return F_292 ( V_13 , V_16 ) ;
case V_8 :
return F_293 ( V_13 , V_16 ) ;
default:
F_122 ( V_16 , L_108 , F_20 ( V_11 ) ) ;
F_294 ( 1 ) ;
F_274 ( V_13 ) ;
return V_408 ;
}
}
static T_11 F_295 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
T_11 V_150 = V_408 ;
if ( F_5 ( F_296 ( V_16 ) ) )
return V_415 ;
F_64 () ;
if ( F_19 ( V_11 ) )
V_150 = F_289 ( V_13 , V_16 ) ;
else
F_274 ( V_13 ) ;
F_66 () ;
return V_150 ;
}
static int F_297 ( struct V_14 * V_19 ,
struct V_31 * V_32 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
unsigned long V_34 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
V_32 -> V_36 = V_37 ;
V_32 -> V_416 = V_417 ;
F_246 ( & V_11 -> V_211 ) ;
F_12 (bond, slave, iter) {
if ( F_273 ( V_22 ) ) {
if ( V_22 -> V_34 != V_35 )
V_34 += V_22 -> V_34 ;
if ( V_32 -> V_36 == V_37 &&
V_22 -> V_36 != V_37 )
V_32 -> V_36 = V_22 -> V_36 ;
}
}
F_298 ( V_32 , V_34 ? : V_35 ) ;
F_247 ( & V_11 -> V_211 ) ;
return 0 ;
}
static void F_299 ( struct V_14 * V_19 ,
struct V_418 * V_419 )
{
F_300 ( V_419 -> V_420 , V_421 , sizeof( V_419 -> V_420 ) ) ;
F_300 ( V_419 -> V_422 , V_423 , sizeof( V_419 -> V_422 ) ) ;
snprintf ( V_419 -> V_424 , sizeof( V_419 -> V_424 ) , L_109 ,
V_425 ) ;
}
static void F_301 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_11 -> V_73 )
F_302 ( V_11 -> V_73 ) ;
F_303 ( V_19 ) ;
}
void F_304 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_305 ( & V_11 -> V_211 ) ;
F_305 ( & V_11 -> V_104 ) ;
V_11 -> V_52 = V_426 ;
V_11 -> V_16 = V_19 ;
F_127 ( V_19 ) ;
V_19 -> V_47 = & V_427 ;
V_19 -> V_55 = & V_428 ;
V_19 -> V_429 = F_301 ;
F_306 ( V_19 , & V_430 ) ;
V_19 -> V_431 = 0 ;
V_19 -> V_82 |= V_303 | V_432 ;
V_19 -> V_142 |= V_192 | V_433 ;
V_19 -> V_142 &= ~ ( V_129 | V_175 ) ;
V_19 -> V_124 |= V_434 ;
V_19 -> V_124 |= V_435 ;
V_19 -> V_436 = V_131 |
V_437 |
V_438 |
V_439 ;
V_19 -> V_436 &= ~ ( V_440 & ~ V_441 ) ;
V_19 -> V_436 |= V_442 ;
V_19 -> V_124 |= V_19 -> V_436 ;
}
static void F_307 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_88 ( V_19 ) ;
F_12 (bond, slave, iter)
F_153 ( V_19 , V_22 -> V_16 , true ) ;
F_71 ( V_19 , L_110 ) ;
F_308 ( & V_11 -> V_443 ) ;
F_309 ( V_11 ) ;
}
static int F_310 ( struct V_444 * V_52 )
{
int V_445 , V_446 , V_447 , V_167 ;
struct V_367 V_368 ;
const struct V_367 * V_448 ;
int V_449 ;
if ( V_1 ) {
F_261 ( & V_368 , V_1 ) ;
V_448 = F_311 ( F_312 ( V_450 ) , & V_368 ) ;
if ( ! V_448 ) {
F_313 ( L_111 , V_1 ) ;
return - V_177 ;
}
V_217 = V_448 -> V_451 ;
}
if ( V_452 ) {
if ( ( V_217 != V_5 ) &&
( V_217 != V_7 ) &&
( V_217 != V_8 ) ) {
F_314 ( L_112 ,
F_1 ( V_217 ) ) ;
} else {
F_261 ( & V_368 , V_452 ) ;
V_448 = F_311 ( F_312 ( V_453 ) ,
& V_368 ) ;
if ( ! V_448 ) {
F_313 ( L_113 ,
V_452 ) ;
return - V_177 ;
}
V_454 = V_448 -> V_451 ;
}
}
if ( V_455 ) {
if ( V_217 != V_7 ) {
F_314 ( L_114 ,
F_1 ( V_217 ) ) ;
} else {
F_261 ( & V_368 , V_455 ) ;
V_448 = F_311 ( F_312 ( V_456 ) ,
& V_368 ) ;
if ( ! V_448 ) {
F_313 ( L_115 ,
V_455 ) ;
return - V_177 ;
}
V_457 = V_448 -> V_451 ;
}
}
if ( V_458 ) {
F_261 ( & V_368 , V_458 ) ;
V_448 = F_311 ( F_312 ( V_459 ) ,
& V_368 ) ;
if ( ! V_448 ) {
F_313 ( L_116 , V_458 ) ;
return - V_177 ;
}
V_52 -> V_458 = V_448 -> V_451 ;
if ( V_217 != V_7 )
F_315 ( L_117 ) ;
} else {
V_52 -> V_458 = V_460 ;
}
if ( V_461 < 0 ) {
F_315 ( L_118 ,
V_461 , 0 , V_462 , V_463 ) ;
V_461 = V_463 ;
}
if ( V_107 < 0 ) {
F_315 ( L_119 ,
V_107 , V_462 ) ;
V_107 = 0 ;
}
if ( V_99 < 0 ) {
F_315 ( L_120 ,
V_99 , V_462 ) ;
V_99 = 0 ;
}
if ( V_228 < 0 ) {
F_315 ( L_121 ,
V_228 , V_462 ) ;
V_228 = 0 ;
}
if ( ( V_53 != 0 ) && ( V_53 != 1 ) ) {
F_315 ( L_122 ,
V_53 ) ;
V_53 = 1 ;
}
if ( V_111 < 0 || V_111 > 255 ) {
F_315 ( L_123 ,
V_111 ) ;
V_111 = 1 ;
}
if ( ! F_316 ( V_217 ) ) {
if ( ! V_107 ) {
F_315 ( L_124 ) ;
F_315 ( L_125 ) ;
V_107 = V_464 ;
}
}
if ( V_465 < 1 || V_465 > 255 ) {
F_315 ( L_126 ,
V_465 , V_466 ) ;
V_465 = V_466 ;
}
if ( ( V_467 != 0 ) && ( V_467 != 1 ) ) {
F_315 ( L_127 ,
V_467 ) ;
V_467 = 0 ;
}
if ( V_114 < 0 || V_114 > 255 ) {
F_315 ( L_128 ,
V_114 , V_468 ) ;
V_114 = V_468 ;
}
F_317 ( & V_368 , V_405 ) ;
if ( ! F_311 ( F_312 ( V_469 ) , & V_368 ) ) {
F_315 ( L_129 ,
V_405 , V_470 ) ;
V_405 = 1 ;
}
if ( V_217 == V_9 ) {
F_318 ( L_130 ,
V_99 ) ;
}
if ( ! V_107 ) {
if ( V_99 || V_228 ) {
F_315 ( L_131 ,
V_99 , V_228 ) ;
}
} else {
if ( V_196 ) {
F_315 ( L_132 ,
V_107 , V_196 ) ;
V_196 = 0 ;
}
if ( ( V_99 % V_107 ) != 0 ) {
F_315 ( L_133 ,
V_99 , V_107 , ( V_99 / V_107 ) * V_107 ) ;
}
V_99 /= V_107 ;
if ( ( V_228 % V_107 ) != 0 ) {
F_315 ( L_134 ,
V_228 , V_107 ,
( V_228 / V_107 ) * V_107 ) ;
}
V_228 /= V_107 ;
}
if ( V_196 < 0 ) {
F_315 ( L_135 ,
V_196 , V_462 ) ;
V_196 = 0 ;
}
for ( V_471 = 0 , V_167 = 0 ;
( V_471 < V_197 ) && V_472 [ V_167 ] ; V_167 ++ ) {
T_8 V_233 ;
if ( ! F_319 ( V_472 [ V_167 ] , - 1 , ( T_5 * ) & V_233 , - 1 , NULL ) ||
! F_320 ( V_233 ) ) {
F_315 ( L_136 ,
V_472 [ V_167 ] ) ;
V_196 = 0 ;
} else {
if ( F_195 ( V_473 , V_233 ) == - 1 )
V_473 [ V_471 ++ ] = V_233 ;
else
F_315 ( L_137 ,
& V_233 ) ;
}
}
if ( V_196 && ! V_471 ) {
F_315 ( L_138 ,
V_196 ) ;
V_196 = 0 ;
}
if ( V_254 ) {
if ( ! V_196 ) {
F_313 ( L_139 ) ;
return - V_177 ;
}
F_261 ( & V_368 , V_254 ) ;
V_448 = F_311 ( F_312 ( V_474 ) ,
& V_368 ) ;
if ( ! V_448 ) {
F_313 ( L_140 ,
V_254 ) ;
return - V_177 ;
}
V_445 = V_448 -> V_451 ;
} else {
V_445 = 0 ;
}
V_449 = 0 ;
if ( V_475 ) {
F_261 ( & V_368 , V_475 ) ;
V_448 = F_311 ( F_312 ( V_476 ) ,
& V_368 ) ;
if ( ! V_448 ) {
F_313 ( L_141 ,
V_475 ) ;
V_449 = 0 ;
} else {
V_449 = V_448 -> V_451 ;
}
}
if ( V_107 ) {
F_314 ( L_142 , V_107 ) ;
} else if ( V_196 ) {
V_448 = F_321 ( V_474 ,
V_445 ) ;
F_314 ( L_143 ,
V_196 , V_448 -> string , V_471 ) ;
for ( V_167 = 0 ; V_167 < V_471 ; V_167 ++ )
F_322 ( L_144 , V_472 [ V_167 ] ) ;
F_322 ( L_145 ) ;
} else if ( V_461 ) {
F_323 ( L_146 ) ;
}
if ( V_199 && ! F_324 ( V_217 ) ) {
F_315 ( L_147 ,
V_199 , F_1 ( V_217 ) ) ;
V_199 = NULL ;
}
if ( V_199 && V_94 ) {
F_261 ( & V_368 , V_94 ) ;
V_448 = F_311 ( F_312 ( V_477 ) ,
& V_368 ) ;
if ( ! V_448 ) {
F_313 ( L_148 ,
V_94 ) ;
return - V_177 ;
}
V_447 = V_448 -> V_451 ;
} else {
V_447 = V_478 ;
}
if ( V_110 ) {
F_261 ( & V_368 , V_110 ) ;
V_448 = F_311 ( F_312 ( V_479 ) ,
& V_368 ) ;
if ( ! V_448 ) {
F_313 ( L_149 ,
V_110 ) ;
return - V_177 ;
}
V_446 = V_448 -> V_451 ;
if ( V_217 != V_4 )
F_315 ( L_150 ) ;
} else {
V_446 = V_480 ;
}
if ( V_481 == 0 ) {
F_315 ( L_151 ,
V_462 , V_482 ) ;
V_481 = V_482 ;
}
V_52 -> V_1 = V_217 ;
V_52 -> V_316 = V_454 ;
V_52 -> V_107 = V_107 ;
V_52 -> V_111 = V_111 ;
V_52 -> V_196 = V_196 ;
V_52 -> V_254 = V_445 ;
V_52 -> V_475 = V_449 ;
V_52 -> V_99 = V_99 ;
V_52 -> V_228 = V_228 ;
V_52 -> V_53 = V_53 ;
V_52 -> V_457 = V_457 ;
V_52 -> V_199 [ 0 ] = 0 ;
V_52 -> V_94 = V_447 ;
V_52 -> V_110 = V_446 ;
V_52 -> V_465 = V_465 ;
V_52 -> V_467 = V_467 ;
V_52 -> V_114 = V_114 ;
V_52 -> V_483 = V_483 ;
V_52 -> V_481 = V_481 ;
V_52 -> V_405 = V_405 ;
V_52 -> V_335 = 1 ;
if ( V_405 > 0 ) {
V_52 -> V_404 =
V_403 ( V_405 ) ;
} else {
V_52 -> V_404 =
(struct V_403 ) { 0 } ;
}
if ( V_199 ) {
strncpy ( V_52 -> V_199 , V_199 , V_60 ) ;
V_52 -> V_199 [ V_60 - 1 ] = 0 ;
}
memcpy ( V_52 -> V_252 , V_473 , sizeof( V_473 ) ) ;
return 0 ;
}
static void F_325 ( struct V_14 * V_16 ,
struct V_484 * V_413 ,
void * V_485 )
{
F_326 ( & V_413 -> V_486 ,
& V_487 ) ;
}
static void F_327 ( struct V_14 * V_16 )
{
F_326 ( & V_16 -> V_488 ,
& V_489 ) ;
F_328 ( V_16 , F_325 , NULL ) ;
V_16 -> V_490 = & V_491 ;
}
static int F_329 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_492 * V_493 = F_330 ( F_191 ( V_19 ) , V_494 ) ;
struct V_495 * V_496 = & ( F_331 ( V_11 ) ) ;
F_57 ( V_19 , L_152 ) ;
F_332 ( & ( V_496 -> V_497 ) ) ;
F_332 ( & ( V_496 -> V_498 ) ) ;
V_11 -> V_73 = F_333 ( V_19 -> V_59 ) ;
if ( ! V_11 -> V_73 )
return - V_120 ;
F_327 ( V_19 ) ;
F_334 ( & V_11 -> V_443 , & V_493 -> V_499 ) ;
F_335 ( V_11 ) ;
F_336 ( V_11 ) ;
if ( F_337 ( V_19 -> V_86 ) &&
V_19 -> V_87 == V_500 )
F_152 ( V_19 ) ;
return 0 ;
}
unsigned int F_338 ( void )
{
return V_465 ;
}
int F_339 ( struct V_369 * V_369 , const char * V_59 )
{
struct V_14 * V_19 ;
int V_26 ;
F_340 () ;
V_19 = F_341 ( sizeof( struct V_10 ) ,
V_59 ? V_59 : L_153 , V_501 ,
F_304 , V_465 ) ;
if ( ! V_19 ) {
F_313 ( L_154 , V_59 ) ;
F_45 () ;
return - V_120 ;
}
F_342 ( V_19 , V_369 ) ;
V_19 -> V_502 = & V_503 ;
V_26 = F_343 ( V_19 ) ;
F_24 ( V_19 ) ;
F_45 () ;
if ( V_26 < 0 )
F_301 ( V_19 ) ;
return V_26 ;
}
static int T_12 F_344 ( struct V_369 * V_369 )
{
struct V_492 * V_493 = F_330 ( V_369 , V_494 ) ;
V_493 -> V_369 = V_369 ;
F_345 ( & V_493 -> V_499 ) ;
F_346 ( V_493 ) ;
F_347 ( V_493 ) ;
return 0 ;
}
static void T_13 F_348 ( struct V_369 * V_369 )
{
struct V_492 * V_493 = F_330 ( V_369 , V_494 ) ;
struct V_10 * V_11 , * V_504 ;
F_349 ( V_505 ) ;
F_350 ( V_493 ) ;
F_340 () ;
F_351 (bond, tmp_bond, &bn->dev_list, bond_list)
F_352 ( V_11 -> V_16 , & V_505 ) ;
F_353 ( & V_505 ) ;
F_45 () ;
F_354 ( V_493 ) ;
}
static int T_14 F_355 ( void )
{
int V_167 ;
int V_26 ;
F_314 ( L_155 , V_506 ) ;
V_26 = F_310 ( & V_426 ) ;
if ( V_26 )
goto V_121;
V_26 = F_356 ( & V_507 ) ;
if ( V_26 )
goto V_121;
V_26 = F_357 () ;
if ( V_26 )
goto V_508;
F_358 () ;
for ( V_167 = 0 ; V_167 < V_461 ; V_167 ++ ) {
V_26 = F_339 ( & V_509 , NULL ) ;
if ( V_26 )
goto V_67;
}
F_359 ( & V_510 ) ;
V_121:
return V_26 ;
V_67:
F_360 () ;
F_361 () ;
V_508:
F_362 ( & V_507 ) ;
goto V_121;
}
static void T_15 F_363 ( void )
{
F_364 ( & V_510 ) ;
F_360 () ;
F_361 () ;
F_362 ( & V_507 ) ;
#ifdef F_142
F_365 ( F_366 ( & V_511 ) ) ;
#endif
}
